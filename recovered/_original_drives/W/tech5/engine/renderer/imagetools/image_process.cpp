
// ========================================================================
// ?R_ResampleTexture@@YAPAEPBEHHHH@Z
// EA  : 0x828C9338
// RVA : 0x008C9338
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

char *__fastcall R_ResampleTexture(
        const unsigned __int8 *in,
        int inwidth,
        unsigned int inheight,
        int outwidth,
        int outheight)
{
  _BYTE *v10; // r20
  _BYTE *v11; // r25
  char *v12; // r17
  char *v13; // r22
  _BYTE v14[12]; // r11
  int v15; // r8
  int v16; // ctr
  int v17; // r26
  double v18; // fp13
  double v19; // fp0
  const unsigned __int8 *v20; // r6
  const unsigned __int8 *v21; // r7
  _DWORD *v22; // r8
  int v23; // ctr
  unsigned __int8 *v24; // r31
  unsigned __int8 *v25; // r4

  v10 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(78) : TAG_IMAGE",
          size: 0x10000u,
          tag: TAG_IMAGE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v11 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(79) : TAG_IMAGE",
          size: 0x10000u,
          tag: TAG_IMAGE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v12 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(81) : TAG_IMAGE",
                  size: 4 * outwidth * outheight,
                  tag: TAG_IMAGE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  *(_DWORD *)&v14[8] = (inwidth << 16) / outwidth;
  *(_DWORD *)&v14[4] = *(int *)&v14[8] >> 2;
  __twllei(outwidth, 0);
  v13 = v12;
  __twlgei(outwidth & ~(__ROL4__(inwidth << 16, 1) - 1), 0xFFFFFFFF);
  *(_DWORD *)v14 = *(int *)&v14[8] >> 1;
  if ( outwidth > 0 )
  {
    v15 = *(_DWORD *)v14 + *(_DWORD *)&v14[4];
    v16 = outwidth;
    *(_DWORD *)v14 = v11;
    do
    {
      *(_DWORD *)(v10 - v11 + *(_DWORD *)v14) = 4 * (*(int *)&v14[4] >> 16);
      *(_DWORD *)&v14[4] += *(_DWORD *)&v14[8];
      **(_DWORD **)v14 = 4 * (v15 >> 16);
      v15 += *(_DWORD *)&v14[8];
      *(_DWORD *)v14 += 4;
      --v16;
    }
    while ( v16 != 0 );
  }
  v17 = 0;
  if ( outheight > 0 )
  {
    *(_DWORD *)&v14[4] = inheight;
    v18 = (float)__SPAIR64__(inheight, outheight);
    v19 = (float)*(__int64 *)v14;
    *(_DWORD *)&v14[4] = &unk_82150000;
    do
    {
      *(_DWORD *)&v14[8] = v17;
      *(_DWORD *)v14 = (int)(float)((float)((float)((float)*(__int64 *)&v14[4] + (float)0.25) * (float)v19) / (float)v18);
      *(_DWORD *)&v14[4] = 4
                         * (int)(float)((float)((float)((float)*(__int64 *)&v14[4] + (float)0.75) * (float)v19)
                                      / (float)v18)
                         * inwidth;
      v20 = &in[*(_DWORD *)&v14[4]];
      v21 = &in[4 * *(_DWORD *)v14 * inwidth];
      if ( outwidth > 0 )
      {
        v22 = v11;
        v23 = outwidth;
        *(_DWORD *)&v14[8] = v13 - 1;
        do
        {
          *(_DWORD *)&v14[4] = *(_DWORD *)((char *)v22 + v10 - v11);
          v24 = (unsigned __int8 *)&v20[*v22];
          v25 = (unsigned __int8 *)&v21[*v22++];
          *(_BYTE *)(*(_DWORD *)&v14[8] + 1) = (*v24 + v20[*(_DWORD *)&v14[4]] + *v25 + v21[*(_DWORD *)&v14[4]]) >> 2;
          *(_BYTE *)(*(_DWORD *)&v14[8] + 2) = (v24[1]
                                              + v20[*(_DWORD *)&v14[4] + 1]
                                              + v25[1]
                                              + v21[*(_DWORD *)&v14[4] + 1]) >> 2;
          *(_BYTE *)(*(_DWORD *)&v14[8] + 3) = (v24[2]
                                              + v20[*(_DWORD *)&v14[4] + 2]
                                              + v25[2]
                                              + v21[*(_DWORD *)&v14[4] + 2]) >> 2;
          *(_DWORD *)v14 = v21[*(_DWORD *)&v14[4] + 3];
          *(_DWORD *)&v14[4] = v24[3] + v20[*(_DWORD *)&v14[4] + 3] + v25[3];
          *(_DWORD *)&v14[8] += 4;
          **(_BYTE **)&v14[8] = (*(_DWORD *)&v14[4] + *(_DWORD *)v14) >> 2;
          --v23;
        }
        while ( v23 != 0 );
      }
      ++v17;
      v13 += 4 * outwidth;
    }
    while ( v17 < outheight );
  }
  idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
  return v12;
}


