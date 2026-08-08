
// ========================================================================
// ?Cmd_Kill_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6C5C8
// RVA : 0x00D6C5C8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_Kill_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idEventReceiver *v2; // r31
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r6

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
    idEventReceiver::PostEventMS(this: v2, ev: &EV_Kill, time: 0, a4: v5, a5: v4, a6: v3);
}


// ========================================================================
// PrintFloat
// EA  : 0x82D6C638
// RVA : 0x00D6C638
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall PrintFloat(double f)
{
  int v1; // r3
  int v2; // r11
  char *v3; // r10
  int v4; // ctr
  char v5[136]; // [sp+50h] [-90h] BYREF

  v1 = sprintf_0(string: v5, format: "%3.2f", f);
  v2 = v1;
  if ( v1 < 7 )
  {
    v3 = &v5[v1 - 1];
    v4 = 7 - v1;
    do
    {
      *++v3 = 32;
      --v4;
    }
    while ( v4 != 0 );
    v2 = 7;
  }
  v5[v2] = 0;
  idLib::Printf(fmt: v5);
}


// ========================================================================
// Cmd_ListDebugLines_f
// EA  : 0x82D6C6B8
// RVA : 0x00D6C6B8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ListDebugLines_f(const idCmdArgs *args)
{
  int v1; // r30
  idVec3 *p_start; // r31
  int v3; // r3
  int v4; // r11
  char *v5; // r10
  int v6; // ctr
  char v7[192]; // [sp+50h] [-C0h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v1 = 0;
    idLib::Printf(fmt: "line num: x1     y1     z1     x2     y2     z2     c  b  a\n");
    p_start = &debugLines[0].start;
    do
    {
      if ( HIBYTE(p_start[-1].z) != 0 )
      {
        idLib::Printf(fmt: "line %3d: ", v1);
        v3 = sprintf_0(string: v7, format: "%3.2f", p_start->x);
        v4 = v3;
        if ( v3 < 7 )
        {
          v5 = &v7[v3 - 1];
          v6 = 7 - v3;
          do
          {
            *++v5 = 32;
            --v6;
          }
          while ( v6 != 0 );
          v4 = 7;
        }
        v7[v4] = 0;
        idLib::Printf(fmt: v7);
        PrintFloat(f: p_start->y);
        PrintFloat(f: p_start->z);
        PrintFloat(f: p_start[1].x);
        PrintFloat(f: p_start[1].y);
        PrintFloat(f: p_start[1].z);
        idLib::Printf(fmt: "%d  %d  %d\n", p_start[2].x, HIBYTE(p_start[2].y), BYTE1(p_start[2].y));
        ++v1;
      }
      p_start += 3;
    }
    while ( (int)p_start < (int)&yawToVector_v.cmdName_ );
    if ( v1 == 0 )
      idLib::Printf(fmt: "no debug lines\n");
  }
}


// ========================================================================
// Cmd_AASStats_f
// EA  : 0x82D6C800
// RVA : 0x00D6C800
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_AASStats_f(const idCmdArgs *args)
{
  int v1; // r29
  int v2; // r31
  idAAS2 *AAS; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v1 = 0;
    v2 = 0;
    if ( idGameLocal::NumAAS(this: gameLocal) <= 0 )
      goto LABEL_7;
    do
    {
      AAS = idGameLocal::GetAAS(this: gameLocal, idx: v2);
      if ( AAS != nullptr )
      {
        AAS->Stats(this: AAS);
        ++v1;
      }
      ++v2;
    }
    while ( v2 < idGameLocal::NumAAS(this: gameLocal) );
    if ( v1 == 0 )
LABEL_7:
      idLib::Printf(fmt: "no AAS loaded\n");
  }
}


// ========================================================================
// Cmd_GameError_f
// EA  : 0x82D6C898
// RVA : 0x00D6C898
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_GameError_f(const idCmdArgs *args)
{
  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
    idLib::Error(fmt: "game error");
}


// ========================================================================
// Cmd_DisasmScript_f
// EA  : 0x82D6C8E0
// RVA : 0x00D6C8E0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_DisasmScript_f(const idCmdArgs *args)
{
  idProgram::Disassemble(this: &gameLocal->program);
}


// ========================================================================
// Cmd_TakeViewNotes_f
// EA  : 0x82D6C8F8
// RVA : 0x00D6C8F8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_TakeViewNotes_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r31

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "g_showHud", a3: false, a4: 0);
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_drawWarnings", a3: false, a4: 0);
    idPlayer::TakeViewNotes(this: DebugPlayer);
  }
}


// ========================================================================
// ?Cmd_PrintVOLog_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6C990
// RVA : 0x00D6C990
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// attributes: thunk
void __fastcall Cmd_PrintVOLog_f(const idCmdArgs *args)
{
  idAIVoiceController::PrintLog();
}


// ========================================================================
// ?EntityReferencesClipModel@@YA_NPBVidEntity@@PBVidClipModel@@@Z
// EA  : 0x82D6C998
// RVA : 0x00D6C998
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

int __fastcall EntityReferencesClipModel(idEntity *ent, const idClipModel *clipModel)
{
  idPhysics *Physics; // r31
  int v4; // r30

  if ( ent == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: ent);
  v4 = 0;
  if ( Physics->GetNumClipModels(this: Physics) <= 0 )
    return 0;
  while ( Physics->GetClipModel(this: Physics, a2: v4) != clipModel )
  {
    if ( ++v4 >= Physics->GetNumClipModels(this: Physics) )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?clipStats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6CA30
// RVA : 0x00D6CA30
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall clipStats_f(const idCmdArgs *args)
{
  idClip::PrintStatistics(this: &clientGame->clip);
}


// ========================================================================
// ?ArgCompletion_CSV@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82D6CA40
// RVA : 0x00D6CA40
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall ArgCompletion_CSV(idAutoComplete *autoComplete)
{
  cmdSystem->ArgCompletion_FolderExtension(
    this: cmdSystem,
    a2: autoComplete,
    a3: "intermediate/;decls/",
    a4: ".csv",
    a5: false);
}


// ========================================================================
// ?Cmd_EntityList_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6CA78
// RVA : 0x00D6CA78
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_EntityList_f(const idCmdArgs *args)
{
  int v1; // r27
  const char *v2; // r3
  int v3; // r26
  int i; // r25
  int v5; // r30
  int v6; // r11
  const char *v7; // r29
  const char *v8; // r28
  const char *Classname; // r3
  idStr v10[4]; // [sp+50h] [-80h] BYREF

  v1 = 0;
  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  if ( args->argc <= 1 )
  {
    idStr::operator=(this: v10, text: &byte_8200D768);
  }
  else
  {
    v2 = idCmdArgs::Args(this: args, start: 1, end: -1, quoteArgs: false, escapeArgs: false);
    idStr::operator=(this: v10, text: v2);
    idStr::Replace(this: v10, old: " ", nw: &byte_8200D768);
  }
  idStr::Replace(this: v10, old: "*", nw: &byte_8200D768);
  v3 = 0;
  idLib::Printf(fmt: "%-4s  %-20s %-20s %s\n", " Num", "EntityDef", "Class", "Name");
  idLib::Printf(fmt: "--------------------------------------------------------------------\n");
  for ( i = 86252; i < 119020; i += 4 )
  {
    v5 = *(int *)((char *)&gameLocal->__vftable + i);
    if ( v5 != 0
      && (v10[0].len <= 0
       || idStr::Find(
            searchIn: *(const char **)(v5 + 16),
            searchFor: v10[0].data,
            casesensitive: true,
            start: 0,
            end: -1) != -1) )
    {
      v6 = *(_DWORD *)(v5 + 496);
      v7 = "*unknown*";
      v8 = *(const char **)(v5 + 16);
      if ( v6 != 0 )
        v7 = *(const char **)(v6 + 8);
      Classname = idClass::GetClassname(this: (idClass *)v5);
      idLib::Printf(fmt: "%4i: %-20s %-20s %s\n", v1, v7, Classname, v8);
      ++v3;
    }
    ++v1;
  }
  idLib::Printf(fmt: "%d entities", v3);
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$492751
// EA  : 0x82D6CC20
// RVA : 0x00D6CC20
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_492751()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?Cmd_ActiveEntityList_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6CC48
// RVA : 0x00D6CC48
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ActiveEntityList_f(const idCmdArgs *args)
{
  int v1; // r25
  int v2; // r24
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r31
  char v5; // r26
  idPhysics *Physics; // r3
  const char *v7; // r27
  const idDeclEntityDef *entityDef; // r11
  const char *str; // r30
  int numPVSAreas; // r29
  const char *data; // r28
  int entityNumber; // r19
  const char *Classname; // r3
  idLinkList<idEntity> *v14; // r11

  v1 = 0;
  v2 = 0;
  idLib::Printf(fmt: "%-4s  %-20s %-20s %s\n", " Num", "EntityDef", "Class", "Name");
  idLib::Printf(fmt: "--------------------------------------------------------------------\n");
  next = gameLocal->activeEntities.next;
  if ( next != nullptr && next != gameLocal->activeEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v14->owner )
    {
      v5 = (*((_BYTE *)&i->flags + 1) & 0x80) == 0 ? 32 : 45;
      Physics = idEntity::GetPhysics(this: i);
      v7 = "non-resident";
      if ( !Physics->IsInNonResidentCollisionArea(this: Physics, a2: false) )
        v7 = "resident";
      entityDef = i->entityDef;
      str = "*unknown*";
      numPVSAreas = i->numPVSAreas;
      data = i->name.data;
      if ( entityDef != nullptr )
        str = entityDef->name.str;
      entityNumber = i->entityNumber;
      Classname = idClass::GetClassname(this: i);
      idLib::Printf(
        fmt: "%4i:%c%-20s %-20s %s (%d PVS areas, collision %s)\n",
        entityNumber,
        v5,
        str,
        Classname,
        data,
        numPVSAreas,
        v7);
      v14 = i->activeNode.next;
      ++v1;
      v2 += *((unsigned __int8 *)&i->flags + 1) >> 7;
      if ( v14 == nullptr )
        break;
      if ( v14 == i->activeNode.head )
        break;
    }
  }
  idLib::Printf(fmt: "...%d active entities of which %d dormant\n", v1, v2);
}


// ========================================================================
// ?Cmd_listActiveLayers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6CDD0
// RVA : 0x00D6CDD0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_listActiveLayers_f(const idCmdArgs *args)
{
  idGameLocal *v1; // r11
  int v2; // r31
  int num; // r4
  int v4; // r30
  idGameLocal *v5; // r11
  int v6; // r31
  int v7; // r4
  int v8; // r30

  v1 = gameLocal;
  v2 = 0;
  num = gameLocal->gameSpawnInfo.layersDeactive.num;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      idLib::Printf(fmt: "\t%s\n", v1->gameSpawnInfo.layersDeactive.list[v4].data);
      v1 = gameLocal;
      ++v2;
      ++v4;
      num = gameLocal->gameSpawnInfo.layersDeactive.num;
    }
    while ( v2 < num );
  }
  idLib::Warning(fmt: "...%d deactive layers", num);
  v5 = gameLocal;
  v6 = 0;
  v7 = gameLocal->gameSpawnInfo.layersActive.num;
  if ( v7 > 0 )
  {
    v8 = 0;
    do
    {
      idLib::Printf(fmt: "\t%s\n", v5->gameSpawnInfo.layersActive.list[v8].data);
      v5 = gameLocal;
      ++v6;
      ++v8;
      v7 = gameLocal->gameSpawnInfo.layersActive.num;
    }
    while ( v6 < v7 );
  }
  idLib::Warning(fmt: "...%d active layers", v7);
}


// ========================================================================
// ?KillEntities@@YAXABVidCmdArgs@@ABVidTypeInfo@@@Z
// EA  : 0x82D6CEA8
// RVA : 0x00D6CEA8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall KillEntities(const idCmdArgs *args, const idTypeInfo *superClass)
{
  idLinkList<idEntity> *next; // r11
  idEventReceiver *i; // r31
  int v6; // r11
  char v7; // r11
  bool v8; // zf
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r6
  int v12; // r11
  idList<idEventReceiver *,5> *listeningToList; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = next->owner; i != nullptr; i = *(idEventReceiver **)&listeningToList->granularity )
      {
        v6 = *(_DWORD *)(i->GetType(this: i) + 36);
        if ( v6 < superClass->typeNum || (v8 = v6 <= superClass->lastChild, v7 = 1, !v8) )
          v7 = 0;
        if ( v7 != 0 && (unsigned __int8)idPlayer::IsTypeOf(c: i) == 0 )
        {
          LODWORD(v10) = args->argc;
          v12 = 1;
          if ( args->argc > 1 )
          {
            HIDWORD(v10) = i[1].listenerList;
            HIDWORD(v9) = &args->argv[1];
            do
            {
              if ( v12 < 0 || v12 >= (int)v10 )
                LODWORD(v9) = &byte_8200D768;
              else
                LODWORD(v9) = *(_DWORD *)HIDWORD(v9);
              if ( HIDWORD(v10) == (_DWORD)v9 )
                break;
              ++v12;
              HIDWORD(v9) += 4;
            }
            while ( v12 < (int)v10 );
          }
          if ( v12 >= (int)v10 )
            idEventReceiver::PostEventMS(this: i, ev: &EV_Remove, time: 0, a4: v11, a5: v10, a6: v9);
        }
        listeningToList = i[62].listeningToList;
        if ( listeningToList == nullptr )
          break;
        if ( listeningToList == i[62].listenerList )
          break;
      }
    }
  }
}


// ========================================================================
// ?Cmd_KillMonsters_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D000
// RVA : 0x00D6D000
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillMonsters_f(const idCmdArgs *args)
{
  KillEntities(args, superClass: &idAI2::Type);
  KillEntities(args, superClass: &idVehicleAI::Type);
}


// ========================================================================
// ?Cmd_KillMovables_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D048
// RVA : 0x00D6D048
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillMovables_f(const idCmdArgs *args)
{
  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
    KillEntities(args, superClass: &idProp_Moveable::Type);
}


// ========================================================================
// ?Cmd_KillRagdolls_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D0A0
// RVA : 0x00D6D0A0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillRagdolls_f(const idCmdArgs *args)
{
  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
    KillEntities(args, superClass: &idAFEntity_Generic::Type);
}


// ========================================================================
// ?Cmd_GetViewpos_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D100
// RVA : 0x00D6D100
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_GetViewpos_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPresentable *presentable; // r3
  int v3; // r3
  double v4; // fp31
  double v5; // fp30
  const char *v6; // r3
  idAngles *v7; // r3
  idVec3 v8; // [sp+50h] [-90h] BYREF
  idMat3 v9; // [sp+60h] [-80h] BYREF
  idMat3 v10; // [sp+90h] [-50h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v3 = 0;
    idView::GetViewPos(this: (idView *)(v3 + 16224), origin: &v8, axis: &v10);
    v9.mat[1].y = 0.0;
    LODWORD(v9.mat[2].x) = 20;
    LODWORD(v9.mat[1].z) = &v9.mat[2].y;
    HIBYTE(v9.mat[2].y) = 0;
    v4 = idVec3::ToPitch(this: v10.mat);
    v5 = idVec3::ToYaw(this: v10.mat);
    v6 = idVec3::ToString(this: (idAngles *)&v8, precision: 2);
    idStr::Format(this: (idStr *)&v9.mat[1].y, fmt: "x y z yaw pitch\n%s %.1f %.1f\n", v6, v5, v4);
    idLib::Printf(fmt: (const char *)LODWORD(v9.mat[1].z));
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)LODWORD(v9.mat[1].z));
    lastViewOrigin_0.x = v8.x;
    lastViewOrigin_0.y = v8.y;
    lastViewOrigin_0.z = v8.z;
    v7 = idMat3::ToAngles(this: &v9, result: (idAngles *)&v10);
    lastViewAngles.pitch = v7->pitch;
    lastViewAngles.yaw = v7->yaw;
    lastViewAngles.roll = v7->roll;
    idStr::FreeData(this: (idStr *)&v9.mat[1].y);
  }
}


// ========================================================================
// __unwind$493149
// EA  : 0x82D6D258
// RVA : 0x00D6D258
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_493149()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?Cmd_SetViewpos_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D280
// RVA : 0x00D6D280
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Cmd_SetViewpos_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idEventReceiver *v3; // r25
  double x; // fp30
  double pitch; // fp29
  double y; // fp31
  double z; // fp13
  double yaw; // fp28
  long double v9; // fp2
  const char *v10; // r3
  long double v11; // fp2
  int v12; // r31
  float *v13; // r28
  const char **v14; // r29
  int i; // r30
  const char *v16; // r3
  long double v17; // fp2
  double v18; // fp26
  __int128 v19; // r7 OVERLAPPED
  int v20; // r8
  __int64 v21; // [sp+8h] [-118h]
  __int64 v22; // [sp+10h] [-110h]
  __int64 v23; // [sp+18h] [-108h]
  __int64 v24; // [sp+20h] [-100h]
  __int64 v25; // [sp+28h] [-F8h]
  __int64 v26; // [sp+30h] [-F0h]
  __int64 v27; // [sp+38h] [-E8h]
  __int64 v28; // [sp+40h] [-E0h]
  __int64 v29; // [sp+48h] [-D8h]
  __int64 v30; // [sp+50h] [-D0h]
  __int64 v31; // [sp+58h] [-C8h]
  int v32; // [sp+6Ch] [-B4h] BYREF
  float v33; // [sp+70h] [-B0h]
  float v34; // [sp+74h] [-ACh]
  __int64 v35; // [sp+78h] [-A8h]
  int v36; // [sp+80h] [-A0h]
  int v37; // [sp+90h] [-90h]
  float v38; // [sp+94h] [-8Ch]
  float v39; // [sp+98h] [-88h]
  float v40; // [sp+9Ch] [-84h]

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    if ( args->argc != 2 || idStr::Icmp(s1: args->argv[1], s2: "last") != 0 )
    {
      if ( args->argc < 4 )
      {
        idLib::Printf(fmt: "usage: setviewpos <x> <y> <z> [yaw] [pitch] or [last]\n");
        return;
      }
      yaw = 0.0;
      pitch = 0.0;
      if ( args->argc >= 5 )
      {
        v9 = atof(nptr: args->argv[4]);
        yaw = (float)*(double *)&v9;
      }
      if ( args->argc >= 6 )
      {
        if ( args->argc <= 5 )
          v10 = &byte_8200D768;
        else
          v10 = args->argv[5];
        v11 = atof(nptr: v10);
        pitch = (float)*(double *)&v11;
      }
      v12 = 1;
      v13 = (float *)&v32;
      v14 = (const char **)&args->argv[1];
      for ( i = 3; i != 0; --i )
      {
        if ( v12 < 0 || v12 >= args->argc )
          v16 = &byte_8200D768;
        else
          v16 = *v14;
        v17 = atof(nptr: v16);
        *++v13 = *(double *)&v17;
        ++v12;
        ++v14;
      }
      z = *(float *)&v35;
      y = v34;
      x = v33;
    }
    else
    {
      x = lastViewOrigin_0.x;
      pitch = lastViewAngles.pitch;
      y = lastViewOrigin_0.y;
      z = lastViewOrigin_0.z;
      yaw = lastViewAngles.yaw;
    }
    v18 = (float)((float)z - (float)(pm_normalviewheight.valueFloat - (float)0.25));
    usercmdGen->ClearAngles(this: usercmdGen);
    v34 = x;
    *(float *)&v35 = y;
    *((float *)&v35 + 1) = v18;
    HIBYTE(v33) = 118;
    v38 = pitch;
    v39 = yaw;
    HIBYTE(v37) = 97;
    v40 = 0.0;
    *((float *)&v19 + 1) = v33;
    *((_QWORD *)&v19 + 1) = v35;
    v20 = __ROL4__(v36, 32);
    idEventReceiver::PostEventMS(
      this: v3,
      ev: &EV_Teleport,
      arg1: *(__int64 *)((char *)&v19 + 4),
      arg2: *(__int64 *)((char *)&v19 - 4),
      a5: *(_QWORD *)(v37 + 8),
      a6: v21,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26,
      a12: v27,
      a13: v28,
      a14: v29,
      a15: v30,
      a16: v31);
  }
}


// ========================================================================
// ?Cmd_CenterView_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D4A8
// RVA : 0x00D6D4A8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_CenterView_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r30
  idPresentable *presentable; // r3
  const idAngles *v5; // r4
  bool v6; // zf
  long double v7; // fp2
  idAngles v8[4]; // [sp+50h] [-30h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v5 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = nullptr;
    idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v8, result: v5, includeWeaponKick: true);
    v6 = args->argc != 2;
    v8[0].pitch = 0.0;
    if ( !v6 )
    {
      v7 = atof(nptr: args->argv[1]);
      v8[0].yaw = *(double *)&v7;
    }
    idPlayer::SetViewAngles(this: v3, angles: v8, force: false);
  }
}


// ========================================================================
// ?Cmd_Teleport_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D560
// RVA : 0x00D6D560
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_Teleport_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r30
  idEntity *v4; // r3
  idEntity *v5; // r31
  idPhysics *Physics; // r3
  idVec3 *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  float v10; // [sp+50h] [-40h] BYREF
  float v11; // [sp+54h] [-3Ch]
  float v12; // [sp+58h] [-38h]
  float v13[12]; // [sp+60h] [-30h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    if ( args->argc == 2 )
    {
      v4 = gameLocal->FindEntity(this: gameLocal, a2: args->argv[1]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v12 = 0.0;
        v11 = 0.0;
        v10 = 0.0;
        Physics = idEntity::GetPhysics(this: v4);
        v7 = (idVec3 *)Physics->GetAxis(this: Physics, a2: 0);
        v11 = idVec3::ToYaw(this: v7);
        v8 = idEntity::GetPhysics(this: v5);
        v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
        v13[0] = *v9;
        v13[1] = v9[1];
        v13[2] = v9[2];
        v3->Teleport(this: v3, a2: (const idVec3 *)v13, a3: (const idAngles *)&v10);
      }
      else
      {
        idLib::Printf(fmt: "entity not found\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "usage: teleport <name of entity to teleport to>\n");
    }
  }
}


// ========================================================================
// ?Cmd_Trigger_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D690
// RVA : 0x00D6D690
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_Trigger_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idEntity *v3; // r30
  idEntity *v4; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    if ( args->argc == 2 )
    {
      v4 = gameLocal->FindEntity(this: gameLocal, a2: args->argv[1]);
      if ( v4 != nullptr )
        idEntity::Activate(this: v4, activator: v3);
      else
        idLib::Printf(fmt: "entity not found\n");
    }
    else
    {
      idLib::Printf(fmt: "usage: trigger <name of entity to trigger>\n");
    }
  }
}


// ========================================================================
// ?Cmd_PopLight_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D738
// RVA : 0x00D6D738
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_PopLight_f(const idCmdArgs *args)
{
  idMapFile *v2; // r27
  idLight *v3; // r28
  int v4; // r29
  idLinkList<idEntity> *next; // r11
  char v6; // r26
  idLight *owner; // r31
  int v8; // r10
  idLinkList<idEntity> *v9; // r11
  idMapEntity *Entity; // r4
  idRenderLight *renderLight; // r3
  unsigned int Index; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v2 = gameLocal->GetLevelMap(this: gameLocal);
    v3 = nullptr;
    v4 = -1;
    next = gameLocal->spawnedEntities.next;
    v6 = ((args->argc >= 0) + (args->argc <= 1u)) & 1;
    if ( next == nullptr )
      goto LABEL_20;
    if ( next == gameLocal->spawnedEntities.head )
      goto LABEL_20;
    owner = (idLight *)next->owner;
    if ( owner == nullptr )
      goto LABEL_20;
    do
    {
      if ( (unsigned __int8)idLight::IsTypeOf(c: owner) != 0 )
      {
        v8 = owner->entityNumber + 29755;
        if ( *((_DWORD *)&gameLocal->__vftable + v8) > v4 )
        {
          v4 = *((_DWORD *)&gameLocal->__vftable + v8);
          v3 = idLight::CastTo(c: owner);
        }
      }
      v9 = owner->spawnNode.next;
      if ( v9 == nullptr )
        break;
      if ( v9 == owner->spawnNode.head )
        break;
      owner = (idLight *)v9->owner;
    }
    while ( owner != nullptr );
    if ( v3 != nullptr )
    {
      Entity = nullptr;
      if ( v2 != nullptr )
        Entity = idMapFile::FindEntity(this: v2, name: v3->name.data, index: nullptr);
      if ( v6 != 0 && Entity != nullptr )
        idMapFile::RemoveEntity(this: v2, mapEnt: Entity);
      renderLight = v3->renderLight;
      if ( renderLight != nullptr )
      {
        Index = idRenderLight::GetIndex(this: renderLight);
        idLib::Printf(fmt: "Removing light %i\n", Index);
      }
      ((void (__fastcall *)(idLight *, int))v3->dtr_idClass)(a1: v3, a2: 1);
    }
    else
    {
LABEL_20:
      idLib::Printf(fmt: "No lights to clear.\n");
    }
  }
}


