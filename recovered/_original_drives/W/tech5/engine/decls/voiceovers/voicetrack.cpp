
// ========================================================================
// ?Alloc@idFrameRefIndexBuffer@idVoiceTrack@@QAAXG@Z
// EA  : 0x826363B0
// RVA : 0x006363B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::idFrameRefIndexBuffer::Alloc(idVoiceTrack::idFrameRefIndexBuffer *this, int size)
{
  unsigned __int16 *indices; // r4

  indices = this->indices;
  if ( indices != nullptr )
  {
    idMem::Free(this: &mem, ptr: indices, align: ALIGN_16);
    this->indices = nullptr;
  }
  this->curOffset = 0;
  this->size = 0;
  this->indices = (unsigned __int16 *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\engine\\decls\\VoiceOvers\\VoiceTrack.cpp(275) : TAG_VOICETRACK_FRAMEREFS",
                                        size: (2 * size) & 0x1FFFE,
                                        tag: TAG_VOICETRACK_FRAMEREFS,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  this->size = size;
}


// ========================================================================
// ?GetMoodForName@idVoiceTrack@@SA?AW4mood_t@@PBD@Z
// EA  : 0x82636428
// RVA : 0x00636428
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::GetMoodForName(const char *name)
{
  int v2; // r30
  const char **v3; // r31

  v2 = 0;
  v3 = idVoiceTrack::moodNames;
  while ( idStr::Icmp(s1: *v3, s2: name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)idVoiceTrack::faceChannelNames )
      return 0;
  }
  return v2;
}


