
// ========================================================================
// ?IsLosingConnectionToHost@idCommonLocal@@UAA_NXZ
// EA  : 0x82658A70
// RVA : 0x00658A70
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

BOOL __fastcall idCommonLocal::IsLosingConnectionToHost(idCommonLocal *this)
{
  return !common->IsServer(this: common) && session->IsLosingConnectionToHost(this: session);
}


// ========================================================================
// ?NetReceiveReliable@idCommonLocal@@EAAXHAAVidBitMsg@@H@Z
// EA  : 0x82658B38
// RVA : 0x00658B38
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::NetReceiveReliable(idCommonLocal *this, int type, idBitMsg *msg, int peer)
{
  idGame *v8; // r3

  if ( this->Game(this) != nullptr )
  {
    v8 = this->Game(this);
    v8->NetReceiveReliable(this: v8, a2: type, a3: msg, a4: peer);
  }
  else if ( net_verbose.valueInteger != 0 )
  {
    idLib::Printf(fmt: "Received Game reliable msg before game has been allocated.\n");
  }
}


// ========================================================================
// ?WriteUserCmdDelta@idCommonLocal@@AAAXAAVidBitMsg@@ABVusercmd_t@@PBV3@@Z
// EA  : 0x82658BD0
// RVA : 0x00658BD0
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::WriteUserCmdDelta(
        idCommonLocal *this,
        idBitMsg *msg,
        const usercmd_t *cmd,
        const usercmd_t *base)
{
  if ( base != nullptr )
  {
    idBitMsg::WriteDeltaLongCounter(this: msg, oldValue: base->clientGameFrame, newValue: cmd->clientGameFrame);
    idBitMsg::WriteDelta(this: msg, oldValue: base->buttons, newValue: cmd->buttons, numBits: 32);
    idBitMsg::WriteDelta(this: msg, oldValue: base->forwardmove, newValue: cmd->forwardmove, numBits: -8);
    idBitMsg::WriteDelta(this: msg, oldValue: base->rightmove, newValue: cmd->rightmove, numBits: -8);
    idBitMsg::WriteDelta(this: msg, oldValue: base->upmove, newValue: cmd->upmove, numBits: -8);
    idBitMsg::WriteDelta(this: msg, oldValue: base->angles[0], newValue: cmd->angles[0], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->angles[1], newValue: cmd->angles[1], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->angles[2], newValue: cmd->angles[2], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: COERCE_INT(base->pos[0]), newValue: COERCE_INT(cmd->pos[0]), numBits: 32);
    idBitMsg::WriteDelta(this: msg, oldValue: COERCE_INT(base->pos[1]), newValue: COERCE_INT(cmd->pos[1]), numBits: 32);
    idBitMsg::WriteDelta(this: msg, oldValue: COERCE_INT(base->pos[2]), newValue: COERCE_INT(cmd->pos[2]), numBits: 32);
    idBitMsg::WriteDelta(this: msg, oldValue: base->pitch, newValue: cmd->pitch, numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->yaw, newValue: cmd->yaw, numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->roll, newValue: cmd->roll, numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->predictionStateBits, newValue: cmd->predictionStateBits, numBits: 8);
    idBitMsg::WriteDelta(this: msg, oldValue: base->vehicleThrottle, newValue: cmd->vehicleThrottle, numBits: 8);
    idBitMsg::WriteDeltaLongCounter(this: msg, oldValue: base->serverGameTime, newValue: cmd->serverGameTime);
    idBitMsg::WriteDeltaShortCounter(this: msg, oldValue: base->fireCount, newValue: cmd->fireCount);
    idBitMsg::WriteDelta(this: msg, oldValue: base->fireAngles[0], newValue: cmd->fireAngles[0], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->fireAngles[1], newValue: cmd->fireAngles[1], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->firePos[0], newValue: cmd->firePos[0], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->firePos[1], newValue: cmd->firePos[1], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->firePos[2], newValue: cmd->firePos[2], numBits: -16);
    idBitMsg::WriteDelta(this: msg, oldValue: base->speed, newValue: cmd->speed, numBits: 8);
  }
  else
  {
    idBitMsg::WriteBits(this: msg, value: cmd->clientGameFrame, numBits: 32);
    idBitMsg::WriteBits(this: msg, value: cmd->buttons, numBits: 32);
    idBitMsg::WriteBits(this: msg, value: cmd->forwardmove, numBits: -8);
    idBitMsg::WriteBits(this: msg, value: cmd->rightmove, numBits: -8);
    idBitMsg::WriteBits(this: msg, value: cmd->upmove, numBits: -8);
    idBitMsg::WriteBits(this: msg, value: cmd->angles[0], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->angles[1], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->angles[2], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(cmd->pos[0]), numBits: 32);
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(cmd->pos[1]), numBits: 32);
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(cmd->pos[2]), numBits: 32);
    idBitMsg::WriteBits(this: msg, value: cmd->pitch, numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->yaw, numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->roll, numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->predictionStateBits, numBits: 8);
    idBitMsg::WriteBits(this: msg, value: cmd->vehicleThrottle, numBits: 8);
    idBitMsg::WriteBits(this: msg, value: cmd->serverGameTime, numBits: 32);
    idBitMsg::WriteBits(this: msg, value: cmd->fireCount, numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->fireAngles[0], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->fireAngles[1], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->firePos[0], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->firePos[1], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->firePos[2], numBits: -16);
    idBitMsg::WriteBits(this: msg, value: cmd->speed, numBits: 8);
  }
  idBitMsg::WriteBits(this: msg, value: *((unsigned __int8 *)cmd + 9) >> 7, numBits: 1);
}


// ========================================================================
// ?ReadUserCmdDelta@idCommonLocal@@AAAXABVidBitMsg@@AAVusercmd_t@@PBV3@@Z
// EA  : 0x82659068
// RVA : 0x00659068
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::ReadUserCmdDelta(
        idCommonLocal *this,
        idBitMsg *msg,
        usercmd_t *cmd,
        const usercmd_t *base)
{
  memset(Dst: cmd, Val: 0, Size: sizeof(usercmd_t));
  if ( base != nullptr )
  {
    cmd->clientGameFrame = idBitMsg::ReadDeltaLongCounter(this: msg, oldValue: base->clientGameFrame);
    cmd->buttons = idBitMsg::ReadDelta(this: msg, oldValue: base->buttons, numBits: 32);
    cmd->forwardmove = idBitMsg::ReadDelta(this: msg, oldValue: base->forwardmove, numBits: -8);
    cmd->rightmove = idBitMsg::ReadDelta(this: msg, oldValue: base->rightmove, numBits: -8);
    cmd->upmove = idBitMsg::ReadDelta(this: msg, oldValue: base->upmove, numBits: -8);
    cmd->angles[0] = idBitMsg::ReadDelta(this: msg, oldValue: base->angles[0], numBits: -16);
    cmd->angles[1] = idBitMsg::ReadDelta(this: msg, oldValue: base->angles[1], numBits: -16);
    cmd->angles[2] = idBitMsg::ReadDelta(this: msg, oldValue: base->angles[2], numBits: -16);
    cmd->pos[0] = COERCE_FLOAT(idBitMsg::ReadDelta(this: msg, oldValue: COERCE_INT(base->pos[0]), numBits: 32));
    cmd->pos[1] = COERCE_FLOAT(idBitMsg::ReadDelta(this: msg, oldValue: COERCE_INT(base->pos[1]), numBits: 32));
    cmd->pos[2] = COERCE_FLOAT(idBitMsg::ReadDelta(this: msg, oldValue: COERCE_INT(base->pos[2]), numBits: 32));
    cmd->pitch = idBitMsg::ReadDelta(this: msg, oldValue: base->pitch, numBits: -16);
    cmd->yaw = idBitMsg::ReadDelta(this: msg, oldValue: base->yaw, numBits: -16);
    cmd->roll = idBitMsg::ReadDelta(this: msg, oldValue: base->roll, numBits: -16);
    cmd->predictionStateBits = idBitMsg::ReadDelta(this: msg, oldValue: base->predictionStateBits, numBits: 8);
    cmd->vehicleThrottle = idBitMsg::ReadDelta(this: msg, oldValue: base->vehicleThrottle, numBits: 8);
    cmd->serverGameTime = idBitMsg::ReadDeltaLongCounter(this: msg, oldValue: base->serverGameTime);
    cmd->fireCount = idBitMsg::ReadDeltaShortCounter(this: msg, oldValue: base->fireCount);
    cmd->fireAngles[0] = idBitMsg::ReadDelta(this: msg, oldValue: base->fireAngles[0], numBits: -16);
    cmd->fireAngles[1] = idBitMsg::ReadDelta(this: msg, oldValue: base->fireAngles[1], numBits: -16);
    cmd->firePos[0] = idBitMsg::ReadDelta(this: msg, oldValue: base->firePos[0], numBits: -16);
    cmd->firePos[1] = idBitMsg::ReadDelta(this: msg, oldValue: base->firePos[1], numBits: -16);
    cmd->firePos[2] = idBitMsg::ReadDelta(this: msg, oldValue: base->firePos[2], numBits: -16);
    cmd->speed = idBitMsg::ReadDelta(this: msg, oldValue: base->speed, numBits: 8);
  }
  else
  {
    cmd->clientGameFrame = idBitMsg::ReadBits(this: msg, numBits: 32);
    cmd->buttons = idBitMsg::ReadBits(this: msg, numBits: 32);
    cmd->forwardmove = idBitMsg::ReadBits(this: msg, numBits: -8);
    cmd->rightmove = idBitMsg::ReadBits(this: msg, numBits: -8);
    cmd->upmove = idBitMsg::ReadBits(this: msg, numBits: -8);
    cmd->angles[0] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->angles[1] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->angles[2] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->pos[0] = COERCE_FLOAT(idBitMsg::ReadBits(this: msg, numBits: 32));
    cmd->pos[1] = COERCE_FLOAT(idBitMsg::ReadBits(this: msg, numBits: 32));
    cmd->pos[2] = COERCE_FLOAT(idBitMsg::ReadBits(this: msg, numBits: 32));
    cmd->pitch = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->yaw = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->roll = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->predictionStateBits = idBitMsg::ReadBits(this: msg, numBits: 8);
    cmd->vehicleThrottle = idBitMsg::ReadBits(this: msg, numBits: 8);
    cmd->serverGameTime = idBitMsg::ReadBits(this: msg, numBits: 32);
    cmd->fireCount = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->fireAngles[0] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->fireAngles[1] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->firePos[0] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->firePos[1] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->firePos[2] = idBitMsg::ReadBits(this: msg, numBits: -16);
    cmd->speed = idBitMsg::ReadBits(this: msg, numBits: 8);
  }
  *((_BYTE *)cmd + 9) = (4 * _cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1)) & 0x80 | *((_BYTE *)cmd + 9) & 0x7F;
}


