
// ========================================================================
// ?ZoomEntity@idEditEntities@@QAA_NABVidVec3@@_N@Z
// EA  : 0x82BDC690
// RVA : 0x00BDC690
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

int __fastcall idEditEntities::ZoomEntity(idEditEntities *this, const idVec3 *camPos, bool push)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  float v8; // r6
  double x; // fp0
  float v10; // r5
  double y; // fp9
  double z; // fp8
  double v13; // fp11
  double v14; // fp7
  double v15; // fp6
  idPhysics *v16; // r3
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  float *v20; // r3
  idEntity **list; // r7
  double v22; // fp8
  double v23; // fp6
  idEntity *v24; // r11
  idCommon *v25; // r3
  idCommon_vtbl *v26; // r4
  int v27; // r3
  double v29; // fp8
  double v30; // fp7
  idVec3 v31; // [sp+50h] [-60h] BYREF
  idVec3 v32; // [sp+60h] [-50h] BYREF

  if ( this->selectedEntities.num == 0 || !this->dragging )
    return 0;
  Physics = idEntity::GetPhysics(this: *this->selectedEntities.list);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = v7[1];
  x = camPos->x;
  v10 = v7[2];
  y = camPos->y;
  z = camPos->z;
  v31.x = *v7;
  v31.y = v8;
  v31.z = v10;
  if ( push )
  {
    v13 = (float)((float)x - v31.x);
    v14 = (float)((float)y - v8);
    v15 = (float)((float)z - v10);
  }
  else
  {
    v13 = (float)(v31.x - (float)x);
    v14 = (float)(v8 - (float)y);
    v15 = (float)(v10 - (float)z);
  }
  v31.z = v15;
  v31.y = v14;
  v31.x = v13;
  idVec3::NormalizeFast(this: &v31);
  v16 = idEntity::GetPhysics(this: *this->selectedEntities.list);
  v17 = (float)(v31.x * (float)10.0);
  v18 = (float)(v31.y * (float)10.0);
  v19 = (float)(v31.z * (float)10.0);
  v20 = (float *)v16->GetOrigin(this: v16, a2: 0);
  list = this->selectedEntities.list;
  v22 = (float)(v20[2] + (float)v19);
  v23 = (float)(v20[1] + (float)v18);
  v32.x = *v20 + (float)v17;
  v32.z = v22;
  v32.y = v23;
  idEntity::SetOrigin(this: *list, org: &v32);
  v24 = *this->selectedEntities.list;
  v24->spawnPosition.x = v32.x;
  v25 = common;
  v24->spawnPosition.y = v32.y;
  v26 = v25->__vftable;
  v24->spawnPosition.z = v32.z;
  v27 = (int)v26->Game(this: v25);
  (*(void (__fastcall **)(int, idEntity *, _DWORD, _DWORD))(*(_DWORD *)v27 + 620))(
    a1: v27,
    a2: *this->selectedEntities.list,
    a3: 0,
    a4: 0);
  v29 = (float)(v32.y - camPos->y);
  v30 = (float)(v32.z - camPos->z);
  this->lastDragPos.x = v32.x - camPos->x;
  this->lastDragPos.y = v29;
  this->lastDragPos.z = v30;
  return 1;
}


// ========================================================================
// ?ResetDragging@idEditEntities@@QAAXXZ
// EA  : 0x82BDC888
// RVA : 0x00BDC888
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::ResetDragging(idEditEntities *this)
{
  idEntity *v2; // r10

  if ( this->dragging )
  {
    v2 = *this->selectedEntities.list;
    if ( v2 != nullptr )
    {
      ((void (*)(void))v2->UpdateEditingDialog)();
      if ( (com_editors & 0x800) != 0
        && cvarSystem->GetCVarInteger(this: cvarSystem, a2: "g_editEntityMode", a3: 0) == 4 )
      {
        common->UpdateTool(this: common, a2: EDITOR_PARTICLE);
      }
    }
  }
  this->dragging = false;
}


// ========================================================================
// ?EditSelected@idEditEntities@@QAAXXZ
// EA  : 0x82BDC948
// RVA : 0x00BDC948
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::EditSelected(idEditEntities *this)
{
  int num; // r11

  num = this->selectedEntities.num;
  this->dragging = false;
  if ( num != 0 )
    (*(void (__fastcall **)(idEntity *))(**(_DWORD **)this->selectedEntities.list + 576))(a1: *this->selectedEntities.list);
}


// ========================================================================
// ?RemoveSelectedEntity@idEditEntities@@QAAXPAVidEntity@@@Z
// EA  : 0x82BDC978
// RVA : 0x00BDC978
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::RemoveSelectedEntity(
        idEditEntities *this,
        lobbyUser_t *ent,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        lobbyUser_t *a14)
{
  idList<lobbyUser_t *,5> *p_selectedEntities; // r3
  int v15; // r10
  int num; // r9
  lobbyUser_t **list; // r8
  int i; // r11

  p_selectedEntities = (idList<lobbyUser_t *,5> *)&this->selectedEntities;
  a14 = ent;
  v15 = 0;
  num = p_selectedEntities->num;
  if ( num > 0 )
  {
    list = p_selectedEntities->list;
    for ( i = 0; list[i] != ent; ++i )
    {
      if ( ++v15 >= num )
        return;
    }
    if ( v15 >= 0 && &list[v15] != nullptr )
      idList<idPresentableAnimatedEntity *,5>::Remove(this: p_selectedEntities, obj: &a14);
  }
}


// ========================================================================
// ?ClearSelectedEntities@idEditEntities@@QAAXXZ
// EA  : 0x82BDCA00
// RVA : 0x00BDCA00
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::ClearSelectedEntities(idEditEntities *this)
{
  int num; // ctr
  int v3; // r11
  idEntity *v4; // r9
  idEntity **list; // r4

  if ( this->selectedEntities.num > 0 )
  {
    num = this->selectedEntities.num;
    v3 = 0;
    do
    {
      v4 = this->selectedEntities.list[v3++];
      *(_BYTE *)&v4->flags &= ~1u;
      --num;
    }
    while ( num != 0 );
  }
  if ( this->selectedEntities.listStatic == 0 || this->selectedEntities.listStatic == 2 )
  {
    list = this->selectedEntities.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->selectedEntities.list = nullptr;
    this->selectedEntities.size = 0;
  }
  this->selectedEntities.num = 0;
}


// ========================================================================
// ?EntityIsSelectable@idEditEntities@@QAA_NPAVidEntity@@PAVidVec4@@PAVidStr@@2@Z
// EA  : 0x82BDCAA0
// RVA : 0x00BDCAA0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

int __fastcall idEditEntities::EntityIsSelectable(
        idEditEntities *this,
        idEntity *ent,
        idVec4 *color,
        idStr *text,
        idStr *type)
{
  int v10; // r24
  int i; // r28
  idSelectedTypeInfo *v12; // r30
  const idTypeInfo *typeInfo; // r31
  int v14; // r11
  char v15; // r11
  bool v16; // zf
  size_t len; // r31
  size_t v19; // r31
  idColor *v20; // r10
  double r; // fp0

  v10 = 0;
  if ( this->selectableEntityClasses.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v12 = &this->selectableEntityClasses.list[i];
    if ( !v12->entityMustExistInMapFile || gameLocal->MapFindEntity_2(this: gameLocal, a2: ent) != nullptr )
    {
      typeInfo = v12->typeInfo;
      v14 = *(_DWORD *)(ent->GetType(this: ent) + 36);
      if ( v14 < typeInfo->typeNum || (v16 = v14 <= typeInfo->lastChild, v15 = 1, !v16) )
        v15 = 0;
      if ( v15 != 0 )
        break;
    }
    if ( ++v10 >= this->selectableEntityClasses.num )
      return 0;
  }
  if ( text != nullptr && type != nullptr )
  {
    len = v12->textKey.len;
    idStr::EnsureAlloced(this: text, amount: len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: text->data, Src: v12->textKey.data, Size: len);
    text->data[len] = 0;
    text->len = len;
    v19 = v12->typeKey.len;
    idStr::EnsureAlloced(this: type, amount: v19 + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: type->data, Src: v12->typeKey.data, Size: v19);
    type->data[v19] = 0;
    type->len = v19;
  }
  if ( color != nullptr )
  {
    if ( (*(_BYTE *)&ent->flags & 1) != 0 )
    {
      v20 = &idColor::colorRed;
      r = idColor::colorRed.r;
    }
    else if ( v10 == 1 )
    {
      v20 = &idColor::colorYellow;
      r = idColor::colorYellow.r;
    }
    else if ( v10 == 2 )
    {
      v20 = &idColor::colorBlue;
      r = idColor::colorBlue.r;
    }
    else
    {
      v20 = &idColor::colorGreen;
      r = idColor::colorGreen.r;
    }
    color->x = r;
    color->y = v20->g;
    color->z = v20->b;
    color->w = v20->a;
  }
  return 1;
}


