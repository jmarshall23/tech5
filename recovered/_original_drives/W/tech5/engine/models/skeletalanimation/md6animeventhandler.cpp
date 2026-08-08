
// ========================================================================
// ?FetchNextEvent@idAnimEventHandler@@QAA_NAAPBVidMD6Anim@@AAPBVidMD6AnimEvent@@@Z
// EA  : 0x8283B7D8
// RVA : 0x0083B7D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

int __fastcall idAnimEventHandler::FetchNextEvent(
        idAnimEventHandler *this,
        const idMD6Anim **animHandle,
        const idMD6AnimEvent **ev)
{
  int nextEventToFetch; // r10

  nextEventToFetch = this->nextEventToFetch;
  if ( nextEventToFetch < this->triggeredEvents.num )
  {
    *animHandle = this->triggeredEvents.list[nextEventToFetch].anim;
    *ev = this->triggeredEvents.list[this->nextEventToFetch++].event;
    return 1;
  }
  else
  {
    *ev = nullptr;
    return 0;
  }
}


// ========================================================================
// ?OffsetTimes@idAnimEventHandler@@QAAXV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x8283B850
// RVA : 0x0083B850
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::OffsetTimes(
        idAnimEventHandler *this,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *timeOffset)
{
  int v2; // r11
  int v3; // r10
  idAnimEventHandler::trackedEvent_t *v4; // r9

  v2 = 0;
  if ( this->trackedEvents.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = &this->trackedEvents.list[v3++];
      v4->startTime += timeOffset->value;
    }
    while ( v2 < this->trackedEvents.num );
  }
}


// ========================================================================
// ??1idAnimEventHandler@@QAA@XZ
// EA  : 0x8283BA28
// RVA : 0x0083BA28
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::~idAnimEventHandler(idAnimEventHandler *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggeredEvents);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$221077_0
// EA  : 0x8283BA70
// RVA : 0x0083BA70
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _unwind_221077_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idAnimEventHandler@@QAA@XZ
// EA  : 0x8283BC78
// RVA : 0x0083BC78
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

idAnimEventHandler *__fastcall idAnimEventHandler::idAnimEventHandler(idAnimEventHandler *this)
{
  idStaticList<idAnimEventHandler::trackedEvent_t,32>::idStaticList<idAnimEventHandler::trackedEvent_t,32>(this: &this->trackedEvents);
  idStaticList<idAnimEventHandler::triggeredEvent_t,32>::idStaticList<idAnimEventHandler::triggeredEvent_t,32>(this: &this->triggeredEvents);
  this->nextEventToFetch = 0;
  return this;
}


// ========================================================================
// ?AddPlayLeafToFrameList@idAnimEventHandler@@AAAXAAV?$idStaticList@UeventInfo_t@idAnimEventHandler@@$0EA@@@PBVidMD6LeafPlay@@HHH_N@Z
// EA  : 0x8283C1F8
// RVA : 0x0083C1F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::AddPlayLeafToFrameList(
        idAnimEventHandler *this,
        idStaticList<idAnimEventHandler::eventInfo_t,64> *frameList,
        idMD6LeafPlay *play,
        int curTime,
        int previousTime,
        int ticksPerSec,
        bool canSkip)
{
  idAnimEventHandler::eventInfo_t *v12; // r26

  v12 = idList<idAnimEventHandler::eventInfo_t,5>::Alloc(this: frameList);
  v12->anim = play->anim;
  v12->lastFrame = idMD6LeafPlay::GetFrame(this: play, gameTime: previousTime, ticksPerSec);
  v12->curFrame = idMD6LeafPlay::GetFrame(this: play, gameTime: curTime, ticksPerSec);
  v12->leaf = play;
  v12->loopCount = idMD6LeafPlay::GetLoopCount(this: play, gameTime: curTime, ticksPerSec);
  v12->startTime = play->startTime;
  v12->initCounter = play->initCounter;
  v12->canSkip = canSkip;
}