// ========================================================================
// ?GetFaceChannelForName@idVoiceTrack@@SA?AW4faceChannel_t@@PBD@Z
// EA  : 0x82636488
// RVA : 0x00636488
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::GetFaceChannelForName(const char *name)
{
  int v2; // r30
  const char **v3; // r31

  v2 = 0;
  v3 = idVoiceTrack::faceChannelNames;
  while ( idStr::Icmp(s1: *v3, s2: name) != 0 )
  {
    ++v3;
    ++v2;
    if ( (int)v3 >= (int)&idSort<vtrEventHandle_t> `RTTI Type Descriptor' )
      return 11;
  }
  return v2;
}


// ========================================================================
// ?GetMoodAnimName@idVoiceTrack@@SAPBDW4mood_t@@@Z
// EA  : 0x826364E8
// RVA : 0x006364E8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

const char *__fastcall idVoiceTrack::GetMoodAnimName(unsigned int mood)
{
  if ( mood > 8 )
    return idVoiceTrack::moodAnimNames[1];
  else
    return idVoiceTrack::moodAnimNames[mood];
}


// ========================================================================
// ?GetMoodName@idVoiceTrack@@SAPBDW4mood_t@@@Z
// EA  : 0x82636520
// RVA : 0x00636520
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

const char *__fastcall idVoiceTrack::GetMoodName(unsigned int mood)
{
  if ( mood > 8 )
    return idVoiceTrack::moodNames[1];
  else
    return idVoiceTrack::moodNames[mood];
}


// ========================================================================
// ?GetFaceChannelName@idVoiceTrack@@SAPBDW4faceChannel_t@@@Z
// EA  : 0x82636558
// RVA : 0x00636558
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

const char *__fastcall idVoiceTrack::GetFaceChannelName(const faceChannel_t fc)
{
  return idVoiceTrack::faceChannelNames[fc];
}


// ========================================================================
// ??1idFrameRefIndexBuffer@idVoiceTrack@@QAA@XZ
// EA  : 0x826365F8
// RVA : 0x006365F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::idFrameRefIndexBuffer::~idFrameRefIndexBuffer(idVoiceTrack::idFrameRefIndexBuffer *this)
{
  unsigned __int16 *indices; // r4

  indices = this->indices;
  if ( indices != nullptr )
  {
    idMem::Free(this: &mem, ptr: indices, align: ALIGN_16);
    this->indices = nullptr;
  }
  this->curOffset = 0;
  this->size = 0;
}


// ========================================================================
// ?Write@idFrameRefIndexBuffer@idVoiceTrack@@QBAXPAVidFile@@@Z
// EA  : 0x82636658
// RVA : 0x00636658
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::idFrameRefIndexBuffer::Write(idVoiceTrack::idFrameRefIndexBuffer *this, idFile *file)
{
  file->Write(this: file, a2: &this->size, a3: 2u);
  file->Write(this: file, a2: this, a3: 2u);
  file->Write(this: file, a2: this->indices, a3: __ROL4__(this->size, 1));
}


// ========================================================================
// ?ReloadIfStale@idVoiceTrack@@UAA_NXZ
// EA  : 0x826366E8
// RVA : 0x006366E8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::ReloadIfStale(idVoiceTrack *this)
{
  _BYTE v3[264]; // [sp+50h] [-120h] BYREF

  if ( fileSystem->GetTimestamp(this: fileSystem, a2: this->name.str, a3: false) == this->timestamp )
    return 0;
  fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmd6anim", a4: this->name.str, a5: v3, a6: 256);
  fileSystem->RemoveFile(this: fileSystem, a2: v3, a3: FSPATH_BASE);
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?CalcTextCRC@idVoiceTrack@@SAIPBD@Z
// EA  : 0x826367B0
// RVA : 0x006367B0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

unsigned int __fastcall idVoiceTrack::CalcTextCRC(const char *text)
{
  int v3; // r4

  if ( idLangDict::IsStringId(str: text) )
    return 0;
  v3 = 0;
  if ( *text != 0 )
  {
    do
      ++v3;
    while ( text[v3] != 0 );
  }
  return CRC32_BlockChecksum(data: text, length: v3);
}


// ========================================================================
// ?OffsetEvents@idVoiceTrack@@AAAXW4eventOffset_t@1@_N@Z
// EA  : 0x82636828
// RVA : 0x00636828
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::OffsetEvents(
        idVoiceTrack *this,
        const idVoiceTrack::eventOffset_t ofs,
        const bool visemesOnly)
{
  char v6; // r11
  int v7; // r28
  unsigned __int32 v8; // r24
  int num; // r11
  unsigned __int32 v10; // r27
  unsigned __int32 v11; // r26
  unsigned __int32 v12; // r25
  unsigned __int32 v13; // r23
  int j; // r30
  idVoiceEvent *v15; // r3
  unsigned int v16; // r11
  int v17; // r11
  int i; // r30
  idVoiceEvent *Event; // r3
  unsigned int eventType; // r11
  int v21; // r11

  if ( ofs == EVENTOFFSET_FORWARDS )
  {
    if ( visemesOnly )
    {
      if ( this->visemeOffsetState == 1 )
        return;
      v6 = 1;
      goto LABEL_18;
    }
    if ( this->offsetState == 1 )
      return;
    if ( this->visemeOffsetState == 1 )
      idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_BACKWARDS, visemesOnly: true);
    v6 = 1;
  }
  else
  {
    if ( ofs != EVENTOFFSET_BACKWARDS )
      goto LABEL_19;
    if ( visemesOnly )
    {
      if ( (unsigned __int8)this->visemeOffsetState == 255 )
        return;
      v6 = -1;
      goto LABEL_18;
    }
    if ( (unsigned __int8)this->offsetState == 255 )
      return;
    if ( (unsigned __int8)this->visemeOffsetState == 255 )
      idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_FORWARDS, visemesOnly: true);
    v6 = -1;
  }
  this->offsetState = v6;
LABEL_18:
  this->visemeOffsetState = v6;
LABEL_19:
  v7 = 0;
  v8 = this->visemeOffsetMS * ofs;
  num = this->events.num;
  v10 = this->animEventOffsetMS * ofs;
  v11 = this->moodEventOffsetMS * ofs;
  v12 = this->gameEventOffsetMS * ofs;
  v13 = this->textEventOffsetMS * ofs;
  if ( !visemesOnly )
  {
    if ( num <= 0 )
      return;
    for ( i = 0; ; ++i )
    {
      Event = idVoiceEventManager::GetEvent(
                this: &this->voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[i]);
      eventType = Event->eventType;
      if ( eventType <= 6 )
        break;
LABEL_51:
      if ( ++v7 >= this->events.num )
        return;
    }
    if ( eventType != 1 )
    {
      if ( eventType == 2 )
      {
        v21 = v12 + Event->startMS;
LABEL_50:
        Event->startMS = v21;
        goto LABEL_51;
      }
      if ( eventType == 3 && Event->eventType != 0 || eventType == 4 && Event->eventType != 0 )
      {
        v21 = v13 + Event->startMS;
        goto LABEL_50;
      }
      if ( eventType == 5 && Event->eventType != 0 )
      {
        v21 = v10 + Event->startMS;
        goto LABEL_50;
      }
      if ( Event->eventType != 0 )
      {
        v21 = v11 + Event->startMS;
        goto LABEL_50;
      }
    }
    v21 = v8 + Event->startMS;
    goto LABEL_50;
  }
  if ( num > 0 )
  {
    for ( j = 0; ; ++j )
    {
      v15 = idVoiceEventManager::GetEvent(
              this: &this->voiceEventManager,
              handle: *(const vtrEventHandle_t **)&this->events.list[j]);
      v16 = v15->eventType;
      if ( v16 <= 4 )
      {
        if ( v16 == 1 )
          goto LABEL_28;
        if ( v16 != 2 )
          break;
      }
LABEL_31:
      if ( ++v7 >= this->events.num )
        return;
    }
    if ( v16 == 3 && v15->eventType != 0 || v15->eventType != 0 )
      v17 = v15->startMS + v13;
    else
LABEL_28:
      v17 = v15->startMS + v8;
    v15->startMS = v17;
    goto LABEL_31;
  }
}


// ========================================================================
// ?SetTrackTextId@idVoiceTrack@@QAAXVidStrId@@@Z
// EA  : 0x82636A50
// RVA : 0x00636A50
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::SetTrackTextId(idVoiceTrack *this, idStrId *id)
{
  idStrId *p_textId; // r30
  const char *LocalizedString; // r3
  const char *Key; // r3

  p_textId = &this->textId;
  this->textId = (idStrId)id->index;
  LocalizedString = idStrId::GetLocalizedString(this: &this->textId);
  this->textCRC = idVoiceTrack::CalcTextCRC(text: LocalizedString);
  if ( id->index >= 0 )
  {
    Key = idStrId::GetKey(this: p_textId);
    idAtomicString::Set(this: &this->textLangKey, str_: Key);
  }
}


// ========================================================================
// ?Write@idVoiceTrack@@QBAXAAVidFile_String@@@Z
// EA  : 0x82636AA8
// RVA : 0x00636AA8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::Write(idVoiceTrack *this, idFile_String *out)
{
  __int64 v4; // r10
  __int64 v5; // r6
  __int64 v6; // r8
  va *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  const idDeclVisemeSet *declVisemeSet; // r11
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  va *v15; // r3
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  __int64 v24; // r6
  __int64 v25; // r10
  __int64 v26; // r8
  va *v27; // r3
  __int64 v28; // r10
  __int64 v29; // r6
  __int64 v30; // r8
  va *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r6
  __int64 v34; // r8
  va *v35; // r3
  __int64 v36; // r8
  __int64 v37; // r6
  __int64 v38; // r10
  va *v39; // r3
  __int64 v40; // r8
  __int64 v41; // r6
  __int64 v42; // r10
  va *v43; // r3
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  va *v47; // r3
  __int64 v48; // r6
  __int64 v49; // r10
  __int64 v50; // r8
  va *v51; // r3
  __int64 v52; // r6
  __int64 v53; // r10
  __int64 v54; // r8
  va *v55; // r3
  __int64 v56; // r10
  __int64 v57; // r6
  __int64 v58; // r8
  va *v59; // r3
  __int64 v60; // r6
  __int64 v61; // r10
  __int64 v62; // r8
  va *v63; // r3
  __int64 v64; // r10
  __int64 v65; // r8
  __int64 v66; // r6
  const idSoundShader *soundShader; // r11
  va *v68; // r3
  __int64 v69; // r10
  __int64 v70; // r6
  __int64 v71; // r8
  va *v72; // r3
  __int64 v73; // r6
  __int64 v74; // r10
  __int64 v75; // r8
  va *v76; // r3
  __int64 v77; // r8
  __int64 v78; // r10
  __int64 v79; // r6
  va *v80; // r3
  __int64 v81; // r6
  __int64 v82; // r10
  __int64 v83; // r8
  va *v84; // r3
  __int64 v85; // r10
  __int64 v86; // r8
  __int64 v87; // r6
  faceChannel_t faceChannel; // r11
  va *v89; // r3
  __int64 v90; // r10
  __int64 v91; // r6
  __int64 v92; // r8
  va *v93; // r3
  __int64 v94; // r8
  __int64 v95; // r10
  __int64 v96; // r6
  va *v97; // r3
  __int64 v98; // r6
  __int64 v99; // r8
  __int64 v100; // r10
  va *v101; // r3
  __int64 v102; // r10
  __int64 v103; // r6
  __int64 v104; // r8
  va *v105; // r3
  __int64 v106; // r8
  __int64 v107; // r6
  __int64 v108; // r10
  va *v109; // r3
  __int64 v110; // r6
  __int64 v111; // r10
  __int64 v112; // r8
  va *v113; // r3
  __int64 v114; // r6
  __int64 v115; // r10
  __int64 v116; // r8
  va *v117; // r3
  __int64 v118; // r10
  __int64 v119; // r6
  __int64 v120; // r8
  va *v121; // r3
  int v122; // r28
  int v123; // r29
  const idVoiceEvent *Event; // r3
  const char *v125; // r11
  unsigned int v126; // r5
  int v127; // r5
  const char *v128; // r11
  int v129; // [sp+8h] [-1088h]
  int v130; // [sp+8h] [-1088h]
  int v131; // [sp+8h] [-1088h]
  int v132; // [sp+8h] [-1088h]
  int v133; // [sp+8h] [-1088h]
  int v134; // [sp+8h] [-1088h]
  int v135; // [sp+8h] [-1088h]
  int v136; // [sp+8h] [-1088h]
  int v137; // [sp+8h] [-1088h]
  int v138; // [sp+8h] [-1088h]
  int v139; // [sp+8h] [-1088h]
  int v140; // [sp+8h] [-1088h]
  int v141; // [sp+8h] [-1088h]
  int v142; // [sp+8h] [-1088h]
  int v143; // [sp+8h] [-1088h]
  int v144; // [sp+8h] [-1088h]
  int v145; // [sp+8h] [-1088h]
  int v146; // [sp+8h] [-1088h]
  int v147; // [sp+8h] [-1088h]
  int v148; // [sp+8h] [-1088h]
  int v149; // [sp+8h] [-1088h]
  int v150; // [sp+8h] [-1088h]
  int v151; // [sp+8h] [-1088h]
  int v152; // [sp+8h] [-1088h]
  int v153; // [sp+8h] [-1088h]
  int v154; // [sp+8h] [-1088h]
  int v155; // [sp+8h] [-1088h]
  int v156; // [sp+8h] [-1088h]
  int v157; // [sp+Ch] [-1084h]
  int v158; // [sp+Ch] [-1084h]
  int v159; // [sp+Ch] [-1084h]
  int v160; // [sp+Ch] [-1084h]
  int v161; // [sp+Ch] [-1084h]
  int v162; // [sp+Ch] [-1084h]
  int v163; // [sp+Ch] [-1084h]
  int v164; // [sp+Ch] [-1084h]
  int v165; // [sp+Ch] [-1084h]
  int v166; // [sp+Ch] [-1084h]
  int v167; // [sp+Ch] [-1084h]
  int v168; // [sp+Ch] [-1084h]
  int v169; // [sp+Ch] [-1084h]
  int v170; // [sp+Ch] [-1084h]
  int v171; // [sp+Ch] [-1084h]
  int v172; // [sp+Ch] [-1084h]
  int v173; // [sp+Ch] [-1084h]
  int v174; // [sp+Ch] [-1084h]
  int v175; // [sp+Ch] [-1084h]
  int v176; // [sp+Ch] [-1084h]
  int v177; // [sp+Ch] [-1084h]
  int v178; // [sp+Ch] [-1084h]
  int v179; // [sp+Ch] [-1084h]
  int v180; // [sp+Ch] [-1084h]
  int v181; // [sp+Ch] [-1084h]
  int v182; // [sp+Ch] [-1084h]
  int v183; // [sp+Ch] [-1084h]
  int v184; // [sp+Ch] [-1084h]
  int v185; // [sp+10h] [-1080h]
  int v186; // [sp+10h] [-1080h]
  int v187; // [sp+10h] [-1080h]
  int v188; // [sp+10h] [-1080h]
  int v189; // [sp+10h] [-1080h]
  int v190; // [sp+10h] [-1080h]
  int v191; // [sp+10h] [-1080h]
  int v192; // [sp+10h] [-1080h]
  int v193; // [sp+10h] [-1080h]
  int v194; // [sp+10h] [-1080h]
  int v195; // [sp+10h] [-1080h]
  int v196; // [sp+10h] [-1080h]
  int v197; // [sp+10h] [-1080h]
  int v198; // [sp+10h] [-1080h]
  int v199; // [sp+10h] [-1080h]
  int v200; // [sp+10h] [-1080h]
  int v201; // [sp+10h] [-1080h]
  int v202; // [sp+10h] [-1080h]
  int v203; // [sp+10h] [-1080h]
  int v204; // [sp+10h] [-1080h]
  int v205; // [sp+10h] [-1080h]
  int v206; // [sp+10h] [-1080h]
  int v207; // [sp+10h] [-1080h]
  int v208; // [sp+10h] [-1080h]
  int v209; // [sp+10h] [-1080h]
  int v210; // [sp+10h] [-1080h]
  int v211; // [sp+10h] [-1080h]
  int v212; // [sp+10h] [-1080h]
  int v213; // [sp+14h] [-107Ch]
  int v214; // [sp+14h] [-107Ch]
  int v215; // [sp+14h] [-107Ch]
  int v216; // [sp+14h] [-107Ch]
  int v217; // [sp+14h] [-107Ch]
  int v218; // [sp+14h] [-107Ch]
  int v219; // [sp+14h] [-107Ch]
  int v220; // [sp+14h] [-107Ch]
  int v221; // [sp+14h] [-107Ch]
  int v222; // [sp+14h] [-107Ch]
  int v223; // [sp+14h] [-107Ch]
  int v224; // [sp+14h] [-107Ch]
  int v225; // [sp+14h] [-107Ch]
  int v226; // [sp+14h] [-107Ch]
  int v227; // [sp+14h] [-107Ch]
  int v228; // [sp+14h] [-107Ch]
  int v229; // [sp+14h] [-107Ch]
  int v230; // [sp+14h] [-107Ch]
  int v231; // [sp+14h] [-107Ch]
  int v232; // [sp+14h] [-107Ch]
  int v233; // [sp+14h] [-107Ch]
  int v234; // [sp+14h] [-107Ch]
  int v235; // [sp+14h] [-107Ch]
  int v236; // [sp+14h] [-107Ch]
  int v237; // [sp+14h] [-107Ch]
  int v238; // [sp+14h] [-107Ch]
  int v239; // [sp+14h] [-107Ch]
  int v240; // [sp+14h] [-107Ch]
  int v241; // [sp+18h] [-1078h]
  int v242; // [sp+18h] [-1078h]
  int v243; // [sp+18h] [-1078h]
  int v244; // [sp+18h] [-1078h]
  int v245; // [sp+18h] [-1078h]
  int v246; // [sp+18h] [-1078h]
  int v247; // [sp+18h] [-1078h]
  int v248; // [sp+18h] [-1078h]
  int v249; // [sp+18h] [-1078h]
  int v250; // [sp+18h] [-1078h]
  int v251; // [sp+18h] [-1078h]
  int v252; // [sp+18h] [-1078h]
  int v253; // [sp+18h] [-1078h]
  int v254; // [sp+18h] [-1078h]
  int v255; // [sp+18h] [-1078h]
  int v256; // [sp+18h] [-1078h]
  int v257; // [sp+18h] [-1078h]
  int v258; // [sp+18h] [-1078h]
  int v259; // [sp+18h] [-1078h]
  int v260; // [sp+18h] [-1078h]
  int v261; // [sp+18h] [-1078h]
  int v262; // [sp+18h] [-1078h]
  int v263; // [sp+18h] [-1078h]
  int v264; // [sp+18h] [-1078h]
  int v265; // [sp+18h] [-1078h]
  int v266; // [sp+18h] [-1078h]
  int v267; // [sp+18h] [-1078h]
  int v268; // [sp+18h] [-1078h]
  int v269; // [sp+1Ch] [-1074h]
  int v270; // [sp+1Ch] [-1074h]
  int v271; // [sp+1Ch] [-1074h]
  int v272; // [sp+1Ch] [-1074h]
  int v273; // [sp+1Ch] [-1074h]
  int v274; // [sp+1Ch] [-1074h]
  int v275; // [sp+1Ch] [-1074h]
  int v276; // [sp+1Ch] [-1074h]
  int v277; // [sp+1Ch] [-1074h]
  int v278; // [sp+1Ch] [-1074h]
  int v279; // [sp+1Ch] [-1074h]
  int v280; // [sp+1Ch] [-1074h]
  int v281; // [sp+1Ch] [-1074h]
  int v282; // [sp+1Ch] [-1074h]
  int v283; // [sp+1Ch] [-1074h]
  int v284; // [sp+1Ch] [-1074h]
  int v285; // [sp+1Ch] [-1074h]
  int v286; // [sp+1Ch] [-1074h]
  int v287; // [sp+1Ch] [-1074h]
  int v288; // [sp+1Ch] [-1074h]
  int v289; // [sp+1Ch] [-1074h]
  int v290; // [sp+1Ch] [-1074h]
  int v291; // [sp+1Ch] [-1074h]
  int v292; // [sp+1Ch] [-1074h]
  int v293; // [sp+1Ch] [-1074h]
  int v294; // [sp+1Ch] [-1074h]
  int v295; // [sp+1Ch] [-1074h]
  int v296; // [sp+1Ch] [-1074h]
  double weightScale; // [sp+20h] [-1070h]
  va v298; // [sp+50h] [-1040h] BYREF

  idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_BACKWARDS, visemesOnly: false);
  LODWORD(v4) = &unk_821C0000;
  HIDWORD(v5) = idVoiceTrack::VOICE_TRACK_NAME;
  v7 = va::va(
         this: &v298,
         fmt: "%s {\n",
         a3: v5,
         a4: v6,
         a5: v4,
         a6: v129,
         a7: v157,
         a8: v185,
         a9: v213,
         a10: v241,
         a11: v269);
  idFile_String::operator+=(this: out, str: v7->buffer);
  declVisemeSet = this->declVisemeSet;
  if ( declVisemeSet != nullptr )
  {
    LODWORD(v8) = &unk_821C0000;
    HIDWORD(v10) = declVisemeSet->name.str;
    v12 = va::va(
            this: &v298,
            fmt: "\tvisemeSet \"%s\"\n",
            a3: v10,
            a4: v9,
            a5: v8,
            a6: v130,
            a7: v158,
            a8: v186,
            a9: v214,
            a10: v242,
            a11: v270);
    idFile_String::operator+=(this: out, str: v12->buffer);
  }
  LODWORD(v13) = &consoleFont[21088];
  HIDWORD(v13) = &unk_821C0000;
  LODWORD(v14) = idVoiceTrack::moodNames;
  HIDWORD(v14) = 4 * this->defaultMood;
  HIDWORD(v10) = *(const char **)((char *)idVoiceTrack::moodNames + HIDWORD(v14));
  v15 = va::va(
          this: &v298,
          fmt: "\tdefaultMood \"%s\"\n",
          a3: v10,
          a4: v14,
          a5: v13,
          a6: v130,
          a7: v158,
          a8: v186,
          a9: v214,
          a10: v242,
          a11: v270);
  idFile_String::operator+=(this: out, str: v15->buffer);
  weightScale = this->weightScale;
  HIDWORD(v16) = LODWORD(weightScale);
  LODWORD(v16) = &unk_821C0000;
  v19 = va::va(
          this: &v298,
          fmt: "\tweightScale %f\n",
          a3: v16,
          a4: v18,
          a5: v17,
          a6: v131,
          a7: v159,
          a8: v187,
          a9: v215,
          a10: v243,
          a11: v271);
  idFile_String::operator+=(this: out, str: v19->buffer);
  HIDWORD(v20) = this->soundOffsetMS;
  v23 = va::va(
          this: &v298,
          fmt: "\tsoundOffsetMS %d\n",
          a3: v20,
          a4: v22,
          a5: v21,
          a6: v132,
          a7: v160,
          a8: v188,
          a9: v216,
          a10: v244,
          a11: v272);
  idFile_String::operator+=(this: out, str: v23->buffer);
  HIDWORD(v24) = this->visemeOffsetMS;
  v27 = va::va(
          this: &v298,
          fmt: "\tvisemeOffsetMS %d\n",
          a3: v24,
          a4: v26,
          a5: v25,
          a6: v133,
          a7: v161,
          a8: v189,
          a9: v217,
          a10: v245,
          a11: v273);
  idFile_String::operator+=(this: out, str: v27->buffer);
  LODWORD(v28) = &unk_821C0000;
  HIDWORD(v29) = this->animEventOffsetMS;
  v31 = va::va(
          this: &v298,
          fmt: "\tanimEventOffsetMS %d\n",
          a3: v29,
          a4: v30,
          a5: v28,
          a6: v134,
          a7: v162,
          a8: v190,
          a9: v218,
          a10: v246,
          a11: v274);
  idFile_String::operator+=(this: out, str: v31->buffer);
  HIDWORD(v32) = &unk_821C0000;
  HIDWORD(v33) = this->moodEventOffsetMS;
  v35 = va::va(
          this: &v298,
          fmt: "\tmoodEventOffsetMS %d\n",
          a3: v33,
          a4: v34,
          a5: v32,
          a6: v135,
          a7: v163,
          a8: v191,
          a9: v219,
          a10: v247,
          a11: v275);
  idFile_String::operator+=(this: out, str: v35->buffer);
  LODWORD(v36) = &unk_821C0000;
  HIDWORD(v37) = this->gameEventOffsetMS;
  v39 = va::va(
          this: &v298,
          fmt: "\tgameEventOffsetMS %d\n",
          a3: v37,
          a4: v36,
          a5: v38,
          a6: v136,
          a7: v164,
          a8: v192,
          a9: v220,
          a10: v248,
          a11: v276);
  idFile_String::operator+=(this: out, str: v39->buffer);
  HIDWORD(v40) = &unk_821C0000;
  HIDWORD(v41) = this->textEventOffsetMS;
  v43 = va::va(
          this: &v298,
          fmt: "\ttextEventOffsetMS %d\n",
          a3: v41,
          a4: v40,
          a5: v42,
          a6: v137,
          a7: v165,
          a8: v193,
          a9: v221,
          a10: v249,
          a11: v277);
  idFile_String::operator+=(this: out, str: v43->buffer);
  LODWORD(v44) = &unk_821C0000;
  HIDWORD(v44) = (*(_BYTE *)&this->flags & 4) != 0;
  v47 = va::va(
          this: &v298,
          fmt: "\tedited %d\n",
          a3: v44,
          a4: v46,
          a5: v45,
          a6: v138,
          a7: v166,
          a8: v194,
          a9: v222,
          a10: v250,
          a11: v278);
  idFile_String::operator+=(this: out, str: v47->buffer);
  idFile_String::operator+=(this: out, str: "\ttext {\n");
  HIDWORD(v48) = this->textLangKey.str;
  v51 = va::va(
          this: &v298,
          fmt: "\t\tid \"%s\"\n",
          a3: v48,
          a4: v50,
          a5: v49,
          a6: v139,
          a7: v167,
          a8: v195,
          a9: v223,
          a10: v251,
          a11: v279);
  idFile_String::operator+=(this: out, str: v51->buffer);
  HIDWORD(v52) = this->textCRC;
  v55 = va::va(
          this: &v298,
          fmt: "\t\tcrc %u\n",
          a3: v52,
          a4: v54,
          a5: v53,
          a6: v140,
          a7: v168,
          a8: v196,
          a9: v224,
          a10: v252,
          a11: v280);
  idFile_String::operator+=(this: out, str: v55->buffer);
  LODWORD(v56) = &unk_821C0000;
  HIDWORD(v57) = this->lipsyncTextCRC;
  v59 = va::va(
          this: &v298,
          fmt: "\t\tlipsyncTextCrc %u\n",
          a3: v57,
          a4: v58,
          a5: v56,
          a6: v141,
          a7: v169,
          a8: v197,
          a9: v225,
          a10: v253,
          a11: v281);
  idFile_String::operator+=(this: out, str: v59->buffer);
  idFile_String::operator+=(this: out, str: "\t}\n");
  idFile_String::operator+=(this: out, str: "\tsubtitles {\n");
  HIDWORD(v60) = this->subtitleLangKey.str;
  v63 = va::va(
          this: &v298,
          fmt: "\t\tid \"%s\"\n",
          a3: v60,
          a4: v62,
          a5: v61,
          a6: v142,
          a7: v170,
          a8: v198,
          a9: v226,
          a10: v254,
          a11: v282);
  idFile_String::operator+=(this: out, str: v63->buffer);
  idFile_String::operator+=(this: out, str: "\t}\n");
  idFile_String::operator+=(this: out, str: "\tsound {\n");
  soundShader = this->soundShader;
  if ( soundShader != nullptr )
    HIDWORD(v66) = soundShader->name.str;
  else
    HIDWORD(v66) = &byte_8200D768;
  v68 = va::va(
          this: &v298,
          fmt: "\t\tshader \"%s\"\n",
          a3: v66,
          a4: v65,
          a5: v64,
          a6: v143,
          a7: v171,
          a8: v199,
          a9: v227,
          a10: v255,
          a11: v283);
  idFile_String::operator+=(this: out, str: v68->buffer);
  LODWORD(v69) = &unk_821C0000;
  HIDWORD(v70) = this->sampleTimestamp;
  v72 = va::va(
          this: &v298,
          fmt: "\t\ttimestamp %u\n",
          a3: v70,
          a4: v71,
          a5: v69,
          a6: v144,
          a7: v172,
          a8: v200,
          a9: v228,
          a10: v256,
          a11: v284);
  idFile_String::operator+=(this: out, str: v72->buffer);
  HIDWORD(v73) = this->sampleCRC;
  v76 = va::va(
          this: &v298,
          fmt: "\t\tcrc %u\n",
          a3: v73,
          a4: v75,
          a5: v74,
          a6: v145,
          a7: v173,
          a8: v201,
          a9: v229,
          a10: v257,
          a11: v285);
  idFile_String::operator+=(this: out, str: v76->buffer);
  LODWORD(v77) = (unsigned __int8)this->flags;
  HIDWORD(v78) = &unk_821C0000;
  HIDWORD(v79) = (v77 & 8) != 0;
  v80 = va::va(
          this: &v298,
          fmt: "\t\tcompressed %d\n",
          a3: v79,
          a4: v77,
          a5: v78,
          a6: v146,
          a7: v174,
          a8: v202,
          a9: v230,
          a10: v258,
          a11: v286);
  idFile_String::operator+=(this: out, str: v80->buffer);
  idFile_String::operator+=(this: out, str: "\t}\n");
  idFile_String::operator+=(this: out, str: "\tanim {\n");
  LODWORD(v81) = &unk_821C0000;
  HIDWORD(v81) = this->animName.data;
  v84 = va::va(
          this: &v298,
          fmt: "\t\talias \"%s\"\n",
          a3: v81,
          a4: v83,
          a5: v82,
          a6: v147,
          a7: v175,
          a8: v203,
          a9: v231,
          a10: v259,
          a11: v287);
  idFile_String::operator+=(this: out, str: v84->buffer);
  faceChannel = this->faceChannel;
  if ( (unsigned int)faceChannel > FACECHANNEL_USER_CHANNEL )
  {
    LODWORD(v85) = &unk_821C0000;
    *(const char **)&v87 = idVoiceTrack::faceChannelNames[0];
  }
  else
  {
    LODWORD(v85) = &consoleFont[21088];
    HIDWORD(v85) = 4 * faceChannel;
    LODWORD(v86) = idVoiceTrack::faceChannelNames;
    HIDWORD(v86) = &unk_821C0000;
    HIDWORD(v87) = idVoiceTrack::faceChannelNames[faceChannel];
  }
  v89 = va::va(
          this: &v298,
          fmt: "\t\tchannel \"%s\"\n",
          a3: v87,
          a4: v86,
          a5: v85,
          a6: v148,
          a7: v176,
          a8: v204,
          a9: v232,
          a10: v260,
          a11: v288);
  idFile_String::operator+=(this: out, str: v89->buffer);
  LODWORD(v90) = &unk_821C0000;
  HIDWORD(v91) = this->blendInMS;
  v93 = va::va(
          this: &v298,
          fmt: "\t\tblendInMS %d\n",
          a3: v91,
          a4: v92,
          a5: v90,
          a6: v149,
          a7: v177,
          a8: v205,
          a9: v233,
          a10: v261,
          a11: v289);
  idFile_String::operator+=(this: out, str: v93->buffer);
  LODWORD(v94) = (unsigned __int16)this->blendOutMS;
  HIDWORD(v95) = &unk_821C0000;
  HIDWORD(v96) = (__int16)v94;
  v97 = va::va(
          this: &v298,
          fmt: "\t\tblendOutMS %d\n",
          a3: v96,
          a4: v94,
          a5: v95,
          a6: v150,
          a7: v178,
          a8: v206,
          a9: v234,
          a10: v262,
          a11: v290);
  idFile_String::operator+=(this: out, str: v97->buffer);
  LODWORD(v98) = (unsigned __int8)this->flags;
  HIDWORD(v99) = &unk_821C0000;
  HIDWORD(v98) = (v98 & 0x80) != 0;
  v101 = va::va(
           this: &v298,
           fmt: "\t\tcycle %d\n",
           a3: v98,
           a4: v99,
           a5: v100,
           a6: v151,
           a7: v179,
           a8: v207,
           a9: v235,
           a10: v263,
           a11: v291);
  idFile_String::operator+=(this: out, str: v101->buffer);
  HIDWORD(v102) = (unsigned __int8)this->flags;
  LODWORD(v102) = &unk_821C0000;
  HIDWORD(v103) = (v102 & 0x4000000000LL) != 0;
  v105 = va::va(
           this: &v298,
           fmt: "\t\tclear %d\n",
           a3: v103,
           a4: v104,
           a5: v102,
           a6: v152,
           a7: v180,
           a8: v208,
           a9: v236,
           a10: v264,
           a11: v292);
  idFile_String::operator+=(this: out, str: v105->buffer);
  HIDWORD(v106) = (unsigned __int8)this->flags;
  LODWORD(v106) = &unk_821C0000;
  HIDWORD(v107) = (v106 & 0x2000000000LL) != 0;
  v109 = va::va(
           this: &v298,
           fmt: "\t\tnolipsync %d\n",
           a3: v107,
           a4: v106,
           a5: v108,
           a6: v153,
           a7: v181,
           a8: v209,
           a9: v237,
           a10: v265,
           a11: v293);
  idFile_String::operator+=(this: out, str: v109->buffer);
  LODWORD(v110) = &unk_821C0000;
  HIDWORD(v110) = (*(_BYTE *)&this->flags & 0x10) != 0;
  v113 = va::va(
           this: &v298,
           fmt: "\t\tsuppressBlinking %d\n",
           a3: v110,
           a4: v112,
           a5: v111,
           a6: v154,
           a7: v182,
           a8: v210,
           a9: v238,
           a10: v266,
           a11: v294);
  idFile_String::operator+=(this: out, str: v113->buffer);
  HIDWORD(v114) = (*(_BYTE *)&this->flags & 2) != 0;
  v117 = va::va(
           this: &v298,
           fmt: "\t\tuseRealTime %d\n",
           a3: v114,
           a4: v116,
           a5: v115,
           a6: v155,
           a7: v183,
           a8: v211,
           a9: v239,
           a10: v267,
           a11: v295);
  idFile_String::operator+=(this: out, str: v117->buffer);
  idFile_String::operator+=(this: out, str: "\t}\n");
  LODWORD(v118) = &unk_821C0000;
  HIDWORD(v119) = this->events.num;
  v121 = va::va(
           this: &v298,
           fmt: "\tevents %d {\n",
           a3: v119,
           a4: v120,
           a5: v118,
           a6: v156,
           a7: v184,
           a8: v212,
           a9: v240,
           a10: v268,
           a11: v296);
  idFile_String::operator+=(this: out, str: v121->buffer);
  v122 = 0;
  if ( this->events.num > 0 )
  {
    v123 = 0;
    do
    {
      Event = idVoiceEventManager::GetEvent(
                this: &this->voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[v123]);
      Event->Write(this: (idVoiceEvent *)Event, a2: this, a3: out);
      ++v122;
      ++v123;
    }
    while ( v122 < this->events.num );
  }
  v125 = "\t}\n";
  v126 = 0;
  do
  {
    ++v125;
    ++v126;
  }
  while ( *v125 != 0 );
  out->Write(this: out, a2: "\t}\n", a3: v126);
  v127 = 0;
  v128 = "}\n";
  do
  {
    ++v128;
    ++v127;
  }
  while ( *v128 != 0 );
  ((void (__fastcall *)(idFile_String *))out->Write)(a1: out);
  idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_FORWARDS, visemesOnly: false);
}


// ========================================================================
// ?FindLastEvent@idVoiceTrack@@QBAHXZ
// EA  : 0x826370C0
// RVA : 0x006370C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::FindLastEvent(idVoiceTrack *this)
{
  int v2; // r29
  int v3; // r26
  int v4; // r28
  idVoiceEventManager *p_voiceEventManager; // r27
  int v6; // r30
  const idVoiceEvent *Event; // r3
  int startMS; // r10

  v2 = -1;
  v3 = -1;
  v4 = 0;
  if ( this->events.num > 0 )
  {
    p_voiceEventManager = &this->voiceEventManager;
    v6 = 0;
    do
    {
      Event = idVoiceEventManager::GetEvent(
                this: p_voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[v6]);
      startMS = Event->startMS;
      if ( Event->durationMS + startMS >= v2 )
      {
        v2 = Event->durationMS + startMS;
        v3 = v4;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->events.num );
  }
  return v3;
}


// ========================================================================
// ?FindNextEventForFrame@idVoiceTrack@@AAAHHH@Z
// EA  : 0x82637140
// RVA : 0x00637140
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::FindNextEventForFrame(idVoiceTrack *this, const int startIndex, const int frame)
{
  int v3; // r28
  int v4; // r29
  int v6; // r26
  idVoiceEventManager *p_voiceEventManager; // r27
  int i; // r30
  idVoiceEvent *Event; // r3

  v3 = 66 * frame;
  v4 = startIndex + 1;
  v6 = 66 * frame + 66;
  if ( startIndex + 1 >= this->events.num )
    return -1;
  p_voiceEventManager = &this->voiceEventManager;
  for ( i = v4; ; ++i )
  {
    Event = idVoiceEventManager::GetEvent(
              this: p_voiceEventManager,
              handle: *(const vtrEventHandle_t **)&this->events.list[i]);
    if ( Event->IsWithinInterval(this: Event, a2: v3, a3: v6) )
      break;
    if ( ++v4 >= this->events.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?IsCustomized@idVoiceTrack@@QBA_NXZ
// EA  : 0x826371D0
// RVA : 0x006371D0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::IsCustomized(idVoiceTrack *this)
{
  idVoiceTrack::flags_t flags; // r11
  int v3; // r28
  idVoiceEventManager *p_voiceEventManager; // r29
  int i; // r30
  const idVoiceEvent *Event; // r3

  flags = this->flags;
  if ( (*(_BYTE *)&flags & 4) == 0
    && this->animName.len == 0
    && (*(_BYTE *)&this->flags & 0x80) != 0x80
    && (*(_BYTE *)&flags & 0x40) != 0x40
    && (*(_BYTE *)&flags & 0x20) != 0x20
    && (*(_BYTE *)&flags & 0x10) != 0x10
    && this->weightScale == 1.0
    && this->defaultMood == MOOD_NONE
    && this->soundOffsetMS == 66
    && this->visemeOffsetMS == 0
    && this->animEventOffsetMS == 0
    && this->moodEventOffsetMS == 0
    && this->gameEventOffsetMS == 0
    && this->textEventOffsetMS == 0 )
  {
    v3 = 0;
    if ( this->events.num <= 0 )
      return 0;
    p_voiceEventManager = &this->voiceEventManager;
    for ( i = 0; ; ++i )
    {
      Event = idVoiceEventManager::GetEvent(
                this: p_voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[i]);
      if ( Event->eventType == 2 || Event->eventType > 4u && Event->eventType <= 6u )
        break;
      if ( ++v3 >= this->events.num )
        return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?FindApproximateDuration@idVoiceTrack@@QBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@XZ
// EA  : 0x82637308
// RVA : 0x00637308
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idVoiceTrack *__fastcall idVoiceTrack::FindApproximateDuration(
        idVoiceTrack *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result)
{
  idSoundShader *value; // r3
  int MaxLength; // r3
  int v6; // r27
  int v7; // r10
  int v8; // r30
  const idVoiceEvent *Event; // r3
  idVoiceTrack_vtbl *v10; // r11

  value = (idSoundShader *)result[48].value;
  if ( value != nullptr )
    MaxLength = idSoundShader::GetMaxLength(this: value);
  else
    MaxLength = 0;
  v6 = 0;
  v7 = result[10].value;
  this->__vftable = (idVoiceTrack_vtbl *)(result[61].value + MaxLength);
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      Event = idVoiceEventManager::GetEvent(
                this: (idVoiceEventManager *)&result[13],
                handle: *(const vtrEventHandle_t **)(result[9].value + v8));
      v10 = (idVoiceTrack_vtbl *)(Event->durationMS + Event->startMS);
      if ( (int)v10 > (int)this->__vftable )
        this->__vftable = v10;
      ++v6;
      v8 += 4;
    }
    while ( v6 < result[10].value );
  }
  return this;
}


// ========================================================================
// ?Read@idFrameRefIndexBuffer@idVoiceTrack@@QAAXPAVidFile@@@Z
// EA  : 0x82637920
// RVA : 0x00637920
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::idFrameRefIndexBuffer::Read(idVoiceTrack::idFrameRefIndexBuffer *this, idFile *file)
{
  unsigned __int16 *indices; // r4
  unsigned int v5; // r5
  unsigned __int16 v6; // [sp+50h] [-20h] BYREF
  unsigned __int16 v7[3]; // [sp+52h] [-1Eh] BYREF

  file->Read(this: file, a2: &v6, a3: 2u);
  file->Read(this: file, a2: v7, a3: 2u);
  idVoiceTrack::idFrameRefIndexBuffer::Alloc(this, size: v6);
  indices = this->indices;
  v5 = __ROL4__(this->size, 1);
  this->curOffset = v7[0];
  file->Read(this: file, a2: indices, a3: v5);
}


// ========================================================================
// ?IsSampleStale@idVoiceTrack@@QBA_NXZ
// EA  : 0x826379C0
// RVA : 0x006379C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

BOOL __fastcall idVoiceTrack::IsSampleStale(idVoiceTrack *this)
{
  const idSoundShader *soundShader; // r11
  idSoundSample_XAudio2 *v4; // r3

  soundShader = this->soundShader;
  if ( soundShader != nullptr && soundShader->entries.num > 0 )
  {
    v4 = *soundShader->entries.list;
    if ( v4 != nullptr )
    {
      if ( v4->format.basic.formatTag - 1 - (v4->format.basic.formatTag - 2 + (v4->format.basic.formatTag == 1)) != ((*(_BYTE *)&this->flags & 8) != 0) )
        return false;
      if ( this->sampleTimestamp >= v4->timestamp )
        return idSoundSample_XAudio2::GetCRC32(this: v4) != this->sampleCRC;
    }
  }
  return true;
}


// ========================================================================
// ?IsStale@idVoiceTrack@@QBA_NXZ
// EA  : 0x82637A88
// RVA : 0x00637A88
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::IsStale(idVoiceTrack *this)
{
  const char *LocalizedString; // r3
  bool IsSampleStale; // r3
  unsigned __int8 v4; // r11

  LocalizedString = idStrId::GetLocalizedString(this: &this->textId);
  if ( idVoiceTrack::CalcTextCRC(text: LocalizedString) != this->textCRC )
    return 1;
  IsSampleStale = idVoiceTrack::IsSampleStale(this);
  v4 = 0;
  if ( IsSampleStale )
    return 1;
  return v4;
}


// ========================================================================
// ?FreeVisemeEvents@idVoiceTrack@@QAAX_N@Z
// EA  : 0x82637AE8
// RVA : 0x00637AE8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::FreeVisemeEvents(idVoiceTrack *this, bool freeTextToo)
{
  idVoiceTrack::idFrameRef *frameRefs; // r4

  idVoiceEventManager::FreeVisemeEvents(
    this: &this->voiceEventManager,
    events: (idList<vtrEventHandle_t,5> *)&this->events,
    freeTextToo);
  frameRefs = this->frameRefs;
  if ( frameRefs != nullptr )
  {
    idMem::Free(this: &mem, ptr: frameRefs, align: ALIGN_16);
    this->frameRefs = nullptr;
  }
  this->visemeOffsetState = 0;
}


// ========================================================================
// ?FreeTextEvents@idVoiceTrack@@AAAXXZ
// EA  : 0x82637B50
// RVA : 0x00637B50
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::FreeTextEvents(idVoiceTrack *this)
{
  idVoiceTrack::idFrameRef *frameRefs; // r4

  idVoiceEventManager::FreeTextEvents(
    this: &this->voiceEventManager,
    events: (idList<vtrEventHandle_t,5> *)&this->events);
  frameRefs = this->frameRefs;
  if ( frameRefs != nullptr )
  {
    idMem::Free(this: &mem, ptr: frameRefs, align: ALIGN_16);
    this->frameRefs = nullptr;
  }
}


// ========================================================================
// ?OffsetVisemeEvents@idVoiceTrack@@QAAXW4eventOffset_t@1@@Z
// EA  : 0x82637BA8
// RVA : 0x00637BA8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::OffsetVisemeEvents(idVoiceTrack *this, idVoiceTrack::eventOffset_t ofs)
{
  idVoiceTrack::OffsetEvents(this, ofs, visemesOnly: true);
}


// ========================================================================
// ?Save@idVoiceTrack@@QBA_NPBD@Z
// EA  : 0x82637BB8
// RVA : 0x00637BB8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

BOOL __fastcall idVoiceTrack::Save(idVoiceTrack *this, const char *fileName)
{
  idFileSystem_vtbl *v4; // r30
  char *filePtr; // r27
  unsigned int v6; // r3
  int v7; // r30
  BOOL v8; // r30
  idFile_Memory v10; // [sp+50h] [-180h] BYREF

  idFile_Memory::idFile_Memory(this: &v10, name: fileName);
  v10.__vftable = (idFile_Memory_vtbl *)&idFile_String::`vftable';
  idVoiceTrack::Write(this, out: (idFile_String *)&v10);
  v4 = fileSystem->__vftable;
  filePtr = v10.filePtr;
  v6 = (unsigned __int64)idFile_Memory::Length(this: &v10) >> 32;
  v7 = v4->WriteFile(this: fileSystem, a2: fileName, a3: filePtr, a4: v6, a5: FSPATH_BASE);
  v8 = (_cntlzw(((unsigned __int64)idFile_Memory::Length(this: &v10) >> 32) - v7) & 0x20) != 0;
  idFile_Memory::~idFile_Memory(this: &v10);
  return v8;
}


// ========================================================================
// __unwind$225718
// EA  : 0x82637C58
// RVA : 0x00637C58
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_225718()
{
  int v0; // r12

  idFile_String::~idFile_String(this: (idFile_String *)(v0 - 464 + 80));
}


// ========================================================================
// ?SetSoundShader@idVoiceTrack@@QAAXPBVidSoundShader@@@Z
// EA  : 0x82637C80
// RVA : 0x00637C80
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::SetSoundShader(idVoiceTrack *this, const idSoundShader *shader)
{
  idSoundSample *v2; // r11

  this->soundShader = shader;
  if ( shader != nullptr && shader->entries.num > 0 && (v2 = *shader->entries.list) != nullptr )
  {
    this->sampleTimestamp = v2->timestamp;
    if ( shader->entries.num <= 0 )
      this->sampleCRC = idSoundSample_XAudio2::GetCRC32(this: nullptr);
    else
      this->sampleCRC = idSoundSample_XAudio2::GetCRC32(this: *shader->entries.list);
  }
  else
  {
    this->sampleTimestamp = 0;
    this->sampleCRC = 0;
  }
}


// ========================================================================
// ?WriteBinary@idVoiceTrack@@QBA_NPBD@Z
// EA  : 0x82637D40
// RVA : 0x00637D40
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::WriteBinary(idVoiceTrack *this, const char *fileName)
{
  int v5; // r28
  int v6; // r27
  idFile *file; // r24
  idVoiceTrack::idFrameRef *v8; // r26
  int v9; // r29
  int v10; // r28
  char v11; // [sp+50h] [-60h] BYREF
  bool v12; // [sp+51h] [-5Fh] BYREF
  bool v13; // [sp+52h] [-5Eh] BYREF
  bool v14; // [sp+53h] [-5Dh] BYREF
  bool v15; // [sp+54h] [-5Ch] BYREF
  bool v16[3]; // [sp+55h] [-5Bh] BYREF
  idFileLocal v17; // [sp+58h] [-58h] BYREF
  int num; // [sp+5Ch] [-54h] BYREF

  v17.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  if ( v17.file != nullptr )
  {
    idLib::Printf(fmt: "Writing %s\n", fileName);
    v17.file->Write(this: v17.file, a2: &idVoiceTrack::VTR_MAGIC, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->timestamp, a3: 4u);
    idFile::WriteString(this: v17.file, string: this->declVisemeSet->name.str);
    idFile::WriteString(this: v17.file, string: this->textLangKey.str);
    v17.file->Write(this: v17.file, a2: &this->textCRC, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->lipsyncTextCRC, a3: 4u);
    idFile::WriteString(this: v17.file, string: this->subtitleLangKey.str);
    idFile::WriteString(this: v17.file, string: this->soundShader->name.str);
    v17.file->Write(this: v17.file, a2: &this->sampleTimestamp, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->sampleCRC, a3: 4u);
    idFile::WriteString(this: v17.file, string: &this->animName);
    v17.file->Write(this: v17.file, a2: &this->faceChannel, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->blendInMS, a3: 2u);
    v17.file->Write(this: v17.file, a2: &this->blendOutMS, a3: 2u);
    v17.file->Write(this: v17.file, a2: &this->soundOffsetMS, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->visemeOffsetMS, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->animEventOffsetMS, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->moodEventOffsetMS, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->gameEventOffsetMS, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->textEventOffsetMS, a3: 4u);
    v11 = *(_BYTE *)&this->flags >> 7;
    v17.file->Write(this: v17.file, a2: &v11, a3: 1u);
    v12 = (*(_BYTE *)&this->flags & 0x40) != 0;
    v17.file->Write(this: v17.file, a2: &v12, a3: 1u);
    v13 = (*(_BYTE *)&this->flags & 0x20) != 0;
    v17.file->Write(this: v17.file, a2: &v13, a3: 1u);
    v14 = (*(_BYTE *)&this->flags & 0x10) != 0;
    v17.file->Write(this: v17.file, a2: &v14, a3: 1u);
    v15 = (*(_BYTE *)&this->flags & 8) != 0;
    v17.file->Write(this: v17.file, a2: &v15, a3: 1u);
    v16[0] = (*(_BYTE *)&this->flags & 4) != 0;
    v17.file->Write(this: v17.file, a2: v16, a3: 1u);
    v17.file->Write(this: v17.file, a2: &this->weightScale, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->defaultMood, a3: 4u);
    v17.file->Write(this: v17.file, a2: &this->approximateDuration, a3: 4u);
    idVoiceTrack::idFrameRefIndexBuffer::Write(this: &this->indexBuffer, file: v17.file);
    v17.file->Write(this: v17.file, a2: &this->numFrameRefs, a3: 2u);
    v5 = 0;
    if ( this->numFrameRefs > 0 )
    {
      v6 = 0;
      do
      {
        file = v17.file;
        v8 = &this->frameRefs[v6];
        v17.file->Write(this: v17.file, a2: v8, a3: 2u);
        file->Write(this: file, a2: &v8->numIndices, a3: 2u);
        ++v5;
        ++v6;
      }
      while ( v5 < this->numFrameRefs );
    }
    idVoiceEventManager::WriteBinary(this: &this->voiceEventManager, file: v17.file);
    num = this->events.num;
    v17.file->Write(this: v17.file, a2: &num, a3: 4u);
    v9 = 0;
    if ( this->events.num > 0 )
    {
      v10 = 0;
      do
      {
        vtrEventHandle_t::WriteBinary(this: &this->events.list[v10], file: v17.file);
        ++v9;
        ++v10;
      }
      while ( v9 < this->events.num );
    }
    v17.file->Write(this: v17.file, a2: &idVoiceTrack::VTR_MAGIC, a3: 4u);
    idFileLocal::~idFileLocal(this: &v17);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Could not open '%s' for writing", fileName);
    idFileLocal::~idFileLocal(this: &v17);
    return 0;
  }
}


// ========================================================================
// __unwind$225863
// EA  : 0x82638218
// RVA : 0x00638218
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_225863()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 176 + 88));
}


