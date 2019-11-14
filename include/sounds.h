/***********************************************************************/
/*                                                                     */
/*  FILE        : sounds.h                                             */
/*  DESCRIPTION : describe about sounds                                */
/*                                                                     */
/***********************************************************************/

#ifndef SOUNDS_H
#define SOUNDS_H

//------------------------------------------------
//  マクロ定義
//------------------------------------------------

/** @def
 * スピーカー出力残時間タイマ用コンペアマッチの単位時間(単位：s)
 */
#define SOUNDS_TIMER_UNIT_TIME  (0.00001024) // ICLK/1024を想定する

/** @def
 * スピーカー出力用のコンペアマッチタイマ等における単位時間(単位：s)
 */
#define UNIT_TIME  (0.00000016) // 周期が細かすぎるとカウンタの上限65000に到達してしまうためICLK/16を想定する

//周波数と対応名称の定義
#define FREQ_U_U_SI    3951
#define FREQ_U_U_LA_S  3729
#define FREQ_U_U_LA    3520
#define FREQ_U_U_SO_S  3322
#define FREQ_U_U_SO    3136
#define FREQ_U_U_FA_S  2960
#define FREQ_U_U_FA    2793
#define FREQ_U_U_MI    2637
#define FREQ_U_U_RE_S  2489
#define FREQ_U_U_RE    2349
#define FREQ_U_U_DO_S  2217
#define FREQ_U_U_DO    2093
#define FREQ_U_SI      1976
#define FREQ_U_LA_S    1865
#define FREQ_U_LA      1760
#define FREQ_U_SO_S    1661
#define FREQ_U_SO      1568
#define FREQ_U_FA_S    1480
#define FREQ_U_FA      1397
#define FREQ_U_MI      1319
#define FREQ_U_RE_S    1245
#define FREQ_U_RE      1175
#define FREQ_U_DO_S    1109
#define FREQ_U_DO      1047
#define FREQ_SI        988
#define FREQ_LA_S      932
#define FREQ_LA        880
#define FREQ_SO_S      831
#define FREQ_SO        784
#define FREQ_FA_S      740
#define FREQ_FA        698
#define FREQ_MI        659
#define FREQ_RE_S      622
#define FREQ_RE        587
#define FREQ_DO_S      554
#define FREQ_DO        523
#define FREQ_S_SI      494
#define FREQ_S_LA_S    466
#define FREQ_S_LA      440
#define FREQ_S_SO_S    415
#define FREQ_S_SO      392
#define FREQ_S_FA_S    370
#define FREQ_S_FA      349
#define FREQ_S_MI      330
#define FREQ_S_RE_S    311
#define FREQ_S_RE      294
#define FREQ_S_DO_S    277
#define FREQ_S_DO      262
#define FREQ_S_S_SI    247
#define FREQ_S_S_LA_S  233
#define FREQ_S_S_LA    220