// ========================================================================
// ?Update@idDragEntity@@QAAXPAVidPlayer@@@Z
// EA  : 0x82BDCC88
// RVA : 0x00BDCC88
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idDragEntity::Update(idDragEntity *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int entityNumber; // r8
  idAnimatedEntity *v7; // r3
  idAnimator_AF *v8; // r3
  float *PhysicsForId; // r3
  float *v10; // r29
  int bodyId; // r10
  double v12; // fp11
  double v13; // fp9
  double x; // fp8
  double z; // fp7
  double v16; // fp6
  double v17; // fp4
  double v18; // fp10
  double v19; // fp7
  int (__fastcall *v20)(float *, int); // ctr
  double v21; // fp3
  double v22; // fp2
  double v23; // fp1
  float *v24; // r3
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  double v28; // fp28
  double v29; // fp27
  double v30; // fp26
  double v31; // fp24
  double v32; // fp23
  double v33; // fp22
  float *v34; // r3
  double v35; // fp7
  double v36; // fp4
  double v37; // fp13
  double v38; // fp12
  idPhysics *v39; // r29
  idPresentable *v40; // r3
  int v41; // r3
  idEntityPtr<idEntity> *p_selected; // r28
  idEntity *v43; // r11
  float *v44; // r4
  idClipModel *v45; // r3
  int v46; // r3
  char *v47; // r10
  _DWORD *v48; // r11
  int i; // ctr
  float *v50; // r3
  double v51; // fp3
  double v52; // fp31
  double v53; // fp30
  double y; // fp27
  float v55; // r6
  double v56; // fp12
  float v57; // r8
  double v58; // fp26
  double v59; // fp28
  double v60; // fp22
  double v61; // fp30
  double v62; // fp0
  double v63; // fp21
  double v64; // fp30
  double v65; // fp9
  double v66; // fp10
  double v67; // fp5
  double v68; // fp4
  double v69; // fp8
  double v70; // fp11
  double v71; // fp1
  double v72; // fp24
  double v73; // fp1
  double angle; // fp31
  double v75; // fp30
  double v76; // fp23
  double v77; // fp27
  double v78; // fp29
  double v79; // fp26
  double v80; // fp28
  long double v81; // fp2
  double v82; // fp1
  __int64 v83; // r9
  double v84; // fp31
  idVec3 *v85; // r3
  double v86; // fp4
  double v87; // fp3
  double v88; // fp30
  double v89; // fp28
  double v90; // fp29
  float *v91; // r3
  int v92; // r5
  double v93; // fp3
  double v94; // fp2
  idGameLocal *v95; // r11
  idEntity *v96; // r3
  int v97; // r4
  char *str; // r4
  idEntity *v99; // r29
  char *data; // r28
  idEntity *v101; // r9
  idEntity *v102; // r3
  char *v103; // r29
  idTypeInfo *(__fastcall *GetType)(struct idEntity *); // ctr
  _DWORD *v105; // r3
  __int64 v106; // r8
  __int64 v107; // r6
  __int64 v108; // r10
  va *v109; // r3
  idEntityPtr<idEntity> *v110; // r30
  idEntity *v111; // r3
  idEntity *v112; // r3
  idPresentable *v113; // r11
  idRenderModel *model; // r10
  char v115; // r11
  idEntity *v116; // r3
  idPresentable *v117; // r11
  idEntity *v118; // r30
  idRenderWorld *renderWorld; // r30
  idRenderWorld_vtbl *v120; // r29
  idBox *v121; // r3
  int v122; // [sp+8h] [-1358h]
  int v123; // [sp+Ch] [-1354h]
  int v124; // [sp+10h] [-1350h]
  int v125; // [sp+14h] [-134Ch]
  int v126; // [sp+18h] [-1348h]
  int v127; // [sp+1Ch] [-1344h]
  idRotation v128; // [sp+60h] [-1300h] BYREF
  float v129; // [sp+A4h] [-12BCh]
  float v130; // [sp+A8h] [-12B8h]
  float v131[9]; // [sp+B0h] [-12B0h] BYREF
  idVec3 v132; // [sp+D4h] [-128Ch] BYREF
  float v133; // [sp+E0h] [-1280h]
  float v134[4]; // [sp+E8h] [-1278h] BYREF
  float v135[4]; // [sp+F8h] [-1268h] BYREF
  float v136[4]; // [sp+108h] [-1258h] BYREF
  idVec3 v137; // [sp+118h] [-1248h] BYREF
  float v138; // [sp+128h] [-1238h] BYREF
  float v139; // [sp+12Ch] [-1234h]
  float v140; // [sp+130h] [-1230h]
  idStr v141; // [sp+140h] [-1220h] BYREF
  float v142; // [sp+160h] [-1200h]
  float v143; // [sp+164h] [-11FCh]
  float v144; // [sp+168h] [-11F8h]
  float v145; // [sp+16Ch] [-11F4h]
  float v146; // [sp+170h] [-11F0h]
  float v147; // [sp+174h] [-11ECh]
  float v148; // [sp+178h] [-11E8h]
  float v149; // [sp+17Ch] [-11E4h]
  float v150; // [sp+180h] [-11E0h]
  idVec3 v151; // [sp+190h] [-11D0h] BYREF
  float v152; // [sp+19Ch] [-11C4h]
  float v153; // [sp+1A0h] [-11C0h]
  float v154; // [sp+1A4h] [-11BCh]
  float v155; // [sp+1A8h] [-11B8h]
  char v156; // [sp+1D0h] [-1190h]
  trace_t v157; // [sp+1E0h] [-1180h] BYREF
  idBox v158; // [sp+260h] [-1100h] BYREF
  va v159; // [sp+2A0h] [-10C0h] BYREF

  player->GetViewTransform(this: player, a2: (idVec3 *)&v128.axis.mat[1].z, a3: (idMat3 *)v131);
  if ( this->physicsId == -1 )
  {
    presentable = player->presentable;
    v5 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    if ( idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v5 + 46244), mask: 1) )
    {
      entityNumber = player->entityNumber;
      v137.z = v128.axis.mat[2].y + (float)(v131[2] * (float)2048.0);
      v137.y = v128.axis.mat[2].x + (float)(v131[1] * (float)2048.0);
      v137.x = v128.axis.mat[1].z + (float)(v131[0] * (float)2048.0);
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v157,
        start: (const idVec3 *)&v128.axis.mat[1].z,
        end: &v137,
        clipMask: 2209987,
        passEntityNumber: entityNumber);
      if ( v157.fraction < 1.0 )
      {
        if ( v157.c.type == CONTACT_SPHERE )
        {
          v7 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)gameLocal->entities.ptr[v157.c.entityNum]);
          if ( v7 != nullptr )
          {
            v8 = v7->GetAF_2(this: v7);
            if ( v8 != nullptr )
            {
              v157.c.physicsId = v8->physicsObj.physicsId;
              v157.c.bodyId = idAnimator_AF::BodyForJoint(
                                this: v8,
                                joint: (idIndex<short,enum invalidJointIndex_t> *)SLOWORD(v157.c.trmFeature));
            }
          }
        }
        PhysicsForId = (float *)idPhysics::GetPhysicsForId(physicsId_: v157.c.physicsId);
        v10 = PhysicsForId;
        if ( PhysicsForId != nullptr )
        {
          v128.vec.y = PhysicsForId[2];
          if ( LODWORD(v128.vec.y) != 1 && LODWORD(v128.vec.y) != 2 )
          {
            bodyId = v157.c.bodyId;
            v12 = (float)(v157.c.point.z - v128.axis.mat[2].y);
            v13 = (float)(v157.c.point.y - v128.axis.mat[2].x);
            x = v157.c.point.x;
            z = v128.axis.mat[1].z;
            this->physicsId = v157.c.physicsId;
            v16 = v131[2];
            v17 = v131[7];
            this->bodyId = bodyId;
            v18 = v131[8];
            v20 = *(int (__fastcall **)(float *, int))(*(_DWORD *)PhysicsForId + 68);
            v21 = (float)((float)(v131[6] * (float)((float)x - (float)z)) + (float)((float)v17 * (float)v13));
            v22 = (float)((float)(v131[3] * (float)((float)x - (float)z)) + (float)(v131[4] * (float)v13));
            v23 = (float)((float)(v131[0] * (float)((float)x - (float)z))
                        + (float)((float)(v131[1] * (float)v13) + (float)((float)v16 * (float)v12)));
            v19 = v131[5];
            this->localPlayerPoint.x = v23;
            this->localPlayerPoint.z = (float)((float)v18 * (float)v12) + (float)v21;
            this->localPlayerPoint.y = (float)((float)v19 * (float)v12) + (float)v22;
            v24 = (float *)v20(a1: PhysicsForId, a2: this->bodyId);
            v25 = v24[8];
            v26 = v24[5];
            v27 = v24[2];
            v28 = v24[7];
            v29 = v24[4];
            v30 = v24[1];
            v31 = v24[6];
            v32 = v24[3];
            v33 = *v24;
            v34 = (float *)(*(int (__fastcall **)(float *, int))(*(_DWORD *)v10 + 64))(a1: v10, a2: this->bodyId);
            v35 = (float)(v157.c.point.y - v34[1]);
            v36 = (float)(v157.c.point.z - v34[2]);
            v37 = (float)((float)((float)(v157.c.point.z - v34[2]) * (float)v25)
                        + (float)((float)(v157.c.point.x - *v34) * (float)v31));
            v38 = (float)((float)((float)(v157.c.point.x - *v34) * (float)v33)
                        + (float)((float)(v157.c.point.y - v34[1]) * (float)v30));
            this->localPhysicsPoint.y = (float)((float)(v157.c.point.z - v34[2]) * (float)v26)
                                      + (float)((float)((float)(v157.c.point.x - *v34) * (float)v32)
                                              + (float)((float)(v157.c.point.y - v34[1]) * (float)v29));
            this->localPhysicsPoint.z = (float)((float)v35 * (float)v28) + (float)v37;
            this->localPhysicsPoint.x = (float)((float)v36 * (float)v27) + (float)v38;
          }
        }
      }
    }
  }
  v39 = idPhysics::GetPhysicsForId(physicsId_: this->physicsId);
  if ( v39 == nullptr )
    goto LABEL_38;
  v40 = player->presentable;
  if ( v40 != nullptr )
    v41 = (int)v40->GetPlayerInterface_2(this: v40);
  else
    v41 = 0;
  if ( !idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v41 + 46244), mask: 1) )
  {
    this->physicsId = -1;
    return;
  }
  p_selected = &this->selected;
  v43 = gameLocal->entities.ptr[v39->entityNumber];
  if ( v43 != nullptr )
  {
    LODWORD(v128.vec.y) = v43->entityNumber;
    p_selected->spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v128.vec.y)] << 13) | LODWORD(v128.vec.y);
  }
  else
  {
    p_selected->spawnId.value = 0x1FFF;
  }
  v45 = v39->GetClipModel(this: v39, a2: this->bodyId);
  if ( v45 != nullptr && v45->traceModels.num != 0 )
  {
    idClipModel::GetMassProperties(
      this: v45,
      density: 1.0,
      mass: v44,
      centerOfMass: &v132,
      inertiaTensor: (idMat3 *)&v128.axis.mat[0].y,
      a6: &v158.center.x);
  }
  else
  {
    v128.axis.mat[1].x = 0.0;
    v128.axis.mat[0].z = 0.0;
    v128.axis.mat[0].y = 0.0;
  }
  v46 = (int)v39->GetAxis(this: v39, a2: this->bodyId);
  v47 = &v141.baseBuffer[16];
  v48 = (_DWORD *)(v46 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v48;
    v47 += 4;
    *(_DWORD *)v47 = *v48;
  }
  v50 = (float *)v39->GetOrigin(this: v39, a2: this->bodyId);
  v51 = this->localPlayerPoint.z;
  v52 = (float)(v131[8] * this->localPlayerPoint.z);
  v53 = (float)(v131[7] * this->localPlayerPoint.z);
  y = this->localPhysicsPoint.y;
  v55 = *v50;
  v56 = (float)(v145 * this->localPhysicsPoint.y);
  v128.origin.z = v50[2];
  v57 = v50[1];
  v58 = this->localPhysicsPoint.z;
  v59 = this->localPlayerPoint.x;
  v60 = (float)(v150 * this->localPhysicsPoint.z);
  v61 = (float)((float)(v131[1] * this->localPlayerPoint.x) + (float)v53);
  v62 = (float)((float)(v131[2] * this->localPlayerPoint.x) + (float)v52);
  v63 = (float)(v149 * this->localPhysicsPoint.z);
  v128.origin.x = v55;
  v64 = (float)((float)(v131[4] * this->localPlayerPoint.y) + (float)v61);
  v65 = (float)((float)(this->localPhysicsPoint.x * v142) + (float)((float)(v148 * (float)v58) + (float)v56));
  v66 = (float)((float)(v146 * (float)y) + (float)((float)(v143 * this->localPhysicsPoint.x) + (float)v63));
  v67 = (float)(v57
              + (float)((float)(v149 * v128.axis.mat[1].x)
                      + (float)((float)(v143 * v128.axis.mat[0].y) + (float)(v146 * v128.axis.mat[0].z))));
  v68 = (float)((float)((float)(v148 * v128.axis.mat[1].x)
                      + (float)((float)(v142 * v128.axis.mat[0].y) + (float)(v145 * v128.axis.mat[0].z)))
              + v55);
  v69 = (float)(v128.axis.mat[2].y + (float)((float)(v131[5] * this->localPlayerPoint.y) + (float)v62));
  v70 = (float)((float)((float)((float)v59 * v131[0])
                      + (float)((float)(v131[6] * (float)v51) + (float)(v131[3] * this->localPlayerPoint.y)))
              + v128.axis.mat[1].z);
  v71 = (float)(v128.origin.z
              + (float)((float)(v147 * (float)y) + (float)((float)(v144 * this->localPhysicsPoint.x) + (float)v60)));
  *(float *)&v128.axisValid = (float)((float)((float)v59 * v131[0])
                                    + (float)((float)(v131[6] * (float)v51) + (float)(v131[3] * this->localPlayerPoint.y)))
                            + v128.axis.mat[1].z;
  v128.axis.mat[1].x = v128.origin.z
                     + (float)((float)(v150 * v128.axis.mat[1].x)
                             + (float)((float)(v144 * v128.axis.mat[0].y) + (float)(v147 * v128.axis.mat[0].z)));
  v128.axis.mat[0].z = v67;
  v128.origin.x = (float)v70 - (float)v68;
  v128.origin.z = (float)v69 - v128.axis.mat[1].x;
  v128.origin.y = (float)(v128.axis.mat[2].x + (float)v64) - (float)v67;
  v138 = (float)v65 + v55;
  v129 = v128.axis.mat[2].x + (float)v64;
  v130 = v69;
  v139 = v57 + (float)v66;
  v140 = v71;
  v128.axis.mat[0].y = v68;
  v128.angle = (float)v71 - v128.axis.mat[1].x;
  v128.vec.z = v139 - (float)v67;
  v128.vec.y = v138 - (float)v68;
  v72 = idVec3::NormalizeFast(this: &v128.origin);
  v73 = idVec3::NormalizeFast(this: (idVec3 *)&v128.vec.y);
  angle = v128.angle;
  v75 = v128.origin.z;
  v76 = v73;
  v77 = v128.vec.y;
  v78 = v128.origin.x;
  v79 = v128.vec.z;
  v80 = v128.origin.y;
  *(double *)&v81 = (float)((float)(v128.vec.z * v128.origin.y)
                          + (float)((float)(v128.vec.y * v128.origin.x) + (float)(v128.angle * v128.origin.z)));
  v82 = idMath::ACos(a: v81);
  v156 = 0;
  v151.x = v128.axis.mat[0].y;
  v151.y = v128.axis.mat[0].z;
  v151.z = v128.axis.mat[1].x;
  v155 = (float)v82 * idMath::M_RAD2DEG;
  v152 = (float)((float)angle * (float)v80) - (float)((float)v79 * (float)v75);
  v154 = (float)((float)v79 * (float)v78) - (float)((float)v80 * (float)v77);
  v153 = (float)((float)v75 * (float)v77) - (float)((float)angle * (float)v78);
  LODWORD(v83) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  *(_QWORD *)&v128.vec.y = v83;
  v84 = (float)((float)v83 * (float)0.001);
  v85 = idRotation::ToAngularVelocity(this: &v128, result: &v151);
  v86 = v85->y;
  v87 = (float)((float)((float)1.0 / (float)v84) * v85->x);
  v134[2] = v85->z * (float)((float)1.0 / (float)v84);
  v134[0] = v87;
  v134[1] = (float)v86 * (float)((float)1.0 / (float)v84);
  v39->SetAngularVelocity(this: v39, a2: (const idVec3 *)v134, a3: this->bodyId);
  *(_QWORD *)&v128.vec.y = __PAIR64__(0x82000000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
  v88 = (float)((float)v75
              * (float)((float)((float)((float)v72 - (float)v76) / (float)((float)*(__int64 *)&v128.vec.y * (float)0.001))
                      * (float)0.5));
  v89 = (float)((float)v80
              * (float)((float)((float)((float)v72 - (float)v76) / (float)((float)*(__int64 *)&v128.vec.y * (float)0.001))
                      * (float)0.5));
  v90 = (float)((float)((float)((float)((float)v72 - (float)v76) / (float)((float)*(__int64 *)&v128.vec.y * (float)0.001))
                      * (float)0.5)
              * (float)v78);
  v91 = (float *)v39->GetLinearVelocity(this: (idPhysics *)&v128, result: (idVec3 *)v39, a3: this->bodyId);
  v92 = this->bodyId;
  v93 = (float)(v91[1] * (float)0.5);
  v94 = (float)(*v91 * (float)0.5);
  v135[2] = (float)(v91[2] * (float)0.5) + (float)v88;
  v135[1] = (float)v93 + (float)v89;
  v135[0] = (float)v94 + (float)v90;
  v39->SetLinearVelocity(this: v39, a2: (const idVec3 *)v135, a3: v92);
  v133 = (float)(v130 + (float)(v131[5] * (float)-5.0)) + (float)(v131[8] * (float)5.0);
  v132.z = (float)(v129 + (float)(v131[4] * (float)-5.0)) + (float)(v131[7] * (float)5.0);
  v132.y = (float)((float)(v131[3] * (float)-5.0) + *(float *)&v128.axisValid) + (float)(v131[6] * (float)5.0);
  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, bool *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &idColor::colorYellow,
    a3: &v132.y,
    a4: &v128.axisValid,
    a5: 2.0);
  ((void (__fastcall *)(idRenderWorld *, idColor *, bool *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &idColor::colorRed,
    a3: &v128.axisValid,
    a4: &v138,
    a5: 2.0);
  v95 = gameLocal;
  if ( gameLocal->spawnIds.ptr[p_selected->spawnId.value & 0x1FFF] == p_selected->spawnId.value >> 13 )
  {
    v96 = gameLocal->entities.ptr[p_selected->spawnId.value & 0x1FFF];
    if ( v96 != nullptr )
    {
      if ( idEntity::CastTo(c: v96) != nullptr )
      {
        v141.len = 0;
        v141.baseBuffer[0] = 0;
        v141.allocedAndFlag = 20;
        v141.data = v141.baseBuffer;
        if ( v39->type == PHYSICS_AF && (v97 = this->bodyId) >= 0 )
          str = (char *)idPhysics_AF::GetBody(this: (idPhysics_AF *)v39, id: v97)->name.str;
        else
          str = &byte_8200D768;
        idStr::operator=(this: &v141, text: str);
        v136[2] = v130 + (float)(v131[8] * (float)32.0);
        v136[1] = v129 + (float)(v131[7] * (float)32.0);
        v136[0] = (float)(v131[6] * (float)32.0) + *(float *)&v128.axisValid;
        v99 = idEntityPtr<idEntity const>::operator->(this: &this->selected);
        data = v141.data;
        v101 = idEntityPtr<idEntity const>::operator->(this: &this->selected);
        v102 = v99;
        GetType = v99->GetType;
        v103 = v101->name.data;
        v105 = (_DWORD *)GetType(this: v102);
        HIDWORD(v106) = data;
        HIDWORD(v107) = v103;
        LODWORD(v107) = *v105;
        v109 = va::va(
                 this: &v159,
                 fmt: "%s\n%s\n%s",
                 a3: v107,
                 a4: v106,
                 a5: v108,
                 a6: v122,
                 a7: v123,
                 a8: v124,
                 a9: v125,
                 a10: v126,
                 a11: v127);
        ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
          a1: clientGame->renderWorld,
          a2: v109,
          a3: v136,
          a4: clientGame->renderWorld->__vftable,
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.1);
        idStr::FreeData(this: &v141);
      }
LABEL_38:
      v95 = gameLocal;
    }
  }
  v110 = &this->selected;
  if ( v95->spawnIds.ptr[v110->spawnId.value & 0x1FFF] == v110->spawnId.value >> 13 )
  {
    v111 = v95->entities.ptr[v110->spawnId.value & 0x1FFF];
    if ( v111 != nullptr && idEntity::CastTo(c: v111) != nullptr && g_dragShowSelection.valueInteger != 0 )
    {
      v112 = idEntityPtr<idEntity const>::operator->(this: v110);
      v113 = v112->presentable;
      if ( v113 == nullptr || (model = v113->model, LODWORD(v132.x) = v112->presentable, v115 = 1, model == nullptr) )
        v115 = 0;
      if ( v115 != 0 )
      {
        v116 = idEntityPtr<idEntity const>::operator->(this: v110);
        v117 = v116->presentable;
        v118 = v116;
        if ( v117 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v116);
          v117 = v118->presentable;
        }
        renderWorld = clientGame->renderWorld;
        v120 = renderWorld->__vftable;
        v121 = idBox::idBox(
                 this: &v158,
                 bounds: &v117->model->referenceBounds,
                 origin: &v117->origin,
                 axis: &v117->axis);
        v120->DebugBox(this: renderWorld, a2: (const idVec4 *)&idColor::colorYellow, a3: v121, a4: 0, a5: false);
      }
    }
  }
}


