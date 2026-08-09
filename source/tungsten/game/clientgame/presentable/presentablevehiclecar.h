#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\presentable\presentablevehiclecar.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2120; PDB kind: unknown.
enum idPresentableVehicle::<unnamed_tag> : __int32
{
  RBS_NONE = 0x0,
  RBS_PULLED = 0x1,
  RBS_RELEASED = 0x2,
  RBS_BOOSTING = 0x3,
};

// IDA Local Type ordinal 2124; PDB kind: enum.
enum idPresentableVehicle::autoRollState_t : __int32
{
  AUTOROLL_NONE = 0x0,
  AUTOROLL_PITCH = 0x1,
  AUTOROLL_ROLL = 0x2,
};

// IDA Local Type ordinal 2127; PDB kind: enum.
enum idPresentableVehicle::wheelLoc_t : __int32
{
  WHEEL_FRONT_LEFT = 0x0,
  WHEEL_FRONT_RIGHT = 0x1,
  WHEEL_REAR_LEFT = 0x2,
  WHEEL_REAR_RIGHT = 0x3,
};

// IDA Local Type ordinal 14505; PDB kind: class.
class __declspec(align(4)) idPresentableVehicle : public idPresentableAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34019.
  virtual ~idPresentableVehicle();
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
  virtual idImpactManager *GetImpactMgrPtr();
  virtual int StartSoundShader(const soundChannel_t, const idSoundShader *, int, unsigned __int8);
  virtual int StartSoundShader_Predicted(const soundChannel_t, const idSoundShader *, int);
  virtual float GetHealth();

  idStaticList<idPresentableVehicle::clientDetachable_t,70> detachableItems;
  idAnimator_VehicleCar *animator;
  const idDeclVehicleProps *vehicleProps;
  bool showExhaust;
  idVec3 lastOrigin;
  idSmokeEmitter exhaustEmitter_right;
  idSmokeEmitter exhaustEmitter_left;
  idSmokeEmitter exhaustEmitter_right2;
  idSmokeEmitter exhaustEmitter_left2;
  idVec3 originalOrigin;
  idVec3 originalSmoothOrigin;
  idMat3 originalSmoothAxis;
  int radialBlurHandle;
  int ammoDepletedMsgTime;
  bool enableVehicleControls;
  bool engineRunning;
  bool accelerating;
  bool reversing;
  bool boosting;
  bool canAccelerate;
  bool braking;
  bool handBraking;
  bool aiSpecialSkid;
  float currentThrottle;
  float maxSpeed;
  int currentGear;
  float currentAproxMPH;
  float currentEngineRPM;
  float totalWheelSkid;
  int savedSurfaceType;
  idVec3 currentAproxLinearVelocity;
  int numAnimWheelsOnGround;
  float averageCompression;
  int rampLandTime;
  idPresentableVehicle::soundState_t soundState;
  idEffectPhysicsDebrisEmitter debrisEmitter;
  idImpactManager impactManager;
  int serializedPhysicsSize;
  unsigned __int8 serializedPhysics[2048];
  int respawnFrame;
  int lastRespawnFrame;
  int serverOverridePositionTime;
  bool firstClientOverride;
  bool postSerializeRespawn;
  int specialDeathTime;
  bool appliedSpecialDeath;
  idPresentablePtr<idPresentablePlayer> cachedPlayerDriver;
  idInventoryCollection inventory;
  idInventoryCollection *activeInventory;
  idList<vehicleOccupant_t,5> occupants;
  idList<idWheel,5> wheels;
  const idSoundShader *vehicleHorn;
  idPhysics_AF physicsObj;
  const idDeclTable *motorTorque;
  vehicleStickControl_t stickControl;
  float curSteerAngle;
  float maxSteerSpeed;
  float brakeForce;
  idAngles driverViewAngles;
  bool mainCameraView;
  idAngles currentViewAngles;
  idAngles minDriverViewAngles;
  idAngles maxDriverViewAngles;
  idAngles lastCarAngles;
  int lastDrawTime;
  float zoom_fov_x;
  int wildSpinTime;
  int jumpStartTime;
  float jumpApogee;
  float jumpHeightOffset;
  float jumpBackOffset;
  idAngles freeAngles;
  bool quickTurnActive;
  bool quickUseFailed;
  bool quickSelectUsed;
  int quickTurnStartTime;
  int quickTurnTotalTime;
  int quickTurnDir;
  float viewAnglesDeltaPerc;
  float prevCameraPitch;
  float prevCameraPushDelta;
  idAngles mouseCumulativeFreeAngles;
  float mouseCumulativePitch;
  idMat3 activeTargetAxis;
  idVec3 currentCameraFocusOffset;
  idVec3 currentViewOrigin;
  bool activeTargetUpright;
  float cameraTraceZs[10];
  int cameraTraceZIndex;
  bool cameraZInitialized;
  int boostStartTime;
  int reverseBoostTime;
  int reverseBoostState;
  float boostScalePercent;
  int externalBoostStart;
  int externalBoostEnd;
  int externalBoostDuration;
  idPresentableVehicle::boostFx_t boostFx;
  int numWheelsOnGround;
  idVec3 driverViewOrigin;
  idMat3 driverViewAxis;
  float driverViewFov_x;
  int jumpTime;
  int lastSlideTime;
  bool playedFullBoostSound;
  bool boostDisabled;
  idInterpolate<float> boostPower;
  float megaBoostAcceleration;
  int megaBoostTime;
  bool slideFxPlaying;
  int forceBoostFxTime;
  bool hasQuad;
  float currentMPH;
  int nextBoostCharge;
  float boostDuration;
  int lastHandbrakeTime;
  int handbrakeStartTime;
  int nextSteerTime;
  float currentMaxSpeed;
  float currentMaxReverseSpeed;
  idStaticList<idVehicleQuickItem *,6> quickItemThink;
  int curQuickItem;
  int curQuickItemSlot;
  idPresentableVehicle::onlinePerks_t currentPerks;
  int currentWeaponGroup;
  int clientPendingWeaponGroup;
  int clientPendingWeaponChangeFirecount;
  int weaponControlIndex;
  bool hadAmmo;
  bool weaponTriggerPulled;
  bool lastWeaponTriggerPulled;
  bool lastHadAmmo;
  bool inhibitFireControl;
  int inhibitFireControlStartTime;
  const idVehicleWeapon *lastFiredVehicleWeapon;
  idThirdPersonCrosshair crosshair;
  idList<idVehicleWeapon *,5> weapons;
  mannedWeaponTransition_t weapTransState;
  int seatTransitionTime;
  idVec3 transitionFromOrigin;
  idMat3 transitionFromAxis;
  idVec3 lastWeaponOrigin;
  idMat3 lastWeaponViewAxis;
  idVec3 lastViewOrigin;
  idMat3 lastViewAxis;
  bool sharedWeaponChange;
  int mannedWeaponChangeTime;
  float attackDamageScale;
  bool canFireWeapons;
  idFXManager predictedFXMgr;
  float boostShake;
  bool drawBirdsView;
  int zoomTime;
  idPresentableVehicle::vehicleDamageInfo_t damageHistory[8];
  int damageHistoryIndex;
  int damageHistoryLastSerialize;
  int predictedDamageCount;
  bool newPassenger;
  idAngles lastFPSStickAngles;
  idVec3 lastPassengerViewOrg;
  idMat3 lastPassengerViewAxis;
  idVec3 birdOrigin;
  int birdObstructedCamTime;
  bool allowWeaponChange_Serialized;
  float health_Serialized;
  float maxHealth_Serialized;
  bool hasInfiniteAmmo_Serialized;
  idPresentablePtr<idPresentable> lockedTarget_Serialized;
  idPhysicsCallbacks *clientPhysicsCB;
  collisionInfo_t lastCollision;
  idVec3 lastLinearVelocity;
  idVec3 lastAngularVelocity;
  int stuckFrames;
  int collisionTime;
  int backImpulseTime;
  int debrisTime;
  int violentRollStartTime;
  int violentRollStopTime;
  int violentRollFxTime;
  int rolloverFxTime;
  vehicleFxDamageLevel_t currentFXDamageLevel;
  int deathTime;
  float lastBoostPower;
  bool engineDisabled;
  bool hasBoosted;
  int lastTargetRenderedTime;
  idPresentableVehicle::autoRollState_t autoRollState;
  bool skipRemoteClientUpdates;
  int EMPTimeout;
  float brakeForceBackup;
  netBoolEvent_t quadOn;
  netBoolEvent_t quadOff;
  netBoolEvent_t resetBoost;
  bool isBully;
  bool isScramblingLocks;
  int lockScramblingTimeout;
  bool isSmashActive;
  int predictSmashActiveFrame;
  int smashTimeout;
  unsigned __int8 approxSpeed;
  int timeInAir;
  int firingHeat;
  int firingLastHeatTime;
  int firingLastHeatFrame;
  int firingLastHeatFireTime;
  int numLockedProjectiles;
  bool skipUpdateSounds;
};

