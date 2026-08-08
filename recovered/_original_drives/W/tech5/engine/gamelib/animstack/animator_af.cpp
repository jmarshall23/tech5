
// ========================================================================
// ?InternalGetMergeBranch@idAnimator_AF@@MBAPBVidMD6Branch@@XZ
// EA  : 0x826C8FB0
// RVA : 0x006C8FB0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_AF::InternalGetMergeBranch(idAnimator_AF *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?GetName@idAnimatedEntityPhysicsCallbacksFake@@UAAPBDXZ
// EA  : 0x826C9670
// RVA : 0x006C9670
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

const char *__fastcall idAnimatedEntityPhysicsCallbacksFake::GetName(idAnimatedEntityPhysicsCallbacksFake *this)
{
  return "fakeAFCB";
}


// ========================================================================
// ?ActivatePhysics@idAnimatedEntityPhysicsCallbacksFake@@UAAXH@Z
// EA  : 0x826C9680
// RVA : 0x006C9680
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacksFake::ActivatePhysics(
        idAnimatedEntityPhysicsCallbacksFake *this,
        int physId)
{
  idAnimator_AF *af; // r11

  af = this->af;
  if ( af != nullptr )
    ((void (__fastcall *)(idPhysics_AF *, int))af->physicsObj.Activate)(a1: &af->physicsObj, a2: physId);
}


// ========================================================================
// ?DeactivatePhysics@idAnimatedEntityPhysicsCallbacksFake@@UAAXH@Z
// EA  : 0x826C96A8
// RVA : 0x006C96A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimatedEntityPhysicsCallbacksFake::DeactivatePhysics(
        idAnimatedEntityPhysicsCallbacksFake *this,
        int physId)
{
  idAnimator_AF *af; // r11

  af = this->af;
  if ( af != nullptr )
    ((void (__fastcall *)(idPhysics_AF *, int))af->physicsObj.PutToRest)(a1: &af->physicsObj, a2: physId);
}


// ========================================================================
// `idAnimator_AF::InitAF'::`39'::local_t::GetJointTransform
// EA  : 0x826C9728
// RVA : 0x006C9728
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall _idAnimator_AF::InitAF_::_39_::local_t::GetJointTransform(
        idIndex<short,enum invalidJointIndex_t> *model,
        const idJointMat *frame,
        const char *jointName,
        idVec3 *origin,
        idMat3 *axis)
{
  const idJointMat *v9; // r11
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  double v19; // fp4
  __int16 v20; // [sp+50h] [-30h] BYREF

  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v20, result: model, jointName);
  if ( v20 == NULL_JOINT_INDEX.value )
    return 0;
  v9 = &frame[v20];
  v10 = v9->mat[7];
  v11 = v9->mat[11];
  origin->x = v9->mat[3];
  origin->y = v10;
  origin->z = v11;
  v12 = v9->mat[10];
  v13 = v9->mat[6];
  v14 = v9->mat[2];
  v15 = v9->mat[9];
  v16 = v9->mat[5];
  v17 = v9->mat[1];
  v18 = v9->mat[8];
  v19 = v9->mat[4];
  axis->mat[0].x = v9->mat[0];
  axis->mat[1].x = v17;
  axis->mat[0].y = v19;
  axis->mat[0].z = v18;
  axis->mat[1].y = v16;
  axis->mat[1].z = v15;
  axis->mat[2].x = v14;
  axis->mat[2].y = v13;
  axis->mat[2].z = v12;
  return 1;
}


// ========================================================================
// ?GetBounds@idAnimator_AF@@IBA?AVidBounds@@XZ
// EA  : 0x826C9848
// RVA : 0x006C9848
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

idAnimator_AF *__fastcall idAnimator_AF::GetBounds(idAnimator_AF *this, idBounds *result)
{
  float x; // r11
  float *v5; // r10
  int v6; // r11
  char *v7; // r10
  _DWORD *v8; // r11
  int i; // ctr
  idBounds *v10; // r30
  int v11; // r3
  char *v12; // r10
  _DWORD *v13; // r11
  int j; // ctr
  float *v15; // r3
  double y; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp9
  float v21; // r8
  double z; // fp8
  float v23; // r7
  double v24; // fp7
  float v25; // r6
  double v26; // fp6
  float *v27; // r3
  double v28; // fp13
  double v29; // fp1
  double v30; // fp0
  double v31; // fp31
  double v32; // fp5
  double v33; // fp4
  double v34; // fp6
  double v35; // fp10
  double v36; // fp9
  double v37; // fp11
  double v38; // fp12
  double v39; // fp31
  double v40; // fp29
  double v41; // fp30
  float v42; // r11
  int v43; // r28
  int v44; // r30
  idAFBody *Body; // r3
  float *clipModel; // r11
  idAFBody *v47; // r26
  double v48; // fp3
  double v49; // fp11
  double v50; // fp8
  double v55; // fp9
  float v65; // [sp+50h] [-170h]
  float v66; // [sp+50h] [-170h]
  float v67; // [sp+54h] [-16Ch]
  float v68; // [sp+54h] [-16Ch]
  float v69; // [sp+58h] [-168h]
  float v70; // [sp+58h] [-168h]
  char v71; // [sp+5Ch] [-164h] BYREF
  idMat3 v72; // [sp+60h] [-160h] BYREF
  idVec3 v73; // [sp+88h] [-138h] BYREF
  idBounds v74; // [sp+A0h] [-120h] BYREF
  idMat3 v75; // [sp+C0h] [-100h] BYREF
  char v76; // [sp+ECh] [-D4h] BYREF
  idMat3 v77; // [sp+F0h] [-D0h] BYREF
  idMat3 v78[2]; // [sp+120h] [-A0h] BYREF

  *(float *)&this->weightGroup = 1.0e30;
  *(float *)&this->gametimeManager.gameTimeManager = 1.0e30;
  *(float *)&this->__vftable = 1.0e30;
  *(float *)&this->serializeProps.serializedTrees[1] = -1.0e30;
  *(float *)this->serializeProps.serializedTrees = -1.0e30;
  *(float *)&this->filterGroup = -1.0e30;
  x = result[4].b[1].x;
  v5 = (float *)(LODWORD(x) + 24);
  if ( *(_BYTE *)(LODWORD(x) + 72) == 0 )
    v5 = (float *)(LODWORD(x) + 116);
  v65 = *v5;
  v67 = v5[1];
  v69 = v5[2];
  if ( *(_BYTE *)(LODWORD(x) + 72) != 0 )
    v6 = LODWORD(x) + 36;
  else
    v6 = LODWORD(x) + 128;
  v7 = &v71;
  v8 = (_DWORD *)(v6 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v8;
    v7 += 4;
    *(_DWORD *)v7 = *v8;
  }
  if ( HIBYTE(result[11].b[0].x) != 0 )
  {
    v10 = result + 12;
    v11 = (*(int (__fastcall **)(idBounds *, _DWORD))(LODWORD(result[12].b[0].x) + 68))(a1: result + 12, a2: 0);
    v12 = &v76;
    v13 = (_DWORD *)(v11 - 4);
    for ( j = 9; j != 0; --j )
    {
      ++v13;
      v12 += 4;
      *(_DWORD *)v12 = *v13;
    }
    v15 = (float *)(*(int (__fastcall **)(idBounds *, _DWORD))(LODWORD(v10->b[0].x) + 64))(a1: result + 12, a2: 0);
    y = result[6].b[0].y;
    v17 = result[5].b[1].y;
    v18 = result[6].b[1].x;
    v19 = result[6].b[0].x;
    v20 = result[5].b[1].x;
    v21 = *v15;
    z = result[6].b[0].z;
    v23 = v15[1];
    v24 = result[5].b[1].z;
    v25 = v15[2];
    v26 = result[5].b[0].z;
    v75.mat[2].z = result[6].b[1].y;
    v75.mat[2].y = y;
    v66 = v21;
    v75.mat[2].x = v17;
    v68 = v23;
    v75.mat[1].z = v18;
    v70 = v25;
    v75.mat[1].y = v19;
    v75.mat[1].x = v20;
    v75.mat[0].z = z;
    v75.mat[0].y = v24;
    v75.mat[0].x = v26;
    v27 = (float *)idMat3::operator*(this: v78, result: &v75, a: &v77);
    v28 = v27[6];
    v29 = (float)(result[5].b[0].y * v27[8]);
    v30 = v27[7];
    v31 = (float)(result[5].b[0].y * v27[6]);
    v32 = (float)(result[5].b[0].y * v27[7]);
    v33 = result[4].b[1].z;
    v34 = *v27;
    v35 = v27[2];
    v36 = v27[1];
    v72.mat[2].z = v27[8];
    v72.mat[0].x = v34;
    v37 = v27[3];
    v38 = v27[5];
    v40 = (float)(v66
                - (float)((float)(result[5].b[0].x * v27[3]) + (float)((float)((float)v33 * (float)v34) + (float)v31)));
    v39 = (float)(v70
                - (float)((float)(result[5].b[0].x * v27[5]) + (float)((float)((float)v33 * (float)v35) + (float)v29)));
    v41 = (float)(v68
                - (float)((float)(result[5].b[0].x * v27[4]) + (float)((float)((float)v33 * (float)v36) + (float)v32)));
    v72.mat[1].y = v27[4];
  }
  else
  {
    v39 = v69;
    v41 = v67;
    v40 = v65;
    v30 = v72.mat[2].y;
    v28 = v72.mat[2].x;
    v38 = v72.mat[1].z;
    v37 = v72.mat[1].x;
    v35 = v72.mat[0].z;
    v36 = v72.mat[0].y;
  }
  v42 = result[7].b[0].x;
  v72.mat[0].y = v37;
  v72.mat[0].z = v28;
  v43 = 0;
  v72.mat[1].z = v30;
  v72.mat[1].x = v36;
  v72.mat[2].x = v35;
  v72.mat[2].y = v38;
  if ( SLODWORD(v42) > 0 )
  {
    v44 = 0;
    do
    {
      Body = idPhysics_AF::GetBody(this: (idPhysics_AF *)&result[12], id: *(_DWORD *)(LODWORD(result[6].b[1].z) + v44));
      clipModel = (float *)Body->clipModel;
      v47 = Body;
      v48 = (float)(clipModel[8] - (float)v40);
      v49 = (float)((float)((float)(clipModel[9] - (float)v41) * v72.mat[1].x)
                  + (float)((float)(clipModel[10] - (float)v39) * v72.mat[2].x));
      v50 = (float)((float)(v72.mat[0].z * (float)(clipModel[8] - (float)v40))
                  + (float)((float)((float)(clipModel[9] - (float)v41) * v72.mat[1].z)
                          + (float)((float)(clipModel[10] - (float)v39) * v72.mat[2].z)));
      v73.y = (float)(v72.mat[0].y * (float)(clipModel[8] - (float)v40))
            + (float)((float)((float)(clipModel[9] - (float)v41) * v72.mat[1].y)
                    + (float)((float)(clipModel[10] - (float)v39) * v72.mat[2].y));
      v73.z = v50;
      v73.x = (float)((float)v48 * v72.mat[0].x) + (float)v49;
      idMat3::operator*(this: &v77, result: &Body->clipModel->axis, a: &v72);
      idBounds::FromTransformedBounds(this: &v74, bounds: &v47->clipModel->bounds, origin: &v73, axis: &v77);
      ++v43;
      _FP4 = (float)(*(float *)&this->__vftable - v74.b[0].x);
      v44 += 60;
      _FP8 = (float)(*(float *)&this->weightGroup - v74.b[0].z);
      _FP2 = (float)(*(float *)&this->gametimeManager.gameTimeManager - v74.b[0].y);
      _FP28 = (float)(v74.b[1].x - *(float *)&this->filterGroup);
      v55 = v74.b[1].z;
      _FP26 = (float)(v74.b[1].y - *(float *)this->serializeProps.serializedTrees);
      __asm { fsel      f6, f4, f0, f6 }
      *(float *)&this->__vftable = _FP6;
      __asm { fsel      f4, f8, f12, f3 }
      *(float *)&this->weightGroup = _FP4;
      __asm { fsel      f5, f2, f13, f5 }
      *(float *)&this->gametimeManager.gameTimeManager = _FP5;
      __asm { fsel      f3, f28, f11, f1 }
      *(float *)&this->filterGroup = _FP3;
      __asm { fsel      f2, f26, f10, f7 }
      _FP25 = (float)((float)v55 - *(float *)&this->serializeProps.serializedTrees[1]);
      *(float *)this->serializeProps.serializedTrees = _FP2;
      __asm { fsel      f1, f25, f9, f27 }
      *(float *)&this->serializeProps.serializedTrees[1] = _FP1;
    }
    while ( v43 < SLODWORD(result[7].b[0].x) );
  }
  return this;
}


// ========================================================================
// ?SetJointVelocities@idAnimator_AF@@IAAXABVidVec3@@@Z
// EA  : 0x826C9BE8
// RVA : 0x006C9BE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::SetJointVelocities(idAnimator_AF *this, const idVec3 *originVel)
{
  double v4; // fp13
  double x; // fp1
  double z; // fp3
  idRenderWorld *v7; // r3
  idTreeAnimator *treeAnimator; // r11
  float *p_x; // r10
  double v10; // fp0
  idRenderModelParms *p_deferredOrigin; // r5
  double v12; // fp10
  double v13; // fp9
  idTreeAnimator *v14; // r11
  float *p_deferredAxis; // r30
  idGame *v16; // r3
  double v17; // fp31
  int v18; // r12
  int v19; // r12
  int num; // r5
  const idIndex<short,enum invalidJointIndex_t> *v21; // r4
  int v22; // r11
  int v23; // r12
  int v24; // r10
  const idIndex<short,enum invalidJointIndex_t> *v25; // r9
  idAnimator_AF::idAFJointMod *v26; // r8
  int v27; // r26
  int v28; // r27
  float *v29; // r28
  idAFBody *Body; // r3
  double v31; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp30
  double v35; // fp9
  double v36; // fp8
  _DWORD back_chain[6]; // [sp+0h] [-C0h]
  double v38; // [sp+18h] [-A8h]
  double y; // [sp+20h] [-A0h]
  double v40; // [sp+28h] [-98h]
  double v41; // [sp+30h] [-90h]
  int v42; // [sp+4Ch] [-74h] BYREF
  idMat3 v43[3]; // [sp+50h] [-70h] BYREF

  if ( af_debugStartVelocity.valueInteger != 0 )
  {
    v4 = (float)(originVel->y * originVel->y);
    x = originVel->x;
    z = originVel->z;
    y = originVel->y;
    v40 = z;
    v38 = x;
    v41 = __fsqrts((float)((float)((float)z * (float)z) + (float)((float)((float)x * (float)x) + (float)v4)));
    idLib::Printf(fmt: (const char *)HIDWORD(x), LODWORD(x), LODWORD(y), HIDWORD(v41), LODWORD(v41));
    v7 = common->RW(this: common);
    treeAnimator = this->treeAnimator;
    p_x = &treeAnimator->deferredOrigin.x;
    v10 = (float)(originVel->z * (float)50.0);
    if ( !treeAnimator->useDeferredPosition )
      p_x = &treeAnimator->g.origin.x;
    p_deferredOrigin = (idRenderModelParms *)&treeAnimator->deferredOrigin;
    v12 = p_x[2];
    v13 = (float)(p_x[1] + (float)(originVel->y * (float)50.0));
    v43[0].mat[0].z = *p_x + (float)(originVel->x * (float)50.0);
    v43[0].mat[1].x = v13;
    v43[0].mat[1].y = (float)v12 + (float)v10;
    if ( !treeAnimator->useDeferredPosition )
      p_deferredOrigin = &treeAnimator->g;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idRenderModelParms *, float *, double))v7->DebugArrow)(
      a1: v7,
      a2: &idColor::colorRed,
      a3: p_deferredOrigin,
      a4: &v43[0].mat[0].z,
      a5: 8.0);
  }
  v14 = this->treeAnimator;
  p_deferredAxis = (float *)&v14->deferredAxis;
  if ( !v14->useDeferredPosition )
    p_deferredAxis = (float *)&v14->g.axis;
  v16 = common->Game(this: common);
  *(_QWORD *)&v43[0].mat[0].x = __PAIR64__(&unk_82390000, v16->GetGameMsPerFrame(this: v16, a2: GAMETIME_SCALED));
  v17 = (float)((float)1.0 / (float)((float)*(__int64 *)&v43[0].mat[0].x * (float)0.001));
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v18) = back_chain[0];
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v19) = back_chain[0];
  ((void (*)(void))RtlCheckStack12)();
  v22 = 0;
  *(_DWORD *)((char *)back_chain + v23) = back_chain[0];
  if ( num > 0 )
  {
    v24 = 0;
    v25 = v21 - 1;
    do
    {
      ++v22;
      v26 = &this->jointMods.list[v24++];
      ++v25;
      v25->value = (__int16)v26->jointIndex;
      num = this->jointMods.num;
    }
    while ( v22 < num );
  }
  idTreeAnimator::GetModelSpaceJointFrameDeltas(
    this: this->treeAnimator,
    indices: v21,
    numIndices: num,
    transDeltas: v43[0].mat,
    rotDeltas: v43);
  v27 = 0;
  if ( this->jointMods.num > 0 )
  {
    v28 = 0;
    v29 = (float *)&v42;
    do
    {
      Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: this->jointMods.list[v28].bodyId);
      ++v27;
      v31 = (float)(v29[1] * (float)v17);
      v32 = (float)(v29[2] * (float)v17);
      ++v28;
      v33 = originVel->x;
      v34 = originVel->z;
      v29 += 3;
      v35 = (float)((float)((float)(*v29 * (float)v17) * p_deferredAxis[6])
                  + (float)((float)(*p_deferredAxis * (float)v31) + (float)(p_deferredAxis[3] * (float)v32)));
      v36 = (float)((float)(p_deferredAxis[5] * (float)v32)
                  + (float)((float)((float)(*v29 * (float)v17) * p_deferredAxis[8])
                          + (float)((float)v31 * p_deferredAxis[2])));
      Body->current.spatialVelocity.p[1] = originVel->y
                                         + (float)((float)(p_deferredAxis[4] * (float)v32)
                                                 + (float)((float)(p_deferredAxis[7] * (float)(*v29 * (float)v17))
                                                         + (float)(p_deferredAxis[1] * (float)v31)));
      Body->current.spatialVelocity.p[0] = (float)v33 + (float)v35;
      Body->current.spatialVelocity.p[2] = (float)v34 + (float)v36;
    }
    while ( v27 < this->jointMods.num );
  }
}


// ========================================================================
// ?BodyForJoint@idAnimator_AF@@QBAHV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x826C9F48
// RVA : 0x006C9F48
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::BodyForJoint(idAnimator_AF *this, idIndex<short,enum invalidJointIndex_t> *joint)
{
  if ( (__int16)joint == -1 || (__int16)joint >= this->jointBody.num )
    return 0;
  else
    return this->jointBody.list[(__int16)joint];
}


// ========================================================================
// ?GetModelTransform@idAnimator_AF@@QBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x826C9F78
// RVA : 0x006C9F78
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::GetModelTransform(idAnimator_AF *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  struct idPhysics_AF *p_physicsObj; // r28
  double z; // fp0
  double v8; // fp13
  double v9; // fp12
  double y; // fp11
  double v11; // fp9
  double x; // fp8
  double v13; // fp7
  double v14; // fp6
  const idMat3 *(__fastcall *GetAxis)(struct idPhysics_AF *, int); // ctr
  const idMat3 *v16; // r3
  float *v17; // r3
  double v18; // fp31
  double v19; // fp30
  double v20; // fp29
  const idVec3 *v21; // r3
  double v22; // fp13
  double v23; // fp12
  idMat3 v24; // [sp+50h] [-A0h] BYREF
  idMat3 v25; // [sp+80h] [-70h] BYREF

  if ( this->modifiesOrigin )
  {
    p_physicsObj = &this->physicsObj;
    z = this->baseAxis.mat[2].z;
    v8 = this->baseAxis.mat[1].z;
    v9 = this->baseAxis.mat[0].z;
    y = this->baseAxis.mat[2].y;
    v11 = this->baseAxis.mat[0].y;
    x = this->baseAxis.mat[2].x;
    v13 = this->baseAxis.mat[1].x;
    v14 = this->baseAxis.mat[0].x;
    GetAxis = this->physicsObj.GetAxis;
    v24.mat[1].y = this->baseAxis.mat[1].y;
    v24.mat[1].x = v11;
    v24.mat[0].z = x;
    v24.mat[0].y = v13;
    v24.mat[0].x = v14;
    v24.mat[1].z = y;
    v24.mat[2].x = v9;
    v24.mat[2].y = v8;
    v24.mat[2].z = z;
    v16 = GetAxis(this: &this->physicsObj, a2: 0);
    *modelAxis = *idMat3::operator*(this: &v25, result: &v24, a: v16);
    v17 = (float *)this->physicsObj.GetAxis(this: p_physicsObj, a2: 0);
    v18 = (float)((float)(this->baseOrigin.x * *v17)
                + (float)((float)(v17[3] * this->baseOrigin.y) + (float)(v17[6] * this->baseOrigin.z)));
    v19 = (float)((float)(v17[7] * this->baseOrigin.z)
                + (float)((float)(v17[1] * this->baseOrigin.x) + (float)(v17[4] * this->baseOrigin.y)));
    v20 = (float)((float)(v17[8] * this->baseOrigin.z)
                + (float)((float)(v17[2] * this->baseOrigin.x) + (float)(v17[5] * this->baseOrigin.y)));
    v21 = this->physicsObj.GetOrigin(this: p_physicsObj, a2: 0);
    v22 = (float)(v21->y - (float)v19);
    v23 = (float)(v21->z - (float)v20);
    modelOrigin->x = v21->x - (float)v18;
    modelOrigin->y = v22;
    modelOrigin->z = v23;
  }
  else
  {
    *modelAxis = this->lastRenderModelAxis;
    *modelOrigin = this->lastRenderModelOrigin;
  }
}


// ========================================================================
// ?Start@idAnimator_AF@@QAAXXZ
// EA  : 0x826CA198
// RVA : 0x006CA198
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::Start(idAnimator_AF *this)
{
  idTreeAnimator *treeAnimator; // r11
  idVec3 *p_deferredOrigin; // r11
  idTreeAnimator *v4; // r11
  idMat3 *p_deferredAxis; // r11

  if ( this->isLoaded )
  {
    treeAnimator = this->treeAnimator;
    if ( treeAnimator->useDeferredPosition )
      p_deferredOrigin = &treeAnimator->deferredOrigin;
    else
      p_deferredOrigin = &treeAnimator->g.origin;
    this->lastRenderModelOrigin = *p_deferredOrigin;
    v4 = this->treeAnimator;
    if ( v4->useDeferredPosition )
      p_deferredAxis = &v4->deferredAxis;
    else
      p_deferredAxis = &v4->g.axis;
    this->lastRenderModelAxis = *p_deferredAxis;
    *((_BYTE *)&this->treeAnimator->g + 107) |= 0x40u;
    this->physicsObj.EnableClip(this: &this->physicsObj);
    this->physicsObj.Activate(this: &this->physicsObj);
    this->isRunningPhysics = true;
    this->isActive = true;
  }
}


