
// ========================================================================
// ?GetMoveStateString@idAIAnimWebState@@MAAXPBVidAI2@@AAVidStr@@W4posture_t@@@Z
// EA  : 0x82A62618
// RVA : 0x00A62618
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void __fastcall idAIAnimWebState::GetMoveStateString(
        idAIAnimWebState *this,
        idAI2 *ai,
        idStr *moveState,
        posture_t overridePosture)
{
  walkState_t v5; // r3

  v5 = ai->GetWalkState(this: ai);
  idStr::operator=(this: moveState, text: walkStateNames[v5]);
}


// ========================================================================
// ?VerifyFloorTrace@idAIAnimWebState@@QAA_NPBVidAI2@@@Z
// EA  : 0x82A62670
// RVA : 0x00A62670
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

BOOL __fastcall idAIAnimWebState::VerifyFloorTrace(idAIAnimWebState *this, idAI2 *ai)
{
  idAnimWebState *v2; // r30
  char *v4; // r10
  float *p_y; // r11
  int v6; // ctr
  const idDeclMD6 *Model; // r3
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp6
  double v14; // fp4
  idAIMoveState *MoveInterface; // r30
  idPhysics *v16; // r3
  int v17; // r3
  idVec3 v19; // [sp+50h] [-80h] BYREF
  float v20[3]; // [sp+60h] [-70h] BYREF
  char v21; // [sp+6Ch] [-64h] BYREF
  idMat3 v22; // [sp+70h] [-60h] BYREF

  v2 = &this->idAnimWebState;
  if ( !idAnimWebState::Verify(this: &this->idAnimWebState, errorMsg: nullptr) )
    return false;
  v4 = &v21;
  p_y = &mat2_identity.mat[1].y;
  v6 = 9;
  v19 = vec3_origin;
  do
  {
    ++p_y;
    v4 += 4;
    *(float *)v4 = *p_y;
    --v6;
  }
  while ( v6 != 0 );
  Model = idAnimWebState::GetModel(this: v2, index: 0);
  idAnimWebState::GetAnimDelta(this: v2, md6: Model, animIndex: 0, deltaPos: &v19, deltaAxis: &v22);
  v8 = (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[0].x * v19.x)
             + (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[1].x * v19.y)
                     + (float)(ai->actorVolatile.modelInfo.modelAxis.mat[2].x * v19.z)));
  v9 = (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[0].y * v19.x)
             + (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[1].y * v19.y)
                     + (float)(ai->actorVolatile.modelInfo.modelAxis.mat[2].y * v19.z)));
  v10 = (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[0].z * v19.x)
              + (float)((float)(ai->actorVolatile.modelInfo.modelAxis.mat[1].z * v19.y)
                      + (float)(ai->actorVolatile.modelInfo.modelAxis.mat[2].z * v19.z)));
  Physics = idEntity::GetPhysics(this: ai);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(v12[2] + (float)v10);
  v14 = (float)(v12[1] + (float)v9);
  v20[0] = (float)v8 + *v12;
  v20[2] = v13;
  v20[1] = v14;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v16 = idEntity::GetPhysics(this: ai);
  v17 = (int)v16->GetOrigin(this: v16, a2: 0);
  return MoveInterface->IsLineInNavGraph(
           this: MoveInterface,
           a2: (const idVec3 *)v17,
           a3: (const idVec3 *)v20,
           a4: nullptr);
}


// ========================================================================
// ?VerifyPointOutsideAnimRange@idAIAnimWebState@@QAA_NPBVidAI2@@ABVidVec3@@@Z
// EA  : 0x82A62828
// RVA : 0x00A62828
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

int __fastcall idAIAnimWebState::VerifyPointOutsideAnimRange(
        idAIAnimWebState *this,
        const idAI2 *ai,
        const idVec3 *point)
{
  idAnimWebState *v3; // r31
  char *v6; // r10
  float *p_y; // r11
  int v8; // ctr
  const idDeclMD6 *Model; // r3
  double v10; // fp31
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp4
  int result; // r3
  double v15; // fp2
  double v16; // fp13
  idVec3 v17; // [sp+50h] [-60h] BYREF
  char v18; // [sp+5Ch] [-54h] BYREF
  idMat3 v19; // [sp+60h] [-50h] BYREF

  v3 = &this->idAnimWebState;
  if ( !idAnimWebState::Verify(this: &this->idAnimWebState, errorMsg: nullptr) )
    return 0;
  v6 = &v18;
  p_y = &mat2_identity.mat[1].y;
  v8 = 9;
  v17 = vec3_origin;
  do
  {
    ++p_y;
    v6 += 4;
    *(float *)v6 = *p_y;
    --v8;
  }
  while ( v8 != 0 );
  Model = idAnimWebState::GetModel(this: v3, index: 0);
  idAnimWebState::GetAnimDelta(this: v3, md6: Model, animIndex: 0, deltaPos: &v17, deltaAxis: &v19);
  v10 = (float)((float)(v17.z * v17.z) + (float)((float)(v17.y * v17.y) + (float)(v17.x * v17.x)));
  Physics = idEntity::GetPhysics(this: &ai->idActor);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(point->z - v12[2]);
  v15 = (float)(point->y - v12[1]);
  v16 = (float)((float)((float)v15 * (float)v15)
              + (float)((float)((float)v13 * (float)v13) + (float)((float)(point->x - *v12) * (float)(point->x - *v12))));
  result = 1;
  if ( v10 >= v16 )
    return 0;
  return result;
}


