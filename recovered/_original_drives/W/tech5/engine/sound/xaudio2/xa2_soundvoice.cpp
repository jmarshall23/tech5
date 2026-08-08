
// ========================================================================
// ?CompatibleFormat@idSoundVoice_XAudio2@@QAA_NPAVidSoundSample_XAudio2@@@Z
// EA  : 0x829A0CF8
// RVA : 0x009A0CF8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

BOOL __fastcall idSoundVoice_XAudio2::CompatibleFormat(idSoundVoice_XAudio2 *this, idSoundSample_XAudio2 *s)
{
  if ( this->pSourceVoice == nullptr )
    return true;
  if ( s != nullptr && s->format.basic.formatTag == this->formatTag && s->format.basic.numChannels == this->numChannels )
    return (_cntlzw(this->bitsPerSample - s->format.basic.bitsPerSample) & 0x20) != 0;
  return false;
}


// ========================================================================
// ?IsPlaying@idSoundVoice_XAudio2@@AAA_NXZ
// EA  : 0x829A0D58
// RVA : 0x009A0D58
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

BOOL __fastcall idSoundVoice_XAudio2::IsPlaying(idSoundVoice_XAudio2 *this)
{
  _BYTE v2[4]; // [sp+50h] [-20h] BYREF
  int v3; // [sp+54h] [-1Ch]

  if ( this->pSourceVoice == nullptr )
    return false;
  if ( this->currentStreamRemaining > 0 )
    return true;
  this->pSourceVoice->GetState(this: this->pSourceVoice, a2: (XAUDIO2_VOICE_STATE *)v2, a3: 256u);
  return v3 != 0;
}


// ========================================================================
// ?FlushSourceBuffers@idSoundVoice_XAudio2@@AAAXXZ
// EA  : 0x829A0DE0
// RVA : 0x009A0DE0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::FlushSourceBuffers(idSoundVoice_XAudio2 *this)
{
  IXAudio2SourceVoice *pSourceVoice; // r11

  pSourceVoice = this->pSourceVoice;
  if ( pSourceVoice != nullptr )
    ((void (*)(void))pSourceVoice->FlushSourceBuffers)();
}


// ========================================================================
// ?OnVoiceError@StreamingVoiceContext@@UAAXPAXJ@Z
// EA  : 0x829A0E08
// RVA : 0x009A0E08
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall StreamingVoiceContext::OnVoiceError(StreamingVoiceContext *this, void *__formal, HRESULT a3)
{
  idLib::Warning(fmt: "VOICE ERROR!!!", __formal, a3);
}


// ========================================================================
// ?OnBufferEnd@StreamingVoiceContext@@UAAXPAX@Z
// EA  : 0x829A0E18
// RVA : 0x009A0E18
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall StreamingVoiceContext::OnBufferEnd(
        StreamingVoiceContext *this,
        idMapChangeListener *pContext,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapChangeListener *a14)
{
  if ( pContext != nullptr )
    idSoundSystemLocal::ReleaseStreamBufferContext(
      this: &soundSystemLocal,
      bufferContext: pContext,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14);
}


// ========================================================================
// ?DestroyInternal@idSoundVoice_XAudio2@@AAAXXZ
// EA  : 0x829A0E30
// RVA : 0x009A0E30
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::DestroyInternal(idSoundVoice_XAudio2 *this)
{
  int v2; // r3

  if ( this->pSourceVoice != nullptr )
  {
    if ( s_debugHardware.valueInteger != 0 )
    {
      v2 = Sys_Milliseconds();
      idLib::Printf(fmt: "%p %d: destroyed\n", this->pSourceVoice, v2);
    }
    this->pSourceVoice->DestroyVoice(this: this->pSourceVoice);
    this->pSourceVoice = nullptr;
    this->hasVUMeter = false;
    this->hasReverb = false;
  }
}


// ========================================================================
// ?RestartAt@idSoundVoice_XAudio2@@AAAHH@Z
// EA  : 0x829A0EB8
// RVA : 0x009A0EB8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