// ========================================================================
// __unwind$491151
// EA  : 0x82BDD770
// RVA : 0x00BDD770
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_491151()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4960 + 320));
}


// ========================================================================
// ?DeleteSelected@idDragEntity@@QAAXXZ
// EA  : 0x82BDD798
// RVA : 0x00BDD798
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idDragEntity::DeleteSelected(idDragEntity *this)
{
  int value; // r10
  idEntity *v3; // r3
  idEntity *v4; // r3

  value = this->selected.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
      if ( v4 != nullptr )
        ((void (__fastcall *)(idEntity *, int))v4->dtr_idClass)(a1: v4, a2: 1);
    }
  }
  this->selected.spawnId.value = 0x1FFF;
  this->physicsId = -1;
}


// ========================================================================
// ?FindEntity@idEditEntities@@AAAPAVidEntity@@ABVidVec3@@0PBV2@@Z
// EA  : 0x82BDD830
// RVA : 0x00BDD830
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

idEntity *__fastcall idEditEntities::FindEntity(
        idEditEntities *this,
        const idVec3 *origin,
        const idVec3 *dir,
        const idEntity *skip)
{
  idEntity *v7; // r30
  double v8; // fp8
  double v9; // fp31
  double v10; // fp7
  idLinkList<idEntity> *next; // r11
  idEntity *i; // r31
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp10
  double v16; // fp8
  double v17; // fp6
  double v18; // fp4
  double v19; // fp3
  idLinkList<idEntity> *v20; // r11
  float v22[2]; // [sp+50h] [-80h] BYREF
  idVec3 v23; // [sp+58h] [-78h] BYREF
  idBounds v24; // [sp+70h] [-60h] BYREF

  v7 = nullptr;
  v8 = (float)(dir->y * (float)4096.0);
  v9 = 1.0;
  v10 = (float)(dir->z * (float)4096.0);
  v23.x = dir->x * (float)4096.0;
  v23.y = v8;
  v23.z = v10;
  next = gameLocal->spawnedEntities.next;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    for ( i = next->owner; i != nullptr; i = v20->owner )
    {
      if ( i != skip
        && (unsigned __int8)idEditEntities::EntityIsSelectable(
                              this,
                              ent: i,
                              color: nullptr,
                              text: nullptr,
                              type: nullptr) != 0 )
      {
        Physics = idEntity::GetPhysics(this: i);
        v14 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
        v15 = (float)(v14[4] + (float)16.0);
        v16 = (float)(v14[5] + (float)16.0);
        v17 = (float)(*v14 - (float)16.0);
        v18 = (float)(v14[1] - (float)16.0);
        v19 = (float)(v14[2] - (float)16.0);
        v24.b[1].x = v14[3] + (float)16.0;
        v24.b[1].y = v15;
        v24.b[1].z = v16;
        v24.b[0].x = v17;
        v24.b[0].y = v18;
        v24.b[0].z = v19;
        if ( (unsigned __int8)idBounds::RayIntersection(this: &v24, start: origin, dir: &v23, scale: v22) != 0
          && v22[0] >= 0.0
          && v22[0] < v9 )
        {
          v7 = i;
          v9 = v22[0];
        }
      }
      v20 = i->spawnNode.next;
      if ( v20 == nullptr )
        break;
      if ( v20 == i->spawnNode.head )
        break;
    }
  }
  return v7;
}


// ========================================================================
// ?UpdateSelected@idEditEntities@@QAA_NABVidVec3@@0PBVidEntity@@@Z
// EA  : 0x82BDD9E0
// RVA : 0x00BDD9E0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

