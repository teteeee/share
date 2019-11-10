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
volatile int interraptMicTimer = MIC_TIMER_PERIOD;

//! 集音された回数
volatile int clapCounts = 0;

//------------------------------------------------
//  関数定義
//------------------------------------------------

/**
 * @fn
 * @brief 現在の音量を取得する
 * @return 0~1の範囲で判定した現在の音の大きさ
 * @detail 現在の音量を取得する。0~1の範囲で判定した現在の音の大きさが返却される。
 */
float getVolume() {
  return micAdValue * K_AD_MIC;
}

/**
 * @fn
 * @brief 音量取得結果の更新
 * @detail 1us毎の割り込み内で呼び出されることを前提とした音量記録を更新する関数
 */
void updateVolumeMemory() {
  float nowVolume = getVolume() - 0.5;
  if (nowVolume * nowVolume > THRESHOLD_VOLUME) {
    volumeMemory16us = (volumeMemory16us << 1) + 1;
  } else {
    volumeMemory16us = volumeMemory16us << 1;
  }
}

/**
 * @fn
 * @brief 音を検知する関数
 * @return 音検知と判定された場合true
 * @detail 集音状態であるか判定し、結果を返却する.
 *         条件1：16usの間で過半数の期間の音量が閾値を超えていること
 */
bool detectedSound() {
  int counts = count16bitVal(volumeMemory16us);
  if (counts >= 8) {
    return true;
  }
  return false;
}

/**
 * @fn
 * @brief 集音実施可能かチェックする関数
 * @return 集音実施条件を満たす場合true
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
 * @brief 集音状態をリセットする
 */
void clearSoundState() {
  volumeMemory16us = 0;
}

/**
 * @fn
 * @brief 集音回数をリセットする関数
 */
void clearClapCounts() {
  clapCounts = 0;
}

/**
 * @fn
 * @brief 集音回数を取得する関数
 */
int getClapCounts() {
  return clapCounts;
}

/**
 * @fn
 * @brief 集音チャタリング用タイマの変数が正数の場合デクリメントする
 */
void decrementChataTimer() {
  if (soundChataTimer > 0) {
    soundChataTimer--;
  }
}

/**
 * @fn
 * @brief 割り込み用タイマ変数が正数の場合デクリメントする
 */
void decrementInterraptMicTimer() {
  if (interraptMicTimer > 0) {
    interraptMicTimer--;
  }
}

/**
 * @fn
 * @brief 割り込み用タイマ変数をリセットする
 */
void resetInterraptMicTimer() {
  interraptMicTimer = MIC_TIMER_PERIOD;
}

/**
 * @fn
 * @brief 割り込みタイマ関連処理
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

