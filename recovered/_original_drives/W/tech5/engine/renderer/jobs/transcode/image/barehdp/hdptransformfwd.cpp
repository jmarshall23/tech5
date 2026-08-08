
// ========================================================================
// FwdOdd2x2Stage1
// EA  : 0x828FB6C0
// RVA : 0x008FB6C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdOdd2x2Stage1(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v5; // r11
  int v6; // r10
  __int16 v7; // r9
  int v8; // r30
  __int16 v9; // r6
  int v10; // r8
  int v11; // r11
  __int16 v12; // r7

  v5 = (__int16)(*pa + *pd);
  v6 = (__int16)(*pb - *pc);
  v7 = ((v6 + 1) >> 1) + *pc;
  v8 = (__int16)(v6 - ((3 * v5 + 4) >> 3));
  v9 = ((v5 + 1) >> 1) - *pd;
  v10 = (__int16)(((3 * v8 + 4) >> 3) + v5);
  v11 = (v8 >> 1) + (__int16)(v9 - ((3 * v7 + 4) >> 3));
  v12 = ((3 * (__int16)(v9 - ((3 * v7 + 4) >> 3)) + 4) >> 3) + v7 - ((v10 + 1) >> 1);
  *pa = v12 + v10;
  *pb = v8 - v11;
  *pc = v12;
  *pd = v11;
}


// ========================================================================
// FwdTransform4x4Stage1
// EA  : 0x828FB7A8
// RVA : 0x008FB7A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdTransform4x4Stage1(__int16 *p)
{
  __int16 *v1; // r30
  __int16 *v2; // r29
  __int16 v4; // r9
  __int16 v5; // r7
  __int16 v6; // r5
  int v7; // r8
  __int16 v8; // r3
  int v9; // r11
  int v10; // r9
  int v11; // r10
  __int16 v12; // r3
  int v13; // r4
  int v14; // r8

  v1 = p + 8;
  v2 = p + 4;
  Hadamard2x2dnStage1(pa: p, pb: p + 4, pc: p + 8, pd: p + 12);
  Hadamard2x2dnStage1(pa: p + 1, pb: p + 5, pc: p + 9, pd: p + 13);
  Hadamard2x2dnStage1(pa: p + 2, pb: p + 6, pc: p + 10, pd: p + 14);
  Hadamard2x2dnStage1(pa: p + 3, pb: p + 7, pc: p + 11, pd: p + 15);
  Hadamard2x2upStage1(pa: p, pb: p + 1, pc: p + 2, pd: p + 3);
  FwdOdd2x2Stage1(pa: p + 5, pb: v2, pc: p + 7, pd: p + 6);
  FwdOdd2x2Stage1(pa: p + 10, pb: v1, pc: p + 11, pd: p + 9);
  v4 = p[15];
  v5 = p[14];
  v6 = v4 + p[12];
  v7 = v6 >> 1;
  v8 = (__int16)(v5 - p[13]) >> 1;
  v9 = (__int16)(v8 - v5);
  v10 = (__int16)(((3 * v9 + 4) >> 3) - v7 + v4);
  v11 = (__int16)(v9 - ((3 * (v10 + 1)) >> 2));
  v12 = v11 - v8;
  v13 = 3 * (v11 + 1);
  LOWORD(v11) = v5 - p[13] + v12;
  v14 = (v13 >> 3) + v10 + v7;
  p[15] = v14;
  p[14] = v12;
  p[13] = v11;
  p[12] = v6 - v14;
}