// ========================================================================
// ?NetSendUsercmds@idCommonLocal@@AAAXXZ
// EA  : 0x82659A60
// RVA : 0x00659A60
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCommonLocal::NetSendUsercmds(idCommonLocal *this)
{
  int v1; // r30 OVERLAPPED
  idLobbyBase *v3; // r3
  signed int v4; // r3
  int userCmdFrame; // r10
  char v6; // r21
  int v7; // r31
  idGame *v8; // r3
  int v9; // r26
  const usercmd_t *v10; // r27
  int v11; // r6
  signed int PlayerCmds; // r30
  idGame *v13; // r3
  int v14; // r29
  usercmd_t **v15; // r28
  int clientGameFrame; // r5
  const char *v17; // r4
  bool v18[4]; // [sp+50h] [-530h] BYREF
  int v19; // [sp+54h] [-52Ch]
  int v20; // [sp+60h] [-520h] BYREF
  __int16 v21; // [sp+64h] [-51Ch]
  char v22; // [sp+66h] [-51Ah]
  char v23; // [sp+67h] [-519h]
  char v24; // [sp+68h] [-518h]
  char v25; // [sp+69h] [-517h]
  __int16 v26; // [sp+6Ah] [-516h]
  __int16 v27; // [sp+6Ch] [-514h]
  __int16 v28; // [sp+6Eh] [-512h]
  int v29; // [sp+70h] [-510h]
  float v30; // [sp+74h] [-50Ch]
  float v31; // [sp+78h] [-508h]
  float v32; // [sp+7Ch] [-504h]
  __int16 v33; // [sp+80h] [-500h]
  __int16 v34; // [sp+82h] [-4FEh]
  __int16 v35; // [sp+84h] [-4FCh]
  char v36; // [sp+86h] [-4FAh]
  int v37; // [sp+88h] [-4F8h]
  __int16 v38; // [sp+8Ch] [-4F4h]
  __int16 v39; // [sp+8Eh] [-4F2h]
  __int16 v40; // [sp+90h] [-4F0h]
  __int16 v41; // [sp+92h] [-4EEh]
  __int16 v42; // [sp+94h] [-4ECh]
  __int16 v43; // [sp+96h] [-4EAh]
  char v44; // [sp+98h] [-4E8h]
  char v45; // [sp+99h] [-4E7h]
  idBitMsg v46; // [sp+A0h] [-4E0h] BYREF
  usercmd_t *v47[6]; // [sp+C8h] [-4B8h] BYREF
  _BYTE v48[1024]; // [sp+E0h] [-4A0h] BYREF

  if ( session->GetState(this: session) == INGAME )
  {
    v3 = session->GetActingGameStateLobbyBase(this: session);
    if ( v3->IsPeer(this: v3) )
    {
      ++this->userCmdFrame;
      v4 = session->GetTitleStorageInt_2(this: session, a2: "net_userCmdRate", a3: net_userCmdRate.valueInteger);
      userCmdFrame = this->userCmdFrame;
      __twllei(v4, 0);
      __twlgei(v4 & ~(__ROL4__(userCmdFrame, 1) - 1), 0xFFFFFFFF);
      if ( userCmdFrame % v4 == 0 )
      {
        v6 = v25;
        v46.writeData = v48;
        v46.readData = v48;
        v7 = 0;
        v46.maxSize = 1024;
        memset(&v46.curSize, 0, 18);
        v19 = 0;
        v46.tempValue = *(_QWORD *)(&v1 - 1);
        do
        {
          v8 = this->Game(this);
          v9 = v8->GetPlayerIndexFromInputDevice(this: v8, a2: v19);
          if ( v9 != -1 )
          {
            v6 &= 0x3Fu;
            v32 = 0.0;
            v31 = 0.0;
            v30 = 0.0;
            v20 = 0;
            v21 = 0;
            v10 = (const usercmd_t *)&v20;
            v22 = 0;
            v23 = 0;
            v24 = 0;
            v28 = 0;
            v27 = 0;
            v26 = 0;
            v29 = 0;
            v34 = 0;
            v33 = 0;
            v35 = 0;
            v36 = 0;
            v44 = 0;
            v37 = 0;
            v38 = 0;
            v40 = 0;
            v39 = 0;
            v43 = 0;
            v42 = 0;
            v41 = 0;
            v45 = 0;
            v25 = v6;
            idBitMsg::WriteBits(this: &v46, value: 1, numBits: 1);
            idBitMsg::WriteBits(this: &v46, value: v9, numBits: 3);
            v11 = session->GetTitleStorageInt_2(this: session, a2: "MAX_REDUNDANT_CMDS", a3: 3);
            if ( v11 >= 3 )
              v11 = 3;
            PlayerCmds = idUserCmdMgr::GetPlayerCmds(this: &this->userCmdMgr, user: v9, buffer: v47, bufferSize: v11);
            v18[0] = false;
            if ( PlayerCmds > 0 )
            {
              v13 = this->Game(this);
              v13->GetPlayerPredictionData(this: v13, a2: v9, a3: v47, a4: PlayerCmds, a5: v18);
            }
            idBitMsg::WriteBits(this: &v46, value: v18[0], numBits: 1);
            idBitMsg::WriteBits(this: &v46, value: PlayerCmds, numBits: 8);
            if ( common->IsClient(this: common) && net_debug_NetSendUsercmds.valueInteger != 0 )
              idLib::Printf(fmt: "Sending commands: %d\n", PlayerCmds);
            v14 = -1;
            if ( PlayerCmds > 0 )
            {
              v15 = (usercmd_t **)&v46.tempValue + 1;
              do
              {
                if ( common->IsClient(this: common) )
                {
                  clientGameFrame = v15[1]->clientGameFrame;
                  if ( clientGameFrame > 10 && v14 >= 0 && clientGameFrame != v14 + 1 )
                    idLib::Printf(
                      fmt: "CLIENT: Sent input out of sequence for user %i ( %i/%i)\n",
                      v9,
                      clientGameFrame,
                      v14);
                }
                if ( common->IsClient(this: common) && net_debug_NetSendUsercmds.valueInteger != 0 )
                  idLib::Printf(fmt: "  Sent command for frame: %d \n", v15[1]->clientGameFrame);
                if ( net_print_ucmds_outgoing.valueInteger != 0 )
                {
                  v17 = "*";
                  if ( v10 != (const usercmd_t *)&v20 )
                    v17 = "-";
                  idLib::Printf(fmt: "%s-------\n", v17);
                  usercmd_t::Print(this: v15[1]);
                }
                idCommonLocal::WriteUserCmdDelta(this, msg: &v46, cmd: v15[1], base: v10);
                --PlayerCmds;
                v10 = *++v15;
                v14 = (*v15)->clientGameFrame;
              }
              while ( PlayerCmds != 0 );
            }
          }
          ++v19;
        }
        while ( v19 < 4 );
        idBitMsg::WriteBits(this: &v46, value: 0, numBits: 1);
        session->SendUsercmds(this: session, a2: &v46);
      }
    }
  }
}


