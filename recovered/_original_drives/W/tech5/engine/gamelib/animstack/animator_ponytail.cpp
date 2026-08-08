
// ========================================================================
// ?InternalIsContributing@idAnimator_Ponytail@@MBA_NXZ
// EA  : 0x826E8EC8
// RVA : 0x006E8EC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

BOOL __fastcall idAnimator_Ponytail::InternalIsContributing(idAnimator_Ponytail *this)
{
  return this->isInitialized;
}


// ========================================================================
// ?GetCooldown@idVehicle_BoostExtender@@UBAHXZ
// EA  : 0x826E8ED0
// RVA : 0x006E8ED0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

const idMD6Branch *__fastcall idVehicle_BoostExtender::GetCooldown(idAnimator_Ponytail *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?InternalShutdown@idAnimator_Ponytail@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826E8F88
// RVA : 0x006E8F88
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __fastcall idAnimator_Ponytail::InternalShutdown(idAnimator_Ponytail *this, idAnimStack *animStack)
{
  idMD6BlockAlloc *p_md6Allocator; // r30

  p_md6Allocator = &animStack->md6Allocator;
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->mergeBranch = nullptr;
  }
  if ( this->lerpBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->lerpBranch = nullptr;
  }
  if ( this->pauseLeaf != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->pauseLeaf = nullptr;
  }
  if ( this->playLeaf != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))p_md6Allocator->Free)(a1: p_md6Allocator);
    this->playLeaf = nullptr;
  }
}


// ========================================================================
// DebugPoint
// EA  : 0x826E9038
// RVA : 0x006E9038
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __fastcall DebugPoint(
        const idVec4 *color,
        const idVec3 *point,
        double scale,
        const int time,
        int depthTest,
        BOOL a6)
{
  idRenderWorld *v11; // r3
  double y; // fp13
  double z; // fp11
  double v14; // fp10
  idRenderWorld *v15; // r3
  double x; // fp8
  double v17; // fp6
  double v18; // fp5
  idRenderWorld *v19; // r3
  double v20; // fp3
  double v21; // fp2
  double v22; // fp1
  double v23; // fp0
  float v24[4]; // [sp+50h] [-A0h] BYREF
  float v25[4]; // [sp+60h] [-90h] BYREF
  float v26[4]; // [sp+70h] [-80h] BYREF
  float v27[4]; // [sp+80h] [-70h] BYREF
  float v28[4]; // [sp+90h] [-60h] BYREF
  float v29[6]; // [sp+A0h] [-50h] BYREF

  v11 = common->RW(this: common);
  y = point->y;
  z = point->z;
  v14 = (float)(point->x - (float)scale);
  v24[0] = point->x + (float)scale;
  v24[1] = y;
  v24[2] = z;
  v25[0] = v14;
  v25[1] = y;
  v25[2] = z;
  v11->DebugLine(this: v11, a2: color, a3: (const idVec3 *)v25, a4: (const idVec3 *)v24, a5: depthTest, a6);
  v15 = common->RW(this: common);
  x = point->x;
  v17 = point->z;
  v18 = (float)(point->y - (float)scale);
  v26[1] = point->y + (float)scale;
  v26[0] = x;
  v26[2] = v17;
  v27[0] = x;
  v27[1] = v18;
  v27[2] = v17;
  v15->DebugLine(this: v15, a2: color, a3: (const idVec3 *)v27, a4: (const idVec3 *)v26, a5: depthTest, a6);
  v19 = common->RW(this: common);
  v20 = point->x;
  v21 = (float)(point->z + (float)scale);
  v22 = point->y;
  v23 = (float)(point->z - (float)scale);
  v28[1] = point->y;
  v28[0] = v20;
  v28[2] = v21;
  v29[0] = v20;
  v29[1] = v22;
  v29[2] = v23;
  v19->DebugLine(this: v19, a2: color, a3: (const idVec3 *)v29, a4: (const idVec3 *)v28, a5: depthTest, a6);
}


// ========================================================================
// ??0idAnimator_Ponytail@@QAA@XZ
// EA  : 0x826E97C0
// RVA : 0x006E97C0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

idAnimator_Ponytail *__fastcall idAnimator_Ponytail::idAnimator_Ponytail(idAnimator_Ponytail *this)
{
  idAnimator_Base::idAnimator_Base(this);
  this->declPonytail = nullptr;
  this->__vftable = (idAnimator_Ponytail_vtbl *)&idAnimator_Ponytail::`vftable';
  this->parentAnimator = nullptr;
  this->joints.list = nullptr;
  this->joints.granularity = 0;
  this->joints.memTag = 30;
  this->joints.listStatic = 0;
  this->joints.size = 0;
  this->joints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  this->mergeBranch = nullptr;
  this->pauseLeaf = nullptr;
  this->playLeaf = nullptr;
  this->lerpBranch = nullptr;
  this->segments.list = nullptr;
  this->segments.granularity = 0;
  this->segments.memTag = 30;
  this->segments.listStatic = 0;
  this->segments.size = 0;
  this->segments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->segments);
  this->ptEndSpring.restLength = 0.0;
  this->ptEndSpring.k = 1.0;
  this->ptEndSpring.m = 1.0;
  this->ptEndSpring.c = 2.0;
  this->ptEndSpring.p0.z = 0.0;
  this->ptEndSpring.p0.y = 0.0;
  this->ptEndSpring.p0.x = 0.0;
  this->ptEndSpring.p1.z = 0.0;
  this->ptEndSpring.p1.y = 0.0;
  this->ptEndSpring.p1.x = 0.0;
  this->ptEndSpring.vel.z = 0.0;
  this->ptEndSpring.vel.y = 0.0;
  this->ptEndSpring.vel.x = 0.0;
  this->ptEndSpring.maxSpeed = 0.0;
  this->ptEndSpring.pMin.z = 0.0;
  this->ptEndSpring.pMin.y = 0.0;
  this->ptEndSpring.pMin.x = 0.0;
  this->ptEndSpring.hasPMin = false;
  this->ptEndSpring.pMax.z = 0.0;
  this->ptEndSpring.pMax.y = 0.0;
  this->ptEndSpring.pMax.x = 0.0;
  this->ptEndSpring.hasPMax = false;
  this->isInitialized = false;
  return this;
}


// ========================================================================
// __unwind$248279
// EA  : 0x826E98EC
// RVA : 0x006E98EC
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248279()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$248280
// EA  : 0x826E9914
// RVA : 0x006E9914
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248280()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ??1idAnimator_Ponytail@@UAA@XZ
// EA  : 0x826E9948
// RVA : 0x006E9948
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __fastcall idAnimator_Ponytail::~idAnimator_Ponytail(idAnimator_Ponytail *this)
{
  idList<idIndex<short,enum invalidJointIndex_t>,30> *p_joints; // r29

  this->__vftable = (idAnimator_Ponytail_vtbl *)&idAnimator_Ponytail::`vftable';
  p_joints = &this->joints;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->segments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->segments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_joints);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$248420
