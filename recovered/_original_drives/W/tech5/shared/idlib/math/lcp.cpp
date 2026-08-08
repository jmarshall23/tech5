
// ========================================================================
// ??1idLCP@@UAA@XZ
// EA  : 0x82F30440
// RVA : 0x00F30440
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP::~idLCP(idLCP *this)
{
  this->__vftable = (idLCP_vtbl *)&idLCP::`vftable';
}


// ========================================================================
// Multiply_SIMD
// EA  : 0x82F30880
// RVA : 0x00F30880
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall Multiply_SIMD(float *dst, const float *src0, float *src1, int count)
{
  int v5; // r11
  float *v6; // r10
  int v7; // r9
  const float *v11; // r8
  float *v12; // r9
  const float *v13; // r10
  float *v14; // r11
  int v15; // ctr

  v5 = 0;
  if ( ((unsigned __int8)dst & 0xF) != 0 )
  {
    v6 = src1;
    while ( v5 < count )
    {
      ++v5;
      *(float *)((char *)v6 + (char *)dst - (char *)src1) = *(float *)((char *)v6 + (char *)src0 - (char *)src1) * *v6;
      ++v6;
    }
  }
  v7 = v5 + 4;
  if ( v5 + 4 <= count )
  {
    _R8 = (char *)src1 - (char *)src0;
    _R10 = &src0[v5];
    _R7 = (char *)dst - (char *)src0;
    do
    {
      __asm { lvx128    v63, r8, r10 }
      v7 += 4;
      __asm { lvx128    v62, r0, r10 }
      v5 += 4;
      __asm { vmulfp128 v61, v94, v63 }
      __asm { stvx128   v61, r7, r10 }
      _R10 += 4;
    }
    while ( v7 <= count );
  }
  if ( v5 < count )
  {
    if ( count - v5 >= 4 )
    {
      v11 = &src0[v5 - 1];
      v12 = &dst[v5 + 2];
      v13 = &src1[v5 + 1];
      do
      {
        v5 += 4;
        *(v12 - 2) = *(v13 - 1) * v11[1];
        *(float *)((char *)v13 + (char *)dst - (char *)src1) = *(const float *)((char *)v13 + (char *)src0
                                                                                            - (char *)src1)
                                                             * *v13;
        *v12 = *(float *)((char *)v12 + (char *)src0 - (char *)dst) * v13[1];
        v11 += 4;
        v12[1] = v13[2] * *v11;
        v13 += 4;
        v12 += 4;
      }
      while ( v5 < count - 3 );
    }
    if ( v5 < count )
    {
      v15 = count - v5;
      v14 = &src1[v5];
      do
      {
        *(float *)((char *)v14 + (char *)dst - (char *)src1) = *(float *)((char *)v14 + (char *)src0 - (char *)src1)
                                                             * *v14;
        ++v14;
        --v15;
      }
      while ( v15 != 0 );
    }
  }
}


// ========================================================================
// MultiplyAdd_SIMD
// EA  : 0x82F309E0
// RVA : 0x00F309E0
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall MultiplyAdd_SIMD(
        float *dst,
        double constant,
        const float *src,
        const int count,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18)
{
  int v19; // r10
  float *v20; // r11
  int v22; // r9
  float *v25; // r9
  float *v26; // r11
  double v27; // fp11
  double v28; // fp8
  double v29; // fp5
  float *v30; // r11
  int v31; // ctr

  a18 = constant;
  v19 = 0;
  if ( ((unsigned __int8)dst & 0xF) != 0 )
  {
    v20 = dst;
    while ( v19 < a5 )
    {
      ++v19;
      *v20 = (float)(*(float *)((char *)v20 + count - (_DWORD)dst) * (float)constant) + *v20;
      ++v20;
    }
  }
  _R11 = &a18;
  v22 = v19 + 4;
  __asm
  {
    lvlx128   v63, r0, r11
    vspltw128 v12, v63, 0
  }
  if ( v19 + 4 <= a5 )
  {
    _R8 = count - (_DWORD)dst;
    _R11 = &dst[v19];
    do
    {
      __asm { lvx128    v0, r0, r11 }
      v22 += 4;
      __asm { lvx128    v13, r11, r8 }
      v19 += 4;
      __asm { vmaddfp   v0, v13, v0, v12 }
      __asm { stvx128   v0, r0, r11 }
      _R11 += 4;
    }
    while ( v22 <= a5 );
  }
  if ( v19 < a5 )
  {
    if ( a5 - v19 >= 4 )
    {
      v25 = (float *)(4 * v19 + count - 4);
      v26 = &dst[v19 + 1];
      do
      {
        v19 += 4;
        v27 = *v26;
        *(v26 - 1) = (float)(v25[1] * (float)constant) + *(v26 - 1);
        v28 = v26[1];
        *v26 = (float)(*(float *)((char *)v26 + count - (_DWORD)dst) * (float)constant) + (float)v27;
        v29 = v26[2];
        v26[1] = (float)(v25[3] * (float)constant) + (float)v28;
        v25 += 4;
        v26[2] = (float)(*v25 * (float)constant) + (float)v29;
        v26 += 4;
      }
      while ( v19 < a5 - 3 );
    }
    if ( v19 < a5 )
    {
      v30 = &dst[v19];
      v31 = a5 - v19;
      do
      {
        *v30 = (float)(*(float *)((char *)v30 + count - (_DWORD)dst) * (float)constant) + *v30;
        ++v30;
        --v31;
      }
      while ( v31 != 0 );
    }
  }
}


// ========================================================================
// DotProduct_SIMD
// EA  : 0x82F30B28
// RVA : 0x00F30B28
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

float __fastcall DotProduct_SIMD(const float *src0, const float *src1, const int count)
{
  unsigned int v6; // ctr
  double v10; // fp1
  float back_chain; // [sp+0h] [-10h] BYREF

  __asm { vspltisw  v0, 0 }
  if ( count - 3 > 0 )
  {
    _R11 = src0;
    _R9 = (char *)src1 - (char *)src0;
    v6 = ((unsigned int)(count - 4) >> 2) + 1;
    do
    {
      __asm
      {
        lvx128    v12, r9, r11
        lvx128    v13, r0, r11
      }
      _R11 += 4;
      __asm { vmaddfp   v0, v13, v0, v12 }
      --v6;
    }
    while ( v6 != 0 );
  }
  _R11 = 4 * count;
  _R9 = &back_chain;
  _R8 = &vmx_float_one;
  __asm
  {
    lvrx      v13, r11, r4
    lvrx      v12, r11, r3
    vmaddfp   v0, v12, v0, v13
    lvx128    v63, r0, r8
    vmsum4fp128 v63, v0, v63
    stvewx128 v63, r0, r9
  }
  v10 = back_chain;
  return *((float *)&v10 + 1);
}


// ========================================================================
// LowerTriangularSolve_Generic
// EA  : 0x82F30B90
// RVA : 0x00F30B90
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall LowerTriangularSolve_Generic(const idMatX *L, float *x, const float *b, int n, int skip)
{
  int v5; // r29
  float *v6; // r30
  double v7; // fp11
  double v8; // fp13
  double v9; // fp0
  int v10; // r10
  float *v11; // r31
  float *v12; // r9
  float *v13; // r11

  if ( skip < n )
  {
    v5 = (char *)b - (char *)x;
    v6 = &x[skip];
    do
    {
      v7 = *(float *)((char *)v6 + v5);
      v8 = 0.0;
      v9 = 0.0;
      v10 = 0;
      v11 = &L->mat[L->numColumns * skip];
      if ( skip >= 2 )
      {
        v12 = v11 - 2;
        v13 = x + 1;
        do
        {
          v10 += 2;
          v12 += 2;
          v9 = (float)-(float)((float)(*(float *)((char *)v13 + (char *)v11 - (char *)x) * *v13) - (float)v9);
          v8 = (float)-(float)((float)(*(v13 - 1) * *v12) - (float)v8);
          v13 += 2;
        }
        while ( v10 < skip - 1 );
      }
      if ( v10 < skip )
        v7 = (float)-(float)((float)(v11[v10] * x[v10]) - *(float *)((char *)v6 + v5));
      ++skip;
      *v6++ = (float)((float)v9 + (float)v8) + (float)v7;
    }
    while ( skip < n );
  }
}


// ========================================================================
// LowerTriangularSolve_SIMD
// EA  : 0x82F30C50
// RVA : 0x00F30C50
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall LowerTriangularSolve_SIMD(const idMatX *L, float *x, float *b, int n, unsigned int skip)
{
  float *mat; // r11
  int numColumns; // r9
  float *v8; // r11
  float *v9; // r10
  float *v10; // r11
  float *v11; // r10
  float *v12; // r10
  float *v13; // r11
  float *v14; // r8
  int v15; // r11
  int v16; // r3
  unsigned int v22; // ctr
  int v23; // r30
  int v24; // r23
  unsigned int v38; // ctr
  int v41; // r30
  int v42; // r9
  int v44; // r29
  int v46; // r8
  unsigned int v48; // ctr

  if ( (int)skip >= n )
    return;
  mat = L->mat;
  numColumns = L->numColumns;
  if ( n < 8 )
  {
    switch ( (8 * n) | skip & 7 )
    {
      case 8u:
        *x = *b;
        return;
      case 0x10u:
        *x = *b;
        goto LABEL_6;
      case 0x11u:
LABEL_6:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        return;
      case 0x18u:
        *x = *b;
        goto LABEL_8;
      case 0x19u:
LABEL_8:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        goto LABEL_9;
      case 0x1Au:
LABEL_9:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        return;
      case 0x20u:
        *x = *b;
        goto LABEL_11;
      case 0x21u:
LABEL_11:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        goto LABEL_12;
      case 0x22u:
LABEL_12:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        goto LABEL_13;
      case 0x23u:
LABEL_13:
        x[3] = -(float)((float)(mat[3 * numColumns + 2] * x[2])
                      - (float)-(float)((float)(mat[3 * numColumns + 1] * x[1])
                                      - (float)-(float)((float)(*x * mat[3 * numColumns]) - b[3])));
        return;
      case 0x28u:
        *x = *b;
        goto LABEL_15;
      case 0x29u:
LABEL_15:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        goto LABEL_16;
      case 0x2Au:
LABEL_16:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        goto LABEL_17;
      case 0x2Bu:
LABEL_17:
        x[3] = -(float)((float)(mat[3 * numColumns + 2] * x[2])
                      - (float)-(float)((float)(mat[3 * numColumns + 1] * x[1])
                                      - (float)-(float)((float)(*x * mat[3 * numColumns]) - b[3])));
        goto LABEL_18;
      case 0x2Cu:
LABEL_18:
        v8 = &mat[4 * numColumns];
        x[4] = -(float)((float)(v8[3] * x[3])
                      - (float)-(float)((float)(v8[2] * x[2])
                                      - (float)-(float)((float)(v8[1] * x[1]) - (float)-(float)((float)(*v8 * *x) - b[4]))));
        return;
      case 0x30u:
        *x = *b;
        goto LABEL_20;
      case 0x31u:
LABEL_20:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        goto LABEL_21;
      case 0x32u:
LABEL_21:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        goto LABEL_22;
      case 0x33u:
LABEL_22:
        x[3] = -(float)((float)(mat[3 * numColumns + 2] * x[2])
                      - (float)-(float)((float)(mat[3 * numColumns + 1] * x[1])
                                      - (float)-(float)((float)(*x * mat[3 * numColumns]) - b[3])));
        goto LABEL_23;
      case 0x34u:
LABEL_23:
        v9 = &mat[4 * numColumns];
        x[4] = -(float)((float)(v9[3] * x[3])
                      - (float)-(float)((float)(v9[2] * x[2])
                                      - (float)-(float)((float)(v9[1] * x[1]) - (float)-(float)((float)(*v9 * *x) - b[4]))));
        goto LABEL_24;
      case 0x35u:
LABEL_24:
        v10 = &mat[5 * numColumns];
        x[5] = -(float)((float)(v10[4] * x[4])
                      - (float)-(float)((float)(v10[3] * x[3])
                                      - (float)-(float)((float)(v10[2] * x[2])
                                                      - (float)-(float)((float)(v10[1] * x[1])
                                                                      - (float)-(float)((float)(*v10 * *x) - b[5])))));
        return;
      case 0x38u:
        *x = *b;
        goto LABEL_26;
      case 0x39u:
LABEL_26:
        x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
        goto LABEL_27;
      case 0x3Au:
LABEL_27:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        goto LABEL_28;
      case 0x3Bu:
LABEL_28:
        x[3] = -(float)((float)(mat[3 * numColumns + 2] * x[2])
                      - (float)-(float)((float)(mat[3 * numColumns + 1] * x[1])
                                      - (float)-(float)((float)(*x * mat[3 * numColumns]) - b[3])));
        goto LABEL_29;
      case 0x3Cu:
LABEL_29:
        v11 = &mat[4 * numColumns];
        x[4] = -(float)((float)(v11[3] * x[3])
                      - (float)-(float)((float)(v11[2] * x[2])
                                      - (float)-(float)((float)(v11[1] * x[1])
                                                      - (float)-(float)((float)(*v11 * *x) - b[4]))));
        goto LABEL_30;
      case 0x3Du:
LABEL_30:
        v12 = &mat[5 * numColumns];
        x[5] = -(float)((float)(v12[4] * x[4])
                      - (float)-(float)((float)(v12[3] * x[3])
                                      - (float)-(float)((float)(v12[2] * x[2])
                                                      - (float)-(float)((float)(v12[1] * x[1])
                                                                      - (float)-(float)((float)(*v12 * *x) - b[5])))));
        goto LABEL_31;
      case 0x3Eu:
LABEL_31:
        v13 = &mat[6 * numColumns];
        x[6] = -(float)((float)(v13[5] * x[5])
                      - (float)-(float)((float)(v13[4] * x[4])
                                      - (float)-(float)((float)(v13[3] * x[3])
                                                      - (float)-(float)((float)(v13[2] * x[2])
                                                                      - (float)-(float)((float)(v13[1] * x[1])
                                                                                      - (float)-(float)((float)(*v13 * *x) - b[6]))))));
        break;
      default:
        return;
    }
    return;
  }
  if ( skip <= 3 )
  {
    if ( skip != 1 )
    {
      if ( skip == 2 )
      {
LABEL_38:
        x[2] = -(float)((float)(mat[2 * numColumns + 1] * x[1])
                      - (float)-(float)((float)(*x * mat[2 * numColumns]) - b[2]));
        goto LABEL_39;
      }
      if ( skip != 0 )
      {
LABEL_39:
        skip = 4;
        x[3] = -(float)((float)(mat[3 * numColumns + 2] * x[2])
                      - (float)-(float)((float)(mat[3 * numColumns + 1] * x[1])
                                      - (float)-(float)((float)(*x * mat[3 * numColumns]) - b[3])));
        goto LABEL_40;
      }
      *x = *b;
    }
    x[1] = -(float)((float)(mat[numColumns] * *x) - b[1]);
    goto LABEL_38;
  }
LABEL_40:
  v14 = L->mat;
  v15 = skip * L->numColumns;
  v16 = skip;
  _R11 = &v14[v15];
  _R16 = &vmx_float_one;
  if ( (skip & 3) != 0 )
  {
    _R10 = 4 * skip;
    do
    {
      if ( v16 >= n )
        break;
      __asm
      {
        vspltisw  v12, 0
        lvlx128   v63, r10, r5
      }
      __asm { vrlimi128 v12, v63, 8, 0 }
      if ( v16 - 3 > 0 )
      {
        _R8 = _R11;
        _R31 = (char *)((char *)x - (char *)_R11);
        v22 = ((unsigned int)(v16 - 4) >> 2) + 1;
        do
        {
          __asm
          {
            lvx128    v0, r31, r8
            lvx128    v13, r0, r8
          }
          _R8 += 4;
          __asm { vnmsubfp  v12, v13, v12, v0 }
          --v22;
        }
        while ( v22 != 0 );
      }
      __asm { lvrx      v13, r10, r11 }
      ++v16;
      __asm { lvrx      v0, r10, r4 }
      __asm
      {
        vnmsubfp  v12, v13, v12, v0
        lvx128    v63, r0, r16
      }
      _R11 += numColumns;
      __asm
      {
        vmsum4fp128 v62, v12, v63
        stvewx128 v62, r4, r10
      }
      _R10 += 4;
    }
    while ( (v16 & 3) != 0 );
  }
  v23 = v16 + 3;
  if ( v16 + 3 < n )
  {
    __asm { vspltisw128 v63, 0 }
    v24 = 16 * numColumns;
    _R8 = 4 * (v16 + 1);
    _R27 = (char *)((char *)x - (char *)_R11);
    _R10 = &_R11[2 * numColumns];
    _R19 = -1 * numColumns;
    _R18 = numColumns;
    _R17 = b - 1;
    _R21 = x - 1;
    do
    {
      __asm
      {
        vor128    v61, v95, v63
        lvx128    v60, r17, r8
        vor128    v59, v95, v63
        lvx128    v58, r0, r4
        vor128    v57, v95, v63
        lvx128    v7, r0, r11
        vor128    v56, v95, v63
        lvx128    v8, r19, r10
        vrlimi128 v61, v60, 8, 0
        lvx128    v10, r0, r10
        vrlimi128 v59, v60, 4, 0
        lvx128    v12, r18, r10
        vrlimi128 v57, v60, 2, 0
      }
      _R29 = &_R10[_R19];
      __asm { vrlimi128 v56, v60, 1, 0 }
      _R31 = &_R10[_R18];
      __asm { vor128    v13, v90, v58 }
      __asm
      {
        vor128    v0, v93, v61
        vor128    v9, v90, v58
        vor128    v11, v90, v58
        vor128    v5, v91, v59
        vor128    v4, v89, v57
        vnmsubfp128 v0, v7, v13, v0
        vor128    v3, v88, v56
        vnmsubfp128 v5, v8, v9, v5
        vnmsubfp128 v4, v10, v11, v4
        vnmsubfp128 v3, v12, v13, v3
      }
      if ( v16 > 4 )
      {
        _R7 = (int)_R10 + 16 - 8 * numColumns;
        _R26 = (char *)_R29 - (char *)_R11;
        _R25 = (char *)_R10 - (char *)_R11;
        _R24 = (char *)_R31 - (char *)_R11;
        v38 = ((unsigned int)(v23 - 8) >> 2) + 1;
        do
        {
          __asm
          {
            lvx128    v13, r27, r7
            vmr       v7, v13
            lvx128    v6, r0, r7
            vmr       v9, v13
            lvx128    v8, r26, r7
            vmr       v11, v13
            lvx128    v10, r25, r7
            lvx128    v12, r24, r7
          }
          _R7 += 16;
          __asm
          {
            vnmsubfp  v0, v6, v0, v7
            vnmsubfp  v5, v8, v5, v9
            vnmsubfp  v4, v10, v4, v11
            vnmsubfp  v3, v12, v3, v13
          }
          --v38;
        }
        while ( v38 != 0 );
      }
      _R7 = _R8 - 4;
      __asm
      {
        lvlx128   v55, r8, r10
        lvlx128   v54, r8, r31
      }
      _R28 = _R8 + 4;
      __asm { vspltw128 v9, v55, 0 }
      v23 += 4;
      __asm { vspltw128 v11, v54, 0 }
      _R11 = (float *)((char *)_R11 + v24);
      _R27 -= 16 * numColumns;
      __asm { lvlx128   v52, r7, r10 }
      _R10 = (float *)((char *)_R10 + v24);
      __asm { lvlx128   v53, r7, r29 }
      v16 += 4;
      __asm
      {
        vspltw128 v7, v52, 0
        lvlx128   v51, r7, r31
        vspltw128 v2, v53, 0
        lvlx128   v50, r28, r31
        vspltw128 v10, v51, 0
      }
      __asm
      {
        vspltw128 v12, v50, 0
        vnmsubfp  v6, v7, v4, v0
        vnmsubfp  v5, v2, v5, v0
        vnmsubfp  v7, v10, v3, v0
        vnmsubfp  v8, v9, v6, v5
        vnmsubfp  v10, v11, v7, v5
        vmr       v13, v8
        vmrghw128 v49, v0, v8
        vmrglw128 v48, v0, v8
        vnmsubfp  v0, v12, v10, v13
        vmrghw128 v47, v5, v0
        vmrglw128 v46, v5, v0
        vmrglw128 v45, v81, v47
        vmrglw128 v44, v80, v46
        vmrghw128 v43, v80, v46
        vmrghw128 v42, v81, v47
        vaddfp128 v41, v75, v44
        vaddfp128 v40, v74, v45
        vaddfp128 v39, v72, v41
        stvx128   v39, r21, r8
      }
      _R8 += 16;
    }
    while ( v23 < n );
  }
  if ( v16 < n )
  {
    __asm { vspltisw128 v62, 0 }
    v41 = 4 * numColumns;
    _R10 = 4 * v16;
    v44 = -4 * numColumns;
    v42 = v16 - 3;
    _R31 = (char *)((char *)x - (char *)_R11);
    v46 = n - v16;
    do
    {
      __asm
      {
        vor128    v12, v94, v62
        lvlx128   v38, r10, r5
      }
      __asm { vrlimi128 v12, v38, 8, 0 }
      if ( v42 > 0 )
      {
        _R7 = _R11;
        v48 = ((unsigned int)(v42 - 1) >> 2) + 1;
        do
        {
          __asm
          {
            lvx128    v0, r7, r31
            lvx128    v13, r0, r7
          }
          _R7 += 4;
          __asm { vnmsubfp  v12, v13, v12, v0 }
          --v48;
        }
        while ( v48 != 0 );
      }
      __asm { lvrx      v13, r10, r11 }
      --v46;
      __asm { lvrx      v0, r10, r4 }
      _R11 = (float *)((char *)_R11 + v41);
      __asm
      {
        vnmsubfp  v12, v13, v12, v0
        lvx128    v63, r0, r16
      }
      _R31 += v44;
      ++v42;
      __asm
      {
        vmsum4fp128 v37, v12, v63
        stvewx128 v37, r4, r10
      }
      _R10 += 4;
    }
    while ( v46 != 0 );
  }
}


// ========================================================================
// LowerTriangularSolveTranspose_Generic
// EA  : 0x82F31588
// RVA : 0x00F31588
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall LowerTriangularSolveTranspose_Generic(const idMatX *L, float *x, const float *b, int n)
{
  int v4; // r23
  int numColumns; // r29
  int v6; // r30
  int v7; // r25
  int v8; // r26
  float *v9; // r31
  int v10; // r28
  int v11; // r24
  int v12; // r27
  int v13; // r22
  int v14; // r10
  double v15; // fp10
  double v16; // fp0
  double v17; // fp13
  float *v18; // r5
  int v19; // r11
  float *v20; // r9
  float *v21; // r8
  float *v22; // r7

  v4 = n - 1;
  numColumns = L->numColumns;
  v6 = n - 1;
  if ( n - 1 >= 0 )
  {
    v7 = 0;
    v8 = v4;
    v9 = &x[v4];
    v10 = 4 * n * numColumns;
    v11 = -4 * numColumns;
    v12 = 4 * (v4 + 2) * numColumns;
    v13 = (char *)b - (char *)x;
    do
    {
      v14 = v6 + 1;
      v15 = *(float *)((char *)v9 + v13);
      v16 = 0.0;
      v17 = 0.0;
      v18 = &L->mat[v8];
      if ( v6 + 1 < n )
      {
        if ( v7 >= 2 )
        {
          v19 = 8 * numColumns;
          v20 = v9;
          v21 = (float *)((char *)v18 + v10 - 8 * numColumns);
          v22 = (float *)((char *)v18 + v12 - 8 * numColumns);
          do
          {
            v14 += 2;
            v21 = (float *)((char *)v21 + v19);
            v16 = (float)-(float)((float)(v20[1] * *v21) - (float)v16);
            v22 = (float *)((char *)v22 + v19);
            v20 += 2;
            v17 = (float)-(float)((float)(*v22 * *v20) - (float)v17);
          }
          while ( v14 < v4 );
        }
        if ( v14 < n )
          v15 = (float)-(float)((float)(v18[v14 * numColumns] * x[v14]) - *(float *)((char *)v9 + v13));
        v15 = (float)((float)((float)v17 + (float)v16) + (float)v15);
      }
      *v9 = v15;
      --v6;
      ++v7;
      v10 += v11;
      v12 += v11;
      --v8;
      --v9;
    }
    while ( v6 >= 0 );
  }
}


// ========================================================================
// LowerTriangularSolveTranspose_SIMD
// EA  : 0x82F31698
// RVA : 0x00F31698
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall LowerTriangularSolveTranspose_SIMD(const idMatX *L, float *x, const float *b, int n)
{
  int v5; // r24
  int numColumns; // r11
  int v7; // r8
  float *v8; // r10
  int v9; // r9
  double v10; // fp0
  double v11; // fp0
  int v12; // r31
  double v13; // fp10
  float *mat; // r9
  int v18; // r7
  int v19; // r30
  int v22; // r4
  unsigned int v28; // ctr
  int i; // ctr

  v5 = n & 3;
  numColumns = L->numColumns;
  v7 = n;
  if ( (n & 3) != 0 )
  {
    v8 = &L->mat[(numColumns + 1) * n];
    if ( v5 == 1 )
    {
      v7 = n - 1;
      x[n - 1] = b[n - 1];
    }
    else
    {
      v9 = n;
      if ( v5 == 2 )
      {
        v7 = n - 2;
        v10 = b[v9 - 1];
        x[v9 - 1] = b[v9 - 1];
        x[n - 2] = -(float)((float)(v8[-numColumns - 2] * (float)v10) - b[n - 2]);
      }
      else
      {
        v11 = b[v9 - 1];
        v12 = n - 2;
        x[v9 - 1] = b[v9 - 1];
        v7 = n - 3;
        v13 = (float)-(float)((float)(v8[-numColumns - 2] * (float)v11) - b[v12]);
        x[v12] = -(float)((float)(v8[-numColumns - 2] * (float)v11) - b[v12]);
        x[n - 3] = -(float)((float)(v8[-2 * numColumns - 3] * (float)v13)
                          - (float)-(float)((float)(v8[-numColumns - 3] * (float)v11) - b[n - 3]));
      }
    }
  }
  _R31 = 4 * numColumns;
  mat = L->mat;
  _R27 = 4 * numColumns + 4;
  _R3 = &x[v7];
  v18 = v7;
  v19 = (int)mat + _R27 * v7 - 16;
  if ( v7 >= 4 )
  {
    __asm { vspltisw128 v63, 0 }
    _R29 = 8 * numColumns;
    _R28 = 12 * numColumns;
    v22 = 16 * numColumns;
    _R26 = 12 * numColumns + 12;
    _R25 = 8 * numColumns + 8;
    _R6 = &b[v7 - 4];
    do
    {
      __asm
      {
        lvx128    v6, r0, r6
        vor128    v5, v95, v63
        vor128    v4, v95, v63
      }
      _R10 = _R3;
      __asm { vor128    v3, v95, v63 }
      _R11 = v19;
      if ( v18 < v7 )
      {
        v28 = ((unsigned int)(v7 - v18 - 1) >> 2) + 1;
        do
        {
          __asm { lvx128    v62, r0, r10 }
          _R10 += 4;
          __asm
          {
            lvx128    v7, r0, r11
            vspltw128 v8, v62, 0
            lvx128    v10, r31, r11
            vspltw128 v9, v62, 1
            lvx128    v12, r29, r11
            vspltw128 v11, v62, 2
            lvx128    v0, r28, r11
            vspltw128 v13, v62, 3
          }
          _R11 += v22;
          __asm
          {
            vnmsubfp  v6, v8, v6, v7
            vnmsubfp  v5, v9, v5, v10
            vnmsubfp  v4, v11, v4, v12
            vnmsubfp  v3, v13, v3, v0
          }
          --v28;
        }
        while ( v28 != 0 );
      }
      if ( v5 > 0 )
      {
        _R9 = 0;
        for ( i = v5; i != 0; --i )
        {
          __asm { lvlx128   v61, r9, r10 }
          _R9 += 4;
          __asm { lvx128    v13, r0, r11 }
          _R11 += _R31;
          __asm
          {
            vspltw128 v0, v61, 0
            vnmsubfp  v6, v13, v6, v0
          }
        }
      }
      __asm { vaddfp128 v60, v6, v5 }
      _R11 = v19 - v22;
      __asm { vaddfp128 v59, v4, v3 }
      v18 -= 4;
      _R3 -= 4;
      _R6 -= 4;
      __asm { lvrx128   v58, r26, r11 }
      __asm { lvrx128   v57, r25, r11 }
      v19 = v19 - v22 - 16;
      __asm
      {
        vsldoi128 v11, v90, v58, 4
        lvrx128   v56, r27, r11
        vsldoi128 v12, v89, v57, 8
        vsldoi128 v13, v88, v56, 0xC
        vaddfp128 v10, v92, v59
        vspltw    v0, v10, 3
        vnmsubfp  v10, v11, v10, v0
        vspltw    v0, v10, 2
        vnmsubfp  v11, v12, v10, v0
        vspltw    v0, v11, 1
        vnmsubfp  v12, v13, v11, v0
        stvx128   v12, r0, r10
      }
    }
    while ( v18 >= 4 );
  }
}


// ========================================================================
// LDLT_Factor_Generic
// EA  : 0x82F31900
// RVA : 0x00F31900
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

int __fastcall LDLT_Factor_Generic(idMatX *mat, idVecX *invDiag, const int n)
{
  int v3; // r5
  int v4; // r4
  int v5; // r3
  int v6; // r24
  int v7; // r27
  int v8; // r12
  unsigned int i; // r25
  double v10; // fp0
  float *v11; // r10
  double v12; // fp13
  int v13; // r7
  float *v14; // r6
  double v15; // fp11
  int v16; // r30
  float *v17; // r9
  float *v18; // r11
  int v19; // r8
  double v20; // fp7
  double v21; // fp12
  double v22; // fp3
  double v23; // fp7
  double v24; // fp0
  int v25; // r11
  int v26; // r30
  double v27; // fp10
  int v28; // ctr
  int v29; // r8
  double v30; // fp11
  float *v31; // r29
  double v32; // fp13
  int v33; // r10
  double v34; // fp0
  float *v35; // r9
  float *v36; // r11
  _DWORD back_chain[20]; // [sp+0h] [-A0h]
  char v39; // [sp+50h] [-50h] BYREF
  _BYTE v40[76]; // [sp+54h] [-4Ch] BYREF

  v5 = ((int (*)(void))RtlCheckStack12)();
  v6 = *(_DWORD *)(v5 + 4);
  v7 = 0;
  *(_DWORD *)((char *)back_chain + v8) = back_chain[0];
  if ( v3 <= 0 )
    return 1;
  for ( i = 0; ; i += 4 )
  {
    v10 = 0.0;
    v11 = *(float **)(v5 + 12);
    v12 = 0.0;
    v13 = 0;
    v14 = &v11[*(_DWORD *)(v5 + 4) * v7];
    v15 = v14[i / 4];
    if ( v7 >= 2 )
    {
      v16 = v6 + 1;
      v17 = v14 - 2;
      v18 = (float *)v40;
      v19 = (char *)v14 - &v39;
      do
      {
        v13 += 2;
        v20 = (float)(v17[2] * *v11);
        *(v18 - 1) = v17[2] * *v11;
        v17 += 2;
        v21 = *v17;
        v22 = (float)(*(float *)((char *)v18 + v19) * v11[v16]);
        *v18 = *(float *)((char *)v18 + v19) * v11[v16];
        v11 = (float *)((char *)v11 + v16 * 4 + v16 * 4);
        v10 = (float)-(float)((float)((float)v20 * (float)v21) - (float)v10);
        v12 = (float)-(float)((float)(*(float *)((char *)v18 + v19) * (float)v22) - (float)v12);
        v18 += 2;
      }
      while ( v13 < v7 - 1 );
    }
    if ( v13 < v7 )
    {
      v23 = (float)(v14[v13] * *v11);
      *(float *)(v40 + 4 * v13 + 2) = v14[v13] * *v11;
      v11 += v6 + 1;
      v15 = (float)-(float)((float)((float)v23 * v14[v13]) - (float)v15);
    }
    v24 = (float)((float)((float)v12 + (float)v10) + (float)v15);
    if ( __fabs(v24) < idMath::FLT_SMALLEST_NON_DENORMAL )
      break;
    v25 = *(_DWORD *)(v4 + 8);
    v26 = v7 + 1;
    *v11 = v24;
    v27 = (float)((float)1.0 / (float)v24);
    *(float *)(v25 + i) = (float)1.0 / (float)v24;
    if ( v7 + 1 < v3 )
    {
      v28 = v3 - v26;
      v29 = 4 * *(_DWORD *)(v5 + 4) * v26 + *(_DWORD *)(v5 + 12);
      do
      {
        v30 = *(float *)(i + v29);
        v31 = (float *)(i + v29);
        v32 = 0.0;
        v33 = 0;
        v34 = 0.0;
        if ( v7 >= 2 )
        {
          v35 = (float *)(v29 - 8);
          v36 = (float *)v40;
          do
          {
            v33 += 2;
            v35 += 2;
            v34 = (float)-(float)((float)(*(float *)((char *)v36 + v29 - (_DWORD)&v39) * *v36) - (float)v34);
            v32 = (float)-(float)((float)(*(v36 - 1) * *v35) - (float)v32);
            v36 += 2;
          }
          while ( v33 < v7 - 1 );
        }
        if ( v33 < v7 )
          v30 = (float)-(float)((float)(*(float *)(4 * v33 + v29) * *(float *)(v40 + 4 * v33 + 2)) - *(float *)(i + v29));
        v29 += 4 * v6;
        *v31 = (float)((float)((float)v34 + (float)v32) + (float)v30) * (float)v27;
        --v28;
      }
      while ( v28 != 0 );
    }
    ++v7;
    if ( v26 >= v3 )
      return 1;
  }
  return 0;
}


// ========================================================================
// LDLT_Factor_SIMD
// EA  : 0x82F31B30
// RVA : 0x00F31B30
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

int __fastcall LDLT_Factor_SIMD(idMatX *mat, idVecX *invDiag, int n)
{
  int v5; // r3
  int v6; // r12
  __int64 v8; // r4
  _DWORD *v10; // r20
  int v12; // r11
  int v13; // r12
  int *v15; // r21
  double v16; // fp0
  double v19; // fp0
  int v20; // r4
  int v21; // r5
  int v22; // r10
  float *v23; // r7
  float *v24; // r9
  float *v25; // r6
  float *v26; // r8
  float *v27; // r10
  int v28; // ctr
  float *v29; // r10
  double v30; // fp11
  double v31; // fp13
  int v32; // r5
  int v33; // r4
  int v34; // r10
  float *v35; // r6
  float *v36; // r9
  float *v37; // r7
  float *v38; // r8
  float *v39; // r10
  int v40; // ctr
  float *v41; // r10
  double v42; // fp11
  double v43; // fp8
  double v44; // fp7
  double v45; // fp13
  int v46; // r5
  int v47; // r4
  int v48; // r6
  float *v49; // r7
  float *v50; // r10
  float *v51; // r8
  float *v52; // r9
  float *v53; // r10
  int v54; // ctr
  float *v55; // r10
  double v56; // fp11
  double v57; // fp7
  double v58; // fp5
  double v59; // fp1
  double v60; // fp2
  double v61; // fp13
  int v62; // r5
  int v63; // r4
  int v64; // r6
  float *v65; // r7
  float *v66; // r8
  float *v67; // r9
  float *v68; // r10
  int v69; // r9
  float *v70; // r11
  int v71; // ctr
  int v75; // r23
  int v79; // r25
  unsigned int v81; // r7
  unsigned int v85; // ctr
  int v88; // r3
  int v89; // r5
  unsigned int v94; // r4
  unsigned int v100; // ctr
  unsigned int v102; // r7
  unsigned int v106; // ctr
  _DWORD back_chain[20]; // [sp+0h] [-110h]
  float v110; // [sp+50h] [-C0h] BYREF
  float v111; // [sp+54h] [-BCh]
  float v112; // [sp+58h] [-B8h]
  float v113; // [sp+5Ch] [-B4h]
  _BYTE v114[16]; // [sp+60h] [-B0h] BYREF
  int v115; // [sp+70h] [-A0h] BYREF

  _R12 = -176;
  __asm { stvx128   v127, r1, r12 }
  v5 = ((int (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v6) = back_chain[0];
  _R30 = &v110;
  v8 = ((__int64 (__fastcall *)(int))RtlCheckStack12)(a1: v5);
  v10 = (_DWORD *)(HIDWORD(v8) + 4);
  _R15 = *(float **)(v8 + 8);
  v12 = *(_DWORD *)(HIDWORD(v8) + 4);
  *(_DWORD *)((char *)back_chain + v13) = back_chain[0];
  _R19 = &v110;
  if ( n > 0 )
  {
    v15 = (int *)(HIDWORD(v8) + 12);
    v16 = **(float **)(HIDWORD(v8) + 12);
    if ( __fabs(v16) < idMath::FLT_SMALLEST_NON_DENORMAL )
    {
LABEL_3:
      _R0 = -176;
      __asm { lvx128    v127, r1, r0 }
      return 0;
    }
    v110 = **(float **)(HIDWORD(v8) + 12);
    v19 = (float)((float)1.0 / (float)v16);
    *_R15 = v19;
    if ( n > 1 )
    {
      v20 = *v15;
      v21 = 1;
      if ( n - 1 >= 4 )
      {
        v22 = 16 * v12;
        v23 = (float *)(12 * v12 + v20);
        v24 = (float *)(4 * v12 + v20);
        v25 = (float *)(16 * v12 + v20);
        v26 = (float *)(8 * v12 + v20);
        do
        {
          v21 += 4;
          *v24 = *v24 * (float)v19;
          *v26 = *v26 * (float)v19;
          v24 = (float *)((char *)v24 + v22);
          *v23 = *v23 * (float)v19;
          v26 = (float *)((char *)v26 + v22);
          *v25 = *v25 * (float)v19;
          v23 = (float *)((char *)v23 + v22);
          v25 = (float *)((char *)v25 + v22);
        }
        while ( v21 < n - 3 );
      }
      if ( v21 < n )
      {
        v27 = (float *)(4 * v21 * v12 + v20);
        v28 = n - v21;
        do
        {
          *v27 = *v27 * (float)v19;
          v27 += v12;
          --v28;
        }
        while ( v28 != 0 );
      }
      v29 = (float *)(4 * *v10 + *v15);
      v30 = (float)(v110 * *v29);
      v110 = v110 * *v29;
      v31 = (float)-(float)((float)((float)v30 * *v29) - v29[1]);
      if ( __fabs(v31) < idMath::FLT_SMALLEST_NON_DENORMAL )
        goto LABEL_3;
      *(float *)(4 * (*v10 + 1) + *v15) = -(float)((float)((float)v30 * *v29) - v29[1]);
      v111 = v31;
      _R15[1] = (float)1.0 / (float)v31;
      if ( n > 2 )
      {
        v32 = *v15;
        v33 = 2;
        if ( n - 2 >= 4 )
        {
          v34 = 16 * v12;
          v35 = (float *)(20 * v12 + v32 + 4);
          v36 = (float *)(8 * v12 + v32 + 4);
          v37 = (float *)(16 * v12 + v32 + 4);
          v38 = (float *)(12 * v12 + v32 + 4);
          do
          {
            v33 += 4;
            *v36 = (float)-(float)((float)(*(v36 - 1) * v110) - *v36) * (float)((float)1.0 / (float)v31);
            v36 = (float *)((char *)v36 + v34);
            *v38 = (float)-(float)((float)(*(v38 - 1) * v110) - *v38) * (float)((float)1.0 / (float)v31);
            v38 = (float *)((char *)v38 + v34);
            *v37 = (float)-(float)((float)(*(v37 - 1) * v110) - *v37) * (float)((float)1.0 / (float)v31);
            v37 = (float *)((char *)v37 + v34);
            *v35 = (float)-(float)((float)(*(v35 - 1) * v110) - *v35) * (float)((float)1.0 / (float)v31);
            v35 = (float *)((char *)v35 + v34);
          }
          while ( v33 < n - 3 );
        }
        if ( v33 < n )
        {
          v39 = (float *)(4 * (v33 * v12 + 1) + v32);
          v40 = n - v33;
          do
          {
            *v39 = (float)-(float)((float)(*(v39 - 1) * v110) - *v39) * (float)((float)1.0 / (float)v31);
            v39 += v12;
            --v40;
          }
          while ( v40 != 0 );
        }
        v41 = (float *)(8 * *v10 + *v15);
        v42 = (float)(v110 * *v41);
        v110 = v110 * *v41;
        v43 = *v41;
        v44 = (float)(v41[1] * v111);
        v111 = v41[1] * v111;
        v45 = (float)-(float)((float)(v41[1] * (float)v44) - (float)(v41[2] - (float)((float)v42 * (float)v43)));
        if ( __fabs(v45) < idMath::FLT_SMALLEST_NON_DENORMAL )
          goto LABEL_3;
        *(float *)(8 * (*v10 + 1) + *v15) = -(float)((float)(v41[1] * (float)v44)
                                                   - (float)(v41[2] - (float)((float)v42 * (float)v43)));
        v112 = v45;
        _R15[2] = (float)1.0 / (float)v45;
        if ( n > 3 )
        {
          v46 = *v15;
          v47 = 3;
          if ( n - 3 >= 4 )
          {
            v48 = 16 * v12;
            v49 = (float *)(24 * v12 + v46 + 8);
            v50 = (float *)(12 * v12 + v46 + 8);
            v51 = (float *)(20 * v12 + v46 + 8);
            v52 = (float *)(16 * v12 + v46 + 8);
            do
            {
              v47 += 4;
              *v50 = (float)-(float)((float)(*(v50 - 1) * v111) - (float)-(float)((float)(*(v50 - 2) * v110) - *v50))
                   * (float)((float)1.0 / (float)v45);
              v50 = (float *)((char *)v50 + v48);
              *v52 = (float)-(float)((float)(*(v52 - 1) * v111) - (float)-(float)((float)(*(v52 - 2) * v110) - *v52))
                   * (float)((float)1.0 / (float)v45);
              v52 = (float *)((char *)v52 + v48);
              *v51 = (float)-(float)((float)(*(v51 - 1) * v111) - (float)-(float)((float)(*(v51 - 2) * v110) - *v51))
                   * (float)((float)1.0 / (float)v45);
              v51 = (float *)((char *)v51 + v48);
              *v49 = (float)-(float)((float)(*(v49 - 1) * v111) - (float)-(float)((float)(*(v49 - 2) * v110) - *v49))
                   * (float)((float)1.0 / (float)v45);
              v49 = (float *)((char *)v49 + v48);
            }
            while ( v47 < n - 3 );
          }
          if ( v47 < n )
          {
            v53 = (float *)(4 * (v47 * v12 + 2) + v46);
            v54 = n - v47;
            do
            {
              *v53 = (float)-(float)((float)(*(v53 - 1) * v111) - (float)-(float)((float)(*(v53 - 2) * v110) - *v53))
                   * (float)((float)1.0 / (float)v45);
              v53 += v12;
              --v54;
            }
            while ( v54 != 0 );
          }
          v55 = (float *)(12 * *v10 + *v15);
          v56 = (float)(v110 * *v55);
          v110 = v110 * *v55;
          v57 = (float)(v55[1] * v111);
          v58 = (float)((float)v56 * *v55);
          v111 = v55[1] * v111;
          v59 = v55[1];
          v60 = (float)(v55[2] * v112);
          v112 = v55[2] * v112;
          v61 = (float)-(float)((float)(v55[2] * (float)v60)
                              - (float)((float)(v55[3] - (float)v58) - (float)((float)v59 * (float)v57)));
          if ( __fabs(v61) < idMath::FLT_SMALLEST_NON_DENORMAL )
            goto LABEL_3;
          *(float *)(12 * (*v10 + 1) + *v15) = -(float)((float)(v55[2] * (float)v60)
                                                      - (float)((float)(v55[3] - (float)v58)
                                                              - (float)((float)v59 * (float)v57)));
          v113 = v61;
          _R15[3] = (float)1.0 / (float)v61;
          if ( n > 4 )
          {
            v62 = *v15;
            v63 = 4;
            if ( n - 4 >= 4 )
            {
              v64 = 16 * v12;
              v65 = (float *)(16 * v12 + v62 + 12);
              v66 = (float *)(28 * v12 + v62 + 12);
              v67 = (float *)(24 * v12 + v62 + 12);
              v68 = (float *)(20 * v12 + v62 + 12);
              do
              {
                v63 += 4;
                *v65 = (float)-(float)((float)(v112 * *(v65 - 1))
                                     - (float)-(float)((float)(*(v65 - 2) * v111)
                                                     - (float)-(float)((float)(*(v65 - 3) * v110) - *v65)))
                     * (float)((float)1.0 / (float)v61);
                v65 = (float *)((char *)v65 + v64);
                *v68 = (float)-(float)((float)(*(v68 - 1) * v112)
                                     - (float)-(float)((float)(*(v68 - 2) * v111)
                                                     - (float)-(float)((float)(*(v68 - 3) * v110) - *v68)))
                     * (float)((float)1.0 / (float)v61);
                v68 = (float *)((char *)v68 + v64);
                *v67 = (float)-(float)((float)(v112 * *(v67 - 1))
                                     - (float)-(float)((float)(*(v67 - 2) * v111)
                                                     - (float)-(float)((float)(*(v67 - 3) * v110) - *v67)))
                     * (float)((float)1.0 / (float)v61);
                v67 = (float *)((char *)v67 + v64);
                *v66 = (float)-(float)((float)(*(v66 - 1) * v112)
                                     - (float)-(float)((float)(*(v66 - 2) * v111)
                                                     - (float)-(float)((float)(*(v66 - 3) * v110) - *v66)))
                     * (float)((float)1.0 / (float)v61);
                v66 = (float *)((char *)v66 + v64);
              }
              while ( v63 < n - 3 );
            }
            if ( v63 < n )
            {
              v69 = 4 * v12;
              v70 = (float *)(4 * (v63 * v12 + 3) + v62);
              v71 = n - v63;
              do
              {
                *v70 = (float)-(float)((float)(v112 * *(v70 - 1))
                                     - (float)-(float)((float)(*(v70 - 2) * v111)
                                                     - (float)-(float)((float)(*(v70 - 3) * v110) - *v70)))
                     * (float)((float)1.0 / (float)v61);
                v70 = (float *)((char *)v70 + v69);
                --v71;
              }
              while ( v71 != 0 );
            }
            __asm { vspltisw128 v127, 0 }
            _R4 = v114;
            __asm { stvx128   v127, r0, r4 }
            blkmov(a1: &v115, a2: v114, a3: (4 * (n - 5)) & 0xFFFFFFF0);
            _R10 = 16;
            v75 = 5;
            _R18 = &vmx_float_tiny;
            _R17 = &vmx_float_one;
            _R16 = vmxi_indexedEndMask[0];
            do
            {
              __asm { lvx128    v63, r0, r19 }
              __asm { vmr128    v62, v127 }
              v79 = v75 - 4;
              _R11 = 4 * (v75 - 1) * *v10 + *v15;
              v81 = 4;
              __asm
              {
                lvx128    v13, r0, r11
                vmulfp128 v61, v95, v13
                lvlx128   v60, r10, r11
                vrlimi128 v62, v60, 8, 0
                vor128    v12, v94, v62
                vor128    v0, v93, v61
                stvx128   v61, r0, r30
                vnmsubfp128 v12, v13, v0, v12
              }
              if ( v75 - 4 > 4 )
              {
                _R9 = v114;
                _R5 = _R11 - (_DWORD)&v110;
                _R4 = 0;
                v81 = 4 * (((unsigned int)(v75 - 9) >> 2) + 2);
                v85 = ((unsigned int)(v75 - 9) >> 2) + 1;
                do
                {
                  __asm
                  {
                    lvx128    v59, r5, r9
                    lvx128    v58, r0, r9
                    vor128    v13, v91, v59
                    vmulfp128 v57, v90, v59
                    vor128    v0, v89, v57
                    stvx128   v57, r4, r9
                  }
                  _R9 += 16;
                  __asm { vnmsubfp  v12, v13, v12, v0 }
                  --v85;
                }
                while ( v85 != 0 );
              }
              _R9 = 4 * v81;
              _R8 = (16 * (v75 - 1)) & 0x30;
              __asm
              {
                lvx128    v56, r9, r11
                lvx128    v63, r8, r16
                vand128   v13, v88, v63
                lvx128    v55, r9, r19
                vmulfp128 v0, v87, v13
                stvx128   v0, r9, r30
                vnmsubfp  v12, v13, v12, v0
                lvx128    v62, r0, r17
                vmsum4fp128 v54, v12, v62
                lvx128    v62, r0, r18
                vcmpeqfp128 v53, v86, v127
                vand128   v52, v85, v62
                vor128    v51, v86, v52
                vrefp128  v50, v51
                stvewx128 v51, r11, r10
                stvewx128 v51, r19, r10
                vaddfp128 v62, v82, v50
                vor128    v0, v82, v50
                vmulfp128 v13, v83, v50
                vnmsubfp128 v62, v13, v0, v62
                stvewx128 v62, r15, r10
              }
              if ( v75 >= n )
                break;
              v88 = v75;
              if ( v75 < n - 3 )
              {
                v89 = v75 + 2;
                do
                {
                  __asm
                  {
                    vmr128    v49, v127
                    vmr128    v48, v127
                    lvx128    v0, r0, r30
                    vmr128    v47, v127
                    vmr128    v46, v127
                    vmr       v11, v0
                    vmr       v13, v0
                    vmr       v12, v0
                  }
                  _R11 = 4 * *v10 * v88 + *v15;
                  _R8 = 4 * (v89 - 1) * *v10 + *v15;
                  _R7 = 4 * *v10 * v89 + *v15;
                  _R6 = 4 * (v89 + 1) * *v10 + *v15;
                  __asm
                  {
                    lvlx128   v45, r10, r11
                    lvlx128   v44, r10, r8
                    vrlimi128 v49, v45, 8, 0
                    vrlimi128 v48, v44, 8, 0
                    lvx128    v9, r0, r11
                    lvx128    v10, r0, r8
                  }
                  v94 = 4;
                  __asm { lvlx128   v43, r10, r7 }
                  __asm
                  {
                    lvlx128   v42, r10, r6
                    vrlimi128 v47, v43, 8, 0
                    vrlimi128 v46, v42, 8, 0
                    vor128    v6, v81, v49
                    vor128    v5, v80, v48
                    vor128    v4, v79, v47
                    vor128    v3, v78, v46
                    vnmsubfp128 v6, v9, v11, v6
                    lvx128    v11, r0, r7
                    vnmsubfp128 v5, v10, v13, v5
                    lvx128    v13, r0, r6
                    vnmsubfp128 v4, v11, v12, v4
                    vnmsubfp128 v3, v13, v0, v3
                  }
                  if ( v79 > 4 )
                  {
                    _R9 = _R11 + 16;
                    _R29 = (char *)&v110 - _R11;
                    _R28 = _R8 - _R11;
                    _R27 = _R7 - _R11;
                    _R26 = _R6 - _R11;
                    v100 = ((unsigned int)(v75 - 9) >> 2) + 1;
                    v94 = 4 * (((unsigned int)(v75 - 9) >> 2) + 2);
                    do
                    {
                      __asm
                      {
                        lvx128    v0, r29, r9
                        vmr       v8, v0
                        lvx128    v7, r0, r9
                        vmr       v10, v0
                        lvx128    v9, r28, r9
                        vmr       v12, v0
                        lvx128    v11, r27, r9
                        lvx128    v13, r26, r9
                      }
                      _R9 += 16;
                      __asm
                      {
                        vnmsubfp  v6, v7, v6, v8
                        vnmsubfp  v5, v9, v5, v10
                        vnmsubfp  v4, v11, v4, v12
                        vnmsubfp  v3, v13, v3, v0
                      }
                      --v100;
                    }
                    while ( v100 != 0 );
                  }
                  _R9 = 4 * v94;
                  v88 += 4;
                  v89 += 4;
                  __asm
                  {
                    lvx128    v41, r9, r30
                    lvx128    v40, r9, r11
                    vor128    v0, v73, v41
                    vand128   v13, v72, v63
                    lvx128    v39, r9, r8
                    lvx128    v38, r9, r7
                    vor128    v10, v73, v41
                    lvx128    v37, r9, r6
                    vand128   v9, v71, v63
                    vor128    v12, v73, v41
                    vnmsubfp  v7, v13, v6, v0
                    vand128   v11, v70, v63
                    vand128   v13, v69, v63
                    vnmsubfp  v8, v9, v5, v10
                    vnmsubfp  v10, v11, v4, v12
                    vnmsubfp  v12, v13, v3, v0
                    vmsum4fp128 v36, v7, v62
                    vmsum4fp128 v35, v8, v62
                    vmsum4fp128 v34, v10, v62
                    vmsum4fp128 v33, v12, v62
                    stvewx128 v36, r11, r10
                    stvewx128 v35, r8, r10
                    stvewx128 v34, r7, r10
                    stvewx128 v33, r6, r10
                  }
                }
                while ( v88 < n - 3 );
              }
              while ( v88 < n )
              {
                __asm { vmr128    v32, v127 }
                __asm { lvx128    v0, r0, r30 }
                v102 = 4;
                _R11 = 4 * *v10 * v88 + *v15;
                __asm
                {
                  lvlx128   v61, r10, r11
                  vrlimi128 v32, v61, 8, 0
                  lvx128    v13, r0, r11
                  vor128    v12, v64, v32
                  vnmsubfp128 v12, v13, v0, v12
                }
                if ( v79 > 4 )
                {
                  _R9 = _R11 + 16;
                  _R6 = (char *)&v110 - _R11;
                  v102 = 4 * (((unsigned int)(v75 - 9) >> 2) + 2);
                  v106 = ((unsigned int)(v75 - 9) >> 2) + 1;
                  do
                  {
                    __asm
                    {
                      lvx128    v0, r6, r9
                      lvx128    v13, r0, r9
                    }
                    _R9 += 16;
                    __asm { vnmsubfp  v12, v13, v12, v0 }
                    --v106;
                  }
                  while ( v106 != 0 );
                }
                _R9 = 4 * v102;
                ++v88;
                __asm
                {
                  lvx128    v60, r9, r11
                  vand128   v13, v92, v63
                  lvx128    v0, r9, r30
                  vnmsubfp  v12, v13, v12, v0
                  vmsum4fp128 v59, v12, v62
                  stvewx128 v59, r11, r10
                }
              }
              ++v75;
              _R10 += 4;
            }
            while ( v75 - 1 < n );
          }
        }
      }
    }
  }
  _R0 = -176;
  __asm { lvx128    v127, r1, r0 }
  return 1;
}


// ========================================================================
// GetMaxStep_SIMD
// EA  : 0x82F32620
// RVA : 0x00F32620
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall GetMaxStep_SIMD(
        const float *f,
        const float *a,
        const float *delta_f,
        const float *delta_a,
        const float *lo,
        const float *hi,
        char *side,
        int numUnbounded,
        double dir,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        int numClamped,
        int d,
        float *maxStep,
        int *limit,
        int *limitSide,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        float a40,
        int a41,
        int a42,
        int a43,
        int numClampeda,
        int a45,
        int da)
{
  unsigned int v61; // r11
  unsigned int v68; // ctr
  unsigned int v75; // r11
  unsigned int v81; // ctr

  _R11 = &a40;
  a40 = dir;
  _R30 = 4 * a38;
  __asm { vspltisw128 v62, 0 }
  _R31 = vmxi_float_absMask;
  a34 = numUnbounded;
  __asm
  {
    lvlx128   v63, r0, r11
    vspltw128 v61, v63, 0
    lvlx128   v60, r30, r6
  }
  _R11 = &vmx_float_LCP_DELTA_ACCEL_EPSILON;
  __asm
  {
    lvx128    v63, r0, r31
    vcmpgefp128 v9, v94, v61
    vspltw128 v11, v60, 0
    vrefp128  v59, v61
  }
  __asm
  {
    lvlx128   v57, r30, r8
    lvlx128   v58, r30, r7
  }
  _R29 = &a34;
  __asm { lvx128    v52, r0, r11 }
  _R11 = &vmx_float_one;
  __asm
  {
    vand128   v56, v11, v63
    vspltw128 v0, v57, 0
    vspltw128 v13, v58, 0
  }
  __asm { lvlx128   v51, r30, r3 }
  _R31 = vmxi_word_not3;
  __asm
  {
    lvlx128   v55, r0, r29
    vcmpgtfp128 v7, v88, v52
    lvx128    v60, r0, r11
    vor128    v12, v92, v60
  }
  __asm
  {
    vspltw128 v54, v55, 0
    vsel      v10, v0, v13, v9
    vaddfp128 v5, v91, v59
    vmulfp128 v13, v93, v59
  }
  __asm
  {
    vsel      v6, v12, v11, v7
    lvx128    v50, r0, r31
  }
  __asm { lvlx128   v53, r30, r4 }
  _R23 = &a38;
  __asm { vmr128    v49, v10 }
  _R31 = vmxi_word_one;
  __asm { vspltw128 v47, v51, 0 }
  _R28 = vmxi_word_index;
  __asm { vor128    v12, v91, v59 }
  _R29 = vmxi_float_signBit;
  __asm { vmr128    v44, v6 }
  _R27 = &vmx_float_LCP_DELTA_FORCE_EPSILON;
  __asm { vand128   v0, v86, v50 }
  _R30 = vmxi_indexedStartMask[0];
  __asm { vspltw128 v48, v53, 0 }
  _R26 = (16 * numUnbounded) & 0x30;
  __asm { vand128   v46, v93, v63 }
  v61 = numUnbounded & 0xFFFFFFFC;
  __asm { lvlx128   v45, r0, r23 }
  __asm
  {
    lvx128    v56, r0, r31
    lvx128    v1, r0, r28
    vor128    v11, v94, v62
    lvx128    v51, r0, r29
    vaddsws   v0, v0, v1
    lvx128    v57, r0, r27
    vor128    v10, v94, v62
    lvx128    v59, r26, r30
    vxor128   v43, v80, v51
    vcmpgtfp128 v42, v78, v57
    vspltw128 v8, v45, 0
  }
  __asm
  {
    vor128    v9, v9, v56
    vsubfp128 v41, v81, v47
  }
  __asm
  {
    vrefp128  v40, v44
    vand128   v39, v81, v63
    vnmsubfp  v6, v13, v5, v12
    vmulfp128 v13, v76, v40
    vor128    v12, v72, v40
    vaddfp128 v5, v72, v40
  }
  _R31 = &vmx_float_infinity;
  __asm { vmulfp128 v38, v73, v6 }
  __asm { lvx128    v53, r0, r30 }
  _R29 = vmxi_word_four;
  __asm
  {
    lvx128    v55, r0, r31
    vcmpeqfp128 v37, v71, v55
    lvx128    v2, r0, r29
    vnmsubfp  v6, v13, v5, v12
    vor128    v12, v70, v38
    vandc128  v36, v74, v37
    vmulfp128 v13, v75, v6
    vsel      v7, v11, v13, v7
    vcmpgefp128 v35, v7, v38
    vmr       v13, v7
    vand128   v11, v68, v35
    vmr128    v61, v11
    vsel      v6, v10, v9, v11
    vsel128   v61, v13, v12, v61
  }
  if ( (int)(numUnbounded & 0xFFFFFFFC) < a36 - 3 )
  {
    _R10 = &lo[v61];
    _R28 = (char *)delta_f - (char *)lo;
    _R27 = (char *)hi - (char *)lo;
    _R26 = (char *)f - (char *)lo;
    v68 = ((a36 - 3 - v61 - 1) >> 2) + 1;
    v61 += 4 * v68;
    do
    {
      __asm
      {
        lvx128    v34, r28, r10
        vor128    v11, v92, v60
        vand128   v10, v66, v59
        lvx128    v12, r0, r10
        lvx128    v13, r27, r10
        vor128    v9, v93, v61
        lvx128    v33, r26, r10
        vmr       v7, v0
      }
      _R10 += 4;
      __asm
      {
        vaddsws   v0, v0, v2
        vand128   v32, v10, v63
        vcmpgefp128 v5, v94, v10
        vor128    v59, v85, v53
        vcmpgtfp128 v4, v64, v57
        vsel      v3, v13, v12, v5
        vor128    v5, v5, v56
        vsel      v13, v11, v10, v4
        vsubfp128 v58, v3, v33
        vand128   v54, v3, v63
        vrefp128  v49, v13
        vcmpeqfp128 v48, v86, v55
        vmulfp128 v13, v13, v49
        vor128    v12, v81, v49
        vaddfp128 v11, v81, v49
        vandc128  v47, v4, v48
        vnmsubfp  v11, v13, v11, v12
        vmulfp128 v12, v90, v11
        vcmpgefp128 v46, v93, v12
        vand128   v13, v79, v46
        vmr128    v61, v13
        vsel128   v61, v9, v12, v61
        vsel      v12, v8, v7, v13
        vsel      v13, v6, v5, v13
        vmr       v8, v12
        vmr       v6, v13
      }
      --v68;
    }
    while ( v68 != 0 );
  }
  __asm { vor128    v11, v92, v60 }
  _R31 = (16 * a36) & 0x30;
  __asm { vor128    v9, v93, v61 }
  _R27 = vmxi_indexedEndMask[0];
  _R10 = 4 * v61;
  _R29 = &a36;
  __asm
  {
    lvx128    v58, r31, r30
    lvx128    v45, r31, r27
  }
  _R31 = &vmx_float_neg_LCP_BOUND_EPSILON;
  __asm
  {
    vand128   v44, v91, v45
    lvx128    v43, r10, r5
    lvx128    v10, r10, r7
  }
  _R5 = &vmx_float_LCP_BOUND_EPSILON;
  __asm { lvx128    v7, r10, r8 }
  v75 = a36 & 0xFFFFFFFC;
  __asm { lvx128    v42, r10, r3 }
  __asm
  {
    vand128   v12, v75, v44
    lvlx128   v41, r0, r29
    lvx128    v54, r0, r31
  }
  __asm
  {
    vspltw128 v40, v41, 0
    lvx128    v59, r0, r5
    vand128   v39, v12, v63
    vcmpgefp128 v5, v94, v12
    vand128   v13, v72, v50
    vcmpgtfp128 v4, v71, v57
    vaddsws   v13, v13, v1
    vsel      v3, v7, v10, v5
    vor128    v10, v5, v56
    vsel      v7, v11, v12, v4
    vsubfp128 v38, v3, v42
    vand128   v37, v3, v63
    vrefp128  v36, v7
    vcmpeqfp128 v35, v69, v55
    vmulfp128 v11, v7, v36
    vor128    v12, v68, v36
    vaddfp128 v7, v68, v36
    vandc128  v34, v4, v35
    vnmsubfp  v7, v11, v7, v12
    vmulfp128 v11, v70, v7
    vcmpgefp128 v33, v93, v11
    vand128   v12, v66, v33
    vmr128    v63, v12
    vsel128   v63, v9, v11, v63
    vsel      v9, v8, v0, v12
    vsel      v11, v6, v10, v12
  }
  if ( (int)(a36 & 0xFFFFFFFC) < a38 - 3 )
  {
    _R10 = (const int *)&side[4 * v75];
    _R31 = (char *)delta_a - side;
    _R30 = (char *)a - side;
    _R29 = (char *)hi - side;
    _R28 = (char *)lo - side;
    v81 = ((a38 - 3 - v75 - 1) >> 2) + 1;
    v75 += 4 * v81;
    do
    {
      __asm
      {
        lvx128    v32, r0, r10
        vor128    v8, v92, v60
        vcsxwfp128 v61, v32, 0
        lvx128    v57, r31, r10
        vand128   v56, v89, v58
        lvx128    v55, r29, r10
        lvx128    v50, r28, r10
        vcmpgtfp128 v49, v87, v59
        vcmpgefp128 v48, v86, v50
        lvx128    v47, r30, r10
        vxor128   v46, v79, v51
      }
      _R10 += 4;
      __asm
      {
        vor128    v0, v88, v56
        vor128    v7, v95, v63
        vmr       v10, v13
        vor128    v12, v94, v62
        vaddsws   v13, v13, v2
        vor128    v58, v85, v53
        vmulfp128 v45, v93, v56
        vor128    v44, v80, v49
        vcmpgtfp128 v6, v77, v52
        vsel      v5, v8, v0, v6
        vand128   v43, v6, v44
        vrefp128  v42, v5
        vmulfp128 v8, v5, v42
        vor128    v0, v74, v42
        vaddfp128 v6, v74, v42
        vnmsubfp  v6, v8, v6, v0
        vmulfp128 v8, v78, v6
        vcmpgefp128 v41, v95, v8
        vand128   v0, v75, v41
        vmr128    v63, v0
        vsel128   v63, v7, v8, v63
        vsel      v8, v9, v10, v0
        vsel      v0, v11, v12, v0
        vmr       v9, v8
        vmr       v11, v0
      }
      --v81;
    }
    while ( v81 != 0 );
  }
  _R11 = 4 * v75;
  __asm { vor128    v10, v95, v63 }
  _R10 = (16 * a38) & 0x30;
  _R5 = a42;
  __asm
  {
    lvx128    v40, r11, r9
    vcsxwfp128 v39, v40, 0
    lvx128    v38, r10, r27
    vand128   v37, v90, v38
    lvx128    v35, r11, r8
    lvx128    v36, r11, r6
    vcmpgtfp128 v33, v67, v59
    lvx128    v34, r11, r7
    vcmpgefp128 v32, v86, v34
    lvx128    v61, r11, r4
    vand128   v59, v68, v37
    vxor128   v58, v93, v51
    vor128    v0, v91, v59
    vmulfp128 v57, v71, v59
    vor128    v56, v64, v33
    vcmpgtfp128 v12, v89, v52
    vmr       v8, v12
    vand128   v55, v12, v56
    vsel128   v8, v92, v0, v8
    vrefp128  v54, v8
    vmulfp128 v12, v8, v54
    vor128    v0, v86, v54
    vaddfp128 v8, v86, v54
    vnmsubfp  v8, v12, v8, v0
    vmulfp128 v12, v90, v8
    vcmpgefp128 v53, v12, v63
    vandc128  v0, v87, v53
    vsel      v8, v10, v12, v0
    vsel      v12, v9, v13, v0
    vsel128   v0, v11, v62, v0
    vpermwi128 v50, v8, 0x4E # 'N'
    vmr128    v52, v12
    vmr128    v51, v0
    vminfp128 v49, v8, v50
    vcmpgefp128 v10, v8, v50
    vpermwi128 v12, v52, 0x4E # 'N'
    vor128    v11, v84, v52
    vpermwi128 v0, v51, 0x4E # 'N'
    vor128    v13, v83, v51
    vpermwi128 v48, v49, 0xB1
    vsel      v9, v11, v12, v10
    vsel      v12, v13, v0, v10
    vcmpgefp128 v10, v81, v48
    vminfp128 v47, v81, v48
    vmr128    v46, v12
    vpermwi128 v12, v9, 0xB1
    vpermwi128 v0, v46, 0xB1
    vor128    v13, v78, v46
    vsel      v9, v9, v12, v10
    vsel      v12, v13, v0, v10
    stvewx128 v47, r0, r5
  }
  _R4 = numClampeda;
  __asm { stvewx    v9, 0, r4 }
  _R3 = da;
  __asm { stvewx    v12, 0, r3 }
}


// ========================================================================
// PrintClocks
// EA  : 0x82F32B10
// RVA : 0x00F32B10
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall PrintClocks(__int64 dataCount, __int64 clocks, __int64 otherClocks, __int64 a4)
{
  const char *v4; // r31
  unsigned int v5; // r27
  int v6; // r30
  int v7; // r28
  __int64 v8; // r10 OVERLAPPED
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  int v12; // r31
  int v13; // r11
  double v14; // fp7
  __int64 v15; // r6
  int v16; // r11
  int v17; // [sp+8h] [-88h]
  int v18; // [sp+8h] [-88h]
  int v19; // [sp+Ch] [-84h]
  int v20; // [sp+Ch] [-84h]
  int v21; // [sp+10h] [-80h]
  int v22; // [sp+10h] [-80h]
  int v23; // [sp+14h] [-7Ch]
  int v24; // [sp+14h] [-7Ch]
  __int64 v25; // [sp+B0h] [+20h]

  v4 = (const char *)HIDWORD(dataCount);
  v25 = *(__int64 *)((char *)&clocks + 4);
  v5 = dataCount;
  v6 = HIDWORD(clocks);
  v7 = clocks;
  idLib::Printf(fmt: dataCount, a2: clocks, a3: otherClocks, a4, a5: v17, a6: v19, a7: v21, a8: v23);
  HIDWORD(v11) = idStr::LengthWithoutColors(s: v4);
  if ( SHIDWORD(v11) < 48 )
  {
    v12 = 48 - HIDWORD(v11);
    do
    {
      HIDWORD(v11) = " ";
      idLib::Printf(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v18, a6: v20, a7: v22, a8: v24);
      --v12;
    }
    while ( v12 != 0 );
  }
  if ( v6 != 0 && v7 != 0 )
  {
    if ( v6 > v7 )
    {
      v16 = v6 - v7;
      LODWORD(v8) = &unk_82150000;
      v14 = (float)((float)((float)*(__int64 *)((char *)&v8 - 4) * (float)-100.0) / (float)v25);
    }
    else
    {
      v13 = v7 - v6;
      LODWORD(v8) = &unk_82150000;
      v14 = (float)((float)((float)*(__int64 *)((char *)&v8 - 4) * (float)100.0) / (float)clocks);
    }
    LODWORD(v15) = (int)v14;
    HIDWORD(v15) = v6;
    idLib::Printf(
      fmt: __SPAIR64__("c = %4d, clcks = %5lld, %d%%\n", v5),
      a2: v15,
      a3: v9,
      a4: v8,
      a5: v18,
      a6: v20,
      a7: v22,
      a8: v24);
  }
  else
  {
    HIDWORD(v10) = v6;
    idLib::Printf(
      fmt: __SPAIR64__("c = %4d, clcks = %5lld\n", v5),
      a2: v10,
      a3: v9,
      a4: v8,
      a5: v18,
      a6: v20,
      a7: v22,
      a8: v24);
  }
}


// ========================================================================
// DotProduct_Test
// EA  : 0x82F32C38
// RVA : 0x00F32C38
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void DotProduct_Test()
{
  int v0; // r2 OVERLAPPED
  __int64 v3; // r26
  int v4; // ctr
  int v5; // r9
  int v6; // r11
  int v7; // r9
  int v8; // r3
  __int64 v9; // r6
  __int64 v10; // r11
  int v11; // r27
  int v14; // r24
  int i; // r30
  double v16; // fp31
  double v17; // fp30
  __int64 v18; // r3
  double v19; // fp0
  int v20; // r10
  int v21; // r11
  double v22; // fp31
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r3
  __int64 v26; // r4
  const char *v27; // r30
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  __int64 v34; // r4
  int v35; // r30
  __int64 v36; // r4
  int v38; // r30
  int v39; // r10
  int v46; // r28
  int v47; // r29
  __int64 v48; // r3
  int v50; // r10
  int v56; // r3
  __int64 v57; // r8
  __int64 v58; // r6
  __int64 v59; // r4
  __int64 v60; // r10
  __int64 v61; // r8
  int v64; // [sp+8h] [-1318h]
  int v65; // [sp+8h] [-1318h]
  int v66; // [sp+8h] [-1318h]
  int v67; // [sp+8h] [-1318h]
  int v68; // [sp+Ch] [-1314h]
  int v69; // [sp+Ch] [-1314h]
  int v70; // [sp+Ch] [-1314h]
  int v71; // [sp+Ch] [-1314h]
  int v72; // [sp+10h] [-1310h]
  int v73; // [sp+10h] [-1310h]
  int v74; // [sp+10h] [-1310h]
  int v75; // [sp+10h] [-1310h]
  int v76; // [sp+14h] [-130Ch]
  int v77; // [sp+14h] [-130Ch]
  int v78; // [sp+14h] [-130Ch]
  int v79; // [sp+14h] [-130Ch]
  int v80; // [sp+18h] [-1308h]
  int v81; // [sp+18h] [-1308h]
  int v82; // [sp+1Ch] [-1304h]
  int v83; // [sp+1Ch] [-1304h]
  idTimer v84; // [sp+50h] [-12D0h] BYREF
  __int64 v85; // [sp+70h] [-12B0h] BYREF
  _QWORD v86[3]; // [sp+78h] [-12A8h] BYREF
  int v87; // [sp+90h] [-1290h] BYREF
  _BYTE v88[200]; // [sp+A0h] [-1280h] BYREF
  float v89; // [sp+168h] [-11B8h]
  _BYTE v90[208]; // [sp+170h] [-11B0h] BYREF
  va v91; // [sp+240h] [-10E0h] BYREF

  _R12 = -224;
  __asm { stvx128   v126, r1, r12 }
  _R12 = -208;
  __asm { stvx128   v127, r1, r12 }
  LODWORD(v3) = 0;
  v4 = 50;
  v5 = 13;
  v6 = 0;
  do
  {
    v7 = 1103515245 * v5 + 12345;
    v8 = (v7 >> 16) & 0x7FFF;
    v5 = 1103515245 * v7 + 12345;
    v86[0] = *(_QWORD *)(&v0 - 1);
    LODWORD(v9) = (v5 >> 16) & 0x7FFF;
    HIDWORD(v9) = v88;
    v85 = v9;
    *(float *)&v90[v6] = (float)((float)((float)*(__int64 *)(&v0 - 1) * (float)0.000061037019) - (float)1.0)
                       * (float)10.0;
    *(float *)&v88[v6] = (float)((float)((float)v9 * (float)0.000061037019) - (float)1.0) * (float)10.0;
    v6 += 4;
    --v4;
  }
  while ( v4 != 0 );
  v84.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  __asm { vspltisw128 v126, 0 }
  HIDWORD(v10) = &unk_82380000;
  v11 = 0;
  _R23 = 0;
  _R22 = &vmx_float_one;
  HIDWORD(v3) = &idTimer::base;
  do
  {
    v14 = -1;
    for ( i = 0; i < 50; ++i )
    {
      v84.clockTicks = v3;
      LODWORD(v10) = i;
      v84.state = TS_STARTED;
      v16 = 0.0;
      v86[1] = v10;
      v89 = (float)v10;
      v17 = 0.0;
      LODWORD(v18) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v84.start = v18;
      v19 = 0.0;
      v20 = 0;
      if ( v11 >= 2 )
      {
        v21 = 0;
        do
        {
          v20 += 2;
          v16 = (float)((float)(*(float *)&v88[v21] * *(float *)&v90[v21]) + (float)v16);
          v17 = (float)((float)(*(float *)&v90[v21 + 4] * *(float *)&v88[v21 + 4]) + (float)v17);
          v21 += 8;
        }
        while ( v20 < v11 - 1 );
      }
      if ( v20 < v11 )
        v19 = (float)(*(float *)&v88[4 * v20] * *(float *)&v90[4 * v20]);
      v22 = (float)((float)((float)v16 + (float)v17) + (float)v19);
      v25 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v10) = v84.start;
      LODWORD(v10) = v25 + LODWORD(v84.clockTicks) - LODWORD(v84.start);
      v84.clockTicks = v10;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v84);
        LODWORD(v10) = v84.clockTicks;
      }
      HIDWORD(v10) = idTimer::base;
      if ( (int)v10 > (int)idTimer::base )
      {
        LODWORD(v10) = v10 - idTimer::base;
        v84.clockTicks = v10;
      }
      v84.state = TS_STOPPED;
      if ( v14 >= (int)v10 )
        v14 = v10;
    }
    HIDWORD(v24) = v11;
    HIDWORD(v26) = va::va(
                     this: &v91,
                     fmt: "DotProduct_Generic %d",
                     a3: v24,
                     a4: v23,
                     a5: idTimer::base,
                     a6: v64,
                     a7: v68,
                     a8: v72,
                     a9: v76,
                     a10: v80,
                     a11: v82);
    v27 = (const char *)HIDWORD(v26);
    idLib::Printf(fmt: v26, a2: v30, a3: v29, a4: v28, a5: v65, a6: v69, a7: v73, a8: v77);
    HIDWORD(v34) = idStr::LengthWithoutColors(s: v27);
    if ( SHIDWORD(v34) < 48 )
    {
      v35 = 48 - HIDWORD(v34);
      do
      {
        HIDWORD(v34) = " ";
        idLib::Printf(fmt: v34, a2: v33, a3: v32, a4: v31, a5: v66, a6: v70, a7: v74, a8: v78);
        --v35;
      }
      while ( v35 != 0 );
    }
    HIDWORD(v36) = "c = %4d, clcks = %5lld\n";
    HIDWORD(v33) = v14;
    LODWORD(v36) = 1;
    idLib::Printf(fmt: v36, a2: v33, a3: v32, a4: v31, a5: v66, a6: v70, a7: v74, a8: v78);
    v38 = v11 - 3;
    __asm { vmr128    v13, v126 }
    v39 = 0;
    if ( v11 - 3 > 0 )
    {
      _R11 = 0;
      _R9 = v90;
      _R8 = v88;
      do
      {
        v39 += 4;
        __asm
        {
          lvx128    v0, r11, r9
          lvx128    v12, r11, r8
        }
        _R11 += 16;
        __asm { vmaddfp   v13, v0, v13, v12 }
      }
      while ( v39 < v38 );
    }
    LODWORD(_R11) = v90;
    __asm { lvx128    v63, r0, r22 }
    HIDWORD(_R11) = v88;
    _R9 = &v87;
    _R8 = v86;
    v46 = -1;
    __asm { lvrx      v0, r23, r11 }
    v47 = 0;
    __asm
    {
      lvrx      v12, r23, r10
      vmr128    v127, v0
      vmaddfp   v13, v0, v13, v12
      stvx128   v0, r0, r9
      vmsum4fp128 v63, v13, v63
      stvewx128 v63, r0, r8
    }
    do
    {
      v84.clockTicks = v3;
      LODWORD(_R11) = v47;
      v84.state = TS_STARTED;
      v86[2] = _R11;
      v89 = (float)_R11;
      LODWORD(v48) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v84.start = v48;
      __asm { vmr128    v0, v126 }
      v50 = 0;
      if ( v38 > 0 )
      {
        _R11 = 0;
        _R9 = v90;
        _R8 = v88;
        do
        {
          v50 += 4;
          __asm
          {
            lvx128    v13, r11, r9
            lvx128    v12, r11, r8
          }
          _R11 += 16;
          __asm { vmaddfp   v0, v13, v0, v12 }
        }
        while ( v50 < v38 );
      }
      _R11 = v88;
      __asm { lvx128    v63, r0, r22 }
      _R10 = &v85;
      __asm
      {
        lvrx      v13, r23, r11
        vmaddfp128 v0, v127, v13, v0
        vmsum4fp128 v62, v0, v63
        stvewx128 v62, r0, r10
      }
      v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      LODWORD(v57) = v84.start;
      HIDWORD(v57) = LODWORD(v84.clockTicks) - LODWORD(v84.start);
      LODWORD(_R11) = v56 + LODWORD(v84.clockTicks) - LODWORD(v84.start);
      v84.clockTicks = _R11;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v84);
        LODWORD(_R11) = v84.clockTicks;
      }
      HIDWORD(_R11) = idTimer::base;
      if ( (int)_R11 > (int)idTimer::base )
      {
        LODWORD(_R11) = _R11 - idTimer::base;
        v84.clockTicks = _R11;
      }
      v84.state = TS_STOPPED;
      if ( v46 >= (int)_R11 )
        v46 = _R11;
      ++v47;
    }
    while ( v47 < 50 );
    LODWORD(v58) = "ok";
    if ( __fabs((float)((float)v22 - *(float *)&v85)) >= 0.000099999997 )
      LODWORD(v58) = "^1X";
    HIDWORD(v58) = v11;
    HIDWORD(v59) = va::va(
                     this: &v91,
                     fmt: "DotProduct_SIMD    %d %s",
                     a3: v58,
                     a4: v57,
                     a5: idTimer::base,
                     a6: v67,
                     a7: v71,
                     a8: v75,
                     a9: v79,
                     a10: v81,
                     a11: v83);
    LODWORD(v59) = 1;
    PrintClocks(dataCount: v59, clocks: __SPAIR64__(v46, v14), otherClocks: v61, a4: v60);
    _R23 += 4;
    ++v11;
  }
  while ( _R23 < 200 );
  _R0 = -224;
  __asm { lvx128    v126, r1, r0 }
  _R0 = -208;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$114430
// EA  : 0x82F3309C
// RVA : 0x00F3309C
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_114430()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 4896 + 80));
}


// ========================================================================
// ?FactorClamped@idLCP_Symmetric@@AAA_NXZ
// EA  : 0x82F330C8
// RVA : 0x00F330C8
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

int __fastcall idLCP_Symmetric::FactorClamped(idLCP_Symmetric *this)
{
  int numClamped; // r11
  int v2; // r29
  int v4; // r30
  idMatX *p_clamped; // r28

  numClamped = this->numClamped;
  v2 = 0;
  v4 = 0;
  this->clampedChangeStart = 0;
  if ( numClamped > 0 )
  {
    p_clamped = &this->clamped;
    do
    {
      memcpy(Dst: &p_clamped->mat[v4 * p_clamped->numColumns], Src: this->rowPtrs[v2], Size: 4 * this->numClamped);
      ++v4;
      ++v2;
    }
    while ( v4 < this->numClamped );
  }
  return LDLT_Factor_SIMD(mat: &this->clamped, invDiag: &this->diagonal, n: this->numClamped);
}


// ========================================================================
// ?CalcForceDelta@idLCP_Symmetric@@AAAXHM@Z
// EA  : 0x82F33148
// RVA : 0x00F33148
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP_Symmetric::CalcForceDelta(idLCP_Symmetric *this, int d, double dir)
{
  int numClamped; // r6
  idMatX *p_clamped; // r30
  int v7; // r10
  int v8; // r11
  float *v9; // r10
  double v10; // fp13

  this->delta_f.p[d] = dir;
  numClamped = this->numClamped;
  if ( numClamped != 0 )
  {
    p_clamped = &this->clamped;
    LowerTriangularSolve_SIMD(
      L: &this->clamped,
      x: this->solveCache1.p,
      b: this->rowPtrs[d],
      n: numClamped,
      skip: this->clampedChangeStart);
    Multiply_SIMD(dst: this->solveCache2.p, src0: this->solveCache1.p, src1: this->diagonal.p, count: this->numClamped);
    LowerTriangularSolveTranspose_SIMD(L: p_clamped, x: this->delta_f.p, b: this->solveCache2.p, n: this->numClamped);
    v7 = this->numClamped;
    this->clampedChangeStart = v7;
    if ( dir > 0.0 )
    {
      v8 = 0;
      if ( v7 > 0 )
      {
        v9 = this->delta_f.p - 1;
        do
        {
          ++v8;
          v10 = -v9[1];
          *++v9 = v10;
        }
        while ( v8 < this->numClamped );
      }
    }
  }
}


// ========================================================================
// ?CalcAccelDelta@idLCP_Symmetric@@AAAXH@Z
// EA  : 0x82F33228
// RVA : 0x00F33228
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP_Symmetric::CalcAccelDelta(idLCP_Symmetric *this, int d)
{
  int numClamped; // r11
  int *p_numClamped; // r27
  int v5; // r9
  float ***p_rowPtrs; // r30
  float **p_p; // r29
  int v8; // r31
  float **v9; // r3
  int v10; // r4
  unsigned int v16; // ctr
  float back_chain; // [sp+0h] [-40h] BYREF

  numClamped = this->numClamped;
  p_numClamped = &this->numClamped;
  if ( numClamped <= d )
  {
    __asm { vspltisw128 v62, 0 }
    v5 = numClamped;
    p_rowPtrs = &this->rowPtrs;
    p_p = &this->delta_f.p;
    v8 = d;
    v9 = &this->delta_a.p;
    v10 = d - numClamped + 1;
    _R28 = &vmx_float_one;
    do
    {
      __asm { vor128    v0, v94, v62 }
      _R10 = *p_p;
      _R11 = (*p_rowPtrs)[v5];
      if ( *p_numClamped - 3 > 0 )
      {
        _R8 = (*p_rowPtrs)[v5];
        _R5 = (char *)_R10 - (char *)_R11;
        v16 = ((unsigned int)(*p_numClamped - 4) >> 2) + 1;
        do
        {
          __asm
          {
            lvx128    v13, r5, r8
            lvx128    v12, r0, r8
          }
          _R8 += 4;
          __asm { vmaddfp   v0, v12, v0, v13 }
          --v16;
        }
        while ( v16 != 0 );
      }
      _R8 = 4 * *p_numClamped;
      __asm { lvx128    v63, r0, r28 }
      _R7 = &back_chain;
      --v10;
      __asm
      {
        lvrx      v13, r8, r10
        lvrx      v12, r8, r11
        vmaddfp   v0, v12, v0, v13
        vmsum4fp128 v63, v0, v63
        stvewx128 v63, r0, r7
      }
      (*v9)[v5++] = (float)(_R11[v8] * _R10[v8]) + back_chain;
    }
    while ( v10 != 0 );
  }
}


// ========================================================================
// LowerTriangularSolve_Test
// EA  : 0x82F33B20
// RVA : 0x00F33B20
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void LowerTriangularSolve_Test()
{
  __int64 v0; // r26
  float *p; // r22
  int i; // r29
  unsigned int v5; // ctr
  int v6; // r21
  int j; // r30
  __int64 v8; // r3
  int v9; // r3
  __int64 v10; // r11
  __int64 v11; // r10
  __int64 v12; // r8
  int size; // r24
  int v16; // ctr
  __int64 v17; // r6
  __int64 v18; // r4
  const char *v19; // r30
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r4
  int v27; // r30
  __int64 v28; // r4
  int v29; // r27
  int k; // r30
  __int64 v31; // r3
  __int64 v32; // r8
  int v33; // r3
  __int64 v34; // r11 OVERLAPPED
  unsigned int v35; // r9 OVERLAPPED
  float *v36; // r28
  char v37; // r11
  __int64 v38; // r6
  __int64 v39; // r4
  __int64 v40; // r10
  __int64 v41; // r8
  float *v42; // r11
  int v43; // [sp+8h] [-1168h]
  int v44; // [sp+8h] [-1168h]
  int v45; // [sp+8h] [-1168h]
  int v46; // [sp+8h] [-1168h]
  int v47; // [sp+Ch] [-1164h]
  int v48; // [sp+Ch] [-1164h]
  int v49; // [sp+Ch] [-1164h]
  int v50; // [sp+Ch] [-1164h]
  int v51; // [sp+10h] [-1160h]
  int v52; // [sp+10h] [-1160h]
  int v53; // [sp+10h] [-1160h]
  int v54; // [sp+10h] [-1160h]
  int v55; // [sp+14h] [-115Ch]
  int v56; // [sp+14h] [-115Ch]
  int v57; // [sp+14h] [-115Ch]
  int v58; // [sp+14h] [-115Ch]
  int v59; // [sp+18h] [-1158h]
  int v60; // [sp+18h] [-1158h]
  int v61; // [sp+1Ch] [-1154h]
  int v62; // [sp+1Ch] [-1154h]
  idVecX v63; // [sp+50h] [-1120h] BYREF
  idTimer v64; // [sp+60h] [-1110h] BYREF
  idMatX v65; // [sp+80h] [-10F0h] BYREF
  idVecX v66; // [sp+90h] [-10E0h] BYREF
  idTimer_vtbl *v67; // [sp+9Ch] [-10D4h]
  const char *v68; // [sp+A0h] [-10D0h]
  idVecX v69; // [sp+A8h] [-10C8h] BYREF
  va v70; // [sp+C0h] [-10B0h] BYREF

  LODWORD(v0) = 0;
  memset(&v65, 0, sizeof(v65));
  memset(&v63, 0, sizeof(v63));
  memset(&v69, 0, sizeof(v69));
  memset(&v66, 0, sizeof(v66));
  idMatX::Random(this: &v65, rows: 52, columns: 52, seed: 0, l: -1.0, u: 1.0);
  idVecX::SetSize(this: &v63, newSize: 52);
  idVecX::Random(this: &v69, length: 52, seed: 0, l: -1.0, u: 1.0);
  v64.clockTicks = v0;
  v64.state = TS_STOPPED;
  v67 = (idTimer_vtbl *)&idTimer::`vftable';
  v64.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  p = v69.p;
  v68 = "ok";
  for ( i = 1; i < 50; ++i )
  {
    idVecX::SetSize(this: &v63, newSize: i);
    HIDWORD(v0) = v63.p;
    if ( i > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      _R11 = v63.p;
      v5 = ((unsigned int)(i - 1) >> 2) + 1;
      do
      {
        __asm { stvx128   v63, r0, r11 }
        _R11 += 4;
        --v5;
      }
      while ( v5 != 0 );
    }
    LowerTriangularSolve_Generic(L: &v65, x: v63.p, b: p, n: i, skip: 0);
    v6 = -1;
    for ( j = 50; j != 0; --j )
    {
      v64.clockTicks = v0;
      v64.state = TS_STARTED;
      LODWORD(v8) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v64.start = v8;
      LowerTriangularSolve_Generic(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i, skip: 0);
      v9 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v10) = v64.start;
      LODWORD(v10) = v9 + LODWORD(v64.clockTicks) - LODWORD(v64.start);
      v64.clockTicks = v10;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v64);
        LODWORD(v10) = v64.clockTicks;
      }
      HIDWORD(v10) = idTimer::base;
      if ( (int)v10 > (int)idTimer::base )
      {
        LODWORD(v10) = v10 - idTimer::base;
        v64.clockTicks = v10;
      }
      v64.state = TS_STOPPED;
      if ( v6 >= (int)v10 )
        v6 = v10;
    }
    idVecX::operator=(this: &v66, a: &v63);
    size = v63.size;
    if ( v63.size > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      _R11 = HIDWORD(v0);
      LODWORD(v11) = ((unsigned int)(v63.size - 1) >> 2) + 1;
      v16 = v11;
      do
      {
        __asm { stvx128   v63, r0, r11 }
        _R11 += 16;
        --v16;
      }
      while ( v16 != 0 );
    }
    LODWORD(v17) = i;
    HIDWORD(v17) = i;
    HIDWORD(v18) = va::va(
                     this: &v70,
                     fmt: "LowerTriangularSolve_Generic %dx%d",
                     a3: v17,
                     a4: v12,
                     a5: v11,
                     a6: v43,
                     a7: v47,
                     a8: v51,
                     a9: v55,
                     a10: v59,
                     a11: v61);
    v19 = (const char *)HIDWORD(v18);
    idLib::Printf(fmt: v18, a2: v22, a3: v21, a4: v20, a5: v44, a6: v48, a7: v52, a8: v56);
    HIDWORD(v26) = idStr::LengthWithoutColors(s: v19);
    if ( SHIDWORD(v26) < 48 )
    {
      v27 = 48 - HIDWORD(v26);
      do
      {
        HIDWORD(v26) = " ";
        idLib::Printf(fmt: v26, a2: v25, a3: v24, a4: v23, a5: v45, a6: v49, a7: v53, a8: v57);
        --v27;
      }
      while ( v27 != 0 );
    }
    HIDWORD(v28) = "c = %4d, clcks = %5lld\n";
    HIDWORD(v25) = v6;
    LODWORD(v28) = 1;
    idLib::Printf(fmt: v28, a2: v25, a3: v24, a4: v23, a5: v45, a6: v49, a7: v53, a8: v57);
    LowerTriangularSolve_SIMD(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i, skip: 0);
    v29 = -1;
    for ( k = 50; k != 0; --k )
    {
      v64.clockTicks = v0;
      v64.state = TS_STARTED;
      LODWORD(v31) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v64.start = v31;
      LowerTriangularSolve_SIMD(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i, skip: 0);
      v33 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v34) = v64.start;
      LODWORD(v34) = v33 + LODWORD(v64.clockTicks) - LODWORD(v64.start);
      v64.clockTicks = v34;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v64);
        LODWORD(v34) = v64.clockTicks;
      }
      *(__int64 *)((char *)&v34 + 4) = idTimer::base;
      if ( (int)v34 > (int)idTimer::base )
      {
        LODWORD(v34) = v34 - idTimer::base;
        v64.clockTicks = v34;
      }
      v64.state = TS_STOPPED;
      if ( v29 >= (int)v34 )
        v29 = v34;
    }
    v36 = v66.p;
    HIDWORD(v34) = 0;
    if ( size <= 0 )
    {
LABEL_31:
      v37 = 1;
    }
    else
    {
      LODWORD(v34) = v66.p;
      v35 = HIDWORD(v0) - (unsigned int)v66.p;
      while ( __fabs((float)(*(float *)(v35 + v34) - *(float *)v34)) <= 0.1 )
      {
        ++HIDWORD(v34);
        LODWORD(v34) = v34 + 4;
        if ( SHIDWORD(v34) >= size )
          goto LABEL_31;
      }
      v37 = 0;
    }
    HIDWORD(v32) = v68;
    if ( v37 == 0 )
      HIDWORD(v32) = "^1X";
    LODWORD(v38) = i;
    HIDWORD(v38) = i;
    HIDWORD(v39) = va::va(
                     this: &v70,
                     fmt: "LowerTriangularSolve_SIMD    %dx%d %s",
                     a3: v38,
                     a4: v32,
                     a5: *(__int64 *)((char *)&v34 + 4),
                     a6: v46,
                     a7: v50,
                     a8: v54,
                     a9: v58,
                     a10: v60,
                     a11: v62);
    LODWORD(v39) = 1;
    PrintClocks(dataCount: v39, clocks: __SPAIR64__(v29, v6), otherClocks: v41, a4: v40);
  }
  v64.__vftable = v67;
  if ( v36 == nullptr )
    goto LABEL_40;
  v42 = idVecX::tempPtr;
  if ( (v36 < idVecX::tempPtr || v36 >= idVecX::tempPtr + 1024) && v66.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
LABEL_40:
    v42 = idVecX::tempPtr;
  }
  if ( p != nullptr && (p < v42 || p >= v42 + 1024) && v69.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
    v42 = idVecX::tempPtr;
  }
  if ( HIDWORD(v0) != 0
    && (HIDWORD(v0) < (unsigned int)v42 || HIDWORD(v0) >= (unsigned int)(v42 + 1024))
    && v63.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: (void *)HIDWORD(v0), align: ALIGN_16);
  }
  if ( v65.mat != nullptr && v65.alloced != -1 )
    idMem::Free(this: &mem, ptr: v65.mat, align: ALIGN_16);
}


