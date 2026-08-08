
// ========================================================================
// binkMemAlloc
// EA  : 0x82949CF0
// RVA : 0x00949CF0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void *__fastcall binkMemAlloc(unsigned int bytes)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\renderer\\RenderSystem_bink.cpp(59) : TAG_BINK",
           size: bytes,
           tag: TAG_BINK,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?SetInfo@idBinkIOWrapper@@CAXPAUBINKIO@@PAXIII@Z
// EA  : 0x82949D18
// RVA : 0x00949D18
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBinkIOWrapper::SetInfo(
        BINKIO *Bnkio,
        void *Buf,
        unsigned int Size,
        unsigned int FileSize,
        unsigned int simulate)
{
  __int64 v5; // r11 OVERLAPPED

  *(__int64 *)((char *)&v5 + 4) = *(_QWORD *)Bnkio->iodata;
  LODWORD(v5) = FileSize;
  if ( HIDWORD(v5) > FileSize )
    *(_QWORD *)Bnkio->iodata = v5;
}


// ========================================================================
// ?BinkVideoIsLoaded@idRenderSystemLocal@@UAA_NXZ
// EA  : 0x82949D30
// RVA : 0x00949D30
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

BOOL __fastcall idRenderSystemLocal::BinkVideoIsLoaded(idRenderSystemLocal *this)
{
  return bink != nullptr;
}


// ========================================================================
// ?BinkVideoIsPlaying@idRenderSystemLocal@@UAA_NXZ
// EA  : 0x82949D48
// RVA : 0x00949D48
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

BOOL __fastcall idRenderSystemLocal::BinkVideoIsPlaying(idRenderSystemLocal *this)
{
  return (_cntlzw(this->renderThread->renderMode - 2) & 0x20) != 0;
}


// ========================================================================
// ?WaitForNextVideoFrame@idRenderSystemLocal@@QAA_NXZ
// EA  : 0x82949D60
// RVA : 0x00949D60
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::WaitForNextVideoFrame(idRenderSystemLocal *this)
{
  int result; // r3

  if ( bink == nullptr )
    return 0;
  if ( bink->FrameNum != bink->Frames )
    return 1;
  result = 0;
  if ( videoFlags != VIDEO_EXIT )
    return 1;
  return result;
}


// ========================================================================
// ?bink_percentage_full@@YAIPAUBINK@@@Z
// EA  : 0x82949DA8
// RVA : 0x00949DA8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

unsigned int __fastcall bink_percentage_full(BINK *bink)
{
  int v2; // r10
  _BYTE v3[44]; // [sp+50h] [-40h] BYREF
  unsigned int v4; // [sp+7Ch] [-14h]
  int v5; // [sp+80h] [-10h]

  BinkGetRealtime(a1: bink, a2: v3, a3: 0);
  if ( v4 == 0 )
    return 100;
  v2 = v5;
  __twllei(v4, 0);
  return 100 * v2 / v4;
}


// ========================================================================
// ?GetBinkWidth@idRenderSystemLocal@@QBAIXZ
// EA  : 0x82949E00
// RVA : 0x00949E00
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

unsigned int __fastcall idRenderSystemLocal::GetBinkWidth(idRenderSystemLocal *this)
{
  unsigned int result; // r3

  result = 0;
  if ( bink != nullptr )
    return bink->Width;
  return result;
}


// ========================================================================
// ?GetBinkHeight@idRenderSystemLocal@@QBAIXZ
// EA  : 0x82949E20
// RVA : 0x00949E20
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

unsigned int __fastcall idRenderSystemLocal::GetBinkHeight(idRenderSystemLocal *this)
{
  unsigned int result; // r3

  result = 0;
  if ( bink != nullptr )
    return bink->Height;
  return result;
}


