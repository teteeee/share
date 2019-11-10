/***********************************************************************/
/*                                                                     */
/*  FILE        : microphone.h                                         */
/*  DESCRIPTION : describe about using microphone                      */
/*                                                                     */
/***********************************************************************/

#ifndef MIC_H
#define MIC_H
#include "util.h"

//------------------------------------------------
//  マクロ定義
//------------------------------------------------

/** @def
 * 音があると判定する基準値の定義
 * AD変換した電圧値に対して用いる
 * 0.5を平常時の音とし0~1の範囲で記載する
 */
#define REF_VOLUME (0.7)

/** @def
 * AD変換値に乗ずることで
 * 供給電圧に対して0~1の範囲に電圧値を変換する定数
 * 例. 分解能4096の場合　AD変換値*(1/4096)=0.000244140625
 */
#define K_AD_MIC (0.000244140625)

/** @def
 * マイク用のチャタリング防止時間(us)
 */
#define MIC_CHATA_TIME (50)

/** @def
 * マイク用のタイマ集計単位周期時間。単位：ｕｓ
 */
#define MIC_TIMER_PERIOD (1000)

/** @def
 * REF_VOLUMEと無音(=0.5)の差の2乗
 */
#define THRESHOLD_VOLUME ((REF_VOLUME - 0.5)*(REF_VOLUME - 0.5))

//------------------------------------------------
//  グローバル変数宣言
//------------------------------------------------

extern volatile int micAdValue;

extern volatile int volumeMemory16us;

extern volatile int soundChataTimer;

extern volatile int clapCounts;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

float getVolume();

void updateVolumeMemory();

bool detectedSound();

void clearSoundState();

int getClapCounts();

bool isSoundCollectable();

void decrementChataTimer();

void decrementInterraptMicTimer();

void resetInterraptMicTimer();

void micInterruptFunc();

#endif MIC_H