// ========================================================================
// ?Cmd_ClearLights_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6D8D0
// RVA : 0x00D6D8D0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ClearLights_f(const idCmdArgs *args)
{
  idMapFile *v2; // r3
  int v3; // r7
  int v4; // r6
  BOOL v5; // r4
  idMapFile *v6; // r30
  char v7; // r11
  char v8; // r28
  idLinkList<idEntity> *next; // r11
  idLight *owner; // r31
  idLinkList<idEntity> *v11; // r11
  idLight *v12; // r29
  idLight *v13; // r3
  idLight *v14; // r31
  idMapEntity *Entity; // r4

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v2 = gameLocal->GetLevelMap(this: gameLocal);
    v3 = 1 - args->argc;
    v4 = ~(args->argc ^ 1);
    v5 = args->argc >= 0;
    v7 = v5 + (args->argc <= 1u);
    v6 = v2;
    v8 = v7 & 1;
    idLib::Printf(fmt: "Clearing all lights.\n", v5, "Clearing all lights.\n", v4, v3);
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      owner = (idLight *)next->owner;
      if ( owner != nullptr )
      {
        do
        {
          v11 = owner->spawnNode.next;
          if ( v11 == nullptr || v11 == owner->spawnNode.head )
            v12 = nullptr;
          else
            v12 = (idLight *)v11->owner;
          if ( (unsigned __int8)idLight::IsTypeOf(c: owner) != 0 )
          {
            v13 = idLight::CastTo(c: owner);
            v14 = v13;
            Entity = nullptr;
            if ( v6 != nullptr )
              Entity = idMapFile::FindEntity(this: v6, name: v13->name.data, index: nullptr);
            if ( v8 != 0 && Entity != nullptr )
              idMapFile::RemoveEntity(this: v6, mapEnt: Entity);
            if ( v14 != nullptr )
              ((void (__fastcall *)(idLight *, int))v14->dtr_idClass)(a1: v14, a2: 1);
          }
          owner = v12;
        }
        while ( v12 != nullptr );
      }
    }
  }
}


// ========================================================================
// Cmd_AddDebugLine_f
// EA  : 0x82D6DA28
// RVA : 0x00D6DA28
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_AddDebugLine_f(const idCmdArgs *args)
{
  int v2; // r31
  gameDebugLine_t *v3; // r11
  const char *v4; // r3
  int v5; // r31
  const char *v6; // r3
  long double v7; // fp2
  const char *v8; // r3
  long double v9; // fp2
  const char *v10; // r3
  long double v11; // fp2
  const char *v12; // r3
  long double v13; // fp2
  const char *v14; // r3
  long double v15; // fp2
  const char *v16; // r3
  long double v17; // fp2
  const char *v18; // r3
  long double v19; // fp2

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 7 )
    {
      v2 = 0;
      v3 = &debugLines[1];
      while ( v3[-1].used )
      {
        if ( !v3->used )
        {
          ++v2;
          break;
        }
        if ( !v3[1].used )
        {
          v2 += 2;
          break;
        }
        if ( !v3[2].used )
        {
          v2 += 3;
          break;
        }
        v3 += 4;
        v2 += 4;
        if ( (int)v3 >= (int)&setDebugEntity_v.argCompletion_ )
          goto LABEL_10;
      }
      if ( v2 >= 128 )
      {
LABEL_10:
        idLib::Printf(fmt: "no free debug lines\n");
        return;
      }
      if ( args->argc <= 0 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[0];
      v5 = v2;
      debugLines[v5].arrow = idStr::Icmp(s1: v4, s2: "addarrow") == 0;
      debugLines[v5].used = true;
      debugLines[v5].blink = false;
      if ( args->argc <= 1 )
        v6 = &byte_8200D768;
      else
        v6 = args->argv[1];
      v7 = atof(nptr: v6);
      debugLines[v5].start.x = *(double *)&v7;
      if ( args->argc <= 2 )
        v8 = &byte_8200D768;
      else
        v8 = args->argv[2];
      v9 = atof(nptr: v8);
      debugLines[v5].start.y = *(double *)&v9;
      if ( args->argc <= 3 )
        v10 = &byte_8200D768;
      else
        v10 = args->argv[3];
      v11 = atof(nptr: v10);
      debugLines[v5].start.z = *(double *)&v11;
      if ( args->argc <= 4 )
        v12 = &byte_8200D768;
      else
        v12 = args->argv[4];
      v13 = atof(nptr: v12);
      debugLines[v5].end.x = *(double *)&v13;
      if ( args->argc <= 5 )
        v14 = &byte_8200D768;
      else
        v14 = args->argv[5];
      v15 = atof(nptr: v14);
      debugLines[v5].end.y = *(double *)&v15;
      if ( args->argc <= 6 )
        v16 = &byte_8200D768;
      else
        v16 = args->argv[6];
      v17 = atof(nptr: v16);
      debugLines[v5].end.z = *(double *)&v17;
      if ( args->argc <= 7 )
        v18 = &byte_8200D768;
      else
        v18 = args->argv[7];
      v19 = atof(nptr: v18);
      debugLines[v5].color = (int)(float)*(double *)&v19;
    }
    else
    {
      idLib::Printf(fmt: "usage: addline <x y z> <x y z> <color>\n");
    }
  }
}


// ========================================================================
// Cmd_RemoveDebugLine_f
// EA  : 0x82D6DC90
// RVA : 0x00D6DC90
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_RemoveDebugLine_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  int v4; // r10
  gameDebugLine_t *v5; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 2 )
    {
      if ( args->argc <= 1 )
        v2 = &byte_8200D768;
      else
        v2 = args->argv[1];
      v3 = atol(nptr: v2);
      v4 = 0;
      v5 = &debugLines[1];
      while ( !v5[-1].used || --v3 >= 0 )
      {
        if ( v5->used && --v3 < 0 )
        {
          ++v4;
          break;
        }
        if ( v5[1].used && --v3 < 0 )
        {
          v4 += 2;
          break;
        }
        if ( v5[2].used && --v3 < 0 )
        {
          v4 += 3;
          break;
        }
        v5 += 4;
        v4 += 4;
        if ( (int)v5 >= (int)&setDebugEntity_v.argCompletion_ )
          goto LABEL_17;
      }
      if ( v4 >= 128 )
      {
LABEL_17:
        idLib::Printf(fmt: "line not found\n");
        return;
      }
      debugLines[v4].used = false;
    }
    else
    {
      idLib::Printf(fmt: "usage: removeline <num>\n");
    }
  }
}


// ========================================================================
// Cmd_BlinkDebugLine_f
// EA  : 0x82D6DE00
// RVA : 0x00D6DE00
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_BlinkDebugLine_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r3
  int v4; // r10
  gameDebugLine_t *v5; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 2 )
    {
      if ( args->argc <= 1 )
        v2 = &byte_8200D768;
      else
        v2 = args->argv[1];
      v3 = atol(nptr: v2);
      v4 = 0;
      v5 = &debugLines[1];
      while ( !v5[-1].used || --v3 >= 0 )
      {
        if ( v5->used && --v3 < 0 )
        {
          ++v4;
          break;
        }
        if ( v5[1].used && --v3 < 0 )
        {
          v4 += 2;
          break;
        }
        if ( v5[2].used && --v3 < 0 )
        {
          v4 += 3;
          break;
        }
        v5 += 4;
        v4 += 4;
        if ( (int)v5 >= (int)&setDebugEntity_v.argCompletion_ )
          goto LABEL_17;
      }
      if ( v4 >= 128 )
      {
LABEL_17:
        idLib::Printf(fmt: "line not found\n");
        return;
      }
      debugLines[v4].blink = (_cntlzw(debugLines[v4].blink) & 0x20) != 0;
    }
    else
    {
      idLib::Printf(fmt: "usage: blinkline <num>\n");
    }
  }
}


// ========================================================================
// ?DrawDebugLines@@YAXXZ
// EA  : 0x82D6DF80
// RVA : 0x00D6DF80
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DrawDebugLines(__int64 a1)
{
  float *p_y; // r31
  int v2; // r10
  float *v3; // r30
  __int64 v4; // r10
  int v5; // r5
  float *v6; // r28
  double v7; // fp30
  double v8; // fp13
  double v9; // fp29
  double v10; // fp11
  double v11; // fp28
  double v12; // fp6
  double v15; // fp2
  double v16; // fp5
  double v17; // fp3
  double v18; // fp2
  double v19; // fp26
  double v20; // fp25
  double v21; // fp24
  double v22; // fp31
  float v23[4]; // [sp+68h] [-118h] BYREF
  float v24[4]; // [sp+78h] [-108h] BYREF
  idVec3 v25; // [sp+88h] [-F8h] BYREF
  idVec3 v26; // [sp+98h] [-E8h] BYREF
  idVec3 v27[2]; // [sp+A8h] [-D8h] BYREF
  float v28[32]; // [sp+C0h] [-C0h] BYREF

  p_y = &debugLines[0].end.y;
  do
  {
    if ( *((_BYTE *)p_y - 20) != 0 )
    {
      if ( *((_BYTE *)p_y + 12) == 0
        || (HIDWORD(a1) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
            (a1 & 0x20000000000LL) != 0) )
      {
        v2 = *((_DWORD *)p_y + 2);
        v3 = p_y - 1;
        HIDWORD(v4) = v2 >> 1;
        LODWORD(a1) = (v2 >> 2) & 1;
        v5 = (v2 >> 1) & 1;
        LODWORD(v4) = v2 & 1;
        v28[3] = 1.0;
        v6 = p_y - 4;
        v28[1] = (float)*(__int64 *)((char *)&a1 - 4);
        v28[0] = (float)v4;
        v28[2] = (float)a1;
        HIDWORD(a1) = ((int (__fastcall *)(idRenderWorld *, float *, float *, float *, _DWORD, _DWORD))clientGame->renderWorld->DebugLine)(
                        a1: clientGame->renderWorld,
                        a2: v28,
                        a3: p_y - 4,
                        a4: p_y - 1,
                        a5: 0,
                        a6: 0);
        if ( *((_BYTE *)p_y + 13) != 0 )
        {
          v7 = *p_y;
          v8 = (float)(*p_y - *(p_y - 3));
          v9 = p_y[1];
          v10 = (float)(p_y[1] - *(p_y - 2));
          v11 = *v3;
          v12 = (float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6))
                      + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)));
          _FP5 = (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6))
                               + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f3, f5, f6, f0 }
          v15 = __frsqrte(_FP3);
          v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15)
                                                      * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6))
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v8 * (float)v8)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v15
                                                              * (float)((float)((float)((float)(*v3 - *v6)
                                                                                      * (float)(*v3 - *v6))
                                                                              + (float)((float)((float)v10 * (float)v10)
                                                                                      + (float)((float)v8 * (float)v8)))
                                                                      * (float)0.5))
                                                      * (float)v15)
                                              - (float)1.5)
                              * (float)v15));
          v17 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15)
                                                                                      * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6))
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5);
          v18 = (float)((float)v17
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15)
                                                              * (float)((float)((float)((float)(*v3 - *v6)
                                                                                      * (float)(*v3 - *v6))
                                                                              + (float)((float)((float)v10 * (float)v10)
                                                                                      + (float)((float)v8 * (float)v8)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)(*v3 - *v6) * (float)(*v3 - *v6)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v8 * (float)v8))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v15
                                                                      * (float)((float)((float)((float)(*v3 - *v6)
                                                                                              * (float)(*v3 - *v6))
                                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                                              + (float)((float)v8 * (float)v8)))
                                                                              * (float)0.5))
                                                              * (float)v15)
                                                      - (float)1.5)
                                      * (float)v15)));
          v19 = (float)((float)v18 * (float)(*v3 - *v6));
          v20 = (float)((float)(*p_y - *(p_y - 3)) * (float)v18);
          v25.x = (float)v18 * (float)(*v3 - *v6);
          v25.y = v20;
          v21 = (float)((float)v10 * (float)v18);
          v25.z = (float)v10 * (float)v18;
          v22 = (float)((float)((float)v18 * (float)v12) * (float)0.2);
          idVec3::NormalVectors(this: &v25, left: &v26, down: v27);
          if ( v22 > 3.0 )
            v22 = 3.0;
          v24[0] = (float)((float)v11 - (float)((float)v19 * (float)v22))
                 + (float)((float)((float)v22 * (float)0.40000001) * v26.x);
          v24[1] = (float)((float)v7 - (float)((float)v20 * (float)v22))
                 + (float)((float)((float)v22 * (float)0.40000001) * v26.y);
          v24[2] = (float)((float)v9 - (float)((float)v21 * (float)v22))
                 + (float)((float)((float)v22 * (float)0.40000001) * v26.z);
          v23[0] = (float)((float)v11 - (float)((float)v19 * (float)v22))
                 - (float)((float)((float)v22 * (float)0.40000001) * v26.x);
          v23[1] = (float)((float)v7 - (float)((float)v20 * (float)v22))
                 - (float)((float)((float)v22 * (float)0.40000001) * v26.y);
          v23[2] = (float)((float)v9 - (float)((float)v21 * (float)v22))
                 - (float)((float)((float)v22 * (float)0.40000001) * v26.z);
          clientGame->renderWorld->DebugLine(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)v28,
            a3: (const idVec3 *)(p_y - 1),
            a4: (const idVec3 *)v24,
            a5: 0,
            a6: false);
          clientGame->renderWorld->DebugLine(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)v28,
            a3: (const idVec3 *)(p_y - 1),
            a4: (const idVec3 *)v23,
            a5: 0,
            a6: false);
          HIDWORD(a1) = ((int (__fastcall *)(idRenderWorld *, float *, float *, float *, _DWORD, _DWORD))clientGame->renderWorld->DebugLine)(
                          a1: clientGame->renderWorld,
                          a2: v28,
                          a3: v24,
                          a4: v23,
                          a5: 0,
                          a6: 0);
        }
      }
    }
    p_y += 9;
  }
  while ( (int)p_y < (int)&setDebugEntity_v );
}


// ========================================================================
// Cmd_AASLoad_f
// EA  : 0x82D6E278
// RVA : 0x00D6E278
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_AASLoad_f(const idCmdArgs *args)
{
  const char *v2; // r4

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    if ( idGameLocal::GetAAS(this: gameLocal, typeName: v2, load: true) == nullptr )
    {
      if ( args->argc <= 1 )
        idLib::Printf(fmt: "AAS %s not found\n", &byte_8200D768);
      else
        idLib::Printf(fmt: "AAS %s not found\n", args->argv[1]);
    }
  }
}


// ========================================================================
// ShowViewNotes
// EA  : 0x82D6E318
// RVA : 0x00D6E318
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall ShowViewNotes(const idStr *comments)
{
  int v2; // [sp+38h] [-28h]

  if ( comments->len != 0 )
    ((void (__fastcall *)(idDebugHUD *, int, int, _DWORD, int, char *))debugHUD->AddPersistentText)(
      a1: debugHUD,
      a2: 10,
      a3: 10,
      a4: 1.2,
      a5: v2,
      a6: comments->data);
  else
    debugHUD->RemovePersistentText(this: debugHUD, a2: 10, a3: 10);
  cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: comments->len != 0, a4: 0);
}


// ========================================================================
// ?Cmd_HealAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E3D8
// RVA : 0x00D6E3D8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_HealAI_f(const idCmdArgs *args)
{
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r31
  idAI2 *v3; // r3
  idLinkList<idEntity> *v4; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v4->owner )
      {
        v3 = idAI2::CastTo(c: i);
        if ( v3 != nullptr )
          v3->aiHealth.Reset_Impl(this: &v3->aiHealth);
        v4 = i->spawnNode.next;
        if ( v4 == nullptr )
          break;
        if ( v4 == i->spawnNode.head )
          break;
      }
    }
  }
}


// ========================================================================
// ?Cmd_ResetViewParms_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E4A0
// RVA : 0x00D6E4A0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ResetViewParms_f(const idCmdArgs *args)
{
  idPresentable *presentable; // r3
  idParmBlock *v2; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( gameLocal != nullptr && gameLocal->world != nullptr )
    {
      presentable = idGameLocal::GetDebugPlayer(this: gameLocal)->presentable;
      if ( presentable != nullptr )
      {
        v2 = (idParmBlock *)presentable->GetPlayerInterface_2(this: presentable);
        idParmBlock::Clear(this: v2 + 410);
      }
      else
      {
        idParmBlock::Clear(this: (idParmBlock *)0x4010);
      }
      idLib::Printf(fmt: "Local client view parms reset\n");
    }
    else
    {
      idLib::Printf(fmt: "Game level not yet loaded.\n");
    }
  }
}


// ========================================================================
// ?Cmd_SetDemoMode_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E558
// RVA : 0x00D6E558
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_SetDemoMode_f(const idCmdArgs *args)
{
  int v1; // r3
  void (*SetCVarInteger)(void); // ctr
  BOOL v3; // r5

  if ( args->argc > 1 )
  {
    v1 = atol(nptr: args->argv[1]);
    SetCVarInteger = (void (*)(void))cvarSystem->SetCVarInteger;
    if ( v1 != 0 )
    {
      SetCVarInteger();
      v3 = true;
    }
    else
    {
      SetCVarInteger();
      v3 = false;
    }
    cvarSystem->SetCVarBool(this: cvarSystem, a2: "con_noPrint", a3: v3, a4: 0);
  }
  else
  {
    idLib::Printf(
      fmt: "0 = reset to non-demo mode and allow console spam, etc.\n"
      "1 = set demo mode and disable all console spam and debug drawing, etc.\n");
  }
}


// ========================================================================
// ?Cmd_ToQuat_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E618
// RVA : 0x00D6E618
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ToQuat_f(const idCmdArgs *args)
{
  int argc; // r9
  const char *v3; // r31
  const char *v4; // r3
  const char *v5; // r30
  __int64 v6; // r11
  double v7; // fp31
  __int64 v8; // r10
  __int64 v9; // r9
  idQuat v10; // [sp+58h] [-58h] BYREF
  idAngles v11; // [sp+70h] [-40h] BYREF
  float v12; // [sp+7Ch] [-34h]

  argc = args->argc;
  if ( args->argc >= 4 )
  {
    v3 = &byte_8200D768;
    if ( argc <= 3 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[3];
    if ( argc <= 2 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[2];
    if ( argc > 1 )
      v3 = args->argv[1];
    LODWORD(v6) = atol(nptr: v4);
    v7 = (float)v6;
    LODWORD(v8) = atol(nptr: v5);
    v10.y = (float)v8;
    LODWORD(v9) = atol(nptr: v3);
    v10.z = v7;
    v10.x = (float)v9;
    idAngles::ToQuat(this: &v11, result: &v10);
    idLib::Printf(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v11.pitch)),
      (unsigned int)COERCE_UNSIGNED_INT64(v11.pitch),
      (unsigned int)COERCE_UNSIGNED_INT64(v11.yaw),
      (unsigned int)COERCE_UNSIGNED_INT64(v11.roll),
      (unsigned int)COERCE_UNSIGNED_INT64(v12));
  }
  else
  {
    idLib::Printf(fmt: "USAGE: toQuat pitch yaw roll\n");
  }
}


// ========================================================================
// ?Cmd_FromQuat_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E758
// RVA : 0x00D6E758
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_FromQuat_f(const idCmdArgs *args)
{
  long double v2; // fp2
  bool v3; // zf
  const char *v4; // r3
  long double v5; // fp2
  const char *v6; // r3
  long double v7; // fp2
  const char *v8; // r3
  long double v9; // fp2
  idQuat v10; // [sp+50h] [-40h] BYREF
  idAngles v11; // [sp+60h] [-30h] BYREF
  float v12; // [sp+6Ch] [-24h]

  if ( args->argc == 5 )
  {
    v2 = atof(nptr: args->argv[1]);
    v3 = args->argc <= 2;
    v11.pitch = *(double *)&v2;
    if ( v3 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[2];
    v5 = atof(nptr: v4);
    v3 = args->argc <= 3;
    v11.yaw = *(double *)&v5;
    if ( v3 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[3];
    v7 = atof(nptr: v6);
    v3 = args->argc <= 4;
    v11.roll = *(double *)&v7;
    if ( v3 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[4];
    v9 = atof(nptr: v8);
    v12 = *(double *)&v9;
    idQuat::ToAngles(this: &v10, result: &v11);
    idLib::Printf(fmt: "Angles = ( %g %g %g )\n", v10.x, v10.y, v10.z);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: fromQuat x y z w\n");
  }
}


// ========================================================================
// ?yawToVector_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E868
// RVA : 0x00D6E868
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall yawToVector_f(const idCmdArgs *args)
{
  const char *v1; // r3
  long double v2; // fp2
  idVec3 v3; // [sp+50h] [-30h] BYREF
  idAngles v4; // [sp+60h] [-20h] BYREF

  if ( args->argc == 2 )
  {
    v1 = args->argv[1];
    v3.x = 0.0;
    v3.z = 0.0;
    v2 = atof(nptr: v1);
    v3.y = *(double *)&v2;
    idAngles::ToForward(this: &v4, result: &v3);
    idLib::Printf(fmt: "vector = %.4f %.4f %.4f\n", v4.pitch, v4.yaw, v4.roll);
  }
  else
  {
    idLib::Printf(fmt: "USAGE: yawToVector <yaw>\n");
  }
}


// ========================================================================
// ?Cmd_ResetBreakables_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E910
// RVA : 0x00D6E910
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ResetBreakables_f(const idCmdArgs *args)
{
  idLinkList<idEntity> *next; // r11
  idBreakable *i; // r31
  idLinkList<idEntity> *v3; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = (idBreakable *)next->owner; i != nullptr; i = (idBreakable *)v3->owner )
      {
        if ( (unsigned __int8)idBreakable::IsTypeOf(c: i) != 0 )
          idBreakable::Reset(this: i);
        v3 = i->spawnNode.next;
        if ( v3 == nullptr )
          break;
        if ( v3 == i->spawnNode.head )
          break;
      }
    }
  }
}


