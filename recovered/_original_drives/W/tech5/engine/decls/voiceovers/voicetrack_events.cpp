
// ========================================================================
// ??1idVoiceEvent@@UAA@XZ
// EA  : 0x8263C608
// RVA : 0x0063C608
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEvent::~idVoiceEvent(idVoiceEvent *this)
{
  this->__vftable = (idVoiceEvent_vtbl *)&idVoiceEvent::`vftable';
}


// ========================================================================
// ?IsWithinInterval@idVoiceEvent@@UBA_NHH@Z
// EA  : 0x8263C618
// RVA : 0x0063C618
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idVoiceEvent::IsWithinInterval(idVoiceEvent *this, int startIntervalMS, int endIntervalMS)
{
  int startMS; // r11
  int v4; // r10
  int v5; // r11

  startMS = this->startMS;
  v4 = this->durationMS + startMS;
  if ( endIntervalMS >= startMS && endIntervalMS < v4 )
    return true;
  v5 = this->startMS;
  if ( v5 <= startIntervalMS )
  {
    if ( startIntervalMS < v4 )
      return true;
    if ( v5 < startIntervalMS )
      return v4 >= startIntervalMS && v4 < endIntervalMS;
  }
  if ( v5 >= endIntervalMS )
    return v4 >= startIntervalMS && v4 < endIntervalMS;
  return true;
}


// ========================================================================
// ??0idViseme_Simple@@QAA@XZ
// EA  : 0x8263C688
// RVA : 0x0063C688
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idViseme_Simple *__fastcall idViseme_Simple::idViseme_Simple(idViseme_Simple *this)
{
  this->durationMS = 0;
  this->startMS = -1;
  this->__vftable = (idViseme_Simple_vtbl *)&idViseme_Simple::`vftable';
  this->eventType = 0;
  this->visemeType = -1;
  this->peakTimeMS = 0;
  this->peakWeight = 0;
  return this;
}


// ========================================================================
// ??8idViseme_Simple@@UBA_NABV0@@Z
// EA  : 0x8263C6C0
// RVA : 0x0063C6C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idViseme_Simple::operator==(idViseme_Simple *this, const idViseme_Simple *other)
{
  bool v2; // r11

  if ( this->eventType != other->eventType
    || this->startMS != other->startMS
    || (v2 = true, this->durationMS != other->durationMS) )
  {
    v2 = false;
  }
  if ( v2 )
    v2 = (_cntlzw(other->visemeType - this->visemeType) & 0x20) != 0;
  return v2 && this->peakTimeMS == other->peakTimeMS && (_cntlzw(other->peakWeight - this->peakWeight) & 0x20) != 0;
}


// ========================================================================
// ?GetWeight@idVoiceTextEvent@@UBAMHH@Z
// EA  : 0x8263C758
// RVA : 0x0063C758
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

float __fastcall idVoiceTextEvent::GetWeight(idVoiceMoodEvent *this, int curTimeMS, const int gameMsPerFrame)
{
  int startMS; // r11
  double v4; // fp1

  startMS = this->startMS;
  if ( curTimeMS < startMS || curTimeMS > this->durationMS + startMS )
    v4 = 0.0;
  else
    v4 = 1.0;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ??0idVoicePunctuationEvent@@QAA@XZ
// EA  : 0x8263C790
// RVA : 0x0063C790
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoicePunctuationEvent *__fastcall idVoicePunctuationEvent::idVoicePunctuationEvent(idVoicePunctuationEvent *this)
{
  this->durationMS = 0;
  this->startMS = -1;
  this->__vftable = (idVoicePunctuationEvent_vtbl *)&idVoicePunctuationEvent::`vftable';
  this->eventType = 4;
  this->punctuation = 0;
  return this;
}


// ========================================================================
// ??8idVoicePunctuationEvent@@UBA_NABV0@@Z
// EA  : 0x8263C7C0
// RVA : 0x0063C7C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idVoicePunctuationEvent::operator==(
        idVoicePunctuationEvent *this,
        const idVoicePunctuationEvent *other)
{
  char v2; // r11

  if ( this->eventType != other->eventType
    || this->startMS != other->startMS
    || (v2 = 1, this->durationMS != other->durationMS) )
  {
    v2 = 0;
  }
  return v2 != 0 && (_cntlzw((unsigned __int8)other->punctuation - (unsigned __int8)this->punctuation) & 0x20) != 0;
}


// ========================================================================
// ?GetRate@idVoiceAnimEvent@@QBAMXZ
// EA  : 0x8263C828
// RVA : 0x0063C828
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idVoiceAnimEvent::GetRate(idVoiceAnimEvent *this)
{
  int v1; // r2 OVERLAPPED
  __int64 v2; // r10
  int v3; // r3
  double v4; // fp1

  HIDWORD(v2) = this->rate;
  v3 = HIDWORD(v2) & RATE_FRACTIONAL_MASK;
  LODWORD(v2) = (HIDWORD(v2) & RATE_WHOLE_MASK) >> RATE_FRACTIONAL_BITS;
  v4 = (float)((float)((float)*(__int64 *)(&v1 - 1) * FRACTIONAL_STEP) + (float)v2);
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?SetRate@idVoiceAnimEvent@@QAAXM@Z
// EA  : 0x8263C888
// RVA : 0x0063C888
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceAnimEvent::SetRate(idVoiceAnimEvent *this, long double r)
{
  double v3; // fp31
  long double v4; // fp2
  __int64 v5; // r8

  v3 = *(double *)&r;
  v4 = floor(x: r);
  LODWORD(v5) = (int)(float)*(double *)&v4;
  this->rate = ((unsigned int)(int)(float)((float)((float)v3 - (float)v5) / FRACTIONAL_STEP) >> 16)
             | ((_WORD)v5 << RATE_FRACTIONAL_BITS);
}


// ========================================================================
// ??0idVoiceMoodEvent@@QAA@XZ
// EA  : 0x8263C918
// RVA : 0x0063C918
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceMoodEvent *__fastcall idVoiceMoodEvent::idVoiceMoodEvent(idVoiceMoodEvent *this)
{
  this->durationMS = 0;
  this->startMS = -1;
  this->__vftable = (idVoiceMoodEvent_vtbl *)&idVoiceMoodEvent::`vftable';
  this->eventType = 6;
  this->mood = MOOD_NONE;
  return this;
}


// ========================================================================
// ??8idVoiceMoodEvent@@UBA_NABV0@@Z
// EA  : 0x8263C948
// RVA : 0x0063C948
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idVoiceMoodEvent::operator==(idVoiceAnimEvent *this, const idVoiceAnimEvent *other)
{
  char v2; // r11

  if ( this->eventType != other->eventType
    || this->startMS != other->startMS
    || (v2 = 1, this->durationMS != other->durationMS) )
  {
    v2 = 0;
  }
  return v2 != 0 && (_cntlzw(other->animName.str - this->animName.str) & 0x20) != 0;
}


// ========================================================================
// ?WriteBinary@vtrEventHandle_t@@QBAXPAVidFile@@@Z
// EA  : 0x8263CB68
// RVA : 0x0063CB68
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall vtrEventHandle_t::WriteBinary(vtrEventHandle_t *this, idFile *file)
{
  file->Write(this: file, a2: this, a3: 2u);
  file->Write(this: file, a2: &this->index, a3: 2u);
}


// ========================================================================
// ?GetWeight@idViseme_Simple@@UBAMHH@Z
// EA  : 0x8263CC30
// RVA : 0x0063CC30
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idViseme_Simple::GetWeight(
        idViseme_Simple *this,
        const int curTimeMS,
        const int gameMsPerFrame,
        int a4,
        int a5,
        _BYTE a6[12])
{
  int v6; // r11
  double v7; // fp0
  int peakTimeMS; // r8
  double v9; // fp12
  double v10; // fp1

  *(_DWORD *)&a6[8] = this->peakTimeMS;
  v6 = curTimeMS - this->startMS;
  if ( v6 >= *(int *)&a6[8] )
  {
    peakTimeMS = this->peakTimeMS;
    *(_DWORD *)&a6[4] = v6 - peakTimeMS;
    v9 = (double)*(__int64 *)a6;
    *(_DWORD *)a6 = this->durationMS - peakTimeMS + vo_extraVisemeDuration.valueInteger;
    v7 = (float)((float)1.0 - (float)((float)v9 / (float)__SPAIR64__(&vo_extraVisemeDuration, *(unsigned int *)a6)));
  }
  else
  {
    *(_DWORD *)&a6[4] = curTimeMS - this->startMS;
    v7 = (float)((float)*(__int64 *)a6 / (float)*(__int64 *)&a6[4]);
  }
  *(_DWORD *)&a6[4] = this->peakWeight;
  v10 = (float)((float)((float)*(__int64 *)a6 * (float)0.0039215689) * (float)v7);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?Parse@idViseme_Simple@@UAAXPAVidVoiceTrack@@AAVidLexer@@@Z
// EA  : 0x8263CD00
// RVA : 0x0063CD00
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idViseme_Simple::Parse(idViseme_Simple *this, idVoiceTrack *track, idLexer *src)
{
  const idDeclVisemeSet *declVisemeSet; // r29
  unsigned __int8 v6; // r3
  int v7; // r3
  int v8; // r29
  char v9; // r11
  int v10; // r3
  int v11; // r29
  char v12; // r11
  unsigned __int8 v13; // r11
  idToken v14; // [sp+50h] [-80h] BYREF

  v14.len = 0;
  v14.allocedAndFlag = 20;
  v14.floatvalue = -3.4028235e38;
  v14.data = v14.baseBuffer;
  v14.baseBuffer[0] = 0;
  v14.intvalue = 0;
  memset(&v14.whiteSpaceStart_p, 0, 12);
  declVisemeSet = track->declVisemeSet;
  if ( declVisemeSet != nullptr )
  {
    idLexer::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v14);
    v6 = idDeclVisemeSet::VisemeForName(this: declVisemeSet, name: v14.data);
    this->visemeType = v6;
    if ( v6 == -1 )
    {
      idLib::Warning(fmt: "idViseme_Simple::Parse - unknown viseme type '%s'. Viseme forced to silence.", v14.data);
      this->visemeType = declVisemeSet->silenceViseme;
    }
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v14);
    idLexer::ExpectTokenString(this: src, string: "start");
    this->startMS = idLexer::ParseInt(this: src);
    idLexer::ExpectTokenString(this: src, string: "duration");
    this->durationMS = idLexer::ParseInt(this: src);
    idLexer::ExpectTokenString(this: src, string: "peakTime");
    v7 = idLexer::ParseInt(this: src);
    v8 = v7;
    if ( v7 < 0 || (v9 = 1, v7 > 0xFFFF) )
      v9 = 0;
    if ( v9 == 0 )
      idLib::Warning(fmt: "idViseme_Simple::Parse - peakTime out of range");
    if ( v8 >= 0 )
    {
      if ( v8 > 0xFFFF )
        LOWORD(v8) = -1;
    }
    else
    {
      LOWORD(v8) = 0;
    }
    this->peakTimeMS = v8;
    idLexer::ExpectTokenString(this: src, string: "peakWeight");
    v10 = idLexer::ParseInt(this: src);
    v11 = v10;
    if ( v10 < 0 || (v12 = 1, v10 > 255) )
      v12 = 0;
    if ( v12 == 0 )
      idLib::Warning(fmt: "idViseme_Simple::Parse - peakWeight out of range");
    if ( v11 >= 0 )
    {
      v13 = -1;
      if ( v11 <= 255 )
        v13 = v11;
    }
    else
    {
      v13 = 0;
    }
    this->peakWeight = v13;
    idLexer::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v14);
  }
  else
  {
    idLexer::Error(this: src, str: "idViseme_Simple::Parse - invalid viseme set.");
  }
  idStr::FreeData(this: &v14);
}


// ========================================================================
// __unwind$224140_0
// EA  : 0x8263CF08
// RVA : 0x0063CF08
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_224140_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?WriteBinary@idViseme_Simple@@UBA_NPAVidFile@@@Z
// EA  : 0x8263CF30
// RVA : 0x0063CF30
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idViseme_Simple::WriteBinary(idViseme_Simple *this, idFile *file)
{
  if ( !idVoicePunctuationEvent::WriteBinary((idVoicePunctuationEvent *)this, file) )
    return 0;
  file->Write(this: file, a2: &this->peakTimeMS, a3: 2u);
  file->Write(this: file, a2: &this->peakWeight, a3: 1u);
  return 1;
}


// ========================================================================
// ??4idViseme_Simple@@QAAAAV0@ABV0@@Z
// EA  : 0x8263CFB8
// RVA : 0x0063CFB8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idViseme_Simple *__fastcall idViseme_Simple::operator=(idViseme_Simple *this, const idViseme_Simple *other)
{
  if ( other != this )
  {
    this->eventType = other->eventType;
    this->startMS = other->startMS;
    this->durationMS = other->durationMS;
    this->visemeType = other->visemeType;
    this->peakTimeMS = other->peakTimeMS;
    this->peakWeight = other->peakWeight;
  }
  return this;
}


// ========================================================================
// ?SetWeights@idViseme_Frame@@QAAXPBEH@Z
// EA  : 0x8263CFF8
// RVA : 0x0063CFF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idViseme_Frame::SetWeights(
        idViseme_Frame *this,
        const unsigned __int8 *weights_,
        unsigned __int8 numWeights_)
{
  unsigned __int8 *v5; // r3
  int numWeights; // r9
  int v7; // r11

  this->numWeights = numWeights_;
  v5 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                            size: numWeights_,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  numWeights = this->numWeights;
  this->weights = v5;
  v7 = 0;
  if ( numWeights != 0 )
  {
    do
    {
      this->weights[v7] = weights_[v7];
      ++v7;
    }
    while ( v7 < this->numWeights );
  }
}