// ========================================================================
// ?Stop@idAnimator_AF@@QAAXXZ
// EA  : 0x826CA2B8
// RVA : 0x006CA2B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::Stop(idAnimator_AF *this)
{
  idPhysics_AF *p_physicsObj; // r30
  BOOL isSyncing; // r9
  double valueFloat; // fp0
  double v5; // fp0
  double v6; // fp0
  double v7; // fp0
  double v8; // fp0
  double v9; // fp0
  double v10; // fp0

  p_physicsObj = &this->physicsObj;
  this->physicsObj.UnlinkClip(this: &this->physicsObj);
  isSyncing = this->isSyncing;
  this->isRunningPhysics = false;
  this->isActive = false;
  if ( isSyncing )
  {
    this->isSyncing = false;
    p_physicsObj->SetGravity(this: p_physicsObj, a2: &this->gravityBeforeSync);
    this->physicsObj.addContactConstraints = true;
    valueFloat = af_errorReduction.valueFloat;
    this->physicsObj.errorReduction.startValue = af_errorReduction.valueFloat;
    this->physicsObj.errorReduction.endValue = valueFloat;
    v5 = af_errorReductionMax.valueFloat;
    this->physicsObj.errorReductionMax.startValue = af_errorReductionMax.valueFloat;
    this->physicsObj.errorReductionMax.endValue = v5;
    this->physicsObj.lcpEpsilon.startValue = 0.001;
    this->physicsObj.lcpEpsilon.endValue = 0.001;
    v6 = af_limitErrorReduction.valueFloat;
    this->physicsObj.limitErrorReduction.startValue = af_limitErrorReduction.valueFloat;
    this->physicsObj.limitErrorReduction.endValue = v6;
    v7 = af_limitErrorReductionMax.valueFloat;
    this->physicsObj.limitErrorReductionMax.startValue = af_limitErrorReductionMax.valueFloat;
    this->physicsObj.limitErrorReductionMax.endValue = v7;
    v8 = af_universalErrorReduction.valueFloat;
    this->physicsObj.universalErrorReduction.startValue = af_universalErrorReduction.valueFloat;
    this->physicsObj.universalErrorReduction.endValue = v8;
    v9 = af_universalErrorReductionMax.valueFloat;
    this->physicsObj.universalErrorReductionMax.startValue = af_universalErrorReductionMax.valueFloat;
    this->physicsObj.universalErrorReductionMax.endValue = v9;
    v10 = af_universalTorsionLcpEpsilon.valueFloat;
    this->physicsObj.universalTorsionLcpEpsilon.startValue = af_universalTorsionLcpEpsilon.valueFloat;
    this->physicsObj.universalTorsionLcpEpsilon.endValue = v10;
  }
}


// ========================================================================
// ?AddBindConstraints@idAnimator_AF@@QAAXXZ
// EA  : 0x826CA3E0
// RVA : 0x006CA3E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::AddBindConstraints(idAnimator_AF *this)
{
  idTreeAnimator *treeAnimator; // r11
  idRenderModelParms *p_deferredOrigin; // r10
  float y; // r8
  float z; // r7
  BOOL useDeferredPosition; // r6
  idMat3 *p_deferredAxis; // r11
  int *v8; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPhysics_AF *p_physicsObj; // r29
  const idMat3 *v12; // r3
  int *v13; // r10
  _DWORD *v14; // r11
  int j; // ctr
  const idVec3 *v16; // r3
  double v17; // fp13
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp9
  float v22; // r7
  double v23; // fp8
  float v24; // r6
  double v25; // fp7
  float v26; // r11
  double v27; // fp6
  float *v28; // r3
  double v29; // fp29
  double v30; // fp30
  double v31; // fp25
  double v32; // fp23
  double v33; // fp24
  double v34; // fp28
  double v35; // fp26
  double v36; // fp27
  double v37; // fp22
  double v38; // fp20
  double v39; // fp21
  double v40; // fp19
  int v41; // r21
  int v42; // r28
  idAFBody *Body; // r3
  idAnimator_AF::idBindConstraint *list; // r11
  idAFBody *v45; // r29
  unsigned int type; // r4
  idAFConstraint_UniversalJoint *v47; // r3
  idAFConstraint_UniversalJoint *v48; // r29
  idJointMat *v49; // r11
  double v50; // fp4
  double v51; // fp3
  idAFConstraint_BallAndSocketJoint *v52; // r3
  idAFConstraint_BallAndSocketJoint *v53; // r29
  idJointMat *v54; // r11
  double v55; // fp4
  double v56; // fp3
  idAFConstraint_Fixed *v57; // r3
  idAFConstraint_Fixed *v58; // r4
  __int16 v59; // [sp+54h] [-1CCh] BYREF
  __int16 v60; // [sp+56h] [-1CAh] BYREF
  float x; // [sp+58h] [-1C8h]
  float v62; // [sp+5Ch] [-1C4h]
  float v63; // [sp+60h] [-1C0h]
  int v64; // [sp+6Ch] [-1B4h] BYREF
  idMat3 v65; // [sp+70h] [-1B0h] BYREF
  idVec3 v66; // [sp+98h] [-188h] BYREF
  idVec3 v67; // [sp+A8h] [-178h] BYREF
  idVec3 v68; // [sp+B8h] [-168h] BYREF
  idVec3 v69; // [sp+C8h] [-158h] BYREF
  int v70; // [sp+DCh] [-144h] BYREF
  idMat3 v71; // [sp+E0h] [-140h] BYREF
  idMat3 v72[4]; // [sp+110h] [-110h] BYREF

  if ( this->isLoaded )
  {
    treeAnimator = this->treeAnimator;
    p_deferredOrigin = (idRenderModelParms *)&treeAnimator->deferredOrigin;
    if ( !treeAnimator->useDeferredPosition )
      p_deferredOrigin = &treeAnimator->g;
    y = p_deferredOrigin->origin.y;
    z = p_deferredOrigin->origin.z;
    useDeferredPosition = treeAnimator->useDeferredPosition;
    x = p_deferredOrigin->origin.x;
    v62 = y;
    v63 = z;
    if ( useDeferredPosition )
      p_deferredAxis = &treeAnimator->deferredAxis;
    else
      p_deferredAxis = &treeAnimator->g.axis;
    v8 = &v64;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++v8 = *++p_z;
    if ( this->modifiesOrigin )
    {
      p_physicsObj = &this->physicsObj;
      v12 = this->physicsObj.GetAxis(this: &this->physicsObj, a2: 0);
      v13 = &v70;
      v14 = (_DWORD *)&v12[-1].mat[2].z;
      for ( j = 9; j != 0; --j )
        *++v13 = *++v14;
      v16 = p_physicsObj->GetOrigin(this: &this->physicsObj, a2: 0);
      v17 = this->baseAxis.mat[1].z;
      v18 = this->baseAxis.mat[0].z;
      v19 = this->baseAxis.mat[2].y;
      v20 = this->baseAxis.mat[1].y;
      v21 = this->baseAxis.mat[0].y;
      v22 = v16->x;
      v23 = this->baseAxis.mat[2].x;
      v24 = v16->y;
      v25 = this->baseAxis.mat[1].x;
      v26 = v16->z;
      v27 = this->baseAxis.mat[0].x;
      v65.mat[2].z = this->baseAxis.mat[2].z;
      v65.mat[2].y = v17;
      x = v22;
      v65.mat[2].x = v18;
      v62 = v24;
      v65.mat[1].z = v19;
      v63 = v26;
      v65.mat[1].y = v20;
      v65.mat[1].x = v21;
      v65.mat[0].z = v23;
      v65.mat[0].y = v25;
      v65.mat[0].x = v27;
      v28 = (float *)idMat3::operator*(this: v72, result: &v65, a: &v71);
      v29 = v28[7];
      v30 = v28[8];
      v31 = v28[3];
      v32 = v28[1];
      v33 = v28[2];
      v34 = v28[6];
      v35 = v28[4];
      v36 = v28[5];
      v37 = *v28;
      v38 = (float)(v62
                  - (float)((float)(this->baseOrigin.y * v28[4])
                          + (float)((float)(this->baseOrigin.x * v28[1]) + (float)(this->baseOrigin.z * v28[7]))));
      v39 = (float)(v63
                  - (float)((float)(this->baseOrigin.y * v28[5])
                          + (float)((float)(this->baseOrigin.x * v28[2]) + (float)(this->baseOrigin.z * v28[8]))));
      v40 = (float)(x
                  - (float)((float)(this->baseOrigin.x * *v28)
                          + (float)((float)(this->baseOrigin.z * v28[6]) + (float)(this->baseOrigin.y * v28[3]))));
    }
    else
    {
      v39 = v63;
      v38 = v62;
      v40 = x;
      v30 = v65.mat[2].z;
      v29 = v65.mat[2].y;
      v34 = v65.mat[2].x;
      v36 = v65.mat[1].z;
      v35 = v65.mat[1].y;
      v31 = v65.mat[1].x;
      v33 = v65.mat[0].z;
      v32 = v65.mat[0].y;
      v37 = v65.mat[0].x;
    }
    v41 = 0;
    if ( this->bindConstraints.num > 0 )
    {
      v42 = 0;
      do
      {
        Body = idPhysics_AF::GetBody(this: &this->physicsObj, bodyName: this->bindConstraints.list[v42].bodyName.data);
        list = this->bindConstraints.list;
        v45 = Body;
        if ( Body != nullptr )
        {
          type = list[v42].type;
          if ( type != 0 )
          {
            if ( type == 1 )
            {
              v52 = (idAFConstraint_BallAndSocketJoint *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                           size: 0x200u,
                                                           tag: TAG_AF,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
              if ( v52 != nullptr )
                v53 = idAFConstraint_BallAndSocketJoint::idAFConstraint_BallAndSocketJoint(
                        this: v52,
                        name: this->bindConstraints.list[v42].name.data,
                        body1: v45,
                        body2: nullptr);
              else
                v53 = nullptr;
              idPhysics_AF::AddConstraint(this: &this->physicsObj, constraint: v53);
              idTreeAnimator::GetJointIndex(
                this: (idTreeAnimator *)&v59,
                result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                jointName: this->bindConstraints.list[v42].jointName.data);
              if ( v59 < 0 )
                idLib::Warning(
                  fmt: "idAnimator_AF::AddBindConstraints: joint '%s' not found",
                  this->bindConstraints.list[v42].jointName.data);
              v54 = &this->treeAnimator->joints[1][v59];
              v55 = (float)((float)(v54->mat[11] * (float)v29)
                          + (float)((float)((float)v32 * v54->mat[3]) + (float)(v54->mat[7] * (float)v35)));
              v56 = (float)((float)(v54->mat[11] * (float)v30)
                          + (float)((float)((float)v33 * v54->mat[3]) + (float)(v54->mat[7] * (float)v36)));
              v69.x = (float)((float)(v54->mat[11] * (float)v34)
                            + (float)((float)(v54->mat[3] * (float)v37) + (float)(v54->mat[7] * (float)v31)))
                    + (float)v40;
              v69.y = (float)v55 + (float)v38;
              v69.z = (float)v56 + (float)v39;
              idAFConstraint_BallAndSocketJoint::SetAnchor(this: v53, worldPosition: &v69);
            }
            else if ( type < 3 )
            {
              v47 = (idAFConstraint_UniversalJoint *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                       size: 0x230u,
                                                       tag: TAG_AF,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
              if ( v47 != nullptr )
                v48 = idAFConstraint_UniversalJoint::idAFConstraint_UniversalJoint(
                        this: v47,
                        name: this->bindConstraints.list[v42].name.data,
                        body1: v45,
                        body2: nullptr);
              else
                v48 = nullptr;
              idPhysics_AF::AddConstraint(this: &this->physicsObj, constraint: v48);
              idTreeAnimator::GetJointIndex(
                this: (idTreeAnimator *)&v60,
                result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                jointName: this->bindConstraints.list[v42].jointName.data);
              if ( v60 < 0 )
                idLib::Warning(
                  fmt: "idAnimator_AF::AddBindConstraints: joint '%s' not found",
                  this->bindConstraints.list[v42].jointName.data);
              v49 = &this->treeAnimator->joints[1][v60];
              v50 = (float)((float)((float)v32 * v49->mat[3])
                          + (float)((float)(v49->mat[7] * (float)v35) + (float)(v49->mat[11] * (float)v29)));
              v51 = (float)((float)((float)v33 * v49->mat[3])
                          + (float)((float)(v49->mat[7] * (float)v36) + (float)(v49->mat[11] * (float)v30)));
              v67.x = (float)((float)(v49->mat[11] * (float)v34)
                            + (float)((float)(v49->mat[3] * (float)v37) + (float)(v49->mat[7] * (float)v31)))
                    + (float)v40;
              v67.y = (float)v50 + (float)v38;
              v67.z = (float)v51 + (float)v39;
              idAFConstraint_UniversalJoint::SetAnchor(this: v48, worldPosition: &v67);
              v66.x = 0.0;
              v66.y = 0.0;
              v66.z = -1.0;
              v68.x = 0.0;
              v68.y = 0.0;
              v68.z = 1.0;
              idAFConstraint_UniversalJoint::SetShafts(this: v48, cardanShaft1: &v68, cardanShaft2: &v66);
            }
            else
            {
              idLib::Warning(fmt: "idAnimator_AF::AddBindConstraints: unknown constraint type '%d'", type);
            }
          }
          else
          {
            v57 = (idAFConstraint_Fixed *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x210u,
                                            tag: TAG_AF,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
            if ( v57 != nullptr )
              v58 = idAFConstraint_Fixed::idAFConstraint_Fixed(
                      this: v57,
                      name: this->bindConstraints.list[v42].name.data,
                      body1: v45,
                      body2: nullptr);
            else
              v58 = nullptr;
            if ( !this->bindConstraints.list[v42].shouldClamp )
              v58->shouldClamp = false;
            idPhysics_AF::AddConstraint(this: &this->physicsObj, constraint: v58);
          }
        }
        else
        {
          idLib::Warning(fmt: "idAnimator_AF::AddBindConstraints: body '%s' not found", list[v42].bodyName.data);
        }
        ++v41;
        ++v42;
      }
      while ( v41 < this->bindConstraints.num );
    }
    this->hasBindConstraints = true;
  }
}


// ========================================================================
// __unwind$252799
// EA  : 0x826CA998
// RVA : 0x006CA998
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_252799()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 544 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$252798
// EA  : 0x826CA9C4
// RVA : 0x006CA9C4
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_252798()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 544 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$252797
// EA  : 0x826CA9F0
// RVA : 0x006CA9F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_252797()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 544 + 80), tag: TAG_AF);
}


// ========================================================================
// ?RemoveBindConstraints@idAnimator_AF@@QAAXXZ
// EA  : 0x826CAA20
// RVA : 0x006CAA20
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::RemoveBindConstraints(idAnimator_AF *this)
{
  int v2; // r28
  idPhysics_AF *p_physicsObj; // r29
  int v4; // r30

  if ( this->isLoaded )
  {
    v2 = 0;
    if ( this->bindConstraints.num > 0 )
    {
      p_physicsObj = &this->physicsObj;
      v4 = 0;
      do
      {
        if ( idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: this->bindConstraints.list[v4].name.data) != nullptr )
          idPhysics_AF::DeleteConstraint(this: p_physicsObj, constraintName: this->bindConstraints.list[v4].name.data);
        ++v2;
        ++v4;
      }
      while ( v2 < this->bindConstraints.num );
    }
    this->hasBindConstraints = false;
  }
}


// ========================================================================
// ?InternalInit@idAnimator_AF@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826CAAA8
// RVA : 0x006CAAA8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

BOOL __fastcall idAnimator_AF::InternalInit(idAnimator_AF *this, const idAnimatorParms_Base *parms)
{
  idMD6Branch *v3; // r3

  v3 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  this->mergeBranch = v3;
  return v3 != nullptr;
}


// ========================================================================
// ?InternalShutdown@idAnimator_AF@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826CAAF8
// RVA : 0x006CAAF8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::InternalShutdown(idAnimator_AF *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
}


// ========================================================================
// ?InternalIsContributing@idAnimator_AF@@MBA_NXZ
// EA  : 0x826CAB50
// RVA : 0x006CAB50
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::InternalIsContributing(idAnimator_AF *this)
{
  unsigned __int8 v1; // r11

  if ( this->isActive )
    return 1;
  v1 = 0;
  if ( this->isClientAuthoritativeActive )
    return 1;
  return v1;
}


// ========================================================================
// ?ZeroAllImpulses@idAnimator_AF@@QAAXXZ
// EA  : 0x826CAB78
// RVA : 0x006CAB78
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::ZeroAllImpulses(idAnimator_AF *this)
{
  idPhysics_AF *p_physicsObj; // r29
  int i; // r30
  idAFBody *Body; // r3

  p_physicsObj = &this->physicsObj;
  for ( i = 0;
        i < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)p_physicsObj);
        *(idVec3 *)&Body->current.spatialVelocity.p[3] = vec3_origin )
  {
    Body = idPhysics_AF::GetBody(this: p_physicsObj, id: i++);
    Body->current.spatialVelocity.p[0] = vec3_origin.x;
    Body->current.spatialVelocity.p[1] = vec3_origin.y;
    Body->current.spatialVelocity.p[2] = vec3_origin.z;
  }
}


// ========================================================================
// ?SetAnimationVelocities@idAnimator_AF@@IAAXXZ
// EA  : 0x826CAED8
// RVA : 0x006CAED8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::SetAnimationVelocities(idAnimator_AF *this)
{
  idTreeAnimator *treeAnimator; // r3
  __int64 v3; // r9
  double v4; // fp31
  idTreeAnimator *v5; // r11
  float *p_deferredAxis; // r11
  double v7; // fp13
  double v8; // fp6
  double v9; // fp4
  idVec3 v10; // [sp+50h] [-60h] BYREF
  idVec3 v11; // [sp+60h] [-50h] BYREF
  idMat3 v12; // [sp+70h] [-40h] BYREF

  if ( this->isLoaded )
  {
    v3 = __PAIR64__(
           0x82000000,
           idGameTimeManager::GetGameMsPerFrame(this: this->gametimeManager.gameTimeManager, type: GAMETIME_SCALED));
    treeAnimator = this->treeAnimator;
    *(_QWORD *)&v10.x = v3;
    v4 = (float)(*(float *)(HIDWORD(v3) + 2984) / (float)((float)v3 * (float)0.001));
    idTreeAnimator::GetLastOriginDeltas(this: treeAnimator, rot: &v12, trans: &v11);
    v5 = this->treeAnimator;
    if ( v5->useDeferredPosition )
      p_deferredAxis = (float *)&v5->deferredAxis;
    else
      p_deferredAxis = (float *)&v5->g.axis;
    v7 = p_deferredAxis[5];
    v8 = (float)((float)(p_deferredAxis[8] * (float)(v11.z * (float)v4))
               + (float)(p_deferredAxis[2] * (float)(v11.x * (float)v4)));
    v9 = (float)((float)(*p_deferredAxis * (float)(v11.x * (float)v4))
               + (float)((float)(p_deferredAxis[6] * (float)(v11.z * (float)v4))
                       + (float)(p_deferredAxis[3] * (float)(v11.y * (float)v4))));
    v10.y = (float)(p_deferredAxis[4] * (float)(v11.y * (float)v4))
          + (float)((float)(p_deferredAxis[7] * (float)(v11.z * (float)v4))
                  + (float)(p_deferredAxis[1] * (float)(v11.x * (float)v4)));
    v10.x = v9;
    v10.z = (float)((float)v7 * (float)(v11.y * (float)v4)) + (float)v8;
    idAnimator_AF::SetJointVelocities(this, originVel: &v10);
  }
}


// ========================================================================
// ?ApplyWaterSplashEffects@idAnimator_AF@@UAAXHHW4surfTypes_t@@W4splashState_t@idPhysicsCallbacks@@@Z
// EA  : 0x826CAFF8
// RVA : 0x006CAFF8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::ApplyWaterSplashEffects(
        idAnimator_AF *this,
        int physId,
        const int bodyId,
        int surfOverride,
        idPhysicsCallbacks::splashState_t splashState)
{
  idPhysics *PhysicsForId; // r30
  const idVec3 *v8; // r3
  float y; // r7
  float z; // r6
  int v11; // r28
  int v12; // r3
  idSoundEmitter *soundEmitter; // r8
  idDeclImpactSound *sndBounceTable; // r3
  const idSoundShader *ImpactSoundForMaterial; // r30
  idDeclImpactParticle *prtBounceTable; // r3
  const idDeclParticle *ImpactParticleForMaterial; // r6
  int v18; // [sp+8h] [-138h]
  const idColor *v19; // [sp+Ch] [-134h]
  int v20; // [sp+10h] [-130h]
  idVec3 v21; // [sp+70h] [-D0h] BYREF
  soundShaderParms_t v22; // [sp+80h] [-C0h] BYREF

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  if ( PhysicsForId != nullptr )
  {
    v8 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    y = v8->y;
    z = v8->z;
    v21.x = v8->x;
    v21.y = y;
    v21.z = z;
    v11 = (int)PhysicsForId->GetBounds(this: PhysicsForId, a2: -1);
    v12 = (int)PhysicsForId->GetOrigin(this: PhysicsForId, a2: 0);
    soundEmitter = this->soundEmitter;
    v21.z = *(float *)(v12 + 8) + *(float *)(v11 + 20);
    if ( soundEmitter != nullptr )
    {
      sndBounceTable = this->sndBounceTable;
      if ( sndBounceTable != nullptr && this->physicsObj.endTime >= this->nextSoundTime )
      {
        ImpactSoundForMaterial = idDeclImpactSound::GetImpactSoundForMaterial(
                                   this: sndBounceTable,
                                   materialID: surfOverride);
        if ( ImpactSoundForMaterial != nullptr )
        {
          soundShaderParms_t::Clear(this: &v22);
          v22.soundShaderFlags = 0;
          this->soundEmitter->StartSound(
            this: this->soundEmitter,
            a2: this->bounceChannel,
            a3: ImpactSoundForMaterial,
            a4: &v22);
        }
        this->nextSoundTime = this->sndBounceTable->soundInterval + this->physicsObj.endTime;
      }
    }
    if ( this->impactMgr != nullptr )
    {
      prtBounceTable = this->prtBounceTable;
      if ( prtBounceTable != nullptr )
      {
        ImpactParticleForMaterial = idDeclImpactParticle::GetImpactParticleForMaterial(
                                      this: prtBounceTable,
                                      materialID: surfOverride);
        if ( ImpactParticleForMaterial != nullptr )
          idImpactManager::UseImpact(
            this: this->impactMgr,
            org: &v21,
            axis: &mat3_identity,
            prt: ImpactParticleForMaterial,
            startTime: this->physicsObj.endTime,
            bindToParent: false,
            parentOrg: &vec3_origin,
            parentAxis: &mat3_identity,
            playerIndex: v18,
            distSqr: 0.0,
            color: v19,
            numCycles: v20);
      }
    }
  }
}