// ========================================================================
// ?NetWriteResources@idCommonLocal@@EAAHPAVidLZWCompressor@@HH_N@Z
// EA  : 0x82659E98
// RVA : 0x00659E98
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

int __fastcall idCommonLocal::NetWriteResources(
        idCommonLocal *this,
        idLZWCompressor *compressor,
        int start,
        int maxLength,
        bool allowOverflow)
{
  unsigned __int8 v9; // r31
  int NumNetworkResources; // r20
  int v11; // r23
  int v12; // r21
  const idResource *NetworkResource; // r3
  const char *str; // r11
  idResource *v15; // r27
  int v16; // r29
  idResourceList *v17; // r3
  const char *ResourceTypeName; // r3
  int v19; // r26
  int v20; // r11
  int bytesWritten; // r7
  int v22; // r31
  _BYTE *v23; // r30
  int v24; // r30
  const char *v25; // r29
  int v26; // r31
  bool v27; // zf
  idResourceList *(__fastcall *GetResourceList)(idResource *); // ctr
  idResourceList *v29; // r3
  char *v30; // r3
  int v31; // r31
  _BYTE *v32; // r30
  int v33; // r31
  _BYTE *v34; // r30
  int v36; // r31
  _BYTE *v37; // r30
  __int16 staticID; // [sp+50h] [-80h]
  _BYTE v39[126]; // [sp+52h] [-7Eh] BYREF

  v9 = HIBYTE(idLib::production) - 2 - (HIBYTE(idLib::production) - 3 + (idLib::production == PROD_PRODUCTION));
  v11 = start;
  NumNetworkResources = idResourceList::GetNumNetworkResources();
  if ( start >= NumNetworkResources )
  {
LABEL_22:
    v33 = 0;
    LOBYTE(staticID) = 0;
    v34 = v39;
    do
    {
      if ( compressor->overflowed )
        break;
      idLZWCompressor::WriteByte(this: compressor, value: *--v34);
      ++v33;
    }
    while ( v33 < 2 );
    return NumNetworkResources;
  }
  else
  {
    v12 = v9;
    while ( 1 )
    {
      NetworkResource = idResourceList::GetNetworkResource(networkID: v11);
      str = NetworkResource->name.str;
      v15 = (idResource *)NetworkResource;
      v16 = 0;
      if ( *str != 0 )
      {
        do
          ++v16;
        while ( str[v16] != 0 );
      }
      v17 = NetworkResource->GetResourceList(this: NetworkResource);
      ResourceTypeName = idResourceList::GetResourceTypeName(this: v17);
      v19 = 0;
      if ( *ResourceTypeName != 0 )
      {
        do
          ++v19;
        while ( ResourceTypeName[v19] != 0 );
      }
      v20 = v16;
      if ( v12 != 0 )
        v20 = v19 + v16;
      bytesWritten = compressor->lzwData->bytesWritten;
      if ( bytesWritten + v20 + 8 >= maxLength )
        break;
      v22 = 0;
      v23 = v39;
      staticID = idResource::GetNetworkID(this: v15, alloc: true) + 1;
      do
      {
        if ( compressor->overflowed )
          break;
        idLZWCompressor::WriteByte(this: compressor, value: *--v23);
        ++v22;
      }
      while ( v22 < 2 );
      v24 = v16 + 1;
      v26 = 0;
      v27 = v16 + 1 <= 0;
      v25 = v15->name.str;
      if ( !v27 )
      {
        do
        {
          if ( compressor->overflowed )
            break;
          idLZWCompressor::WriteByte(this: compressor, value: v25[v26++]);
        }
        while ( v26 < v24 );
      }
      GetResourceList = v15->GetResourceList;
      if ( v12 != 0 )
      {
        v29 = GetResourceList(this: v15);
        v30 = (char *)idResourceList::GetResourceTypeName(this: v29);
        idLZWCompressor::Write(this: compressor, data: v30, length: v19 + 1);
      }
      else
      {
        v31 = 0;
        v32 = v39;
        staticID = GetResourceList(this: v15)->staticID;
        do
        {
          if ( compressor->overflowed )
            break;
          idLZWCompressor::WriteByte(this: compressor, value: *--v32);
          ++v31;
        }
        while ( v31 < 2 );
      }
      if ( ++v11 >= NumNetworkResources )
        goto LABEL_22;
    }
    if ( !allowOverflow )
      idLib::Error(fmt: "idCommonLocal::NetWriteResources exceeded max buffer size");
    if ( v11 == start )
      idLib::Warning(
        fmt: "NetWriteResources: unable to write any resources! start: %d maxLength: %d nameLength: %d compressedSize: %d",
        start,
        maxLength,
        v16,
        bytesWritten);
    v36 = 0;
    LOBYTE(staticID) = 0;
    v37 = v39;
    do
    {
      if ( compressor->overflowed )
        break;
      idLZWCompressor::WriteByte(this: compressor, value: *--v37);
      ++v36;
    }
    while ( v36 < 2 );
    return v11;
  }
}


