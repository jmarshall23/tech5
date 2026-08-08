
// ========================================================================
// ?GetTypeInfoTools@idGameLocal@@UAAPBVidTypeInfoTools@@XZ
// EA  : 0x82D9A608
// RVA : 0x00D9A608
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

const idTypeInfoTools *__fastcall idGameLocal::GetTypeInfoTools(idGameLocal *this)
{
  const idTypeInfoTools *TypeInfoTools; // r30
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  TypeInfoTools = idGameState::GetTypeInfoTools();
  idGameLock::~idGameLock(this: v3);
  return TypeInfoTools;
}


// ========================================================================
// __unwind$493582_0
// EA  : 0x82D9A658
// RVA : 0x00D9A658
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493582_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetEntityEditState@idGameLocal@@UAAXPAVidEntity@@AAVidTypeInfoFile@@_N@Z
// EA  : 0x82D9A688
// RVA : 0x00D9A688
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::GetEntityEditState(
        idGameLocal *this,
        idEntity *entity,
        idTypeInfoFile *file,
        bool includeDefVars)
{
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  idGameState::GetEntityEditState(entity, file, includeDefVars);
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$493602
// EA  : 0x82D9A6D0
// RVA : 0x00D9A6D0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493602()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetEntityEditState@idGameLocal@@UAAXPAVidEntity@@AAVidTypeInfoFile@@_N@Z
// EA  : 0x82D9A700
// RVA : 0x00D9A700
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::SetEntityEditState(
        idGameLocal *this,
        idEntity *entity,
        idTypeInfoFile *file,
        bool includeDefVars)
{
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  idGameState::SetEntityEditState(entity, file, includeDefVars);
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$493622
// EA  : 0x82D9A748
// RVA : 0x00D9A748
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493622()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?AddNewLayer@idGameLocal@@UAAXPAVidDecl@@PBD@Z
// EA  : 0x82D9A778
// RVA : 0x00D9A778
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::AddNewLayer(idGameLocal *this, idDecl *decl, const char *layerName)
{
  idDecl *v4; // r3
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  v4 = (idDecl *)_RTDynamicCast(
                   inptr: decl,
                   VfDelta: 0,
                   SrcType: &idDecl `RTTI Type Descriptor',
                   TargetType: (void *)&idDeclLayer `RTTI Type Descriptor',
                   isReference: 0);
  if ( v4 != nullptr )
    idDecl::ReplaceSourceFileText(this: v4, useSourceControl: true);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$493641_0
// EA  : 0x82D9A7F0
// RVA : 0x00D9A7F0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493641_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?AddSelectedEntity@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9A820
// RVA : 0x00D9A820
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::AddSelectedEntity(idGameLocal *this, idEntity *ent)
{
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // [sp+8h] [-78h]
  int v11; // [sp+Ch] [-74h]
  int v12; // [sp+10h] [-70h]
  int v13; // [sp+14h] [-6Ch]
  int v14; // [sp+18h] [-68h]
  idEntity *v15; // [sp+1Ch] [-64h]
  idGameLock v16[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v16, newGame: this);
  if ( ent != nullptr )
    idEditEntities::AddSelectedEntity(
      this: &this->editEntities,
      ent,
      a3: v9,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4,
      a9: v10,
      a10: v11,
      a11: v12,
      a12: v13,
      a13: v14,
      a14: v15);
  idGameLock::~idGameLock(this: v16);
}


// ========================================================================
// __unwind$493658
// EA  : 0x82D9A86C
// RVA : 0x00D9A86C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493658()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?DeleteEntity@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9A8A0
// RVA : 0x00D9A8A0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::DeleteEntity(idGameLocal *this, idEntity *ent)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( ent != nullptr )
    ((void (__fastcall *)(idEntity *, int))ent->dtr_idClass)(a1: ent, a2: 1);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$493684
// EA  : 0x82D9A908
// RVA : 0x00D9A908
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493684()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?DeleteEntityAndSubEntities@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9A938
// RVA : 0x00D9A938
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::DeleteEntityAndSubEntities(idGameLocal *this, idEntity *ent)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( ent != nullptr )
  {
    ent->DeleteSubEntities(this: ent);
    ((void (__fastcall *)(idEntity *, int))ent->dtr_idClass)(a1: ent, a2: 1);
  }
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$493705
// EA  : 0x82D9A9B4
// RVA : 0x00D9A9B4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493705()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?SetEntityName@idGameLocal@@UAAXPAVidEntity@@PBD@Z
// EA  : 0x82D9A9E8
// RVA : 0x00D9A9E8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::SetEntityName(idGameLocal *this, idEntity *ent, const char *newName)
{
  idGameLock v5[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  idEntity::SetName(this: ent, newName);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$493722
// EA  : 0x82D9AA28
// RVA : 0x00D9AA28
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493722()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetEntityType@idGameLocal@@UBAPBDPAVidEntity@@@Z
// EA  : 0x82D9AA58
// RVA : 0x00D9AA58
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

const char *__fastcall idGameLocal::GetEntityType(idGameLocal *this, idEntity *ent)
{
  int v3; // r30
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  v3 = *(_DWORD *)ent->GetType(this: ent);
  idGameLock::~idGameLock(this: v5);
  return (const char *)v3;
}


// ========================================================================
// __unwind$493741
// EA  : 0x82D9AABC
// RVA : 0x00D9AABC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493741()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetUniqueEntityName@idGameLocal@@UBAPBDPBD@Z
// EA  : 0x82D9AAF0
// RVA : 0x00D9AAF0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

char *__fastcall idGameLocal::GetUniqueEntityName(idGameLocal *this, const char *classname)
{
  idMapFile *v4; // r25
  int v5; // r28
  idGameLock v7[20]; // [sp+50h] [-50h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  v4 = this->GetLevelMap(this);
  v5 = 0;
  while ( 1 )
  {
    idStr::snPrintf(dest: name, size: 1024, fmt: "%s_%d", classname, v5);
    if ( this->FindEntity(this, a2: name) == nullptr
      && v4 != nullptr
      && idMapFile::FindEntity(this: v4, name: name, index: nullptr) == nullptr )
    {
      break;
    }
    if ( ++v5 >= 0x2000 )
    {
      idStr::snPrintf(dest: name, size: 1024, fmt: "%s_%d", classname, v5);
      break;
    }
  }
  idGameLock::~idGameLock(this: v7);
  return name;
}


// ========================================================================
// $M493773_0
// EA  : 0x82D9ABD4
// RVA : 0x00D9ABD4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _M493773_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?EntitySetOrigin@idGameLocal@@UAAXPAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82D9AC08
// RVA : 0x00D9AC08
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntitySetOrigin(idGameLocal *this, idEntity *ent, const idVec3 *org)
{
  idGameLock v5[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  if ( ent != nullptr )
    idEntity::SetOrigin(this: ent, org);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$493787_0
// EA  : 0x82D9AC50
// RVA : 0x00D9AC50
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493787_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntitySetAxis@idGameLocal@@UAAXPAVidEntity@@ABVidMat3@@@Z
// EA  : 0x82D9AC80
// RVA : 0x00D9AC80
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntitySetAxis(idGameLocal *this, idEntity *ent, const idMat3 *axis)
{
  idGameLock v5[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  if ( ent != nullptr )
    ent->SetAxis(this: ent, a2: axis);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$493805
// EA  : 0x82D9ACD4
// RVA : 0x00D9ACD4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493805()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntitySetViewPosition@idGameLocal@@UAAXPAVidEntity@@ABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82D9AD08
// RVA : 0x00D9AD08
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntitySetViewPosition(
        idGameLocal *this,
        idEntity *ent,
        const idVec3 *org,
        idAngles *angles)
{
  idEntity_vtbl *v7; // r29
  idMat3 *v8; // r3
  idGameLock v9[4]; // [sp+50h] [-60h] BYREF
  idAngles v10[6]; // [sp+60h] [-50h] BYREF

  idGameLock::idGameLock(this: v9, newGame: this);
  if ( ent != nullptr )
  {
    if ( (unsigned __int8)idPlayer::IsTypeOf(c: ent) != 0 )
    {
      ent->Teleport(this: ent, a2: org, a3: angles);
    }
    else
    {
      idEntity::SetOrigin(this: ent, org);
      v7 = ent->__vftable;
      v8 = idAngles::ToMat3(this: v10, result: (idMat3 *)angles);
      v7->SetAxis(this: ent, a2: v8);
    }
  }
  idGameLock::~idGameLock(this: v9);
}


// ========================================================================
// __unwind$493824
// EA  : 0x82D9ADA8
// RVA : 0x00D9ADA8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493824()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// ?EntityTranslate@idGameLocal@@UAAXPAVidEntity@@ABVidVec3@@_N@Z
// EA  : 0x82D9ADD8
// RVA : 0x00D9ADD8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityTranslate(
        idGameLocal *this,
        idEntity *ent,
        const idVec3 *org,
        bool updateSpawnPosition)
{
  idPhysics *Physics; // r3
  idGameLock v8[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v8, newGame: this);
  if ( ent != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    Physics->Translate(this: Physics, a2: org, a3: -1);
    if ( updateSpawnPosition )
      idEntity::SpawnTransform(this: ent, origin: org, axis: &mat3_identity);
  }
  idGameLock::~idGameLock(this: v8);
}


// ========================================================================
// __unwind$493842_0
// EA  : 0x82D9AE58
// RVA : 0x00D9AE58
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493842_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityUpdateVisuals@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9AE88
// RVA : 0x00D9AE88
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityUpdateVisuals(idGameLocal *this, idEntity *ent)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( ent != nullptr )
    idEntity::UpdateVisuals(this: ent);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$493860_0
// EA  : 0x82D9AEE0
// RVA : 0x00D9AEE0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493860_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityUpdateModifiedProperties@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9AF10
// RVA : 0x00D9AF10
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityUpdateModifiedProperties(idGameLocal *this, idEntity *ent)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( ent != nullptr )
    ent->UpdateModifiedProperties(this: ent);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$493877
// EA  : 0x82D9AF74
// RVA : 0x00D9AF74
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493877()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityStopSound@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9AFA8
// RVA : 0x00D9AFA8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityStopSound(idGameLocal *this, idEntity *ent)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( ent != nullptr )
    idEntity::StopSound(this: ent, channel: SND_CHANNEL_ANY, peerMask: 0);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$493894
// EA  : 0x82D9B008
// RVA : 0x00D9B008
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493894()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityGetSoundEmitter@idGameLocal@@UAAPAVidSoundEmitter@@PAVidEntity@@@Z
// EA  : 0x82D9B038
// RVA : 0x00D9B038
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idSoundEmitter *__fastcall idGameLocal::EntityGetSoundEmitter(idGameLocal *this, idEntity *ent)
{
  idSoundEmitter *SoundEmitter; // r30
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  if ( ent != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this: ent, alloc: false);
    idGameLock::~idGameLock(this: v5);
    return SoundEmitter;
  }
  else
  {
    idGameLock::~idGameLock(this: v5);
    return nullptr;
  }
}


// ========================================================================
// __unwind$493913
// EA  : 0x82D9B0AC
// RVA : 0x00D9B0AC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493913()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityGetRenderModel@idGameLocal@@UAAPAVidRenderModel@@PAVidEntity@@@Z
// EA  : 0x82D9B0E0
// RVA : 0x00D9B0E0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idRenderModel *__fastcall idGameLocal::EntityGetRenderModel(idGameLocal *this, idEntity *ent)
{
  idRenderModel *RenderModelFromPresentable; // r30
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  if ( ent != nullptr )
  {
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: ent);
    idGameLock::~idGameLock(this: v5);
    return RenderModelFromPresentable;
  }
  else
  {
    idGameLock::~idGameLock(this: v5);
    return nullptr;
  }
}


// ========================================================================
// __unwind$493932_1
// EA  : 0x82D9B150
// RVA : 0x00D9B150
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493932_1()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntitySetScale@idGameLocal@@UBAXPAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82D9B180
// RVA : 0x00D9B180
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntitySetScale(idGameLocal *this, idEntity *ent, const idVec3 *scale)
{
  idGameLock v5[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  if ( ent != nullptr )
    ent->SetScale(this: ent, a2: scale);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$493949
// EA  : 0x82D9B1D4
// RVA : 0x00D9B1D4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493949()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityIsHidden@idGameLocal@@UBA_NPAVidEntity@@@Z
// EA  : 0x82D9B200
// RVA : 0x00D9B200
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::EntityIsHidden(idGameLocal *this, idEntity *ent)
{
  if ( ent != nullptr )
    return Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)ent);
  else
    return 0;
}


// ========================================================================
// ?MapAddEntity@idGameLocal@@UAAXPAVidEntity@@@Z
// EA  : 0x82D9B218
// RVA : 0x00D9B218
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::MapAddEntity(idGameLocal *this, idEntity *ent)
{
  this->MapUpdateEntity(this, a2: ent, a3: true, a4: nullptr);
}


// ========================================================================
// ?MapFindEntity@idGameLocal@@UAAPAVidMapEntity@@PBD@Z
// EA  : 0x82D9B230
// RVA : 0x00D9B230
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idMapEntity *__fastcall idGameLocal::MapFindEntity(idGameLocal *this, const char *entName)
{
  idMapFile *v3; // r3

  v3 = this->GetLevelMap(this);
  if ( v3 != nullptr )
    return idMapFile::FindEntity(this: v3, name: entName, index: nullptr);
  else
    return nullptr;
}


// ========================================================================
// ?MapRemoveEntity@idGameLocal@@UBAXPBD@Z
// EA  : 0x82D9B2A0
// RVA : 0x00D9B2A0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::MapRemoveEntity(idGameLocal *this, const char *name)
{
  idMapFile *v4; // r3
  idMapFile *v5; // r30
  idMapEntity *Entity; // r4
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  v4 = this->GetLevelMap(this);
  v5 = v4;
  if ( v4 != nullptr )
  {
    Entity = idMapFile::FindEntity(this: v4, name, index: nullptr);
    if ( Entity != nullptr )
      idMapFile::RemoveEntity(this: v5, mapEnt: Entity);
  }
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$493977
// EA  : 0x82D9B314
// RVA : 0x00D9B314
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_493977()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?AllocEntityInterface@idGameLocal@@UAAPAVidEntityInterface@@PAVidEntity@@@Z
// EA  : 0x82D9B348
// RVA : 0x00D9B348
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idEntityInterface *__fastcall idGameLocal::AllocEntityInterface(idGameLocal *this, idEntity *ent)
{
  idEntityInterface *v4; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  v4 = ent->CreateEntityInterface(this: ent, a2: this);
  idGameLock::~idGameLock(this: v6);
  return v4;
}


// ========================================================================
// __unwind$494000
// EA  : 0x82D9B39C
// RVA : 0x00D9B39C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494000()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?FreeEntityInterface@idGameLocal@@UAAXPAVidEntityInterface@@@Z
// EA  : 0x82D9B3D0
// RVA : 0x00D9B3D0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::FreeEntityInterface(idGameLocal *this, idEntityInterface *iface)
{
  idGameLock v3[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v3, newGame: this);
  if ( iface != nullptr )
    ((void (__fastcall *)(idEntityInterface *, int))iface->dtr_idEntityInterface)(a1: iface, a2: 1);
  idGameLock::~idGameLock(this: v3);
}


// ========================================================================
// __unwind$494022_0
// EA  : 0x82D9B438
// RVA : 0x00D9B438
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494022_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetScriptObjectNames@idGameLocal@@UAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9B468
// RVA : 0x00D9B468
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::GetScriptObjectNames(idGameLocal *this, idList<idStr,5> *list)
{
  idGameLock v4[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  idProgram::GetScriptObjectNames(this: &this->program, list);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$494039_0
// EA  : 0x82D9B4AC
// RVA : 0x00D9B4AC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494039_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetSuperScriptObjectNames@idGameLocal@@UAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9B4E0
// RVA : 0x00D9B4E0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::GetSuperScriptObjectNames(idGameLocal *this, idList<idStr,5> *list)
{
  idGameLock v4[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  idSuperScriptSystem::GetScriptObjectNames(this: &this->superScript, list);
  idGameLock::~idGameLock(this: v4);
}


// ========================================================================
// __unwind$494059_0
// EA  : 0x82D9B524
// RVA : 0x00D9B524
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494059_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?CompileScriptText@idGameLocal@@UAA_NPBD0_N1@Z
// EA  : 0x82D9B558
// RVA : 0x00D9B558
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

BOOL __fastcall idGameLocal::CompileScriptText(
        idGameLocal *this,
        const char *name,
        const char *text,
        const bool errorsAsWarnings,
        const bool noStats)
{
  idProgram *p_program; // r30
  BOOL v10; // r30
  idGameLock v12[16]; // [sp+50h] [-40h] BYREF

  p_program = &this->program;
  idGameLock::idGameLock(this: v12, newGame: this);
  idProgram::Restart(this: p_program);
  v10 = idProgram::CompileText(this: p_program, source: name, text, flags: errorsAsWarnings | (!noStats ? 0 : 2));
  idGameLock::~idGameLock(this: v12);
  return v10;
}


// ========================================================================
// __unwind$494080
// EA  : 0x82D9B5E4
// RVA : 0x00D9B5E4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494080()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?FunctionExists@idGameLocal@@UAA_NPBD0@Z
// EA  : 0x82D9B618
// RVA : 0x00D9B618
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

BOOL __fastcall idGameLocal::FunctionExists(idGameLocal *this, const char *objectName, const char *functionName)
{
  idProgram *p_program; // r30
  const idTypeDef *Type; // r5
  function_t *Function; // r3
  BOOL v10; // r30
  idGameLock v11[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v11, newGame: this);
  if ( objectName != nullptr )
  {
    p_program = &this->program;
    Type = idProgram::FindType(this: p_program, name: objectName);
    if ( Type == nullptr )
    {
      idGameLock::~idGameLock(this: v11);
      return false;
    }
    Function = idProgram::FindFunction(this: p_program, name: functionName, type: Type);
  }
  else
  {
    Function = idProgram::FindFunction(this: &this->program, name: functionName);
  }
  v10 = Function != nullptr;
  idGameLock::~idGameLock(this: v11);
  return v10;
}


// ========================================================================
// __unwind$494104
// EA  : 0x82D9B6B4
// RVA : 0x00D9B6B4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494104()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?SS_FindEnumTypeInfo@idGameLocal@@UAAPBUenumTypeInfo_t@@PBD@Z
// EA  : 0x82D9B6E0
// RVA : 0x00D9B6E0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

ssEnumTypeInfo_t *__fastcall idGameLocal::SS_FindEnumTypeInfo(idGameLocal *this, const char *type)
{
  return idSuperScriptSystem::GetEnumTypeInfoFor(this: &this->superScript, type);
}


// ========================================================================
// ?GetSuperScriptMetaDataForType@idGameLocal@@UAAPBUclassMetaDataInfo_t@@PBD@Z
// EA  : 0x82D9B6F8
// RVA : 0x00D9B6F8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

ssMetaData_t *__fastcall idGameLocal::GetSuperScriptMetaDataForType(idGameLocal *this, const char *type)
{
  ssMetaData_t *MetaDataFor; // r30
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  MetaDataFor = idSuperScriptSystem::GetMetaDataFor(this: &this->superScript, type);
  idGameLock::~idGameLock(this: v6);
  return MetaDataFor;
}


// ========================================================================
// __unwind$494129_0
// EA  : 0x82D9B744
// RVA : 0x00D9B744
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494129_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetSelectedEntities@idGameLocal@@UAAHQAPAVidEntity@@H@Z
// EA  : 0x82D9B770
// RVA : 0x00D9B770
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::GetSelectedEntities(idGameLocal *this, idEntity **list, int max)
{
  int v6; // r31
  idLinkList<idEntity> *p_spawnedEntities; // r10
  idLinkList<idEntity> *next; // r11
  idEntity *owner; // r11
  idEntity **v10; // r9
  idLinkList<idEntity> *v11; // r10
  idGameLock v13[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v13, newGame: this);
  p_spawnedEntities = &this->spawnedEntities;
  next = this->spawnedEntities.next;
  v6 = 0;
  if ( next != nullptr && next != p_spawnedEntities->head )
  {
    owner = next->owner;
    if ( owner != nullptr )
    {
      v10 = list - 1;
      do
      {
        if ( (*(_BYTE *)&owner->flags & 1) != 0 )
        {
          ++v6;
          *++v10 = owner;
          if ( v6 >= max )
            break;
        }
        v11 = owner->spawnNode.next;
        if ( v11 == nullptr )
          break;
        if ( v11 == owner->spawnNode.head )
          break;
        owner = v11->owner;
      }
      while ( owner != nullptr );
    }
  }
  idGameLock::~idGameLock(this: v13);
  return v6;
}


// ========================================================================
// ?TriggerSelected@idGameLocal@@UAAXXZ
// EA  : 0x82D9B828
// RVA : 0x00D9B828
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::TriggerSelected(idGameLocal *this)
{
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r30
  idPlayer *DebugPlayer; // r3
  idEventArg *v5; // r3
  __int64 v6; // r10
  __int128 v7; // r7 OVERLAPPED
  int v8; // r8
  idLinkList<idEntity> *v9; // r11
  __int64 v10; // [sp+8h] [-B8h]
  __int64 v11; // [sp+10h] [-B0h]
  __int64 v12; // [sp+18h] [-A8h]
  __int64 v13; // [sp+20h] [-A0h]
  __int64 v14; // [sp+28h] [-98h]
  __int64 v15; // [sp+30h] [-90h]
  __int64 v16; // [sp+38h] [-88h]
  __int64 v17; // [sp+40h] [-80h]
  idGameLock v18[4]; // [sp+50h] [-70h] BYREF
  idEventArg v19; // [sp+60h] [-60h] BYREF
  idEventReceiver v20[5]; // [sp+80h] [-40h] BYREF

  idGameLock::idGameLock(this: v18, newGame: this);
  next = this->spawnedEntities.next;
  if ( next != nullptr && next != this->spawnedEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v9->owner )
    {
      if ( (*(_BYTE *)&i->flags & 1) != 0 )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        v5 = idEventArg::idEventArg(this: &v19, data: DebugPlayer);
        LODWORD(v6) = LODWORD(v5->value.q[3]);
        *(_QWORD *)((char *)&v7 + 4) = *(_QWORD *)&v5->type;
        v8 = __ROL4__(v6, 32);
        *((_QWORD *)&v7 + 1) = *(_QWORD *)&v5->value.q[1];
        idEventReceiver::ProcessEvent(
          this: v20,
          result: i,
          arg1: *(__int64 *)((char *)&v7 + 4),
          a4: *(__int64 *)((char *)&v7 - 4),
          a5: v6,
          a6: v10,
          a7: v11,
          a8: v12,
          a9: v13,
          a10: v14,
          a11: v15,
          a12: v16,
          a13: v17);
      }
      v9 = i->spawnNode.next;
      if ( v9 == nullptr )
        break;
      if ( v9 == i->spawnNode.head )
        break;
    }
  }
  idGameLock::~idGameLock(this: v18);
}


// ========================================================================
// __unwind$494755
// EA  : 0x82D9B8FC
// RVA : 0x00D9B8FC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494755()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 192 + 80));
}


// ========================================================================
// ?ClearEntitySelection@idGameLocal@@UAAXXZ
// EA  : 0x82D9B930
// RVA : 0x00D9B930
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::ClearEntitySelection(idGameLocal *this)
{
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r11
  idLinkList<idEntity> *v4; // r10
  idGameLock v5[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  next = this->spawnedEntities.next;
  if ( next != nullptr && next != this->spawnedEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v4->owner )
    {
      *(_BYTE *)&i->flags &= ~1u;
      v4 = i->spawnNode.next;
      if ( v4 == nullptr )
        break;
      if ( v4 == i->spawnNode.head )
        break;
    }
  }
  idEditEntities::ClearSelectedEntities(this: &this->editEntities);
  idGameLock::~idGameLock(this: v5);
}


// ========================================================================
// __unwind$494793_0
// EA  : 0x82D9B9E0
// RVA : 0x00D9B9E0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494793_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?GetEntityName@idGameLocal@@UBAPBDPAVidEntity@@@Z
// EA  : 0x82D9BA08
// RVA : 0x00D9BA08
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

char *__fastcall idGameLocal::GetEntityName(idGameLocal *this, idEntity *ent)
{
  char *data; // r31
  idGameLock v5[4]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v5, newGame: this);
  data = ent->name.data;
  idGameLock::~idGameLock(this: v5);
  return data;
}


// ========================================================================
// ?GetEntity@idGameLocal@@UBAPAVidEntity@@H@Z
// EA  : 0x82D9BA50
// RVA : 0x00D9BA50
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idEntity *__fastcall idGameLocal::GetEntity(idGameLocal *this, int num)
{
  idEntity *v4; // r31
  idGameLock v6[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v6, newGame: this);
  v4 = this->entities.ptr[num];
  idGameLock::~idGameLock(this: v6);
  return v4;
}


// ========================================================================
// ?EntityGetOrigin@idGameLocal@@UBAXPAVidEntity@@AAVidVec3@@@Z
// EA  : 0x82D9BAB0
// RVA : 0x00D9BAB0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityGetOrigin(idGameLocal *this, idEntity *ent, idVec3 *org)
{
  idPhysics *Physics; // r3
  float *v6; // r3
  idGameLock v7[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  if ( ent != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    org->x = *v6;
    org->y = v6[1];
    org->z = v6[2];
  }
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$494860
// EA  : 0x82D9BB20
// RVA : 0x00D9BB20
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494860()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityGetColor@idGameLocal@@UAA?BVidColor@@PAVidEntity@@@Z
// EA  : 0x82D9BB50
// RVA : 0x00D9BB50
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::EntityGetColor(idGameLocal *this, idGameLocal *result, idLight *ent)
{
  idLight *v5; // r3
  idEntity_vtbl *v6; // r11
  idGameLock v8[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v8, newGame: result);
  *(float *)&this->__vftable = 1.0;
  *(float *)&this->gameSpawnInfo.gameFlags = 1.0;
  *(float *)&this->gameSpawnInfo.mapName.len = 1.0;
  *(float *)&this->gameSpawnInfo.mapName.data = 1.0;
  if ( ent != nullptr )
  {
    v5 = idLight::CastTo(c: ent);
    if ( v5 != nullptr )
    {
      v6 = (idEntity_vtbl *)v5->__vftable;
    }
    else
    {
      v6 = (idEntity_vtbl *)ent->__vftable;
      v5 = ent;
    }
    v6->GetColor_2(this: v5, a2: (idColor *)this);
  }
  idGameLock::~idGameLock(this: v8);
  return this;
}


// ========================================================================
// __unwind$494882
// EA  : 0x82D9BBD4
// RVA : 0x00D9BBD4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494882()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityGetViewAngles@idGameLocal@@UBAXPAVidEntity@@AAVidAngles@@@Z
// EA  : 0x82D9BC08
// RVA : 0x00D9BC08
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityGetViewAngles(idGameLocal *this, idEntity *ent, idAngles *angles)
{
  idPresentable *presentable; // r3
  const idAngles *v6; // r3
  idAngles *ViewAngles; // r3
  idPhysics *Physics; // r3
  idAngles *v9; // r3
  idGameLock v10[2]; // [sp+50h] [-40h] BYREF
  idMat3 v11; // [sp+58h] [-38h] BYREF

  idGameLock::idGameLock(this: v10, newGame: this);
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: ent) != 0 )
  {
    presentable = ent->presentable;
    if ( presentable != nullptr )
    {
      v6 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
      ViewAngles = (idAngles *)idPresentablePlayer::GetViewAngles(
                                 this: (idPresentablePlayer *)&v11,
                                 result: v6,
                                 includeWeaponKick: true);
    }
    else
    {
      ViewAngles = (idAngles *)idPresentablePlayer::GetViewAngles(
                                 this: (idPresentablePlayer *)&v11,
                                 result: nullptr,
                                 includeWeaponKick: true);
    }
  }
  else
  {
    Physics = idEntity::GetPhysics(this: ent);
    v9 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
    ViewAngles = idMat3::ToAngles(this: &v11, result: v9);
  }
  angles->pitch = ViewAngles->pitch;
  angles->yaw = ViewAngles->yaw;
  angles->roll = ViewAngles->roll;
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$494906
// EA  : 0x82D9BCD4
// RVA : 0x00D9BCD4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494906()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?EntityGetEyePosition@idGameLocal@@UBAXPAVidEntity@@AAVidVec3@@@Z
// EA  : 0x82D9BD08
// RVA : 0x00D9BD08
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::EntityGetEyePosition(idGameLocal *this, idEntity *ent, idVec3 *org)
{
  idPresentable *presentable; // r3
  float *v6; // r3
  double v7; // fp12
  idPhysics *Physics; // r3
  float *v9; // r3
  idGameLock v10[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v10, newGame: this);
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: ent) != 0 )
  {
    presentable = ent->presentable;
    if ( presentable != nullptr )
      v6 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = nullptr;
    org->x = v6[11633];
    org->y = v6[11634];
    v7 = v6[11635];
  }
  else
  {
    Physics = idEntity::GetPhysics(this: ent);
    v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    org->x = *v9;
    org->y = v9[1];
    v7 = v9[2];
  }
  org->z = v7;
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$494952
// EA  : 0x82D9BDC8
// RVA : 0x00D9BDC8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_494952()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityGetSpawnPosition@idGameLocal@@UBAABVidVec3@@PAVidEntity@@@Z
// EA  : 0x82D9BDF8
// RVA : 0x00D9BDF8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

const idVec3 *__fastcall idGameLocal::EntityGetSpawnPosition(idGameLocal *this, idEntity *ent)
{
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  idGameLock::~idGameLock(this: v4);
  if ( ent != nullptr )
    return &ent->spawnPosition;
  else
    return &vec3_origin;
}


// ========================================================================
// __unwind$495003
// EA  : 0x82D9BE64
// RVA : 0x00D9BE64
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495003()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityGetSpawnOrientation@idGameLocal@@UBAABVidMat3@@PAVidEntity@@@Z
// EA  : 0x82D9BE98
// RVA : 0x00D9BE98
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

const idMat3 *__fastcall idGameLocal::EntityGetSpawnOrientation(idGameLocal *this, idEntity *ent)
{
  idGameLock v4[2]; // [sp+50h] [-20h] BYREF

  idGameLock::idGameLock(this: v4, newGame: this);
  idGameLock::~idGameLock(this: v4);
  if ( ent != nullptr )
    return &ent->spawnOrientation;
  else
    return &mat3_identity;
}


// ========================================================================
// __unwind$495022
// EA  : 0x82D9BF04
// RVA : 0x00D9BF04
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495022()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?EntityGetScale@idGameLocal@@UBA?AVidVec3@@PAVidEntity@@@Z
// EA  : 0x82D9BF38
// RVA : 0x00D9BF38
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::EntityGetScale(idGameLocal *this, idGameLocal *result, idEntity *ent)
{
  idGameLock v6[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v6, newGame: result);
  *(float *)&this->__vftable = 1.0;
  *(float *)&this->gameSpawnInfo.gameFlags = 1.0;
  *(float *)&this->gameSpawnInfo.mapName.len = 1.0;
  if ( ent != nullptr )
    ent->GetScale(this: ent, a2: (idVec3 *)this);
  idGameLock::~idGameLock(this: v6);
  return this;
}


// ========================================================================
// __unwind$495039
// EA  : 0x82D9BFA0
// RVA : 0x00D9BFA0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495039()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?EntityGetEntityDef@idGameLocal@@UBAPBVidDeclEntityDef@@PAVidEntity@@@Z
// EA  : 0x82D9BFC8
// RVA : 0x00D9BFC8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

const idDeclEntityDef *__fastcall idGameLocal::EntityGetEntityDef(idGameLocal *this, idEntity *ent)
{
  if ( ent != nullptr )
    return ent->entityDef;
  else
    return nullptr;
}


// ========================================================================
// ?MapSave@idGameLocal@@UBA_NPBD_N@Z
// EA  : 0x82D9BFE8
// RVA : 0x00D9BFE8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::MapSave(idGameLocal *this, const char *path, bool soundsOnly)
{
  idMapFile *v6; // r3
  const char *data; // r4
  int v8; // r30
  const char *v10; // r4
  int v11; // r30
  idGameLock v12[12]; // [sp+50h] [-30h] BYREF

  idGameLock::idGameLock(this: v12, newGame: this);
  v6 = this->GetLevelMap(this);
  if ( v6 != nullptr )
  {
    v6->game = gameLocal;
    if ( soundsOnly )
    {
      data = path;
      if ( path == nullptr )
        data = v6->name.data;
      v8 = idMapFile::WriteSounds(this: v6, fileName: data, osPath: false);
      idGameLock::~idGameLock(this: v12);
      return v8;
    }
    else
    {
      v10 = path;
      if ( path == nullptr )
        v10 = v6->name.data;
      v11 = idMapFile::Write(this: v6, fileName: v10, osPath: false);
      idGameLock::~idGameLock(this: v12);
      return v11;
    }
  }
  else
  {
    idLib::Warning(fmt: "Could not GetLevelMap");
    idGameLock::~idGameLock(this: v12);
    return 0;
  }
}


// ========================================================================
// __unwind$495073_1
// EA  : 0x82D9C0BC
// RVA : 0x00D9C0BC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495073_1()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 80));
}


// ========================================================================
// ?MapSetEntityReferenceId@idGameLocal@@UAAXPAVidEntity@@PBD@Z
// EA  : 0x82D9C0E8
// RVA : 0x00D9C0E8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::MapSetEntityReferenceId(idGameLocal *this, idEntity *ent, const char *refId)
{
  idMapFile *v5; // r3
  idMapEntity *Entity; // r3

  if ( ent != nullptr )
  {
    v5 = this->GetLevelMap(this);
    if ( v5 != nullptr )
    {
      Entity = idMapFile::FindEntity(this: v5, name: ent->name.data, index: nullptr);
      if ( Entity != nullptr )
        idStr::operator=(this: &Entity->refId, text: refId);
    }
  }
}


// ========================================================================
// ?LoadScriptForMapFile@idGameLocal@@UAA_NPBD@Z
// EA  : 0x82D9C168
// RVA : 0x00D9C168
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::LoadScriptForMapFile(idGameLocal *this, const char *mapName)
{
  idProgram *p_program; // r30
  BOOL v5; // r30
  idGameLock v7[4]; // [sp+50h] [-50h] BYREF
  idStr v8[2]; // [sp+60h] [-40h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  v8[0].len = 0;
  v8[0].allocedAndFlag = 20;
  v8[0].data = v8[0].baseBuffer;
  v8[0].baseBuffer[0] = 0;
  p_program = &this->program;
  idProgram::Restart(this: p_program);
  idStr::operator=(this: v8, text: mapName);
  idStr::SetFileExtension(this: v8, extension: ".script");
  if ( fileSystem->FileExists(this: fileSystem, a2: v8[0].data, a3: false) )
  {
    v5 = idProgram::CompileFile(this: p_program, filename: v8[0].data, flags: 3);
    idStr::FreeData(this: v8);
    idGameLock::~idGameLock(this: v7);
    return v5;
  }
  else
  {
    idStr::FreeData(this: v8);
    idGameLock::~idGameLock(this: v7);
    return 1;
  }
}


// ========================================================================
// __unwind$495151
// EA  : 0x82D9C248
// RVA : 0x00D9C248
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495151()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$495152
// EA  : 0x82D9C270
// RVA : 0x00D9C270
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495152()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?TracePoint@idGameLocal@@UAA_NAAUtrace_t@@ABVidVec3@@1HPBVidEntity@@@Z
// EA  : 0x82D9C298
// RVA : 0x00D9C298
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

BOOL __fastcall idGameLocal::TracePoint(
        idGameLocal *this,
        trace_t *results,
        const idVec3 *start,
        const idVec3 *end,
        int contentMask,
        const idEntity *passEntity)
{
  int entityNumber; // r8

  if ( passEntity != nullptr )
    entityNumber = passEntity->entityNumber;
  else
    entityNumber = 0x1FFF;
  return idClip::TracePoint(
           this: &this->clientGame.clip,
           result: results,
           start,
           end,
           clipMask: contentMask,
           passEntityNumber: entityNumber);
}


// ========================================================================
// ?SP_GetGuardSplineEntry@idGameLocal@@UAAXHAAVidStr@@AAM1@Z
// EA  : 0x82D9C2C0
// RVA : 0x00D9C2C0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::SP_GetGuardSplineEntry(
        idGameLocal *this,
        int num,
        idStr *splineName,
        float *start,
        float *end)
{
  idList<navSplineSegment_t,5> *p_splineSegmentList; // r29
  int v9; // r30
  idGameLock v10[16]; // [sp+50h] [-40h] BYREF

  p_splineSegmentList = &this->splineSegmentList;
  v9 = num;
  idGameLock::idGameLock(this: v10, newGame: this);
  idStr::operator=(this: splineName, text: p_splineSegmentList->list[v9].navSpline->splinePath->name.data);
  *start = p_splineSegmentList->list[v9].start;
  *end = p_splineSegmentList->list[v9].end;
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$495233
// EA  : 0x82D9C34C
// RVA : 0x00D9C34C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495233()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?EntityGetSoundDistances@idGameLocal@@UAA_NPAVidEntity@@AAM1@Z
// EA  : 0x82D9C380
// RVA : 0x00D9C380
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::EntityGetSoundDistances(idGameLocal *this, idEntity *ent, float *min, float *max)
{
  idTypeInfoObject *v8; // r29
  const idTypeInfoTools *v9; // r30
  const char *Classname; // r3
  idTypeInfoObject *v11; // r30
  float *v13; // r3
  double v16; // fp12
  double v17; // fp11
  double v20; // fp12
  double v21; // fp11
  idGameLock v22; // [sp+50h] [-80h] BYREF
  idTypeInfoObject *v23; // [sp+54h] [-7Ch]
  idStr v24; // [sp+60h] [-70h] BYREF

  idGameLock::idGameLock(this: &v22, newGame: this);
  v8 = (idTypeInfoObject *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0x2Cu,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v23 = v8;
  if ( v8 != nullptr )
  {
    v9 = this->GetTypeInfoTools(this);
    Classname = idClass::GetClassname(this: ent);
    v11 = idTypeInfoObject::idTypeInfoObject(this: v8, objectPtr: ent, objectType: Classname, ti: v9);
  }
  else
  {
    v11 = nullptr;
  }
  if ( v11 != nullptr )
  {
    *min = 0.0;
    *max = 0.0;
    idTypeInfoObject::GetFloat(this: v11, variable: &TIV_idSound_parms_minDistance, f: min);
    idTypeInfoObject::GetFloat(this: v11, variable: &TIV_idSound_parms_maxDistance, f: max);
    v24.len = 0;
    v24.allocedAndFlag = 20;
    v24.data = v24.baseBuffer;
    v24.baseBuffer[0] = 0;
    idTypeInfoObject::GetStrPtrType(this: v11, variable: &TIV_idSound_soundShader, s: &v24, resolvePtrs: false);
    if ( v24.len != 0
      || (idTypeInfoObject::GetStrPtrType(
            this: v11,
            variable: &TIV_idLight_soundInfo_shader,
            s: &v24,
            resolvePtrs: false),
          v24.len != 0) )
    {
      if ( v24.data != nullptr )
      {
        v13 = (float *)idDeclInfo::FindWithInheritance(
                         this: &idSoundShader::resourceList,
                         name: v24.data,
                         makeDefault: false);
        if ( v13 != nullptr )
        {
          if ( *min == 0.0 )
          {
            _FP0 = v13[19];
            __asm { fsel      f13, f0, f31, f0 }
            v16 = v13[16];
            v17 = v13[18];
            v23 = (idTypeInfoObject *)(v13 + 16);
            *min = (float)((float)_FP13 + (float)v16) * (float)v17;
          }
          if ( *max == 0.0 )
          {
            _FP0 = v13[20];
            __asm { fsel      f13, f0, f0, f31 }
            v20 = v13[17];
            v21 = v13[18];
            v23 = (idTypeInfoObject *)(v13 + 16);
            *max = (float)((float)_FP13 + (float)v20) * (float)v21;
          }
        }
      }
    }
    if ( *min == 0.0 && *max == 0.0 )
    {
      idStr::FreeData(this: &v24);
      idGameLock::~idGameLock(this: &v22);
      return 0;
    }
    else
    {
      idStr::FreeData(this: &v24);
      idGameLock::~idGameLock(this: &v22);
      return 1;
    }
  }
  else
  {
    idGameLock::~idGameLock(this: &v22);
    return 0;
  }
}


// ========================================================================
// __unwind$495683
// EA  : 0x82D9C5B0
// RVA : 0x00D9C5B0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495683()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$495684
// EA  : 0x82D9C5D8
// RVA : 0x00D9C5D8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall _unwind_495684(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 208 + 84), tag: a2);
}


// ========================================================================
// __unwind$495685
// EA  : 0x82D9C600
// RVA : 0x00D9C600
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495685()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?EntityIsNameUnique@idGameLocal@@UBA_NPBDPBVidEntity@@@Z
// EA  : 0x82D9C630
// RVA : 0x00D9C630
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::EntityIsNameUnique(idGameLocal *this, const char *name, const idEntity *ignoreEnt)
{
  idHashIndex *p_entityHash; // r29
  int v7; // r30
  idEntity *v8; // r11
  idGameLock v10[16]; // [sp+50h] [-40h] BYREF

  p_entityHash = &this->entityHash;
  idGameLock::idGameLock(this: v10, newGame: this);
  v7 = p_entityHash->hash[this->entityHash.hashMask
                        & idHashIndex::GenerateKeyForString(this: &this->entityHash, string: name, caseSensitive: false)
                        & this->entityHash.lookupMask];
  if ( v7 == -1 )
  {
LABEL_6:
    idGameLock::~idGameLock(this: v10);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v8 = this->entities.ptr[v7];
      if ( v8 != nullptr && v8 != ignoreEnt && idStr::Icmp(s1: v8->name.data, s2: name) == 0 )
        break;
      v7 = this->entityHash.indexChain[v7 & this->entityHash.lookupMask];
      if ( v7 == -1 )
        goto LABEL_6;
    }
    idGameLock::~idGameLock(this: v10);
    return 0;
  }
}


// ========================================================================
// __unwind$495852_0
// EA  : 0x82D9C704
// RVA : 0x00D9C704
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495852_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?EntitySetScriptObject@idGameLocal@@UBA?AVidStr@@PAVidEntity@@PBDH_N@Z
// EA  : 0x82D9C738
// RVA : 0x00D9C738
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::EntitySetScriptObject(
        idGameLocal *this,
        idGameLocal *result,
        idEntity *ent,
        const char *objectName,
        int spot,
        bool clear)
{
  bfx::Planner3D *v10; // r3
  idScriptObject *v11; // r3
  const char *TypeName; // r3
  idScriptObject *v13; // r3
  idGameLock v15[15]; // [sp+54h] [-3Ch] BYREF

  idGameLock::idGameLock(this: v15, newGame: result);
  idStr::idStr((idStr *)this, text: &byte_8200D768);
  if ( ent != nullptr )
  {
    v10 = (bfx::Planner3D *)ent->GetScriptObject_2(this: ent);
    if ( idScriptObject::GetTypeDef(this: v10) != nullptr )
    {
      v11 = ent->GetScriptObject_2(this: ent);
      TypeName = idScriptObject::GetTypeName(this: v11);
      idStr::operator=((idStr *)this, text: TypeName);
    }
    v13 = ent->GetScriptObject_2(this: ent);
    idScriptObject::SetType(this: v13, typeName: objectName, clear);
  }
  idGameLock::~idGameLock(this: v15);
  return this;
}


// ========================================================================
// __unwind$495902_0
// EA  : 0x82D9C804
// RVA : 0x00D9C804
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495902_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$495903_0
// EA  : 0x82D9C82C
// RVA : 0x00D9C82C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495903_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?MapSaveReference@idGameLocal@@UBA_NPBD0_N@Z
// EA  : 0x82D9C878
// RVA : 0x00D9C878
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::MapSaveReference(
        idGameLocal *this,
        const char *referenceId,
        const char *path,
        bool soundsOnly)
{
  idMapFile *v8; // r29
  idGame *v9; // r3
  idMapFile *v10; // r30
  int ReferenceMap; // r3
  idDeclEntityDef *v12; // r25
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r7
  int v17; // r6
  int v18; // r5
  const char *data; // r4
  __int64 v20; // r8
  int v21; // r6
  int v22; // r5
  int v23; // r3
  const char *v24; // r4
  int v25; // r29
  int v27; // [sp+8h] [-158h]
  int v28; // [sp+Ch] [-154h]
  int v29; // [sp+10h] [-150h]
  int v30; // [sp+14h] [-14Ch]
  int v31; // [sp+18h] [-148h]
  idMapEntity *v32; // [sp+1Ch] [-144h]
  idGameLock v33[4]; // [sp+50h] [-110h] BYREF
  idStr v34; // [sp+60h] [-100h] BYREF
  idMapFile v35; // [sp+80h] [-E0h] BYREF

  idGameLock::idGameLock(this: v33, newGame: this);
  v8 = this->GetLevelMap(this);
  if ( v8 == nullptr )
  {
    idLib::Warning(fmt: "Could not GetLevelMap");
LABEL_21:
    idGameLock::~idGameLock(this: v33);
    return 0;
  }
  idMapEntity::idMapEntity(this: (idMapEntity *)&v35.name.baseBuffer[16]);
  v9 = (idGame *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                   size: 0x98u,
                   tag: TAG_NEW,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v33[1].prevGame = v9;
  if ( v9 != nullptr )
    v10 = idMapFile::idMapFile(this: (idMapFile *)v9);
  else
    v10 = nullptr;
  if ( v10 == nullptr )
  {
    idLib::Warning(fmt: "Could not create reference map '%s'!", path);
    idMapEntity::~idMapEntity(this: (idMapEntity *)&v35.name.baseBuffer[16]);
    goto LABEL_21;
  }
  v10->game = gameLocal;
  if ( path != nullptr )
  {
    idStr::operator=(this: &v10->name, text: path);
    ReferenceMap = idMapFile::FindReferenceMap(this: v8, name: path);
    if ( ReferenceMap < 0 )
    {
      idLib::Warning(fmt: "Could not find reference map named: %s!", path);
    }
    else
    {
      idStr::idStr(this: &v34, text: v8->referenceMaps.list[ReferenceMap].worldSpawnText.data);
      v12 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
      idResource::SetName(this: &v12->idDecl, _name: "world");
      idDecl::SetText(this: &v12->idDecl, text: v34.data, length: 0);
      idDecl::ReParse(this: &v12->idDecl, fromDisk: false);
      idMapEntity::SetEntityDef(this: (idMapEntity *)&v35.name.baseBuffer[16], def: v12);
      idMapFile::AddEntity(
        this: v10,
        mapEnt: (idMapEntity *)&v35.name.baseBuffer[16],
        a3: v18,
        a4: v17,
        a5: v16,
        a6: v15,
        a7: v14,
        a8: v13,
        a9: v27,
        a10: v28,
        a11: v29,
        a12: v30,
        a13: v31,
        a14: v32);
      idStr::FreeData(this: &v34);
    }
  }
  else
  {
    idStr::operator=(this: &v10->name, text: v8->name.data);
  }
  idMapFile::CopyMapEntities(this: &v35, result: (idStr *)v10, map: v8, refId: referenceId);
  if ( soundsOnly )
  {
    data = path;
    if ( path == nullptr )
      data = v10->name.data;
    v23 = idMapFile::WriteSounds(this: v10, fileName: data, osPath: false);
  }
  else
  {
    v24 = path;
    if ( path == nullptr )
      v24 = v10->name.data;
    v23 = idMapFile::Write(this: v10, fileName: v24, osPath: false);
  }
  v25 = v23;
  idMapFile::ClearCopiedEntities(this: v10, refname: (const idStr *)&v35, a3: v22, a4: v21, a5: v20);
  ((void (__fastcall *)(idMapFile *, int))v10->dtr_idMapFile)(a1: v10, a2: 1);
  idStr::FreeData(this: (idStr *)&v35);
  idMapEntity::~idMapEntity(this: (idMapEntity *)&v35.name.baseBuffer[16]);
  idGameLock::~idGameLock(this: v33);
  return v25;
}


// ========================================================================
// __unwind$495942
// EA  : 0x82D9CAC0
// RVA : 0x00D9CAC0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495942()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$495943
// EA  : 0x82D9CAE8
// RVA : 0x00D9CAE8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495943()
{
  int v0; // r12

  idMapEntity::~idMapEntity(this: (idMapEntity *)(v0 - 352 + 160));
}


// ========================================================================
// __unwind$495944_0
// EA  : 0x82D9CB10
// RVA : 0x00D9CB10
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall _unwind_495944_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 352 + 84), tag: a2);
}


// ========================================================================
// __unwind$495945_0
// EA  : 0x82D9CB38
// RVA : 0x00D9CB38
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495945_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$495946
// EA  : 0x82D9CB60
// RVA : 0x00D9CB60
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_495946()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 128));
}


