
// ========================================================================
// ?DeleteSelected_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E505F8
// RVA : 0x00E505F8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall DeleteSelected_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
    idDragEntity::DeleteSelected(this: &v2->dragEntity);
}


// ========================================================================
// ?jobGUI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50660
// RVA : 0x00E50660
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall jobGUI_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    idPlayer::ForceFistUp(this: DebugPlayer);
    idPlayer::LaunchDebugJobGui(this: v2);
  }
  else
  {
    idLib::Printf(fmt: "jobGUI couldn't find player\n");
  }
}


// ========================================================================
// ?playtestGUI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E506D0
// RVA : 0x00E506D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall playtestGUI_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
    idPlayer::LaunchPlayTestGui(this: DebugPlayer);
  else
    idLib::Printf(fmt: "playtestgui couldn't find player\n");
}


// ========================================================================
// ?playtest_SaveAndClear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50720
// RVA : 0x00E50720
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall playtest_SaveAndClear_f(const idCmdArgs *args)
{
  if ( gameLocal != nullptr )
    gameLocal->Playtest_SaveAndClear(this: gameLocal);
}


// ========================================================================
// ?playtest_SaveNoClear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50748
// RVA : 0x00E50748
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall playtest_SaveNoClear_f(const idCmdArgs *args)
{
  if ( gameLocal != nullptr )
    gameLocal->Playtest_SaveNoClear(this: gameLocal);
}


// ========================================================================
// ?StepParticleTime_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E508D0
// RVA : 0x00E508D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall StepParticleTime_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r25
  idRenderWorld *v4; // r29
  int i; // r26
  idRenderModel *v6; // r3
  idRenderModel *v7; // r3
  idRenderModel *v8; // r31
  const idDeclRenderParm *TimeOffset; // r22
  idStaticParmBlock<32> *ParmBlock; // r3
  __int64 v11; // r10

  if ( args->argc >= 2 )
  {
    idCVar::SetBool(this: &g_stopTime, newValue: true, force: true);
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atol(nptr: v2);
    v4 = gameLocal->GetRenderWorld(this: gameLocal);
    for ( i = 0; i < v4->GetNumRenderModels(this: v4); ++i )
    {
      v6 = v4->RenderModelForIndex(this: v4, a2: i);
      v7 = (idRenderModel *)_RTDynamicCast(
                              inptr: v6,
                              VfDelta: 0,
                              SrcType: &idRenderModel `RTTI Type Descriptor',
                              TargetType: &idRenderModelParticle `RTTI Type Descriptor',
                              isReference: 0);
      v8 = v7;
      if ( v7 != nullptr )
      {
        idRenderModel::SetParm(this: v7, parm: rp->TimeStop, scalar: 0.0);
        TimeOffset = rp->TimeOffset;
        ParmBlock = idRenderModel::GetParmBlock(this: v8);
        LODWORD(v11) = (int)(float)(1000.0 * idParmBlock::GetFloat(this: ParmBlock, parm: TimeOffset)) + v3;
        idRenderModel::SetParm(this: v8, parm: rp->TimeOffset, scalar: (float)((float)v11 * (float)0.001));
        idRenderModel::CommitThisFrame(this: v8);
      }
    }
  }
  else if ( args->argc <= 0 )
  {
    idLib::Printf(fmt: "Syntax: %s <deltaTime>\n", &byte_8200D768);
  }
  else
  {
    idLib::Printf(fmt: "Syntax: %s <deltaTime>\n", args->argv[0]);
  }
}


// ========================================================================
// ?ReloadParticles_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50AA8
// RVA : 0x00E50AA8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ReloadParticles_f(const idCmdArgs *args)
{
  idGame *v1; // r3
  int i; // r30
  idGameLocal *v3; // r29
  idEntityInterface *iface; // r11
  bool v5; // r3
  idGame *v6; // r3
  idGame *v7; // r3
  idGame *v8; // r3
  idEntityInterfaceObject v9[8]; // [sp+50h] [-40h] BYREF

  ++idResourceList::staleCount;
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "reloadDecls");
  v1 = common->Game(this: common);
  for ( i = (int)v1->FindEntityUsingClass(this: v1, a2: nullptr, a3: "idParticleEmitter");
        i != 0;
        i = (int)v8->FindEntityUsingClass(this: v8, a2: (idEntity *)i, a3: "idParticleEmitter") )
  {
    v3 = (idGameLocal *)common->Game(this: common);
    idGameLock::idGameLock(this: &v9[0].lock, newGame: v3);
    v9[0].iface = nullptr;
    iface = v3->AllocEntityInterface(this: v3, a2: (idEntity *)i);
    v9[0].iface = iface;
    if ( iface != nullptr )
    {
      v5 = iface->IsValid(this: iface);
      iface = v9[0].iface;
    }
    else
    {
      v5 = false;
    }
    if ( v5 && iface->GetTypeInfoObject(this: iface) != nullptr )
    {
      v6 = common->Game(this: common);
      v6->EntityUpdateModifiedProperties(this: v6, a2: (idEntity *)i);
      v7 = common->Game(this: common);
      v7->EntityUpdateVisuals(this: v7, a2: (idEntity *)i);
    }
    idEntityInterfaceObject::~idEntityInterfaceObject(this: v9);
    v8 = common->Game(this: common);
  }
}


// ========================================================================
// __unwind$493949_0
// EA  : 0x82E50C68
// RVA : 0x00E50C68
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_493949_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$493944
// EA  : 0x82E50C90
// RVA : 0x00E50C90
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_493944()
{
  int v0; // r12

  idEntityInterfaceObject::~idEntityInterfaceObject(this: (idEntityInterfaceObject *)(v0 - 144 + 80));
}


// ========================================================================
// ?TestPlayerViewParticle_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50CB8
// RVA : 0x00E50CB8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall TestPlayerViewParticle_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r29
  const enumTypeInfo_t *EnumInfo; // r4
  const char *v5; // r5
  const enumValueInfo_t *EnumValueInfo; // r31
  idPresentable *presentable; // r3
  idPresentablePlayer *v8; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc >= 2 )
    {
      EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxScreenPrtType_t");
      if ( EnumInfo != nullptr )
      {
        v5 = args->argc <= 1 ? &byte_8200D768 : args->argv[1];
        EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                          this: typeInfoTools,
                          enumInfo: EnumInfo,
                          name: v5,
                          defaultIfNotFound: false);
        if ( EnumValueInfo != nullptr )
        {
          presentable = v3->presentable;
          if ( presentable != nullptr )
            v8 = presentable->GetPlayerInterface_2(this: presentable);
          else
            v8 = nullptr;
          idPresentablePlayer::StartScreenParticle(this: v8, screenPrtType: EnumValueInfo->value, excludeAngle: -1.0);
        }
      }
    }
    else if ( args->argc <= 0 )
    {
      idLib::Printf(fmt: "Syntax: %s <type>\n", &byte_8200D768);
    }
    else
    {
      idLib::Printf(fmt: "Syntax: %s <type>\n", args->argv[0]);
    }
  }
}


// ========================================================================
// ?Noclip_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50DD0
// RVA : 0x00E50DD0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Noclip_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r27
  bool v4; // r3
  int argc; // r11
  unsigned int v6; // r3
  bool v7; // r3
  int v8; // r29
  signed int i; // r30
  idPlayer *Player; // r3
  idPlayer *v11; // r31
  bool Noclip; // r3
  idPresentable *presentable; // r3
  int v14; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    v4 = common->IsMultiplayer(this: common);
    argc = args->argc;
    if ( v4 )
    {
      v8 = 0;
      if ( argc > 1 )
        v8 = atol(nptr: args->argv[1]);
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        v11 = Player;
        if ( Player != nullptr && (v8 == -1 || Player->entityNumber == v8) )
        {
          Noclip = idPlayer::GetNoclip(this: Player);
          idPlayer::SetNoclip(this: v11, v: (_cntlzw(Noclip) & 0x20) != 0);
        }
      }
    }
    else if ( argc == 2 )
    {
      v6 = idStr::Icmp(s1: args->argv[1], s2: "1");
      idPlayer::SetNoclip(this: v3, v: (_cntlzw(v6) & 0x20) != 0);
    }
    else
    {
      v7 = idPlayer::GetNoclip(this: v3);
      idPlayer::SetNoclip(this: v3, v: (_cntlzw(v7) & 0x20) != 0);
    }
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v14 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v14 = 0;
    if ( (*(_BYTE *)(v14 + 47032) & 0x20) != 0 )
      idLib::Printf(fmt: "noclip %s\n", "ON");
    else
      idLib::Printf(fmt: "noclip %s\n", "OFF");
  }
}


// ========================================================================
// ?God_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E50F68
// RVA : 0x00E50F68
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall God_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r27
  char v4; // r10
  int v5; // r30
  signed int i; // r31
  idPlayer *Player; // r3
  char v8; // r11

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( common->IsMultiplayer(this: common) )
    {
      v5 = 0;
      if ( args->argc > 1 )
        v5 = atol(nptr: args->argv[1]);
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        if ( Player != nullptr && (v5 == -1 || Player->entityNumber == v5) )
        {
          if ( (*((_BYTE *)Player + 12824) & 0x40) == 0 || (v8 = 0, g_permaGodMode.valueInteger != 0) )
            v8 = 1;
          *((_BYTE *)Player + 12824) = (v8 << 6) & 0x40 | *((_BYTE *)Player + 12824) & 0xBF;
        }
      }
    }
    else
    {
      if ( (*((_BYTE *)v3 + 12824) & 0x40) == 0 || (v4 = 0, g_permaGodMode.valueInteger != 0) )
        v4 = 1;
      *((_BYTE *)v3 + 12824) = (v4 << 6) & 0x40 | *((_BYTE *)v3 + 12824) & 0xBF;
    }
    if ( (*((_BYTE *)v3 + 12824) & 0x40) != 0 )
      idLib::Printf(fmt: "godmode %s\n", "ON");
    else
      idLib::Printf(fmt: "godmode %s\n", "OFF");
  }
}


// ========================================================================
// ?InfiniteHealth_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E510E0
// RVA : 0x00E510E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall InfiniteHealth_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  char v3; // r11
  const char *v4; // r4

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    v3 = (32 * ~(*((unsigned __int8 *)v2 + 12824) >> 5)) & 0x20 | *((_BYTE *)v2 + 12824) & 0xDF;
    *((_BYTE *)v2 + 12824) = v3;
    if ( (v3 & 0x20) != 0 )
      v4 = "ON";
    else
      v4 = "OFF";
    idLib::Printf(fmt: "infiniteHealth %s\n", v4);
  }
}


// ========================================================================
// ?NoPlayerDeath_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51180
// RVA : 0x00E51180
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall NoPlayerDeath_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  char v3; // r11
  const char *v4; // r4

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    v3 = (16 * ~(*((unsigned __int8 *)v2 + 12824) >> 4)) & 0x10 | *((_BYTE *)v2 + 12824) & 0xEF;
    *((_BYTE *)v2 + 12824) = v3;
    if ( (v3 & 0x10) != 0 )
      v4 = "ON";
    else
      v4 = "OFF";
    idLib::Printf(fmt: "noPlayerDeath %s\n", v4);
  }
}


// ========================================================================
// ?Notarget_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51220
// RVA : 0x00E51220
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Notarget_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r28
  int v4; // r30
  signed int i; // r31
  idPlayer *Player; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( common->IsMultiplayer(this: common) )
    {
      v4 = 0;
      if ( args->argc > 1 )
        v4 = atol(nptr: args->argv[1]);
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        if ( Player != nullptr && (v4 == -1 || Player->entityNumber == v4) )
          *((_BYTE *)Player + 12824) = (8 * ((unsigned int)~*((unsigned __int8 *)Player + 12824) >> 3)) & 8
                                     | *((_BYTE *)Player + 12824) & 0xF7;
      }
    }
    else
    {
      *((_BYTE *)v3 + 12824) = (8 * ((unsigned int)~*((unsigned __int8 *)v3 + 12824) >> 3)) & 8
                             | *((_BYTE *)v3 + 12824) & 0xF7;
    }
    if ( (*((_BYTE *)v3 + 12824) & 8) != 0 )
      idLib::Printf(fmt: "notarget %s\n", "ON");
    else
      idLib::Printf(fmt: "notarget %s\n", "OFF");
  }
}


// ========================================================================
// ?VehExitForce_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51350
// RVA : 0x00E51350
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall VehExitForce_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  idVehicle *v3; // r3
  idVehicle *v4; // r30
  idPresentable *presentable; // r3
  idPresentablePlayer *v6; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: v2) != 0 )
  {
    v3 = v2->GetVehicle_2(this: v2);
    v4 = v3;
    if ( v3 != nullptr )
    {
      idVehicle::AllowOccupantExitVehicle(this: v3, seat: 0, bl: true);
      v4->ExitVehicle(this: v4, a2: 0, a3: true, a4: false);
      presentable = v2->presentable;
      if ( presentable != nullptr )
        v6 = presentable->GetPlayerInterface_2(this: presentable);
      else
        v6 = nullptr;
      idPresentablePlayer::ResetControl(this: v6);
    }
  }
}


// ========================================================================
// ?SetSceneModelFlag_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51438
// RVA : 0x00E51438
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall SetSceneModelFlag_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r4
  const char *v3; // r3
  const char *v4; // r30
  int v5; // r29
  idEntity *v6; // r3
  idPresentable *presentable; // r11
  idRenderModel *v8; // r10
  idRenderModel *model; // r31
  char v10; // r10

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc == 3 )
    {
      v3 = args->argv[2];
      v4 = args->argv[1];
      v5 = atol(nptr: v3);
      v6 = gameLocal->FindEntity(this: gameLocal, a2: v4);
      if ( v6 != nullptr )
      {
        presentable = v6->presentable;
        if ( presentable != nullptr && (v8 = presentable->model) != nullptr )
        {
          model = presentable->model;
          if ( v5 != 0 )
            v10 = *((_BYTE *)&v8->g + 104) | 4;
          else
            v10 = *((_BYTE *)&v8->g + 104) & 0xFB;
          *((_BYTE *)&model->g + 104) = v10;
          if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v6) == 0 )
            idRenderModel::CommitThisFrame(this: model);
        }
        else
        {
          idLib::Printf(fmt: "Entity '%s' does not have a rendermodel", v4);
        }
      }
      else
      {
        idLib::Printf(fmt: "Could not find entity '%s'", v4);
      }
    }
    else
    {
      idLib::Printf(fmt: "usage: setSceneModelFlag <name of entity to remove> <0|1>\n");
    }
  }
}


// ========================================================================
// ?jobComplete_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51558
// RVA : 0x00E51558
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall jobComplete_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r31
  idPlayerHud *PlayerHud; // r3
  const char *v5; // r4
  idPlayerHud *v6; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    if ( args->argc == 2 )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
      idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
      v3->jobManager.inDebug = true;
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idJobManager::CompleteJob(this: &v3->jobManager, jobName: v5, completeTree: true, giveJob: true, force: true);
      v3->jobManager.inDebug = false;
      v6 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v3);
      idPlayerHud::SetIgnoreJobUpdates(this: v6, ignore: false);
    }
    else
    {
      idLib::Printf(fmt: "usage: jobComplete <job name>\n");
    }
  }
}


// ========================================================================
// ?jobReadyToTurnIn_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51620
// RVA : 0x00E51620
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall jobReadyToTurnIn_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r31
  idPlayerHud *PlayerHud; // r3
  const char *v5; // r4
  idPlayerHud *v6; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    if ( args->argc == 2 )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
      idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
      v3->jobManager.inDebug = true;
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idJobManager::SetJobReadyToTurnIn(
        this: &v3->jobManager,
        jobName: v5,
        completeTree: true,
        giveJobIfNeeded: true,
        hideIfGiven: false,
        force: true);
      v3->jobManager.inDebug = false;
      v6 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v3);
      idPlayerHud::SetIgnoreJobUpdates(this: v6, ignore: false);
    }
    else
    {
      idLib::Printf(fmt: "usage: jobReadyToTurnIn <job name>\n");
    }
  }
}


// ========================================================================
// ?jobAccept_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E516E8
// RVA : 0x00E516E8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall jobAccept_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r31
  idPlayerHud *PlayerHud; // r3
  const char *v5; // r4
  idPlayerHud *v6; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    if ( args->argc == 2 )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
      idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
      v3->jobManager.inDebug = true;
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idJobManager::AcceptJob(this: &v3->jobManager, name: v5, completeTree: true, force: true);
      v3->jobManager.inDebug = false;
      v6 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v3);
      idPlayerHud::SetIgnoreJobUpdates(this: v6, ignore: false);
    }
    else
    {
      idLib::Printf(fmt: "usage: jobAccept <job name>\n");
    }
  }
}


// ========================================================================
// ?jobFail_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E517A8
// RVA : 0x00E517A8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall jobFail_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r31
  idPlayerHud *PlayerHud; // r3
  const char *v5; // r4
  idPlayerHud *v6; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    if ( args->argc == 2 )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
      idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
      v3->jobManager.inDebug = true;
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idJobManager::FailJob(this: &v3->jobManager, jobName: v5);
      v3->jobManager.inDebug = false;
      v6 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v3);
      idPlayerHud::SetIgnoreJobUpdates(this: v6, ignore: false);
    }
    else
    {
      idLib::Printf(fmt: "usage: jobFail <job name>\n");
    }
  }
}


// ========================================================================
// ?Hands_Cmd_Hide_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51860
// RVA : 0x00E51860
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Hands_Cmd_Hide_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r30
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    if ( v4 == -37616 )
    {
      idLib::Warning(fmt: "Hands_cmd_Hide couldn't find player hands");
    }
    else
    {
      v5 = v2->presentable;
      if ( v5 != nullptr )
        v6 = (int)v5->GetPlayerInterface_2(this: v5);
      else
        v6 = 0;
      idHands::Hide(this: (idHands *)(v6 + 37616), hideReason: HAND_HIDE_SPECIAL);
      v7 = v2->presentable;
      if ( v7 != nullptr )
        v8 = (int)v7->GetPlayerInterface_2(this: v7);
      else
        v8 = 0;
      *(_BYTE *)(v8 + 40605) = 1;
    }
  }
  else
  {
    idLib::Warning(fmt: "Hands_cmd_Hide couldn't find player");
  }
}


// ========================================================================
// ?Hands_Cmd_Show_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51960
// RVA : 0x00E51960
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Hands_Cmd_Show_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r30
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    if ( v4 == -37616 )
    {
      idLib::Warning(fmt: "Hands_Cmd_Show couldn't find player hands");
    }
    else
    {
      v5 = v2->presentable;
      if ( v5 != nullptr )
        v6 = (int)v5->GetPlayerInterface_2(this: v5);
      else
        v6 = 0;
      idHands::Show(this: (idHands *)(v6 + 37616), hideReason: HAND_HIDE_SPECIAL);
      v7 = v2->presentable;
      if ( v7 != nullptr )
        v8 = (int)v7->GetPlayerInterface_2(this: v7);
      else
        v8 = 0;
      idHands::Enable(this: (idHands *)(v8 + 37616));
      v9 = v2->presentable;
      if ( v9 != nullptr )
        v10 = (int)v9->GetPlayerInterface_2(this: v9);
      else
        v10 = 0;
      idHands::Reset(this: (idHands *)(v10 + 37616), doIntro: false);
    }
  }
  else
  {
    idLib::Warning(fmt: "Hands_Cmd_Show couldn't find player");
  }
}


// ========================================================================
// ?test_dlc_rewards_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51A88
// RVA : 0x00E51A88
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall test_dlc_rewards_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
    idJobManager::CheckAndGiveDLCRewards(this: &DebugPlayer->jobManager, mapLoad: false);
  else
    idLib::Warning(fmt: "test_dlc_rewards couldn't find player");
}


// ========================================================================
// ?playtest_DebugDraw_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51AE0
// RVA : 0x00E51AE0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall playtest_DebugDraw_f(const idCmdArgs *args)
{
  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      atol(nptr: &byte_8200D768);
    else
      atol(nptr: args->argv[1]);
  }
}


// ========================================================================
// ?testMatchParms_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51B10
// RVA : 0x00E51B10
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall testMatchParms_f(const idCmdArgs *args)
{
  if ( common->IsMultiplayer(this: common) )
    idMainMenu::SetScoreLimit(this: gameLocal->mainMenu, newScoreLimit: 12, storeDefaults: true);
  else
    idLib::Warning(fmt: "testUnlock is only available in multiplayer");
}


// ========================================================================
// ?achievementsClearAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51B90
// RVA : 0x00E51B90
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsClearAll_f(const idCmdArgs *args)
{
  int v1; // r4
  idSignInManagerBase *signInManager; // r31
  idSignInManagerBase_vtbl *v3; // r30
  int v4; // r3
  idSessionLocalXbox *v5; // r11
  int v6; // r3
  idPlayer *DebugPlayer; // r3
  idPlayer *v8; // r31
  idAchievementManager *p_achievementManager; // r30

  v1 = 0;
  if ( args->argc > 1 )
  {
    signInManager = session->signInManager;
    v3 = signInManager->__vftable;
    v4 = atol(nptr: args->argv[1]);
    v1 = (int)v3->GetLocalUserByIndex_2(this: signInManager, a2: v4);
  }
  if ( common != nullptr )
  {
    v5 = (idSessionLocalXbox *)session;
    if ( session != nullptr )
    {
      if ( v1 == 0 )
      {
        v6 = ((int (*)(void))common->GetMasterLocalUser)();
        v5 = (idSessionLocalXbox *)session;
        v1 = v6;
      }
      v5->achievementSystem->AchievementLockAll(this: v5->achievementSystem, a2: (idLocalUser *)v1, a3: 50);
      idLib::Printf(fmt: "Online achievements cleared.\n");
    }
  }
  if ( gameLocal != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v8 = DebugPlayer;
    if ( DebugPlayer != nullptr )
    {
      p_achievementManager = &DebugPlayer->achievementManager;
      idAchievementManager::ClearAllRequirements(this: &DebugPlayer->achievementManager);
      idAchievementManager::Init(this: p_achievementManager, player: v8);
    }
    else
    {
      idLib::Printf(fmt: "Unable to execute command.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n", v1);
  }
}


// ========================================================================
// ?achievementsList_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51CE0
// RVA : 0x00E51CE0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsList_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r27
  int i; // r31
  const char *v3; // r5
  char v4[500]; // [sp+50h] [-620h] BYREF
  char v5[1068]; // [sp+244h] [-42Ch] BYREF

  if ( common != nullptr && session != nullptr )
  {
    v1 = (idLocalUser *)((int (*)(void))common->GetMasterLocalUser)();
    if ( v1 != nullptr )
    {
      idLib::Printf(fmt: "Listing all online achievements for the current platform:\n\n");
      for ( i = 1; i < 51; ++i )
      {
        if ( session->achievementSystem->GetAchievementDescription(
               this: session->achievementSystem,
               a2: v1,
               a3: i,
               a4: (achievementDescription_t *)v4) )
        {
          v3 = "^1H^0";
          if ( v5[1000] == 0 )
            v3 = "^2V^0";
          idLib::Printf(fmt: "^8%03d^0: [%s], ^3%s\n^0          %s\n", i, v3, v4, v5);
        }
      }
    }
    else
    {
      idLib::Printf(fmt: "Unable to execute command.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Can't execute test.\n");
  }
}


// ========================================================================
// ?achievementsOnlineState_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51DE8
// RVA : 0x00E51DE8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsOnlineState_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r31
  unsigned int v2; // r30
  unsigned int v3; // r3
  int i; // r31
  const char *v5; // r5
  _BYTE v6[176]; // [sp+50h] [-B0h] BYREF

  if ( common != nullptr && session != nullptr )
  {
    v1 = (idLocalUser *)((int (*)(void))common->GetMasterLocalUser)();
    if ( v1 != nullptr )
    {
      idLib::Printf(fmt: "Lists all the state of the achievements for the current platform:\n");
      v2 = Sys_Milliseconds();
      session->achievementSystem->GetAchievementState(
        this: session->achievementSystem,
        a2: v1,
        a3: (idArray<bool,128> *)v6);
      v3 = Sys_Milliseconds();
      idLib::Printf(fmt: "Retrieved state in %d ms.\n", v3 - v2);
      for ( i = 0; i < 128; ++i )
      {
        v5 = "^2X^0";
        if ( v6[i] == 0 )
          v5 = " ";
        idLib::Printf(fmt: "^8%03d^0: [ %s ]\n", i, v5);
      }
    }
    else
    {
      idLib::Printf(fmt: "Unable to execute command.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Can't execute test.\n");
  }
}


// ========================================================================
// ?statsClearAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E51EF8
// RVA : 0x00E51EF8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall statsClearAll_f(const idCmdArgs *args)
{
  idSignInManagerBase *signInManager; // r31
  idSignInManagerBase_vtbl *v2; // r30
  int v3; // r3
  idLocalUser *v4; // r31
  rageStat_t i; // r30
  bool IsInt; // r3
  idLocalUser_vtbl *v7; // r11
  idPlayerProfile *v8; // r3
  idPlayer *DebugPlayer; // r3

  if ( args->argc > 1
    && (signInManager = session->signInManager,
        v2 = signInManager->__vftable,
        v3 = atol(nptr: args->argv[1]),
        (v4 = v2->GetLocalUserByIndex_2(this: signInManager, a2: v3)) != nullptr)
    || (v4 = common->GetMasterLocalUser(this: common)) != nullptr )
  {
    for ( i = RAGE_STAT_VEHICLE_KILLS; i < NUM_RAGE_STATS; ++i )
    {
      IsInt = RageStatTypeIsInt(stat: i);
      v7 = v4->__vftable;
      if ( IsInt )
        v7->SetStatInt(this: v4, a2: i, a3: 0);
      else
        v7->SetStatFloat(this: v4, a2: i, a3: 0.0);
    }
    v4->SetStatInt(this: v4, a2: 32, a3: 1);
    v4->SetStatInt(this: v4, a2: 31, a3: 1);
    if ( session != nullptr )
      session->SendLocalSessionUsersToPeers(this: session);
    idLib::Printf(fmt: "All stats reset.  Saving profile.\n");
    if ( v4->GetProfile(this: v4) != nullptr )
    {
      v8 = v4->GetProfile(this: v4);
      idPlayerProfile::SaveSettings(this: v8);
      if ( session != nullptr )
        session->UpdateSignInManager(this: session);
    }
    if ( gameLocal != nullptr )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      if ( DebugPlayer != nullptr )
        idAchievementManager::ResetLifetimeStats(this: &DebugPlayer->achievementManager);
    }
  }
  else
  {
    idLib::Warning(fmt: "No master local user");
  }
}


// ========================================================================
// ?statsClearGame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E520D8
// RVA : 0x00E520D8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall statsClearGame_f(const idCmdArgs *args)
{
  unsigned int v2; // r4
  idPlayer *Player; // r3
  idPlayer *v4; // r29
  rageStat_t v5; // r30
  profileStatValue_t *stats; // r31

  if ( gameLocal != nullptr && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
  {
    v2 = 0;
    if ( args->argc > 1 )
      v2 = atol(nptr: args->argv[1]);
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v2);
    v4 = Player;
    if ( Player != nullptr )
    {
      v5 = RAGE_STAT_VEHICLE_KILLS;
      stats = Player->stats;
      do
      {
        if ( RageStatTypeIsInt(stat: v5) )
          stats->i = 0;
        else
          stats->f = 0.0;
        ++v5;
        ++stats;
      }
      while ( v5 < NUM_RAGE_STATS );
      v4->stats[32].i = 1;
      v4->stats[31].i = 1;
    }
    else
    {
      idLib::Warning(fmt: "No master player found");
    }
  }
  else
  {
    idLib::Printf(fmt: "You must be in a game to test achievements, a box map will do...\n");
  }
}


// ========================================================================
// ?resetProfile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E521C8
// RVA : 0x00E521C8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall resetProfile_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r3
  idPlayerProfile *v2; // r31
  idCmdArgs v3; // [sp+50h] [-920h] BYREF

  v3.argc = 0;
  achievementsClearAll_f(args: &v3);
  statsClearAll_f(args: &v3);
  statsClearGame_f(args: &v3);
  v1 = common->GetMasterLocalUser(this: common);
  if ( v1 != nullptr )
  {
    v2 = v1->GetProfile(this: v1);
    v2->SetDefaults(this: v2);
    idPlayerProfile::SaveSettings(this: v2);
  }
  else
  {
    idLib::Warning(fmt: "No master local user");
  }
}


// ========================================================================
// ?setStat_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52278
// RVA : 0x00E52278
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setStat_f(const idCmdArgs *args)
{
  idLocalUser *v2; // r28
  const enumTypeInfo_t *EnumInfo; // r4
  const char *v4; // r5
  const enumValueInfo_t *EnumValueInfo; // r3
  rageStat_t value; // r29
  int StatAsInt; // r5
  idPlayer *DebugPlayer; // r28
  bool IsInt; // r3
  int argc; // r11
  const char *v11; // r3
  int v12; // r27
  int v13; // r6
  const char *v14; // r3
  long double v15; // fp2
  double v16; // fp1

  if ( common->IsMultiplayer(this: common) )
  {
    if ( args->argc >= 2 )
    {
      v2 = common->GetMasterLocalUser(this: common);
      if ( v2 != nullptr )
      {
        EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "rageStat_t");
        if ( EnumInfo != nullptr )
        {
          if ( args->argc <= 1 )
            v4 = &byte_8200D768;
          else
            v4 = args->argv[1];
          EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                            this: typeInfoTools,
                            enumInfo: EnumInfo,
                            name: v4,
                            defaultIfNotFound: false);
          if ( EnumValueInfo != nullptr )
          {
            value = EnumValueInfo->value;
            if ( args->argc == 3 )
            {
              DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
              IsInt = RageStatTypeIsInt(stat: value);
              argc = args->argc;
              if ( IsInt )
              {
                if ( argc <= 2 )
                  v11 = &byte_8200D768;
                else
                  v11 = args->argv[2];
                v12 = atol(nptr: v11);
                v13 = v12 - idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: DebugPlayer, stat: value);
                if ( v13 > 0 )
                  idRageMetrics::StatAddInt(this: clientGame->rageMetrics, player: DebugPlayer, stat: value, value: v13);
              }
              else
              {
                if ( argc <= 2 )
                  v14 = &byte_8200D768;
                else
                  v14 = args->argv[2];
                v15 = atof(nptr: v14);
                v16 = (float)((float)*(double *)&v15
                            - idRageMetrics::GetStatFloat(
                                this: clientGame->rageMetrics,
                                player: DebugPlayer,
                                stat: value));
                if ( v16 > 0.0 )
                  idRageMetrics::StatAddFloat(
                    this: clientGame->rageMetrics,
                    player: DebugPlayer,
                    stat: value,
                    value: v16);
              }
              idRageMetrics::UpdateLevel(this: clientGame->rageMetrics, playerId: 0);
            }
            else
            {
              StatAsInt = GetStatAsInt(user: v2, stat: (rageStat_t)EnumValueInfo->value);
              if ( args->argc <= 1 )
                idLib::Printf(
                  fmt: "Current value for %s is %d. usage: setStat < stat > < value >\n",
                  &byte_8200D768,
                  StatAsInt);
              else
                idLib::Printf(
                  fmt: "Current value for %s is %d. usage: setStat < stat > < value >\n",
                  args->argv[1],
                  StatAsInt);
            }
          }
          else
          {
            idLib::Printf(fmt: "setStat invalid stat. usage: setStat < stat > < value >\n");
          }
        }
      }
      else
      {
        idLib::Warning(fmt: "No master local user");
      }
    }
    else
    {
      idLib::Printf(fmt: "usage: setStat < stat > < value >\n");
    }
  }
  else
  {
    idLib::Warning(fmt: "setStat is only available in multiplayer");
  }
}


