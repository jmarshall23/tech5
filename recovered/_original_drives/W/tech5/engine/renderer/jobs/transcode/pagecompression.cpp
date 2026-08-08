
// ========================================================================
// ?DCT_Compress@@YAHPBXHPAXH_N2AAUcompressionStats_t@@@Z
// EA  : 0x82927F40
// RVA : 0x00927F40
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall DCT_Compress(
        const unsigned __int8 *src,
        int length,
        unsigned __int8 *dest,
        int maxDestLength,
        bool storeCover,
        bool storeAlpha,
        compressionStats_t *stats)
{
  char *v9; // r30
  const unsigned __int8 *v10; // r20
  unsigned __int8 *v11; // r27
  void *v12; // r17
  __int64 v13; // r19
  unsigned __int8 *v14; // r15
  int i; // r5
  int v16; // r7
  int j; // ctr
  int v18; // r8
  unsigned __int8 *v19; // r6
  int v20; // r3
  unsigned __int8 *v21; // r11
  int v22; // r29
  unsigned __int8 *v23; // r10
  signed int v24; // r9
  int v25; // r8
  int v26; // r29
  int v27; // r8
  unsigned int v28; // r4
  unsigned int v29; // r9
  int v30; // r8
  unsigned int v31; // r4
  signed int v32; // r9
  int v33; // r29
  int v34; // r8
  unsigned int v35; // r4
  int v36; // r28
  int v37; // r8
  int v38; // r29
  unsigned int v39; // r4
  unsigned int v40; // r26
  signed int v41; // r9
  int v42; // r3
  int v43; // r29
  int v44; // r8
  int v45; // r3
  int v46; // r4
  int v47; // r3
  unsigned int v48; // r8
  unsigned int v49; // r4
  unsigned int v50; // r9
  signed int v51; // r9
  int v52; // r8
  unsigned int v53; // r4
  int v54; // r3
  unsigned int v55; // r6
  int k; // r23
  int m; // r24
  int v58; // r4
  int v59; // r26
  int n; // r25
  int v61; // r10
  int v62; // r3
  int ii; // ctr
  int v64; // r11
  unsigned __int8 *v65; // r11
  int v66; // r9
  int v67; // r8
  int v68; // r7
  int v69; // r6
  int v70; // r5
  int v71; // r11
  int v72; // r30
  int v73; // r29
  int v74; // r11
  int jj; // r7
  int v76; // r8
  int kk; // ctr
  unsigned __int8 *v78; // r9
  int v79; // r6
  int v80; // r6
  char v81; // r30
  int mm; // r10
  int v83; // r11
  const unsigned __int8 *v84; // r8
  int nn; // ctr
  int i1; // r7
  int v87; // r10
  int i2; // ctr
  unsigned int v89; // r3
  int valueInteger_low; // r28
  int v91; // r26
  int v92; // r22
  int v93; // r30
  int v94; // r29
  unsigned __int8 valueInteger; // r23
  int v96; // r6
  unsigned __int16 v97; // r26
  int v98; // r5
  int v99; // r4
  unsigned __int8 *v100; // r30
  unsigned __int8 *v101; // r30
  unsigned __int16 v102; // r25
  unsigned __int8 *v103; // r30
  unsigned __int8 *v104; // r20
  int v105; // r2 OVERLAPPED
  unsigned __int16 v106; // r23
  unsigned __int8 *v107; // r30
  __int128 v108; // r6 OVERLAPPED
  unsigned __int64 coverBytes; // r8 OVERLAPPED
  int v110; // r11
  unsigned __int64 wastedBytes; // r10
  int v112; // r28
  unsigned __int64 specularBytes; // r25
  int v115[3]; // [sp+54h] [-38FCh] BYREF
  __int128 v116; // [sp+60h] [-38F0h]
  int v117; // [sp+70h] [-38E0h] BYREF
  int v118; // [sp+74h] [-38DCh] BYREF
  int v119; // [sp+78h] [-38D8h] BYREF
  unsigned __int8 *v120; // [sp+7Ch] [-38D4h]
  int v121[4]; // [sp+80h] [-38D0h] BYREF
  idBareDctEncoder v122; // [sp+90h] [-38C0h] BYREF

  v9 = (char *)(src + 0x20000);
  v10 = src + 0x10000;
  v11 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(103) : TAG_VIRTUALTEXTURE",
                             size: 0x10000u,
                             tag: TAG_VIRTUALTEXTURE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v120 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(104) : TAG_VIRTUALTEXTURE",
                              size: 0x400u,
                              tag: TAG_VIRTUALTEXTURE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v12 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(105) : TAG_VIRTUALTEXTURE",
          size: 0x800u,
          tag: TAG_VIRTUALTEXTURE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  LODWORD(v13) = 0;
  v14 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(106) : TAG_VIRTUALTEXTURE",
                             size: 0x4000u,
                             tag: TAG_VIRTUALTEXTURE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  for ( i = 0; i < 0x4000; i += 128 )
  {
    v16 = 0;
    for ( j = 32; j != 0; --j )
    {
      v18 = 4 * (i + v16);
      v19 = (unsigned __int8 *)&v10[v18];
      v20 = 4 * (i + v16 + 2);
      v21 = (unsigned __int8 *)&v9[v18];
      v22 = (unsigned __int8)v9[v18];
      v23 = &v11[v18];
      v24 = (v10[v18 + 2] >> 3) + 1;
      v11[v18] = v22 / v24;
      __twllei(v24, 0);
      v25 = (unsigned __int8)v9[v18 + 1];
      __twlgei(v24 & ~(__ROL4__(v22, 1) - 1), 0xFFFFFFFF);
      v23[1] = v25 / v24;
      __twllei(v24, 0);
      v26 = __ROL4__(v25, 1) - 1;
      v27 = v21[2];
      v23[2] = v27 / v24;
      v28 = v24 & ~v26;
      v23[3] = v21[3];
      __twllei(v24, 0);
      v29 = v24 & ~(__ROL4__(v27, 1) - 1);
      v30 = v21[4];
      __twlgei(v28, 0xFFFFFFFF);
      v31 = v19[6];
      __twlgei(v29, 0xFFFFFFFF);
      v32 = (v31 >> 3) + 1;
      v23[4] = v30 / v32;
      __twllei(v32, 0);
      v33 = __ROL4__(v30, 1) - 1;
      v34 = v21[5];
      v23[5] = v34 / v32;
      v35 = v32 & ~v33;
      v36 = __ROL4__(v34, 1) - 1;
      v37 = v21[6];
      v23[6] = v37 / v32;
      v23[7] = v21[7];
      __twlgei(v32 & ~v36, 0xFFFFFFFF);
      v38 = (unsigned __int8)v9[v20];
      __twlgei(v35, 0xFFFFFFFF);
      v39 = v19[10];
      v40 = v32 & ~(__ROL4__(v37, 1) - 1);
      __twllei(v32, 0);
      __twllei(v32, 0);
      v41 = (v39 >> 3) + 1;
      v11[v20] = v38 / v41;
      __twlgei(v40, 0xFFFFFFFF);
      v42 = v21[9];
      __twllei(v41, 0);
      __twlgei(v41 & ~(__ROL4__(v38, 1) - 1), 0xFFFFFFFF);
      __twllei(v41, 0);
      v23[9] = v42 / v41;
      __twllei(v41, 0);
      v43 = 4 * (i + v16 + 3);
      v44 = __ROL4__(v42, 1);
      v45 = v21[10];
      v23[10] = v45 / v41;
      v46 = __ROL4__(v45, 1);
      v23[11] = v21[11];
      v47 = (unsigned __int8)v9[v43];
      v48 = v41 & ~(v44 - 1);
      v49 = v41 & ~(v46 - 1);
      v50 = v19[14];
      __twlgei(v48, 0xFFFFFFFF);
      __twlgei(v49, 0xFFFFFFFF);
      v16 += 4;
      v51 = (v50 >> 3) + 1;
      v11[v43] = v47 / v51;
      __twllei(v51, 0);
      v52 = v21[13];
      v23[13] = v52 / v51;
      v53 = v51 & ~(__ROL4__(v47, 1) - 1);
      v54 = v21[14];
      v55 = v51 & ~(__ROL4__(v52, 1) - 1);
      __twllei(v51, 0);
      v23[14] = v54 / v51;
      __twllei(v51, 0);
      LOBYTE(v52) = v21[15];
      __twlgei(v53, 0xFFFFFFFF);
      v23[15] = v52;
      __twlgei(v55, 0xFFFFFFFF);
      __twlgei(v51 & ~(__ROL4__(v54, 1) - 1), 0xFFFFFFFF);
    }
  }
  BYTE3(v13) = 1;
  for ( k = 0; k < 0x4000; k += 512 )
  {
    for ( m = 0; m < 128; m += 4 )
    {
      v58 = 0;
      v59 = k + m;
      for ( n = 4; n != 0; --n )
      {
        v61 = 0;
        v62 = 0;
        for ( ii = 2; ii != 0; --ii )
        {
          v64 = 4 * (v59 + v61);
          v61 += 2;
          v65 = &v11[v64];
          v66 = v65[1];
          v67 = v65[2];
          v68 = *v65;
          v69 = v65[5];
          v70 = v65[6];
          v71 = v65[4];
          v72 = (2 * (v67 + v66 + v68) + 3) / 6;
          v73 = (2 * (v70 + v69 + v71) + 3) / 6;
          v58 += (v68 - v72) * (v68 - v72) + (v66 - v72) * (v66 - v72) + (v67 - v72) * (v67 - v72);
          v62 += (v71 - v73) * (v71 - v73) + (v69 - v73) * (v69 - v73) + (v70 - v73) * (v70 - v73);
        }
        v58 += v62;
        v59 += 128;
      }
      BYTE3(v13) &= __CFADD__(
                      vt_maxMonoSpecularError.valueInteger * vt_maxMonoSpecularError.valueInteger - v58 / 16,
                      (v58 / 16) ^ 0x80000000)
                  - 1;
    }
  }
  v74 = 0;
  for ( jj = 0; jj < 0x4000; jj += 128 )
  {
    v76 = 0;
    for ( kk = 32; kk != 0; --kk )
    {
      v78 = &v11[4 * jj + 4 * v76];
      if ( *v78 > v74 )
        v74 = *v78;
      if ( v78[1] > v74 )
        v74 = v78[1];
      if ( v78[2] > v74 )
        v74 = v78[2];
      if ( v78[4] > v74 )
        v74 = v78[4];
      if ( v78[5] > v74 )
        v74 = v78[5];
      if ( v78[6] > v74 )
        v74 = v78[6];
      v79 = 4 * (jj + v76 + 2);
      if ( v11[v79] > v74 )
        v74 = v11[v79];
      if ( v78[9] > v74 )
        v74 = v78[9];
      if ( v78[10] > v74 )
        v74 = v78[10];
      v80 = 4 * (jj + v76 + 3);
      if ( v11[v80] > v74 )
        v74 = v11[v80];
      if ( v78[13] > v74 )
        v74 = v78[13];
      if ( v78[14] > v74 )
        v74 = v78[14];
      v76 += 4;
    }
  }
  v81 = 0;
  if ( vt_useSpecularScale.valueInteger != 0 )
  {
    if ( v74 >= 64 )
      v81 = v74 < 128;
    else
      v81 = 2;
  }
  for ( mm = 0; mm < 4096; mm += 128 )
  {
    v83 = 0;
    v84 = &v120[mm / 4];
    for ( nn = 32; nn != 0; --nn )
    {
      v84[v83] = v10[16 * mm + 16 * v83];
      ++v83;
    }
  }
  memset(Dst: v12, Val: 0, Size: 0x800u);
  for ( i1 = 0; i1 < 0x4000; i1 += 128 )
  {
    v87 = 0;
    for ( i2 = 128; i2 != 0; --i2 )
    {
      v89 = v11[4 * i1 + 3 + 4 * v87];
      *((_BYTE *)v12 + ((i1 + v87) >> 3)) |= (v89 >= 0x80) << ((i1 + v87) & 7);
      v14[i1 + v87++] = v89;
    }
  }
  HIDWORD(v13) = BYTE3(v13);
  *((_QWORD *)&v116 + 1) = v13;
  valueInteger_low = LOBYTE(vt_qualityDCTLuma.valueInteger);
  v91 = LOBYTE(vt_qualityDCTChroma.valueInteger);
  HIBYTE(v116) = vt_qualityDCTLuma.valueInteger;
  v92 = v81 & 3 | (!storeCover ? 0 : 8) | (BYTE3(v13) == 0 ? 0 : 4);
  BYTE1(v116) = vt_qualityDCTChroma.valueInteger;
  v94 = LOBYTE(vt_qualityDCTSpecular.valueInteger);
  BYTE5(v116) = v81 & 3 | (!storeCover ? 0 : 8) | (BYTE3(v13) == 0 ? 0 : 4);
  v93 = LOBYTE(vt_qualityDCTNormal.valueInteger);
  valueInteger = vt_qualityDCTPower.valueInteger;
  BYTE2(v116) = vt_qualityDCTNormal.valueInteger;
  BYTE3(v116) = vt_qualityDCTSpecular.valueInteger;
  BYTE4(v116) = vt_qualityDCTPower.valueInteger;
  idBareDctEncoder::idBareDctEncoder(this: &v122);
  idBareDctBase::SetQuality_Xenon(
    this: &v122,
    luminanceQuality: valueInteger_low,
    chrominanceQuality: v91,
    alphaQuality: valueInteger_low);
  v119 = 0;
  idBareDctEncoder::CompressImageYCoCg_Generic(
    this: &v122,
    inBuf: src,
    outBuf: dest + 16,
    width: 128,
    height: 128,
    outputBytes: &v119);
  v96 = v93;
  v97 = v119;
  v98 = v93;
  v99 = v93;
  WORD3(v116) = v119;
  v100 = &dest[(unsigned __int16)v119 + 16];
  idBareDctBase::SetQuality_Xenon(this: &v122, luminanceQuality: v99, chrominanceQuality: v98, alphaQuality: v96);
  v118 = 0;
  idBareDctEncoder::CompressImageNormalMap_Generic(
    this: &v122,
    inBuf: v10,
    outBuf: v100,
    width: 128,
    height: 128,
    outputBytes: &v118);
  WORD4(v116) = v118;
  v101 = &v100[(unsigned __int16)v118];
  idBareDctBase::SetQuality_Xenon(this: &v122, luminanceQuality: v94, chrominanceQuality: v94, alphaQuality: v94);
  v115[0] = 0;
  if ( BYTE3(v13) != 0 )
    idBareDctEncoder::CompressImageGrayScale_Generic(
      this: &v122,
      inBuf: v11,
      outBuf: v101,
      width: 128,
      height: 128,
      outputBytes: v115);
  else
    idBareDctEncoder::CompressImageRGB_Generic(
      this: &v122,
      inBuf: v11,
      outBuf: v101,
      width: 128,
      height: 128,
      outputBytes: v115);
  v102 = v115[0];
  WORD5(v116) = v115[0];
  v103 = &v101[LOWORD(v115[0])];
  idBareDctBase::SetQuality_Xenon(
    this: &v122,
    luminanceQuality: valueInteger,
    chrominanceQuality: valueInteger,
    alphaQuality: valueInteger);
  v117 = 0;
  v104 = v120;
  idBareDctEncoder::CompressImageMono_Generic(
    this: &v122,
    inBuf: v120,
    outBuf: v103,
    width: 32,
    height: 32,
    outputBytes: &v117);
  v106 = v117;
  WORD6(v116) = v117;
  v107 = &v103[(unsigned __int16)v117];
  if ( storeCover )
  {
    memcpy(Dst: v107, Src: v12, Size: 0x800u);
    v107 += 2048;
  }
  if ( storeAlpha )
  {
    idBareDctBase::SetQuality_Xenon(
      this: &v122,
      luminanceQuality: valueInteger_low,
      chrominanceQuality: valueInteger_low,
      alphaQuality: valueInteger_low);
    v121[0] = 0;
    idBareDctEncoder::CompressImageMono_Generic(
      this: &v122,
      inBuf: v14,
      outBuf: v107,
      width: 128,
      height: 128,
      outputBytes: v121);
    LOWORD(v116) = v121[0];
    v107 += LOWORD(v121[0]);
  }
  else
  {
    LOWORD(v116) = 0;
  }
  *((_QWORD *)&v108 + 1) = stats->powerBytes;
  coverBytes = stats->coverBytes;
  v110 = stats->diskOffsetScale - ((stats->diskOffsetScale - 1) & (v107 - dest));
  wastedBytes = stats->wastedBytes;
  DWORD2(v108) += LODWORD(stats->normalBytes);
  DWORD1(v108) = v97 + LODWORD(stats->diffuseBytes);
  v112 = v102;
  specularBytes = stats->specularBytes;
  stats->normalBytes = *(_QWORD *)((char *)&v108 + 4);
  HIDWORD(v108) = v106 + (_DWORD)v108;
  stats->diffuseBytes = *(_QWORD *)&v108;
  HIDWORD(wastedBytes) = ((v92 << 8) & 0x800) + coverBytes;
  stats->powerBytes = *(_QWORD *)(&v105 - 1);
  LODWORD(coverBytes) = v110 + wastedBytes;
  HIDWORD(coverBytes) = HIDWORD(specularBytes) + 16;
  stats->coverBytes = *(unsigned __int64 *)((char *)&coverBytes - 4);
  LODWORD(v108) = v112 + specularBytes;
  stats->wastedBytes = coverBytes;
  stats->headerBytes = *(_QWORD *)((char *)&v108 - 4);
  DWORD2(v108) = 16;
  stats->specularBytes = v108;
  *(_OWORD *)dest = v116;
  idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v104, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v122);
  return v107 - dest;
}