// ========================================================================
// ?MapFindEntity@idGameLocal@@UAAPAVidMapEntity@@PAVidEntity@@@Z
// EA  : 0x82D9CB90
// RVA : 0x00D9CB90
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idMapEntity *__fastcall idGameLocal::MapFindEntity(idGameLocal *this, idEntity *ent)
{
  idMapFile *v3; // r3
  idMapEntity *Entity; // r30
  idStr v6; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v6, text: ent->name.data);
  v3 = this->GetLevelMap(this);
  if ( v3 != nullptr )
  {
    Entity = idMapFile::FindEntity(this: v3, name: v6.data, index: nullptr);
    idStr::FreeData(this: &v6);
    return Entity;
  }
  else
  {
    idStr::FreeData(this: &v6);
    return nullptr;
  }
}


// ========================================================================
// __unwind$496087
// EA  : 0x82D9CC18
// RVA : 0x00D9CC18
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?AF_SpawnEntity@idGameLocal@@UAA_NPBD@Z
// EA  : 0x82D9CC48
// RVA : 0x00D9CC48
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::AF_SpawnEntity(idGameLocal *this, const char *fileName)
{
  idGameLocal *v4; // r3
  idPlayer *DebugPlayer; // r30
  const idDecl *v7; // r26
  idPhysics *Physics; // r29
  idPresentable *presentable; // r3
  const idAngles *v10; // r4
  idVec3 *v11; // r3
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  float *v15; // r3
  double v16; // fp9
  double v17; // fp6
  double v18; // fp5
  idPresentable *v19; // r3
  const idAngles *v20; // r4
  double v21; // fp13
  idEntity *v22; // r3
  idAFEntity_Generic *v23; // r30
  const idDeclAF *v24; // r3
  idPhysics *v25; // r3
  int v26; // r5
  idPhysics *v27; // r3
  idGameLock v28; // [sp+50h] [-F0h] BYREF
  float v29; // [sp+54h] [-ECh]
  idVec3 v30; // [sp+58h] [-E8h] BYREF
  idVec3 v31; // [sp+68h] [-D8h] BYREF
  idMat3 v32; // [sp+78h] [-C8h] BYREF
  idMat3 v33; // [sp+B0h] [-90h] BYREF

  v4 = (idGameLocal *)common->Game(this: common);
  idGameLock::idGameLock(this: &v28, newGame: v4);
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr
    && fileName != nullptr
    && (v7 = idDeclInfo::FindWithInheritance(this: &idDeclAF::resourceList, name: fileName, makeDefault: false)) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: DebugPlayer);
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v10 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = nullptr;
    v31.y = *((float *)&idPresentablePlayer::GetViewAngles(
                          this: (idPresentablePlayer *)&v32.mat[1].y,
                          result: v10,
                          includeWeaponKick: true)->__vftable
            + 1);
    v31.x = 0.0;
    v31.z = 0.0;
    v11 = idAngles::ToForward(this: (idAngles *)&v32.mat[2].z, result: &v31);
    v12 = (float)(v11->z * (float)80.0);
    v13 = (float)(v11->y * (float)80.0);
    v14 = (float)(v11->x * (float)80.0);
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v16 = (float)(v15[2] + (float)v12);
    v17 = (float)(*v15 + (float)v14);
    v18 = (float)(v15[1] + (float)v13);
    v30.y = v15[1] + (float)v13;
    v30.x = v17;
    v29 = v18;
    v30.z = (float)v16 + (float)1.0;
    v19 = DebugPlayer->presentable;
    if ( v19 != nullptr )
      v20 = (const idAngles *)v19->GetPlayerInterface_2(this: v19);
    else
      v20 = nullptr;
    v21 = *((float *)&idPresentablePlayer::GetViewAngles(
                        this: (idPresentablePlayer *)&v32.mat[2].z,
                        result: v20,
                        includeWeaponKick: true)->__vftable
          + 1);
    v32.mat[0].x = 0.0;
    v32.mat[0].z = 0.0;
    v32.mat[0].y = (float)v21 + (float)180.0;
    idAngles::ToMat3(this: (idAngles *)&v33, result: &v32);
    v22 = idGameLocal::SpawnEntityType(
            this,
            typeInfo: &idAFEntity_Generic::Type,
            forceEntityNumber: -1,
            _model: nullptr);
    v22->spawnPosition = v30;
    v22->spawnOrientation.mat[0].x = v33.mat[0].x;
    v23 = (idAFEntity_Generic *)v22;
    v22->spawnOrientation.mat[0].y = v33.mat[0].y;
    LODWORD(v29) = &v22->spawnOrientation.mat[2];
    v22->spawnOrientation.mat[0].z = v33.mat[0].z;
    v22->spawnOrientation.mat[1] = v33.mat[1];
    v22->spawnOrientation.mat[2] = v33.mat[2];
    idEntity::SetOrigin(this: v22, org: &v30);
    v23->SetAxis(this: v23, a2: &v33);
    v23->SetModelByName(this: v23, a2: *(const char **)(v7[1].trackedMemory + 8));
    v24 = (const idDeclAF *)idDeclInfo::FindWithInheritance(
                              this: &idDeclAF::resourceList,
                              name: fileName,
                              makeDefault: false);
    if ( (unsigned __int8)idAFEntity_Generic::LoadAF(this: v23, decl: v24) != 0 )
    {
      v25 = (idPhysics *)v23->GetAF_2(this: v23);
      idEntity::SetPhysics(this: v23, phys: v25 + 6, a3: v26);
      v27 = idEntity::GetPhysics(this: v23);
      v27->PutToRest(this: v27);
      idEntity::BecomeActive(this: v23, flags: 1);
      idAFEntity_Generic::InitTestAF(this: v23);
      idGameLock::~idGameLock(this: &v28);
      return 1;
    }
    else
    {
      ((void (__fastcall *)(idAFEntity_Generic *, int))v23->dtr_idClass)(a1: v23, a2: 1);
      idGameLock::~idGameLock(this: &v28);
      return 0;
    }
  }
  else
  {
    idGameLock::~idGameLock(this: &v28);
    return 0;
  }
}