// ========================================================================
// ?R_HorizontalFlip@@YAXPAEHH@Z
// EA  : 0x828C95F0
// RVA : 0x008C95F0
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall R_HorizontalFlip(unsigned __int8 *data, int width, int height)
{
  int v3; // r8
  int v4; // r11
  int v5; // ctr
  int v6; // r9
  int v7; // r10
  int v8; // r31

  if ( height > 0 )
  {
    v3 = 0;
    do
    {
      v4 = 0;
      if ( width / 2 > 0 )
      {
        v5 = width / 2;
        do
        {
          v6 = 4 * (v3 + v4);
          v7 = 4 * (v3 + width - v4++ - 1);
          v8 = *(_DWORD *)&data[v6];
          *(_DWORD *)&data[v6] = *(_DWORD *)&data[v7];
          *(_DWORD *)&data[v7] = v8;
          --v5;
        }
        while ( v5 != 0 );
      }
      --height;
      v3 += width;
    }
    while ( height != 0 );
  }
}


// ========================================================================
// ?R_VerticalFlip@@YAXPAEHH@Z
// EA  : 0x828C9668
// RVA : 0x008C9668
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall R_VerticalFlip(unsigned __int8 *data, int width, int height)
{
  int v3; // r7
  unsigned __int8 *v4; // r6
  int v5; // ctr
  unsigned __int8 *v6; // r11
  unsigned __int8 *v7; // r10
  int v8; // r29

  v3 = 0;
  if ( width > 0 )
  {
    v4 = data;
    do
    {
      if ( height / 2 > 0 )
      {
        v5 = height / 2;
        v6 = v4;
        v7 = &data[4 * (height - 1) * width + 4 * v3];
        do
        {
          v8 = *(_DWORD *)v6;
          *(_DWORD *)v6 = *(_DWORD *)v7;
          v6 += 4 * width;
          *(_DWORD *)v7 = v8;
          v7 -= 4 * width;
          --v5;
        }
        while ( v5 != 0 );
      }
      ++v3;
      v4 += 4;
    }
    while ( v3 < width );
  }
}


// ========================================================================
// ?R_RotatePic@@YAXPAEH@Z
// EA  : 0x828C96E8
// RVA : 0x008C96E8
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall R_RotatePic(unsigned __int8 *data, int width)
{
  unsigned int v2; // r28
  char *v5; // r30
  int v6; // r7
  int v7; // r8
  unsigned __int8 *v8; // r6
  int i; // r5
  int v10; // r11
  int v11; // ctr
  unsigned __int8 *v12; // r10
  int v13; // r3

  v2 = 4 * width * width;
  v5 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(637) : TAG_IMAGE",
                 size: v2,
                 tag: TAG_IMAGE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( width > 0 )
  {
    v6 = 4 * width;
    v7 = 0;
    v8 = data;
    for ( i = width; i != 0; --i )
    {
      v10 = 0;
      v11 = width;
      v12 = &v8[-v6];
      do
      {
        v12 += v6;
        v13 = 4 * (v7 + v10++);
        *(_DWORD *)&v5[v13] = *(_DWORD *)v12;
        --v11;
      }
      while ( v11 != 0 );
      v7 += width;
      v8 += 4;
    }
  }
  memcpy(Dst: data, Src: v5, Size: v2);
  idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
}


