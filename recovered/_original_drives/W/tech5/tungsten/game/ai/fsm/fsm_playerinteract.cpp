
// ========================================================================
// ?Evaluate@PCI_CurrentInteractionDisappeared@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE5C40
// RVA : 0x00AE5C40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_CurrentInteractionDisappeared::Evaluate(
        PCI_CurrentInteractionDisappeared *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const idDeclJob *interactionJob; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  if ( idAI2::GetCurrentPlayerInteraction(this: ai) == nullptr )
    return TRANSCODE_PCI_PLAYERINTERACTION_DISAPPEARED;
  interactionJob = idAI2::GetCurrentPlayerInteraction(this: ai)->interactionJob;
  result = 0;
  if ( interactionJob == nullptr )
    return TRANSCODE_PCI_PLAYERINTERACTION_DISAPPEARED;
  return result;
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5C98
// RVA : 0x00AE5C98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_Default::InternalInitState(
        idPlayerInteract_Default *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_IsAnimWebTransitioning::Type,
    nextStateType: &idPlayerInteract_WaitOnTransition::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_StartInteraction::Type,
    nextStateType: &idPlayerInteract_StartInteraction::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_WaitOnTransition@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5D00
// RVA : 0x00AE5D00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitOnTransition::InternalInitState(
        idPlayerInteract_WaitOnTransition *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_TransitionFinished::Type,
    nextStateType: &idPlayerInteract_StartInteraction::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_StartInteraction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5D18
// RVA : 0x00AE5D18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_StartInteraction::InternalInitState(
        idPlayerInteract_StartInteraction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_AtInteractionPoint::Type,
    nextStateType: &idPlayerInteract_ReachedInteractionPoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_MoveToInteractionPoint::Type,
    nextStateType: &idPlayerInteract_MoveToInteractionPoint::Type);
}


// ========================================================================
// ?Evaluate@PCI_MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE5D98
// RVA : 0x00AE5D98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_MoveFailed::Evaluate(
        PCI_MoveFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3

  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return __CFADD__(MoveInterface->GetMoveStatus(this: MoveInterface) - 2, -2147483646) ? 0 : 0x8F;
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_MoveToInteractionPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5DE8
// RVA : 0x00AE5DE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_MoveToInteractionPoint::InternalInitState(
        idPlayerInteract_MoveToInteractionPoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_MoveFailed::Type,
    nextStateType: &idPlayerInteract_ReachedInteractionPoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ReachedInteractionPoint::Type,
    nextStateType: &idPlayerInteract_ReachedInteractionPoint::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_AtInteractionPoint::Type,
    nextStateType: &idPlayerInteract_ReachedInteractionPoint::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_ReachedInteractionPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5E68
// RVA : 0x00AE5E68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ReachedInteractionPoint::InternalInitState(
        idPlayerInteract_ReachedInteractionPoint *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobCompleteVO_EARLY::Type,
    nextStateType: &idPlayerInteract_DeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_WaitForInteraction::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_ProcessInteraction::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_WaitForInteraction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5F08
// RVA : 0x00AE5F08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitForInteraction::InternalInitState(
        idPlayerInteract_WaitForInteraction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_ProcessInteraction::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobCompleteVO_EARLY::Type,
    nextStateType: &idPlayerInteract_DeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldCompleteEmptyJob::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_EmptyInteraction::Type,
    nextStateType: &idPlayerInteract_ProcessEmptyInteraction::Type);
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverNonJobVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE5FC0
// RVA : 0x00AE5FC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_ShouldDeliverNonJobVO::Evaluate(
        PCI_ShouldDeliverNonJobVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 150;
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_ProcessInteraction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE5FC8
// RVA : 0x00AE5FC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ProcessInteraction::InternalInitState(
        idPlayerInteract_ProcessInteraction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobFailedVO::Type,
    nextStateType: &idPlayerInteract_DeliverJobFailedVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobOfferVO::Type,
    nextStateType: &idPlayerInteract_DeliverJobOfferVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobEndVO::Type,
    nextStateType: &idPlayerInteract_DeliverJobEndVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobCompleteVO::Type,
    nextStateType: &idPlayerInteract_DeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverJobInProgressVO::Type,
    nextStateType: &idPlayerInteract_DeliverJobInProgressVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_IsMerchant::Type,
    nextStateType: &idPlayerInteract_DeliverNonJobGUIVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldDeliverNonJobVO::Type,
    nextStateType: &idPlayerInteract_DeliverNonJobVO::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverNonJobGUIVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE60B8
// RVA : 0x00AE60B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverNonJobGUIVO::InternalInitState(
        idPlayerInteract_DeliverNonJobGUIVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_IsMerchant::Type,
    nextStateType: &idPlayerInteract_MerchantInteract::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverNonJobVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6120
// RVA : 0x00AE6120
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverNonJobVO::InternalInitState(
        idPlayerInteract_DeliverNonJobVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_TriggerPostMessageEnt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_TriggerPostMessageEnt::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_TriggerPostMessageEnt@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6188
// RVA : 0x00AE6188
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_TriggerPostMessageEnt::InternalInitState(
        idPlayerInteract_TriggerPostMessageEnt *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_NonJobDeliverJobCompleteVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE61F0
// RVA : 0x00AE61F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_NonJobDeliverJobCompleteVO::InternalInitState(
        idPlayerInteract_NonJobDeliverJobCompleteVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverJobOfferVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6258
// RVA : 0x00AE6258
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobOfferVO::InternalInitState(
        idPlayerInteract_DeliverJobOfferVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished_With_Delay::Type,
    nextStateType: &idPlayerInteract_DeliverJobEndVO::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_DeliverJobEndVO::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverJobEndVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE62C0
// RVA : 0x00AE62C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobEndVO::InternalInitState(
        idPlayerInteract_DeliverJobEndVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished_Or_PlayerSelected::Type,
    nextStateType: &idPlayerInteract_WaitForJobChoice::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverJobCompleteVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6328
// RVA : 0x00AE6328
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobCompleteVO::InternalInitState(
        idPlayerInteract_DeliverJobCompleteVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished_With_Delay::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverJobFailedVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6390
// RVA : 0x00AE6390
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobFailedVO::InternalInitState(
        idPlayerInteract_DeliverJobFailedVO *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_DeliverJobEndVO::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_DeliverJobInProgressVO@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE63F8
// RVA : 0x00AE63F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobInProgressVO::InternalInitState(
        idPlayerInteract_SayGoodbye *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_WaitForJobChoice@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6460
// RVA : 0x00AE6460
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitForJobChoice::InternalInitState(
        idPlayerInteract_WaitForJobChoice *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_CurrentInteractionDisappeared::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerAcceptedJob::Type,
    nextStateType: &idPlayerInteract_PlayerAcceptedJob::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerDeclinedJob::Type,
    nextStateType: &idPlayerInteract_PlayerDeclinedJob::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_PlayerAcceptedJob@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6500
// RVA : 0x00AE6500
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerAcceptedJob::InternalInitState(
        idPlayerInteract_PlayerAcceptedJob *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ShouldProcessInteraction::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_PlayerLeft@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6568
// RVA : 0x00AE6568
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerLeft::InternalInitState(
        idPlayerInteract_PlayerLeft *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_ChildFSMAndVOFinished::Type,
    nextStateType: &idAIStateDone::Type);
  idState::AddEventTransition(
    this,
    fsm,
    transType: &PCI_PlayerReturned::Type,
    nextStateType: &idPlayerInteract_Default::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_MerchantInteractLoop@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE65D0
// RVA : 0x00AE65D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_MerchantInteractLoop::InternalInitState(
        idPlayerInteract_MerchantInteractLoop *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerLeft::Type,
    nextStateType: &idPlayerInteract_PlayerLeft::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerPurchasedItem::Type,
    nextStateType: &idPlayerInteract_PlayerPurchasedItem::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_PlayerClosedMerchantMenu::Type,
    nextStateType: &idPlayerInteract_PlayerClosedMerchantMenu::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_PlayerPurchasedItem@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6650
// RVA : 0x00AE6650
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerPurchasedItem::InternalInitState(
        idPlayerInteract_PlayerPurchasedItem *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_MerchantInteractLoop::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_ProcessEmptyInteraction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6668
// RVA : 0x00AE6668
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ProcessEmptyInteraction::InternalInitState(
        idPlayerInteract_PlayerClosedMerchantMenu *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_VOFinished::Type,
    nextStateType: &idPlayerInteract_WaitBriefly::Type);
}


// ========================================================================
// ?InternalInitState@idPlayerInteract_WaitBriefly@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AE6680
// RVA : 0x00AE6680
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitBriefly::InternalInitState(
        idPlayerInteract_WaitBriefly *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &PCI_HasMoreInteractions::Type,
    nextStateType: &idPlayerInteract_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &PCI_WaitFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?InitStates@idPlayerInteractFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AE66E8
// RVA : 0x00AE66E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteractFSM::InitStates(idPlayerInteractFSM *this, const idFiniteStateMachineParams *parms)
{
  idAIFSM::InitStates(this, params: parms);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateWaitOnTransition);
  this->AddState(this, a2: &this->stateStartInteraction);
  this->AddState(this, a2: &this->stateMoveToInteractionPoint);
  this->AddState(this, a2: &this->stateReachedInteractionPoint);
  this->AddState(this, a2: &this->stateWaitForInteraction);
  this->AddState(this, a2: &this->stateProcessInteraction);
  this->AddState(this, a2: &this->stateProcessEmptyInteraction);
  this->AddState(this, a2: &this->stateDeliverNonJobVO);
  this->AddState(this, a2: &this->stateDeliverNonJobGUIVO);
  this->AddState(this, a2: &this->stateDeliverJobOfferVO);
  this->AddState(this, a2: &this->stateDeliverJobEndVO);
  this->AddState(this, a2: &this->stateDeliverJobCompleteVO);
  this->AddState(this, a2: &this->stateDeliverJobFailedVO);
  this->AddState(this, a2: &this->stateDeliverJobInProgressVO);
  this->AddState(this, a2: &this->stateTriggerPostMessageEnt);
  this->AddState(this, a2: &this->stateNonJobDeliverJobCompleteVO);
  this->AddState(this, a2: &this->stateWaitForJobChoice);
  this->AddState(this, a2: &this->statePlayerAcceptedJob);
  this->AddState(this, a2: &this->statePlayerDeclinedJob);
  this->AddState(this, a2: &this->stateSayGoodbye);
  this->AddState(this, a2: &this->stateWaitBriefly);
  this->AddState(this, a2: &this->statePlayerLeft);
  this->AddState(this, a2: &this->stateMerchantInteract);
  this->AddState(this, a2: &this->stateMerchantInteractLoop);
  this->AddState(this, a2: &this->statePlayerPurchasedItem);
  this->AddState(this, a2: &this->statePlayerClosedMerchantMenu);
}


// ========================================================================
// ?Evaluate@PCI_VOFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE69A0
// RVA : 0x00AE69A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_VOFinished::Evaluate(
        PCI_VOFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiVolatile.faceMgr.voiceOver != nullptr ? 0 : 0x8C;
}


// ========================================================================
// ?Evaluate@PCI_ChildFSMAndVOFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE69C0
// RVA : 0x00AE69C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_ChildFSMAndVOFinished::Evaluate(
        PCI_ChildFSMAndVOFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath != nullptr && idFiniteStateMachine::GetStatus(this: FullPath) != 0 )
    return 0;
  else
    return ai->aiVolatile.faceMgr.voiceOver != nullptr ? 0 : 0x8C;
}


// ========================================================================
// ?Evaluate@PCI_VOFinished_With_Delay@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE6A40
// RVA : 0x00AE6A40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_VOFinished_With_Delay::Evaluate(
        PCI_VOFinished_With_Delay *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  bool v6; // zf
  idTypesafeNumber<int,enum gameTimeUnique_t> v7; // [sp+50h] [-10h] BYREF

  if ( ai->aiVolatile.faceMgr.voiceOver != nullptr )
    return 0;
  v7.value = 480;
  v6 = !idFaceMgr::RecentlyPlayedVoiceOver(this: &ai->aiVolatile.faceMgr, threshold: &v7);
  result = TRANSCODE_PCI_VO_FINISHED;
  if ( !v6 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_WaitOnTransition@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE6AA0
// RVA : 0x00AE6AA0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitOnTransition::AIState_EnterState(
        idPlayerInteract_WaitOnTransition *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.focus.enableBodyRotation = false;
  ai->aiVolatile.memory.interactionIsUsable = false;
  idAI2::SetEnableAutoFocus(this: ai, enable: false);
}


// ========================================================================
// ?Evaluate@PCI_ShouldCompleteEmptyJob@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE6AC8
// RVA : 0x00AE6AC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_ShouldCompleteEmptyJob::Evaluate(
        PCI_ShouldCompleteEmptyJob *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclJob *interactionJob; // r11

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr || !interactionJob->giveAndCompleteOnApproach )
    return 0;
  if ( ai->aiVolatile.memory.completeJobDecl == nullptr )
  {
    idLib::Warning(fmt: "in PCI_ShouldCompleteEmptyJob it looks like we should be completing a job, but one not set");
    return 0;
  }
  return 148;
}


// ========================================================================
// ?AIState_ExitState@idPlayerInteract_WaitForInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE6B58
// RVA : 0x00AE6B58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idPlayerInteract_WaitForInteraction::AIState_ExitState(idAI2 *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_BYTE *)(result + 58868) = 0;
  return result;
}


// ========================================================================
// ?AIState_ExitState@idPlayerInteract_PlayerLeft@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE6B70
// RVA : 0x00AE6B70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerLeft::AIState_ExitState(
        idPlayerInteract_PlayerLeft *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  ai->aiVolatile.memory.interactionIsUsable = false;
  idAI2::ClearLookFocus(this: ai);
  idAI2::SetEnableAutoFocus(this: ai, enable: true);
  ai->aiVolatile.focus.enableBodyRotation = true;
}


// ========================================================================
// ?Evaluate@PCI_HasMoreInteractions@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE6BC8
// RVA : 0x00AE6BC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

unsigned int __fastcall PCI_HasMoreInteractions::Evaluate(
        PCI_HasMoreInteractions *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return (((unsigned int)ai->aiVolatile.memory.currentPlayerInteraction >> 31) - 1) & 0x9D;
}


// ========================================================================
// ?Evaluate@PCI_WaitFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE6BE8
// RVA : 0x00AE6BE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_WaitFinished::Evaluate(
        PCI_WaitFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return __CFADD__(curTime - ai->aiVolatile.memory.waitExpireTime, ai->aiVolatile.memory.waitExpireTime ^ 0x80000000)
       ? 0
       : 0x9C;
}