// ========================================================================
// ?WalkTree@idAnimEventHandler@@AAAXAAV?$idStaticList@UeventInfo_t@idAnimEventHandler@@$0EA@@@PBVidMD6Node@@HHH@Z
// EA  : 0x8283C290
// RVA : 0x0083C290
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::WalkTree(
        idAnimEventHandler *this,
        idStaticList<idAnimEventHandler::eventInfo_t,64> *frameList,
        const idMD6Node *node,
        int curTime,
        const char *previousTime,
        int ticksPerSec)
{
  unsigned __int64 v10; // r6
  int v13; // r28
  char *v14; // r30
  const idMD6Node **v15; // r29
  float *v16; // r5
  char v17; // r9
  int type; // r11
  char v19; // r11
  bool v20; // zf
  char v21; // r10
  char v22; // r11
  char v23; // r11
  unsigned int v24; // r11
  unsigned int v25; // r10
  int v26; // r8
  const idMD6Node *v27; // [sp+50h] [-110h]
  const idMD6Node *v28; // [sp+50h] [-110h]
  int size; // [sp+50h] [-110h]
  idPLogScope v30; // [sp+58h] [-108h] BYREF
  char v31; // [sp+60h] [-100h] BYREF
  const idMD6Node *v32; // [sp+80h] [-E0h] BYREF

  LODWORD(v10) = "idAnimEventHandler::WalkTree";
  HIDWORD(v10) = 1;
  idPLogScope::idPLogScope(this: &v30, pl: &pLog, gMask: v10, label: previousTime);
  if ( frameList->num >= 64 || node == nullptr )
  {
LABEL_33:
    idPLogScope::~idPLogScope(this: &v30);
    return;
  }
  v32 = node;
  v13 = 0;
  v31 = 0;
  v14 = &v31;
  v15 = &v32;
  while ( 1 )
  {
    v16 = (float *)*v15;
    v17 = *v14;
    type = (*v15)->type;
    if ( (*v15)->type == 0 || type == 3 || type == 4 || (v20 = type != 5, v19 = 0, !v20) )
      v19 = 1;
    if ( v19 != 0 )
    {
      v21 = *v14;
      if ( (*((unsigned __int8 *)v16 + 21) < 3u || *((unsigned __int8 *)v16 + 21) > 6u) && *((_BYTE *)v16 + 20) == 0 )
      {
        if ( v16[6] <= 0.5 || (v22 = 1, *((_DWORD *)v16 + 2) == 0) )
          v22 = 0;
        v17 |= v22;
        if ( v16[6] > 0.5 || (v23 = 1, *((_DWORD *)v16 + 1) == 0) )
          v23 = 0;
        v21 = *v14 | v23;
      }
      --v13;
      --v14;
      --v15;
      v27 = *((const idMD6Node **)v16 + 1);
      if ( v27 != nullptr )
      {
        ++v13;
        *++v15 = v27;
        *++v14 = v17;
      }
      v28 = *((const idMD6Node **)v16 + 2);
      if ( v28 != nullptr )
      {
        ++v13;
        *++v15 = v28;
        *++v14 = v21;
      }
      goto LABEL_32;
    }
    if ( *(_BYTE *)v16 == 6 )
    {
      v24 = *((_DWORD *)v16 + 2);
      --v13;
      --v14;
      --v15;
      if ( v24 != 0 )
      {
        v25 = *((unsigned __int16 *)v16 + 44);
        v26 = *((_DWORD *)v16 + 1);
        if ( *(_DWORD *)(((4 * (((__PAIR64__(v24 >> 31, v25) - v24) >> 32) & v25)) & 0x3FFFC) + v26) != 0 )
        {
          ++v13;
          ++v14;
          ++v15;
          *v14 = v17;
          *v15 = *(const idMD6Node **)(((4 * (((__PAIR64__(v24 >> 31, v25) - __PAIR64__(v25 >> 31, v24)) >> 32) & v25))
                                      & 0x3FFFC)
                                     + v26);
        }
      }
      goto LABEL_32;
    }
    if ( *(_BYTE *)v16 == 2 )
      break;
LABEL_31:
    --v15;
    --v14;
    --v13;
LABEL_32:
    if ( v13 < 0 )
      goto LABEL_33;
  }
  size = frameList->size;
  if ( frameList->num < size )
  {
    idAnimEventHandler::AddPlayLeafToFrameList(
      this,
      frameList,
      play: (idMD6LeafPlay *)v16,
      curTime,
      (int)previousTime,
      ticksPerSec,
      canSkip: v17);
    goto LABEL_31;
  }
  idLib::Error(fmt: "more than %d anim events", size);
  _LN132_1();
}


// ========================================================================
// $LN132_1
// EA  : 0x8283C544
// RVA : 0x0083C544
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _LN132_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 88));
}


