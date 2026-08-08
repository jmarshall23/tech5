
// ========================================================================
// ?FindBreakable@idBreakableManager@@AAAHPBVidDeclEntityDef@@@Z
// EA  : 0x82C0EB38
// RVA : 0x00C0EB38
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

int __fastcall idBreakableManager::FindBreakable(idBreakableManager *this, const idDeclEntityDef *decl)
{
  int num; // r9
  int result; // r3
  idBreakableManager::breakables_t *list; // r8
  int i; // r11

  num = this->breakable.num;
  result = 0;
  if ( num <= 0 )
    return -1;
  list = this->breakable.list;
  for ( i = 0; list[i].entity.num <= 0 || (*list[i].entity.list)->entityDef != decl; ++i )
  {
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?UseBreakable@idBreakableManager@@QAAPAVidBreakable@@PBVidDeclEntityDef@@ABVidVec3@@ABVidMat3@@1PBV4@MM@Z
// EA  : 0x82C0EB90
// RVA : 0x00C0EB90
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

idBreakable *__fastcall idBreakableManager::UseBreakable(
        idBreakableManager *this,
        const idDeclEntityDef *decl,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *dir,
        const idVec3 *pos,
        double impulse,
        double fadeTime)
{
  int v15; // r4
  int Breakable; // r3
  int v18; // r29
  idBreakable *v19; // r3
  idBreakable *v20; // r31
  idPresentable *presentable; // r11
  idPhysics *Physics; // r3
  idPhysics *v23; // r3
  double v24; // fp8
  double v25; // fp6
  idBreakableManager::breakables_t *v26; // r11
  int v27; // r10
  idBreakableManager::breakables_t *v28; // r11
  idVec3 v29; // [sp+50h] [-70h] BYREF
  char v30; // [sp+60h] [-60h] BYREF

  Breakable = idBreakableManager::FindBreakable(this, decl);
  if ( Breakable == -1 )
  {
    idLib::Warning(fmt: "idBreakableManager::UseBreakable: entity '%s' not in list", *(const char **)(v15 + 8));
    return nullptr;
  }
  else
  {
    v18 = Breakable;
    v19 = idBreakable::CastTo(c: (idBreakable *)this->breakable.list[Breakable].entity.list[this->breakable.list[Breakable].next]);
    v20 = v19;
    if ( v19 != nullptr )
    {
      presentable = v19->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v19);
        presentable = v20->presentable;
      }
      idRenderModel::ClearOcclusionQuery(this: presentable->model);
      idEventReceiver::CancelEvents(this: v20, ev: &EV_Hide);
      Physics = idEntity::GetPhysics(this: v20);
      Physics->SetOrigin(this: Physics, a2: origin, a3: -1);
      v23 = idEntity::GetPhysics(this: v20);
      v23->SetAxis(this: v23, a2: axis, a3: -1);
      v20->Show(this: v20);
      idBreakable::Reset(this: v20);
      if ( pos != nullptr )
      {
        v24 = (float)(pos->y - dir->y);
        v25 = (float)(pos->z - dir->z);
        v29.x = pos->x - dir->x;
        v29.y = v24;
        v29.z = v25;
        idBreakable::AddExplosion(this: (idBreakable *)&v30, result: v20, pos: &v29, impulse);
      }
      else
      {
        ((void (__fastcall *)(idBreakable *, _DWORD, _DWORD, _DWORD, double))v20->Damage)(
          a1: v20,
          a2: 0,
          a3: 0,
          a4: 0,
          a5: 1.0);
      }
      if ( fadeTime > 0.0 )
        v20->fadeTime = fadeTime;
      v26 = &this->breakable.list[v18];
      v27 = v26->next + 1;
      v26->next = v27;
      v28 = &this->breakable.list[v18];
      if ( v27 >= v28->entity.num )
        v28->next = 0;
      return v20;
    }
    else
    {
      idLib::Warning(fmt: "idBreakableManager::UseBreakable: NULL entity in list");
      return nullptr;
    }
  }
}


// ========================================================================
// ?ReactToMover@idBreakableManager@@QAAXXZ
// EA  : 0x82C0EDA8
// RVA : 0x00C0EDA8
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