// ========================================================================
// ?GetBinkTime@idRenderSystemLocal@@QBAMXZ
// EA  : 0x82949E40
// RVA : 0x00949E40
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRenderSystemLocal::GetBinkTime(
        idRenderSystemLocal *this,
        int a2,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  __int64 v6; // r7
  double v7; // fp1

  if ( bink == nullptr || (LODWORD(a6) = binkRealTime.FrameNum, binkRealTime.FrameNum == -1) )
  {
    v7 = 0.0;
  }
  else
  {
    *(__int64 *)((char *)&a6 + 4) = *(_QWORD *)&binkRealTime.FrameRate;
    v7 = (float)((float)a6 / (float)((float)v6 / (float)*(__int64 *)&binkRealTime.FrameRate));
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?bink_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82949EB8
// RVA : 0x00949EB8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall bink_f(const idCmdArgs *args)
{
  char *v1; // r30
  idRenderSystem_vtbl *v2; // r31
  idRenderVideoOverlay *v3; // r29
  void *v4; // r3
  idSysLocal v5; // [sp+50h] [-D0h] BYREF
  int v6; // [sp+54h] [-CCh]
  int v7; // [sp+58h] [-C8h]
  float v8[6]; // [sp+70h] [-B0h] BYREF
  char v9; // [sp+88h] [-98h]
  bool v10; // [sp+89h] [-97h]
  _BYTE v11[64]; // [sp+90h] [-90h] BYREF

  if ( args->argc == 2 )
  {
    v1 = args->argv[1];
    v2 = renderSystem->__vftable;
    v3 = common->VideoOverlay(this: common);
    v4 = renderSystem->GetGameWindow(this: renderSystem);
    v2->BeginBinkVideo(this: renderSystem, a2: v4, a3: v1, a4: VIDEO_EXIT, a5: v3);
    if ( bink != nullptr )
    {
      if ( renderSystem->BinkVideoIsPlaying(this: renderSystem) )
      {
        while ( 1 )
        {
          v8[0] = 0.0;
          v8[1] = 1.0;
          v9 = 0;
          v8[2] = 1.0;
          v8[3] = joy_pitchSpeed.valueFloat;
          v8[4] = joy_yawSpeed.valueFloat;
          v10 = in_invertLook.valueInteger != 0;
          v8[5] = m_sensitivity.valueFloat;
          usercmdGen->GetUsercmd(
            this: (idUsercmdGen *)v11,
            result: (usercmd_t *)usercmdGen,
            a3: 0,
            a4: (const inputSettings_t *)v8,
            a5: false,
            a6: 0);
          sys->GenerateEvents(this: sys);
          sys->GetEvent(this: &v5, result: (sysEvent_t *)sys);
          if ( v5.__vftable == (idSysLocal_vtbl *)1 && v7 != 0 && (v6 == 1 || v6 == 257) )
            break;
          if ( !renderSystem->BinkVideoIsPlaying(this: renderSystem) )
            goto LABEL_13;
        }
        sys->ClearEvents(this: sys);
      }
LABEL_13:
      renderSystem->FreeBinkVideo(this: renderSystem);
    }
    else
    {
      idLib::Printf(fmt: "BeginBinkVideo() failed\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: bink <filename>\n");
  }
}


// ========================================================================
// ?ReadHeader@idBinkIOWrapper@@CAIPAUBINKIO@@HPAXI@Z
// EA  : 0x8294A0E0
// RVA : 0x0094A0E0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

unsigned int __fastcall idBinkIOWrapper::ReadHeader(BINKIO *Bnkio, int offset, __int64 size)
{
  __int64 v4; // r29
  unsigned int v5; // r27
  unsigned int CachedData; // r30
  __int64 v7; // r11
  void (__fastcall *flipendian_callback)(void *, unsigned int); // r11
  int v10; // [sp+8h] [-88h]
  pfcRequest_t v11; // [sp+Ch] [-84h]

  HIDWORD(v4) = HIDWORD(size);
  v5 = size;
  if ( offset == -1 )
    v4 = *(_QWORD *)&Bnkio->iodata[8];
  else
    LODWORD(v4) = offset;
  if ( bink_useSFCForNetwork.valueInteger != 0 )
  {
    HIDWORD(size) = v4;
    CachedData = idStreamFileCache::ReadCachedData(
                   this: streamFileCache,
                   cacheFile: *(idFile **)&Bnkio->iodata[16],
                   ofs: size,
                   length: (unsigned __int8 *)HIDWORD(v4),
                   dest: 1,
                   blockingRead: (idStreamControlThread_vtbl *)0x70000000,
                   priority: nullptr,
                   persistence: v10,
                   pfc: v11);
  }
  else
  {
    CachedData = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&Bnkio->iodata[16] + 20))(
                   a1: *(_DWORD *)&Bnkio->iodata[16],
                   a2: v4,
                   a3: HIDWORD(v4));
  }
  flipendian_callback = Bnkio->flipendian_callback;
  if ( flipendian_callback != nullptr )
    flipendian_callback(a1: (void *)HIDWORD(v4), a2: v5);
  LODWORD(v7) = CachedData + v4;
  *(_QWORD *)&Bnkio->iodata[8] = v7;
  return CachedData;
}


// ========================================================================
// ?ReadFrame@idBinkIOWrapper@@CAIPAUBINKIO@@IHPAXI@Z
// EA  : 0x8294A1A8
// RVA : 0x0094A1A8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

unsigned int __fastcall idBinkIOWrapper::ReadFrame(
        BINKIO *Bnkio,
        unsigned int Framenum,
        int origofs,
        unsigned __int8 *dest,
        unsigned int size)
{
  volatile unsigned __int8 *iodata; // r31
  __int64 v9; // r28
  __int64 v10; // r6
  unsigned int CachedData; // r29
  __int64 v12; // r11
  __int64 v13; // r6
  void (__fastcall *flipendian_callback)(void *, unsigned int); // r11
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+8h] [-98h]
  pfcRequest_t v18; // [sp+Ch] [-94h]
  pfcRequest_t v19; // [sp+Ch] [-94h]

  iodata = Bnkio->iodata;
  if ( origofs == -1 )
    v9 = *(_QWORD *)&Bnkio->iodata[8];
  else
    LODWORD(v9) = origofs;
  LODWORD(v10) = size;
  if ( bink_useSFCForNetwork.valueInteger != 0 )
  {
    HIDWORD(v10) = v9;
    CachedData = idStreamFileCache::ReadCachedData(
                   this: streamFileCache,
                   cacheFile: *(idFile **)&Bnkio->iodata[16],
                   ofs: v10,
                   length: dest,
                   dest: 1,
                   blockingRead: (idStreamControlThread_vtbl *)0x7FFFFFFF,
                   priority: (idStreamControlThread_vtbl *)1,
                   persistence: v16,
                   pfc: v18);
    HIDWORD(v12) = 0x20000;
    LODWORD(v12) = *((_DWORD *)iodata + 1) - (CachedData + v9);
    if ( (unsigned int)v12 < 0x20000 )
    {
      if ( (_DWORD)v12 == 0 )
        goto LABEL_10;
    }
    else
    {
      LODWORD(v12) = 0x20000;
    }
    LODWORD(v13) = v12;
    HIDWORD(v13) = CachedData + v9;
    idStreamFileCache::ReadCachedData(
      this: streamFileCache,
      cacheFile: *((idFile **)iodata + 4),
      ofs: v13,
      length: nullptr,
      dest: 0,
      blockingRead: (idStreamControlThread_vtbl *)0x7FFFFFF0,
      priority: (idStreamControlThread_vtbl *)1,
      persistence: v17,
      pfc: v19);
  }
  else
  {
    CachedData = (*(int (__fastcall **)(_DWORD, _DWORD, unsigned __int8 *, unsigned int))(**(_DWORD **)&Bnkio->iodata[16]
                                                                                        + 20))(
                   a1: *(_DWORD *)&Bnkio->iodata[16],
                   a2: v9,
                   a3: dest,
                   a4: size);
  }
LABEL_10:
  flipendian_callback = Bnkio->flipendian_callback;
  if ( flipendian_callback != nullptr )
    flipendian_callback(a1: dest, a2: size);
  LODWORD(v12) = CachedData + v9;
  *((_QWORD *)iodata + 1) = v12;
  return CachedData;
}


