
// ========================================================================
// ?SendResources@idLobby@@QAA_NH@Z
// EA  : 0x829B45A0
// RVA : 0x009B45A0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::SendResources(
        idLobby *this,
        int p,
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
        int a27)
{
  __int64 v27; // r4
  int v28; // r31
  int v29; // r28
  int NumNetworkResources; // r29
  int v32; // r30
  int v33; // r5
  int v34; // r11
  int v35; // r3
  int v36; // r11
  int v37; // r29
  int v38; // r6

  v27 = ((__int64 (*)(void))RtlCheckStack12)();
  v28 = HIDWORD(v27);
  v29 = v27;
  NumNetworkResources = idResourceList::GetNumNetworkResources();
  if ( (unsigned __int8)idResourceList::ShouldPerformNetworkResourceExchange() != 0 )
  {
    v32 = 472 * v29;
    v33 = *(_DWORD *)(*(_DWORD *)(v28 + 4184) + 472 * v29 + 96);
    if ( NumNetworkResources == v33 )
    {
      return 0;
    }
    else
    {
      if ( NumNetworkResources < v33 )
        idLib::Warning(
          fmt: "Peer %d has %d network resources, more than the server has to send %d",
          v29,
          v33,
          NumNetworkResources);
      if ( *(_DWORD *)(*(_DWORD *)(v28 + 4184) + 472 * v29) == 2
        && idLobby::CanSendMoreData(this: (idLobby *)v28, p: v29) )
      {
        v34 = *(_DWORD *)(*(_DWORD *)(v28 + 4184) + v32 + 100);
        if ( *(_DWORD *)(v34 + 25324) - *(_DWORD *)(v34 + 25332) <= 0 )
        {
          v35 = Sys_Milliseconds();
          v36 = *(_DWORD *)(v28 + 4184) + v32;
          if ( v35 - *(_DWORD *)(v36 + 244) >= 500 )
          {
            *(_DWORD *)(v36 + 244) = v35;
            STACK[0x112B0] = (unsigned int)&STACK[0xE290];
            idLZWCompressor::Start(
              this: (idLZWCompressor *)&STACK[0x112B0],
              data_: (unsigned __int8 *)&a27,
              maxSize_: 1189,
              append: false);
            v37 = common->NetWriteResources(
                    this: common,
                    a2: (idLZWCompressor *)&STACK[0x112B0],
                    a3: *(_DWORD *)(*(_DWORD *)(v28 + 4184) + v32 + 96),
                    a4: 1061,
                    a5: true);
            idLZWCompressor::End(this: (idLZWCompressor *)&STACK[0x112B0]);
            idLobby::ProcessOutgoingMsg(
              this: (idLobby *)v28,
              p: v29,
              data: (unsigned int)&a27,
              size: *(_DWORD *)(STACK[0x112B0] + 12316),
              isOOB: true,
              userData: 4);
            if ( net_verboseResource.valueInteger != 0 )
            {
              v38 = *(_DWORD *)(*(_DWORD *)(v28 + 4184) + v32 + 96);
              idLib::Printf(fmt: "NET: Send peer[%d] %d resources: %d - %d \n", v29, v37, v38, v38 + v37);
            }
          }
        }
      }
      return 1;
    }
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(v28 + 4184) + 472 * v29 + 96) = NumNetworkResources;
    return 0;
  }
}


// ========================================================================
// ?SubmitPendingSnap@idLobby@@QAA_NH@Z
// EA  : 0x829B4768
// RVA : 0x009B4768
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::SubmitPendingSnap(idLobby *this, int p)
{
  __int64 v3; // r28
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v9; // r10
  int v10; // r31
  int v11; // r11
  int v12; // r30
  idParallelJobList *v13; // r30
  idSessionCallbacks *sessionCB; // r29
  lzwCompressionData_t *v15; // r25
  int v16; // r26
  unsigned __int8 *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  va *v20; // r3
  int v21; // [sp+8h] [-1088h]
  int v22; // [sp+8h] [-1088h]
  int v23; // [sp+Ch] [-1084h]
  int v24; // [sp+Ch] [-1084h]
  int v25; // [sp+10h] [-1080h]
  int v26; // [sp+10h] [-1080h]
  int v27; // [sp+14h] [-107Ch]
  int v28; // [sp+14h] [-107Ch]
  int v29; // [sp+18h] [-1078h]
  int v30; // [sp+18h] [-1078h]
  int v31; // [sp+1Ch] [-1074h]
  int v32; // [sp+1Ch] [-1074h]
  int v33; // [sp+20h] [-1070h]
  int v34; // [sp+24h] [-106Ch]
  int v35; // [sp+28h] [-1068h]
  int v36; // [sp+2Ch] [-1064h]
  int v37; // [sp+30h] [-1060h]
  int v38; // [sp+34h] [-105Ch]
  int v39; // [sp+38h] [-1058h]
  int v40; // [sp+3Ch] [-1054h]
  int v41; // [sp+40h] [-1050h]
  int v42; // [sp+44h] [-104Ch]
  int v43; // [sp+48h] [-1048h]
  int v44; // [sp+4Ch] [-1044h]
  va v45; // [sp+50h] [-1040h] BYREF

  HIDWORD(v3) = p;
  if ( session->GetState(this: session) != INGAME )
    return 0;
  v9 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
  v10 = v9 + 472 * HIDWORD(v3);
  if ( *(_DWORD *)v10 != 2 )
    return 0;
  if ( (unsigned __int8)idLobby::SendResources(
                          this,
                          p: SHIDWORD(v3),
                          a3: v7,
                          a4: v6,
                          a5: v5,
                          a6: v4,
                          a7: 2,
                          a8: v9,
                          a9: v21,
                          a10: v23,
                          a11: v25,
                          a12: v27,
                          a13: v29,
                          a14: v31,
                          a15: v33,
                          a16: v34,
                          a17: v35,
                          a18: v36,
                          a19: v37,
                          a20: v38,
                          a21: v39,
                          a22: v40,
                          a23: v41,
                          a24: v42,
                          a25: v43,
                          a26: v44,
                          a27: *(int *)v45.buffer) != 0 )
    return 0;
  if ( *(_BYTE *)(v10 + 4) == 0 )
    return 0;
  v11 = *(_DWORD *)(v10 + 104);
  if ( v11 == 0 )
    return 0;
  if ( *(_BYTE *)(v11 + 66696) == 0 )
    return 0;
  v12 = Sys_Milliseconds();
  LODWORD(v3) = v12 - *(_DWORD *)(v10 + 264);
  if ( (int)v3 < session->GetTitleStorageInt_2(
                   this: session,
                   a2: "net_snap_redundant_resend_in_ms",
                   a3: net_snap_redundant_resend_in_ms.valueInteger)
    && (unsigned __int8)idSnapshotProcessor::IsBusyConfirmingPartialSnap(this: *(idSnapshotProcessor **)(v10 + 104)) != 0 )
  {
    return 0;
  }
  *(_DWORD *)(v10 + 264) = v12;
  if ( net_disableSnapJob.valueInteger != 0 )
    v13 = nullptr;
  else
    v13 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB);
  sessionCB = this->sessionCB;
  v15 = sessionCB->GetLZWData(this: sessionCB);
  v16 = sessionCB->GetObjMemorySize(this: sessionCB);
  v17 = sessionCB->GetObjMemory(this: sessionCB);
  idSnapshotProcessor::SubmitPendingSnap(
    this: *(idSnapshotProcessor **)(v10 + 104),
    visIndex: HIDWORD(v3) + 1,
    objMemory: v17,
    objMemorySize: v16,
    lzwData: v15,
    snapshotJobList: v13);
  if ( net_verboseSnapshot.valueInteger >= 2 )
  {
    v20 = va::va(
            this: &v45,
            fmt: "  Submitted snapshot to jobList for peer %d. Since last jobsub: %d\n",
            a3: v3,
            a4: v19,
            a5: v18,
            a6: v22,
            a7: v24,
            a8: v26,
            a9: v28,
            a10: v30,
            a11: v32);
    idLib::Printf(fmt: v20->buffer);
  }
  return 1;
}


