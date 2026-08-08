
// ========================================================================
// ??0idAIStateLite@@QAA@XZ
// EA  : 0x82A692C0
// RVA : 0x00A692C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAIStateLite *__fastcall idAIStateLite::idAIStateLite(idAIStateLite *this)
{
  idEventReceiver::idEventReceiver(this);
  this->subState = -1;
  this->__vftable = (idAIStateLite_vtbl *)&idAIStateLite::`vftable';
  return this;
}


// ========================================================================
// ?SetSubState@idAIStateLite@@IAAXH@Z
// EA  : 0x82A69308
// RVA : 0x00A69308
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIStateLite::SetSubState(idAIStateLite *this, int newSubState)
{
  if ( this->subState != newSubState )
    this->subState = newSubState;
}


// ========================================================================
// ??0idAIFSMLite@@QAA@XZ
// EA  : 0x82A69320
// RVA : 0x00A69320
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAIFSMLite *__fastcall idAIFSMLite::idAIFSMLite(idAIFSMLite *this)
{
  idEventReceiver::idEventReceiver(this);
  this->ai = nullptr;
  this->__vftable = (idAIFSMLite_vtbl *)&idAIFSMLite::`vftable';
  this->defaultState = nullptr;
  this->currentState = nullptr;
  this->stateStartTime = 0;
  this->currentlyUpdating = false;
  return this;
}


// ========================================================================
// ??1idAIFSMLite@@UAA@XZ
// EA  : 0x82A69378
// RVA : 0x00A69378
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIFSMLite::~idAIFSMLite(idAIFSMLite *this)
{
  this->__vftable = (idAIFSMLite_vtbl *)&idAIFSMLite::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// ?Init@idAIFSMLite@@QAAXPAVidAI2@@@Z
// EA  : 0x82A69388
// RVA : 0x00A69388
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIFSMLite::Init(idAIFSMLite *this, idAI2 *ai)
{
  idAIFSMLite_vtbl *v3; // r30
  int v5; // r3
  int i; // r30
  idAIStateLite *defaultState; // r3
  const char *Classname; // r3

  this->ai = ai;
  v3 = this->__vftable;
  v5 = this->GetDefaultStateId(this);
  this->defaultState = v3->GetState(this, a2: v5);
  for ( i = 0; i < this->GetNumStates(this); ++i )
    ;
  this->InternalInit(this);
  defaultState = this->defaultState;
  if ( defaultState == nullptr )
  {
    Classname = idClass::GetClassname(this);
    idLib::Error(fmt: "FSM %s has no default state\n", Classname);
    JUMPOUT(0x82A69464);
  }
  this->currentState = defaultState;
  defaultState->InternalEnter(this: defaultState, a2: ai, a3: this);
}


// ========================================================================
// ?RegisterBlendVariables@idAnimBaseFSM@@UAAXPAVidAnimator_AnimWeb@@@Z
// EA  : 0x82A69468
// RVA : 0x00A69468
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::RegisterBlendVariables(idAnimBaseFSM *this, idAnimator_AnimWeb *web)
{
  this->animBlendVars.animDepartureSelect.index = idAnimator_AnimWeb::AddBlendVariable(
                                                    this: web,
                                                    name: "departureSelect",
                                                    scalar: &this->animBlendVars.animDepartureSelect.value,
                                                    flags: FF_NO_OVERRIDE);
  this->animBlendVars.animArrivalSelect.index = idAnimator_AnimWeb::AddBlendVariable(
                                                  this: web,
                                                  name: "arrivalSelect",
                                                  scalar: &this->animBlendVars.animArrivalSelect.value,
                                                  flags: FF_NO_OVERRIDE);
  this->animBlendVars.animStepSelect.index = idAnimator_AnimWeb::AddBlendVariable(
                                               this: web,
                                               name: "stepSelect",
                                               scalar: &this->animBlendVars.animStepSelect.value,
                                               flags: FF_NO_OVERRIDE);
  this->animBlendVars.animTurnSelect.index = idAnimator_AnimWeb::AddBlendVariable(
                                               this: web,
                                               name: "turnSelect",
                                               scalar: &this->animBlendVars.animTurnSelect.value,
                                               flags: FF_NO_OVERRIDE);
  this->animBlendVars.animClimbSelect.index = idAnimator_AnimWeb::AddBlendVariable(
                                                this: web,
                                                name: "climbSelect",
                                                scalar: &this->animBlendVars.animClimbSelect.value,
                                                flags: FF_NO_OVERRIDE);
  this->animBlendVars.animFallHeightIndex.index = idAnimator_AnimWeb::AddBlendVariable(
                                                    this: web,
                                                    name: "fallHeightIndex",
                                                    scalar: &this->animBlendVars.animFallHeightIndex.value,
                                                    flags: FF_NO_OVERRIDE);
  this->animBlendVars.bodyLookYaw.index = idAnimator_AnimWeb::AddBlendVariable(
                                            this: web,
                                            name: "bodyLookYaw",
                                            scalar: &this->animBlendVars.bodyLookYaw.value,
                                            flags: FF_NO_OVERRIDE);
  this->animBlendVars.bodyAimYaw.index = idAnimator_AnimWeb::AddBlendVariable(
                                           this: web,
                                           name: "bodyAimYaw",
                                           scalar: &this->animBlendVars.bodyAimYaw.value,
                                           flags: FF_NO_OVERRIDE);
  this->animBlendVars.bodyAimPitch.index = idAnimator_AnimWeb::AddBlendVariable(
                                             this: web,
                                             name: "bodyAimPitch",
                                             scalar: &this->animBlendVars.bodyAimPitch.value,
                                             flags: FF_NO_OVERRIDE);
  this->animBlendVars.bodyMoveAngle.index = idAnimator_AnimWeb::AddBlendVariable(
                                              this: web,
                                              name: "bodyMoveAngle",
                                              scalar: &this->animBlendVars.bodyMoveAngle.value,
                                              flags: FF_NO_OVERRIDE);
}


// ========================================================================
// ?SetPuppetMode@idAnimBaseFSM@@QAAX_NW4puppetModeTypes_t@@@Z
// EA  : 0x82A695B8
// RVA : 0x00A695B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::SetPuppetMode(idAnimBaseFSM *this, bool enable, puppetModeTypes_t reason)
{
  unsigned __int8 puppetModeMask; // r11

  puppetModeMask = this->puppetModeMask;
  if ( enable )
    this->puppetModeMask = puppetModeMask | reason;
  else
    this->puppetModeMask = puppetModeMask & ~(_BYTE)reason;
}


// ========================================================================
// ?ReachedDestination@idAnimBaseFSM@@UBA_NXZ
// EA  : 0x82A695E0
// RVA : 0x00A695E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::ReachedDestination(idAnimBaseFSM *this)
{
  return (_cntlzw(this->reachedDestFlagsExpected - (this->reachedDestFlags & this->reachedDestFlagsExpected)) & 0x20) != 0;
}


// ========================================================================
// ?ReachedDestination@idAnimBaseFSM@@UBA_NH@Z
// EA  : 0x82A69600
// RVA : 0x00A69600
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::ReachedDestination(idAnimBaseFSM *this, const int checkFlag)
{
  return (_cntlzw(checkFlag - (this->reachedDestFlags & checkFlag)) & 0x20) != 0;
}


// ========================================================================
// ?AnimFinishBlend@idAnimFSM@@UAAXPBVidDeclAnimWebNode@@0@Z
// EA  : 0x82A69698
// RVA : 0x00A69698
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimFSM::AnimFinishBlend(
        idAnimFSM *this,
        const idDeclAnimWebNode *prevNode,
        const idDeclAnimWebNode *curNode)
{
  idAnimBaseFSM::CheckResetAnimDeltaCorrection(this, node: prevNode);
}


// ========================================================================
// ?GetClosestReachableAreas@idAnimFSM_NP@@UBAHABVidVec3@@MHQAVidNpAreaHandle@@@Z
// EA  : 0x82A696A0
// RVA : 0x00A696A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_NP::GetClosestReachableAreas(
        idAnimFSM_NP *this,
        const idVec3 *dstPos,
        double radius,
        int maxAreas,
        idNpAreaHandle *handles)
{
  idNpNavigator *groundNavigator; // r3

  groundNavigator = this->groundNavigator;
  if ( groundNavigator != nullptr )
    return idNpNavigator::GetClosestReachableAreas(
             this: groundNavigator,
             dstPos,
             radius,
             maxNumAreas: maxAreas,
             areasOut: handles);
  idLib::Printf(fmt: "No Navigator!\n", dstPos, maxAreas, handles, radius);
  return 0;
}


// ========================================================================
// ?CanRotateBodyIndepentlyOfMove@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A696F0
// RVA : 0x00A696F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::CanRotateBodyIndepentlyOfMove(idAnimBaseFSM *this)
{
  return this->currentMove.allowStrafing;
}


// ========================================================================
// ?GetSubStateName@idAIStateLite@@IBAPBDH@Z
// EA  : 0x82A698E8
// RVA : 0x00A698E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

const char *__fastcall idAIStateLite::GetSubStateName(idAIStateLite *this, int stateId)
{
  idTypeInfo *v3; // r31
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  va *v7; // r3
  const char *result; // r3
  int v9; // [sp+8h] [-1078h]
  int v10; // [sp+Ch] [-1074h]
  int v11; // [sp+10h] [-1070h]
  int v12; // [sp+14h] [-106Ch]
  int v13; // [sp+18h] [-1068h]
  int v14; // [sp+1Ch] [-1064h]
  va v15; // [sp+50h] [-1030h] BYREF

  v3 = (idTypeInfo *)this->GetType(this);
  if ( v3 == &idAIStateLite::Type )
    return nullptr;
  while ( 1 )
  {
    HIDWORD(v6) = v3->classname;
    v7 = va::va(
           this: &v15,
           fmt: "%s::subState_t",
           a3: v6,
           a4: v5,
           a5: v4,
           a6: v9,
           a7: v10,
           a8: v11,
           a9: v12,
           a10: v13,
           a11: v14);
    result = idTypeInfoTools::GetEnumName(
               this: typeInfoTools,
               enumTypeName: v7->buffer,
               enumValue: stateId,
               defaultValue: nullptr);
    if ( result != nullptr )
      break;
    v3 = v3->super;
    if ( v3 == &idAIStateLite::Type )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?PrintDebugInfo@idAIStateLite@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A69978
// RVA : 0x00A69978
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIStateLite::PrintDebugInfo(idAIStateLite *this, idGuiListBox *info)
{
  const char *SubStateName; // r3
  const char *v4; // r31
  idGuiListBox *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idGuiListBox *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6

  SubStateName = idAIStateLite::GetSubStateName(this, stateId: this->subState);
  if ( SubStateName != nullptr )
    v4 = SubStateName;
  else
    v4 = "-";
  v5 = idGuiListBox::Row(this: info);
  v9 = idGuiListBox::Printf(this: v5, fmt: "SubState", a3: v8, a4: v7, a5: v6);
  idGuiListBox::Printf(this: v9, fmt: v4, a3: v12, a4: v11, a5: v10);
}


// ========================================================================
// ?ChangeState@idAIFSMLite@@QAAXH@Z
// EA  : 0x82A69A50
// RVA : 0x00A69A50
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIFSMLite::ChangeState(idAIFSMLite *this, const int destStateId)
{
  int valueInteger; // r29
  idClass *v4; // r3
  idAIStateLite *v5; // r30
  const char *Classname; // r28
  const char *v7; // r3
  idAIStateLite *currentState; // r3
  const char *v9; // r3
  const char *v10; // r3
  void (*InternalReEnter)(void); // r10
  const char *v12; // r3

  valueInteger = ai_debugMoveFSM.valueInteger;
  v4 = (idClass *)((int (__fastcall *)(idAIFSMLite *))this->GetState)(a1: this);
  v5 = (idAIStateLite *)v4;
  if ( v4 != nullptr )
  {
    if ( valueInteger > 1 )
    {
      Classname = idClass::GetClassname(this: v4);
      v7 = idClass::GetClassname(this: this->currentState);
      idLib::Printf(fmt: "%s::Work( transition %s )\n", v7, Classname);
    }
    currentState = this->currentState;
    if ( currentState == v5 )
    {
      if ( valueInteger > 0 )
      {
        v12 = idClass::GetClassname(this: currentState);
        idLib::Printf(fmt: "%s::ReEnter\n", v12);
      }
      InternalReEnter = (void (*)(void))this->currentState->InternalReEnter;
    }
    else
    {
      if ( valueInteger > 0 )
      {
        v9 = idClass::GetClassname(this: currentState);
        idLib::Printf(fmt: "%s::Exit\n", v9);
      }
      this->currentState->InternalExit(this: this->currentState, a2: this->ai, a3: this);
      this->currentState = v5;
      if ( valueInteger > 0 )
      {
        v10 = idClass::GetClassname(this: v5);
        idLib::Printf(fmt: "%s::Enter\n", v10);
      }
      InternalReEnter = (void (*)(void))this->currentState->InternalEnter;
    }
    InternalReEnter();
    this->stateStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?InternalCallEvent@idAIFSMLite@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82A69B90
// RVA : 0x00A69B90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAIFSMLite *__fastcall idAIFSMLite::InternalCallEvent(
        idAIFSMLite *this,
        idEventArg *result,
        const idEventDef *event,
        const idEventArg *args)
{
  const char *EnumName; // r3
  idEventArg *v7; // r4

  if ( event->type == EVENT_FSMEVENT )
  {
    v7 = *(idEventArg **)&result[1].type;
    if ( v7 != nullptr )
    {
      idEventReceiver::ProcessEventArgPtr(this, result: v7, ev: event, args);
      return this;
    }
  }
  else
  {
    EnumName = idTypeInfoTools::GetEnumName(
                 this: typeInfoTools,
                 enumTypeName: "eventType_t",
                 enumValue: event->type,
                 defaultValue: "<unknown>");
    idLib::Warning(fmt: "idAIFSMLite::InternalCallEvent() doesn't handle %s event type.", EnumName);
  }
  this->listenerList = nullptr;
  HIBYTE(this->__vftable) = 0;
  return this;
}


// ========================================================================
// ?InternalRespondsTo@idAIFSMLite@@MBA_NABVidEventDef@@@Z
// EA  : 0x82A69C20
// RVA : 0x00A69C20
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAIFSMLite::InternalRespondsTo(idAIFSMLite *this, const idEventDef *event)
{
  idAIStateLite *currentState; // r11

  return event->type == EVENT_FSMEVENT
      && (currentState = this->currentState) != nullptr
      && ((bool (*)(void))currentState->RespondsTo)();
}


// ========================================================================
// ?InitTransform@idAnimBaseFSM@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82A69EE8
// RVA : 0x00A69EE8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::InitTransform(idAnimBaseFSM *this, const idVec3 *origin, const idMat3 *axis)
{
  idAIOrientation::Init(this: &this->orientMove, axis);
  idAIOrientation::Init(this: &this->orientBody, axis);
}


// ========================================================================
// ?GetUserChannelValue@idAnimBaseFSM@@QBAMW4userChannelId_t@1@@Z
// EA  : 0x82A69F38
// RVA : 0x00A69F38
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetUserChannelValue(idAnimBaseFSM *this, idAnimBaseFSM::userChannelId_t chanId)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  __int32 v5; // r11
  double BlendedUserChannel; // fp1

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  v5 = 2 * (chanId + 1496);
  if ( *(unsigned __int16 *)((char *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable + v5) >= 0x8000u )
    BlendedUserChannel = 0.0;
  else
    BlendedUserChannel = idTreeAnimator::GetBlendedUserChannel(
                           this: TreeAnimatorFromPresentable,
                           index: (idIndex<short,enum invalidUserChannelIndex_t> *)*(unsigned __int16 *)((char *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable
                                                                                                + v5));
  return *((float *)&BlendedUserChannel + 1);
}


// ========================================================================
// ?GetUserChannelIsMoving@idAnimBaseFSM@@QBA_NW4walkState_t@@@Z
// EA  : 0x82A69FA0
// RVA : 0x00A69FA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::GetUserChannelIsMoving(idAnimBaseFSM *this, const walkState_t threshold)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double BlendedUserChannel; // fp1
  unsigned __int8 v6; // r11
  unsigned __int8 v8; // r11
  unsigned __int8 v9; // r11

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  if ( (unsigned __int16)this->userChannels[0].value >= 0x8000u )
    return 0;
  BlendedUserChannel = idTreeAnimator::GetBlendedUserChannel(
                         this: TreeAnimatorFromPresentable,
                         index: (idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)this->userChannels[0].value);
  switch ( threshold )
  {
    case WALKSTATE_WALKING:
      if ( BlendedUserChannel < 0.5 )
        return 0;
      v9 = 1;
      if ( BlendedUserChannel >= 1.5 )
        return 0;
      return v9;
    case WALKSTATE_RUNNING:
      if ( BlendedUserChannel < 1.5 )
        return 0;
      v8 = 1;
      if ( BlendedUserChannel >= 2.5 )
        return 0;
      return v8;
    case WALKSTATE_SPRINTING:
      if ( BlendedUserChannel < 2.5 )
        return 0;
      v6 = 1;
      if ( BlendedUserChannel >= 3.5 )
        return 0;
      return v6;
    default:
      return 0;
  }
}


// ========================================================================
// ?GetUserChannelIsDeltaDriven@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A6A0A0
// RVA : 0x00A6A0A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::GetUserChannelIsDeltaDriven(idAnimBaseFSM *this)
{
  int result; // r3
  idAnimBaseFSM::deltaMode_t animDeltaMode; // r11

  if ( (this->currentState->GetStateFlags(this: this->currentState) & 4) != 0 )
    return 1;
  if ( idAnimBaseFSM::GetUserChannelValue(this, chanId: CHAN_STEER) != 0.0 )
    return 0;
  animDeltaMode = this->animDeltaMode;
  if ( animDeltaMode <= ANIMDELTAMODE_DEFAULT )
    return 0;
  result = 1;
  if ( animDeltaMode > ANIMDELTAMODE_FULL_DRIVE_AI )
    return 0;
  return result;
}


// ========================================================================
// ?GetUserChannelUseGravity@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A6A138
// RVA : 0x00A6A138
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::GetUserChannelUseGravity(idAnimBaseFSM *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int result; // r3
  idAnimBaseFSM::deltaMode_t animDeltaMode; // r11

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  if ( (unsigned __int16)this->userChannels[4].value < 0x8000u
    && idTreeAnimator::GetBlendedUserChannel(
         this: TreeAnimatorFromPresentable,
         index: (idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)this->userChannels[4].value) > 0.0 )
  {
    return 1;
  }
  animDeltaMode = this->animDeltaMode;
  if ( animDeltaMode < ANIMDELTAMODE_DRIVEN_GRAVITY )
    return 0;
  result = 1;
  if ( animDeltaMode > ANIMDELTAMODE_FULL_DRIVE_AI )
    return 0;
  return result;
}


// ========================================================================
// ?GetPathPositionAndDirection@idAnimBaseFSM@@UBAHABUpathPositionAndDirectionParms_t@1@AAVidVec3@@1@Z
// EA  : 0x82A6A1C0
// RVA : 0x00A6A1C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::GetPathPositionAndDirection(
        idAnimBaseFSM *this,
        const idAnimBaseFSM::pathPositionAndDirectionParms_t *parms,
        idVec3 *outPosition,
        idVec3 *outDirection)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this: this->ai);
  *outPosition = *Physics->GetOrigin(this: Physics, a2: 0);
  *outDirection = this->orientBody.axis.mat[0];
  return -1;
}


// ========================================================================
// ?HasDestination@idAnimBaseFSM@@UBA_NXZ
// EA  : 0x82A6A238
// RVA : 0x00A6A238
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::HasDestination(idAnimBaseFSM *this)
{
  return this->currentMove.destType != MOVE_NONE;
}


// ========================================================================
// ?CacheNextPoints@idAnimBaseFSM@@QAAXPBUidAIMoveInfo@@@Z
// EA  : 0x82A6A378
// RVA : 0x00A6A378
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::CacheNextPoints(idAnimBaseFSM *this, const idAIMoveInfo *destination)
{
  int num; // r24
  int v5; // r29
  int v6; // r25
  idNpCornerInfo *v7; // r11
  int v8; // r27
  char v9; // r28
  char v10; // r30
  double v11; // fp10
  double v12; // fp7
  double y; // fp13
  double v14; // fp4
  double v15; // fp12
  double v16; // fp5
  double v17; // fp3
  double v18; // fp2
  double v21; // fp4
  double v22; // fp4
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp5
  double v30; // fp4
  double v31; // fp3
  float x; // [sp+50h] [-A0h]
  float v33; // [sp+54h] [-9Ch]
  float z; // [sp+58h] [-98h]
  idMat3 v35; // [sp+60h] [-90h] BYREF

  num = this->cachedCorners.num;
  this->nextArrivalCorner = -1;
  v5 = 0;
  this->nextLinkCorner = -1;
  if ( num > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = &this->cachedCorners.list[v6];
      if ( (*((_BYTE *)v7 + 56) & 0x80) != 0 && destination->arrivalAction >= AIARRIVAL_STOP )
        break;
      v8 = v5 + 1;
      if ( num <= v5 + 1 )
        goto LABEL_26;
      if ( (*((_BYTE *)v7 + 56) & 0x40) == 0 || (v9 = 1, this->nextArrivalCorner != -1) )
        v9 = 0;
      if ( v7->cornerType != CORNER_LINKSTART
        || v7[1].cornerType != CORNER_LINKEND
        || (v10 = 1, this->nextLinkCorner != -1) )
      {
        v10 = 0;
      }
      if ( (*((_BYTE *)v7 + 56) & 0x40) == 0 && v10 == 0 )
        goto LABEL_26;
      v11 = (float)(v7[1].position.z - v7->position.z);
      v12 = (float)(v7[1].position.y - v7->position.y);
      y = v7->areaNormal.y;
      x = v7->position.x;
      v14 = (float)(v7[1].position.x - x);
      v33 = v7->position.y;
      v15 = v7->areaNormal.x;
      z = v7->position.z;
      v35.mat[2].z = v7->areaNormal.z;
      v35.mat[2].y = y;
      v35.mat[2].x = v15;
      v16 = (float)((float)v12
                  - (float)((float)y
                          * (float)((float)((float)v15 * (float)v14)
                                  + (float)((float)((float)v12 * (float)y) + (float)((float)v11 * v35.mat[2].z)))));
      v17 = (float)((float)v11
                  - (float)(v35.mat[2].z
                          * (float)((float)((float)v15 * (float)v14)
                                  + (float)((float)((float)v12 * (float)y) + (float)((float)v11 * v35.mat[2].z)))));
      v18 = (float)((float)v14
                  - (float)((float)v15
                          * (float)((float)((float)v15 * (float)v14)
                                  + (float)((float)((float)v12 * (float)y) + (float)((float)v11 * v35.mat[2].z)))));
      _FP8 = (float)((float)((float)((float)v18 * (float)v18)
                           + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f6, f8, f9, f11 }
      v21 = __frsqrte(_FP6);
      v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                          * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v21)
                                                                          - (float)1.5)
                                                          * (float)v21)
                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                  + (float)((float)((float)v17 * (float)v17)
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v21
                                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                  + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                          * (float)0.5))
                                                                          * (float)v21)
                                                                  - (float)1.5)
                                                  * (float)v21))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v21
                                                          * (float)((float)((float)((float)v18 * (float)v18)
                                                                          + (float)((float)((float)v17 * (float)v17)
                                                                                  + (float)((float)v16 * (float)v16)))
                                                                  * (float)0.5))
                                                  * (float)v21)
                                          - (float)1.5)
                          * (float)v21));
      v35.mat[0].x = (float)v18
                   * (float)((float)-(float)((float)((float)((float)v22
                                                           * (float)((float)((float)((float)v18 * (float)v18)
                                                                           + (float)((float)((float)v17 * (float)v17)
                                                                                   + (float)((float)v16 * (float)v16)))
                                                                   * (float)0.5))
                                                   * (float)v22)
                                           - (float)1.5)
                           * (float)v22);
      v35.mat[0].y = (float)v16
                   * (float)((float)-(float)((float)((float)((float)v22
                                                           * (float)((float)((float)((float)v18 * (float)v18)
                                                                           + (float)((float)((float)v17 * (float)v17)
                                                                                   + (float)((float)v16 * (float)v16)))
                                                                   * (float)0.5))
                                                   * (float)v22)
                                           - (float)1.5)
                           * (float)v22);
      v35.mat[0].z = (float)v17
                   * (float)((float)-(float)((float)((float)((float)v22
                                                           * (float)((float)((float)((float)v18 * (float)v18)
                                                                           + (float)((float)((float)v17 * (float)v17)
                                                                                   + (float)((float)v16 * (float)v16)))
                                                                   * (float)0.5))
                                                   * (float)v22)
                                           - (float)1.5)
                           * (float)v22);
      v35.mat[1].z = (float)((float)v15 * v35.mat[0].y) - (float)((float)y * v35.mat[0].x);
      v35.mat[1].x = (float)((float)y * v35.mat[0].z) - (float)(v35.mat[2].z * v35.mat[0].y);
      v35.mat[1].y = (float)(v35.mat[2].z * v35.mat[0].x) - (float)((float)v15 * v35.mat[0].z);
      idMat3::OrthoNormalizeSelf(this: &v35);
      v23 = v35.mat[2].z;
      v24 = v35.mat[2].y;
      v25 = v35.mat[2].x;
      v26 = v35.mat[1].z;
      v27 = v35.mat[1].y;
      v28 = v35.mat[1].x;
      v29 = v35.mat[0].z;
      v30 = v35.mat[0].y;
      v31 = v35.mat[0].x;
      if ( v10 != 0 )
      {
        this->nextLinkCorner = v5;
        this->nextLinkPos.x = x;
        this->nextLinkPos.y = v33;
        this->nextLinkPos.z = z;
        this->nextLinkAxis.mat[0].x = v31;
        this->nextLinkAxis.mat[1].x = v28;
        this->nextLinkAxis.mat[0].y = v30;
        this->nextLinkAxis.mat[0].z = v29;
        this->nextLinkAxis.mat[1].y = v27;
        this->nextLinkAxis.mat[1].z = v26;
        this->nextLinkAxis.mat[2].x = v25;
        this->nextLinkAxis.mat[2].y = v24;
        this->nextLinkAxis.mat[2].z = v23;
      }
      if ( v9 != 0 )
      {
        this->nextArrivalPos.x = x;
        this->nextArrivalPos.y = v33;
        this->nextArrivalPos.z = z;
        this->nextArrivalAxis.mat[0].x = v31;
        this->nextArrivalAxis.mat[1].x = v28;
        this->nextArrivalAxis.mat[0].y = v30;
        this->nextArrivalAxis.mat[0].z = v29;
        this->nextArrivalAxis.mat[1].y = v27;
        this->nextArrivalAxis.mat[1].z = v26;
        this->nextArrivalAxis.mat[2].x = v25;
        this->nextArrivalAxis.mat[2].y = v24;
        this->nextArrivalAxis.mat[2].z = v23;
        this->nextArrivalCorner = v5;
      }
      if ( this->nextLinkCorner == -1 || this->nextArrivalCorner == -1 )
      {
LABEL_26:
        ++v5;
        ++v6;
        if ( v8 < num )
          continue;
      }
      return;
    }
    this->nextArrivalPos.x = destination->destPosition.x;
    this->nextArrivalPos.y = destination->destPosition.y;
    this->nextArrivalPos.z = destination->destPosition.z;
    this->nextArrivalAxis.mat[0].x = destination->destOrientation.mat[0].x;
    this->nextArrivalAxis.mat[0].y = destination->destOrientation.mat[0].y;
    this->nextArrivalAxis.mat[0].z = destination->destOrientation.mat[0].z;
    this->nextArrivalAxis.mat[1].x = destination->destOrientation.mat[1].x;
    this->nextArrivalAxis.mat[1].y = destination->destOrientation.mat[1].y;
    this->nextArrivalAxis.mat[1].z = destination->destOrientation.mat[1].z;
    this->nextArrivalAxis.mat[2].x = destination->destOrientation.mat[2].x;
    this->nextArrivalAxis.mat[2].y = destination->destOrientation.mat[2].y;
    this->nextArrivalAxis.mat[2].z = destination->destOrientation.mat[2].z;
    this->nextArrivalCorner = v5;
  }
}


// ========================================================================
// ?UpdateTurnTransitionCache@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A6A6D0
// RVA : 0x00A6A6D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::UpdateTurnTransitionCache(idAnimBaseFSM *this)
{
  idAIAnimWebState_Current v2[2]; // [sp+50h] [-40h] BYREF

  idAIAnimWebState_Current::idAIAnimWebState_Current(this: v2, ai: this->ai);
  if ( idAnimWebState::operator!=(this: &this->turnTransitionCache.srcState, other: &v2[0].idAnimWebState) )
    idAnimWebTransitions::InitTransitionCache(
      ai: this->ai,
      cache: &this->turnTransitionCache,
      srcState: (idAnimWebPath *)&v2[0].idAnimWebState,
      dstState: (idAnimWebPath *)&v2[0].idAnimWebState,
      nodeCheckFlags: 8,
      additionalSubweb: nullptr);
}


// ========================================================================
// __unwind$495446
// EA  : 0x82A6A734
// RVA : 0x00A6A734
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_495446()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 144 + 80));
}


// ========================================================================
// ?UpdateBlendVariables@idAnimBaseFSM@@MAAXXZ
// EA  : 0x82A6A760
// RVA : 0x00A6A760
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::UpdateBlendVariables(idAnimBaseFSM *this)
{
  double v2; // fp31
  idPlayer *DebugPlayer; // r30
  idPhysics *Physics; // r3
  float *v5; // r28
  idPhysics *v6; // r3
  float *v7; // r3
  double v8; // fp9
  double v9; // fp7
  float *v10; // r3
  double x; // fp13
  double v12; // fp7
  double v13; // fp6
  const idVec3 *(__fastcall *GetNavUpAxis)(idAnimBaseFSM *, const idVec3 *); // ctr
  double v15; // fp4
  double v16; // fp3
  const idVec3 *v17; // r3
  const idVec3 *v18; // r3
  double v19; // fp1
  double v20; // fp1
  int v21; // r3
  double value; // fp1
  _QWORD v23[2]; // [sp+50h] [-80h] BYREF
  idVec3 v24; // [sp+60h] [-70h] BYREF
  idMat3 v25; // [sp+70h] [-60h] BYREF

  v2 = 0.0;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = idEntity::GetPhysics(this: DebugPlayer);
    v7 = (float *)v6->GetOrigin(this: v6, a2: 0);
    v8 = (float)(v7[2] - v5[2]);
    v9 = (float)(v7[1] - v5[1]);
    v24.x = *v7 - *v5;
    v24.z = v8;
    v24.y = v9;
    v10 = (float *)idMat3::Inverse(this: &v25, result: &this->orientBody.axis);
    x = v24.x;
    v12 = v10[1];
    v13 = v10[2];
    GetNavUpAxis = this->GetNavUpAxis;
    v15 = (float)((float)(v10[7] * v24.z) + (float)(v10[4] * v24.y));
    v16 = (float)((float)(v10[8] * v24.z) + (float)(v10[5] * v24.y));
    v24.x = (float)(*v10 * v24.x) + (float)((float)(v10[6] * v24.z) + (float)(v10[3] * v24.y));
    v24.y = (float)((float)v12 * (float)x) + (float)v15;
    v24.z = (float)((float)v13 * (float)x) + (float)v16;
    v17 = GetNavUpAxis(this: (idAnimBaseFSM *)v23, result: (const idVec3 *)this);
    idVec3::ProjectOntoPlane(this: &v24, normal: v17, overBounce: 1.0);
    v18 = this->GetNavUpAxis(this: v23, result: this);
    v19 = idVec3::ToYaw(this: &v24, up: v18);
    v20 = idMath::AngleNormalize360(angle: v19);
    if ( v20 > 180.0 )
      v20 = (float)((float)v20 - (float)360.0);
    v2 = v20;
  }
  v21 = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  value = this->animBlendVars.bodyLookYaw.value;
  v23[0] = __PAIR64__(&unk_82390000, v21);
  this->animBlendVars.bodyLookYaw.value = LerpToWithRate(
                                            cur: value,
                                            dest: v2,
                                            absRate: (float)((float)((float)__SPAIR64__(&unk_82390000, v21) * (float)0.001)
                                                  * (float)90.0));
}


// ========================================================================
// ?InitTransform@idAnimFSM_NP@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82A6A948
// RVA : 0x00A6A948
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::InitTransform(idAnimFSM_NP *this, const idVec3 *origin, const idMat3 *axis)
{
  idNpNavigator *groundNavigator; // r3

  groundNavigator = this->groundNavigator;
  if ( groundNavigator != nullptr )
    idNpNavigator::SetNavOrigin(this: groundNavigator, pos: origin);
  idAIOrientation::Init(this: &this->orientMove, axis);
  idAIOrientation::Init(this: &this->orientBody, axis);
}


// ========================================================================
// ?InternalUpdateBodyRotation@idAnimFSM@@MAAXXZ
// EA  : 0x82A6A9A8
// RVA : 0x00A6A9A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::InternalUpdateBodyRotation(idAnimFSM *this)
{
  idEntity *BindMaster; // r3
  idVec3 v3; // [sp+50h] [-50h] BYREF
  idMat3 v4; // [sp+60h] [-40h] BYREF

  if ( idEntity::GetBindMaster(this: this->ai) != nullptr )
  {
    BindMaster = idEntity::GetBindMaster(this: this->ai);
    BindMaster->GetModelTransform(this: BindMaster, a2: &v3, a3: &v4);
  }
}


// ========================================================================
// ?JobSync@idAnimFSM_NP@@UAAXXZ
// EA  : 0x82A6AA00
// RVA : 0x00A6AA00
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::JobSync(idAnimFSM_NP *this)
{
  idVec3 *p_position; // r4
  idPhysics *Physics; // r3

  if ( this->groundNavigator != nullptr )
  {
    if ( idNavigationSpace::IsValid(this: &this->linkTraversing) )
    {
      p_position = &this->linkEndCorner.position;
    }
    else
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      p_position = (idVec3 *)Physics->GetOrigin(this: Physics, a2: 0);
    }
    idNpNavigator::SetNavOrigin(this: this->groundNavigator, pos: p_position);
  }
}


// ========================================================================
// ?GetPathDelta@idAnimFSM_NP@@UBA?AVidVec3@@ABV2@M_N@Z
// EA  : 0x82A6AA80
// RVA : 0x00A6AA80
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM_NP *__fastcall idAnimFSM_NP::GetPathDelta(
        idAnimFSM_NP *this,
        idVec3 *result,
        const idVec3 *lastOrigin,
        double deltaLength,
        bool stopAtLink,
        bool a6)
{
  double v11; // fp10
  double v12; // fp7
  idNpNavigator::idNpAdvanceSpec v14; // [sp+50h] [-C0h] BYREF
  idNpNavigator::idAdvanceInfo v15; // [sp+60h] [-B0h] BYREF

  v14.stopAtLink = true;
  v14.distAhead = 0.0;
  idNpNavigator::idAdvanceInfo::idAdvanceInfo(this: &v15);
  v14.distAhead = deltaLength;
  v14.stopAtLink = a6;
  idNpNavigator::GetPosOnPath(this: (idNpNavigator *)LODWORD(result[1110].x), spec: &v14, advanceInfo: &v15);
  v11 = (float)(v15.advancePos.z - lastOrigin->z);
  v12 = (float)(v15.advancePos.y - lastOrigin->y);
  *(float *)&this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = v15.advancePos.x
                                                                                              - lastOrigin->x;
  *(float *)&this->listenerList = v12;
  *(float *)&this->listeningToList = v11;
  idNpNavigator::idAdvanceInfo::~idAdvanceInfo(this: &v15);
  return this;
}


// ========================================================================
// __unwind$495665_0
// EA  : 0x82A6AB24
// RVA : 0x00A6AB24
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_495665_0()
{
  int v0; // r12

  idNpNavigator::idAdvanceInfo::~idAdvanceInfo(this: (idNpNavigator::idAdvanceInfo *)(v0 - 272 + 96));
}


// ========================================================================
// ?HasGoalChangedSignificantly@idAnimBaseFSM@@QBA_NABVidVec3@@M@Z
// EA  : 0x82A6AB50
// RVA : 0x00A6AB50
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::HasGoalChangedSignificantly(idAnimBaseFSM *this, const idVec3 *newGoal, double cutoff)
{
  double v3; // fp11
  double v4; // fp8
  double v5; // fp5

  v3 = (float)(newGoal->z - this->moveDestOriginAtAnimStart.z);
  v4 = (float)(newGoal->x - this->moveDestOriginAtAnimStart.x);
  v5 = (float)(newGoal->y - this->moveDestOriginAtAnimStart.y);
  return (float)((float)((float)v5 * (float)v5)
               + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))) > (double)(float)((float)cutoff * (float)cutoff);
}


// ========================================================================
// ?AnimStartBlend@idAnimFSM@@UAAXPBVidDeclAnimWebNode@@0@Z
// EA  : 0x82A6AB98
// RVA : 0x00A6AB98
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::AnimStartBlend(
        idAnimFSM *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode)
{
  const idVec3 *v5; // r3
  const idMD6Anim *Anim; // r3
  const idMD6Anim *v7; // r30
  _BYTE v8[20]; // [sp+70h] [-F0h] BYREF
  _BYTE v9[20]; // [sp+90h] [-D0h] BYREF
  _DWORD v10[5]; // [sp+B0h] [-B0h] BYREF
  _DWORD v11[5]; // [sp+D0h] [-90h] BYREF
  int v12; // [sp+F0h] [-70h]
  int v13; // [sp+F4h] [-6Ch]
  const idEventArg *v14; // [sp+F8h] [-68h]
  int v15; // [sp+110h] [-50h]
  const idMD6Anim *v16; // [sp+114h] [-4Ch]
  const idEventArg *v17; // [sp+118h] [-48h]
  const idEventArg *v18; // [sp+11Ch] [-44h]

  if ( this->currentMove.destType != MOVE_NONE )
  {
    v5 = this->GetFinalPoint(this: &this->idAIMoveInterface);
    this->moveDestOriginAtAnimStart.x = v5->x;
    this->moveDestOriginAtAnimStart.y = v5->y;
    this->moveDestOriginAtAnimStart.z = v5->z;
    this->moveDestAxisAtAnimStart.mat[0].x = this->currentMove.arriveAxis.mat[0].x;
    this->moveDestAxisAtAnimStart.mat[0].y = this->currentMove.arriveAxis.mat[0].y;
    this->moveDestAxisAtAnimStart.mat[0].z = this->currentMove.arriveAxis.mat[0].z;
    this->moveDestAxisAtAnimStart.mat[1].x = this->currentMove.arriveAxis.mat[1].x;
    this->moveDestAxisAtAnimStart.mat[1].y = this->currentMove.arriveAxis.mat[1].y;
    this->moveDestAxisAtAnimStart.mat[1].z = this->currentMove.arriveAxis.mat[1].z;
    this->moveDestAxisAtAnimStart.mat[2].x = this->currentMove.arriveAxis.mat[2].x;
    this->moveDestAxisAtAnimStart.mat[2].y = this->currentMove.arriveAxis.mat[2].y;
    this->moveDestAxisAtAnimStart.mat[2].z = this->currentMove.arriveAxis.mat[2].z;
  }
  Anim = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: 0);
  v7 = Anim;
  if ( Anim != nullptr && Anim == this->pendingAnims.traversalDeltaCorrectionAnim )
  {
    idLib::Warning(
      fmt: "%s, traversal anim without delta correction events for scaling to endpoint, this should be fixed",
      Anim->name.str);
    v10[1] = 0;
    HIBYTE(v10[0]) = 105;
    v16 = v7;
    HIBYTE(v11[0]) = 105;
    v11[1] = 0;
    HIBYTE(v12) = 105;
    v13 = 9;
    HIBYTE(v15) = 52;
    memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
    memcpy(Dst: v8, Src: v11, Size: sizeof(v8));
    idEventReceiver::PostEventMS(
      this: this->ai,
      ev: &AE_AnimDeltaCorrection,
      time: v15,
      arg1: v17,
      arg2: v18,
      arg3: (const idEventArg *)__ROL4__(v12, 32),
      arg4: v14);
    this->pendingAnims.traversalDeltaCorrectionAnim = nullptr;
  }
}


// ========================================================================
// ?GetPathPositionAndDirection@idAnimFSM@@UBAHABUpathPositionAndDirectionParms_t@idAnimBaseFSM@@AAVidVec3@@1@Z
// EA  : 0x82A6AD08
// RVA : 0x00A6AD08
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM::GetPathPositionAndDirection(
        idAnimFSM *this,
        const idAnimBaseFSM::pathPositionAndDirectionParms_t *parms,
        idVec3 *outPosition,
        idVec3 *outDirection)
{
  double distance; // fp31
  idPhysics *Physics; // r3
  float *v10; // r3
  int num; // r11
  int startingCorner; // r30
  bool clampAtLink; // r28
  idVec3 *p_position; // r3
  idPhysics *v16; // r3
  int v17; // r9
  int v18; // r8
  double x; // fp11
  double y; // fp12
  double z; // fp13
  idNpCornerInfo *list; // r7
  int v23; // r10
  float v24; // r5
  float v25; // r4
  double v26; // fp3
  double v27; // fp1
  double v28; // fp11
  double v31; // fp13
  double v32; // fp6
  double v33; // fp2
  double v34; // fp13
  double v35; // fp6
  double v36; // fp5
  double v37; // fp7
  double v38; // fp30
  double v39; // fp29
  double v40; // fp31
  idVec3 v43; // [sp+50h] [-80h]
  float v44; // [sp+68h] [-68h]
  float v45; // [sp+70h] [-60h]
  float v46; // [sp+74h] [-5Ch]
  float v47; // [sp+78h] [-58h]

  distance = parms->distance;
  Physics = idEntity::GetPhysics(this: this->ai);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  num = this->cachedCorners.num;
  v45 = *v10;
  v43 = this->orientBody.axis.mat[0];
  v46 = v10[1];
  v47 = v10[2];
  if ( num == 0 )
    return -1;
  startingCorner = parms->startingCorner;
  clampAtLink = parms->clampAtLink;
  if ( startingCorner <= 0 || startingCorner >= num )
  {
    v16 = idEntity::GetPhysics(this: this->ai);
    p_position = (idVec3 *)v16->GetOrigin(this: v16, a2: 0);
  }
  else
  {
    p_position = &this->cachedCorners.list[startingCorner - 1].position;
  }
  v17 = startingCorner;
  v18 = this->cachedCorners.num;
  x = p_position->x;
  y = p_position->y;
  z = p_position->z;
  if ( startingCorner >= v18 )
  {
    v37 = v43.z;
    v35 = v43.y;
    v36 = v43.x;
LABEL_18:
    if ( clampAtLink || parms->clampAtEnd && distance > 0.0 )
    {
      v40 = x;
      v38 = y;
      v39 = z;
    }
    else
    {
      v38 = (float)((float)((float)v35 * (float)distance) + v46);
      v39 = (float)((float)((float)v37 * (float)distance) + v47);
      v40 = (float)((float)((float)v36 * (float)distance) + v45);
    }
    if ( !parms->adjustWithAvoidance )
      goto LABEL_26;
    ((void (__fastcall *)(idAnimFSM *, double))this->UpdateAvoidance)(a1: this, a2: parms->distance);
  }
  else
  {
    list = this->cachedCorners.list;
    v23 = startingCorner;
    while ( 1 )
    {
      v24 = list[v23].position.y;
      v25 = list[v23].position.x;
      v44 = list[v23].position.z;
      v26 = (float)(v44 - (float)z);
      v27 = (float)(v25 - (float)x);
      v28 = (float)((float)((float)(v25 - (float)x) * (float)(v25 - (float)x))
                  + (float)((float)((float)(v44 - (float)z) * (float)(v44 - (float)z))
                          + (float)((float)(v24 - (float)y) * (float)(v24 - (float)y))));
      _FP6 = (float)((float)v28 - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f2, f6, f11, f10 }
      v31 = __frsqrte(_FP2);
      v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                          * (float)((float)v28
                                                                                                  * (float)0.5))
                                                                                  * (float)v31)
                                                                          - (float)1.5)
                                                          * (float)v31)
                                                  * (float)((float)v28 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v31
                                                                                  * (float)((float)v28 * (float)0.5))
                                                                          * (float)v31)
                                                                  - (float)1.5)
                                                  * (float)v31))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31)
                                          - (float)1.5)
                          * (float)v31));
      v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                                  * (float)v31)
                                                                                          * (float)((float)v28
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                          * (float)v31))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v31
                                                                                                  * (float)((float)v28 * (float)0.5))
                                                                                          * (float)v31)
                                                                                  - (float)1.5)
                                                                  * (float)v31))
                                                  * (float)((float)v28 * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                          * (float)v31)
                                                                                  * (float)((float)v28 * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31)
                                                                                                  - (float)1.5)
                                                                                  * (float)v31))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v31
                                                                                          * (float)((float)v28
                                                                                                  * (float)0.5))
                                                                                  * (float)v31)
                                                                          - (float)1.5)
                                                          * (float)v31)))
                                  - (float)1.5)
                  * (float)v32);
      v34 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31)
                                                                                                  * (float)((float)v28 * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                                  * (float)v31))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5))
                                                                                                  * (float)v31)
                                                                                          - (float)1.5)
                                                                          * (float)v31))
                                                          * (float)((float)v28 * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                                  * (float)v31)
                                                                                          * (float)((float)v28
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)v28 * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                          * (float)v31))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v31
                                                                                                  * (float)((float)v28 * (float)0.5))
                                                                                          * (float)v31)
                                                                                  - (float)1.5)
                                                                  * (float)v31)))
                                          - (float)1.5)
                          * (float)v32)
                  * (float)v28);
      v35 = (float)((float)(v24 - (float)y) * (float)v33);
      v43.y = (float)(v24 - (float)y) * (float)v33;
      v36 = (float)((float)v27 * (float)v33);
      v43.x = (float)v27 * (float)v33;
      v37 = (float)((float)v26 * (float)v33);
      v43.z = (float)v26 * (float)v33;
      if ( distance <= v34 )
        break;
      distance = (float)((float)distance - (float)v34);
      x = v25;
      y = v24;
      z = v44;
      if ( list[v23].cornerType == CORNER_LINKSTART && parms->clampAtLink )
      {
        clampAtLink = true;
        goto LABEL_18;
      }
      ++v17;
      ++v23;
      if ( v17 >= v18 )
        goto LABEL_18;
    }
    v38 = (float)(v46 + (float)((float)((float)(v24 - (float)y) * (float)v33) * (float)distance));
    v39 = (float)(v47 + (float)((float)((float)v26 * (float)v33) * (float)distance));
    v40 = (float)((float)((float)((float)v27 * (float)v33) * (float)distance) + v45);
    if ( !parms->adjustWithAvoidance )
      goto LABEL_26;
    _FP12 = (float)(parms->distance - (float)400.0);
    __asm { fsel      f1, f12, f13, f0 }
    ((void (__fastcall *)(idAnimFSM *, double))this->UpdateAvoidance)(a1: this, a2: _FP1);
  }
  v37 = v43.z;
  v36 = v43.x;
  v35 = v43.y;
LABEL_26:
  outPosition->x = v40;
  outPosition->y = v38;
  outPosition->z = v39;
  outDirection->z = v37;
  outDirection->y = v35;
  outDirection->x = v36;
  return 0;
}


// ========================================================================
// ?CallbackFinishLinkTraversal@idAnimFSM_NP@@UAAXXZ
// EA  : 0x82A6B040
// RVA : 0x00A6B040
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::CallbackFinishLinkTraversal(idAnimFSM_NP *this)
{
  idNpLink::Release(this: &this->linkTraversing);
}


// ========================================================================
// ?CallbackCanUseLink@idAnimFSM_NP@@UAA_NPAVidInfoLinkSegment@@@Z
// EA  : 0x82A6B048
// RVA : 0x00A6B048
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimFSM_NP::CallbackCanUseLink(idAnimFSM_NP *this, idInfoLinkSegment *link)
{
  return idInfoLinkSegment::TryReserveLink(this: link, reservation: &this->linkTraversing, force: false);
}


// ========================================================================
// ?FSMEvent_NotifyDead@idAnimFSM@@IAA?AVeventVoid@@XZ
// EA  : 0x82A6B060
// RVA : 0x00A6B060
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM *__fastcall idAnimFSM::FSMEvent_NotifyDead(idAnimFSM *this, idAIFSMLite *result)
{
  idAIFSMLite::ChangeState(this: result, destStateId: 2);
  return this;
}


// ========================================================================
// ?GetFinalPoint@idAnimBaseFSM@@UBAABVidVec3@@XZ
// EA  : 0x82A6B098
// RVA : 0x00A6B098
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

const idVec3 *__fastcall idAnimBaseFSM::GetFinalPoint(idAnimBaseFSM *this)
{
  float y; // r10
  idPhysics *Physics; // r3

  y = this->desiredMoveAxis.mat[2].y;
  if ( SLODWORD(y) > 0 )
    return (const idVec3 *)(60 * LODWORD(y) + LODWORD(this->desiredMoveAxis.mat[2].x) - 56);
  if ( LODWORD(this->intermediateMove.arriveAxis.mat[2].z) != 0 )
    return (const idVec3 *)&this->intermediateMove.moveFlags;
  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  return Physics->GetOrigin(this: Physics, a2: 0);
}


// ========================================================================
// ?PointInMovementRange@idAnimBaseFSM@@UBA_NABVidVec3@@0MAAM@Z
// EA  : 0x82A6B120
// RVA : 0x00A6B120
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::PointInMovementRange(
        idAnimBaseFSM *this,
        const idVec3 *dest,
        const idVec3 *curPos,
        double range,
        float *dist,
        float *a6)
{
  idEntity *v7; // r3
  double v8; // fp30
  double v10; // fp29
  double v12; // fp28
  idPhysics *Physics; // r3
  const idVec3 *v14; // r31
  double v15; // fp30
  idPhysics *v16; // r3
  int v17; // r3
  double v19; // fp9
  idVec3 v20; // [sp+50h] [-50h] BYREF

  v7 = *((idEntity **)this - 5);
  v8 = (float)(dest->x - curPos->x);
  v10 = (float)(dest->y - curPos->y);
  v12 = (float)(dest->z - curPos->z);
  v20.x = dest->x - curPos->x;
  v20.y = v10;
  v20.z = v12;
  Physics = idEntity::GetPhysics(this: v7);
  v14 = Physics->GetGravityNormal(this: Physics);
  v15 = (float)((float)(v14->x * (float)v8) + (float)((float)(v14->z * (float)v12) + (float)(v14->y * (float)v10)));
  v16 = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v17 = (int)v16->GetBounds(this: v16, a2: -1);
  if ( __fabs(v15) > (float)(*(float *)(v17 + 20) - *(float *)(v17 + 8)) )
    return false;
  idVec3::ProjectOntoPlane(this: &v20, normal: v14, overBounce: 1.0);
  v19 = __fsqrts((float)((float)(v20.y * v20.y) + (float)((float)(v20.z * v20.z) + (float)(v20.x * v20.x))));
  *a6 = v19;
  return v19 <= range;
}


// ========================================================================
// ?ReachedPoint@idAnimBaseFSM@@UBA_NABVidVec3@@M@Z
// EA  : 0x82A6B248
// RVA : 0x00A6B248
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::ReachedPoint(idAnimBaseFSM *this, const idVec3 *point, double tolerance)
{
  idPhysics *Physics; // r3
  idAnimBaseFSM_vtbl *v7; // r31
  int v8; // r3

  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v7 = this->idAIFSMLite::idEventReceiver::idClass::__vftable;
  v8 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  return ((int (__fastcall *)(idAnimBaseFSM *, const idVec3 *, int, double))v7->InternalCallEvent)(
           a1: this,
           a2: point,
           a3: v8,
           a4: tolerance);
}


// ========================================================================
// ?WillReachPoint@idAnimBaseFSM@@UBA_NABVidVec3@@M_N@Z
// EA  : 0x82A6B2B0
// RVA : 0x00A6B2B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::WillReachPoint(
        idAnimBaseFSM *this,
        const idVec3 *point,
        double timeSeconds,
        bool isFinalPoint)
{
  idPhysics *Physics; // r3
  int v8; // r29
  idPhysics *v9; // r3
  double v10; // fp0
  double v11; // fp1
  double v12; // fp13
  float v14; // [sp+58h] [-38h] BYREF
  float v15; // [sp+5Ch] [-34h]
  float v16; // [sp+60h] [-30h]

  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v8 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v9->GetLinearVelocity(this: (idPhysics *)&v14, result: (idVec3 *)v9, a3: 0);
  v10 = __fsqrts((float)((float)(v14 * v14) + (float)((float)(v15 * v15) + (float)(v16 * v16))));
  if ( v10 >= 0.000099999997 )
  {
    v12 = (float)((float)(*(float *)&this->bestTransitionInfo.anim * this->lastTransitionCorner.z)
                + (float)((float)(*(float *)&this->overrideMoveFlags * this->lastTransitionCorner.y)
                        + (float)(*(float *)&this->enableIdlePump * this->lastTransitionCorner.x)));
    if ( v12 < 0.99989998 && v12 > -0.99989998 )
      return 0;
    v11 = (float)((float)((float)v10 * (float)timeSeconds) + (float)4.0);
  }
  else
  {
    v11 = 4.0;
  }
  return ((int (__fastcall *)(idAnimBaseFSM *, const idVec3 *, int, double))this->InternalCallEvent)(
           a1: this,
           a2: point,
           a3: v8,
           a4: v11);
}


// ========================================================================
// ?GetTraversalEndpoint@idAnimFSM_AAS@@UBA?AVidVec3@@XZ
// EA  : 0x82A6B3E0
// RVA : 0x00A6B3E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM_AAS *__fastcall idAnimFSM_AAS::GetTraversalEndpoint(idAnimFSM_AAS *this, idVec3 *result)
{
  int v4; // r3
  int v5; // r3
  idList<idEventReceiver *,5> *v6; // r6
  idList<idEventReceiver *,5> *v7; // r5
  float y; // r8
  float z; // r7

  if ( SLODWORD(result[1117].x) <= 0 )
  {
    y = vec3_origin.y;
    z = vec3_origin.z;
    this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_AAS_vtbl *)LODWORD(vec3_origin.x);
    *(float *)&this->listenerList = y;
    *(float *)&this->listeningToList = z;
  }
  else
  {
    v4 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)LODWORD(result[1].x) + 552))(a1: LODWORD(result[1].x));
    v5 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v4 + 184))(a1: v4, a2: LODWORD(result[1117].x));
    v6 = *(idList<idEventReceiver *,5> **)(v5 + 16);
    v7 = *(idList<idEventReceiver *,5> **)(v5 + 20);
    this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = *(idAnimFSM_AAS_vtbl **)(v5 + 12);
    this->listenerList = v6;
    this->listeningToList = v7;
  }
  return this;
}


// ========================================================================
// ?IsLineInNavGraph@idAnimFSM_NP@@UBA_NABVidVec3@@0PAV2@@Z
// EA  : 0x82A6B490
// RVA : 0x00A6B490
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimFSM_NP::IsLineInNavGraph(
        idAnimFSM_NP *this,
        const idVec3 *start,
        const idVec3 *end,
        idVec3 *outTraceEndpoint)
{
  return idNpUtils::IsLineInNavGraph(ai: *((const idAI2 **)this - 5), p0: start, p1: end);
}


// ========================================================================
// ?IsLineInNavGraph@idAnimFSM_AAS@@UBA_NABVidVec3@@0PAV2@@Z
// EA  : 0x82A6B498
// RVA : 0x00A6B498
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimFSM_AAS::IsLineInNavGraph(
        idAnimFSM_AAS *this,
        const idVec3 *start,
        const idVec3 *end,
        idVec3 *outTraceEndpoint)
{
  idActor *v4; // r27
  const idAAS2 *v8; // r3
  const idAASPosition *AASPosition; // r27
  int v10; // r6
  double v11; // fp13
  double v12; // fp12
  float v14; // [sp+60h] [-90h] BYREF
  float v15; // [sp+64h] [-8Ch]
  float v16; // [sp+68h] [-88h]
  float v17; // [sp+6Ch] [-84h]
  int v18; // [sp+70h] [-80h]
  int v19; // [sp+74h] [-7Ch]
  int v20; // [sp+78h] [-78h]
  float v21; // [sp+7Ch] [-74h]
  float v22; // [sp+80h] [-70h]
  float v23; // [sp+84h] [-6Ch]
  int v24; // [sp+88h] [-68h]
  int v25; // [sp+8Ch] [-64h]
  float v26; // [sp+90h] [-60h]
  float v27; // [sp+94h] [-5Ch]
  float v28; // [sp+98h] [-58h]
  int v29; // [sp+9Ch] [-54h]
  int v30; // [sp+A0h] [-50h]
  int v31; // [sp+A4h] [-4Ch]
  int v32; // [sp+A8h] [-48h]
  int v33; // [sp+ACh] [-44h]
  int v34; // [sp+B0h] [-40h]

  v4 = *((idActor **)this - 5);
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v14 = 0.0;
  v24 = 0;
  v15 = 0.0;
  v25 = 0;
  v16 = 0.0;
  v29 = 0;
  v17 = 0.0;
  v30 = 0;
  v21 = 0.0;
  v31 = 0;
  v22 = 0.0;
  v32 = 0;
  v23 = 0.0;
  v33 = 0;
  v26 = 0.0;
  v34 = 0;
  v27 = 0.0;
  v28 = 0.0;
  v8 = v4->GetAAS(this: v4);
  AASPosition = idActor::GetAASPosition(this: v4, aas: v8);
  v10 = AASPosition->aas->PointAreaNum(this: (idAAS2 *)AASPosition->aas, a2: nullptr, a3: start);
  ((void (__fastcall *)(const idAAS2 *, float *, const idVec3 *, int, const idVec3 *, int, _DWORD, _DWORD))AASPosition->aas->TraceFloor)(
    a1: AASPosition->aas,
    a2: &v14,
    a3: start,
    a4: v10,
    a5: end,
    a6: 40,
    a7: 0,
    a8: 0);
  if ( outTraceEndpoint != nullptr )
  {
    v11 = v16;
    v12 = v17;
    outTraceEndpoint->x = v15;
    outTraceEndpoint->y = v11;
    outTraceEndpoint->z = v12;
  }
  return v14 > 0.99000001;
}


// ========================================================================
// ?GetReachedEntityDist@idAnimBaseFSM@@UBAMPBVidEntity@@M@Z
// EA  : 0x82A6B5D8
// RVA : 0x00A6B5D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetReachedEntityDist(idAnimBaseFSM *this, idEntity *ent, double tolerance)
{
  idPhysics *Physics; // r3
  int v6; // r3
  char *v7; // r10
  _DWORD *v8; // r11
  int i; // ctr
  double Radius; // fp30
  idPhysics *v11; // r3
  int v12; // r3
  char *v13; // r10
  _DWORD *v14; // r11
  int j; // ctr
  double v16; // fp1
  char v18; // [sp+4Ch] [-64h] BYREF
  idBounds v19; // [sp+50h] [-60h] BYREF
  char v20; // [sp+6Ch] [-44h] BYREF
  idBounds v21; // [sp+70h] [-40h] BYREF

  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v6 = (int)Physics->GetBounds(this: Physics, a2: -1);
  v7 = &v18;
  v8 = (_DWORD *)(v6 - 4);
  for ( i = 6; i != 0; --i )
  {
    ++v8;
    v7 += 4;
    *(_DWORD *)v7 = *v8;
  }
  v19.b[0].z = 0.0;
  v19.b[1].z = 0.0;
  Radius = idBounds::GetRadius(this: &v19);
  v11 = idEntity::GetPhysics(this: ent);
  v12 = (int)v11->GetBounds(this: v11, a2: -1);
  v13 = &v20;
  v14 = (_DWORD *)(v12 - 4);
  for ( j = 6; j != 0; --j )
  {
    ++v14;
    v13 += 4;
    *(_DWORD *)v13 = *v14;
  }
  v21.b[0].z = 0.0;
  v21.b[1].z = 0.0;
  v16 = (float)((float)(idBounds::GetRadius(this: &v21) + (float)Radius) + (float)tolerance);
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?ReachedEntity@idAnimBaseFSM@@UBA_NPBVidEntity@@M@Z
// EA  : 0x82A6B6C0
// RVA : 0x00A6B6C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::ReachedEntity(idAnimBaseFSM *this, idEntity *ent, double tolerance)
{
  idPhysics *Physics; // r3
  float *v7; // r29
  idPhysics *v8; // r3
  float *v9; // r3
  double v10; // fp10
  double v11; // fp6
  double v12; // fp30
  double v14; // fp29
  double v16; // fp0
  double v17; // fp10
  double v18; // fp28

  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = idEntity::GetPhysics(this: ent);
  v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
  v10 = (float)(v7[2] - v9[2]);
  v11 = (float)(v7[1] - v9[1]);
  v12 = (float)((float)((float)v11 * (float)v11)
              + (float)((float)((float)(*v7 - *v9) * (float)(*v7 - *v9)) + (float)((float)v10 * (float)v10)));
  _FP3 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)(*v7 - *v9) * (float)(*v7 - *v9)) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v14 = (float)((float)((float)((float)v11 * (float)v11)
                      + (float)((float)((float)(*v7 - *v9) * (float)(*v7 - *v9)) + (float)((float)v10 * (float)v10)))
              * (float)0.5);
  __asm { fsel      f2, f3, f30, f0 }
  v16 = __frsqrte(_FP2);
  v17 = (float)((float)-(float)((float)((float)((float)v16
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)(*v7 - *v9) * (float)(*v7 - *v9))
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v18 = (float)((float)-(float)((float)((float)((float)v17 * (float)v14) * (float)v17) - (float)1.5) * (float)v17);
  return (float)((float)((float)-(float)((float)((float)((float)v18 * (float)v14) * (float)v18) - (float)1.5)
                       * (float)v18)
               * (float)v12) < ((double (__fastcall *)(idAnimBaseFSM *, idEntity *, double))this->GetNumStates)(
                                 a1: this,
                                 a2: ent,
                                 a3: tolerance);
}


// ========================================================================
// ?WillReachEntity@idAnimBaseFSM@@UBA_NPBVidEntity@@MM@Z
// EA  : 0x82A6B7E8
// RVA : 0x00A6B7E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::WillReachEntity(
        idAnimBaseFSM *this,
        idEntity *ent,
        double timeSeconds,
        double tolerance)
{
  idPhysics *Physics; // r3
  float *v9; // r29
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp29
  double v13; // fp28
  double v14; // fp27
  idPhysics *v15; // r3
  float v17; // [sp+50h] [-60h] BYREF
  float v18; // [sp+54h] [-5Ch]
  float v19; // [sp+58h] [-58h]

  Physics = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = idEntity::GetPhysics(this: ent);
  v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
  v12 = (float)(*v9 - *v11);
  v13 = (float)(v9[1] - v11[1]);
  v14 = (float)(v9[2] - v11[2]);
  v15 = idEntity::GetPhysics(this: *((idEntity **)this - 5));
  v15->GetLinearVelocity(this: (idPhysics *)&v17, result: (idVec3 *)v15, a3: 0);
  return (float)-(float)((float)((float)__fsqrts((float)((float)(v17 * v17)
                                                       + (float)((float)(v18 * v18) + (float)(v19 * v19))))
                               * (float)timeSeconds)
                       - (float)__fsqrts((float)((float)((float)v13 * (float)v13)
                                               + (float)((float)((float)v14 * (float)v14)
                                                       + (float)((float)v12 * (float)v12))))) < ((double (__fastcall *)(idAnimBaseFSM *, idEntity *, double))this->GetNumStates)(
                                                                                                  a1: this,
                                                                                                  a2: ent,
                                                                                                  a3: tolerance);
}


// ========================================================================
// ?IsPlayingTraversalAnim@idAnimBaseFSM@@UBA_NXZ
// EA  : 0x82A6B908
// RVA : 0x00A6B908
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::IsPlayingTraversalAnim(idAnimBaseFSM *this)
{
  idAnimStateMoveGround *v1; // r3
  int subState; // r11
  int result; // r3

  v1 = idAnimStateMoveGround::CastTo(c: *((idAnimStateMoveGround **)this - 3));
  if ( v1 == nullptr )
    return 0;
  subState = v1->subState;
  if ( subState == 7 || subState == 8 )
    return 1;
  result = 1;
  if ( subState != 9 )
    return 0;
  return result;
}


// ========================================================================
// ?SetMoveStatus@idAnimBaseFSM@@QAA?AW4aiMoveStatus_t@@W42@@Z
// EA  : 0x82A6B970
// RVA : 0x00A6B970
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

aiMoveStatus_t __fastcall idAnimBaseFSM::SetMoveStatus(idAnimBaseFSM *this, aiMoveStatus_t _status)
{
  int v4[4]; // [sp+50h] [-20h] BYREF

  this->status = _status;
  if ( _status >= AIMOVESTATUS_ERROR && _status < AIMOVESTATUS_MAX )
  {
    v4[0] = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->MoveFailed(
      this: &this->idAIMoveInterface,
      a2: this->currentMove.moveReason,
      a3: this->status,
      a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)v4);
  }
  return this->status;
}


// ========================================================================
// ?CanArrivalTransition@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A6B9F0
// RVA : 0x00A6B9F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::CanArrivalTransition(idAnimBaseFSM *this)
{
  return (this->currentMove.moveFlags & 0x1000) == 0
      && (this->overrideMoveFlags & 0x1000) == 0
      && ai_useStopTransitions.valueInteger != 0;
}


// ========================================================================
// ?CanStepTransition@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A6BA30
// RVA : 0x00A6BA30
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::CanStepTransition(idAnimBaseFSM *this)
{
  return (this->currentMove.moveFlags & 0x1000) == 0
      && (this->overrideMoveFlags & 0x1000) == 0
      && ai_useStepTransitions.valueInteger != 0;
}


// ========================================================================
// ?GetDestinationTraversal@idAnimFSM_AAS@@UBAPBUaas2Traversal_t@@XZ
// EA  : 0x82A6BA70
// RVA : 0x00A6BA70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

const aas2Traversal_t *__fastcall idAnimFSM_AAS::GetDestinationTraversal(idAnimFSM_AAS *this)
{
  int v3; // r3

  if ( this->lastPath.moveAreaNum <= 0 )
    return nullptr;
  v3 = (*(int (__fastcall **)(_DWORD))(**((_DWORD **)this - 5) + 552))(a1: *((_DWORD *)this - 5));
  return (*(const aas2Traversal_t *(__fastcall **)(int, int))(*(_DWORD *)v3 + 184))(
           a1: v3,
           a2: this->lastPath.moveAreaNum);
}


// ========================================================================
// ?GetDistanceToPath@idAnimBaseFSM@@QBAMABVidVec3@@0AAV2@1@Z
// EA  : 0x82A6BAE8
// RVA : 0x00A6BAE8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetDistanceToPath(
        idAnimBaseFSM *this,
        const idVec3 *startOrigin,
        const idVec3 *testPoint,
        idVec3 *outPositionOnPath,
        idVec3 *outDirectionOnPath)
{
  double v9; // fp5
  double v10; // fp4
  double v11; // fp1
  float y; // r9
  float z; // r8
  idNpCornerInfo *list; // r11
  double v15; // fp13
  float v16; // r10
  float v17; // r9
  double v18; // fp30
  double v19; // fp28
  double v20; // fp29
  int v21; // r28
  double v22; // fp31
  double v23; // fp9
  int v24; // r29
  double v25; // fp8
  double x; // fp7
  idNpCornerInfo *v27; // r11
  float *v28; // r11
  double v29; // fp9
  double v30; // fp8
  double v33; // fp2
  double v34; // fp7
  idVec3 v36; // [sp+50h] [-A0h] BYREF
  idVec3 v37; // [sp+60h] [-90h] BYREF
  idVec3 v38; // [sp+70h] [-80h] BYREF
  idVec3 v39; // [sp+80h] [-70h] BYREF

  if ( this->cachedCorners.num != 0 )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    list = this->cachedCorners.list;
    v37.x = startOrigin->x;
    v37.y = y;
    v15 = y;
    v37.z = z;
    v16 = list->position.y;
    v17 = list->position.z;
    v36.x = list->position.x;
    v36.y = v16;
    v36.z = v17;
    v18 = (float)(v36.x - v37.x);
    v19 = (float)(v17 - z);
    v20 = (float)(v16 - (float)v15);
    idGeometry::ClosestPointOnLineSegment(point: testPoint, start: &v37, end: &v36, closest: &v38);
    v21 = 1;
    v22 = (float)((float)((float)(testPoint->x - v38.x) * (float)(testPoint->x - v38.x))
                + (float)((float)((float)(testPoint->z - v38.z) * (float)(testPoint->z - v38.z))
                        + (float)((float)(testPoint->y - v38.y) * (float)(testPoint->y - v38.y))));
    if ( this->cachedCorners.num > 1 )
    {
      v23 = v36.z;
      v24 = 1;
      v25 = v36.y;
      x = v36.x;
      do
      {
        v37.x = x;
        v27 = this->cachedCorners.list;
        v37.z = v23;
        v28 = (float *)&v27[v24];
        v37.y = v25;
        v36.x = v28[1];
        v36.y = v28[2];
        v36.z = v28[3];
        idGeometry::ClosestPointOnLineSegment(point: testPoint, start: &v37, end: &v36, closest: &v39);
        v23 = v36.z;
        v25 = v36.y;
        x = v36.x;
        if ( (float)((float)((float)(testPoint->y - v39.y) * (float)(testPoint->y - v39.y))
                   + (float)((float)(testPoint->x - v39.x) * (float)(testPoint->x - v39.x))) < v22 )
        {
          v22 = (float)((float)((float)(testPoint->y - v39.y) * (float)(testPoint->y - v39.y))
                      + (float)((float)(testPoint->x - v39.x) * (float)(testPoint->x - v39.x)));
          v38.x = v39.x;
          v38.z = v39.z;
          v38.y = v39.y;
          v20 = (float)(v36.y - v37.y);
          v18 = (float)(v36.x - v37.x);
          v19 = (float)(v36.z - v37.z);
        }
        ++v21;
        ++v24;
      }
      while ( v21 < this->cachedCorners.num );
    }
    v29 = v38.y;
    v30 = v38.z;
    outPositionOnPath->x = v38.x;
    outPositionOnPath->y = v29;
    v11 = __fsqrts(v22);
    outPositionOnPath->z = v30;
    _FP5 = (float)((float)((float)((float)v18 * (float)v18)
                         + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v33 = __frsqrte(_FP3);
    v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20)))
                                                                                                * (float)0.5))
                                                                                * (float)v33)
                                                                        - (float)1.5)
                                                        * (float)v33)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)v20 * (float)v20)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v33
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20)))
                                                                                        * (float)0.5))
                                                                        * (float)v33)
                                                                - (float)1.5)
                                                * (float)v33))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v33
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)v19 * (float)v19)
                                                                                + (float)((float)v20 * (float)v20)))
                                                                * (float)0.5))
                                                * (float)v33)
                                        - (float)1.5)
                        * (float)v33));
    outDirectionOnPath->x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33)
                                                                                                  - (float)1.5)
                                                                                  * (float)v33))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v19
                                                                                                  * (float)v19)
                                                                                          + (float)((float)v20
                                                                                                  * (float)v20)))
                                                                          * (float)0.5))
                                                          * (float)v34)
                                                  - (float)1.5)
                                  * (float)v34)
                          * (float)v18;
    outDirectionOnPath->y = (float)v20
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33)
                                                                                                  - (float)1.5)
                                                                                  * (float)v33))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v19
                                                                                                  * (float)v19)
                                                                                          + (float)((float)v20
                                                                                                  * (float)v20)))
                                                                          * (float)0.5))
                                                          * (float)v34)
                                                  - (float)1.5)
                                  * (float)v34);
    outDirectionOnPath->z = (float)v19
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5))
                                                                                                  * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v33)
                                                                                                  - (float)1.5)
                                                                                  * (float)v33))
                                                                  * (float)((float)((float)((float)v18 * (float)v18)
                                                                                  + (float)((float)((float)v19
                                                                                                  * (float)v19)
                                                                                          + (float)((float)v20
                                                                                                  * (float)v20)))
                                                                          * (float)0.5))
                                                          * (float)v34)
                                                  - (float)1.5)
                                  * (float)v34);
  }
  else
  {
    *outPositionOnPath = *startOrigin;
    outDirectionOnPath->x = 0.0;
    outDirectionOnPath->y = 0.0;
    outDirectionOnPath->z = 1.0;
    v9 = (float)(testPoint->y - startOrigin->y);
    v10 = (float)(testPoint->z - startOrigin->z);
    v11 = __fsqrts((float)((float)((float)(testPoint->x - startOrigin->x) * (float)(testPoint->x - startOrigin->x))
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?DebugDrawCurrentCorners@idAnimBaseFSM@@QBAXABVidVec3@@VidColor@@H@Z
// EA  : 0x82A6BDB0
// RVA : 0x00A6BDB0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimBaseFSM::DebugDrawCurrentCorners(
        idAnimBaseFSM *this,
        const idVec3 *startOrigin,
        __int64 lifetime,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  int num; // r11
  float y; // r9
  float z; // r8
  idNpCornerInfo *list; // r11
  idRenderWorld *v18; // r3
  int v19; // r31
  int v20; // r30
  idNpCornerInfo *v21; // r11
  float *v22; // r11
  idRenderWorld *v23; // r3
  float v24; // [sp+50h] [-50h] BYREF
  float v25; // [sp+54h] [-4Ch]
  float v26; // [sp+58h] [-48h]
  float x; // [sp+60h] [-40h] BYREF
  float v28; // [sp+64h] [-3Ch]
  float v29; // [sp+68h] [-38h]

  num = this->cachedCorners.num;
  a11 = *(__int64 *)((char *)&lifetime + 4);
  a12 = lifetime;
  if ( num != 0 )
  {
    y = startOrigin->y;
    z = startOrigin->z;
    list = this->cachedCorners.list;
    x = startOrigin->x;
    v28 = y;
    v29 = z;
    LODWORD(lifetime) = LODWORD(list->position.y);
    *(float *)&lifetime = list->position.z;
    v24 = list->position.x;
    v26 = *(float *)&lifetime;
    v25 = *((float *)&lifetime + 1);
    v18 = gameLocal->GetRenderWorld(this: gameLocal);
    v18->DebugLine(
      this: v18,
      a2: (const idVec4 *)&a11,
      a3: (const idVec3 *)&x,
      a4: (const idVec3 *)&v24,
      a5: a4,
      a6: false);
    v19 = 1;
    if ( this->cachedCorners.num > 1 )
    {
      v20 = 1;
      do
      {
        v21 = this->cachedCorners.list;
        x = v24;
        v22 = (float *)&v21[v20];
        v28 = v25;
        v29 = v26;
        v24 = v22[1];
        v25 = v22[2];
        v26 = v22[3];
        v23 = gameLocal->GetRenderWorld(this: gameLocal);
        v23->DebugLine(
          this: v23,
          a2: (const idVec4 *)&a11,
          a3: (const idVec3 *)&x,
          a4: (const idVec3 *)&v24,
          a5: a4,
          a6: false);
        ++v19;
        ++v20;
      }
      while ( v19 < this->cachedCorners.num );
    }
  }
}


// ========================================================================
// ?GetRemainingPathDistance@idAnimBaseFSM@@QBAMXZ
// EA  : 0x82A6BEF0
// RVA : 0x00A6BEF0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetRemainingPathDistance(idAnimBaseFSM *this)
{
  double v2; // fp1
  idPhysics *Physics; // r3
  float *v4; // r3
  idNpCornerInfo *list; // r9
  int num; // r11
  double v7; // fp12
  double v8; // fp11
  double v9; // fp13
  double v12; // fp4
  double v13; // fp7
  double v14; // fp4
  int v15; // r10
  int v16; // ctr
  double v17; // fp5
  double v18; // fp4
  double v19; // fp3
  double v20; // fp7
  double v22; // fp5
  double v24; // fp3
  double v25; // fp4
  double v26; // fp3
  float x; // [sp+50h] [-30h]
  float y; // [sp+54h] [-2Ch]
  float z; // [sp+58h] [-28h]
  float v31; // [sp+60h] [-20h]
  float v32; // [sp+64h] [-1Ch]
  float v33; // [sp+68h] [-18h]

  if ( this->cachedCorners.num != 0 )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    list = this->cachedCorners.list;
    num = this->cachedCorners.num;
    v33 = v4[2];
    v31 = *v4;
    z = list->position.z;
    v7 = z;
    x = list->position.x;
    v8 = x;
    y = list->position.y;
    v9 = y;
    v32 = v4[1];
    _FP7 = (float)((float)((float)((float)(x - v31) * (float)(x - v31))
                         + (float)((float)((float)(z - v33) * (float)(z - v33))
                                 + (float)((float)(y - v32) * (float)(y - v32))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f10 }
    v12 = __frsqrte(_FP5);
    v13 = (float)((float)-(float)((float)((float)((float)v12
                                                * (float)((float)((float)((float)(x - v31) * (float)(x - v31))
                                                                + (float)((float)((float)(z - v33) * (float)(z - v33))
                                                                        + (float)((float)(y - v32) * (float)(y - v32))))
                                                        * (float)0.5))
                                        * (float)v12)
                                - (float)1.5)
                * (float)v12);
    v14 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                * (float)((float)((float)((float)(x - v31) * (float)(x - v31))
                                                                                                + (float)((float)((float)(z - v33) * (float)(z - v33)) + (float)((float)(y - v32) * (float)(y - v32))))
                                                                                        * (float)0.5))
                                                                        * (float)v12)
                                                                - (float)1.5)
                                                * (float)v12)
                                        * (float)((float)((float)((float)(x - v31) * (float)(x - v31))
                                                        + (float)((float)((float)(z - v33) * (float)(z - v33))
                                                                + (float)((float)(y - v32) * (float)(y - v32))))
                                                * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v12
                                                                        * (float)((float)((float)((float)(x - v31)
                                                                                                * (float)(x - v31))
                                                                                        + (float)((float)((float)(z - v33) * (float)(z - v33))
                                                                                                + (float)((float)(y - v32) * (float)(y - v32))))
                                                                                * (float)0.5))
                                                                * (float)v12)
                                                        - (float)1.5)
                                        * (float)v12))
                        - (float)1.5);
    v2 = (float)((float)((float)-(float)((float)((float)((float)((float)v14 * (float)v13)
                                                       * (float)((float)((float)((float)(x - v31) * (float)(x - v31))
                                                                       + (float)((float)((float)(z - v33)
                                                                                       * (float)(z - v33))
                                                                               + (float)((float)(y - v32)
                                                                                       * (float)(y - v32))))
                                                               * (float)0.5))
                                               * (float)((float)v14 * (float)v13))
                                       - (float)1.5)
                       * (float)((float)v14 * (float)v13))
               * (float)((float)((float)(x - v31) * (float)(x - v31))
                       + (float)((float)((float)(z - v33) * (float)(z - v33))
                               + (float)((float)(y - v32) * (float)(y - v32)))));
    if ( num > 1 )
    {
      v15 = 1;
      v16 = num - 1;
      do
      {
        v17 = (float)(list[v15].position.y - (float)v9);
        v9 = list[v15].position.y;
        v18 = (float)(list[v15].position.z - (float)v7);
        v7 = list[v15].position.z;
        v19 = (float)(list[v15].position.x - (float)v8);
        v8 = list[v15++].position.x;
        v20 = (float)((float)((float)v19 * (float)v19)
                    + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
        _FP6 = (float)((float)((float)((float)v19 * (float)v19)
                             + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v22 = (float)((float)((float)((float)v19 * (float)v19)
                            + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                    * (float)0.5);
        __asm { fsel      f4, f6, f7, f10 }
        v24 = __frsqrte(_FP4);
        v25 = (float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5) * (float)v24);
        v26 = (float)((float)((float)-(float)((float)((float)((float)v24 * (float)v22) * (float)v24) - (float)1.5)
                            * (float)v24)
                    * (float)v22);
        v2 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v26 * (float)v25)
                                                                                           - (float)1.5)
                                                                           * (float)v25)
                                                                   * (float)v22)
                                                           * (float)((float)-(float)((float)((float)v26 * (float)v25)
                                                                                   - (float)1.5)
                                                                   * (float)v25))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)v26 * (float)v25) - (float)1.5) * (float)v25))
                           * (float)v20)
                   + (float)v2);
        --v16;
      }
      while ( v16 != 0 );
    }
  }
  else
  {
    v2 = 0.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?AlignToNextPoint@idAnimFSM_AAS@@UAA_NXZ
// EA  : 0x82A6C0A8
// RVA : 0x00A6C0A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::AlignToNextPoint(idAnimFSM_AAS *this)
{
  idPhysics *Physics; // r27
  double v5; // fp1
  double v6; // fp1
  double v7; // fp7
  double v8; // fp31
  double v9; // fp5
  char *v11; // r10
  float *p_z; // r11
  int v13; // ctr
  float *v14; // r3
  double valueFloat; // fp0
  double v16; // fp1
  double v17; // fp31
  __int128 v18; // r5
  idAIOrientation *p_orientBody; // r3
  double v20; // fp31
  __int64 v21; // r7
  double v22; // fp30
  const idVec3 *v23; // r3
  float x; // [sp+50h] [-A0h]
  float y; // [sp+54h] [-9Ch]
  float z; // [sp+58h] [-98h]
  float v27; // [sp+60h] [-90h] BYREF
  float v28; // [sp+64h] [-8Ch]
  float v29; // [sp+68h] [-88h]
  idVec3 v30; // [sp+70h] [-80h] BYREF
  char v31; // [sp+7Ch] [-74h] BYREF
  idMat3 v32; // [sp+80h] [-70h] BYREF

  Physics = idEntity::GetPhysics(this: this->ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v27, result: (idVec3 *)Physics, a3: 0);
  _FP4 = (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f12 }
  v5 = __frsqrte(_FP2);
  v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5)
                                             * (float)((float)((float)(v27 * v27)
                                                             + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                             * (float)((float)((float)(v27 * v27)
                                                                                             + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                                                     * (float)0.5))
                                                                     * (float)v5)
                                                             - (float)1.5)
                                             * (float)v5))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v5
                                                     * (float)((float)((float)(v27 * v27)
                                                                     + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                             * (float)0.5))
                                             * (float)v5)
                                     - (float)1.5)
                     * (float)v5));
  v7 = (float)((float)-(float)((float)((float)((float)v6
                                             * (float)((float)((float)(v27 * v27)
                                                             + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                     * (float)0.5))
                                     * (float)v6)
                             - (float)1.5)
             * (float)v6);
  v8 = (float)((float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(v27 * v27)
                                                                     + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6)
             * (float)((float)(v27 * v27) + (float)((float)(v29 * v29) + (float)(v28 * v28))));
  v9 = (float)(v28
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(v27 * v27)
                                                                     + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v27 = v27
      * (float)((float)-(float)((float)((float)((float)v6
                                              * (float)((float)((float)(v27 * v27)
                                                              + (float)((float)(v29 * v29) + (float)(v28 * v28)))
                                                      * (float)0.5))
                                      * (float)v6)
                              - (float)1.5)
              * (float)v6);
  v28 = v9;
  v29 = v29 * (float)v7;
  if ( v8 < 0.000099999997 )
    return 0;
  v11 = &v31;
  p_z = &this->nextArrivalPos.z;
  x = this->nextArrivalPos.x;
  v13 = 9;
  y = this->nextArrivalPos.y;
  z = this->nextArrivalPos.z;
  do
  {
    ++p_z;
    v11 += 4;
    *(float *)v11 = *p_z;
    --v13;
  }
  while ( v13 != 0 );
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  valueFloat = ai_alignToPointDist.valueFloat;
  v16 = __fsqrts((float)((float)((float)(x - *v14) * (float)(x - *v14))
                       + (float)((float)((float)(z - v14[2]) * (float)(z - v14[2]))
                               + (float)((float)(y - v14[1]) * (float)(y - v14[1])))));
  if ( ai_alignToPointDist.valueFloat <= 0.0 )
    valueFloat = this->ai->aiEditable.behaviors.decl->movementBehaviors.alignToPointDistance;
  if ( (float)((float)v16 - this->currentMove.arrivalRadius) > valueFloat )
    return 0;
  v17 = (float)((float)((float)((float)v16 - this->currentMove.arrivalRadius) / (float)v8) * (float)0.89999998);
  v30 = v32.mat[0];
  *(_QWORD *)((char *)&v18 + 4) = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameMsPerFrame)(
                                    a1: gameLocal,
                                    a2: 1);
  LODWORD(v18) = DWORD1(v18);
  p_orientBody = &this->orientBody;
  if ( v17 > (float)((float)(__int64)v18 * (float)0.001) )
  {
    v20 = idAIOrientation::CalcTurnRateForTime(
            this: p_orientBody,
            rotationAxis: &this->orientBody.axis.mat[2],
            destDir: &v30,
            timeSeconds: v17);
    idAIOrientation::SetIdealDir(this: &this->orientBody, ai: this->ai, dir: &v30);
    LODWORD(v21) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v22 = (float)((float)v21 * (float)0.001);
    v23 = Physics->GetGravityNormal(this: Physics);
    idAIOrientation::UpdateAxis(this: &this->orientBody, normal: v23, turnRate: v20, timeSeconds: v22);
  }
  else
  {
    idAIOrientation::SetIdealDir(this: p_orientBody, ai: this->ai, dir: &v30);
    idAIOrientation::SetAxis(this: &this->orientBody, axis: &v32);
  }
  return 1;
}


// ========================================================================
// ?AddNavTrace@idAnimBaseFSM@@QAAHABVidVec3@@0@Z
// EA  : 0x82A6C380
// RVA : 0x00A6C380
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::AddNavTrace(idAnimBaseFSM *this, const idVec3 *start, const idVec3 *stop)
{
  idAnimBaseFSM::navTrace_t *v4; // r11
  int result; // r3
  int numNewNavTraces; // r9

  v4 = &this->navTraces.ptr[this->numNavTraces];
  if ( v4->used )
  {
    idLib::Warning(
      fmt: "Exhausted nav trace pool, either too many traces queued or someone isn't cleaning up their traces",
      start,
      stop);
    return -1;
  }
  else
  {
    v4->fraction = -1.0;
    v4->start = *start;
    v4->stop = *stop;
    v4->dirty = true;
    v4->used = true;
    numNewNavTraces = this->numNewNavTraces;
    result = this->numNavTraces;
    this->numNewNavTraces = numNewNavTraces + 1;
    this->numNavTraces = (result + 1) % 256;
  }
  return result;
}


// ========================================================================
// ?GetNavTraceResult@idAnimBaseFSM@@QAAMH@Z
// EA  : 0x82A6C450
// RVA : 0x00A6C450
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetNavTraceResult(idAnimBaseFSM *this, int queryNum)
{
  double fraction; // fp1

  fraction = this->navTraces.ptr[queryNum].fraction;
  return *((float *)&fraction + 1);
}


// ========================================================================
// ?ReleaseAllNavTraces@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A6C460
// RVA : 0x00A6C460
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::ReleaseAllNavTraces(idAnimBaseFSM *this)
{
  char *v1; // r11
  int i; // ctr

  v1 = (char *)&this->moveFailures.staticList[1].failureTime.value + 1;
  for ( i = 256; i != 0; --i )
  {
    v1[31] = 0;
    v1 += 32;
    *v1 = 0;
  }
}


// ========================================================================
// ?InitNavTraceSystem@idAnimBaseFSM@@MAAXXZ
// EA  : 0x82A6C480
// RVA : 0x00A6C480
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::InitNavTraceSystem(idAnimBaseFSM *this)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> *p_failureTime; // r11
  int i; // ctr

  p_failureTime = &this->moveFailures.staticList[1].failureTime;
  for ( i = 256; i != 0; --i )
  {
    p_failureTime += 8;
    HIBYTE(p_failureTime->value) = 0;
  }
  this->numNewNavTraces = 0;
  this->numNavTraces = 0;
}


// ========================================================================
// ?InitNavTraceSystem@idAnimFSM_AAS@@UAAXXZ
// EA  : 0x82A6C4A8
// RVA : 0x00A6C4A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::InitNavTraceSystem(idAnimFSM_AAS *this)
{
  idTypesafeNumber<int,enum gameTimeUnique_t> *p_failureTime; // r11
  int i; // ctr
  int *p_numTraces; // r10
  float *p_z; // r11
  int j; // ctr

  p_failureTime = &this->moveFailures.staticList[1].failureTime;
  for ( i = 256; i != 0; --i )
  {
    p_failureTime += 8;
    HIBYTE(p_failureTime->value) = 0;
  }
  this->numNewNavTraces = 0;
  this->numNavTraces = 0;
  p_numTraces = &this->obstacleTraces.numTraces;
  p_z = &this->lastPath.obstacleRoute.areas[10].end.z;
  for ( j = 256; j != 0; --j )
  {
    *(p_numTraces - 256) = -1;
    *(idVec2 *)(p_z + 1) = vec2_origin;
    p_z[3] = vec2_origin.x;
    p_z += 4;
    *p_z = vec2_origin.y;
    *((float *)p_numTraces++ - 512) = -1.0;
    *p_numTraces = -1;
  }
  this->obstacleTraces.numTraces = 0;
  this->obstacleTraces.prevNumTraces = 0;
}


// ========================================================================
// ?PrintDebugInfo@idAnimBaseFSM@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A6CCD8
// RVA : 0x00A6CCD8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::PrintDebugInfo(idAnimBaseFSM *this, idGuiListBox *info)
{
  idAIMoveCmd *p_currentMove; // r23
  int *p_flagsDebug; // r25
  idGuiListBox *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idGuiListBox *v10; // r3
  const char *v11; // r28
  const char *EnumValueName; // r26
  double previousRemainingTranslationFrames; // fp31
  idGuiListBox *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // fp31
  idGuiListBox *v22; // r3
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  idGuiListBox *v26; // r3
  __int64 v27; // r10
  __int64 v28; // r8
  idAIStateLite *currentState; // r28
  __int64 v30; // r4
  __int64 v31; // fp31
  const char *v32; // r28
  idGuiListBox *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  __int64 v36; // r6
  idGuiListBox *v37; // r3
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  idGuiListBox *v41; // r3
  __int64 v42; // r8
  __int64 v43; // r10
  __int64 v44; // r6
  idGuiListBox *v45; // r3
  idPhysics *Physics; // r3
  int v47; // r10
  idBounds *v48; // r3
  double InternalRadiusXY; // fp31
  int (*GetRenderWorld)(void); // ctr
  int v51; // r3
  int v52; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r26
  int v54; // r29
  idIndex<short,enum invalidUserChannelIndex_t> *userChannels; // r31
  double BlendedUserChannel; // fp31
  const char *v57; // r25
  idGuiListBox *v58; // r3
  __int64 v59; // r10
  __int64 v60; // r8
  __int64 v61; // r6
  idGuiListBox *v62; // r3
  __int64 v63; // r6
  __int64 v64; // r10
  __int64 v65; // r8
  __int64 v66; // [sp+8h] [-128h]
  __int64 v67; // [sp+10h] [-120h]
  __int64 v68; // [sp+18h] [-118h]
  __int64 v69; // [sp+28h] [-108h]
  float v70[4]; // [sp+58h] [-D8h] BYREF
  float v71[6]; // [sp+68h] [-C8h] BYREF
  idAIMoveInfo v72; // [sp+80h] [-B0h] BYREF

  p_currentMove = &this->currentMove;
  p_flagsDebug = &this->flagsDebug;
  idAIMoveCmd::PrintDebugInfo(this: &this->currentMove, info);
  v6 = idGuiListBox::Row(this: info);
  v10 = idGuiListBox::Printf(this: v6, fmt: "Show Path Corners", a3: v9, a4: v8, a5: v7);
  idGuiListBox::CheckBox(this: v10, bitfield: &this->flagsDebug, bit: 0);
  v11 = "-";
  if ( (*((_BYTE *)&this->animDeltaCorrection + 372) & 0x20) != 0
    && (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x40) != 0 )
  {
    EnumValueName = idTypeInfoTools::FindEnumValueName(
                      this: typeInfoTools,
                      enumTypeName: "aiAnimDCIdealPoint_t",
                      value: this->animDeltaCorrection.idealPoint);
  }
  else
  {
    EnumValueName = "-";
  }
  previousRemainingTranslationFrames = this->animDeltaCorrection.previousRemainingTranslationFrames;
  v14 = idGuiListBox::Row(this: info);
  v18 = idGuiListBox::Printf(this: v14, fmt: "Delta Trans: ", a3: v17, a4: v16, a5: v15);
  idGuiListBox::Printf(
    this: v18,
    fmt: "%s (%.1f)",
    a3: __SPAIR64__((unsigned int)EnumValueName, LODWORD(previousRemainingTranslationFrames)),
    a4: v20,
    a5: v19,
    previousRemainingTranslationFrames);
  if ( (*((_BYTE *)&this->animDeltaCorrection + 372) & 0x20) != 0
    && (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x80) != 0 )
  {
    v11 = idTypeInfoTools::FindEnumValueName(
            this: typeInfoTools,
            enumTypeName: "aiAnimDCIdealDir_t",
            value: this->animDeltaCorrection.idealDir);
  }
  *(double *)&v21 = this->animDeltaCorrection.previousRemainingRotationFrames;
  v22 = idGuiListBox::Row(this: info);
  v26 = idGuiListBox::Printf(this: v22, fmt: "Delta Rot: ", a3: v25, a4: v24, a5: v23);
  v69 = v21;
  idGuiListBox::Printf(
    this: v26,
    fmt: "%s (%.1f)",
    a3: __SPAIR64__((unsigned int)v11, v21),
    a4: v28,
    a5: v27,
    *(double *)&v21);
  currentState = this->currentState;
  LODWORD(v30) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->stateStartTime;
  HIDWORD(v30) = currentState;
  *(double *)&v31 = (float)((float)v30 * (float)0.001);
  v32 = *(const char **)currentState->GetType(this: currentState);
  v33 = idGuiListBox::Row(this: info);
  v37 = idGuiListBox::Printf(this: v33, fmt: v32, a3: v36, a4: v35, a5: v34);
  HIDWORD(v38) = v31;
  idGuiListBox::Printf(this: v37, fmt: "%.2f", a3: v38, a4: v40, a5: v39, *(double *)&v31);
  this->currentState->PrintDebugInfo(this: this->currentState, a2: info);
  v41 = idGuiListBox::Row(this: info);
  HIDWORD(v42) = "1 - formation cover, such as behind regime shield units";
  v45 = idGuiListBox::Printf(this: v41, fmt: "Blend Var: bodyLookYaw", a3: v44, a4: v42, a5: v43);
  idGuiListBox::Value(this: v45, value: &this->animBlendVars.bodyLookYaw.value, stepSize: 1.0);
  if ( (*p_flagsDebug & 1) != 0 )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    Physics->GetOrigin(this: Physics, a2: 0);
    idAnimBaseFSM::DebugDrawCurrentCorners(
      this,
      startOrigin: (const idVec3 *)LODWORD(idColor::colorGreen.r),
      lifetime: *(__int64 *)&idColor::colorGreen.b,
      a4: 1,
      a5: (int)&idColor::colorGreen,
      a6: (int)&aAvSsobjectVCom[20],
      a7: v47,
      a8: v66,
      a9: v67,
      a10: v68,
      a11: v31,
      a12: v69);
  }
  if ( this->HasDestination(this) )
  {
    idAIMoveInfo::idAIMoveInfo(this: &v72);
    if ( this->GetMoveInfo(this, a2: p_currentMove, a3: &v72) == 0 )
    {
      v48 = (idBounds *)this->ai->aiVolatile.physics.object.GetBounds(this: &this->ai->aiVolatile, a2: -1);
      InternalRadiusXY = idBounds::GetInternalRadiusXY(this: v48);
      GetRenderWorld = (int (*)(void))gameLocal->GetRenderWorld;
      if ( v72.useDestOrientation )
      {
        v51 = GetRenderWorld();
        v70[0] = v72.destPosition.x + (float)(v72.destOrientation.mat[0].x * (float)InternalRadiusXY);
        v71[0] = v72.destPosition.x - (float)(v72.destOrientation.mat[0].x * (float)InternalRadiusXY);
        v70[1] = v72.destPosition.y + (float)(v72.destOrientation.mat[0].y * (float)InternalRadiusXY);
        v70[2] = v72.destPosition.z + (float)(v72.destOrientation.mat[0].z * (float)InternalRadiusXY);
        v71[1] = v72.destPosition.y - (float)(v72.destOrientation.mat[0].y * (float)InternalRadiusXY);
        v71[2] = v72.destPosition.z - (float)(v72.destOrientation.mat[0].z * (float)InternalRadiusXY);
        (*(void (__fastcall **)(int, idColor *, float *, float *, double))(*(_DWORD *)v51 + 180))(
          a1: v51,
          a2: &idColor::colorBlue,
          a3: v71,
          a4: v70,
          a5: InternalRadiusXY);
      }
      else
      {
        v52 = GetRenderWorld();
        (*(void (__fastcall **)(int, idColor *, idVec3 *, idVec3 *, double))(*(_DWORD *)v52 + 200))(
          a1: v52,
          a2: &idColor::colorBlue,
          a3: &v72.destPosition,
          a4: &v72.destNormal,
          a5: InternalRadiusXY);
      }
    }
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  v54 = 0;
  userChannels = this->userChannels;
  do
  {
    if ( (unsigned __int16)userChannels->value < 0x8000u )
    {
      BlendedUserChannel = idTreeAnimator::GetBlendedUserChannel(
                             this: TreeAnimatorFromPresentable,
                             index: (idIndex<short,enum invalidUserChannelIndex_t> *)(unsigned __int16)userChannels->value);
      v57 = idTypeInfoTools::FindEnumValueName(
              this: typeInfoTools,
              enumTypeName: "idAnimBaseFSM::userChannelId_t",
              value: v54);
      v58 = idGuiListBox::Row(this: info);
      v62 = idGuiListBox::Printf(this: v58, fmt: v57, a3: v61, a4: v60, a5: v59);
      HIDWORD(v63) = LODWORD(BlendedUserChannel);
      idGuiListBox::Printf(this: v62, fmt: "%.2f", a3: v63, a4: v65, a5: v64, BlendedUserChannel);
    }
    ++v54;
    ++userChannels;
  }
  while ( v54 < 5 );
}


// ========================================================================
// ?InternalInit@idAnimBaseFSM@@MAAXXZ
// EA  : 0x82A6D100
// RVA : 0x00A6D100
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::InternalInit(idAnimBaseFSM *this)
{
  const idDeclMD6 *decl; // r31
  int v3; // r6
  bool v4; // cr56
  int v5; // r6
  bool v6; // cr56
  int trackedMemory_high; // r6
  bool v8; // cr56
  int trackedMemory_low; // r6
  bool v10; // cr56
  int str_high; // r6
  bool v12; // cr56
  idMD6Skel v13; // [sp+50h] [-40h] BYREF

  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai)->decl;
  idMD6Skel::GetUserChannelIndex(
    this: &v13,
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)decl->model->skeleton,
    name: "animMoveMode");
  v3 = SHIWORD(v13.__vftable);
  v4 = SHIWORD(v13.__vftable) < 0;
  this->userChannels[0].value = HIWORD(v13.__vftable);
  if ( !v4 )
    idLib::Printf(fmt: "Model '%s' got channel '%s' as %d\n", decl->name.str, "animMoveMode", v3);
  idMD6Skel::GetUserChannelIndex(
    this: (idMD6Skel *)((char *)&v13.__vftable + 2),
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)decl->model->skeleton,
    name: "animPosture");
  v5 = SLOWORD(v13.__vftable);
  v6 = SLOWORD(v13.__vftable) < 0;
  this->userChannels[1].value = (__int16)v13.__vftable;
  if ( !v6 )
    idLib::Printf(fmt: "Model '%s' got channel '%s' as %d\n", decl->name.str, "animPosture", v5);
  idMD6Skel::GetUserChannelIndex(
    this: (idMD6Skel *)&v13.trackedMemory,
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)decl->model->skeleton,
    name: "animSteer");
  trackedMemory_high = SHIWORD(v13.trackedMemory);
  v8 = v13.trackedMemory < 0;
  this->userChannels[2].value = HIWORD(v13.trackedMemory);
  if ( !v8 )
    idLib::Printf(fmt: "Model '%s' got channel '%s' as %d\n", decl->name.str, "animSteer", trackedMemory_high);
  idMD6Skel::GetUserChannelIndex(
    this: (idMD6Skel *)((char *)&v13.trackedMemory + 2),
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)decl->model->skeleton,
    name: "animClip");
  trackedMemory_low = SLOWORD(v13.trackedMemory);
  v10 = SLOWORD(v13.trackedMemory) < 0;
  this->userChannels[3].value = v13.trackedMemory;
  if ( !v10 )
    idLib::Printf(fmt: "Model '%s' got channel '%s' as %d\n", decl->name.str, "animClip", trackedMemory_low);
  idMD6Skel::GetUserChannelIndex(
    this: (idMD6Skel *)&v13.name,
    result: (idIndex<short,enum invalidUserChannelIndex_t> *)decl->model->skeleton,
    name: "animGravity");
  str_high = SHIWORD(v13.name.str);
  v12 = SHIWORD(v13.name.str) < 0;
  this->userChannels[4].value = HIWORD(v13.name.str);
  if ( !v12 )
    idLib::Printf(fmt: "Model '%s' got channel '%s' as %d\n", decl->name.str, "animGravity", str_high);
}


// ========================================================================
// ?UpdateArrivalTransitionCache@idAnimBaseFSM@@QAA_NHPBD@Z
// EA  : 0x82A6D278
// RVA : 0x00A6D278
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::UpdateArrivalTransitionCache(
        idAnimBaseFSM *this,
        int nodeCheckFlags,
        const char *transitionSubweb)
{
  int *v6; // r10
  float *p_destAnimUpdateDistanceMinSqr; // r11
  int i; // ctr
  idAIAnimWebState_Idle *v9; // r3
  idAnimWebState *v10; // r11
  int *v11; // r10
  idAtomicString *p_debugState; // r11
  int j; // ctr
  int v15; // [sp+4Ch] [-94h] BYREF
  idAnimWebPath v16; // [sp+50h] [-90h] BYREF
  idAIAnimWebState_Current v17; // [sp+70h] [-70h] BYREF
  idAIAnimWebState_Idle v18[3]; // [sp+90h] [-50h] BYREF

  idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v17, ai: this->ai);
  v6 = &v15;
  p_destAnimUpdateDistanceMinSqr = &this->currentMove.destAnimUpdateDistanceMinSqr;
  for ( i = 5; i != 0; --i )
    *++v6 = *(_DWORD *)++p_destAnimUpdateDistanceMinSqr;
  if ( !idAnimWebState::Verify(this: (idAnimWebState *)&v16, errorMsg: nullptr) )
  {
    v9 = idAIAnimWebState_Idle::idAIAnimWebState_Idle(
           this: v18,
           ai: this->ai,
           subweb: AISUBWEB_MAX,
           posture: POSTURE_MAX,
           useWeaponSlot: EQUIP_MAX);
    v10 = &v9->idAnimWebState;
    if ( v9 == nullptr )
      v10 = nullptr;
    v11 = &v15;
    p_debugState = &v10[-1].debugState;
    for ( j = 5; j != 0; --j )
    {
      ++p_debugState;
      *++v11 = (int)p_debugState->str;
    }
    v18[0].__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
  }
  if ( !idAnimWebState::operator!=(this: &this->arrivalTransitionCache.srcState, other: &v17.idAnimWebState)
    && !idAnimWebState::operator!=(this: &this->arrivalTransitionCache.dstState, other: (const idAnimWebState *)&v16)
    && this->arrivalTransitionCache.lastCheckFlags == nodeCheckFlags )
  {
    return 0;
  }
  idAnimWebTransitions::InitTransitionCache(
    ai: this->ai,
    cache: &this->arrivalTransitionCache,
    srcState: (idAnimWebPath *)&v17.idAnimWebState,
    dstState: &v16,
    nodeCheckFlags,
    additionalSubweb: transitionSubweb);
  return 1;
}


// ========================================================================
// __unwind$498437
// EA  : 0x82A6D394
// RVA : 0x00A6D394
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_498437()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 224 + 112));
}


// ========================================================================
// ?StartTurnAnimation@idAnimBaseFSM@@QAA_NAAUtransitionQueryResult_t@idAnimWebTransitions@@ABVidVec3@@@Z
// EA  : 0x82A6D3C8
// RVA : 0x00A6D3C8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::StartTurnAnimation(
        idAnimBaseFSM *this,
        idAnimWebTransitions::transitionQueryResult_t *transInfo,
        const idVec3 *destinationOrigin)
{
  idAIAnimWebState_Movement *v5; // r3
  idAnimWebState *v6; // r11
  int *v7; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr
  idAI2 *ai; // r3
  idAnimWebCmdCtx *v11; // r3
  idAnimWebCmd *v12; // r3
  idAnimWebCmd *v13; // r3
  idAnimWebCmd *v14; // r3
  __int64 v15; // r10
  int selectionIndex; // r11
  idAIAnimWebState_Transition v18; // [sp+60h] [-140h] BYREF
  int v19; // [sp+7Ch] [-124h] BYREF
  idAnimWebState v20; // [sp+80h] [-120h] BYREF
  idAIAnimWebState_Movement v21; // [sp+A0h] [-100h] BYREF
  idAnimWebCmd v22; // [sp+C0h] [-E0h] BYREF

  idAIAnimWebState_Transition::idAIAnimWebState_Transition(
    this: &v18,
    ai: this->ai,
    out: transInfo,
    skipTrace: true,
    skipVerifyPointOutsideAnimRange: true);
  if ( !idAnimWebState::Verify(this: &v18.idAnimWebState, errorMsg: nullptr) )
    return 0;
  v5 = idAIAnimWebState_Movement::idAIAnimWebState_Movement(
         this: &v21,
         ai: this->ai,
         postfix: nullptr,
         subweb: AISUBWEB_MAX,
         posture: POSTURE_MAX);
  v6 = &v5->idAnimWebState;
  if ( v5 == nullptr )
    v6 = nullptr;
  v7 = &v19;
  p_debugState = &v6[-1].debugState;
  for ( i = 5; i != 0; --i )
  {
    ++p_debugState;
    *++v7 = (int)p_debugState->str;
  }
  ai = this->ai;
  v21.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
  v11 = ai->GetAnimWebCmdCtx(this: ai);
  idAnimWebCmd::idAnimWebCmd(
    this: &v22,
    _owner: v11,
    userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM.cpp(1413) : turn transition");
  v22.flags |= 0x200u;
  v12 = idAnimWebCmd::ChangeState(this: &v22, _dst: &v20);
  v12->intrBlend = INTR_BLEND_MULTI;
  v12->intrPath = INTR_PATH_IMMEDIATE;
  v12->groups = 1;
  v13 = idAnimWebCmd::Via(this: v12, _via: &v18.idAnimWebState, optional: false);
  v14 = idAnimWebCmd::Force(this: v13, blendFrames: 3, originBlend: ORIGINBLEND_BRANCH);
  if ( idAnimWebCmd::Commit(
         this: v14,
         handle: &this->animWaitHandle,
         priority: AWCMD_PRIORITY_HIGH,
         ev: AWCMD_EVENT_DEST_BLEND_END) != AWCMD_STATUS_OK )
  {
    this->animBlendVars.animTurnSelect.used = false;
    this->animBlendVars.animTurnSelect.value = 0.0;
    return 0;
  }
  selectionIndex = transInfo->selectionIndex;
  this->animBlendVars.animTurnSelect.used = true;
  LODWORD(v15) = selectionIndex;
  this->animBlendVars.animTurnSelect.value = (float)v15;
  return 1;
}


// ========================================================================
// __unwind$498501
// EA  : 0x82A6D52C
// RVA : 0x00A6D52C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_498501()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 416 + 96));
}


// ========================================================================
// ?PrintDebugInfo@idAnimFSM@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A6D558
// RVA : 0x00A6D558
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimFSM::PrintDebugInfo(idAnimFSM *this, idGuiListBox *info)
{
  idAnimBaseFSM::PrintDebugInfo(this, info);
}


// ========================================================================
// ?DeleteNavigator@idAnimFSM_NP@@IAAXXZ
// EA  : 0x82A6D560
// RVA : 0x00A6D560
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::DeleteNavigator(idAnimFSM_NP *this)
{
  idNpNavigator *groundNavigator; // r31

  groundNavigator = this->groundNavigator;
  if ( groundNavigator != nullptr )
  {
    idNpNavigator::~idNpNavigator(this: this->groundNavigator);
    idMem::Free(this: &mem, ptr: groundNavigator, align: ALIGN_16);
    this->groundNavigator = nullptr;
  }
  else
  {
    this->groundNavigator = nullptr;
  }
}


// ========================================================================
// ?SetOnLink@idAnimFSM_NP@@UAA_N_N@Z
// EA  : 0x82A6D5D0
// RVA : 0x00A6D5D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_NP::SetOnLink(idAnimFSM_NP *this, bool onLink)
{
  int num; // r11
  idNpLink *list; // r10
  idNpCornerInfo *v5; // r30

  if ( onLink )
  {
    num = this->cachedCorners.num;
    if ( num <= 1 )
      list = nullptr;
    else
      list = (idNpLink *)this->cachedCorners.list;
    if ( num <= 2 )
      v5 = nullptr;
    else
      v5 = this->cachedCorners.list + 1;
    if ( list == nullptr
      || v5 == nullptr
      || list->impl != (idNpLinkImpl *)1
      || v5->cornerType != CORNER_LINKEND
      || !idNpLink::TryReserveLink(this: list + 6, reservation: &this->linkTraversing, force: true) )
    {
      idLib::Warning(fmt: "idAnimFSM::SetOnLink failed");
      return 0;
    }
    idNpNavigator::SetNavOrigin(this: this->groundNavigator, pos: &v5->position);
    idNpCornerInfo::operator=(this: &this->linkEndCorner, __that: v5);
  }
  else
  {
    idNpLink::Release(this: &this->linkTraversing);
  }
  this->UpdateCachedCorners(this);
  return 1;
}


// ========================================================================
// ?GetPathDelta@idAnimFSM@@MBA?AVidVec3@@ABV2@M_N@Z
// EA  : 0x82A6D6D0
// RVA : 0x00A6D6D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM *__fastcall idAnimFSM::GetPathDelta(
        idAnimFSM *this,
        idVec3 *result,
        const idVec3 *lastOrigin,
        double deltaLength,
        bool stopAtLink,
        char a6)
{
  double v8; // fp7
  double v9; // fp6
  float y; // r8
  float z; // r7
  float v13[4]; // [sp+50h] [-50h] BYREF
  _BYTE v14[16]; // [sp+60h] [-40h] BYREF
  float v15; // [sp+70h] [-30h] BYREF
  char v16; // [sp+74h] [-2Ch]
  char v17; // [sp+75h] [-2Bh]
  int v18; // [sp+78h] [-28h]
  char v19; // [sp+7Ch] [-24h]

  if ( SLODWORD(result[79].z) <= 0 )
  {
    y = vec3_origin.y;
    z = vec3_origin.z;
    this->idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_vtbl *)LODWORD(vec3_origin.x);
    *(float *)&this->listenerList = y;
    *(float *)&this->listeningToList = z;
  }
  else
  {
    v15 = deltaLength;
    v17 = a6;
    v16 = 1;
    v18 = 0;
    v19 = 1;
    (*(void (__fastcall **)(idVec3 *, float *, float *, _BYTE *))(LODWORD(result->x) + 112))(
      a1: result,
      a2: &v15,
      a3: v13,
      a4: v14);
    v8 = (float)(v13[1] - lastOrigin->y);
    v9 = (float)(v13[2] - lastOrigin->z);
    *(float *)&this->idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = v13[0] - lastOrigin->x;
    *(float *)&this->listenerList = v8;
    *(float *)&this->listeningToList = v9;
  }
  return this;
}


// ========================================================================
// ?MoveAIEmergencyLerp@idAnimBaseFSM@@IAAXXZ
// EA  : 0x82A6D7A8
// RVA : 0x00A6D7A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::MoveAIEmergencyLerp(idAnimBaseFSM *this)
{
  idPhysics *Physics; // r3
  float *v3; // r30
  const idVec3 *v4; // r3
  double v5; // fp13
  double v6; // fp12
  double v7; // fp0
  idAI2 *v8; // r11
  idAI2 *ai; // r31
  unsigned int v10; // r3
  const idVec3 *v11; // r4
  float v12[6]; // [sp+50h] [-30h] BYREF

  if ( this->cachedCorners.num <= 0 )
  {
    this->ai->aiVolatile.physics.object.movementType = AI_MOVE_WALKING;
    ai = this->ai;
    v10 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v11 = &vec3_origin;
  }
  else
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v4 = this->GetFinalPoint(this: &this->idAIMoveInterface);
    v5 = (float)(v4->y - v3[1]);
    v6 = (float)(v4->z - v3[2]);
    v7 = (float)((float)1.0
               / (float)__fsqrts((float)((float)((float)(v4->x - *v3) * (float)(v4->x - *v3))
                                       + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))));
    if ( v7 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    v8 = this->ai;
    v12[0] = (float)(v4->x - *v3) * (float)v7;
    v12[1] = (float)v5 * (float)v7;
    v8->aiVolatile.physics.object.movementType = AI_MOVE_WALKING;
    v12[2] = (float)v6 * (float)v7;
    ai = this->ai;
    v10 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v11 = (const idVec3 *)v12;
  }
  idPhysics_AI::SetDelta(this: &ai->aiVolatile.physics.object, d: v11, ticksPerFrame: v10);
}


// ========================================================================
// ?CheckForEndDeltaCorrectionEmergencyLerp@idAnimBaseFSM@@QAA_NXZ
// EA  : 0x82A6D910
// RVA : 0x00A6D910
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::CheckForEndDeltaCorrectionEmergencyLerp(idAnimBaseFSM *this)
{
  if ( this->cachedCorners.num <= 0 )
    return 0;
  this->emergencyLerp = (_cntlzw(this->IsMoveDone(this)) & 0x20) != 0;
  return 1;
}


// ========================================================================
// ?UpdateAvoidance@idAnimFSM_NP@@MBAXMAAVidVec3@@@Z
// EA  : 0x82A6D980
// RVA : 0x00A6D980
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::UpdateAvoidance(idAnimFSM_NP *this, double animSpeed, idVec3 *pathDelta, float *a4)
{
  float v6; // r7
  float v7; // r5
  int v8; // ctr
  float *p_a; // r11
  double v12; // fp3
  double v13; // fp3
  double y; // fp29
  double x; // fp30
  double z; // fp28
  double v17; // fp24
  int v18; // r28
  idRenderWorld *v19; // r31
  double v20; // fp31
  double v21; // fp27
  double v22; // fp26
  idPhysics *Physics; // r3
  float *v24; // r3
  idAI2 *ai; // r3
  double v26; // fp8
  double v27; // fp6
  double v28; // fp5
  idPhysics *v29; // r3
  int v30; // r3
  idNpNavigator::idNavWedge *v31; // r30
  int i; // r31
  idAI2 *v33; // r21
  idPhysics *v34; // r3
  const idVec3 *v35; // r20
  int v36; // r3
  const idColor *v37; // r7
  double v38; // fp27
  int v39; // r31
  double v40; // fp26
  idNpNavigator::idNavWedge *v41; // r30
  long double v42; // fp2
  int v43; // r9
  double v44; // fp0
  double v45; // fp30
  double v46; // fp0
  long double v47; // fp2
  idVec3 *v48; // r3
  idColor *v49; // r11
  float r; // r10
  float g; // r9
  float b; // r8
  float a; // r7
  double v54; // fp13
  idRenderWorld *v55; // r31
  idPhysics *v56; // r3
  float *v57; // r3
  idAI2 *v58; // r3
  double v59; // fp12
  double v60; // fp10
  double v61; // fp9
  idPhysics *v62; // r3
  int v63; // r3
  idRenderWorld *v64; // r3
  idRenderWorld *v65; // r31
  idVec3 *v66; // r3
  double v67; // fp30
  double v68; // fp29
  double v69; // fp28
  idPhysics *v70; // r3
  float *v71; // r3
  idAI2 *v72; // r3
  double v73; // fp3
  double v74; // fp1
  double v75; // fp0
  idPhysics *v76; // r3
  int v77; // r3
  idRenderWorld *v78; // r3
  idRenderWorld *v79; // r31
  idVec3 *v80; // r3
  double v81; // fp29
  double v82; // fp28
  double v83; // fp31
  idPhysics *v84; // r3
  float *v85; // r3
  idAI2 *v86; // r3
  double v87; // fp8
  double v88; // fp6
  double v89; // fp5
  idPhysics *v90; // r3
  int v91; // r3
  idVec3 v92; // [sp+50h] [-1D0h] BYREF
  idTypesafeNumber<float,enum DegreesUnique_t> v93[2]; // [sp+60h] [-1C0h] BYREF
  idVec3 v94; // [sp+68h] [-1B8h] BYREF
  float v95[4]; // [sp+78h] [-1A8h] BYREF
  float v96[4]; // [sp+88h] [-198h] BYREF
  float v97[4]; // [sp+98h] [-188h] BYREF
  float v98[6]; // [sp+A8h] [-178h] BYREF
  float v99[4]; // [sp+C0h] [-160h] BYREF
  idColor v100; // [sp+D0h] [-150h] BYREF
  idColor v101; // [sp+E0h] [-140h] BYREF
  float v102[50]; // [sp+F0h] [-130h] BYREF

  if ( ai_avoidanceEnabled.valueInteger == 1 || ai_avoidanceEnabled.valueInteger == this->ai->entityNumber )
  {
    v6 = a4[1];
    v7 = a4[2];
    v92.x = *a4;
    v8 = 16;
    p_a = &v101.a;
    _FP6 = (float)((float)((float)(v6 * v6) + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v12 = __frsqrte(_FP4);
    v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                        * (float)((float)((float)(v6 * v6) + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                                                                * (float)0.5))
                                                                                * (float)v12)
                                                                        - (float)1.5)
                                                        * (float)v12)
                                                * (float)((float)((float)(v6 * v6)
                                                                + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v12
                                                                                * (float)((float)((float)(v6 * v6)
                                                                                                + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                                                        * (float)0.5))
                                                                        * (float)v12)
                                                                - (float)1.5)
                                                * (float)v12))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v12
                                                        * (float)((float)((float)(v6 * v6)
                                                                        + (float)((float)(v92.x * v92.x)
                                                                                + (float)(v7 * v7)))
                                                                * (float)0.5))
                                                * (float)v12)
                                        - (float)1.5)
                        * (float)v12));
    y = (float)(v6
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)(v6 * v6)
                                                                      + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
    x = (float)(v92.x
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)(v6 * v6)
                                                                      + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
    z = (float)(v7
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)(v6 * v6)
                                                                      + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
    v92.z = v7
          * (float)((float)-(float)((float)((float)((float)v13
                                                  * (float)((float)((float)(v6 * v6)
                                                                  + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                          * (float)0.5))
                                          * (float)v13)
                                  - (float)1.5)
                  * (float)v13);
    v17 = (float)((float)((float)-(float)((float)((float)((float)v13
                                                        * (float)((float)((float)(v6 * v6)
                                                                        + (float)((float)(v92.x * v92.x)
                                                                                + (float)(v7 * v7)))
                                                                * (float)0.5))
                                                * (float)v13)
                                        - (float)1.5)
                        * (float)v13)
                * (float)((float)(v6 * v6) + (float)((float)(v92.x * v92.x) + (float)(v7 * v7))));
    v92.y = v6
          * (float)((float)-(float)((float)((float)((float)v13
                                                  * (float)((float)((float)(v6 * v6)
                                                                  + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                          * (float)0.5))
                                          * (float)v13)
                                  - (float)1.5)
                  * (float)v13);
    v92.x = v92.x
          * (float)((float)-(float)((float)((float)((float)v13
                                                  * (float)((float)((float)(v6 * v6)
                                                                  + (float)((float)(v92.x * v92.x) + (float)(v7 * v7)))
                                                          * (float)0.5))
                                          * (float)v13)
                                  - (float)1.5)
                  * (float)v13);
    do
    {
      p_a[1] = 0.0;
      p_a += 2;
      *p_a = 0.0;
      --v8;
    }
    while ( v8 != 0 );
    v18 = idNpNavigator::CalcCollisionFreeWedges(
            this: this->groundNavigator,
            fwd: &v92,
            speed: animSpeed,
            maxWedges: SLODWORD(v7),
            wedgesOut: (idNpNavigator::idNavWedge *)0x10);
    if ( v18 > 0 )
    {
      if ( ai_debugMoveFSMAvoidance.valueInteger != 0 )
      {
        v19 = gameLocal->GetRenderWorld(this: gameLocal);
        v20 = (float)(v92.x * (float)72.0);
        v21 = (float)(v92.y * (float)72.0);
        v22 = (float)(v92.z * (float)72.0);
        Physics = idEntity::GetPhysics(this: this->ai);
        v24 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v26 = (float)(v24[2] + (float)v22);
        v27 = (float)(v24[1] + (float)v21);
        v28 = (float)((float)v20 + *v24);
        ai = this->ai;
        v96[0] = v28;
        v96[2] = v26;
        v96[1] = v27;
        v29 = idEntity::GetPhysics(this: ai);
        v30 = (int)v29->GetOrigin(this: v29, a2: 0);
        v19->DebugLine(
          this: v19,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idVec3 *)v30,
          a4: (const idVec3 *)v96,
          a5: 0,
          a6: false);
        v31 = (idNpNavigator::idNavWedge *)v102;
        for ( i = v18; i != 0; --i )
        {
          v33 = this->ai;
          v99[0] = idColor::colorBlue.r;
          v99[1] = idColor::colorBlue.g;
          v99[2] = idColor::colorBlue.b;
          v99[3] = 0.25;
          v34 = idEntity::GetPhysics(this: v33);
          v35 = v34->GetOrigin(this: v34, a2: 0);
          v36 = (int)v33->GetNavParms(this: v33);
          idNpNavigator::idNavWedge::Render(
            this: v31++,
            pos: v35,
            fwd: &v92,
            up: &this->orientBody.axis.mat[2],
            radius: *(float *)(v36 + 112),
            color: v37,
            duration: (const int)v99);
        }
      }
      v38 = 0.0;
      v39 = 0;
      v40 = 0.0;
      v41 = (idNpNavigator::idNavWedge *)v102;
      while ( 1 )
      {
        if ( idNpNavigator::idNavWedge::IsHeadingInside(this: v41, heading: 0.0) )
        {
          v43 = 1;
          goto LABEL_15;
        }
        if ( v41->angleStart > 0.0 )
          break;
        ++v39;
        ++v41;
        if ( v39 >= v18 )
        {
          v43 = 2;
LABEL_14:
          v40 = v102[0];
          v38 = v102[2 * v18 - 1];
          goto LABEL_15;
        }
      }
      v43 = 2;
      if ( v39 <= 0 )
        goto LABEL_14;
      v40 = v102[2 * v39];
      v38 = v102[2 * v39 - 1];
LABEL_15:
      v100 = idColor::colorMagenta;
      v101 = idColor::colorMagenta;
      if ( v43 == 2 )
      {
        v44 = v38;
        if ( v38 >= 360.0 || v38 < 0.0 )
        {
          *(double *)&v42 = (float)((float)v38 * (float)0.0027777778);
          v42 = floor(x: v42);
          v44 = (float)-(float)((float)((float)*(double *)&v42 * (float)360.0) - (float)v38);
        }
        v45 = v44;
        if ( v44 > 180.0 )
          v45 = (float)((float)v44 - (float)360.0);
        v38 = v45;
        v46 = v40;
        if ( v40 >= 360.0 || v40 < 0.0 )
        {
          *(double *)&v42 = (float)((float)v40 * (float)0.0027777778);
          v47 = floor(x: v42);
          v46 = (float)-(float)((float)((float)*(double *)&v47 * (float)360.0) - (float)v40);
        }
        if ( v46 > 180.0 )
          v46 = (float)((float)v46 - (float)360.0);
        LODWORD(v93[1].value) = (int)v46;
        v40 = v46;
        if ( (int)abs32((int)v45) <= (int)abs32((int)v46) )
        {
          v93[0].value = v45;
          v48 = idVec3::RotateCopy(this: &v94, result: &v92, axis: &this->orientBody.axis.mat[2], angle: v93);
          v49 = &v100;
        }
        else
        {
          v93[0].value = v46;
          v48 = idVec3::RotateCopy(this: &v94, result: &v92, axis: &this->orientBody.axis.mat[2], angle: v93);
          v49 = &v101;
        }
        r = idColor::colorCyan.r;
        x = v48->x;
        g = idColor::colorCyan.g;
        y = v48->y;
        b = idColor::colorCyan.b;
        z = v48->z;
        a = idColor::colorCyan.a;
        v54 = (float)(v48->y * (float)v17);
        *a4 = v48->x * (float)v17;
        v49->r = r;
        v49->g = g;
        a4[1] = v54;
        v49->b = b;
        a4[2] = (float)z * (float)v17;
        v49->a = a;
      }
      if ( ai_debugMoveFSMAvoidance.valueInteger != 0 )
      {
        v55 = gameLocal->GetRenderWorld(this: gameLocal);
        v56 = idEntity::GetPhysics(this: this->ai);
        v57 = (float *)v56->GetOrigin(this: v56, a2: 0);
        v59 = (float)(v57[2] + (float)((float)z * (float)64.0));
        v60 = (float)(v57[1] + (float)((float)y * (float)64.0));
        v61 = (float)(*v57 + (float)((float)x * (float)64.0));
        v58 = this->ai;
        v98[0] = v61;
        v98[2] = v59;
        v98[1] = v60;
        v62 = idEntity::GetPhysics(this: v58);
        v63 = (int)v62->GetOrigin(this: v62, a2: 0);
        v55->DebugLine(
          this: v55,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idVec3 *)v63,
          a4: (const idVec3 *)v98,
          a5: 0,
          a6: false);
        v64 = gameLocal->GetRenderWorld(this: gameLocal);
        v93[0].value = v38;
        v65 = v64;
        v66 = idVec3::RotateCopy(this: &v94, result: &v92, axis: &this->orientBody.axis.mat[2], angle: v93);
        v67 = (float)(v66->x * (float)32.0);
        v68 = (float)(v66->y * (float)32.0);
        v69 = (float)(v66->z * (float)32.0);
        v70 = idEntity::GetPhysics(this: this->ai);
        v71 = (float *)v70->GetOrigin(this: v70, a2: 0);
        v73 = (float)(v71[2] + (float)v69);
        v74 = (float)(v71[1] + (float)v68);
        v75 = (float)(*v71 + (float)v67);
        v72 = this->ai;
        v97[0] = v75;
        v97[2] = v73;
        v97[1] = v74;
        v76 = idEntity::GetPhysics(this: v72);
        v77 = (int)v76->GetOrigin(this: v76, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v65->DebugArrow)(
          a1: v65,
          a2: &v100,
          a3: v77,
          a4: v97,
          a5: 16.0);
        v78 = gameLocal->GetRenderWorld(this: gameLocal);
        v93[0].value = v40;
        v79 = v78;
        v80 = idVec3::RotateCopy(this: &v94, result: &v92, axis: &this->orientBody.axis.mat[2], angle: v93);
        v81 = (float)(v80->x * (float)32.0);
        v82 = (float)(v80->y * (float)32.0);
        v83 = (float)(v80->z * (float)32.0);
        v84 = idEntity::GetPhysics(this: this->ai);
        v85 = (float *)v84->GetOrigin(this: v84, a2: 0);
        v87 = (float)(v85[2] + (float)v83);
        v88 = (float)(v85[1] + (float)v82);
        v89 = (float)(*v85 + (float)v81);
        v86 = this->ai;
        v95[0] = v89;
        v95[2] = v87;
        v95[1] = v88;
        v90 = idEntity::GetPhysics(this: v86);
        v91 = (int)v90->GetOrigin(this: v90, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v79->DebugArrow)(
          a1: v79,
          a2: &v101,
          a3: v91,
          a4: v95,
          a5: 16.0);
      }
    }
  }
}


// ========================================================================
// ?ShouldStartAASTraversal@idAnimFSM_AAS@@UAA_NAAVidVec3@@0AAVidMat3@@AAUaas2Traversal_t@@@Z
// EA  : 0x82A6E100
// RVA : 0x00A6E100
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAnimFSM_AAS::ShouldStartAASTraversal(
        idAnimFSM_AAS *this,
        idVec3 *outStartOrigin,
        idVec3 *outEndOrigin,
        idMat3 *traversalAxis,
        aas2Traversal_t *outTraversal)
{
  idNpCornerInfo *list; // r11
  idAIMoveInterface_vtbl *v11; // r24
  idAIMoveInterface *v12; // r30
  float y; // r9
  float z; // r8
  int v15; // r23
  signed int v16; // r3
  bool (__fastcall *WillReachPoint)(idAIMoveInterface *, const idVec3 *, float, bool); // r10
  __int64 v18; // r7
  const idAAS2 *v19; // r3
  const aas2Traversal_t *v20; // r30
  float v21; // r6
  float v22; // r5
  idAI2 *ai; // r3
  idPhysics *Physics; // r3
  const idVec3 *v25; // r3
  idAI2 *v26; // r3
  idPhysics *v27; // r3
  const idVec3 *v28; // r3
  double v29; // fp30
  double v30; // fp29
  double v31; // fp28
  idPhysics *v32; // r3
  float *v33; // r3
  double v34; // fp27
  __int64 v35; // r6
  int v36; // r2 OVERLAPPED
  double v37; // fp9
  __int64 v38; // r10
  __int64 v39; // r5
  int v40; // r3
  idVec3 v42; // [sp+50h] [-E0h] BYREF
  idVec3 v43; // [sp+60h] [-D0h] BYREF
  idVec3 v44; // [sp+70h] [-C0h] BYREF
  idMat3 v45[2]; // [sp+80h] [-B0h] BYREF

  if ( this->cachedCorners.num == 0 )
    return 0;
  list = this->cachedCorners.list;
  v11 = this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable;
  v12 = &this->idAIMoveInterface;
  y = list->position.y;
  z = list->position.z;
  v43.x = list->position.x;
  v43.y = y;
  v43.z = z;
  v15 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v16 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
  WillReachPoint = v11->WillReachPoint;
  LODWORD(v18) = v15 / v16;
  *(_QWORD *)&v42.x = v18;
  __twllei(v16, 0);
  __twlgei(v16 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
  if ( ((unsigned __int8 (__fastcall *)(idAIMoveInterface *, idVec3 *, double))WillReachPoint)(
         a1: v12,
         a2: &v43,
         a3: (float)v18) == 0 )
    return 0;
  if ( (unsigned __int16)this->lastPath.reachIndex.value >= 0x8000u )
    return 0;
  if ( this->lastPath.traversalIndex <= 0 )
    return 0;
  v19 = this->ai->GetAAS(this: this->ai);
  v20 = v19->GetTraversal(this: v19, a2: this->lastPath.traversalIndex);
  v21 = this->lastPath.traversalStart.y;
  v22 = this->lastPath.traversalStart.z;
  ai = this->ai;
  v42.x = this->lastPath.traversalStart.x;
  v42.y = v21;
  v42.z = v22;
  Physics = idEntity::GetPhysics(this: ai);
  v25 = Physics->GetGravityNormal(this: Physics);
  idVec3::ProjectOntoPlane(this: &v42, normal: v25, overBounce: 1.0);
  v26 = this->ai;
  v44 = v43;
  v27 = idEntity::GetPhysics(this: v26);
  v28 = v27->GetGravityNormal(this: v27);
  idVec3::ProjectOntoPlane(this: &v44, normal: v28, overBounce: 1.0);
  v29 = (float)(v44.x - v42.x);
  v30 = (float)(v44.y - v42.y);
  v31 = (float)(v44.z - v42.z);
  v32 = idEntity::GetPhysics(this: this->ai);
  v33 = (float *)((int (__fastcall *)(idVec3 *))v32->GetLinearVelocity)(a1: &v44);
  v34 = __fsqrts((float)((float)(v33[2] * v33[2]) + (float)((float)(*v33 * *v33) + (float)(v33[1] * v33[1]))));
  LODWORD(v35) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  *(_QWORD *)&v42.x = v35;
  v37 = (float)((float)((float)1.0 / (float)v35) * (float)v34);
  if ( (float)((float)((float)v29 * (float)v29)
             + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) > (double)(float)((float)v37 * (float)v37) )
    return 0;
  HIDWORD(v38) = (unsigned __int16)v20->orientationFwd.y;
  HIDWORD(v39) = v45;
  LODWORD(v39) = v20->orientationFwd.x;
  v40 = SWORD1(v38);
  LODWORD(v38) = v20->orientationFwd.z;
  *(_QWORD *)&v42.x = v38;
  v45[0].mat[0].x = (float)v39 * (float)0.000030518509;
  v45[0].mat[0].y = (float)*(__int64 *)(&v36 - 1) * (float)0.000030518509;
  v45[0].mat[0].z = (float)v38 * (float)0.000030518509;
  *traversalAxis = *idVec3::ToMat3(this: (idVec3 *)&v45[0].mat[1].y, result: v45);
  outStartOrigin->x = v20->startPoint.x;
  outStartOrigin->y = v20->startPoint.y;
  outStartOrigin->z = v20->startPoint.z;
  outEndOrigin->x = v20->endPoint.x;
  outEndOrigin->y = v20->endPoint.y;
  outEndOrigin->z = v20->endPoint.z;
  aas2Traversal_t::operator=(this: outTraversal, __that: v20);
  return 1;
}


// ========================================================================
// ?RecentlyFailedMove@idAnimBaseFSM@@UAA_NW4aiMoveReason_t@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A6E488
// RVA : 0x00A6E488
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::RecentlyFailedMove(
        idAnimBaseFSM *this,
        const aiMoveReason_t reason,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *timeout)
{
  int v6; // r26
  float obstacleEntityThreshold; // r11
  int i; // r31
  int GameMs; // r3

  v6 = 0;
  if ( SLODWORD(this->obstacleInfo.moveFrustrationThreshold) <= 0 )
    return 0;
  obstacleEntityThreshold = this->obstacleInfo.obstacleEntityThreshold;
  for ( i = 0; ; i += 8 )
  {
    if ( *(unsigned __int8 *)(i + LODWORD(obstacleEntityThreshold)) == reason )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      obstacleEntityThreshold = this->obstacleInfo.obstacleEntityThreshold;
      if ( *(_DWORD *)(i + LODWORD(obstacleEntityThreshold) + 4) + timeout->value >= GameMs )
        break;
    }
    if ( ++v6 >= SLODWORD(this->obstacleInfo.moveFrustrationThreshold) )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Reset@idAnimBaseFSM@@UAAXXZ
// EA  : 0x82A6E570
// RVA : 0x00A6E570
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::Reset(idAnimBaseFSM *this)
{
  const animDeltaCorrection_t *v2; // r3
  idAnimBaseFSM_vtbl *v3; // r4
  animDeltaCorrection_t v4; // [sp+50h] [-1F0h] BYREF

  idAnimWebCmdWaitHandle::Init(this: &this->animWaitHandle);
  this->desiredMoveAxis = mat3_identity;
  this->navNextPos = vec3_origin;
  this->navFinalPos = vec3_origin;
  this->navFinalAxis = mat3_identity;
  this->nextArrivalPos = vec3_origin;
  this->nextArrivalAxis = mat3_identity;
  this->nextArrivalCorner = -1;
  this->nextLinkPos = vec3_origin;
  this->nextLinkAxis = mat3_identity;
  this->nextLinkCorner = -1;
  v2 = animDeltaCorrection_t::animDeltaCorrection_t(this: &v4);
  animDeltaCorrection_t::operator=(this: &this->animDeltaCorrection, __that: v2);
  v3 = this->idAIFSMLite::idEventReceiver::idClass::__vftable;
  this->puppetModeMask = 0;
  v3->InitNavTraceSystem(this);
}


// ========================================================================
// ?Reset@idAnimFSM_AAS@@UAAXXZ
// EA  : 0x82A6E780
// RVA : 0x00A6E780
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::Reset(idAnimFSM_AAS *this)
{
  idAnimBaseFSM::Reset(this);
  memset(Dst: &this->lastPath, Val: 0, Size: sizeof(this->lastPath));
}


// ========================================================================
// ?HasReachedDestination@idAnimBaseFSM@@UBA?AW4reachDestFlags_t@1@ABVidAIMoveCmd@@ABUidAIMoveInfo@@@Z
// EA  : 0x82A6E7C0
// RVA : 0x00A6E7C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimBaseFSM::reachDestFlags_t __fastcall idAnimBaseFSM::HasReachedDestination(
        idAnimBaseFSM *this,
        const idAIMoveCmd *moveCmd,
        const idAIMoveInfo *moveInfo)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  int value; // r9
  double v9; // fp31
  double v10; // fp30
  double arrivalRadius; // fp29
  double v12; // fp27
  double v13; // fp28
  idEntity *v14; // r3
  int v15; // r9
  idEntity *v16; // r3
  idEntity *v17; // r4
  int v18; // r31
  double arrivalHeight; // fp0
  idAnimBaseFSM::reachDestFlags_t result; // r3
  bool IsAligned; // zf

  Physics = idEntity::GetPhysics(this: this->ai);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  value = moveCmd->destEnt.spawnId.value;
  v9 = (float)(moveInfo->destPosition.x - *v7);
  v10 = (float)(moveInfo->destPosition.y - v7[1]);
  arrivalRadius = moveCmd->arrivalRadius;
  v12 = (float)(moveInfo->destPosition.z - v7[2]);
  v13 = __fsqrts((float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)));
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v14 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v14 != nullptr && idEntity::CastTo(c: v14) != nullptr )
    {
      v15 = moveCmd->destEnt.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
        && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
      {
        v17 = idEntity::CastTo(c: v16);
      }
      else
      {
        v17 = nullptr;
      }
      arrivalRadius = ((double (__fastcall *)(idAIMoveInterface *, idEntity *, double))this->GetReachedEntityDist)(
                        a1: &this->idAIMoveInterface,
                        a2: v17,
                        a3: arrivalRadius);
    }
  }
  v18 = 0;
  if ( v13 <= arrivalRadius )
  {
    arrivalHeight = moveCmd->arrivalHeight;
    if ( arrivalHeight < 0.0
      || __fabs((float)((float)(this->orientBody.axis.mat[2].x * (float)v9)
                      + (float)((float)(this->orientBody.axis.mat[2].y * (float)v10)
                              + (float)(this->orientBody.axis.mat[2].z * (float)v12)))) <= arrivalHeight )
    {
      v18 = 1;
    }
  }
  if ( !moveInfo->useDestOrientation )
    return v18;
  IsAligned = idAIOrientation::IsAligned(
                this: &this->orientBody,
                testIdeal: moveInfo->destOrientation.mat,
                degrees: moveCmd->arriveOrientAngleTolerance);
  result = v18 | 2;
  if ( !IsAligned )
    return v18;
  return result;
}


// ========================================================================
// ?Reset@idAnimFSM@@UAAXXZ
// EA  : 0x82A6E968
// RVA : 0x00A6E968
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::Reset(idAnimFSM *this)
{
  idAnimBaseFSM::Reset(this);
  this->lastTransitionCorner = vec3_origin;
}


// ========================================================================
// ?CreateNavigator@idAnimFSM_NP@@IAAXXZ
// EA  : 0x82A6E9C0
// RVA : 0x00A6E9C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::CreateNavigator(idAnimFSM_NP *this)
{
  idNpNavigator *v2; // r3
  idNpNavigator *v3; // r3

  if ( np_enable.valueInteger != 0
    && (gameLocal->GetGameFlags(this: gameLocal) & 0x202) == 0
    && !common->IsClient(this: common)
    && this->groundNavigator == nullptr )
  {
    idAI2::ClearErrorFlags(this: this->ai, flags: 1);
    v2 = (idNpNavigator *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 4u,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
      v3 = idNpNavigator::idNpNavigator(this: v2, ai: this->ai);
    else
      v3 = nullptr;
    this->groundNavigator = v3;
    if ( !idNpNavigator::IsValid(this: v3) )
      idAnimFSM_NP::DeleteNavigator(this);
  }
}


// ========================================================================
// __unwind$500437
// EA  : 0x82A6EACC
// RVA : 0x00A6EACC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall _unwind_500437(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 80), tag: a2);
}


// ========================================================================
// ?EnterHiddenMode@idAnimFSM_NP@@UAAX_N@Z
// EA  : 0x82A6EAF8
// RVA : 0x00A6EAF8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::EnterHiddenMode(idAnimFSM_NP *this, bool hide)
{
  if ( hide )
    idAnimFSM_NP::DeleteNavigator(this);
  else
    idAnimFSM_NP::CreateNavigator(this);
}


// ========================================================================
// ?PrintMoveDebugInfo@idAnimFSM_NP@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A6EB18
// RVA : 0x00A6EB18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::PrintMoveDebugInfo(idAnimFSM_NP *this, idGuiListBox *info)
{
  char v4; // r30
  int puppetModeMask; // r4
  idPhysics *Physics; // r3
  const char *v7; // r29
  idGuiListBox *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idGuiListBox *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idPhysics *v16; // r3
  double v17; // fp31
  idGuiListBox *v18; // r3
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  idGuiListBox *v22; // r3
  __int64 v23; // r6
  __int64 v24; // r10
  __int64 v25; // r8
  idPhysics *v26; // r3
  const char *v27; // r29
  idGuiListBox *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  idGuiListBox *v32; // r3
  __int64 v33; // r10
  __int64 v34; // r8
  __int64 v35; // r6
  idNpAreaHandle *groundNavigator; // r4
  idNpAreaHandle *Area; // r3
  const char *v38; // r28
  idGuiListBox *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  idGuiListBox *v43; // r3
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  const char *v47; // r30
  idGuiListBox *v48; // r3
  __int64 v49; // r10
  __int64 v50; // r8
  __int64 v51; // r6
  idGuiListBox *v52; // r3
  __int64 v53; // r6
  __int64 v54; // r10
  __int64 v55; // r8
  char *data; // r30
  idGuiListBox *v57; // r3
  __int64 v58; // r10
  __int64 v59; // r8
  __int64 v60; // r6
  idGuiListBox *v61; // r3
  __int64 v62; // r10
  __int64 v63; // r8
  __int64 v64; // r6
  const char *v65; // r30
  idGuiListBox *v66; // r3
  __int64 v67; // r10
  __int64 v68; // r8
  __int64 v69; // r6
  idGuiListBox *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r8
  __int64 v73; // r6
  idEntity *v74; // r3
  idEntity *v75; // r3
  char *v76; // r30
  idGuiListBox *v77; // r3
  __int64 v78; // r10
  __int64 v79; // r8
  __int64 v80; // r6
  idGuiListBox *v81; // r3
  __int64 v82; // r10
  __int64 v83; // r8
  __int64 v84; // r6
  idEntity *v85; // r3
  idEntity *v86; // r3
  char *v87; // r30
  idGuiListBox *v88; // r3
  __int64 v89; // r10
  __int64 v90; // r8
  __int64 v91; // r6
  idGuiListBox *v92; // r3
  __int64 v93; // r10
  __int64 v94; // r8
  __int64 v95; // r6
  const char *v96; // r30
  idGuiListBox *v97; // r3
  __int64 v98; // r10
  __int64 v99; // r8
  __int64 v100; // r6
  idGuiListBox *v101; // r3
  __int64 v102; // r10
  __int64 v103; // r8
  __int64 v104; // r6
  int num; // r30
  idGuiListBox *v106; // r3
  __int64 v107; // r10
  __int64 v108; // r6
  __int64 v109; // r8
  int v110; // r22
  int v111; // r14
  char *v112; // r30
  int v113; // r9
  idEntity *v114; // r3
  idEntity *v115; // r28
  __int64 v116; // r10
  __int64 v117; // r8
  __int64 v118; // r6
  char *v119; // r29
  va *v120; // r28
  const char *v121; // r30
  idGuiListBox *v122; // r3
  __int64 v123; // r10
  __int64 v124; // r8
  __int64 v125; // r6
  idGuiListBox *v126; // r3
  __int64 v127; // r10
  __int64 v128; // r8
  __int64 v129; // r30
  __int64 v130; // r6
  char *v131; // r28
  va *v132; // r14
  idGuiListBox *v133; // r3
  __int64 v134; // r10
  __int64 v135; // r8
  __int64 v136; // r6
  idGuiListBox *v137; // r3
  __int64 v138; // r8
  __int64 v139; // r10
  int v140; // [sp+8h] [-11C8h]
  int v141; // [sp+Ch] [-11C4h]
  int v142; // [sp+10h] [-11C0h]
  int v143; // [sp+14h] [-11BCh]
  int v144; // [sp+18h] [-11B8h]
  int v145; // [sp+1Ch] [-11B4h]
  int v146; // [sp+50h] [-1180h]
  idNpAreaHandle v147; // [sp+54h] [-117Ch] BYREF
  const char *v148; // [sp+58h] [-1178h]
  char *v149; // [sp+5Ch] [-1174h]
  float v150[4]; // [sp+60h] [-1170h] BYREF
  idStr v151; // [sp+70h] [-1160h] BYREF
  idStr v152; // [sp+90h] [-1140h] BYREF
  char *v153; // [sp+B0h] [-1120h]
  idNpLinkInfo v154; // [sp+C0h] [-1110h] BYREF
  idAngles v155; // [sp+E8h] [-10E8h] BYREF
  idAngles v156[2]; // [sp+F8h] [-10D8h] BYREF
  idStr v157; // [sp+110h] [-10C0h] BYREF
  va v158; // [sp+130h] [-10A0h] BYREF

  v4 = 0;
  idStr::idStr(this: &v157, text: "NONE");
  puppetModeMask = this->puppetModeMask;
  v148 = " ";
  idTypeInfoTools::GetEnumBitFlags(
    this: typeInfoTools,
    flags: puppetModeMask,
    enumType: "puppetModeTypes_t",
    flagNames: &v157,
    delimiter: " ");
  Physics = idEntity::GetPhysics(this: this->ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v155, result: (idVec3 *)Physics, a3: 0);
  v7 = idVec3::ToString(this: &v155, precision: 2);
  v8 = idGuiListBox::Row(this: info);
  LODWORD(v9) = "1 - formation cover, such as behind regime shield units";
  v12 = idGuiListBox::Printf(this: v8, fmt: "Vel: ", a3: v11, a4: v10, a5: v9);
  idGuiListBox::Printf(this: v12, fmt: v7, a3: v15, a4: v14, a5: v13);
  v16 = idEntity::GetPhysics(this: this->ai);
  v16->GetLinearVelocity(this: (idPhysics *)v150, result: (idVec3 *)v16, a3: 0);
  v17 = __fsqrts((float)((float)(v150[2] * v150[2]) + (float)((float)(v150[0] * v150[0]) + (float)(v150[1] * v150[1]))));
  v18 = idGuiListBox::Row(this: info);
  LODWORD(v19) = "1 - formation cover, such as behind regime shield units";
  v22 = idGuiListBox::Printf(this: v18, fmt: "Speed: ", a3: v19, a4: v21, a5: v20);
  HIDWORD(v23) = LODWORD(v17);
  idGuiListBox::Printf(this: v22, fmt: (const char *)HIDWORD(v17), a3: v23, a4: v25, a5: v24, v17);
  v26 = idEntity::GetPhysics(this: this->ai);
  v26->GetAngularVelocity(this: (idPhysics *)v156, result: (idVec3 *)v26, a3: 0);
  v27 = idVec3::ToString(this: v156, precision: 2);
  v28 = idGuiListBox::Row(this: info);
  HIDWORD(v29) = "1 - formation cover, such as behind regime shield units";
  v32 = idGuiListBox::Printf(this: v28, fmt: "Rot Vel: ", a3: v31, a4: v30, a5: v29);
  idGuiListBox::Printf(this: v32, fmt: v27, a3: v35, a4: v34, a5: v33);
  groundNavigator = (idNpAreaHandle *)this->groundNavigator;
  if ( groundNavigator == nullptr
    || (Area = idNpNavigator::GetArea(this: (idNpNavigator *)&v147, result: groundNavigator),
        v4 = 1,
        v38 = "yes",
        !idNpAreaHandle::IsValid(this: Area)) )
  {
    v38 = "no";
  }
  v39 = idGuiListBox::Row(this: info);
  v43 = idGuiListBox::Printf(this: v39, fmt: "Stranded: ", a3: v42, a4: v41, a5: v40);
  HIDWORD(v44) = v38;
  idGuiListBox::Printf(this: v43, fmt: "%s", a3: v44, a4: v46, a5: v45);
  if ( (v4 & 1) != 0 )
    idNpAreaHandle::~idNpAreaHandle(this: &v147);
  v47 = "yes";
  if ( this->puppetModeMask == 0 )
    v47 = "no";
  v48 = idGuiListBox::Row(this: info);
  v52 = idGuiListBox::Printf(this: v48, fmt: "Puppet: ", a3: v51, a4: v50, a5: v49);
  HIDWORD(v53) = v47;
  idGuiListBox::Printf(this: v52, fmt: "%s", a3: v53, a4: v55, a5: v54);
  data = v157.data;
  v57 = idGuiListBox::Row(this: info);
  LODWORD(v58) = "1 - formation cover, such as behind regime shield units";
  v61 = idGuiListBox::Printf(this: v57, fmt: "PuppetFlags: ", a3: v60, a4: v59, a5: v58);
  idGuiListBox::Printf(this: v61, fmt: data, a3: v64, a4: v63, a5: v62);
  idNpLinkInfo::idNpLinkInfo(this: &v154);
  idNpLink::GetLinkInfo(this: &this->linkTraversing, info: &v154);
  v65 = "yes";
  if ( !idNavigationSpace::IsValid(this: &this->linkTraversing) )
    v65 = "no";
  v66 = idGuiListBox::Row(this: info);
  v70 = idGuiListBox::Printf(this: v66, fmt: "Link Using :", a3: v69, a4: v68, a5: v67);
  idGuiListBox::Printf(this: v70, fmt: v65, a3: v73, a4: v72, a5: v71);
  if ( gameLocal->spawnIds.ptr[v154.linkEntityStart.spawnId.value & 0x1FFF] == v154.linkEntityStart.spawnId.value >> 13
    && (v74 = gameLocal->entities.ptr[v154.linkEntityStart.spawnId.value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v74) != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[v154.linkEntityStart.spawnId.value & 0x1FFF] == v154.linkEntityStart.spawnId.value >> 13
      && (v75 = gameLocal->entities.ptr[v154.linkEntityStart.spawnId.value & 0x1FFF]) != nullptr )
    {
      v76 = idEntity::CastTo(c: v75)->name.data;
    }
    else
    {
      v76 = (char *)MEMORY[0x10];
    }
  }
  else
  {
    v76 = "null";
  }
  v77 = idGuiListBox::Row(this: info);
  v81 = idGuiListBox::Printf(this: v77, fmt: "- Link Ent Start :", a3: v80, a4: v79, a5: v78);
  idGuiListBox::Printf(this: v81, fmt: v76, a3: v84, a4: v83, a5: v82);
  if ( gameLocal->spawnIds.ptr[v154.linkEntityEnd.spawnId.value & 0x1FFF] == v154.linkEntityEnd.spawnId.value >> 13
    && (v85 = gameLocal->entities.ptr[v154.linkEntityEnd.spawnId.value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v85) != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[v154.linkEntityEnd.spawnId.value & 0x1FFF] == v154.linkEntityEnd.spawnId.value >> 13
      && (v86 = gameLocal->entities.ptr[v154.linkEntityEnd.spawnId.value & 0x1FFF]) != nullptr )
    {
      v87 = idEntity::CastTo(c: v86)->name.data;
    }
    else
    {
      v87 = (char *)MEMORY[0x10];
    }
  }
  else
  {
    v87 = "null";
  }
  v88 = idGuiListBox::Row(this: info);
  v92 = idGuiListBox::Printf(this: v88, fmt: "- Link Ent End :", a3: v91, a4: v90, a5: v89);
  idGuiListBox::Printf(this: v92, fmt: v87, a3: v95, a4: v94, a5: v93);
  v96 = "yes";
  if ( !v154.linkData.linkIsJump )
    v96 = "no";
  v97 = idGuiListBox::Row(this: info);
  v101 = idGuiListBox::Printf(this: v97, fmt: "- Jump Link :", a3: v100, a4: v99, a5: v98);
  idGuiListBox::Printf(this: v101, fmt: v96, a3: v104, a4: v103, a5: v102);
  num = this->cachedCorners.num;
  v106 = idGuiListBox::Row(this: info);
  LODWORD(v107) = "1 - formation cover, such as behind regime shield units";
  HIDWORD(v108) = num;
  idGuiListBox::Printf(this: v106, fmt: "Cached Corners: %d", a3: v108, a4: v109, a5: v107);
  v110 = 0;
  if ( this->cachedCorners.num > 0 )
  {
    v111 = 0;
    v146 = 0;
    v149 = "goal";
    v147.impl = (idNpAreaHandleImpl *)"stop";
    while ( 1 )
    {
      v112 = (char *)this->cachedCorners.list + v111;
      v153 = v112 + 44;
      v113 = *((_DWORD *)v112 + 11);
      if ( gameLocal->spawnIds.ptr[v113 & 0x1FFF] == v113 >> 13 )
      {
        v114 = gameLocal->entities.ptr[v113 & 0x1FFF];
        if ( v114 != nullptr )
          v115 = idEntity::CastTo(c: v114);
        else
          v115 = nullptr;
      }
      else
      {
        v115 = nullptr;
      }
      v151.allocedAndFlag = 20;
      v151.len = 0;
      v151.data = v151.baseBuffer;
      v151.baseBuffer[0] = 0;
      if ( (v112[56] & 0x40) != 0 )
        idStr::Append(this: &v151, text: (char *)v147.impl);
      if ( v112[56] < 0 )
        idStr::Append(this: &v151, text: v149);
      v152.allocedAndFlag = 20;
      v152.len = 0;
      v152.data = v152.baseBuffer;
      v152.baseBuffer[0] = 0;
      idTypeInfoTools::GetEnumBitFlags(
        this: typeInfoTools,
        flags: *((_DWORD *)v112 + 7),
        enumType: "navLinkFlags_t",
        flagNames: &v152,
        delimiter: v148);
      idStr::Replace(this: &v152, old: "LinkFl_", nw: &byte_8200D768);
      if ( *(_DWORD *)v112 == 1 )
        break;
      if ( *(_DWORD *)v112 == 2 )
      {
        HIDWORD(v129) = "End";
        goto LABEL_44;
      }
      v119 = v151.data;
      HIDWORD(v118) = v110;
      v120 = va::va(
               this: &v158,
               fmt: "%d) Pos: ",
               a3: v118,
               a4: v117,
               a5: v116,
               a6: v140,
               a7: v141,
               a8: v142,
               a9: v143,
               a10: v144,
               a11: v145);
      v121 = idVec3::ToString(this: (idAngles *)(v112 + 4), precision: 0);
      v122 = idGuiListBox::Row(this: info);
      v126 = idGuiListBox::Printf(this: v122, fmt: v120->buffer, a3: v125, a4: v124, a5: v123);
      idGuiListBox::Printf(
        this: v126,
        fmt: "(%s) %s",
        a3: __SPAIR64__((unsigned int)v121, (unsigned int)v119),
        a4: v128,
        a5: v127);
LABEL_48:
      idStr::FreeData(this: &v152);
      idStr::FreeData(this: &v151);
      ++v110;
      v111 += 60;
      v146 = v111;
      if ( v110 >= this->cachedCorners.num )
        goto LABEL_49;
    }
    HIDWORD(v129) = "Start";
LABEL_44:
    if ( v115 != nullptr )
      LODWORD(v129) = v115->name.data;
    else
      LODWORD(v129) = idVec3::ToString(this: (idAngles *)(v112 + 4), precision: 0);
    v130 = __PAIR64__(v110, HIDWORD(v129));
    v131 = v151.data;
    HIDWORD(v129) = v152.data;
    v132 = va::va(
             this: &v158,
             fmt: "%d) Link %s",
             a3: v130,
             a4: v117,
             a5: v116,
             a6: v140,
             a7: v141,
             a8: v142,
             a9: v143,
             a10: v144,
             a11: v145);
    v133 = idGuiListBox::Row(this: info);
    v137 = idGuiListBox::Printf(this: v133, fmt: v132->buffer, a3: v136, a4: v135, a5: v134);
    HIDWORD(v138) = v131;
    idGuiListBox::Printf(this: v137, fmt: "%s %s %s", a3: v129, a4: v138, a5: v139);
    v111 = v146;
    goto LABEL_48;
  }
LABEL_49:
  idStr::FreeData(this: &v157);
}


// ========================================================================
// __unwind$500506
// EA  : 0x82A6F1F4
// RVA : 0x00A6F1F4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_500506()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 272));
}


// ========================================================================
// __unwind$500508
// EA  : 0x82A6F21C
// RVA : 0x00A6F21C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_500508()
{
  int v0; // r12
  idNpAreaHandle *v1; // r31

  v1 = (idNpAreaHandle *)(v0 - 4560);
  if ( (*(_DWORD *)(v0 - 4560 + 80) & 1) != 0 )
  {
    v1[20].impl = (idNpAreaHandleImpl *)((int)v1[20].impl & ~1u);
    idNpAreaHandle::~idNpAreaHandle(this: v1 + 21);
  }
}


// ========================================================================
// __unwind$500511
// EA  : 0x82A6F260
// RVA : 0x00A6F260
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_500511()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 112));
}


// ========================================================================
// __unwind$500512
// EA  : 0x82A6F288
// RVA : 0x00A6F288
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_500512()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 144));
}


// ========================================================================
// ?PrintMoveDebugInfo@idAnimFSM_AAS@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A6F2B8
// RVA : 0x00A6F2B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::PrintMoveDebugInfo(idAnimFSM_AAS *this, idGuiListBox *info)
{
  idPhysics *Physics; // r3
  const char *v5; // r30
  idGuiListBox *v6; // r3
  __int64 v7; // r8
  __int64 v8; // r10
  __int64 v9; // r6
  idGuiListBox *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idPhysics *v14; // r3
  double v15; // fp31
  idGuiListBox *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  idGuiListBox *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r6
  __int64 v23; // r8
  idPhysics *v24; // r3
  const char *v25; // r30
  idGuiListBox *v26; // r3
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  int num; // r30
  idGuiListBox *v35; // r3
  __int64 v36; // r6
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r8
  __int64 v40; // r6
  int v41; // r29
  int v42; // r27
  idNpCornerInfo *list; // r11
  idNpCornerInfo *v44; // r30
  __int64 v45; // r10
  char *data; // r19
  va *v47; // r18
  const char *v48; // r30
  idGuiListBox *v49; // r3
  __int64 v50; // r10
  __int64 v51; // r8
  __int64 v52; // r6
  idGuiListBox *v53; // r3
  __int64 v54; // r10
  __int64 v55; // r8
  int v56; // [sp+8h] [-1118h]
  int v57; // [sp+Ch] [-1114h]
  int v58; // [sp+10h] [-1110h]
  int v59; // [sp+14h] [-110Ch]
  int v60; // [sp+18h] [-1108h]
  int v61; // [sp+1Ch] [-1104h]
  float v62[4]; // [sp+50h] [-10D0h] BYREF
  idStr v63; // [sp+60h] [-10C0h] BYREF
  idAngles v64; // [sp+80h] [-10A0h] BYREF
  idAngles v65; // [sp+90h] [-1090h] BYREF
  va v66; // [sp+A0h] [-1080h] BYREF

  Physics = idEntity::GetPhysics(this: this->ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v65, result: (idVec3 *)Physics, a3: 0);
  v5 = idVec3::ToString(this: &v65, precision: 2);
  v6 = idGuiListBox::Row(this: info);
  LODWORD(v7) = "1 - formation cover, such as behind regime shield units";
  v10 = idGuiListBox::Printf(this: v6, fmt: "Vel: ", a3: v9, a4: v7, a5: v8);
  idGuiListBox::Printf(this: v10, fmt: v5, a3: v13, a4: v12, a5: v11);
  v14 = idEntity::GetPhysics(this: this->ai);
  v14->GetLinearVelocity(this: (idPhysics *)v62, result: (idVec3 *)v14, a3: 0);
  v15 = __fsqrts((float)((float)(v62[0] * v62[0]) + (float)((float)(v62[1] * v62[1]) + (float)(v62[2] * v62[2]))));
  v16 = idGuiListBox::Row(this: info);
  LODWORD(v17) = "1 - formation cover, such as behind regime shield units";
  v20 = idGuiListBox::Printf(this: v16, fmt: "Speed: ", a3: v19, a4: v18, a5: v17);
  HIDWORD(v21) = "ound traces";
  HIDWORD(v22) = LODWORD(v15);
  idGuiListBox::Printf(this: v20, fmt: (const char *)HIDWORD(v15), a3: v22, a4: v23, a5: v21, v15);
  v24 = idEntity::GetPhysics(this: this->ai);
  v24->GetAngularVelocity(this: (idPhysics *)&v64, result: (idVec3 *)v24, a3: 0);
  v25 = idVec3::ToString(this: &v64, precision: 2);
  v26 = idGuiListBox::Row(this: info);
  HIDWORD(v27) = "1 - formation cover, such as behind regime shield units";
  v30 = idGuiListBox::Printf(this: v26, fmt: "Rot Vel: ", a3: v27, a4: v29, a5: v28);
  idGuiListBox::Printf(this: v30, fmt: v25, a3: v33, a4: v32, a5: v31);
  num = this->cachedCorners.num;
  v35 = idGuiListBox::Row(this: info);
  HIDWORD(v36) = num;
  idGuiListBox::Printf(this: v35, fmt: "Cached Corners: %d", a3: v36, a4: v38, a5: v37);
  v41 = 0;
  if ( this->cachedCorners.num > 0 )
  {
    v42 = 0;
    do
    {
      list = this->cachedCorners.list;
      v63.allocedAndFlag = 20;
      v63.data = v63.baseBuffer;
      v44 = &list[v42];
      v63.len = 0;
      v63.baseBuffer[0] = 0;
      HIDWORD(v45) = *((unsigned __int8 *)&list[v42] + 56);
      LODWORD(v39) = BYTE3(v45) & 0x40;
      if ( (v45 & 0x4000000000LL) != 0 )
        idStr::Append(this: &v63, text: "stop");
      LODWORD(v45) = *((_BYTE *)v44 + 56) & 0x80;
      if ( (*((_BYTE *)v44 + 56) & 0x80) != 0 )
        idStr::Append(this: &v63, text: "goal");
      data = v63.data;
      HIDWORD(v40) = v41;
      v47 = va::va(
              this: &v66,
              fmt: "%d) Pos: ",
              a3: v40,
              a4: v39,
              a5: v45,
              a6: v56,
              a7: v57,
              a8: v58,
              a9: v59,
              a10: v60,
              a11: v61);
      v48 = idVec3::ToString(this: (idAngles *)&v44->position, precision: 0);
      v49 = idGuiListBox::Row(this: info);
      v53 = idGuiListBox::Printf(this: v49, fmt: v47->buffer, a3: v52, a4: v51, a5: v50);
      idGuiListBox::Printf(
        this: v53,
        fmt: "(%s) %s",
        a3: __SPAIR64__((unsigned int)v48, (unsigned int)data),
        a4: v55,
        a5: v54);
      idStr::FreeData(this: &v63);
      ++v41;
      ++v42;
    }
    while ( v41 < this->cachedCorners.num );
  }
}


// ========================================================================
// __unwind$500971
// EA  : 0x82A6F50C
// RVA : 0x00A6F50C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_500971()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 96));
}


// ========================================================================
// ?DeleteMoveAutoObstacle@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A6F680
// RVA : 0x00A6F680
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::DeleteMoveAutoObstacle(idAnimBaseFSM *this)
{
  int value; // r10
  idInfoNavObstacle *v3; // r3
  int v4; // r9
  idInfoNavObstacle *v5; // r3
  idInfoNavObstacle *v6; // r3

  value = this->obstacleMove.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idInfoNavObstacle *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idInfoNavObstacle::CastTo(c: v3) != nullptr )
    {
      v4 = this->obstacleMove.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
        && (v5 = (idInfoNavObstacle *)gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
      {
        v6 = idInfoNavObstacle::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v6->Remove(this: v6);
      this->obstacleMove.spawnId.value = 0x1FFF;
    }
  }
}


// ========================================================================
// ?TeleportToSpace@idAnimFSM_NP@@UAAXABVidNavigationSpace@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82A6F758
// RVA : 0x00A6F758
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::TeleportToSpace(
        idAnimFSM_NP *this,
        const idNavigationSpace *space,
        const idVec3 *origin,
        const idMat3 *axis)
{
  idNpNavigator *groundNavigator; // r30

  groundNavigator = this->groundNavigator;
  if ( groundNavigator != nullptr )
  {
    idNpNavigator::~idNpNavigator(this: this->groundNavigator);
    idMem::Free(this: &mem, ptr: groundNavigator, align: ALIGN_16);
  }
  this->groundNavigator = nullptr;
  idNavigationSpace::SetActiveSpace(this: space);
  idAnimFSM_NP::CreateNavigator(this);
}


// ========================================================================
// ?TreeUsesFullBodyAiming@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A6F7C0
// RVA : 0x00A6F7C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::TreeUsesFullBodyAiming(idAnimBaseFSM *this)
{
  int v2; // r30
  encounterGroupRole_t v4[4]; // [sp+50h] [-40h] BYREF
  idList<enum encounterGroupRole_t,5> v5; // [sp+60h] [-30h] BYREF
  int v6; // [sp+70h] [-20h] BYREF

  v5.granularity = 1;
  v5.size = 2;
  v5.num = 0;
  v5.list = (encounterGroupRole_t *)&v6;
  v5.memTag = 5;
  v5.listStatic = 1;
  v4[0] = this->animBlendVars.bodyAimPitch.index;
  idList<idAnimWebBlendTree *,5>::Append(this: &v5, obj: v4);
  v4[0] = this->animBlendVars.bodyAimYaw.index;
  idList<idAnimWebBlendTree *,5>::Append(this: &v5, obj: v4);
  v2 = idAnimator_AnimWeb::UsesAnyScalarIndices(
         this: (idAnimator_AnimWeb *)&this->ai->aiVolatile.animation,
         testScalars: (const idList<int,5> *)&v5);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v5);
  return v2;
}


// ========================================================================
// __unwind$501721
// EA  : 0x82A6F874
// RVA : 0x00A6F874
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501721()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 96));
}


// ========================================================================
// ?TreeUsesBlendVar@idAnimBaseFSM@@QBA_NH@Z
// EA  : 0x82A6F8A8
// RVA : 0x00A6F8A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::TreeUsesBlendVar(
        idAnimBaseFSM *this,
        int blendVarIndex,
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
        int a14)
{
  int v15; // r30
  idList<enum encounterGroupRole_t,5> v17; // [sp+50h] [-30h] BYREF
  int v18; // [sp+60h] [-20h] BYREF

  a14 = blendVarIndex;
  v17.size = 1;
  v17.num = 0;
  v17.granularity = 1;
  v17.list = (encounterGroupRole_t *)&v18;
  v17.memTag = 5;
  v17.listStatic = 1;
  idList<idAnimWebBlendTree *,5>::Append(this: &v17, obj: (const encounterGroupRole_t *)&a14);
  v15 = idAnimator_AnimWeb::UsesAnyScalarIndices(
          this: (idAnimator_AnimWeb *)&this->ai->aiVolatile.animation,
          testScalars: (const idList<int,5> *)&v17);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v17);
  return v15;
}


// ========================================================================
// __unwind$501774
// EA  : 0x82A6F938
// RVA : 0x00A6F938
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501774()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 128 + 80));
}


// ========================================================================
// ?FillListWithCachedCorners@idAnimBaseFSM@@QBAXAAV?$idStaticList@VidVec3@@$0BP@@@_N1@Z
// EA  : 0x82A6F960
// RVA : 0x00A6F960
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::FillListWithCachedCorners(
        idAnimBaseFSM *this,
        idStaticList<idVec3,31> *otherList,
        bool stopAtLink,
        bool stopAtArrive)
{
  int v7; // r27
  BOOL v8; // r25
  int v9; // r29
  idNpCornerInfo *v10; // r30
  int granularity; // r4
  int size; // r11
  bool v13; // cr58
  signed int v14; // r10
  int v15; // r4
  int v16; // r11
  int num; // r11
  idVec3 *v18; // r11

  v7 = 0;
  if ( this->cachedCorners.num > 0 )
  {
    v8 = stopAtLink;
    v9 = 0;
    do
    {
      v10 = &this->cachedCorners.list[v9];
      if ( otherList->list == nullptr )
      {
        granularity = otherList->granularity;
        if ( granularity <= 0 )
          granularity = 1;
        if ( (unsigned __int8)idList<idVec3,59>::Resize(this: otherList, newsize: granularity) == 0 )
          goto LABEL_21;
      }
      size = otherList->size;
      if ( otherList->num != size )
        goto LABEL_18;
      if ( forceIdListsToReallocateEveryAppend )
      {
        v13 = (unsigned __int8)idList<idVec3,59>::Resize(this: otherList, newsize: size + 1) == 0;
      }
      else
      {
        v14 = otherList->granularity;
        if ( otherList->granularity != 0 )
        {
          v16 = size + v14;
          __twllei(v14, 0);
          __twlgei(v14 & ~(__ROL4__(v16, 1) - 1), 0xFFFFFFFF);
          v13 = (unsigned __int8)idList<idVec3,59>::Resize(this: otherList, newsize: v16 - v16 % v14) == 0;
        }
        else
        {
          v15 = 2 * size;
          if ( 2 * size >= size )
          {
            if ( v15 == 0 )
              v15 = 1;
            v13 = (unsigned __int8)idList<idVec3,59>::Resize(this: otherList, newsize: v15) == 0;
          }
          else
          {
            v13 = (unsigned __int8)idList<idVec3,59>::Resize(this: otherList, newsize: 0x7FFFFFFF) == 0;
          }
        }
      }
      if ( !v13 )
      {
LABEL_18:
        num = otherList->num;
        if ( num < otherList->size )
        {
          v18 = &otherList->list[num];
          v18->x = v10->position.x;
          v18->y = v10->position.y;
          v18->z = v10->position.z;
          ++otherList->num;
        }
      }
LABEL_21:
      if ( v8 && this->cachedCorners.list[v9].cornerType == CORNER_LINKSTART )
        break;
      if ( stopAtArrive && (*((_BYTE *)&this->cachedCorners.list[v9] + 56) & 0x40) != 0 )
        break;
      ++v7;
      ++v9;
    }
    while ( v7 < this->cachedCorners.num );
  }
}


// ========================================================================
// ??1idAnimBaseFSM@@UAA@XZ
// EA  : 0x82A6FEE0
// RVA : 0x00A6FEE0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::~idAnimBaseFSM(idAnimBaseFSM *this)
{
  this->idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimBaseFSM_vtbl *)&idAnimBaseFSM::`vftable'{for `idAIFSMLite'};
  this->idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimBaseFSM::`vftable'{for `idAIMoveInterface'};
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->moveFailures);
  idAnimWebCmdWaitHandle::~idAnimWebCmdWaitHandle(this: &this->animWaitHandle);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->turnTransitionCache.transitions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->departureTransitionCache.transitions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->arrivalTransitionCache.transitions);
  idStaticList<idNpCornerInfo,31>::~idStaticList<idNpCornerInfo,31>(this: &this->cachedCorners);
  idAIMoveCmd::~idAIMoveCmd(this: &this->currentMove);
  idAIMoveCmd::~idAIMoveCmd(this: &this->intermediateMove);
  this->idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimBaseFSM_vtbl *)&idAIFSMLite::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$501996
// EA  : 0x82A6FF90
// RVA : 0x00A6FF90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501996()
{
  int v0; // r12

  idAIFSMLite::~idAIFSMLite(this: *(idAIFSMLite **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501997
// EA  : 0x82A6FFB8
// RVA : 0x00A6FFB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501997()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(*(_DWORD *)(v0 - 112 + 132) + 584));
}


// ========================================================================
// __unwind$501998
// EA  : 0x82A6FFE4
// RVA : 0x00A6FFE4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501998()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(*(_DWORD *)(v0 - 112 + 132) + 740));
}


// ========================================================================
// __unwind$501999
// EA  : 0x82A70010
// RVA : 0x00A70010
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_501999()
{
  int v0; // r12

  idStaticList<idNpCornerInfo,31>::~idStaticList<idNpCornerInfo,31>(this: (idStaticList<idNpCornerInfo,31> *)(*(_DWORD *)(v0 - 112 + 132) + 952));
}


// ========================================================================
// __unwind$502000
// EA  : 0x82A7003C
// RVA : 0x00A7003C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_502000()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 112 + 132) + 3004));
}


// ========================================================================
// __unwind$502001
// EA  : 0x82A70068
// RVA : 0x00A70068
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_502001()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 112 + 132) + 3080));
}


// ========================================================================
// __unwind$502002
// EA  : 0x82A70094
// RVA : 0x00A70094
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_502002()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 112 + 132) + 3156));
}


// ========================================================================
// __unwind$502003
// EA  : 0x82A700C0
// RVA : 0x00A700C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_502003()
{
  int v0; // r12

  idAnimWebCmdWaitHandle::~idAnimWebCmdWaitHandle(this: (idAnimWebCmdWaitHandle *)(*(_DWORD *)(v0 - 112 + 132) + 3488));
}


// ========================================================================
// ?ClearCachedCorners@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A700F0
// RVA : 0x00A700F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::ClearCachedCorners(idAnimBaseFSM *this)
{
  idStaticList<idNpCornerInfo,31> *p_cachedCorners; // r31

  p_cachedCorners = &this->cachedCorners;
  if ( this->cachedCorners.size < 0 )
    idList<idNpCornerInfo,5>::~idList<idNpCornerInfo,5>(this: &this->cachedCorners);
  p_cachedCorners->num = __CFADD__(-p_cachedCorners->size, p_cachedCorners->size ^ 0x80000000)
                       ? 0
                       : p_cachedCorners->size;
  this->nextArrivalCorner = -1;
  this->nextLinkCorner = -1;
}


// ========================================================================
// ?CheckForStationaryTurnTransition@idAnimBaseFSM@@QAA?AW4transitionCheckReturnValue_t@@ABVidMat3@@AAUtransitionQueryResult_t@idAnimWebTransitions@@@Z
// EA  : 0x82A70170
// RVA : 0x00A70170
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::CheckForStationaryTurnTransition(
        idAnimBaseFSM *this,
        const idMat3 *desiredAxis,
        idAnimWebTransitions::transitionQueryResult_t *transInfo)
{
  idPhysics *Physics; // r3
  double y; // fp10
  double z; // fp9
  double x; // fp8
  double v10; // fp7
  double v11; // fp6
  double v12; // fp5
  double v13; // fp4
  double v14; // fp3
  double v15; // fp2
  double v16; // fp1
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  double v20; // fp0
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  char v24; // r11
  idAI2 *ai; // r3
  bool v26; // r11
  bool v27; // zf
  char CommonArrivalTransition; // r29
  idAnimWebTransitions::transitionQueryValidation_t v30; // [sp+70h] [-290h] BYREF
  idAnimWebTransitions::transitionQueryParms_t v31; // [sp+B0h] [-250h] BYREF
  idVec3 v32; // 0:^58.12

  Physics = idEntity::GetPhysics(this: this->ai);
  v32 = *Physics->GetOrigin(this: Physics, a2: 0);
  v30 = idAnimWebTransitions::defaultStepTransitionValidation;
  idAnimBaseFSM::UpdateArrivalTransitionCache(this, nodeCheckFlags: 4, transitionSubweb: "steptransitions");
  this->bestTransitionInfo.selectionIndex = -1;
  idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v31);
  y = desiredAxis->mat[0].y;
  z = desiredAxis->mat[0].z;
  x = desiredAxis->mat[1].x;
  v10 = desiredAxis->mat[1].y;
  v11 = desiredAxis->mat[1].z;
  v12 = desiredAxis->mat[2].x;
  v13 = desiredAxis->mat[2].y;
  v14 = desiredAxis->mat[2].z;
  v15 = this->orientBody.axis.mat[0].x;
  v16 = this->orientBody.axis.mat[0].y;
  v17 = this->orientBody.axis.mat[0].z;
  v18 = this->orientBody.axis.mat[1].x;
  v19 = this->orientBody.axis.mat[1].y;
  v31.destinationAxis.mat[0].x = desiredAxis->mat[0].x;
  v31.destinationAxis.mat[0].y = y;
  v31.destinationOrigin.x = v32.x;
  v31.destinationAxis.mat[0].z = z;
  v31.destinationOrigin.y = v32.y;
  v31.destinationAxis.mat[1].x = x;
  v31.destinationOrigin.z = v32.z;
  v31.destinationAxis.mat[1].y = v10;
  v31.destinationAxis.mat[1].z = v11;
  v31.sourceOrigin1 = v32;
  v31.destinationAxis.mat[2].x = v12;
  v31.destinationAxis.mat[2].y = v13;
  v31.destinationAxis.mat[2].z = v14;
  v31.sourceAxis.mat[0].x = v15;
  v31.sourceAxis.mat[0].y = v16;
  v31.sourceAxis.mat[0].z = v17;
  v20 = this->orientBody.axis.mat[1].z;
  v21 = this->orientBody.axis.mat[2].x;
  v22 = this->orientBody.axis.mat[2].y;
  v23 = this->orientBody.axis.mat[2].z;
  v31.sourceAxis.mat[1].x = v18;
  v31.sourceAxis.mat[1].y = v19;
  v31.sourceAxis.mat[1].z = v20;
  v31.sourceAxis.mat[2].x = v21;
  v31.sourceAxis.mat[2].y = v22;
  v31.sourceAxis.mat[2].z = v23;
  if ( ai_enableScrambles.valueInteger == 0
    || (v24 = 1, this->ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
  {
    v24 = 0;
  }
  ai = this->ai;
  v27 = v24 == 0;
  v26 = (ai->aiVolatile.groupStatus.condition & 8) != 0;
  if ( !v27 )
  {
    v30.suggestedFlags |= 0x4000u;
    v30.allowedFlags |= 0x4000u;
  }
  if ( v26 )
  {
    v30.allowedFlags |= 0x2000u;
    v30.requiredFlags |= 0x2000u;
  }
  v30.navProbeAnimApex = false;
  v30.navProbeAnimTranslation = false;
  v30.navProbeToPathPosition = false;
  if ( (unsigned __int8)idAnimWebTransitions::PrepareArrivalTraces(
                          ai,
                          validation: &v30,
                          cache: &this->arrivalTransitionCache,
                          parms: &v31) != 0 )
  {
    CommonArrivalTransition = idAnimWebTransitions::FindCommonArrivalTransition(
                                ai: this->ai,
                                validation: &v30,
                                cache: &this->arrivalTransitionCache,
                                parms: &v31,
                                out: transInfo);
    if ( transInfo->selectionIndex > -1 )
      idAnimWebTransitions::transitionQueryResult_t::operator=(this: &this->bestTransitionInfo, __that: transInfo);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31.cachedCorners);
    return CommonArrivalTransition == 0 ? 0 : 2;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v31.cachedCorners);
    return 1;
  }
}


// ========================================================================
// __unwind$502341
// EA  : 0x82A70420
// RVA : 0x00A70420
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_502341()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 768 + 176));
}


// ========================================================================
// ?CreateMoveAutoObstacle@idAnimBaseFSM@@QAAXABVidVec3@@@Z
// EA  : 0x82A70448
// RVA : 0x00A70448
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::CreateMoveAutoObstacle(idAnimBaseFSM *this, const idVec3 *pos)
{
  const idAINavPowerMoverParms *v4; // r3
  const idNpObstacleData *p_goalObstacleParms; // r28
  idPhysics *Physics; // r3
  float *v7; // r3
  idAI2 *ai; // r3
  double v9; // fp11
  double v10; // fp8
  double v11; // fp6
  idPhysics *v12; // r3
  idMat3 *v13; // r31
  double x; // fp31
  double y; // fp30
  double v16; // fp29
  idInfoNavObstacle *Instance; // r3
  idInfoNavObstacle *v18; // r3
  idEntityPtr<idInfoNavObstacle> *p_obstacleMove; // r30
  idInfoNavObstacle *v20; // r3
  idInfoNavObstacle *v21; // r3
  idInfoNavObstacle *v22; // r3
  idGameLocal_vtbl *v23; // r31
  idInfoNavObstacle *v24; // r3
  idVec3 v25; // [sp+50h] [-50h] BYREF

  idAnimBaseFSM::DeleteMoveAutoObstacle(this);
  v4 = this->ai->GetNavParms(this: this->ai);
  if ( v4 != nullptr && v4->arrival.createGoalObstacle )
  {
    p_goalObstacleParms = &v4->arrival.goalObstacleParms;
    Physics = idEntity::GetPhysics(this: this->ai);
    v7 = (float *)Physics->GetBounds(this: Physics, a2: -1);
    v9 = (float)(v7[5] - v7[2]);
    v10 = (float)(v7[4] - v7[1]);
    v11 = (float)(v7[3] - *v7);
    ai = this->ai;
    v25.y = v10;
    v25.x = v11;
    v25.z = v9;
    v12 = idEntity::GetPhysics(this: ai);
    v13 = (idMat3 *)v12->GetAxis(this: v12, a2: 0);
    x = pos->x;
    y = pos->y;
    v16 = (float)(pos->z + (float)(v25.z * (float)0.5));
    Instance = idInfoNavObstacle::CreateInstance();
    v18 = idInfoNavObstacle::CastTo(c: Instance);
    p_obstacleMove = &this->obstacleMove;
    if ( v18 != nullptr )
      p_obstacleMove->spawnId.value = (gameLocal->spawnIds.ptr[v18->entityNumber] << 13) | v18->entityNumber;
    else
      p_obstacleMove->spawnId.value = 0x1FFF;
    if ( gameLocal->spawnIds.ptr[p_obstacleMove->spawnId.value & 0x1FFF] == p_obstacleMove->spawnId.value >> 13 )
    {
      v20 = (idInfoNavObstacle *)gameLocal->entities.ptr[p_obstacleMove->spawnId.value & 0x1FFF];
      if ( v20 != nullptr && idInfoNavObstacle::CastTo(c: v20) != nullptr )
      {
        v21 = idEntityPtr<idInfoNavObstacle>::operator->(this: p_obstacleMove);
        v21->spawnPosition.x = x;
        v21->spawnPosition.y = y;
        v21->spawnPosition.z = v16;
        idEntityPtr<idInfoNavObstacle>::operator->(this: p_obstacleMove)->spawnOrientation = *v13;
        v22 = idEntityPtr<idInfoNavObstacle>::operator->(this: p_obstacleMove);
        idInfoNavObstacle::Init(this: v22, parms: p_goalObstacleParms, size: &v25, lifeTime: 9999.0);
        v23 = gameLocal->__vftable;
        v24 = idEntityPtr<idInfoNavObstacle>::operator->(this: p_obstacleMove);
        v23->SpawnEntity(this: gameLocal, a2: v24, a3: -1, a4: -1, a5: -1);
      }
    }
  }
}


// ========================================================================
// ?AnimCheckNextNode@idAnimFSM@@UAA?AW4awCheckPathResult_t@@AAVidAnimWebAI@@PBVidDeclAnimWebNode@@1@Z
// EA  : 0x82A70688
// RVA : 0x00A70688
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM::AnimCheckNextNode(
        idAnimFSM *this,
        idAnimWebAI *animWeb,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode)
{
  unsigned __int8 flags; // r28
  double value; // fp31
  __int64 v10; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idDeclMD6 *decl; // r27
  const idMD6Anim *Anim; // r3
  idMD6AnimData *animData; // r11
  const idMD6Anim *v15; // r29
  int numFrames; // r6
  idAI2 *ai; // r24
  double v18; // fp31
  __int64 v19; // r11
  idTreeAnimator *v20; // r3
  idDeclMD6 *v21; // r27
  const idMD6Anim *v22; // r3
  idMD6AnimData *v23; // r11
  int v24; // r29
  int v25; // r6
  idAI2 *v26; // r24
  double v27; // fp31
  __int64 v28; // r11
  idTreeAnimator *v29; // r3
  idDeclMD6 *v30; // r27
  const idMD6Anim *v31; // r3
  idMD6AnimData *v32; // r11
  int v33; // r29
  int v34; // r6
  idAI2 *v35; // r24
  idTreeAnimator *v36; // r3
  int v37; // r10
  char CommonArrivalTransition; // r22
  bool v39; // r11
  char v40; // r11
  idAI2 *v41; // r3
  bool v42; // r11
  bool v43; // zf
  __int64 v44; // r9
  double v45; // fp0
  idAIStateLite *currentState; // r3
  const char *name; // r29
  const char *Classname; // r3
  idTreeAnimator *v49; // r3
  idDeclMD6 *v50; // r27
  const idMD6Anim *v51; // r3
  idMD6AnimData *v52; // r11
  int v53; // r29
  int v54; // r6
  idAI2 *v55; // r24
  idList<idVehicleState *,5> *p_cachedCorners; // r3
  bool v57; // r11
  double v58; // fp31
  char v59; // r11
  idAI2 *v60; // r3
  bool v61; // r11
  __int64 v62; // r9
  idAIStateLite *v63; // r3
  const char *v64; // r29
  const char *v65; // r3
  idTreeAnimator *v66; // r3
  idDeclMD6 *v67; // r27
  const idMD6Anim *v68; // r3
  idMD6AnimData *v69; // r11
  int v70; // r29
  int v71; // r6
  idAI2 *v72; // r24
  char v73; // r11
  idAI2 *v74; // r3
  bool v75; // r11
  __int64 v76; // r9
  double v77; // fp0
  idAIStateLite *v78; // r3
  const char *v79; // r29
  const char *v80; // r3
  idTreeAnimator *v81; // r3
  idDeclMD6 *v82; // r27
  const idMD6Anim *v83; // r3
  int v84; // r29
  idMD6AnimData *v85; // r11
  int v86; // r6
  idAI2 *v87; // r24
  _BYTE v88[20]; // [sp+70h] [-AC0h] BYREF
  _BYTE v89[20]; // [sp+90h] [-AA0h] BYREF
  __int64 v90; // [sp+B0h] [-A80h]
  bool v91; // [sp+B8h] [-A78h] BYREF
  float v92; // [sp+C0h] [-A70h] BYREF
  float v93; // [sp+C4h] [-A6Ch]
  float v94; // [sp+C8h] [-A68h]
  idEventReceiver v95[2]; // [sp+D0h] [-A60h] BYREF
  idMat3 v96; // [sp+F0h] [-A40h] BYREF
  int v97[5]; // [sp+120h] [-A10h] BYREF
  const idEventArg *v98[5]; // [sp+140h] [-9F0h] BYREF
  const idEventArg *v99[5]; // [sp+160h] [-9D0h] BYREF
  idAnimWebTransitions::transitionQueryValidation_t v100; // [sp+180h] [-9B0h] BYREF
  idVec3 v101; // [sp+1B8h] [-978h] BYREF
  idStr v102; // [sp+1D0h] [-960h] BYREF
  idAnimWebState v103; // [sp+1F0h] [-940h] BYREF
  idStr v104; // [sp+210h] [-920h] BYREF
  idStr v105; // [sp+230h] [-900h] BYREF
  idStr v106; // [sp+250h] [-8E0h] BYREF
  idList<idVehicleState *,5> v107; // [sp+270h] [-8C0h] BYREF
  int v108; // [sp+280h] [-8B0h] BYREF
  idList<idVehicleState *,5> v109; // [sp+2C0h] [-870h] BYREF
  int v110; // [sp+2D0h] [-860h] BYREF
  idList<idVehicleState *,5> v111; // [sp+310h] [-820h] BYREF
  int v112; // [sp+320h] [-810h] BYREF
  idList<idVehicleState *,5> v113; // [sp+360h] [-7D0h] BYREF
  int v114; // [sp+370h] [-7C0h] BYREF
  idList<idVehicleState *,5> v115; // [sp+3B0h] [-780h] BYREF
  int v116; // [sp+3C0h] [-770h] BYREF
  idList<idVehicleState *,5> v117; // [sp+400h] [-730h] BYREF
  int v118; // [sp+410h] [-720h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v119; // [sp+450h] [-6E0h] BYREF
  idAnimWebTransitions::transitionQueryParms_t v120; // [sp+4A0h] [-690h] BYREF
  idAnimWebTransitions::transitionQueryParms_t v121; // [sp+6B0h] [-480h] BYREF
  idAnimWebTransitions::transitionQueryParms_t v122; // [sp+8C0h] [-270h] BYREF

  flags = nextNode->flags;
  if ( (flags & 0xF) == 0 )
    return 0;
  if ( (nextNode->flags & 0xF) == (curNode->flags & 0xF) )
    return 2;
  idAnimWebState::idAnimWebState(
    this: &v103,
    decl: animWeb->decl,
    _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)nextNode->nodeIndex.value);
  if ( (flags & 4) != 0 )
  {
    if ( this->animBlendVars.animStepSelect.used )
    {
      value = this->animBlendVars.animStepSelect.value;
      LODWORD(v10) = idDeclAnimWebNode::NumAnims(this: nextNode, modelIndex: nullptr);
      v90 = v10;
      if ( value >= (float)v10 )
      {
        v104.len = 0;
        v104.baseBuffer[0] = 0;
        v104.allocedAndFlag = 20;
        v104.data = v104.baseBuffer;
        idDeclAnimWebNode::GetName(this: nextNode, web: animWeb->decl, name: &v104);
        LODWORD(v90) = (int)this->animBlendVars.animStepSelect.value;
        idLib::Warning(fmt: "animStepSelect %i is out of range for %s, setting to 0 ", (_DWORD)v90, v104.data);
        this->animBlendVars.animStepSelect.value = 0.0;
        idStr::FreeData(this: &v104);
      }
      v111.num = 0;
      v111.granularity = 1;
      v111.size = 16;
      v111.list = (idVehicleState **)&v112;
      v111.memTag = 5;
      v111.listStatic = 1;
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
      LODWORD(v90) = (int)this->animBlendVars.animStepSelect.value;
      decl = TreeAnimatorFromPresentable->decl;
      Anim = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
      animData = Anim->animData;
      v15 = Anim;
      numFrames = 0;
      if ( animData != nullptr )
        numFrames = animData->numFrames;
      idDeclMD6::FindAnimEvents(
        this: decl,
        anim: Anim,
        startFrame: 0,
        endFrame: numFrames,
        eventNum: AE_AnimDeltaCorrection.eventnum,
        events: &v111);
      if ( v111.num == 0 )
      {
        idLib::Warning(fmt: "%s, STEP_TRANSITION without delta correction events, this should be fixed", v15->name.str);
        v97[1] = 0;
        HIBYTE(v97[0]) = 105;
        v95[0].listenerList = (idList<idEventReceiver *,5> *)v15;
        v98[1] = (const idEventArg *)1;
        HIBYTE(v99[0]) = 105;
        v99[1] = (const idEventArg *)3;
        HIBYTE(v98[0]) = 105;
        HIBYTE(v95[0].__vftable) = 52;
        ai = this->ai;
        memcpy(Dst: v89, Src: v97, Size: sizeof(v89));
        memcpy(Dst: v88, Src: v99, Size: sizeof(v88));
        idEventReceiver::PostEventMS(
          this: ai,
          ev: &AE_AnimDeltaCorrection,
          time: (int)v95[0].__vftable,
          arg1: (const idEventArg *)v95[0].listeningToList,
          arg2: (const idEventArg *)v95[1].__vftable,
          arg3: (const idEventArg *)__ROL4__(v95[1].listenerList, 32),
          arg4: v98[2]);
      }
      this->animBlendVars.animStepSelect.used = false;
      idList<idThread *,58>::Clear(this: &v111);
      return 0;
    }
LABEL_32:
    this->ai->GetModelTransform(this: this->ai, a2: (idVec3 *)&v92, a3: &v96);
    v36 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
    idTreeAnimator::GetLastOriginDeltas(this: v36, trans: &v101);
    v92 = (float)((float)(v96.mat[2].x * v101.z)
                + (float)((float)(v96.mat[0].x * v101.x) + (float)(v96.mat[1].x * v101.y)))
        + v92;
    v94 = (float)((float)(v101.x * v96.mat[0].z)
                + (float)((float)(v96.mat[1].z * v101.y) + (float)(v96.mat[2].z * v101.z)))
        + v94;
    v93 = (float)((float)(v101.x * v96.mat[0].y)
                + (float)((float)(v96.mat[1].y * v101.y) + (float)(v96.mat[2].y * v101.z)))
        + v93;
    idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v119);
    v37 = this->currentMove.moveFlags & 0x1000;
    CommonArrivalTransition = 0;
    v39 = v37 == 0 && (this->overrideMoveFlags & 0x1000) == 0 && ai_useStepTransitions.valueInteger != 0;
    if ( v39 && (flags & 4) != 0 )
    {
      idAnimWebTransitions::FillTransitionCache(
        ai: this->ai,
        cache: &this->arrivalTransitionCache,
        transitionState: &v103);
      idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v120);
      v120.sourceOrigin1.x = v92;
      v120.sourceOrigin1.y = v93;
      v120.sourceOrigin1.z = v94;
      v120.sourceAxis.mat[0].x = v96.mat[0].x;
      v120.sourceAxis.mat[0].y = v96.mat[0].y;
      v120.sourceAxis.mat[0].z = v96.mat[0].z;
      v120.sourceAxis.mat[1].x = v96.mat[1].x;
      v120.sourceAxis.mat[1].y = v96.mat[1].y;
      v120.sourceAxis.mat[1].z = v96.mat[1].z;
      v120.sourceAxis.mat[2].x = v96.mat[2].x;
      v120.sourceAxis.mat[2].y = v96.mat[2].y;
      v120.sourceAxis.mat[2].z = v96.mat[2].z;
      v120.destinationOrigin.x = v92;
      v120.destinationOrigin.y = v93;
      v120.destinationOrigin.z = v94;
      v120.destinationAxis = v96;
      v120.totalPathDistance = idAnimBaseFSM::GetRemainingPathDistance(this);
      idAnimBaseFSM::FillListWithCachedCorners(
        this,
        otherList: &v120.cachedCorners,
        stopAtLink: true,
        stopAtArrive: true);
      v100 = idAnimWebTransitions::defaultStepTransitionValidation;
      if ( ai_enableScrambles.valueInteger == 0
        || (v40 = 1,
            this->ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
      {
        v40 = 0;
      }
      v41 = this->ai;
      HIDWORD(v90) = v41;
      v43 = v40 == 0;
      v42 = (v41->aiVolatile.groupStatus.condition & 8) != 0;
      if ( !v43 )
      {
        v100.suggestedFlags |= 0x4000u;
        v100.allowedFlags |= 0x4000u;
      }
      if ( v42 )
      {
        v100.allowedFlags |= 0x2000u;
        v100.requiredFlags |= 0x2000u;
      }
      HIDWORD(v90) = v41;
      if ( (unsigned __int8)idAnimWebTransitions::PrepareArrivalTraces(
                              ai: v41,
                              validation: &v100,
                              cache: &this->arrivalTransitionCache,
                              parms: &v120) == 0 )
      {
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v120.cachedCorners);
        return 1;
      }
      CommonArrivalTransition = idAnimWebTransitions::FindCommonArrivalTransition(
                                  ai: this->ai,
                                  validation: &v100,
                                  cache: &this->arrivalTransitionCache,
                                  parms: &v120,
                                  out: &v119);
      idAnimWebTransitions::CleanupNavTraces(ai: this->ai, cache: &this->arrivalTransitionCache);
      if ( CommonArrivalTransition != 0 )
      {
        LODWORD(v44) = v119.selectionIndex;
        v90 = v44;
        v45 = (float)v44;
      }
      else
      {
        v45 = 0.0;
      }
      this->animBlendVars.animStepSelect.value = v45;
      if ( CommonArrivalTransition != 0 )
      {
        if ( this->RespondsTo(this, a2: &FSM_StartStepTransition) )
        {
          idEventReceiver::ProcessEvent(this: v95, result: (idEventArg *)this, ev: &FSM_StartStepTransition);
        }
        else
        {
          currentState = this->currentState;
          name = FSM_StartStepTransition.name;
          if ( currentState != nullptr )
          {
            Classname = idClass::GetClassname(this: currentState);
            idLib::Warning(fmt: "State '%s' didn't handle event '%s'", Classname, name);
          }
          else
          {
            idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_StartStepTransition.name);
          }
        }
        v117.num = 0;
        v117.granularity = 1;
        v117.size = 16;
        v117.list = (idVehicleState **)&v118;
        v117.memTag = 5;
        v117.listStatic = 1;
        v49 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
        LODWORD(v90) = (int)this->animBlendVars.animStepSelect.value;
        v50 = v49->decl;
        v51 = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
        v52 = v51->animData;
        v53 = (int)v51;
        v54 = 0;
        if ( v52 != nullptr )
          v54 = v52->numFrames;
        idDeclMD6::FindAnimEvents(
          this: v50,
          anim: v51,
          startFrame: 0,
          endFrame: v54,
          eventNum: AE_AnimDeltaCorrection.eventnum,
          events: &v117);
        if ( v117.num == 0 )
        {
          idLib::Warning(
            fmt: "%s, STEP_TRANSITION without delta correction events, this should be fixed",
            *(const char **)(v53 + 8));
          v95[0].listenerList = nullptr;
          HIBYTE(v95[0].__vftable) = 105;
          v97[1] = v53;
          v99[1] = (const idEventArg *)1;
          HIBYTE(v98[0]) = 105;
          v98[1] = (const idEventArg *)3;
          HIBYTE(v99[0]) = 105;
          HIBYTE(v97[0]) = 52;
          v55 = this->ai;
          memcpy(Dst: v89, Src: v95, Size: sizeof(v89));
          memcpy(Dst: v88, Src: v98, Size: sizeof(v88));
          idEventReceiver::PostEventMS(
            this: v55,
            ev: &AE_AnimDeltaCorrection,
            time: v97[0],
            arg1: (const idEventArg *)v97[2],
            arg2: (const idEventArg *)v97[3],
            arg3: (const idEventArg *)__ROL4__(v97[4], 32),
            arg4: v99[2]);
        }
        this->animBlendVars.animStepSelect.used = false;
        idList<idThread *,58>::Clear(this: &v117);
      }
      p_cachedCorners = (idList<idVehicleState *,5> *)&v120.cachedCorners;
    }
    else
    {
      v57 = v37 == 0 && (this->overrideMoveFlags & 0x1000) == 0 && ai_useStopTransitions.valueInteger != 0;
      if ( v57 && (flags & 2) != 0 )
      {
        if ( this->IsMoveDone(this) )
          return 2;
        v58 = 0.0;
        *(float *)&v90 = 0.0;
        if ( (float)((float)((float)0.0 * (float)0.0)
                   + (float)((float)((float)0.0 * (float)0.0) + (float)((float)0.0 * (float)0.0))) < 2500.0 )
          return 2;
        idAnimWebTransitions::FillTransitionCache(
          ai: this->ai,
          cache: &this->arrivalTransitionCache,
          transitionState: &v103);
        idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v121);
        v121.sourceOrigin1.x = v92;
        v121.sourceOrigin1.y = v93;
        v121.sourceOrigin1.z = v94;
        v121.sourceAxis.mat[0].x = v96.mat[0].x;
        v121.sourceAxis.mat[0].y = v96.mat[0].y;
        v121.sourceAxis.mat[0].z = v96.mat[0].z;
        v121.sourceAxis.mat[1].x = v96.mat[1].x;
        v121.sourceAxis.mat[1].y = v96.mat[1].y;
        v121.sourceAxis.mat[1].z = v96.mat[1].z;
        v121.sourceAxis.mat[2].x = v96.mat[2].x;
        v121.sourceAxis.mat[2].y = v96.mat[2].y;
        v121.sourceAxis.mat[2].z = v96.mat[2].z;
        v121.destinationOrigin.x = v92;
        v121.destinationOrigin.y = v93;
        v121.destinationOrigin.z = v94;
        v121.destinationAxis = v96;
        v121.totalPathDistance = idAnimBaseFSM::GetRemainingPathDistance(this);
        idAnimBaseFSM::FillListWithCachedCorners(
          this,
          otherList: &v121.cachedCorners,
          stopAtLink: true,
          stopAtArrive: true);
        v100 = idAnimWebTransitions::defaultArrivalTransitionValidation;
        if ( ai_enableScrambles.valueInteger == 0
          || (v59 = 1,
              this->ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
        {
          v59 = 0;
        }
        v60 = this->ai;
        HIDWORD(v90) = v60;
        v43 = v59 == 0;
        v61 = (v60->aiVolatile.groupStatus.condition & 8) != 0;
        if ( !v43 )
        {
          v100.suggestedFlags |= 0x4000u;
          v100.allowedFlags |= 0x4000u;
        }
        if ( v61 )
        {
          v100.allowedFlags |= 0x2000u;
          v100.requiredFlags |= 0x2000u;
        }
        HIDWORD(v90) = v60;
        if ( (unsigned __int8)idAnimWebTransitions::PrepareArrivalTraces(
                                ai: v60,
                                validation: &v100,
                                cache: &this->arrivalTransitionCache,
                                parms: &v121) == 0 )
        {
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v121.cachedCorners);
          return 1;
        }
        CommonArrivalTransition = idAnimWebTransitions::FindCommonArrivalTransition(
                                    ai: this->ai,
                                    validation: &v100,
                                    cache: &this->arrivalTransitionCache,
                                    parms: &v121,
                                    out: &v119);
        idAnimWebTransitions::CleanupNavTraces(ai: this->ai, cache: &this->arrivalTransitionCache);
        if ( CommonArrivalTransition != 0 )
        {
          LODWORD(v62) = v119.selectionIndex;
          v90 = v62;
          v58 = (float)v62;
        }
        this->animBlendVars.animArrivalSelect.value = v58;
        if ( CommonArrivalTransition != 0 )
        {
          if ( this->RespondsTo(this, a2: &FSM_StartArrival) )
          {
            idEventReceiver::ProcessEvent(this: v95, result: (idEventArg *)this, ev: &FSM_StartArrival);
          }
          else
          {
            v63 = this->currentState;
            v64 = FSM_StartArrival.name;
            if ( v63 != nullptr )
            {
              v65 = idClass::GetClassname(this: v63);
              idLib::Warning(fmt: "State '%s' didn't handle event '%s'", v65, v64);
            }
            else
            {
              idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_StartArrival.name);
            }
          }
          v109.num = 0;
          v109.granularity = 1;
          v109.size = 16;
          v109.list = (idVehicleState **)&v110;
          v109.memTag = 5;
          v109.listStatic = 1;
          v66 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
          LODWORD(v90) = (int)this->animBlendVars.animArrivalSelect.value;
          v67 = v66->decl;
          v68 = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
          v69 = v68->animData;
          v70 = (int)v68;
          v71 = 0;
          if ( v69 != nullptr )
            v71 = v69->numFrames;
          idDeclMD6::FindAnimEvents(
            this: v67,
            anim: v68,
            startFrame: 0,
            endFrame: v71,
            eventNum: AE_AnimDeltaCorrection.eventnum,
            events: &v109);
          if ( v109.num == 0 )
          {
            idLib::Warning(
              fmt: "%s, STOP_TRANSITION without delta correction events, this should be fixed",
              *(const char **)(v70 + 8));
            v95[0].listenerList = nullptr;
            HIBYTE(v95[0].__vftable) = 105;
            v97[1] = v70;
            v99[1] = (const idEventArg *)1;
            HIBYTE(v98[0]) = 105;
            v98[1] = (const idEventArg *)3;
            HIBYTE(v99[0]) = 105;
            HIBYTE(v97[0]) = 52;
            v72 = this->ai;
            memcpy(Dst: v89, Src: v95, Size: sizeof(v89));
            memcpy(Dst: v88, Src: v98, Size: sizeof(v88));
            idEventReceiver::PostEventMS(
              this: v72,
              ev: &AE_AnimDeltaCorrection,
              time: v97[0],
              arg1: (const idEventArg *)v97[2],
              arg2: (const idEventArg *)v97[3],
              arg3: (const idEventArg *)__ROL4__(v97[4], 32),
              arg4: v99[2]);
          }
          this->animBlendVars.animArrivalSelect.used = false;
          idList<idThread *,58>::Clear(this: &v109);
        }
        p_cachedCorners = (idList<idVehicleState *,5> *)&v121.cachedCorners;
      }
      else
      {
        if ( ai_useStartTransitions.valueInteger == 0 || (flags & 1) == 0 )
          return CommonArrivalTransition != 0 ? 0 : 2;
        if ( this->departureTransitionCache.transitions.num == 0
          || this->departureTransitionCache.nodeIndex.value != v103.node.value )
        {
          idAnimWebTransitions::FillTransitionCache(
            ai: this->ai,
            cache: &this->departureTransitionCache,
            transitionState: &v103);
        }
        v91 = false;
        idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v122);
        v122.sourceOrigin1.x = v92;
        v122.sourceOrigin1.y = v93;
        v122.sourceOrigin1.z = v94;
        v122.sourceAxis.mat[0].x = v96.mat[0].x;
        v122.sourceAxis.mat[0].y = v96.mat[0].y;
        v122.sourceAxis.mat[0].z = v96.mat[0].z;
        v122.sourceAxis.mat[1].x = v96.mat[1].x;
        v122.sourceAxis.mat[1].y = v96.mat[1].y;
        v122.sourceAxis.mat[1].z = v96.mat[1].z;
        v122.sourceAxis.mat[2].x = v96.mat[2].x;
        v122.sourceAxis.mat[2].y = v96.mat[2].y;
        v122.sourceAxis.mat[2].z = v96.mat[2].z;
        v122.totalPathDistance = idAnimBaseFSM::GetRemainingPathDistance(this);
        v122.debugDrawTime = 2000;
        idAnimBaseFSM::FillListWithCachedCorners(
          this,
          otherList: &v122.cachedCorners,
          stopAtLink: true,
          stopAtArrive: true);
        v100 = idAnimWebTransitions::defaultDepartureTransitionValidation;
        if ( ai_enableScrambles.valueInteger == 0
          || (v73 = 1,
              this->ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
        {
          v73 = 0;
        }
        v74 = this->ai;
        HIDWORD(v90) = v74;
        v43 = v73 == 0;
        v75 = (v74->aiVolatile.groupStatus.condition & 8) != 0;
        if ( !v43 )
        {
          v100.suggestedFlags |= 0x4000u;
          v100.allowedFlags |= 0x4000u;
        }
        if ( v75 )
        {
          v100.allowedFlags |= 0x2000u;
          v100.requiredFlags |= 0x2000u;
        }
        HIDWORD(v90) = v74;
        if ( (unsigned __int8)idAnimWebTransitions::PrepareDepartureTraces(
                                ai: v74,
                                validation: &v100,
                                cache: &this->departureTransitionCache,
                                parms: &v122) == 0 )
        {
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v122.cachedCorners);
          return 1;
        }
        CommonArrivalTransition = idAnimWebTransitions::FindDepartureTransition(
                                    ai: this->ai,
                                    validation: &v100,
                                    cache: &this->departureTransitionCache,
                                    parms: &v122,
                                    out: &v119,
                                    wasRejectedBasedOnDistanceAlone: &v91);
        idAnimWebTransitions::CleanupNavTraces(ai: this->ai, cache: &this->departureTransitionCache);
        if ( CommonArrivalTransition != 0 )
        {
          LODWORD(v76) = v119.selectionIndex;
          v90 = v76;
          v77 = (float)v76;
        }
        else
        {
          v77 = 0.0;
        }
        this->animBlendVars.animDepartureSelect.value = v77;
        if ( CommonArrivalTransition != 0 )
        {
          if ( this->RespondsTo(this, a2: &FSM_StartDeparture) )
          {
            idEventReceiver::ProcessEvent(this: v95, result: (idEventArg *)this, ev: &FSM_StartDeparture);
          }
          else
          {
            v78 = this->currentState;
            v79 = FSM_StartDeparture.name;
            if ( v78 != nullptr )
            {
              v80 = idClass::GetClassname(this: v78);
              idLib::Warning(fmt: "State '%s' didn't handle event '%s'", v80, v79);
            }
            else
            {
              idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_StartDeparture.name);
            }
          }
          v113.num = 0;
          v113.granularity = 1;
          v113.size = 16;
          v113.list = (idVehicleState **)&v114;
          v113.memTag = 5;
          v113.listStatic = 1;
          v81 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
          LODWORD(v90) = (int)this->animBlendVars.animDepartureSelect.value;
          v82 = v81->decl;
          v83 = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
          v84 = (int)v83;
          if ( v83 != nullptr )
          {
            v85 = v83->animData;
            v86 = 0;
            if ( v85 != nullptr )
              v86 = v85->numFrames;
            idDeclMD6::FindAnimEvents(
              this: v82,
              anim: v83,
              startFrame: 0,
              endFrame: v86,
              eventNum: AE_AnimDeltaCorrection.eventnum,
              events: &v113);
            if ( v113.num == 0 )
            {
              idLib::Warning(
                fmt: "%s, START_TRANSITION without delta correction events, this should be fixed",
                *(const char **)(v84 + 8));
              v95[0].listenerList = nullptr;
              HIBYTE(v95[0].__vftable) = 105;
              v97[1] = v84;
              HIBYTE(v98[0]) = 105;
              v98[1] = (const idEventArg *)11;
              HIBYTE(v99[0]) = 105;
              v99[1] = nullptr;
              HIBYTE(v97[0]) = 52;
              v87 = this->ai;
              memcpy(Dst: v89, Src: v95, Size: sizeof(v89));
              memcpy(Dst: v88, Src: v98, Size: sizeof(v88));
              idEventReceiver::PostEventMS(
                this: v87,
                ev: &AE_AnimDeltaCorrection,
                time: v97[0],
                arg1: (const idEventArg *)v97[2],
                arg2: (const idEventArg *)v97[3],
                arg3: (const idEventArg *)__ROL4__(v97[4], 32),
                arg4: v99[2]);
            }
          }
          else
          {
            v102.len = 0;
            v102.baseBuffer[0] = 0;
            v102.allocedAndFlag = 20;
            v102.data = v102.baseBuffer;
            idDeclAnimWebNode::GetName(this: nextNode, web: animWeb->decl, name: &v102);
            LODWORD(v90) = (int)this->animBlendVars.animDepartureSelect.value;
            idLib::Warning(fmt: "NULL md6anim in model info for node %s index %i", v102.data, (_DWORD)v90);
            idStr::FreeData(this: &v102);
          }
          this->animBlendVars.animDepartureSelect.used = false;
          idList<idThread *,58>::Clear(this: &v113);
        }
        p_cachedCorners = (idList<idVehicleState *,5> *)&v122.cachedCorners;
      }
    }
    idList<idThread *,58>::Clear(this: p_cachedCorners);
    return CommonArrivalTransition != 0 ? 0 : 2;
  }
  if ( (flags & 2) != 0 )
  {
    if ( !this->animBlendVars.animArrivalSelect.used )
      goto LABEL_32;
    v18 = this->animBlendVars.animArrivalSelect.value;
    LODWORD(v19) = idDeclAnimWebNode::NumAnims(this: nextNode, modelIndex: nullptr);
    v90 = v19;
    if ( v18 >= (float)v19 )
    {
      v106.len = 0;
      v106.baseBuffer[0] = 0;
      v106.allocedAndFlag = 20;
      v106.data = v106.baseBuffer;
      idDeclAnimWebNode::GetName(this: nextNode, web: animWeb->decl, name: &v106);
      LODWORD(v90) = (int)this->animBlendVars.animArrivalSelect.value;
      idLib::Warning(fmt: "animArrivalSelct %i is out of range for %s, setting to 0 ", (_DWORD)v90, v106.data);
      this->animBlendVars.animArrivalSelect.value = 0.0;
      idStr::FreeData(this: &v106);
    }
    v107.num = 0;
    v107.granularity = 1;
    v107.size = 16;
    v107.list = (idVehicleState **)&v108;
    v107.memTag = 5;
    v107.listStatic = 1;
    v20 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
    LODWORD(v90) = (int)this->animBlendVars.animArrivalSelect.value;
    v21 = v20->decl;
    v22 = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
    v23 = v22->animData;
    v24 = (int)v22;
    v25 = 0;
    if ( v23 != nullptr )
      v25 = v23->numFrames;
    idDeclMD6::FindAnimEvents(
      this: v21,
      anim: v22,
      startFrame: 0,
      endFrame: v25,
      eventNum: AE_AnimDeltaCorrection.eventnum,
      events: &v107);
    if ( v107.num == 0 )
    {
      idLib::Warning(
        fmt: "%s, STOP_TRANSITION without delta correction events, this should be fixed",
        *(const char **)(v24 + 8));
      v95[0].listenerList = nullptr;
      HIBYTE(v95[0].__vftable) = 105;
      v97[1] = v24;
      v99[1] = (const idEventArg *)1;
      HIBYTE(v98[0]) = 105;
      v98[1] = (const idEventArg *)3;
      HIBYTE(v99[0]) = 105;
      HIBYTE(v97[0]) = 52;
      v26 = this->ai;
      memcpy(Dst: v89, Src: v95, Size: sizeof(v89));
      memcpy(Dst: v88, Src: v98, Size: sizeof(v88));
      idEventReceiver::PostEventMS(
        this: v26,
        ev: &AE_AnimDeltaCorrection,
        time: v97[0],
        arg1: (const idEventArg *)v97[2],
        arg2: (const idEventArg *)v97[3],
        arg3: (const idEventArg *)__ROL4__(v97[4], 32),
        arg4: v99[2]);
    }
    this->animBlendVars.animArrivalSelect.used = false;
    idList<idThread *,58>::Clear(this: &v107);
    return 0;
  }
  else
  {
    if ( (flags & 8) == 0 || !this->animBlendVars.animTurnSelect.used )
      goto LABEL_32;
    v27 = this->animBlendVars.animTurnSelect.value;
    LODWORD(v28) = idDeclAnimWebNode::NumAnims(this: nextNode, modelIndex: nullptr);
    v90 = v28;
    if ( v27 >= (float)v28 )
    {
      v105.len = 0;
      v105.baseBuffer[0] = 0;
      v105.allocedAndFlag = 20;
      v105.data = v105.baseBuffer;
      idDeclAnimWebNode::GetName(this: nextNode, web: animWeb->decl, name: &v105);
      LODWORD(v90) = (int)this->animBlendVars.animTurnSelect.value;
      idLib::Warning(fmt: "animTurnSelect %i is out of range for %s, setting to 0 ", (_DWORD)v90, v105.data);
      this->animBlendVars.animTurnSelect.value = 0.0;
      idStr::FreeData(this: &v105);
    }
    v115.num = 0;
    v115.granularity = 1;
    v115.size = 16;
    v115.list = (idVehicleState **)&v116;
    v115.memTag = 5;
    v115.listStatic = 1;
    v29 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
    LODWORD(v90) = (int)this->animBlendVars.animTurnSelect.value;
    v30 = v29->decl;
    v31 = (const idMD6Anim *)idDeclAnimWebNode::GetAnim(this: nextNode, modelIndex: nullptr, animIndex: v90);
    v32 = v31->animData;
    v33 = (int)v31;
    v34 = 0;
    if ( v32 != nullptr )
      v34 = v32->numFrames;
    idDeclMD6::FindAnimEvents(
      this: v30,
      anim: v31,
      startFrame: 0,
      endFrame: v34,
      eventNum: AE_AnimDeltaCorrection.eventnum,
      events: &v115);
    if ( v115.num == 0 )
    {
      idLib::Warning(
        fmt: "%s, TURN_TRANSITION without delta correction events, this should be fixed",
        *(const char **)(v33 + 8));
      v95[0].listenerList = nullptr;
      HIBYTE(v95[0].__vftable) = 105;
      v97[1] = v33;
      v98[1] = (const idEventArg *)1;
      HIBYTE(v98[0]) = 105;
      HIBYTE(v99[0]) = 105;
      v99[1] = nullptr;
      HIBYTE(v97[0]) = 52;
      v35 = this->ai;
      memcpy(Dst: v89, Src: v95, Size: sizeof(v89));
      memcpy(Dst: v88, Src: v98, Size: sizeof(v88));
      idEventReceiver::PostEventMS(
        this: v35,
        ev: &AE_AnimDeltaCorrection,
        time: v97[0],
        arg1: (const idEventArg *)v97[2],
        arg2: (const idEventArg *)v97[3],
        arg3: (const idEventArg *)__ROL4__(v97[4], 32),
        arg4: v99[2]);
    }
    this->animBlendVars.animTurnSelect.used = false;
    idList<idThread *,58>::Clear(this: &v115);
    return 0;
  }
}


// ========================================================================
// __unwind$503204
// EA  : 0x82A71A74
// RVA : 0x00A71A74
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503204()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2864 + 528));
}


// ========================================================================
// __unwind$503205
// EA  : 0x82A71A9C
// RVA : 0x00A71A9C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503205()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 784));
}


// ========================================================================
// __unwind$503206
// EA  : 0x82A71AC4
// RVA : 0x00A71AC4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2864 + 592));
}


// ========================================================================
// __unwind$503207
// EA  : 0x82A71AEC
// RVA : 0x00A71AEC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503207()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 624));
}


// ========================================================================
// __unwind$503208
// EA  : 0x82A71B14
// RVA : 0x00A71B14
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2864 + 560));
}


// ========================================================================
// __unwind$503209
// EA  : 0x82A71B3C
// RVA : 0x00A71B3C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503209()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 944));
}


// ========================================================================
// __unwind$503210
// EA  : 0x82A71B64
// RVA : 0x00A71B64
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503210()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 2864 + 1184));
}


// ========================================================================
// __unwind$503211
// EA  : 0x82A71B8C
// RVA : 0x00A71B8C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503211()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 1024));
}


// ========================================================================
// __unwind$503212
// EA  : 0x82A71BB4
// RVA : 0x00A71BB4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503212()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 2864 + 1712));
}


// ========================================================================
// __unwind$503213
// EA  : 0x82A71BDC
// RVA : 0x00A71BDC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503213()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 704));
}


// ========================================================================
// __unwind$503214
// EA  : 0x82A71C04
// RVA : 0x00A71C04
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503214()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 2864 + 2240));
}


// ========================================================================
// __unwind$503215
// EA  : 0x82A71C2C
// RVA : 0x00A71C2C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503215()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2864 + 864));
}


// ========================================================================
// __unwind$503216
// EA  : 0x82A71C54
// RVA : 0x00A71C54
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_503216()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2864 + 464));
}


// ========================================================================
// ?InternalUpdate@idAIFSMLite@@MAAXXZ
// EA  : 0x82A71D40
// RVA : 0x00A71D40
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAIFSMLite::InternalUpdate(idAIFSMLite *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAIStateLite *currentState; // r8
  int valueInteger; // r22
  int v6; // r29
  const char *EnumName; // r21
  const char *Classname; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v10; // r30
  int v11; // r3
  __int64 totalTicks; // r11
  __int64 v13; // r9
  idPLogScope v14; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idAIFSMLite::InternalUpdate");
  LODWORD(v2) = "idAIFSMLite::InternalUpdate";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v14, pl: &::pLog, gMask: v2, label: v3);
  currentState = this->currentState;
  this->currentlyUpdating = true;
  valueInteger = ai_debugMoveFSM.valueInteger;
  if ( currentState != nullptr )
  {
    do
    {
      v6 = this->currentState->InternalWork(this: this->currentState, a2: this->ai, a3: this);
      if ( v6 - 4 < 0 )
      {
        if ( valueInteger > 1 )
        {
          EnumName = idTypeInfoTools::GetEnumName(
                       this: typeInfoTools,
                       enumTypeName: "idTransitionCode",
                       enumValue: v6,
                       defaultValue: "<unknown>");
          Classname = idClass::GetClassname(this: this->currentState);
          idLib::Printf(fmt: "%s::Work( %s )\n", Classname, EnumName);
        }
      }
      else
      {
        this->currentlyUpdating = false;
        idAIFSMLite::ChangeState(this, destStateId: v6 - 4);
        this->currentlyUpdating = true;
      }
    }
    while ( v6 == 2 );
  }
  this->currentlyUpdating = false;
  if ( v14.logIndex >= 0 )
  {
    pLog = v14.pLog;
    v10 = &v14.pLog->logEntries.list[v14.logIndex];
    v11 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v10->totalTicks;
    HIDWORD(totalTicks) = v10->parent;
    LODWORD(v13) = v11 - totalTicks;
    v10->totalTicks = v13;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$504603
// EA  : 0x82A71E7C
// RVA : 0x00A71E7C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504603()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$504604
// EA  : 0x82A71EA4
// RVA : 0x00A71EA4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504604()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ??0idAnimBaseFSM@@QAA@XZ
// EA  : 0x82A71ED8
// RVA : 0x00A71ED8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimBaseFSM *__fastcall idAnimBaseFSM::idAnimBaseFSM(idAnimBaseFSM *this)
{
  int v2; // ctr
  float *p_z; // r9
  float *p_y; // r10
  const char **p_userString; // r10
  float *v6; // r11
  int i; // ctr
  float z; // r4

  idEventReceiver::idEventReceiver(this);
  this->ai = nullptr;
  this->defaultState = nullptr;
  this->currentState = nullptr;
  this->stateStartTime = 0;
  this->currentlyUpdating = false;
  this->idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAIMoveInterface::`vftable';
  this->idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimBaseFSM_vtbl *)&idAnimBaseFSM::`vftable'{for `idAIFSMLite'};
  this->idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimBaseFSM::`vftable'{for `idAIMoveInterface'};
  animDeltaCorrection_t::animDeltaCorrection_t(this: &this->animDeltaCorrection);
  this->translationDeltaScale.x = 1.0;
  this->translationDeltaScale.y = 1.0;
  v2 = 9;
  this->translationDeltaScale.z = 1.0;
  this->emergencyLerp = false;
  p_z = &this->moveDestOriginAtAnimStart.z;
  p_y = &mat2_identity.mat[1].y;
  this->moveDestOriginAtAnimStart = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->flagsDebug = 1;
  idAIMoveCmd::idAIMoveCmd(
    this: &this->intermediateMove,
    user: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM.cpp(317) : default");
  idAIMoveCmd::idAIMoveCmd(
    this: &this->currentMove,
    user: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM.cpp(316) : default");
  p_userString = &this->currentMove.userString;
  v6 = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_userString = *(const char **)++v6;
  this->cachedMoveInfoDest = nullptr;
  this->cachedMoveInfoIntermediate = nullptr;
  this->reachedDestFlags = REACHED_DEST_NONE;
  this->reachedDestFlagsExpected = REACHED_DEST_NONE;
  this->obstacleMove.spawnId.value = 0x1FFF;
  idStaticList<idNpCornerInfo,31>::idStaticList<idNpCornerInfo,31>(this: &this->cachedCorners);
  this->userChannels[0].value = -1;
  this->userChannels[1].value = -1;
  this->userChannels[2].value = -1;
  this->userChannels[3].value = -1;
  this->userChannels[4].value = -1;
  idAnimWebTransitions::transitionCache_t::transitionCache_t(this: &this->arrivalTransitionCache);
  idAnimWebTransitions::transitionCache_t::transitionCache_t(this: &this->departureTransitionCache);
  idAnimWebTransitions::transitionCache_t::transitionCache_t(this: &this->turnTransitionCache);
  idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &this->bestTransitionInfo);
  this->lastTransitionCorner.x = vec3_origin.x;
  this->lastTransitionCorner.y = vec3_origin.y;
  z = vec3_origin.z;
  this->enableIdlePump = true;
  this->overrideMoveFlags = 0;
  this->moveCycleFlags = 0;
  this->moveOrientationOnPath = false;
  this->lastTransitionCorner.z = z;
  idAIOrientation::idAIOrientation(this: &this->orientMove, minRate: 90.0, maxRate: 720.0);
  idAIOrientation::idAIOrientation(this: &this->orientBody, minRate: 45.0, maxRate: 540.0);
  this->useFullyBodyAiming = false;
  this->idleTurnType = AIIDLETURN_RELAXED;
  this->animDeltaMode = ANIMDELTAMODE_DEFAULT;
  idAnimWebCmdWaitHandle::idAnimWebCmdWaitHandle(this: &this->animWaitHandle);
  idAnimBaseFSM::animBlendVars_t::animBlendVars_t(this: &this->animBlendVars);
  idObstacleInfo::idObstacleInfo(this: &this->obstacleInfo);
  this->status = AIMOVESTATUS_DONE;
  this->lastTravelTime = 0;
  this->moveFailures.size = 2;
  this->moveFailures.list = this->moveFailures.staticList;
  this->moveFailures.num = 0;
  this->moveFailures.granularity = 1;
  this->moveFailures.memTag = 5;
  this->moveFailures.listStatic = 1;
  this->moveFailures.staticList[0].moveReason = 37;
  this->moveFailures.staticList[0].moveStatus = 0;
  this->moveFailures.staticList[0].failureTime.value = -1;
  this->moveFailures.staticList[0].pad[0] = 0;
  this->moveFailures.staticList[0].pad[1] = 0;
  this->moveFailures.staticList[1].moveReason = 37;
  this->moveFailures.staticList[1].moveStatus = 0;
  this->moveFailures.staticList[1].failureTime.value = -1;
  this->moveFailures.staticList[1].pad[0] = 0;
  this->moveFailures.staticList[1].pad[1] = 0;
  idArray<idAnimBaseFSM::navTrace_t,256>::idArray<idAnimBaseFSM::navTrace_t,256>(this: &this->navTraces);
  this->pendingAnims.traversalDeltaCorrectionAnim = nullptr;
  idAnimBaseFSM::Reset(this);
  return this;
}


// ========================================================================
// __unwind$504658
// EA  : 0x82A72158
// RVA : 0x00A72158
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504658()
{
  int v0; // r12

  idAIFSMLite::~idAIFSMLite(this: *(idAIFSMLite **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$504659
// EA  : 0x82A72180
// RVA : 0x00A72180
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504659()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(*(_DWORD *)(v0 - 144 + 164) + 584));
}


// ========================================================================
// __unwind$504660
// EA  : 0x82A721AC
// RVA : 0x00A721AC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504660()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(*(_DWORD *)(v0 - 144 + 164) + 740));
}


// ========================================================================
// __unwind$504661
// EA  : 0x82A721D8
// RVA : 0x00A721D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504661()
{
  int v0; // r12

  idStaticList<idNpCornerInfo,31>::~idStaticList<idNpCornerInfo,31>(this: (idStaticList<idNpCornerInfo,31> *)(*(_DWORD *)(v0 - 144 + 164) + 952));
}


// ========================================================================
// __unwind$504662
// EA  : 0x82A72204
// RVA : 0x00A72204
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504662()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 144 + 164) + 3004));
}


// ========================================================================
// __unwind$504663
// EA  : 0x82A72230
// RVA : 0x00A72230
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504663()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 144 + 164) + 3080));
}


// ========================================================================
// __unwind$504664
// EA  : 0x82A7225C
// RVA : 0x00A7225C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504664()
{
  int v0; // r12

  idBreakablePieceDecal::~idBreakablePieceDecal(this: (idBreakablePieceDecal *)(*(_DWORD *)(v0 - 144 + 164) + 3156));
}


// ========================================================================
// __unwind$504665
// EA  : 0x82A72288
// RVA : 0x00A72288
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504665()
{
  int v0; // r12

  idAnimWebCmdWaitHandle::~idAnimWebCmdWaitHandle(this: (idAnimWebCmdWaitHandle *)(*(_DWORD *)(v0 - 144 + 164) + 3488));
}


// ========================================================================
// __unwind$504666
// EA  : 0x82A722B4
// RVA : 0x00A722B4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504666()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 3840));
}


// ========================================================================
// ?CheckReachedCurrentDestination@idAnimBaseFSM@@QAA?AW4reachDestFlags_t@1@XZ
// EA  : 0x82A72348
// RVA : 0x00A72348
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimBaseFSM::reachDestFlags_t __fastcall idAnimBaseFSM::CheckReachedCurrentDestination(idAnimBaseFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAIMoveCmd::DestinationType destType; // r8
  idAIMoveCmd *p_intermediateMove; // r4
  idAnimBaseFSM::reachDestFlags_t v6; // r30
  idPLogScope v8[2]; // [sp+50h] [-90h] BYREF
  idAIMoveInfo v9; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAnimBaseFSM::CheckReachedCurrentDestination");
  LODWORD(v2) = "idAnimBaseFSM::CheckReachedCurrentDestination";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v2, label: v3);
  idAIMoveInfo::idAIMoveInfo(this: &v9);
  destType = this->intermediateMove.destType;
  this->reachedDestFlagsExpected = REACHED_DEST_ORIGIN;
  if ( destType != MOVE_NONE )
  {
    p_intermediateMove = &this->intermediateMove;
  }
  else
  {
    if ( this->currentMove.destType == MOVE_NONE )
    {
      this->reachedDestFlagsExpected = REACHED_DEST_NONE;
      idPLogScope::~idPLogScope(this: v8);
      RD_EventEnd();
      return REACHED_DEST_NONE;
    }
    p_intermediateMove = &this->currentMove;
  }
  this->GetMoveInfo(this, a2: p_intermediateMove, a3: &v9);
  if ( v9.useDestOrientation )
    this->reachedDestFlagsExpected |= 2u;
  v6 = this->HasReachedDestination(this, a2: &this->currentMove, a3: &v9);
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
  return v6;
}


// ========================================================================
// __unwind$504850
// EA  : 0x82A7243C
// RVA : 0x00A7243C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504850()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 176));
}


// ========================================================================
// __unwind$504851
// EA  : 0x82A72464
// RVA : 0x00A72464
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_504851()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?IsMoveDone@idAnimBaseFSM@@UAA_NXZ
// EA  : 0x82A72490
// RVA : 0x00A72490
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::IsMoveDone(idAnimBaseFSM *this)
{
  return (_cntlzw(this->reachedDestFlagsExpected - idAnimBaseFSM::CheckReachedCurrentDestination(this)) & 0x20) != 0;
}


// ========================================================================
// ?SetDestination@idAnimBaseFSM@@QAAXABVidAIMoveCmd@@@Z
// EA  : 0x82A724D0
// RVA : 0x00A724D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::SetDestination(idAnimBaseFSM *this, const idAIMoveCmd *cmd)
{
  idAIMoveCmd *p_currentMove; // r3

  p_currentMove = &this->currentMove;
  if ( cmd->destType != MOVE_NONE )
  {
    idAIMoveCmd::operator=(this: p_currentMove, __that: cmd);
    this->reachedDestFlags = idAnimBaseFSM::CheckReachedCurrentDestination(this);
    this->status = AIMOVESTATUS_MOVING;
  }
  else
  {
    this->reachedDestFlagsExpected = REACHED_DEST_NONE;
    idAIMoveCmd::Init(this: p_currentMove);
    idAIMoveCmd::Init(this: &this->intermediateMove);
    idAnimBaseFSM::ClearCachedCorners(this);
    this->status = AIMOVESTATUS_DONE;
  }
  this->emergencyLerp = false;
}


// ========================================================================
// ?ClearDestination@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A72558
// RVA : 0x00A72558
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::ClearDestination(idAnimBaseFSM *this)
{
  idAnimBaseFSM::SetDestination(this, cmd: &idAIMoveCmd::s_null);
}


// ========================================================================
// ?GetMoveInfo@idAnimBaseFSM@@UAAHABVidAIMoveCmd@@AAUidAIMoveInfo@@@Z
// EA  : 0x82A72568
// RVA : 0x00A72568
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::GetMoveInfo(idAnimBaseFSM *this, const idAIMoveCmd *moveCmd, idAIMoveInfo *moveInfo)
{
  idPhysics *Physics; // r3
  idVec3 *v7; // r26
  idAIOrientation *BodyOrientation; // r3
  idMat3 *p_destOrientation; // r27
  idVec3 *v10; // r29
  idVec3 *v11; // r28
  idVec3 *p_destPosition; // r26
  idVec3 *p_destNormal; // r11
  idAIMoveCmd::DestinationType destType; // r11
  int value; // r10
  idEntity *v17; // r3
  idEntity *v18; // r3
  idPhysics *v19; // r3
  float *v20; // r3
  idEntity *v21; // r3
  idEntity *v22; // r3
  idPhysics *v23; // r3
  float *v24; // r3

  Physics = idEntity::GetPhysics(this: this->ai);
  v7 = (idVec3 *)Physics->GetOrigin(this: Physics, a2: 0);
  BodyOrientation = idAI2::GetBodyOrientation(this: this->ai);
  moveInfo->destEntity.spawnId.value = 0x1FFF;
  moveInfo->destPosition = *v7;
  p_destOrientation = &moveInfo->destOrientation;
  v10 = &moveInfo->destOrientation.mat[1];
  v11 = &moveInfo->destOrientation.mat[2];
  p_destPosition = &moveInfo->destPosition;
  p_destNormal = &moveCmd->destNormal;
  moveInfo->destOrientation = BodyOrientation->axis;
  moveInfo->useDestOrientation = moveCmd->arriveOrient != AIARRIVAL_ORIENT_NONE;
  moveInfo->arrivalAction = moveCmd->arrivalAction;
  moveInfo->arrivalRadius = moveCmd->arrivalRadius;
  moveInfo->moveFlags = moveCmd->moveFlags;
  if ( ((LODWORD(moveCmd->destNormal.z) | LODWORD(moveCmd->destNormal.y) | LODWORD(moveCmd->destNormal.x)) & 0x7FFFFFFF) == 0 )
    p_destNormal = &moveInfo->destOrientation.mat[2];
  moveInfo->destNormal.x = p_destNormal->x;
  moveInfo->destNormal.y = p_destNormal->y;
  moveInfo->destNormal.z = p_destNormal->z;
  destType = moveCmd->destType;
  switch ( destType )
  {
    case MOVE_NONE:
      goto LABEL_4;
    case MOVE_ENTITY:
      value = moveCmd->destEnt.spawnId.value;
      moveInfo->destEntity.spawnId.value = value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
        || (v17 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        || idEntity::CastTo(c: v17) == nullptr )
      {
LABEL_4:
        idAnimBaseFSM::SetDestination(this, cmd: &idAIMoveCmd::s_null);
        return 4;
      }
      v18 = idEntityPtr<idEntity const>::operator->(this: &moveInfo->destEntity);
      v19 = idEntity::GetPhysics(this: v18);
      v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
      p_destPosition->x = *v20;
      moveInfo->destPosition.y = v20[1];
      moveInfo->destPosition.z = v20[2];
      if ( (moveCmd->moveFlags & 0x10) != 0 )
      {
        v21 = idEntityPtr<idEntity const>::operator->(this: &moveInfo->destEntity);
        v21->GetAimPoint(this: v21, a2: AIMPOINT_HEAD, a3: &moveInfo->destPosition);
      }
      v22 = idEntityPtr<idEntity const>::operator->(this: &moveInfo->destEntity);
      v23 = idEntity::GetPhysics(this: v22);
      v24 = (float *)v23->GetAxis(this: v23, a2: 0);
      p_destOrientation->mat[0].x = *v24;
      moveInfo->destOrientation.mat[0].y = v24[1];
      moveInfo->destOrientation.mat[0].z = v24[2];
      v10->x = v24[3];
      moveInfo->destOrientation.mat[1].y = v24[4];
      moveInfo->destOrientation.mat[1].z = v24[5];
      v11->x = v24[6];
      moveInfo->destOrientation.mat[2].y = v24[7];
      moveInfo->destOrientation.mat[2].z = v24[8];
      break;
    case MOVE_POSITION:
      p_destPosition->x = moveCmd->destPos.x;
      moveInfo->destPosition.y = moveCmd->destPos.y;
      moveInfo->destPosition.z = moveCmd->destPos.z;
      p_destOrientation->mat[0].x = moveCmd->arriveAxis.mat[0].x;
      moveInfo->destOrientation.mat[0].y = moveCmd->arriveAxis.mat[0].y;
      moveInfo->destOrientation.mat[0].z = moveCmd->arriveAxis.mat[0].z;
      v10->x = moveCmd->arriveAxis.mat[1].x;
      moveInfo->destOrientation.mat[1].y = moveCmd->arriveAxis.mat[1].y;
      moveInfo->destOrientation.mat[1].z = moveCmd->arriveAxis.mat[1].z;
      v11->x = moveCmd->arriveAxis.mat[2].x;
      moveInfo->destOrientation.mat[2].y = moveCmd->arriveAxis.mat[2].y;
      moveInfo->destOrientation.mat[2].z = moveCmd->arriveAxis.mat[2].z;
      return 0;
    default:
      break;
  }
  return 0;
}


// ========================================================================
// ?UpdateTransitionToDestination@idAnimBaseFSM@@QAA?AW4transitionCheckReturnValue_t@@AAUtransitionQueryResult_t@idAnimWebTransitions@@W4transitionType_t@@@Z
// EA  : 0x82A72868
// RVA : 0x00A72868
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::UpdateTransitionToDestination(
        idAnimBaseFSM *this,
        idAnimWebTransitions::transitionQueryResult_t *transInfo,
        int transType)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int nextArrivalCorner; // r21
  char v9; // r11
  idPhysics *Physics; // r3
  const idVec3 *v11; // r3
  idAI2 *ai; // r3
  idMat3 *p_axis; // r29
  float x; // r8
  float y; // r7
  float z; // r6
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idVec3 *v18; // r27
  idVec3 *v19; // r26
  double v20; // fp8
  double v21; // fp7
  double v22; // fp29
  double v23; // fp31
  double v24; // fp30
  idVec3 *p_position; // r30
  idVec3 *p_nextArrivalPos; // r11
  float v27; // r9
  float v28; // r8
  idMat3 *p_nextArrivalAxis; // r11
  int *v30; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const char *v33; // r25
  int v34; // r24
  idAnimWebTransitions::transitionQueryValidation_t *v35; // r4
  double v36; // fp0
  double v37; // fp13
  double v38; // fp12
  char v39; // r24
  double v40; // fp5
  double v41; // fp3
  char v42; // r25
  double v43; // fp10
  double v44; // fp9
  double v45; // fp8
  double v46; // fp7
  double v47; // fp6
  double v48; // fp0
  double v49; // fp13
  double v50; // fp12
  char v51; // r11
  idAI2 *v52; // r3
  bool v53; // r11
  bool v54; // zf
  double v56; // fp12
  double v57; // fp11
  double v58; // fp10
  double v59; // fp9
  double v60; // fp8
  double v61; // fp7
  double v62; // fp6
  double v63; // fp5
  double v64; // fp4
  double v65; // fp5
  double v66; // fp3
  idMat3 *v67; // r3
  double v68; // fp13
  double v69; // fp12
  double v70; // fp11
  double v71; // fp10
  double v72; // fp9
  double v73; // fp8
  double v74; // fp7
  double v75; // fp6
  double v76; // fp13
  double v77; // fp9
  idAnimBaseFSM_vtbl *v78; // r10
  char CommonArrivalTransition; // r30
  idPLogScope v80; // [sp+58h] [-388h] BYREF
  float v81; // [sp+60h] [-380h] BYREF
  float v82; // [sp+64h] [-37Ch]
  float v83; // [sp+68h] [-378h]
  idAnimWebTransitions::transitionQueryValidation_t v84; // [sp+70h] [-370h] BYREF
  float v85; // [sp+A8h] [-338h]
  float v86; // [sp+ACh] [-334h]
  float v87; // [sp+B0h] [-330h]
  float v88; // [sp+C0h] [-320h] BYREF
  __int16 v89; // [sp+C4h] [-31Ch]
  int v90; // [sp+C8h] [-318h]
  char v91; // [sp+CCh] [-314h]
  idMat3 v92; // [sp+D0h] [-310h] BYREF
  float v93; // [sp+F4h] [-2ECh]
  float v94; // [sp+F8h] [-2E8h]
  int v95; // [sp+FCh] [-2E4h] BYREF
  idVec3 v96; // [sp+100h] [-2E0h] BYREF
  float v97; // [sp+10Ch] [-2D4h]
  float v98; // [sp+110h] [-2D0h]
  float v99; // [sp+114h] [-2CCh]
  float v100; // [sp+118h] [-2C8h]
  float v101; // [sp+11Ch] [-2C4h]
  float v102; // [sp+120h] [-2C0h]
  idAnimWebTransitions::transitionQueryParms_t v103; // [sp+130h] [-2B0h] BYREF
  int v104; // [sp+338h] [-A8h] BYREF

  RD_EventBegin(name: "idAnimBaseFSM::UpdateTransitionToDestination");
  LODWORD(v6) = "idAnimBaseFSM::UpdateTransitionToDestination";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v80, pl: &pLog, gMask: v6, label: v7);
  nextArrivalCorner = this->nextArrivalCorner;
  if ( nextArrivalCorner < 0 || (v9 = 1, nextArrivalCorner >= this->cachedCorners.num) )
    v9 = 0;
  if ( transType != 6 && v9 == 0 )
    goto LABEL_26;
  Physics = idEntity::GetPhysics(this: this->ai);
  v11 = Physics->GetOrigin(this: Physics, a2: 0);
  p_axis = &this->orientBody.axis;
  x = v11->x;
  y = v11->y;
  z = v11->z;
  ai = this->ai;
  v81 = x;
  v82 = y;
  v83 = z;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, trans: (idVec3 *)&v92.mat[2].z);
  v18 = &this->orientBody.axis.mat[2];
  v19 = &this->orientBody.axis.mat[1];
  v20 = (float)((float)(this->orientBody.axis.mat[0].z * v92.mat[2].z)
              + (float)((float)(this->orientBody.axis.mat[1].z * v93) + (float)(this->orientBody.axis.mat[2].z * v94)));
  v21 = (float)((float)(v92.mat[2].z * this->orientBody.axis.mat[0].y)
              + (float)((float)(this->orientBody.axis.mat[1].y * v93) + (float)(this->orientBody.axis.mat[2].y * v94)));
  v22 = (float)((float)((float)(this->orientBody.axis.mat[0].x * v92.mat[2].z)
                      + (float)((float)(v93 * this->orientBody.axis.mat[1].x)
                              + (float)(v94 * this->orientBody.axis.mat[2].x)))
              + v81);
  v23 = (float)(v83
              + (float)((float)(this->orientBody.axis.mat[0].z * v92.mat[2].z)
                      + (float)((float)(this->orientBody.axis.mat[1].z * v93)
                              + (float)(this->orientBody.axis.mat[2].z * v94))));
  v81 = (float)((float)(this->orientBody.axis.mat[0].x * v92.mat[2].z)
              + (float)((float)(v93 * this->orientBody.axis.mat[1].x) + (float)(v94 * this->orientBody.axis.mat[2].x)))
      + v81;
  v83 = v83 + (float)v20;
  v24 = (float)(v82 + (float)v21);
  v82 = v82 + (float)v21;
  if ( transType == 6 )
  {
    p_position = (idVec3 *)&v81;
    p_nextArrivalPos = (idVec3 *)&v81;
  }
  else
  {
    p_position = &this->cachedCorners.list[nextArrivalCorner].position;
    p_nextArrivalPos = &this->nextArrivalPos;
  }
  v27 = p_nextArrivalPos->y;
  v28 = p_nextArrivalPos->z;
  v85 = p_nextArrivalPos->x;
  p_nextArrivalAxis = &this->orientBody.axis;
  v86 = v27;
  v87 = v28;
  if ( transType != 6 )
    p_nextArrivalAxis = &this->nextArrivalAxis;
  v30 = &v95;
  p_z = (_DWORD *)&p_nextArrivalAxis[-1].mat[2].z;
  for ( i = 9; i != 0; --i )
    *++v30 = *++p_z;
  v84 = idAnimWebTransitions::defaultArrivalTransitionValidation;
  v33 = "transitions";
  v34 = 2;
  if ( transType >= 3 )
  {
    if ( transType <= 4 )
    {
      v33 = "steptransitions";
      v34 = 4;
      v84 = idAnimWebTransitions::defaultStepTransitionValidation;
    }
    else if ( transType == 6 )
    {
      v35 = &idAnimWebTransitions::defaultSoftStopTransitionValidation;
LABEL_22:
      v84 = *v35;
      goto LABEL_23;
    }
  }
  if ( transType == 2 || transType == 4 )
  {
    v35 = &idAnimWebTransitions::defaultFlightTransitionValidation;
    goto LABEL_22;
  }
LABEL_23:
  idAnimBaseFSM::UpdateArrivalTransitionCache(this, nodeCheckFlags: v34, transitionSubweb: v33);
  if ( this->arrivalTransitionCache.transitions.num == 0 )
    goto LABEL_26;
  v36 = v85;
  v37 = v86;
  this->bestTransitionInfo.selectionIndex = -1;
  v38 = v87;
  this->lastTransitionCorner.x = v36;
  v39 = 1;
  this->lastTransitionCorner.y = v37;
  this->lastTransitionCorner.z = v38;
  v40 = (float)((float)v24 - p_position->y);
  v41 = (float)((float)v23 - p_position->z);
  if ( (float)((float)((float)v41 * (float)v41)
             + (float)((float)((float)((float)v22 - p_position->x) * (float)((float)v22 - p_position->x))
                     + (float)((float)v40 * (float)v40))) <= (double)(float)(this->arrivalTransitionCache.maximumDeltaOriginDistanceSqr
                                                                           * v84.maxMoveDistanceMultiplier) )
  {
_M505683:
    idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v103);
    idAnimBaseFSM::FillListWithCachedCorners(this, otherList: &v103.cachedCorners, stopAtLink: true, stopAtArrive: true);
    v103.destinationOrigin = *p_position;
    v42 = 1;
    v103.destinationAxis.mat[0].x = v96.x;
    v103.destinationAxis.mat[0].y = v96.y;
    v103.destinationAxis.mat[0].z = v96.z;
    v103.destinationAxis.mat[1].x = v97;
    v103.destinationAxis.mat[1].y = v98;
    v103.destinationAxis.mat[1].z = v99;
    v103.destinationAxis.mat[2].x = v100;
    v103.destinationAxis.mat[2].y = v101;
    v103.destinationAxis.mat[2].z = v102;
    if ( transType == 6 )
    {
      v43 = this->orientBody.axis.mat[1].y;
      v44 = this->orientBody.axis.mat[1].z;
      v45 = v18->x;
      v42 = 0;
      v46 = this->orientBody.axis.mat[2].y;
      v47 = this->orientBody.axis.mat[2].z;
      v48 = p_axis->mat[0].x;
      v49 = this->orientBody.axis.mat[0].y;
      v50 = this->orientBody.axis.mat[0].z;
      v103.destinationAxis.mat[1].x = v19->x;
      v103.destinationAxis.mat[1].y = v43;
      v103.destinationOrigin.x = v22;
      v103.destinationAxis.mat[1].z = v44;
      v103.destinationOrigin.y = v24;
      v103.destinationAxis.mat[2].x = v45;
      v103.destinationOrigin.z = v23;
      v103.destinationAxis.mat[2].y = v46;
      v103.destinationAxis.mat[0].x = v48;
      v103.destinationAxis.mat[2].z = v47;
      v103.destinationAxis.mat[0].y = v49;
      v103.sourceAxis.mat[1].x = v103.destinationAxis.mat[1].x;
      v103.destinationAxis.mat[0].z = v50;
      v103.sourceAxis.mat[1].y = v43;
      v103.sourceAxis.mat[1].z = v44;
      v103.sourceOrigin1.x = v22;
      v103.sourceAxis.mat[2].x = v45;
      v103.sourceOrigin1.y = v24;
      v103.sourceAxis.mat[2].y = v46;
      v103.sourceOrigin1.z = v23;
      v103.sourceAxis.mat[2].z = v47;
      v103.sourceOrigin2.x = v22;
      v103.sourceOrigin2.y = v24;
      v103.sourceOrigin2.z = v23;
      v103.sourceAxis.mat[0].x = v48;
      v103.sourceAxis.mat[0].y = v49;
      v103.sourceAxis.mat[0].z = v50;
    }
    else if ( transType == 5 )
    {
      if ( nextArrivalCorner != 0 )
      {
        v84.selectType = CHOOSE_CLOSEST_TO_SEGMENT;
        v103.sourceOrigin1 = this->cachedCorners.list[nextArrivalCorner - 1].position;
        v103.sourceOrigin2.x = p_position->x;
        v103.sourceOrigin2.y = p_position->y;
        v103.sourceOrigin2.z = p_position->z;
        v84.checkMaxMovementDistance = false;
        v84.navProbeAnimTranslation = true;
        v84.requiredSourceAlignAngleDot = -1.0;
        v84.requiredMoveAlignAngleDot = -0.000000050005699;
        v84.requiredApexAlignAngleDot = -0.000000050005699;
        v65 = p_position->z;
        v66 = (float)(p_position->y - (float)v24);
        v92.mat[0].x = p_position->x - (float)v22;
        v92.mat[0].z = (float)v65 - (float)v23;
        v92.mat[0].y = v66;
        v67 = idVec3::ToMat3(this: &v96, result: &v92);
        v103.sourceAxis.mat[0].x = v67->mat[0].x;
        v103.sourceAxis.mat[0].y = v67->mat[0].y;
        v103.sourceAxis.mat[0].z = v67->mat[0].z;
        v103.sourceAxis.mat[1] = v67->mat[1];
        v103.sourceAxis.mat[2] = v67->mat[2];
      }
      else
      {
        v103.sourceOrigin1.x = v22;
        v103.sourceOrigin1.y = v24;
        v103.sourceOrigin1.z = v23;
        v103.sourceOrigin2.x = p_position->x;
        v103.sourceOrigin2.y = p_position->y;
        v56 = p_axis->mat[0].x;
        v57 = this->orientBody.axis.mat[0].y;
        v58 = this->orientBody.axis.mat[0].z;
        v59 = v19->x;
        v60 = this->orientBody.axis.mat[1].y;
        v61 = this->orientBody.axis.mat[1].z;
        v62 = v18->x;
        v63 = this->orientBody.axis.mat[2].y;
        v64 = this->orientBody.axis.mat[2].z;
        v103.sourceOrigin2.z = p_position->z;
        v103.sourceAxis.mat[0].x = v56;
        v103.sourceAxis.mat[0].y = v57;
        v103.sourceAxis.mat[0].z = v58;
        v103.sourceAxis.mat[1].x = v59;
        v103.sourceAxis.mat[1].y = v60;
        v103.sourceAxis.mat[1].z = v61;
        v103.sourceAxis.mat[2].x = v62;
        v103.sourceAxis.mat[2].y = v63;
        v103.sourceAxis.mat[2].z = v64;
        if ( v39 == 0 )
        {
          v84.selectType = CHOOSE_CLOSEST_TO_SEGMENT;
          v84.checkMaxMovementDistance = false;
          v84.navProbeAnimTranslation = true;
          v84.requiredSourceAlignAngleDot = -1.0;
          v84.requiredMoveAlignAngleDot = -0.000000050005699;
          v84.requiredApexAlignAngleDot = -0.000000050005699;
        }
      }
    }
    else
    {
      v68 = this->orientBody.axis.mat[0].y;
      v69 = this->orientBody.axis.mat[0].z;
      v70 = v19->x;
      v71 = this->orientBody.axis.mat[1].y;
      v72 = this->orientBody.axis.mat[1].z;
      v73 = v18->x;
      v74 = this->orientBody.axis.mat[2].y;
      v75 = this->orientBody.axis.mat[2].z;
      v103.sourceAxis.mat[0].x = p_axis->mat[0].x;
      v103.sourceAxis.mat[0].y = v68;
      v103.sourceOrigin1.x = v22;
      v103.sourceAxis.mat[0].z = v69;
      v103.sourceOrigin1.y = v24;
      v103.sourceAxis.mat[1].x = v70;
      v103.sourceOrigin1.z = v23;
      v103.sourceAxis.mat[1].y = v71;
      v103.sourceAxis.mat[1].z = v72;
      v103.sourceAxis.mat[2].x = v73;
      v103.sourceAxis.mat[2].y = v74;
      v103.sourceAxis.mat[2].z = v75;
      if ( transType != 0 )
      {
        if ( transType != 1 )
          goto LABEL_30;
      }
      else
      {
        v76 = (float)(p_position->y - (float)v24);
        v77 = (float)(p_position->z - (float)v23);
        if ( (float)((float)((float)v77 * (float)v77)
                   + (float)((float)((float)(p_position->x - (float)v22) * (float)(p_position->x - (float)v22))
                           + (float)((float)v76 * (float)v76))) < (double)(float)(ai_arrivalFallbackDistance.valueFloat
                                                                                * ai_arrivalFallbackDistance.valueFloat) )
          v84.allowRejections = false;
      }
      v89 = 257;
      v90 = 0;
      v91 = 1;
      v78 = this->idAIFSMLite::idEventReceiver::idClass::__vftable;
      v88 = 1.0;
      v78->GetPathPositionAndDirection(
        this,
        a2: (const idAnimBaseFSM::pathPositionAndDirectionParms_t *)&v88,
        a3: (idVec3 *)&v104,
        a4: (idVec3 *)&v92.mat[1].y);
      if ( (float)((float)(this->orientBody.axis.mat[0].z * v92.mat[2].x)
                 + (float)((float)(v92.mat[1].y * this->orientBody.axis.mat[0].x)
                         + (float)(v92.mat[1].z * this->orientBody.axis.mat[0].y))) < 0.9238795 )
      {
LABEL_58:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v103.cachedCorners);
        idPLogScope::~idPLogScope(this: &v80);
        goto LABEL_59;
      }
    }
LABEL_30:
    if ( ai_enableScrambles.valueInteger == 0
      || (v51 = 1, this->ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
    {
      v51 = 0;
    }
    v52 = this->ai;
    v54 = v51 == 0;
    v53 = (v52->aiVolatile.groupStatus.condition & 8) != 0;
    if ( !v54 )
    {
      v84.suggestedFlags |= 0x4000u;
      v84.allowedFlags |= 0x4000u;
    }
    if ( v53 )
    {
      v84.allowedFlags |= 0x2000u;
      v84.requiredFlags |= 0x2000u;
    }
    if ( (unsigned __int8)idAnimWebTransitions::PrepareArrivalTraces(
                            ai: v52,
                            validation: &v84,
                            cache: &this->arrivalTransitionCache,
                            parms: &v103) == 0 )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v103.cachedCorners);
      idPLogScope::~idPLogScope(this: &v80);
      RD_EventEnd();
      return 1;
    }
    CommonArrivalTransition = idAnimWebTransitions::FindCommonArrivalTransition(
                                ai: this->ai,
                                validation: &v84,
                                cache: &this->arrivalTransitionCache,
                                parms: &v103,
                                out: transInfo);
    if ( transInfo->selectionIndex > -1 )
      idAnimWebTransitions::transitionQueryResult_t::operator=(this: &this->bestTransitionInfo, __that: transInfo);
    if ( (v42 == 0
       || CommonArrivalTransition == 0
       || idAnimBaseFSM::GetRemainingPathDistance(this) <= (double)transInfo->approximatePathDistance)
      && v39 != 0
      && CommonArrivalTransition != 0 )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v103.cachedCorners);
      idPLogScope::~idPLogScope(this: &v80);
      RD_EventEnd();
      return 2;
    }
    goto LABEL_58;
  }
  if ( transType == 5 )
  {
    v39 = 0;
    goto _M505683;
  }
LABEL_26:
  idPLogScope::~idPLogScope(this: &v80);
LABEL_59:
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$505183
// EA  : 0x82A73130
// RVA : 0x00A73130
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505183()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 992 + 836));
}


// ========================================================================
// __unwind$505184
// EA  : 0x82A73158
// RVA : 0x00A73158
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505184()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 992 + 88));
}


// ========================================================================
// __unwind$505185
// EA  : 0x82A73180
// RVA : 0x00A73180
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505185()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 992 + 304));
}


// ========================================================================
// ?StartArrivalAnimation@idAnimBaseFSM@@QAA_NAAUtransitionQueryResult_t@idAnimWebTransitions@@ABVidVec3@@_NW4transitionType_t@@@Z
// EA  : 0x82A731B0
// RVA : 0x00A731B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimBaseFSM::StartArrivalAnimation(
        idAnimBaseFSM *this,
        idAnimWebTransitions::transitionQueryResult_t *transInfo,
        const idVec3 *destinationOrigin,
        bool force,
        transitionType_t transType)
{
  int *v5; // r10
  int v10; // ctr
  float *p_destAnimUpdateDistanceMinSqr; // r9
  idAIAnimWebState_Idle *v13; // r3
  idAnimWebState *v14; // r11
  int *v15; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr
  idAnimWebCmdCtx *v18; // r3
  idAnimWebCmd *v19; // r3
  idAnimWebCmd *v20; // r3
  int flags; // r8
  __int64 v22; // r10
  int v24; // r11
  int selectionIndex; // r11
  int v26; // [sp+5Ch] [-154h] BYREF
  idAnimWebState v27; // [sp+60h] [-150h] BYREF
  idAIAnimWebState_Transition v28; // [sp+80h] [-130h] BYREF
  idAIAnimWebState_Idle v29; // [sp+A0h] [-110h] BYREF
  idAnimWebCmd v30; // [sp+C0h] [-F0h] BYREF

  v5 = &v26;
  v10 = 5;
  p_destAnimUpdateDistanceMinSqr = &this->currentMove.destAnimUpdateDistanceMinSqr;
  do
  {
    *++v5 = *(_DWORD *)++p_destAnimUpdateDistanceMinSqr;
    --v10;
  }
  while ( v10 != 0 );
  if ( !idAnimWebState::Verify(this: &v27, errorMsg: nullptr) )
  {
    v13 = idAIAnimWebState_Idle::idAIAnimWebState_Idle(
            this: &v29,
            ai: this->ai,
            subweb: AISUBWEB_MAX,
            posture: POSTURE_MAX,
            useWeaponSlot: EQUIP_MAX);
    v14 = &v13->idAnimWebState;
    if ( v13 == nullptr )
      v14 = nullptr;
    v15 = &v26;
    p_debugState = &v14[-1].debugState;
    for ( i = 5; i != 0; --i )
    {
      ++p_debugState;
      *++v15 = (int)p_debugState->str;
    }
    v29.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
  }
  idAIAnimWebState_Transition::idAIAnimWebState_Transition(
    this: &v28,
    ai: this->ai,
    out: transInfo,
    skipTrace: true,
    skipVerifyPointOutsideAnimRange: true);
  if ( !idAnimWebState::Verify(this: &v28.idAnimWebState, errorMsg: nullptr) )
    return 0;
  v18 = this->ai->GetAnimWebCmdCtx(this: this->ai);
  idAnimWebCmd::idAnimWebCmd(
    this: &v30,
    _owner: v18,
    userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM.cpp(1342) : arrival transition");
  if ( force )
    idAnimWebCmd::Force(this: &v30, blendFrames: 3, originBlend: ORIGINBLEND_BRANCH);
  v19 = idAnimWebCmd::Via(this: &v30, _via: &v28.idAnimWebState, optional: false);
  v20 = idAnimWebCmd::ChangeState(this: v19, _dst: &v27);
  flags = v20->flags;
  v20->intrBlend = INTR_BLEND_MULTI;
  v20->intrPath = INTR_PATH_IMMEDIATE;
  v20->flags = flags | 0x200;
  v20->groups = 1;
  v20->groupFilter = 34825;
  if ( idAnimWebCmd::Commit(
         this: v20,
         handle: &this->animWaitHandle,
         priority: AWCMD_PRIORITY_HIGH,
         ev: AWCMD_EVENT_VIA_BLEND_OUT_END) != AWCMD_STATUS_OK )
  {
    if ( transType == TRANSITION_STEP || transType == TRANSITION_STEP_FLIGHT )
    {
      this->animBlendVars.animStepSelect.used = false;
      this->animBlendVars.animStepSelect.value = 0.0;
    }
    else
    {
      this->animBlendVars.animArrivalSelect.used = false;
      this->animBlendVars.animArrivalSelect.value = 0.0;
    }
    return 0;
  }
  if ( transType == TRANSITION_STEP || transType == TRANSITION_STEP_FLIGHT )
  {
    selectionIndex = transInfo->selectionIndex;
    this->animBlendVars.animStepSelect.used = true;
    LODWORD(v22) = selectionIndex;
    this->animBlendVars.animStepSelect.value = (float)v22;
  }
  else
  {
    v24 = transInfo->selectionIndex;
    this->animBlendVars.animArrivalSelect.used = true;
    LODWORD(v22) = v24;
    this->animBlendVars.animArrivalSelect.value = (float)v22;
  }
  idAIOrientation::SetIdealDir(this: &this->orientBody, ai: this->ai, dir: this->nextArrivalAxis.mat);
  idAnimBaseFSM::CreateMoveAutoObstacle(this, pos: destinationOrigin);
  return 1;
}


// ========================================================================
// __unwind$505732
// EA  : 0x82A733E4
// RVA : 0x00A733E4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505732()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 432 + 128));
}


// ========================================================================
// ??1idAnimFSM_AAS@@UAA@XZ
// EA  : 0x82A73418
// RVA : 0x00A73418
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::~idAnimFSM_AAS(idAnimFSM_AAS *this)
{
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_AAS_vtbl *)&idAnimFSM_AAS::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM_AAS::`vftable'{for `idAIMoveInterface'};
  idObstacleAvoidance::~idObstacleAvoidance(this: &this->oa);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_AAS_vtbl *)&idAnimFSM::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM::`vftable'{for `idAIMoveInterface'};
  idAnimBaseFSM::~idAnimBaseFSM(this);
}


// ========================================================================
// __unwind$505845
// EA  : 0x82A73490
// RVA : 0x00A73490
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505845()
{
  int v0; // r12

  idAnimFSM::~idAnimFSM(this: *(idAnimFSM **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idAnimFSM_NP@@UAA@XZ
// EA  : 0x82A734C0
// RVA : 0x00A734C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::~idAnimFSM_NP(idAnimFSM_NP *this)
{
  idNpNavigator *groundNavigator; // r29

  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_NP_vtbl *)&idAnimFSM_NP::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM_NP::`vftable'{for `idAIMoveInterface'};
  groundNavigator = this->groundNavigator;
  if ( groundNavigator != nullptr )
  {
    idNpNavigator::~idNpNavigator(this: this->groundNavigator);
    idMem::Free(this: &mem, ptr: groundNavigator, align: ALIGN_16);
  }
  this->groundNavigator = nullptr;
  idAnimBaseFSM::DeleteMoveAutoObstacle(this);
  idNpLink::~idNpLink(this: &this->linkEndCorner.link);
  idNpLink::~idNpLink(this: &this->linkTraversing);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_NP_vtbl *)&idAnimFSM::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM::`vftable'{for `idAIMoveInterface'};
  idAnimBaseFSM::~idAnimBaseFSM(this);
}


// ========================================================================
// __unwind$505867
// EA  : 0x82A73564
// RVA : 0x00A73564
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505867()
{
  int v0; // r12

  idAnimFSM::~idAnimFSM(this: *(idAnimFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505868
// EA  : 0x82A7358C
// RVA : 0x00A7358C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505868()
{
  int v0; // r12

  idNpLink::~idNpLink(this: (idNpLink *)(*(_DWORD *)(v0 - 112 + 132) + 13324));
}


// ========================================================================
// __unwind$505869
// EA  : 0x82A735B8
// RVA : 0x00A735B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505869()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(*(_DWORD *)(v0 - 112 + 132) + 13332));
}


// ========================================================================
// ?ClampCachedCornersToGround@idAnimFSM@@IAAXM@Z
// EA  : 0x82A735F0
// RVA : 0x00A735F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::ClampCachedCornersToGround(idAnimFSM *this, double dropHeight)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  __int64 v6; // r24
  int v7; // r17
  float *p_y; // r29
  float *p_z; // r30
  int v10; // r21
  idNpCornerInfo *v11; // r26
  int v12; // r10
  char v13; // r11
  float *v14; // r28
  idClip *p_clip; // r27
  __int64 v16; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  __int64 v20; // r11
  double v21; // fp0
  double v22; // fp13
  char v23; // r9
  double v24; // fp12
  double v25; // fp11
  double v26; // fp10
  double v27; // fp9
  idPhysics *Physics; // r30
  idPhysics *v29; // r28
  int v30; // r3
  double v31; // fp29
  float *v32; // r3
  double v33; // fp11
  idAI2 *ai; // r3
  double v35; // fp10
  double v36; // fp8
  double v37; // fp9
  double v38; // fp6
  idPhysics *v39; // r3
  float *v40; // r3
  double v41; // fp4
  double v42; // fp3
  double v43; // fp10
  double v44; // fp9
  idClip *v45; // r3
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  char v49; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v51; // r30
  int v52; // r3
  __int64 totalTicks; // r11
  __int64 v54; // r9
  int v55; // [sp+8h] [-6B8h]
  bool v56; // [sp+Fh] [-6B1h]
  const char *v57; // [sp+10h] [-6B0h]
  int v58; // [sp+14h] [-6ACh]
  int v59; // [sp+18h] [-6A8h]
  int v60; // [sp+1Ch] [-6A4h]
  int v61; // [sp+20h] [-6A0h]
  int v62; // [sp+24h] [-69Ch]
  int v63; // [sp+28h] [-698h]
  int v64; // [sp+2Ch] [-694h]
  int v65; // [sp+30h] [-690h]
  int v66; // [sp+34h] [-68Ch]
  int v67; // [sp+38h] [-688h]
  int v68; // [sp+3Ch] [-684h]
  int v69; // [sp+40h] [-680h]
  int v70; // [sp+44h] [-67Ch]
  int v71; // [sp+48h] [-678h]
  int v72; // [sp+4Ch] [-674h]
  int v73; // [sp+50h] [-670h]
  int v74; // [sp+58h] [-668h]
  int v75; // [sp+60h] [-660h]
  int v76; // [sp+70h] [-650h]
  idPLogScope v77; // [sp+78h] [-648h] BYREF
  idVec3 v78; // [sp+80h] [-640h] BYREF
  idVec3 v79; // [sp+90h] [-630h] BYREF
  idClip *v80; // [sp+9Ch] [-624h]
  int v81; // [sp+A0h] [-620h] BYREF
  trace_t v82; // [sp+B0h] [-610h] BYREF
  idArray<idAnimFSM::cornerClipInfo_t,31> v83; // [sp+130h] [-590h] BYREF

  RD_EventBegin(name: "idAnimFSM::ClampCachedCornersToGround");
  LODWORD(v4) = "idAnimFSM::ClampCachedCornersToGround";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: &v77, pl: &::pLog, gMask: v4, label: v5);
  idArray<idAnimFSM::cornerClipInfo_t,31>::idArray<idAnimFSM::cornerClipInfo_t,31>(this: &v83);
  LODWORD(v6) = 0;
  v76 = 0;
  if ( this->cachedCorners.num <= 0 )
    goto LABEL_22;
  v7 = 0;
  p_y = &v83.ptr[0].groundPos.y;
  do
  {
    p_z = &this->cornerGroundInfo.ptr[0].navPos.z;
    BYTE3(v6) = 0;
    v10 = 0;
    v11 = &this->cachedCorners.list[v7];
    while ( BYTE3(v6) == 0 )
    {
      v12 = *((_DWORD *)p_z + 4);
      if ( v12 == 0 )
        goto LABEL_18;
      if ( *(p_z - 2) != v11->position.x || *(p_z - 1) != v11->position.y || (v13 = 1, *p_z != v11->position.z) )
        v13 = 0;
      if ( v13 == 0 )
        goto LABEL_18;
      HIDWORD(v6) = 1;
      if ( v12 != 1 )
        goto LABEL_15;
      v14 = p_z - 4;
      p_clip = &clientGame->clip;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: (const idClipQuery *)p_z - 2) != 0 )
      {
        v16 = *(_QWORD *)v14;
        *(_QWORD *)v14 = v6;
        v80 = p_clip;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v82,
          query: &p_clip->collisionQueries[v16 & 0xFFF].query,
          peek: false);
        if ( v82.fraction < 1.0 )
        {
          x = v82.endpos.x;
          y = v82.endpos.y;
          z = v82.endpos.z;
          *((_DWORD *)p_z + 4) = 2;
          p_z[1] = x;
          p_z[2] = y;
          p_z[3] = z;
        }
LABEL_15:
        if ( *((_DWORD *)p_z + 4) == 2 )
        {
          v11->position.x = p_z[1];
          v11->position.y = p_z[2];
          v11->position.z = p_z[3];
          *((_BYTE *)v11 + 56) = (*((_BYTE *)p_z + 20) << 6) & 0x40 | *((_BYTE *)v11 + 56) & 0xBF;
        }
        v20 = *((_QWORD *)p_z - 2);
        v21 = *(p_z - 2);
        *(float *)&v20 = p_z[4];
        v22 = *(p_z - 1);
        v23 = *((_BYTE *)p_z + 20);
        v24 = *p_z;
        v25 = p_z[1];
        v26 = p_z[2];
        *((_QWORD *)p_y - 3) = v20;
        *(p_y - 4) = v21;
        *(p_y - 3) = v22;
        *(p_y - 2) = v24;
        v27 = p_z[3];
        *(p_y - 1) = v25;
        *p_y = v26;
        p_y[1] = v27;
        p_y[2] = *(float *)&v20;
        *((_BYTE *)p_y + 12) = v23;
        goto LABEL_18;
      }
      BYTE3(v6) = 0;
LABEL_18:
      ++v10;
      p_z += 10;
      if ( v10 >= 31 )
        break;
    }
    if ( BYTE3(v6) == 0 )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v29 = idEntity::GetPhysics(this: this->ai);
      v30 = (int)Physics->GetBounds(this: Physics, a2: -1);
      v31 = (float)(*(float *)(v30 + 20) - *(float *)(v30 + 8));
      v32 = (float *)v29->GetGravityNormal(this: v29);
      v33 = v11->position.y;
      v35 = v11->position.x;
      v36 = v32[2];
      v37 = *v32;
      v38 = v32[1];
      ai = this->ai;
      v78.z = (float)((float)v31 * (float)-v36) + v11->position.z;
      v78.x = (float)v35 + (float)((float)v31 * (float)-v37);
      v78.y = (float)v33 + (float)((float)v31 * (float)-v38);
      v39 = idEntity::GetPhysics(this: ai);
      v40 = (float *)v39->GetGravityNormal(this: v39);
      v41 = (float)(v40[1] * (float)dropHeight);
      v42 = (float)(*v40 * (float)dropHeight);
      v43 = v11->position.y;
      v44 = v11->position.x;
      v79.z = v11->position.z - (float)(v40[2] * (float)dropHeight);
      v79.y = (float)v43 - (float)v41;
      v79.x = (float)v44 - (float)v42;
      v45 = idClip::Translation(
              this: (idClip *)&v81,
              result: &clientGame->clip,
              a3: nullptr,
              start: &v78,
              end: &v79,
              clipModel: nullptr,
              startAxis: &mat3_identity,
              clipMask: 1,
              passEntityNumber: v55,
              moveClipModel: v56,
              userName: v57,
              a12: v58,
              a13: v59,
              a14: v60,
              a15: v61,
              a16: v62,
              a17: v63,
              a18: v64,
              a19: v65,
              a20: v66,
              a21: v67,
              a22: v68,
              a23: v69,
              a24: v70,
              a25: v71,
              a26: v72,
              a27: v73,
              a28: 0x1FFF,
              a29: v74,
              a30: false,
              a31: v75,
              a32: (int)"moveFSM update cached corners");
      v46 = v11->position.x;
      *((_DWORD *)p_y + 2) = 1;
      v47 = v11->position.y;
      v48 = v11->position.z;
      *((_QWORD *)p_y - 3) = *(_QWORD *)&v45->world;
      *p_y = v47;
      p_y[1] = v48;
      v49 = *((_BYTE *)v11 + 56);
      *(p_y - 1) = v46;
      *(p_y - 4) = v46;
      *(p_y - 3) = *p_y;
      *(p_y - 2) = p_y[1];
      *((_BYTE *)p_y + 12) = (v49 & 0x40) != 0;
    }
    ++v7;
    p_y += 10;
    ++v76;
  }
  while ( v76 < this->cachedCorners.num );
LABEL_22:
  this->cornerGroundInfo = v83;
  if ( v77.logIndex >= 0 )
  {
    pLog = v77.pLog;
    v51 = &v77.pLog->logEntries.list[v77.logIndex];
    v52 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v51->totalTicks;
    HIDWORD(totalTicks) = v51->parent;
    LODWORD(v54) = v52 - totalTicks;
    v51->totalTicks = v54;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// $M506218
// EA  : 0x82A73A20
// RVA : 0x00A73A20
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _M506218()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1728 + 1544));
}


// ========================================================================
// __unwind$505939
// EA  : 0x82A73A48
// RVA : 0x00A73A48
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_505939()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1728 + 120));
}


// ========================================================================
// ?PreMove@idAnimFSM@@IAAXXZ
// EA  : 0x82A73A78
// RVA : 0x00A73A78
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::PreMove(idAnimFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAIMoveInfo *cachedMoveInfoIntermediate; // r29
  float *p_x; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  idPhysics *v8; // r3
  float *p_destOrientation; // r11
  idVec3 *p_position; // r11
  idPhysics *v11; // r3
  idRenderWorld *v12; // r3
  idRenderWorld *v13; // r3
  idPLogScope v14[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idAnimFSM::PreMove");
  LODWORD(v2) = "idAnimFSM::PreMove";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v2, label: v3);
  cachedMoveInfoIntermediate = this->cachedMoveInfoIntermediate;
  if ( cachedMoveInfoIntermediate != nullptr || (cachedMoveInfoIntermediate = this->cachedMoveInfoDest) != nullptr )
  {
    p_x = &cachedMoveInfoIntermediate->destPosition.x;
  }
  else
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    p_x = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  }
  this->navNextPos.x = *p_x;
  this->navNextPos.y = p_x[1];
  this->navNextPos.z = p_x[2];
  if ( cachedMoveInfoIntermediate != nullptr )
  {
    v7 = &cachedMoveInfoIntermediate->destPosition.x;
  }
  else
  {
    v8 = idEntity::GetPhysics(this: this->ai);
    v7 = (float *)v8->GetOrigin(this: v8, a2: 0);
  }
  this->navFinalPos.x = *v7;
  this->navFinalPos.y = v7[1];
  p_destOrientation = (float *)&cachedMoveInfoIntermediate->destOrientation;
  this->navFinalPos.z = v7[2];
  if ( cachedMoveInfoIntermediate == nullptr )
    p_destOrientation = (float *)&this->orientBody.axis;
  this->navFinalAxis.mat[0].x = *p_destOrientation;
  this->navFinalAxis.mat[0].y = p_destOrientation[1];
  this->navFinalAxis.mat[0].z = p_destOrientation[2];
  this->navFinalAxis.mat[1].x = p_destOrientation[3];
  this->navFinalAxis.mat[1].y = p_destOrientation[4];
  this->navFinalAxis.mat[1].z = p_destOrientation[5];
  this->navFinalAxis.mat[2].x = p_destOrientation[6];
  this->navFinalAxis.mat[2].y = p_destOrientation[7];
  this->navFinalAxis.mat[2].z = p_destOrientation[8];
  if ( cachedMoveInfoIntermediate != nullptr )
  {
    if ( this->cachedCorners.num <= 0 )
    {
      v11 = idEntity::GetPhysics(this: this->ai);
      p_position = (idVec3 *)v11->GetOrigin(this: v11, a2: 0);
    }
    else
    {
      p_position = &this->cachedCorners.list->position;
    }
    this->navNextPos.x = p_position->x;
    this->navNextPos.y = p_position->y;
    this->navNextPos.z = p_position->z;
    idAnimBaseFSM::CacheNextPoints(this, destination: cachedMoveInfoIntermediate);
  }
  if ( ai_debugMoveFSM.valueInteger > 0 )
  {
    if ( this->nextArrivalCorner >= 0 )
    {
      v12 = gameLocal->GetRenderWorld(this: gameLocal);
      v12->DebugAxis(
        this: v12,
        a2: (const idVec4 *)&idColor::colorBlue,
        a3: &this->nextArrivalPos,
        a4: &this->nextArrivalAxis,
        a5: 1,
        a6: false);
    }
    if ( this->nextLinkCorner >= 0 )
    {
      v13 = gameLocal->GetRenderWorld(this: gameLocal);
      v13->DebugAxis(
        this: v13,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: &this->nextLinkPos,
        a4: &this->nextLinkAxis,
        a5: 1,
        a6: false);
    }
  }
  this->moveOrientationOnPath = false;
  idPLogScope::~idPLogScope(this: v14);
  RD_EventEnd();
}


// ========================================================================
// __unwind$506247
// EA  : 0x82A73CFC
// RVA : 0x00A73CFC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506247()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$506248
// EA  : 0x82A73D24
// RVA : 0x00A73D24
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506248()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?PointReachableAreaNum@idAnimFSM_AAS@@QBAHABVidVec3@@M@Z
// EA  : 0x82A73D58
// RVA : 0x00A73D58
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::PointReachableAreaNum(idAnimFSM_AAS *this, const idVec3 *point, double boundsScale)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  const idAAS2 *v7; // r3
  const idAAS2 *v8; // r30
  idAAS2_vtbl *v10; // r25
  int v11; // r3
  int v12; // r30
  idPLogScope v13[2]; // [sp+50h] [-70h] BYREF
  int v14; // [sp+60h] [-60h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::PointReachableAreaNum");
  LODWORD(v5) = "idAnimFSM_AAS::PointReachableAreaNum";
  HIDWORD(v5) = 6;
  idPLogScope::idPLogScope(this: v13, pl: &pLog, gMask: v5, label: v6);
  v7 = this->ai->GetAAS(this: this->ai);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v10 = v7->__vftable;
    v11 = (int)v7->DefaultSearchBounds(this: (idAAS2 *)&v14, result: (idBounds *)v7);
    v12 = v10->PointReachableAreaNum(
            this: (idAAS2 *)v8,
            a2: nullptr,
            a3: point,
            a4: (const idBounds *)v11,
            a5: 2,
            a6: 1);
    idPLogScope::~idPLogScope(this: v13);
    RD_EventEnd();
    return v12;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v13);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$506387
// EA  : 0x82A73E30
// RVA : 0x00A73E30
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506387()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 120));
}


// ========================================================================
// __unwind$506388
// EA  : 0x82A73E58
// RVA : 0x00A73E58
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506388()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?PathToPoint@idAnimFSM_AAS@@QBA_NAAUidAAS2Path@@HABVidVec3@@H1AAH@Z
// EA  : 0x82A73E88
// RVA : 0x00A73E88
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::PathToPoint(
        idAnimFSM_AAS *this,
        idAAS2Path *path,
        int myAreaNum,
        const idVec3 *myPos,
        int goalAreaNum,
        const idVec3 *goalPos,
        int *totalTravelTime)
{
  unsigned __int64 v14; // r6
  const char *v15; // r7
  const idAAS2 *v16; // r28
  const idAAS2 *v18; // r3
  idAI2 *ai; // r9
  const idAAS2 *v20; // r19
  unsigned int v21; // r17
  idAAS2_vtbl *v22; // r23
  int travelFlags; // r16
  int entityNumber; // r18
  unsigned __int64 v25; // r6
  const char *v26; // r7
  int v27; // r30
  idPLogScope v28; // [sp+68h] [-A8h] BYREF
  idPLogScope v29[20]; // [sp+70h] [-A0h] BYREF

  RD_EventBegin(name: "idAnimBaseFSM::PathToPoint");
  LODWORD(v14) = "idAnimBaseFSM::PathToPoint";
  HIDWORD(v14) = 6;
  idPLogScope::idPLogScope(this: &v28, pl: &pLog, gMask: v14, label: v15);
  v16 = this->ai->GetAAS(this: this->ai);
  if ( v16 != nullptr && myAreaNum != 0 && goalAreaNum != 0 )
  {
    if ( ai_showPath.valueInteger == -1 || ai_showPath.valueInteger == this->ai->entityNumber )
    {
      v18 = this->ai->GetAAS(this: this->ai);
      ai = this->ai;
      v20 = v18;
      v21 = ai->aiVolatile.aas.travelFlags & 0xFE78C83F;
      v22 = v18->__vftable;
      travelFlags = ai->aiVolatile.aas.travelFlags;
      entityNumber = ai->entityNumber;
      gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      ((void (__fastcall *)(const idAAS2 *, int, const idVec3 *, int, const idVec3 *, int, unsigned int, int))v22->ShowWalkPath)(
        a1: v20,
        a2: myAreaNum,
        a3: myPos,
        a4: goalAreaNum,
        a5: goalPos,
        a6: travelFlags,
        a7: v21,
        a8: entityNumber);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: goalPos,
        a4: 1000,
        a5: false);
    }
    RD_EventBegin(name: "idAAS2Local::WalkPathToGoal");
    LODWORD(v25) = "idAAS2Local::WalkPathToGoal";
    HIDWORD(v25) = 6;
    idPLogScope::idPLogScope(this: v29, pl: &pLog, gMask: v25, label: v26);
    v27 = ((int (__fastcall *)(const idAAS2 *, idAAS2Path *, const int, const idVec3 *, const int, const idVec3 *, int, unsigned int))v16->WalkPathToGoal)(
            a1: v16,
            a2: path,
            a3: myAreaNum,
            a4: myPos,
            a5: goalAreaNum,
            a6: goalPos,
            a7: this->ai->aiVolatile.aas.travelFlags,
            a8: this->ai->aiVolatile.aas.travelFlags & 0xFE78C83F);
    *totalTravelTime = 10 * path->travelTime;
    idPLogScope::~idPLogScope(this: v29);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v28);
    RD_EventEnd();
    return v27;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v28);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$506435
// EA  : 0x82A740FC
// RVA : 0x00A740FC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506435()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 120));
}


// ========================================================================
// __unwind$506436
// EA  : 0x82A74124
// RVA : 0x00A74124
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506436()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$506437
// EA  : 0x82A7414C
// RVA : 0x00A7414C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506437()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 121));
}


// ========================================================================
// __unwind$506438
// EA  : 0x82A74174
// RVA : 0x00A74174
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506438()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 112));
}


// ========================================================================
// ?PushEntityIfClose@idAnimFSM_AAS@@QBA_NPBVidEntity@@@Z
// EA  : 0x82A741A8
// RVA : 0x00A741A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::PushEntityIfClose(idAnimFSM_AAS *this, idAI2 *otherEntity)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idActor *v6; // r29
  double v8; // fp31
  idPhysics *Physics; // r15
  idPhysics *v10; // r16
  int v11; // r3
  float v12; // r6
  float v13; // r5
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r11
  int v15; // r3
  float v16; // r9
  float v17; // r8
  idAI2 *ai; // r11
  float *extendedClipModel; // r7
  double x; // fp27
  double y; // fp28
  double z; // fp23
  double v23; // fp0
  double v24; // fp21
  idPhysics *v25; // r3
  double v26; // fp1
  const idAAS2 *v27; // r21
  double v28; // fp30
  double v29; // fp26
  double v30; // fp25
  double v31; // fp24
  int AreaNum; // r19
  float *v33; // r26
  const idAAS2 *aas; // r3
  idRenderWorld_vtbl *v35; // r11
  double v36; // fp8
  double v37; // fp6
  double v38; // fp4
  double v39; // fp28
  double v42; // fp1
  double v43; // fp5
  double v44; // fp1
  double v45; // fp5
  double v46; // fp31
  const idVec3 *v47; // r3
  idVec3 *NearestPerpendicular; // r3
  double v49; // fp0
  double v50; // fp13
  double v51; // fp10
  double v52; // fp7
  double v55; // fp3
  double v56; // fp4
  double v57; // fp3
  double v58; // fp13
  double v59; // fp0
  double v60; // fp13
  idVec3 v61; // [sp+60h] [-230h] BYREF
  idVec3 v62; // [sp+70h] [-220h] BYREF
  float v63; // [sp+80h] [-210h] BYREF
  float v64; // [sp+84h] [-20Ch]
  float v65; // [sp+88h] [-208h]
  float v66; // [sp+90h] [-200h] BYREF
  float v67; // [sp+94h] [-1FCh]
  float v68; // [sp+98h] [-1F8h]
  idAI2 *p_collisionResidency; // [sp+9Ch] [-1F4h]
  idVec3 v70; // [sp+A0h] [-1F0h] BYREF
  float v71; // [sp+B0h] [-1E0h] BYREF
  float v72; // [sp+B4h] [-1DCh]
  float v73; // [sp+B8h] [-1D8h]
  idRotation v74; // [sp+C0h] [-1D0h] BYREF
  int v75; // [sp+104h] [-18Ch]
  int v76; // [sp+108h] [-188h]
  float v77; // [sp+10Ch] [-184h]
  float v78; // [sp+110h] [-180h]
  float v79; // [sp+114h] [-17Ch]
  int v80; // [sp+118h] [-178h]
  int v81; // [sp+11Ch] [-174h]
  float v82; // [sp+120h] [-170h]
  float v83; // [sp+124h] [-16Ch]
  float v84; // [sp+128h] [-168h]
  int v85; // [sp+12Ch] [-164h]
  int v86; // [sp+130h] [-160h]
  int v87; // [sp+134h] [-15Ch]
  int v88; // [sp+138h] [-158h]
  int v89; // [sp+13Ch] [-154h]
  int v90; // [sp+140h] [-150h]
  idRotation v91[2]; // [sp+150h] [-140h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::PushEntityIfClose");
  LODWORD(v4) = "idAnimFSM_AAS::PushEntityIfClose";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v74.vec.y, pl: &pLog, gMask: v4, label: v5);
  v6 = idActor::CastTo(c: otherEntity);
  if ( v6->IsDead(this: v6) )
  {
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v74.vec.y);
    RD_EventEnd();
    return 0;
  }
  else
  {
    v8 = 8100.0;
    if ( idAI2::CastTo(c: otherEntity) != nullptr )
      v8 = 3025.0;
    Physics = idEntity::GetPhysics(this: this->ai);
    v10 = idEntity::GetPhysics(this: otherEntity);
    v11 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v12 = *(float *)(v11 + 4);
    v13 = *(float *)(v11 + 8);
    GetOrigin = v10->GetOrigin;
    v70.x = *(float *)v11;
    v70.y = v12;
    v70.z = v13;
    v15 = (int)GetOrigin(this: v10, a2: 0);
    v16 = *(float *)(v15 + 4);
    v17 = *(float *)(v15 + 8);
    ai = this->ai;
    v63 = *(float *)v15;
    v64 = v16;
    v65 = v17;
    extendedClipModel = (float *)ai->aiVolatile.physics.extendedClipModel;
    p_collisionResidency = ai;
    if ( extendedClipModel != nullptr )
    {
      p_collisionResidency = (idAI2 *)(extendedClipModel + 8);
      x = extendedClipModel[8];
      y = extendedClipModel[9];
      z = extendedClipModel[10];
    }
    else
    {
      z = v70.z;
      y = v70.y;
      x = v70.x;
    }
    v23 = (float)((float)((float)(v63 - (float)x) * (float)(v63 - (float)x))
                + (float)((float)(v64 - (float)y) * (float)(v64 - (float)y)));
    if ( v23 < v8 )
    {
      v24 = __fsqrts(v23);
      v25 = idEntity::GetPhysics(this: otherEntity);
      v25->GetLinearVelocity(this: (idPhysics *)&v61, result: (idVec3 *)v25, a3: 0);
      if ( v24 < 60.0 )
      {
        v62.z = (float)z - v65;
        v62.x = (float)x - v63;
        v62.y = (float)y - v64;
        if ( v24 < 55.0 )
        {
          v70.z = v65 - (float)z;
          v70.y = v64 - (float)y;
          v70.x = v63 - (float)x;
          v26 = idVec3::NormalizeFast(this: &v70);
          v27 = (const idAAS2 *)((int (__fastcall *)(idAI2 *, double))this->ai->GetAAS)(a1: this->ai, a2: v26);
          v28 = -1.0;
          v29 = 0.0;
          v30 = 0.0;
          v31 = 0.0;
          AreaNum = idActor::GetAreaNum(this: v6, aas: v27);
          v33 = (float *)ANGLES_TO_TRY;
          do
          {
            if ( v28 >= 1.0 )
              break;
            idRotation::idRotation(this: v91, rotationOrigin: &vec3_origin, rotationVec: &vec3_up, rotationAngle: *v33);
            idRotation::operator*(this: &v74, result: v91, v: &v70);
            v74.axis.mat[1].z = 0.0;
            v74.axis.mat[2].x = 0.0;
            *(_DWORD *)&v74.axisValid = 0;
            v74.axis.mat[2].y = 0.0;
            v75 = 0;
            v74.axis.mat[2].z = 0.0;
            v76 = 0;
            v77 = 0.0;
            v80 = 0;
            v78 = 0.0;
            v81 = 0;
            v79 = 0.0;
            v85 = 0;
            v82 = 0.0;
            v86 = 0;
            v83 = 0.0;
            v84 = 0.0;
            v68 = (float)z + (float)(v74.origin.z * (float)65.0);
            v67 = (float)y + (float)(v74.origin.y * (float)65.0);
            v87 = 0;
            v66 = (float)(v74.origin.x * (float)65.0) + (float)x;
            v88 = 0;
            v89 = 0;
            v90 = 0;
            aas = idActor::GetAASPosition(this: this->ai, aas: v27)->aas;
            ((void (__fastcall *)(const idAAS2 *, float *, float *, int, float *, int, _DWORD, _DWORD))aas->TraceFloor)(
              a1: aas,
              a2: &v74.axis.mat[1].z,
              a3: &v63,
              a4: AreaNum,
              a5: &v66,
              a6: 40,
              a7: 0,
              a8: 0);
            if ( v74.axis.mat[1].z > v28 )
            {
              v29 = v66;
              v28 = v74.axis.mat[1].z;
              v30 = v67;
              v31 = v68;
            }
            if ( ai_debugPushPlayer.valueInteger != 0 )
            {
              v35 = clientGame->renderWorld->__vftable;
              if ( v74.axis.mat[1].z >= 1.0 )
              {
                ((void (__fastcall *)(double))v35->DebugArrow)(a1: 16.0);
              }
              else
              {
                ((void (*)(void))v35->DebugLine)();
                v74.axis.mat[0].y = v65 + (float)((float)(v68 - v65) * v74.axis.mat[1].z);
                v74.axis.mat[0].x = v64 + (float)((float)(v67 - v64) * v74.axis.mat[1].z);
                v74.angle = (float)((float)(v66 - v63) * v74.axis.mat[1].z) + v63;
                clientGame->renderWorld->DebugPoint(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorWhite,
                  a3: (const idVec3 *)&v74.angle,
                  a4: 16,
                  a5: false);
              }
            }
            ++v33;
          }
          while ( (int)v33 < (int)&_real_453d1000 );
          v36 = (float)((float)v30 - v64);
          v37 = (float)((float)v29 - v63);
          v38 = (float)((float)v31 - v65);
          v39 = __fsqrts((float)((float)(v61.y * v61.y) + (float)((float)(v61.x * v61.x) + (float)(v61.z * v61.z))));
          _FP5 = (float)((float)((float)((float)((float)v31 - v65) * (float)((float)v31 - v65))
                               + (float)((float)((float)((float)v29 - v63) * (float)((float)v29 - v63))
                                       + (float)((float)((float)v30 - v64) * (float)((float)v30 - v64))))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f2, f5, f7, f0 }
          v42 = __frsqrte(_FP2);
          v43 = (float)((float)-(float)((float)((float)((float)v42
                                                      * (float)((float)((float)((float)((float)v31 - v65)
                                                                              * (float)((float)v31 - v65))
                                                                      + (float)((float)((float)((float)v29 - v63)
                                                                                      * (float)((float)v29 - v63))
                                                                              + (float)((float)((float)v30 - v64)
                                                                                      * (float)((float)v30 - v64))))
                                                              * (float)0.5))
                                              * (float)v42)
                                      - (float)1.5)
                      * (float)v42);
          v44 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                      * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v42)
                                                                      - (float)1.5)
                                                      * (float)v42)
                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v42
                                                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                                                              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                      * (float)0.5))
                                                                      * (float)v42)
                                                              - (float)1.5)
                                              * (float)v42))
                              - (float)1.5);
          v45 = (float)((float)-(float)((float)((float)((float)((float)v44 * (float)v43)
                                                      * (float)((float)((float)((float)((float)v31 - v65)
                                                                              * (float)((float)v31 - v65))
                                                                      + (float)((float)((float)((float)v29 - v63)
                                                                                      * (float)((float)v29 - v63))
                                                                              + (float)((float)((float)v30 - v64)
                                                                                      * (float)((float)v30 - v64))))
                                                              * (float)0.5))
                                              * (float)((float)v44 * (float)v43))
                                      - (float)1.5)
                      * (float)((float)v44 * (float)v43));
          v62.z = (float)((float)v31 - v65) * (float)v45;
          v62.x = (float)((float)v29 - v63) * (float)v45;
          v62.y = (float)((float)v30 - v64) * (float)v45;
          if ( (float)((float)(v62.y * v61.y) + (float)((float)(v62.x * v61.x) + (float)(v62.z * v61.z))) < 0.0
            && v39 > idMath::FLT_SMALLEST_NON_DENORMAL )
          {
            v46 = (float)((float)((float)((float)((float)((float)v30 - v64) * (float)v45) * v61.y)
                                + (float)((float)((float)((float)((float)v29 - v63) * (float)v45) * v61.x)
                                        + (float)((float)((float)((float)v31 - v65) * (float)v45) * v61.z)))
                        / (float)v39);
            v47 = v10->GetGravityNormal(this: v10);
            NearestPerpendicular = idGeometry::FindNearestPerpendicular(
                                     result: &v74.origin,
                                     input: &v62,
                                     up: v47,
                                     hint: &v61);
            v49 = NearestPerpendicular->x;
            v61.x = NearestPerpendicular->x;
            v50 = NearestPerpendicular->y;
            v61.y = NearestPerpendicular->y;
            v51 = NearestPerpendicular->z;
            v61.x = (float)((float)((float)v46 + (float)1.0) * (float)v39) * (float)v49;
            v61.y = (float)v50 * (float)((float)((float)v46 + (float)1.0) * (float)v39);
            v61.z = (float)v51 * (float)((float)((float)v46 + (float)1.0) * (float)v39);
          }
          Physics->GetLinearVelocity(this: (idPhysics *)&v71, result: (idVec3 *)Physics, a3: 0);
          v52 = (float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)));
          _FP6 = (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f4, f6, f7, f13 }
          v55 = __frsqrte(_FP4);
          v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72))) * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55)
                                                      * (float)((float)((float)(v71 * v71)
                                                                      + (float)((float)(v73 * v73) + (float)(v72 * v72)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v55
                                                                                      * (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)))
                                                                                              * (float)0.5))
                                                                              * (float)v55)
                                                                      - (float)1.5)
                                                      * (float)v55))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v55
                                                              * (float)((float)((float)(v71 * v71)
                                                                              + (float)((float)(v73 * v73)
                                                                                      + (float)(v72 * v72)))
                                                                      * (float)0.5))
                                                      * (float)v55)
                                              - (float)1.5)
                              * (float)v55));
          v57 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72))) * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55)
                                                              * (float)((float)((float)(v71 * v71)
                                                                              + (float)((float)(v73 * v73)
                                                                                      + (float)(v72 * v72)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                                              * (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72))) * (float)0.5))
                                                                                      * (float)v55)
                                                                              - (float)1.5)
                                                              * (float)v55))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v55
                                                                      * (float)((float)((float)(v71 * v71)
                                                                                      + (float)((float)(v73 * v73)
                                                                                              + (float)(v72 * v72)))
                                                                              * (float)0.5))
                                                              * (float)v55)
                                                      - (float)1.5)
                                      * (float)v55))
                      * (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)))
                              * (float)0.5));
          v71 = v71 * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56);
          v72 = v72 * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56);
          v73 = v73 * (float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56);
          v58 = (float)((float)((float)-(float)((float)((float)v57 * (float)v56) - (float)1.5) * (float)v56) * (float)v52);
          if ( v24 >= 45.0 )
          {
            v59 = 25.0;
            if ( v58 > 6.0 )
            {
              if ( v58 < 60.0 )
                v60 = (float)((float)((float)((float)((float)((float)-(float)((float)((float)v57 * (float)v56)
                                                                            - (float)1.5)
                                                            * (float)v56)
                                                    * (float)v52)
                                            - (float)6.0)
                                    * (float)0.37037036)
                            + (float)5.0);
              else
                v60 = 25.0;
            }
            else
            {
              v60 = 5.0;
            }
            if ( v24 > 45.0 )
              v59 = (float)((float)((float)((float)((float)v60 - (float)25.0) * (float)((float)v24 - (float)45.0))
                                  * (float)0.1)
                          + (float)25.0);
          }
          else if ( v24 > 30.0 )
          {
            v59 = (float)-(float)((float)((float)((float)v24 - (float)30.0) * (float)1.6666666) - (float)50.0);
          }
          else
          {
            v59 = 50.0;
          }
          v61.y = v61.y + (float)(v62.y * (float)v59);
          v61.z = v61.z + (float)(v62.z * (float)v59);
          v61.x = (float)((float)v59 * v62.x) + v61.x;
          v10->SetLinearVelocity(this: v10, a2: &v61, a3: 0);
        }
        if ( v10->type == PHYSICS_PLAYER )
        {
          idVec3::NormalizeFast(this: &v62);
          *(float *)&v10[25].collisionResidency = v62.x;
          *((float *)&v10[25].collisionResidency + 1) = v62.y;
          p_collisionResidency = (idAI2 *)&v10[25].collisionResidency;
          *(float *)&v10[26].__vftable = v62.z;
          *((float *)&v10[25].residencyQuery.index + 1) = 1.0;
        }
      }
    }
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v74.vec.y);
    RD_EventEnd();
    return 1;
  }
}


// ========================================================================
// __unwind$506593
// EA  : 0x82A74960
// RVA : 0x00A74960
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506593()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 656 + 404));
}


// ========================================================================
// __unwind$506594
// EA  : 0x82A74988
// RVA : 0x00A74988
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_506594()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 656 + 208));
}


// ========================================================================
// ?UpdateAimBlends@idAnimBaseFSM@@IAAXXZ
// EA  : 0x82A749B8
// RVA : 0x00A749B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::UpdateAimBlends(idAnimBaseFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  char HasFocus; // r3
  idAI2 *ai; // r11
  idFocusInfo *ptr; // r3
  bool v7; // zf
  idPhysics *Physics; // r3
  float *v9; // r3
  idAI2 *v10; // r11
  double v11; // fp12
  double z; // fp9
  double v13; // fp5
  double x; // fp7
  bool v15; // r4
  idPLogScope v16; // [sp+58h] [-58h] BYREF
  idVec3 v17; // [sp+60h] [-50h] BYREF
  idVec3 v18; // [sp+70h] [-40h] BYREF
  idMat3 v19; // [sp+80h] [-30h] BYREF

  RD_EventBegin(name: "idAnimBaseFSM::UpdateAimBlends");
  LODWORD(v2) = "idAnimBaseFSM::UpdateAimBlends";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v16, pl: &pLog, gMask: v2, label: v3);
  HasFocus = idFocusInfo::HasFocus(this: this->ai->aiVolatile.focus.foci.ptr);
  ai = this->ai;
  v7 = HasFocus != 0;
  ptr = ai->aiVolatile.focus.foci.ptr;
  if ( !v7 )
    ptr = &ai->aiVolatile.focus.foci.ptr[1];
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: ptr) != 0
    && (unsigned __int8)idAnimBaseFSM::TreeUsesFullBodyAiming(this) != 0 )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v10 = this->ai;
    v11 = (float)(v9[2] + (float)50.0);
    z = v10->aiVolatile.focus.foci.ptr[0].idealFocusPoint.z;
    v13 = (float)(v10->aiVolatile.focus.foci.ptr[0].idealFocusPoint.x - *v9);
    v18.y = v10->aiVolatile.focus.foci.ptr[0].idealFocusPoint.y - v9[1];
    v18.x = v13;
    v18.z = (float)z - (float)v11;
    idVec3::NormalizeFast(this: &v18);
    idVec3::ToAngles(this: &v17, result: (idAngles *)&v18);
    idMat3::ToAngles(this: &v19, result: (idAngles *)&this->ai->actorVolatile);
    v17.x = v17.x - v19.mat[0].x;
    v17.y = v17.y - v19.mat[0].y;
    v17.z = v17.z - v19.mat[0].z;
    idAngles::Normalize180(this: (idAngles *)&v17);
    x = v17.x;
    v15 = true;
    this->animBlendVars.bodyAimYaw.value = v17.y;
    this->animBlendVars.bodyAimPitch.value = x;
  }
  else
  {
    v15 = false;
    this->animBlendVars.bodyAimYaw.value = 0.0;
    this->animBlendVars.bodyAimPitch.value = 0.0;
  }
  idAI2::SetSuppressHeadTracking(this: this->ai, suppress: v15);
  idPLogScope::~idPLogScope(this: &v16);
  RD_EventEnd();
}


// ========================================================================
// __unwind$507115
// EA  : 0x82A74B48
// RVA : 0x00A74B48
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507115()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 140));
}


// ========================================================================
// __unwind$507116
// EA  : 0x82A74B70
// RVA : 0x00A74B70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507116()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?SubmitNavTraces@idAnimFSM_AAS@@UAAXXZ
// EA  : 0x82A74BA0
// RVA : 0x00A74BA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::SubmitNavTraces(idAnimFSM_AAS *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int numTraces; // r9
  int v5; // r5
  int v6; // r6
  float *v7; // r7
  float *p_y; // r8
  float *p_z; // r9
  idVec3 *p_end; // r10
  float *v11; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v13; // r30
  int v14; // r3
  __int64 totalTicks; // r11
  __int64 v16; // r9
  idPLogScope v17; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::SubmitNavTraces");
  LODWORD(v2) = "idAnimFSM_AAS::SubmitNavTraces";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v17, pl: &::pLog, gMask: v2, label: v3);
  numTraces = this->obstacleTraces.numTraces;
  this->obstacleTraces.prevNumTraces = numTraces;
  memcpy(Dst: this->obstacleTraces.prevTraceNumbers, Src: this->obstacleTraces.traceNumbers, Size: 4 * numTraces);
  if ( this->numNewNavTraces <= 0 )
  {
    this->obstacleTraces.numTraces = 0;
  }
  else
  {
    v5 = 2;
    v6 = 0;
    v7 = &this->obstacleTraces.traceFractions[255];
    p_y = &this->obstacleTraces.traces[255].end.y;
    p_z = &this->lastPath.obstacleRoute.areas[10].end.z;
    p_end = &this->lastPath.obstacleRoute.areas[10].end;
    v11 = &this->navTraces.ptr[0].stop.y;
    do
    {
      if ( *((_BYTE *)v11 + 12) != 0 )
      {
        p_end[1].x = *(v11 - 4);
        ++v6;
        p_end[1].y = *(v11 - 3);
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = *(v11 - 1);
        p_z[4] = *v11;
        *((_DWORD *)v7 + 1) = v5 - 2;
        p_y[1] = -1.0;
        *((_BYTE *)v11 + 12) = 0;
        ++p_y;
        ++v7;
        p_z += 4;
      }
      if ( *((_BYTE *)v11 + 44) != 0 )
      {
        p_end[1].x = v11[4];
        ++v6;
        p_end[1].y = v11[5];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[7];
        p_z[4] = v11[8];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5 - 1;
        *((_BYTE *)v11 + 44) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 76) != 0 )
      {
        ++v6;
        p_end[1].x = v11[12];
        p_end[1].y = v11[13];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[15];
        p_z[4] = v11[16];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5;
        *((_BYTE *)v11 + 76) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 108) != 0 )
      {
        p_end[1].x = v11[20];
        ++v6;
        p_end[1].y = v11[21];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[23];
        p_z[4] = v11[24];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5 + 1;
        *((_BYTE *)v11 + 108) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 140) != 0 )
      {
        p_end[1].x = v11[28];
        ++v6;
        p_end[1].y = v11[29];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[31];
        p_z[4] = v11[32];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5 + 2;
        *((_BYTE *)v11 + 140) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 172) != 0 )
      {
        p_end[1].x = v11[36];
        ++v6;
        p_end[1].y = v11[37];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[39];
        p_z[4] = v11[40];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5 + 3;
        *((_BYTE *)v11 + 172) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 204) != 0 )
      {
        p_end[1].x = v11[44];
        ++v6;
        p_end[1].y = v11[45];
        p_end = (idVec3 *)((char *)p_end + 16);
        p_z[3] = v11[47];
        p_z[4] = v11[48];
        p_z += 4;
        p_y[1] = -1.0;
        *((_DWORD *)v7 + 1) = v5 + 4;
        *((_BYTE *)v11 + 204) = 0;
        ++p_y;
        ++v7;
      }
      if ( *((_BYTE *)v11 + 236) != 0 )
      {
        p_end[1].x = v11[52];
        ++v6;
        p_end = (idVec3 *)((char *)p_end + 16);
        p_end->x = v11[53];
        p_z[3] = v11[55];
        p_z += 4;
        *p_z = v11[56];
        *++p_y = -1.0;
        *(_DWORD *)++v7 = v5 + 5;
        *((_BYTE *)v11 + 236) = 0;
      }
      v5 += 8;
      v11 += 64;
    }
    while ( v5 - 2 < 256 );
    this->obstacleTraces.numTraces = v6;
    this->numNewNavTraces = 0;
  }
  if ( v17.logIndex >= 0 )
  {
    pLog = v17.pLog;
    v13 = &v17.pLog->logEntries.list[v17.logIndex];
    v14 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v13->totalTicks;
    HIDWORD(totalTicks) = v13->parent;
    LODWORD(v16) = v14 - totalTicks;
    v13->totalTicks = v16;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$507262
// EA  : 0x82A74F00
// RVA : 0x00A74F00
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507262()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// ?RecordNavTraceResults@idAnimFSM_AAS@@UAAXXZ
// EA  : 0x82A74F30
// RVA : 0x00A74F30
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::RecordNavTraceResults(idAnimFSM_AAS *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r9
  float *p_y; // r10
  int v6; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v8; // r30
  int v9; // r3
  __int64 totalTicks; // r11
  __int64 v11; // r9
  idPLogScope v12; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::RecordNavTraceResults");
  LODWORD(v2) = "idAnimFSM_AAS::RecordNavTraceResults";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v12, pl: &::pLog, gMask: v2, label: v3);
  v4 = 0;
  if ( this->obstacleTraces.prevNumTraces > 0 )
  {
    p_y = &this->obstacleTraces.traces[255].end.y;
    do
    {
      v6 = *((_DWORD *)p_y + 257);
      if ( v6 < 0 )
        break;
      ++p_y;
      ++v4;
      this->navTraces.ptr[v6].fraction = *p_y;
    }
    while ( v4 < this->obstacleTraces.prevNumTraces );
  }
  if ( v12.logIndex >= 0 )
  {
    pLog = v12.pLog;
    v8 = &v12.pLog->logEntries.list[v12.logIndex];
    v9 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v8->totalTicks;
    HIDWORD(totalTicks) = v8->parent;
    LODWORD(v11) = v9 - totalTicks;
    v8->totalTicks = v11;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$507335
// EA  : 0x82A74FF0
// RVA : 0x00A74FF0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507335()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// ??0idAnimFSM_AAS@@QAA@XZ
// EA  : 0x82A75020
// RVA : 0x00A75020
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM_AAS *__fastcall idAnimFSM_AAS::idAnimFSM_AAS(idAnimFSM_AAS *this)
{
  idAnimBaseFSM::idAnimBaseFSM(this);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_AAS_vtbl *)&idAnimFSM::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM::`vftable'{for `idAIMoveInterface'};
  idArray<idAnimFSM::cornerClipInfo_t,31>::idArray<idAnimFSM::cornerClipInfo_t,31>(this: &this->cornerGroundInfo);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_AAS_vtbl *)&idAnimFSM_AAS::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM_AAS::`vftable'{for `idAIMoveInterface'};
  idObstacleAvoidance::idObstacleAvoidance(this: &this->oa);
  idAAS2Path::idAAS2Path(this: &this->lastPath);
  idAnimBaseFSM::Reset(this);
  memset(Dst: &this->lastPath, Val: 0, Size: sizeof(this->lastPath));
  return this;
}


// ========================================================================
// __unwind$507388
// EA  : 0x82A750AC
// RVA : 0x00A750AC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507388()
{
  int v0; // r12

  idAnimFSM::~idAnimFSM(this: *(idAnimFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$507389
// EA  : 0x82A750D4
// RVA : 0x00A750D4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507389()
{
  int v0; // r12

  idObstacleAvoidance::~idObstacleAvoidance(this: (idObstacleAvoidance *)(*(_DWORD *)(v0 - 112 + 132) + 13320));
}


// ========================================================================
// ??0idAnimFSM_NP@@QAA@XZ
// EA  : 0x82A75168
// RVA : 0x00A75168
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

idAnimFSM_NP *__fastcall idAnimFSM_NP::idAnimFSM_NP(idAnimFSM_NP *this)
{
  idAnimBaseFSM::idAnimBaseFSM(this);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_NP_vtbl *)&idAnimFSM::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM::`vftable'{for `idAIMoveInterface'};
  idArray<idAnimFSM::cornerClipInfo_t,31>::idArray<idAnimFSM::cornerClipInfo_t,31>(this: &this->cornerGroundInfo);
  this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_NP_vtbl *)&idAnimFSM_NP::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM_NP::`vftable'{for `idAIMoveInterface'};
  this->groundNavigator = nullptr;
  idNpLink::idNpLink(this: &this->linkTraversing);
  idNpCornerInfo::idNpCornerInfo(this: &this->linkEndCorner);
  idAnimBaseFSM::Reset(this);
  this->lastTransitionCorner = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$507428
// EA  : 0x82A75228
// RVA : 0x00A75228
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507428()
{
  int v0; // r12

  idAnimFSM::~idAnimFSM(this: *(idAnimFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$507429
// EA  : 0x82A75250
// RVA : 0x00A75250
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507429()
{
  int v0; // r12

  idNpLink::~idNpLink(this: (idNpLink *)(*(_DWORD *)(v0 - 112 + 132) + 13324));
}


// ========================================================================
// __unwind$507430
// EA  : 0x82A7527C
// RVA : 0x00A7527C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507430()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(*(_DWORD *)(v0 - 112 + 132) + 13332));
}


// ========================================================================
// ?UpdateCachedCorners@idAnimFSM_NP@@UAAXXZ
// EA  : 0x82A75310
// RVA : 0x00A75310
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_NP::UpdateCachedCorners(idAnimFSM_NP *this)
{
  idStaticList<idNpCornerInfo,31> *p_cachedCorners; // r29
  idAnimFSM_NP_vtbl *v3; // r10
  int num; // r28
  int size; // r8
  idNpNavigator *groundNavigator; // r3
  idNpCornerInfo *v7; // r5
  int v8; // r28
  int v9; // r11
  idAIMoveInfo *cachedMoveInfoIntermediate; // r29
  const idNpAreaHandle *v11; // r3
  const idAINavPowerMoverParms *v12; // r3
  double probeDropHeight; // fp0
  idPhysics *Physics; // r3
  int v15; // r3
  idStreamFileLog v16; // [sp+50h] [-40h] BYREF

  p_cachedCorners = &this->cachedCorners;
  if ( this->cachedCorners.size < 0 )
    idList<idNpCornerInfo,5>::~idList<idNpCornerInfo,5>(this: &this->cachedCorners);
  p_cachedCorners->num = __CFADD__(-p_cachedCorners->size, p_cachedCorners->size ^ 0x80000000)
                       ? 0
                       : p_cachedCorners->size;
  if ( idNavigationSpace::IsValid(this: &this->linkTraversing) )
    idList<idNpCornerInfo,5>::Append(this: p_cachedCorners, obj: &this->linkEndCorner);
  HIBYTE(v16.mutex.handle) = 0;
  v3 = this->idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable;
  *(float *)&v16.entries = 3.4028235e38;
  HIBYTE(v16.mutex.handle) = v3->AddCornerAtEveryArea(this);
  num = this->cachedCorners.num;
  size = this->cachedCorners.size;
  groundNavigator = this->groundNavigator;
  v7 = &p_cachedCorners->list[num];
  v16.numEntries = num;
  v8 = idNpNavigator::GetNextNCorners(
         this: groundNavigator,
         maxCorners: size - num,
         infoOut: v7,
         parms: (const idNpNavigator::idNextCornerParms *)&v16.entries)
     + num;
  if ( v8 <= p_cachedCorners->size
    || (unsigned __int8)idList<idNpCornerInfo,5>::Resize(this: p_cachedCorners, newsize: v8) != 0 )
  {
    v9 = p_cachedCorners->size;
    if ( v8 < v9 )
      v9 = v8;
    p_cachedCorners->num = v9;
  }
  cachedMoveInfoIntermediate = this->cachedMoveInfoIntermediate;
  if ( cachedMoveInfoIntermediate != nullptr || (cachedMoveInfoIntermediate = this->cachedMoveInfoDest) != nullptr )
  {
    idMD6PhaseTrack::idMD6PhaseTrack(this: &v16);
    idNpNavigator::SetGoalOrigin(
      this: this->groundNavigator,
      goalPos: &cachedMoveInfoIntermediate->destPosition,
      goalArea: v11);
    idNpAreaHandle::~idNpAreaHandle(this: (idNpAreaHandle *)&v16);
    v12 = this->ai->GetNavParms(this: this->ai);
    if ( v12 == nullptr || (probeDropHeight = v12->probe.probeDropHeight) == 0.0 )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v15 = (int)Physics->GetBounds(this: Physics, a2: -1);
      probeDropHeight = (float)(*(float *)(v15 + 20) - *(float *)(v15 + 8));
    }
    idAnimFSM::ClampCachedCornersToGround(this, dropHeight: probeDropHeight);
  }
  else
  {
    idAnimBaseFSM::ClearCachedCorners(this);
  }
}


// ========================================================================
// __unwind$507483
// EA  : 0x82A754C0
// RVA : 0x00A754C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507483()
{
  int v0; // r12

  idNpAreaHandle::~idNpAreaHandle(this: (idNpAreaHandle *)(v0 - 144 + 80));
}


// ========================================================================
// ?MoveAIAlongPath@idAnimFSM@@IAAXABUidAIMoveInfo@@@Z
// EA  : 0x82A754F0
// RVA : 0x00A754F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::MoveAIAlongPath(idAnimFSM *this, const idAIMoveInfo *moveInfo)
{
  unsigned __int64 v3; // r6
  const char *v4; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  idPhysics *Physics; // r3
  int v7; // r3
  idAI2 *ai; // r3
  float v9; // r7
  float v10; // r6
  float v11; // r5
  idPhysics *v12; // r3
  int v13; // r3
  float v14; // r9
  int *v15; // r6
  float v16; // r8
  float *p_z; // r7
  int v18; // ctr
  float v19; // r10
  idPLog **p_pLog; // r7
  float *v21; // r11
  int i; // ctr
  double v23; // fp30
  idAnimFSM_vtbl *v24; // r29
  __int64 v25; // r5
  idMat3 *p_axis; // r11
  float y; // r8
  float z; // r6
  idAI2 *v29; // r4
  double v32; // fp3
  double v33; // fp6
  double v34; // fp3
  unsigned __int64 v35; // r6
  const char *v36; // r7
  idPhysics *v37; // r3
  float *v38; // r3
  double v39; // fp31
  idPhysics *v40; // r28
  __int64 v41; // r10
  double v42; // fp30
  const idVec3 *v43; // r3
  double x; // fp0
  double v45; // fp13
  char v46; // r11
  idAI2 *v47; // r29
  int (*GetGameMsPerFrame)(void); // ctr
  unsigned int v49; // r3
  const idVec3 *v50; // r4
  idAI2 *v51; // r29
  unsigned int v52; // r3
  double pitch; // fp0
  double roll; // fp13
  double yaw; // fp12
  double v56; // fp31
  const char *v57; // r3
  idAngles v58; // [sp+50h] [-1A0h] BYREF
  idVec3 v59; // [sp+60h] [-190h] BYREF
  idVec3 v60; // [sp+70h] [-180h] BYREF
  idAngles v61; // [sp+80h] [-170h] BYREF
  _QWORD v62[2]; // [sp+90h] [-160h] BYREF
  idVec3 v63; // [sp+A0h] [-150h] BYREF
  idVec3 v64; // [sp+B0h] [-140h] BYREF
  idVec3 v65; // [sp+C0h] [-130h] BYREF
  float v66; // [sp+D0h] [-120h] BYREF
  float v67; // [sp+D4h] [-11Ch]
  float v68; // [sp+D8h] [-118h]
  int v69; // [sp+DCh] [-114h] BYREF
  idMat3 v70; // [sp+E0h] [-110h] BYREF
  idMat3 v71; // [sp+110h] [-E0h] BYREF
  idPLogScope v72; // [sp+138h] [-B8h] BYREF
  idMat3 v73; // [sp+140h] [-B0h] BYREF
  idMat3 v74[2]; // [sp+170h] [-80h] BYREF

  RD_EventBegin(name: "idAnimFSM::MoveAIALongPath");
  LODWORD(v3) = "idAnimFSM::MoveAIALongPath";
  HIDWORD(v3) = 6;
  idPLogScope::idPLogScope(this: &v72, pl: &pLog, gMask: v3, label: v4);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
  idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
  Physics = idEntity::GetPhysics(this: this->ai);
  v7 = (int)Physics->GetGravityNormal(this: Physics);
  v9 = *(float *)v7;
  v10 = *(float *)(v7 + 4);
  v11 = *(float *)(v7 + 8);
  ai = this->ai;
  v64.x = v9;
  v64.y = v10;
  v64.z = v11;
  v12 = idEntity::GetPhysics(this: ai);
  v13 = (int)v12->GetOrigin(this: v12, a2: 0);
  v14 = *(float *)v13;
  v15 = &v69;
  v16 = *(float *)(v13 + 4);
  p_z = &this->orientBody.idealDir.z;
  v18 = 9;
  v19 = *(float *)(v13 + 8);
  v58.pitch = *(float *)v13;
  v58.yaw = v16;
  v58.roll = v19;
  do
  {
    *++v15 = *(_DWORD *)++p_z;
    --v18;
  }
  while ( v18 != 0 );
  p_pLog = &v72.pLog;
  v21 = &this->orientBody.idealDir.z;
  for ( i = 9; i != 0; --i )
    *++p_pLog = *(idPLog **)++v21;
  v63.y = v16;
  v63.x = v14;
  v63.z = v19;
  v65.x = 1.0;
  v65.y = 1.0;
  v65.z = 1.0;
  idTreeAnimator::ApplyOriginDeltas(
    this: TreeAnimatorFromPresentable,
    axis: &v70,
    origin: (const idVec3 *)&v58,
    outAxis: &v73,
    outOrigin: &v63,
    extraScale: &v65);
  v71.mat[0].x = v70.mat[0].x;
  v71.mat[0].y = v70.mat[1].x;
  v71.mat[0].z = v70.mat[2].x;
  v71.mat[1].x = v70.mat[0].y;
  v71.mat[1].y = v70.mat[1].y;
  v71.mat[1].z = v70.mat[2].y;
  v71.mat[2].x = v70.mat[0].z;
  v71.mat[2].y = v70.mat[1].z;
  v71.mat[2].z = v70.mat[2].z;
  v66 = v63.x - v58.pitch;
  v68 = v63.z - v58.roll;
  v67 = v63.y - v58.yaw;
  v23 = __fsqrts((float)((float)(v68 * v68)
                       + (float)((float)((float)(v63.x - v58.pitch) * (float)(v63.x - v58.pitch)) + (float)(v67 * v67))));
  idMat3::operator*(this: v74, result: &v71, a: &v73);
  v59 = *(idVec3 *)((int (__fastcall *)(_QWORD *, idAnimFSM *, idAngles *, double))this->GetPathDelta)(
                     a1: v62,
                     a2: this,
                     a3: &v58,
                     a4: v23);
  idVec3::ProjectOntoPlane(this: &v59, normal: &v64, overBounce: 1.0);
  v24 = this->idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable;
  LODWORD(v25) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v25) = v24->UpdateAvoidance;
  v62[0] = v25;
  ((void (__fastcall *)(idAnimFSM *, double))HIDWORD(v25))(a1: this, a2: (float)((float)v25 * (float)v23));
  p_axis = &this->orientMove.axis;
  if ( ((LODWORD(v59.y) | LODWORD(v59.z) | LODWORD(v59.x)) & 0x7FFFFFFF) != 0 )
    p_axis = (idMat3 *)&v59;
  y = p_axis->mat[0].y;
  z = p_axis->mat[0].z;
  v29 = this->ai;
  v60.x = p_axis->mat[0].x;
  v60.z = z;
  _FP6 = (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v32 = __frsqrte(_FP4);
  v33 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32
                                                                                      * (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
                                                                                              * (float)0.5))
                                                                              * (float)v32)
                                                                      - (float)1.5)
                                                      * (float)v32)
                                              * (float)((float)((float)(y * y)
                                                              + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v32
                                                                              * (float)((float)((float)(y * y)
                                                                                              + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
                                                                                      * (float)0.5))
                                                                      * (float)v32)
                                                              - (float)1.5)
                                              * (float)v32))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v32
                                                      * (float)((float)((float)(y * y)
                                                                      + (float)((float)(v60.x * v60.x)
                                                                              + (float)(v60.z * v60.z)))
                                                              * (float)0.5))
                                              * (float)v32)
                                      - (float)1.5)
                      * (float)v32));
  v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                              * (float)v32)
                                                                                      * (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v32 * (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z))) * (float)0.5)) * (float)v32) - (float)1.5)
                                                                                      * (float)v32))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v32
                                                                                              * (float)((float)((float)(y * y) + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z))) * (float)0.5))
                                                                                      * (float)v32)
                                                                              - (float)1.5)
                                                              * (float)v32))
                                              * (float)((float)((float)(y * y)
                                                              + (float)((float)(v60.x * v60.x) + (float)(v60.z * v60.z)))
                                                      * (float)0.5))
                                      * (float)v33)
                              - (float)1.5)
              * (float)v33);
  v60.x = v60.x * (float)v34;
  v60.y = y * (float)v34;
  v60.z = z * (float)v34;
  idAIOrientation::SetIdealDir(this: &this->orientMove, ai: v29, dir: &v60);
  this->moveOrientationOnPath = true;
  RD_EventBegin(name: "idAnimFSM::MoveAIALongPath -- rotation");
  LODWORD(v35) = "idAnimFSM::MoveAIALongPath -- rotation";
  HIDWORD(v35) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v64, pl: &pLog, gMask: v35, label: v36);
  if ( this->currentMove.allowStrafing )
  {
    if ( !this->AlignToNextPoint(this) )
      idAI2::UpdateBodyOrientationWhileMovingWithFSM(this: this->ai);
  }
  else if ( !this->AlignToNextPoint(this) )
  {
    idAIOrientation::SetIdealDir(this: &this->orientBody, ai: this->ai, dir: &this->orientMove.idealDir);
    v37 = idEntity::GetPhysics(this: this->ai);
    v38 = (float *)v37->GetLinearVelocity(this: (idPhysics *)v62, result: (idVec3 *)v37, a3: 0);
    v39 = (float)((float)((float)__fsqrts((float)((float)(v38[2] * v38[2])
                                                + (float)((float)(*v38 * *v38) + (float)(v38[1] * v38[1]))))
                        * (float)0.0040000002)
                * (float)360.0);
    v40 = idEntity::GetPhysics(this: this->ai);
    LODWORD(v41) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v41) = v40->__vftable;
    v62[0] = v41;
    v42 = (float)((float)v41 * (float)0.001);
    v43 = (const idVec3 *)(*(int (__fastcall **)(idPhysics *))(HIDWORD(v41) + 104))(a1: v40);
    idAIOrientation::UpdateAxis(this: &this->orientBody, normal: v43, turnRate: v39, timeSeconds: v42);
  }
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v64);
  RD_EventEnd();
  idAnimBaseFSM::UpdateAimBlends(this);
  this->ai->aiVolatile.physics.object.movementType = AI_MOVE_WALKING;
  x = this->nextArrivalPos.x;
  HIDWORD(v62[0]) = &this->nextArrivalPos;
  v45 = __fsqrts((float)((float)((float)(this->nextArrivalPos.z - v58.roll) * (float)(this->nextArrivalPos.z - v58.roll))
                       + (float)((float)((float)((float)x - v58.pitch) * (float)((float)x - v58.pitch))
                               + (float)((float)(this->nextArrivalPos.y - v58.yaw)
                                       * (float)(this->nextArrivalPos.y - v58.yaw)))));
  if ( ai_useAnimBasedMovement.valueInteger == 0 || (v46 = 1, v45 <= 30.0) )
    v46 = 0;
  v47 = this->ai;
  GetGameMsPerFrame = (int (*)(void))gameLocal->GetGameMsPerFrame;
  if ( v46 != 0 )
  {
    v49 = GetGameMsPerFrame();
    v50 = (const idVec3 *)&v66;
  }
  else
  {
    v49 = GetGameMsPerFrame();
    v50 = &v59;
  }
  idPhysics_AI::SetDelta(this: &v47->aiVolatile.physics.object, d: v50, ticksPerFrame: v49);
  v51 = this->ai;
  v52 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_AI::GetDelta(this: (idPhysics_AI *)&v61, result: (const idVec3 *)&v51->aiVolatile, ticksPerFrame: v52);
  if ( (unsigned __int8)IsValid<idVec3>(v: (const idVec3 *)&v61) != 0 )
  {
    roll = v61.roll;
    yaw = v61.yaw;
    pitch = v61.pitch;
  }
  else
  {
    pitch = 0.0;
    v61.roll = 0.0;
    roll = 0.0;
    v61.yaw = 0.0;
    yaw = 0.0;
    v61.pitch = 0.0;
  }
  if ( ai_printDeltas.valueInteger == this->ai->entityNumber )
  {
    v56 = __fsqrts((float)((float)((float)roll * (float)roll)
                         + (float)((float)((float)pitch * (float)pitch) + (float)((float)yaw * (float)yaw))));
    idVec3::ToString(this: &v61, precision: 2);
    v57 = idVec3::ToString(this: &v58, precision: 2);
    idLib::Printf(
      fmt: "last origin : ( %s ) :  delta( %s ), s( %f )  ( move ground ) \n",
      v57,
      (const char *)HIDWORD(v56),
      v56);
  }
  idPLogScope::~idPLogScope(this: &v72);
  RD_EventEnd();
}


// ========================================================================
// __unwind$507826
// EA  : 0x82A75B68
// RVA : 0x00A75B68
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507826()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 496 + 404));
}


// ========================================================================
// __unwind$507827
// EA  : 0x82A75B90
// RVA : 0x00A75B90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507827()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 496 + 312));
}


// ========================================================================
// __unwind$507828
// EA  : 0x82A75BB8
// RVA : 0x00A75BB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507828()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 496 + 405));
}


// ========================================================================
// __unwind$507829
// EA  : 0x82A75BE0
// RVA : 0x00A75BE0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_507829()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 496 + 176));
}


// ========================================================================
// ?InternalTestMoveToPoint@idAnimFSM_AAS@@QBA?AW4aiMoveStatus_t@@ABVidAIMoveCmd@@AAVidVec3@@11AAH2AAUidAAS2Path@@@Z
// EA  : 0x82A75C10
// RVA : 0x00A75C10
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::InternalTestMoveToPoint(
        idAnimFSM_AAS *this,
        idVec3 *cmd,
        idVec3 *aasStartingPoint,
        idVec3 *aasFinalPoint,
        idVec3 *nextPoint,
        int *totalTravelTime,
        int *startAreaNum,
        idAAS2Path *localPath)
{
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idPhysics *Physics; // r3
  const idVec3 *v19; // r26
  double x; // fp0
  double y; // fp13
  double z; // fp12
  const idAAS2 *v23; // r28
  int v24; // r20
  int v26; // r3
  unsigned __int64 v27; // r6
  const char *v28; // r7
  double v29; // fp13
  idPLogScope v30; // [sp+50h] [-90h] BYREF
  idPLogScope v31; // [sp+58h] [-88h] BYREF
  idVec3 v32; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAnimBaseFSM::InternalTestMoveToPoint");
  LODWORD(v16) = "idAnimBaseFSM::InternalTestMoveToPoint";
  HIDWORD(v16) = 6;
  idPLogScope::idPLogScope(this: &v31, pl: &pLog, gMask: v16, label: v17);
  Physics = idEntity::GetPhysics(this: this->ai);
  v19 = Physics->GetOrigin(this: Physics, a2: 0);
  idAIMoveCmd::GetDestinationOrigin(this: (idAIMoveCmd *)&v32, result: cmd);
  *aasStartingPoint = *v19;
  x = v32.x;
  y = v32.y;
  z = v32.z;
  aasFinalPoint->x = v32.x;
  aasFinalPoint->y = y;
  aasFinalPoint->z = z;
  nextPoint->x = x;
  nextPoint->y = y;
  nextPoint->z = z;
  *startAreaNum = 0;
  *totalTravelTime = 0;
  v23 = this->ai->GetAAS(this: this->ai);
  if ( v23 == nullptr || ai_testPaths.valueInteger != 0 )
  {
    idPLogScope::~idPLogScope(this: &v31);
    RD_EventEnd();
    return 3;
  }
  else
  {
    v24 = idAnimFSM_AAS::PointReachableAreaNum(this, point: &v32, boundsScale: 1.0);
    if ( v24 != 0 )
    {
      v26 = idAnimFSM_AAS::PointReachableAreaNum(this, point: v19, boundsScale: 1.0);
      *startAreaNum = v26;
      if ( v26 != 0 )
      {
        RD_EventBegin(name: "idAnimBaseFSM::InternalTestMoveToPoint -- push points");
        LODWORD(v27) = "idAnimBaseFSM::InternalTestMoveToPoint -- push points";
        HIDWORD(v27) = 6;
        idPLogScope::idPLogScope(this: &v30, pl: &pLog, gMask: v27, label: v28);
        v23->PushPointIntoAreaNum(this: (idAAS2 *)v23, a2: *startAreaNum, a3: aasStartingPoint);
        v23->PushPointIntoAreaNum(this: (idAAS2 *)v23, a2: v24, a3: aasFinalPoint);
        idPLogScope::~idPLogScope(this: &v30);
        RD_EventEnd();
        if ( (unsigned __int8)idAnimFSM_AAS::PathToPoint(
                                this,
                                path: localPath,
                                myAreaNum: *startAreaNum,
                                myPos: aasStartingPoint,
                                goalAreaNum: v24,
                                goalPos: aasFinalPoint,
                                totalTravelTime) != 0 )
        {
          nextPoint->x = localPath->moveGoal.x;
          v29 = localPath->moveGoal.y;
          v30.logIndex = (int)&localPath->moveGoal;
          nextPoint->y = v29;
          nextPoint->z = localPath->moveGoal.z;
          idPLogScope::~idPLogScope(this: &v31);
          RD_EventEnd();
          return 1;
        }
        else
        {
          idPLogScope::~idPLogScope(this: &v31);
          RD_EventEnd();
          return 7;
        }
      }
      else
      {
        idPLogScope::~idPLogScope(this: &v31);
        RD_EventEnd();
        return 6;
      }
    }
    else
    {
      idPLogScope::~idPLogScope(this: &v31);
      RD_EventEnd();
      return 5;
    }
  }
}


// ========================================================================
// __unwind$508284
// EA  : 0x82A75E78
// RVA : 0x00A75E78
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508284()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 108));
}


// ========================================================================
// __unwind$508285
// EA  : 0x82A75EA0
// RVA : 0x00A75EA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508285()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// __unwind$508286
// EA  : 0x82A75EC8
// RVA : 0x00A75EC8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508286()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 109));
}


// ========================================================================
// __unwind$508287
// EA  : 0x82A75EF0
// RVA : 0x00A75EF0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508287()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?PathAroundObstacles@idAnimFSM_AAS@@QAA_NABVidVec3@@0PBUobstacleRoute_t@@PBVidEntity@@AAV2@AAVidObstacleInfo@@@Z
// EA  : 0x82A75F20
// RVA : 0x00A75F20
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::PathAroundObstacles(
        idAnimFSM_AAS *this,
        const idVec3 *startPos,
        const idVec3 *destination,
        const obstacleRoute_t *obstacleRoute,
        const idEntity *ignore,
        idVec3 *newPos,
        idObstacleInfo *obstacleInfo)
{
  idAnimFSM_AAS *v7; // r21
  const idVec3 *v8; // r26
  idVec3 *v9; // r27
  idObstacleInfo *v10; // r19
  unsigned __int64 v11; // r6
  idPLog *v12; // r20
  const char *v13; // r7
  double v14; // fp28
  idPLogScope v15; // r29
  float v16; // r30
  float g; // r24
  float b; // r22
  float r; // r27
  float v20; // r28
  float v21; // r23
  int *size; // r5
  float v23; // r29
  char *v24; // r17
  float v25; // r3
  float v26; // r21
  float v27; // r8
  float v28; // r20
  float v29; // r18
  int g_low; // r6
  float v31; // r14
  int v32; // r16
  float v33; // r17
  float v34; // r4
  float v35; // r9
  float v36; // r15
  float v37; // r26
  float v38; // r5
  int logIndex; // r10
  float v40; // r7
  float v41; // r10
  float v42; // r10
  float v43; // r10
  float v44; // r15
  float v45; // r14
  idPLogScope v46; // r29
  float v47; // r27
  float v48; // r11
  float v49; // r16
  float *v50; // r10
  float v51; // r8
  float v52; // r25
  float v53; // r24
  float v54; // r23
  float v55; // r10
  float v56; // r9
  float v57; // r10
  float v58; // r9
  int v59; // r24
  float v60; // r18
  float v61; // r23
  float v62; // r9
  float y; // r25
  const idVec4 *v64; // r27
  float v65; // r6
  char *v66; // r10
  int clipMask; // r5
  float v68; // r7
  idPhysics::residency_t collisionResidency; // r5
  float v70; // r4
  float v71; // r3
  float v72; // r11
  float v73; // r10
  float v74; // r8
  float v75; // r7
  float v76; // r5
  float v77; // r4
  float v78; // r3
  float v79; // r9
  float z; // r7
  idEntity *ai; // r3
  unsigned int entityNumber; // r5
  double v83; // fp30
  double v84; // fp29
  double v85; // fp26
  double v86; // fp25
  unsigned int v87; // r25
  idPhysics *Physics; // r3
  float *v89; // r3
  idEntity *v90; // r3
  double v91; // fp12
  double v92; // fp10
  double v93; // fp9
  idPhysics *v94; // r3
  int v95; // r3
  const idVec4 *v96; // r30
  idPhysics *v97; // r3
  float *v98; // r3
  double v99; // fp8
  double v100; // fp7
  double v101; // fp5
  idEntity *v102; // r3
  idPhysics *v103; // r3
  int v104; // r3
  idPhysics *v105; // r3
  float *v106; // r3
  idEntity *v107; // r3
  double v108; // fp2
  double v109; // fp0
  double v110; // fp13
  idPhysics *v111; // r3
  int v112; // r3
  unsigned __int64 v113; // r6
  const char *v114; // r7
  int v115; // r3
  const idAAS2 *v116; // r30
  double valueFloat; // fp0
  double v118; // fp25
  idAI2 *v119; // r10
  const idVec3 *Origin; // r3
  idAI2 *v121; // r9
  float v122; // r7
  float v123; // r6
  const idVec3 *v124; // r3
  char v125; // r11
  double v126; // fp11
  double x; // fp10
  double v128; // fp3
  idActor *v129; // r3
  idAASPosition *AASPosition; // r3
  float v131; // r3
  double v132; // fp0
  double v133; // fp13
  double v134; // fp12
  double v135; // fp11
  double v136; // fp10
  double v137; // fp9
  idPhysics *v138; // r16
  int v139; // r3
  idClipModel *v140; // r6
  int v141; // r11
  idVec3 *(__fastcall *GetLinearVelocity)(idPhysics *, idVec3 *, int); // r10
  double v143; // fp13
  double v144; // fp12
  double v145; // fp0
  double v146; // fp27
  double v147; // fp14
  double v148; // fp26
  idAI2 *v149; // r3
  double v152; // fp3
  double v153; // fp6
  double v154; // fp3
  double DefaultSpeedByCurrentWalkState; // fp1
  idPhysics_vtbl *v156; // r8
  float *v157; // r3
  double v158; // fp31
  double v159; // fp30
  double v160; // fp29
  float *v161; // r3
  double v162; // fp2
  double v163; // fp1
  double v164; // fp0
  double v165; // fp31
  double v166; // fp12
  const idAAS2Settings *(__fastcall *GetSettings)(idAAS2 *); // ctr
  obstacleVertex_t *VertexArray; // r29
  obstacleEdge_t *EdgeArray; // r28
  idAASPosition *v170; // r3
  idAAS2 v171; // r26
  int AreaNum; // r3
  unsigned __int64 v173; // r6
  const char *v174; // r7
  const idEntity *v175; // r27
  float v176; // r24
  float v177; // r29
  double v178; // fp23
  double v179; // fp31
  int v180; // r30
  int v181; // r8
  idAI2 *v182; // r25
  idActor *v183; // r3
  float *v184; // r3
  double v185; // fp13
  double v186; // fp12
  physicsType_t type; // r10
  idDrone *v188; // r3
  const idSpawnId **v189; // r3
  float v190; // r7
  int *p_physicsId; // r10
  float v192; // r6
  _DWORD *v193; // r11
  int v194; // ctr
  int *v195; // r10
  _DWORD *v196; // r11
  int i; // ctr
  const idSpawnId **v198; // r3
  idAI2 *v199; // r11
  aiMovePushStatus_t movePushStatus; // r9
  double v201; // fp13
  double v202; // fp11
  double v203; // fp19
  idVec3 *v204; // r28
  idAI2 *v205; // r26
  double v206; // fp30
  double v207; // fp29
  double v208; // fp24
  float *v209; // r3
  double v210; // fp9
  double v211; // fp7
  const idSpawnId **v212; // r3
  unsigned __int64 v213; // r6
  const char *v214; // r7
  char v215; // r30
  double v216; // fp31
  double v217; // fp30
  double v218; // fp29
  unsigned int v219; // r5
  float *OriginHistory; // r3
  float v221; // r11
  float *p_x; // r27
  float v223; // r10
  double v224; // fp28
  double v225; // fp30
  double v226; // fp31
  float v227; // r9
  int z_low; // r7
  float v229; // r6
  contactInfo_t *y_low; // r8
  double v231; // fp22
  double v232; // fp24
  double v233; // fp21
  char v234; // r24
  double v235; // fp29
  double v236; // fp27
  int v237; // r11
  idEntity *v238; // r30
  idEntity *v239; // r3
  float v240; // r9
  float v241; // r8
  idPhysics *v242; // r3
  int v243; // r3
  float v244; // r10
  idAI2 *v245; // r9
  unsigned int v246; // r8
  float v247; // r7
  unsigned int v248; // r6
  double v249; // fp28
  double v250; // fp30
  double v251; // fp31
  double v252; // fp26
  int GameMs; // r3
  int frustrationOverTime; // r11
  int v255; // r3
  int v256; // r11
  double v257; // fp0
  double v258; // fp13
  float *v259; // r3
  double v260; // fp31
  double v261; // fp7
  double v262; // fp6
  double v263; // fp5
  double v264; // fp0
  double v265; // fp4
  double v266; // fp3
  double v267; // fp2
  double v268; // fp25
  double v269; // fp13
  double v270; // fp26
  double v271; // fp12
  double v272; // fp23
  double v273; // fp11
  double v274; // fp29
  double v275; // fp27
  idPhysics *v276; // r3
  float *v277; // r3
  double v278; // fp5
  double v279; // fp4
  double v280; // fp2
  double v281; // fp1
  double v282; // fp31
  float v283; // r11
  double v284; // fp0
  float v285; // r10
  float v286; // r9
  float *v287; // r3
  double v288; // fp8
  double v289; // fp5
  double v290; // fp6
  double v291; // fp2
  double v292; // fp9
  double v293; // fp7
  double v294; // fp3
  double v295; // fp4
  double v296; // fp10
  double aiPathfindRadius; // fp29
  double v298; // fp11
  const idSpawnId **SpawnId; // r3
  char *v300; // r27
  int v301; // r11
  idAI2 *v302; // r25
  int num; // r29
  float v304; // r30
  bool v305; // zf
  idPhysics *v306; // r3
  int v307; // r3
  double v308; // fp31
  idPhysics *v309; // r3
  int v310; // r3
  float v311; // r29
  int v312; // r30
  int v313; // r3
  __int64 v314; // r11
  __int64 v315; // r9
  unsigned __int64 groupMask; // r11
  idPhysics::residency_t v317; // r22
  int v318; // r11
  int v319; // r10
  int v320; // r30
  __int64 v321; // r3
  unsigned __int64 v322; // r11
  float v323; // r30
  int v324; // r11
  int v325; // r10
  int v326; // r29
  __int64 v327; // r3
  int v328; // r29
  idPhysics *v329; // r28
  double obstaclePerceptionRadius; // fp31
  const idVec3 *v331; // r29
  const idBounds *v332; // r28
  int v333; // r26
  int v334; // r3
  const obstacleRoute_t *v335; // r10
  int v336; // r9
  bool PathAroundObstacles; // r23
  int v338; // r30
  int v339; // r3
  int v340; // r11
  __int64 v341; // r9
  double v342; // fp13
  double v343; // fp12
  double v344; // fp10
  double v345; // fp9
  idRenderWorld *renderWorld; // r30
  idRenderWorld_vtbl *v347; // r29
  int v348; // r3
  const idVec3 *v349; // r16
  idRenderWorld *v350; // r30
  idRenderWorld_vtbl *v351; // r29
  int v352; // r3
  idRenderWorld *v353; // r30
  idRenderWorld_vtbl *v354; // r29
  int v355; // r3
  idEntity *v356; // r3
  idEntity *v357; // r3
  idEntity *v358; // r3
  idEntityPtr<idEntity const > *p_endObstacle; // r25
  float *v360; // r11
  double v361; // fp0
  double v362; // fp13
  unsigned __int64 v363; // r11
  int v364; // r29
  int v365; // r11
  int v366; // r10
  int v367; // r30
  __int64 v368; // r3
  int v369; // r28
  float *v370; // r30
  double v371; // fp0
  int v372; // r30
  int v373; // r3
  int v374; // r11
  __int64 v375; // r9
  int value; // r9
  idGameLocal *v377; // r11
  int v378; // r7
  idEntity *v379; // r3
  idEntity *v380; // r3
  idEntity *v381; // r30
  int v382; // r9
  __int64 v383; // r6
  idEntity *v384; // r3
  idEntity *v385; // r3
  int obstacleStopDistance; // r8
  double v387; // fp3
  int v388; // r30
  int v389; // r3
  int v390; // r11
  __int64 v391; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v393; // r30
  int v394; // r3
  __int64 totalTicks; // r11
  __int64 v396; // r9
  float v397; // r29
  int v398; // r30
  int v399; // r3
  __int64 v400; // r11
  __int64 v401; // r9
  int v403; // r30
  int v404; // r3
  int v405; // r11
  __int64 v406; // r9
  idPLog *v407; // r29
  idPLog::logEntry_t *v408; // r30
  int v409; // r3
  __int64 v410; // r11
  __int64 v411; // r9
  float v412; // r29
  int v413; // r30
  int v414; // r3
  __int64 v415; // r11
  __int64 v416; // r9
  int v417; // r10
  idAI2 *v418; // r30
  int v419; // r8
  idEntity *v420; // r3
  idPhysics *v421; // r3
  int v422; // r3
  idPhysics *v423; // r3
  idPhysics *v424; // r3
  float *v425; // r3
  idEntity *v426; // r3
  double v427; // fp9
  double v428; // fp7
  double v429; // fp6
  idPhysics *v430; // r3
  int v431; // r3
  idPhysics *v432; // r3
  int v433; // r3
  int v434; // r30
  int v435; // r3
  int v436; // r11
  __int64 v437; // r9
  idPLog *v438; // r29
  idPLog::logEntry_t *v439; // r30
  int v440; // r3
  __int64 v441; // r11
  __int64 v442; // r9
  float v443; // r29
  int v444; // r30
  int v445; // r3
  __int64 v446; // r11
  __int64 v447; // r9
  obstacleTraceSet_t *v448; // [sp+8h] [-18E8h]
  int v449; // [sp+Ch] [-18E4h]
  int v450; // [sp+10h] [-18E0h]
  int v451; // [sp+14h] [-18DCh]
  int v452; // [sp+18h] [-18D8h]
  int v453; // [sp+1Ch] [-18D4h]
  int v454; // [sp+20h] [-18D0h]
  int v455; // [sp+24h] [-18CCh]
  int v456; // [sp+28h] [-18C8h]
  int v457; // [sp+2Ch] [-18C4h]
  int v458; // [sp+30h] [-18C0h]
  int v459; // [sp+34h] [-18BCh]
  int v460; // [sp+38h] [-18B8h]
  int v461; // [sp+3Ch] [-18B4h]
  int v462; // [sp+40h] [-18B0h]
  int v463; // [sp+44h] [-18ACh]
  int v464; // [sp+48h] [-18A8h]
  int v465; // [sp+4Ch] [-18A4h]
  int v466; // [sp+50h] [-18A0h]
  int v467; // [sp+58h] [-1898h]
  int v468; // [sp+60h] [-1890h]
  int v469; // [sp+68h] [-1888h]
  float v470; // [sp+70h] [-1880h]
  float v471; // [sp+70h] [-1880h]
  const idEntity *v472; // [sp+70h] [-1880h]
  aiMovePushStatus_t v473; // [sp+70h] [-1880h]
  float v474; // [sp+74h] [-187Ch]
  float v475; // [sp+80h] [-1870h] BYREF
  float v476; // [sp+84h] [-186Ch]
  float v477; // [sp+88h] [-1868h]
  float v478; // [sp+90h] [-1860h]
  idPLog *v479; // [sp+94h] [-185Ch]
  int v480; // [sp+98h] [-1858h]
  float v481; // [sp+9Ch] [-1854h]
  float v482; // [sp+A0h] [-1850h]
  char *v483; // [sp+A4h] [-184Ch]
  float v484; // [sp+A8h] [-1848h]
  int p_newDest; // [sp+B0h] [-1840h]
  idPLog *v486; // [sp+B4h] [-183Ch]
  float v487; // [sp+B8h] [-1838h] BYREF
  float v488; // [sp+BCh] [-1834h] BYREF
  float v489; // [sp+C0h] [-1830h]
  float v490; // [sp+C4h] [-182Ch] BYREF
  float v491; // [sp+C8h] [-1828h] BYREF
  float v492; // [sp+CCh] [-1824h] BYREF
  int v493; // [sp+D0h] [-1820h]
  const idVec4 *MaxEdges; // [sp+D4h] [-181Ch] BYREF
  idPLogScope v495; // [sp+D8h] [-1818h] BYREF
  idVec3 v496; // [sp+E0h] [-1810h] BYREF
  float v497; // [sp+ECh] [-1804h]
  float v498; // [sp+F0h] [-1800h]
  float v499; // [sp+F4h] [-17FCh]
  float v500; // [sp+F8h] [-17F8h]
  float v501; // [sp+FCh] [-17F4h]
  float a; // [sp+100h] [-17F0h]
  int a_low; // [sp+104h] [-17ECh] BYREF
  float v504; // [sp+108h] [-17E8h]
  float v505; // [sp+10Ch] [-17E4h]
  idPhysics_Actor v506; // [sp+110h] [-17E0h] BYREF
  float v507; // [sp+2D8h] [-1618h]
  idVec3 v508; // [sp+2E0h] [-1610h] BYREF
  float v509[4]; // [sp+2F0h] [-1600h] BYREF
  float v510[4]; // [sp+300h] [-15F0h] BYREF
  float v511[3]; // [sp+310h] [-15E0h] BYREF
  int v512; // [sp+31Ch] [-15D4h] BYREF
  idBounds v513; // [sp+320h] [-15D0h] BYREF
  idNpCornerInfo v514; // [sp+340h] [-15B0h] BYREF
  idPhysics_Actor v515; // [sp+380h] [-1570h] BYREF
  int v516; // [sp+694h] [-125Ch]
  float v517; // [sp+698h] [-1258h]
  float v518; // [sp+69Ch] [-1254h]
  float v519; // [sp+6A0h] [-1250h]
  float v520; // [sp+6A4h] [-124Ch]
  int v521; // [sp+6B4h] [-123Ch]
  int v522; // [sp+6C4h] [-122Ch]
  float v523; // [sp+6C8h] [-1228h]
  float v524; // [sp+6CCh] [-1224h]
  float v525; // [sp+6D0h] [-1220h]
  int v526; // [sp+6D4h] [-121Ch]
  float v527; // [sp+6DCh] [-1214h]
  float v528; // [sp+6F4h] [-11FCh]
  float v529; // [sp+6F8h] [-11F8h]
  float v530; // [sp+6FCh] [-11F4h]
  float v531; // [sp+700h] [-11F0h]
  float v532; // [sp+704h] [-11ECh]
  float v533; // [sp+708h] [-11E8h]
  idVec3 v534[4]; // [sp+790h] [-1160h] BYREF
  _BYTE v535[304]; // [sp+7C0h] [-1130h] BYREF

  v7 = this;
  v8 = startPos;
  v15.logIndex = (int)destination;
  v9 = newPos;
  v10 = obstacleInfo;
  RD_EventBegin(name: "idAnimFSM_AAS::PathAroundObstacles");
  LODWORD(v11) = "idAnimFSM_AAS::PathAroundObstacles";
  v12 = &::pLog;
  HIDWORD(v11) = 6;
  v499 = COERCE_FLOAT(&::pLog);
  idPLogScope::idPLogScope(this: (idPLogScope *)&v506.gravityNormal, pl: &::pLog, gMask: v11, label: v13);
  v506.contacts.size = (int)&idColor::colorPurple;
  v506.lastHistorySaveTime = (int)&idColor::colorCyan;
  p_newDest = (int)&idColor::colorMagenta;
  v506.contactPhysicsIds.list = (int *)&idColor::colorYellow;
  v14 = 8.0;
  v15.pLog = (idPLog *)-2088894464;
  *(float *)&v506.contactPhysicsIds.size = 8.0;
  LODWORD(v506.originHistory[2].x) = &idColor::colorBlue;
  *(_DWORD *)&v506.contacts.granularity = &idColor::colorMdGrey;
  LODWORD(v506.gravityVector.x) = &idColor::colorGreen;
  v506.contactPhysicsIds.num = (int)&idColor::colorRed;
  if ( ai_showMovementTrails.valueInteger != 0 )
  {
    v16 = COERCE_FLOAT(DEBUG_COLORS_0);
    v489 = COERCE_FLOAT(DEBUG_COLORS_0);
    if ( (_S20_0 & 1) == 0 )
    {
      g = idColor::colorRed.g;
      b = idColor::colorRed.b;
      v506.gravityVector.y = idColor::colorRed.a;
      r = idColor::colorWhite.r;
      v495.logIndex = LODWORD(idColor::colorGreen.r);
      v483 = &aAvSsobjectVCom[20];
      a = idColor::colorBlack.a;
      v490 = idColor::colorGreen.g;
      v501 = idColor::colorWhite.g;
      v20 = idColor::colorWhite.b;
      v487 = idColor::colorGreen.a;
      v491 = idColor::colorGreen.b;
      a_low = LODWORD(idColor::colorWhite.a);
      v21 = idColor::colorBlue.b;
      v488 = idColor::colorBlue.r;
      v481 = idColor::colorBlue.g;
      *(float *)&v493 = COERCE_FLOAT(&idColor::colorOrange);
      v484 = idColor::colorBlue.a;
      _S20_0 |= 1u;
      DEBUG_COLORS_0[0].x = idColor::colorBlack.r;
      DEBUG_COLORS_0[0].y = idColor::colorBlack.g;
      size = (int *)v506.contacts.size;
      v492 = idColor::colorRed.g;
      v482 = idColor::colorRed.b;
      v497 = idColor::colorYellow.g;
      v505 = idColor::colorYellow.b;
      v470 = idColor::colorYellow.a;
      v500 = idColor::colorMagenta.r;
      v504 = idColor::colorMagenta.g;
      v498 = idColor::colorMagenta.b;
      DEBUG_COLORS_0[0].z = idColor::colorBlack.b;
      MaxEdges = &DEBUG_COLORS_0[8];
      v16 = v489;
      v23 = idColor::colorRed.r;
      *(float *)&v506.residencyQuery.index = idColor::colorBrown.r;
      v506.clipMask = LODWORD(idColor::colorPink.r);
      v480 = *(_DWORD *)&v506.contacts.granularity;
      v24 = *(char **)(v506.contacts.size + 4);
      v506.collisionResidency = LODWORD(idColor::colorBrown.g);
      v25 = idColor::colorBrown.b;
      v26 = idColor::colorCyan.r;
      v27 = idColor::colorMagenta.a;
      v478 = idColor::colorBrown.a;
      v482 = idColor::colorYellow.r;
      v493 = LODWORD(v489) + 224;
      LODWORD(v489) += 208;
      v483 = v24;
      DEBUG_COLORS_0[0].w = idColor::colorBlack.a;
      v506.callbacks = (idPhysicsCallbacks *)LODWORD(idColor::colorPink.g);
      v28 = idColor::colorCyan.g;
      v29 = idColor::colorCyan.b;
      g_low = LODWORD(idColor::colorOrange.g);
      *(float *)(LODWORD(v16) + 20) = idColor::colorWhite.g;
      v31 = idColor::colorOrange.b;
      v32 = *size;
      v33 = *((float *)size + 2);
      v34 = idColor::colorPink.b;
      *(_DWORD *)(LODWORD(v16) + 28) = a_low;
      v35 = idColor::colorCyan.a;
      v36 = idColor::colorOrange.r;
      v37 = idColor::colorOrange.a;
      v38 = *((float *)size + 3);
      *(float *)(LODWORD(v16) + 44) = v506.gravityVector.y;
      logIndex = v495.logIndex;
      v40 = idColor::colorPink.a;
      *(float *)(LODWORD(v16) + 16) = r;
      *(float *)(LODWORD(v16) + 24) = v20;
      *(float *)(LODWORD(v16) + 32) = v23;
      *(_DWORD *)(LODWORD(v16) + 48) = logIndex;
      v41 = v490;
      *(float *)(LODWORD(v16) + 36) = g;
      *(float *)(LODWORD(v16) + 40) = b;
      *(float *)(LODWORD(v16) + 72) = v21;
      *(float *)(LODWORD(v16) + 52) = v41;
      *(float *)(LODWORD(v16) + 56) = v491;
      *(float *)(LODWORD(v16) + 60) = v487;
      *(float *)(LODWORD(v16) + 64) = v488;
      v42 = v481;
      v481 = v26;
      *(float *)(LODWORD(v16) + 68) = v42;
      v43 = v484;
      v484 = v27;
      *(float *)(LODWORD(v16) + 76) = v43;
      MaxEdges = (const idVec4 *)LODWORD(v37);
      v488 = v28;
      v487 = v29;
      v490 = v36;
      v44 = v500;
      v500 = v28;
      v12 = (idPLog *)LODWORD(v499);
      v499 = v484;
      v506.gravityVector.y = v31;
      v45 = v504;
      v504 = v26;
      v46.logIndex = LODWORD(idColor::colorLtGrey.b);
      v47 = idColor::colorLtGrey.a;
      v48 = idColor::colorLtGrey.g;
      *(float *)(LODWORD(v16) + 84) = v497;
      v491 = v35;
      v495.logIndex = g_low;
      v492 = *(float *)&v32;
      v49 = v470;
      v50 = (float *)v480;
      v51 = idColor::colorLtGrey.r;
      v52 = *(float *)v480;
      v471 = v487;
      *(float *)(LODWORD(v16) + 104) = v498;
      v53 = v50[1];
      v54 = v50[2];
      v55 = v50[3];
      *(float *)(LODWORD(v16) + 108) = v499;
      v56 = idColor::colorDkGrey.r;
      v46.pLog = (idPLog *)-2088894464;
      v487 = v55;
      *(float *)(LODWORD(v16) + 112) = v504;
      v57 = v491;
      v491 = v56;
      v481 = v53;
      v58 = idColor::colorDkGrey.g;
      v59 = v495.logIndex;
      v488 = v54;
      v495 = v46;
      *(float *)(LODWORD(v16) + 116) = v500;
      v60 = v505;
      v61 = v490;
      v490 = v58;
      v62 = idColor::colorDkGrey.b;
      v484 = v52;
      v497 = v47;
      v505 = *(float *)&v46.logIndex;
      y = v506.gravityVector.y;
      v64 = MaxEdges;
      *(float *)&v46.logIndex = v492;
      v65 = idColor::colorDkGrey.a;
      v10 = obstacleInfo;
      v8 = startPos;
      v7 = this;
      *(float *)(LODWORD(v16) + 80) = v482;
      *(float *)(LODWORD(v16) + 88) = v60;
      *(float *)(LODWORD(v16) + 92) = v49;
      *(float *)(LODWORD(v16) + 96) = v44;
      *(float *)(LODWORD(v16) + 100) = v45;
      *(float *)(LODWORD(v16) + 120) = v471;
      *(float *)(LODWORD(v16) + 124) = v57;
      *(float *)(LODWORD(v16) + 128) = v61;
      *(_DWORD *)(LODWORD(v16) + 132) = v59;
      *(float *)(LODWORD(v16) + 156) = v38;
      v66 = v483;
      clipMask = v506.clipMask;
      *(float *)(LODWORD(v16) + 168) = v34;
      *(float *)(LODWORD(v16) + 172) = v40;
      *(float *)(LODWORD(v16) + 184) = v25;
      *(_DWORD *)(LODWORD(v16) + 148) = v66;
      *(_DWORD *)(LODWORD(v16) + 160) = clipMask;
      v68 = *(float *)&v506.residencyQuery.index;
      collisionResidency = v506.collisionResidency;
      v70 = v478;
      v71 = v505;
      *(_DWORD *)(LODWORD(v16) + 164) = v506.callbacks;
      *(float *)(LODWORD(v16) + 176) = v68;
      *(_DWORD *)(LODWORD(v16) + 180) = collisionResidency;
      *(float *)(LODWORD(v16) + 188) = v70;
      *(float *)(LODWORD(v16) + 192) = v51;
      *(float *)(LODWORD(v16) + 196) = v48;
      *(float *)(LODWORD(v16) + 200) = v71;
      v72 = v497;
      v73 = v484;
      v74 = v481;
      v75 = v488;
      v76 = v487;
      v77 = v491;
      v78 = v490;
      *(_DWORD *)(LODWORD(v16) + 140) = v64;
      *(_DWORD *)(LODWORD(v16) + 144) = v46.logIndex;
      v9 = newPos;
      v15 = v495;
      *(float *)(LODWORD(v16) + 136) = y;
      *(float *)(LODWORD(v16) + 152) = v33;
      *(float *)(LODWORD(v16) + 204) = v72;
      *(float *)(LODWORD(v16) + 208) = v73;
      *(float *)(LODWORD(v16) + 212) = v74;
      *(float *)(LODWORD(v16) + 216) = v75;
      *(float *)(LODWORD(v16) + 220) = v76;
      *(float *)(LODWORD(v16) + 224) = v77;
      *(float *)(LODWORD(v16) + 228) = v78;
      *(float *)(LODWORD(v16) + 232) = v62;
      *(float *)(LODWORD(v16) + 236) = v65;
    }
    v79 = v7->orientMove.idealDir.y;
    z = v7->orientMove.idealDir.z;
    ai = v7->ai;
    v496.x = v7->orientMove.idealDir.x;
    v496.y = v79;
    v496.z = z;
    entityNumber = ai->entityNumber;
    v478 = *(float *)&ai;
    v83 = v79;
    v84 = z;
    v85 = (float)(v79 * (float)100.0);
    v86 = (float)(z * (float)100.0);
    v87 = entityNumber % 0xF;
    Physics = idEntity::GetPhysics(this: ai);
    v89 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v91 = (float)(v89[2] + (float)v86);
    v92 = (float)(v89[1] + (float)v85);
    v93 = (float)((float)(v496.x * (float)100.0) + *v89);
    v90 = v7->ai;
    v510[0] = v93;
    v510[2] = v91;
    v510[1] = v92;
    v94 = idEntity::GetPhysics(this: v90);
    v95 = (int)v94->GetOrigin(this: v94, a2: 0);
    v96 = (const idVec4 *)(16 * v87 + LODWORD(v16));
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, double))(**(_DWORD **)(v15.pLog[366].logEntries.size
                                                                                       + 4)
                                                                         + 180))(
      a1: *(_DWORD *)(v15.pLog[366].logEntries.size + 4),
      a2: v96,
      a3: v95,
      a4: v510,
      a5: 8.0);
    v97 = idEntity::GetPhysics(this: v7->ai);
    v98 = (float *)v97->GetOrigin(this: v97, a2: 0);
    v99 = v98[2];
    v100 = v98[1];
    v101 = *v98;
    v102 = v7->ai;
    v511[0] = v101;
    v511[1] = v100;
    v511[2] = (float)v99 + (float)48.0;
    v103 = idEntity::GetPhysics(this: v102);
    v104 = (int)v103->GetOrigin(this: v103, a2: 0);
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, int, _DWORD))(**(_DWORD **)(v15.pLog[366].logEntries.size
                                                                                            + 4)
                                                                              + 176))(
      a1: *(_DWORD *)(v15.pLog[366].logEntries.size + 4),
      a2: v96,
      a3: v104,
      a4: v511,
      a5: 16,
      a6: 0);
    v105 = idEntity::GetPhysics(this: v7->ai);
    v106 = (float *)v105->GetOrigin(this: v105, a2: 0);
    v108 = (float)(v106[2] + (float)((float)v84 * (float)2.0));
    v109 = (float)(v106[1] + (float)((float)v83 * (float)2.0));
    v110 = (float)(*v106 + (float)(v496.x * (float)2.0));
    v107 = v7->ai;
    v509[0] = v110;
    v509[2] = v108;
    v509[1] = v109;
    v111 = idEntity::GetPhysics(this: v107);
    v112 = (int)v111->GetOrigin(this: v111, a2: 0);
    (*(void (__fastcall **)(_DWORD, const idVec4 *, int, float *, int, int))(**(_DWORD **)(v15.pLog[366].logEntries.size
                                                                                         + 4)
                                                                           + 176))(
      a1: *(_DWORD *)(v15.pLog[366].logEntries.size + 4),
      a2: v96,
      a3: v112,
      a4: v509,
      a5: 60000,
      a6: 1);
  }
  RD_EventBegin(name: "idAnimFSM_AAS::PathAroundObstacles -- block1");
  LODWORD(v113) = "idAnimFSM_AAS::PathAroundObstacles -- block1";
  HIDWORD(v113) = 6;
  idPLogScope::idPLogScope(this: &v495, pl: v12, gMask: v113, label: v114);
  v9->x = *(float *)v15.logIndex;
  v9->y = *(float *)(v15.logIndex + 4);
  v9->z = *(float *)(v15.logIndex + 8);
  v115 = (int)v7->ai->GetAAS(this: v7->ai);
  memset(&v515.contacts.num, 0, 12);
  v116 = (const idAAS2 *)v115;
  *(float *)&v515.contactPhysicsIds.list = 0.0;
  *(float *)&v515.contactPhysicsIds.num = 0.0;
  *(float *)&v515.contactPhysicsIds.size = 0.0;
  *(float *)&v515.contactPhysicsIds.granularity = 0.0;
  obstacleRoute_t::Clear(this: (obstacleRoute_t *)&v515.contacts.num);
  valueFloat = ai_cornerCircleRadius.valueFloat;
  if ( ai_cornerCircleRadius.valueFloat <= 0.0 )
    valueFloat = v7->ai->aiEditable.behaviors.decl->movementBehaviors.cornerCircleRadius;
  v474 = valueFloat;
  v118 = 16.0;
  v497 = 16.0;
  if ( ai_useObstacleRoute.valueInteger != 0 )
  {
    v119 = v7->ai;
    v480 = 276;
    if ( idAICover::IsValid(this: &v119->aiVolatile.memory.currentCover) )
    {
      Origin = idAICover::GetOrigin(this: &v7->ai->aiVolatile.memory.currentCover);
      v121 = v7->ai;
      v122 = Origin->y;
      v123 = Origin->z;
      v496.x = Origin->x;
      v496.y = v122;
      v496.z = v123;
      v124 = idAICover::GetOrigin(this: &v121->aiVolatile.memory.currentCover);
      if ( *(float *)v15.logIndex != v124->x
        || *(float *)(v15.logIndex + 4) != v124->y
        || (v125 = 1, *(float *)(v15.logIndex + 8) != v124->z) )
      {
        v125 = 0;
      }
      if ( v125 != 0 )
      {
        v126 = (float)(v10->wallCorners[1].y - v496.y);
        x = v10->wallCorners[1].x;
        LODWORD(v478) = &v10->wallCorners[1];
        if ( (float)((float)((float)(v10->wallCorners[1].z - v496.z) * (float)(v10->wallCorners[1].z - v496.z))
                   + (float)((float)((float)((float)x - v496.x) * (float)((float)x - v496.x))
                           + (float)((float)v126 * (float)v126))) < 16.0 )
        {
          v128 = (float)((float)((float)(v10->wallCorners[0].z - v496.z) * (float)(v10->wallCorners[0].z - v496.z))
                       + (float)((float)((float)(v10->wallCorners[0].x - v496.x)
                                       * (float)(v10->wallCorners[0].x - v496.x))
                               + (float)((float)(v10->wallCorners[0].y - v496.y)
                                       * (float)(v10->wallCorners[0].y - v496.y))));
          LODWORD(v478) = v10->wallCorners;
          if ( v128 > 16.0 )
            v474 = ai_minCornerCircleRadius.valueFloat;
        }
      }
    }
    obstacleRoute_t::operator=(this: (obstacleRoute_t *)&v515.contacts.num, __that: obstacleRoute);
  }
  else
  {
    v129 = v7->ai;
    v515.contacts.num = 1;
    v480 = 273;
    AASPosition = (idAASPosition *)idActor::GetAASPosition(this: v129, aas: v116);
    v131 = COERCE_FLOAT(idAASPosition::GetAreaNum(this: AASPosition));
    v132 = v8->x;
    v133 = v8->y;
    v515.waterLevel = v131;
    v134 = v8->z;
    v135 = *(float *)v15.logIndex;
    v136 = *(float *)(v15.logIndex + 4);
    v137 = *(float *)(v15.logIndex + 8);
    v515.waterViscosity = v132;
    *(&v515.waterViscosity + 1) = v133;
    *(float *)v515.clipModels = v134;
    *(float *)&v515.clipModels[1] = v135;
    *(float *)v515.clipMasks = v136;
    *(float *)&v515.clipMasks[1] = v137;
  }
  v138 = idEntity::GetPhysics(this: v7->ai);
  v139 = (int)v138->GetOrigin(this: v138, a2: 0);
  v140 = *(idClipModel **)(v139 + 4);
  v141 = *(_DWORD *)(v139 + 8);
  GetLinearVelocity = v138->GetLinearVelocity;
  v506.clipModels[0] = *(idClipModel **)v139;
  v506.clipModels[1] = v140;
  v506.clipMasks[0] = v141;
  GetLinearVelocity(this: (idPhysics *)&v506.entityNumber, result: (idVec3 *)v138, a3: 0);
  v143 = *(float *)&v506.clip;
  v144 = *(float *)&v506.nextInHash;
  v145 = *(float *)&v506.entityNumber;
  v146 = *(float *)v506.clipMasks;
  v147 = *(float *)&v506.clipModels[1];
  v148 = *(float *)v506.clipModels;
  if ( (float)((float)(*(float *)&v506.entityNumber * *(float *)&v506.entityNumber)
             + (float)((float)(*(float *)&v506.nextInHash * *(float *)&v506.nextInHash)
                     + (float)(*(float *)&v506.clip * *(float *)&v506.clip))) < 1.0 )
  {
    v143 = (float)(*(float *)(v15.logIndex + 8) - *(float *)v506.clipMasks);
    v144 = (float)(*(float *)(v15.logIndex + 4) - *(float *)&v506.clipModels[1]);
    v145 = (float)(*(float *)v15.logIndex - *(float *)v506.clipModels);
  }
  v149 = v7->ai;
  v505 = 1.5;
  _FP6 = (float)((float)((float)((float)v145 * (float)v145)
                       + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f11 }
  v152 = __frsqrte(_FP4);
  v153 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v152
                                                                                       * (float)((float)((float)((float)v145 * (float)v145) + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143)))
                                                                                               * (float)0.5))
                                                                               * (float)v152)
                                                                       - (float)1.5)
                                                       * (float)v152)
                                               * (float)((float)((float)((float)v145 * (float)v145)
                                                               + (float)((float)((float)v144 * (float)v144)
                                                                       + (float)((float)v143 * (float)v143)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v152
                                                                               * (float)((float)((float)((float)v145 * (float)v145)
                                                                                               + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143)))
                                                                                       * (float)0.5))
                                                                       * (float)v152)
                                                               - (float)1.5)
                                               * (float)v152))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v152
                                                       * (float)((float)((float)((float)v145 * (float)v145)
                                                                       + (float)((float)((float)v144 * (float)v144)
                                                                               + (float)((float)v143 * (float)v143)))
                                                               * (float)0.5))
                                               * (float)v152)
                                       - (float)1.5)
                       * (float)v152));
  v154 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v152 * (float)((float)((float)((float)v145 * (float)v145) + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143))) * (float)0.5)) * (float)v152) - (float)1.5)
                                                                                               * (float)v152)
                                                                                       * (float)((float)((float)((float)v145 * (float)v145) + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v152 * (float)((float)((float)((float)v145 * (float)v145) + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143))) * (float)0.5)) * (float)v152) - (float)1.5)
                                                                                       * (float)v152))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v152
                                                                                               * (float)((float)((float)((float)v145 * (float)v145) + (float)((float)((float)v144 * (float)v144) + (float)((float)v143 * (float)v143))) * (float)0.5))
                                                                                       * (float)v152)
                                                                               - (float)1.5)
                                                               * (float)v152))
                                               * (float)((float)((float)((float)v145 * (float)v145)
                                                               + (float)((float)((float)v144 * (float)v144)
                                                                       + (float)((float)v143 * (float)v143)))
                                                       * (float)0.5))
                                       * (float)v153)
                               - (float)1.5)
               * (float)v153);
  *(float *)&v506.entityNumber = (float)v154 * (float)v145;
  *(float *)&v506.nextInHash = (float)v144 * (float)v154;
  *(float *)&v506.clip = (float)v143 * (float)v154;
  DefaultSpeedByCurrentWalkState = idAI2::GetDefaultSpeedByCurrentWalkState(this: v149);
  v156 = v138->__vftable;
  v498 = DefaultSpeedByCurrentWalkState;
  v157 = (float *)v156->GetGravityNormal(this: v138);
  v158 = -v157[2];
  v159 = -v157[1];
  v160 = -*v157;
  v161 = (float *)v138->GetAbsBounds(this: v138, a2: -1);
  v162 = (float)((float)(v161[3] - (float)((float)(v161[3] + *v161) * (float)0.5)) * (float)v160);
  v163 = __fabs((float)((float)(v161[5] - (float)((float)(v161[5] + v161[2]) * (float)0.5)) * (float)v158));
  v164 = __fabs((float)((float)(v161[4] - (float)((float)(v161[4] + v161[1]) * (float)0.5)) * (float)v159));
  v165 = (float)((float)((float)((float)(v161[5] + v161[2]) * (float)0.5) * (float)v158)
               + (float)((float)((float)((float)(v161[3] + *v161) * (float)0.5) * (float)v160)
                       + (float)((float)((float)(v161[4] + v161[1]) * (float)0.5) * (float)v159)));
  LODWORD(v478) = v161 + 3;
  v166 = __fabs(v162);
  GetSettings = v116->GetSettings;
  *(float *)&v506.callbacks = (float)((float)((float)v163 + (float)v164) + (float)v166) + (float)v165;
  v478 = GetSettings(this: (idAAS2 *)v116)->maxStepHeight
       + (float)((float)v165 - (float)((float)((float)v163 + (float)v164) + (float)v166));
  a_low = 1024;
  idObstacleAvoidance::AllocBuffers(this: &v7->oa);
  VertexArray = idObstacleAvoidance::GetVertexArray(this: &v7->oa);
  EdgeArray = idObstacleAvoidance::GetEdgeArray(this: &v7->oa);
  v492 = COERCE_FLOAT(idObstacleAvoidance::GetMaxVertices(this: &v7->oa));
  MaxEdges = (const idVec4 *)idObstacleAvoidance::GetMaxEdges(this: &v7->oa);
  v170 = (idAASPosition *)idActor::GetAASPosition(this: v7->ai, aas: v116);
  v171.__vftable = v116->__vftable;
  AreaNum = idAASPosition::GetAreaNum(this: v170);
  ((void (__fastcall *)(const idAAS2 *, int, int, obstacleVertex_t *, float *, obstacleEdge_t *, const idVec4 **, _BYTE *))v171.GetObstaclePVSObstacles)(
    a1: v116,
    a2: AreaNum,
    a3: 515,
    a4: VertexArray,
    a5: &v492,
    a6: EdgeArray,
    a7: &MaxEdges,
    a8: v535);
  idObstacleAvoidance::SetNumVertices(this: &v7->oa, num: SLODWORD(v492));
  idObstacleAvoidance::SetNumEdges(this: &v7->oa, num: (int)MaxEdges);
  v10->obstacleEntity.spawnId.value = 0x1FFF;
  v10->obstacleEntityThreshold = 0.0;
  v506.collisionResidency = (idPhysics::residency_t)&v10->obstacleEntity;
  RD_EventBegin(name: "idAnimBaseFSM::PathAroundObstacles -- add obstacles");
  LODWORD(v173) = "idAnimBaseFSM::PathAroundObstacles -- add obstacles";
  HIDWORD(v173) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v506.gravityVector.y, pl: v12, gMask: v173, label: v174);
  v501 = 0.0;
  v482 = COERCE_FLOAT(&ai_debugCam);
  v483 = (char *)&ai_debugReactionBasedMovement;
  if ( a_low > 0 )
  {
    v175 = ignore;
    v176 = v501;
    a = COERCE_FLOAT(v535);
    v177 = COERCE_FLOAT(v535);
    v178 = 1.1;
    v179 = 0.25;
    v500 = 4.0;
    v504 = 3.0;
    *(float *)&v493 = 0.94999999;
    v489 = 150.0;
    v484 = 1.1;
    v499 = -1.0;
    v481 = 0.25;
    *(float *)&v506.clipMask = 1000000.0;
    do
    {
      v180 = *(_DWORD *)LODWORD(v177);
      v181 = 4 * (*(_DWORD *)(*(_DWORD *)LODWORD(v177) + 12) + 21563);
      v182 = *(idAI2 **)((char *)&gameLocal->__vftable + v181);
      if ( v182 != v175
        && !idEntity::IsBoundTo(this: *(idEntity **)((char *)&gameLocal->__vftable + v181), master: v175) )
      {
        v472 = v7->ai;
        if ( v182 != v472 && !idEntity::IsBoundTo(this: v182, master: v472) )
        {
          v183 = idActor::CastTo(c: v182);
          if ( v183 == nullptr || !v183->IsDead(this: v183) )
          {
            v184 = (float *)v138->GetGravityNormal(this: v138);
            v185 = v184[1];
            v186 = -v184[2];
            v506.yawHistory[10] = -*v184;
            v506.yawHistory[12] = v186;
            v506.yawHistory[11] = -v185;
            idBounds::AxisProjection(
              this: (idBounds *)(v180 + 104),
              dir: (const idVec3 *)&v506.yawHistory[10],
              min: (float *)&v506.residencyQuery,
              max: (float *)&v506.collisionResidency);
            if ( *(float *)&v506.collisionResidency >= (double)v478
              && *(float *)&v506.residencyQuery.index <= (double)*(float *)&v506.callbacks )
            {
              type = idEntity::GetPhysics(this: v182)->type;
              if ( type == PHYSICS_AI || type == PHYSICS_PLAYER )
              {
                v199 = v7->ai;
                movePushStatus = v199->aiEditable.movement.movePushStatus;
                if ( movePushStatus == AIMOVEPUSHSTATUS_PUSH_PLAYERS_AND_NPCS
                  || movePushStatus == AIMOVEPUSHSTATUS_PUSH_OTHER_NPCS && type == PHYSICS_AI
                  || v199->aiEditable.movement.movePushStatus == AIMOVEPUSHSTATUS_PUSH_PLAYERS && type == PHYSICS_PLAYER )
                {
                  idAnimFSM_AAS::PushEntityIfClose(this: v7, otherEntity: v182);
                }
                else
                {
                  v201 = (float)(*(float *)(v180 + 36) - (float)v147);
                  v202 = (float)(*(float *)(v180 + 32) - (float)v148);
                  v203 = __fsqrts((float)((float)((float)v202 * (float)v202) + (float)((float)v201 * (float)v201)));
                  if ( v203 < *(float *)&v506.clipMask )
                  {
                    v204 = (idVec3 *)idEntity::GetPhysics(this: v182);
                    v205 = idAI2::CastTo(c: v182);
                    if ( v205 != nullptr )
                    {
                      RD_EventBegin(name: "idAnimBaseFSM::PathAroundObstacles -- logic for AI obstacles");
                      LODWORD(v213) = "idAnimBaseFSM::PathAroundObstacles -- logic for AI obstacles";
                      HIDWORD(v213) = 6;
                      idPLogScope::idPLogScope(
                        this: (idPLogScope *)&v506.originHistory[1].y,
                        pl: v12,
                        gMask: v213,
                        label: v214);
                      v215 = 0;
                      idPhysics_Actor::GetVelocityHistory(this: &v506, result: v204, timeBack: 350);
                      v216 = (float)(*(float *)&v506.type * (float)0.35000002);
                      v217 = (float)(*((float *)&v506.__vftable + 1) * (float)0.35000002);
                      v218 = (float)(*(float *)&v506.__vftable * (float)0.35000002);
                      OriginHistory = (float *)idPhysics_Actor::GetOriginHistory(
                                                 this: &v515,
                                                 result: v204,
                                                 timeBack: 350);
                      v221 = v10->wallCorners[0].x;
                      p_x = &v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].x;
                      v223 = v10->wallCorners[0].y;
                      v224 = (float)(OriginHistory[2] + (float)v216);
                      v225 = (float)(OriginHistory[1] + (float)v217);
                      v226 = (float)((float)v218 + *OriginHistory);
                      v475 = (float)v218 + *OriginHistory;
                      v506.originHistory[5].y = v221;
                      v506.originHistory[5].z = v223;
                      v477 = v224;
                      v227 = v10->wallCorners[0].z;
                      v476 = v225;
                      z_low = LODWORD(v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].z);
                      v229 = v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].x;
                      y_low = (contactInfo_t *)LODWORD(v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].y);
                      v231 = (float)((float)v224 - (float)v146);
                      *(float *)&v506.wasHistoryInitialized = 0.0;
                      v232 = (float)((float)v225 - (float)v147);
                      v506.originHistory[0].z = (float)v224 - (float)v146;
                      v233 = (float)((float)v226 - (float)v148);
                      v506.originHistory[0].x = (float)v226 - (float)v148;
                      v506.originHistory[0].y = (float)v225 - (float)v147;
                      v234 = 0;
                      v506.originHistory[6].x = v227;
                      v506.contacts.list = y_low;
                      v506.gravityNormal.z = v229;
                      v235 = (float)(v223 - (float)v147);
                      v506.masterDeltaYaw = v223 - (float)v147;
                      v236 = (float)(v221 - (float)v148);
                      v506.masterYaw = v221 - (float)v148;
                      v506.contacts.num = z_low;
                      if ( (float)((float)(*(float *)&v506.type * *(float *)&v506.type)
                                 + (float)((float)(*(float *)&v506.__vftable * *(float *)&v506.__vftable)
                                         + (float)(*((float *)&v506.__vftable + 1) * *((float *)&v506.__vftable + 1)))) <= 0.1 )
                        goto LABEL_85;
                      v237 = *((_DWORD *)v483 + 8);
                      if ( v237 > 0 )
                      {
                        if ( v237 == 2 )
                          goto LABEL_53;
                        if ( *(_DWORD *)(LODWORD(v482) + 32) != 0 )
                        {
                          v238 = v7->ai;
                          if ( v238 == idGameLocal::GetDebugEntity(this: gameLocal) )
                          {
LABEL_53:
                            v239 = v7->ai;
                            v240 = destination->y;
                            v241 = destination->z;
                            v506.yawHistory[2] = destination->x;
                            v506.yawHistory[3] = v240;
                            v506.yawHistory[4] = v241;
                            v242 = idEntity::GetPhysics(this: v239);
                            v243 = (int)v242->GetOrigin(this: v242, a2: 0);
                            ((void (__fastcall *)(idRenderWorld *, _DWORD, int, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
                              a1: clientGame->renderWorld,
                              a2: LODWORD(v506.gravityVector.x),
                              a3: v243,
                              a4: v10->wallCorners,
                              a5: v118);
                            ((void (__fastcall *)(idRenderWorld *, int *, idVec3 *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
                              a1: clientGame->renderWorld,
                              a2: v506.contactPhysicsIds.list,
                              a3: v10->wallCorners,
                              a4: &v10->wallCorners[1],
                              a5: v118);
                            ((void (__fastcall *)(idRenderWorld *, int, idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
                              a1: clientGame->renderWorld,
                              a2: v506.contactPhysicsIds.num,
                              a3: &v10->wallCorners[1],
                              a4: &v506.yawHistory[2],
                              a5: v118);
                          }
                          v226 = v475;
                          v225 = v476;
                        }
                      }
                      v473 = v205->aiEditable.movement.movePushStatus;
                      if ( v473 == AIMOVEPUSHSTATUS_PUSH_OTHER_NPCS || v473 == AIMOVEPUSHSTATUS_PUSH_PLAYERS_AND_NPCS )
                        goto LABEL_67;
                      v244 = *p_x;
                      v245 = v7->ai;
                      v246 = v205->entityNumber;
                      v247 = v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].z;
                      v506.originHistory[8].y = v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].y;
                      v506.originHistory[8].x = v244;
                      v248 = v245->entityNumber;
                      v219 = v248 - v246;
                      v506.originHistory[8].z = v247;
                      v215 = ((((v246 ^ v248) & 0x80000000) == 0) + (v248 >= v246)) & 1;
                      v249 = __fsqrts((float)((float)((float)v236 * (float)v236) + (float)((float)v235 * (float)v235)));
                      v250 = (float)(v506.originHistory[8].y - (float)v225);
                      v251 = (float)(v244 - (float)v226);
                      v252 = __fsqrts((float)((float)((float)v251 * (float)v251) + (float)((float)v250 * (float)v250)));
                      if ( v249 <= 0.1 || v252 <= 0.1 )
                        goto LABEL_68;
                      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                      frustrationOverTime = v10->frustrationOverTime;
                      if ( GameMs < frustrationOverTime
                        && frustrationOverTime < v205->aiVolatile.animation.animFSM.obstacleInfo.frustrationOverTime )
                      {
                        v215 = 1;
                        goto LABEL_68;
                      }
                      v255 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                      v256 = v205->aiVolatile.animation.animFSM.obstacleInfo.frustrationOverTime;
                      if ( v255 < v256 && v256 < v10->frustrationOverTime )
                        goto LABEL_67;
                      v257 = (float)((float)((float)((float)((float)v236 * (float)v233)
                                                   + (float)((float)v232 * (float)v235))
                                           + (float)((float)v231 * (float)0.0))
                                   / (float)v249);
                      v258 = (float)((float)((float)((float)((float)((float)v251 * (float)v233)
                                                           + (float)((float)v250 * (float)v232))
                                                   + (float)((float)v231 * (float)0.0))
                                           / (float)v252)
                                   * v499);
                      if ( v257 < v258 )
                      {
                        v215 = 1;
                        goto LABEL_68;
                      }
                      if ( v257 > v258 )
LABEL_67:
                        v215 = 0;
LABEL_68:
                      v259 = (float *)(*(int (__fastcall **)(idVec3 *, _DWORD, unsigned int))(LODWORD(v204->x) + 64))(
                                        a1: v204,
                                        a2: 0,
                                        a3: v219);
                      v475 = *v259;
                      v476 = v259[1];
                      v477 = v259[2];
                      v260 = idAI2::GetDefaultSpeedByCurrentWalkState(this: v205);
                      idVec3::Truncate(this: (idVec3 *)&v506, length: v260);
                      v261 = v475;
                      v262 = v477;
                      v263 = v476;
                      v264 = (float)((float)v203 / (float)((float)v260 + v498));
                      if ( v215 != 0 )
                      {
                        v265 = (float)((float)((float)((float)v203 / (float)((float)v260 + v498))
                                             * *(float *)&v506.__vftable)
                                     * (float)0.5);
                        v266 = (float)((float)(*(float *)&v506.type * (float)((float)v203 / (float)((float)v260 + v498)))
                                     * (float)0.5);
                        v267 = (float)((float)(*((float *)&v506.__vftable + 1)
                                             * (float)((float)v203 / (float)((float)v260 + v498)))
                                     * (float)0.5);
                      }
                      else
                      {
                        v265 = (float)((float)((float)((float)v203 / (float)((float)v260 + v498))
                                             * *(float *)&v506.__vftable)
                                     * (float)v178);
                        v266 = (float)((float)(*(float *)&v506.type * (float)((float)v203 / (float)((float)v260 + v498)))
                                     * (float)v178);
                        v267 = (float)((float)(*((float *)&v506.__vftable + 1)
                                             * (float)((float)v203 / (float)((float)v260 + v498)))
                                     * (float)v178);
                      }
                      v225 = (float)(v476 + (float)v267);
                      v476 = v476 + (float)v267;
                      v224 = (float)(v477 + (float)v266);
                      v477 = v477 + (float)v266;
                      v226 = (float)(v475 + (float)v265);
                      v475 = v475 + (float)v265;
                      if ( v215 != 0 )
                      {
LABEL_85:
                        v272 = *(float *)&v506.contacts.num;
                        v268 = *(float *)&v506.contacts.list;
                        v270 = v506.gravityNormal.z;
                      }
                      else
                      {
                        v268 = *(float *)&v506.contacts.list;
                        v269 = (float)(*(float *)&v506.contacts.list - (float)((float)v263 + (float)v267));
                        v270 = v506.gravityNormal.z;
                        v271 = (float)(v506.gravityNormal.z - (float)((float)v261 + (float)v265));
                        v272 = *(float *)&v506.contacts.num;
                        v273 = (float)(*(float *)&v506.contacts.num - (float)((float)v262 + (float)v266));
                        v274 = (float)((float)v264 * v489);
                        v275 = __fsqrts((float)((float)((float)v273 * (float)v273)
                                              + (float)((float)((float)v271 * (float)v271)
                                                      + (float)((float)v269 * (float)v269))));
                        v276 = idEntity::GetPhysics(this: v7->ai);
                        v277 = (float *)v276->GetOrigin(this: v276, a2: 0);
                        v278 = v10->wallCorners[0].y;
                        v279 = v10->wallCorners[0].x;
                        v280 = v277[1];
                        v281 = *v277;
                        v506.invMass = v10->wallCorners[0].z - v277[2];
                        v506.mass = (float)v278 - (float)v280;
                        v506.clipModelAxis.mat[2].z = (float)v279 - (float)v281;
                        idVec3::NormalizeFast(this: (idVec3 *)&v506.clipModelAxis.mat[2].z);
                        if ( (float)((float)(v506.invMass * *(float *)&v506.clip)
                                   + (float)((float)(v506.clipModelAxis.mat[2].z * *(float *)&v506.entityNumber)
                                           + (float)(v506.mass * *(float *)&v506.nextInHash))) < (double)*(float *)&v493 )
                          v274 = (float)((float)((float)((float)(*(float *)&v493
                                                               - (float)((float)(v506.invMass * *(float *)&v506.clip)
                                                                       + (float)((float)(v506.clipModelAxis.mat[2].z
                                                                                       * *(float *)&v506.entityNumber)
                                                                               + (float)(v506.mass
                                                                                       * *(float *)&v506.nextInHash))))
                                                       * v504)
                                               + (float)1.0)
                                       * (float)v274);
                        v224 = v477;
                        v225 = v476;
                        v226 = v475;
                        if ( v275 > v274 )
                        {
                          v272 = (float)((float)(v477 * (float)((float)1.0 - (float)((float)v274 / (float)v275)))
                                       + (float)((float)v272 * (float)((float)v274 / (float)v275)));
                          v268 = (float)((float)(v476 * (float)((float)1.0 - (float)((float)v274 / (float)v275)))
                                       + (float)((float)v268 * (float)((float)v274 / (float)v275)));
                          v270 = (float)((float)(v475 * (float)((float)1.0 - (float)((float)v274 / (float)v275)))
                                       + (float)((float)v270 * (float)((float)v274 / (float)v275)));
                        }
                        if ( v203 < v489 )
                        {
                          v234 = 1;
                          if ( v7->ai->aiVolatile.focus.enableAutoFocus )
                          {
                            if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < v10->updatedTime )
                              goto LABEL_84;
                            if ( (float)((float)(*(float *)&v506.clip * (float)v231)
                                       + (float)((float)((float)v233 * *(float *)&v506.entityNumber)
                                               + (float)(*(float *)&v506.nextInHash * (float)v232))) <= 0.0 )
                              goto LABEL_84;
                            *(idVec3 *)&v506.clipModelAxis.mat[1].y = v506.originHistory[0];
                            v506.clipModelAxis.mat[0] = *(idVec3 *)&v506.masterYaw;
                            v282 = idVec3::NormalizeFast(this: (idVec3 *)&v506.clipModelAxis.mat[1].y);
                            idVec3::NormalizeFast(this: v506.clipModelAxis.mat);
                            v283 = v10->newDest.y;
                            *(float *)&v506.contactPhysicsIds.granularity = v10->newDest.x;
                            v506.waterViscosity = 0.0;
                            v506.waterLevel = v283;
                            idVec3::NormalizeFast(this: (idVec3 *)&v506.contactPhysicsIds.granularity);
                            if ( (float)((float)(v506.clipModelAxis.mat[0].z * v506.waterViscosity)
                                       + (float)((float)(v506.waterLevel * v506.clipModelAxis.mat[0].y)
                                               + (float)(v506.clipModelAxis.mat[0].x
                                                       * *(float *)&v506.contactPhysicsIds.granularity))) >= (double)(float)((float)(v506.clipModelAxis.mat[2].x * v506.waterViscosity) + (float)((float)(v506.clipModelAxis.mat[1].z * v506.waterLevel) + (float)(v506.clipModelAxis.mat[1].y * *(float *)&v506.contactPhysicsIds.granularity)))
                              || v282 <= 0.1
                              || (v284 = (float)((float)((float)(v506.clipModelAxis.mat[1].y
                                                               * v506.clipModelAxis.mat[0].x)
                                                       + (float)((float)(v506.clipModelAxis.mat[1].z
                                                                       * v506.clipModelAxis.mat[0].y)
                                                               + (float)(v506.clipModelAxis.mat[2].x
                                                                       * v506.clipModelAxis.mat[0].z)))
                                               / (float)v282)) <= v10->obstacleEntityThreshold )
                            {
LABEL_84:
                              v224 = v477;
                              v225 = v476;
                              v226 = v475;
                            }
                            else
                            {
                              v224 = v477;
                              v225 = v476;
                              v226 = v475;
                              v10->obstacleEntity.spawnId.value = (gameLocal->spawnIds.ptr[v205->entityNumber] << 13)
                                                                | v205->entityNumber;
                              v10->obstacleEntityThreshold = v284;
                            }
                          }
                        }
                      }
                      if ( v234 == 0 )
                      {
                        v285 = *p_x;
                        v496.z = 0.0;
                        v286 = v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].z;
                        v506.originHistory[4].y = v205->aiVolatile.animation.animFSM.obstacleInfo.wallCorners[0].y;
                        v506.originHistory[4].x = v285;
                        v496.y = v506.originHistory[4].y - (float)v225;
                        v496.x = v285 - (float)v226;
                        v506.originHistory[4].z = v286;
                        if ( idVec3::NormalizeFast(this: &v496) <= 0.1 )
                        {
                          v270 = v226;
                          v268 = v225;
                          v272 = v224;
                        }
                        else
                        {
                          v272 = (float)((float)v224 + (float)(v496.z * v500));
                          v268 = (float)((float)v225 + (float)(v496.y * v500));
                          v270 = (float)((float)v226 + (float)(v496.x * v500));
                        }
                      }
                      v506.originHistory[7].y = 0.0;
                      v506.originHistory[6].z = (float)v270 - (float)v226;
                      v506.originHistory[7].x = (float)v268 - (float)v225;
                      if ( idVec3::NormalizeFast(this: (idVec3 *)&v506.originHistory[6].z) <= (double)idMath::FLT_SMALLEST_NON_DENORMAL )
                      {
                        v296 = 1.0;
                        v292 = 1.0;
                        v288 = 1.0;
                        v293 = 0.0;
                        v290 = 0.0;
                        v289 = 0.0;
                        v295 = 0.0;
                        v294 = 0.0;
                        v291 = 0.0;
                      }
                      else
                      {
                        v287 = (float *)idVec3::ToMat3(this: v534, result: (idMat3 *)&v506.originHistory[6].z);
                        v224 = v477;
                        v225 = v476;
                        v226 = v475;
                        v288 = *v287;
                        v289 = v287[1];
                        v290 = v287[2];
                        v291 = v287[3];
                        v292 = v287[4];
                        v293 = v287[5];
                        v294 = v287[6];
                        v295 = v287[7];
                        v296 = v287[8];
                      }
                      aiPathfindRadius = v205->aiConstants.physics.aiPathfindRadius;
                      v298 = __fsqrts((float)((float)((float)((float)v270 - (float)v226)
                                                    * (float)((float)v270 - (float)v226))
                                            + (float)((float)((float)v268 - (float)v225)
                                                    * (float)((float)v268 - (float)v225))));
                      if ( v215 == 0 )
                        aiPathfindRadius = (float)(v205->aiConstants.physics.aiPathfindRadius * v505);
                      v506.originHistory[10].x = (float)((float)v270 + (float)v226) * (float)0.5;
                      v506.originHistory[10].y = (float)((float)v268 + (float)v225) * (float)0.5;
                      v506.originHistory[10].z = (float)((float)v272 + (float)v224) * (float)0.5;
                      v506.originHistory[11].y = aiPathfindRadius;
                      v506.originHistory[11].z = aiPathfindRadius;
                      v506.originHistory[12].x = v288;
                      v506.originHistory[12].y = v289;
                      v506.originHistory[12].z = v290;
                      v506.originHistory[13].x = v291;
                      v506.originHistory[13].y = v292;
                      v506.originHistory[13].z = v293;
                      v506.originHistory[14].x = v294;
                      v506.originHistory[14].y = v295;
                      v506.originHistory[14].z = v296;
                      v506.originHistory[11].x = (float)((float)v298 * (float)0.5) + (float)aiPathfindRadius;
                      SpawnId = (const idSpawnId **)idGameLocal::GetSpawnId(
                                                      this: (idGameLocal *)&v490,
                                                      result: (idSpawnId *)gameLocal,
                                                      ent: v182);
                      idObstacleAvoidance::AddObstacle(
                        this: &v7->oa,
                        box: (const idBox *)&v506.originHistory[10],
                        id: *SpawnId,
                        soft: v182->clipModelInfo.softObstacle);
                      v300 = v483;
                      v301 = *((_DWORD *)v483 + 8);
                      if ( v301 > 0
                        && (v301 > 1
                         || *(_DWORD *)(LODWORD(v482) + 32) != 0
                         && (v302 = v7->ai) == idGameLocal::GetDebugEntity(this: gameLocal)) )
                      {
                        v506.originHistory[11].y = v506.originHistory[11].y + (float)aiPathfindRadius;
                        v506.originHistory[11].z = v506.originHistory[11].z + (float)aiPathfindRadius;
                        v506.originHistory[11].x = v506.originHistory[11].x + (float)aiPathfindRadius;
                        num = v506.contactPhysicsIds.num;
                        clientGame->renderWorld->DebugBox(
                          this: clientGame->renderWorld,
                          a2: (const idVec4 *)v506.contactPhysicsIds.num,
                          a3: (const idBox *)&v506.originHistory[10],
                          a4: v234 == 0 ? 16 : 250,
                          a5: true);
                        v305 = v215 != 0;
                        v304 = v506.gravityVector.x;
                        if ( !v305 )
                          v304 = *(float *)&num;
                        v306 = idEntity::GetPhysics(this: v7->ai);
                        v307 = (int)v306->GetOrigin(this: v306, a2: 0);
                        v308 = *(float *)&v506.contactPhysicsIds.size;
                        ((void (__fastcall *)(idRenderWorld *, _DWORD, int, float *, double))clientGame->renderWorld->DebugArrow)(
                          a1: clientGame->renderWorld,
                          a2: LODWORD(v304),
                          a3: v307,
                          a4: &v475,
                          a5: *(float *)&v506.contactPhysicsIds.size);
                        if ( *((_DWORD *)v300 + 8) == 1 )
                        {
                          v309 = idEntity::GetPhysics(this: v205);
                          v310 = (int)v309->GetOrigin(this: v309, a2: 0);
                          ((void (__fastcall *)(idRenderWorld *, _DWORD, float *, int, double))clientGame->renderWorld->DebugArrow)(
                            a1: clientGame->renderWorld,
                            a2: *(_DWORD *)&v506.contacts.granularity,
                            a3: &v475,
                            a4: v310,
                            a5: v308);
                        }
                      }
                      idPLogScope::~idPLogScope(this: (idPLogScope *)&v506.originHistory[1].y);
                      RD_EventEnd();
                      v146 = *(float *)v506.clipMasks;
                      v118 = v497;
                      v177 = a;
                      v14 = *(float *)&v506.contactPhysicsIds.size;
                      v175 = ignore;
                      v148 = *(float *)v506.clipModels;
                      v176 = v501;
                      v178 = v484;
                      v179 = v481;
                      goto LABEL_105;
                    }
                    idPhysics_Actor::GetVelocityHistory(
                      this: (idPhysics_Actor *)&v506.originHistory[15].y,
                      result: v204,
                      timeBack: 250);
                    v206 = (float)(v506.yawHistory[0] * (float)v179);
                    v207 = (float)(v506.originHistory[15].z * (float)v179);
                    v208 = (float)(v506.originHistory[15].y * (float)v179);
                    v209 = (float *)idPhysics_Actor::GetOriginHistory(
                                      this: (idPhysics_Actor *)&v515.gravityVector.y,
                                      result: v204,
                                      timeBack: 250);
                    v210 = (float)(v209[2] + (float)v206);
                    v211 = (float)(v209[1] + (float)v207);
                    v508.x = *v209 + (float)v208;
                    v508.z = v210;
                    v508.y = v211;
                    v212 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                                 this: (idGameLocal *)&v491,
                                                 result: (idSpawnId *)gameLocal,
                                                 ent: v182);
                    idObstacleAvoidance::AddObstacle(
                      this: &v7->oa,
                      bounds: (const idBounds *)(v180 + 80),
                      origin: &v508,
                      axis: (const idMat3 *)(v180 + 44),
                      id: *v212,
                      soft: v182->clipModelInfo.softObstacle);
                  }
                }
              }
              else
              {
                v188 = idDrone::CastTo(c: (idDrone *)v182);
                if ( v188 != nullptr )
                {
                  v190 = *(float *)(v180 + 36);
                  p_physicsId = &v515.physicsId;
                  v192 = *(float *)(v180 + 40);
                  v193 = (_DWORD *)(v180 + 40);
                  v506.originHistory[2].z = *(float *)(v180 + 32);
                  v194 = 9;
                  v506.originHistory[3].x = v190;
                  v506.originHistory[3].y = v192;
                  do
                  {
                    *++p_physicsId = *++v193;
                    --v194;
                  }
                  while ( v194 != 0 );
                  v195 = &v512;
                  v196 = (_DWORD *)(v180 + 76);
                  for ( i = 6; i != 0; --i )
                    *++v195 = *++v196;
                  idDrone::HandleObstacleAvoidance(
                    this: v188,
                    ai: v7->ai,
                    bounds: &v513,
                    origin: (idVec3 *)&v506.originHistory[2].z,
                    otherAxis: (idMat3 *)&v515.entityNumber);
                  v198 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                               this: (idGameLocal *)&v487,
                                               result: (idSpawnId *)gameLocal,
                                               ent: v182);
                  idObstacleAvoidance::AddObstacle(
                    this: &v7->oa,
                    bounds: &v513,
                    origin: (const idVec3 *)&v506.originHistory[2].z,
                    axis: (const idMat3 *)&v515.entityNumber,
                    id: *v198,
                    soft: v182->clipModelInfo.softObstacle);
                }
                else
                {
                  v189 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                               this: (idGameLocal *)&v488,
                                               result: (idSpawnId *)gameLocal,
                                               ent: v182);
                  idObstacleAvoidance::AddObstacle(
                    this: &v7->oa,
                    bounds: (const idBounds *)(v180 + 80),
                    origin: (const idVec3 *)(v180 + 32),
                    axis: (const idMat3 *)(v180 + 44),
                    id: *v189,
                    soft: v182->clipModelInfo.softObstacle);
                }
              }
            }
          }
        }
      }
LABEL_105:
      ++LODWORD(v176);
      LODWORD(v177) += 4;
      v501 = v176;
      a = v177;
    }
    while ( SLODWORD(v176) < a_low );
  }
  if ( v506.gravityVector.y >= 0.0 )
  {
    v311 = v506.gravityVector.z;
    v312 = *(_DWORD *)(LODWORD(v506.gravityVector.z) + 16) + 16 * LODWORD(v506.gravityVector.y);
    v313 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v314 = *(_QWORD *)(v312 + 8);
    HIDWORD(v314) = *(_DWORD *)(v312 + 4);
    LODWORD(v315) = v313 - v314;
    *(_QWORD *)(v312 + 8) = v315;
    *(_DWORD *)(LODWORD(v311) + 32) = HIDWORD(v314);
  }
  RD_EventEnd();
  RD_EventBegin(name: "idAnimFSM_AAS::PathAroundObstacles -- misc2");
  groupMask = v12->groupMask;
  *((_DWORD *)&v506.collisionResidency + 1) = v12;
  v317 = -1;
  v506.collisionResidency = -1;
  if ( (groupMask & 6) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &v12->logEntries, newSize: v12->logEntries.num + 1);
    v318 = v12->logEntries.num;
    v319 = v12->logEntries.size;
    if ( v318 >= v319 )
    {
      v320 = (int)&v12->logEntries.list[v319 - 1];
    }
    else
    {
      v320 = (int)&v12->logEntries.list[v318];
      v12->logEntries.num = v318 + 1;
    }
    idMem::PopHeap(this: &mem);
    *(_DWORD *)v320 = "idAnimFSM_AAS::PathAroundObstacles -- misc2";
    *(_DWORD *)(v320 + 4) = v12->lastEntry;
    v317 = v12->logEntries.num - 1;
    v12->lastEntry = v317;
    v506.collisionResidency = v317;
    LODWORD(v321) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    *(_QWORD *)(v320 + 8) = v321;
  }
  obstaclePath_t::obstaclePath_t(this: (obstaclePath_t *)&v515.yawHistory[6]);
  RD_EventBegin(name: "idAnimBaseFSM::PathAroundObstacles -- submit job");
  v322 = v12->groupMask;
  v323 = NAN;
  v479 = v12;
  v478 = NAN;
  if ( (v322 & 6) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &v12->logEntries, newSize: v12->logEntries.num + 1);
    v324 = v12->logEntries.num;
    v325 = v12->logEntries.size;
    if ( v324 >= v325 )
    {
      v326 = (int)&v12->logEntries.list[v325 - 1];
    }
    else
    {
      v326 = (int)&v12->logEntries.list[v324];
      v12->logEntries.num = v324 + 1;
    }
    idMem::PopHeap(this: &mem);
    *(_DWORD *)v326 = "idAnimBaseFSM::PathAroundObstacles -- submit job";
    *(_DWORD *)(v326 + 4) = v12->lastEntry;
    LODWORD(v323) = v12->logEntries.num - 1;
    *(float *)&v12->lastEntry = v323;
    v478 = v323;
    LODWORD(v327) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    *(_QWORD *)(v326 + 8) = v327;
  }
  v328 = (int)v7->ai->GetAAS(this: v7->ai);
  v329 = idEntity::GetPhysics(this: v7->ai);
  obstaclePerceptionRadius = v7->ai->aiEditable.perception.obstaclePerceptionRadius;
  v331 = (const idVec3 *)((*(int (__fastcall **)(int))(*(_DWORD *)v328 + 20))(a1: v328) + 136);
  v332 = v329->GetBounds(this: v329, a2: -1);
  v333 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v334 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  PathAroundObstacles = idObstacleAvoidance::FindPathAroundObstacles(
                          this: &v7->oa,
                          path: (obstaclePath_t *)&v515.yawHistory[6],
                          time: v334,
                          gameMsPerFrame: v333,
                          bbox: v332,
                          gravity: v331,
                          obstacleRadius: obstaclePerceptionRadius,
                          frameMoveDist: v118,
                          cornerCircleRadius: v474,
                          flags: v336,
                          route: v335,
                          traceSet: v448,
                          a13: v449,
                          a14: v450,
                          a15: v451,
                          a16: v452,
                          a17: v453,
                          a18: v454,
                          a19: v455,
                          a20: v456,
                          a21: v457,
                          a22: v458,
                          a23: v459,
                          a24: v460,
                          a25: v461,
                          a26: v462,
                          a27: v463,
                          a28: v464,
                          a29: v465,
                          a30: v466,
                          a31: (int)&a_low,
                          a32: v467,
                          a33: v480,
                          a34: v468,
                          a35: (const obstacleRoute_t *)&v515.contacts.num,
                          a36: v469,
                          a37: &v7->obstacleTraces);
  if ( v323 >= 0.0 )
  {
    v338 = (int)&v12->logEntries.list[LODWORD(v323)];
    v339 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v340 = *(_DWORD *)(v338 + 4);
    LODWORD(v341) = v339 - *(_DWORD *)(v338 + 12);
    *(_QWORD *)(v338 + 8) = v341;
    v12->lastEntry = v340;
  }
  RD_EventEnd();
  LODWORD(v478) = &v10->endPos;
  v10->startPos.x = startPos->x;
  v10->startPos.y = startPos->y;
  v10->startPos.z = startPos->z;
  v10->endPos.x = destination->x;
  v10->endPos.y = destination->y;
  v10->endPos.z = destination->z;
  if ( ignore != nullptr )
  {
    v478 = *(float *)&ignore->entityNumber;
    v10->ignore.spawnId.value = (gameLocal->spawnIds.ptr[LODWORD(v478)] << 13) | LODWORD(v478);
  }
  else
  {
    v10->ignore.spawnId.value = 0x1FFF;
  }
  v342 = v529;
  v343 = v530;
  v344 = v532;
  v10->wallCorners[0].x = v528;
  v10->wallCorners[0].y = v342;
  LODWORD(v478) = &v10->wallCorners[1];
  v10->wallCorners[0].z = v343;
  v10->wallCorners[1].y = v344;
  v345 = v533;
  v10->wallCorners[1].x = v531;
  v10->wallCorners[1].z = v345;
  if ( ai_debugMove.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
  {
    renderWorld = clientGame->renderWorld;
    v347 = renderWorld->__vftable;
    v348 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v349 = startPos;
    v347->DebugPoint(
      this: renderWorld,
      a2: (const idVec4 *)LODWORD(v506.originHistory[2].x),
      a3: startPos,
      a4: v348,
      a5: false);
    v350 = clientGame->renderWorld;
    v351 = v350->__vftable;
    v352 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v351->DebugPoint(
      this: v350,
      a2: (const idVec4 *)v506.contacts.size,
      a3: (const idVec3 *)&v515.yawHistory[6],
      a4: v352,
      a5: false);
    v353 = clientGame->renderWorld;
    v354 = v353->__vftable;
    v355 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    v354->DebugPoint(
      this: v353,
      a2: (const idVec4 *)p_newDest,
      a3: (const idVec3 *)&v515.yawHistory[9],
      a4: v355,
      a5: false);
  }
  else
  {
    v349 = startPos;
  }
  v356 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v521);
  if ( v356 != nullptr )
  {
    p_newDest = v356->entityNumber;
    v10->firstObstacle.spawnId.value = (gameLocal->spawnIds.ptr[p_newDest] << 13) | p_newDest;
  }
  else
  {
    v10->firstObstacle.spawnId.value = 0x1FFF;
  }
  v357 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v522);
  if ( v357 != nullptr )
  {
    p_newDest = v357->entityNumber;
    v10->startObstacle.spawnId.value = (gameLocal->spawnIds.ptr[p_newDest] << 13) | p_newDest;
  }
  else
  {
    v10->startObstacle.spawnId.value = 0x1FFF;
  }
  v358 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: v526);
  p_endObstacle = &v10->endObstacle;
  if ( v358 != nullptr )
  {
    p_newDest = v358->entityNumber;
    p_endObstacle->spawnId.value = (gameLocal->spawnIds.ptr[p_newDest] << 13) | p_newDest;
  }
  else
  {
    p_endObstacle->spawnId.value = 0x1FFF;
  }
  v10->length = v527;
  v360 = &v515.yawHistory[3
                        * ((float)((float)((float)(v349->x * v517)
                                         + (float)((float)(v518 * v349->y) + (float)(v519 * v349->z)))
                                 + v520) > -0.0099999998)
                        + 6];
  p_newDest = (int)&v10->newDest;
  v361 = *v360;
  v362 = v360[1];
  newPos->z = v360[2];
  newPos->y = v362;
  newPos->x = v361;
  v10->newDest.x = v361;
  v10->newDest.y = newPos->y;
  v10->newDest.z = newPos->z;
  RD_EventBegin(name: "idAnimBaseFSM::PathAroundObstacles -- copy to cached corners");
  v363 = v12->groupMask;
  v364 = -1;
  v486 = v12;
  p_newDest = -1;
  if ( (v363 & 6) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &v12->logEntries, newSize: v12->logEntries.num + 1);
    v365 = v12->logEntries.num;
    v366 = v12->logEntries.size;
    if ( v365 >= v366 )
    {
      v367 = (int)&v12->logEntries.list[v366 - 1];
    }
    else
    {
      v367 = (int)&v12->logEntries.list[v365];
      v12->logEntries.num = v365 + 1;
    }
    idMem::PopHeap(this: &mem);
    *(_DWORD *)v367 = "idAnimBaseFSM::PathAroundObstacles -- copy to cached corners";
    *(_DWORD *)(v367 + 4) = v12->lastEntry;
    v364 = v12->logEntries.num - 1;
    v12->lastEntry = v364;
    p_newDest = v364;
    LODWORD(v368) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    *(_QWORD *)(v367 + 8) = v368;
  }
  v369 = 0;
  if ( v516 > 0 )
  {
    v370 = &v515.yawHistory[4];
    do
    {
      idNpCornerInfo::idNpCornerInfo(this: &v514);
      v371 = v370[2];
      v370 += 3;
      v514.position.y = *v370;
      v514.position.x = v371;
      v514.position.z = v146;
      idList<idNpCornerInfo,5>::Append(this: &v7->cachedCorners, obj: &v514);
      idNpLink::~idNpLink(this: &v514.link);
      ++v369;
    }
    while ( v369 < v516 );
  }
  if ( v364 >= 0 )
  {
    v372 = (int)&v12->logEntries.list[v364];
    v373 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v374 = *(_DWORD *)(v372 + 4);
    LODWORD(v375) = v373 - *(_DWORD *)(v372 + 12);
    *(_QWORD *)(v372 + 8) = v375;
    v12->lastEntry = v374;
  }
  RD_EventEnd();
  value = p_endObstacle->spawnId.value;
  v377 = gameLocal;
  v378 = (p_endObstacle->spawnId.value & 0x1FFF) + 29755;
  p_newDest = (int)&v10->endObstacle;
  if ( *((_DWORD *)&gameLocal->__vftable + v378) == value >> 13 )
  {
    p_newDest = (int)&v10->endObstacle;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v379 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v380 = idEntity::CastTo(c: v379);
      v377 = gameLocal;
      v381 = v380;
    }
    else
    {
      v381 = nullptr;
    }
    v382 = v7->currentMove.destEnt.spawnId.value;
    HIDWORD(v383) = 4 * ((v382 & 0x1FFF) + 29755);
    p_newDest = (int)&v7->currentMove.destEnt;
    if ( *(idGameLocal_vtbl **)((char *)&v377->__vftable + HIDWORD(v383)) == (idGameLocal_vtbl *)(v382 >> 13)
      && (v384 = v377->entities.ptr[v382 & 0x1FFF]) != nullptr )
    {
      v385 = idEntity::CastTo(c: v384);
      v377 = gameLocal;
    }
    else
    {
      v385 = nullptr;
    }
    if ( v381 != v385 )
    {
      obstacleStopDistance = v7->ai->aiEditable.behaviors.decl->obstacleStopDistance;
      LODWORD(v383) = obstacleStopDistance * obstacleStopDistance;
      v387 = (float)((float)((float)(v525 - v349->z) * (float)(v525 - v349->z))
                   + (float)((float)((float)(v523 - v349->x) * (float)(v523 - v349->x))
                           + (float)((float)(v524 - v349->y) * (float)(v524 - v349->y))));
      *(_QWORD *)&v506.originHistory[1].y = v383;
      if ( v387 < (float)v383 )
      {
        if ( v317 >= RESIDENCY_NOT_TESTED )
        {
          v388 = (int)&v12->logEntries.list[v317];
          v389 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v390 = *(_DWORD *)(v388 + 4);
          LODWORD(v391) = v389 - *(_DWORD *)(v388 + 12);
          *(_QWORD *)(v388 + 8) = v391;
          v12->lastEntry = v390;
        }
        RD_EventEnd();
        if ( v495.logIndex >= 0 )
        {
          pLog = v495.pLog;
          v393 = &v495.pLog->logEntries.list[v495.logIndex];
          v394 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          totalTicks = v393->totalTicks;
          HIDWORD(totalTicks) = v393->parent;
          LODWORD(v396) = v394 - totalTicks;
          v393->totalTicks = v396;
          pLog->lastEntry = HIDWORD(totalTicks);
        }
        RD_EventEnd();
        if ( v506.gravityNormal.x >= 0.0 )
        {
          v397 = v506.gravityNormal.y;
          v398 = *(_DWORD *)(LODWORD(v506.gravityNormal.y) + 16) + 16 * LODWORD(v506.gravityNormal.x);
          v399 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          v400 = *(_QWORD *)(v398 + 8);
          HIDWORD(v400) = *(_DWORD *)(v398 + 4);
          LODWORD(v401) = v399 - v400;
          *(_QWORD *)(v398 + 8) = v401;
          *(_DWORD *)(LODWORD(v397) + 32) = HIDWORD(v400);
        }
LABEL_163:
        RD_EventEnd();
        return 0;
      }
    }
  }
  if ( !PathAroundObstacles )
  {
    if ( v317 >= RESIDENCY_NOT_TESTED )
    {
      v403 = (int)&v12->logEntries.list[v317];
      v404 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v405 = *(_DWORD *)(v403 + 4);
      LODWORD(v406) = v404 - *(_DWORD *)(v403 + 12);
      *(_QWORD *)(v403 + 8) = v406;
      v12->lastEntry = v405;
    }
    RD_EventEnd();
    if ( v495.logIndex >= 0 )
    {
      v407 = v495.pLog;
      v408 = &v495.pLog->logEntries.list[v495.logIndex];
      v409 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v410 = v408->totalTicks;
      HIDWORD(v410) = v408->parent;
      LODWORD(v411) = v409 - v410;
      v408->totalTicks = v411;
      v407->lastEntry = HIDWORD(v410);
    }
    RD_EventEnd();
    if ( v506.gravityNormal.x >= 0.0 )
    {
      v412 = v506.gravityNormal.y;
      v413 = *(_DWORD *)(LODWORD(v506.gravityNormal.y) + 16) + 16 * LODWORD(v506.gravityNormal.x);
      v414 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v415 = *(_QWORD *)(v413 + 8);
      HIDWORD(v415) = *(_DWORD *)(v413 + 4);
      LODWORD(v416) = v414 - v415;
      *(_QWORD *)(v413 + 8) = v416;
      *(_DWORD *)(LODWORD(v412) + 32) = HIDWORD(v415);
    }
    goto LABEL_163;
  }
  v417 = *((_DWORD *)v483 + 8);
  if ( v417 > 1 )
    goto LABEL_180;
  if ( v417 == 1 && *(_DWORD *)(LODWORD(v482) + 32) != 0 )
  {
    v418 = v7->ai;
    v419 = v377->debugEntity.spawnId.value;
    if ( v377->spawnIds.ptr[v419 & 0x1FFF] == v419 >> 13 )
    {
      v420 = v377->entities.ptr[v419 & 0x1FFF];
      if ( v420 != nullptr )
        v420 = idEntity::CastTo(c: v420);
    }
    else
    {
      v420 = nullptr;
    }
    if ( v418 == v420 )
    {
LABEL_180:
      v421 = idEntity::GetPhysics(this: v7->ai);
      v422 = (int)v421->GetOrigin(this: v421, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, int, int, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: v506.lastHistorySaveTime,
        a3: v422,
        a4: &v10->newDest,
        a5: v14);
      v423 = idEntity::GetPhysics(this: v7->ai);
      v423->GetLinearVelocity(this: (idPhysics_Actor *)&v506.yawHistory[6], result: (idVec3 *)v423, a3: 0);
      v424 = idEntity::GetPhysics(this: v7->ai);
      v425 = (float *)v424->GetOrigin(this: v424, a2: 0);
      v427 = (float)(v425[2] + v506.yawHistory[8]);
      v428 = (float)(v425[1] + v506.yawHistory[7]);
      v429 = (float)(v506.yawHistory[6] + *v425);
      v426 = v7->ai;
      v506.yawHistory[14] = v429;
      v507 = v427;
      v506.yawHistory[15] = v428;
      v430 = idEntity::GetPhysics(this: v426);
      v431 = (int)v430->GetOrigin(this: v430, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, _DWORD, int, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: LODWORD(v506.gravityVector.x),
        a3: v431,
        a4: &v506.yawHistory[14],
        a5: v14);
      v432 = idEntity::GetPhysics(this: v7->ai);
      v433 = (int)v432->GetOrigin(this: v432, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, int *, int, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: v506.contactPhysicsIds.list,
        a3: v433,
        a4: v10->wallCorners,
        a5: v14);
    }
  }
  if ( v317 >= RESIDENCY_NOT_TESTED )
  {
    v434 = (int)&v12->logEntries.list[v317];
    v435 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v436 = *(_DWORD *)(v434 + 4);
    LODWORD(v437) = v435 - *(_DWORD *)(v434 + 12);
    *(_QWORD *)(v434 + 8) = v437;
    v12->lastEntry = v436;
  }
  RD_EventEnd();
  if ( v495.logIndex >= 0 )
  {
    v438 = v495.pLog;
    v439 = &v495.pLog->logEntries.list[v495.logIndex];
    v440 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v441 = v439->totalTicks;
    HIDWORD(v441) = v439->parent;
    LODWORD(v442) = v440 - v441;
    v439->totalTicks = v442;
    v438->lastEntry = HIDWORD(v441);
  }
  RD_EventEnd();
  if ( v506.gravityNormal.x >= 0.0 )
  {
    v443 = v506.gravityNormal.y;
    v444 = *(_DWORD *)(LODWORD(v506.gravityNormal.y) + 16) + 16 * LODWORD(v506.gravityNormal.x);
    v445 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v446 = *(_QWORD *)(v444 + 8);
    HIDWORD(v446) = *(_DWORD *)(v444 + 4);
    LODWORD(v447) = v445 - v446;
    *(_QWORD *)(v444 + 8) = v447;
    *(_DWORD *)(LODWORD(v443) + 32) = HIDWORD(v446);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$508428
// EA  : 0x82A786C0
// RVA : 0x00A786C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508428()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6080));
}


// ========================================================================
// __unwind$508429
// EA  : 0x82A786E8
// RVA : 0x00A786E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508429()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 336));
}


// ========================================================================
// __unwind$508431
// EA  : 0x82A78710
// RVA : 0x00A78710
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508431()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6081));
}


// ========================================================================
// __unwind$508432
// EA  : 0x82A78738
// RVA : 0x00A78738
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508432()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 216));
}


// ========================================================================
// __unwind$508433
// EA  : 0x82A78760
// RVA : 0x00A78760
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508433()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6082));
}


// ========================================================================
// __unwind$508434
// EA  : 0x82A78788
// RVA : 0x00A78788
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508434()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 328));
}


// ========================================================================
// __unwind$508435
// EA  : 0x82A787B0
// RVA : 0x00A787B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508435()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6083));
}


// ========================================================================
// __unwind$508436
// EA  : 0x82A787D8
// RVA : 0x00A787D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508436()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 488));
}


// ========================================================================
// __unwind$508437
// EA  : 0x82A78800
// RVA : 0x00A78800
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508437()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6084));
}


// ========================================================================
// __unwind$508438
// EA  : 0x82A78828
// RVA : 0x00A78828
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508438()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 312));
}


// ========================================================================
// __unwind$508439
// EA  : 0x82A78850
// RVA : 0x00A78850
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508439()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6085));
}


// ========================================================================
// __unwind$508440
// EA  : 0x82A78878
// RVA : 0x00A78878
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508440()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 144));
}


// ========================================================================
// __unwind$508441
// EA  : 0x82A788A0
// RVA : 0x00A788A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508441()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 6384 + 6086));
}


// ========================================================================
// __unwind$508442
// EA  : 0x82A788C8
// RVA : 0x00A788C8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508442()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 6384 + 176));
}


// ========================================================================
// __unwind$508443
// EA  : 0x82A788F0
// RVA : 0x00A788F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_508443()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(v0 - 6384 + 832));
}


// ========================================================================
// ?MoveFailed@idAnimBaseFSM@@UAAXW4aiMoveReason_t@@W4aiMoveStatus_t@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82A78918
// RVA : 0x00A78918
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::MoveFailed(
        idAnimBaseFSM *this,
        const aiMoveReason_t reason,
        const aiMoveStatus_t status,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *time)
{
  char v5; // r29
  char v6; // r28
  float v8; // r30
  int moveFrustrationThreshold_low; // r11
  float v10; // r9
  int v11; // r7
  int v12; // r10
  float moveFrustrationThreshold; // ctr
  float obstacleEntityThreshold; // r11
  int v15; // r11
  int v16; // r11

  v5 = reason;
  v6 = status;
  v8 = NAN;
  *(_DWORD *)(*((_DWORD *)this - 5) + 58484) = idGameTimeManager::GetGameMs(
                                                 this: &clientGame->gameTimeManager,
                                                 type: GAMETIME_SCALED);
  moveFrustrationThreshold_low = LODWORD(this->obstacleInfo.moveFrustrationThreshold);
  if ( moveFrustrationThreshold_low >= this->obstacleInfo.minFrustratedTime )
  {
    v10 = 0.0;
    v11 = 0x7FFFFFFF;
    if ( moveFrustrationThreshold_low > 0 )
    {
      v12 = 0;
      moveFrustrationThreshold = this->obstacleInfo.moveFrustrationThreshold;
      obstacleEntityThreshold = this->obstacleInfo.obstacleEntityThreshold;
      do
      {
        v15 = *(_DWORD *)(LODWORD(obstacleEntityThreshold) + 4);
        if ( v15 < v11 )
        {
          v11 = v15;
          v8 = v10;
        }
        v12 += 8;
        ++LODWORD(v10);
        LODWORD(obstacleEntityThreshold) = v12 + LODWORD(this->obstacleInfo.obstacleEntityThreshold);
        --LODWORD(moveFrustrationThreshold);
      }
      while ( moveFrustrationThreshold != 0.0 );
    }
  }
  else
  {
    v8 = this->obstacleInfo.moveFrustrationThreshold;
    idList<moveFailureInfo_t,5>::Alloc(this: (idList<moveFailureInfo_t,5> *)&this->obstacleInfo.obstacleEntityThreshold);
  }
  v16 = LODWORD(this->obstacleInfo.obstacleEntityThreshold) + 8 * LODWORD(v8);
  *(_BYTE *)v16 = v5;
  *(_BYTE *)(v16 + 1) = v6;
  *(idTypesafeNumber<int,enum gameTimeUnique_t> *)(v16 + 4) = (idTypesafeNumber<int,enum gameTimeUnique_t>)time->value;
}


// ========================================================================
// ?UpdateCachedCorners@idAnimFSM_AAS@@MAAXXZ
// EA  : 0x82A789F8
// RVA : 0x00A789F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM_AAS::UpdateCachedCorners(idAnimFSM_AAS *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  aiMoveStatus_t v4; // r3
  double z; // fp13
  double y; // fp11
  double x; // fp12
  double v8; // fp10
  aiArrivalOrientation_t arriveOrient; // r11
  idMat3 *p_arriveAxis; // r11
  char v11; // r11
  idAI2 *ai; // r3
  idMat3 *v13; // r29
  const idDeclAIBehavior *decl; // r10
  bool v15; // r11
  idAIOrientation *BodyOrientation; // r3
  double v17; // fp10
  double v18; // fp13
  double v19; // fp9
  double v20; // fp12
  double v21; // fp1
  double v22; // fp1
  int value; // r10
  idEntity *v24; // r3
  idEntity *v25; // r7
  idPhysics *Physics; // r3
  int v27; // r3
  int v28; // r9
  float v29; // r6
  float v30; // r5
  int num; // r8
  double v32; // fp0
  int v33; // r10
  double v34; // fp13
  double v35; // fp12
  idNpCornerInfo *v36; // r11
  int v37; // r11
  idAI2 *v38; // r3
  idPhysics *v39; // r3
  int v40; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v42; // r30
  int v43; // r3
  __int64 totalTicks; // r11
  __int64 v45; // r9
  int GameMs; // [sp+50h] [-80h] BYREF
  void *p_obstacleGoal; // [sp+54h] [-7Ch] BYREF
  idPLogScope v48; // [sp+58h] [-78h] BYREF
  idVec3 v49; // [sp+60h] [-70h] BYREF
  idVec3 v50; // [sp+70h] [-60h] BYREF
  float v51[4]; // [sp+80h] [-50h] BYREF
  idVec3 v52[5]; // [sp+90h] [-40h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::UpdateCachedCorners");
  LODWORD(v2) = "idAnimFSM_AAS::UpdateCachedCorners";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v48, pl: &::pLog, gMask: v2, label: v3);
  idAnimBaseFSM::ClearCachedCorners(this);
  if ( this->IsMoveDone(this) )
  {
    idPLogScope::~idPLogScope(this: &v48);
  }
  else
  {
    v4 = idAnimFSM_AAS::InternalTestMoveToPoint(
           this,
           cmd: (idVec3 *)&this->currentMove,
           aasStartingPoint: v52,
           aasFinalPoint: &v50,
           nextPoint: &v49,
           totalTravelTime: &GameMs,
           startAreaNum: (int *)&p_obstacleGoal,
           localPath: &this->lastPath);
    z = v50.z;
    y = v50.y;
    x = v50.x;
    this->status = v4;
    if ( v4 == AIMOVESTATUS_NOT_IN_AAS )
    {
      this->lastPath.type = 0;
      this->lastPath.moveGoal.x = x;
      this->lastPath.moveGoal.y = y;
      this->lastPath.moveGoal.z = z;
      this->lastPath.moveAreaNum = 0;
      this->lastPath.firstEdge.toAreaNum = 0;
      this->lastPath.firstEdge.edgeNum = 0;
      this->lastPath.firstEdge.edgePoint.z = 0.0;
      this->lastPath.firstEdge.edgePoint.y = 0.0;
      this->lastPath.firstEdge.edgePoint.x = 0.0;
      this->lastPath.reachIndex.value = -1;
      this->lastPath.travelTime = 1;
      this->lastPath.traversalIndex = 0;
      this->lastPath.traversalStart.z = 0.0;
      this->lastPath.traversalStart.y = 0.0;
      this->lastPath.traversalStart.x = 0.0;
      v8 = v52[0].z;
      this->lastPath.traversalEnd.z = 0.0;
      this->lastPath.traversalEnd.y = 0.0;
      p_obstacleGoal = &this->lastPath.obstacleGoal;
      this->lastPath.traversalEnd.x = 0.0;
      this->lastPath.dependencyIndex.value = -1;
      v49.x = x;
      v49.y = y;
      v49.z = z;
      this->lastPath.obstacleGoal.x = x;
      this->lastPath.obstacleGoal.y = y;
      this->lastPath.obstacleGoal.z = z;
      if ( z > v8 )
        v8 = z;
      arriveOrient = this->currentMove.arriveOrient;
      this->lastPath.pathMaxHeight = v8;
      this->lastPath.obstacleRoute.numAreas = 0;
      if ( arriveOrient == AIARRIVAL_ORIENT_ALIGN )
      {
        p_arriveAxis = &this->currentMove.arriveAxis;
      }
      else
      {
        v51[1] = 0.0;
        v51[2] = 0.0;
        p_arriveAxis = (idMat3 *)v51;
        v51[0] = 1.0;
      }
      this->lastPath.obstacleRoute.endAlignDir.x = p_arriveAxis->mat[0].x;
      this->lastPath.obstacleRoute.endAlignDir.y = p_arriveAxis->mat[0].y;
      this->lastPath.obstacleRoute.endAlignDir.z = p_arriveAxis->mat[0].z;
      this->lastPath.obstacleRoute.endTurnRadius = 0.0;
    }
    else if ( (unsigned int)v4 >= AIMOVESTATUS_ERROR )
    {
      idAnimBaseFSM::SetMoveStatus(this, _status: v4);
      idAnimBaseFSM::SetDestination(this, cmd: &idAIMoveCmd::s_null);
      idPLogScope::~idPLogScope(this: &v48);
      goto LABEL_41;
    }
    if ( v49.x != x || v49.y != y || (v11 = 1, v49.z != z) )
      v11 = 0;
    if ( v11 != 0 && this->currentMove.arriveOrient == AIARRIVAL_ORIENT_ALIGN )
    {
      ai = this->ai;
      v13 = &this->currentMove.arriveAxis;
      decl = ai->aiEditable.behaviors.decl;
      p_obstacleGoal = ai;
      v15 = ai_useTurningCircles.valueInteger > 0
         && (ai_useTurningCircles.valueInteger > 1 || (*((_BYTE *)decl + 85) & 4) != 0);
      if ( v15 || ai_showTurningCircles.valueInteger != 0 )
      {
        p_obstacleGoal = ai;
        BodyOrientation = idAI2::GetBodyOrientation(this: ai);
        v17 = (float)(BodyOrientation->axis.mat[0].y * this->currentMove.arriveAxis.mat[0].y);
        v18 = this->currentMove.arriveAxis.mat[0].z;
        v19 = BodyOrientation->axis.mat[0].z;
        v20 = v13->mat[0].x;
        p_obstacleGoal = &BodyOrientation->axis;
        if ( (float)((float)((float)v20 * BodyOrientation->axis.mat[0].x)
                   + (float)((float)((float)v19 * (float)v18) + (float)v17)) < (double)ai_turningCircleAlignmentTolerance.valueFloat )
        {
          v21 = idAI2::CalcMovementTurnRate(
                  this: this->ai,
                  idealDir: &this->orientMove.idealDir,
                  curDir: this->orientMove.axis.mat);
          v22 = idAI2::CalcTurnRadius(this: this->ai, speed: 80.0, turnRate: v21);
          this->lastPath.obstacleRoute.endAlignDir.x = v13->mat[0].x;
          this->lastPath.obstacleRoute.endAlignDir.y = this->currentMove.arriveAxis.mat[0].y;
          this->lastPath.obstacleRoute.endAlignDir.z = this->currentMove.arriveAxis.mat[0].z;
          this->lastPath.obstacleRoute.endTurnRadius = v22;
        }
      }
    }
    if ( this->status == AIMOVESTATUS_NOT_IN_AAS
      || ((value = this->currentMove.destEnt.spawnId.value,
           p_obstacleGoal = &this->currentMove.destEnt,
           gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
       || (v24 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        ? (v25 = nullptr)
        : (v25 = idEntity::CastTo(c: v24)),
          (unsigned __int8)idAnimFSM_AAS::PathAroundObstacles(
                             this,
                             startPos: v52,
                             destination: &v49,
                             obstacleRoute: &this->lastPath.obstacleRoute,
                             ignore: v25,
                             newPos: &v49,
                             obstacleInfo: &this->obstacleInfo) != 0) )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v27 = (int)Physics->GetGravityNormal(this: Physics);
      v28 = 0;
      v29 = *(float *)(v27 + 4);
      v30 = *(float *)(v27 + 8);
      num = this->cachedCorners.num;
      v49.x = *(float *)v27;
      v49.y = v29;
      v49.z = v30;
      if ( num > 0 )
      {
        v32 = v49.z;
        v33 = 0;
        v34 = v49.y;
        v35 = v49.x;
        do
        {
          ++v28;
          v36 = &this->cachedCorners.list[v33++];
          v36->areaNormal.x = v35;
          v36->areaNormal.y = v34;
          v36->areaNormal.z = v32;
        }
        while ( v28 < this->cachedCorners.num );
      }
      p_obstacleGoal = (void *)this->cachedCorners.num;
      if ( (int)p_obstacleGoal > 0 )
        *((_BYTE *)&this->cachedCorners.list[(int)p_obstacleGoal - 1] + 56) |= 0x80u;
      v37 = GameMs;
      this->status = AIMOVESTATUS_MOVING;
      v38 = this->ai;
      this->lastTravelTime = v37;
      v39 = idEntity::GetPhysics(this: v38);
      v40 = (int)v39->GetBounds(this: v39, a2: -1);
      idAnimFSM::ClampCachedCornersToGround(this, dropHeight: (float)(*(float *)(v40 + 20) - *(float *)(v40 + 8)));
      if ( v48.logIndex >= 0 )
      {
        pLog = v48.pLog;
        v42 = &v48.pLog->logEntries.list[v48.logIndex];
        v43 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v42->totalTicks;
        HIDWORD(totalTicks) = v42->parent;
        LODWORD(v45) = v43 - totalTicks;
        v42->totalTicks = v45;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
    }
    else
    {
      this->status = AIMOVESTATUS_OBSTRUCTED;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->MoveFailed(
        this: &this->idAIMoveInterface,
        a2: this->currentMove.moveReason,
        a3: this->status,
        a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&GameMs);
      idAnimBaseFSM::SetDestination(this, cmd: &idAIMoveCmd::s_null);
      idPLogScope::~idPLogScope(this: &v48);
    }
  }
LABEL_41:
  RD_EventEnd();
}


// ========================================================================
// __unwind$511034
// EA  : 0x82A78F38
// RVA : 0x00A78F38
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511034()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 156));
}


// ========================================================================
// __unwind$511035
// EA  : 0x82A78F60
// RVA : 0x00A78F60
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511035()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// ?PostMove@idAnimFSM@@IAAXXZ
// EA  : 0x82A78F90
// RVA : 0x00A78F90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::PostMove(idAnimFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idAIMoveInfo *cachedMoveInfoIntermediate; // r29
  idAI2 *ai; // r29
  unsigned int v6; // r3
  unsigned __int64 v7; // r6
  const char *v8; // r7
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  idPhysics *Physics; // r3
  int v15; // r3
  double valueFloat; // fp31
  idPhysics *v17; // r29
  __int64 v18; // r7
  double v19; // fp30
  const idVec3 *v20; // r3
  idAngles *v21; // r29
  idAngles *v22; // r3
  double v23; // fp9
  double v24; // fp7
  int v25; // [sp+8h] [-D8h]
  int v26; // [sp+Ch] [-D4h]
  int v27; // [sp+10h] [-D0h]
  int v28; // [sp+14h] [-CCh]
  int v29; // [sp+18h] [-C8h]
  int v30; // [sp+1Ch] [-C4h]
  idMat3 v31; // [sp+50h] [-90h] BYREF
  int v32; // [sp+74h] [-6Ch]
  int v33; // [sp+78h] [-68h]
  idAngles v34; // [sp+80h] [-60h] BYREF
  idMat3 v35; // [sp+90h] [-50h] BYREF

  RD_EventBegin(name: "idAnimFSM::PostMove");
  LODWORD(v2) = "idAnimFSM::PostMove";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v31.mat[2], pl: &pLog, gMask: v2, label: v3);
  cachedMoveInfoIntermediate = this->cachedMoveInfoIntermediate;
  if ( cachedMoveInfoIntermediate == nullptr )
    cachedMoveInfoIntermediate = this->cachedMoveInfoDest;
  if ( (this->currentState->GetStateFlags(this: this->currentState) & 1) == 0 )
  {
    if ( (unsigned __int8)idAnimBaseFSM::GetUserChannelIsDeltaDriven(this) != 0 )
    {
      idAnimBaseFSM::MoveAIDeltaCorrection(this);
    }
    else if ( this->emergencyLerp )
    {
      idAnimBaseFSM::MoveAIEmergencyLerp(this);
    }
    else if ( cachedMoveInfoIntermediate != nullptr )
    {
      idAnimFSM::MoveAIAlongPath(this, moveInfo: cachedMoveInfoIntermediate);
    }
    else
    {
      ai = this->ai;
      v6 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      idPhysics_AI::SetDelta(this: &ai->aiVolatile.physics.object, d: &vec3_origin, ticksPerFrame: v6);
    }
  }
  RD_EventBegin(name: "idAnimFSM::PostMove -- misc");
  LODWORD(v7) = "idAnimFSM::PostMove -- misc";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v31.mat[1].y, pl: &pLog, gMask: v7, label: v8);
  if ( (!this->moveOrientationOnPath
     || (unsigned __int8)idAnimBaseFSM::TreeUsesBlendVar(
                           this,
                           blendVarIndex: this->animBlendVars.bodyMoveAngle.index,
                           a3: v13,
                           a4: v12,
                           a5: v11,
                           a6: v10,
                           a7: v9,
                           a8: this->moveOrientationOnPath,
                           a9: v25,
                           a10: v26,
                           a11: v27,
                           a12: v28,
                           a13: v29,
                           a14: v30) != 0)
    && this->cachedCorners.num > 0 )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    ((void (__fastcall *)(float *, idAnimFSM *, int, double))this->GetPathDelta)(
      a1: &v31.mat[2].z,
      a2: this,
      a3: v15,
      a4: 1.0);
    if ( ((v32 | v33 | LODWORD(v31.mat[2].z)) & 0x7FFFFFFF) != 0 )
    {
      idVec3::NormalizeFast(this: (idVec3 *)&v31.mat[2].z);
      idAIOrientation::SetIdealDir(this: &this->orientMove, ai: this->ai, dir: (const idVec3 *)&v31.mat[2].z);
    }
  }
  if ( this->stompMoveOrientationAxis )
  {
    idAIOrientation::SetAxis(this: &this->orientMove, ai: this->ai, dir: &this->orientMove.idealDir);
    this->stompMoveOrientationAxis = false;
  }
  else
  {
    valueFloat = ai_moveOrientTurnRate.valueFloat;
    v17 = idEntity::GetPhysics(this: this->ai);
    LODWORD(v18) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v18) = v17->__vftable;
    *(_QWORD *)&v31.mat[0].x = v18;
    v19 = (float)((float)v18 * (float)0.001);
    v20 = (const idVec3 *)(*(int (__fastcall **)(idPhysics *))(HIDWORD(v18) + 104))(a1: v17);
    idAIOrientation::UpdateAxis(this: &this->orientMove, normal: v20, turnRate: valueFloat, timeSeconds: v19);
  }
  v21 = idMat3::ToAngles(this: &v31, result: (idAngles *)&this->orientBody.axis);
  v22 = idMat3::ToAngles(this: &v35, result: (idAngles *)&this->orientMove.axis);
  v23 = (float)(v22->roll - v21->roll);
  v24 = (float)(v22->yaw - v21->yaw);
  v34.pitch = v22->pitch - v21->pitch;
  v34.roll = v23;
  v34.yaw = v24;
  idAngles::Normalize180(this: &v34);
  this->animBlendVars.bodyMoveAngle.value = v34.yaw;
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v31.mat[1].y);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v31.mat[2]);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511450
// EA  : 0x82A79290
// RVA : 0x00A79290
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511450()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 156));
}


// ========================================================================
// __unwind$511451
// EA  : 0x82A792B8
// RVA : 0x00A792B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511451()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 104));
}


// ========================================================================
// __unwind$511452
// EA  : 0x82A792E0
// RVA : 0x00A792E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511452()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 157));
}


// ========================================================================
// __unwind$511453
// EA  : 0x82A79308
// RVA : 0x00A79308
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511453()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 96));
}


// ========================================================================
// ?TestMove@idAnimFSM_AAS@@UBA?AW4aiMoveStatus_t@@ABVidAIMoveParms@@AAVidVec3@@1AAH@Z
// EA  : 0x82A79338
// RVA : 0x00A79338
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

int __fastcall idAnimFSM_AAS::TestMove(
        idAnimFSM_AAS *this,
        const idAIMoveParms *parms,
        idVec3 *aasFinalPoint,
        idVec3 *nextPoint,
        int *totalTravelTime)
{
  int value; // r10
  idEntity *v11; // r3
  int v12; // r9
  double goalTolerance; // fp31
  idEntity *v14; // r3
  idEntity *v15; // r4
  int v17; // r9
  idEntity *v18; // r3
  int v19; // r9
  idEntity *v20; // r3
  idEntity *v21; // r3
  int v22; // r30
  int v23; // [sp+50h] [-2C0h] BYREF
  idVec3 v24[2]; // [sp+58h] [-2B8h] BYREF
  idAIMoveCmd v25; // [sp+70h] [-2A0h] BYREF
  idAAS2Path v26; // [sp+110h] [-200h] BYREF

  value = parms->goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v11 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v11 != nullptr && idEntity::CastTo(c: v11) != nullptr )
    {
      v12 = parms->goalEntity.spawnId.value;
      goalTolerance = parms->goalTolerance;
      if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
        && (v14 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      if ( ((unsigned __int8 (__fastcall *)(idAnimFSM_AAS *, idEntity *, double))this->GetState)(
             a1: this,
             a2: v15,
             a3: goalTolerance) != 0 )
        return 0;
    }
  }
  idAIMoveCmd::idAIMoveCmd(this: &v25, user: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM.cpp(3312) : TestMove");
  v17 = parms->goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
    && (v18 = gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v18) != nullptr )
  {
    v19 = parms->goalEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 && (v20 = gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
    {
      v21 = idEntity::CastTo(c: v20);
      idAIMoveCmd::SetDest(this: &v25, ent: v21, entType: DEST_ENT_NONE);
    }
    else
    {
      idAIMoveCmd::SetDest(this: &v25, ent: nullptr, entType: DEST_ENT_NONE);
    }
  }
  else
  {
    idAIMoveCmd::SetDest(this: &v25, dest: &parms->goalOrigin, entType: DEST_ENT_NONE);
  }
  idAAS2Path::idAAS2Path(this: &v26);
  v22 = idAnimFSM_AAS::InternalTestMoveToPoint(
          this: (idAnimFSM_AAS *)((char *)this - 32),
          cmd: (idVec3 *)&v25,
          aasStartingPoint: v24,
          aasFinalPoint,
          nextPoint,
          totalTravelTime,
          startAreaNum: &v23,
          localPath: &v26);
  idAIMoveCmd::~idAIMoveCmd(this: &v25);
  return v22;
}


// ========================================================================
// __unwind$511605
// EA  : 0x82A79530
// RVA : 0x00A79530
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511605()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 784 + 112));
}


// ========================================================================
// ?InternalUpdate@idAnimFSM@@MAAXXZ
// EA  : 0x82A79560
// RVA : 0x00A79560
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __fastcall idAnimFSM::InternalUpdate(idAnimFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned __int64 v4; // r6
  const char *v5; // r7
  float *ai; // r11
  idAnimFSM_vtbl *v7; // r7
  idPLogScope v8; // [sp+58h] [-108h] BYREF
  idPLogScope v9[2]; // [sp+60h] [-100h] BYREF
  idAIMoveInfo v10; // [sp+70h] [-F0h] BYREF
  idAIMoveInfo v11[2]; // [sp+C0h] [-A0h] BYREF

  RD_EventBegin(name: "idAnimFSM::InternalUpdate");
  LODWORD(v2) = "idAnimFSM::InternalUpdate";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: &v8, pl: &pLog, gMask: v2, label: v3);
  RD_EventBegin(name: "idAnimFSM::InternalUpdate -- misc1");
  LODWORD(v4) = "idAnimFSM::InternalUpdate -- misc1";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v4, label: v5);
  this->ai->UpdateModelTransform(this: this->ai);
  this->desiredMoveAxis = this->orientBody.axis;
  idAIMoveInfo::idAIMoveInfo(this: v11);
  idAIMoveInfo::idAIMoveInfo(this: &v10);
  this->cachedMoveInfoDest = nullptr;
  this->cachedMoveInfoIntermediate = nullptr;
  idAnimBaseFSM::ClearCachedCorners(this);
  if ( this->intermediateMove.destType != MOVE_NONE )
  {
    idLobbyBackend360::StartArbitration(pexcept: (_exception *)&this->intermediateMove);
    this->ai->aiVolatile.debugging.errorFlags |= this->GetMoveInfo(this, a2: &this->currentMove, a3: &v10);
    this->cachedMoveInfoIntermediate = &v10;
  }
  if ( this->currentMove.destType != MOVE_NONE )
  {
    idLobbyBackend360::StartArbitration(pexcept: (_exception *)&this->currentMove);
    this->ai->aiVolatile.debugging.errorFlags |= this->GetMoveInfo(this, a2: &this->currentMove, a3: v11);
    this->cachedMoveInfoDest = v11;
  }
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
  this->SubmitNavTraces(this);
  this->UpdateCachedCorners(this);
  this->RecordNavTraceResults(this);
  idAnimFSM::PreMove(this);
  idAIFSMLite::InternalUpdate(this);
  idAnimFSM::PostMove(this);
  if ( (unsigned __int8)idAnimBaseFSM::GetUserChannelIsDeltaDriven(this) == 0 )
    this->InternalUpdateBodyRotation(this);
  ai = (float *)this->ai;
  ai[1868] = this->orientBody.axis.mat[0].x;
  ai[1869] = this->orientBody.axis.mat[0].y;
  ai[1870] = this->orientBody.axis.mat[0].z;
  ai[1871] = this->orientBody.axis.mat[1].x;
  ai[1872] = this->orientBody.axis.mat[1].y;
  ai[1873] = this->orientBody.axis.mat[1].z;
  ai[1874] = this->orientBody.axis.mat[2].x;
  ai[1875] = this->orientBody.axis.mat[2].y;
  ai[1876] = this->orientBody.axis.mat[2].z;
  v7 = this->idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable;
  this->cachedMoveInfoDest = nullptr;
  this->cachedMoveInfoIntermediate = nullptr;
  v7->UpdateBlendVariables(this);
  idPLogScope::~idPLogScope(this: &v8);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511825
// EA  : 0x82A79840
// RVA : 0x00A79840
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511825()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 272));
}


// ========================================================================
// __unwind$511826
// EA  : 0x82A79868
// RVA : 0x00A79868
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511826()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 88));
}


// ========================================================================
// __unwind$511827
// EA  : 0x82A79890
// RVA : 0x00A79890
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511827()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 352 + 273));
}


// ========================================================================
// __unwind$511828
// EA  : 0x82A798B8
// RVA : 0x00A798B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void _unwind_511828()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 352 + 96));
}


// ========================================================================
// `dynamic initializer for 'ai_debugMoveFSM''
// EA  : 0x83368288
// RVA : 0x01368288
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugMoveFSM__()
{
  idCVar::idCVar(
    this: &ai_debugMoveFSM,
    name: "ai_debugMoveFSM",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugMoveFSM__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugMoveFSMAvoidance''
// EA  : 0x833682E0
// RVA : 0x013682E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugMoveFSMAvoidance__()
{
  idCVar::idCVar(
    this: &ai_debugMoveFSMAvoidance,
    name: "ai_debugMoveFSMAvoidance",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugMoveFSMAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'ai_avoidanceEnabled''
// EA  : 0x83368338
// RVA : 0x01368338
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_avoidanceEnabled__()
{
  idCVar::idCVar(
    this: &ai_avoidanceEnabled,
    name: "ai_avoidanceEnabled",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_avoidanceEnabled__);
}


// ========================================================================
// `dynamic initializer for 'ai_arrivalFallbackDistance''
// EA  : 0x83368390
// RVA : 0x01368390
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_arrivalFallbackDistance__()
{
  idCVar::idCVar(
    this: &ai_arrivalFallbackDistance,
    name: "ai_arrivalFallbackDistance",
    value: "40.0",
    flags: 4,
    description: "distance to destination under which any arrival will be considered, no matter how bad",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_arrivalFallbackDistance__);
}


// ========================================================================
// `dynamic initializer for 'ai_useStepTransitions''
// EA  : 0x833683E8
// RVA : 0x013683E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useStepTransitions__()
{
  idCVar::idCVar(
    this: &ai_useStepTransitions,
    name: "ai_useStepTransitions",
    value: "1",
    flags: 1,
    description: "enable/disable step transitions.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useStepTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_useTurnTransitions''
// EA  : 0x83368440
// RVA : 0x01368440
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useTurnTransitions__()
{
  idCVar::idCVar(
    this: &ai_useTurnTransitions,
    name: "ai_useTurnTransitions",
    value: "1",
    flags: 1,
    description: "enable/disable braking turn transitions.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useTurnTransitions__);
}


// ========================================================================
// `dynamic initializer for 'ai_enablePreArrivals''
// EA  : 0x83368498
// RVA : 0x01368498
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_enablePreArrivals__()
{
  idCVar::idCVar(
    this: &ai_enablePreArrivals,
    name: "ai_enablePreArrivals",
    value: "0",
    flags: 1,
    description: "enable or disable pre-arrival deceleration animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_enablePreArrivals__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugTakeOffPoints''
// EA  : 0x833684F0
// RVA : 0x013684F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugTakeOffPoints__()
{
  idCVar::idCVar(
    this: &ai_debugTakeOffPoints,
    name: "ai_debugTakeOffPoints",
    value: "0",
    flags: 1,
    description: "show information about takeoff points",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugTakeOffPoints__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugLandingPoints''
// EA  : 0x83368548
// RVA : 0x01368548
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugLandingPoints__()
{
  idCVar::idCVar(
    this: &ai_debugLandingPoints,
    name: "ai_debugLandingPoints",
    value: "0",
    flags: 1,
    description: "show information about landing points",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugLandingPoints__);
}


// ========================================================================
// `dynamic initializer for 'pm_enableCustomPlayerRepulsors''
// EA  : 0x833685A0
// RVA : 0x013685A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_enableCustomPlayerRepulsors__()
{
  idCVar::idCVar(
    this: &pm_enableCustomPlayerRepulsors,
    name: "pm_enableCustomPlayerRepulsors",
    value: "1",
    flags: 1,
    description: "enables custom repulsors for ai vs player clipping",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_enableCustomPlayerRepulsors__);
}


// ========================================================================
// `dynamic initializer for 'ai_useAnimBasedMovement''
// EA  : 0x833685F8
// RVA : 0x013685F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useAnimBasedMovement__()
{
  idCVar::idCVar(
    this: &ai_useAnimBasedMovement,
    name: "ai_useAnimBasedMovement",
    value: "0",
    flags: 1,
    description: "enable/disable anim based movement.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useAnimBasedMovement__);
}


// ========================================================================
// `dynamic initializer for 'ai_moveOrientTurnRate''
// EA  : 0x83368650
// RVA : 0x01368650
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_moveOrientTurnRate__()
{
  idCVar::idCVar(
    this: &ai_moveOrientTurnRate,
    name: "ai_moveOrientTurnRate",
    value: "720",
    flags: 4,
    description: "turn speed for move orientation following path",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_moveOrientTurnRate__);
}


// ========================================================================
// `dynamic initializer for 'ai_useMoveFSM''
// EA  : 0x833686A8
// RVA : 0x013686A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useMoveFSM__()
{
  idCVar::idCVar(
    this: &ai_useMoveFSM,
    name: "ai_useMoveFSM",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useMoveFSM__);
}

