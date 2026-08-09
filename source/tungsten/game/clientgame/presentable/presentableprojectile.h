#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\presentable\presentableprojectile.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1039; PDB kind: enum.
enum idPresentableProjectile_Homing::homingState_t : __int32
{
  LAUNCHING = 0x0,
  FLYOUT = 0x1,
  ACQUIRING = 0x2,
};

// IDA Local Type ordinal 15429; PDB kind: class.
class idPresentableProjectile : public idPresentableAnimatedEntity
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34014.
  virtual ~idPresentableProjectile();
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
  virtual bool IsDead();
  virtual void InternalClientLaunch(idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, float, int);
  virtual void UpdateLaserDot();

  const idDeclProjectile *projectileDecl;
  projectileState_t state;
  idPhysics *projectilePhysics;
  idPresentablePtr<idPresentable> attacker;
  bool playingWarningSound;
  idVec3 launchOrigin;
  idMat3 launchAxis;
  bool launched;
  bool hasQuad;
  idVec3 smoothOrigin;
  idMat3 smoothAxis;
  int launchTime;
  idMat3 intitialFireAxis;
};

// IDA Local Type ordinal 15432; PDB kind: class.
class idPresentableProjectile_Rocket : public idPresentableProjectile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34120.
  virtual ~idPresentableProjectile_Rocket();
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
  virtual bool IsDead();
  virtual void InternalClientLaunch(idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, float, int);
  virtual void UpdateLaserDot();
  virtual idVec3 *GetInitialDir(idVec3 *result, const idMat3 *);

  idPhysics_RigidBody physicsObj;
  int calcThrustDelay;
  float goalSpeed;
};

// IDA Local Type ordinal 15437; PDB kind: class.
class idPresentableProjectile_Homing : public idPresentableProjectile_Rocket
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34165.
  virtual ~idPresentableProjectile_Homing();
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
  virtual bool IsDead();
  virtual void InternalClientLaunch(idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, float, int);
  virtual void UpdateLaserDot();
  virtual idVec3 *GetInitialDir(idVec3 *result, const idMat3 *);

  idPresentableProjectile_Homing::homingState_t homingState;
  idProjectileTarget target;
};

// IDA Local Type ordinal 15438; PDB kind: class.
class idPresentableProjectile_Grenade : public idPresentableProjectile
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34119.
  virtual ~idPresentableProjectile_Grenade();
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
  virtual bool IsDead();
  virtual void InternalClientLaunch(idPresentable *, const idVec3 *, const idMat3 *, const idProjectileTarget *, float, int);
  virtual void UpdateLaserDot();

  idPhysics_RigidBody physicsObj;
};