// ========================================================================
// ?R_Dropsample@@YAPAEPBEHHHH@Z
// EA  : 0x828C97A8
// RVA : 0x008C97A8
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall R_Dropsample(
        const unsigned __int8 *in,
        int inwidth,
        unsigned int inheight,
        int outwidth,
        int outheight)
{
  __int64 v10; // r10 OVERLAPPED
  unsigned __int8 *result; // r3
  int v12; // r6
  unsigned __int8 *v13; // r5
  double v14; // fp13
  double v15; // fp12
  int v16; // r11
  int v17; // ctr
  unsigned __int8 *v18; // r11
  unsigned int v19; // r29
  unsigned __int8 v20; // r8
  int v21; // [sp+5Ch] [-34h]

  result = (unsigned __int8 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(129) : TAG_IMAGE",
                                size: 4 * outwidth * outheight,
                                tag: TAG_IMAGE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v12 = 0;
  v13 = result;
  if ( outheight > 0 )
  {
    LODWORD(v10) = inheight;
    v14 = (float)v10;
    v15 = (float)__SPAIR64__(inheight, outheight);
    do
    {
      v16 = v12;
      v21 = (int)(float)((float)((float)((float)*(__int64 *)((char *)&v10 - 4) + (float)0.25) * (float)v14) / (float)v15);
      LODWORD(v10) = v21;
      if ( outwidth > 0 )
      {
        HIDWORD(v10) = 0;
        v17 = outwidth;
        v18 = v13 - 1;
        do
        {
          v19 = outwidth & ~(__ROL4__(HIDWORD(v10), 1) - 1);
          LODWORD(v10) = &in[4 * v21 * inwidth + 4 * (SHIDWORD(v10) / outwidth)];
          __twllei(outwidth, 0);
          v20 = *(_BYTE *)v10;
          HIDWORD(v10) += inwidth;
          __twlgei(v19, 0xFFFFFFFF);
          v18[1] = v20;
          v18[2] = *(_BYTE *)(v10 + 1);
          v18[3] = *(_BYTE *)(v10 + 2);
          LODWORD(v10) = *(unsigned __int8 *)(v10 + 3);
          v18 += 4;
          *v18 = v10;
          --v17;
        }
        while ( v17 != 0 );
      }
      ++v12;
      v13 += 4 * outwidth;
    }
    while ( v12 < outheight );
  }
  return result;
}


// ========================================================================
// ?R_SetAlphaNormalDivergence@@YAXPAEHH@Z
// EA  : 0x828C98E8
// RVA : 0x008C98E8
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall R_SetAlphaNormalDivergence(unsigned __int8 *in, int width, int height)
{
  char *v6; // r3
  _BYTE *v7; // r4
  int v8; // r6
  unsigned __int8 *v9; // r30
  int v10; // r7
  unsigned __int8 *v11; // r5
  __int64 v12; // r11
  double v13; // fp9
  unsigned __int64 v14; // r9 OVERLAPPED
  __int64 v15; // fp8
  double v16; // fp1
  double v17; // fp7
  double v18; // fp10
  double v19; // fp8
  double v22; // fp1
  double v23; // fp2
  double v24; // fp2
  double v25; // fp8
  double v26; // fp7
  double v27; // fp6
  int i; // ctr
  unsigned __int8 *v29; // r11
  __int64 v30; // r27
  __int64 v31; // r11 OVERLAPPED
  double v32; // fp10
  double v33; // fp1
  double v34; // fp2
  double v37; // fp31
  double v38; // fp31
  double v39; // fp31
  double v40; // fp31
  int v41; // r11
  int v42; // r23
  int v43; // r25
  int v44; // r5
  int v45; // r29
  int v46; // ctr
  int v47; // r28
  int v48; // r30
  int v49; // r10
  int v50; // r8
  int v51; // r11
  int v52; // r6
  int v53; // r7
  int v54; // r10
  int v55; // r10
  int v56; // r10
  unsigned __int8 v57; // r9
  int v58; // r11

  v6 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(172) : TAG_IMAGE",
                 size: width * height,
                 tag: TAG_IMAGE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v7 = v6;
  v8 = 0;
  if ( height > 0 )
  {
    v9 = in + 2;
    do
    {
      v10 = 0;
      if ( width > 0 )
      {
        v11 = v9;
        do
        {
          LODWORD(v12) = *(v11 - 2);
          v13 = 1.0;
          HIDWORD(v12) = *v11;
          v14 = *(v11 - 2) | 0xFFFFFFFF00000000uLL;
          v15 = v12;
          v16 = (double)*(__int64 *)((char *)&v14 - 4);
          HIDWORD(v12) = *(v11 - 1);
          v17 = (float)((float)((float)*(__int64 *)((char *)&v14 - 4) * (float)0.0078431377) - (float)1.0);
          v18 = (float)((float)((float)v16 * (float)0.0078431377) - (float)1.0);
          v19 = (float)((float)((float)v15 * (float)0.0078431377) - (float)1.0);
          _FP1 = (float)((float)((float)((float)v19 * (float)v19)
                               + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f2, f1, f2, f11 }
          v22 = __frsqrte(_FP2);
          v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)((float)v19 * (float)v19)
                                                                              + (float)((float)((float)v18 * (float)v18)
                                                                                      + (float)((float)v17 * (float)v17)))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22));
          v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22)
                                                                                              * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                              * (float)v22))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                              * (float)v22)
                                                                                      - (float)1.5)
                                                                      * (float)v22))
                                                      * (float)((float)((float)((float)v19 * (float)v19)
                                                                      + (float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17)))
                                                              * (float)0.5))
                                              * (float)v23)
                                      - (float)1.5)
                      * (float)v23);
          v25 = (float)((float)v24 * (float)v19);
          v26 = (float)((float)((float)((float)*(__int64 *)((char *)&v14 - 4) * (float)0.0078431377) - (float)1.0)
                      * (float)v24);
          v27 = (float)((float)v18 * (float)v24);
          do
          {
            LODWORD(v14) = -1;
            for ( i = 3; i != 0; --i )
            {
              if ( v14 != 0 )
              {
                HIDWORD(v30) = width - 1;
                v29 = &in[4 * ((HIDWORD(v14) + v8) & (height - 1)) * width + 4 * ((v14 + v10) & (width - 1))];
                HIDWORD(v31) = v29[2];
                LODWORD(v30) = *v29;
                LODWORD(v31) = v29[1];
                v32 = (float)((float)((float)*(__int64 *)((char *)&v14 - 4) * (float)0.0078431377) - (float)1.0);
                v33 = (float)((float)((float)v31 * (float)0.0078431377) - (float)1.0);
                v34 = (float)((float)((float)v30 * (float)0.0078431377) - (float)1.0);
                _FP30 = (float)((float)((float)((float)v34 * (float)v34)
                                      + (float)((float)((float)v32 * (float)v32) + (float)((float)v33 * (float)v33)))
                              - idMath::FLT_SMALLEST_NON_DENORMAL);
                __asm { fsel      f31, f30, f31, f11 }
                v37 = __frsqrte(_FP31);
                v38 = (float)((float)-(float)((float)((float)((float)v37
                                                            * (float)((float)((float)((float)v34 * (float)v34)
                                                                            + (float)((float)((float)v32 * (float)v32)
                                                                                    + (float)((float)v33 * (float)v33)))
                                                                    * (float)0.5))
                                                    * (float)v37)
                                            - (float)1.5)
                            * (float)v37);
                v39 = (float)((float)-(float)((float)((float)((float)v38
                                                            * (float)((float)((float)((float)v34 * (float)v34)
                                                                            + (float)((float)((float)v32 * (float)v32)
                                                                                    + (float)((float)v33 * (float)v33)))
                                                                    * (float)0.5))
                                                    * (float)v38)
                                            - (float)1.5)
                            * (float)v38);
                v40 = (float)((float)-(float)((float)((float)((float)v39
                                                            * (float)((float)((float)((float)v34 * (float)v34)
                                                                            + (float)((float)((float)v32 * (float)v32)
                                                                                    + (float)((float)v33 * (float)v33)))
                                                                    * (float)0.5))
                                                    * (float)v39)
                                            - (float)1.5)
                            * (float)v39);
                if ( (float)((float)((float)((float)v40 * (float)((float)((float)v30 * (float)0.0078431377) - (float)1.0))
                                   * (float)v25)
                           + (float)((float)((float)((float)((float)((float)*(__int64 *)((char *)&v14 - 4)
                                                                   * (float)0.0078431377)
                                                           - (float)1.0)
                                                   * (float)v40)
                                           * (float)v27)
                                   + (float)((float)((float)((float)((float)v31 * (float)0.0078431377) - (float)1.0)
                                                   * (float)v40)
                                           * (float)v26))) < v13 )
                  v13 = (float)((float)((float)((float)v40
                                              * (float)((float)((float)v30 * (float)0.0078431377) - (float)1.0))
                                      * (float)v25)
                              + (float)((float)((float)((float)((float)((float)*(__int64 *)((char *)&v14 - 4)
                                                                      * (float)0.0078431377)
                                                              - (float)1.0)
                                                      * (float)v40)
                                              * (float)v27)
                                      + (float)((float)((float)((float)((float)v31 * (float)0.0078431377) - (float)1.0)
                                                      * (float)v40)
                                              * (float)v26)));
              }
              LODWORD(v14) = v14 + 1;
            }
            ++HIDWORD(v14);
          }
          while ( SHIDWORD(v14) <= 1 );
          if ( v13 < 0.0 )
            v13 = 0.0;
          v41 = (int)(float)((float)v13 * (float)255.0);
          if ( v41 >= 0 )
          {
            if ( v41 > 255 )
              LOBYTE(v41) = -1;
          }
          else
          {
            LOBYTE(v41) = 0;
          }
          v6[v10++] = v41;
          v11 += 4;
        }
        while ( v10 < width );
      }
      ++v8;
      v9 += 4 * width;
      v6 += width;
    }
    while ( v8 < height );
    v42 = 0;
    v43 = 1;
    do
    {
      v44 = 0;
      if ( width > 0 )
      {
        v45 = height - 1;
        v46 = width;
        v47 = ((height - 1) & v43) * width;
        v48 = width - 1;
        do
        {
          v49 = (v45 & (v43 - 2)) * width;
          v50 = (v44 - 1) & v48;
          v51 = 255;
          if ( (unsigned __int8)v7[v50 + v49] != 255 )
            v51 = (unsigned __int8)v7[v50 + v49];
          v52 = v48 & v44;
          if ( (unsigned __int8)v7[v49 + (v48 & v44)] < v51 )
            v51 = (unsigned __int8)v7[v49 + (v48 & v44)];
          v53 = (v44 + 1) & v48;
          v54 = (unsigned __int8)v7[v49 + v53];
          if ( v54 < v51 )
            v51 = v54;
          v55 = (v45 & (v43 - 1)) * width;
          if ( (unsigned __int8)v7[v50 + v55] < v51 )
            v51 = (unsigned __int8)v7[v50 + v55];
          if ( (unsigned __int8)v7[v55 + v52] < v51 )
            v51 = (unsigned __int8)v7[v55 + v52];
          v56 = (unsigned __int8)v7[v55 + v53];
          if ( v56 < v51 )
            v51 = v56;
          if ( (unsigned __int8)v7[v50 + v47] < v51 )
            v51 = (unsigned __int8)v7[v50 + v47];
          if ( (unsigned __int8)v7[v47 + v52] < v51 )
            v51 = (unsigned __int8)v7[v47 + v52];
          if ( (unsigned __int8)v7[v47 + v53] < v51 )
            LOBYTE(v51) = v7[v47 + v53];
          v57 = v51;
          v58 = 4 * (v42 + v44++);
          in[v58 + 3] = v57;
          --v46;
        }
        while ( v46 != 0 );
      }
      ++v43;
      v42 += width;
    }
    while ( v43 - 1 < height );
  }
  idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
}