// ========================================================================
// __unwind$235616
// EA  : 0x829288F0
// RVA : 0x009288F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void _unwind_235616()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 14672 + 144));
}


// ========================================================================
// ?HDP_Compress@@YAHPBXHPAXH_N2AAUcompressionStats_t@@@Z
// EA  : 0x82928920
// RVA : 0x00928920
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall HDP_Compress(
        char *src,
        int length,
        unsigned __int8 *dest,
        unsigned int maxDestLength,
        bool storeCover,
        bool storeAlpha,
        compressionStats_t *stats)
{
  char *v8; // r30
  unsigned __int8 *v9; // r16
  char *v10; // r17
  unsigned __int8 *v11; // r27
  __int64 v12; // r19
  int i; // r5
  int v14; // r7
  int j; // ctr
  int v16; // r8
  unsigned __int8 *v17; // r6
  int v18; // r3
  unsigned __int8 *v19; // r11
  int v20; // r29
  unsigned __int8 *v21; // r10
  signed int v22; // r9
  int v23; // r8
  int v24; // r29
  int v25; // r8
  unsigned int v26; // r4
  unsigned int v27; // r9
  int v28; // r8
  unsigned int v29; // r4
  signed int v30; // r9
  int v31; // r29
  int v32; // r8
  unsigned int v33; // r4
  int v34; // r28
  int v35; // r8
  int v36; // r29
  unsigned int v37; // r4
  unsigned int v38; // r26
  signed int v39; // r9
  int v40; // r3
  int v41; // r29
  int v42; // r8
  int v43; // r3
  int v44; // r4
  int v45; // r3
  unsigned int v46; // r8
  unsigned int v47; // r4
  unsigned int v48; // r9
  signed int v49; // r9
  int v50; // r8
  unsigned int v51; // r4
  int v52; // r3
  unsigned int v53; // r6
  unsigned __int8 v54; // r22
  int v55; // r21
  int k; // r23
  int m; // r24
  int v58; // r4
  int v59; // r26
  int n; // r25
  int v61; // r10
  int v62; // r3
  int ii; // ctr
  int v64; // r11
  unsigned __int8 *v65; // r11
  int v66; // r9
  int v67; // r8
  int v68; // r7
  int v69; // r6
  int v70; // r5
  int v71; // r11
  int v72; // r30
  int v73; // r29
  int v74; // r9
  int v75; // r7
  int v76; // r11
  int v77; // r7
  int v78; // r21
  int v79; // r4
  int valueInteger; // r7
  double valueFloat; // fp0
  int v82; // r5
  int jj; // ctr
  int v84; // r3
  unsigned __int8 *v85; // r11
  __int64 v86; // r10
  double v87; // fp12
  __int64 v88; // r10
  __int64 v89; // r10
  double v90; // fp12
  __int64 v91; // r10
  int v92; // r8
  __int64 v93; // r10
  double v94; // fp9
  __int64 v95; // r10
  int v96; // r8
  __int64 v97; // r10
  double v98; // fp12
  __int64 v99; // r10
  int v100; // r8
  __int64 v101; // r10
  __int64 v102; // r10
  int v103; // r8
  __int64 v104; // r10
  __int64 v105; // r10
  int v106; // r8
  __int64 v107; // r10
  __int64 v108; // r10
  int v109; // r8
  __int64 v110; // r10
  __int64 v111; // r10
  int v112; // r11
  int kk; // r7
  int v114; // r8
  int mm; // ctr
  unsigned __int8 *v116; // r9
  int v117; // r6
  int v118; // r6
  char v119; // r30
  unsigned __int8 *v120; // r7
  int nn; // r10
  int v122; // r11
  int i1; // ctr
  _BYTE *v124; // r29
  unsigned __int8 *v125; // r6
  int i2; // r7
  int v127; // r10
  int i3; // ctr
  unsigned int v129; // r28
  char v130; // r5
  int v131; // r23
  int v132; // r30
  int v133; // r26
  int v134; // r25
  unsigned __int8 v135; // r24
  idBareHDP *v136; // r3
  int v137; // r12
  int v138; // r26
  unsigned __int8 *v139; // r29
  unsigned __int16 v140; // r22
  unsigned __int8 *v141; // r29
  unsigned int v142; // r26
  unsigned __int8 *v143; // r16
  unsigned __int8 *v144; // r29
  unsigned int v145; // r26
  int v146; // r2 OVERLAPPED
  unsigned __int16 v147; // r24
  unsigned __int8 *v148; // r29
  unsigned int v149; // r28
  __int128 v150; // r6 OVERLAPPED
  __int64 v151; // r8 OVERLAPPED
  __int64 v152; // r26
  int v153; // r11
  __int64 v154; // r28
  __int64 v155; // r10
  _DWORD back_chain[20]; // [sp+0h] [-250h]
  int v158; // [sp+50h] [-200h] BYREF
  int v159; // [sp+54h] [-1FCh]
  unsigned __int8 *v160; // [sp+58h] [-1F8h] BYREF
  __int128 v161; // [sp+60h] [-1F0h]
  _BYTE *v162; // [sp+70h] [-1E0h]
  __int64 v163; // [sp+78h] [-1D8h]
  int v164; // [sp+80h] [-1D0h] BYREF
  unsigned __int8 *v165; // [sp+84h] [-1CCh]
  int v166; // [sp+88h] [-1C8h] BYREF
  int v167; // [sp+8Ch] [-1C4h] BYREF
  int v168; // [sp+90h] [-1C0h] BYREF
  __int64 v169; // [sp+98h] [-1B8h]
  __int64 v170; // [sp+A0h] [-1B0h]
  __int64 v171; // [sp+A8h] [-1A8h]
  __int64 v172; // [sp+B0h] [-1A0h]
  __int64 v173; // [sp+B8h] [-198h]
  __int64 v174; // [sp+C0h] [-190h]
  __int64 v175; // [sp+C8h] [-188h]
  __int64 v176; // [sp+D0h] [-180h]
  __int64 v177; // [sp+D8h] [-178h]
  __int64 v178; // [sp+E0h] [-170h]
  __int64 v179; // [sp+E8h] [-168h]
  __int64 v180; // [sp+F0h] [-160h]
  __int64 v181; // [sp+F8h] [-158h]
  __int64 v182; // [sp+100h] [-150h]
  idBareHDP v183; // [sp+110h] [-140h] BYREF

  HIDWORD(v12) = stats;
  v8 = src + 0x20000;
  v9 = (unsigned __int8 *)(src + 0x10000);
  v10 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(277) : TAG_VIRTUALTEXTURE",
                  size: 0x10000u,
                  tag: TAG_VIRTUALTEXTURE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v11 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(278) : TAG_VIRTUALTEXTURE",
                             size: 0x10000u,
                             tag: TAG_VIRTUALTEXTURE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v160 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(279) : TAG_VIRTUALTEXTURE",
                              size: 0x400u,
                              tag: TAG_VIRTUALTEXTURE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v162 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(280) : TAG_VIRTUALTEXTURE",
           size: 0x800u,
           tag: TAG_VIRTUALTEXTURE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
  LODWORD(v12) = 0;
  v165 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(281) : TAG_VIRTUALTEXTURE",
                              size: 0x4000u,
                              tag: TAG_VIRTUALTEXTURE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  for ( i = 0; i < 0x4000; i += 128 )
  {
    v14 = 0;
    for ( j = 32; j != 0; --j )
    {
      v16 = 4 * (i + v14);
      v17 = &v9[v16];
      v18 = 4 * (i + v14 + 2);
      v19 = (unsigned __int8 *)&v8[v16];
      v20 = (unsigned __int8)v8[v16];
      v21 = &v11[v16];
      v22 = (v9[v16 + 2] >> 3) + 1;
      v11[v16] = v20 / v22;
      __twllei(v22, 0);
      v23 = (unsigned __int8)v8[v16 + 1];
      __twlgei(v22 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
      v21[1] = v23 / v22;
      __twllei(v22, 0);
      v24 = __ROL4__(v23, 1) - 1;
      v25 = v19[2];
      v21[2] = v25 / v22;
      v26 = v22 & ~v24;
      v21[3] = v19[3];
      __twllei(v22, 0);
      v27 = v22 & ~(__ROL4__(v25, 1) - 1);
      v28 = v19[4];
      __twlgei(v26, 0xFFFFFFFF);
      v29 = v17[6];
      __twlgei(v27, 0xFFFFFFFF);
      v30 = (v29 >> 3) + 1;
      v21[4] = v28 / v30;
      __twllei(v30, 0);
      v31 = __ROL4__(v28, 1) - 1;
      v32 = v19[5];
      v21[5] = v32 / v30;
      v33 = v30 & ~v31;
      v34 = __ROL4__(v32, 1) - 1;
      v35 = v19[6];
      v21[6] = v35 / v30;
      v21[7] = v19[7];
      __twlgei(v30 & ~v34, 0xFFFFFFFF);
      v36 = (unsigned __int8)v8[v18];
      __twlgei(v33, 0xFFFFFFFF);
      v37 = v17[10];
      v38 = v30 & ~(__ROL4__(v35, 1) - 1);
      __twllei(v30, 0);
      __twllei(v30, 0);
      v39 = (v37 >> 3) + 1;
      v11[v18] = v36 / v39;
      __twlgei(v38, 0xFFFFFFFF);
      v40 = v19[9];
      __twllei(v39, 0);
      __twlgei(v39 & ~(__ROL4__(v36, 1) - 1), 0xFFFFFFFF);
      __twllei(v39, 0);
      v21[9] = v40 / v39;
      __twllei(v39, 0);
      v41 = 4 * (i + v14 + 3);
      v42 = __ROL4__(v40, 1);
      v43 = v19[10];
      v21[10] = v43 / v39;
      v44 = __ROL4__(v43, 1);
      v21[11] = v19[11];
      v45 = (unsigned __int8)v8[v41];
      v46 = v39 & ~(v42 - 1);
      v47 = v39 & ~(v44 - 1);
      v48 = v17[14];
      __twlgei(v46, 0xFFFFFFFF);
      __twlgei(v47, 0xFFFFFFFF);
      v14 += 4;
      v49 = (v48 >> 3) + 1;
      v11[v41] = v45 / v49;
      __twllei(v49, 0);
      v50 = v19[13];
      v21[13] = v50 / v49;
      v51 = v49 & ~(__ROL4__(v45, 1) - 1);
      v52 = v19[14];
      v53 = v49 & ~(__ROL4__(v50, 1) - 1);
      __twllei(v49, 0);
      v21[14] = v52 / v49;
      __twllei(v49, 0);
      LOBYTE(v50) = v19[15];
      __twlgei(v51, 0xFFFFFFFF);
      v21[15] = v50;
      __twlgei(v53, 0xFFFFFFFF);
      __twlgei(v49 & ~(__ROL4__(v52, 1) - 1), 0xFFFFFFFF);
    }
  }
  v54 = 1;
  if ( vt_qualityHDPLossless.valueInteger != 0 )
    v55 = 0;
  else
    v55 = vt_maxMonoSpecularError.valueInteger * vt_maxMonoSpecularError.valueInteger;
  for ( k = 0; k < 0x4000; k += 512 )
  {
    for ( m = 0; m < 128; m += 4 )
    {
      v58 = 0;
      v59 = k + m;
      for ( n = 4; n != 0; --n )
      {
        v61 = 0;
        v62 = 0;
        for ( ii = 2; ii != 0; --ii )
        {
          v64 = 4 * (v59 + v61);
          v61 += 2;
          v65 = &v11[v64];
          v66 = v65[1];
          v67 = v65[2];
          v68 = *v65;
          v69 = v65[5];
          v70 = v65[6];
          v71 = v65[4];
          v72 = (2 * (v67 + v66 + v68) + 3) / 6;
          v73 = (2 * (v70 + v69 + v71) + 3) / 6;
          HIDWORD(v163) = v66 - v72;
          v74 = (v68 - v72) * (v68 - v72);
          v75 = HIDWORD(v163);
          HIDWORD(v163) = v71 - v73;
          v76 = v74 + v75 * v75;
          v77 = HIDWORD(v163);
          HIDWORD(v163) = v69 - v73;
          v58 += v76 + (v67 - v72) * (v67 - v72);
          v62 += v77 * v77 + HIDWORD(v163) * HIDWORD(v163) + (v70 - v73) * (v70 - v73);
        }
        v58 += v62;
        v59 += 128;
      }
      v54 &= __CFADD__(v55 - v58 / 16, (v58 / 16) ^ 0x80000000) - 1;
    }
  }
  memcpy(Dst: v10, Src: src, Size: 0x10000u);
  v78 = v54;
  if ( v54 != 0 )
  {
    v79 = 0;
    valueInteger = vt_specularThreshold.valueInteger;
    valueFloat = vt_specularScale.valueFloat;
    do
    {
      v82 = 0;
      for ( jj = 16; jj != 0; --jj )
      {
        v84 = 4 * (v79 + v82);
        v85 = &v11[v84];
        LODWORD(v86) = (v11[v84 + 2] + v11[v84 + 1] + v11[v84]) / 3;
        if ( (int)v86 < valueInteger )
        {
          HIDWORD(v86) = &v10[v84];
          v163 = v86;
          v87 = (double)v86;
          LODWORD(v86) = (unsigned __int8)v10[v84 + 3];
          v172 = v86;
          v159 = (int)(float)((float)((float)v87 * (float)valueFloat) + (float)v86);
          LOBYTE(v88) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v88) = -1;
          }
          else
          {
            LOBYTE(v88) = 0;
          }
          *(_BYTE *)(HIDWORD(v88) + 3) = v88;
          *v85 = 0;
          v85[1] = 0;
          v85[2] = 0;
        }
        LODWORD(v89) = (v85[6] + v85[4] + v85[5]) / 3;
        if ( (int)v89 < valueInteger )
        {
          HIDWORD(v89) = &v10[v84];
          v181 = v89;
          v90 = (double)v89;
          LODWORD(v89) = (unsigned __int8)v10[v84 + 7];
          v180 = v89;
          v159 = (int)(float)((float)((float)v90 * (float)valueFloat) + (float)v89);
          LOBYTE(v91) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v91) = -1;
          }
          else
          {
            LOBYTE(v91) = 0;
          }
          *(_BYTE *)(HIDWORD(v91) + 7) = v91;
          v85[4] = 0;
          v85[5] = 0;
          v85[6] = 0;
        }
        v92 = 4 * (v79 + v82 + 2);
        LODWORD(v93) = (v85[10] + v85[9] + v11[v92]) / 3;
        if ( (int)v93 < valueInteger )
        {
          HIDWORD(v93) = &v10[v84];
          v178 = v93;
          v94 = (double)v93;
          LODWORD(v93) = (unsigned __int8)v10[v84 + 11];
          v169 = v93;
          v159 = (int)(float)((float)((float)v94 * (float)valueFloat) + (float)v93);
          LOBYTE(v95) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v95) = -1;
          }
          else
          {
            LOBYTE(v95) = 0;
          }
          *(_BYTE *)(HIDWORD(v95) + 11) = v95;
          v11[v92] = 0;
          v85[9] = 0;
          v85[10] = 0;
        }
        v96 = 4 * (v79 + v82 + 3);
        LODWORD(v97) = (v85[14] + v85[13] + v11[v96]) / 3;
        if ( (int)v97 < valueInteger )
        {
          HIDWORD(v97) = &v10[v84];
          v174 = v97;
          v98 = (double)v97;
          LODWORD(v97) = (unsigned __int8)v10[v84 + 15];
          v182 = v97;
          v159 = (int)(float)((float)((float)v98 * (float)valueFloat) + (float)v97);
          LOBYTE(v99) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v99) = -1;
          }
          else
          {
            LOBYTE(v99) = 0;
          }
          *(_BYTE *)(HIDWORD(v99) + 15) = v99;
          v11[v96] = 0;
          v85[13] = 0;
          v85[14] = 0;
        }
        v100 = 4 * (v79 + v82 + 4);
        LODWORD(v101) = (v85[18] + v85[17] + v11[v100]) / 3;
        if ( (int)v101 < valueInteger )
        {
          HIDWORD(v101) = &v10[v84];
          v176 = v101;
          LODWORD(v101) = (unsigned __int8)v10[v84 + 19];
          v170 = v101;
          v159 = (int)(float)((float)((float)v176 * (float)valueFloat) + (float)v101);
          LOBYTE(v102) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v102) = -1;
          }
          else
          {
            LOBYTE(v102) = 0;
          }
          *(_BYTE *)(HIDWORD(v102) + 19) = v102;
          v11[v100] = 0;
          v85[17] = 0;
          v85[18] = 0;
        }
        v103 = 4 * (v79 + v82 + 5);
        LODWORD(v104) = (v85[22] + v85[21] + v11[v103]) / 3;
        if ( (int)v104 < valueInteger )
        {
          HIDWORD(v104) = &v10[v84];
          v171 = v104;
          LODWORD(v104) = (unsigned __int8)v10[v84 + 23];
          v173 = v104;
          v159 = (int)(float)((float)((float)v171 * (float)valueFloat) + (float)v104);
          LOBYTE(v105) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v105) = -1;
          }
          else
          {
            LOBYTE(v105) = 0;
          }
          *(_BYTE *)(HIDWORD(v105) + 23) = v105;
          v11[v103] = 0;
          v85[21] = 0;
          v85[22] = 0;
        }
        v106 = 4 * (v79 + v82 + 6);
        LODWORD(v107) = (v85[26] + v85[25] + v11[v106]) / 3;
        if ( (int)v107 < valueInteger )
        {
          HIDWORD(v107) = &v10[v84];
          v175 = v107;
          LODWORD(v107) = (unsigned __int8)v10[v84 + 27];
          v177 = v107;
          v159 = (int)(float)((float)((float)v175 * (float)valueFloat) + (float)v107);
          LOBYTE(v108) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v108) = -1;
          }
          else
          {
            LOBYTE(v108) = 0;
          }
          *(_BYTE *)(HIDWORD(v108) + 27) = v108;
          v11[v106] = 0;
          v85[25] = 0;
          v85[26] = 0;
        }
        v109 = 4 * (v79 + v82 + 7);
        LODWORD(v110) = (v85[30] + v85[29] + v11[v109]) / 3;
        if ( (int)v110 < valueInteger )
        {
          HIDWORD(v110) = &v10[v84];
          v179 = v110;
          LODWORD(v110) = (unsigned __int8)v10[v84 + 31];
          *(_QWORD *)&v161 = v110;
          v159 = (int)(float)((float)((float)v179 * (float)valueFloat) + (float)v110);
          LOBYTE(v111) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v111) = -1;
          }
          else
          {
            LOBYTE(v111) = 0;
          }
          *(_BYTE *)(HIDWORD(v111) + 31) = v111;
          v11[v109] = 0;
          v85[29] = 0;
          v85[30] = 0;
        }
        v82 += 8;
      }
      v79 += 128;
    }
    while ( v79 < 0x4000 );
  }
  v112 = 0;
  for ( kk = 0; kk < 0x4000; kk += 128 )
  {
    v114 = 0;
    for ( mm = 32; mm != 0; --mm )
    {
      v116 = &v11[4 * kk + 4 * v114];
      if ( *v116 > v112 )
        v112 = *v116;
      if ( v116[1] > v112 )
        v112 = v116[1];
      if ( v116[2] > v112 )
        v112 = v116[2];
      if ( v116[4] > v112 )
        v112 = v116[4];
      if ( v116[5] > v112 )
        v112 = v116[5];
      if ( v116[6] > v112 )
        v112 = v116[6];
      v117 = 4 * (kk + v114 + 2);
      if ( v11[v117] > v112 )
        v112 = v11[v117];
      if ( v116[9] > v112 )
        v112 = v116[9];
      if ( v116[10] > v112 )
        v112 = v116[10];
      v118 = 4 * (kk + v114 + 3);
      if ( v11[v118] > v112 )
        v112 = v11[v118];
      if ( v116[13] > v112 )
        v112 = v116[13];
      if ( v116[14] > v112 )
        v112 = v116[14];
      v114 += 4;
    }
  }
  v119 = 0;
  if ( vt_useSpecularScale.valueInteger != 0 )
  {
    if ( v112 >= 64 )
      v119 = v112 < 128;
    else
      v119 = 2;
  }
  v120 = v160;
  for ( nn = 0; nn < 4096; nn += 128 )
  {
    v122 = 0;
    for ( i1 = 32; i1 != 0; --i1 )
    {
      v120[nn / 4 + v122] = v9[16 * nn + 16 * v122];
      ++v122;
    }
  }
  v124 = v162;
  memset(Dst: v162, Val: 0, Size: 0x800u);
  v125 = v165;
  for ( i2 = 0; i2 < 0x4000; i2 += 128 )
  {
    v127 = 0;
    for ( i3 = 128; i3 != 0; --i3 )
    {
      v129 = v11[4 * i2 + 3 + 4 * v127];
      v124[(i2 + v127) >> 3] |= (v129 >= 0x80) << ((i2 + v127) & 7);
      v125[i2 + v127++] = v129;
    }
  }
  v130 = (vt_qualityHDPLossless.valueInteger != 0) - 1;
  DWORD1(v161) = 0;
  *((_QWORD *)&v161 + 1) = v12;
  LOWORD(v161) = 0;
  v131 = v119 & 3 | (!storeCover ? 0 : 8) | (v54 == 0 ? 0 : 4);
  BYTE4(v161) = v119 & 3 | (!storeCover ? 0 : 8) | (v54 == 0 ? 0 : 4);
  v132 = (unsigned __int8)(v130 & vt_qualityHDPDiffuse.valueInteger);
  v133 = (unsigned __int8)(v130 & vt_qualityHDPNormal.valueInteger);
  v134 = (unsigned __int8)(v130 & vt_qualityHDPSpecular.valueInteger);
  HIBYTE(v161) = v130 & vt_qualityHDPDiffuse.valueInteger;
  v135 = v130 & vt_qualityHDPPower.valueInteger;
  BYTE1(v161) = v130 & vt_qualityHDPNormal.valueInteger;
  BYTE2(v161) = v130 & vt_qualityHDPSpecular.valueInteger;
  BYTE3(v161) = v130 & vt_qualityHDPPower.valueInteger;
  v136 = idBareHDP::idBareHDP(this: &v183);
  ((void (__fastcall *)(idBareHDP *))RtlCheckStack12)(a1: v136);
  v183.quality = v132;
  v168 = 0;
  *(_DWORD *)((char *)back_chain + v137) = back_chain[0];
  v183.tempBufferSize = 33792;
  v183.tempBuffer = &v158;
  idBareHDP::CompressImageYCoCg(
    this: &v183,
    inBuf: (unsigned __int8 *)v10,
    outBuf: dest + 16,
    outBufSize: maxDestLength,
    width: 0x80u,
    height: 0x80u,
    outputBytes: &v168);
  v183.quality = v133;
  v166 = 0;
  v138 = maxDestLength - v168;
  v139 = &dest[v168 + 16];
  WORD3(v161) = v168;
  v140 = v168;
  idBareHDP::CompressImageNormalMap(
    this: &v183,
    inBuf: v9,
    outBuf: v139,
    outBufSize: maxDestLength - v168,
    width: 0x80u,
    height: 0x80u,
    outputBytes: &v166);
  v183.quality = v134;
  v164 = 0;
  v141 = &v139[v166];
  v142 = v138 - v166;
  WORD4(v161) = v166;
  if ( v78 != 0 )
    idBareHDP::CompressImageGrayScale(
      this: &v183,
      inBuf: v11,
      outBuf: v141,
      outBufSize: v142,
      width: 0x80u,
      height: 0x80u,
      outputBytes: &v164);
  else
    idBareHDP::CompressImageRGB(
      this: &v183,
      inBuf: v11,
      outBuf: v141,
      outBufSize: v142,
      width: 0x80u,
      height: 0x80u,
      outputBytes: &v164);
  v167 = 0;
  v183.quality = v135;
  v143 = v160;
  v144 = &v141[v164];
  v145 = v142 - v164;
  WORD5(v161) = v164;
  idBareHDP::CompressImageMono(
    this: &v183,
    inBuf: v160,
    outBuf: v144,
    outBufSize: v145,
    width: 0x20u,
    height: 0x20u,
    outputBytes: &v167);
  v147 = v167;
  v148 = &v144[v167];
  WORD6(v161) = v167;
  v149 = v145 - v167;
  if ( storeCover )
  {
    memcpy(Dst: v148, Src: v162, Size: 0x800u);
    v148 += 2048;
    v149 -= 2048;
  }
  if ( storeAlpha )
  {
    v183.quality = v132;
    v160 = nullptr;
    idBareHDP::CompressImageMono(
      this: &v183,
      inBuf: v165,
      outBuf: v148,
      outBufSize: v149,
      width: 0x80u,
      height: 0x80u,
      outputBytes: (int *)&v160);
    v148 = &v148[(_DWORD)v160];
    LOWORD(v161) = (_WORD)v160;
  }
  *((_QWORD *)&v150 + 1) = *(_QWORD *)(HIDWORD(v12) + 32);
  v151 = *(_QWORD *)(HIDWORD(v12) + 40);
  v152 = *(_QWORD *)HIDWORD(v12);
  v153 = *(_DWORD *)(HIDWORD(v12) + 56) - ((*(_DWORD *)(HIDWORD(v12) + 56) - 1) & (v148 - dest));
  v154 = *(_QWORD *)(HIDWORD(v12) + 8);
  DWORD2(v150) += *(_DWORD *)(HIDWORD(v12) + 28);
  v155 = *(_QWORD *)(HIDWORD(v12) + 48);
  DWORD1(v150) = v140 + *(_DWORD *)(HIDWORD(v12) + 20);
  *(_QWORD *)(HIDWORD(v12) + 24) = *(_QWORD *)((char *)&v150 + 4);
  HIDWORD(v150) = v147 + (_DWORD)v150;
  *(_QWORD *)(HIDWORD(v12) + 16) = *(_QWORD *)&v150;
  *(_QWORD *)(HIDWORD(v12) + 32) = *(_QWORD *)(&v146 - 1);
  HIDWORD(v155) = ((v131 << 8) & 0x800) + v151;
  LODWORD(v151) = v153 + v155;
  HIDWORD(v151) = v152 + 16;
  *(_QWORD *)(HIDWORD(v12) + 40) = *(__int64 *)((char *)&v151 - 4);
  LODWORD(v150) = WORD1(v152) + (_DWORD)v154;
  *(_QWORD *)(HIDWORD(v12) + 48) = v151;
  *(_QWORD *)HIDWORD(v12) = *(_QWORD *)((char *)&v150 - 4);
  DWORD2(v150) = 16;
  *(_QWORD *)(HIDWORD(v12) + 8) = v150;
  *(_OWORD *)dest = v161;
  idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)HIDWORD(v154), align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v143, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v162, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v165, align: ALIGN_16);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v183);
  return v148 - dest;
}


