/***********************************************************************/
/*                                                                     */
/*  FILE        : sounds.c                                             */
/*  DESCRIPTION : describe about sounds                                */
/*                                                                     */
/***********************************************************************/

#include "sounds.h"
#include "interrupt.h"

//------------------------------------------------
//  グローバル変数定義
//------------------------------------------------

//! 曲のテンポ.分当たりのメトロノームの回数.
volatile unsigned char tempo = 0;

//! 現在出力中メロディーの残時間(単位：s).
volatile double merodyRemainingTime = 0;

//------------------------------------------------
//  関数定義
//------------------------------------------------

/**
 * @fn
 * @brief 指定の音階を指定の拍数出す
 * @param scale 音階
 * @param beat 拍数
 */
void oneScaleOut(float scale, float beat) {
  //割り込み周期を音階に応じた値に設定する
  setInterruptPeriodMtu3a((unsigned int)scale);

  //TODO 音の長さに応じたタイマ値に設定する
}

/**
 * @fn
 * @brief 割り込みタイマ関連処理
 * @detail 割り込み関数内で単位時間ごとに実行されることを想定したタイマ関連処理
 */
void soundsInterruptFunc() {
  //メロディ残時間の更新
  merodyRemainingTime = merodyRemainingTime - SOUNDS_TIMER_UNIT_TIME;
  if (merodyRemainingTime > 0) {
    return;
  }

  //メロディ更新処理
  //TODO メロディ情報をメモリに持ちたくないのでこんな感じで実装メロディの羅列からこの形式になるようにプログラミングしてサブモジュールで置いておく
　　/*
　　　void surveyParameter(int merodytitle){
   if(medrodytitle = ...){
    ...
   }
   else if (merodytile=...){
    if(nowMerodyNum < 100){
     if(nowMerodyNum < 5)

    else if(nowMerodyNum < 200*/

}