// ========================================================================
// FwdOdd2x2Stage2
// EA  : 0x828FB928
// RVA : 0x008FB928
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdOdd2x2Stage2(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  __int16 v5; // r5
  int v6; // r10
  int v7; // r11
  __int16 v8; // r5
  int v9; // r11
  int v10; // r9
  int v11; // r10
  int v12; // r7
  __int16 v13; // r8

  v5 = *pc;
  v6 = (__int16)(*pa + *pd);
  v7 = (__int16)(*pb - v5);
  v8 = ((v7 + 1) >> 1) + v5;
  v9 = -96 * (v6 >> 8) - (__int16)(((unsigned __int8)(*(_BYTE *)pa + *(_BYTE *)pd) + ((2 * v6) & 0x1FE) + 4) >> 3) + v7;
  v10 = -96 * (v8 >> 8)
      - (__int16)(((unsigned __int8)v8 + ((2 * v8) & 0x1FE) + 4) >> 3)
      + (__int16)(((v6 + 1) >> 1) - *pd);
  v11 = (__int16)((((unsigned __int8)v9 + ((2 * v9) & 0x1FE) + 4) >> 3) + 96 * ((__int16)v9 >> 8) + v6);
  v12 = (__int16)v9 >> 1;
  v13 = (((unsigned __int8)v10 + ((2 * v10) & 0x1FE) + 4) >> 3) + 96 * ((__int16)v10 >> 8) + v8 - ((v11 + 1) >> 1);
  *pa = v13 + v11;
  *pb = v9 - (v12 + v10);
  *pc = v13;
  *pd = v12 + v10;
}


// ========================================================================
// FwdOddOdd2x2Stage2
// EA  : 0x828FBA78
// RVA : 0x008FBA78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdOddOdd2x2Stage2(unsigned __int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v5; // r8
  __int16 v7; // r11
  int v8; // r5
  __int16 v9; // r27
  __int16 v10; // r28
  __int16 v11; // r6
  int v12; // r11
  int v13; // r10
  int v14; // r5

  v5 = *pa;
  v7 = *pb - *pc;
  v8 = (__int16)(*pd + v5);
  v9 = *pd + v5;
  v10 = v7 >> 1;
  v11 = v7;
  v12 = (__int16)((v7 >> 1) - *pb);
  v13 = (__int16)(((unsigned __int8)(v10 - *(_BYTE *)pb) + ((2 * v12) & 0x1FE) + 4) >> 3)
      + 96 * (v12 >> 8)
      - (v8 >> 1)
      + v5;
  LOWORD(v12) = -192 * ((__int16)v13 >> 8)
              - ((3
                * ((unsigned __int8)((((unsigned __int8)(v10 - *(_BYTE *)pb) + ((2 * v12) & 0x1FE) + 4) >> 3)
                                   + 96 * BYTE2(v12)
                                   - (v8 >> 1)
                                   + v5)
                 + 1)) >> 2)
              + v12;
  v14 = (v8 >> 1) + (__int16)((3 * ((unsigned __int8)v12 + 1)) >> 3) + 96 * ((__int16)v12 >> 8) + v13;
  *pa = v14;
  *pb = v12 - v10;
  *pc = v11 + v12 - v10;
  *pd = v9 - v14;
}


// ========================================================================
// FwdTransform4x4Stage2
// EA  : 0x828FBB90
// RVA : 0x008FBB90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdTransform4x4Stage2(__int16 *p)
{
  __int16 *v1; // r30
  __int16 *v2; // r29
  __int16 *v3; // r28

  v1 = p + 240;
  v2 = p + 48;
  v3 = p + 192;
  Hadamard2x2dnStage2(pa: p, pb: p + 192, pc: p + 48, pd: p + 240);
  Hadamard2x2dnStage2(pa: p + 64, pb: p + 128, pc: p + 112, pd: p + 176);
  Hadamard2x2dnStage2(pa: p + 16, pb: p + 208, pc: p + 32, pd: p + 224);
  Hadamard2x2dnStage2(pa: p + 80, pb: p + 144, pc: p + 96, pd: p + 160);
  Hadamard2x2upStage2(pa: p, pb: p + 64, pc: p + 16, pd: p + 80);
  FwdOdd2x2Stage2(pa: p + 128, pb: v3, pc: p + 144, pd: p + 208);
  FwdOdd2x2Stage2(pa: p + 32, pb: v2, pc: p + 96, pd: p + 112);
  FwdOddOdd2x2Stage2(pa: (unsigned __int16 *)p + 160, pb: p + 224, pc: p + 176, pd: v1);
}