// ========================================================================
// ?Close@idBinkIOWrapper@@CAXPAUBINKIO@@@Z
// EA  : 0x8294A2C8
// RVA : 0x0094A2C8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBinkIOWrapper::Close(BINKIO *Bnkio)
{
  __int64 v2; // r5 OVERLAPPED
  unsigned int v3; // r11
  unsigned int v4; // r6
  void (__fastcall ***v5)(_DWORD, int); // r3
  int v6; // [sp+8h] [-68h]
  pfcRequest_t v7; // [sp+Ch] [-64h]

  if ( bink_useSFCForNetwork.valueInteger != 0 )
  {
    v2 = *(_QWORD *)&Bnkio->iodata[8];
    v3 = *(_DWORD *)&Bnkio->iodata[4] - v2;
    if ( v3 < 0x20000 )
    {
      if ( v3 == 0 )
        goto LABEL_6;
    }
    else
    {
      v3 = 0x20000;
    }
    v4 = v3;
    idStreamFileCache::ReadCachedData(
      this: streamFileCache,
      cacheFile: *(idFile **)&Bnkio->iodata[16],
      ofs: *(__int64 *)((char *)&v2 - 4),
      length: nullptr,
      dest: 1,
      blockingRead: (idStreamControlThread_vtbl *)0x70000000,
      priority: (idStreamControlThread_vtbl *)1,
      persistence: v6,
      pfc: v7);
  }
LABEL_6:
  v5 = *(void (__fastcall ****)(_DWORD, int))&Bnkio->iodata[16];
  if ( v5 != nullptr )
    (**v5)(a1: v5, a2: 1);
}


// ========================================================================
// ?InitBink@idRenderSystemLocal@@AAAXXZ
// EA  : 0x8294A378
// RVA : 0x0094A378
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::InitBink(idRenderSystemLocal *this)
{
  __int64 v1; // r6
  __int64 v2; // r10
  __int64 v3; // r8
  int i; // r29
  va *v5; // r3
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  int v14; // [sp+8h] [-1108h]
  int v15; // [sp+8h] [-1108h]
  int v16; // [sp+8h] [-1108h]
  int v17; // [sp+Ch] [-1104h]
  int v18; // [sp+Ch] [-1104h]
  int v19; // [sp+Ch] [-1104h]
  int v20; // [sp+10h] [-1100h]
  int v21; // [sp+10h] [-1100h]
  int v22; // [sp+10h] [-1100h]
  int v23; // [sp+14h] [-10FCh]
  int v24; // [sp+14h] [-10FCh]
  int v25; // [sp+14h] [-10FCh]
  int v26; // [sp+18h] [-10F8h]
  int v27; // [sp+18h] [-10F8h]
  int v28; // [sp+18h] [-10F8h]
  int v29; // [sp+1Ch] [-10F4h]
  int v30; // [sp+1Ch] [-10F4h]
  int v31; // [sp+1Ch] [-10F4h]
  idImageOpts v32; // [sp+50h] [-10C0h] BYREF
  va v33; // [sp+A0h] [-1070h] BYREF

  if ( bink_dontfree.valueInteger != 0 )
  {
    HIDWORD(v3) = &unk_821F0000;
    LODWORD(v1) = 0x82000000;
    HIDWORD(v2) = "Mips";
    LODWORD(v3) = "Mips";
    for ( i = 0; i < 2; ++i )
    {
      v32.border.x = 0.0;
      LODWORD(v2) = bfb.YABufferHeight;
      v32.border.y = 0.0;
      v32.border.z = 0.0;
      v32.colorFormat = CFM_DEFAULT;
      v32.border.w = 0.0;
      v32.filter = TF_DEFAULT;
      v32.lodBias = 0.0;
      v32.cubeFilter = false;
      v32.lodMinClamp = 0.0;
      v32.depth = 0;
      v32.lodMaxClamp = 13.0;
      v32.textureType = TT_2D;
      v32.aniso = 0.0;
      v32.packedTail = true;
      v32.forceBias = false;
      v32.depthCompareMode = false;
      HIDWORD(v1) = i;
      v32.overlayMemory = false;
      v32.startPurged = true;
      v32.format = FMT_LUM8;
      v32.repeat = TR_CLAMP;
      v32.width = bfb.YABufferWidth;
      v32.height = bfb.YABufferHeight;
      v32.numLevels = 1;
      v32.linear = true;
      v32.readback = true;
      v5 = va::va(
             this: &v33,
             fmt: "_binkY%i",
             a3: v1,
             a4: v3,
             a5: v2,
             a6: v14,
             a7: v17,
             a8: v20,
             a9: v23,
             a10: v26,
             a11: v29);
      idImageManager::ScratchImage(this: globalImages, _name: v5->buffer, imgOpts: &v32);
      HIDWORD(v6) = i;
      v9 = va::va(
             this: &v33,
             fmt: "_binkCr%i",
             a3: v6,
             a4: v8,
             a5: v7,
             a6: v15,
             a7: v18,
             a8: v21,
             a9: v24,
             a10: v27,
             a11: v30);
      idImageManager::ScratchImage(this: globalImages, _name: v9->buffer, imgOpts: &v32);
      HIDWORD(v10) = i;
      v13 = va::va(
              this: &v33,
              fmt: "_binkCb%i",
              a3: v10,
              a4: v12,
              a5: v11,
              a6: v16,
              a7: v19,
              a8: v22,
              a9: v25,
              a10: v28,
              a11: v31);
      idImageManager::ScratchImage(this: globalImages, _name: v13->buffer, imgOpts: &v32);
    }
  }
}