// ========================================================================
// ?NetReadResources@idCommonLocal@@EAAXPAVidLZWCompressor@@@Z
// EA  : 0x8265A118
// RVA : 0x0065A118
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::NetReadResources(idCommonLocal *this, idLZWCompressor *compressor)
{
  char v3; // r20
  int v4; // r30
  int *v5; // r29
  int Byte; // r3
  int v7; // r26
  int v8; // r30
  char *v9; // r29
  int v10; // r3
  int v11; // r30
  char *v12; // r29
  int v13; // r3
  int v14; // r30
  int v15; // r30
  unsigned __int16 *v16; // r29
  int v17; // r3
  int v18; // r30
  idResourceList *v19; // r3
  char *data; // r29
  const char *ResourceTypeName; // r3
  idResource *NetworkResource; // r3
  idMaterial *v23; // r3
  unsigned __int16 v24; // [sp+50h] [-C0h] BYREF
  unsigned __int16 v25; // [sp+52h] [-BEh] BYREF
  int v26; // [sp+54h] [-BCh] BYREF
  idStr v27; // [sp+60h] [-B0h] BYREF
  idStr v28[4]; // [sp+80h] [-90h] BYREF

  v25 = 0;
  v3 = HIBYTE(idLib::production) - 2 - (HIBYTE(idLib::production) - 3 + (idLib::production == PROD_PRODUCTION));
LABEL_2:
  v4 = 0;
  v5 = &v26;
  while ( 1 )
  {
    Byte = idLZWCompressor::ReadByte(this: compressor, ignoreOverflow: false);
    if ( Byte == -1 )
      break;
    ++v4;
    v5 = (int *)((char *)v5 - 1);
    *(_BYTE *)v5 = Byte;
    if ( v4 >= 2 )
    {
      v7 = v25;
      if ( v25 == 0 )
        return;
      v27.allocedAndFlag = 20;
      v27.data = v27.baseBuffer;
      v27.len = 0;
      v27.baseBuffer[0] = 0;
      v8 = 0;
      v9 = (char *)&v24 + 1;
      do
      {
        v10 = idLZWCompressor::ReadByte(this: compressor, ignoreOverflow: false);
        if ( v10 == -1 )
          break;
        ++v8;
        *--v9 = v10;
      }
      while ( v8 < 1 );
      if ( v3 != 0 )
      {
        v28[0].allocedAndFlag = 20;
        v28[0].data = v28[0].baseBuffer;
        v28[0].len = 0;
        v28[0].baseBuffer[0] = 0;
        v11 = 0;
        v12 = (char *)&v24 + 1;
        do
        {
          v13 = idLZWCompressor::ReadByte(this: compressor, ignoreOverflow: false);
          if ( v13 == -1 )
            break;
          ++v11;
          *--v12 = v13;
        }
        while ( v11 < 1 );
        v14 = v7 - 1;
        idResourceList::RegisterNetworkResource(typeName: v28[0].data, name: v27.data, networkID: v7 - 1);
        idStr::FreeData(this: v28);
      }
      else
      {
        v15 = 0;
        v24 = 0;
        v16 = &v25;
        do
        {
          v17 = idLZWCompressor::ReadByte(this: compressor, ignoreOverflow: false);
          if ( v17 == -1 )
            break;
          ++v15;
          v16 = (unsigned __int16 *)((char *)v16 - 1);
          *(_BYTE *)v16 = v17;
        }
        while ( v15 < 2 );
        v18 = v24;
        v19 = idResourceList::ForStaticID(id: v24);
        if ( v19 == nullptr )
        {
          idLib::Error(fmt: " Resource list not found for id: %i '%s'\n", v18, v27.data);
          return;
        }
        data = v27.data;
        v14 = v7 - 1;
        ResourceTypeName = idResourceList::GetResourceTypeName(this: v19);
        idResourceList::RegisterNetworkResource(typeName: ResourceTypeName, name: data, networkID: v7 - 1);
      }
      NetworkResource = (idResource *)idResourceList::GetNetworkResource(networkID: v14);
      v23 = (idMaterial *)_RTDynamicCast(
                            inptr: NetworkResource,
                            VfDelta: 0,
                            SrcType: &idResource `RTTI Type Descriptor',
                            TargetType: (void *)&idMaterial `RTTI Type Descriptor',
                            isReference: 0);
      if ( v23 != nullptr )
        idMaterial::SetupVirtualTexture(this: v23);
      idStr::FreeData(this: &v27);
      goto LABEL_2;
    }
  }
}


// ========================================================================
// $LN132
// EA  : 0x8265A468
// RVA : 0x0065A468
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void _LN132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$223135_0
// EA  : 0x8265A490
// RVA : 0x0065A490
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void _unwind_223135_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// ?InterpolateSnapshot@idCommonLocal@@AAAXAAUgameReturn_t@@00M_N@Z
// EA  : 0x8265A4B8
// RVA : 0x0065A4B8
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::InterpolateSnapshot(
        idCommonLocal *this,
        gameReturn_t *ret,
        gameReturn_t *prev,
        gameReturn_t *next,
        double fraction,
        bool predict)
{
  idGame *v11; // r3
  __int64 v12; // r4
  __int64 v13; // r6
  idGame *v14; // r3
  idGame *v15; // r3
  float *p_fov_y; // r29
  renderView_t *p_view; // r30
  float *p_z; // r31
  int v19; // r27
  char v20; // r11
  bool *p_forceFullVirtualTextureLoad; // r11
  _DWORD *v22; // r10
  int i; // ctr
  const idQuat *v24; // r22
  const idQuat *v25; // r3
  idMat3 *v26; // r3
  __int64 v27; // r4
  idGame *v28; // r3
  float v29; // [sp+50h] [-E0h]
  float v30; // [sp+54h] [-DCh]
  float x; // [sp+60h] [-D0h]
  float y; // [sp+64h] [-CCh]
  idMat3 v33; // [sp+70h] [-C0h] BYREF
  idQuat v34; // [sp+A0h] [-90h] BYREF

  v11 = this->Game(this);
  ret->localTime = v11->GetGameMs(this: v11, a2: GAMETIME_SCALED);
  HIDWORD(v12) = this;
  LODWORD(v13) = next->serverTime;
  LODWORD(v12) = prev->serverTime;
  ret->serverTime = (int)(float)((float)((float)((float)v13 - (float)v12) * (float)fraction) + (float)v12);
  v14 = this->Game(this);
  v14->SetServerGameTimeMs(this: v14, a2: ret->serverTime);
  v15 = this->Game(this);
  v15->SetSSTimes(this: v15, a2: prev->serverTime, a3: next->serverTime);
  if ( !this->TimeTrialPlaying(this) )
  {
    p_fov_y = &prev->players.ptr[0].view.fov_y;
    p_view = &next->players.ptr[0].view;
    p_z = &ret->players.ptr[0].view.viewaxis.mat[1].z;
    v19 = 6;
    do
    {
      if ( *((_BYTE *)p_fov_y - 36) == 0 || (v20 = 1, HIBYTE(p_view[-1].godRaysSourceSize) == 0) )
        v20 = 0;
      *((_BYTE *)p_z - 144) = v20;
      if ( v20 != 0 )
      {
        p_z[436] = 0.0;
        p_forceFullVirtualTextureLoad = &p_view[1].forceFullVirtualTextureLoad;
        v22 = p_z + 438;
        for ( i = 7; i != 0; --i )
        {
          p_forceFullVirtualTextureLoad += 4;
          *++v22 = *(_DWORD *)p_forceFullVirtualTextureLoad;
        }
        renderView_t::operator=(this: (renderView_t *)(p_z - 32), __that: p_view);
        *(p_z - 28) = (float)((float)(p_view->fov_x - *(p_fov_y - 1)) * (float)fraction) + *(p_fov_y - 1);
        *(p_z - 27) = (float)((float)(p_view->fov_y - *p_fov_y) * (float)fraction) + *p_fov_y;
        v29 = p_fov_y[19];
        v30 = p_fov_y[20];
        x = p_view->vieworg.x;
        y = p_view->vieworg.y;
        *(p_z - 6) = (float)((float)(p_view->vieworg.z - p_fov_y[21]) * (float)fraction) + p_fov_y[21];
        *(p_z - 7) = (float)((float)(y - v30) * (float)fraction) + v30;
        *(p_z - 8) = (float)((float)(x - v29) * (float)fraction) + v29;
        v24 = idMat3::ToQuat(this: (idMat3 *)&v33.mat[1].y, result: (idQuat *)&p_view->viewaxis);
        v25 = idMat3::ToQuat(this: (idMat3 *)&v33.mat[2].z, result: (idQuat *)(p_fov_y + 22));
        idQuat::Slerp(this: (idQuat *)&v33, from: v25, to: v24, t: fraction);
        v26 = idQuat::ToMat3(this: &v34, result: &v33);
        *(idVec3 *)(p_z - 5) = v26->mat[0];
        *(p_z - 2) = v26->mat[1].x;
        *(p_z - 1) = v26->mat[1].y;
        *p_z = v26->mat[1].z;
        *(idVec3 *)(p_z + 1) = v26->mat[2];
      }
      --v19;
      p_z += 488;
      p_fov_y += 488;
      p_view = (renderView_t *)((char *)p_view + 1952);
    }
    while ( v19 != 0 );
  }
  v27 = ((__int64 (__fastcall *)(idCommonLocal *))this->Game)(a1: this);
  (*(void (__fastcall **)(_DWORD, _DWORD, int, int, int, double))(*(_DWORD *)HIDWORD(v27) + 300))(
    a1: HIDWORD(v27),
    a2: v27,
    a3: ret->serverTime,
    a4: prev->serverTime,
    a5: next->serverTime,
    a6: fraction);
  v28 = this->Game(this);
  v28->RunFrame(this: v28, a2: &this->userCmdMgr, a3: ret, a4: true);
}


