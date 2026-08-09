#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\vehicleai\vehicleaidef.h
// Recovered logical types: 37
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2202; PDB kind: enum.
enum vehicleAiSetup_t::difficultyLevel_t::difficulty_t : __int32
{
  DIFFICULTY_LOW = 0x0,
  DIFFICULTY_MED = 0x1,
  DIFFICULTY_HIGH = 0x2,
};

// IDA Local Type ordinal 2203; PDB kind: enum.
enum vehicleAiSetup_t::patrol_t::patrolPath_t : __int32
{
  PATROL_CYCLICAL = 0x0,
  PATROL_REBOUND = 0x1,
  PATROL_RANDOM = 0x2,
  PATROL_ONCE = 0x3,
};

// IDA Local Type ordinal 2204; PDB kind: enum.
enum vehicleAiSetup_t::cmdName_t : __int32
{
  CMD_NONE = 0x0,
  CMD_OCCUPANTS = 0x1,
  CMD_TRAVEL = 0x2,
  CMD_WAIT_FOR_TRIGGER = 0x3,
  CMD_TO_TRIGGER = 0x4,
  CMD_PAUSE_STATE = 0x5,
  CMD_CHANGE_STATE = 0x6,
  CMD_ENTER_VEHICLE = 0x7,
  CMD_EXIT_VEHICLE = 0x8,
  CMD_UNLOCK_OCCUPANTS = 0x9,
  CMD_WAIT = 0xA,
  CMD_WAIT_FOR_SOUND = 0xB,
  CMD_WAIT_FOR_VOICEOVER = 0xC,
  CMD_POWER_SLIDE = 0xD,
  CMD_WAIT_TIL_DEAD = 0xE,
  CMD_WAIT_FOR_PLAYER = 0xF,
  CMD_TRAVEL_TIL_DEAD = 0x10,
  CMD_TRIGGER_ACTION = 0x11,
};

// IDA Local Type ordinal 2224; PDB kind: enum.
enum vehicleAiSetup_t::death_t::respawnType_t : __int32
{
  NO_RESPAWN = 0x0,
  DO_NOTHING = 0x1,
  RESPAWN_AT_SPAWN_POINT = 0x2,
  RESPAWN_NEAR_DEATHSPOT = 0x3,
};

// IDA Local Type ordinal 2225; PDB kind: enum.
enum vehicleAiSetup_t::triggerAction_t : __int32
{
  TA_CONTINUE_EVALUATING_COMMANDS = 0x0,
  TA_TOGGLE_ACTIVE_STATE = 0x1,
};

// IDA Local Type ordinal 14517; PDB kind: class.
class idVehicleBodyDef
{
public:
  const idCollisionModel *model;
  float density;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  float bouncyness;
};

// IDA Local Type ordinal 15689; PDB kind: struct.
struct __declspec(align(4)) vehicleAiSetup_t::vehicle_t
{
  const idDeclEntityDef *vehicleDef;
  idEntityPtr<idVehicle> vehicleEnt;
  bool useAiOriginAxis;
};

// IDA Local Type ordinal 15690; PDB kind: struct.
struct __declspec(align(2)) vehicleAiSetup_t::dormancy_t
{
  float distance;
  idList<idEntityPtr<idVehicleAI>,5> group;
  bool isDormant;
  bool isAttacking;
  bool isNearPlayer;
};

// IDA Local Type ordinal 15713; PDB kind: struct.
struct vehicleAiSetup_t::patrol_t
{
  const idDeclEntityDef *waypointDef;
  idEntityPtr<idSplineWaypoint> waypoint;
  vehicleAiSetup_t::patrol_t::patrolPath_t pathType;
  float speed;
  bool fleeNearEnemy;
  int iterations;
  float maxRightDistance;
  float nextWaypointDist;
  int curPatrolPoint;
  int curPatrolDir;
  int delayTime;
  int iterationCount;
  bool pathComplete;
  idList<idSplineWaypoint *,5> waypoints;
  idNavSplinePosition goalPosition;
};

// IDA Local Type ordinal 15715; PDB kind: struct.
struct vehicleAiSetup_t::encounter_t
{
  idList<idEntityPtr<idSplineWaypoint>,5> waypoints;
  idList<idEntityPtr<idEntity>,5> team;
};

// IDA Local Type ordinal 15716; PDB kind: struct.
struct vehicleAiSetup_t::engage_t::guardEntity_t
{
  idEntityPtr<idEntity> entity;
  float engageDist;
  float disengageDist;
};

// IDA Local Type ordinal 15718; PDB kind: struct.
struct vehicleAiSetup_t::engage_t::extension_t
{
  idEntityPtr<idEntity> entity;
  float engageDist;
};

