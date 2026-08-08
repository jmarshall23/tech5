
// ========================================================================
// ?PurgeOverlays@idCommonLocal@@EAAXXZ
// EA  : 0x826512B0
// RVA : 0x006512B0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __fastcall idCommonLocal::PurgeOverlays(idCommonLocal *this)
{
  if ( !this->preventOverlayPurge )
    this->purgeOverlays = true;
}


// ========================================================================
// ?ShowJobListTimeRanges@idCommonLocal@@AAAX_K@Z
// EA  : 0x82651598
// RVA : 0x00651598
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCommonLocal::ShowJobListTimeRanges(idCommonLocal *this, int a2, unsigned __int64 displayStartTime)
{
  int v4; // r24
  int v5; // r21
  _BYTE v6[12]; // r11 OVERLAPPED
  unsigned __int64 UnitWastedTimeMicroSec; // r4
  int i; // r29
  int v9; // r27
  int v10; // r31
  int v11; // r28
  int j; // r30
  idParallelJobList *v13; // r19
  int v14; // r31
  int v15; // r31 OVERLAPPED
  double v16; // fp1
  __int128 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r8
  va *v20; // r3
  rangeId_t v21; // r31
  int v22; // [sp+8h] [-10C8h]
  int v23; // [sp+Ch] [-10C4h]
  int v24; // [sp+10h] [-10C0h]
  int v25; // [sp+14h] [-10BCh]
  int v26; // [sp+18h] [-10B8h]
  int v27; // [sp+1Ch] [-10B4h]
  va v28; // [sp+50h] [-1080h] BYREF

  if ( com_drawThreadSpeeds.valueInteger != 0 )
  {
    v4 = parallelJobManager->GetNumJobLists(this: parallelJobManager);
    if ( v4 != 0 )
    {
      v5 = parallelJobManager->GetNumProcessingUnits(this: parallelJobManager);
      for ( i = 0; i < v5; ++i )
      {
        if ( i > 30 )
          break;
        v9 = a2;
        v10 = a2;
        v11 = 0;
        for ( j = 0; j < v4; v11 += HIDWORD(UnitWastedTimeMicroSec) )
        {
          v13 = parallelJobManager->GetJobList(this: parallelJobManager, a2: j);
          v14 = (idParallelJobList::GetUnitProcessingTimeMicroSec(this: v13, unit: i) >> 32) + v10;
          v10 = (idParallelJobList::GetUnitWastedTimeMicroSec(this: v13, unit: i) >> 32) + v14;
          console->AddTimeRange(this: console, a2: (rangeId_t)(i + 15), a3: v13->color, a4: v9, a5: v10);
          v9 = v10;
          UnitWastedTimeMicroSec = idParallelJobList::GetUnitWastedTimeMicroSec(this: v13, unit: i);
          ++j;
        }
        *(_DWORD *)&v6[8] = v10 - a2;
        if ( v10 == a2 )
        {
          v15 = 0;
        }
        else
        {
          *(_DWORD *)&v6[4] = 100 * v11;
          *(_QWORD *)&v15 = *(_QWORD *)v6 / *(_QWORD *)&v6[4];
          __tdllei(*(unsigned __int64 *)&v6[4], 0);
        }
        v16 = _u64tod(a1: v11, a2: UnitWastedTimeMicroSec);
        LODWORD(v17) = v15;
        *(double *)((char *)&v17 + 4) = (float)((float)v16 * (float)0.001);
        v20 = va::va(
                this: &v28,
                fmt: (const char *)DWORD1(v17),
                a3: v17,
                a4: v19,
                a5: v18,
                a6: v22,
                a7: v23,
                a8: v24,
                a9: v25,
                a10: v26,
                a11: v27);
        console->SetTimeRangeLabel(this: console, a2: (rangeId_t)(i + 15), a3: (const char *)v20);
      }
      v21 = v5 + 15;
      if ( v5 + 15 <= 30 )
      {
        do
          console->SetTimeRangeLabel(this: console, a2: v21++, a3: &byte_8200D768);
        while ( v21 <= RANGE_JPU15 );
      }
    }
  }
}


// ========================================================================
// ?CalcSnapTimeBuffered@idCommonLocal@@AAAHAAH0@Z
// EA  : 0x82651780
// RVA : 0x00651780
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

int __fastcall idCommonLocal::CalcSnapTimeBuffered(idCommonLocal *this, int *totalBufferedTime, int *totalRecvTime)
{
  int readSnapshotIndex; // r11
  int time; // r10
  int i; // r8
  int v9; // r7
  int v10; // r4
  int v11; // r9
  int recvTime; // r9
  int v13; // r5
  int v14; // r11
  __int64 v15; // r8
  __int64 v16; // r6
  unsigned __int64 snapCurrentTime; // r11

  *totalBufferedTime = this->snapRate;
  *totalRecvTime = this->snapTimeDelta;
  readSnapshotIndex = this->readSnapshotIndex;
  time = this->oldss.time;
  for ( i = this->oldss.recvTime; readSnapshotIndex < this->writeSnapshotIndex; *totalRecvTime = v13 )
  {
    v9 = *totalBufferedTime - time;
    v10 = readSnapshotIndex % 16 + 489;
    v11 = readSnapshotIndex % 16;
    ++readSnapshotIndex;
    time = *((_DWORD *)&this->__vftable + 13 * v10);
    recvTime = this->receivedSnaps.ptr[v11].recvTime;
    *totalBufferedTime = v9 + time;
    v13 = *totalRecvTime - i + recvTime;
    i = recvTime;
  }
  v14 = *totalRecvTime;
  if ( *totalRecvTime < 1 )
    v14 = 1;
  *totalRecvTime = v14;
  LODWORD(v15) = this->game->GetGameMsPerRealSec(this: this->game);
  LODWORD(v16) = *totalRecvTime;
  *totalRecvTime = (int)(float)((float)((float)v15 * (float)v16) * (float)0.001);
  snapCurrentTime = this->snapCurrentTime;
  if ( SHIDWORD(snapCurrentTime) >= (int)snapCurrentTime )
    return *totalBufferedTime - snapCurrentTime;
  else
    return *totalBufferedTime - HIDWORD(snapCurrentTime);
}


// ========================================================================
// ?CalcPerfTimings@idCommonLocal@@AAAXXZ
// EA  : 0x826518C8
// RVA : 0x006518C8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __fastcall idCommonLocal::CalcPerfTimings(idCommonLocal *this)
{
  unsigned __int64 v1; // r29
  unsigned __int64 v2; // r3
  __int128 v3; // r4
  bool v4; // r4
  double v5; // fp1
  __int64 v6; // r9
  double v7; // fp7
  int valueInteger; // r11
  double v9; // fp26
  double v10; // fp27
  double v11; // fp29
  __int64 v12; // r7
  bool v13; // r4
  int v14; // r4
  double v15; // fp1
  __int64 v16; // r11
  bool v17; // r4
  __int64 v18; // r9
  bool v19; // r4
  __int64 v20; // r7
  bool v21; // r4
  __int64 v22; // r11
  bool v23; // r4
  double v24; // [sp+20h] [-F0h]

  if ( (_S19 & 1) == 0 )
  {
    _S19 |= 1u;
    LODWORD(v2) = Sys_Microseconds() >> 32;
    prevTime = v2;
  }
  *((_QWORD *)&v3 + 1) = Sys_Microseconds();
  LODWORD(v1) = DWORD2(v3) - prevTime;
  prevTime = *(_QWORD *)((char *)&v3 + 4);
  time_frame = v1;
  v5 = _u64tod(a1: v1, a2: v3);
  HIDWORD(v6) = &off_82040000;
  v7 = (float)((float)((float)1000000.0 / (float)((float)((float)((float)v5 - avgFrameTime) * (float)0.2) + avgFrameTime))
             + (float)0.5);
  avgFrameTime = (float)((float)((float)v5 - avgFrameTime) * (float)0.2) + avgFrameTime;
  time_FPS = (int)v7;
  if ( com_drawThreadSpeeds.valueInteger == 3 )
  {
    HIDWORD(v6) = 1000 * com_hitchThresholdMS.valueInteger;
    if ( (unsigned int)v1 > 1000 * com_hitchThresholdMS.valueInteger )
    {
      idCVar::SetInteger(this: &com_drawThreadSpeeds, newValue: 2, force: true);
      LODWORD(v1) = time_frame;
    }
  }
  valueInteger = com_speeds.valueInteger;
  if ( com_speeds.valueInteger == 1 )
  {
    v9 = (float)((float)__SPAIR64__(time_GPUFrameTime, time_spinning) * (float)0.001);
    v10 = (float)((float)__SPAIR64__(v1, time_gameFrame) * (float)0.001);
    v11 = (float)((float)__SPAIR64__(time_spinning, time_renderFrame) * (float)0.001);
    v24 = (float)((float)_u64tod(a1: v1, a2: time_gameFrame) * (float)0.001);
    idLib::Printf(
      fmt: (const char *)(HIDWORD(v9) - 30072),
      idLib::frameNumber,
      LODWORD(v24),
      HIDWORD(v10),
      LODWORD(v10),
      count_numGameFrames,
      v11);
    valueInteger = com_speeds.valueInteger;
  }
  if ( valueInteger != 0 || com_logMetrics.valueInteger == 1 )
  {
    LODWORD(v6) = count_numGameFrames;
    idGaugeMetric::Log(this: &countNumGameFrames, x: (float)v6, skipPush: v4);
    LODWORD(v12) = time_spinning;
    idGaugeMetric::Log(this: &timeSpinning, x: (float)v12, skipPush: v13);
    v15 = _u64tod(a1: (int)time_frame - time_spinning, a2: v14);
    idGaugeMetric::Log(this: &timeCPUFrameTime, x: (float)v15, skipPush: (bool)&localConsole.text.ptr[2048]);
    LODWORD(v16) = time_gameFrame;
    idGaugeMetric::Log(this: &timeGameFrame, x: (float)v16, skipPush: v17);
    LODWORD(v18) = time_renderThreadSync;
    idGaugeMetric::Log(this: &timeRenderThreadSync, x: (float)v18, skipPush: v19);
    LODWORD(v20) = time_renderFrame;
    idGaugeMetric::Log(this: &timeRenderFrame, x: (float)v20, skipPush: v21);
    idGaugeMetric::Log(
      this: &timeGPUFrameTime,
      x: (float)__SPAIR64__(&timeGPUFrameTime, time_GPUFrameTime),
      skipPush: time_GPUFrameTime);
    LODWORD(v22) = time_FPS;
    idGaugeMetric::Log(this: &framesPerSec, x: (float)v22, skipPush: v23);
  }
}


// ========================================================================
// __unwind$225525
// EA  : 0x82651C4C
// RVA : 0x00651C4C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_225525()
{
  _S19 &= ~1u;
}