// ========================================================================
// ?EndSync@idAnimator_AF@@QAAXXZ
// EA  : 0x826CB490
// RVA : 0x006CB490
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::EndSync(idAnimator_AF *this)
{
  idMD6Branch *v2; // r3
  int endTime; // r11
  idPhysics_AF_vtbl *v4; // r9
  long double v5; // fp2
  int v6; // r29
  int valueInteger; // r28
  __int64 v8; // r10
  _BYTE *v9; // r8
  __int64 v10; // r10
  long double v11; // fp2
  _BYTE *v12; // r8
  int v13; // r7
  int v14; // r4
  long double v15; // fp2
  __int64 v16; // r10
  int v17; // r7
  int v18; // r4
  long double v19; // fp2
  __int64 v20; // r10
  _BYTE *v21; // r8
  long double v22; // fp2
  __int64 v23; // r10
  _BYTE *v24; // r8
  int v25; // r7
  int v26; // r4
  __int64 v27; // r10
  long double v28; // fp2
  _BYTE *v29; // r8
  int v30; // r7
  int v31; // r4
  long double v32; // fp2
  __int64 v33; // r10
  int v34; // r4
  long double v35; // fp2
  __int64 v36; // r10
  _BYTE *v37; // r8
  int v38; // r7
  idPhysics_AF_vtbl *v39; // r10
  void (__fastcall *SetGravity)(struct idPhysics_AF *, const idVec3 *); // ctr
  float v41[4]; // [sp+50h] [-40h] BYREF

  if ( this->isSyncing )
  {
    v2 = this->InternalGetMergeBranch_2(this);
    if ( v2 != nullptr )
    {
      v2->currentAlpha = 0.0;
      v2->targetAlpha = 1.0;
      v2->alphaRate = (float)1.0 / af_blendDuration.valueFloat;
    }
    endTime = this->physicsObj.endTime;
    v4 = this->physicsObj.__vftable;
    this->isSyncing = false;
    this->poseTime = endTime;
    v4->SetGravity(this: &this->physicsObj, a2: &this->gravityBeforeSync);
    this->physicsObj.addContactConstraints = true;
    *(double *)&v5 = af_errorReduction.valueFloat;
    v6 = this->physicsObj.endTime;
    valueInteger = af_constraintRampDuration.valueInteger;
    idFader::FadeTowards(
      this: &this->physicsObj.errorReduction,
      endValue_: v5,
      time: (const int)&r_cuttablemodel_freecpudata.description,
      duration_: v6,
      a5: af_constraintRampDuration.valueInteger,
      a6: (int)&r_cuttablemodel_freecpudata.description,
      a7: v9,
      a8: v8);
    LODWORD(v10) = &r_cuttablemodel_freecpudata.description;
    HIDWORD(v10) = &af_errorReductionMax;
    *(double *)&v11 = af_errorReductionMax.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.errorReductionMax,
      endValue_: v11,
      time: v14,
      duration_: v6,
      a5: valueInteger,
      a6: v13,
      a7: v12,
      a8: v10);
    *(double *)&v15 = 0.001;
    idFader::FadeTowards(
      this: &this->physicsObj.lcpEpsilon,
      endValue_: v15,
      time: v18,
      duration_: v6,
      a5: valueInteger,
      a6: v17,
      a7: &off_82040000,
      a8: v16);
    *(double *)&v19 = af_limitErrorReduction.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.limitErrorReduction,
      endValue_: v19,
      time: (const int)&af_limitErrorReduction,
      duration_: v6,
      a5: valueInteger,
      a6: (int)&r_cuttablemodel_freecpudata.description,
      a7: v21,
      a8: v20);
    *(double *)&v22 = af_limitErrorReductionMax.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.limitErrorReductionMax,
      endValue_: v22,
      time: v26,
      duration_: v6,
      a5: valueInteger,
      a6: v25,
      a7: v24,
      a8: v23);
    LODWORD(v27) = &r_cuttablemodel_freecpudata.description;
    HIDWORD(v27) = &af_universalErrorReduction;
    *(double *)&v28 = af_universalErrorReduction.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.universalErrorReduction,
      endValue_: v28,
      time: v31,
      duration_: v6,
      a5: valueInteger,
      a6: v30,
      a7: v29,
      a8: v27);
    *(double *)&v32 = af_universalErrorReductionMax.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.universalErrorReductionMax,
      endValue_: v32,
      time: v34,
      duration_: v6,
      a5: valueInteger,
      a6: (int)&af_universalErrorReductionMax,
      a7: &r_cuttablemodel_freecpudata.description,
      a8: v33);
    *(double *)&v35 = af_universalTorsionLcpEpsilon.valueFloat;
    idFader::FadeTowards(
      this: &this->physicsObj.universalTorsionLcpEpsilon,
      endValue_: v35,
      time: (const int)&af_universalTorsionLcpEpsilon,
      duration_: v6,
      a5: valueInteger,
      a6: v38,
      a7: v37,
      a8: v36);
    v39 = this->physicsObj.__vftable;
    v41[0] = 0.0;
    v41[1] = 0.0;
    SetGravity = v39->SetGravity;
    v41[2] = -750.0;
    SetGravity(this: &this->physicsObj, a2: (const idVec3 *)v41);
    idAnimator_AF::Start(this);
    idAnimator_AF::SetAnimationVelocities(this);
  }
}


// ========================================================================
// ?Shutdown@idAnimator_AF@@QAAXXZ
// EA  : 0x826CB9D0
// RVA : 0x006CB9D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::Shutdown(idAnimator_AF *this)
{
  int v2; // r29
  int v3; // r30
  idAFConstraint *constraint; // r3
  idAnimator_AF::idSyncConstraint *v5; // r11
  idAnimator_AF::idSyncConstraint *list; // r4
  idAnimator_AF::idBindConstraint *v7; // r28
  int size; // r30
  idAnimator_AF::idBindConstraint *v9; // r29

  v2 = 0;
  if ( this->syncConstraints.num > 0 )
  {
    v3 = 0;
    do
    {
      constraint = this->syncConstraints.list[v3].constraint;
      if ( constraint != nullptr )
        ((void (__fastcall *)(idAFConstraint *, int))constraint->dtr_idAFConstraint)(a1: constraint, a2: 1);
      ++v2;
      v5 = &this->syncConstraints.list[v3++];
      v5->constraint = nullptr;
    }
    while ( v2 < this->syncConstraints.num );
  }
  if ( this->syncConstraints.listStatic == 0 || this->syncConstraints.listStatic == 2 )
  {
    list = this->syncConstraints.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->syncConstraints.list = nullptr;
    this->syncConstraints.size = 0;
  }
  this->syncConstraints.num = 0;
  if ( this->bindConstraints.listStatic == 0 || this->bindConstraints.listStatic == 2 )
  {
    v7 = this->bindConstraints.list;
    if ( v7 != nullptr )
    {
      size = this->bindConstraints.size;
      if ( size > 0 )
      {
        v9 = this->bindConstraints.list;
        do
        {
          idAAS2Settings::~idAAS2Settings(this: v9);
          --size;
          ++v9;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    }
    this->bindConstraints.list = nullptr;
    this->bindConstraints.size = 0;
  }
  this->bindConstraints.num = 0;
  this->physicsObj.UnlinkClip(this: &this->physicsObj);
  idPhysics_AF::Shutdown(this: &this->physicsObj);
}


// ========================================================================
// ?Collide@idAnimator_AF@@QAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x826CBB08
// RVA : 0x006CBB08
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

collide_t __fastcall idAnimator_AF::Collide(
        idAnimator_AF *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idAFBody *Body; // r3
  idDeclImpactSound *sndBounceTable; // r3
  double v9; // fp0
  double v10; // fp31
  const idSoundShader *ImpactSoundForMaterial; // r29
  idDeclImpactParticle *prtBounceTable; // r3
  const idDeclParticle *ImpactParticleForMaterial; // r29
  int endTime; // r27
  const idMat3 *v15; // r3
  int v17; // [sp+8h] [-178h]
  const idColor *v18; // [sp+Ch] [-174h]
  int v19; // [sp+10h] [-170h]
  idVec3 v20[4]; // [sp+70h] [-110h] BYREF
  soundShaderParms_t v21; // [sp+A0h] [-E0h] BYREF

  if ( this->physicsObj.physicsId == physId )
  {
    if ( this->isSyncing
      && (float)((float)(collision->c.normal.x * vec3_up.x)
               + (float)((float)(collision->c.normal.y * vec3_up.y) + (float)(collision->c.normal.z * vec3_up.z))) < 0.70710677 )
    {
      Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: collision->c.selfId);
      if ( Body != nullptr && (*(_BYTE *)&Body->fl & 2) == 0 )
        idAnimator_AF::EndSync(this);
    }
    if ( this->soundEmitter != nullptr )
    {
      sndBounceTable = this->sndBounceTable;
      if ( sndBounceTable != nullptr )
      {
        v9 = (float)-(float)((float)(velocity->x * collision->c.normal.x)
                           + (float)((float)(collision->c.normal.z * velocity->z)
                                   + (float)(collision->c.normal.y * velocity->y)));
        if ( v9 > 80.0 && this->physicsObj.endTime >= this->nextSoundTime )
        {
          if ( v9 <= 200.0 )
            v10 = (float)((float)__fsqrts((float)((float)-(float)((float)(velocity->x * collision->c.normal.x)
                                                                + (float)((float)(collision->c.normal.z * velocity->z)
                                                                        + (float)(collision->c.normal.y * velocity->y)))
                                                - (float)80.0))
                        * (float)((float)1.0 / (float)__fsqrts(120.0)));
          else
            v10 = 1.0;
          ImpactSoundForMaterial = idDeclImpactSound::GetImpactSoundForMaterial(
                                     this: sndBounceTable,
                                     materialID: collision->c.surfaceType);
          if ( ImpactSoundForMaterial != nullptr )
          {
            soundShaderParms_t::Clear(this: &v21);
            v21.soundShaderFlags = 0;
            if ( this->soundEmitter->StartSound(
                   this: this->soundEmitter,
                   a2: this->bounceChannel,
                   a3: ImpactSoundForMaterial,
                   a4: &v21) != 0 )
              this->soundEmitter->SetVolume(this: this->soundEmitter, a2: this->bounceChannel, a3: v10);
          }
          this->nextSoundTime = this->sndBounceTable->soundInterval + this->physicsObj.endTime;
        }
      }
    }
    if ( this->impactMgr != nullptr )
    {
      prtBounceTable = this->prtBounceTable;
      if ( prtBounceTable != nullptr && collision->fraction < 1.0 )
      {
        ImpactParticleForMaterial = idDeclImpactParticle::GetImpactParticleForMaterial(
                                      this: prtBounceTable,
                                      materialID: collision->c.surfaceType);
        if ( ImpactParticleForMaterial != nullptr )
        {
          endTime = this->physicsObj.endTime;
          v15 = idVec3::ToZAxis(this: v20, result: (idMat3 *)&collision->c.normal);
          idImpactManager::UseImpact(
            this: this->impactMgr,
            org: &collision->c.point,
            axis: v15,
            prt: ImpactParticleForMaterial,
            startTime: endTime,
            bindToParent: false,
            parentOrg: &vec3_origin,
            parentAxis: &mat3_identity,
            playerIndex: v17,
            distSqr: 0.0,
            color: v18,
            numCycles: v19);
        }
      }
    }
  }
  return COLLIDE_CONTINUE_SIMULATION;
}


// ========================================================================
// ??0idAnimator_AF@@QAA@XZ
// EA  : 0x826CC0F8
// RVA : 0x006CC0F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

idAnimator_AF *__fastcall idAnimator_AF::idAnimator_AF(idAnimator_AF *this)
{
  float *p_z; // r9
  float *p_y; // r10
  int i; // ctr
  float *v5; // r9
  float *v6; // r10
  int v7; // ctr

  idAnimator_Base::idAnimator_Base(this);
  this->articulatedFigure = nullptr;
  this->__vftable = (idAnimator_AF_vtbl *)&idAnimator_AF::`vftable';
  this->sndBounceTable = nullptr;
  this->prtBounceTable = nullptr;
  this->bindConstraints.granularity = 0;
  this->bindConstraints.memTag = 71;
  this->bindConstraints.listStatic = 0;
  this->bindConstraints.list = nullptr;
  this->bindConstraints.size = 0;
  this->bindConstraints.num = 0;
  this->canDeattachBones = true;
  this->afName.allocedAndFlag = 20;
  this->afName.data = this->afName.baseBuffer;
  this->afName.len = 0;
  this->afName.baseBuffer[0] = 0;
  this->clip = nullptr;
  this->treeAnimator = nullptr;
  this->modifiedAnim = nullptr;
  p_z = &this->baseOrigin.z;
  this->baseOrigin.x = 0.0;
  this->baseOrigin.y = 0.0;
  p_y = &mat2_identity.mat[1].y;
  this->baseOrigin.z = 0.0;
  for ( i = 9; i != 0; --i )
    *++p_z = *++p_y;
  this->jointMods.list = nullptr;
  this->jointMods.granularity = 0;
  this->jointMods.memTag = 71;
  this->jointMods.listStatic = 0;
  this->jointMods.size = 0;
  this->jointMods.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointMods);
  this->jointBody.list = nullptr;
  this->jointBody.granularity = 0;
  this->jointBody.memTag = 71;
  this->jointBody.listStatic = 0;
  this->jointBody.size = 0;
  this->jointBody.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointBody);
  v5 = &this->lastRenderModelOrigin.z;
  v6 = &mat2_identity.mat[1].y;
  v7 = 9;
  this->lastRenderModelOrigin = vec3_origin;
  do
  {
    *++v5 = *++v6;
    --v7;
  }
  while ( v7 != 0 );
  this->gravityBeforeSync = vec3_origin;
  this->poseTime = -1;
  this->restStartTime = -1;
  this->modifiesOrigin = false;
  this->isLoaded = false;
  this->isRunningPhysics = false;
  this->isActive = false;
  this->isClientAuthoritativeActive = false;
  this->isSyncing = false;
  this->hasBindConstraints = false;
  this->walkIKDisabled = false;
  this->syncConstraints.list = nullptr;
  this->syncConstraints.granularity = 0;
  this->syncConstraints.memTag = 71;
  this->syncConstraints.listStatic = 0;
  this->syncConstraints.size = 0;
  this->syncConstraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->syncConstraints);
  idPhysics_AF::idPhysics_AF(this: &this->physicsObj);
  this->physicsCallbacks = nullptr;
  idMD6LeafPause::idMD6LeafPause(this: &this->AFLeaf);
  this->mergeBranch = nullptr;
  this->soundEmitter = nullptr;
  this->bounceChannel = SND_CHANNEL_ANY;
  this->nextSoundTime = 0;
  this->impactMgr = nullptr;
  this->oldIsActive = false;
  this->fakeCB = nullptr;
  this->storedDeclAF = nullptr;
  this->lastTime = 0;
  this->initCount = 0;
  this->lastImpulseTime = -1;
  this->numSerializedImpulses = 0;
  this->inheritAnimationVelocity = false;
  this->inheritOverrideVelocity = false;
  this->overrideVelocity = vec3_origin;
  memset(Dst: this->serializeImpulseBuffer, Val: 0, Size: sizeof(this->serializeImpulseBuffer));
  return this;
}


// ========================================================================
// __unwind$255215
// EA  : 0x826CC32C
// RVA : 0x006CC32C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255215()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$255216
// EA  : 0x826CC354
// RVA : 0x006CC354
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255216()
{
  int v0; // r12

  idList<idAnimator_AF::idBindConstraint,71>::Clear(this: (idList<idAnimator_AF::idBindConstraint,71> *)(*(_DWORD *)(v0 - 144 + 164) + 52));
}


// ========================================================================
// __unwind$255217
// EA  : 0x826CC380
// RVA : 0x006CC380
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 72));
}


// ========================================================================
// __unwind$255218
// EA  : 0x826CC3AC
// RVA : 0x006CC3AC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255218()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 164));
}


// ========================================================================
// __unwind$255219
// EA  : 0x826CC3D8
// RVA : 0x006CC3D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255219()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 180));
}


// ========================================================================
// __unwind$255220
// EA  : 0x826CC404
// RVA : 0x006CC404
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255220()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 272));
}


// ========================================================================
// __unwind$255221
// EA  : 0x826CC430
// RVA : 0x006CC430
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255221()
{
  int v0; // r12

  idPhysics_AF::~idPhysics_AF(this: (idPhysics_AF *)(*(_DWORD *)(v0 - 144 + 164) + 288));
}


// ========================================================================
// ??1idAnimator_AF@@UAA@XZ
// EA  : 0x826CC480
// RVA : 0x006CC480
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::~idAnimator_AF(idAnimator_AF *this)
{
  idAnimatedEntityPhysicsCallbacksFake *fakeCB; // r11
  idAnimator_AF::idBindConstraint *list; // r3

  this->__vftable = (idAnimator_AF_vtbl *)&idAnimator_AF::`vftable';
  fakeCB = this->fakeCB;
  if ( fakeCB != nullptr )
  {
    fakeCB->af = nullptr;
    idMem::Free(this: &mem, ptr: this->fakeCB, align: ALIGN_16);
    this->fakeCB = nullptr;
  }
  idAnimator_AF::Shutdown(this);
  idMD6LeafPause::~idMD6LeafPause(this: &this->AFLeaf);
  idPhysics_AF::~idPhysics_AF(this: &this->physicsObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->syncConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointBody);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jointMods);
  idStr::FreeData(this: &this->afName);
  if ( this->bindConstraints.listStatic == 0 || this->bindConstraints.listStatic == 2 )
  {
    list = this->bindConstraints.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimator_AF::idBindConstraint>(ptr: list, num: this->bindConstraints.size);
    this->bindConstraints.list = nullptr;
    this->bindConstraints.size = 0;
  }
  this->bindConstraints.num = 0;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$255364
// EA  : 0x826CC54C
// RVA : 0x006CC54C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255364()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$255365
// EA  : 0x826CC574
// RVA : 0x006CC574
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255365()
{
  int v0; // r12

  idList<idAnimator_AF::idBindConstraint,71>::Clear(this: (idList<idAnimator_AF::idBindConstraint,71> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$255366
// EA  : 0x826CC5A0
// RVA : 0x006CC5A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$255367
// EA  : 0x826CC5CC
// RVA : 0x006CC5CC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255367()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$255368
// EA  : 0x826CC5F8
// RVA : 0x006CC5F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255368()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 180));
}


// ========================================================================
// __unwind$255369
// EA  : 0x826CC624
// RVA : 0x006CC624
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255369()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 272));
}


// ========================================================================
// __unwind$255370
// EA  : 0x826CC650
// RVA : 0x006CC650
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255370()
{
  int v0; // r12

  idPhysics_AF::~idPhysics_AF(this: (idPhysics_AF *)(*(_DWORD *)(v0 - 112 + 132) + 288));
}


// ========================================================================
// __unwind$255371
// EA  : 0x826CC67C
// RVA : 0x006CC67C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255371()
{
  int v0; // r12

  idMD6LeafPause::~idMD6LeafPause(this: (idMD6LeafPause *)(*(_DWORD *)(v0 - 112 + 132) + 1204));
}


// ========================================================================
// ?AddDynamicBindConstraint@idAnimator_AF@@QAAXHVidStr@@@Z
// EA  : 0x826CC6B0
// RVA : 0x006CC6B0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::AddDynamicBindConstraint(idAnimator_AF *this, int bodyIndex, idStr *constraintName)
{
  idPhysics_AF *p_physicsObj; // r28
  idAFBody *Body; // r10
  idAnimator_AF::idBindConstraint v8; // [sp+50h] [-A0h] BYREF

  if ( bodyIndex >= 0 )
  {
    p_physicsObj = &this->physicsObj;
    if ( bodyIndex < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)&this->physicsObj) )
    {
      Body = idPhysics_AF::GetBody(this: p_physicsObj, id: bodyIndex);
      if ( Body != nullptr )
      {
        v8.name.len = 0;
        v8.name.baseBuffer[0] = 0;
        v8.bodyName.len = 0;
        v8.bodyName.baseBuffer[0] = 0;
        v8.jointName.len = 0;
        v8.jointName.baseBuffer[0] = 0;
        v8.type = Fixed;
        v8.name.data = v8.name.baseBuffer;
        v8.bodyName.data = v8.bodyName.baseBuffer;
        v8.jointName.data = v8.jointName.baseBuffer;
        v8.name.allocedAndFlag = 20;
        v8.bodyName.allocedAndFlag = 20;
        v8.jointName.allocedAndFlag = 20;
        idStr::operator=(this: &v8.bodyName, text: Body->name.str);
        v8.type = Fixed;
        idStr::operator=(this: &v8.name, text: constraintName);
        v8.shouldClamp = false;
        idList<idAnimator_AF::idBindConstraint,71>::Insert(this: &this->bindConstraints, obj: &v8, index: 0);
        idAAS2Settings::~idAAS2Settings(this: &v8);
      }
    }
  }
  idStr::FreeData(this: constraintName);
}


// ========================================================================
// __unwind$255454
// EA  : 0x826CC7B8
// RVA : 0x006CC7B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255454()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 240 + 276));
}


// ========================================================================
// __unwind$255455
// EA  : 0x826CC7E0
// RVA : 0x006CC7E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255455()
{
  int v0; // r12

  idAAS2Settings::~idAAS2Settings(this: (idAnimator_AF::idBindConstraint *)(v0 - 240 + 80));
}


// ========================================================================
// ?AddBody@idAnimator_AF@@IAAXPAVidAFBody@@PBVidJointMat@@PBDW4AFJointModType_t@@@Z
// EA  : 0x826CC9A8
// RVA : 0x006CC9A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::AddBody(
        idAnimator_AF *this,
        idAFBody *body,
        const idJointMat *joints,
        const char *jointName,
        AFJointModType_t mod)
{
  int num; // r30
  const idJointMat *v11; // r11
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  double v15; // fp28
  double v16; // fp27
  double v17; // fp26
  double v18; // fp25
  double v19; // fp24
  double v20; // fp23
  double v21; // fp22
  double v22; // fp21
  double v23; // fp20
  idAnimator_AF::idAFJointMod *list; // r28
  idClipModel *clipModel; // r10
  float *v26; // r11
  double v27; // fp11
  double v28; // fp4
  double v29; // fp3
  char *v30; // r31
  __int16 v31; // [sp+50h] [-100h] BYREF
  idMat3 v32; // [sp+60h] [-F0h] BYREF
  idMat3 v33[4]; // [sp+90h] [-C0h] BYREF

  idTreeAnimator::GetJointIndex(
    this: (idTreeAnimator *)&v31,
    result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
    jointName);
  if ( v31 >= 0 )
  {
    num = this->jointMods.num;
    v11 = &joints[v31];
    v12 = v11->mat[10];
    v13 = v11->mat[6];
    v14 = v11->mat[2];
    v15 = v11->mat[9];
    v16 = v11->mat[5];
    v17 = v11->mat[1];
    v18 = v11->mat[8];
    v19 = v11->mat[4];
    v20 = v11->mat[0];
    v21 = v11->mat[3];
    v22 = v11->mat[7];
    v23 = v11->mat[11];
    v32.mat[2].z = v11->mat[10];
    v32.mat[1].z = v13;
    v32.mat[0].z = v14;
    v32.mat[2].y = v15;
    v32.mat[1].y = v16;
    v32.mat[0].y = v17;
    v32.mat[2].x = v18;
    v32.mat[1].x = v19;
    v32.mat[0].x = v20;
    idList<idAnimator_AF::idAFJointMod,71>::SetNum(this: &this->jointMods, newNum: num + 1);
    num *= 60;
    list = this->jointMods.list;
    *(int *)((char *)&list->bodyId + num) = idPhysics_AF::GetBodyId(this: &this->physicsObj, body);
    *(__int16 *)((char *)&this->jointMods.list->jointIndex.value + num) = v31;
    *(AFJointModType_t *)((char *)&this->jointMods.list->jointMod + num) = mod;
    clipModel = body->clipModel;
    v26 = (float *)((char *)&this->jointMods.list->bodyId + num);
    v27 = (float)(clipModel->origin.x - (float)v21);
    v28 = (float)((float)((float)(clipModel->origin.y - (float)v22) * (float)v16)
                + (float)((float)(clipModel->origin.z - (float)v23) * (float)v15));
    v29 = (float)((float)((float)(clipModel->origin.y - (float)v22) * (float)v13)
                + (float)((float)(clipModel->origin.z - (float)v23) * (float)v12));
    v26[1] = (float)((float)(clipModel->origin.x - (float)v21) * (float)v20)
           + (float)((float)((float)(clipModel->origin.y - (float)v22) * (float)v19)
                   + (float)((float)(clipModel->origin.z - (float)v23) * (float)v18));
    v26[2] = (float)((float)v27 * (float)v17) + (float)v28;
    v26[3] = (float)((float)v27 * (float)v14) + (float)v29;
    v30 = (char *)this->jointMods.list + num;
    *(idMat3 *)(v30 + 16) = *idMat3::operator*(this: v33, result: &body->clipModel->axis, a: &v32);
  }
  else
  {
    idLib::Warning(fmt: "idAnimator_AF for articulated figure '%s' modifies unknown joint '%s'", "<unknown>", jointName);
  }
}