// ========================================================================
// ?FreeBinkVideo@idRenderSystemLocal@@UAAXXZ
// EA  : 0x8294A4E8
// RVA : 0x0094A4E8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::FreeBinkVideo(idRenderSystemLocal *this)
{
  idRenderVideoOverlay *videoOverlay; // r3
  int i; // r30
  idImage *v4; // r3
  idImage *v5; // r3
  idImage *v6; // r3

  this->renderThread->renderMode = RENDER_MODE_MANUAL;
  this->SyncRenderThread(this, a2: false);
  Sys_MutexLock(handle: &binkMutex.handle, blocking: true);
  videoOverlay = this->videoOverlay;
  if ( videoOverlay != nullptr )
    videoOverlay->End(this: videoOverlay);
  this->videoOverlay = nullptr;
  if ( bink != nullptr )
  {
    BinkClose();
    bink = nullptr;
  }
  idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkY.r, image: globalImages->defaultImage);
  idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkCr.r, image: globalImages->defaultImage);
  idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkCb.r, image: globalImages->defaultImage);
  if ( bink_dontfree.valueInteger == 0 )
  {
    for ( i = 0; i < 2; ++i )
    {
      v4 = binkY[i];
      if ( v4 != nullptr )
      {
        ((void (__fastcall *)(idImage *, int))v4->dtr_idResource)(a1: v4, a2: 1);
        binkY[i] = nullptr;
      }
      v5 = binkCr[i];
      if ( v5 != nullptr )
      {
        ((void (__fastcall *)(idImage *, int))v5->dtr_idResource)(a1: v5, a2: 1);
        binkCr[i] = nullptr;
      }
      v6 = binkCb[i];
      if ( v6 != nullptr )
      {
        ((void (__fastcall *)(idImage *, int))v6->dtr_idResource)(a1: v6, a2: 1);
        binkCb[i] = nullptr;
      }
    }
    binkSetupOnce = false;
  }
  XMPRestoreBackgroundMusic();
  Sys_MutexUnlock(handle: &binkMutex.handle);
}


// ========================================================================
// __unwind$231119_0
// EA  : 0x8294A684
// RVA : 0x0094A684
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _unwind_231119_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?UpdateBinkTextures@idRenderSystemLocal@@QAAXXZ
// EA  : 0x8294A6B0
// RVA : 0x0094A6B0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::UpdateBinkTextures(idRenderSystemLocal *this)
{
  int v1; // r23
  int v2; // r24
  unsigned int v3; // r28
  char **v4; // r29
  int v5; // r30
  int v6; // [sp+8h] [-A8h]
  int v7; // [sp+8h] [-A8h]
  int v8; // [sp+8h] [-A8h]

  if ( bink != nullptr )
  {
    if ( byte_837A3EAC == 0 )
      idStreamFileCache::ServiceBink(this: streamFileCache, source: (fsDevice_t)dword_837A3FDC);
    idStreamFileCache::SignalWork(this: streamFileCache);
    BinkGetSummary(a1: bink, a2: &unk_837A3F60);
    BinkGetRealtime(a1: bink, a2: &binkRealTime, a3: 0);
    v1 = Sys_Milliseconds();
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_BINK_FRAME);
    skipped = BinkDoFrame(a1: bink);
    idRenderLog::CloseMainBlock(this: &renderLog);
    if ( skipped != 0 )
      idLib::Printf(fmt: "BindDoFrame() skipped on %i\n", bink->FrameNum);
    v2 = Sys_Milliseconds();
    v3 = bink->FrameNum & 1;
    if ( !binkDirectlyIntoTextures )
    {
      v4 = (char **)((char *)bink->FrameBuffers + 48 * v3);
      idDeclRenderProg::BindTexture(image: binkY[v3], texUnit: 0);
      idImage::SubImageUpload(
        this: binkY[v3],
        mipLevel: 0,
        destX: 0,
        destY: 0,
        destZ: D3DCUBEMAP_FACE_POSITIVE_X,
        width: bink->FrameBuffers->YABufferWidth,
        height: bink->FrameBuffers->YABufferHeight,
        pic: v4[7],
        pixelPitch: v6);
      idDeclRenderProg::BindTexture(image: binkCr[v3], texUnit: 0);
      idImage::SubImageUpload(
        this: binkCr[v3],
        mipLevel: 0,
        destX: 0,
        destY: 0,
        destZ: D3DCUBEMAP_FACE_POSITIVE_X,
        width: bink->FrameBuffers->cRcBBufferWidth,
        height: bink->FrameBuffers->cRcBBufferHeight,
        pic: v4[10],
        pixelPitch: v7);
      idDeclRenderProg::BindTexture(image: binkCb[v3], texUnit: 0);
      idImage::SubImageUpload(
        this: binkCb[v3],
        mipLevel: 0,
        destX: 0,
        destY: 0,
        destZ: D3DCUBEMAP_FACE_POSITIVE_X,
        width: bink->FrameBuffers->cRcBBufferWidth,
        height: bink->FrameBuffers->cRcBBufferHeight,
        pic: v4[13],
        pixelPitch: v8);
    }
    v5 = Sys_Milliseconds();
    idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkY.r, image: binkY[v3]);
    idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkCr.r, image: binkCr[v3]);
    idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpBinkCb.r, image: binkCb[v3]);
    if ( bink_debug.valueInteger != 0 )
      idLib::Printf(fmt: "bink frame %i: %i ms doFrame, %i ms upload\n", bink->FrameNum, v2 - v1, v5 - v2);
    idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_BINK_NEXT_FRAME);
    BinkNextFrame(a1: bink);
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
}