// ========================================================================
// $M115800
// EA  : 0x82F33FE4
// RVA : 0x00F33FE4
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _M115800()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4464 + 128));
}


// ========================================================================
// __unwind$115574
// EA  : 0x82F3400C
// RVA : 0x00F3400C
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115574()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 80));
}


// ========================================================================
// __unwind$115575
// EA  : 0x82F34034
// RVA : 0x00F34034
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115575()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 168));
}


// ========================================================================
// __unwind$115576
// EA  : 0x82F3405C
// RVA : 0x00F3405C
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115576()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 144));
}


// ========================================================================
// __unwind$115577
// EA  : 0x82F34084
// RVA : 0x00F34084
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115577()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 4464 + 96));
}


// ========================================================================
// LowerTriangularSolveTranspose_Test
// EA  : 0x82F340B8
// RVA : 0x00F340B8
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void LowerTriangularSolveTranspose_Test()
{
  __int64 v0; // r26
  float *p; // r22
  int i; // r29
  unsigned int v5; // ctr
  int v6; // r21
  int j; // r30
  __int64 v8; // r3
  int v9; // r3
  __int64 v10; // r11
  __int64 v11; // r10
  __int64 v12; // r8
  int size; // r24
  int v16; // ctr
  __int64 v17; // r6
  __int64 v18; // r4
  const char *v19; // r30
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r4
  int v27; // r30
  __int64 v28; // r4
  int v29; // r27
  int k; // r30
  __int64 v31; // r3
  __int64 v32; // r8
  int v33; // r3
  __int64 v34; // r11 OVERLAPPED
  unsigned int v35; // r9 OVERLAPPED
  float *v36; // r28
  char v37; // r11
  __int64 v38; // r6
  __int64 v39; // r4
  __int64 v40; // r10
  __int64 v41; // r8
  float *v42; // r11
  int v43; // [sp+8h] [-1168h]
  int v44; // [sp+8h] [-1168h]
  int v45; // [sp+8h] [-1168h]
  int v46; // [sp+8h] [-1168h]
  int v47; // [sp+Ch] [-1164h]
  int v48; // [sp+Ch] [-1164h]
  int v49; // [sp+Ch] [-1164h]
  int v50; // [sp+Ch] [-1164h]
  int v51; // [sp+10h] [-1160h]
  int v52; // [sp+10h] [-1160h]
  int v53; // [sp+10h] [-1160h]
  int v54; // [sp+10h] [-1160h]
  int v55; // [sp+14h] [-115Ch]
  int v56; // [sp+14h] [-115Ch]
  int v57; // [sp+14h] [-115Ch]
  int v58; // [sp+14h] [-115Ch]
  int v59; // [sp+18h] [-1158h]
  int v60; // [sp+18h] [-1158h]
  int v61; // [sp+1Ch] [-1154h]
  int v62; // [sp+1Ch] [-1154h]
  idVecX v63; // [sp+50h] [-1120h] BYREF
  idTimer v64; // [sp+60h] [-1110h] BYREF
  idMatX v65; // [sp+80h] [-10F0h] BYREF
  idVecX v66; // [sp+90h] [-10E0h] BYREF
  idTimer_vtbl *v67; // [sp+9Ch] [-10D4h]
  const char *v68; // [sp+A0h] [-10D0h]
  idVecX v69; // [sp+A8h] [-10C8h] BYREF
  va v70; // [sp+C0h] [-10B0h] BYREF

  LODWORD(v0) = 0;
  memset(&v65, 0, sizeof(v65));
  memset(&v63, 0, sizeof(v63));
  memset(&v69, 0, sizeof(v69));
  memset(&v66, 0, sizeof(v66));
  idMatX::Random(this: &v65, rows: 52, columns: 52, seed: 0, l: -1.0, u: 1.0);
  idVecX::SetSize(this: &v63, newSize: 52);
  idVecX::Random(this: &v69, length: 52, seed: 0, l: -1.0, u: 1.0);
  v64.clockTicks = v0;
  v64.state = TS_STOPPED;
  v67 = (idTimer_vtbl *)&idTimer::`vftable';
  v64.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  p = v69.p;
  v68 = "ok";
  for ( i = 1; i < 50; ++i )
  {
    idVecX::SetSize(this: &v63, newSize: i);
    HIDWORD(v0) = v63.p;
    if ( i > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      _R11 = v63.p;
      v5 = ((unsigned int)(i - 1) >> 2) + 1;
      do
      {
        __asm { stvx128   v63, r0, r11 }
        _R11 += 4;
        --v5;
      }
      while ( v5 != 0 );
    }
    LowerTriangularSolveTranspose_Generic(L: &v65, x: v63.p, b: p, n: i);
    v6 = -1;
    for ( j = 50; j != 0; --j )
    {
      v64.clockTicks = v0;
      v64.state = TS_STARTED;
      LODWORD(v8) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v64.start = v8;
      LowerTriangularSolveTranspose_Generic(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i);
      v9 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v10) = v64.start;
      LODWORD(v10) = v9 + LODWORD(v64.clockTicks) - LODWORD(v64.start);
      v64.clockTicks = v10;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v64);
        LODWORD(v10) = v64.clockTicks;
      }
      HIDWORD(v10) = idTimer::base;
      if ( (int)v10 > (int)idTimer::base )
      {
        LODWORD(v10) = v10 - idTimer::base;
        v64.clockTicks = v10;
      }
      v64.state = TS_STOPPED;
      if ( v6 >= (int)v10 )
        v6 = v10;
    }
    idVecX::operator=(this: &v66, a: &v63);
    size = v63.size;
    if ( v63.size > 0 )
    {
      __asm { vspltisw128 v63, 0 }
      _R11 = HIDWORD(v0);
      LODWORD(v11) = ((unsigned int)(v63.size - 1) >> 2) + 1;
      v16 = v11;
      do
      {
        __asm { stvx128   v63, r0, r11 }
        _R11 += 16;
        --v16;
      }
      while ( v16 != 0 );
    }
    LODWORD(v17) = i;
    HIDWORD(v17) = i;
    HIDWORD(v18) = va::va(
                     this: &v70,
                     fmt: "LowerTriangularSolveTranspose_Generic %dx%d",
                     a3: v17,
                     a4: v12,
                     a5: v11,
                     a6: v43,
                     a7: v47,
                     a8: v51,
                     a9: v55,
                     a10: v59,
                     a11: v61);
    v19 = (const char *)HIDWORD(v18);
    idLib::Printf(fmt: v18, a2: v22, a3: v21, a4: v20, a5: v44, a6: v48, a7: v52, a8: v56);
    HIDWORD(v26) = idStr::LengthWithoutColors(s: v19);
    if ( SHIDWORD(v26) < 48 )
    {
      v27 = 48 - HIDWORD(v26);
      do
      {
        HIDWORD(v26) = " ";
        idLib::Printf(fmt: v26, a2: v25, a3: v24, a4: v23, a5: v45, a6: v49, a7: v53, a8: v57);
        --v27;
      }
      while ( v27 != 0 );
    }
    HIDWORD(v28) = "c = %4d, clcks = %5lld\n";
    HIDWORD(v25) = v6;
    LODWORD(v28) = 1;
    idLib::Printf(fmt: v28, a2: v25, a3: v24, a4: v23, a5: v45, a6: v49, a7: v53, a8: v57);
    LowerTriangularSolveTranspose_SIMD(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i);
    v29 = -1;
    for ( k = 50; k != 0; --k )
    {
      v64.clockTicks = v0;
      v64.state = TS_STARTED;
      LODWORD(v31) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v64.start = v31;
      LowerTriangularSolveTranspose_SIMD(L: &v65, x: (float *)HIDWORD(v0), b: p, n: i);
      v33 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v34) = v64.start;
      LODWORD(v34) = v33 + LODWORD(v64.clockTicks) - LODWORD(v64.start);
      v64.clockTicks = v34;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v64);
        LODWORD(v34) = v64.clockTicks;
      }
      *(__int64 *)((char *)&v34 + 4) = idTimer::base;
      if ( (int)v34 > (int)idTimer::base )
      {
        LODWORD(v34) = v34 - idTimer::base;
        v64.clockTicks = v34;
      }
      v64.state = TS_STOPPED;
      if ( v29 >= (int)v34 )
        v29 = v34;
    }
    v36 = v66.p;
    HIDWORD(v34) = 0;
    if ( size <= 0 )
    {
LABEL_31:
      v37 = 1;
    }
    else
    {
      LODWORD(v34) = v66.p;
      v35 = HIDWORD(v0) - (unsigned int)v66.p;
      while ( __fabs((float)(*(float *)(v35 + v34) - *(float *)v34)) <= 0.1 )
      {
        ++HIDWORD(v34);
        LODWORD(v34) = v34 + 4;
        if ( SHIDWORD(v34) >= size )
          goto LABEL_31;
      }
      v37 = 0;
    }
    HIDWORD(v32) = v68;
    if ( v37 == 0 )
      HIDWORD(v32) = "^1X";
    LODWORD(v38) = i;
    HIDWORD(v38) = i;
    HIDWORD(v39) = va::va(
                     this: &v70,
                     fmt: "LowerTriangularSolveTranspose_SIMD    %dx%d %s",
                     a3: v38,
                     a4: v32,
                     a5: *(__int64 *)((char *)&v34 + 4),
                     a6: v46,
                     a7: v50,
                     a8: v54,
                     a9: v58,
                     a10: v60,
                     a11: v62);
    LODWORD(v39) = 1;
    PrintClocks(dataCount: v39, clocks: __SPAIR64__(v29, v6), otherClocks: v41, a4: v40);
  }
  v64.__vftable = v67;
  if ( v36 == nullptr )
    goto LABEL_40;
  v42 = idVecX::tempPtr;
  if ( (v36 < idVecX::tempPtr || v36 >= idVecX::tempPtr + 1024) && v66.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
LABEL_40:
    v42 = idVecX::tempPtr;
  }
  if ( p != nullptr && (p < v42 || p >= v42 + 1024) && v69.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
    v42 = idVecX::tempPtr;
  }
  if ( HIDWORD(v0) != 0
    && (HIDWORD(v0) < (unsigned int)v42 || HIDWORD(v0) >= (unsigned int)(v42 + 1024))
    && v63.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: (void *)HIDWORD(v0), align: ALIGN_16);
  }
  if ( v65.mat != nullptr && v65.alloced != -1 )
    idMem::Free(this: &mem, ptr: v65.mat, align: ALIGN_16);
}


// ========================================================================
// $M116056
// EA  : 0x82F3456C
// RVA : 0x00F3456C
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _M116056()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4464 + 128));
}


// ========================================================================
// __unwind$115834
// EA  : 0x82F34594
// RVA : 0x00F34594
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115834()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 80));
}


// ========================================================================
// __unwind$115835
// EA  : 0x82F345BC
// RVA : 0x00F345BC
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115835()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 168));
}


// ========================================================================
// __unwind$115836
// EA  : 0x82F345E4
// RVA : 0x00F345E4
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115836()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4464 + 144));
}


// ========================================================================
// __unwind$115837
// EA  : 0x82F3460C
// RVA : 0x00F3460C
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_115837()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 4464 + 96));
}


// ========================================================================
// LDLT_Factor_Test
// EA  : 0x82F34640
// RVA : 0x00F34640
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void LDLT_Factor_Test()
{
  __int64 v0; // r29
  int v2; // r24
  int v3; // r22
  int i; // r30
  int v6; // ctr
  float *p; // r21
  __int64 v9; // r3
  __int64 v10; // r8
  int v11; // r3
  __int64 v12; // r11
  __int64 v13; // r6
  __int64 v14; // r4
  const char *v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r4
  int v23; // r30
  __int64 v24; // r4
  int v25; // r26
  int j; // r30
  int v28; // ctr
  float *v29; // r25
  __int64 v31; // r3
  __int64 v32; // r8
  int v33; // r3
  __int64 v34; // r11
  float *mat; // r27
  __int64 v36; // r10
  float *v37; // r11
  char v38; // r11
  float *v39; // r11
  char v40; // r11
  __int64 v41; // r6
  __int64 v42; // r4
  __int64 v43; // r10
  __int64 v44; // r8
  float *v45; // r11
  int v47; // [sp+8h] [-1198h]
  int v48; // [sp+8h] [-1198h]
  int v49; // [sp+8h] [-1198h]
  int v50; // [sp+8h] [-1198h]
  int v51; // [sp+Ch] [-1194h]
  int v52; // [sp+Ch] [-1194h]
  int v53; // [sp+Ch] [-1194h]
  int v54; // [sp+Ch] [-1194h]
  int v55; // [sp+10h] [-1190h]
  int v56; // [sp+10h] [-1190h]
  int v57; // [sp+10h] [-1190h]
  int v58; // [sp+10h] [-1190h]
  int v59; // [sp+14h] [-118Ch]
  int v60; // [sp+14h] [-118Ch]
  int v61; // [sp+14h] [-118Ch]
  int v62; // [sp+14h] [-118Ch]
  int v63; // [sp+18h] [-1188h]
  int v64; // [sp+18h] [-1188h]
  int v65; // [sp+1Ch] [-1184h]
  int v66; // [sp+1Ch] [-1184h]
  idTimer v67; // [sp+50h] [-1150h] BYREF
  idVecX v68; // [sp+70h] [-1130h] BYREF
  idMatX v69; // [sp+80h] [-1120h] BYREF
  idMatX v70; // [sp+90h] [-1110h] BYREF
  idVecX v71; // [sp+A0h] [-1100h] BYREF
  idMatX v72; // [sp+B0h] [-10F0h] BYREF
  idMatX v73; // [sp+C0h] [-10E0h] BYREF
  idTimer_vtbl *v74; // [sp+D0h] [-10D0h]
  const char *v75; // [sp+D4h] [-10CCh]
  va v76; // [sp+E0h] [-10C0h] BYREF

  _R12 = -192;
  __asm { stvx128   v127, r1, r12 }
  LODWORD(v0) = 0;
  memset(&v72, 0, sizeof(v72));
  memset(&v70, 0, sizeof(v70));
  memset(&v69, 0, sizeof(v69));
  memset(&v73, 0, sizeof(v73));
  memset(&v68, 0, sizeof(v68));
  memset(&v71, 0, sizeof(v71));
  idMatX::SetSize(this: &v70, rows: 52, columns: 52);
  idMatX::Random(this: &v72, rows: 52, columns: 52, seed: 0, l: -1.0, u: 1.0);
  idMatX::TransposeMultiply(this: &v72, dst: &v70, a: &v72);
  v67.clockTicks = v0;
  v67.state = TS_STOPPED;
  v74 = (idTimer_vtbl *)&idTimer::`vftable';
  v67.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  __asm { vspltisw128 v127, 0 }
  v2 = 1;
  v75 = "ok";
  do
  {
    v3 = -1;
    for ( i = 50; i != 0; --i )
    {
      idMatX::operator=(this: &v69, a: &v70);
      idVecX::SetSize(this: &v68, newSize: 50);
      v6 = 13;
      p = v68.p;
      _R11 = v68.p;
      do
      {
        __asm { stvx128   v127, r0, r11 }
        _R11 += 4;
        --v6;
      }
      while ( v6 != 0 );
      v67.clockTicks = v0;
      v67.state = TS_STARTED;
      LODWORD(v9) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v67.start = v9;
      LDLT_Factor_Generic(mat: &v69, invDiag: &v68, n: v2);
      v11 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v12) = v67.start;
      LODWORD(v12) = v11 + LODWORD(v67.clockTicks) - LODWORD(v67.start);
      v67.clockTicks = v12;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v67);
        LODWORD(v12) = v67.clockTicks;
      }
      HIDWORD(v12) = idTimer::base;
      if ( (int)v12 > (int)idTimer::base )
      {
        LODWORD(v12) = v12 - idTimer::base;
        v67.clockTicks = v12;
      }
      v67.state = TS_STOPPED;
      if ( v3 >= (int)v12 )
        v3 = v12;
    }
    LODWORD(v13) = v2;
    HIDWORD(v13) = v2;
    HIDWORD(v14) = va::va(
                     this: &v76,
                     fmt: "LDLT_Factor_Generic %dx%d",
                     a3: v13,
                     a4: v10,
                     a5: idTimer::base,
                     a6: v47,
                     a7: v51,
                     a8: v55,
                     a9: v59,
                     a10: v63,
                     a11: v65);
    v15 = (const char *)HIDWORD(v14);
    idLib::Printf(fmt: v14, a2: v18, a3: v17, a4: v16, a5: v48, a6: v52, a7: v56, a8: v60);
    HIDWORD(v22) = idStr::LengthWithoutColors(s: v15);
    if ( SHIDWORD(v22) < 48 )
    {
      v23 = 48 - HIDWORD(v22);
      do
      {
        HIDWORD(v22) = " ";
        idLib::Printf(fmt: v22, a2: v21, a3: v20, a4: v19, a5: v49, a6: v53, a7: v57, a8: v61);
        --v23;
      }
      while ( v23 != 0 );
    }
    HIDWORD(v24) = "c = %4d, clcks = %5lld\n";
    HIDWORD(v21) = v3;
    LODWORD(v24) = 1;
    idLib::Printf(fmt: v24, a2: v21, a3: v20, a4: v19, a5: v49, a6: v53, a7: v57, a8: v61);
    v25 = -1;
    for ( j = 50; j != 0; --j )
    {
      idMatX::operator=(this: &v73, a: &v70);
      idVecX::SetSize(this: &v71, newSize: 50);
      v28 = 13;
      v29 = v71.p;
      _R11 = v71.p;
      do
      {
        __asm { stvx128   v127, r0, r11 }
        _R11 += 4;
        --v28;
      }
      while ( v28 != 0 );
      v67.clockTicks = v0;
      v67.state = TS_STARTED;
      LODWORD(v31) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v67.start = v31;
      LDLT_Factor_SIMD(mat: &v73, invDiag: &v71, n: v2);
      v33 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      HIDWORD(v34) = v67.start;
      LODWORD(v34) = v33 + LODWORD(v67.clockTicks) - LODWORD(v67.start);
      v67.clockTicks = v34;
      if ( (float)idTimer::base < 0.0 )
      {
        idTimer::InitBaseClockTicks(this: &v67);
        LODWORD(v34) = v67.clockTicks;
      }
      HIDWORD(v34) = idTimer::base;
      if ( (int)v34 > (int)idTimer::base )
      {
        LODWORD(v34) = v34 - idTimer::base;
        v67.clockTicks = v34;
      }
      v67.state = TS_STOPPED;
      if ( v25 >= (int)v34 )
        v25 = v34;
    }
    LODWORD(v36) = 0;
    mat = v69.mat;
    HIDWORD(v0) = v73.mat;
    HIDWORD(v36) = v69.numColumns * v69.numRows;
    if ( v69.numColumns * v69.numRows <= 0 )
    {
LABEL_29:
      v38 = 1;
    }
    else
    {
      v37 = v73.mat;
      LODWORD(v32) = (char *)v69.mat - (char *)v73.mat;
      while ( __fabs((float)(*(float *)((char *)v37 + v32) - *v37)) <= 0.1 )
      {
        LODWORD(v36) = v36 + 1;
        ++v37;
        if ( (int)v36 >= SHIDWORD(v36) )
          goto LABEL_29;
      }
      v38 = 0;
    }
    if ( v38 == 0 )
      goto LABEL_37;
    LODWORD(v32) = v68.size;
    LODWORD(v36) = 0;
    if ( v68.size <= 0 )
    {
LABEL_35:
      v40 = 1;
    }
    else
    {
      v39 = v29;
      HIDWORD(v36) = (char *)p - (char *)v29;
      while ( __fabs((float)(*(float *)((char *)v39 + HIDWORD(v36)) - *v39)) <= 0.1 )
      {
        LODWORD(v36) = v36 + 1;
        ++v39;
        if ( (int)v36 >= v68.size )
          goto LABEL_35;
      }
      v40 = 0;
    }
    HIDWORD(v32) = v75;
    if ( v40 == 0 )
