
// ========================================================================
// ?OnActivate@idCollisionStreamArea@@UAAXPAVidEntity@@@Z
// EA  : 0x82C18350
// RVA : 0x00C18350
// PDB : w:\tech5\tungsten\game\entities\collisionstreamarea.cpp
// ========================================================================

void __fastcall idCollisionStreamArea::OnActivate(idCollisionStreamArea *this, idEntity *activator)
{
  idPhysics *Physics; // r3
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // [sp+8h] [-58h]
  int v11; // [sp+Ch] [-54h]
  int v12; // [sp+10h] [-50h]
  int v13; // [sp+14h] [-4Ch]
  int v14; // [sp+18h] [-48h]
  int v15; // [sp+1Ch] [-44h]

  Physics = idEntity::GetPhysics(this);
  idClip::AddStreamArea(
    this: Physics->clip,
    areaNum: this->streamArea,
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
}


// ========================================================================
// ??1idCollisionStreamArea@@UAA@XZ
// EA  : 0x82C18410
// RVA : 0x00C18410
// PDB : w:\tech5\tungsten\game\entities\collisionstreamarea.cpp
// ========================================================================

void __fastcall idCollisionStreamArea::~idCollisionStreamArea(idCollisionStreamArea *this)
{
  int entityNumber; // r10
  int v3[4]; // [sp+50h] [-20h] BYREF

  entityNumber = this->entityNumber;
  this->__vftable = (idCollisionStreamArea_vtbl *)&idCollisionStreamArea::`vftable';
  v3[0] = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  idList<idEntityPtr<idActor>,5>::RemoveFast(
    this: (idList<int,5> *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-3].userPath[2].distance,
    obj: v3);
  idEntity::~idEntity(this);
}


// ========================================================================
// ?Spawn@idCollisionStreamArea@@QAAXXZ
// EA  : 0x82C18480
// RVA : 0x00C18480
// PDB : w:\tech5\tungsten\game\entities\collisionstreamarea.cpp
// ========================================================================

void __fastcall idCollisionStreamArea::Spawn(idCollisionStreamArea *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r30
  idPhysics *v4; // r8
  idPhysics *v5; // r3
  idClip *clip; // r30
  idClipModel *(__fastcall *GetClipModel)(idPhysics *, int); // ctr
  idClipModel *v8; // r3
  int StreamArea; // r3
  int entityNumber; // r10
  idEntityPtr<idEntity> v11; // [sp+50h] [-20h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  v3 = idEntity::GetPhysics(this);
  v4 = idEntity::GetPhysics(this);
  v5 = v3;
  GetClipModel = v3->GetClipModel;
  clip = v4->clip;
  v8 = GetClipModel(this: v5, a2: 0);
  StreamArea = idClip::FindStreamArea(this: clip, clipModel: v8);
  entityNumber = this->entityNumber;
  this->streamArea = StreamArea;
  v11.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  idList<idEntityPtr<idEntity>,58>::Append(
    this: (idList<idEntityPtr<idEntity>,58> *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-3].userPath[2].distance,
    obj: &v11);
}