// ========================================================================
// ?FillBinkBuffer@@YAXXZ
// EA  : 0x8294A918
// RVA : 0x0094A918
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall FillBinkBuffer()
{
  int v0; // r29
  int v1; // r3
  int v2; // r3
  unsigned int v3; // r10
  unsigned int v4[28]; // [sp+60h] [-70h] BYREF

  if ( renderSystem->BinkVideoIsPlaying(this: renderSystem) && byte_837A3EAC == 0 )
  {
    Sys_MutexLock(handle: &binkMutex.handle, blocking: true);
    if ( bink != nullptr )
    {
      BinkControlBackgroundIO(a1: bink, a2: -2147483647);
      v0 = bink_percentage_full(bink: bink);
      if ( v0 == 0 )
      {
        v1 = Sys_Milliseconds();
        idLib::Printf(fmt: "Bink underflow at %i\n", v1);
      }
      if ( bink_debug.valueInteger != 0 )
      {
        v2 = Sys_Milliseconds();
        idLib::Printf(fmt: "%6i: FillBinkBuffer: %i\n", v2, v0);
      }
      if ( v0 < 20 )
      {
        BinkControlBackgroundIO(a1: bink, a2: -2147483646);
        while ( renderSystem->BinkVideoIsPlaying(this: renderSystem) )
        {
          BinkGetRealtime(a1: bink, a2: v4, a3: 0);
          if ( v4[11] == 0 )
            break;
          v3 = v4[12];
          __twllei(v4[11], 0);
          if ( 100 * v3 / v4[11] >= 0x5A )
            break;
          mgthread_sleep(ms: 1);
        }
      }
      BinkControlBackgroundIO(a1: bink, a2: -2147483647);
    }
    Sys_MutexUnlock(handle: &binkMutex.handle);
  }
}


// ========================================================================
// __unwind$231198_0
// EA  : 0x8294AA98
// RVA : 0x0094AA98
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _unwind_231198_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 208 + 80));
}


// ========================================================================
// ?Open@idBinkIOWrapper@@SAHPAUBINKIO@@PBDI@Z
// EA  : 0x8294AAC0
// RVA : 0x0094AAC0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

int __fastcall idBinkIOWrapper::Open(BINKIO *Bnkio, const char *name, unsigned int flags)
{
  idFile *v5; // r3
  __int64 v7; // r3
  __int64 v8; // r9

  idLib::Printf(fmt: "idBinkIOWrapper::Open: %s\n", name);
  Bnkio->ReadHeader = (unsigned int (__fastcall *)(BINKIO *, int, void *, unsigned int))idBinkIOWrapper::ReadHeader;
  Bnkio->ReadFrame = (unsigned int (__fastcall *)(BINKIO *, unsigned int, int, void *, unsigned int))idBinkIOWrapper::ReadFrame;
  Bnkio->GetBufferSize = (unsigned int (__fastcall *)(BINKIO *, unsigned int))idLobbyBackend360::StartArbitration;
  Bnkio->Idle = (unsigned int (__fastcall *)(BINKIO *))idLobbyBackend360::StartArbitration;
  Bnkio->SetInfo = idBinkIOWrapper::SetInfo;
  Bnkio->BGControl = (int (__fastcall *)(BINKIO *, unsigned int))idLobbyBackend360::StartArbitration;
  Bnkio->Close = idBinkIOWrapper::Close;
  v5 = fileSystem->OpenFileRead(this: fileSystem, a2: name, a3: 1, a4: 0);
  if ( v5 == nullptr )
    return -1;
  *(_DWORD *)&Bnkio->iodata[16] = v5;
  LODWORD(v7) = v5->Length(this: v5);
  LODWORD(v8) = 0;
  *(_QWORD *)Bnkio->iodata = v7;
  *(_QWORD *)&Bnkio->iodata[8] = v8;
  return 1;
}