// ========================================================================
// ?SerializePlayer@idCommonLocal@@AAAXAAVidSerializer@@AAUgameReturnPlayer_t@@@Z
// EA  : 0x8265A7D8
// RVA : 0x0065A7D8
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::SerializePlayer(idCommonLocal *this, idSerializer *ser, gameReturnPlayer_t *player)
{
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3
  bool absoluteAngles; // r29
  idBitMsg *v9; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: player->view.viewID, numBits: 32);
  else
    player->view.viewID = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: COERCE_INT(player->view.fov_x), numBits: 32);
  else
    LODWORD(player->view.fov_x) = idBitMsg::ReadBits(this: v6, numBits: 32);
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: COERCE_INT(player->view.fov_y), numBits: 32);
  else
    LODWORD(player->view.fov_y) = idBitMsg::ReadBits(this: v7, numBits: 32);
  absoluteAngles = player->inputSettings.absoluteAngles;
  v9 = ser->msg;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v9, value: player->inputSettings.absoluteAngles, numBits: 1);
    player->inputSettings.absoluteAngles = absoluteAngles;
  }
  else
  {
    player->inputSettings.absoluteAngles = (_cntlzw(idBitMsg::ReadBits(this: v9, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ?DrawSnapshotMetrics@idCommonLocal@@QAAX_N@Z
// EA  : 0x8265A8D0
// RVA : 0x0065A8D0
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCommonLocal::DrawSnapshotMetrics(idCommonLocal *this, BOOL draw)
{
  idLobbyBase *v4; // r3
  idLobbyBase *v5; // r30
  idLobbyBase_vtbl *v6; // r31
  idRenderModelGui *v7; // r3
  idGame *v8; // r3
  int v9; // r3
  int snapTimeBuffered; // r27
  int time; // r25
  int v12; // r26
  const idColor *v13; // r4
  idDebugGraph *v14; // r3
  double v15; // fp0
  double v16; // fp13
  double v17; // fp0
  const idColor *v18; // r4
  double v19; // fp1
  double v20; // fp25
  int v21; // r3
  idDebugGraph *graph; // r11
  double v23; // fp9
  idConsole *v24; // r3
  idConsole_vtbl *v25; // r10
  const idColor *v26; // r4
  int v27; // r3
  double v28; // fp0
  __int64 v29; // r9
  double v30; // fp30
  __int64 v31; // r6
  idDebugGraph *graphSnapRate; // r11
  idDebugGraph *v33; // r11
  idRenderModelGui *v34; // r3
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r8
  unsigned __int8 v38; // r29
  __int64 v39; // r4
  __int64 v40; // r10
  __int64 v41; // r6
  unsigned __int8 v42; // r29
  __int64 v43; // r4
  __int64 v44; // r8
  __int64 v45; // r10
  unsigned __int8 v46; // r29
  __int64 v47; // r4
  const idVec4 *v48; // r5
  __int128 v49; // r7 OVERLAPPED
  void *v50; // r8
  __int64 v51; // r10
  unsigned __int8 v52; // r30
  __int64 v53; // r4
  const idVec4 *v54; // r5
  double optimalTimeBuffered; // fp13
  double v56; // fp0
  float r; // r10
  float g; // r9
  float b; // r8
  float a; // r7
  double v61; // fp0
  int v62; // [sp+8h] [-1158h]
  int v63; // [sp+8h] [-1158h]
  int v64; // [sp+8h] [-1158h]
  int v65; // [sp+8h] [-1158h]
  int v66; // [sp+Ch] [-1154h]
  int v67; // [sp+Ch] [-1154h]
  int v68; // [sp+Ch] [-1154h]
  int v69; // [sp+Ch] [-1154h]
  int v70; // [sp+10h] [-1150h]
  int v71; // [sp+10h] [-1150h]
  int v72; // [sp+10h] [-1150h]
  int v73; // [sp+10h] [-1150h]
  int v74; // [sp+14h] [-114Ch]
  int v75; // [sp+14h] [-114Ch]
  int v76; // [sp+14h] [-114Ch]
  int v77; // [sp+14h] [-114Ch]
  int v78; // [sp+18h] [-1148h]
  int v79; // [sp+18h] [-1148h]
  int v80; // [sp+18h] [-1148h]
  int v81; // [sp+18h] [-1148h]
  int v82; // [sp+1Ch] [-1144h]
  int v83; // [sp+1Ch] [-1144h]
  int v84; // [sp+1Ch] [-1144h]
  int v85; // [sp+1Ch] [-1144h]
  double effectiveSnapRate; // [sp+28h] [-1138h]
  double optimalPCTBuffer; // [sp+40h] [-1120h]
  idVec4 v88; // [sp+90h] [-10D0h] BYREF
  float v89; // [sp+A0h] [-10C0h]
  float v90; // [sp+A4h] [-10BCh]
  float v91; // [sp+A8h] [-10B8h]
  float v92; // [sp+ACh] [-10B4h]
  idColor v93; // [sp+B0h] [-10B0h]
  va v94; // [sp+C0h] [-10A0h] BYREF

  if ( session->GetState(this: session) != INGAME )
    return;
  if ( common->IsServer(this: common) )
  {
    v4 = session->GetActingGameStateLobbyBase(this: session);
    if ( v4->HasActivePeers(this: v4) )
    {
      v5 = session->GetActingGameStateLobbyBase(this: session);
      v6 = v5->__vftable;
      v7 = console->Gui(this: console);
      v6->DrawDebugNetworkHUD_ServerSnapshotMetrics(this: v5, a2: v7, a3: draw);
    }
    return;
  }
  v8 = this->Game(this);
  v9 = v8->GetServerGameTimeMs(this: v8);
  snapTimeBuffered = (int)this->snapTimeBuffered;
  time = this->receivedSnaps.ptr[(this->writeSnapshotIndex - 1) % 16].time;
  v12 = v9;
  if ( this->graph == nullptr )
  {
    v14 = console->CreateGraph(this: console, a2: 500);
    v15 = flt_835AAAA0;
    v16 = flt_835AAA9C;
    this->graph = v14;
    v14->mode = GRAPH_LINE;
    v17 = (float)((float)((float)-100.0 - (float)v15) / (float)((float)v16 - (float)v15));
    if ( v17 >= 0.0 )
    {
      if ( v17 > 1.0 )
        v17 = 1.0;
    }
    else
    {
      v17 = 0.0;
    }
    idDebugGraph::AddGridLine(this: this->graph, value: v17, color: v13);
    v19 = (float)((float)-flt_835AAAA0 / (float)(flt_835AAA9C - flt_835AAAA0));
    if ( v19 >= 0.0 )
    {
      if ( v19 > 1.0 )
        v19 = 1.0;
    }
    else
    {
      v19 = 0.0;
    }
    idDebugGraph::AddGridLine(this: this->graph, value: v19, color: v18);
    v20 = (float)((float)__SPAIR64__(0x82000000, renderSystem->GetWidth(this: renderSystem)) * 0.5);
    v21 = ((int (*)(void))renderSystem->GetWidth)();
    graph = this->graph;
    v23 = (float)__SPAIR64__(&unk_82150000, v21);
    v24 = console;
    graph->position.y = 50.0;
    graph->position.z = v20;
    graph->position.w = 200.0;
    v25 = v24->__vftable;
    graph->position.x = (float)v23 * (float)0.25;
    v27 = (int)v25->CreateGraph(this: v24, a2: 500);
    this->graphSnapRate = (idDebugGraph *)v27;
    *(_DWORD *)(v27 + 36) = 0;
    v28 = (float)((float)((float)16.0 - flt_8369DE80) / (float)(flt_835AAAA4 - flt_8369DE80));
    if ( v28 >= 0.0 )
    {
      if ( v28 > 1.0 )
        v28 = 1.0;
    }
    else
    {
      v28 = 0.0;
    }
    idDebugGraph::AddGridLine(this: this->graphSnapRate, value: v28, color: v26);
    LODWORD(v29) = renderSystem->GetWidth(this: renderSystem);
    v30 = (float)((float)v29 * (float)0.5);
    v31 = __PAIR64__(&unk_821C0000, renderSystem->GetWidth(this: renderSystem));
    graphSnapRate = this->graphSnapRate;
    graphSnapRate->position.y = 300.0;
    graphSnapRate->position.z = v30;
    graphSnapRate->position.w = 200.0;
    graphSnapRate->position.x = (float)v31 * (float)0.25;
  }
  v33 = this->graph;
  if ( !draw )
  {
    v33->enable = false;
    this->graphSnapRate->enable = false;
    return;
  }
  v33->enable = true;
  this->graphSnapRate->enable = false;
  v88.x = 0.0;
  v88.z = 0.0;
  v88.y = 0.0;
  v88.w = 0.69999999;
  v34 = console->Gui(this: console);
  idRenderModelGui::DrawFilled(this: v34, color: &v88, x: 10.0, y: 10.0, w: 1550.0, h: 80.0);
  v89 = 1.0;
  HIDWORD(v35) = this->readSnapshotIndex;
  v90 = 1.0;
  LODWORD(v35) = this->writeSnapshotIndex;
  v91 = 1.0;
  HIDWORD(v36) = &unk_821D0000;
  v92 = 1.0;
  HIDWORD(v37) = HIDWORD(v35) - v35;
  v38 = (unsigned __int8)va::va(
                           this: &v94,
                           fmt: "ss: %d/%d.  (%d)",
                           a3: v35,
                           a4: v37,
                           a5: v36,
                           a6: v62,
                           a7: v66,
                           a8: v70,
                           a9: v74,
                           a10: v78,
                           a11: v82);
  v39 = ((__int64 (__fastcall *)(idConsole *))console->Gui)(a1: console);
  idRenderModelGui::DrawString(
    this: (idRenderModelGui *)HIDWORD(v39),
    x: 20.0,
    y: 20.0,
    string: (const char *)v39,
    defaultColor: (const idVec4 *)&off_82040000,
    forceColor: v38,
    scale: 1.0);
  optimalPCTBuffer = this->optimalPCTBuffer;
  HIDWORD(v40) = LODWORD(optimalPCTBuffer);
  effectiveSnapRate = this->effectiveSnapRate;
  LODWORD(v41) = LODWORD(effectiveSnapRate);
  HIDWORD(v41) = (int)this->optimalTimeBuffered;
  v42 = (unsigned __int8)va::va(
                           this: &v94,
                           fmt: "optimalTimeBuffered: %d effectiveSnapRate:  %.2f  totalBufferedTime: %d totalRecvTime: %d opt"
                           "imalPCTBuffer: %.2f",
                           a3: v41,
                           a4: *(_QWORD *)&this->totalBufferedTime,
                           a5: v40,
                           a6: v63,
                           a7: v67,
                           a8: v71,
                           a9: v75,
                           a10: v79,
                           a11: v83);
  v43 = ((__int64 (__fastcall *)(idConsole *))console->Gui)(a1: console);
  idRenderModelGui::DrawString(
    this: (idRenderModelGui *)HIDWORD(v43),
    x: 20.0,
    y: 35.0,
    string: (const char *)v43,
    defaultColor: (const idVec4 *)&unk_821C0000,
    forceColor: v42,
    scale: 1.0);
  HIDWORD(v44) = snapTimeBuffered;
  v46 = (unsigned __int8)va::va(
                           this: &v94,
                           fmt: "Interpolation time: %d.  Server time: %d.  delta: %d",
                           a3: __SPAIR64__(v12, time),
                           a4: v44,
                           a5: v45,
                           a6: v64,
                           a7: v68,
                           a8: v72,
                           a9: v76,
                           a10: v80,
                           a11: v84);
  v47 = ((__int64 (__fastcall *)(idConsole *))console->Gui)(a1: console);
  idRenderModelGui::DrawString(
    this: (idRenderModelGui *)HIDWORD(v47),
    x: 20.0,
    y: 50.0,
    string: (const char *)v47,
    defaultColor: v48,
    forceColor: v46,
    scale: 1.0);
  *((_QWORD *)&v49 + 1) = this->snapCurrentTime;
  *(_QWORD *)((char *)&v49 + 4) = this->snapRate;
  v50 = &unk_821D0000;
  DWORD1(v49) = this->snapCurrentTime;
  LODWORD(v49) = v49 - DWORD2(v49);
  v52 = (unsigned __int8)va::va(
                           this: &v94,
                           fmt: "snapCurrentTime: %d.  snapRate: %d.  delta: %d",
                           a3: *(__int64 *)((char *)&v49 + 4),
                           a4: *(__int64 *)((char *)&v49 - 4),
                           a5: v51,
                           a6: v65,
                           a7: v69,
                           a8: v73,
                           a9: v77,
                           a10: v81,
                           a11: v85);
  v53 = ((__int64 (__fastcall *)(idConsole *))console->Gui)(a1: console);
  idRenderModelGui::DrawString(
    this: (idRenderModelGui *)HIDWORD(v53),
    x: 20.0,
    y: 65.0,
    string: (const char *)v53,
    defaultColor: v54,
    forceColor: v52,
    scale: 1.0);
  optimalTimeBuffered = this->optimalTimeBuffered;
  v56 = (float)__SPAIR64__(&aAvSsobjectVCom[20], snapTimeBuffered);
  v93 = idColor::colorGreen;
  if ( v56 < optimalTimeBuffered )
  {
    r = idColor::colorRed.r;
    g = idColor::colorRed.g;
    b = idColor::colorRed.b;
    a = idColor::colorRed.a;
LABEL_25:
    v93.r = r;
    v93.g = g;
    v93.b = b;
    v93.a = a;
    goto LABEL_26;
  }
  if ( v56 > (float)(this->optimalTimeBufferedWindow + (float)optimalTimeBuffered) )
  {
    r = idColor::colorYellow.r;
    g = idColor::colorYellow.g;
    b = idColor::colorYellow.b;
    a = idColor::colorYellow.a;
    goto LABEL_25;
  }
LABEL_26:
  v61 = (float)((float)((float)__SPAIR64__(&aAvSsobjectVCom[20], snapTimeBuffered) - flt_835AAAA0)
              / (float)(flt_835AAA9C - flt_835AAAA0));
  if ( v61 >= 0.0 )
  {
    if ( v61 > 1.0 )
      v61 = 1.0;
  }
  else
  {
    v61 = 0.0;
  }
  idDebugGraph::SetValue(this: this->graph, b: -1, value: v61, color: (const idColor *)LODWORD(idColor::colorGreen.g));
}


// ========================================================================
// ?NetReceiveUsercmds@idCommonLocal@@EAAXAAVidBitMsg@@@Z
// EA  : 0x8265B418
// RVA : 0x0065B418
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::NetReceiveUsercmds(idCommonLocal *this, idBitMsg *msg)
{
  idBitMsg *v2; // r22
  char v4; // r19
  idUserCmdMgr *p_userCmdMgr; // r29
  int Bits; // r24
  idBitMsg *v7; // r3
  char v8; // r10
  bool v9; // r22
  unsigned __int8 v10; // r3
  int v11; // r21
  const usercmd_t *v12; // r27
  char v13; // r20
  int v14; // r26
  signed int v15; // r23
  int i; // r25
  const char *v17; // r4
  int clientGameFrame; // r28
  idGame *v19; // r3
  int v20; // r25
  int v21; // r28
  int v22; // r27
  int v23; // r11
  const char *v24; // r3
  int num; // r10
  int v26; // r28
  usercmd_t v27; // [sp+50h] [-2A0h] BYREF
  idCVar *v28; // [sp+8Ch] [-264h]
  const char *v29; // [sp+90h] [-260h]
  const char *v30; // [sp+94h] [-25Ch]
  const char *v31; // [sp+98h] [-258h]
  idMem *v32; // [sp+9Ch] [-254h]
  const char *v33; // [sp+A0h] [-250h]
  const char *v34; // [sp+A4h] [-24Ch]
  const char *v35; // [sp+A8h] [-248h]
  const char *v36; // [sp+ACh] [-244h]
  const char *v37; // [sp+B0h] [-240h]
  const char *v38; // [sp+B4h] [-23Ch]
  _BYTE v39[9]; // [sp+C0h] [-230h] BYREF
  char v40; // [sp+C9h] [-227h]
  __int16 v41; // [sp+CAh] [-226h]
  __int16 v42; // [sp+CCh] [-224h]
  __int16 v43; // [sp+CEh] [-222h]
  int v44; // [sp+D0h] [-220h]
  float v45; // [sp+D4h] [-21Ch]
  float v46; // [sp+D8h] [-218h]
  float v47; // [sp+DCh] [-214h]
  __int16 v48; // [sp+E0h] [-210h]
  __int16 v49; // [sp+E2h] [-20Eh]
  __int16 v50; // [sp+E4h] [-20Ch]
  char v51; // [sp+E6h] [-20Ah]
  int v52; // [sp+E8h] [-208h]
  __int16 v53; // [sp+ECh] [-204h]
  __int16 v54; // [sp+EEh] [-202h]
  __int16 v55; // [sp+F0h] [-200h]
  __int16 v56; // [sp+F2h] [-1FEh]
  __int16 v57; // [sp+F4h] [-1FCh]
  __int16 v58; // [sp+F6h] [-1FAh]
  char v59; // [sp+F8h] [-1F8h]
  char v60; // [sp+F9h] [-1F7h]
  usercmd_t v61; // [sp+100h] [-1F0h] BYREF
  idStaticList<usercmd_t,3> v62; // [sp+140h] [-1B0h] BYREF
  _DWORD v63[16]; // [sp+210h] [-E0h] BYREF

  v2 = msg;
  if ( idBitMsg::ReadBits(this: msg, numBits: 1) != 0 )
  {
    v4 = v40;
    v32 = &mem;
    v29 = "PutUserCmdForPlayer: buffer overflow.\n";
    v30 = "\nSERVER: No commands were newer.\n";
    v28 = &net_ucmd_smoothing_enable;
    v36 = "* %d\n";
    v33 = "^6SERVER: Client input frame out of sequence (GAP)  for user: %i, cur: %i, new: %i\n";
    v37 = "  Received command for frame: %d \n";
    v31 = "%s--------\n";
    v38 = "-";
    p_userCmdMgr = &this->userCmdMgr;
    v34 = "*";
    v35 = "Received commands: %d\n";
    while ( 1 )
    {
      Bits = idBitMsg::ReadBits(this: v2, numBits: 3);
      v8 = _cntlzw(idBitMsg::ReadBits(this: v2, numBits: 1) - 1);
      v7 = v2;
      v9 = (v8 & 0x20) != 0;
      v10 = idBitMsg::ReadBits(this: v7, numBits: 8);
      v11 = v10;
      if ( net_debug_NetSendUsercmds.valueInteger != 0 )
        idLib::Printf(fmt: v35, v10);
      v4 &= 0x3Fu;
      v47 = 0.0;
      v46 = 0.0;
      v45 = 0.0;
      memset(v39, 0, sizeof(v39));
      v61.pos[2] = 0.0;
      v61.pos[1] = 0.0;
      v61.pos[0] = 0.0;
      v12 = (const usercmd_t *)v39;
      v13 = 0;
      v43 = 0;
      v42 = 0;
      v41 = 0;
      v44 = 0;
      v49 = 0;
      v48 = 0;
      v50 = 0;
      v51 = 0;
      v59 = 0;
      v52 = 0;
      v53 = 0;
      v55 = 0;
      v54 = 0;
      v58 = 0;
      v57 = 0;
      v56 = 0;
      v60 = 0;
      memset(&v61, 0, 20);
      v40 = v4;
      *(_DWORD *)&v61.pitch = 0;
      v61.roll = 0;
      v61.predictionStateBits = 0;
      memset(&v61.serverGameTime, 0, 18);
      idStaticList<usercmd_t,3>::idStaticList<usercmd_t,3>(this: &v62);
      v14 = 4 * (Bits + 11520);
      memcpy(
        Dst: v63,
        Src: &p_userCmdMgr->cmdBuffer[(int)(((*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14) == 1)
                                      + ((unsigned int)(*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14)
                                                      - 1) >> 31)
                                      - 1)
                                     & (*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14) - 1))
                               % 128][Bits],
        Size: 0x3Cu);
      v15 = 0;
      for ( i = v63[4]; v15 < v11; ++v15 )
      {
        v27.pos[2] = 0.0;
        v27.pos[1] = 0.0;
        memset(&v27, 0, 9);
        v27.pos[0] = 0.0;
        memset(v27.angles, 0, 10);
        v27.yaw = 0;
        v27.pitch = 0;
        v27.roll = 0;
        v27.predictionStateBits = 0;
        memset(&v27.serverGameTime, 0, 18);
        *((_BYTE *)&v27 + 9) &= 0x3Fu;
        idCommonLocal::ReadUserCmdDelta(this, msg, cmd: &v27, base: v12);
        if ( net_print_ucmds_incoming.valueInteger != 0 )
        {
          v17 = v34;
          if ( v12 != (const usercmd_t *)v39 )
            v17 = v38;
          idLib::Printf(fmt: v31, v17);
          usercmd_t::Print(this: &v27);
        }
        v61 = v27;
        v12 = &v61;
        clientGameFrame = v27.clientGameFrame;
        if ( net_debug_NetSendUsercmds.valueInteger != 0 )
          idLib::Printf(fmt: v37);
        if ( clientGameFrame > i )
        {
          if ( clientGameFrame != i + 1 && clientGameFrame > 10 && i > 10 )
            idLib::Printf(fmt: v33, Bits, i, clientGameFrame);
          if ( net_print_ucmds_incoming.valueInteger != 0 )
            idLib::Printf(fmt: v36, v27.clientGameFrame);
          if ( (((v15 >= 0) + ((unsigned int)v15 >= 3)) & 1) != 0 )
          {
            idList<usercmd_t,5>::Append(this: &v62, obj: &v27);
            v13 = 1;
            i = clientGameFrame;
          }
        }
      }
      if ( v28->valueInteger != 0 && v9 && v62.num > 1 )
      {
        v19 = this->Game(this);
        v19->SmoothIncomingUserCmds(this: v19, a2: (usercmd_t *)v63, a3: v62.list, a4: v62.num);
      }
      v20 = 0;
      if ( v62.num > 0 )
      {
        v21 = 0;
        v22 = 4 * (Bits + 11526);
        do
        {
          memcpy(
            Dst: &p_userCmdMgr->cmdBuffer[*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14) % 128][Bits],
            Src: &v62.list[v21],
            Size: sizeof(p_userCmdMgr->cmdBuffer[*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14) % 128][Bits]));
          v23 = *(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14);
          if ( v23 - *(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v22) + 1 > 128 )
          {
            v24 = v29;
            *(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v22) = v23 - 64;
            idLib::Printf(fmt: v24);
          }
          ++v20;
          num = v62.num;
          ++v21;
          ++*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14);
        }
        while ( v20 < num );
      }
      if ( v11 > 0 && v13 == 0 )
      {
        v26 = 4 * (Bits + 18126);
        if ( *(int *)((char *)&this->__vftable + v26) > 1 )
        {
          idLib::Printf(fmt: v30);
          idLib::Printf(
            fmt: "usercmdMgr readFrame: %d writeFrame: %d \n",
            this->userCmdMgr.readFrame[Bits],
            *(idCommonLocal_vtbl **)((char *)&this->__vftable + v26));
          idLib::Printf(
            fmt: "HasUserCmdForPlayer: %d \n",
            ((((*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons + v14) - 1) ^ p_userCmdMgr->readFrame[Bits]) >= 0)
           + (p_userCmdMgr->readFrame[Bits] >= (unsigned int)(*(int *)((char *)&p_userCmdMgr->cmdBuffer[0][0].buttons
                                                                     + v14)
                                                            - 1)))
          & 1);
        }
      }
      if ( v62.listStatic == 0 || v62.listStatic == 2 )
      {
        if ( v62.list != nullptr )
          idMem::Free(this: v32, ptr: v62.list, align: ALIGN_16);
        v62.list = nullptr;
        v62.size = 0;
      }
      v62.num = 0;
      if ( idBitMsg::ReadBits(this: msg, numBits: 1) == 0 )
        break;
      v2 = msg;
    }
  }
}