// ========================================================================
// ?setDebugEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6E9C0
// RVA : 0x00D6E9C0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall setDebugEntity_f(const idCmdArgs *args)
{
  int v1; // r3
  int v2; // r9
  int v3; // r31

  if ( args->argc == 2 )
  {
    v1 = atol(nptr: args->argv[1]);
    if ( v1 >= 0 && (v2 = 4 * (v1 + 21563), (v3 = *(int *)((char *)&gameLocal->__vftable + v2)) != 0) )
    {
      idGameLocal::SetDebugEntity(this: gameLocal, ent: *(idEntity **)((char *)&gameLocal->__vftable + v2));
      idLib::Printf(fmt: "Selected entity '%s' as debug target.\n", *(const char **)(v3 + 16));
    }
    else
    {
      idLib::Printf(fmt: "Cleared debug target.\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: setDebugentity <entity number>\n");
  }
}


// ========================================================================
// ?toggleFreeCam_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6EA60
// RVA : 0x00D6EA60
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall toggleFreeCam_f(const idCmdArgs *args)
{
  idCVar::SetInteger(this: &g_freeCam, newValue: (_cntlzw(g_freeCam.valueInteger) & 0x20) != 0, force: true);
  g_freeCam.flags |= 0x20000u;
}


// ========================================================================
// ?Cmd_ListEntitiesAtOrigin_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6EAB0
// RVA : 0x00D6EAB0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ListEntitiesAtOrigin_f(const idCmdArgs *args)
{
  int v2; // r21
  idTypeInfoTools *v3; // r3
  const enumTypeInfo_t *EnumInfo; // r28
  int i; // r27
  const enumValueInfo_t *values; // r31
  int v7; // r29
  int v8; // r30
  char *v9; // r3
  int v10; // r24
  int v11; // r25
  int j; // r26
  idClass *v13; // r28
  idPhysics *Physics; // r31
  float *v15; // r3
  char v16; // r11
  char v17; // r29
  int v18; // r30
  const char *v19; // r31
  const char *Classname; // r3

  v2 = 0;
  if ( args->argc > 1 )
  {
    if ( idStr::Icmp(s1: args->argv[1], s2: "all") != 0 )
    {
      v3 = (idTypeInfoTools *)gameLocal->GetTypeInfoTools(this: gameLocal);
      EnumInfo = idTypeInfoTools::FindEnumInfo(this: v3, typeName: "contentsFlags_t");
      if ( EnumInfo != nullptr )
      {
        for ( i = 1; i < args->argc; ++i )
        {
          values = EnumInfo->values;
          v7 = 0;
          if ( values->name != nullptr )
          {
            v8 = 0;
            while ( 1 )
            {
              v9 = idCmdArgs::Argv(this: args, arg: i);
              if ( idStr::Icmp(s1: values[v8].name, s2: v9) == 0 )
                break;
              ++v7;
              values = EnumInfo->values;
              v8 = v7;
              if ( values[v7].name == nullptr )
                goto LABEL_12;
            }
            v2 |= EnumInfo->values[v8].value;
          }
LABEL_12:
          ;
        }
      }
    }
    else
    {
      v2 = 0x7FFFFFFF;
    }
  }
  idLib::Printf(fmt: "Entities at origin:\n");
  v10 = 0;
  v11 = 0;
  for ( j = 86252; j < 119020; j += 4 )
  {
    if ( v11 != 8190 )
    {
      v13 = *(idClass **)((char *)&gameLocal->__vftable + j);
      if ( v13 != nullptr )
      {
        Physics = idEntity::GetPhysics(this: *(idEntity **)((char *)&gameLocal->__vftable + j));
        v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        if ( *v15 != vec3_origin.x || v15[1] != vec3_origin.y || (v16 = 1, v15[2] != vec3_origin.z) )
          v16 = 0;
        if ( v16 != 0 )
        {
          if ( v2 == 0 )
            goto LABEL_28;
          v17 = 0;
          v18 = 0;
          if ( Physics->GetNumClipModels(this: Physics) > 0 )
          {
            while ( (Physics->GetClipModel(this: Physics, a2: v18)->contents & v2) == 0 )
            {
              if ( ++v18 >= Physics->GetNumClipModels(this: Physics) )
                goto LABEL_27;
            }
            v17 = 1;
          }
LABEL_27:
          if ( v17 != 0 )
          {
LABEL_28:
            v19 = (const char *)v13[4].__vftable;
            Classname = idClass::GetClassname(this: v13);
            idLib::Printf(fmt: "  %s, %s\n", v19, Classname);
            ++v10;
          }
        }
      }
    }
    ++v11;
  }
  idLib::Printf(fmt: "Found %d entities at origin", v10);
  if ( v2 != 0 )
    idLib::Printf(fmt: " matching clip mask.\n");
  else
    idLib::Printf(fmt: ".\n");
}


// ========================================================================
// ?Cmd_EntityListCollision_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6EE38
// RVA : 0x00D6EE38
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_EntityListCollision_f(const idCmdArgs *args)
{
  const char *v1; // r3
  int v2; // r27
  int v3; // r26
  int i; // r24
  idEntity *v5; // r30
  int v6; // r28
  idPhysics *Physics; // r3
  idPhysics *v8; // r3
  idClipModel *v9; // r3
  idCollisionModel *collisionModel; // r29
  const char *str; // r29
  const char *data; // r19
  const char *Classname; // r18
  const char *EntityDefName; // r3
  idPhysics *v15; // r3
  idStr v16[5]; // [sp+50h] [-A0h] BYREF

  v16[0].len = 0;
  v16[0].allocedAndFlag = 20;
  v16[0].data = v16[0].baseBuffer;
  v16[0].baseBuffer[0] = 0;
  if ( args->argc <= 1 )
  {
    idStr::operator=(this: v16, text: &byte_8200D768);
  }
  else
  {
    v1 = idCmdArgs::Args(this: args, start: 1, end: -1, quoteArgs: false, escapeArgs: false);
    idStr::operator=(this: v16, text: v1);
    idStr::Replace(this: v16, old: " ", nw: &byte_8200D768);
  }
  idStr::Replace(this: v16, old: "*", nw: &byte_8200D768);
  v2 = 0;
  idLib::Printf(fmt: "%-4s  %-20s %-20s %s\n", " Num", "EntityDef", "Class", "Name");
  idLib::Printf(fmt: "--------------------------------------------------------------------\n");
  v3 = 0;
  for ( i = 86252; i < 119020; i += 4 )
  {
    v5 = *(idEntity **)((char *)&gameLocal->__vftable + i);
    if ( v5 != nullptr )
    {
      v6 = 0;
      Physics = idEntity::GetPhysics(this: *(idEntity **)((char *)&gameLocal->__vftable + i));
      if ( Physics->GetNumClipModels(this: Physics) > 0 )
      {
        do
        {
          v8 = idEntity::GetPhysics(this: v5);
          v9 = v8->GetClipModel(this: v8, a2: v6);
          collisionModel = v9->collisionModel;
          if ( collisionModel != nullptr
            || (v9->traceModels.num <= 0
              ? (collisionModel = idClipModel::NoTraceModelWarning(this: v9))
              : (collisionModel = v9->clip->traceModelCache->cache.list[*v9->traceModels.list]->collisionModel),
                collisionModel != nullptr) )
          {
            if ( v16[0].len <= 0
              || idStr::Find(
                   searchIn: collisionModel->name.str,
                   searchFor: v16[0].data,
                   casesensitive: true,
                   start: 0,
                   end: -1) != -1 )
            {
              str = collisionModel->name.str;
              data = v5->name.data;
              Classname = idClass::GetClassname(this: v5);
              EntityDefName = idEntity::GetEntityDefName(this: v5);
              idLib::Printf(fmt: "%4i: %-20s %-20s %s: %s\n", v3, EntityDefName, Classname, data, str);
              ++v2;
            }
          }
          ++v6;
          v15 = idEntity::GetPhysics(this: v5);
        }
        while ( v6 < v15->GetNumClipModels(this: v15) );
      }
    }
    ++v3;
  }
  idLib::Printf(fmt: "%d referenced collision models", v2);
  idStr::FreeData(this: v16);
}


// ========================================================================
// __unwind$495202
// EA  : 0x82D6F094
// RVA : 0x00D6F094
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495202()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?Cmd_ActiveActorList_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6F128
// RVA : 0x00D6F128
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ActiveActorList_f(const idCmdArgs *args)
{
  int v1; // r25
  int v2; // r24
  idLinkList<idActor> *next; // r11
  idActor *owner; // r31
  char v5; // r26
  idPhysics *Physics; // r3
  const char *v7; // r27
  const idDeclEntityDef *entityDef; // r11
  const char *str; // r30
  int numPVSAreas; // r29
  const char *data; // r28
  int entityNumber; // r19
  const char *Classname; // r3
  idLinkList<idActor> *v14; // r11

  v1 = 0;
  v2 = 0;
  idLib::Printf(fmt: "%-4s  %-20s %-20s %s\n", " Num", "EntityDef", "Class", "Name");
  idLib::Printf(fmt: "--------------------------------------------------------------------\n");
  next = gameLocal->actorEntities.next;
  if ( next != nullptr && next != gameLocal->actorEntities.head )
  {
    owner = next->owner;
    while ( owner != nullptr )
    {
      v5 = (*((_BYTE *)&owner->flags + 1) & 0x80) == 0 ? 32 : 45;
      Physics = idEntity::GetPhysics(this: owner);
      v7 = "non-resident";
      if ( !Physics->IsInNonResidentCollisionArea(this: Physics, a2: false) )
        v7 = "resident";
      entityDef = owner->entityDef;
      str = "*unknown*";
      numPVSAreas = owner->numPVSAreas;
      data = owner->name.data;
      if ( entityDef != nullptr )
        str = entityDef->name.str;
      entityNumber = owner->entityNumber;
      Classname = idClass::GetClassname(this: owner);
      idLib::Printf(
        fmt: "%4i:%c%-20s %-20s %s (%d PVS areas, collision %s)\n",
        entityNumber,
        v5,
        str,
        Classname,
        data,
        numPVSAreas,
        v7);
      v14 = owner->actorNode.next;
      ++v1;
      v2 += *((unsigned __int8 *)&owner->flags + 1) >> 7;
      if ( v14 == nullptr || v14 == owner->actorNode.head )
        owner = nullptr;
      else
        owner = v14->owner;
    }
  }
  idLib::Printf(fmt: "...%d active actors of which %d dormant\n", v1, v2);
}


// ========================================================================
// ?Cmd_Script_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6F2C0
// RVA : 0x00D6F2C0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_Script_f(const idCmdArgs *args)
{
  __int64 v2; // r8
  __int64 v3; // r6
  __int64 v4; // r10
  va *v5; // r3
  const char *v6; // r3
  __int64 v7; // r8
  __int64 v8; // r10
  va *v9; // r3
  const function_t *Function; // r27
  idGameLocal *v11; // r3
  idLinkList<idEntity> *next; // r11
  idEntity *owner; // r30
  idLinkList<idEntity> *v14; // r11
  int v15; // [sp+8h] [-20B8h]
  int v16; // [sp+8h] [-20B8h]
  int v17; // [sp+Ch] [-20B4h]
  int v18; // [sp+Ch] [-20B4h]
  int v19; // [sp+10h] [-20B0h]
  int v20; // [sp+10h] [-20B0h]
  int v21; // [sp+14h] [-20ACh]
  int v22; // [sp+14h] [-20ACh]
  int v23; // [sp+18h] [-20A8h]
  int v24; // [sp+18h] [-20A8h]
  int v25; // [sp+1Ch] [-20A4h]
  int v26; // [sp+1Ch] [-20A4h]
  idStr v27; // [sp+50h] [-2070h] BYREF
  idStr v28; // [sp+70h] [-2050h] BYREF
  va v29; // [sp+90h] [-2030h] BYREF
  va v30; // [sp+1090h] [-1030h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( idGameLocal::IsExecutingConsoleScript(this: gameLocal) )
    {
      idLib::Warning(fmt: "A console script command is already running.");
    }
    else
    {
      LODWORD(v4) = &idEventDef::eventDefList[3154];
      HIDWORD(v4) = "WriteBoundedFloatBase";
      HIDWORD(v3) = funccount++;
      v5 = va::va(
             this: &v29,
             fmt: "ConsoleFunction_%d",
             a3: v3,
             a4: v2,
             a5: v4,
             a6: v15,
             a7: v17,
             a8: v19,
             a9: v21,
             a10: v23,
             a11: v25);
      idStr::idStr(this: &v27, text: v5);
      v6 = idCmdArgs::Args(this: args, start: 1, end: -1, quoteArgs: false, escapeArgs: false);
      LODWORD(v7) = "WriteBoundedFloatBase";
      v9 = va::va(
             this: &v30,
             fmt: "void %s() {%s;}\n",
             a3: __SPAIR64__((unsigned int)v27.data, (unsigned int)v6),
             a4: v7,
             a5: v8,
             a6: v16,
             a7: v18,
             a8: v20,
             a9: v22,
             a10: v24,
             a11: v26);
      idStr::idStr(this: &v28, text: v9);
      if ( idProgram::CompileText(this: &gameLocal->program, source: "console", text: v28.data, flags: 9) )
      {
        Function = idProgram::FindFunction(this: &gameLocal->program, name: v27.data);
        if ( Function != nullptr )
        {
          v11 = gameLocal;
          next = gameLocal->spawnedEntities.next;
          if ( next != nullptr && next != gameLocal->spawnedEntities.head )
          {
            owner = next->owner;
            if ( owner != nullptr )
            {
              while ( 1 )
              {
                idProgram::SetEntity(this: &v11->program, name: owner->name.data, ent: owner);
                v14 = owner->spawnNode.next;
                if ( v14 == nullptr )
                  break;
                if ( v14 == owner->spawnNode.head )
                  break;
                owner = v14->owner;
                if ( owner == nullptr )
                  break;
                v11 = gameLocal;
              }
              v11 = gameLocal;
            }
          }
          idGameLocal::ExecuteConsoleScriptFunction(this: v11, func: Function);
        }
      }
      idStr::FreeData(this: &v28);
      idStr::FreeData(this: &v27);
    }
  }
}


// ========================================================================
// __unwind$495466
// EA  : 0x82D6F460
// RVA : 0x00D6F460
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495466()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8384 + 80));
}


// ========================================================================
// __unwind$495467
// EA  : 0x82D6F488
// RVA : 0x00D6F488
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495467()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8384 + 112));
}


// ========================================================================
// ?Cmd_ReloadEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6F4B8
// RVA : 0x00D6F4B8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ReloadEntity_f(const idCmdArgs *args)
{
  const char *v2; // r4
  int entityNumber; // r27
  idEntity *v4; // r3
  idEntity *v5; // r29
  idMapFile *v6; // r3
  idMapEntity *v7; // r28
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 2 )
    {
      if ( gameLocal->IsGameActive(this: gameLocal) )
      {
        if ( args->argc <= 1 )
          v2 = &byte_8200D768;
        else
          v2 = args->argv[1];
        idStr::idStr(this: v8, text: v2);
        entityNumber = -1;
        v4 = gameLocal->FindEntity(this: gameLocal, a2: v8[0].data);
        v5 = v4;
        if ( v4 != nullptr )
          entityNumber = v4->entityNumber;
        v6 = gameLocal->GetLevelMap(this: gameLocal);
        if ( (unsigned __int8)idMapFile::Reload(this: v6) != 0 )
        {
          v7 = gameLocal->MapFindEntity(this: gameLocal, a2: v8[0].data);
          if ( v7 != nullptr )
          {
            if ( v5 != nullptr )
              ((void (__fastcall *)(idEntity *, int))v5->dtr_idClass)(a1: v5, a2: 1);
            gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v7->entityDef, a3: entityNumber, a4: -1, a5: -1);
          }
          else
          {
            idLib::Printf(fmt: "Entity '%s' not found.\n", v8[0].data);
          }
        }
        idStr::FreeData(this: v8);
      }
      else
      {
        idLib::Printf(fmt: "You must be in-game for this command to work.\n");
      }
    }
    else
    {
      idLib::Printf(fmt: "Must pass in an entity name to reload\n");
    }
  }
}


// ========================================================================
// __unwind$495560
// EA  : 0x82D6F638
// RVA : 0x00D6F638
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495560()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Cmd_KillEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6F668
// RVA : 0x00D6F668
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillEntity_f(const idCmdArgs *args)
{
  const char *v2; // r4
  char v3; // r29
  const char *v4; // r4
  __int64 v5; // r10
  __int64 v6; // r8
  int v7; // r6
  idEntity *v8; // r3
  idEntity_vtbl *v9; // r11
  const idTypeInfo *v10; // r3
  idStr v11; // [sp+60h] [-960h] BYREF
  idCmdArgs v12; // [sp+80h] [-940h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc >= 2 )
    {
      if ( args->argc <= 1 )
        v2 = &byte_8200D768;
      else
        v2 = args->argv[1];
      idStr::idStr(this: &v11, text: v2);
      v3 = 0;
      if ( idStr::Icmp(s1: v11.data, s2: "all") == 0 && args->argc >= 3 )
      {
        if ( args->argc <= 2 )
          v4 = &byte_8200D768;
        else
          v4 = args->argv[2];
        idStr::operator=(this: &v11, text: v4);
        v3 = 1;
      }
      v8 = gameLocal->FindEntity(this: gameLocal, a2: v11.data);
      if ( v8 != nullptr )
      {
        if ( v3 != 0 )
        {
          v9 = v8->__vftable;
          v12.argc = 0;
          v10 = v9->GetType(this: v8);
          KillEntities(args: &v12, superClass: v10);
        }
        else
        {
          idEventReceiver::PostEventMS(this: v8, ev: &EV_Remove, time: 0, a4: v7, a5: v6, a6: v5);
        }
      }
      else
      {
        idLib::Printf(fmt: "Entity '%s' not found.\n", v11.data);
      }
      idStr::FreeData(this: &v11);
    }
    else
    {
      idLib::Printf(fmt: "Must pass in an entity name to kill, optionally pass in all and an entity name to kill of of that type\n");
    }
  }
}


// ========================================================================
// __unwind$495630
// EA  : 0x82D6F7B0
// RVA : 0x00D6F7B0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2496 + 96));
}


// ========================================================================
// ?Cmd_Damage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6F7D8
// RVA : 0x00D6F7D8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_Damage_f(const idCmdArgs *args)
{
  idEntity *v2; // r27
  __int64 v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // r4
  const char *v6; // r4
  idDeclDamage *v7; // r3
  idDeclDamage *v8; // r30
  idEntity_vtbl *v9; // r31
  idWorldspawn *world; // r29
  double v11; // fp1
  const idDecl *v12; // r30
  const char *v13; // r3
  __int64 v14; // [sp+50h] [-50h]
  idVec3 v15; // [sp+58h] [-48h] BYREF

  if ( !idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
    return;
  if ( args->argc != 3 )
  {
    idLib::Printf(fmt: "usage: damage <name of entity to damage> <damageDecl>\n");
    idLib::Printf(fmt: "usage: damage <name of entity to damage> <damageAmount>\n");
    return;
  }
  v2 = gameLocal->FindEntity(this: gameLocal, a2: args->argv[1]);
  if ( v2 == nullptr )
  {
    idLib::Printf(fmt: "entity not found\n");
    return;
  }
  HIDWORD(v3) = 1013904223;
  v4 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v4;
  LODWORD(v3) = (v4 >> 10) & 0x7FFF;
  v5 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v5 + 1013904223;
  v15.z = 1.0;
  v15.y = (float)((float)v3 * (float)0.000061037019) - (float)1.0;
  LODWORD(v3) = ((v5 + 1013904223) >> 10) & 0x7FFF;
  v15.x = (float)((float)v3 * (float)0.000061037019) - (float)1.0;
  idVec3::NormalizeFast(this: &v15);
  if ( args->argc <= 2 )
  {
    v6 = &byte_8200D768;
LABEL_8:
    v7 = (idDeclDamage *)idDeclInfo::FindWithInheritance(
                           this: &idDeclDamage::resourceList,
                           name: v6,
                           makeDefault: false);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v9 = v2->__vftable;
      world = gameLocal->world;
      v11 = idDeclDamage::DamageAmount(this: v7);
      ((void (__fastcall *)(idEntity *, idWorldspawn *, idWorldspawn *, idDeclDamage *, double))v9->Damage)(
        a1: v2,
        a2: world,
        a3: world,
        a4: v8,
        a5: v11);
      return;
    }
    goto LABEL_11;
  }
  v6 = args->argv[2];
  if ( v6 != nullptr )
    goto LABEL_8;
LABEL_11:
  v12 = idDeclInfo::FindWithInheritance(
          this: &idDeclDamage::resourceList,
          name: "damage/code_referenced/damage1",
          makeDefault: true);
  if ( args->argc <= 2 )
    v13 = &byte_8200D768;
  else
    v13 = args->argv[2];
  v14 = (unsigned int)atol(nptr: v13) | 0x2000000000000LL;
  ((void (__fastcall *)(idEntity *, idWorldspawn *, idWorldspawn *, const idDecl *, double))v2->Damage)(
    a1: v2,
    a2: gameLocal->world,
    a3: gameLocal->world,
    a4: v12,
    a5: (float)v14);
}


// ========================================================================
// ?Cmd_TestLight_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6FA08
// RVA : 0x00D6FA08
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_TestLight_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v3; // r29
  idPresentable *presentable; // r3
  int v5; // r30
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  long double v9; // fp2
  __int64 v10; // r6
  long double v11; // fp2
  __int64 v12; // r10
  double v13; // fp31
  __int64 v14; // r8
  va *v15; // r3
  idEntity *v16; // r3
  idLight *v17; // r30
  int argc; // r11
  const char *v19; // r3
  const char *v20; // r3
  const char *v21; // r3
  const char *v22; // r4
  int v23; // [sp+8h] [-1148h]
  int v24; // [sp+Ch] [-1144h]
  int v25; // [sp+10h] [-1140h]
  int v26; // [sp+14h] [-113Ch]
  int v27; // [sp+18h] [-1138h]
  int v28; // [sp+1Ch] [-1134h]
  float v29; // [sp+50h] [-1100h] BYREF
  idMat3 v30; // [sp+60h] [-10F0h] BYREF
  idVec3 v31; // [sp+88h] [-10C8h] BYREF
  idVec3 v32; // [sp+98h] [-10B8h] BYREF
  idVec3 v33; // [sp+A8h] [-10A8h] BYREF
  idVec3 v34; // [sp+B8h] [-1098h] BYREF
  idStr v35; // [sp+D0h] [-1080h] BYREF
  int v36; // [sp+F0h] [-1060h]
  float v37; // [sp+F4h] [-105Ch] BYREF
  idVec3 v38[2]; // [sp+F8h] [-1058h] BYREF
  va v39; // [sp+110h] [-1040h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    presentable = v3->presentable;
    v5 = 0;
    if ( presentable != nullptr )
      v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = 0;
    idView::GetViewPos(this: (idView *)(v6 + 16224), origin: v38, axis: &v30);
    v7 = v3->presentable;
    if ( v7 != nullptr )
      v8 = (int)v7->GetPlayerInterface_2(this: v7);
    else
      v8 = 0;
    idView::GetFOV(this: (idView *)(v8 + 16224), fov_x: &v29, fov_y: &v37);
    *(double *)&v9 = (float)((float)(idMath::M_DEG2RAD * v29) * (float)0.5);
    v11 = tan(x: v9);
    HIDWORD(v12) = 20;
    v13 = (float)*(double *)&v11;
    LODWORD(v14) = v35.baseBuffer;
    v35.len = 0;
    v35.allocedAndFlag = 20;
    v35.data = v35.baseBuffer;
    v35.baseBuffer[0] = 0;
    do
    {
      HIDWORD(v10) = v5;
      v15 = va::va(
              this: &v39,
              fmt: "spawned_light_%d",
              a3: v10,
              a4: v14,
              a5: v12,
              a6: v23,
              a7: v24,
              a8: v25,
              a9: v26,
              a10: v27,
              a11: v28);
      idStr::operator=(this: &v35, text: v15);
      if ( gameLocal->FindEntity(this: gameLocal, a2: v35.data) == nullptr )
        break;
      ++v5;
    }
    while ( v5 < 0x2000 );
    v16 = idGameLocal::SpawnEntityType(
            this: gameLocal,
            typeInfo: &idLight::Type,
            forceEntityNumber: -1,
            _model: nullptr);
    v17 = (idLight *)v16;
    if ( v16 != nullptr )
    {
      idEntity::SetName(this: v16, newName: v35.data);
      v17->SetAxis(this: v17, a2: &mat3_identity);
      idEntity::SetOrigin(this: v17, org: v38);
      idLight::SetLightTarget(this: v17, v: v30.mat);
      v33.z = v30.mat[1].z * (float)-v13;
      v33.y = v30.mat[1].y * (float)-v13;
      v33.x = v30.mat[1].x * (float)-v13;
      idLight::SetLightRight(this: v17, v: &v33);
      v34.x = v30.mat[2].x * (float)v13;
      v34.z = v30.mat[2].z * (float)v13;
      v34.y = v30.mat[2].y * (float)v13;
      idLight::SetLightUp(this: v17, v: &v34);
      v31.z = v30.mat[0].z * (float)16.0;
      v31.y = v30.mat[0].y * (float)16.0;
      v31.x = v30.mat[0].x * (float)16.0;
      idLight::SetLightStart(this: v17, v: &v31);
      v32.z = v30.mat[0].z * (float)10000.0;
      v32.y = v30.mat[0].y * (float)10000.0;
      v32.x = v30.mat[0].x * (float)10000.0;
      idLight::SetLightEnd(this: v17, v: &v32);
      idLight::SetSpot(this: v17, b: true);
      argc = args->argc;
      v36 = args->argc;
      if ( v36 >= 2 )
      {
        if ( argc <= 1 )
          v19 = &byte_8200D768;
        else
          v19 = args->argv[1];
        if ( idStr::Icmp(s1: v19, s2: "privatePrime") != 0 )
        {
          if ( args->argc <= 1 )
            v20 = &byte_8200D768;
          else
            v20 = args->argv[1];
          if ( idStr::Icmp(s1: v20, s2: "privateSecondary") != 0 )
          {
            if ( args->argc <= 1 )
              v21 = &byte_8200D768;
            else
              v21 = args->argv[1];
            if ( idStr::Icmp(s1: v21, s2: "privateFill") != 0 )
            {
              if ( args->argc <= 1 )
                v22 = &byte_8200D768;
              else
                v22 = args->argv[1];
              idLight::SetLightMaterial(this: v17, mat: v22);
            }
            else
            {
              v17->renderLight->g.lightClass = LIGHT_PRIVATE_DYNAMIC_ONLY;
              v17->renderLight->g.noShadows = true;
            }
          }
          else
          {
            v17->renderLight->g.lightClass = LIGHT_PRIVATE_DYNAMIC_ONLY;
          }
        }
        else
        {
          v17->renderLight->g.lightClass = LIGHT_PRIVATE_PRIME;
        }
      }
      idEntity::UpdateVisuals(this: v17);
    }
    idLib::Printf(fmt: "Created new light\n");
    idStr::FreeData(this: &v35);
  }
}


// ========================================================================
// __unwind$495789
// EA  : 0x82D6FDA8
// RVA : 0x00D6FDA8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_495789()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 208));
}


// ========================================================================
// ?Cmd_TestPointLight_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D6FDD8
// RVA : 0x00D6FDD8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_TestPointLight_f(const idCmdArgs *args)
{
  double v2; // fp30
  double v3; // fp31
  idPlayer *DebugPlayer; // r3
  idPlayer *v5; // r30
  idPresentable *presentable; // r3
  int v7; // r30
  int v8; // r3
  const char *v9; // r3
  long double v10; // fp2
  const char *v11; // r3
  long double v12; // fp2
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  va *v16; // r3
  idEntity *v17; // r3
  idLight *v18; // r30
  int v19; // [sp+8h] [-10F8h]
  int v20; // [sp+Ch] [-10F4h]
  int v21; // [sp+10h] [-10F0h]
  int v22; // [sp+14h] [-10ECh]
  double v23; // [sp+18h] [-10E8h]
  idStr v24; // [sp+60h] [-10A0h] BYREF
  idVec3 v25; // [sp+80h] [-1080h] BYREF
  idMat3 v26; // [sp+90h] [-1070h] BYREF
  va v27; // [sp+C0h] [-1040h] BYREF

  v2 = 300.0;
  v3 = 1.0;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v5 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    presentable = v5->presentable;
    v7 = 0;
    if ( presentable != nullptr )
      v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = 0;
    idView::GetViewPos(this: (idView *)(v8 + 16224), origin: &v25, axis: &v26);
    if ( args->argc >= 2 )
    {
      if ( args->argc <= 1 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[1];
      v10 = atof(nptr: v9);
      v2 = (float)*(double *)&v10;
    }
    if ( args->argc >= 3 )
    {
      if ( args->argc <= 2 )
        v11 = &byte_8200D768;
      else
        v11 = args->argv[2];
      v12 = atof(nptr: v11);
      v3 = (float)*(double *)&v12;
    }
    v23 = v2;
    idLib::Printf(fmt: "Creating a %f radius / %4.2f intensity point light.\n", v2, v3);
    LODWORD(v15) = 20;
    HIDWORD(v15) = v24.baseBuffer;
    v24.len = 0;
    v24.allocedAndFlag = 20;
    v24.data = v24.baseBuffer;
    v24.baseBuffer[0] = 0;
    do
    {
      HIDWORD(v14) = v7;
      v16 = va::va(
              this: &v27,
              fmt: "light_%d",
              a3: v14,
              a4: v13,
              a5: v15,
              a6: v19,
              a7: v20,
              a8: v21,
              a9: v22,
              a10: SHIDWORD(v23),
              a11: SLODWORD(v23));
      idStr::operator=(this: &v24, text: v16);
      if ( gameLocal->FindEntity(this: gameLocal, a2: v24.data) == nullptr )
        break;
      ++v7;
    }
    while ( v7 < 0x2000 );
    v17 = idGameLocal::SpawnEntityType(
            this: gameLocal,
            typeInfo: &idLight::Type,
            forceEntityNumber: -1,
            _model: nullptr);
    v18 = (idLight *)v17;
    if ( v17 != nullptr )
    {
      idEntity::SetName(this: v17, newName: v24.data);
      idLight::SetRadius(this: v18, radius: v2);
      idEntity::SetOrigin(this: v18, org: &v25);
      idEntity::UpdateVisuals(this: v18);
      v18->SetColor_4(this: v18, a2: v3, a3: v3, a4: v3);
    }
    idLib::Printf(fmt: "Created new point light\n");
    idStr::FreeData(this: &v24);
  }
}