int __fastcall idEditEntities::UpdateSelected(
        idEditEntities *this,
        const idVec3 *origin,
        const idVec3 *dir,
        const idEntity *skip)
{
  idPhysics *Physics; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  float *v13; // r3
  double v14; // fp28
  double v15; // fp27
  double v16; // fp26
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  char v20; // r11
  char v21; // r11
  int dragAxis; // r11
  double v23; // fp13
  double v24; // fp0
  double v25; // fp13
  int v26; // r11
  idPhysics *v27; // r3
  __int64 z_low; // r9
  float *v29; // r3
  long double v30; // fp2
  double v31; // fp10
  double v32; // fp9
  idEntity *Entity; // r3
  idPhysics *v34; // r3
  float *v35; // r3
  double v36; // fp7
  double v37; // fp6
  float x; // r11
  double v39; // fp12
  float y; // r7
  double v41; // fp9
  double z; // fp7
  double v43; // fp3
  double v44; // fp11
  double v45; // fp31
  long double v46; // fp2
  long double v47; // fp2
  long double v48; // fp2
  long double v49; // fp2
  long double v50; // fp2
  long double v51; // fp2
  idEntity *v52; // r11
  idCommon *v53; // r3
  idGame *(__fastcall *Game)(idCommon *); // ctr
  int v55; // r3
  __int64 v56; // [sp+50h] [-90h] BYREF
  int v57; // [sp+58h] [-88h]
  idVec3 v58; // [sp+60h] [-80h] BYREF
  idPlane v59; // [sp+70h] [-70h] BYREF

  if ( this->selectedEntities.num == 0 )
    return 0;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->dragTime >= 50 )
  {
    if ( g_editEntityMouseDrag.valueInteger != 0 )
    {
      Physics = idEntity::GetPhysics(this: *this->selectedEntities.list);
      v10 = -dir->x;
      v11 = -dir->y;
      v12 = -dir->z;
      v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v59.a = v10;
      v59.b = v11;
      v59.c = v12;
      *(float *)&v56 = 0.0;
      v59.d = -(float)((float)(*v13 * (float)v10) + (float)((float)(v13[1] * (float)v11) + (float)(v13[2] * (float)v12)));
      if ( (unsigned __int8)idPlane::RayIntersection(this: &v59, start: origin, dir, scale: (float *)&v56) == 0 )
        return 0;
      v14 = (float)(origin->x + (float)(dir->x * *(float *)&v56));
      v15 = (float)(origin->y + (float)(dir->y * *(float *)&v56));
      v16 = (float)(origin->z + (float)(dir->z * *(float *)&v56));
      v17 = (float)((float)(origin->x + (float)(dir->x * *(float *)&v56)) - this->lastDragPos.x);
      v18 = (float)((float)(origin->y + (float)(dir->y * *(float *)&v56)) - this->lastDragPos.y);
      v19 = (float)((float)(origin->z + (float)(dir->z * *(float *)&v56)) - this->lastDragPos.z);
      if ( v17 != vec3_origin.x || v18 != vec3_origin.y || (v20 = 1, v19 != vec3_origin.z) )
        v20 = 0;
      if ( v20 != 0 )
        return 0;
      if ( this->lastViewDir.x != dir->x || this->lastViewDir.y != dir->y || (v21 = 1, this->lastViewDir.z != dir->z) )
        v21 = 0;
      if ( v21 != 0 )
        return 0;
      dragAxis = this->dragAxis;
      if ( dragAxis == -1 )
      {
        v23 = __fabs(v17);
        v24 = 0.0;
        if ( v23 > 0.0 )
        {
          v24 = v23;
          dragAxis = 0;
        }
        v25 = __fabs(v18);
        if ( v25 > v24 )
        {
          v24 = v25;
          dragAxis = 1;
        }
        if ( __fabs(v19) > v24 )
          dragAxis = 2;
        this->dragAxis = dragAxis;
      }
      v26 = this->dragAxis;
      if ( v26 != 0 )
        v17 = 0.0;
      if ( v26 != 1 )
        v18 = 0.0;
      if ( v26 != 2 )
        v19 = 0.0;
      v27 = idEntity::GetPhysics(this: *this->selectedEntities.list);
      v29 = (float *)v27->GetOrigin(this: v27, a2: 0);
      *(double *)&v30 = (float)(*v29 + (float)v17);
      v31 = (float)(v29[1] + (float)v18);
      v32 = (float)(v29[2] + (float)v19);
      this->lastViewDir.x = dir->x;
      this->lastViewDir.y = dir->y;
      this->lastViewDir.z = dir->z;
      v58.y = v31;
      this->lastDragPos.x = v14;
      v58.z = v32;
      this->lastDragPos.y = v15;
      this->lastDragPos.z = v16;
    }
    else
    {
      if ( !this->dragging )
      {
        Entity = idEditEntities::FindEntity(this, origin, dir, skip);
        if ( Entity == nullptr || Entity != *this->selectedEntities.list )
          return 0;
        v34 = idEntity::GetPhysics(this: Entity);
        v35 = (float *)v34->GetOrigin(this: v34, a2: 0);
        v36 = (float)(v35[1] - origin->y);
        v37 = (float)(v35[2] - origin->z);
        this->lastDragPos.x = *v35 - origin->x;
        this->lastDragPos.y = v36;
        this->lastDragPos.z = v37;
      }
      x = this->lastDragPos.x;
      z_low = LODWORD(this->lastDragPos.z);
      this->dragAxis = 0;
      this->dragging = true;
      v39 = dir->x;
      y = this->lastDragPos.y;
      v41 = dir->y;
      *(float *)&v56 = x;
      v57 = z_low;
      z = dir->z;
      *((float *)&v56 + 1) = y;
      v43 = __fsqrts((float)((float)(x * x)
                           + (float)((float)(y * y) + (float)(*((float *)&z_low + 1) * *((float *)&z_low + 1)))));
      *((double *)&v30 + 1) = (float)((float)v39 * (float)v43);
      *(double *)&v30 = (float)(origin->x + (float)((float)v39 * (float)v43));
      v44 = (float)(origin->z + (float)((float)z * (float)v43));
      v58.y = origin->y + (float)((float)v41 * (float)v43);
      v58.z = v44;
    }
    v58.x = *(double *)&v30;
    LODWORD(z_low) = g_editEntityGridSize.valueInteger;
    v56 = z_low;
    v45 = (float)z_low;
    if ( v45 <= 0.0 )
    {
      v49 = floor(x: v30);
      v58.x = *(double *)&v49;
      *(double *)&v49 = v58.y;
      v50 = floor(x: v49);
      v58.y = *(double *)&v50;
      *(double *)&v50 = v58.z;
      v51 = floor(x: v50);
      v58.z = *(double *)&v51;
    }
    else
    {
      *(double *)&v30 = (float)((float)((float)((float)1.0 / (float)z_low) * (float)*(double *)&v30) + (float)0.5);
      v46 = floor(x: v30);
      v58.x = (float)*(double *)&v46 * (float)v45;
      *(double *)&v46 = (float)((float)((float)((float)1.0 / (float)v45) * v58.y) + (float)0.5);
      v47 = floor(x: v46);
      v58.y = (float)*(double *)&v47 * (float)v45;
      *(double *)&v47 = (float)((float)((float)((float)1.0 / (float)v45) * v58.z) + (float)0.5);
      v48 = floor(x: v47);
      v58.z = (float)*(double *)&v48 * (float)v45;
    }
    idEntity::SetOrigin(this: *this->selectedEntities.list, org: &v58);
    v52 = *this->selectedEntities.list;
    v53 = common;
    v52->spawnPosition.x = v58.x;
    Game = v53->Game;
    v52->spawnPosition.y = v58.y;
    v52->spawnPosition.z = v58.z;
    v55 = (int)Game(this: v53);
    (*(void (__fastcall **)(int, idEntity *, _DWORD, _DWORD))(*(_DWORD *)v55 + 620))(
      a1: v55,
      a2: *this->selectedEntities.list,
      a3: 0,
      a4: 0);
  }
  return 1;
}


// ========================================================================
// ??0idDragEntity@@QAA@XZ
// EA  : 0x82BDDFE8
// RVA : 0x00BDDFE8
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

