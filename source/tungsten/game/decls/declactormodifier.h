#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declactormodifier.h
// Recovered logical types: 12
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2010; PDB kind: enum.
enum idDeclActorModifier::ActorModifierAction_t : __int32
{
  ACTION_MODIFY_VALUE = 0x0,
  ACTION_APPLY_MODIFIER = 0x1,
  ACTION_DROP_POI = 0x2,
  ACTION_GIVE_OVERDRIVE_POINTS = 0x3,
  ACTION_CLEAR_OVERDRIVE_POINTS = 0x4,
  MODIFIER_ACTION_COUNT = 0x5,
};

// IDA Local Type ordinal 2011; PDB kind: enum.
enum idDeclActorModifier::ActorModifierAttribute_t : __int32
{
  NULL_MODIFICATION = 0x0,
  SPEED_MODIFICATION = 0x1,
  DAMAGE_MODIFICATION = 0x2,
  OVERDRIVE_DISABLE_MODIFICATION = 0x3,
  MODIFIER_ATTRIB_COUNT = 0x4,
};

// IDA Local Type ordinal 2012; PDB kind: enum.
enum idDeclActorModifier::ActorModifierAttributeOperation_t : __int32
{
  MULTIPLY_VALUE = 0x0,
  ADD_VALUE = 0x1,
};

// IDA Local Type ordinal 2014; PDB kind: enum.
enum idDeclActorModifier::ActorModifierTarget_t : __int32
{
  TARGET_SELF = 0x0,
  TARGET_VICTIM = 0x1,
  TARGET_ATTACKER = 0x2,
};

// IDA Local Type ordinal 2015; PDB kind: enum.
enum idDeclActorModifier::ActorModifierDepType_t : __int32
{
  NULL_DEPTYPE = 0x0,
  OVERDRIVE_FULL_DEPTYPE = 0x1,
  DEPTYPE_COUNT = 0x2,
};

// IDA Local Type ordinal 2016; PDB kind: enum.
enum idDeclActorModifier::TriggerType_t : __int32
{
  TRIGGER_TYPE_BUTTON = 0x0,
  TRIGGER_TYPE_ALWAYS_ON = 0x1,
  TRIGGER_TYPE_EVENT = 0x2,
  TRIGGER_TYPE_DAMAGE_DEALT = 0x3,
  TRIGGER_TYPE_DAMAGE_TAKEN = 0x4,
  TRIGGER_TYPE_TIMER = 0x5,
};

// IDA Local Type ordinal 2039; PDB kind: enum.
enum idDeclActorModifier::ActorModifierUISlot_t : __int32
{
  SLOT_HIDDEN = 0x0,
  SLOT_ACTIVE = 0x1,
  SLOT_PASSIVE = 0x2,
  SLOT_OVERDRIVE = 0x3,
};

// IDA Local Type ordinal 15289; PDB kind: class.
class __declspec(align(4)) idDeclActorModifier : public idDeclInventory
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15297.
  virtual ~idDeclActorModifier();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idList<idDeclActorModifier::ActorModifierOutput_t,5> outputs;
  idList<idDeclActorModifier::ActorModifierTrigger_t,5> triggers;
  idList<idDeclActorModifier::ActorModifierDeps_t,5> deps;
  int lifetime;
  int removeAfter;
  int cooldown;
  const idDeclFX *fxDecl;
  idDeclActorModifier::ActorModifierUISlot_t uiSlot;
  bool removeOnDeath;
};

// IDA Local Type ordinal 15290; PDB kind: struct.
struct idDeclActorModifier::ActorModifierSounds_t
{
  const idSoundShader *attackSound;
  const idSoundShader *activeSound;
  const idSoundShader *startSound;
  const idSoundShader *stopSound;
  const idSoundShader *almostDoneSound;
};

// IDA Local Type ordinal 15291; PDB kind: struct.
struct __declspec(align(4)) idDeclActorModifier::ActorModifierOutput_t
{
  idDeclActorModifier::ActorModifierAction_t action;
  idDeclActorModifier::ActorModifierAttribute_t attrib;
  idDeclActorModifier::ActorModifierAttributeOperation_t operation;
  idDeclActorModifier::ActorModifierTarget_t target;
  float value;
  const idDeclActorModifier *decl;
  const idMaterial *customMaterial;
  const idMaterial *customWeaponMaterial;
  const idMaterial *customMaterial3rdPerson;
  const idMaterial *customWeaponMaterial3rdPerson;
  idDeclActorModifier::ActorModifierSounds_t sounds;
  bool predicted;
};

// IDA Local Type ordinal 15294; PDB kind: struct.
struct __unaligned __declspec(align(4)) idDeclActorModifier::ActorModifierTrigger_t
{
  idDeclActorModifier::TriggerType_t type;
  usercmdButton_t button;
  int timerDelay;
  idList<idDeclActorModifier::ActorModifierTrigger_t,5> triggers;
};

// IDA Local Type ordinal 15295; PDB kind: struct.
struct idDeclActorModifier::ActorModifierDeps_t
{
  idDeclActorModifier::ActorModifierDepType_t type;
};