// ========================================================================
// __unwind$496038
// EA  : 0x82D6FFEC
// RVA : 0x00D6FFEC
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 96));
}


// ========================================================================
// ?Cmd_TestParallelLight_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D70020
// RVA : 0x00D70020
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_TestParallelLight_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r30
  idPresentable *presentable; // r3
  int v4; // r30
  int v5; // r3
  __int64 v6; // r8
  __int64 v7; // r6
  __int64 v8; // r10
  va *v9; // r3
  idEntity *v10; // r3
  idLight *v11; // r30
  int v12; // [sp+8h] [-10E8h]
  int v13; // [sp+Ch] [-10E4h]
  int v14; // [sp+10h] [-10E0h]
  int v15; // [sp+14h] [-10DCh]
  double v16; // [sp+18h] [-10D8h]
  idVec3 v17; // [sp+50h] [-10A0h] BYREF
  idStr v18; // [sp+60h] [-1090h] BYREF
  idMat3 v19; // [sp+80h] [-1070h] BYREF
  idVec3 v20[2]; // [sp+A8h] [-1048h] BYREF
  va v21; // [sp+C0h] [-1030h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    presentable = v2->presentable;
    v4 = 0;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idView::GetViewPos(this: (idView *)(v5 + 16224), origin: v20, axis: &v19);
    v16 = -v19.mat[0].x;
    idLib::Printf(fmt: "light_center %f %f %f", v16, -v19.mat[0].y, -v19.mat[0].z);
    LODWORD(v8) = 20;
    HIDWORD(v8) = v18.baseBuffer;
    v18.len = 0;
    v18.allocedAndFlag = 20;
    v18.data = v18.baseBuffer;
    v18.baseBuffer[0] = 0;
    do
    {
      HIDWORD(v7) = v4;
      v9 = va::va(
             this: &v21,
             fmt: "light_%d",
             a3: v7,
             a4: v6,
             a5: v8,
             a6: v12,
             a7: v13,
             a8: v14,
             a9: v15,
             a10: SHIDWORD(v16),
             a11: SLODWORD(v16));
      idStr::operator=(this: &v18, text: v9);
      if ( gameLocal->FindEntity(this: gameLocal, a2: v18.data) == nullptr )
        break;
      ++v4;
    }
    while ( v4 < 0x2000 );
    v10 = idGameLocal::SpawnEntityType(
            this: gameLocal,
            typeInfo: &idLight::Type,
            forceEntityNumber: -1,
            _model: nullptr);
    v11 = (idLight *)v10;
    if ( v10 != nullptr )
    {
      idEntity::SetName(this: v10, newName: v18.data);
      v17.x = -v19.mat[0].x;
      v17.z = -v19.mat[0].z;
      v17.y = -v19.mat[0].y;
      idLight::SetLightCenter(this: v11, v: &v17);
      idLight::SetParallel(this: v11, b: true);
      idLight::SetRadius(this: v11, radius: 8000.0);
      idEntity::SetOrigin(this: v11, org: v20);
      idEntity::UpdateVisuals(this: v11);
    }
    idLib::Printf(fmt: "Created new parallel light\n");
    idStr::FreeData(this: &v18);
  }
}


// ========================================================================
// __unwind$496153_0
// EA  : 0x82D701E8
// RVA : 0x00D701E8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496153_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4336 + 96));
}


// ========================================================================
// Cmd_TestDeath_f
// EA  : 0x82D70210
// RVA : 0x00D70210
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_TestDeath_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r30
  float *v2; // r3
  long double v3; // fp2
  const idDecl *v4; // r6
  float v5; // [sp+50h] [-30h] BYREF
  float v6[5]; // [sp+54h] [-2Ch] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    v2 = (float *)idGameLocal::CheckCheats(this: gameLocal, player: nullptr);
    if ( (_BYTE)v2 != 0 )
    {
      *(double *)&v3 = (float)(idMath::M_DEG2RAD * (float)45.0);
      idMath::SinCos(a: v3, s: v2, c: v6, a4: &v5);
      v6[1] = 0.0;
      idCVar::SetBool(this: &g_testDeath, newValue: true, force: true);
      v4 = idDeclInfo::FindWithInheritance(
             this: &idDeclDamage::resourceList,
             name: "damage/code_referenced/triggerHurt1000",
             makeDefault: true);
      if ( v4 != nullptr )
        ((void (__fastcall *)(idPlayer *, _DWORD, _DWORD, const idDecl *, double))DebugPlayer->Damage)(
          a1: DebugPlayer,
          a2: 0,
          a3: 0,
          a4: v4,
          a5: 1.0);
    }
  }
}


// ========================================================================
// Cmd_RecordViewNotes_f
// EA  : 0x82D70308
// RVA : 0x00D70308
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_RecordViewNotes_f(const idCmdArgs *args)
{
  const char *v2; // r3
  idPlayer *DebugPlayer; // r3
  const char *v4; // r4
  idFile *v5; // r3
  idFile *v6; // r30
  idFile_vtbl *v7; // r28
  const char *v8; // r26
  const char *v9; // r3
  char *v10; // r6
  char *v11; // r5
  idAngles v12; // [sp+50h] [-B0h] BYREF
  idStr v13; // [sp+60h] [-A0h] BYREF
  idStr v14; // [sp+80h] [-80h] BYREF
  idMat3 v15[2]; // [sp+A0h] [-60h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v13.len = 0;
    v13.allocedAndFlag = 20;
    v13.data = v13.baseBuffer;
    v13.baseBuffer[0] = 0;
    v2 = gameLocal->GetMapName(this: gameLocal);
    idStr::idStr(this: &v14, text: v2);
    idStr::StripFileExtension(this: &v14);
    if ( args->argc > 3 )
    {
      DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
      if ( DebugPlayer != nullptr )
      {
        DebugPlayer->GetViewTransform(this: DebugPlayer, a2: (idVec3 *)&v12, a3: v15);
        v4 = args->argc <= 1 ? &byte_8200D768 : args->argv[1];
        idStr::operator=(this: &v13, text: v4);
        idStr::SetFileExtension(this: &v13, extension: ".txt");
        v5 = fileSystem->OpenFileAppend(this: fileSystem, a2: v13.data, a3: 2);
        v6 = v5;
        if ( v5 != nullptr )
        {
          v7 = v5->__vftable;
          v8 = idMat3::ToString(this: v15, precision: 2);
          v9 = idVec3::ToString(this: &v12, precision: 2);
          v7->WriteFloatString(this: v6, a2: "\"view\"\t( %s )\t( %s )\r\n", v9, v8);
          if ( args->argc <= 3 )
            v10 = &byte_8200D768;
          else
            v10 = args->argv[3];
          if ( args->argc <= 2 )
            v11 = &byte_8200D768;
          else
            v11 = args->argv[2];
          v6->WriteFloatString(this: v6, a2: "\"comments\"\t\"%s: %s\"\r\n\r\n", v11, v10);
          ((void (__fastcall *)(idFile *, int))v6->dtr_idFile)(a1: v6, a2: 1);
        }
      }
      idStr::FreeData(this: &v14);
    }
    else
    {
      idLib::Printf(fmt: "Invalid parameters:\n");
      idLib::Printf(fmt: "  Argv(1) = filename for map ( viewnotes/%s/<person> )\n", v14.data);
      idLib::Printf(fmt: "  Argv(2) = note number ( <person>0001 )\n");
      idLib::Printf(fmt: "  Argv(3) = comments\n");
      idStr::FreeData(this: &v14);
    }
    idStr::FreeData(this: &v13);
  }
}


// ========================================================================
// __unwind$496373
// EA  : 0x82D70518
// RVA : 0x00D70518
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496373()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$496374
// EA  : 0x82D70540
// RVA : 0x00D70540
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496374()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// Cmd_CloseViewNotes_f
// EA  : 0x82D70570
// RVA : 0x00D70570
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_CloseViewNotes_f(const idCmdArgs *args)
{
  idStr v1; // [sp+50h] [-30h] BYREF

  if ( idGameLocal::GetDebugPlayer(this: gameLocal) != nullptr )
  {
    idStr::idStr(this: &v1, text: &byte_8200D768);
    ShowViewNotes(comments: &v1);
    idStr::FreeData(this: &v1);
  }
}