// ========================================================================
// ?AIState_ExitState@idPlayerInteract_WaitBriefly@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE6C10
// RVA : 0x00AE6C10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitBriefly::AIState_ExitState(
        idPlayerInteract_WaitBriefly *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  if ( ai->aiVolatile.memory.currentPlayerInteraction < 0 && ai->aiEditable.interactions.idleTrackFriendlyDist < 0.0 )
  {
    ai->aiVolatile.memory.interactionIsUsable = false;
    idAI2::ClearLookFocus(this: ai);
    idAI2::SetEnableAutoFocus(this: ai, enable: true);
    ai->aiVolatile.focus.enableBodyRotation = true;
  }
}


// ========================================================================
// ??0idPlayerInteractFSM@@QAA@XZ
// EA  : 0x82AE6CA8
// RVA : 0x00AE6CA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idPlayerInteractFSM *__fastcall idPlayerInteractFSM::idPlayerInteractFSM(idPlayerInteractFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_playerInteract");
  this->__vftable = (idPlayerInteractFSM_vtbl *)&idPlayerInteractFSM::`vftable';
  idState::idState(
    this: &this->stateDefault,
    stateType: &idPlayerInteract_Default::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateDefault.__vftable = (idPlayerInteract_Default_vtbl *)&idPlayerInteract_Default::`vftable';
  idState::idState(
    this: &this->stateWaitOnTransition,
    stateType: &idPlayerInteract_WaitOnTransition::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateWaitOnTransition.__vftable = (idPlayerInteract_WaitOnTransition_vtbl *)&idPlayerInteract_WaitOnTransition::`vftable';
  idState::idState(
    this: &this->stateStartInteraction,
    stateType: &idPlayerInteract_StartInteraction::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateStartInteraction.__vftable = (idPlayerInteract_StartInteraction_vtbl *)&idPlayerInteract_StartInteraction::`vftable';
  idState::idState(
    this: &this->stateMoveToInteractionPoint,
    stateType: &idPlayerInteract_MoveToInteractionPoint::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateMoveToInteractionPoint.__vftable = (idPlayerInteract_MoveToInteractionPoint_vtbl *)&idPlayerInteract_MoveToInteractionPoint::`vftable';
  idState::idState(
    this: &this->stateReachedInteractionPoint,
    stateType: &idPlayerInteract_ReachedInteractionPoint::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateReachedInteractionPoint.__vftable = (idPlayerInteract_ReachedInteractionPoint_vtbl *)&idPlayerInteract_ReachedInteractionPoint::`vftable';
  idState::idState(
    this: &this->stateWaitForInteraction,
    stateType: &idPlayerInteract_WaitForInteraction::Type,
    childFSMType: nullptr,
    flags: 2);
  this->stateWaitForInteraction.__vftable = (idPlayerInteract_WaitForInteraction_vtbl *)&idPlayerInteract_WaitForInteraction::`vftable';
  idState::idState(
    this: &this->stateProcessInteraction,
    stateType: &idPlayerInteract_ProcessInteraction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateProcessInteraction.__vftable = (idPlayerInteract_ProcessInteraction_vtbl *)&idPlayerInteract_ProcessInteraction::`vftable';
  idState::idState(
    this: &this->stateProcessEmptyInteraction,
    stateType: &idPlayerInteract_ProcessEmptyInteraction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateProcessEmptyInteraction.__vftable = (idPlayerInteract_ProcessEmptyInteraction_vtbl *)&idPlayerInteract_ProcessEmptyInteraction::`vftable';
  idState::idState(
    this: &this->stateDeliverJobOfferVO,
    stateType: &idPlayerInteract_DeliverJobOfferVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverJobOfferVO.__vftable = (idPlayerInteract_DeliverJobOfferVO_vtbl *)&idPlayerInteract_DeliverJobOfferVO::`vftable';
  idState::idState(
    this: &this->stateDeliverJobEndVO,
    stateType: &idPlayerInteract_DeliverJobEndVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverJobEndVO.__vftable = (idPlayerInteract_DeliverJobEndVO_vtbl *)&idPlayerInteract_DeliverJobEndVO::`vftable';
  idState::idState(
    this: &this->stateDeliverJobCompleteVO,
    stateType: &idPlayerInteract_DeliverJobCompleteVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverJobCompleteVO.__vftable = (idPlayerInteract_DeliverJobCompleteVO_vtbl *)&idPlayerInteract_DeliverJobCompleteVO::`vftable';
  idState::idState(
    this: &this->stateDeliverJobFailedVO,
    stateType: &idPlayerInteract_DeliverJobFailedVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverJobFailedVO.__vftable = (idPlayerInteract_DeliverJobFailedVO_vtbl *)&idPlayerInteract_DeliverJobFailedVO::`vftable';
  idState::idState(
    this: &this->stateDeliverJobInProgressVO,
    stateType: &idPlayerInteract_DeliverJobInProgressVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverJobInProgressVO.__vftable = (idPlayerInteract_DeliverJobInProgressVO_vtbl *)&idPlayerInteract_DeliverJobInProgressVO::`vftable';
  idState::idState(
    this: &this->stateDeliverNonJobGUIVO,
    stateType: &idPlayerInteract_DeliverNonJobGUIVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverNonJobGUIVO.__vftable = (idPlayerInteract_DeliverNonJobGUIVO_vtbl *)&idPlayerInteract_DeliverNonJobGUIVO::`vftable';
  idState::idState(
    this: &this->stateDeliverNonJobVO,
    stateType: &idPlayerInteract_DeliverNonJobVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateDeliverNonJobVO.__vftable = (idPlayerInteract_DeliverNonJobVO_vtbl *)&idPlayerInteract_DeliverNonJobVO::`vftable';
  idState::idState(
    this: &this->stateTriggerPostMessageEnt,
    stateType: &idPlayerInteract_TriggerPostMessageEnt::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateTriggerPostMessageEnt.__vftable = (idPlayerInteract_TriggerPostMessageEnt_vtbl *)&idPlayerInteract_TriggerPostMessageEnt::`vftable';
  idState::idState(
    this: &this->stateNonJobDeliverJobCompleteVO,
    stateType: &idPlayerInteract_NonJobDeliverJobCompleteVO::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateNonJobDeliverJobCompleteVO.__vftable = (idPlayerInteract_NonJobDeliverJobCompleteVO_vtbl *)&idPlayerInteract_NonJobDeliverJobCompleteVO::`vftable';
  idState::idState(
    this: &this->stateWaitForJobChoice,
    stateType: &idPlayerInteract_WaitForJobChoice::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateWaitForJobChoice.__vftable = (idPlayerInteract_WaitForJobChoice_vtbl *)&idPlayerInteract_WaitForJobChoice::`vftable';
  idState::idState(
    this: &this->statePlayerAcceptedJob,
    stateType: &idPlayerInteract_PlayerAcceptedJob::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayerAcceptedJob.__vftable = (idPlayerInteract_PlayerAcceptedJob_vtbl *)&idPlayerInteract_PlayerAcceptedJob::`vftable';
  idState::idState(
    this: &this->statePlayerDeclinedJob,
    stateType: &idPlayerInteract_PlayerDeclinedJob::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayerDeclinedJob.__vftable = (idPlayerInteract_PlayerDeclinedJob_vtbl *)&idPlayerInteract_PlayerDeclinedJob::`vftable';
  idState::idState(
    this: &this->stateSayGoodbye,
    stateType: &idPlayerInteract_SayGoodbye::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSayGoodbye.__vftable = (idPlayerInteract_SayGoodbye_vtbl *)&idPlayerInteract_SayGoodbye::`vftable';
  idState::idState(
    this: &this->stateWaitBriefly,
    stateType: &idPlayerInteract_WaitBriefly::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateWaitBriefly.__vftable = (idPlayerInteract_WaitBriefly_vtbl *)&idPlayerInteract_WaitBriefly::`vftable';
  idState::idState(
    this: &this->statePlayerLeft,
    stateType: &idPlayerInteract_PlayerLeft::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayerLeft.__vftable = (idPlayerInteract_PlayerLeft_vtbl *)&idPlayerInteract_PlayerLeft::`vftable';
  idState::idState(
    this: &this->stateMerchantInteract,
    stateType: &idPlayerInteract_MerchantInteract::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMerchantInteract.__vftable = (idPlayerInteract_MerchantInteract_vtbl *)&idPlayerInteract_MerchantInteract::`vftable';
  idState::idState(
    this: &this->stateMerchantInteractLoop,
    stateType: &idPlayerInteract_MerchantInteractLoop::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMerchantInteractLoop.__vftable = (idPlayerInteract_MerchantInteractLoop_vtbl *)&idPlayerInteract_MerchantInteractLoop::`vftable';
  idState::idState(
    this: &this->statePlayerPurchasedItem,
    stateType: &idPlayerInteract_PlayerPurchasedItem::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayerPurchasedItem.__vftable = (idPlayerInteract_PlayerPurchasedItem_vtbl *)&idPlayerInteract_PlayerPurchasedItem::`vftable';
  idState::idState(
    this: &this->statePlayerClosedMerchantMenu,
    stateType: &idPlayerInteract_PlayerClosedMerchantMenu::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePlayerClosedMerchantMenu.__vftable = (idPlayerInteract_PlayerClosedMerchantMenu_vtbl *)&idPlayerInteract_PlayerClosedMerchantMenu::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$490379
// EA  : 0x82AE70C4
// RVA : 0x00AE70C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490379()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490380
// EA  : 0x82AE70EC
// RVA : 0x00AE70EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490380()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$490381
// EA  : 0x82AE7118
// RVA : 0x00AE7118
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490381()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$490382
// EA  : 0x82AE7144
// RVA : 0x00AE7144
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490382()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$490383_0
// EA  : 0x82AE7170
// RVA : 0x00AE7170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490383_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$490384
// EA  : 0x82AE719C
// RVA : 0x00AE719C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490384()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$490385
// EA  : 0x82AE71C8
// RVA : 0x00AE71C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490385()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$490386
// EA  : 0x82AE71F4
// RVA : 0x00AE71F4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490386()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// __unwind$490387
// EA  : 0x82AE7220
// RVA : 0x00AE7220
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490387()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 304));
}


// ========================================================================
// __unwind$490388
// EA  : 0x82AE724C
// RVA : 0x00AE724C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490388()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 332));
}


// ========================================================================
// __unwind$490389
// EA  : 0x82AE7278
// RVA : 0x00AE7278
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490389()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 360));
}


// ========================================================================
// __unwind$490390
// EA  : 0x82AE72A4
// RVA : 0x00AE72A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490390()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 388));
}


// ========================================================================
// __unwind$490391
// EA  : 0x82AE72D0
// RVA : 0x00AE72D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490391()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 416));
}


// ========================================================================
// __unwind$490392
// EA  : 0x82AE72FC
// RVA : 0x00AE72FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490392()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 444));
}


// ========================================================================
// __unwind$490393
// EA  : 0x82AE7328
// RVA : 0x00AE7328
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490393()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 472));
}


// ========================================================================
// __unwind$490394
// EA  : 0x82AE7354
// RVA : 0x00AE7354
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490394()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 500));
}


// ========================================================================
// __unwind$490395
// EA  : 0x82AE7380
// RVA : 0x00AE7380
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490395()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 528));
}


// ========================================================================
// __unwind$490396_0
// EA  : 0x82AE73AC
// RVA : 0x00AE73AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490396_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 556));
}


// ========================================================================
// __unwind$490397
// EA  : 0x82AE73D8
// RVA : 0x00AE73D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490397()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 584));
}


// ========================================================================
// __unwind$490398
// EA  : 0x82AE7404
// RVA : 0x00AE7404
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490398()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 612));
}


// ========================================================================
// __unwind$490399
// EA  : 0x82AE7430
// RVA : 0x00AE7430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490399()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 640));
}


// ========================================================================
// __unwind$490400
// EA  : 0x82AE745C
// RVA : 0x00AE745C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490400()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 668));
}


// ========================================================================
// __unwind$490401
// EA  : 0x82AE7488
// RVA : 0x00AE7488
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490401()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 696));
}


// ========================================================================
// __unwind$490402
// EA  : 0x82AE74B4
// RVA : 0x00AE74B4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490402()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 724));
}


// ========================================================================
// __unwind$490403
// EA  : 0x82AE74E0
// RVA : 0x00AE74E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490403()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 752));
}


// ========================================================================
// __unwind$490404
// EA  : 0x82AE750C
// RVA : 0x00AE750C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490404()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 780));
}


// ========================================================================
// __unwind$490405
// EA  : 0x82AE7538
// RVA : 0x00AE7538
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490405()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 808));
}


// ========================================================================
// __unwind$490406
// EA  : 0x82AE7564
// RVA : 0x00AE7564
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490406()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 836));
}


// ========================================================================
// ??1idPlayerInteractFSM@@UAA@XZ
// EA  : 0x82AE7598
// RVA : 0x00AE7598
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteractFSM::~idPlayerInteractFSM(idPlayerInteractFSM *this)
{
  this->__vftable = (idPlayerInteractFSM_vtbl *)&idPlayerInteractFSM::`vftable';
  idState::~idState(this: &this->statePlayerClosedMerchantMenu);
  idState::~idState(this: &this->statePlayerPurchasedItem);
  idState::~idState(this: &this->stateMerchantInteractLoop);
  idState::~idState(this: &this->stateMerchantInteract);
  idState::~idState(this: &this->statePlayerLeft);
  idState::~idState(this: &this->stateWaitBriefly);
  idState::~idState(this: &this->stateSayGoodbye);
  idState::~idState(this: &this->statePlayerDeclinedJob);
  idState::~idState(this: &this->statePlayerAcceptedJob);
  idState::~idState(this: &this->stateWaitForJobChoice);
  idState::~idState(this: &this->stateNonJobDeliverJobCompleteVO);
  idState::~idState(this: &this->stateTriggerPostMessageEnt);
  idState::~idState(this: &this->stateDeliverNonJobVO);
  idState::~idState(this: &this->stateDeliverNonJobGUIVO);
  idState::~idState(this: &this->stateDeliverJobInProgressVO);
  idState::~idState(this: &this->stateDeliverJobFailedVO);
  idState::~idState(this: &this->stateDeliverJobCompleteVO);
  idState::~idState(this: &this->stateDeliverJobEndVO);
  idState::~idState(this: &this->stateDeliverJobOfferVO);
  idState::~idState(this: &this->stateProcessEmptyInteraction);
  idState::~idState(this: &this->stateProcessInteraction);
  idState::~idState(this: &this->stateWaitForInteraction);
  idState::~idState(this: &this->stateReachedInteractionPoint);
  idState::~idState(this: &this->stateMoveToInteractionPoint);
  idState::~idState(this: &this->stateStartInteraction);
  idState::~idState(this: &this->stateWaitOnTransition);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$490860
// EA  : 0x82AE76BC
// RVA : 0x00AE76BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490860()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490861
// EA  : 0x82AE76E4
// RVA : 0x00AE76E4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490861()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$490862
// EA  : 0x82AE7710
// RVA : 0x00AE7710
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490862()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$490863
// EA  : 0x82AE773C
// RVA : 0x00AE773C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490863()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$490864
// EA  : 0x82AE7768
// RVA : 0x00AE7768
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490864()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$490865
// EA  : 0x82AE7794
// RVA : 0x00AE7794
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490865()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$490866
// EA  : 0x82AE77C0
// RVA : 0x00AE77C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490866()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$490867
// EA  : 0x82AE77EC
// RVA : 0x00AE77EC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490867()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$490868
// EA  : 0x82AE7818
// RVA : 0x00AE7818
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490868()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$490869
// EA  : 0x82AE7844
// RVA : 0x00AE7844
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490869()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$490870
// EA  : 0x82AE7870
// RVA : 0x00AE7870
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490870()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// __unwind$490871
// EA  : 0x82AE789C
// RVA : 0x00AE789C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490871()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 388));
}


// ========================================================================
// __unwind$490872
// EA  : 0x82AE78C8
// RVA : 0x00AE78C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490872()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 416));
}


// ========================================================================
// __unwind$490873
// EA  : 0x82AE78F4
// RVA : 0x00AE78F4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490873()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 444));
}


// ========================================================================
// __unwind$490874
// EA  : 0x82AE7920
// RVA : 0x00AE7920
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490874()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 472));
}


// ========================================================================
// __unwind$490875
// EA  : 0x82AE794C
// RVA : 0x00AE794C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490875()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 500));
}


// ========================================================================
// __unwind$490876
// EA  : 0x82AE7978
// RVA : 0x00AE7978
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490876()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 528));
}


// ========================================================================
// __unwind$490877
// EA  : 0x82AE79A4
// RVA : 0x00AE79A4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490877()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 556));
}


// ========================================================================
// __unwind$490878
// EA  : 0x82AE79D0
// RVA : 0x00AE79D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490878()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 584));
}