// ========================================================================
// ?MergeWeights@idViseme_Frame@@QAAXPBV1@H@Z
// EA  : 0x8263D088
// RVA : 0x0063D088
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idViseme_Frame::MergeWeights(
        idViseme_Frame *this,
        const idViseme_Frame *other,
        signed int gameMsPerFrame)
{
  int startMS; // r10
  int v5; // r11
  int v8; // r30
  int v9; // r11
  int v10; // r10
  int v11; // r29
  unsigned __int8 *v12; // r3
  int v13; // r10
  unsigned __int8 *v14; // r25
  int v15; // r9
  unsigned int v16; // r4
  int v17; // r10
  int v18; // r11
  int v19; // r9
  int v20; // ctr
  int v21; // r8
  unsigned __int8 *v22; // r7
  int v23; // r11
  unsigned __int8 v24; // r11
  unsigned __int8 v25; // r10
  unsigned __int8 v26; // r11

  startMS = this->startMS;
  v5 = other->startMS;
  v8 = startMS;
  if ( startMS >= v5 )
    v8 = other->startMS;
  v9 = other->durationMS + v5;
  v10 = this->durationMS + startMS;
  if ( v10 > v9 )
    v9 = v10;
  v11 = (v9 - v8) / gameMsPerFrame;
  __twllei(gameMsPerFrame, 0);
  __twlgei(gameMsPerFrame & ~(__ROL4__(v9 - v8, 1) - 1), 0xFFFFFFFF);
  v12 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                             size: v11,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v13 = this->startMS;
  v14 = v12;
  v15 = other->startMS;
  __twllei(gameMsPerFrame, 0);
  v16 = gameMsPerFrame & ~(__ROL4__(v13 - v8, 1) - 1);
  v17 = (v13 - v8) / gameMsPerFrame;
  __twlgei(v16, 0xFFFFFFFF);
  v18 = (v15 - v8) / gameMsPerFrame;
  __twllei(gameMsPerFrame, 0);
  __twlgei(gameMsPerFrame & ~(__ROL4__(v15 - v8, 1) - 1), 0xFFFFFFFF);
  if ( v11 > 0 )
  {
    v19 = -v18;
    v20 = v11;
    v21 = v18 - v17;
    v22 = &v12[v18];
    do
    {
      v23 = v21 + v19;
      if ( v21 + v19 < 0 || v23 >= this->numWeights )
        v24 = 0;
      else
        v24 = this->weights[v23];
      v25 = v24;
      if ( v19 < 0 || v19 >= other->numWeights )
        v26 = 0;
      else
        v26 = other->weights[v19];
      if ( v25 > (unsigned int)v26 )
        v26 = v25;
      v22[v19++] = v26;
      --v20;
    }
    while ( v20 != 0 );
  }
  idMem::Free(this: &mem, ptr: this->weights, align: ALIGN_16);
  this->weights = v14;
  this->numWeights = v11;
}


// ========================================================================
// ?WriteBinary@idVoiceGameEvent@@UBA_NPAVidFile@@@Z
// EA  : 0x8263D210
// RVA : 0x0063D210
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceGameEvent::WriteBinary(idVoiceGameEvent *this, idFile *file)
{
  file->Write(this: file, a2: &this->startMS, a3: 4u);
  file->Write(this: file, a2: &this->durationMS, a3: 2u);
  return 1;
}


// ========================================================================
// ?Memory@idVoiceGameEvent@@UBAIXZ
// EA  : 0x8263D280
// RVA : 0x0063D280
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceGameEvent::Memory(idVoiceGameEvent *this)
{
  return this->args.buffSize + 58;
}


// ========================================================================
// ??0idVoiceTextEvent@@QAA@XZ
// EA  : 0x8263D290
// RVA : 0x0063D290
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceTextEvent *__fastcall idVoiceTextEvent::idVoiceTextEvent(idVoiceTextEvent *this)
{
  this->durationMS = 0;
  this->__vftable = (idVoiceTextEvent_vtbl *)&idVoiceTextEvent::`vftable';
  this->startMS = -1;
  this->eventType = 3;
  this->text.allocedAndFlag = 20;
  this->text.data = this->text.baseBuffer;
  this->text.len = 0;
  this->text.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ??1idVoiceTextEvent@@UAA@XZ
// EA  : 0x8263D2F0
// RVA : 0x0063D2F0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceTextEvent::~idVoiceTextEvent(idVoiceTextEvent *this)
{
  this->__vftable = (idVoiceTextEvent_vtbl *)&idVoiceTextEvent::`vftable';
  idStr::FreeData(this: &this->text);
  this->__vftable = (idVoiceTextEvent_vtbl *)&idVoiceEvent::`vftable';
}


// ========================================================================
// __unwind$224657
// EA  : 0x8263D348
// RVA : 0x0063D348
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_224657()
{
  int v0; // r12

  idVoiceEvent::~idVoiceEvent(this: *(idVoiceEvent **)(v0 - 112 + 132));
}


// ========================================================================
// ??8idVoiceTextEvent@@UBA_NABV0@@Z
// EA  : 0x8263D370
// RVA : 0x0063D370
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idVoiceTextEvent::operator==(idVoiceTextEvent *this, const idVoiceTextEvent *other)
{
  char v2; // r11

  if ( this->eventType != other->eventType
    || this->startMS != other->startMS
    || (v2 = 1, this->durationMS != other->durationMS) )
  {
    v2 = 0;
  }
  return v2 != 0 && (_cntlzw(idStr::Cmp(s1: this->text.data, s2: other->text.data)) & 0x20) != 0;
}


// ========================================================================
// ?Write@idVoicePunctuationEvent@@UBAXPBVidVoiceTrack@@AAVidFile_String@@@Z
// EA  : 0x8263D3F8
// RVA : 0x0063D3F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoicePunctuationEvent::Write(
        idVoicePunctuationEvent *this,
        const idVoiceTrack *track,
        idFile_String *file)
{
  __int64 v3; // r10
  __int64 v5; // r8
  __int64 v7; // r6
  va *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  va *v16; // r3
  int v17; // [sp+8h] [-1068h]
  int v18; // [sp+8h] [-1068h]
  int v19; // [sp+8h] [-1068h]
  int v20; // [sp+Ch] [-1064h]
  int v21; // [sp+Ch] [-1064h]
  int v22; // [sp+Ch] [-1064h]
  int v23; // [sp+10h] [-1060h]
  int v24; // [sp+10h] [-1060h]
  int v25; // [sp+10h] [-1060h]
  int v26; // [sp+14h] [-105Ch]
  int v27; // [sp+14h] [-105Ch]
  int v28; // [sp+14h] [-105Ch]
  int v29; // [sp+18h] [-1058h]
  int v30; // [sp+18h] [-1058h]
  int v31; // [sp+18h] [-1058h]
  int v32; // [sp+1Ch] [-1054h]
  int v33; // [sp+1Ch] [-1054h]
  int v34; // [sp+1Ch] [-1054h]
  va v35; // [sp+50h] [-1020h] BYREF

  LODWORD(v3) = &consoleFont[21088];
  HIDWORD(v3) = (unsigned __int8)this->punctuation;
  HIDWORD(v5) = idVoiceEvent::voiceEventNames;
  LODWORD(v5) = &unk_821C0000;
  LODWORD(v7) = SBYTE3(v3);
  HIDWORD(v7) = *(const char **)((char *)idVoiceEvent::voiceEventNames + __ROL4__(this->eventType, 2));
  v8 = va::va(
         this: &v35,
         fmt: "\t\t%s \"%c\" {\n",
         a3: v7,
         a4: v5,
         a5: v3,
         a6: v17,
         a7: v20,
         a8: v23,
         a9: v26,
         a10: v29,
         a11: v32);
  idFile_String::operator+=(this: file, str: v8->buffer);
  HIDWORD(v9) = this->startMS;
  v12 = va::va(
          this: &v35,
          fmt: "\t\t\tstart %d\n",
          a3: v9,
          a4: v11,
          a5: v10,
          a6: v18,
          a7: v21,
          a8: v24,
          a9: v27,
          a10: v30,
          a11: v33);
  idFile_String::operator+=(this: file, str: v12->buffer);
  LODWORD(v13) = (unsigned __int16)this->durationMS;
  HIDWORD(v14) = (__int16)v13;
  v16 = va::va(
          this: &v35,
          fmt: "\t\t\tduration %d\n",
          a3: v14,
          a4: v15,
          a5: v13,
          a6: v19,
          a7: v22,
          a8: v25,
          a9: v28,
          a10: v31,
          a11: v34);
  idFile_String::operator+=(this: file, str: v16->buffer);
  idFile_String::operator+=(this: file, str: "\t\t}\n");
}


// ========================================================================
// ?Parse@idVoicePunctuationEvent@@UAAXPAVidVoiceTrack@@AAVidLexer@@@Z
// EA  : 0x8263D4C8
// RVA : 0x0063D4C8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoicePunctuationEvent::Parse(idVoicePunctuationEvent *this, idVoiceTrack *track, idLexer *src)
{
  int v5; // r6
  int v6; // [sp+50h] [-80h] BYREF
  idToken v7; // [sp+60h] [-70h] BYREF

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.floatvalue = -3.4028235e38;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
  v5 = (unsigned __int8)*v7.data;
  this->punctuation = v5;
  if ( v5 == 0 )
  {
    strncpy(dest: idException::error, source: "idVoicePunctuationEvent - NULL punctuation found", count: 0x800u);
    CxxThrowException(pExceptionObject: &v6, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
  }
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v7);
  idLexer::ExpectTokenString(this: src, string: "start");
  this->startMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenString(this: src, string: "duration");
  this->durationMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v7);
  idStr::FreeData(this: &v7);
}


// ========================================================================
// $LN26
// EA  : 0x8263D5E0
// RVA : 0x0063D5E0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _LN26()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?WriteBinary@idVoicePunctuationEvent@@UBA_NPAVidFile@@@Z
// EA  : 0x8263D608
// RVA : 0x0063D608
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoicePunctuationEvent::WriteBinary(idVoicePunctuationEvent *this, idFile *file)
{
  file->Write(this: file, a2: &this->startMS, a3: 4u);
  file->Write(this: file, a2: &this->durationMS, a3: 2u);
  file->Write(this: file, a2: &this->punctuation, a3: 1u);
  return 1;
}


// ========================================================================
// ??4idVoicePunctuationEvent@@QAAAAV0@ABV0@@Z
// EA  : 0x8263D698
// RVA : 0x0063D698
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoicePunctuationEvent *__fastcall idVoicePunctuationEvent::operator=(
        idVoicePunctuationEvent *this,
        const idVoicePunctuationEvent *other)
{
  if ( this != other )
  {
    this->eventType = other->eventType;
    this->startMS = other->startMS;
    this->durationMS = other->durationMS;
    this->punctuation = other->punctuation;
  }
  return this;
}


// ========================================================================
// ??0idVoiceAnimEvent@@QAA@XZ
// EA  : 0x8263D6C8
// RVA : 0x0063D6C8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceAnimEvent *__fastcall idVoiceAnimEvent::idVoiceAnimEvent(idVoiceAnimEvent *this, long double a2)
{
  this->durationMS = 0;
  this->__vftable = (idVoiceAnimEvent_vtbl *)&idVoiceAnimEvent::`vftable';
  this->startMS = -1;
  this->eventType = 5;
  this->animName.str = &byte_8200D768;
  this->channel = 11;
  *(double *)&a2 = 1.0;
  this->blendInDurationMS = 250;
  this->blendOutDurationMS = 250;
  this->startFrame = 0;
  this->rate = 0;
  this->looping = false;
  idVoiceAnimEvent::SetRate(this, r: a2);
  return this;
}


