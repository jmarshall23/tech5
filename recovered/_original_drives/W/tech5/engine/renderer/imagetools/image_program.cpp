
// ========================================================================
// ?Extrude@idImageByteArray@@QAAXHHHH@Z
// EA  : 0x828CA7F0
// RVA : 0x008CA7F0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall idImageByteArray::Extrude(idImageByteArray *this, int x, int y, int w, int h)
{
  int v10; // r11
  int v11; // r9
  int i; // r10
  int v13; // r8
  int v14; // r11
  int v15; // r10
  int v16; // r9
  int j; // r11
  int width; // r3

  if ( y > 0 )
    memcpy(Dst: &this->data[4 * (y - 1) * this->width], Src: &this->data[4 * this->width * y], Size: 4 * this->width);
  if ( y + h < this->height )
    memcpy(
      Dst: &this->data[4 * this->width * (y + h)],
      Src: &this->data[4 * (y + h - 1) * this->width],
      Size: 4 * this->width);
  if ( x > 0 )
  {
    v10 = 4 * x;
    v11 = 0;
    for ( i = 4 * x - 4; v11 < this->height; i += v13 )
    {
      ++v11;
      this->data[i] = this->data[v10];
      this->data[i + 1] = this->data[v10 + 1];
      this->data[i + 2] = this->data[v10 + 2];
      this->data[i + 3] = this->data[v10 + 3];
      v13 = 4 * this->width;
      v10 += v13;
    }
  }
  v14 = x + w;
  if ( x + w < this->width )
  {
    v15 = 4 * v14;
    v16 = 0;
    for ( j = 4 * v14 - 4; v16 < this->height; v15 += 4 * width )
    {
      ++v16;
      this->data[v15] = this->data[j];
      this->data[v15 + 1] = this->data[j + 1];
      this->data[v15 + 2] = this->data[j + 2];
      this->data[v15 + 3] = this->data[j + 3];
      width = this->width;
      j += 4 * width;
    }
  }
}