// ========================================================================
// ?BuildEventList@idAnimEventHandler@@AAAXAAV?$idStaticList@UtriggeredEvent_t@idAnimEventHandler@@$0CA@@@ABV?$idStaticList@UeventInfo_t@idAnimEventHandler@@$0EA@@@PBVidDeclMD6@@HHHQBHH@Z
// EA  : 0x8283C578
// RVA : 0x0083C578
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::BuildEventList(
        idAnimEventHandler *this,
        idList<idVehicleState *,5> *eventList,
        const idStaticList<idAnimEventHandler::eventInfo_t,64> *frameList,
        const idDeclMD6 *decl,
        const char *curTime,
        int previousTime,
        int ticksPerSec,
        const int *onlyEvents,
        const int onlyNumEvents,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idAnimEventHandler *v29; // r29
  unsigned __int64 v32; // r6
  int v33; // r22
  idAnimEventHandler *v34; // r24
  int v35; // r19
  unsigned __int8 *v36; // r16
  const char *v37; // r18
  const char *v38; // r21
  int v39; // r20
  const char *v40; // r17
  idAnimEventHandler::eventInfo_t *list; // r10
  const idEventDef *v42; // r28
  const char *v43; // r30
  int v44; // r3
  char v45; // r11
  const char *v46; // r9
  int v47; // r23
  const char *v48; // r25
  char v49; // r29
  int v50; // r26
  int v51; // r11
  const int *v52; // r10
  char v53; // r3
  const idEventDef *EventCommand; // r3
  int v55; // r27
  bool v56; // r11
  char v57; // r11
  int v58; // r9
  idAnimEventHandler::trackedEvent_t *v59; // r8
  int v60; // r10
  idAnimEventHandler::trackedEvent_t *v61; // r11
  const char *v62; // r30
  int v63; // r3
  char v64; // r11
  const char *v65; // r10
  const char *v66; // r5
  const char *v67; // r30
  int v68; // r3
  char v69; // r11
  const char *v70; // r10
  const char *v71; // r5
  idList<idVehicleState *,5> *v72; // r30
  int num; // r11
  int v74; // r10
  int v75; // r11
  idAnimEventHandler::triggeredEvent_t *v76; // r9
  int v77; // r11
  int v78; // r11
  int v79; // r28
  const idMD6Anim **v80; // r30
  int v81; // r29
  idAnimEventHandler::eventInfo_t *v82; // r11
  idMD6LeafPlay *leaf; // r3
  int Frame; // r11
  const idEventDef *v85; // r3
  int v86; // r11
  const char *v87; // r29
  const char *v88; // r4
  int v89; // r3
  char v90; // r11
  const char *v91; // r8
  const idMD6Anim *name; // r5
  int v93; // r11
  int v94; // r11
  idAnimEventHandler::trackedEvent_t *v95; // r7
  int v96; // ctr
  __int16 *p_eventFrame; // r11
  int v98; // r11
  int v99; // r29
  int v100; // r8
  idAnimEventHandler::trackedEvent_t *v101; // r4
  int v102; // r3
  idAnimEventHandler::trackedEvent_t *v103; // r7
  const idMD6Anim *anim; // r5
  int v105; // r11
  int loopCount; // r10
  idMD6AnimData *animData; // r11
  int numFrames; // r9
  int v109; // r9
  signed int frameRate; // r10
  idMD6AnimData *v111; // r10
  const char *v112; // r9
  int v113; // r11
  int v114; // r10
  __int16 eventFrame; // r9
  int v116; // r11
  idAnimEventHandler::trackedEvent_t *v117; // r9
  __int16 *v118; // r10
  int j; // ctr
  idAnimEventHandler::trackedEvent_t *v120; // r9
  __int16 *v121; // r10
  int i; // ctr
  int v123; // r26
  int v124; // r27
  int v125; // r30
  const idEventDef *v126; // r3
  int v127; // r11
  const char **p_name; // r28
  const char *v129; // r29
  const char *v130; // r4
  int v131; // r3
  char v132; // r11
  const char *v133; // r8
  const char *v134; // r5
  idPLog *pLog; // r29
  idPLog::logEntry_t *v136; // r30
  int v137; // r3
  __int64 totalTicks; // r11
  __int64 v139; // r9
  int valueInteger; // [sp+54h] [-10Ch]
  int size; // [sp+64h] [-FCh]
  int v142; // [sp+64h] [-FCh]
  idPLogScope v143; // [sp+68h] [-F8h] BYREF
  idList<idVehicleState *,5> v144; // [sp+70h] [-F0h] BYREF
  int v145; // [sp+80h] [-E0h] BYREF

  v29 = this;
  LODWORD(v32) = "idAnimEventHandler::BuildEventList";
  HIDWORD(v32) = 1;
  idPLogScope::idPLogScope(this: &v143, pl: &::pLog, gMask: v32, label: curTime);
  valueInteger = anim_debugEvents.valueInteger;
  if ( eventList->size < 0 )
    idList<idThread *,58>::Clear(this: eventList);
  eventList->num = __CFADD__(-eventList->size, eventList->size ^ 0x80000000) ? 0 : eventList->size;
  v33 = 0;
  if ( frameList->num > 0 )
  {
    v34 = (idAnimEventHandler *)a28;
    v35 = 16;
    v36 = &consoleFont[21088];
    v37 = (const char *)&mem;
    v38 = "^2AnimEvent(%d)(triggering):^8 '^7%s^8', curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p^8, anim '^7%s^8'\n";
    v39 = (int)"^3AnimEvent(%d)(skipping):^8 '^7%s^8', curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p^8, anim '^7%s^8'\n";
    v40 = "^3AnimEvent(%d)(no anim events found):^8 curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p^8, anim '^7%s^8'\n";
    do
    {
      list = frameList->list;
      v144.size = 16;
      v144.num = 0;
      v144.granularity = 1;
      v144.listStatic = 1;
      v144.list = (idVehicleState **)&v145;
      v42 = (const idEventDef *)&list[v33];
      v144.memTag = 5;
      if ( idDeclMD6::FindAnimEvents(
             this: decl,
             anim: (const idMD6Anim *)v42->name,
             startFrame: LOWORD(v42->argNames),
             endFrame: HIWORD(v42->returnType),
             events: &v144) )
      {
        v47 = 0;
        if ( v144.num > 0 )
        {
          v48 = nullptr;
          do
          {
            v49 = 0;
            v50 = *(int *)((char *)v144.list + (unsigned int)v48);
            if ( a28 > 0 )
            {
              v49 = 1;
              v51 = 0;
              v52 = onlyEvents;
              do
              {
                if ( v49 == 0 )
                  break;
                ++v51;
                v53 = (*v52++ == *(__int16 *)(v50 + 32)) - 1;
                v49 &= v53;
              }
              while ( v51 < a28 );
            }
            EventCommand = idEventDef::GetEventCommand(eventnum: *(__int16 *)(v50 + 32));
            v55 = (int)EventCommand;
            v56 = EventCommand != nullptr && EventCommand->isClientSafe;
            if ( !v56 && common->IsClient(this: common) )
              v49 = 1;
            if ( v55 != 0 )
              v57 = *(_BYTE *)(v55 + 32);
            else
              v57 = 0;
            if ( v57 != 0 && HIBYTE(v42->numargs) != 0 )
              v49 = 1;
            if ( v49 == 0 )
            {
              v58 = this->trackedEvents.num - 1;
              if ( v58 >= 0 )
              {
                v59 = this->trackedEvents.list;
                v60 = v58;
                while ( 1 )
                {
                  v61 = &v59[v60];
                  if ( v59[v60].eventId.value == *(_DWORD *)(v50 + 36)
                    && (unsigned __int16)v61->loopCount == LOWORD(v42->returnType)
                    && v61->initCounter == HIBYTE(v42->argNames) )
                  {
                    break;
                  }
                  --v58;
                  --v60;
                  if ( v58 < 0 )
                    goto LABEL_58;
                }
                v49 = 1;
                if ( valueInteger > 1 )
                {
                  if ( v42->name != nullptr )
                    v62 = *((const char **)v42->name + 2);
                  else
                    v62 = &byte_8200D768;
                  if ( *anim_debugEvents_Name.valueString.data == 0
                    || (v63 = idStr::Find(
                                searchIn: v62,
                                searchFor: anim_debugEvents_Name.valueString.data,
                                casesensitive: true,
                                start: 0,
                                end: -1),
                        v64 = 0,
                        v63 != -1) )
                  {
                    v64 = 1;
                  }
                  if ( v64 != 0 )
                  {
                    v65 = v62;
                    if ( v62 == nullptr )
                      v65 = "NULL";
                    if ( v55 != 0 )
                      v66 = *(const char **)v55;
                    else
                      v66 = "<NULL>";
                    idLib::Printf(
                      fmt: "^3AnimEvent(%d)(skipping):^8 '^7%s^8', curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p^8"
                      ", anim '^7%s^8'\n",
                      curTime,
                      v66,
                      HIWORD(v42->returnType),
                      LOWORD(v42->argNames),
                      SLOWORD(v42->returnType),
                      v42->formatspec,
                      v65);
                  }
                }
              }
LABEL_58:
              if ( v49 == 0 )
              {
                if ( valueInteger > 0 )
                {
                  if ( v42->name != nullptr )
                    v67 = *((const char **)v42->name + 2);
                  else
                    v67 = &byte_8200D768;
                  if ( *anim_debugEvents_Name.valueString.data == 0
                    || (v68 = idStr::Find(
                                searchIn: v67,
                                searchFor: anim_debugEvents_Name.valueString.data,
                                casesensitive: true,
                                start: 0,
                                end: -1),
                        v69 = 0,
                        v68 != -1) )
                  {
                    v69 = 1;
                  }
                  if ( v69 != 0 )
                  {
                    v70 = v67;
                    if ( v67 == nullptr )
                      v70 = "NULL";
                    if ( v55 != 0 )
                      v71 = *(const char **)v55;
                    else
                      v71 = "<NULL>";
                    idLib::Printf(
                      fmt: "^2AnimEvent(%d)(triggering):^8 '^7%s^8', curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p"
                      "^8, anim '^7%s^8'\n",
                      curTime,
                      v71,
                      HIWORD(v42->returnType),
                      LOWORD(v42->argNames),
                      SLOWORD(v42->returnType),
                      v42->formatspec,
                      v70);
                  }
                }
                v72 = eventList;
                num = eventList->num;
                size = eventList->size;
                if ( num >= size )
                {
                  idLib::Error(fmt: "more than %d triggered events", size);
                  goto _LN442_0;
                }
                idList<idAnimEventHandler::triggeredEvent_t,5>::PreAllocateWithGranularity(
                  this: (idList<idAnimEventHandler::triggeredEvent_t,5> *)eventList,
                  newSize: num + 1);
                v74 = eventList->size;
                v75 = eventList->num;
                v76 = (idAnimEventHandler::triggeredEvent_t *)eventList->list;
                if ( v75 >= v74 )
                {
                  v77 = (int)&v76[v74 - 1];
                }
                else
                {
                  eventList->num = v75 + 1;
                  v77 = (int)&v76[v75];
                }
                *(_DWORD *)(v77 + 8) = *(_DWORD *)(v50 + 36);
                *(_WORD *)(v77 + 4) = *(_WORD *)(v50 + 32);
                *(_DWORD *)(v77 + 12) = v42->name;
                *(_WORD *)(v77 + 16) = *(_WORD *)(v50 + 34);
                *(_WORD *)(v77 + 18) = v42->returnType;
                *(_DWORD *)v77 = v42->argTypes;
                *(_BYTE *)(v77 + 6) = HIBYTE(v42->argNames);
                *(_DWORD *)(v77 + 20) = v50;
              }
            }
            ++v47;
            v48 += 4;
          }
          while ( v47 < v144.num );
        }
      }
      else if ( valueInteger > 3 )
      {
        if ( v42->name != nullptr )
          v43 = *((const char **)v42->name + 2);
        else
          v43 = &byte_8200D768;
        if ( *anim_debugEvents_Name.valueString.data == 0
          || (v44 = idStr::Find(
                      searchIn: v43,
                      searchFor: anim_debugEvents_Name.valueString.data,
                      casesensitive: true,
                      start: 0,
                      end: -1),
              v45 = 0,
              v44 != -1) )
        {
          v45 = 1;
        }
        if ( v45 != 0 )
        {
          v46 = v43;
          if ( v43 == nullptr )
            v46 = "NULL";
          idLib::Printf(
            fmt: "^3AnimEvent(%d)(no anim events found):^8 curFrame ^7%d^8, lastFrame ^7%d^8, loop ^7%d^8, leaf ^7%p^8, anim '^7%s^8'\n",
            curTime,
            HIWORD(v42->returnType),
            LOWORD(v42->argNames),
            SLOWORD(v42->returnType),
            v42->formatspec,
            v46);
        }
      }
      if ( v144.listStatic == 0 || v144.listStatic == 2 )
      {
        if ( v144.list != nullptr )
          idMem::Free(this: &mem, ptr: v144.list, align: ALIGN_16);
        v144.list = nullptr;
        v144.size = 0;
      }
      v78 = frameList->num;
      ++v33;
      v144.num = 0;
    }
    while ( v33 < v78 );
    v29 = this;
  }
  v50 = v29->trackedEvents.num - 1;
  if ( v50 < 0 )
  {
    v38 = curTime;
    v33 = ticksPerSec;
    v34 = this;
    v39 = valueInteger;
    v35 = (int)&anim_debugEvents_Name;
    v37 = "<NULL>";
    v40 = "NULL";
    v36 = (unsigned __int8 *)&byte_8200D768;
  }
  else
  {
    v38 = curTime;
    v33 = ticksPerSec;
    v34 = this;
    v39 = valueInteger;
    v55 = 20 * v50;
    v35 = (int)&anim_debugEvents_Name;
    v37 = "<NULL>";
    v40 = "NULL";
    v36 = (unsigned __int8 *)&byte_8200D768;
    v48 = "^1AnimEvent(%d)(untracking):^8 '^7%s^8', eventFrame ^7%d^8, loop ^7%d^8, anim = '^7%s^8'\n";
    do
    {
      v79 = 0;
      v80 = (const idMD6Anim **)((char *)v34->trackedEvents.list + v55);
      if ( frameList->num > 0 )
      {
        v81 = 0;
        do
        {
          v82 = &frameList->list[v81];
          if ( v80[3] == v82->anim
            && *((unsigned __int16 *)v80 + 9) == (unsigned __int16)v82->loopCount
            && *((unsigned __int8 *)v80 + 6) == v82->initCounter )
          {
            leaf = (idMD6LeafPlay *)v82->leaf;
            Frame = -1;
            if ( leaf->type == 2 )
              Frame = idMD6LeafPlay::GetFrame(this: leaf, gameTime: (const int)v38, ticksPerSec: v33);
            if ( Frame >= *((__int16 *)v80 + 8) )
              break;
          }
          ++v79;
          ++v81;
        }
        while ( v79 < frameList->num );
      }
      if ( v79 >= frameList->num )
      {
        if ( v39 > 2 )
        {
          v72 = (idList<idVehicleState *,5> *)((char *)v34->trackedEvents.list + v55);
          v85 = idEventDef::GetEventCommand(eventnum: SHIWORD(v72->num));
          v86 = *(_DWORD *)&v72->granularity;
          v42 = v85;
          if ( v86 != 0 )
            v87 = *(const char **)(v86 + 8);
          else
_LN442_0:
            v87 = (const char *)v36;
          v88 = *(const char **)(v35 + 4);
          if ( *v88 == 0
            || (v89 = idStr::Find(searchIn: v87, searchFor: v88, casesensitive: true, start: 0, end: -1),
                v90 = 0,
                v89 != -1) )
          {
            v90 = 1;
          }
          if ( v90 != 0 )
          {
            v91 = v87;
            if ( v87 == nullptr )
              v91 = v40;
            if ( v42 != nullptr )
              name = (const idMD6Anim *)v42->name;
            else
              name = (const idMD6Anim *)v37;
            idLib::Printf(fmt: v48, v38, name, SHIWORD(v72[1].list), SLOWORD(v72[1].list), v91);
          }
        }
        if ( v50 >= 0 )
        {
          v93 = v34->trackedEvents.num;
          if ( v50 < v93 )
          {
            v94 = v93 - 1;
            v34->trackedEvents.num = v94;
            if ( v50 != v94 )
            {
              v95 = (idAnimEventHandler::trackedEvent_t *)((char *)v34->trackedEvents.list + v55 - 4);
              v96 = 5;
              p_eventFrame = &v34->trackedEvents.list[v94 - 1].eventFrame;
              do
              {
                p_eventFrame += 2;
                v95 = (idAnimEventHandler::trackedEvent_t *)((char *)v95 + 4);
                v95->startTime = *(_DWORD *)p_eventFrame;
                --v96;
              }
              while ( v96 != 0 );
            }
          }
        }
      }
      --v50;
      v55 -= 20;
    }
    while ( v50 >= 0 );
  }
  v98 = eventList->num;
  if ( v34->trackedEvents.num + v98 >= v34->trackedEvents.size )
  {
    v99 = 0;
    if ( v98 > 0 )
    {
      do
      {
        v100 = 0;
        v142 = v34->trackedEvents.num;
        if ( v142 > 0 )
        {
          v101 = v34->trackedEvents.list;
          v102 = 0;
          while ( 1 )
          {
            v103 = &v101[v102];
            anim = v101[v102].anim;
            if ( anim == nullptr )
              break;
            v105 = 0;
            loopCount = v103->loopCount;
            if ( loopCount > 0 )
            {
              animData = anim->animData;
              numFrames = 0;
              if ( animData != nullptr )
                numFrames = animData->numFrames;
              v109 = numFrames * loopCount;
              frameRate = 30;
              if ( animData != nullptr )
                frameRate = animData->frameRate;
              v105 = v109 * v33 / frameRate;
              __twllei(frameRate, 0);
              __twlgei(frameRate & ~(__ROL4__(v109 * v33, 1) - 1), 0xFFFFFFFF);
            }
            v111 = anim->animData;
            v112 = &v38[-v103->startTime - v105];
            v113 = 30;
            if ( v111 != nullptr )
              v113 = v111->frameRate;
            v114 = v113 * (_DWORD)v112;
            v116 = __ROL4__(v113 * (_DWORD)v112, 1);
            eventFrame = v103->eventFrame;
            __twllei(v33, 0);
            __twlgei(v33 & ~(v116 - 1), 0xFFFFFFFF);
            if ( eventFrame < v114 / v33 - 1 )
            {
              if ( v100 >= 0 && v100 < v142 )
              {
                v34->trackedEvents.num = v142 - 1;
                if ( v100 != v142 - 1 )
                {
                  v120 = (idAnimEventHandler::trackedEvent_t *)((char *)&v101[v142 - 1] - 4);
                  v121 = &v101[v100 - 1].eventFrame;
                  for ( i = 5; i != 0; --i )
                  {
                    v120 = (idAnimEventHandler::trackedEvent_t *)((char *)v120 + 4);
                    v121 += 2;
                    *(_DWORD *)v121 = v120->startTime;
                  }
                }
              }
              goto LABEL_148;
            }
            ++v100;
            ++v102;
            if ( v100 >= v34->trackedEvents.num )
              goto LABEL_148;
          }
          if ( v100 >= 0 && v100 < v142 )
          {
            v34->trackedEvents.num = v142 - 1;
            if ( v100 != v142 - 1 )
            {
              v117 = (idAnimEventHandler::trackedEvent_t *)((char *)&v101[v142 - 1] - 4);
              v118 = &v101[v100 - 1].eventFrame;
              for ( j = 5; j != 0; --j )
              {
                v117 = (idAnimEventHandler::trackedEvent_t *)((char *)v117 + 4);
                v118 += 2;
                *(_DWORD *)v118 = v117->startTime;
              }
            }
          }
        }
LABEL_148:
        ++v99;
      }
      while ( v99 < eventList->num );
    }
  }
  v123 = 0;
  if ( eventList->num > 0 )
  {
    v124 = 0;
    while ( v34->trackedEvents.num < v34->trackedEvents.size )
    {
      idList<idAnimEventHandler::trackedEvent_t,5>::Append(
        this: &v34->trackedEvents,
        obj: (const idAnimEventHandler::trackedEvent_t *)&eventList->list[v124]);
      if ( v39 > 2 )
      {
        v125 = (int)&v34->trackedEvents.list[v34->trackedEvents.num];
        v126 = idEventDef::GetEventCommand(eventnum: *(__int16 *)(v125 - 16));
        v127 = *(_DWORD *)(v125 - 8);
        p_name = &v126->name;
        if ( v127 != 0 )
          v129 = *(const char **)(v127 + 8);
        else
          v129 = (const char *)v36;
        v130 = *(const char **)(v35 + 4);
        if ( *v130 == 0
          || (v131 = idStr::Find(searchIn: v129, searchFor: v130, casesensitive: true, start: 0, end: -1),
              v132 = 0,
              v131 != -1) )
        {
          v132 = 1;
        }
        if ( v132 != 0 )
        {
          v133 = v129;
          if ( v129 == nullptr )
            v133 = v40;
          if ( p_name != nullptr )
            v134 = *p_name;
          else
            v134 = v37;
          idLib::Printf(
            fmt: "^1AnimEvent(%d)(tracking):^8 '^7%s^8', eventFrame ^7%d^8, loop ^7%d^8, anim = '^7%s^8'\n",
            v38,
            v134,
            *(__int16 *)(v125 - 4),
            *(__int16 *)(v125 - 2),
            v133);
        }
      }
      ++v123;
      v124 += 6;
      if ( v123 >= eventList->num )
        goto LABEL_169;
    }
    idLib::Warning(fmt: "Tracked anim events overflow for '%s'.", decl->name.str);
  }
LABEL_169:
  if ( v143.logIndex >= 0 )
  {
    pLog = v143.pLog;
    v136 = &v143.pLog->logEntries.list[v143.logIndex];
    v137 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v136->totalTicks;
    HIDWORD(totalTicks) = v136->parent;
    LODWORD(v139) = v137 - totalTicks;
    v136->totalTicks = v139;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
}


// ========================================================================
// $LN419
// EA  : 0x8283D0F8
// RVA : 0x0083D0F8
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _LN419()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 104));
}