// ========================================================================
// ?LoadBody@idAnimator_AF@@IAA_NPBVidDeclAF_Body@@PBVidJointMat@@PBDPBVidMaterial@@@Z
// EA  : 0x826CCB98
// RVA : 0x006CCB98
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::LoadBody(
        idAnimator_AF *this,
        const idDeclAF_Body *fb,
        const idJointMat *joints,
        const char *baseName,
        const idMaterial *clipMaterial)
{
  float y; // r10
  float z; // r9
  float *v12; // r4
  double v13; // fp12
  double v14; // fp9
  double x; // fp0
  int v16; // r30
  double v17; // fp13
  double v18; // fp11
  double v19; // fp10
  float *p_z; // r9
  int v21; // ctr
  idSysMutex *p_viewNoteMutex; // r10
  float *v23; // r9
  int v24; // ctr
  idSysMutex *v25; // r10
  float *v26; // r9
  int v27; // ctr
  idSysMutex *v28; // r10
  float *v29; // r9
  int v30; // ctr
  idSysMutex *v31; // r10
  float *v32; // r9
  int v33; // ctr
  idSysMutex *v34; // r10
  float *v35; // r9
  int v36; // ctr
  idSysMutex *v37; // r10
  float *v38; // r9
  int v39; // ctr
  idSysMutex *v40; // r10
  idSysMutex *v41; // r11
  int v42; // ctr
  float *v43; // r10
  int modelType; // r11
  int v45; // r25
  unsigned int v46; // r11
  double v47; // fp31
  int v48; // r3
  idMat3 *p_relativeAxis; // r28
  int i; // r29
  idTraceModel *p_fovScale; // r28
  int j; // r29
  double v53; // fp31
  double v54; // fp30
  int v55; // r29
  double v56; // fp29
  idTreeAnimator_vtbl *v57; // r3
  idClipModel *v58; // r28
  idAFBody *Body; // r3
  idAFBody *v60; // r29
  const idMat3 *v61; // r4
  int BodyId; // r3
  idTreeAnimator_vtbl *v63; // r3
  const idMat3 *v64; // r4
  double linearFriction; // fp1
  int v66; // r20
  int clipMask; // r11
  idAFBody::afBodyFlags_t fl; // r10
  idAFBody::afBodyFlags_t v69; // r11
  const char *str; // r3
  int v71; // r3
  char v72; // r11
  idAnimation_vtbl *v73; // r6
  float *clipModel; // r11
  int (*GetOriginJointName)(void); // r5
  int p_axis; // r11
  const char *v77; // r3
  idIndex<short,enum invalidJointIndex_t> *FirstChild; // r3
  const char *JointName; // r6
  AFJointModType_t v80; // r7
  declAFJointMod_t jointMod; // r11
  __int64 v82; // r10
  __int64 v83; // r8
  int v84; // r6
  idAnimator_AF::idAFJointMod *list; // r4
  unsigned int num; // r5
  double v87; // fp13
  double v88; // fp0
  double v89; // fp12
  double v90; // fp13
  bool v91; // zf
  char v92; // r11
  char v93; // r11
  int k; // r24
  const idIndex<short,enum invalidJointIndex_t> *value; // r28
  int v96; // r29
  int v97; // r10
  idAFBody *v98; // r3
  const char *v99; // r19
  const idIndex<short,enum invalidJointIndex_t> *v100; // r4
  const char *v101; // r28
  const char *v102; // r3
  idTreeAnimator v104; // [sp+50h] [-3170h] BYREF
  int v105; // [sp+CE0h] [-24E0h]
  int v106; // [sp+CE4h] [-24DCh]
  int v107; // [sp+CE8h] [-24D8h]
  int v108; // [sp+CECh] [-24D4h]
  int v109; // [sp+CF0h] [-24D0h]
  float v110; // [sp+CF4h] [-24CCh]
  float v111; // [sp+CF8h] [-24C8h]
  float v112[8]; // [sp+CFCh] [-24C4h] BYREF
  __int16 v113; // [sp+D1Ch] [-24A4h]
  __int16 v114; // [sp+D1Eh] [-24A2h]
  int v115; // [sp+12E0h] [-1EE0h]
  int v116; // [sp+12E4h] [-1EDCh]
  int v117; // [sp+12E8h] [-1ED8h]
  int v118; // [sp+12ECh] [-1ED4h]
  int v119; // [sp+12F0h] [-1ED0h]
  float v120; // [sp+12F4h] [-1ECCh]
  float v121; // [sp+12F8h] [-1EC8h]
  float v122[8]; // [sp+12FCh] [-1EC4h] BYREF
  __int16 v123; // [sp+131Ch] [-1EA4h]
  __int16 v124; // [sp+131Eh] [-1EA2h]
  int v125; // [sp+18E0h] [-18E0h]
  int v126; // [sp+18E4h] [-18DCh]
  int v127; // [sp+18E8h] [-18D8h]
  int v128; // [sp+18ECh] [-18D4h]
  int v129; // [sp+18F0h] [-18D0h]
  float v130; // [sp+18F4h] [-18CCh]
  float v131; // [sp+18F8h] [-18C8h]
  float v132[8]; // [sp+18FCh] [-18C4h] BYREF
  __int16 v133; // [sp+191Ch] [-18A4h]
  __int16 v134; // [sp+191Eh] [-18A2h]
  int v135; // [sp+1EE0h] [-12E0h]
  int v136; // [sp+1EE4h] [-12DCh]
  int v137; // [sp+1EE8h] [-12D8h]
  int v138; // [sp+1EECh] [-12D4h]
  int v139; // [sp+1EF0h] [-12D0h]
  float v140; // [sp+1EF4h] [-12CCh]
  float v141; // [sp+1EF8h] [-12C8h]
  float v142[8]; // [sp+1EFCh] [-12C4h] BYREF
  __int16 v143; // [sp+1F1Ch] [-12A4h]
  __int16 v144; // [sp+1F1Eh] [-12A2h]
  int v145; // [sp+24E0h] [-CE0h]
  int v146; // [sp+24E4h] [-CDCh]
  int v147; // [sp+24E8h] [-CD8h]
  int v148; // [sp+24ECh] [-CD4h]
  int v149; // [sp+24F0h] [-CD0h]
  float v150; // [sp+24F4h] [-CCCh]
  float v151; // [sp+24F8h] [-CC8h]
  float v152[8]; // [sp+24FCh] [-CC4h] BYREF
  __int16 v153; // [sp+251Ch] [-CA4h]
  __int16 v154; // [sp+251Eh] [-CA2h]
  int v155; // [sp+2AE0h] [-6E0h]
  int v156; // [sp+2AE4h] [-6DCh]
  int v157; // [sp+2AE8h] [-6D8h]
  int v158; // [sp+2AECh] [-6D4h]
  int v159; // [sp+2AF0h] [-6D0h]
  float v160; // [sp+2AF4h] [-6CCh]
  float v161; // [sp+2AF8h] [-6C8h]
  float v162[8]; // [sp+2AFCh] [-6C4h] BYREF
  __int16 v163; // [sp+2B1Ch] [-6A4h]
  __int16 v164; // [sp+2B1Eh] [-6A2h]
  int v165; // [sp+30E0h] [-E0h]
  int v166; // [sp+30E4h] [-DCh]
  int v167; // [sp+30E8h] [-D8h]
  int v168; // [sp+30ECh] [-D4h]
  int v169; // [sp+30F0h] [-D0h]
  float v170; // [sp+30F4h] [-CCh]
  float v171; // [sp+30F8h] [-C8h]
  float v172[8]; // [sp+30FCh] [-C4h] BYREF
  __int16 v173; // [sp+311Ch] [-A4h]
  __int16 v174; // [sp+311Eh] [-A2h]

  y = fb->origin.vec.y;
  z = fb->origin.vec.z;
  *((_DWORD *)&v104.__vftable + 2) = LODWORD(fb->origin.vec.x);
  *((float *)&v104.__vftable + 3) = y;
  *(float *)&v104.name.str = z;
  idAngles::ToMat3(this: (idAngles *)&v104.deferredAxis.mat[2].y, result: (idMat3 *)&fb->angles);
  v13 = fb->v1.vec.z;
  v14 = fb->v2.vec.z;
  x = fb->v1.vec.x;
  v16 = 0;
  v17 = fb->v1.vec.y;
  v18 = fb->v2.vec.x;
  v19 = fb->v2.vec.y;
  p_z = &v104.decalData.staticList[10].relativePos.z;
  v21 = 6;
  v104.decalData.staticList[10].relativePos.x = 0.0;
  memset(&v104.decalData.staticList[9].relativeAxis.mat[2], 0, 20);
  v104.decalData.staticList[10].relativePos.y = 0.0;
  v104.decalData.staticList[10].relativePos.z = 0.0;
  v104.deferredAxis.mat[0].y = v13;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  v104.deferredAxis.mat[1].y = v14;
  v104.deferredOrigin.z = x;
  v104.deferredAxis.mat[0].x = v17;
  v104.deferredAxis.mat[0].z = v18;
  v104.deferredAxis.mat[1].x = v19;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v21;
  }
  while ( v21 != 0 );
  v104.decalData.staticList[10].relativeAxis.mat[2].x = 0.0;
  v23 = v112;
  v110 = 0.0;
  v111 = 0.0;
  v112[0] = 0.0;
  v104.decalData.staticList[10].relativeAxis.mat[2].y = 0.0;
  v24 = 6;
  v105 = 0;
  v25 = &analysisClient.viewNoteMutex;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v109 = 0;
  do
  {
    ++v25;
    *++v23 = *(float *)&v25->handle;
    --v24;
  }
  while ( v24 != 0 );
  v112[7] = 0.0;
  v26 = v122;
  v120 = 0.0;
  v121 = 0.0;
  v122[0] = 0.0;
  v114 = 0;
  v27 = 6;
  v113 = 0;
  v115 = 0;
  v28 = &analysisClient.viewNoteMutex;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  v119 = 0;
  do
  {
    ++v28;
    *++v26 = *(float *)&v28->handle;
    --v27;
  }
  while ( v27 != 0 );
  v122[7] = 0.0;
  v29 = v132;
  v130 = 0.0;
  v131 = 0.0;
  v132[0] = 0.0;
  v124 = 0;
  v30 = 6;
  v123 = 0;
  v125 = 0;
  v31 = &analysisClient.viewNoteMutex;
  v126 = 0;
  v127 = 0;
  v128 = 0;
  v129 = 0;
  do
  {
    ++v31;
    *++v29 = *(float *)&v31->handle;
    --v30;
  }
  while ( v30 != 0 );
  v132[7] = 0.0;
  v32 = v142;
  v140 = 0.0;
  v141 = 0.0;
  v142[0] = 0.0;
  v134 = 0;
  v33 = 6;
  v133 = 0;
  v135 = 0;
  v34 = &analysisClient.viewNoteMutex;
  v136 = 0;
  v137 = 0;
  v138 = 0;
  v139 = 0;
  do
  {
    ++v34;
    *++v32 = *(float *)&v34->handle;
    --v33;
  }
  while ( v33 != 0 );
  v142[7] = 0.0;
  v35 = v152;
  v150 = 0.0;
  v151 = 0.0;
  v152[0] = 0.0;
  v144 = 0;
  v36 = 6;
  v143 = 0;
  v145 = 0;
  v37 = &analysisClient.viewNoteMutex;
  v146 = 0;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  do
  {
    ++v37;
    *++v35 = *(float *)&v37->handle;
    --v36;
  }
  while ( v36 != 0 );
  v152[7] = 0.0;
  v38 = v162;
  v160 = 0.0;
  v161 = 0.0;
  v162[0] = 0.0;
  v154 = 0;
  v39 = 6;
  v153 = 0;
  v155 = 0;
  v40 = &analysisClient.viewNoteMutex;
  v156 = 0;
  v157 = 0;
  v158 = 0;
  v159 = 0;
  do
  {
    ++v40;
    *++v38 = *(float *)&v40->handle;
    --v39;
  }
  while ( v39 != 0 );
  v162[7] = 0.0;
  v170 = 0.0;
  v171 = 0.0;
  v164 = 0;
  v41 = &analysisClient.viewNoteMutex;
  v163 = 0;
  v42 = 6;
  v43 = v172;
  v172[0] = 0.0;
  v165 = 0;
  v166 = 0;
  v167 = 0;
  v168 = 0;
  v169 = 0;
  do
  {
    ++v41;
    *++v43 = *(float *)&v41->handle;
    --v42;
  }
  while ( v42 != 0 );
  modelType = fb->modelType;
  v172[7] = 0.0;
  v45 = 1;
  v46 = modelType - 1;
  v174 = 0;
  v173 = 0;
  if ( v46 > 8 )
    goto LABEL_42;
  switch ( v46 )
  {
    case 1u:
      idTraceModel::SetupOctahedron(
        this: (idTraceModel *)&v104.g.fovScale,
        octBounds: (const idBounds *)&v104.deferredOrigin.z);
      goto LABEL_42;
    case 2u:
      idTraceModel::SetupDodecahedron(
        this: (idTraceModel *)&v104.g.fovScale,
        dodBounds: (const idBounds *)&v104.deferredOrigin.z);
      goto LABEL_42;
    case 3u:
      idTraceModel::SetupCylinder(
        this: (idTraceModel *)&v104.g.fovScale,
        cylBounds: (const idBounds *)&v104.deferredOrigin.z,
        numSides: fb->numSides);
      goto LABEL_42;
    case 4u:
      v104.deferredAxis.mat[0].y = (float)v13 - (float)v14;
      v104.deferredAxis.mat[1].y = 0.0;
      idTraceModel::SetupCone(
        this: (idTraceModel *)&v104.g.fovScale,
        coneBounds: (const idBounds *)&v104.deferredOrigin.z,
        numSides: fb->numSides);
      goto LABEL_42;
    case 5u:
      v104.referenceBounds.b[0].y = (float)v14 - (float)v13;
      v104.referenceBounds.b[0].x = (float)v19 - (float)v17;
      *(float *)&v104.committed = (float)v18 - (float)x;
      v47 = idVec3::NormalizeFast(this: (idVec3 *)&v104.committed);
      idVec3::NormalVectors(
        this: (idVec3 *)&v104.committed,
        left: (idVec3 *)&v104.deferredAxis.mat[2].y,
        down: (idVec3 *)&v104.needWriteToSnapshot);
      *(float *)&v104.needWriteToSnapshot = -*(float *)&v104.needWriteToSnapshot;
      *(float *)&v104.needCommitFrameNum = -*(float *)&v104.needCommitFrameNum;
      *(float *)&v104.nextOnCommitList = -*(float *)&v104.nextOnCommitList;
      idTraceModel::SetupBone(this: (idTraceModel *)&v104.g.fovScale, length: v47, width: fb->width);
      goto LABEL_42;
    case 6u:
    case 7u:
      goto LABEL_42;
    case 0u:
      idTraceModel::SetupBox(
        this: (idTraceModel *)&v104.g.fovScale,
        boxBounds: (const idBounds *)&v104.deferredOrigin.z);
      goto LABEL_42;
    default:
      break;
  }
  v48 = idCollisionModelManager::CompoundTrmFromModel(
          this: collisionModelManager,
          modelName: fb->modelName.str,
          trms: (idTraceModel *)&v104.g.fovScale,
          maxTrms: 8,
          invalidSubmodelIndices: nullptr,
          numInvalidIndices: nullptr);
  v45 = v48;
  if ( v48 == 0 || v48 > 8 )
  {
    idLib::Warning(fmt: "idAnimator_AF::LoadBody: couldn't load collision model '%s'", fb->modelName.str);
    idTraceModel::SetupBox(this: (idTraceModel *)&v104.g.fovScale, size: 8.0);
    v45 = 1;
LABEL_42:
    v53 = *(float *)&v104.name.str;
    v54 = *((float *)&v104.__vftable + 3);
    v55 = 2;
    v56 = *((float *)&v104.__vftable + 2);
    do
    {
      idTraceModel::GetMassProperties(
        this: (idTraceModel *)&v104.g.fovScale,
        density: 1.0,
        mass: v12,
        centerOfMass: (idVec3 *)&v104,
        inertiaTensor: (idMat3 *)&v104.referenceBounds.b[1]);
      *(float *)&v104.g.groupMasterIndex = -v104.referenceBounds.b[1].x;
      *(float *)&v104.g.suppressSurfaceInViewID = -v104.referenceBounds.b[1].z;
      *(float *)&v104.g.allowSurfaceOnlyInViewID = -v104.referenceBounds.b[1].y;
      idTraceModel::Translate(
        this: (idTraceModel *)&v104.g.fovScale,
        translation: (const idVec3 *)&v104.g.groupMasterIndex);
      --v55;
      v56 = (float)((float)((float)(*(float *)&v104.committed * v104.referenceBounds.b[1].z)
                          + (float)((float)(v104.deferredAxis.mat[2].y * v104.referenceBounds.b[1].x)
                                  + (float)(*(float *)&v104.needWriteToSnapshot * v104.referenceBounds.b[1].y)))
                  + (float)v56);
      v53 = (float)((float)v53
                  + (float)((float)(*(float *)&v104.useDeferredPosition * v104.referenceBounds.b[1].x)
                          + (float)((float)(*(float *)&v104.needCommitFrameNum * v104.referenceBounds.b[1].y)
                                  + (float)(v104.referenceBounds.b[0].y * v104.referenceBounds.b[1].z))));
      v54 = (float)((float)v54
                  + (float)((float)(v104.deferredAxis.mat[2].z * v104.referenceBounds.b[1].x)
                          + (float)((float)(*(float *)&v104.nextOnCommitList * v104.referenceBounds.b[1].y)
                                  + (float)(v104.referenceBounds.b[0].x * v104.referenceBounds.b[1].z))));
    }
    while ( v55 != 0 );
    *((float *)&v104.__vftable + 3) = v54;
    *(float *)&v104.name.str = v53;
    *((float *)&v104.__vftable + 2) = v56;
    goto LABEL_45;
  }
  if ( idBounds::GetVolume(this: (idBounds *)&v104.deferredOrigin.z) > 0.0 )
  {
    v104.g.axis.mat[0].z = 1.0e30;
    v104.g.axis.mat[0].y = 1.0e30;
    v104.g.axis.mat[0].x = 1.0e30;
    v104.g.axis.mat[1].z = -1.0e30;
    v104.g.axis.mat[1].y = v104.g.axis.mat[1].z;
    v104.g.axis.mat[1].x = v104.g.axis.mat[1].z;
    if ( v45 > 0 )
    {
      p_relativeAxis = &v104.decalData.staticList[10].relativeAxis;
      for ( i = v45; i != 0; --i )
      {
        idBounds::AddBounds(this: (idBounds *)&v104.g.axis, a: (const idBounds *)p_relativeAxis);
        p_relativeAxis = (idMat3 *)((char *)p_relativeAxis + 1536);
      }
    }
    v104.g.scale.y = (float)(v104.deferredAxis.mat[0].z - v104.deferredOrigin.z)
                   / (float)(v104.g.axis.mat[1].x - v104.g.axis.mat[0].x);
    v104.g.scale.z = (float)(v104.deferredAxis.mat[1].x - v104.deferredAxis.mat[0].x)
                   / (float)(v104.g.axis.mat[1].y - v104.g.axis.mat[0].y);
    *(float *)&v104.g.customMaterial = (float)(v104.deferredAxis.mat[1].y - v104.deferredAxis.mat[0].y)
                                     / (float)(v104.g.axis.mat[1].z - v104.g.axis.mat[0].z);
    if ( v45 > 0 )
    {
      p_fovScale = (idTraceModel *)&v104.g.fovScale;
      for ( j = v45; j != 0; --j )
        idTraceModel::Scale(this: p_fovScale++, scale: (const idVec3 *)&v104.g.scale.y);
    }
  }
  if ( v45 == 1 )
    goto LABEL_42;
LABEL_45:
  v57 = (idTreeAnimator_vtbl *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xD8u,
                                 tag: TAG_CLIPMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  v104.__vftable = v57;
  if ( v57 != nullptr )
    v58 = idClipModel::idClipModel(
            this: (idClipModel *)v57,
            clip: this->clip,
            trm: (const idTraceModel *)&v104.g.fovScale,
            numTraceModels: v45,
            material: clipMaterial);
  else
    v58 = nullptr;
  idClipModel::SetContents(this: v58, newContents: fb->contents);
  idClipModel::SetLinkedPosition(
    this: v58,
    newOrigin: (const idVec3 *)(&v104.__vftable + 2),
    newAxis: (const idMat3 *)&v104.deferredAxis.mat[2].y);
  Body = idPhysics_AF::GetBody(this: &this->physicsObj, bodyName: fb->name.str);
  v60 = Body;
  if ( Body != nullptr )
  {
    idAFBody::SetClipModel(this: Body, clipModel: v58);
    idAFBody::SetDensity(this: v60, density: fb->density, inertiaScale: v61);
    idClipModel::SetLinkedPosition(
      this: v60->clipModel,
      newOrigin: (const idVec3 *)(&v104.__vftable + 2),
      newAxis: &v60->clipModel->axis);
    idClipModel::SetLinkedPosition(
      this: v60->clipModel,
      newOrigin: &v60->clipModel->origin,
      newAxis: (const idMat3 *)&v104.deferredAxis.mat[2].y);
    BodyId = idPhysics_AF::GetBodyId(this: &this->physicsObj, body: v60);
  }
  else
  {
    v63 = (idTreeAnimator_vtbl *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x330u,
                                   tag: TAG_AF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    v104.__vftable = v63;
    if ( v63 != nullptr )
      v60 = idAFBody::idAFBody(this: (idAFBody *)v63, name: fb->name.str, clipModel: v58, density: fb->density);
    else
      v60 = nullptr;
    if ( (unsigned __int8)idMat3::Compare(this: &fb->inertiaScale, a: &mat3_identity) == 0 )
      idAFBody::SetDensity(this: v60, density: fb->density, inertiaScale: v64);
    BodyId = idPhysics_AF::AddBody(this: &this->physicsObj, body: v60);
  }
  linearFriction = fb->linearFriction;
  v66 = BodyId;
  if ( linearFriction != -1.0 )
    idAFBody::SetFriction(this: v60, linear: linearFriction, angular: fb->angularFriction, contact: fb->contactFriction);
  clipMask = fb->clipMask;
  fl = v60->fl;
  v60->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
  v60->clipMask = clipMask;
  v60->fl = (idAFBody::afBodyFlags_t)((fb->selfCollision << 6) & 0x40 | *(_BYTE *)&fl & 0x3F | 0x80);
  idAFBody::SetBouncyness(this: v60, bounce: fb->bouncyness);
  v69 = (idAFBody::afBodyFlags_t)((2 * fb->noSyncCollide) & 2 | *(_BYTE *)&v60->fl & 0xFD);
  v60->fl = v69;
  v60->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&v69 & 0xFE | fb->clearClipMaskInSolid);
  str = fb->jointName.str;
  if ( str == baseName || (v71 = idStr::Cmp(s1: str, s2: baseName), v72 = 0, v71 == 0) )
    v72 = 1;
  if ( v72 != 0 )
  {
    idPhysics_AF::ForceBodyId(this: &this->physicsObj, body: v60, newId: 0);
    v104.__vftable = (idTreeAnimator_vtbl *)&this->baseOrigin;
    v73 = animation->__vftable;
    clipModel = (float *)v60->clipModel;
    this->baseOrigin.x = clipModel[8];
    this->baseOrigin.y = clipModel[9];
    GetOriginJointName = (int (*)(void))v73->GetOriginJointName;
    this->baseOrigin.z = clipModel[10];
    p_axis = (int)&v60->clipModel->axis;
    this->baseAxis.mat[0].x = *(float *)p_axis;
    this->baseAxis.mat[0].y = *(float *)(p_axis + 4);
    v104.__vftable = (idTreeAnimator_vtbl *)(p_axis + 24);
    this->baseAxis.mat[0].z = *(float *)(p_axis + 8);
    this->baseAxis.mat[1].x = *(float *)(p_axis + 12);
    this->baseAxis.mat[1].y = *(float *)(p_axis + 16);
    this->baseAxis.mat[1].z = *(float *)(p_axis + 20);
    this->baseAxis.mat[2].x = *(float *)(p_axis + 24);
    this->baseAxis.mat[2].y = *(float *)(p_axis + 28);
    this->baseAxis.mat[2].z = *(float *)(p_axis + 32);
    v77 = (const char *)GetOriginJointName();
    FirstChild = idTreeAnimator::GetFirstChild(
                   this: &v104,
                   result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                   parentName: v77);
    JointName = idTreeAnimator::GetJointName(
                  this: this->treeAnimator,
                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)FirstChild->value);
    v80 = AF_JOINTMOD_AXIS;
    goto LABEL_70;
  }
  jointMod = fb->jointMod;
  if ( jointMod == DECLAF_JOINTMOD_AXIS )
    goto LABEL_68;
  if ( jointMod != DECLAF_JOINTMOD_ORIGIN )
  {
    v80 = AF_JOINTMOD_BOTH;
    if ( jointMod == DECLAF_JOINTMOD_BOTH )
      goto LABEL_69;
LABEL_68:
    v80 = AF_JOINTMOD_AXIS;
    goto LABEL_69;
  }
  v80 = AF_JOINTMOD_ORIGIN;
LABEL_69:
  JointName = fb->jointName.str;