// ========================================================================
// R_HeightmapToNormalMap
// EA  : 0x828CA9A8
// RVA : 0x008CA9A8
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall R_HeightmapToNormalMap(unsigned __int8 *data, int width, int height, double scale)
{
  int v4; // r31
  double v5; // fp31
  _BYTE *v9; // r3
  int v10; // r10
  unsigned __int8 *v11; // r11
  int i; // ctr
  int v13; // r7
  int v14; // r5
  int v15; // r25
  int v16; // r7
  int v17; // r11
  int v18; // ctr
  int v19; // r6
  int v20; // r10
  int v21; // r9
  int v22; // r8
  int v23; // r22
  int v24; // r9
  int v25; // r10
  __int64 v26; // r21
  double v27; // fp10
  int v28; // r9
  __int64 v29; // r11
  double v30; // fp3
  double v31; // fp1
  double v32; // fp7
  double v33; // fp5
  double v34; // fp10
  double v35; // fp4
  double v38; // fp2
  double v41; // fp3
  double v42; // fp10
  double v43; // fp4
  double v44; // fp11
  double v45; // fp11
  double v46; // fp11
  double v47; // fp10
  double v48; // fp3
  double v49; // fp1
  double v50; // fp11
  double v51; // fp7
  double v52; // fp5
  double v53; // fp3
  double v56; // fp10
  double v57; // fp6
  double v58; // fp3
  double v59; // fp13
  double v60; // fp11
  int v61; // fp6

  v4 = width * height;
  v5 = (float)((float)scale * (float)0.00390625);
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(38) : TAG_IMAGE",
         size: width * height,
         tag: TAG_IMAGE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v10 = 0;
  if ( v4 > 0 )
  {
    v11 = data - 4;
    for ( i = v4; i != 0; --i )
    {
      v13 = v11[5];
      v14 = v11[6];
      v11 += 4;
      v9[v10++] = (v13 + v14 + *v11) / 3;
    }
  }
  v15 = 0;
  if ( height > 0 )
  {
    v16 = 0;
    do
    {
      v17 = 0;
      if ( width > 0 )
      {
        v18 = width;
        v19 = ((v15 + 1) & (height - 1)) * width;
        v20 = v16;
        v21 = v19;
        do
        {
          v22 = v17 + 1;
          v23 = (unsigned __int8)v9[v20];
          v24 = (unsigned __int8)v9[v21];
          v25 = (width - 1) & (v17 + 1);
          LODWORD(v26) = v23 - v24;
          HIDWORD(v26) = v25 + v19;
          v27 = (double)v26;
          v28 = v24 - (unsigned __int8)v9[v25 + v19];
          LODWORD(v26) = (unsigned __int8)v9[v16 + v25];
          HIDWORD(v29) = 4 * (v16 + v17);
          LODWORD(v29) = v28;
          v30 = (double)v29;
          LODWORD(v29) = v23 - v26;
          v31 = (float)((float)v27 * (float)v5);
          v32 = (float)((float)v29 * (float)v5);
          v33 = (float)((float)v30 * (float)v5);
          v35 = (float)((float)((float)((float)((float)v27 * (float)v5) * (float)((float)v27 * (float)v5))
                              + (float)((float)((float)v30 * (float)v5) * (float)((float)v30 * (float)v5)))
                      + (float)1.0);
          v34 = (float)((float)((float)((float)((float)v27 * (float)v5) * (float)((float)v27 * (float)v5))
                              + (float)((float)v32 * (float)v32))
                      + (float)1.0);
          _FP3 = (float)((float)v34 - idMath::FLT_SMALLEST_NON_DENORMAL);
          _FP11 = (float)((float)v35 - idMath::FLT_SMALLEST_NON_DENORMAL);
          v38 = (float)((float)v34 * (float)0.5);
          __asm
          {
            fsel      f10, f3, f10, f13
            fsel      f11, f11, f4, f13
          }
          v41 = (float)((float)v35 * (float)0.5);
          v42 = __frsqrte(_FP10);
          v43 = __frsqrte(_FP11);
          v44 = (float)((float)-(float)((float)((float)((float)v42 * (float)v38) * (float)v42) - (float)1.5) * (float)v42);
          v45 = (float)((float)-(float)((float)((float)((float)v44 * (float)v38) * (float)v44) - (float)1.5) * (float)v44);
          v46 = (float)((float)-(float)((float)((float)((float)v45 * (float)v38) * (float)v45) - (float)1.5) * (float)v45);
          v47 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)v41) * (float)v43) - (float)1.5) * (float)v43)
                                                                                              * (float)v41)
                                                                                      * (float)((float)-(float)((float)((float)((float)v43 * (float)v41) * (float)v43) - (float)1.5)
                                                                                              * (float)v43))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v43 * (float)v41)
                                                                                              * (float)v43)
                                                                                      - (float)1.5)
                                                                      * (float)v43))
                                                      * (float)v41)
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)v41) * (float)v43) - (float)1.5)
                                                                                              * (float)v43)
                                                                                      * (float)v41)
                                                                              * (float)((float)-(float)((float)((float)((float)v43 * (float)v41) * (float)v43) - (float)1.5)
                                                                                      * (float)v43))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v43 * (float)v41)
                                                                                      * (float)v43)
                                                                              - (float)1.5)
                                                              * (float)v43)))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)v41)
                                                                                              * (float)v43)
                                                                                      - (float)1.5)
                                                                      * (float)v43)
                                                              * (float)v41)
                                                      * (float)((float)-(float)((float)((float)((float)v43 * (float)v41)
                                                                                      * (float)v43)
                                                                              - (float)1.5)
                                                              * (float)v43))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v43 * (float)v41) * (float)v43)
                                                      - (float)1.5)
                                      * (float)v43)));
          v48 = (float)((float)v31 * (float)v46);
          v49 = (float)((float)v31 * (float)v47);
          v51 = (float)((float)v49 + (float)v48);
          v52 = (float)((float)((float)v47 * (float)v33) + (float)((float)v46 * (float)((float)v29 * (float)v5)));
          v50 = (float)((float)v47 + (float)v46);
          v53 = (float)((float)((float)v52 * (float)v52)
                      + (float)((float)((float)((float)v49 + (float)v48) * (float)((float)v49 + (float)v48))
                              + (float)((float)v50 * (float)v50)));
          _FP2 = (float)((float)v53 - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f13, f2, f3, f13 }
          v56 = __frsqrte(_FP13);
          v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56
                                                                                              * (float)((float)v53 * (float)0.5))
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56)
                                                      * (float)((float)v53 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v56
                                                                                      * (float)((float)v53 * (float)0.5))
                                                                              * (float)v56)
                                                                      - (float)1.5)
                                                      * (float)v56))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)v53 * (float)0.5))
                                                      * (float)v56)
                                              - (float)1.5)
                              * (float)v56));
          v58 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)v53 * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)((float)v53 * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)v53 * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56
                                                                                              * (float)((float)v53 * (float)0.5))
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))
                                              * (float)((float)v53 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)v53 * (float)0.5)) * (float)v56) - (float)1.5)
                                                                                      * (float)v56)
                                                                              * (float)((float)v53 * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)v53 * (float)0.5)) * (float)v56)
                                                                                              - (float)1.5)
                                                                              * (float)v56))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v56
                                                                                      * (float)((float)v53 * (float)0.5))
                                                                              * (float)v56)
                                                                      - (float)1.5)
                                                      * (float)v56)))
                              - (float)1.5);
          v59 = (float)((float)v51 * (float)((float)v58 * (float)v57));
          v60 = (float)((float)v50 * (float)((float)v58 * (float)v57));
          v61 = (int)(float)((float)((float)((float)((float)((float)v58 * (float)v57) * (float)v52) + (float)1.0)
                                   * (float)127.5)
                           + (float)0.5);
          if ( v61 >= 0 )
          {
            if ( v61 <= 255 )
              LOBYTE(v29) = v61;
            else
              LOBYTE(v29) = -1;
          }
          else
          {
            LOBYTE(v29) = 0;
          }
          data[HIDWORD(v29)] = v29;
          LODWORD(v29) = (int)(float)((float)((float)((float)v59 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( (int)v29 >= 0 )
          {
            if ( (int)v29 > 255 )
              LOBYTE(v29) = -1;
          }
          else
          {
            LOBYTE(v29) = 0;
          }
          data[HIDWORD(v29) + 1] = v29;
          LODWORD(v29) = (int)(float)((float)((float)((float)v60 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( (int)v29 >= 0 )
          {
            if ( (int)v29 > 255 )
              LOBYTE(v29) = -1;
          }
          else
          {
            LOBYTE(v29) = 0;
          }
          data[HIDWORD(v29) + 2] = v29;
          v17 = v22;
          data[HIDWORD(v29) + 3] = -1;
          v20 = v16 + v22;
          v21 = v19 + v22;
          --v18;
        }
        while ( v18 != 0 );
      }
      ++v15;
      v16 += width;
    }
    while ( v15 < height );
  }
  idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
}


// ========================================================================
// R_ImageScale
// EA  : 0x828CAD28
// RVA : 0x008CAD28
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall R_ImageScale(unsigned __int8 *data, int width, int height, float *scale, __int64 a5)
{
  __int64 v5; // r26
  int v6; // r27
  int v7; // r11
  unsigned __int8 *v8; // r5
  unsigned __int8 *v9; // r4
  int v10; // r9
  int v11; // r9
  int v12; // r8
  __int64 v13; // r9
  int v14; // r9
  int v15; // r8
  __int64 v16; // r9
  int v17; // r9
  unsigned __int8 *v18; // r9
  int v19; // r10
  int v20; // ctr
  int v21; // r10

  v6 = 4 * width * height;
  v7 = 0;
  if ( v6 >= 4 )
  {
    v8 = data + 1;
    HIDWORD(a5) = data + 2;
    v9 = data + 3;
    v10 = 0;
    do
    {
      LODWORD(a5) = data[v7];
      v11 = (int)(float)(*(float *)((char *)scale + v10) * (float)a5);
      if ( v11 >= 0 )
      {
        if ( v11 > 255 )
          LOBYTE(v11) = -1;
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      v12 = v8[v7];
      data[v7] = v11;
      LODWORD(v13) = v12;
      HIDWORD(v13) = (4 * (v7 + 1)) & 0xC;
      v14 = (int)(float)(*(float *)((char *)scale + HIDWORD(v13)) * (float)v13);
      if ( v14 >= 0 )
      {
        if ( v14 > 255 )
          LOBYTE(v14) = -1;
      }
      else
      {
        LOBYTE(v14) = 0;
      }
      v15 = *(unsigned __int8 *)(HIDWORD(a5) + v7);
      v8[v7] = v14;
      LODWORD(v16) = v15;
      HIDWORD(v16) = (4 * (v7 - 2)) & 0xC;
      v17 = (int)(float)(*(float *)((char *)scale + HIDWORD(v16)) * (float)v16);
      if ( v17 >= 0 )
      {
        LOBYTE(a5) = -1;
        if ( v17 <= 255 )
          LOBYTE(a5) = v17;
      }
      else
      {
        LOBYTE(a5) = 0;
      }
      LODWORD(v5) = v9[v7];
      *(_BYTE *)(HIDWORD(a5) + v7) = a5;
      v18 = &v9[v7];
      v19 = (int)(float)(*(float *)((char *)scale + ((4 * (v7 - 1)) & 0xC)) * (float)v5);
      if ( v19 >= 0 )
      {
        if ( v19 > 255 )
          LOBYTE(v19) = -1;
      }
      else
      {
        LOBYTE(v19) = 0;
      }
      v7 += 4;
      *v18 = v19;
      v10 = (4 * v7) & 0xC;
    }
    while ( v7 < v6 - 3 );
  }
  if ( v7 < v6 )
  {
    v20 = v6 - v7;
    do
    {
      LODWORD(a5) = data[v7];
      v21 = (int)(float)(*(float *)((char *)scale + ((4 * v7) & 0xC)) * (float)a5);
      if ( v21 >= 0 )
      {
        if ( v21 > 255 )
          LOBYTE(v21) = -1;
      }
      else
      {
        LOBYTE(v21) = 0;
      }
      data[v7++] = v21;
      --v20;
    }
    while ( v20 != 0 );
  }
}


// ========================================================================
// R_DivideAlpha
// EA  : 0x828CAF50
// RVA : 0x008CAF50
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall R_DivideAlpha(unsigned __int8 *data, int width, int height, int a4, int a5, _BYTE a6[12])
{
  int v6; // r11
  unsigned int v7; // ctr
  double v8; // fp0
  double v9; // fp0
  int v10; // r11
  int v11; // r11
  int v12; // r11

  v6 = 4 * width * height;
  *(_DWORD *)a6 = 0;
  if ( v6 > 0 )
  {
    v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
    do
    {
      *(_DWORD *)&a6[8] = data[*(_DWORD *)a6 + 3];
      v8 = (float)*(__int64 *)&a6[4];
      if ( v8 > 0.0 )
      {
        *(_DWORD *)&a6[8] = data[*(_DWORD *)a6];
        v9 = (float)((float)255.0 / (float)v8);
        v10 = (int)(float)((float)*(__int64 *)&a6[4] * (float)v9);
        if ( v10 >= 0 )
        {
          if ( v10 > 255 )
            LOBYTE(v10) = -1;
        }
        else
        {
          LOBYTE(v10) = 0;
        }
        data[*(_DWORD *)a6] = v10;
        *(_DWORD *)&a6[4] = data[*(_DWORD *)a6 + 1];
        v11 = (int)(float)((float)*(__int64 *)a6 * (float)v9);
        if ( v11 >= 0 )
        {
          if ( v11 > 255 )
            LOBYTE(v11) = -1;
        }
        else
        {
          LOBYTE(v11) = 0;
        }
        *(_DWORD *)&a6[4] = &data[*(_DWORD *)a6];
        data[*(_DWORD *)a6 + 1] = v11;
        *(_DWORD *)&a6[8] = data[*(_DWORD *)a6 + 2];
        v12 = (int)(float)((float)*(__int64 *)&a6[4] * (float)v9);
        if ( v12 >= 0 )
        {
          if ( v12 > 255 )
            LOBYTE(v12) = -1;
        }
        else
        {
          LOBYTE(v12) = 0;
        }
        *(_BYTE *)(*(_DWORD *)&a6[4] + 2) = v12;
      }
      *(_DWORD *)a6 += 4;
      --v7;
    }
    while ( v7 != 0 );
  }
}


// ========================================================================
// R_AddNormalMaps
// EA  : 0x828CB0A0
// RVA : 0x008CB0A0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall R_AddNormalMaps(
        unsigned __int8 *data1,
        int width1,
        int height1,
        unsigned __int8 *data2,
        int width2,
        unsigned int height2)
{
  __int64 v6; // r27 OVERLAPPED
  int v9; // r31
  unsigned __int8 *v10; // r3
  __int64 v11; // r5
  int v12; // r8
  int v13; // r9
  int i; // ctr
  int v15; // r11
  __int64 v16; // r11
  int v17; // r28
  double v18; // fp9
  double v19; // fp8
  double v20; // fp13
  double v23; // fp2
  double v24; // fp2
  double v25; // fp2
  double v26; // fp1
  double v27; // fp9
  double v30; // fp8
  double v31; // fp8
  double v32; // fp2
  double v33; // fp11
  double v34; // fp13

  v9 = height1;
  v10 = data2;
  if ( width2 == width1 && height2 == height1 )
  {
    HIDWORD(v11) = 0;
  }
  else
  {
    v10 = R_Dropsample(in: data2, inwidth: width2, inheight: height2, outwidth: width1, outheight: height1);
    HIDWORD(v11) = v10;
  }
  if ( v9 > 0 )
  {
    v12 = 0;
    do
    {
      v13 = 0;
      if ( width1 > 0 )
      {
        for ( i = width1; i != 0; --i )
        {
          v15 = 4 * (v12 + v13);
          HIDWORD(v16) = &data1[v15];
          LODWORD(v11) = data1[v15 + 1];
          v17 = data1[v15 + 2];
          LODWORD(v6) = data1[v15];
          v18 = (float)((float)((float)v6 * (float)0.0078431377) - (float)1.0);
          v19 = (float)((float)((float)v11 * (float)0.0078431377) - (float)1.0);
          LODWORD(v16) = &v10[v15];
          v20 = (float)((float)((float)*(__int64 *)((char *)&v6 - 4) * (float)0.0078431377) - (float)1.0);
          _FP2 = (float)((float)((float)((float)((float)v20 * (float)v20) + (float)((float)v18 * (float)v18))
                               + (float)((float)v19 * (float)v19))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f2, f2, f1, f11 }
          v23 = __frsqrte(_FP2);
          v24 = (float)((float)-(float)((float)((float)((float)v23
                                                      * (float)((float)((float)((float)((float)v20 * (float)v20)
                                                                              + (float)((float)v18 * (float)v18))
                                                                      + (float)((float)v19 * (float)v19))
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23);
          v25 = (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)((float)((float)v20 * (float)v20)
                                                                              + (float)((float)v18 * (float)v18))
                                                                      + (float)((float)v19 * (float)v19))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24);
          if ( (float)((float)((float)-(float)((float)((float)((float)v25
                                                             * (float)((float)((float)((float)((float)v20 * (float)v20)
                                                                                     + (float)((float)v18 * (float)v18))
                                                                             + (float)((float)v19 * (float)v19))
                                                                     * (float)0.5))
                                                     * (float)v25)
                                             - (float)1.5)
                             * (float)v25)
                     * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)v18 * (float)v18))
                             + (float)((float)v19 * (float)v19))) < 0.89999998 )
            v20 = __fsqrts((float)((float)((float)1.0 - (float)((float)v18 * (float)v18))
                                 - (float)((float)v19 * (float)v19)));
          LODWORD(v11) = *(unsigned __int8 *)v16;
          LODWORD(v16) = *(unsigned __int8 *)(v16 + 1);
          v26 = (float)((float)((float)((float)v16 * (float)0.0078431377) - (float)1.0) + (float)v19);
          v27 = (float)((float)((float)((float)v11 * (float)0.0078431377) - (float)1.0)
                      + (float)((float)((float)v6 * (float)0.0078431377) - (float)1.0));
          _FP5 = (float)((float)((float)((float)v27 * (float)v27)
                               + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f11, f5, f6, f11 }
          v30 = __frsqrte(_FP11);
          v31 = (float)((float)-(float)((float)((float)((float)v30
                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)v20 * (float)v20)))
                                                              * (float)0.5))
                                              * (float)v30)
                                      - (float)1.5)
                      * (float)v30);
          v32 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                              * (float)v31)
                                                                                      - (float)1.5)
                                                                      * (float)v31)
                                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                                              + (float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)v20 * (float)v20)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                      * (float)v31)
                                                                              - (float)1.5)
                                                              * (float)v31))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v31
                                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v20 * (float)v20)))
                                                                              * (float)0.5))
                                                              * (float)v31)
                                                      - (float)1.5)
                                      * (float)v31))
                      * (float)v27);
          v33 = (float)((float)v26
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                              * (float)v31)
                                                                                      - (float)1.5)
                                                                      * (float)v31)
                                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                                              + (float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)v20 * (float)v20)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                      * (float)v31)
                                                                              - (float)1.5)
                                                              * (float)v31))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v31
                                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v20 * (float)v20)))
                                                                              * (float)0.5))
                                                              * (float)v31)
                                                      - (float)1.5)
                                      * (float)v31)));
          LODWORD(v16) = (int)(float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31) * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v31)
                                                                                            - (float)1.5)
                                                                            * (float)v31))
                                                            * (float)v27)
                                                    + (float)1.0)
                                            * (float)127.5)
                                    + (float)0.5);
          v34 = (float)((float)v20
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                              * (float)v31)
                                                                                      - (float)1.5)
                                                                      * (float)v31)
                                                              * (float)((float)((float)((float)v27 * (float)v27)
                                                                              + (float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)v20 * (float)v20)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v31
                                                                                              * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                      * (float)v31)
                                                                              - (float)1.5)
                                                              * (float)v31))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v31
                                                                      * (float)((float)((float)((float)v27 * (float)v27)
                                                                                      + (float)((float)((float)v26 * (float)v26)
                                                                                              + (float)((float)v20 * (float)v20)))
                                                                              * (float)0.5))
                                                              * (float)v31)
                                                      - (float)1.5)
                                      * (float)v31)));
          if ( (int)(float)((float)((float)((float)v32 + (float)1.0) * (float)127.5) + (float)0.5) >= 0 )
          {
            if ( (int)v16 > 255 )
              LOBYTE(v16) = -1;
          }
          else
          {
            LOBYTE(v16) = 0;
          }
          *(_BYTE *)HIDWORD(v16) = v16;
          LODWORD(v16) = (int)(float)((float)((float)((float)v33 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( (int)v16 >= 0 )
          {
            if ( (int)v16 > 255 )
              LOBYTE(v16) = -1;
          }
          else
          {
            LOBYTE(v16) = 0;
          }
          *(_BYTE *)(HIDWORD(v16) + 1) = v16;
          LODWORD(v16) = (int)(float)((float)((float)((float)v34 + (float)1.0) * (float)127.5) + (float)0.5);
          if ( (int)v16 >= 0 )
          {
            if ( (int)v16 > 255 )
              LOBYTE(v16) = -1;
          }
          else
          {
            LOBYTE(v16) = 0;
          }
          *(_BYTE *)(HIDWORD(v16) + 2) = v16;
          ++v13;
          *(_BYTE *)(HIDWORD(v16) + 3) = -1;
        }
      }
      --v9;
      v12 += width1;
    }
    while ( v9 != 0 );
  }
  if ( HIDWORD(v11) != 0 )
    idMem::Free(this: &mem, ptr: (void *)HIDWORD(v11), align: ALIGN_16);
}