int __fastcall idSoundVoice_XAudio2::RestartAt(idSoundVoice_XAudio2 *this, int offsetSamples)
{
  idSoundSample_XAudio2 *sample; // r11
  __int64 v3; // r29
  int v6; // r26
  bool v7; // r27
  int numStaticSamples; // r9
  idSoundSystemLocal::bufferContext_t *v9; // r3
  idSoundSample_XAudio2 *v11; // r11
  idSoundSystemLocal *staticBuffer; // r11
  idSoundSystemLocal::bufferContext_t *v13; // r3
  IXAudio2SourceVoice *pSourceVoice; // r7
  idSoundSample_XAudio2 *v15; // r8
  int v16; // r6
  int *xma2SeekTable; // r8
  int v18; // r9
  int v19; // r10
  unsigned int bytesPerBlock; // r10
  unsigned int staticBufferSize; // r8
  unsigned int streamBlockSize; // r7
  signed int v23; // r4
  unsigned int v24; // r10
  int streamedLength; // r10
  signed int v26; // r7
  int v27; // r8
  signed int v28; // r10
  int numStreamSamples; // r8
  unsigned int v30; // r3
  int v31; // r11
  idSoundSample_XAudio2 *v32; // r11
  int v33; // r10
  __int64 v34; // [sp+50h] [-60h] BYREF
  idSoundSystemLocal *v35; // [sp+58h] [-58h]
  unsigned int v36; // [sp+5Ch] [-54h]
  __int64 v37; // [sp+60h] [-50h]
  __int64 v38; // [sp+68h] [-48h]
  idSoundSystemLocal::bufferContext_t *v39; // [sp+70h] [-40h]

  sample = this->sample;
  LODWORD(v3) = 0;
  v6 = 0;
  v7 = (this->startFlags & 0x200) != 0;
  numStaticSamples = sample->numStaticSamples;
  if ( offsetSamples >= numStaticSamples )
  {
    xma2SeekTable = sample->xma2SeekTable;
    if ( xma2SeekTable != nullptr )
    {
      v18 = 0;
      if ( sample->format.extra.xma2.blockCount != 0 )
      {
        v19 = 0;
        do
        {
          if ( xma2SeekTable[v19] > offsetSamples )
            break;
          ++v18;
          ++v19;
        }
        while ( v18 < this->sample->format.extra.xma2.blockCount );
      }
      bytesPerBlock = sample->format.extra.xma2.bytesPerBlock;
      staticBufferSize = sample->staticBufferSize;
      streamBlockSize = sample->streamBlockSize;
      __twllei(bytesPerBlock, 0);
      v23 = v18 - staticBufferSize / bytesPerBlock;
      __twllei(bytesPerBlock, 0);
      __twllei(streamBlockSize / bytesPerBlock, 0);
      this->currentStreamBlock = v23 / (int)(streamBlockSize / bytesPerBlock);
      v24 = (streamBlockSize / bytesPerBlock) & ~(__ROL4__(v23, 1) - 1);
    }
    else
    {
      streamedLength = sample->streamedLength;
      v26 = sample->streamBlockSize;
      v27 = __ROL4__(streamedLength, 1);
      v28 = streamedLength / v26;
      __twllei(v26, 0);
      __twlgei(v26 & ~(v27 - 1), 0xFFFFFFFF);
      if ( v28 <= 0 )
        v28 = 1;
      numStreamSamples = sample->numStreamSamples;
      __twllei(v28, 0);
      v30 = v28 & ~(__ROL4__(numStreamSamples, 1) - 1);
      v31 = (offsetSamples - numStaticSamples) / (numStreamSamples / v28);
      __twllei(numStreamSamples / v28, 0);
      v24 = (numStreamSamples / v28) & ~(__ROL4__(offsetSamples - numStaticSamples, 1) - 1);
      this->currentStreamBlock = v31;
      __twlgei(v30, 0xFFFFFFFF);
    }
    __twlgei(v24, 0xFFFFFFFF);
  }
  else
  {
    HIDWORD(v3) = &soundSystemLocal;
    v9 = idSoundSystemLocal::ObtainStreamBufferContext(this: &soundSystemLocal);
    if ( v9 == nullptr )
    {
LABEL_3:
      if ( s_debugStreaming.valueInteger != 0 )
        idLib::Warning(fmt: "No Sound buffer Contexts!  AKA No Sound Buffer!");
      return 0;
    }
    v9->voice = this;
    v9->sampleRate = this->sample->format.basic.samplesPerSec;
    v11 = this->sample;
    v34 = v3;
    v35 = &soundSystemLocal;
    v37 = v3;
    v38 = v3;
    v39 = nullptr;
    v36 = offsetSamples & 0xFFFFFF80;
    HIDWORD(v37) = (v11->numStaticSamples - offsetSamples) & 0xFFFFFF80;
    LODWORD(v37) = 0;
    v38 = 0;
    if ( v11->streamedLength == 0 )
      HIDWORD(v34) = 64;
    LODWORD(v34) = v11->staticBufferSize;
    staticBuffer = (idSoundSystemLocal *)v11->staticBuffer;
    v39 = v9;
    v35 = staticBuffer;
    if ( staticBuffer != nullptr )
    {
      this->pSourceVoice->SubmitSourceBuffer(this: this->pSourceVoice, a2: (const XAUDIO2_BUFFER *)&v34, a3: nullptr);
      v6 = v34;
      if ( this->sample->streamedLength == 0 && v7 )
      {
        v13 = idSoundSystemLocal::ObtainStreamBufferContext(this: &soundSystemLocal);
        if ( v13 == nullptr )
          goto LABEL_3;
        v13->voice = this;
        v13->sampleRate = this->sample->format.basic.samplesPerSec;
        pSourceVoice = this->pSourceVoice;
        v15 = this->sample;
        v36 = v15->loopBegin & 0xFFFFFF80;
        HIDWORD(v37) = (v15->numStaticSamples - v15->loopBegin) & 0xFFFFFF80;
        LODWORD(v37) = v15->loopBegin & 0xFFFFFF80;
        v16 = v15->loopEnd - v15->loopBegin;
        v39 = v13;
        LODWORD(v38) = 255;
        HIDWORD(v38) = v16 & 0xFFFFFF80;
        pSourceVoice->SubmitSourceBuffer(this: pSourceVoice, a2: (const XAUDIO2_BUFFER *)&v34, a3: nullptr);
        v6 += v34;
      }
    }
    this->currentStreamBlock = 0;
  }
  this->currentStreamRemaining = 0;
  v32 = this->sample;
  v33 = v32->streamedLength;
  if ( v33 != 0 )
    this->currentStreamRemaining = v33 - v32->streamBlockSize * this->currentStreamBlock;
  return v6;
}


