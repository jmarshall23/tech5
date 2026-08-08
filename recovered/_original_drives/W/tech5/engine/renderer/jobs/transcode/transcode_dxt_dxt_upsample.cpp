
// ========================================================================
// ?TranscodePage_DXT_DXT_upsample@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82932208
// RVA : 0x00932208
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dxt_dxt_upsample.cpp
// ========================================================================

void __fastcall TranscodePage_DXT_DXT_upsample(const transcodeParms_t *parms)
{
  int imageFlags; // r4
  int v2; // r11
  int upsampleLevel; // r8
  unsigned int v5; // r14
  unsigned int v6; // r25
  int i; // r9
  int v8; // r10
  int v9; // r10
  int v10; // r19
  unsigned __int8 *tempData; // r28
  int v12; // r26
  const unsigned __int8 *inPageData; // r18
  int v14; // r23
  unsigned int v15; // r27
  unsigned int v16; // r20
  unsigned int v17; // r21
  int v18; // r11
  int v19; // r29
  int v20; // r22
  const unsigned __int8 *v21; // r30
  int v22; // r29
  unsigned int j; // r30
  int v24; // r27
  int v25; // r11
  int v26; // r16
  unsigned __int8 *v27; // r29
  unsigned int upsampleNoise; // r6
  const unsigned __int8 *v29; // r15
  char pageLevel; // r4
  int upsampleSharpen; // r22
  int v32; // r21
  int v33; // r24
  unsigned int v34; // r28
  unsigned int v35; // r18
  unsigned int v36; // r19
  int v37; // r11
  int v38; // r23
  int v39; // r20
  const unsigned __int8 *v40; // r30
  unsigned int k; // r30
  int v42; // r19
  int v43; // r28
  int v44; // r11
  unsigned __int8 *v45; // r29
  const unsigned __int8 *v46; // r18
  int v47; // r24
  unsigned int v48; // r27
  unsigned int v49; // r20
  unsigned int v50; // r21
  int v51; // r11
  int v52; // r23
  int v53; // r22
  const unsigned __int8 *v54; // r30
  unsigned int m; // r30
  int v56; // [sp+8h] [-168h]
  int v57; // [sp+Ch] [-164h]
  int v58; // [sp+10h] [-160h]
  int v59; // [sp+14h] [-15Ch]
  int v60; // [sp+18h] [-158h]
  unsigned int v61; // [sp+1Ch] [-154h]
  int v62; // [sp+20h] [-150h]
  unsigned int v63; // [sp+24h] [-14Ch]
  int v64; // [sp+28h] [-148h]
  unsigned int v65; // [sp+2Ch] [-144h]
  int v66; // [sp+30h] [-140h]
  int v67; // [sp+34h] [-13Ch]
  int v68; // [sp+38h] [-138h]
  unsigned int v69; // [sp+3Ch] [-134h]
  int v70; // [sp+40h] [-130h]
  unsigned int v71; // [sp+44h] [-12Ch]
  int v72; // [sp+48h] [-128h]
  int v73; // [sp+4Ch] [-124h]
  int v74; // [sp+50h] [-120h]
  int v75; // [sp+58h] [-118h]
  int v76; // [sp+60h] [-110h]
  idDxtDecoder v77; // [sp+70h] [-100h] BYREF
  idDxtEncoder v78; // [sp+80h] [-F0h] BYREF
  idDxtEncoder v79; // [sp+A0h] [-D0h] BYREF
  idDxtEncoder v80; // [sp+C0h] [-B0h] BYREF

  imageFlags = parms->imageFlags;
  v2 = 1;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    upsampleLevel = parms->upsampleLevel;
    v5 = 0;
    v6 = 0;
    for ( i = 0; i < upsampleLevel; v2 *= 2 )
    {
      v8 = 124 * v2;
      if ( (parms->upsampleX & v2) == 0 )
        v8 = 4 * v2;
      v5 += v8;
      v9 = 124 * v2;
      if ( (parms->upsampleY & v2) == 0 )
        v9 = 4 * v2;
      ++i;
      v6 += v9;
    }
    if ( (imageFlags & 1) != 0 )
    {
      v10 = parms->targetBytePitch[0];
      tempData = parms->tempData;
      v12 = -1;
      inPageData = parms->inPageData;
      v78.srcPadding = 0;
      v78.dstPadding = v10 - 32;
      v14 = 0;
      v15 = 0;
      v16 = (int)((4 << upsampleLevel) + v6) / 16 + 1;
      v17 = (int)(v6 - (4 << upsampleLevel)) / 16;
      do
      {
        v18 = parms->upsampleLevel;
        v19 = (v16 >> v18) & 7;
        v20 = (v17 >> v18) & 7;
        if ( v12 < v19 )
        {
          v21 = &inPageData[1024 * v12];
          do
          {
            ++v12;
            v21 += 1024;
            if ( v12 >= v20 )
              idDxtDecoder::DecompressImageDXT1(
                this: &v77,
                inBuf: v21,
                outBuf: &tempData[((v12 << 13) & 0x2000) + 1024],
                width: 128,
                height: 16);
          }
          while ( v12 < v19 );
        }
        v22 = 0;
        for ( j = 0; j < 0x80; j += 16 )
        {
          UpSample16x16_Bicubic_1(
            dst: tempData,
            dstX: j,
            dstY: v15,
            dstBytePitch: 0x40u,
            src: tempData + 1024,
            srcX: v5,
            srcY: v6,
            srcMaskY: 0x1Fu,
            upsampleLevel: v56,
            sharpenScale: v57,
            noiseScale: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: parms->upsampleLevel,
            a29: v75,
            a30: 0,
            a31: v76,
            a32: 0);
          idDxtEncoder::CompressImageDXT1AlphaFast_Xenon(
            this: &v78,
            inBuf: tempData,
            outBuf: &parms->targetImage[0][4 * v14 + 4 * v22],
            width: 16,
            height: 16);
          v22 += 8;
        }
        v15 += 16;
        ++v17;
        ++v16;
        v14 += v10;
      }
      while ( v15 < 0x80 );
    }
    if ( (parms->imageFlags & 2) != 0 )
    {
      v24 = -1;
      v25 = 4 << parms->upsampleLevel;
      v26 = parms->targetBytePitch[1];
      v27 = parms->tempData;
      upsampleNoise = parms->upsampleNoise;
      v29 = parms->inPageData;
      pageLevel = parms->pageLevel;
      upsampleSharpen = parms->upsampleSharpen;
      v79.srcPadding = 0;
      v79.dstPadding = v26 - 64;
      v32 = upsampleNoise >> pageLevel;
      v33 = 0;
      v34 = 0;
      v35 = (int)(v25 + v6) / 16 + 1;
      v36 = (int)(v6 - v25) / 16;
      do
      {
        v37 = parms->upsampleLevel;
        v38 = (v35 >> v37) & 7;
        v39 = (v36 >> v37) & 7;
        if ( v24 < v38 )
        {
          v40 = &v29[2048 * v24];
          do
          {
            ++v24;
            v40 += 2048;
            if ( v24 >= v39 )
              idDxtDecoder::DecompressYCoCgDXT5(
                this: &v77,
                inBuf: v40,
                outBuf: &v27[((v24 << 13) & 0x2000) + 1024],
                width: 128,
                height: 16);
          }
          while ( v24 < v38 );
        }
        for ( k = 0; k < 0x80; k += 16 )
        {
          UpSample16x16_Bicubic_1(
            dst: v27,
            dstX: k,
            dstY: v34,
            dstBytePitch: 0x40u,
            src: v27 + 1024,
            srcX: v5,
            srcY: v6,
            srcMaskY: 0x1Fu,
            upsampleLevel: v56,
            sharpenScale: v57,
            noiseScale: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: parms->upsampleLevel,
            a29: v75,
            a30: upsampleSharpen,
            a31: v76,
            a32: v32);
          idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(
            this: &v79,
            inBuf: v27,
            outBuf: &parms->targetImage[1][4 * v33 + 4 * k],
            width: 16,
            height: 16);
        }
        v34 += 16;
        ++v36;
        ++v35;
        v33 += v26;
      }
      while ( v34 < 0x80 );
    }
    if ( (parms->imageFlags & 4) != 0 )
    {
      v42 = parms->targetBytePitch[2];
      v43 = -1;
      v44 = 4 << parms->upsampleLevel;
      v45 = parms->tempData;
      v46 = parms->inPageData;
      v80.srcPadding = 0;
      v80.dstPadding = v42 - 64;
      v47 = 0;
      v48 = 0;
      v49 = (int)(v44 + v6) / 16 + 1;
      v50 = (int)(v6 - v44) / 16;
      do
      {
        v51 = parms->upsampleLevel;
        v52 = (v49 >> v51) & 7;
        v53 = (v50 >> v51) & 7;
        if ( v43 < v52 )
        {
          v54 = &v46[2048 * v43];
          do
          {
            ++v43;
            v54 += 2048;
            if ( v43 >= v53 )
              idDxtDecoder::DecompressImageDXT5(
                this: &v77,
                inBuf: v54,
                outBuf: &v45[((v43 << 13) & 0x2000) + 1024],
                width: 128,
                height: 16);
          }
          while ( v43 < v52 );
        }
        for ( m = 0; m < 0x80; m += 16 )
        {
          UpSample16x16_Bicubic_1(
            dst: v45,
            dstX: m,
            dstY: v48,
            dstBytePitch: 0x40u,
            src: v45 + 1024,
            srcX: v5,
            srcY: v6,
            srcMaskY: 0x1Fu,
            upsampleLevel: v56,
            sharpenScale: v57,
            noiseScale: v58,
            a12: v59,
            a13: v60,
            a14: v61,
            a15: v62,
            a16: v63,
            a17: v64,
            a18: v65,
            a19: v66,
            a20: v67,
            a21: v68,
            a22: v69,
            a23: v70,
            a24: v71,
            a25: v72,
            a26: v73,
            a27: v74,
            a28: parms->upsampleLevel,
            a29: v75,
            a30: 0,
            a31: v76,
            a32: 0);
          idDxtEncoder::CompressNormalMapDXT5Fast_Xenon(
            this: &v80,
            inBuf: v45,
            outBuf: &parms->targetImage[2][4 * m + 4 * v47],
            width: 16,
            height: 16);
        }
        v48 += 16;
        ++v50;
        ++v49;
        v47 += v42;
      }
      while ( v48 < 0x80 );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_DXT_DXT_upsample''
// EA  : 0x83358120
// RVA : 0x01358120
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dxt_dxt_upsample.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_DXT_DXT_upsample__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_DXT_DXT_upsample,
           function: (void (__fastcall *)(void *))TranscodePage_DXT_DXT_upsample,
           name: "TranscodePage_DXT_DXT_upsample");
}

