#pragma once

#include "game/decls/declgore.h"
#include "idlib/index.h"

class idDamageGroup;
class idDeclDamage;
class idPresentableAnimatedEntity;

using idGoreJointIndex = idIndex<short, idRecoveredInvalidIndex>;

struct idGoreFloorTraceResult {
    bool hit = false;
    idVec3 position = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 normal = idVec3(0.0f, 0.0f, 1.0f);
};

class idGoreComponentServices {
public:
    virtual ~idGoreComponentServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual bool IsGoreEnabled() const;
    virtual bool IsMultiplayer() const;
    virtual bool IsPresentableValid(
        const idPresentableAnimatedEntity* presentable) const;
    virtual bool IsPresentableDead(
        const idPresentableAnimatedEntity* presentable) const;
    virtual float GetPresentableFade(
        const idPresentableAnimatedEntity* presentable) const;
    virtual void GetPresentableTransform(
        const idPresentableAnimatedEntity* presentable,
        idVec3& origin, idMat3& axis) const;

    virtual void SetDeathFadeOpacity(
        idPresentableAnimatedEntity* presentable, float opacity);
    virtual void SetClipSphere(idPresentableAnimatedEntity* presentable,
        int slot, const idVec4& sphere);
    virtual void SetClipEllipsoid(
        idPresentableAnimatedEntity* presentable, const idVec3& origin,
        const idMat3& axis);
    virtual void ClearClipShape(idPresentableAnimatedEntity* presentable,
        int slot);
    virtual void MarkClipParmsChanged(
        idPresentableAnimatedEntity* presentable);

    virtual bool TraceFloor(const idVec3& start, const idVec3& end,
        idGoreFloorTraceResult& result);
    virtual void SetClothFloor(void* cloth, const idVec3& position,
        const idVec3& normal);
    virtual void* AllocateCloth(
        idPresentableAnimatedEntity* presentable, int gorePieceIndex,
        const idAtomicString& attachTag);
    virtual void FreeCloth(void* cloth);

    virtual bool ValidateGorePiece(idPresentableAnimatedEntity* presentable,
        const idGorePieceInfo_t& piece, int pieceIndex) const;
    virtual void RegisterSpawnable(const void* declaration,
        bool breakable, idPresentableAnimatedEntity* presentable);
    virtual void SetMeshKit(idPresentableAnimatedEntity* presentable,
        goreKitComponent_t component, const idAtomicString& name,
        bool visible);
    virtual void ZeroJoint(idPresentableAnimatedEntity* presentable,
        const idAtomicString& jointName, bool zero);
    virtual void BreakConstraint(idPresentableAnimatedEntity* presentable,
        const idAtomicString& constraintName);
    virtual void StopVoice(idPresentableAnimatedEntity* presentable);
    virtual void StartGoreFX(idPresentableAnimatedEntity* presentable,
        int condition, const idAtomicString& jointName);
    virtual void StopGoreFX(idPresentableAnimatedEntity* presentable,
        int condition);
    virtual void SpawnGoreEntity(const void* declaration, bool breakable,
        const idVec3& origin, const idMat3& axis, const idVec3& impulse,
        goreSpawnImpulseBehavior_t behavior);
    virtual void ApplyMorph(idPresentableAnimatedEntity* presentable,
        int morphIndex, bool enabled);

    virtual int GetDamageGoreTypes(const idDeclDamage* damage) const;
    virtual float GetDamageRagdollImpulse(
        const idDeclDamage* damage) const;
    virtual bool HasBodyExplosion(const idDeclDamage* damage) const;
    virtual int GetBodyExplosionMaxPieces(
        const idDeclDamage* damage) const;
    virtual int GetBodyExplosionMaxWounds(
        const idDeclDamage* damage) const;
    virtual idAtomicString GetDamageGroupName(
        const idDamageGroup* group) const;
    virtual int GetTestGoreIndex();
    virtual int RandomInt(int maximum);
    virtual void ActivateBFGBreakable(const idDeclGore& gore,
        idPresentableAnimatedEntity* presentable,
        const idDeclDamage* damage, const idVec3& origin,
        const idVec3& direction);
};

class idGoreComponent {
public:
    struct goreFrameDamage_t {
        idGoreJointIndex hitJoint;
        const idDamageGroup* damageGroup = nullptr;
        const idDeclDamage* damageDecl = nullptr;
        float damage = 0.0f;
        idVec3 impulse = idVec3(0.0f, 0.0f, 0.0f);
        idVec3 position = idVec3(0.0f, 0.0f, 0.0f);
        idVec3 normal = idVec3(0.0f, 0.0f, 1.0f);
    };

    struct goredPiecesInUse_t {
        idVec3 initialGibJointPos = idVec3(0.0f, 0.0f, 0.0f);
        idVec3 impulse = idVec3(0.0f, 0.0f, 0.0f);
        int frameCountSinceSpawn = 0;
        void* clothSim = nullptr;
        short goreIndex = -1;
        bool gibMeshSpawned = false;
        bool activated = false;
    };

    idGoreComponent();
    ~idGoreComponent();

    static void SetServices(idGoreComponentServices* services);
    static idGoreComponentServices& Services();

    void Init(idPresentableAnimatedEntity* presentable,
        const idDeclGore* goreDecl);
    void UpdateDeathFade();
    void SetClipSphereRenderParms(const idVec4& woundSphere,
        int clipSphereIndex);
    void SetClipEllipsoidRenderParms(const idVec3& position,
        const idMat3& axis, int clipEllipsoidIndex);
    void UpdateFloorTrace();
    void DisableCloth(int pieceInUse, const idVec3& position,
        const idVec3& impulse);
    void DisableGorePiece(int goreIndex, const idVec3& position,
        const idVec3& impulse);
    void ActivateBFGExplosion(const idDeclDamage* damageDecl,
        const idVec3& impactPoint, const idVec3& direction);
    bool EnableGorePiece(int goreIndex, const idVec3& impulse);
    void UpdateKillshot(idGoreJointIndex hitJoint,
        const idDeclDamage* damageDecl, float damage,
        const idVec3& impulse, const idVec3& position,
        const idVec3& normal, const idDamageGroup* damageGroup,
        bool allowGore);
    bool CheckForGoreByDamageGroup(const idAtomicString& name,
        goreLevel_t level, const idVec3& direction);
    bool CheckForGoreByName(const idAtomicString& name);
    void ActivateFullBodyExplosion(const idDeclDamage* damageDecl,
        float damage, const idVec3& impactPoint, const idVec3& impulse);
    void AddDamage(idGoreJointIndex hitJoint,
        const idDeclDamage* damageDecl, float damage,
        const idVec3& impulse, const idVec3& position,
        const idVec3& normal, const idDamageGroup* damageGroup,
        bool allowGore);
    void TestGoreCheat();
    bool UpdateGore();
    bool CheckForGore();

    idList<goreFrameDamage_t, 5> frameDamage;
    idList<goredPiecesInUse_t, 5> goredPiecesInUse;
    idList<idGoreJointIndex, 5> jointsGoredThisFrame;
    idList<int, 5> wounds;
    idPresentableAnimatedEntity* presentable;
    const idDeclGore* goreDecl;
    int deathTime;
};

// Retail split-scope cleanup block at 0x82C5D600.
void idGoreInitScopeCleanup();