// ========================================================================
// ?setStatGame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52500
// RVA : 0x00E52500
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setStatGame_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r28
  const enumTypeInfo_t *EnumInfo; // r4
  const char *v4; // r5
  const enumValueInfo_t *EnumValueInfo; // r3
  int value; // r31
  profileStatValue_t v7; // r5
  bool IsInt; // r3
  int argc; // r11
  const char *v10; // r3
  long double v11; // fp2

  if ( args->argc >= 2 )
  {
    if ( gameLocal != nullptr && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      if ( DebugPlayer != nullptr )
      {
        EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "rageStat_t");
        if ( EnumInfo != nullptr )
        {
          if ( args->argc <= 1 )
            v4 = &byte_8200D768;
          else
            v4 = args->argv[1];
          EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                            this: typeInfoTools,
                            enumInfo: EnumInfo,
                            name: v4,
                            defaultIfNotFound: false);
          if ( EnumValueInfo != nullptr )
          {
            value = EnumValueInfo->value;
            if ( args->argc == 3 )
            {
              IsInt = RageStatTypeIsInt(stat: (rageStat_t)EnumValueInfo->value);
              argc = args->argc;
              if ( IsInt )
              {
                if ( argc <= 2 )
                  DebugPlayer->stats[value].i = atol(nptr: &byte_8200D768);
                else
                  DebugPlayer->stats[value].i = atol(nptr: args->argv[2]);
              }
              else
              {
                if ( argc <= 2 )
                  v10 = &byte_8200D768;
                else
                  v10 = args->argv[2];
                v11 = atof(nptr: v10);
                DebugPlayer->stats[value].f = *(double *)&v11;
              }
            }
            else
            {
              v7.i = (int)DebugPlayer->stats[value];
              if ( args->argc <= 1 )
                idLib::Printf(
                  fmt: "Current 'int' value for %s is %d. usage: setStatGame < stat > < value >\n",
                  &byte_8200D768,
                  v7.i);
              else
                idLib::Printf(
                  fmt: "Current 'int' value for %s is %d. usage: setStatGame < stat > < value >\n",
                  args->argv[1],
                  v7.i);
            }
          }
          else
          {
            idLib::Printf(fmt: "setStat invalid stat. usage: setStatGame < stat > < value >\n");
          }
        }
      }
      else
      {
        idLib::Warning(fmt: "No master player found");
      }
    }
    else
    {
      idLib::Printf(fmt: "You must be in a game to test achievements, a box map will do...\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: setStatGame < stat > < value >\n");
  }
}


// ========================================================================
// ?giveStat_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E526D0
// RVA : 0x00E526D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall giveStat_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r28
  const enumTypeInfo_t *EnumInfo; // r4
  const char *v4; // r5
  const enumValueInfo_t *EnumValueInfo; // r3
  rageStat_t value; // r29
  profileStatValue_t v7; // r5
  bool IsInt; // r3
  int argc; // r11
  const char *v10; // r3
  int v11; // r27
  int v12; // r6
  const char *v13; // r3
  long double v14; // fp2
  double v15; // fp1

  if ( args->argc >= 2 )
  {
    if ( gameLocal != nullptr && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      if ( DebugPlayer != nullptr )
      {
        if ( common->GetMasterLocalUser(this: common) != nullptr )
        {
          EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "rageStat_t");
          if ( EnumInfo != nullptr )
          {
            if ( args->argc <= 1 )
              v4 = &byte_8200D768;
            else
              v4 = args->argv[1];
            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                              this: typeInfoTools,
                              enumInfo: EnumInfo,
                              name: v4,
                              defaultIfNotFound: false);
            if ( EnumValueInfo != nullptr )
            {
              value = EnumValueInfo->value;
              if ( args->argc == 3 )
              {
                IsInt = RageStatTypeIsInt(stat: (rageStat_t)EnumValueInfo->value);
                argc = args->argc;
                if ( IsInt )
                {
                  if ( argc <= 2 )
                    v10 = &byte_8200D768;
                  else
                    v10 = args->argv[2];
                  v11 = atol(nptr: v10);
                  v12 = v11 - idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: DebugPlayer, stat: value);
                  if ( v12 > 0 )
                    idRageMetrics::StatAddInt(
                      this: clientGame->rageMetrics,
                      player: DebugPlayer,
                      stat: value,
                      value: v12);
                }
                else
                {
                  if ( argc <= 2 )
                    v13 = &byte_8200D768;
                  else
                    v13 = args->argv[2];
                  v14 = atof(nptr: v13);
                  v15 = (float)((float)*(double *)&v14
                              - idRageMetrics::GetStatFloat(
                                  this: clientGame->rageMetrics,
                                  player: DebugPlayer,
                                  stat: value));
                  if ( v15 > 0.0 )
                    idRageMetrics::StatAddFloat(
                      this: clientGame->rageMetrics,
                      player: DebugPlayer,
                      stat: value,
                      value: v15);
                }
                if ( common->IsMultiplayer(this: common) )
                  idRageMetrics::UpdateLevel(this: clientGame->rageMetrics, playerId: 0);
              }
              else
              {
                v7.i = (int)DebugPlayer->stats[value];
                if ( args->argc <= 1 )
                  idLib::Printf(
                    fmt: "Current 'int' value for %s is %d. usage: giveStat < stat > < value >\n",
                    &byte_8200D768,
                    v7.i);
                else
                  idLib::Printf(
                    fmt: "Current 'int' value for %s is %d. usage: giveStat < stat > < value >\n",
                    args->argv[1],
                    v7.i);
              }
            }
            else
            {
              idLib::Printf(fmt: "setStat invalid stat. usage: giveStat < stat > < value >\n");
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "No master local user");
        }
      }
      else
      {
        idLib::Warning(fmt: "No master player found");
      }
    }
    else
    {
      idLib::Printf(fmt: "You must be in a game to test achievements, a box map will do...\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: giveStat < stat > < deltavalue >\n");
  }
}


// ========================================================================
// ?correctOnlineLevel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52988
// RVA : 0x00E52988
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall correctOnlineLevel_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r3
  idDeclOnlineLevel *v2; // r30
  idLocalUser *v3; // r3
  idLocalUser *v4; // r31
  int v5; // r27
  int v6; // r29
  __int64 v7; // r10
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int LevelForXp; // r30
  idPlayerProfile *v12; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v1 = session->GetGameLobbyBase(this: session), v1->IsPeer(this: v1)) )
    {
      idLib::Warning(fmt: "Can't %s while you are a peer in a session", "correctOnlineLevel_f");
    }
    else
    {
      v2 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
      if ( v2 != nullptr )
      {
        v3 = common->GetMasterLocalUser(this: common);
        v4 = v3;
        if ( v3 != nullptr )
        {
          v5 = v3->GetStatInt(this: v3, a2: 23);
          v6 = v4->GetStatInt(this: v4, a2: 32);
          LevelForXp = idDeclOnlineLevel::GetLevelForXp(this: v2, xp: v5, a3: v10, a4: v9, a5: v8, a6: v7);
          v4->SetStatInt(this: v4, a2: 32, a3: LevelForXp);
          if ( session != nullptr )
            session->SendLocalSessionUsersToPeers(this: session);
          idLib::Printf(fmt: "Online level changed from %d to %d.\n", v6, LevelForXp);
          if ( v4->GetProfile(this: v4) != nullptr )
          {
            v12 = v4->GetProfile(this: v4);
            idPlayerProfile::SaveSettings(this: v12);
          }
        }
      }
      else
      {
        idLib::Printf(fmt: "Level decls not found, aborting!\n");
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "%s is only available in multiplayer", "correctOnlineLevel_f");
  }
}


// ========================================================================
// ?setOnlineXP_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52B48
// RVA : 0x00E52B48
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineXP_f(const idCmdArgs *args)
{
  idLobbyBase *v2; // r3
  idLocalUser *v3; // r3
  idLocalUser *v4; // r31
  int v5; // r28
  int v6; // r3
  int v7; // r27
  idDeclOnlineLevel *v8; // r29
  const char *v9; // r3
  __int64 v10; // r10
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int v14; // r3
  int v15; // r30
  int v16; // r4
  int LevelForXp; // r29
  idPlayerProfile *v18; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v2 = session->GetGameLobbyBase(this: session), v2->IsPeer(this: v2)) )
    {
      idLib::Warning(fmt: "Can't setOnlineXP while you are a peer in a session");
    }
    else
    {
      v3 = common->GetMasterLocalUser(this: common);
      v4 = v3;
      if ( v3 != nullptr )
      {
        v5 = v3->GetStatInt(this: v3, a2: 23);
        v6 = v4->GetStatInt(this: v4, a2: 32);
        v7 = v6;
        if ( args->argc == 2 )
        {
          v8 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
          if ( v8 != nullptr )
          {
            if ( args->argc <= 1 )
              v9 = &byte_8200D768;
            else
              v9 = args->argv[1];
            v14 = atol(nptr: v9);
            v15 = v14;
            if ( v14 >= 0 )
            {
              LODWORD(v10) = v8->xpCap;
              v16 = (int)(float)((float)v10 * v8->globalXpScale);
              if ( v14 <= v16 )
              {
                LevelForXp = idDeclOnlineLevel::GetLevelForXp(this: v8, xp: v14, a3: v13, a4: v12, a5: v11, a6: v10);
                v4->SetStatInt(this: v4, a2: 23, a3: v15);
                v4->SetStatInt(this: v4, a2: 32, a3: LevelForXp);
                if ( session != nullptr )
                  session->SendLocalSessionUsersToPeers(this: session);
                idLib::Printf(fmt: "Online level changed from %d to %d.\n", v7, LevelForXp);
                idLib::Printf(fmt: "Online xp changed from %d to %d.\n", v5, v15);
                if ( v4->GetProfile(this: v4) != nullptr )
                {
                  v18 = v4->GetProfile(this: v4);
                  idPlayerProfile::SaveSettings(this: v18);
                }
              }
              else
              {
                idLib::Printf(
                  fmt: "XP cannot be larger than %d!\n Current XP is %d. usage: setOnlineXP < xp >\n",
                  v16,
                  v5);
              }
            }
            else
            {
              idLib::Printf(fmt: "XP cannot be negative!\n Current XP is %d. usage: setOnlineXP < xp >\n", v5);
            }
          }
          else
          {
            idLib::Printf(fmt: "Level decls not found, aborting!\n Current XP is %d. usage: setOnlineXP < xp >\n", v5);
          }
        }
        else
        {
          idLib::Printf(fmt: "Current Level is %d, XP is %d. usage: setOnlineXP < level >\n", v6, v5);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineXP is only available in multiplayer");
  }
}


// ========================================================================
// ?setOnlineCash_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52DE8
// RVA : 0x00E52DE8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineCash_f(const idCmdArgs *args)
{
  idLobbyBase *v2; // r3
  idLocalUser *v3; // r3
  idLocalUser *v4; // r31
  int v5; // r3
  int v6; // r30
  int v7; // r29
  idPlayerProfile *v8; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v2 = session->GetGameLobbyBase(this: session), v2->IsPeer(this: v2)) )
    {
      idLib::Warning(fmt: "Can't setOnlineCash while you are a peer in a session");
    }
    else
    {
      v3 = common->GetMasterLocalUser(this: common);
      v4 = v3;
      if ( v3 != nullptr )
      {
        v5 = v3->GetStatInt(this: v3, a2: 21);
        v6 = v5;
        if ( args->argc == 2 )
        {
          v7 = atol(nptr: args->argv[1]);
          v4->SetStatInt(this: v4, a2: 21, a3: v7);
          idLib::Printf(fmt: "Online cash changed from %d to %d.\n", v6, v7);
          if ( v4->GetProfile(this: v4) != nullptr )
          {
            v8 = v4->GetProfile(this: v4);
            idPlayerProfile::SaveSettings(this: v8);
          }
        }
        else
        {
          idLib::Printf(fmt: "Current Cash is %d. usage: setOnlineCash < cash >\n", v5);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineCash is only available in multiplayer");
  }
}


// ========================================================================
// ?setOnlineCoopUnlock_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E52F58
// RVA : 0x00E52F58
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineCoopUnlock_f(const idCmdArgs *args)
{
  idLobbyBase *v2; // r3
  int v3; // r29
  idLocalUser *v4; // r3
  idLocalUser *v5; // r31
  idPlayerProfile *v6; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v2 = session->GetGameLobbyBase(this: session), v2->IsPeer(this: v2)) )
    {
      idLib::Warning(fmt: "Can't setOnlineCoopUnlock while you are a peer in a session");
    }
    else if ( args->argc == 2 )
    {
      v3 = atol(nptr: args->argv[1]) + 50;
      if ( v3 >= 0 )
      {
        v4 = common->GetMasterLocalUser(this: common);
        v5 = v4;
        if ( v4 != nullptr )
        {
          v4->SetStatInt(this: v4, a2: v3, a3: 1);
          if ( v5->GetProfile(this: v5) != nullptr )
          {
            v6 = v5->GetProfile(this: v5);
            idPlayerProfile::SaveSettings(this: v6);
          }
        }
      }
      else
      {
        idLib::Printf(fmt: "Unlock map cannot be negative\n");
      }
    }
    else
    {
      idLib::Warning(fmt: "Need a single map index integer value");
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineCoopUnlock is only available in multiplayer");
  }
}


// ========================================================================
// ?VehHealth_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E530A8
// RVA : 0x00E530A8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall VehHealth_f(const idCmdArgs *args)
{
  int v2; // r28
  double v3; // fp31
  const char *v4; // r3
  __int64 v5; // r11
  const char *v6; // r3
  signed int i; // r30
  idPlayer *Player; // r3
  idPlayer *v9; // r31
  int v10; // r3

  v2 = -1;
  v3 = 100.0;
  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    LODWORD(v5) = atol(nptr: v4);
    v3 = (float)v5;
  }
  if ( args->argc >= 3 )
  {
    if ( args->argc <= 2 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[2];
    v2 = atol(nptr: v6);
  }
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    v9 = Player;
    if ( Player != nullptr && (v2 < 0 || v2 == i) && Player->GetVehicle_2(this: Player) != nullptr )
    {
      v10 = (int)v9->GetVehicle_2(this: v9);
      (*(void (__fastcall **)(int, double))(*(_DWORD *)v10 + 720))(a1: v10, a2: v3);
    }
  }
}


// ========================================================================
// ?setGameChallengeState_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E531C0
// RVA : 0x00E531C0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setGameChallengeState_f(const idCmdArgs *args)
{
  if ( args->argc == 2 )
    gameLocal->challengeState = atol(nptr: args->argv[1]);
  else
    idLib::Printf(fmt: "usage: setGameChallengeState <number> (CHALLENGE_STATE_GAME_OVER = 6)\n");
}


// ========================================================================
// ?ArgCompletion_Give@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82E532E0
// RVA : 0x00E532E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ArgCompletion_Give(idAutoComplete *autoComplete)
{
  idStr v2; // [sp+50h] [-140h] BYREF
  idStr v3; // [sp+70h] [-120h] BYREF
  idStr v4; // [sp+90h] [-100h] BYREF
  idStr v5; // [sp+B0h] [-E0h] BYREF
  idStr v6; // [sp+D0h] [-C0h] BYREF
  idStr v7; // [sp+F0h] [-A0h] BYREF
  idStr v8; // [sp+110h] [-80h] BYREF
  idStr v9; // [sp+130h] [-60h] BYREF
  idStr v10; // [sp+150h] [-40h] BYREF

  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idDeclInventory::resourceList);
  idStr::idStr(this: &v3, text: "all");
  idAutoComplete::Append(this: autoComplete, suggestion: &v3, completingArg: -1);
  idStr::FreeData(this: &v3);
  idStr::idStr(this: &v7, text: "weapons");
  idAutoComplete::Append(this: autoComplete, suggestion: &v7, completingArg: -1);
  idStr::FreeData(this: &v7);
  idStr::idStr(this: &v5, text: "ammo");
  idAutoComplete::Append(this: autoComplete, suggestion: &v5, completingArg: -1);
  idStr::FreeData(this: &v5);
  idStr::idStr(this: &v9, text: "health");
  idAutoComplete::Append(this: autoComplete, suggestion: &v9, completingArg: -1);
  idStr::FreeData(this: &v9);
  idStr::idStr(this: &v2, text: "armor");
  idAutoComplete::Append(this: autoComplete, suggestion: &v2, completingArg: -1);
  idStr::FreeData(this: &v2);
  idStr::idStr(this: &v4, text: "items");
  idAutoComplete::Append(this: autoComplete, suggestion: &v4, completingArg: -1);
  idStr::FreeData(this: &v4);
  idStr::idStr(this: &v6, text: "cash");
  idAutoComplete::Append(this: autoComplete, suggestion: &v6, completingArg: -1);
  idStr::FreeData(this: &v6);
  idStr::idStr(this: &v8, text: "racecash");
  idAutoComplete::Append(this: autoComplete, suggestion: &v8, completingArg: -1);
  idStr::FreeData(this: &v8);
  idStr::idStr(this: &v10, text: "recipes");
  idAutoComplete::Append(this: autoComplete, suggestion: &v10, completingArg: -1);
  idStr::FreeData(this: &v10);
}


// ========================================================================
// __unwind$495797_0
// EA  : 0x82E534A0
// RVA : 0x00E534A0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495797_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$495798_0
// EA  : 0x82E534C8
// RVA : 0x00E534C8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495798_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$495799_0
// EA  : 0x82E534F0
// RVA : 0x00E534F0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495799_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$495800_0
// EA  : 0x82E53518
// RVA : 0x00E53518
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495800_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 304));
}


// ========================================================================
// __unwind$495801_0
// EA  : 0x82E53540
// RVA : 0x00E53540
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495801_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$495802_1
// EA  : 0x82E53568
// RVA : 0x00E53568
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495802_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$495803_0
// EA  : 0x82E53590
// RVA : 0x00E53590
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495803_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$495804_0
// EA  : 0x82E535B8
// RVA : 0x00E535B8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495804_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 272));
}


// ========================================================================
// __unwind$495805_1
// EA  : 0x82E535E0
// RVA : 0x00E535E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495805_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 336));
}


// ========================================================================
// ?KillPlayer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E53608
// RVA : 0x00E53608
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall KillPlayer_f(const idCmdArgs *args)
{
  unsigned int v1; // r31
  const char *v2; // r3
  idPlayer *Player; // r30
  const idDecl *v4; // r3

  v1 = 0;
  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v1 = atol(nptr: v2);
  }
  Player = idGameLocal::GetPlayer(this: gameLocal, i: v1);
  if ( Player != nullptr )
  {
    v4 = idDeclInfo::FindWithInheritance(
           this: &idDeclDamage::resourceList,
           name: "damage/code_referenced/suicide",
           makeDefault: false);
    ((void (__fastcall *)(idPlayer *, _DWORD, _DWORD, const idDecl *, double))Player->Damage)(
      a1: Player,
      a2: 0,
      a3: 0,
      a4: v4,
      a5: 99999.0);
  }
  else
  {
    idLib::Printf(fmt: "Invalid player %d\n", v1);
  }
}


// ========================================================================
// ?TestFx_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E536E8
// RVA : 0x00E536E8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall TestFx_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r27
  const enumValueInfo_t *EnumValueInfo; // r28
  int argc; // r11
  bool v6; // cr56
  double v7; // fp30
  const char *v8; // r4
  const char *v9; // r4
  bool v10; // cr57
  bool v11; // cr57
  long double v12; // fp2
  char *data; // r4
  const idDeclFX *v14; // r24
  idPresentable *presentable; // r3
  int v16; // r3
  idPresentable *v17; // r11
  float v18; // r8
  float v19; // r7
  float *v20; // r3
  float v21; // r7
  float v22; // r9
  idEntityFx *v23; // r3
  idEntityFx *v24; // r4
  const enumTypeInfo_t *EnumInfo; // r4
  idDeclEntityDef *v26; // r30
  idEntityFx *v27; // r3
  idEntityFx *v28; // r29
  idEntityFx_vtbl *v29; // r27
  idMat3 *v30; // r3
  fxCondition_t value; // r5
  idVec3 v32; // [sp+50h] [-180h] BYREF
  int v33; // [sp+5Ch] [-174h]
  float v34; // [sp+60h] [-170h]
  float v35; // [sp+64h] [-16Ch]
  float v36; // [sp+68h] [-168h]
  idStr v37; // [sp+70h] [-160h] BYREF
  idVec3 v38; // [sp+90h] [-140h] BYREF
  idVec3 v39; // [sp+A0h] [-130h] BYREF
  idStr v40; // [sp+B0h] [-120h] BYREF
  trace_t v41; // [sp+D0h] [-100h] BYREF
  idVec3 v42[3]; // [sp+150h] [-80h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    idStr::idStr(this: &v40, text: g_testFxName.valueString.data);
    EnumValueInfo = nullptr;
    v37.len = 0;
    v37.allocedAndFlag = 20;
    v37.data = v37.baseBuffer;
    v37.baseBuffer[0] = 0;
    argc = args->argc;
    v6 = args->argc < 2;
    v7 = 1.0;
    v33 = args->argc;
    if ( v6 )
    {
      if ( v40.len == 0 )
      {
        if ( argc <= 0 )
          v8 = &byte_8200D768;
        else
          v8 = args->argv[0];
        idLib::Printf(fmt: "Syntax: %s <fxDecl>\n", v8);
        idStr::FreeData(this: &v37);
        goto LABEL_36;
      }
    }
    else
    {
      if ( argc <= 1 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[1];
      idStr::operator=(this: &v40, text: v9);
      v10 = args->argc > 2;
      v33 = args->argc;
      if ( v10 )
      {
        idStr::operator=(this: &v37, text: args->argv[2]);
        v11 = args->argc > 3;
        v33 = args->argc;
        if ( v11 )
        {
          v12 = atof(nptr: args->argv[3]);
          v7 = (float)*(double *)&v12;
        }
      }
      else
      {
        idStr::operator=(this: &v37, text: "FX_NONE");
      }
    }
    data = v40.data;
    if ( v40.data != nullptr )
    {
      v14 = (const idDeclFX *)idDeclInfo::FindWithInheritance(
                                this: &idDeclFX::resourceList,
                                name: v40.data,
                                makeDefault: false);
      if ( v14 != nullptr )
      {
        presentable = v3->presentable;
        if ( presentable != nullptr )
          v16 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v16 = 0;
        v17 = v3->presentable;
        v18 = *(float *)(v16 + 46548);
        v19 = *(float *)(v16 + 46552);
        v34 = *(float *)(v16 + 46544);
        v35 = v18;
        v36 = v19;
        if ( v17 != nullptr )
          v20 = (float *)v17->GetPlayerInterface_2(this: v17);
        else
          v20 = nullptr;
        v21 = v20[11635];
        v22 = v20[11633];
        v32.y = v20[11634];
        v32.z = v21;
        v32.x = v22;
        v39.x = (float)(v34 * (float)4096.0) + v22;
        v39.z = v21 + (float)(v36 * (float)4096.0);
        v39.y = v32.y + (float)(v35 * (float)4096.0);
        idClip::StartQueryFrame(this: &clientGame->clip);
        idClip::ResolveCollisionQueries(this: &clientGame->clip);
        idClip::TracePoint(
          this: &clientGame->clip,
          result: &v41,
          start: &v32,
          end: &v39,
          clipMask: 1,
          passEntityNumber: 0x1FFF);
        if ( __fabs((float)((float)((float)(v41.c.normal.x * v41.c.normal.x)
                                  + (float)((float)(v41.c.normal.y * v41.c.normal.y)
                                          + (float)(v41.c.normal.z * v41.c.normal.z)))
                          - (float)1.0)) < 0.0099999998 )
        {
          v23 = (idEntityFx *)gameLocal->FindEntity(this: gameLocal, a2: "testFxEntity");
          v24 = idEntityFx::CastTo(c: v23);
          if ( v24 != nullptr )
            gameLocal->DeleteEntity(this: gameLocal, a2: v24);
          EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxCondition_t");
          if ( EnumInfo != nullptr )
            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                              this: typeInfoTools,
                              enumInfo: EnumInfo,
                              name: v37.data,
                              defaultIfNotFound: false);
          v26 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
          idResource::SetName(this: &v26->idDecl, _name: "testFxEntity");
          v26->BuildText(this: v26, a2: "func/fx", a3: "idEntityFx");
          v26->SetInheritedClass(this: v26, a2: false);
          v38.z = (float)(v41.c.point.z * (float)v7) + (float)(v32.z * (float)((float)1.0 - (float)v7));
          v38.x = (float)(v41.c.point.x * (float)v7) + (float)((float)((float)1.0 - (float)v7) * v32.x);
          v38.y = (float)(v41.c.point.y * (float)v7) + (float)(v32.y * (float)((float)1.0 - (float)v7));
          v27 = (idEntityFx *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v26, a3: -1, a4: -1, a5: -1);
          v28 = idEntityFx::CastTo(c: v27);
          idEntity::SetOrigin(this: v28, org: &v38);
          v29 = v28->__vftable;
          v30 = idVec3::ToMat3(this: v42, result: (idMat3 *)&v41.c.normal);
          v29->SetAxis(this: v28, a2: v30);
          if ( EnumValueInfo != nullptr )
            value = EnumValueInfo->value;
          else
            value = FX_NONE;
          idEntityFx::TestEntityDeclFx(this: v28, declFx: v14, startCondition: value);
          ((void (__fastcall *)(idDeclEntityDef *, int))v26->dtr_idResource)(a1: v26, a2: 1);
        }
        idClip::SubmitCollisionQueries(this: &clientGame->clip);
        idClip::EndQueryFrame(this: &clientGame->clip);
        idClip::DeleteClipModels(this: &clientGame->clip);
        idStr::FreeData(this: &v37);
        goto LABEL_36;
      }
      data = v40.data;
    }
    idLib::Printf(fmt: "Could not find %s\n", data);
    idStr::FreeData(this: &v37);
LABEL_36:
    idStr::FreeData(this: &v40);
  }
}


// ========================================================================
// __unwind$495940
// EA  : 0x82E53B94
// RVA : 0x00E53B94
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495940()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 176));
}


// ========================================================================
// __unwind$495941
// EA  : 0x82E53BBC
// RVA : 0x00E53BBC
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_495941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 112));
}


// ========================================================================
// ?StopTestFx_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E53BF0
// RVA : 0x00E53BF0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall StopTestFx_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r4
  idAnimatedEntity *v3; // r29
  const enumTypeInfo_t *EnumInfo; // r4
  const enumValueInfo_t *EnumValueInfo; // r3
  int value; // r4
  idStr v7[2]; // [sp+60h] [-40h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    idStr::idStr(this: v7, text: "FX_NONE");
    if ( args->argc > 1 )
      idStr::operator=(this: v7, text: args->argv[1]);
    v3 = (idAnimatedEntity *)gameLocal->FindEntity(this: gameLocal, a2: "testFxEntity");
    if ( v3 != nullptr )
    {
      EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: "fxCondition_t");
      if ( EnumInfo != nullptr
        && (EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                              this: typeInfoTools,
                              enumInfo: EnumInfo,
                              name: v7[0].data,
                              defaultIfNotFound: false)) != nullptr )
      {
        value = EnumValueInfo->value;
      }
      else
      {
        value = 0;
      }
      idAnimatedEntity::StopFX(this: v3, condition: value);
    }
    idStr::FreeData(this: v7);
  }
}


// ========================================================================
// __unwind$496225
// EA  : 0x82E53CE4
// RVA : 0x00E53CE4
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_496225()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Spawn_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E53D10
// RVA : 0x00E53D10
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Spawn_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r31
  idPresentable *presentable; // r3
  const idAngles *v5; // r4
  double v6; // fp30
  idPhysics *Physics; // r31
  idVec3 *v8; // r3
  double v9; // fp29
  double v10; // fp28
  double v11; // fp27
  float *v12; // r3
  double v13; // fp9
  int argc; // r11
  double v15; // fp5
  int v16; // r31
  const char *v17; // r3
  long double v18; // fp2
  const char *v19; // r3
  long double v20; // fp2
  const char *v21; // r3
  long double v22; // fp2
  const char *v23; // r4
  const idDeclEntityDef *v24; // r30
  idEntity *v25; // r31
  idVec3 v26; // [sp+50h] [-C0h] BYREF
  idVec3 v27; // [sp+60h] [-B0h] BYREF
  idMat3 v28; // [sp+70h] [-A0h] BYREF
  float v29; // [sp+94h] [-7Ch]
  float v30; // [sp+98h] [-78h]
  float v31; // [sp+9Ch] [-74h]
  float v32; // [sp+A0h] [-70h]
  float v33; // [sp+A4h] [-6Ch]
  float v34; // [sp+A8h] [-68h]
  float v35; // [sp+ACh] [-64h]
  float v36; // [sp+B0h] [-60h]

  if ( args->argc == 1 )
  {
    idLib::Printf(fmt: "USAGE: spawn <entity def name> [location]\n");
    return;
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: v3) != 0 )
  {
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v5 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = nullptr;
    v6 = *((float *)&idPresentablePlayer::GetViewAngles(
                       this: (idPresentablePlayer *)&v28.mat[1].y,
                       result: v5,
                       includeWeaponKick: true)->__vftable
         + 1);
    v27.y = v6;
    Physics = idEntity::GetPhysics(this: v3);
    v27.x = 0.0;
    v27.z = 0.0;
    v8 = idAngles::ToForward(this: (idAngles *)&v28.mat[1].y, result: &v27);
    v9 = (float)(v8->x * (float)80.0);
    v10 = (float)(v8->y * (float)80.0);
    v11 = (float)(v8->z * (float)80.0);
    v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v13 = (float)(v12[2] + (float)v11);
    argc = args->argc;
    v15 = (float)(v12[1] + (float)v10);
    v26.x = *v12 + (float)v9;
    v26.y = v15;
    v26.z = (float)v13 + (float)1.0;
    if ( argc > 2 )
    {
      if ( argc != 7 && argc != 5 )
      {
        idLib::Printf(fmt: "Invalid number of parameters. Specify location as \"( x y z )\" or \"x y z\"\n");
        return;
      }
      v16 = 2;
      if ( argc == 7 )
        v16 = 3;
      if ( v16 >= argc )
        v17 = &byte_8200D768;
      else
        v17 = args->argv[v16];
      v18 = atof(nptr: v17);
      v26.x = *(double *)&v18;
      if ( v16 + 1 < 0 || v16 + 1 >= args->argc )
        v19 = &byte_8200D768;
      else
        v19 = args->argv[v16 + 1];
      v20 = atof(nptr: v19);
      v26.y = *(double *)&v20;
      if ( v16 + 2 < 0 || v16 + 2 >= args->argc )
        v21 = &byte_8200D768;
      else
        v21 = args->argv[v16 + 2];
      v22 = atof(nptr: v21);
      v26.z = *(double *)&v22;
    }
    if ( args->argc <= 1 )
    {
      v23 = &byte_8200D768;
    }
    else
    {
      v23 = args->argv[1];
      if ( v23 == nullptr )
      {
LABEL_30:
        idLib::Printf(fmt: "entityDef not found\n");
        return;
      }
    }
    v24 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclEntityDef::resourceList,
                                     name: v23,
                                     makeDefault: false);
    if ( v24 == nullptr )
      goto LABEL_30;
    v25 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v24, a3: -1, a4: -1, a5: -1);
    if ( v25 != nullptr )
    {
      v28.mat[0].x = 0.0;
      v28.mat[0].z = 0.0;
      v28.mat[0].y = (float)v6 + (float)180.0;
      idAngles::ToMat3(this: (idAngles *)&v28.mat[2].z, result: &v28);
      v25->spawnPosition = v26;
      v25->spawnOrientation.mat[0].x = v28.mat[2].z;
      v25->spawnOrientation.mat[0].y = v29;
      v25->spawnOrientation.mat[0].z = v30;
      v25->spawnOrientation.mat[1].x = v31;
      v25->spawnOrientation.mat[1].y = v32;
      v25->spawnOrientation.mat[1].z = v33;
      v25->spawnOrientation.mat[2].x = v34;
      v25->spawnOrientation.mat[2].y = v35;
      v25->spawnOrientation.mat[2].z = v36;
      idEntity::SetOrigin(this: v25, org: &v26);
      v25->SetAxis(this: v25, a2: (idMat3 *)&v28.mat[2].z);
    }
    else
    {
      idLib::Printf(fmt: "couldn't spawn %s\n", v24->name.str);
    }
  }
}