// ========================================================================
// ?R_MipMap@@YAPAEPBEHH@Z
// EA  : 0x828C9D20
// RVA : 0x008C9D20
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

unsigned __int8 *__fastcall R_MipMap(const unsigned __int8 *in, int width, int height)
{
  int v3; // r11
  int v7; // r10
  unsigned __int8 *v8; // r28

  v3 = width >> 1;
  if ( width >> 1 < 1 )
    v3 = 1;
  v7 = height >> 1;
  if ( height >> 1 < 1 )
    v7 = 1;
  v8 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(283) : TAG_IMAGE",
                            size: 4 * v7 * v3,
                            tag: TAG_IMAGE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  idMipMap::CreateSingleMip(src: in, width, height, dest: v8);
  return v8;
}


// ========================================================================
// ?R_CubeTexel@@YAPAEHQAPAEVidVec3@@@Z
// EA  : 0x828C9DA8
// RVA : 0x008C9DA8
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

unsigned __int8 *__fastcall R_CubeTexel(int size, unsigned __int8 **data, idVec3 *dir)
{
  __int64 v3; // r11
  double v4; // fp0
  double v5; // fp12
  double v6; // fp13
  double v8; // fp10
  double v9; // fp11
  int v10; // r8
  double v11; // fp9
  double v12; // fp13
  double v13; // fp8
  int v14; // ctr
  double v15; // fp12
  int v16; // r11
  double v17; // fp13
  int v18; // fp6
  __int64 v19; // [sp+0h] [-20h] BYREF
  int v21; // [sp+Ch] [-14h]
  float back_chain; // [sp+10h] [-10h] BYREF
  float v23; // [sp+14h] [-Ch]
  float v24; // [sp+18h] [-8h]

  v4 = *(float *)&data;
  v5 = *(float *)&dir;
  v6 = *(float *)&dir;
  if ( *(float *)&data == 0.0 && v6 == 0.0 && v5 == 0.0 )
    return *data;
  v8 = __fabs(v6);
  v9 = __fabs(v4);
  v10 = 0;
  v11 = __fabs(v5);
  if ( v4 >= v8 && v4 >= v11 )
  {
    back_chain = -v5;
    v24 = v9;
    v12 = -v6;
LABEL_24:
    v23 = v12;
    goto LABEL_25;
  }
  v13 = -v4;
  if ( -v4 >= v8 && v13 >= v11 )
  {
    back_chain = *(float *)&dir;
    v24 = v9;
    v10 = 1;
    v23 = -v6;
    goto LABEL_25;
  }
  if ( v6 >= v9 && v6 >= v11 )
  {
    v24 = v8;
    v10 = 2;
    back_chain = *(float *)&data;
    v23 = *(float *)&dir;
    goto LABEL_25;
  }
  v12 = -v6;
  if ( v12 >= v9 && v12 >= v11 )
  {
    back_chain = *(float *)&data;
    v12 = -v5;
    v24 = v8;
    v10 = 3;
    goto LABEL_24;
  }
  if ( v5 >= v9 && v5 >= v8 )
  {
    back_chain = *(float *)&data;
    v10 = 4;
LABEL_23:
    v24 = v11;
    goto LABEL_24;
  }
  if ( -v5 >= v9 && -v5 >= v8 )
  {
    back_chain = v13;
    v10 = 5;
    goto LABEL_23;
  }
LABEL_25:
  LODWORD(v3) = size;
  v19 = v3;
  v14 = 2;
  v15 = (float)v3;
  v16 = 0;
  v17 = (float)((float)1.0 / v24);
  do
  {
    v18 = (int)(float)((float)((float)((float)(*(float *)((char *)&back_chain + v16) * (float)v17) + (float)1.0)
                             * (float)0.5)
                     * (float)v15);
    v21 = v18;
    *(_DWORD *)((char *)&v19 + v16) = v18;
    if ( v18 >= 0 )
    {
      if ( v18 >= size )
        *(_DWORD *)((char *)&v19 + v16) = size - 1;
    }
    else
    {
      *(_DWORD *)((char *)&v19 + v16) = 0;
    }
    v16 += 4;
    --v14;
  }
  while ( v14 != 0 );
  return &data[v10][4 * v19 * size + 4 * HIDWORD(v19)];
}