// ========================================================================
// ?LoadAnims@idVoiceTrack@@AAAXXZ
// EA  : 0x82638248
// RVA : 0x00638248
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::LoadAnims(idVoiceTrack *this)
{
  int v1; // r28
  int len; // r9
  idStr *p_animName; // r3
  int i; // r27
  const vtrEventHandle_t **v6; // r11
  const vtrEventHandle_t *v7; // r4
  idVoiceEvent *Event; // r29
  _DWORD v9[4]; // [sp+50h] [-90h] BYREF
  idStr v10; // [sp+60h] [-80h] BYREF
  idStr v11[3]; // [sp+80h] [-60h] BYREF

  v1 = 0;
  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  len = this->animName.len;
  p_animName = &this->animName;
  if ( len != 0 )
  {
    idStr::ExtractFileExtension(this: p_animName, dest: &v10);
    if ( v10.len != 0 )
      idMD6Anim::LoadAnim_UserChannels(filename: this->animName.data);
    else
      ((void (__fastcall *)(_DWORD *))animation->AddStrongAliasRef)(a1: v9);
  }
  for ( i = 0; i < this->events.num; ++v1 )
  {
    v6 = (const vtrEventHandle_t **)&this->events.list[v1];
    if ( *(_WORD *)v6 == 5 )
    {
      v7 = *v6;
      v9[1] = &this->events.list[v1];
      Event = idVoiceEventManager::GetEvent(this: &this->voiceEventManager, handle: v7);
      idStr::idStr(this: v11, text: (const char *)Event[1].__vftable);
      if ( v11[0].len != 0 )
      {
        idStr::ExtractFileExtension(this: v11, dest: &v10);
        if ( v10.len != 0 )
          idMD6Anim::LoadAnim_UserChannels(filename: (const char *)Event[1].__vftable);
        else
          ((void (__fastcall *)(_DWORD *))animation->AddStrongAliasRef)(a1: v9);
      }
      idStr::FreeData(this: v11);
    }
    ++i;
  }
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$226169
// EA  : 0x82638384
// RVA : 0x00638384
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226169()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$226170
// EA  : 0x826383AC
// RVA : 0x006383AC
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226170()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?GetFacialAnimationEvent@idVoiceTrack@@QAAPAVidVoiceAnimEvent@@PAVvtrEventHandle_t@@@Z
// EA  : 0x826383D8
// RVA : 0x006383D8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idVoiceAnimEvent *__fastcall idVoiceTrack::GetFacialAnimationEvent(
        idVoiceTrack *this,
        const vtrEventHandle_t **eventHandle_)
{
  int num; // r26
  int v5; // r27
  idVoiceEventManager *p_voiceEventManager; // r28
  int i; // r31
  const vtrEventHandle_t *v8; // r29
  idVoiceAnimEvent *result; // r3

  num = this->events.num;
  v5 = 0;
  if ( num <= 0 )
    return nullptr;
  p_voiceEventManager = &this->voiceEventManager;
  for ( i = 0; ; ++i )
  {
    v8 = (const vtrEventHandle_t *)this->events.list[i];
    result = (idVoiceAnimEvent *)idVoiceEventManager::GetEvent(this: p_voiceEventManager, handle: v8);
    if ( result != nullptr && result->eventType == 5 && result->channel == 10 )
      break;
    if ( ++v5 >= num )
      return nullptr;
  }
  if ( eventHandle_ != nullptr )
    *eventHandle_ = v8;
  return result;
}


// ========================================================================
// ?Memory@idVoiceTrack@@QBAIXZ
// EA  : 0x82638468
// RVA : 0x00638468
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::Memory(idVoiceTrack *this)
{
  return 4 * (this->numFrameRefs + this->events.size + 73);
}


