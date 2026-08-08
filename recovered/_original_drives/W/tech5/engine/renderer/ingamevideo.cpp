
// ========================================================================
// ?Shutdown@idInGameVideoManagerLocal@@UAAXXZ
// EA  : 0x828D1410
// RVA : 0x008D1410
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::Shutdown(idInGameVideoManagerLocal *this)
{
  if ( this->parallelJobList != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    this->parallelJobList = nullptr;
  }
}


// ========================================================================
// ?BindVideo@idInGameVideoManagerLocal@@UAAXHPBVidInGameVideoFile@@@Z
// EA  : 0x828D1468
// RVA : 0x008D1468
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::BindVideo(
        idInGameVideoManagerLocal *this,
        unsigned int index,
        const idInGameVideoFile *file)
{
  char *v3; // r11

  if ( index > 5 )
  {
    idLib::Warning(fmt: "Video index %d out of range.  Valid index 0-%d", index, 5);
  }
  else
  {
    v3 = (char *)this + 20 * index;
    if ( *((const idInGameVideoFile **)v3 + 6) != file )
    {
      *((_DWORD *)v3 + 6) = file;
      *((_DWORD *)v3 + 5) = -1;
    }
  }
}


// ========================================================================
// ?SetLooping@idInGameVideoManagerLocal@@UAAXH_N@Z
// EA  : 0x828D14B8
// RVA : 0x008D14B8
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::SetLooping(idInGameVideoManagerLocal *this, unsigned int index, bool loop)
{
  if ( index > 5 )
    idLib::Warning(fmt: "Video index %d out of range.  Valid index 0-%d", index, 5);
  else
    this->videos[index].looping = loop;
}


// ========================================================================
// ?UnbindAll@idInGameVideoManagerLocal@@UAAXXZ
// EA  : 0x828D14F0
// RVA : 0x008D14F0
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::UnbindAll(idInGameVideoManagerLocal *this)
{
  idParallelJobList *parallelJobList; // r3

  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
    idParallelJobList::Wait(this: parallelJobList);
  this->videos[0].timeOffset = 0;
  this->videos[1].timeOffset = 0;
  this->videos[0].pausedTime = -1;
  this->videos[0].looping = true;
  this->videos[0].lastFrame = -1;
  this->videos[0].file = nullptr;
  this->videos[1].pausedTime = -1;
  this->videos[1].looping = true;
  this->videos[1].lastFrame = -1;
  this->videos[1].file = nullptr;
  this->videos[2].timeOffset = 0;
  this->videos[2].pausedTime = -1;
  this->videos[2].looping = true;
  this->videos[2].lastFrame = -1;
  this->videos[2].file = nullptr;
  this->videos[3].timeOffset = 0;
  this->videos[3].pausedTime = -1;
  this->videos[3].looping = true;
  this->videos[3].lastFrame = -1;
  this->videos[3].file = nullptr;
  this->videos[4].timeOffset = 0;
  this->videos[4].pausedTime = -1;
  this->videos[4].looping = true;
  this->videos[4].lastFrame = -1;
  this->videos[4].file = nullptr;
  this->videos[5].timeOffset = 0;
  this->videos[5].pausedTime = -1;
  this->videos[5].looping = true;
  this->videos[5].lastFrame = -1;
  this->videos[5].file = nullptr;
}