// ========================================================================
// ?Write@idVoiceAnimEvent@@UBAXPBVidVoiceTrack@@AAVidFile_String@@@Z
// EA  : 0x8263D750
// RVA : 0x0063D750
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceAnimEvent::Write(idVoiceAnimEvent *this, const idVoiceTrack *track, idFile_String *file)
{
  __int64 v3; // r10
  __int64 v4; // r6
  __int64 v5; // r8
  va *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r6
  __int64 v19; // r8
  va *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r6
  __int64 v23; // r8
  va *v24; // r3
  const char *FaceChannelName; // r3
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r10
  va *v29; // r3
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  __int128 v34; // r6
  __int64 v35; // r10
  __int64 v36; // r8
  va *v37; // r3
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  va *v41; // r3
  int v42; // [sp+8h] [-1078h]
  int v43; // [sp+8h] [-1078h]
  int v44; // [sp+8h] [-1078h]
  int v45; // [sp+8h] [-1078h]
  int v46; // [sp+8h] [-1078h]
  int v47; // [sp+8h] [-1078h]
  int v48; // [sp+8h] [-1078h]
  int v49; // [sp+8h] [-1078h]
  int v50; // [sp+8h] [-1078h]
  int v51; // [sp+Ch] [-1074h]
  int v52; // [sp+Ch] [-1074h]
  int v53; // [sp+Ch] [-1074h]
  int v54; // [sp+Ch] [-1074h]
  int v55; // [sp+Ch] [-1074h]
  int v56; // [sp+Ch] [-1074h]
  int v57; // [sp+Ch] [-1074h]
  int v58; // [sp+Ch] [-1074h]
  int v59; // [sp+Ch] [-1074h]
  int v60; // [sp+10h] [-1070h]
  int v61; // [sp+10h] [-1070h]
  int v62; // [sp+10h] [-1070h]
  int v63; // [sp+10h] [-1070h]
  int v64; // [sp+10h] [-1070h]
  int v65; // [sp+10h] [-1070h]
  int v66; // [sp+10h] [-1070h]
  int v67; // [sp+10h] [-1070h]
  int v68; // [sp+10h] [-1070h]
  int v69; // [sp+14h] [-106Ch]
  int v70; // [sp+14h] [-106Ch]
  int v71; // [sp+14h] [-106Ch]
  int v72; // [sp+14h] [-106Ch]
  int v73; // [sp+14h] [-106Ch]
  int v74; // [sp+14h] [-106Ch]
  int v75; // [sp+14h] [-106Ch]
  int v76; // [sp+14h] [-106Ch]
  int v77; // [sp+14h] [-106Ch]
  int v78; // [sp+18h] [-1068h]
  int v79; // [sp+18h] [-1068h]
  int v80; // [sp+18h] [-1068h]
  int v81; // [sp+18h] [-1068h]
  int v82; // [sp+18h] [-1068h]
  int v83; // [sp+18h] [-1068h]
  int v84; // [sp+18h] [-1068h]
  int v85; // [sp+18h] [-1068h]
  int v86; // [sp+18h] [-1068h]
  int v87; // [sp+1Ch] [-1064h]
  int v88; // [sp+1Ch] [-1064h]
  int v89; // [sp+1Ch] [-1064h]
  int v90; // [sp+1Ch] [-1064h]
  int v91; // [sp+1Ch] [-1064h]
  int v92; // [sp+1Ch] [-1064h]
  int v93; // [sp+1Ch] [-1064h]
  int v94; // [sp+1Ch] [-1064h]
  int v95; // [sp+1Ch] [-1064h]
  va v96; // [sp+60h] [-1020h] BYREF

  LODWORD(v3) = &consoleFont[21088];
  HIDWORD(v3) = &unk_821C0000;
  LODWORD(v4) = this->animName.str;
  LODWORD(v5) = idVoiceEvent::voiceEventNames;
  HIDWORD(v5) = __ROL4__(this->eventType, 2);
  HIDWORD(v4) = *(const char **)((char *)idVoiceEvent::voiceEventNames + HIDWORD(v5));
  v8 = va::va(
         this: &v96,
         fmt: "\t\t%s \"%s\" {\n",
         a3: v4,
         a4: v5,
         a5: v3,
         a6: v42,
         a7: v51,
         a8: v60,
         a9: v69,
         a10: v78,
         a11: v87);
  idFile_String::operator+=(this: file, str: v8->buffer);
  LODWORD(v9) = &unk_821C0000;
  HIDWORD(v9) = this->startMS;
  v12 = va::va(
          this: &v96,
          fmt: "\t\t\tstart %d\n",
          a3: v9,
          a4: v11,
          a5: v10,
          a6: v43,
          a7: v52,
          a8: v61,
          a9: v70,
          a10: v79,
          a11: v88);
  idFile_String::operator+=(this: file, str: v12->buffer);
  HIDWORD(v13) = this->durationMS;
  v16 = va::va(
          this: &v96,
          fmt: "\t\t\tduration %d\n",
          a3: v13,
          a4: v15,
          a5: v14,
          a6: v44,
          a7: v53,
          a8: v62,
          a9: v71,
          a10: v80,
          a11: v89);
  idFile_String::operator+=(this: file, str: v16->buffer);
  LODWORD(v17) = &unk_821C0000;
  HIDWORD(v18) = this->blendInDurationMS;
  v20 = va::va(
          this: &v96,
          fmt: "\t\t\tblendInDurationMS %d\n",
          a3: v18,
          a4: v19,
          a5: v17,
          a6: v45,
          a7: v54,
          a8: v63,
          a9: v72,
          a10: v81,
          a11: v90);
  idFile_String::operator+=(this: file, str: v20->buffer);
  HIDWORD(v21) = &unk_821C0000;
  HIDWORD(v22) = this->blendOutDurationMS;
  v24 = va::va(
          this: &v96,
          fmt: "\t\t\tblendOutDurationMS %d\n",
          a3: v22,
          a4: v23,
          a5: v21,
          a6: v46,
          a7: v55,
          a8: v64,
          a9: v73,
          a10: v82,
          a11: v91);
  idFile_String::operator+=(this: file, str: v24->buffer);
  FaceChannelName = idVoiceTrack::GetFaceChannelName(fc: (const faceChannel_t)this->channel);
  HIDWORD(v26) = &unk_821C0000;
  HIDWORD(v27) = FaceChannelName;
  v29 = va::va(
          this: &v96,
          fmt: "\t\t\tchannel \"%s\"\n",
          a3: v27,
          a4: v26,
          a5: v28,
          a6: v47,
          a7: v56,
          a8: v65,
          a9: v74,
          a10: v83,
          a11: v92);
  idFile_String::operator+=(this: file, str: v29->buffer);
  LODWORD(v30) = &unk_821C0000;
  HIDWORD(v30) = this->startFrame;
  v33 = va::va(
          this: &v96,
          fmt: "\t\t\tstartFrame %d\n",
          a3: v30,
          a4: v32,
          a5: v31,
          a6: v48,
          a7: v57,
          a8: v66,
          a9: v75,
          a10: v84,
          a11: v93);
  idFile_String::operator+=(this: file, str: v33->buffer);
  DWORD2(v34) = &idDeclReachIK::resourceList.hashTable[243];
  HIDWORD(v35) = this->rate;
  HIDWORD(v34) = &consoleFont[21088];
  LODWORD(v35) = RATE_WHOLE_MASK;
  LODWORD(v36) = HIDWORD(v35) & RATE_FRACTIONAL_MASK;
  HIDWORD(v36) = HIDWORD(v35) & RATE_WHOLE_MASK;
  LODWORD(v34) = HIDWORD(v35) & RATE_FRACTIONAL_MASK;
  DWORD1(v34) = (HIDWORD(v35) & RATE_WHOLE_MASK) >> RATE_FRACTIONAL_BITS;
  *(double *)((char *)&v34 + 4) = (float)((float)((float)(__int64)v34 * FRACTIONAL_STEP) + (float)*(__int64 *)&v34);
  v37 = va::va(
          this: &v96,
          fmt: (const char *)DWORD1(v34),
          a3: v34,
          a4: v36,
          a5: v35,
          a6: v49,
          a7: v58,
          a8: v67,
          a9: v76,
          a10: v85,
          a11: v94);
  idFile_String::operator+=(this: file, str: v37->buffer);
  if ( this->looping )
    HIDWORD(v40) = "1";
  else
    HIDWORD(v40) = "0";
  LODWORD(v38) = this->looping;
  v41 = va::va(
          this: &v96,
          fmt: "\t\t\tloop %s\n",
          a3: v40,
          a4: v39,
          a5: v38,
          a6: v50,
          a7: v59,
          a8: v68,
          a9: v77,
          a10: v86,
          a11: v95);
  idFile_String::operator+=(this: file, str: v41->buffer);
  idFile_String::operator+=(this: file, str: "\t\t}\n");
}


// ========================================================================
// ?Parse@idVoiceAnimEvent@@UAAXPAVidVoiceTrack@@AAVidLexer@@@Z
// EA  : 0x8263D960
// RVA : 0x0063D960
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceAnimEvent::Parse(idVoiceAnimEvent *this, idVoiceTrack *track, idLexer *src)
{
  char v3; // r30
  char *str; // r11
  int v7; // r18
  __int16 FaceChannelForName; // r3
  long double v9; // fp2
  int v10; // [sp+50h] [-D0h] BYREF
  idToken v11[2]; // [sp+60h] [-C0h] BYREF

  v3 = 0;
  v11[0].len = 0;
  v11[0].allocedAndFlag = 20;
  v11[0].floatvalue = -3.4028235e38;
  v11[0].data = v11[0].baseBuffer;
  v11[0].baseBuffer[0] = 0;
  v11[0].intvalue = 0;
  v11[0].whiteSpaceStart_p = nullptr;
  v11[0].whiteSpaceEnd_p = nullptr;
  v11[0].next = nullptr;
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: v11);
  idAtomicString::Set(this: &this->animName, str_: v11[0].data);
  str = (char *)this->animName.str;
  if ( str == &byte_8200D768 || *str == 0 )
    v3 = 1;
  if ( v3 != 0 )
  {
    strncpy(dest: idException::error, source: "idVoiceAnimEvent - empty animation name", count: 0x800u);
    CxxThrowException(pExceptionObject: &v10, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
  }
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 46, token: v11);
  v7 = -1;
  if ( !idLexer::ReadToken(this: src, token: v11) )
    goto LABEL_30;
  do
  {
    if ( v11[0].type == 5 && v11[0].subtype == 47 )
      break;
    if ( idStr::Cmp(s1: v11[0].data, s2: "start") != 0 )
    {
      if ( idStr::Cmp(s1: v11[0].data, s2: "duration") != 0 )
      {
        if ( idStr::Cmp(s1: v11[0].data, s2: "blendInDurationMS") != 0 )
        {
          if ( idStr::Cmp(s1: v11[0].data, s2: "blendOutDurationMS") != 0 )
          {
            if ( idStr::Cmp(s1: v11[0].data, s2: "channel") != 0 )
            {
              if ( idStr::Cmp(s1: v11[0].data, s2: "loop") != 0 )
              {
                if ( idStr::Cmp(s1: v11[0].data, s2: "rate") != 0 )
                {
                  if ( idStr::Cmp(s1: v11[0].data, s2: "startFrame") != 0 )
                    idLexer::Error(this: src, str: "Unknown token '%s' in anim event.", v11[0].data);
                  else
                    this->startFrame = idLexer::ParseInt(this: src);
                }
                else
                {
                  *(double *)&v9 = idLexer::ParseFloat(this: src, errorFlag: nullptr);
                  idVoiceAnimEvent::SetRate(this, r: v9);
                }
              }
              else
              {
                this->looping = idLexer::ParseBool(this: src);
              }
            }
            else
            {
              idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: v11);
              FaceChannelForName = idVoiceTrack::GetFaceChannelForName(name: v11[0].data);
              this->channel = FaceChannelForName;
              if ( FaceChannelForName == 11 )
                idLexer::Error(this: src, str: "Invalid face channel '%s'", v11[0].data);
            }
          }
          else
          {
            v7 = idLexer::ParseInt(this: src);
          }
        }
        else
        {
          this->blendInDurationMS = idLexer::ParseInt(this: src);
        }
      }
      else
      {
        this->durationMS = idLexer::ParseInt(this: src);
      }
    }
    else
    {
      this->startMS = idLexer::ParseInt(this: src);
    }
  }
  while ( idLexer::ReadToken(this: src, token: v11) );
  if ( v7 >= 0 )
    this->blendOutDurationMS = v7;
  else
LABEL_30:
    this->blendOutDurationMS = this->blendInDurationMS;
  idStr::FreeData(this: &v11[0]);
}


// ========================================================================
// $LN80
// EA  : 0x8263DC64
// RVA : 0x0063DC64
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _LN80()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ??4idVoiceAnimEvent@@QAAAAV0@ABV0@@Z
// EA  : 0x8263DC90
// RVA : 0x0063DC90
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceAnimEvent *__fastcall idVoiceAnimEvent::operator=(idVoiceAnimEvent *this, const idVoiceAnimEvent *other)
{
  if ( this != other )
  {
    this->eventType = other->eventType;
    this->startMS = other->startMS;
    this->durationMS = other->durationMS;
    this->animName.str = other->animName.str;
    this->channel = other->channel;
    this->blendInDurationMS = other->blendInDurationMS;
    this->blendOutDurationMS = other->blendOutDurationMS;
    this->startFrame = other->startFrame;
    this->rate = other->rate;
    this->looping = other->looping;
  }
  return this;
}


// ========================================================================
// ?Memory@idVoiceAnimEvent@@UBAIXZ
// EA  : 0x8263DCF0
// RVA : 0x0063DCF0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceAnimEvent::Memory(idVoiceAnimEvent *this)
{
  const char *str; // r11
  int v2; // r9

  str = this->animName.str;
  do
    v2 = *(unsigned __int8 *)str++;
  while ( v2 != 0 );
  return str - this->animName.str - 1 + 28;
}


// ========================================================================
// ?Write@idVoiceMoodEvent@@UBAXPBVidVoiceTrack@@AAVidFile_String@@@Z
// EA  : 0x8263DD20
// RVA : 0x0063DD20
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceMoodEvent::Write(idVoiceMoodEvent *this, const idVoiceTrack *track, idFile_String *file)
{
  const char *MoodName; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  int v18; // [sp+8h] [-1068h]
  int v19; // [sp+8h] [-1068h]
  int v20; // [sp+8h] [-1068h]
  int v21; // [sp+Ch] [-1064h]
  int v22; // [sp+Ch] [-1064h]
  int v23; // [sp+Ch] [-1064h]
  int v24; // [sp+10h] [-1060h]
  int v25; // [sp+10h] [-1060h]
  int v26; // [sp+10h] [-1060h]
  int v27; // [sp+14h] [-105Ch]
  int v28; // [sp+14h] [-105Ch]
  int v29; // [sp+14h] [-105Ch]
  int v30; // [sp+18h] [-1058h]
  int v31; // [sp+18h] [-1058h]
  int v32; // [sp+18h] [-1058h]
  int v33; // [sp+1Ch] [-1054h]
  int v34; // [sp+1Ch] [-1054h]
  int v35; // [sp+1Ch] [-1054h]
  va v36; // [sp+50h] [-1020h] BYREF

  MoodName = idVoiceTrack::GetMoodName(mood: this->mood);
  LODWORD(v6) = &consoleFont[21088];
  HIDWORD(v6) = &unk_821C0000;
  LODWORD(v7) = idVoiceEvent::voiceEventNames;
  HIDWORD(v7) = __ROL4__(this->eventType, 2);
  LODWORD(v8) = MoodName;
  HIDWORD(v8) = *(const char **)((char *)idVoiceEvent::voiceEventNames + HIDWORD(v7));
  v9 = va::va(
         this: &v36,
         fmt: "\t\t%s \"%s\" {\n",
         a3: v8,
         a4: v7,
         a5: v6,
         a6: v18,
         a7: v21,
         a8: v24,
         a9: v27,
         a10: v30,
         a11: v33);
  idFile_String::operator+=(this: file, str: v9->buffer);
  LODWORD(v10) = &unk_821C0000;
  HIDWORD(v10) = this->startMS;
  v13 = va::va(
          this: &v36,
          fmt: "\t\t\tstart %d\n",
          a3: v10,
          a4: v12,
          a5: v11,
          a6: v19,
          a7: v22,
          a8: v25,
          a9: v28,
          a10: v31,
          a11: v34);
  idFile_String::operator+=(this: file, str: v13->buffer);
  HIDWORD(v14) = this->durationMS;
  v17 = va::va(
          this: &v36,
          fmt: "\t\t\tduration %d\n",
          a3: v14,
          a4: v16,
          a5: v15,
          a6: v20,
          a7: v23,
          a8: v26,
          a9: v29,
          a10: v32,
          a11: v35);
  idFile_String::operator+=(this: file, str: v17->buffer);
  idFile_String::operator+=(this: file, str: "\t\t}\n");
}


// ========================================================================
// ?Parse@idVoiceMoodEvent@@UAAXPAVidVoiceTrack@@AAVidLexer@@@Z
// EA  : 0x8263DDF0
// RVA : 0x0063DDF0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceMoodEvent::Parse(idVoiceMoodEvent *this, idVoiceTrack *track, idLexer *src)
{
  mood_t MoodForName; // r3
  int v6; // [sp+50h] [-80h] BYREF
  idToken v7; // [sp+60h] [-70h] BYREF

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.floatvalue = -3.4028235e38;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v7);
  MoodForName = idVoiceTrack::GetMoodForName(name: v7.data);
  this->mood = MoodForName;
  if ( MoodForName >= MOOD_MAX )
  {
    strncpy(dest: idException::error, source: "idVoiceMoodEvent - unknown mood type", count: 0x800u);
    CxxThrowException(pExceptionObject: &v6, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidLexerException__);
  }
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v7);
  idLexer::ExpectTokenString(this: src, string: "start");
  this->startMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenString(this: src, string: "duration");
  this->durationMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v7);
  idStr::FreeData(this: &v7);
}


// ========================================================================
// $LN28
// EA  : 0x8263DF08
// RVA : 0x0063DF08
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _LN28()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?WriteBinary@idVoiceMoodEvent@@UBA_NPAVidFile@@@Z
// EA  : 0x8263DF30
// RVA : 0x0063DF30
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceMoodEvent::WriteBinary(idVoiceMoodEvent *this, idFile *file)
{
  idFile_vtbl *v4; // r6
  _BYTE v6[8]; // [sp+50h] [-20h] BYREF

  file->Write(this: file, a2: &this->startMS, a3: 4u);
  file->Write(this: file, a2: &this->durationMS, a3: 2u);
  v4 = file->__vftable;
  v6[0] = this->mood;
  v4->Write(this: file, a2: v6, a3: 1u);
  return 1;
}