// ========================================================================
// R_SmoothNormalMap
// EA  : 0x828CB388
// RVA : 0x008CB388
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall R_SmoothNormalMap(unsigned __int8 *data, int width, int height)
{
  __int64 v3; // r17
  unsigned int v4; // r28
  char *v8; // r29
  int v9; // r21
  unsigned __int8 *v10; // r20
  int v11; // r7
  int v12; // r28
  int v13; // r31
  unsigned __int8 *v14; // r27
  int v15; // ctr
  double x; // fp13
  double y; // fp12
  double z; // fp11
  __int128 v19; // r11
  float *v20; // r6
  __int64 v21; // fp1
  double v24; // fp5
  double v25; // fp3
  int v26; // r11
  int v27; // r11
  int v28; // r11

  v4 = 4 * width * height;
  v8 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(249) : TAG_IMAGE",
                 size: v4,
                 tag: TAG_IMAGE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v8, Src: data, Size: v4);
  v9 = 0;
  if ( width > 0 )
  {
    v10 = data + 2;
    do
    {
      if ( height > 0 )
      {
        v11 = height - 1;
        v12 = width - 1;
        v13 = 1;
        v14 = v10;
        do
        {
          v15 = 3;
          x = vec3_origin.x;
          y = vec3_origin.y;
          z = vec3_origin.z;
          HIDWORD(v19) = v9 - 1;
          v20 = &factors[0][1];
          do
          {
            DWORD1(v19) = v12 & HIDWORD(v19);
            LODWORD(v19) = &v8[4 * (v11 & (v13 - 2)) * width + 4 * (v12 & HIDWORD(v19))];
            DWORD2(v19) = *(unsigned __int8 *)v19;
            if ( (*(_BYTE *)v19 != 0 || *(_BYTE *)(v19 + 1) != 0 || *(_BYTE *)(v19 + 2) != 0)
              && (DWORD2(v19) != 128 || *(unsigned __int8 *)(v19 + 1) != 128 || *(unsigned __int8 *)(v19 + 2) != 128) )
            {
              LODWORD(v3) = *(unsigned __int8 *)(v19 + 1);
              LODWORD(v19) = *(unsigned __int8 *)(v19 + 2);
              x = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v19 + 4) * (float)0.0078431377)
                                        - (float)1.0)
                                * *(v20 - 1))
                        + (float)x);
              DWORD2(v19) = v19;
              y = (float)((float)((float)((float)((float)v3 * (float)0.0078431377) - (float)1.0) * *(v20 - 1)) + (float)y);
              z = (float)((float)((float)((float)((float)(__int64)v19 * (float)0.0078431377) - (float)1.0) * *(v20 - 1))
                        + (float)z);
            }
            LODWORD(v19) = &v8[4 * (v11 & (v13 - 1)) * width + 4 * DWORD1(v19)];
            DWORD2(v19) = *(unsigned __int8 *)v19;
            if ( (*(_BYTE *)v19 != 0 || *(_BYTE *)(v19 + 1) != 0 || *(_BYTE *)(v19 + 2) != 0)
              && (DWORD2(v19) != 128 || *(unsigned __int8 *)(v19 + 1) != 128 || *(unsigned __int8 *)(v19 + 2) != 128) )
            {
              LODWORD(v3) = *(unsigned __int8 *)(v19 + 2);
              LODWORD(v19) = *(unsigned __int8 *)(v19 + 1);
              v21 = *(_QWORD *)((char *)&v19 + 4);
              DWORD2(v19) = v19;
              y = (float)((float)((float)((float)((float)(__int64)v19 * (float)0.0078431377) - (float)1.0) * *v20)
                        + (float)y);
              z = (float)((float)((float)((float)((float)v3 * (float)0.0078431377) - (float)1.0) * *v20) + (float)z);
              x = (float)((float)((float)((float)((float)v21 * (float)0.0078431377) - (float)1.0) * *v20) + (float)x);
            }
            LODWORD(v19) = &v8[4 * (v11 & v13) * width + 4 * DWORD1(v19)];
            DWORD2(v19) = *(unsigned __int8 *)v19;
            if ( (*(_BYTE *)v19 != 0 || *(_BYTE *)(v19 + 1) != 0 || *(_BYTE *)(v19 + 2) != 0)
              && (DWORD2(v19) != 128 || *(unsigned __int8 *)(v19 + 1) != 128 || *(unsigned __int8 *)(v19 + 2) != 128) )
            {
              DWORD1(v19) = *(unsigned __int8 *)(v19 + 1);
              LODWORD(v19) = *(unsigned __int8 *)(v19 + 2);
              z = (float)((float)((float)((float)((float)(__int64)v19 * (float)0.0078431377) - (float)1.0) * v20[1])
                        + (float)z);
              x = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v19 + 4) * (float)0.0078431377)
                                        - (float)1.0)
                                * v20[1])
                        + (float)x);
              y = (float)((float)((float)((float)((float)*(__int64 *)&v19 * (float)0.0078431377) - (float)1.0) * v20[1])
                        + (float)y);
            }
            ++HIDWORD(v19);
            v20 += 3;
            --v15;
          }
          while ( v15 != 0 );
          _FP2 = (float)((float)((float)((float)x * (float)x)
                               + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f9, f2, f3, f9 }
          v24 = __frsqrte(_FP9);
          v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5))
                                                                                      * (float)v24)
                                                                              - (float)1.5)
                                                              * (float)v24)
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)((float)y * (float)y)
                                                                              + (float)((float)z * (float)z)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v24
                                                                                      * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z)))
                                                                                              * (float)0.5))
                                                                              * (float)v24)
                                                                      - (float)1.5)
                                                      * (float)v24))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v24
                                                              * (float)((float)((float)((float)x * (float)x)
                                                                              + (float)((float)((float)y * (float)y)
                                                                                      + (float)((float)z * (float)z)))
                                                                      * (float)0.5))
                                                      * (float)v24)
                                              - (float)1.5)
                              * (float)v24));
          v26 = (int)(float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24) * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24))
                                                                                           * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5))
                                                                                   * (float)v25)
                                                                           - (float)1.5)
                                                           * (float)v25)
                                                   * (float)x)
                                           + (float)1.0)
                                   * (float)127.5)
                           + (float)0.5);
          if ( v26 >= 0 )
          {
            if ( v26 > 255 )
              LOBYTE(v26) = -1;
          }
          else
          {
            LOBYTE(v26) = 0;
          }
          *(v14 - 2) = v26;
          v27 = (int)(float)((float)((float)((float)((float)y
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24) * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24))
                                                                                           * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5))
                                                                                   * (float)v25)
                                                                           - (float)1.5)
                                                           * (float)v25))
                                           + (float)1.0)
                                   * (float)127.5)
                           + (float)0.5);
          if ( v27 >= 0 )
          {
            if ( v27 > 255 )
              LOBYTE(v27) = -1;
          }
          else
          {
            LOBYTE(v27) = 0;
          }
          *(v14 - 1) = v27;
          v28 = (int)(float)((float)((float)((float)((float)z
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24) * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)) - (float)1.5) * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24))
                                                                                           * (float)((float)((float)((float)x * (float)x) + (float)((float)((float)y * (float)y) + (float)((float)z * (float)z))) * (float)0.5))
                                                                                   * (float)v25)
                                                                           - (float)1.5)
                                                           * (float)v25))
                                           + (float)1.0)
                                   * (float)127.5)
                           + (float)0.5);
          if ( v28 >= 0 )
          {
            if ( v28 > 255 )
              LOBYTE(v28) = -1;
          }
          else
          {
            LOBYTE(v28) = 0;
          }
          ++v13;
          *v14 = v28;
          v14 += 4 * width;
        }
        while ( v13 - 1 < height );
      }
      ++v9;
      v10 += 4;
    }
    while ( v9 < width );
  }
  idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
}


// ========================================================================
// ?Copy@idImageByteArray@@QAAXABV1@HH@Z
// EA  : 0x828CB800
// RVA : 0x008CB800
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall idImageByteArray::Copy(idImageByteArray *this, const idImageByteArray *src, int xDst, int yDst)
{
  int width; // r8
  int v6; // r11
  int height; // r28
  int v9; // r31
  int v10; // r27
  size_t v11; // r26

  width = this->width;
  v6 = src->width;
  if ( v6 >= width - xDst )
    v6 = width - xDst;
  height = this->height - yDst;
  if ( src->height < height )
    height = src->height;
  v9 = 0;
  v10 = 4 * (width * yDst + xDst);
  if ( height > 0 )
  {
    v11 = 4 * v6;
    do
    {
      memcpy(Dst: &this->data[4 * v9 * this->width + v10], Src: &src->data[4 * v9 * src->width], Size: v11);
      ++v9;
    }
    while ( v9 < height );
  }
}


// ========================================================================
// ?R_AtlasBorder@@YAPAEPAEPAH1HH@Z
// EA  : 0x828CB8A8
// RVA : 0x008CB8A8
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

unsigned __int8 *__fastcall R_AtlasBorder(unsigned __int8 *pic, int *width, int *height, int maxWidth, int maxHeight)
{
  int v7; // r11
  int v9; // r30
  int v10; // r11
  int v11; // r8
  int v12; // r11
  int v13; // r29
  int v14; // r11
  int v15; // r10
  int v16; // r28
  int v17; // r27
  unsigned __int8 *v18; // r3
  int v19; // r11
  int v20; // r10
  unsigned __int8 *v21; // r25
  int v22; // r31
  int v23; // r29
  idImageByteArray v25; // [sp+50h] [-80h] BYREF
  idImageByteArray v26; // [sp+60h] [-70h] BYREF

  v7 = maxWidth - *width;
  if ( v7 >= 4 )
  {
    v9 = 4;
  }
  else
  {
    v9 = maxWidth - *width;
    if ( v7 < 0 )
      v9 = 0;
  }
  v10 = v7 - v9;
  if ( v10 < 4 )
  {
    v11 = 0;
    if ( v10 < 0 )
      goto LABEL_9;
  }
  else
  {
    v10 = 4;
  }
  v11 = v10;
LABEL_9:
  v12 = maxHeight - *height;
  if ( v12 >= 4 )
  {
    v13 = 4;
  }
  else
  {
    v13 = maxHeight - *height;
    if ( v12 < 0 )
      v13 = 0;
  }
  v14 = v12 - v13;
  if ( v14 >= 4 )
  {
    v15 = 4;
  }
  else
  {
    v15 = v14;
    if ( v14 < 0 )
      v15 = 0;
  }
  v16 = *width + v11 + v9;
  v17 = *height + v15 + v13;
  v18 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(394) : TAG_IMAGE",
                             size: 4 * v17 * v16,
                             tag: TAG_IMAGE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v19 = *width;
  v20 = *height;
  v21 = v18;
  v25.data = v18;
  v26.data = pic;
  v25.width = v16;
  v26.width = v19;
  v26.height = v20;
  v25.height = v17;
  idImageByteArray::Copy(this: &v25, src: &v26, xDst: v9, yDst: v13);
  v22 = 0;
  v23 = v13 - v9;
  do
  {
    idImageByteArray::Extrude(this: &v25, x: v9, y: v23 + v9, w: *width + v22, h: *height + v22);
    v22 += 2;
    --v9;
  }
  while ( v22 < 8 );
  idMem::Free(this: &mem, ptr: pic, align: ALIGN_16);
  *width = v16;
  *height = v17;
  return v21;
}


// ========================================================================
// ?R_Resize@@YAPAEPAEHHHH@Z
// EA  : 0x828CBA30
// RVA : 0x008CBA30
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

unsigned __int8 *__fastcall R_Resize(unsigned __int8 *pic, int srcWidth, int srcHeight, int newWidth, int newHeight)
{
  char v8; // r11
  char v9; // r11
  int v10; // r30
  int v11; // r31
  unsigned __int8 *v12; // r29
  char v13; // r11
  char v14; // r11
  int v15; // r8
  int v16; // r10
  int v17; // r9
  int v18; // r10
  int v19; // r27
  int v20; // r28
  char *v21; // r31
  unsigned __int8 *v22; // r28

  if ( ((newWidth - 1) & newWidth) != 0 || (v8 = 1, newWidth <= 0) )
    v8 = 0;
  if ( v8 == 0 )
    goto _LN50_3;
  if ( ((newHeight - 1) & newHeight) != 0 || (v9 = 1, newHeight <= 0) )
    v9 = 0;
  if ( v9 == 0 )
  {
_LN50_3:
    idLib::Error(fmt: "R_Resize: target size %dx%d is not a power of two (code error)", newWidth, newHeight);
    JUMPOUT(0x828CBC74);
  }
  if ( srcWidth < newWidth || srcHeight < newHeight )
  {
    idLib::Error(fmt: "R_Resize: up sampling not implemented in");
    goto _LN50_3;
  }
  v10 = srcWidth;
  v11 = srcHeight;
  v12 = pic;
  if ( ((srcWidth - 1) & srcWidth) != 0 || (v13 = 1, srcWidth <= 0) )
    v13 = 0;
  if ( v13 == 0 )
    goto LABEL_19;
  if ( ((srcHeight - 1) & srcHeight) != 0 || (v14 = 1, srcHeight <= 0) )
    v14 = 0;
  if ( v14 == 0 )
  {
LABEL_19:
    v15 = (((srcWidth >> 1) | srcWidth) >> 2) | (srcWidth >> 1) | srcWidth;
    v16 = (((v15 >> 4) | v15) >> 8) | (v15 >> 4) | v15;
    v10 = (((v16 >> 16) | v16) + 1) >> 1;
    v17 = (((srcHeight >> 1) | srcHeight) >> 2) | (srcHeight >> 1) | srcHeight;
    v18 = (((v17 >> 4) | v17) >> 8) | (v17 >> 4) | v17;
    v11 = (((v18 >> 16) | v18) + 1) >> 1;
    v12 = (unsigned __int8 *)R_ResampleTexture(
                               in: pic,
                               inwidth: srcWidth,
                               inheight: srcHeight,
                               outwidth: v10,
                               outheight: v11);
    idMem::Free(this: &mem, ptr: pic, align: ALIGN_16);
  }
  while ( v10 != newWidth )
  {
    if ( v11 == newHeight )
    {
LABEL_22:
      v19 = v10 >> 1;
      if ( newWidth > v10 >> 1 )
        v19 = newWidth;
      v20 = v11 >> 1;
      if ( newHeight > v11 >> 1 )
        v20 = newHeight;
      v21 = R_ResampleTexture(in: v12, inwidth: v10, inheight: v11, outwidth: v19, outheight: v20);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      v12 = (unsigned __int8 *)v21;
      v10 = v19;
      v11 = v20;
    }
    else
    {
      v22 = R_MipMap(in: v12, width: v10, height: v11);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      v10 >>= 1;
      v11 >>= 1;
      v12 = v22;
    }
  }
  if ( v11 != newHeight )
    goto LABEL_22;
  return v12;
}