// ========================================================================
// Hadamard2x2dnPreFilter
// EA  : 0x828FBC80
// RVA : 0x008FBC80
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall Hadamard2x2dnPreFilter(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v4; // r10
  int v5; // r7
  __int16 v6; // r31
  int v7; // r11
  __int16 v8; // r8
  int v9; // r10
  int v10; // r7
  int v11; // r11
  int v12; // r9

  v4 = (__int16)(*pb - *pc);
  v5 = (__int16)(*pa + *pd);
  v6 = ((v5 - v4) >> 1) - *pd;
  v7 = (__int16)(((__int16)(*pb - *pc) >> 1) + *pc);
  v8 = v6 + v4;
  v9 = (__int16)(v5 - ((3 * v7 + 8) >> 4));
  v10 = (__int16)(v7 - ((3 * v9 + 4) >> 5));
  v11 = (__int16)(v9 - ((3 * v10 + 8) >> 4));
  v12 = (v11 >> 1) - v10;
  *pa = v11 - v12;
  *pb = v8;
  *pc = v6;
  *pd = v12;
}


// ========================================================================
// FwdOddOdd2x2PreFilter
// EA  : 0x828FBD50
// RVA : 0x008FBD50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdOddOdd2x2PreFilter(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  __int16 v4; // r30
  __int16 v5; // r29
  int v6; // r11
  int v7; // r10
  int v8; // r8
  int v9; // r11
  __int16 v10; // r7

  v4 = *pd + *pa;
  v5 = *pc - *pb;
  v6 = (__int16)(*pb + (v5 >> 1));
  v7 = (__int16)(((3 * v6 + 4) >> 3) - (v4 >> 1) + *pa);
  v8 = (__int16)(v6 - ((3 * v7 + 2) >> 2));
  v9 = ((3 * (v8 + 2)) >> 3) + v7;
  LOWORD(v8) = v8 - (v5 >> 1);
  v10 = v9 + (v4 >> 1);
  *pa = v10;
  *pb = v8;
  *pc = v5 + v8;
  *pd = v4 - v10;
}


// ========================================================================
// PreFilter4x4Stage1
// EA  : 0x828FBE10
// RVA : 0x008FBE10
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter4x4Stage1(__int16 *p0, __int16 *p1, __int16 *p2, __int16 *p3)
{
  int v8; // r6
  __int16 *v9; // r27
  int v10; // r3
  __int16 *v11; // r24
  int v12; // r5
  __int16 *v13; // r23
  int v14; // r4
  __int16 *v15; // r22
  int v16; // r3
  int v17; // r7
  int v18; // r11
  int v19; // r11
  __int16 *v20; // r6

  Hadamard2x2dnPreFilter(pa: p0, pb: p1, pc: p2, pd: p3);
  v9 = (__int16 *)(v8 + 2);
  v11 = (__int16 *)(v10 + 2);
  v13 = (__int16 *)(v12 + 2);
  v15 = (__int16 *)(v14 + 2);
  Hadamard2x2dnPreFilter(
    pa: (__int16 *)(v10 + 2),
    pb: (__int16 *)(v14 + 2),
    pc: (__int16 *)(v12 + 2),
    pd: (__int16 *)(v8 + 2));
  Hadamard2x2dnPreFilter(pa: p0 + 2, pb: p1 + 2, pc: p2 + 2, pd: p3 + 2);
  Hadamard2x2dnPreFilter(pa: p0 + 3, pb: p1 + 3, pc: p2 + 3, pd: p3 + 3);
  v16 = (__int16)(p1[3] - ((p1[1] + 1) >> 1));
  p1[3] = v16;
  p1[1] += (v16 + 1) >> 1;
  v17 = (__int16)(p1[2] - ((*p1 + 1) >> 1));
  p1[2] = v17;
  *p1 += (v17 + 1) >> 1;
  v18 = (__int16)(p2[3] - ((p2[2] + 1) >> 1));
  p2[3] = v18;
  p2[2] += (v18 + 1) >> 1;
  v19 = (__int16)(p2[1] - ((*p2 + 1) >> 1));
  p2[1] = v19;
  *p2 += (v19 + 1) >> 1;
  FwdOddOdd2x2PreFilter(pa: p3, pb: v9, pc: p3 + 2, pd: v20);
  Hadamard2x2dnStage1(pa: p0, pb: p1, pc: p2, pd: p3);
  Hadamard2x2dnStage1(pa: v11, pb: v15, pc: v13, pd: v9);
  Hadamard2x2dnStage1(pa: p0 + 2, pb: p1 + 2, pc: p2 + 2, pd: p3 + 2);
  Hadamard2x2dnStage1(pa: p0 + 3, pb: p1 + 3, pc: p2 + 3, pd: p3 + 3);
}