// ========================================================================
// __unwind$235827
// EA  : 0x82929840
// RVA : 0x00929840
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void _unwind_235827()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 592 + 272));
}


// ========================================================================
// ?JXR_Compress@@YAHPBXHPAXH_N2AAUcompressionStats_t@@@Z
// EA  : 0x82929870
// RVA : 0x00929870
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall JXR_Compress(
        char *src,
        int length,
        unsigned __int8 *dest,
        unsigned int maxDestLength,
        bool storeCover,
        bool storeAlpha,
        compressionStats_t *stats)
{
  char *v8; // r30
  const unsigned __int8 *v9; // r16
  char *v10; // r17
  const unsigned __int8 *v11; // r27
  __int64 v12; // r19
  int i; // r5
  int v14; // r7
  int j; // ctr
  int v16; // r8
  unsigned __int8 *v17; // r6
  int v18; // r3
  unsigned __int8 *v19; // r11
  int v20; // r29
  const unsigned __int8 *v21; // r10
  signed int v22; // r9
  int v23; // r8
  int v24; // r29
  int v25; // r8
  unsigned int v26; // r4
  unsigned int v27; // r9
  int v28; // r8
  unsigned int v29; // r4
  signed int v30; // r9
  int v31; // r29
  int v32; // r8
  unsigned int v33; // r4
  int v34; // r28
  int v35; // r8
  int v36; // r29
  unsigned int v37; // r4
  unsigned int v38; // r26
  signed int v39; // r9
  int v40; // r3
  int v41; // r29
  int v42; // r8
  int v43; // r3
  int v44; // r4
  int v45; // r3
  unsigned int v46; // r8
  unsigned int v47; // r4
  unsigned int v48; // r9
  signed int v49; // r9
  int v50; // r8
  unsigned int v51; // r4
  int v52; // r3
  unsigned int v53; // r6
  unsigned __int8 v54; // r22
  int v55; // r21
  int k; // r23
  int m; // r24
  int v58; // r4
  int v59; // r26
  int n; // r25
  int v61; // r10
  int v62; // r3
  int ii; // ctr
  int v64; // r11
  unsigned __int8 *v65; // r11
  int v66; // r9
  int v67; // r8
  int v68; // r7
  int v69; // r6
  int v70; // r5
  int v71; // r11
  int v72; // r30
  int v73; // r29
  int v74; // r9
  int v75; // r7
  int v76; // r11
  int v77; // r7
  int v78; // r21
  int v79; // r4
  int valueInteger; // r7
  double valueFloat; // fp0
  int v82; // r5
  int jj; // ctr
  int v84; // r3
  const unsigned __int8 *v85; // r11
  __int64 v86; // r10
  double v87; // fp12
  __int64 v88; // r10
  __int64 v89; // r10
  double v90; // fp12
  __int64 v91; // r10
  int v92; // r8
  __int64 v93; // r10
  double v94; // fp9
  __int64 v95; // r10
  int v96; // r8
  __int64 v97; // r10
  double v98; // fp12
  __int64 v99; // r10
  int v100; // r8
  __int64 v101; // r10
  __int64 v102; // r10
  int v103; // r8
  __int64 v104; // r10
  __int64 v105; // r10
  int v106; // r8
  __int64 v107; // r10
  __int64 v108; // r10
  int v109; // r8
  __int64 v110; // r10
  __int64 v111; // r10
  int v112; // r11
  int kk; // r7
  int v114; // r8
  int mm; // ctr
  unsigned __int8 *v116; // r9
  int v117; // r6
  int v118; // r6
  char v119; // r30
  const unsigned __int8 *v120; // r7
  int nn; // r10
  int v122; // r11
  int i1; // ctr
  _BYTE *v124; // r29
  unsigned __int8 *v125; // r6
  int i2; // r7
  int v127; // r10
  int i3; // ctr
  unsigned int v129; // r28
  char v130; // r5
  int v131; // r23
  int v132; // r30
  int v133; // r26
  int v134; // r25
  unsigned __int8 v135; // r24
  idBareJXR *v136; // r3
  int v137; // r12
  int v138; // r26
  unsigned __int8 *v139; // r29
  unsigned __int16 v140; // r22
  unsigned __int8 *v141; // r29
  unsigned int v142; // r26
  unsigned __int8 *v143; // r16
  unsigned __int8 *v144; // r29
  unsigned int v145; // r26
  int v146; // r2 OVERLAPPED
  unsigned __int16 v147; // r24
  unsigned __int8 *v148; // r29
  unsigned int v149; // r28
  __int128 v150; // r6 OVERLAPPED
  __int64 v151; // r8 OVERLAPPED
  __int64 v152; // r26
  int v153; // r11
  __int64 v154; // r28
  __int64 v155; // r10
  _DWORD back_chain[20]; // [sp+0h] [-1D0h]
  int v158; // [sp+50h] [-180h] BYREF
  int v159; // [sp+54h] [-17Ch]
  unsigned __int8 *v160; // [sp+58h] [-178h] BYREF
  __int64 v161; // [sp+60h] [-170h]
  __int128 v162; // [sp+70h] [-160h]
  _BYTE *v163; // [sp+80h] [-150h]
  unsigned __int8 *v164; // [sp+84h] [-14Ch]
  int v165; // [sp+88h] [-148h] BYREF
  int v166; // [sp+8Ch] [-144h] BYREF
  int v167; // [sp+90h] [-140h] BYREF
  int v168[3]; // [sp+94h] [-13Ch] BYREF
  idBareJXR v169; // [sp+A0h] [-130h] BYREF
  __int64 v170; // [sp+C0h] [-110h]
  __int64 v171; // [sp+C8h] [-108h]
  __int64 v172; // [sp+D0h] [-100h]
  __int64 v173; // [sp+D8h] [-F8h]
  __int64 v174; // [sp+E0h] [-F0h]
  __int64 v175; // [sp+E8h] [-E8h]
  __int64 v176; // [sp+F0h] [-E0h]
  __int64 v177; // [sp+F8h] [-D8h]
  __int64 v178; // [sp+100h] [-D0h]
  __int64 v179; // [sp+108h] [-C8h]
  __int64 v180; // [sp+110h] [-C0h]
  __int64 v181; // [sp+118h] [-B8h]
  __int64 v182; // [sp+120h] [-B0h]
  __int64 v183; // [sp+128h] [-A8h]

  HIDWORD(v12) = stats;
  v8 = src + 0x20000;
  v9 = (const unsigned __int8 *)(src + 0x10000);
  v10 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(478) : TAG_VIRTUALTEXTURE",
                  size: 0x10000u,
                  tag: TAG_VIRTUALTEXTURE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v11 = (const unsigned __int8 *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(479) : TAG_VIRTUALTEXTURE",
                                   size: 0x10000u,
                                   tag: TAG_VIRTUALTEXTURE,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  v160 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(480) : TAG_VIRTUALTEXTURE",
                              size: 0x400u,
                              tag: TAG_VIRTUALTEXTURE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v163 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(481) : TAG_VIRTUALTEXTURE",
           size: 0x800u,
           tag: TAG_VIRTUALTEXTURE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
  LODWORD(v12) = 0;
  v164 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\renderer\\jobs\\transcode\\PageCompression.cpp(482) : TAG_VIRTUALTEXTURE",
                              size: 0x4000u,
                              tag: TAG_VIRTUALTEXTURE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  for ( i = 0; i < 0x4000; i += 128 )
  {
    v14 = 0;
    for ( j = 32; j != 0; --j )
    {
      v16 = 4 * (i + v14);
      v17 = (unsigned __int8 *)&v9[v16];
      v18 = 4 * (i + v14 + 2);
      v19 = (unsigned __int8 *)&v8[v16];
      v20 = (unsigned __int8)v8[v16];
      v21 = &v11[v16];
      v22 = (v9[v16 + 2] >> 3) + 1;
      v11[v16] = v20 / v22;
      __twllei(v22, 0);
      v23 = (unsigned __int8)v8[v16 + 1];
      __twlgei(v22 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
      *((_BYTE *)v21 + 1) = v23 / v22;
      __twllei(v22, 0);
      v24 = __ROL4__(v23, 1) - 1;
      v25 = v19[2];
      *((_BYTE *)v21 + 2) = v25 / v22;
      v26 = v22 & ~v24;
      *((_BYTE *)v21 + 3) = v19[3];
      __twllei(v22, 0);
      v27 = v22 & ~(__ROL4__(v25, 1) - 1);
      v28 = v19[4];
      __twlgei(v26, 0xFFFFFFFF);
      v29 = v17[6];
      __twlgei(v27, 0xFFFFFFFF);
      v30 = (v29 >> 3) + 1;
      *((_BYTE *)v21 + 4) = v28 / v30;
      __twllei(v30, 0);
      v31 = __ROL4__(v28, 1) - 1;
      v32 = v19[5];
      *((_BYTE *)v21 + 5) = v32 / v30;
      v33 = v30 & ~v31;
      v34 = __ROL4__(v32, 1) - 1;
      v35 = v19[6];
      *((_BYTE *)v21 + 6) = v35 / v30;
      *((_BYTE *)v21 + 7) = v19[7];
      __twlgei(v30 & ~v34, 0xFFFFFFFF);
      v36 = (unsigned __int8)v8[v18];
      __twlgei(v33, 0xFFFFFFFF);
      v37 = v17[10];
      v38 = v30 & ~(__ROL4__(v35, 1) - 1);
      __twllei(v30, 0);
      __twllei(v30, 0);
      v39 = (v37 >> 3) + 1;
      v11[v18] = v36 / v39;
      __twlgei(v38, 0xFFFFFFFF);
      v40 = v19[9];
      __twllei(v39, 0);
      __twlgei(v39 & ~(__ROL4__(v36, 1) - 1), 0xFFFFFFFF);
      __twllei(v39, 0);
      *((_BYTE *)v21 + 9) = v40 / v39;
      __twllei(v39, 0);
      v41 = 4 * (i + v14 + 3);
      v42 = __ROL4__(v40, 1);
      v43 = v19[10];
      *((_BYTE *)v21 + 10) = v43 / v39;
      v44 = __ROL4__(v43, 1);
      *((_BYTE *)v21 + 11) = v19[11];
      v45 = (unsigned __int8)v8[v41];
      v46 = v39 & ~(v42 - 1);
      v47 = v39 & ~(v44 - 1);
      v48 = v17[14];
      __twlgei(v46, 0xFFFFFFFF);
      __twlgei(v47, 0xFFFFFFFF);
      v14 += 4;
      v49 = (v48 >> 3) + 1;
      v11[v41] = v45 / v49;
      __twllei(v49, 0);
      v50 = v19[13];
      *((_BYTE *)v21 + 13) = v50 / v49;
      v51 = v49 & ~(__ROL4__(v45, 1) - 1);
      v52 = v19[14];
      v53 = v49 & ~(__ROL4__(v50, 1) - 1);
      __twllei(v49, 0);
      *((_BYTE *)v21 + 14) = v52 / v49;
      __twllei(v49, 0);
      LOBYTE(v50) = v19[15];
      __twlgei(v51, 0xFFFFFFFF);
      *((_BYTE *)v21 + 15) = v50;
      __twlgei(v53, 0xFFFFFFFF);
      __twlgei(v49 & ~(__ROL4__(v52, 1) - 1), 0xFFFFFFFF);
    }
  }
  v54 = 1;
  if ( vt_qualityJXRLossless.valueInteger != 0 )
    v55 = 0;
  else
    v55 = vt_maxMonoSpecularError.valueInteger * vt_maxMonoSpecularError.valueInteger;
  for ( k = 0; k < 0x4000; k += 512 )
  {
    for ( m = 0; m < 128; m += 4 )
    {
      v58 = 0;
      v59 = k + m;
      for ( n = 4; n != 0; --n )
      {
        v61 = 0;
        v62 = 0;
        for ( ii = 2; ii != 0; --ii )
        {
          v64 = 4 * (v59 + v61);
          v61 += 2;
          v65 = (unsigned __int8 *)&v11[v64];
          v66 = v65[1];
          v67 = v65[2];
          v68 = *v65;
          v69 = v65[5];
          v70 = v65[6];
          v71 = v65[4];
          v72 = (2 * (v67 + v66 + v68) + 3) / 6;
          v73 = (2 * (v70 + v69 + v71) + 3) / 6;
          HIDWORD(v161) = v66 - v72;
          v74 = (v68 - v72) * (v68 - v72);
          v75 = HIDWORD(v161);
          HIDWORD(v161) = v71 - v73;
          v76 = v74 + v75 * v75;
          v77 = HIDWORD(v161);
          HIDWORD(v161) = v69 - v73;
          v58 += v76 + (v67 - v72) * (v67 - v72);
          v62 += v77 * v77 + HIDWORD(v161) * HIDWORD(v161) + (v70 - v73) * (v70 - v73);
        }
        v58 += v62;
        v59 += 128;
      }
      v54 &= __CFADD__(v55 - v58 / 16, (v58 / 16) ^ 0x80000000) - 1;
    }
  }
  memcpy(Dst: v10, Src: src, Size: 0x10000u);
  v78 = v54;
  if ( v54 != 0 )
  {
    v79 = 0;
    valueInteger = vt_specularThreshold.valueInteger;
    valueFloat = vt_specularScale.valueFloat;
    do
    {
      v82 = 0;
      for ( jj = 16; jj != 0; --jj )
      {
        v84 = 4 * (v79 + v82);
        v85 = &v11[v84];
        LODWORD(v86) = (v11[v84 + 2] + v11[v84 + 1] + v11[v84]) / 3;
        if ( (int)v86 < valueInteger )
        {
          HIDWORD(v86) = &v10[v84];
          v161 = v86;
          v87 = (double)v86;
          LODWORD(v86) = (unsigned __int8)v10[v84 + 3];
          v172 = v86;
          v159 = (int)(float)((float)((float)v87 * (float)valueFloat) + (float)v86);
          LOBYTE(v88) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v88) = -1;
          }
          else
          {
            LOBYTE(v88) = 0;
          }
          *(_BYTE *)(HIDWORD(v88) + 3) = v88;
          *v85 = 0;
          *((_BYTE *)v85 + 1) = 0;
          *((_BYTE *)v85 + 2) = 0;
        }
        LODWORD(v89) = (v85[6] + v85[4] + v85[5]) / 3;
        if ( (int)v89 < valueInteger )
        {
          HIDWORD(v89) = &v10[v84];
          v181 = v89;
          v90 = (double)v89;
          LODWORD(v89) = (unsigned __int8)v10[v84 + 7];
          v183 = v89;
          v159 = (int)(float)((float)((float)v90 * (float)valueFloat) + (float)v89);
          LOBYTE(v91) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v91) = -1;
          }
          else
          {
            LOBYTE(v91) = 0;
          }
          *(_BYTE *)(HIDWORD(v91) + 7) = v91;
          *((_BYTE *)v85 + 4) = 0;
          *((_BYTE *)v85 + 5) = 0;
          *((_BYTE *)v85 + 6) = 0;
        }
        v92 = 4 * (v79 + v82 + 2);
        LODWORD(v93) = (v85[10] + v85[9] + v11[v92]) / 3;
        if ( (int)v93 < valueInteger )
        {
          HIDWORD(v93) = &v10[v84];
          v178 = v93;
          v94 = (double)v93;
          LODWORD(v93) = (unsigned __int8)v10[v84 + 11];
          v170 = v93;
          v159 = (int)(float)((float)((float)v94 * (float)valueFloat) + (float)v93);
          LOBYTE(v95) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v95) = -1;
          }
          else
          {
            LOBYTE(v95) = 0;
          }
          *(_BYTE *)(HIDWORD(v95) + 11) = v95;
          v11[v92] = 0;
          *((_BYTE *)v85 + 9) = 0;
          *((_BYTE *)v85 + 10) = 0;
        }
        v96 = 4 * (v79 + v82 + 3);
        LODWORD(v97) = (v85[14] + v85[13] + v11[v96]) / 3;
        if ( (int)v97 < valueInteger )
        {
          HIDWORD(v97) = &v10[v84];
          v174 = v97;
          v98 = (double)v97;
          LODWORD(v97) = (unsigned __int8)v10[v84 + 15];
          v182 = v97;
          v159 = (int)(float)((float)((float)v98 * (float)valueFloat) + (float)v97);
          LOBYTE(v99) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v99) = -1;
          }
          else
          {
            LOBYTE(v99) = 0;
          }
          *(_BYTE *)(HIDWORD(v99) + 15) = v99;
          v11[v96] = 0;
          *((_BYTE *)v85 + 13) = 0;
          *((_BYTE *)v85 + 14) = 0;
        }
        v100 = 4 * (v79 + v82 + 4);
        LODWORD(v101) = (v85[18] + v85[17] + v11[v100]) / 3;
        if ( (int)v101 < valueInteger )
        {
          HIDWORD(v101) = &v10[v84];
          v176 = v101;
          LODWORD(v101) = (unsigned __int8)v10[v84 + 19];
          v180 = v101;
          v159 = (int)(float)((float)((float)v176 * (float)valueFloat) + (float)v101);
          LOBYTE(v102) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v102) = -1;
          }
          else
          {
            LOBYTE(v102) = 0;
          }
          *(_BYTE *)(HIDWORD(v102) + 19) = v102;
          v11[v100] = 0;
          *((_BYTE *)v85 + 17) = 0;
          *((_BYTE *)v85 + 18) = 0;
        }
        v103 = 4 * (v79 + v82 + 5);
        LODWORD(v104) = (v85[22] + v85[21] + v11[v103]) / 3;
        if ( (int)v104 < valueInteger )
        {
          HIDWORD(v104) = &v10[v84];
          v171 = v104;
          LODWORD(v104) = (unsigned __int8)v10[v84 + 23];
          v173 = v104;
          v159 = (int)(float)((float)((float)v171 * (float)valueFloat) + (float)v104);
          LOBYTE(v105) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v105) = -1;
          }
          else
          {
            LOBYTE(v105) = 0;
          }
          *(_BYTE *)(HIDWORD(v105) + 23) = v105;
          v11[v103] = 0;
          *((_BYTE *)v85 + 21) = 0;
          *((_BYTE *)v85 + 22) = 0;
        }
        v106 = 4 * (v79 + v82 + 6);
        LODWORD(v107) = (v85[26] + v85[25] + v11[v106]) / 3;
        if ( (int)v107 < valueInteger )
        {
          HIDWORD(v107) = &v10[v84];
          v175 = v107;
          LODWORD(v107) = (unsigned __int8)v10[v84 + 27];
          v177 = v107;
          v159 = (int)(float)((float)((float)v175 * (float)valueFloat) + (float)v107);
          LOBYTE(v108) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v108) = -1;
          }
          else
          {
            LOBYTE(v108) = 0;
          }
          *(_BYTE *)(HIDWORD(v108) + 27) = v108;
          v11[v106] = 0;
          *((_BYTE *)v85 + 25) = 0;
          *((_BYTE *)v85 + 26) = 0;
        }
        v109 = 4 * (v79 + v82 + 7);
        LODWORD(v110) = (v85[30] + v85[29] + v11[v109]) / 3;
        if ( (int)v110 < valueInteger )
        {
          HIDWORD(v110) = &v10[v84];
          v179 = v110;
          LODWORD(v110) = (unsigned __int8)v10[v84 + 31];
          *(_QWORD *)&v162 = v110;
          v159 = (int)(float)((float)((float)v179 * (float)valueFloat) + (float)v110);
          LOBYTE(v111) = v159;
          if ( v159 >= 0 )
          {
            if ( v159 > 255 )
              LOBYTE(v111) = -1;
          }
          else
          {
            LOBYTE(v111) = 0;
          }
          *(_BYTE *)(HIDWORD(v111) + 31) = v111;
          v11[v109] = 0;
          *((_BYTE *)v85 + 29) = 0;
          *((_BYTE *)v85 + 30) = 0;
        }
        v82 += 8;
      }
      v79 += 128;
    }
    while ( v79 < 0x4000 );
  }
  v112 = 0;
  for ( kk = 0; kk < 0x4000; kk += 128 )
  {
    v114 = 0;
    for ( mm = 32; mm != 0; --mm )
    {
      v116 = (unsigned __int8 *)&v11[4 * kk + 4 * v114];
      if ( *v116 > v112 )
        v112 = *v116;
      if ( v116[1] > v112 )
        v112 = v116[1];
      if ( v116[2] > v112 )
        v112 = v116[2];
      if ( v116[4] > v112 )
        v112 = v116[4];
      if ( v116[5] > v112 )
        v112 = v116[5];
      if ( v116[6] > v112 )
        v112 = v116[6];
      v117 = 4 * (kk + v114 + 2);
      if ( v11[v117] > v112 )
        v112 = v11[v117];
      if ( v116[9] > v112 )
        v112 = v116[9];
      if ( v116[10] > v112 )
        v112 = v116[10];
      v118 = 4 * (kk + v114 + 3);
      if ( v11[v118] > v112 )
        v112 = v11[v118];
      if ( v116[13] > v112 )
        v112 = v116[13];
      if ( v116[14] > v112 )
        v112 = v116[14];
      v114 += 4;
    }
  }
  v119 = 0;
  if ( vt_useSpecularScale.valueInteger != 0 )
  {
    if ( v112 >= 64 )
      v119 = v112 < 128;
    else
      v119 = 2;
  }
  v120 = v160;
  for ( nn = 0; nn < 4096; nn += 128 )
  {
    v122 = 0;
    for ( i1 = 32; i1 != 0; --i1 )
    {
      v120[nn / 4 + v122] = v9[16 * nn + 16 * v122];
      ++v122;
    }
  }
  v124 = v163;
  memset(Dst: v163, Val: 0, Size: 0x800u);
  v125 = v164;
  for ( i2 = 0; i2 < 0x4000; i2 += 128 )
  {
    v127 = 0;
    for ( i3 = 128; i3 != 0; --i3 )
    {
      v129 = v11[4 * i2 + 3 + 4 * v127];
      v124[(i2 + v127) >> 3] |= (v129 >= 0x80) << ((i2 + v127) & 7);
      v125[i2 + v127++] = v129;
    }
  }
  v130 = (vt_qualityJXRLossless.valueInteger != 0) - 1;
  DWORD1(v162) = 0;
  *((_QWORD *)&v162 + 1) = v12;
  LOWORD(v162) = 0;
  v131 = v119 & 3 | (!storeCover ? 0 : 8) | (v54 == 0 ? 0 : 4);
  BYTE4(v162) = v119 & 3 | (!storeCover ? 0 : 8) | (v54 == 0 ? 0 : 4);
  v132 = (unsigned __int8)(v130 & vt_qualityJXRDiffuse.valueInteger);
  v133 = (unsigned __int8)(v130 & vt_qualityJXRNormal.valueInteger);
  v134 = (unsigned __int8)(v130 & vt_qualityJXRSpecular.valueInteger);
  HIBYTE(v162) = v130 & vt_qualityJXRDiffuse.valueInteger;
  v135 = v130 & vt_qualityJXRPower.valueInteger;
  BYTE1(v162) = v130 & vt_qualityJXRNormal.valueInteger;
  BYTE2(v162) = v130 & vt_qualityJXRSpecular.valueInteger;
  BYTE3(v162) = v130 & vt_qualityJXRPower.valueInteger;
  v136 = idBareJXR::idBareJXR(this: &v169);
  ((void (__fastcall *)(idBareJXR *))RtlCheckStack12)(a1: v136);
  v169.quality = v132;
  v167 = 0;
  *(_DWORD *)((char *)back_chain + v137) = back_chain[0];
  v169.tempBufferSize = 163840;
  v169.tempBuffer = &v158;
  idBareJXR::CompressImageYCoCg(
    this: &v169,
    inBuf: (const unsigned __int8 *)v10,
    outBuf: dest + 16,
    outBufSize: maxDestLength,
    width: 128,
    height: 128,
    outputBytes: &v167);
  v169.quality = v133;
  v168[0] = 0;
  v138 = maxDestLength - v167;
  v139 = &dest[v167 + 16];
  WORD3(v162) = v167;
  v140 = v167;
  idBareJXR::CompressImageNormalMap(
    this: &v169,
    inBuf: v9,
    outBuf: v139,
    outBufSize: maxDestLength - v167,
    width: 128,
    height: 128,
    outputBytes: v168);
  v169.quality = v134;
  v165 = 0;
  v141 = &v139[v168[0]];
  v142 = v138 - v168[0];
  WORD4(v162) = v168[0];
  if ( v78 != 0 )
    idBareJXR::CompressImageGrayScale(
      this: &v169,
      inBuf: v11,
      outBuf: v141,
      outBufSize: v142,
      width: 128,
      height: 128,
      outputBytes: &v165);
  else
    idBareJXR::CompressImageRGB(
      this: &v169,
      inBuf: v11,
      outBuf: v141,
      outBufSize: v142,
      width: 128,
      height: 128,
      outputBytes: &v165);
  v166 = 0;
  v169.quality = v135;
  v143 = v160;
  v144 = &v141[v165];
  v145 = v142 - v165;
  WORD5(v162) = v165;
  idBareJXR::CompressImageMono(
    this: &v169,
    inBuf: v160,
    outBuf: v144,
    outBufSize: v145,
    width: 32,
    height: 32,
    outputBytes: &v166);
  v147 = v166;
  v148 = &v144[v166];
  WORD6(v162) = v166;
  v149 = v145 - v166;
  if ( storeCover )
  {
    memcpy(Dst: v148, Src: v163, Size: 0x800u);
    v148 += 2048;
    v149 -= 2048;
  }
  if ( storeAlpha )
  {
    v169.quality = v132;
    v160 = nullptr;
    idBareJXR::CompressImageMono(
      this: &v169,
      inBuf: v164,
      outBuf: v148,
      outBufSize: v149,
      width: 128,
      height: 128,
      outputBytes: (int *)&v160);
    v148 = &v148[(_DWORD)v160];
    LOWORD(v162) = (_WORD)v160;
  }
  *((_QWORD *)&v150 + 1) = *(_QWORD *)(HIDWORD(v12) + 32);
  v151 = *(_QWORD *)(HIDWORD(v12) + 40);
  v152 = *(_QWORD *)HIDWORD(v12);
  v153 = *(_DWORD *)(HIDWORD(v12) + 56) - ((*(_DWORD *)(HIDWORD(v12) + 56) - 1) & (v148 - dest));
  v154 = *(_QWORD *)(HIDWORD(v12) + 8);
  DWORD2(v150) += *(_DWORD *)(HIDWORD(v12) + 28);
  v155 = *(_QWORD *)(HIDWORD(v12) + 48);
  DWORD1(v150) = v140 + *(_DWORD *)(HIDWORD(v12) + 20);
  *(_QWORD *)(HIDWORD(v12) + 24) = *(_QWORD *)((char *)&v150 + 4);
  HIDWORD(v150) = v147 + (_DWORD)v150;
  *(_QWORD *)(HIDWORD(v12) + 16) = *(_QWORD *)&v150;
  *(_QWORD *)(HIDWORD(v12) + 32) = *(_QWORD *)(&v146 - 1);
  HIDWORD(v155) = ((v131 << 8) & 0x800) + v151;
  LODWORD(v151) = v153 + v155;
  HIDWORD(v151) = v152 + 16;
  *(_QWORD *)(HIDWORD(v12) + 40) = *(__int64 *)((char *)&v151 - 4);
  LODWORD(v150) = WORD1(v152) + (_DWORD)v154;
  *(_QWORD *)(HIDWORD(v12) + 48) = v151;
  *(_QWORD *)HIDWORD(v12) = *(_QWORD *)((char *)&v150 - 4);
  DWORD2(v150) = 16;
  *(_QWORD *)(HIDWORD(v12) + 8) = v150;
  *(_OWORD *)dest = v162;
  idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: (void *)HIDWORD(v154), align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v143, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v163, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v164, align: ALIGN_16);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v169);
  return v148 - dest;
}