// ========================================================================
// __unwind$224067
// EA  : 0x8265B9E8
// RVA : 0x0065B9E8
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void _unwind_224067()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 752 + 320));
}


// ========================================================================
// ?ProcessSnapshot@idCommonLocal@@AAAXAAVidSnapShot@@@Z
// EA  : 0x8265BA10
// RVA : 0x0065BA10
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::ProcessSnapshot(idCommonLocal *this, idSnapShot *ss)
{
  int v4; // r28
  unsigned __int64 v5; // r4
  int time; // r6
  int serverTime; // r11
  unsigned __int64 v8; // r28
  idArray<gameReturnPlayer_t,6> *p_players; // r24
  int ObjectIndexByID; // r3
  idConsole_vtbl *v11; // r29
  int v12; // r30
  int v13; // r3
  idGame *v14; // r3
  int v15; // r29
  idGame *v16; // r3
  idGame *v17; // r3
  idGame *v18; // r3
  int v19; // r3
  idGame *v20; // r3
  int v21; // r3
  idGame *v22; // r3
  unsigned __int64 v23; // r9
  idSerializer v24; // [sp+50h] [-A0h] BYREF
  idBitMsg v25; // [sp+60h] [-90h] BYREF

  v4 = Sys_Milliseconds();
  this->snapPrevious.localTime = this->snapCurrent.localTime;
  this->snapPrevious.serverTime = this->snapCurrent.serverTime;
  this->snapPrevious.forceOneView = this->snapCurrent.forceOneView;
  idArray<gameReturnPlayer_t,6>::operator=(this: &this->snapPrevious.players, __that: &this->snapCurrent.players);
  HIDWORD(v5) = idStaticList<idRenderModelGui *,8>::operator=(
                  this: &this->snapPrevious.debugGuis,
                  __that: (const idList<idMD6Node *,5> *)&this->snapCurrent.debugGuis);
  time = ss->time;
  serverTime = this->snapPrevious.serverTime;
  LODWORD(v5) = time - serverTime;
  this->snapCurrent.serverTime = time;
  this->snapRate = v5;
  if ( net_debug_snapShotTime.valueInteger != 0 )
    idLib::Printf(
      fmt: "^2ProcessSnapshot. delta serverTime: %d  delta localTime: %d \n",
      time - serverTime,
      v4 - lastReceivedLocalTime);
  lastReceivedLocalTime = v4;
  console->ClearSnapshots(this: console);
  v8 = 0;
  p_players = &this->snapCurrent.players;
  do
  {
    memset(&v25, 0, 30);
    v25.tempValue = v8;
    ObjectIndexByID = idSnapShot::FindObjectIndexByID(this: ss, objectNum: SHIDWORD(v8));
    if ( idSnapShot::GetObjectMsgByIndex(this: ss, i: ObjectIndexByID, msg: &v25, ignoreIfStale: false) == HIDWORD(v8) )
    {
      if ( (v25.writeBit != 0) + v25.curSize != 0 )
      {
        v24.writing = false;
        v24.msg = &v25;
        idCommonLocal::SerializePlayer(this, ser: &v24, player: p_players->ptr);
        p_players->ptr[0].valid = true;
        if ( com_drawSnapshots.valueInteger == 3 )
        {
          v11 = console->__vftable;
          v12 = (v25.writeBit != 0) + v25.curSize;
          v13 = idSnapShot::CompareObject(
                  this: ss,
                  oldss: &this->oldss,
                  objectNum: SHIDWORD(v8),
                  start: 0,
                  end: 0,
                  oldStart: 0);
          v11->AddSnapObject(this: console, a2: "players", a3: v12, a4: v13, a5: 0.0);
        }
      }
      else
      {
        p_players->ptr[0].valid = false;
      }
    }
    ++HIDWORD(v8);
    p_players = (idArray<gameReturnPlayer_t,6> *)((char *)p_players + 1952);
  }
  while ( SHIDWORD(v8) < 6 );
  v14 = this->Game(this);
  v15 = v14->GetServerGameTimeMs(this: v14);
  v16 = this->Game(this);
  v16->SetServerGameTimeMs(this: v16, a2: this->snapCurrent.serverTime);
  v17 = this->Game(this);
  v17->ReadFromSnapshot(this: v17, a2: ss, a3: &this->oldss);
  v18 = this->Game(this);
  v19 = (int)v18->GetRenderWorld(this: v18);
  (*(void (__fastcall **)(int, idSnapShot *, idSnapShot *))(*(_DWORD *)v19 + 164))(a1: v19, a2: ss, a3: &this->oldss);
  v20 = this->Game(this);
  v21 = (int)v20->GetSoundWorld(this: v20);
  (*(void (__fastcall **)(int, idSnapShot *, idSnapShot *))(*(_DWORD *)v21 + 96))(a1: v21, a2: ss, a3: &this->oldss);
  v22 = this->Game(this);
  v22->SetServerGameTimeMs(this: v22, a2: v15);
  LODWORD(v23) = ss->recvTime - this->oldss.recvTime;
  this->snapTimeDelta = v23;
  idSnapShot::operator=(this: &this->oldss, other: ss);
}