// ========================================================================
// __unwind$490879
// EA  : 0x82AE79FC
// RVA : 0x00AE79FC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490879()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 612));
}


// ========================================================================
// __unwind$490880
// EA  : 0x82AE7A28
// RVA : 0x00AE7A28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490880()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 640));
}


// ========================================================================
// __unwind$490881
// EA  : 0x82AE7A54
// RVA : 0x00AE7A54
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490881()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 668));
}


// ========================================================================
// __unwind$490882
// EA  : 0x82AE7A80
// RVA : 0x00AE7A80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490882()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 696));
}


// ========================================================================
// __unwind$490883
// EA  : 0x82AE7AAC
// RVA : 0x00AE7AAC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490883()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 724));
}


// ========================================================================
// __unwind$490884
// EA  : 0x82AE7AD8
// RVA : 0x00AE7AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490884()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 752));
}


// ========================================================================
// __unwind$490885
// EA  : 0x82AE7B04
// RVA : 0x00AE7B04
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490885()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 780));
}


// ========================================================================
// __unwind$490886
// EA  : 0x82AE7B30
// RVA : 0x00AE7B30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_490886()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 808));
}


// ========================================================================
// ?Evaluate@PCI_IsAnimWebTransitioning@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE7B60
// RVA : 0x00AE7B60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_IsAnimWebTransitioning::Evaluate(
        PCI_IsAnimWebTransitioning *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r31
  char v6; // r11

  p_animation = &ai->aiVolatile.animation;
  if ( !idAI2::GetCurrentPlayerInteraction(this: ai)->waitTillInteractIdle )
    return 0;
  if ( (unsigned __int16)p_animation->animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v6 = 1, (unsigned __int16)p_animation->animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
    return 159;
  if ( p_animation->animWebAnimator.ptr[0].destStateIndices.numStates != 0
    || !p_animation->animWebAnimator.ptr[0].skipForcedEdgeAutoPath
    && (unsigned __int16)p_animation->animWebAnimator.ptr[0].forcedEdge.destNodeIndex.value < 0x8000u )
  {
    return 159;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?Evaluate@PCI_TransitionFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE7C28
// RVA : 0x00AE7C28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_TransitionFinished::Evaluate(
        PCI_TransitionFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v6; // r11

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v6 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v6 = 0;
  }
  if ( v6 == 0 )
  {
    if ( idAI2::GetBodyOrientation(this: ai)->currentTurnDir == 0 )
      return 161;
    if ( !ai->aiVolatile.focus.enableBodyRotation )
    {
      idLib::Warning(fmt: "AI '%s' tried to wait on transition when body rotation was disabled.", ai->name.data);
      return 161;
    }
  }
  return 0;
}


// ========================================================================
// ?FindBestIneractionPoint@@YAPBVidInfoPath@@PAVidAI2@@PAVidPlayer@@@Z
// EA  : 0x82AE7D30
// RVA : 0x00AE7D30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

const idInfoPath *__fastcall FindBestIneractionPoint(idAI2 *ai, idPlayer *player)
{
  idPhysics *Physics; // r3
  float *v4; // r25
  idPhysics *v5; // r3
  float *v6; // r24
  int v7; // r26
  int v8; // r29
  double v9; // fp31
  int v10; // r28
  int value; // r9
  idEntity *v12; // r3
  idInfoPath *v13; // r3
  idInfoPath *v14; // r3
  idEntity *v15; // r31
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp29
  double v19; // fp28
  idPhysics *v20; // r3
  float *v21; // r3
  double v22; // fp4
  double v23; // fp1
  double v24; // fp13
  int num; // r11
  int v26; // r9
  idEntity *v27; // r3
  idInfoPath *v28; // r3

  Physics = idEntity::GetPhysics(this: player);
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v5 = idEntity::GetPhysics(this: ai);
  v6 = (float *)v5->GetOrigin(this: v5, a2: 0);
  v7 = -1;
  v8 = 0;
  v9 = 3.4028235e38;
  if ( ai->targets.num <= 0 )
    return nullptr;
  v10 = 0;
  do
  {
    value = ai->targets.list[v10].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v12 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v13 = (idInfoPath *)idEntity::CastTo(c: v12);
    }
    else
    {
      v13 = nullptr;
    }
    v14 = idInfoPath::CastTo(c: v13);
    v15 = v14;
    if ( v14 != nullptr )
    {
      v16 = idEntity::GetPhysics(this: v14);
      v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
      v18 = (float)(*v4 - *v17);
      v19 = (float)(v4[1] - v17[1]);
      v20 = idEntity::GetPhysics(this: v15);
      v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
      v22 = (float)(v6[1] - v21[1]);
      v23 = __fsqrts((float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
      v24 = __fsqrts((float)((float)((float)v22 * (float)v22) + (float)((float)(*v6 - *v21) * (float)(*v6 - *v21))));
      if ( (float)((float)((float)v23 * (float)3.0) + (float)v24) < v9 )
      {
        v7 = v8;
        v9 = (float)((float)((float)v23 * (float)3.0) + (float)v24);
      }
    }
    num = ai->targets.num;
    ++v8;
    ++v10;
  }
  while ( v8 < num );
  if ( v7 < 0 )
    return nullptr;
  if ( v7 >= num )
    return idInfoPath::CastTo(c: nullptr);
  v26 = ai->targets.list[v7].spawnId.value;
  if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] != v26 >> 13 )
    return idInfoPath::CastTo(c: nullptr);
  v27 = gameLocal->entities.ptr[ai->targets.list[v7].spawnId.value & 0x1FFF];
  if ( v27 == nullptr )
    return idInfoPath::CastTo(c: nullptr);
  v28 = (idInfoPath *)idEntity::CastTo(c: v27);
  return idInfoPath::CastTo(c: v28);
}


// ========================================================================
// ?Evaluate@PCI_VOFinished_Or_PlayerSelected@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE7F50
// RVA : 0x00AE7F50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_VOFinished_Or_PlayerSelected::Evaluate(
        PCI_VOFinished_Or_PlayerSelected *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  idPlayer::offerChoice_t lastOfferChoice; // r11

  if ( ai->aiVolatile.faceMgr.voiceOver == nullptr )
    return TRANSCODE_PCI_VO_FINISHED;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idPlayer::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  lastOfferChoice = v8->lastOfferChoice;
  result = TRANSCODE_PCI_VO_FINISHED;
  if ( lastOfferChoice == OFFERCHOICE_UNKNOWN )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_PlayerReturned@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE7FF8
