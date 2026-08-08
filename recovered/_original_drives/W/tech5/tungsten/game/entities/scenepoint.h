
// ========================================================================
// ?GetScenePointPos@idScenePoint@@QBA?BVidVec3@@XZ
// EA  : 0x829F0A60
// RVA : 0x009F0A60
// PDB : w:\tech5\tungsten\game\entities\scenepoint.h
// ========================================================================

idScenePoint *__fastcall idScenePoint::GetScenePointPos(idScenePoint *this, idEntity *result)
{
  idPhysics *Physics; // r3
  int v4; // r3
  idList<idEventReceiver *,5> *v5; // r8
  idList<idEventReceiver *,5> *v6; // r7

  Physics = idEntity::GetPhysics(this: result);
  v4 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v5 = *(idList<idEventReceiver *,5> **)(v4 + 4);
  v6 = *(idList<idEventReceiver *,5> **)(v4 + 8);
  this->__vftable = *(idScenePoint_vtbl **)v4;
  this->listenerList = v5;
  this->listeningToList = v6;
  return this;
}


// ========================================================================
// ?HasScenePointUserGroup@idScenePoint@@QBA_NXZ
// EA  : 0x82D4A830
// RVA : 0x00D4A830
// PDB : w:\tech5\tungsten\game\entities\scenepoint.h
// ========================================================================

BOOL __fastcall idScenePoint::HasScenePointUserGroup(idScenePoint *this)
{
  int value; // r10
  idScenePoint_UserGroup *v2; // r3

  value = this->userGroup.spawnId.value;
  return gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idScenePoint_UserGroup *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idScenePoint_UserGroup::CastTo(c: v2) != nullptr;
}