// IDA Local Type ordinal 15720; PDB kind: struct.
struct vehicleAiSetup_t::engage_t
{
  idList<vehicleAiSetup_t::engage_t::guardEntity_t,5> guard;
  idList<vehicleAiSetup_t::engage_t::extension_t,5> extension;
  float delay;
  idEntityPtr<idEntity> trigger;
  float alertDistance;
  const idSoundShader *alertSound;
  int alertSoundTime;
};

// IDA Local Type ordinal 15721; PDB kind: struct.
struct vehicleAiSetup_t::attack_t
{
  const idDeclVehicleAttack *decl;
  vehicleAttackParams_t params;
};

// IDA Local Type ordinal 15723; PDB kind: struct.
struct vehicleAiSetup_t::attackInfo_t
{
  bool freeForm;
  idList<vehicleAiSetup_t::attack_t,5> types;
};

// IDA Local Type ordinal 15724; PDB kind: struct.
struct vehicleAiSetup_t::difficultyLevel_t
{
  vehicleAiSetup_t::difficultyLevel_t::difficulty_t level;
  float attackScale;
  float damageScale;
  float speedRate;
  float accuracy;
  float damageTakenScale;
};

// IDA Local Type ordinal 15725; PDB kind: struct.
struct vehicleAiSetup_t::death_t
{
  vehicleAiSetup_t::death_t::respawnType_t respawnType;
  bool killWhenStuck;
  bool respawnInBackground;
  float minBackgroundDistance;
  float minBackgroundViewDistance;
  bool clearEnemyTracker;
  float minRespawnTime;
  float maxRespawnTime;
  int numRespawns;
  float waveMinDelayTime;
  float waveMaxDelayTime;
  int numWaves;
  idEntityPtr<idEntity> trigger;
  int triggerMilliSec;
  idEntityPtr<idEntity> triggerAfterWave;
  int triggerAfterWaveMilliSec;
  int respawns;
};

// IDA Local Type ordinal 15726; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::occupants_t
{
  idEntityPtr<idEntity> entity;
  bool waitForPlayer;
  bool lockInSeat;
  const idDeclVoiceOver *voiceOver;
  float delayTime;
  float repeatDelayTime;
};

// IDA Local Type ordinal 15728; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::travel_t
{
  idEntityPtr<idSplineWaypoint> waypoint;
  float normalSpeed;
  float attackSpeed;
  int iterations;
  float nextWaypointDist;
  float maxRightFrac;
  bool shootAtEnemy;
  float goalSpeed;
};

// IDA Local Type ordinal 15729; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::trigger_t
{
  idEntityPtr<idEntity> triggerEntity;
  int triggerTime;
};

// IDA Local Type ordinal 15730; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::toTrigger_t
{
  idEntityPtr<idEntity> toTriggerEntity;
  int occupantToActivate;
};

// IDA Local Type ordinal 15731; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::pauseState_t
{
  bool decision;
  bool attack;
  bool movement;
};

// IDA Local Type ordinal 15732; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::setState_t
{
  vehicleDecision_t decision;
  vehicleAttack_t attack;
};

// IDA Local Type ordinal 15733; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::enterVehicle_t
{
  idEntityPtr<idEntity> entitysVehicle;
  idEntityPtr<idEntity> vehicle;
  vehicleSeat_t seat;
};

// IDA Local Type ordinal 15734; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::wait_t
{
  float time;
};

// IDA Local Type ordinal 15735; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::waitForSound_t
{
  const idSoundShader *sound;
};

// IDA Local Type ordinal 15736; PDB kind: struct.
struct __declspec(align(4)) vehicleAiSetup_t::commands_t::waitForVoiceOver_t
{
  const idDeclVoiceOver *voiceOver;
  bool waitOnVoiceOver;
};

// IDA Local Type ordinal 15738; PDB kind: struct.
struct __declspec(align(4)) vehicleAiSetup_t::commands_t::exitVehicle_t
{
  bool unlockOccupants;
  idEntityPtr<idInfoPath> infoPath;
  idEntityPtr<idEntity> triggerEntityExit;
  bool removeVehicleWhenEmpty;
};

// IDA Local Type ordinal 15739; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::powerSlide_t
{
  int wheelDir;
  float impulse;
};

// IDA Local Type ordinal 15740; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::waitTilDead_t
{
  idList<idEntityPtr<idEntity>,5> deadList;
};

// IDA Local Type ordinal 15741; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::waitForPlayer_t
{
  float distance;
};

// IDA Local Type ordinal 15742; PDB kind: struct.
struct vehicleAiSetup_t::commands_t::travelTilDead_t
{
  idEntityPtr<idSplineWaypoint> waypoint;
  float normalSpeed;
  float attackSpeed;
  idList<idEntityPtr<idEntity>,5> deadList;
  float goalSpeed;
};

