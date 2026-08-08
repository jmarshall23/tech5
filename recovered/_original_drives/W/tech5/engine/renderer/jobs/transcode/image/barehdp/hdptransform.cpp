
// ========================================================================
// ?Hadamard2x2dnStage1@@YAXPAF000@Z
// EA  : 0x828FB4A0
// RVA : 0x008FB4A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransform.cpp
// ========================================================================

void __fastcall Hadamard2x2dnStage1(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v4; // r9
  int v5; // r10
  int v6; // r11
  __int16 v7; // r8
  __int16 v8; // r7

  v4 = (__int16)(*pa + *pd);
  v5 = (__int16)(*pb - *pc);
  v6 = (v4 - v5) >> 1;
  v7 = v6 - *pc;
  v8 = v6 - *pd;
  *pa = v4 - v7;
  *pb = v8 + v5;
  *pc = v8;
  *pd = v7;
}


// ========================================================================
// ?Hadamard2x2upStage1@@YAXPAF000@Z
// EA  : 0x828FB528
// RVA : 0x008FB528
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransform.cpp
// ========================================================================

void __fastcall Hadamard2x2upStage1(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v4; // r9
  int v5; // r10
  int v6; // r11
  __int16 v7; // r8
  __int16 v8; // r7

  v4 = (__int16)(*pa + *pd);
  v5 = (__int16)(*pb - *pc);
  v6 = (v4 - v5 + 1) >> 1;
  v7 = v6 - *pc;
  v8 = v6 - *pd;
  *pa = v4 - v7;
  *pb = v8 + v5;
  *pc = v8;
  *pd = v7;
}


// ========================================================================
// ?Hadamard2x2dnStage2@@YAXPAF000@Z
// EA  : 0x828FB5B0
// RVA : 0x008FB5B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransform.cpp
// ========================================================================

void __fastcall Hadamard2x2dnStage2(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  __int16 v4; // r7
  __int16 v5; // r31
  __int16 v6; // r30
  __int16 v7; // r8
  __int16 v8; // r10

  v4 = *pa + *pd;
  v5 = *pb - *pc;
  v6 = *pc;
  v7 = (((v4 & 1) - (v5 & 1)) >> 1) - (v5 >> 1) + (v4 >> 1);
  v8 = v7 - *pd;
  *pa = v4 - (v7 - *pc);
  *pb = v8 + v5;
  *pc = v8;
  *pd = v7 - v6;
}


// ========================================================================
// ?Hadamard2x2upStage2@@YAXPAF000@Z
// EA  : 0x828FB638
// RVA : 0x008FB638
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdptransform.cpp
// ========================================================================

void __fastcall Hadamard2x2upStage2(__int16 *pa, __int16 *pb, __int16 *pc, __int16 *pd)
{
  int v4; // r11
  __int16 v5; // r31
  __int16 v6; // r8
  __int16 v7; // r7
  __int16 v8; // r8

  v4 = (__int16)(*pa + *pd);
  v5 = *pb - *pc;
  v6 = ((((*(_BYTE *)pa + *(_BYTE *)pd - 1) & 1) - (v5 & 1)) >> 1) + ((v4 + 1) >> 1) - (v5 >> 1);
  v7 = v6 - *pc;
  v8 = v6 - *pd;
  *pa = v4 - v7;
  *pb = v8 + v5;
  *pc = v8;
  *pd = v7;
}