// ========================================================================
// PreFilter4x4Stage1_9
// EA  : 0x828FBFE8
// RVA : 0x008FBFE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter4x4Stage1_9(__int16 *p)
{
  __int16 *v1; // r30

  v1 = p + 16;
  PreFilter4x4Stage1(p0: p + 12, p1: p + 72, p2: p + 20, p3: p + 80);
  PreFilter4x4Stage1(p0: v1 + 12, p1: v1 + 72, p2: p + 36, p3: p + 96);
  PreFilter4x4Stage1(p0: p + 44, p1: p + 104, p2: p + 52, p3: p + 112);
  PreFilter4x4Stage1(p0: p + 76, p1: p + 136, p2: p + 84, p3: p + 144);
  PreFilter4x4Stage1(p0: p + 92, p1: p + 152, p2: p + 100, p3: p + 160);
  PreFilter4x4Stage1(p0: p + 108, p1: p + 168, p2: p + 116, p3: p + 176);
  PreFilter4x4Stage1(p0: p + 140, p1: p + 200, p2: p + 148, p3: p + 208);
  PreFilter4x4Stage1(p0: p + 156, p1: p + 216, p2: p + 164, p3: p + 224);
  PreFilter4x4Stage1(p0: p + 172, p1: p + 232, p2: p + 180, p3: p + 240);
}


// ========================================================================
// PreFilter4
// EA  : 0x828FC0E0
// RVA : 0x008FC0E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter4(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r11
  int v10; // r10
  int v11; // r7
  int v12; // r6
  int v13; // r9
  int v14; // r8
  int v15; // r10
  int v16; // r11
  int v17; // r11

  v5 = *pd;
  v6 = *pc;
  v7 = (__int16)(*pa - ((3 * v5 + 16) >> 5));
  v8 = (__int16)(*pb - ((3 * v6 + 16) >> 5));
  v9 = (__int16)(v5 - ((3 * v7 + 8) >> 4));
  v10 = (__int16)(v6 - ((3 * v8 + 8) >> 4));
  v11 = (__int16)(v7 - ((3 * v9 + 16) >> 5) + v9);
  v12 = (__int16)(v8 - ((3 * v10 + 16) >> 5) + v10);
  v13 = (v12 + 1) >> 1;
  v14 = (v11 + 1) >> 1;
  v15 = (__int16)(v10 - v13);
  v16 = (__int16)(v9 - ((v15 + 1) >> 1) - v14);
  LOWORD(v14) = v14 + v16;
  v17 = ((v16 + 1) >> 1) + v15 + v13;
  *pa = v11 - v14;
  *pb = v12 - v17;
  *pc = v17;
  *pd = v14;
}


// ========================================================================
// PreFilter2x4Stage1
// EA  : 0x828FC208
// RVA : 0x008FC208
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter2x4Stage1(__int16 *pa, __int16 *pb)
{
  int v3; // r5

  PreFilter4(pa: pa + 5, pb: pa + 4, pc: pb, pd: pb + 1);
  PreFilter4(pa: pa + 7, pb: pa + 6, pc: (__int16 *)(v3 + 4), pd: (__int16 *)(v3 + 6));
}


// ========================================================================
// PreFilter4x2Stage1
// EA  : 0x828FC258
// RVA : 0x008FC258
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter4x2Stage1(__int16 *pa, __int16 *pb)
{
  int v3; // r5

  PreFilter4(pa: pa + 10, pb: pa + 8, pc: pb, pd: pb + 2);
  PreFilter4(pa: pa + 11, pb: pa + 9, pc: (__int16 *)(v3 + 2), pd: (__int16 *)(v3 + 6));
}


