#pragma once

#include "presentable.h"
#include "game/effects/influencetrail_types.h"

#include <cstdint>

class idAI2;
class idAnimator_Pain;
class idDeclGore;
class idDeclProjectile;
class idDeclTwitchPain;
struct trace_t;

class idPresentableAI;

class idPresentableAIServices {
public:
    virtual ~idPresentableAIServices() = default;

    virtual bool IsServer() const { return false; }
    virtual int GetServerGameTime() const { return 0; }
    virtual int GetScaledGameTime() const { return 0; }
    virtual bool SerializeRenderModelParms() const { return true; }
    virtual bool PlayerIndexIsLocal(int) const { return false; }
    virtual idInventoryCollection* GetAIInventory(idAI2*) const {
        return nullptr;
    }

    virtual void EnableInfluence(idPresentableAI*, idEntityInfluenceTrail&) {}
    virtual void UpdateInfluence(idPresentableAI*, const idVec3&, int) {}
    virtual void AddBloodSplatter(const idDeclGore*, const idVec3&,
        const idVec3&, int) {}
    virtual void PlayAdditivePain(idPresentableAI*, idAnimator_Pain*,
        idAnimStack*, const idVec3&, std::int16_t,
        const idDeclTwitchPain*, const char*, int) {}
    virtual void LootBody(idPresentableAI*, int, bool) {}
    virtual std::int16_t GetTraceJoint(const trace_t*) const { return -1; }

    virtual int GetAnimatorIndex(idAnimStack*, idAnimator_Pain*) const {
        return -1;
    }
    virtual idAnimator_Pain* GetAnimatorByIndex(idAnimStack*, int) const {
        return nullptr;
    }
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}

    virtual idClipModel* CreateAttachment(const char*) { return nullptr; }
    virtual void DeleteAttachment(idClipModel*) {}
    virtual void LinkAttachment(idClipModel*, int) {}
    virtual void SetAttachmentContents(idClipModel*, int) {}
    virtual void SetAttachmentTransform(idPresentableAI*, idClipModel*,
        std::int16_t, const idVec3&, const idMat3&) {}
    virtual void SetClipModelContents(idClipModel*, int) {}
};

void Tungsten_SetPresentableAIServices(idPresentableAIServices* services);
idPresentableAIServices* Tungsten_GetPresentableAIServices();

class idPresentableAI : public idPresentableActor {
public:
    struct bloodSplatterEventInfo_t {
        int eventTime;
        int lastHandledEventTime;
        int playerIndex;
        const idDeclGore* goreInfo;
        idVec3 impactPoint;
        idVec3 impactDir;
    };

    struct painAnimationEventInfo_t {
        int eventTime;
        int lastHandledEventTime;
        int playerIndex;
        idStr weaponPrefix;
        idVec3 projDir;
        std::int16_t joint;
        const idDeclTwitchPain* declTwitchPain;
    };

    struct attachmentInfo_t {
        bool enabled;
        idStr name;
        std::int16_t jointId;
        int content;
        const idDeclFX* fxDecl;
        idClipModel* model;
    };

    struct lootBodyEventInfo_t {
        int eventTime;
        int lastHandledEventTime;
        int playerIndex;
        bool hasLoot;
    };

    idPresentableAI();
    idPresentableAI(idAI2* entity, idRenderModel* renderModel,
        idAnimStack* animStack, idAnimator_Pain* painAnimator,
        const idEntityInfluenceTrail* influence, int entityNumber,
        const idDeclFX* fx, bool useSphereModel);
    ~idPresentableAI() override;

    void Serialize(idSerializer& serializer) override;
    void Interpolate(int currentTime, float fraction) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    bool ShouldSerializeRenderModelParms() const override;
    presentableType_t GetType() const override { return PRESENTABLE_AI; }
    idPresentableAI* GetAIInterface() { return this; }

    void SetDefaults();
    void InternalSplatterBlood();
    void InternalPlayAdditivePain();
    void InternalLootBody();
    void SplatterBlood(const idVec3& impactPoint,
        const idVec3& impactDirection, int playerIndex);
    void PlayAdditivePain(const idVec3& projectileDirection,
        std::int16_t joint, int playerIndex);
    void LootBody(int playerIndex, bool bodyHasLoot);
    void PredictHitScanHit(idPresentable* attacker, float damage,
        const idVec3& hitPosition, const idVec3& projectileDirection,
        const idDeclProjectile* projectile, trace_t* trace);
    void UpdateInfluenceTrail();

    bloodSplatterEventInfo_t bloodSplatterEventInfo;
    painAnimationEventInfo_t painAnimationEventInfo;
    attachmentInfo_t attachment;
    lootBodyEventInfo_t lootBodyEventInfo;
    idAnimator_Pain* painAnimator;
    idEntityInfluenceTrail influence;
    bool hasLoot;
    bool predictedLootBody;
    bool dead;
};
