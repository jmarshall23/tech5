#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// Recovered logical types: 18
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1179; PDB kind: enum.
enum idPresentablePlayer::idPlayerExplicitMotion_t::explicitMoveType_t : __int32
{
  EXPLICIT_MOVE_NONE = 0x0,
  EXPLICIT_MOVE_SINGLE_EXCLUSIVE = 0x1,
  EXPLICIT_MOVE_SINGLE_ADDITIONAL = 0x2,
};

// IDA Local Type ordinal 1206; PDB kind: enum.
enum idPresentablePlayer::playerGuis_t : __int32
{
  GUI_DELIVERY = 0x0,
  GUI_JOBOFFER = 0x1,
  GUI_JOBBOARD = 0x2,
  GUI_MERCHANT = 0x3,
  GUI_CLOTHING = 0x4,
  GUI_RACES = 0x5,
  GUI_JOB_DEBUG = 0x6,
  GUI_PLAYTEST_DEBUG = 0x7,
  GUI_GENERAL_GAME_USE = 0x8,
  GUI_PLAYERGARAGE = 0x9,
  GUI_TUNE_VEHICLE = 0xA,
  GUI_TUNER_VEHICLE = 0xB,
  GUI_INFO_BIG_NO_PIC = 0xC,
  GUI_INFO_SMALL = 0xD,
  GUI_INITIAL_ACTIVATE = 0xE,
  GUI_SUBTITLE = 0xF,
  GUI_INVENTORY = 0x10,
  GUI_SIDEMISSION = 0x11,
  GUI_VIEWNOTE = 0x12,
  GUI_TOWTRUCK = 0x13,
  GUI_TUTORIAL = 0x14,
};

// IDA Local Type ordinal 2131; PDB kind: enum.
enum idPresentablePlayer::additiveBlendType_t : __int32
{
  ADDITIVE_VIEW_ANGLE_BLEND_FULL_OUT = 0x0,
  ADDITIVE_VIEW_ANGLE_BLEND_IN = 0x1,
  ADDITIVE_VIEW_ANGLE_BLEND_OUT = 0x2,
  ADDITIVE_VIEW_ANGLE_BLEND_FULL_IN = 0x3,
};

