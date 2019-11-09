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

volatile long secondTimer = 0;

//------------------------------------------------
//  関数定義
//------------------------------------------------
/**
 * @fn
 * @brief 引数の秒数分待つ関数(小数点を使用可能)
 * @param sec 秒数
 * @return なし
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
 * @brief 16bitｊの変数の立っているビットをカウントする
 * @param int anyInt
 * @return int 立っているビット数
 * @detail 16bitｊの変数の立っているビットをカウントする
 */
int count16bitVal(int anyInt) {
  anyInt = (anyInt & 0x5555) + (anyInt >> 1 & 0x5555);
  anyInt = (anyInt & 0x3333) + (anyInt >> 2 & 0x3333);
  anyInt = (anyInt & 0x0f0f) + (anyInt >> 4 & 0x0f0f);
  return (anyInt & 0x00ff) + (anyInt >> 8 & 0x00ff);
}

