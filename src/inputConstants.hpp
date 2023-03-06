#pragma once

#include "platform.hpp"

const int errorKey = -69420;
const int windowsSpecialKey = 0xe0;
const int unixSpecialKey1 = 0x1b;
const int unixSpecialKey2 = 0x5b;
const int nullKey = 0x00;

const int upArrow = 0x80;
const int downArrow = 0x81;
const int leftArrow = 0x82;
const int rightArrow = 0x83;

const int K_CtrlA = 0x01;
const int K_CtrlB = 0x02;
const int K_CtrlC = 0x03;
const int K_CtrlD = 0x04;
const int K_CtrlE = 0x05;
const int K_CtrlF = 0x06;
const int K_CtrlG = 0x07;
const int K_CtrlH = 0x08;
const int K_CtrlI = 0x09;
const int K_CtrlJ = 0x0a;
const int K_CtrlK = 0x0b;
const int K_CtrlL = 0x0c;
const int K_CtrlM = 0x0d;
const int K_CtrlN = 0x0e;
const int K_CtrlO = 0x0f;
const int K_CtrlP = 0x10;
const int K_CtrlQ = 0x11;
const int K_CtrlR = 0x12;
const int K_CtrlS = 0x13;
const int K_CtrlT = 0x14;
const int K_CtrlU = 0x15;
const int K_CtrlV = 0x16;
const int K_CtrlW = 0x17;
const int K_CtrlX = 0x18;
const int K_CtrlY = 0x19;
const int K_CtrlZ = 0x1a;
const int K_ESC   = 0x1b;
const int K_FS    = 0x1c;
const int K_GS    = 0x1d;
const int K_RS    = 0x1e;
const int K_US    = 0x1f;
const int K_Space = 0x20; //  
const int K_ExtMk = 0x21; // !
const int K_DubQt = 0x22; // "
const int K_Hshtg = 0x23; // #
const int K_DolSg = 0x24; // $
const int K_Pectg = 0x25; // %
const int K_Ambct = 0x26; // &
const int K_SngQt = 0x27; // '
const int K_LBrac = 0x28; // (
const int K_RBrac = 0x29; // )
const int K_Atrsk = 0x2a; // *
const int K_Plus  = 0x2b; // +
const int K_Comma = 0x2c; // ,
const int K_Dash  = 0x2d; // -
const int K_Dot   = 0x2e; // .
const int K_Slash = 0x2f; // /
const int K_0     = 0x30; // 0
const int K_1     = 0x31; // 1
const int K_2     = 0x32; // 2
const int K_3     = 0x33; // 3
const int K_4     = 0x34; // 4
const int K_5     = 0x35; // 5
const int K_6     = 0x36; // 6
const int K_7     = 0x37; // 7
const int K_8     = 0x38; // 8
const int K_9     = 0x39; // 9
const int K_Colon = 0x3a; // :
const int K_SemiC = 0x3b; // ;
const int K_ST    = 0x3c; // <
const int K_EQ    = 0x3d; // =
const int K_GT    = 0x3e; // >
const int K_QstnM = 0x3f; // ?
const int K_At    = 0x40; // @
const int K_A     = 0x41; // A
const int K_B     = 0x42; // B
const int K_C     = 0x43; // C
const int K_D     = 0x44; // D
const int K_E     = 0x45; // E
const int K_F     = 0x46; // F
const int K_G     = 0x47; // G
const int K_H     = 0x48; // H
const int K_I     = 0x49; // I
const int K_J     = 0x4a; // J
const int K_K     = 0x4b; // K
const int K_L     = 0x4c; // L
const int K_M     = 0x4d; // M
const int K_N     = 0x4e; // N
const int K_O     = 0x4f; // O
const int K_P     = 0x50; // P
const int K_Q     = 0x51; // Q
const int K_R     = 0x52; // R
const int K_S     = 0x53; // S
const int K_T     = 0x54; // T
const int K_U     = 0x55; // U
const int K_V     = 0x56; // V
const int K_W     = 0x57; // W
const int K_X     = 0x58; // X
const int K_Y     = 0x59; // Y
const int K_Z     = 0x5a; // Z
const int K_LSBrk = 0x5b; // [
const int K_BkSh  = 0x5c; // '\'
const int K_RSBrk = 0x5d; // ]
const int K_Caret = 0x5e; // ^
const int K_UnScr = 0x5f; // _
const int K_BkTck = 0x60; // `
const int K_a     = 0x61; // a
const int K_b     = 0x62; // b
const int K_c     = 0x63; // c
const int K_d     = 0x64; // d
const int K_e     = 0x65; // e
const int K_f     = 0x66; // f
const int K_g     = 0x67; // g
const int K_h     = 0x68; // h
const int K_i     = 0x69; // i
const int K_j     = 0x6a; // j
const int K_k     = 0x6b; // k
const int K_l     = 0x6c; // l
const int K_m     = 0x6d; // m
const int K_n     = 0x6e; // n
const int K_o     = 0x6f; // o
const int K_p     = 0x70; // p
const int K_q     = 0x71; // q
const int K_r     = 0x72; // r
const int K_s     = 0x73; // s
const int K_t     = 0x74; // t
const int K_u     = 0x75; // u
const int K_v     = 0x76; // v
const int K_w     = 0x77; // w
const int K_x     = 0x78; // x
const int K_y     = 0x79; // y
const int K_z     = 0x7a; // z
const int K_LCBrk = 0x7b; // {
const int K_Pipe  = 0x7c; // |
const int K_RCBrk = 0x7d; // }
const int K_Tide  = 0x7e; // ~
const int K_Del   = 0x7f;
