
// ========================================================================
// ?TranscodePage_DXT_DXT@@YAXABUtranscodeParms_t@@@Z
// EA  : 0x82931870
// RVA : 0x00931870
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dxt_dxt.cpp
// ========================================================================

void __fastcall TranscodePage_DXT_DXT(const transcodeParms_t *parms)
{
  int imageFlags; // r11
  const unsigned __int8 *inPageData; // r28
  int v4; // r11
  int v5; // r23
  int v6; // r29
  int v7; // r30
  int v8; // r24
  int v9; // r25
  int v10; // r26
  int v11; // r27
  int v12; // r23
  int v13; // r29
  int v14; // r30
  const unsigned __int8 *v15; // r28
  int v16; // r24
  int v17; // r25
  int v18; // r26
  int v19; // r27
  int v20; // r23
  int v21; // r29
  int v22; // r30
  const unsigned __int8 *v23; // r28
  int v24; // r24
  int v25; // r25
  int v26; // r26
  int v27; // r27
  int v28; // r28
  int v29; // r29
  int i; // r30
  int v31; // r28
  int v32; // r29
  int j; // r30
  int v34; // r28
  int v35; // r29
  int k; // r30

  imageFlags = parms->imageFlags;
  parms->startedExecution = true;
  if ( imageFlags != 0 )
  {
    inPageData = parms->inPageData;
    v4 = imageFlags & 1;
    if ( inPageData != nullptr )
    {
      if ( v4 != 0 )
      {
        v5 = parms->targetBytePitch[0];
        v6 = 0;
        v7 = 256;
        v8 = 4 * v5;
        v9 = 3 * v5;
        v10 = 2 * v5;
        v11 = 8;
        do
        {
          memcpy(Dst: &parms->targetImage[0][v6], Src: &inPageData[8 * ((v7 - 256) / 4)], Size: 0x100u);
          memcpy(Dst: &parms->targetImage[0][v6 + v5], Src: &inPageData[8 * ((v7 - 128) / 4)], Size: 0x100u);
          memcpy(Dst: &parms->targetImage[0][v10], Src: &inPageData[8 * (v7 / 4)], Size: 0x100u);
          memcpy(Dst: &parms->targetImage[0][v9], Src: &inPageData[8 * ((v7 + 128) / 4)], Size: 0x100u);
          --v11;
          v6 += v8;
          v10 += v8;
          v9 += v8;
          v7 += 512;
        }
        while ( v11 != 0 );
      }
      if ( (parms->imageFlags & 2) != 0 )
      {
        v12 = parms->targetBytePitch[1];
        v13 = 0;
        v14 = 256;
        v15 = parms->inPageData + 0x2000;
        v16 = 4 * v12;
        v17 = 3 * v12;
        v18 = 2 * v12;
        v19 = 8;
        do
        {
          memcpy(Dst: &parms->targetImage[1][v13], Src: &v15[16 * ((v14 - 256) / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[1][v13 + v12], Src: &v15[16 * ((v14 - 128) / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[1][v18], Src: &v15[16 * (v14 / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[1][v17], Src: &v15[16 * ((v14 + 128) / 4)], Size: 0x200u);
          --v19;
          v13 += v16;
          v18 += v16;
          v17 += v16;
          v14 += 512;
        }
        while ( v19 != 0 );
      }
      if ( (parms->imageFlags & 4) != 0 )
      {
        v20 = parms->targetBytePitch[2];
        v21 = 0;
        v22 = 256;
        v23 = parms->inPageData + 24576;
        v24 = 4 * v20;
        v25 = 3 * v20;
        v26 = 2 * v20;
        v27 = 8;
        do
        {
          memcpy(Dst: &parms->targetImage[2][v21], Src: &v23[16 * ((v22 - 256) / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[2][v21 + v20], Src: &v23[16 * ((v22 - 128) / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[2][v26], Src: &v23[16 * (v22 / 4)], Size: 0x200u);
          memcpy(Dst: &parms->targetImage[2][v25], Src: &v23[16 * ((v22 + 128) / 4)], Size: 0x200u);
          --v27;
          v21 += v24;
          v26 += v24;
          v25 += v24;
          v22 += 512;
        }
        while ( v27 != 0 );
      }
    }
    else
    {
      if ( v4 != 0 )
      {
        v28 = parms->targetBytePitch[0];
        v29 = 0;
        for ( i = 32; i != 0; --i )
        {
          memset(Dst: &parms->targetImage[0][v29], Val: 0, Size: 0x100u);
          v29 += v28;
        }
      }
      if ( (parms->imageFlags & 2) != 0 )
      {
        v31 = parms->targetBytePitch[1];
        v32 = 0;
        for ( j = 32; j != 0; --j )
        {
          memset(Dst: &parms->targetImage[1][v32], Val: 0, Size: 0x200u);
          v32 += v31;
        }
      }
      if ( (parms->imageFlags & 4) != 0 )
      {
        v34 = parms->targetBytePitch[2];
        v35 = 0;
        for ( k = 32; k != 0; --k )
        {
          memset(Dst: &parms->targetImage[2][v35], Val: 0, Size: 0x200u);
          v35 += v34;
        }
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'register_TranscodePage_DXT_DXT''
// EA  : 0x833580E8
// RVA : 0x013580E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\transcode_dxt_dxt.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_TranscodePage_DXT_DXT__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_TranscodePage_DXT_DXT,
           function: (void (__fastcall *)(void *))TranscodePage_DXT_DXT,
           name: "TranscodePage_DXT_DXT");
}

