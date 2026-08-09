#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aievent.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1276; PDB kind: enum.
enum idAIEvent::aiEventClass_t : __int32
{
  AIEVENT_NONE = 0x0,
  AIEVENT_FOOTSTEP = 0x1,
  AIEVENT_GUNFIRE = 0x2,
  AIEVENT_EXPLOSION = 0x4,
  AIEVENT_GRENADE = 0x8,
  AIEVENT_BODY = 0x10,
  AIEVENT_VEHICLE = 0x20,
  AIEVENT_AIM = 0x40,
  AIEVENT_VOICE = 0x200,
  AIEVENT_INVESTIGATE = 0x800,
  AIEVENT_PROJECTILE = 0x1000,
  AIEVENT_POSSESSION = 0x2000,
  AIEVENT_DOOR_MOTION = 0x10000,
  AIEVENT_DEAD_BODY_LAND = 0x20000,
  AIEVENT_DEPLOY_SOUND = 0x40000,
  AIEVENT_VEHICLE_SOUND = 0x80000,
  AIEVENT_PLAYER_GRENADE = 0x100000,
  AIEVENT_PLAYER_INTERACTION = 0x200000,
  AIEVENT_RELOAD = 0x1000000,
  AIEVENT_PROJECTILE_IMPACT = 0x2000000,
  AIEVENT_DELAYED_VO = 0x4000000,
  AIEVENT_ALL_AI = 0xFFEFFFFF,
  AIEVENT_ALL_PLAYER = 0x100000,
  AIEVENT_ALL = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2368; PDB kind: enum.
enum idAIEvent::aiEventUpdateResult_t : __int32
{
  AIUPDATE_OK = 0x0,
  AIUPDATE_REMOVE = 0x1,
};

// IDA Local Type ordinal 2372; PDB kind: enum.
enum idAIEvent::aiEventPriority_t : __int32
{
  AIPRIORITY_VERY_LOW = 0x0,
  AIPRIORITY_LOW = 0x19,
  AIPRIORITY_MEDIUM = 0x32,
  AIPRIORITY_HIGH = 0x4B,
  AIPRIORITY_VERY_HIGH = 0x64,
};

// IDA Local Type ordinal 2758; PDB kind: enum.
enum idAIEvent::aiEventTrigger_t : __int32
{
  TRIGGERS_NOTHING = 0x0,
  TRIGGERS_COMBAT = 0x1,
  TRIGGERS_SEARCH = 0x2,
  TRIGGERS_RELAXED = 0x4,
};

// IDA Local Type ordinal 14193; PDB kind: class.
class idEvent : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14194.
  virtual idTypeInfo *GetType();
  virtual ~idEvent();

  const idEventDef *eventdef;
  idEventArg args[8];
  unsigned __int8 *data;
  int time;
  idEventReceiver *object;
  idLinkList<idEvent> eventNode;
};

// IDA Local Type ordinal 15125; PDB kind: class.
class idAIEvent : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15126.
  virtual idTypeInfo *GetType();
  virtual ~idAIEvent();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);

  const idDeclAiEvent *eventDecl;
  bool enabled;
  idEntityPtr<idEntity const > originator;
  idEntityPtr<idEntity const > instigator;
  idVec3 origin;
  idVec3 stimulusOrigin;
  int startTime;
  idHandle<int,enum invalidAIEvent_t,-1> handle;
};