// ========================================================================
// ?UnbindVideo@idInGameVideoManagerLocal@@QAAXPBVidInGameVideoFile@@@Z
// EA  : 0x828D15B0
// RVA : 0x008D15B0
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::UnbindVideo(idInGameVideoManagerLocal *this, const idInGameVideoFile *file)
{
  idParallelJobList *parallelJobList; // r3
  const idInGameVideoFile *v5; // r9
  int v6; // r7
  const idInGameVideoFile *v7; // r9
  const idInGameVideoFile *v8; // r9
  const idInGameVideoFile *v9; // r9
  const idInGameVideoFile *v10; // r9
  const idInGameVideoFile *v11; // r9
  idParallelJobList *v12; // r3

  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
    idParallelJobList::Wait(this: parallelJobList);
  v5 = this->videos[0].file;
  v6 = 0;
  if ( v5 != nullptr && v5 == file )
  {
    this->videos[0].timeOffset = 0;
    this->videos[0].pausedTime = -1;
    this->videos[0].looping = true;
    this->videos[0].lastFrame = -1;
    this->videos[0].file = nullptr;
  }
  else
  {
    v6 = 1;
  }
  v7 = this->videos[1].file;
  if ( v7 != nullptr && v7 == file )
  {
    this->videos[1].timeOffset = 0;
    this->videos[1].pausedTime = -1;
    this->videos[1].looping = true;
    this->videos[1].lastFrame = -1;
    this->videos[1].file = nullptr;
  }
  else
  {
    ++v6;
  }
  v8 = this->videos[2].file;
  if ( v8 != nullptr && v8 == file )
  {
    this->videos[2].timeOffset = 0;
    this->videos[2].pausedTime = -1;
    this->videos[2].looping = true;
    this->videos[2].lastFrame = -1;
    this->videos[2].file = nullptr;
  }
  else
  {
    ++v6;
  }
  v9 = this->videos[3].file;
  if ( v9 != nullptr && v9 == file )
  {
    this->videos[3].timeOffset = 0;
    this->videos[3].pausedTime = -1;
    this->videos[3].looping = true;
    this->videos[3].lastFrame = -1;
    this->videos[3].file = nullptr;
  }
  else
  {
    ++v6;
  }
  v10 = this->videos[4].file;
  if ( v10 != nullptr && v10 == file )
  {
    this->videos[4].timeOffset = 0;
    this->videos[4].pausedTime = -1;
    this->videos[4].looping = true;
    this->videos[4].lastFrame = -1;
    this->videos[4].file = nullptr;
  }
  else
  {
    ++v6;
  }
  v11 = this->videos[5].file;
  if ( v11 != nullptr && v11 == file )
  {
    this->videos[5].timeOffset = 0;
    this->videos[5].pausedTime = -1;
    this->videos[5].looping = true;
    this->videos[5].lastFrame = -1;
    this->videos[5].file = nullptr;
  }
  else
  {
    ++v6;
  }
  if ( v6 > 0 )
  {
    v12 = this->parallelJobList;
    if ( v12 != nullptr )
      idParallelJobList::Submit(this: v12, waitForJobList: nullptr, parallelism: -1);
  }
}


// ========================================================================
// ?GetSerializeType@idAnimator_TorsoTracker@@UAA?AW4serializeType_t@@XZ
// EA  : 0x828D1748
// RVA : 0x008D1748
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

unsigned int __fastcall idAnimator_TorsoTracker::GetSerializeType()
{
  return 4;
}


// ========================================================================
// ?Free@idInGameVideoFile@@QAAXXZ
// EA  : 0x828D1750
// RVA : 0x008D1750
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoFile::Free(idInGameVideoFile *this)
{
  unsigned __int8 *buffer; // r4

  buffer = this->buffer;
  if ( buffer != nullptr )
  {
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    this->buffer = nullptr;
  }
}


// ========================================================================
// ??0idInGameVideoManagerLocal@@QAA@XZ
// EA  : 0x828D1818
// RVA : 0x008D1818
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