// ========================================================================
// ?FindExactDuration@idVoiceTrack@@QBA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@PBVidDeclMD6@@@Z
// EA  : 0x82638488
// RVA : 0x00638488
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idVoiceTrack *__fastcall idVoiceTrack::FindExactDuration(
        idVoiceTrack *this,
        idTypesafeNumber<int,enum millisecondUnique_t> *result,
        const idDeclMD6 *declMD6)
{
  idSoundShader *value; // r3
  int MaxLength; // r3
  idVoiceTrack_vtbl *v8; // r24
  idVoiceTrack_vtbl *v9; // r11
  int v11; // r25
  int v12; // r28
  const idVoiceEvent *Event; // r3
  const idVoiceEvent *v14; // r31
  idVoiceTrack_vtbl *startMS; // r30
  const idMD6Alias *Alias; // r3
  idResource *v17; // r3
  int trackedMemory; // r11
  int v19; // r10
  signed int v20; // r11
  int v21; // r10

  value = (idSoundShader *)result[48].value;
  if ( value != nullptr )
    MaxLength = idSoundShader::GetMaxLength(this: value);
  else
    MaxLength = 0;
  v8 = (idVoiceTrack_vtbl *)(result[61].value + MaxLength);
  if ( declMD6 != nullptr )
  {
    v11 = 0;
    if ( result[10].value > 0 )
    {
      v12 = 0;
      do
      {
        Event = idVoiceEventManager::GetEvent(
                  this: (idVoiceEventManager *)&result[13],
                  handle: *(const vtrEventHandle_t **)(result[9].value + v12));
        v14 = Event;
        startMS = (idVoiceTrack_vtbl *)Event->startMS;
        if ( Event->eventType == 5 )
        {
          Alias = idDeclMD6::FindAlias(
                    this: declMD6,
                    aliasName: (const char *)Event[1].__vftable,
                    includeInherited: true);
          if ( Alias != nullptr
            && (v17 = idResourceList::Load(
                        this: &idMD6Anim::resourceList,
                        name: Alias->animRefs.list->str,
                        makeDefault: false,
                        skipStaleCheck: true)) != nullptr
            || (v17 = idResourceList::Load(
                        this: &idMD6Anim::resourceList,
                        name: (const char *)v14[1].__vftable,
                        makeDefault: false,
                        skipStaleCheck: true)) != nullptr )
          {
            trackedMemory = v17[1].trackedMemory;
            v19 = 0;
            if ( trackedMemory != 0 )
            {
              v19 = *(unsigned __int16 *)(trackedMemory + 8);
              v20 = *(unsigned __int16 *)(trackedMemory + 10);
            }
            else
            {
              v20 = 30;
            }
            v21 = 1000 * v19;
            __twllei(v20, 0);
            startMS = (idVoiceTrack_vtbl *)((char *)startMS + v21 / v20);
            __twlgei(v20 & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
          }
        }
        else
        {
          startMS = (idVoiceTrack_vtbl *)((char *)startMS + Event->durationMS);
        }
        if ( (int)startMS > (int)v8 )
          v8 = startMS;
        ++v11;
        v12 += 4;
      }
      while ( v11 < result[10].value );
    }
    this->__vftable = v8;
    return this;
  }
  else
  {
    v9 = (idVoiceTrack_vtbl *)result[72].value;
    if ( (int)v9 < 0 )
      idVoiceTrack::FindApproximateDuration(this, result);
    else
      this->__vftable = v9;
    return this;
  }
}


// ========================================================================
// ??0idVoiceTrack@@QAA@PBD@Z
// EA  : 0x826386F0
// RVA : 0x006386F0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idVoiceTrack *__fastcall idVoiceTrack::idVoiceTrack(idVoiceTrack *this, const char *defaultVisemeSetName)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idVoiceTrack_vtbl *)&idVoiceTrack::`vftable';
  this->events.list = nullptr;
  this->events.granularity = 0;
  this->events.memTag = 66;
  this->events.listStatic = 0;
  this->events.size = 0;
  this->events.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->events);
  idVoiceEventManager::idVoiceEventManager(this: &this->voiceEventManager);
  this->frameRefs = nullptr;
  this->numFrameRefs = 0;
  this->indexBuffer.curOffset = 0;
  this->indexBuffer.size = 0;
  this->indexBuffer.indices = nullptr;
  this->rebuildFrameRefs = true;
  this->visemeOffsetState = 0;
  this->offsetState = 0;
  this->textLangKey.str = &byte_8200D768;
  this->textId.index = -1;
  this->textCRC = 0;
  this->lipsyncTextCRC = 0;
  this->subtitleLangKey.str = &byte_8200D768;
  this->subtitleId.index = -1;
  this->soundShader = nullptr;
  this->sampleTimestamp = 0;
  this->sampleCRC = 0;
  this->animName.allocedAndFlag = 20;
  this->animName.data = this->animName.baseBuffer;
  this->animName.len = 0;
  this->animName.baseBuffer[0] = 0;
  this->faceChannel = FACECHANNEL_BODY;
  this->blendInMS = 250;
  this->blendOutMS = 250;
  this->soundOffsetMS = 66;
  this->visemeOffsetMS = 0;
  this->animEventOffsetMS = 0;
  this->moodEventOffsetMS = 0;
  this->gameEventOffsetMS = 0;
  this->textEventOffsetMS = 0;
  this->flags = (idVoiceTrack::flags_t)2;
  this->weightScale = 1.0;
  this->defaultMood = MOOD_NONE;
  this->declVisemeSet = nullptr;
  this->timestamp = -1;
  this->approximateDuration.value = -1;
  return this;
}


// ========================================================================
// __unwind$226703
// EA  : 0x82638850
// RVA : 0x00638850
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226703()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$226704
// EA  : 0x82638878
// RVA : 0x00638878
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226704()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 36));
}