LABEL_37:
      HIDWORD(v32) = "^1X";
    LODWORD(v41) = v2;
    HIDWORD(v41) = v2;
    HIDWORD(v42) = va::va(
                     this: &v76,
                     fmt: "LDLT_Factor_SIMD    %dx%d %s",
                     a3: v41,
                     a4: v32,
                     a5: v36,
                     a6: v50,
                     a7: v54,
                     a8: v58,
                     a9: v62,
                     a10: v64,
                     a11: v66);
    LODWORD(v42) = 1;
    PrintClocks(dataCount: v42, clocks: __SPAIR64__(v25, v3), otherClocks: v44, a4: v43);
    ++v2;
  }
  while ( v2 < 50 );
  v67.__vftable = v74;
  if ( v29 == nullptr )
    goto LABEL_44;
  v45 = idVecX::tempPtr;
  if ( (v29 < idVecX::tempPtr || v29 >= idVecX::tempPtr + 1024) && v71.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
LABEL_44:
    v45 = idVecX::tempPtr;
  }
  if ( p != nullptr && (p < v45 || p >= v45 + 1024) && v68.alloced != -1 )
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
  if ( HIDWORD(v0) != 0 && v73.alloced != -1 )
    idMem::Free(this: &mem, ptr: (void *)HIDWORD(v0), align: ALIGN_16);
  if ( mat != nullptr && v69.alloced != -1 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
  if ( v70.mat != nullptr && v70.alloced != -1 )
    idMem::Free(this: &mem, ptr: v70.mat, align: ALIGN_16);
  if ( v72.mat != nullptr && v72.alloced != -1 )
    idMem::Free(this: &mem, ptr: v72.mat, align: ALIGN_16);
  _R0 = -192;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$116089
// EA  : 0x82F34B70
// RVA : 0x00F34B70
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116089()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4512 + 176));
}