idInGameVideoManagerLocal *__fastcall idInGameVideoManagerLocal::idInGameVideoManagerLocal(
        idInGameVideoManagerLocal *this)
{
  this->parallelJobList = nullptr;
  this->__vftable = (idInGameVideoManagerLocal_vtbl *)&idInGameVideoManagerLocal::`vftable';
  this->videos[0].timeOffset = 0;
  this->videos[0].pausedTime = -1;
  this->videos[0].looping = true;
  this->videos[0].lastFrame = -1;
  this->videos[0].file = nullptr;
  this->parms[0].dctQualityLuma = 0;
  this->parms[0].dctQualityChroma = 0;
  this->parms[0].dctBuffer = nullptr;
  this->parms[0].dctBufferSize = 0;
  this->parms[0].image = nullptr;
  this->parms[0].dxtBuffer = nullptr;
  this->parms[0].targetBytePitch = 0;
  this->parms[0].needSubImageUpload = false;
  this->videos[1].timeOffset = 0;
  this->videos[1].pausedTime = -1;
  this->videos[1].looping = true;
  this->videos[1].lastFrame = -1;
  this->videos[1].file = nullptr;
  this->parms[1].dctQualityLuma = 0;
  this->parms[1].dctQualityChroma = 0;
  this->parms[1].dctBuffer = nullptr;
  this->parms[1].dctBufferSize = 0;
  this->parms[1].image = nullptr;
  this->parms[1].dxtBuffer = nullptr;
  this->parms[1].targetBytePitch = 0;
  this->parms[1].needSubImageUpload = false;
  this->videos[2].timeOffset = 0;
  this->videos[2].pausedTime = -1;
  this->videos[2].looping = true;
  this->videos[2].lastFrame = -1;
  this->videos[2].file = nullptr;
  this->parms[2].dctQualityLuma = 0;
  this->parms[2].dctQualityChroma = 0;
  this->parms[2].dctBuffer = nullptr;
  this->parms[2].dctBufferSize = 0;
  this->parms[2].image = nullptr;
  this->parms[2].dxtBuffer = nullptr;
  this->parms[2].targetBytePitch = 0;
  this->parms[2].needSubImageUpload = false;
  this->videos[3].timeOffset = 0;
  this->videos[3].pausedTime = -1;
  this->videos[3].looping = true;
  this->videos[3].lastFrame = -1;
  this->videos[3].file = nullptr;
  this->parms[3].dctQualityLuma = 0;
  this->parms[3].dctQualityChroma = 0;
  this->parms[3].dctBuffer = nullptr;
  this->parms[3].dctBufferSize = 0;
  this->parms[3].image = nullptr;
  this->parms[3].dxtBuffer = nullptr;
  this->parms[3].targetBytePitch = 0;
  this->parms[3].needSubImageUpload = false;
  this->videos[4].timeOffset = 0;
  this->videos[4].pausedTime = -1;
  this->videos[4].looping = true;
  this->videos[4].lastFrame = -1;
  this->videos[4].file = nullptr;
  this->parms[4].dctQualityLuma = 0;
  this->parms[4].dctQualityChroma = 0;
  this->parms[4].dctBuffer = nullptr;
  this->parms[4].dctBufferSize = 0;
  this->parms[4].image = nullptr;
  this->parms[4].dxtBuffer = nullptr;
  this->parms[4].targetBytePitch = 0;
  this->parms[4].needSubImageUpload = false;
  this->videos[5].timeOffset = 0;
  this->videos[5].pausedTime = -1;
  this->videos[5].looping = true;
  this->videos[5].lastFrame = -1;
  this->videos[5].file = nullptr;
  this->parms[5].dctQualityLuma = 0;
  this->parms[5].dctQualityChroma = 0;
  this->parms[5].dctBuffer = nullptr;
  this->parms[5].dctBufferSize = 0;
  this->parms[5].image = nullptr;
  this->parms[5].dxtBuffer = nullptr;
  this->parms[5].targetBytePitch = 0;
  this->parms[5].needSubImageUpload = false;
  return this;
}


// ========================================================================
// ?Init@idInGameVideoManagerLocal@@UAAXXZ
// EA  : 0x828D1970
// RVA : 0x008D1970
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::Init(idInGameVideoManagerLocal *this)
{
  __int64 v2; // r6
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r30
  const idInGameVideoFile **p_file; // r29
  va *v7; // r3
  idImage *v8; // r3
  int v9; // [sp+8h] [-10C8h]
  int v10; // [sp+Ch] [-10C4h]
  int v11; // [sp+10h] [-10C0h]
  int v12; // [sp+14h] [-10BCh]
  int v13; // [sp+18h] [-10B8h]
  int v14; // [sp+1Ch] [-10B4h]
  idImageOpts v15; // [sp+50h] [-1080h] BYREF
  va v16; // [sp+A0h] [-1030h] BYREF

  this->parallelJobList = parallelJobManager->AllocJobList(
                            this: parallelJobManager,
                            a2: 4,
                            a3: 2,
                            a4: 6,
                            a5: 0,
                            a6: &idColor::colorCyan);
  HIDWORD(v3) = 0x82000000;
  LODWORD(v4) = &unk_821F0000;
  v15.width = 128;
  v15.height = 128;
  LODWORD(v3) = 1;
  HIDWORD(v4) = 11;
  memset(&v15.colorFormat, 0, 12);
  v15.border.x = 0.0;
  v15.cubeFilter = false;
  v15.border.y = 0.0;
  v15.depth = 0;
  v15.border.z = 0.0;
  v15.numLevels = 0;
  v15.border.w = 0.0;
  v15.packedTail = true;
  v15.lodBias = 0.0;
  v5 = 0;
  v15.lodMinClamp = 0.0;
  v15.readback = false;
  v15.lodMaxClamp = 13.0;
  p_file = &this->videos[5].file;
  v15.aniso = 0.0;
  v15.forceBias = false;
  v15.depthCompareMode = false;
  v15.overlayMemory = false;
  v15.startPurged = false;
  v15.textureType = TT_2D;
  v15.format = FMT_DXT5;
  v15.linear = true;
  do
  {
    HIDWORD(v2) = v5;
    v7 = va::va(
           this: &v16,
           fmt: "_video%d",
           a3: v2,
           a4: v4,
           a5: v3,
           a6: v9,
           a7: v10,
           a8: v11,
           a9: v12,
           a10: v13,
           a11: v14);
    v8 = idImageManager::ScratchImage(this: globalImages, _name: v7->buffer, imgOpts: &v15);
    p_file[4] = (const idInGameVideoFile *)v8;
    ++v5;
    p_file[5] = (const idInGameVideoFile *)v8->lockRect[0].pBits;
    p_file += 7;
    *(_BYTE *)p_file = 0;
  }
  while ( v5 < 6 );
}


// ========================================================================
// ??1idInGameVideoManagerLocal@@UAA@XZ
// EA  : 0x828D1AA0
// RVA : 0x008D1AA0
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::~idInGameVideoManagerLocal(idInGameVideoManagerLocal *this)
{
  this->__vftable = (idInGameVideoManagerLocal_vtbl *)&idInGameVideoManagerLocal::`vftable';
  if ( this->parallelJobList != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    this->parallelJobList = nullptr;
  }
  this->__vftable = (idInGameVideoManagerLocal_vtbl *)&idInGameVideoManager::`vftable';
}


// ========================================================================
// __unwind$229584
// EA  : 0x828D1B1C
// RVA : 0x008D1B1C
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void _unwind_229584()
{
  int v0; // r12

  idInGameVideoManager::~idInGameVideoManager(this: *(idInGameVideoManager **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetVideoTime@idInGameVideoManagerLocal@@UAAXHH@Z
// EA  : 0x828D1B48
// RVA : 0x008D1B48
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::SetVideoTime(idInGameVideoManagerLocal *this, unsigned int index, int time)
{
  idGame *v6; // r3
  int v7; // r3

  if ( index > 5 )
  {
    idLib::Warning(fmt: "Video index %d out of range.  Valid index 0-%d", index, 5);
  }
  else
  {
    if ( com_useGameTimeForVideos.valueInteger != 0 && common->Game(this: common) != nullptr )
    {
      v6 = common->Game(this: common);
      v7 = v6->GetGameMs(this: v6, a2: GAMETIME_SCALED);
    }
    else
    {
      v7 = Sys_Milliseconds();
    }
    this->videos[index].timeOffset = v7 - time;
  }
}


// ========================================================================
// ?SetPaused@idInGameVideoManagerLocal@@UAAXH_N@Z
// EA  : 0x828D1C10
// RVA : 0x008D1C10
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::SetPaused(idInGameVideoManagerLocal *this, unsigned int index, bool paused)
{
  idGame *v5; // r3
  int v6; // r3

  if ( index > 5 )
  {
    idLib::Warning(fmt: "Video index %d out of range.  Valid index 0-%d", index, 5);
  }
  else if ( paused )
  {
    if ( com_useGameTimeForVideos.valueInteger != 0 && common->Game(this: common) != nullptr )
    {
      v5 = common->Game(this: common);
      v6 = v5->GetGameMs(this: v5, a2: GAMETIME_SCALED);
    }
    else
    {
      v6 = Sys_Milliseconds();
    }
    this->videos[index].pausedTime = v6;
  }
  else
  {
    this->videos[index].pausedTime = -1;
  }
}


// ========================================================================
// ??1idInGameVideoFile@@UAA@XZ
// EA  : 0x828D1D08
// RVA : 0x008D1D08
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoFile::~idInGameVideoFile(idInGameVideoFile *this)
{
  unsigned __int8 *buffer; // r4

  this->__vftable = (idInGameVideoFile_vtbl *)&idInGameVideoFile::`vftable';
  if ( videoManager != nullptr )
    idInGameVideoManagerLocal::UnbindVideo(this: &localVideoManager, file: this);
  buffer = this->buffer;
  if ( buffer != nullptr )
  {
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    this->buffer = nullptr;
  }
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$229636
// EA  : 0x828D1D98
// RVA : 0x008D1D98
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void _unwind_229636()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?Update@idInGameVideoManagerLocal@@UAAXXZ
// EA  : 0x828D1F38
// RVA : 0x008D1F38
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoManagerLocal::Update(idInGameVideoManagerLocal *this)
{
  idParallelJobList *parallelJobList; // r3
  int *p_dctBufferSize; // r31
  int *p_pausedTime; // r30
  int i; // r22
  int v6; // r11
  idGame *v7; // r3
  int v8; // r3
  int v9; // r11
  int v10; // r11
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r7
  unsigned int v14; // r10
  int v15; // r8
  int v16; // r7
  int v17; // r11
  int v18; // r10

  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
  {
    idParallelJobList::Wait(this: parallelJobList);
    console->AddJobListTimeRange(
      this: console,
      a2: RANGE_JBL_VDEO,
      a3: &idColor::colorYellow,
      a4: this->parallelJobList,
      a5: 0);
    p_dctBufferSize = &this->parms[0].dctBufferSize;
    p_pausedTime = &this->videos[0].pausedTime;
    for ( i = 6; i != 0; --i )
    {
      v6 = p_pausedTime[3];
      if ( v6 != 0 && *(_DWORD *)(v6 + 36) != 0 )
      {
        if ( com_useGameTimeForVideos.valueInteger != 0 && common->Game(this: common) != nullptr )
        {
          v7 = common->Game(this: common);
          v8 = v7->GetGameMs(this: v7, a2: GAMETIME_SCALED);
        }
        else
        {
          v8 = Sys_Milliseconds();
        }
        v9 = *p_pausedTime;
        if ( *p_pausedTime < 0 )
          v9 = v8;
        v10 = v9 - *(p_pausedTime - 1);
        if ( v10 >= 0 )
        {
          v12 = *(_DWORD *)(p_pausedTime[3] + 36);
          v13 = *(_DWORD *)(v12 + 4);
          v14 = *(_DWORD *)(v12 + 8);
          v11 = v13 * v10 / 1000;
          if ( *((_BYTE *)p_pausedTime + 4) != 0 )
          {
            __twllei(v14, 0);
            v11 %= v14;
          }
          else if ( v11 > v14 - 1 )
          {
            v11 = v14 - 1;
          }
        }
        else
        {
          v11 = 0;
        }
        if ( v11 != p_pausedTime[2] )
        {
          p_pausedTime[2] = v11;
          *((_BYTE *)p_dctBufferSize - 8) = 90;
          *((_BYTE *)p_dctBufferSize - 7) = 80;
          v15 = 4 * (v11 + 3);
          v16 = p_pausedTime[3];
          *p_dctBufferSize = *(_DWORD *)(4 * (v11 + 4) + *(_DWORD *)(v16 + 36))
                           - *(_DWORD *)(v15 + *(_DWORD *)(v16 + 36));
          v17 = *(_DWORD *)(v16 + 36);
          v18 = *(_DWORD *)(v15 + v17);
          p_dctBufferSize[3] = 512;
          *((_BYTE *)p_dctBufferSize + 16) = 1;
          *(p_dctBufferSize - 1) = v18 + v17;
          idParallelJobList::AddJob(
            this: this->parallelJobList,
            function: (void (__fastcall *)(void *))VideoTranscodeJob,
            data: p_dctBufferSize - 2);
        }
      }
      p_pausedTime += 5;
      p_dctBufferSize += 7;
    }
    idParallelJobList::Submit(this: this->parallelJobList, waitForJobList: nullptr, parallelism: -1);
  }
}


// ========================================================================
// ?LoadResource@idInGameVideoFile@@UAAXXZ
// EA  : 0x828D2120
// RVA : 0x008D2120
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __fastcall idInGameVideoFile::LoadResource(idInGameVideoFile *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int8 *buffer; // r4
  const char *str; // r28
  idFile *v8; // r3
  idFile *v9; // r31
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  signed int v13; // r3
  signed int v14; // r29
  unsigned __int8 *v15; // r3
  __int64 v16; // r10
  __int64 v17; // r6
  int v18; // [sp+8h] [-78h]
  int v19; // [sp+Ch] [-74h]
  int v20; // [sp+10h] [-70h]
  int v21; // [sp+14h] [-6Ch]
  int v22; // [sp+18h] [-68h]
  int v23; // [sp+1Ch] [-64h]

  buffer = this->buffer;
  if ( buffer != nullptr )
  {
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    this->buffer = nullptr;
  }
  str = this->name.str;
  if ( *str != 0 )
  {
    v8 = fileSystem->OpenFileRead(this: fileSystem, a2: this->name.str, a3: 1, a4: 0);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v13 = v8->Length(this: v8);
      v14 = v13;
      if ( v13 >= 0 )
      {
        if ( (unsigned int)v13 >= 0xC )
        {
          v15 = (unsigned __int8 *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\engine\\renderer\\InGameVideo.cpp(333) : TAG_VIDEO",
                                     size: v13,
                                     tag: TAG_VIDEO,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
          this->buffer = v15;
          v9->Read(this: v9, a2: v15, a3: v14);
          LODWORD(v17) = this->buffer;
          if ( *(_DWORD *)v17 != 3490902 )
          {
            HIDWORD(v17) = str;
            idResource::SetResourceError(
              this: &this->idResource,
              fmt: "Bad magic in video '%s'",
              a3: v17,
              a4: 0x35445600350000LL,
              a5: v16,
              a6: v18,
              a7: v19,
              a8: v20,
              a9: v21,
              a10: v22,
              a11: v23);
            idInGameVideoFile::Free(this);
          }
          ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
        }
        else
        {
          HIDWORD(v12) = str;
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Video '%s' too small",
            a3: v12,
            a4: v11,
            a5: v10,
            a6: v18,
            a7: v19,
            a8: v20,
            a9: v21,
            a10: v22,
            a11: v23);
          idInGameVideoFile::Free(this);
          ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
        }
      }
      else
      {
        HIDWORD(v12) = str;
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Could not open video '%s'",
          a3: v12,
          a4: v11,
          a5: v10,
          a6: v18,
          a7: v19,
          a8: v20,
          a9: v21,
          a10: v22,
          a11: v23);
        ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
      }
    }
  }
  else
  {
    idResource::SetResourceError(
      this: &this->idResource,
      fmt: "Empty name on ingamevideo",
      a3,
      a4,
      a5,
      a6: v18,
      a7: v19,
      a8: v20,
      a9: v21,
      a10: v22,
      a11: v23);
  }
}