// ========================================================================
// __unwind$236065
// EA  : 0x8292A790
// RVA : 0x0092A790
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void _unwind_236065()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v0 - 464 + 160));
}


// ========================================================================
// `dynamic initializer for 'vt_maxMonoSpecularError''
// EA  : 0x833578C0
// RVA : 0x013578C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_maxMonoSpecularError__()
{
  idCVar::idCVar(
    this: &vt_maxMonoSpecularError,
    name: "vt_maxMonoSpecularError",
    value: "10",
    flags: 18,
    description: "specular is considered monochrome if the error is less than this value",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_maxMonoSpecularError__);
}


// ========================================================================
// `dynamic initializer for 'vt_useSpecularScale''
// EA  : 0x83357918
// RVA : 0x01357918
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useSpecularScale__()
{
  idCVar::idCVar(
    this: &vt_useSpecularScale,
    name: "vt_useSpecularScale",
    value: "1",
    flags: 17,
    description: "scale the specular to avoid DXT quantization errors",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useSpecularScale__);
}


// ========================================================================
// `dynamic initializer for 'vt_specularThreshold''
// EA  : 0x83357970
// RVA : 0x01357970
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_specularThreshold__()
{
  idCVar::idCVar(
    this: &vt_specularThreshold,
    name: "vt_specularThreshold",
    value: "0",
    flags: 20,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_specularThreshold__);
}