// ========================================================================
// ?BeginBinkVideo@idRenderSystemLocal@@UAAXPAXQBDW4videoFlags_t@@PAVidRenderVideoOverlay@@@Z
// EA  : 0x8294ABB8
// RVA : 0x0094ABB8
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::BeginBinkVideo(
        idRenderSystemLocal *this,
        void *hdc,
        const char *fileName,
        videoFlags_t videoFlags_,
        idRenderVideoOverlay *overlay)
{
  const char *v6; // r22
  idRenderVideoOverlay *v8; // r21
  idRenderSystemLocal_vtbl *v9; // r9
  idFile *v10; // r3
  idFile *v11; // r29
  const char *v12; // r3
  int v13; // r3
  idFile_vtbl *v14; // r7
  BOOL v15; // r25
  void *v16; // r4
  int v17; // r28
  int v18; // r5
  int v19; // r4
  int v20; // r29
  int v21; // r26
  int v22; // r29
  long double v23; // fp4
  const char *Error; // r3
  long double v25; // fp2
  long double v26; // fp2
  int v27; // r29
  __int16 v28; // r3
  __int16 v29; // r25
  int v30; // r28
  int v31; // r7
  int v32; // r7
  int v33; // r28
  int i; // r29
  idImage *v35; // r3
  unsigned int cRcBBufferWidth; // r11
  unsigned int cRcBBufferHeight; // r10
  int v38; // r6
  unsigned int *p_BufferPitch; // r10
  unsigned int v40; // r7
  idImage *v41; // r5
  idImage *v42; // r4
  idImage *v43; // r3
  unsigned int YABufferHeight; // r8
  unsigned int YABufferWidth; // r9
  unsigned int v46; // r11
  unsigned int v47; // r7
  unsigned int v48; // r9
  unsigned int v49; // r8
  unsigned int v50; // r11
  __int64 v51; // r8
  idRenderVideoOverlay v52; // r9
  __int64 v53; // [sp+50h] [-280h] BYREF
  int v54; // [sp+58h] [-278h]
  int v55; // [sp+5Ch] [-274h]
  int v56; // [sp+60h] [-270h] BYREF
  int v57; // [sp+64h] [-26Ch]
  int v58; // [sp+68h] [-268h]
  int v59; // [sp+6Ch] [-264h]
  idImageOpts v60; // [sp+70h] [-260h] BYREF
  idStr v61; // [sp+C0h] [-210h] BYREF
  _DWORD v62[8]; // [sp+E0h] [-1F0h] BYREF
  idStr v63; // [sp+100h] [-1D0h] BYREF
  char v64[264]; // [sp+120h] [-1B0h] BYREF

  v6 = fileName;
  v8 = overlay;
  if ( !idLib::headless )
  {
    this->SyncRenderThread(this, a2: false);
    v62[4] = &binkMutex;
    Sys_MutexLock(handle: &binkMutex.handle, blocking: true);
    v9 = this->__vftable;
    videoFlags = videoFlags_;
    v9->FreeBinkVideo(this);
    v10 = fileSystem->OpenFileRead(this: fileSystem, a2: v6, a3: 1, a4: 0);
    v11 = v10;
    if ( v10 != nullptr )
    {
      v12 = v10->GetFullPath(this: v10);
      idStr::idStr(this: &v63, text: v12);
      v13 = v11->GetDevice(this: v11);
      v14 = v11->__vftable;
      dword_837A3FDC = v13;
      v15 = v14->IsOSNative(this: v11);
      byte_837A3EAC = 0;
      if ( !v15 )
        byte_837A3EAC = bink_useSFCForNetwork.valueInteger != 0;
      ((void (__fastcall *)(idFile *, int))v11->dtr_idFile)(a1: v11, a2: 1);
      BinkSetMemory(a1: binkMemAlloc, a2: operator delete);
      v16 = soundSystem->GetIXAudio2(this: soundSystem);
      if ( v16 != nullptr )
        BinkSetSoundSystem(a1: BinkOpenXAudio2, a2: v16);
      v17 = 0;
      if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "english") != 0 )
      {
        if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "french") != 0 )
        {
          if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "german") != 0 )
          {
            if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "italian") != 0 )
            {
              if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "japanese") != 0 )
              {
                if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "polish") != 0 )
                {
                  if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "russian") != 0 )
                  {
                    if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "spanish") != 0 )
                      idLib::Warning(fmt: "Unknown language");
                    else
                      v17 = 7;
                  }
                  else
                  {
                    v17 = 6;
                  }
                }
                else
                {
                  v17 = 5;
                }
              }
              else
              {
                v17 = 4;
              }
            }
            else
            {
              v17 = 3;
            }
          }
          else
          {
            v17 = 2;
          }
        }
        else
        {
          v17 = 1;
        }
      }
      v19 = !binkDirectlyIntoTextures - 1;
      v20 = v19 & 0x400;
      BinkSetIOSize(a1: bink_ioMegs.valueInteger << 20, a2: v19, a3: v18, a4: -binkDirectlyIntoTextures);
      v21 = v17 + 3;
      v62[0] = 0;
      v62[1] = 1;
      v62[3] = v17 + 3;
      v62[2] = 2;
      BinkSetSoundTrack(a1: 4, a2: v62);
      v22 = v20 | 0x1004000;
      fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v63.data, a3: v64, a4: 256, a5: FSPATH_BASE);
      if ( !v15 )
      {
        BinkSetIO(a1: idBinkIOWrapper::Open);
        v22 |= 0x2000000u;
      }
      bink = (BINK *)BinkOpen(a1: v64, a2: v22);
      if ( bink != nullptr )
      {
        *(_QWORD *)&v25 = 0x4000000000000000LL;
        *((double *)&v25 + 1) = (float)(s_volume_dB.valueFloat * (float)0.16666667);
        v26 = pow(x: v25, y: v23);
        LODWORD(v53) = (int)(float)((float)*(double *)&v26 * (float)32768.0);
        if ( (int)v53 >= 0 )
        {
          v27 = 0x8000;
          if ( (int)v53 <= 0x8000 )
            v27 = v53;
        }
        else
        {
          v27 = 0;
        }
        if ( bink->NumTracks == 1 )
        {
          BinkSetVolume();
        }
        else
        {
          v28 = soundSystem->GetSpeakerMask(this: soundSystem);
          v56 = v27;
          v57 = v27;
          v53 = 1;
          v29 = v28;
          BinkSetSpeakerVolumes(a1: bink, a2: 0, a3: &v53, a4: &v56, a5: 2);
          v30 = 2;
          if ( (v29 & 4) != 0 )
          {
            v56 = v27;
            v31 = 1;
            HIDWORD(v53) = 2;
            v30 = 3;
          }
          else
          {
            v53 = 1;
            v31 = 2;
            v56 = 7071 * v27 / 10000;
            v57 = v56;
          }
          BinkSetSpeakerVolumes(a1: bink, a2: v21, a3: &v53, a4: &v56, a5: v31);
          if ( (v29 & 8) != 0 )
          {
            HIDWORD(v53) = v30++;
            v56 = v27;
          }
          else
          {
            v56 = 0;
            HIDWORD(v53) = 0;
          }
          BinkSetSpeakerVolumes(a1: bink, a2: 2, a3: &v53, a4: &v56, a5: 1);
          if ( (v29 & 0x30) != 0 )
          {
            v56 = v27;
            v57 = v27;
            v32 = 2;
            HIDWORD(v53) = v30;
            LODWORD(v53) = v30 + 1;
          }
          else if ( (v29 & 0x600) != 0 )
          {
            if ( (v29 & 0x40) != 0 )
              ++v30;
            if ( (v29 & 0x80) != 0 )
              ++v30;
            if ( (v29 & 0x100) != 0 )
              ++v30;
            v56 = v27;
            v57 = v27;
            v32 = 2;
            HIDWORD(v53) = v30;
            LODWORD(v53) = v30 + 1;
          }
          else
          {
            v53 = 1;
            v54 = 1;
            v55 = 0;
            v56 = 8717 * v27 / 10000;
            v32 = 4;
            v57 = v56;
            v58 = -4899 * v27 / 10000;
            v59 = v58;
          }
          BinkSetSpeakerVolumes(a1: bink, a2: 1, a3: &v53, a4: &v56, a5: v32);
        }
        BinkGetFrameBuffersInfo(a1: bink, a2: &bfb);
        if ( binkSetupOnce )
        {
          HIDWORD(v53) = binkY[0]->opts.width;
          if ( bfb.YABufferWidth != HIDWORD(v53)
            || bfb.YABufferHeight != binkY[0]->opts.height
            || bfb.cRcBBufferWidth != binkCr[0]->opts.width
            || bfb.cRcBBufferHeight != binkCr[0]->opts.height )
          {
            idLib::Warning(
              fmt: "Bink video '%s' with dimensions %dx%d does not match dimensions of previously played video %dx%d, aborting video",
              v6,
              bfb.YABufferWidth,
              bfb.YABufferHeight,
              HIDWORD(v53),
              binkY[0]->opts.height);
            BinkClose(a1: bink);
            idStr::FreeData(this: &v63);
            goto LABEL_82;
          }
        }
        else
        {
          v33 = 0;
          for ( i = 0; i < 2; ++i )
          {
            v60.border.x = 0.0;
            v60.border.y = 0.0;
            v60.colorFormat = CFM_DEFAULT;
            v60.border.z = 0.0;
            v60.filter = TF_DEFAULT;
            v60.border.w = 0.0;
            v60.cubeFilter = false;
            v60.lodBias = 0.0;
            v60.depth = 0;
            v60.lodMinClamp = 0.0;
            v60.textureType = TT_2D;
            v60.lodMaxClamp = 13.0;
            v60.packedTail = true;
            v60.aniso = 0.0;
            v60.forceBias = false;
            v60.depthCompareMode = false;
            v60.overlayMemory = false;
            v60.startPurged = false;
            v60.format = FMT_LUM8;
            v60.repeat = TR_CLAMP;
            v60.width = bfb.YABufferWidth;
            v60.height = bfb.YABufferHeight;
            v60.numLevels = 1;
            v60.linear = true;
            v60.readback = true;
            v61.allocedAndFlag = 20;
            v61.data = v61.baseBuffer;
            v61.len = 0;
            v61.baseBuffer[0] = 0;
            idStr::Format(this: &v61, fmt: "_binkY%i", v33);
            idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
            v35 = idImageManager::ScratchImage(this: globalImages, _name: v61.data, imgOpts: &v60);
            cRcBBufferWidth = bfb.cRcBBufferWidth;
            cRcBBufferHeight = bfb.cRcBBufferHeight;
            binkY[i] = v35;
            v60.width = cRcBBufferWidth;
            v60.height = cRcBBufferHeight;
            idStr::Format(this: &v61, fmt: "_binkCr%i", v33);
            binkCr[i] = idImageManager::ScratchImage(this: globalImages, _name: v61.data, imgOpts: &v60);
            idStr::Format(this: &v61, fmt: "_binkCb%i", v33);
            binkCb[i] = idImageManager::ScratchImage(this: globalImages, _name: v61.data, imgOpts: &v60);
            idMem::PopHeap(this: &mem);
            idStr::FreeData(this: &v61);
            ++v33;
          }
          v6 = fileName;
          v8 = overlay;
        }
        if ( binkDirectlyIntoTextures )
        {
          v38 = 0;
          p_BufferPitch = &bfb.Frames[0].YPlane.BufferPitch;
          do
          {
            v40 = 0;
            v41 = binkY[v38];
            v42 = binkCr[v38];
            v43 = binkCb[v38];
            *(p_BufferPitch - 1) = (unsigned int)v41->lockRect[0].pBits;
            *p_BufferPitch = v41->lockRect[0].Pitch;
            p_BufferPitch[2] = (unsigned int)v42->lockRect[0].pBits;
            p_BufferPitch[3] = v42->lockRect[0].Pitch;
            p_BufferPitch[5] = (unsigned int)v43->lockRect[0].pBits;
            p_BufferPitch[6] = v43->lockRect[0].Pitch;
            YABufferHeight = bfb.YABufferHeight;
            if ( bfb.YABufferHeight != 0 )
            {
              YABufferWidth = bfb.YABufferWidth;
              do
              {
                v46 = 0;
                if ( YABufferWidth != 0 )
                {
                  do
                  {
                    *(_BYTE *)(*p_BufferPitch * v40 + *(p_BufferPitch - 1) + v46) = v46;
                    ++v46;
                    YABufferWidth = bfb.YABufferWidth;
                  }
                  while ( v46 < bfb.YABufferWidth );
                  YABufferHeight = bfb.YABufferHeight;
                }
                ++v40;
              }
              while ( v40 < YABufferHeight );
            }
            v47 = bfb.cRcBBufferHeight;
            v48 = 0;
            if ( bfb.cRcBBufferHeight != 0 )
            {
              v49 = bfb.cRcBBufferWidth;
              do
              {
                v50 = 0;
                if ( v49 != 0 )
                {
                  do
                  {
                    *(_BYTE *)(p_BufferPitch[3] * v48 + p_BufferPitch[2] + v50) = v50;
                    *(_BYTE *)(p_BufferPitch[6] * v48 + p_BufferPitch[5] + v50) = v50;
                    ++v50;
                    v49 = bfb.cRcBBufferWidth;
                  }
                  while ( v50 < bfb.cRcBBufferWidth );
                  v47 = bfb.cRcBBufferHeight;
                }
                ++v48;
              }
              while ( v48 < v47 );
            }
            p_BufferPitch += 12;
            ++v38;
          }
          while ( (int)p_BufferPitch < (int)&binkRealTime.FrameRateDiv );
          BinkRegisterFrameBuffers(a1: bink, a2: &bfb);
        }
        if ( byte_837A3EAC == 0 )
          BinkControlBackgroundIO(a1: bink, a2: -2147483647);
        BinkGetSummary(a1: bink, a2: &unk_837A3F60);
        BinkGetRealtime(a1: bink, a2: &binkRealTime, a3: 0);
        this->videoOverlay = v8;
        if ( v8 != nullptr )
        {
          LODWORD(v51) = dword_837A3F68;
          v52.__vftable = v8->__vftable;
          v53 = v51;
          v52.Start(this: v8, a2: v6, a3: (float)((float)v51 * (float)0.001));
        }
        this->renderThread->renderModeBeforeSync = RENDER_MODE_BINK;
        idRenderSystemLocal::RestartRenderThread(this, hdc);
        XMPOverrideBackgroundMusic();
        binkSetupOnce = true;
        idStr::FreeData(this: &v63);
        goto LABEL_82;
      }
      Error = (const char *)BinkGetError();
      idLib::Warning(fmt: "BinkOpen( %s ) failed: %s", v64, Error);
      idStr::FreeData(this: &v63);
    }
    else
    {
      idLib::Warning(fmt: "couldn't find bink file %s", v6);
    }