// ========================================================================
// __unwind$116090
// EA  : 0x82F34B98
// RVA : 0x00F34B98
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116090()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4512 + 144));
}


// ========================================================================
// __unwind$116091_0
// EA  : 0x82F34BC0
// RVA : 0x00F34BC0
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116091_0()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4512 + 128));
}


// ========================================================================
// __unwind$116092_0
// EA  : 0x82F34BE8
// RVA : 0x00F34BE8
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116092_0()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 4512 + 192));
}


// ========================================================================
// __unwind$116093_0
// EA  : 0x82F34C10
// RVA : 0x00F34C10
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116093_0()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4512 + 112));
}


// ========================================================================
// __unwind$116094
// EA  : 0x82F34C38
// RVA : 0x00F34C38
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116094()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 4512 + 160));
}


// ========================================================================
// __unwind$116095
// EA  : 0x82F34C60
// RVA : 0x00F34C60
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_116095()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 4512 + 80));
}


// ========================================================================
// ?Swap@idLCP_Symmetric@@AAAXHH@Z
// EA  : 0x82F34C88
// RVA : 0x00F34C88
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP_Symmetric::Swap(idLCP_Symmetric *this, int i, int j)
{
  float **rowPtrs; // r9
  int v4; // r11
  int v5; // r10
  int v6; // r7
  float *v7; // r6
  float *v8; // r5
  float *k; // r9
  double v10; // fp0
  float *p; // r9
  float *v12; // r8
  float *v13; // r7
  float *v14; // r6
  float *v15; // r5
  double v16; // fp0
  double v17; // fp12
  double v18; // fp10
  double v19; // fp8
  double v20; // fp6
  int *boxIndex; // r4
  int v22; // r7
  float *boxScale; // r6
  double v24; // fp0
  int *side; // r9
  int v26; // r7
  int *permuted; // r6
  int v28; // r4

  if ( i != j )
  {
    rowPtrs = this->rowPtrs;
    v4 = j;
    v5 = i;
    v6 = 0;
    v7 = rowPtrs[j];
    v8 = rowPtrs[i];
    rowPtrs[i] = v7;
    rowPtrs[v4] = v8;
    for ( k = this->m.mat; v6 < this->m.numRows; k += this->m.numColumns )
    {
      v10 = k[v5];
      ++v6;
      k[v5] = k[v4];
      k[v4] = v10;
    }
    p = this->b.p;
    v12 = this->lo.p;
    v13 = this->hi.p;
    v14 = this->a.p;
    v15 = this->f.p;
    v16 = p[i];
    p[i] = p[v4];
    p[v4] = v16;
    v17 = v12[i];
    v12[i] = v12[v4];
    v12[v4] = v17;
    v18 = v13[i];
    v13[i] = v13[v4];
    v13[v4] = v18;
    v19 = v14[i];
    v14[i] = v14[v4];
    v14[v4] = v19;
    v20 = v15[i];
    v15[i] = v15[v4];
    v15[v4] = v20;
    boxIndex = this->boxIndex;
    if ( boxIndex != nullptr && this->boxScale != nullptr )
    {
      v22 = boxIndex[v5];
      boxIndex[v5] = boxIndex[v4];
      boxIndex[v4] = v22;
      boxScale = this->boxScale;
      v24 = boxScale[v5];
      boxScale[v5] = boxScale[v4];
      boxScale[v4] = v24;
    }
    side = this->side;
    v26 = side[v5];
    side[v5] = side[v4];
    side[v4] = v26;
    permuted = this->permuted;
    v28 = permuted[v5];
    permuted[v5] = permuted[v4];
    permuted[v4] = v28;
  }
}