// ========================================================================
// ?RunNormalFrame@idCommonLocal@@AAAXAAUgameReturn_t@@@Z
// EA  : 0x82651E70
// RVA : 0x00651E70
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCommonLocal::RunNormalFrame(idCommonLocal *this, gameReturn_t *gameReturn)
{
  idGame *v4; // r3
  double valueFloat; // fp31
  __int128 v6; // r5
  int v7; // r22
  int v8; // r3
  int v9; // r9
  unsigned __int64 v10; // r4
  int v11; // r29
  int v12; // r3
  int v13; // r3
  idGame *v14; // r3
  unsigned __int64 v15; // r4
  int v16; // r11
  bool (__fastcall *DemoRecording)(struct idCommonLocal *); // r7
  BOOL v18; // r9
  unsigned __int8 v19; // r11
  int v20; // r30
  idLobbyBase *v21; // r3
  idLobbyBase *v22; // r3
  unsigned __int64 v23; // r30
  idLobbyBase *v24; // r3
  idLobbyBase *v25; // r3
  unsigned __int64 v26; // r11 OVERLAPPED
  unsigned int v27; // r9 OVERLAPPED
  int serverTime; // r9
  idLobbyBase *v29; // r3
  idLobbyBase *v30; // r3
  int PendingSnapDelta; // r9
  int sequence; // r29
  int v33; // r3
  int baseSequence; // r11
  idSnapShot v35; // [sp+60h] [-1FF0h] BYREF
  unsigned __int8 v36[4016]; // [sp+A0h] [-1FB0h] BYREF

  v4 = this->Game(this);
  valueFloat = com_timescale.valueFloat;
  *(_QWORD *)((char *)&v6 + 4) = ((__int64 (__fastcall *)(idGame *, _DWORD))v4->GetGameMsPerFrame)(a1: v4, a2: 0);
  LODWORD(v6) = DWORD1(v6);
  v7 = (int)(float)((float)(__int64)v6 / (float)valueFloat) + 1;
  if ( (_S18 & 1) == 0 )
  {
    _S18 |= 1u;
    lastTime = Sys_Milliseconds();
  }
  v8 = Sys_Milliseconds();
  v9 = v8 - lastTime;
  if ( v8 - lastTime >= 0 )
  {
    if ( v9 > 50 )
      v9 = 50;
  }
  else
  {
    v9 = 0;
  }
  lastTime = v8;
  count_numGameFrames = 0;
  time_gameFrame = 0;
  time_maxGameFrame = 0;
  gameTimeResidual = com_fixedTic.valueInteger != 0 ? 0 : gameTimeResidual + v9;
  do
  {
    v10 = Sys_Microseconds();
    v11 = HIDWORD(v10);
    v12 = ((int (__fastcall *)(idCommonLocal *, _DWORD))this->Game)(a1: this, a2: v10);
    v13 = (*(int (__fastcall **)(int))(*(_DWORD *)v12 + 16))(a1: v12);
    (*(void (__fastcall **)(int))(*(_DWORD *)v13 + 16))(a1: v13);
    v14 = this->Game(this);
    v14->RunFrame(this: v14, a2: &this->userCmdMgr, a3: gameReturn, a4: true);
    if ( com_sleepGame.valueInteger > 0 )
      mgthread_sleep(ms: com_sleepGame.valueInteger);
    v15 = Sys_Microseconds();
    time_gameFrame += HIDWORD(v15) - v11;
    if ( HIDWORD(v15) - v11 > time_maxGameFrame )
      time_maxGameFrame = HIDWORD(v15) - v11;
    v16 = gameTimeResidual - v7;
    ++count_numGameFrames;
    gameTimeResidual = v16;
  }
  while ( v16 >= v7 );
  DemoRecording = this->DemoRecording;
  gameTimeResidual = (((unsigned int)v16 >> 31) - 1) & v16;
  if ( ((unsigned __int8 (__fastcall *)(idCommonLocal *, _DWORD))DemoRecording)(a1: this, a2: v15) != 0
    || (v18 = this->TimeTrialRecording(this), v19 = 0, v18) )
  {
    v19 = 1;
  }
  v20 = v19;
  if ( v19 != 0
    || net_ForceWriteSnap.valueInteger != 0 && session->GetState(this: session) == INGAME
    || (v21 = session->GetActingGameStateLobbyBase(this: session), v21->IsHost(this: v21) != 0)
    && session->GetState(this: session) == INGAME
    && (v22 = session->GetActingGameStateLobbyBase(this: session), v22->HasActivePeers(this: v22)) )
  {
    HIDWORD(v23) = 0;
    if ( v20 != 0 )
    {
      HIDWORD(v23) = this->ssFileState[1].ss;
    }
    else
    {
      v24 = session->GetActingGameStateLobbyBase(this: session);
      if ( v24->IsHost(this: v24) != 0
        && (v25 = session->GetActingGameStateLobbyBase(this: session), v25->HasActivePeers(this: v25))
        || net_ForceWriteSnap.valueInteger != 0 )
      {
        HIDWORD(v23) = &this->oldss;
      }
    }
    LODWORD(v23) = 1000 * gameReturn->serverTime;
    if ( LODWORD(this->snapTimeWrite) == 0 )
      this->snapTimeWrite = v23;
    LODWORD(v26) = v23 - LODWORD(this->snapTimeWrite);
    if ( net_snapRate.valueInteger > 0 )
      this->snapRate = __PAIR64__(&net_snapRate, net_snapRate.valueInteger);
    *(unsigned __int64 *)((char *)&v26 + 4) = 2 * this->snapRate;
    if ( (unsigned int)v26 > HIDWORD(v26) )
      LODWORD(v26) = HIDWORD(v26);
    if ( (unsigned int)v26 >= v27 )
    {
      if ( net_debug_snapShotTime.valueInteger != 0 )
      {
        HIDWORD(v26) = 1000;
        serverTime = gameReturn->serverTime;
        idLib::Printf(
          fmt: "^5Creating snapshot. Delta real time: %d  Delta ss time: %d. SnapTime: %d\n",
          (unsigned int)(v26 / *(unsigned __int64 *)((char *)&v26 + 4)),
          serverTime - *(_DWORD *)(HIDWORD(v23) + 40),
          serverTime);
      }
      this->snapTimeWrite = v23;
      idSnapShot::idSnapShot(this: &v35);
      this->PrepareSnapshot(this, a2: &v35, a3: gameReturn, a4: (idSnapShot *)HIDWORD(v23));
      v29 = session->GetActingGameStateLobbyBase(this: session);
      if ( v29->IsHost(this: v29) != 0 )
      {
        if ( com_sendSnapshots.valueInteger != 0 )
          session->SendSnapshot(this: session, a2: &v35);
        if ( net_ForceWriteSnap.valueInteger != 0 )
        {
          v30 = session->GetActingGameStateLobbyBase(this: session);
          if ( !v30->HasActivePeers(this: v30) )
          {
            idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
            if ( (_S18 & 2) == 0 )
            {
              _S18 |= 2u;
              idSnapshotProcessor::idSnapshotProcessor(this: &snapProc);
              atexit(func: (void (__fastcall *)())_idCommonLocal::RunNormalFrame_::_51_::_dynamic_atexit_destructor_for__snapProc__);
            }
            idMem::PopHeap(this: &mem);
            idSnapshotProcessor::TrySetPendingSnapshot(this: &snapProc, ss: &v35);
            if ( snapProc.hasPendingSnap )
              idSnapshotProcessor::SubmitPendingSnap(
                this: &snapProc,
                visIndex: 1,
                objMemory: objMemory,
                objMemorySize: 0x20000,
                lzwData: &lzwData,
                snapshotJobList: nullptr);
            PendingSnapDelta = idSnapshotProcessor::GetPendingSnapDelta(
                                 this: &snapProc,
                                 outBuffer: v36,
                                 maxLength: 7872);
            if ( snapProc.deltas.items.num != 0 )
              sequence = snapProc.deltas.items.list[snapProc.deltas.items.num - 1].sequence;
            else
              sequence = -1;
            idSnapshotMetrics::LogSnapshotDelta(
              this: &snapshotMetrics,
              ss: &v35,
              oldss: &this->oldss,
              seq: sequence,
              baseSeq: snapProc.baseSequence,
              peer: 0,
              size: PendingSnapDelta,
              fullSnap: (_cntlzw(snapProc.hasPendingSnap) & 0x20) != 0);
            v33 = Sys_Milliseconds();
            if ( v33 - lastAckMS >= net_ForceWriteSnapAckMS.valueInteger && net_ForceWriteSnapAckMS.valueInteger >= 0 )
            {
              lastAckMS = v33;
              baseSequence = sequence - net_ForceWriteSnapAckSEQ.valueInteger;
              if ( sequence - net_ForceWriteSnapAckSEQ.valueInteger <= snapProc.baseSequence )
                baseSequence = snapProc.baseSequence;
              idSnapshotProcessor::ApplySnapshotDelta(this: &snapProc, visIndex: 1, snapshotNumber: baseSequence);
            }
          }
        }
      }
      idSnapShot::operator=(this: &this->oldss, other: &v35);
      idSnapShot::~idSnapShot(this: &v35);
    }
  }
}


// ========================================================================
// __unwind$226309
// EA  : 0x826524DC
// RVA : 0x006524DC
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_226309()
{
  _S18 &= ~1u;
}


// ========================================================================
// __unwind$226310
// EA  : 0x826524FC
// RVA : 0x006524FC
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_226310()
{
  int v0; // r12

  idSnapShot::~idSnapShot(this: (idSnapShot *)(v0 - 8272 + 96));
}


// ========================================================================
// __unwind$226311
// EA  : 0x82652524
// RVA : 0x00652524
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_226311()
{
  _S18 &= ~2u;
}


// ========================================================================
// ?RunNetworkSnapshotFrame@idCommonLocal@@AAAXAAUgameReturn_t@@@Z
// EA  : 0x82652DA8
// RVA : 0x00652DA8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCommonLocal::RunNetworkSnapshotFrame(idCommonLocal *this, gameReturn_t *gameReturn)
{
  idGame *v4; // r29
  idGame *v5; // r3
  idRenderWorld *v6; // r27
  idGame *v7; // r3
  idRenderWorld_vtbl *v8; // r29
  int (__fastcall *GetGameMsPerFrame)(idGame *, const gameTimeType_t); // ctr
  int v10; // r3
  idGame *v11; // r3
  double valueFloat; // fp31
  __int128 v13; // r5
  int v14; // r3
  int v15; // r9
  unsigned __int64 snapCurrentTime; // r11 OVERLAPPED
  idGame *v17; // r3
  int v18; // r3
  int v19; // r4
  unsigned __int64 snapRate; // r9
  int valueInteger; // r10
  int v22; // r11
  unsigned __int64 v23; // r11
  unsigned __int64 v24; // r11
  unsigned __int64 v25; // r29 OVERLAPPED
  idCVar *v26; // r27 OVERLAPPED
  double v27; // fp31
  int v28; // r4
  double v29; // fp31
  bool v30; // r7
  int *v31; // r28
  int *v32; // r29
  double v33; // fp29
  __int64 v34; // r10
  int v35; // r4
  __int128 v36; // r8
  double v37; // fp1
  __int64 v38; // r11
  double snapTimeBuffered; // fp0
  idCVar *v40; // r11
  idGame *v41; // r3
  __int64 v42; // r7
  double v43; // fp31
  __int128 v44; // r9
  double effectiveSnapRate; // fp0
  float *p_snapCurrentResidual; // r29
  double v47; // fp30
  long double v48; // fp2
  long double v49; // fp2
  unsigned __int64 v50; // r9
  int v51; // r11
  int v52; // [sp+50h] [-140h]
  float v53; // [sp+58h] [-138h] BYREF
  int v54; // [sp+5Ch] [-134h]
  gameReturn_t *p_snapCurrent; // [sp+60h] [-130h]
  gameReturn_t *p_snapPrevious; // [sp+64h] [-12Ch]
  int *p_totalRecvTime; // [sp+68h] [-128h]
  int *p_totalBufferedTime; // [sp+6Ch] [-124h]
  idCVar *v59; // [sp+70h] [-120h]
  int v60; // [sp+74h] [-11Ch]
  idCVar *v61; // [sp+78h] [-118h]
  idCVar *v62; // [sp+7Ch] [-114h]
  idCVar *v63; // [sp+80h] [-110h]
  int v64; // [sp+88h] [-108h]
  int v65; // [sp+8Ch] [-104h]
  __int64 v66; // [sp+90h] [-100h]
  __int64 v67; // [sp+98h] [-F8h]
  __int64 v68; // [sp+A0h] [-F0h]
  __int64 v69; // [sp+A8h] [-E8h]
  __int64 v70; // [sp+B0h] [-E0h]
  __int64 v71; // [sp+B8h] [-D8h]
  __int64 v72; // [sp+C0h] [-D0h]

  time_gameFrame = Sys_Microseconds() >> 32;
  time_maxGameFrame = 0;
  count_numGameFrames = 0;
  v4 = this->Game(this);
  v5 = this->Game(this);
  v6 = v5->GetRenderWorld(this: v5);
  v7 = v4;
  GetGameMsPerFrame = v4->GetGameMsPerFrame;
  v8 = v6->__vftable;
  v10 = GetGameMsPerFrame(this: v7, a2: GAMETIME_NORMAL);
  v8->DebugClear(this: v6, a2: v10);
  if ( this->snapPrevious.serverTime < 0 )
  {
    gameReturn_t::operator=(this: gameReturn, __that: &this->snapCurrent);
    goto LABEL_55;
  }
  v11 = this->Game(this);
  valueFloat = com_timescale.valueFloat;
  *(_QWORD *)((char *)&v13 + 4) = ((__int64 (__fastcall *)(idGame *, _DWORD))v11->GetGameMsPerFrame)(a1: v11, a2: 0);
  LODWORD(v13) = DWORD1(v13);
  v65 = (int)(float)((float)(__int64)v13 / (float)valueFloat);
  v64 = v65 + 1;
  if ( (_S17 & 1) == 0 )
  {
    _S17 |= 1u;
    lastTime_0 = Sys_Milliseconds();
  }
  v14 = Sys_Milliseconds();
  v15 = v14 - lastTime_0;
  if ( v14 - lastTime_0 >= 1 )
  {
    if ( v15 <= 33 )
      v52 = v14 - lastTime_0;
    else
      v52 = 33;
  }
  else
  {
    v52 = 1;
  }
  if ( v15 >= 0 )
  {
    if ( v15 > 50 )
      v15 = 50;
  }
  else
  {
    v15 = 0;
  }
  lastTime_0 = v14;
  p_totalRecvTime = &this->totalRecvTime;
  p_snapCurrent = &this->snapCurrent;
  p_snapPrevious = &this->snapPrevious;
  p_totalBufferedTime = &this->totalBufferedTime;
  clientTimeResidual = com_fixedTic.valueInteger != 0 ? 0 : clientTimeResidual + v15;
  v59 = &net_optimalDynamic;
  v60 = -2090926080;
  v63 = &net_effectiveSnapRateDebug;
  v62 = &net_interpolationCatchupRate;
  v61 = &net_interpolationFallbackRate;
  do
  {
    while ( 1 )
    {
      snapCurrentTime = this->snapCurrentTime;
      *(unsigned __int64 *)((char *)&snapCurrentTime + 4) = this->snapRate;
      if ( (unsigned int)snapCurrentTime < HIDWORD(snapCurrentTime) && com_forceLatestSnap.valueInteger == 0 )
        break;
      if ( this->readSnapshotIndex >= this->writeSnapshotIndex )
        break;
      LODWORD(snapCurrentTime) = snapCurrentTime - HIDWORD(snapCurrentTime);
      this->snapCurrentTime = snapCurrentTime;
      idCommonLocal::ProcessNextSnapshot(this);
    }
    v17 = this->Game(this);
    v18 = (int)v17->GetRenderWorld(this: v17);
    (*(void (__fastcall **)(int))(*(_DWORD *)v18 + 16))(a1: v18);
    snapRate = this->snapRate;
    valueInteger = net_maxExtrapolationInMS.valueInteger;
    v22 = this->snapRate;
    if ( v22 < net_maxExtrapolationInMS.valueInteger )
      valueInteger = this->snapRate;
    HIDWORD(v23) = v22 + valueInteger;
    LODWORD(v23) = this->snapCurrentTime;
    if ( (v23 & 0x80000000) == 0LL )
    {
      if ( (int)v23 > SHIDWORD(v23) )
        LODWORD(v23) = HIDWORD(v23);
    }
    else
    {
      LODWORD(v23) = 0;
    }
    this->snapCurrentTime = v23;
    if ( (_DWORD)snapRate == 0 )
    {
      idLib::Warning(fmt: "snapRate <= 0. Resetting to 100");
      LODWORD(v24) = 100;
      this->snapRate = v24;
    }
    v25 = this->snapCurrentTime;
    *(unsigned __int64 *)((char *)&v25 + 4) = this->snapRate;
    v27 = (float)_u64tod(a1: this->snapCurrentTime, a2: v19);
    v29 = (float)((float)v27 / (float)_u64tod(a1: HIDWORD(v25), a2: v28));
    v53 = v29;
    if ( (unsigned __int8)IsValid<float>(f: &v53) == 0 )
    {
      idLib::Warning(fmt: "Interpolation Fraction invalid: snapCurrentTime %d / snapRate %d", (_DWORD)v25, HIDWORD(v25));
      v29 = 0.0;
    }
    idCommonLocal::InterpolateSnapshot(
      this,
      ret: gameReturn,
      prev: p_snapPrevious,
      next: p_snapCurrent,
      fraction: v29,
      predict: v30);
    v31 = p_totalRecvTime;
    v32 = p_totalBufferedTime;
    v33 = net_interpolationBaseRate.valueFloat;
    LODWORD(v34) = idCommonLocal::CalcSnapTimeBuffered(
                     this,
                     totalBufferedTime: p_totalBufferedTime,
                     totalRecvTime: p_totalRecvTime);
    HIDWORD(v34) = *v31;
    LODWORD(v36) = *v32;
    DWORD2(v36) = *v31;
    v66 = v34;
    v67 = v36;
    v68 = *(_QWORD *)((char *)&v36 + 4);
    this->snapTimeBuffered = (float)v34;
    this->effectiveSnapRate = (float)(__int64)v36 / (float)*(__int64 *)((char *)&v36 + 4);
    if ( v26->valueFloat > 0.0 )
      this->optimalPCTBuffer = ((double (__fastcall *)(idSession *, const char *))session->GetTitleStorageFloat_2)(
                                 a1: session,
                                 a2: "net_minBufferedSnapPCT_Static");
    if ( v59->valueInteger != 0 )
    {
      v37 = _u64tod(a1: this->snapRate, a2: v35);
      v54 = (int)(float)(this->optimalPCTBuffer * (float)v37);
      LODWORD(v38) = v54;
      if ( v54 >= 0 )
      {
        HIDWORD(v38) = net_maxBufferedSnapMS.valueInteger;
        if ( v54 > net_maxBufferedSnapMS.valueInteger )
          LODWORD(v38) = net_maxBufferedSnapMS.valueInteger;
      }
      else
      {
        LODWORD(v38) = 0;
      }
      v69 = v38;
      this->optimalTimeBuffered = (float)v38;
      this->optimalTimeBufferedWindow = (float)v37 * net_minBufferedSnapWinPCT_Static.valueFloat;
    }
    else
    {
      this->optimalTimeBuffered = net_optimalSnapTime.valueFloat;
      this->optimalTimeBufferedWindow = net_optimalSnapWindow.valueFloat;
    }
    snapTimeBuffered = this->snapTimeBuffered;
    if ( snapTimeBuffered > this->optimalTimeBuffered )
    {
      if ( snapTimeBuffered <= (float)(this->optimalTimeBuffered + this->optimalTimeBufferedWindow) )
        goto LABEL_44;
      v40 = v62;
    }
    else
    {
      if ( snapTimeBuffered <= *(float *)(v60 - 23160) )
      {
        v33 = 0.0;
        goto LABEL_44;
      }
      v40 = v61;
    }
    v33 = v40->valueFloat;
LABEL_44:
    v41 = this->Game(this);
    LODWORD(v42) = v41->GetGameMsPerFrame(this: v41, a2: GAMETIME_NORMAL);
    v70 = v42;
    v43 = (float)((float)v42 * (float)v33);
    if ( net_effectiveSnapRateEnable.valueInteger != 0 )
    {
      LODWORD(v44) = this->game->GetGameMsPerRealSec(this: this->game);
      effectiveSnapRate = this->effectiveSnapRate;
      v72 = v44;
      DWORD2(v44) = v52;
      p_snapCurrentResidual = &this->snapCurrentResidual;
      v47 = (float)((float)((float)v72 * (float)*(__int64 *)((char *)&v44 + 4)) * (float)0.001);
      v43 = (float)((float)((float)((float)effectiveSnapRate
                                  * (float)((float)((float)v72 * (float)*(__int64 *)((char *)&v44 + 4)) * (float)0.001))
                          * (float)v33)
                  + this->snapCurrentResidual);
      v53 = (float)((float)((float)effectiveSnapRate
                          * (float)((float)((float)v72 * (float)*(__int64 *)((char *)&v44 + 4)) * (float)0.001))
                  * (float)v33)
          + this->snapCurrentResidual;
      v71 = *(_QWORD *)((char *)&v44 + 4);
      if ( (unsigned __int8)IsValid<float>(f: &v53) == 0 )
        v43 = 0.0;
      *(double *)&v48 = v43;
      v49 = floor(x: v48);
      *p_snapCurrentResidual = (float)v43 - (float)*(double *)&v49;
      if ( (unsigned __int8)IsValid<float>(f: &this->snapCurrentResidual) == 0 )
        *p_snapCurrentResidual = 0.0;
      if ( v63->valueInteger != 0 )
        idLib::Printf(
          fmt: "%d/%.2f snapRateScale: %.2f effectiveSR: %.2f d.interp: %.2f snapTimeBuffered: %.2f res: %.2f\n",
          HIDWORD(v47),
          v47,
          v33,
          this->effectiveSnapRate,
          v43,
          this->snapTimeBuffered,
          *p_snapCurrentResidual);
    }
    v54 = (int)v43;
    v50 = this->snapCurrentTime;
    HIDWORD(v50) = v64;
    clientTimeResidual -= v64;
    v51 = clientTimeResidual;
    LODWORD(v50) = (int)v43 + v50;
    this->snapCurrentTime = v50;
  }
  while ( v51 >= SHIDWORD(v50) );
  if ( v51 < 0 )
    clientTimeResidual = 0;
LABEL_55:
  time_gameFrame = (Sys_Microseconds() >> 32) - time_gameFrame;
}