idDragEntity *__fastcall idDragEntity::idDragEntity(idDragEntity *this)
{
  this->selected.spawnId.value = 0x1FFF;
  this->physicsId = -1;
  this->bodyId = 0;
  this->localPhysicsPoint.z = 0.0;
  this->localPhysicsPoint.y = 0.0;
  this->localPhysicsPoint.x = 0.0;
  this->localPlayerPoint.z = 0.0;
  this->localPlayerPoint.y = 0.0;
  this->localPlayerPoint.x = 0.0;
  this->selected.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idEditEntities@@QAA@XZ
// EA  : 0x82BDE1B0
// RVA : 0x00BDE1B0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

idEditEntities *__fastcall idEditEntities::idEditEntities(idEditEntities *this)
{
  idList<idSelectedTypeInfo,5> *p_selectableEntityClasses; // r28

  p_selectableEntityClasses = &this->selectableEntityClasses;
  this->selectableEntityClasses.granularity = 0;
  this->selectableEntityClasses.memTag = 5;
  this->selectableEntityClasses.listStatic = 0;
  this->selectableEntityClasses.list = nullptr;
  this->selectableEntityClasses.size = 0;
  this->selectableEntityClasses.num = 0;
  this->selectedEntities.list = nullptr;
  this->selectedEntities.granularity = 0;
  this->selectedEntities.memTag = 5;
  this->selectedEntities.listStatic = 0;
  this->selectedEntities.size = 0;
  this->selectedEntities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->selectedEntities);
  if ( this->selectableEntityClasses.listStatic == 0 || this->selectableEntityClasses.listStatic == 2 )
  {
    if ( p_selectableEntityClasses->list != nullptr )
      idListArrayDelete<idSelectedTypeInfo>(
        ptr: (char *)p_selectableEntityClasses->list,
        num: p_selectableEntityClasses->size);
    p_selectableEntityClasses->list = nullptr;
    p_selectableEntityClasses->size = 0;
  }
  p_selectableEntityClasses->num = 0;
  this->nextSelectTime = 0;
  this->lastSelectResult = false;
  this->dragging = false;
  this->dragTime = 0;
  this->dragAxis = -1;
  this->lastViewDir = vec3_origin;
  this->lastDragPos = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$493192
// EA  : 0x82BDE2B0
// RVA : 0x00BDE2B0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493192()
{
  int v0; // r12

  idList<idSelectedTypeInfo,5>::~idList<idSelectedTypeInfo,5>(this: (idList<idSelectedTypeInfo,5> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$493193
// EA  : 0x82BDE2DC
// RVA : 0x00BDE2DC
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493193()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// ?AddSelectedEntity@idEditEntities@@QAAXPAVidEntity@@@Z
// EA  : 0x82BDE308
// RVA : 0x00BDE308
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::AddSelectedEntity(
        idEditEntities *this,
        idEntity *ent,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idEntity *a14)
{
  char flags; // r11
  idList<enum encounterGroupRole_t,5> *p_selectedEntities; // r3
  int v16; // r10
  int num; // r9
  int v18; // r11

  flags = (char)ent->flags;
  p_selectedEntities = (idList<enum encounterGroupRole_t,5> *)&this->selectedEntities;
  a14 = ent;
  v16 = 0;
  *(_BYTE *)&ent->flags = flags | 1;
  num = p_selectedEntities->num;
  if ( num <= 0 )
    goto LABEL_7;
  v18 = 0;
  while ( (idEntity *)p_selectedEntities->list[v18] != ent )
  {
    ++v16;
    ++v18;
    if ( v16 >= num )
      goto LABEL_7;
  }
  if ( v16 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_selectedEntities, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?DisplayEntities@idEditEntities@@QAAXXZ
// EA  : 0x82BDE388
// RVA : 0x00BDE388
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::DisplayEntities(idEditEntities *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idList<idSelectedTypeInfo,5> *p_selectableEntityClasses; // r30
  __int64 v5; // r5
  double v6; // fp15
  idLinkList<idEntity> *next; // r11
  idEntity *owner; // r25
  const char *v9; // r14
  const char *v10; // r30
  char v11; // r21
  idAnimatedEntity *v12; // r3
  int v13; // r3
  char v14; // r11
  idPhysics *Physics; // r3
  float *v16; // r30
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp7
  double v20; // fp6
  double v21; // fp13
  double v22; // fp12
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp12
  double v26; // fp13
  double v27; // fp0
  char v28; // r11
  idPhysics *v29; // r3
  float *v30; // r23
  idGame *v31; // r3
  int v32; // r24
  double g; // fp13
  double b; // fp12
  double a; // fp11
  idGame *v36; // r3
  int v37; // r11
  double v38; // fp13
  double v39; // fp12
  double v40; // fp11
  idPhysics *v41; // r3
  idRenderWorld *renderWorld; // r24
  BOOL v43; // r30
  idRenderWorld_vtbl *v44; // r14
  int v45; // r3
  idPhysics *v46; // r3
  BOOL v47; // r30
  float *v48; // r3
  double v49; // fp12
  double v50; // fp11
  double v51; // fp10
  double v52; // fp9
  double v53; // fp8
  double v54; // fp6
  idPhysics *v55; // r3
  float *v56; // r3
  const idVec3 *v57; // r30
  idPhysics *v58; // r3
  float *v59; // r3
  double v60; // fp6
  double x; // fp0
  double v62; // fp9
  double z; // fp13
  idPhysics *v64; // r3
  float *v65; // r3
  double v66; // fp8
  double v67; // fp9
  double v68; // fp7
  double y; // fp5
  idPhysics *v70; // r3
  float *v71; // r3
  double v72; // fp5
  double v73; // fp4
  double v74; // fp11
  double v75; // fp10
  idPhysics *v76; // r3
  float *v77; // r3
  double v78; // fp3
  double v79; // fp2
  double v80; // fp9
  double v81; // fp8
  idPhysics *v82; // r3
  float *v83; // r3
  double v84; // fp13
  double v85; // fp0
  double v86; // fp6
  double v87; // fp7
  idPhysics *v88; // r3
  float *v89; // r3
  double v90; // fp5
  double v91; // fp4
  double v92; // fp12
  double v93; // fp11
  double v94; // fp13
  double v95; // fp11
  double v96; // fp7
  double v97; // fp5
  double v98; // fp0
  double v99; // fp12
  double v100; // fp7
  double v101; // fp6
  double v102; // fp10
  double v103; // fp7
  double v104; // fp6
  double v105; // fp5
  int v106; // r9
  int v107; // r10
  int v108; // r24
  int v109; // r6
  const idVec4 *v110; // r24
  int GameMsPerFrame; // r3
  double v112; // fp13
  double v113; // fp12
  double v114; // fp10
  double v115; // fp8
  const idVec4 *v116; // r24
  int v117; // r3
  double v118; // fp12
  double v119; // fp11
  double v120; // fp8
  double v121; // fp9
  const idVec4 *v122; // r24
  int v123; // r3
  double v124; // fp13
  double v125; // fp12
  double v126; // fp8
  double v127; // fp9
  int entityNumber; // r8
  double v129; // fp5
  double v130; // fp4
  __int64 v131; // r10
  __int64 v132; // r8
  __int64 v133; // r6
  const char *v134; // r24
  va *v135; // r3
  idColor *v136; // r23
  int v137; // r8
  double v138; // fp13
  double v139; // fp12
  __int64 v140; // r10
  __int64 v141; // r8
  __int64 v142; // r6
  va *v143; // r3
  int v144; // r8
  double v145; // fp13
  double v146; // fp12
  __int64 v147; // r10
  __int64 v148; // r8
  __int64 v149; // r6
  va *v150; // r3
  int v151; // r8
  double v152; // fp13
  double v153; // fp12
  __int64 v154; // r10
  __int64 v155; // r8
  __int64 v156; // r6
  va *v157; // r3
  int v158; // r8
  double v159; // fp8
  double v160; // fp7
  __int64 v161; // r10
  __int64 v162; // r8
  __int64 v163; // r6
  va *v164; // r3
  int v165; // r8
  double v166; // fp8
  double v167; // fp7
  __int64 v168; // r10
  __int64 v169; // r8
  __int64 v170; // r6
  va *v171; // r3
  idPhysics *v172; // r3
  const idVec3 *v173; // r3
  idTypeInfoObject *v174; // r3
  char *data; // r24
  idTypeInfoObject *v176; // r3
  idPhysics *v177; // r3
  float *v178; // r3
  double v179; // fp13
  double v180; // fp12
  idMapEntity *v181; // r3
  idList<idStr,5> *p_layerList; // r23
  int v183; // r30
  int v184; // r24
  idPhysics *v185; // r3
  __int64 v186; // r11
  double v187; // fp15
  double v188; // fp14
  float *v189; // r3
  double v190; // fp10
  double v191; // fp6
  idLinkList<idEntity> *v192; // r11
  int v193; // [sp+8h] [-1698h]
  int v194; // [sp+Ch] [-1694h]
  int v195; // [sp+10h] [-1690h]
  int v196; // [sp+14h] [-168Ch]
  int v197; // [sp+18h] [-1688h]
  int v198; // [sp+1Ch] [-1684h]
  float v199; // [sp+68h] [-1638h] BYREF
  float v200; // [sp+6Ch] [-1634h]
  float v201; // [sp+70h] [-1630h]
  char v202; // [sp+74h] [-162Ch]
  idColor *v203; // [sp+78h] [-1628h]
  idCVar *v204; // [sp+7Ch] [-1624h]
  float v205; // [sp+80h] [-1620h] BYREF
  float v206; // [sp+84h] [-161Ch] BYREF
  idCVar *v207; // [sp+88h] [-1618h]
  const char *v208; // [sp+8Ch] [-1614h]
  idColor *v209; // [sp+90h] [-1610h]
  const char *v210; // [sp+94h] [-160Ch]
  idSelectedTypeInfo v211; // [sp+A0h] [-1600h] BYREF
  idVec4 v212; // [sp+F0h] [-15B0h] BYREF
  idEntityInterfaceObject v213; // [sp+100h] [-15A0h] BYREF
  const idVec4 *v214; // [sp+108h] [-1598h]
  const idVec3 *v215; // [sp+10Ch] [-1594h]
  const char *v216; // [sp+110h] [-1590h]
  idCVar *v217; // [sp+114h] [-158Ch]
  const char *v218; // [sp+118h] [-1588h]
  float v219; // [sp+11Ch] [-1584h]
  float v220; // [sp+120h] [-1580h]
  const int *v221; // [sp+124h] [-157Ch]
  float v222; // [sp+128h] [-1578h]
  float v223; // [sp+130h] [-1570h]
  float v224; // [sp+134h] [-156Ch]
  float v225; // [sp+138h] [-1568h]
  float v226; // [sp+13Ch] [-1564h]
  float v227; // [sp+140h] [-1560h]
  float v228; // [sp+144h] [-155Ch]
  const char *v229; // [sp+148h] [-1558h]
  float v230[6]; // [sp+150h] [-1550h] BYREF
  idCVar *v231; // [sp+168h] [-1538h]
  float v232; // [sp+16Ch] [-1534h]
  const char *v233; // [sp+170h] [-1530h]
  idStr v234; // [sp+180h] [-1520h] BYREF
  idStr v235; // [sp+1A0h] [-1500h] BYREF
  idStr v236; // [sp+1C0h] [-14E0h] BYREF
  float v237[4]; // [sp+1E0h] [-14C0h] BYREF
  idVec3 v238; // [sp+1F0h] [-14B0h] BYREF
  float v239[4]; // [sp+200h] [-14A0h] BYREF
  float v240[4]; // [sp+210h] [-1490h] BYREF
  idVec3 v241; // [sp+220h] [-1480h] BYREF
  float v242[4]; // [sp+230h] [-1470h] BYREF
  float v243[4]; // [sp+240h] [-1460h] BYREF
  float v244[4]; // [sp+250h] [-1450h] BYREF
  float v245[4]; // [sp+260h] [-1440h] BYREF
  float v246[4]; // [sp+270h] [-1430h] BYREF
  float v247[4]; // [sp+280h] [-1420h] BYREF
  float v248[4]; // [sp+290h] [-1410h] BYREF
  float v249[4]; // [sp+2A0h] [-1400h] BYREF
  float v250[4]; // [sp+2B0h] [-13F0h] BYREF
  idTypeInfoVariable_StrPtr v251; // [sp+2C0h] [-13E0h] BYREF
  idVec3 v252; // [sp+2D0h] [-13D0h] BYREF
  float v253[4]; // [sp+2E0h] [-13C0h] BYREF
  idVec3 v254; // [sp+2F0h] [-13B0h] BYREF
  float v255[4]; // [sp+300h] [-13A0h] BYREF
  idVec3 v256; // [sp+310h] [-1390h] BYREF
  idVec3 v257; // [sp+320h] [-1380h] BYREF
  idVec3 v258; // [sp+330h] [-1370h] BYREF
  float v259[4]; // [sp+340h] [-1360h] BYREF
  float v260[4]; // [sp+350h] [-1350h] BYREF
  float v261[4]; // [sp+360h] [-1340h] BYREF
  float v262[4]; // [sp+370h] [-1330h] BYREF
  float v263[4]; // [sp+380h] [-1320h] BYREF
  float v264[4]; // [sp+390h] [-1310h] BYREF
  float v265[4]; // [sp+3A0h] [-1300h] BYREF
  float v266[4]; // [sp+3B0h] [-12F0h] BYREF
  float v267[4]; // [sp+3C0h] [-12E0h] BYREF
  float v268[4]; // [sp+3D0h] [-12D0h] BYREF
  float v269[4]; // [sp+3E0h] [-12C0h] BYREF
  float v270[4]; // [sp+3F0h] [-12B0h] BYREF
  float v271[4]; // [sp+400h] [-12A0h] BYREF
  float v272[4]; // [sp+410h] [-1290h] BYREF
  float v273[4]; // [sp+420h] [-1280h] BYREF
  idBounds v274; // [sp+430h] [-1270h] BYREF
  idStr v275; // [sp+450h] [-1250h] BYREF
  __int64 v276; // [sp+470h] [-1230h]
  trace_t v277; // [sp+480h] [-1220h] BYREF
  idStr v278; // [sp+500h] [-11A0h] BYREF
  idStr v279; // [sp+520h] [-1180h] BYREF
  idMat3 v280; // [sp+540h] [-1160h] BYREF
  va v281; // [sp+570h] [-1130h] BYREF

  v234.len = 0;
  v234.allocedAndFlag = 20;
  v234.data = v234.baseBuffer;
  v234.baseBuffer[0] = 0;
  v236.allocedAndFlag = 20;
  v236.data = v236.baseBuffer;
  v236.len = 0;
  v236.baseBuffer[0] = 0;
  v202 = 0;
  presentable = idGameLocal::GetDebugPlayer(this: gameLocal)->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  idView::GetViewPos(this: (idView *)(v3 + 16224), origin: &v257, axis: &v280);
  p_selectableEntityClasses = &this->selectableEntityClasses;
  if ( p_selectableEntityClasses->listStatic == 0 || p_selectableEntityClasses->listStatic == 2 )
  {
    if ( p_selectableEntityClasses->list != nullptr )
      idListArrayDelete<idSelectedTypeInfo>(
        ptr: (char *)p_selectableEntityClasses->list,
        num: p_selectableEntityClasses->size);
    p_selectableEntityClasses->list = nullptr;
    p_selectableEntityClasses->size = 0;
  }
  p_selectableEntityClasses->num = 0;
  v211.typeInfo = nullptr;
  v211.typeKey.data = v211.typeKey.baseBuffer;
  v211.typeKey.len = 0;
  v211.typeKey.baseBuffer[0] = 0;
  v211.textKey.len = 0;
  v211.textKey.data = v211.textKey.baseBuffer;
  v211.textKey.baseBuffer[0] = 0;
  v211.entityMustExistInMapFile = false;
  v211.typeKey.allocedAndFlag = 20;
  v211.textKey.allocedAndFlag = 20;
  v204 = &g_editEntityMode;
  if ( (unsigned int)(g_editEntityMode.valueInteger - 1) > 8 )
  {
    idFuncChain::binddef_t::~binddef_t(this: &v211);
    idStr::FreeData(this: &v236);
    goto LABEL_136;
  }
  switch ( g_editEntityMode.valueInteger )
  {
    case 2:
      v211.typeInfo = &idSound::Type;
      idStr::operator=(this: &v211.typeKey, text: "idSoundShader");
      idStr::operator=(this: &v211.textKey, text: "soundShader");
      idList<idSelectedTypeInfo,5>::Append(this: p_selectableEntityClasses, obj: &v211);
      if ( g_showLightEntities.valueInteger == 0 )
        goto LABEL_30;
      v211.typeInfo = &idLight::Type;
      idStr::operator=(this: &v211.typeKey, text: "idSoundShader");
      idStr::operator=(this: &v211.textKey, text: "soundInfo.shader");
      break;
    case 3:
      v211.typeInfo = &idAFEntity_Generic::Type;
      idStr::operator=(this: &v211.typeKey, text: "idDeclAF");
      idStr::operator=(this: &v211.textKey, text: "afProperties.articulatedFigure");
      break;
    case 4:
      v211.typeInfo = &idParticleEmitter::Type;
      idStr::operator=(this: &v211.typeKey, text: "idDeclParticle");
      idStr::operator=(this: &v211.textKey, text: "particleSystem");
      break;
    case 5:
      v211.typeInfo = &idAI2::Type;
      idStr::operator=(this: &v211.textKey, text: "name");
      break;
    case 6:
      v211.typeInfo = &idEntity::Type;
      idStr::operator=(this: &v211.textKey, text: "name");
      break;
    case 7:
      v211.typeInfo = &idEntity::Type;
      idStr::operator=(this: &v211.textKey, text: "model");
      break;
    case 8:
      v211.typeInfo = &idEntityFx::Type;
      idStr::operator=(this: &v211.typeKey, text: "idDeclFX");
      idStr::operator=(this: &v211.textKey, text: "fxEffect");
      break;
    case 1:
      v211.typeInfo = &idLight::Type;
      idStr::operator=(this: &v211.textKey, text: "texture");
      break;
    default:
      v211.entityMustExistInMapFile = true;
      v211.typeInfo = &idEntity::Type;
      break;
  }
  idList<idSelectedTypeInfo,5>::Append(this: p_selectableEntityClasses, obj: &v211);
LABEL_30:
  v274.b[0].x = v257.x - (float)256.0;
  LODWORD(v5) = g_showEditEntityDistance.valueInteger;
  v6 = 512.0;
  v206 = 0.0;
  v205 = 512.0;
  next = gameLocal->spawnedEntities.next;
  v274.b[0].y = v257.y - (float)256.0;
  v274.b[0].z = v257.z - (float)256.0;
  v222 = 512.0;
  v274.b[1].x = v257.x + (float)256.0;
  v274.b[1].y = v257.y + (float)256.0;
  v274.b[1].z = v257.z + (float)256.0;
  v223 = v257.x - (float)v5;
  v224 = v257.y - (float)v5;
  v225 = v257.z - (float)v5;
  v226 = v257.x + (float)v5;
  v227 = v257.y + (float)v5;
  v228 = v257.z + (float)v5;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    owner = next->owner;
    if ( owner != nullptr )
    {
      v231 = &g_showEditLayerNames;
      v219 = 0.00390625;
      v215 = &vec3_origin;
      v218 = "null";
      v229 = "*";
      v208 = "%i";
      v209 = &idColor::colorYellow;
      v214 = (const idVec4 *)&idColor::colorRed;
      v221 = validSegments;
      v217 = &g_showEditEntityInfo;
      v210 = "x+";
      v9 = "x-";
      v233 = "x-";
      v203 = &idColor::colorMdGrey;
      v207 = &g_showEditEntityLocalAxes;
      v232 = 12.0;
      v220 = 0.25;
      v216 = &byte_8200D768;
      while ( 1 )
      {
        v10 = v216;
        idStr::operator=(this: &v236, text: v216);
        idStr::operator=(this: &v234, text: v10);
        if ( (unsigned __int8)idEditEntities::EntityIsSelectable(
                                this,
                                ent: owner,
                                color: &v212,
                                text: &v234,
                                type: &v236) != 0 )
        {
          v11 = 0;
          if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: owner) != 0 )
          {
            v12 = idAnimatedEntity::CastTo(c: (idAnimatedEntity *)owner);
            v13 = (int)v12->GetAF_2(this: v12);
            if ( v13 != 0 )
            {
              if ( *(_BYTE *)(v13 + 267) != 0 || (v14 = 0, *(_BYTE *)(v13 + 268) != 0) )
                v14 = 1;
              if ( v14 == 0 )
                goto LABEL_131;
            }
          }
          else if ( (unsigned __int8)idSound::IsTypeOf(c: owner) != 0
                 || (unsigned __int8)idLight::IsTypeOf(c: owner) != 0 && v204->valueInteger == 2 )
          {
            if ( (*(_BYTE *)&owner->flags & 1) != 0 )
            {
              v11 = 1;
              if ( gameLocal->EntityGetSoundDistances(this: gameLocal, a2: owner, a3: &v206, a4: &v205) )
                v202 = 1;
            }
          }
          else if ( (unsigned __int8)idParticleEmitter::IsTypeOf(c: owner) != 0 && (*(_BYTE *)&owner->flags & 1) != 0 )
          {
            v11 = 1;
            if ( v207->valueInteger == 0 )
            {
              Physics = idEntity::GetPhysics(this: owner);
              v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v17 = idEntity::GetPhysics(this: owner);
              v18 = (float *)v17->GetAxis(this: v17, a2: 0);
              v19 = (float)(v18[7] * (float)50.0);
              v20 = (float)(v18[6] * (float)50.0);
              v21 = v16[1];
              v22 = *v16;
              v265[2] = v16[2] + (float)(v18[8] * (float)50.0);
              v265[1] = (float)v21 + (float)v19;
              v265[0] = (float)v22 + (float)v20;
              ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
                a1: clientGame->renderWorld,
                a2: &idColor::colorGreen,
                a3: v16,
                a4: v265,
                a5: 2.0);
            }
          }
          if ( (*(_BYTE *)&owner->flags & 1) != 0 )
            goto LABEL_61;
          v23 = idEntity::GetPhysics(this: owner);
          v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
          v25 = *v24;
          if ( v25 < v223
            || (v26 = v24[1]) < v224
            || (v27 = v24[2]) < v225
            || v25 > v226
            || v26 > v227
            || (v28 = 1, v27 > v228) )
          {
            v28 = 0;
          }
          if ( v28 != 0 )
          {
LABEL_61:
            v29 = idEntity::GetPhysics(this: owner);
            v30 = (float *)v29->GetBounds(this: v29, a2: -1);
            if ( v204->valueInteger == 4 )
            {
              v31 = common->Game(this: common);
              v32 = (int)v31->MapFindEntity_2(this: v31, a2: owner);
              if ( v32 != 0 )
              {
                v275.len = 0;
                v275.baseBuffer[0] = 0;
                v275.data = v275.baseBuffer;
                v275.allocedAndFlag = 20;
                common->GetToolReferenceMap(this: common, a2: EDITOR_PARTICLE, a3: &v275);
                if ( v275.len != 0 && idStr::Icmp(s1: v275.data, s2: *(const char **)(v32 + 80)) != 0 )
                {
                  g = v203->g;
                  b = v203->b;
                  a = v203->a;
                  v212.x = v203->r;
                  v212.y = g;
                  v212.z = b;
                  v212.w = a;
                }
                idStr::FreeData(this: &v275);
              }
            }
            if ( v204->valueInteger == 2 )
            {
              v36 = common->Game(this: common);
              v37 = (int)v36->MapFindEntity_2(this: v36, a2: owner);
              if ( v37 != 0 )
              {
                idStr::idStr(this: &v278, text: *(const char **)(v37 + 80));
                if ( v278.len != 0 )
                {
                  v38 = v203->g;
                  v39 = v203->b;
                  v40 = v203->a;
                  v212.x = v203->r;
                  v212.y = v38;
                  v212.z = v39;
                  v212.w = v40;
                }
                idStr::FreeData(this: &v278);
              }
            }
            if ( *v30 >= (double)v30[3]
              || v30[1] >= (double)v30[4]
              || v30[2] >= (double)v30[5]
              || (float)((float)((float)(v30[5] - v30[2]) * (float)(v30[4] - v30[1])) * (float)(v30[3] - *v30)) <= 0.0 )
            {
              v46 = idEntity::GetPhysics(this: owner);
              v47 = g_showEditEntityDepthTested.valueInteger != 0;
              v48 = (float *)v46->GetOrigin(this: v46, a2: 0);
              v49 = (float)(*v48 - (float)8.0);
              v230[0] = *v48;
              v50 = (float)(v48[1] - (float)8.0);
              v230[1] = v48[1];
              v51 = (float)(v48[2] - (float)8.0);
              v230[2] = v48[2];
              v52 = (float)(*v48 + (float)8.0);
              v230[3] = *v48;
              v53 = (float)(v48[1] + (float)8.0);
              v230[4] = v48[1];
              v54 = (float)(v48[2] + (float)8.0);
              v230[0] = v49;
              v230[1] = v50;
              v230[2] = v51;
              v230[3] = v52;
              v230[4] = v53;
              v230[5] = v54;
              clientGame->renderWorld->DebugBounds(
                this: clientGame->renderWorld,
                a2: &v212,
                a3: (const idBounds *)v230,
                a4: v215,
                a5: 0,
                a6: v47);
            }
            else
            {
              v41 = idEntity::GetPhysics(this: owner);
              renderWorld = clientGame->renderWorld;
              v43 = g_showEditEntityDepthTested.valueInteger != 0;
              v44 = renderWorld->__vftable;
              v45 = (int)v41->GetOrigin(this: v41, a2: 0);
              v44->DebugBounds(
                this: renderWorld,
                a2: &v212,
                a3: (const idBounds *)v30,
                a4: (const idVec3 *)v45,
                a5: 0,
                a6: v43);
              v9 = v233;
            }
            if ( v11 != 0 )
            {
              v55 = idEntity::GetPhysics(this: owner);
              v56 = (float *)v55->GetOrigin(this: v55, a2: 0);
              v57 = (const idVec3 *)v56;
              if ( v207->valueInteger != 0 )
              {
                v58 = idEntity::GetPhysics(this: owner);
                v59 = (float *)v58->GetAxis(this: v58, a2: 0);
                v60 = (float)(*v59 * (float)20.0);
                x = v57->x;
                v62 = (float)(v59[2] * (float)20.0);
                z = v57->z;
                v200 = v57->y + (float)(v59[1] * (float)20.0);
                v199 = (float)v60 + (float)x;
                v201 = (float)z + (float)v62;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorWhite,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v267[1] = v200;
                v267[2] = v201;
                v267[0] = v199 + (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v210,
                  a3: v267,
                  a4: clientGame->renderWorld->DebugText,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v64 = idEntity::GetPhysics(this: owner);
                v65 = (float *)v64->GetAxis(this: v64, a2: 0);
                v66 = v57->z;
                v67 = (float)(v65[2] * (float)-20.0);
                v68 = (float)(v65[1] * (float)-20.0);
                y = v57->y;
                v199 = (float)(*v65 * (float)-20.0) + v57->x;
                v201 = (float)v66 + (float)v67;
                v200 = (float)y + (float)v68;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorWhite,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v269[1] = v200;
                v269[2] = v201;
                v269[0] = v199 - (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v9,
                  a3: v269,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v70 = idEntity::GetPhysics(this: owner);
                v71 = (float *)v70->GetAxis(this: v70, a2: 0);
                v72 = (float)(v71[4] * (float)20.0);
                v73 = (float)(v71[3] * (float)20.0);
                v74 = v57->y;
                v75 = v57->x;
                v201 = v57->z + (float)(v71[5] * (float)20.0);
                v200 = (float)v74 + (float)v72;
                v199 = (float)v73 + (float)v75;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorGreen,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v271[2] = v201;
                v271[1] = v200 + (float)4.0;
                v271[0] = v199;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "y+",
                  a3: v271,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v76 = idEntity::GetPhysics(this: owner);
                v77 = (float *)v76->GetAxis(this: v76, a2: 0);
                v78 = (float)(v77[4] * (float)-20.0);
                v79 = (float)(v77[3] * (float)-20.0);
                v80 = v57->y;
                v81 = v57->x;
                v201 = v57->z + (float)(v77[5] * (float)-20.0);
                v200 = (float)v80 + (float)v78;
                v199 = (float)v79 + (float)v81;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, int, _DWORD, bool, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorGreen,
                  a3: v57,
                  a4: &v199,
                  a5: g_showEditEntityDepthTested.valueInteger - 1,
                  a6: 0,
                  a7: g_showEditEntityDepthTested.valueInteger != 0,
                  a8: 2.0);
                v260[2] = v201;
                v260[0] = v199;
                v260[1] = v200 - (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, int, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "y-",
                  a3: v260,
                  a4: g_showEditEntityDepthTested.valueInteger - 1,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v82 = idEntity::GetPhysics(this: owner);
                v83 = (float *)v82->GetAxis(this: v82, a2: 0);
                v84 = (float)(v83[6] * (float)20.0);
                v85 = (float)(v83[7] * (float)20.0);
                v86 = v57->x;
                v87 = v57->y;
                v201 = v57->z + (float)(v83[8] * (float)20.0);
                v199 = (float)v84 + (float)v86;
                v200 = (float)v87 + (float)v85;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorBlue,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v263[0] = v199;
                v263[2] = v201 + (float)4.0;
                v263[1] = v200;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "z+",
                  a3: v263,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v88 = idEntity::GetPhysics(this: owner);
                v89 = (float *)v88->GetAxis(this: v88, a2: 0);
                v90 = v57->z;
                v91 = v57->y;
                v92 = (float)(v89[8] * (float)-20.0);
                v93 = (float)(v89[7] * (float)-20.0);
                v199 = (float)(v89[6] * (float)-20.0) + v57->x;
                v201 = (float)v90 + (float)v92;
                v200 = (float)v91 + (float)v93;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorBlue,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v244[1] = v200;
                v244[2] = v201 - (float)4.0;
                v244[0] = v199;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "z-",
                  a3: v244,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
              }
              else
              {
                v94 = v56[2];
                v95 = v56[1];
                v199 = *v56 + (float)20.0;
                v201 = v94;
                v200 = v95;
                ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorWhite,
                  a3: v56,
                  a4: &v199,
                  a5: 2.0);
                v240[2] = v201;
                v240[1] = v200;
                v240[0] = v199 + (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v210,
                  a3: v240,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v96 = v57->z;
                v97 = v57->y;
                v199 = v57->x - (float)20.0;
                v200 = v97;
                v201 = v96;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorWhite,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v245[0] = v199 - (float)4.0;
                v245[2] = v201;
                v245[1] = v200;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v9,
                  a3: v245,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v98 = v57->z;
                v99 = v57->x;
                v200 = v57->y + (float)20.0;
                v199 = v99;
                v201 = v98;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorGreen,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v242[2] = v201;
                v242[1] = v200 + (float)4.0;
                v242[0] = v199;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "y+",
                  a3: v242,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v100 = v57->z;
                v101 = (float)(v57->y - (float)20.0);
                v199 = v57->x;
                v200 = v101;
                v201 = v100;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorGreen,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v247[2] = v201;
                v247[0] = v199;
                v247[1] = v200 - (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "y-",
                  a3: v247,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v102 = v57->y;
                v103 = v57->x;
                v201 = v57->z + (float)(vec3_up.z * (float)20.0);
                v200 = (float)v102 + (float)(vec3_up.y * (float)20.0);
                v199 = (float)(vec3_up.x * (float)20.0) + (float)v103;
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorBlue,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v237[1] = v200;
                v237[0] = v199;
                v237[2] = v201 + (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "z+",
                  a3: v237,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
                v104 = v57->y;
                v105 = (float)((float)(vec3_up.x * (float)-20.0) + v57->x);
                v201 = v57->z + (float)(vec3_up.z * (float)-20.0);
                v199 = v105;
                v200 = (float)v104 + (float)(vec3_up.y * (float)-20.0);
                ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &idColor::colorBlue,
                  a3: v57,
                  a4: &v199,
                  a5: 2.0);
                v249[1] = v200;
                v249[0] = v199;
                v249[2] = v201 - (float)4.0;
                ((void (__fastcall *)(idRenderWorld *, const char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, bool, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: "z-",
                  a3: v249,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: g_showEditEntityDepthTested.valueInteger != 0,
                  a9: 0.15000001);
              }
              if ( v217->valueInteger != 0 && v202 != 0 )
              {
                v106 = (int)(float)((float)(v206 - (float)256.0) * (float)0.0078125);
                if ( v106 >= 0 )
                {
                  if ( v106 > 9 )
                    v106 = 9;
                }
                else
                {
                  v106 = 0;
                }
                v107 = (int)(float)((float)(v205 - (float)v6) * v219);
                if ( v107 >= 0 )
                {
                  if ( v107 > 9 )
                    v107 = 9;
                }
                else
                {
                  v107 = 0;
                }
                v272[0] = v57->x;
                v272[1] = v57->y;
                v108 = v221[v107];
                v272[2] = v57->z;
                v109 = v221[v106];
                v272[3] = v206;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorGreen,
                  a3: (const idSphere *)v272,
                  a4: v109,
                  a5: 0,
                  a6: true);
                v273[0] = v57->x;
                v273[1] = v57->y;
                v273[2] = v57->z;
                v273[3] = v205;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: v214,
                  a3: (const idSphere *)v273,
                  a4: v108,
                  a5: 0,
                  a6: true);
              }
              if ( this->dragging )
              {
                v110 = (const idVec4 *)&idColor::colorWhite;
                if ( this->dragAxis != 0 )
                  v110 = (const idVec4 *)v203;
                GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
                v112 = v57->z;
                v113 = (float)(v57->x + (float)2048.0);
                v246[1] = v57->y;
                v246[0] = v113;
                v246[2] = v112;
                v114 = v57->y;
                v115 = v57->z;
                v266[0] = v57->x - (float)2048.0;
                v266[2] = v115;
                v266[1] = v114;
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: v110,
                  a3: (const idVec3 *)v266,
                  a4: (const idVec3 *)v246,
                  a5: GameMsPerFrame,
                  a6: true);
                v116 = (const idVec4 *)&idColor::colorWhite;
                if ( this->dragAxis != 1 )
                  v116 = (const idVec4 *)v203;
                v117 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v118 = (float)(v57->y + (float)2048.0);
                v119 = v57->x;
                v248[2] = v57->z;
                v248[1] = v118;
                v248[0] = v119;
                v120 = (float)(v57->y - (float)2048.0);
                v121 = v57->z;
                v262[0] = v57->x;
                v262[2] = v121;
                v262[1] = v120;
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: v116,
                  a3: (const idVec3 *)v262,
                  a4: (const idVec3 *)v248,
                  a5: v117,
                  a6: true);
                v122 = (const idVec4 *)&idColor::colorWhite;
                if ( this->dragAxis != 2 )
                  v122 = (const idVec4 *)v203;
                v123 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                v124 = v57->y;
                v125 = (float)(v57->z + (float)2048.0);
                v250[0] = v57->x;
                v250[1] = v124;
                v250[2] = v125;
                v126 = v57->y;
                v127 = (float)(v57->z - (float)2048.0);
                v270[0] = v57->x;
                v270[1] = v126;
                v270[2] = v127;
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: v122,
                  a3: (const idVec3 *)v270,
                  a4: (const idVec3 *)v250,
                  a5: v123,
                  a6: true);
                entityNumber = owner->entityNumber;
                v129 = v57->z;
                v130 = (float)(v57->x + (float)2048.0);
                v252.y = v57->y;
                v252.x = v130;
                v252.z = v129;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v252,
                  clipMask: 8462469,
                  passEntityNumber: entityNumber);
                v134 = v208;
                if ( v277.fraction >= 1.0 )
                {
                  v136 = v209;
                }
                else
                {
                  v264[1] = v277.endpos.y;
                  v264[2] = v277.endpos.z;
                  v264[0] = v277.endpos.x + (float)4.0;
                  HIDWORD(v133) = (int)(float)(v277.endpos.x - v57->x);
                  v135 = va::va(
                           this: &v281,
                           fmt: v208,
                           a3: v133,
                           a4: v132,
                           a5: v131,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  v136 = v209;
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v135,
                    a3: v264,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v209,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
                v137 = owner->entityNumber;
                v138 = v57->z;
                v139 = (float)(v57->x - (float)2048.0);
                v254.y = v57->y;
                v254.x = v139;
                v254.z = v138;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v254,
                  clipMask: 8462469,
                  passEntityNumber: v137);
                if ( v277.fraction < 1.0 )
                {
                  v268[0] = v277.endpos.x - (float)4.0;
                  v268[2] = v277.endpos.z;
                  v268[1] = v277.endpos.y;
                  HIDWORD(v142) = (int)(float)(v57->x - v277.endpos.x);
                  v143 = va::va(
                           this: &v281,
                           fmt: v134,
                           a3: v142,
                           a4: v141,
                           a5: v140,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v143,
                    a3: v268,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v136,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
                v144 = owner->entityNumber;
                v145 = v57->z;
                v146 = (float)(v57->y + (float)2048.0);
                v256.x = v57->x;
                v256.z = v145;
                v256.y = v146;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v256,
                  clipMask: 8462469,
                  passEntityNumber: v144);
                if ( v277.fraction < 1.0 )
                {
                  v259[0] = v277.endpos.x + (float)4.0;
                  v259[1] = v277.endpos.y;
                  v259[2] = v277.endpos.z;
                  HIDWORD(v149) = (int)(float)(v277.endpos.y - v57->y);
                  v150 = va::va(
                           this: &v281,
                           fmt: v134,
                           a3: v149,
                           a4: v148,
                           a5: v147,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v150,
                    a3: v259,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v136,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
                v151 = owner->entityNumber;
                v152 = v57->z;
                v153 = (float)(v57->y - (float)2048.0);
                v258.x = v57->x;
                v258.z = v152;
                v258.y = v153;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v258,
                  clipMask: 8462469,
                  passEntityNumber: v151);
                if ( v277.fraction < 1.0 )
                {
                  v261[0] = v277.endpos.x - (float)4.0;
                  v261[1] = v277.endpos.y;
                  v261[2] = v277.endpos.z;
                  HIDWORD(v156) = (int)(float)(v57->y - v277.endpos.y);
                  v157 = va::va(
                           this: &v281,
                           fmt: v134,
                           a3: v156,
                           a4: v155,
                           a5: v154,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v157,
                    a3: v261,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v136,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
                v158 = owner->entityNumber;
                v159 = v57->y;
                v160 = v57->x;
                v238.z = (float)(vec3_up.z * (float)2048.0) + v57->z;
                v238.y = (float)(vec3_up.y * (float)2048.0) + (float)v159;
                v238.x = (float)(vec3_up.x * (float)2048.0) + (float)v160;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v238,
                  clipMask: 8462469,
                  passEntityNumber: v158);
                if ( v277.fraction < 1.0 )
                {
                  v239[0] = v277.endpos.x + (float)4.0;
                  v239[1] = v277.endpos.y;
                  v239[2] = v277.endpos.z;
                  HIDWORD(v163) = (int)(float)(v277.endpos.z - v57->z);
                  v164 = va::va(
                           this: &v281,
                           fmt: v134,
                           a3: v163,
                           a4: v162,
                           a5: v161,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v164,
                    a3: v239,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v136,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
                v165 = owner->entityNumber;
                v166 = v57->y;
                v167 = v57->x;
                v241.z = (float)(vec3_up.z * (float)-2048.0) + v57->z;
                v241.y = (float)(vec3_up.y * (float)-2048.0) + (float)v166;
                v241.x = (float)(vec3_up.x * (float)-2048.0) + (float)v167;
                idClip::TracePoint(
                  this: &clientGame->clip,
                  result: &v277,
                  start: v57,
                  end: &v241,
                  clipMask: 8462469,
                  passEntityNumber: v165);
                if ( v277.fraction < 1.0 )
                {
                  v243[0] = v277.endpos.x - (float)4.0;
                  v243[1] = v277.endpos.y;
                  v243[2] = v277.endpos.z;
                  HIDWORD(v170) = (int)(float)(v57->z - v277.endpos.z);
                  v171 = va::va(
                           this: &v281,
                           fmt: v134,
                           a3: v170,
                           a4: v169,
                           a5: v168,
                           a6: v193,
                           a7: v194,
                           a8: v195,
                           a9: v196,
                           a10: v197,
                           a11: v198);
                  ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                    a1: clientGame->renderWorld,
                    a2: v171,
                    a3: v243,
                    a4: clientGame->renderWorld->DebugText,
                    a5: v136,
                    a6: 1,
                    a7: 0,
                    a8: 0,
                    a9: 0.2);
                }
              }
            }
            if ( v234.len != 0 )
            {
              v172 = idEntity::GetPhysics(this: owner);
              v173 = v172->GetOrigin(this: v172, a2: 0);
              if ( (unsigned __int8)idBounds::ContainsPoint(this: &v274, p: v173) != 0
                || (*(_BYTE *)&owner->flags & 1) != 0 )
              {
                idEntityInterfaceObject::idEntityInterfaceObject(this: &v213, game: gameLocal, entity: owner);
                if ( v213.iface->IsValid(this: v213.iface) )
                {
                  v235.len = 0;
                  v235.baseBuffer[0] = 0;
                  v235.data = v235.baseBuffer;
                  v235.allocedAndFlag = 20;
                  if ( v236.len != 0 )
                  {
                    v251.ops = v229;
                    v251.path = v234.data;
                    v251.type = v236.data;
                    v174 = v213.iface->GetTypeInfoObject(this: v213.iface);
                    idTypeInfoObject::GetStrPtrType(this: v174, variable: &v251, s: &v235, resolvePtrs: false);
                  }
                  else
                  {
                    data = v234.data;
                    v176 = v213.iface->GetTypeInfoObject(this: v213.iface);
                    idTypeInfoObject::GetValueText(this: v176, path: data, text: &v235);
                  }
                  if ( v235.len != 0 && idStr::Icmp(s1: v235.data, s2: v218) != 0 )
                  {
                    v177 = idEntity::GetPhysics(this: owner);
                    v178 = (float *)v177->GetOrigin(this: v177, a2: 0);
                    v179 = v178[2];
                    v180 = v178[1];
                    v253[0] = *v178;
                    v253[1] = v180;
                    v253[2] = (float)v179 + v232;
                    ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                      a1: clientGame->renderWorld,
                      a2: v235.data,
                      a3: v253,
                      a4: clientGame->renderWorld->__vftable,
                      a5: &idColor::colorWhite,
                      a6: 1,
                      a7: 0,
                      a8: 0,
                      a9: v220);
                  }
                  idStr::FreeData(this: &v235);
                }
                if ( v231->valueInteger != 0 )
                {
                  v181 = gameLocal->MapFindEntity_2(this: gameLocal, a2: owner);
                  if ( v181 != nullptr )
                  {
                    p_layerList = &v181->layerList;
                    v183 = 0;
                    if ( v181->layerList.num > 0 )
                    {
                      v184 = 0;
                      do
                      {
                        idStr::idStr(this: &v279, text: &p_layerList->list[v184]);
                        v185 = idEntity::GetPhysics(this: owner);
                        LODWORD(v186) = v183;
                        HIDWORD(v186) = v185->__vftable;
                        v276 = v186;
                        v187 = (float)((float)v186 * (float)0.0);
                        v188 = (float)((float)v186 * (float)4.0);
                        v189 = (float *)(*(int (__fastcall **)(idPhysics *, _DWORD))(HIDWORD(v186) + 64))(
                                          a1: v185,
                                          a2: 0);
                        v190 = (float)(v189[2] - (float)14.0);
                        v191 = (float)(v189[1] - (float)v187);
                        v255[0] = *v189 - (float)v187;
                        v255[1] = v191;
                        v255[2] = (float)v190 - (float)v188;
                        ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                          a1: clientGame->renderWorld,
                          a2: v279.data,
                          a3: v255,
                          a4: clientGame->renderWorld->__vftable,
                          a5: &idColor::colorWhite,
                          a6: 1,
                          a7: 0,
                          a8: 0,
                          a9: 0.1);
                        idStr::FreeData(this: &v279);
                        ++v183;
                        ++v184;
                      }
                      while ( v183 < p_layerList->num );
                      v6 = v222;
                    }
                  }
                }
                idEntityInterfaceObject::~idEntityInterfaceObject(this: &v213);
              }
            }
          }
        }
LABEL_131:
        v192 = owner->spawnNode.next;
        if ( v192 != nullptr && v192 != owner->spawnNode.head )
        {
          owner = v192->owner;
          if ( owner != nullptr )
            continue;
        }
        break;
      }
    }
  }
  idStr::FreeData(this: &v211.textKey);
  idStr::FreeData(this: &v211.typeKey);
  idStr::FreeData(this: &v236);
LABEL_136:
  idStr::FreeData(this: &v234);
}


// ========================================================================
// __unwind$493405
// EA  : 0x82BE0468
// RVA : 0x00BE0468
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493405()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 384));
}


// ========================================================================
// __unwind$493406
// EA  : 0x82BE0490
// RVA : 0x00BE0490
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 448));
}


