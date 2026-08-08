
// ========================================================================
// ?FindSpawnable@idSpawnablePropManager@@AAAHPBVidDeclEntityDef@@@Z
// EA  : 0x82CB7C68
// RVA : 0x00CB7C68
// PDB : w:\tech5\tungsten\game\entities\spawnablepropmanager.cpp
// ========================================================================

int __fastcall idSpawnablePropManager::FindSpawnable(idSpawnablePropManager *this, const idDeclEntityDef *decl)
{
  int num; // r9
  int result; // r3
  idSpawnablePropManager::spawnables_t *list; // r8
  int i; // r11

  num = this->spawnable.num;
  result = 0;
  if ( num <= 0 )
    return -1;
  list = this->spawnable.list;
  for ( i = 0; list[i].entity.num <= 0 || (*list[i].entity.list)->entityDef != decl; ++i )
  {
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?UseSpawnable@idSpawnablePropManager@@QAAXPBVidDeclEntityDef@@ABVidVec3@@ABVidMat3@@11@Z
// EA  : 0x82CB7CC0
// RVA : 0x00CB7CC0
// PDB : w:\tech5\tungsten\game\entities\spawnablepropmanager.cpp
// ========================================================================

void __fastcall idSpawnablePropManager::UseSpawnable(
        idSpawnablePropManager *this,
        const idDeclEntityDef *decl,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *linearVelocity,
        const idVec3 *angularVelocity)
{
  int v11; // r4
  int Spawnable; // r3
  int v13; // r26
  idProp_Spawnable *v14; // r30
  idPresentable *presentable; // r11
  idRenderModel *model; // r31
  idPhysics *Physics; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idSpawnablePropManager::spawnables_t *v20; // r11
  signed int num; // r8
  int v22; // r7

  if ( decl == nullptr )
    idLib::Error(fmt: "idSpawnablePropManager::UseSpawnable() - NULL idDeclEntityDef passed in.");
  Spawnable = idSpawnablePropManager::FindSpawnable(this, decl);
  if ( Spawnable == -1 )
  {
    idLib::Warning(fmt: "idSpawnablePropManager::UseSpawnable: entity '%s' not in list", *(const char **)(v11 + 8));
  }
  else
  {
    v13 = Spawnable;
    v14 = this->spawnable.list[Spawnable].entity.list[this->spawnable.list[Spawnable].next];
    if ( v14 != nullptr )
    {
      presentable = v14->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v14);
        presentable = v14->presentable;
      }
      model = presentable->model;
      idRenderModel::ClearOcclusionQuery(this: model);
      model->g.origin.x = origin->x;
      model->g.origin.y = origin->y;
      model->g.origin.z = origin->z;
      model->g.axis.mat[0].x = axis->mat[0].x;
      model->g.axis.mat[0].y = axis->mat[0].y;
      model->g.axis.mat[0].z = axis->mat[0].z;
      model->g.axis.mat[1].x = axis->mat[1].x;
      model->g.axis.mat[1].y = axis->mat[1].y;
      model->g.axis.mat[1].z = axis->mat[1].z;
      model->g.axis.mat[2].x = axis->mat[2].x;
      model->g.axis.mat[2].y = axis->mat[2].y;
      model->g.axis.mat[2].z = axis->mat[2].z;
      idEventReceiver::CancelEvents(this: v14, ev: &EV_Hide);
      idEntity::SetOrigin(this: v14, org: origin);
      Physics = idEntity::GetPhysics(this: v14);
      Physics->SetAxis(this: Physics, a2: axis, a3: -1);
      v14->Show(this: v14);
      idEntity::BecomeActive(this: v14, flags: 1);
      idProp_Spawnable::ActivateSpawnableProp(this: v14);
      v18 = idEntity::GetPhysics(this: v14);
      v18->SetLinearVelocity(this: v18, a2: linearVelocity, a3: 0);
      v19 = idEntity::GetPhysics(this: v14);
      v19->SetAngularVelocity(this: v19, a2: angularVelocity, a3: 0);
      v20 = &this->spawnable.list[v13];
      num = v20->entity.num;
      v22 = v20->next + 1;
      __twllei(num, 0);
      v20->next = v22 % num;
      __twlgei(num & ~(__ROL4__(v22, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      idLib::Warning(fmt: "idSpawnablePropManager::UseSpawnable: NULL entity in list");
    }
  }
}


// ========================================================================
// ?AddSpawnable@idSpawnablePropManager@@QAAXPBVidDeclEntityDef@@ABVidVec3@@@Z
// EA  : 0x82CB80E8
// RVA : 0x00CB80E8
// PDB : w:\tech5\tungsten\game\entities\spawnablepropmanager.cpp
// ========================================================================

void __fastcall idSpawnablePropManager::AddSpawnable(
        idSpawnablePropManager *this,
        const idDeclEntityDef *decl,
        const idVec3 *origin)
{
  int Spawnable; // r31
  int v7; // r29
  idProp_Spawnable *v8; // r3
  idProp_Spawnable *v9; // r3
  idEntity *v10; // r31
  idPhysics *Physics; // r3
  idPhysics *v12; // r3
  idPhysics *v13; // r3
  const char *v14; // r3
  idSplineFollower *v15; // r3

  if ( decl == nullptr )
    idLib::Error(fmt: "idSpawnablePropManager::AddSpawnable() - NULL idDeclEntityDef passed in.");
  Spawnable = idSpawnablePropManager::FindSpawnable(this, decl);
  if ( Spawnable == -1 )
  {
    Spawnable = this->spawnable.num;
    if ( Spawnable >= this->spawnable.size )
    {
      idLib::Warning(
        fmt: "idSpawnablePropManager::AddSpawnable: No more free spawnable spots, could not add '%s'",
        decl->name.str);
      return;
    }
    idList<idSpawnablePropManager::spawnables_t,5>::Alloc(this: &this->spawnable);
  }
  v7 = Spawnable;
  if ( this->spawnable.list[Spawnable].entity.num < this->spawnable.list[Spawnable].entity.size )
  {
    v8 = (idProp_Spawnable *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: decl, a3: -1, a4: -1, a5: -1);
    v9 = idProp_Spawnable::CastTo(c: v8);
    v10 = v9;
    if ( v9 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v9);
      Physics->SetOrigin(this: Physics, a2: origin, a3: -1);
      v10->Hide_2(this: v10);
      idEntity::BecomeInactive(this: v10, flags: 7);
      v12 = idEntity::GetPhysics(this: v10);
      v12->UnlinkClip(this: v12);
      v13 = idEntity::GetPhysics(this: v10);
      v13->SetContents(this: v13, a2: 0, a3: -1);
      *idList<unsigned char *,5>::Alloc(this: (idList<idDeclAF_Constraint *,71> *)&this->spawnable.list[v7]) = (idDeclAF_Constraint *)v10;
    }
    else
    {
      v14 = decl->GetClass(this: decl);
      idLib::Error(fmt: "idSpawnablePropManager: Unable to spawn Entity with class '%s'", v14);
      idSplineFollower::Hide(this: v15);
    }
  }
}