// ========================================================================
// ?R_ImageCompileWrinkleMask@@YAPAEAAH0AAV?$idList@PAE$04@@@Z
// EA  : 0x828CBC78
// RVA : 0x008CBC78
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

unsigned __int8 *__fastcall R_ImageCompileWrinkleMask(
        int *argWidth,
        int *argHeight,
        idList<unsigned char *,5> *picList)
{
  int v3; // r31
  int v5; // r18
  int v6; // r19
  int num; // r11
  unsigned __int8 *result; // r3
  int v9; // r27
  int v10; // r25
  int v11; // r23
  unsigned __int8 *v12; // r21
  unsigned __int8 *v13; // r22
  int v14; // r26
  int v15; // r6
  unsigned __int8 *v16; // r4
  unsigned __int8 *v17; // r30
  int v18; // r28
  int v19; // r29
  unsigned __int8 **list; // r7
  int v21; // r8
  unsigned int v22; // ctr
  int v23; // r11
  unsigned __int8 *v24; // r10
  unsigned __int8 *v25; // r9
  int v26; // r5
  int v27; // r9
  int v28; // r10
  char v29; // r10
  char v30; // r9
  char v31; // r8
  char v32; // r7
  char v33; // r5
  char v34; // r3
  char v35; // r11
  unsigned __int8 v36; // [sp+50h] [-C0h]
  int v37; // [sp+54h] [-BCh]
  unsigned __int8 *v38; // [sp+58h] [-B8h]
  char v39; // [sp+60h] [-B0h] BYREF
  char v40; // [sp+61h] [-AFh] BYREF
  char v41; // [sp+62h] [-AEh] BYREF
  char v42; // [sp+63h] [-ADh]
  char v43; // [sp+64h] [-ACh]
  char v44; // [sp+65h] [-ABh]
  char v45; // [sp+66h] [-AAh]
  char v46; // [sp+67h] [-A9h]
  char v47; // [sp+68h] [-A8h]

  v3 = *argWidth;
  v5 = *argHeight;
  v6 = 2 * *argWidth;
  *argWidth = v6;
  num = picList->num;
  if ( num == 0 )
    return nullptr;
  v9 = picList->num;
  if ( num >= 6 )
    v9 = 6;
  result = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(490) : TAG_IMAGE",
                                size: 4 * v6 * v5,
                                tag: TAG_IMAGE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v38 = result;
  if ( v3 > 0 )
  {
    v10 = 4 * v3;
    v37 = v3;
    v11 = 0;
    v12 = result + 2;
    v13 = &result[4 * v3 + 2];
    do
    {
      if ( v5 > 0 )
      {
        v14 = 4 * v6;
        v15 = v11;
        v16 = &v12[v11];
        v17 = v13;
        v18 = v5;
        do
        {
          v39 = 127;
          v19 = 0;
          v40 = 127;
          v47 = 127;
          v41 = 127;
          v42 = 127;
          v43 = 127;
          v44 = 127;
          v45 = 127;
          v46 = 127;
          if ( v9 > 0 )
          {
            list = picList->list;
            v21 = 0;
            v22 = ((unsigned int)(v9 - 1) >> 1) + 1;
            do
            {
              v23 = 3 * (v19 >> 1);
              v24 = &list[v21][v15];
              if ( v19 + 1 >= v9 )
              {
                v26 = *v24 >> 1;
                v27 = v24[1] >> 1;
                v28 = v24[2] >> 1;
              }
              else
              {
                v25 = &list[v21 + 1][v15];
                v26 = (*v24 >> 1) - (*v25 >> 1);
                v36 = v25[2] >> 1;
                v27 = (v24[1] >> 1) - (v25[1] >> 1);
                v28 = (v24[2] >> 1) - v36;
              }
              *(&v41 + v23) = v28 + 127;
              *(&v40 + v23) = v27 + 127;
              v19 += 2;
              *(&v39 + v23) = v26 + 127;
              v21 += 2;
              --v22;
            }
            while ( v22 != 0 );
          }
          --v18;
          v29 = v43;
          v15 += v10;
          v30 = v40;
          v31 = v44;
          v32 = v41;
          v33 = v45;
          *(v16 - 2) = v39;
          v34 = v42;
          v35 = v46;
          *(v17 - 2) = v29;
          *(v16 - 1) = v30;
          *(v17 - 1) = v31;
          *v16 = v32;
          *v17 = v33;
          v16[1] = v34;
          v16 += v14;
          v17[1] = v35;
          v17 += v14;
        }
        while ( v18 != 0 );
        result = v38;
        v3 = v37;
      }
      --v3;
      v11 += 4;
      v37 = v3;
      v13 += 4;
    }
    while ( v3 != 0 );
  }
  return result;
}


// ========================================================================
// ?R_ImageShuffle@@YAPAEQAH0QAEAAH2AAV?$idList@PAE$04@@@Z
// EA  : 0x828CBEB0
// RVA : 0x008CBEB0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

unsigned __int8 *__fastcall R_ImageShuffle(
        char *srcIndexList,
        char *srcChannelList,
        unsigned __int8 *srcConst,
        int *argWidth,
        int *argHeight,
        idList<unsigned char *,5> *picList)
{
  int v7; // r26
  int v9; // r25
  unsigned __int8 *result; // r3
  unsigned __int8 *v13; // r27
  int i; // r22
  unsigned __int8 *v15; // r7
  int v16; // r30
  int v17; // r9
  char *v18; // r8
  int j; // ctr
  unsigned __int8 v20; // r10
  unsigned __int8 v21; // r9
  unsigned __int8 v22; // r8
  _BYTE v23[112]; // [sp+50h] [-70h] BYREF

  v7 = *argWidth;
  v9 = *argHeight;
  if ( picList->num <= 0 )
    result = (unsigned __int8 *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(545) : TAG_IMAGE",
                                  size: 4 * v9 * v7,
                                  tag: TAG_IMAGE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  else
    result = *picList->list;
  if ( v7 > 0 )
  {
    v13 = result + 2;
    for ( i = v7; i != 0; --i )
    {
      if ( v9 > 0 )
      {
        v15 = v13;
        v16 = v9;
        do
        {
          v17 = 0;
          v18 = srcIndexList;
          for ( j = 4; j != 0; --j )
          {
            if ( *(int *)v18 < 0 )
              v23[v17] = v23[v17 + srcConst - v23];
            else
              v23[v17] = picList->list[*(_DWORD *)v18][*(_DWORD *)&v18[srcChannelList - srcIndexList]
                                                     + -2
                                                     - (_DWORD)result
                                                     + (unsigned int)v15];
            ++v17;
            v18 += 4;
          }
          --v16;
          v20 = v23[1];
          v21 = v23[2];
          v22 = v23[3];
          *(v15 - 2) = v23[0];
          *(v15 - 1) = v20;
          *v15 = v21;
          v15[1] = v22;
          v15 += 4 * v7;
        }
        while ( v16 != 0 );
      }
      v13 += 4;
    }
  }
  return result;
}


// ========================================================================
// R_OutlineAlpha
// EA  : 0x828CBFF0
// RVA : 0x008CBFF0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall R_OutlineAlpha(unsigned __int8 *data, int width, int height, unsigned __int8 *alphaData, int count)
{
  idMem *v5; // r29
  unsigned int v6; // r17
  void *v12; // r28
  void *v13; // r30
  __int64 v14; // r14 OVERLAPPED
  int v15; // r26
  int v16; // r19
  int v17; // r21
  int v18; // r7
  int v19; // r5
  int v20; // r27
  _BYTE v21[12]; // r11
  int v22; // r8
  int v23; // ctr
  double w; // fp11
  double z; // fp12
  double y; // fp13
  double x; // fp0
  int v28; // r3
  int v29; // r6
  __int64 v30; // r16
  __int128 v31; // r16
  double v32; // fp4
  __int64 v33; // r16
  double v34; // fp4
  double v35; // fp10
  double v36; // fp0
  void *v37[2]; // [sp+60h] [-130h] BYREF
  idMem *v38; // [sp+68h] [-128h]
  int v40; // [sp+74h] [-11Ch]
  __int64 v41; // [sp+78h] [-118h]
  __int64 v42; // [sp+80h] [-110h]
  __int64 v43; // [sp+88h] [-108h]
  __int64 v44; // [sp+90h] [-100h]
  __int64 v45; // [sp+98h] [-F8h]
  __int64 v46; // [sp+A0h] [-F0h]
  __int64 v47; // [sp+A8h] [-E8h]
  __int64 v48; // [sp+B0h] [-E0h]
  int v50; // [sp+BCh] [-D4h]
  __int64 v51; // [sp+C0h] [-D0h]
  __int64 v52; // [sp+C8h] [-C8h]
  __int64 v53; // [sp+D0h] [-C0h]
  int v55; // [sp+DCh] [-B4h]
  __int64 v56; // [sp+E0h] [-B0h]
  __int64 v57; // [sp+E8h] [-A8h]

  v5 = &mem;
  v6 = 4 * width * height;
  v38 = &mem;
  v37[0] = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(636) : TAG_IMAGE",
             size: v6,
             tag: TAG_IMAGE,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
  v12 = v37[0];
  memcpy(Dst: v37[0], Src: alphaData, Size: v6);
  v37[1] = alphaData;
  v13 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(642) : TAG_IMAGE",
          size: v6,
          tag: TAG_IMAGE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( count != 0 )
  {
    do
    {
      --count;
      memcpy(Dst: v13, Src: data, Size: v6);
      v15 = 0;
      v16 = *(int *)((char *)v37 + ((4 * count) & 4));
      v17 = *(int *)((char *)v37 + ((4 * ~count) & 4));
      if ( width > 0 )
      {
        do
        {
          if ( height > 0 )
          {
            v18 = v16 + 3;
            v19 = 1;
            v20 = 4 * v15;
            do
            {
              if ( *(_BYTE *)(v20 + v18) == 0 )
              {
                *(_DWORD *)v21 = height - 1;
                v22 = 0;
                v23 = 3;
                w = vec4_origin.w;
                z = vec4_origin.z;
                y = vec4_origin.y;
                x = vec4_origin.x;
                v28 = width - 1;
                v29 = v15 - 1;
                do
                {
                  *(_DWORD *)&v21[4] = v29 & v28;
                  *(_DWORD *)&v21[8] = 4 * (((v19 - 2) & *(_DWORD *)v21) * width + (v29 & v28));
                  if ( *(_BYTE *)(v18 + *(_DWORD *)&v21[8]) != 0 )
                  {
                    HIDWORD(v30) = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8]);
                    *(_DWORD *)&v21[8] += v13;
                    ++v22;
                    LODWORD(v30) = *(unsigned __int8 *)(*(_DWORD *)&v21[8] + 2);
                    LODWORD(v14) = *(unsigned __int8 *)(*(_DWORD *)&v21[8] + 3);
                    *(_DWORD *)&v21[8] = *(unsigned __int8 *)(*(_DWORD *)&v21[8] + 1);
                    v53 = *(__int64 *)((char *)&v14 - 4);
                    v52 = v14;
                    v57 = *(_QWORD *)&v21[4];
                    v56 = v30;
                    x = (float)((float)*(__int64 *)((char *)&v14 - 4) + (float)x);
                    z = (float)((float)v30 + (float)z);
                    y = (float)((float)*(__int64 *)&v21[4] + (float)y);
                    w = (float)((float)v14 + (float)w);
                  }
                  *(_DWORD *)&v21[8] = 4 * (((v19 - 1) & *(_DWORD *)v21) * width + *(_DWORD *)&v21[4]);
                  if ( *(_BYTE *)(v18 + *(_DWORD *)&v21[8]) != 0 )
                  {
                    DWORD2(v31) = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8]);
                    DWORD1(v31) = (char *)v13 + *(_DWORD *)&v21[8];
                    ++v22;
                    v46 = *(_QWORD *)((char *)&v31 + 4);
                    v32 = (double)*(__int64 *)((char *)&v31 + 4);
                    DWORD2(v31) = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8] + 1);
                    v41 = *(_QWORD *)((char *)&v31 + 4);
                    LODWORD(v31) = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8] + 2);
                    *(_DWORD *)&v21[8] = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8] + 3);
                    v51 = *(_QWORD *)&v21[4];
                    v44 = v31;
                    z = (float)((float)(__int64)v31 + (float)z);
                    x = (float)((float)v32 + (float)x);
                    y = (float)((float)*(__int64 *)((char *)&v31 + 4) + (float)y);
                    w = (float)((float)*(__int64 *)&v21[4] + (float)w);
                  }
                  *(_DWORD *)&v21[8] = 4 * ((v19 & (height - 1)) * width + *(_DWORD *)&v21[4]);
                  *(_DWORD *)&v21[4] = *(unsigned __int8 *)(v18 + *(_DWORD *)&v21[8]);
                  if ( *(_BYTE *)(v18 + *(_DWORD *)&v21[8]) != 0 )
                  {
                    LODWORD(v33) = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8]);
                    HIDWORD(v33) = (char *)v13 + *(_DWORD *)&v21[8];
                    ++v22;
                    *(_DWORD *)&v21[4] = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8] + 3);
                    v43 = v33;
                    *(_DWORD *)&v21[8] = *((unsigned __int8 *)v13 + *(_DWORD *)&v21[8] + 1);
                    v34 = (double)v33;
                    v42 = *(_QWORD *)&v21[4];
                    v48 = *(_QWORD *)v21;
                    LODWORD(v33) = *(unsigned __int8 *)(HIDWORD(v33) + 2);
                    v45 = v33;
                    x = (float)((float)v34 + (float)x);
                    z = (float)((float)v33 + (float)z);
                    y = (float)((float)*(__int64 *)&v21[4] + (float)y);
                    w = (float)((float)*(__int64 *)v21 + (float)w);
                    *(_DWORD *)&v21[4] = *(_DWORD *)&v21[8];
                  }
                  ++v29;
                  --v23;
                }
                while ( v23 != 0 );
                if ( v22 != 0 )
                {
                  *(_DWORD *)&v21[8] = v22;
                  v47 = *(_QWORD *)&v21[4];
                  v35 = (float)((float)x * (float)((float)1.0 / (float)*(__int64 *)&v21[4]));
                  v36 = (float)((float)((float)1.0 / (float)*(__int64 *)&v21[4]) * (float)y);
                  v50 = (int)(float)((float)w * (float)((float)1.0 / (float)*(__int64 *)&v21[4]));
                  v55 = (int)v36;
                  v40 = (int)(float)((float)z * (float)((float)1.0 / (float)*(__int64 *)&v21[4]));
                  data[v20 + 3] = v50;
                  data[v20 + 1] = (int)v36;
                  data[v20 + 2] = v40;
                  data[v20] = (int)v35;
                  *(_BYTE *)(v20 + v17 + 3) = -1;
                }
              }
              ++v19;
              v20 += 4 * width;
            }
            while ( v19 - 1 < height );
          }
          ++v15;
        }
        while ( v15 < width );
        v5 = v38;
      }
    }
    while ( count != 0 );
    v12 = v37[0];
  }
  idMem::Free(this: v5, ptr: v12, align: ALIGN_16);
  idMem::Free(this: v5, ptr: v13, align: ALIGN_16);
}