// IDA Local Type ordinal 14754; PDB kind: class.
class __declspec(align(16)) idPresentablePlayer : public idPresentableActor
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34013.
  virtual ~idPresentablePlayer();
  virtual void Shutdown();
  virtual void ClientJobSync();
  virtual void ControlReleased();
  virtual inputSettings_t *GetInputSettings(inputSettings_t *result, idPresentablePlayer *);
  virtual void Present();
  virtual void Serialize(idSerializer *);
  virtual void PostSerializeRead(bool);
  virtual void Interpolate(int, float);
  virtual bool ShouldSerializeHidden();
  virtual bool ShouldInterpolate();
  virtual void ClientPredict(int, float);
  virtual void ClientThink(int, float, bool);
  virtual void ServerThink(int);
  virtual bool Draw(idPresentablePlayer *);
  virtual void SerializeFX(idSerializer *);
  virtual void PostAlloc();
  virtual presentableType_t GetType();
  virtual idPresentableAnimatedEntity *GetAnimatedEntityInterface();
  virtual idPresentableVehicle *GetVehicleInterface();
  virtual idPresentableBreakable *GetBreakableInterface();
  virtual idPresentablePieceEmitter *GetPieceEmitterInterface();
  virtual idPresentableDamageable *GetDamageableInterface();
  virtual const idPresentableActor *GetActorInterface();
  virtual idPresentableActor *GetActorInterface_2();
  virtual const idPresentablePlayer *GetPlayerInterface();
  virtual idPresentablePlayer *GetPlayerInterface_2();
  virtual idPresentableProjectile *GetProjectileInterface();
  virtual idPresentableProjectile_Rocket *GetProjectileRocketInterface();
  virtual idPresentableProjectile_Homing *GetProjectileHomingInterface();
  virtual idPresentableProjectile_Grenade *GetProjectileGrenadeInterface();
  virtual idPresentableMultiplayerTrigger *GetMultiplayerTriggerInterface();
  virtual idPresentableWeaponStatic *GetWeaponStaticInterface();
  virtual idPresentableAI *GetAIInterface();
  virtual idPresentableProp *GetPropInterface();
  virtual idPresentableDoorAnimated *GetDoorAnimatedInterface();
  virtual idPresentableWeapon *GetWeaponInterface();
  virtual idOnlineVehicleDeathCameraPresentable *GetVehicleCameraInterface();
  virtual idPresentableReviveCamera *GetReviveCameraInterface();
  virtual idPresentableArmorPiece *GetArmorInterface();
  virtual idPresentablePusher *GetPusherInterface();
  virtual idPresentableTurret *GetTurretInterface();
  virtual idPresentableParticleEmitter *GetParticleEmitterInterface();
  virtual idPresentableCollisionTrigger *GetCollisionTriggerInterface();
  virtual idPresentableSpectatorCamera *GetSpectatorCameraInterface();
  virtual idPresentableAnimatedEntity *GetAnimatedPhysicsInterface();
  virtual void SetRenderModel(idRenderModel *, bool);
  virtual bool ShouldSerializeRenderModelParms();
  virtual void StopSound_Predicted(const soundChannel_t);
  virtual void Hide(bool);
  virtual void Show();
  virtual void GetWorldTransform(idVec3 *, idMat3 *);
  virtual idBounds *GetBounds(idBounds *result, int);
  virtual idBounds *GetAbsBounds(idBounds *result, int);
  virtual bool ShouldTriggerClientHitScanHit();
  virtual void ClientHitScanHit(int, int, int, const idDeclWeapon *, const idDeclProjectile *, int);
  virtual void ClientHitScanHit_ClientFire(int, const idDeclWeapon *, int);
  virtual void PredictHitScanHit(idPresentable *, float, const idVec3 *, const idVec3 *, const idDeclProjectile *, trace_t *);
  virtual int GetPeerIndex();
  virtual bool IsTargetLockable(const idDeclAmmo *);
  virtual float GetTotalCurHealth();
  virtual float GetTotalMaxHealth();
  virtual bool ShouldSaveForTimeTrial();
  virtual void StartFX(fxCondition_t, fxExtraCondition_t);
  virtual void StopAllFX();
  virtual void UpdateFX(const idVec3 *, const idMat3 *, idFXManager *, const float, const float);
  virtual void UpdateFX_2(const idVec3 *, const idMat3 *);
  virtual void UpdateFX_3(const float, const float);
  virtual void LocalStartFX(fxCondition_t);
  virtual usableState_t GetOnlineUsableState(idPresentablePlayer *, int);
  virtual void GetOnlineModifiedCrosshairInfo(const idPresentable *, const idFocusTrace *, const usableState_t, idCrosshairInfo *);
  virtual idStrId *GetOnlineUsableText(idStrId *result);
  virtual void BecomeReplicated();
  virtual int GetControllingPlayerIndex();
  virtual idPresentablePlayer *GetControllingPlayer();
  virtual bool IsLocallyControlled();
  virtual idWeapon *GetFiredWeapon(const idDeclWeapon *);
  virtual void InitFXMgr(const idDeclFX *);
  virtual void ShutdownFXMgr();
  virtual void UpdateClientCollision(const idVec3 *, const idMat3 *, const idVec3 *, const idMat3 *);
  virtual bool ShouldLinkPresentableCollision();
  virtual idInventoryCollection *GetInventory();
  virtual const idInventoryCollection *GetInventory_2();
  virtual bool ShouldEnableSphereCollision();
  virtual void InventoryAdded(idInventoryItem *, int, bool);
  virtual idWeapon *GetEquippedWeapon();
  virtual idWeapon *GetEquippedWeapon(const equipSlot_t);
  virtual void OnDamage(idEntity *, idEntity *, const idDeclDamage *);
  virtual bool IsDead();
  virtual const idActorModifierManager *GetActorModifierManager();
  virtual idActorModifierManager *GetActorModifierManager();
  virtual void HandleActorModifierMessage(unsigned int, unsigned __int8);
  virtual float GetSpeedScale();
  virtual float GetDamageScale();
  virtual bool IsOverdriveDisabled();
  virtual void HudThink();
  virtual void UpdateSerializedView();
  virtual unsigned __int8 GetPeerMaskForPrediction();
  virtual int StartSoundShader_Predicted(const soundChannel_t, const idSoundShader *, int);

  idPresentablePlayer::damageDealtFeedbackItem_t damageDealtBuffer[4];
  int damageDealtBufferIndex;
  int lastDamageDealtBufferIndex;
  idPresentablePlayer::coopCalloutItem_t calloutHistory[4];
  int calloutHistoryIndex;
  int lastCalloutHistoryIndex;
  idPresentablePlayer::coopScoreItem_t coopScoreHistory[4];
  int coopScoringIndex;
  int lastCoopScoringIndex;
  bool renderLegendTitle;
  idStrId coopLegendTitle;
  idStaticList<idPresentablePlayer::screenParticleState_t,5> screenPrtState;
  idPresentablePlayer::screenParticleState_t fxScreenPrtState[4];
  idPresentablePtr<idPresentableProjectile> uniqueTrackedProjectile;
  int uniqueTrackedProjectileClientGameFrameWhenFired;
  idPresentablePlayer::idPlayerCameraShake cameraShake;
  bool stepUpSpringCrouchState;
  idSpring<idVec1> stepUpViewSpring;
  idSpring<idVec1> stepUpHandsSpring;
  float leanRoll;
  idPresentablePlayer::idPlayerExplicitMotion_t explicitMotion;
  const idDeclPlayerProps *playerProps;
  int clientPlayerInputFrame;
  int serverOverridePositionTime;
  idView view;
  idAngles localMinViewAngles;
  idAngles localMaxViewAngles;
  localView_t localView;
  idPlayerViewCallbacks *viewCallbacks;
  clientFireInfo_t clientFire;
  int throwCount;
  idInventoryCollection predictedInventory;
  idInventoryCollection *activeInventory;
  bool physicsInitialized;
  bool firstPredictionSerialize;
  playerPState_t serializedState;
  idPresentablePlayer::moveBufferItem_t moveBuffer[64];
  int lastRecordedMoveBufferIndex;
  idPresentablePlayer::damageFeedbackBufferItem_t damageFeedback[10];
  int damageFeedbackBufferPos;
  int serializeDamageFeedbackCount;
  idPresentablePlayer::attackerInfo_t attackerInfo[3];
  idList<idPresentablePtr<idPresentable>,5> controlledPresentables;
  int wrongWeapons;
  int wrongAmmo;
  idEntityInfluenceTrail influence;
  idPlayerHud playerHud;
  idHudInfo hudInfo;
  unsigned __int8 serializedHudInfoBuffer[444];
  bool ignoreTutorialPause;
  bool ignoreTowTruckPause;
  idPhysics_Player physicsObj;
  idHands hands;
  idBobCycle bobCycle;
  idUCmdTracker ucmdTracker1;
  idUCmdTracker ucmdTracker2;
  idUCmdInhibit::inhibitFlags_t inhibitFlags;
  idVec3 firstPersonViewOrigin;
  idMat3 firstPersonViewAxis;
  idVec3 serializedViewOrigin;
  idMat3 serializedviewAxis;
  idVec3 originError;
  float deferredOriginOffsetZ;
  float lastFov;
  idInterpolate<float> zoomFov;
  bool wantZoom;
  idEntityPtr<idEntity> missionPin;
  idEntityPtr<idEntity> controlledEntity;
  idWeaponKick weaponKick[5];
  float savedViewPitchForKick;
  idAngles addViewAngles;
  idVec3 addViweOffset;
  int addViewAnglDoneAtTime;
  idPresentablePlayer::additiveBlendType_t addViewAnglBlendState;
  idInterpolate<float> baseWeaponSpread;
  idInterpolate<float> kickWeaponSpread;
  idQuat perfectOriginRotation;
  int perfectOriginDuration;
  int perfectOriginStartTime;
  __int8 hasOddball : 1;
  __int8 hasQuad : 1;
  __int8 incapacitated : 1;
  __int8 spectating : 1;
  __int8 inhibited : 1;
  __int8 noClip : 1;
  __int8 zoomedIn : 1;
  __int8 isDead : 1;
  __int8 restrictedGamePlayCanRun : 1;
  __int8 restrictedGamePlay : 1;
  __int8 perfectMovement : 1;
  __int8 inhibitFireControl : 1;
  __int8 isAFK : 1;
  __int8 showDeadBody : 1;
  __int8 canRespawn : 1;
  __int8 isBully : 1;
  unsigned __int8 : 4;
  __int8 forceIgnoreLanding : 1;
  __int8 forceSoftLanding : 1;
  __int8 inhibitChangeWeapon : 1;
  __int8 inhibitRaiseWeapon : 1;
  int disableLandingResultsFrames;
  const idDeclAmmo *pendingAmmo;
  int pendingQuickWeapon;
  bool useIntroBringUp;
  int nextAmmoChangeTime;
  int nextWeaponChangeTime;
  int weaponButtonPressTime;
  int ammoButtonPressTime;
  int inhibitFireControlStartTime;
  idWeapon::weaponState_t weaponFiremodeAnimStateRight;
  idWeapon::weaponState_t weaponFiremodeAnimStateLeft;
  int lastWeaponSlotRight;
  int lastWeaponSlotLeft;
  burstMode_t lastBurstModeRight;
  burstMode_t lastBurstModeLeft;
  idLaserCutter::functionalityLens_t lastFunctionalityLens;
  float staminaCharge;
  int previousStaminaCharge;
  float staminaPercent;
  float staminaStopTime;
  float staminaStartTime;
  bool requireSprintButtonrelease;
  bool isSprinting;
  bool wasSprinting;
  bool inInteractionView;
  bool isTurretControl;
  int respawnCount;
  decayParams_s standDecay;
  decayParams_s crouchDecay;
  idFocusTracker_Player focusTracker;
  idEnvironmentAnalyzer environmentAnalyzer;
  netBoolEvent_t killed;
  netBoolEvent_t respawn;
  netBoolEvent_t teleported;
  netBoolEvent_t vehicleExited;
  int pain_debounce_time;
  int nextBeatTime;
  float breath_sprintScale;
  bool heartBeatLub;
  bool playDamagedBreathing;
  const idDeclTutorialEvent *currentTutorialGuiDecl;
  idPresentablePlayer::deathMessage_t deathInfo;
  idSubtitleSequencer subtitleSequencer;
  int subtitleStartTime;
  idRenderModelAugmentOutline *outlineModel;
  idAimAssist aimAssist;
  idSWF *loadedGuis[21];
  idStr guiNames[21];
  bool purgableGuis[21];
  bool challengeLeavingSoon;
  bool challengeRestartingSoon;
  bool challengeLocalRestart;
  bool challengeRemoteRestart;
  int challengeEndTime;
  float lastDecalValue;
  bool wasPaused;
  idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5> postGameItems;
  int roverBombSoundCounter;
  int localRoverBombSoundCounter;
  bool disableSubtitles;
  idPresentablePlayer::idSWFScriptFunction_goToMission scriptFunction_goToMission;
  idPresentablePlayer::idSWFScriptFunction_resumeMap scriptFunction_resumeMap;
  int quickUseFailedTime;
  bool sentOfficialSnap;
  bool quickSelectUsed;
  bool isGeneralGuiCardGame;
};