void __fastcall idBreakableManager::ReactToMover(idBreakableManager *this)
{
  int v2; // r26
  int v3; // r30
  idBreakableManager::breakables_t *list; // r11
  int v5; // r28
  int v6; // r31
  idBreakable *v7; // r3
  idBreakable *v8; // r29

  v2 = 0;
  if ( this->breakable.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->breakable.list;
      v5 = 0;
      if ( this->breakable.list[v3].entity.num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = idBreakable::CastTo(c: (idBreakable *)list[v3].entity.list[v6]);
          v8 = v7;
          if ( v7 != nullptr && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v7) == 0 )
            v8->Hide_2(this: v8);
          list = this->breakable.list;
          ++v5;
          ++v6;
        }
        while ( v5 < this->breakable.list[v3].entity.num );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->breakable.num );
  }
}


// ========================================================================
// ?OrientBodies@idBreakableManager@@QAA_NPBVidTreeAnimator@@PAVidRenderModelDiscreteAnimation@@ABVidVec3@@ABVidMat3@@ABV?$idList@UbreakableJoint_t@@$04@@@Z
// EA  : 0x82C0EE60
// RVA : 0x00C0EE60
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

int __fastcall idBreakableManager::OrientBodies(
        idBreakableManager *this,
        idTreeAnimator *ta,
        idRenderModelDiscreteAnimation *breakableModel,
        const idVec3 *breakableOrigin,
        const idMat3 *breakableAxis,
        const idList<breakableJoint_t,5> *jointList)
{
  const idDeclMD6 *decl; // r11
  const idMD6Model *model; // r11
  const idMD6Skel *skeleton; // r11
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  const idMD6Skel *v15; // r11
  int v16; // r26
  int v17; // r25
  int i; // r28
  breakableJoint_t *v19; // r11
  const idIndex<short,enum invalidJointIndex_t> *value; // r5
  int pieceIndex; // r30
  int v22; // r31
  float *v23; // r11
  double v24; // fp12
  double v25; // fp10
  double v26; // fp6
  double v27; // fp5
  double v28; // fp2
  double v29; // fp4
  double v30; // fp1
  double v31; // fp3
  double v32; // fp26
  double v33; // fp11
  double v34; // fp27
  double v35; // fp8
  double v36; // fp23
  double v37; // fp7
  double v38; // fp11
  float *v39; // r3
  bool v40; // mr_fpscr50
  double v41; // fp13
  double v42; // fp0
  char v43; // r11
  const idMat3 *v44; // r6
  idMat3 v46; // [sp+50h] [-1C0h] BYREF
  idVec3 v47; // [sp+78h] [-198h] BYREF
  idVec3 v48; // [sp+88h] [-188h] BYREF
  idVec3 v49; // [sp+98h] [-178h] BYREF
  idMat3 v50; // [sp+B0h] [-160h] BYREF
  idMat3 v51; // [sp+E0h] [-130h] BYREF
  idMat3 v52[4]; // [sp+110h] [-100h] BYREF

  if ( breakableModel != nullptr )
  {
    decl = ta->decl;
    if ( decl != nullptr )
    {
      model = decl->model;
      if ( model != nullptr )
      {
        skeleton = model->skeleton;
        if ( skeleton != nullptr
          && (idMD6SkelData *)((char *)skeleton->data + skeleton->data->inverseBasePoseOffset) != nullptr
          && jointList->num >= 1 )
        {
          v12 = (float)((float)((float)(ta->g.origin.x - breakableOrigin->x) * breakableAxis->mat[0].x)
                      + (float)((float)((float)(ta->g.origin.y - breakableOrigin->y) * breakableAxis->mat[0].y)
                              + (float)((float)(ta->g.origin.z - breakableOrigin->z) * breakableAxis->mat[0].z)));
          v13 = (float)((float)((float)(ta->g.origin.x - breakableOrigin->x) * breakableAxis->mat[1].x)
                      + (float)((float)((float)(ta->g.origin.y - breakableOrigin->y) * breakableAxis->mat[1].y)
                              + (float)((float)(ta->g.origin.z - breakableOrigin->z) * breakableAxis->mat[1].z)));
          v14 = (float)((float)((float)(ta->g.origin.x - breakableOrigin->x) * breakableAxis->mat[2].x)
                      + (float)((float)((float)(ta->g.origin.y - breakableOrigin->y) * breakableAxis->mat[2].y)
                              + (float)((float)(ta->g.origin.z - breakableOrigin->z) * breakableAxis->mat[2].z)));
          idRenderModelDiscreteAnimation::Reset(this: breakableModel);
          v15 = ta->decl->model->skeleton;
          if ( v15 != nullptr )
            v16 = (int)v15->data + v15->data->inverseBasePoseOffset;
          else
            v16 = 0;
          v17 = 0;
          if ( jointList->num <= 0 )
            return 1;
          for ( i = 0; ; ++i )
          {
            v19 = &jointList->list[i];
            value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v19->jointIndex.value;
            pieceIndex = v19->pieceIndex;
            v22 = (__int16)value;
            if ( (__int16)value < 0 || pieceIndex < 0 || pieceIndex >= breakableModel->transforms.num )
              break;
            idTreeAnimator::GetModelSpaceJointTransform(
              this: ta,
              pose: DRIVER_MODEL,
              jointIndex: value,
              origin: &v48,
              axis: &v50);
            idRenderModelDiscreteAnimation::GetPiecePosition(
              this: breakableModel,
              index: pieceIndex,
              position: &v49,
              orientation: &v51);
            v23 = (float *)(48 * v22 + v16);
            v24 = v23[6];
            v25 = v23[10];
            v26 = v23[5];
            v27 = v23[9];
            v28 = v23[1];
            v29 = v23[4];
            v30 = v23[8];
            v31 = v23[7];
            v32 = *v23;
            v33 = (float)((float)(v49.y * v23[5]) + (float)(v49.z * v23[6]));
            v34 = v23[11];
            v35 = (float)((float)(v49.y * v23[9]) + (float)(v49.z * v23[10]));
            v36 = v23[3];
            v37 = (float)((float)(v49.y * v23[1]) + (float)(v49.z * v23[2]));
            v46.mat[2].x = v23[2];
            v46.mat[1].y = v26;
            v46.mat[0].y = v29;
            v46.mat[1].z = v27;
            v46.mat[0].z = v30;
            v46.mat[1].x = v28;
            v46.mat[2].z = v25;
            v38 = (float)((float)v31 + (float)((float)(v49.x * (float)v29) + (float)v33));
            v46.mat[2].y = v24;
            v46.mat[0].x = v32;
            v47.x = (float)((float)((float)(v50.mat[0].x
                                          * (float)((float)((float)(v49.x * (float)v32) + (float)v37) + (float)v36))
                                  + (float)((float)(v50.mat[2].x
                                                  * (float)((float)v34
                                                          + (float)((float)(v49.x * (float)v30) + (float)v35)))
                                          + (float)(v50.mat[1].x * (float)v38)))
                          + v48.x)
                  + (float)v12;
            v47.y = (float)(v48.y
                          + (float)((float)(v50.mat[0].y
                                          * (float)((float)((float)(v49.x * (float)v32) + (float)v37) + (float)v36))
                                  + (float)((float)(v50.mat[2].y
                                                  * (float)((float)v34
                                                          + (float)((float)(v49.x * (float)v30) + (float)v35)))
                                          + (float)(v50.mat[1].y * (float)v38))))
                  + (float)v13;
            v47.z = (float)(v48.z
                          + (float)((float)(v50.mat[0].z
                                          * (float)((float)((float)(v49.x * (float)v32) + (float)v37) + (float)v36))
                                  + (float)((float)(v50.mat[2].z
                                                  * (float)((float)v34
                                                          + (float)((float)(v49.x * (float)v30) + (float)v35)))
                                          + (float)(v50.mat[1].z * (float)v38))))
                  + (float)v14;
            v39 = (float *)idMat3::operator*(this: v52, result: &v46, a: &v50);
            v46.mat[0].x = *v39;
            v46.mat[0].y = v39[1];
            v46.mat[0].z = v39[2];
            v46.mat[1].x = v39[3];
            v46.mat[1].y = v39[4];
            v46.mat[1].z = v39[5];
            v40 = v39[6] == 0.0;
            v46.mat[2].x = v39[6];
            v41 = v39[7];
            v46.mat[2].y = v39[7];
            v42 = v39[8];
            v46.mat[2].z = v39[8];
            if ( !v40 || v41 != 0.0 || (v43 = 1, v42 != 0.0) )
              v43 = 0;
            v44 = &mat3_identity;
            if ( v43 == 0 )
              v44 = &v46;
            idRenderModelDiscreteAnimation::SetPiecePosition(
              this: breakableModel,
              index: pieceIndex,
              position: &v47,
              orientation: v44);
            if ( ++v17 >= jointList->num )
              return 1;
          }
          idLib::Warning(fmt: "idBreakableManager::OrientBodies() failed");
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?OrientAndUseBreakable@idBreakableManager@@QAAXPBVidDeclEntityDef@@ABVidVec3@@ABVidMat3@@1MPBVidTreeAnimator@@ABV?$idList@UbreakableJoint_t@@$04@@@Z
// EA  : 0x82C0F1E0
// RVA : 0x00C0F1E0
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

void __fastcall idBreakableManager::OrientAndUseBreakable(
        idBreakableManager *this,
        const idDeclEntityDef *decl,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *explosionOrigin,
        double impulse,
        const idTreeAnimator *ta,
        idTreeAnimator *jointList,
        const idList<breakableJoint_t,5> *a9)
{
  int v16; // r4
  int Breakable; // r3
  int v18; // r29
  idBreakable *v19; // r3
  idBreakable *v20; // r31
  idPresentable *presentable; // r11
  idPhysics *Physics; // r3
  idPhysics *v23; // r3
  idPhysics *v24; // r26
  idPhysics *v25; // r3
  const idVec3 *v26; // r25
  const idMat3 *v27; // r26
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v29; // r3
  idBreakableManager::breakables_t *v30; // r11
  int v31; // r10
  idBreakableManager::breakables_t *v32; // r11
  char v33; // [sp+50h] [-60h] BYREF

  if ( decl != nullptr )
  {
    if ( jointList != nullptr && a9->num >= 1 )
    {
      Breakable = idBreakableManager::FindBreakable(this, decl);
      if ( Breakable == -1 )
      {
        idLib::Warning(
          fmt: "idBreakableManager::OrientAndUseBreakable: entity '%s' not in list",
          *(const char **)(v16 + 8));
      }
      else
      {
        v18 = Breakable;
        v19 = idBreakable::CastTo(c: (idBreakable *)this->breakable.list[Breakable].entity.list[this->breakable.list[Breakable].next]);
        v20 = v19;
        if ( v19 != nullptr )
        {
          presentable = v19->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v19);
            presentable = v20->presentable;
          }
          idRenderModel::ClearOcclusionQuery(this: presentable->model);
          idEventReceiver::CancelEvents(this: v20, ev: &EV_Hide);
          Physics = idEntity::GetPhysics(this: v20);
          Physics->SetOrigin(this: Physics, a2: origin, a3: -1);
          v23 = idEntity::GetPhysics(this: v20);
          v23->SetAxis(this: v23, a2: axis, a3: -1);
          v20->Show(this: v20);
          v24 = idEntity::GetPhysics(this: v20);
          v25 = idEntity::GetPhysics(this: v20);
          v26 = v25->GetOrigin(this: v25, a2: 0);
          v27 = v24->GetAxis(this: v24, a2: 0);
          RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v20);
          v29 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                                    inptr: RenderModelFromPresentable,
                                                    VfDelta: 0,
                                                    SrcType: &idRenderModel `RTTI Type Descriptor',
                                                    TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                                    isReference: 0);
          if ( (unsigned __int8)idBreakableManager::OrientBodies(
                                  this,
                                  ta: jointList,
                                  breakableModel: v29,
                                  breakableOrigin: v26,
                                  breakableAxis: v27,
                                  jointList: a9) != 0 )
          {
            idBreakable::ResetRigidBodies(this: v20);
            idBreakable::AddExplosion(this: (idBreakable *)&v33, result: v20, pos: explosionOrigin, impulse);
            v30 = &this->breakable.list[v18];
            v31 = v30->next + 1;
            v30->next = v31;
            v32 = &this->breakable.list[v18];
            if ( v31 >= v32->entity.num )
              v32->next = 0;
          }
          else
          {
            idLib::Warning(fmt: "idBreakableManager::OrientAndUseBreakable: Unable to reorient he bodies for the breakable");
          }
        }
        else
        {
          idLib::Warning(fmt: "idBreakableManager::OrientAndUseBreakable: NULL entity in list");
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "idBreakableManager::OrientAndUseBreakable: bad treeAnimator or jointList data");
    }
  }
  else
  {
    idLib::Warning(fmt: "idBreakableManager::OrientAndUseBreakable: NULL decl passed in");
  }
}


// ========================================================================
// ?AddBreakable@idBreakableManager@@QAAXPBVidDeclEntityDef@@ABVidVec3@@@Z
// EA  : 0x82C0F458
// RVA : 0x00C0F458
// PDB : w:\tech5\tungsten\game\entities\breakablemanager.cpp
// ========================================================================

void __fastcall idBreakableManager::AddBreakable(
        idBreakableManager *this,
        const idDeclEntityDef *decl,
        const idVec3 *origin)
{
  int Breakable; // r31
  int v7; // r27
  idBreakable *v8; // r29
  idBreakable *v9; // r3
  idBreakable *v10; // r31
  idEventReceiver *v11; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  _DWORD *v13; // r3
  idPresentable *presentable; // r11
  idPhysics *Physics; // r3
  idBreakable_vtbl *v16; // r6
  idPhysics *v17; // r3
  idPhysics *v18; // r3

  if ( decl == nullptr )
  {
    idLib::Warning(fmt: "NULL breakable");
    return;
  }
  Breakable = idBreakableManager::FindBreakable(this, decl);
  if ( Breakable == -1 )
  {
    Breakable = this->breakable.num;
    if ( Breakable >= this->breakable.size )
    {
      idLib::Warning(
        fmt: "idBreakableManager::AddBreakable: No more free breakable spots, could not add '%s'",
        decl->name.str);
      return;
    }
    idList<idRibbonModelManager::ribbonEffects_t,5>::Alloc((idList<idRibbonModelManager::ribbonEffects_t,5> *)this);
  }
  v7 = Breakable;
  if ( this->breakable.list[Breakable].entity.num < this->breakable.list[Breakable].entity.size )
  {
    v8 = (idBreakable *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: decl, a3: -1, a4: -1, a5: -1);
    v9 = idBreakable::CastTo(c: v8);
    v10 = v9;
    if ( v9 == nullptr )
    {
      idLib::Warning(fmt: "Could not spawn breakable '%s'", decl->name.str);
      if ( v8 == nullptr )
        return;
      v11 = v8;
      goto LABEL_17;
    }
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v9);
    v13 = _RTDynamicCast(
            inptr: RenderModelFromPresentable,
            VfDelta: 0,
            SrcType: &idRenderModel `RTTI Type Descriptor',
            TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
            isReference: 0);
    if ( v13 == nullptr || v13[509] == 0 )
    {
      v11 = v10;
LABEL_17:
      idEventReceiver::PostEventMS(this: v11, ev: &EV_Remove, time: 0);
      return;
    }
    presentable = v10->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v10);
      presentable = v10->presentable;
    }
    presentable->model->g.firstVisibleFrameCount = 0;
    Physics = idEntity::GetPhysics(this: v10);
    Physics->SetOrigin(this: Physics, a2: origin, a3: -1);
    v16 = v10->__vftable;
    v10->isPooled = true;
    v16->Hide_2(this: v10);
    v17 = idEntity::GetPhysics(this: v10);
    v17->UnlinkClip(this: v17);
    v18 = idEntity::GetPhysics(this: v10);
    v18->SetContents(this: v18, a2: 0, a3: -1);
    *idList<unsigned char *,5>::Alloc(this: (idList<idDeclAF_Constraint *,71> *)&this->breakable.list[v7]) = (idDeclAF_Constraint *)v10;
  }
}