// ========================================================================
// ?VehSpawn_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E540B0
// RVA : 0x00E540B0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall VehSpawn_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r29
  const char *v4; // r4
  const idDeclEntityDef *v5; // r30
  idEntity *v6; // r31
  idEntity *v7; // r30
  idPresentable *presentable; // r3
  const idAngles *v9; // r4
  double v10; // fp29
  idPhysics *Physics; // r30
  double valueFloat; // fp30
  double v13; // fp27
  double v14; // fp28
  idVec3 *v15; // r3
  double v16; // fp26
  double v17; // fp25
  double v18; // fp27
  float *v19; // r3
  double v20; // fp9
  double v21; // fp7
  double v22; // fp6
  idVec3 v23; // [sp+50h] [-C0h] BYREF
  idVec3 v24; // [sp+60h] [-B0h] BYREF
  idMat3 v25; // [sp+70h] [-A0h] BYREF
  float v26; // [sp+94h] [-7Ch]
  float v27; // [sp+98h] [-78h]
  float v28; // [sp+9Ch] [-74h]
  float v29; // [sp+A0h] [-70h]
  float v30; // [sp+A4h] [-6Ch]
  float v31; // [sp+A8h] [-68h]
  float v32; // [sp+ACh] [-64h]
  float v33; // [sp+B0h] [-60h]

  if ( args->argc != 2 )
  {
    idLib::Printf(fmt: "USAGE: spawn <entity def name>\n");
    return;
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0
    && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: v3) != 0 )
  {
    if ( args->argc <= 1 )
    {
      v4 = &byte_8200D768;
    }
    else
    {
      v4 = args->argv[1];
      if ( v4 == nullptr )
      {
LABEL_9:
        idLib::Printf(fmt: "entityDef not found\n");
        return;
      }
    }
    v5 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclEntityDef::resourceList,
                                    name: v4,
                                    makeDefault: false);
    if ( v5 == nullptr )
      goto LABEL_9;
    v6 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v5, a3: -1, a4: -1, a5: -1);
    if ( v6 != nullptr )
    {
      v7 = v3->GetVehicle_2(this: v3);
      if ( v7 != nullptr )
      {
        presentable = v3->presentable;
        if ( presentable != nullptr )
          v9 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
        else
          v9 = nullptr;
        v10 = *((float *)&idPresentablePlayer::GetViewAngles(
                            this: (idPresentablePlayer *)&v25.mat[1].y,
                            result: v9,
                            includeWeaponKick: true)->__vftable
              + 1);
        v24.y = v10;
        Physics = idEntity::GetPhysics(this: v7);
        v24.x = 0.0;
        v24.z = 0.0;
        valueFloat = veh_spawn_height.valueFloat;
        v13 = veh_spawn_distance.valueFloat;
        v14 = (float)(veh_spawn_height.valueFloat * (float)0.0);
        v15 = idAngles::ToForward(this: (idAngles *)&v25.mat[1].y, result: &v24);
        v16 = (float)(v15->x * (float)v13);
        v17 = (float)(v15->y * (float)v13);
        v18 = (float)(v15->z * (float)v13);
        v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v20 = (float)(*v19 + (float)v16);
        v21 = (float)(v19[1] + (float)v17);
        v22 = (float)(v19[2] + (float)v18);
        v25.mat[0].x = 0.0;
        v25.mat[0].y = (float)v10 + (float)180.0;
        v25.mat[0].z = 0.0;
        v23.x = (float)v20 + (float)v14;
        v23.y = (float)v21 + (float)v14;
        v23.z = (float)v22 + (float)valueFloat;
        idAngles::ToMat3(this: (idAngles *)&v25.mat[2].z, result: &v25);
        v6->spawnPosition = v23;
        v6->spawnOrientation.mat[0].x = v25.mat[2].z;
        v6->spawnOrientation.mat[0].y = v26;
        v6->spawnOrientation.mat[0].z = v27;
        v6->spawnOrientation.mat[1].x = v28;
        v6->spawnOrientation.mat[1].y = v29;
        v6->spawnOrientation.mat[1].z = v30;
        v6->spawnOrientation.mat[2].x = v31;
        v6->spawnOrientation.mat[2].y = v32;
        v6->spawnOrientation.mat[2].z = v33;
        idEntity::SetOrigin(this: v6, org: &v23);
        v6->SetAxis(this: v6, a2: (idMat3 *)&v25.mat[2].z);
      }
    }
    else
    {
      idLib::Printf(fmt: "couldn't spawn %s\n", v5->name.str);
    }
  }
}


// ========================================================================
// ?testUnlock_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E543A8
// RVA : 0x00E543A8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall testUnlock_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r30
  idResource *v4; // r3
  idResource *v5; // r31
  const char *LocalizedString; // r3
  idStrId v7; // [sp+50h] [-20h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atol(nptr: v2);
    idDeclInfo::FindWithInheritance(
      this: &idDeclVehicleUnlock::resourceList,
      name: "vehicle/unlocks/online/machine_gun_01",
      makeDefault: true);
    if ( v3 >= 0 && v3 < idDeclVehicleUnlock::resourceList.num )
    {
      v4 = idResourceList::Index(this: &idDeclVehicleUnlock::resourceList, index: v3);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v7.index = (int)v4[2].__vftable;
        LocalizedString = idStrId::GetLocalizedString(this: &v7);
        idLib::Printf(fmt: "%s\n", LocalizedString);
        if ( (int)v5[3].resourceError <= 0 )
          idLib::Printf(fmt: "no items in this list???\n");
        else
          idLib::Printf(
            fmt: "type: %d count: %d\n",
            v5[3].resourceListPtr->hashTable[20],
            v5[3].resourceListPtr->hashTable[19]);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "testUnlock is only available in multiplayer");
  }
}


// ========================================================================
// ?DebugGiveAchievement@@YAXPBVidDeclAchievement@@@Z
// EA  : 0x82E544D0
// RVA : 0x00E544D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall DebugGiveAchievement(const idDeclAchievement *achievementDecl)
{
  idLocalUser *v2; // r25
  idPlayer *DebugPlayer; // r28
  idPlayerHud *PlayerHud; // r3
  int num; // r24
  int v6; // r27
  idDeclAchievement::statConstraint_t *v7; // r30
  __int64 v8; // r10
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idDeclOnlineLevel *v13; // r3
  int XpRequiredForLevel; // r22
  int v15; // r6
  __int64 v16; // r9
  bool IsInt; // r3
  rageStat_t stat; // r5
  idRageMetrics *rageMetrics; // r3
  bool v20; // zf
  int count; // r22
  int v22; // r6
  double v23; // fp1
  int v24; // r25
  int v25; // r27
  char *data; // r4
  const idDeclInventory *v27; // r29
  int v28; // r30
  idPresentable *presentable; // r31
  idInventoryCollection *v30; // r3
  int v31; // r30
  int v32; // r31
  int v33; // r30
  int v34; // r31
  int v35; // r30
  int v36; // r31
  int v37; // r30
  int v38; // r31
  idPresentable *v39; // r3
  int v40; // r3

  if ( achievementDecl != nullptr )
  {
    if ( gameLocal != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
    {
      if ( session != nullptr )
      {
        v2 = common->GetMasterLocalUser(this: common);
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        DebugPlayer->jobManager.inDebug = true;
        PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
        idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
        if ( v2 != nullptr )
        {
          if ( achievementDecl->events.num > 0 )
          {
            num = achievementDecl->events.num;
            v6 = 0;
            do
            {
              v7 = &achievementDecl->events.list[v6];
              if ( GetStatAsInt(user: v2, stat: v7->stat) < v7->count )
              {
                if ( v7->stat == RAGE_STAT_MP_LEVEL )
                {
                  v13 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
                  if ( v13 != nullptr )
                  {
                    XpRequiredForLevel = idDeclOnlineLevel::GetXpRequiredForLevel(
                                           this: v13,
                                           level: v7->count,
                                           a3: v12,
                                           a4: v11,
                                           a5: v10,
                                           a6: v9,
                                           a7: v8);
                    v15 = XpRequiredForLevel
                        - idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: DebugPlayer, stat: 23);
                    if ( v15 > 0 )
                      idRageMetrics::StatAddInt(
                        this: clientGame->rageMetrics,
                        player: DebugPlayer,
                        stat: RAGE_STAT_MP_XP,
                        value: v15);
                  }
                }
                IsInt = RageStatTypeIsInt(stat: v7->stat);
                stat = v7->stat;
                v20 = !IsInt;
                rageMetrics = clientGame->rageMetrics;
                if ( v20 )
                {
                  LODWORD(v16) = v7->count;
                  v23 = (float)((float)v16 - idRageMetrics::GetStatFloat(this: rageMetrics, player: DebugPlayer, stat));
                  if ( v23 > 0.0 )
                    idRageMetrics::StatAddFloat(
                      this: clientGame->rageMetrics,
                      player: DebugPlayer,
                      stat: v7->stat,
                      value: v23);
                }
                else
                {
                  count = v7->count;
                  v22 = count - idRageMetrics::GetStatInt(this: rageMetrics, player: DebugPlayer, stat);
                  if ( v22 > 0 )
                    idRageMetrics::StatAddInt(
                      this: clientGame->rageMetrics,
                      player: DebugPlayer,
                      stat: v7->stat,
                      value: v22);
                }
              }
              --num;
              ++v6;
            }
            while ( num != 0 );
          }
          v24 = 0;
          if ( achievementDecl->item.num > 0 )
          {
            v25 = 0;
            do
            {
              data = achievementDecl->item.list[v25].itemDecl.data;
              if ( data != nullptr )
                v27 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclInventory::resourceList,
                                                 name: data,
                                                 makeDefault: true);
              else
                v27 = nullptr;
              v28 = achievementDecl->item.list[v25].count;
              if ( v28 > 0 )
              {
                do
                {
                  presentable = DebugPlayer->presentable;
                  if ( presentable == nullptr )
                  {
                    idEntity::InitPresentableInternal(this: DebugPlayer);
                    presentable = DebugPlayer->presentable;
                  }
                  v30 = DebugPlayer->GetInventory_2(this: DebugPlayer);
                  idInventoryCollection::GiveItem(
                    this: v30,
                    owner: presentable,
                    decl: v27,
                    count: 1,
                    forceCount: false,
                    canIntro: false);
                  --v28;
                }
                while ( v28 != 0 );
              }
              ++v24;
              ++v25;
            }
            while ( v24 < achievementDecl->item.num );
          }
          v31 = 0;
          if ( achievementDecl->jobDecl.num > 0 )
          {
            v32 = 0;
            do
            {
              idJobManager::SetJobReadyToTurnIn(
                this: &DebugPlayer->jobManager,
                jobName: achievementDecl->jobDecl.list[v32].data,
                completeTree: true,
                giveJobIfNeeded: true,
                hideIfGiven: false,
                force: false);
              ++v31;
              ++v32;
            }
            while ( v31 < achievementDecl->jobDecl.num );
          }
          v33 = 0;
          if ( achievementDecl->trigger.num > 0 )
          {
            v34 = 0;
            do
            {
              idAchievementManager::TriggerCompletesAchievement(
                this: &DebugPlayer->achievementManager,
                taid: achievementDecl->trigger.list[v34]);
              ++v33;
              ++v34;
            }
            while ( v33 < achievementDecl->trigger.num );
          }
          v35 = 0;
          if ( achievementDecl->races.num > 0 )
          {
            v36 = 0;
            do
            {
              idJobManager::SetBestRacePlace(
                this: &DebugPlayer->jobManager,
                raceDeclName: achievementDecl->races.list[v36].raceName.data,
                place: (idVoiceEvent_vtbl *)4);
              ++v35;
              ++v36;
            }
            while ( v35 < achievementDecl->races.num );
          }
          if ( achievementDecl->achievements.num != 0 )
          {
            idLib::Warning(
              fmt: "Achievement %s needs other achievements, not giving directly so this will fail",
              achievementDecl->name.str);
            v37 = 0;
            if ( achievementDecl->achievements.num > 0 )
            {
              v38 = 0;
              do
              {
                idLib::Printf(fmt: "  %d\n", achievementDecl->achievements.list[v38]);
                ++v37;
                ++v38;
              }
              while ( v37 < achievementDecl->achievements.num );
            }
          }
        }
        v39 = DebugPlayer->presentable;
        DebugPlayer->jobManager.inDebug = false;
        if ( v39 != nullptr )
        {
          v40 = (int)v39->GetPlayerInterface_2(this: v39);
          idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v40 + 35096), ignore: false);
        }
        else
        {
          idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)0x8918, ignore: false);
        }
      }
      else
      {
        idLib::Printf(fmt: "Invalid session\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Unable to find achievement decl.\n");
  }
}


// ========================================================================
// ?achievementsGive_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E54960
// RVA : 0x00E54960
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsGive_f(const idCmdArgs *args)
{
  char *v2; // r4
  const idDeclAchievement *v3; // r3

  if ( args->argc == 2 )
  {
    if ( gameLocal != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
    {
      if ( session != nullptr )
      {
        if ( args->argc <= 1 )
          v2 = &byte_8200D768;
        else
          v2 = args->argv[1];
        v3 = (const idDeclAchievement *)idResourceList::Load(
                                          this: &idDeclAchievement::resourceList,
                                          name: v2,
                                          makeDefault: false,
                                          skipStaleCheck: false);
        if ( v3 != nullptr )
          DebugGiveAchievement(achievementDecl: v3);
        else
          idLib::Warning(fmt: "no achievement found for inputed string");
      }
      else
      {
        idLib::Printf(fmt: "Invalid session\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: achievementsGive <idDeclAchievement>\n");
  }
}


// ========================================================================
// ?achievementsGiveAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E54A50
// RVA : 0x00E54A50
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsGiveAll_f(const idCmdArgs *args)
{
  int v1; // r31
  int i; // r29
  const idDeclAchievement *v3; // r3

  if ( session != nullptr )
  {
    if ( gameLocal != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
      && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
    {
      v1 = 0;
      for ( i = idDeclAchievement::resourceList.num; v1 < i; ++v1 )
      {
        v3 = (const idDeclAchievement *)idResourceList::Index(this: &idDeclAchievement::resourceList, index: v1);
        DebugGiveAchievement(achievementDecl: v3);
      }
    }
    else
    {
      idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Invalid session\n");
  }
}


// ========================================================================
// ?achievementsSetEndUnlockedState_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E54B00
// RVA : 0x00E54B00
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsSetEndUnlockedState_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31
  int v2; // r29
  int i; // r22
  const idDeclAchievement *v4; // r30
  idPlayerHud *PlayerHud; // r3
  const idDeclInventory *v6; // r28
  idPresentable *presentable; // r29
  idInventoryCollection *v8; // r3
  const idDeclInventory *v9; // r28
  idPresentable *v10; // r29
  idInventoryCollection *v11; // r3
  const idDeclInventory *v12; // r26
  idPresentable *v13; // r28
  idInventoryCollection *v14; // r3
  const idDeclInventory *v15; // r28
  idPresentable *v16; // r29
  idInventoryCollection *v17; // r3
  const idDeclInventory *v18; // r29
  idPresentable *v19; // r30
  idInventoryCollection *v20; // r3
  int v21; // r30
  int j; // r28
  const idDeclGameStateInt *v23; // r3
  idPresentable *v24; // r3
  int v25; // r3

  if ( session == nullptr )
    goto LABEL_2;
  if ( gameLocal != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
  {
    if ( session == nullptr )
    {
LABEL_2:
      idLib::Printf(fmt: "Invalid session\n");
      return;
    }
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v2 = 0;
    for ( i = idDeclAchievement::resourceList.num; v2 < i; ++v2 )
    {
      v4 = (const idDeclAchievement *)idResourceList::Index(this: &idDeclAchievement::resourceList, index: v2);
      if ( idStr::Icmp(s1: v4->name.str, s2: "achievement_44") != 0
        && idStr::Icmp(s1: v4->name.str, s2: "achievement_40") != 0
        && idStr::Icmp(s1: v4->name.str, s2: "achievement_41") != 0
        && idStr::Icmp(s1: v4->name.str, s2: "achievement_42") != 0
        && idStr::Icmp(s1: v4->name.str, s2: "achievement_43") != 0 )
      {
        DebugGiveAchievement(achievementDecl: v4);
      }
    }
    DebugPlayer->jobManager.inDebug = true;
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: DebugPlayer);
    idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
    idJobManager::AcceptJob(
      this: &DebugPlayer->jobManager,
      name: "jobs/wasteland2/subwaytown/assault_capital_prime",
      completeTree: true,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/protect_settler",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/mutant_menace",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/exchange",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/ghost_hideout_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/dam_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland1/wellspring/posted/phallinx_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland2/subwaytown/posted/distillery_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland2/subwaytown/posted/cave_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idJobManager::SetJobReadyToTurnIn(
      this: &DebugPlayer->jobManager,
      jobName: "jobs/wasteland2/subwaytown/posted/plaza_1",
      completeTree: true,
      giveJobIfNeeded: true,
      hideIfGiven: false,
      force: false);
    idGameLayerManager::RemoveActiveLayer(this: &DebugPlayer->gameLayerManager, layerName: "lay/jumps");
    v6 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclInventory::resourceList,
                                    name: "inventory/spdatacollection/recipies",
                                    makeDefault: true);
    if ( DebugPlayer->presentable == nullptr )
      idEntity::InitPresentableInternal(this: DebugPlayer);
    presentable = DebugPlayer->presentable;
    v8 = DebugPlayer->GetInventory_2(this: DebugPlayer);
    idInventoryCollection::GiveItem(
      this: v8,
      owner: presentable,
      decl: v6,
      count: 1,
      forceCount: false,
      canIntro: false);
    v9 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclInventory::resourceList,
                                    name: "inventory/spdatacollection/weapons",
                                    makeDefault: true);
    if ( DebugPlayer->presentable == nullptr )
      idEntity::InitPresentableInternal(this: DebugPlayer);
    v10 = DebugPlayer->presentable;
    v11 = DebugPlayer->GetInventory_2(this: DebugPlayer);
    idInventoryCollection::GiveItem(this: v11, owner: v10, decl: v9, count: 1, forceCount: false, canIntro: false);
    v12 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclInventory::resourceList,
                                     name: "inventory/spdatacollection/collectorcards",
                                     makeDefault: true);
    if ( DebugPlayer->presentable == nullptr )
      idEntity::InitPresentableInternal(this: DebugPlayer);
    v13 = DebugPlayer->presentable;
    v14 = DebugPlayer->GetInventory_2(this: DebugPlayer);
    idInventoryCollection::GiveItem(this: v14, owner: v13, decl: v12, count: 1, forceCount: false, canIntro: false);
    v15 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclInventory::resourceList,
                                     name: "inventory/spdatacollection/collectorcards",
                                     makeDefault: true);
    if ( DebugPlayer->presentable == nullptr )
      idEntity::InitPresentableInternal(this: DebugPlayer);
    v16 = DebugPlayer->presentable;
    v17 = DebugPlayer->GetInventory_2(this: DebugPlayer);
    idInventoryCollection::GiveItem(this: v17, owner: v16, decl: v15, count: 1, forceCount: false, canIntro: false);
    v18 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclInventory::resourceList,
                                     name: "inventory/cardsets/basic_cardset",
                                     makeDefault: true);
    if ( DebugPlayer->presentable == nullptr )
      idEntity::InitPresentableInternal(this: DebugPlayer);
    v19 = DebugPlayer->presentable;
    v20 = DebugPlayer->GetInventory_2(this: DebugPlayer);
    idInventoryCollection::GiveItem(this: v20, owner: v19, decl: v18, count: 1, forceCount: false, canIntro: false);
    v21 = 0;
    for ( j = idDeclGameStateInt::resourceList.num; v21 < j; ++v21 )
    {
      v23 = (const idDeclGameStateInt *)idResourceList::Index(this: &idDeclGameStateInt::resourceList, index: v21);
      idJobManager::SetGameStateIntValue(this: &DebugPlayer->jobManager, gameState: v23, stateValue: 1);
    }
    v24 = DebugPlayer->presentable;
    DebugPlayer->jobManager.inDebug = false;
    if ( v24 != nullptr )
    {
      v25 = (int)v24->GetPlayerInterface_2(this: v24);
      idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v25 + 35096), ignore: false);
    }
    else
    {
      idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)0x8918, ignore: false);
    }
  }
  else
  {
    idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n");
  }
}