// ========================================================================
// __unwind$221635
// EA  : 0x8283D120
// RVA : 0x0083D120
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _unwind_221635()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 352 + 112));
}


// ========================================================================
// ?BuildAnimEventList@idAnimEventHandler@@QAAXPBVidDeclMD6@@PBVidMD6Node@@HHHQBHH@Z
// EA  : 0x8283D150
// RVA : 0x0083D150
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __fastcall idAnimEventHandler::BuildAnimEventList(
        idAnimEventHandler *this,
        const idDeclMD6 *decl,
        const idMD6Node *tree,
        const char *curTime,
        const char *previousTime,
        int ticksPerSec,
        const int *onlyEvents,
        int onlyNumEvents)
{
  unsigned __int64 v13; // r6
  int v17; // [sp+8h] [-6C8h]
  int v18; // [sp+Ch] [-6C4h]
  int v19; // [sp+10h] [-6C0h]
  int v20; // [sp+14h] [-6BCh]
  int v21; // [sp+18h] [-6B8h]
  int v22; // [sp+1Ch] [-6B4h]
  int v23; // [sp+20h] [-6B0h]
  int v24; // [sp+24h] [-6ACh]
  int v25; // [sp+28h] [-6A8h]
  int v26; // [sp+2Ch] [-6A4h]
  int v27; // [sp+30h] [-6A0h]
  int v28; // [sp+34h] [-69Ch]
  int v29; // [sp+38h] [-698h]
  int v30; // [sp+3Ch] [-694h]
  int v31; // [sp+40h] [-690h]
  int v32; // [sp+44h] [-68Ch]
  int v33; // [sp+48h] [-688h]
  int v34; // [sp+4Ch] [-684h]
  int v35; // [sp+50h] [-680h]
  idPLogScope v36[2]; // [sp+60h] [-670h] BYREF
  idStaticList<idAnimEventHandler::eventInfo_t,64> v37; // [sp+70h] [-660h] BYREF

  LODWORD(v13) = "idAnimEventHandler::BuildAnimEventList";
  HIDWORD(v13) = 1;
  idPLogScope::idPLogScope(this: v36, pl: &pLog, gMask: v13, label: previousTime);
  idStaticList<idAnimEventHandler::eventInfo_t,64>::idStaticList<idAnimEventHandler::eventInfo_t,64>(this: &v37);
  idAnimEventHandler::WalkTree(this, frameList: &v37, node: tree, (int)curTime, previousTime, ticksPerSec);
  idAnimEventHandler::BuildEventList(
    this,
    eventList: (idList<idVehicleState *,5> *)&this->triggeredEvents,
    frameList: &v37,
    decl,
    curTime,
    (int)previousTime,
    ticksPerSec,
    onlyEvents,
    onlyNumEvents: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22,
    a15: v23,
    a16: v24,
    a17: v25,
    a18: v26,
    a19: v27,
    a20: v28,
    a21: v29,
    a22: v30,
    a23: v31,
    a24: v32,
    a25: v33,
    a26: v34,
    a27: v35,
    a28: onlyNumEvents);
  this->nextEventToFetch = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v37);
  idPLogScope::~idPLogScope(this: v36);
}


// ========================================================================
// __unwind$222387_0
// EA  : 0x8283D208
// RVA : 0x0083D208
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _unwind_222387_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1744 + 96));
}


// ========================================================================
// __unwind$222388
// EA  : 0x8283D230
// RVA : 0x0083D230
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void _unwind_222388()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1744 + 112));
}


// ========================================================================
// `dynamic initializer for 'anim_debugEvents''
// EA  : 0x83344198
// RVA : 0x01344198
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugEvents__()
{
  idCVar::idCVar(
    this: &anim_debugEvents,
    name: "anim_debugEvents",
    value: "0",
    flags: 2,
    description: "  1 = show triggered events\n"
    "  2 = also show all events and skipped events\n"
    "  3 = also show event tracking info\n"
    "  4 = verbose spew",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugEvents__);
}


// ========================================================================
// `dynamic initializer for 'anim_debugEvents_Name''
// EA  : 0x833441F0
// RVA : 0x013441F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6animeventhandler.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_debugEvents_Name__()
{
  idCVar::idCVar(
    this: &anim_debugEvents_Name,
    name: "anim_debugEvents_Name",
    value: &byte_8200D768,
    flags: 0,
    description: "optional animation to debug animevents for \n",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_debugEvents_Name__);
}