// ========================================================================
// AppendToken
// EA  : 0x828CC420
// RVA : 0x008CC420
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall AppendToken(idToken *token)
{
  int v2; // r11
  char *v3; // r10

  v2 = 0;
  if ( parseBuffer[0] != 0 )
  {
    v3 = parseBuffer;
    do
    {
      ++v3;
      ++v2;
    }
    while ( *v3 != 0 );
  }
  if ( token->len + v2 + 1 < 1024 )
  {
    if ( parseBuffer[0] != 0 )
      idStr::Append(dest: parseBuffer, size: 1024, src: " ");
    idStr::Append(dest: parseBuffer, size: 1024, src: token->data);
  }
  else if ( !parseBufferError )
  {
    idLib::Warning(
      fmt: "image program: token \"%s\" can't be appended to \"%s\", length > MAX_IMAGE_NAME(%d)",
      token->data,
      parseBuffer,
      1024);
    parseBufferError = true;
  }
}


// ========================================================================
// MatchAndAppendToken
// EA  : 0x828CC4F0
// RVA : 0x008CC4F0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void __fastcall MatchAndAppendToken(idParser *src, const char *match)
{
  int v3; // r9
  char *v4; // r11
  int v5; // r11

  if ( idParser::ExpectTokenString(this: src, string: match) )
  {
    v3 = 0;
    if ( parseBuffer[0] != 0 )
    {
      v4 = parseBuffer;
      do
      {
        ++v4;
        ++v3;
      }
      while ( *v4 != 0 );
    }
    v5 = 0;
    if ( *match != 0 )
    {
      do
        ++v5;
      while ( match[v5] != 0 );
    }
    if ( v5 + v3 + 1 < 1024 )
    {
      idStr::Append(dest: parseBuffer, size: 1024, src: match);
    }
    else if ( !parseBufferError )
    {
      idLib::Warning(
        fmt: "image program: token \"%s\" can't be appended to \"%s\", length > MAX_IMAGE_NAME(%d)",
        match,
        parseBuffer,
        1024);
      parseBufferError = true;
    }
  }
}


// ========================================================================
// ParseIntAndAppendToken
// EA  : 0x828CC5D8
// RVA : 0x008CC5D8
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

unsigned int __fastcall ParseIntAndAppendToken(idParser *src)
{
  unsigned int UnsignedIntValue; // r30
  idToken v4; // [sp+50h] [-60h] BYREF

  v4.len = 0;
  v4.allocedAndFlag = 20;
  v4.data = v4.baseBuffer;
  v4.floatvalue = -3.4028235e38;
  v4.baseBuffer[0] = 0;
  v4.intvalue = 0;
  memset(&v4.whiteSpaceStart_p, 0, 12);
  if ( idParser::ReadToken(this: src, token: &v4) )
  {
    AppendToken(token: &v4);
    if ( v4.type != 5 || idStr::Cmp(s1: v4.data, s2: "-") != 0 )
    {
      if ( v4.type != 3 || v4.subtype == 128 )
        idParser::Error(this: src, str: "expected integer value, found '%s'", v4.data);
      UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v4);
    }
    else
    {
      idParser::ExpectTokenType(this: src, type: 3, subtype: 1, token: &v4);
      AppendToken(token: &v4);
      UnsignedIntValue = -idToken::GetUnsignedIntValue(this: &v4);
    }
    idStr::FreeData(this: &v4);
    return UnsignedIntValue;
  }
  else
  {
    idParser::Error(this: src, str: "couldn't read expected integer");
    idStr::FreeData(this: &v4);
    return 0;
  }
}