// ========================================================================
// ?achievementsClear_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55050
// RVA : 0x00E55050
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsClear_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const idDecl *v3; // r30
  idLocalUser *v4; // r3

  if ( gameLocal != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
  {
    if ( args->argc == 2 )
    {
      v2 = args->argv[1];
      if ( v2 != nullptr
        && (v3 = idDeclInfo::FindWithInheritance(this: &idDeclAchievement::resourceList, name: v2, makeDefault: false)) != nullptr )
      {
        if ( common != nullptr && session != nullptr )
        {
          v4 = (idLocalUser *)((int (*)(void))common->GetMasterLocalUser)();
          session->achievementSystem->AchievementLock(
            this: session->achievementSystem,
            a2: v4,
            a3: (const int)v3[1].resourceListPtr);
        }
        else
        {
          idLib::Printf(fmt: "Unable to execute command.\n");
        }
      }
      else
      {
        idLib::Printf(fmt: "Unable to find achievement decl.\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "Usage: achievementsClear <idDeclAchievement>\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "You must be in a game to give achievements, a box map will do...\n");
  }
}


// ========================================================================
// ?achievementsProgress_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55168
// RVA : 0x00E55168
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsProgress_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  idLocalUser *LocalUser; // r26
  int v4; // r30
  int num; // r23
  idAchievementManager *p_achievementManager; // r22
  idResource *v7; // r3
  idStrId *v8; // r31
  double AchievementCompletionPercent; // fp31
  const char *LocalizedString; // r29
  idPlayerProfile *v11; // r3
  unsigned __int8 Achievement; // r3
  bool v13; // [sp+60h] [-80h] BYREF
  int v14; // [sp+64h] [-7Ch] BYREF
  int v15; // [sp+68h] [-78h] BYREF

  if ( gameLocal != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr
    && idGameLocal::GetDebugPlayer(this: gameLocal)->achievementManager.owner != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v2 = DebugPlayer;
    if ( DebugPlayer != nullptr )
    {
      LocalUser = idPlayer::GetLocalUser(this: DebugPlayer);
      if ( LocalUser != nullptr )
      {
        v4 = 0;
        num = idDeclAchievement::resourceList.num;
        if ( idDeclAchievement::resourceList.num > 0 )
        {
          p_achievementManager = &v2->achievementManager;
          do
          {
            v7 = idResourceList::Index(this: &idDeclAchievement::resourceList, index: v4);
            v15 = 0;
            v14 = 0;
            v8 = (idStrId *)v7;
            v13 = false;
            AchievementCompletionPercent = idAchievementManager::GetAchievementCompletionPercent(
                                             this: p_achievementManager,
                                             id: (const achievementId_t)v7[2].__vftable,
                                             gained: &v15,
                                             required: &v14,
                                             isFulfilled: &v13);
            LocalizedString = idStrId::GetLocalizedString(this: v8 + 16);
            idStrId::GetLocalizedString(this: v8 + 17);
            if ( LocalizedString == nullptr )
              LocalizedString = &byte_8200D768;
            v11 = LocalUser->GetProfile(this: LocalUser);
            Achievement = idPlayerProfile::GetAchievement(this: v11, id: v4);
            idLib::Printf(
              fmt: "[%03d/%03d - %3.0f%%] (%02d) (%d) (ach bit: %d) ^3%s^0 - %s\n",
              v15,
              v14,
              (float)((float)AchievementCompletionPercent * (float)100.0),
              (unsigned int)COERCE_UNSIGNED_INT64((float)((float)AchievementCompletionPercent * (float)100.0)),
              ++v4,
              v13,
              (const char *)Achievement,
              LocalizedString);
          }
          while ( v4 < num );
        }
      }
    }
    else
    {
      idLib::Printf(fmt: "Unable to execute command.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "You must be in a game to see achievements, a box map will do...\n");
  }
}


// ========================================================================
// ?achievementsTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55318
// RVA : 0x00E55318
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsTest_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r31
  char v2; // r25
  int v3; // r19
  int v4; // r26
  char v5; // r23
  int num; // r21
  int v7; // r24
  idStrId *v8; // r3
  idStrId *v9; // r30
  const char *LocalizedString; // r28
  const char *v11; // r3
  const char *v12; // r27
  const char *v13; // r10
  char *v14; // r11
  int v15; // r9
  unsigned int v16; // r9
  bool v17; // zf
  const char *v18; // r10
  bool v19; // r8
  char *v20; // r11
  int v21; // r9
  unsigned int v22; // r9
  BOOL v23; // r31
  bool v24; // r29
  const char *v25; // r5
  const char *v26; // r5
  const char *v27; // r5
  int v28; // [sp+50h] [-690h]
  idLocalUser *v29; // [sp+54h] [-68Ch]
  char v30[500]; // [sp+60h] [-680h] BYREF
  char v31[1164]; // [sp+254h] [-48Ch] BYREF

  if ( common == nullptr || session == nullptr )
  {
    idLib::Printf(fmt: "Can't execute test.\n");
    return;
  }
  v1 = (idLocalUser *)((int (*)(void))common->GetMasterLocalUser)();
  v29 = v1;
  if ( v1 == nullptr )
  {
    idLib::Printf(fmt: "^1Unable to execute command.\n");
    return;
  }
  v2 = 0;
  v28 = 0;
  v3 = 1;
  v4 = 0;
  do
  {
    idLib::Printf(fmt: "^8%03d^0: ", v3);
    if ( !session->achievementSystem->GetAchievementDescription(
            this: session->achievementSystem,
            a2: v1,
            a3: v3,
            a4: (achievementDescription_t *)v30) )
    {
      idLib::Printf(fmt: "[^1FAILED^0], Error retrieving achievement data online.\n");
      v2 = 1;
      goto LABEL_33;
    }
    v5 = 0;
    num = idDeclAchievement::resourceList.num;
    v7 = 0;
    ++v28;
    if ( idDeclAchievement::resourceList.num > 0 )
    {
      do
      {
        v8 = (idStrId *)idResourceList::Index(this: &idDeclAchievement::resourceList, index: v7);
        v9 = v8;
        if ( v8[18].index == v3 )
        {
          v5 = 1;
          LocalizedString = idStrId::GetLocalizedString(this: v8 + 16);
          v11 = idStrId::GetLocalizedString(this: v9 + 17);
          v12 = v11;
          v13 = LocalizedString;
          v14 = v30;
          do
          {
            v15 = (unsigned __int8)*v14;
            v17 = v15 == 0;
            v16 = v15 - *(unsigned __int8 *)v13;
            if ( v17 )
              break;
            ++v14;
            ++v13;
          }
          while ( v16 == 0 );
          v18 = v11;
          v19 = (_cntlzw(v16) & 0x20) != 0;
          v20 = v31;
          do
          {
            v21 = (unsigned __int8)*v20;
            v17 = v21 == 0;
            v22 = v21 - *(unsigned __int8 *)v18;
            if ( v17 )
              break;
            ++v20;
            ++v18;
          }
          while ( v22 == 0 );
          v23 = v19;
          v24 = (_cntlzw(v22) & 0x20) != 0;
          if ( v19 && v24 )
            idLib::Printf(fmt: "[^2PASSED^0], ^3%s^0, decl: %s\n", LocalizedString, (const char *)v9[2].index);
          else
            idLib::Printf(fmt: "[^1FAILED^0],\n");
          if ( !v23 )
          {
            v25 = &byte_8200D768;
            if ( LocalizedString != nullptr && *LocalizedString != 10 )
              v25 = LocalizedString;
            idLib::Printf(fmt: "\tname: online(^3%s^0), decl(^3%s^0).\n", v30, v25);
            ++v4;
            v2 = 1;
          }
          if ( !v24 )
          {
            v26 = &byte_8200D768;
            if ( v12 != nullptr && *v12 != 10 )
              v26 = v12;
            idLib::Printf(fmt: "\tdesc: online(^3%s^0), decl(^3%s^0).\n", v31, v26);
            ++v4;
            v2 = 1;
          }
        }
        ++v7;
      }
      while ( v7 < num );
      v1 = v29;
    }
    if ( v5 == 0 )
    {
      idLib::Printf(fmt: "[^1FAILED^0], Error finding achievement (^3%s^0) in decls.\n", v30);
LABEL_33:
      ++v4;
    }
    ++v3;
  }
  while ( v3 < 51 );
  idLib::Printf(fmt: "\nTotal online achievements: %d\n", v28);
  idLib::Printf(fmt: "Total decl achievements: %d\n", idDeclAchievement::resourceList.num);
  if ( v4 <= 0 )
    v27 = "^2";
  else
    v27 = "^1";
  if ( v2 != 0 )
    idLib::Printf(fmt: "[%s] %s%d^0 total errors.\n", "^1FAILED^0", v27, v4);
  else
    idLib::Printf(fmt: "[%s] %s%d^0 total errors.\n", "^2PASSED^0", v27, v4);
}


// ========================================================================
// ?achievementsTestCompletion_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55668
// RVA : 0x00E55668
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsTestCompletion_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r3
  idLocalUser *v2; // r26
  char v3; // r24
  int v4; // r23
  int i; // r21
  idPlayerProfile *v6; // r3
  char Achievement; // r18
  char v8; // r17
  char v9; // r25
  int num; // r22
  int v11; // r26
  idStrId *v12; // r3
  idStrId *v13; // r30
  const char *LocalizedString; // r28
  const char *v15; // r3
  const char *v16; // r27
  const char *v17; // r10
  char *v18; // r11
  int v19; // r9
  unsigned int v20; // r9
  bool v21; // zf
  const char *v22; // r10
  bool v23; // r8
  char *v24; // r11
  int v25; // r9
  unsigned int v26; // r9
  BOOL v27; // r31
  bool v28; // r29
  const char *v29; // r5
  const char *v30; // r5
  const char *v31; // r5
  const char *v32; // r4
  const char *v33; // r5
  const char *v34; // r4
  const char *v35; // r5
  int v36; // [sp+50h] [-730h]
  int v37; // [sp+54h] [-72Ch]
  idLocalUser *v38; // [sp+58h] [-728h]
  _BYTE v39[128]; // [sp+80h] [-700h] BYREF
  char v40[500]; // [sp+100h] [-680h] BYREF
  char v41[1164]; // [sp+2F4h] [-48Ch] BYREF

  if ( common != nullptr )
  {
    v1 = common->GetMasterLocalUser(this: common);
    v2 = v1;
    v38 = v1;
    if ( v1 != nullptr )
    {
      v3 = 0;
      v36 = 0;
      v4 = 0;
      v37 = 0;
      session->achievementSystem->GetAchievementState(
        this: session->achievementSystem,
        a2: v1,
        a3: (idArray<bool,128> *)v39);
      for ( i = 1; i < 51; ++i )
      {
        idLib::Printf(fmt: "^8%03d^0: ", i);
        v6 = v2->GetProfile(this: v2);
        Achievement = idPlayerProfile::GetAchievement(this: v6, id: i);
        v8 = v39[i];
        if ( session->achievementSystem->GetAchievementDescription(
               this: session->achievementSystem,
               a2: v2,
               a3: i,
               a4: (achievementDescription_t *)v40) )
        {
          v9 = 0;
          num = idDeclAchievement::resourceList.num;
          v11 = 0;
          ++v36;
          if ( idDeclAchievement::resourceList.num > 0 )
          {
            do
            {
              v12 = (idStrId *)idResourceList::Index(this: &idDeclAchievement::resourceList, index: v11);
              v13 = v12;
              if ( v12[18].index == i )
              {
                v9 = 1;
                LocalizedString = idStrId::GetLocalizedString(this: v12 + 16);
                v15 = idStrId::GetLocalizedString(this: v13 + 17);
                v16 = v15;
                v17 = LocalizedString;
                v18 = v40;
                do
                {
                  v19 = (unsigned __int8)*v18;
                  v21 = v19 == 0;
                  v20 = v19 - *(unsigned __int8 *)v17;
                  if ( v21 )
                    break;
                  ++v18;
                  ++v17;
                }
                while ( v20 == 0 );
                v22 = v15;
                v23 = (_cntlzw(v20) & 0x20) != 0;
                v24 = v41;
                do
                {
                  v25 = (unsigned __int8)*v24;
                  v21 = v25 == 0;
                  v26 = v25 - *(unsigned __int8 *)v22;
                  if ( v21 )
                    break;
                  ++v24;
                  ++v22;
                }
                while ( v26 == 0 );
                v27 = v23;
                v28 = (_cntlzw(v26) & 0x20) != 0;
                if ( v23 && v28 )
                  idLib::Printf(fmt: "[^2PASSED^0], ^3%s^0, decl: %s\n", LocalizedString, v13[2].index);
                else
                  idLib::Printf(fmt: "[^1FAILED^0],\n");
                if ( !v27 )
                {
                  v29 = &byte_8200D768;
                  if ( LocalizedString != nullptr && *LocalizedString != 10 )
                    v29 = LocalizedString;
                  idLib::Printf(fmt: "\tname: online(^3%s^0), decl(^3%s^0).\n", v40, v29);
                  ++v4;
                  v3 = 1;
                }
                if ( !v28 )
                {
                  v30 = &byte_8200D768;
                  if ( v16 != nullptr && *v16 != 10 )
                    v30 = v16;
                  idLib::Printf(fmt: "\tdesc: online(^3%s^0), decl(^3%s^0).\n", v41, v30);
                  ++v4;
                  v3 = 1;
                }
              }
              ++v11;
            }
            while ( v11 < num );
          }
          if ( v9 == 0 )
          {
            idLib::Printf(fmt: "[^1FAILED^0], Error finding achievement (^3%s^0) in decls.\n", v40);
            ++v4;
          }
          v2 = v38;
        }
        else
        {
          idLib::Printf(fmt: "[^1FAILED^0], Error retrieving achievement data online.\n");
          ++v4;
          v3 = 1;
        }
        if ( v3 == 0 )
        {
          if ( Achievement == v8 )
          {
            idLib::Printf(fmt: "   [MATCH],     ");
          }
          else
          {
            idLib::Printf(fmt: "[^1MISMATCH^0], ");
            v3 = 1;
            ++v37;
          }
          v31 = "^2SET^0";
          if ( Achievement == 0 )
            v31 = "^1NOT^0";
          v32 = "^2SET^0";
          if ( v8 == 0 )
            v32 = "^1NOT^0";
          idLib::Printf(fmt: "SERVER: %s,   PROFILE: %s\n---\n", v32, v31);
        }
      }
      idLib::Printf(fmt: "\nTotal online achievements: %d\n", v36);
      idLib::Printf(fmt: "Total decl achievements: %d\n", idDeclAchievement::resourceList.num);
      v33 = "^1";
      if ( v4 <= 0 )
        v33 = "^2";
      if ( v3 != 0 )
        v34 = "^1FAILED^0";
      else
        v34 = "^2PASSED^0";
      idLib::Printf(fmt: "[%s] %s%d^0 total errors.\n", v34, v33, v4);
      v35 = "^1";
      if ( v37 > 0 || (v35 = "^2", v37 != 0) )
        idLib::Printf(fmt: "[%s] %s%d^0 total mismatches.\n", "^1MISMATCH^0", v35, v37);
      else
        idLib::Printf(fmt: "[%s] %s%d^0 total mismatches.\n", "^2MATCH^0", "^2", 0);
    }
    else
    {
      idLib::Printf(fmt: "^1Unable to execute command. You must go past the start screen to run this test.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Can't execute test. You must go past the start screen to run this test.\n");
  }
}


// ========================================================================
// ?achievementsTestMismatches_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55AF0
// RVA : 0x00E55AF0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall achievementsTestMismatches_f(const idCmdArgs *args)
{
  idLocalUser *v1; // r3
  idLocalUser *v2; // r27
  int v3; // r20
  int i; // r29
  idPlayerProfile *v5; // r3
  int Achievement; // r30
  int v7; // r28
  const char *v8; // r5
  const char *v9; // r4
  const char *v10; // r5
  idStr v11; // [sp+50h] [-6F0h] BYREF
  _BYTE v12[128]; // [sp+70h] [-6D0h] BYREF
  char v13[1616]; // [sp+F0h] [-650h] BYREF

  if ( common != nullptr )
  {
    v1 = common->GetMasterLocalUser(this: common);
    v2 = v1;
    if ( v1 != nullptr )
    {
      v3 = 0;
      session->achievementSystem->GetAchievementState(
        this: session->achievementSystem,
        a2: v1,
        a3: (idArray<bool,128> *)v12);
      for ( i = 1; i < 51; ++i )
      {
        v5 = v2->GetProfile(this: v2);
        Achievement = (unsigned __int8)idPlayerProfile::GetAchievement(this: v5, id: i);
        v7 = (unsigned __int8)v12[i];
        if ( Achievement != v7 )
        {
          idStr::idStr(this: &v11, text: "Achievement Does Not Exist on server");
          if ( session->achievementSystem->GetAchievementDescription(
                 this: session->achievementSystem,
                 a2: v2,
                 a3: i,
                 a4: (achievementDescription_t *)v13) )
          {
            idStr::operator=(this: &v11, text: v13);
            idLib::Printf(fmt: "[^1MISMATCH^0], %d: %s\n", i, v11.data);
            v8 = "^2SET^0";
            if ( Achievement == 0 )
              v8 = "^1NOT^0";
            v9 = "^2SET^0";
            if ( v7 == 0 )
              v9 = "^1NOT^0";
            idLib::Printf(fmt: "   SERVER: %s,   PROFILE: %s\n---\n", v9, v8);
            ++v3;
          }
          idStr::FreeData(this: &v11);
        }
      }
      if ( v3 <= 0 )
        v10 = "^2";
      else
        v10 = "^1";
      if ( v3 != 0 )
        idLib::Printf(fmt: "---\n[%s] %s%d^0 total mismatches.\n", "^1MISMATCH^0", v10, v3);
      else
        idLib::Printf(fmt: "---\n[%s] %s%d^0 total mismatches.\n", "^2MATCH^0", v10, 0);
    }
    else
    {
      idLib::Printf(fmt: "^1Unable to execute command. You must go past the start screen to run this test.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "Can't execute test. You must go past the start screen to run this test.\n");
  }
}


// ========================================================================
// __unwind$497449_0
// EA  : 0x82E55CD4
// RVA : 0x00E55CD4
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_497449_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 80));
}


// ========================================================================
// ?setOnlineLevel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55D00
// RVA : 0x00E55D00
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineLevel_f(const idCmdArgs *args)
{
  idLobbyBase *v2; // r3
  idDeclOnlineLevel *v3; // r29
  idLocalUser *v4; // r3
  idLocalUser *v5; // r31
  int v6; // r27
  int v7; // r3
  int v8; // r28
  __int64 v9; // r10
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int v14; // r3
  int v15; // r30
  int num; // r4
  int XpRequiredForLevel; // r29
  idPlayerProfile *v18; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v2 = session->GetGameLobbyBase(this: session), v2->IsPeer(this: v2)) )
    {
      idLib::Warning(fmt: "Can't setOnlineLevel while you are a peer in a session");
    }
    else
    {
      v3 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
      if ( v3 != nullptr )
      {
        v4 = common->GetMasterLocalUser(this: common);
        v5 = v4;
        if ( v4 != nullptr )
        {
          v6 = v4->GetStatInt(this: v4, a2: 23);
          v7 = v5->GetStatInt(this: v5, a2: 32);
          v8 = v7;
          if ( args->argc == 2 )
          {
            v14 = atol(nptr: args->argv[1]);
            v15 = v14;
            if ( v14 > 0 )
            {
              num = v3->levelList.num;
              if ( v14 <= num )
              {
                XpRequiredForLevel = idDeclOnlineLevel::GetXpRequiredForLevel(
                                       this: v3,
                                       level: v14,
                                       a3: v13,
                                       a4: v12,
                                       a5: v11,
                                       a6: v10,
                                       a7: v9);
                v5->SetStatInt(this: v5, a2: 23, a3: XpRequiredForLevel);
                v5->SetStatInt(this: v5, a2: 32, a3: v15);
                if ( session != nullptr )
                  session->SendLocalSessionUsersToPeers(this: session);
                idLib::Printf(fmt: "Online level changed from %d to %d.\n", v8, v15);
                idLib::Printf(fmt: "Online xp changed from %d to %d.\n", v6, XpRequiredForLevel);
                if ( v5->GetProfile(this: v5) != nullptr )
                {
                  v18 = v5->GetProfile(this: v5);
                  idPlayerProfile::SaveSettings(this: v18);
                }
              }
              else
              {
                idLib::Printf(
                  fmt: "Level must be between 1-%d!\n Current Level is %d. usage: setOnlineLevel < level >\n",
                  num,
                  v8);
              }
            }
            else
            {
              idLib::Printf(
                fmt: "Level must be 1 or greater!\n Current Level is %d. usage: setOnlineLevel < level >\n",
                v8);
            }
          }
          else
          {
            idLib::Printf(fmt: "Current Level is %d, XP is %d. usage: setOnlineLevel < level >\n", v7, v6);
          }
        }
      }
      else
      {
        idLib::Printf(fmt: "Level decls not found, aborting!\n");
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineLevel is only available in multiplayer");
  }
}


// ========================================================================
// ?setOnlineCoopUnlockAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E55F60
// RVA : 0x00E55F60
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineCoopUnlockAll_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r3
  idLocalUser *v2; // r28
  int i; // r26
  idResource *v4; // r3
  idResource *v5; // r31
  int v6; // r29
  int v7; // r30
  int v8; // r4
  const char *str; // r24
  const char *LocalizedString; // r3
  idPlayerProfile *v11; // r3
  idStrId v12; // [sp+50h] [-50h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v1 = session->GetGameLobbyBase(this: session), v1->IsPeer(this: v1)) )
    {
      idLib::Warning(fmt: "Can't setOnlineCoopUnlockAll while you are a peer in a session");
    }
    else
    {
      v2 = common->GetMasterLocalUser(this: common);
      if ( v2 != nullptr )
      {
        for ( i = 0; i < idDeclCoopMap::resourceList.num; ++i )
        {
          v4 = idResourceList::Index(this: &idDeclCoopMap::resourceList, index: i);
          v5 = v4;
          if ( v4 != nullptr )
          {
            v6 = 0;
            if ( (int)v4[3].nextOnHashChain > 0 )
            {
              v7 = 0;
              do
              {
                v8 = *(_DWORD *)&v5[3].name.str[v7 + 64];
                if ( v8 != -1 )
                {
                  v2->SetStatInt(this: v2, a2: v8, a3: 1);
                  v12.index = *(_DWORD *)&v5[3].name.str[v7];
                  str = v5->name.str;
                  LocalizedString = idStrId::GetLocalizedString(this: &v12);
                  idLib::Printf(fmt: "Unlocking %s: %s\n", str, LocalizedString);
                }
                ++v6;
                v7 += 76;
              }
              while ( v6 < (int)v5[3].nextOnHashChain );
            }
          }
        }
        if ( v2->GetProfile(this: v2) != nullptr )
        {
          v11 = v2->GetProfile(this: v2);
          idPlayerProfile::SaveSettings(this: v11);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineCoopUnlockAll is only available in multiplayer");
  }
}


// ========================================================================
// ?setOnlineEmblemUnlockAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E56118
// RVA : 0x00E56118
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineEmblemUnlockAll_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r3
  idLocalUser *v2; // r29
  int i; // r26
  idResource *v4; // r3
  idResource *v5; // r30
  int v6; // r27
  int v7; // r31
  idResource_vtbl *v8; // r11
  bool IsInt; // r3
  idLocalUser_vtbl *v10; // r10
  int *v11; // r28
  int v12; // r4
  double v13; // fp1
  __int64 v14; // r7
  const int *v15; // r11
  idPlayerProfile *v16; // r3

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v1 = session->GetGameLobbyBase(this: session), v1->IsPeer(this: v1)) )
    {
      idLib::Warning(fmt: "Can't setOnlineEmblemUnlockAll while you are a peer in a session");
    }
    else
    {
      v2 = common->GetMasterLocalUser(this: common);
      if ( v2 != nullptr )
      {
        for ( i = 0; i < idDeclEmblem::resourceList.num; ++i )
        {
          v4 = idResourceList::Index(this: &idDeclEmblem::resourceList, index: i);
          v5 = v4;
          if ( v4 != nullptr )
          {
            v6 = 0;
            if ( v4[2].trackedMemory > 0 )
            {
              v7 = 0;
              do
              {
                v8 = v5[2].__vftable;
                if ( *(void (__fastcall **)(idResource *))((char *)&v8->dtr_idResource + v7) != (void (__fastcall *)(idResource *))-1 )
                {
                  IsInt = RageStatTypeIsInt(stat: *(rageStat_t *)((char *)&v8->dtr_idResource + v7));
                  v10 = v2->__vftable;
                  v11 = (int *)((char *)v5[2].__vftable + v7);
                  v12 = *v11;
                  if ( IsInt )
                  {
                    if ( v10->GetStatInt(this: v2, a2: v12) < v11[1] )
                      v2->SetStatInt(
                        this: v2,
                        a2: *(const int *)((char *)&v5[2].dtr_idResource + v7),
                        a3: *(const int *)((char *)&v5[2].LoadResource + v7));
                  }
                  else
                  {
                    v13 = ((double (__fastcall *)(idLocalUser *, int))v10->GetStatFloat)(a1: v2, a2: v12);
                    LODWORD(v14) = v11[1];
                    if ( v13 < (float)v14 )
                    {
                      v15 = (const int *)((char *)v5[2].__vftable + v7);
                      LODWORD(v14) = v15[1];
                      v2->SetStatFloat(this: v2, a2: *v15, a3: (float)v14);
                    }
                  }
                }
                ++v6;
                v7 += 8;
              }
              while ( v6 < v5[2].trackedMemory );
            }
            idLib::Printf(fmt: "Unlocking %s\n", v5->name.str);
          }
        }
        if ( v2->GetProfile(this: v2) != nullptr )
        {
          v16 = v2->GetProfile(this: v2);
          idPlayerProfile::SaveSettings(this: v16);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineEmblemUnlockAll is only available in multiplayer");
  }
}


// ========================================================================
// ?setOnlineCoopLockAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E56360
// RVA : 0x00E56360
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall setOnlineCoopLockAll_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r3
  idLocalUser *v2; // r28
  int i; // r26
  idResource *v4; // r3
  idResource *v5; // r31
  int v6; // r29
  int v7; // r30
  int v8; // r4
  const char *str; // r24
  const char *LocalizedString; // r3
  idPlayerProfile *v11; // r3
  idStrId v12; // [sp+50h] [-50h] BYREF

  if ( common->IsMultiplayer(this: common) )
  {
    if ( session != nullptr && (v1 = session->GetGameLobbyBase(this: session), v1->IsPeer(this: v1)) )
    {
      idLib::Warning(fmt: "Can't setOnlineCoopUnlockAll while you are a peer in a session");
    }
    else
    {
      v2 = common->GetMasterLocalUser(this: common);
      if ( v2 != nullptr )
      {
        for ( i = 0; i < idDeclCoopMap::resourceList.num; ++i )
        {
          v4 = idResourceList::Index(this: &idDeclCoopMap::resourceList, index: i);
          v5 = v4;
          if ( v4 != nullptr )
          {
            v6 = 0;
            if ( (int)v4[3].nextOnHashChain > 0 )
            {
              v7 = 0;
              do
              {
                v8 = *(_DWORD *)&v5[3].name.str[v7 + 64];
                if ( v8 != -1 )
                {
                  v2->SetStatInt(this: v2, a2: v8, a3: 0);
                  v12.index = *(_DWORD *)&v5[3].name.str[v7];
                  str = v5->name.str;
                  LocalizedString = idStrId::GetLocalizedString(this: &v12);
                  idLib::Printf(fmt: "Locked %s: %s\n", str, LocalizedString);
                }
                ++v6;
                v7 += 76;
              }
              while ( v6 < (int)v5[3].nextOnHashChain );
            }
          }
        }
        if ( v2->GetProfile(this: v2) != nullptr )
        {
          v11 = v2->GetProfile(this: v2);
          idPlayerProfile::SaveSettings(this: v11);
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "setOnlineCoopUnlockAll is only available in multiplayer");
  }
}


// ========================================================================
// ?suicide_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E56518
// RVA : 0x00E56518
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall suicide_f(const idCmdArgs *args)
{
  unsigned __int64 v1; // r30
  idClientGame *v2; // r3
  int v3; // r31
  idLobbyBase *v4; // r3
  _BYTE v5[16]; // [sp+50h] [-60h] BYREF
  idBitMsg v6[2]; // [sp+60h] [-50h] BYREF

  HIDWORD(v1) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  v2 = clientGame;
  if ( clientGame != nullptr )
  {
    LODWORD(v1) = 0;
    v3 = 0;
    while ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: v2, playerNum: v3) == 0 )
    {
      if ( ++v3 >= 6 )
        return;
      v2 = clientGame;
    }
    v6[0].curSize = 0;
    v6[0].writeBit = 0;
    v6[0].writeData = v5;
    v6[0].readData = v5;
    v6[0].maxSize = 2;
    v6[0].readCount = 0;
    v6[0].readBit = 0;
    v6[0].allowOverflow = false;
    v6[0].overflowed = false;
    v6[0].tempValue = v1;
    idBitMsg::WriteBits(this: v6, value: v3, numBits: 8);
    v4 = session->GetGameLobbyBase(this: session);
    v4->SendReliable(this: v4, a2: 8, a3: v6, a4: true, a5: 255u);
  }
}


// ========================================================================
// ?VehDamage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E565F0
// RVA : 0x00E565F0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall VehDamage_f(const idCmdArgs *args)
{
  int v2; // r27
  double v3; // fp30
  const char *v4; // r3
  __int64 v5; // r11
  const char *v6; // r3
  const idDecl *v7; // r28
  signed int i; // r30
  idPlayer *Player; // r3
  idPlayer *v10; // r31
  int v11; // r3
  idEntity *v12; // r3
  idPhysics *Physics; // r3
  int v14; // r3

  v2 = -1;
  v3 = 10.0;
  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    LODWORD(v5) = atol(nptr: v4);
    v3 = (float)v5;
  }
  if ( args->argc >= 3 )
  {
    if ( args->argc <= 2 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[2];
    v2 = atol(nptr: v6);
  }
  v7 = idDeclInfo::FindWithInheritance(
         this: &idDeclDamage::resourceList,
         name: "damage/code_referenced/damage1",
         makeDefault: false);
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    v10 = Player;
    if ( Player != nullptr && (v2 < 0 || v2 == i) && Player->GetVehicle_2(this: Player) != nullptr )
    {
      v11 = (int)v10->GetVehicle_2(this: v10);
      if ( ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v11 + 704))(a1: v11) > 0.0 )
      {
        v12 = v10->GetVehicle_2(this: v10);
        Physics = idEntity::GetPhysics(this: v12);
        Physics->GetAxis(this: Physics, a2: 0);
        v14 = (int)v10->GetVehicle_2(this: v10);
        (*(void (__fastcall **)(int, idPlayer *, idPlayer *, const idDecl *, double))(*(_DWORD *)v14 + 312))(
          a1: v14,
          a2: v10,
          a3: v10,
          a4: v7,
          a5: v3);
      }
    }
  }
}


// ========================================================================
// ?changeTeam_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E567B8
// RVA : 0x00E567B8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall changeTeam_f(const idCmdArgs *args)
{
  int v1; // r3
  int v2; // r28
  idClientGame *v3; // r3
  int v4; // r31 OVERLAPPED
  int v5; // r30 OVERLAPPED
  idLobbyBase *v6; // r3
  _BYTE v7[16]; // [sp+50h] [-60h] BYREF
  idBitMsg v8[2]; // [sp+60h] [-50h] BYREF

  if ( args->argc == 2 )
  {
    v1 = atol(nptr: args->argv[1]);
    v2 = v1;
    if ( v1 < 1 || v1 > 2 )
    {
      idLib::Printf(fmt: "Incorrect Team Num. Please choose 1 for RED, 2 for BLUE\n");
    }
    else
    {
      v3 = clientGame;
      if ( clientGame != nullptr )
      {
        v4 = 0;
        v5 = 0;
        while ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: v3, playerNum: v5) == 0 )
        {
          if ( ++v5 >= 6 )
            return;
          v3 = clientGame;
        }
        v8[0].curSize = 0;
        v8[0].writeBit = 0;
        v8[0].writeData = v7;
        v8[0].readData = v7;
        v8[0].maxSize = 4;
        v8[0].readCount = 0;
        v8[0].readBit = 0;
        v8[0].allowOverflow = false;
        v8[0].overflowed = false;
        v8[0].tempValue = *(_QWORD *)&v4;
        idBitMsg::WriteBits(this: v8, value: v5, numBits: 8);
        idBitMsg::WriteBits(this: v8, value: v2, numBits: 8);
        v6 = session->GetGameLobbyBase(this: session);
        v6->SendReliable(this: v6, a2: 9, a3: v8, a4: true, a5: 255u);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: changeTeam <number> (RED = 1, BLUE = 2)\n");
  }
}