// ========================================================================
// ??4idVoiceMoodEvent@@QAAAAV0@ABV0@@Z
// EA  : 0x8263DFC8
// RVA : 0x0063DFC8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceMoodEvent *__fastcall idVoiceMoodEvent::operator=(idVoiceMoodEvent *this, const idVoiceMoodEvent *other)
{
  if ( this != other )
  {
    this->eventType = other->eventType;
    this->startMS = other->startMS;
    this->durationMS = other->durationMS;
    this->mood = other->mood;
  }
  return this;
}


// ========================================================================
// ?WriteBinary@idVoiceEventManager@@QBAXPAVidFile@@@Z
// EA  : 0x8263DFF8
// RVA : 0x0063DFF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::WriteBinary(idVoiceEventManager *this, idFile *file)
{
  idFile_vtbl *v3; // r10
  int v5; // r29
  int v6; // r28
  idFile_vtbl *v7; // r10
  int v8; // r29
  int v9; // r28
  idFile_vtbl *v10; // r10
  int v11; // r29
  int v12; // r28
  idFile_vtbl *v13; // r10
  int v14; // r29
  int v15; // r28
  idFile_vtbl *v16; // r10
  int v17; // r29
  int v18; // r28
  idFile_vtbl *v19; // r10
  int v20; // r29
  int v21; // r28
  int num; // [sp+50h] [-40h] BYREF
  int v23; // [sp+54h] [-3Ch] BYREF
  int v24; // [sp+58h] [-38h] BYREF
  int v25; // [sp+5Ch] [-34h] BYREF
  int v26; // [sp+60h] [-30h] BYREF
  int v27; // [sp+64h] [-2Ch] BYREF

  v3 = file->__vftable;
  num = this->eventsVisemeSimple.num;
  v3->Write(this: file, a2: &num, a3: 4u);
  v5 = 0;
  if ( this->eventsVisemeSimple.num > 0 )
  {
    v6 = 0;
    do
    {
      this->eventsVisemeSimple.list[v6].WriteBinary(this: &this->eventsVisemeSimple.list[v6], a2: file);
      ++v5;
      ++v6;
    }
    while ( v5 < this->eventsVisemeSimple.num );
  }
  v7 = file->__vftable;
  v23 = this->eventsGame.num;
  v7->Write(this: file, a2: &v23, a3: 4u);
  v8 = 0;
  if ( this->eventsGame.num > 0 )
  {
    v9 = 0;
    do
    {
      this->eventsGame.list[v9].WriteBinary(this: &this->eventsGame.list[v9], a2: file);
      ++v8;
      ++v9;
    }
    while ( v8 < this->eventsGame.num );
  }
  v10 = file->__vftable;
  v24 = this->eventsText.num;
  v10->Write(this: file, a2: &v24, a3: 4u);
  v11 = 0;
  if ( this->eventsText.num > 0 )
  {
    v12 = 0;
    do
    {
      this->eventsText.list[v12].WriteBinary(this: &this->eventsText.list[v12], a2: file);
      ++v11;
      ++v12;
    }
    while ( v11 < this->eventsText.num );
  }
  v13 = file->__vftable;
  v25 = this->eventsPunc.num;
  v13->Write(this: file, a2: &v25, a3: 4u);
  v14 = 0;
  if ( this->eventsPunc.num > 0 )
  {
    v15 = 0;
    do
    {
      this->eventsPunc.list[v15].WriteBinary(this: &this->eventsPunc.list[v15], a2: file);
      ++v14;
      ++v15;
    }
    while ( v14 < this->eventsPunc.num );
  }
  v16 = file->__vftable;
  v26 = this->eventsAnim.num;
  v16->Write(this: file, a2: &v26, a3: 4u);
  v17 = 0;
  if ( this->eventsAnim.num > 0 )
  {
    v18 = 0;
    do
    {
      this->eventsAnim.list[v18].WriteBinary(this: &this->eventsAnim.list[v18], a2: file);
      ++v17;
      ++v18;
    }
    while ( v17 < this->eventsAnim.num );
  }
  v19 = file->__vftable;
  v27 = this->eventsMood.num;
  v19->Write(this: file, a2: &v27, a3: 4u);
  v20 = 0;
  if ( this->eventsMood.num > 0 )
  {
    v21 = 0;
    do
    {
      this->eventsMood.list[v21].WriteBinary(this: &this->eventsMood.list[v21], a2: file);
      ++v20;
      ++v21;
    }
    while ( v20 < this->eventsMood.num );
  }
}


// ========================================================================
// ?GetEvent@idVoiceEventManager@@QAAPAVidVoiceEvent@@VvtrEventHandle_t@@@Z
// EA  : 0x8263E288
// RVA : 0x0063E288
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idViseme_Simple *__fastcall idVoiceEventManager::GetEvent(idVoiceEventManager *this, const vtrEventHandle_t *handle)
{
  if ( (__int16)handle >= 0 && (unsigned int)SHIWORD(handle) <= 6 && (SHIWORD(handle) != 1 || HIWORD(handle) == 0) )
  {
    if ( SHIWORD(handle) == 2 )
    {
      if ( (__int16)handle < this->eventsGame.num )
        return (idViseme_Simple *)&this->eventsGame.list[(__int16)handle];
    }
    else if ( SHIWORD(handle) == 3 && HIWORD(handle) != 0 )
    {
      if ( (__int16)handle < this->eventsText.num )
        return (idViseme_Simple *)&this->eventsText.list[(__int16)handle];
    }
    else if ( SHIWORD(handle) == 4 && HIWORD(handle) != 0 )
    {
      if ( (__int16)handle < this->eventsPunc.num )
        return (idViseme_Simple *)&this->eventsPunc.list[(__int16)handle];
    }
    else if ( SHIWORD(handle) == 5 && HIWORD(handle) != 0 )
    {
      if ( (__int16)handle < this->eventsAnim.num )
        return (idViseme_Simple *)&this->eventsAnim.list[(__int16)handle];
    }
    else if ( HIWORD(handle) != 0 )
    {
      if ( (__int16)handle < this->eventsMood.num )
        return (idViseme_Simple *)&this->eventsMood.list[(__int16)handle];
    }
    else if ( (__int16)handle < this->eventsVisemeSimple.num )
    {
      return &this->eventsVisemeSimple.list[(__int16)handle];
    }
  }
  return nullptr;
}


// ========================================================================
// ?GetEvent@idVoiceEventManager@@QBAPBVidVoiceEvent@@VvtrEventHandle_t@@@Z
// EA  : 0x8263E390
// RVA : 0x0063E390
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

// attributes: thunk
idViseme_Simple *__fastcall idVoiceEventManager::GetEvent(idVoiceEventManager *this, const vtrEventHandle_t *handle)
{
  return ?GetEvent@idVoiceEventManager@@QAAPAVidVoiceEvent@@VvtrEventHandle_t@@@Z(this, handle);
}


// ========================================================================
// ?NumEventType@idVoiceEventManager@@QBAHW4voiceEvent_t@@@Z
// EA  : 0x8263E398
// RVA : 0x0063E398
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceEventManager::NumEventType(idVoiceEventManager *this, unsigned int type)
{
  if ( type > 6 || type == 1 )
    return 0;
  switch ( type )
  {
    case 2u:
      return this->eventsGame.num;
    case 3u:
      return this->eventsText.num;
    case 4u:
      return this->eventsPunc.num;
    case 5u:
      return this->eventsAnim.num;
    default:
      break;
  }
  if ( type != 0 )
    return this->eventsMood.num;
  return this->eventsVisemeSimple.num;
}


// ========================================================================
// ??$FindFreeIndex@VidViseme_Simple@@$0EC@@@YAHABV?$idList@VidViseme_Simple@@$0EC@@@@Z
// EA  : 0x8263E880
// RVA : 0x0063E880
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall FindFreeIndex<idViseme_Simple,66>(const idList<idViseme_Simple,66> *list)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idViseme_Simple *v4; // r8

  num = list->num;
  v2 = 0;
  if ( num <= 0 )
    return -1;
  v3 = 0;
  v4 = list->list;
  while ( v4->eventType != 7 )
  {
    ++v2;
    v4 = &list->list[++v3];
    if ( v2 >= num )
      return -1;
  }
  return v2;
}


// ========================================================================
// ??$FindFreeIndex@VidVoiceGameEvent@@$0EC@@@YAHABV?$idList@VidVoiceGameEvent@@$0EC@@@@Z
// EA  : 0x8263E8D0
// RVA : 0x0063E8D0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall FindFreeIndex<idVoiceGameEvent,66>(const idList<idVoiceGameEvent,66> *list)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idVoiceGameEvent *v4; // r8

  num = list->num;
  v2 = 0;
  if ( num <= 0 )
    return -1;
  v3 = 0;
  v4 = list->list;
  while ( v4->eventType != 7 )
  {
    ++v2;
    v4 = &list->list[++v3];
    if ( v2 >= num )
      return -1;
  }
  return v2;
}


// ========================================================================
// ??$FindFreeIndex@VidVoiceTextEvent@@$0EC@@@YAHABV?$idList@VidVoiceTextEvent@@$0EC@@@@Z
// EA  : 0x8263E920
// RVA : 0x0063E920
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall FindFreeIndex<idVoiceTextEvent,66>(const idList<idVoiceTextEvent,66> *list)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idVoiceTextEvent *v4; // r8

  num = list->num;
  v2 = 0;
  if ( num <= 0 )
    return -1;
  v3 = 0;
  v4 = list->list;
  while ( v4->eventType != 7 )
  {
    ++v2;
    v4 = &list->list[++v3];
    if ( v2 >= num )
      return -1;
  }
  return v2;
}


// ========================================================================
// ??$FindFreeIndex@VidVoiceAnimEvent@@$0EC@@@YAHABV?$idList@VidVoiceAnimEvent@@$0EC@@@@Z
// EA  : 0x8263E970
// RVA : 0x0063E970
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall FindFreeIndex<idVoiceAnimEvent,66>(const idList<idVoiceAnimEvent,66> *list)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idVoiceAnimEvent *v4; // r8

  num = list->num;
  v2 = 0;
  if ( num <= 0 )
    return -1;
  v3 = 0;
  v4 = list->list;
  while ( v4->eventType != 7 )
  {
    ++v2;
    v4 = &list->list[++v3];
    if ( v2 >= num )
      return -1;
  }
  return v2;
}


// ========================================================================
// ??$FindFreeIndex@VidVoiceMoodEvent@@$0EC@@@YAHABV?$idList@VidVoiceMoodEvent@@$0EC@@@@Z
// EA  : 0x8263E9C0
// RVA : 0x0063E9C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall FindFreeIndex<idVoiceMoodEvent,66>(const idList<idVoiceMoodEvent,66> *list)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idVoiceMoodEvent *v4; // r8

  num = list->num;
  v2 = 0;
  if ( num <= 0 )
    return -1;
  v3 = 0;
  v4 = list->list;
  while ( v4->eventType != 7 )
  {
    ++v2;
    v4 = &list->list[++v3];
    if ( v2 >= num )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?LoadBinary@vtrEventHandle_t@@QAAXPAVidFile@@@Z
// EA  : 0x8263EA10
// RVA : 0x0063EA10
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall vtrEventHandle_t::LoadBinary(vtrEventHandle_t *this, idFile *file)
{
  file->Read(this: file, a2: this, a3: 2u);
  file->Read(this: file, a2: &this->index, a3: 2u);
}


// ========================================================================
// ?LoadBinary@idVisemeEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263EA80
// RVA : 0x0063EA80
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVisemeEvent::LoadBinary(idVisemeEvent *this, idFile *file)
{
  unsigned __int8 v5[8]; // [sp+50h] [-20h] BYREF

  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  file->Read(this: file, a2: v5, a3: 1u);
  if ( v5[0] == 255 )
    return 0;
  this->visemeType = v5[0];
  return 1;
}


// ========================================================================
// ?Write@idViseme_Simple@@UBAXPBVidVoiceTrack@@AAVidFile_String@@@Z
// EA  : 0x8263EB28
// RVA : 0x0063EB28
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idViseme_Simple::Write(idViseme_Simple *this, const idVoiceTrack *track, idFile_String *file)
{
  __int64 v3; // r8
  __int64 v5; // r10
  __int64 v7; // r6
  va *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  va *v12; // r3
  __int64 v13; // r6
  __int64 v14; // r8
  __int64 v15; // r10
  va *v16; // r3
  __int64 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r8
  va *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  va *v24; // r3
  int v25; // [sp+8h] [-1068h]
  int v26; // [sp+8h] [-1068h]
  int v27; // [sp+8h] [-1068h]
  int v28; // [sp+8h] [-1068h]
  int v29; // [sp+8h] [-1068h]
  int v30; // [sp+Ch] [-1064h]
  int v31; // [sp+Ch] [-1064h]
  int v32; // [sp+Ch] [-1064h]
  int v33; // [sp+Ch] [-1064h]
  int v34; // [sp+Ch] [-1064h]
  int v35; // [sp+10h] [-1060h]
  int v36; // [sp+10h] [-1060h]
  int v37; // [sp+10h] [-1060h]
  int v38; // [sp+10h] [-1060h]
  int v39; // [sp+10h] [-1060h]
  int v40; // [sp+14h] [-105Ch]
  int v41; // [sp+14h] [-105Ch]
  int v42; // [sp+14h] [-105Ch]
  int v43; // [sp+14h] [-105Ch]
  int v44; // [sp+14h] [-105Ch]
  int v45; // [sp+18h] [-1058h]
  int v46; // [sp+18h] [-1058h]
  int v47; // [sp+18h] [-1058h]
  int v48; // [sp+18h] [-1058h]
  int v49; // [sp+18h] [-1058h]
  int v50; // [sp+1Ch] [-1054h]
  int v51; // [sp+1Ch] [-1054h]
  int v52; // [sp+1Ch] [-1054h]
  int v53; // [sp+1Ch] [-1054h]
  int v54; // [sp+1Ch] [-1054h]
  va v55; // [sp+50h] [-1020h] BYREF

  LODWORD(v3) = track->declVisemeSet;
  LODWORD(v5) = *(_DWORD *)(v3 + 88);
  HIDWORD(v5) = 4 * (this->visemeType + __ROL4__(this->visemeType, 1));
  HIDWORD(v3) = &unk_821C0000;
  HIDWORD(v7) = *(const char **)((char *)idVoiceEvent::voiceEventNames + __ROL4__(this->eventType, 2));
  LODWORD(v7) = *(_DWORD *)(HIDWORD(v5) + v5);
  v8 = va::va(
         this: &v55,
         fmt: "\t\t%s %s {\n",
         a3: v7,
         a4: v3,
         a5: v5,
         a6: v25,
         a7: v30,
         a8: v35,
         a9: v40,
         a10: v45,
         a11: v50);
  idFile_String::operator+=(this: file, str: v8->buffer);
  LODWORD(v9) = &unk_821C0000;
  HIDWORD(v10) = this->startMS;
  v12 = va::va(
          this: &v55,
          fmt: "\t\t\tstart %d\n",
          a3: v10,
          a4: v9,
          a5: v11,
          a6: v26,
          a7: v31,
          a8: v36,
          a9: v41,
          a10: v46,
          a11: v51);
  idFile_String::operator+=(this: file, str: v12->buffer);
  LODWORD(v13) = (unsigned __int16)this->durationMS;
  HIDWORD(v14) = &unk_821C0000;
  HIDWORD(v13) = (__int16)v13;
  v16 = va::va(
          this: &v55,
          fmt: "\t\t\tduration %d\n",
          a3: v13,
          a4: v14,
          a5: v15,
          a6: v27,
          a7: v32,
          a8: v37,
          a9: v42,
          a10: v47,
          a11: v52);
  idFile_String::operator+=(this: file, str: v16->buffer);
  HIDWORD(v17) = this->peakTimeMS;
  v20 = va::va(
          this: &v55,
          fmt: "\t\t\tpeakTime %d\n",
          a3: v17,
          a4: v19,
          a5: v18,
          a6: v28,
          a7: v33,
          a8: v38,
          a9: v43,
          a10: v48,
          a11: v53);
  idFile_String::operator+=(this: file, str: v20->buffer);
  HIDWORD(v21) = this->peakWeight;
  v24 = va::va(
          this: &v55,
          fmt: "\t\t\tpeakWeight %d\n",
          a3: v21,
          a4: v23,
          a5: v22,
          a6: v29,
          a7: v34,
          a8: v39,
          a9: v44,
          a10: v49,
          a11: v54);
  idFile_String::operator+=(this: file, str: v24->buffer);
  idFile_String::operator+=(this: file, str: "\t\t}\n");
}


// ========================================================================
// ?LoadBinary@idViseme_Simple@@UAA_NPAVidFile@@@Z
// EA  : 0x8263EC40
// RVA : 0x0063EC40
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idViseme_Simple::LoadBinary(idViseme_Simple *this, idFile *file)
{
  if ( (unsigned __int8)idVisemeEvent::LoadBinary(this, file) == 0 )
    return 0;
  file->Read(this: file, a2: &this->peakTimeMS, a3: 2u);
  file->Read(this: file, a2: &this->peakWeight, a3: 1u);
  return 1;
}


// ========================================================================
// ?LoadBinary@idVoiceGameEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263ECC8
// RVA : 0x0063ECC8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceGameEvent::LoadBinary(idVoiceGameEvent *this, idFile *file)
{
  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  return 1;
}


// ========================================================================
// ??8idVoiceGameEvent@@UBA_NABV0@@Z
// EA  : 0x8263ED38
// RVA : 0x0063ED38
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

BOOL __fastcall idVoiceGameEvent::operator==(idVoiceGameEvent *this, const idVoiceGameEvent *other)
{
  char v2; // r11

  if ( this->eventType != other->eventType
    || this->startMS != other->startMS
    || (v2 = 1, this->durationMS != other->durationMS) )
  {
    v2 = 0;
  }
  return v2 != 0
      && this->eventNum == other->eventNum
      && (unsigned __int8)idVarArgs<2>::Equal(this: &this->args, other: &other->args) != 0;
}


// ========================================================================
// ?Parse@idVoiceTextEvent@@UAAXPAVidVoiceTrack@@AAVidLexer@@@Z
// EA  : 0x8263EE40
// RVA : 0x0063EE40
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceTextEvent::Parse(idVoiceTextEvent *this, idVoiceTrack *track, idLexer *src)
{
  int len; // r27
  idToken v6; // [sp+50h] [-80h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.floatvalue = -3.4028235e38;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v6);
  len = v6.len;
  idStr::EnsureAlloced(this: &this->text, amount: v6.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->text.data, Src: v6.data, Size: len);
  this->text.data[len] = 0;
  this->text.len = len;
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v6);
  idLexer::ExpectTokenString(this: src, string: "start");
  this->startMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenString(this: src, string: "duration");
  this->durationMS = idLexer::ParseInt(this: src);
  idLexer::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v6);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// __unwind$226909