// ========================================================================
// __unwind$496147
// EA  : 0x82D9CFB0
// RVA : 0x00D9CFB0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496147()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 320 + 80));
}


// ========================================================================
// ?AF_UpdateEntities@idGameLocal@@UAAXPBD@Z
// EA  : 0x82D9CFE0
// RVA : 0x00D9CFE0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::AF_UpdateEntities(idGameLocal *this, const char *fileName)
{
  const idDeclAF *v4; // r28
  idLinkList<idEntity> *next; // r11
  idAFEntity_Generic *i; // r29
  idAFEntity_Generic *v7; // r30
  int v8; // r3
  idLinkList<idEntity> *v9; // r11
  idGameLock v10[16]; // [sp+50h] [-40h] BYREF

  idGameLock::idGameLock(this: v10, newGame: this);
  if ( fileName != nullptr )
    v4 = (const idDeclAF *)idDeclInfo::FindWithInheritance(
                             this: &idDeclAF::resourceList,
                             name: fileName,
                             makeDefault: false);
  else
    v4 = nullptr;
  next = this->spawnedEntities.next;
  if ( next != nullptr && next != this->spawnedEntities.head )
  {
    for ( i = (idAFEntity_Generic *)next->owner; i != nullptr; i = (idAFEntity_Generic *)v9->owner )
    {
      if ( (unsigned __int8)idAFEntity_Generic::IsTypeOf(c: i) != 0 )
      {
        v7 = idAFEntity_Generic::CastTo(c: i);
        v7->GetAF_2(this: v7);
        if ( idStr::Icmp(s1: v4->name.str, s2: "<unknown>") == 0 )
        {
          idAFEntity_Generic::LoadAF(this: v7, decl: v4);
          v8 = (int)v7->GetAF_2(this: v7);
          (*(void (__fastcall **)(int))(*(_DWORD *)(v8 + 288) + 156))(a1: v8 + 288);
        }
      }
      v9 = i->spawnNode.next;
      if ( v9 == nullptr )
        break;
      if ( v9 == i->spawnNode.head )
        break;
    }
  }
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$496342
// EA  : 0x82D9D110
// RVA : 0x00D9D110
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496342()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?AF_UndoChanges@idGameLocal@@UAAXXZ
// EA  : 0x82D9D140
// RVA : 0x00D9D140
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::AF_UndoChanges(idGameLocal *this)
{
  int v2; // r26
  int i; // r22
  idResource *v4; // r3
  const idDeclAF *v5; // r28
  idLinkList<idEntity> *next; // r11
  idAFEntity_Generic *j; // r29
  idAFEntity_Generic *v8; // r30
  idLinkList<idEntity> *v9; // r11
  idGameLock v10[24]; // [sp+50h] [-60h] BYREF

  idGameLock::idGameLock(this: v10, newGame: this);
  v2 = 0;
  for ( i = idDeclAF::resourceList.num; v2 < i; ++v2 )
  {
    v4 = idResourceList::Index(this: &idDeclAF::resourceList, index: v2);
    v5 = (const idDeclAF *)v4;
    if ( HIBYTE(v4[1].resourceError) != 0 )
    {
      idDecl::Revert(this: (idDecl *)v4);
      next = this->spawnedEntities.next;
      if ( next != nullptr && next != this->spawnedEntities.head )
      {
        for ( j = (idAFEntity_Generic *)next->owner; j != nullptr; j = (idAFEntity_Generic *)v9->owner )
        {
          if ( (unsigned __int8)idAFEntity_Generic::IsTypeOf(c: j) != 0 )
          {
            v8 = idAFEntity_Generic::CastTo(c: j);
            v8->GetAF_2(this: v8);
            if ( idStr::Icmp(s1: v5->name.str, s2: "<unknown>") == 0 )
              idAFEntity_Generic::LoadAF(this: v8, decl: v5);
          }
          v9 = j->spawnNode.next;
          if ( v9 == nullptr )
            break;
          if ( v9 == j->spawnNode.head )
            break;
        }
      }
    }
  }
  idGameLock::~idGameLock(this: v10);
}


// ========================================================================
// __unwind$496402
// EA  : 0x82D9D260
// RVA : 0x00D9D260
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496402()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetScriptCompileError@idGameLocal@@UAA?AVidStr@@XZ
// EA  : 0x82D9D290
// RVA : 0x00D9D290
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

idGameLocal *__fastcall idGameLocal::GetScriptCompileError(idGameLocal *this, idGameLocal *result)
{
  idGameLock v5[11]; // [sp+54h] [-2Ch] BYREF

  idGameLock::idGameLock(this: v5, newGame: result);
  idStr::idStr((idStr *)this, text: result->program.errMsg.data);
  idGameLock::~idGameLock(this: v5);
  return this;
}


// ========================================================================
// __unwind$496462_0
// EA  : 0x82D9D2EC
// RVA : 0x00D9D2EC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496462_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$496463_0
// EA  : 0x82D9D314
// RVA : 0x00D9D314
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496463_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?SP_GetSplineLength@idGameLocal@@UAAMVidStr@@@Z
// EA  : 0x82D9D360
// RVA : 0x00D9D360
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

float __fastcall idGameLocal::SP_GetSplineLength(idGameLocal *this, idStr *splineName)
{
  idStr *v4; // r3
  idNavSpline *NavSpline; // r3
  double length; // fp31
  double v7; // fp1
  idGameLock v9[4]; // [sp+50h] [-60h] BYREF
  idStr v10; // [sp+60h] [-50h] BYREF

  idGameLock::idGameLock(this: v9, newGame: this);
  v4 = idStr::idStr(this: &v10, text: splineName);
  NavSpline = idNavSplinePathMgr::FindNavSpline(this: &this->aiSplinePathMgr, splineName: v4, searchExact: true);
  if ( NavSpline != nullptr )
    length = NavSpline->length;
  else
    length = 0.0;
  idGameLock::~idGameLock(this: v9);
  idStr::FreeData(this: splineName);
  v7 = length;
  return *((float *)&v7 + 1);
}


// ========================================================================
// __unwind$496500_0
// EA  : 0x82D9D3E4
// RVA : 0x00D9D3E4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496500_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 176 + 204));
}


