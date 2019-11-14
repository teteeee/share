/***********************************************************************/
/*                                                                     */
/*  FILE        : interrupt.h                                          */
/*  DESCRIPTION : for arround interrupt process                        */
/*                                                                     */
/***********************************************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H

//------------------------------------------------
//  マクロ定義
//------------------------------------------------

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------


//------------------------------------------------
//  グローバル変数宣言
//------------------------------------------------


//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------

//interrupt init
void mtu3Init();
void mtu4Init();
void mtu7Init();

//Speaker
void mtu3aSpeaker1();
void mtu3cSpeaker2();

//ESC
void mtu4aEsc1();
void mtu4cEsc2();
void mtu7aEsc3();
void mtu7cEsc4();

//Control

//Operate
void clearInterruptFlgMtu3a();
void setInterruptPeriodMtu3a(unsigned int period);

#endif INTERRUPT_H