// EA  : 0x826E99A4
// RVA : 0x006E99A4
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248420()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$248421
// EA  : 0x826E99CC
// RVA : 0x006E99CC
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248421()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$248422
// EA  : 0x826E99F8
// RVA : 0x006E99F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248422()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 80));
}


// ========================================================================
// ?InternalInit@idAnimator_Ponytail@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E9C78
// RVA : 0x006E9C78
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

int __fastcall idAnimator_Ponytail::InternalInit(idAnimator_Ponytail *this, const idAnimatorParms_Base *parms)
{
  idMD6LeafPause *v4; // r3
  idMD6Leaf::wrapMode_t v5; // r5
  idMD6Leaf::wrapMode_t v6; // r8
  idMD6LeafPlay *v7; // r3
  int v8; // r28
  const idMD6Anim *defaultAnim; // r4
  const idMD6Skel *skeleton; // r11
  idMD6Branch *v11; // r3
  idMD6LeafPause *pauseLeaf; // r5
  idMD6LeafPlay *playLeaf; // r4
  idMD6Branch::blendType_t v14; // r9
  md6WeightGroup_t v15; // r8
  idMD6Branch *v16; // r3
  idMD6Branch *lerpBranch; // r6
  const idDeclPonytail *animStack; // r5
  int num; // r29
  int size; // r11
  const idDeclPonytail *declPonytail; // r11
  int v22; // r31
  idIndex<short,enum invalidJointIndex_t> *treeAnimator; // r20
  int v24; // r11
  int v25; // r26
  int v26; // r27
  idDeclPonytail::idPonytailJointInfo *v27; // r25
  idPonytailSegment *v28; // r31
  idIndex<short,enum invalidJointIndex_t> *v29; // r31
  char v31; // [sp+60h] [-120h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v32; // [sp+64h] [-11Ch] BYREF
  idVec3 v33; // [sp+68h] [-118h] BYREF
  idConeConstraint_Quat v34; // [sp+80h] [-100h] BYREF
  idPonytailSegment v35; // [sp+B0h] [-D0h] BYREF

  v4 = (idMD6LeafPause *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 1);
  this->pauseLeaf = v4;
  idMD6LeafPause::Init(this: v4, anim: nullptr, frame: 0.0, wrapMode: v5, weightGroup: MD6_WEIGHTGROUP_ALL);
  v7 = (idMD6LeafPlay *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 2);
  this->playLeaf = v7;
  v8 = 0;
  defaultAnim = nullptr;
  skeleton = parms->animStack->treeAnimator->decl->model->skeleton;
  if ( skeleton != nullptr )
    defaultAnim = skeleton->defaultAnim;
  idMD6LeafPlay::Init(
    this: v7,
    anim: defaultAnim,
    gameTime: 0,
    ticksPerSec: 0,
    frame: 0,
    rateScale: 1.0,
    wrapMode: v6,
    weightGroup: MD6_WEIGHTGROUP_LEGS);
  v11 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  pauseLeaf = this->pauseLeaf;
  playLeaf = this->playLeaf;
  this->lerpBranch = v11;
  idMD6Branch::Init(
    this: v11,
    left: playLeaf,
    right: pauseLeaf,
    op: BOP_REF_LERP,
    originBlend: ORIGINBLEND_BRANCH,
    startAlpha: 1.0,
    targetAlpha: 1.0,
    alphaRate: 0.0,
    filterGroup: v15,
    blendType: v14);
  v16 = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  lerpBranch = this->lerpBranch;
  this->mergeBranch = v16;
  v16->right = lerpBranch;
  this->isInitialized = false;
  animStack = (const idDeclPonytail *)parms[1].animStack;
  this->declPonytail = animStack;
  this->parentAnimator = (idTreeAnimator *)parms[1].name.len;
  num = animStack->jointInfo.num;
  if ( num <= this->segments.size
    || (unsigned __int8)idList<idPonytailSegment,30>::Resize(this: &this->segments, newsize: animStack->jointInfo.num) != 0 )
  {
    size = this->segments.size;
    if ( num < size )
      size = num;
    this->segments.num = size;
  }
  declPonytail = this->declPonytail;
  treeAnimator = (idIndex<short,enum invalidJointIndex_t> *)parms->animStack->treeAnimator;
  v22 = declPonytail->jointInfo.num;
  if ( v22 <= this->joints.size
    || (unsigned __int8)idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
                          this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->joints,
                          newsize: declPonytail->jointInfo.num) != 0 )
  {
    v24 = this->joints.size;
    if ( v22 < v24 )
      v24 = v22;
    this->joints.num = v24;
  }
  if ( num > 0 )
  {
    v33.x = 0.0;
    v33.y = 0.0;
    v25 = 0;
    v33.z = 0.0;
    v26 = 0;
    do
    {
      v27 = &this->declPonytail->jointInfo.list[v8];
      v32.value = v27->limitAngle.value * idMath::M_DEG2RAD;
      idConeConstraint_Quat::idConeConstraint_Quat(this: &v34, center_: &quat_identity, maxAngle_: &v32);
      v28 = &this->segments.list[v26];
      *v28 = *idPonytailSegment::idPonytailSegment(this: &v35, origin_: &v33, ccq: &v34);
      v29 = &this->joints.list[v25];
      --num;
      ++v8;
      ++v26;
      ++v25;
      v29->value = idTreeAnimator::GetJointIndex(
                     this: (idTreeAnimator *)&v31,
                     result: treeAnimator,
                     jointName: v27->jointName.data)->value;
    }
    while ( num != 0 );
  }
  return 1;
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_Ponytail@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826E9FC8
// RVA : 0x006E9FC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __fastcall idAnimator_Ponytail::InternalPreBlendTree(
        idAnimator_Ponytail *this,
        const idAnimStack *stack,
        int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idTreeAnimator *treeAnimator; // r27
  int v10; // r3
  int num; // r16
  bool v12; // r23
  int v13; // r28
  int v14; // r25
  int i; // r26
  jointTransform_t *v16; // r30
  int j; // r28
  idPonytailSegment *v18; // r30
  idDeclPonytail::idPonytailJointInfo *v19; // r26
  double v20; // fp13
  double v21; // fp12
  double v22; // fp11
  double w; // fp0
  jointTransform_t *v24; // r11
  double v25; // fp11
  double v26; // fp8
  idQuat *v27; // r3
  idQuat *v28; // r3
  double v29; // fp7
  jointTransform_t *v30; // r11
  double v31; // fp5
  double v32; // fp1
  double v33; // fp3
  double v34; // fp4
  double v35; // fp2
  jointTransform_t *v36; // r11
  long double v37; // fp2
  double v38; // fp29
  long double v39; // fp2
  double v40; // fp29
  long double v41; // fp2
  long double v42; // fp2
  const idDeclPonytail *v43; // r11
  const idDeclPonytail *v44; // r10
  jointTransform_t *v45; // r11
  float *v46; // r11
  double v47; // fp5
  double v48; // fp4
  double v49; // fp31
  double v50; // fp3
  double v51; // fp2
  double v52; // fp8
  double v53; // fp7
  double v54; // fp6
  double RealMsPerFrame; // fp1
  const idDeclPonytail *declPonytail; // r11
  double v57; // fp31
  const idDeclPonytail *v58; // r6
  double z; // fp9
  double y; // fp8
  jointTransform_t *v61; // r11
  double v62; // fp7
  idMat3 *p_axis; // r30
  double v64; // fp6
  float *p_x; // r26
  double v66; // fp4
  double v67; // fp3
  double v68; // fp29
  double x; // fp28
  double v70; // fp13
  double v71; // fp30
  double v72; // fp12
  double v73; // fp10
  double v74; // fp11
  double v75; // fp7
  double v76; // fp13
  double v77; // fp9
  double v78; // fp12
  double v79; // fp8
  double v80; // fp11
  idDeclPonytail::idPonytailSpringInfo *list; // r11
  double v82; // fp0
  double maxLength; // fp4
  double v86; // fp2
  double v87; // fp1
  int v88; // r5
  int v89; // r24
  double v90; // fp29
  double v91; // fp28
  double v92; // fp27
  int v93; // r21
  int v94; // r22
  float *v95; // r28
  idPonytailSegment *v96; // r27
  double len; // fp26
  idVec3 *v98; // r3
  double v99; // fp8
  double v100; // fp6
  double v101; // fp13
  double v102; // fp12
  float *v103; // r25
  double v104; // fp12
  double v105; // fp10
  double v106; // fp8
  double v109; // fp1
  double v110; // fp5
  idConeConstraint_Quat *p_coneConstraintQ; // r27
  double v112; // fp10
  double v113; // fp8
  double v114; // fp6
  double v115; // fp5
  idMat3 *v116; // r3
  idRenderWorld *v117; // r3
  double v118; // fp12
  double v119; // fp9
  double v120; // fp4
  double v121; // fp3
  idRenderWorld *v122; // r3
  idMD6LeafPause *pauseLeaf; // r3
  int v124; // r26
  idMD6Blend::jointMod_t *v125; // r27
  int v126; // r28
  int v127; // r30
  idIndex<short,enum invalidJointIndex_t> *v128; // r25
  idPonytailSegment *v129; // r11
  double v130; // fp8
  double v131; // fp7
  double v132; // fp9
  double v133; // fp13
  double v134; // fp5
  double v135; // fp2
  double v136; // fp3
  float v137; // r7
  float v138; // r6
  const idMat3 *v139; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v141; // r30
  int v142; // r3
  __int64 totalTicks; // r11
  __int64 v144; // r9
  idMat3 v145; // [sp+60h] [-370h] BYREF
  float v146; // [sp+84h] [-34Ch]
  float v147; // [sp+88h] [-348h]
  idPLogScope v148[2]; // [sp+90h] [-340h] BYREF
  idMat3 v149; // [sp+A0h] [-330h] BYREF
  float v150; // [sp+C4h] [-30Ch]
  float v151; // [sp+C8h] [-308h]
  idMat3 v152; // [sp+D0h] [-300h] BYREF
  idQuat v153[3]; // [sp+100h] [-2D0h] BYREF
  idList<jointTransform_t,5> v154; // [sp+130h] [-2A0h] BYREF
  int v155; // [sp+140h] [-290h] BYREF

  RD_EventBegin(name: "idAnimator_Ponytail::InternalPreBlendTree");
  LODWORD(v7) = "idAnimator_Ponytail::InternalPreBlendTree";
  HIDWORD(v7) = 2;
  idPLogScope::idPLogScope(this: v148, pl: &::pLog, gMask: v7, label: v8);
  treeAnimator = stack->treeAnimator;
  if ( treeAnimator != nullptr )
  {
    v10 = idStr::Find(
            searchIn: treeAnimator->decl->name.str,
            searchFor: "bobble",
            casesensitive: true,
            start: 0,
            end: -1);
    num = this->declPonytail->jointInfo.num;
    v154.size = 16;
    v154.num = 0;
    v12 = v10 != -1;
    v154.granularity = 1;
    v154.list = (jointTransform_t *)&v155;
    v154.memTag = 5;
    v154.listStatic = 1;
    idList<jointTransform_t,5>::SetNum(this: &v154, newNum: num);
    if ( num > 0 )
    {
      v13 = 0;
      v14 = 0;
      for ( i = num; i != 0; --i )
      {
        idTreeAnimator::GetModelSpaceJointTransform(
          this: treeAnimator,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->joints.list[v14].value,
          origin: &v154.list[v13].msOrigin,
          axis: &v152);
        v16 = &v154.list[v13];
        v16->msQuat = *idMat3::ToQuat(this: &v149, result: (idQuat *)&v152);
        ++v14;
        ++v13;
      }
    }
    if ( this->isInitialized )
    {
      RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(
                         this: this->gametimeManager.gameTimeManager,
                         type: GAMETIME_SCALED);
      declPonytail = this->declPonytail;
      v57 = (float)((float)RealMsPerFrame * (float)0.001);
      this->ptEndSpring.m = declPonytail->springInfo.list->mass;
      idSpring<idVec3>::SetConstants(
        this: &this->ptEndSpring,
        _k: declPonytail->springInfo.list->tightness,
        _c: declPonytail->springInfo.list->damping);
      v58 = this->declPonytail;
      this->ptEndSpring.maxSpeed = 2500.0;
      z = treeAnimator->g.axis.mat[0].z;
      y = treeAnimator->g.axis.mat[1].y;
      v61 = &v154.list[v58->springInfo.list->ptJointIndex];
      v62 = treeAnimator->g.axis.mat[2].z;
      p_axis = &treeAnimator->g.axis;
      v64 = treeAnimator->g.axis.mat[2].y;
      p_x = &treeAnimator->g.origin.x;
      v66 = treeAnimator->g.origin.z;
      v67 = treeAnimator->g.origin.y;
      v68 = v61->msOrigin.y;
      x = v61->msOrigin.x;
      v70 = (float)(v61->msOrigin.y * treeAnimator->g.axis.mat[1].z);
      v71 = v61->msOrigin.z;
      v72 = (float)(treeAnimator->g.axis.mat[0].y * v61->msOrigin.x);
      this->ptEndSpring.p0.x = (float)((float)(treeAnimator->g.axis.mat[0].x * v61->msOrigin.x)
                                     + (float)((float)(treeAnimator->g.axis.mat[2].x * v61->msOrigin.z)
                                             + (float)(v61->msOrigin.y * treeAnimator->g.axis.mat[1].x)))
                             + treeAnimator->g.origin.x;
      this->ptEndSpring.p0.z = (float)((float)((float)v62 * (float)v71)
                                     + (float)((float)((float)z * (float)x) + (float)v70))
                             + (float)v66;
      this->ptEndSpring.p0.y = (float)v67
                             + (float)((float)((float)v64 * (float)v71)
                                     + (float)((float)((float)y * (float)v68) + (float)v72));
      v73 = this->ptEndSpring.vel.z;
      v74 = (float)((float)((float)v57 * (float)0.0) + this->ptEndSpring.vel.y);
      v75 = (float)((float)(this->declPonytail->springInfo.list->gravityMag * (float)-1.0) * (float)v57);
      this->ptEndSpring.vel.x = this->ptEndSpring.vel.x + (float)((float)v57 * (float)0.0);
      this->ptEndSpring.vel.y = v74;
      this->ptEndSpring.vel.z = (float)v75 + (float)v73;
      idSpring<idVec3>::Update(this: &this->ptEndSpring, dt: v57);
      v76 = (float)(this->ptEndSpring.p1.y - this->ptEndSpring.p0.y);
      v77 = this->ptEndSpring.p0.x;
      v78 = (float)(this->ptEndSpring.p1.x - this->ptEndSpring.p0.x);
      v79 = this->ptEndSpring.p0.z;
      v80 = (float)(this->ptEndSpring.p1.z - this->ptEndSpring.p0.z);
      list = this->declPonytail->springInfo.list;
      v82 = (float)((float)((float)v80 * (float)v80)
                  + (float)((float)((float)v78 * (float)v78) + (float)((float)v76 * (float)v76)));
      if ( v82 > (float)(list->maxLength * list->maxLength) )
      {
        maxLength = list->maxLength;
        _FP5 = (float)((float)((float)((float)v80 * (float)v80)
                             + (float)((float)((float)v78 * (float)v78) + (float)((float)v76 * (float)v76)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f3, f5, f0, f7 }
        v86 = __frsqrte(_FP3);
        v87 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86
                                                                                            * (float)((float)v82 * (float)0.5))
                                                                                    * (float)v86)
                                                                            - (float)1.5)
                                                            * (float)v86)
                                                    * (float)((float)v82 * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v86
                                                                                    * (float)((float)v82 * (float)0.5))
                                                                            * (float)v86)
                                                                    - (float)1.5)
                                                    * (float)v86))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86)
                                            - (float)1.5)
                            * (float)v86));
        this->ptEndSpring.p1.y = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                               * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                       * (float)((float)v82 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                               * (float)v86)))
                                                                       - (float)1.5)
                                                       * (float)v87)
                                               * (float)(this->ptEndSpring.p1.y - this->ptEndSpring.p0.y))
                                       * list->maxLength)
                               + this->ptEndSpring.p0.y;
        this->ptEndSpring.p1.x = (float)((float)maxLength
                                       * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                               * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                       * (float)((float)v82 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                               * (float)v86)))
                                                                       - (float)1.5)
                                                       * (float)v87)
                                               * (float)v78))
                               + (float)v77;
        this->ptEndSpring.p1.z = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                               * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                       * (float)((float)v82 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)v82 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)v82 * (float)0.5)) * (float)v86) - (float)1.5)
                                                                                               * (float)v86)))
                                                                       - (float)1.5)
                                                       * (float)v87)
                                               * (float)v80)
                                       * (float)maxLength)
                               + (float)v79;
      }
      if ( pt_debug.valueInteger != 0 )
      {
        DebugPoint(
          color: (const idVec4 *)&idColor::colorBlue,
          point: &this->ptEndSpring.p0,
          scale: 4.0,
          time: 0x82000000,
          depthTest: 0,
          a6: false);
        DebugPoint(
          color: (const idVec4 *)&idColor::colorCyan,
          point: &this->ptEndSpring.p1,
          scale: 4.0,
          time: v88,
          depthTest: 0,
          a6: false);
      }
      v89 = 0;
      v90 = (float)((float)((float)(this->ptEndSpring.p1.z - treeAnimator->g.origin.z) * treeAnimator->g.axis.mat[2].z)
                  + (float)((float)((float)(this->ptEndSpring.p1.x - treeAnimator->g.origin.x)
                                  * treeAnimator->g.axis.mat[2].x)
                          + (float)((float)(this->ptEndSpring.p1.y - treeAnimator->g.origin.y)
                                  * treeAnimator->g.axis.mat[2].y)));
      v91 = (float)((float)((float)(this->ptEndSpring.p1.z - treeAnimator->g.origin.z) * treeAnimator->g.axis.mat[1].z)
                  + (float)((float)((float)(this->ptEndSpring.p1.x - treeAnimator->g.origin.x)
                                  * treeAnimator->g.axis.mat[1].x)
                          + (float)((float)(this->ptEndSpring.p1.y - treeAnimator->g.origin.y)
                                  * treeAnimator->g.axis.mat[1].y)));
      v92 = (float)((float)((float)(this->ptEndSpring.p1.z - treeAnimator->g.origin.z) * treeAnimator->g.axis.mat[0].z)
                  + (float)((float)((float)(this->ptEndSpring.p1.x - treeAnimator->g.origin.x)
                                  * treeAnimator->g.axis.mat[0].x)
                          + (float)((float)(this->ptEndSpring.p1.y - treeAnimator->g.origin.y)
                                  * treeAnimator->g.axis.mat[0].y)));
      if ( num > 0 )
      {
        v93 = 0;
        v94 = 0;
        do
        {
          v95 = nullptr;
          v96 = &this->segments.list[v94];
          if ( v89 > 0 )
          {
            v95 = &v96[-1].localOrigin.x;
            len = v96[-1].len;
            v98 = idQuat::ToForward(this: (idQuat *)&v149, result: (idVec3 *)&v96[-1].coneConstraintQ);
            v99 = (float)(v98->y * (float)len);
            v100 = (float)(v98->z * (float)len);
            v101 = v96[-1].origin.y;
            v102 = v96[-1].origin.z;
            v96->origin.x = (float)(v98->x * (float)len) + v96[-1].origin.x;
            v96->origin.y = (float)v101 + (float)v99;
            v96->origin.z = (float)v102 + (float)v100;
            v96->coneConstraintQ.center.x = v96[-1].coneConstraintQ.current.x;
            v96->coneConstraintQ.center.y = v96[-1].coneConstraintQ.current.y;
            v96->coneConstraintQ.center.z = v96[-1].coneConstraintQ.current.z;
            v96->coneConstraintQ.center.w = v96[-1].coneConstraintQ.current.w;
          }
          v103 = &v96->origin.x;
          v104 = (float)((float)v90 - v96->origin.z);
          v105 = (float)((float)v91 - v96->origin.y);
          v106 = (float)((float)v92 - v96->origin.x);
          _FP4 = (float)((float)((float)((float)v106 * (float)v106)
                               + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f2, f4, f5, f0 }
          v109 = __frsqrte(_FP2);
          v110 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                       * (float)v109)
                                                                               - (float)1.5)
                                                               * (float)v109)
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v105 * (float)v105)
                                                                               + (float)((float)v104 * (float)v104)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v109
                                                                                       * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104)))
                                                                                               * (float)0.5))
                                                                               * (float)v109)
                                                                       - (float)1.5)
                                                       * (float)v109))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v109
                                                               * (float)((float)((float)((float)v106 * (float)v106)
                                                                               + (float)((float)((float)v105
                                                                                               * (float)v105)
                                                                                       + (float)((float)v104
                                                                                               * (float)v104)))
                                                                       * (float)0.5))
                                                       * (float)v109)
                                               - (float)1.5)
                               * (float)v109));
          v145.mat[2].z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109) * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109)
                                                                                                - (float)1.5)
                                                                                * (float)v109))
                                                                * (float)((float)((float)((float)v106 * (float)v106)
                                                                                + (float)((float)((float)v105
                                                                                                * (float)v105)
                                                                                        + (float)((float)v104
                                                                                                * (float)v104)))
                                                                        * (float)0.5))
                                                        * (float)v110)
                                                - (float)1.5)
                                * (float)v110)
                        * (float)v106;
          v146 = (float)v105
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109)
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5)
                                                                                               * (float)v109))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                               * (float)v109)
                                                                                       - (float)1.5)
                                                                       * (float)v109))
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v105 * (float)v105)
                                                                               + (float)((float)v104 * (float)v104)))
                                                               * (float)0.5))
                                               * (float)v110)
                                       - (float)1.5)
                       * (float)v110);
          v147 = (float)v104
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109)
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5)
                                                                                               * (float)v109))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                               * (float)v109)
                                                                                       - (float)1.5)
                                                                       * (float)v109))
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v105 * (float)v105)
                                                                               + (float)((float)v104 * (float)v104)))
                                                               * (float)0.5))
                                               * (float)v110)
                                       - (float)1.5)
                       * (float)v110);
          if ( v12 )
          {
            v145.mat[2].z = (float)v105
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109) * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109)
                                                                                                  - (float)1.5)
                                                                                  * (float)v109))
                                                                  * (float)((float)((float)((float)v106 * (float)v106)
                                                                                  + (float)((float)((float)v105
                                                                                                  * (float)v105)
                                                                                          + (float)((float)v104
                                                                                                  * (float)v104)))
                                                                          * (float)0.5))
                                                          * (float)v110)
                                                  - (float)1.5)
                                  * (float)v110);
            v146 = -(float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109) * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109) - (float)1.5) * (float)v109))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v105 * (float)v105) + (float)((float)v104 * (float)v104))) * (float)0.5)) * (float)v109)
                                                                                                  - (float)1.5)
                                                                                  * (float)v109))
                                                                  * (float)((float)((float)((float)v106 * (float)v106)
                                                                                  + (float)((float)((float)v105
                                                                                                  * (float)v105)
                                                                                          + (float)((float)v104
                                                                                                  * (float)v104)))
                                                                          * (float)0.5))
                                                          * (float)v110)
                                                  - (float)1.5)
                                  * (float)v110)
                          * (float)v106);
          }
          p_coneConstraintQ = &v96->coneConstraintQ;
          idConeConstraint_Quat::RotateTo(
            this: p_coneConstraintQ,
            dir: (const idVec3 *)&v145.mat[2].z,
            lerpRate: this->declPonytail->jointInfo.list[v93].lerpRate);
          if ( pt_debug.valueInteger != 0 )
          {
            v112 = p_x[1];
            v113 = *p_x;
            v114 = (float)((float)(p_axis->mat[0].y * *v103)
                         + (float)((float)(v103[1] * p_axis->mat[1].y) + (float)(v103[2] * p_axis->mat[2].y)));
            v115 = (float)((float)(p_axis->mat[0].x * *v103)
                         + (float)((float)(v103[1] * p_axis->mat[1].x) + (float)(v103[2] * p_axis->mat[2].x)));
            v149.mat[2].x = (float)((float)(*v103 * p_axis->mat[0].z)
                                  + (float)((float)(v103[1] * p_axis->mat[1].z) + (float)(v103[2] * p_axis->mat[2].z)))
                          + p_x[2];
            v149.mat[1].z = (float)v112 + (float)v114;
            v149.mat[1].y = (float)v115 + (float)v113;
            v116 = idQuat::ToMat3(this: v153, result: (idMat3 *)p_coneConstraintQ);
            idMat3::operator*(this: &v152, result: v116, a: p_axis);
            v117 = common->RW(this: common);
            ((void (__fastcall *)(idRenderWorld *, float *, idMat3 *, void (__fastcall *)(idRenderWorld *, const idVec3 *, const idMat3 *, const float, const int, const bool), _DWORD, _DWORD, double))v117->DebugAxisScaled)(
              a1: v117,
              a2: &v149.mat[1].y,
              a3: &v152,
              a4: v117->DebugAxisScaled,
              a5: 0,
              a6: 0,
              a7: 0.5);
            if ( v95 != nullptr )
            {
              v118 = *p_x;
              v119 = p_x[1];
              v120 = (float)((float)(p_axis->mat[0].x * v95[7])
                           + (float)((float)(v95[8] * p_axis->mat[1].x) + (float)(v95[9] * p_axis->mat[2].x)));
              v121 = (float)((float)(p_axis->mat[0].y * v95[7])
                           + (float)((float)(v95[8] * p_axis->mat[1].y) + (float)(v95[9] * p_axis->mat[2].y)));
              v151 = (float)((float)(v95[7] * p_axis->mat[0].z)
                           + (float)((float)(v95[8] * p_axis->mat[1].z) + (float)(v95[9] * p_axis->mat[2].z)))
                   + p_x[2];
              v149.mat[2].z = (float)v120 + (float)v118;
              v150 = (float)v119 + (float)v121;
              v122 = common->RW(this: common);
              ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v122->DebugArrow)(
                a1: v122,
                a2: &idColor::colorRed,
                a3: &v149.mat[2].z,
                a4: &v149.mat[1].y,
                a5: 0.5);
            }
          }
          ++v89;
          ++v94;
          ++v93;
        }
        while ( v89 < num );
      }
    }
    else
    {
      for ( j = 0; j < num; v18->coneConstraintQ.halfLimitAngleSine = *(double *)&v42 )
      {
        v18 = &this->segments.list[j];
        v19 = &this->declPonytail->jointInfo.list[j];
        if ( j == num - 1 )
        {
          if ( j != 0 )
          {
            v20 = v18[-1].coneConstraintQ.center.x;
            v21 = v18[-1].coneConstraintQ.center.y;
            v22 = v18[-1].coneConstraintQ.center.z;
            w = v18[-1].coneConstraintQ.center.w;
          }
          else
          {
            v20 = v154.list->msQuat.x;
            v21 = v154.list->msQuat.y;
            v22 = v154.list->msQuat.z;
            w = v154.list->msQuat.w;
          }
          v18->len = 0.0;
        }
        else
        {
          v24 = &v154.list[j];
          v25 = (float)(v24[1].msOrigin.z - v24->msOrigin.z);
          v26 = (float)(v24[1].msOrigin.y - v24->msOrigin.y);
          v145.mat[1].y = v24[1].msOrigin.x - v24->msOrigin.x;
          v145.mat[2].x = v25;
          v145.mat[1].z = v26;
          v27 = (idQuat *)idVec3::ToMat3(this: v152.mat, result: (idMat3 *)&v145.mat[1].y);
          v28 = idMat3::ToQuat(this: &v149, result: v27);
          v20 = v28->x;
          v21 = v28->y;
          v22 = v28->z;
          w = v28->w;
          v18->len = __fsqrts((float)((float)(v145.mat[1].y * v145.mat[1].y)
                                    + (float)((float)(v145.mat[2].x * v145.mat[2].x)
                                            + (float)(v145.mat[1].z * v145.mat[1].z))));
        }
        v29 = v154.list[j].msQuat.x;
        v30 = &v154.list[j];
        v31 = v30->msQuat.w;
        v32 = v30->msQuat.y;
        v33 = v30->msQuat.z;
        v34 = (float)((float)(v30->msQuat.y * (float)w)
                    + (float)((float)(v30->msQuat.x * (float)-v22) + (float)(v30->msQuat.w * (float)-v21)));
        v35 = (float)((float)(v30->msQuat.x * (float)w)
                    + (float)((float)(v30->msQuat.z * (float)-v21) + (float)(v30->msQuat.w * (float)-v20)));
        v18->localAxis.w = -(float)((float)(v30->msQuat.z * (float)-v22)
                                  - (float)-(float)((float)(v30->msQuat.y * (float)-v21)
                                                  - (float)((float)(v30->msQuat.w * (float)w)
                                                          - (float)(v30->msQuat.x * (float)-v20))));
        v18->localAxis.z = -(float)((float)((float)v29 * (float)-v21)
                                  - (float)((float)((float)v33 * (float)w)
                                          + (float)((float)((float)v32 * (float)-v20) + (float)((float)v31 * (float)-v22))));
        v18->localAxis.y = -(float)((float)((float)v33 * (float)-v20) - (float)v34);
        v18->localAxis.x = -(float)((float)((float)v32 * (float)-v22) - (float)v35);
        v36 = &v154.list[j];
        *((double *)&v37 + 1) = v36->msOrigin.x;
        v18->origin.x = v36->msOrigin.x;
        v18->origin.y = v36->msOrigin.y;
        v18->origin.z = v36->msOrigin.z;
        v18->coneConstraintQ.center.x = v20;
        v18->coneConstraintQ.center.y = v21;
        v18->coneConstraintQ.center.z = v22;
        v18->coneConstraintQ.center.w = w;
        v38 = (float)(v19->limitAngle.value * idMath::M_DEG2RAD);
        *(double *)&v37 = v38;
        v39 = cos(x: v37);
        v18->coneConstraintQ.limitAngleDot = *(double *)&v39;
        v40 = (float)((float)v38 * (float)0.5);
        *(double *)&v39 = v40;
        v41 = cos(x: v39);
        v18->coneConstraintQ.halfLimitAngleCosine = *(double *)&v41;
        *(double *)&v41 = v40;
        v42 = sin(x: v41);
        ++j;
      }
      this->ptEndSpring.restLength = 0.0;
      this->ptEndSpring.p0.x = 0.0;
      this->ptEndSpring.p0.z = 0.0;
      this->ptEndSpring.p0.y = 0.0;
      this->ptEndSpring.k = 1.0;
      this->ptEndSpring.m = 1.0;
      this->ptEndSpring.c = 2.0;
      this->ptEndSpring.p1.z = 0.0;
      this->ptEndSpring.p1.y = 0.0;
      this->ptEndSpring.p1.x = 0.0;
      this->ptEndSpring.vel.z = 0.0;
      this->ptEndSpring.vel.y = 0.0;
      this->ptEndSpring.vel.x = 0.0;
      this->ptEndSpring.maxSpeed = 0.0;
      this->ptEndSpring.pMin.z = 0.0;
      this->ptEndSpring.pMin.y = 0.0;
      this->ptEndSpring.pMin.x = 0.0;
      this->ptEndSpring.hasPMin = false;
      this->ptEndSpring.pMax.z = 0.0;
      this->ptEndSpring.pMax.y = 0.0;
      this->ptEndSpring.pMax.x = 0.0;
      this->ptEndSpring.hasPMax = false;
      v43 = this->declPonytail;
      this->ptEndSpring.m = v43->springInfo.list->mass;
      idSpring<idVec3>::SetConstants(
        this: &this->ptEndSpring,
        _k: v43->springInfo.list->tightness,
        _c: v43->springInfo.list->damping);
      v44 = this->declPonytail;
      v45 = v154.list;
      this->ptEndSpring.maxSpeed = 2500.0;
      v46 = &v45[v44->springInfo.list->ptJointIndex].msQuat.x;
      v47 = treeAnimator->g.axis.mat[2].z;
      v48 = treeAnimator->g.axis.mat[2].y;
      v49 = v46[6];
      v50 = treeAnimator->g.origin.z;
      v51 = treeAnimator->g.origin.y;
      v52 = (float)((float)(treeAnimator->g.axis.mat[0].z * v46[4]) + (float)(treeAnimator->g.axis.mat[1].z * v46[5]));
      v53 = (float)((float)(treeAnimator->g.axis.mat[0].y * v46[4]) + (float)(treeAnimator->g.axis.mat[1].y * v46[5]));
      v54 = (float)(treeAnimator->g.origin.x
                  + (float)((float)(treeAnimator->g.axis.mat[0].x * v46[4])
                          + (float)((float)(treeAnimator->g.axis.mat[1].x * v46[5])
                                  + (float)(treeAnimator->g.axis.mat[2].x * v46[6]))));
      this->ptEndSpring.p0.x = treeAnimator->g.origin.x
                             + (float)((float)(treeAnimator->g.axis.mat[0].x * v46[4])
                                     + (float)((float)(treeAnimator->g.axis.mat[1].x * v46[5])
                                             + (float)(treeAnimator->g.axis.mat[2].x * v46[6])));
      this->ptEndSpring.p0.z = (float)v50 + (float)((float)((float)v47 * (float)v49) + (float)v52);
      this->ptEndSpring.p0.y = (float)v51 + (float)((float)((float)v48 * (float)v49) + (float)v53);
      this->ptEndSpring.p1.x = v54;
      this->ptEndSpring.p1.y = this->ptEndSpring.p0.y;
      this->ptEndSpring.p1.z = this->ptEndSpring.p0.z;
      this->isInitialized = true;
    }
    pauseLeaf = this->pauseLeaf;
    if ( pt_modifyJoints.valueInteger != 0 )
    {
      idMD6LeafPause::SetNumAnimMods(this: pauseLeaf, n: this->joints.num);
      v124 = 0;
      v125 = this->pauseLeaf->animMods[this->pauseLeaf->currentDeferred & 1].list;
      if ( this->joints.num > 0 )
      {
        v126 = 0;
        v127 = 0;
        do
        {
          v128 = this->joints.list;
          v129 = &this->segments.list[v127];
          v145.mat[0] = *(idVec3 *)&v129->coneConstraintQ.current.x;
          v145.mat[1].x = v129->coneConstraintQ.current.w;
          v130 = v129->localAxis.z;
          v131 = v129->localAxis.y;
          v132 = v129->localAxis.x;
          v133 = v145.mat[0].x;
          v134 = (float)((float)(v145.mat[0].x * v129->localAxis.y)
                       + (float)((float)(v145.mat[1].x * v129->localAxis.z) + (float)(v145.mat[0].z * v129->localAxis.w)));
          v135 = (float)((float)(v145.mat[0].x * v129->localAxis.w)
                       + (float)((float)(v145.mat[0].y * v129->localAxis.z) + (float)(v145.mat[1].x * v129->localAxis.x)));
          v136 = (float)((float)(v145.mat[0].y * v129->localAxis.w)
                       + (float)((float)(v145.mat[1].x * v129->localAxis.y) + (float)(v145.mat[0].z * v129->localAxis.x)));
          v145.mat[1].x = -(float)((float)(v145.mat[0].z * v129->localAxis.z)
                                 - (float)-(float)((float)(v145.mat[0].y * v129->localAxis.y)
                                                 - (float)((float)(v145.mat[1].x * v129->localAxis.w)
                                                         - (float)(v145.mat[0].x * v129->localAxis.x))));
          v145.mat[0].x = -(float)((float)(v145.mat[0].z * (float)v131) - (float)v135);
          v145.mat[0].z = -(float)((float)(v145.mat[0].y * (float)v132) - (float)v134);
          v145.mat[0].y = -(float)((float)((float)v133 * (float)v130) - (float)v136);
          v137 = v129->origin.y;
          v138 = v129->origin.z;
          v149.mat[0].x = v129->origin.x;
          v149.mat[0].y = v137;
          v149.mat[0].z = v138;
          v139 = idQuat::ToMat3(this: v153, result: &v145);
          SetJointModFromOriginAxis(
            mod: v125,
            joint: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v128[v126].value,
            flags: 0x2Bu,
            origin: v149.mat,
            axis: v139);
          ++v124;
          ++v127;
          ++v126;
          ++v125;
        }
        while ( v124 < this->joints.num );
      }
      this->lerpBranch->currentAlpha = 0.99989998;
      this->mergeBranch->left = nullptr;
      this->mergeBranch->right = this->lerpBranch;
    }
    else
    {
      idMD6LeafPause::SetNumAnimMods(this: pauseLeaf, n: 0);
      this->mergeBranch->right = this->playLeaf;
    }
    this->playLeaf->startTime = curTime;
    if ( v154.listStatic == 0 || v154.listStatic == 2 )
    {
      if ( v154.list != nullptr )
        idMem::Free(this: &mem, ptr: v154.list, align: ALIGN_16);
      v154.list = nullptr;
      v154.size = 0;
    }
    v154.num = 0;
    if ( v148[0].logIndex >= 0 )
    {
      pLog = v148[0].pLog;
      v141 = &v148[0].pLog->logEntries.list[v148[0].logIndex];
      v142 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v141->totalTicks;
      HIDWORD(totalTicks) = v141->parent;
      LODWORD(v144) = v142 - totalTicks;
      v141->totalTicks = v144;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v148);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$248782
// EA  : 0x826EACD8
// RVA : 0x006EACD8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248782()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 976 + 768));
}


// ========================================================================
// __unwind$248783
// EA  : 0x826EAD00
// RVA : 0x006EAD00
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248783()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 976 + 144));
}


// ========================================================================
// __unwind$248784
// EA  : 0x826EAD28
// RVA : 0x006EAD28
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void _unwind_248784()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 976 + 304));
}


// ========================================================================
// `dynamic initializer for 'pt_debug''
// EA  : 0x8333F138
// RVA : 0x0133F138
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pt_debug__()
{
  idCVar::idCVar(
    this: &pt_debug,
    name: "pt_debug",
    value: "0",
    flags: 2,
    description: "1 = show ponytail debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pt_debug__);
}


// ========================================================================
// `dynamic initializer for 'pt_modifyJoints''
// EA  : 0x8333F190
// RVA : 0x0133F190
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pt_modifyJoints__()
{
  idCVar::idCVar(
    this: &pt_modifyJoints,
    name: "pt_modifyJoints",
    value: "1",
    flags: 1,
    description: "1 = allow ponytails to modify joints using anim mods",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pt_modifyJoints__);
}