// ========================================================================
// ?ApplySnapshotDeltaInternal@idLobby@@QAA_NHH@Z
// EA  : 0x829B4940
// RVA : 0x009B4940
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::ApplySnapshotDeltaInternal(idLobby *this, int p, int snapshotNumber)
{
  char v7; // r11
  int v8; // r31
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  int v12; // r4
  int v13; // r30

  if ( session->GetState(this: session) != INGAME )
    return 0;
  if ( p < 0 || (v7 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v7 = 0;
  if ( v7 == 0 )
    return 0;
  v8 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
  if ( *(_DWORD *)v8 != 2 || *(_DWORD *)(v8 + 104) == 0 )
    return 0;
  HIDWORD(v9) = this->IsHost(this);
  v12 = p + 1;
  if ( HIDWORD(v9) == 0 )
    v12 = 0;
  HIDWORD(v11) = snapshotNumber;
  v13 = idSnapshotProcessor::ApplySnapshotDelta(
          this: *(idSnapshotProcessor **)(v8 + 104),
          visIndex: v12,
          snapshotNumber: v11,
          a4: v10,
          a5: v9);
  if ( (_BYTE)v13 != 0 && this->IsHost(this) != 0 && *(_BYTE *)(*(_DWORD *)(v8 + 104) + 66696) != 0 )
  {
    *(_BYTE *)(v8 + 260) = 1;
    if ( net_verboseSnapshot.valueInteger > 0 )
      idLib::Printf(fmt: "NET: Sent more unsent snapshot data to peer %d for snapshot %d\n", p, snapshotNumber);
  }
  return v13;
}


// ========================================================================
// ?AllPeersHaveBaseState@idLobby@@QAA_NXZ
// EA  : 0x829B4A88
// RVA : 0x009B4A88
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::AllPeersHaveBaseState(idLobby *this)
{
  int v3; // r7
  int v4; // r9
  int v5; // r8
  int i; // r11
  int v7; // r10

  if ( session->GetState(this: session) != INGAME )
    return 0;
  v3 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    for ( i = 0; ; i += 472 )
    {
      if ( *(_DWORD *)(i + v5) == 2 )
      {
        v7 = *(_DWORD *)(i + v5 + 104);
        if ( v7 == 0 || *(int *)(v7 + 8) < 42 )
          break;
      }
      if ( ++v4 >= v3 )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?ThrottleSnapsForXSeconds@idLobby@@QAAXHH_N@Z
// EA  : 0x829B4B40
// RVA : 0x009B4B40
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::ThrottleSnapsForXSeconds(idLobby *this, int p, int seconds, bool recoverPing)
{
  int v4; // r31
  int v8; // r28

  v4 = 472 * p;
  if ( *(_DWORD *)(472 * p + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 436) == 0 )
  {
    idLib::Printf(fmt: "Throttling peer %i for %i seconds...\n", p, seconds);
    v8 = v4 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    *(_DWORD *)(v8 + 436) = Sys_Milliseconds() + 1000 * seconds;
    if ( recoverPing )
      *(_DWORD *)(v4 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 440) = *(_DWORD *)(v4 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 256);
    else
      *(_DWORD *)(v4 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 440) = 0;
  }
}


// ========================================================================
// ?AllPeersHaveStaleSnapObj@idLobby@@UAA_NH@Z
// EA  : 0x829B4BD8
// RVA : 0x009B4BD8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::AllPeersHaveStaleSnapObj(idLobby *this, int objId)
{
  int v5; // r29
  int i; // r31
  _DWORD *v7; // r11
  int v8; // r11
  idSnapShot::objectState_t *ObjectByID; // r3

  if ( session->GetState(this: session) != INGAME )
    return 0;
  v5 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    for ( i = 0; ; i += 472 )
    {
      v7 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i);
      if ( *v7 == 2 )
      {
        v8 = v7[26];
        if ( v8 != 0 )
        {
          ObjectByID = idSnapShot::FindObjectByID(this: (idSnapShot *)(v8 + 12), objectNum: objId);
          if ( ObjectByID == nullptr || !ObjectByID->stale )
            break;
        }
      }
      if ( ++v5 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?AllPeersHaveExpectedSnapObj@idLobby@@UAA_NH@Z
// EA  : 0x829B4C90
// RVA : 0x009B4C90
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::AllPeersHaveExpectedSnapObj(idLobby *this, int objId)
{
  int v5; // r29
  int i; // r31
  _DWORD *v7; // r11
  int v8; // r11
  idSnapShot::objectState_t *ObjectByID; // r3
  int expectedSequence; // r11

  if ( session->GetState(this: session) != INGAME )
    return 0;
  v5 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    for ( i = 0; ; i += 472 )
    {
      v7 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i);
      if ( *v7 == 2 )
      {
        v8 = v7[26];
        if ( v8 != 0 )
        {
          ObjectByID = idSnapShot::FindObjectByID(this: (idSnapShot *)(v8 + 12), objectNum: objId);
          if ( ObjectByID == nullptr )
            break;
          expectedSequence = ObjectByID->expectedSequence;
          if ( expectedSequence == -2
            || expectedSequence > 0
            && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i + 104) + 8) <= expectedSequence )
          {
            break;
          }
        }
      }
      if ( ++v5 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?RefreshSnapObj@idLobby@@UAAXH@Z
// EA  : 0x829B4D68
// RVA : 0x009B4D68
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::RefreshSnapObj(idLobby *this, int objId)
{
  int v4; // r29
  int v5; // r31
  _DWORD *v6; // r11
  int v7; // r11
  idSnapShot::objectState_t *ObjectByID; // r3

  if ( session->GetState(this: session) == INGAME )
  {
    v4 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
    {
      v5 = 0;
      do
      {
        v6 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5);
        if ( *v6 == 2 )
        {
          v7 = v6[26];
          if ( v7 != 0 )
          {
            ObjectByID = idSnapShot::FindObjectByID(this: (idSnapShot *)(v7 + 12), objectNum: objId);
            if ( ObjectByID != nullptr )
              ObjectByID->expectedSequence = -2;
          }
        }
        ++v4;
        v5 += 472;
      }
      while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
}


// ========================================================================
// ?MarkSnapObjDeleted@idLobby@@UAAXH@Z
// EA  : 0x829B4E08
// RVA : 0x009B4E08
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::MarkSnapObjDeleted(idLobby *this, int objId)
{
  int v4; // r29
  int v5; // r31
  _DWORD *v6; // r11
  int v7; // r11
  idSnapShot::objectState_t *ObjectByID; // r3

  if ( session->GetState(this: session) == INGAME )
  {
    v4 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
    {
      v5 = 0;
      do
      {
        v6 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5);
        if ( *v6 == 2 )
        {
          v7 = v6[26];
          if ( v7 != 0 )
          {
            ObjectByID = idSnapShot::FindObjectByID(this: (idSnapShot *)(v7 + 12), objectNum: objId);
            if ( ObjectByID != nullptr )
              ObjectByID->deleted = true;
          }
        }
        ++v4;
        v5 += 472;
      }
      while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
    }
  }
}


// ========================================================================
// ?ResetBandwidthStats@idLobby@@QAAXXZ
// EA  : 0x829B4EA8
// RVA : 0x009B4EA8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::ResetBandwidthStats(idLobby *this)
{
  int v1; // r11
  int v2; // r9
  int v3; // r11

  v1 = *(_DWORD *)this->userPool.staticList[5].gamertag;
  v2 = 0;
  this->lastSnapBspHistoryUpdateSequence = -1;
  if ( v1 > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      *(float *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 424) = -1.0;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 276) = 0;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 448) = *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 256);
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 436) = 0;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 440) = 0;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 444) = 0;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v3 + 448) = 0;
      v3 += 472;
    }
    while ( v2 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
}


