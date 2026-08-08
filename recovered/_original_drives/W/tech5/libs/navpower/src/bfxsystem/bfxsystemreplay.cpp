
// ========================================================================
// ?LogEnableBatchProbeProcessing@bfx@@YAX_N@Z
// EA  : 0x8326D6E0
// RVA : 0x0126D6E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableBatchProbeProcessing(BOOL enable)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 0,
         comment: "EnableBatchProbeProcessing",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_7(this: v2, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogGetProbeRequests@bfx@@YAXH@Z
// EA  : 0x8326D768
// RVA : 0x0126D768
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogGetProbeRequests(int arraySize)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 1u,
         comment: "GetProbeRequests",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_12(this: v2, a2: "arraySize", a3: arraySize);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogSupplyProbeResults@bfx@@YAXPAVProbeRequest@1@H@Z
// EA  : 0x8326D7F0
// RVA : 0x0126D7F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogSupplyProbeResults(bfx::ProbeRequest *pProbeRequestArray, int numRequests)
{
  bfx::ReplayLogOut *v4; // r3
  bfx::ReplayLogOut *v5; // r31
  bfx::Vector3 *p_m_endPos; // r30

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 2u,
         comment: "SupplyProbeResults",
         version: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->WriteAttrib_12(this: v4, a2: "numRequests", a3: numRequests);
    if ( numRequests > 0 )
    {
      p_m_endPos = &pProbeRequestArray->m_endPos;
      do
      {
        v5->PushElement(this: v5, a2: "ProbeRequest");
        v5->PushElement(this: v5, a2: "CollideData");
        v5->WriteAttrib_8(
          this: v5,
          a2: (const char *)LODWORD(p_m_endPos[-2].m_y),
          a3: LODWORD(p_m_endPos[-2].m_z),
          a4: FMT_DEC);
        v5->PopElement(this: v5);
        v5->WriteAttrib_5(this: v5, a2: "m_startPos", a3: p_m_endPos - 1);
        v5->WriteAttrib_5(this: v5, a2: "m_endPos", a3: p_m_endPos);
        v5->WriteAttrib_7(this: v5, a2: "m_collided", a3: HIBYTE(p_m_endPos[1].m_x));
        v5->WriteAttrib_5(this: v5, a2: "m_collidePos", a3: (bfx::Vector3 *)((char *)p_m_endPos + 16));
        v5->WriteAttrib_12(this: v5, a2: "m_requestID", a3: LODWORD(p_m_endPos[2].m_y));
        v5->PopElement(this: v5);
        --numRequests;
        p_m_endPos = (bfx::Vector3 *)((char *)p_m_endPos + 56);
      }
      while ( numRequests != 0 );
    }
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogAddResource@bfx@@YAXAAVSpaceHandle@1@PBDABVResourceOffset@1@@Z
// EA  : 0x8326D9C0
// RVA : 0x0126D9C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogAddResource(
        bfx::SpaceHandle *spaceHandle,
        const char *pBinaryImage,
        const bfx::ResourceOffset *offset)
{
  bfx::ReplayLogOut *v6; // r31
  unsigned int SpaceID; // r3
  int ImageSize; // r29

  v6 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 3u,
         comment: "AddResource",
         version: 0);
  if ( v6 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v6->WriteAttrib_9(this: v6, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v6->WriteAttrib_5(this: v6, a2: "position_offset", a3: &offset->m_positionOffset);
    v6->WriteAttrib_4(this: v6, a2: "rotation_offset", a3: &offset->m_rotationOffset);
    v6->WriteAttrib_12(this: v6, a2: "layer_offset", a3: offset->m_layerOffset);
    v6->WriteAttrib_9(this: v6, a2: "image_ptr", a3: (unsigned int)pBinaryImage, a4: FMT_HEX);
    ImageSize = bfx::BinaryImageIn::GetImageSize(pBinaryImage);
    v6->WriteAttrib_9(this: v6, a2: "image_size", a3: ImageSize, a4: FMT_DEC);
    v6->WriteBinary(this: v6, a2: pBinaryImage, a3: ImageSize);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogRemoveResource@bfx@@YAXAAVSpaceHandle@1@PBD@Z
// EA  : 0x8326DB18
// RVA : 0x0126DB18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogRemoveResource(bfx::SpaceHandle *spaceHandle, const char *pBinaryImage)
{
  bfx::ReplayLogOut *v4; // r31
  unsigned int SpaceID; // r3

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 4u,
         comment: "RemoveResource",
         version: 0);
  if ( v4 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v4->WriteAttrib_9(this: v4, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v4->WriteAttrib_9(this: v4, a2: "image_ptr", a3: (unsigned int)pBinaryImage, a4: FMT_HEX);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCoreSystemSimulate@bfx@@YAXM@Z
// EA  : 0x8326DBC0
// RVA : 0x0126DBC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogCoreSystemSimulate(double simTime)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 6u,
         comment: "CoreSystemSimulate",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_6(this: v2, a2: "simTime", a3: simTime);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogSystemSimulate@bfx@@YAXM@Z
// EA  : 0x8326DC48
// RVA : 0x0126DC48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogSystemSimulate(double simTime)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 7u,
         comment: "SystemSimulate",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_6(this: v2, a2: "simTime", a3: simTime);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogSystemDraw@bfx@@YAXPBVDrawCullParams@1@@Z
// EA  : 0x8326DCD0
// RVA : 0x0126DCD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogSystemDraw(const bfx::DrawCullParams *pDrawCullParams)
{
  bfx::ReplayLogOut *v2; // r3
  bfx::ReplayLogOut *v3; // r31

  if ( pDrawCullParams != nullptr )
  {
    v2 = bfx::ReplayRecorder::OpenLogEvent(
           this: bfx::g_pCurInstance->m_pReplayRecorder,
           componentID: COMPONENTID_SYSTEM,
           eventID: 8u,
           comment: "SystemDraw",
           version: 0);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v2->WriteAttrib_5(this: v2, a2: "m_cameraPos", a3: &pDrawCullParams->m_cameraPos);
      v3->WriteAttrib_5(this: v3, a2: "m_cameraDir", a3: &pDrawCullParams->m_cameraDir);
      v3->WriteAttrib_6(this: v3, a2: "m_farClipDist", a3: pDrawCullParams->m_farClipDist);
      v3->WriteAttrib_6(this: v3, a2: "m_fov", a3: pDrawCullParams->m_fov);
      bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
    }
  }
}


// ========================================================================
// ?LogSpaceHandleSetPos@bfx@@YAXAAVSpaceHandle@1@ABVVector3@1@@Z
// EA  : 0x8326DDA8
// RVA : 0x0126DDA8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogSpaceHandleSetPos(bfx::SpaceHandle *spaceHandle, const bfx::Vector3 *pos)
{
  bfx::ReplayLogOut *v4; // r31
  unsigned int SpaceID; // r3

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 9u,
         comment: "SpaceHandle::SetPos",
         version: 0);
  if ( v4 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v4->WriteAttrib_9(this: v4, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v4->WriteAttrib_5(this: v4, a2: "pos", a3: pos);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogSpaceHandleSetRot@bfx@@YAXAAVSpaceHandle@1@ABVQuaternion@1@@Z
// EA  : 0x8326DE50
// RVA : 0x0126DE50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogSpaceHandleSetRot(bfx::SpaceHandle *spaceHandle, const bfx::Quaternion *rot)
{
  bfx::ReplayLogOut *v4; // r31
  unsigned int SpaceID; // r3

  v4 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 0xAu,
         comment: "SpaceHandle::SetRot",
         version: 0);
  if ( v4 != nullptr )
  {
    SpaceID = bfx::GetSpaceID(space: spaceHandle);
    v4->WriteAttrib_9(this: v4, a2: "spaceID", a3: SpaceID, a4: FMT_DEC);
    v4->WriteAttrib_4(this: v4, a2: "rot", a3: rot);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogCreateSpace@bfx@@YAXI@Z
// EA  : 0x8326DEF8
// RVA : 0x0126DEF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogCreateSpace(unsigned int spaceID)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 0xDu,
         comment: "CreateSpace",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_9(this: v2, a2: "spaceID", a3: spaceID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogDestroySpace@bfx@@YAXI@Z
// EA  : 0x8326DF80
// RVA : 0x0126DF80
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogDestroySpace(unsigned int spaceID)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 0xEu,
         comment: "DestroySpace",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_9(this: v2, a2: "spaceID", a3: spaceID, a4: FMT_DEC);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?LogEnableAsyncSimulation@bfx@@YAX_N@Z
// EA  : 0x8326E008
// RVA : 0x0126E008
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void __fastcall bfx::LogEnableAsyncSimulation(BOOL enable)
{
  bfx::ReplayLogOut *v2; // r3

  v2 = bfx::ReplayRecorder::OpenLogEvent(
         this: bfx::g_pCurInstance->m_pReplayRecorder,
         componentID: COMPONENTID_SYSTEM,
         eventID: 0x11u,
         comment: "EnableAsyncSimulation",
         version: 0);
  if ( v2 != nullptr )
  {
    v2->WriteAttrib_7(this: v2, a2: "enable", a3: enable);
    bfx::ReplayRecorder::CloseLogEvent(this: bfx::g_pCurInstance->m_pReplayRecorder);
  }
}


// ========================================================================
// ?GetSpace@bfx@@YAAAVSpaceHandle@1@I@Z
// EA  : 0x8326E098
// RVA : 0x0126E098
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::GetSpace(void (__fastcall *spaceID)(bfx::SystemReplayManager *this))
{
  bfx::SpaceHandle *DefaultSpaceHandle; // r3
  int v4; // r10
  bfx::SystemReplayManager *m_pSystemReplayManager; // r11
  bfx::SystemReplayManager_vtbl *v6; // r8
  int v7; // r11
  int v8; // [sp+50h] [-30h]

  if ( spaceID == (void (__fastcall *)(bfx::SystemReplayManager *))-1 )
    return bfx::SystemInstance::GetInvalidSpaceHandle(this: bfx::g_pCurInstance);
  DefaultSpaceHandle = bfx::SystemInstance::GetDefaultSpaceHandle(this: bfx::g_pCurInstance);
  if ( (void (__fastcall *)(bfx::SystemReplayManager *))bfx::GetVolume(spaceHandle: DefaultSpaceHandle)->m_spaceID == spaceID )
    return bfx::SystemInstance::GetDefaultSpaceHandle(this: bfx::g_pCurInstance);
  v4 = 0;
  m_pSystemReplayManager = bfx::g_pCurInstance->m_pSystemReplayManager;
  v8 = (int)m_pSystemReplayManager[3].__vftable;
  if ( v8 <= 0 )
  {
LABEL_9:
    if ( (_S1_1 & 1) == 0 )
    {
      _S1_1 |= 1u;
      bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &s_invalidSpaceHandle);
      atexit(func: (void (__fastcall *)())_bfx::GetSpace_::_10_::_dynamic_atexit_destructor_for__s_invalidSpaceHandle__);
    }
    return &s_invalidSpaceHandle;
  }
  else
  {
    v6 = m_pSystemReplayManager[2].__vftable;
    v7 = 0;
    while ( v6[v7].dtr_SystemReplayManager != spaceID )
    {
      ++v4;
      v7 += 2;
      if ( v4 >= v8 )
        goto LABEL_9;
    }
    return (bfx::SpaceHandle *)&v6[2 * v4 + 1];
  }
}


// ========================================================================
// __unwind$15988
// EA  : 0x8326E180
// RVA : 0x0126E180
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemreplay.cpp
// ========================================================================

void _unwind_15988()
{
  _S1_1 &= ~1u;
}