// ========================================================================
// ?GiveAll@idPlayer@@QAAXXZ
// EA  : 0x82E568F0
// RVA : 0x00E568F0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall idPlayer::GiveAll(idPlayer *this)
{
  idJobManager *v2; // r21
  int v3; // r28
  int v4; // r30
  int v5; // r26
  idDeclInfo *v6; // r3
  idDeclInfo *v7; // r29
  idDeclInfoTemplate<idDeclInventory> *parent; // r11
  int v9; // r27
  int v10; // r28
  int num; // r26
  const char *str; // r4
  idDecl *v13; // r3
  idDecl *v14; // r3
  idDecl *v15; // r31
  const char *v16; // r4
  const char **v17; // r11
  const char *v18; // r30
  int LineNum; // r14
  const char *FileName; // r3
  idJob *JobByDecl; // r30
  idPresentable *presentable; // r4
  int v23; // [sp+50h] [-B0h]
  int v24; // [sp+54h] [-ACh]
  int v25; // [sp+5Ch] [-A4h]

  if ( (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: this) != 0 )
  {
    this->playerHealth.Reset_Impl(this: &this->playerHealth);
    v2 = (idJobManager *)this->GetInventory_2(this);
    v3 = 0;
    v23 = 0;
    v4 = 0;
    v25 = declManager->GetNumDeclTypes(this: declManager);
    v5 = v25;
    v24 = 0;
    if ( v25 > 0 )
    {
      do
      {
        v6 = declManager->GetDeclType_2(this: declManager, a2: v4);
        v7 = v6;
        if ( v6 != nullptr )
        {
          parent = (idDeclInfoTemplate<idDeclInventory> *)v6;
          while ( parent != &idDeclInventory::resourceList )
          {
            parent = (idDeclInfoTemplate<idDeclInventory> *)parent->parent;
            if ( parent == nullptr )
              goto LABEL_7;
          }
          LOBYTE(parent) = 1;
LABEL_7:
          if ( (_BYTE)parent != 0 )
          {
            v9 = 0;
            if ( v6->declSources.num > 0 )
            {
              v10 = 0;
              num = v6->declSources.num;
              do
              {
                str = v7->declSources.list[v10]->name.str;
                if ( str != nullptr )
                  v13 = (idDecl *)idDeclInfo::FindWithInheritance(this: v7, name: str, makeDefault: false);
                else
                  v13 = nullptr;
                v14 = (idDecl *)_RTDynamicCast(
                                  inptr: v13,
                                  VfDelta: 0,
                                  SrcType: &idDecl `RTTI Type Descriptor',
                                  TargetType: &idDeclInventory `RTTI Type Descriptor',
                                  isReference: 0);
                v15 = v14;
                if ( v14 != nullptr )
                {
                  if ( HIBYTE(v14[4].staleCount) != 0 )
                  {
                    v18 = v14->name.str;
                    LineNum = idDecl::GetLineNum(this: v14);
                    FileName = idDecl::GetFileName(this: v15);
                    idLib::Printf(fmt: "%s is giveable, file: %s - %i\n", v18, FileName, LineNum);
                    JobByDecl = idJobManager::FindJobByDecl(this: v2, jobDecl: (const idDeclJob *)v15);
                    if ( (_RTDynamicCast(
                            inptr: v15,
                            VfDelta: 0,
                            SrcType: &idDeclInventory `RTTI Type Descriptor',
                            TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
                            isReference: 0) == nullptr
                       || JobByDecl == nullptr)
                      && (*(&v15[4].programaticallyDefined + 2) || JobByDecl == nullptr)
                      && idStr::Find(
                           searchIn: v15->name.str,
                           searchFor: "default",
                           casesensitive: false,
                           start: 0,
                           end: -1) == -1 )
                    {
                      presentable = this->presentable;
                      if ( presentable == nullptr )
                      {
                        idEntity::InitPresentableInternal(this);
                        presentable = this->presentable;
                      }
                      idInventoryCollection::GiveItem(
                        this: (idInventoryCollection *)v2,
                        owner: presentable,
                        decl: (const idDeclInventory *)v15,
                        count: 1,
                        forceCount: false,
                        canIntro: false);
                      ++v9;
                    }
                  }
                }
                else
                {
                  v16 = v7->declSources.list[v10]->name.str;
                  if ( v16 != nullptr )
                    v14 = (idDecl *)idDeclInfo::FindWithInheritance(this: v7, name: v16, makeDefault: false);
                  v17 = (const char **)_RTDynamicCast(
                                         inptr: v14,
                                         VfDelta: 0,
                                         SrcType: &idDecl `RTTI Type Descriptor',
                                         TargetType: &idDeclTypeInfo `RTTI Type Descriptor',
                                         isReference: 0);
                  if ( v17 != nullptr )
                    idLib::Warning(
                      fmt: "In Give All casting to idDeclInventory Failed.  %s probably is set up as having inventory as paren"
                      "t even though it isn't a subclass of idDeclInventory",
                      v17[2]);
                  else
                    idLib::Warning(fmt: "In Give All casting to idDeclInventory Failed.  Casting to idDeclTypeInfo also failed.");
                }
                --num;
                ++v10;
              }
              while ( num != 0 );
              v3 = v23;
              v5 = v25;
              v4 = v24;
            }
            idLib::Printf(fmt: "Gave %d %s items.\n", v9, v7->classname);
            v3 += v9;
            v23 = v3;
          }
        }
        v24 = ++v4;
      }
      while ( v4 < v5 );
    }
    idLib::Printf(fmt: "Gave %d total items.\n", v3);
  }
}


// ========================================================================
// ?ExportPlayerInventoryCosts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E56C20
// RVA : 0x00E56C20
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ExportPlayerInventoryCosts_f(const idCmdArgs *args)
{
  idFile *v2; // r3
  idFile *v3; // r25
  const char *v4; // r4
  int i; // r24
  idDeclInfo *v6; // r3
  idDeclInfo *v7; // r28
  idDeclInfoTemplate<idDeclInventory> *parent; // r11
  char v9; // r11
  int v10; // r26
  int v11; // r27
  const char *str; // r4
  const idDecl *v13; // r30
  idStrId *p_declSource; // r3
  const char *v15; // r19
  int v16; // r18
  idFile_vtbl *v17; // r29
  int staleCount; // r30
  const char *LocalizedString; // r3
  idStr v20[5]; // [sp+60h] [-A0h] BYREF

  if ( args->argc == 2 )
  {
    idStr::idStr(this: v20, text: args->argv[1]);
    idStr::SetFileExtension(this: v20, extension: "csv");
    v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v20[0].data, a3: 2);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v2->Printf(this: v2, a2: "displayName,decl,price,sell_price\n");
      for ( i = 0; i < declManager->GetNumDeclTypes(this: declManager); ++i )
      {
        v6 = declManager->GetDeclType_2(this: declManager, a2: i);
        v7 = v6;
        parent = (idDeclInfoTemplate<idDeclInventory> *)v6;
        if ( v6 != nullptr )
        {
          while ( parent != &idDeclInventory::resourceList )
          {
            parent = (idDeclInfoTemplate<idDeclInventory> *)parent->parent;
            if ( parent == nullptr )
              goto LABEL_12;
          }
          v9 = 1;
        }
        else
        {
LABEL_12:
          v9 = 0;
        }
        if ( v9 != 0 )
        {
          v10 = 0;
          if ( v6->declSources.num > 0 )
          {
            v11 = 0;
            do
            {
              str = v7->declSources.list[v11]->name.str;
              if ( str != nullptr )
                v13 = idDeclInfo::FindWithInheritance(this: v7, name: str, makeDefault: false);
              else
                v13 = nullptr;
              if ( idStr::Find(searchIn: v13->name.str, searchFor: "/ai/", casesensitive: false, start: 0, end: -1) == -1 )
              {
                p_declSource = (idStrId *)&v13[2].declSource;
                v15 = v13->name.str;
                v16 = *((_DWORD *)&v13[6].idResource + 8);
                v17 = v3->__vftable;
                staleCount = v13[6].staleCount;
                LocalizedString = idStrId::GetLocalizedString(this: p_declSource);
                v17->Printf(this: v3, a2: "%s,%s,%d,%d\n", LocalizedString, v15, staleCount, v16);
              }
              ++v10;
              ++v11;
            }
            while ( v10 < v7->declSources.num );
          }
        }
      }
      ((void (__fastcall *)(idFile *, int))v3->dtr_idFile)(a1: v3, a2: 1);
    }
    else
    {
      if ( args->argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idLib::Warning(fmt: "Could not create output file '%s'", v4);
    }
    idStr::FreeData(this: v20);
  }
  else
  {
    idLib::Printf(fmt: "usage: ExportPlayerInventoryCosts <csv file name>\n");
  }
}


// ========================================================================
// __unwind$497991
// EA  : 0x82E56E80
// RVA : 0x00E56E80
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_497991()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?ImportPlayerInventoryCosts_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E56EB0
// RVA : 0x00E56EB0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ImportPlayerInventoryCosts_f(const idCmdArgs *args)
{
  bool v2; // cr57
  const char *v3; // r4
  const char *v4; // r4
  int v5; // r22
  char v6; // r27
  idDecl *v7; // r29
  int v8; // r30
  idDeclInfoTemplate<idDeclInventory> *parent; // r3
  char v10; // r11
  const idDecl *v11; // r3
  int v12; // r3
  int v13; // r3
  idToken v14; // [sp+50h] [-150h] BYREF
  idStr v15; // [sp+A0h] [-100h] BYREF
  idLexer v16; // [sp+C0h] [-E0h] BYREF

  if ( args->argc == 2 )
  {
    idLexer::idLexer(this: &v16, flags_: 0);
    v2 = args->argc > 1;
    v16.flags = 524800;
    if ( v2 )
      v3 = args->argv[1];
    else
      v3 = &byte_8200D768;
    idStr::idStr(this: &v15, text: v3);
    idStr::SetFileExtension(this: &v15, extension: "csv");
    if ( idLexer::LoadFile(this: &v16, filename_: v15.data, OSPath: false) )
    {
      idLexer::SkipRestOfLine(this: &v16);
      v14.len = 0;
      v14.baseBuffer[0] = 0;
      v14.intvalue = 0;
      v14.floatvalue = -3.4028235e38;
      memset(&v14.whiteSpaceStart_p, 0, 12);
      v14.allocedAndFlag = 20;
      v14.data = v14.baseBuffer;
      v5 = 0;
      idLexer::SkipUntilString(this: &v16, string: ",");
      while ( !idLexer::EndOfFile(this: &v16) )
      {
        v6 = 0;
        idLexer::ReadToken(this: &v16, token: &v14);
        v7 = nullptr;
        v8 = 0;
        if ( declManager->GetNumDeclTypes(this: declManager) <= 0 )
        {
LABEL_25:
          idLib::Warning(fmt: "Failed to find decl '%s'", v14.data);
          idLexer::SkipRestOfLine(this: &v16);
        }
        else
        {
          while ( 1 )
          {
            parent = (idDeclInfoTemplate<idDeclInventory> *)declManager->GetDeclType_2(this: declManager, a2: v8);
            if ( parent != nullptr )
            {
              while ( parent != &idDeclInventory::resourceList )
              {
                parent = (idDeclInfoTemplate<idDeclInventory> *)parent->parent;
                if ( parent == nullptr )
                  goto LABEL_16;
              }
              v10 = 1;
            }
            else
            {
LABEL_16:
              v10 = 0;
            }
            if ( v10 != 0 )
            {
              v11 = v14.data != nullptr
                  ? idDeclInfo::FindWithInheritance(
                      this: &idDeclInventory::resourceList,
                      name: v14.data,
                      makeDefault: false)
                  : nullptr;
              v7 = (idDecl *)v11;
              if ( v11 != nullptr )
                break;
            }
            if ( ++v8 >= declManager->GetNumDeclTypes(this: declManager) )
            {
              if ( v7 == nullptr )
                goto LABEL_25;
              break;
            }
          }
          idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 40, token: &v14);
          v12 = idLexer::ParseInt(this: &v16);
          if ( v12 != v7[6].staleCount )
          {
            v6 = 1;
            v7[6].staleCount = v12;
          }
          idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 40, token: &v14);
          v13 = idLexer::ParseInt(this: &v16);
          if ( v13 != *((_DWORD *)&v7[6].idResource + 8) )
          {
            v6 = 1;
            *((_DWORD *)&v7[6].idResource + 8) = v13;
          }
          if ( v6 != 0 )
          {
            ++v5;
            v7->RebuildTextSource(this: v7);
            idDecl::ReplaceSourceFileText(this: v7, useSourceControl: true);
          }
        }
        idLexer::SkipUntilString(this: &v16, string: ",");
      }
      idLib::Printf(fmt: "Modified %d inventory decls.\n", v5);
      idStr::FreeData(this: &v14);
      idStr::FreeData(this: &v15);
    }
    else
    {
      if ( args->argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idLib::Warning(fmt: "Failed to load file '%s'", v4);
      idStr::FreeData(this: &v15);
    }
    idLexer::~idLexer(this: &v16);
  }
  else
  {
    idLib::Printf(fmt: "usage: ImportPlayerInventoryCosts <csv file name>\n");
  }
}


// ========================================================================
// __unwind$498116
// EA  : 0x82E571C8
// RVA : 0x00E571C8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498116()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$498117
// EA  : 0x82E571F0
// RVA : 0x00E571F0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498117()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 160));
}


// ========================================================================
// __unwind$498118
// EA  : 0x82E57218
// RVA : 0x00E57218
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498118()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 80));
}


// ========================================================================
// ?ImportPlayerWeaponStats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E57248
// RVA : 0x00E57248
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ImportPlayerWeaponStats_f(const idCmdArgs *args)
{
  bool v2; // cr57
  const char *v3; // r4
  const char *v4; // r4
  int v5; // r24
  char v6; // r20
  char *data; // r4
  idDecl *v8; // r22
  int v9; // r3
  int v10; // r28
  const idDecl *v11; // r30
  float *v12; // r30
  char v13; // r29
  double v14; // fp1
  double v15; // fp1
  char v16; // r26
  idDecl *v17; // r27
  idDecl_vtbl *v18; // r11
  unsigned int (__fastcall *Size)(idDecl *); // r11
  const char *v20; // r4
  float *v21; // r30
  char v22; // r29
  double v23; // fp1
  double v24; // fp1
  void (__fastcall *LoadResource)(struct idDecl *); // r11
  const char *v26; // r4
  float *v27; // r30
  char v28; // r29
  double v29; // fp1
  double v30; // fp1
  int v31; // r3
  idToken v32; // [sp+50h] [-190h] BYREF
  idLexer v33; // [sp+A0h] [-140h] BYREF
  idStr v34[5]; // [sp+130h] [-B0h] BYREF

  if ( args->argc != 2 )
  {
    idLib::Printf(fmt: "usage: ImportPlayerWeaponStats <csv file name>\n");
    return;
  }
  idLexer::idLexer(this: &v33, flags_: 0);
  v2 = args->argc > 1;
  v33.flags = 524800;
  if ( v2 )
    v3 = args->argv[1];
  else
    v3 = &byte_8200D768;
  idStr::idStr(this: v34, text: v3);
  idStr::SetFileExtension(this: v34, extension: "csv");
  if ( !idLexer::LoadFile(this: &v33, filename_: v34[0].data, OSPath: false) )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    idLib::Warning(fmt: "Failed to load file '%s'", v4);
    idStr::FreeData(this: v34);
    goto LABEL_72;
  }
  idLexer::SkipRestOfLine(this: &v33);
  v32.len = 0;
  v32.baseBuffer[0] = 0;
  v32.intvalue = 0;
  v32.floatvalue = -3.4028235e38;
  memset(&v32.whiteSpaceStart_p, 0, 12);
  v32.allocedAndFlag = 20;
  v32.data = v32.baseBuffer;
  v5 = 0;
  idLexer::SkipUntilString(this: &v33, string: ",");
  while ( !idLexer::EndOfFile(this: &v33) )
  {
    v6 = 0;
    idLexer::ReadToken(this: &v33, token: &v32);
    data = v32.data;
    if ( v32.data != nullptr )
    {
      v8 = (idDecl *)idDeclInfo::FindWithInheritance(
                       this: &idDeclWeapon::resourceList,
                       name: v32.data,
                       makeDefault: false);
      if ( v8 != nullptr )
      {
        idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
        v9 = idLexer::ParseInt(this: &v33);
        if ( v9 != v8[6].staleCount )
        {
          v6 = 1;
          v8[6].staleCount = v9;
        }
        idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
        v10 = idLexer::ParseInt(this: &v33);
        idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
        idLexer::ReadToken(this: &v33, token: &v32);
        if ( v32.data != nullptr )
          v11 = idDeclInfo::FindWithInheritance(
                  this: &idDeclProjectile::resourceList,
                  name: v32.data,
                  makeDefault: false);
        else
          v11 = nullptr;
        idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
        if ( v11 != nullptr )
        {
          idLexer::ReadToken(this: &v33, token: &v32);
          if ( v32.data != nullptr )
            v12 = (float *)idDeclInfo::FindWithInheritance(
                             this: &idDeclDamage::resourceList,
                             name: v32.data,
                             makeDefault: false);
          else
            v12 = nullptr;
          idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
          if ( v12 != nullptr )
          {
            v13 = 0;
            v14 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
            if ( v14 != v12[32] )
            {
              v12[32] = v14;
              v13 = 1;
            }
            idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
            v15 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
            if ( v15 != v12[33] )
            {
              v12[33] = v15;
              v13 = 1;
            }
            if ( v13 != 0 )
            {
              ++v5;
              (*(void (__fastcall **)(float *))(*(_DWORD *)v12 + 36))(a1: v12);
              idDecl::ReplaceSourceFileText(this: (idDecl *)v12, useSourceControl: true);
            }
          }
          else
          {
            idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
            idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
            idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
          }
        }
        else
        {
          idLexer::ReadToken(this: &v33, token: &v32);
        }
        if ( v10 > 0 )
        {
          do
          {
            v16 = 0;
            idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
            idLexer::SkipUntilString(this: &v33, string: ",");
            idLexer::ReadToken(this: &v33, token: &v32);
            if ( v32.data != nullptr )
              v17 = (idDecl *)idDeclInfo::FindWithInheritance(
                                this: &idDeclAmmo::resourceList,
                                name: v32.data,
                                makeDefault: false);
            else
              v17 = nullptr;
            idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
            idLexer::SkipUntilString(this: &v33, string: ",");
            idLexer::SkipUntilString(this: &v33, string: ",");
            idLexer::SkipUntilString(this: &v33, string: ",");
            if ( v17 != nullptr && (v18 = v17[9].__vftable) != nullptr )
            {
              Size = v18[6].Size;
              if ( Size != nullptr )
              {
                v20 = *((const char **)Size + 2);
                if ( v20 != nullptr )
                  v21 = (float *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclDamage::resourceList,
                                   name: v20,
                                   makeDefault: false);
                else
                  v21 = nullptr;
                v22 = 0;
                v23 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                if ( v23 != v21[32] )
                {
                  v21[32] = v23;
                  v22 = 1;
                }
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                v24 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                if ( v24 != v21[33] )
                {
                  v21[33] = v24;
                  v22 = 1;
                }
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                if ( v22 != 0 )
                {
                  ++v5;
                  (*(void (__fastcall **)(float *))(*(_DWORD *)v21 + 36))(a1: v21);
                  idDecl::ReplaceSourceFileText(this: (idDecl *)v21, useSourceControl: true);
                }
              }
              else
              {
                idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              }
              LoadResource = v17[9].__vftable[7].LoadResource;
              if ( LoadResource != nullptr )
              {
                v26 = *((const char **)LoadResource + 2);
                if ( v26 != nullptr )
                  v27 = (float *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclDamage::resourceList,
                                   name: v26,
                                   makeDefault: false);
                else
                  v27 = nullptr;
                v28 = 0;
                v29 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                if ( v29 != v27[32] )
                {
                  v27[32] = v29;
                  v28 = 1;
                }
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                v30 = idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                if ( v30 != v27[33] )
                {
                  v27[33] = v30;
                  v28 = 1;
                }
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                if ( v28 != 0 )
                {
                  ++v5;
                  (*(void (__fastcall **)(float *))(*(_DWORD *)v27 + 36))(a1: v27);
                  idDecl::ReplaceSourceFileText(this: (idDecl *)v27, useSourceControl: true);
                }
              }
              else
              {
                idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
                idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
                idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              }
              idLexer::ParseInt(this: &v33);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseInt(this: &v33);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              v31 = idLexer::ParseInt(this: &v33);
              if ( v31 != v17[6].staleCount )
              {
                v16 = 1;
                v17[6].staleCount = v31;
              }
              if ( v16 != 0 )
              {
                ++v5;
                v17->RebuildTextSource(this: v17);
                idDecl::ReplaceSourceFileText(this: v17, useSourceControl: true);
              }
            }
            else
            {
              idLib::Warning(fmt: "Failed to find decl '%s'", v32.data);
              idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseFloat(this: &v33, errorFlag: nullptr);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseInt(this: &v33);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseInt(this: &v33);
              idLexer::ExpectTokenType(this: &v33, type: 5, subtype: 40, token: &v32);
              idLexer::ParseInt(this: &v33);
            }
            --v10;
          }
          while ( v10 != 0 );
        }
        if ( v6 != 0 )
        {
          ++v5;
          v8->RebuildTextSource(this: v8);
          idDecl::ReplaceSourceFileText(this: v8, useSourceControl: true);
        }
        goto LABEL_70;
      }
      data = v32.data;
    }
    idLib::Warning(fmt: "Failed to find decl '%s'", data);
LABEL_70:
    idLexer::SkipRestOfLine(this: &v33);
    idLexer::SkipUntilString(this: &v33, string: ",");
  }
  idLib::Printf(fmt: "Modified %d weapon-related decls.\n", v5);
  idStr::FreeData(this: &v32);
  idStr::FreeData(this: v34);
LABEL_72:
  idLexer::~idLexer(this: &v33);
}


// ========================================================================
// __unwind$498271
// EA  : 0x82E57A50
// RVA : 0x00E57A50
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498271()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$498272
// EA  : 0x82E57A78
// RVA : 0x00E57A78
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498272()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 304));
}


// ========================================================================
// __unwind$498273
// EA  : 0x82E57AA0
// RVA : 0x00E57AA0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498273()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// ?ImportPlayerRecipes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E57AD0
// RVA : 0x00E57AD0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ImportPlayerRecipes_f(const idCmdArgs *args)
{
  bool v2; // cr57
  const char *v3; // r4
  const char *v4; // r4
  int v5; // r19
  char *data; // r4
  char v7; // r26
  idDecl *v8; // r27
  int v9; // r25
  int v10; // r29
  int v11; // r28
  int v12; // r30
  int v13; // r3
  int v14; // r11
  idToken v15; // [sp+50h] [-170h] BYREF
  idLexer v16; // [sp+A0h] [-120h] BYREF
  idStr v17[4]; // [sp+130h] [-90h] BYREF

  if ( args->argc != 2 )
  {
    idLib::Printf(fmt: "usage: ImportPlayerRecipes <csv file name>\n");
    return;
  }
  idLexer::idLexer(this: &v16, flags_: 0);
  v2 = args->argc > 1;
  v16.flags = 524800;
  if ( v2 )
    v3 = args->argv[1];
  else
    v3 = &byte_8200D768;
  idStr::idStr(this: v17, text: v3);
  idStr::SetFileExtension(this: v17, extension: "csv");
  if ( !idLexer::LoadFile(this: &v16, filename_: v17[0].data, OSPath: false) )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    idLib::Warning(fmt: "Failed to load file '%s'", v4);
    idStr::FreeData(this: v17);
    goto LABEL_31;
  }
  idLexer::SkipRestOfLine(this: &v16);
  v15.len = 0;
  v15.baseBuffer[0] = 0;
  v15.intvalue = 0;
  v15.floatvalue = -3.4028235e38;
  memset(&v15.whiteSpaceStart_p, 0, 12);
  v15.allocedAndFlag = 20;
  v15.data = v15.baseBuffer;
  v5 = 0;
  idLexer::ReadToken(this: &v16, token: &v15);
  while ( !idLexer::EndOfFile(this: &v16) )
  {
    data = v15.data;
    v7 = 0;
    if ( v15.data != nullptr )
    {
      v8 = (idDecl *)idDeclInfo::FindWithInheritance(
                       this: &idDeclRecipe::resourceList,
                       name: v15.data,
                       makeDefault: false);
      if ( v8 != nullptr )
      {
        idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 40, token: &v15);
        idLexer::SkipUntilString(this: &v16, string: ",");
        idLexer::SkipUntilString(this: &v16, string: ",");
        v9 = idLexer::ParseInt(this: &v16);
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = 0;
          do
          {
            idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 40, token: &v15);
            if ( v10 < 0 || v10 > (int)v8[1].textSource )
              v12 = 0;
            else
              v12 = *((_DWORD *)&v8[1].idResource + 8) + v11;
            idLexer::SkipUntilString(this: &v16, string: ",");
            idLexer::SkipUntilString(this: &v16, string: ",");
            v13 = idLexer::ParseInt(this: &v16);
            if ( v13 != *(_DWORD *)(v12 + 4) )
            {
              v7 = 1;
              *(_DWORD *)(v12 + 4) = v13;
            }
            idLexer::ExpectTokenType(this: &v16, type: 5, subtype: 40, token: &v15);
            idLexer::ReadToken(this: &v16, token: &v15);
            v14 = (_cntlzw(idStr::Icmp(s1: v15.data, s2: "true")) & 0x20) != 0;
            if ( v14 != *(unsigned __int8 *)(v12 + 8) )
            {
              v7 = 1;
              *(_BYTE *)(v12 + 8) = v14;
            }
            ++v10;
            v11 += 12;
          }
          while ( v10 < v9 );
        }
        if ( v7 != 0 )
        {
          ++v5;
          v8->RebuildTextSource(this: v8);
          idDecl::ReplaceSourceFileText(this: v8, useSourceControl: true);
        }
        goto LABEL_29;
      }
      data = v15.data;
    }
    idLib::Warning(fmt: "Failed to find decl '%s'", data);
LABEL_29:
    idLexer::SkipRestOfLine(this: &v16);
    idLexer::ReadToken(this: &v16, token: &v15);
  }
  idLib::Printf(fmt: "Modified %d recipe decls.\n", v5);
  idStr::FreeData(this: &v15);
  idStr::FreeData(this: v17);
LABEL_31:
  idLexer::~idLexer(this: &v16);
}


// ========================================================================
// __unwind$498586
// EA  : 0x82E57DEC
// RVA : 0x00E57DEC
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498586()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 448 + 160));
}


// ========================================================================
// __unwind$498587
// EA  : 0x82E57E14
// RVA : 0x00E57E14
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498587()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 304));
}


// ========================================================================
// __unwind$498588
// EA  : 0x82E57E3C
// RVA : 0x00E57E3C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498588()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 80));
}


// ========================================================================
// ?ImportPlayerAmmo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E57E70
// RVA : 0x00E57E70
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ImportPlayerAmmo_f(const idCmdArgs *args)
{
  bool v2; // cr57
  const char *v3; // r4
  const char *v4; // r4
  char v5; // r25
  char *data; // r4
  idDecl *v7; // r26
  int v8; // r3
  int v9; // r3
  char v10; // r27
  char *v11; // r4
  idDecl *v12; // r28
  int v13; // r3
  double v14; // fp1
  double v15; // fp1
  int v16; // r3
  char v17; // r29
  char *v18; // r4
  float *v19; // r30
  double v20; // fp1
  double v21; // fp1
  char v22; // r29
  char *v23; // r4
  float *v24; // r30
  double v25; // fp1
  double v26; // fp1
  double v27; // fp1
  char v28; // r29
  char *v29; // r4
  float *v30; // r30
  double v31; // fp1
  double v32; // fp1
  double v33; // fp1
  idToken v34; // [sp+50h] [-190h] BYREF
  idLexer v35; // [sp+A0h] [-140h] BYREF
  idStr v36[5]; // [sp+130h] [-B0h] BYREF

  if ( args->argc != 2 )
  {
    idLib::Printf(fmt: "usage: ImportPlayerRecipes <csv file name>\n");
    return;
  }
  idLexer::idLexer(this: &v35, flags_: 0);
  v2 = args->argc > 1;
  v35.flags = 524800;
  if ( v2 )
    v3 = args->argv[1];
  else
    v3 = &byte_8200D768;
  idStr::idStr(this: v36, text: v3);
  idStr::SetFileExtension(this: v36, extension: "csv");
  if ( !idLexer::LoadFile(this: &v35, filename_: v36[0].data, OSPath: false) )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    idLib::Warning(fmt: "Failed to load file '%s'", v4);
    idStr::FreeData(this: v36);
    goto LABEL_80;
  }
  idLexer::SkipRestOfLine(this: &v35);
  v34.len = 0;
  v34.allocedAndFlag = 20;
  v34.data = v34.baseBuffer;
  v34.floatvalue = -3.4028235e38;
  v34.baseBuffer[0] = 0;
  v34.intvalue = 0;
  memset(&v34.whiteSpaceStart_p, 0, 12);
  idLexer::SkipUntilString(this: &v35, string: ",");
  if ( !idLexer::EndOfFile(this: &v35) )
  {
    while ( 1 )
    {
      v5 = 0;
      idLexer::ReadToken(this: &v35, token: &v34);
      data = v34.data;
      if ( v34.data == nullptr )
        goto LABEL_15;
      v7 = (idDecl *)idDeclInfo::FindWithInheritance(
                       this: &idDeclAmmo::resourceList,
                       name: v34.data,
                       makeDefault: false);
      if ( v7 == nullptr )
        break;
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v8 = idLexer::ParseInt(this: &v35);
      if ( (idDecl_vtbl *)v8 != v7[6].__vftable )
      {
        v5 = 1;
        v7[6].__vftable = (idDecl_vtbl *)v8;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v9 = idLexer::ParseInt(this: &v35);
      if ( v9 != v7[6].staleCount )
      {
        v5 = 1;
        v7[6].staleCount = v9;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      if ( v7[9].__vftable == nullptr )
        goto LABEL_75;
      v10 = 0;
      idLexer::ReadToken(this: &v35, token: &v34);
      v11 = v34.data;
      if ( v34.data == nullptr )
        goto LABEL_24;
      v12 = (idDecl *)idDeclInfo::FindWithInheritance(
                        this: &idDeclProjectile::resourceList,
                        name: v34.data,
                        makeDefault: false);
      if ( v12 == nullptr )
      {
        v11 = v34.data;
LABEL_24:
        idLib::Warning(fmt: "Failed to find projectileDecl '%s'", v11);
        idLexer::SkipRestOfLine(this: &v35);
        idLexer::ReadToken(this: &v35, token: &v34);
        goto LABEL_78;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v13 = idLexer::ParseInt(this: &v35);
      if ( (char *)v13 != v12[8].textSource )
      {
        v10 = 1;
        v12[8].textSource = (char *)v13;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v14 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
      if ( v14 != *(float *)&v12[8].textLength )
      {
        *(float *)&v12[8].textLength = v14;
        v10 = 1;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v15 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
      if ( v15 != *(float *)&v12[8].md5Checksum )
      {
        *(float *)&v12[8].md5Checksum = v15;
        v10 = 1;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      v16 = idLexer::ParseInt(this: &v35);
      if ( v16 != *(_DWORD *)&v12[8].programaticallyDefined )
      {
        v10 = 1;
        *(_DWORD *)&v12[8].programaticallyDefined = v16;
      }
      idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      if ( v12[7].declSource != nullptr )
      {
        v17 = 0;
        idLexer::ReadToken(this: &v35, token: &v34);
        v18 = v34.data;
        if ( v34.data == nullptr )
          goto LABEL_37;
        v19 = (float *)idDeclInfo::FindWithInheritance(
                         this: &idDeclDamage::resourceList,
                         name: v34.data,
                         makeDefault: false);
        if ( v19 == nullptr )
        {
          v18 = v34.data;
LABEL_37:
          idLib::Warning(fmt: "Failed to find damageDecl '%s'", v18);
          idLexer::SkipRestOfLine(this: &v35);
          idLexer::ReadToken(this: &v35, token: &v34);
          goto LABEL_78;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v20 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        if ( v20 != v19[32] )
        {
          v19[32] = v20;
          v17 = 1;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v21 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        if ( v21 != v19[33] )
        {
          v19[33] = v21;
          v17 = 1;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        if ( v17 != 0 )
        {
          (*(void (__fastcall **)(float *))(*(_DWORD *)v19 + 36))(a1: v19);
          idDecl::ReplaceSourceFileText(this: (idDecl *)v19, useSourceControl: true);
        }
      }
      else
      {
        idLexer::ReadToken(this: &v35, token: &v34);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      }
      if ( v12[8].trackedMemory != 0 )
      {
        v22 = 0;
        idLexer::ReadToken(this: &v35, token: &v34);
        v23 = v34.data;
        if ( v34.data == nullptr )
          goto LABEL_49;
        v24 = (float *)idDeclInfo::FindWithInheritance(
                         this: &idDeclDamage::resourceList,
                         name: v34.data,
                         makeDefault: false);
        if ( v24 == nullptr )
        {
          v23 = v34.data;
LABEL_49:
          idLib::Warning(fmt: "Failed to find splashDamageDecl '%s'", v23);
          idLexer::SkipRestOfLine(this: &v35);
          idLexer::ReadToken(this: &v35, token: &v34);
          goto LABEL_78;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v25 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        if ( v25 != v24[32] )
        {
          v24[32] = v25;
          v22 = 1;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v26 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        if ( v26 != v24[33] )
        {
          v24[33] = v26;
          v22 = 1;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v27 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        if ( v27 != v24[50] )
        {
          v24[50] = v27;
          v22 = 1;
        }
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        if ( v22 != 0 )
        {
          (*(void (__fastcall **)(float *))(*(_DWORD *)v24 + 36))(a1: v24);
          idDecl::ReplaceSourceFileText(this: (idDecl *)v24, useSourceControl: true);
        }
      }
      else
      {
        idLexer::ReadToken(this: &v35, token: &v34);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
      }
      if ( v12[8].name.str == nullptr )
      {
        idLexer::ReadToken(this: &v35, token: &v34);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
        idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
        v33 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
LABEL_73:
        if ( v10 != 0 )
        {
          ((void (__fastcall *)(idDecl *, double))v12->RebuildTextSource)(a1: v12, a2: v33);
          idDecl::ReplaceSourceFileText(this: v12, useSourceControl: true);
        }
LABEL_75:
        if ( v5 != 0 )
        {
          v7->RebuildTextSource(this: v7);
          idDecl::ReplaceSourceFileText(this: v7, useSourceControl: true);
        }
        idLexer::SkipRestOfLine(this: &v35);
        idLexer::SkipUntilString(this: &v35, string: ",");
        goto LABEL_78;
      }
      v28 = 0;
      idLexer::ReadToken(this: &v35, token: &v34);
      v29 = v34.data;
      if ( v34.data != nullptr )
      {
        v30 = (float *)idDeclInfo::FindWithInheritance(
                         this: &idDeclDamage::resourceList,
                         name: v34.data,
                         makeDefault: false);
        if ( v30 != nullptr )
        {
          idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
          v31 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
          if ( v31 != v30[32] )
          {
            v30[32] = v31;
            v28 = 1;
          }
          idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
          v32 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
          if ( v32 != v30[33] )
          {
            v30[33] = v32;
            v28 = 1;
          }
          idLexer::ExpectTokenType(this: &v35, type: 5, subtype: 40, token: &v34);
          v33 = idLexer::ParseFloat(this: &v35, errorFlag: nullptr);
          if ( v33 != v30[50] )
          {
            v30[50] = v33;
            v28 = 1;
          }
          if ( v28 != 0 )
          {
            (*(void (__fastcall **)(float *))(*(_DWORD *)v30 + 36))(a1: v30);
            idDecl::ReplaceSourceFileText(this: (idDecl *)v30, useSourceControl: true);
          }
          goto LABEL_73;
        }
        v29 = v34.data;
      }
      idLib::Warning(fmt: "Failed to find electricDamageDecl '%s'", v29);
      idLexer::SkipRestOfLine(this: &v35);
      idLexer::ReadToken(this: &v35, token: &v34);
LABEL_78:
      if ( idLexer::EndOfFile(this: &v35) )
        goto LABEL_79;
    }
    data = v34.data;
LABEL_15:
    idLib::Warning(fmt: "Failed to find decl '%s'", data);
    idLexer::SkipRestOfLine(this: &v35);
    idLexer::ReadToken(this: &v35, token: &v34);
    goto LABEL_78;
  }
LABEL_79:
  idStr::FreeData(this: &v34);
  idStr::FreeData(this: v36);
LABEL_80:
  idLexer::~idLexer(this: &v35);
}


// ========================================================================
// __unwind$498748_0
// EA  : 0x82E58748
// RVA : 0x00E58748
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498748_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$498749_0
// EA  : 0x82E58770
// RVA : 0x00E58770
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498749_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 304));
}


// ========================================================================
// __unwind$498750_0
// EA  : 0x82E58798
// RVA : 0x00E58798
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_498750_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 80));
}


// ========================================================================
// ?GiveRecipes@idPlayer@@QAAXH@Z
// EA  : 0x82E58880
// RVA : 0x00E58880
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall idPlayer::GiveRecipes(idPlayer *this, int recCount)
{
  idInventoryCollection *v4; // r27
  int v5; // r22
  int v6; // r26
  int num; // r20
  int v8; // r21
  const char *str; // r4
  const idDecl *v10; // r3
  const idDecl *v11; // r28
  int textLength; // r11
  int v13; // r30
  int v14; // r29
  int v15; // r31
  idPresentable *v16; // r4
  idPresentable *presentable; // r4
  idJob *JobByDecl; // r3
  idPresentable *v19; // r4

  v4 = this->GetInventory_2(this);
  v5 = 0;
  v6 = 0;
  if ( idDeclInventory::resourceList.declSources.num > 0 )
  {
    num = idDeclInventory::resourceList.declSources.num;
    v8 = 0;
    do
    {
      str = idDeclInventory::resourceList.declSources.list[v8]->name.str;
      if ( str != nullptr )
      {
        v10 = idDeclInfo::FindWithInheritance(this: &idDeclInventory::resourceList, name: str, makeDefault: false);
        v11 = v10;
        if ( v10 != nullptr )
        {
          textLength = v10[6].textLength;
          if ( textLength != 0 )
          {
            if ( HIBYTE(v10[4].staleCount) != 0 )
            {
              v13 = 0;
              if ( *(int *)(textLength + 92) > 0 )
              {
                v14 = 0;
                do
                {
                  if ( v13 >= 0 && v13 <= *(_DWORD *)(textLength + 92) )
                  {
                    v15 = *(_DWORD *)(textLength + 88) + v14;
                    if ( v15 != 0 && *(_DWORD *)v15 != 0 )
                    {
                      if ( *(_BYTE *)(*(_DWORD *)v15 + 274) != 0 )
                      {
                        presentable = this->presentable;
                        if ( presentable == nullptr )
                        {
                          idEntity::InitPresentableInternal(this);
                          presentable = this->presentable;
                        }
                        idInventoryCollection::GiveItem(
                          this: v4,
                          owner: presentable,
                          decl: *(const idDeclInventory **)v15,
                          count: *(_DWORD *)(v15 + 4) * recCount,
                          forceCount: false,
                          canIntro: false);
                        v6 += *(_DWORD *)(v15 + 4) * recCount;
                      }
                      else if ( idJobManager::FindJobByDecl(this: (idJobManager *)v4, jobDecl: (const idDeclJob *)v11) == nullptr )
                      {
                        v16 = this->presentable;
                        if ( v16 == nullptr )
                        {
                          idEntity::InitPresentableInternal(this);
                          v16 = this->presentable;
                        }
                        idInventoryCollection::GiveItem(
                          this: v4,
                          owner: v16,
                          decl: *(const idDeclInventory **)v15,
                          count: 1,
                          forceCount: false,
                          canIntro: false);
                        ++v6;
                      }
                    }
                  }
                  textLength = v11[6].textLength;
                  ++v13;
                  v14 += 12;
                }
                while ( v13 < *(_DWORD *)(textLength + 92) );
              }
              JobByDecl = idJobManager::FindJobByDecl(this: (idJobManager *)v4, jobDecl: (const idDeclJob *)v11);
              if ( *(&v11[4].programaticallyDefined + 2) )
                goto LABEL_26;
              if ( JobByDecl == nullptr )
              {
                if ( *(&v11[4].programaticallyDefined + 2) )
LABEL_26:
                  idLib::Warning(fmt: "%s recipe marked as stackable", v11->name.str);
                v19 = this->presentable;
                if ( v19 == nullptr )
                {
                  idEntity::InitPresentableInternal(this);
                  v19 = this->presentable;
                }
                idInventoryCollection::GiveItem(
                  this: v4,
                  owner: v19,
                  decl: (const idDeclInventory *)v11,
                  count: 1,
                  forceCount: false,
                  canIntro: false);
                ++v5;
              }
            }
            else
            {
              idLib::Warning(fmt: "%s recipe not marked as giveable", v10->name.str);
            }
          }
        }
      }
      --num;
      ++v8;
    }
    while ( num != 0 );
  }
  idLib::Printf(fmt: "Gave %d recipes. and %d ingredients\n", v5, v6);
}


// ========================================================================
// ?ExportPlayerWeaponStats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E58AC0
// RVA : 0x00E58AC0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ExportPlayerWeaponStats_f(const idCmdArgs *args)
{
  idFile *v2; // r15
  const char *v3; // r4
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  va *v7; // r3
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  int i; // r30
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  int v17; // r18
  int v18; // r20
  const char *str; // r4
  idDeclWeapon *v20; // r27
  unsigned int v21; // r30
  int v22; // r9
  int v23; // r11
  const idDeclAmmo *validAmmoDecl; // r10
  const char *v25; // r28
  int price; // r26
  const char *LocalizedString; // r3
  __int64 v28; // r10
  va *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  const idDeclProjectile *pistolWhipProjectile; // r11
  __int128 v34; // r7 OVERLAPPED
  int v35; // r8
  va *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r6
  int v40; // r25
  int v41; // r26
  const idDeclAmmo *v42; // r30
  int v43; // r11
  char *v44; // r28
  int v45; // r11
  char *v46; // r29
  const idDeclProjectile *projectileDecl; // r11
  const char *v48; // r15
  const idDeclDamage *damageDecl; // r10
  const char *v50; // r14
  double maxDamage; // fp30
  double minDamage; // fp29
  const char *v53; // r3
  va *v54; // r3
  __int64 v55; // r10
  __int64 v56; // r8
  va *v57; // r3
  int v58; // r29
  int ClipSize; // r28
  int v60; // r3
  __int64 v61; // r8
  __int64 v62; // r10
  va *v63; // r3
  va *v64; // r3
  int v65; // [sp+8h] [-2188h]
  int v66; // [sp+8h] [-2188h]
  int v67; // [sp+8h] [-2188h]
  int v68; // [sp+8h] [-2188h]
  int v69; // [sp+8h] [-2188h]
  int v70; // [sp+8h] [-2188h]
  int v71; // [sp+8h] [-2188h]
  int v72; // [sp+Ch] [-2184h]
  int v73; // [sp+Ch] [-2184h]
  int v74; // [sp+Ch] [-2184h]
  int v75; // [sp+Ch] [-2184h]
  int v76; // [sp+Ch] [-2184h]
  int v77; // [sp+Ch] [-2184h]
  int v78; // [sp+Ch] [-2184h]
  int v79; // [sp+10h] [-2180h]
  int v80; // [sp+10h] [-2180h]
  int v81; // [sp+10h] [-2180h]
  int v82; // [sp+10h] [-2180h]
  int v83; // [sp+10h] [-2180h]
  int v84; // [sp+10h] [-2180h]
  int v85; // [sp+10h] [-2180h]
  int v86; // [sp+14h] [-217Ch]
  int v87; // [sp+14h] [-217Ch]
  int v88; // [sp+14h] [-217Ch]
  int v89; // [sp+14h] [-217Ch]
  int v90; // [sp+14h] [-217Ch]
  int v91; // [sp+14h] [-217Ch]
  int v92; // [sp+14h] [-217Ch]
  int v93; // [sp+18h] [-2178h]
  int v94; // [sp+18h] [-2178h]
  int v95; // [sp+18h] [-2178h]
  int v96; // [sp+18h] [-2178h]
  int v97; // [sp+18h] [-2178h]
  int v98; // [sp+18h] [-2178h]
  int v99; // [sp+18h] [-2178h]
  int v100; // [sp+1Ch] [-2174h]
  int v101; // [sp+1Ch] [-2174h]
  int v102; // [sp+1Ch] [-2174h]
  int v103; // [sp+1Ch] [-2174h]
  int v104; // [sp+1Ch] [-2174h]
  int v105; // [sp+1Ch] [-2174h]
  int v106; // [sp+1Ch] [-2174h]
  double v107; // [sp+38h] [-2158h]
  int num; // [sp+64h] [-212Ch]
  idFile *v109; // [sp+6Ch] [-2124h]
  idStr v110; // [sp+80h] [-2110h] BYREF
  idStr v111; // [sp+A0h] [-20F0h] BYREF
  idStr v112; // [sp+C0h] [-20D0h] BYREF
  va v113; // [sp+E0h] [-20B0h] BYREF
  va v114; // [sp+10E0h] [-10B0h] BYREF

  if ( args->argc == 2 )
  {
    idStr::idStr(this: &v112, text: args->argv[1]);
    idStr::SetFileExtension(this: &v112, extension: "csv");
    v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v112.data, a3: 2);
    v109 = v2;
    if ( v2 != nullptr )
    {
      idStr::idStr(this: &v111, text: "displayName,decl,price,numAmmo,");
      LODWORD(v4) = &unk_82360000;
      v7 = va::va(
             this: &v114,
             fmt: "melee name,damage decl,minDamage,maxDamage,",
             a3: v6,
             a4: v5,
             a5: v4,
             a6: v65,
             a7: v72,
             a8: v79,
             a9: v86,
             a10: v93,
             a11: v100);
      idStr::Append(this: &v111, text: v7);
      LODWORD(v9) = &unk_82360000;
      HIDWORD(v9) = &unk_82360000;
      LODWORD(v10) = &unk_82360000;
      for ( i = 0; i < 4; ++i )
      {
        HIDWORD(v8) = i;
        v12 = va::va(
                this: &v114,
                fmt: "ammo %d name,decl,projectile decl,damage decl,splash damage decl,",
                a3: v8,
                a4: v10,
                a5: v9,
                a6: v66,
                a7: v73,
                a8: v80,
                a9: v87,
                a10: v94,
                a11: v101);
        idStr::Append(this: &v111, text: v12);
        v16 = va::va(
                this: &v114,
                fmt: "minDamage,maxDamage,",
                a3: v15,
                a4: v14,
                a5: v13,
                a6: v67,
                a7: v74,
                a8: v81,
                a9: v88,
                a10: v95,
                a11: v102);
        idStr::Append(this: &v111, text: v16);
        idStr::Append(this: &v111, text: "minSplashDamage,maxSplashDamage,");
        idStr::Append(this: &v111, text: "clipSize,upgradedClipSize,price,");
      }
      v2->Printf(this: v2, a2: "%s\n", v111.data);
      v17 = 0;
      if ( idDeclWeapon::resourceList.declSources.num > 0 )
      {
        v18 = 0;
        do
        {
          str = idDeclWeapon::resourceList.declSources.list[v18]->name.str;
          if ( str != nullptr )
            v20 = (idDeclWeapon *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclWeapon::resourceList,
                                    name: str,
                                    makeDefault: false);
          else
            v20 = nullptr;
          if ( idStr::Find(searchIn: v20->name.str, searchFor: "/ai/", casesensitive: false, start: 0, end: -1) == -1 )
          {
            v21 = 0;
            v22 = 0;
            num = v20->validAmmoClips.num;
            if ( num > 0 )
            {
              v23 = 0;
              do
              {
                validAmmoDecl = v20->validAmmoClips.list[v23].validAmmoDecl;
                if ( validAmmoDecl != nullptr && validAmmoDecl->projectileDecl != nullptr )
                  ++v21;
                ++v22;
                ++v23;
              }
              while ( v22 < num );
            }
            v25 = v20->name.str;
            price = v20->price;
            LocalizedString = idStrId::GetLocalizedString(this: &v20->displayName);
            v29 = va::va(
                    this: &v114,
                    fmt: "%s,%s,%d,%d",
                    a3: __SPAIR64__((unsigned int)LocalizedString, (unsigned int)v25),
                    a4: __SPAIR64__(price, v21),
                    a5: v28,
                    a6: v66,
                    a7: v73,
                    a8: v80,
                    a9: v87,
                    a10: v94,
                    a11: v101);
            idStr::idStr(this: &v110, text: v29);
            pistolWhipProjectile = v20->pistolWhipProjectile;
            if ( pistolWhipProjectile != nullptr )
            {
              LODWORD(v30) = pistolWhipProjectile->damageDecl;
              DWORD1(v34) = pistolWhipProjectile->name.str;
              v107 = *(float *)(v30 + 132);
              v35 = LODWORD(v107);
              *((double *)&v34 + 1) = *(float *)(v30 + 128);
              v36 = va::va(
                      this: &v113,
                      fmt: ",%s,%s,%.2f,%.2f",
                      a3: *(__int64 *)((char *)&v34 + 4),
                      a4: *(__int64 *)((char *)&v34 - 4),
                      a5: v30,
                      a6: v68,
                      a7: v75,
                      a8: v82,
                      a9: v89,
                      a10: v96,
                      a11: v103);
            }
            else
            {
              v36 = va::va(
                      this: &v113,
                      fmt: ",,,,",
                      a3: v32,
                      a4: v31,
                      a5: v30,
                      a6: v68,
                      a7: v75,
                      a8: v82,
                      a9: v89,
                      a10: v96,
                      a11: v103);
            }
            idStr::Append(this: &v110, text: v36);
            v40 = 0;
            if ( v20->validAmmoClips.num > 0 )
            {
              v41 = 0;
              do
              {
                v42 = v20->validAmmoClips.list[v41].validAmmoDecl;
                if ( v42 != nullptr )
                {
                  LODWORD(v37) = v42->projectileDecl;
                  if ( (_DWORD)v37 != 0 )
                  {
                    v43 = *(_DWORD *)(v37 + 452);
                    v44 = &byte_8200D768;
                    if ( v43 != 0 )
                      v44 = *(char **)(v43 + 8);
                    v45 = *(_DWORD *)(v37 + 444);
                    v46 = &byte_8200D768;
                    if ( v45 != 0 )
                      v46 = *(char **)(v45 + 8);
                    projectileDecl = v42->projectileDecl;
                    v48 = v42->name.str;
                    damageDecl = projectileDecl->damageDecl;
                    v50 = projectileDecl->name.str;
                    maxDamage = damageDecl->maxDamage;
                    minDamage = damageDecl->minDamage;
                    v53 = idStrId::GetLocalizedString(this: &v42->displayName);
                    v54 = va::va(
                            this: &v113,
                            fmt: ",%s,%s,%s,%s,%s,%.2f,%.2f,",
                            a3: __SPAIR64__((unsigned int)v53, (unsigned int)v48),
                            a4: __SPAIR64__((unsigned int)v50, (unsigned int)v46),
                            a5: __SPAIR64__((unsigned int)v44, LODWORD(minDamage)),
                            a6: v69,
                            a7: v76,
                            a8: v83,
                            a9: v90,
                            a10: v97,
                            a11: v104,
                            minDamage,
                            maxDamage);
                    idStr::Append(this: &v110, text: v54);
                    HIDWORD(v55) = v42->projectileDecl;
                    LODWORD(v56) = *(_DWORD *)(HIDWORD(v55) + 452);
                    if ( (_DWORD)v56 != 0 )
                    {
                      LODWORD(v55) = *(_DWORD *)(HIDWORD(v55) + 452);
                      v57 = va::va(
                              this: &v113,
                              fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(v55 + 128))),
                              a3: COERCE__INT64(*(float *)(v55 + 132)),
                              a4: v56,
                              a5: v55,
                              a6: v70,
                              a7: v77,
                              a8: v84,
                              a9: v91,
                              a10: v98,
                              a11: v105);
                    }
                    else
                    {
                      v57 = va::va(
                              this: &v113,
                              fmt: nullptr,
                              a3: 0,
                              a4: v56,
                              a5: v55,
                              a6: v70,
                              a7: v77,
                              a8: v84,
                              a9: v91,
                              a10: v98,
                              a11: v105,
                              0.0,
                              0.0);
                    }
                    idStr::Append(this: &v110, text: v57);
                    v58 = v42->price;
                    ClipSize = idDeclWeapon::GetClipSize(
                                 this: v20,
                                 ammoDecl: v42,
                                 weaponUpgraded: true,
                                 secondary: false);
                    v60 = idDeclWeapon::GetClipSize(this: v20, ammoDecl: v42, weaponUpgraded: false, secondary: false);
                    HIDWORD(v61) = v58;
                    v63 = va::va(
                            this: &v113,
                            fmt: "%d,%d,%d",
                            a3: __SPAIR64__(v60, ClipSize),
                            a4: v61,
                            a5: v62,
                            a6: v71,
                            a7: v78,
                            a8: v85,
                            a9: v92,
                            a10: v99,
                            a11: v106);
                    idStr::Append(this: &v110, text: v63);
                    v2 = v109;
                  }
                }
                ++v40;
                ++v41;
              }
              while ( v40 < v20->validAmmoClips.num );
            }
            HIDWORD(v39) = v110.data;
            v64 = va::va(
                    this: &v113,
                    fmt: "%s\n",
                    a3: v39,
                    a4: v38,
                    a5: v37,
                    a6: v69,
                    a7: v76,
                    a8: v83,
                    a9: v90,
                    a10: v97,
                    a11: v104);
            v2->Printf(this: v2, a2: v64->buffer);
            idStr::FreeData(this: &v110);
          }
          ++v17;
          ++v18;
        }
        while ( v17 < idDeclWeapon::resourceList.declSources.num );
      }
      ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
      idStr::FreeData(this: &v111);
    }
    else
    {
      if ( args->argc <= 1 )
        v3 = &byte_8200D768;
      else
        v3 = args->argv[1];
      idLib::Warning(fmt: "Could not create output file '%s'", v3);
    }
    idStr::FreeData(this: &v112);
  }
  else
  {
    idLib::Printf(fmt: "usage: ExportPlayerWeaponStats <csv file name>\n");
  }
}


// ========================================================================
// __unwind$499379
// EA  : 0x82E59010
// RVA : 0x00E59010
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499379()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8592 + 192));
}


// ========================================================================
// __unwind$499380
// EA  : 0x82E59038
// RVA : 0x00E59038
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499380()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8592 + 160));
}


// ========================================================================
// __unwind$499381
// EA  : 0x82E59060
// RVA : 0x00E59060
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499381()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8592 + 128));
}


// ========================================================================
// ?ExportPlayerRecipes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E59090
// RVA : 0x00E59090
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ExportPlayerRecipes_f(const idCmdArgs *args)
{
  idFile *v2; // r21
  const char *v3; // r4
  int i; // r30
  int v5; // r22
  int v6; // r23
  const char *str; // r4
  const idDecl *v8; // r27
  idStrId *v9; // r11
  const char *v10; // r30
  int textSource; // r26
  int index; // r29
  const char *LocalizedString; // r3
  __int64 v14; // r10
  va *v15; // r3
  int v16; // r30
  int v17; // r28
  idStrId **v18; // r10
  const char *v19; // r29
  idStrId *v20; // r16
  int v21; // r15
  const char *v22; // r3
  __int64 v23; // r10
  va *v24; // r3
  int v25; // [sp+8h] [-2148h]
  int v26; // [sp+Ch] [-2144h]
  int v27; // [sp+10h] [-2140h]
  int v28; // [sp+14h] [-213Ch]
  int v29; // [sp+18h] [-2138h]
  int v30; // [sp+1Ch] [-2134h]
  idStr v31; // [sp+60h] [-20F0h] BYREF
  idStr v32; // [sp+80h] [-20D0h] BYREF
  idStr v33; // [sp+A0h] [-20B0h] BYREF
  va v34; // [sp+C0h] [-2090h] BYREF
  va v35; // [sp+10C0h] [-1090h] BYREF

  if ( args->argc == 2 )
  {
    idStr::idStr(this: &v31, text: args->argv[1]);
    idStr::SetFileExtension(this: &v31, extension: "csv");
    v2 = fileSystem->OpenFileWrite(this: fileSystem, a2: v31.data, a3: 2);
    if ( v2 != nullptr )
    {
      idStr::idStr(this: &v33, text: "decl,produces,produces decl,numIngredients");
      for ( i = 5; i != 0; --i )
        idStr::Append(this: &v33, text: ",ingredient,decl,count,consumed");
      v2->Printf(this: v2, a2: "%s\n", v33.data);
      v5 = 0;
      if ( idDeclRecipe::resourceList.declSources.num > 0 )
      {
        v6 = 0;
        do
        {
          str = idDeclRecipe::resourceList.declSources.list[v6]->name.str;
          if ( str != nullptr )
            v8 = idDeclInfo::FindWithInheritance(this: &idDeclRecipe::resourceList, name: str, makeDefault: false);
          else
            v8 = nullptr;
          v9 = (idStrId *)v8[1].name.str;
          v10 = v8->name.str;
          textSource = (int)v8[1].textSource;
          index = v9[2].index;
          LocalizedString = idStrId::GetLocalizedString(this: v9 + 41);
          v15 = va::va(
                  this: &v34,
                  fmt: "%s,%s,%s,%d",
                  a3: __SPAIR64__((unsigned int)v10, (unsigned int)LocalizedString),
                  a4: __SPAIR64__(index, textSource),
                  a5: v14,
                  a6: v25,
                  a7: v26,
                  a8: v27,
                  a9: v28,
                  a10: v29,
                  a11: v30);
          idStr::idStr(this: &v32, text: v15);
          v16 = 0;
          if ( textSource > 0 )
          {
            v17 = 0;
            do
            {
              if ( v16 < 0 || v16 > (int)v8[1].textSource )
                v18 = nullptr;
              else
                v18 = (idStrId **)(*((_DWORD *)&v8[1].idResource + 8) + v17);
              v19 = "true";
              if ( *((_BYTE *)v18 + 8) == 0 )
                v19 = "false";
              v20 = v18[1];
              v21 = (*v18)[2].index;
              v22 = idStrId::GetLocalizedString(this: *v18 + 41);
              v24 = va::va(
                      this: &v35,
                      fmt: ",%s,%s,%d,%s",
                      a3: __SPAIR64__((unsigned int)v22, v21),
                      a4: __SPAIR64__((unsigned int)v20, (unsigned int)v19),
                      a5: v23,
                      a6: v25,
                      a7: v26,
                      a8: v27,
                      a9: v28,
                      a10: v29,
                      a11: v30);
              idStr::Append(this: &v32, text: v24);
              ++v16;
              v17 += 12;
            }
            while ( v16 < textSource );
          }
          v2->Printf(this: v2, a2: "%s\n", v32.data);
          idStr::FreeData(this: &v32);
          ++v5;
          ++v6;
        }
        while ( v5 < idDeclRecipe::resourceList.declSources.num );
      }
      ((void (__fastcall *)(idFile *, int))v2->dtr_idFile)(a1: v2, a2: 1);
      idStr::FreeData(this: &v33);
    }
    else
    {
      if ( args->argc <= 1 )
        v3 = &byte_8200D768;
      else
        v3 = args->argv[1];
      idLib::Warning(fmt: "Could not create output file '%s'", v3);
    }
    idStr::FreeData(this: &v31);
  }
  else
  {
    idLib::Printf(fmt: "usage: ExportPlayerRecipes <csv file name>\n");
  }
}


// ========================================================================
// __unwind$499676
// EA  : 0x82E59354
// RVA : 0x00E59354
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499676()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 96));
}


// ========================================================================
// __unwind$499677
// EA  : 0x82E5937C
// RVA : 0x00E5937C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499677()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 160));
}


// ========================================================================
// __unwind$499678
// EA  : 0x82E593A4
// RVA : 0x00E593A4
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499678()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8528 + 128));
}


// ========================================================================
// ?ExportPlayerAmmo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E593D8
// RVA : 0x00E593D8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ExportPlayerAmmo_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r4
  idFile *v4; // r22
  const char *v5; // r4
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  va *v13; // r3
  __int64 v14; // r8
  __int64 v15; // r10
  __int64 v16; // r6
  va *v17; // r3
  __int64 v18; // r8
  __int64 v19; // r10
  __int64 v20; // r6
  va *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  va *v33; // r3
  int v34; // r21
  int v35; // r28
  const char *str; // r4
  const idDecl *v37; // r3
  const idDecl *v38; // r30
  const char *v39; // r19
  __int64 v40; // r18
  const char *LocalizedString; // r3
  __int64 v42; // r10
  va *v43; // r3
  __int64 v44; // r10
  __int64 v45; // r8 OVERLAPPED
  idDecl_vtbl *v46; // r30
  unsigned int (__fastcall *Size)(idDecl *); // r11
  __int64 v48; // r6
  va *v49; // r3
  __int64 v50; // r10
  float *LoadResource; // r11
  va *v52; // r3
  __int64 v53; // r10
  float *ReloadIfStale; // r11
  va *v55; // r3
  int v56; // [sp+8h] [-2158h]
  int v57; // [sp+8h] [-2158h]
  int v58; // [sp+8h] [-2158h]
  int v59; // [sp+8h] [-2158h]
  int v60; // [sp+8h] [-2158h]
  int v61; // [sp+8h] [-2158h]
  int v62; // [sp+8h] [-2158h]
  int v63; // [sp+8h] [-2158h]
  int v64; // [sp+8h] [-2158h]
  int v65; // [sp+8h] [-2158h]
  int v66; // [sp+Ch] [-2154h]
  int v67; // [sp+Ch] [-2154h]
  int v68; // [sp+Ch] [-2154h]
  int v69; // [sp+Ch] [-2154h]
  int v70; // [sp+Ch] [-2154h]
  int v71; // [sp+Ch] [-2154h]
  int v72; // [sp+Ch] [-2154h]
  int v73; // [sp+Ch] [-2154h]
  int v74; // [sp+Ch] [-2154h]
  int v75; // [sp+Ch] [-2154h]
  int v76; // [sp+10h] [-2150h]
  int v77; // [sp+10h] [-2150h]
  int v78; // [sp+10h] [-2150h]
  int v79; // [sp+10h] [-2150h]
  int v80; // [sp+10h] [-2150h]
  int v81; // [sp+10h] [-2150h]
  int v82; // [sp+10h] [-2150h]
  int v83; // [sp+10h] [-2150h]
  int v84; // [sp+10h] [-2150h]
  int v85; // [sp+10h] [-2150h]
  int v86; // [sp+14h] [-214Ch]
  int v87; // [sp+14h] [-214Ch]
  int v88; // [sp+14h] [-214Ch]
  int v89; // [sp+14h] [-214Ch]
  int v90; // [sp+14h] [-214Ch]
  int v91; // [sp+14h] [-214Ch]
  int v92; // [sp+14h] [-214Ch]
  int v93; // [sp+14h] [-214Ch]
  int v94; // [sp+14h] [-214Ch]
  int v95; // [sp+14h] [-214Ch]
  int v96; // [sp+18h] [-2148h]
  int v97; // [sp+18h] [-2148h]
  int v98; // [sp+18h] [-2148h]
  int v99; // [sp+18h] [-2148h]
  int v100; // [sp+18h] [-2148h]
  int v101; // [sp+18h] [-2148h]
  int v102; // [sp+18h] [-2148h]
  int v103; // [sp+18h] [-2148h]
  int v104; // [sp+18h] [-2148h]
  int v105; // [sp+18h] [-2148h]
  int v106; // [sp+1Ch] [-2144h]
  int v107; // [sp+1Ch] [-2144h]
  int v108; // [sp+1Ch] [-2144h]
  int v109; // [sp+1Ch] [-2144h]
  int v110; // [sp+1Ch] [-2144h]
  int v111; // [sp+1Ch] [-2144h]
  int v112; // [sp+1Ch] [-2144h]
  int v113; // [sp+1Ch] [-2144h]
  int v114; // [sp+1Ch] [-2144h]
  int v115; // [sp+1Ch] [-2144h]
  idStrId v116; // [sp+50h] [-2110h] BYREF
  idStr v117; // [sp+60h] [-2100h] BYREF
  idStr v118; // [sp+80h] [-20E0h] BYREF
  idDeclSource **v119; // [sp+A0h] [-20C0h]
  idStr v120; // [sp+B0h] [-20B0h] BYREF
  va v121; // [sp+D0h] [-2090h] BYREF
  va v122; // [sp+10D0h] [-1090h] BYREF

  argc = args->argc;
  v116.index = args->argc;
  if ( v116.index == 2 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    idStr::idStr(this: &v120, text: v3);
    idStr::SetFileExtension(this: &v120, extension: "csv");
    v4 = fileSystem->OpenFileWrite(this: fileSystem, a2: v120.data, a3: 2);
    if ( v4 != nullptr )
    {
      idStr::idStr(
        this: &v117,
        text: "ammo name,ammo decl,count,price,clip size,clip size upgrade,reload num,reload num upgrade,");
      LODWORD(v6) = &unk_82360000;
      v9 = va::va(
             this: &v121,
             fmt: "projectile decl,aim assist range,aim assist zoom snap,spread,spawn count,burst duration,",
             a3: v8,
             a4: v7,
             a5: v6,
             a6: v56,
             a7: v66,
             a8: v76,
             a9: v86,
             a10: v96,
             a11: v106);
      idStr::Append(this: &v117, text: v9);
      HIDWORD(v10) = &unk_82360000;
      v13 = va::va(
              this: &v121,
              fmt: "pitch kick amount,pitch kick delta,pitch kick into,pitch kick from,",
              a3: v12,
              a4: v11,
              a5: v10,
              a6: v57,
              a7: v67,
              a8: v77,
              a9: v87,
              a10: v97,
              a11: v107);
      idStr::Append(this: &v117, text: v13);
      LODWORD(v14) = &unk_82360000;
      v17 = va::va(
              this: &v121,
              fmt: "yaw kick amount,yaw kick into,yaw kick from,",
              a3: v16,
              a4: v14,
              a5: v15,
              a6: v58,
              a7: v68,
              a8: v78,
              a9: v88,
              a10: v98,
              a11: v108);
      idStr::Append(this: &v117, text: v17);
      HIDWORD(v18) = &unk_82360000;
      v21 = va::va(
              this: &v121,
              fmt: "spread addition per shot,max spread addition,recovery delay,",
              a3: v20,
              a4: v18,
              a5: v19,
              a6: v59,
              a7: v69,
              a8: v79,
              a9: v89,
              a10: v99,
              a11: v109);
      idStr::Append(this: &v117, text: v21);
      LODWORD(v22) = &unk_82360000;
      v25 = va::va(
              this: &v121,
              fmt: "damage decl,min damage,max damage,",
              a3: v22,
              a4: v24,
              a5: v23,
              a6: v60,
              a7: v70,
              a8: v80,
              a9: v90,
              a10: v100,
              a11: v110);
      idStr::Append(this: &v117, text: v25);
      HIDWORD(v26) = &unk_82360000;
      v29 = va::va(
              this: &v121,
              fmt: "splash damage decl,min damage,max damage,radius,",
              a3: v26,
              a4: v28,
              a5: v27,
              a6: v61,
              a7: v71,
              a8: v81,
              a9: v91,
              a10: v101,
              a11: v111);
      idStr::Append(this: &v117, text: v29);
      v33 = va::va(
              this: &v121,
              fmt: "electric damage decl,min damage,max damage,radius,",
              a3: v32,
              a4: v31,
              a5: v30,
              a6: v62,
              a7: v72,
              a8: v82,
              a9: v92,
              a10: v102,
              a11: v112);
      idStr::Append(this: &v117, text: v33);
      v4->Printf(this: v4, a2: "%s\n", v117.data);
      v34 = 0;
      if ( idDeclAmmo::resourceList.declSources.num > 0 )
      {
        v35 = 0;
        do
        {
          v119 = &idDeclAmmo::resourceList.declSources.list[v35];
          str = idDeclAmmo::resourceList.declSources.list[v35]->name.str;
          if ( str != nullptr )
          {
            v37 = idDeclInfo::FindWithInheritance(this: &idDeclAmmo::resourceList, name: str, makeDefault: false);
            v38 = v37;
            if ( v37 != nullptr )
            {
              v39 = v37->name.str;
              v116.index = (int)v37[2].declSource;
              LODWORD(v40) = v37[6].staleCount;
              HIDWORD(v40) = v37[6].__vftable;
              LocalizedString = idStrId::GetLocalizedString(this: &v116);
              v43 = va::va(
                      this: &v121,
                      fmt: "%s,%s,%d,%d,",
                      a3: __SPAIR64__((unsigned int)LocalizedString, (unsigned int)v39),
                      a4: v40,
                      a5: v42,
                      a6: v63,
                      a7: v73,
                      a8: v83,
                      a9: v93,
                      a10: v103,
                      a11: v113);
              idStr::idStr(this: &v118, text: v43);
              v46 = v38[9].__vftable;
              if ( v46 != nullptr )
              {
                Size = v46[6].Size;
                if ( Size != nullptr )
                {
                  *(double *)((char *)&v45 + 4) = *((float *)Size + 33);
                  HIDWORD(v48) = *((_DWORD *)Size + 2);
                  v49 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,",
                          a3: v48,
                          a4: v45,
                          a5: v44,
                          a6: v63,
                          a7: v73,
                          a8: v83,
                          a9: v93,
                          a10: v103,
                          a11: v113);
                }
                else
                {
                  v49 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,",
                          a3: 0,
                          a4: (unsigned int)v45,
                          a5: v44,
                          a6: v63,
                          a7: v73,
                          a8: v83,
                          a9: v93,
                          a10: v103,
                          a11: v113,
                          0.0,
                          0.0);
                }
                idStr::Append(this: &v118, text: v49);
                LoadResource = (float *)v46[7].LoadResource;
                if ( LoadResource != nullptr )
                  v52 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,%.2f,",
                          a3: COERCE__INT64(LoadResource[32]),
                          a4: __SPAIR64__(COERCE_UNSIGNED_INT64(LoadResource[33]), COERCE_UNSIGNED_INT64(LoadResource[50])),
                          a5: v50,
                          a6: v64,
                          a7: v74,
                          a8: v84,
                          a9: v94,
                          a10: v104,
                          a11: v114);
                else
                  v52 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,%.2f,",
                          a3: 0,
                          a4: 0,
                          a5: v50,
                          a6: v64,
                          a7: v74,
                          a8: v84,
                          a9: v94,
                          a10: v104,
                          a11: v114,
                          0.0,
                          0.0,
                          0.0);
                idStr::Append(this: &v118, text: v52);
                ReloadIfStale = (float *)v46[7].ReloadIfStale;
                if ( ReloadIfStale != nullptr )
                  v55 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,%.2f",
                          a3: COERCE__INT64(ReloadIfStale[32]),
                          a4: __SPAIR64__(
                            COERCE_UNSIGNED_INT64(ReloadIfStale[33]),
                            COERCE_UNSIGNED_INT64(ReloadIfStale[50])),
                          a5: v53,
                          a6: v65,
                          a7: v75,
                          a8: v85,
                          a9: v95,
                          a10: v105,
                          a11: v115);
                else
                  v55 = va::va(
                          this: &v122,
                          fmt: "%s,%.2f,%.2f,%.2f",
                          a3: 0,
                          a4: 0,
                          a5: v53,
                          a6: v65,
                          a7: v75,
                          a8: v85,
                          a9: v95,
                          a10: v105,
                          a11: v115,
                          0.0,
                          0.0,
                          0.0);
                idStr::Append(this: &v118, text: v55);
              }
              v4->Printf(this: v4, a2: "%s\n", v118.data);
              idStr::FreeData(this: &v118);
            }
          }
          ++v34;
          ++v35;
        }
        while ( v34 < idDeclAmmo::resourceList.declSources.num );
      }
      ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
      idStr::FreeData(this: &v117);
    }
    else
    {
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idLib::Warning(fmt: "Could not create output file '%s'", v5);
    }
    idStr::FreeData(this: &v120);
  }
  else
  {
    idLib::Printf(fmt: "usage: ExportPlayerRecipes <csv file name>\n");
  }
}


// ========================================================================
// __unwind$499879
// EA  : 0x82E5983C
// RVA : 0x00E5983C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499879()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8544 + 176));
}


// ========================================================================
// __unwind$499880
// EA  : 0x82E59864
// RVA : 0x00E59864
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499880()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8544 + 96));
}


// ========================================================================
// __unwind$499881
// EA  : 0x82E5988C
// RVA : 0x00E5988C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_499881()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8544 + 128));
}


// ========================================================================
// ?Give_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E59A48
// RVA : 0x00E59A48
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Give_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r29
  const char *v4; // r3
  const char *v5; // r3
  int v6; // r4
  int v7; // r3
  const char *v8; // r3
  const char *v9; // r4
  const char *v10; // r3
  const char *v11; // r5
  const char *v12; // r4
  idCmdArgs v13; // [sp+50h] [-1240h] BYREF
  idCmdArgs v14; // [sp+960h] [-930h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc < 2 )
    {
      idLib::Printf(fmt: "Give what?\n");
      return;
    }
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    if ( idStr::Icmp(s1: v4, s2: "all") == 0 )
    {
      idPlayer::GiveAll(this: v3);
      return;
    }
    if ( args->argc <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[1];
    if ( idStr::Icmp(s1: v5, s2: "recipes") != 0 )
    {
      idCmdArgs::idCmdArgs(this: &v13, other: args);
      if ( v13.argc < 3 )
      {
        v8 = v13.argv[1];
        if ( v13.argc <= 1 )
          v8 = &byte_8200D768;
        if ( idStr::Icmp(s1: v8, s2: "health") != 0 )
        {
          v10 = v13.argv[1];
          if ( v13.argc <= 1 )
            v10 = &byte_8200D768;
          if ( idStr::Icmp(s1: v10, s2: "armor") != 0 )
            v9 = "1";
          else
            v9 = "1000";
        }
        else
        {
          v9 = "1000";
        }
        idCmdArgs::AppendArg(this: &v13, text: v9);
      }
      v11 = v13.argv[2];
      if ( v13.argc <= 2 )
        v11 = &byte_8200D768;
      v12 = v13.argv[1];
      if ( v13.argc <= 1 )
        v12 = &byte_8200D768;
      idPlayer::Give(this: v3, statname: v12, value: v11);
    }
    else
    {
      idCmdArgs::idCmdArgs(this: &v14, other: args);
      v6 = 1;
      if ( args->argc >= 3 )
      {
        if ( args->argc > 2 )
        {
          v7 = atol(nptr: args->argv[2]);
          idPlayer::GiveRecipes(this: v3, recCount: v7);
          return;
        }
        v6 = atol(nptr: &byte_8200D768);
      }
      idPlayer::GiveRecipes(this: v3, recCount: v6);
    }
  }
}


// ========================================================================
// ?GiveAllPlayers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E59C30
// RVA : 0x00E59C30
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall GiveAllPlayers_f(const idCmdArgs *args)
{
  signed int i; // r21
  idPlayer *Player; // r31
  char *v4; // r3
  char *v5; // r3
  int v6; // r4
  char *v7; // r3
  const char *v8; // r3
  const char *v9; // r4
  const char *v10; // r3
  int v11; // r3
  const char *v12; // r5
  const char *v13; // r4
  int j; // r29
  idDeclInfo *v15; // r30
  int k; // r31
  idResource *v17; // r3
  idCmdArgs v18; // [sp+50h] [-1280h] BYREF
  idCmdArgs v19; // [sp+960h] [-970h] BYREF

  if ( args->argc >= 2 )
  {
    if ( common->IsServer(this: common) )
    {
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        if ( Player != nullptr )
        {
          v4 = idCmdArgs::Argv(this: args, arg: 1);
          if ( idStr::Icmp(s1: v4, s2: "all") != 0 )
          {
            v5 = idCmdArgs::Argv(this: args, arg: 1);
            if ( idStr::Icmp(s1: v5, s2: "recipes") != 0 )
            {
              idCmdArgs::idCmdArgs(this: &v18, other: args);
              if ( v18.argc < 3 )
              {
                v8 = v18.argv[1];
                if ( v18.argc <= 1 )
                  v8 = &byte_8200D768;
                if ( idStr::Icmp(s1: v8, s2: "health") != 0 )
                {
                  v10 = v18.argv[1];
                  if ( v18.argc <= 1 )
                    v10 = &byte_8200D768;
                  v11 = idStr::Icmp(s1: v10, s2: "armor");
                  v9 = "1000";
                  if ( v11 != 0 )
                    v9 = "1";
                }
                else
                {
                  v9 = "1000";
                }
                idCmdArgs::AppendArg(this: &v18, text: v9);
              }
              v12 = v18.argv[2];
              if ( v18.argc <= 2 )
                v12 = &byte_8200D768;
              v13 = v18.argv[1];
              if ( v18.argc <= 1 )
                v13 = &byte_8200D768;
              idPlayer::Give(this: Player, statname: v13, value: v12);
            }
            else
            {
              idCmdArgs::idCmdArgs(this: &v19, other: args);
              v6 = 1;
              if ( args->argc >= 3 )
              {
                v7 = idCmdArgs::Argv(this: args, arg: 2);
                v6 = atol(nptr: v7);
              }
              idPlayer::GiveRecipes(this: Player, recCount: v6);
            }
          }
          else
          {
            idPlayer::GiveAll(this: Player);
          }
        }
      }
      for ( j = 0; j < declManager->GetNumDeclTypes(this: declManager); ++j )
      {
        v15 = declManager->GetDeclType_2(this: declManager, a2: j);
        for ( k = 0; k < v15->num; ++k )
        {
          v17 = idResourceList::Index(this: v15, index: k);
          idResource::GetNetworkID(this: v17, alloc: true);
        }
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Give what?\n");
  }
}


// ========================================================================
// ?TestParticle_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E59EB0
// RVA : 0x00E59EB0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall TestParticle_f(const idCmdArgs *args)
{
  int size; // r30
  char v3; // r3
  idClass **list; // r27
  int v5; // r3
  int v6; // r29
  bool v7; // cr56
  char v8; // r3
  const char *Classname; // r3
  idPlayer *DebugPlayer; // r3
  idPlayer *v11; // r27
  int v12; // r28
  int argc; // r11
  const char *v14; // r4
  const char *v15; // r4
  int v16; // r11
  bool v17; // cr58
  const char *v18; // r3
  char *data; // r4
  const idMaterial *v20; // r29
  idPresentable *presentable; // r3
  float *v22; // r3
  idPresentable *v23; // r11
  int v24; // r8
  float v25; // r7
  float *v26; // r3
  float v27; // r7
  float v28; // r9
  __int64 v29; // r4 OVERLAPPED
  __int64 v30; // r7
  double v31; // fp31
  int v32; // r5
  idColor *v33; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  unsigned int GameMs; // r27
  idMat3 *v38; // r30
  idImpactManager *WeaponImpactMgr; // r3
  int v40; // [sp+8h] [-1E8h]
  const idColor *v41; // [sp+Ch] [-1E4h]
  int v42; // [sp+10h] [-1E0h]
  int v43; // [sp+14h] [-1DCh]
  int v44; // [sp+18h] [-1D8h]
  int v45; // [sp+1Ch] [-1D4h]
  int v46; // [sp+20h] [-1D0h]
  int v47; // [sp+24h] [-1CCh]
  int v48; // [sp+28h] [-1C8h]
  int v49; // [sp+2Ch] [-1C4h]
  int v50; // [sp+30h] [-1C0h]
  int v51; // [sp+34h] [-1BCh]
  int v52; // [sp+38h] [-1B8h]
  int v53; // [sp+3Ch] [-1B4h]
  int v54; // [sp+40h] [-1B0h]
  int v55; // [sp+44h] [-1ACh]
  int v56; // [sp+48h] [-1A8h]
  int v57; // [sp+4Ch] [-1A4h]
  int v58; // [sp+50h] [-1A0h]
  int v59; // [sp+58h] [-198h]
  int v60; // [sp+5Ch] [-194h]
  int v61; // [sp+60h] [-190h]
  int v62; // [sp+68h] [-188h]
  idList<idVehicleState *,5> v63; // [sp+70h] [-180h] BYREF
  __int64 v64; // [sp+80h] [-170h] BYREF
  float v65; // [sp+88h] [-168h]
  float v66; // [sp+8Ch] [-164h]
  idVec3 v67; // [sp+90h] [-160h] BYREF
  idVec3 v68; // [sp+A0h] [-150h] BYREF
  float v69[4]; // [sp+B0h] [-140h] BYREF
  idStr v70; // [sp+C0h] [-130h] BYREF
  idStr v71; // [sp+E0h] [-110h] BYREF
  trace_t v72; // [sp+100h] [-F0h] BYREF
  idVec3 v73[3]; // [sp+180h] [-70h] BYREF

  memset(&v63, 0, 14);
  *(_WORD *)&v63.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v63);
  size = v63.size;
  if ( v63.size >= 128
    || (v3 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v63, newsize: 128),
        size = v63.size,
        v3 != 0) )
  {
    if ( size <= 128 )
      v63.num = size;
    else
      v63.num = 128;
  }
  list = v63.list;
  v5 = gameLocal->GetSelectedEntities(this: gameLocal, a2: (idEntity **)v63.list, a3: v63.num);
  v6 = v5;
  v7 = v5 < size;
  if ( v5 > size )
  {
    v8 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v63, newsize: v5);
    list = v63.list;
    if ( v8 == 0 )
      goto LABEL_11;
    size = v63.size;
    v7 = v6 < v63.size;
  }
  v63.num = v6;
  if ( !v7 )
    v63.num = size;
LABEL_11:
  if ( v6 == 1 )
  {
    Classname = idClass::GetClassname(this: *list);
    idStr::idStr(this: &v71, text: Classname);
    if ( idStr::Icmp(s1: v71.data, s2: "idParticleEmitter") == 0 )
    {
      gameLocal->EntityUpdateModifiedProperties(this: gameLocal, a2: (idEntity *)*list);
      idStr::FreeData(this: &v71);
      goto _M500654;
    }
    idStr::FreeData(this: &v71);
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v11 = DebugPlayer;
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    v12 = 1;
    idStr::idStr(this: &v70, text: g_testParticleName.valueString.data);
    argc = args->argc;
    HIDWORD(v64) = args->argc;
    if ( HIDWORD(v64) == 2 || (HIDWORD(v64) = argc, argc == 3) )
    {
      if ( argc <= 1 )
        v15 = &byte_8200D768;
      else
        v15 = args->argv[1];
      idStr::operator=(this: &v70, text: v15);
      v16 = args->argc;
      v17 = args->argc == 3;
      HIDWORD(v64) = args->argc;
      if ( v17 )
      {
        if ( v16 <= 2 )
          v18 = &byte_8200D768;
        else
          v18 = args->argv[2];
        v12 = atol(nptr: v18);
      }
    }
    else if ( v70.len == 0 )
    {
      if ( argc <= 0 )
        v14 = &byte_8200D768;
      else
        v14 = args->argv[0];
      idLib::Printf(fmt: "Syntax: %s <particleDecl>\n", v14);
      idStr::FreeData(this: &v70);
      goto _M500654;
    }
    data = v70.data;
    if ( v70.data == nullptr )
    {
LABEL_35:
      idLib::Printf(fmt: "Could not find %s\n", data);
      idStr::FreeData(this: &v70);
      goto _M500654;
    }
    v20 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                this: &idDeclParticle::resourceList,
                                name: v70.data,
                                makeDefault: false);
    if ( v20 == nullptr )
    {
      data = v70.data;
      goto LABEL_35;
    }
    presentable = v11->presentable;
    if ( presentable != nullptr )
      v22 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v22 = nullptr;
    v23 = v11->presentable;
    v24 = *((_DWORD *)v22 + 11637);
    v25 = v22[11638];
    *(float *)&v64 = v22[11636];
    LODWORD(v64) = v24;
    v65 = v25;
    if ( v23 != nullptr )
      v26 = (float *)v23->GetPlayerInterface_2(this: v23);
    else
      v26 = nullptr;
    v27 = v26[11635];
    v28 = v26[11633];
    v67.y = v26[11634];
    v67.z = v27;
    v67.x = v28;
    v68.x = (float)(*(float *)&v64 * (float)4096.0) + v28;
    v68.z = v27 + (float)(v65 * (float)4096.0);
    v68.y = v67.y + (float)(*((float *)&v64 + 1) * (float)4096.0);
    idClip::ResolveCollisionQueries(this: &clientGame->clip);
    HIDWORD(v29) = idClip::TracePoint(
                     this: &clientGame->clip,
                     result: &v72,
                     start: &v67,
                     end: &v68,
                     clipMask: 1,
                     passEntityNumber: 0x1FFF);
    HIDWORD(v30) = 0x82000000;
    if ( __fabs((float)((float)((float)(v72.c.normal.x * v72.c.normal.x)
                              + (float)((float)(v72.c.normal.y * v72.c.normal.y)
                                      + (float)(v72.c.normal.z * v72.c.normal.z)))
                      - (float)1.0)) < 0.0099999998 )
    {
      v31 = (float)((float)((float)(v67.z - v72.c.point.z) * (float)(v67.z - v72.c.point.z))
                  + (float)((float)((float)(v67.x - v72.c.point.x) * (float)(v67.x - v72.c.point.x))
                          + (float)((float)(v67.y - v72.c.point.y) * (float)(v67.y - v72.c.point.y))));
      if ( g_useImpactColor.valueInteger != 0 )
      {
        v32 = v72.c.surfaceColor[0];
        LODWORD(v29) = v72.c.surfaceColor[1];
        v69[3] = 1.0;
        LODWORD(v30) = v72.c.surfaceColor[2];
        v33 = (idColor *)v69;
        v64 = v30;
        v69[2] = (float)v30 * (float)0.0039215689;
        v69[1] = (float)v29 * (float)0.0039215689;
        v69[0] = (float)*(__int64 *)((char *)&v29 - 4) * (float)0.0039215689;
      }
      else
      {
        v33 = &idColor::colorWhite;
      }
      g = v33->g;
      b = v33->b;
      a = v33->a;
      *(float *)&v64 = v33->r;
      *((float *)&v64 + 1) = g;
      v65 = b;
      v66 = a;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v38 = idVec3::ToZAxis(this: v73, result: (idMat3 *)&v72.c.normal);
      WeaponImpactMgr = idClientGame::GetWeaponImpactMgr(this: clientGame);
      idImpactManager::UseImpact(
        this: WeaponImpactMgr,
        org: &v72.c.point,
        axis: v38,
        prt: v20,
        startTime: GameMs,
        bindToParent: false,
        parentOrg: &vec3_origin,
        parentAxis: &mat3_identity,
        distSqr: v31,
        playerIndex: v40,
        color: v41,
        numCycles: v42,
        a13: v43,
        a14: v44,
        a15: v45,
        a16: v46,
        a17: v47,
        a18: v48,
        a19: v49,
        a20: v50,
        a21: v51,
        a22: v52,
        a23: v53,
        a24: v54,
        a25: v55,
        a26: v56,
        a27: v57,
        a28: v58,
        a29: 0,
        a30: v59,
        a31: v60,
        a32: v61,
        a33: (float *)&v64,
        a34: v62,
        a35: v12);
    }
    idStr::FreeData(this: &v70);
  }
_M500654:
  idList<idThread *,58>::Clear(this: &v63);
}


// ========================================================================
// __unwind$500360
// EA  : 0x82E5A3D4
// RVA : 0x00E5A3D4
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500360()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 112));
}


// ========================================================================
// __unwind$500361
// EA  : 0x82E5A3FC
// RVA : 0x00E5A3FC
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500361()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 224));
}


// ========================================================================
// __unwind$500362
// EA  : 0x82E5A424
// RVA : 0x00E5A424
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500362()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 192));
}


// ========================================================================
// ?ItemsInMap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E5A458
// RVA : 0x00E5A458
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall ItemsInMap_f(const idCmdArgs *args)
{
  idLinkList<idEntity> *next; // r11
  idProp_Loot *i; // r30
  idLinkList<idEntity> *v3; // r11
  encounterGroupRole_t *list; // r18
  int v5; // r23
  char *count; // r24
  encounterGroupRole_t *v7; // r30
  int j; // r26
  char v9; // r27
  int v10; // r29
  const char **v11; // r28
  const char *v12; // r25
  char *v13; // r11
  const char *LocalizedString; // r3
  encounterGroupRole_t v15; // r10
  idInventoryItem_vtbl *v16; // r9
  void (__fastcall *Serialize)(idInventoryItem *, idSerializer *, idInventoryCollection *); // r7
  void *coolDownTime; // r19
  _DWORD *v19; // r27
  const idDeclSkins *k; // r20
  bfx::Planner3D *v21; // r3
  bfx::Space *TypeDef; // r21
  int v23; // r28
  int v24; // r25
  char v25; // r26
  int v26; // r30
  const char **v27; // r29
  const char *v28; // r17
  idInventoryCollection *v29; // r3
  idStrId *InventoryItem; // r3
  idStrId *DisplayName; // r3
  idInventoryCollection *v32; // r3
  idInventoryItem *v33; // r3
  idInventoryCollection *v34; // r3
  idInventoryItem *v35; // r3
  int v36; // r3
  idInventoryCollection *v37; // r3
  idStrId *v38; // r3
  idStrId *v39; // r3
  const char *v40; // r3
  int v41; // r9
  idInventoryCollection *v42; // r3
  idInventoryItem *v43; // r3
  int v44; // r3
  int v45; // r4
  idInventoryCollection *v46; // r3
  idInventoryItem *v47; // r3
  int v48; // r28
  _DWORD *v49; // r30
  int m; // r29
  idInventoryItem v51; // [sp+50h] [-E0h] BYREF
  int v52; // [sp+78h] [-B8h]
  __int16 v53; // [sp+7Ch] [-B4h]
  char v54; // [sp+7Eh] [-B2h]
  char v55; // [sp+7Fh] [-B1h]
  idList<enum encounterGroupRole_t,5> v56; // [sp+80h] [-B0h] BYREF
  idList<enum encounterGroupRole_t,5> v57; // [sp+90h] [-A0h] BYREF
  itemsGiven v58[9]; // [sp+A0h] [-90h] BYREF

  memset(&v51.count, 0, 12);
  v51.counttosave = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v51.count);
  memset(&v56, 0, 14);
  *(_WORD *)&v56.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v56);
  v51.coolDownTime = 0;
  v53 = 0;
  v54 = 5;
  v55 = 0;
  v52 = 0;
  v51.skinPreload = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v51.coolDownTime);
  memset(&v57, 0, 14);
  *(_WORD *)&v57.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v57);
  next = gameLocal->spawnedEntities.next;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    for ( i = (idProp_Loot *)next->owner; i != nullptr; i = (idProp_Loot *)v3->owner )
    {
      v51.__vftable = (idInventoryItem_vtbl *)idProp_Loot::CastTo(c: i);
      if ( v51.__vftable != nullptr )
      {
        idList<idAnimWebBlendTree *,5>::Append(this: &v57, obj: (encounterGroupRole_t *)&v51);
      }
      else
      {
        v51.__vftable = (idInventoryItem_vtbl *)idProp_Moveable::CastTo(c: i);
        if ( v51.__vftable != nullptr )
        {
          idList<idAnimWebBlendTree *,5>::Append(this: &v56, obj: (encounterGroupRole_t *)&v51);
        }
        else
        {
          v51.__vftable = (idInventoryItem_vtbl *)idProp_BreakableLoot::CastTo(c: (idProp_BreakableLoot *)i);
          if ( v51.__vftable != nullptr )
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&v51.coolDownTime,
              obj: (encounterGroupRole_t *)&v51);
        }
      }
      v3 = i->spawnNode.next;
      if ( v3 == nullptr )
        break;
      if ( v3 == i->spawnNode.head )
        break;
    }
  }
  list = v56.list;
  v5 = *(_DWORD *)&v51.forSale;
  count = (char *)v51.count;
  if ( v56.num > 0 )
  {
    v7 = v56.list;
    for ( j = v56.num; j != 0; --j )
    {
      if ( *(_DWORD *)(*v7 + 5396) != 0 )
      {
        v9 = 0;
        v10 = 0;
        if ( v5 > 0 )
        {
          v11 = (const char **)count;
          while ( 1 )
          {
            v12 = *v11;
            if ( v12 == idStrId::GetLocalizedString(this: (idStrId *)(*(_DWORD *)(*v7 + 5396) + 164)) )
              break;
            ++v10;
            v11 += 4;
            if ( v10 >= v5 )
              goto LABEL_22;
          }
          v9 = 1;
          v13 = &count[16 * v10];
          *((_DWORD *)v13 + 1) += *(_DWORD *)(*(_DWORD *)(*v7 + 5396) + 336) * *(_DWORD *)(*v7 + 5400);
          *((_DWORD *)v13 + 2) += *(_DWORD *)(*(_DWORD *)(*v7 + 5396) + 368) * *(_DWORD *)(*v7 + 5400);
        }
LABEL_22:
        if ( v9 == 0 )
        {
          LocalizedString = idStrId::GetLocalizedString(this: (idStrId *)(*(_DWORD *)(*v7 + 5396) + 164));
          v15 = *v7;
          v58[0].name = LocalizedString;
          v16 = *(idInventoryItem_vtbl **)(v15 + 5396);
          v51.__vftable = *(idInventoryItem_vtbl **)(v15 + 5400);
          Serialize = v16[3].Serialize;
          v58[0].sellper = (int)v16[4].InternalCallEvent * (int)v51.__vftable;
          v58[0].count = (_DWORD)Serialize * (int)v51.__vftable;
          v58[0].selltotal = v58[0].sellper;
          v51.__vftable = v16;
          idList<itemsGiven,5>::Append(this: (idList<itemsGiven,5> *)&v51.count, obj: v58);
          v5 = *(_DWORD *)&v51.forSale;
          count = (char *)v51.count;
        }
      }
      ++v7;
    }
  }
  coolDownTime = (void *)v51.coolDownTime;
  if ( (int)v51.skinPreload > 0 )
  {
    v19 = (_DWORD *)v51.coolDownTime;
    for ( k = v51.skinPreload; k != nullptr; k = (const idDeclSkins *)((char *)k - 1) )
    {
      v21 = (bfx::Planner3D *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)*v19 + 468))(a1: *v19);
      TypeDef = idScriptObject::GetTypeDef(this: v21);
      v23 = 0;
      if ( (int)TypeDef > 0 )
      {
        v24 = 0;
        do
        {
          v25 = 0;
          v26 = 0;
          if ( v5 > 0 )
          {
            v27 = (const char **)count;
            while ( 1 )
            {
              v28 = *v27;
              v29 = (idInventoryCollection *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)*v19 + 468))(a1: *v19);
              InventoryItem = (idStrId *)idInventoryCollection::GetInventoryItem(this: v29, index: v23);
              DisplayName = idInventoryItem::GetDisplayName(this: &v51, result: InventoryItem);
              if ( v28 == idStrId::GetLocalizedString(this: DisplayName) )
                break;
              ++v26;
              v27 += 4;
              if ( v26 >= v5 )
                goto LABEL_35;
            }
            v32 = (idInventoryCollection *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)*v19 + 468))(a1: *v19);
            v33 = idInventoryCollection::GetInventoryItem(this: v32, index: v23);
            *(_DWORD *)&count[16 * v26 + 4] += v33->GetCount(this: v33);
            v34 = (idInventoryCollection *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)*v19 + 468))(a1: *v19);
            v35 = idInventoryCollection::GetInventoryItem(this: v34, index: v23);
            v25 = 1;
            *(_DWORD *)&count[v24 + 8] += idInventoryItem::GetSellPrice(this: v35);
          }
LABEL_35:
          if ( v25 == 0 )
          {
            v36 = *v19;
            v58[0].sellper = 0;
            v37 = (idInventoryCollection *)(*(int (__fastcall **)(int))(*(_DWORD *)v36 + 468))(a1: v36);
            v38 = (idStrId *)idInventoryCollection::GetInventoryItem(this: v37, index: v23);
            v39 = idInventoryItem::GetDisplayName(this: (idInventoryItem *)&v51.listenerList, result: v38);
            v40 = idStrId::GetLocalizedString(this: v39);
            v41 = *v19;
            v58[0].name = v40;
            v42 = (idInventoryCollection *)(*(int (__fastcall **)(int))(*(_DWORD *)v41 + 468))(a1: v41);
            v43 = idInventoryCollection::GetInventoryItem(this: v42, index: v23);
            v44 = v43->GetCount(this: v43);
            v45 = *v19;
            v58[0].count = v44;
            v46 = (idInventoryCollection *)(*(int (__fastcall **)(int))(*(_DWORD *)v45 + 468))(a1: v45);
            v47 = idInventoryCollection::GetInventoryItem(this: v46, index: v23);
            v58[0].selltotal = idInventoryItem::GetSellPrice(this: v47);
            idList<itemsGiven,5>::Append(this: (idList<itemsGiven,5> *)&v51.count, obj: v58);
            v5 = *(_DWORD *)&v51.forSale;
            count = (char *)v51.count;
          }
          ++v23;
          v24 += 16;
        }
        while ( v23 < (int)TypeDef );
      }
      ++v19;
    }
  }
  idLib::Printf(fmt: "%20s,%20s,%20s,%20s\n", "Item", "Count", "Sell Price", "Sell Total");
  v48 = 0;
  if ( v5 > 0 )
  {
    v49 = count + 8;
    for ( m = v5; m != 0; --m )
    {
      idLib::Printf(fmt: "%20s,%20d,%20d,%20d\n", (const char *)*(v49 - 2), *(v49 - 1), v49[1], *v49);
      v48 += *v49;
      v49 += 4;
    }
  }
  idLib::Printf(fmt: "%20s,%20s,%20s,%20d\n", "Max possible money", &byte_8200D768, &byte_8200D768, v48);
  if ( (v57.listStatic == 0 || v57.listStatic == 2) && v57.list != nullptr )
    idMem::Free(this: &mem, ptr: v57.list, align: ALIGN_16);
  if ( (v55 == 0 || v55 == 2) && coolDownTime != nullptr )
    idMem::Free(this: &mem, ptr: coolDownTime, align: ALIGN_16);
  if ( (v56.listStatic == 0 || v56.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  if ( (LOBYTE(v51.counttosave) == 0 || LOBYTE(v51.counttosave) == 2) && count != nullptr )
    idMem::Free(this: &mem, ptr: count, align: ALIGN_16);
}


// ========================================================================
// __unwind$500702
// EA  : 0x82E5AA3C
// RVA : 0x00E5AA3C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500702()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$500703
// EA  : 0x82E5AA64
// RVA : 0x00E5AA64
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500703()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$500704
// EA  : 0x82E5AA8C
// RVA : 0x00E5AA8C
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500704()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$500705
// EA  : 0x82E5AAB4
// RVA : 0x00E5AAB4
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_500705()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 144));
}


// ========================================================================
// ?Remove_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E5AAE8
// RVA : 0x00E5AAE8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Remove_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r4
  const char *v3; // r27
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6
  idEntity *v7; // r3
  const char *v8; // r3
  int v9; // r30
  const char *v10; // r4
  int i; // r29
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r6
  idEntity *v15; // r3
  idAutoComplete v16; // [sp+60h] [-960h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc == 1 )
      goto _M501244_1;
    if ( args->argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v7 = gameLocal->FindEntity(this: gameLocal, a2: v3);
    if ( v7 != nullptr )
    {
      idEventReceiver::PostEventMS(this: v7, ev: &EV_Remove, time: 0, a4: v6, a5: v5, a6: v4);
      return;
    }
    if ( args->argc == 2
      || (args->argc <= 2 ? (v8 = &byte_8200D768) : (v8 = args->argv[2]), idStr::Cmp(s1: v8, s2: "*") != 0) )
    {
_M501244_1:
      idLib::Printf(fmt: "usage: remove <name of entity to remove>\n");
    }
    else
    {
      v9 = 0;
      v16.matchLength = 0;
      v16.currentIndex = -1;
      v16.args.argc = 0;
      v16.suggestions.memTag = 5;
      v16.suggestions.listStatic = 0;
      memset(&v16.suggestions, 0, 14);
      if ( args->argc <= 1 )
        v10 = &byte_8200D768;
      else
        v10 = args->argv[1];
      idCmdArgs::AppendArg(this: &v16.args, text: v10);
      idGameLocal::ArgCompletion_EntityName(autoComplete: &v16);
      if ( v16.suggestions.num != 0 )
      {
        for ( i = 0; i < v16.suggestions.num; ++v9 )
        {
          v15 = gameLocal->FindEntity(this: gameLocal, a2: v16.suggestions.list[v9].data);
          if ( v15 != nullptr )
            idEventReceiver::PostEventMS(this: v15, ev: &EV_Remove, time: 0, a4: v14, a5: v13, a6: v12);
          ++i;
        }
        idAutoComplete::~idAutoComplete(this: &v16);
      }
      else
      {
        idLib::Printf(fmt: "entity %s not found\n", v3);
        idAutoComplete::~idAutoComplete(this: &v16);
      }
    }
  }
}


// ========================================================================
// __unwind$501136
// EA  : 0x82E5ACB8
// RVA : 0x00E5ACB8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_501136()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(v0 - 2496 + 96));
}


// ========================================================================
// ?Hide_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E5ACE8
// RVA : 0x00E5ACE8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Hide_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r4
  const char *v3; // r27
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6
  idEntity *v7; // r3
  const char *v8; // r3
  int v9; // r30
  const char *v10; // r4
  int i; // r29
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r6
  idEntity *v15; // r3
  idAutoComplete v16; // [sp+60h] [-960h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc == 1 )
      goto _M501366;
    if ( args->argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v7 = gameLocal->FindEntity(this: gameLocal, a2: v3);
    if ( v7 != nullptr )
    {
      idEventReceiver::PostEventMS(this: v7, ev: &EV_Hide, time: 0, a4: v6, a5: v5, a6: v4);
      return;
    }
    if ( args->argc == 2
      || (args->argc <= 2 ? (v8 = &byte_8200D768) : (v8 = args->argv[2]), idStr::Cmp(s1: v8, s2: "*") != 0) )
    {
_M501366:
      idLib::Printf(fmt: "usage: hide <name of entity to remove>\n");
    }
    else
    {
      v9 = 0;
      v16.matchLength = 0;
      v16.currentIndex = -1;
      v16.args.argc = 0;
      v16.suggestions.memTag = 5;
      v16.suggestions.listStatic = 0;
      memset(&v16.suggestions, 0, 14);
      if ( args->argc <= 1 )
        v10 = &byte_8200D768;
      else
        v10 = args->argv[1];
      idCmdArgs::AppendArg(this: &v16.args, text: v10);
      idGameLocal::ArgCompletion_EntityName(autoComplete: &v16);
      if ( v16.suggestions.num != 0 )
      {
        for ( i = 0; i < v16.suggestions.num; ++v9 )
        {
          v15 = gameLocal->FindEntity(this: gameLocal, a2: v16.suggestions.list[v9].data);
          if ( v15 != nullptr )
            idEventReceiver::PostEventMS(this: v15, ev: &EV_Hide, time: 0, a4: v14, a5: v13, a6: v12);
          ++i;
        }
        idAutoComplete::~idAutoComplete(this: &v16);
      }
      else
      {
        idLib::Printf(fmt: "entity %s not found\n", v3);
        idAutoComplete::~idAutoComplete(this: &v16);
      }
    }
  }
}


// ========================================================================
// __unwind$501258
// EA  : 0x82E5AEB8
// RVA : 0x00E5AEB8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_501258()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(v0 - 2496 + 96));
}


// ========================================================================
// ?Show_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E5AEE8
// RVA : 0x00E5AEE8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __fastcall Show_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r4
  const char *v3; // r27
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6
  idEntity *v7; // r3
  const char *v8; // r3
  int v9; // r30
  const char *v10; // r4
  int i; // r29
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r6
  idEntity *v15; // r3
  idAutoComplete v16; // [sp+60h] [-960h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr && (unsigned __int8)idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) != 0 )
  {
    if ( args->argc == 1 )
      goto _M501488_1;
    if ( args->argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v7 = gameLocal->FindEntity(this: gameLocal, a2: v3);
    if ( v7 != nullptr )
    {
      idEventReceiver::PostEventMS(this: v7, ev: &EV_Show, time: 0, a4: v6, a5: v5, a6: v4);
      return;
    }
    if ( args->argc == 2
      || (args->argc <= 2 ? (v8 = &byte_8200D768) : (v8 = args->argv[2]), idStr::Cmp(s1: v8, s2: "*") != 0) )
    {
_M501488_1:
      idLib::Printf(fmt: "usage: show <name of entity to remove>\n");
    }
    else
    {
      v9 = 0;
      v16.matchLength = 0;
      v16.currentIndex = -1;
      v16.args.argc = 0;
      v16.suggestions.memTag = 5;
      v16.suggestions.listStatic = 0;
      memset(&v16.suggestions, 0, 14);
      if ( args->argc <= 1 )
        v10 = &byte_8200D768;
      else
        v10 = args->argv[1];
      idCmdArgs::AppendArg(this: &v16.args, text: v10);
      idGameLocal::ArgCompletion_EntityName(autoComplete: &v16);
      if ( v16.suggestions.num != 0 )
      {
        for ( i = 0; i < v16.suggestions.num; ++v9 )
        {
          v15 = gameLocal->FindEntity(this: gameLocal, a2: v16.suggestions.list[v9].data);
          if ( v15 != nullptr )
            idEventReceiver::PostEventMS(this: v15, ev: &EV_Show, time: 0, a4: v14, a5: v13, a6: v12);
          ++i;
        }
        idAutoComplete::~idAutoComplete(this: &v16);
      }
      else
      {
        idLib::Printf(fmt: "entity %s not found\n", v3);
        idAutoComplete::~idAutoComplete(this: &v16);
      }
    }
  }
}


// ========================================================================
// __unwind$501380
// EA  : 0x82E5B0B8
// RVA : 0x00E5B0B8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void _unwind_501380()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(v0 - 2496 + 96));
}


// ========================================================================
// `dynamic initializer for 'Give_v''
// EA  : 0x8338ECF0
// RVA : 0x0138ECF0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Give_v__()
{
  return idCommandLink::idCommandLink(
           this: &Give_v,
           cmdName: "Give",
           function: Give_f,
           description: "gives one or more items",
           argCompletion: ArgCompletion_Give);
}


// ========================================================================
// `dynamic initializer for 'GiveAllPlayers_v''
// EA  : 0x8338ED20
// RVA : 0x0138ED20
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__GiveAllPlayers_v__()
{
  return idCommandLink::idCommandLink(
           this: &GiveAllPlayers_v,
           cmdName: "GiveAllPlayers",
           function: GiveAllPlayers_f,
           description: "gives one or more items",
           argCompletion: ArgCompletion_Give);
}


// ========================================================================
// `dynamic initializer for 'KillPlayer_v''
// EA  : 0x8338ED50
// RVA : 0x0138ED50
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__KillPlayer_v__()
{
  return idCommandLink::idCommandLink(
           this: &KillPlayer_v,
           cmdName: "KillPlayer",
           function: KillPlayer_f,
           description: "Kill player",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'g_testParticleName''
// EA  : 0x8338ED78
// RVA : 0x0138ED78
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testParticleName__()
{
  idCVar::idCVar(
    this: &g_testParticleName,
    name: "g_testParticleName",
    value: &byte_8200D768,
    flags: 0,
    description: "particle decl name used for the testParticle command in absence of a name parameter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testParticleName__);
}


// ========================================================================
// `dynamic initializer for 'TestParticle_v''
// EA  : 0x8338EDD0
// RVA : 0x0138EDD0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestParticle_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestParticle_v,
           cmdName: "TestParticle",
           function: TestParticle_f,
           description: "tests a particle impact",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclParticle>);
}


// ========================================================================
// `dynamic initializer for 'StepParticleTime_v''
// EA  : 0x8338EE00
// RVA : 0x0138EE00
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StepParticleTime_v__()
{
  return idCommandLink::idCommandLink(
           this: &StepParticleTime_v,
           cmdName: "StepParticleTime",
           function: StepParticleTime_f,
           description: "modifies a global particle 'timeline' to debug particles in game",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReloadParticles_v''
// EA  : 0x8338EE28
// RVA : 0x0138EE28
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReloadParticles_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReloadParticles_v,
           cmdName: "ReloadParticles",
           function: ReloadParticles_f,
           description: &byte_8200D768,
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'g_testFxName''
// EA  : 0x8338EE50
// RVA : 0x0138EE50
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_testFxName__()
{
  idCVar::idCVar(
    this: &g_testFxName,
    name: "g_testFxName",
    value: &byte_8200D768,
    flags: 0,
    description: "fx decl name used for the testFx command in absence of a name parameter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_testFxName__);
}


// ========================================================================
// `dynamic initializer for 'TestFx_v''
// EA  : 0x8338EEA8
// RVA : 0x0138EEA8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestFx_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestFx_v,
           cmdName: "TestFx",
           function: TestFx_f,
           description: "tests a fx impact",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclFX>);
}


// ========================================================================
// `dynamic initializer for 'StopTestFx_v''
// EA  : 0x8338EED8
// RVA : 0x0138EED8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__StopTestFx_v__()
{
  return idCommandLink::idCommandLink(
           this: &StopTestFx_v,
           cmdName: "StopTestFx",
           function: StopTestFx_f,
           description: "stops the current test fx",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestPlayerViewParticle_v''
// EA  : 0x8338EF00
// RVA : 0x0138EF00
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestPlayerViewParticle_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestPlayerViewParticle_v,
           cmdName: "TestPlayerViewParticle",
           function: TestPlayerViewParticle_f,
           description: "tests a player view particle",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DeleteSelected_v''
// EA  : 0x8338EF28
// RVA : 0x0138EF28
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DeleteSelected_v__()
{
  return idCommandLink::idCommandLink(
           this: &DeleteSelected_v,
           cmdName: "DeleteSelected",
           function: DeleteSelected_f,
           description: "deletes selected entity from the game world, but does not remove it from the map file.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Noclip_v''
// EA  : 0x8338EF50
// RVA : 0x0138EF50
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Noclip_v__()
{
  return idCommandLink::idCommandLink(
           this: &Noclip_v,
           cmdName: "Noclip",
           function: Noclip_f,
           description: "disables collision detection for the player",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'God_v''
// EA  : 0x8338EF78
// RVA : 0x0138EF78
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__God_v__()
{
  return idCommandLink::idCommandLink(
           this: &God_v,
           cmdName: "God",
           function: God_f,
           description: "enables god mode",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'InfiniteHealth_v''
// EA  : 0x8338EFA0
// RVA : 0x0138EFA0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__InfiniteHealth_v__()
{
  return idCommandLink::idCommandLink(
           this: &InfiniteHealth_v,
           cmdName: "InfiniteHealth",
           function: InfiniteHealth_f,
           description: "player experiences damage effects, but never loses health",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'NoPlayerDeath_v''
// EA  : 0x8338EFC8
// RVA : 0x0138EFC8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__NoPlayerDeath_v__()
{
  return idCommandLink::idCommandLink(
           this: &NoPlayerDeath_v,
           cmdName: "NoPlayerDeath",
           function: NoPlayerDeath_f,
           description: "player takes damage and experiences damage effects, but doesn't die",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Notarget_v''
// EA  : 0x8338EFF0
// RVA : 0x0138EFF0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Notarget_v__()
{
  return idCommandLink::idCommandLink(
           this: &Notarget_v,
           cmdName: "Notarget",
           function: Notarget_f,
           description: "disables the player as a target",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Spawn_v''
// EA  : 0x8338F018
// RVA : 0x0138F018
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Spawn_v__()
{
  return idCommandLink::idCommandLink(
           this: &Spawn_v,
           cmdName: "Spawn",
           function: Spawn_f,
           description: "spawns a game entity",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclEntityDef>);
}


// ========================================================================
// `dynamic initializer for 'veh_spawn_distance''
// EA  : 0x8338F048
// RVA : 0x0138F048
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__veh_spawn_distance__()
{
  idCVar::idCVar(
    this: &veh_spawn_distance,
    name: "veh_spawn_distance",
    value: "250",
    flags: 4,
    description: "player never loses god mode",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__veh_spawn_distance__);
}


// ========================================================================
// `dynamic initializer for 'veh_spawn_height''
// EA  : 0x8338F0A0
// RVA : 0x0138F0A0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__veh_spawn_height__()
{
  idCVar::idCVar(
    this: &veh_spawn_height,
    name: "veh_spawn_height",
    value: "50",
    flags: 4,
    description: "player never loses god mode",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__veh_spawn_height__);
}


// ========================================================================
// `dynamic initializer for 'VehSpawn_v''
// EA  : 0x8338F0F8
// RVA : 0x0138F0F8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__VehSpawn_v__()
{
  return idCommandLink::idCommandLink(
           this: &VehSpawn_v,
           cmdName: "VehSpawn",
           function: VehSpawn_f,
           description: "spawns a game entity while you are in a vehicle",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclEntityDef>);
}


// ========================================================================
// `dynamic initializer for 'VehExitForce_v''
// EA  : 0x8338F128
// RVA : 0x0138F128
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__VehExitForce_v__()
{
  return idCommandLink::idCommandLink(
           this: &VehExitForce_v,
           cmdName: "VehExitForce",
           function: VehExitForce_f,
           description: "Forces local player out of vehicle in VDM games",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Remove_v''
// EA  : 0x8338F150
// RVA : 0x0138F150
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Remove_v__()
{
  return idCommandLink::idCommandLink(
           this: &Remove_v,
           cmdName: "Remove",
           function: Remove_f,
           description: "remove a game entity",
           argCompletion: idGameLocal::ArgCompletion_EntityName);
}


// ========================================================================
// `dynamic initializer for 'Hide_v''
// EA  : 0x8338F180
// RVA : 0x0138F180
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Hide_v__()
{
  return idCommandLink::idCommandLink(
           this: &Hide_v,
           cmdName: "Hide",
           function: Hide_f,
           description: "hide a game entity",
           argCompletion: idGameLocal::ArgCompletion_EntityName);
}


// ========================================================================
// `dynamic initializer for 'Show_v''
// EA  : 0x8338F1B0
// RVA : 0x0138F1B0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Show_v__()
{
  return idCommandLink::idCommandLink(
           this: &Show_v,
           cmdName: "Show",
           function: Show_f,
           description: "show a game entity",
           argCompletion: idGameLocal::ArgCompletion_EntityName);
}


// ========================================================================
// `dynamic initializer for 'SetSceneModelFlag_v''
// EA  : 0x8338F1E0
// RVA : 0x0138F1E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SetSceneModelFlag_v__()
{
  return idCommandLink::idCommandLink(
           this: &SetSceneModelFlag_v,
           cmdName: "SetSceneModelFlag",
           function: SetSceneModelFlag_f,
           description: "Sets scenemodel flag on entity",
           argCompletion: idGameLocal::ArgCompletion_EntityName);
}


// ========================================================================
// `dynamic initializer for 'jobComplete_v''
// EA  : 0x8338F210
// RVA : 0x0138F210
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__jobComplete_v__()
{
  return idCommandLink::idCommandLink(
           this: &jobComplete_v,
           cmdName: "jobComplete",
           function: jobComplete_f,
           description: "completes a job and all predecessor jobs",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclJob>);
}


// ========================================================================
// `dynamic initializer for 'jobReadyToTurnIn_v''
// EA  : 0x8338F240
// RVA : 0x0138F240
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__jobReadyToTurnIn_v__()
{
  return idCommandLink::idCommandLink(
           this: &jobReadyToTurnIn_v,
           cmdName: "jobReadyToTurnIn",
           function: jobReadyToTurnIn_f,
           description: "sets a job to the ready to turn in status",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclJob>);
}


// ========================================================================
// `dynamic initializer for 'jobAccept_v''
// EA  : 0x8338F270
// RVA : 0x0138F270
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__jobAccept_v__()
{
  return idCommandLink::idCommandLink(
           this: &jobAccept_v,
           cmdName: "jobAccept",
           function: jobAccept_f,
           description: "accepts the given job and completes all predecessor jobs",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclJob>);
}


// ========================================================================
// `dynamic initializer for 'jobFail_v''
// EA  : 0x8338F2A0
// RVA : 0x0138F2A0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__jobFail_v__()
{
  return idCommandLink::idCommandLink(
           this: &jobFail_v,
           cmdName: "jobFail",
           function: jobFail_f,
           description: "fails the given job.",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclJob>);
}


// ========================================================================
// `dynamic initializer for 'jobGUI_v''
// EA  : 0x8338F2D0
// RVA : 0x0138F2D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__jobGUI_v__()
{
  return idCommandLink::idCommandLink(
           this: &jobGUI_v,
           cmdName: "jobGUI",
           function: jobGUI_f,
           description: "open the job debug GUI.  adds all job decls to the job manager in status NONE",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Hands_Cmd_Hide_v''
// EA  : 0x8338F2F8
// RVA : 0x0138F2F8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Hands_Cmd_Hide_v__()
{
  return idCommandLink::idCommandLink(
           this: &Hands_Cmd_Hide_v,
           cmdName: "Hands_Cmd_Hide",
           function: Hands_Cmd_Hide_f,
           description: "force the player hands to hide.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Hands_Cmd_Show_v''
// EA  : 0x8338F320
// RVA : 0x0138F320
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Hands_Cmd_Show_v__()
{
  return idCommandLink::idCommandLink(
           this: &Hands_Cmd_Show_v,
           cmdName: "Hands_Cmd_Show",
           function: Hands_Cmd_Show_f,
           description: "force the player hands to show.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'test_dlc_rewards_v''
// EA  : 0x8338F348
// RVA : 0x0138F348
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__test_dlc_rewards_v__()
{
  return idCommandLink::idCommandLink(
           this: &test_dlc_rewards_v,
           cmdName: "test_dlc_rewards",
           function: test_dlc_rewards_f,
           description: "Call give dlc rewards on the player",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'playtestGUI_v''
// EA  : 0x8338F370
// RVA : 0x0138F370
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtestGUI_v__()
{
  return idCommandLink::idCommandLink(
           this: &playtestGUI_v,
           cmdName: "playtestGUI",
           function: playtestGUI_f,
           description: "open the playtest debug gui",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'playtest_SaveAndClear_v''
// EA  : 0x8338F398
// RVA : 0x0138F398
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_SaveAndClear_v__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_SaveAndClear_v,
           cmdName: "playtest_SaveAndClear",
           function: playtest_SaveAndClear_f,
           description: "saves the playtest log to a file and clears the data",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'playtest_SaveNoClear_v''
// EA  : 0x8338F3C0
// RVA : 0x0138F3C0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_SaveNoClear_v__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_SaveNoClear_v,
           cmdName: "playtest_SaveNoClear",
           function: playtest_SaveNoClear_f,
           description: "saves the playtest log to a file does not clear the data",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'playtest_DebugDraw_v''
// EA  : 0x8338F3E8
// RVA : 0x0138F3E8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__playtest_DebugDraw_v__()
{
  return idCommandLink::idCommandLink(
           this: &playtest_DebugDraw_v,
           cmdName: "playtest_DebugDraw",
           function: playtest_DebugDraw_f,
           description: "draws the current playtest log info in debug mode, parameter is ms to draw for, 60000 by default",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testMatchParms_v''
// EA  : 0x8338F410
// RVA : 0x0138F410
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testMatchParms_v__()
{
  return idCommandLink::idCommandLink(
           this: &testMatchParms_v,
           cmdName: "testMatchParms",
           function: testMatchParms_f,
           description: "test function for match parms.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testUnlock_v''
// EA  : 0x8338F438
// RVA : 0x0138F438
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testUnlock_v__()
{
  return idCommandLink::idCommandLink(
           this: &testUnlock_v,
           cmdName: "testUnlock",
           function: testUnlock_f,
           description: "test function for vehicle unlocks.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsGive_v''
// EA  : 0x8338F460
// RVA : 0x0138F460
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsGive_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsGive_v,
           cmdName: "achievementsGive",
           function: achievementsGive_f,
           description: "Give an achievement to debug player",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclAchievement>);
}


// ========================================================================
// `dynamic initializer for 'achievementsGiveAll_v''
// EA  : 0x8338F490
// RVA : 0x0138F490
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsGiveAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsGiveAll_v,
           cmdName: "achievementsGiveAll",
           function: achievementsGiveAll_f,
           description: "Give all achievements to debug player",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsSetEndUnlockedState_v''
// EA  : 0x8338F4B8
// RVA : 0x0138F4B8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsSetEndUnlockedState_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsSetEndUnlockedState_v,
           cmdName: "achievementsSetEndUnlockedState",
           function: achievementsSetEndUnlockedState_f,
           description: "Setup the player for the end unlocked state",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsClear_v''
// EA  : 0x8338F4E0
// RVA : 0x0138F4E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsClear_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsClear_v,
           cmdName: "achievementsClear",
           function: achievementsClear_f,
           description: "clears state of an achievement",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclAchievement>);
}


// ========================================================================
// `dynamic initializer for 'achievementsClearAll_v''
// EA  : 0x8338F510
// RVA : 0x0138F510
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsClearAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsClearAll_v,
           cmdName: "achievementsClearAll",
           function: achievementsClearAll_f,
           description: "clears state of all online achievements",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsProgress_v''
// EA  : 0x8338F538
// RVA : 0x0138F538
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsProgress_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsProgress_v,
           cmdName: "achievementsProgress",
           function: achievementsProgress_f,
           description: "shows the progress of all the achievements for the user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsList_v''
// EA  : 0x8338F560
// RVA : 0x0138F560
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsList_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsList_v,
           cmdName: "achievementsList",
           function: achievementsList_f,
           description: "Lists all the online achievements",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsOnlineState_v''
// EA  : 0x8338F588
// RVA : 0x0138F588
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsOnlineState_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsOnlineState_v,
           cmdName: "achievementsOnlineState",
           function: achievementsOnlineState_f,
           description: "Lists all the state of the achievements from their (cached) online source",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsTest_v''
// EA  : 0x8338F5B0
// RVA : 0x0138F5B0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsTest_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsTest_v,
           cmdName: "achievementsTest",
           function: achievementsTest_f,
           description: "This tests all the achievements online to make sure the decls match",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsTestCompletion_v''
// EA  : 0x8338F5D8
// RVA : 0x0138F5D8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsTestCompletion_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsTestCompletion_v,
           cmdName: "achievementsTestCompletion",
           function: achievementsTestCompletion_f,
           description: "This tests which achievements have been marked for completion",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'achievementsTestMismatches_v''
// EA  : 0x8338F600
// RVA : 0x0138F600
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__achievementsTestMismatches_v__()
{
  return idCommandLink::idCommandLink(
           this: &achievementsTestMismatches_v,
           cmdName: "achievementsTestMismatches",
           function: achievementsTestMismatches_f,
           description: "This tests which achievements are out of sync between the server and the profile",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'statsClearAll_v''
// EA  : 0x8338F628
// RVA : 0x0138F628
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__statsClearAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &statsClearAll_v,
           cmdName: "statsClearAll",
           function: statsClearAll_f,
           description: "clears all lifetime stats for the master user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'statsClearGame_v''
// EA  : 0x8338F650
// RVA : 0x0138F650
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__statsClearGame_v__()
{
  return idCommandLink::idCommandLink(
           this: &statsClearGame_v,
           cmdName: "statsClearGame",
           function: statsClearGame_f,
           description: "clears all game stats for the master user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'resetProfile_v''
// EA  : 0x8338F678
// RVA : 0x0138F678
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__resetProfile_v__()
{
  return idCommandLink::idCommandLink(
           this: &resetProfile_v,
           cmdName: "resetProfile",
           function: resetProfile_f,
           description: "clears stats, achievements, and loadouts for the master user",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setStat_v''
// EA  : 0x8338F6A0
// RVA : 0x0138F6A0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setStat_v__()
{
  return idCommandLink::idCommandLink(
           this: &setStat_v,
           cmdName: "setStat",
           function: setStat_f,
           description: "test function for lifetime stats",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setStatGame_v''
// EA  : 0x8338F6C8
// RVA : 0x0138F6C8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setStatGame_v__()
{
  return idCommandLink::idCommandLink(
           this: &setStatGame_v,
           cmdName: "setStatGame",
           function: setStatGame_f,
           description: "test function for game stats",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'giveStat_v''
// EA  : 0x8338F6F0
// RVA : 0x0138F6F0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__giveStat_v__()
{
  return idCommandLink::idCommandLink(
           this: &giveStat_v,
           cmdName: "giveStat",
           function: giveStat_f,
           description: "gives stats that affects game/lifetime values",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'correctOnlineLevel_v''
// EA  : 0x8338F718
// RVA : 0x0138F718
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__correctOnlineLevel_v__()
{
  return idCommandLink::idCommandLink(
           this: &correctOnlineLevel_v,
           cmdName: "correctOnlineLevel",
           function: correctOnlineLevel_f,
           description: "function for setting proper level from user's xp",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineLevel_v''
// EA  : 0x8338F740
// RVA : 0x0138F740
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineLevel_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineLevel_v,
           cmdName: "setOnlineLevel",
           function: setOnlineLevel_f,
           description: "test function for setting online level.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineXP_v''
// EA  : 0x8338F768
// RVA : 0x0138F768
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineXP_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineXP_v,
           cmdName: "setOnlineXP",
           function: setOnlineXP_f,
           description: "test function for setting online xp.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineCash_v''
// EA  : 0x8338F790
// RVA : 0x0138F790
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineCash_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineCash_v,
           cmdName: "setOnlineCash",
           function: setOnlineCash_f,
           description: "test function for setting online cash.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineCoopUnlockAll_v''
// EA  : 0x8338F7B8
// RVA : 0x0138F7B8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineCoopUnlockAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineCoopUnlockAll_v,
           cmdName: "setOnlineCoopUnlockAll",
           function: setOnlineCoopUnlockAll_f,
           description: "This will unlock all coop maps in your player profile",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineCoopUnlock_v''
// EA  : 0x8338F7E0
// RVA : 0x0138F7E0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineCoopUnlock_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineCoopUnlock_v,
           cmdName: "setOnlineCoopUnlock",
           function: setOnlineCoopUnlock_f,
           description: "This will unlock a coop map in your player profile",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineEmblemUnlockAll_v''
// EA  : 0x8338F808
// RVA : 0x0138F808
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineEmblemUnlockAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineEmblemUnlockAll_v,
           cmdName: "setOnlineEmblemUnlockAll",
           function: setOnlineEmblemUnlockAll_f,
           description: "This will unlock all emblems in your player profile",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setOnlineCoopLockAll_v''
// EA  : 0x8338F830
// RVA : 0x0138F830
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setOnlineCoopLockAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &setOnlineCoopLockAll_v,
           cmdName: "setOnlineCoopLockAll",
           function: setOnlineCoopLockAll_f,
           description: "This will reset/lock all coop maps in your player profile to default",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'suicide_v''
// EA  : 0x8338F858
// RVA : 0x0138F858
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__suicide_v__()
{
  return idCommandLink::idCommandLink(
           this: &suicide_v,
           cmdName: "suicide",
           function: suicide_f,
           description: "suicide the player.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'VehDamage_v''
// EA  : 0x8338F880
// RVA : 0x0138F880
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__VehDamage_v__()
{
  return idCommandLink::idCommandLink(
           this: &VehDamage_v,
           cmdName: "VehDamage",
           function: VehDamage_f,
           description: "KillDamage vehicles <amount> <playerNum>",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'VehHealth_v''
// EA  : 0x8338F8A8
// RVA : 0x0138F8A8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__VehHealth_v__()
{
  return idCommandLink::idCommandLink(
           this: &VehHealth_v,
           cmdName: "VehHealth",
           function: VehHealth_f,
           description: "Give vehicles health <amount> <playerNum>",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'changeTeam_v''
// EA  : 0x8338F8D0
// RVA : 0x0138F8D0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__changeTeam_v__()
{
  return idCommandLink::idCommandLink(
           this: &changeTeam_v,
           cmdName: "changeTeam",
           function: changeTeam_f,
           description: "Change teams (Team Games Only).",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setGameChallengeState_v''
// EA  : 0x8338F8F8
// RVA : 0x0138F8F8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setGameChallengeState_v__()
{
  return idCommandLink::idCommandLink(
           this: &setGameChallengeState_v,
           cmdName: "setGameChallengeState",
           function: setGameChallengeState_f,
           description: "Change the current state of the game challange.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ExportPlayerInventoryCosts_v''
// EA  : 0x8338F920
// RVA : 0x0138F920
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ExportPlayerInventoryCosts_v__()
{
  return idCommandLink::idCommandLink(
           this: &ExportPlayerInventoryCosts_v,
           cmdName: "ExportPlayerInventoryCosts",
           function: ExportPlayerInventoryCosts_f,
           description: "exports costs to a csv from the appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ImportPlayerInventoryCosts_v''
// EA  : 0x8338F948
// RVA : 0x0138F948
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ImportPlayerInventoryCosts_v__()
{
  return idCommandLink::idCommandLink(
           this: &ImportPlayerInventoryCosts_v,
           cmdName: "ImportPlayerInventoryCosts",
           function: ImportPlayerInventoryCosts_f,
           description: "imports costs from a csv and writes to appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ExportPlayerWeaponStats_v''
// EA  : 0x8338F970
// RVA : 0x0138F970
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ExportPlayerWeaponStats_v__()
{
  return idCommandLink::idCommandLink(
           this: &ExportPlayerWeaponStats_v,
           cmdName: "ExportPlayerWeaponStats",
           function: ExportPlayerWeaponStats_f,
           description: "exports weapon stats to a csv from the appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ImportPlayerWeaponStats_v''
// EA  : 0x8338F998
// RVA : 0x0138F998
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ImportPlayerWeaponStats_v__()
{
  return idCommandLink::idCommandLink(
           this: &ImportPlayerWeaponStats_v,
           cmdName: "ImportPlayerWeaponStats",
           function: ImportPlayerWeaponStats_f,
           description: "imports weapon stats from a csv and writes to appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ExportPlayerRecipes_v''
// EA  : 0x8338F9C0
// RVA : 0x0138F9C0
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ExportPlayerRecipes_v__()
{
  return idCommandLink::idCommandLink(
           this: &ExportPlayerRecipes_v,
           cmdName: "ExportPlayerRecipes",
           function: ExportPlayerRecipes_f,
           description: "exports recipes to a csv from the appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ImportPlayerRecipes_v''
// EA  : 0x8338F9E8
// RVA : 0x0138F9E8
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ImportPlayerRecipes_v__()
{
  return idCommandLink::idCommandLink(
           this: &ImportPlayerRecipes_v,
           cmdName: "ImportPlayerRecipes",
           function: ImportPlayerRecipes_f,
           description: "imports recipes from a csv and writes to appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ExportPlayerAmmo_v''
// EA  : 0x8338FA10
// RVA : 0x0138FA10
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ExportPlayerAmmo_v__()
{
  return idCommandLink::idCommandLink(
           this: &ExportPlayerAmmo_v,
           cmdName: "ExportPlayerAmmo",
           function: ExportPlayerAmmo_f,
           description: "exports all the ammo types the player can have",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ImportPlayerAmmo_v''
// EA  : 0x8338FA38
// RVA : 0x0138FA38
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ImportPlayerAmmo_v__()
{
  return idCommandLink::idCommandLink(
           this: &ImportPlayerAmmo_v,
           cmdName: "ImportPlayerAmmo",
           function: ImportPlayerAmmo_f,
           description: "imports ammo from a csv and writes to appropriate decls",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ItemsInMap_v''
// EA  : 0x8338FA60
// RVA : 0x0138FA60
// PDB : w:\tech5\tungsten\game\player\player_commands.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ItemsInMap_v__()
{
  return idCommandLink::idCommandLink(
           this: &ItemsInMap_v,
           cmdName: "ItemsInMap",
           function: ItemsInMap_f,
           description: " get the stats from all items in the level ",
           argCompletion: nullptr);
}