// ========================================================================
// __unwind$227079
// EA  : 0x826534C8
// RVA : 0x006534C8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227079()
{
  _S17 &= ~1u;
}


// ========================================================================
// ?PrepareSnapshot@idCommonLocal@@UAAXAAVidSnapShot@@AAUgameReturn_t@@PAV2@@Z
// EA  : 0x82653830
// RVA : 0x00653830
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __fastcall idCommonLocal::PrepareSnapshot(
        idCommonLocal *this,
        idSnapShot *newss,
        gameReturn_t *gameReturn,
        idSnapShot *compareSnap)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  __int64 v9; // r30
  idArray<gameReturnPlayer_t,6> *p_players; // r25
  int i; // r28
  idConsole_vtbl *v12; // r26
  int v13; // r27
  int v14; // r3
  idGame *v15; // r3
  idGame *v16; // r3
  int v17; // r3
  idGame *v18; // r3
  int v19; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v21; // r30
  int v22; // r3
  __int64 totalTicks; // r11
  __int64 v24; // r9
  _BYTE *v25; // [sp+50h] [-8D0h] BYREF
  const char *v26; // [sp+54h] [-8CCh]
  int v27; // [sp+58h] [-8C8h]
  int v28; // [sp+5Ch] [-8C4h]
  int v29; // [sp+60h] [-8C0h]
  int v30; // [sp+64h] [-8BCh]
  int v31; // [sp+68h] [-8B8h]
  char v32; // [sp+6Ch] [-8B4h]
  char v33; // [sp+6Dh] [-8B3h]
  __int64 v34; // [sp+70h] [-8B0h]
  idPLogScope v35; // [sp+78h] [-8A8h] BYREF
  idSerializer v36; // [sp+80h] [-8A0h] BYREF
  _BYTE v37[2064]; // [sp+90h] [-890h] BYREF

  HIDWORD(v9) = newss;
  RD_EventBegin(name: "idCommonLocal_PrepareSnapshot");
  LODWORD(v7) = "idCommonLocal_PrepareSnapshot";
  HIDWORD(v7) = 32;
  idPLogScope::idPLogScope(this: &v35, pl: &::pLog, gMask: v7, label: v8);
  *(_DWORD *)(HIDWORD(v9) + 40) = gameReturn->serverTime;
  console->ClearSnapshots(this: console);
  LODWORD(v9) = 0;
  p_players = &gameReturn->players;
  for ( i = 0; i < 6; ++i )
  {
    if ( p_players->ptr[0].valid )
    {
      v27 = 2048;
      v28 = 0;
      v25 = v37;
      v26 = v37;
      v29 = 0;
      v30 = 0;
      v31 = 0;
      v32 = 0;
      v33 = 0;
      v34 = v9;
      v36.writing = true;
      v36.msg = (idBitMsg *)&v25;
      idCommonLocal::SerializePlayer(this, ser: &v36, player: p_players->ptr);
      idSnapShot::S_AddObject(
        this: (idSnapShot *)HIDWORD(v9),
        objectNum: i,
        visMask: p_players->ptr[0].visMask,
        data: v26,
        _size: (v29 != 0) + v28,
        tag: nullptr);
      if ( com_drawSnapshots.valueInteger == 3 )
      {
        v12 = console->__vftable;
        v13 = (v29 != 0) + v28;
        v14 = idSnapShot::CompareObject(
                this: (idSnapShot *)HIDWORD(v9),
                oldss: compareSnap,
                objectNum: i,
                start: 0,
                end: 0,
                oldStart: 0);
        v12->AddSnapObject(this: console, a2: "players", a3: v13, a4: v14, a5: 0.0);
      }
    }
    p_players = (idArray<gameReturnPlayer_t,6> *)((char *)p_players + 1952);
  }
  v15 = this->Game(this);
  v15->WriteToSnapshot(this: v15, a2: (idSnapShot *)HIDWORD(v9), a3: compareSnap);
  v16 = this->Game(this);
  v17 = (int)v16->GetRenderWorld(this: v16);
  (*(void (__fastcall **)(int, _DWORD, idSnapShot *))(*(_DWORD *)v17 + 160))(a1: v17, a2: HIDWORD(v9), a3: compareSnap);
  v18 = this->Game(this);
  v19 = (int)v18->GetSoundWorld(this: v18);
  (*(void (__fastcall **)(int, _DWORD, idSnapShot *))(*(_DWORD *)v19 + 92))(a1: v19, a2: HIDWORD(v9), a3: compareSnap);
  if ( v35.logIndex >= 0 )
  {
    pLog = v35.pLog;
    v21 = &v35.pLog->logEntries.list[v35.logIndex];
    v22 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v21->totalTicks;
    HIDWORD(totalTicks) = v21->parent;
    LODWORD(v24) = v22 - totalTicks;
    v21->totalTicks = v24;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$227523
// EA  : 0x82653AA8
// RVA : 0x00653AA8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227523()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2336 + 2192));
}


// ========================================================================
// __unwind$227524
// EA  : 0x82653AD0
// RVA : 0x00653AD0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227524()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2336 + 120));
}


