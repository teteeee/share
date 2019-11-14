/***********************************************************************/
/*                                                                     */
/*  FILE        : interrupt.c                                          */
/*  DESCRIPTION : arround interrupt process                            */
/*                                                                     */
/***********************************************************************/

#include "interrupt.h"
#include "iodefine.h"

//------------------------------------------------
//  グローバル変数定義
//------------------------------------------------

//------------------------------------------------
//  関数定義
//------------------------------------------------
/**
 * @fn
 * @brief mtu4aによる割り込み関数.ESCを制御する
 */
void mtu4aEsc1() {

}

/**
 * @fn
 * @brief mtu4cによる割り込み関数.ESCを制御する
 */
void mtu4cEsc2() {

}

/**
 * @fn
 * @brief mtu7aによる割り込み関数.ESCを制御する
 */
void mtu7aEsc3() {

}

/**
 * @fn
 * @brief mtu7cによる割り込み関数.ESCを制御する
 */
void mtu7cEsc4() {

}

/**
 * @fn
 * @brief mtu3aによる割り込み関数.スピーカを制御する
 */
void mtu3aSpeaker1() {

}

/**
 * @fn
 * @brief mtu3aの割り込みフラグクリア.
 * @detail 割り込み発動時に呼ぶことで、次回の割り込みを実行可能にする.
 */
void clearInterruptFlgMtu3a() {
  MTU3.TSR.BIT.TGFA = 0;
}

/**
 * @fn
 * @brief mtu3aの割り込み周期を設定する.
 * @param period 割り込み期間.0~65535の範囲で設定する.
 */
void setInterruptPeriodMtu3a(unsigned int period) {
  MTU3.TGRA = period;
}

/**
 * @fn
 * @brief mtu3を使用可能な状態にする
 */
void mtu3Init() {
  MSTP (MTU3) = 0;          //モジュール動作停止を解除
  IPR(MTU3, TGIA3)= 13;     //割り込みレベル
  IPR(MTU3, TGIB3)= 13;
  IEN(MTU3, TGIA3)= 1;      //割り込みを許可
  IEN(MTU3, TGIB3)= 1;      //割り込みを許可
  MTU.TSTRA.BIT.CST3 = 0;   //カウント動作停止
  MTU3.TCR.BIT.TPSC = 1;    //内部クロックICLK/4でカウント
  MTU3.TCR.BIT.CKEG = 0;    //立ち上がりエッジでカウント
  MTU3.TCR.BIT.CCLR = 1;    //TGRAのコンペアマッチ/インプットキャプチャででTCNTクリア
  MTU3.TIER.BIT.TGIEA = 1;  //割り込み要求(TGIA)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU3.TIER.BIT.TGIEB = 1;  //割り込み要求(TGIB)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU3.TMDR1.BIT.BFA = 0;   //バッファ動作なし
  MTU3.TMDR1.BIT.BFB = 0;   //バッファ動作なし
  MTU3.TMDR1.BIT.MD = 0;    //通常動作(PWMモード等を使わない)
  MTU3.TSR.BIT.TGFA = 0;    //割り込みフラグクリアに使う
  MTU3.TSR.BIT.TGFB = 0;    //割り込みフラグクリアに使う
  MTU.TSYRA.BIT.SYNC3 = 0;  //TCNTは独立して動作
  MTU3.TCNT = 0;
  MTU3.TGRA = 24000 / 5 - 1;  //0.2ms:24000/5-1
  MTU3.TGRB = 350;          //LED応答の時間 288:12ns
  MTU.TSTRA.BIT.CST3 = 1;   //カウント動作開始
}

/**
 * @fn
 * @brief mtu4を使用可能な状態にする
 */
void mtu4Init() {
  MSTP (MTU4) = 0;          //モジュール動作停止を解除
  IPR(MTU4, TGIA4)= 13;     //割り込みレベル
  IPR(MTU4, TGIB4)= 13;
  IEN(MTU4, TGIA4)= 1;      //割り込みを許可
  IEN(MTU4, TGIB4)= 1;      //割り込みを許可
  MTU.TSTRA.BIT.CST4 = 0;   //カウント動作停止
  MTU4.TCR.BIT.TPSC = 1;    //内部クロックICLK/4でカウント
  MTU4.TCR.BIT.CKEG = 0;    //立ち上がりエッジでカウント
  MTU4.TCR.BIT.CCLR = 1;    //TGRAのコンペアマッチ/インプットキャプチャででTCNTクリア
  MTU4.TIER.BIT.TGIEA = 1;  //割り込み要求(TGIA)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU4.TIER.BIT.TGIEB = 1;  //割り込み要求(TGIB)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU4.TMDR1.BIT.BFA = 0;   //バッファ動作なし
  MTU4.TMDR1.BIT.BFB = 0;   //バッファ動作なし
  MTU4.TMDR1.BIT.MD = 0;    //通常動作(PWMモード等を使わない)
  MTU4.TSR.BIT.TGFA = 0;    //割り込みフラグクリアに使う
  MTU4.TSR.BIT.TGFB = 0;    //割り込みフラグクリアに使う
  MTU.TSYRA.BIT.SYNC4 = 0;  //TCNTは独立して動作
  MTU4.TCNT = 0;
  MTU4.TGRA = 24000 / 5 - 1;  //0.2ms:24000/5-1
  MTU4.TGRB = 350;          //LED応答の時間 288:12ns
  MTU.TSTRA.BIT.CST4 = 1;   //カウント動作開始
}

/**
 * @fn
 * @brief mtu7を使用可能な状態にする
 */
void mtu7Init() {
  MSTP (MTU7) = 0;          //モジュール動作停止を解除
  IPR(MTU7, TGIA7)= 13;     //割り込みレベル
  IPR(MTU7, TGIB7)= 13;
  IEN(MTU7, TGIA7)= 1;      //割り込みを許可
  IEN(MTU7, TGIB7)= 1;      //割り込みを許可
  MTU.TSTRB.BIT.CST7 = 0;   //カウント動作停止
  MTU7.TCR.BIT.TPSC = 1;    //内部クロックICLK/4でカウント
  MTU7.TCR.BIT.CKEG = 0;    //立ち上がりエッジでカウント
  MTU7.TCR.BIT.CCLR = 1;    //TGRAのコンペアマッチ/インプットキャプチャででTCNTクリア
  MTU7.TIER.BIT.TGIEA = 1;  //割り込み要求(TGIA)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU7.TIER.BIT.TGIEB = 1;  //割り込み要求(TGIB)を許可。(インプットキャプチャでTGFフラグが1になるはず)
  MTU7.TMDR1.BIT.BFA = 0;   //バッファ動作なし
  MTU7.TMDR1.BIT.BFB = 0;   //バッファ動作なし
  MTU7.TMDR1.BIT.MD = 0;    //通常動作(PWMモード等を使わない)
  MTU7.TSR.BIT.TGFA = 0;    //割り込みフラグクリアに使う
  MTU7.TSR.BIT.TGFB = 0;    //割り込みフラグクリアに使う
  MTU.TSYRB.BIT.SYNC7 = 0;  //TCNTは独立して動作
  MTU7.TCNT = 0;
  MTU7.TGRA = 24000 / 5 - 1;  //0.2ms:24000/5-1
  MTU7.TGRB = 350;          //LED応答の時間 288:12ns
  MTU.TSTRB.BIT.CST7 = 1;   //カウント動作開始
}