// ========================================================================
// __unwind$496487
// EA  : 0x82D705CC
// RVA : 0x00D705CC
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496487()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?RandomTest@@YAXH@Z
// EA  : 0x82D705F8
// RVA : 0x00D705F8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RandomTest(signed int trials)
{
  int v2; // ctr
  unsigned int v3; // r5
  double v4; // fp31
  double v5; // fp28
  double v6; // fp27
  double v7; // fp29
  int v8; // r23
  unsigned int v9; // r24
  int v10; // r9
  idRandomMersenne *v11; // r8
  int v12; // r11
  int v13; // r31
  __int64 v14; // r8
  __int64 v15; // r6
  int v16; // r4
  int v17; // r11
  int v18; // r11
  __int64 v19; // r6
  double v20; // r4
  __int128 v21; // r4 OVERLAPPED
  __int64 v22; // r8
  int v23; // r5
  __int64 v24; // r11
  double v25; // fp30
  __int64 v26; // r8
  __int64 v27; // r6
  int v28; // [sp+58h] [-A98h] BYREF
  int v29; // [sp+5Ch] [-A94h]
  unsigned int v30; // [sp+60h] [-A90h]
  int v31; // [sp+68h] [-A88h] BYREF
  int v32; // [sp+6Ch] [-A84h]
  int v33; // [sp+70h] [-A80h]
  __int64 v34; // [sp+78h] [-A78h]
  __int64 v35; // [sp+80h] [-A70h]
  __int64 v36; // [sp+88h] [-A68h]
  idRandomMersenne v37; // [sp+90h] [-A60h] BYREF

  v2 = 623;
  v3 = 1664525 * clientGame->random.seed;
  v31 = 0;
  v4 = 0.0;
  v32 = 0;
  v5 = 0.0;
  v37.index = 0;
  v6 = 0.0;
  v33 = 0;
  v28 = 0;
  v7 = 0.0;
  v29 = 0;
  v30 = 0;
  v8 = -1;
  clientGame->random.seed = v3 + 1013904223;
  v9 = -1;
  v10 = 1;
  v11 = &v37;
  v37.MT[0] = (((v3 + 1013904223) >> 10) & 0x7FFF) % 0x2711;
  do
  {
    v12 = 1812433253 * ((v11->MT[0] >> 30) ^ v11->MT[0]) + v10++;
    v11 = (idRandomMersenne *)((char *)v11 + 4);
    v11->MT[0] = v12;
    --v2;
  }
  while ( v2 != 0 );
  v13 = 0;
  if ( trials > 0 )
  {
    HIDWORD(v14) = v37.index;
    do
    {
      HIDWORD(v15) = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = HIDWORD(v15);
      v16 = (HIDWORD(v15) >> 10) & 0x7FFF;
      v17 = v16 - 3 * ((unsigned __int64)(1431655766LL * v16) >> 32);
      LODWORD(v14) = v17;
      v34 = v14;
      ++*(&v31 + v17);
      v4 = (float)((float)v14 + (float)v4);
      if ( v13 > 0 )
      {
        LODWORD(v15) = (v17 - 1) * (v8 - 1);
        v35 = v15;
        v6 = (float)((float)v15 + (float)v6);
      }
      v8 = v16 % 3;
      if ( HIDWORD(v14) >= 0x270 )
      {
        v37.index = 0;
        idRandomMersenne::GenerateNumbers(this: &v37);
        HIDWORD(v14) = v37.index;
      }
      LODWORD(v14) = v37.MT[HIDWORD(v14)++];
      v37.index = HIDWORD(v14);
      v18 = (((((unsigned int)v14 >> 11) ^ (unsigned int)v14) & 0xFF3A58AD) << 7) ^ ((unsigned int)v14 >> 11) ^ v14;
      HIDWORD(v19) = (((v18 << 15) & 0xEFC60000 ^ v18) >> 18) ^ (v18 << 15) & 0xEFC60000 ^ v18;
      LODWORD(v14) = HIDWORD(v19) % 3;
      v36 = v14;
      ++*(&v28 + HIDWORD(v19) % 3);
      v5 = (float)((float)v14 + (float)v5);
      if ( v13 > 0 )
      {
        LODWORD(v19) = (HIDWORD(v19) % 3 - 1) * (v9 - 1);
        v7 = (float)((float)v19 + (float)v7);
      }
      ++v13;
      v9 = HIDWORD(v19) % 3;
    }
    while ( v13 < trials );
  }
  idLib::Printf(fmt: "Trials: %d\n", trials);
  idLib::Printf(fmt: "\n");
  idLib::Printf(fmt: "Normal random number generator\n");
  v20 = (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, trials)) * (float)v4);
  idLib::Printf(fmt: (const char *)HIDWORD(v20), LODWORD(v20));
  DWORD2(v21) = v31;
  *((double *)&v21 + 1) = (float)((float)((float)*(__int64 *)((char *)&v21 + 4) * (float)100.0)
                                / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  LODWORD(v22) = v32;
  *((double *)&v21 + 1) = (float)((float)((float)v22 * (float)100.0) / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  v23 = v33;
  *((double *)&v21 + 1) = (float)((float)((float)*(__int64 *)((char *)&v21 - 4) * (float)100.0)
                                / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  LODWORD(v24) = trials - 1;
  v25 = (float)((float)1.0 / (float)v24);
  *((double *)&v21 + 1) = (float)((float)((float)1.0 / (float)v24) * (float)v6);
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  idLib::Printf(fmt: "\n");
  idLib::Printf(fmt: "Mersenne twister\n");
  idLib::Printf(fmt: "Average: %f\n", (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, trials)) * (float)v5));
  LODWORD(v26) = v28;
  *((double *)&v21 + 1) = (float)((float)((float)v26 * (float)100.0) / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  LODWORD(v27) = v29;
  *((double *)&v21 + 1) = (float)((float)((float)v27 * (float)100.0) / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  *((double *)&v21 + 1) = (float)((float)((float)__SPAIR64__("2: %5.2f%\n", v30) * (float)100.0)
                                / (float)__SPAIR64__(0x82000000, trials));
  idLib::Printf(fmt: (const char *)DWORD2(v21), (_DWORD)v21);
  idLib::Printf(fmt: "Correlation: %f\n", (float)((float)v25 * (float)v7));
  idLib::Printf(fmt: "\n");
}


// ========================================================================
// ?Cmd_randomTest_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D70AA0
// RVA : 0x00D70AA0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_randomTest_f(const idCmdArgs *args)
{
  signed int v2; // r3
  const char *v3; // r3

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    v2 = 240;
    if ( args->argc > 0 )
    {
      if ( args->argc <= 1 )
        v3 = &byte_8200D768;
      else
        v3 = args->argv[1];
      v2 = atol(nptr: v3);
      if ( v2 <= 0 )
        v2 = 240;
    }
    RandomTest(trials: v2);
  }
}


// ========================================================================
// ?Cmd_SaveFSM_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D70B28
// RVA : 0x00D70B28
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_SaveFSM_f(const idCmdArgs *args)
{
  const char *v2; // r27
  char v3; // r26
  idLinkList<idEntity> *next; // r11
  idAI2 *owner; // r30
  idAI2 *v6; // r29
  idLinkList<idEntity> *v7; // r11
  idFile *v8; // r30
  idFile_vtbl *v9; // r28
  char *filePtr; // r27
  unsigned int v11; // r3
  char *data; // r30
  const char *v13; // r3
  idStr v14; // [sp+60h] [-1B0h] BYREF
  idFile_Memory v15; // [sp+80h] [-190h] BYREF

  v2 = "FSM_alertCycle";
  v3 = 0;
  next = gameLocal->spawnedEntities.next;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    owner = (idAI2 *)next->owner;
    if ( owner != nullptr )
    {
      while ( 1 )
      {
        v6 = idAI2::CastTo(c: owner);
        if ( v6 != nullptr )
          break;
        v7 = owner->spawnNode.next;
        if ( v7 != nullptr && v7 != owner->spawnNode.head )
        {
          owner = (idAI2 *)v7->owner;
          if ( owner != nullptr )
            continue;
        }
        goto LABEL_17;
      }
      v3 = 1;
      idFile_Memory::idFile_Memory(this: &v15, name: "*unknown*");
      v15.__vftable = (idFile_Memory_vtbl *)&idFile_String::`vftable';
      if ( args->argc > 1 )
        v2 = args->argv[1];
      idAI2::SaveFSM(this: v6, file: (idFile_String *)&v15, fsmName: v2, indent: &byte_8200D768);
      idStr::idStr(this: &v14, text: "ai2.fsm");
      if ( args->argc > 2 )
        idStr::operator=(this: &v14, text: args->argv[2]);
      v8 = fileSystem->OpenFileWrite(this: fileSystem, a2: v14.data, a3: 2);
      if ( v8 != nullptr )
      {
        v9 = v8->__vftable;
        filePtr = v15.filePtr;
        v11 = (unsigned __int64)idFile_Memory::Length(this: &v15) >> 32;
        v9->Write(this: v8, a2: filePtr, a3: v11);
        ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
        data = v14.data;
        v13 = fileSystem->GetBasePathStr(this: fileSystem, a2: 2);
        idLib::Printf(fmt: "AI fsm saved to '%s/base/%s'.\n", v13, data);
      }
      else
      {
        idLib::Warning(fmt: "Error creating file '%s'", v14.data);
      }
      idStr::FreeData(this: &v14);
      idFile_Memory::~idFile_Memory(this: &v15);
    }
  }
LABEL_17:
  if ( v3 == 0 )
    idLib::Printf(fmt: "No idAI2 entity is spawned.\n");
}


// ========================================================================
// __unwind$496586
// EA  : 0x82D70D14
// RVA : 0x00D70D14
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496586()
{
  int v0; // r12

  idFile_String::~idFile_String(this: (idFile_String *)(v0 - 528 + 128));
}


// ========================================================================
// __unwind$496587
// EA  : 0x82D70D3C
// RVA : 0x00D70D3C
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496587()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 96));
}


// ========================================================================
// ScriptCmd
// EA  : 0x82D70D70
// RVA : 0x00D70D70
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall ScriptCmd(idEntity *ent, const idCmdArgs *args)
{
  const char *v3; // r3
  const idEventDef *Event; // r3
  idEventDef *v5; // r28
  const char *formatspec; // r29
  int v7; // r24
  int v8; // r20
  int v9; // r25
  int v10; // r23
  idAICover *v11; // r22
  unsigned int v12; // r10
  int v13; // r30
  char *v14; // r11
  int v15; // r10
  float *v16; // r27
  const char **v17; // r28
  int ii; // r29
  const char *v19; // r3
  long double v20; // fp2
  float *v21; // r11
  __int16 *v22; // r10
  int jj; // ctr
  const char *v24; // r3
  int v25; // r3
  int v26; // ctr
  _DWORD *v27; // r11
  __int16 *v28; // r10
  const char *v29; // r4
  const idEntity *v30; // r4
  const char *v31; // r3
  int *v32; // r11
  __int16 *v33; // r10
  int mm; // ctr
  const char *v35; // r3
  long double v36; // fp2
  float *v37; // r11
  __int16 *v38; // r10
  int n; // ctr
  const enumTypeInfo_t *EnumInfo; // r4
  const char *v41; // r5
  const enumValueInfo_t *EnumValueInfo; // r3
  char *v43; // r11
  __int16 *p_coverIndex; // r10
  int i; // ctr
  const char *v46; // r3
  int v47; // r3
  _DWORD *v48; // r11
  __int16 *v49; // r10
  int j; // ctr
  int v51; // r10
  float *v52; // r27
  const char **v53; // r28
  int k; // r29
  const char *v55; // r3
  long double v56; // fp2
  float *v57; // r11
  __int16 *v58; // r10
  int m; // ctr
  char *v60; // r11
  __int16 *v61; // r10
  int kk; // ctr
  const char *v63; // r4
  int v64; // r30
  idDeclInfo *v65; // r3
  idDeclInfo *v66; // r30
  const idDecl *v67; // r3
  int v68; // ctr
  char *v69; // r11
  idAICover *v70; // r10
  const char *v71; // r5
  int v72; // [sp+4Ch] [-2F4h] BYREF
  float x; // [sp+50h] [-2F0h]
  float y; // [sp+54h] [-2ECh]
  float z; // [sp+58h] [-2E8h]
  idEventDef *v76; // [sp+5Ch] [-2E4h]
  const char *v77; // [sp+60h] [-2E0h]
  idStr v78; // [sp+70h] [-2D0h] BYREF
  const char *v79; // [sp+90h] [-2B0h]
  idStr v80; // [sp+A0h] [-2A0h] BYREF
  idStr v81; // [sp+C0h] [-280h] BYREF
  char v82; // [sp+E0h] [-260h]
  void *v83; // [sp+E4h] [-25Ch]
  float v84[8]; // [sp+FCh] [-244h] BYREF
  float v85[9]; // [sp+11Ch] [-224h] BYREF
  idStr v86; // [sp+140h] [-200h] BYREF
  char v87; // [sp+160h] [-1E0h]
  int value; // [sp+164h] [-1DCh]
  float v89[8]; // [sp+17Ch] [-1C4h] BYREF
  _DWORD v90[8]; // [sp+19Ch] [-1A4h] BYREF
  int v91; // [sp+1BCh] [-184h] BYREF
  idEventArg v92; // [sp+1C0h] [-180h] BYREF
  _DWORD v93[9]; // [sp+1DCh] [-164h] BYREF
  idAICover v94; // [sp+200h] [-140h] BYREF
  char v95; // [sp+214h] [-12Ch]
  int v96; // [sp+218h] [-128h]
  char v97; // [sp+228h] [-118h]
  int v98; // [sp+22Ch] [-114h]
  char v99; // [sp+23Ch] [-104h]
  int v100; // [sp+240h] [-100h]
  char v101; // [sp+250h] [-F0h]
  int v102; // [sp+254h] [-ECh]
  char v103; // [sp+264h] [-DCh]
  int v104; // [sp+268h] [-D8h]
  char v105; // [sp+278h] [-C8h]
  int v106; // [sp+27Ch] [-C4h]
  char v107; // [sp+28Ch] [-B4h]
  int v108; // [sp+290h] [-B0h]

  if ( args->argc <= 0 )
    v3 = &byte_8200D768;
  else
    v3 = args->argv[0];
  Event = idEventDef::FindEvent(name: v3);
  v5 = Event;
  v76 = Event;
  if ( Event == nullptr )
  {
    if ( args->argc <= 1 )
      idLib::Warning(fmt: "ai_ScriptCmd unknown event '%s'", &byte_8200D768);
    else
      idLib::Warning(fmt: "ai_ScriptCmd unknown event '%s'", args->argv[1]);
    return;
  }
  formatspec = Event->formatspec;
  HIBYTE(v94.aas) = 0;
  v94.spawnId.value = 0;
  v95 = 0;
  v96 = 0;
  v97 = 0;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  v105 = 0;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v78.len = 0;
  v78.baseBuffer[0] = 0;
  v77 = formatspec;
  v78.allocedAndFlag = 20;
  v78.data = v78.baseBuffer;
  v7 = 1;
  v8 = 0;
  if ( *formatspec == 0 )
  {
LABEL_107:
    idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)&v92, result: ent, ev: v5, args: &v94);
    goto LABEL_108;
  }
  v9 = 2;
  v10 = 4;
  v79 = "int";
  v11 = &v94;
  while ( 1 )
  {
    v12 = (unsigned __int8)formatspec[v8];
    v13 = v7;
    if ( v12 <= 0x66 )
      break;
    switch ( formatspec[v8] )
    {
      case 'i':
        if ( v9 > args->argc )
          idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, (char)v12);
        ++v7;
        ++v10;
        ++v9;
        if ( (unsigned __int8)idEventDef::GetArgTypeName(this: v5, arg: v8, typeName: &v78) != 0
          && idStr::Cmp(s1: v78.data, s2: v79) != 0 )
        {
          EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: v78.data);
          if ( EnumInfo == nullptr )
          {
            idLib::Warning(fmt: "no enum %s", v78.data);
            goto LABEL_108;
          }
          if ( v13 < 0 || v13 >= args->argc )
            v41 = &byte_8200D768;
          else
            v41 = args->argv[v13];
          EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                            this: typeInfoTools,
                            enumInfo: EnumInfo,
                            name: v41,
                            defaultIfNotFound: false);
          if ( EnumValueInfo == nullptr )
          {
            if ( v13 < 0 || v13 >= args->argc )
              v71 = &byte_8200D768;
            else
              v71 = args->argv[v13];
            idLib::Warning(fmt: "no enum or value for %s::%s", v78.data, v71);
            goto LABEL_108;
          }
          v43 = &v86.baseBuffer[16];
          p_coverIndex = &v11[-1].coverIndex;
          value = EnumValueInfo->value;
          v87 = 105;
          for ( i = 5; i != 0; --i )
          {
            v43 += 4;
            p_coverIndex += 2;
            *(_DWORD *)p_coverIndex = *(_DWORD *)v43;
          }
        }
        else
        {
          if ( v13 < 0 || v13 >= args->argc )
            v46 = &byte_8200D768;
          else
            v46 = args->argv[v13];
          v47 = atol(nptr: v46);
          v48 = v93;
          v93[2] = v47;
          HIBYTE(v93[1]) = 105;
          v49 = &v11[-1].coverIndex;
          for ( j = 5; j != 0; --j )
          {
            ++v48;
            v49 += 2;
            *(_DWORD *)v49 = *v48;
          }
        }
        break;
      case 'l':
        idLib::Warning(fmt: "ai_ScriptCmd script list not supported from console right now");
        goto LABEL_108;
      case 's':
        goto LABEL_18;
      case 'v':
        if ( v10 > args->argc )
          idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 3, (char)v12);
        v51 = 4 * (v7 + 1);
        x = vec3_origin.x;
        v7 += 3;
        y = vec3_origin.y;
        v10 += 3;
        z = vec3_origin.z;
        v9 += 3;
        v52 = (float *)&v72;
        v53 = (const char **)((char *)args + v51);
        for ( k = 3; k != 0; --k )
        {
          if ( v13 < 0 || v13 >= args->argc )
            v55 = &byte_8200D768;
          else
            v55 = *v53;
          v56 = atof(nptr: v55);
          *++v52 = *(double *)&v56;
          ++v13;
          ++v53;
        }
        v57 = v84;
        HIBYTE(v84[1]) = 118;
        v84[2] = x;
        v84[3] = y;
        v84[4] = z;
        v58 = &v11[-1].coverIndex;
        for ( m = 5; m != 0; --m )
        {
          ++v57;
          v58 += 2;
          *(float *)v58 = *v57;
        }
        v5 = v76;
        formatspec = v77;
        break;
      case 'x':
        idLib::Warning(fmt: "ai_ScriptCmd var args not supported from console right now");
        goto LABEL_108;
      default:
        break;
    }
LABEL_106:
    ++v8;
    v11 = (idAICover *)((char *)v11 + 20);
    if ( formatspec[v8] == 0 )
      goto LABEL_107;
  }
  if ( v12 == 102 )
  {
    if ( v9 > args->argc )
      idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, 102);
    ++v7;
    ++v10;
    ++v9;
    if ( v13 < 0 || v13 >= args->argc )
      v35 = &byte_8200D768;
    else
      v35 = args->argv[v13];
    v36 = atof(nptr: v35);
    v37 = v89;
    v89[2] = *(double *)&v36;
    HIBYTE(v89[1]) = 102;
    v38 = &v11[-1].coverIndex;
    for ( n = 5; n != 0; --n )
    {
      ++v37;
      v38 += 2;
      *(float *)v38 = *v37;
    }
    goto LABEL_106;
  }
  if ( v12 <= 0x62 )
  {
    if ( v12 == 98 )
    {
      if ( v9 > args->argc )
        idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, 98);
      ++v7;
      ++v10;
      ++v9;
      if ( v13 < 0 || v13 >= args->argc )
        v24 = &byte_8200D768;
      else
        v24 = args->argv[v13];
      v25 = atol(nptr: v24);
      HIBYTE(v90[1]) = 105;
      v90[2] = v25 != 0;
      v26 = 5;
      v27 = v90;
      v28 = &v11[-1].coverIndex;
      do
      {
        ++v27;
        v28 += 2;
        *(_DWORD *)v28 = *v27;
        --v26;
      }
      while ( v26 != 0 );
    }
    else if ( v12 > 0x35 )
    {
      if ( v12 == 97 )
      {
        if ( v10 > args->argc )
          idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 3, 97);
        v15 = 4 * (v7 + 1);
        x = vec3_origin.x;
        v7 += 3;
        y = vec3_origin.y;
        v10 += 3;
        z = vec3_origin.z;
        v9 += 3;
        v16 = (float *)&v72;
        v17 = (const char **)((char *)args + v15);
        for ( ii = 3; ii != 0; --ii )
        {
          if ( v13 < 0 || v13 >= args->argc )
            v19 = &byte_8200D768;
          else
            v19 = *v17;
          v20 = atof(nptr: v19);
          *++v16 = *(double *)&v20;
          ++v13;
          ++v17;
        }
        v21 = v85;
        HIBYTE(v85[1]) = 97;
        v85[2] = x;
        v85[3] = y;
        v85[4] = z;
        v22 = &v11[-1].coverIndex;
        for ( jj = 5; jj != 0; --jj )
        {
          ++v21;
          v22 += 2;
          *(float *)v22 = *v21;
        }
        v5 = v76;
        formatspec = v77;
      }
    }
    else if ( v12 == 53 || v12 >= 0x31 && v12 <= 0x32 )
    {
LABEL_18:
      if ( v9 > args->argc )
        idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, (char)v12);
      ++v7;
      ++v10;
      ++v9;
      if ( v13 < 0 || v13 >= args->argc )
        v14 = &byte_8200D768;
      else
        v14 = args->argv[v13];
      v83 = v14;
      v60 = &v81.baseBuffer[16];
      v82 = 115;
      v61 = &v11[-1].coverIndex;
      for ( kk = 5; kk != 0; --kk )
      {
        v60 += 4;
        v61 += 2;
        *(_DWORD *)v61 = *(_DWORD *)v60;
      }
      HIBYTE(v11->aas) = formatspec[v8];
    }
    goto LABEL_106;
  }
  if ( v12 != 100 )
  {
    if ( v12 == 101 )
    {
      if ( v9 > args->argc )
        idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, 101);
      ++v7;
      ++v10;
      ++v9;
      if ( v13 < 0 || v13 >= args->argc )
        v29 = &byte_8200D768;
      else
        v29 = args->argv[v13];
      v30 = gameLocal->FindEntity(this: gameLocal, a2: v29);
      if ( v30 == nullptr )
      {
        if ( v13 < 0 || v13 >= args->argc )
          v31 = &byte_8200D768;
        else
          v31 = args->argv[v13];
        v30 = gameLocal->entities.ptr[atol(nptr: v31)];
      }
      idEventArg::idEventArg(this: &v92, data: v30);
      v32 = &v91;
      v33 = &v11[-1].coverIndex;
      for ( mm = 5; mm != 0; --mm )
      {
        ++v32;
        v33 += 2;
        *(_DWORD *)v33 = *v32;
      }
    }
    goto LABEL_106;
  }
  if ( v7 + 1 > args->argc )
    idLib::Warning(fmt: "ai_ScriptCmd parm %d expects %d values for %c", v8, 1, 100);
  v81.len = 0;
  v81.baseBuffer[0] = 0;
  v81.data = v81.baseBuffer;
  v81.allocedAndFlag = 20;
  v80.allocedAndFlag = 20;
  v80.data = v80.baseBuffer;
  v80.len = 0;
  v80.baseBuffer[0] = 0;
  if ( v7 < 0 || v7 >= args->argc )
    v63 = &byte_8200D768;
  else
    v63 = args->argv[v7];
  idStr::idStr(this: &v86, text: v63);
  v64 = idStr::Find(str: v86.data, c: 58, start: 0, end: v86.len);
  idStr::Append(this: &v81, text: v86.data, l: v64);
  idStr::Append(this: &v80, text: &v86.data[v64 + 1], l: v86.len - v64);
  idStr::FreeData(this: &v86);
  if ( v80.len != 0 )
  {
    v65 = declManager->GetDeclType(this: declManager, a2: v81.data);
    v66 = v65;
    if ( v65 != nullptr && v80.data != nullptr )
      v67 = idDeclInfo::FindWithInheritance(this: v65, name: v80.data, makeDefault: false);
    else
      v67 = nullptr;
    if ( v66 != nullptr )
    {
      if ( v67 != nullptr )
      {
        v83 = (void *)v67;
        v68 = 5;
        v69 = &v81.baseBuffer[16];
        v82 = 100;
        v70 = (idAICover *)((char *)&v94 + 20 * v8 - 4);
        do
        {
          v69 += 4;
          v70 = (idAICover *)((char *)v70 + 4);
          v70->aas = *(const idAAS2 **)v69;
          --v68;
        }
        while ( v68 != 0 );
        idStr::FreeData(this: &v80);
        idStr::FreeData(this: &v81);
      }
      else
      {
        idLib::Warning(fmt: "ai_ScriptCmd decl '%s' not found", v80.data);
        idStr::FreeData(this: &v80);
        idStr::FreeData(this: &v81);
      }
    }
    else
    {
      idLib::Warning(fmt: "ai_ScriptCmd decl type '%s' not found", v81.data);
      idStr::FreeData(this: &v80);
      idStr::FreeData(this: &v81);
    }
  }
  else
  {
    idLib::Warning(fmt: "ai_ScriptCmd decl parm expects declType:declName");
    idStr::FreeData(this: &v80);
    idStr::FreeData(this: &v81);
  }
LABEL_108:
  idStr::FreeData(this: &v78);
}


// ========================================================================
// $M497249_0
// EA  : 0x82D71748
// RVA : 0x00D71748
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _M497249_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 112));
}


// ========================================================================
// __unwind$496747
// EA  : 0x82D71770
// RVA : 0x00D71770
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496747()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 192));
}


// ========================================================================
// __unwind$496748
// EA  : 0x82D71798
// RVA : 0x00D71798
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496748()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 160));
}


// ========================================================================
// __unwind$496749
// EA  : 0x82D717C0
// RVA : 0x00D717C0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_496749()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 320));
}


// ========================================================================
// Cmd_ai_ScriptCmdEnt_f
// EA  : 0x82D717E8
// RVA : 0x00D717E8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ai_ScriptCmdEnt_f(const idCmdArgs *args)
{
  const char *v2; // r4
  idEntity *v3; // r3
  int argc; // r11
  idEntity *v5; // r27
  int v6; // r31
  const char **v7; // r30
  const char *v8; // r4
  idCmdArgs v9; // [sp+50h] [-940h] BYREF

  if ( args->argc >= 3 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = gameLocal->FindEntity(this: gameLocal, a2: v2);
    argc = args->argc;
    v5 = v3;
    if ( v3 != nullptr )
    {
      v6 = 2;
      v9.argc = 0;
      if ( argc > 2 )
      {
        v7 = (const char **)&args->argv[2];
        do
        {
          if ( v6 < 0 || v6 >= argc )
            v8 = &byte_8200D768;
          else
            v8 = *v7;
          idCmdArgs::AppendArg(this: &v9, text: v8);
          argc = args->argc;
          ++v6;
          ++v7;
        }
        while ( v6 < args->argc );
      }
      ScriptCmd(ent: v5, args: &v9);
    }
    else if ( argc <= 1 )
    {
      idLib::Warning(fmt: "ai_ScriptCmdEnt, entity '%s' not found.", &byte_8200D768);
    }
    else
    {
      idLib::Warning(fmt: "ai_ScriptCmdEnt, entity '%s' not found.", args->argv[1]);
    }
  }
  else
  {
    idLib::Warning(fmt: "ai_ScriptCmdEnt entname func args...");
  }
}


// ========================================================================
// ?Cmd_ListInventory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D71A88
// RVA : 0x00D71A88
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ListInventory_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r31
  idEntity *FocusUsable; // r3
  bfx::Planner3D *v4; // r3
  idInventoryCollection *v5; // r30
  bfx::Space *TypeDef; // r29
  int i; // r31
  idStrId *InventoryItem; // r3
  int index; // r10
  const char *v10; // r27
  const char *v11; // r26
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r3
  idInventoryItem v14; // [sp+50h] [-40h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v2 = DebugPlayer;
    if ( DebugPlayer != nullptr )
    {
      FocusUsable = idPlayer::GetFocusUsable(this: DebugPlayer);
      if ( FocusUsable == nullptr )
        FocusUsable = v2;
      v4 = (bfx::Planner3D *)FocusUsable->GetInventory_2(this: FocusUsable);
      v5 = (idInventoryCollection *)v4;
      if ( v4 != nullptr )
      {
        TypeDef = idScriptObject::GetTypeDef(this: v4);
        idLib::Printf(fmt: "\t[N]\t[localized name]\t[internal name]\t[decl name]\n");
        for ( i = 0; i < (int)TypeDef; ++i )
        {
          InventoryItem = (idStrId *)idInventoryCollection::GetInventoryItem(this: v5, index: i);
          index = InventoryItem[3].index;
          v10 = *(const char **)(index + 8);
          v11 = *(const char **)(index + 172);
          DisplayName = idInventoryItem::GetDisplayName(this: &v14, result: InventoryItem);
          LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
          idLib::Printf(fmt: "\t[%i]\t(%s)\t\t\t\t(%s)\t\t\t\t(%s)\n", i, LocalizedString, v11, v10);
        }
      }
    }
  }
}


// ========================================================================
// ?Cmd_NextAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D71B70
// RVA : 0x00D71B70
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_NextAI_f(const idCmdArgs *args)
{
  idGameLocal *v1; // r11
  idLinkList<idEntity> *next; // r10
  idEntity *owner; // r28
  int value; // r8
  idEntity *v5; // r3
  idEntity *v6; // r30
  idEntity *v7; // r3
  idLinkList<idEntity> *v8; // r11
  idEntity *v9; // r31
  idLinkList<idEntity> *v10; // r11

  v1 = gameLocal;
  next = gameLocal->spawnedEntities.next;
  if ( next == nullptr || next == gameLocal->spawnedEntities.head || (owner = next->owner) == nullptr )
  {
    idLib::Warning(fmt: "'nextAI' failed - no entities spawned.");
    return;
  }
  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v5);
    v6 = v7;
    if ( v7 != nullptr )
    {
      v8 = v7->spawnNode.next;
      if ( v8 == nullptr || v8 == v7->spawnNode.head )
      {
        v1 = gameLocal;
        v9 = nullptr;
      }
      else
      {
        v9 = v8->owner;
        v1 = gameLocal;
      }
      goto LABEL_15;
    }
    v1 = gameLocal;
  }
  else
  {
    v6 = nullptr;
  }
  v9 = owner;
LABEL_15:
  if ( v9 != v6 )
  {
    do
    {
      if ( v9 == nullptr )
        v9 = owner;
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v9) != 0
        && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v9) == 0 )
      {
        break;
      }
      v10 = v9->spawnNode.next;
      if ( v10 == nullptr || v10 == v9->spawnNode.head )
        v9 = nullptr;
      else
        v9 = v10->owner;
    }
    while ( v9 != v6 );
    v1 = gameLocal;
  }
  idGameLocal::SetDebugEntity(this: v1, ent: v9);
  if ( v9 != nullptr )
    idLib::Printf(fmt: "Current AI is: %s\n", v9->name.data);
}


// ========================================================================
// ?Cmd_NextActiveAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D71CE8
// RVA : 0x00D71CE8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_NextActiveAI_f(const idCmdArgs *args)
{
  idGameLocal *v1; // r11
  idLinkList<idEntity> *next; // r10
  idEntity *owner; // r28
  int value; // r8
  idEntity *v5; // r3
  idEntity *v6; // r30
  idEntity *v7; // r3
  idLinkList<idEntity> *v8; // r11
  idEntity *v9; // r31
  idLinkList<idEntity> *v10; // r11

  v1 = gameLocal;
  next = gameLocal->spawnedEntities.next;
  if ( next == nullptr || next == gameLocal->spawnedEntities.head || (owner = next->owner) == nullptr )
  {
    idLib::Warning(fmt: "'nextAI' failed - no entities spawned.");
    return;
  }
  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v5);
    v6 = v7;
    if ( v7 != nullptr )
    {
      v8 = v7->spawnNode.next;
      if ( v8 == nullptr || v8 == v7->spawnNode.head )
      {
        v1 = gameLocal;
        v9 = nullptr;
      }
      else
      {
        v9 = v8->owner;
        v1 = gameLocal;
      }
      goto LABEL_15;
    }
    v1 = gameLocal;
  }
  else
  {
    v6 = nullptr;
  }
  v9 = owner;
LABEL_15:
  if ( v9 != v6 )
  {
    do
    {
      if ( v9 == nullptr )
        v9 = owner;
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v9) != 0
        && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v9) == 0
        && !v9->IsDead(this: v9) )
      {
        break;
      }
      v10 = v9->spawnNode.next;
      if ( v10 == nullptr || v10 == v9->spawnNode.head )
        v9 = nullptr;
      else
        v9 = v10->owner;
    }
    while ( v9 != v6 );
    v1 = gameLocal;
  }
  idGameLocal::SetDebugEntity(this: v1, ent: v9);
  if ( v9 != nullptr )
    idLib::Printf(fmt: "Current AI is: %s\n", v9->name.data);
}


// ========================================================================
// ?Cmd_PrevAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D71E80
// RVA : 0x00D71E80
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_PrevAI_f(const idCmdArgs *args)
{
  idGameLocal *v1; // r11
  idLinkList<idEntity> *prev; // r10
  idEntity *owner; // r28
  int value; // r8
  idEntity *v5; // r3
  idEntity *v6; // r30
  idEntity *v7; // r3
  idLinkList<idEntity> *v8; // r11
  idEntity *v9; // r31
  idLinkList<idEntity> *v10; // r11

  v1 = gameLocal;
  prev = gameLocal->spawnedEntities.prev;
  if ( prev == nullptr || prev == gameLocal->spawnedEntities.head || (owner = prev->owner) == nullptr )
  {
    idLib::Warning(fmt: "'prevAI' failed - no entities spawned.");
    return;
  }
  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v5);
    v6 = v7;
    if ( v7 != nullptr )
    {
      v8 = v7->spawnNode.prev;
      if ( v8 == nullptr || v8 == v7->spawnNode.head )
      {
        v1 = gameLocal;
        v9 = nullptr;
      }
      else
      {
        v9 = v8->owner;
        v1 = gameLocal;
      }
      goto LABEL_15;
    }
    v1 = gameLocal;
  }
  else
  {
    v6 = nullptr;
  }
  v9 = owner;
LABEL_15:
  if ( v9 != v6 )
  {
    do
    {
      if ( v9 == nullptr )
        v9 = owner;
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v9) != 0 )
        break;
      v10 = v9->spawnNode.prev;
      if ( v10 == nullptr || v10 == v9->spawnNode.head )
        v9 = nullptr;
      else
        v9 = v10->owner;
    }
    while ( v9 != v6 );
    v1 = gameLocal;
  }
  idGameLocal::SetDebugEntity(this: v1, ent: v9);
  if ( v9 != nullptr )
    idLib::Printf(fmt: "Current AI is: %s\n", v9->name.data);
}


// ========================================================================
// ?Cmd_KillAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D71FE8
// RVA : 0x00D71FE8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillAI_f(const idCmdArgs *args)
{
  int value; // r8
  idEntity *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r27
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r31
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r6
  idAI2 *v11; // r3
  idAI2 *v12; // r30
  idAICover *p_currentCover; // r30
  idLinkList<idEntity> *v14; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = (idAI2 *)idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    v5 = idAI2::CastTo(c: v4);
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v14->owner )
      {
        v11 = idAI2::CastTo(c: i);
        v12 = v11;
        if ( v11 != nullptr && v11 != v5 )
        {
          idEventReceiver::PostEventMS(this: i, ev: &EV_Remove, time: 0, a4: v10, a5: v9, a6: v8);
          p_currentCover = &v12->aiVolatile.memory.currentCover;
          if ( (unsigned __int8)idAICover::IsValid(this: p_currentCover) != 0 )
            idAICover::Unreserve(this: p_currentCover);
        }
        v14 = i->spawnNode.next;
        if ( v14 == nullptr )
          break;
        if ( v14 == i->spawnNode.head )
          break;
      }
    }
    KillEntities(args, superClass: &idVehicleAI::Type);
  }
}


// ========================================================================
// ?Cmd_KillUnhiddenAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D72130
// RVA : 0x00D72130
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillUnhiddenAI_f(const idCmdArgs *args)
{
  int value; // r8
  idEntity *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r27
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r30
  unsigned __int8 *v8; // r3
  unsigned __int8 *v9; // r31
  __int64 v10; // r10
  __int64 v11; // r8
  int v12; // r6
  idAICover *v13; // r31
  idLinkList<idEntity> *v14; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = (idAI2 *)idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    v5 = idAI2::CastTo(c: v4);
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v14->owner )
      {
        v8 = (unsigned __int8 *)idAI2::CastTo(c: i);
        v9 = v8;
        if ( v8 != nullptr
          && v8 != (unsigned __int8 *)v5
          && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v8) == 0 )
        {
          idEventReceiver::PostEventMS(this: i, ev: &EV_Remove, time: 0, a4: v12, a5: v11, a6: v10);
          v13 = (idAICover *)(v9 + 58196);
          if ( (unsigned __int8)idAICover::IsValid(this: v13) != 0 )
            idAICover::Unreserve(this: v13);
        }
        v14 = i->spawnNode.next;
        if ( v14 == nullptr )
          break;
        if ( v14 == i->spawnNode.head )
          break;
      }
    }
    KillEntities(args, superClass: &idVehicleAI::Type);
  }
}


// ========================================================================
// ?Cmd_KillDeadAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D72288
// RVA : 0x00D72288
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillDeadAI_f(const idCmdArgs *args)
{
  int value; // r8
  idEntity *v2; // r3
  idAI2 *v3; // r3
  idAI2 *v4; // r29
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r31
  idAI2 *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r6
  idLinkList<idEntity> *v11; // r11

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v3 = (idAI2 *)idEntity::CastTo(c: v2);
    }
    else
    {
      v3 = nullptr;
    }
    v4 = idAI2::CastTo(c: v3);
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v11->owner )
      {
        v7 = idAI2::CastTo(c: i);
        if ( v7 != nullptr && v7 != v4 )
        {
          HIDWORD(v8) = v7->IsDead(this: v7);
          if ( HIDWORD(v8) != 0 )
            idEventReceiver::PostEventMS(this: i, ev: &EV_Remove, time: 0, a4: v10, a5: v9, a6: v8);
        }
        v11 = i->spawnNode.next;
        if ( v11 == nullptr )
          break;
        if ( v11 == i->spawnNode.head )
          break;
      }
    }
  }
}


// ========================================================================
// ?Cmd_KillDebugTarget_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D723B0
// RVA : 0x00D723B0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillDebugTarget_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r30
  __int64 v2; // r10
  __int64 v3; // r8
  int v4; // r6
  idEntity *v5; // r3
  idAI2 *v6; // r31
  idAI2 *v7; // r3
  idAICover *p_currentCover; // r31

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    LODWORD(v3) = gameLocal->debugEntity.spawnId.value;
    v2 = v3 & 0x1FFF | 0x15D3AC00000000LL;
    HIDWORD(v3) = (int)v3 >> 13;
    v4 = v2 + 29755;
    if ( gameLocal->spawnIds.ptr[v2] == (int)v3 >> 13
      && (LODWORD(v2) = v2 + 21563, HIDWORD(v2) = 4 * v2, (v5 = *((idEntity **)&gameLocal->__vftable + v2)) != nullptr) )
    {
      v6 = (idAI2 *)idEntity::CastTo(c: v5);
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != (idAI2 *)DebugPlayer && v6 != nullptr )
    {
      idEventReceiver::PostEventMS(this: v6, ev: &EV_Remove, time: 0, a4: v4, a5: v3, a6: v2);
      v7 = idAI2::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        p_currentCover = &v7->aiVolatile.memory.currentCover;
        if ( (unsigned __int8)idAICover::IsValid(this: &v7->aiVolatile.memory.currentCover) != 0 )
          idAICover::Unreserve(this: p_currentCover);
      }
    }
  }
}


// ========================================================================
// ?Cmd_SelectDebugEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D724B0
// RVA : 0x00D724B0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_SelectDebugEntity_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  int v2; // r9
  idGameLocal *v3; // r11
  idEntity *v4; // r3
  idEntity *v5; // r3
  idEntity *v6; // r31

  if ( !common->IsMultiplayer(this: common) )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr )
    {
      v2 = *(_DWORD *)(idPlayer::GetFocusTracker(this: DebugPlayer) + 76);
      v3 = gameLocal;
      if ( gameLocal->spawnIds.ptr[v2 & 0x1FFF] == v2 >> 13 && (v4 = gameLocal->entities.ptr[v2 & 0x1FFF]) != nullptr )
      {
        v5 = idEntity::CastTo(c: v4);
        v3 = gameLocal;
        v6 = v5;
      }
      else
      {
        v6 = nullptr;
      }
      idGameLocal::SetDebugEntity(this: v3, ent: v6);
      if ( v6 != nullptr )
        idLib::Printf(fmt: "Selected entity '%s' (%d) as debug target.\n", v6->name.data, v6->entityNumber);
      else
        idLib::Printf(fmt: "Cleared debug target.\n");
    }
  }
}


// ========================================================================
// ScriptFunctionArgs
// EA  : 0x82D725B0
// RVA : 0x00D725B0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall ScriptFunctionArgs(idAutoComplete *autoComplete)
{
  idStr *v2; // r10
  idCmdArgs *p_args; // r24
  const char *v4; // r3
  int v5; // r26
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  const char *v9; // r4
  idAI2 *v10; // r23
  int v11; // r25
  const char *v12; // r3
  const idEventDef *Event; // r30
  signed int ii; // r30
  const idEventDef *EventCommand; // r3
  int i; // r29
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  va *v20; // r3
  unsigned int v21; // r11
  idAI2 *v22; // r3
  const idDeclAnimWeb *decl; // r29
  int n; // r30
  idDeclAnimWebNode *v25; // r3
  int k; // r28
  idDeclInfo *v27; // r29
  int m; // r30
  idResource *v29; // r3
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v35; // r29
  int v36; // r30
  const char *j; // r4
  int v38; // [sp+8h] [-11B8h]
  int v39; // [sp+Ch] [-11B4h]
  int v40; // [sp+10h] [-11B0h]
  int v41; // [sp+14h] [-11ACh]
  int v42; // [sp+18h] [-11A8h]
  int v43; // [sp+1Ch] [-11A4h]
  idStr v44; // [sp+50h] [-1170h] BYREF
  idStr v45; // [sp+70h] [-1150h] BYREF
  int argc; // [sp+90h] [-1130h]
  idStr v47; // [sp+A0h] [-1120h] BYREF
  idStr v48; // [sp+C0h] [-1100h] BYREF
  idStr v49; // [sp+E0h] [-10E0h] BYREF
  idStr v50; // [sp+100h] [-10C0h] BYREF
  idStr v51; // [sp+120h] [-10A0h] BYREF
  idStr v52; // [sp+140h] [-1080h] BYREF
  va v53; // [sp+160h] [-1060h] BYREF

  p_args = &autoComplete->args;
  v2 = idStr::idStr(this: &v52, text: "ai_ScriptCmdEnt");
  if ( autoComplete->args.argc <= 0 )
    v4 = &byte_8200D768;
  else
    v4 = autoComplete->args.argv[0];
  v5 = ((_cntlzw(idStr::Cmp(s1: v4, s2: v2->data)) & 0x20) != 0) + 1;
  idStr::FreeData(this: &v52);
  if ( v5 == 2 )
  {
    if ( p_args->argc == 2 )
    {
      idGameLocal::ArgCompletion_EntityName(autoComplete);
      return;
    }
    if ( p_args->argc <= 1 )
      v9 = &byte_8200D768;
    else
      v9 = autoComplete->args.argv[1];
    v8 = gameLocal->FindEntity(this: gameLocal, a2: v9);
  }
  else
  {
    if ( v5 != 1 )
      return;
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
  }
  v10 = (idAI2 *)v8;
  if ( v8 != nullptr )
  {
    v11 = p_args->argc - v5 - 2;
    argc = p_args->argc;
    if ( v5 >= argc )
      v12 = &byte_8200D768;
    else
      v12 = p_args->argv[v5];
    Event = idEventDef::FindEvent(name: v12);
    if ( Event != nullptr )
    {
      idStr::idStr(this: &v48, text: Event->name);
      idStr::Append(this: &v48, text: "( ");
      for ( i = 0; i < Event->numargs; ++i )
      {
        v44.allocedAndFlag = 20;
        v44.len = 0;
        v44.data = v44.baseBuffer;
        v44.baseBuffer[0] = 0;
        LODWORD(v17) = (unsigned __int8)idEventDef::GetArgTypeName(this: Event, arg: i, typeName: &v44);
        if ( (_DWORD)v17 != 0 )
        {
          HIDWORD(v19) = v44.data;
          v20 = va::va(
                  this: &v53,
                  fmt: "%s ",
                  a3: v19,
                  a4: v18,
                  a5: v17,
                  a6: v38,
                  a7: v39,
                  a8: v40,
                  a9: v41,
                  a10: v42,
                  a11: v43);
          idStr::Append(this: &v48, text: v20);
        }
        idStr::FreeData(this: &v44);
      }
      idStr::Append(this: &v48, text: ")\n");
      idLib::Printf(fmt: v48.data);
      if ( p_args->argc > v5 && v11 < Event->numargs )
      {
        v47.allocedAndFlag = 20;
        v47.len = 0;
        v47.data = v47.baseBuffer;
        v47.baseBuffer[0] = 0;
        v21 = (unsigned __int8)Event->formatspec[v11];
        if ( v21 > 0x64 )
        {
          if ( v21 == 101 )
          {
            idGameLocal::ArgCompletion_EntityName(autoComplete);
          }
          else if ( v21 == 105
                 && (unsigned __int8)idEventDef::GetArgTypeName(this: Event, arg: v11, typeName: &v47) != 0 )
          {
            EnumInfo = idTypeInfoTools::FindEnumInfo(this: typeInfoTools, typeName: v47.data);
            v35 = EnumInfo;
            if ( EnumInfo != nullptr )
            {
              v36 = 0;
              for ( j = EnumInfo->values->name; j != nullptr; j = v35->values[v36].name )
              {
                idStr::idStr(this: &v49, text: j);
                idAutoComplete::Append(this: autoComplete, suggestion: &v49, completingArg: -1);
                idStr::FreeData(this: &v49);
                ++v36;
              }
            }
          }
        }
        else
        {
          switch ( v21 )
          {
            case 'd':
              for ( k = 0; k < declManager->GetNumDeclTypes(this: declManager); ++k )
              {
                v27 = declManager->GetDeclType_2(this: declManager, a2: k);
                for ( m = 0; m < v27->num; ++m )
                {
                  v29 = idResourceList::Index(this: v27, index: m);
                  HIDWORD(v30) = v27->name;
                  LODWORD(v30) = v29->name.str;
                  v33 = va::va(
                          this: &v53,
                          fmt: "%s:%s",
                          a3: v30,
                          a4: v32,
                          a5: v31,
                          a6: v38,
                          a7: v39,
                          a8: v40,
                          a9: v41,
                          a10: v42,
                          a11: v43);
                  idStr::idStr(this: &v51, text: v33);
                  idAutoComplete::Append(this: autoComplete, suggestion: &v51, completingArg: -1);
                  idStr::FreeData(this: &v51);
                }
              }
              break;
            case '1':
              v22 = idAI2::CastTo(c: v10);
              if ( v22 != nullptr )
              {
                decl = v22->aiVolatile.animation.animWebAnimator.ptr[0].decl;
                if ( decl != nullptr )
                {
                  for ( n = 0; n < decl->nodes.num; ++n )
                  {
                    if ( (__int16)n == -1 )
                      v25 = nullptr;
                    else
                      v25 = decl->nodes.list[(__int16)n];
                    v45.allocedAndFlag = 20;
                    v45.len = 0;
                    v45.data = v45.baseBuffer;
                    v45.baseBuffer[0] = 0;
                    idDeclAnimWebNode::GetPath(this: v25, web: decl, path: (idAnimWebPath *)&v45);
                    idAutoComplete::Append(this: autoComplete, suggestion: &v45, completingArg: -1);
                    idStr::FreeData(this: &v45);
                  }
                }
              }
              break;
            case 'b':
              idCmdSystem::ArgCompletion_Boolean(autoComplete);
              break;
            default:
              break;
          }
        }
        idStr::FreeData(this: &v47);
      }
      idStr::FreeData(this: &v48);
    }
    else
    {
      for ( ii = 0; ii < idEventDef::GetNumEvents(); ++ii )
      {
        EventCommand = idEventDef::GetEventCommand(eventnum: ii);
        idStr::idStr(this: &v50, text: EventCommand->name);
        idAutoComplete::Append(this: autoComplete, suggestion: &v50, completingArg: -1);
        idStr::FreeData(this: &v50);
      }
    }
  }
}


// ========================================================================
// __unwind$498659
// EA  : 0x82D72AB4
// RVA : 0x00D72AB4
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498659()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 320));
}


// ========================================================================
// __unwind$498660
// EA  : 0x82D72ADC
// RVA : 0x00D72ADC
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498660()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 256));
}


// ========================================================================
// __unwind$498661
// EA  : 0x82D72B04
// RVA : 0x00D72B04
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498661()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 192));
}


// ========================================================================
// __unwind$498662
// EA  : 0x82D72B2C
// RVA : 0x00D72B2C
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498662()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 80));
}


// ========================================================================
// __unwind$498663
// EA  : 0x82D72B54
// RVA : 0x00D72B54
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498663()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 160));
}


// ========================================================================
// __unwind$498666
// EA  : 0x82D72B7C
// RVA : 0x00D72B7C
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 112));
}


// ========================================================================
// __unwind$498665
// EA  : 0x82D72BA4
// RVA : 0x00D72BA4
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498665()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 288));
}


// ========================================================================
// __unwind$498664
// EA  : 0x82D72BCC
// RVA : 0x00D72BCC
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_498664()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4544 + 224));
}


// ========================================================================
// Cmd_ai_ScriptCmd_f
// EA  : 0x82D72BF8
// RVA : 0x00D72BF8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ai_ScriptCmd_f(const idCmdArgs *args)
{
  int value; // r9
  idEntity *v3; // r3
  int argc; // r11
  int v5; // r31
  bool v6; // zf
  const char **v7; // r30
  const char *v8; // r4
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  idCmdArgs v12; // [sp+50h] [-940h] BYREF

  if ( args->argc >= 2 )
  {
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v3) != nullptr )
    {
      argc = args->argc;
      v5 = 1;
      v6 = args->argc <= 1;
      v12.argc = 0;
      if ( !v6 )
      {
        v7 = (const char **)&args->argv[1];
        do
        {
          if ( v5 < 0 || v5 >= argc )
            v8 = &byte_8200D768;
          else
            v8 = *v7;
          idCmdArgs::AppendArg(this: &v12, text: v8);
          argc = args->argc;
          ++v5;
          ++v7;
        }
        while ( v5 < args->argc );
      }
      v9 = gameLocal->debugEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        ScriptCmd(ent: v11, args: &v12);
      }
      else
      {
        ScriptCmd(ent: nullptr, args: &v12);
      }
    }
    else
    {
      idLib::Warning(fmt: "ai_ScriptCmd, no debug AI is selected.");
    }
  }
  else
  {
    idLib::Warning(fmt: "ai_ScriptCmd func args...");
  }
}


// ========================================================================
// ?Cmd_ai_MoveToFacingReticule_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D72D48
// RVA : 0x00D72D48
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Cmd_ai_MoveToFacingReticule_f(const idCmdArgs *args)
{
  int value; // r9
  idEntity *v2; // r3
  idAI2 *v3; // r3
  idAI2 *v4; // r31
  idPlayer *Player; // r3
  double y; // fp0
  double x; // fp13
  double v8; // fp12
  double z; // fp11
  idEventArg *v10; // r30
  int v11; // r8 OVERLAPPED
  __int128 v12; // r7 OVERLAPPED
  int v13; // [sp+8h] [-328h]
  const idEventArg *v14; // [sp+8h] [-328h]
  bool v15; // [sp+Fh] [-321h]
  const char *v16; // [sp+10h] [-320h]
  __int64 v17; // [sp+10h] [-320h]
  int v18; // [sp+14h] [-31Ch]
  int v19; // [sp+18h] [-318h]
  __int64 v20; // [sp+18h] [-318h]
  int v21; // [sp+1Ch] [-314h]
  int v22; // [sp+20h] [-310h]
  __int64 v23; // [sp+20h] [-310h]
  int v24; // [sp+24h] [-30Ch]
  int v25; // [sp+28h] [-308h]
  __int64 v26; // [sp+28h] [-308h]
  int v27; // [sp+2Ch] [-304h]
  int v28; // [sp+30h] [-300h]
  __int64 v29; // [sp+30h] [-300h]
  int v30; // [sp+34h] [-2FCh]
  int v31; // [sp+38h] [-2F8h]
  __int64 v32; // [sp+38h] [-2F8h]
  int v33; // [sp+3Ch] [-2F4h]
  int v34; // [sp+40h] [-2F0h]
  __int64 v35; // [sp+40h] [-2F0h]
  int v36; // [sp+44h] [-2ECh]
  int v37; // [sp+48h] [-2E8h]
  __int64 v38; // [sp+48h] [-2E8h]
  int v39; // [sp+4Ch] [-2E4h]
  int v40; // [sp+50h] [-2E0h]
  __int64 v41; // [sp+50h] [-2E0h]
  int entityNumber; // [sp+54h] [-2DCh]
  int v43; // [sp+58h] [-2D8h]
  __int64 v44; // [sp+58h] [-2D8h]
  int v45; // [sp+60h] [-2D0h]
  int arg5; // [sp+64h] [-2CCh]
  int arg5_4; // [sp+68h] [-2C8h]
  int arg5_8; // [sp+6Ch] [-2C4h]
  int arg5_12[8]; // [sp+70h] [-2C0h] BYREF
  int v50[8]; // [sp+90h] [-2A0h] BYREF
  int v51[8]; // [sp+B0h] [-280h] BYREF
  _BYTE v52[20]; // [sp+D0h] [-260h] BYREF
  _BYTE v53[20]; // [sp+F0h] [-240h] BYREF
  idVec3 v54[2]; // [sp+110h] [-220h] BYREF
  idVec3 v55[2]; // [sp+130h] [-200h] BYREF
  idVec3 v56; // [sp+148h] [-1E8h] BYREF
  idVec3 v57; // [sp+158h] [-1D8h] BYREF
  idMat3 v58; // [sp+170h] [-1C0h] BYREF
  float v59[5]; // [sp+1A0h] [-190h] BYREF
  char v60; // [sp+1C0h] [-170h]
  int v61; // [sp+1C4h] [-16Ch]
  __int64 v62; // [sp+1C8h] [-168h]
  int v63; // [sp+1D0h] [-160h]
  _DWORD v64[5]; // [sp+1E0h] [-150h] BYREF
  _DWORD v65[5]; // [sp+200h] [-130h] BYREF
  idEventArg v66; // [sp+220h] [-110h] BYREF
  idEventReceiver v67[2]; // [sp+240h] [-F0h] BYREF
  trace_t v68; // [sp+260h] [-D0h] BYREF

  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v3 = (idAI2 *)idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  v4 = idAI2::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    Player->GetViewTransform(this: Player, a2: &v56, a3: &v58);
    entityNumber = idGameLocal::GetPlayer(this: gameLocal, i: 0)->entityNumber;
    v57.x = v56.x + (float)(v58.mat[0].x * (float)9000.0);
    v57.y = v56.y + (float)(v58.mat[0].y * (float)9000.0);
    v57.z = v56.z + (float)(v58.mat[0].z * (float)9000.0);
    idClip::Translation(
      this: (idClip *)v54,
      result: &clientGame->clip,
      a3: &v68,
      start: &v56,
      end: &v57,
      clipModel: nullptr,
      startAxis: &v58,
      clipMask: 1,
      passEntityNumber: v13,
      moveClipModel: v15,
      userName: v16,
      a12: v18,
      a13: v19,
      a14: v21,
      a15: v22,
      a16: v24,
      a17: v25,
      a18: v27,
      a19: v28,
      a20: v30,
      a21: v31,
      a22: v33,
      a23: v34,
      a24: v36,
      a25: v37,
      a26: v39,
      a27: v40,
      a28: entityNumber,
      a29: v43,
      a30: false,
      a31: v45,
      a32: 0);
    v54[0] = v58.mat[0];
    v55[0].z = 1.0;
    v55[0].x = 0.0;
    v55[0].y = 0.0;
    idVec3::ProjectOntoPlane(this: v54, normal: v55, overBounce: 1.0);
    idAI2::ForceFSMIntoExecutingCodeAction(this: v4, action: &ACTION_MoveToPointEnter);
    y = v54[0].y;
    x = v68.endpos.x;
    v8 = v68.endpos.y;
    z = v68.endpos.z;
    v55[0].y = v54[0].x;
    v4->aiVolatile.fsms.actionManager.actionEventTransCode = 6;
    v55[0].z = y;
    v55[1].x = v54[0].z;
    v54[0].y = x;
    v54[0].z = v8;
    v54[1].x = z;
    HIBYTE(v55[0].x) = 118;
    v59[1] = 0.1;
    HIBYTE(v64[0]) = 105;
    v64[1] = 1;
    HIBYTE(v59[0]) = 102;
    HIBYTE(v65[0]) = 105;
    v65[1] = 2;
    HIBYTE(v54[0].x) = 118;
    v60 = 105;
    v61 = 0;
    v10 = idEventArg::idEventArg(this: &v66, data: v4);
    memcpy(Dst: v53, Src: v55, Size: sizeof(v53));
    memcpy(Dst: v52, Src: v64, Size: sizeof(v52));
    memcpy(Dst: v51, Src: v59, Size: 0x14u);
    memcpy(Dst: v50, Src: v65, Size: 0x14u);
    memcpy(Dst: arg5_12, Src: v54, Size: 0x14u);
    v11 = __ROL4__(LODWORD(v10->value.q[3]), 32);
    *(_QWORD *)((char *)&v12 + 4) = *(_QWORD *)&v10->type;
    *((_QWORD *)&v12 + 1) = *(_QWORD *)&v10->value.q[1];
    idEventReceiver::ProcessEvent(
      this: v67,
      result: &v4->aiVolatile.fsms.actionManager,
      arg1: *(__int64 *)((char *)&v12 + 4),
      arg3: *(__int64 *)&v11,
      arg5: v62,
      arg6: v14,
      a7: v17,
      a8: v20,
      a9: v23,
      a10: v26,
      a11: v29,
      a12: v32,
      a13: v35,
      a14: v38,
      a15: v41,
      a16: v44,
      a17: v63,
      a18: arg5,
      a19: arg5_4,
      a20: arg5_8,
      a21: arg5_12[0],
      a22: arg5_12[1],
      arg3a: arg5_12[2],
      arg3_4: arg5_12[3],
      arg3_8: arg5_12[4],
      arg3_12: arg5_12[5],
      arg3_16: arg5_12[6],
      a28: arg5_12[7],
      arg4: v50[0],
      arg4_4: v50[1],
      arg4_8: v50[2],
      arg4_12: v50[3],
      arg4_16: v50[4],
      a34: v50[5],
      arg5a: v50[6],
      arg5_4: v50[7],
      arg5_8: v51[0]);
  }
}


// ========================================================================
// ?Cmd_ai_MoveToFacingPlayer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D72FF0
// RVA : 0x00D72FF0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Cmd_ai_MoveToFacingPlayer_f(const idCmdArgs *args)
{
  int value; // r9
  idEntity *v2; // r3
  idAI2 *v3; // r3
  idAI2 *v4; // r31
  idPlayer *Player; // r3
  double z; // fp13
  double v7; // fp12
  double x; // fp10
  double y; // fp9
  double v10; // fp11
  double v11; // fp8
  idEventArg *v12; // r30
  int v13; // r8 OVERLAPPED
  __int128 v14; // r7 OVERLAPPED
  int v15; // [sp+8h] [-328h]
  const idEventArg *v16; // [sp+8h] [-328h]
  bool v17; // [sp+Fh] [-321h]
  const char *v18; // [sp+10h] [-320h]
  __int64 v19; // [sp+10h] [-320h]
  int v20; // [sp+14h] [-31Ch]
  int v21; // [sp+18h] [-318h]
  __int64 v22; // [sp+18h] [-318h]
  int v23; // [sp+1Ch] [-314h]
  int v24; // [sp+20h] [-310h]
  __int64 v25; // [sp+20h] [-310h]
  int v26; // [sp+24h] [-30Ch]
  int v27; // [sp+28h] [-308h]
  __int64 v28; // [sp+28h] [-308h]
  int v29; // [sp+2Ch] [-304h]
  int v30; // [sp+30h] [-300h]
  __int64 v31; // [sp+30h] [-300h]
  int v32; // [sp+34h] [-2FCh]
  int v33; // [sp+38h] [-2F8h]
  __int64 v34; // [sp+38h] [-2F8h]
  int v35; // [sp+3Ch] [-2F4h]
  int v36; // [sp+40h] [-2F0h]
  __int64 v37; // [sp+40h] [-2F0h]
  int v38; // [sp+44h] [-2ECh]
  int v39; // [sp+48h] [-2E8h]
  __int64 v40; // [sp+48h] [-2E8h]
  int v41; // [sp+4Ch] [-2E4h]
  int v42; // [sp+50h] [-2E0h]
  __int64 v43; // [sp+50h] [-2E0h]
  int entityNumber; // [sp+54h] [-2DCh]
  int v45; // [sp+58h] [-2D8h]
  __int64 v46; // [sp+58h] [-2D8h]
  int v47; // [sp+60h] [-2D0h]
  int arg5; // [sp+64h] [-2CCh]
  int arg5_4; // [sp+68h] [-2C8h]
  int arg5_8; // [sp+6Ch] [-2C4h]
  int arg5_12[8]; // [sp+70h] [-2C0h] BYREF
  int v52[8]; // [sp+90h] [-2A0h] BYREF
  int v53[8]; // [sp+B0h] [-280h] BYREF
  _BYTE v54[20]; // [sp+D0h] [-260h] BYREF
  _BYTE v55[20]; // [sp+F0h] [-240h] BYREF
  idVec3 v56[2]; // [sp+110h] [-220h] BYREF
  idVec3 v57[2]; // [sp+130h] [-200h] BYREF
  idVec3 v58; // [sp+148h] [-1E8h] BYREF
  idVec3 v59; // [sp+158h] [-1D8h] BYREF
  idMat3 v60; // [sp+170h] [-1C0h] BYREF
  float v61[5]; // [sp+1A0h] [-190h] BYREF
  char v62; // [sp+1C0h] [-170h]
  int v63; // [sp+1C4h] [-16Ch]
  __int64 v64; // [sp+1C8h] [-168h]
  int v65; // [sp+1D0h] [-160h]
  _DWORD v66[5]; // [sp+1E0h] [-150h] BYREF
  _DWORD v67[5]; // [sp+200h] [-130h] BYREF
  idEventArg v68; // [sp+220h] [-110h] BYREF
  idEventReceiver v69[2]; // [sp+240h] [-F0h] BYREF
  trace_t v70; // [sp+260h] [-D0h] BYREF

  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v3 = (idAI2 *)idEntity::CastTo(c: v2);
  }
  else
  {
    v3 = nullptr;
  }
  v4 = idAI2::CastTo(c: v3);
  if ( v4 != nullptr )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    Player->GetViewTransform(this: Player, a2: &v58, a3: &v60);
    entityNumber = idGameLocal::GetPlayer(this: gameLocal, i: 0)->entityNumber;
    v59.x = v58.x + (float)(v60.mat[0].x * (float)9000.0);
    v59.y = v58.y + (float)(v60.mat[0].y * (float)9000.0);
    v59.z = v58.z + (float)(v60.mat[0].z * (float)9000.0);
    idClip::Translation(
      this: (idClip *)v56,
      result: &clientGame->clip,
      a3: &v70,
      start: &v58,
      end: &v59,
      clipModel: nullptr,
      startAxis: &v60,
      clipMask: 1,
      passEntityNumber: v15,
      moveClipModel: v17,
      userName: v18,
      a12: v20,
      a13: v21,
      a14: v23,
      a15: v24,
      a16: v26,
      a17: v27,
      a18: v29,
      a19: v30,
      a20: v32,
      a21: v33,
      a22: v35,
      a23: v36,
      a24: v38,
      a25: v39,
      a26: v41,
      a27: v42,
      a28: entityNumber,
      a29: v45,
      a30: false,
      a31: v47,
      a32: 0);
    v56[0] = v60.mat[0];
    v57[0].z = 1.0;
    v57[0].x = 0.0;
    v57[0].y = 0.0;
    idVec3::ProjectOntoPlane(this: v56, normal: v57, overBounce: 1.0);
    idAI2::ForceFSMIntoExecutingCodeAction(this: v4, action: &ACTION_MoveToPointEnter);
    z = v56[0].z;
    v7 = -v56[0].x;
    x = v70.endpos.x;
    y = v70.endpos.y;
    v10 = -v56[0].y;
    v11 = v70.endpos.z;
    v4->aiVolatile.fsms.actionManager.actionEventTransCode = 6;
    v56[0].y = x;
    v57[0].y = v7;
    v57[0].z = v10;
    v57[1].x = -z;
    HIBYTE(v57[0].x) = 118;
    v56[0].z = y;
    v56[1].x = v11;
    HIBYTE(v66[0]) = 105;
    v61[1] = 0.1;
    v66[1] = 1;
    HIBYTE(v61[0]) = 102;
    HIBYTE(v67[0]) = 105;
    v67[1] = 2;
    HIBYTE(v56[0].x) = 118;
    v62 = 105;
    v63 = 0;
    v12 = idEventArg::idEventArg(this: &v68, data: v4);
    memcpy(Dst: v55, Src: v57, Size: sizeof(v55));
    memcpy(Dst: v54, Src: v66, Size: sizeof(v54));
    memcpy(Dst: v53, Src: v61, Size: 0x14u);
    memcpy(Dst: v52, Src: v67, Size: 0x14u);
    memcpy(Dst: arg5_12, Src: v56, Size: 0x14u);
    v13 = __ROL4__(LODWORD(v12->value.q[3]), 32);
    *(_QWORD *)((char *)&v14 + 4) = *(_QWORD *)&v12->type;
    *((_QWORD *)&v14 + 1) = *(_QWORD *)&v12->value.q[1];
    idEventReceiver::ProcessEvent(
      this: v69,
      result: &v4->aiVolatile.fsms.actionManager,
      arg1: *(__int64 *)((char *)&v14 + 4),
      arg3: *(__int64 *)&v13,
      arg5: v64,
      arg6: v16,
      a7: v19,
      a8: v22,
      a9: v25,
      a10: v28,
      a11: v31,
      a12: v34,
      a13: v37,
      a14: v40,
      a15: v43,
      a16: v46,
      a17: v65,
      a18: arg5,
      a19: arg5_4,
      a20: arg5_8,
      a21: arg5_12[0],
      a22: arg5_12[1],
      arg3a: arg5_12[2],
      arg3_4: arg5_12[3],
      arg3_8: arg5_12[4],
      arg3_12: arg5_12[5],
      arg3_16: arg5_12[6],
      a28: arg5_12[7],
      arg4: v52[0],
      arg4_4: v52[1],
      arg4_8: v52[2],
      arg4_12: v52[3],
      arg4_16: v52[4],
      a34: v52[5],
      arg5a: v52[6],
      arg5_4: v52[7],
      arg5_8: v53[0]);
  }
}


// ========================================================================
// ?Cmd_EntityListTypes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D733C8
// RVA : 0x00D733C8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_EntityListTypes_f(const idCmdArgs *args)
{
  __int64 v1; // kr00_8
  int i; // r16
  int v3; // r26
  int v4; // r11
  const char *v5; // r4
  char v6; // r28
  int v7; // r30
  int v8; // r29
  int v9; // r30
  __int128 v10; // r5
  idStr *v11; // r3
  idStr *v12; // r30
  unsigned int allocedAndFlag; // r11
  size_t len; // r29
  int v15; // r4
  int v16; // r11
  bool v17; // zf
  __int64 v18; // r7
  const char *v19; // r7
  int v20; // r29
  int j; // r30
  __int128 v22; // r6
  idSort_Quick<entityListType_t *,idSort_EntityType> v23; // [sp+50h] [-E0h] BYREF
  idStr *v24; // [sp+54h] [-DCh] BYREF
  idList<enum encounterGroupRole_t,5> v25; // [sp+60h] [-D0h] BYREF
  idStr v26[6]; // [sp+70h] [-C0h] BYREF

  memset(&v25, 0, 14);
  *(_WORD *)&v25.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
  v1 = *(_QWORD *)&v25.list;
  for ( i = 86252; i < 119020; i += 4 )
  {
    v3 = *(int *)((char *)&gameLocal->__vftable + i);
    if ( v3 != 0 )
    {
      v4 = *(_DWORD *)(v3 + 496);
      v5 = "*unknown*";
      if ( v4 != 0 )
        v5 = *(const char **)(v4 + 8);
      idStr::idStr(this: v26, text: v5);
      v6 = 0;
      v7 = 0;
      if ( (int)v1 > 0 )
      {
        v8 = HIDWORD(v1);
        while ( idStr::Icmp(s1: *(const char **)(*(_DWORD *)v8 + 4), s2: v26[0].data) != 0 )
        {
          ++v7;
          v8 += 4;
          if ( v7 >= (int)v1 )
            goto LABEL_11;
        }
        ++*(_DWORD *)(*(_DWORD *)(4 * v7 + HIDWORD(v1)) + 40);
        v9 = *(_DWORD *)(4 * v7 + HIDWORD(v1));
        *(_QWORD *)((char *)&v10 + 4) = ((__int64 (__fastcall *)(int))**(_DWORD **)v3)(a1: v3);
        v6 = 1;
        LODWORD(v10) = *(_DWORD *)(DWORD1(v10) + 32) + *(_DWORD *)(v9 + 36);
        *(_QWORD *)(v9 + 32) = v10;
      }
LABEL_11:
      if ( v6 == 0 )
      {
        v11 = (idStr *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x30u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
        {
          v11->allocedAndFlag = 20;
          v11->len = 0;
          v12 = v11;
          v11->data = v11->baseBuffer;
          v11->baseBuffer[0] = 0;
        }
        else
        {
          v12 = nullptr;
        }
        allocedAndFlag = v12->allocedAndFlag;
        len = v26[0].len;
        v24 = v12;
        v15 = v26[0].len + 1;
        v17 = allocedAndFlag >> 31 == 0;
        v16 = allocedAndFlag & 0x7FFFFFFF;
        if ( v17 )
        {
          if ( v15 > v16 )
            idStr::ReAllocate(this: v12, amount: v15, keepold: false);
        }
        else if ( v15 > v16
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v12->data, Src: v26[0].data, Size: len);
        v12->data[len] = 0;
        v12->len = len;
        LODWORD(v18) = *(_DWORD *)((**(int (__fastcall ***)(int))v3)(a1: v3) + 32);
        *(_QWORD *)&v12[1].len = v18;
        v12[1].allocedAndFlag = 1;
        idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (encounterGroupRole_t *)&v24);
        v1 = *(_QWORD *)&v25.list;
      }
      idStr::FreeData(this: v26);
    }
  }
  v23.__vftable = (idSort_Quick<entityListType_t *,idSort_EntityType>_vtbl *)&idSort_EntityType::`vftable';
  if ( HIDWORD(v1) != 0 )
    idSort_Quick<entityListType_t *,idSort_EntityType>::Sort(
      this: &v23,
      base: (entityListType_t **)HIDWORD(v1),
      num: v1);
  v23.__vftable = (idSort_Quick<entityListType_t *,idSort_EntityType>_vtbl *)&idSort<entityListType_t *>::`vftable';
  idLib::Printf(fmt: "\nEntity Types:\n-------------\n");
  idLib::Printf(fmt: "%-6s     %-11s %-30s\n", "Count", "Size (Kb)", "EntityDef");
  idLib::Printf(fmt: "--------------------------------------------------------------------\n");
  if ( (int)v1 > 0 )
  {
    v20 = HIDWORD(v1) - 4;
    for ( j = v1; j != 0; --j )
    {
      v20 += 4;
      LODWORD(v22) = *(_DWORD *)(*(_DWORD *)v20 + 4);
      *(_QWORD *)((char *)&v22 + 4) = *(_QWORD *)(*(_DWORD *)v20 + 32) >> 10;
      idLib::Printf(fmt: " %6i %8lld Kb  %-30s\n", *(_DWORD *)(*(_DWORD *)v20 + 40), (_QWORD)v22, v19);
    }
  }
  idList<idVarDefName *,58>::DeleteContents(this: (idList<idMapBrushSide *,5> *)&v25);
  if ( (v25.listStatic == 0 || v25.listStatic == 2) && v25.list != nullptr )
    idMem::Free(this: &mem, ptr: v25.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$499770
// EA  : 0x82D73708
// RVA : 0x00D73708
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_499770()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$499771
// EA  : 0x82D73730
// RVA : 0x00D73730
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_499771()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$499773
// EA  : 0x82D73758
// RVA : 0x00D73758
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_499773()
{
  int v0; // r12

  idSort_EntityType::~idSort_EntityType(this: (idSort_EntityType *)(v0 - 304 + 80));
}


// ========================================================================
// ?Cmd_FindNewProps_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D73788
// RVA : 0x00D73788
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_FindNewProps_f(const idCmdArgs *args, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int argc; // r11
  bool v6; // cr58
  idFile *v7; // r14
  va *v8; // r3
  int num; // r24
  idLinkList<idEntity> *next; // r11
  idEntity *owner; // r20
  idRenderModel *RenderModelFromPresentable; // r11
  int v13; // r25
  idStr *list; // r28
  int v15; // r29
  const char *str; // r4
  const idDecl *v17; // r3
  const char *v18; // r4
  const idDeclEntityDef *v19; // r4
  idEntity *v20; // r3
  idEntity *v21; // r30
  idRenderModel *v22; // r11
  const idStr *v23; // r3
  const idStr *v24; // r3
  idStr *v25; // r3
  const idStr *v26; // r3
  const idStr *v27; // r3
  idLinkList<idEntity> *v28; // r11
  int v29; // [sp+8h] [-1318h]
  int v30; // [sp+Ch] [-1314h]
  int v31; // [sp+10h] [-1310h]
  int v32; // [sp+14h] [-130Ch]
  int v33; // [sp+18h] [-1308h]
  int v34; // [sp+1Ch] [-1304h]
  idList<idStr,5> v35; // [sp+50h] [-12D0h] BYREF
  idList<idStr,5> v36; // [sp+60h] [-12C0h] BYREF
  idDeclSource **v37; // [sp+70h] [-12B0h]
  idStr v38; // [sp+80h] [-12A0h] BYREF
  idStr v39; // [sp+A0h] [-1280h] BYREF
  idStr v40; // [sp+C0h] [-1260h] BYREF
  idStr v41; // [sp+E0h] [-1240h] BYREF
  idStr v42; // [sp+100h] [-1220h] BYREF
  idStr v43; // [sp+120h] [-1200h] BYREF
  idStr v44; // [sp+140h] [-11E0h] BYREF
  idStr v45; // [sp+160h] [-11C0h] BYREF
  char v46[256]; // [sp+180h] [-11A0h] BYREF
  va v47; // [sp+280h] [-10A0h] BYREF

  v38.len = 0;
  v38.data = v38.baseBuffer;
  v38.allocedAndFlag = 20;
  v38.baseBuffer[0] = 0;
  LODWORD(a5) = v40.baseBuffer;
  v40.allocedAndFlag = 20;
  v40.data = v40.baseBuffer;
  v40.len = 0;
  v40.baseBuffer[0] = 0;
  argc = args->argc;
  v6 = args->argc == 1;
  v37 = (idDeclSource **)args->argc;
  if ( v6 )
  {
    idLib::Printf(fmt: "usage: findNewProps <def file>\n");
    idStr::FreeData(this: &v40);
    goto LABEL_54;
  }
  v7 = nullptr;
  if ( argc <= 1 )
    HIDWORD(a3) = &byte_8200D768;
  else
    HIDWORD(a3) = args->argv[1];
  v8 = va::va(this: &v47, fmt: "def/%s", a3, a4, a5, a6: v29, a7: v30, a8: v31, a9: v32, a10: v33, a11: v34);
  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: (const char *)v8, a3: v46, a4: 256, a5: FSPATH_BASE);
  idStr::idStr(this: &v41, text: v46);
  idStr::SetFileExtension(this: &v41, extension: ".def");
  *(_WORD *)&v36.memTag = 1280;
  memset(&v36, 0, 14);
  *(_WORD *)&v35.memTag = 1280;
  memset(&v35, 0, 14);
  num = idDeclEntityDef::resourceList.declSources.num;
  idList<idStr,3>::SetNum(this: &v36, newNum: idDeclEntityDef::resourceList.declSources.num);
  next = gameLocal->spawnedEntities.next;
  if ( next == nullptr )
    goto LABEL_45;
  if ( next == gameLocal->spawnedEntities.head )
    goto LABEL_45;
  owner = next->owner;
  if ( owner == nullptr )
    goto LABEL_45;
  while ( 1 )
  {
    if ( (unsigned __int8)idStaticEntity::IsTypeOf(c: owner) != 0 )
    {
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: owner);
      if ( RenderModelFromPresentable == nullptr )
        goto LABEL_40;
      idStr::operator=(this: &v38, text: RenderModelFromPresentable->name.str);
      v39.allocedAndFlag = 20;
      v39.data = v39.baseBuffer;
      v39.len = 0;
      v39.baseBuffer[0] = 0;
      idStr::ExtractFileExtension(this: &v38, dest: &v39);
      if ( v39.len != 0
        && idStr::Icmpn(s1: v38.data, s2: "models/", n: 7) == 0
        && idList<idStr,5>::FindIndex(this: &v35, obj: &v38, startIndex: 0) < 0 )
      {
        break;
      }
LABEL_39:
      idStr::FreeData(this: &v39);
    }
LABEL_40:
    v28 = owner->spawnNode.next;
    if ( v28 != nullptr && v28 != owner->spawnNode.head )
    {
      owner = v28->owner;
      if ( owner != nullptr )
        continue;
    }
    if ( v7 != nullptr )
      ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: v7, a2: 1);
LABEL_45:
    idLib::Printf(fmt: "\n...Found %d entities\n\n", v35.num);
    if ( (v35.listStatic == 0 || v35.listStatic == 2) && v35.list != nullptr )
      idListArrayDelete<idStr>(ptr: v35.list, num: v35.size);
    if ( (v36.listStatic == 0 || v36.listStatic == 2) && v36.list != nullptr )
      idListArrayDelete<idStr>(ptr: v36.list, num: v36.size);
    idStr::FreeData(this: &v41);
    idStr::FreeData(this: &v40);
    goto LABEL_54;
  }
  v13 = 0;
  if ( num <= 0 )
    goto LABEL_30;
  list = v36.list;
  v15 = 0;
  while ( 2 )
  {
    if ( list->len == 0 )
    {
      v37 = &idDeclEntityDef::resourceList.declSources.list[v15];
      str = idDeclEntityDef::resourceList.declSources.list[v15]->name.str;
      if ( str != nullptr )
        v17 = idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: str, makeDefault: false);
      else
        v17 = nullptr;
      if ( idStr::Icmpn(s1: v17->name.str, s2: "prop/", n: 5) == 0 )
      {
        idStr::operator=(this: list, text: "*");
        v37 = &idDeclEntityDef::resourceList.declSources.list[v15];
        v18 = idDeclEntityDef::resourceList.declSources.list[v15]->name.str;
        if ( v18 != nullptr )
          v19 = (const idDeclEntityDef *)idDeclInfo::FindWithInheritance(
                                           this: &idDeclEntityDef::resourceList,
                                           name: v18,
                                           makeDefault: false);
        else
          v19 = nullptr;
        v20 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v19, a3: -1, a4: -1, a5: -1);
        v21 = v20;
        if ( v20 != nullptr )
        {
          v22 = idEntity::GetRenderModelFromPresentable(this: v20);
          if ( v22 != nullptr )
            idStr::operator=(this: list, text: v22->name.str);
          ((void (__fastcall *)(idEntity *, int))v21->dtr_idClass)(a1: v21, a2: 1);
        }
        break;
      }
LABEL_29:
      ++v13;
      ++v15;
      ++list;
      if ( v13 >= num )
        goto LABEL_30;
      continue;
    }
    break;
  }
  if ( idStr::Cmp(s1: list->data, s2: v38.data) != 0 )
    goto LABEL_29;
  if ( v13 < num )
    goto LABEL_39;
LABEL_30:
  idList<idStr,5>::Append(this: &v35, obj: &v38);
  if ( idStr::Icmpn(s1: v38.data, s2: "models/mapobjects/", n: 18) != 0 )
  {
    v23 = idStr::Right(this: &v44, result: &v38, len: v38.len - 18);
    v24 = operator+(result: &v45, a: "prop/", b: v23);
    idStr::operator=(this: &v40, text: v24);
    idStr::FreeData(this: &v45);
    v25 = &v44;
  }
  else
  {
    v26 = idStr::Right(this: &v43, result: &v38, len: v38.len - 7);
    v27 = operator+(result: &v42, a: "prop/", b: v26);
    idStr::operator=(this: &v40, text: v27);
    idStr::FreeData(this: &v42);
    v25 = &v43;
  }
  idStr::FreeData(this: v25);
  idStr::StripFileExtension(this: &v40);
  if ( v7 != nullptr )
  {
LABEL_38:
    v7->Printf(this: v7, a2: "// FIXME");
    goto LABEL_39;
  }
  v7 = fileSystem->OpenFileAppend(this: fileSystem, a2: v41.data, a3: 0);
  if ( v7 != nullptr )
  {
    idLib::Printf(fmt: "writing %s...\n", v41.data);
    goto LABEL_38;
  }
  idLib::Printf(fmt: "\nCould not open file %s for writing\n", v41.data);
  idStr::FreeData(this: &v39);
  idList<idStr,99>::~idList<idStr,99>(this: &v35);
  idList<idStr,99>::~idList<idStr,99>(this: &v36);
  idStr::FreeData(this: &v41);
  idStr::FreeData(this: &v40);
LABEL_54:
  idStr::FreeData(this: &v38);
}


// ========================================================================
// $M500528_2
// EA  : 0x82D73CF8
// RVA : 0x00D73CF8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _M500528_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 128));
}


// ========================================================================
// __unwind$500071
// EA  : 0x82D73D20
// RVA : 0x00D73D20
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500071()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 192));
}


// ========================================================================
// __unwind$500072
// EA  : 0x82D73D48
// RVA : 0x00D73D48
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500072()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 224));
}


// ========================================================================
// __unwind$500073
// EA  : 0x82D73D70
// RVA : 0x00D73D70
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500073()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4896 + 96));
}


// ========================================================================
// __unwind$500074
// EA  : 0x82D73D98
// RVA : 0x00D73D98
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500074()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4896 + 80));
}


// ========================================================================
// __unwind$500075
// EA  : 0x82D73DC0
// RVA : 0x00D73DC0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 160));
}


// ========================================================================
// __unwind$500076
// EA  : 0x82D73DE8
// RVA : 0x00D73DE8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 320));
}


// ========================================================================
// __unwind$500077
// EA  : 0x82D73E10
// RVA : 0x00D73E10
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500077()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 352));
}


// ========================================================================
// __unwind$500078
// EA  : 0x82D73E38
// RVA : 0x00D73E38
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500078()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 288));
}


// ========================================================================
// __unwind$500079
// EA  : 0x82D73E60
// RVA : 0x00D73E60
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500079()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4896 + 256));
}


// ========================================================================
// ?Cmd_KillShot_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D73E90
// RVA : 0x00D73E90
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_KillShot_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const idDeclProjectile *v3; // r28
  idPlayer *DebugPlayer; // r30
  idPresentable *presentable; // r11
  idActor *FocusEntity; // r3
  idActor *v7; // r30
  int v8; // r27
  idFinishFireResults *v9; // r11
  int i; // ctr
  idFireParms v11; // [sp+60h] [-A30h] BYREF
  idFinishFireResults v12; // [sp+100h] [-990h] BYREF
  idTestFireResults v13; // [sp+150h] [-940h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    if ( args->argc > 1 )
    {
      v2 = args->argv[1];
      if ( v2 != nullptr
        && (v3 = (const idDeclProjectile *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclProjectile::resourceList,
                                             name: v2,
                                             makeDefault: false)) != nullptr )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        if ( DebugPlayer != nullptr )
        {
          idFireParms::idFireParms(this: &v11);
          idFireParms::Clear(this: &v11);
          presentable = DebugPlayer->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: DebugPlayer);
            presentable = DebugPlayer->presentable;
          }
          if ( presentable != nullptr )
            v11.attacker.spawnId = presentable->spawnId;
          else
            v11.attacker.spawnId = 0;
          v11.ignoreEntityNum = DebugPlayer->entityNumber;
          v11.wepDef = nullptr;
          DebugPlayer->GetViewTransform(this: DebugPlayer, a2: &v11.start, a3: &v11.fireAxis);
          v11.projDef = v3;
          v11.projectile.spawnId.value = 0x1FFF;
          v11.muzzleOffset.x = vec3_origin.x;
          *((_BYTE *)&v11 + 128) = *((_BYTE *)&v11 + 128) & 0x88 | 0x73;
          v11.muzzleOffset.y = vec3_origin.y;
          v11.muzzleOffset.z = vec3_origin.z;
          v11.startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          v11.damageScale = 1.0;
          FocusEntity = (idActor *)idPlayer::GetFocusEntity(this: DebugPlayer);
          v7 = idActor::CastTo(c: FocusEntity);
          if ( v7 == nullptr )
            v11.damageScale = 1000.0;
          v8 = 0;
          do
          {
            memset(&v13, 0, sizeof(v13));
            idClientGame::TestFire(this: clientGame, fp: &v11, tfr: &v13);
            v9 = &v12;
            v12.numProjectiles = 0;
            for ( i = 16; i != 0; --i )
            {
              v9 = (idFinishFireResults *)((char *)v9 + 4);
              v9->numProjectiles = 0;
            }
            idGameLocal::FinishFire(this: gameLocal, fp: &v11, tfr: &v13, ffr: &v12);
            ++v8;
          }
          while ( v7 != nullptr && !v7->IsDead(this: v7) && v8 < 50 );
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v11.targetList);
        }
      }
      else if ( args->argc <= 1 )
      {
        idLib::Printf(fmt: "Unknown projectile decl '%s'\n", &byte_8200D768);
      }
      else
      {
        idLib::Printf(fmt: "Unknown projectile decl '%s'\n", args->argv[1]);
      }
    }
    else
    {
      idLib::Printf(fmt: "USAGE: killshot <projectile decl>\n");
    }
  }
}


// ========================================================================
// __unwind$500578
// EA  : 0x82D74120
// RVA : 0x00D74120
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500578()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2704 + 96));
}


// ========================================================================
// Cmd_ShowViewNotes_f
// EA  : 0x82D74278
// RVA : 0x00D74278
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ShowViewNotes_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r21
  char *v3; // r3
  bool v4; // cr57
  char *data; // r4
  idFileList *v6; // r30
  idFileList *v7; // r3
  int num; // r8
  idStr *list; // r10
  const char *v10; // r3
  idPlayer_vtbl *v11; // r30
  idAngles *v12; // r3
  idFileList *v13; // r30
  int v14; // r10
  int v15; // r11
  __int64 v16; // r10
  __int64 v17; // r6
  __int64 v18; // r8
  va *v19; // r3
  int v20; // [sp+8h] [-11D8h]
  int v21; // [sp+Ch] [-11D4h]
  int v22; // [sp+10h] [-11D0h]
  int v23; // [sp+14h] [-11CCh]
  int v24; // [sp+18h] [-11C8h]
  int v25; // [sp+1Ch] [-11C4h]
  idStr v26; // [sp+50h] [-1190h] BYREF
  int argc; // [sp+70h] [-1170h]
  idToken v28; // [sp+80h] [-1160h] BYREF
  float v29[6]; // [sp+C8h] [-1118h] BYREF
  idStr v30; // [sp+E0h] [-1100h] BYREF
  idStr v31; // [sp+100h] [-10E0h] BYREF
  idStr v32; // [sp+120h] [-10C0h] BYREF
  idMat3 v33; // [sp+140h] [-10A0h] BYREF
  va v34; // [sp+180h] [-1060h] BYREF

  if ( (_S18_16 & 1) == 0 )
  {
    _S18_16 |= 1u;
    idLexer::idLexer(this: &parser, flags_: 566);
    atexit(func: (void (__fastcall *)())_Cmd_ShowViewNotes_f_::_2_::_dynamic_atexit_destructor_for__parser__);
  }
  v28.len = 0;
  v28.allocedAndFlag = 20;
  v28.data = v28.baseBuffer;
  v28.floatvalue = -3.4028235e38;
  v28.baseBuffer[0] = 0;
  v28.intvalue = 0;
  memset(&v28.whiteSpaceStart_p, 0, 12);
  v26.allocedAndFlag = 20;
  v26.data = v26.baseBuffer;
  v26.len = 0;
  v26.baseBuffer[0] = 0;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer == nullptr )
  {
    idStr::idStr(this: &v30, text: &byte_8200D768);
    ShowViewNotes(comments: &v30);
    idStr::FreeData(this: &v30);
    idStr::FreeData(this: &v26);
    goto LABEL_27;
  }
  if ( !parser.loaded )
  {
    idStr::operator=(this: &v26, text: "viewnotes/");
    v3 = (char *)gameLocal->GetMapName(this: gameLocal);
    idStr::Append(this: &v26, text: v3);
    idStr::StripFileExtension(this: &v26);
    idStr::Append(this: &v26, text: "/");
    v4 = args->argc > 1;
    argc = args->argc;
    if ( v4 )
    {
      data = args->argv[1];
    }
    else
    {
      v6 = viewList_0;
      if ( viewList_0 != nullptr )
      {
        idFileList::~idFileList(this: viewList_0);
        idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
        viewList_0 = nullptr;
      }
      v7 = fileSystem->ListFiles(this: fileSystem, a2: v26.data, a3: ".txt", a4: 0, a5: 0);
      num = v7->list.num;
      viewList_0 = v7;
      if ( num <= 0 )
      {
LABEL_13:
        idStr::SetFileExtension(this: &v26, extension: ".txt");
        if ( !idLexer::LoadFile(this: &parser, filename_: v26.data, OSPath: false) )
        {
          v10 = gameLocal->GetMapName(this: gameLocal);
          idLib::Printf(fmt: "No view notes for %s\n", v10);
          idStr::idStr(this: &v32, text: &byte_8200D768);
          ShowViewNotes(comments: &v32);
          idStr::FreeData(this: &v32);
          idStr::FreeData(this: &v26);
          goto LABEL_27;
        }
        goto _M501117;
      }
      list = v7->list.list;
      fileIndex = 0;
      data = list->data;
    }
    idStr::Append(this: &v26, text: data);
    goto LABEL_13;
  }
_M501117:
  if ( !idLexer::EndOfFile(this: &parser)
    && idLexer::ExpectTokenString(this: &parser, string: "view")
    && idLexer::Parse1DMatrix(this: &parser, x: 3, m: v29, expectCommas: false)
    && idLexer::Parse1DMatrix(this: &parser, x: 9, m: &v33.mat[1].y, expectCommas: false)
    && idLexer::ExpectTokenString(this: &parser, string: "comments")
    && idLexer::ReadToken(this: &parser, token: &v28) )
  {
    idLexer::SkipWhiteSpace(this: &parser, currentLine: false);
    v11 = DebugPlayer->__vftable;
    v12 = idMat3::ToAngles(this: &v33, result: (idAngles *)&v33.mat[1].y);
    v11->Teleport(this: DebugPlayer, a2: (const idVec3 *)v29, a3: v12);
    ShowViewNotes(comments: &v28);
    idStr::FreeData(this: &v26);
  }
  else
  {
    idLexer::FreeSource(this: &parser);
    idStr::idStr(this: &v31, text: &byte_8200D768);
    ShowViewNotes(comments: &v31);
    idStr::FreeData(this: &v31);
    v13 = viewList_0;
    if ( viewList_0 != nullptr )
    {
      v14 = viewList_0->list.num;
      v15 = fileIndex + 1;
      fileIndex = v15;
      if ( v15 >= v14 )
      {
        idFileList::~idFileList(this: viewList_0);
        idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
        viewList_0 = nullptr;
        fileIndex = 0;
      }
      else
      {
        idStr::operator=(this: &v26, text: viewList_0->list.list[v15].data);
        idStr::StripFileExtension(this: &v26);
        LODWORD(v16) = "WriteBoundedFloatBase";
        HIDWORD(v17) = v26.data;
        v19 = va::va(
                this: &v34,
                fmt: "showViewNotes %s\n",
                a3: v17,
                a4: v18,
                a5: v16,
                a6: v20,
                a7: v21,
                a8: v22,
                a9: v23,
                a10: v24,
                a11: v25);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v19->buffer);
      }
    }
    idStr::FreeData(this: &v26);
  }
LABEL_27:
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$500840
// EA  : 0x82D746A0
// RVA : 0x00D746A0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500840()
{
  _S18_16 &= ~1u;
}


// ========================================================================
// __unwind$500841
// EA  : 0x82D746C0
// RVA : 0x00D746C0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500841()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 128));
}


// ========================================================================
// __unwind$500842
// EA  : 0x82D746E8
// RVA : 0x00D746E8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500842()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 80));
}


// ========================================================================
// __unwind$500843
// EA  : 0x82D74710
// RVA : 0x00D74710
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500843()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 224));
}


// ========================================================================
// __unwind$500844
// EA  : 0x82D74738
// RVA : 0x00D74738
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500844()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 288));
}


// ========================================================================
// __unwind$500845
// EA  : 0x82D74760
// RVA : 0x00D74760
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_500845()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 256));
}


// ========================================================================
// ?GatherClipModels_r@@YAXPBUclipSector_t@@AAV?$idList@PBVidClipModel@@$04@@@Z
// EA  : 0x82D74788
// RVA : 0x00D74788
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall GatherClipModels_r(const clipSector_t *sector, idList<enum encounterGroupRole_t,5> *clipModels)
{
  clipLink_t *i; // r31
  int num; // r7
  int v6; // r10
  int v7; // r11
  const clipSector_t *v8; // r3

  while ( 1 )
  {
    for ( i = sector->clipLinks; i != nullptr; i = i->nextInSector )
    {
      num = clipModels->num;
      v6 = 0;
      if ( num > 0 )
      {
        v7 = 0;
        while ( (idClipModel *)clipModels->list[v7] != i->clipModel )
        {
          ++v6;
          ++v7;
          if ( v6 >= num )
            goto LABEL_8;
        }
        if ( v6 >= 0 )
          continue;
      }
LABEL_8:
      idList<idAnimWebBlendTree *,5>::Append(this: clipModels, obj: (encounterGroupRole_t *)i);
    }
    v8 = sector->children[0];
    if ( v8 != nullptr )
      GatherClipModels_r(sector: v8, (idList<idClipModel const *,5> *)clipModels);
    if ( sector->children[1] == nullptr )
      break;
    sector = sector->children[1];
  }
}


// ========================================================================
// ?Cmd_FindOrphanedClipModels_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D74840
// RVA : 0x00D74840
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_FindOrphanedClipModels_f(const idCmdArgs *args)
{
  clipSector_t *list; // r29
  int v2; // r21
  int num; // r28
  encounterGroupRole_t *v4; // r20
  int v5; // r25
  const idClipModel *v6; // r26
  int entityNumber; // r11
  char v8; // r27
  int v9; // r29
  idEntity *v10; // r3
  int v11; // r10
  encounterGroupRole_t *v12; // r11
  idClipModel **v13; // r29
  idClipModel *v14; // r30
  idCollisionModel *collisionModel; // r11
  double v16; // [sp+8h] [-108h]
  const idClipModel *v17; // [sp+70h] [-A0h] BYREF
  idList<enum encounterGroupRole_t,5> v18; // [sp+80h] [-90h] BYREF
  idList<enum encounterGroupRole_t,5> v19[8]; // [sp+90h] [-80h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    list = clientGame->clip.clipSectors.list;
    memset(v19, 0, 14);
    v19[0].listStatic = 0;
    v19[0].memTag = 5;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v19);
    GatherClipModels_r(sector: list, clipModels: v19);
    memset(&v18, 0, 14);
    *(_WORD *)&v18.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v18);
    v2 = 0;
    if ( v19[0].num <= 0 )
    {
      num = v18.num;
      v4 = v18.list;
    }
    else
    {
      num = v18.num;
      v4 = v18.list;
      v5 = 0;
      do
      {
        v6 = (const idClipModel *)v19[0].list[v5];
        entityNumber = v6->entityNumber;
        v17 = v6;
        v8 = EntityReferencesClipModel(ent: gameLocal->entities.ptr[entityNumber], clipModel: v6);
        if ( v8 == 0 )
        {
          v9 = 0;
          while ( 1 )
          {
            v10 = gameLocal->entities.ptr[v5];
            if ( v10 != nullptr
              && v5 != 8190
              && (unsigned __int8)EntityReferencesClipModel(ent: v10, clipModel: v6) != 0 )
            {
              break;
            }
            if ( ++v9 >= 0x2000 )
              goto LABEL_12;
          }
          v8 = 1;
        }
LABEL_12:
        if ( v8 == 0 )
        {
          v11 = 0;
          if ( num <= 0 )
            goto LABEL_19;
          v12 = v4;
          while ( *(const idClipModel **)v12 != v6 )
          {
            ++v11;
            ++v12;
            if ( v11 >= num )
              goto LABEL_19;
          }
          if ( v11 < 0 )
          {
LABEL_19:
            idList<idAnimWebBlendTree *,5>::Append(this: &v18, obj: (encounterGroupRole_t *)&v17);
            num = v18.num;
            v4 = v18.list;
          }
        }
        ++v2;
        ++v5;
      }
      while ( v2 < v19[0].num );
    }
    idLib::Printf(fmt: "Found %d orphaned clip models.\n", num);
    if ( num > 0 )
    {
      v13 = (idClipModel **)v4;
      do
      {
        v14 = *v13;
        collisionModel = (*v13)->collisionModel;
        if ( collisionModel == nullptr )
        {
          if ( v14->traceModels.num <= 0 )
            collisionModel = idClipModel::NoTraceModelWarning(this: *v13);
          else
            collisionModel = v14->clip->traceModelCache->cache.list[*v14->traceModels.list]->collisionModel;
        }
        idLib::Printf(
          fmt: "  %s e: %d o:( %.2f %.2f %.2f ) b:( %.2f %.2f %.2f ) -> ( %.2f %.2f %.2f )\n",
          collisionModel->name.str,
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v14->origin.x)),
          v14->origin.x,
          v14->origin.y,
          v14->origin.z,
          v14->absBounds.b[0].x,
          v14->absBounds.b[0].y,
          v14->absBounds.b[0].z,
          v14->absBounds.b[1].x,
          v14->absBounds.b[1].y,
          v16);
        --num;
        ++v13;
      }
      while ( num != 0 );
    }
    if ( (v18.listStatic == 0 || v18.listStatic == 2) && v4 != nullptr )
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
    if ( (v19[0].listStatic == 0 || v19[0].listStatic == 2) && v19[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v19[0].list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$501195
// EA  : 0x82D74B44
// RVA : 0x00D74B44
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_501195()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 144));
}


// ========================================================================
// __unwind$501196
// EA  : 0x82D74B6C
// RVA : 0x00D74B6C
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_501196()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 128));
}


// ========================================================================
// ?Cmd_ReloadVehicles_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82D74CE8
// RVA : 0x00D74CE8
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall Cmd_ReloadVehicles_f(const idCmdArgs *args)
{
  idSpawnedVehicle *list; // r26
  idGameLocal *v2; // r3
  idLinkList<idEntity> *next; // r11
  __int64 v4; // kr00_8
  idVehicle *owner; // r29
  idLinkList<idEntity> *v6; // r11
  idVehicle *v7; // r28
  idSpawnedVehicle *v8; // r30
  idPhysics *Physics; // r3
  idPhysics *v10; // r3
  idClass **p_driver; // r29
  int v12; // r27
  idVehicle_Car *v13; // r30
  idPhysics *v14; // r3
  idPhysics *v15; // r3
  idVehicleAI *v16; // r3
  bool v17; // zf
  idStr *p_name; // r29
  int i; // r30
  idList<idSpawnedVehicle,5> v20; // [sp+60h] [-60h] BYREF

  if ( idGameLocal::CheckCheats(this: gameLocal, player: nullptr) )
  {
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "reloadDecls");
    list = nullptr;
    *(_WORD *)&v20.memTag = 1280;
    memset(&v20, 0, 14);
    v2 = gameLocal;
    next = gameLocal->spawnedEntities.next;
    v4 = 0;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      owner = (idVehicle *)next->owner;
      if ( owner != nullptr )
      {
        do
        {
          v6 = owner->spawnNode.next;
          if ( v6 == nullptr || v6 == owner->spawnNode.head )
            v7 = nullptr;
          else
            v7 = (idVehicle *)v6->owner;
          if ( (unsigned __int8)idVehicle::IsTypeOf(c: owner) != 0 )
          {
            v8 = idList<idSpawnedVehicle,5>::Alloc(this: &v20);
            v8->def = owner->entityDef;
            idStr::operator=(this: &v8->name, text: owner->name.data);
            Physics = idEntity::GetPhysics(this: owner);
            v8->origin = *Physics->GetOrigin(this: Physics, a2: 0);
            v10 = idEntity::GetPhysics(this: owner);
            v8->axis = *v10->GetAxis(this: v10, a2: 0);
            v8->driver = idVehicle::GetDriver(this: owner);
            ((void (__fastcall *)(idVehicle *, int))owner->dtr_idClass)(a1: owner, a2: 1);
          }
          owner = v7;
        }
        while ( v7 != nullptr );
        v4 = *(_QWORD *)&v20.num;
        list = v20.list;
        v2 = gameLocal;
      }
    }
    if ( SHIDWORD(v4) > 0 )
    {
      p_driver = &list->driver;
      v12 = HIDWORD(v4);
      while ( 1 )
      {
        v13 = (idVehicle_Car *)v2->SpawnEntityFromDef(
                                 this: v2,
                                 a2: (const idDeclEntityDef *)*(p_driver - 21),
                                 a3: -1,
                                 a4: -1,
                                 a5: -1);
        if ( (unsigned __int8)idVehicle::IsTypeOf(c: v13) != 0 )
        {
          idEntity::SetName(this: v13, newName: (const char *)*(p_driver - 19));
          v14 = idEntity::GetPhysics(this: v13);
          v14->SetOrigin(this: v14, a2: (const idVec3 *)p_driver - 4, a3: -1);
          v15 = idEntity::GetPhysics(this: v13);
          v15->SetAxis(this: v15, a2: (const idMat3 *)p_driver - 1, a3: -1);
          if ( *p_driver != nullptr )
          {
            v17 = (unsigned __int8)idVehicleAI::IsTypeOf(c: *p_driver) == 0;
            v16 = (idVehicleAI *)*p_driver;
            if ( v17 )
            {
              if ( (unsigned __int8)idActor::IsTypeOf(c: v16) != 0 )
                v13->EnterVehicle(this: v13, a2: (idEntity *)*p_driver, a3: SEAT_MAX);
            }
            else
            {
              idVehicleAI::UseVehicle(this: v16, entity: v13, seat: SEAT_MAX);
            }
          }
        }
        else if ( v13 != nullptr )
        {
          ((void (__fastcall *)(idVehicle_Car *, int))v13->dtr_idClass)(a1: v13, a2: 1);
        }
        --v12;
        p_driver += 22;
        if ( v12 == 0 )
          break;
        v2 = gameLocal;
      }
    }
    if ( (v20.listStatic == 0 || v20.listStatic == 2) && list != nullptr )
    {
      if ( (int)v4 > 0 )
      {
        p_name = &list->name;
        for ( i = v4; i != 0; --i )
        {
          idStr::FreeData(this: p_name);
          p_name = (idStr *)((char *)p_name + 88);
        }
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$501481
// EA  : 0x82D75074
// RVA : 0x00D75074
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void _unwind_501481()
{
  int v0; // r12

  idList<idSpawnedVehicle,5>::~idList<idSpawnedVehicle,5>(this: (idList<idSpawnedVehicle,5> *)(v0 - 192 + 96));
}


// ========================================================================
// ?InitConsoleCommands@@YAXXZ
// EA  : 0x82D750A0
// RVA : 0x00D750A0
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

void __fastcall InitConsoleCommands()
{
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listTypeInfo",
    a3: idGameState::ListTypeInfo_f,
    a4: "list type info",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listGameTypeInfo",
    a3: idGameState::ListGameTypeInfo_f,
    a4: "list game type info",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listClassTypeInfo",
    a3: idGameState::ListClassTypeInfo_f,
    a4: "list class type info",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "findUninitializedMem",
    a3: idGameState::FindUninitializedMemory_f,
    a4: "find uninitialized class variables",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "game_memory",
    a3: idClass::DisplayInfo_f,
    a4: "displays game class info",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listClasses",
    a3: idClass::ListClasses_f,
    a4: "lists game classes",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listThreads",
    a3: idThreadManager::ListThreads_f,
    a4: "lists script threads",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "htmlScriptOperators",
    a3: idCompiler::HtmlScriptOperators_f,
    a4: "lists all script operators",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listEntities",
    a3: Cmd_EntityList_f,
    a4: "lists game entities",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listEntityTypes",
    a3: Cmd_EntityListTypes_f,
    a4: "lists game entities by type and count",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listEntityCollision",
    a3: Cmd_EntityListCollision_f,
    a4: "lists game entity collision models",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listActiveEntities",
    a3: Cmd_ActiveEntityList_f,
    a4: "lists active game entities",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listActiveActors",
    a3: Cmd_ActiveActorList_f,
    a4: "lists active game actors",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listActiveLayers",
    a3: Cmd_listActiveLayers_f,
    a4: "lists active gameplay layers",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listEntitiesAtOrigin",
    a3: Cmd_ListEntitiesAtOrigin_f,
    a4: "lists all entities at the origin, optionally matching contents flags",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "findOrphanedClipModels",
    a3: Cmd_FindOrphanedClipModels_f,
    a4: "lists all clip models that aren't pointed to by an entity",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "gameLayerActiveLayers",
    a3: idGameLayerManager::GameLayerActiveLayers_f,
    a4: "prints out the current activate layers in the game layer manager",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "jobActiveItemMemories",
    a3: idGameLayerManager::GameLayerActiveItemMemories_f,
    a4: "prints out the current item memories in the game layer manager",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "jobImportStrings",
    a3: idJobManager::ImportJobStrings_f,
    a4: "imports job strings from a .csv file",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "jobActiveGameState",
    a3: idJobManager::JobActiveGameState_f,
    a4: "prints out the current game state variables on the job manager",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "jobTestArea",
    a3: idJobManager::JobTestArea_f,
    a4: "print out the area we are in",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "exportJobDescriptions",
    a3: ExportJobDescriptions_f,
    a4: "Exports the jobs description values to a csv.  Temp tool for generating excell sheet",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "importJobDescriptions",
    a3: ImportJobDescriptions_f,
    a4: "imports voice strings for jobs from a master .csv file.",
    a5: ArgCompletion_CSV);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "exportJobNotes",
    a3: ExportJobNotes_f,
    a4: "Exports the jobs notes values to a csv.  Temp tool for generating excell sheet",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "importJobNotes",
    a3: ImportJobNotes_f,
    a4: "imports the job notes strings and references from a master.csv file.",
    a5: ArgCompletion_CSV);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "exportJobCompletions",
    a3: ExportJobCompletions_f,
    a4: "Exports the jobs completions values to a csv.  Temp tool for generating excell sheet",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "importVoiceOvers",
    a3: ImportVoiceOvers_f,
    a4: "imports voice overs and strings for jobs and interactions from a master .csv file.",
    a5: ArgCompletion_CSV);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "rewriteInteractions",
    a3: RewriteInteractions_f,
    a4: "rewrite's all interaction decls.",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "selectDebugEntity",
    a3: Cmd_SelectDebugEntity_f,
    a4: "selects the player's focus entity as the debug entity",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "kill", a3: Cmd_Kill_f, a4: "kills the player", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "where",
    a3: Cmd_GetViewpos_f,
    a4: "prints the current view position",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "getviewpos",
    a3: Cmd_GetViewpos_f,
    a4: "prints the current view position",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "setviewpos",
    a3: Cmd_SetViewpos_f,
    a4: "sets the current view position",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "centerview",
    a3: Cmd_CenterView_f,
    a4: "centers the view (set pitch to 0)",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "teleport",
    a3: Cmd_Teleport_f,
    a4: "teleports the player to an entity location",
    a5: idGameLocal::ArgCompletion_EntityName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "trigger",
    a3: Cmd_Trigger_f,
    a4: "triggers an entity",
    a5: idGameLocal::ArgCompletion_EntityName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "damage",
    a3: Cmd_Damage_f,
    a4: "apply damage to an entity",
    a5: idGameLocal::ArgCompletion_EntityName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killMonsters",
    a3: Cmd_KillMonsters_f,
    a4: "removes all monsters",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killMoveables",
    a3: Cmd_KillMovables_f,
    a4: "removes all moveables",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killRagdolls",
    a3: Cmd_KillRagdolls_f,
    a4: "removes all ragdolls",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killEntity",
    a3: Cmd_KillEntity_f,
    a4: "removes the entity with the given name, 'kill entityname' will remove that single entity, 'kill all entityname' remo"
    "ves all entities matching the class of the given name",
    a5: idGameLocal::ArgCompletion_EntityName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadEntity",
    a3: Cmd_ReloadEntity_f,
    a4: "reloads the specified entity",
    a5: idGameLocal::ArgCompletion_EntityName);
  cmdSystem->AddCommand(this: cmdSystem, a2: "addline", a3: Cmd_AddDebugLine_f, a4: "adds a debug line", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "addarrow", a3: Cmd_AddDebugLine_f, a4: "adds a debug arrow", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "removeline",
    a3: Cmd_RemoveDebugLine_f,
    a4: "removes a debug line",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "blinkline",
    a3: Cmd_BlinkDebugLine_f,
    a4: "blinks a debug line",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listLines",
    a3: Cmd_ListDebugLines_f,
    a4: "lists all debug lines",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "testLight", a3: Cmd_TestLight_f, a4: "tests a light", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testPointLight",
    a3: Cmd_TestPointLight_f,
    a4: "tests a point light",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testParallelLight",
    a3: Cmd_TestParallelLight_f,
    a4: "tests a point light",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "popLight",
    a3: Cmd_PopLight_f,
    a4: "removes the last created light",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "testDeath", a3: Cmd_TestDeath_f, a4: "tests death", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "script", a3: Cmd_Script_f, a4: "executes a line of script", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "aasStats", a3: Cmd_AASStats_f, a4: "shows AAS stats", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "aasLoad",
    a3: Cmd_AASLoad_f,
    a4: "load a particular AAS",
    a5: idCmdSystem::ArgCompletion_String<&public: static char const * * idAAS2Settings::fileExtensions,8>);
  cmdSystem->AddCommand(this: cmdSystem, a2: "clearLights", a3: Cmd_ClearLights_f, a4: "clears all lights", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "gameError", a3: Cmd_GameError_f, a4: "causes a game error", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "disasmScript",
    a3: Cmd_DisasmScript_f,
    a4: "disassembles script",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "recordViewNotes",
    a3: Cmd_RecordViewNotes_f,
    a4: "system record the current view position with notes",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "takeViewNotes",
    a3: Cmd_TakeViewNotes_f,
    a4: "user record the current view position with notes",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "showViewNotes",
    a3: Cmd_ShowViewNotes_f,
    a4: "show any view notes for the current map, successive calls will cycle to the next note",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "closeViewNotes",
    a3: Cmd_CloseViewNotes_f,
    a4: "close the view showing any notes for this map",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killDebugTarget",
    a3: Cmd_KillDebugTarget_f,
    a4: "kills the current debug target",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listInventory",
    a3: Cmd_ListInventory_f,
    a4: "lists players inventory or inventory of actor player is targeting with cursor",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testWeapon",
    a3: idHands::Cmd_TestWeapon_f,
    a4: "test a weapon model",
    a5: idCmdSystem::ArgCompletion_ModelName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "tw_save",
    a3: idHands::Cmd_tw_save_f,
    a4: "writes current testweapon parameters to a config file",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "resetBreakables",
    a3: Cmd_ResetBreakables_f,
    a4: "reset breakables",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testmodel",
    a3: idTestModel2::SpawnTestModel_f,
    a4: "spawns a test model",
    a5: idTestModel2::ArgCompletion_Model);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "keepTestModel",
    a3: tm_keep_f,
    a4: "keeps the current testmodel around even if a new one is spawned",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "printVOlog",
    a3: Cmd_PrintVOLog_f,
    a4: "Show recent history of AI voice controller",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "nextActiveAI",
    a3: Cmd_NextActiveAI_f,
    a4: "move debug target to the next active (alive and not hidden) monster",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "nextAI",
    a3: Cmd_NextAI_f,
    a4: "move debug target to the next monster",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "prevAI",
    a3: Cmd_PrevAI_f,
    a4: "move debug target to the prev monster",
    a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "killAI", a3: Cmd_KillAI_f, a4: "kills all AI in the level", a5: nullptr);
  cmdSystem->AddCommand(this: cmdSystem, a2: "healAI", a3: Cmd_HealAI_f, a4: "heals all AI in the level", a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "randomTest",
    a3: Cmd_randomTest_f,
    a4: "superficial test of random number generators",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killUnhiddenAI",
    a3: Cmd_KillUnhiddenAI_f,
    a4: "kills all AI that are not currently hidden in the level",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killDeadAI",
    a3: Cmd_KillDeadAI_f,
    a4: "kills (removes) all AI that are dead.",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "aas_visCacheInfo",
    a3: idAASVisCache::Cmd_VisCacheInfo_f,
    a4: "shows information about the AAS visibility cache",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "saveFSM",
    a3: Cmd_SaveFSM_f,
    a4: "saves out the AI's finite state machine to a file",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "saveWeaponFSM",
    a3: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
    a4: "saves out the AI's finite state machine to a file",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "forceFollow",
    a3: idAI2::Cmd_ForceFollow_f,
    a4: "force the debug targetted AI to follow the player.",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "killshot",
    a3: Cmd_KillShot_f,
    a4: "fire a shot guaranteed to kill any actor in the player's focus",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "moveToFacingReticule",
    a3: Cmd_ai_MoveToFacingReticule_f,
    a4: "tell debug target to move to location under reticule, facing direction of reticule",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "moveToFacingPlayer",
    a3: Cmd_ai_MoveToFacingPlayer_f,
    a4: "tell debug target to move to location under reticule, facing direction of player",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "fixActionScripts",
    a3: Cmd_FixActionScripts_f,
    a4: "fix action script formats",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "findNewProps",
    a3: (void (__fastcall *)(const idCmdArgs *))Cmd_FindNewProps_f,
    a4: "finds all func/statics with prop models that haven't been defined as props",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "pushDebugPoint",
    a3: idGameLocal::PushDebugPoint_f,
    a4: "adds a debug point to the list of debug points",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "popDebugPoint",
    a3: idGameLocal::PopDebugPoint_f,
    a4: "removes a debug point from the list of debug points",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "clearDebugPoints",
    a3: idGameLocal::ClearDebugPoints_f,
    a4: "empties the list of debug points",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadVehicles",
    a3: Cmd_ReloadVehicles_f,
    a4: "reload all vehicles",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "resetViewParms",
    a3: Cmd_ResetViewParms_f,
    a4: "Resets the current view renderParms",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "toQuat",
    a3: Cmd_ToQuat_f,
    a4: "converts an angle to a quaternion",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "fromQuat",
    a3: Cmd_FromQuat_f,
    a4: "converts an quaternion to a euler rotation",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "setDemoMode",
    a3: Cmd_SetDemoMode_f,
    a4: "Disables all debug output and sets any other cvars necessary for giving a demo",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ai_ScriptCmd",
    a3: Cmd_ai_ScriptCmd_f,
    a4: "Execute a script command.",
    a5: ScriptFunctionArgs);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "ai_ScriptCmdEnt",
    a3: Cmd_ai_ScriptCmdEnt_f,
    a4: "Execute a script command.",
    a5: ScriptFunctionArgs);
}


// ========================================================================
// `dynamic initializer for 'yawToVector_v''
// EA  : 0x83381020
// RVA : 0x01381020
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__yawToVector_v__()
{
  return idCommandLink::idCommandLink(
           this: &yawToVector_v,
           cmdName: "yawToVector",
           function: yawToVector_f,
           description: "convert a yaw value to a normalized vector",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setDebugEntity_v''
// EA  : 0x83381048
// RVA : 0x01381048
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setDebugEntity_v__()
{
  return idCommandLink::idCommandLink(
           this: &setDebugEntity_v,
           cmdName: "setDebugEntity",
           function: setDebugEntity_f,
           description: "sets the debug entity to the entity with the specified entity number",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'toggleFreeCam_v''
// EA  : 0x83381070
// RVA : 0x01381070
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__toggleFreeCam_v__()
{
  return idCommandLink::idCommandLink(
           this: &toggleFreeCam_v,
           cmdName: "toggleFreeCam",
           function: toggleFreeCam_f,
           description: "Toggles free look camera",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'clipStats_v''
// EA  : 0x83381098
// RVA : 0x01381098
// PDB : w:\tech5\tungsten\game\gamesys\syscmds.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__clipStats_v__()
{
  return idCommandLink::idCommandLink(
           this: &clipStats_v,
           cmdName: "clipStats",
           function: clipStats_f,
           description: "clip space statistics",
           argCompletion: nullptr);
}

