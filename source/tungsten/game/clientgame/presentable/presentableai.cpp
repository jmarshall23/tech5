#include "presentableai.h"

namespace {

idPresentableAIServices defaultPresentableAIServices;
idPresentableAIServices* presentableAIServices = &defaultPresentableAIServices;

idVec3 AIZeroVector() {
    return idVec3(0.0f, 0.0f, 0.0f);
}

} // namespace

void Tungsten_SetPresentableAIServices(idPresentableAIServices* services) {
    presentableAIServices = services != nullptr ? services
                                                : &defaultPresentableAIServices;
}

idPresentableAIServices* Tungsten_GetPresentableAIServices() {
    return presentableAIServices;
}

idPresentableAI::idPresentableAI()
    : idPresentableActor()
    , painAnimator(nullptr)
    , hasLoot(false)
    , predictedLootBody(false)
    , dead(false) {
    painAnimationEventInfo.weaponPrefix.Clear();
    painAnimationEventInfo.joint = -1;
    attachment.name.Clear();
    attachment.jointId = -1;
    SetDefaults();
}

idPresentableAI::idPresentableAI(idAI2* aiEntity,
        idRenderModel* renderModel, idAnimStack* stack,
        idAnimator_Pain* animator, const idEntityInfluenceTrail* trail,
        int newEntityNumber, const idDeclFX* declaration,
        bool sphereModel)
    : idPresentableActor(reinterpret_cast<idEntity*>(aiEntity), renderModel,
        stack, presentableAIServices->GetAIInventory(aiEntity),
        newEntityNumber, declaration, sphereModel)
    , painAnimator(nullptr)
    , hasLoot(false)
    , predictedLootBody(false)
    , dead(false) {
    painAnimationEventInfo.weaponPrefix.Clear();
    painAnimationEventInfo.joint = -1;
    attachment.name.Clear();
    attachment.jointId = -1;
    SetDefaults();
    painAnimator = animator;
    if (trail != nullptr) {
        influence = *trail;
    }
}

idPresentableAI::~idPresentableAI() {
    if (attachment.model != nullptr) {
        presentableAIServices->DeleteAttachment(attachment.model);
        attachment.model = nullptr;
    }
}

void idPresentableAI::InternalSplatterBlood() {
    if (bloodSplatterEventInfo.goreInfo == nullptr) {
        return;
    }
    const idVec3 end = bloodSplatterEventInfo.impactPoint
        + bloodSplatterEventInfo.impactDir * 200.0f;
    presentableAIServices->AddBloodSplatter(
        bloodSplatterEventInfo.goreInfo,
        bloodSplatterEventInfo.impactPoint, end, 1);
}

void idPresentableAI::InternalPlayAdditivePain() {
    UpdateModelTransform();
    if (painAnimationEventInfo.joint == -1 || painAnimator == nullptr
            || painAnimationEventInfo.declTwitchPain == nullptr) {
        return;
    }
    presentableAIServices->PlayAdditivePain(this, painAnimator, animStack,
        painAnimationEventInfo.projDir, painAnimationEventInfo.joint,
        painAnimationEventInfo.declTwitchPain,
        painAnimationEventInfo.weaponPrefix.c_str(), 150);
}

void idPresentableAI::InternalLootBody() {
    presentableAIServices->LootBody(this, lootBodyEventInfo.playerIndex,
        lootBodyEventInfo.hasLoot);
}

void idPresentableAI::Interpolate(int currentTime, float fraction) {
    idPresentableAnimatedEntity::Interpolate(currentTime, fraction);
    if (lootBodyEventInfo.lastHandledEventTime
            != lootBodyEventInfo.eventTime) {
        predictedLootBody = false;
        if (!presentableAIServices->PlayerIndexIsLocal(
                lootBodyEventInfo.playerIndex)) {
            InternalLootBody();
        }
    }
    lootBodyEventInfo.lastHandledEventTime = lootBodyEventInfo.eventTime;
}

bool idPresentableAI::ShouldSerializeRenderModelParms() const {
    return presentableAIServices->SerializeRenderModelParms();
}

void idPresentableAI::SetDefaults() {
    painAnimator = nullptr;
    hasLoot = false;
    predictedLootBody = false;
    dead = false;

    bloodSplatterEventInfo.eventTime = 0;
    bloodSplatterEventInfo.lastHandledEventTime = 0;
    bloodSplatterEventInfo.playerIndex = 0;
    bloodSplatterEventInfo.goreInfo = nullptr;
    bloodSplatterEventInfo.impactPoint = AIZeroVector();
    bloodSplatterEventInfo.impactDir = AIZeroVector();

    painAnimationEventInfo.eventTime = 0;
    painAnimationEventInfo.lastHandledEventTime = 0;
    painAnimationEventInfo.playerIndex = 0;
    painAnimationEventInfo.projDir = AIZeroVector();
    painAnimationEventInfo.declTwitchPain = nullptr;

    lootBodyEventInfo.eventTime = 0;
    lootBodyEventInfo.lastHandledEventTime = 0;
    lootBodyEventInfo.playerIndex = 0;
    lootBodyEventInfo.hasLoot = false;

    attachment.enabled = false;
    attachment.content = 0;
    attachment.fxDecl = nullptr;
    attachment.model = nullptr;
    presentableAIServices->EnableInfluence(this, influence);
}

void idPresentableAI::SplatterBlood(const idVec3& impactPoint,
        const idVec3& impactDirection, int playerIndex) {
    if (presentableAIServices->IsServer()) {
        bloodSplatterEventInfo.playerIndex = playerIndex;
        bloodSplatterEventInfo.eventTime =
            presentableAIServices->GetServerGameTime();
        bloodSplatterEventInfo.lastHandledEventTime =
            bloodSplatterEventInfo.eventTime;
    }
    bloodSplatterEventInfo.impactPoint = impactPoint;
    bloodSplatterEventInfo.impactDir = impactDirection;
    InternalSplatterBlood();
}

