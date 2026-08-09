#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\clientgame\presentable\presentabledooranimated.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15480; PDB kind: class.
class __declspec(align(4)) idPresentableDoorAnimated : public idPresentable
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34009.
  virtual ~idPresentableDoorAnimated();
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

  idPhysics_Static physicsObj;
  idStrClipModel clip;
  bool physicsInit;
  int entityOwnerIndex;
  bool linked;
};