// ========================================================================
// ?GetTurnStateString@idAIAnimWebState@@MAAXPBVidAI2@@AAVidStr@@@Z
// EA  : 0x82A62948
// RVA : 0x00A62948
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void __fastcall idAIAnimWebState::GetTurnStateString(idAIAnimWebState *this, idAI2 *ai, idStr *turnState)
{
  int currentTurnDir; // r11
  const char *v5; // r4

  currentTurnDir = idAI2::GetBodyOrientation(this: ai)->currentTurnDir;
  if ( currentTurnDir == 1 )
  {
    v5 = "turn_left";
  }
  else if ( currentTurnDir == 2 )
  {
    v5 = "turn_right";
  }
  else
  {
    v5 = &byte_8200D768;
  }
  idStr::operator=(this: turnState, text: v5);
}


// ========================================================================
// ??0idAIAnimWebState@@QAA@PBVidAI2@@PBD1@Z
// EA  : 0x82A629C0
// RVA : 0x00A629C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState *__fastcall idAIAnimWebState::idAIAnimWebState(
        idAIAnimWebState *this,
        idAI2 *ai,
        const char *subwebName,
        const char *stateName)
{
  idAnimWebState *v4; // r29
  idStr v10; // [sp+50h] [-80h] BYREF
  idStr v11[3]; // [sp+70h] [-60h] BYREF

  v4 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  v10.len = 0;
  v10.allocedAndFlag = 20;
  this->__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  idStr::idStr(this: v11, text: subwebName);
  idAI2::GetSubWebName(this: ai, inSubWebName: v11, subWebName: &v10);
  idStr::FreeData(this: v11);
  idAnimWebState::Init(
    this: v4,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _subweb: v10.data,
    _state: stateName);
  idStr::FreeData(this: &v10);
  return this;
}


// ========================================================================
// __unwind$488708
// EA  : 0x82A62A68
// RVA : 0x00A62A68
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_488708()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$488709
// EA  : 0x82A62A90
// RVA : 0x00A62A90
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_488709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ??0idAIAnimWebState_Transition@@QAA@PBVidAI2@@AAUtransitionQueryResult_t@idAnimWebTransitions@@_N2@Z
// EA  : 0x82A62AC0
// RVA : 0x00A62AC0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState_Transition *__fastcall idAIAnimWebState_Transition::idAIAnimWebState_Transition(
        idAIAnimWebState_Transition *this,
        idAI2 *ai,
        idAnimWebTransitions::transitionQueryResult_t *out,
        bool skipTrace,
        bool skipVerifyPointOutsideAnimRange)
{
  idAnimWebState *v5; // r28
  idAIMoveState *MoveInterface; // r3
  const idVec3 *v12; // r3

  v5 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  this->__vftable = (idAIAnimWebState_Transition_vtbl *)&idAIAnimWebState_Transition::`vftable';
  idAnimWebState::Init(
    this: v5,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _node: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)out->via.node.value);
  if ( !skipVerifyPointOutsideAnimRange
    && (MoveInterface = idAI2::GetMoveInterface(this: ai),
        v12 = MoveInterface->GetNextPoint(this: MoveInterface),
        (unsigned __int8)idAIAnimWebState::VerifyPointOutsideAnimRange(this, ai, point: v12) == 0)
    || !skipTrace && !idAIAnimWebState::VerifyFloorTrace(this, ai) )
  {
    idAnimWebState::Clear(this: v5);
  }
  return this;
}


// ========================================================================
// __unwind$488977
// EA  : 0x82A62B98
// RVA : 0x00A62B98
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_488977()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: *(idAIAnimWebState_Current **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idAIAnimWebState_Current@@QAA@PBVidAI2@@@Z
// EA  : 0x82A62BC8
// RVA : 0x00A62BC8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState_Current *__fastcall idAIAnimWebState_Current::idAIAnimWebState_Current(
        idAIAnimWebState_Current *this,
        const idAI2 *ai)
{
  idAnimWebState *v2; // r29

  v2 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  this->__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState_Current::`vftable';
  idAnimWebState::Init(
    this: v2,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _node: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curNodeIndex.value);
  return this;
}