// ========================================================================
// ?DetectSaturation@idLobby@@QAAXH@Z
// EA  : 0x829B4F40
// RVA : 0x009B4F40
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::DetectSaturation(idLobby *this, int p)
{
  _DWORD *v4; // r31
  double v5; // fp31
  int v6; // r30
  int v7; // r29
  int v8; // r3
  __int128 v9; // r7

  v4 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p);
  if ( *v4 == 2 )
  {
    v5 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
           a1: session,
           a2: "net_pingIncPercentBeforeRecover",
           a3: net_pingIncPercentBeforeRecover.valueFloat);
    v6 = session->GetTitleStorageInt_2(this: session, a2: "net_min_ping_in_ms", a3: net_min_ping_in_ms.valueInteger);
    v7 = session->GetTitleStorageInt_2(
           this: session,
           a2: "net_maxFailedPingRecoveries",
           a3: net_maxFailedPingRecoveries.valueInteger);
    v8 = session->GetTitleStorageInt_2(
           this: session,
           a2: "net_pingRecoveryThrottleTimeInSeconds",
           a3: net_pingRecoveryThrottleTimeInSeconds.valueInteger);
    DWORD1(v9) = v8;
    LODWORD(v9) = v4[64];
    DWORD2(v9) = v4[112];
    if ( (float)(__int64)v9 > (double)(float)((float)*(__int64 *)((char *)&v9 + 4) * (float)v5)
      && v4[64] > v6
      && v4[111] < v7 )
    {
      idLobby::ThrottleSnapsForXSeconds(this, p, seconds: v8, recoverPing: true);
    }
  }
}


// ========================================================================
// ?AddSnapObjTemplate@idLobby@@UAAXHAAVidBitMsg@@@Z
// EA  : 0x829B5098
// RVA : 0x009B5098
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::AddSnapObjTemplate(idLobby *this, int objID, idBitMsg *msg)
{
  idSnapShot *v4; // r3
  int v7; // r29
  int v8; // r31
  _DWORD *v9; // r11
  idSnapshotProcessor *v10; // r3

  v4 = *(idSnapShot **)&this->parms.debugJobName.buffer[28];
  if ( v4 != nullptr )
    idSnapShot::ApplyToExistingState(this: v4, objId: objID, msg);
  v7 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    v8 = 0;
    do
    {
      v9 = (_DWORD *)(v8 + *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType);
      if ( *v9 == 2 )
      {
        v10 = (idSnapshotProcessor *)v9[26];
        if ( v10 != nullptr )
          idSnapshotProcessor::AddSnapObjTemplate(this: v10, objID, msg);
      }
      ++v7;
      v8 += 472;
    }
    while ( v7 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
}


// ========================================================================
// ?VerifySnapshotInitialState@idLobby@@QAAXH@Z
// EA  : 0x829B5128
// RVA : 0x009B5128
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::VerifySnapshotInitialState(idLobby *this, int peerNum)
{
  int v4; // r27
  int i; // r30
  _DWORD *v6; // r11
  idSnapshotProcessor *v7; // r3
  idSnapshotProcessor *v8; // r10
  int v9; // r10
  int v10; // r11

  v4 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag <= 0 )
    return;
  for ( i = 0; ; i += 472 )
  {
    if ( peerNum != -1 && v4 != peerNum )
      goto LABEL_15;
    v6 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i);
    if ( *v6 != 2 )
      goto LABEL_15;
    if ( v6[26] == 0 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v7 = (idSnapshotProcessor *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x10530u,
                                    tag: TAG_NETWORKING,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idSnapshotProcessor::idSnapshotProcessor(this: v7);
      else
        v8 = nullptr;
      *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i + 104) = v8;
      idMem::PopHeap(this: &mem);
    }
    v9 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
    if ( *(_BYTE *)(i + v9 + 260) != 0 )
      break;
    v10 = *(_DWORD *)(i + v9 + 104);
    if ( *(_BYTE *)(v10 + 66696) != 0 )
      goto _LN61_2;
    if ( *(_DWORD *)v10 != 42 )
      goto _LN62_4;
    if ( *(_DWORD *)(v10 + 4) != -1 )
      goto _LN63_6;
LABEL_15:
    if ( ++v4 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
      return;
  }
  idLib::Error(fmt: "Invalid needToSubmitPendingSnap state\n");
_LN61_2:
  idLib::Error(fmt: "Invalid HasPendingSnap state\n");
_LN62_4:
  idLib::Error(fmt: "Invalid INITIAL_SNAP_SEQUENCE state %d for peer %d \n", **(_DWORD **)(472 * v4 + v9 + 104), v4);
_LN63_6:
  idLib::Error(fmt: "Invalid GetBaseSequence state\n");
  _LN64_3();
}