// EA  : 0x8263EF4C
// RVA : 0x0063EF4C
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_226909()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?WriteBinary@idVoiceTextEvent@@UBA_NPAVidFile@@@Z
// EA  : 0x8263EF78
// RVA : 0x0063EF78
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceTextEvent::WriteBinary(idVoiceTextEvent *this, idFile *file)
{
  file->Write(this: file, a2: &this->startMS, a3: 4u);
  file->Write(this: file, a2: &this->durationMS, a3: 2u);
  idFile::WriteString(this: file, string: &this->text);
  return 1;
}


// ========================================================================
// ?LoadBinary@idVoiceTextEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263EFF8
// RVA : 0x0063EFF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceTextEvent::LoadBinary(idVoiceTextEvent *this, idFile *file)
{
  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  idFile::ReadString(this: file, string: &this->text);
  return 1;
}


// ========================================================================
// ?Memory@idVoiceTextEvent@@UBAIXZ
// EA  : 0x8263F078
// RVA : 0x0063F078
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceTextEvent::Memory(idVoiceTextEvent *this)
{
  if ( this->text.data == this->text.baseBuffer )
    return 44;
  else
    return (this->text.allocedAndFlag & 0x7FFFFFFF) + 44;
}


// ========================================================================
// ?Copy@idVoiceTextEvent@@IAAXABV1@@Z
// EA  : 0x8263F0A8
// RVA : 0x0063F0A8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceTextEvent::Copy(idVoiceTextEvent *this, const idVoiceTextEvent *other)
{
  int len; // r30

  this->eventType = other->eventType;
  this->startMS = other->startMS;
  this->durationMS = other->durationMS;
  len = other->text.len;
  idStr::EnsureAlloced(this: &this->text, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->text.data, Src: other->text.data, Size: len);
  this->text.data[len] = 0;
  this->text.len = len;
}


// ========================================================================
// ?LoadBinary@idVoicePunctuationEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263F118
// RVA : 0x0063F118
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoicePunctuationEvent::LoadBinary(idVoicePunctuationEvent *this, idFile *file)
{
  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  file->Read(this: file, a2: &this->punctuation, a3: 1u);
  return 1;
}


// ========================================================================
// ?WriteBinary@idVoiceAnimEvent@@UBA_NPAVidFile@@@Z
// EA  : 0x8263F1A8
// RVA : 0x0063F1A8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceAnimEvent::WriteBinary(idVoiceAnimEvent *this, idFile *file)
{
  file->Write(this: file, a2: &this->startMS, a3: 4u);
  file->Write(this: file, a2: &this->durationMS, a3: 2u);
  idFile::WriteString(this: file, string: this->animName.str);
  file->Write(this: file, a2: &this->channel, a3: 2u);
  file->Write(this: file, a2: &this->blendInDurationMS, a3: 2u);
  file->Write(this: file, a2: &this->blendOutDurationMS, a3: 2u);
  file->Write(this: file, a2: &this->startFrame, a3: 2u);
  file->Write(this: file, a2: &this->rate, a3: 2u);
  file->Write(this: file, a2: &this->looping, a3: 1u);
  return 1;
}


// ========================================================================
// ?LoadBinary@idVoiceAnimEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263F2D0
// RVA : 0x0063F2D0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceAnimEvent::LoadBinary(idVoiceAnimEvent *this, idFile *file)
{
  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  idFile::ReadString(this: file, string: &this->animName);
  file->Read(this: file, a2: &this->channel, a3: 2u);
  file->Read(this: file, a2: &this->blendInDurationMS, a3: 2u);
  file->Read(this: file, a2: &this->blendOutDurationMS, a3: 2u);
  file->Read(this: file, a2: &this->startFrame, a3: 2u);
  file->Read(this: file, a2: &this->rate, a3: 2u);
  file->Read(this: file, a2: &this->looping, a3: 1u);
  return 1;
}


// ========================================================================
// ?LoadBinary@idVoiceMoodEvent@@UAA_NPAVidFile@@@Z
// EA  : 0x8263F3F8
// RVA : 0x0063F3F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

int __fastcall idVoiceMoodEvent::LoadBinary(idVoiceMoodEvent *this, idFile *file)
{
  mood_t v4; // r11
  int result; // r3
  _BYTE v6[8]; // [sp+50h] [-20h] BYREF

  file->Read(this: file, a2: &this->startMS, a3: 4u);
  file->Read(this: file, a2: &this->durationMS, a3: 2u);
  file->Read(this: file, a2: v6, a3: 1u);
  v4 = v6[0];
  if ( v6[0] < 9u )
  {
    result = 1;
  }
  else
  {
    v4 = MOOD_NONE;
    result = 0;
  }
  this->mood = v4;
  return result;
}


// ========================================================================
// ?Free@idVoiceEventManager@@QAAXAAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x8263F4A0
// RVA : 0x0063F4A0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::Free(idVoiceEventManager *this, idList<idVehicleState *,5> *eventList)
{
  char *list; // r3
  char *v5; // r3
  char *v6; // r3
  char *v7; // r3
  char *v8; // r3
  char *v9; // r3

  if ( this->eventsVisemeSimple.listStatic == 0 || this->eventsVisemeSimple.listStatic == 2 )
  {
    list = (char *)this->eventsVisemeSimple.list;
    if ( this->eventsVisemeSimple.list != nullptr )
      idListArrayDelete<idViseme_Simple>(ptr: list, num: this->eventsVisemeSimple.size);
    this->eventsVisemeSimple.list = nullptr;
    this->eventsVisemeSimple.size = 0;
  }
  this->eventsVisemeSimple.num = 0;
  if ( this->eventsGame.listStatic == 0 || this->eventsGame.listStatic == 2 )
  {
    v5 = (char *)this->eventsGame.list;
    if ( v5 != nullptr )
      idListArrayDelete<idVoiceGameEvent>(ptr: v5, num: this->eventsGame.size);
    this->eventsGame.list = nullptr;
    this->eventsGame.size = 0;
  }
  this->eventsGame.num = 0;
  if ( this->eventsText.listStatic == 0 || this->eventsText.listStatic == 2 )
  {
    v6 = (char *)this->eventsText.list;
    if ( v6 != nullptr )
      idListArrayDelete<idDeclTypeInfoGraph::idContextMenuItemLink>(ptr: v6, num: this->eventsText.size);
    this->eventsText.list = nullptr;
    this->eventsText.size = 0;
  }
  this->eventsText.num = 0;
  if ( this->eventsPunc.listStatic == 0 || this->eventsPunc.listStatic == 2 )
  {
    v7 = (char *)this->eventsPunc.list;
    if ( v7 != nullptr )
      idListArrayDelete<idVoiceMoodEvent>(ptr: v7, num: this->eventsPunc.size);
    this->eventsPunc.list = nullptr;
    this->eventsPunc.size = 0;
  }
  this->eventsPunc.num = 0;
  if ( this->eventsAnim.listStatic == 0 || this->eventsAnim.listStatic == 2 )
  {
    v8 = (char *)this->eventsAnim.list;
    if ( v8 != nullptr )
      idListArrayDelete<idVoiceAnimEvent>(ptr: v8, num: this->eventsAnim.size);
    this->eventsAnim.list = nullptr;
    this->eventsAnim.size = 0;
  }
  this->eventsAnim.num = 0;
  if ( this->eventsMood.listStatic == 0 || this->eventsMood.listStatic == 2 )
  {
    v9 = (char *)this->eventsMood.list;
    if ( v9 != nullptr )
      idListArrayDelete<idVoiceMoodEvent>(ptr: v9, num: this->eventsMood.size);
    this->eventsMood.list = nullptr;
    this->eventsMood.size = 0;
  }
  this->eventsMood.num = 0;
  idList<idThread *,58>::Clear(this: eventList);
}


// ========================================================================
// ?FreeVisemeEvents@idVoiceEventManager@@QAAXAAV?$idList@VvtrEventHandle_t@@$04@@_N@Z
// EA  : 0x8263F600
// RVA : 0x0063F600
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::FreeVisemeEvents(
        idVoiceEventManager *this,
        idList<vtrEventHandle_t,5> *events,
        const bool freeTextToo)
{
  int v6; // r30
  int v7; // r28
  int eventType; // r11
  char v9; // r10
  char v10; // r11
  bool v11; // zf
  char *list; // r3
  char *v13; // r3

  v6 = events->num - 1;
  if ( v6 >= 0 )
  {
    v7 = v6;
    do
    {
      eventType = (unsigned __int8)events->list[v7].eventType;
      if ( (unsigned __int8)events->list[v7].eventType == 0 || (v9 = 0, eventType == 1) )
        v9 = 1;
      if ( eventType == 3 || (v11 = eventType != 4, v10 = 0, !v11) )
        v10 = 1;
      if ( v9 != 0 || freeTextToo && v10 != 0 )
        idList<vtrEventHandle_t,5>::RemoveIndex(this: events, index: v6);
      --v6;
      --v7;
    }
    while ( v6 >= 0 );
  }
  if ( this->eventsVisemeSimple.listStatic == 0 || this->eventsVisemeSimple.listStatic == 2 )
  {
    if ( this->eventsVisemeSimple.list != nullptr )
      idListArrayDelete<idViseme_Simple>(ptr: (char *)this->eventsVisemeSimple.list, num: this->eventsVisemeSimple.size);
    this->eventsVisemeSimple.list = nullptr;
    this->eventsVisemeSimple.size = 0;
  }
  this->eventsVisemeSimple.num = 0;
  if ( freeTextToo )
  {
    if ( this->eventsText.listStatic == 0 || this->eventsText.listStatic == 2 )
    {
      list = (char *)this->eventsText.list;
      if ( list != nullptr )
        idListArrayDelete<idDeclTypeInfoGraph::idContextMenuItemLink>(ptr: list, num: this->eventsText.size);
      this->eventsText.list = nullptr;
      this->eventsText.size = 0;
    }
    this->eventsText.num = 0;
    if ( this->eventsPunc.listStatic == 0 || this->eventsPunc.listStatic == 2 )
    {
      v13 = (char *)this->eventsPunc.list;
      if ( v13 != nullptr )
        idListArrayDelete<idVoiceMoodEvent>(ptr: v13, num: this->eventsPunc.size);
      this->eventsPunc.list = nullptr;
      this->eventsPunc.size = 0;
    }
    this->eventsPunc.num = 0;
  }
}