// ========================================================================
// ?R_FilterCube@@YAXHQAPAEH@Z
// EA  : 0x828C9F88
// RVA : 0x008C9F88
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall R_FilterCube(int size, unsigned __int8 **data, int filterSize)
{
  unsigned int v5; // r29
  _DWORD *v6; // r31
  int v7; // r28
  int i; // r30
  void *v9; // r3
  const void *v10; // r4
  __int64 v11; // r7
  double v12; // fp4
  double v13; // fp2
  double v14; // fp3
  _BYTE v15[12]; // r11
  int v16; // r14
  int v17; // r17
  double v18; // fp5
  int v19; // r21
  int v20; // r23
  int v21; // r19
  double v22; // fp30
  double v23; // fp29
  int v24; // r30
  int v25; // r29
  int v26; // r28
  int v27; // r27
  signed int v28; // r26
  int v29; // r18
  int v30; // r31
  double v31; // fp1
  double v32; // fp31
  unsigned __int8 *v33; // r3
  unsigned __int8 *v34; // r3
  idMem *v35; // r29
  int v36; // r31
  void **v37; // r30
  int v38; // [sp+50h] [-150h]
  int v39; // [sp+54h] [-14Ch]
  unsigned __int8 **v40; // [sp+58h] [-148h] BYREF
  idVec3 *v41; // [sp+5Ch] [-144h]
  int v42; // [sp+64h] [-13Ch]
  idMem *v43; // [sp+68h] [-138h]
  int v44; // [sp+70h] [-130h] BYREF
  int v45; // [sp+74h] [-12Ch] BYREF
  _DWORD v46[8]; // [sp+78h] [-128h] BYREF
  __int64 v47; // [sp+98h] [-108h]
  __int64 v48; // [sp+A0h] [-100h]
  unsigned __int64 v49; // [sp+A8h] [-F8h]
  __int64 v50; // [sp+B0h] [-F0h]
  __int64 v51; // [sp+B8h] [-E8h]
  __int64 v52; // [sp+C0h] [-E0h]
  __int64 v53; // [sp+C8h] [-D8h] BYREF
  _BYTE v54[32]; // [sp+D0h] [-D0h] BYREF

  v45 = 1;
  v46[1] = 1;
  v46[6] = 1;
  v46[0] = 2;
  v46[3] = 2;
  v46[4] = 2;
  v44 = 0;
  v46[2] = 0;
  v46[5] = 0;
  v43 = &mem;
  v5 = 4 * size * size;
  v6 = v54;
  v7 = (char *)data - v54;
  for ( i = 6; i != 0; --i )
  {
    v9 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\renderer\\ImageTools\\Image_process.cpp(731) : TAG_IMAGE",
           size: v5,
           tag: TAG_IMAGE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    v10 = *(const void **)((char *)v6 + v7);
    *v6 = v9;
    memcpy(Dst: v9, Src: v10, Size: v5);
    ++v6;
  }
  v38 = 0;
  v12 = 1.0;
  v13 = 2.0;
  v14 = 0.5;
  do
  {
    *(_DWORD *)&v15[4] = v38;
    v39 = -1;
    *(_DWORD *)v15 = 4 * *(int *)((char *)&v44 + v38);
    v42 = *(_DWORD *)v15;
    do
    {
      v16 = 0;
      LODWORD(v11) = v39;
      v52 = v11;
      *(float *)((char *)&v40 + *(_DWORD *)v15) = (float)v11;
      if ( size > 0 )
      {
        *(_DWORD *)&v15[8] = size;
        *(_DWORD *)v15 = v46;
        v50 = *(_QWORD *)&v15[4];
        v17 = -filterSize;
        v18 = (float)*(__int64 *)&v15[4];
        v19 = *(_DWORD *)((char *)v46 + *(_DWORD *)&v15[4]);
        v20 = *(_DWORD *)((char *)&v46[-1] + *(_DWORD *)&v15[4]);
        do
        {
          *(_DWORD *)&v15[8] = v16;
          v21 = 0;
          v47 = *(_QWORD *)&v15[4];
          v22 = (float)*(__int64 *)&v15[4];
          v23 = (float)((float)((float)((float)((float)*(__int64 *)&v15[4] + (float)v14) * (float)v13) / (float)v18)
                      - (float)v12);
          do
          {
            v24 = 0;
            v25 = 0;
            v26 = 0;
            v27 = 0;
            v28 = 0;
            v29 = -filterSize;
            if ( v17 <= filterSize )
            {
              do
              {
                v30 = -filterSize;
                if ( v17 <= filterSize )
                {
                  *(_DWORD *)&v15[4] = v21;
                  v53 = *(_QWORD *)v15;
                  v49 = __PAIR64__(v21, v29);
                  v28 += filterSize + filterSize + 1;
                  v31 = (float)*(__int64 *)v15;
                  v32 = (float)((float)((float)((float)__SPAIR64__(v21, v29) + (float)v22) + (float)v14) * (float)v13);
                  do
                  {
                    *(_DWORD *)&v15[8] = v30;
                    v51 = *(_QWORD *)&v15[4];
                    *(float *)&(&v40)[v20] = (float)((float)v32 / (float)v18) - (float)v12;
                    *(float *)&(&v40)[v19] = (float)((float)((float)((float)((float)*(__int64 *)&v15[4] + (float)v31)
                                                                   + (float)v14)
                                                           * (float)v13)
                                                   / (float)v18)
                                           - (float)v12;
                    v33 = R_CubeTexel(size, data: v40, dir: v41);
                    *(_DWORD *)v15 = v33[1];
                    ++v30;
                    v24 += *v33;
                    *(_DWORD *)&v15[4] = v33[2];
                    v25 += *(_DWORD *)v15;
                    v26 += *(_DWORD *)&v15[4];
                    v27 += v33[3];
                  }
                  while ( v30 <= filterSize );
                }
                ++v29;
              }
              while ( v29 <= filterSize );
            }
            *(_DWORD *)&v15[8] = v21;
            *(float *)&(&v40)[v20] = v23;
            v48 = *(_QWORD *)&v15[4];
            *(float *)&(&v40)[v19] = (float)((float)((float)((float)*(__int64 *)&v15[4] + (float)v14) * (float)v13)
                                           / (float)v18)
                                   - (float)v12;
            v34 = R_CubeTexel(size, data: v40, dir: v41);
            v34[1] = v25 / v28;
            *v34 = v24 / v28;
            HIDWORD(v11) = v28 & ~(__ROL4__(v24, 1) - 1);
            *(_DWORD *)v15 = v26 / v28;
            *(_DWORD *)&v15[4] = v27 / v28;
            ++v21;
            v34[2] = v26 / v28;
            __twllei(v28, 0);
            v34[3] = v27 / v28;
            __twllei(v28, 0);
            __twllei(v28, 0);
            __twllei(v28, 0);
            __twlgei(HIDWORD(v11), 0xFFFFFFFF);
            __twlgei(v28 & ~(__ROL4__(v25, 1) - 1), 0xFFFFFFFF);
            __twlgei(v28 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
            __twlgei(v28 & ~(__ROL4__(v27, 1) - 1), 0xFFFFFFFF);
          }
          while ( v21 < size );
          ++v16;
        }
        while ( v16 < size );
        *(_DWORD *)&v15[4] = v38;
        *(_DWORD *)v15 = v42;
      }
      v39 += 2;
    }
    while ( v39 <= 1 );
    v38 = *(_DWORD *)&v15[4] + 12;
  }
  while ( *(_DWORD *)&v15[4] + 12 < 36 );
  v35 = v43;
  v36 = 6;
  v37 = (void **)&v53 + 1;
  do
  {
    idMem::Free(this: v35, ptr: *++v37, align: ALIGN_16);
    --v36;
  }
  while ( v36 != 0 );
}


// ========================================================================
// ?R_BlendCubeBorders@@YAXHQAPAE@Z
// EA  : 0x828CA340
// RVA : 0x008CA340
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall R_BlendCubeBorders(int size, unsigned __int8 **data)
{
  __int64 v3; // r11
  double v4; // fp2
  double v5; // fp4
  int v6; // r29
  int v7; // r24
  int v8; // r22
  int v9; // r26
  double v10; // fp31
  int v11; // r27
  double v12; // fp5
  unsigned __int8 *v13; // r31
  unsigned __int8 *v14; // r3
  int v15; // r7
  int v16; // r28
  double v17; // fp3
  int *v18; // r11
  int *v19; // r10
  int v20; // r7
  int v21; // r28
  unsigned __int8 *v22; // r3
  double v23; // fp3
  int v24; // r7
  int v25; // r28
  double v26; // fp1
  unsigned __int8 v27; // r9
  unsigned __int8 v28; // r6
  unsigned __int8 v29; // r10
  unsigned __int8 v30; // r7
  unsigned __int8 **v31; // [sp+68h] [-B8h] BYREF
  idVec3 *v32; // [sp+6Ch] [-B4h]
  int v33; // [sp+80h] [-A0h] BYREF
  int v34; // [sp+84h] [-9Ch] BYREF
  _DWORD v35[16]; // [sp+88h] [-98h] BYREF

  v34 = 1;
  v35[1] = 1;
  v35[6] = 1;
  HIDWORD(v3) = &off_82230000;
  v4 = -0.99989998;
  v5 = 0.99989998;
  v35[0] = 2;
  v35[3] = 2;
  v35[4] = 2;
  v33 = 0;
  v6 = 0;
  v35[2] = 0;
  v35[5] = 0;
  do
  {
    v7 = -1;
    v8 = *(int *)((char *)&v33 + v6 * 4);
    do
    {
      LODWORD(v3) = v7;
      v9 = 0;
      *(float *)&(&v31)[v8] = (float)v3;
      if ( size <= 0 )
        goto LABEL_18;
      LODWORD(v3) = size;
      v10 = (float)v3;
      do
      {
        LODWORD(v3) = v9;
        v11 = 0;
        v12 = (float)((float)((float)((float)((float)v3 + (float)0.5) * (float)2.0) / (float)v10) - (float)1.0);
        do
        {
          v13 = nullptr;
          v14 = nullptr;
          if ( (unsigned int)v11 > 3 )
            goto LABEL_16;
          switch ( v11 )
          {
            case 1:
              v18 = &v34;
              v19 = v35;
LABEL_14:
              v24 = v19[v6];
              v25 = v18[v6];
              *(float *)&(&v31)[v25] = v4;
              *(float *)&(&v31)[v24] = v12;
              v22 = R_CubeTexel(size, data: v31, dir: v32);
              *(float *)&(&v31)[v25] = v26;
              break;
            case 2:
              v20 = v35[v6 - 1];
              v21 = v35[v6];
              *(float *)&(&v31)[v21] = v5;
              *(float *)&(&v31)[v20] = v12;
              v22 = R_CubeTexel(size, data: v31, dir: v32);
              *(float *)&(&v31)[v21] = v23;
              break;
            case 0:
              v15 = v35[v6];
              v16 = v35[v6 - 1];
              *(float *)&(&v31)[v16] = v5;
              *(float *)&(&v31)[v15] = v12;
              v22 = R_CubeTexel(size, data: v31, dir: v32);
              *(float *)&(&v31)[v16] = v17;
              break;
            default:
              v18 = v35;
              v19 = &v34;
              goto LABEL_14;
          }
          v13 = v22;
          v14 = R_CubeTexel(size, data: v31, dir: v32);
LABEL_16:
          ++v11;
          v27 = (*v14 + *v13) >> 1;
          *v14 = v27;
          *v13 = v27;
          v28 = (v13[1] + v14[1]) >> 1;
          v14[1] = v28;
          v13[1] = v28;
          v29 = (v13[2] + v14[2]) >> 1;
          v14[2] = v29;
          v13[2] = v29;
          HIDWORD(v3) = v14[3];
          v30 = (v13[3] + HIDWORD(v3)) >> 1;
          v14[3] = v30;
          v13[3] = v30;
        }
        while ( v11 < 4 );
        ++v9;
      }
      while ( v9 < size );
LABEL_18:
      v7 += 2;
    }
    while ( v7 <= 1 );
    v6 += 3;
  }
  while ( v6 < 9 );
}


// ========================================================================
// ?WriteGammaTable_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828CA600
// RVA : 0x008CA600
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall WriteGammaTable_f(const idCmdArgs *args, double a2, double a3, long double a4)
{
  __int64 v4; // r11
  float *v5; // r30
  int i; // r31
  long double v7; // fp2
  long double v8; // fp2
  int v9; // r31
  int v10; // r6
  const char *v11; // r3
  _BYTE v12[1036]; // [sp+5Ch] [-454h] BYREF

  HIDWORD(v4) = &off_82230000;
  v5 = (float *)v12;
  for ( i = 0; i < 256; ++i )
  {
    LODWORD(v4) = i;
    *((double *)&v7 + 1) = 2.200000047683716;
    *(double *)&v7 = (float)((float)v4 * (float)0.0039215689);
    v8 = pow(x: v7, y: a4);
    *++v5 = (float)*(double *)&v8 * (float)255.0;
  }
  idLib::Printf(fmt: "const float gamma2_2[256] = {\n");
  v9 = 0;
  v10 = 0;
  do
  {
    idLib::Printf(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v12[v10 + 4])),
      (unsigned int)COERCE_UNSIGNED_INT64(*(float *)&v12[v10 + 4]));
    v11 = ", ";
    if ( v9 == 255 )
      v11 = " };";
    idLib::Printf(fmt: v11);
    if ( (v9 & 7) == 7 )
      idLib::Printf(fmt: "\n");
    ++v9;
    v10 = 4 * v9;
  }
  while ( v9 < 256 );
}