LABEL_70:
  idAnimator_AF::AddBody(this, body: v60, joints, jointName: JointName, mod: v80);
  LODWORD(v104.deferredAxis.mat[1].z) = &idSort_JointMods::`vftable';
  list = this->jointMods.list;
  if ( list != nullptr )
  {
    num = this->jointMods.num;
    v104.__vftable = (idTreeAnimator_vtbl *)this->jointMods.list;
    idSort_Quick<idAnimator_AF::idAFJointMod,idSort_JointMods>::Sort(
      this: (idSort_Quick<idAnimator_AF::idAFJointMod,idSort_JointMods> *)&v104.deferredAxis.mat[1].z,
      base: list,
      num,
      a4: v84,
      a5: v83,
      a6: v82);
  }
  v87 = fb->frictionDirection.vec.x;
  v88 = vec3_origin.x;
  LODWORD(v104.deferredAxis.mat[1].z) = &idSort<idAnimator_AF::idAFJointMod>::`vftable';
  v89 = vec3_origin.z;
  v91 = v87 != vec3_origin.x;
  v90 = vec3_origin.y;
  if ( v91 || fb->frictionDirection.vec.y != v90 || (v92 = 1, fb->frictionDirection.vec.z != v89) )
    v92 = 0;
  if ( v92 == 0 )
  {
    idAFBody::SetFrictionDirection(this: v60, dir: &fb->frictionDirection.vec);
    v89 = vec3_origin.z;
    v90 = vec3_origin.y;
    v88 = vec3_origin.x;
  }
  if ( fb->contactMotorDirection.vec.x != v88
    || fb->contactMotorDirection.vec.y != v90
    || (v93 = 1, fb->contactMotorDirection.vec.z != v89) )
  {
    v93 = 0;
  }
  if ( v93 == 0 )
    idAFBody::SetContactMotorDirection(this: v60, dir: &fb->contactMotorDirection.vec);
  for ( k = 0; k < fb->containedJointIndices.num; this->jointBody.list[v96] = v66 )
  {
    value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)fb->containedJointIndices.list[v16].value;
    v96 = (__int16)value;
    v97 = this->jointBody.list[v96];
    if ( v97 != -1 && v97 != v66 )
    {
      v104.__vftable = (idTreeAnimator_vtbl *)&this->jointBody.list[v96];
      if ( idPhysics_AF::GetBody(this: &this->physicsObj, id: v97) != nullptr )
      {
        v98 = idPhysics_AF::GetBody(this: &this->physicsObj, id: this->jointBody.list[v96]);
        v99 = fb->name.str;
        v100 = value;
        v101 = v98->name.str;
        v102 = idTreeAnimator::GetJointName(this: this->treeAnimator, jointIndex: v100);
        idLib::Warning(
          fmt: "%s: joint '%s' contained by body '%s' is already contained by body '%s'",
          "<unknown>",
          v102,
          v99,
          v101);
      }
    }
    ++k;
    ++v16;
  }
  return 1;
}


// ========================================================================
// __unwind$255969
// EA  : 0x826CD6CC
// RVA : 0x006CD6CC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255969()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12736 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$255970
// EA  : 0x826CD6F8
// RVA : 0x006CD6F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255970()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12736 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$255971
// EA  : 0x826CD724
// RVA : 0x006CD724
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_255971()
{
  int v0; // r12

  idSort_JointMods::~idSort_JointMods(this: (idSort_JointMods *)(v0 - 12736 + 136));
}