// IDA Local Type ordinal 15305; PDB kind: struct.
struct idPresentablePlayer::damageDealtFeedbackItem_t
{
  idPresentablePtr<idPresentable> victim;
};

// IDA Local Type ordinal 15308; PDB kind: struct.
struct idPresentablePlayer::coopCalloutItem_t
{
  const idDeclOnlineScoringCallout *callout;
  int scoreIndex;
};

// IDA Local Type ordinal 15309; PDB kind: struct.
struct idPresentablePlayer::coopScoreItem_t
{
  idVec3 worldPosition;
  int score;
  int time;
  int index;
};

// IDA Local Type ordinal 15310; PDB kind: struct.
struct __declspec(align(4)) idPresentablePlayer::screenParticleState_t
{
  idRenderModel *pModel;
  float excludeAngle;
  int fadeStartTime;
  int fadeEndTime;
  bool isActive;
};

// IDA Local Type ordinal 15313; PDB kind: struct.
struct idPresentablePlayer::idPlayerCameraShake
{
  bool active;
  float startTime;
  float scale;
  float decay;
};

// IDA Local Type ordinal 15315; PDB kind: struct.
struct idPresentablePlayer::idPlayerExplicitMotion_t
{
  idVec3 right;
  idVec3 up;
  idVec3 forward;
  idVec3 lastPos;
  idPresentablePlayer::idPlayerExplicitMotion_t::explicitMoveType_t moveType;
  playerExplicitMove_t singleMove;
  playerExplicitMove_t singleMove2;
};