LABEL_82:
    Sys_MutexUnlock(handle: &binkMutex.handle);
  }
}


// ========================================================================
// __unwind$231288
// EA  : 0x8294B58C
// RVA : 0x0094B58C
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _unwind_231288()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 720 + 240));
}


// ========================================================================
// __unwind$231289
// EA  : 0x8294B5B4
// RVA : 0x0094B5B4
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _unwind_231289()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 256));
}


// ========================================================================
// __unwind$231290
// EA  : 0x8294B5DC
// RVA : 0x0094B5DC
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _unwind_231290()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 192));
}


// ========================================================================
// `dynamic initializer for 'bink_dontfree''
// EA  : 0x8335D310
// RVA : 0x0135D310
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bink_dontfree__()
{
  idCVar::idCVar(
    this: &bink_dontfree,
    name: "bink_dontfree",
    value: "1",
    flags: 1,
    description: "keep bink textures around since we need to be able to play videos whenever",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bink_dontfree__);
}


// ========================================================================
// `dynamic initializer for 'bink_debug''
// EA  : 0x8335D368
// RVA : 0x0135D368
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bink_debug__()
{
  idCVar::idCVar(
    this: &bink_debug,
    name: "bink_debug",
    value: "0",
    flags: 1,
    description: "dump information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bink_debug__);
}


// ========================================================================
// `dynamic initializer for 'bink_ioMegs''
// EA  : 0x8335D3C0
// RVA : 0x0135D3C0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bink_ioMegs__()
{
  idCVar::idCVar(
    this: &bink_ioMegs,
    name: "bink_ioMegs",
    value: "4",
    flags: 2,
    description: "larger buffers for less seeks during load",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bink_ioMegs__);
}


// ========================================================================
// `dynamic initializer for 'mtrBink''_0
// EA  : 0x8335D418
// RVA : 0x0135D418
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _dynamic_initializer_for__mtrBink___0()
{
  mtrBink_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrBink_0;
}


// ========================================================================
// `dynamic initializer for 'rpBinkY''
// EA  : 0x8335D438
// RVA : 0x0135D438
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _dynamic_initializer_for__rpBinkY__()
{
  rpBinkY.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpBinkY;
}


// ========================================================================
// `dynamic initializer for 'rpBinkCr''
// EA  : 0x8335D458
// RVA : 0x0135D458
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _dynamic_initializer_for__rpBinkCr__()
{
  rpBinkCr.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpBinkCr;
}


// ========================================================================
// `dynamic initializer for 'rpBinkCb''
// EA  : 0x8335D478
// RVA : 0x0135D478
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void _dynamic_initializer_for__rpBinkCb__()
{
  rpBinkCb.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpBinkCb;
}


// ========================================================================
// `dynamic initializer for 'binkMutex''
// EA  : 0x8335D498
// RVA : 0x0135D498
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__binkMutex__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&binkMutex);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__binkMutex__);
}


// ========================================================================
// `dynamic initializer for 'bink_v''
// EA  : 0x8335D4D0
// RVA : 0x0135D4D0
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__bink_v__()
{
  return idCommandLink::idCommandLink(
           this: &bink_v,
           cmdName: "bink",
           function: bink_f,
           description: "Play a bink video",
           argCompletion: idCmdSystem::ArgCompletion_FileName);
}


// ========================================================================
// `dynamic initializer for 'bink_useSFCForNetwork''
// EA  : 0x8335D500
// RVA : 0x0135D500
// PDB : w:\tech5\engine\renderer\rendersystem_bink.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bink_useSFCForNetwork__()
{
  idCVar::idCVar(
    this: &bink_useSFCForNetwork,
    name: "bink_useSFCForNetwork",
    value: "1",
    flags: 1,
    description: "use the stream file cache when reading videos over network (to reduce the number of reads)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bink_useSFCForNetwork__);
}