// ========================================================================
// ?UpdateAnimation@idAnimator_AF@@IAA_NXZ
// EA  : 0x826CD758
// RVA : 0x006CD758
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::UpdateAnimation(idAnimator_AF *this)
{
  char v2; // r11
  idPhysics_AF *p_physicsObj; // r24
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idMD6Leaf::wrapMode_t v6; // r5
  idTreeAnimator *treeAnimator; // r11
  idRenderModelParms *p_deferredOrigin; // r10
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r10
  BOOL useDeferredPosition; // r6
  int *v13; // r9
  _DWORD *p_z; // r10
  int i; // ctr
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  double v19; // fp28
  double v20; // fp30
  double v21; // fp29
  double v22; // fp12
  double v23; // fp11
  double v24; // fp9
  double v25; // fp10
  double v26; // fp13
  double v27; // fp0
  int v28; // r3
  idPLog **p_pLog; // r10
  _DWORD *v30; // r11
  int j; // ctr
  const idVec3 *v32; // r3
  double v33; // fp13
  double v34; // fp12
  double v35; // fp11
  double v36; // fp10
  double v37; // fp9
  float v38; // r7
  double v39; // fp8
  float v40; // r6
  double v41; // fp7
  float v42; // r11
  double v43; // fp6
  idMat3 *v44; // r3
  double v45; // fp1
  double v46; // fp31
  double v47; // fp5
  double v48; // fp4
  double v49; // fp7
  const idMD6Anim *modifiedAnim; // r4
  float *Bounds; // r3
  double v52; // fp9
  double v53; // fp7
  double v54; // fp5
  double v55; // fp4
  double v56; // fp3
  int v57; // r26
  int v58; // r7
  idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *v59; // r27
  idMD6Blend::jointMod_t *list; // r25
  int v61; // r12
  int v62; // r19
  int v63; // r27
  idMD6Blend::jointMod_t *v64; // r22
  idPLogScope v65; // r9
  int v66; // r3
  idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> *v67; // r10
  idIndex<short,enum invalidJointIndex_t> *p_joint; // r11
  idPLogScope *v69; // r11
  int k; // ctr
  idMD6Blend::jointMod_t *v71; // r11
  int v72; // r7
  _QWORD *v73; // r10
  _QWORD *v74; // r11
  int m; // ctr
  __int64 v76; // r9
  _QWORD *v77; // r8
  __int64 v78; // r11
  int n; // ctr
  idMD6Blend::jointMod_t *v80; // r30
  AFJointModType_t jointMod; // r11
  float *v82; // r14
  idMat3 *v83; // r3
  idAnimator_AF::idAFJointMod *v84; // r28
  const idMat3 *v85; // r3
  double v86; // fp12
  idAnimator_AF::idAFJointMod *v87; // r11
  double v88; // fp9
  double v89; // fp11
  double v90; // fp10
  double v91; // fp8
  double v92; // fp5
  double v93; // fp4
  double v94; // fp3
  double v95; // fp2
  double v96; // fp1
  double v97; // fp27
  double v98; // fp7
  double v99; // fp26
  double v100; // fp25
  double v101; // fp24
  double v102; // fp13
  double v103; // fp6
  double v104; // fp1
  double v105; // fp23
  double v106; // fp22
  double v107; // fp21
  double v108; // fp5
  double v109; // fp4
  double v110; // fp20
  double v111; // fp9
  double v112; // fp5
  double v113; // fp3
  double v114; // fp2
  double v115; // fp0
  double v116; // fp12
  _DWORD back_chain[20]; // [sp+0h] [-240h]
  idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod> v119[3]; // [sp+50h] [-1F0h] BYREF
  int v120; // [sp+5Ch] [-1E4h] BYREF
  idMat3 v121; // [sp+60h] [-1E0h] BYREF
  idMat3 v122; // [sp+90h] [-1B0h] BYREF
  float x; // [sp+C0h] [-180h] BYREF
  float v124; // [sp+C4h] [-17Ch]
  float v125; // [sp+C8h] [-178h]
  idPLogScope v126; // [sp+D8h] [-168h] BYREF
  idMD6Blend::jointMod_t v127; // [sp+E0h] [-160h] BYREF
  idMat3 v128[3]; // [sp+120h] [-120h] BYREF

  if ( this->isLoaded )
  {
    if ( this->isActive || (v2 = 0, this->isClientAuthoritativeActive) )
      v2 = 1;
    if ( v2 != 0 )
    {
      p_physicsObj = &this->physicsObj;
      if ( !this->physicsObj.IsAtRest(this: &this->physicsObj) )
      {
        this->restStartTime = -1;
        goto LABEL_10;
      }
      if ( this->restStartTime <= 0 )
      {
        this->restStartTime = 1;
LABEL_10:
        RD_EventBegin(name: "idAnimator_AF::UpdateAnimation");
        LODWORD(v4) = "idAnimator_AF::UpdateAnimation";
        HIDWORD(v4) = 2;
        idPLogScope::idPLogScope(this: &v126, pl: &pLog, gMask: v4, label: v5);
        treeAnimator = this->treeAnimator;
        p_deferredOrigin = (idRenderModelParms *)&treeAnimator->deferredOrigin;
        if ( !treeAnimator->useDeferredPosition )
          p_deferredOrigin = &treeAnimator->g;
        y = p_deferredOrigin->origin.y;
        z = p_deferredOrigin->origin.z;
        useDeferredPosition = treeAnimator->useDeferredPosition;
        x = p_deferredOrigin->origin.x;
        p_deferredAxis = &treeAnimator->deferredAxis;
        v124 = y;
        v125 = z;
        if ( !useDeferredPosition )
          p_deferredAxis = &treeAnimator->g.axis;
        v13 = &v120;
        p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
        for ( i = 9; i != 0; --i )
          *++v13 = *++p_z;
        if ( af_useDeferred.valueInteger != 0 )
        {
          v16 = treeAnimator->g.axis.mat[0].x;
          v17 = treeAnimator->g.axis.mat[1].y;
          v18 = treeAnimator->g.axis.mat[2].z;
          v19 = treeAnimator->g.origin.x;
          v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&treeAnimator->g.axis.mat[1];
          v20 = treeAnimator->g.origin.y;
          v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&treeAnimator->g;
          v21 = treeAnimator->g.origin.z;
          v22 = treeAnimator->g.axis.mat[0].y;
          v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&treeAnimator->g.axis.mat[2];
          v23 = treeAnimator->g.axis.mat[0].z;
          v24 = treeAnimator->g.axis.mat[1].x;
          v25 = treeAnimator->g.axis.mat[1].z;
          v26 = treeAnimator->g.axis.mat[2].x;
          v27 = treeAnimator->g.axis.mat[2].y;
          v121.mat[0].x = v16;
          v121.mat[1].y = v17;
          v121.mat[2].z = v18;
        }
        else
        {
          v21 = v125;
          v20 = v124;
          v19 = x;
          v27 = v121.mat[2].y;
          v26 = v121.mat[2].x;
          v25 = v121.mat[1].z;
          v24 = v121.mat[1].x;
          v23 = v121.mat[0].z;
          v22 = v121.mat[0].y;
        }
        if ( this->modifiesOrigin )
        {
          v28 = (int)p_physicsObj->GetAxis(this: &this->physicsObj, a2: 0);
          p_pLog = &v126.pLog;
          v30 = (_DWORD *)(v28 - 4);
          for ( j = 9; j != 0; --j )
            *++p_pLog = (idPLog *)*++v30;
          v32 = p_physicsObj->GetOrigin(this: &this->physicsObj, a2: 0);
          v33 = this->baseAxis.mat[1].z;
          v34 = this->baseAxis.mat[0].z;
          v35 = this->baseAxis.mat[2].y;
          v36 = this->baseAxis.mat[1].y;
          v37 = this->baseAxis.mat[0].y;
          v38 = v32->x;
          v39 = this->baseAxis.mat[2].x;
          v40 = v32->y;
          v41 = this->baseAxis.mat[1].x;
          v42 = v32->z;
          v43 = this->baseAxis.mat[0].x;
          v122.mat[2].z = this->baseAxis.mat[2].z;
          v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&this->baseAxis;
          v122.mat[2].y = v33;
          x = v38;
          v122.mat[2].x = v34;
          v124 = v40;
          v122.mat[1].z = v35;
          v125 = v42;
          v122.mat[1].y = v36;
          v122.mat[1].x = v37;
          v122.mat[0].z = v39;
          v122.mat[0].y = v41;
          v122.mat[0].x = v43;
          v44 = idMat3::operator*(this: v128, result: &v122, a: (const idMat3 *)&v127);
          v27 = v44->mat[2].y;
          v45 = (float)(v44->mat[2].z * this->baseOrigin.z);
          v26 = v44->mat[2].x;
          v46 = (float)(v44->mat[2].y * this->baseOrigin.z);
          v47 = (float)(v44->mat[2].x * this->baseOrigin.z);
          v48 = this->baseOrigin.x;
          v22 = v44->mat[0].y;
          v23 = v44->mat[0].z;
          v49 = v44->mat[0].x;
          v121.mat[2].z = v44->mat[2].z;
          v121.mat[0].x = v49;
          v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&v44->mat[2];
          v25 = v44->mat[1].z;
          v24 = v44->mat[1].x;
          v21 = (float)(v125
                      - (float)((float)(v44->mat[1].z * this->baseOrigin.y)
                              + (float)((float)((float)v23 * (float)v48) + (float)v45)));
          v20 = (float)(v124
                      - (float)((float)(v44->mat[1].y * this->baseOrigin.y)
                              + (float)((float)((float)v22 * (float)v48) + (float)v46)));
          v19 = (float)(x
                      - (float)((float)(v44->mat[1].x * this->baseOrigin.y)
                              + (float)((float)((float)v48 * (float)v49) + (float)v47)));
          v121.mat[1].y = v44->mat[1].y;
        }
        modifiedAnim = this->modifiedAnim;
        v121.mat[0].y = v24;
        v121.mat[0].z = v26;
        v121.mat[1].z = v27;
        v121.mat[1].x = v22;
        v121.mat[2].x = v23;
        v121.mat[2].y = v25;
        if ( modifiedAnim == nullptr )
          idLib::Error(fmt: "AF '%s' has no animation to modify", this->afName.data);
        idMD6LeafPause::Init(
          this: &this->AFLeaf,
          anim: modifiedAnim,
          frame: 0.0,
          wrapMode: v6,
          weightGroup: MD6_WEIGHTGROUP_ALL);
        idMD6LeafPause::SetNumAnimMods(this: &this->AFLeaf, n: this->jointMods.num);
        Bounds = (float *)idAnimator_AF::GetBounds(this: (idAnimator_AF *)&x, result: (idBounds *)this);
        v52 = (float)(Bounds[3] + (float)5.0);
        v53 = (float)(Bounds[2] - (float)5.0);
        v54 = (float)(Bounds[1] - (float)5.0);
        v55 = Bounds[5];
        v56 = (float)(Bounds[4] + (float)5.0);
        this->AFLeaf.bounds.b[0].x = *Bounds - (float)5.0;
        this->AFLeaf.bounds.b[1].x = v52;
        v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&this->AFLeaf.bounds.b[1];
        this->AFLeaf.bounds.b[0].z = v53;
        this->AFLeaf.bounds.b[0].y = v54;
        this->AFLeaf.bounds.b[1].y = v56;
        this->AFLeaf.bounds.b[1].z = (float)v55 + (float)5.0;
        idMD6LeafPause::SetOverrideFrameBounds(this: &this->AFLeaf, set: true);
        v57 = 0;
        v58 = this->AFLeaf.currentDeferred + 1;
        this->AFLeaf.currentDeferred = v58;
        list = this->AFLeaf.animMods[v58 & 1].list;
        v119[0] = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>)this->jointMods.num;
        v59 = v119[0].__vftable;
        ((void (*)(void))RtlCheckStack12)();
        *(_DWORD *)((char *)back_chain + v61) = back_chain[0];
        memset(Dst: v119, Val: 0, Size: 4 * (_DWORD)v59);
        v62 = 0;
        v119[0].__vftable = v59;
        if ( (int)v59 > 0 )
        {
          v63 = 0;
          v64 = list;
          do
          {
            v65.logIndex = (unsigned __int16)this->jointMods.list[v63].jointIndex.value;
            if ( LOWORD(v65.logIndex) != 0 )
            {
              v66 = 0;
              if ( v57 <= 0 )
                goto LABEL_35;
              v67 = v119;
              p_joint = &list->joint;
              while ( p_joint->value != SLOWORD(v65.logIndex) || v67->__vftable != nullptr )
              {
                ++v66;
                p_joint += 32;
                ++v67;
                if ( v66 >= v57 )
                  goto LABEL_35;
              }
              v119[v66].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)1;
              if ( v66 >= v57 )
              {
LABEL_35:
                v127.flags = 0;
                v69 = &v126;
                v127.joint.value = -1;
                v65.pLog = nullptr;
                for ( k = 6; k != 0; --k )
                  *++v69 = v65;
                v127.s[2] = 0.0;
                v127.joint.value = v65.logIndex;
                v127.s[1] = 0.0;
                v127.s[0] = 0.0;
                v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&idSearch_JointMod::`vftable';
                v66 = idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>::Search_FirstGreater(
                        this: v119,
                        base: list,
                        num: v57,
                        value: &v127);
                if ( v57 > v66 )
                {
                  v71 = v64;
                  v72 = v57 - v66;
                  do
                  {
                    v73 = (_QWORD *)&v71[-1].s[2];
                    v74 = (_QWORD *)&v71[-2].s[2];
                    for ( m = 8; m != 0; --m )
                    {
                      v76 = *++v74;
                      *++v73 = *v74;
                    }
                    --v72;
                    v71 = (idMD6Blend::jointMod_t *)HIDWORD(v76);
                  }
                  while ( v72 != 0 );
                }
                v77 = (_QWORD *)&list[v66 - 1].s[2];
                HIDWORD(v78) = &v126;
                for ( n = 8; n != 0; --n )
                {
                  v78 = *(_QWORD *)(HIDWORD(v78) + 8);
                  *++v77 = v78;
                }
                ++v57;
                ++v64;
                v119[v66].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)1;
              }
              v80 = &list[v66];
              v80->flags = 33;
              jointMod = this->jointMods.list[v63].jointMod;
              switch ( jointMod )
              {
                case AF_JOINTMOD_AXIS:
                  v80->flags = 35;
                  break;
                case AF_JOINTMOD_ORIGIN:
                  v80->flags = 41;
                  break;
                case AF_JOINTMOD_BOTH:
                  v80->flags = 43;
                  break;
                default:
                  break;
              }
              v82 = (float *)p_physicsObj->GetOrigin(this: &this->physicsObj, a2: this->jointMods.list[v63].bodyId);
              v83 = (idMat3 *)p_physicsObj->GetAxis(this: &this->physicsObj, a2: this->jointMods.list[v63].bodyId);
              v84 = &this->jointMods.list[v63];
              v85 = idMat3::operator*(this: v128, result: v83, a: &v121);
              idMat3::TransposeMultiply(this: &v122, result: &v84->jointBodyAxis, b: v85);
              v86 = v122.mat[2].y;
              v87 = &this->jointMods.list[v63];
              v88 = v122.mat[0].y;
              v89 = v122.mat[2].z;
              v90 = v122.mat[2].x;
              v91 = v122.mat[1].y;
              v119[0].__vftable = (idSearch_Binary<idMD6Blend::jointMod_t,idSearch_JointMod>_vtbl *)&v87->jointBodyOrigin;
              v92 = v87->jointBodyOrigin.z;
              v93 = (float)(v122.mat[2].y * v87->jointBodyOrigin.z);
              v94 = v87->jointBodyOrigin.y;
              v95 = v87->jointBodyOrigin.x;
              v96 = (float)(v122.mat[1].x * v87->jointBodyOrigin.y);
              v97 = (float)(v87->jointBodyOrigin.z * v122.mat[2].z);
              v98 = v122.mat[0].z;
              v99 = v82[1];
              v100 = *v82;
              v101 = v82[2];
              v102 = v122.mat[0].x;
              v80->mat[1] = v122.mat[1].x;
              v103 = v122.mat[1].z;
              v80->mat[0] = v102;
              v80->mat[10] = v89;
              v104 = (float)((float)((float)v90 * (float)v92) + (float)v96);
              v105 = v121.mat[1].x;
              v80->mat[2] = v90;
              v80->mat[5] = v91;
              v80->mat[6] = v86;
              v106 = v121.mat[1].z;
              v107 = v121.mat[1].y;
              v108 = v121.mat[0].x;
              v80->mat[4] = v88;
              v80->mat[8] = v98;
              v109 = (float)((float)((float)v91 * (float)v94) + (float)((float)((float)v95 * (float)v88) + (float)v93));
              v80->mat[9] = v103;
              v110 = v121.mat[0].z;
              v80->s[0] = 0.0;
              v80->s[1] = 0.0;
              v80->s[2] = 0.0;
              v111 = (float)((float)((float)v101
                                   - (float)((float)((float)v103 * (float)v94)
                                           + (float)((float)((float)v95 * (float)v98) + (float)v97)))
                           - (float)v21);
              v112 = (float)((float)((float)((float)((float)v100
                                                   - (float)((float)((float)v95 * (float)v102) + (float)v104))
                                           - (float)v19)
                                   * (float)v108)
                           + (float)((float)v105 * (float)((float)((float)v99 - (float)v109) - (float)v20)));
              v113 = (float)((float)((float)v110
                                   * (float)((float)((float)v100
                                                   - (float)((float)((float)v95 * (float)v102) + (float)v104))
                                           - (float)v19))
                           + (float)((float)v106 * (float)((float)((float)v99 - (float)v109) - (float)v20)));
              v114 = (float)((float)(v121.mat[0].y
                                   * (float)((float)((float)v100
                                                   - (float)((float)((float)v95 * (float)v102) + (float)v104))
                                           - (float)v19))
                           + (float)((float)v107 * (float)((float)((float)v99 - (float)v109) - (float)v20)));
              v115 = v121.mat[2].z;
              v116 = v121.mat[2].y;
              v80->mat[3] = (float)(v121.mat[2].x * (float)v111) + (float)v112;
              v80->mat[11] = (float)((float)v115 * (float)v111) + (float)v113;
              v80->mat[7] = (float)((float)v116 * (float)v111) + (float)v114;
            }
            ++v62;
            ++v63;
          }
          while ( v62 < this->jointMods.num );
        }
        idPLogScope::~idPLogScope(this: &v126);
        RD_EventEnd();
        return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// $LN409
// EA  : 0x826CDEFC
// RVA : 0x006CDEFC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _LN409()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 576 + 324));
}


// ========================================================================
// __unwind$256628
// EA  : 0x826CDF24
// RVA : 0x006CDF24
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_256628()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 576 + 216));
}


// ========================================================================
// ?SetupPose@idAnimator_AF@@IAAXPBVidJointMat@@H@Z
// EA  : 0x826CDF58
// RVA : 0x006CDF58
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::SetupPose(idAnimator_AF *this, const idJointMat *joints, int time)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  BOOL isRunningPhysics; // r11
  idTreeAnimator *treeAnimator; // r11
  float *p_x; // r24
  idMat3 *p_deferredAxis; // r29
  float *v12; // r26
  int v13; // r25
  int v14; // r28
  double v15; // fp0
  double v16; // fp13
  idAnimator_AF::idAFJointMod *v17; // r30
  double v18; // fp12
  const idJointMat *v19; // r11
  double v20; // fp31
  double v21; // fp25
  double v22; // fp24
  double v23; // fp28
  double v24; // fp30
  double v25; // fp23
  double v26; // fp27
  double v27; // fp26
  double v28; // fp29
  double v29; // fp19
  double v30; // fp21
  double v31; // fp20
  double v32; // fp29
  double v33; // fp9
  double v34; // fp1
  double v35; // fp0
  idMat3 *v36; // r3
  idAFBody *Body; // r30
  idPLogScope v38; // [sp+58h] [-178h] BYREF
  idMat3 v39; // [sp+60h] [-170h] BYREF
  idVec3 v40; // [sp+88h] [-148h] BYREF
  idMat3 v41; // [sp+A0h] [-130h] BYREF
  idMat3 v42[4]; // [sp+D0h] [-100h] BYREF

  RD_EventBegin(name: "idAnimator_AF::SetupPose");
  LODWORD(v6) = "idAnimator_AF::SetupPose";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v38, pl: &pLog, gMask: v6, label: v7);
  if ( this->isLoaded && this->poseTime != time )
  {
    isRunningPhysics = this->isRunningPhysics;
    this->poseTime = time;
    if ( !isRunningPhysics )
    {
      treeAnimator = this->treeAnimator;
      p_x = &treeAnimator->deferredOrigin.x;
      if ( !treeAnimator->useDeferredPosition )
        p_x = &treeAnimator->g.origin.x;
      p_deferredAxis = &treeAnimator->deferredAxis;
      if ( !treeAnimator->useDeferredPosition )
        p_deferredAxis = &treeAnimator->g.axis;
      v12 = &treeAnimator->g.scale.x;
      v13 = 0;
      if ( this->jointMods.num > 0 )
      {
        v14 = 0;
        do
        {
          v15 = *v12;
          v16 = v12[1];
          v17 = &this->jointMods.list[v14];
          v18 = v12[2];
          v19 = &joints[v17->jointIndex.value];
          v20 = v19->mat[10];
          v21 = v19->mat[6];
          v22 = v19->mat[2];
          v23 = v19->mat[9];
          v24 = v19->mat[5];
          v25 = v19->mat[1];
          v26 = v19->mat[8];
          v27 = v19->mat[4];
          v28 = v19->mat[0];
          v39.mat[2].z = v19->mat[10];
          v39.mat[2].y = v21;
          v39.mat[2].x = v22;
          v39.mat[1].z = v23;
          v39.mat[1].y = v24;
          v39.mat[1].x = v25;
          v39.mat[0].z = v26;
          v39.mat[0].x = v28;
          v39.mat[0].y = v27;
          v29 = (float)(v19->mat[3] * (float)v15);
          v30 = (float)((float)v18 * v19->mat[11]);
          v31 = (float)((float)v16 * v19->mat[7]);
          if ( (unsigned __int8)idMat3::Compare(this: &v39, a: &mat3_zero, epsilon: 0.1) != 0 )
          {
            v39.mat[2].z = 1.0;
            v20 = 1.0;
            v39.mat[1].y = 1.0;
            v24 = 1.0;
            v39.mat[0].x = 1.0;
            v28 = 1.0;
            v39.mat[1].z = 0.0;
            v23 = 0.0;
            v39.mat[0].z = 0.0;
            v26 = 0.0;
            v39.mat[0].y = 0.0;
            v27 = 0.0;
            v39.mat[2].y = 0.0;
            v21 = 0.0;
            v39.mat[2].x = 0.0;
            v22 = 0.0;
            v39.mat[1].x = 0.0;
            v25 = 0.0;
          }
          v33 = (float)((float)((float)(v17->jointBodyOrigin.z * (float)v22)
                              + (float)((float)(v17->jointBodyOrigin.x * (float)v28)
                                      + (float)(v17->jointBodyOrigin.y * (float)v25)))
                      + (float)v29);
          v34 = (float)((float)(p_deferredAxis->mat[1].x
                              * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v21)
                                              + (float)((float)(v17->jointBodyOrigin.x * (float)v27)
                                                      + (float)(v17->jointBodyOrigin.y * (float)v24)))
                                      + (float)v31))
                      + (float)((float)(p_deferredAxis->mat[0].x
                                      * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v22)
                                                      + (float)((float)(v17->jointBodyOrigin.x * (float)v28)
                                                              + (float)(v17->jointBodyOrigin.y * (float)v25)))
                                              + (float)v29))
                              + (float)((float)((float)((float)(v17->jointBodyOrigin.z * (float)v20)
                                                      + (float)((float)(v17->jointBodyOrigin.x * (float)v26)
                                                              + (float)(v17->jointBodyOrigin.y * (float)v23)))
                                              + (float)v30)
                                      * p_deferredAxis->mat[2].x)));
          v35 = (float)((float)((float)(p_deferredAxis->mat[1].z
                                      * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v21)
                                                      + (float)((float)(v17->jointBodyOrigin.x * (float)v27)
                                                              + (float)(v17->jointBodyOrigin.y * (float)v24)))
                                              + (float)v31))
                              + (float)((float)(p_deferredAxis->mat[2].z
                                              * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v20)
                                                              + (float)((float)(v17->jointBodyOrigin.x * (float)v26)
                                                                      + (float)(v17->jointBodyOrigin.y * (float)v23)))
                                                      + (float)v30))
                                      + (float)((float)((float)((float)(v17->jointBodyOrigin.z * (float)v22)
                                                              + (float)((float)(v17->jointBodyOrigin.x * (float)v28)
                                                                      + (float)(v17->jointBodyOrigin.y * (float)v25)))
                                                      + (float)v29)
                                              * p_deferredAxis->mat[0].z)))
                      + p_x[2]);
          v32 = *p_x;
          v40.y = p_x[1]
                + (float)((float)(p_deferredAxis->mat[1].y
                                * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v21)
                                                + (float)((float)(v17->jointBodyOrigin.x * (float)v27)
                                                        + (float)(v17->jointBodyOrigin.y * (float)v24)))
                                        + (float)v31))
                        + (float)((float)(p_deferredAxis->mat[0].y * (float)v33)
                                + (float)(p_deferredAxis->mat[2].y
                                        * (float)((float)((float)(v17->jointBodyOrigin.z * (float)v20)
                                                        + (float)((float)(v17->jointBodyOrigin.x * (float)v26)
                                                                + (float)(v17->jointBodyOrigin.y * (float)v23)))
                                                + (float)v30))));
          v40.z = v35;
          v40.x = (float)v32 + (float)v34;
          v36 = idMat3::operator*(this: v42, result: &v17->jointBodyAxis, a: &v39);
          idMat3::operator*(this: &v41, result: v36, a: p_deferredAxis);
          Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: this->jointMods.list[v14].bodyId);
          idClipModel::SetLinkedPosition(this: Body->clipModel, newOrigin: &v40, newAxis: &Body->clipModel->axis);
          idClipModel::SetLinkedPosition(this: Body->clipModel, newOrigin: &Body->clipModel->origin, newAxis: &v41);
          ++v13;
          ++v14;
        }
        while ( v13 < this->jointMods.num );
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v38);
  RD_EventEnd();
}


// ========================================================================
// __unwind$257572
// EA  : 0x826CE284
// RVA : 0x006CE284
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_257572()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 464 + 244));
}


// ========================================================================
// __unwind$257573
// EA  : 0x826CE2AC
// RVA : 0x006CE2AC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_257573()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 464 + 88));
}


// ========================================================================
// ?DrivePoseWithForces@idAnimator_AF@@IAAXXZ
// EA  : 0x826CE2E0
// RVA : 0x006CE2E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::DrivePoseWithForces(idAnimator_AF *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int GameMsPerFrame; // r3
  idTreeAnimator *treeAnimator; // r11
  float *p_x; // r26
  double valueFloat; // fp30
  double v8; // fp31
  float *p_deferredAxis; // r30
  int v10; // r27
  int v11; // r29
  idAFBody *Body; // r3
  idAnimator_AF::idAFJointMod *v13; // r11
  float *clipModel; // r10
  double z; // fp6
  double v16; // fp4
  double y; // fp7
  double x; // fp3
  double v19; // fp5
  double v20; // fp2
  float v21; // r8
  float v22; // r7
  double v23; // fp28
  double v24; // fp29
  double v25; // fp27
  double v26; // fp10
  double v27; // fp11
  double v28; // fp5
  double v29; // fp9
  double v30; // fp2
  double v31; // fp24
  double v32; // fp7
  double v33; // fp11
  double v34; // fp4
  double v35; // fp3
  double v36; // fp12
  double v37; // fp10
  double v38; // fp9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v40; // r30
  int v41; // r3
  __int64 totalTicks; // r11
  __int64 v43; // r9
  idPLogScope v44; // [sp+58h] [-F8h] BYREF
  float v45; // [sp+60h] [-F0h]
  float v46; // [sp+64h] [-ECh]
  float v47; // [sp+68h] [-E8h]
  idVec3 v48; // [sp+70h] [-E0h] BYREF
  idMat3 v49; // [sp+80h] [-D0h] BYREF

  RD_EventBegin(name: "idAnimator_AF::DrivePosWithForces");
  LODWORD(v2) = "idAnimator_AF::DrivePosWithForces";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v44, pl: &::pLog, gMask: v2, label: v3);
  if ( this->isLoaded )
  {
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                       this: this->gametimeManager.gameTimeManager,
                       type: GAMETIME_SCALED);
    treeAnimator = this->treeAnimator;
    p_x = &treeAnimator->deferredOrigin.x;
    valueFloat = af_forceScale.valueFloat;
    v8 = (float)((float)1.0 / (float)((float)__SPAIR64__(&unk_82390000, GameMsPerFrame) * (float)0.001));
    if ( !treeAnimator->useDeferredPosition )
      p_x = &treeAnimator->g.origin.x;
    p_deferredAxis = (float *)&treeAnimator->deferredAxis;
    if ( !treeAnimator->useDeferredPosition )
      p_deferredAxis = (float *)&treeAnimator->g.axis;
    v10 = 0;
    if ( this->jointMods.num > 0 )
    {
      v11 = 0;
      do
      {
        idTreeAnimator::GetModelSpaceJointTransform(
          this: this->treeAnimator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointMods.list[v11].jointIndex.value,
          origin: &v48,
          axis: &v49);
        Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: this->jointMods.list[v11].bodyId);
        v13 = &this->jointMods.list[v11];
        clipModel = (float *)Body->clipModel;
        ++v10;
        z = v13->jointBodyOrigin.z;
        v16 = (float)(v13->jointBodyOrigin.z * v49.mat[2].y);
        y = v13->jointBodyOrigin.y;
        x = v13->jointBodyOrigin.x;
        v19 = (float)(v13->jointBodyOrigin.y * v49.mat[1].z);
        v20 = (float)(v13->jointBodyOrigin.y * v49.mat[1].x);
        v21 = clipModel[10];
        v22 = clipModel[8];
        v23 = p_deferredAxis[5];
        v24 = p_deferredAxis[6];
        v46 = clipModel[9];
        v25 = p_deferredAxis[7];
        v47 = v21;
        v26 = p_deferredAxis[2];
        v27 = (float)((float)((float)x * v49.mat[0].z) + (float)v19);
        v28 = *p_deferredAxis;
        v29 = (float)((float)((float)z * v49.mat[2].x) + (float)v20);
        v30 = p_deferredAxis[1];
        v31 = p_deferredAxis[8];
        v45 = v22;
        v32 = (float)((float)((float)y * v49.mat[1].y) + (float)((float)((float)x * v49.mat[0].y) + (float)v16));
        v33 = (float)((float)((float)z * v49.mat[2].z) + (float)v27);
        v34 = Body->current.externalForce.p[0];
        ++v11;
        v36 = (float)((float)((float)((float)(p_x[2]
                                            + (float)((float)((float)(v48.z + (float)v33) * (float)v31)
                                                    + (float)((float)((float)v26
                                                                    * (float)((float)((float)((float)x * v49.mat[0].x)
                                                                                    + (float)v29)
                                                                            + v48.x))
                                                            + (float)((float)v23 * (float)(v48.y + (float)v32)))))
                                    - v21)
                            * (float)v8)
                    * (float)v8);
        v37 = (float)((float)((float)((float)((float)((float)((float)((float)((float)(p_deferredAxis[4]
                                                                                    * (float)(v48.y + (float)v32))
                                                                            + (float)((float)((float)((float)((float)((float)x * v49.mat[0].x) + (float)v29) + v48.x)
                                                                                            * (float)v30)
                                                                                    + (float)((float)(v48.z + (float)v33)
                                                                                            * (float)v25)))
                                                                    + p_x[1])
                                                            - v46)
                                                    * (float)v8)
                                            * (float)v8)
                                    * (float)valueFloat)
                            * Body->mass)
                    - Body->current.externalForce.p[1]);
        v38 = (float)((float)((float)((float)((float)((float)((float)(*p_x
                                                                    + (float)((float)(p_deferredAxis[3]
                                                                                    * (float)(v48.y + (float)v32))
                                                                            + (float)((float)((float)v28
                                                                                            * (float)((float)((float)((float)x * v49.mat[0].x) + (float)v29) + v48.x))
                                                                                    + (float)((float)v24
                                                                                            * (float)(v48.z + (float)v33)))))
                                                            - v22)
                                                    * (float)v8)
                                            * (float)v8)
                                    * (float)valueFloat)
                            * Body->mass)
                    - Body->current.externalForce.p[0]);
        v35 = Body->current.externalForce.p[1];
        Body->current.externalForce.p[2] = (float)((float)((float)((float)v36 * (float)valueFloat) * Body->mass)
                                                 - Body->current.externalForce.p[2])
                                         + Body->current.externalForce.p[2];
        Body->current.externalForce.p[1] = (float)v35 + (float)v37;
        Body->current.externalForce.p[0] = (float)v38 + (float)v34;
      }
      while ( v10 < this->jointMods.num );
    }
    if ( v44.logIndex >= 0 )
    {
      pLog = v44.pLog;
      v40 = &v44.pLog->logEntries.list[v44.logIndex];
      v41 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v40->totalTicks;
      HIDWORD(totalTicks) = v40->parent;
      LODWORD(v43) = v41 - totalTicks;
      v40->totalTicks = v43;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v44);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$257924
// EA  : 0x826CE5D4
// RVA : 0x006CE5D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_257924()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 164));
}


// ========================================================================
// __unwind$257925
// EA  : 0x826CE5FC
// RVA : 0x006CE5FC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_257925()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 88));
}


// ========================================================================
// ?TestSolid@idAnimator_AF@@QAA?AW4testSolidResult_t@1@_N@Z
// EA  : 0x826CE630
// RVA : 0x006CE630
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::TestSolid(idAnimator_AF *this, const bool clearClipMasksOfBodiesInSolids)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r21
  int i; // r27
  idAFBody *Body; // r3
  int clipMask; // r9
  idAFBody *v10; // r30
  idClipModel *clipModel; // r3
  double y; // fp6
  double x; // fp5
  double v14; // fp31
  idRenderWorld *v15; // r3
  idRenderWorld *v16; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 totalTicks; // r11
  __int64 v21; // r9
  const char *v23; // [sp+8h] [-1A8h]
  idPLogScope v24; // [sp+68h] [-148h] BYREF
  float v25[4]; // [sp+70h] [-140h] BYREF
  idVec3 v26; // [sp+80h] [-130h] BYREF
  trace_t v27; // [sp+90h] [-120h] BYREF
  int v28; // [sp+110h] [-A0h] BYREF

  RD_EventBegin(name: "idAnimator_AF::TestSolid");
  LODWORD(v4) = "idAnimator_AF::TestSolid";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v24, pl: &::pLog, gMask: v4, label: v5);
  if ( this->isLoaded && this->clip != nullptr )
  {
    v6 = 0;
    for ( i = 0; i < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)&this->physicsObj); ++i )
    {
      Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: i);
      v10 = Body;
      clipMask = Body->clipMask;
      if ( clipMask != 0 )
      {
        idClip::Contents(
          this: (idClip *)&v28,
          result: (idClipQuery *)this->clip,
          result: &v27,
          start: &Body->clipModel->origin,
          clipModel: Body->clipModel,
          startAxis: &Body->clipModel->axis,
          clipMask,
          passEntityNumber: this->physicsObj.entityNumber,
          userName: v23);
        if ( v27.fraction < 1.0 )
        {
          clipModel = v10->clipModel;
          y = clipModel->origin.y;
          x = clipModel->origin.x;
          v14 = __fabs((float)((float)((float)(v27.c.point.z * v27.c.normal.z)
                                     + (float)((float)(v27.c.point.y * v27.c.normal.y)
                                             + (float)(v27.c.point.x * v27.c.normal.x)))
                             - v27.c.dist));
          v26.z = clipModel->origin.z + (float)((float)((float)v14 + (float)8.0) * v27.c.normal.z);
          v26.y = (float)y + (float)((float)((float)v14 + (float)8.0) * v27.c.normal.y);
          v26.x = (float)x + (float)((float)((float)v14 + (float)8.0) * v27.c.normal.x);
          idClipModel::SetLinkedPosition(this: clipModel, newOrigin: &v26, newAxis: &clipModel->axis);
          if ( af_testSolidDebug.valueInteger != 0 )
            idLib::Warning(
              fmt: "idAnimator_AF::TestSolid: body '%s' stuck in %d (normal = %.2f %.2f %.2f, depth = %.2f)",
              v10->name.str,
              v27.c.normal.x,
              (unsigned int)COERCE_UNSIGNED_INT64(v27.c.normal.y),
              (unsigned int)COERCE_UNSIGNED_INT64(v27.c.normal.z),
              LODWORD(v14));
          if ( clearClipMasksOfBodiesInSolids
            && (*(_BYTE *)&v10->fl & 1) != 0
            && idPhysics_AF::AddNoclipBody(this: &this->physicsObj, bodyId: i) )
          {
            if ( v6 < 2 )
              v6 = 1;
          }
          else
          {
            v6 = 2;
            if ( af_testSolidDebug.valueInteger != 0 )
            {
              v15 = common->RW(this: common);
              v15->DebugPoint(this: v15, a2: (const idVec4 *)&idColor::colorRed, a3: &v27.c.point, a4: 5000, a5: false);
              v16 = common->RW(this: common);
              v25[2] = (float)(v27.c.normal.z * (float)20.0) + v27.c.point.z;
              v25[1] = v27.c.point.y + (float)(v27.c.normal.y * (float)20.0);
              v25[0] = (float)(v27.c.normal.x * (float)20.0) + v27.c.point.x;
              v16->DebugLine(
                this: v16,
                a2: (const idVec4 *)&idColor::colorYellow,
                a3: &v27.c.point,
                a4: (const idVec3 *)v25,
                a5: 5000,
                a6: false);
            }
          }
        }
      }
    }
    if ( v24.logIndex >= 0 )
    {
      pLog = v24.pLog;
      v18 = &v24.pLog->logEntries.list[v24.logIndex];
      v19 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v18->totalTicks;
      HIDWORD(totalTicks) = v18->parent;
      LODWORD(v21) = v19 - totalTicks;
      v18->totalTicks = v21;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return v6;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v24);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$258196
// EA  : 0x826CE97C
// RVA : 0x006CE97C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258196()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 280));
}


// ========================================================================
// __unwind$258197_0
// EA  : 0x826CE9A4
// RVA : 0x006CE9A4
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258197_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 104));
}


// ========================================================================
// ?Sync@idAnimator_AF@@QAAXH_N@Z
// EA  : 0x826CE9D8
// RVA : 0x006CE9D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::Sync(idAnimator_AF *this, int time, bool runPhysics)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r27
  int v9; // r28
  idAnimator_AF::idSyncConstraint *v10; // r5
  idAFConstraint *constraint; // r30
  const idDeclAF *storedDeclAF; // r11
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  idGameTimeManager *gameTimeManager; // r3
  idPhysics_AF *p_physicsObj; // r30
  idPhysics_AF_vtbl *v16; // r29
  int GameMsPerFrame; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v19; // r30
  int v20; // r3
  __int64 totalTicks; // r11
  __int64 v22; // r9
  int v23; // [sp+50h] [-B0h] BYREF
  idPLogScope v24; // [sp+58h] [-A8h] BYREF
  idVec3 v25; // [sp+60h] [-A0h] BYREF
  idMat3 v26[4]; // [sp+70h] [-90h] BYREF

  RD_EventBegin(name: "idAnimator_AF::Sync");
  LODWORD(v6) = "idAnimator_AF::Sync";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v24, pl: &::pLog, gMask: v6, label: v7);
  if ( this->isSyncing )
  {
    if ( this->physicsObj.IsAtRest(this: &this->physicsObj) )
      this->physicsObj.Activate(this: &this->physicsObj);
    idAnimator_AF::DrivePoseWithForces(this);
    v8 = 0;
    if ( this->syncConstraints.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->syncConstraints.list[v9];
        constraint = v10->constraint;
        if ( constraint->type == CONSTRAINT_BALLANDSOCKETJOINT )
        {
          if ( v10->jointHandle.value == 0xFFFF )
          {
            storedDeclAF = this->storedDeclAF;
            if ( storedDeclAF != nullptr )
              idLib::Warning(fmt: "Invalid syncConstraint in AF %s", storedDeclAF->name.str);
            else
              idLib::Warning(fmt: "Invalid syncConstraint in AF %s", "NULL");
          }
          else
          {
            JointIndex = idTreeAnimator::GetJointIndex(
                           this: (idTreeAnimator *)&v23,
                           result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                           jointHandle: &v10->jointHandle);
            if ( idTreeAnimator::GetWorldSpaceJointTransform(
                   this: this->treeAnimator,
                   pose: DRIVER_MODEL,
                   jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)JointIndex->value,
                   origin: &v25,
                   axis: v26) )
            {
              idAFConstraint_BallAndSocketJoint::SetWorldPosition(
                this: (idAFConstraint_BallAndSocketJoint *)constraint,
                worldPosition: &v25);
              idPhysics_AF::AddFrameConstraint(this: &this->physicsObj, constraint);
            }
            else
            {
              idLib::Warning(fmt: "Failed to add syncConstraint");
            }
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->syncConstraints.num );
    }
  }
  if ( this->isRunningPhysics && runPhysics )
  {
    gameTimeManager = this->gametimeManager.gameTimeManager;
    p_physicsObj = &this->physicsObj;
    v16 = this->physicsObj.__vftable;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: gameTimeManager, type: GAMETIME_SCALED);
    v16->Evaluate(this: p_physicsObj, a2: GameMsPerFrame, a3: time);
    p_physicsObj->EnableClip(this: p_physicsObj);
  }
  if ( v24.logIndex >= 0 )
  {
    pLog = v24.pLog;
    v19 = &v24.pLog->logEntries.list[v24.logIndex];
    v20 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v19->totalTicks;
    HIDWORD(totalTicks) = v19->parent;
    LODWORD(v22) = v20 - totalTicks;
    v19->totalTicks = v22;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$258551
// EA  : 0x826CEBE8
// RVA : 0x006CEBE8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258551()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 148));
}


// ========================================================================
// __unwind$258552
// EA  : 0x826CEC10
// RVA : 0x006CEC10
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258552()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?BreakConstraint@idAnimator_AF@@QAAXPBDABVidVec3@@@Z
// EA  : 0x826CEC40
// RVA : 0x006CEC40
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::BreakConstraint(idAnimator_AF *this, const char *constraintName, const idVec3 *impulse)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idAFConstraint *Constraint; // r29
  int BodyId; // r27
  int v10; // r3
  int v11; // r29
  int v12; // r8
  int v13; // r9
  idAnimator_AF::idAFJointMod *v14; // r10
  idAFBody *Body; // r3
  idPLogScope v16[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAnimator_AF::BreakConstraint");
  LODWORD(v6) = "idAnimator_AF::BreakConstraint";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v6, label: v7);
  if ( !this->isLoaded || !this->canDeattachBones || constraintName == nullptr )
    goto _M258690;
  Constraint = idPhysics_AF::GetConstraint(this: &this->physicsObj, constraintName);
  if ( Constraint == nullptr )
  {
    idLib::Warning(
      fmt: "%s: could not find constraint %s for %s",
      "idAnimator_AF::BreakConstraint",
      constraintName,
      "<unknown>");
    idPLogScope::~idPLogScope(this: v16);
    goto LABEL_16;
  }
  BodyId = idPhysics_AF::GetBodyId(this: &this->physicsObj, body: Constraint->body1);
  v10 = idPhysics_AF::GetBodyId(this: &this->physicsObj, body: Constraint->body2);
  v11 = v10;
  if ( BodyId == -1 || v10 == -1 )
  {
_M258690:
    idPLogScope::~idPLogScope(this: v16);
    goto LABEL_16;
  }
  idPhysics_AF::DeleteConstraint(this: &this->physicsObj, constraintName);
  v12 = 0;
  if ( this->jointMods.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &this->jointMods.list[v13];
      if ( v14->bodyId == BodyId || v14->bodyId == v11 )
        v14->jointMod = AF_JOINTMOD_BOTH;
      ++v12;
      ++v13;
    }
    while ( v12 < this->jointMods.num );
  }
  Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: BodyId);
  this->physicsObj.ApplyImpulse(this: &this->physicsObj, a2: BodyId, a3: &Body->clipModel->origin, a4: impulse);
  idPLogScope::~idPLogScope(this: v16);
LABEL_16:
  RD_EventEnd();
}


// ========================================================================
// __unwind$258624
// EA  : 0x826CEDD0
// RVA : 0x006CEDD0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258624()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$258625
// EA  : 0x826CEDF8
// RVA : 0x006CEDF8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258625()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?UnattachBones@idAnimator_AF@@QAAXABVidVec3@@@Z
// EA  : 0x826CEE28
// RVA : 0x006CEE28
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimator_AF::UnattachBones(idAnimator_AF *this, const idVec3 *dir)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPhysics_AF *p_physicsObj; // r28
  int i; // r30
  int v8; // r30
  idAnimator_AF::idBindConstraint *list; // r3
  idAnimator_AF::idSyncConstraint *v10; // r4
  int v11; // r10
  int num; // r11
  int v13; // r11
  idAnimator_AF::idAFJointMod *v14; // r9
  int endTime; // r27
  __int64 v16; // r6 OVERLAPPED
  double y; // fp13
  double x; // fp0
  int v19; // r11
  int v20; // r7
  idAFBody *Body; // r3
  double mass; // fp8
  idAFBody *v23; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v25; // r30
  int v26; // r3
  __int64 totalTicks; // r11
  __int64 v28; // r9
  idPLogScope v29[2]; // [sp+58h] [-78h] BYREF
  float v30; // [sp+68h] [-68h] BYREF
  float v31; // [sp+6Ch] [-64h]
  float v32; // [sp+70h] [-60h]

  RD_EventBegin(name: "idAnimator_AF::UnattachBones");
  LODWORD(v4) = "idAnimator_AF::UnattachBones";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v29, pl: &::pLog, gMask: v4, label: v5);
  if ( this->isLoaded && this->canDeattachBones )
  {
    p_physicsObj = &this->physicsObj;
    for ( i = idPhysics_AF::GetNumConstraints(this: &this->physicsObj) - 1; i >= 0; --i )
      idPhysics_AF::DeleteConstraint(this: &this->physicsObj, id: i);
    v8 = 0;
    if ( this->bindConstraints.listStatic == 0 || this->bindConstraints.listStatic == 2 )
    {
      list = this->bindConstraints.list;
      if ( list != nullptr )
        idListArrayDelete<idAnimator_AF::idBindConstraint>(ptr: list, num: this->bindConstraints.size);
      this->bindConstraints.list = nullptr;
      this->bindConstraints.size = 0;
    }
    this->bindConstraints.num = 0;
    if ( this->syncConstraints.listStatic == 0 || this->syncConstraints.listStatic == 2 )
    {
      v10 = this->syncConstraints.list;
      if ( v10 != nullptr )
        idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
      this->syncConstraints.list = nullptr;
      this->syncConstraints.size = 0;
    }
    this->syncConstraints.num = 0;
    v11 = 0;
    num = this->jointMods.num;
    this->hasBindConstraints = false;
    if ( num > 0 )
    {
      v13 = 0;
      do
      {
        ++v11;
        v14 = &this->jointMods.list[v13++];
        v14->jointMod = AF_JOINTMOD_BOTH;
      }
      while ( v11 < this->jointMods.num );
    }
    endTime = this->physicsObj.endTime;
    if ( (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)&this->physicsObj) > 0 )
    {
      do
      {
        y = dir->y;
        x = dir->x;
        v19 = 1103515245 * endTime + 12345;
        v32 = (float)(dir->z + (float)0.80000001) * (float)50.0;
        endTime = 1103515245 * v19 + 12345;
        v20 = (v19 >> 16) & 0x7FFF;
        LODWORD(v16) = (endTime >> 16) & 0x7FFF;
        v29[1] = (idPLogScope)v16;
        v31 = (float)((float)((float)((float)*(__int64 *)((char *)&v16 - 4) * (float)0.000061037019) - (float)1.0)
                    + (float)y)
            * (float)50.0;
        v30 = (float)((float)x + (float)((float)((float)v16 * (float)0.000061037019) - (float)1.0)) * (float)50.0;
        Body = idPhysics_AF::GetBody(this: p_physicsObj, id: v8);
        mass = Body->mass;
        v30 = v30 * Body->mass;
        v31 = (float)mass * v31;
        v32 = v32 * (float)mass;
        v23 = idPhysics_AF::GetBody(this: p_physicsObj, id: v8);
        p_physicsObj->ApplyImpulse(this: p_physicsObj, a2: v8++, a3: &v23->clipModel->origin, a4: (const idVec3 *)&v30);
      }
      while ( v8 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)p_physicsObj) );
    }
    if ( v29[0].logIndex >= 0 )
    {
      pLog = v29[0].pLog;
      v25 = &v29[0].pLog->logEntries.list[v29[0].logIndex];
      v26 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v25->totalTicks;
      HIDWORD(totalTicks) = v25->parent;
      LODWORD(v28) = v26 - totalTicks;
      v25->totalTicks = v28;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v29);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$258711
// EA  : 0x826CF0EC
// RVA : 0x006CF0EC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258711()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 116));
}


// ========================================================================
// __unwind$258712
// EA  : 0x826CF114
// RVA : 0x006CF114
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258712()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_AF@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826CF148
// RVA : 0x006CF148
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::InternalPreBlendTree(
        idAnimator_AF *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  char v7; // r11
  idPLogScope v8[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idAnimator_AF::InternalPreBlendTree");
  LODWORD(v5) = "idAnimator_AF::InternalPreBlendTree";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v5, label: v6);
  this->mergeBranch->left = nullptr;
  if ( this->isActive || (v7 = 0, this->isClientAuthoritativeActive) )
    v7 = 1;
  if ( v7 != 0 )
  {
    idAnimator_AF::UpdateAnimation(this);
    this->mergeBranch->right = &this->AFLeaf;
  }
  else
  {
    this->mergeBranch->right = nullptr;
  }
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
}


// ========================================================================
// __unwind$258876
// EA  : 0x826CF1F0
// RVA : 0x006CF1F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258876()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$258877
// EA  : 0x826CF218
// RVA : 0x006CF218
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258877()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?AddConstraint@idAnimator_AF@@IAAXPBVidDeclAF_Constraint@@PAVidAFConstraint@@@Z
// EA  : 0x826CF2B8
// RVA : 0x006CF2B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::AddConstraint(idAnimator_AF *this, const idDeclAF_Constraint *fc, idAFConstraint *c)
{
  idAnimator_AF::idSyncConstraint *v4; // r29
  unsigned __int16 v5; // r8
  char v6; // [sp+50h] [-30h] BYREF

  if ( fc->syncConstraint )
  {
    v4 = idList<idAnimator_AF::idSyncConstraint,71>::Alloc(this: &this->syncConstraints);
    v5 = *(_WORD *)((int (__fastcall *)(char *))animation->FindJointHandle)(a1: &v6);
    v4->constraint = c;
    v4->jointHandle.value = v5;
  }
  else
  {
    idPhysics_AF::AddConstraint(this: &this->physicsObj, constraint: c);
  }
}


// ========================================================================
// ?LoadConstraint@idAnimator_AF@@IAA_NPBVidDeclAF_Constraint@@@Z
// EA  : 0x826CF338
// RVA : 0x006CF338
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::LoadConstraint(idAnimator_AF *this, const idDeclAF_Constraint *fc)
{
  idPhysics_AF *p_physicsObj; // r29
  idAFBody *Body; // r28
  idAFBody *v6; // r27
  idAFConstraint *v7; // r3
  idAFConstraint *v8; // r29
  idAFConstraint_Fixed *v9; // r3
  idAFConstraint_Fixed *v10; // r5
  idAFConstraint *Constraint; // r3
  idAFConstraint_BallAndSocketJoint *v12; // r29
  idAFConstraint_BallAndSocketJoint *v13; // r3
  idAFConstraint_BallAndSocketJoint *v14; // r5
  const idVec3 *v15; // r5
  idDeclAF_Constraint::afConstraintLimit_t limit; // r11
  const idVec3 *v17; // r6
  idAFConstraint *v18; // r3
  idAFConstraint_UniversalJoint *v19; // r29
  idAFConstraint_UniversalJoint *v20; // r3
  idAFConstraint_UniversalJoint *v21; // r5
  idDeclAF_Constraint::afConstraintLimit_t v22; // r11
  idAFConstraint *v23; // r3
  idAFConstraint_Hinge *v24; // r29
  idAFConstraint_Hinge *v25; // r3
  idAFConstraint_Hinge *v26; // r5
  idRotation *v27; // r3
  idRotation *v28; // r3
  const idVec3 *v29; // r5
  idAFConstraint *v30; // r3
  idAFConstraint_Slider *v31; // r29
  idAFConstraint_Slider *v32; // r3
  idAFConstraint_Slider *v33; // r5
  idAFConstraint_Slider *v34; // r29
  idAFConstraint *v35; // r3
  idAFConstraint_Spring *v36; // r29
  idAFConstraint_Spring *v37; // r3
  idAFConstraint_Spring *v38; // r5
  idRotation v40; // [sp+58h] [-178h] BYREF
  idAngles v41; // [sp+A0h] [-130h] BYREF
  idVec3 v42[3]; // [sp+ACh] [-124h] BYREF
  idAngles v43; // [sp+D0h] [-100h] BYREF
  idVec3 v44[3]; // [sp+DCh] [-F4h] BYREF
  idRotation v45; // [sp+100h] [-D0h] BYREF
  idRotation v46; // [sp+150h] [-80h] BYREF

  p_physicsObj = &this->physicsObj;
  Body = idPhysics_AF::GetBody(this: &this->physicsObj, bodyName: fc->body1.str);
  v6 = idPhysics_AF::GetBody(this: p_physicsObj, bodyName: fc->body2.str);
  if ( (unsigned int)(fc->type - 1) <= 5 )
  {
    switch ( fc->type )
    {
      case DECLAF_CONSTRAINT_BALLANDSOCKETJOINT:
        Constraint = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v12 = (idAFConstraint_BallAndSocketJoint *)Constraint;
        if ( Constraint != nullptr )
        {
          Constraint->SetBody1(this: Constraint, a2: Body);
          v12->SetBody2(this: v12, a2: v6);
        }
        else
        {
          v13 = (idAFConstraint_BallAndSocketJoint *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                       size: 0x200u,
                                                       tag: TAG_AF,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
          if ( v13 != nullptr )
            v14 = idAFConstraint_BallAndSocketJoint::idAFConstraint_BallAndSocketJoint(
                    this: v13,
                    name: fc->name.str,
                    body1: Body,
                    body2: v6);
          else
            v14 = nullptr;
          v12 = v14;
          idAnimator_AF::AddConstraint(this, fc, c: v14);
        }
        idAFConstraint_BallAndSocketJoint::SetAnchor(this: v12, worldPosition: &fc->anchor.vec);
        v12->friction = fc->friction;
        limit = fc->limit;
        if ( limit != LIMIT_CONE )
        {
          if ( limit == LIMIT_PYRAMID )
          {
            idVec3::ToAngles(this: &v40.origin, result: (idAngles *)&fc->limitAxis.vec);
            v40.origin.z = fc->limitAngles[2];
            idAngles::ToMat3(this: &v43, result: (idMat3 *)&v40);
            idAFConstraint_BallAndSocketJoint::SetPyramidLimit(
              this: v12,
              pyramidAxis: (const idVec3 *)&v43,
              baseAxis: v44,
              angle1: fc->limitAngles[0],
              angle2: fc->limitAngles[1],
              body1Axis: v17);
          }
          else
          {
            idAFConstraint_BallAndSocketJoint::SetNoLimit(this: v12);
          }
        }
        else
        {
          idAFConstraint_BallAndSocketJoint::SetConeLimit(
            this: v12,
            coneAxis: &fc->limitAxis.vec,
            coneAngle: fc->limitAngles[0],
            body1Axis: v15);
        }
        break;
      case DECLAF_CONSTRAINT_UNIVERSALJOINT:
        v18 = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v19 = (idAFConstraint_UniversalJoint *)v18;
        if ( v18 != nullptr )
        {
          v18->SetBody1(this: v18, a2: Body);
          v19->SetBody2(this: v19, a2: v6);
        }
        else
        {
          v20 = (idAFConstraint_UniversalJoint *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x230u,
                                                   tag: TAG_AF,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
          if ( v20 != nullptr )
            v21 = idAFConstraint_UniversalJoint::idAFConstraint_UniversalJoint(
                    this: v20,
                    name: fc->name.str,
                    body1: Body,
                    body2: v6);
          else
            v21 = nullptr;
          v19 = v21;
          idAnimator_AF::AddConstraint(this, fc, c: v21);
        }
        idAFConstraint_UniversalJoint::SetAnchor(this: v19, worldPosition: &fc->anchor.vec);
        idAFConstraint_UniversalJoint::SetShafts(
          this: v19,
          cardanShaft1: &fc->shaft[0].vec,
          cardanShaft2: &fc->shaft[1].vec);
        v19->friction = fc->friction;
        v22 = fc->limit;
        if ( v22 != LIMIT_CONE )
        {
          if ( v22 == LIMIT_PYRAMID )
          {
            idVec3::ToAngles(this: &v40.origin, result: (idAngles *)&fc->limitAxis.vec);
            v40.origin.z = fc->limitAngles[2];
            idAngles::ToMat3(this: &v41, result: (idMat3 *)&v40);
            idAFConstraint_UniversalJoint::SetPyramidLimit(
              this: v19,
              pyramidAxis: (const idVec3 *)&v41,
              baseAxis: v42,
              angle1: fc->limitAngles[0],
              angle2: fc->limitAngles[1]);
          }
          else
          {
            idAFConstraint_UniversalJoint::SetNoLimit(this: v19);
          }
        }
        else
        {
          idAFConstraint_UniversalJoint::SetConeLimit(
            this: v19,
            coneAxis: &fc->limitAxis.vec,
            coneAngle: fc->limitAngles[0]);
        }
        break;
      case DECLAF_CONSTRAINT_HINGE:
        v23 = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v24 = (idAFConstraint_Hinge *)v23;
        if ( v23 != nullptr )
        {
          v23->SetBody1(this: v23, a2: Body);
          v24->SetBody2(this: v24, a2: v6);
        }
        else
        {
          v25 = (idAFConstraint_Hinge *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x240u,
                                          tag: TAG_AF,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
          if ( v25 != nullptr )
            v26 = idAFConstraint_Hinge::idAFConstraint_Hinge(this: v25, name: fc->name.str, body1: Body, body2: v6);
          else
            v26 = nullptr;
          v24 = v26;
          idAnimator_AF::AddConstraint(this, fc, c: v26);
        }
        idAFConstraint_Hinge::SetAnchor(this: v24, worldPosition: &fc->anchor.vec);
        idAFConstraint_Hinge::SetAxis(this: v24, axis: &fc->axis.vec);
        v24->friction = fc->friction;
        if ( fc->limit != LIMIT_CONE )
        {
          idAFConstraint_Hinge::SetNoLimit(this: v24);
        }
        else
        {
          idVec3::OrthogonalBasis(this: &fc->axis.vec, left: (idVec3 *)&v40.axis.mat[1].z, up: &v40.origin);
          v27 = idRotation::idRotation(
                  this: &v45,
                  rotationOrigin: &vec3_origin,
                  rotationVec: &fc->axis.vec,
                  rotationAngle: fc->limitAngles[0]);
          idRotation::operator*(this: &v40, result: v27, v: (const idVec3 *)&v40.axis.mat[1].z);
          v40.vec.y = v40.origin.x;
          v40.vec.z = v40.origin.y;
          v40.angle = v40.origin.z;
          v28 = idRotation::idRotation(
                  this: &v46,
                  rotationOrigin: &vec3_origin,
                  rotationVec: &fc->axis.vec,
                  rotationAngle: fc->limitAngles[2]);
          idRotation::operator*(this: &v40, result: v28, v: (const idVec3 *)&v40.axis.mat[1].z);
          v40.axis.mat[0].y = v40.origin.x;
          v40.axis.mat[0].z = v40.origin.y;
          v40.axis.mat[1].x = v40.origin.z;
          idAFConstraint_Hinge::SetLimit(
            this: v24,
            axis: (const idVec3 *)&v40.vec.y,
            angle: fc->limitAngles[1],
            body1Axis: v29);
        }
        break;
      case DECLAF_CONSTRAINT_SLIDER:
        v30 = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v31 = (idAFConstraint_Slider *)v30;
        if ( v30 != nullptr )
        {
          v30->SetBody1(this: v30, a2: Body);
          v31->SetBody2(this: v31, a2: v6);
          idAFConstraint_Slider::SetAxis(this: v31, ax: &fc->axis.vec);
        }
        else
        {
          v32 = (idAFConstraint_Slider *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x210u,
                                           tag: TAG_AF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
          if ( v32 != nullptr )
            v33 = idAFConstraint_Slider::idAFConstraint_Slider(this: v32, name: fc->name.str, body1: Body, body2: v6);
          else
            v33 = nullptr;
          v34 = v33;
          idAnimator_AF::AddConstraint(this, fc, c: v33);
          idAFConstraint_Slider::SetAxis(this: v34, ax: &fc->axis.vec);
        }
        break;
      case DECLAF_CONSTRAINT_FIXED:
        v7 = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v8 = v7;
        if ( v7 != nullptr )
        {
          v7->SetBody1(this: v7, a2: Body);
          v8->SetBody2(this: v8, a2: v6);
        }
        else
        {
          v9 = (idAFConstraint_Fixed *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x210u,
                                         tag: TAG_AF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v9 != nullptr )
            v10 = idAFConstraint_Fixed::idAFConstraint_Fixed(this: v9, name: fc->name.str, body1: Body, body2: v6);
          else
            v10 = nullptr;
          idAnimator_AF::AddConstraint(this, fc, c: v10);
        }
        break;
      default:
        v35 = idPhysics_AF::GetConstraint(this: p_physicsObj, constraintName: fc->name.str);
        v36 = (idAFConstraint_Spring *)v35;
        if ( v35 != nullptr )
        {
          v35->SetBody1(this: v35, a2: Body);
          v36->SetBody2(this: v36, a2: v6);
        }
        else
        {
          v37 = (idAFConstraint_Spring *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x200u,
                                           tag: TAG_AF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
          if ( v37 != nullptr )
            v38 = idAFConstraint_Spring::idAFConstraint_Spring(this: v37, name: fc->name.str, body1: Body, body2: v6);
          else
            v38 = nullptr;
          v36 = v38;
          idAnimator_AF::AddConstraint(this, fc, c: v38);
        }
        idAFConstraint_Spring::SetAnchor(this: v36, worldAnchor1: &fc->anchor.vec, worldAnchor2: &fc->anchor2.vec);
        idAFConstraint_Spring::SetSpring(
          this: v36,
          stretch: fc->stretch,
          compress: fc->compress,
          damping: fc->damping,
          restLength: fc->restLength);
        idAFConstraint_Spring::SetLimit(this: v36, minLength: fc->minLength, maxLength: fc->maxLength);
        break;
    }
  }
  return 1;
}


// ========================================================================
// __unwind$258971
// EA  : 0x826CF9EC
// RVA : 0x006CF9EC
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258971()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$258972
// EA  : 0x826CFA18
// RVA : 0x006CFA18
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258972()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$258973
// EA  : 0x826CFA44
// RVA : 0x006CFA44
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258973()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$258974
// EA  : 0x826CFA70
// RVA : 0x006CFA70
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258974()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$258975
// EA  : 0x826CFA9C
// RVA : 0x006CFA9C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258975()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$258976
// EA  : 0x826CFAC8
// RVA : 0x006CFAC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_258976()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 464 + 80), tag: TAG_AF);
}


// ========================================================================
// ?InitAF@idAnimator_AF@@QAA_NPAVidAnimStack@@PAVidClip@@PAVidImpactManager@@PAVidSoundEmitter@@W4soundChannel_t@@ABVidVec3@@HPAVidPhysicsCallbacks@@@Z
// EA  : 0x826CFB00
// RVA : 0x006CFB00
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::InitAF(
        idAnimator_AF *this,
        idAnimStack *animStack,
        idClip *clip,
        idImpactManager *impactManager,
        idSoundEmitter *soundEmitter,
        soundChannel_t soundChannel,
        const idVec3 *gravityVector,
        int entityNumber,
        idPhysicsCallbacks *callback,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idPhysicsCallbacks *a28)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  int initCount; // r10
  idTreeAnimator *treeAnimator; // r11
  const idDeclAF *articulatedFigure; // r30
  const idMD6Alias *Alias; // r3
  const idMD6Skel *skeleton; // r11
  int v44; // r20
  idTreeAnimator *v45; // r3
  int v46; // r12
  idDeclMD6 *decl; // r26
  char v48; // r25
  const idVec3 *VisualOffset; // r3
  bool JointsForAnimTime; // r3
  const char *str; // r4
  idPhysics_AF *p_physicsObj; // r23
  signed int i; // r26
  idAFBody *Body; // r27
  int v55; // r28
  int v56; // r29
  int j; // r26
  idAFConstraint *Constraint; // r27
  int v59; // r28
  int v60; // r29
  unsigned int type; // r11
  int v62; // r11
  int v63; // r28
  int v64; // r29
  int v65; // r29
  int v66; // r28
  const char *JointName; // r3
  int v68; // r28
  int v69; // r29
  float v70; // r29
  int v71; // r30
  int v72; // r3
  __int64 v73; // r11
  __int64 v74; // r9
  _DWORD back_chain[20]; // [sp+0h] [-E0h]
  idJointMat v76; // [sp+50h] [-90h] BYREF

  RD_EventBegin(name: "idAnimator_AF::InitAF");
  LODWORD(v36) = "idAnimator_AF::InitAF";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v76.mat[2], pl: &pLog, gMask: v36, label: v37);
  initCount = this->initCount;
  this->clip = clip;
  this->impactMgr = impactManager;
  this->soundEmitter = soundEmitter;
  this->bounceChannel = soundChannel;
  treeAnimator = animStack->treeAnimator;
  this->treeAnimator = treeAnimator;
  this->initCount = initCount + 1;
  if ( treeAnimator != nullptr && (articulatedFigure = this->articulatedFigure) != nullptr )
  {
    Alias = idDeclMD6::FindAlias(this: treeAnimator->decl, aliasName: "misc/af_pose", includeInherited: true);
    if ( Alias != nullptr )
    {
      this->modifiedAnim = (const idMD6Anim *)idResourceList::Load(
                                                this: &idMD6Anim::resourceList,
                                                name: (char *)Alias->animRefs.list->str,
                                                makeDefault: true,
                                                skipStaleCheck: false);
    }
    else
    {
      skeleton = this->treeAnimator->decl->model->skeleton;
      if ( skeleton != nullptr )
        this->modifiedAnim = skeleton->defaultAnim;
      else
        this->modifiedAnim = nullptr;
    }
    v44 = idTreeAnimator::NumJoints(this: this->treeAnimator);
    ((void (*)(void))RtlCheckStack12)();
    v45 = this->treeAnimator;
    *(_DWORD *)((char *)back_chain + v46) = back_chain[0];
    decl = v45->decl;
    v48 = idTreeAnimator::GetRemoveOriginTranslation(ptr: v45);
    VisualOffset = idTreeAnimator::GetVisualOffset(this: this->treeAnimator);
    JointsForAnimTime = idDeclMD6::GetJointsForAnimTime(
                          this: decl,
                          joints: &v76,
                          anim: this->modifiedAnim,
                          timeMS: 0,
                          offset: VisualOffset,
                          removeOriginOffset: v48);
    str = articulatedFigure->name.str;
    if ( !JointsForAnimTime )
      idLib::Error(fmt: "Articulated figure '%s' is missing pose anim '%s'", str, this->modifiedAnim->name.str);
    idStr::operator=(this: &this->afName, text: str);
    if ( articulatedFigure->bodies.num != 0 )
    {
      p_physicsObj = &this->physicsObj;
      this->physicsCallbacks = a28;
      idPhysics::InitPhysics(
        this: &this->physicsObj.idPhysics_DynamicBase,
        clip_: clip,
        callbacks_: a28,
        entityNumber_: entityNumber);
      this->physicsObj.SetGravity(this: &this->physicsObj, a2: gravityVector);
      this->physicsObj.SetClipMask(this: &this->physicsObj, a2: articulatedFigure->clipMask, a3: -1);
      idPhysics_AF::SetDefaultFriction(
        this: &this->physicsObj,
        linear: articulatedFigure->defaultLinearFriction,
        angular: articulatedFigure->defaultAngularFriction,
        contact: articulatedFigure->defaultContactFriction);
      idPhysics_AF::SetSuspendSpeed(
        this: &this->physicsObj,
        velocity: &articulatedFigure->suspendVelocity,
        acceleration: &articulatedFigure->suspendAcceleration);
      idPhysics_AF::SetSuspendTolerance(
        this: &this->physicsObj,
        noMoveTime: articulatedFigure->noMoveTime,
        noMoveTranslation: articulatedFigure->noMoveTranslation,
        noMoveRotation: articulatedFigure->noMoveRotation);
      idPhysics_AF::SetSuspendTime(
        this: &this->physicsObj,
        minTime: articulatedFigure->minMoveTime,
        maxTime: articulatedFigure->maxMoveTime);
      this->physicsObj.selfCollision = articulatedFigure->selfCollision;
      idList<idAnimator_AF::idAFJointMod,71>::SetNum(this: &this->jointMods, newNum: 0);
      for ( i = 0;
            i < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)&this->physicsObj);
            ++i )
      {
        Body = idPhysics_AF::GetBody(this: &this->physicsObj, id: i);
        v55 = 0;
        if ( articulatedFigure->bodies.num > 0 )
        {
          v56 = 0;
          do
          {
            if ( idStr::Icmp(s1: articulatedFigure->bodies.list[v56]->name.str, s2: Body->name.str) == 0 )
              break;
            ++v55;
            ++v56;
          }
          while ( v55 < articulatedFigure->bodies.num );
        }
        if ( v55 >= articulatedFigure->bodies.num )
          idPhysics_AF::DeleteBody(this: &this->physicsObj, id: i--);
      }
      for ( j = 0; j < idPhysics_AF::GetNumConstraints(this: &this->physicsObj); ++j )
      {
        Constraint = idPhysics_AF::GetConstraint(this: &this->physicsObj, id: j);
        v59 = 0;
        if ( articulatedFigure->constraints.num > 0 )
        {
          v60 = 0;
          do
          {
            if ( idStr::Icmp(s1: articulatedFigure->constraints.list[v60]->name.str, s2: Constraint->name.str) == 0 )
            {
              type = articulatedFigure->constraints.list[v60]->type;
              if ( type <= 6 && type != 0 )
              {
                switch ( type )
                {
                  case 1u:
                    v62 = 1;
                    break;
                  case 2u:
                    v62 = 2;
                    break;
                  case 3u:
                    v62 = 3;
                    break;
                  case 4u:
                    v62 = 4;
                    break;
                  default:
                    v62 = type == 5 ? 6 : 10;
                    break;
                }
              }
              else
              {
                v62 = 0;
              }
              if ( v62 == Constraint->type )
                break;
            }
            ++v59;
            ++v60;
          }
          while ( v59 < articulatedFigure->constraints.num );
        }
        if ( v59 >= articulatedFigure->constraints.num )
          idPhysics_AF::DeleteConstraint(this: &this->physicsObj, id: j--);
      }
      articulatedFigure->Finish(
        this: articulatedFigure,
        a2: (bool (__fastcall *const)(void *, const idJointMat *, const char *, idVec3 *, idMat3 *))_idAnimator_AF::InitAF_::_39_::local_t::GetJointTransform,
        a3: &v76,
        a4: this->treeAnimator);
      v76.mat[0] = NAN;
      idList<idRenderModelCommitted *,5>::SetNum(
        this: (idList<int,5> *)&this->jointBody,
        newNum: v44,
        initValue: (const int *)&v76);
      v63 = 0;
      this->modifiesOrigin = false;
      if ( articulatedFigure->bodies.num > 0 )
      {
        v64 = 0;
        do
        {
          idAnimator_AF::LoadBody(
            this,
            fb: articulatedFigure->bodies.list[v64],
            joints: &v76,
            baseName: articulatedFigure->base.str,
            clipMaterial: articulatedFigure->clipMaterial);
          if ( articulatedFigure->bodies.list[v64]->jointName.str == articulatedFigure->base.str )
            this->modifiesOrigin = true;
          ++v63;
          ++v64;
        }
        while ( v63 < articulatedFigure->bodies.num );
      }
      if ( this->treeAnimator->decl->model == nullptr )
      {
        v65 = 0;
        if ( v44 > 0 )
        {
          v66 = 0;
          do
          {
            if ( this->jointBody.list[v66] == -1 )
            {
              JointName = idTreeAnimator::GetJointName(
                            this: this->treeAnimator,
                            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v65);
              idLib::Warning(
                fmt: "idAnimator_AF::InitAF: joint '%s' on articulated figure '%s' is not contained by a body",
                JointName,
                "<unknown>");
            }
            ++v65;
            ++v66;
          }
          while ( v65 < v44 );
        }
      }
      v68 = 0;
      if ( articulatedFigure->constraints.num > 0 )
      {
        v69 = 0;
        do
        {
          idAnimator_AF::LoadConstraint(this, fc: articulatedFigure->constraints.list[v69]);
          ++v68;
          ++v69;
        }
        while ( v68 < articulatedFigure->constraints.num );
      }
      idPhysics_AF::UpdateClipModels(this: &this->physicsObj);
      p_physicsObj->UnlinkClip(this: &this->physicsObj);
      this->physicsObj.changedAF = true;
      p_physicsObj->DisableClip(this: &this->physicsObj);
      this->isLoaded = true;
      LODWORD(v76.mat[1]) = (int)(float)(af_blendDuration.valueFloat * (float)1000.0);
      idAnimator_Base::Start(this, stack: animStack, curTime: 0, blendDurationMS: SLODWORD(v76.mat[1]), reset: true);
      if ( v76.mat[2] >= 0.0 )
      {
        v70 = v76.mat[3];
        v71 = 16 * LODWORD(v76.mat[2]) + *(_DWORD *)(LODWORD(v76.mat[3]) + 16);
        v72 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v73 = *(_QWORD *)(v71 + 8);
        HIDWORD(v73) = *(_DWORD *)(v71 + 4);
        LODWORD(v74) = v72 - v73;
        *(_QWORD *)(v71 + 8) = v74;
        *(_DWORD *)(LODWORD(v70) + 32) = HIDWORD(v73);
      }
      RD_EventEnd();
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "idAnimator_AF::InitAF: articulated figure '%s' has no bodies.", "<unknown>");
      idPLogScope::~idPLogScope(this: (idPLogScope *)&v76.mat[2]);
      RD_EventEnd();
      return 0;
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v76.mat[2]);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// $LN183
// EA  : 0x826D0154
// RVA : 0x006D0154
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _LN183()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$259212
// EA  : 0x826D017C
// RVA : 0x006D017C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_259212()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?SetupPose@idAnimator_AF@@IAAXH@Z
// EA  : 0x826D01A8
// RVA : 0x006D01A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::SetupPose(idAnimator_AF *this, int time)
{
  const idDeclAF *articulatedFigure; // r11
  double errorReduction; // fp0
  double errorReductionMax; // fp13
  const idDeclAF *v5; // r9
  double lcpEpsilon; // fp12
  const idDeclAF *v7; // r8
  double limitErrorReduction; // fp11
  const idDeclAF *v9; // r7
  double limitErrorReductionMax; // fp10
  const idDeclAF *v11; // r6
  double universalErrorReduction; // fp9
  double universalErrorReductionMax; // fp8
  const idDeclAF *v14; // r11
  double universalTorsionLcpEpsilon; // fp7

  articulatedFigure = this->articulatedFigure;
  if ( articulatedFigure != nullptr )
  {
    errorReduction = articulatedFigure->solverConstants.errorReduction;
    this->physicsObj.errorReduction.startValue = articulatedFigure->solverConstants.errorReduction;
    this->physicsObj.errorReduction.endValue = errorReduction;
    errorReductionMax = this->articulatedFigure->solverConstants.errorReductionMax;
    this->physicsObj.errorReductionMax.startValue = this->articulatedFigure->solverConstants.errorReductionMax;
    this->physicsObj.errorReductionMax.endValue = errorReductionMax;
    v5 = this->articulatedFigure;
    lcpEpsilon = v5->solverConstants.lcpEpsilon;
    this->physicsObj.lcpEpsilon.startValue = v5->solverConstants.lcpEpsilon;
    this->physicsObj.lcpEpsilon.endValue = lcpEpsilon;
    v7 = this->articulatedFigure;
    limitErrorReduction = v7->solverConstants.limitErrorReduction;
    this->physicsObj.limitErrorReduction.startValue = v7->solverConstants.limitErrorReduction;
    this->physicsObj.limitErrorReduction.endValue = limitErrorReduction;
    v9 = this->articulatedFigure;
    limitErrorReductionMax = v9->solverConstants.limitErrorReductionMax;
    this->physicsObj.limitErrorReductionMax.startValue = v9->solverConstants.limitErrorReductionMax;
    this->physicsObj.limitErrorReductionMax.endValue = limitErrorReductionMax;
    v11 = this->articulatedFigure;
    universalErrorReduction = v11->solverConstants.universalErrorReduction;
    this->physicsObj.universalErrorReduction.startValue = v11->solverConstants.universalErrorReduction;
    this->physicsObj.universalErrorReduction.endValue = universalErrorReduction;
    universalErrorReductionMax = this->articulatedFigure->solverConstants.universalErrorReductionMax;
    this->physicsObj.universalErrorReductionMax.startValue = this->articulatedFigure->solverConstants.universalErrorReductionMax;
    this->physicsObj.universalErrorReductionMax.endValue = universalErrorReductionMax;
    v14 = this->articulatedFigure;
    universalTorsionLcpEpsilon = v14->solverConstants.universalTorsionLcpEpsilon;
    this->physicsObj.universalTorsionLcpEpsilon.startValue = v14->solverConstants.universalTorsionLcpEpsilon;
    this->physicsObj.universalTorsionLcpEpsilon.endValue = universalTorsionLcpEpsilon;
    idAnimator_AF::SetupPose(this, joints: this->treeAnimator->joints[1], time);
  }
}


// ========================================================================
// ?ApplyImpulse@idAnimator_AF@@QAAXHHHABVidVec3@@0@Z
// EA  : 0x826D0248
// RVA : 0x006D0248
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::ApplyImpulse(
        idAnimator_AF *this,
        int curTime,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  if ( !this->isActive && this->lastImpulseTime < curTime )
  {
    idAnimator_AF::ZeroAllImpulses(this);
    this->numSerializedImpulses = 0;
  }
  idAnimator_AF::SetupPose(this, time: this->physicsObj.endTime);
  this->physicsObj.ApplyImpulse(this: &this->physicsObj, a2: bodyId, a3: point, a4: impulse);
  this->lastImpulseTime = curTime;
}


// ========================================================================
// ?ApplyForce@idAnimator_AF@@QAAXHHABVidVec3@@0@Z
// EA  : 0x826D02C8
// RVA : 0x006D02C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::ApplyForce(
        idAnimator_AF *this,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  idAnimator_AF::SetupPose(this, time: this->physicsObj.endTime);
  this->physicsObj.ApplyForce(this: &this->physicsObj, a2: bodyId, a3: point, a4: force);
}


// ========================================================================
// ?StartFromCurrentPose@idAnimator_AF@@QAA?AW4testSolidResult_t@1@H_N0ABVidVec3@@@Z
// EA  : 0x826D0320
// RVA : 0x006D0320
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

int __fastcall idAnimator_AF::StartFromCurrentPose(
        idAnimator_AF *this,
        int time,
        bool inheritAnimationVelocity_,
        bool inheritOverrideVelocity_,
        const idVec3 *overrideVelocity_)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  int v13; // r29
  idPLogScope v14[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAnimator_AF::StartFromCurrentPose");
  LODWORD(v10) = "idAnimator_AF::StartFromCurrentPose";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v10, label: v11);
  if ( this->isLoaded )
  {
    this->inheritAnimationVelocity = inheritAnimationVelocity_;
    this->inheritOverrideVelocity = inheritOverrideVelocity_;
    this->overrideVelocity.x = overrideVelocity_->x;
    this->overrideVelocity.y = overrideVelocity_->y;
    this->overrideVelocity.z = overrideVelocity_->z;
    if ( (this->inheritAnimationVelocity || this->inheritOverrideVelocity) && af_inheritVelocity.valueInteger != 0 )
    {
      this->physicsObj.PutToRest(this: &this->physicsObj);
      idAnimator_AF::SetupPose(this, time);
      if ( this->inheritAnimationVelocity )
      {
        idAnimator_AF::SetAnimationVelocities(this);
      }
      else if ( this->inheritOverrideVelocity )
      {
        idAnimator_AF::SetJointVelocities(this, originVel: &this->overrideVelocity);
      }
    }
    else
    {
      idAnimator_AF::SetupPose(this, time);
    }
    idPhysics_AF::UpdateClipModels(this: &this->physicsObj);
    v13 = idAnimator_AF::TestSolid(this, clearClipMasksOfBodiesInSolids: true);
    idAnimator_AF::Start(this);
    idAnimator_AF::UpdateAnimation(this);
    idPLogScope::~idPLogScope(this: v14);
    RD_EventEnd();
    return v13;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v14);
    RD_EventEnd();
    return 3;
  }
}


// ========================================================================
// __unwind$259592
// EA  : 0x826D047C
// RVA : 0x006D047C
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_259592()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$259593
// EA  : 0x826D04A4
// RVA : 0x006D04A4
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_259593()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_AF@@UAAXAAVidSerializer@@@Z
// EA  : 0x826D04D8
// RVA : 0x006D04D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::SerializeSnapshot(idAnimator_AF *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  int entityNumber; // r26
  int initCount; // r27
  idBitMsg *v7; // r3
  bool v8; // r9
  idAnimStack *animStack; // r10
  idTreeAnimator *treeAnimator; // r11
  double currentAlpha; // fp31
  idAnimatedEntityPhysicsCallbacksFake *v12; // r3
  idAnimatedEntityPhysicsCallbacksFake *v13; // r11
  idClip *clip; // r5
  idAnimStack *v15; // r4
  idAnimatedEntityPhysicsCallbacksFake *fakeCB; // r11
  bool isActive; // r28
  idBitMsg *v18; // r3
  idMD6Branch *mergeBranch; // r11
  idBitMsg *v20; // r3
  idMD6Branch *v21; // r11
  bool inheritAnimationVelocity; // r28
  idBitMsg *v23; // r3
  bool inheritOverrideVelocity; // r28
  idBitMsg *v25; // r3
  idPhysicsCallbacks *v26; // [sp+8h] [-F8h]
  int v27; // [sp+Ch] [-F4h]
  int v28; // [sp+10h] [-F0h]
  int v29; // [sp+14h] [-ECh]
  int v30; // [sp+18h] [-E8h]
  int v31; // [sp+1Ch] [-E4h]
  int v32; // [sp+20h] [-E0h]
  int v33; // [sp+24h] [-DCh]
  int v34; // [sp+28h] [-D8h]
  int v35; // [sp+2Ch] [-D4h]
  int v36; // [sp+30h] [-D0h]
  int v37; // [sp+34h] [-CCh]
  int v38; // [sp+38h] [-C8h]
  int v39; // [sp+3Ch] [-C4h]
  int v40; // [sp+40h] [-C0h]
  int v41; // [sp+44h] [-BCh]
  int v42; // [sp+48h] [-B8h]
  int v43; // [sp+4Ch] [-B4h]
  int v44; // [sp+50h] [-B0h]
  int v45; // [sp+60h] [-A0h]
  idVec3 v46; // [sp+68h] [-98h] BYREF
  idAnimatorParms_Base v47; // [sp+80h] [-80h] BYREF

  idSerializer::Serialize<idDeclAF>(this: ser, decl: &this->articulatedFigure);
  msg = ser->msg;
  entityNumber = this->physicsObj.entityNumber;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->physicsObj.entityNumber, numBits: 32);
  else
    entityNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
  initCount = this->initCount;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->initCount, numBits: 32);
  else
    this->initCount = idBitMsg::ReadBits(this: v7, numBits: 32);
  v8 = false;
  if ( !ser->writing )
  {
    animStack = this->serializeProps.animStack;
    if ( animStack != nullptr )
    {
      treeAnimator = this->treeAnimator;
      if ( treeAnimator != nullptr )
        v8 = animStack->treeAnimator != treeAnimator;
    }
  }
  currentAlpha = 0.0;
  if ( v8 || initCount < this->initCount )
  {
    idAnimator_AF::Shutdown(this);
    v47.animStack = this->serializeProps.animStack;
    idStr::idStr(this: &v47.name, text: "af");
    memset(&v47.originBlend, 0, 12);
    v47.blendOp = BOP_LERP;
    v47.alpha = 1.0;
    if ( initCount == 0 )
      idAnimator_Base::Init(this, gametimeManager: this->gametimeManager.gameTimeManager, parms: &v47);
    if ( this->fakeCB == nullptr )
    {
      v12 = (idAnimatedEntityPhysicsCallbacksFake *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                      size: 8u,
                                                      tag: TAG_AF,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
      if ( v12 != nullptr )
      {
        v12->af = nullptr;
        v13 = v12;
        v12->__vftable = (idAnimatedEntityPhysicsCallbacksFake_vtbl *)&idAnimatedEntityPhysicsCallbacksFake::`vftable';
      }
      else
      {
        v13 = nullptr;
      }
      this->fakeCB = v13;
    }
    this->fakeCB->af = this;
    clip = this->serializeProps.clip;
    v15 = this->serializeProps.animStack;
    fakeCB = this->fakeCB;
    v46.x = 0.0;
    v46.y = 0.0;
    v46.z = -1066.0;
    idAnimator_AF::InitAF(
      this,
      animStack: v15,
      clip,
      impactManager: nullptr,
      soundEmitter: nullptr,
      soundChannel: SND_CHANNEL_ANY,
      gravityVector: &v46,
      entityNumber,
      callback: v26,
      a10: v27,
      a11: v28,
      a12: v29,
      a13: v30,
      a14: v31,
      a15: v32,
      a16: v33,
      a17: v34,
      a18: v35,
      a19: v36,
      a20: v37,
      a21: v38,
      a22: v39,
      a23: v40,
      a24: v41,
      a25: v42,
      a26: v43,
      a27: v44,
      a28: fakeCB);
    idStr::FreeData(this: &v47.name);
  }
  isActive = this->isActive;
  v18 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v18, value: this->isActive, numBits: 1);
  else
    isActive = (_cntlzw(idBitMsg::ReadBits(this: v18, numBits: 1) - 1) & 0x20) != 0;
  mergeBranch = this->mergeBranch;
  this->isActive = isActive;
  if ( mergeBranch != nullptr )
    currentAlpha = mergeBranch->currentAlpha;
  v20 = ser->msg;
  if ( ser->writing )
  {
    *(float *)&v45 = currentAlpha;
    idBitMsg::WriteBits(this: v20, value: v45, numBits: 32);
  }
  else
  {
    currentAlpha = COERCE_FLOAT(idBitMsg::ReadBits(this: v20, numBits: 32));
  }
  v21 = this->mergeBranch;
  if ( v21 != nullptr )
    v21->currentAlpha = currentAlpha;
  inheritAnimationVelocity = this->inheritAnimationVelocity;
  v23 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v23, value: this->inheritAnimationVelocity, numBits: 1);
  else
    inheritAnimationVelocity = (_cntlzw(idBitMsg::ReadBits(this: v23, numBits: 1) - 1) & 0x20) != 0;
  this->inheritAnimationVelocity = inheritAnimationVelocity;
  inheritOverrideVelocity = this->inheritOverrideVelocity;
  v25 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v25, value: this->inheritOverrideVelocity, numBits: 1);
  else
    inheritOverrideVelocity = (_cntlzw(idBitMsg::ReadBits(this: v25, numBits: 1) - 1) & 0x20) != 0;
  this->inheritOverrideVelocity = inheritOverrideVelocity;
  idSerializer::Serialize(this: ser, value: &this->overrideVelocity);
}