// IDA Local Type ordinal 15743; PDB kind: struct.
struct vehicleAiSetup_t::commands_t
{
  vehicleAiSetup_t::cmdName_t type;
  idList<vehicleAiSetup_t::commands_t::occupants_t,5> occupants;
  vehicleAiSetup_t::commands_t::travel_t travel;
  vehicleAiSetup_t::commands_t::trigger_t trigger;
  vehicleAiSetup_t::commands_t::toTrigger_t toTrigger;
  vehicleAiSetup_t::commands_t::pauseState_t pauseState;
  vehicleAiSetup_t::commands_t::setState_t changeState;
  vehicleAiSetup_t::commands_t::enterVehicle_t enterVehicle;
  vehicleAiSetup_t::commands_t::wait_t wait;
  vehicleAiSetup_t::commands_t::waitForSound_t waitForSound;
  vehicleAiSetup_t::commands_t::waitForVoiceOver_t waitForVoiceOver;
  vehicleAiSetup_t::commands_t::exitVehicle_t exitVehicle;
  vehicleAiSetup_t::commands_t::powerSlide_t powerSlide;
  vehicleAiSetup_t::commands_t::waitTilDead_t waitTilDead;
  vehicleAiSetup_t::commands_t::waitForPlayer_t waitForPlayer;
  vehicleAiSetup_t::commands_t::travelTilDead_t travelTilDead;
  vehicleAiSetup_t::triggerAction_t triggerAction;
};

// IDA Local Type ordinal 15745; PDB kind: struct.
struct vehicleAiSetup_t::aiAudio_t
{
  idList<idSoundShader const *,5> sounds;
  float minDelay;
  float maxDelay;
  int nextPlayTime;
};

// IDA Local Type ordinal 15746; PDB kind: struct.
struct vehicleAiSetup_t::conditionalAudio_t
{
  vehicleAiSetup_t::aiAudio_t afterKills;
  int lastKillCount;
  vehicleAiSetup_t::aiAudio_t duringFireFight;
  vehicleAiSetup_t::aiAudio_t takingDamage;
  vehicleAiSetup_t::aiAudio_t lowHealth;
};

// IDA Local Type ordinal 15747; PDB kind: struct.
struct vehicleAiSetup_t
{
  bool takesDamage;
  vehicleDecision_t decisionState;
  idEntityPtr<idSplineWaypoint> secondaryAmbushPos;
  idStr debugState;
  vaiControl_t control;
  vehicleAiSetup_t::vehicle_t controlVehicle;
  float health;
  bool infiniteAmmo;
  bool infiniteQuickUse;
  idEntityPtr<idNavSplinePath> initialPath;
  bool guardInitialPath;
  bool allowSplineJumping;
  bool allowSlideTurn;
  bool boostAltersVelocity;
  bool ghostCollision;
  bool canRunAway;
  bool turnaroundTowardsMiddle;
  int vehicleRating;
  float narrowPathDistance;
  int predatorHealthRegen;
  float passThroughGoalDist;
  vehicleAiSetup_t::dormancy_t dormancy;
  vehicleAiSetup_t::patrol_t patrol;
  vehicleAiSetup_t::encounter_t encounter;
  vehicleAiSetup_t::engage_t engage;
  int groupNumber;
  vehicleAiSetup_t::attackInfo_t attack;
  idList<idEntityPtr<idEntity>,5> specificEnemyList;
  bool forcePlayerEnemy;
  vehicleAiSetup_t::difficultyLevel_t difficultyLevel;
  vehicleAiSetup_t::death_t death;
  idFaction faction;
  idList<vehicleAiSetup_t::commands_t,5> commands;
  vehicleAiSetup_t::conditionalAudio_t conditionalAudio;
};

// IDA Local Type ordinal 17514; PDB kind: class.
class idVehicleUpgrade : public idInventoryItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17515.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleUpgrade();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(const idDeclInventory *);
  virtual void Merge(idPresentable *, idInventoryCollection *, const idDeclInventory *);
  virtual void Hide();
  virtual void Show();
  virtual void OnEquip(const idPresentable *, idFXManager *);
  virtual void OnUnequip(const idPresentable *, idFXManager *);
  virtual void OnClone(const idInventoryItem *);
  virtual int GetCount();
  virtual bool CanUse(idActor *);
  virtual bool Use(idActor *);
  virtual bool CanUseInVehicle(idActor *);
  virtual bool ClientUse(idPresentablePlayer *);
  virtual void Serialize(idSerializer *, idInventoryCollection *);
  virtual void SerializeNonPrediction(idSerializer *, idInventoryCollection *);
  virtual void ClientUpdate();
  virtual void GetPickupHudInfo(const idEntity *, idPickupHudInfo *);

  bool newUpgrade;
  float damage;
};
