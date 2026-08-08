
// ========================================================================
// ?TranscodePage_DCT_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x8292EE38
// RVA : 0x0092EE38
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void __fastcall TranscodePage_DCT_DXT(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  int v3; // r3
  int v4; // r12
  unsigned __int8 *tempData; // r28
  unsigned __int8 *v6; // r19
  unsigned __int8 *v7; // r11
  unsigned __int8 *v8; // r29
  unsigned __int8 *v9; // r15
  const unsigned __int8 *inPageHeader; // r25
  unsigned __int8 *v11; // r30
  const unsigned __int8 *inPageData; // r16
  unsigned __int64 v13; // r27
  int v14; // r10
  unsigned __int8 v15; // r11
  int v16; // r24
  int v17; // r5
  int v18; // r6
  int v19; // r10
  int v20; // r9
  unsigned int i; // r24
  unsigned __int8 v22; // r17
  int v23; // r14
  int v24; // r11
  __int64 v25; // r8
  int v26; // r20
  const unsigned __int8 *v27; // r19
  int v28; // r23
  unsigned int j; // r21
  unsigned __int8 *v30; // r4
  int v31; // r10
  int v32; // r9
  int v33; // r8
  unsigned __int8 *v34; // r6
  unsigned __int8 *v35; // r3
  int v36; // r21
  int v37; // r5
  __int64 v38; // r8
  int v39; // r6
  int v40; // r11
  int v41; // r24
  int v42; // r23
  unsigned int k; // r26
  int v44; // r23
  int v45; // r5
  int v46; // r24
  int v47; // r26
  int v48; // r5
  __int64 v49; // r8
  int v50; // r6
  int v51; // r11
  int v52; // r9
  int v53; // r10
  unsigned __int8 *v54; // r7
  int v55; // r8
  unsigned __int8 v56; // r24
  unsigned __int8 *v57; // r3
  unsigned __int8 *v58; // r5
  unsigned __int8 v59; // r21
  unsigned __int8 *v60; // r4
  unsigned __int8 v61; // r23
  unsigned __int8 *v62; // r28
  unsigned __int8 v63; // r18
  unsigned __int8 v64; // r19
  unsigned __int8 v65; // r25
  unsigned __int8 v66; // r23
  unsigned __int8 v67; // r22
  unsigned __int8 v68; // r6
  unsigned __int8 v69; // r21
  unsigned __int8 v70; // r20
  unsigned __int8 v71; // r15
  unsigned __int8 v72; // r17
  unsigned __int8 v73; // r18
  unsigned __int8 v74; // r14
  unsigned __int8 *v75; // r3
  unsigned __int8 v76; // r16
  unsigned __int8 v77; // r18
  unsigned __int8 v78; // r29
  unsigned __int8 *v79; // r11
  int v80; // r28
  int v81; // r29
  int back_chain[13]; // [sp+0h] [-2D50h]
  unsigned __int8 v83; // [sp+37h] [-2D19h]
  unsigned __int8 v84; // [sp+50h] [-2D00h]
  unsigned __int8 v85; // [sp+51h] [-2CFFh]
  unsigned __int8 v86; // [sp+52h] [-2CFEh]
  unsigned __int8 v87; // [sp+53h] [-2CFDh]
  unsigned __int8 v88; // [sp+54h] [-2CFCh]
  unsigned int v89; // [sp+58h] [-2CF8h]
  int v90; // [sp+5Ch] [-2CF4h]
  char v91; // [sp+60h] [-2CF0h]
  unsigned __int8 *v92; // [sp+64h] [-2CECh]
  int v93; // [sp+68h] [-2CE8h]
  int v94; // [sp+6Ch] [-2CE4h]
  int v95; // [sp+70h] [-2CE0h]
  unsigned __int8 *v96; // [sp+74h] [-2CDCh]
  unsigned __int8 *v97; // [sp+78h] [-2CD8h]
  unsigned __int8 *v98; // [sp+7Ch] [-2CD4h]
  unsigned __int8 *v99; // [sp+80h] [-2CD0h]
  idDxtEncoder v100; // [sp+90h] [-2CC0h] BYREF
  idDxtEncoder v101; // [sp+B0h] [-2CA0h] BYREF
  char v102; // [sp+CFh] [-2C81h] BYREF
  idDxtEncoder v103; // [sp+D0h] [-2C80h] BYREF
  idBareDctDecoder v104; // [sp+F0h] [-2C60h] BYREF
  idBareDctDecoder v105; // [sp+2D0h] [-2A80h] BYREF
  idBareDctDecoder v106; // [sp+4B0h] [-28A0h] BYREF
  idBareDctDecoder v107; // [sp+690h] [-26C0h] BYREF
  idBareDCTHuffmanTable v108; // [sp+870h] [-24E0h] BYREF
  idBareDCTHuffmanTable v109; // [sp+1180h] [-1BD0h] BYREF
  idBareDCTHuffmanTable v110; // [sp+1A90h] [-12C0h] BYREF
  idBareDCTHuffmanTable v111; // [sp+23A0h] [-9B0h] BYREF

  imageFlags = parms->imageFlags;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    if ( parms->tempData == nullptr )
    {
      v3 = ((int (*)(void))RtlCheckStack12)();
      *(int *)((char *)back_chain + v4) = back_chain[0];
      *(_DWORD *)(v3 + 108) = (unsigned int)&v102 & 0xFFFFFF80;
    }
    __asm { dcbz128   0, r11 }
    __asm { dcbz128   r20, r10 }
    __asm { dcbz128   r7, r8 }
    __asm { dcbz128   r6, r5 }
    __asm { dcbz128   r4, r3 }
    __asm { dcbz128   r11, r10 }
    __asm { dcbz128   r9, r8 }
    __asm { dcbz128   r7, r6 }
    tempData = parms->tempData;
    v6 = parms->targetImage[1];
    v7 = parms->targetImage[2];
    v8 = tempData + 1024;
    v9 = parms->targetImage[0];
    inPageHeader = parms->inPageHeader;
    v11 = tempData + 2048;
    inPageData = parms->inPageData;
    v97 = tempData;
    v96 = tempData + 1024;
    v92 = v6;
    v99 = v7;
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v109, huffmanType: 0, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v108, huffmanType: 1u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v111, huffmanType: 2u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v110, huffmanType: 3u, encode: false);
    LODWORD(v13) = 0;
    v14 = parms->imageFlags & 1;
    if ( v14 == 0 || (parms->imageFlags & 4) == 0 || (v15 = 1, (inPageHeader[5] & 3) == 2) )
      v15 = 0;
    HIDWORD(v13) = v15;
    if ( v14 != 0 )
    {
      v93 = parms->targetBytePitch[0];
      v16 = v93;
      idBareDctDecoder::idBareDctDecoder(this: &v104);
      idBareDctDecoder::SetHuffmanTables(
        this: &v104,
        tableYDC: &v109,
        tableYAC: &v108,
        tableCoCgDC: &v111,
        tableCoCgAC: &v110,
        tableADC: nullptr,
        tableAAC: nullptr);
      v17 = inPageHeader[3];
      v90 = v17;
      idBareDctBase::SetQuality_Xenon(this: &v104, luminanceQuality: v90, chrominanceQuality: v17, alphaQuality: v90);
      v19 = *((unsigned __int16 *)inPageHeader + 4);
      HIDWORD(v25) = v16 - 32;
      v20 = *((unsigned __int16 *)inPageHeader + 3);
      v22 = inPageHeader[5];
      v23 = BYTE3(v13);
      v104.imageWidth = 128;
      v104.imageHeight = 128;
      v104.bitCnt = v13;
      v24 = *((unsigned __int16 *)inPageHeader + 5);
      v104.data = &inPageData[v20 + v19];
      LODWORD(v25) = *((unsigned __int16 *)inPageHeader + 6);
      v26 = 0;
      v104.bitBuff = v13;
      v90 = v24;
      v104.dataBytes = v24;
      memset(&v104.dcY, 0, 16);
      v100.srcPadding = 0;
      v27 = &inPageData[v25 + v20 + v19 + v24];
      v100.dstPadding = v16 - 32;
      for ( i = 0; i < 8; ++i )
      {
        v28 = 0;
        for ( j = 0; j < 0x40; j += 8 )
        {
          v30 = tempData + 2048;
          if ( (v22 & 4) != 0 )
            idBareDctDecoder::DecompressOneTileGrayScale_Xenon(this: &v104, rgb: v30, stride: 64, a4: v18, a5: v25);
          else
            idBareDctDecoder::DecompressOneTileRGB_Xenon(this: &v104, rgb: v30, stride: 64, a4: v18, a5: v25);
          v34 = tempData + 2048;
          v35 = tempData + 1024;
          if ( v23 != 0 )
            DynamicScaleSpecular16x16(specularScale: v35, tileX: v28, tileY: i, rgba: v34);
          else
            ConstantScaleSpecular16x16(
              specularScale: v35,
              tileX: v28,
              tileY: i,
              rgba: v34,
              specularShift: v22 & 3,
              a6: v33,
              a7: v32,
              a8: v31,
              a9: back_chain[2],
              a10: back_chain[3],
              a11: back_chain[4],
              a12: back_chain[5],
              a13: back_chain[6],
              a14: back_chain[7],
              a15: back_chain[8],
              a16: back_chain[9],
              a17: back_chain[10],
              a18: back_chain[11],
              a19: back_chain[12],
              a20: v83);
          HIDWORD(v13) = 4 * (j + v26);
          if ( (v22 & 8) != 0 )
          {
            DecompressCover16x16(cover: v27, tileX: v28, tileY: i, rgba: tempData + 2048, byteStride: 64);
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v100,
              inBuf: tempData + 2048,
              outBuf: &v9[HIDWORD(v13)],
              width: 16,
              height: 16);
          }
          else
          {
            idDxtEncoder::CompressImageDXT1Fast_Xenon(
              this: &v100,
              inBuf: tempData + 2048,
              outBuf: &v9[HIDWORD(v13)],
              width: 16,
              height: 16);
          }
          ++v28;
        }
        v26 += v93;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v104);
      v6 = v92;
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      v36 = parms->targetBytePitch[1];
      idBareDctDecoder::idBareDctDecoder(this: &v106);
      idBareDctDecoder::SetHuffmanTables(
        this: &v106,
        tableYDC: &v109,
        tableYAC: &v108,
        tableCoCgDC: &v111,
        tableCoCgAC: &v110,
        tableADC: nullptr,
        tableAAC: nullptr);
      v37 = inPageHeader[1];
      v90 = *inPageHeader;
      idBareDctBase::SetQuality_Xenon(this: &v106, luminanceQuality: v90, chrominanceQuality: v37, alphaQuality: v90);
      v40 = *((unsigned __int16 *)inPageHeader + 3);
      v106.data = inPageData;
      v41 = 0;
      v106.imageWidth = 128;
      v42 = 8;
      v106.imageHeight = 128;
      v106.bitCnt = v13;
      v106.dataBytes = v40;
      v106.bitBuff = v13;
      memset(&v106.dcY, 0, 16);
      v103.srcPadding = 0;
      v103.dstPadding = v36 - 64;
      do
      {
        for ( k = 0; k < 0x80; k += 16 )
        {
          idBareDctDecoder::DecompressOneTileYCoCg_Xenon(
            this: &v106,
            rgb: tempData + 2048,
            stride: 64,
            a4: v39,
            a5: v38);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v103,
            inBuf: tempData + 2048,
            outBuf: &v6[4 * v41 + 4 * k],
            width: 16,
            height: 16);
        }
        --v42;
        v41 += v36;
      }
      while ( v42 != 0 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v106);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      if ( (parms->imageFlags & 1) == 0 )
        memset(Dst: tempData + 1024, Val: 8 * (1 << (inPageHeader[5] & 3)) - 8, Size: 0x400u);
      v90 = parms->targetBytePitch[2];
      v44 = v90;
      idBareDctDecoder::idBareDctDecoder(this: &v107);
      idBareDctDecoder::SetHuffmanTables(
        this: &v107,
        tableYDC: &v109,
        tableYAC: &v108,
        tableCoCgDC: nullptr,
        tableCoCgAC: nullptr,
        tableADC: nullptr,
        tableAAC: nullptr);
      v45 = inPageHeader[4];
      v89 = v45;
      idBareDctBase::SetQuality_Xenon(this: &v107, luminanceQuality: v89, chrominanceQuality: v45, alphaQuality: v89);
      v46 = *((unsigned __int16 *)inPageHeader + 3);
      v47 = *((unsigned __int16 *)inPageHeader + 4);
      idBareDctDecoder::DecompressImageMono_Xenon(
        this: &v107,
        inBuf: &inPageData[*((unsigned __int16 *)inPageHeader + 5) + v46 + v47],
        outBuf: tempData,
        width: 32,
        inputBytes: *((unsigned __int16 *)inPageHeader + 6) | 0x2000000000LL);
      idBareDctDecoder::idBareDctDecoder(this: &v105);
      idBareDctDecoder::SetHuffmanTables(
        this: &v105,
        tableYDC: &v109,
        tableYAC: &v108,
        tableCoCgDC: nullptr,
        tableCoCgAC: nullptr,
        tableADC: nullptr,
        tableAAC: nullptr);
      v48 = inPageHeader[2];
      v89 = v48;
      idBareDctBase::SetQuality_Xenon(this: &v105, luminanceQuality: v89, chrominanceQuality: v48, alphaQuality: v89);
      v89 = v47;
      v105.dataBytes = v47;
      v105.imageWidth = 128;
      HIDWORD(v13) = 0;
      v105.data = &inPageData[v46];
      v105.imageHeight = 128;
      memset(&v105.dcY, 0, 32);
      v101.srcPadding = 0;
      v101.dstPadding = v44 - 64;
      v93 = 0;
      v94 = 0;
      while ( 1 )
      {
        v95 = 0;
        v92 = nullptr;
        v89 = (unsigned int)(HIDWORD(v13) + 384) >> 2;
        while ( 1 )
        {
          idBareDctDecoder::DecompressOneTileNormalMap_Xenon(this: &v105, normalMap: v11, stride: 64, a4: v50, a5: v49);
          v51 = (HIDWORD(v13) >> 2) + v13;
          v52 = ((unsigned int)(HIDWORD(v13) + 256) >> 2) + v13;
          v53 = ((unsigned int)(HIDWORD(v13) + 128) >> 2) + v13;
          v54 = &tempData[v51];
          BYTE3(v13) = tempData[v51];
          v55 = v89 + v13;
          v56 = v8[v51];
          v57 = &v8[v51];
          v58 = &tempData[v52];
          v59 = tempData[v51 + 1];
          LOBYTE(v51) = tempData[v51 + 2];
          v60 = &tempData[v89 + v13];
          v61 = *v60;
          LOBYTE(v13) = tempData[v53];
          v84 = tempData[v52];
          v85 = v13;
          LODWORD(v13) = &v8[v52];
          v88 = v51;
          v86 = v59;
          v98 = &v8[v55];
          v87 = v61;
          v63 = v57[2];
          v64 = v57[1];
          LOBYTE(v57) = v57[3];
          LOBYTE(v51) = tempData[v53 + 1];
          v65 = tempData[v53 + 2];
          v66 = tempData[v52 + 1];
          v67 = tempData[v52 + 2];
          LOBYTE(v52) = v8[v52];
          LOBYTE(v54) = v54[3];
          v68 = tempData[v53 + 3];
          v69 = tempData[v55 + 1];
          v70 = tempData[v55 + 2];
          v62 = &v8[v53];
          LOBYTE(v55) = v8[v55];
          v71 = v84;
          v84 = v8[v53];
          v72 = v85;
          LOBYTE(v53) = v88;
          v88 = v63;
          v85 = v52;
          v73 = v62[1];
          LOBYTE(v52) = *(_BYTE *)(v13 + 1);
          v74 = v86;
          v86 = (unsigned __int8)v57;
          v75 = v98;
          v76 = v87;
          v87 = v73;
          v91 = v52;
          v77 = v62[2];
          LOBYTE(v52) = *(_BYTE *)(v13 + 2);
          LOBYTE(v58) = v58[3];
          LOBYTE(v60) = v60[3];
          LOBYTE(v62) = v62[3];
          LOBYTE(v13) = *(_BYTE *)(v13 + 3);
          v78 = v98[1];
          *v11 = BYTE3(v13);
          v11[16] = v74;
          v11[32] = v53;
          v11[48] = (unsigned __int8)v54;
          v11[256] = v72;
          v11[272] = v51;
          v11[288] = v65;
          v11[304] = v68;
          v11[512] = v71;
          v11[528] = v66;
          v11[544] = v67;
          LOBYTE(v53) = v84;
          v79 = v75;
          v11[560] = (unsigned __int8)v58;
          LOBYTE(v58) = v88;
          LOBYTE(v75) = v86;
          v11[816] = (unsigned __int8)v60;
          v11[258] = v53;
          LOBYTE(v53) = v87;
          v11[34] = (unsigned __int8)v58;
          LOBYTE(v58) = v79[2];
          LOBYTE(v79) = v79[3];
          v11[50] = (unsigned __int8)v75;
          v11[274] = v53;
          LOBYTE(v53) = v85;
          v11[306] = (unsigned __int8)v62;
          v11[546] = v52;
          v11[770] = v55;
          v11[786] = v78;
          v11[514] = v53;
          LOBYTE(v53) = v91;
          v11[802] = (unsigned __int8)v58;
          v11[818] = (unsigned __int8)v79;
          v11[768] = v76;
          v11[784] = v69;
          v11[800] = v70;
          v11[2] = v56;
          v11[18] = v64;
          v11[290] = v77;
          v11[530] = v53;
          v11[562] = v13;
          v80 = v93;
          v81 = v95;
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v101,
            inBuf: v11,
            outBuf: &v99[4 * v93 + 4 * v95],
            width: 16,
            height: 16);
          HIDWORD(v49) = v92;
          v50 = v81 + 16;
          LODWORD(v13) = v92 + 4;
          v95 = v81 + 16;
          v92 = (unsigned __int8 *)v13;
          if ( (unsigned int)v13 >= 0x20 )
            break;
          HIDWORD(v13) = v94;
          v8 = v96;
          tempData = v97;
        }
        HIDWORD(v13) = v94 + 512;
        v93 = v80 + v90;
        v94 = HIDWORD(v13);
        if ( HIDWORD(v13) >= 0x1000 )
          break;
        v8 = v96;
        LODWORD(v13) = 0;
        tempData = v97;
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v105);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v107);
    }
  }
}