// ========================================================================
// __unwind$493407
// EA  : 0x82BE04B8
// RVA : 0x00BE04B8
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493407()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(v0 - 5792 + 160));
}


// ========================================================================
// __unwind$493408
// EA  : 0x82BE04E0
// RVA : 0x00BE04E0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493408()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 1104));
}


// ========================================================================
// __unwind$493410
// EA  : 0x82BE0508
// RVA : 0x00BE0508
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493410()
{
  int v0; // r12

  idEntityInterfaceObject::~idEntityInterfaceObject(this: (idEntityInterfaceObject *)(v0 - 5792 + 256));
}


// ========================================================================
// __unwind$493411
// EA  : 0x82BE0530
// RVA : 0x00BE0530
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493411()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 416));
}


// ========================================================================
// __unwind$493412
// EA  : 0x82BE0558
// RVA : 0x00BE0558
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_493412()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 1312));
}


// ========================================================================
// __unwind$495719
// EA  : 0x82BE0580
// RVA : 0x00BE0580
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_495719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5792 + 164));
}


// ========================================================================
// ?SelectEntity@idEditEntities@@QAA_NABVidVec3@@0PBVidEntity@@@Z
// EA  : 0x82BE05B0
// RVA : 0x00BE05B0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

BOOL __fastcall idEditEntities::SelectEntity(
        idEditEntities *this,
        const idVec3 *origin,
        const idVec3 *dir,
        const idEntity *skip)
{
  int GameMs; // r3
  idEntity *Entity; // r30
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  const char *data; // r28
  int entityNumber; // r24
  const char *Classname; // r3
  idPhysics *v19; // r3
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  float *v23; // r3
  double v24; // fp10
  double v25; // fp8
  double y; // fp7
  double v27; // fp6
  double z; // fp5
  idPhysics *Physics; // r3
  float *v30; // r3
  double v31; // fp7
  double v32; // fp6
  int v34; // [sp+8h] [-C8h]
  int v35; // [sp+Ch] [-C4h]
  int v36; // [sp+10h] [-C0h]
  int v37; // [sp+14h] [-BCh]
  int v38; // [sp+18h] [-B8h]
  idEntity *v39; // [sp+1Ch] [-B4h]
  float v40[4]; // [sp+50h] [-80h] BYREF
  idPlane v41; // [sp+60h] [-70h] BYREF

  this->dragging = false;
  if ( g_editEntityMode.valueInteger != 0 && this->selectableEntityClasses.num != 0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextSelectTime )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->lastSelectResult = false;
      this->nextSelectTime = GameMs + 300;
      Entity = idEditEntities::FindEntity(this, origin, dir, skip);
      idEditEntities::ClearSelectedEntities(this);
      if ( Entity != nullptr )
      {
        if ( (unsigned __int8)idEditEntities::EntityIsSelectable(
                                this,
                                ent: Entity,
                                color: nullptr,
                                text: nullptr,
                                type: nullptr) == 0 )
        {
LABEL_13:
          Entity->UpdateEditingDialog(this: Entity);
          return this->lastSelectResult;
        }
        idEditEntities::AddSelectedEntity(
          this,
          ent: Entity,
          a3: v15,
          a4: v14,
          a5: v13,
          a6: v12,
          a7: v11,
          a8: v10,
          a9: v34,
          a10: v35,
          a11: v36,
          a12: v37,
          a13: v38,
          a14: v39);
        data = Entity->name.data;
        entityNumber = Entity->entityNumber;
        Classname = idClass::GetClassname(this: Entity);
        idLib::Printf(fmt: "Selected Entity #%d: %s '^2%s^0'\n", entityNumber, Classname, data);
        if ( g_editEntityMouseDrag.valueInteger != 0 )
          this->dragging = true;
        this->dragTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( g_editEntityMouseDrag.valueInteger == 0 )
        {
          Physics = idEntity::GetPhysics(this: Entity);
          v30 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v31 = (float)(v30[1] - origin->y);
          v32 = (float)(v30[2] - origin->z);
          this->lastDragPos.x = *v30 - origin->x;
          this->lastDragPos.y = v31;
          this->lastDragPos.z = v32;
          goto LABEL_12;
        }
        v19 = idEntity::GetPhysics(this: Entity);
        v20 = -dir->x;
        v21 = -dir->y;
        v22 = -dir->z;
        v23 = (float *)v19->GetOrigin(this: v19, a2: 0);
        v24 = (float)(v23[1] * (float)v21);
        v41.a = v20;
        v41.b = v21;
        v41.c = v22;
        v41.d = -(float)((float)(*v23 * (float)v20) + (float)((float)(v23[2] * (float)v22) + (float)v24));
        v40[0] = 0.0;
        if ( (unsigned __int8)idPlane::RayIntersection(this: &v41, start: origin, dir, scale: v40) != 0 )
        {
          v25 = (float)(v40[0] * dir->y);
          y = origin->y;
          v27 = (float)(v40[0] * dir->z);
          z = origin->z;
          this->lastDragPos.x = origin->x + (float)(dir->x * v40[0]);
          this->lastDragPos.y = (float)y + (float)v25;
          this->lastDragPos.z = (float)z + (float)v27;
LABEL_12:
          this->lastSelectResult = true;
          this->dragAxis = -1;
          goto LABEL_13;
        }
        return false;
      }
      this->dragging = false;
      if ( (com_editors & 0x800) != 0 )
        common->UpdateTool(this: common, a2: EDITOR_PARTICLE);
    }
    return this->lastSelectResult;
  }
  return false;
}