// IDA Local Type ordinal 14507; PDB kind: struct.
struct idPresentableVehicle::clientDetachable_t
{
  detachable_t item;
  bool attached;
  bool permDetach;
  int lastAddCount;
  int lastRemoveCount;
  int addCount;
  int removeCount;
  int damageLeft;
};

// IDA Local Type ordinal 14567; PDB kind: struct.
struct __declspec(align(4)) idPresentableVehicle::soundState_t
{
  bool engineRunning;
  int engineDamagedLevel;
  int lastTireBumpSound;
  int startInAirTime;
  int startIdleTime;
  int stopIdleTime;
  int startNonIdleTime;
  int stopNonIdleTime;
  int surfaceType;
  int oldSurfaceType;
  int nextSkidTime;
  bool braking;
  int shiftStartTime;
  int shiftRampDownEndTime;
  int shiftRampUpStartTime;
  int shiftEndTime;
  bool reverse;
  int revLimitStartTime;
  int revLimitEndTime;
  int boostStartTime;
  int boostEndTime;
  bool boostOverlayStarted;
  int nextCrashTime;
  int engineSoundFadeInTime;
  bool crosshairLockedOn;
  bool isLockedTargeted;
};

// IDA Local Type ordinal 14631; PDB kind: struct.
struct idPresentableVehicle::boostFx_t
{
  float curFov;
  float startingPower;
};

// IDA Local Type ordinal 14635; PDB kind: struct.
struct idPresentableVehicle::onlinePerks_t
{
  float boostUpModifier;
  float duraBumpModifier;
  float jumpManModifier;
  float overAmmoModifier;
  float lockJackModifier;
  float fasterFasterModifier;
  float theSnapperModifier;
  int overLoadModifier;
};

// IDA Local Type ordinal 14751; PDB kind: struct.
struct __declspec(align(4)) idPresentableVehicle::vehicleDamageInfo_t
{
  const idDeclDamage *damageDef;
  idVec3 damageDir;
  idVec3 impactPoint;
  float damageScale;
  float damage;
  float startHealth;
  float endHealth;
  int time;
  idPresentablePtr<idPresentable> attacker;
  bool predicted;
};