// ========================================================================
// ?Pause@idSoundVoice_XAudio2@@QAAXXZ
// EA  : 0x829A11A8
// RVA : 0x009A11A8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::Pause(idSoundVoice_XAudio2 *this)
{
  idSoundSample_XAudio2 *sample; // r11
  const char *str; // r31
  int v4; // r3

  if ( this->pSourceVoice != nullptr && !this->paused )
  {
    if ( s_debugHardware.valueInteger != 0 )
    {
      sample = this->sample;
      if ( sample != nullptr )
        str = sample->name.str;
      else
        str = "<null>";
      v4 = Sys_Milliseconds();
      idLib::Printf(fmt: "%p %d: pausing %s\n", this->pSourceVoice, v4, str);
    }
    this->pSourceVoice->Stop(this: this->pSourceVoice, a2: 0, a3: 1u);
    this->paused = true;
  }
}


// ========================================================================
// ?UnPause@idSoundVoice_XAudio2@@QAAXXZ
// EA  : 0x829A1260
// RVA : 0x009A1260
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::UnPause(idSoundVoice_XAudio2 *this)
{
  idSoundSample_XAudio2 *sample; // r11
  const char *str; // r31
  int v4; // r3

  if ( this->pSourceVoice != nullptr && this->paused )
  {
    if ( s_debugHardware.valueInteger != 0 )
    {
      sample = this->sample;
      if ( sample != nullptr )
        str = sample->name.str;
      else
        str = "<null>";
      v4 = Sys_Milliseconds();
      idLib::Printf(fmt: "%p %d: unpausing %s\n", this->pSourceVoice, v4, str);
    }
    this->pSourceVoice->Start(this: this->pSourceVoice, a2: 0, a3: 1u);
    this->paused = false;
  }
}


// ========================================================================
// ?Stop@idSoundVoice_XAudio2@@QAAXXZ
// EA  : 0x829A1318
// RVA : 0x009A1318
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::Stop(idSoundVoice_XAudio2 *this)
{
  idSoundSample_XAudio2 *sample; // r11
  const char *str; // r30
  int v4; // r3

  if ( this->pSourceVoice != nullptr )
  {
    if ( !this->paused )
    {
      if ( s_debugHardware.valueInteger != 0 )
      {
        sample = this->sample;
        if ( sample != nullptr )
          str = sample->name.str;
        else
          str = "<null>";
        v4 = Sys_Milliseconds();
        idLib::Printf(fmt: "%p %d: stopping %s\n", this->pSourceVoice, v4, str);
      }
      this->pSourceVoice->Stop(this: this->pSourceVoice, a2: 0, a3: 1u);
      this->paused = true;
    }
    this->currentStreamRemaining = 0;
    this->currentStreamBlock = 0;
  }
}


// ========================================================================
// ?GetAmplitude@idSoundVoice_XAudio2@@QAAMXZ
// EA  : 0x829A13E0
// RVA : 0x009A13E0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