// ========================================================================
// ?FreeTextEvents@idVoiceEventManager@@QAAXAAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x8263F758
// RVA : 0x0063F758
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::FreeTextEvents(idVoiceEventManager *this, idList<vtrEventHandle_t,5> *events)
{
  int v3; // r8
  int v4; // r7
  int eventType; // r11
  int num; // r11
  int v7; // r11
  int v8; // r10
  int v9; // r9
  vtrEventHandle_t *v10; // r11
  char *list; // r3
  char *v12; // r3

  v3 = events->num - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      eventType = (unsigned __int8)events->list[v4].eventType;
      if ( eventType == 3 || eventType == 4 )
      {
        num = events->num;
        if ( v3 < num )
        {
          v7 = num - 1;
          v8 = v3;
          events->num = v7;
          if ( v3 < v7 )
          {
            v9 = v4 * 4;
            do
            {
              ++v8;
              v10 = (vtrEventHandle_t *)((char *)events->list + v9);
              v9 += 4;
              v10->eventType = v10[1].eventType;
              v10->index = v10[1].index;
            }
            while ( v8 < events->num );
          }
        }
      }
      --v3;
      --v4;
    }
    while ( v3 >= 0 );
  }
  if ( this->eventsText.listStatic == 0 || this->eventsText.listStatic == 2 )
  {
    list = (char *)this->eventsText.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclTypeInfoGraph::idContextMenuItemLink>(ptr: list, num: this->eventsText.size);
    this->eventsText.list = nullptr;
    this->eventsText.size = 0;
  }
  this->eventsText.num = 0;
  if ( this->eventsPunc.listStatic == 0 || this->eventsPunc.listStatic == 2 )
  {
    v12 = (char *)this->eventsPunc.list;
    if ( v12 != nullptr )
      idListArrayDelete<idVoiceMoodEvent>(ptr: v12, num: this->eventsPunc.size);
    this->eventsPunc.list = nullptr;
    this->eventsPunc.size = 0;
  }
  this->eventsPunc.num = 0;
}


// ========================================================================
// ?FreeEvents@idVoiceEventManager@@QAAXAAV?$idList@VvtrEventHandle_t@@$04@@0@Z
// EA  : 0x8263F888
// RVA : 0x0063F888
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::FreeEvents(
        idVoiceEventManager *this,
        idList<vtrEventHandle_t,5> *toFree,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v3; // r30
  int v4; // r31
  int v5; // r8
  int v6; // r7
  vtrEventHandle_t *v7; // r11
  vtrEventHandle_t *v8; // r10
  char v9; // r11
  bool v10; // zf
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  vtrEventHandle_t *v16; // r11
  unsigned int eventType; // r10
  _BYTE *list; // r10
  int v19; // r11

  v3 = 0;
  if ( toFree->num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = eventList->num - 1;
      if ( v5 >= 0 )
      {
        v6 = v5;
        do
        {
          v7 = &eventList->list[v6];
          v8 = &toFree->list[v4];
          if ( v8->eventType != v7->eventType || (v10 = v8->index == v7->index, v9 = 1, !v10) )
            v9 = 0;
          if ( v9 != 0 )
          {
            num = eventList->num;
            if ( v5 < num )
            {
              v12 = num - 1;
              v13 = v5;
              eventList->num = v12;
              if ( v5 < v12 )
              {
                v14 = v6 * 4;
                do
                {
                  ++v13;
                  v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                  v14 += 4;
                  v15->eventType = v15[1].eventType;
                  v15->index = v15[1].index;
                }
                while ( v13 < eventList->num );
              }
            }
          }
          --v5;
          --v6;
        }
        while ( v5 >= 0 );
      }
      v16 = &toFree->list[v4];
      eventType = v16->eventType;
      if ( eventType > 6 || eventType == 1 )
        goto LABEL_32;
      if ( eventType == 2 )
      {
        list = this->eventsGame.list;
        v19 = 36 * v16->index;
      }
      else if ( eventType == 3 && v16->eventType != 0 )
      {
        list = this->eventsText.list;
        v19 = 44 * v16->index;
      }
      else
      {
        if ( eventType == 4 && v16->eventType != 0 )
        {
          list = this->eventsPunc.list;
LABEL_30:
          v19 = 16 * v16->index;
          goto LABEL_31;
        }
        if ( eventType == 5 && v16->eventType != 0 )
        {
          list = this->eventsAnim.list;
          v19 = 28 * v16->index;
        }
        else
        {
          if ( v16->eventType != 0 )
          {
            list = this->eventsMood.list;
            goto LABEL_30;
          }
          list = this->eventsVisemeSimple.list;
          v19 = 20 * v16->index;
        }
      }
LABEL_31:
      list[v19 + 10] = 7;
LABEL_32:
      ++v3;
      ++v4;
    }
    while ( v3 < toFree->num );
  }
}


