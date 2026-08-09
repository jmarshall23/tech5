#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_opencombat.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16874; PDB kind: class.
class idOpenCombatFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16875.
  virtual idTypeInfo *GetType();
  virtual ~idOpenCombatFSM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual bool CanUse(idFiniteStateMachine *, const int);
  virtual idState *GetErrorState();
  virtual idState *GetDoneState();
  virtual void Save(idFile_String *, const char *);
  virtual void Restart(idFiniteStateMachine *, const int);
  virtual void AddState(idState *);
  virtual int GetUpdateInterval();
  virtual void InitStates(const idFiniteStateMachineParams *);
  virtual void AppendDefaultTransitions(idState *);
  virtual void SetNextState(const idStateData::transResult_t *, const int);
  virtual void SetState(const idStateData::transResult_t *, const int, const bool);

  __unaligned __declspec(align(1)) idOpenCombat_Default stateDefault;
  idOpenCombat_MoveTowardEnemy stateMoveTowardEnemy;
  __unaligned __declspec(align(1)) idOpenCombat_MoveToSightEnemy stateMoveToSightEnemy;
  idOpenCombat_AttackIdle stateAttackIdle;
  __unaligned __declspec(align(1)) idOpenCombat_StartThrowProjectile stateStartThrowProjectile;
  idOpenCombat_ThrowProjectile stateThrowProjectile;
  __unaligned __declspec(align(1)) idOpenCombat_Shoot stateShoot;
  idOpenCombat_AttackMove stateAttackMove;
  __unaligned __declspec(align(1)) idOpenCombat_ReachedEnemyPos stateReachedEnemyPos;
  idOpenCombat_AttackMelee stateAttackMelee;
  __unaligned __declspec(align(1)) idOpenCombat_ChargeMelee stateChargeMelee;
  idOpenCombat_LeapAttack stateLeapAttack;
  __unaligned __declspec(align(1)) idOpenCombat_MoveToCoverAndReload stateMoveToCoverAndReload;
  idOpenCombat_MoveOutOfSightAndReload stateMoveOutOfSightAndReload;
  __unaligned __declspec(align(1)) idOpenCombat_ReloadWeapon stateReloadWeapon;
  idOpenCombat_Stand stateStand;
  __unaligned __declspec(align(1)) idOpenCombat_Crouch stateCrouch;
  idOpenCombat_EnemyNotVisible stateEnemyNotVisible;
  __unaligned __declspec(align(1)) idOpenCombat_Sidestep stateSidestep;
  idOpenCombat_ChargeSidestep stateChargeSidestep;
  __unaligned __declspec(align(1)) idOpenCombat_MoveTowardEnemyFailed stateMoveTowardEnemyFailed;
  idOpenCombat_MoveFailed stateMoveFailed;
  __unaligned __declspec(align(1)) idOpenCombat_Rage stateRage;
  idOpenCombat_MoveToRecharge stateMoveToRecharge;
  __unaligned __declspec(align(1)) idOpenCombat_Recharging stateRecharging;
  idOpenCombat_MoveToRoleHintNode stateMoveToRoleHintNode;
  __unaligned __declspec(align(1)) idOpenCombat_PlayOverrideAnim statePlayOverrideAnim;
};