// ========================================================================
// ?AddClamped@idLCP_Symmetric@@AAAXH_N@Z
// EA  : 0x82F34DC0
// RVA : 0x00F34DC0
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP_Symmetric::AddClamped(idLCP_Symmetric *this, int r, bool useSolveCache)
{
  int numClamped; // r11
  int *p_numColumns; // r29
  float **p_mat; // r28
  int v8; // r5
  float *p; // r4
  float *v10; // r3
  float **rowPtrs; // r4
  int v12; // r12
  int v13; // r10
  int v14; // r6
  const float *v15; // r4
  __int64 v16; // r6
  __int64 v17; // r4
  double v18; // fp1
  __int64 v19; // r10
  __int64 v20; // r8
  double v21; // fp0
  int back_chain[20]; // [sp+0h] [-80h]
  float v23; // [sp+50h] [-30h] BYREF

  numClamped = this->numClamped;
  if ( numClamped < this->clampedChangeStart )
    this->clampedChangeStart = numClamped;
  idLCP_Symmetric::Swap(this, i: numClamped, j: r);
  if ( useSolveCache )
  {
    p_numColumns = &this->clamped.numColumns;
    p_mat = &this->clamped.mat;
    memcpy(
      Dst: &this->clamped.mat[this->numClamped * this->clamped.numColumns],
      Src: this->solveCache2.p,
      Size: 4 * this->numClamped);
    v8 = this->numClamped;
    p = this->solveCache1.p;
    v10 = this->solveCache2.p;
  }
  else
  {
    ((void (*)(void))RtlCheckStack12)();
    rowPtrs = this->rowPtrs;
    *(int *)((char *)back_chain + v12) = back_chain[0];
    LowerTriangularSolve_SIMD(L: &this->clamped, x: &v23, b: *(float **)((char *)rowPtrs + v13), n: v14, skip: 0);
    p_numColumns = &this->clamped.numColumns;
    p_mat = &this->clamped.mat;
    Multiply_SIMD(
      dst: &this->clamped.mat[this->numClamped * this->clamped.numColumns],
      src0: v15,
      src1: this->diagonal.p,
      count: this->numClamped);
    v8 = this->numClamped;
    v10 = &this->clamped.mat[v8 * this->clamped.numColumns];
  }
  v18 = DotProduct_SIMD(src0: v10, src1: p, count: v8);
  LODWORD(v19) = this->rowPtrs;
  HIDWORD(v19) = 4 * this->numClamped;
  LODWORD(v20) = *(_DWORD *)(v19 + HIDWORD(v19));
  v21 = (float)(*(float *)(v20 + HIDWORD(v19)) - (float)v18);
  if ( __fabs(v21) < idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    HIDWORD(v17) = "idLCP_Symmetric::AddClamped: updating factorization failed\n";
    idLib::Printf(
      fmt: v17,
      a2: v16,
      a3: v20,
      a4: v19,
      a5: back_chain[2],
      a6: back_chain[3],
      a7: back_chain[4],
      a8: back_chain[5]);
    v21 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  (*p_mat)[(*p_numColumns + 1) * this->numClamped] = v21;
  this->diagonal.p[this->numClamped++] = (float)1.0 / (float)v21;
}


// ========================================================================
// ?RemoveClamped@idLCP_Symmetric@@AAAXH@Z
// EA  : 0x82F34F68
// RVA : 0x00F34F68
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP_Symmetric::RemoveClamped(idLCP_Symmetric *this, unsigned int r)
{
  unsigned int numClamped; // r11
  int v4; // r29
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r4
  int v8; // r12
  float **rowPtrs; // r11
  double v10; // fp0
  int v11; // r9
  int v12; // r10
  float *v13; // r7
  float *v14; // r11
  char *v15; // r8
  char *v16; // r9
  float **v17; // r9
  int v18; // r26
  int v19; // r12
  const float *v20; // r4
  __int64 v21; // r10
  __int64 v22; // r6
  __int64 v23; // r4
  double v24; // fp1
  __int64 v25; // r8
  double v26; // fp0
  int v27; // r11
  float *v28; // r10
  int numColumns; // r9
  int v30; // r8
  float *v31; // r9
  int v32; // ctr
  int v33; // r10
  int v34; // r10
  int v35; // r5
  int v36; // r11
  float *mat; // r9
  double v38; // fp11
  double v39; // fp13
  double v40; // fp0
  int v41; // r10
  float *v42; // r6
  float *v43; // r9
  float *v44; // r11
  int v45; // r3
  int v46; // r12
  int v47; // r7
  __int64 v48; // r4
  int v49; // r8
  double v50; // fp0
  int v51; // r9
  int v52; // r12
  __int64 v53; // r6
  float *v54; // r10
  double v55; // fp12
  int v56; // r24
  double v57; // fp27
  double v58; // fp26
  int v59; // r25
  int v60; // r22
  float *v61; // r26
  int v62; // r21
  int v63; // r20
  int v64; // r30
  double v65; // fp30
  __int64 v66; // r10
  double v67; // fp13
  __int64 v68; // r8
  double v69; // fp29
  double v70; // fp0
  double v71; // fp31
  double v72; // fp12
  double v73; // fp28
  double v74; // fp0
  double v75; // fp29
  double v76; // fp13
  int v77; // r10
  double v78; // fp12
  double v79; // fp0
  float *v80; // r7
  float *v81; // r9
  float *v82; // r11
  float *v83; // r8
  double v84; // fp13
  double v85; // fp12
  double v86; // fp9
  double v87; // fp8
  double v88; // fp3
  double v89; // fp2
  float *v90; // r11
  float *v91; // r9
  double v92; // fp13
  double v93; // fp11
  double v94; // fp8
  _DWORD back_chain[2]; // [sp+0h] [-110h]
  int v96; // [sp+8h] [-108h]
  int v97; // [sp+Ch] [-104h]
  int v98; // [sp+10h] [-100h]
  int v99; // [sp+14h] [-FCh]
  float v100[3]; // [sp+50h] [-C0h] BYREF
  char v101; // [sp+5Fh] [-B1h] BYREF

  numClamped = this->numClamped;
  v4 = r;
  if ( (((((numClamped ^ r) & 0x80000000) == 0) + (r >= numClamped)) & 1) != 0 )
  {
    if ( (signed int)r < this->clampedChangeStart )
      this->clampedChangeStart = r;
    this->numClamped = numClamped - 1;
    if ( r != numClamped - 1 )
    {
      idLCP_Symmetric::Swap(this, i: r, j: numClamped - 1);
      HIDWORD(v7) = ((int (*)(void))RtlCheckStack12)();
      *(_DWORD *)((char *)back_chain + v8) = back_chain[0];
      if ( v4 == 0 )
      {
        rowPtrs = this->rowPtrs;
        if ( HIDWORD(v5) == 1 )
        {
          v10 = **rowPtrs;
          if ( __fabs(v10) < idMath::FLT_SMALLEST_NON_DENORMAL )
          {
            HIDWORD(v7) = "idLCP_Symmetric::RemoveClamped: updating factorization failed\n";
            LODWORD(v5) = *rowPtrs;
            idLib::Printf(
              fmt: v7,
              a2: __SPAIR64__(&v101, back_chain[0]),
              a3: v6,
              a4: v5,
              a5: v96,
              a6: v97,
              a7: v98,
              a8: v99);
            v10 = idMath::FLT_SMALLEST_NON_DENORMAL;
          }
          *this->clamped.mat = v10;
          *this->diagonal.p = (float)1.0 / (float)v10;
          return;
        }
        v11 = *(int *)((char *)rowPtrs + v6);
        v12 = 1;
        v13 = *rowPtrs;
        v100[0] = **rowPtrs - *(float *)(v6 + v11);
        if ( this->numClamped > 1 )
        {
          v14 = (float *)(v11 + 4);
          v15 = (char *)v13 - v11;
          v16 = (char *)v100 - v11;
          do
          {
            ++v12;
            *(float *)((char *)v14 + (_DWORD)v16) = *(float *)((char *)v14 + (_DWORD)v15) - *v14;
            ++v14;
          }
          while ( v12 < this->numClamped );
        }
        goto LABEL_35;
      }
      ((void (__fastcall *)(_DWORD))RtlCheckStack12)(a1: HIDWORD(v7));
      v17 = this->rowPtrs;
      v18 = v4;
      *(_DWORD *)((char *)back_chain + v19) = back_chain[0];
      LowerTriangularSolve_SIMD(L: &this->clamped, x: v100, b: v17[v4], n: v4, skip: 0);
      Multiply_SIMD(
        dst: &this->clamped.mat[this->clamped.numColumns * v4],
        src0: v20,
        src1: this->diagonal.p,
        count: v4);
      if ( v4 != this->numClamped - 1 )
      {
        v27 = 0;
        if ( v4 >= 4 )
        {
          v28 = (float *)(v7 - 4);
          do
          {
            v28[1] = this->clamped.mat[this->clamped.numColumns * v4 + v27]
                   * this->clamped.mat[(this->clamped.numColumns + 1) * v27];
            v28[2] = *(float *)((char *)this->clamped.mat + (4 * (v27 + 2) - 4) * (this->clamped.numColumns + 1))
                   * this->clamped.mat[this->clamped.numColumns * v4 + 1 + v27];
            v28[3] = this->clamped.mat[this->clamped.numColumns * v4 + 2 + v27]
                   * this->clamped.mat[(this->clamped.numColumns + 1) * (v27 + 2)];
            numColumns = this->clamped.numColumns;
            HIDWORD(v7) = numColumns * v4 + v27 + 3;
            v30 = (numColumns + 1) * (v27 + 3);
            v27 += 4;
            v28 += 4;
            *v28 = this->clamped.mat[v30] * this->clamped.mat[HIDWORD(v7)];
          }
          while ( v27 < v4 - 3 );
        }
        if ( v27 < v4 )
        {
          v31 = (float *)(4 * v27 + v7 - 4);
          v32 = v4 - v27;
          do
          {
            v33 = this->clamped.numColumns;
            HIDWORD(v7) = (v33 + 1) * v27;
            v34 = v33 * v4 + v27++;
            *++v31 = this->clamped.mat[v34] * this->clamped.mat[HIDWORD(v7)];
            --v32;
          }
          while ( v32 != 0 );
        }
        v35 = v4;
        if ( v4 < this->numClamped )
        {
          HIDWORD(v7) = 4 * v4;
          do
          {
            v36 = this->clamped.numColumns;
            mat = this->clamped.mat;
            if ( v35 == v4 )
              v38 = mat[(v36 + 1) * v4];
            else
              v38 = (float)(mat[v36 * v35 + v4] * mat[(v36 + 1) * v4]);
            v39 = 0.0;
            v40 = 0.0;
            v41 = 0;
            v42 = &mat[v36 * v35];
            if ( v4 >= 2 )
            {
              v43 = v42 - 2;
              v44 = (float *)(v7 + 4);
              do
              {
                v41 += 2;
                v43 += 2;
                v40 = (float)((float)(*(float *)((char *)v44 + (_DWORD)v42 - v7) * *v44) + (float)v40);
                v39 = (float)((float)(*(v44 - 1) * *v43) + (float)v39);
                v44 += 2;
              }
              while ( v41 < v4 - 1 );
            }
            if ( v41 < v4 )
              v38 = (float)((float)(v42[v41] * *(float *)(4 * v41 + v7)) + (float)v38);
            ++v35;
            *(float *)((char *)v100 + HIDWORD(v7)) = *(float *)((char *)this->rowPtrs[v18] + HIDWORD(v7))
                                                   - (float)((float)((float)v40 + (float)v39) + (float)v38);
            HIDWORD(v7) += 4;
          }
          while ( v35 < this->numClamped );
        }
LABEL_35:
        v45 = ((int (__fastcall *)(_DWORD))RtlCheckStack12)(a1: HIDWORD(v7));
        *(_DWORD *)((char *)back_chain + v46) = back_chain[0];
        ((void (__fastcall *)(int))RtlCheckStack12)(a1: v45);
        LODWORD(v48) = 0x82000000;
        v49 = v4 + 1;
        v50 = v100[v4];
        v51 = v4 + 1;
        *(_DWORD *)((char *)back_chain + v52) = back_chain[0];
        LODWORD(v53) = &v100[v4];
        *(float *)(4 * v4 + v47) = (float)((float)((float)v50 * (float)0.5) + (float)1.0) * (float)0.70710677;
        *(float *)v53 = (float)((float)(*(float *)v53 * (float)0.5) - (float)1.0) * (float)0.70710677;
        HIDWORD(v53) = this->numClamped;
        if ( v4 + 1 < SHIDWORD(v53) )
        {
          HIDWORD(v53) = 0;
          v54 = &v100[v49];
          LODWORD(v48) = v47 - (_DWORD)v100;
          do
          {
            ++v51;
            v55 = (float)(*v54 * (float)0.70710677);
            *v54 = *v54 * (float)0.70710677;
            *(float *)((char *)v54++ + v48) = v55;
          }
          while ( v51 < this->numClamped );
        }
        v56 = this->clamped.numColumns;
        v57 = 1.0;
        v58 = -1.0;
        if ( v4 < this->numClamped )
        {
          v59 = v4;
          v60 = 4 * v56;
          v61 = &v100[v4];
          v62 = 4 * v49 * v56;
          v63 = 4 * (v4 + 2) * v56;
          v64 = v47 - (_DWORD)v100;
          do
          {
            v65 = *(float *)((char *)v61 + v64);
            LODWORD(v66) = this->clamped.mat;
            HIDWORD(v66) = this->clamped.numColumns + 1;
            v67 = idMath::FLT_SMALLEST_NON_DENORMAL;
            LODWORD(v68) = HIDWORD(v66) * v4;
            HIDWORD(v68) = 4 * HIDWORD(v66) * v4;
            v69 = *(float *)(HIDWORD(v68) + v66);
            v70 = (float)((float)((float)(*(float *)((char *)v61 + v64) * *(float *)((char *)v61 + v64)) * (float)v57)
                        + *(float *)(HIDWORD(v68) + v66));
            if ( __fabs(v70) < idMath::FLT_SMALLEST_NON_DENORMAL )
            {
              HIDWORD(v48) = "idLCP_Symmetric::RemoveClamped: updating factorization failed\n";
              idLib::Printf(fmt: v48, a2: v53, a3: v68, a4: v66, a5: v96, a6: v97, a7: v98, a8: v99);
              v67 = idMath::FLT_SMALLEST_NON_DENORMAL;
              v70 = idMath::FLT_SMALLEST_NON_DENORMAL;
            }
            v71 = *v61;
            v72 = (float)((float)v57 / (float)v70);
            v73 = v70;
            v57 = (float)((float)((float)v57 / (float)v70) * (float)v69);
            v74 = (float)((float)((float)(*v61 * *v61) * (float)v58) + (float)v70);
            v75 = (float)((float)v65 * (float)v72);
            if ( __fabs(v74) < v67 )
            {
              HIDWORD(v48) = "idLCP_Symmetric::RemoveClamped: updating factorization failed\n";
              idLib::Printf(fmt: v48, a2: v53, a3: v68, a4: v66, a5: v96, a6: v97, a7: v98, a8: v99);
              v74 = idMath::FLT_SMALLEST_NON_DENORMAL;
            }
            v76 = (float)((float)1.0 / (float)v74);
            HIDWORD(v48) = v4 + 1;
            v77 = v4 + 1;
            v78 = (float)((float)((float)1.0 / (float)v74) * (float)v58);
            LODWORD(v53) = 4 * (this->clamped.numColumns + 1) * v4;
            *(float *)((char *)this->clamped.mat + v53) = v74;
            v79 = (float)((float)v71 * (float)((float)((float)1.0 / (float)v74) * (float)v58));
            v58 = (float)((float)v78 * (float)v73);
            HIDWORD(v53) = this->diagonal.p;
            *(float *)(HIDWORD(v53) + v59 * 4) = v76;
            LODWORD(v48) = &this->clamped.mat[v59];
            if ( v4 + 1 < this->numClamped - 1 )
            {
              v80 = (float *)((char *)v61 + v64 - 4);
              LODWORD(v53) = 8 * v56;
              v81 = (float *)(v62 + v48);
              v82 = v61 + 2;
              v83 = (float *)(v63 + v48);
              do
              {
                v84 = *v81;
                v77 += 2;
                v85 = *v83;
                v86 = (float)-(float)((float)(*v83 * (float)v65) - *(float *)((char *)v82 + v64));
                v87 = (float)-(float)((float)(*v81 * (float)v65) - v80[2]);
                *(float *)((char *)v82 + v64) = -(float)((float)(*v83 * (float)v65) - *(float *)((char *)v82 + v64));
                v80 += 2;
                *v80 = v87;
                v88 = (float)-(float)((float)((float)((float)((float)v87 * (float)v75) + (float)v84) * (float)v71)
                                    - *(v82 - 1));
                v89 = (float)-(float)((float)((float)((float)((float)v86 * (float)v75) + (float)v85) * (float)v71) - *v82);
                *(v82 - 1) = -(float)((float)((float)((float)((float)v87 * (float)v75) + (float)v84) * (float)v71)
                                    - *(v82 - 1));
                *v82 = v89;
                *v81 = (float)((float)v88 * (float)v79) + (float)((float)((float)v87 * (float)v75) + (float)v84);
                *v83 = (float)((float)v89 * (float)v79) + (float)((float)((float)v86 * (float)v75) + (float)v85);
                v82 += 2;
                v81 = (float *)((char *)v81 + v53);
                v83 = (float *)((char *)v83 + v53);
                HIDWORD(v53) = this->numClamped - 1;
              }
              while ( v77 < SHIDWORD(v53) );
            }
            if ( v77 < this->numClamped )
            {
              v90 = &v100[v77];
              v91 = (float *)(4 * v77 * v56 + v48);
              do
              {
                v92 = *v91;
                ++v77;
                v93 = (float)-(float)((float)(*v91 * (float)v65) - *(float *)((char *)v90 + v64));
                *(float *)((char *)v90 + v64) = -(float)((float)(*v91 * (float)v65) - *(float *)((char *)v90 + v64));
                v94 = (float)-(float)((float)((float)((float)((float)v93 * (float)v75) + (float)v92) * (float)v71) - *v90);
                *v90 = -(float)((float)((float)((float)((float)v93 * (float)v75) + (float)v92) * (float)v71) - *v90);
                ++v90;
                *v91 = (float)((float)v94 * (float)v79) + (float)((float)((float)v93 * (float)v75) + (float)v92);
                v91 = (float *)((char *)v91 + v60);
              }
              while ( v77 < this->numClamped );
            }
            ++v4;
            ++v59;
            ++v61;
            v62 += v60;
            v63 += v60;
          }
          while ( SHIDWORD(v48) < this->numClamped );
        }
        return;
      }
      v24 = DotProduct_SIMD(src0: &this->clamped.mat[this->clamped.numColumns * v4], src1: (const float *)v7, count: v4);
      LODWORD(v25) = this->rowPtrs;
      HIDWORD(v25) = *(_DWORD *)(v18 * 4 + v25);
      v26 = (float)(*(float *)(HIDWORD(v25) + 4 * v4) - (float)v24);
      if ( __fabs(v26) < idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        HIDWORD(v23) = "idLCP_Symmetric::RemoveClamped: updating factorization failed\n";
        idLib::Printf(fmt: v23, a2: v22, a3: v25, a4: v21, a5: v96, a6: v97, a7: v98, a8: v99);
        v26 = idMath::FLT_SMALLEST_NON_DENORMAL;
      }
      this->clamped.mat[(this->clamped.numColumns + 1) * v4] = v26;
      this->diagonal.p[v18] = (float)1.0 / (float)v26;
    }
  }
}


// ========================================================================
// ?Solve@idLCP_Symmetric@@UAA_NABVidMatX@@AAVidVecX@@ABV3@22PBHPBM@Z
// EA  : 0x82F35730
// RVA : 0x00F35730
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

int __fastcall idLCP_Symmetric::Solve(
        idLCP_Symmetric *this,
        const idMatX *o_m,
        idVecX *o_x,
        const idVecX *o_b,
        const idVecX *o_lo,
        const idVecX *o_hi,
        const int *o_boxIndex,
        const float *o_boxScale)
{
  idVecX *p_f; // r17
  int v18; // r12
  int v19; // r4
  idVecX *p_a; // r26
  int v21; // r4
  int v22; // r12
  int v23; // r4
  int v24; // r12
  int v25; // r4
  int v26; // r12
  int v27; // r4
  int v28; // r12
  unsigned int v29; // r15
  int v30; // r12
  int v31; // r12
  idMatX *p_m; // r19
  int v33; // r11
  int v36; // r10
  idVecX *v39; // r3
  int v40; // r3
  int v41; // r10
  int v42; // r11
  int v43; // r12
  int v44; // r10
  int v45; // r8
  int v46; // r9
  char **p_side; // r21
  int v48; // r12
  int v49; // r3
  int **p_permuted; // r20
  int v51; // r9
  int v52; // r11
  int v53; // r12
  int v54; // r10
  int v55; // r11
  int *p_numUnbounded; // r16
  int v57; // r29
  int v58; // r28
  double v59; // fp0
  int v60; // r11
  int v61; // r14
  int v62; // r10
  int v63; // r29
  int v64; // r28
  int v65; // r10
  int v66; // r12
  int v67; // r5
  int v68; // r4
  int v69; // r12
  int v70; // r4
  int v71; // r12
  int v72; // r4
  int v73; // r12
  int *p_numClamped; // r22
  bool v75; // cr58
  __int64 v76; // r10
  __int64 v77; // r8
  __int64 v78; // r6
  __int64 v79; // r4
  int result; // r3
  bool v81; // cr58
  int v82; // r4
  int v83; // r12
  int v84; // r4
  int v85; // r12
  int v87; // r26
  float *v89; // r4
  const float **p_p; // r23
  int v92; // r17
  int v93; // r24
  int v94; // r9
  int v95; // r11
  int v96; // r11
  int v97; // ctr
  int v98; // r10
  int v99; // r11
  float *p; // r9
  int v101; // r7
  double v102; // fp12
  float *v105; // r9
  double v106; // fp3
  float **v110; // r28
  int v111; // r10
  float **v116; // r25
  __int64 v117; // r8
  double v118; // fp0
  double v119; // fp31
  double v120; // fp8
  double v121; // fp7
  double v122; // fp6
  double v123; // fp5
  double v124; // fp4
  double v125; // fp3
  double v126; // fp2
  const float *v127; // r4
  double v128; // fp8
  double v129; // fp7
  double v130; // fp6
  double v131; // fp5
  double v132; // fp4
  double v133; // fp3
  double v134; // fp2
  double v135; // fp1
  const float *v136; // r4
  double v137; // fp8
  double v138; // fp7
  double v139; // fp6
  double v140; // fp5
  double v141; // fp4
  double v142; // fp3
  double v143; // fp2
  unsigned int v144; // r29
  int v145; // r10
  int v146; // r11
  float *v147; // r10
  int maxIterations; // r5
  __int64 v149; // r10
  __int64 v150; // r10
  __int64 v151; // r6
  idVecX *v152; // r9
  int v153; // r10
  int v154; // r11
  _DWORD back_chain[2]; // [sp+0h] [-190h]
  int v157; // [sp+8h] [-188h]
  int v158; // [sp+Ch] [-184h]
  float *v159; // [sp+10h] [-180h]
  int *v160; // [sp+14h] [-17Ch]
  int *v161; // [sp+18h] [-178h]
  int v162; // [sp+1Ch] [-174h]
  int v163; // [sp+20h] [-170h]
  int v164; // [sp+24h] [-16Ch]
  int v165; // [sp+28h] [-168h]
  int v166; // [sp+2Ch] [-164h]
  int v167; // [sp+30h] [-160h]
  int v168; // [sp+34h] [-15Ch]
  int v169; // [sp+38h] [-158h]
  int v170; // [sp+3Ch] [-154h]
  int v171; // [sp+40h] [-150h]
  int v172; // [sp+44h] [-14Ch]
  int v173; // [sp+48h] [-148h]
  int v174; // [sp+4Ch] [-144h]
  int v175; // [sp+50h] [-140h]
  int v176; // [sp+58h] [-138h]
  int v177; // [sp+60h] [-130h]
  float v178; // [sp+64h] [-12Ch]
  int v179; // [sp+68h] [-128h]
  int v180; // [sp+70h] [-120h]
  int v181; // [sp+78h] [-118h]
  float v182; // [sp+80h] [-110h] BYREF
  const float *v183; // [sp+84h] [-10Ch]
  __vector4 *v184; // [sp+88h] [-108h]
  float v185; // [sp+8Ch] [-104h] BYREF
  unsigned int v186; // [sp+90h] [-100h] BYREF
  int size; // [sp+94h] [-FCh] BYREF
  idVecX *numRows; // [sp+98h] [-F8h]
  idStr v189[2]; // [sp+A0h] [-F0h] BYREF
  char v190; // [sp+FFh] [-91h] BYREF

  _R12 = -208;
  __asm { stvx128   v127, r1, r12 }
  this->padded = (_cntlzw(o_m->numColumns - ((o_m->numRows + 3) & 0xFFFFFFFC)) & 0x20) != 0;
  numRows = (idVecX *)o_m->numRows;
  p_f = &this->f;
  ((void (*)(void))RtlCheckStack12)();
  numRows = &this->f;
  *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
  idVecX::SetData(this: &this->f, length: v19, data: &v182);
  size = o_b->size;
  ((void (*)(void))RtlCheckStack12)();
  p_a = &this->a;
  size = v21;
  *(_DWORD *)((char *)back_chain + v22) = back_chain[0];
  idVecX::SetData(this: &this->a, length: v21, data: &v182);
  size = o_b->size;
  ((void (*)(void))RtlCheckStack12)();
  size = v23;
  *(_DWORD *)((char *)back_chain + v24) = back_chain[0];
  idVecX::SetData(this: &this->b, length: v23, data: &v182);
  size = o_lo->size;
  ((void (*)(void))RtlCheckStack12)();
  size = v25;
  *(_DWORD *)((char *)back_chain + v26) = back_chain[0];
  idVecX::SetData(this: &this->lo, length: v25, data: &v182);
  size = o_hi->size;
  ((void (*)(void))RtlCheckStack12)();
  size = v27;
  *(_DWORD *)((char *)back_chain + v28) = back_chain[0];
  idVecX::SetData(this: &this->hi, length: v27, data: &v182);
  v29 = 0;
  if ( o_boxIndex != nullptr && o_boxScale != nullptr )
  {
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v30) = back_chain[0];
    this->boxIndex = (int *)&v182;
    memcpy(Dst: &v182, Src: o_boxIndex, Size: 4 * o_x->size);
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v31) = back_chain[0];
    this->boxScale = &v182;
    memcpy(Dst: &v182, Src: o_boxScale, Size: 4 * o_x->size);
  }
  else
  {
    this->boxIndex = nullptr;
    this->boxScale = nullptr;
  }
  p_m = &this->m;
  idMatX::SetData(this: &this->m, rows: o_m->numRows, columns: o_m->numColumns, data: o_m->mat);
  v33 = 0;
  if ( p_f->size > 0 )
  {
    __asm { vspltisw128 v63, 0 }
    _R10 = 0;
    do
    {
      _R9 = this->f.p;
      v33 += 4;
      __asm { stvx128   v63, r9, r10 }
      _R10 += 16;
    }
    while ( v33 < p_f->size );
  }
  v36 = 0;
  if ( p_a->size > 0 )
  {
    __asm { vspltisw128 v63, 0 }
    _R11 = 0;
    do
    {
      _R9 = this->a.p;
      v36 += 4;
      __asm { stvx128   v63, r9, r11 }
      _R11 += 16;
    }
    while ( v36 < p_a->size );
  }
  idVecX::operator=(this: &this->b, a: o_b);
  idVecX::operator=(this: &this->lo, a: o_lo);
  v39 = idVecX::operator=(this: &this->hi, a: o_hi);
  size = p_m->numRows;
  v40 = ((int (__fastcall *)(idVecX *))RtlCheckStack12)(a1: v39);
  size = v41;
  v42 = 0;
  *(_DWORD *)((char *)back_chain + v43) = back_chain[0];
  this->rowPtrs = (float **)&v182;
  if ( v41 > 0 )
  {
    v44 = 0;
    do
    {
      v45 = this->m.numColumns * v42++;
      this->rowPtrs[v44++] = &this->m.mat[v45];
      v40 = p_m->numRows;
    }
    while ( v42 < p_m->numRows );
  }
  size = p_m->numRows;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v40);
  size = v46;
  p_side = (char **)&this->side;
  *(_DWORD *)((char *)back_chain + v48) = back_chain[0];
  this->side = (int *)&v182;
  v49 = ((int (*)(void))RtlCheckStack12)();
  p_permuted = &this->permuted;
  size = v51;
  v52 = 0;
  *(_DWORD *)((char *)back_chain + v53) = back_chain[0];
  this->permuted = (int *)&v182;
  if ( v51 > 0 )
  {
    v54 = 0;
    do
      (*p_permuted)[v54++] = v52++;
    while ( v52 < p_m->numRows );
  }
  v55 = p_m->numRows;
  p_numUnbounded = &this->numUnbounded;
  v57 = 0;
  this->numUnbounded = 0;
  if ( v55 > 0 )
  {
    v58 = 0;
    v59 = 1.0e30;
    do
    {
      if ( this->lo.p[v58] == -v59 && this->hi.p[v58] == v59 )
      {
        if ( *p_numUnbounded != v57 )
          idLCP_Symmetric::Swap(this, i: *p_numUnbounded, j: v57);
        ++*p_numUnbounded;
        v59 = 1.0e30;
      }
      ++v57;
      ++v58;
    }
    while ( v57 < p_m->numRows );
  }
  v60 = p_m->numRows;
  v61 = p_m->numRows;
  if ( this->boxIndex != nullptr )
  {
    v62 = *p_numUnbounded;
    v63 = v60 - 1;
    size = p_m->numRows;
    if ( v60 - 1 >= v62 )
    {
      v64 = v63;
      do
      {
        if ( this->boxIndex[v64] >= 0 && --v61 != v63 )
          idLCP_Symmetric::Swap(this, i: v61, j: v63);
        --v63;
        --v64;
      }
      while ( v63 >= *p_numUnbounded );
    }
  }
  size = this->m.numColumns;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v49);
  size = v65;
  *(_DWORD *)((char *)back_chain + v66) = back_chain[0];
  idMatX::SetDataCacheLines(
    this: &this->clamped,
    rows: v65,
    columns: v67,
    data: (float *)((unsigned int)&v190 & 0xFFFFFF80),
    clear: true);
  size = p_m->numRows;
  ((void (*)(void))RtlCheckStack12)();
  size = v68;
  *(_DWORD *)((char *)back_chain + v69) = back_chain[0];
  idVecX::SetData(this: &this->diagonal, length: v68, data: &v182);
  size = p_m->numRows;
  ((void (*)(void))RtlCheckStack12)();
  size = v70;
  *(_DWORD *)((char *)back_chain + v71) = back_chain[0];
  idVecX::SetData(this: &this->solveCache1, length: v70, data: &v182);
  size = p_m->numRows;
  ((void (*)(void))RtlCheckStack12)();
  size = v72;
  *(_DWORD *)((char *)back_chain + v73) = back_chain[0];
  idVecX::SetData(this: &this->solveCache2, length: v72, data: &v182);
  p_numClamped = &this->numClamped;
  v75 = *p_numUnbounded == 0;
  this->numClamped = *p_numUnbounded;
  if ( !v75 )
  {
    if ( (unsigned __int8)idLCP_Symmetric::FactorClamped(this) == 0 )
    {
      HIDWORD(v79) = "idLCP_Symmetric::Solve: unbounded factorization failed\n";
      idLib::Printf(fmt: v79, a2: v78, a3: v77, a4: v76, a5: v157, a6: v158, a7: (int)v159, a8: (int)v160);
      result = 0;
      goto _M118375;
    }
    LowerTriangularSolve_SIMD(
      L: &this->clamped,
      x: this->solveCache1.p,
      b: this->b.p,
      n: *p_numClamped,
      skip: this->clampedChangeStart);
    Multiply_SIMD(dst: this->solveCache2.p, src0: this->solveCache1.p, src1: this->diagonal.p, count: *p_numClamped);
    LowerTriangularSolveTranspose_SIMD(L: &this->clamped, x: this->f.p, b: this->solveCache2.p, n: *p_numClamped);
    v81 = *p_numUnbounded == p_m->numRows;
    this->clampedChangeStart = *p_numClamped;
    if ( v81 )
    {
      idVecX::operator=(this: o_x, a: &this->f);
      goto LABEL_93;
    }
  }
  size = p_m->numRows;
  ((void (*)(void))RtlCheckStack12)();
  size = v82;
  *(_DWORD *)((char *)back_chain + v83) = back_chain[0];
  idVecX::SetData(this: &this->delta_f, length: v82, data: &v182);
  size = p_m->numRows;
  ((void (*)(void))RtlCheckStack12)();
  size = v84;
  *(_DWORD *)((char *)back_chain + v85) = back_chain[0];
  idVecX::SetData(this: &this->delta_a, length: v84, data: &v182);
  v189[0].len = 0;
  v189[0].allocedAndFlag = 20;
  v189[0].data = v189[0].baseBuffer;
  v189[0].baseBuffer[0] = 0;
  v87 = *p_numUnbounded;
  if ( *p_numUnbounded >= p_m->numRows )
    goto LABEL_89;
  __asm { vspltisw128 v127, 0 }
  LODWORD(_R6) = 0x82000000;
  HIDWORD(_R6) = &vmx_float_one;
  v89 = (float *)&LCP_BOUND_EPSILON;
  p_p = (const float **)&this->a.p;
  _R27 = v87;
  v184 = &vmx_float_one;
  v92 = v87 - 3;
  v183 = &LCP_BOUND_EPSILON;
  while ( 2 )
  {
    v93 = 0;
    this->clampedChangeStart = 0;
    if ( v87 == v61 )
    {
      v94 = 0;
      if ( v61 >= 4 )
      {
        LODWORD(_R6) = v61 - 3;
        v95 = 0;
        do
        {
          v94 += 4;
          o_x->p[(*p_permuted)[v95]] = this->f.p[v95];
          o_x->p[(*p_permuted)[v95 + 1]] = this->f.p[v95 + 1];
          o_x->p[(*p_permuted)[v95 + 2]] = this->f.p[v95 + 2];
          o_x->p[(*p_permuted)[v95 + 3]] = this->f.p[v95 + 3];
          v95 += 4;
        }
        while ( v94 < (int)_R6 );
      }
      if ( v94 < v61 )
      {
        v96 = v94;
        v97 = v61 - v94;
        do
        {
          LODWORD(_R6) = 4 * (*p_permuted)[v96];
          *(float *)((char *)o_x->p + _R6) = this->f.p[v96++];
          --v97;
        }
        while ( v97 != 0 );
      }
      v98 = v61;
      if ( v61 < p_m->numRows )
      {
        v99 = v61;
        do
        {
          ++v98;
          p = this->lo.p;
          v101 = this->boxIndex[v99];
          v102 = o_x->p[v101];
          _FP8 = (float)(p[v99] - (float)-__fabs((float)(this->boxScale[v99] * o_x->p[v101])));
          __asm { fsel      f7, f8, f13, f9 }
          p[v99] = _FP7;
          LODWORD(_R6) = this->boxScale;
          v105 = &this->hi.p[v99];
          v106 = __fabs((float)(*(float *)(v99 * 4 + _R6) * (float)v102));
          ++v99;
          _FP2 = (float)(*v105 - (float)v106);
          __asm { fsel      f1, f2, f3, f6 }
          *v105 = _FP1;
        }
        while ( v98 < p_m->numRows );
      }
    }
    _R9 = this->f.p;
    v110 = &this->f.p;
    __asm { vmr128    v0, v127 }
    v111 = 0;
    _R8 = this->rowPtrs[_R27];
    if ( v92 > 0 )
    {
      _R11 = this->f.p;
      _R7 = (char *)_R8 - (char *)_R9;
      do
      {
        v111 += 4;
        __asm
        {
          lvx128    v13, r7, r11
          lvx128    v12, r0, r11
        }
        _R11 += 4;
        __asm { vmaddfp   v0, v13, v0, v12 }
      }
      while ( v111 < v92 );
    }
    __asm { lvrx      v13, r27, r8 }
    _R10 = &v182;
    __asm { lvrx      v12, r27, r9 }
    v116 = &this->lo.p;
    __asm
    {
      vmaddfp   v0, v13, v0, v12
      lvx128    v63, r0, r5
    }
    __asm
    {
      vmsum4fp128 v63, v0, v63
      stvewx128 v63, r0, r10
    }
    LODWORD(v117) = *p_p;
    (*p_p)[_R27] = v182 - this->b.p[_R27];
    HIDWORD(v117) = this->lo.p;
    if ( *(float *)(_R27 * 4 + HIDWORD(v117)) >= -0.0000099999997 && (*p_p)[_R27] >= -0.0000099999997 )
    {
      *(_DWORD *)&(*p_side)[_R27 * 4] = -1;
      goto LABEL_80;
    }
    v118 = *v89;
    if ( this->hi.p[_R27] <= v118 && (*p_p)[_R27] <= v118 )
    {
      *(_DWORD *)&(*p_side)[_R27 * 4] = 1;
      goto LABEL_80;
    }
    if ( __fabs((*p_p)[_R27]) <= *v89 )
    {
      *(_DWORD *)&(*p_side)[_R27 * 4] = 0;
      idLCP_Symmetric::AddClamped(this, r: v87, useSolveCache: false);
      goto LABEL_80;
    }
    if ( this->maxIterations <= 0 )
      goto LABEL_78;
    while ( 1 )
    {
      v119 = (*p_p)[_R27] > 0.0 ? -1.0 : 1.0;
      idLCP_Symmetric::CalcForceDelta(this, d: v87, dir: v119);
      idLCP_Symmetric::CalcAccelDelta(this, d: v87);
      GetMaxStep_SIMD(
        f: *v110,
        a: *p_p,
        delta_f: this->delta_f.p,
        delta_a: this->delta_a.p,
        lo: *v116,
        hi: this->hi.p,
        side: *p_side,
        numUnbounded: *p_numUnbounded,
        dir: v119,
        a10: v126,
        a11: v125,
        a12: v124,
        a13: v123,
        a14: v122,
        a15: v121,
        a16: v120,
        numClamped: v157,
        d: v158,
        maxStep: v159,
        limit: v160,
        limitSide: v161,
        a22: v162,
        a23: v163,
        a24: v164,
        a25: v165,
        a26: v166,
        a27: v167,
        a28: v168,
        a29: v169,
        a30: v170,
        a31: v171,
        a32: v172,
        a33: v173,
        a34: v174,
        a35: v175,
        a36: *p_numClamped,
        a37: v176,
        a38: v87,
        a39: v177,
        a40: v178,
        a41: v179,
        a42: (int)&v185,
        a43: v180,
        numClampeda: (int)&v186,
        a45: v181,
        da: (int)&size);
      if ( v185 <= 0.0 )
        break;
      MultiplyAdd_SIMD(
        dst: *v110,
        constant: v185,
        src: v127,
        count: (const int)this->delta_f.p,
        a5: *p_numClamped,
        a6: v134,
        a7: v133,
        a8: v132,
        a9: v131,
        a10: v130,
        a11: v129,
        a12: v128,
        a13: *(float *)&v157,
        a14: *(float *)&v158,
        a15: *(float *)&v159,
        a16: *(float *)&v160,
        a17: *(float *)&v161,
        a18: *(float *)&v162);
      (*v110)[_R27] = (float)(this->delta_f.p[_R27] * (float)v135) + (*v110)[_R27];
      MultiplyAdd_SIMD(
        dst: (float *)&(*p_p)[*p_numClamped],
        constant: v135,
        src: v136,
        count: (const int)&this->delta_a.p[*p_numClamped],
        a5: v87 - *p_numClamped + 1,
        a6: v143,
        a7: v142,
        a8: v141,
        a9: v140,
        a10: v139,
        a11: v138,
        a12: v137,
        a13: *(float *)&v157,
        a14: *(float *)&v158,
        a15: *(float *)&v159,
        a16: *(float *)&v160,
        a17: *(float *)&v161,
        a18: *(float *)&v162);
      v144 = v186;
      v145 = size;
      HIDWORD(v117) = *p_side;
      v146 = v186;
      *(_DWORD *)&(*p_side)[4 * v186] = size;
      if ( v145 != 0 )
      {
        if ( v145 == -1 )
        {
          v147 = *v116;
LABEL_72:
          (*v110)[v146] = v147[v146];
          if ( v144 == v87 )
            goto LABEL_78;
          idLCP_Symmetric::RemoveClamped(this, r: v144);
          goto LABEL_74;
        }
        if ( v145 == 1 )
        {
          v147 = this->hi.p;
          goto LABEL_72;
        }
      }
      else
      {
        (*p_p)[v146] = 0.0;
        idLCP_Symmetric::AddClamped(this, r: v144, useSolveCache: (_cntlzw(v87 - v144) & 0x20) != 0);
      }
LABEL_74:
      if ( v144 != v87 && ++v93 < this->maxIterations )
        continue;
      goto LABEL_78;
    }
    ++v29;
    this->hi.p[_R27] = 0.0;
    (*v116)[_R27] = 0.0;
    LODWORD(v117) = *v110;
    (*v110)[_R27] = 0.0;
    HIDWORD(v117) = *p_side;
    *(_DWORD *)&(*p_side)[_R27 * 4] = -1;
LABEL_78:
    maxIterations = this->maxIterations;
    if ( v93 >= maxIterations )
    {
      idStr::Format(this: v189, fmt: "max iterations %d", maxIterations);
    }
    else if ( v189[0].len == 0 )
    {
LABEL_80:
      ++v87;
      ++v92;
      ++_R27;
      if ( v87 < p_m->numRows )
      {
        v89 = (float *)v183;
        HIDWORD(_R6) = v184;
        continue;
      }
    }
    break;
  }
  if ( v29 != 0 && lcp_showFailures.valueInteger != 0 )
  {
    LODWORD(v149) = &unk_82390000;
    HIDWORD(v149) = *p_numUnbounded;
    HIDWORD(_R6) = p_m->numRows - *p_numUnbounded;
    idLib::Printf(
      fmt: __SPAIR64__("idLCP_Symmetric::Solve: %d of %d bounded variables ignored\n", v29),
      a2: _R6,
      a3: v117,
      a4: v149,
      a5: v157,
      a6: v158,
      a7: (int)v159,
      a8: (int)v160);
  }
  if ( v189[0].len != 0 && lcp_showFailures.valueInteger != 0 )
  {
    LODWORD(v150) = &unk_82390000;
    HIDWORD(v150) = *p_numUnbounded;
    HIDWORD(v151) = v29;
    LODWORD(v151) = p_m->numRows - *p_numUnbounded;
    idLib::Printf(
      fmt: __SPAIR64__("idLCP_Symmetric::Solve: %s (%d of %d bounded variables ignored)\n", (unsigned int)v189[0].data),
      a2: v151,
      a3: v117,
      a4: v150,
      a5: v157,
      a6: v158,
      a7: (int)v159,
      a8: (int)v160);
  }