void idPresentableAI::PlayAdditivePain(
        const idVec3& projectileDirection, std::int16_t joint,
        int playerIndex) {
    if (presentableAIServices->IsServer()) {
        painAnimationEventInfo.playerIndex = playerIndex;
        painAnimationEventInfo.eventTime =
            presentableAIServices->GetServerGameTime();
        painAnimationEventInfo.lastHandledEventTime =
            painAnimationEventInfo.eventTime;
    }
    painAnimationEventInfo.projDir = projectileDirection;
    painAnimationEventInfo.joint = joint;
    InternalPlayAdditivePain();
}

void idPresentableAI::LootBody(int playerIndex, bool bodyHasLoot) {
    if (presentableAIServices->IsServer()) {
        lootBodyEventInfo.playerIndex = playerIndex;
        lootBodyEventInfo.eventTime = presentableAIServices->GetServerGameTime();
        lootBodyEventInfo.lastHandledEventTime =
            lootBodyEventInfo.eventTime;
        lootBodyEventInfo.hasLoot = bodyHasLoot;
    } else {
        lootBodyEventInfo.hasLoot = bodyHasLoot;
        predictedLootBody = true;
    }
    InternalLootBody();
}

void idPresentableAI::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentableActor::ClientThink(currentTime, fraction, predict);
    presentableAIServices->UpdateInfluence(this, origin,
        presentableAIServices->GetScaledGameTime());
    if (dead && clipModel != nullptr) {
        presentableAIServices->SetClipModelContents(clipModel, 0);
    }
    if (attachment.model != nullptr) {
        presentableAIServices->SetAttachmentTransform(this,
            attachment.model, attachment.jointId, origin, axis);
    }
}

void idPresentableAI::PredictHitScanHit(idPresentable* attacker, float,
        const idVec3& hitPosition, const idVec3& projectileDirection,
        const idDeclProjectile*, trace_t* trace) {
    if (trace == nullptr) {
        return;
    }
    const int playerIndex = attacker != nullptr ? attacker->index : -1;
    SplatterBlood(hitPosition, projectileDirection, playerIndex);
    PlayAdditivePain(projectileDirection,
        presentableAIServices->GetTraceJoint(trace), playerIndex);
}

void idPresentableAI::Serialize(idSerializer& serializer) {
    idPresentableActor::Serialize(serializer);
    serializer.Serialize(hasLoot);
    serializer.Serialize(dead);

    serializer.Serialize(bloodSplatterEventInfo.eventTime);
    serializer.Serialize(bloodSplatterEventInfo.playerIndex);
    const void* gore = bloodSplatterEventInfo.goreInfo;
    presentableAIServices->SerializeDeclaration(serializer, gore);
    if (serializer.IsReading()) {
        bloodSplatterEventInfo.goreInfo = static_cast<const idDeclGore*>(gore);
    }
    serializer.Serialize(bloodSplatterEventInfo.impactPoint);
    serializer.Serialize(bloodSplatterEventInfo.impactDir);

    serializer.Serialize(painAnimationEventInfo.eventTime);
    serializer.Serialize(painAnimationEventInfo.playerIndex);
    serializer.Serialize(painAnimationEventInfo.projDir);
    const void* twitch = painAnimationEventInfo.declTwitchPain;
    presentableAIServices->SerializeDeclaration(serializer, twitch);
    if (serializer.IsReading()) {
        painAnimationEventInfo.declTwitchPain =
            static_cast<const idDeclTwitchPain*>(twitch);
    }

    serializer.Serialize(lootBodyEventInfo.eventTime);
    serializer.Serialize(lootBodyEventInfo.playerIndex);
    serializer.Serialize(lootBodyEventInfo.hasLoot);

    serializer.Serialize(influence.angle);
    serializer.Serialize(influence.innerRadius);
    serializer.Serialize(influence.outerRadius);
    serializer.Serialize(influence.trailDist);
    serializer.Serialize(influence.trailFadeInTime);
    serializer.Serialize(influence.trailFadeOutTime);

    int painAnimatorIndex = serializer.IsWriting()
        ? presentableAIServices->GetAnimatorIndex(animStack, painAnimator)
        : -1;
    serializer.SerializePacked(painAnimatorIndex);
    if (serializer.IsReading()) {
        painAnimator = presentableAIServices->GetAnimatorByIndex(animStack,
            painAnimatorIndex);
    }

    serializer.Serialize(painAnimationEventInfo.joint);
    serializer.Serialize(attachment.enabled);
    serializer.SerializeString(attachment.name);
    serializer.Serialize(attachment.content);
    serializer.Serialize(attachment.jointId);
    serializer.SerializeString(painAnimationEventInfo.weaponPrefix);

    if (serializer.IsReading()) {
        if (attachment.enabled && !attachment.name.IsEmpty() && !hidden) {
            if (attachment.model == nullptr) {
                attachment.model = presentableAIServices->CreateAttachment(
                    attachment.name.c_str());
                if (attachment.model != nullptr) {
                    presentableAIServices->LinkAttachment(attachment.model,
                        entityNumber);
                }
            }
            if (attachment.model != nullptr) {
                presentableAIServices->SetAttachmentContents(attachment.model,
                    attachment.content);
            }
        } else if (!attachment.enabled && attachment.model != nullptr) {
            presentableAIServices->DeleteAttachment(attachment.model);
            attachment.model = nullptr;
        }
    }
}