// ========================================================================
// __unwind$496501
// EA  : 0x82D9D40C
// RVA : 0x00D9D40C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496501()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetLayerList@idGameLocal@@UAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9D4A8
// RVA : 0x00D9D4A8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::GetLayerList(idGameLocal *this, idList<idStr,5> *list)
{
  int v3; // r28
  int v4; // r29
  const char *str; // r4
  const idDecl *v6; // r11
  idGameLock v7[4]; // [sp+50h] [-60h] BYREF
  idStr v8[2]; // [sp+60h] [-50h] BYREF

  idGameLock::idGameLock(this: v7, newGame: this);
  v3 = 0;
  if ( idDeclLayer::resourceList.declSources.num > 0 )
  {
    v4 = 0;
    do
    {
      v7[1].prevGame = (const idGame *)&idDeclLayer::resourceList.declSources.list[v4];
      str = idDeclLayer::resourceList.declSources.list[v4]->name.str;
      if ( str != nullptr )
        v6 = idDeclInfo::FindWithInheritance(this: &idDeclLayer::resourceList, name: str, makeDefault: false);
      else
        v6 = nullptr;
      idStr::idStr(this: v8, text: v6->name.str);
      if ( idList<idStr,5>::FindIndex(this: list, obj: v8, startIndex: 0) < 0 )
        idList<idStr,5>::Append(this: list, obj: v8);
      idStr::FreeData(this: v8);
      ++v3;
      ++v4;
    }
    while ( v3 < idDeclLayer::resourceList.declSources.num );
  }
  idGameLock::~idGameLock(this: v7);
}