float __fastcall idSoundVoice_XAudio2::GetAmplitude(idSoundVoice_XAudio2 *this)
{
  double v1; // fp1
  unsigned int numChannels; // r11
  __int64 v3; // r11
  double v4; // fp0
  float *v5; // r11
  int i; // ctr
  _DWORD v8[2]; // [sp+50h] [-60h] BYREF
  int v9; // [sp+58h] [-58h]
  char v10; // [sp+5Ch] [-54h] BYREF
  float v11; // [sp+60h] [-50h] BYREF
  char v12; // [sp+80h] [-30h] BYREF

  if ( !this->hasVUMeter )
    goto LABEL_2;
  numChannels = this->sample->format.basic.numChannels;
  v8[0] = &v12;
  v8[1] = &v11;
  v9 = numChannels;
  if ( numChannels > 8 )
    v9 = 8;
  if ( this->pSourceVoice->GetEffectParameters(this: this->pSourceVoice, a2: 0, a3: v8, a4: 12u) != 0 )
  {
LABEL_2:
    v1 = 0.0;
  }
  else
  {
    HIDWORD(v3) = v9;
    if ( v9 == 1 )
    {
      v1 = v11;
    }
    else
    {
      v4 = 0.0;
      if ( v9 != 0 )
      {
        v5 = (float *)&v10;
        for ( i = v9; i != 0; --i )
          v4 = (float)(*++v5 + (float)v4);
      }
      LODWORD(v3) = v9;
      v1 = (float)((float)v4 / (float)v3);
    }
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?OnBufferStart@StreamingVoiceContext@@UAAXPAX@Z
// EA  : 0x829A14D0
// RVA : 0x009A14D0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall StreamingVoiceContext::OnBufferStart(StreamingVoiceContext *this, _DWORD *pContext)
{
  int v2; // r11
  int v3; // r3
  char v4; // r10
  double v5; // fp1
  double v6; // fp0

  v2 = *pContext;
  v3 = *(_DWORD *)(*pContext + 156);
  if ( v3 == 0 || (v4 = 1, *(_DWORD *)(v2 + 160) == 0) )
    v4 = 0;
  if ( v4 != 0 )
  {
    v5 = *(float *)(v2 + 116);
    *(_DWORD *)(v2 + 328) = pContext[2];
    v6 = 0.0009765625;
    if ( v5 < 0.0009765625 || (v6 = 1024.0, v5 > 1024.0) )
      v5 = v6;
    (*(void (__fastcall **)(int, double))(*(_DWORD *)v3 + 104))(a1: v3, a2: v5);
  }
}


// ========================================================================
// ?Update@idSoundVoice_XAudio2@@QAA_NXZ
// EA  : 0x829A1548
// RVA : 0x009A1548
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idSoundVoice_XAudio2::Update(idSoundVoice_XAudio2 *this)
{
  IXAudio2SourceVoice *pSourceVoice; // r3
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  volatile int currentStreamRemaining; // r9
  int j; // r28
  volatile int streamBlockSize; // r29
  idSoundSystemLocal::bufferContext_t *v10; // r3
  idMapChangeListener *v11; // r30
  __int64 v12; // r6
  idSoundSample_XAudio2 *sample; // r7
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  unsigned int CachedData; // r3
  float *v21; // r11
  int k; // ctr
  volatile int v23; // r10
  IXAudio2SourceVoice *v24; // r3
  int v25; // r8
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r6
  int v30; // r5
  volatile int v31; // r11
  int startFlags; // r11
  idSoundSample *v33; // r3
  volatile int v34; // r11
  __int64 v35; // r6
  int v36; // r9
  idFile *v37; // r4
  int v39; // r10
  int i; // r30
  idSoundSample *v41; // r3
  idSoundSample_XAudio2 *v42; // r11
  int numChannels; // r30
  unsigned int channelMask; // r29
  int v45; // r7
  double v46; // fp1
  __int64 v47; // r11
  long double v48; // fp2
  idSoundSample_XAudio2 *v49; // r5
  unsigned int samplesPerSec; // r3 OVERLAPPED
  long double v53; // fp2
  double v54; // fp0
  IXAudio2SourceVoice *v55; // r3
  char v56; // r11
  double pitch; // fp1
  double v58; // fp0
  const char *v59; // [sp+8h] [-238h]
  pfcRequest_t v60; // [sp+Ch] [-234h]
  int v61; // [sp+10h] [-230h]
  int v62; // [sp+14h] [-22Ch]
  int v63; // [sp+18h] [-228h]
  idMapChangeListener *v64; // [sp+1Ch] [-224h]
  float v65; // [sp+60h] [-1E0h]
  float v66[6]; // [sp+68h] [-1D8h] BYREF
  float v67; // [sp+80h] [-1C0h] BYREF
  _DWORD v68[11]; // [sp+84h] [-1BCh] BYREF
  char v69; // [sp+B0h] [-190h] BYREF
  int v70; // [sp+B4h] [-18Ch]
  float v71[66]; // [sp+C0h] [-180h] BYREF

  pSourceVoice = this->pSourceVoice;
  if ( pSourceVoice == nullptr || this->sample == nullptr )
    return 0;
  pSourceVoice->GetState(this: pSourceVoice, a2: (XAUDIO2_VOICE_STATE *)&v69, a3: 256u);
  currentStreamRemaining = this->currentStreamRemaining;
  if ( currentStreamRemaining <= 0 )
  {
    v39 = this->startFlags & 0x100000;
    if ( v39 != 0 )
    {
      for ( i = v70; i < MIN_BUFFER_SUBMITTED; ++i )
      {
        v41 = idSoundVoice_Base::SelectSample(
                this,
                previousSample: (idMapChangeListener *)this->sample,
                a3: v6,
                a4: v5,
                a5: v4,
                a6: v3,
                a7: currentStreamRemaining,
                a8: v39,
                a9: (int)v59,
                a10: v60,
                a11: v61,
                a12: v62,
                a13: v63,
                a14: v64);
        this->sample = v41;
        if ( idSoundVoice_XAudio2::RestartAt(this, offsetSamples: v41->loopBegin) == 0 )
          break;
      }
    }
  }
  else
  {
    for ( j = v70; j < 3; ++j )
    {
      streamBlockSize = this->sample->streamBlockSize;
      if ( this->currentStreamRemaining < streamBlockSize )
        streamBlockSize = this->currentStreamRemaining;
      if ( streamBlockSize == 0 )
        break;
      v10 = idSoundSystemLocal::ObtainStreamBufferContext(this: &soundSystemLocal);
      v11 = (idMapChangeListener *)v10;
      if ( v10 == nullptr )
      {
        if ( s_debugStreaming.valueInteger == 0 )
          goto LABEL_30;
        idLib::Warning(fmt: "No Sound buffer Contexts!  AKA No Sound Buffer!");
        break;
      }
      v10->voice = this;
      LODWORD(v12) = streamBlockSize;
      v10->sampleRate = this->sample->format.basic.samplesPerSec;
      sample = this->sample;
      HIDWORD(v12) = sample->streamBlockSize * this->currentStreamBlock + sample->streamedOffset;
      CachedData = idStreamFileCache::ReadCachedData(
                     this: streamFileCache,
                     cacheFile: sample->streamFile,
                     ofs: v12,
                     length: (unsigned __int8 *)v10->buffer,
                     dest: (this->startFlags & 0x400000) != 0,
                     blockingRead: nullptr,
                     priority: nullptr,
                     persistence: (int)v59,
                     pfc: v60);
      if ( CachedData != streamBlockSize )
      {
        if ( CachedData != 0 )
          idLib::Warning(fmt: "Sound read failure: %i != %i!", CachedData, streamBlockSize);
        idSoundSystemLocal::ReleaseStreamBufferContext(
          this: &soundSystemLocal,
          bufferContext: v11,
          a3: v19,
          a4: v18,
          a5: v17,
          a6: v16,
          a7: v15,
          a8: v14,
          a9: (int)v59,
          a10: v60,
          a11: v61,
          a12: v62,
          a13: v63,
          a14: v64);
        break;
      }
      if ( s_debugStreaming.valueInteger != 0 )
        idLib::Printf(
          fmt: "voice 0x%08x : queued %i = block %3i, buffer 0x%08x, %8i remaining, read 0x%x bytes from offset 0x%08x : %s\n",
          this,
          j,
          this->currentStreamBlock,
          v11[1].__vftable,
          this->currentStreamRemaining,
          streamBlockSize,
          this->sample->streamBlockSize * this->currentStreamBlock,
          v59);
      v21 = &v67;
      v67 = 0.0;
      for ( k = 8; k != 0; --k )
        *++v21 = 0.0;
      v23 = this->currentStreamRemaining;
      v24 = this->pSourceVoice;
      v25 = this->sample->streamBlockSize;
      v68[0] = streamBlockSize;
      LODWORD(v67) = __CFADD__(v25 - v23, v23 ^ 0x80000000) ? 0 : 0x40;
      v68[1] = v11[1].__vftable;
      v68[7] = v11;
      v24->SubmitSourceBuffer(this: v24, a2: (const XAUDIO2_BUFFER *)&v67, a3: nullptr);
      v30 = this->currentStreamBlock + 1;
      this->currentStreamRemaining -= streamBlockSize;
      v31 = this->currentStreamRemaining;
      this->currentStreamBlock = v30;
      if ( v31 <= 0 )
      {
        startFlags = this->startFlags;
        if ( (startFlags & 0x100000) != 0 )
        {
          v33 = idSoundVoice_Base::SelectSample(
                  this,
                  previousSample: (idMapChangeListener *)this->sample,
                  a3: v30,
                  a4: v29,
                  a5: v28,
                  a6: v27,
                  a7: v26,
                  a8: startFlags & 0x100000,
                  a9: (int)v59,
                  a10: v60,
                  a11: v61,
                  a12: v62,
                  a13: v63,
                  a14: v64);
          this->sample = v33;
          idSoundVoice_XAudio2::RestartAt(this, offsetSamples: v33->loopBegin);
        }
        else if ( (startFlags & 0x200) != 0 )
        {
          idSoundVoice_XAudio2::RestartAt(this, offsetSamples: this->sample->loopBegin);
        }
        else
        {
          this->currentStreamRemaining = 0;
        }
      }
    }
    if ( s_debugStreaming.valueInteger != 0 && j == 0 )
      idLib::Printf(
        fmt: "voice 0x%08x : No buffers at block %i for sound %s\n",
        this,
        this->currentStreamBlock,
        this->sample->name.str);
LABEL_30:
    v34 = this->currentStreamRemaining;
    LODWORD(v35) = 0x20000;
    if ( v34 >= 0x20000 || (LODWORD(v35) = this->currentStreamRemaining, v34 != 0) )
    {
      if ( j > 1 )
        v36 = (__CFADD__(4 * (3 - j), 0x80000000) ? 0 : 4 * (3 - j)) << 15;
      else
        v36 = 1015808;
      HIDWORD(v35) = this->sample;
      v37 = *(idFile **)(HIDWORD(v35) + 88);
      HIDWORD(v35) = *(_DWORD *)(HIDWORD(v35) + 76) * this->currentStreamBlock + *(_DWORD *)(HIDWORD(v35) + 84);
      idStreamFileCache::ReadCachedData(
        this: streamFileCache,
        cacheFile: v37,
        ofs: v35,
        length: nullptr,
        dest: 0,
        blockingRead: (idStreamControlThread_vtbl *)v36,
        priority: (idStreamControlThread_vtbl *)(64 << (2 * (j + 1))),
        persistence: (int)v59,
        pfc: v60);
    }
    if ( j == 0 )
      return 1;
  }
  v42 = this->sample;
  numChannels = v42->format.basic.numChannels;
  channelMask = v42->channelMask;
  v71[0] = 0.0;
  memset(Dst: &v71[1], Val: 0, Size: 0xFCu);
  if ( this->hasReverb )
    v46 = (float)(this->dryGain * soundSystemLocal.hardware.dryGain);
  else
    v46 = 1.0;
  idSoundVoice_Base::CalculateSurround(
    this,
    srcChannels: numChannels,
    srcMask: channelMask,
    pLevelMatrix: v71,
    scale: v46,
    startFlags: v45,
    a7: this->startFlags);
  if ( s_skipHardwareSets.valueInteger != 0 )
    return 1;
  this->pSourceVoice->SetOutputMatrix(
    this: this->pSourceVoice,
    a2: soundSystemLocal.hardware.pMasterVoice,
    a3: numChannels,
    a4: idSoundVoice_Base::dstChannels,
    a5: v71,
    a6: 1u);
  if ( this->hasReverb )
  {
    LODWORD(v47) = numChannels;
    if ( numChannels > 0 )
    {
      v67 = this->wetGain / (float)v47;
      blkmov(a1: v68, a2: &v67, a3: (4 * numChannels - 1) & 0xFFFFFFFC);
    }
    this->pSourceVoice->SetOutputMatrix(
      this: this->pSourceVoice,
      a2: soundSystemLocal.hardware.pSubmixVoice,
      a3: numChannels,
      a4: 1u,
      a5: &v67,
      a6: 1u);
  }
  ((void (__fastcall *)(IXAudio2SourceVoice *, double))this->pSourceVoice->SetVolume)(
    a1: this->pSourceVoice,
    a2: this->gain);
  v49 = this->sample;
  v66[0] = 0.0;
  _FP10 = (float)((float)0.0099999998 - this->occlusion);
  __asm { fsel      f9, f10, f0, f11 }
  v66[2] = 1.0;
  samplesPerSec = v49->format.basic.samplesPerSec;
  if ( (float)((float)((float)1000.0 / (float)_FP9) * (float)6.0) >= (double)(float)*(__int64 *)&samplesPerSec
    || s_lowPassFilter.valueInteger == 0 )
  {
    goto LABEL_55;
  }
  *(double *)&v48 = (float)((float)((float)((float)1000.0 / (float)_FP9) * (float)3.1415927)
                          / (float)*(__int64 *)&samplesPerSec);
  v53 = sin(x: v48);
  v54 = (float)((float)*(double *)&v53 * (float)2.0);
  if ( v54 < 0.0 )
  {
    v54 = 0.0;
    goto LABEL_56;
  }
  if ( v54 > 1.0 )
LABEL_55:
    v54 = 1.0;
LABEL_56:
  v65 = v54;
  v66[1] = v65;
  this->pSourceVoice->SetFilterParameters(this: this->pSourceVoice, a2: (const XAUDIO2_FILTER_PARAMETERS *)v66, a3: 1u);
  v55 = this->pSourceVoice;
  if ( v55 == nullptr || (v56 = 1, this->sample == nullptr) )
    v56 = 0;
  if ( v56 != 0 )
  {
    pitch = this->pitch;
    v58 = 0.0009765625;
    if ( pitch < 0.0009765625 || (v58 = 1024.0, pitch > 1024.0) )
      pitch = v58;
    ((void (__fastcall *)(IXAudio2SourceVoice *, double))v55->SetFrequencyRatio)(a1: v55, a2: pitch);
  }
  return 1;
}


// ========================================================================
// ??1idSoundVoice_XAudio2@@QAA@XZ
// EA  : 0x829A1BD0
// RVA : 0x009A1BD0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::~idSoundVoice_XAudio2(idSoundVoice_XAudio2 *this)
{
  idSoundVoice_XAudio2::DestroyInternal(this);
  `eh vector destructor iterator'(
    ptr: this->pins,
    size: 0x30u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->samples);
}


// ========================================================================
// __unwind$224667
// EA  : 0x829A1C2C
// RVA : 0x009A1C2C
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void _unwind_224667()
{
  int v0; // r12

  idSoundVoice_Base::~idSoundVoice_Base(this: *(idSoundVoice_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$224668
// EA  : 0x829A1C54
// RVA : 0x009A1C54
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void _unwind_224668()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 168),
    size: 0x30u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
}


// ========================================================================
// ?Create@idSoundVoice_XAudio2@@QAAXPBVidSoundSample@@ABV?$idList@PAVidSoundSample@@$04@@@Z
// EA  : 0x829A1C90
// RVA : 0x009A1C90
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::Create(
        idSoundVoice_XAudio2 *this,
        const idSoundSample *firstSample,
        const idList<idMD6Node *,5> *samplesList)
{
  IXAudio2SourceVoice *pSourceVoice; // r11
  const void **p_pSourceVoice; // r30
  idSoundSample_XAudio2 *sample; // r11
  idSoundSample_XAudio2 *v9; // r11
  const char *str; // r29
  int v11; // r3
  const void *v12; // r3
  idSoundSample_XAudio2 *v13; // r10
  int streamedLength; // r6
  volatile int v15; // r10

  if ( idSoundVoice_XAudio2::IsPlaying(this) )
  {
    idSoundVoice_XAudio2::Stop(this);
    return;
  }
  idList<idMaterial const *,59>::operator=(this: (idList<idMD6Node *,5> *)&this->samples, other: samplesList);
  pSourceVoice = this->pSourceVoice;
  p_pSourceVoice = (const void **)&this->pSourceVoice;
  this->sample = &firstSample->idSoundSample_XAudio2;
  if ( pSourceVoice != nullptr && idSoundVoice_XAudio2::CompatibleFormat(this, s: &firstSample->idSoundSample_XAudio2) )
  {
    this->sampleRate = firstSample->format.basic.samplesPerSec;
  }
  else
  {
    idSoundVoice_XAudio2::DestroyInternal(this);
    sample = this->sample;
    this->formatTag = sample->format.basic.formatTag;
    this->numChannels = sample->format.basic.numChannels;
    this->sampleRate = sample->format.basic.samplesPerSec;
    this->bitsPerSample = sample->format.basic.bitsPerSample;
    ((void (__fastcall *)(IXAudio2 *, IXAudio2SourceVoice **, idWaveFile::waveFmt_t *, int, double))soundSystemLocal.hardware.pXAudio2->CreateSourceVoice)(
      a1: soundSystemLocal.hardware.pXAudio2,
      a2: &this->pSourceVoice,
      a3: &sample->format,
      a4: 8,
      a5: 4.0);
    if ( *p_pSourceVoice == nullptr )
      return;
    if ( s_debugHardware.valueInteger != 0 )
    {
      v9 = this->sample;
      if ( v9 != nullptr )
        str = v9->name.str;
      else
        str = "<null>";
      v11 = Sys_Milliseconds();
      idLib::Printf(fmt: "%p %d: created for %s\n", *p_pSourceVoice, v11, str);
    }
  }
  v12 = *p_pSourceVoice;
  this->sourceVoiceRate = this->sampleRate;
  (*(void (__fastcall **)(const void *))(*(_DWORD *)v12 + 112))(a1: v12);
  (*(void (__fastcall **)(const void *, double))(*(_DWORD *)*p_pSourceVoice + 48))(a1: *p_pSourceVoice, a2: 0.0);
  v13 = this->sample;
  streamedLength = v13->streamedLength;
  this->currentStreamBlock = 0;
  if ( streamedLength != 0 )
  {
    v15 = v13->streamedLength;
    this->readPin = 0;
    this->currentStreamRemaining = v15;
  }
  else
  {
    this->currentStreamRemaining = 0;
  }
}


// ========================================================================
// ?Start@idSoundVoice_XAudio2@@QAAXHH@Z
// EA  : 0x829A1E48
// RVA : 0x009A1E48
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall idSoundVoice_XAudio2::Start(idSoundVoice_XAudio2 *this, int offsetMS, int ssFlags)
{
  idSoundSample_XAudio2 *sample; // r11
  const char *str; // r30
  int v8; // r3
  idSoundSample_XAudio2 *v9; // r11
  idSoundSample_XAudio2 *v10; // r11
  char v11; // r11
  char v12; // r27
  char v13; // r10
  BOOL v14; // r11
  bool v15; // r30
  idSoundSample_XAudio2 *v16; // r11
  IXAudio2SourceVoice *pSourceVoice; // r3
  IXAudio2SourceVoice *v18; // r3
  idSoundSample_XAudio2 *v19; // r11
  int loopEnd; // r9
  unsigned int v21; // r10
  int v22; // r4
  int loopBegin; // r11
  IUnknown *v24; // [sp+50h] [-60h] BYREF
  int v25; // [sp+58h] [-58h] BYREF
  int *v26; // [sp+5Ch] [-54h]
  int v27; // [sp+60h] [-50h] BYREF
  int pMasterVoice; // [sp+64h] [-4Ch]
  int numChannels; // [sp+68h] [-48h]
  IXAudio2SubmixVoice *pSubmixVoice; // [sp+6Ch] [-44h]

  if ( s_debugHardware.valueInteger != 0 )
  {
    sample = this->sample;
    if ( sample != nullptr )
      str = sample->name.str;
    else
      str = "<null>";
    v8 = Sys_Milliseconds();
    idLib::Printf(fmt: "%p %d: starting %s @ %d\n", this->pSourceVoice, v8, str, offsetMS);
  }
  v9 = this->sample;
  if ( v9 != nullptr && this->pSourceVoice != nullptr )
  {
    if ( !v9->loaded )
    {
      if ( idLib::production == PROD_LOADED )
        resourceManager->SetFileHook(this: resourceManager);
      this->sample->LoadResource(this: this->sample);
      if ( idLib::production == PROD_LOADED )
        resourceManager->ReleaseFileHook(this: resourceManager);
    }
    v10 = this->sample;
    if ( v10->timestamp == -1 )
      idLib::Warning(fmt: "Starting defaulted sound sample %s", v10->name.str);
    this->startFlags = ssFlags;
    if ( (ssFlags & 0x200) != 0 || (v11 = 0, (ssFlags & 0x100000) != 0) )
      v11 = 1;
    v12 = v11;
    if ( (ssFlags & 0x8000) != 0 || (v13 = 1, s_reverb.valueInteger == 0) )
      v13 = 0;
    v14 = (ssFlags & 0x4000) != 0;
    v15 = v13;
    if ( v14 != this->hasVUMeter )
    {
      this->hasVUMeter = v14;
      if ( (ssFlags & 0x4000) != 0 )
      {
        v24 = nullptr;
        if ( CreateAudioVolumeMeter(ppApo: &v24) == 0 )
        {
          v16 = this->sample;
          pMasterVoice = 1;
          pSourceVoice = this->pSourceVoice;
          numChannels = v16->format.basic.numChannels;
          v27 = (int)v24;
          v25 = 1;
          v26 = &v27;
          pSourceVoice->SetEffectChain(this: pSourceVoice, a2: (const XAUDIO2_EFFECT_CHAIN *)&v25);
          v24->Release(this: v24);
        }
      }
      else
      {
        this->pSourceVoice->SetEffectChain(this: this->pSourceVoice, a2: nullptr);
      }
    }
    if ( v15 != this->hasReverb )
    {
      v18 = this->pSourceVoice;
      this->hasReverb = v15;
      if ( v15 )
      {
        v27 = 128;
        numChannels = 128;
        v26 = &v27;
        v25 = 2;
        pMasterVoice = (int)soundSystemLocal.hardware.pMasterVoice;
        pSubmixVoice = soundSystemLocal.hardware.pSubmixVoice;
      }
      else
      {
        v25 = 1;
        v27 = 128;
        v26 = &v27;
        pMasterVoice = (int)soundSystemLocal.hardware.pMasterVoice;
      }
      v18->SetOutputVoices(this: v18, a2: (const XAUDIO2_VOICE_SENDS *)&v25);
    }
    v19 = this->sample;
    loopEnd = v19->loopEnd;
    v21 = v19->format.basic.samplesPerSec / 0x64 * offsetMS / 0xA + v19->firstValidSample;
    v22 = v21 - (v21 & 0x7F);
    if ( v22 < loopEnd )
      goto LABEL_35;
    if ( v12 != 0 && loopEnd > 0 )
    {
      loopBegin = v19->loopBegin;
      __twllei(loopEnd - loopBegin, 0);
      __twlgei((loopEnd - loopBegin) & ~(__ROL4__(v22 - loopBegin, 1) - 1), 0xFFFFFFFF);
      v22 = (v22 - loopBegin) % (loopEnd - loopBegin) + loopBegin;
LABEL_35:
      idSoundVoice_XAudio2::RestartAt(this, offsetSamples: v22);
      idSoundVoice_XAudio2::Update(this);
      idSoundVoice_XAudio2::UnPause(this);
    }
  }
}


// ========================================================================
// ??0idSoundVoice_XAudio2@@QAA@XZ
// EA  : 0x829A2188
// RVA : 0x009A2188
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

idSoundVoice_XAudio2 *__fastcall idSoundVoice_XAudio2::idSoundVoice_XAudio2(idSoundVoice_XAudio2 *this)
{
  idSoundVoice_Base::idSoundVoice_Base(this);
  this->pSourceVoice = nullptr;
  this->sample = nullptr;
  `eh vector constructor iterator'(
    ptr: this->pins,
    size: 0x30u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))pinnedCacheLines_t::pinnedCacheLines_t,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  this->readPin = 0;
  this->paused = true;
  this->formatTag = 0;
  this->numChannels = 0;
  this->sourceVoiceRate = 0;
  this->sampleRate = 0;
  this->bitsPerSample = 0;
  this->currentStreamBlock = 0;
  this->currentStreamRemaining = 0;
  this->hasVUMeter = false;
  this->hasReverb = false;
  this->startFlags = 0;
  return this;
}