// ========================================================================
// `dynamic initializer for 'vt_specularScale''
// EA  : 0x833579D8
// RVA : 0x013579D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_specularScale__()
{
  idCVar::idCVar(
    this: &vt_specularScale,
    name: "vt_specularScale",
    value: "0.2",
    flags: 20,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"_AI_OBSTACLE",
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_specularScale__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityDCTLuma''
// EA  : 0x83357A40
// RVA : 0x01357A40
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityDCTLuma__()
{
  idCVar::idCVar(
    this: &vt_qualityDCTLuma,
    name: "vt_qualityDCTLuma",
    value: "90",
    flags: 18,
    description: "quality in the range [0-100] percent where higher is better quality",
    valueMin: 0.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityDCTLuma__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityDCTChroma''
// EA  : 0x83357AA8
// RVA : 0x01357AA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityDCTChroma__()
{
  idCVar::idCVar(
    this: &vt_qualityDCTChroma,
    name: "vt_qualityDCTChroma",
    value: "80",
    flags: 18,
    description: "quality in the range [0-100] percent",
    valueMin: 0.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityDCTChroma__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityDCTNormal''
// EA  : 0x83357B10
// RVA : 0x01357B10
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityDCTNormal__()
{
  idCVar::idCVar(
    this: &vt_qualityDCTNormal,
    name: "vt_qualityDCTNormal",
    value: "60",
    flags: 18,
    description: "quality in the range [0-100] percent",
    valueMin: 0.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityDCTNormal__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityDCTSpecular''
// EA  : 0x83357B78
// RVA : 0x01357B78
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityDCTSpecular__()
{
  idCVar::idCVar(
    this: &vt_qualityDCTSpecular,
    name: "vt_qualityDCTSpecular",
    value: "80",
    flags: 18,
    description: "quality in the range [0-100] percent",
    valueMin: 0.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityDCTSpecular__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityDCTPower''
// EA  : 0x83357BE0
// RVA : 0x01357BE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityDCTPower__()
{
  idCVar::idCVar(
    this: &vt_qualityDCTPower,
    name: "vt_qualityDCTPower",
    value: "80",
    flags: 18,
    description: "quality in the range [0-100] percent",
    valueMin: 0.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityDCTPower__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityHDPDiffuse''
// EA  : 0x83357C48
// RVA : 0x01357C48
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityHDPDiffuse__()
{
  idCVar::idCVar(
    this: &vt_qualityHDPDiffuse,
    name: "vt_qualityHDPDiffuse",
    value: "30",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityHDPDiffuse__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityHDPNormal''
// EA  : 0x83357CB0
// RVA : 0x01357CB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityHDPNormal__()
{
  idCVar::idCVar(
    this: &vt_qualityHDPNormal,
    name: "vt_qualityHDPNormal",
    value: "30",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityHDPNormal__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityHDPSpecular''
// EA  : 0x83357D18
// RVA : 0x01357D18
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityHDPSpecular__()
{
  idCVar::idCVar(
    this: &vt_qualityHDPSpecular,
    name: "vt_qualityHDPSpecular",
    value: "25",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityHDPSpecular__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityHDPPower''
// EA  : 0x83357D80
// RVA : 0x01357D80
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityHDPPower__()
{
  idCVar::idCVar(
    this: &vt_qualityHDPPower,
    name: "vt_qualityHDPPower",
    value: "40",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityHDPPower__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityHDPLossless''
// EA  : 0x83357DE8
// RVA : 0x01357DE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityHDPLossless__()
{
  idCVar::idCVar(
    this: &vt_qualityHDPLossless,
    name: "vt_qualityHDPLossless",
    value: "0",
    flags: 17,
    description: "force lossless HD-Photo compression",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityHDPLossless__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityJXRDiffuse''
// EA  : 0x83357E50
// RVA : 0x01357E50
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityJXRDiffuse__()
{
  idCVar::idCVar(
    this: &vt_qualityJXRDiffuse,
    name: "vt_qualityJXRDiffuse",
    value: "30",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityJXRDiffuse__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityJXRNormal''
// EA  : 0x83357EB8
// RVA : 0x01357EB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityJXRNormal__()
{
  idCVar::idCVar(
    this: &vt_qualityJXRNormal,
    name: "vt_qualityJXRNormal",
    value: "30",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityJXRNormal__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityJXRSpecular''
// EA  : 0x83357F20
// RVA : 0x01357F20
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityJXRSpecular__()
{
  idCVar::idCVar(
    this: &vt_qualityJXRSpecular,
    name: "vt_qualityJXRSpecular",
    value: "25",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityJXRSpecular__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityJXRPower''
// EA  : 0x83357F88
// RVA : 0x01357F88
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityJXRPower__()
{
  idCVar::idCVar(
    this: &vt_qualityJXRPower,
    name: "vt_qualityJXRPower",
    value: "40",
    flags: 18,
    description: "amount of quantization to apply in the range [0-255] where lower is better quality",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"mMaterial",
    a9: (int)&off_82230000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityJXRPower__);
}


// ========================================================================
// `dynamic initializer for 'vt_qualityJXRLossless''
// EA  : 0x83357FF0
// RVA : 0x01357FF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\pagecompression.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_qualityJXRLossless__()
{
  idCVar::idCVar(
    this: &vt_qualityJXRLossless,
    name: "vt_qualityJXRLossless",
    value: "0",
    flags: 17,
    description: "force lossless JPEG-XR compression",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Mips",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_qualityJXRLossless__);
}