// ========================================================================
// ?ProcessNextSnapshot@idCommonLocal@@AAAXXZ
// EA  : 0x8265BD48
// RVA : 0x0065BD48
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::ProcessNextSnapshot(idCommonLocal *this)
{
  int readSnapshotIndex; // r11

  readSnapshotIndex = this->readSnapshotIndex;
  if ( readSnapshotIndex == this->writeSnapshotIndex )
  {
    idLib::Printf(fmt: "No snapshots to process.\n");
  }
  else
  {
    idCommonLocal::ProcessSnapshot(this, ss: &this->receivedSnaps.ptr[readSnapshotIndex % 16]);
    ++this->readSnapshotIndex;
  }
}


// ========================================================================
// ?NetReceiveSnapshot@idCommonLocal@@EAAXAAVidSnapShot@@@Z
// EA  : 0x8265BDD0
// RVA : 0x0065BDD0
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __fastcall idCommonLocal::NetReceiveSnapshot(idCommonLocal *this, idSnapShot *ss)
{
  int writeSnapshotIndex; // r5
  int readSnapshotIndex; // r4
  int v6; // r5

  ss->recvTime = Sys_Milliseconds();
  writeSnapshotIndex = this->writeSnapshotIndex;
  readSnapshotIndex = this->readSnapshotIndex;
  if ( writeSnapshotIndex - readSnapshotIndex >= 16 )
  {
    idLib::Printf(fmt: "Overwritting oldest snapshot %d with new snapshot %d\n", readSnapshotIndex, writeSnapshotIndex);
    idCommonLocal::ProcessNextSnapshot(this);
  }
  idSnapShot::operator=(this: &this->receivedSnaps.ptr[this->writeSnapshotIndex % 16], other: ss);
  v6 = this->readSnapshotIndex;
  ++this->writeSnapshotIndex;
  if ( v6 < 2 )
    idCommonLocal::ProcessNextSnapshot(this);
}


