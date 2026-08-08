
// ========================================================================
// ?Destroy@ssDebugUtil@@UAAXXZ
// EA  : 0x82EEAFA0
// RVA : 0x00EEAFA0
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void __fastcall ssDebugUtil::Destroy(ssDebugUtil *this)
{
  gameInterface->TerminateThread_2(this: gameInterface, a2: this->debugActionsThreadId);
  this->debugActionsThreadId = 0;
}


// ========================================================================
// ?ReadDebugActions@ssDebugUtil@@QAAXXZ
// EA  : 0x82EEB258
// RVA : 0x00EEB258
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void __fastcall __noreturn ssDebugUtil::ReadDebugActions(ssDebugUtil *this)
{
  idGameSuperInterface *v1; // r11
  sflEntry_t *v2; // r3
  int v3; // r9
  char v4; // r11
  __int64 v5; // r9
  double v6; // fp30
  ssEntity *Angles; // r30
  ssEntity *WorldOrigin; // r24
  ssEntity *Maxs; // r23
  ssEntity *Mins; // r3
  int i; // r30
  char *v12; // r3
  idStreamFileLog v13; // [sp+50h] [-110h] BYREF
  ssString v14; // [sp+80h] [-E0h] BYREF
  __int64 v15; // [sp+90h] [-D0h]
  ssString v16; // [sp+A0h] [-C0h] BYREF
  ssString v17; // [sp+B0h] [-B0h] BYREF
  ssEntity v18; // [sp+C0h] [-A0h] BYREF
  ssEntity v19; // [sp+D0h] [-90h] BYREF
  ssEntity v20; // [sp+E0h] [-80h] BYREF
  ssEntity v21; // [sp+F0h] [-70h] BYREF

  memset(v13.driveState, 0, sizeof(v13.driveState));
  v1 = gameInterface;
  if ( gameInterface != nullptr )
  {
    v2 = (sflEntry_t *)gameInterface->GetAllocThread(this: gameInterface);
    v1 = gameInterface;
    v13.currentEntry[0] = v2;
  }
  else
  {
    v13.currentEntry[0] = nullptr;
  }
  while ( 1 )
  {
    v1->WaitFrame(this: v1);
    idMD6PhaseTrack::idMD6PhaseTrack(this: &v13);
    if ( v13.numEntries == 0
      || (v3 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
          v4 = 1,
          v3 == 0) )
    {
      v4 = 0;
    }
    if ( v4 != 0 )
    {
      LODWORD(v5) = gameInterface->GetFrameTime(this: gameInterface);
      v15 = v5;
      v6 = (float)((float)v5 * (float)0.001);
      Angles = ssEntity::GetAngles(this: &v20, result: (ssString *)&v13);
      WorldOrigin = ssEntity::GetWorldOrigin(this: &v19, result: (ssString *)&v13);
      Maxs = ssEntity::GetMaxs(this: &v21, result: (ssString *)&v13);
      Mins = ssEntity::GetMins(this: &v18, result: (ssString *)&v13);
      gameInterface->DebugOrientedBounds(
        this: gameInterface,
        a2: (const ssVec3_t *)&ssUtil::RED,
        a3: (const ssVec3_t *)Mins,
        a4: (const ssVec3_t *)Maxs,
        a5: (const ssVec3_t *)WorldOrigin,
        a6: (const ssVec3_t *)Angles,
        a7: v6);
    }
    cvarString_::operator ssString(this: (cvarString_ *)&v17, result: (ssString *)&ss_debugAction);
    ssString::Init(this: (ssString *)&v13.currentEntry[1]);
    ssString::operator=(this: (ssString *)&v13.currentEntry[1], text: &v17);
    ssString::Empty(this: &v17);
    if ( ssString::Cmp(this: (ssString *)&v13.currentEntry[1], text: "idle") != 0 )
    {
      ssString::ToLower(this: (ssString *)&v13.currentEntry[1]);
      ssList<ssString>::Clear(this: (ssList<ssString> *)v13.driveState);
      ssString::Init(this: &v14);
      for ( i = 0; i < (int)v13.currentEntry[1]; ++i )
      {
        if ( *ssString::operator[](this: (ssString *)&v13.currentEntry[1], index: i) == 32 )
        {
          if ( v14.len > 0 )
          {
            ssList<ssString>::Insert(this: (ssList<ssString> *)v13.driveState, element: &v14, index: v13.driveState[1]);
            ssString::Empty(this: &v14);
          }
        }
        else
        {
          v12 = ssString::operator[](this: (ssString *)&v13.currentEntry[1], index: i);
          ssString::Append(this: &v14, a: *v12);
        }
      }
      if ( v14.len > 0 )
      {
        ssList<ssString>::Insert(this: (ssList<ssString> *)v13.driveState, element: &v14, index: v13.driveState[1]);
        ssString::Empty(this: &v14);
      }
      ssString::Init(this: &v16);
      ssString::operator=(this: &v16, text: "idle");
      gameInterface->SetCVarString(this: gameInterface, a2: ss_debugAction.name, a3: v16.data);
      ssString::Empty(this: &v16);
      ssString::Empty(this: &v14);
      ssString::Empty(this: (ssString *)&v13.currentEntry[1]);
      v1 = gameInterface;
    }
    else
    {
      ssString::Empty(this: (ssString *)&v13.currentEntry[1]);
      v1 = gameInterface;
    }
  }
}