// ========================================================================
// ?Frame@idCommonLocal@@UAAXXZ
// EA  : 0x82653B00
// RVA : 0x00653B00
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCommonLocal::Frame(idCommonLocal *this)
{
  __int64 v1; // r18
  idCommonLocal *v2; // r27
  unsigned __int64 v3; // r6
  const char *v4; // r7
  const idGame *v5; // r3
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r4
  int v9; // r3
  double valueFloat; // fp30
  __int64 v11; // r11
  __int64 v12; // r29
  unsigned __int64 v13; // r3
  unsigned __int64 v14; // r4
  unsigned __int64 v15; // r11
  idPLog::logEntry_t *v16; // r30
  __int64 v17; // r3
  int v18; // r3
  unsigned __int64 v19; // r6
  idMouse *v20; // r3
  idMouse *v21; // r3
  int v22; // r3
  int v23; // r17
  int v24; // r25
  int v25; // r3
  int v26; // r3
  int v27; // r3
  int v28; // r3
  int v29; // r3
  idPLog::logEntry_t *v30; // r30
  __int64 v31; // r3
  int v32; // r3
  idGameTimeManager *v33; // r3
  idLobbyBase *v34; // r3
  idLobbyBase *v35; // r3
  int v36; // r26
  int i; // r30
  int v38; // r30
  idPLog::logEntry_t *v39; // r30
  __int64 v40; // r3
  int v41; // r3
  idRenderModelGui *v42; // r3
  int v43; // r30
  idGame *v44; // r3
  idPLog::logEntry_t *v45; // r30
  __int64 v46; // r3
  int v47; // r27
  idCommonLocal *v48; // r22
  int v49; // r3
  int v50; // r3
  int v51; // r3
  idSoundWorld *v52; // r29
  int v53; // r3
  int v54; // r3
  int v55; // r28
  int k; // r30
  int v57; // r3
  int v58; // r3
  int v59; // r3
  idSoundWorld *v60; // r30
  int v61; // r4
  int v62; // r28
  idPLog::logEntry_t *v63; // r30
  int v64; // r3
  __int64 totalTicks; // r11
  __int64 v66; // r9
  idPLog::logEntry_t *v67; // r30
  int v68; // r3
  __int64 v69; // r11
  __int64 v70; // r9
  int m; // r11
  idPLog::logEntry_t *v72; // r30
  int v73; // r3
  __int64 v74; // r11
  __int64 v75; // r9
  idPLog::logEntry_t *v76; // r30
  __int64 v77; // r3
  int v78; // r4
  idSession *v79; // r3
  idPLog::logEntry_t *v80; // r30
  __int64 v81; // r3
  int v82; // r30
  __int128 v83; // r11
  idPLog::logEntry_t *v84; // r30
  __int64 v85; // r3
  idPlayerProfile *v86; // r28
  char v87; // r29
  idSession::sessionState_t v88; // r3
  idSession_vtbl *v89; // r11
  int v90; // r3
  int v91; // r30
  idGameSpawnInfo *v92; // r3
  idGameSpawnInfo *v93; // r27
  idLobbyBase *v94; // r3
  char v95; // r11
  char *data; // r3
  idLobbyBase *v97; // r3
  int v98; // r3
  idDebugMenu **v99; // r27
  sysEventType_t evType; // r11
  idPLog::logEntry_t *v101; // r30
  __int64 v102; // r3
  int v103; // r30
  __int64 v105; // r6
  idPLog::logEntry_t *v106; // r30
  int v107; // r3
  __int64 v108; // r11
  __int64 v109; // r9
  idPLog::logEntry_t *v110; // r30
  int v111; // r3
  __int64 v112; // r11
  __int64 v113; // r9
  idPLog::logEntry_t *v114; // r30
  int v115; // r3
  __int64 v116; // r11
  __int64 v117; // r9
  idPLog::logEntry_t *v118; // r30
  int v119; // r3
  __int64 v120; // r11
  __int64 v121; // r9
  idPLog::logEntry_t *v122; // r30
  int v123; // r3
  __int64 v124; // r11
  __int64 v125; // r9
  idPLog::logEntry_t *v126; // r30
  int v127; // r3
  __int64 v128; // r11
  __int64 v129; // r9
  idPLog::logEntry_t *v130; // r30
  int v131; // r3
  __int64 v132; // r11
  __int64 v133; // r9
  idSignInManagerBase *signInManager; // r30
  int v135; // r30
  idLocalUser *LocalUserByInputDevice; // r11
  int v137; // r3
  int v138; // r3
  int v139; // r3
  int v140; // r30
  int v141; // r3
  const char *ContentPackagePath; // r3
  int vibrationLow; // r30
  int vibrationHigh; // r29
  int v145; // r3
  int v146; // r3
  int v147; // r3
  int v148; // r3
  int v149; // r3
  int v150; // r3
  int v151; // r3
  int v152; // r3
  int v153; // r3
  int v154; // r3
  idRenderModel **p_hudModel; // r9
  __int16 *v156; // r10
  int j; // ctr
  int v158; // r3
  int v159; // r27
  int v160; // r3
  bool v161; // r3
  char v162; // r11
  BOOL v163; // r7
  int v164; // r3
  idGameTimeManager *v165; // r3
  bool v166; // r3
  idGame *(__fastcall *Game)(struct idCommonLocal *); // ctr
  int v168; // r29
  int v169; // r30
  int v170; // r29
  int v171; // r3
  int v172; // r3
  idUserCmdMgr *p_userCmdMgr; // r30
  int v174; // r29
  int v175; // r28
  int v176; // r11
  int v177; // r11
  sysEvent_t v178; // [sp+90h] [-5A80h] BYREF
  idPLogScope v179; // [sp+A8h] [-5A68h] BYREF
  idPLogScope v180; // [sp+B0h] [-5A60h] BYREF
  idCVar *v181; // [sp+B8h] [-5A58h]
  idDebugMenu **v182; // [sp+BCh] [-5A54h]
  idPLogScope v183; // [sp+C0h] [-5A50h] BYREF
  idPLogScope v184; // [sp+C8h] [-5A48h] BYREF
  idPLogScope v185; // [sp+D0h] [-5A40h] BYREF
  idPLogScope v186; // [sp+D8h] [-5A38h] BYREF
  idPLogScope v187; // [sp+E0h] [-5A30h] BYREF
  idPLogScope v188; // [sp+E8h] [-5A28h] BYREF
  idPLogScope v189; // [sp+F0h] [-5A20h] BYREF
  idCVar *v190; // [sp+F8h] [-5A18h]
  idPLogScope v191; // [sp+100h] [-5A10h] BYREF
  BOOL v192; // [sp+108h] [-5A08h]
  __int64 v193; // [sp+110h] [-5A00h] BYREF
  int v194; // [sp+118h] [-59F8h]
  int v195; // [sp+11Ch] [-59F4h]
  idGameLock v196[2]; // [sp+120h] [-59F0h] BYREF
  __int64 v197; // [sp+128h] [-59E8h] BYREF
  float v198[8]; // [sp+130h] [-59E0h] BYREF
  _BYTE v199[16]; // [sp+150h] [-59C0h] BYREF
  rangeId_t v200; // [sp+160h] [-59B0h]
  _DWORD v201[16]; // [sp+170h] [-59A0h] BYREF
  int v202; // [sp+1B0h] [-5960h] BYREF
  idStrStatic<1024> v203; // [sp+1F0h] [-5920h] BYREF
  idStrStatic<1024> v204; // [sp+610h] [-5500h] BYREF
  idCmdArgs v205; // [sp+A30h] [-50E0h] BYREF
  gameReturn_t v206; // [sp+1340h] [-47D0h] BYREF
  idCommonLocal *v207; // [sp+5B24h] [+14h]

  v207 = (idCommonLocal *)((int (*)(void))RtlCheckStack12)();
  LODWORD(v1) = 0;
  v2 = v207;
  v181 = &com_recordFrameTrace;
  v192 = com_recordFrameTrace.valueInteger != 0;
  RD_Syncpoint(name: "idCommonLocal::FrameSync");
  RD_EventBegin(name: "idCommonLocal::Frame");
  soundSystem->WaitForSoundThread(this: soundSystem);
  renderSystem->AllowBackgroundSwaps(this: renderSystem, a2: false);
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorWhite);
  idPLog::Clear(this: &pLog);
  RD_EventBegin(name: "TOTAL");
  LODWORD(v3) = "TOTAL";
  HIDWORD(v3) = 4095;
  idPLogScope::idPLogScope(this: &v191, pl: &pLog, gMask: v3, label: v4);
  v5 = v207->Game(this: v207);
  idGameLock::idGameLock(this: v196, newGame: v5);
  RD_EventBegin(name: "MAIN_Spin");
  LODWORD(v6) = "MAIN_Spin";
  HIDWORD(v6) = 128;
  idPLogScope::idPLogScope(this: &v189, pl: &pLog, gMask: v6, label: v7);
  v190 = &com_timescale;
  if ( com_timescale.valueFloat < 1.0 || com_syncToTime.valueInteger != 0 && r_swapInterval.valueInteger == 0 )
  {
    ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v199);
    v200 = RANGE_MAIN;
    console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorYellow);
    v8 = Sys_Microseconds();
    v9 = ((int (__fastcall *)(idCommonLocal *, int))v207->Game)(a1: v207, a2: v8);
    valueFloat = com_timescale.valueFloat;
    LODWORD(v11) = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v9 + 144))(a1: v9, a2: 0);
    v193 = (__int64)(float)((float)1000000.0 / (float)((float)v11 * (float)valueFloat));
    v12 = v193;
    if ( (_S20 & 1) == 0 )
    {
      _S20 |= 1u;
      LODWORD(v13) = Sys_Microseconds() >> 32;
      lastTime_1 = v13;
    }
    v14 = Sys_Microseconds();
    LODWORD(v15) = HIDWORD(v14);
    while ( (int)v15 - (int)lastTime_1 < (unsigned int)v12 )
    {
      ((void (__fastcall *)(idSession *, _DWORD))session->Pump)(a1: session, a2: v14);
      Sys_Yield();
      v14 = Sys_Microseconds();
      LODWORD(v15) = HIDWORD(v14);
    }
    HIDWORD(v15) = v15 - lastTime_1;
    lastTime_1 = v15;
    ((void (__fastcall *)(idSession *, _DWORD))session->Pump)(a1: session, a2: v14);
    time_spinning = (Sys_Microseconds() >> 32) - HIDWORD(v12);
    console->BeginTimeRange(this: console, a2: v200, a3: (const idColor *)v199);
  }
  else
  {
    time_spinning = 0;
  }
  v197 = v1;
  idPLogScope::End(this: &v189, totalTicks: &v197);
  RD_EventBegin(name: "MAIN_Misc1");
  v188.pLog = &pLog;
  v188.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v16 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v16 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v16->label = "MAIN_Misc1";
    v16->parent = pLog.lastEntry;
    v188.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v17) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v16->totalTicks = v17;
  }
  v18 = Sys_Microseconds() >> 32;
  idCommonLocal::ShowJobListTimeRanges(this: v207, a2: v18, displayStartTime: v19);
  idCommonLocal::CalcPerfTimings(this: v207);
  if ( com_traceFrame.valueInteger != 0 )
  {
    if ( com_traceFrame.valueInteger == 1 )
      idCVar::SetInteger(this: &com_traceFrame, newValue: -1, force: true);
    else
      idCVar::SetInteger(this: &com_traceFrame, newValue: 0, force: true);
  }
  if ( console->IsActive(this: console) || com_editorActive.valueInteger != 0 )
  {
    v21 = sys->Mouse(this: sys);
    v21->GrabCursor(this: v21, a2: false);
    LOBYTE(v1) = 1;
  }
  else if ( (com_editors & 2) == 0 )
  {
    v20 = sys->Mouse(this: sys);
    v20->GrabCursor(this: v20, a2: true);
  }
  v22 = (int)v207->Game(this: v207);
  v23 = (*(int (__fastcall **)(int))(*(_DWORD *)v22 + 324))(a1: v22);
  v24 = 0;
  v182 = &debugMenu;
  while ( v24 < 4 )
  {
    v158 = (int)v2->Game(this: v2);
    v159 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v158 + 328))(a1: v158, a2: v24);
    if ( v159 < 0 )
    {
      if ( session->GetState(this: session) < INGAME )
      {
        v198[2] = 1.0;
        v198[3] = joy_pitchSpeed.valueFloat;
        v198[0] = 0.0;
        HIBYTE(v198[6]) = 0;
        v198[1] = 1.0;
        v198[4] = joy_yawSpeed.valueFloat;
        BYTE1(v198[6]) = in_invertLook.valueInteger != 0;
        v198[5] = m_sensitivity.valueFloat;
        usercmdGen->GetUsercmd(
          this: (idUsercmdGen *)&v202,
          result: (usercmd_t *)usercmdGen,
          a3: v24,
          a4: (const inputSettings_t *)v198,
          a5: false,
          a6: -1);
      }
      ++v24;
      v2 = v207;
    }
    else
    {
      v160 = (int)v207->Game(this: v207);
      if ( (*(unsigned __int8 (__fastcall **)(int, int))(*(_DWORD *)v160 + 320))(a1: v160, a2: v159) != 0
        || (v161 = (*v182)->IsActive(this: *v182), v162 = 0, v161) )
      {
        v162 = 1;
      }
      if ( (_BYTE)v1 != 0 || (v163 = false, v162 != 0) )
        v163 = true;
      usercmdGen->GetUsercmd(
        this: (idUsercmdGen *)v201,
        result: (usercmd_t *)usercmdGen,
        a3: v24,
        a4: &v207->inputSettings[v24],
        a5: v163,
        a6: v159);
      v164 = (int)v207->Game(this: v207);
      v165 = (idGameTimeManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v164 + 140))(a1: v164);
      v201[4] = idAccolade::Count(this: v165);
      v166 = v207->IsClient(this: v207);
      Game = v207->Game;
      if ( v166 )
      {
        v168 = (int)Game(this: v207);
        v169 = (int)v207->Game(this: v207);
        v170 = (*(int (__fastcall **)(int))(*(_DWORD *)v168 + 196))(a1: v168);
        v171 = (*(int (__fastcall **)(int))(*(_DWORD *)v169 + 188))(a1: v169);
        if ( v171 >= v170 )
        {
          v201[10] = v170;
          goto LABEL_266;
        }
      }
      else
      {
        v172 = (int)Game(this: v207);
        v171 = (*(int (__fastcall **)(int))(*(_DWORD *)v172 + 188))(a1: v172);
      }
      v201[10] = v171;
LABEL_266:
      p_userCmdMgr = &v207->userCmdMgr;
      v174 = 4 * (v159 + 11520);
      HIDWORD(v193) = p_userCmdMgr;
      v175 = 4 * (v159 + 11526);
      v176 = *(int *)((char *)&v207->userCmdMgr.cmdBuffer[0][0].buttons + v174);
      v201[0] &= ((unsigned __int8)v1 != 0) - 1;
      *(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v175) = v176 - 1;
      memcpy(
        Dst: &v207->userCmdMgr.cmdBuffer[v176 % 128][v159],
        Src: v201,
        Size: sizeof(v207->userCmdMgr.cmdBuffer[v176 % 128][v159]));
      v177 = *(int *)((char *)&v207->userCmdMgr.cmdBuffer[0][0].buttons + v174);
      if ( v177 - *(int *)((char *)&v207->userCmdMgr.cmdBuffer[0][0].buttons + v175) + 1 > 128 )
      {
        *(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v175) = v177 - 64;
        idLib::Printf(fmt: "PutUserCmdForPlayer: buffer overflow.\n");
      }
      ++v24;
      v2 = v207;
      ++*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v174);
    }
  }
  if ( v23 == 0 && session->GetState(this: session) == INGAME )
  {
    v25 = (int)v2->Game(this: v2);
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v25 + 228))(a1: v25) == 0
      && net_headlessServer.valueInteger == 0 )
    {
      v26 = (int)v2->Game(this: v2);
      (*(void (__fastcall **)(int, int))(*(_DWORD *)v26 + 216))(a1: v26, a2: 1);
    }
  }
  if ( !session->IsSystemUIShowing(this: session)
    || (v27 = (int)v2->Game(this: v2), (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v27 + 228))(a1: v27) != 0)
    || (v28 = (int)v2->Game(this: v2), (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v28 + 12))(a1: v28) == 0)
    || common->IsMultiplayer(this: common) )
  {
    if ( session->IsSystemUIShowing(this: session) && common->IsMultiplayer(this: common) )
      idKeyInput::ClearStates();
  }
  else
  {
    idKeyInput::ClearStates();
    v29 = (int)v2->Game(this: v2);
    (*(void (__fastcall **)(int, int))(*(_DWORD *)v29 + 216))(a1: v29, a2: 1);
  }
  Sys_Microseconds();
  idPLogScope::End(this: &v188, totalTicks: nullptr);
  RD_EventBegin(name: "MAIN_RunFrame");
  v187.pLog = &pLog;
  v187.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v30 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v30 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v30->label = "MAIN_RunFrame";
    v30->parent = pLog.lastEntry;
    v187.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v31) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v30->totalTicks = v31;
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorYellow);
  gameReturn_t::gameReturn_t(this: &v206);
  v32 = (int)v2->Game(this: v2);
  v33 = (idGameTimeManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v32 + 140))(a1: v32);
  idGameTimeManager::UpdateTimeScale(this: v33);
  if ( !common->IsMultiplayer(this: common) )
  {
    if ( com_editorActive.valueInteger != 0 && (com_editors & 0xA004) != 0 )
      goto _M228720_0;
    goto LABEL_52;
  }
  v34 = session->GetActingGameStateLobbyBase(this: session);
  if ( v34->IsHost(this: v34) != 0 && session->GetState(this: session) == INGAME )
  {
LABEL_52:
    idCommonLocal::RunNormalFrame(this: v2, gameReturn: &v206);
    goto _M228720_0;
  }
  v35 = session->GetActingGameStateLobbyBase(this: session);
  if ( v35->IsPeer(this: v35) && session->GetState(this: session) == INGAME )
    idCommonLocal::RunNetworkSnapshotFrame(this: v2, gameReturn: &v206);