// ========================================================================
// __unwind$222196
// EA  : 0x828CC714
// RVA : 0x008CC714
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222196()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// R_ParseImageProgram_r
// EA  : 0x828CC7C0
// RVA : 0x008CC7C0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall R_ParseImageProgram_r(
        idParser *src,
        unsigned __int8 **pic,
        int *width,
        int *height,
        unsigned int *timestamps,
        const char *imgNameBase)
{
  unsigned __int8 v6; // r25
  double FloatValue; // fp1
  __int64 v14; // r6
  __int64 v15; // r4 OVERLAPPED
  int v16; // r2 OVERLAPPED
  int v17; // r11
  int v18; // r6
  unsigned __int8 *v19; // r9
  char v20; // r10
  unsigned __int8 *v21; // r9
  int v22; // r3
  char v23; // r10
  __int64 v24; // r10
  unsigned __int8 *v25; // r9
  char v26; // r10
  int v27; // ctr
  unsigned __int8 *v28; // r9
  char num; // r10
  int v30; // r28
  unsigned __int8 *v31; // r8
  int v32; // r29
  unsigned __int8 *v33; // r30
  unsigned __int8 *v34; // r4
  int v35; // r7
  int v36; // r10
  int i; // ctr
  int v38; // r11
  unsigned __int8 v39; // r5
  int v40; // r29
  unsigned __int8 *v41; // r10
  int v42; // r28
  unsigned __int8 *v43; // r30
  unsigned __int8 *v44; // r4
  char *v45; // r11
  int v46; // ctr
  int v47; // r8
  char v48; // r10
  int j; // r28
  char v50; // r11
  unsigned __int8 *v51; // r3
  unsigned __int8 v52; // r9
  int v53; // r11
  unsigned __int8 v54; // r8
  unsigned __int8 v55; // r7
  unsigned __int8 v56; // r6
  int k; // ctr
  unsigned __int8 *v58; // r3
  int v59; // r29
  float *v60; // r28
  __int64 v61; // r8
  idParser *v62; // r3
  bool v63; // zf
  int UnsignedIntValue; // r7
  _BYTE *v66; // r8
  int v67; // r7
  int v68; // r6
  int v69; // r10
  unsigned __int8 *v70; // r9
  int v71; // r7
  unsigned int v72; // ctr
  int v73; // r11
  unsigned __int8 *v74; // r10
  int v75; // r9
  unsigned __int8 *v76; // r9
  unsigned int v77; // r7
  unsigned __int8 *v78; // r8
  unsigned int v79; // ctr
  unsigned __int8 v80; // r5
  unsigned __int8 v81; // r4
  int v82; // r11
  int v83; // r10
  unsigned int v84; // ctr
  unsigned __int8 *v85; // r10
  int v86; // r11
  int v87; // r10
  unsigned int v88; // ctr
  int v89; // r11
  int v90; // r10
  unsigned int v91; // ctr
  unsigned __int8 *v92; // r6
  int appended; // r28
  int v94; // r29
  bool v95; // cr56
  int v96; // r8
  unsigned int v97; // r7
  int v98; // r8
  char v99; // r11
  char v100; // r11
  int v101; // r29
  int v102; // r7
  int v103; // r21
  unsigned int v104; // r27
  idDeclAF_Constraint **v105; // r3
  __int64 v106; // r8
  unsigned __int8 **v107; // r29
  __int64 v108; // r10
  int *v109; // r17
  va *v110; // r3
  bool v111; // r28
  int v112; // r29
  int v113; // r10
  void **v114; // r30
  unsigned __int8 *v115; // r3
  void **v116; // r30
  int v117; // r27
  int v118; // r21
  int m; // r28
  double v120; // fp1
  int v121; // r10
  int v122; // r5
  int v123; // r5
  unsigned __int8 **v124; // r3
  bool v125; // r28
  int v126; // r27
  int v127; // r10
  void **list; // r30
  int n; // r29
  unsigned __int8 *v130; // r3
  int v131; // r29
  void **v132; // r30
  __int64 v133; // r10
  __int64 v134; // r8
  va *v135; // r3
  int v136; // r28
  int v137; // r27
  int v138; // r8
  int v139; // r7
  int v140; // r10
  int ii; // ctr
  int v142; // r11
  unsigned __int8 v143; // r6
  unsigned __int8 *v144; // r3
  unsigned __int8 *v145; // r3
  const char *v146; // r4
  unsigned __int8 *v147; // r3
  unsigned int v148; // r11
  __int64 v149; // r10
  __int64 v150; // r8
  va *v151; // r3
  int v152; // [sp+8h] [-1288h]
  int v153; // [sp+Ch] [-1284h]
  int v154; // [sp+10h] [-1280h]
  int v155; // [sp+14h] [-127Ch]
  int v156; // [sp+18h] [-1278h]
  int v157; // [sp+1Ch] [-1274h]
  unsigned __int8 *v158; // [sp+50h] [-1240h] BYREF
  int v159; // [sp+54h] [-123Ch] BYREF
  unsigned int v160; // [sp+58h] [-1238h] BYREF
  unsigned int v161; // [sp+5Ch] [-1234h] BYREF
  int v162; // [sp+60h] [-1230h] BYREF
  int v163; // [sp+64h] [-122Ch]
  idToken v164; // [sp+70h] [-1220h] BYREF
  __int64 v165; // [sp+B8h] [-11D8h] BYREF
  idList<idDeclAF_Constraint *,71> v166; // [sp+C0h] [-11D0h] BYREF
  _QWORD v167[2]; // [sp+D0h] [-11C0h] BYREF
  idList<idDeclAF_Constraint *,71> v168; // [sp+E0h] [-11B0h] BYREF
  idStr v169; // [sp+F0h] [-11A0h] BYREF
  int v170; // [sp+124h] [-116Ch]
  float v171; // [sp+128h] [-1168h]
  int v172; // [sp+12Ch] [-1164h]
  int v173; // [sp+130h] [-1160h]
  int v174; // [sp+134h] [-115Ch]
  char v175[16]; // [sp+140h] [-1150h] BYREF
  idStr v176; // [sp+150h] [-1140h] BYREF
  int v177; // [sp+184h] [-110Ch]
  float v178; // [sp+188h] [-1108h]
  int v179; // [sp+18Ch] [-1104h]
  int v180; // [sp+190h] [-1100h]
  int v181; // [sp+194h] [-10FCh]
  idStr v182; // [sp+1A0h] [-10F0h] BYREF
  idStr v183; // [sp+1C0h] [-10D0h] BYREF
  char v184[16]; // [sp+1E0h] [-10B0h] BYREF
  va v185; // [sp+1F0h] [-10A0h] BYREF

  v6 = 0;
  v158 = nullptr;
  v164.allocedAndFlag = 20;
  v164.floatvalue = -3.4028235e38;
  v164.data = v164.baseBuffer;
  v164.len = 0;
  v164.baseBuffer[0] = 0;
  v164.intvalue = 0;
  memset(&v164.whiteSpaceStart_p, 0, 12);
  idParser::ReadToken(this: src, token: &v164);
  AppendToken(token: &v164);
  if ( idStr::Icmp(s1: v164.data, s2: "heightmap") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    idParser::ReadToken(this: src, token: &v164);
    AppendToken(token: &v164);
    FloatValue = idToken::GetFloatValue(this: &v164);
    if ( pic != nullptr )
      R_HeightmapToNormalMap(data: *pic, width: *width, height: *height, scale: FloatValue);
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "addnormals") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    v158 = nullptr;
    v159 = 0;
    v160 = 0;
    if ( !R_ParseImageProgram_r(
            src,
            pic: pic == nullptr ? nullptr : &v158,
            width: width == nullptr ? nullptr : &v159,
            height: height == nullptr ? nullptr : (int *)&v160,
            timestamps,
            imgNameBase) )
    {
      if ( pic != nullptr )
      {
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
      }
      goto LABEL_231;
    }
    if ( pic != nullptr )
    {
      R_AddNormalMaps(data1: *pic, width1: *width, height1: *height, data2: v158, width2: v159, height2: v160);
      idMem::Free(this: &mem, ptr: v158, align: ALIGN_16);
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "multiplyImages") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    v158 = nullptr;
    v159 = 0;
    v160 = 0;
    HIDWORD(v15) = R_ParseImageProgram_r(
                     src,
                     pic: pic == nullptr ? nullptr : &v158,
                     width: width == nullptr ? nullptr : &v159,
                     height: height == nullptr ? nullptr : (int *)&v160,
                     timestamps,
                     imgNameBase);
    if ( BYTE3(v15) == 0 )
    {
      if ( pic != nullptr )
      {
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
      }
      goto LABEL_231;
    }
    if ( pic != nullptr )
    {
      LODWORD(v15) = v158;
      if ( v158 != nullptr && *pic != nullptr )
      {
        v17 = 0;
        v18 = 4 * *width * *height;
        if ( v18 >= 4 )
        {
          do
          {
            v19 = *pic;
            LODWORD(v15) = *(unsigned __int8 *)(v17 + v15) * (*pic)[v17];
            v167[0] = v15;
            v163 = (int)(float)((float)v15 * (float)0.0039215689);
            v20 = v163;
            if ( v163 >= 0 )
            {
              if ( v163 > 255 )
                v20 = -1;
            }
            else
            {
              v20 = 0;
            }
            v19[v17] = v20;
            v21 = &(*pic)[v17];
            v22 = v158[v17 + 1] * v21[1];
            v165 = *(_QWORD *)(&v16 - 1);
            v163 = (int)(float)((float)*(__int64 *)(&v16 - 1) * (float)0.0039215689);
            v23 = v163;
            if ( v163 >= 0 )
            {
              if ( v163 > 255 )
                v23 = -1;
            }
            else
            {
              v23 = 0;
            }
            v21[1] = v23;
            HIDWORD(v24) = &(*pic)[v17];
            LODWORD(v24) = v158[v17 + 2] * *(unsigned __int8 *)(HIDWORD(v24) + 2);
            *(_QWORD *)&v168.list = v24;
            v163 = (int)(float)((float)v24 * (float)0.0039215689);
            LOBYTE(v24) = v163;
            if ( v163 >= 0 )
            {
              if ( v163 > 255 )
                LOBYTE(v24) = -1;
            }
            else
            {
              LOBYTE(v24) = 0;
            }
            *(_BYTE *)(HIDWORD(v24) + 2) = v24;
            v25 = &(*pic)[v17];
            HIDWORD(v14) = v25[3];
            HIDWORD(v15) = v158[v17 + 3] * HIDWORD(v14);
            *(_QWORD *)&v166.list = *(__int64 *)((char *)&v15 + 4);
            v163 = (int)(float)((float)*(__int64 *)((char *)&v15 + 4) * (float)0.0039215689);
            v26 = v163;
            if ( v163 >= 0 )
            {
              if ( v163 > 255 )
                v26 = -1;
            }
            else
            {
              v26 = 0;
            }
            v17 += 4;
            v25[3] = v26;
            LODWORD(v15) = v158;
          }
          while ( v17 < v18 - 3 );
        }
        if ( v17 < v18 )
        {
          v27 = v18 - v17;
          do
          {
            v28 = *pic;
            LODWORD(v14) = *(unsigned __int8 *)(v17 + v15) * (*pic)[v17];
            *(_QWORD *)&v166.list = v14;
            v168.num = (int)(float)((float)v14 * (float)0.0039215689);
            num = v168.num;
            if ( v168.num >= 0 )
            {
              if ( v168.num > 255 )
                num = -1;
            }
            else
            {
              num = 0;
            }
            v28[v17++] = num;
            LODWORD(v15) = v158;
            --v27;
          }
          while ( v27 != 0 );
        }
        idMem::Free(this: &mem, ptr: (void *)v15, align: ALIGN_16);
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "smoothnormals") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
      R_SmoothNormalMap(data: *pic, width: *width, height: *height);
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "patchAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    v158 = nullptr;
    v159 = 0;
    v160 = 0;
    if ( !R_ParseImageProgram_r(
            src,
            pic: pic == nullptr ? nullptr : &v158,
            width: width == nullptr ? nullptr : &v159,
            height: height == nullptr ? nullptr : (int *)&v160,
            timestamps,
            imgNameBase) )
    {
      if ( pic != nullptr )
      {
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
      }
      goto LABEL_231;
    }
    if ( pic != nullptr )
    {
      v30 = *width;
      v31 = v158;
      v32 = *height;
      v33 = *pic;
      if ( v159 == *width && v160 == v32 )
      {
        v34 = nullptr;
      }
      else
      {
        v34 = R_Dropsample(in: v158, inwidth: v159, inheight: v160, outwidth: *width, outheight: *height);
        v31 = v34;
      }
      if ( v32 > 0 )
      {
        v35 = 0;
        do
        {
          v36 = 0;
          if ( v30 > 0 )
          {
            for ( i = v30; i != 0; --i )
            {
              v38 = 4 * (v35 + v36++);
              v39 = v31[v38];
              HIDWORD(v167[0]) = &v31[v38];
              v33[v38 + 3] = v39;
            }
          }
          --v32;
          v35 += v30;
        }
        while ( v32 != 0 );
      }
      if ( v34 != nullptr )
        idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
      idMem::Free(this: &mem, ptr: v158, align: ALIGN_16);
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "add") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    v158 = nullptr;
    v159 = 0;
    v160 = 0;
    if ( !R_ParseImageProgram_r(
            src,
            pic: pic == nullptr ? nullptr : &v158,
            width: width == nullptr ? nullptr : &v159,
            height: height == nullptr ? nullptr : (int *)&v160,
            timestamps,
            imgNameBase) )
    {
      if ( pic != nullptr )
      {
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
      }
      goto LABEL_231;
    }
    if ( pic != nullptr )
    {
      v40 = *width;
      v41 = v158;
      v42 = *height;
      v43 = *pic;
      if ( v159 == *width && v160 == v42 )
      {
        v44 = nullptr;
      }
      else
      {
        v44 = R_Dropsample(in: v158, inwidth: v159, inheight: v160, outwidth: *width, outheight: *height);
        v41 = v44;
      }
      if ( 4 * v40 * v42 > 0 )
      {
        v45 = (char *)v43;
        v46 = 4 * v40 * v42;
        v47 = v41 - v43;
        do
        {
          v48 = v45[v47] + *v45;
          if ( (unsigned __int8)v45[v47] + (unsigned int)(unsigned __int8)*v45 > 0xFF )
            v48 = -1;
          *v45++ = v48;
          --v46;
        }
        while ( v46 != 0 );
      }
      if ( v44 != nullptr )
        idMem::Free(this: &mem, ptr: v44, align: ALIGN_16);
      idMem::Free(this: &mem, ptr: v158, align: ALIGN_16);
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "constantColor") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    for ( j = 0; j < 4; ++j )
    {
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      v166.num = (int)(float)(idToken::GetFloatValue(this: &v164) * (float)255.0);
      v50 = v166.num;
      if ( v166.num >= 0 )
      {
        if ( v166.num > 255 )
          v50 = -1;
      }
      else
      {
        v50 = 0;
      }
      *((_BYTE *)&v165 + j) = v50;
      if ( j != 3 )
        MatchAndAppendToken(src, match: ",");
    }
    MatchAndAppendToken(src, match: ")");
    if ( width != nullptr )
      *width = 4;
    if ( height != nullptr )
      *height = 4;
    if ( pic != nullptr )
    {
      v51 = (unsigned __int8 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(971) : TAG_IMAGE",
                                 size: 0x40u,
                                 tag: TAG_IMAGE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v52 = BYTE3(v165);
      v53 = 0;
      v54 = BYTE2(v165);
      v55 = BYTE1(v165);
      v56 = HIBYTE(v165);
      *pic = v51;
      for ( k = 16; k != 0; --k )
      {
        (*pic)[v53] = v56;
        (*pic)[v53 + 1] = v55;
        (*pic)[v53 + 2] = v54;
        v58 = &(*pic)[v53];
        v53 += 4;
        v58[3] = v52;
      }
    }
    if ( timestamps != nullptr && *timestamps == -1 )
      *timestamps = 0;
    goto LABEL_374;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "scale") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    v59 = 0;
    v60 = (float *)&v165 + 1;
    *(float *)&v166.granularity = 1.0;
    *(float *)&v166.size = 1.0;
    *(float *)&v166.num = 1.0;
    *(float *)&v166.list = 1.0;
    while ( 1 )
    {
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      if ( idStr::Cmp(s1: v164.data, s2: ")") == 0 )
        break;
      v63 = idStr::Cmp(s1: v164.data, s2: ",") != 0;
      v62 = src;
      if ( v63 )
        goto LABEL_128;
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      ++v59;
      *++v60 = idToken::GetFloatValue(this: &v164);
      if ( v59 >= 4 )
        goto LABEL_129;
    }
    *(float *)&v166.granularity = *(float *)&v166.list;
    v166.size = (int)v166.list;
    v166.num = (int)v166.list;
    if ( v59 != 1 )
    {
      v62 = src;
LABEL_128:
      idParser::Warning(this: v62, str: "Bad scale format");
    }
LABEL_129:
    if ( v59 == 4 )
      MatchAndAppendToken(src, match: ")");
    if ( pic != nullptr )
      R_ImageScale(data: *pic, width: *width, height: *height, scale: (float *)&v166, a5: v61);
    goto LABEL_374;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "outlineAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    v158 = nullptr;
    v159 = 0;
    v160 = 0;
    if ( !R_ParseImageProgram_r(
            src,
            pic: pic == nullptr ? nullptr : &v158,
            width: width == nullptr ? nullptr : &v159,
            height: height == nullptr ? nullptr : (int *)&v160,
            timestamps,
            imgNameBase) )
    {
      if ( pic != nullptr )
      {
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
      }
      goto LABEL_231;
    }
    MatchAndAppendToken(src, match: ",");
    idParser::ReadToken(this: src, token: &v164);
    AppendToken(token: &v164);
    UnsignedIntValue = idToken::GetUnsignedIntValue(this: &v164);
    if ( pic != nullptr )
    {
      if ( *width != v159 || *height != v160 )
      {
        idParser::Warning(this: src, str: "mismatched sizes.\n");
        idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
        *pic = nullptr;
        idStr::FreeData(this: &v164);
        return false;
      }
      R_OutlineAlpha(data: *pic, width: v159, height: v160, alphaData: v158, count: UnsignedIntValue);
      idMem::Free(this: &mem, ptr: v158, align: ALIGN_16);
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "divideAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
      R_DivideAlpha(data: *pic, width: *width, height: *height, a4: v68, a5: v67, a6: v66);
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "invertAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
    {
      v69 = 0;
      v70 = *pic;
      v71 = *width * *height;
      if ( 4 * v71 > 0 )
      {
        v72 = ((unsigned int)(4 * v71 - 1) >> 2) + 1;
        do
        {
          v70[v69 + 3] = -1 - v70[v69 + 3];
          v69 += 4;
          --v72;
        }
        while ( v72 != 0 );
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "invertColor") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
    {
      v73 = 0;
      v74 = *pic;
      v75 = 4 * *height * *width;
      if ( v75 > 0 )
      {
        v77 = (unsigned int)(v75 - 1) >> 2;
        v76 = v74 + 1;
        v78 = v74 + 2;
        v79 = v77 + 1;
        do
        {
          v80 = -1 - v76[v73];
          v81 = -1 - v78[v73];
          v74[v73] = -1 - v74[v73];
          v76[v73] = v80;
          v78[v73] = v81;
          v73 += 4;
          --v79;
        }
        while ( v79 != 0 );
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "makeIntensity") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
    {
      v82 = 0;
      v83 = 4 * *width * *height;
      if ( v83 > 0 )
      {
        v84 = ((unsigned int)(v83 - 1) >> 2) + 1;
        do
        {
          (*pic)[v82 + 3] = (*pic)[v82];
          (*pic)[v82 + 2] = (*pic)[v82 + 3];
          v85 = &(*pic)[v82];
          v82 += 4;
          v85[1] = v85[2];
          --v84;
        }
        while ( v84 != 0 );
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "makeAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
    {
      v86 = 0;
      v87 = 4 * *width * *height;
      if ( v87 > 0 )
      {
        v88 = ((unsigned int)(v87 - 1) >> 2) + 1;
        do
        {
          (*pic)[v86 + 3] = ((*pic)[v86 + 2] + (*pic)[v86 + 1] + (*pic)[v86]) / 3;
          (*pic)[v86 + 2] = -1;
          (*pic)[v86 + 1] = -1;
          (*pic)[v86] = -1;
          v86 += 4;
          --v88;
        }
        while ( v88 != 0 );
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "extractAlpha") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
    {
      v89 = 0;
      v90 = 4 * *width * *height;
      if ( v90 > 0 )
      {
        v91 = ((unsigned int)(v90 - 1) >> 2) + 1;
        do
        {
          (*pic)[v89 + 2] = (*pic)[v89 + 3];
          (*pic)[v89 + 1] = (*pic)[v89 + 2];
          (*pic)[v89] = (*pic)[v89 + 1];
          v92 = &(*pic)[v89];
          v89 += 4;
          v92[3] = -1;
          --v91;
        }
        while ( v91 != 0 );
      }
    }
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "makeDivergence") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
      goto LABEL_231;
    if ( pic != nullptr )
      R_SetAlphaNormalDivergence(in: *pic, width: *width, height: *height);
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "resize") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    HIDWORD(v167[0]) = 0;
    v162 = 0;
    if ( !R_ParseImageProgram_r(
            src,
            pic,
            width: width == nullptr ? nullptr : (int *)v167,
            height: height == nullptr ? nullptr : &v162,
            timestamps,
            imgNameBase) )
      goto LABEL_231;
    MatchAndAppendToken(src, match: ",");
    appended = ParseIntAndAppendToken(src);
    v94 = -1;
    if ( idParser::PeekTokenType(this: src, type: 5, subtype: 40, token: &v164) != 0 )
    {
      MatchAndAppendToken(src, match: ",");
      v94 = ParseIntAndAppendToken(src);
    }
    if ( appended == -1 )
    {
      v95 = v94 < -1;
      if ( v94 == -1 )
      {
        idParser::Error(this: src, str: "At least one of target width and height must be specified\n");
LABEL_207:
        if ( HIDWORD(v167[0]) == 0 || v162 == 0 )
          goto LABEL_214;
        if ( v94 == -1 )
        {
          v94 = appended * v162 / SHIDWORD(v167[0]);
          v96 = __ROL4__(appended * v162, 1) - 1;
          __twllei(HIDWORD(v167[0]), 0);
          v97 = HIDWORD(v167[0]) & ~v96;
        }
        else
        {
          if ( appended != -1 )
          {
LABEL_214:
            if ( pic != nullptr )
            {
              if ( ((appended - 1) & appended) != 0 || (v99 = 1, appended <= 0) )
                v99 = 0;
              if ( v99 == 0 )
                goto LABEL_228;
              if ( ((v94 - 1) & v94) != 0 || (v100 = 1, v94 <= 0) )
                v100 = 0;
              if ( v100 == 0 )
              {
LABEL_228:
                idParser::Error(
                  this: src,
                  str: "new size not a power of to: old: %dx%d, new %dx%d\n",
                  HIDWORD(v167[0]),
                  v162,
                  appended,
                  v94);
                idStr::FreeData(this: &v164);
                return false;
              }
              *pic = R_Resize(
                       pic: *pic,
                       srcWidth: SHIDWORD(v167[0]),
                       srcHeight: v162,
                       newWidth: appended,
                       newHeight: v94);
            }
            if ( width != nullptr && height != nullptr )
            {
              *width = appended;
              *height = v94;
            }
LABEL_234:
            MatchAndAppendToken(src, match: ")");
            goto LABEL_374;
          }
          appended = v94 * HIDWORD(v167[0]) / v162;
          v98 = __ROL4__(v94 * HIDWORD(v167[0]), 1) - 1;
          __twllei(v162, 0);
          v97 = v162 & ~v98;
        }
        __twlgei(v97, 0xFFFFFFFF);
        goto LABEL_214;
      }
    }
    else
    {
      if ( appended < -1 )
        goto LABEL_206;
      v95 = v94 < -1;
    }
    if ( !v95 )
      goto LABEL_207;
LABEL_206:
    idParser::Error(this: src, str: "invalid target size: %dx%d\n", appended, v94);
    goto LABEL_207;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "atlasBorder") == 0 )
  {
    MatchAndAppendToken(src, match: "(");
    if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase) )
    {
LABEL_231:
      idStr::FreeData(this: &v164);
      return false;
    }
    MatchAndAppendToken(src, match: ",");
    idParser::ReadToken(this: src, token: &v164);
    AppendToken(token: &v164);
    v101 = idToken::GetUnsignedIntValue(this: &v164);
    MatchAndAppendToken(src, match: ",");
    idParser::ReadToken(this: src, token: &v164);
    AppendToken(token: &v164);
    v102 = idToken::GetUnsignedIntValue(this: &v164);
    if ( pic != nullptr )
      *pic = R_AtlasBorder(pic: *pic, width, height, maxWidth: v101, maxHeight: v102);
    goto LABEL_234;
  }
  if ( idStr::Icmp(s1: v164.data, s2: "wrinkleMask") != 0 )
  {
    if ( idStr::Icmp(s1: v164.data, s2: "chanShuffle") == 0 )
    {
      MatchAndAppendToken(src, match: "(");
      v171 = -3.4028235e38;
      v169.allocedAndFlag = 20;
      v169.data = v169.baseBuffer;
      v169.len = 0;
      v169.baseBuffer[0] = 0;
      v170 = 0;
      v172 = 0;
      v173 = 0;
      v174 = 0;
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v168);
      HIDWORD(v167[0]) = 0;
      v117 = 0;
      v118 = -1;
      for ( m = 0; m < 16; m += 4 )
      {
        idParser::ReadToken(this: src, token: &v164);
        AppendToken(token: &v164);
        if ( v164.type == 3 )
        {
          *(_DWORD *)&v175[m] = -1;
          v120 = idToken::GetFloatValue(this: &v164);
          if ( v120 > 1.0 || v120 < 0.0 )
          {
            idParser::Error(
              this: src,
              str: "chanShuffle: constant for channel %c is out of range: %f in shuffle spec \"%s\"\n",
              HIDWORD(v120),
              LODWORD(v120),
              v164.data);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
            idStr::FreeData(this: &v169);
            idStr::FreeData(this: &v164);
            return false;
          }
          *(_QWORD *)&v166.list = (__int64)(float)((float)v120 * (float)255.0);
          *((_BYTE *)v167 + v117) = v166.num;
        }
        else
        {
          if ( v164.type != 4 && v164.type != 1 || v164.len != 2 )
          {
            idParser::Error(
              this: src,
              str: "chanShuffle: invalid shuffle specification: \"%s\", expected [source number][source channel]\n",
              v164.data);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
            idStr::FreeData(this: &v169);
            idStr::FreeData(this: &v164);
            return false;
          }
          idStr::ToLower(this: &v164);
          v121 = 0;
          v122 = *v164.data;
          while ( v122 != aRgba[v121] )
          {
            if ( ++v121 >= 4 )
              goto LABEL_282;
          }
          if ( v121 == -1 )
          {
LABEL_282:
            idParser::Error(
              this: src,
              str: "chanShuffle: unknown channel '%c' in shuffle spec \"%s\", valid: r,g,b,a\n",
              v122,
              v164.data);
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
            idStr::FreeData(this: &v169);
            idStr::FreeData(this: &v164);
            return false;
          }
          v123 = v164.data[1];
          if ( v118 <= v123 - 48 )
            v118 = v123 - 48;
          *(_DWORD *)&v184[m] = v121;
          *(_DWORD *)&v175[m] = v123 - 48;
        }
        MatchAndAppendToken(src, match: ",");
        ++v117;
      }
      while ( 1 )
      {
        v124 = (unsigned __int8 **)idList<unsigned char *,5>::Alloc(this: &v168);
        *v124 = nullptr;
        v162 = 0;
        HIDWORD(v165) = 0;
        v125 = !R_ParseImageProgram_r(
                  src,
                  pic: pic == nullptr ? nullptr : v124,
                  width: width == nullptr ? nullptr : &v162,
                  height: height == nullptr ? nullptr : (int *)&v165,
                  timestamps: &v161,
                  imgNameBase);
        v126 = v168.num;
        if ( !v125 && width != nullptr && height != nullptr )
        {
          if ( v168.num == 1 )
          {
            v127 = HIDWORD(v165);
            *width = v162;
            *height = v127;
          }
          else if ( v162 != *width || HIDWORD(v165) != *height )
          {
            idParser::Error(
              this: src,
              str: "image sizes mismatch, first image: %dx%d, %d:th image %dx%d\n",
              *width,
              *height,
              v168.num,
              v162,
              HIDWORD(v165));
            v125 = true;
          }
        }
        if ( v125 )
          break;
        if ( idParser::PeekTokenType(this: src, type: 5, subtype: 40, token: &v164) == 0 )
        {
          if ( v126 <= v118 )
          {
            idParser::Error(this: src, str: "chanShuffle: pattern uses %d but only %d is specified\n", v118, v126);
            v6 = 1;
          }
          if ( width != nullptr && height != nullptr )
          {
            v130 = R_ImageShuffle(
                     srcIndexList: v175,
                     srcChannelList: v184,
                     srcConst: (unsigned __int8 *)v167,
                     argWidth: width,
                     argHeight: height,
                     picList: (idList<unsigned char *,5> *)&v168);
            if ( pic != nullptr )
              *pic = v130;
          }
          MatchAndAppendToken(src, match: ")");
          if ( v126 > 1 )
          {
            v131 = v126 - 1;
            v132 = (void **)(v168.list + 1);
            do
            {
              if ( *v132 != nullptr )
                idMem::Free(this: &mem, ptr: *v132, align: ALIGN_16);
              --v131;
              ++v132;
            }
            while ( v131 != 0 );
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
          idStr::FreeData(this: &v169);
          idStr::FreeData(this: &v164);
          return (_cntlzw(v6) & 0x20) != 0;
        }
        MatchAndAppendToken(src, match: ",");
      }
      if ( v126 > 0 )
      {
        list = (void **)v168.list;
        for ( n = v126; n != 0; --n )
        {
          if ( *list != nullptr )
            idMem::Free(this: &mem, ptr: *list, align: ALIGN_16);
          ++list;
        }
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v168);
      idStr::FreeData(this: &v169);
      idStr::FreeData(this: &v164);
      return false;
    }
    if ( idStr::Icmp(s1: v164.data, s2: "nameBase") == 0 )
    {
      MatchAndAppendToken(src, match: "(");
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      if ( v164.type != 4 && v164.type != 1 )
      {
        idParser::Error(this: src, str: "setImgBase: expected string or name, found \"%s\"\n", v164.data);
        idStr::FreeData(this: &v164);
        return false;
      }
      v135 = va::va(
               this: &v185,
               fmt: "%s%s",
               a3: __SPAIR64__((unsigned int)imgNameBase, (unsigned int)v164.data),
               a4: v134,
               a5: v133,
               a6: v152,
               a7: v153,
               a8: v154,
               a9: v155,
               a10: v156,
               a11: v157);
      idStr::idStr(this: &v182, text: v135);
      MatchAndAppendToken(src, match: ",");
      if ( !R_ParseImageProgram_r(src, pic, width, height, timestamps, imgNameBase: v182.data) )
      {
        idStr::FreeData(this: &v182);
        idStr::FreeData(this: &v164);
        return false;
      }
      MatchAndAppendToken(src, match: ")");
      idStr::FreeData(this: &v182);
      goto LABEL_374;
    }
    if ( idStr::Icmp(s1: v164.data, s2: "checker") == 0 )
    {
      MatchAndAppendToken(src, match: "(");
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      v136 = atol(nptr: v164.data);
      MatchAndAppendToken(src, match: ",");
      idParser::ReadToken(this: src, token: &v164);
      AppendToken(token: &v164);
      v137 = atol(nptr: v164.data);
      if ( width != nullptr )
        *width = v136;
      if ( height != nullptr )
        *height = v136;
      if ( pic != nullptr )
      {
        *pic = (unsigned __int8 *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1526) : TAG_IMAGE",
                                    size: 4 * v137 * v136,
                                    tag: TAG_IMAGE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
        v138 = 0;
        if ( v137 > 0 )
        {
          v139 = 0;
          do
          {
            v140 = 0;
            if ( v136 > 0 )
            {
              for ( ii = v136; ii != 0; --ii )
              {
                v142 = 4 * (v140 + v139);
                v143 = ((((unsigned __int8)v140++ ^ (unsigned __int8)v138) & 1) == 0) - 1;
                (*pic)[v142 + 2] = v143;
                (*pic)[v142 + 1] = v143;
                (*pic)[v142] = v143;
                (*pic)[v142 + 3] = -1;
              }
            }
            ++v138;
            v139 += v136;
          }
          while ( v138 < v137 );
        }
      }
      MatchAndAppendToken(src, match: ")");
      if ( timestamps != nullptr && *timestamps == -1 )
        *timestamps = 0;
      goto LABEL_374;
    }
    if ( timestamps == nullptr && pic == nullptr && width == nullptr && height == nullptr )
    {
LABEL_374:
      idStr::FreeData(this: &v164);
      return true;
    }
    if ( idStr::Icmp(s1: v164.data, s2: "_flat") != 0 )
    {
      if ( idStr::Icmp(s1: v164.data, s2: "_black") == 0 )
      {
        if ( width != nullptr )
          *width = 1;
        if ( height != nullptr )
          *height = 1;
        if ( pic != nullptr )
        {
          v145 = (unsigned __int8 *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1574) : TAG_IMAGE",
                                      size: 4u,
                                      tag: TAG_IMAGE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          *pic = v145;
          *v145 = 0;
          (*pic)[1] = 0;
          (*pic)[2] = 0;
          (*pic)[3] = -1;
        }
        goto LABEL_369;
      }
      if ( idStr::Icmp(s1: v164.data, s2: "_white") != 0 )
      {
        if ( idStr::Icmp(s1: v164.data, s2: "_borderedPointWhite") != 0 )
        {
          if ( idStr::Icmp(s1: v164.data, s2: "_noFalloff") != 0 )
          {
            v151 = va::va(
                     this: &v185,
                     fmt: "%s%s",
                     a3: __SPAIR64__((unsigned int)imgNameBase, (unsigned int)v164.data),
                     a4: v150,
                     a5: v149,
                     a6: v152,
                     a7: v153,
                     a8: v154,
                     a9: v155,
                     a10: v156,
                     a11: v157);
            R_LoadImage(cname: v151->buffer, pic, width, height, timestamp: &v161);
            v148 = v161;
            if ( v161 == -1 )
            {
              idStr::FreeData(this: &v164);
              return false;
            }
LABEL_370:
            if ( timestamps != nullptr && (v148 > *timestamps || *timestamps == -1) )
              *timestamps = v148;
            goto LABEL_374;
          }
          if ( width != nullptr )
            *width = 1;
          if ( height != nullptr )
            *height = 1;
          if ( pic == nullptr )
          {
LABEL_369:
            v148 = 0;
            v161 = 0;
            goto LABEL_370;
          }
          v146 = "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1619) : TAG_IMAGE";
        }
        else
        {
          if ( width != nullptr )
            *width = 1;
          if ( height != nullptr )
            *height = 1;
          if ( pic == nullptr )
            goto LABEL_369;
          v146 = "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1604) : TAG_IMAGE";
        }
      }
      else
      {
        if ( width != nullptr )
          *width = 1;
        if ( height != nullptr )
          *height = 1;
        if ( pic == nullptr )
          goto LABEL_369;
        v146 = "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1589) : TAG_IMAGE";
      }
      v147 = (unsigned __int8 *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: v146,
                                  size: 4u,
                                  tag: TAG_IMAGE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      *pic = v147;
      *v147 = -1;
      (*pic)[1] = -1;
    }
    else
    {
      if ( width != nullptr )
        *width = 1;
      if ( height != nullptr )
        *height = 1;
      if ( pic == nullptr )
        goto LABEL_369;
      v144 = (unsigned __int8 *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_program.cpp(1559) : TAG_IMAGE",
                                  size: 4u,
                                  tag: TAG_IMAGE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      *pic = v144;
      *v144 = 0x80;
      (*pic)[1] = 0x80;
    }
    (*pic)[2] = -1;
    (*pic)[3] = -1;
    goto LABEL_369;
  }
  MatchAndAppendToken(src, match: "(");
  v178 = -3.4028235e38;
  v176.allocedAndFlag = 20;
  v176.data = v176.baseBuffer;
  v176.len = 0;
  v176.baseBuffer[0] = 0;
  v177 = 0;
  v179 = 0;
  v180 = 0;
  v181 = 0;
  idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v164);
  AppendToken(token: &v164);
  idStr::idStr(this: &v183, text: &v164);
  MatchAndAppendToken(src, match: ",");
  idParser::ExpectTokenType(this: src, type: 3, subtype: 1, token: &v164);
  AppendToken(token: &v164);
  v103 = idToken::GetUnsignedIntValue(this: &v164);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v166);
  if ( pic == nullptr || (v104 = 0, v103 <= 0) )
  {
    v112 = v166.num;
LABEL_260:
    if ( width != nullptr && height != nullptr )
    {
      v115 = R_ImageCompileWrinkleMask(argWidth: width, argHeight: height, picList: (idList<unsigned char *,5> *)&v166);
      if ( pic != nullptr )
        *pic = v115;
    }
    MatchAndAppendToken(src, match: ")");
    if ( v112 > 0 )
    {
      v116 = (void **)v166.list;
      do
      {
        if ( *v116 != nullptr )
          idMem::Free(this: &mem, ptr: *v116, align: ALIGN_16);
        --v112;
        ++v116;
      }
      while ( v112 != 0 );
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v166);
    idStr::FreeData(this: &v183);
    idStr::FreeData(this: &v176);
    goto LABEL_374;
  }
  while ( 1 )
  {
    v105 = idList<unsigned char *,5>::Alloc(this: &v166);
    *v105 = nullptr;
    HIDWORD(v165) = 0;
    v162 = 0;
    LODWORD(v106) = (height == nullptr) - 1;
    HIDWORD(v106) = -(int)width;
    v107 = (unsigned __int8 **)v105;
    HIDWORD(v108) = &v162;
    v109 = (int *)(v106 & (unsigned int)&v162);
    v110 = va::va(
             this: &v185,
             fmt: "%s%d",
             a3: __SPAIR64__((unsigned int)v183.data, v104),
             a4: v106,
             a5: v108,
             a6: v152,
             a7: v153,
             a8: v154,
             a9: v155,
             a10: v156,
             a11: v157);
    R_LoadImage(
      cname: v110->buffer,
      pic: v107,
      width: width == nullptr ? nullptr : (int *)&v165,
      height: v109,
      timestamp: &v161);
    v111 = v161 == -1;
    if ( timestamps != nullptr && (v161 > *timestamps || *timestamps == -1) )
      *timestamps = v161;
    v112 = v166.num;
    if ( !v111 && width != nullptr && height != nullptr )
    {
      if ( v166.num == 1 )
      {
        v113 = v162;
        *width = HIDWORD(v165);
        *height = v113;
      }
      else if ( HIDWORD(v165) != *width || v162 != *height )
      {
        idParser::Error(
          this: src,
          str: "image sizes mismatch, first image: %dx%d, %d:th image %dx%d\n",
          *width,
          *height,
          v166.num,
          HIDWORD(v165),
          v162);
        v111 = true;
      }
    }
    if ( v111 )
      break;
    if ( (int)++v104 >= v103 )
      goto LABEL_260;
  }
  if ( v112 > 0 )
  {
    v114 = (void **)v166.list;
    do
    {
      if ( *v114 != nullptr )
        idMem::Free(this: &mem, ptr: *v114, align: ALIGN_16);
      --v112;
      ++v114;
    }
    while ( v112 != 0 );
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v166);
  idStr::FreeData(this: &v183);
  idStr::FreeData(this: &v176);
  idStr::FreeData(this: &v164);
  return false;
}


// ========================================================================
// __unwind$222594
// EA  : 0x828CED04
// RVA : 0x008CED04
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 112));
}