// ========================================================================
// __unwind$489038
// EA  : 0x82A62C28
// RVA : 0x00A62C28
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489038()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: *(idAIAnimWebState_Current **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idAIAnimWebState_Target@@QAA@PBVidAI2@@@Z
// EA  : 0x82A62C58
// RVA : 0x00A62C58
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState_Target *__fastcall idAIAnimWebState_Target::idAIAnimWebState_Target(
        idAIAnimWebState_Target *this,
        const idAI2 *ai)
{
  idAnimWebState *v2; // r28
  int v5; // r11
  __int16 value; // r11
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v7; // r5
  int num; // [sp+50h] [-30h]

  v2 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  this->__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState_Target::`vftable';
  num = ai->aiVolatile.animation.animWebAnimator.ptr[0].curPath.num;
  if ( num <= 0 )
  {
    value = -1;
  }
  else
  {
    v5 = (__int16)(num - 1);
    if ( v5 < 0 || v5 >= ai->aiVolatile.animation.animWebAnimator.ptr[0].curPath.num )
      value = -1;
    else
      value = ai->aiVolatile.animation.animWebAnimator.ptr[0].curPath.path[v5].value;
  }
  v7 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)value;
  if ( value < 0 )
    v7 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curNodeIndex.value;
  idAnimWebState::Init(this: v2, decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl, _node: v7);
  return this;
}


// ========================================================================
// __unwind$489224
// EA  : 0x82A62D18
// RVA : 0x00A62D18
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489224()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: *(idAIAnimWebState_Current **)(v0 - 128 + 148));
}


// ========================================================================
// ?GetSubwebString@idAIAnimWebState@@SAXPBVidAI2@@AAVidStr@@W4aiSubWeb_t@@W4posture_t@@W4equipSlot_t@@@Z
// EA  : 0x82A62D40
// RVA : 0x00A62D40
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void __fastcall idAIAnimWebState::GetSubwebString(
        idAI2 *ai,
        idStr *out,
        aiSubWeb_t subWeb,
        posture_t posture,
        equipSlot_t useWeaponSlot)
{
  aiSubWeb_t v7; // r30
  idWeapon *EquippedWeapon; // r3
  const char *thirdPersonScale_low; // r4

  v7 = subWeb;
  if ( subWeb == AISUBWEB_MAX && ai != nullptr )
    v7 = ai->aiVolatile.animation.subWeb;
  if ( posture == POSTURE_MAX && ai != nullptr )
    ai->GetPosture(this: ai);
  if ( true == (v7 == AISUBWEB_DYING) )
  {
    idStr::operator=(this: out, text: aiSubWebNames[v7]);
  }
  else
  {
    if ( ai != nullptr
      && (useWeaponSlot == EQUIP_MAX
        ? (EquippedWeapon = ai->GetEquippedWeapon(this: ai))
        : (EquippedWeapon = idActor::GetEquippedWeapon(this: ai, slot: useWeaponSlot)),
          EquippedWeapon != nullptr) )
    {
      thirdPersonScale_low = (const char *)LODWORD(EquippedWeapon->decl[1].thirdPersonScale);
    }
    else
    {
      thirdPersonScale_low = "hands_";
    }
    idStr::operator=(this: out, text: thirdPersonScale_low);
    idStr::Append(this: out, text: (char *)aiSubWebNames[v7]);
  }
}


// ========================================================================
// ??0idAIAnimWebState_Idle@@QAA@PBVidAI2@@W4aiSubWeb_t@@W4posture_t@@W4equipSlot_t@@@Z
// EA  : 0x82A62E58
// RVA : 0x00A62E58
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState_Idle *__fastcall idAIAnimWebState_Idle::idAIAnimWebState_Idle(
        idAIAnimWebState_Idle *this,
        idAI2 *ai,
        aiSubWeb_t subweb,
        posture_t posture,
        equipSlot_t useWeaponSlot)
{
  idAnimWebState *v5; // r28
  idStr v12; // [sp+50h] [-90h] BYREF
  idStr v13[3]; // [sp+70h] [-70h] BYREF

  v5 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  v13[0].len = 0;
  v13[0].allocedAndFlag = 20;
  this->__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState_Idle::`vftable';
  v13[0].data = v13[0].baseBuffer;
  v13[0].baseBuffer[0] = 0;
  idAIAnimWebState::GetSubwebString(ai, out: v13, subWeb: subweb, posture, useWeaponSlot);
  v12.allocedAndFlag = 20;
  v12.data = v12.baseBuffer;
  v12.len = 0;
  v12.baseBuffer[0] = 0;
  idAI2::GetIdleStateName(this: ai, name: &v12);
  idAnimWebState::Init(
    this: v5,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _subweb: v13[0].data,
    _state: v12.data);
  idStr::FreeData(this: &v12);
  idStr::FreeData(this: v13);
  return this;
}


// ========================================================================
// __unwind$489437
// EA  : 0x82A62F24
// RVA : 0x00A62F24
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489437()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: *(idAIAnimWebState_Current **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$489438
// EA  : 0x82A62F4C
// RVA : 0x00A62F4C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489438()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$489439
// EA  : 0x82A62F74
// RVA : 0x00A62F74
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489439()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ??0idAIAnimWebState_Movement@@QAA@PBVidAI2@@PBDW4aiSubWeb_t@@W4posture_t@@@Z
// EA  : 0x82A62FA8
// RVA : 0x00A62FA8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState_Movement *__fastcall idAIAnimWebState_Movement::idAIAnimWebState_Movement(
        idAIAnimWebState_Movement *this,
        idAI2 *ai,
        char *postfix,
        aiSubWeb_t subweb,
        posture_t posture)
{
  idAnimWebState *v5; // r23
  walkState_t v11; // r3
  idStr v13; // [sp+50h] [-90h] BYREF
  idStr v14[3]; // [sp+70h] [-70h] BYREF

  v5 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  this->__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState_Movement::`vftable';
  if ( subweb == AISUBWEB_MAX )
  {
    subweb = ai->aiVolatile.animation.subWeb;
    if ( (unsigned int)subweb >= AISUBWEB_HOSTILE && subweb != AISUBWEB_MELEE )
      subweb = idAI2::AlertCycleToSubWeb(this: ai, ac: 1);
  }
  v14[0].len = 0;
  v14[0].allocedAndFlag = 20;
  v14[0].data = v14[0].baseBuffer;
  v14[0].baseBuffer[0] = 0;
  idAIAnimWebState::GetSubwebString(ai, out: v14, subWeb: subweb, posture, useWeaponSlot: EQUIP_MAX);
  v13.allocedAndFlag = 20;
  v13.data = v13.baseBuffer;
  v13.len = 0;
  v13.baseBuffer[0] = 0;
  v11 = ai->GetWalkState(this: ai);
  idStr::operator=(this: &v13, text: walkStateNames[v11]);
  if ( postfix != nullptr )
    idStr::Append(this: &v13, text: postfix);
  idAnimWebState::Init(
    this: v5,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _subweb: v14[0].data,
    _state: v13.data);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: v14);
  return this;
}


// ========================================================================
// __unwind$489919
// EA  : 0x82A630DC
// RVA : 0x00A630DC
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489919()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: *(idAIAnimWebState_Current **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$489920
// EA  : 0x82A63104
// RVA : 0x00A63104
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489920()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$489921
// EA  : 0x82A6312C
// RVA : 0x00A6312C
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_489921()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ??0idAIAnimWebState@@QAA@PBVidAI2@@W4aiSubWeb_t@@PBD@Z
// EA  : 0x82A631B8
// RVA : 0x00A631B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

idAIAnimWebState *__fastcall idAIAnimWebState::idAIAnimWebState(
        idAIAnimWebState *this,
        idAI2 *ai,
        aiSubWeb_t subweb,
        const char *stateName)
{
  idAnimWebState *v4; // r29
  idStr v10[3]; // [sp+50h] [-60h] BYREF

  v4 = &this->idAnimWebState;
  idAnimWebState::idAnimWebState(this: &this->idAnimWebState);
  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  this->__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  idAIAnimWebState::GetSubwebString(ai, out: v10, subWeb: subweb, posture: POSTURE_MAX, useWeaponSlot: EQUIP_MAX);
  idAnimWebState::Init(
    this: v4,
    decl: ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    _subweb: v10[0].data,
    _state: stateName);
  idStr::FreeData(this: v10);
  return this;
}


// ========================================================================
// __unwind$490396
// EA  : 0x82A63254
// RVA : 0x00A63254
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.cpp
// ========================================================================

void _unwind_490396()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}

