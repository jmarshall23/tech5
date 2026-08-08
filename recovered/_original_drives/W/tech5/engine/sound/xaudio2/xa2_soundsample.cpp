
// ========================================================================
// ??0idSoundSample_XAudio2@@QAA@XZ
// EA  : 0x8299F4C8
// RVA : 0x0099F4C8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

idSoundSample_XAudio2 *__fastcall idSoundSample_XAudio2::idSoundSample_XAudio2(idSoundSample_XAudio2 *this)
{
  idResource::idResource(this);
  this->loaded = false;
  this->timestamp = -1;
  this->__vftable = (idSoundSample_XAudio2_vtbl *)&idSoundSample_XAudio2::`vftable';
  this->localizedStream = false;
  memset(Dst: &this->format, Val: 0, Size: sizeof(this->format));
  this->numStaticSamples = 0;
  this->numStreamSamples = 0;
  this->staticBufferSize = 0;
  this->staticBuffer = nullptr;
  this->firstValidSample = 0;
  this->lastValidSample = 0;
  this->loopBegin = 0;
  this->loopEnd = 0;
  this->streamBlockSize = 0;
  this->streamedLength = 0;
  this->streamedOffset = 0;
  this->streamFile = nullptr;
  this->xma2SeekTable = nullptr;
  this->channelMask = 0;
  return this;
}


// ========================================================================
// ?FreeData@idSoundSample_XAudio2@@QAAXXZ
// EA  : 0x8299F568
// RVA : 0x0099F568
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void __fastcall idSoundSample_XAudio2::FreeData(
        idSoundSample_XAudio2 *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int *xma2SeekTable; // r4
  idFile *streamFile; // r10
  idFile *v8; // r3
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]
  int v13; // [sp+18h] [-58h]
  int v14; // [sp+1Ch] [-54h]

  idResource::SetResourceError(this, fmt: nullptr, a3, a4, a5, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
  if ( this->staticBuffer != nullptr )
  {
    idSoundSystemLocal::StopVoicesWithSample(this: &soundSystemLocal, sample: (const idSoundSample *const)this);
    XMemFree(pAddress: (void *)this->staticBuffer, dwAllocAttributes: 0xAB280000);
  }
  xma2SeekTable = this->xma2SeekTable;
  if ( xma2SeekTable != nullptr )
  {
    idMem::Free(this: &mem, ptr: xma2SeekTable, align: ALIGN_16);
    this->xma2SeekTable = nullptr;
  }
  this->timestamp = -1;
  memset(Dst: &this->format, Val: 0, Size: sizeof(this->format));
  streamFile = this->streamFile;
  this->loaded = false;
  this->numStaticSamples = 0;
  this->numStreamSamples = 0;
  this->staticBufferSize = 0;
  this->staticBuffer = nullptr;
  this->firstValidSample = 0;
  this->lastValidSample = 0;
  this->loopEnd = 0;
  this->loopBegin = 0;
  if ( streamFile != nullptr
    && this->streamFile != resourceManager->GetStreamFile(this: resourceManager)
    && this->streamFile != resourceManager->GetLocalizedStreamFile(this: resourceManager)
    && this->streamFile != resourceManager->GetCachedStreamFile(this: resourceManager) )
  {
    idStreamFileCache::Flush(this: streamFileCache);
    if ( resourceManager->GetStreamFile(this: resourceManager) != nullptr )
    {
      v8 = this->streamFile;
      if ( v8 != nullptr )
        ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
    }
    this->streamFile = nullptr;
  }
}


// ========================================================================
// ?GetCRC32@idSoundSample_XAudio2@@QBAIXZ
// EA  : 0x8299F6D0
// RVA : 0x0099F6D0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

unsigned int __fastcall idSoundSample_XAudio2::GetCRC32(idSoundSample_XAudio2 *this)
{
  return CRC32_BlockChecksum(data: this->staticBuffer, length: this->staticBufferSize);
}


// ========================================================================
// ??1idSoundSample_XAudio2@@MAA@XZ
// EA  : 0x8299F760
// RVA : 0x0099F760
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void __fastcall idSoundSample_XAudio2::~idSoundSample_XAudio2(
        idSoundSample_XAudio2 *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  LODWORD(a5) = &idSoundSample_XAudio2::`vftable';
  this->__vftable = (idSoundSample_XAudio2_vtbl *)&idSoundSample_XAudio2::`vftable';
  idSoundSample_XAudio2::FreeData(this, a2, a3, a4, a5);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$224683
// EA  : 0x8299F7B0
// RVA : 0x0099F7B0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_224683()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?MakeDefault@idSoundSample_XAudio2@@QAAXXZ
// EA  : 0x8299F7D8
// RVA : 0x0099F7D8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void __fastcall idSoundSample_XAudio2::MakeDefault(
        idSoundSample_XAudio2 *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  const char *v6; // r3
  int v7; // r11
  int i; // ctr
  int numStaticSamples; // r11
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  int v15; // [sp+1Ch] [-54h]

  if ( this->resourceError == nullptr )
  {
    HIDWORD(a3) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: "defaulted '%s'",
      a3,
      a4,
      a5,
      a6: v10,
      a7: v11,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15);
  }
  this->timestamp = -1;
  this->numStaticSamples = 256;
  this->numStreamSamples = 0;
  memset(Dst: &this->format, Val: 0, Size: sizeof(this->format));
  this->format.basic.formatTag = 1;
  this->format.basic.numChannels = 1;
  this->format.basic.bitsPerSample = 8;
  this->format.basic.samplesPerSec = 1000;
  this->format.basic.blockSize = 1;
  this->format.basic.avgBytesPerSec = 1000;
  v6 = (const char *)XMemAlloc(dwSize: 0x100u, dwAllocAttributes: 0xAB280000);
  v7 = 0;
  for ( i = 128; i != 0; --i )
  {
    v6[v7] = 0;
    v6[v7 + 1] = -1;
    v7 += 2;
  }
  numStaticSamples = this->numStaticSamples;
  this->staticBuffer = v6;
  this->staticBufferSize = 256;
  this->firstValidSample = 0;
  this->loopBegin = 0;
  this->lastValidSample = numStaticSamples;
  this->loopEnd = numStaticSamples;
  this->channelMask = 0;
}


// ========================================================================
// ?PreCacheStreamData@idSoundSample_XAudio2@@QBAH_N@Z
// EA  : 0x8299F8A8
// RVA : 0x0099F8A8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

unsigned int __fastcall idSoundSample_XAudio2::PreCacheStreamData(idSoundSample_XAudio2 *this, const bool highPriority)
{
  unsigned int v2; // r11
  int v3; // r9
  __int64 v4; // r6
  int v6; // [sp+8h] [-58h]
  pfcRequest_t v7; // [sp+Ch] [-54h]

  if ( this->streamedLength == 0 )
    return 0;
  v2 = highPriority ? 0 : 3;
  if ( v2 > 1 )
    v3 = (__CFADD__(4 * (3 - v2), 0x80000000) ? 0 : 4 * (3 - v2)) << 15;
  else
    v3 = 1015808;
  LODWORD(v4) = this->streamBlockSize;
  HIDWORD(v4) = this->streamedOffset;
  return idStreamFileCache::ReadCachedData(
           this: streamFileCache,
           cacheFile: this->streamFile,
           ofs: v4,
           length: nullptr,
           dest: 0,
           blockingRead: (idStreamControlThread_vtbl *)v3,
           priority: (idStreamControlThread_vtbl *)(64 << (2 * (v2 + 1))),
           persistence: v6,
           pfc: v7);
}


// ========================================================================
// ?ReloadIfStale@idSoundSample_XAudio2@@UAA_NXZ
// EA  : 0x8299F9F8
// RVA : 0x0099F9F8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

int __fastcall idSoundSample_XAudio2::ReloadIfStale(idSoundSample_XAudio2 *this)
{
  unsigned int v2; // r3
  unsigned int v3; // r11
  unsigned int v4; // r3
  unsigned int timestamp; // r11
  unsigned int v6; // r3
  unsigned int v7; // r11
  idStr v9; // [sp+50h] [-80h] BYREF
  idStr v10; // [sp+70h] [-60h] BYREF
  idStr v11[2]; // [sp+90h] [-40h] BYREF

  idStr::idStr(this: v11, text: this->name.str);
  idStr::SetFileExtension(this: v11, extension: "wav");
  idStr::idStr(this: &v10, text: "compressed");
  idStr::AppendPath(this: &v10, text: this->name.str);
  idStr::SetFileExtension(this: &v10, extension: "xma");
  idStr::idStr(this: &v9, text: "compressed");
  idStr::AppendPath(this: &v9, text: this->name.str);
  idStr::SetFileExtension(this: &v9, extension: "msadpcm");
  if ( s_useCompression.valueInteger == 0 )
    goto LABEL_11;
  v2 = fileSystem->GetTimestamp(this: fileSystem, a2: v10.data, a3: false);
  if ( v2 == -1 )
  {
    v4 = fileSystem->GetTimestamp(this: fileSystem, a2: v9.data, a3: false);
    if ( v4 != -1 )
    {
      timestamp = this->timestamp;
      if ( v4 <= timestamp && timestamp != -1 )
        goto LABEL_15;
LABEL_14:
      this->LoadResource(this);
      idStr::FreeData(this: &v9);
      idStr::FreeData(this: &v10);
      idStr::FreeData(this: v11);
      return 1;
    }
LABEL_11:
    v6 = fileSystem->GetTimestamp(this: fileSystem, a2: v11[0].data, a3: false);
    if ( v6 == -1 )
      goto LABEL_15;
    v7 = this->timestamp;
    if ( v6 <= v7 && v7 != -1 )
      goto LABEL_15;
    goto LABEL_14;
  }
  v3 = this->timestamp;
  if ( v2 > v3 || v3 == -1 )
    goto LABEL_14;
LABEL_15:
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v10);
  idStr::FreeData(this: v11);
  return 0;
}


// ========================================================================
// __unwind$225142
// EA  : 0x8299FC28
// RVA : 0x0099FC28
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$225143
// EA  : 0x8299FC50
// RVA : 0x0099FC50
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225143()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$225144
// EA  : 0x8299FC78
// RVA : 0x0099FC78
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225144()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?LoadWav@idSoundSample_XAudio2@@IAA_NABVidStr@@@Z
// EA  : 0x8299FD20
// RVA : 0x0099FD20
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idSoundSample_XAudio2::LoadWav(idSoundSample_XAudio2 *this, const idStr *filename)
{
  __int64 v3; // r22
  idFile *v4; // r3
  idFile *v5; // r29
  bool *p_localizedStream; // r24
  char *data; // r28
  int v9; // r26
  int offset; // r11
  unsigned int *p_streamedOffset; // r27
  idWaveFile::waveFmt_t *p_format; // r28
  int *v13; // r3
  int blockCount; // r7
  int v15; // r10
  fmtFound_t *list; // r11
  int numChannels; // r10
  unsigned int samplesPerSec; // r9
  idResourceManager_vtbl *v19; // r11
  int (*GetLocalizedStreamFile)(void); // r10
  idFile *v21; // r3
  BOOL v22; // r10
  idFile *v23; // r3
  idWaveFile::waveFmt_t *v24; // r26
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  const char *v28; // r4
  unsigned int v29; // r3
  int formatTag; // r9
  signed int blockSize; // r29
  unsigned __int8 v32; // r11
  _BYTE v33[12]; // r10 OVERLAPPED
  bool v34; // r10
  int staticBufferSize; // r11
  bool v36; // r9
  bool v37; // cr57
  int streamBlockSize; // r7
  unsigned int v39; // r10
  int v40; // r7
  int v41; // r7 OVERLAPPED
  bool v42; // zf
  idFile *v43; // r3
  const char *v44; // r4
  __int64 v45; // r6
  signed int v46; // r8
  int *p_loopEnd; // r29
  int v48; // r7
  int *p_loopBegin; // r28
  int streamedLength; // r6
  int *v51; // r5
  int validBitsPerSample; // r4
  int v53; // r11
  int v54; // r10
  int v55; // r11
  int *v56; // r4
  unsigned int v57; // r29
  __int64 v58; // r8
  __int64 v59; // r6
  __int64 v60; // r10
  int *v61; // r3
  idFile *file; // r11
  __int64 v63; // r6
  unsigned int v64; // r10
  int *v65; // r11
  int v66; // r10
  int *xma2SeekTable; // r11
  int v68; // r8
  unsigned int bytesPerBlock; // r9
  int v70; // r7
  int v71; // r4
  unsigned int loopBegin; // r11
  unsigned int playBegin; // r10
  unsigned int v74; // r9
  __int64 v75; // r8
  __int64 v76; // r10
  int v77; // r9
  __int64 v78; // r8
  __int64 v79; // r6
  __int64 v80; // r10
  int numStaticSamples; // r10
  int v82; // r11
  int firstValidSample; // r11
  int lastValidSample; // r10
  unsigned int v85; // r3
  int v86; // r11
  int v87; // r9
  char *v88; // r11
  int v89; // ctr
  char v90; // r9
  int v91; // r29
  int v92; // [sp+8h] [-2D8h]
  int v93; // [sp+Ch] [-2D4h]
  int v94; // [sp+10h] [-2D0h]
  int v95; // [sp+14h] [-2CCh]
  int v96; // [sp+18h] [-2C8h]
  int v97; // [sp+1Ch] [-2C4h]
  int *v98; // [sp+50h] [-290h] BYREF
  int v99; // [sp+54h] [-28Ch] BYREF
  int v100; // [sp+58h] [-288h] BYREF
  int v101; // [sp+5Ch] [-284h] BYREF
  _DWORD v102[2]; // [sp+60h] [-280h] BYREF
  aas2Edge_t v103; // [sp+68h] [-278h] BYREF
  _DWORD v104[3]; // [sp+74h] [-26Ch] BYREF
  idLocalizedSampleOnDisc v105; // [sp+80h] [-260h] BYREF
  idLocalizedSampleOnDisc v106; // [sp+A0h] [-240h] BYREF
  idStr v107; // [sp+C0h] [-220h] BYREF
  idWaveFile v108; // [sp+E0h] [-200h] BYREF

  HIDWORD(v3) = filename;
  if ( idLib::production != PROD_DEVELOPMENT
    && (idStr::Find(searchIn: filename->data, searchFor: ".idxma", casesensitive: true, start: 0, end: filename->len) >= 0
     || idStr::Find(
          searchIn: *(const char **)(HIDWORD(v3) + 4),
          searchFor: ".idmsa",
          casesensitive: true,
          start: 0,
          end: *(_DWORD *)HIDWORD(v3)) >= 0) )
  {
    v4 = fileSystem->OpenFileRead(this: fileSystem, a2: *(_DWORD *)(HIDWORD(v3) + 4), a3: 1, a4: 0);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->Read(this: v4, a2: v104, a3: 4u);
      if ( v104[0] != 1836741236 )
      {
        ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
        idLib::Warning(fmt: "sound sample %s had invalid magic", *(const char **)(HIDWORD(v3) + 4));
        return 0;
      }
      LODWORD(v3) = 0;
      this->localizedStream = false;
      p_localizedStream = &this->localizedStream;
      v5->Read(this: v5, a2: &v99, a3: 4u);
      v5->Read(this: v5, a2: &this->localizedStream, a3: 1u);
      if ( v99 <= 1 )
      {
        v105.lang[0] = 0;
        memset(&v105.offset, 0, 12);
        idLocalizedSampleOnDisc::Read(this: &v105, file: v5);
        if ( v105.lang[0] != 0 && idStr::Icmp(s1: v105.lang, s2: sys_lang.valueString.data) != 0
          || (offset = v105.offset, v105.offset < 0) )
        {
LABEL_15:
          ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
          idLib::Warning(
            fmt: "could not find %s version of %s",
            sys_lang.valueString.data,
            *(const char **)(HIDWORD(v3) + 4));
          return 0;
        }
      }
      else
      {
        *p_localizedStream = true;
        data = sys_lang.valueString.data;
        if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "czech") == 0 )
          data = "english";
        v9 = 0;
        if ( v99 <= 0 )
          goto LABEL_15;
        while ( 1 )
        {
          v106.lang[0] = 0;
          memset(&v106.offset, 0, 12);
          idLocalizedSampleOnDisc::Read(this: &v106, file: v5);
          if ( idStr::Icmp(s1: v106.lang, s2: data) == 0 )
            break;
          if ( ++v9 >= v99 )
            goto LABEL_15;
        }
        offset = v106.offset;
        if ( v106.offset < 0 )
          goto LABEL_15;
      }
      v5->Seek(this: v5, a2: offset, a3: FS_SEEK_SET);
      v5->Read(this: v5, a2: &this->timestamp, a3: 4u);
      v5->Read(this: v5, a2: &this->loaded, a3: 1u);
      this->loaded = true;
      v5->Read(this: v5, a2: &this->numStaticSamples, a3: 4u);
      v5->Read(this: v5, a2: &this->numStreamSamples, a3: 4u);
      v5->Read(this: v5, a2: &this->staticBufferSize, a3: 4u);
      v5->Read(this: v5, a2: &this->firstValidSample, a3: 4u);
      v5->Read(this: v5, a2: &this->lastValidSample, a3: 4u);
      v5->Read(this: v5, a2: &this->loopBegin, a3: 4u);
      v5->Read(this: v5, a2: &this->loopEnd, a3: 4u);
      v5->Read(this: v5, a2: &this->streamBlockSize, a3: 4u);
      v5->Read(this: v5, a2: &this->streamedLength, a3: 4u);
      p_streamedOffset = &this->streamedOffset;
      v5->Read(this: v5, a2: &this->streamedOffset, a3: 4u);
      v5->Read(this: v5, a2: &this->channelMask, a3: 4u);
      p_format = &this->format;
      idWaveFile::ReadWaveFormatDirect(format: &this->format, file: v5);
      if ( this->format.basic.formatTag == 358 )
      {
        v13 = (int *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\engine\\sound\\XAudio2\\XA2_SoundSample.cpp(680) : TAG_SOUND_SAMPLETABLES",
                       size: __ROL4__(this->format.extra.xma2.blockCount, 2),
                       tag: TAG_SOUND_SAMPLETABLES,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
        blockCount = this->format.extra.xma2.blockCount;
        this->xma2SeekTable = v13;
        v5->Read(this: v5, a2: v13, a3: __ROL4__(blockCount, 2));
      }
      else
      {
        this->xma2SeekTable = nullptr;
      }
      v15 = 0;
      if ( fmtFound.num > 0 )
      {
        list = fmtFound.list;
        do
        {
          if ( list->formatTag == p_format->basic.formatTag && list->numChannels == this->format.basic.numChannels )
            break;
          ++v15;
          ++list;
        }
        while ( v15 < fmtFound.num );
      }
      if ( v15 == fmtFound.num && fmtFound.num < fmtFound.size )
      {
        numChannels = this->format.basic.numChannels;
        samplesPerSec = this->format.basic.samplesPerSec;
        v103.vertexNum[0] = p_format->basic.formatTag;
        v103.vertexNum[1] = numChannels;
        v103.flags = samplesPerSec;
        idList<idRenderModelEffects::deferredStage_t,5>::Append(this: (idList<aas2Edge_t,37> *)&fmtFound, obj: &v103);
      }
      if ( idLib::production < PROD_PRODUCTION )
      {
        this->streamFile = nullptr;
      }
      else
      {
        v19 = resourceManager->__vftable;
        if ( *p_localizedStream )
          GetLocalizedStreamFile = (int (*)(void))v19->GetLocalizedStreamFile;
        else
          GetLocalizedStreamFile = (int (*)(void))v19->GetStreamFile;
        v21 = (idFile *)GetLocalizedStreamFile();
        v102[0] = 0;
        this->streamFile = v21;
        v98 = nullptr;
        *(_QWORD *)v103.vertexNum = v3;
        v100 = 0;
        v101 = 0;
        if ( !resourceManager->GetPatchFileInfo(
                this: resourceManager,
                a2: *(const char **)(HIDWORD(v3) + 4),
                a3: (__int64 *)&v103,
                a4: (unsigned int *)&v100,
                a5: (unsigned int *)&v101,
                a6: v102,
                a7: (int *)&v98) )
          ((void (__fastcall *)(idResourceManager *, _DWORD, aas2Edge_t *, int *, int *, _DWORD *))resourceManager->GetCacheFileInfo)(
            a1: resourceManager,
            a2: *(_DWORD *)(HIDWORD(v3) + 4),
            a3: &v103,
            a4: &v100,
            a5: &v101,
            a6: v102);
        v22 = *p_localizedStream;
        *p_streamedOffset = v102[0];
        if ( !v22 && resourceManager->GetCachedStreamFile(this: resourceManager) != nullptr )
        {
          v23 = resourceManager->GetCachedStreamFile(this: resourceManager);
          if ( (int)(*p_streamedOffset + this->streamedLength) < (int)v23->Length(this: v23) )
            this->streamFile = resourceManager->GetCachedStreamFile(this: resourceManager);
        }
      }
      this->staticBuffer = nullptr;
      ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
      return 1;
    }
  }
  v108.file = nullptr;
  v108.chunks.num = 0;
  v108.chunks.size = 32;
  v108.chunks.granularity = 1;
  v108.chunks.list = v108.chunks.staticList;
  v108.chunks.memTag = 5;
  v108.chunks.listStatic = 1;
  if ( (unsigned __int8)idWaveFile::Open(this: &v108, filename: *(const char **)(HIDWORD(v3) + 4)) == 0 )
  {
    idWaveFile::~idWaveFile(this: &v108);
    return 0;
  }
  v24 = &this->format;
  v28 = idWaveFile::ReadWaveFormat(this: &v108, format: &this->format);
  if ( v28 != nullptr )
  {
    idResource::SetResourceError(
      this,
      fmt: v28,
      a3: v27,
      a4: v26,
      a5: v25,
      a6: v92,
      a7: v93,
      a8: v94,
      a9: v95,
      a10: v96,
      a11: v97);
    idWaveFile::~idWaveFile(this: &v108);
    return 0;
  }
  v29 = v108.file->Timestamp(this: v108.file);
  formatTag = v24->basic.formatTag;
  blockSize = this->format.basic.blockSize;
  this->timestamp = v29;
  if ( formatTag == 358 )
    blockSize = this->format.extra.xma2.bytesPerBlock;
  this->staticBufferSize = idWaveFile::SeekToChunk(this: &v108, id: 0x64617461u);
  idStr::idStr(this: &v107, text: (const idStr *)HIDWORD(v3));
  idStr::MakeNameCanonical(this: &v107);
  if ( idLib::production == PROD_DEVELOPMENT || (v32 = 1, sys_localization.valueInteger != 0) )
    v32 = 0;
  *(_DWORD *)v33 = v32;
  v34 = v32 != 0 || v24->basic.formatTag != 1 && s_useStreaming.valueInteger != 0;
  staticBufferSize = this->staticBufferSize;
  v36 = v34;
  v37 = s_streamBufferSizeK.valueInteger << 10 > staticBufferSize;
  this->streamBlockSize = s_streamBufferSizeK.valueInteger << 10;
  if ( v37 )
    this->streamBlockSize = staticBufferSize;
  streamBlockSize = this->streamBlockSize;
  __twllei(blockSize, 0);
  v39 = blockSize & ~(__ROL4__(streamBlockSize, 1) - 1);
  v40 = streamBlockSize - streamBlockSize % blockSize;
  __twlgei(v39, 0xFFFFFFFF);
  this->streamBlockSize = v40;
  if ( v40 == 0 )
    this->streamBlockSize = blockSize;
  *(_DWORD *)&v33[8] = this->streamBlockSize;
  v41 = 2 * *(_DWORD *)&v33[8];
  v42 = !v36;
  *(_DWORD *)&v33[4] = (((staticBufferSize ^ (2 * *(_DWORD *)&v33[8])) >= 0)
                      + (2 * *(_DWORD *)&v33[8] >= (unsigned int)staticBufferSize))
                     & 1;
  if ( v42 || (*(_DWORD *)&v33[4] = v33[7], *(_QWORD *)v33 == 0) )
  {
    this->streamedOffset = 0;
    this->streamedLength = 0;
    this->streamBlockSize = 0;
  }
  else
  {
    if ( *(_DWORD *)v33 != 0 )
    {
      this->staticBufferSize = 0;
      this->streamedLength = staticBufferSize;
    }
    else
    {
      *(_DWORD *)&v33[4] = this->streamBlockSize;
      this->streamedLength = staticBufferSize - *(_DWORD *)&v33[8];
      this->staticBufferSize = *(_DWORD *)&v33[4];
    }
    this->streamedOffset = idWaveFile::GetChunkOffset(this: &v108, id: 0x64617461u) + this->staticBufferSize;
    v43 = resourceManager->GetCacheFile(this: resourceManager);
    this->streamFile = v43;
    v44 = *(const char **)(HIDWORD(v3) + 4);
    if ( v43 != nullptr )
    {
      resourceManager->GetCacheFileInfo(
        this: resourceManager,
        a2: v44,
        a3: (__int64 *)&v103,
        a4: (unsigned int *)&v101,
        a5: (unsigned int *)&v100,
        a6: (unsigned int *)&v98,
        a7: false);
      *(_DWORD *)&v33[4] = v103.vertexNum[1];
      *(_DWORD *)&v33[8] = v103.vertexNum[1];
      *(_DWORD *)v33 = v103.vertexNum[1] + this->streamedOffset;
      this->streamedOffset = *(_DWORD *)v33;
    }
    else
    {
      this->streamFile = fileSystem->OpenFileRead(this: fileSystem, a2: v44, a3: 0, a4: 0);
    }
  }
  HIDWORD(v45) = v24->basic.formatTag;
  switch ( HIDWORD(v45) )
  {
    case 1:
    case 0xFFFF:
      v77 = this->staticBufferSize;
      LODWORD(v78) = this->streamedLength;
      HIDWORD(v78) = this->format.basic.blockSize;
      LODWORD(v79) = this->format.basic.bitsPerSample;
      HIDWORD(v79) = __ROL4__(v77, 1) - 1;
      this->numStaticSamples = v77 / SHIDWORD(v78);
      HIDWORD(v80) = HIDWORD(v78) & ~(__ROL4__(v78, 1) - 1);
      LODWORD(v80) = HIDWORD(v78) & ~HIDWORD(v79);
      __twllei(HIDWORD(v78), 0);
      this->numStreamSamples = (int)v78 / SHIDWORD(v78);
      __twllei(HIDWORD(v78), 0);
      __twlgei(v80, 0xFFFFFFFF);
      __twlgei(HIDWORD(v80), 0xFFFFFFFF);
      if ( (_DWORD)v79 != 16 )
      {
        HIDWORD(v79) = *(_DWORD *)(HIDWORD(v3) + 4);
        idResource::SetResourceError(
          this,
          fmt: "Not a 16 bit PCM wav file '%s'",
          a3: v79,
          a4: v78,
          a5: v80,
          a6: v92,
          a7: v93,
          a8: v94,
          a9: v95,
          a10: v96,
          a11: v97);
        idStr::FreeData(this: &v107);
        idWaveFile::~idWaveFile(this: &v108);
        return 0;
      }
      numStaticSamples = this->numStaticSamples;
      p_loopEnd = &this->loopEnd;
      p_loopBegin = &this->loopBegin;
      this->firstValidSample = 0;
      v82 = (int)v78 / SHIDWORD(v78) + numStaticSamples;
      v51 = &this->loopEnd;
      this->loopEnd = v82;
      v56 = &this->loopBegin;
      this->lastValidSample = v82;
      break;
    case 2:
      v46 = this->format.basic.blockSize;
      p_loopEnd = &this->loopEnd;
      v48 = this->staticBufferSize;
      p_loopBegin = &this->loopBegin;
      streamedLength = this->streamedLength;
      v51 = &this->loopEnd;
      validBitsPerSample = this->format.extra.extensible.validBitsPerSample;
      this->firstValidSample = 0;
      v53 = v48 / v46 * validBitsPerSample;
      this->numStaticSamples = v53;
      v54 = streamedLength / v46 * validBitsPerSample;
      this->numStreamSamples = v54;
      v55 = v54 + v53;
      this->loopEnd = v55;
      this->lastValidSample = v55;
      __twllei(v46, 0);
      __twllei(v46, 0);
      v56 = &this->loopBegin;
      __twlgei(v46 & ~(__ROL4__(v48, 1) - 1), 0xFFFFFFFF);
      __twlgei(v46 & ~(__ROL4__(streamedLength, 1) - 1), 0xFFFFFFFF);
      break;
    case 0x166:
      v57 = idWaveFile::SeekToChunk(this: &v108, id: 0x7365656Bu);
      LODWORD(v60) = __ROL4__(this->format.extra.xma2.blockCount, 2);
      if ( v57 != (_DWORD)v60 )
      {
        HIDWORD(v59) = *(_DWORD *)(HIDWORD(v3) + 4);
        idResource::SetResourceError(
          this,
          fmt: "Wrong number of entries in seek table '%s'",
          a3: v59,
          a4: v58,
          a5: v60,
          a6: v92,
          a7: v93,
          a8: v94,
          a9: v95,
          a10: v96,
          a11: v97);
        idStr::FreeData(this: &v107);
        idWaveFile::~idWaveFile(this: &v108);
        return 0;
      }
      v61 = (int *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\engine\\sound\\XAudio2\\XA2_SoundSample.cpp(840) : TAG_SOUND_SAMPLETABLES",
                     size: v57,
                     tag: TAG_SOUND_SAMPLETABLES,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
      file = v108.file;
      this->xma2SeekTable = v61;
      v98 = v61;
      file->Read(this: file, a2: v61, a3: v57);
      v64 = this->staticBufferSize;
      if ( v64 != 0 )
      {
        xma2SeekTable = this->xma2SeekTable;
        if ( this->streamedLength != 0 )
        {
          bytesPerBlock = this->format.extra.xma2.bytesPerBlock;
          v70 = this->format.extra.xma2.blockCount;
          __twllei(bytesPerBlock, 0);
          LODWORD(v63) = &xma2SeekTable[v64 / bytesPerBlock];
          v71 = *(_DWORD *)(v63 - 4);
          this->numStaticSamples = v71;
          this->numStreamSamples = *(int *)((char *)xma2SeekTable + __ROL4__(v70, 2) - 4) - v71;
        }
        else
        {
          v68 = *(int *)((char *)xma2SeekTable + __ROL4__(this->format.extra.xma2.blockCount, 2) - 4);
          this->numStreamSamples = 0;
          this->numStaticSamples = v68;
        }
      }
      else
      {
        v65 = this->xma2SeekTable;
        v66 = __ROL4__(this->format.extra.xma2.blockCount, 2);
        this->numStaticSamples = 0;
        this->numStreamSamples = *(int *)((char *)v65 + v66 - 4);
      }
      loopBegin = this->format.extra.xma2.loopBegin;
      playBegin = this->format.extra.xma2.playBegin;
      v74 = this->format.extra.xma2.playLength - (this->format.extra.xma2.playLength & 0x7F);
      HIDWORD(v75) = loopBegin + this->format.extra.xma2.loopLength;
      LODWORD(v75) = playBegin + v74;
      this->format.extra.xma2.playLength = v74;
      if ( HIDWORD(v75) > playBegin + v74 )
      {
        HIDWORD(v75) = playBegin - loopBegin;
        this->format.extra.xma2.loopLength = playBegin - loopBegin + v74;
      }
      HIDWORD(v76) = this->format.extra.xma2.loopLength;
      p_loopBegin = &this->loopBegin;
      this->firstValidSample = playBegin;
      p_loopEnd = &this->loopEnd;
      this->lastValidSample = v75;
      this->loopBegin = loopBegin;
      this->loopEnd = loopBegin + HIDWORD(v76);
      goto LABEL_90;
    default:
      LODWORD(v45) = *(_DWORD *)(HIDWORD(v3) + 4);
      idResource::SetResourceError(
        this,
        fmt: "Unsupported wave format %d on '%s'",
        a3: v45,
        a4: *(__int64 *)&v33[8],
        a5: *(__int64 *)&v33[4],
        a6: v92,
        a7: v93,
        a8: v94,
        a9: v95,
        a10: v96,
        a11: v97);
      idStr::FreeData(this: &v107);
      idWaveFile::~idWaveFile(this: &v108);
      return 0;
  }
  idWaveFile::ReadLoopData(this: &v108, start: v56, end: v51);
LABEL_90:
  firstValidSample = this->firstValidSample;
  if ( *p_loopBegin < firstValidSample )
    *p_loopBegin = firstValidSample;
  lastValidSample = this->lastValidSample;
  if ( *p_loopEnd > lastValidSample || *p_loopEnd == 0 )
    *p_loopEnd = lastValidSample;
  if ( *p_loopBegin > *p_loopEnd )
  {
    HIDWORD(v63) = *(_DWORD *)(HIDWORD(v3) + 4);
    LODWORD(v76) = *p_loopEnd;
    idResource::SetResourceError(
      this,
      fmt: "Loop Begin > Loop End '%s'",
      a3: v63,
      a4: v75,
      a5: v76,
      a6: v92,
      a7: v93,
      a8: v94,
      a9: v95,
      a10: v96,
      a11: v97);
  }
  v85 = this->staticBufferSize;
  if ( v85 != 0 )
  {
    this->staticBuffer = (const char *)XMemAlloc(dwSize: v85, dwAllocAttributes: 0xAB280000);
    idWaveFile::SeekToChunk(this: &v108, id: 0x64617461u);
    v108.file->Read(this: v108.file, a2: (void *)this->staticBuffer, a3: this->staticBufferSize);
    v86 = v24->basic.formatTag;
    if ( (v86 == 1 || v86 == 0xFFFF) && this->format.basic.bitsPerSample == 16 )
    {
      v87 = this->numStaticSamples;
      if ( this->format.basic.numChannels * v87 > 0 )
      {
        v88 = (char *)(this->staticBuffer - 1);
        v89 = this->format.basic.numChannels * v87;
        do
        {
          v90 = v88[1];
          v88[1] = v88[2];
          v88 += 2;
          *v88 = v90;
          --v89;
        }
        while ( v89 != 0 );
      }
    }
  }
  else
  {
    this->staticBuffer = nullptr;
  }
  idWaveFile::Close(this: &v108);
  this->channelMask = 0;
  v91 = v24->basic.formatTag;
  if ( v91 == 0xFFFF || v91 == 358 )
    this->channelMask = this->format.extra.extensible.channelMask;
  if ( this->channelMask == 0 )
    this->channelMask = idWaveFile::GetDefaultChannelMask(numChannels: this->format.basic.numChannels);
  if ( v91 == 0xFFFF )
    v24->basic.formatTag = this->format.extra.extensible.subFormat.data1;
  idStr::FreeData(this: &v107);
  idWaveFile::~idWaveFile(this: &v108);
  return 1;
}


// ========================================================================
// __unwind$225422
// EA  : 0x829A0AAC
// RVA : 0x009A0AAC
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225422()
{
  int v0; // r12

  idWaveFile::~idWaveFile(this: (idWaveFile *)(v0 - 736 + 224));
}


// ========================================================================
// __unwind$225423_0
// EA  : 0x829A0AD4
// RVA : 0x009A0AD4
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225423_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 192));
}


// ========================================================================
// ?LoadResource@idSoundSample_XAudio2@@UAAXXZ
// EA  : 0x829A0B08
// RVA : 0x009A0B08
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void __fastcall idSoundSample_XAudio2::LoadResource(
        idSoundSample_XAudio2 *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // r8
  __int64 v7; // r6
  int v8; // r4
  __int64 v9; // r10
  unsigned int v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  int v13; // r4
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // r4
  idStrStatic<256> v18; // [sp+50h] [-140h] BYREF

  idSoundSample_XAudio2::FreeData(this, a2, a3, a4, a5);
  LODWORD(v9) = &s_noSound;
  if ( s_noSound.valueInteger != 0 )
  {
    idSoundSample_XAudio2::MakeDefault(this, a2: v8, a3: v7, a4: v6, a5: v9);
  }
  else
  {
    this->loaded = true;
    idStrStatic<256>::idStrStatic<256>(this: &v18, text: "compressed/");
    idStr::Append(this: &v18, text: (char *)this->name.str);
    idStr::MakeNameCanonical(this: &v18);
    idStr::ToLower(this: &v18);
    if ( s_useCompression.valueInteger != 0 )
    {
      if ( idLib::production < PROD_PRODUCTION
        || (idStr::SetFileExtension(this: &v18, extension: "idxma"),
            (unsigned __int8)idSoundSample_XAudio2::LoadWav(this, filename: &v18) == 0) )
      {
        idStr::SetFileExtension(this: &v18, extension: "xma");
        if ( (unsigned __int8)idSoundSample_XAudio2::LoadWav(this, filename: &v18) == 0 )
        {
          idStr::SetFileExtension(this: &v18, extension: "msadpcm");
          if ( (unsigned __int8)idSoundSample_XAudio2::LoadWav(this, filename: &v18) == 0 )
          {
            idStr::SetFileExtension(this: &v18, extension: "wav");
            LODWORD(v14) = (unsigned __int8)idSoundSample_XAudio2::LoadWav(this, filename: &v18);
            if ( (_DWORD)v14 == 0 )
              idSoundSample_XAudio2::MakeDefault(this, a2: v17, a3: v16, a4: v15, a5: v14);
          }
        }
      }
    }
    else
    {
      idStr::ReplaceFirst(this: &v18, old: "compressed/", nw: &byte_8200D768);
      idStr::SetFileExtension(this: &v18, extension: "wav");
      if ( (unsigned __int8)idSoundSample_XAudio2::LoadWav(this, filename: &v18) == 0 )
        idSoundSample_XAudio2::MakeDefault(this, a2: v13, a3: v12, a4: v11, a5: v10);
    }
    idStr::FreeData(this: &v18);
  }
}


// ========================================================================
// __unwind$225933
// EA  : 0x829A0CB0
// RVA : 0x009A0CB0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void _unwind_225933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// `dynamic initializer for 'fmtFound''
// EA  : 0x83361898
// RVA : 0x01361898
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundsample.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fmtFound__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fmtFound__);
}