// ========================================================================
// $LN64_3
// EA  : 0x829B5298
// RVA : 0x009B5298
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void _LN64_3()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ?SendCompletedPendingSnap@idLobby@@QAAXH@Z
// EA  : 0x829B52C8
// RVA : 0x009B52C8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::SendCompletedPendingSnap(idLobby *this, int p)
{
  int v4; // r3
  int v5; // r31
  int v6; // r25
  idSnapshotProcessor *v7; // r3
  int jobMemory; // r7
  int v9; // r6
  int PendingSnapDelta; // r26
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int v14; // r11
  int v15; // r10
  int v16; // r9
  int v17; // r4
  int v18; // r11
  int v19; // r27
  int v20; // r23
  int v21; // r11
  int v22; // r11
  int v23; // r3
  int v24; // r29
  int v25; // r29
  int v26; // r30
  int v27; // r3
  __int64 v28; // r11
  _DWORD *v29; // r11
  __int64 v30; // r8
  __int64 v31; // r6
  va *v32; // r3
  int v33; // r30
  const char *PeerName; // r3
  int *v35; // r11
  int v36; // r11
  int v37; // [sp+8h] [-2FE8h]
  int v38; // [sp+8h] [-2FE8h]
  int v39; // [sp+Ch] [-2FE4h]
  int v40; // [sp+Ch] [-2FE4h]
  int v41; // [sp+10h] [-2FE0h]
  int v42; // [sp+10h] [-2FE0h]
  int v43; // [sp+14h] [-2FDCh]
  int v44; // [sp+14h] [-2FDCh]
  int v45; // [sp+18h] [-2FD8h]
  int v46; // [sp+18h] [-2FD8h]
  int v47; // [sp+1Ch] [-2FD4h]
  int v48; // [sp+1Ch] [-2FD4h]
  int v49; // [sp+20h] [-2FD0h]
  int v50; // [sp+24h] [-2FCCh]
  int v51; // [sp+28h] [-2FC8h]
  int v52; // [sp+2Ch] [-2FC4h]
  int v53; // [sp+30h] [-2FC0h]
  int v54; // [sp+34h] [-2FBCh]
  int v55; // [sp+38h] [-2FB8h]
  int v56; // [sp+3Ch] [-2FB4h]
  int v57; // [sp+40h] [-2FB0h]
  int v58; // [sp+44h] [-2FACh]
  int v59; // [sp+48h] [-2FA8h]
  int v60; // [sp+4Ch] [-2FA4h]
  int v61; // [sp+50h] [-2FA0h]
  va v62; // [sp+60h] [-2F90h] BYREF
  unsigned __int8 v63[3984]; // [sp+1060h] [-1F90h] BYREF

  if ( session->GetState(this: session) == INGAME )
  {
    v4 = Sys_Milliseconds();
    v5 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
    v6 = v4;
    if ( *(_DWORD *)v5 == 2 )
    {
      v7 = *(idSnapshotProcessor **)(v5 + 104);
      if ( v7 != nullptr )
      {
        jobMemory = (int)v7->jobMemory;
        v9 = *(_DWORD *)(jobMemory + 214032);
        if ( v9 > 0 )
        {
          PendingSnapDelta = idSnapshotProcessor::GetPendingSnapDelta(
                               this: v7,
                               outBuffer: v63,
                               maxLength: 7872 - *(_DWORD *)(*(_DWORD *)(v5 + 100) + 8788),
                               a4: v9,
                               a5: jobMemory);
          if ( idLobby::CanSendMoreData(this, p) )
          {
            v14 = *(_DWORD *)(v5 + 100);
            v15 = *(_DWORD *)(v14 + 25324);
            v16 = *(_DWORD *)(v14 + 25332);
            if ( v15 - v16 <= 0
              && (unsigned __int8)idLobby::SendResources(
                                    this,
                                    p,
                                    a3: v13,
                                    a4: v12,
                                    a5: v11,
                                    a6: v15 - v16,
                                    a7: v16,
                                    a8: v15,
                                    a9: v37,
                                    a10: v39,
                                    a11: v41,
                                    a12: v43,
                                    a13: v45,
                                    a14: v47,
                                    a15: v49,
                                    a16: v50,
                                    a17: v51,
                                    a18: v52,
                                    a19: v53,
                                    a20: v54,
                                    a21: v55,
                                    a22: v56,
                                    a23: v57,
                                    a24: v58,
                                    a25: v59,
                                    a26: v60,
                                    a27: v61) == 0 )
            {
              v18 = *(_DWORD *)(v5 + 8);
              v19 = v6 - v18;
              v20 = v6 - *(_DWORD *)(v5 + 264);
              if ( v6 - v18 <= 0 )
                *(float *)(v5 + 12) = 0.0;
              else
                *(float *)(v5 + 12) = (float)1000.0 / (float)__SPAIR64__(&unk_82150000, v19);
              if ( net_snapshot_send_warntime.valueInteger > 0
                && v18 != 0
                && net_snapshot_send_warntime.valueInteger < v19 )
              {
                idLib::Printf(fmt: "NET: Took %d ms to send peer %d snapshot\n", v19, p);
              }
              v21 = *(_DWORD *)(v5 + 436);
              if ( v21 != 0 )
              {
                if ( v6 < v21 )
                  return;
                v22 = *(_DWORD *)(v5 + 440);
                if ( v22 != 0 )
                {
                  if ( *(_DWORD *)(v5 + 256) < v22 )
                  {
                    v23 = session->GetTitleStorageInt_2(
                            this: session,
                            a2: "net_peer_throttle_minSnapSeq",
                            a3: net_peer_throttle_minSnapSeq.valueInteger);
                    v17 = *(_DWORD *)(*(_DWORD *)(v5 + 104) + 8);
                    if ( v17 > v23 + 42 )
                    {
                      v24 = session->GetTitleStorageInt_2(
                              this: session,
                              a2: "net_peer_throttle_maxSnapRate",
                              a3: net_peer_throttle_maxSnapRate.valueInteger);
                      v25 = v24 * common->GetSnapRate(this: common);
                      v26 = common->GetSnapRate(this: common) + *(_DWORD *)(v5 + 276);
                      v27 = common->GetSnapRate(this: common);
                      if ( v26 >= v27 )
                      {
                        v27 = v25;
                        if ( v26 <= v25 )
                          v27 = v26;
                      }
                      *(_DWORD *)(v5 + 276) = v27;
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)(v5 + 444);
                  }
                }
                *(_DWORD *)(v5 + 436) = 0;
              }
              *(_DWORD *)(v5 + 8) = v6;
              LODWORD(v28) = PendingSnapDelta;
              HIDWORD(v28) = *(_DWORD *)(v5 + 100);
              idGaugeMetric::Log(this: (idGaugeMetric *)(HIDWORD(v28) + 33924), x: (float)v28, skipPush: v17);
              if ( PendingSnapDelta != 0 )
              {
                if ( PendingSnapDelta <= 0 )
                {
                  idLobby::ProcessOutgoingMsg(
                    this,
                    p,
                    data: (unsigned int)v63,
                    size: -PendingSnapDelta,
                    isOOB: false,
                    userData: 0);
                  if ( net_verboseSnapshot.valueInteger > 0 )
                  {
                    v33 = **(_DWORD **)(v5 + 104);
                    PeerName = idLobby::GetPeerName(this, peerNum: p);
                    idLib::Printf(
                      fmt: "NET: (peerNum: %d - name: %s) Resending last snapshot delta %d because his delta list filled up. S"
                      "ince JobSub: %d Since LastSend: %d Delta Size: %d\n",
                      p,
                      PeerName,
                      v33,
                      v20,
                      v19,
                      PendingSnapDelta);
                  }
                }
                else
                {
                  if ( net_verboseSnapshot.valueInteger >= 3 )
                  {
                    v29 = *(_DWORD **)(v5 + 104);
                    LODWORD(v30) = v20;
                    HIDWORD(v31) = p;
                    HIDWORD(v30) = v29[1];
                    LODWORD(v31) = *v29;
                    v32 = va::va(
                            this: &v62,
                            fmt: "NET: (peer %d) Sending snapshot %d delta'd against %d. Since JobSub: %d Since LastSend: %d. Size: %d\n",
                            a3: v31,
                            a4: v30,
                            a5: __SPAIR64__(v19, PendingSnapDelta),
                            a6: v38,
                            a7: v40,
                            a8: v42,
                            a9: v44,
                            a10: v46,
                            a11: v48);
                    idLib::Printf(fmt: v32->buffer);
                  }
                  idLobby::ProcessOutgoingMsg(
                    this,
                    p,
                    data: (unsigned int)v63,
                    size: PendingSnapDelta,
                    isOOB: false,
                    userData: 0);
                }
              }
              if ( this->IsHost(this) != 0 )
              {
                v35 = *(int **)(v5 + 104);
                if ( v35 != nullptr )
                {
                  v36 = *v35;
                  if ( v36 > 0 )
                    *(float *)(4 * (v36 % 32 + 72) + v5) = *(float *)(*(_DWORD *)(v5 + 100) + 33360);
                }
              }
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?CheckPeerThrottle@idLobby@@QAAXH@Z
// EA  : 0x829B56C0
// RVA : 0x009B56C0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::CheckPeerThrottle(idLobby *this, int p)
{
  char v4; // r11
  int v5; // r31
  int v6; // r26
  double v7; // fp1
  int v8; // r10
  int v9; // r11
  int v10; // r28
  int v11; // r11
  char v12; // r30
  int v13; // r6
  double v14; // fp30
  double v15; // fp0
  double v16; // fp31
  double v17; // fp1
  double v18; // fp1
  __int64 v19; // r6
  int v22; // r29
  int v23; // r3
  int v24; // r11
  int v25; // r29
  int v26; // r30
  int v27; // r3

  if ( session->GetState(this: session) == INGAME )
  {
    if ( p < 0 || (v4 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
      v4 = 0;
    if ( v4 != 0 )
    {
      v5 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
      if ( *(_DWORD *)v5 == 2
        && this->IsHost(this) != 0
        && session->GetTitleStorageInt_2(
             this: session,
             a2: "net_peer_throttle_mode",
             a3: net_peer_throttle_mode.valueInteger) != 0
        && *(float *)(v5 + 420) >= 0.0 )
      {
        v6 = Sys_Milliseconds();
        if ( (unsigned __int8)idLobby::AllPeersHaveBaseState(this) != 0
          && (*(_DWORD *)(v5 + 104) == 0
           || *(_DWORD *)(*(_DWORD *)(v5 + 104) + 8) > session->GetTitleStorageInt_2(
                                                         this: session,
                                                         a2: "net_peer_throttle_minSnapSeq",
                                                         a3: net_peer_throttle_minSnapSeq.valueInteger)
                                                     + 42) )
        {
          session->GetTitleStorageFloat_2(
            this: session,
            a2: "net_peer_throttle_bps_host_threshold",
            a3: net_peer_throttle_bps_host_threshold.valueFloat);
          if ( *(_DWORD *)(v5 + 104) != 0 && v7 > 0.0 )
          {
            v8 = *(_DWORD *)(v5 + 432);
            v9 = v6 - v8;
            if ( v6 - v8 >= 0 )
            {
              if ( v9 > 100 )
              {
                v10 = 100;
LABEL_19:
                if ( v8 > 0 )
                {
                  v11 = *(_DWORD *)(v5 + 416);
                  if ( v11 > 0 )
                  {
                    v12 = 0;
                    v13 = 4 * (v11 % 32 + 72);
                    v14 = *(float *)(v13 + v5);
                    if ( v14 > v7 )
                    {
                      v15 = 0.0099999998;
                      if ( v14 >= 0.0099999998 )
                      {
                        v15 = 10240.0;
                        if ( v14 <= 10240.0 )
                          v15 = *(float *)(v13 + v5);
                      }
                      v16 = (float)(*(float *)(v5 + 420) / (float)v15);
                      if ( v16 < ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                                   a1: session,
                                   a2: "net_peer_throttle_bps_peer_threshold_pct",
                                   a3: net_peer_throttle_bps_peer_threshold_pct.valueFloat) )
                      {
                        v12 = 1;
                        v17 = (float)((float)__SPAIR64__(
                                               (idSessionLocalXbox *)&sessionLocal.partyLobby.parms.layersDeactive.buffer[332],
                                               v10)
                                    + *(float *)(v5 + 428));
                        *(float *)(v5 + 428) = (float)__SPAIR64__(
                                                        (idSessionLocalXbox *)&sessionLocal.partyLobby.parms.layersDeactive.buffer[332],
                                                        v10)
                                             + *(float *)(v5 + 428);
                        if ( net_verbose.valueInteger != 0 )
                          idLib::Printf(
                            fmt: "NET: throttled... %.2f ....pct %.2f  receivedBps %.2f outgoingBps %.2f, peer %i, seq %i\n",
                            v17,
                            v16,
                            *(float *)(v5 + 420),
                            v14,
                            LODWORD(v17),
                            LODWORD(v16));
                      }
                    }
                    if ( v12 == 0 )
                    {
                      v18 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                              a1: session,
                              a2: "net_peer_throttle_bps_decay",
                              a3: net_peer_throttle_bps_decay.valueFloat);
                      LODWORD(v19) = v10;
                      _FP9 = -(float)-(float)((float)((float)v19 * (float)v18) - *(float *)(v5 + 428));
                      __asm { fsel      f8, f9, f29, f10 }
                      *(float *)(v5 + 428) = _FP8;
                    }
                    if ( *(float *)(v5 + 428) > ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                                                  a1: session,
                                                  a2: "net_peer_throttle_bps_duration",
                                                  a3: net_peer_throttle_bps_duration.valueFloat) )
                    {
                      *(float *)(v5 + 424) = session->GetTitleStorageFloat_2(
                                               this: session,
                                               a2: "net_snap_bw_test_throttle_max_scale",
                                               a3: net_snap_bw_test_throttle_max_scale.valueFloat)
                                           * *(float *)(v5 + 420);
                      v22 = session->GetTitleStorageInt_2(
                              this: session,
                              a2: "net_peer_throttle_maxSnapRate",
                              a3: net_peer_throttle_maxSnapRate.valueInteger);
                      v23 = common->GetSnapRate(this: common);
                      v24 = *(_DWORD *)(v5 + 276);
                      v25 = v22 * v23;
                      if ( v24 != 0 )
                      {
                        if ( v24 < v25 )
                        {
                          v26 = common->GetSnapRate(this: common) + *(_DWORD *)(v5 + 276);
                          v27 = common->GetSnapRate(this: common);
                          if ( v26 >= v27 )
                          {
                            v27 = v25;
                            if ( v26 <= v25 )
                              v27 = v26;
                          }
                          *(_DWORD *)(v5 + 276) = v27;
                        }
                      }
                      else
                      {
                        *(_DWORD *)(v5 + 276) = 2 * common->GetSnapRate(this: common);
                      }
                      *(float *)(v5 + 428) = 0.0;
                    }
                  }
                }
                goto LABEL_39;
              }
              v10 = v6 - v8;
              if ( v9 > 0 )
                goto LABEL_19;
            }
LABEL_39:
            *(_DWORD *)(v5 + 432) = v6;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?SendSnapshotToPeer@idLobby@@QAAXAAVidSnapShot@@H@Z
// EA  : 0x829B5B30
// RVA : 0x009B5B30
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::SendSnapshotToPeer(idLobby *this, idSnapShot *ss, int p)
{
  int v6; // r31
  int v7; // r30
  __int64 v8; // r8
  int v9; // r3
  int v10; // r29
  __int64 v11; // r6
  __int64 v12; // r10
  va *v13; // r3
  double v14; // fp0
  __int64 v15; // r8
  unsigned int v16; // r6
  char v17; // r3
  __int64 v18; // r10
  va *v19; // r3
  int v20; // r11
  va *v21; // r3
  int v22; // [sp+8h] [-1088h]
  int v23; // [sp+Ch] [-1084h]
  int v24; // [sp+10h] [-1080h]
  int v25; // [sp+14h] [-107Ch]
  int v26; // [sp+18h] [-1078h]
  int v27; // [sp+1Ch] [-1074h]
  va v28; // [sp+50h] [-1040h] BYREF

  if ( session->GetState(this: session) == INGAME )
  {
    v6 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p;
    if ( net_forceDropSnap.valueInteger != 0 )
    {
      idCVar::SetBool(this: &net_forceDropSnap, newValue: false, force: true);
      return;
    }
    if ( *(_DWORD *)(v6 + 104) != 0 && *(_DWORD *)(v6 + 32) == 0 )
    {
      v7 = Sys_Milliseconds();
      v9 = session->GetTitleStorageInt_2(
             this: session,
             a2: "net_peer_throttle_mode",
             a3: net_peer_throttle_mode.valueInteger);
      v10 = v9;
      if ( (v9 == 1 || v9 == 3)
        && (HIDWORD(v8) = *(_DWORD *)(v6 + 276), SHIDWORD(v8) > 0)
        && (LODWORD(v11) = v7 - *(_DWORD *)(v6 + 264), (int)v11 < SHIDWORD(v8) / 1000) )
      {
        LODWORD(v12) = &net_verboseSnapshot;
        if ( net_verboseSnapshot.valueInteger >= 2 )
        {
          HIDWORD(v11) = p;
          HIDWORD(v12) = SHIDWORD(v8) / 1000;
          v13 = va::va(
                  this: &v28,
                  fmt: "NET: Throttling peer %d.Skipping snapshot. Time elapsed: %d peer snap rate: %d\n",
                  a3: v11,
                  a4: v8,
                  a5: v12,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27);
          idLib::Printf(fmt: v13->buffer);
        }
      }
      else
      {
        if ( v9 != 0 )
          idLobby::DetectSaturation(this, p);
        v14 = *(float *)(v6 + 424);
        if ( v14 < 0.0 || v10 != 2 && v10 != 3 || *(float *)(*(_DWORD *)(v6 + 100) + 33360) <= v14 )
        {
          v17 = idSnapshotProcessor::TrySetPendingSnapshot(this: *(idSnapshotProcessor **)(v6 + 104), ss);
          LODWORD(v18) = &net_verboseSnapshot;
          if ( v17 != 0 )
          {
            if ( net_verboseSnapshot.valueInteger >= 2 )
            {
              v19 = va::va(
                      this: &v28,
                      fmt: "  ^8Set next pending snapshot peer %d\n",
                      a3: v16,
                      a4: v15,
                      a5: v18,
                      a6: v22,
                      a7: v23,
                      a8: v24,
                      a9: v25,
                      a10: v26,
                      a11: v27);
              idLib::Printf(fmt: v19->buffer);
            }
            ++*(_DWORD *)(v6 + 284);
            v20 = *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p + 104);
            if ( v20 != -12 )
            {
              idSnapShot::UpdateExpectedSeq(this: (idSnapShot *)(v20 + 12), newSeq: *(_DWORD *)v20);
              *(_BYTE *)(v6 + 260) = 1;
              return;
            }
          }
          else if ( net_verboseSnapshot.valueInteger >= 2 )
          {
            v21 = va::va(
                    this: &v28,
                    fmt: "  ^2FAILED Set next pending snapshot peer %d\n",
                    a3: v16,
                    a4: v15,
                    a5: v18,
                    a6: v22,
                    a7: v23,
                    a8: v24,
                    a9: v25,
                    a10: v26,
                    a11: v27);
            idLib::Printf(fmt: v21->buffer);
          }
          *(_BYTE *)(v6 + 260) = 1;
        }
      }
    }
  }
}


// ========================================================================
// ?FirstSnapHasBeenSent@idLobby@@QAA_NH@Z
// EA  : 0x829B5D58
// RVA : 0x009B5D58
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

BOOL __fastcall idLobby::FirstSnapHasBeenSent(idLobby *this, int p)
{
  char v5; // r11
  int v6; // r11
  int v7; // r10

  if ( session->GetState(this: session) != INGAME )
    return false;
  if ( p < 0 || (v5 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
    v5 = 0;
  if ( v5 != 0
    && (v6 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p, (v7 = *(_DWORD *)(v6 + 104)) != 0)
    && *(_DWORD *)(v6 + 284) != 0
    && v7 != -66644 )
  {
    return *(_DWORD *)(v7 + 66648) != 0;
  }
  else
  {
    return false;
  }
}


// ========================================================================
// ?EnsureAllPeersHaveBaseState@idLobby@@UAA_NXZ
// EA  : 0x829B5E18
// RVA : 0x009B5E18
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::EnsureAllPeersHaveBaseState(idLobby *this)
{
  int v2; // r25
  int v3; // r28
  int v4; // r30
  int v5; // r29
  int v6; // r11
  int v7; // r29
  int i; // r30
  _DWORD *v9; // r11
  int v10; // r11

  if ( session->GetState(this: session) == INGAME )
  {
    v2 = Sys_Milliseconds();
    v3 = session->GetTitleStorageInt_2(
           this: session,
           a2: "net_peer_timeout_loading",
           a3: net_peer_timeout_loading.valueInteger);
    if ( v3 > 0 )
    {
      v4 = 0;
      if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
      {
        v5 = 0;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5) == 2
            && idLobby::FirstSnapHasBeenSent(this, p: v4) )
          {
            v6 = *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5 + 268);
            if ( v6 > 0 && v2 > v6 + v3 )
            {
              if ( net_verbose.valueInteger != 0 )
                idLib::Printf(fmt: "EnsureAllPeersHaveBaseState: disconnecting peer %d for taking too long\n", v4);
              idLobby::DisconnectPeerFromSession(this, p: v4);
            }
          }
          ++v4;
          v5 += 472;
        }
        while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
      }
    }
    v7 = 0;
    if ( *(int *)this->userPool.staticList[5].gamertag <= 0 )
      return 1;
    for ( i = 0; ; i += 472 )
    {
      v9 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + i);
      if ( *v9 == 2 && v9[26] != 0 && idLobby::FirstSnapHasBeenSent(this, p: v7) )
      {
        v10 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType;
        if ( *(int *)(*(_DWORD *)(i + v10 + 104) + 8) < 42 )
          break;
      }
      if ( ++v7 >= *(_DWORD *)this->userPool.staticList[5].gamertag )
        return 1;
    }
    if ( v2 - *(_DWORD *)(472 * v7 + v10 + 8) > session->GetTitleStorageInt_2(
                                                  this: session,
                                                  a2: "net_snap_redundant_resend_in_ms",
                                                  a3: net_snap_redundant_resend_in_ms.valueInteger) )
      idLobby::SendSnapshotToPeer(
        this,
        ss: (idSnapShot *)(*(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * v7 + 104)
                     + 66644),
        p: v7);
  }
  return 0;
}


// ========================================================================
// ?SendCompletedSnaps@idLobby@@QAA_NXZ
// EA  : 0x829B6020
// RVA : 0x009B6020
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

int __fastcall idLobby::SendCompletedSnaps(idLobby *this)
{
  int v3; // r22
  int v4; // r29
  int v5; // r26
  _DWORD *v6; // r31
  int v7; // r11
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  va *v15; // r3
  int v16; // [sp+8h] [-10A8h]
  int v17; // [sp+Ch] [-10A4h]
  int v18; // [sp+10h] [-10A0h]
  int v19; // [sp+14h] [-109Ch]
  int v20; // [sp+18h] [-1098h]
  int v21; // [sp+1Ch] [-1094h]
  va v22; // [sp+50h] [-1060h] BYREF

  if ( session->GetState(this: session) != INGAME )
    return 0;
  v3 = 1;
  v4 = 0;
  if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
  {
    v5 = 0;
    do
    {
      v6 = (_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v5);
      if ( *v6 == 2 )
      {
        v7 = v6[26];
        if ( v7 != 0 )
        {
          if ( *(int *)(*(_DWORD *)(v7 + 66700) + 214032) <= 0 )
          {
            HIDWORD(v8) = this->IsHost(this);
            if ( HIDWORD(v8) != 0 && net_verboseSnapshot.valueInteger >= 7 )
            {
              HIDWORD(v10) = v4;
              v11 = va::va(
                      this: &v22,
                      fmt: "  ^8Peer %d pendingSnap not ready to send\n",
                      a3: v10,
                      a4: v9,
                      a5: v8,
                      a6: v16,
                      a7: v17,
                      a8: v18,
                      a9: v19,
                      a10: v20,
                      a11: v21);
              idLib::Printf(fmt: v11->buffer);
            }
          }
          else
          {
            idLobby::SendCompletedPendingSnap(this, p: v4);
          }
          if ( *v6 == 2 && *(int *)(*(_DWORD *)(v6[26] + 66700) + 214032) > 0 )
          {
            v3 = 0;
            HIDWORD(v12) = this->IsHost(this);
            if ( HIDWORD(v12) != 0 && net_verboseSnapshot.valueInteger >= 2 )
            {
              HIDWORD(v14) = v4;
              v15 = va::va(
                      this: &v22,
                      fmt: "  ^2Peer %d did not send all submitted snapshots.\n",
                      a3: v14,
                      a4: v13,
                      a5: v12,
                      a6: v16,
                      a7: v17,
                      a8: v18,
                      a9: v19,
                      a10: v20,
                      a11: v21);
              idLib::Printf(fmt: v15->buffer);
            }
          }
        }
      }
      ++v4;
      v5 += 472;
    }
    while ( v4 < *(_DWORD *)this->userPool.staticList[5].gamertag );
  }
  return v3;
}


// ========================================================================
// ?ApplySnapshotDelta@idLobby@@QAAXHH@Z
// EA  : 0x829B61A8
// RVA : 0x009B61A8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::ApplySnapshotDelta(idLobby *this, int p, const idMaterial *snapshotNumber)
{
  char v6; // r11
  int v7; // r11
  int v8; // r11
  int v9; // r10
  int v10; // r9
  _DWORD *v11; // r11
  idSkinMapping v12; // [sp+50h] [-30h] BYREF

  if ( session->GetState(this: session) == INGAME )
  {
    if ( p < 0 || (v6 = 1, p >= *(_DWORD *)this->userPool.staticList[5].gamertag) )
      v6 = 0;
    if ( v6 != 0 && *(_DWORD *)(*(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + 472 * p) == 2 )
    {
      if ( net_queueSnapAcks.valueInteger != 0 && (unsigned __int8)idLobby::AllPeersHaveBaseState(this) != 0 )
      {
        if ( *(_DWORD *)&this->parms.debugJobName.buffer[36] == *(_DWORD *)&this->parms.debugJobName.buffer[40] )
        {
          idLobby::ApplySnapshotDeltaInternal(
            this,
            p: **(_DWORD **)&this->parms.debugJobName.buffer[32],
            snapshotNumber: *(_DWORD *)(*(_DWORD *)&this->parms.debugJobName.buffer[32] + 4));
          v7 = *(_DWORD *)&this->parms.debugJobName.buffer[36];
          if ( v7 > 0 )
          {
            v8 = v7 - 1;
            v9 = 0;
            *(_DWORD *)&this->parms.debugJobName.buffer[36] = v8;
            if ( v8 > 0 )
            {
              v10 = 0;
              do
              {
                ++v9;
                v11 = (_DWORD *)(*(_DWORD *)&this->parms.debugJobName.buffer[32] + v10);
                v10 += 8;
                *v11 = v11[2];
                v11[1] = v11[3];
              }
              while ( v9 < *(_DWORD *)&this->parms.debugJobName.buffer[36] );
            }
          }
        }
        v12.from = (const idMaterial *)p;
        v12.to = snapshotNumber;
        idList<cachedPageFile_t,5>::Append(
          this: (idList<idSkinMapping,46> *)&this->parms.debugJobName.buffer[32],
          obj: &v12);
      }
      else
      {
        idLobby::ApplySnapshotDeltaInternal(this, p, (int)snapshotNumber);
      }
    }
  }
}


// ========================================================================
// ?UpdateSnaps@idLobby@@QAAXXZ
// EA  : 0x829B62F8
// RVA : 0x009B62F8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __fastcall idLobby::UpdateSnaps(idLobby *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idParallelJobList *v4; // r3
  idConsole_vtbl *v5; // r29
  idParallelJobList *v6; // r3
  char v7; // r25
  int v8; // r27
  int v9; // r28
  int v10; // r29
  idParallelJobList *v11; // r3
  idParallelJobList *v12; // r3
  idPLogScope v13[10]; // [sp+50h] [-50h] BYREF

  if ( session->GetState(this: session) == INGAME )
  {
    RD_EventBegin(name: "idLobby_UpdateSnaps");
    LODWORD(v2) = "idLobby_UpdateSnaps";
    HIDWORD(v2) = 32;
    idPLogScope::idPLogScope(this: v13, pl: &pLog, gMask: v2, label: v3);
    if ( this->sessionCB->GetSnapshotJobList(this: this->sessionCB) == nullptr
      || (v4 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB), idParallelJobList::TryWait(this: v4)) )
    {
      if ( this->parms.debugJobName.buffer[25] != 0 )
      {
        v5 = console->__vftable;
        v6 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB);
        v5->AddJobListTimeRange(this: console, a2: RANGE_JBL_SNAP, a3: &idColor::colorPink, a4: v6, a5: 0);
      }
      this->parms.debugJobName.buffer[25] = 0;
      v7 = 0;
      if ( (unsigned __int8)idLobby::SendCompletedSnaps(this) != 0 )
      {
        v8 = 0;
        if ( *(int *)this->userPool.staticList[5].gamertag > 0 )
        {
          v9 = 0;
          do
          {
            v10 = *(_DWORD *)&this->userPool.staticList[5].lobbyUserID.lobbyType + v9;
            if ( *(_DWORD *)v10 == 2
              && *(_BYTE *)(v10 + 260) != 0
              && (unsigned __int8)idLobby::SubmitPendingSnap(this, p: v8) != 0 )
            {
              v7 = 1;
              *(_BYTE *)(v10 + 260) = 0;
            }
            ++v8;
            v9 += 472;
          }
          while ( v8 < *(_DWORD *)this->userPool.staticList[5].gamertag );
        }
        if ( v7 != 0
          && net_disableSnapJob.valueInteger == 0
          && this->sessionCB->GetSnapshotJobList(this: this->sessionCB) != nullptr )
        {
          v11 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB);
          idParallelJobList::Submit(this: v11, waitForJobList: nullptr, parallelism: -1);
          this->parms.debugJobName.buffer[25] = 1;
          if ( net_waitOnSnaps.valueInteger != 0 )
          {
            v12 = this->sessionCB->GetSnapshotJobList(this: this->sessionCB);
            idParallelJobList::Wait(this: v12);
            idLobby::SendCompletedSnaps(this);
          }
        }
      }
    }
    else if ( net_verboseSnapshot.valueInteger >= 5 )
    {
      idLib::Printf(fmt: "   ^8snapshotJobList not done...\n");
    }
    idPLogScope::~idPLogScope(this: v13);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$224398
// EA  : 0x829B6554
// RVA : 0x009B6554
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void _unwind_224398()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$224399_0
// EA  : 0x829B657C
// RVA : 0x009B657C
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void _unwind_224399_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'net_waitOnSnaps''
// EA  : 0x83362438
// RVA : 0x01362438
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_waitOnSnaps__()
{
  idCVar::idCVar(
    this: &net_waitOnSnaps,
    name: "net_waitOnSnaps",
    value: "0",
    flags: 1,
    description: "wait on snaps",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_waitOnSnaps__);
}


// ========================================================================
// `dynamic initializer for 'net_disableSnapJob''
// EA  : 0x83362490
// RVA : 0x01362490
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_disableSnapJob__()
{
  idCVar::idCVar(
    this: &net_disableSnapJob,
    name: "net_disableSnapJob",
    value: "0",
    flags: 1,
    description: "disable snap jobs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_disableSnapJob__);
}


// ========================================================================
// `dynamic initializer for 'net_snapshot_send_warntime''
// EA  : 0x833624E8
// RVA : 0x013624E8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapshot_send_warntime__()
{
  idCVar::idCVar(
    this: &net_snapshot_send_warntime,
    name: "net_snapshot_send_warntime",
    value: "500",
    flags: 2,
    description: "Print warning messages if we take longer than this to send a client a snapshot.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapshot_send_warntime__);
}


// ========================================================================
// `dynamic initializer for 'net_queueSnapAcks''
// EA  : 0x83362540
// RVA : 0x01362540
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_queueSnapAcks__()
{
  idCVar::idCVar(
    this: &net_queueSnapAcks,
    name: "net_queueSnapAcks",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_queueSnapAcks__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_mode''
// EA  : 0x83362598
// RVA : 0x01362598
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_mode__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_mode,
    name: "net_peer_throttle_mode",
    value: "3",
    flags: 2,
    description: "= 0 off, 1 = enable fixed, 2 = absolute, 3 = both",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_mode__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_minSnapSeq''
// EA  : 0x833625F0
// RVA : 0x013625F0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_minSnapSeq__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_minSnapSeq,
    name: "net_peer_throttle_minSnapSeq",
    value: "150",
    flags: 2,
    description: "Minumum number of snapshot exchanges before throttling can be triggered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_minSnapSeq__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_bps_peer_threshold_pct''
// EA  : 0x83362648
// RVA : 0x01362648
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_bps_peer_threshold_pct__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_bps_peer_threshold_pct,
    name: "net_peer_throttle_bps_peer_threshold_pct",
    value: "0.60",
    flags: 4,
    description: "Min reported incoming bps % of sent from host that a peer must maintain before throttling kicks in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_bps_peer_threshold_pct__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_bps_host_threshold''
// EA  : 0x833626A0
// RVA : 0x013626A0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_bps_host_threshold__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_bps_host_threshold,
    name: "net_peer_throttle_bps_host_threshold",
    value: "1024",
    flags: 4,
    description: "Min outgoing bps of host for bps based throttling to be considered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_bps_host_threshold__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_bps_decay''
// EA  : 0x833626F8
// RVA : 0x013626F8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_bps_decay__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_bps_decay,
    name: "net_peer_throttle_bps_decay",
    value: "0.25f",
    flags: 4,
    description: "If peer exceeds this number of queued snap deltas, then throttle his effective snap rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_bps_decay__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_bps_duration''
// EA  : 0x83362750
// RVA : 0x01362750
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_bps_duration__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_bps_duration,
    name: "net_peer_throttle_bps_duration",
    value: "3000",
    flags: 2,
    description: "If peer exceeds this number of queued snap deltas, then throttle his effective snap rate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_bps_duration__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_throttle_maxSnapRate''
// EA  : 0x833627A8
// RVA : 0x013627A8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_throttle_maxSnapRate__()
{
  idCVar::idCVar(
    this: &net_peer_throttle_maxSnapRate,
    name: "net_peer_throttle_maxSnapRate",
    value: "4",
    flags: 2,
    description: "Highest factor of server base snapRate that a client can be throttled",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_throttle_maxSnapRate__);
}


// ========================================================================
// `dynamic initializer for 'net_snap_bw_test_throttle_max_scale''
// EA  : 0x83362800
// RVA : 0x01362800
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snap_bw_test_throttle_max_scale__()
{
  idCVar::idCVar(
    this: &net_snap_bw_test_throttle_max_scale,
    name: "net_snap_bw_test_throttle_max_scale",
    value: "0.80",
    flags: 4,
    description: "When clamping bandwidth to reported values, scale reported value by this",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snap_bw_test_throttle_max_scale__);
}


// ========================================================================
// `dynamic initializer for 'net_snap_redundant_resend_in_ms''
// EA  : 0x83362858
// RVA : 0x01362858
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snap_redundant_resend_in_ms__()
{
  idCVar::idCVar(
    this: &net_snap_redundant_resend_in_ms,
    name: "net_snap_redundant_resend_in_ms",
    value: "800",
    flags: 2,
    description: "Delay between redundantly sending snaps during initial snap exchange",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snap_redundant_resend_in_ms__);
}


// ========================================================================
// `dynamic initializer for 'net_min_ping_in_ms''
// EA  : 0x833628B0
// RVA : 0x013628B0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_min_ping_in_ms__()
{
  idCVar::idCVar(
    this: &net_min_ping_in_ms,
    name: "net_min_ping_in_ms",
    value: "1500",
    flags: 2,
    description: "Ping has to be higher than this before we consider throttling to recover",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_min_ping_in_ms__);
}


// ========================================================================
// `dynamic initializer for 'net_pingIncPercentBeforeRecover''
// EA  : 0x83362908
// RVA : 0x01362908
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_pingIncPercentBeforeRecover__()
{
  idCVar::idCVar(
    this: &net_pingIncPercentBeforeRecover,
    name: "net_pingIncPercentBeforeRecover",
    value: "1.3",
    flags: 4,
    description: "Percentage change increase of ping before we try to recover",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_pingIncPercentBeforeRecover__);
}


// ========================================================================
// `dynamic initializer for 'net_maxFailedPingRecoveries''
// EA  : 0x83362960
// RVA : 0x01362960
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_maxFailedPingRecoveries__()
{
  idCVar::idCVar(
    this: &net_maxFailedPingRecoveries,
    name: "net_maxFailedPingRecoveries",
    value: "10",
    flags: 2,
    description: "Max failed ping recoveries before we stop trying",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_maxFailedPingRecoveries__);
}


// ========================================================================
// `dynamic initializer for 'net_pingRecoveryThrottleTimeInSeconds''
// EA  : 0x833629B8
// RVA : 0x013629B8
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_pingRecoveryThrottleTimeInSeconds__()
{
  idCVar::idCVar(
    this: &net_pingRecoveryThrottleTimeInSeconds,
    name: "net_pingRecoveryThrottleTimeInSeconds",
    value: "3",
    flags: 2,
    description: "Throttle snaps for this amount of time in seconds to recover from ping spike",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_pingRecoveryThrottleTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'net_peer_timeout_loading''
// EA  : 0x83362A10
// RVA : 0x01362A10
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_peer_timeout_loading__()
{
  idCVar::idCVar(
    this: &net_peer_timeout_loading,
    name: "net_peer_timeout_loading",
    value: "90000",
    flags: 2,
    description: "time in MS to disconnect clients during loading - production only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_peer_timeout_loading__);
}


// ========================================================================
// `dynamic initializer for 'net_snapreport_warnsize''
// EA  : 0x83362A68
// RVA : 0x01362A68
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_snapreport_warnsize__()
{
  idCVar::idCVar(
    this: &net_snapreport_warnsize,
    name: "net_snapreport_warnsize",
    value: "100",
    flags: 2,
    description: "Print snapshot report if final compressed delta is > than this (bytes)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_snapreport_warnsize__);
}


// ========================================================================
// `dynamic initializer for 'net_forceDropSnap''
// EA  : 0x83362AC0
// RVA : 0x01362AC0
// PDB : w:\tech5\engine\sys\sys_lobby_snapshot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_forceDropSnap__()
{
  idCVar::idCVar(
    this: &net_forceDropSnap,
    name: "net_forceDropSnap",
    value: "0",
    flags: 1,
    description: "wait on snaps",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_forceDropSnap__);
}