// RVA : 0x00AE7FF8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_PlayerReturned::Evaluate(
        PCI_PlayerReturned *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  char v6; // r11
  idAIEventSphere *eventData; // r31
  idPlayer *Originator; // r3
  idPlayer *v9; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v11; // zf

  if ( (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v6 = 1, (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( parentFSM->eventId != 0x200000 )
    return 0;
  eventData = (idAIEventSphere *)parentFSM->eventData;
  if ( idAIEventSphere::CastTo(c: eventData) == nullptr )
    return 0;
  Originator = (idPlayer *)idAIEvent::GetOriginator(this: eventData);
  v9 = idPlayer::CastTo(c: Originator);
  v11 = (unsigned __int8)idAI2::PlayerApproachingInteraction(this: ai, player: v9) != 0;
  result = TRANSCODE_PCI_VO_FINISHED;
  if ( !v11 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_PlayerLeft@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE80B0
// RVA : 0x00AE80B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_PlayerLeft::Evaluate(
        PCI_PlayerLeft *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  idPhysics *Physics; // r29
  idPhysics *v12; // r31
  float *v13; // r29
  float *v14; // r3
  double v15; // fp8
  double v16; // fp6
  double v17; // fp1

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( CurrentPlayerInteraction == nullptr )
    goto LABEL_10;
  if ( !CurrentPlayerInteraction->forceDoNotStopOnPlayerDepature )
  {
    if ( CurrentPlayerInteraction->countPlayerControlledAsDeparture && idPlayer::GetControl(this: v8) != nullptr )
      return TRANSCODE_PCI_PLAYER_LEFT;
LABEL_10:
    Physics = idEntity::GetPhysics(this: ai);
    v12 = idEntity::GetPhysics(this: v8);
    v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = (float *)v12->GetOrigin(this: v12, a2: 0);
    v15 = (float)(v14[2] - v13[2]);
    v16 = (float)(v14[1] - v13[1]);
    v17 = (float)((float)((float)v16 * (float)v16)
                + (float)((float)((float)v15 * (float)v15) + (float)((float)(*v14 - *v13) * (float)(*v14 - *v13))));
    result = TRANSCODE_PCI_PLAYER_LEFT;
    if ( v17 >= (float)(ai->aiVolatile.aiPlayerInteraction.decl->departureRadius
                      * ai->aiVolatile.aiPlayerInteraction.decl->departureRadius) )
      return result;
  }
  return 0;
}


// ========================================================================
// ?Evaluate@PCI_ReachedInteractionPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8200
// RVA : 0x00AE8200
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_ReachedInteractionPoint::Evaluate(
        PCI_ReachedInteractionPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idInfoPath *v7; // r3

  value = ai->aiVolatile.memory.interactionPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idInfoPath::CastTo(c: v7) != nullptr )
  {
    return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x90;
  }
  else
  {
    return 144;
  }
}


// ========================================================================
// ?Evaluate@PCI_AtInteractionPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE82B0
// RVA : 0x00AE82B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_AtInteractionPoint::Evaluate(
        PCI_AtInteractionPoint *this,
        _exception *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int v6; // r8
  idInfoPath *v7; // r3
  idInfoPath *v8; // r3
  idPhysics *Physics; // r3
  int v10; // r30
  double v11; // fp31
  idAIMoveState *MoveInterface; // r3

  v6 = DWORD1(ai[919].arg2);
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] != v6 >> 13 )
    return 158;
  v7 = (idInfoPath *)gameLocal->entities.ptr[v6 & 0x1FFF];
  if ( v7 == nullptr )
    return 158;
  v8 = idInfoPath::CastTo(c: v7);
  if ( v8 == nullptr )
    return 158;
  Physics = idEntity::GetPhysics(this: v8);
  v10 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: ai) != 0 )
    v11 = *((float *)&ai[557].arg2 + 3);
  else
    v11 = *((float *)&ai[191].arg2 + 1);
  MoveInterface = idAI2::GetMoveInterface(this: (idAI2 *)ai);
  return !MoveInterface->ReachedPoint(this: MoveInterface, a2: (const idVec3 *)v10, a3: v11) ? 0 : 0x9E;
}


// ========================================================================
// ?Evaluate@PCI_ShouldProcessInteraction@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE83B8
// RVA : 0x00AE83B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldProcessInteraction::Evaluate(
        PCI_ShouldProcessInteraction *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  value = ai->aiVolatile.memory.triggeredInteraction.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return 0;
  v8 = idPlayer::CastTo(c: v6) != nullptr;
  result = TRANSCODE_PCI_DELIVER_JOB_OFFER_VO;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_MoveToInteractionPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8430
// RVA : 0x00AE8430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_MoveToInteractionPoint::Evaluate(
        PCI_MoveToInteractionPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idInfoPath *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  value = ai->aiVolatile.memory.interactionPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v6 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return 0;
  v8 = idInfoPath::CastTo(c: v6) != nullptr;
  result = TRANSCODE_PCI_MOVE_TO_INTERACTION_POINT;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_StartInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE84A8
// RVA : 0x00AE84A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_StartInteraction::AIState_EnterState(
        idPlayerInteract_StartInteraction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r30
  idJobManager *p_jobManager; // r26
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v11; // r28
  const idDeclAIPlayerInteraction *decl; // r25
  int v13; // r24
  idAIOrientation *BodyOrientation; // r3
  float y; // r6
  float z; // r5
  int v17; // r7
  idInfoPath *v18; // r3
  idInfoPath *v19; // r29
  double v20; // fp31
  idPhysics *Physics; // r30
  idAIMoveState *MoveInterface; // r23
  idPhysics *v23; // r3
  idAIMoveState_vtbl *v24; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v26; // r3
  long double v27; // fp2
  double alignmentTolerance; // fp31
  idAIOrientation *v29; // r3
  __int64 v30; // r10
  __int64 v31; // r8
  __int64 v32; // r6
  bool v33; // r30
  const idDeclJob *interactionJob; // r4
  idJob *JobByDecl; // r3
  __int64 v36; // r4
  const idDeclVoiceOver *approachVO; // r5
  __int64 v38; // r4
  __int64 v39; // r4
  const idDeclJob *v40; // r4
  char *data; // r30
  idStrId *JobName; // r3
  __int64 v43; // r6
  __int64 v44; // r10
  __int64 v45; // r8
  const idDeclVoiceOver *secondaryApproachVO; // r5
  __int64 v47; // r4
  __int64 v48; // r4
  int v49; // [sp+8h] [-B8h]
  int v50; // [sp+8h] [-B8h]
  int v51; // [sp+Ch] [-B4h]
  int v52; // [sp+Ch] [-B4h]
  int v53; // [sp+10h] [-B0h]
  int v54; // [sp+10h] [-B0h]
  int v55; // [sp+14h] [-ACh]
  int v56; // [sp+14h] [-ACh]
  char v57; // [sp+50h] [-70h] BYREF
  float x; // [sp+58h] [-68h]
  float v59; // [sp+5Ch] [-64h]
  float v60; // [sp+60h] [-60h]

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  p_jobManager = &v8->jobManager;
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  v11 = CurrentPlayerInteraction;
  decl = ai->aiVolatile.aiPlayerInteraction.decl;
  v13 = ai->aiVolatile.memory.currentPlayerInteraction;
  if ( CurrentPlayerInteraction != nullptr )
  {
    if ( CurrentPlayerInteraction->actionNodeGroupName.len != 0 )
      idAI2::SetActionNodeGroupName(this: ai, groupName: CurrentPlayerInteraction->actionNodeGroupName.data);
    idAI2::SetEnableHeadTracking(this: ai, enable: v11->allowHeadTracking);
    if ( v11->allowAutoFocus )
    {
      idAI2::SetEnableAutoFocus(this: ai, enable: true);
    }
    else
    {
      idAI2::SetEnableAutoFocus(this: ai, enable: false);
      idAI2::SetLookFocusEntity(this: ai, ent: v8, keepFocusInView: true, aimPoint: AIMPOINT_HEAD, timeout: -1);
    }
    BodyOrientation = idAI2::GetBodyOrientation(this: ai);
    y = BodyOrientation->axis.mat[0].y;
    z = BodyOrientation->axis.mat[0].z;
    x = BodyOrientation->axis.mat[0].x;
    v17 = ai->aiVolatile.memory.interactionPoint.spawnId.value;
    v59 = y;
    v60 = z;
    if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13 )
    {
      v18 = (idInfoPath *)gameLocal->entities.ptr[v17 & 0x1FFF];
      if ( v18 != nullptr )
      {
        v19 = idInfoPath::CastTo(c: v18);
        if ( v19 != nullptr )
        {
          v20 = (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0
              ? ai->aiVolatile.animation.animFSM.currentMove.arrivalRadius
              : ai->aiVolatile.physics.moveState.moveParms.goalTolerance;
          Physics = idEntity::GetPhysics(this: v19);
          MoveInterface = idAI2::GetMoveInterface(this: ai);
          v23 = Physics;
          GetOrigin = Physics->GetOrigin;
          v24 = MoveInterface->__vftable;
          v26 = (int)GetOrigin(this: v23, a2: 0);
          if ( v24->ReachedPoint(this: MoveInterface, a2: (const idVec3 *)v26, a3: v20) )
          {
            alignmentTolerance = v19->alignmentTolerance;
            *(double *)&v27 = (float)((float)(v19->spawnOrientation.mat[0].x * x)
                                    + (float)((float)(v19->spawnOrientation.mat[0].y * v59)
                                            + (float)(v19->spawnOrientation.mat[0].z * v60)));
            if ( idMath::ACos(a: v27) >= (double)(float)((float)alignmentTolerance * idMath::M_DEG2RAD) )
            {
              v29 = idAI2::GetBodyOrientation(this: ai);
              idAIOrientation::SetIdealDir(this: v29, ai, dir: v19->spawnOrientation.mat);
            }
          }
        }
      }
    }
    if ( idAI2::GetCurrentPlayerInteractionTempInfoState(this: ai) == PISTATE_INACTIVE )
    {
      LODWORD(v30) = _cntlzw(
                       idJobManager::GetInteractionApproachPlayed(
                         this: p_jobManager,
                         interactionDecl: decl,
                         interactionNumber: v13));
      v33 = (v30 & 0x20) != 0;
      if ( (v30 & 0x20) != 0 )
      {
        interactionJob = v11->interactionJob;
        if ( interactionJob != nullptr )
        {
          JobByDecl = idJobManager::FindJobByDecl(this: p_jobManager, jobDecl: interactionJob);
          if ( JobByDecl != nullptr && JobByDecl->status != JOBSTATUS_NONE )
          {
            LODWORD(v36) = ai->name.data;
            v33 = false;
            HIDWORD(v36) = "'%s': not playing main approach vo since job is known.\n";
            idAI2::Job_DebugPrintf(fmt: v36, a2: v32, a3: v31, a4: v30, a5: v49, a6: v51, a7: v53, a8: v55);
          }
        }
      }
      if ( v33 )
      {
        approachVO = v11->approachVO;
        if ( approachVO != nullptr )
        {
          if ( v11->lowerWorldSoundVolumeForApproachVO || ai_interactionFadeForApproachVOFlag.valueInteger != 0 )
            idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai, vo: approachVO, priority: AIVOICEPRIORITY_MED);
          LODWORD(v30) = "ound traces";
          LODWORD(v38) = ai->name.data;
          HIDWORD(v38) = "'%s': playing approach VO: %s.\n";
          HIDWORD(v32) = v11->approachVO->name.str;
          idAI2::Job_DebugPrintf(fmt: v38, a2: v32, a3: v31, a4: v30, a5: v49, a6: v51, a7: v53, a8: v55);
        }
        else
        {
          LODWORD(v39) = ai->name.data;
          HIDWORD(v39) = "'%s': no approach VO.\n";
          idAI2::Job_DebugPrintf(fmt: v39, a2: (unsigned int)v32, a3: v31, a4: v30, a5: v49, a6: v51, a7: v53, a8: v55);
        }
        v40 = v11->interactionJob;
        if ( v40 != nullptr && v40->giveAndCompleteOnApproach )
        {
          data = ai->name.data;
          JobName = idDeclJob::GetJobName(this: (idDeclJob *)&v57, result: (idStrId *)v40);
          HIDWORD(v43) = idStrId::GetLocalizedString(this: JobName);
          idAI2::Job_DebugPrintf(
            fmt: __SPAIR64__(
              "'%s': completing Job because of giveAndCompleteOnApproach %s. (well after the vo...)\n",
              (unsigned int)data),
            a2: v43,
            a3: v45,
            a4: v44,
            a5: v50,
            a6: v52,
            a7: v54,
            a8: v56);
          ai->aiVolatile.memory.completeJobDecl = v11->interactionJob;
        }
      }
      else
      {
        secondaryApproachVO = v11->secondaryApproachVO;
        if ( secondaryApproachVO != nullptr )
        {
          if ( v11->lowerWorldSoundVolumeForApproachVO || ai_interactionFadeForApproachVOFlag.valueInteger != 0 )
            idGameLocal::PlayInteractVoiceOver(
              this: gameLocal,
              ai,
              vo: secondaryApproachVO,
              priority: AIVOICEPRIORITY_MED);
          LODWORD(v30) = "ound traces";
          LODWORD(v47) = ai->name.data;
          HIDWORD(v47) = "'%s': playing secondary approach VO: %s.\n";
          HIDWORD(v32) = v11->secondaryApproachVO->name.str;
          idAI2::Job_DebugPrintf(fmt: v47, a2: v32, a3: v31, a4: v30, a5: v49, a6: v51, a7: v53, a8: v55);
        }
        else
        {
          LODWORD(v48) = ai->name.data;
          HIDWORD(v48) = "'%s': no secondary approach VO.\n";
          idAI2::Job_DebugPrintf(fmt: v48, a2: (unsigned int)v32, a3: v31, a4: v30, a5: v49, a6: v51, a7: v53, a8: v55);
        }
      }
      idJobManager::SetInteractionApproachPlayed(
        this: p_jobManager,
        interactionDecl: decl,
        interactionNumber: v13,
        played: true);
      idAI2::SetCurrentPlayerInteractionTempInfoState(this: ai, newState: PISTATE_APPROACH_PLAYED);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobCompleteVO_EARLY@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE88D0
// RVA : 0x00AE88D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldDeliverJobCompleteVO_EARLY::Evaluate(
        PCI_ShouldDeliverJobCompleteVO_EARLY *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v7; // r29
  const idDeclJob *interactionJob; // r11
  idPlayer *InteractionEntity; // r30
  idPhysics *Physics; // r28
  idPhysics *v11; // r27
  float *v12; // r28
  __int128 v13; // r5
  double v14; // fp8
  double v15; // fp3
  idAIStateTransition::aiTransCode_t result; // r3
  bool ShouldDeliverJobCompleteVO; // zf

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  v7 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr )
    return 0;
  if ( !interactionJob->autoCompletes )
    return 0;
  InteractionEntity = idAIMemory::GetInteractionEntity(this: &ai->aiVolatile.memory);
  Physics = idEntity::GetPhysics(this: ai);
  v11 = idEntity::GetPhysics(this: InteractionEntity);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  *(_QWORD *)((char *)&v13 + 4) = ((__int64 (__fastcall *)(idPhysics *, _DWORD))v11->GetOrigin)(a1: v11, a2: 0);
  v14 = (float)(*(float *)(DWORD1(v13) + 8) - v12[2]);
  v15 = (float)(*(float *)(DWORD1(v13) + 4) - v12[1]);
  LODWORD(v13) = v7->interactionJob->autoCompleteDistance;
  if ( (float)((float)((float)v15 * (float)v15)
             + (float)((float)((float)v14 * (float)v14)
                     + (float)((float)(*(float *)DWORD1(v13) - *v12) * (float)(*(float *)DWORD1(v13) - *v12)))) >= (double)(float)((float)(__int64)v13 * (float)(__int64)v13) )
    return 0;
  ShouldDeliverJobCompleteVO = idJobManager::ShouldDeliverJobCompleteVO(this: &InteractionEntity->jobManager, ai);
  result = TRANSCODE_PCI_DELIVER_JOB_COMPLETE_VO;
  if ( !ShouldDeliverJobCompleteVO )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_EmptyInteraction@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE89E8