// ========================================================================
// `dynamic initializer for 'net_debug_NetSendUsercmds''
// EA  : 0x83339E10
// RVA : 0x01339E10
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_debug_NetSendUsercmds__()
{
  idCVar::idCVar(
    this: &net_debug_NetSendUsercmds,
    name: "net_debug_NetSendUsercmds",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_debug_NetSendUsercmds__);
}


// ========================================================================
// `dynamic initializer for 'net_debug_snapShotTime''
// EA  : 0x83339E68
// RVA : 0x01339E68
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_debug_snapShotTime__()
{
  idCVar::idCVar(
    this: &net_debug_snapShotTime,
    name: "net_debug_snapShotTime",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_debug_snapShotTime__);
}


// ========================================================================
// `dynamic initializer for 'net_userCmdRate''
// EA  : 0x83339EC0
// RVA : 0x01339EC0
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_userCmdRate__()
{
  idCVar::idCVar(
    this: &net_userCmdRate,
    name: "net_userCmdRate",
    value: "4",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_userCmdRate__);
}


// ========================================================================
// `dynamic initializer for 'net_print_ucmds_outgoing''
// EA  : 0x83339F18
// RVA : 0x01339F18
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_print_ucmds_outgoing__()
{
  idCVar::idCVar(
    this: &net_print_ucmds_outgoing,
    name: "net_print_ucmds_outgoing",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_print_ucmds_outgoing__);
}


// ========================================================================
// `dynamic initializer for 'net_print_ucmds_incoming''
// EA  : 0x83339F70
// RVA : 0x01339F70
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_print_ucmds_incoming__()
{
  idCVar::idCVar(
    this: &net_print_ucmds_incoming,
    name: "net_print_ucmds_incoming",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_print_ucmds_incoming__);
}


// ========================================================================
// `dynamic initializer for 'net_ucmd_smoothing_enable''
// EA  : 0x83339FC8
// RVA : 0x01339FC8
// PDB : w:\tech5\engine\framework\common_network.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_ucmd_smoothing_enable__()
{
  idCVar::idCVar(
    this: &net_ucmd_smoothing_enable,
    name: "net_ucmd_smoothing_enable",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_ucmd_smoothing_enable__);
}

