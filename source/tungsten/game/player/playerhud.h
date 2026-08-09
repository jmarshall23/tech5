#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\playerhud.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1198; PDB kind: enum.
enum idPlayerHud::hudState_t : __int32
{
  HUDSTATE_NONE = 0x0,
  HUDSTATE_BALOON = 0x1,
  HUDSTATE_DAMAGE = 0x2,
  HUDSTATE_DAMAGE_HEALTH = 0x3,
  HUDSTATE_INFO = 0x4,
  HUDSTATE_ALL = 0x5,
};

// IDA Local Type ordinal 15336; PDB kind: struct.
struct idPlayerHud::updateJobInfo_t
{
  const idDeclJob *jobDecl;
  int requiredNum;
  bool playSound;
  bool treatAsSameStatusUpdate;
  bool fakeJob;
  idStrId fakeJobName;
  idStrId fakeJobObj;
};

// IDA Local Type ordinal 15341; PDB kind: struct.
struct idPlayerHud::clusterTarget_t
{
  idEntityPtr<idEntity> target;
  bool locked;
  int aquirePulse;
  int aquireTime;
  int startLock;
  int lockTime;
};

// IDA Local Type ordinal 15344; PDB kind: class.
class __declspec(align(4)) idPlayerHud
{
public:
  float combatCalmDownTime;
  int driverNum;
  bool showCrosshair;
  bool ignoreJobUpdates;
  bool ignorePickupUpdates;
  int activateCombatTime;
  idList<idPlayerHud::updateJobInfo_t,5> jobUpdateQueue;
  idJob *currentJob;
  bool fakeJobCurrentJob;
  bool currentJobPlaySound;
  bool currentJobTreatUpdateAsSameStatus;
  idJob *dynamicJob;
  bool dynamicJobPlaySound;
  bool dynamicJobTreatUpdateAsSameStatus;
  idList<idPlayerHud::updateJobInfo_t,5> dynamicJobUpdateQueue;
  int currentRequirement;
  int jobStartShowTime;
  int defaultJobShowTime;
  int completedJobShowTime;
  int acceptedJobShowTime;
  idPlayerHud::hudState_t hudState;
  idPlayerHud::hudState_t tempHudState;
  bool allowWeaponChange;
  bool allowDossier;
  idList<idHudPickupInfo,5> pickupList;
  idPlayer *player;
  idPresentablePlayer *presPlayer;
  idEntityPtr<idEntity> rocketTarget;
  idList<idEntityPtr<idEntity>,5> hudWatchTargets;
  idStaticList<idEntityPtr<idEntity>,3> combinerTargets;
  idVec3 damageOrigin;
  int damageImpulseTime;
  int pickupSwitchTime;
  bool pickupUpdate;
  bool canRemovePickup;
  bool mainMenuActive;
  idList<idPlayerHud::clusterTarget_t,5> clusterTargets;
  bool gameInhibited;
  bool playerChangeWeapon;
  bool prevChangeVisible;
  idRenderModel *guiModel;
  idVec2 guiModelLoc;
  bool forceScoreboard;
  int quickMenuIndex;
  int quickScrollWait;
  int quickMenuOffset;
  bool crosshairUsed;
  int msDelayHudUpdate;
  idEntityPtr<idEntity> minigameEntity;
  bool newMinigame;
  idHudHelpInfo helpInfo;
  bool showBottomBar;
  bool restrictedGameplay;
};