// ========================================================================
// __unwind$259645
// EA  : 0x826D07E0
// RVA : 0x006D07E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void _unwind_259645()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 256 + 128));
}


// ========================================================================
// ?PreBlendSnapshot@idAnimator_AF@@UAAXPAVidAnimStack@@HHM@Z
// EA  : 0x826D0808
// RVA : 0x006D0808
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __fastcall idAnimator_AF::PreBlendSnapshot(
        idAnimator_AF *this,
        idAnimStack *stack,
        int curTime,
        const int ticksPerSec,
        double fraction)
{
  idMD6Branch *mergeBranch; // r11
  char v8; // r11
  idPhysics_AF_vtbl *v9; // r29
  int GameMsPerFrame; // r3
  BOOL isActive; // r11
  bool v12; // r11

  mergeBranch = this->mergeBranch;
  if ( mergeBranch != nullptr )
  {
    mergeBranch->left = nullptr;
    if ( this->isActive || (v8 = 0, this->isClientAuthoritativeActive) )
      v8 = 1;
    if ( v8 != 0 )
    {
      if ( !this->oldIsActive )
      {
        idAnimator_AF::StartFromCurrentPose(
          this,
          time: curTime,
          inheritAnimationVelocity_: this->inheritAnimationVelocity,
          inheritOverrideVelocity_: this->inheritOverrideVelocity,
          overrideVelocity_: &this->overrideVelocity);
        this->lastTime = curTime;
      }
      v9 = this->physicsObj.__vftable;
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                         this: this->gametimeManager.gameTimeManager,
                         type: GAMETIME_SCALED);
      v9->Evaluate(this: &this->physicsObj, a2: GameMsPerFrame, a3: curTime);
      idAnimator_AF::UpdateAnimation(this);
      this->mergeBranch->right = &this->AFLeaf;
    }
    else
    {
      if ( this->oldIsActive )
        idAnimator_AF::Stop(this);
      this->mergeBranch->right = nullptr;
    }
    isActive = this->isActive;
    this->numSerializedImpulses = 0;
    if ( isActive || (v12 = false, this->isClientAuthoritativeActive) )
      v12 = true;
    this->oldIsActive = v12;
  }
}