// RVA : 0x00AE89E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_EmptyInteraction::Evaluate(
        PCI_EmptyInteraction *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r30
  unsigned int TalkState; // r3
  __int64 v11; // r11

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  if ( idAI2::GetCurrentPlayerInteraction(this: ai) != nullptr
    && (!idAI2::GetCurrentPlayerInteraction(this: ai)->messageExpiresInteraction
     || idAI2::GetCurrentPlayerInteraction(this: ai)->messageTriggerEnt.len != 0) )
  {
    return 0;
  }
  TalkState = idAI2::GetTalkState(this: ai, activator: v8);
  LODWORD(v11) = 2;
  HIDWORD(v11) = TalkState >> 31;
  return (((unsigned __int64)TalkState - v11) >> 32) & 0x91;
}


// ========================================================================
// ?UpdateInteractionIsUsableFlag@@YAXPAVidAI2@@@Z
// EA  : 0x82AE8AD8
// RVA : 0x00AE8AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall UpdateInteractionIsUsableFlag(idAI2 *ai)
{
  bool v2; // r27
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v4; // r28
  idAILogic *v5; // r3
  const aiLatchedState_t *State; // r31
  idPlayer *InteractionEntity; // r3
  idEntity *v8; // r29
  float y; // r10
  float z; // r9
  idPhysics *Physics; // r3
  float *v12; // r31
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp7
  double v16; // fp6
  idVec3 v17; // [sp+50h] [-70h] BYREF
  float x; // [sp+60h] [-60h]
  float v19; // [sp+64h] [-5Ch]
  float v20; // [sp+68h] [-58h]
  idAILogic v21[2]; // [sp+70h] [-50h] BYREF

  v2 = true;
  if ( ai != nullptr )
  {
    CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
    v4 = CurrentPlayerInteraction;
    if ( CurrentPlayerInteraction != nullptr
      && CurrentPlayerInteraction->activateWhenVisible
      && CurrentPlayerInteraction->interactionFoV > -1.0 )
    {
      v5 = idAILogic::idAILogic(this: v21, ai);
      State = idAILogic::GetState(this: v5);
      InteractionEntity = idAIMemory::GetInteractionEntity(this: &ai->aiVolatile.memory);
      v8 = InteractionEntity;
      if ( State != nullptr && InteractionEntity != nullptr )
      {
        y = State->physical.viewfwd.y;
        z = State->physical.viewfwd.z;
        x = State->physical.viewfwd.x;
        v19 = y;
        v20 = z;
        Physics = idEntity::GetPhysics(this: ai);
        v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v13 = idEntity::GetPhysics(this: v8);
        v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
        v15 = (float)(v14[1] - v12[1]);
        v16 = (float)(v14[2] - v12[2]);
        v17.x = *v14 - *v12;
        v17.y = v15;
        v17.z = v16;
        if ( idVec3::NormalizeFast(this: &v17) > 0.000099999997 )
          v2 = (float)((float)(v19 * v17.y) + (float)((float)(v17.x * x) + (float)(v20 * v17.z))) >= (double)v4->interactionFoV;
      }
    }
    ai->aiVolatile.memory.interactionIsUsable = v2;
  }
}


