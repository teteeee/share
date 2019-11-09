/***********************************************************************/
/*                                                                     */
/*  FILE        : microphone.c                                         */
/*  DESCRIPTION : describe about using microphone                      */
/*                割り込み関数の中でmicInterruptFuncを実行する                                    */
/*                getClapCountsにより現在検知している拍手回数を取得できる                    */
/*                                                                     */
/***********************************************************************/

#include "microphone.h"

//------------------------------------------------
//  グローバル変数定義
//------------------------------------------------

//! マイクのAD変換値を格納する変数
volatile int micAdValue = 0;

//! 直近16usの閾値を用いた音量取得結果
volatile int volumeMemory16us = 0;

//! 集音チャタリング用タイマ変数。単位：us。
volatile int soundChataTimer = 0;

//! 割り込み用タイマ変数。単位：us。
volatile int interraptMicTimer = MIC_TIMER_DT;

//! 集音された回数
volatile int clapCounts = 0;

//------------------------------------------------
//  関数定義
//------------------------------------------------

/**
 * @fn
 * @brief 現在の音量を取得する
 * @param なし
 * @return 0~1の範囲で判定した現在の音の大きさ
 * @detail 現在の音量を取得する。0~1の範囲で判定した現在の音の大きさが返却される。
 */
float getVolume() {
  return micAdValue * K_AD_MIC;
}

/**
 * @fn
 * @brief 音量取得結果の更新
 * @param なし
 * @return なし
 * @detail 1us毎の割り込み内で呼び出されることを前提とした音量記録を更新する関数
 */
void updateVolumeMemory() {
  float volume = getVolume();
  if (volume * volume > BASE_VOLUME_SQUARE) {
    volumeMemory16us = (volumeMemory16us << 1) + 1;
  } else {
    volumeMemory16us = volumeMemory16us << 1;
  }
}

/**
 * @fn
 * @brief 集音検知する関数
 * @param なし
 * @return 集音状態と判定された場合のみtrue
 * @detail 集音状態であるか判定し、結果を返却する.
 *         条件1：16usの間で過半数の期間の音量が閾値を超えていること
 *         条件2:集音チャタリング用タイマ変数が0であること
 */
bool detectedSound() {
  //チャタリング防止期間中は即false
  if (soundChataTimer > 0) {
    return false;
  }

  int counts = count16bitVal(volumeMemory16us);
  if (counts >= 8) {
    return true;
  }
  return false;
}

/**
 * @fn
 * @brief 集音実施可能かチェックする関数
 * @param なし
 * @return bool　集音実施条件を満たす場合true
 * @detail 集音実施条件：集音チャタリング用の変数が0であること
 */
bool isSoundCollectable() {
  if (soundChataTimer == 0) {
    return true;
  }
  return false;
}

/**
 * @fn
 * @brief 集音状態をリセットする関数
 * @param なし
 * @return なし
 */
void clearSoundState() {
  volumeMemory16us = 0;
}

/**
 * @fn
 * @brief 集音回数をリセットする関数
 * @param なし
 * @return なし
 */
void clearClapCounts() {
  clapCounts = 0;
}

/**
 * @fn
 * @brief 集音回数を取得する関数
 * @param なし
 * @return なし
 */
int getClapCounts() {
  return clapCounts;
}

/**
 * @fn
 * @brief 集音チャタリング用タイマの変数が正数の場合デクリメントする
 * @param なし
 * @return なし
 */
void decrementChataTimer() {
  if (soundChataTimer > 0) {
    soundChataTimer--;
  }
}

/**
 * @fn
 * @brief 割り込み用タイマ変数が正数の場合デクリメントする
 * @param なし
 * @return なし
 */
void decrementInterraptMicTimer() {
  if (interraptMicTimer > 0) {
    interraptMicTimer--;
  }
}

/**
 * @fn
 * @brief 割り込み用タイマ変数をリセットする
 * @param なし
 * @return なし
 */
void resetInterraptMicTimer() {
  interraptMicTimer = MIC_TIMER_DT;
}

/**
 * @fn
 * @brief 割り込みタイマ関連処理
 * @param なし
 * @return 　なし
 * @detail 割り込み関数内で単位時間ごとに実行されることを想定したタイマ関連処理
 */
void micInterruptFunc() {
  //タイマ変数の更新
  decrementChataTimer();
  decrementInterraptMicTimer();

  //集音情報の更新
  updateVolumeMemory();

  //音の検知処理
  if (isSoundCollectable()) {
    if (detectedSound()) {
      clapCounts++;
      resetInterraptMicTimer();

      //集音状態をリセット
      clearSoundState();
      soundChataTimer = MIC_CHATA_TIME;
    }
  }

  if (interraptMicTimer == 0) {
    //タイマと検知回数リセット
    clearClapCounts();
    resetInterraptMicTimer();
  }
}