// ========================================================================
// ??1idVoiceTrack@@UAA@XZ
// EA  : 0x826388C0
// RVA : 0x006388C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::~idVoiceTrack(idVoiceTrack *this)
{
  idList<vtrEventHandle_t,66> *p_events; // r26
  idVoiceEventManager *p_voiceEventManager; // r25
  idVoiceTrack::idFrameRef *frameRefs; // r4
  unsigned __int16 *indices; // r4

  this->__vftable = (idVoiceTrack_vtbl *)&idVoiceTrack::`vftable';
  p_events = &this->events;
  p_voiceEventManager = &this->voiceEventManager;
  idVoiceEventManager::Free(this: &this->voiceEventManager, eventList: (idList<vtrEventHandle_t,5> *)&this->events);
  frameRefs = this->frameRefs;
  if ( frameRefs != nullptr )
  {
    idMem::Free(this: &mem, ptr: frameRefs, align: ALIGN_16);
    this->frameRefs = nullptr;
  }
  idStr::FreeData(this: &this->animName);
  indices = this->indexBuffer.indices;
  if ( indices != nullptr )
  {
    idMem::Free(this: &mem, ptr: indices, align: ALIGN_16);
    this->indexBuffer.indices = nullptr;
  }
  this->indexBuffer.curOffset = 0;
  this->indexBuffer.size = 0;
  idVoiceEventManager::~idVoiceEventManager(this: p_voiceEventManager);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_events);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$226786
// EA  : 0x82638974
// RVA : 0x00638974
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226786()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$226787
// EA  : 0x8263899C
// RVA : 0x0063899C
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226787()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 36));
}


// ========================================================================
// __unwind$226788_0
// EA  : 0x826389C8
// RVA : 0x006389C8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226788_0()
{
  int v0; // r12

  idVoiceEventManager::~idVoiceEventManager(this: (idVoiceEventManager *)(*(_DWORD *)(v0 - 160 + 180) + 52));
}


// ========================================================================
// __unwind$226789_0
// EA  : 0x826389F4
// RVA : 0x006389F4
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226789_0()
{
  int v0; // r12

  idVoiceTrack::idFrameRefIndexBuffer::~idFrameRefIndexBuffer(this: (idVoiceTrack::idFrameRefIndexBuffer *)(*(_DWORD *)(v0 - 160 + 180) + 156));
}


// ========================================================================
// __unwind$226790
// EA  : 0x82638A20
// RVA : 0x00638A20
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226790()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 204));
}


// ========================================================================
// ?BuildFrameRefs@idVoiceTrack@@QAAXXZ
// EA  : 0x82638C28
// RVA : 0x00638C28
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::BuildFrameRefs(idVoiceTrack *this)
{
  int v2; // r8
  int v3; // r7
  int v4; // r6
  int *ApproximateDuration; // r3
  __int64 v6; // r10
  vtrEventHandle_t *list; // r4
  unsigned int num; // r5
  vtrEventHandle_t *v9; // r4
  unsigned int v10; // r5
  idVoiceTrack::idFrameRef *frameRefs; // r4
  int LastEvent; // r3
  idVoiceEvent *Event; // r3
  int v14; // r11
  unsigned int v15; // r29
  unsigned int v16; // r5
  idVoiceTrack::idFrameRef *v17; // r3
  unsigned __int16 *p_numIndices; // r11
  unsigned int v19; // ctr
  idVoiceTrack::idFrameRef *v20; // r11
  __int16 numFrameRefs; // r10
  int v22; // r28
  int v23; // r29
  int i; // r3
  idVoiceTrack::idFrameRefIndexBuffer *p_indexBuffer; // r27
  int v26; // r28
  int v27; // r26
  int j; // r29
  int curOffset; // r7
  idVoiceTrack::idFrameRef *v30; // r8
  int list_low; // r3
  __int16 v32; // r11
  idVoiceTrack v33[7]; // [sp+50h] [-890h] BYREF

  ApproximateDuration = (int *)idVoiceTrack::FindApproximateDuration(
                                 this: v33,
                                 result: (idTypesafeNumber<int,enum millisecondUnique_t> *)this);
  LODWORD(v6) = this->rebuildFrameRefs;
  this->approximateDuration.value = *ApproximateDuration;
  if ( (_DWORD)v6 != 0 && this->events.num != 0 )
  {
    v33[0].nextOnHashChain = (idResource *)&this->voiceEventManager;
    v33[0].name.str = (const char *)&idSort_EventTime::`vftable';
    list = this->events.list;
    if ( list != nullptr )
    {
      num = this->events.num;
      v33[0].__vftable = (idVoiceTrack_vtbl *)this->events.list;
      idSort_Quick<vtrEventHandle_t,idSort_EventTime>::Sort(
        this: (idSort_Quick<vtrEventHandle_t,idSort_EventTime> *)&v33[0].name,
        base: list,
        num,
        a4: v4,
        a5: v3,
        a6: v2,
        a7: v6);
    }
    v33[0].resourceListPtr = (idResourceList *)&idSort_EventTime::`vftable';
    v33[0].resourceError = (const char *)&this->voiceEventManager;
    v33[0].name.str = (const char *)&idSort<vtrEventHandle_t>::`vftable';
    v9 = this->events.list;
    if ( v9 != nullptr )
    {
      v10 = this->events.num;
      v33[0].__vftable = (idVoiceTrack_vtbl *)this->events.list;
      idSort_Quick<vtrEventHandle_t,idSort_EventTime>::Sort(
        this: (idSort_Quick<vtrEventHandle_t,idSort_EventTime> *)&v33[0].resourceListPtr,
        base: v9,
        num: v10,
        a4: v4,
        a5: v3,
        a6: v2,
        a7: v6);
    }
    frameRefs = this->frameRefs;
    v33[0].resourceListPtr = (idResourceList *)&idSort<vtrEventHandle_t>::`vftable';
    if ( frameRefs != nullptr )
    {
      v33[0].__vftable = (idVoiceTrack_vtbl *)frameRefs;
      idMem::Free(this: &mem, ptr: frameRefs, align: ALIGN_16);
      this->frameRefs = nullptr;
    }
    LastEvent = idVoiceTrack::FindLastEvent(this);
    if ( LastEvent >= 0 )
    {
      Event = idVoiceEventManager::GetEvent(
                this: &this->voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[LastEvent]);
      if ( Event != nullptr )
        v14 = Event->durationMS + Event->startMS;
      else
        v14 = 0;
      v15 = (__int16)(v14 / 66 + 1);
      this->numFrameRefs = v15;
      v16 = 4 * v15;
      if ( v15 > 0x3FFFFFFF )
        v16 = -1;
      v17 = (idVoiceTrack::idFrameRef *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                          size: v16,
                                          tag: TAG_VOICETRACK_FRAMEREFS,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
      {
        if ( (int)(v15 - 1) >= 0 )
        {
          v19 = v15;
          p_numIndices = &v17[-1].numIndices;
          do
          {
            p_numIndices[1] = 0;
            p_numIndices += 2;
            *p_numIndices = 0;
            --v19;
          }
          while ( v19 != 0 );
        }
        v20 = v17;
      }
      else
      {
        v20 = nullptr;
      }
      numFrameRefs = this->numFrameRefs;
      v22 = 0;
      this->frameRefs = v20;
      v23 = 0;
      if ( numFrameRefs <= 0 )
        goto LABEL_26;
      do
      {
        for ( i = idVoiceTrack::FindNextEventForFrame(this, startIndex: -1, frame: v23);
              i >= 0;
              i = idVoiceTrack::FindNextEventForFrame(this, startIndex: i, frame: v23) )
        {
          ++v22;
        }
        ++v23;
      }
      while ( v23 < this->numFrameRefs );
      if ( v22 != 0 )
      {
        p_indexBuffer = &this->indexBuffer;
        idVoiceTrack::idFrameRefIndexBuffer::Alloc(this: &this->indexBuffer, size: (unsigned __int16)v22);
        v26 = 0;
        if ( this->numFrameRefs > 0 )
        {
          v27 = 0;
          do
          {
            v33[0].events.num = 1024;
            v33[0].events.list = nullptr;
            *((_DWORD *)&v33[0].idResource + 8) = &v33[0].events.granularity;
            v33[0].events.size = 66817;
            for ( j = idVoiceTrack::FindNextEventForFrame(this, startIndex: -1, frame: v26);
                  j >= 0;
                  j = idVoiceTrack::FindNextEventForFrame(this, startIndex: j, frame: v26) )
            {
              HIWORD(v33[0].__vftable) = j;
              idList<unsigned short,72>::Append(
                this: (idList<unsigned short,5> *)&v33[0].idResource + 2,
                obj: (unsigned __int16 *)v33);
            }
            curOffset = p_indexBuffer->curOffset;
            v30 = this->frameRefs;
            p_indexBuffer->curOffset = curOffset + LOWORD(v33[0].events.list);
            HIWORD(v33[0].__vftable) = curOffset;
            v30[v27].offset = curOffset;
            list_low = LOWORD(v33[0].events.list);
            v30[v27].numIndices = (unsigned __int16)v33[0].events.list;
            memcpy(
              Dst: (char *)this->indexBuffer.indices + __ROL4__(curOffset, 1),
              Src: *((const void **)&v33[0].idResource + 8),
              Size: (2 * list_low) & 0x1FFFE);
            if ( LOBYTE(v33[0].events.size) == 0 || LOBYTE(v33[0].events.size) == 2 )
            {
              if ( *((_DWORD *)&v33[0].idResource + 8) != 0 )
                idMem::Free(this: &mem, ptr: *((void **)&v33[0].idResource + 8), align: ALIGN_16);
              *((_DWORD *)&v33[0].idResource + 8) = 0;
              v33[0].events.num = 0;
            }
            v32 = this->numFrameRefs;
            ++v26;
            v33[0].events.list = nullptr;
            ++v27;
          }
          while ( v26 < v32 );
        }
      }
      else
      {
LABEL_26:
        this->numFrameRefs = 0;
      }
    }
  }
}


// ========================================================================
// __unwind$226995
// EA  : 0x82638F78
// RVA : 0x00638F78
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226995()
{
  int v0; // r12

  idSort_EventTime::~idSort_EventTime(this: (idSort_EventTime *)(v0 - 2272 + 88));
}


// ========================================================================
// __unwind$226996
// EA  : 0x82638FA0
// RVA : 0x00638FA0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226996()
{
  int v0; // r12

  idSort_EventTime::~idSort_EventTime(this: (idSort_EventTime *)(v0 - 2272 + 96));
}


// ========================================================================
// __unwind$226998
// EA  : 0x82638FC8
// RVA : 0x00638FC8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_226998()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2272 + 112));
}


// ========================================================================
// ?Parse@idVoiceTrack@@AAAXAAVidLexer@@@Z
// EA  : 0x82639278
// RVA : 0x00639278
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::Parse(idVoiceTrack *this, idLexer *src)
{
  idList<vtrEventHandle_t,66> *p_events; // r29
  bool Token; // r3
  __int128 v5; // r20
  __int128 v6; // r27
  idVoiceTrack *v7; // r29
  idViseme_Simple *list; // r25
  const char *v9; // r26
  const char *v10; // r4
  const char *v11; // r4
  const idSoundShader *v12; // r3
  int v13; // r4
  idVoiceEvent *Event; // r3
  const idDecl *v15; // r3
  idVoiceAnimEvent *FacialAnimationEvent; // r3
  int value; // r11
  __int64 v18; // r10
  idVoiceTrack::idFrameRef *frameRefs; // r4
  const char *str; // r4
  __int16 numFrameRefs; // r11
  unsigned int v22; // r8
  unsigned int v23; // r30
  signed int v24; // r6
  int v25; // r7
  int v26; // r5
  int v27; // r3
  signed int v28; // r11
  double v29; // r5
  char v30; // [sp+50h] [-180h]
  idVoiceEventManager v31; // [sp+68h] [-168h] BYREF
  const char *v32; // [sp+C8h] [-108h]
  idDeclInfoTemplate<idDeclVisemeSet> *v33; // [sp+CCh] [-104h]
  __int64 v34; // [sp+D0h] [-100h]
  const char *v35; // [sp+D8h] [-F8h]
  const char *v36; // [sp+DCh] [-F4h]
  const char *v37; // [sp+E0h] [-F0h]
  const char *v38; // [sp+E4h] [-ECh]
  const char *v39; // [sp+E8h] [-E8h]
  const char *v40; // [sp+ECh] [-E4h]
  const char *v41; // [sp+F0h] [-E0h]
  const char *v42; // [sp+F4h] [-DCh]
  const char *v43; // [sp+F8h] [-D8h]
  const char *v44; // [sp+FCh] [-D4h]
  const char *v45; // [sp+100h] [-D0h]
  const char *v46; // [sp+104h] [-CCh]
  const char *v47; // [sp+108h] [-C8h]
  const char *v48; // [sp+10Ch] [-C4h]
  const char *v49; // [sp+110h] [-C0h]
  const char *v50; // [sp+114h] [-BCh]
  const char *v51; // [sp+118h] [-B8h]
  __int64 v52; // [sp+120h] [-B0h]
  __int64 v53; // [sp+128h] [-A8h]

  v31.eventsVisemeSimple.size = 0;
  v31.eventsGame.list = (idVoiceGameEvent *)20;
  *(_DWORD *)&v31.eventsVisemeSimple.granularity = &v31.eventsGame.num;
  *(float *)&v31.eventsAnim.list = -3.4028235e38;
  HIBYTE(v31.eventsGame.num) = 0;
  *(_DWORD *)&v31.eventsPunc.granularity = 0;
  memset(&v31.eventsAnim.num, 0, 12);
  this->visemeOffsetState = 0;
  this->offsetState = 0;
  p_events = &this->events;
  v30 = 0;
  if ( this->events.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->events);
  p_events->num = __CFADD__(-p_events->size, p_events->size ^ 0x80000000) ? 0 : p_events->size;
  Token = idLexer::ReadToken(this: src, token: (idToken *)&v31.eventsVisemeSimple.size);
  v33 = &idDeclVisemeSet::resourceList;
  if ( Token )
  {
    v43 = "visemes";
    DWORD1(v5) = "frictionTime";
    v45 = "Unknown token '%s' in voice track";
    v41 = "events";
    v39 = "useRealTime";
    v37 = "suppressBlinking";
    v44 = (const char *)-2113858732;
    v49 = (const char *)-2113605720;
    v42 = (const char *)-2113354648;
    v47 = (const char *)-2113354588;
    v36 = "nolipsync";
    DWORD1(v6) = &unk_821C0000;
    *((_QWORD *)&v6 + 1) = 0x820A000082050000uLL;
    LODWORD(v5) = "Unrecognized voice event type '%s'";
    DWORD2(v5) = "Unknown token '%s' in anim block";
    *(_QWORD *)&v31.eventsVisemeSimple.list = *(_QWORD *)((char *)&v6 + 4);
    DWORD2(v6) = -2112094208;
    v52 = v6;
    v53 = v5;
    v34 = *(_QWORD *)((char *)&v5 + 4);
    v40 = (const char *)-2113586780;
    v46 = (const char *)-2113511480;
    v50 = (const char *)-2113603160;
    v51 = "useExactDuration";
    v38 = "moodEventOffsetMS";
    v7 = this;
    v48 = "edited";
    v31.eventsMood.num = (int)"animEventOffsetMS";
    v31.eventsMood.list = (idVoiceMoodEvent *)"visemeOffsetMS";
    v35 = (const char *)-2113245656;
    list = v31.eventsVisemeSimple.list;
    *(_DWORD *)&v31.eventsMood.granularity = "eventOffsetMS";
    v31.eventsMood.size = (int)"soundOffsetMS";
    v9 = (const char *)(v31.eventsVisemeSimple.num + 21724);
    v32 = "weightScale";
    while ( 1 )
    {
      if ( v31.eventsText.size == 5 && *(_DWORD *)&v31.eventsText.granularity == 47 )
        goto LABEL_94;
      if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "defaultMood") != 0 )
      {
        if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "visemeSet") != 0 )
        {
          if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v32) != 0 )
          {
            if ( idStr::Cmp(
                   s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                   s2: (const char *)v31.eventsMood.size) != 0 )
            {
              if ( idStr::Cmp(
                     s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                     s2: *(const char **)&v31.eventsMood.granularity) != 0
                && idStr::Cmp(
                     s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                     s2: (const char *)v31.eventsMood.list) != 0 )
              {
                if ( idStr::Cmp(
                       s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                       s2: (const char *)v31.eventsMood.num) != 0 )
                {
                  if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "gameEventOffsetMS") != 0 )
                  {
                    if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "textEventOffsetMS") != 0 )
                    {
                      if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v38) != 0 )
                      {
                        if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v51) != 0 )
                        {
                          if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v48) != 0 )
                          {
                            if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "text") != 0 )
                            {
                              if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: "subtitles") == 0 )
                              {
                                idLexer::ExpectTokenType(
                                  this: src,
                                  type: 5,
                                  subtype: 46,
                                  token: (idToken *)&v31.eventsVisemeSimple.size);
                                idLexer::ExpectTokenString(this: src, string: v9);
                                idLexer::ExpectTokenType(
                                  this: src,
                                  type: 1,
                                  subtype: 0,
                                  token: (idToken *)&v31.eventsVisemeSimple.size);
                                idAtomicString::Set(
                                  this: &this->subtitleLangKey,
                                  str_: *(const char *const *)&v31.eventsVisemeSimple.granularity);
                                if ( v31.eventsVisemeSimple.size != 0 )
                                {
                                  v11 = *(const char **)&v31.eventsVisemeSimple.granularity;
                                }
                                else
                                {
                                  idLib::Warning(
                                    fmt: "vtr '%s' has a completely blank subtitles .lang key. This should never happen. Use #"
                                    "str_empty instead.",
                                    this->name.str);
                                  v11 = "#str_empty";
                                }
                                idStrId::Set(this: &this->subtitleId, key: v11);
                                idLexer::ExpectTokenType(
                                  this: src,
                                  type: 5,
                                  subtype: 47,
                                  token: (idToken *)&v31.eventsVisemeSimple.size);
                                goto LABEL_91;
                              }
                              if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v50) != 0 )
                              {
                                if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v46) != 0 )
                                {
                                  if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v41) != 0
                                    && idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v43) != 0 )
                                  {
                                    idLexer::Error(this: src, str: v45, *(_DWORD *)&v31.eventsVisemeSimple.granularity);
                                  }
                                  else
                                  {
                                    v13 = this->events.num + idLexer::ParseInt(this: src);
                                    if ( v13 > this->events.size )
                                      idList<vtrEventHandle_t,66>::Resize(
                                        this: (idList<vtrEventHandle_t,5> *)&this->events,
                                        newsize: v13);
                                    idLexer::ExpectTokenType(
                                      this: src,
                                      type: 5,
                                      subtype: 46,
                                      token: (idToken *)&v31.eventsVisemeSimple.size);
                                    while ( idLexer::ReadToken(
                                              this: src,
                                              token: (idToken *)&v31.eventsVisemeSimple.size) )
                                    {
                                      if ( v31.eventsText.size == 5 && *(_DWORD *)&v31.eventsText.granularity == 47 )
                                        break;
                                      idVoiceEventManager::AllocEvent(
                                        this: &v31,
                                        result: (vtrEventHandle_t *)&this->voiceEventManager,
                                        name: *(const char **)&v31.eventsVisemeSimple.granularity);
                                      Event = idVoiceEventManager::GetEvent(
                                                this: &this->voiceEventManager,
                                                handle: (const vtrEventHandle_t *)v31.eventsVisemeSimple.list);
                                      if ( Event != nullptr )
                                      {
                                        Event->Parse(this: Event, a2: this, a3: src);
                                        idList<vtrEventHandle_t,5>::Append(
                                          this: (idList<vtrEventHandle_t,5> *)&this->events,
                                          obj: (const vtrEventHandle_t *)&v31);
                                      }
                                      else
                                      {
                                        idLexer::Error(
                                          this: src,
                                          str: "Unrecognized voice event type '%s'",
                                          *(_DWORD *)&v31.eventsVisemeSimple.granularity);
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  idLexer::ExpectTokenType(
                                    this: src,
                                    type: 5,
                                    subtype: 46,
                                    token: (idToken *)&v31.eventsVisemeSimple.size);
                                  idLexer::ExpectTokenString(this: src, string: "frictionTime");
                                  idLexer::ExpectTokenType(
                                    this: src,
                                    type: 1,
                                    subtype: 0,
                                    token: (idToken *)&v31.eventsVisemeSimple.size);
                                  idStr::operator=(
                                    this: &this->animName,
                                    text: (const idStr *)&v31.eventsVisemeSimple.size);
                                  this->faceChannel = FACECHANNEL_HEAD;
                                  while ( idLexer::ReadToken(this: src, token: (idToken *)&v31.eventsVisemeSimple.size) )
                                  {
                                    if ( v31.eventsText.size == 5 && *(_DWORD *)&v31.eventsText.granularity == 47 )
                                      break;
                                    if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v40) != 0 )
                                    {
                                      if ( idStr::Cmp(s1: *(const char **)&v31.eventsVisemeSimple.granularity, s2: v47) != 0 )
                                      {
                                        if ( idStr::Cmp(
                                               s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                               s2: v42) != 0 )
                                        {
                                          if ( idStr::Cmp(
                                                 s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                 s2: v49) != 0 )
                                          {
                                            if ( idStr::Cmp(
                                                   s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                   s2: v44) != 0 )
                                            {
                                              if ( idStr::Cmp(
                                                     s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                     s2: v36) != 0 )
                                              {
                                                if ( idStr::Cmp(
                                                       s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                       s2: v37) != 0 )
                                                {
                                                  if ( idStr::Cmp(
                                                         s1: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                         s2: v39) != 0 )
                                                    idLexer::Error(
                                                      this: src,
                                                      str: "Unknown token '%s' in anim block",
                                                      *(_DWORD *)&v31.eventsVisemeSimple.granularity);
                                                  else
                                                    this->flags = (idVoiceTrack::flags_t)((2
                                                                                         * (idLexer::ParseInt(this: src) != 0))
                                                                                        & 2
                                                                                        | *(_BYTE *)&this->flags & 0xFD);
                                                }
                                                else
                                                {
                                                  this->flags = (idVoiceTrack::flags_t)((16
                                                                                       * (idLexer::ParseInt(this: src) != 0))
                                                                                      & 0x10
                                                                                      | *(_BYTE *)&this->flags & 0xEF);
                                                }
                                              }
                                              else
                                              {
                                                this->flags = (idVoiceTrack::flags_t)((32
                                                                                     * (idLexer::ParseInt(this: src) != 0))
                                                                                    & 0x20
                                                                                    | *(_BYTE *)&this->flags & 0xDF);
                                              }
                                            }
                                            else
                                            {
                                              this->flags = (idVoiceTrack::flags_t)(((idLexer::ParseInt(this: src) != 0) << 6)
                                                                                  & 0x40
                                                                                  | *(_BYTE *)&this->flags & 0xBF);
                                            }
                                          }
                                          else
                                          {
                                            this->flags = (idVoiceTrack::flags_t)(((idLexer::ParseInt(this: src) != 0) << 7)
                                                                                | *(_BYTE *)&this->flags & 0x7F);
                                          }
                                        }
                                        else
                                        {
                                          this->blendOutMS = idLexer::ParseInt(this: src);
                                        }
                                      }
                                      else
                                      {
                                        this->blendInMS = idLexer::ParseInt(this: src);
                                      }
                                    }
                                    else
                                    {
                                      idLexer::ExpectTokenType(
                                        this: src,
                                        type: 1,
                                        subtype: 0,
                                        token: (idToken *)&v31.eventsVisemeSimple.size);
                                      this->faceChannel = idVoiceTrack::GetFaceChannelForName(name: *(const char **)&v31.eventsVisemeSimple.granularity);
                                    }
                                  }
                                }
                                goto LABEL_91;
                              }
                              idLexer::ExpectTokenType(
                                this: src,
                                type: 5,
                                subtype: 46,
                                token: (idToken *)&v31.eventsVisemeSimple.size);
                              idLexer::ExpectTokenString(this: src, string: "shader");
                              idLexer::ExpectTokenType(
                                this: src,
                                type: 1,
                                subtype: 0,
                                token: (idToken *)&v31.eventsVisemeSimple.size);
                              if ( *(_DWORD *)&v31.eventsVisemeSimple.granularity != 0 )
                                v12 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                                               this: &idSoundShader::resourceList,
                                                               name: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                               makeDefault: true);
                              else
                                v12 = nullptr;
                              this->soundShader = v12;
                              if ( idLexer::CheckTokenString(this: src, string: "timestamp") )
                                this->sampleTimestamp = idLexer::ParseInt(this: src);
                              if ( idLexer::CheckTokenString(this: src, string: "crc") )
                                this->sampleCRC = idLexer::ParseInt(this: src);
                              if ( idLexer::CheckTokenString(this: src, string: v35) )
                                this->flags = (idVoiceTrack::flags_t)((8 * idLexer::ParseBool(this: src)) & 8
                                                                    | *(_BYTE *)&this->flags & 0xF7);
                            }
                            else
                            {
                              idLexer::ExpectTokenType(
                                this: src,
                                type: 5,
                                subtype: 46,
                                token: (idToken *)&v31.eventsVisemeSimple.size);
                              idLexer::ExpectTokenString(this: src, string: v9);
                              idLexer::ExpectTokenType(
                                this: src,
                                type: 1,
                                subtype: 0,
                                token: (idToken *)&v31.eventsVisemeSimple.size);
                              idAtomicString::Set(
                                this: &this->textLangKey,
                                str_: *(const char *const *)&v31.eventsVisemeSimple.granularity);
                              if ( v31.eventsVisemeSimple.size != 0 )
                              {
                                v10 = *(const char **)&v31.eventsVisemeSimple.granularity;
                              }
                              else
                              {
                                idLib::Warning(fmt: (const char *)list, this->name.str);
                                v10 = "#str_empty";
                              }
                              idStrId::Set(this: &this->textId, key: v10);
                              idLexer::ExpectTokenString(this: src, string: "crc");
                              this->textCRC = idLexer::ParseInt(this: src);
                              if ( idLexer::CheckTokenString(this: src, string: "lipsyncTextCrc") )
                                this->lipsyncTextCRC = idLexer::ParseInt(this: src);
                            }
                            idLexer::ExpectTokenType(
                              this: src,
                              type: 5,
                              subtype: 47,
                              token: (idToken *)&v31.eventsVisemeSimple.size);
                          }
                          else
                          {
                            this->flags = (idVoiceTrack::flags_t)((4 * idLexer::ParseBool(this: src)) & 4
                                                                | *(_BYTE *)&this->flags & 0xFB);
                          }
                        }
                        else
                        {
                          this->flags = (idVoiceTrack::flags_t)(idLexer::ParseBool(this: src)
                                                              | *(_BYTE *)&this->flags & 0xFE);
                        }
                      }
                      else
                      {
                        this->moodEventOffsetMS = idLexer::ParseInt(this: src);
                      }
                    }
                    else
                    {
                      this->textEventOffsetMS = idLexer::ParseInt(this: src);
                    }
                  }
                  else
                  {
                    this->gameEventOffsetMS = idLexer::ParseInt(this: src);
                  }
                }
                else
                {
                  this->animEventOffsetMS = idLexer::ParseInt(this: src);
                }
              }
              else
              {
                this->visemeOffsetMS = idLexer::ParseInt(this: src);
              }
            }
            else
            {
              this->soundOffsetMS = idLexer::ParseInt(this: src);
            }
          }
          else
          {
            this->weightScale = idLexer::ParseFloat(this: src, errorFlag: nullptr);
          }
        }
        else
        {
          v30 = 1;
          idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v31.eventsVisemeSimple.size);
          if ( *(_DWORD *)&v31.eventsVisemeSimple.granularity != 0 )
            this->declVisemeSet = (const idDeclVisemeSet *)idDeclInfo::FindWithInheritance(
                                                             this: v33,
                                                             name: *(const char **)&v31.eventsVisemeSimple.granularity,
                                                             makeDefault: true);
          else
            this->declVisemeSet = nullptr;
        }
      }
      else
      {
        idLexer::ExpectTokenType(this: src, type: 1, subtype: 0, token: (idToken *)&v31.eventsVisemeSimple.size);
        this->defaultMood = idVoiceTrack::GetMoodForName(name: *(const char **)&v31.eventsVisemeSimple.granularity);
      }
LABEL_91:
      if ( !idLexer::ReadToken(this: src, token: (idToken *)&v31.eventsVisemeSimple.size) )
        goto LABEL_94;
    }
  }
  v7 = this;
LABEL_94:
  idVoiceEventManager::Condense(this: &v7->voiceEventManager, eventList: (idList<vtrEventHandle_t,5> *)&v7->events);
  if ( v30 == 0 )
  {
    if ( idVoiceTrack::DEFAULT_VISEME_SET_NAME != nullptr )
      v15 = idDeclInfo::FindWithInheritance(this: v33, name: idVoiceTrack::DEFAULT_VISEME_SET_NAME, makeDefault: true);
    else
      v15 = nullptr;
    v7->declVisemeSet = (const idDeclVisemeSet *)v15;
  }
  idVoiceTrack::OffsetEvents(this: v7, ofs: EVENTOFFSET_FORWARDS, visemesOnly: false);
  idVoiceTrack::LoadAnims(this: v7);
  FacialAnimationEvent = idVoiceTrack::GetFacialAnimationEvent(this: v7, eventHandle_: nullptr);
  if ( FacialAnimationEvent != nullptr )
  {
    value = v7->approximateDuration.value;
    if ( value >= 0 )
    {
      if ( value > 0x7FFF )
        LOWORD(value) = 0x7FFF;
    }
    else
    {
      LOWORD(value) = 0;
    }
    FacialAnimationEvent->durationMS = value;
  }
  idVoiceTrack::BuildFrameRefs(this: v7);
  frameRefs = v7->frameRefs;
  if ( frameRefs != nullptr )
  {
    numFrameRefs = v7->numFrameRefs;
    v22 = 0;
    v23 = numFrameRefs;
    v24 = 0x80000000;
    v25 = 0x7FFFFFFF;
    v26 = 0;
    if ( numFrameRefs > 0 )
    {
      HIDWORD(v18) = 0;
      v27 = numFrameRefs;
      do
      {
        v28 = *(unsigned __int16 *)((char *)&frameRefs->numIndices + HIDWORD(v18));
        v22 += v28;
        if ( v28 > v24 )
          v24 = *(unsigned __int16 *)((char *)&frameRefs->numIndices + HIDWORD(v18));
        if ( *(unsigned __int16 *)((char *)&frameRefs->numIndices + HIDWORD(v18)) < v25 )
          v25 = *(unsigned __int16 *)((char *)&frameRefs->numIndices + HIDWORD(v18));
        ++v26;
        HIDWORD(v18) += 4;
      }
      while ( v26 < v27 );
    }
    LODWORD(v18) = v22;
    v34 = v18;
    v29 = (float)((float)v18 / (float)__SPAIR64__(v22, v23));
    idLib::Printf(
      fmt: "%s : %.2f events per frame ref. Max = %d, min = %d.\n",
      (const char *)HIDWORD(v29),
      v29,
      LODWORD(v29),
      v24);
  }
  else
  {
    str = v7->name.str;
    v7->numFrameRefs = 0;
    idLib::Printf(fmt: "%s : has no frame refs.\n", str);
  }
  idStr::FreeData(this: (idStr *)&v31.eventsVisemeSimple.size);
}


// ========================================================================
// __unwind$227446
// EA  : 0x82639EF8
// RVA : 0x00639EF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_227446()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 112));
}


// ========================================================================
// ?LoadBinary@idVoiceTrack@@AAA_NPBDI@Z
// EA  : 0x82639F28
// RVA : 0x00639F28
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::LoadBinary(idVoiceTrack *this, const char *fileName, const unsigned int srcTimestamp)
{
  idFile *v5; // r3
  int v7; // r29
  const idDeclVisemeSet *v8; // r3
  const idSoundShader *v9; // r3
  idFile *file; // r11
  idFile *v11; // r3
  idFile *v12; // r3
  idFile *v13; // r3
  idFile *v14; // r3
  idFile *v15; // r3
  idFile *v16; // r3
  idFile *v17; // r4
  __int16 *p_numFrameRefs; // r29
  __int16 numFrameRefs; // r10
  int v20; // r28
  unsigned int v21; // r5
  idVoiceTrack::idFrameRef *v22; // r3
  unsigned __int16 *p_numIndices; // r11
  int v24; // ctr
  idVoiceTrack::idFrameRef *v25; // r11
  __int16 v26; // r10
  int v27; // r28
  int v28; // r27
  idVoiceTrack::idFrameRef *v29; // r26
  int v30; // r4
  idList<vtrEventHandle_t,66> *p_events; // r27
  int v32; // r29
  char v33; // r3
  int size; // r11
  int v35; // r28
  int v36; // r29
  const char *str; // r3
  int v38; // r28
  int v39; // r29
  idVoiceEvent *Event; // r3
  idFileLocal v41; // [sp+50h] [-300h] BYREF
  char v42[4]; // [sp+54h] [-2FCh] BYREF
  int v43; // [sp+58h] [-2F8h] BYREF
  int v44; // [sp+5Ch] [-2F4h] BYREF
  int v45; // [sp+60h] [-2F0h] BYREF
  int v46[3]; // [sp+64h] [-2ECh] BYREF
  idStr v47; // [sp+70h] [-2E0h] BYREF
  idStr v48; // [sp+90h] [-2C0h] BYREF
  char v49[288]; // [sp+B0h] [-2A0h] BYREF
  _DWORD v50[71]; // [sp+1D0h] [-180h] BYREF

  v5 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  if ( v5 == nullptr )
    return 0;
  v41.file = v5;
  v5->Read(this: v5, a2: &v43, a3: 4u);
  if ( v43 != 542266454 && v43 != 525489238 )
  {
    if ( v43 != 542528594 && v43 != 525751378 )
    {
      idFileLocal::~idFileLocal(this: &v41);
      return 0;
    }
    v41.file->Read(this: v41.file, a2: &v45, a3: 4u);
    if ( v45 <= 0 )
      goto LABEL_22;
    v49[0] = 0;
    v7 = 0;
    v49[256] = 0;
    memset(&v49[272], 0, 12);
    v50[68] = 0;
    while ( 1 )
    {
      v41.file->Read(this: v41.file, a2: &v49[256], a3: 16u);
      v41.file->Read(this: v41.file, a2: &v49[276], a3: 4u);
      v41.file->Read(this: v41.file, a2: &v49[272], a3: 4u);
      if ( v7 == 0 )
        memcpy(Dst: v50, Src: v49, Size: sizeof(v50));
      if ( idStr::Icmp(s1: &v49[256], s2: sys_lang.valueString.data) == 0 )
        break;
      if ( ++v7 >= v45 )
        goto LABEL_17;
    }
    memcpy(Dst: v50, Src: v49, Size: sizeof(v50));
LABEL_17:
    v41.file->Seek(this: v41.file, a2: v50[68], a3: FS_SEEK_SET);
    v41.file->Read(this: v41.file, a2: &v43, a3: 4u);
    if ( v43 != 542266454 && v43 != 525489238 )
      goto LABEL_22;
  }
  v41.file->Read(this: v41.file, a2: &this->timestamp, a3: 4u);
  if ( srcTimestamp == 0 || srcTimestamp == -1 || srcTimestamp == this->timestamp )
  {
    v47.len = 0;
    v47.baseBuffer[0] = 0;
    v47.allocedAndFlag = 20;
    v47.data = v47.baseBuffer;
    idFile::ReadString(this: v41.file, string: &v47);
    if ( v47.data != nullptr )
      v8 = (const idDeclVisemeSet *)idDeclInfo::FindWithInheritance(
                                      this: &idDeclVisemeSet::resourceList,
                                      name: v47.data,
                                      makeDefault: true);
    else
      v8 = nullptr;
    this->declVisemeSet = v8;
    idFile::ReadString(this: v41.file, string: &this->textLangKey);
    idStrId::Set(this: &this->textId, key: this->textLangKey.str);
    v41.file->Read(this: v41.file, a2: &this->textCRC, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->lipsyncTextCRC, a3: 4u);
    if ( v43 != 525489238 )
    {
      idFile::ReadString(this: v41.file, string: &this->subtitleLangKey);
      idStrId::Set(this: &this->subtitleId, key: this->subtitleLangKey.str);
    }
    v48.allocedAndFlag = 20;
    v48.len = 0;
    v48.data = v48.baseBuffer;
    v48.baseBuffer[0] = 0;
    idFile::ReadString(this: v41.file, string: &v48);
    if ( v48.data != nullptr )
      v9 = (const idSoundShader *)idDeclInfo::FindWithInheritance(
                                    this: &idSoundShader::resourceList,
                                    name: v48.data,
                                    makeDefault: true);
    else
      v9 = nullptr;
    file = v41.file;
    this->soundShader = v9;
    file->Read(this: file, a2: &this->sampleTimestamp, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->sampleCRC, a3: 4u);
    idFile::ReadString(this: v41.file, string: &this->animName);
    v41.file->Read(this: v41.file, a2: &this->faceChannel, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->blendInMS, a3: 2u);
    v41.file->Read(this: v41.file, a2: &this->blendOutMS, a3: 2u);
    v41.file->Read(this: v41.file, a2: &this->soundOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->visemeOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->animEventOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->moodEventOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->gameEventOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->textEventOffsetMS, a3: 4u);
    v41.file->Read(this: v41.file, a2: v42, a3: 1u);
    v11 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((v42[0] << 7) | *(_BYTE *)&this->flags & 0x7F);
    v11->Read(this: v11, a2: v42, a3: 1u);
    v12 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((v42[0] << 6) & 0x40 | *(_BYTE *)&this->flags & 0xBF);
    v12->Read(this: v12, a2: v42, a3: 1u);
    v13 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((32 * v42[0]) & 0x20 | *(_BYTE *)&this->flags & 0xDF);
    v13->Read(this: v13, a2: v42, a3: 1u);
    v14 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((16 * v42[0]) & 0x10 | *(_BYTE *)&this->flags & 0xEF);
    v14->Read(this: v14, a2: v42, a3: 1u);
    v15 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((8 * v42[0]) & 8 | *(_BYTE *)&this->flags & 0xF7);
    v15->Read(this: v15, a2: v42, a3: 1u);
    v16 = v41.file;
    this->flags = (idVoiceTrack::flags_t)((4 * v42[0]) & 4 | *(_BYTE *)&this->flags & 0xFB);
    v16->Read(this: v16, a2: &this->weightScale, a3: 4u);
    v41.file->Read(this: v41.file, a2: &this->defaultMood, a3: 4u);
    v41.file->Read(this: v41.file, a2: v46, a3: 4u);
    v17 = v41.file;
    this->approximateDuration.value = v46[0];
    idVoiceTrack::idFrameRefIndexBuffer::Read(this: &this->indexBuffer, file: v17);
    p_numFrameRefs = &this->numFrameRefs;
    v41.file->Read(this: v41.file, a2: &this->numFrameRefs, a3: 2u);
    numFrameRefs = this->numFrameRefs;
    v20 = numFrameRefs;
    if ( numFrameRefs > 0 )
    {
      v21 = 4 * numFrameRefs;
      if ( (unsigned int)numFrameRefs > 0x3FFFFFFF )
        v21 = -1;
      v22 = (idVoiceTrack::idFrameRef *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                          size: v21,
                                          tag: TAG_VOICETRACK_FRAMEREFS,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
      {
        if ( v20 - 1 >= 0 )
        {
          v24 = v20;
          p_numIndices = &v22[-1].numIndices;
          do
          {
            p_numIndices[1] = 0;
            p_numIndices += 2;
            *p_numIndices = 0;
            --v24;
          }
          while ( v24 != 0 );
        }
        v25 = v22;
      }
      else
      {
        v25 = nullptr;
      }
      v26 = *p_numFrameRefs;
      v27 = 0;
      this->frameRefs = v25;
      if ( v26 > 0 )
      {
        v28 = 0;
        do
        {
          v29 = &this->frameRefs[v28];
          v41.file->Read(this: v41.file, a2: v29, a3: 2u);
          v41.file->Read(this: v41.file, a2: &v29->numIndices, a3: 2u);
          ++v27;
          ++v28;
        }
        while ( v27 < *p_numFrameRefs );
      }
    }
    idVoiceEventManager::LoadBinary(this: &this->voiceEventManager, file: v41.file);
    v41.file->Read(this: v41.file, a2: &v44, a3: 4u);
    v30 = v44;
    p_events = &this->events;
    v32 = v44;
    if ( v44 <= this->events.size
      || (v33 = idList<vtrEventHandle_t,66>::Resize(this: (idList<vtrEventHandle_t,5> *)&this->events, newsize: v44),
          v30 = v44,
          v33 != 0) )
    {
      size = this->events.size;
      if ( v32 < size )
        size = v32;
      this->events.num = size;
    }
    v35 = 0;
    if ( v30 > 0 )
    {
      v36 = 0;
      do
      {
        vtrEventHandle_t::LoadBinary(this: &p_events->list[v36], file: v41.file);
        ++v35;
        ++v36;
      }
      while ( v35 < v44 );
    }
    v41.file->Read(this: v41.file, a2: &v43, a3: 4u);
    if ( v43 == 542266454 || v43 == 525489238 )
    {
      idVoiceTrack::LoadAnims(this);
      str = this->name.str;
      this->visemeOffsetState = 1;
      this->offsetState = 1;
      if ( idStr::Icmp(s1: str, s2: "voicetrack/english/wasteland2/subwaytown/saul/approach_01.vtr") == 0 )
      {
        v38 = 0;
        if ( this->events.num > 0 )
        {
          v39 = 0;
          do
          {
            Event = idVoiceEventManager::GetEvent(
                      this: &this->voiceEventManager,
                      handle: *(const vtrEventHandle_t **)&p_events->list[v39]);
            if ( Event != nullptr && Event->eventType == 5 && HIWORD(Event[1].startMS) == 0 )
              HIWORD(Event[1].startMS) = 1;
            ++v38;
            ++v39;
          }
          while ( v38 < this->events.num );
        }
      }
      idStr::FreeData(this: &v48);
      idStr::FreeData(this: &v47);
      idFileLocal::~idFileLocal(this: &v41);
      return 1;
    }
    else
    {
      idStr::FreeData(this: &v48);
      idStr::FreeData(this: &v47);
      idFileLocal::~idFileLocal(this: &v41);
      return 0;
    }
  }
  else
  {
LABEL_22:
    idFileLocal::~idFileLocal(this: &v41);
    return 0;
  }
}


// ========================================================================
// __unwind$227948
// EA  : 0x8263A804
// RVA : 0x0063A804
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_227948()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 848 + 80));
}


// ========================================================================
// __unwind$227949
// EA  : 0x8263A82C
// RVA : 0x0063A82C
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_227949()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 112));
}


// ========================================================================
// __unwind$227950
// EA  : 0x8263A854
// RVA : 0x0063A854
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_227950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 848 + 144));
}


// ========================================================================
// ?AllocEvent@idVoiceTrack@@QAA?AVvtrEventHandle_t@@W4voiceEvent_t@@@Z
// EA  : 0x8263A880
// RVA : 0x0063A880
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idVoiceTrack *__fastcall idVoiceTrack::AllocEvent(idVoiceTrack *this, vtrEventHandle_t *result, voiceEvent_t type)
{
  char v5; // r11

  idVoiceEventManager::AllocEvent((idVoiceEventManager *)this, result: result + 13, eventType: type);
  if ( HIWORD(this->__vftable) == 7 || (v5 = 1, LOWORD(this->__vftable) >= 0x8000u) )
    v5 = 0;
  if ( v5 != 0 )
    idList<vtrEventHandle_t,5>::Append(
      this: (idList<vtrEventHandle_t,5> *)&result[9],
      obj: (const vtrEventHandle_t *)this);
  return this;
}


// ========================================================================
// ?GetEvents@idVoiceTrack@@QBAXHV?$idTypesafeNumber@HW4millisecondUnique_t@@@@0W4voiceEvent_t@@PAV?$idStaticList@PBVidVoiceEvent@@$0CA@@@2@Z
// EA  : 0x8263A8F8
// RVA : 0x0063A8F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::GetEvents(
        idVoiceTrack *this,
        const int frame,
        const idTypesafeNumber<int,enum millisecondUnique_t> *curTimeMS,
        const idTypesafeNumber<int,enum millisecondUnique_t> *lastTimeMS,
        const voiceEvent_t type,
        idStaticList<idVoiceEvent const *,32> *visemeEvents,
        idStaticList<idVoiceEvent const *,32> *nonVisemeEvents)
{
  int v13; // r25
  idVoiceTrack::idFrameRef *v14; // r28
  char *v15; // r11
  idVoiceEventManager *p_voiceEventManager; // r27
  unsigned __int16 *i; // r29
  const idVoiceEvent *Event; // r3
  const idVoiceEvent *v19; // r31
  idStaticList<idVoiceEvent const *,32> *v20; // r3
  const idVoiceEvent *v21; // [sp+50h] [-70h] BYREF

  if ( frame < this->numFrameRefs )
  {
    v13 = 0;
    v14 = &this->frameRefs[frame];
    v15 = (char *)this->indexBuffer.indices + __ROL4__(v14->offset, 1);
    if ( v14->numIndices != 0 )
    {
      p_voiceEventManager = &this->voiceEventManager;
      for ( i = (unsigned __int16 *)v15; ; ++i )
      {
        Event = idVoiceEventManager::GetEvent(
                  this: p_voiceEventManager,
                  handle: *(const vtrEventHandle_t **)((char *)this->events.list + __ROL4__(*i, 2)));
        v19 = Event;
        v21 = Event;
        if ( (type == VOICEEVENT_MAX || Event->eventType == type)
          && Event->IsWithinInterval(this: (idVoiceEvent *)Event, a2: lastTimeMS->value, a3: curTimeMS->value) )
        {
          if ( visemeEvents == nullptr || v19->eventType != 0 && v19->eventType != 1 )
            break;
          if ( visemeEvents->num < visemeEvents->size )
          {
            v20 = visemeEvents;
LABEL_15:
            idList<idDeclMD6 const *,5>::AddUnique(this: v20, obj: &v21);
          }
        }
LABEL_16:
        if ( ++v13 >= v14->numIndices )
          return;
      }
      if ( nonVisemeEvents == nullptr || nonVisemeEvents->num >= nonVisemeEvents->size )
        goto LABEL_16;
      v20 = nonVisemeEvents;
      goto LABEL_15;
    }
  }
}


// ========================================================================
// ?GetEventsForFrameRef@idVoiceTrack@@QBAXHW4voiceEvent_t@@PAV?$idStaticList@PBVidVoiceEvent@@$0CA@@@1@Z
// EA  : 0x8263AA30
// RVA : 0x0063AA30
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::GetEventsForFrameRef(
        idVoiceTrack *this,
        const int frame,
        const voiceEvent_t type,
        idStaticList<idVoiceEvent const *,32> *visemeEvents,
        idStaticList<idVoiceEvent const *,32> *nonVisemeEvents)
{
  int v9; // r27
  idVoiceTrack::idFrameRef *v10; // r29
  char *v11; // r11
  idVoiceEventManager *p_voiceEventManager; // r28
  unsigned __int16 *i; // r30
  const idVoiceEvent *Event; // r3
  idStaticList<idVoiceEvent const *,32> *v15; // r3
  const idVoiceEvent *v16; // [sp+50h] [-50h] BYREF

  if ( frame < this->numFrameRefs )
  {
    v9 = 0;
    v10 = &this->frameRefs[frame];
    v11 = (char *)this->indexBuffer.indices + __ROL4__(v10->offset, 1);
    if ( v10->numIndices != 0 )
    {
      p_voiceEventManager = &this->voiceEventManager;
      for ( i = (unsigned __int16 *)v11; ; ++i )
      {
        Event = idVoiceEventManager::GetEvent(
                  this: p_voiceEventManager,
                  handle: *(const vtrEventHandle_t **)((char *)this->events.list + __ROL4__(*i, 2)));
        v16 = Event;
        if ( type == VOICEEVENT_MAX || Event->eventType == type )
        {
          if ( visemeEvents == nullptr || Event->eventType != 0 && Event->eventType != 1 )
            break;
          if ( visemeEvents->num < visemeEvents->size )
          {
            v15 = visemeEvents;
LABEL_14:
            idList<idDeclMD6 const *,5>::AddUnique(this: v15, obj: &v16);
          }
        }
LABEL_15:
        if ( ++v9 >= v10->numIndices )
          return;
      }
      if ( nonVisemeEvents == nullptr || nonVisemeEvents->num >= nonVisemeEvents->size )
        goto LABEL_15;
      v15 = nonVisemeEvents;
      goto LABEL_14;
    }
  }
}


// ========================================================================
// ?MergeVisemes@idVoiceTrack@@QAAXXZ
// EA  : 0x8263AB40
// RVA : 0x0063AB40
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::MergeVisemes(idVoiceTrack *this)
{
  int num; // r4
  int v3; // r20
  int v4; // r19
  const vtrEventHandle_t **v5; // r30
  idVoiceEvent *Event; // r28
  int startMS; // r30
  int v8; // r23
  int v9; // r26
  int v10; // r24
  const vtrEventHandle_t **v11; // r11
  idVoiceEvent *v12; // r29
  int v13; // r9
  int v14; // r11
  int v15; // r27
  unsigned int v16; // r11
  unsigned __int8 v17; // r10
  __int16 v18; // r10
  __int16 v19; // r10
  __int16 startMS_high; // r9
  int v21; // r11
  idList<idVehicleState *,5> v22[8]; // [sp+60h] [-80h] BYREF

  this->rebuildFrameRefs = false;
  idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_BACKWARDS, visemesOnly: true);
  memset(v22, 0, 14);
  v22[0].memTag = 5;
  v22[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: v22);
  num = this->events.num;
  if ( num > v22[0].size )
    idList<vtrEventHandle_t,66>::Resize(this: (idList<vtrEventHandle_t,5> *)v22, newsize: num);
  v3 = 0;
  if ( this->events.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = (const vtrEventHandle_t **)&this->events.list[v4];
      if ( (*(_WORD *)v5 == 0 || *(_WORD *)v5 == 1)
        && idList<vtrEventHandle_t,5>::FindIndex(
             this: (idList<vtrEventHandle_t,5> *)v22,
             obj: (const vtrEventHandle_t *)v5,
             startIndex: 0) < 0 )
      {
        Event = idVoiceEventManager::GetEvent(this: &this->voiceEventManager, handle: *v5);
        startMS = Event->startMS;
        v8 = 0;
        v9 = Event->durationMS + startMS;
        if ( this->events.num > 0 )
        {
          v10 = 0;
          do
          {
            if ( v3 != v8 )
            {
              v11 = (const vtrEventHandle_t **)&this->events.list[v10];
              if ( *(_WORD *)v11 == 0 || *(_WORD *)v11 == 1 )
              {
                v12 = idVoiceEventManager::GetEvent(this: &this->voiceEventManager, handle: *v11);
                if ( HIBYTE(v12[1].__vftable) == HIBYTE(Event[1].__vftable)
                  && idList<vtrEventHandle_t,5>::FindIndex(
                       this: (idList<vtrEventHandle_t,5> *)v22,
                       obj: &this->events.list[v10],
                       startIndex: 0) < 0 )
                {
                  if ( (v13 = v12->startMS, v14 = v12->durationMS + v13, v13 >= startMS) && v13 < v9
                    || v14 >= startMS && v14 < v9
                    || startMS >= v13 && startMS < v14
                    || v9 >= v13 && v9 < v14 )
                  {
                    v15 = startMS;
                    if ( startMS >= v13 )
                      v15 = v12->startMS;
                    if ( v9 <= v14 )
                      v9 = v12->durationMS + v13;
                    if ( Event->eventType != 0 )
                    {
                      if ( Event->eventType == 1 )
                        idViseme_Frame::MergeWeights(
                          this: (idViseme_Frame *)Event,
                          other: (const idViseme_Frame *)v12,
                          gameMsPerFrame: 66);
                    }
                    else
                    {
                      v16 = BYTE2(v12[1].startMS);
                      v17 = BYTE2(Event[1].startMS);
                      if ( v16 <= v17 )
                      {
                        startMS_high = HIWORD(Event[1].startMS);
                        BYTE2(Event[1].startMS) = v17;
                        v19 = startMS_high + startMS - v15;
                      }
                      else
                      {
                        v18 = HIWORD(v12[1].startMS);
                        BYTE2(Event[1].startMS) = v16;
                        v19 = v18 + v13 - v15;
                      }
                      HIWORD(Event[1].startMS) = v19;
                    }
                    v21 = v9 - v15;
                    Event->startMS = v15;
                    if ( v9 - v15 >= 0 )
                    {
                      if ( v21 > 0x7FFF )
                        LOWORD(v21) = 0x7FFF;
                    }
                    else
                    {
                      LOWORD(v21) = 0;
                    }
                    Event->durationMS = v21;
                    startMS = v15;
                    idList<vtrEventHandle_t,5>::Append(
                      this: (idList<vtrEventHandle_t,5> *)v22,
                      obj: &this->events.list[v10]);
                  }
                }
              }
            }
            ++v8;
            ++v10;
          }
          while ( v8 < this->events.num );
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->events.num );
  }
  idVoiceEventManager::FreeEvents(
    this: &this->voiceEventManager,
    toFree: (idList<vtrEventHandle_t,5> *)v22,
    eventList: (idList<vtrEventHandle_t,5> *)&this->events);
  idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_FORWARDS, visemesOnly: true);
  this->rebuildFrameRefs = true;
  idVoiceTrack::BuildFrameRefs(this);
  if ( (v22[0].listStatic == 0 || v22[0].listStatic == 2) && v22[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v22[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$228901
// EA  : 0x8263AE54
// RVA : 0x0063AE54
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_228901()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?SpreadOutTextEvents@idVoiceTrack@@QAA_NPBD0HAAVidStr@@@Z
// EA  : 0x8263AE88
// RVA : 0x0063AE88
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::SpreadOutTextEvents(
        idVoiceTrack *this,
        const char *languageName,
        const char *text,
        signed int textLen,
        idStr *errorMsg)
{
  bool IsValidUTF8; // r26
  idVoiceEvent *Event; // r3
  int *p_trackedMemory; // r4
  char v12; // r9
  idVoiceEvent *v13; // r29
  idVoiceEvent *v14; // r3
  idAtomicString *p_name; // r4
  char v16; // r9
  char v17; // r11
  idVoiceEvent *v18; // r29
  signed int resourceError; // r26
  idResourceList *resourceListPtr; // r21
  signed int v21; // r28
  idResource *nextOnHashChain; // r25
  idResource *v23; // r27
  const vtrEventHandle_t *v24; // r4
  idVoiceEvent *v25; // r3
  int eventType; // r9
  idVoiceEvent *v27; // r29
  unsigned int v28; // r11
  int v29; // r10
  idVoiceTrack v31; // [sp+50h] [-8F0h] BYREF
  idToken v32; // [sp+250h] [-6F0h] BYREF
  char v33; // [sp+298h] [-6A8h] BYREF
  idToken v34; // [sp+3A0h] [-5A0h] BYREF
  char v35; // [sp+3E8h] [-558h] BYREF
  idToken v36; // [sp+4F0h] [-450h] BYREF
  char v37; // [sp+538h] [-408h] BYREF
  idToken v38; // [sp+640h] [-300h] BYREF
  char v39; // [sp+688h] [-2B8h] BYREF
  idToken v40; // [sp+790h] [-1B0h] BYREF
  char v41; // [sp+7D8h] [-168h] BYREF

  if ( text == nullptr || textLen <= 0 )
  {
    idStr::operator=(this: errorMsg, text: "Invalid text buffer.");
    return 0;
  }
  this->rebuildFrameRefs = false;
  idVoiceTrack::FreeTextEvents(this);
  idVoiceTrack::FindApproximateDuration(
    this: (idVoiceTrack *)&v31.nextOnHashChain,
    result: (idTypesafeNumber<int,enum millisecondUnique_t> *)this);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v31.resourceListPtr);
  IsValidUTF8 = idStr::IsValidUTF8(s: (const unsigned __int8 *)text, maxLen: textLen, encoding: (utf8Encoding_t *)&v31);
  if ( idStr::Icmp(s1: languageName, s2: "japanese") != 0 )
    idStr::Icmp(s1: languageName, s2: "russian");
  if ( IsValidUTF8 )
  {
    idLexerUTF8::idLexerUTF8(this: (idLexerUTF8 *)((char *)&v31.idResource + 32), flags_: 0x80000);
    idLexerUTF8::LoadMemory(
      this: (idLexerUTF8 *)((char *)&v31.idResource + 32),
      ptr: (const unsigned __int8 *)text,
      length: textLen,
      name: &byte_8200D768);
    HIBYTE(v31.subtitleId.index) = 0;
    *(_DWORD *)&v31.animName.baseBuffer[12] = 0;
    memset(&v31.faceChannel, 0, 13);
    *(float *)&v31.animName.baseBuffer[16] = -3.4028235e38;
    v31.lipsyncTextCRC = (unsigned int)&v31.visemeOffsetMS;
    v31.textCRC = 0;
    v31.subtitleLangKey.str = (const char *)-2147483392;
    v38.floatvalue = -3.4028235e38;
    v38.baseBuffer[0] = 0;
    v38.intvalue = 0;
    memset(&v38.whiteSpaceStart_p, 0, 12);
    v39 = 0;
    v38.data = &v39;
    v38.len = 0;
    v38.allocedAndFlag = -2147483392;
    v34.floatvalue = -3.4028235e38;
    v34.baseBuffer[0] = 0;
    v34.intvalue = 0;
    memset(&v34.whiteSpaceStart_p, 0, 12);
    v35 = 0;
    v34.data = &v35;
    v34.len = 0;
    v34.allocedAndFlag = -2147483392;
    if ( idLexerUTF8::ReadToken(this: (idLexerUTF8 *)((char *)&v31.idResource + 32), token: (idToken *)&v31.textCRC) )
    {
      while ( v31.animName.data == (char *)5 )
      {
        if ( v31.animName.allocedAndFlag == 53 )
          goto LABEL_11;
        idVoiceTrack::AllocEvent(
          this: (idVoiceTrack *)&v31.trackedMemory,
          result: (vtrEventHandle_t *)this,
          type: VOICEEVENT_PUNCTUATION);
        Event = idVoiceEventManager::GetEvent(
                  this: &this->voiceEventManager,
                  handle: (const vtrEventHandle_t *)v31.trackedMemory);
        p_trackedMemory = &v31.trackedMemory;
        v12 = *(_BYTE *)v31.lipsyncTextCRC;
        Event->startMS = 0;
        Event->durationMS = 0;
        HIBYTE(Event[1].__vftable) = v12;
LABEL_18:
        idList<vtrEventHandle_t,5>::Append(
          this: (idList<vtrEventHandle_t,5> *)&v31.resourceListPtr,
          obj: (const vtrEventHandle_t *)p_trackedMemory);
        if ( !idLexerUTF8::ReadToken(
                this: (idLexerUTF8 *)((char *)&v31.idResource + 32),
                token: (idToken *)&v31.textCRC) )
          goto LABEL_19;
      }
      if ( v31.animName.allocedAndFlag == 53 )
      {
LABEL_11:
        if ( !idLexerUTF8::ReadToken(this: (idLexerUTF8 *)((char *)&v31.idResource + 32), token: &v34) )
        {
LABEL_17:
          idVoiceTrack::AllocEvent(this: &v31, result: (vtrEventHandle_t *)this, type: VOICEEVENT_TEXT);
          v13 = idVoiceEventManager::GetEvent(
                  this: &this->voiceEventManager,
                  handle: (const vtrEventHandle_t *)v31.__vftable);
          idStr::operator=(this: (idStr *)&v13[1], text: (const char *)v31.lipsyncTextCRC);
          v13->startMS = 0;
          v13->durationMS = 0;
          p_trackedMemory = (int *)&v31;
          goto LABEL_18;
        }
        if ( v34.type == 5 )
        {
          idLexerUTF8::UnreadToken(this: (idLexerUTF8 *)((char *)&v31.idResource + 32));
          goto LABEL_17;
        }
      }
      else
      {
        if ( (unsigned __int8)idLexerUTF8::CheckTokenType(
                                this: (idLexerUTF8 *)((char *)&v31.idResource + 32),
                                type: 5,
                                subType: 53,
                                token: &v38) == 0 )
          goto LABEL_17;
        idStr::Append(this: (idStr *)&v31.textCRC, text: &v38);
        idLexerUTF8::ReadToken(this: (idLexerUTF8 *)((char *)&v31.idResource + 32), token: &v34);
      }
      idStr::Append(this: (idStr *)&v31.textCRC, text: &v34);
      goto LABEL_17;
    }
LABEL_19:
    idStr::FreeData(this: &v34);
    idStr::FreeData(this: &v38);
    idStr::FreeData(this: (idStr *)&v31.textCRC);
    idLexerUTF8::~idLexerUTF8(this: (idLexerUTF8 *)((char *)&v31.idResource + 32));
    goto LABEL_39;
  }
  idLexer::idLexer(this: (idLexer *)((char *)&v31.idResource + 32), flags_: 0x80000);
  idLexer::LoadMemory(
    this: (idLexer *)((char *)&v31.idResource + 32),
    ptr: text,
    length_: textLen,
    name: &byte_8200D768);
  v32.baseBuffer[0] = 0;
  v32.intvalue = 0;
  memset(&v32.whiteSpaceStart_p, 0, 12);
  v32.floatvalue = -3.4028235e38;
  v33 = 0;
  v32.data = &v33;
  v32.len = 0;
  v32.allocedAndFlag = -2147483392;
  v40.floatvalue = -3.4028235e38;
  v40.baseBuffer[0] = 0;
  v40.intvalue = 0;
  memset(&v40.whiteSpaceStart_p, 0, 12);
  v41 = 0;
  v40.data = &v41;
  v40.len = 0;
  v40.allocedAndFlag = -2147483392;
  v36.floatvalue = -3.4028235e38;
  v36.baseBuffer[0] = 0;
  v36.intvalue = 0;
  memset(&v36.whiteSpaceStart_p, 0, 12);
  v37 = 0;
  v36.data = &v37;
  v36.len = 0;
  v36.allocedAndFlag = -2147483392;
  if ( idLexer::ReadToken(this: (idLexer *)((char *)&v31.idResource + 32), token: &v32) )
  {
    while ( v32.type == 5 )
    {
      if ( v32.subtype == 53 )
        goto LABEL_25;
      idVoiceTrack::AllocEvent(this: &v31, result: (vtrEventHandle_t *)this, type: VOICEEVENT_PUNCTUATION);
      v14 = idVoiceEventManager::GetEvent(
              this: &this->voiceEventManager,
              handle: (const vtrEventHandle_t *)v31.__vftable);
      p_name = (idAtomicString *)&v31;
      v16 = *v32.data;
      v14->startMS = 0;
      v14->durationMS = 0;
      HIBYTE(v14[1].__vftable) = v16;
LABEL_37:
      idList<vtrEventHandle_t,5>::Append(
        this: (idList<vtrEventHandle_t,5> *)&v31.resourceListPtr,
        obj: (const vtrEventHandle_t *)p_name);
      if ( !idLexer::ReadToken(this: (idLexer *)((char *)&v31.idResource + 32), token: &v32) )
        goto LABEL_38;
    }
    if ( v32.subtype == 53 )
    {
LABEL_25:
      if ( !idLexer::ReadToken(this: (idLexer *)((char *)&v31.idResource + 32), token: &v36) )
        goto LABEL_31;
      if ( v36.type == 5 )
      {
        idLexer::UnreadToken(this: (idLexer *)((char *)&v31.idResource + 32));
        goto LABEL_31;
      }
    }
    else
    {
      if ( !idLexer::CheckTokenType(this: (idLexer *)((char *)&v31.idResource + 32), type: 5, subtype: 53, token: &v40) )
        goto LABEL_31;
      idStr::Append(this: &v32, text: &v40);
      idLexer::ReadToken(this: (idLexer *)((char *)&v31.idResource + 32), token: &v36);
    }
    idStr::Append(this: &v32, text: &v36);
LABEL_31:
    idVoiceEventManager::AllocEvent(
      this: (idVoiceEventManager *)&v31.name,
      result: (vtrEventHandle_t *)&this->voiceEventManager,
      eventType: VOICEEVENT_TEXT);
    if ( HIWORD(v31.name.str) == 7 || (v17 = 1, SLOWORD(v31.name.str) < 0) )
      v17 = 0;
    if ( v17 != 0 )
      idList<vtrEventHandle_t,5>::Append(
        this: (idList<vtrEventHandle_t,5> *)&this->events,
        obj: (const vtrEventHandle_t *)&v31.name);
    v18 = idVoiceEventManager::GetEvent(this: &this->voiceEventManager, handle: (const vtrEventHandle_t *)v31.name.str);
    idStr::operator=(this: (idStr *)&v18[1], text: v32.data);
    v18->startMS = 0;
    v18->durationMS = 0;
    p_name = &v31.name;
    goto LABEL_37;
  }
LABEL_38:
  idStr::FreeData(this: &v36);
  idStr::FreeData(this: &v40);
  idStr::FreeData(this: &v32);
  idLexer::~idLexer(this: (idLexer *)((char *)&v31.idResource + 32));
LABEL_39:
  idLib::Printf(fmt: "Distributing text event timings:\n");
  resourceError = (signed int)v31.resourceError;
  resourceListPtr = v31.resourceListPtr;
  v21 = 0;
  if ( (int)v31.resourceError > 0 )
  {
    nextOnHashChain = v31.nextOnHashChain;
    v23 = (idResource *)v31.resourceListPtr;
    do
    {
      v24 = (const vtrEventHandle_t *)v23->__vftable;
      v31.nextOnHashChain = v23;
      v25 = idVoiceEventManager::GetEvent(this: &this->voiceEventManager, handle: v24);
      eventType = v25->eventType;
      v27 = v25;
      v28 = v21;
      v29 = 0;
      if ( eventType == 4 )
      {
        v29 = 1;
        v31.nextOnHashChain = (idResource *)(v21 - 1);
        v28 = (((unsigned int)(v21 - 1) >> 31) - 1) & (v21 - 1);
      }
      __twllei(resourceError, 0);
      v25->startMS = (int)(v28 * (_DWORD)nextOnHashChain) / resourceError + v29;
      __twlgei(resourceError & ~(__ROL4__(v28 * (_DWORD)nextOnHashChain, 1) - 1), 0xFFFFFFFF);
      if ( eventType == 3 )
      {
        if ( v21 != 0 )
          idLib::Printf(fmt: " ");
        idLib::Printf(fmt: (const char *)v27[1].startMS);
      }
      else if ( eventType == 4 )
      {
        HIBYTE(v31.trackedMemory) = HIBYTE(v25[1].__vftable);
        BYTE1(v31.trackedMemory) = 0;
        idLib::Printf(fmt: (const char *)&v31.trackedMemory);
      }
      ++v21;
      v23 = (idResource *)((char *)v23 + 4);
    }
    while ( v21 < resourceError );
  }
  idLib::Printf(fmt: "\n");
  idVoiceTrack::OffsetEvents(this, ofs: EVENTOFFSET_FORWARDS, visemesOnly: false);
  this->rebuildFrameRefs = true;
  idVoiceTrack::BuildFrameRefs(this);
  if ( (LOBYTE(v31.staleCount) == 0 || LOBYTE(v31.staleCount) == 2) && resourceListPtr != nullptr )
    idMem::Free(this: &mem, ptr: resourceListPtr, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$229136
// EA  : 0x8263B4F8
// RVA : 0x0063B4F8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229136()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2368 + 96));
}


// ========================================================================
// __unwind$229137
// EA  : 0x8263B520
// RVA : 0x0063B520
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229137()
{
  int v0; // r12

  idLexerUTF8::~idLexerUTF8(this: (idLexerUTF8 *)(v0 - 2368 + 112));
}


// ========================================================================
// __unwind$229138
// EA  : 0x8263B548
// RVA : 0x0063B548
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229138()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 256));
}


// ========================================================================
// __unwind$229139
// EA  : 0x8263B570
// RVA : 0x0063B570
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229139()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 1600));
}


// ========================================================================
// __unwind$229140
// EA  : 0x8263B598
// RVA : 0x0063B598
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229140()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 928));
}


// ========================================================================
// __unwind$229141
// EA  : 0x8263B5C0
// RVA : 0x0063B5C0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229141()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 2368 + 112));
}


// ========================================================================
// __unwind$229142
// EA  : 0x8263B5E8
// RVA : 0x0063B5E8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 592));
}


// ========================================================================
// __unwind$229143
// EA  : 0x8263B610
// RVA : 0x0063B610
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229143()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 1936));
}


// ========================================================================
// __unwind$229144
// EA  : 0x8263B638
// RVA : 0x0063B638
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_229144()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2368 + 1264));
}


// ========================================================================
// ?loadVoiceTrack_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8263B728
// RVA : 0x0063B728
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall loadVoiceTrack_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v2; // cr56
  const char *v3; // r4
  idResource *v4; // r3
  idVoiceTrack *v5; // r24
  int staleCount; // r25
  int v7; // r21
  int v8; // r22
  int v9; // r29
  int num; // r10
  int v11; // r27
  int v12; // r28
  const idVoiceEvent *v13; // r3
  const char *v14; // r17
  double v15; // [sp+20h] [-190h]
  idStr v16; // [sp+50h] [-160h] BYREF
  idStr v17; // [sp+70h] [-140h] BYREF
  int v18; // [sp+90h] [-120h]
  idStaticList<idVoiceEvent const *,32> v19; // [sp+A0h] [-110h] BYREF

  argc = args->argc;
  v2 = args->argc < 2;
  v18 = args->argc;
  if ( v2 )
  {
    idLib::Printf(fmt: "USAGE: loadVoiceTrack [ .vtr file ]\n");
    idLib::Printf(fmt: "  Loads a voice track file and outputs some statistics about the file.\n");
  }
  else
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v17, text: v3);
    v16.len = 0;
    v16.allocedAndFlag = 20;
    v16.data = v16.baseBuffer;
    v16.baseBuffer[0] = 0;
    idStr::ExtractFileExtension(this: &v17, dest: &v16);
    v4 = idResourceList::Load(
           this: &idVoiceTrack::resourceList,
           name: v17.data,
           makeDefault: false,
           skipStaleCheck: false);
    v5 = (idVoiceTrack *)v4;
    if ( v4 != nullptr )
    {
      staleCount = v4[7].staleCount;
      if ( staleCount != 0 )
      {
        idLib::Printf(fmt: "Loaded voice track '%s'.\n", v17.data);
        idLib::Printf(fmt: "  voice track size: %d\n\n", 4 * (v5->numFrameRefs + v5->events.size + 73));
        if ( idVoiceTrack::FindLastEvent(this: v5) >= 0 )
        {
          v19.num = 0;
          v19.granularity = 1;
          v19.size = 32;
          v19.list = v19.staticList;
          v7 = 0;
          v19.memTag = 5;
          v19.listStatic = 1;
          v8 = 0;
          if ( v5->numFrameRefs > 0 )
          {
            v9 = 0;
            do
            {
              idVoiceTrack::GetEventsForFrameRef(
                this: v5,
                frame: v8,
                type: VOICEEVENT_MAX,
                visemeEvents: &v19,
                nonVisemeEvents: nullptr);
              num = v19.num;
              if ( v19.num > v7 )
                v7 = v19.num;
              v11 = 0;
              if ( v19.num > 0 )
              {
                v12 = 0;
                do
                {
                  v13 = v19.list[v12];
                  if ( v13->eventType == 1 || v13->eventType == 0 )
                  {
                    v14 = *(const char **)(4 * (HIBYTE(v13[1].__vftable) + __ROL4__(HIBYTE(v13[1].__vftable), 1))
                                         + *(_DWORD *)(staleCount + 88));
                    v15 = ((double (__fastcall *)(const idVoiceEvent *, int, int))v13->GetWeight)(
                            a1: v13,
                            a2: v9,
                            a3: 66);
                    idLib::Printf(fmt: "%s %.2f%s", v14, v15, (const char *)LODWORD(v15));
                    num = v19.num;
                  }
                  ++v11;
                  ++v12;
                }
                while ( v11 < num );
              }
              ++v8;
              v9 += 66;
            }
            while ( v8 < v5->numFrameRefs );
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v19);
          idStr::FreeData(this: &v16);
        }
        else
        {
          idLib::Warning(fmt: "Error finding last viseme.");
          idStr::FreeData(this: &v16);
        }
      }
      else
      {
        idLib::Warning(fmt: "VoiceTrack '%s' does not have a valid viseme set.", v17.data);
        idStr::FreeData(this: &v16);
      }
    }
    else
    {
      idLib::Warning(fmt: "Failed to load vtr file '%s'...", v17.data);
      idStr::FreeData(this: &v16);
    }
    idStr::FreeData(this: &v17);
  }
}


// ========================================================================
// __unwind$230043
// EA  : 0x8263B9CC
// RVA : 0x0063B9CC
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230043()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 112));
}


// ========================================================================
// __unwind$230044
// EA  : 0x8263B9F4
// RVA : 0x0063B9F4
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$230045
// EA  : 0x8263BA1C
// RVA : 0x0063BA1C
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230045()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 160));
}


// ========================================================================
// ?rewriteVoiceTracks_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8263BA50
// RVA : 0x0063BA50
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall rewriteVoiceTracks_f(const idCmdArgs *args)
{
  int v2; // r27
  idFileList *v3; // r3
  idFileList *v4; // r29
  int v5; // r20
  int v6; // r30
  idVoiceTrack *v7; // r3
  idVoiceTrack *v8; // r28
  idVoiceTrack *v9; // r3
  idVoiceTrack *v10; // r30
  int num; // [sp+50h] [-1A0h]
  idStr v12; // [sp+60h] [-190h] BYREF
  char v13[368]; // [sp+80h] [-170h] BYREF

  idStr::idStr(this: &v12, text: "voicetrack");
  if ( args->argc > 1 )
    idStr::operator=(this: &v12, text: args->argv[1]);
  common->SetRefreshOnPrint(this: common, a2: true);
  v2 = 0;
  if ( Sys_IsFolder(path: v12.data) != FOLDER_YES )
  {
    idLib::Printf(fmt: "^7Loading '%s'...\n", v12.data);
    v9 = (idVoiceTrack *)idResourceList::Load(
                           this: &idVoiceTrack::resourceList,
                           name: v12.data,
                           makeDefault: false,
                           skipStaleCheck: false);
    v10 = v9;
    if ( v9 != nullptr )
    {
      idVoiceTrack::MergeVisemes(this: v9);
      v2 = 1;
      idLib::Printf(fmt: "^2Saving '%s'...\n", v12.data);
      idVoiceTrack::Save(this: v10, fileName: v12.data);
      fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bvtr", a4: v12.data, a5: v13, a6: 256);
      idVoiceTrack::WriteBinary(this: v10, fileName: v13);
    }
    goto LABEL_15;
  }
  v3 = fileSystem->ListFilesTree(this: fileSystem, a2: v12.data, a3: "vtr", a4: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    num = v3->list.num;
    if ( num == 0 )
    {
      idLib::Warning(fmt: "No files found.");
      goto LABEL_16;
    }
    v5 = 0;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        idLib::Printf(fmt: "^7Loading '%s'...\n", v4->list.list[v6].data);
        v7 = (idVoiceTrack *)idResourceList::Load(
                               this: &idVoiceTrack::resourceList,
                               name: v4->list.list[v6].data,
                               makeDefault: false,
                               skipStaleCheck: false);
        v8 = v7;
        if ( v7 != nullptr )
        {
          idVoiceTrack::MergeVisemes(this: v7);
          ++v2;
          idLib::Printf(fmt: "^2Saving '%s'...\n", v4->list.list[v6].data);
          idVoiceTrack::Save(this: v8, fileName: v4->list.list[v6].data);
          fileSystem->FixLongFilename(
            this: fileSystem,
            a2: "generated",
            a3: "bvtr",
            a4: v4->list.list[v6].data,
            a5: v13,
            a6: 256);
          idVoiceTrack::WriteBinary(this: v8, fileName: v13);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v4->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v4);
LABEL_15:
    idLib::Printf(fmt: "Rewrote %d voice tracks.\n", v2);
    common->SetRefreshOnPrint(this: common, a2: false);
  }
LABEL_16:
  idStr::FreeData(this: &v12);
}


// ========================================================================
// __unwind$230254
// EA  : 0x8263BCF8
// RVA : 0x0063BCF8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 96));
}


// ========================================================================
// ?LoadText@idVoiceTrack@@AAA_NPBD@Z
// EA  : 0x8263BD28
// RVA : 0x0063BD28
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::LoadText(idVoiceTrack *this, const char *fileName)
{
  signed int v4; // r29
  char *v6; // [sp+50h] [-120h] BYREF
  idToken v7; // [sp+60h] [-110h] BYREF
  idLexer v8; // [sp+B0h] [-C0h] BYREF

  v4 = fileSystem->ReadFile(this: fileSystem, a2: fileName, a3: (void **)&v6, a4: &this->timestamp);
  if ( v4 < 0 )
    return 0;
  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.floatvalue = -3.4028235e38;
  v7.baseBuffer[0] = 0;
  v7.intvalue = 0;
  memset(&v7.whiteSpaceStart_p, 0, 12);
  idLexer::idLexer(this: &v8, flags_: 0x40000);
  idLexer::LoadMemory(this: &v8, ptr: v6, length_: v4, name: fileName);
  idLexer::ExpectTokenString(this: &v8, string: idVoiceTrack::VOICE_TRACK_NAME);
  idLexer::ExpectTokenType(this: &v8, type: 5, subtype: 46, token: &v7);
  idVoiceTrack::Parse(this, src: &v8);
  idLexer::~idLexer(this: &v8);
  fileSystem->FreeFile(this: fileSystem, a2: v6);
  idStr::FreeData(this: &v7);
  return 1;
}


// ========================================================================
// $M230557
// EA  : 0x8263BE60
// RVA : 0x0063BE60
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void *_M230557()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 368;
  idLib::Warning(fmt: idException::error);
  fileSystem->FreeFile(this: fileSystem, a2: *(void **)(v1 + 80));
  return &_LN10;
}


// ========================================================================
// __unwind$230471
// EA  : 0x8263BEB0
// RVA : 0x0063BEB0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230471()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$230472
// EA  : 0x8263BED8
// RVA : 0x0063BED8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void _unwind_230472()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 368 + 176));
}


// ========================================================================
// ?GetEvents@idVoiceTrack@@QBAXV?$idTypesafeNumber@HW4millisecondUnique_t@@@@00W4voiceEvent_t@@AAV?$idStaticList@PBVidVoiceEvent@@$0CA@@@2@Z
// EA  : 0x8263BF00
// RVA : 0x0063BF00
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::GetEvents(
        idVoiceTrack *this,
        const idTypesafeNumber<int,enum millisecondUnique_t> *curTimeMS,
        const idTypesafeNumber<int,enum millisecondUnique_t> *lastTimeMS,
        const idTypesafeNumber<int,enum millisecondUnique_t> *loopLengthMS,
        voiceEvent_t type,
        idStaticList<idVoiceEvent const *,32> *visemeEvents,
        idStaticList<idVoiceEvent const *,32> *nonVisemeEvents)
{
  int value; // r9
  int v14; // r10
  int v15; // r31
  signed int v16; // r11
  int v17; // r6
  int v18; // r30
  int v19; // r10
  int numFrameRefs; // r11
  int v21; // r10
  int v22; // r10
  int i; // r31
  int v24; // r10
  idTypesafeNumber<int,enum millisecondUnique_t> v25; // [sp+50h] [-50h] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v26[19]; // [sp+54h] [-4Ch] BYREF

  value = curTimeMS->value;
  if ( curTimeMS->value >= 0 )
  {
    v14 = lastTimeMS->value;
    v15 = 0;
    v16 = loopLengthMS->value;
    v17 = 0;
    if ( lastTimeMS->value > 0 )
    {
      if ( v16 != 0 )
      {
        v17 = v14 / v16;
        __twllei(v16, 0);
        v15 = v14 % v16 / 66;
        __twlgei(v16 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
      }
      else
      {
        v15 = v14 / 66;
      }
    }
    v18 = 0;
    v19 = 0;
    if ( value > 0 )
    {
      if ( v16 != 0 )
      {
        v19 = value / v16;
        __twllei(v16, 0);
        v18 = value % v16 / 66;
        __twlgei(v16 & ~(__ROL4__(value, 1) - 1), 0xFFFFFFFF);
      }
      else
      {
        v18 = value / 66;
      }
    }
    numFrameRefs = this->numFrameRefs;
    if ( numFrameRefs > 0 )
    {
      if ( v17 == v19 )
      {
        for ( ; v15 <= v18; ++v15 )
        {
          v21 = curTimeMS->value;
          v25.value = lastTimeMS->value;
          v26[0].value = v21;
          idVoiceTrack::GetEvents(
            this,
            frame: v15,
            curTimeMS: v26,
            lastTimeMS: &v25,
            type,
            visemeEvents,
            nonVisemeEvents);
        }
      }
      else if ( v17 < v19 )
      {
        if ( v15 < numFrameRefs )
        {
          do
          {
            v22 = curTimeMS->value;
            v26[0] = (idTypesafeNumber<int,enum millisecondUnique_t>)lastTimeMS->value;
            v25.value = v22;
            idVoiceTrack::GetEvents(
              this,
              frame: v15++,
              curTimeMS: &v25,
              lastTimeMS: v26,
              type,
              visemeEvents,
              nonVisemeEvents);
          }
          while ( v15 < this->numFrameRefs );
        }
        for ( i = 0; i <= v18; ++i )
        {
          v24 = curTimeMS->value;
          v26[0] = (idTypesafeNumber<int,enum millisecondUnique_t>)lastTimeMS->value;
          v25.value = v24;
          idVoiceTrack::GetEvents(this, frame: i, curTimeMS: &v25, lastTimeMS: v26, type, visemeEvents, nonVisemeEvents);
        }
      }
      if ( vo_showFrames.valueInteger > 0 )
        idLib::Printf(
          fmt: "(%d): GetEvents: frame %d, %d events\n",
          curTimeMS->value,
          v18,
          visemeEvents->num + nonVisemeEvents->num);
    }
  }
}


// ========================================================================
// ?LoadResource@idVoiceTrack@@UAAXXZ
// EA  : 0x8263C1C8
// RVA : 0x0063C1C8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __fastcall idVoiceTrack::LoadResource(idVoiceTrack *this)
{
  idVoiceTrack::idFrameRef *frameRefs; // r4
  const char *LocalizedName; // r29
  unsigned int v4; // r3
  char v5[256]; // [sp+50h] [-230h] BYREF
  char v6; // [sp+150h] [-130h] BYREF

  idVoiceEventManager::Free(this: &this->voiceEventManager, eventList: (idList<vtrEventHandle_t,5> *)&this->events);
  frameRefs = this->frameRefs;
  if ( frameRefs != nullptr )
  {
    idMem::Free(this: &mem, ptr: frameRefs, align: ALIGN_16);
    this->frameRefs = nullptr;
  }
  LocalizedName = idResource::GetLocalizedName(inName: this->name.str, outName: &v6, sizeOfOutName: 256);
  if ( idLib::production < PROD_PRODUCTION )
  {
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bvtr", a4: LocalizedName, a5: v5, a6: 256);
    if ( s_noSound.valueInteger == 0 )
    {
      v4 = fileSystem->GetTimestamp(this: fileSystem, a2: LocalizedName, a3: false);
      if ( (unsigned __int8)idVoiceTrack::LoadBinary(this, fileName: v5, srcTimestamp: v4) == 0 )
      {
        if ( (unsigned __int8)idVoiceTrack::LoadText(this, fileName: LocalizedName) != 0 )
          idVoiceTrack::WriteBinary(this, fileName: v5);
        else
          idResource::SetResourceError(this: &this->idResource, fmt: "Voicetrack '%s' does not exist.", LocalizedName);
      }
    }
  }
  else
  {
    fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bmvtr", a4: this->name.str, a5: v5, a6: 256);
    if ( (unsigned __int8)idVoiceTrack::LoadBinary(this, fileName: v5, srcTimestamp: 0) == 0 )
    {
      fileSystem->FixLongFilename(this: fileSystem, a2: "generated", a3: "bvtr", a4: LocalizedName, a5: v5, a6: 256);
      if ( (unsigned __int8)idVoiceTrack::LoadBinary(this, fileName: v5, srcTimestamp: 0) == 0 )
        idLib::Warning(fmt: "Pre-load '%s' failed.", v5);
    }
  }
}


// ========================================================================
// ?GetSubtitles@idVoiceTrack@@QBAHAAV?$idList@VidSubtitleText@idVoiceTrack@@$04@@_N@Z
// EA  : 0x8263C430
// RVA : 0x0063C430
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

int __fastcall idVoiceTrack::GetSubtitles(
        idVoiceTrack *this,
        idList<idVoiceTrack::idSubtitleText,5> *subtitles,
        const bool mergePunctuation)
{
  idVoiceTrack::idSubtitleText *v6; // r29
  bool v7; // r22
  int v8; // r23
  int i; // r26
  const idVoiceEvent *Event; // r3
  int eventType; // r11
  const idVoiceEvent *v12; // r30
  idVoiceTrack::idSubtitleText *v13; // r31
  char v14; // r31
  bool v15; // r10
  idVoiceTrack::idSubtitleText *v16; // r3
  char v17; // r20

  if ( subtitles->size < 0 )
    idList<idPlayer::jobMessage_t,5>::Clear(this: subtitles);
  v6 = nullptr;
  v7 = false;
  v8 = 0;
  subtitles->num = __CFADD__(-subtitles->size, subtitles->size ^ 0x80000000) ? 0 : subtitles->size;
  if ( this->events.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      Event = idVoiceEventManager::GetEvent(
                this: &this->voiceEventManager,
                handle: *(const vtrEventHandle_t **)&this->events.list[i]);
      eventType = Event->eventType;
      v12 = Event;
      if ( eventType == 3 )
        break;
      if ( eventType == 4 )
      {
        v14 = HIBYTE(Event[1].__vftable);
        if ( mergePunctuation && v14 != 45 )
        {
          if ( v14 == 34 || v14 == 39 )
          {
            v7 = (_cntlzw(v7) & 0x20) != 0;
            v15 = false;
          }
          else
          {
            v15 = v14 == 40 || v14 == 91;
          }
          if ( v15 || v6 == nullptr )
          {
            v6 = idList<idVoiceTrack::idSubtitleText,5>::Alloc(this: subtitles);
            idStr::operator=(this: &v6->word, c: v14);
            v6->time.value = v12->startMS;
          }
          else
          {
            idStr::operator+=(this: &v6->word, a: HIBYTE(Event[1].__vftable));
            v6->time.value = v12->startMS;
          }
          goto LABEL_22;
        }
        v16 = idList<idVoiceTrack::idSubtitleText,5>::Alloc(this: subtitles);
        v17 = HIBYTE(v12[1].__vftable);
        v13 = v16;
        idStr::EnsureAlloced(this: &v16->word, amount: 2, keepold: true, geometricGrowth: false);
        *v13->word.data = v17;
        v13->word.data[1] = 0;
        v13->word.len = (-v17 & (unsigned int)~v17) >> 31;
        v13->time.value = v12->startMS;
        goto LABEL_21;
      }
LABEL_22:
      if ( ++v8 >= this->events.num )
        return subtitles->num;
    }
    v13 = idList<idVoiceTrack::idSubtitleText,5>::Alloc(this: subtitles);
    idStr::operator=(this: &v13->word, text: (const char *)v12[1].startMS);
    v13->time.value = v12->startMS;
LABEL_21:
    v6 = v13;
    goto LABEL_22;
  }
  return subtitles->num;
}


// ========================================================================
// `dynamic initializer for 'idVoiceTrack::resourceList''
// EA  : 0x83337500
// RVA : 0x01337500
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idVoiceTrack::resourceList__()
{
  idResourceList::idResourceList(this: &idVoiceTrack::resourceList, typeName: "voicetrack");
  idVoiceTrack::resourceList.__vftable = (idTypedResourceList<idVoiceTrack>_vtbl *)&idTypedResourceList<idVoiceTrack>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idVoiceTrack::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'vo_showFrames''
// EA  : 0x83337550
// RVA : 0x01337550
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vo_showFrames__()
{
  idCVar::idCVar(
    this: &vo_showFrames,
    name: "vo_showFrames",
    value: "0",
    flags: 2,
    description: "1 = show frame numbers for GetEvents()",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vo_showFrames__);
}


// ========================================================================
// `dynamic initializer for 'loadVoiceTrack_v''
// EA  : 0x833375A8
// RVA : 0x013375A8
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__loadVoiceTrack_v__()
{
  return idCommandLink::idCommandLink(
           this: &loadVoiceTrack_v,
           cmdName: "loadVoiceTrack",
           function: loadVoiceTrack_f,
           description: "Loads a voice track file and outputs some statistics about the file",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'rewriteVoiceTracks_v''
// EA  : 0x833375D0
// RVA : 0x013375D0
// PDB : w:\tech5\engine\decls\voiceovers\voicetrack.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__rewriteVoiceTracks_v__()
{
  return idCommandLink::idCommandLink(
           this: &rewriteVoiceTracks_v,
           cmdName: "rewriteVoiceTracks",
           function: rewriteVoiceTracks_f,
           description: "loads all voice tracks in the base/voicetrack folder and rewrites them.",
           argCompletion: nullptr);
}