// ========================================================================
// ?TestGammaTable_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828CA710
// RVA : 0x008CA710
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

void __fastcall TestGammaTable_f(const idCmdArgs *args, double a2, double a3, long double a4)
{
  int v4; // r31
  float *v5; // r30
  double v6; // fp0
  unsigned __int8 v7; // r11
  long double v8; // fp2
  long double v9; // fp2

  v4 = 0;
  v5 = (float *)gamma2_2;
  do
  {
    v6 = *v5;
    if ( v6 < 255.0 )
    {
      if ( v6 > 0.0 )
      {
        *((double *)&v8 + 1) = 0.4545454446934474;
        *(double *)&v8 = (float)(v6 * 0.00392156862745098);
        v9 = pow(x: v8, y: a4);
        v7 = (int)(float)((float)((float)*(double *)&v9 * (float)255.0) + (float)0.5);
      }
      else
      {
        v7 = 0;
      }
    }
    else
    {
      v7 = -1;
    }
    if ( v7 != v4 )
      idLib::Printf(fmt: "inverse of %i == %i\n", v4, v7);
    ++v5;
    ++v4;
  }
  while ( (int)v5 < (int)&gamma2_2[255] );
}


// ========================================================================
// `dynamic initializer for 'WriteGammaTable_v''
// EA  : 0x8334C068
// RVA : 0x0134C068
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__WriteGammaTable_v__()
{
  return idCommandLink::idCommandLink(
           this: &WriteGammaTable_v,
           cmdName: "WriteGammaTable",
           function: (void (__fastcall *)(const idCmdArgs *))WriteGammaTable_f,
           description: "Writes the static code for the 2.2 gamma table",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestGammaTable_v''
// EA  : 0x8334C090
// RVA : 0x0134C090
// PDB : w:\tech5\engine\renderer\imagetools\image_process.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestGammaTable_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestGammaTable_v,
           cmdName: "TestGammaTable",
           function: (void (__fastcall *)(const idCmdArgs *))TestGammaTable_f,
           description: "Checks for perfect inversion",
           argCompletion: nullptr);
}