// ========================================================================
// `dynamic initializer for 'af_inheritVelocity''
// EA  : 0x8333EA58
// RVA : 0x0133EA58
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_inheritVelocity__()
{
  idCVar::idCVar(
    this: &af_inheritVelocity,
    name: "af_inheritVelocity",
    value: "1",
    flags: 1,
    description: "1 = allow ragdolls to inherit velocity from animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_inheritVelocity__);
}


// ========================================================================
// `dynamic initializer for 'af_forceScale''
// EA  : 0x8333EAB0
// RVA : 0x0133EAB0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_forceScale__()
{
  idCVar::idCVar(
    this: &af_forceScale,
    name: "af_forceScale",
    value: "0.3",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_forceScale__);
}


// ========================================================================
// `dynamic initializer for 'af_constraintRampDuration''
// EA  : 0x8333EB08
// RVA : 0x0133EB08
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_constraintRampDuration__()
{
  idCVar::idCVar(
    this: &af_constraintRampDuration,
    name: "af_constraintRampDuration",
    value: "500",
    flags: 2,
    description: "duration over which constraint tolerances will ramp back up to normal values after a sync to animation ends",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_constraintRampDuration__);
}


// ========================================================================
// `dynamic initializer for 'af_blendDuration''
// EA  : 0x8333EB60
// RVA : 0x0133EB60
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_blendDuration__()
{
  idCVar::idCVar(
    this: &af_blendDuration,
    name: "af_blendDuration",
    value: "0.2",
    flags: 4,
    description: "duration over which animation will blend into ragdoll once ragdoll is active",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_blendDuration__);
}


// ========================================================================
// `dynamic initializer for 'af_debugStartVelocity''
// EA  : 0x8333EBB8
// RVA : 0x0133EBB8
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_debugStartVelocity__()
{
  idCVar::idCVar(
    this: &af_debugStartVelocity,
    name: "af_debugStartVelocity",
    value: "0",
    flags: 1,
    description: "Debug starting velocity of ragdolls",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_debugStartVelocity__);
}


// ========================================================================
// `dynamic initializer for 'af_serializeDebug''
// EA  : 0x8333EC10
// RVA : 0x0133EC10
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_serializeDebug__()
{
  idCVar::idCVar(
    this: &af_serializeDebug,
    name: "af_serializeDebug",
    value: "0",
    flags: 1,
    description: "Debug AF serialization",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_serializeDebug__);
}


// ========================================================================
// `dynamic initializer for 'af_serializeImpulses''
// EA  : 0x8333EC68
// RVA : 0x0133EC68
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_serializeImpulses__()
{
  idCVar::idCVar(
    this: &af_serializeImpulses,
    name: "af_serializeImpulses",
    value: "1",
    flags: 1,
    description: "Debug AF serialization",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_serializeImpulses__);
}


// ========================================================================
// `dynamic initializer for 'af_testSolidDebug''
// EA  : 0x8333ECC0
// RVA : 0x0133ECC0
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_testSolidDebug__()
{
  idCVar::idCVar(
    this: &af_testSolidDebug,
    name: "af_testSolidDebug",
    value: "0",
    flags: 1,
    description: "Debug AF solid testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_testSolidDebug__);
}


// ========================================================================
// `dynamic initializer for 'af_useDeferred''
// EA  : 0x8333ED18
// RVA : 0x0133ED18
// PDB : w:\tech5\engine\gamelib\animstack\animator_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_useDeferred__()
{
  idCVar::idCVar(
    this: &af_useDeferred,
    name: "af_useDeferred",
    value: "0",
    flags: 1,
    description: "Debug AF solid testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_useDeferred__);
}

