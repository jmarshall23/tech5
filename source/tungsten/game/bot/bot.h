#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\bot.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14926; PDB kind: class.
class idBot
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14927.
  virtual ~idBot();

  bool isControllingAFKPlayer;
  const char *debugName;
  idBotBehaviorTree *behaviorTree;
  idBotAimState *aimState;
  idBotWorldState *worldState;
  idBotMoveState *moveState;
  idBotWeaponState *weaponState;
  const idDeclBot *behaviorDef;
  idPlayer *owner;
  idBotGoal goalTask;
  usercmd_t usercmd;
};