// ========================================================================
// ??0idVoiceGameEvent@@QAA@XZ
// EA  : 0x82640090
// RVA : 0x00640090
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceGameEvent *__fastcall idVoiceGameEvent::idVoiceGameEvent(idVoiceGameEvent *this)
{
  this->startMS = -1;
  this->durationMS = 0;
  this->eventType = 2;
  this->eventNum = -1;
  this->__vftable = (idVoiceGameEvent_vtbl *)&idVoiceGameEvent::`vftable';
  this->args.numArgs = 0;
  this->args.argSize = 0;
  this->args.buffSize = 0;
  this->args.args = nullptr;
  this->args.argOffsets[0] = 0;
  this->args.argOffsets[1] = 0;
  *(_WORD *)this->args.argTypes = 0;
  *(_WORD *)this->args.argExTypes = 0;
  idVarArgs<2>::Grow(this: &this->args, newArgSize: 0);
  return this;
}


// ========================================================================
// __unwind$228064
// EA  : 0x82640120
// RVA : 0x00640120
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228064()
{
  int v0; // r12

  idVoiceEvent::~idVoiceEvent(this: *(idVoiceEvent **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVoiceGameEvent@@UAA@XZ
// EA  : 0x82640160
// RVA : 0x00640160
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceGameEvent::~idVoiceGameEvent(idVoiceGameEvent *this)
{
  unsigned __int8 *args; // r4
  idVarArgs<2> *p_args; // r30

  this->__vftable = (idVoiceGameEvent_vtbl *)&idVoiceGameEvent::`vftable';
  args = this->args.args;
  p_args = &this->args;
  if ( args != nullptr )
  {
    idMem::Free(this: &mem, ptr: args, align: ALIGN_16);
    p_args->args = nullptr;
  }
  p_args->argSize = 0;
  p_args->buffSize = 0;
  p_args->numArgs = 0;
  this->__vftable = (idVoiceGameEvent_vtbl *)&idVoiceEvent::`vftable';
}


// ========================================================================
// __unwind$228124
// EA  : 0x826401D0
// RVA : 0x006401D0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228124()
{
  int v0; // r12

  idVoiceEvent::~idVoiceEvent(this: *(idVoiceEvent **)(v0 - 128 + 148));
}


// ========================================================================
// ?Write@idVoiceTextEvent@@UBAXPBVidVoiceTrack@@AAVidFile_String@@@Z
// EA  : 0x82640200
// RVA : 0x00640200
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceTextEvent::Write(idVoiceTextEvent *this, const idVoiceTrack *track, idFile_String *file)
{
  int allocedAndFlag; // r7
  int v6; // r28
  char v7; // r4
  int v8; // r11
  int v9; // r10
  char v10; // r30
  int v11; // r11
  int v12; // r10
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  va *v16; // r3
  unsigned int i; // r5
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r8
  va *v21; // r3
  unsigned int j; // r5
  __int64 v23; // r8
  __int64 v24; // r10
  __int64 v25; // r6
  va *v26; // r3
  unsigned int k; // r5
  int v28; // r5
  const char *v29; // r11
  int v30; // [sp+8h] [-10D8h]
  int v31; // [sp+8h] [-10D8h]
  int v32; // [sp+8h] [-10D8h]
  int v33; // [sp+Ch] [-10D4h]
  int v34; // [sp+Ch] [-10D4h]
  int v35; // [sp+Ch] [-10D4h]
  int v36; // [sp+10h] [-10D0h]
  int v37; // [sp+10h] [-10D0h]
  int v38; // [sp+10h] [-10D0h]
  int v39; // [sp+14h] [-10CCh]
  int v40; // [sp+14h] [-10CCh]
  int v41; // [sp+14h] [-10CCh]
  int v42; // [sp+18h] [-10C8h]
  int v43; // [sp+18h] [-10C8h]
  int v44; // [sp+18h] [-10C8h]
  int v45; // [sp+1Ch] [-10C4h]
  int v46; // [sp+1Ch] [-10C4h]
  int v47; // [sp+1Ch] [-10C4h]
  idStr v48; // [sp+60h] [-1080h] BYREF
  va v49; // [sp+80h] [-1060h] BYREF

  allocedAndFlag = 20;
  v48.baseBuffer[0] = 0;
  v48.len = 0;
  v48.allocedAndFlag = 20;
  v48.data = v48.baseBuffer;
  v6 = 0;
  if ( this->text.len > 0 )
  {
    while ( 1 )
    {
      v7 = this->text.data[v6];
      switch ( v7 )
      {
        case 34:
        case 39:
          v8 = v48.len + 2;
          v9 = allocedAndFlag & 0x7FFFFFFF;
          if ( allocedAndFlag >= 0 )
          {
            if ( v8 > v9 )
              idStr::ReAllocate(this: &v48, amount: (v8 >> 1) + v8, keepold: true);
          }
          else if ( v8 > v9
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v48.data[v48.len++] = 92;
          v48.data[v48.len] = 0;
          v10 = this->text.data[v6];
          v11 = v48.len + 2;
          v12 = v48.allocedAndFlag & 0x7FFFFFFF;
          if ( v48.allocedAndFlag >= 0 )
          {
            if ( v11 > v12 )
              idStr::ReAllocate(this: &v48, amount: (v11 >> 1) + v11, keepold: true);
          }
          else if ( v11 > v12
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v48.data[v48.len++] = v10;
          v48.data[v48.len] = 0;
          break;
        case 13:
          idStr::Append(this: &v48, text: "\\r");
          break;
        case 10:
          idStr::Append(this: &v48, text: "\\n");
          break;
        default:
          idStr::operator+=(this: &v48, a: v7);
          break;
      }
      if ( ++v6 >= this->text.len )
        break;
      allocedAndFlag = v48.allocedAndFlag;
    }
  }
  LODWORD(v13) = &consoleFont[21088];
  HIDWORD(v13) = &unk_821C0000;
  LODWORD(v14) = v48.data;
  LODWORD(v15) = idVoiceEvent::voiceEventNames;
  HIDWORD(v15) = __ROL4__(this->eventType, 2);
  HIDWORD(v14) = *(const char **)((char *)idVoiceEvent::voiceEventNames + HIDWORD(v15));
  v16 = va::va(
          this: &v49,
          fmt: "\t\t%s \"%s\" {\n",
          a3: v14,
          a4: v15,
          a5: v13,
          a6: v30,
          a7: v33,
          a8: v36,
          a9: v39,
          a10: v42,
          a11: v45);
  for ( i = 0; v16->buffer[i] != 0; ++i )
    ;
  file->Write(this: file, a2: v16, a3: i);
  HIDWORD(v18) = &unk_821C0000;
  HIDWORD(v19) = this->startMS;
  v21 = va::va(
          this: &v49,
          fmt: "\t\t\tstart %d\n",
          a3: v19,
          a4: v20,
          a5: v18,
          a6: v31,
          a7: v34,
          a8: v37,
          a9: v40,
          a10: v43,
          a11: v46);
  for ( j = 0; v21->buffer[j] != 0; ++j )
    ;
  file->Write(this: file, a2: v21, a3: j);
  LODWORD(v23) = (unsigned __int16)this->durationMS;
  HIDWORD(v24) = &unk_821C0000;
  HIDWORD(v25) = (__int16)v23;
  v26 = va::va(
          this: &v49,
          fmt: "\t\t\tduration %d\n",
          a3: v25,
          a4: v23,
          a5: v24,
          a6: v32,
          a7: v35,
          a8: v38,
          a9: v41,
          a10: v44,
          a11: v47);
  for ( k = 0; v26->buffer[k] != 0; ++k )
    ;
  file->Write(this: file, a2: v26, a3: k);
  v28 = 0;
  v29 = "\t\t}\n";
  do
  {
    ++v29;
    ++v28;
  }
  while ( *v29 != 0 );
  ((void (__fastcall *)(idFile_String *))file->Write)(a1: file);
  idStr::FreeData(this: &v48);
}


// ========================================================================
// __unwind$228177
// EA  : 0x82640548
// RVA : 0x00640548
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228177()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 96));
}


// ========================================================================
// ??4idVoiceTextEvent@@QAAAAV0@ABV0@@Z
// EA  : 0x82640570
// RVA : 0x00640570
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceTextEvent *__fastcall idVoiceTextEvent::operator=(idVoiceTextEvent *this, const idVoiceTextEvent *other)
{
  idVoiceTextEvent *v2; // r31

  v2 = this;
  if ( this != other )
  {
    idVoiceTextEvent::Copy(this, other);
    return v2;
  }
  return this;
}


// ========================================================================
// ??0idVoiceEventManager@@QAA@XZ
// EA  : 0x826405B0
// RVA : 0x006405B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceEventManager *__fastcall idVoiceEventManager::idVoiceEventManager(idVoiceEventManager *this)
{
  this->eventsVisemeSimple.granularity = 0;
  this->eventsVisemeSimple.memTag = 66;
  this->eventsVisemeSimple.listStatic = 0;
  this->eventsVisemeSimple.list = nullptr;
  this->eventsVisemeSimple.size = 0;
  this->eventsVisemeSimple.num = 0;
  this->eventsGame.granularity = 0;
  this->eventsGame.memTag = 66;
  this->eventsGame.listStatic = 0;
  this->eventsGame.list = nullptr;
  this->eventsGame.size = 0;
  this->eventsGame.num = 0;
  this->eventsText.granularity = 0;
  this->eventsText.memTag = 66;
  this->eventsText.listStatic = 0;
  this->eventsText.list = nullptr;
  this->eventsText.size = 0;
  this->eventsText.num = 0;
  this->eventsPunc.granularity = 0;
  this->eventsPunc.memTag = 66;
  this->eventsPunc.listStatic = 0;
  this->eventsPunc.list = nullptr;
  this->eventsPunc.size = 0;
  this->eventsPunc.num = 0;
  this->eventsAnim.granularity = 0;
  this->eventsAnim.memTag = 66;
  this->eventsAnim.listStatic = 0;
  this->eventsAnim.list = nullptr;
  this->eventsAnim.size = 0;
  this->eventsAnim.num = 0;
  this->eventsMood.granularity = 0;
  this->eventsMood.memTag = 66;
  this->eventsMood.listStatic = 0;
  this->eventsMood.list = nullptr;
  this->eventsMood.size = 0;
  this->eventsMood.num = 0;
  return this;
}


// ========================================================================
// __unwind$228490
// EA  : 0x82640688
// RVA : 0x00640688
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228490()
{
  int v0; // r12

  idList<idViseme_Simple,66>::~idList<idViseme_Simple,66>(this: *(idList<idViseme_Simple,66> **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$228491
// EA  : 0x826406B0
// RVA : 0x006406B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228491()
{
  int v0; // r12

  idList<idVoiceGameEvent,66>::~idList<idVoiceGameEvent,66>(this: (idList<idVoiceGameEvent,66> *)(*(_DWORD *)(v0 - 32 + 52)
                                                                                                + 16));
}


// ========================================================================
// __unwind$228492
// EA  : 0x826406DC
// RVA : 0x006406DC
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228492()
{
  int v0; // r12

  idList<idDeclTypeInfoGraph::idContextMenuItemMain,5>::Clear(this: (idList<idVoiceTextEvent,66> *)(*(_DWORD *)(v0 - 32 + 52)
                                                                                                  + 32));
}


// ========================================================================
// __unwind$228493
// EA  : 0x82640708
// RVA : 0x00640708
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228493()
{
  int v0; // r12

  idList<idVoicePunctuationEvent,66>::Clear(this: (idList<idVoicePunctuationEvent,66> *)(*(_DWORD *)(v0 - 32 + 52) + 48));
}


// ========================================================================
// __unwind$228494
// EA  : 0x82640734
// RVA : 0x00640734
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228494()
{
  int v0; // r12

  idList<idVoiceAnimEvent,66>::Clear(this: (idList<idVoiceAnimEvent,66> *)(*(_DWORD *)(v0 - 32 + 52) + 64));
}


// ========================================================================
// ??1idVoiceEventManager@@QAA@XZ
// EA  : 0x82640768
// RVA : 0x00640768
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::~idVoiceEventManager(idVoiceEventManager *this)
{
  char *list; // r3
  char *v3; // r3
  char *v4; // r3
  char *v5; // r3
  char *v6; // r3

  if ( this->eventsMood.listStatic == 0 || this->eventsMood.listStatic == 2 )
  {
    list = (char *)this->eventsMood.list;
    if ( list != nullptr )
      idListArrayDelete<idVoiceMoodEvent>(ptr: list, num: this->eventsMood.size);
    this->eventsMood.list = nullptr;
    this->eventsMood.size = 0;
  }
  this->eventsMood.num = 0;
  if ( this->eventsAnim.listStatic == 0 || this->eventsAnim.listStatic == 2 )
  {
    v3 = (char *)this->eventsAnim.list;
    if ( v3 != nullptr )
      idListArrayDelete<idVoiceAnimEvent>(ptr: v3, num: this->eventsAnim.size);
    this->eventsAnim.list = nullptr;
    this->eventsAnim.size = 0;
  }
  this->eventsAnim.num = 0;
  if ( this->eventsPunc.listStatic == 0 || this->eventsPunc.listStatic == 2 )
  {
    v4 = (char *)this->eventsPunc.list;
    if ( v4 != nullptr )
      idListArrayDelete<idVoiceMoodEvent>(ptr: v4, num: this->eventsPunc.size);
    this->eventsPunc.list = nullptr;
    this->eventsPunc.size = 0;
  }
  this->eventsPunc.num = 0;
  if ( this->eventsText.listStatic == 0 || this->eventsText.listStatic == 2 )
  {
    v5 = (char *)this->eventsText.list;
    if ( v5 != nullptr )
      idListArrayDelete<idDeclTypeInfoGraph::idContextMenuItemLink>(ptr: v5, num: this->eventsText.size);
    this->eventsText.list = nullptr;
    this->eventsText.size = 0;
  }
  this->eventsText.num = 0;
  if ( this->eventsGame.listStatic == 0 || this->eventsGame.listStatic == 2 )
  {
    v6 = (char *)this->eventsGame.list;
    if ( v6 != nullptr )
      idListArrayDelete<idVoiceGameEvent>(ptr: v6, num: this->eventsGame.size);
    this->eventsGame.list = nullptr;
    this->eventsGame.size = 0;
  }
  this->eventsGame.num = 0;
  if ( this->eventsVisemeSimple.listStatic == 0 || this->eventsVisemeSimple.listStatic == 2 )
  {
    if ( this->eventsVisemeSimple.list != nullptr )
      idListArrayDelete<idViseme_Simple>(ptr: (char *)this->eventsVisemeSimple.list, num: this->eventsVisemeSimple.size);
    this->eventsVisemeSimple.list = nullptr;
    this->eventsVisemeSimple.size = 0;
  }
  this->eventsVisemeSimple.num = 0;
}


// ========================================================================
// __unwind$228614
// EA  : 0x826408C4
// RVA : 0x006408C4
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228614()
{
  int v0; // r12

  idList<idViseme_Simple,66>::~idList<idViseme_Simple,66>(this: *(idList<idViseme_Simple,66> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$228615
// EA  : 0x826408EC
// RVA : 0x006408EC
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228615()
{
  int v0; // r12

  idList<idVoiceGameEvent,66>::~idList<idVoiceGameEvent,66>(this: (idList<idVoiceGameEvent,66> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                + 16));
}


// ========================================================================
// __unwind$228616
// EA  : 0x82640918
// RVA : 0x00640918
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228616()
{
  int v0; // r12

  idList<idDeclTypeInfoGraph::idContextMenuItemMain,5>::Clear(this: (idList<idVoiceTextEvent,66> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                  + 32));
}


// ========================================================================
// __unwind$228617
// EA  : 0x82640944
// RVA : 0x00640944
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228617()
{
  int v0; // r12

  idList<idVoicePunctuationEvent,66>::Clear(this: (idList<idVoicePunctuationEvent,66> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$228618_0
// EA  : 0x82640970
// RVA : 0x00640970
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _unwind_228618_0()
{
  int v0; // r12

  idList<idVoiceAnimEvent,66>::Clear(this: (idList<idVoiceAnimEvent,66> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ??4idVoiceGameEvent@@QAAAAV0@ABV0@@Z
// EA  : 0x82640D90
// RVA : 0x00640D90
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceGameEvent *__fastcall idVoiceGameEvent::operator=(idVoiceGameEvent *this, const idVoiceGameEvent *other)
{
  if ( other != this )
  {
    this->eventType = other->eventType;
    this->startMS = other->startMS;
    this->durationMS = other->durationMS;
    this->eventNum = other->eventNum;
    idVarArgs<2>::Copy(this: &this->args, other: &other->args);
  }
  return this;
}


// ========================================================================
// ??$AllocEventFromList@VidViseme_Simple@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidViseme_Simple@@$0EC@@@@Z
// EA  : 0x82640DF8
// RVA : 0x00640DF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idViseme_Simple,66>(
        vtrEventHandle_t *result,
        idList<idViseme_Simple,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idViseme_Simple,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idViseme_Simple,66>::Alloc(this: list);
  }
  result->index = Free;
  result->eventType = 0;
  return result;
}


// ========================================================================
// ??$AllocEventFromList@VidVoicePunctuationEvent@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidVoicePunctuationEvent@@$0EC@@@@Z
// EA  : 0x82640E48
// RVA : 0x00640E48
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idVoicePunctuationEvent,66>(
        vtrEventHandle_t *result,
        idList<idVoiceMoodEvent,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idVoiceMoodEvent,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idVoicePunctuationEvent,66>::Alloc(this: (idList<idVoicePunctuationEvent,66> *)list);
  }
  result->index = Free;
  result->eventType = 4;
  return result;
}


// ========================================================================
// ??$AllocEventFromList@VidVoiceMoodEvent@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidVoiceMoodEvent@@$0EC@@@@Z
// EA  : 0x82640E98
// RVA : 0x00640E98
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idVoiceMoodEvent,66>(
        vtrEventHandle_t *result,
        idList<idVoiceMoodEvent,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idVoiceMoodEvent,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idVoiceMoodEvent,66>::Alloc(this: list);
  }
  result->index = Free;
  result->eventType = 6;
  return result;
}


// ========================================================================
// ??$CondenseList@VidViseme_Simple@@$0EC@@@YAXAAV?$idList@VidViseme_Simple@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x82640EE8
// RVA : 0x00640EE8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idViseme_Simple,66>(
        idList<idViseme_Simple,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idViseme_Simple,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idViseme_Simple,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idViseme_Simple,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ??$CondenseList@VidVoicePunctuationEvent@@$0EC@@@YAXAAV?$idList@VidVoicePunctuationEvent@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x82641048
// RVA : 0x00641048
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idVoicePunctuationEvent,66>(
        idList<idVoicePunctuationEvent,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idVoicePunctuationEvent,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idVoicePunctuationEvent,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idVoicePunctuationEvent,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ??$CondenseList@VidVoiceMoodEvent@@$0EC@@@YAXAAV?$idList@VidVoiceMoodEvent@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x826411A0
// RVA : 0x006411A0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idVoiceMoodEvent,66>(
        idList<idVoiceMoodEvent,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idVoiceMoodEvent,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idVoiceMoodEvent,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idVoiceMoodEvent,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ??$AllocEventFromList@VidVoiceAnimEvent@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidVoiceAnimEvent@@$0EC@@@@Z
// EA  : 0x826415B0
// RVA : 0x006415B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idVoiceAnimEvent,66>(
        vtrEventHandle_t *result,
        idList<idVoiceAnimEvent,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idVoiceAnimEvent,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idVoiceAnimEvent,66>::Alloc(this: list);
  }
  result->index = Free;
  result->eventType = 5;
  return result;
}


// ========================================================================
// ??$CondenseList@VidVoiceAnimEvent@@$0EC@@@YAXAAV?$idList@VidVoiceAnimEvent@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x82641600
// RVA : 0x00641600
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idVoiceAnimEvent,66>(
        idList<idVoiceAnimEvent,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idVoiceAnimEvent,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idVoiceAnimEvent,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idVoiceAnimEvent,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ??$AllocEventFromList@VidVoiceTextEvent@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidVoiceTextEvent@@$0EC@@@@Z
// EA  : 0x82641960
// RVA : 0x00641960
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idVoiceTextEvent,66>(
        vtrEventHandle_t *result,
        idList<idVoiceTextEvent,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idVoiceTextEvent,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idVoiceTextEvent,66>::Alloc(this: list);
  }
  result->index = Free;
  result->eventType = 3;
  return result;
}


// ========================================================================
// ??$CondenseList@VidVoiceTextEvent@@$0EC@@@YAXAAV?$idList@VidVoiceTextEvent@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x826419B0
// RVA : 0x006419B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idVoiceTextEvent,66>(
        idList<idVoiceTextEvent,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idVoiceTextEvent,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idVoiceTextEvent,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idVoiceTextEvent,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ?LoadBinary@idVoiceEventManager@@QAAXPAVidFile@@@Z
// EA  : 0x82641B98
// RVA : 0x00641B98
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::LoadBinary(idVoiceEventManager *this, idFile *file)
{
  int v4; // r4
  int v5; // r31
  char v6; // r3
  int size; // r11
  int v8; // r30
  int v9; // r31
  int v10; // r4
  int v11; // r31
  char v12; // r3
  int v13; // r11
  int v14; // r30
  int v15; // r31
  int v16; // r4
  int v17; // r31
  char v18; // r3
  int v19; // r11
  int v20; // r30
  int v21; // r31
  int v22; // r4
  int v23; // r31
  char v24; // r3
  int v25; // r11
  int v26; // r30
  int v27; // r31
  int v28; // r4
  int v29; // r31
  char v30; // r3
  int v31; // r11
  int v32; // r30
  int v33; // r31
  int v34; // r4
  int v35; // r31
  char v36; // r3
  int v37; // r11
  int v38; // r30
  int v39; // r31
  int v40[16]; // [sp+50h] [-40h] BYREF

  file->Read(this: file, a2: v40, a3: 4u);
  v4 = v40[0];
  v5 = v40[0];
  if ( v40[0] <= this->eventsVisemeSimple.size
    || (v6 = idList<idViseme_Simple,66>::Resize(this: &this->eventsVisemeSimple, newsize: v40[0]), v4 = v40[0], v6 != 0) )
  {
    size = this->eventsVisemeSimple.size;
    if ( v5 < size )
      size = v5;
    this->eventsVisemeSimple.num = size;
  }
  v8 = 0;
  if ( v4 > 0 )
  {
    v9 = 0;
    do
    {
      this->eventsVisemeSimple.list[v9].LoadBinary(this: &this->eventsVisemeSimple.list[v9], a2: file);
      ++v8;
      ++v9;
    }
    while ( v8 < v40[0] );
  }
  file->Read(this: file, a2: v40, a3: 4u);
  v10 = v40[0];
  v11 = v40[0];
  if ( v40[0] <= this->eventsGame.size
    || (v12 = idList<idVoiceGameEvent,66>::Resize(this: &this->eventsGame, newsize: v40[0]), v10 = v40[0], v12 != 0) )
  {
    v13 = this->eventsGame.size;
    if ( v11 < v13 )
      v13 = v11;
    this->eventsGame.num = v13;
  }
  v14 = 0;
  if ( v10 > 0 )
  {
    v15 = 0;
    do
    {
      this->eventsGame.list[v15].LoadBinary(this: &this->eventsGame.list[v15], a2: file);
      ++v14;
      ++v15;
    }
    while ( v14 < v40[0] );
  }
  file->Read(this: file, a2: v40, a3: 4u);
  v16 = v40[0];
  v17 = v40[0];
  if ( v40[0] <= this->eventsText.size
    || (v18 = idList<idVoiceTextEvent,66>::Resize(this: &this->eventsText, newsize: v40[0]), v16 = v40[0], v18 != 0) )
  {
    v19 = this->eventsText.size;
    if ( v17 < v19 )
      v19 = v17;
    this->eventsText.num = v19;
  }
  v20 = 0;
  if ( v16 > 0 )
  {
    v21 = 0;
    do
    {
      this->eventsText.list[v21].LoadBinary(this: &this->eventsText.list[v21], a2: file);
      ++v20;
      ++v21;
    }
    while ( v20 < v40[0] );
  }
  file->Read(this: file, a2: v40, a3: 4u);
  v22 = v40[0];
  v23 = v40[0];
  if ( v40[0] <= this->eventsPunc.size
    || (v24 = idList<idVoicePunctuationEvent,66>::Resize(this: &this->eventsPunc, newsize: v40[0]),
        v22 = v40[0],
        v24 != 0) )
  {
    v25 = this->eventsPunc.size;
    if ( v23 < v25 )
      v25 = v23;
    this->eventsPunc.num = v25;
  }
  v26 = 0;
  if ( v22 > 0 )
  {
    v27 = 0;
    do
    {
      this->eventsPunc.list[v27].LoadBinary(this: &this->eventsPunc.list[v27], a2: file);
      ++v26;
      ++v27;
    }
    while ( v26 < v40[0] );
  }
  file->Read(this: file, a2: v40, a3: 4u);
  v28 = v40[0];
  v29 = v40[0];
  if ( v40[0] <= this->eventsAnim.size
    || (v30 = idList<idVoiceAnimEvent,66>::Resize(this: &this->eventsAnim, newsize: v40[0]), v28 = v40[0], v30 != 0) )
  {
    v31 = this->eventsAnim.size;
    if ( v29 < v31 )
      v31 = v29;
    this->eventsAnim.num = v31;
  }
  v32 = 0;
  if ( v28 > 0 )
  {
    v33 = 0;
    do
    {
      this->eventsAnim.list[v33].LoadBinary(this: &this->eventsAnim.list[v33], a2: file);
      ++v32;
      ++v33;
    }
    while ( v32 < v40[0] );
  }
  file->Read(this: file, a2: v40, a3: 4u);
  v34 = v40[0];
  v35 = v40[0];
  if ( v40[0] <= this->eventsMood.size
    || (v36 = idList<idVoiceMoodEvent,66>::Resize(this: &this->eventsMood, newsize: v40[0]), v34 = v40[0], v36 != 0) )
  {
    v37 = this->eventsMood.size;
    if ( v35 < v37 )
      v37 = v35;
    this->eventsMood.num = v37;
  }
  v38 = 0;
  if ( v34 > 0 )
  {
    v39 = 0;
    do
    {
      this->eventsMood.list[v39].LoadBinary(this: &this->eventsMood.list[v39], a2: file);
      ++v38;
      ++v39;
    }
    while ( v38 < v40[0] );
  }
}


// ========================================================================
// ??$AllocEventFromList@VidVoiceGameEvent@@$0EC@@@YA?AVvtrEventHandle_t@@AAV?$idList@VidVoiceGameEvent@@$0EC@@@@Z
// EA  : 0x82641F70
// RVA : 0x00641F70
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

vtrEventHandle_t *__fastcall AllocEventFromList<idVoiceGameEvent,66>(
        vtrEventHandle_t *result,
        idList<idVoiceGameEvent,66> *list)
{
  int Free; // r31

  Free = FindFreeIndex<idVoiceGameEvent,66>(list);
  if ( Free < 0 )
  {
    Free = list->num;
    idList<idVoiceGameEvent,66>::Alloc(this: list);
  }
  result->index = Free;
  result->eventType = 2;
  return result;
}


// ========================================================================
// ??$CondenseList@VidVoiceGameEvent@@$0EC@@@YAXAAV?$idList@VidVoiceGameEvent@@$0EC@@@AAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x82641FC0
// RVA : 0x00641FC0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall CondenseList<idVoiceGameEvent,66>(
        idList<idVoiceGameEvent,66> *list,
        idList<vtrEventHandle_t,5> *eventList)
{
  int v4; // r28
  int v5; // r30
  int v6; // r27
  int v7; // r8
  int v8; // r7
  vtrEventHandle_t *v9; // r10
  __int16 index; // r9
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  vtrEventHandle_t *v15; // r11
  int v16; // r11
  int v17; // r31
  int size; // r11

  v4 = 0;
  v5 = list->num - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      if ( list->list[v6].eventType == 7 )
      {
        ++v4;
        idList<idVoiceGameEvent,66>::RemoveIndex(this: list, index: v5);
        v7 = eventList->num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          do
          {
            v9 = &eventList->list[v8];
            index = v9->index;
            if ( index == v5 )
            {
              num = eventList->num;
              if ( v7 < num )
              {
                v12 = num - 1;
                v13 = v7;
                eventList->num = v12;
                if ( v7 < v12 )
                {
                  v14 = v8 * 4;
                  do
                  {
                    ++v13;
                    v15 = (vtrEventHandle_t *)((char *)eventList->list + v14);
                    v14 += 4;
                    v15->eventType = v15[1].eventType;
                    v15->index = v15[1].index;
                  }
                  while ( v13 < eventList->num );
                }
              }
            }
            else if ( index > v5 )
            {
              v9->index = index - 1;
            }
            --v7;
            --v8;
          }
          while ( v7 >= 0 );
        }
      }
      --v5;
      --v6;
    }
    while ( v5 >= 0 );
    if ( v4 > 0 )
    {
      v16 = list->num;
      v17 = v16 - v4;
      if ( v16 - v4 <= list->size
        || (unsigned __int8)idList<idVoiceGameEvent,66>::Resize(this: list, newsize: v16 - v4) != 0 )
      {
        size = list->size;
        if ( v17 < size )
          size = v17;
        list->num = size;
      }
    }
  }
  idList<idVoiceGameEvent,66>::Resize(this: list, newsize: list->num);
}


// ========================================================================
// ?AllocEvent@idVoiceEventManager@@QAA?AVvtrEventHandle_t@@W4voiceEvent_t@@@Z
// EA  : 0x82642120
// RVA : 0x00642120
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceEventManager *__fastcall idVoiceEventManager::AllocEvent(
        idVoiceEventManager *this,
        idList<idViseme_Simple,66> *result,
        unsigned int eventType)
{
  vtrEventHandle_t *v4; // r3
  __int16 v5; // r11
  vtrEventHandle_t v7; // [sp+50h] [-30h] BYREF
  vtrEventHandle_t v8; // [sp+54h] [-2Ch] BYREF
  vtrEventHandle_t v9; // [sp+58h] [-28h] BYREF
  vtrEventHandle_t v10; // [sp+5Ch] [-24h] BYREF
  vtrEventHandle_t v11; // [sp+60h] [-20h] BYREF
  vtrEventHandle_t v12; // [sp+64h] [-1Ch] BYREF

  HIWORD(this->eventsVisemeSimple.list) = 7;
  LOWORD(this->eventsVisemeSimple.list) = -1;
  if ( eventType <= 6 && eventType != 1 )
  {
    switch ( eventType )
    {
      case 2u:
        v4 = AllocEventFromList<idVoiceGameEvent,66>(result: &v8, list: (idList<idVoiceGameEvent,66> *)&result[1]);
        break;
      case 3u:
        v4 = AllocEventFromList<idVoiceTextEvent,66>(result: &v9, list: (idList<idVoiceTextEvent,66> *)&result[2]);
        break;
      case 4u:
        v4 = AllocEventFromList<idVoicePunctuationEvent,66>(
               result: &v10,
               list: (idList<idVoiceMoodEvent,66> *)&result[3]);
        break;
      case 5u:
        v4 = AllocEventFromList<idVoiceAnimEvent,66>(result: &v11, list: (idList<idVoiceAnimEvent,66> *)&result[4]);
        break;
      default:
        if ( eventType != 0 )
          v4 = AllocEventFromList<idVoiceMoodEvent,66>(result: &v12, list: (idList<idVoiceMoodEvent,66> *)&result[5]);
        else
          v4 = AllocEventFromList<idViseme_Simple,66>(result: &v7, list: result);
        break;
    }
    v5 = v4->eventType;
    LOWORD(this->eventsVisemeSimple.list) = v4->index;
    HIWORD(this->eventsVisemeSimple.list) = v5;
  }
  return this;
}


// ========================================================================
// ?AllocEvent@idVoiceEventManager@@QAA?AVvtrEventHandle_t@@PBD@Z
// EA  : 0x826421F0
// RVA : 0x006421F0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

idVoiceEventManager *__fastcall idVoiceEventManager::AllocEvent(
        idVoiceEventManager *this,
        idList<idViseme_Simple,66> *result,
        const char *name)
{
  unsigned int v6; // r29
  const char **v7; // r30
  vtrEventHandle_t *v9; // r3
  __int16 v10; // r11
  vtrEventHandle_t *v11; // r3
  __int16 eventType; // r11
  vtrEventHandle_t *v13; // r3
  __int16 v14; // r11
  vtrEventHandle_t *v15; // r3
  __int16 v16; // r11
  vtrEventHandle_t *v17; // r3
  __int16 v18; // r11
  vtrEventHandle_t v19; // [sp+50h] [-50h] BYREF
  vtrEventHandle_t v20; // [sp+54h] [-4Ch] BYREF
  vtrEventHandle_t v21; // [sp+58h] [-48h] BYREF
  vtrEventHandle_t v22; // [sp+5Ch] [-44h] BYREF
  vtrEventHandle_t v23; // [sp+60h] [-40h] BYREF
  vtrEventHandle_t v24; // [sp+64h] [-3Ch] BYREF

  v6 = 0;
  v7 = idVoiceEvent::voiceEventNames;
  while ( idStr::Cmp(s1: name, s2: *v7) != 0 )
  {
    ++v7;
    ++v6;
    if ( (int)v7 >= (int)idVoiceAnimEvent::channelNames )
    {
      HIWORD(this->eventsVisemeSimple.list) = 7;
      LOWORD(this->eventsVisemeSimple.list) = -1;
      return this;
    }
  }
  HIWORD(this->eventsVisemeSimple.list) = 7;
  LOWORD(this->eventsVisemeSimple.list) = -1;
  if ( v6 > 6 || v6 == 1 )
    return this;
  switch ( v6 )
  {
    case 2u:
      v11 = AllocEventFromList<idVoiceGameEvent,66>(result: &v20, list: (idList<idVoiceGameEvent,66> *)&result[1]);
      eventType = v11->eventType;
      LOWORD(this->eventsVisemeSimple.list) = v11->index;
      HIWORD(this->eventsVisemeSimple.list) = eventType;
      return this;
    case 3u:
      v13 = AllocEventFromList<idVoiceTextEvent,66>(result: &v21, list: (idList<idVoiceTextEvent,66> *)&result[2]);
      v14 = v13->eventType;
      LOWORD(this->eventsVisemeSimple.list) = v13->index;
      HIWORD(this->eventsVisemeSimple.list) = v14;
      return this;
    case 4u:
      v15 = AllocEventFromList<idVoicePunctuationEvent,66>(
              result: &v22,
              list: (idList<idVoiceMoodEvent,66> *)&result[3]);
      v16 = v15->eventType;
      LOWORD(this->eventsVisemeSimple.list) = v15->index;
      HIWORD(this->eventsVisemeSimple.list) = v16;
      return this;
    case 5u:
      v17 = AllocEventFromList<idVoiceAnimEvent,66>(result: &v23, list: (idList<idVoiceAnimEvent,66> *)&result[4]);
      v18 = v17->eventType;
      LOWORD(this->eventsVisemeSimple.list) = v17->index;
      HIWORD(this->eventsVisemeSimple.list) = v18;
      return this;
    default:
      if ( v6 != 0 )
        v9 = AllocEventFromList<idVoiceMoodEvent,66>(result: &v24, list: (idList<idVoiceMoodEvent,66> *)&result[5]);
      else
        v9 = AllocEventFromList<idViseme_Simple,66>(result: &v19, list: result);
      v10 = v9->eventType;
      LOWORD(this->eventsVisemeSimple.list) = v9->index;
      HIWORD(this->eventsVisemeSimple.list) = v10;
      return this;
  }
}


// ========================================================================
// ?Condense@idVoiceEventManager@@QAAXAAV?$idList@VvtrEventHandle_t@@$04@@@Z
// EA  : 0x82642388
// RVA : 0x00642388
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall idVoiceEventManager::Condense(idVoiceEventManager *this, idList<vtrEventHandle_t,5> *eventList)
{
  CondenseList<idViseme_Simple,66>(list: &this->eventsVisemeSimple, eventList);
  CondenseList<idVoiceGameEvent,66>(list: &this->eventsGame, eventList);
  CondenseList<idVoiceTextEvent,66>(list: &this->eventsText, eventList);
  CondenseList<idVoicePunctuationEvent,66>(list: &this->eventsPunc, eventList);
  CondenseList<idVoiceAnimEvent,66>(list: &this->eventsAnim, eventList);
  CondenseList<idVoiceMoodEvent,66>(list: &this->eventsMood, eventList);
}


// ========================================================================
// `dynamic initializer for 'vo_extraVisemeDuration''
// EA  : 0x833375F8
// RVA : 0x013375F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vo_extraVisemeDuration__()
{
  idCVar::idCVar(
    this: &vo_extraVisemeDuration,
    name: "vo_extraVisemeDuration",
    value: "0",
    flags: 4,
    description: "extra duration to add to visemes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vo_extraVisemeDuration__);
}


// ========================================================================
// `dynamic initializer for 'idViseme_Simple::NAME''
// EA  : 0x83337650
// RVA : 0x01337650
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idViseme_Simple::NAME__()
{
  idViseme_Simple::NAME = idVoiceEvent::voiceEventNames[0];
}


// ========================================================================
// `dynamic initializer for 'idViseme_Frame::NAME''
// EA  : 0x83337668
// RVA : 0x01337668
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idViseme_Frame::NAME__()
{
  idViseme_Frame::NAME = idVoiceEvent::voiceEventNames[1];
}


// ========================================================================
// `dynamic initializer for 'idVoiceGameEvent::NAME''
// EA  : 0x83337680
// RVA : 0x01337680
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceGameEvent::NAME__()
{
  idVoiceGameEvent::NAME = idVoiceEvent::voiceEventNames[2];
}


// ========================================================================
// `dynamic initializer for 'idVoiceTextEvent::NAME''
// EA  : 0x83337698
// RVA : 0x01337698
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceTextEvent::NAME__()
{
  idVoiceTextEvent::NAME = idVoiceEvent::voiceEventNames[3];
}


// ========================================================================
// `dynamic initializer for 'idVoicePunctuationEvent::NAME''
// EA  : 0x833376B0
// RVA : 0x013376B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idVoicePunctuationEvent::NAME__()
{
  idVoicePunctuationEvent::NAME = idVoiceEvent::voiceEventNames[4];
}


// ========================================================================
// `dynamic initializer for 'idVoiceAnimEvent::NAME''
// EA  : 0x833376C8
// RVA : 0x013376C8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceAnimEvent::NAME__()
{
  idVoiceAnimEvent::NAME = idVoiceEvent::voiceEventNames[5];
}


// ========================================================================
// `dynamic initializer for 'idVoiceMoodEvent::NAME''
// EA  : 0x833376E0
// RVA : 0x013376E0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__idVoiceMoodEvent::NAME__()
{
  idVoiceMoodEvent::NAME = idVoiceEvent::voiceEventNames[6];
}


// ========================================================================
// `dynamic initializer for 'RATE_FRACTIONAL_MASK''
// EA  : 0x833376F8
// RVA : 0x013376F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__RATE_FRACTIONAL_MASK__()
{
  RATE_FRACTIONAL_MASK = (1 << RATE_FRACTIONAL_BITS) - 1;
}


// ========================================================================
// `dynamic initializer for 'RATE_WHOLE_MASK''
// EA  : 0x83337718
// RVA : 0x01337718
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void _dynamic_initializer_for__RATE_WHOLE_MASK__()
{
  RATE_WHOLE_MASK = ~RATE_FRACTIONAL_MASK;
}


// ========================================================================
// `dynamic initializer for 'FRACTIONAL_STEP''
// EA  : 0x83337730
// RVA : 0x01337730
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack_events.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__FRACTIONAL_STEP__(int a1, int a2, int a3, int a4, __int64 a5)
{
  LODWORD(a5) = RATE_FRACTIONAL_MASK;
  FRACTIONAL_STEP = (float)1.0 / (float)a5;
}