// IDA Local Type ordinal 15333; PDB kind: struct.
struct __declspec(align(4)) idPresentablePlayer::moveBufferItem_t
{
  usercmd_t prevCmd;
  usercmd_t curCmd;
  idAngles viewAngles;
  int startTime;
  int endTime;
  idVec3 origin;
  float speed;
  unsigned __int8 predictionBits;
};

// IDA Local Type ordinal 15334; PDB kind: struct.
struct idPresentablePlayer::damageFeedbackBufferItem_t
{
  float damage;
  const idDeclDamage *damageDef;
  idPresentablePtr<idPresentable> attacker;
  idVec3 impactPoint;
  idVec3 impactDir;
  idVec3 impactKick;
  int impactOverrideTimer;
};

// IDA Local Type ordinal 15335; PDB kind: struct.
struct idPresentablePlayer::attackerInfo_t
{
  idPresentablePtr<idPresentable> attacker;
  float damageDone;
  float spikeDamage;
};

// IDA Local Type ordinal 15384; PDB kind: struct.
struct __declspec(align(4)) idPresentablePlayer::deathMessage_t
{
  idStr attacker;
  idStr attackerEmblem;
  const idDeclDamage *damageDef;
  bool isKilledByPlayer;
  bool isTeamKill;
  bool isSuicide;
  bool hasQuad;
  bool show;
};

// IDA Local Type ordinal 15402; PDB kind: class.
class idPresentablePlayer::idSWFScriptFunction_goToMission : public idSWFScriptFunction_Nested<idPresentablePlayer>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15403.
  virtual ~idSWFScriptFunction_goToMission();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 15404; PDB kind: class.
class idPresentablePlayer::idSWFScriptFunction_resumeMap : public idSWFScriptFunction_Nested<idPresentablePlayer>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15405.
  virtual ~idSWFScriptFunction_resumeMap();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 20310; PDB kind: class.
class idPresentablePlayer::ShowTutorialGui::__l32::idSWFScriptFunction_waitInput : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20311.
  virtual ~idSWFScriptFunction_waitInput();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  const idDeclTutorialEvent *decl;
  idSWF *gui;
  idEntity *activatingEntity;
  idPlayer *player;
  idStr actionCheck;
};

// IDA Local Type ordinal 20312; PDB kind: class.
class idPresentablePlayer::ShowTutorialGui::__l31::idSWFScriptFunction_DeactivateCallback : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20313.
  virtual ~idSWFScriptFunction_DeactivateCallback();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
  idEntity *activatingEntity;
  idPlayer *player;
  const idDeclTutorialEvent *decl;
};