// ========================================================================
// __unwind$73894
// EA  : 0x8292F618
// RVA : 0x0092F618
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_73894()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11600 + 240));
}


// ========================================================================
// __unwind$73895
// EA  : 0x8292F640
// RVA : 0x0092F640
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_73895()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11600 + 1200));
}


// ========================================================================
// __unwind$73896
// EA  : 0x8292F668
// RVA : 0x0092F668
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_73896()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11600 + 1680));
}


// ========================================================================
// __unwind$73897
// EA  : 0x8292F690
// RVA : 0x0092F690
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_73897()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 11600 + 720));
}


// ========================================================================
// ?TestPerformance_DCT_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x8292F6C0
// RVA : 0x0092F6C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void __fastcall TestPerformance_DCT_DXT(const transcodeParms_t *parms)
{
  unsigned __int64 v2; // r30
  const unsigned __int8 *inPageData; // r25
  unsigned __int8 *tempData; // r24
  __int64 v5; // r8
  int v6; // r6
  int v7; // r26
  int v8; // r9
  int v9; // r10
  int v10; // r11
  bool v11; // cr58
  int v12; // r10
  int j; // r28
  int i; // r28
  __int64 v15; // r8
  int v16; // r6
  int v17; // r11
  int v18; // r26
  int k; // r28
  __int64 v20; // r8
  int v21; // r6
  int v22; // r28
  int v23; // r10
  const unsigned __int8 *v24; // r11
  int m; // r29
  unsigned __int8 *v26; // r29
  const unsigned __int8 *inPageHeader; // r27
  int imageFlags; // r11
  unsigned __int8 v29; // r11
  int v30; // r27
  int n; // r30
  int ii; // r30
  int jj; // r27
  int kk; // r30
  int mm; // r27
  int nn; // r30
  idDxtEncoder v37; // [sp+60h] [-2A50h] BYREF
  idBareDctDecoder v38; // [sp+80h] [-2A30h] BYREF
  idBareDctDecoder v39; // [sp+260h] [-2850h] BYREF
  idBareDctDecoder v40; // [sp+440h] [-2670h] BYREF
  idBareDCTHuffmanTable v41; // [sp+620h] [-2490h] BYREF
  idBareDCTHuffmanTable v42; // [sp+F30h] [-1B80h] BYREF
  idBareDCTHuffmanTable v43; // [sp+1840h] [-1270h] BYREF
  idBareDCTHuffmanTable v44; // [sp+2150h] [-960h] BYREF

  LODWORD(v2) = 0;
  if ( (parms->imageFlags & 0x10) != 0 )
  {
    HIDWORD(v2) = parms->inPageHeader;
    inPageData = parms->inPageData;
    tempData = parms->tempData;
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v41, huffmanType: 0, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v43, huffmanType: 1u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v44, huffmanType: 2u, encode: false);
    idBareDCTHuffmanTable::idBareDCTHuffmanTable(this: &v42, huffmanType: 3u, encode: false);
    if ( (parms->imageFlags & 1) != 0 )
    {
      idBareDctDecoder::idBareDctDecoder(this: &v38);
      idBareDctDecoder::SetHuffmanTables(
        this: &v38,
        tableYDC: &v41,
        tableYAC: &v43,
        tableCoCgDC: &v44,
        tableCoCgAC: &v42,
        tableADC: nullptr,
        tableAAC: nullptr);
      idBareDctBase::SetQuality_Xenon(
        this: &v38,
        luminanceQuality: *(unsigned __int8 *)(HIDWORD(v2) + 3),
        chrominanceQuality: *(unsigned __int8 *)(HIDWORD(v2) + 3),
        alphaQuality: *(unsigned __int8 *)(HIDWORD(v2) + 3));
      v7 = 8;
      v8 = *(unsigned __int16 *)(HIDWORD(v2) + 10);
      v9 = *(_BYTE *)(HIDWORD(v2) + 5) & 4;
      v10 = *(unsigned __int16 *)(HIDWORD(v2) + 6);
      v38.imageWidth = 128;
      v11 = v9 == 0;
      v12 = *(unsigned __int16 *)(HIDWORD(v2) + 8);
      v38.imageHeight = 128;
      v38.bitCnt = v2;
      v38.bitBuff = v2;
      memset(&v38.dcY, 0, 16);
      v38.dataBytes = v8;
      v38.data = &inPageData[v12 + v10];
      if ( v11 )
      {
        do
        {
          for ( i = 8; i != 0; --i )
            idBareDctDecoder::DecompressOneTileRGB_Xenon(this: &v38, rgb: tempData, stride: 64, a4: v6, a5: v5);
          --v7;
        }
        while ( v7 != 0 );
      }
      else
      {
        do
        {
          for ( j = 8; j != 0; --j )
            idBareDctDecoder::DecompressOneTileGrayScale_Xenon(this: &v38, rgb: tempData, stride: 64, a4: v6, a5: v5);
          --v7;
        }
        while ( v7 != 0 );
      }
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v38);
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      idBareDctDecoder::idBareDctDecoder(this: &v40);
      idBareDctDecoder::SetHuffmanTables(
        this: &v40,
        tableYDC: &v41,
        tableYAC: &v43,
        tableCoCgDC: &v44,
        tableCoCgAC: &v42,
        tableADC: nullptr,
        tableAAC: nullptr);
      idBareDctBase::SetQuality_Xenon(
        this: &v40,
        luminanceQuality: (unsigned __int8)*(_BYTE *)HIDWORD(v2),
        chrominanceQuality: *(unsigned __int8 *)(HIDWORD(v2) + 1),
        alphaQuality: (unsigned __int8)*(_BYTE *)HIDWORD(v2));
      v17 = *(unsigned __int16 *)(HIDWORD(v2) + 6);
      v18 = 8;
      v40.data = inPageData;
      v40.imageWidth = 128;
      v40.imageHeight = 128;
      v40.bitCnt = v2;
      v40.dataBytes = v17;
      v40.bitBuff = v2;
      memset(&v40.dcY, 0, 16);
      do
      {
        for ( k = 8; k != 0; --k )
          idBareDctDecoder::DecompressOneTileYCoCg_Xenon(this: &v40, rgb: tempData, stride: 64, a4: v16, a5: v15);
        --v18;
      }
      while ( v18 != 0 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v40);
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      idBareDctDecoder::idBareDctDecoder(this: &v39);
      idBareDctDecoder::SetHuffmanTables(
        this: &v39,
        tableYDC: &v41,
        tableYAC: &v43,
        tableCoCgDC: nullptr,
        tableCoCgAC: nullptr,
        tableADC: nullptr,
        tableAAC: nullptr);
      idBareDctBase::SetQuality_Xenon(
        this: &v39,
        luminanceQuality: *(unsigned __int8 *)(HIDWORD(v2) + 2),
        chrominanceQuality: *(unsigned __int8 *)(HIDWORD(v2) + 2),
        alphaQuality: *(unsigned __int8 *)(HIDWORD(v2) + 2));
      v22 = 8;
      v23 = *(unsigned __int16 *)(HIDWORD(v2) + 8);
      v24 = &inPageData[*(unsigned __int16 *)(HIDWORD(v2) + 6)];
      v39.imageWidth = 128;
      v39.imageHeight = 128;
      v39.data = v24;
      v39.bitCnt = v2;
      v39.dataBytes = v23;
      v39.bitBuff = v2;
      memset(&v39.dcY, 0, 16);
      do
      {
        for ( m = 8; m != 0; --m )
          idBareDctDecoder::DecompressOneTileNormalMap_Xenon(
            this: &v39,
            normalMap: tempData,
            stride: 64,
            a4: v21,
            a5: v20);
        --v22;
      }
      while ( v22 != 0 );
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v39);
    }
  }
  if ( (parms->imageFlags & 8) != 0 )
  {
    v26 = parms->tempData;
    inPageHeader = parms->inPageHeader;
    memset(Dst: v26, Val: 0, Size: 0x400u);
    imageFlags = parms->imageFlags;
    v37.dstPadding = 0;
    v37.srcPadding = 0;
    if ( (imageFlags & 1) != 0 )
    {
      v29 = inPageHeader[5];
      v30 = 8;
      if ( (v29 & 8) != 0 )
      {
        do
        {
          for ( n = 8; n != 0; --n )
            idDxtEncoder::CompressImageDXT1Fast_Xenon(this: &v37, inBuf: v26, outBuf: v26 + 1024, width: 16, height: 16);
          --v30;
        }
        while ( v30 != 0 );
      }
      else
      {
        do
        {
          for ( ii = 8; ii != 0; --ii )
            idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
              this: &v37,
              inBuf: v26,
              outBuf: v26 + 1024,
              width: 16,
              height: 16);
          --v30;
        }
        while ( v30 != 0 );
      }
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      for ( jj = 8; jj != 0; --jj )
      {
        for ( kk = 8; kk != 0; --kk )
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(this: &v37, inBuf: v26, outBuf: v26 + 1024, width: 16, height: 16);
      }
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      for ( mm = 8; mm != 0; --mm )
      {
        for ( nn = 8; nn != 0; --nn )
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v37,
            inBuf: v26,
            outBuf: v26 + 1024,
            width: 16,
            height: 16);
      }
    }
  }
}


// ========================================================================
// __unwind$74241
// EA  : 0x8292FAE4
// RVA : 0x0092FAE4
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_74241()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 10928 + 128));
}


// ========================================================================
// __unwind$74242
// EA  : 0x8292FB0C
// RVA : 0x0092FB0C
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_74242()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 10928 + 1088));
}


// ========================================================================
// __unwind$74243
// EA  : 0x8292FB34
// RVA : 0x0092FB34
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

void _unwind_74243()
{
  int v0; // r12

  bfx::Planner3DInstance::Stop(this: (bfx::Planner3DInstance *)(v0 - 10928 + 608));
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_DCT_DXT''
// EA  : 0x83358090
// RVA : 0x01358090
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dct_dxt.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_DCT_DXT__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_DCT_DXT,
           function: (void (__fastcall *)(void *))TranscodePage_DCT_DXT,
           name: "TranscodePage_DCT_DXT");
}