// ========================================================================
// PreFilter4x4Stage2
// EA  : 0x828FC2A8
// RVA : 0x008FC2A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall PreFilter4x4Stage2(__int16 *p0, __int16 *p1)
{
  __int16 *v2; // r29
  __int16 *v3; // r26
  __int16 *v4; // r25
  __int16 *v5; // r24
  int v8; // r11
  int v9; // r11
  int v10; // r9
  int v11; // r9

  v2 = p1 + 80;
  v3 = p1 - 112;
  v4 = p0 + 96;
  v5 = p0 - 96;
  Hadamard2x2dnPreFilter(pa: p0 - 96, pb: p0 + 96, pc: p1 - 112, pd: p1 + 80);
  Hadamard2x2dnPreFilter(pa: p0 - 32, pb: p0 + 32, pc: p1 - 48, pd: p1 + 16);
  Hadamard2x2dnPreFilter(pa: p0 - 80, pb: p0 + 112, pc: p1 - 128, pd: p1 + 64);
  Hadamard2x2dnPreFilter(pa: p0 - 16, pb: p0 + 48, pc: p1 - 64, pd: p1);
  v8 = (__int16)(*(p1 - 112) - ((*(p1 - 48) + 1) >> 1));
  *(p1 - 112) = v8;
  *(p1 - 48) += (v8 + 1) >> 1;
  v9 = (__int16)(*(p1 - 128) - ((*(p1 - 64) + 1) >> 1));
  *(p1 - 128) = v9;
  *(p1 - 64) += (v9 + 1) >> 1;
  v10 = (__int16)(p0[96] - ((p0[112] + 1) >> 1));
  p0[96] = v10;
  p0[112] += (v10 + 1) >> 1;
  v11 = (unsigned __int16)p0[32] - ((p0[48] + 1) >> 1);
  p0[32] = v11;
  p0[48] += ((__int16)v11 + 1) >> 1;
  FwdOddOdd2x2PreFilter(pa: p1, pb: p1 + 64, pc: p1 + 16, pd: v2);
  Hadamard2x2dnStage2(pa: v5, pb: v3, pc: v4, pd: v2);
  Hadamard2x2dnStage2(pa: p0 - 32, pb: p1 - 48, pc: p0 + 32, pd: p1 + 16);
  Hadamard2x2dnStage2(pa: p0 - 80, pb: p1 - 128, pc: p0 + 112, pd: p1 + 64);
  Hadamard2x2dnStage2(pa: p0 - 16, pb: p1 - 64, pc: p0 + 48, pd: p1);
}


// ========================================================================
// ?FwdTransformMacroblock@@YAXPAUhdpCodec_t@@@Z
// EA  : 0x828FC498
// RVA : 0x008FC498
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransformfwd.cpp
// ========================================================================