// ========================================================================
// `dynamic initializer for 'idInGameVideoFile::resourceList''
// EA  : 0x8334C0B8
// RVA : 0x0134C0B8
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idInGameVideoFile::resourceList__()
{
  idResourceList::idResourceList(this: &idInGameVideoFile::resourceList, typeName: "video");
  idInGameVideoFile::resourceList.__vftable = (idTypedResourceList<idInGameVideoFile>_vtbl *)&idTypedResourceList<idInGameVideoFile>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idInGameVideoFile::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'com_useGameTimeForVideos''
// EA  : 0x8334C108
// RVA : 0x0134C108
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_useGameTimeForVideos__()
{
  idCVar::idCVar(
    this: &com_useGameTimeForVideos,
    name: "com_useGameTimeForVideos",
    value: "0",
    flags: 1,
    description: "1 = use game time to pump videos, necessary for correct frame rates with com_captureFrames",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_useGameTimeForVideos__);
}


// ========================================================================
// `dynamic initializer for 'localVideoManager''
// EA  : 0x8334C160
// RVA : 0x0134C160
// PDB : w:\tech5\engine\renderer\ingamevideo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localVideoManager__()
{
  idInGameVideoManagerLocal::idInGameVideoManagerLocal(this: &localVideoManager);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localVideoManager__);
}