// ========================================================================
// __unwind$222595
// EA  : 0x828CED2C
// RVA : 0x008CED2C
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 336));
}


// ========================================================================
// __unwind$222596
// EA  : 0x828CED54
// RVA : 0x008CED54
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 448));
}


// ========================================================================
// __unwind$222597_0
// EA  : 0x828CED7C
// RVA : 0x008CED7C
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222597_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4752 + 192));
}


// ========================================================================
// __unwind$222598
// EA  : 0x828CEDA4
// RVA : 0x008CEDA4
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222598()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 240));
}


// ========================================================================
// __unwind$222599
// EA  : 0x828CEDCC
// RVA : 0x008CEDCC
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222599()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4752 + 224));
}


// ========================================================================
// __unwind$222600
// EA  : 0x828CEDF4
// RVA : 0x008CEDF4
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_222600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 416));
}


// ========================================================================
// ?R_LoadImageProgram@@YA_NPBDPAPAEPAH2PAI@Z
// EA  : 0x828CEE28
// RVA : 0x008CEE28
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

int __fastcall R_LoadImageProgram(
        const char *name,
        unsigned __int8 **pic,
        int *width,
        int *height,
        unsigned int *timestamps)
{
  int v10; // r5
  bool v11; // r30
  bool v12; // r3
  unsigned __int8 v13; // r11
  int v14; // r30
  idParser v16; // [sp+50h] [-2E0h] BYREF

  idParser::idParser(this: &v16, flags: 0);
  v10 = 0;
  if ( *name != 0 )
  {
    do
      ++v10;
    while ( name[v10] != 0 );
  }
  idParser::LoadMemory(this: &v16, ptr: name, length: v10, name);
  idParser::SetFlags(this: &v16, flags: 564);
  parseBuffer[0] = 0;
  parseBufferError = false;
  if ( timestamps != nullptr )
    *timestamps = -1;
  if ( pic != nullptr )
    *pic = nullptr;
  if ( width != nullptr )
    *width = 0;
  if ( height != nullptr )
    *height = 0;
  v11 = R_ParseImageProgram_r(src: &v16, pic, width, height, timestamps, imgNameBase: &byte_8200D768);
  if ( parseBufferError )
    idParser::Error(this: &v16, str: "Image program/name to long, max %d chars", 1024);
  if ( !v11 || (v12 = idParser::HadError(this: &v16), v13 = 1, v12) )
    v13 = 0;
  v14 = v13;
  if ( v13 == 0 )
  {
    if ( timestamps != nullptr )
      *timestamps = -1;
    if ( pic != nullptr && *pic != nullptr )
    {
      idMem::Free(this: &mem, ptr: *pic, align: ALIGN_16);
      *pic = nullptr;
    }
    if ( width != nullptr )
      *width = 0;
    if ( height != nullptr )
      *height = 0;
  }
  idParser::FreeSource(this: &v16);
  idParser::~idParser(this: &v16);
  return v14;
}


// ========================================================================
// __unwind$223940
// EA  : 0x828CEFC4
// RVA : 0x008CEFC4
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

void _unwind_223940()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 816 + 80));
}


// ========================================================================
// ?R_ParsePastImageProgram@@YA?AVidStr@@AAVidParser@@@Z
// EA  : 0x828CEFF0
// RVA : 0x008CEFF0
// PDB : w:\tech5\engine\renderer\imagetools\image_program.cpp
// ========================================================================

idStr *__fastcall R_ParsePastImageProgram(idStr *result, idParser *src)
{
  parseBuffer[0] = 0;
  parseBufferError = false;
  R_ParseImageProgram_r(
    src,
    pic: nullptr,
    width: nullptr,
    height: nullptr,
    timestamps: nullptr,
    imgNameBase: &byte_8200D768);
  if ( parseBufferError )
    idParser::Error(this: src, str: "Image program/name to long, max %d chars", 1024);
  idStr::idStr(this: result, text: parseBuffer);
  return result;
}