// ========================================================================
// __unwind$19954
// EA  : 0x82EEB51C
// RVA : 0x00EEB51C
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_19954()
{
  int v0; // r12

  ssList<ssString>::~ssList<ssString>(this: (ssList<ssString> *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$19955
// EA  : 0x82EEB544
// RVA : 0x00EEB544
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_19955()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 352 + 176));
}


// ========================================================================
// __unwind$19956
// EA  : 0x82EEB56C
// RVA : 0x00EEB56C
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_19956()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$19957
// EA  : 0x82EEB594
// RVA : 0x00EEB594
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_19957()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$19958
// EA  : 0x82EEB5BC
// RVA : 0x00EEB5BC
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_19958()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 352 + 160));
}


// ========================================================================
// ?Init@ssDebugUtil@@UAAXXZ
// EA  : 0x82EEB5F0
// RVA : 0x00EEB5F0
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void __fastcall ssDebugUtil::Init(ssDebugUtil *this)
{
  ssEntity v2; // [sp+50h] [-50h] BYREF
  ssString v3; // [sp+60h] [-40h] BYREF
  ssString v4; // [sp+70h] [-30h] BYREF

  if ( this->self.spawnId == ssEntity::ssEntity(this: &v2, name: "world")->spawnId )
  {
    ssString::Init(this: &v4);
    ssString::operator=(this: &v4, text: "ReadDebugActions");
    this->debugActionsThreadId = idSuperScriptObject::CreateThreadNamed(
                                   this,
                                   threadName: &v4,
                                   f: ssDebugUtil::ReadDebugActions);
  }
  else
  {
    ssString::Init(this: &v3);
    ssString::operator=(this: &v3, text: "ssDebugUtil should only be placed on the world ssEntity (worldspawn).");
    Error(msg: &v3);
    ssString::Empty(this: &v3);
  }
}


// ========================================================================
// __unwind$20124
// EA  : 0x82EEB6A0
// RVA : 0x00EEB6A0
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _unwind_20124()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// `dynamic initializer for 'ss_debugAction''
// EA  : 0x83393D70
// RVA : 0x01393D70
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _dynamic_initializer_for__ss_debugAction__()
{
  if ( gameInterface != nullptr )
  {
    cvarString_::RegisterCVar(this: &ss_debugAction);
  }
  else
  {
    ss_debugAction.nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = &ss_debugAction;
  }
}


// ========================================================================
// `dynamic initializer for 'ss_debugPlayerPos''
// EA  : 0x83393DB8
// RVA : 0x01393DB8
// PDB : w:\tech5\tungsten\superscript\shared\debugutil.cpp
// ========================================================================

void _dynamic_initializer_for__ss_debugPlayerPos__()
{
  if ( gameInterface != nullptr )
  {
    cvarString_::RegisterCVar(this: &ss_debugPlayerPos);
  }
  else
  {
    ss_debugPlayerPos.nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = &ss_debugPlayerPos;
  }
}