// ========================================================================
// ?DuplicateSelected@idEditEntities@@QAAXABVidVec3@@0@Z
// EA  : 0x82BE08C0
// RVA : 0x00BE08C0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void __fastcall idEditEntities::DuplicateSelected(idEditEntities *this, const idVec3 *origin, const idVec3 *dir)
{
  int num; // r11
  int v7; // r3
  int v8; // r30
  int v9; // r27
  const char *v10; // r3
  const idDeclEntityDef *v11; // r27
  const char *v12; // r3
  idEntity *v13; // r3
  idEntity *v14; // r30
  double y; // fp6
  double x; // fp5
  double v17; // fp9
  double v18; // fp8
  idGameLocal *v19; // r3
  double v20; // fp10
  double v21; // fp9
  double z; // fp7
  double v23; // fp6
  void (__fastcall *MapAddEntity)(struct idGameLocal *, idEntity *); // r8
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r6
  int v30; // r5
  int v31; // [sp+8h] [-F8h]
  int v32; // [sp+Ch] [-F4h]
  int v33; // [sp+10h] [-F0h]
  int v34; // [sp+14h] [-ECh]
  int v35; // [sp+18h] [-E8h]
  idEntity *v36; // [sp+1Ch] [-E4h]
  idVec3 v37; // [sp+58h] [-A8h] BYREF
  idTypeInfoTree v38; // [sp+70h] [-90h] BYREF
  idStr v39[3]; // [sp+90h] [-70h] BYREF

  num = this->selectedEntities.num;
  this->dragging = false;
  if ( num != 0
    && cvarSystem->GetCVarInteger(this: cvarSystem, a2: "g_editEntityMode", a3: 0) != 4
    && *this->selectedEntities.list != nullptr )
  {
    v7 = ((int (__fastcall *)(idGameLocal *))gameLocal->MapFindEntity_2)(a1: gameLocal);
    if ( v7 != 0 )
    {
      v8 = *(_DWORD *)(v7 + 20);
      v9 = (*(int (__fastcall **)(int))(*(_DWORD *)v8 + 96))(a1: v8);
      v10 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v8 + 92))(a1: v8);
      idTypeInfoTree::idTypeInfoTree(this: &v38, text: v10, length: v9);
      v11 = idDeclInfoTemplate<idDeclEntityDef>::AllocDecl(this: &idDeclEntityDef::resourceList);
      if ( v11 != nullptr )
      {
        v12 = gameLocal->GetUniqueEntityName(this: gameLocal, a2: "speaker");
        idStr::idStr(this: v39, text: v12);
        v11->BuildText(this: v11, a2: "speaker", a3: "idSound");
        v11->SetInheritedClass(this: v11, a2: false);
        v11->SetEntityState_2(this: v11, a2: &v38, a3: true, a4: false);
        v13 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v11, a3: -1, a4: -1, a5: -1);
        v14 = v13;
        if ( v13 != nullptr )
        {
          idEntity::SetName(this: v13, newName: v39[0].data);
          y = origin->y;
          x = origin->x;
          v17 = (float)(dir->y * g_editEntityCloneDist.valueFloat);
          v18 = (float)(dir->x * g_editEntityCloneDist.valueFloat);
          v37.z = origin->z + (float)(dir->z * g_editEntityCloneDist.valueFloat);
          v37.y = (float)y + (float)v17;
          v37.x = (float)x + (float)v18;
          idEntity::SetOrigin(this: v14, org: &v37);
          v19 = gameLocal;
          v20 = (float)(dir->z * g_editEntityCloneDist.valueFloat);
          v21 = (float)(dir->y * g_editEntityCloneDist.valueFloat);
          z = origin->z;
          v23 = origin->y;
          MapAddEntity = gameLocal->MapAddEntity;
          v14->spawnPosition.x = origin->x + (float)(dir->x * g_editEntityCloneDist.valueFloat);
          v14->spawnPosition.z = (float)z + (float)v20;
          v14->spawnPosition.y = (float)v23 + (float)v21;
          MapAddEntity(this: v19, a2: v14);
          gameLocal->ClearEntitySelection(this: gameLocal);
          idEditEntities::AddSelectedEntity(
            this,
            ent: v14,
            a3: v30,
            a4: v29,
            a5: v28,
            a6: v27,
            a7: v26,
            a8: v25,
            a9: v31,
            a10: v32,
            a11: v33,
            a12: v34,
            a13: v35,
            a14: v36);
          v14->ShowEditingDialog(this: v14);
        }
        else
        {
          idLib::Warning(fmt: "Couldn't create entity!");
        }
        ((void (__fastcall *)(const idDeclEntityDef *, int))v11->dtr_idResource)(a1: v11, a2: 1);
        idStr::FreeData(this: v39);
        idTypeInfoTree::~idTypeInfoTree(this: &v38);
      }
      else
      {
        idLib::Warning(fmt: "Could not allocate entity def!");
        idTypeInfoTree::~idTypeInfoTree(this: &v38);
      }
    }
    else
    {
      idLib::Warning(fmt: "Couldn't find entity in map file!");
    }
  }
}


// ========================================================================
// __unwind$495980
// EA  : 0x82BE0BB0
// RVA : 0x00BE0BB0
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_495980()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$495981
// EA  : 0x82BE0BD8
// RVA : 0x00BE0BD8
// PDB : w:\tech5\tungsten\game\editor\gameedit.cpp
// ========================================================================

void _unwind_495981()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}