void __fastcall FwdTransformMacroblock(hdpCodec_t *codec)
{
  unsigned int currentMacroblockColumn; // r11
  unsigned __int8 v2; // r6
  unsigned int currentMacroblockRow; // r10
  hdpOverlap_t overlap; // r15
  hdpColorFormat_t colorFormat; // r7
  char v6; // r4
  BOOL v7; // r8
  bool v8; // r9
  BOOL v9; // r26
  BOOL v10; // r16
  char v11; // r14
  BOOL v12; // r20
  BOOL v13; // r25
  unsigned int v14; // r18
  unsigned int numChannels; // r11
  int v16; // r17
  __int16 **macroBlockColumnPtr1; // r23
  unsigned int i; // r19
  __int16 *v19; // r30
  __int16 *v20; // r31
  __int16 *v21; // r3
  __int16 *v22; // r3
  __int16 *v23; // r3
  int v24; // r11
  int v25; // r10
  __int16 *v26; // r28
  unsigned int v27; // r29
  signed int v28; // r11
  int v29; // r10
  __int16 *v30; // r29
  unsigned int v31; // r28
  unsigned int v32; // r29
  bool v33; // [sp+50h] [-A0h]

  currentMacroblockColumn = codec->currentMacroblockColumn;
  v2 = 0;
  currentMacroblockRow = codec->currentMacroblockRow;
  overlap = codec->codecParms.overlap;
  colorFormat = codec->codecParms.colorFormat;
  v6 = _cntlzw(codec->heightInMacroblocks - currentMacroblockRow);
  v7 = (_cntlzw(codec->widthInMacroblocks - currentMacroblockColumn) & 0x20) != 0;
  v8 = (_cntlzw(currentMacroblockRow) & 0x20) != 0;
  v9 = (_cntlzw(currentMacroblockColumn) & 0x20) != 0;
  v33 = v9 || v7;
  v10 = v8;
  if ( v8 || (v11 = 0, (v6 & 0x20) != 0) )
    v11 = 1;
  if ( v9 || v8 )
    v2 = 1;
  v12 = (v6 & 0x20) != 0;
  v13 = v7;
  v14 = 3 * (((_cntlzw((v6 & 0x20) != 0 || v8) & 0x20) != 0) + 2 * v12)
      + ((_cntlzw(v7 || v9) & 0x20) != 0)
      + ((2 * v7) & 0x1FE);
  if ( colorFormat == CF_YUV_420 || colorFormat == CF_YUV_422 )
    numChannels = 1;
  else
    numChannels = codec->codecParms.numChannels;
  if ( numChannels != 0 )
  {
    v16 = v2;
    macroBlockColumnPtr1 = codec->macroBlockColumnPtr1;
    for ( i = numChannels; i != 0; --i )
    {
      v19 = *(macroBlockColumnPtr1 - 16);
      v20 = *macroBlockColumnPtr1;
      if ( overlap != OL_NONE && v14 <= 8 )
      {
        switch ( v14 )
        {
          case 1u:
            PreFilter2x4Stage1(pa: v20 - 64, pb: *macroBlockColumnPtr1);
            PreFilter2x4Stage1(pa: v20, pb: v20 + 64);
            PreFilter2x4Stage1(pa: v20 + 64, pb: v20 + 128);
            PreFilter2x4Stage1(pa: v20 + 128, pb: v20 + 192);
            PreFilter4x4Stage1(p0: v20 - 52, p1: v20 + 8, p2: v20 - 44, p3: v20 + 16);
            PreFilter4x4Stage1(p0: v20 - 36, p1: v20 + 24, p2: v20 - 28, p3: v20 + 32);
            PreFilter4x4Stage1(p0: v20 - 20, p1: v20 + 40, p2: v20 - 12, p3: v20 + 48);
            PreFilter4x4Stage1_9(p: v20);
            break;
          case 2u:
            PreFilter4(pa: v20 - 60, pb: v20 - 59, pc: v20 - 58, pd: v20 - 57);
            PreFilter4x2Stage1(pa: v22, pb: v20 - 44);
            PreFilter4x2Stage1(pa: v20 - 44, pb: v20 - 28);
            PreFilter4x2Stage1(pa: v20 - 28, pb: v20 - 12);
            break;
          case 3u:
            PreFilter4x2Stage1(pa: v19 + 48, pb: *macroBlockColumnPtr1);
            PreFilter4x2Stage1(pa: v20, pb: v20 + 16);
            PreFilter4x2Stage1(pa: v20 + 16, pb: v20 + 32);
            PreFilter4x2Stage1(pa: v20 + 32, pb: v20 + 48);
            PreFilter4x4Stage1(p0: v19 + 60, p1: v19 + 120, p2: v20 + 4, p3: v20 + 64);
            PreFilter4x4Stage1(p0: v19 + 124, p1: v19 + 184, p2: v20 + 68, p3: v20 + 128);
            PreFilter4x4Stage1(p0: v19 + 188, p1: v19 + 248, p2: v20 + 132, p3: v20 + 192);
            PreFilter4x4Stage1_9(p: v20);
            break;
          case 4u:
            PreFilter4x4Stage1(p0: v19 - 4, p1: v19 + 56, p2: v20 - 60, p3: *macroBlockColumnPtr1);
            PreFilter4x4Stage1(p0: v19 + 60, p1: v19 + 120, p2: v20 + 4, p3: v20 + 64);
            PreFilter4x4Stage1(p0: v19 + 124, p1: v19 + 184, p2: v20 + 68, p3: v20 + 128);
            PreFilter4x4Stage1(p0: v19 + 188, p1: v19 + 248, p2: v20 + 132, p3: v20 + 192);
            PreFilter4x4Stage1(p0: v20 - 52, p1: v20 + 8, p2: v20 - 44, p3: v20 + 16);
            PreFilter4x4Stage1(p0: v20 - 36, p1: v20 + 24, p2: v20 - 28, p3: v20 + 32);
            PreFilter4x4Stage1(p0: v20 - 20, p1: v20 + 40, p2: v20 - 12, p3: v20 + 48);
            PreFilter4x4Stage1_9(p: v20);
            break;
          case 5u:
            PreFilter4x2Stage1(pa: v19 - 12, pb: v20 - 60);
            PreFilter4x2Stage1(pa: v20 - 60, pb: v20 - 44);
            PreFilter4x2Stage1(pa: v20 - 44, pb: v20 - 28);
            PreFilter4x2Stage1(pa: v20 - 28, pb: v20 - 12);
            break;
          case 6u:
            PreFilter4(pa: v19 + 56, pb: v19 + 57, pc: v19 + 58, pd: v19 + 59);
            PreFilter2x4Stage1(pa: v23, pb: v19 + 120);
            PreFilter2x4Stage1(pa: v19 + 120, pb: v19 + 184);
            PreFilter2x4Stage1(pa: v19 + 184, pb: v19 + 248);
            break;
          case 7u:
            PreFilter2x4Stage1(pa: v19 - 8, pb: v19 + 56);
            PreFilter2x4Stage1(pa: v19 + 56, pb: v19 + 120);
            PreFilter2x4Stage1(pa: v19 + 120, pb: v19 + 184);
            PreFilter2x4Stage1(pa: v19 + 184, pb: v19 + 248);
            break;
          default:
            if ( v14 != 0 )
            {
              PreFilter4(pa: v19 - 4, pb: v19 - 3, pc: v19 - 2, pd: v19 - 1);
            }
            else
            {
              PreFilter4(pa: *macroBlockColumnPtr1, pb: v20 + 1, pc: v20 + 2, pd: v20 + 3);
              PreFilter4x2Stage1(pa: v21, pb: v20 + 16);
              PreFilter4x2Stage1(pa: v20 + 16, pb: v20 + 32);
              PreFilter4x2Stage1(pa: v20 + 32, pb: v20 + 48);
              PreFilter2x4Stage1(pa: v20, pb: v20 + 64);
              PreFilter2x4Stage1(pa: v20 + 64, pb: v20 + 128);
              PreFilter2x4Stage1(pa: v20 + 128, pb: v20 + 192);
              PreFilter4x4Stage1_9(p: v20);
            }
            break;
        }
      }
      if ( !v10 )
      {
        v24 = !v9 ? -16 : 48;
        v25 = !v13 ? 240 : 48;
        if ( v24 < v25 )
        {
          v26 = &v19[v24];
          v27 = ((unsigned int)(v25 - v24 - 1) >> 6) + 1;
          do
          {
            FwdTransform4x4Stage1(p: v26);
            --v27;
            v26 += 64;
          }
          while ( v27 != 0 );
        }
      }
      if ( !v12 )
      {
        v28 = v9 ? 0 : 0xFFFFFFC0;
        v29 = v13 ? 0 : 0xC0;
        if ( v28 < v29 )
        {
          v30 = &v20[v28 + 32];
          v31 = ((unsigned int)(v29 - v28 - 1) >> 6) + 1;
          do
          {
            FwdTransform4x4Stage1(p: v30 - 32);
            FwdTransform4x4Stage1(p: v30 - 16);
            FwdTransform4x4Stage1(p: v30);
            --v31;
            v30 += 64;
          }
          while ( v31 != 0 );
        }
      }
      if ( overlap == OL_TWO )
      {
        if ( v33 )
        {
          if ( v11 == 0 )
          {
            v32 = v9 ? 0 : 0xFFFFFF80;
            PreFilter4(pa: &v19[v32 + 32], pb: &v19[v32 + 48], pc: &v20[v32], pd: &v20[v32 + 16]);
            PreFilter4(pa: &v19[v32 + 96], pb: &v19[v32 + 112], pc: &v20[v32 + 64], pd: &v20[v32 + 80]);
          }
        }
        else if ( v11 != 0 )
        {
          if ( !v10 )
            v20 = v19 + 32;
          PreFilter4(pa: v20 - 128, pb: v20 - 64, pc: v20, pd: v20 + 64);
          PreFilter4(pa: v20 - 112, pb: v20 - 48, pc: v20 + 16, pd: v20 + 80);
        }
        else
        {
          PreFilter4x4Stage2(p0: v19, p1: v20);
        }
      }
      if ( v16 == 0 )
        FwdTransform4x4Stage2(p: v19 - 256);
      ++macroBlockColumnPtr1;
    }
  }
}