// ========================================================================
// __unwind$224790
// EA  : 0x829A2210
// RVA : 0x009A2210
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void _unwind_224790()
{
  int v0; // r12

  idSoundVoice_Base::~idSoundVoice_Base(this: *(idSoundVoice_Base **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 's_reverb''
// EA  : 0x833618A8
// RVA : 0x013618A8
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_reverb__()
{
  idCVar::idCVar(
    this: &s_reverb,
    name: "s_reverb",
    value: "1",
    flags: 1,
    description: "enable reverb",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_reverb__);
}


// ========================================================================
// `dynamic initializer for 's_lowPassFilter''
// EA  : 0x83361900
// RVA : 0x01361900
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_lowPassFilter__()
{
  idCVar::idCVar(
    this: &s_lowPassFilter,
    name: "s_lowPassFilter",
    value: "1",
    flags: 1,
    description: "enable low pass filter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_lowPassFilter__);
}


// ========================================================================
// `dynamic initializer for 's_skipHardwareSets''
// EA  : 0x83361958
// RVA : 0x01361958
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_skipHardwareSets__()
{
  idCVar::idCVar(
    this: &s_skipHardwareSets,
    name: "s_skipHardwareSets",
    value: "0",
    flags: 1,
    description: "Do all calculation, but skip XA2 calls",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_skipHardwareSets__);
}


// ========================================================================
// `dynamic initializer for 's_debugStreaming''
// EA  : 0x833619B0
// RVA : 0x013619B0
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_debugStreaming__()
{
  idCVar::idCVar(
    this: &s_debugStreaming,
    name: "s_debugStreaming",
    value: "0",
    flags: 1,
    description: "Show debug info for streaming",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_debugStreaming__);
}


// ========================================================================
// `dynamic initializer for 's_debugHardware''
// EA  : 0x83361A08
// RVA : 0x01361A08
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_debugHardware__()
{
  idCVar::idCVar(
    this: &s_debugHardware,
    name: "s_debugHardware",
    value: "0",
    flags: 1,
    description: "Print a message any time a hardware voice changes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_debugHardware__);
}


// ========================================================================
// `dynamic initializer for 'ONE_OVER_SYSTEM_SAMPLE_RATE''
// EA  : 0x83361A60
// RVA : 0x01361A60
// PDB : w:\tech5\engine\sound\xaudio2\xa2_soundvoice.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__ONE_OVER_SYSTEM_SAMPLE_RATE__(int a1, int a2, int a3, int a4, __int64 a5)
{
  LODWORD(a5) = SYSTEM_SAMPLE_RATE;
  ONE_OVER_SYSTEM_SAMPLE_RATE = (float)1.0 / (float)a5;
}