//周波数を実現するために必要な単位時間数
#define U_U_SI    ( 1 / FREQ_U_U_SI   / UNIT_TIME )
#define U_U_LA_S  ( 1 / FREQ_U_U_LA_S / UNIT_TIME )
#define U_U_LA    ( 1 / FREQ_U_U_LA   / UNIT_TIME )
#define U_U_SO_S  ( 1 / FREQ_U_U_SO_S / UNIT_TIME )
#define U_U_SO    ( 1 / FREQ_U_U_SO   / UNIT_TIME )
#define U_U_FA_S  ( 1 / FREQ_U_U_FA_S / UNIT_TIME )
#define U_U_FA    ( 1 / FREQ_U_U_FA   / UNIT_TIME )
#define U_U_MI    ( 1 / FREQ_U_U_MI   / UNIT_TIME )
#define U_U_RE_S  ( 1 / FREQ_U_U_RE_S / UNIT_TIME )
#define U_U_RE    ( 1 / FREQ_U_U_RE   / UNIT_TIME )
#define U_U_DO_S  ( 1 / FREQ_U_U_DO_S / UNIT_TIME )
#define U_U_DO    ( 1 / FREQ_U_U_DO   / UNIT_TIME )
#define U_SI      ( 1 / FREQ_U_SI     / UNIT_TIME )
#define U_LA_S    ( 1 / FREQ_U_LA_S   / UNIT_TIME )
#define U_LA      ( 1 / FREQ_U_LA     / UNIT_TIME )
#define U_SO_S    ( 1 / FREQ_U_SO_S   / UNIT_TIME )
#define U_SO      ( 1 / FREQ_U_SO     / UNIT_TIME )
#define U_FA_S    ( 1 / FREQ_U_FA_S   / UNIT_TIME )
#define U_FA      ( 1 / FREQ_U_FA     / UNIT_TIME )
#define U_MI      ( 1 / FREQ_U_MI     / UNIT_TIME )
#define U_RE_S    ( 1 / FREQ_U_RE_S   / UNIT_TIME )
#define U_RE      ( 1 / FREQ_U_RE     / UNIT_TIME )
#define U_DO_S    ( 1 / FREQ_U_DO_S   / UNIT_TIME )
#define U_DO      ( 1 / FREQ_U_DO     / UNIT_TIME )
#define SI        ( 1 / FREQ_SI       / UNIT_TIME )
#define LA_S      ( 1 / FREQ_LA_S     / UNIT_TIME )
#define LA        ( 1 / FREQ_LA       / UNIT_TIME )
#define SO_S      ( 1 / FREQ_SO_S     / UNIT_TIME )
#define SO        ( 1 / FREQ_SO       / UNIT_TIME )
#define FA_S      ( 1 / FREQ_FA_S     / UNIT_TIME )
#define FA        ( 1 / FREQ_FA       / UNIT_TIME )
#define MI        ( 1 / FREQ_MI       / UNIT_TIME )
#define RE_S      ( 1 / FREQ_RE_S     / UNIT_TIME )
#define RE        ( 1 / FREQ_RE       / UNIT_TIME )
#define DO_S      ( 1 / FREQ_DO_S     / UNIT_TIME )
#define DO        ( 1 / FREQ_DO       / UNIT_TIME )
#define S_SI      ( 1 / FREQ_S_SI     / UNIT_TIME )
#define S_LA_S    ( 1 / FREQ_S_LA_S   / UNIT_TIME )
#define S_LA      ( 1 / FREQ_S_LA     / UNIT_TIME )
#define S_SO_S    ( 1 / FREQ_S_SO_S   / UNIT_TIME )
#define S_SO      ( 1 / FREQ_S_SO     / UNIT_TIME )
#define S_FA_S    ( 1 / FREQ_S_FA_S   / UNIT_TIME )
#define S_FA      ( 1 / FREQ_S_FA     / UNIT_TIME )
#define S_MI      ( 1 / FREQ_S_MI     / UNIT_TIME )
#define S_RE_S    ( 1 / FREQ_S_RE_S   / UNIT_TIME )
#define S_RE      ( 1 / FREQ_S_RE     / UNIT_TIME )
#define S_DO_S    ( 1 / FREQ_S_DO_S   / UNIT_TIME )
#define S_DO      ( 1 / FREQ_S_DO     / UNIT_TIME )
#define S_S_SI    ( 1 / FREQ_S_S_SI   / UNIT_TIME )
#define S_S_LA_S  ( 1 / FREQ_S_S_LA_S / UNIT_TIME )
#define S_S_LA    ( 1 / FREQ_S_S_LA   / UNIT_TIME )

//------------------------------------------------
//  構造体定義
//------------------------------------------------

/**
 * @typedef struct
 * 曲定義
 */
typedef struct{
  unsigned char tempo;
  unsigned int nowMerodyNumber;
  float kyokuritu;
  float first_dist; //前距離
  float end_dist; //後ろ距離
  float kabekirego;
  double turn_alfa;
  double turn_omega_max;
  double turn_time1;
}t_Snani;

//------------------------------------------------
//  グローバル変数宣言
//------------------------------------------------

extern volatile unsigned char tempo;

extern volatile unsigned char merodyRemainingTime;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

void oneScaleOut(float scale, float beat) ;

#endif SOUNDS_H