_M228720_0:
  v36 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v153 = (int)v2->Game(this: v2);
    v154 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v153 + 328))(a1: v153, a2: i);
    if ( v154 >= 0 )
    {
      p_hudModel = &v206.players.ptr[v154].hudModel;
      v156 = &v2->mapChangeListeners.granularity + 14 * i;
      for ( j = 7; j != 0; --j )
      {
        ++p_hudModel;
        v156 += 2;
        *(_DWORD *)v156 = *p_hudModel;
      }
    }
  }
  v38 = 0;
  v193 = 0;
  v194 = 0;
  v195 = 0;
  while ( v38 < 4 )
  {
    v151 = (int)v2->Game(this: v2);
    v152 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v151 + 328))(a1: v151, a2: v38);
    if ( v152 >= 0 && v206.players.ptr[v152].valid )
      *((_DWORD *)&v193 + v36++) = v152;
    ++v38;
  }
  idPLogScope::End(this: &v187, totalTicks: nullptr);
  RD_EventBegin(name: "MAIN_GUI");
  v183.pLog = &pLog;
  v183.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v39 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v39 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v39->label = "MAIN_GUI";
    v39->parent = pLog.lastEntry;
    v183.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v40) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v39->totalTicks = v40;
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorOrange);
  v41 = (int)v2->Game(this: v2);
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v41 + 228))(a1: v41) != 0 )
  {
    v42 = v2->game->Shell_Render(this: v2->game);
    idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: v42, loading: false);
  }
  else
  {
    v43 = renderSystem->FrameNumber(this: renderSystem);
    v44 = v2->Game(this: v2);
    idRenderManager::BuildGameFrame(this: &renderManager, gameReturn: &v206, game: v44, frameNumber: v43);
  }
  idPLogScope::End(this: &v183, totalTicks: nullptr);
  RD_EventBegin(name: "MAIN_Sound");
  v185.pLog = &pLog;
  v185.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v45 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v45 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v45->label = "MAIN_Sound";
    v45->parent = pLog.lastEntry;
    v185.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v46) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v45->totalTicks = v46;
  }
  renderSystem->AllowBackgroundSwaps(this: renderSystem, a2: true);
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorPurple);
  v47 = Sys_Microseconds() >> 32;
  if ( (unsigned __int8)XGComparePixelShaders() != 0 || com_forceSound.valueInteger != 0 || (com_editors & 0x40100) != 0 )
  {
    v48 = v207;
    v51 = (int)v207->Game(this: v207);
    v52 = (idSoundWorld *)(*(int (__fastcall **)(int))(*(_DWORD *)v51 + 20))(a1: v51);
    if ( v36 <= 0
      || (v53 = (int)v207->Game(this: v207),
          (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v53 + 284))(a1: v53) != 0)
      || (v54 = (int)v207->Game(this: v207),
          (*(int (__fastcall **)(int, int))(*(_DWORD *)v54 + 156))(a1: v54, a2: 1) < 250) )
    {
      v59 = (int)v207->Game(this: v207);
      v60 = (idSoundWorld *)(*(int (__fastcall **)(int))(*(_DWORD *)v59 + 24))(a1: v59);
      v60->SetNumListeners(this: v60, a2: 1);
      v60->PlaceListener(this: v60, a2: &vec3_origin, a3: &mat3_identity, a4: &vec3_origin, a5: -1);
      v52->Pause(this: v52);
      soundSystem->SetPlayingSoundWorld(this: soundSystem, a2: v60);
    }
    else
    {
      v52->SetNumListeners(this: v52, a2: v36);
      v55 = 0;
      for ( k = 0; k < 4 && v55 < v36; ++k )
      {
        v57 = (int)v207->Game(this: v207);
        v58 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v57 + 328))(a1: v57, a2: k);
        if ( v58 >= 0 && v206.players.ptr[v58].valid )
        {
          v52->PlaceListener(
            this: v52,
            a2: &v206.players.ptr[v58].view.vieworg,
            a3: &v206.players.ptr[v58].view.viewaxis,
            a4: &v206.players.ptr[v58].velocity,
            a5: v206.players.ptr[v58].view.viewID);
          ++v55;
        }
      }
      v52->UnPause(this: v52);
      soundSystem->SetPlayingSoundWorld(this: soundSystem, a2: v52);
    }
  }
  else
  {
    v48 = v207;
    v49 = (int)v207->Game(this: v207);
    v50 = (*(int (__fastcall **)(int))(*(_DWORD *)v49 + 20))(a1: v49);
    if ( v50 != 0 )
      (*(void (__fastcall **)(int))(*(_DWORD *)v50 + 104))(a1: v50);
    soundSystem->SetPlayingSoundWorld(this: soundSystem, a2: nullptr);
  }
  time_gameFrame += (Sys_Microseconds() >> 32) - v47;
  idPLogScope::End(this: &v185, totalTicks: nullptr);
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorCyan);
  v61 = Sys_Microseconds();
  v62 = 0;
  while ( 2 )
  {
    if ( v62 < 4 )
    {
_M229163:
      vibrationLow = 0;
      vibrationHigh = 0;
      if ( in_joystickRumble.valueInteger != 0 )
      {
        v145 = ((int (__fastcall *)(idCommonLocal *, int))v48->Game)(a1: v48, a2: v61);
        if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v145 + 228))(a1: v145) == 0 )
        {
          v146 = (int)v48->Game(this: v48);
          if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v146 + 284))(a1: v146) == 0 )
          {
            v147 = (int)v48->Game(this: v48);
            if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v147 + 12))(a1: v147) != 0 )
            {
              v148 = (int)v48->Game(this: v48);
              v149 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v148 + 328))(a1: v148, a2: v62);
              if ( v149 >= 0 )
              {
                vibrationLow = v206.players.ptr[v149].vibrationLow;
                vibrationHigh = v206.players.ptr[v149].vibrationHigh;
              }
            }
          }
        }
      }
      v150 = ((int (__fastcall *)(idSys *, int))sys->Joystick)(a1: sys, a2: v61);
      (*(void (__fastcall **)(int, int, int, int))(*(_DWORD *)v150 + 16))(
        a1: v150,
        a2: v62++,
        a3: vibrationLow,
        a4: vibrationHigh);
      continue;
    }
    break;
  }
  if ( v185.logIndex >= 0 )
  {
    v63 = &v185.pLog->logEntries.list[v185.logIndex];
    v64 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v63->totalTicks;
    HIDWORD(totalTicks) = v63->parent;
    LODWORD(v66) = v64 - totalTicks;
    v63->totalTicks = v66;
    v185.pLog->lastEntry = HIDWORD(totalTicks);
    v185.logIndex = -1;
  }
  RD_EventEnd();
  if ( v183.logIndex >= 0 )
  {
    v67 = &v183.pLog->logEntries.list[v183.logIndex];
    v68 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v69 = v67->totalTicks;
    HIDWORD(v69) = v67->parent;
    LODWORD(v70) = v68 - v69;
    v67->totalTicks = v70;
    v183.pLog->lastEntry = HIDWORD(v69);
    v183.logIndex = -1;
  }
  RD_EventEnd();
  if ( v206.debugGuis.listStatic == 0 || v206.debugGuis.listStatic == 2 )
  {
    if ( v206.debugGuis.list != nullptr )
    {
      for ( m = 0; m < v206.debugGuis.size; ++m )
        ;
      idMem::Free(this: &mem, ptr: v206.debugGuis.list, align: ALIGN_16);
      v206.debugGuis.list = nullptr;
      v206.debugGuis.size = 0;
    }
    else
    {
      v206.debugGuis.list = nullptr;
      v206.debugGuis.size = 0;
    }
  }
  v206.debugGuis.num = 0;
  `eh vector destructor iterator'(
    ptr: &v206.players,
    size: 0x7A0u,
    count: 6,
    pDtor: (void (__fastcall *)(void *))gameReturnPlayer_t::~gameReturnPlayer_t);
  if ( v187.logIndex >= 0 )
  {
    v72 = &v187.pLog->logEntries.list[v187.logIndex];
    v73 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v74 = v72->totalTicks;
    HIDWORD(v74) = v72->parent;
    LODWORD(v75) = v73 - v74;
    v72->totalTicks = v75;
    v187.pLog->lastEntry = HIDWORD(v74);
    v187.logIndex = -1;
  }
  RD_EventEnd();
  RD_EventBegin(name: "MAIN_Misc2");
  v186.pLog = &pLog;
  v186.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v76 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v76 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v76->label = "MAIN_Misc2";
    v76->parent = pLog.lastEntry;
    v186.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v77) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v76->totalTicks = v77;
  }
  idCommonLocal::StopLevelLoad(this: v48, loadVirtualTextures: true);
  if ( com_skipSignInManager.valueInteger == 0 )
    session->UpdateSignInManager(this: session);
  if ( !v48->TimeTrialPlaying(this: v48) && !v48->TimeTrialRecording(this: v48) && !v48->DemoPlaying(this: v48) )
    idCommonLocal::NetSendUsercmds(this: v48);
  idPLogScope::End(this: &v186, totalTicks: nullptr);
  ++idLib::frameNumber;
  v79 = (idSession *)XGComparePixelShaders();
  if ( (_BYTE)v79 == 0 )
  {
    ContentPackagePath = idSession::GetContentPackagePath(this: v79, contentIndex: v78);
    idLib::Printf(fmt: ContentPackagePath);
    idLib::FatalError(fmt: "idCommon::Frame: the FPU stack is not empty at the end of the frame\n");
    goto _M229163;
  }
  if ( com_captureSounds.valueInteger == 2 )
    idCVar::SetInteger(this: &com_captureSounds, newValue: 3, force: true);
  RD_EventBegin(name: "MAIN_RenderSync");
  v184.pLog = &pLog;
  v184.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v80 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v80 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v80->label = "MAIN_RenderSync";
    v80->parent = pLog.lastEntry;
    v184.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v81) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v80->totalTicks = v81;
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorRed);
  v82 = Sys_Microseconds() >> 32;
  renderSystem->SyncRenderThread(this: renderSystem, a2: false);
  LODWORD(v83) = (Sys_Microseconds() >> 32) - v82;
  DWORD2(v83) = 1000;
  DWORD1(v83) = &idDeclReachIK::resourceList.hashTable[243];
  time_renderThreadSync = (unsigned __int64)v83 / *(_QWORD *)((char *)&v83 + 4);
  idPLogScope::End(this: &v184, totalTicks: nullptr);
  RD_EventBegin(name: "MAIN_Misc3");
  v179.pLog = &pLog;
  v179.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v84 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v84 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v84->label = "MAIN_Misc3";
    v84->parent = pLog.lastEntry;
    v179.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v85) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v84->totalTicks = v85;
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorBrown);
  session->Pump(this: session);
  session->ProcessSnapAckQueue(this: session);
  common->SetRefreshOnPrint(this: common, a2: false);
  renderSystem->InhibitEndFrameRendering(this: renderSystem, a2: 0x80000000);
  if ( common != nullptr && common->Game(this: common) != nullptr )
  {
    v86 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v86 != nullptr )
    {
      v87 = 0;
      if ( (cvarSystem->GetModifiedFlags(this: cvarSystem) & 0x10000) != 0 )
      {
        cvarSystem->ClearModifiedFlags(this: cvarSystem, a2: 0x10000);
        v48->WriteConfigToFile(this: v48, a2: "tungstenConfigXenon.cfg");
        v87 = 1;
      }
      if ( v87 != 0 )
        idPlayerProfile::SaveSettings(this: v86);
    }
  }
  sys->GenerateEvents(this: sys);
  v48->inConsoleCommand = true;
  v88 = session->GetState(this: session);
  v89 = session->__vftable;
  if ( v88 == (PARTY_LOBBY|SEARCHING) )
  {
    v90 = ((int (*)(void))v89->GetActingGameStateLobbyBase)();
    v91 = (*(int (__fastcall **)(int))(*(_DWORD *)v90 + 128))(a1: v90);
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v92 = (idGameSpawnInfo *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x150B8u,
                               tag: TAG_GAME,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v92 != nullptr )
      v93 = idGameSpawnInfo::idGameSpawnInfo(this: v92, mapName_: *(const char **)(v91 + 28), gameFlags_: 284);
    else
      v93 = nullptr;
    v94 = session->GetActingGameStateLobbyBase(this: session);
    if ( v94->IsHost(this: v94) == 0 )
      v93->gameFlags = 72;
    if ( com_disableGameScripts.valueInteger != 0 )
      v93->gameFlags &= ~8u;
    idGameSpawnInfo::ReadLayersFromCommaSeparatedStrings(
      this: v93,
      activeString: *(const char **)(v91 + 188),
      deactiveString: *(const char **)(v91 + 2268));
    v93->comboMap = *(_BYTE *)(v91 + 4622);
    v93->devmap = *(_BYTE *)(v91 + 4623);
    idStrStatic<1024>::idStrStatic<1024>(this: &v204, text: (const idStr *)(v91 + 4440));
    v93->debugJobName.len = v204.len;
    memcpy(Dst: v93->debugJobName.data, Src: v204.data, Size: v204.len + 1);
    idStr::FreeData(this: &v204);
    v93->debugJobState = *(_DWORD *)(v91 + 4600);
    if ( *(_DWORD *)(v91 + 184) != 0 || (v95 = 1, *(_DWORD *)(v91 + 2264) != 0) )
      v95 = 0;
    v93->initialMap = v95;
    idStrStatic<1024>::idStrStatic<1024>(this: &v203, text: (const idStr *)(v91 + 4344));
    data = v93->spawnSpot.data;
    v93->spawnSpot.len = v203.len;
    memcpy(Dst: data, Src: v203.data, Size: v203.len + 1);
    idStr::FreeData(this: &v203);
    v93->isTransitionalMapRequest = *(_BYTE *)(v91 + 4624);
    v97 = session->GetActingGameStateLobbyBase(this: session);
    v93->numPlayers = v97->GetNumLobbyUsers(this: v97);
    if ( com_forceAllMapLayersToLoad.valueInteger != 0 )
      v93->gameFlags |= 0x80u;
    idMem::PopHeap(this: &mem);
    if ( common->IsMultiplayer(this: common) && !idLib::headless )
    {
      v98 = (int)v48->Game(this: v48);
      (*(void (__fastcall **)(int))(*(_DWORD *)v98 + 268))(a1: v98);
    }
    v48->ExecuteMapChange(this: v48, a2: v93, a3: nullptr);
    idGameSpawnInfo::~idGameSpawnInfo(this: v93);
    idMem::Free(this: &mem, ptr: (void *)v93, align: ALIGN_16);
  }
  else if ( ((int (*)(void))v89->GetState)() != 7 && v48->game->IsGameActive(this: v48->game) )
  {
    if ( session->GetState(this: session) == 1 )
      idCommonLocal::Disconnect(this: v48, cancelAllProcessors: true);
    else
      idCommonLocal::LeaveGame(this: v48, cancelProcessors: true);
  }
  v99 = v182;
  while ( 2 )
  {
    cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
    ((void (__fastcall *)(sysEvent_t *))sys->GetEvent)(a1: &v178);
    if ( v48->eventFile != nullptr )
    {
      if ( v48->recordState == RECORD_MAKE )
      {
        idCommonLocal::WriteSysEvent(this: v48, ev: &v178);
      }
      else if ( v178.evType == SE_KEY && v178.evValue == 88 )
      {
        v48->RecordPlayback(this: v48, a2: false, a3: nullptr);
      }
      else
      {
        idCommonLocal::ReadSysEvent(this: v48, ev: &v178);
      }
    }
    evType = v178.evType;
    if ( v178.evType != SE_NONE )
    {
      if ( v178.evType == SE_KEY )
      {
        idKeyInput::PreliminaryKeyEvent(
          deviceNum: v178.inputDevice,
          keyNum: (keyNum_t)v178.evValue,
          down: v178.evValue2 != 0);
        evType = v178.evType;
      }
      if ( evType == SE_CONSOLE )
      {
        cmdSystem->AppendCommandText(this: cmdSystem, a2: (const char *)v178.evPtr);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
        goto _M229154;
      }
      if ( !(*v99)->HandleGuiEvent(this: *v99, a2: &v178)
        && !console->ProcessEvent(this: console, a2: &v178, a3: false)
        && (v48->IsDialogActive(this: v48) || !session->ProcessInputEvent(this: session, a2: &v178)) )
      {
        signInManager = session->signInManager;
        if ( signInManager->GetNumLocalUsers(this: signInManager) <= 0 )
          v135 = 0;
        else
          v135 = (int)signInManager->GetLocalUserByIndex_2(this: signInManager, a2: 0);
        LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(
                                   this: session->signInManager,
                                   index: v178.inputDevice);
        if ( LocalUserByInputDevice == nullptr )
          LocalUserByInputDevice = session->signInManager->GetRegisteringUserByInputDevice(
                                     this: session->signInManager,
                                     a2: v178.inputDevice);
        if ( v135 != 0 )
        {
          if ( LocalUserByInputDevice != nullptr )
          {
_M229133_0:
            v137 = (int)v48->Game(this: v48);
            if ( (*(unsigned __int8 (__fastcall **)(int, sysEvent_t *))(*(_DWORD *)v137 + 280))(a1: v137, a2: &v178) == 0 )
            {
              v48->recentInputDevice = v178.inputDevice;
              if ( (unsigned __int8)idCommonLocal::HandleDialogEvent(this: v48, sev: &v178) == 0 )
              {
                v138 = (int)v48->Game(this: v48);
                if ( (*(unsigned __int8 (__fastcall **)(int, sysEvent_t *))(*(_DWORD *)v138 + 232))(a1: v138, a2: &v178) == 0 )
                {
                  v139 = (int)v48->Game(this: v48);
                  v140 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v139 + 328))(a1: v139, a2: v178.inputDevice);
                  if ( v140 < 0
                    || (v141 = (int)v48->Game(this: v48),
                        (*(unsigned __int8 (__fastcall **)(int, sysEvent_t *, int))(*(_DWORD *)v141 + 76))(
                          a1: v141,
                          a2: &v178,
                          a3: v140) == 0) )
                  {
                    if ( v178.evType == SE_KEY
                      && v178.evValue2 != 0
                      && !idKeyInput::ExecKeyBinding(
                            numDevice: v178.inputDevice,
                            bindset: v48->inputSettings[v178.inputDevice].bindset,
                            keynum: (keyNum_t)v178.evValue) )
                    {
                      idKeyInput::ExecKeyBinding(
                        numDevice: v178.inputDevice,
                        bindset: BIND_DEFAULT,
                        keynum: (keyNum_t)v178.evValue);
                    }
                  }
                }
              }
            }
          }
        }
        else if ( LocalUserByInputDevice != nullptr
               || session->signInManager->GetRegisteringUser(this: session->signInManager) == nullptr )
        {
          goto _M229133_0;
        }
      }
_M229154:
      if ( v178.evPtr != nullptr )
        idMem::Free(this: &mem, ptr: v178.evPtr, align: ALIGN_16);
      continue;
    }
    break;
  }
  if ( (sys_lang.flags & 0x20000) != 0 )
  {
    sys_lang.flags &= ~0x20000u;
    idCommonLocal::InitLanguageDict(this: v48);
    idResourceList::ReloadStaleResources(this: &idFont::resourceList);
  }
  idSaveGameManager::Pump(this: session->saveGameManager);
  v48->inConsoleCommand = false;
  debugHUD->Frame(this: debugHUD);
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorPurple);
  soundSystem->Render(this: soundSystem, a2: true);
  idPLogScope::End(this: &v179, totalTicks: nullptr);
  RD_EventBegin(name: "MAIN_RenderEndFrame");
  v180.pLog = &pLog;
  v180.logIndex = -1;
  if ( (pLog.groupMask & 0x80) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &pLog.logEntries, newSize: pLog.logEntries.num + 1);
    if ( pLog.logEntries.num >= pLog.logEntries.size )
      v101 = &pLog.logEntries.list[pLog.logEntries.size - 1];
    else
      v101 = &pLog.logEntries.list[pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v101->label = "MAIN_RenderEndFrame";
    v101->parent = pLog.lastEntry;
    v180.logIndex = pLog.logEntries.num - 1;
    pLog.lastEntry = pLog.logEntries.num - 1;
    LODWORD(v102) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v101->totalTicks = v102;
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorMdGrey);
  if ( v48->levelLoadInProgress <= 0 && (com_editors & 0x800000) == 0 )
    idRenderManager::RenderFrame(this: &renderManager);
  idPLogScope::End(this: &v180, totalTicks: nullptr);
  if ( com_captureFrames.valueInteger == 2 )
  {
    v205.argc = 0;
    idCmdArgs::AppendArg(this: &v205, text: "screenshot");
    if ( com_captureTGA.valueInteger == 1 )
    {
      idCmdArgs::AppendArg(this: &v205, text: "tga");
      idCmdArgs::AppendArg(this: &v205, text: "loadtextures");
    }
    else if ( com_captureTGA.valueInteger == 2 )
    {
      idCmdArgs::AppendArg(this: &v205, text: "png");
      idCmdArgs::AppendArg(this: &v205, text: "loadtextures");
    }
    LODWORD(v193) = (int)(float)((float)1.0 / v190->valueFloat);
    v103 = v193;
    if ( (_DWORD)v193 == 0 )
      v103 = 1;
    while ( v103-- != 0 )
      R_ScreenShot_f(args: &v205);
  }
  if ( v48->purgeOverlays )
  {
    v48->purgeOverlays = false;
    idImageManager::PurgeAllOverlays(this: globalImages);
  }
  idSWF::PurgeUnusedImages();
  idPLogScope::End(this: &v191, totalTicks: nullptr);
  if ( LODWORD(pLog.groupMask) != 0 )
  {
    if ( plog_mode.valueInteger != 0 )
    {
      if ( plog_mode.valueInteger == 1 )
      {
        HIDWORD(v105) = v197;
        idPLog::ShowCallGraph(this: &pLog, thresholdMS: plog_threshold.valueFloat, adjustByTicks: v105);
      }
    }
    else
    {
      HIDWORD(v105) = v197;
      idPLog::ShowUniqueEntries(this: &pLog, thresholdMS: plog_threshold.valueFloat, adjustByTicks: v105);
    }
  }
  if ( v48->quitFlag )
    v48->Shutdown(this: v48, a2: v48->quitExitCode);
  if ( v180.logIndex >= 0 )
  {
    v106 = &v180.pLog->logEntries.list[v180.logIndex];
    v107 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v108 = v106->totalTicks;
    HIDWORD(v108) = v106->parent;
    LODWORD(v109) = v107 - v108;
    v106->totalTicks = v109;
    v180.pLog->lastEntry = HIDWORD(v108);
    v180.logIndex = -1;
  }
  RD_EventEnd();
  if ( v179.logIndex >= 0 )
  {
    v110 = &v179.pLog->logEntries.list[v179.logIndex];
    v111 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v112 = v110->totalTicks;
    HIDWORD(v112) = v110->parent;
    LODWORD(v113) = v111 - v112;
    v110->totalTicks = v113;
    v179.pLog->lastEntry = HIDWORD(v112);
    v179.logIndex = -1;
  }
  RD_EventEnd();
  if ( v184.logIndex >= 0 )
  {
    v114 = &v184.pLog->logEntries.list[v184.logIndex];
    v115 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v116 = v114->totalTicks;
    HIDWORD(v116) = v114->parent;
    LODWORD(v117) = v115 - v116;
    v114->totalTicks = v117;
    v184.pLog->lastEntry = HIDWORD(v116);
    v184.logIndex = -1;
  }
  RD_EventEnd();
  if ( v186.logIndex >= 0 )
  {
    v118 = &v186.pLog->logEntries.list[v186.logIndex];
    v119 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v120 = v118->totalTicks;
    HIDWORD(v120) = v118->parent;
    LODWORD(v121) = v119 - v120;
    v118->totalTicks = v121;
    v186.pLog->lastEntry = HIDWORD(v120);
    v186.logIndex = -1;
  }
  RD_EventEnd();
  if ( v188.logIndex >= 0 )
  {
    v122 = &v188.pLog->logEntries.list[v188.logIndex];
    v123 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v124 = v122->totalTicks;
    HIDWORD(v124) = v122->parent;
    LODWORD(v125) = v123 - v124;
    v122->totalTicks = v125;
    v188.pLog->lastEntry = HIDWORD(v124);
    v188.logIndex = -1;
  }
  RD_EventEnd();
  if ( v189.logIndex >= 0 )
  {
    v126 = &v189.pLog->logEntries.list[v189.logIndex];
    v127 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v128 = v126->totalTicks;
    HIDWORD(v128) = v126->parent;
    LODWORD(v129) = v127 - v128;
    v126->totalTicks = v129;
    v189.pLog->lastEntry = HIDWORD(v128);
    v189.logIndex = -1;
  }
  RD_EventEnd();
  idGameLock::~idGameLock(this: v196);
  if ( v191.logIndex >= 0 )
  {
    v130 = &v191.pLog->logEntries.list[v191.logIndex];
    v131 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v132 = v130->totalTicks;
    HIDWORD(v132) = v130->parent;
    LODWORD(v133) = v131 - v132;
    v130->totalTicks = v133;
    v191.pLog->lastEntry = HIDWORD(v132);
    v191.logIndex = -1;
  }
  RD_EventEnd();
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorBlack);
  if ( v192 )
    idCVar::SetBool(this: v181, newValue: false, force: true);
  RD_EventEnd();
}


// ========================================================================
// $M229259
// EA  : 0x82656C04
// RVA : 0x00656C04
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void *_M229259()
{
  idLib::Printf(fmt: "idNetworkLoadException: %s\n", idException::error);
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
  return &_LN180;
}


// ========================================================================
// $M229262
// EA  : 0x82656C6C
// RVA : 0x00656C6C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _M229262()
{
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $M229265
// EA  : 0x82656C8C
// RVA : 0x00656C8C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void *_M229265()
{
  int v0; // r12
  int v1; // r31
  idCommonLocal *v2; // r30
  bool v3; // r29
  int v4; // r3
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  va *v8; // r3
  int v10; // [sp+8h] [-78h]
  int v11; // [sp+Ch] [-74h]
  int v12; // [sp+10h] [-70h]
  int v13; // [sp+14h] [-6Ch]
  int v14; // [sp+18h] [-68h]
  int v15; // [sp+1Ch] [-64h]

  v1 = v0 - 23312;
  fileSystem->SetFilePreCallback(this: fileSystem, a2: nullptr);
  v2 = *(idCommonLocal **)(v1 + 23332);
  v3 = false;
  if ( v2->IsMultiplayer(this: v2) && session != nullptr )
    v3 = session->GetState(this: session) >= (PARTY_LOBBY|SEARCHING);
  renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
  v2->SetRefreshOnPrint(this: v2, a2: false);
  if ( idLib::headless || idLib::production == PROD_BUILDING )
    CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
  if ( v2->GetRegression(this: v2) != nullptr )
  {
    v4 = (int)v2->GetRegression(this: v2);
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v4 + 52))(a1: v4) != 0 )
    {
      *(_DWORD *)(v1 + 16704) = 0;
      Com_TestStatsEnd_f(args: (const idCmdArgs *)(v1 + 16704));
      Sys_Quit(exitCode: -1);
    }
  }
  if ( com_gatherMapStats.valueInteger != 0 )
    Sys_Quit(exitCode: -1);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)idException::error);
  idCommonLocal::Disconnect(this: v2, cancelAllProcessors: true);
  idLib::Printf(fmt: "^1********************^7 ERROR ^1********************\n");
  idLib::Printf(fmt: "^3%s\n", idException::error);
  idLib::Printf(fmt: "^1***********************************************\n");
  HIDWORD(v5) = &unk_821D0000;
  HIDWORD(v6) = idException::error;
  v8 = va::va(
         this: (va *)(v1 + 19024),
         fmt: "ERROR: %s\n",
         a3: v6,
         a4: v5,
         a5: v7,
         a6: v10,
         a7: v11,
         a8: v12,
         a9: v13,
         a10: v14,
         a11: v15);
  if ( compileStatusHandler.compileStatus != nullptr )
    compileStatusHandler.compileStatus->Error(this: compileStatusHandler.compileStatus, a2: (const char *)v8);
  if ( v3 )
    ((void (__fastcall *)(idCommonLocal *, int, _DWORD, _DWORD, _DWORD, _DWORD, char *, _DWORD))v2->AddDialog)(
      a1: v2,
      a2: 120,
      a3: 0,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: &byte_8200D768,
      a8: 0);
  return &_LN184;
}


// ========================================================================
// $LN1415
// EA  : 0x82656ED0
// RVA : 0x00656ED0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _LN1415()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23128));
}


// ========================================================================
// __unwind$227657
// EA  : 0x82656EF8
// RVA : 0x00656EF8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227657()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23129));
}


// ========================================================================
// __unwind$227658
// EA  : 0x82656F20
// RVA : 0x00656F20
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227658()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 256));
}


// ========================================================================
// __unwind$227659
// EA  : 0x82656F48
// RVA : 0x00656F48
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227659()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 23312 + 288));
}


// ========================================================================
// __unwind$227660
// EA  : 0x82656F70
// RVA : 0x00656F70
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227660()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23130));
}


// ========================================================================
// __unwind$227661
// EA  : 0x82656F98
// RVA : 0x00656F98
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227661()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 240));
}


// ========================================================================
// __unwind$227662
// EA  : 0x82656FC0
// RVA : 0x00656FC0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227662()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 23312 + 336));
}


// ========================================================================
// __unwind$227663
// EA  : 0x82656FE8
// RVA : 0x00656FE8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227663()
{
  _S20 &= ~1u;
}


// ========================================================================
// __unwind$227664
// EA  : 0x82657008
// RVA : 0x00657008
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227664()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23131));
}


// ========================================================================
// __unwind$227665
// EA  : 0x82657030
// RVA : 0x00657030
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227665()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 232));
}


// ========================================================================
// __unwind$227666
// EA  : 0x82657058
// RVA : 0x00657058
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227666()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23132));
}


// ========================================================================
// __unwind$227667
// EA  : 0x82657080
// RVA : 0x00657080
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227667()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 224));
}


// ========================================================================
// __unwind$227668
// EA  : 0x826570A8
// RVA : 0x006570A8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227668()
{
  int v0; // r12

  gameReturn_t::~gameReturn_t(this: (gameReturn_t *)(v0 - 23312 + 4928));
}


// ========================================================================
// __unwind$227669
// EA  : 0x826570D0
// RVA : 0x006570D0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227669()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23133));
}


// ========================================================================
// __unwind$227670
// EA  : 0x826570F8
// RVA : 0x006570F8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227670()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 192));
}


// ========================================================================
// __unwind$227671
// EA  : 0x82657120
// RVA : 0x00657120
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227671()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23134));
}


// ========================================================================
// __unwind$227672
// EA  : 0x82657148
// RVA : 0x00657148
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227672()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 208));
}


// ========================================================================
// __unwind$227936
// EA  : 0x82657170
// RVA : 0x00657170
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227936()
{
  int v0; // r12

  idArray<gameReturnPlayer_t,6>::~idArray<gameReturnPlayer_t,6>(this: (idArray<gameReturnPlayer_t,6> *)(v0 - 23312 + 4944));
}


// ========================================================================
// __unwind$227673
// EA  : 0x8265719C
// RVA : 0x0065719C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227673()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23135));
}


// ========================================================================
// __unwind$227674
// EA  : 0x826571C4
// RVA : 0x006571C4
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227674()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 216));
}


// ========================================================================
// __unwind$227675
// EA  : 0x826571EC
// RVA : 0x006571EC
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227675()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23136));
}


// ========================================================================
// __unwind$227676
// EA  : 0x82657214
// RVA : 0x00657214
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227676()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 200));
}


// ========================================================================
// __unwind$227677
// EA  : 0x8265723C
// RVA : 0x0065723C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227677()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23137));
}


// ========================================================================
// __unwind$227678
// EA  : 0x82657264
// RVA : 0x00657264
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227678()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 168));
}


// ========================================================================
// __unwind$227679
// EA  : 0x8265728C
// RVA : 0x0065728C
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227679()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 23312 + 116), tag: TAG_GAME);
}


// ========================================================================
// __unwind$227682
// EA  : 0x826572B8
// RVA : 0x006572B8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227682()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 23312 + 23138));
}


// ========================================================================
// __unwind$227683
// EA  : 0x826572E0
// RVA : 0x006572E0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_227683()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 23312 + 176));
}


// ========================================================================
// `dynamic initializer for 'com_syncToTime''
// EA  : 0x833385A0
// RVA : 0x013385A0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_syncToTime__()
{
  idCVar::idCVar(
    this: &com_syncToTime,
    name: "com_syncToTime",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_syncToTime__);
}