// ========================================================================
// __unwind$496680
// EA  : 0x82D9D574
// RVA : 0x00D9D574
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496680()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$496681
// EA  : 0x82D9D59C
// RVA : 0x00D9D59C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496681()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?MapGetEntityLayers@idGameLocal@@UBAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9D5C8
// RVA : 0x00D9D5C8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::MapGetEntityLayers(idGameLocal *this, idList<idStr,5> *list)
{
  idMapFile *v3; // r25
  int i; // r26
  idMapEntity *Entity; // r3
  idList<idStr,5> *p_layerList; // r29
  int v7; // r28
  int v8; // r30
  const idStr *v9; // r31

  v3 = this->GetLevelMap(this);
  if ( list->listStatic == 0 || list->listStatic == 2 )
  {
    if ( list->list != nullptr )
      idListArrayDelete<idStr>(ptr: list->list, num: list->size);
    list->list = nullptr;
    list->size = 0;
  }
  list->num = 0;
  if ( v3 != nullptr )
  {
    for ( i = 0; i < (int)idPhysics_Static::GetNumContactPhysics(this: (idDeclEntityDef *)v3); ++i )
    {
      Entity = idMapFile::GetEntity(this: v3, i);
      p_layerList = &Entity->layerList;
      v7 = 0;
      if ( Entity->layerList.num > 0 )
      {
        v8 = 0;
        do
        {
          v9 = &p_layerList->list[v8];
          if ( idList<idStr,5>::FindIndex(this: list, obj: v9, startIndex: 0) < 0 )
            idList<idStr,5>::Append(this: list, obj: v9);
          ++v7;
          ++v8;
        }
        while ( v7 < p_layerList->num );
      }
    }
  }
}