LABEL_89:
  v152 = numRows;
  v153 = 0;
  if ( numRows->size > 0 )
  {
    v154 = 0;
    do
    {
      ++v153;
      o_x->p[(*p_permuted)[v154]] = this->f.p[v154];
      ++v154;
    }
    while ( v153 < v152->size );
  }
  idStr::FreeData(this: v189);
LABEL_93:
  result = 1;
_M118375:
  _R0 = -208;
  __asm { lvx128    v127, r1, r0 }
  return result;
}


// ========================================================================
// __unwind$117636
// EA  : 0x82F364E8
// RVA : 0x00F364E8
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _unwind_117636()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 160));
}


// ========================================================================
// ?AllocSymmetric@idLCP@@SAPAV1@XZ
// EA  : 0x82F36510
// RVA : 0x00F36510
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

idLCP_Symmetric *__fastcall idLCP::AllocSymmetric()
{
  idLCP_Symmetric *v0; // r3
  idLCP_Symmetric *v1; // r31

  v0 = (idLCP_Symmetric *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0xC4u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    v1 = idLCP_Symmetric::idLCP_Symmetric(this: v0);
  else
    v1 = nullptr;
  v1->SetMaxIterations(this: v1, a2: 32);
  return v1;
}


// ========================================================================
// ?Test_f@idLCP@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F365F0
// RVA : 0x00F365F0
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __fastcall idLCP::Test_f(const idCmdArgs *args)
{
  DotProduct_Test();
  LowerTriangularSolve_Test();
  LowerTriangularSolveTranspose_Test();
  LDLT_Factor_Test();
}


// ========================================================================
// `dynamic initializer for 'lcp_showFailures''
// EA  : 0x83395818
// RVA : 0x01395818
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lcp_showFailures__()
{
  idCVar::idCVar(
    this: &lcp_showFailures,
    name: "lcp_showFailures",
    value: "0",
    flags: 1,
    description: "show LCP solver failures",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lcp_showFailures__);
}


// ========================================================================
// `dynamic initializer for 'vmx_float_infinity''
// EA  : 0x83395870
// RVA : 0x01395870
// PDB : w:\tech5\shared\idlib\math\lcp.cpp
// ========================================================================

void _dynamic_initializer_for__vmx_float_infinity__()
{
  vmx_float_infinity.vector4_f32[0] = 1.0e30;
  vmx_float_infinity.vector4_f32[1] = 1.0e30;
  vmx_float_infinity.vector4_f32[2] = 1.0e30;
  vmx_float_infinity.vector4_f32[3] = 1.0e30;
}

