/***********************************************************************/
/*                                                                     */
/*  FILE        : util.c                                               */
/*  DESCRIPTION : corrected original util                              */
/*                                                                     */
/***********************************************************************/

#include "util.h"

//------------------------------------------------
//  グローバル変数定義
//------------------------------------------------

//! コンペアマッチにより一秒ごとにインクリメントされるタイマーの変数
volatile long secondTimer = 0;

//------------------------------------------------
//  関数定義
//------------------------------------------------
/**
 * @fn
 * @brief 引数の秒数分待つ関数(小数点を使用可能)
 * @param sec 待機したい秒数
 * @detail 引数の秒数分待つ関数(小数点を使用可能)
 */
void wait(float sec) {
  secondTimer = 0;
  while (secondTimer <= sec) {
    //時間が経過するまで何もしない
  }
}

/**
 * @fn
 * @brief 16bit変数の中で立っているビット数をカウントする
 * @param anyInt　任意のint型変数
 * @return int 立っているビット数
 */
int count16bitVal(int anyInt) {
  anyInt = (anyInt & 0x5555) + (anyInt >> 1 & 0x5555);
  anyInt = (anyInt & 0x3333) + (anyInt >> 2 & 0x3333);
  anyInt = (anyInt & 0x0f0f) + (anyInt >> 4 & 0x0f0f);
  return (anyInt & 0x00ff) + (anyInt >> 8 & 0x00ff);
}