// ========================================================================
// ?GetBinaryAnimationStates@idGameLocal@@UAAXAAV?$idList@PAVidTreeAnimator@@$04@@AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9D6C8
// RVA : 0x00D9D6C8
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::GetBinaryAnimationStates(
        idGameLocal *this,
        idList<enum encounterGroupRole_t,5> *treeAnimators,
        idList<idStr,5> *animNames)
{
  int v5; // r26
  idArray<idEntity *,8192> *p_entities; // r27
  idBinaryAnimation *v7; // r30
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  idTreeAnimator *v11[4]; // [sp+50h] [-80h] BYREF
  idStr v12[3]; // [sp+60h] [-70h] BYREF

  v5 = 0x2000;
  p_entities = &this->entities;
  do
  {
    v7 = (idBinaryAnimation *)p_entities->ptr[0];
    if ( p_entities->ptr[0] != nullptr )
    {
      v8 = *(_DWORD *)(v7->GetType(this: (struct idBinaryAnimation *)p_entities->ptr[0]) + 36);
      if ( v8 < idBinaryAnimation::Type.typeNum || (v10 = v8 <= idBinaryAnimation::Type.lastChild, v9 = 1, !v10) )
        v9 = 0;
      if ( v9 != 0 )
      {
        v12[0].allocedAndFlag = 20;
        v12[0].len = 0;
        v12[0].data = v12[0].baseBuffer;
        v12[0].baseBuffer[0] = 0;
        if ( (unsigned __int8)idBinaryAnimation::GetBinaryAnimationState(this: v7, treeAnimator: v11, animName: v12) == 1 )
        {
          idList<idStr,5>::Append(this: animNames, obj: v12);
          idList<idAnimWebBlendTree *,5>::Append(this: treeAnimators, obj: (encounterGroupRole_t *)v11);
        }
        idStr::FreeData(this: v12);
      }
    }
    --v5;
    p_entities = (idArray<idEntity *,8192> *)((char *)p_entities + 4);
  }
  while ( v5 != 0 );
}