// ========================================================================
// ?AIState_Work@idPlayerInteract_WaitForInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE8C40
// RVA : 0x00AE8C40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitForInteraction::AIState_Work(
        idPlayerInteract_WaitForInteraction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  UpdateInteractionIsUsableFlag(ai);
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_ProcessEmptyInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE8C48
// RVA : 0x00AE8C48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ProcessEmptyInteraction::AIState_EnterState(
        idPlayerInteract_ProcessEmptyInteraction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEntityPtr<idPlayer> *p_interactionEntity; // r30
  int value; // r9
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  int currentPlayerInteraction; // r31
  const idDeclAIPlayerInteraction *decl; // r28
  idPlayer *v11; // r3
  idPlayer *v12; // r4

  p_interactionEntity = &ai->aiVolatile.memory.interactionEntity;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  currentPlayerInteraction = ai->aiVolatile.memory.currentPlayerInteraction;
  decl = ai->aiVolatile.aiPlayerInteraction.decl;
  if ( currentPlayerInteraction >= 0 )
  {
    idJobManager::SetJobOfferPlayed(
      this: &v8->jobManager,
      interactionDecl: ai->aiVolatile.aiPlayerInteraction.decl,
      interactionNumber: ai->aiVolatile.memory.currentPlayerInteraction,
      played: true);
    if ( gameLocal->spawnIds.ptr[p_interactionEntity->spawnId.value & 0x1FFF] == p_interactionEntity->spawnId.value >> 13
      && (v11 = (idPlayer *)gameLocal->entities.ptr[p_interactionEntity->spawnId.value & 0x1FFF]) != nullptr )
    {
      v12 = idPlayer::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    if ( (unsigned __int8)idAI2::IsMerchant(this: ai, player: v12) != 0
      || decl != nullptr && !decl->interactList.list[currentPlayerInteraction].messageExpiresInteraction )
    {
      idLib::Warning(
        fmt: "Marking Interaction played because it is empty, but there are issues. %s %d",
        decl->name.str,
        currentPlayerInteraction);
    }
  }
  else
  {
    idLib::Warning(fmt: "curIndex %d in ai_fsm ProcessEmptyInteraction", ai->aiVolatile.memory.currentPlayerInteraction);
  }
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobOfferVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8D90
// RVA : 0x00AE8D90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldDeliverJobOfferVO::Evaluate(
        PCI_ShouldDeliverJobOfferVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r30
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  int PlayerInteractionState; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  PlayerInteractionState = idAI2::Job_GetPlayerInteractionState(this: ai, player: v9);
  if ( CurrentPlayerInteraction->interactionJob == nullptr )
    return 0;
  v12 = PlayerInteractionState == 1;
  result = TRANSCODE_PCI_DELIVER_JOB_OFFER_VO;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobEndVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8E48
// RVA : 0x00AE8E48
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldDeliverJobEndVO::Evaluate(
        PCI_ShouldDeliverJobEndVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r30
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  int PlayerInteractionState; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  PlayerInteractionState = idAI2::Job_GetPlayerInteractionState(this: ai, player: v9);
  if ( CurrentPlayerInteraction->interactionJob == nullptr )
    return 0;
  v12 = PlayerInteractionState == 2;
  result = TRANSCODE_PCI_DELIVER_JOB_END_VO;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobCompleteVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8F00
// RVA : 0x00AE8F00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_ShouldDeliverJobCompleteVO::Evaluate(
        PCI_ShouldDeliverJobCompleteVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  return !idJobManager::ShouldDeliverJobCompleteVO(this: &v8->jobManager, ai) ? 0 : 0x93;
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobFailedVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE8F98
// RVA : 0x00AE8F98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldDeliverJobFailedVO::Evaluate(
        PCI_ShouldDeliverJobFailedVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclJob *interactionJob; // r4
  idJob *JobByDecl; // r3
  missionStatus_t status; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr )
    return 0;
  JobByDecl = idJobManager::FindJobByDecl(this: &v8->jobManager, jobDecl: interactionJob);
  if ( JobByDecl == nullptr )
    return 0;
  status = JobByDecl->status;
  result = TRANSCODE_PCI_DELIVER_JOB_COMPLETE_VO;
  if ( status != JOBSTATUS_FAILED )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_ShouldDeliverJobInProgressVO@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE9060
// RVA : 0x00AE9060
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall PCI_ShouldDeliverJobInProgressVO::Evaluate(
        PCI_ShouldDeliverJobInProgressVO *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclJob *interactionJob; // r4
  idJob *JobByDecl; // r3
  missionStatus_t status; // r11
  idAIStateTransition::aiTransCode_t result; // r3
  char v14; // r11
  bool v15; // zf

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( CurrentPlayerInteraction == nullptr )
    return 0;
  interactionJob = CurrentPlayerInteraction->interactionJob;
  if ( interactionJob == nullptr )
    return 0;
  JobByDecl = idJobManager::FindJobByDecl(this: &v8->jobManager, jobDecl: interactionJob);
  if ( JobByDecl == nullptr )
    return 0;
  status = JobByDecl->status;
  if ( (_cntlzw(status - 2) & 0x20) != 0 )
    return TRANSCODE_PCI_DELIVER_JOB_COMPLETE_VO;
  if ( status == JOBSTATUS_READYTOTURNIN || (v15 = status != JOBSTATUS_ACCEPTED, v14 = 0, !v15) )
    v14 = 1;
  if ( v14 == 0 )
    return 0;
  v15 = !idDeclJob::AIMatchesJobCompleteNPC(this: JobByDecl->decl, inAI2: ai);
  result = TRANSCODE_PCI_DELIVER_JOB_COMPLETE_VO;
  if ( !v15 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@PCI_IsMerchant@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE9178
// RVA : 0x00AE9178
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_IsMerchant::Evaluate(
        PCI_IsMerchant *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r4

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  return (unsigned __int8)idAI2::IsMerchant(this: ai, player: v8) == 0 ? 0 : 0xA2;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverNonJobVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9210
// RVA : 0x00AE9210
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverNonJobVO::AIState_EnterState(
        idPlayerInteract_DeliverNonJobVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_MessageVO(this: ai, playerEnt: v9, playVO: true, checkAIType: false);
  if ( !idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v12[0]) = 105;
    HIBYTE(v13) = 105;
    v12[1] = 0;
    v14 = -1;
    v10 = idEventArg::idEventArg(this: &v15, data: ai);
    memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
    idEventReceiver::ProcessEvent(
      this: v16,
      result: fsm,
      ev: *(const idEventDef **)&v10->type,
      arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v13, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_TriggerPostMessageEnt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9338
// RVA : 0x00AE9338
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_TriggerPostMessageEnt::AIState_EnterState(
        idPlayerInteract_TriggerPostMessageEnt *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v6; // r31
  const idDeclAIPlayerInteraction *decl; // r28
  idEntity *v8; // r30
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idPlayer *InteractionEntity; // r3
  __int64 v13; // r4
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]

  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  v6 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction != nullptr )
  {
    decl = ai->aiVolatile.aiPlayerInteraction.decl;
    if ( CurrentPlayerInteraction->messageTriggerEnt.len != 0 && CurrentPlayerInteraction->messageTriggerPostMessage )
    {
      v8 = gameLocal->FindEntity(this: gameLocal, a2: CurrentPlayerInteraction->messageTriggerEnt.data);
      if ( v8 != nullptr )
      {
        InteractionEntity = idAIMemory::GetInteractionEntity(this: &ai->aiVolatile.memory);
        idEntity::Activate(this: v8, activator: InteractionEntity);
        HIDWORD(v11) = v8->name.data;
        HIDWORD(v13) = "Interaction '%s' triggering entity %s.";
        LODWORD(v13) = decl->name.str;
      }
      else
      {
        HIDWORD(v11) = v6->messageTriggerEnt.data;
        LODWORD(v13) = decl->name.str;
        HIDWORD(v13) = "Interaction '%s' could not find trigger entity %s.";
      }
      idAI2::Job_DebugPrintf(fmt: v13, a2: v11, a3: v10, a4: v9, a5: v14, a6: v15, a7: v16, a8: v17);
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverJobOfferVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE93F8
// RVA : 0x00AE93F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobOfferVO::AIState_EnterState(
        idPlayerInteract_DeliverJobOfferVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r30
  idJob *CompletedJob; // r3
  idEventArg *v11; // r28
  _BYTE v12[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-A0h] BYREF
  int v14; // [sp+B0h] [-80h]
  int v15; // [sp+B4h] [-7Ch]
  idEventArg v16; // [sp+D0h] [-60h] BYREF
  idEventReceiver v17[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  CompletedJob = idJobManager::FindCompletedJob(this: &v9->jobManager, completionNPC: ai);
  if ( CompletedJob != nullptr )
    ai->aiVolatile.memory.completeJobDecl = CompletedJob->decl;
  idAI2::Job_Offer(this: ai, playerEnt: v9, playVO: true);
  if ( !idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v13[0]) = 105;
    HIBYTE(v14) = 105;
    v13[1] = 0;
    v15 = -1;
    v11 = idEventArg::idEventArg(this: &v16, data: ai);
    memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
    idEventReceiver::ProcessEvent(
      this: v17,
      result: fsm,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v14, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverJobEndVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9540
// RVA : 0x00AE9540
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobEndVO::AIState_EnterState(
        idPlayerInteract_DeliverJobEndVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEntityPtr<idPlayer> *p_interactionEntity; // r30
  int value; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r4
  idPlayer *v11; // r3
  idPlayer *v12; // r4
  idEventArg *v13; // r29
  _BYTE v14[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v15[5]; // [sp+90h] [-B0h] BYREF
  int v16; // [sp+B0h] [-90h]
  int v17; // [sp+B4h] [-8Ch]
  idEventArg v18; // [sp+D0h] [-70h] BYREF
  idEventReceiver v19[6]; // [sp+F0h] [-50h] BYREF

  p_interactionEntity = &ai->aiVolatile.memory.interactionEntity;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idPlayer::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  idAI2::Job_CompleteSavedJob(this: ai, player: v10);
  if ( gameLocal->spawnIds.ptr[p_interactionEntity->spawnId.value & 0x1FFF] == p_interactionEntity->spawnId.value >> 13
    && (v11 = (idPlayer *)gameLocal->entities.ptr[p_interactionEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v12 = idPlayer::CastTo(c: v11);
  }
  else
  {
    v12 = nullptr;
  }
  idAI2::Job_End(this: ai, playerEnt: v12, playVO: true);
  if ( !idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    HIBYTE(v15[0]) = 105;
    HIBYTE(v16) = 105;
    v15[1] = 0;
    v17 = -1;
    v13 = idEventArg::idEventArg(this: &v18, data: ai);
    memcpy(Dst: v14, Src: v15, Size: sizeof(v14));
    idEventReceiver::ProcessEvent(
      this: v19,
      result: fsm,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v16, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverJobCompleteVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE96B0
// RVA : 0x00AE96B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobCompleteVO::AIState_EnterState(
        idPlayerInteract_DeliverJobCompleteVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_Complete(this: ai, playerEnt: v9, playVO: true);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13) = 105;
  v12[1] = 0;
  v14 = -1;
  v10 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32));
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverJobFailedVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE97B8
// RVA : 0x00AE97B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobFailedVO::AIState_EnterState(
        idPlayerInteract_DeliverJobFailedVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_Failed(this: ai, playerEnt: v9, playVO: true);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13) = 105;
  v12[1] = 0;
  v14 = -1;
  v10 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32));
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverJobInProgressVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE98C0
// RVA : 0x00AE98C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverJobInProgressVO::AIState_EnterState(
        idPlayerInteract_DeliverJobInProgressVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_InProgress(this: ai, playerEnt: v9, playVO: true);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13) = 105;
  v12[1] = 0;
  v14 = -1;
  v10 = idEventArg::idEventArg(this: &v15, data: ai);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: fsm,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32));
}


// ========================================================================
// ?Evaluate@PCI_PlayerAcceptedJob@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE99C8
// RVA : 0x00AE99C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_PlayerAcceptedJob::Evaluate(
        PCI_PlayerAcceptedJob *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( idDeclJob::ShowsGUI(this: CurrentPlayerInteraction->interactionJob) )
    return v8->lastOfferChoice != OFFERCHOICE_ACCEPTED ? 0 : 0xA5;
  else
    return 165;
}


// ========================================================================
// ?Evaluate@PCI_PlayerDeclinedJob@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AE9A88
// RVA : 0x00AE9A88
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_PlayerDeclinedJob::Evaluate(
        PCI_PlayerDeclinedJob *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  return v7->lastOfferChoice != OFFERCHOICE_DECLINED ? 0 : 0x9B;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_WaitForJobChoice@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9B08
// RVA : 0x00AE9B08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitForJobChoice::AIState_EnterState(
        idPlayerInteract_WaitForJobChoice *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r4

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idAI2::Job_CompleteSavedJob(this: ai, player: v7);
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_PlayerAcceptedJob@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9B90
// RVA : 0x00AE9B90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerAcceptedJob::AIState_EnterState(
        idPlayerInteract_PlayerAcceptedJob *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idEventArg *v10; // r28
  _BYTE v11[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-A0h] BYREF
  int v13; // [sp+B0h] [-80h]
  int v14; // [sp+B4h] [-7Ch]
  idEventArg v15; // [sp+D0h] [-60h] BYREF
  idEventReceiver v16[5]; // [sp+F0h] [-40h] BYREF

  ai->aiVolatile.memory.interactionIsUsable = ai_fastJobInteraction.valueInteger != 0;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_Accepted(this: ai, playerEnt: v9, playVO: true);
  if ( !idComponentActionScript::RunningActionScript(this: &ai->actionScript, entity: ai) )
  {
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    v12[1] = 0;
    HIBYTE(v12[0]) = 105;
    HIBYTE(v13) = 105;
    v14 = -1;
    v10 = idEventArg::idEventArg(this: &v15, data: ai);
    memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
    idEventReceiver::ProcessEvent(
      this: v16,
      result: fsm,
      ev: *(const idEventDef **)&v10->type,
      arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v13, 32));
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_PlayerDeclinedJob@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9CE0
// RVA : 0x00AE9CE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerDeclinedJob::AIState_EnterState(
        idPlayerInteract_PlayerDeclinedJob *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r4

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idAI2::Job_Declined(this: ai, playerEnt: v7, playVO: true);
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_PlayerLeft@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AE9D70
// RVA : 0x00AE9D70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerLeft::AIState_EnterState(
        idPlayerInteract_PlayerLeft *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idGameLocal *v7; // r11
  int value; // r9
  idPlayer *v10; // r3
  idPlayer *v11; // r3
  idPlayer *v12; // r28
  int v13; // r8
  idInfoPath *v14; // r3
  idInfoPath *v15; // r3
  idInfoPath *v16; // r29
  idPhysics *Physics; // r3
  int v18; // r28
  double v19; // fp31
  idAIMoveState *MoveInterface; // r3
  int v21; // r3
  sitState_t sitState; // r8
  idInfoPath::anim_t *list; // r10
  const idDeclAnimWeb *decl; // r29
  idInfoPath::anim_t *v25; // r28
  idDeclAnimWebNode *v26; // r29
  idEventArg *v27; // r3
  idResource **p_nextOnHashChain; // r10
  _DWORD *v29; // r11
  int i; // ctr
  idEntity *v31; // r3
  idDeclSource *data; // r10
  idEventArg *v33; // r26
  idEventArg *v34; // r3
  _BYTE v35[20]; // [sp+70h] [-180h] BYREF
  _BYTE v36[20]; // [sp+90h] [-160h] BYREF
  idDeclAnimWeb v37; // [sp+B0h] [-140h] BYREF

  v7 = gameLocal;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v10 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v11 = idPlayer::CastTo(c: v10);
    v7 = gameLocal;
    v12 = v11;
  }
  else
  {
    v12 = nullptr;
  }
  idGameLocal::ResetSpecifiedInteractAi(this: v7, ai);
  idAI2::Job_PlayerLeft(this: ai, playerEnt: v12, playVO: true);
  v13 = ai->aiVolatile.memory.interactionPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
  {
    v14 = (idInfoPath *)gameLocal->entities.ptr[v13 & 0x1FFF];
    if ( v14 != nullptr )
    {
      v15 = idInfoPath::CastTo(c: v14);
      v16 = v15;
      if ( v15 != nullptr && v15->playerLeftAnims.num > 0 )
      {
        Physics = idEntity::GetPhysics(this: v15);
        v18 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        v19 = (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0
            ? ai->aiVolatile.animation.animFSM.currentMove.arrivalRadius
            : ai->aiVolatile.physics.moveState.moveParms.goalTolerance;
        MoveInterface = idAI2::GetMoveInterface(this: ai);
        if ( MoveInterface->ReachedPoint(this: MoveInterface, a2: (const idVec3 *)v18, a3: v19) )
        {
          v21 = idInfoPath::ChoosePlayerLeftAnim(this: v16);
          if ( v21 >= 0 )
          {
            sitState = v16->sitState;
            list = v16->playerLeftAnims.list;
            ai->aiVolatile.focus.enableBodyRotation = false;
            ai->aiVolatile.focus.enableGreetings = false;
            v37.states.list = (idDeclAnimWeb::idStateInfo *)20;
            ai->actorEditable.sitState = sitState;
            v37.subWebs.size = 0;
            decl = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
            HIBYTE(v37.states.num) = 0;
            v25 = &list[v21];
            *(_DWORD *)&v37.subWebs.granularity = &v37.states.num;
            v37.edges.list = (idDeclAnimWebEdge *)20;
            *(_DWORD *)&v37.models.granularity = &v37.edges.num;
            v37.models.size = 0;
            HIBYTE(v37.edges.num) = 0;
            idAI2::GetSubWebAndStateFromAnimWebPath(
              this: ai,
              animWebPath: v25->animWebNode.data,
              subWebName: (idStr *)&v37.subWebs.size,
              stateName: (idStr *)&v37.models.size);
            idDeclAnimWeb::GetSubWebIndexForName(
              this: &v37,
              result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)decl,
              subWebName: *(const char **)&v37.subWebs.granularity);
            idDeclAnimWeb::GetStateIndexForName(
              this: (idDeclAnimWeb *)((char *)&v37.__vftable + 2),
              result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)decl,
              name: *(const char **)&v37.models.granularity);
            idDeclAnimWeb::FindNodeIndex(
              this: (idDeclAnimWeb *)&v37.trackedMemory,
              result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
              subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIWORD(v37.__vftable),
              stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)LOWORD(v37.__vftable));
            if ( v37.trackedMemory >= 0 )
            {
              if ( SHIWORD(v37.trackedMemory) != -1 && (v26 = decl->nodes.list[SHIWORD(v37.trackedMemory)]) != nullptr )
              {
                if ( idEntityPtr<idEntity const>::operator->(this: &v25->trigger) != nullptr )
                {
                  v27 = idEventArg::idEventArg(this: (idEventArg *)&v37.programaticallyDefined, data: ai);
                  p_nextOnHashChain = &v37.nextOnHashChain;
                  v29 = (_DWORD *)&v27[-1].value.q[3];
                  for ( i = 5; i != 0; --i )
                    *++p_nextOnHashChain = (idResource *)*++v29;
                  v31 = idEntityPtr<idEntity const>::operator->(this: &v25->trigger);
                  idEventReceiver::PostEventMS(
                    this: v31,
                    ev: &EV_Activate,
                    time: 0,
                    arg1: (const idEventArg *)v37.networkID);
                }
                idAI2::SetEnableHeadTracking(this: ai, enable: v25->enableHeadTracking);
                if ( (unsigned __int8)idDeclAnimWebNode::IsLooping(this: v26) != 0 )
                {
                  data = (idDeclSource *)v25->animWebNode.data;
                  *(_DWORD *)&v37.edgeCache.granularity = 0;
                  HIBYTE(v37.resourceListPtr) = 105;
                  v37.resourceError = (const char *)10;
                  HIBYTE(v37.edgeCache.size) = 105;
                  v37.declSource = data;
                  v37.programaticallyDefined = 49;
                  v33 = idEventArg::idEventArg(this: (idEventArg *)&v37.scalars.size, data: ai);
                  memcpy(Dst: v36, Src: &v37.resourceListPtr, Size: sizeof(v36));
                  memcpy(Dst: v35, Src: &v37.edgeCache.size, Size: sizeof(v35));
                  idEventReceiver::ProcessEvent(
                    this: (idEventReceiver *)&v37.layers.size,
                    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
                    ev: *(const idEventDef **)&v33->type,
                    arg1: (const idEventArg *)LODWORD(v33->value.v[1]),
                    arg2: (const idEventArg *)LODWORD(v33->value.v[2]),
                    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v37.programaticallyDefined, 32),
                    arg4: (const idEventArg *)v37.nodes.list);
                }
                else
                {
                  v37.declSource = (idDeclSource *)v25->animWebNode.data;
                  v37.programaticallyDefined = 49;
                  v34 = idEventArg::idEventArg(this: (idEventArg *)&v37.layers.size, data: ai);
                  idEventReceiver::ProcessEvent(
                    this: (idEventReceiver *)&v37.scalars.size,
                    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
                    ev: *(const idEventDef **)&v34->type,
                    arg1: (const idEventArg *)LODWORD(v34->value.v[1]),
                    arg2: (const idEventArg *)LODWORD(v34->value.v[2]));
                }
                idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
                idAI2::ClearLookFocus(this: ai);
                idAI2::SetEnableAutoFocus(this: ai, enable: true);
                idStr::FreeData(this: (idStr *)&v37.models.size);
              }
              else
              {
                idLib::Warning(fmt: "Failed to find interaction node animation '%s'", v25->animWebNode.data);
                idStr::FreeData(this: (idStr *)&v37.models.size);
              }
            }
            else
            {
              idStr::FreeData(this: (idStr *)&v37.models.size);
            }
            idStr::FreeData(this: (idStr *)&v37.subWebs.size);
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$495076
// EA  : 0x82AEA19C
// RVA : 0x00AEA19C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_495076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 256));
}


// ========================================================================
// __unwind$495077
// EA  : 0x82AEA1C4
// RVA : 0x00AEA1C4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void _unwind_495077()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 288));
}


// ========================================================================
// ?Evaluate@PCI_PlayerPurchasedItem@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEA1F0
// RVA : 0x00AEA1F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_PlayerPurchasedItem::Evaluate(
        PCI_PlayerPurchasedItem *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  return v7->lastOfferChoice != OFFERCHOICE_PURCHASE ? 0 : 0xA6;
}


// ========================================================================
// ?Evaluate@PCI_PlayerClosedMerchantMenu@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEA278
// RVA : 0x00AEA278
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

int __fastcall PCI_PlayerClosedMerchantMenu::Evaluate(
        PCI_PlayerClosedMerchantMenu *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  return v7->lastOfferChoice != OFFERCHOICE_DECLINED ? 0 : 0xA7;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_MerchantInteract@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA2F8
// RVA : 0x00AEA2F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_MerchantInteract::AIState_EnterState(
        idPlayerInteract_MerchantInteract *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r6
  idPlayer *v6; // r3
  idPlayer *v7; // r30
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  __int64 v12; // r4
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  int v16; // [sp+14h] [-5Ch]

  ai->aiVolatile.memory.interactionIsUsable = false;
  idAI2::SetEnableAutoFocus(this: ai, enable: false);
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idAI2::AddDynamicGoods(this: ai, player: v7);
  if ( (unsigned __int8)idAI2::HasGoodsToSellPlayerNeeds(this: ai, player: v7) != 0 )
  {
    CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
    idPlayer::OfferInteraction(
      this: v7,
      offerType: OFFERTYPE_VENDER,
      interaction: CurrentPlayerInteraction,
      offeringEntity: ai);
  }
  else
  {
    LODWORD(v12) = ai->name.data;
    HIDWORD(v12) = "'%s': has no goods for sale player needs. continue to end\n";
    idAI2::Job_DebugPrintf(fmt: v12, a2: v10, a3: v9, a4: v8, a5: v13, a6: v14, a7: v15, a8: v16);
    v7->lastOfferChoice = OFFERCHOICE_DECLINED;
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_PlayerPurchasedItem@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA3E0
// RVA : 0x00AEA3E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerPurchasedItem::AIState_EnterState(
        idPlayerInteract_PlayerPurchasedItem *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v5; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    idPlayer::CastTo(c: v5)->lastOfferChoice = OFFERCHOICE_UNKNOWN;
  }
  else
  {
    MEMORY[0x311C] = 7;
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_PlayerClosedMerchantMenu@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA468
// RVA : 0x00AEA468
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_PlayerClosedMerchantMenu::AIState_EnterState(
        idPlayerInteract_PlayerClosedMerchantMenu *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r29
  const idDeclVoiceOver *finishedVO; // r5
  __int64 v9; // r4
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  const idDeclAIPlayerInteraction *decl; // r4
  int currentPlayerInteraction; // r5
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  v7->lastOfferChoice = OFFERCHOICE_UNKNOWN;
  finishedVO = idAI2::GetCurrentPlayerInteraction(this: ai)->finishedVO;
  if ( finishedVO != nullptr )
  {
    idGameLocal::PlayInteractVoiceOver(this: gameLocal, ai, vo: finishedVO, priority: AIVOICEPRIORITY_MED);
    LODWORD(v9) = ai->name.data;
    HIDWORD(v9) = "'%s': playing merchant interaction finished VO.\n";
    idAI2::Job_DebugPrintf(fmt: v9, a2: v12, a3: v11, a4: v10, a5: v15, a6: v16, a7: v17, a8: v18);
  }
  else
  {
    idAIVoiceController::FadeVoiceOver(this: &ai->aiVolatile.voiceController, ai);
    idLib::Warning(fmt: "missing merchant interaction finished VO.");
  }
  decl = ai->aiVolatile.aiPlayerInteraction.decl;
  currentPlayerInteraction = ai->aiVolatile.memory.currentPlayerInteraction;
  if ( decl->interactList.list[currentPlayerInteraction].messageExpiresInteraction )
    idJobManager::SetJobOfferPlayed(
      this: &v7->jobManager,
      interactionDecl: decl,
      interactionNumber: currentPlayerInteraction,
      played: true);
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_WaitBriefly@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA568
// RVA : 0x00AEA568
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitBriefly::AIState_EnterState(
        idPlayerInteract_WaitBriefly *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idEntityPtr<idPlayer> *p_interactionEntity; // r31
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  idPlayer *v10; // r3
  idPlayer *v11; // r4
  idPlayer *v12; // r3
  idPlayer *v13; // r31
  __int64 v14; // r10
  __int64 v15; // r8
  const aiPlayerInteraction_t *Interaction; // r31
  int v17; // r10

  p_interactionEntity = &ai->aiVolatile.memory.interactionEntity;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  idAI2::Job_CompleteSavedJob(this: ai, player: v9);
  if ( gameLocal->spawnIds.ptr[p_interactionEntity->spawnId.value & 0x1FFF] == p_interactionEntity->spawnId.value >> 13
    && (v10 = (idPlayer *)gameLocal->entities.ptr[p_interactionEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v11 = idPlayer::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  idAI2::Job_AcceptSavedJob(this: ai, player: v11);
  if ( gameLocal->spawnIds.ptr[p_interactionEntity->spawnId.value & 0x1FFF] == p_interactionEntity->spawnId.value >> 13
    && (v12 = (idPlayer *)gameLocal->entities.ptr[p_interactionEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v13 = idPlayer::CastTo(c: v12);
  }
  else
  {
    v13 = nullptr;
  }
  idAI2::PlayerInteractionDone(this: ai, playerLeft: false);
  Interaction = idAIPlayerInteraction::FindInteraction(
                  this: &ai->aiVolatile.aiPlayerInteraction,
                  player: v13,
                  debugString: 0x100000000LL,
                  a4: v15,
                  a5: v14);
  idAI2::SetCurrentPlayerInteraction(this: ai, interaction: Interaction);
  v17 = -1;
  if ( Interaction == nullptr )
    v17 = curTime + 1000;
  ai->aiVolatile.memory.waitExpireTime = v17;
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA6C8
// RVA : 0x00AEA6C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_Default::AIState_EnterState(
        idPlayerInteract_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPlayer *v5; // r30
  int value; // r6
  idPlayer *v7; // r3
  idAIGameState *p_aiGameState; // r28
  const idSpawnId *v9; // r26
  const idAILogic *v10; // r3
  const idSpawnId *v11; // r8
  const idInfoPath *BestIneractionPoint; // r3
  idEntityPtr<idInfoPath const > *p_interactionPoint; // r10
  standState_t standState; // r11
  idSpawnId v15; // [sp+50h] [-70h] BYREF
  idSpawnId v16; // [sp+54h] [-6Ch] BYREF
  idAILogic v17[3]; // [sp+60h] [-60h] BYREF

  v5 = nullptr;
  ai->aiVolatile.focus.enableBodyRotation = false;
  idAI2::SetEnableAutoFocus(this: ai, enable: false);
  ai->aiVolatile.focus.enableGreetings = false;
  *((_BYTE *)&ai->aiVolatile + 49704) &= ~2u;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v5 = idPlayer::CastTo(c: v7);
  }
  idAI2::AddDynamicGoods(this: ai, player: v5);
  p_aiGameState = &gameLocal->aiGameState;
  idSpawnId::idSpawnId(this: &v15, ent: ai);
  v9 = idSpawnId::idSpawnId(this: &v16, ent: v5);
  v10 = idAILogic::idAILogic(this: v17, ai);
  idAIWorldState::AddEntityState(
    this: &ai->aiVolatile.world.worldState,
    gameState: p_aiGameState,
    owner: v10,
    entId: v9,
    stimulusType: AISTIMULUS_TOUCH,
    stimulusAmount: 1.0,
    sourceId: v11);
  idAI2::SetLookFocusEntity(this: ai, ent: v5, keepFocusInView: false, aimPoint: AIMPOINT_HEAD, timeout: -1);
  BestIneractionPoint = FindBestIneractionPoint(ai, player: v5);
  p_interactionPoint = &ai->aiVolatile.memory.interactionPoint;
  if ( BestIneractionPoint != nullptr )
  {
    p_interactionPoint->spawnId.value = (gameLocal->spawnIds.ptr[BestIneractionPoint->entityNumber] << 13)
                                      | BestIneractionPoint->entityNumber;
    standState = BestIneractionPoint->standState;
    if ( standState != STANDSTATE_MAX )
      ai->actorEditable.standState = standState;
  }
  else
  {
    p_interactionPoint->spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_MoveToInteractionPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEA838
// RVA : 0x00AEA838
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_MoveToInteractionPoint::AIState_EnterState(
        idPlayerInteract_MoveToInteractionPoint *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  const idInfoPath *BestIneractionPoint; // r3
  idInfoPath *v11; // r31
  standState_t standState; // r11
  idPhysics *Physics; // r29
  idPhysics *v14; // r21
  float *v15; // r3
  idPhysics_vtbl *v16; // r9
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r5
  double v18; // fp12
  double v19; // fp11
  float *v20; // r3
  double v21; // fp9
  double v22; // fp8
  idEventArg *v23; // r31
  int v24; // r8
  idInfoPath *v25; // r3
  idInfoPath *v26; // r3
  const idEventArg *v27; // [sp+8h] [-268h]
  const idEventArg *v28; // [sp+Ch] [-264h]
  _BYTE v29[20]; // [sp+70h] [-200h] BYREF
  _BYTE v30[20]; // [sp+90h] [-1E0h] BYREF
  _BYTE v31[20]; // [sp+B0h] [-1C0h] BYREF
  _BYTE v32[20]; // [sp+D0h] [-1A0h] BYREF
  _BYTE v33[20]; // [sp+F0h] [-180h] BYREF
  float v34[5]; // [sp+110h] [-160h] BYREF
  float v35[5]; // [sp+130h] [-140h] BYREF
  float v36[5]; // [sp+150h] [-120h] BYREF
  int v37; // [sp+170h] [-100h]
  int v38; // [sp+174h] [-FCh]
  const idEventArg *v39; // [sp+178h] [-F8h]
  const idEventArg *v40; // [sp+17Ch] [-F4h]
  _DWORD v41[5]; // [sp+190h] [-E0h] BYREF
  _DWORD v42[5]; // [sp+1B0h] [-C0h] BYREF
  idEventArg v43; // [sp+1D0h] [-A0h] BYREF
  idEventReceiver v44[10]; // [sp+1F0h] [-80h] BYREF

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  BestIneractionPoint = FindBestIneractionPoint(ai, player: v9);
  v11 = (idInfoPath *)BestIneractionPoint;
  if ( BestIneractionPoint != nullptr )
  {
    ai->aiVolatile.memory.interactionPoint.spawnId.value = (gameLocal->spawnIds.ptr[BestIneractionPoint->entityNumber] << 13)
                                                         | BestIneractionPoint->entityNumber;
  }
  else
  {
    v24 = ai->aiVolatile.memory.interactionPoint.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13
      && (v25 = (idInfoPath *)gameLocal->entities.ptr[v24 & 0x1FFF]) != nullptr )
    {
      v26 = idInfoPath::CastTo(c: v25);
    }
    else
    {
      v26 = nullptr;
    }
    v11 = v26;
    if ( v26 == nullptr )
    {
      idState::SetEnterFailed(this, failed: true);
      return;
    }
  }
  standState = v11->standState;
  if ( standState != STANDSTATE_MAX )
    ai->actorEditable.standState = standState;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  Physics = idEntity::GetPhysics(this: v11);
  v14 = idEntity::GetPhysics(this: v11);
  v15 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  v16 = v14->__vftable;
  v34[1] = *v15;
  HIBYTE(v41[0]) = 105;
  GetOrigin = v16->GetOrigin;
  v18 = v15[1];
  v19 = v15[2];
  v36[1] = 0.1;
  HIBYTE(v34[0]) = 118;
  v34[2] = v18;
  v41[1] = 1;
  v34[3] = v19;
  HIBYTE(v36[0]) = 102;
  HIBYTE(v42[0]) = 105;
  v42[1] = 2;
  v20 = (float *)GetOrigin(this: v14, a2: 0);
  HIBYTE(v35[0]) = 118;
  HIBYTE(v37) = 105;
  v38 = 25;
  v21 = v20[1];
  v22 = v20[2];
  v35[1] = *v20;
  v35[2] = v21;
  v35[3] = v22;
  v23 = idEventArg::idEventArg(this: &v43, data: ai);
  memcpy(Dst: v33, Src: v34, Size: sizeof(v33));
  memcpy(Dst: v32, Src: v41, Size: sizeof(v32));
  memcpy(Dst: v31, Src: v36, Size: sizeof(v31));
  memcpy(Dst: v30, Src: v42, Size: sizeof(v30));
  memcpy(Dst: v29, Src: v35, Size: sizeof(v29));
  idEventReceiver::ProcessEvent(
    this: v44,
    result: fsm,
    ev: *(const idEventDef **)&v23->type,
    arg1: (const idEventArg *)LODWORD(v23->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v23->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v37, 32),
    arg4: v39,
    arg5: v40,
    arg6: v27,
    arg7: v28);
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_ReachedInteractionPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEAAE0
// RVA : 0x00AEAAE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ReachedInteractionPoint::AIState_EnterState(
        idPlayerInteract_ReachedInteractionPoint *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idInfoPath *v8; // r3
  idInfoPath *v9; // r30
  idInfoPath *v10; // r3
  standState_t standState; // r11
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const aiPlayerInteraction_t *v13; // r29
  idAIOrientation *BodyOrientation; // r3
  int v15; // r8
  idPlayer *v16; // r3
  idPlayer *v17; // r4
  sitState_t sitState; // r11
  standState_t v19; // r11
  idEventArg *v20; // r29
  _BYTE v21[20]; // [sp+70h] [-E0h] BYREF
  _DWORD v22[5]; // [sp+90h] [-C0h] BYREF
  int v23; // [sp+B0h] [-A0h]
  int v24; // [sp+B4h] [-9Ch]
  idEventArg v25; // [sp+D0h] [-80h] BYREF
  idEventReceiver v26[8]; // [sp+F0h] [-60h] BYREF

  ai->aiVolatile.memory.triggeredInteraction.spawnId.value = 0x1FFF;
  ai->aiVolatile.memory.interactionIsUsable = ai_fastJobInteraction.valueInteger != 0;
  value = ai->aiVolatile.memory.interactionPoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idInfoPath::CastTo(c: v8);
    v9 = v10;
    if ( v10 != nullptr )
    {
      standState = v10->standState;
      if ( standState != STANDSTATE_MAX )
        ai->actorEditable.standState = standState;
    }
  }
  else
  {
    v9 = nullptr;
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  v13 = CurrentPlayerInteraction;
  if ( CurrentPlayerInteraction != nullptr )
  {
    if ( CurrentPlayerInteraction->allowBodyRotation )
    {
      ai->aiVolatile.focus.enableBodyRotation = true;
      if ( v9 != nullptr )
      {
        BodyOrientation = idAI2::GetBodyOrientation(this: ai);
        idAIOrientation::SetIdealDir(this: BodyOrientation, ai, dir: v9->spawnOrientation.mat);
      }
    }
    else
    {
      ai->aiVolatile.focus.enableBodyRotation = false;
    }
    if ( v13->allowAutoFocus )
    {
      idAI2::SetEnableAutoFocus(this: ai, enable: true);
    }
    else
    {
      idAI2::SetEnableAutoFocus(this: ai, enable: false);
      v15 = ai->aiVolatile.memory.interactionEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
        && (v16 = (idPlayer *)gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
      {
        v17 = idPlayer::CastTo(c: v16);
      }
      else
      {
        v17 = nullptr;
      }
      idAI2::SetLookFocusEntity(
        this: ai,
        ent: v17,
        keepFocusInView: v13->allowBodyRotation,
        aimPoint: AIMPOINT_HEAD,
        timeout: -1);
    }
    if ( v13->posture != POSTURE_NONE )
      ((void (__fastcall *)(idAI2 *))ai->SetPosture)(a1: ai);
    sitState = v13->sitState;
    if ( sitState != SITSTATE_MAX )
      ai->actorEditable.sitState = sitState;
    v19 = v13->standState;
    if ( v19 != STANDSTATE_MAX )
      ai->actorEditable.standState = v19;
  }
  if ( ai->actorEditable.mentalState == MENTALSTATE_ASLEEP )
    ai->actorEditable.mentalState = MENTALSTATE_AWAKE;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v22[1] = 0;
  HIBYTE(v22[0]) = 105;
  HIBYTE(v23) = 105;
  v24 = -1;
  v20 = idEventArg::idEventArg(this: &v25, data: ai);
  memcpy(Dst: v21, Src: v22, Size: sizeof(v21));
  idEventReceiver::ProcessEvent(
    this: v26,
    result: fsm,
    ev: *(const idEventDef **)&v20->type,
    arg1: (const idEventArg *)LODWORD(v20->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v20->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v23, 32));
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_WaitForInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEAD50
// RVA : 0x00AEAD50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_WaitForInteraction::AIState_EnterState(
        idPlayerInteract_WaitForInteraction *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r28
  _BYTE v8[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-A0h] BYREF
  int v10; // [sp+B0h] [-80h]
  int v11; // [sp+B4h] [-7Ch]
  idEventArg v12; // [sp+D0h] [-60h] BYREF
  idEventReceiver v13[5]; // [sp+F0h] [-40h] BYREF

  ai->aiVolatile.memory.triggeredInteraction.spawnId.value = 0x1FFF;
  UpdateInteractionIsUsableFlag(ai);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v9[0]) = 105;
  v9[1] = 0;
  HIBYTE(v10) = 105;
  v11 = -1;
  v7 = idEventArg::idEventArg(this: &v12, data: ai);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_ProcessInteraction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEAE10
// RVA : 0x00AEAE10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_ProcessInteraction::AIState_EnterState(
        idPlayerInteract_ProcessInteraction *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idPlayer *v5; // r31
  int value; // r8
  idPlayer *v7; // r3
  const aiPlayerInteraction_t *CurrentPlayerInteraction; // r3
  const idDeclGameStateInt *interactionGameStateIntDecl; // r4

  v5 = nullptr;
  ai->aiVolatile.memory.triggeredInteraction.spawnId.value = 0x1FFF;
  ai->aiVolatile.memory.interactionIsUsable = ai_fastJobInteraction.valueInteger != 0;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v5 = idPlayer::CastTo(c: v7);
  }
  CurrentPlayerInteraction = idAI2::GetCurrentPlayerInteraction(this: ai);
  if ( v5 != nullptr && CurrentPlayerInteraction != nullptr )
  {
    interactionGameStateIntDecl = CurrentPlayerInteraction->interactionGameStateIntDecl;
    if ( interactionGameStateIntDecl != nullptr )
      idJobManager::SetGameStateIntValue(this: &v5->jobManager, gameState: interactionGameStateIntDecl, stateValue: 1);
  }
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_DeliverNonJobGUIVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEAF00
// RVA : 0x00AEAF00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_DeliverNonJobGUIVO::AIState_EnterState(
        idPlayerInteract_DeliverNonJobGUIVO *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idGameLocal *v7; // r11
  int value; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r3
  idPlayer *v11; // r4
  idEventArg *v12; // r28
  _BYTE v13[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-A0h] BYREF
  int v15; // [sp+B0h] [-80h]
  int v16; // [sp+B4h] [-7Ch]
  idEventArg v17; // [sp+D0h] [-60h] BYREF
  idEventReceiver v18[5]; // [sp+F0h] [-40h] BYREF

  v7 = gameLocal;
  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idPlayer::CastTo(c: v9);
    v7 = gameLocal;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  if ( ai != nullptr )
    v11->guiInteractionEntity.spawnId.value = (v7->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
  else
    v11->guiInteractionEntity.spawnId.value = 0x1FFF;
  idAI2::Job_MessageVO(this: ai, playerEnt: v11, playVO: true, checkAIType: true);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  HIBYTE(v14[0]) = 105;
  HIBYTE(v15) = 105;
  v14[1] = 0;
  v16 = -1;
  v12 = idEventArg::idEventArg(this: &v17, data: ai);
  memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
  idEventReceiver::ProcessEvent(
    this: v18,
    result: fsm,
    ev: *(const idEventDef **)&v12->type,
    arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v15, 32));
}


// ========================================================================
// ?AIState_EnterState@idPlayerInteract_NonJobDeliverJobCompleteVO@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEB040
// RVA : 0x00AEB040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __fastcall idPlayerInteract_NonJobDeliverJobCompleteVO::AIState_EnterState(
        idPlayerInteract_NonJobDeliverJobCompleteVO *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idPlayer *v6; // r3
  idPlayer *v7; // r31
  idJob *CompletedJob; // r3

  value = ai->aiVolatile.memory.interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idPlayer::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  CompletedJob = idJobManager::FindCompletedJob(this: &v7->jobManager, completionNPC: ai);
  if ( CompletedJob != nullptr
    && (ai->aiVolatile.memory.completeJobDecl = CompletedJob->decl, ai_debugInteraction.valueInteger > 0) )
  {
    idLib::Warning(
      fmt: "Job '%s' completed on non job interaction... Could need to figure out VO.",
      CompletedJob->decl->name.str);
    v7->guiInteractionEntity.spawnId.value = 0x1FFF;
  }
  else
  {
    v7->guiInteractionEntity.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// `dynamic initializer for 'ai_interactionFadeForApproachVOFlag''
// EA  : 0x833696B8
// RVA : 0x013696B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_playerinteract.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_interactionFadeForApproachVOFlag__()
{
  idCVar::idCVar(
    this: &ai_interactionFadeForApproachVOFlag,
    name: "ai_interactionFadeForApproachVOFlag",
    value: "0",
    flags: 1,
    description: "Flag to fade the global volume for 'approach' VOs (all other interaction VOs always cause global volume change.)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_interactionFadeForApproachVOFlag__);
}