// ========================================================================
// `dynamic initializer for 'com_skipSignInManager''
// EA  : 0x833385F8
// RVA : 0x013385F8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_skipSignInManager__()
{
  idCVar::idCVar(
    this: &com_skipSignInManager,
    name: "com_skipSignInManager",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_skipSignInManager__);
}


// ========================================================================
// `dynamic initializer for 'com_skipDiscSwapStateManager''
// EA  : 0x83338650
// RVA : 0x01338650
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_skipDiscSwapStateManager__()
{
  idCVar::idCVar(
    this: &com_skipDiscSwapStateManager,
    name: "com_skipDiscSwapStateManager",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_skipDiscSwapStateManager__);
}


// ========================================================================
// `dynamic initializer for 'com_skipInputRouting''
// EA  : 0x833386A8
// RVA : 0x013386A8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_skipInputRouting__()
{
  idCVar::idCVar(
    this: &com_skipInputRouting,
    name: "com_skipInputRouting",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_skipInputRouting__);
}


// ========================================================================
// `dynamic initializer for 'com_skipGameRenderView''
// EA  : 0x83338700
// RVA : 0x01338700
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_skipGameRenderView__()
{
  idCVar::idCVar(
    this: &com_skipGameRenderView,
    name: "com_skipGameRenderView",
    value: "0",
    flags: 17,
    description: "skip generating the GUIs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_skipGameRenderView__);
}


// ========================================================================
// `dynamic initializer for 'com_threadSpeedScale''
// EA  : 0x83338758
// RVA : 0x01338758
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_threadSpeedScale__()
{
  idCVar::idCVar(
    this: &com_threadSpeedScale,
    name: "com_threadSpeedScale",
    value: "10.0",
    flags: 20,
    description: "Time to screen scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_threadSpeedScale__);
}


// ========================================================================
// `dynamic initializer for 'com_hitchThresholdMS''
// EA  : 0x833387B0
// RVA : 0x013387B0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_hitchThresholdMS__()
{
  idCVar::idCVar(
    this: &com_hitchThresholdMS,
    name: "com_hitchThresholdMS",
    value: "33",
    flags: 18,
    description: "sets com_drawThreadSpeeds to 2 if a frame takes longer than this time in milliseconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_hitchThresholdMS__);
}


// ========================================================================
// `dynamic initializer for 'com_drawThreadSpeeds''
// EA  : 0x83338808
// RVA : 0x01338808
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_drawThreadSpeeds__()
{
  idCVar::idCVar(
    this: &com_drawThreadSpeeds,
    name: "com_drawThreadSpeeds",
    value: "0",
    flags: 18,
    description: "1 = dynamic draw, 2 = static draw, 3 = dynamic draw until stall",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_drawThreadSpeeds__);
}


// ========================================================================
// `dynamic initializer for 'com_statsFileName''
// EA  : 0x83338870
// RVA : 0x01338870
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_statsFileName__()
{
  idCVar::idCVar(
    this: &com_statsFileName,
    name: "com_statsFile",
    value: "stats.txt",
    flags: 0,
    description: "logfile name",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_statsFileName__);
}


// ========================================================================
// `dynamic initializer for 'in_joystickRumble''
// EA  : 0x833388C8
// RVA : 0x013388C8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_joystickRumble__()
{
  idCVar::idCVar(
    this: &in_joystickRumble,
    name: "in_joystickRumble",
    value: "1",
    flags: 1,
    description: "enables joystick rumble",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_joystickRumble__);
}


// ========================================================================
// `dynamic initializer for 'com_captureFrames''
// EA  : 0x83338920
// RVA : 0x01338920
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_captureFrames__()
{
  idCVar::idCVar(
    this: &com_captureFrames,
    name: "com_captureFrames",
    value: "0",
    flags: 2,
    description: "1 to capture each frame and output it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_captureFrames__);
}


// ========================================================================
// `dynamic initializer for 'com_captureSounds''
// EA  : 0x83338978
// RVA : 0x01338978
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_captureSounds__()
{
  idCVar::idCVar(
    this: &com_captureSounds,
    name: "com_captureSounds",
    value: "0",
    flags: 2,
    description: "set to 1 to start capture, 2 while capturing, 0 when disabled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_captureSounds__);
}


// ========================================================================
// `dynamic initializer for 'com_demoPlaybackRate''
// EA  : 0x833389D0
// RVA : 0x013389D0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_demoPlaybackRate__()
{
  idCVar::idCVar(
    this: &com_demoPlaybackRate,
    name: "com_demoPlaybackRate",
    value: "0",
    flags: 2,
    description: "Rate to playback demos, 0 for realtime",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_demoPlaybackRate__);
}


// ========================================================================
// `dynamic initializer for 'com_demoPlaybackScale''
// EA  : 0x83338A28
// RVA : 0x01338A28
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_demoPlaybackScale__()
{
  idCVar::idCVar(
    this: &com_demoPlaybackScale,
    name: "com_demoPlaybackScale",
    value: "1",
    flags: 4,
    description: "Scales playback time of demos",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_demoPlaybackScale__);
}


// ========================================================================
// `dynamic initializer for 'com_demoStats''
// EA  : 0x83338A80
// RVA : 0x01338A80
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_demoStats__()
{
  idCVar::idCVar(
    this: &com_demoStats,
    name: "com_demoStats",
    value: "0",
    flags: 1,
    description: "Print stats on demo compression rates",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_demoStats__);
}


// ========================================================================
// `dynamic initializer for 'com_forceAllMapLayersToLoad''
// EA  : 0x83338AD8
// RVA : 0x01338AD8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_forceAllMapLayersToLoad__()
{
  idCVar::idCVar(
    this: &com_forceAllMapLayersToLoad,
    name: "com_forceAllMapLayersToLoad",
    value: "0",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_forceAllMapLayersToLoad__);
}


// ========================================================================
// `dynamic initializer for 'com_forceSound''
// EA  : 0x83338B30
// RVA : 0x01338B30
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_forceSound__()
{
  idCVar::idCVar(
    this: &com_forceSound,
    name: "com_forceSound",
    value: "0",
    flags: 1,
    description: "Force sound to play even if not the focused app",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_forceSound__);
}


// ========================================================================
// `dynamic initializer for 'net_drawDebugHud''
// EA  : 0x83338B88
// RVA : 0x01338B88
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_drawDebugHud__()
{
  idCVar::idCVar(
    this: &net_drawDebugHud,
    name: "net_drawDebugHud",
    value: "0",
    flags: 2,
    description: "Shows various network debug information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_drawDebugHud__);
}


// ========================================================================
// `dynamic initializer for 'com_logMetrics''
// EA  : 0x83338BE0
// RVA : 0x01338BE0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_logMetrics__()
{
  idCVar::idCVar(
    this: &com_logMetrics,
    name: "com_logMetrics",
    value: "0",
    flags: 1,
    description: "Enable logging of performance metrics (renderer, frame timing, network etc.)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_logMetrics__);
}


// ========================================================================
// `dynamic initializer for 'com_sendSnapshots''
// EA  : 0x83338C38
// RVA : 0x01338C38
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_sendSnapshots__()
{
  idCVar::idCVar(
    this: &com_sendSnapshots,
    name: "com_sendSnapshots",
    value: "1",
    flags: 1,
    description: "For debugging, will not send snapshots when false.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_sendSnapshots__);
}


// ========================================================================
// `dynamic initializer for 'com_debugSnapShotInterpolation''
// EA  : 0x83338C90
// RVA : 0x01338C90
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_debugSnapShotInterpolation__()
{
  idCVar::idCVar(
    this: &com_debugSnapShotInterpolation,
    name: "com_debugSnapShotInterpolation",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_debugSnapShotInterpolation__);
}


// ========================================================================
// `dynamic initializer for 'com_forceLatestSnap''
// EA  : 0x83338CE8
// RVA : 0x01338CE8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_forceLatestSnap__()
{
  idCVar::idCVar(
    this: &com_forceLatestSnap,
    name: "com_forceLatestSnap",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_forceLatestSnap__);
}


// ========================================================================
// `dynamic initializer for 'com_sleepGame''
// EA  : 0x83338D40
// RVA : 0x01338D40
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_sleepGame__()
{
  idCVar::idCVar(
    this: &com_sleepGame,
    name: "com_sleepGame",
    value: "0",
    flags: 2,
    description: "sleep for this many milliseconds between frames to simulate long game frames.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_sleepGame__);
}


// ========================================================================
// `dynamic initializer for 'com_disableGameScripts''
// EA  : 0x83338D98
// RVA : 0x01338D98
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_disableGameScripts__()
{
  idCVar::idCVar(
    this: &com_disableGameScripts,
    name: "com_disableGameScripts",
    value: "0",
    flags: 1,
    description: "disable script loading",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_disableGameScripts__);
}


// ========================================================================
// `dynamic initializer for 'net_snapRate''
// EA  : 0x83338DF0
// RVA : 0x01338DF0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapRate__()
{
  idCVar::idCVar(
    this: &net_snapRate,
    name: "net_snapRate",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapRate__);
}


// ========================================================================
// `dynamic initializer for 'net_ForceWriteSnap''
// EA  : 0x83338E48
// RVA : 0x01338E48
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ForceWriteSnap__()
{
  idCVar::idCVar(
    this: &net_ForceWriteSnap,
    name: "net_ForceWriteSnap",
    value: "0",
    flags: 1,
    description: "If true, server will create snapshots even if there are no peers (for debugging)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ForceWriteSnap__);
}


// ========================================================================
// `dynamic initializer for 'net_ForceWriteSnapAckMS''
// EA  : 0x83338EA0
// RVA : 0x01338EA0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ForceWriteSnapAckMS__()
{
  idCVar::idCVar(
    this: &net_ForceWriteSnapAckMS,
    name: "net_ForceWriteSnapAckMS",
    value: "0",
    flags: 2,
    description: "Ack net_ForceWriteSnap snapshots every x MS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ForceWriteSnapAckMS__);
}


// ========================================================================
// `dynamic initializer for 'net_ForceWriteSnapAckSEQ''
// EA  : 0x83338EF8
// RVA : 0x01338EF8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ForceWriteSnapAckSEQ__()
{
  idCVar::idCVar(
    this: &net_ForceWriteSnapAckSEQ,
    name: "net_ForceWriteSnapAckSEQ",
    value: "0",
    flags: 2,
    description: "Ack net_ForceWriteSnap snapshots this many seqs behind latest",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ForceWriteSnapAckSEQ__);
}


// ========================================================================
// `dynamic initializer for 'plog_mode''
// EA  : 0x83338F50
// RVA : 0x01338F50
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__plog_mode__()
{
  idCVar::idCVar(
    this: &plog_mode,
    name: "plog_mode",
    value: "0",
    flags: 2,
    description: "global performance log mode, 0 = list, 1 = call graph",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__plog_mode__);
}


// ========================================================================
// `dynamic initializer for 'plog_threshold''
// EA  : 0x83338FA8
// RVA : 0x01338FA8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__plog_threshold__()
{
  idCVar::idCVar(
    this: &plog_threshold,
    name: "plog_threshold",
    value: "0",
    flags: 4,
    description: "only shows the global log if the total time exceeds this threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__plog_threshold__);
}


// ========================================================================
// `dynamic initializer for 'com_recordGuiTrace''
// EA  : 0x83339000
// RVA : 0x01339000
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_recordGuiTrace__()
{
  idCVar::idCVar(
    this: &com_recordGuiTrace,
    name: "com_recordGuiTrace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_recordGuiTrace__);
}


// ========================================================================
// `dynamic initializer for 'com_recordFrameTrace''
// EA  : 0x83339058
// RVA : 0x01339058
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_recordFrameTrace__()
{
  idCVar::idCVar(
    this: &com_recordFrameTrace,
    name: "com_recordFrameTrace",
    value: "0",
    flags: 1,
    description: "Record a full frame cpu trace on the main thread",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_recordFrameTrace__);
}


// ========================================================================
// `dynamic initializer for 'framesPerSec''
// EA  : 0x833390B8
// RVA : 0x013390B8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__framesPerSec__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "frames per second");
  idStr::idStr(this: &v0, text: "framesPerSec");
  idGaugeMetric::idGaugeMetric(this: &framesPerSec, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__framesPerSec__);
}


// ========================================================================
// __unwind$229585
// EA  : 0x83339130
// RVA : 0x01339130
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229585()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229586
// EA  : 0x83339158
// RVA : 0x01339158
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeSpinning''
// EA  : 0x83339188
// RVA : 0x01339188
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeSpinning__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "main thread time spent waiting, when com_syncToTime is set (PC only), in microseconds");
  idStr::idStr(this: &v0, text: "timeSpinning");
  idGaugeMetric::idGaugeMetric(this: &timeSpinning, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeSpinning__);
}


// ========================================================================
// __unwind$229617_0
// EA  : 0x83339200
// RVA : 0x01339200
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229617_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229618
// EA  : 0x83339228
// RVA : 0x01339228
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229618()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeCPUFrameTime''
// EA  : 0x83339258
// RVA : 0x01339258
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeCPUFrameTime__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "CPU time spent this frame, in microseconds");
  idStr::idStr(this: &v0, text: "timeCPUFrameTime");
  idGaugeMetric::idGaugeMetric(this: &timeCPUFrameTime, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeCPUFrameTime__);
}


// ========================================================================
// __unwind$229649
// EA  : 0x833392D0
// RVA : 0x013392D0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229649()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229650
// EA  : 0x833392F8
// RVA : 0x013392F8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeGameFrame''
// EA  : 0x83339328
// RVA : 0x01339328
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeGameFrame__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "time spent advancing game frames, in microseconds");
  idStr::idStr(this: &v0, text: "timeGameFrame");
  idGaugeMetric::idGaugeMetric(this: &timeGameFrame, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeGameFrame__);
}


// ========================================================================
// __unwind$229681
// EA  : 0x833393A0
// RVA : 0x013393A0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229681()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229682
// EA  : 0x833393C8
// RVA : 0x013393C8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229682()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeRenderThreadSync''
// EA  : 0x833393F8
// RVA : 0x013393F8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeRenderThreadSync__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "time spent waiting for the renderer thread, in microseconds");
  idStr::idStr(this: &v0, text: "timeRenderThreadSync");
  idGaugeMetric::idGaugeMetric(this: &timeRenderThreadSync, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeRenderThreadSync__);
}


// ========================================================================
// __unwind$229713
// EA  : 0x83339470
// RVA : 0x01339470
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229714
// EA  : 0x83339498
// RVA : 0x01339498
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeRenderFrame''
// EA  : 0x833394C8
// RVA : 0x013394C8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeRenderFrame__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "time spent in the renderer thread generating command buffers");
  idStr::idStr(this: &v0, text: "timeRenderFrame");
  idGaugeMetric::idGaugeMetric(this: &timeRenderFrame, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeRenderFrame__);
}


// ========================================================================
// __unwind$229745
// EA  : 0x83339540
// RVA : 0x01339540
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229745()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229746
// EA  : 0x83339568
// RVA : 0x01339568
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229746()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'timeGPUFrameTime''
// EA  : 0x83339598
// RVA : 0x01339598
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timeGPUFrameTime__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "time spent by the GPU rendering the scene");
  idStr::idStr(this: &v0, text: "timeGPUFrameTime");
  idGaugeMetric::idGaugeMetric(this: &timeGPUFrameTime, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timeGPUFrameTime__);
}


// ========================================================================
// __unwind$229777
// EA  : 0x83339610
// RVA : 0x01339610
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229777()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229778
// EA  : 0x83339638
// RVA : 0x01339638
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229778()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'countNumGameFrames''
// EA  : 0x83339668
// RVA : 0x01339668
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__countNumGameFrames__()
{
  idStr v0; // [sp+60h] [-50h] BYREF
  idStr v1; // [sp+80h] [-30h] BYREF

  idStr::idStr(this: &v1, text: "number of game frames executed this frame");
  idStr::idStr(this: &v0, text: "countNumGameFrames");
  idGaugeMetric::idGaugeMetric(this: &countNumGameFrames, _shortName: &v0, _description: &v1);
  idStr::FreeData(this: &v0);
  idStr::FreeData(this: &v1);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__countNumGameFrames__);
}


// ========================================================================
// __unwind$229809
// EA  : 0x833396E0
// RVA : 0x013396E0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229809()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$229810
// EA  : 0x83339708
// RVA : 0x01339708
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void _unwind_229810()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'net_effectiveSnapRateEnable''
// EA  : 0x83339730
// RVA : 0x01339730
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_effectiveSnapRateEnable__()
{
  idCVar::idCVar(
    this: &net_effectiveSnapRateEnable,
    name: "net_effectiveSnapRateEnable",
    value: "0",
    flags: 1,
    description: "Dynamically adjust client snaprate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_effectiveSnapRateEnable__);
}


// ========================================================================
// `dynamic initializer for 'net_effectiveSnapRateDebug''
// EA  : 0x83339788
// RVA : 0x01339788
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_effectiveSnapRateDebug__()
{
  idCVar::idCVar(
    this: &net_effectiveSnapRateDebug,
    name: "net_effectiveSnapRateDebug",
    value: "0",
    flags: 1,
    description: "Debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_effectiveSnapRateDebug__);
}


// ========================================================================
// `dynamic initializer for 'net_minBufferedSnapPCT_Static''
// EA  : 0x833397E0
// RVA : 0x013397E0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_minBufferedSnapPCT_Static__()
{
  idCVar::idCVar(
    this: &net_minBufferedSnapPCT_Static,
    name: "net_minBufferedSnapPCT_Static",
    value: "0.5",
    flags: 4,
    description: "Min amount of snapshot buffer time we want need to buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_minBufferedSnapPCT_Static__);
}


// ========================================================================
// `dynamic initializer for 'net_maxBufferedSnapMS''
// EA  : 0x83339838
// RVA : 0x01339838
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxBufferedSnapMS__()
{
  idCVar::idCVar(
    this: &net_maxBufferedSnapMS,
    name: "net_maxBufferedSnapMS",
    value: "336",
    flags: 2,
    description: "Max time to allow for interpolation cushion",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxBufferedSnapMS__);
}


// ========================================================================
// `dynamic initializer for 'net_minBufferedSnapWinPCT_Static''
// EA  : 0x83339890
// RVA : 0x01339890
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_minBufferedSnapWinPCT_Static__()
{
  idCVar::idCVar(
    this: &net_minBufferedSnapWinPCT_Static,
    name: "net_minBufferedSnapWinPCT_Static",
    value: "1.0",
    flags: 4,
    description: "Min amount of snapshot buffer time we want need to buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_minBufferedSnapWinPCT_Static__);
}


// ========================================================================
// `dynamic initializer for 'net_interpolationCatchupRate''
// EA  : 0x833398E8
// RVA : 0x013398E8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_interpolationCatchupRate__()
{
  idCVar::idCVar(
    this: &net_interpolationCatchupRate,
    name: "net_interpolationCatchupRate",
    value: "1.3",
    flags: 4,
    description: "Scale interpolationg rate when we fall behind",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_interpolationCatchupRate__);
}


// ========================================================================
// `dynamic initializer for 'net_interpolationFallbackRate''
// EA  : 0x83339940
// RVA : 0x01339940
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_interpolationFallbackRate__()
{
  idCVar::idCVar(
    this: &net_interpolationFallbackRate,
    name: "net_interpolationFallbackRate",
    value: "0.95",
    flags: 4,
    description: "Scale interpolationg rate when we fall behind",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_interpolationFallbackRate__);
}


// ========================================================================
// `dynamic initializer for 'net_interpolationBaseRate''
// EA  : 0x83339998
// RVA : 0x01339998
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_interpolationBaseRate__()
{
  idCVar::idCVar(
    this: &net_interpolationBaseRate,
    name: "net_interpolationBaseRate",
    value: "1.0",
    flags: 4,
    description: "Scale interpolationg rate when we fall behind",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_interpolationBaseRate__);
}


// ========================================================================
// `dynamic initializer for 'net_optimalDynamic''
// EA  : 0x833399F0
// RVA : 0x013399F0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_optimalDynamic__()
{
  idCVar::idCVar(
    this: &net_optimalDynamic,
    name: "net_optimalDynamic",
    value: "1",
    flags: 1,
    description: "How fast to add to our optimal time buffer when we are playing snapshots faster than server is feeding them to us",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_optimalDynamic__);
}


// ========================================================================
// `dynamic initializer for 'net_optimalSnapWindow''
// EA  : 0x83339A48
// RVA : 0x01339A48
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_optimalSnapWindow__()
{
  idCVar::idCVar(
    this: &net_optimalSnapWindow,
    name: "net_optimalSnapWindow",
    value: "112",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_optimalSnapWindow__);
}


// ========================================================================
// `dynamic initializer for 'net_optimalSnapTime''
// EA  : 0x83339AA0
// RVA : 0x01339AA0
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_optimalSnapTime__()
{
  idCVar::idCVar(
    this: &net_optimalSnapTime,
    name: "net_optimalSnapTime",
    value: "112",
    flags: 4,
    description: "How fast to add to our optimal time buffer when we are playing snapshots faster than server is feeding them to us",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_optimalSnapTime__);
}


// ========================================================================
// `dynamic initializer for 'net_interpolationSlowdownStart''
// EA  : 0x83339AF8
// RVA : 0x01339AF8
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_interpolationSlowdownStart__()
{
  idCVar::idCVar(
    this: &net_interpolationSlowdownStart,
    name: "net_interpolationSlowdownStart",
    value: "0.5",
    flags: 4,
    description: "Scale interpolation rate when we fall behind",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_interpolationSlowdownStart__);
}


// ========================================================================
// `dynamic initializer for 'net_maxExtrapolationInMS''
// EA  : 0x83339B50
// RVA : 0x01339B50
// PDB : w:\tech5\engine\framework\common_frame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxExtrapolationInMS__()
{
  idCVar::idCVar(
    this: &net_maxExtrapolationInMS,
    name: "net_maxExtrapolationInMS",
    value: "0",
    flags: 2,
    description: "Max time in MS that extrapolation is allowed to occur.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxExtrapolationInMS__);
}