// ========================================================================
// __unwind$496819_0
// EA  : 0x82D9D7B0
// RVA : 0x00D9D7B0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496819_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?SP_BuildGuardSplineList@idGameLocal@@UAAHVidVec3@@MAAM@Z
// EA  : 0x82D9D7E0
// RVA : 0x00D9D7E0
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

int __fastcall idGameLocal::SP_BuildGuardSplineList(
        idGameLocal *this,
        idVec3 *worldPos,
        double distance,
        float *startDistance,
        int a5,
        float *a6)
{
  int num; // r30
  float z; // r11
  idList<navSplineSegment_t,5> *SplinesWithinDistance; // r28
  int v13; // r30
  int v14; // r29
  idGameLock v16[2]; // [sp+70h] [-70h] BYREF
  idVec3 v17; // [sp+78h] [-68h] BYREF
  idNavSplinePosition v18[2]; // [sp+88h] [-58h] BYREF

  idGameLock::idGameLock(this: v16, newGame: this);
  ((void (__fastcall *)(idVec3 *, idAISplinePathMgr *, idVec3 *, _DWORD, _DWORD, double, double))this->aiSplinePathMgr.GetClosestPathPosition)(
    a1: &v17,
    a2: &this->aiSplinePathMgr,
    a3: worldPos,
    a4: __ROL4__(LODWORD(vec3_origin.x), 32),
    a5: 0,
    a6: 8000.0,
    a7: 0.0099999998);
  if ( distance == -1.0 )
  {
    num = 1;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineSegmentList);
    z = v17.z;
    *a6 = 0.0;
    v18[0].distance = z;
    v18[0].rightDistance = 0.0;
    v18[0].navSpline = *(idNavSpline **)(LODWORD(z) + 12);
    idList<idRenderModelEffects::deferredStage_t,5>::Append(
      this: (idList<aas2Edge_t,37> *)&this->splineSegmentList,
      obj: (const aas2Edge_t *)v18);
  }
  else
  {
    idNavSplinePosition::GetWorldPos(this: v18, result: &v17);
    *a6 = v17.x;
    SplinesWithinDistance = idNavSplinePathMgr::GetSplinesWithinDistance(
                              this: (idNavSplinePathMgr *)LODWORD(v17.x),
                              pathPos: (idNavSpline *)LODWORD(v17.y),
                              distance);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineSegmentList);
    v13 = 0;
    if ( SplinesWithinDistance->num > 0 )
    {
      v14 = 0;
      do
      {
        idList<idRenderModelEffects::deferredStage_t,5>::Append(
          this: (idList<aas2Edge_t,37> *)&this->splineSegmentList,
          obj: (const aas2Edge_t *)&SplinesWithinDistance->list[v14]);
        ++v13;
        ++v14;
      }
      while ( v13 < SplinesWithinDistance->num );
    }
    num = this->splineSegmentList.num;
  }
  idGameLock::~idGameLock(this: v16);
  return num;
}


