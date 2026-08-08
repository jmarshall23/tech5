
// ========================================================================
// ?VideoTranscodeJob@@YAXAAUvideoTranscodeParms_t@@@Z
// EA  : 0x82938CD8
// RVA : 0x00938CD8
// PDB : w:\tech5\engine\renderer\jobs\videotranscode\videotranscode.cpp
// ========================================================================

void __fastcall VideoTranscodeJob(videoTranscodeParms_t *videoParms)
{
  unsigned __int8 dctQualityLuma; // r6
  __int64 v2; // r9
  unsigned __int8 dctQualityChroma; // r5
  __int64 *v4; // r11
  int v5; // ctr
  int targetBytePitch; // r6
  unsigned __int8 *dctBuffer; // r4
  char v8; // [sp+CFh] [-D01h] BYREF
  __int64 v9; // [sp+D20h] [-B0h] BYREF
  __int64 v10; // [sp+D28h] [-A8h] BYREF
  transcodeParms_t v11; // [sp+D30h] [-A0h] BYREF

  HIDWORD(v2) = videoParms->dctBufferSize;
  dctQualityLuma = videoParms->dctQualityLuma;
  LODWORD(v2) = 0;
  dctQualityChroma = videoParms->dctQualityChroma;
  v4 = &v10;
  v9 = v2;
  v10 = v2;
  HIBYTE(v9) = dctQualityLuma;
  v5 = 16;
  LOWORD(v9) = WORD1(v2);
  BYTE1(v9) = dctQualityChroma;
  do
  {
    *++v4 = v2;
    --v5;
  }
  while ( v5 != 0 );
  LODWORD(v2) = videoParms->dxtBuffer;
  targetBytePitch = videoParms->targetBytePitch;
  dctBuffer = videoParms->dctBuffer;
  v11.imageFlags = 2;
  v11.inPageDataLength = HIDWORD(v2);
  v11.inPageHeader = (const unsigned __int8 *)&v9;
  v11.inPageData = dctBuffer;
  v11.tempSize = 3072;
  v11.targetImage[0] = (unsigned __int8 *)v2;
  v11.targetImage[1] = (unsigned __int8 *)v2;
  v11.targetImage[2] = (unsigned __int8 *)v2;
  v11.targetBytePitch[0] = targetBytePitch;
  v11.targetBytePitch[1] = targetBytePitch;
  v11.tempData = (unsigned __int8 *)((unsigned int)&v8 & 0xFFFFFF80);
  v11.targetBytePitch[2] = targetBytePitch;
  v11.diskOffsetScale = 64;
  TranscodePage_DCT_DXT(parms: &v11);
}


// ========================================================================
// `dynamic initializer for 'register_VideoTranscodeJob''
// EA  : 0x833581F0
// RVA : 0x013581F0
// PDB : w:\tech5\engine\renderer\jobs\videotranscode\videotranscode.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_VideoTranscodeJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_VideoTranscodeJob,
           function: (void (__fastcall *)(void *))VideoTranscodeJob,
           name: "VideoTranscodeJob");
}