// ========================================================================
// __unwind$496885
// EA  : 0x82D9D960
// RVA : 0x00D9D960
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496885()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 224 + 112));
}


// ========================================================================
// ?MapUpdateEntity@idGameLocal@@UAAXPAVidEntity@@_NPAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82D9D990
// RVA : 0x00D9D990
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void __fastcall idGameLocal::MapUpdateEntity(idGameLocal *this, idEntity *ent, bool addNew, idList<idStr,5> *layerList)
{
  idMapFile *v8; // r3
  idMapFile *v9; // r27
  idMapEntity *Entity; // r20
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  idMapEntity *v17; // r3
  idMapEntity *v18; // r28
  const idDeclEntityDef *entityDef; // r28
  idGameLocal_vtbl *v20; // r27
  idTypeInfoSettings *v21; // r3
  idEntity *v22; // r23
  idGameLocal_vtbl *v23; // r28
  const char *Classname; // r3
  int v25; // r25
  int v26; // r27
  const idStr *v27; // r28
  idDeclEntityDef *v28; // r30
  idDeclEntityDef_vtbl *v29; // r29
  const char *v30; // r3
  char *v31; // r4
  char *str; // r28
  int v33; // [sp+8h] [-278h]
  int v34; // [sp+Ch] [-274h]
  int v35; // [sp+10h] [-270h]
  int v36; // [sp+14h] [-26Ch]
  int v37; // [sp+18h] [-268h]
  idMapEntity *v38; // [sp+1Ch] [-264h]
  const idDeclEntityDef *v39; // [sp+50h] [-230h]
  idTypeInfoTree v40; // [sp+60h] [-220h] BYREF
  idGameLock v41[2]; // [sp+78h] [-208h] BYREF
  idTypeInfoTree v42; // [sp+80h] [-200h] BYREF
  idStr v43; // [sp+A0h] [-1E0h] BYREF
  idTypeInfoSettings v44; // [sp+C0h] [-1C0h] BYREF
  idTypeInfoFile v45; // [sp+D0h] [-1B0h] BYREF
  idTypeInfoFile v46; // [sp+170h] [-110h] BYREF

  idGameLock::idGameLock(this: v41, newGame: this);
  idStr::idStr(this: &v43, text: ent->name.data);
  v8 = this->GetLevelMap(this);
  v9 = v8;
  if ( v8 != nullptr )
  {
    Entity = idMapFile::FindEntity(this: v8, name: v43.data, index: nullptr);
    if ( Entity != nullptr
      || addNew
      && ((v17 = (idMapEntity *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x7Cu,
                                  tag: TAG_GAME,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP)) == nullptr
        ? (v18 = nullptr)
        : (v18 = idMapEntity::idMapEntity(this: v17)),
          Entity = v18,
          idMapFile::AddEntity(
            this: v9,
            mapEnt: v18,
            a3: v16,
            a4: v15,
            a5: v14,
            a6: v13,
            a7: v12,
            a8: v11,
            a9: v33,
            a10: v34,
            a11: v35,
            a12: v36,
            a13: v37,
            a14: v38),
          v18 != nullptr) )
    {
      idTypeInfoFile::idTypeInfoFile(this: &v46, indent_: 0);
      idTypeInfoFile::idTypeInfoFile(this: &v45, indent_: 0);
      v42.nodeBlockAlloc.allowAllocs = true;
      v42.nodeBlockAlloc.clearAllocs = false;
      memset(&v42, 0, 20);
      v40.nodeBlockAlloc.allowAllocs = true;
      v40.nodeBlockAlloc.clearAllocs = false;
      memset(&v40, 0, 20);
      entityDef = ent->entityDef;
      if ( entityDef == nullptr
        || (v20 = this->__vftable,
            v21 = idTypeInfoSettings::idTypeInfoSettings(
                    this: &v44,
                    resolveEntityPointers: false,
                    resolveModelPointers: false),
            (v22 = v20->CreateEntityFromDef(this, a2: entityDef, a3: v21)) == nullptr) )
      {
        v23 = this->__vftable;
        Classname = idClass::GetClassname(this: ent);
        v22 = v23->CreateClass(this, a2: Classname);
      }
      if ( layerList != nullptr )
      {
        idMapEntity::ClearLayerList(this: Entity);
        v25 = 0;
        if ( layerList->num > 0 )
        {
          v26 = 0;
          do
          {
            v27 = &layerList->list[v26];
            if ( idList<idStr,5>::FindIndex(this: &Entity->layerList, obj: v27, startIndex: 0) < 0 )
              idList<idStr,5>::Append(this: &Entity->layerList, obj: v27);
            ++v25;
            ++v26;
          }
          while ( v25 < layerList->num );
        }
      }
      idTypeInfoFile::WriteMemoryFile(this: &v46);
      v46.settings.resolveEntityPointers = false;
      v46.settings.resolveModelPointers = false;
      this->GetEntityEditState(this, a2: v22, a3: &v46, a4: true);
      idTypeInfoFile::ReadMemoryFile(this: &v46);
      idTypeInfoTree::Parse(this: &v42, file: &v46);
      idTypeInfoFile::WriteMemoryFile(this: &v45);
      v45.settings.resolveEntityPointers = true;
      v45.settings.resolveModelPointers = true;
      this->GetEntityEditState(this, a2: ent, a3: &v45, a4: true);
      idTypeInfoFile::ReadMemoryFile(this: &v45);
      idTypeInfoTree::Parse(this: &v40, file: &v45);
      idTypeInfoTree::Diff(this: &v40, tree: &v42);
      idTypeInfoTree::ForceRootDifferent(this: &v40, set: true);
      this->DeleteEntity(this, a2: v22);
      v28 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
      idResource::SetName(this: &v28->idDecl, _name: ent->name.data);
      v39 = ent->entityDef;
      v29 = v28->__vftable;
      if ( v39 != nullptr )
      {
        str = (char *)v39->name.str;
        v30 = idClass::GetClassname(this: ent);
        v31 = str;
      }
      else
      {
        v30 = idClass::GetClassname(this: ent);
        v31 = &byte_8200D768;
      }
      v29->BuildText(this: v28, a2: v31, a3: v30);
      v28->SetEntityState_2(this: v28, a2: &v40, a3: true, a4: false);
      idMapEntity::SetEntityDef(this: Entity, def: v28);
      idTypeInfoTree::~idTypeInfoTree(this: &v40);
      idTypeInfoTree::~idTypeInfoTree(this: &v42);
      idTypeInfoFile::~idTypeInfoFile(this: &v45);
      idTypeInfoFile::~idTypeInfoFile(this: &v46);
    }
  }
  idStr::FreeData(this: &v43);
  idGameLock::~idGameLock(this: v41);
}


// ========================================================================
// __unwind$496946
// EA  : 0x82D9DD18
// RVA : 0x00D9DD18
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496946()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 640 + 120));
}


// ========================================================================
// __unwind$496947_0
// EA  : 0x82D9DD40
// RVA : 0x00D9DD40
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496947_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$496948_0
// EA  : 0x82D9DD68
// RVA : 0x00D9DD68
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496948_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 640 + 80), tag: TAG_GAME);
}


// ========================================================================
// __unwind$496949
// EA  : 0x82D9DD94
// RVA : 0x00D9DD94
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496949()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 640 + 368));
}


// ========================================================================
// __unwind$496950
// EA  : 0x82D9DDBC
// RVA : 0x00D9DDBC
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496950()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 640 + 208));
}


// ========================================================================
// __unwind$496951
// EA  : 0x82D9DDE4
// RVA : 0x00D9DDE4
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496951()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 640 + 128));
}


// ========================================================================
// __unwind$496952
// EA  : 0x82D9DE0C
// RVA : 0x00D9DE0C
// PDB : w:\tech5\tungsten\game\game_local_edit.cpp
// ========================================================================

void _unwind_496952()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 640 + 96));
}

