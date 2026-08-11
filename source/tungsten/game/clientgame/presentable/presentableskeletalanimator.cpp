#include "presentable.h"

namespace {

idPresentableAnimatedEntityServices defaultAnimatedEntityServices;
idPresentableAnimatedEntityServices* animatedEntityServices =
    &defaultAnimatedEntityServices;

idMat3 AnimatedIdentityMatrix() {
    return idMat3(1.0f);
}

} // namespace

void Tungsten_SetPresentableAnimatedEntityServices(
        idPresentableAnimatedEntityServices* services) {
    animatedEntityServices = services != nullptr
        ? services : &defaultAnimatedEntityServices;
}

// EA 0x82B8E668
void idPresentableAnimatedEntity::Hide(bool stopFX) {
    idPresentable::Hide(stopFX);
    if (sphereModel != nullptr && useSphereModel) {
        animatedEntityServices->UnlinkSphereModel(sphereModel);
    }
}

// EA 0x82B8E6B0
const idTreeAnimator* idPresentableAnimatedEntity::GetTreeAnimator() const {
    return cachedAnimator;
}

idPresentableAnimatedEntity::idPresentableAnimatedEntity()
    : idPresentable(), animStack(nullptr), useSphereModel(false),
      sphereModel(nullptr), sphereModelContents(0), createdAnimStack(false),
      serializedEyePos(0.0f, 0.0f, 0.0f), isAimAssistable(true),
      serializedAimAssist(false), serializedTotalCurHealth(0.0f),
      wasAddedToAimAssistList(false), serializedTotalMaxHealth(0.0f),
      cachedAnimator(nullptr) {
}

// EA 0x82B8E6C0
idPresentableAnimatedEntity::idPresentableAnimatedEntity(idEntity* newEntity,
        idRenderModel* renderModel, idAnimStack* stack,
        int newEntityNumber, const idDeclFX* declaration, bool sphere)
    : idPresentable(newEntity, renderModel, newEntityNumber, declaration),
      animStack(stack), useSphereModel(sphere), sphereModel(nullptr),
      sphereModelContents(0), createdAnimStack(false),
      serializedEyePos(0.0f, 0.0f, 0.0f), isAimAssistable(true),
      serializedAimAssist(false), serializedTotalCurHealth(0.0f),
      wasAddedToAimAssistList(false), serializedTotalMaxHealth(0.0f),
      cachedAnimator(animatedEntityServices->AsTreeAnimator(renderModel)) {
    if (useSphereModel
            && !animatedEntityServices->EntityHasClipModel(newEntity)) {
        useSphereModel = false;
    }
    if (newEntityNumber != ENTITYNUM_NONE && cachedAnimator != nullptr
            && useSphereModel) {
        sphereModel = animatedEntityServices->CreateSphereModel(
            cachedAnimator, newEntityNumber);
    }
}

// EA 0x82B8E890
void idPresentableAnimatedEntity::Present() {
    idPresentable::Present();
    if (sphereModel == nullptr) {
        return;
    }
    if (hidden) {
        animatedEntityServices->UnlinkSphereModel(sphereModel);
        return;
    }
    idVec3 animatorOrigin;
    idMat3 animatorAxis;
    animatedEntityServices->GetAnimatorTransform(cachedAnimator,
        animatorOrigin, animatorAxis);
    animatedEntityServices->LinkSphereModel(sphereModel, entityNumber,
        animatorOrigin, animatorAxis, true);
}

// EA 0x82B8E930
void idPresentableAnimatedEntity::UpdateClientCollision(
        const idVec3& oldOrigin, const idMat3& oldAxis,
        const idVec3& newOrigin, const idMat3& newAxis) {
    idPresentable::UpdateClientCollision(oldOrigin, oldAxis,
        newOrigin, newAxis);
    if (sphereModel != nullptr && useSphereModel) {
        animatedEntityServices->EnableSphereModel(sphereModel,
            ShouldEnableSphereCollision());
    }
}

// EA 0x82B8E9A8
void idPresentableAnimatedEntity::Show() {
    idPresentable::Show();
    if (sphereModel != nullptr && useSphereModel) {
        idVec3 animatorOrigin;
        idMat3 animatorAxis;
        animatedEntityServices->GetAnimatorTransform(cachedAnimator,
            animatorOrigin, animatorAxis);
        animatedEntityServices->LinkSphereModel(sphereModel, entityNumber,
            animatorOrigin, animatorAxis, false);
    }
}

// EA 0x82B8EA28
void idPresentableAnimatedEntity::ClientJobSync() {
    UpdateModelTransform();
    if (cachedAnimator != nullptr) {
        animatedEntityServices->SyncAnimatorJoints(cachedAnimator,
            animatedEntityServices->GetServerGameTime());
    }
}

// EA 0x82B8EA80
void idPresentableAnimatedEntity::SetRenderModel(
        idRenderModel* renderModel, bool inheritTransform) {
    idPresentable::SetRenderModel(renderModel, inheritTransform);
    cachedAnimator = animatedEntityServices->AsTreeAnimator(renderModel);
    if (sphereModel != nullptr) {
        animatedEntityServices->DeleteSphereModel(sphereModel);
        sphereModel = cachedAnimator != nullptr
            ? animatedEntityServices->CreateSphereModel(cachedAnimator,
                entityNumber)
            : nullptr;
    }
    if (animatedEntityServices->IsClient() && cachedAnimator != nullptr) {
        animatedEntityServices->SetAnimatorDeferred(cachedAnimator,
            GetParent() == nullptr);
    }
}

// EA 0x82B8EBC8
bool idPresentableAnimatedEntity::GetPresentableTagPosition(
        const char* propName, const char* tagName, idVec3& outOrigin,
        idMat3& outAxis) const {
    const_cast<idPresentableAnimatedEntity*>(this)->UpdateModelTransform();
    if (cachedAnimator != nullptr) {
        return animatedEntityServices->GetTagTransform(cachedAnimator,
            propName, tagName, outOrigin, outAxis);
    }
    if (model != nullptr) {
        outOrigin = animatedEntityServices->GetRenderModelBoundsCenter(model);
        outAxis = axis;
    } else {
        outOrigin.Zero();
        outAxis = AnimatedIdentityMatrix();
    }
    return false;
}

// EA 0x82B8ED58
bool idPresentableAnimatedEntity::GetPresentableTagPosition(
        int propIndex, int tagIndex, idVec3& outOrigin,
        idMat3& outAxis) const {
    const_cast<idPresentableAnimatedEntity*>(this)->UpdateModelTransform();
    if (cachedAnimator != nullptr) {
        return animatedEntityServices->GetTagTransform(cachedAnimator,
            propIndex, tagIndex, outOrigin, outAxis);
    }
    if (model != nullptr) {
        outOrigin = animatedEntityServices->GetRenderModelBoundsCenter(model);
        outAxis = axis;
    } else {
        outOrigin.Zero();
        outAxis = AnimatedIdentityMatrix();
    }
    return false;
}

// EA 0x82B8EEE8
const idInventoryCollection* idPresentableAnimatedEntity::GetInventory()
        const {
    return entity != nullptr && animatedEntityServices->IsServer()
        ? animatedEntityServices->GetEntityInventory(entity) : nullptr;
}

// EA 0x82B8EF68
idInventoryCollection* idPresentableAnimatedEntity::GetInventory() {
    return entity != nullptr && animatedEntityServices->IsServer()
        ? animatedEntityServices->GetEntityInventory(entity) : nullptr;
}

// EA 0x82B8EFE8
void idPresentableAnimatedEntity::InventoryAdded(idInventoryItem* item,
        int count, bool canIntro) {
    if (entity != nullptr) {
        animatedEntityServices->InventoryAdded(entity, item, count, canIntro);
    }
}

// EA 0x82B8F008
void idPresentableAnimatedEntity::GetEyePos(idVec3& eyePosition) const {
    eyePosition = entity != nullptr && animatedEntityServices->IsServer()
        ? animatedEntityServices->GetEntityEyePosition(entity)
        : serializedEyePos;
}

// EA 0x82B8F0A0
float idPresentableAnimatedEntity::GetTotalCurHealth() const {
    return entity != nullptr && animatedEntityServices->IsServer()
        ? animatedEntityServices->GetEntityCurrentHealth(entity)
        : serializedTotalCurHealth;
}

// EA 0x82B8F158
float idPresentableAnimatedEntity::GetTotalMaxHealth() const {
    return entity != nullptr && animatedEntityServices->IsServer()
        ? animatedEntityServices->GetEntityMaximumHealth(entity)
        : serializedTotalMaxHealth;
}

// EA 0x82B8F210
bool idPresentableAnimatedEntity::GetCanAimAssist() {
    if (entity == nullptr || !animatedEntityServices->IsServer()) {
        return serializedAimAssist;
    }
    return isAimAssistable
        && animatedEntityServices->EntityCanAimAssist(entity);
}

// EA 0x82B8F348
bool idPresentableAnimatedEntity::IsTargetLockable(
        const idDeclAmmo* ammo) const {
    return entity != nullptr
        ? animatedEntityServices->EntityIsTargetLockable(entity, ammo)
        : GetTotalCurHealth() > 0.0f;
}

// EA 0x82B8F3C8
idPresentableAnimatedEntity::~idPresentableAnimatedEntity() {
    if (sphereModel != nullptr) {
        animatedEntityServices->DeleteSphereModel(sphereModel);
        sphereModel = nullptr;
    }
    if (wasAddedToAimAssistList) {
        animatedEntityServices->RemoveAimAssistTarget(this);
        wasAddedToAimAssistList = false;
    }
    if (createdAnimStack && animStack != nullptr) {
        animatedEntityServices->FreeSerializedAnimators(animStack);
        animatedEntityServices->DestroyAnimStack(animStack);
        animStack = nullptr;
    }
}

// EA 0x82B8F4B0
void idPresentableAnimatedEntity::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    idTreeAnimator* treeAnimator =
        animatedEntityServices->AsTreeAnimator(model);
    bool hasAnimation = animStack != nullptr && treeAnimator != nullptr;
    serializer.Serialize(hasAnimation);
    serializer.Serialize(useSphereModel);
    serializedTotalMaxHealth = GetTotalMaxHealth();
    serializedTotalCurHealth = GetTotalCurHealth();
    serializer.Serialize(serializedTotalMaxHealth);
    serializer.Serialize(serializedTotalCurHealth);
    if (sphereModel != nullptr) {
        sphereModelContents =
            animatedEntityServices->GetSphereModelContents(sphereModel);
    }
    serializer.Serialize(sphereModelContents);

    if (hasAnimation) {
        if (serializer.IsReading() && animStack != nullptr
                && !createdAnimStack && animatedEntityServices->IsClient()) {
            animStack = nullptr;
        }
        if (animStack != nullptr
                && animatedEntityServices->GetAnimStackTreeAnimator(animStack)
                    != treeAnimator) {
            if (createdAnimStack) {
                animatedEntityServices->DestroyAnimStack(animStack);
            }
            animStack = nullptr;
        }
        if (animStack == nullptr) {
            animStack = animatedEntityServices->CreateAnimStack(treeAnimator);
            createdAnimStack = animStack != nullptr;
            if (createdAnimStack) {
                animatedEntityServices->ResetFXTreeAnimator(this,
                    treeAnimator);
            }
        }
        if (animStack != nullptr) {
            animatedEntityServices->SerializeAnimStack(animStack,
                serializer, animatedEntityServices->GetScaledGameTime());
        }
    } else if (animStack != nullptr) {
        if (serializer.IsReading() && createdAnimStack) {
            animatedEntityServices->DestroyAnimStack(animStack);
        }
        animStack = nullptr;
        createdAnimStack = false;
    }
    cachedAnimator = treeAnimator;
}

// EA 0x82B8F890
void idPresentableAnimatedEntity::UpdateAnimation(int, float fraction) {
    if (animStack != nullptr && !hidden) {
        animatedEntityServices->BlendAnimStack(animStack,
            animatedEntityServices->GetServerGameTime(),
            animatedEntityServices->GetScaledFrameTime(),
            animatedEntityServices->GetTicksPerSecond(), fraction);
    }
}

// EA 0x82B8F948
void idPresentableAnimatedEntity::ClientThink(int currentTime,
        float fraction, bool predict) {
    if (index >= 0x2000) {
        return;
    }
    Interpolate(currentTime, fraction);
    if (predict) {
        ClientPredict(currentTime, fraction);
    }
    UpdateAnimation(currentTime, fraction);
    UpdateFX(1.0f, 0.0f);
    UpdateSound();
    Present();
}

// EA 0x82B8FA10
void idPresentableAnimatedEntity::PostSerializeRead(bool firstClientFrame) {
    idPresentable::PostSerializeRead(firstClientFrame);
    if (entityNumber != ENTITYNUM_NONE && cachedAnimator != nullptr
            && useSphereModel) {
        if (sphereModel == nullptr) {
            sphereModel = animatedEntityServices->CreateSphereModel(
                cachedAnimator, entityNumber);
        }
        if (sphereModel != nullptr) {
            idVec3 animatorOrigin;
            idMat3 animatorAxis;
            animatedEntityServices->GetAnimatorTransform(cachedAnimator,
                animatorOrigin, animatorAxis);
            animatedEntityServices->LinkSphereModel(sphereModel,
                entityNumber, animatorOrigin, animatorAxis, false);
        }
    } else if (sphereModel != nullptr) {
        animatedEntityServices->DeleteSphereModel(sphereModel);
        sphereModel = nullptr;
    }
    if (sphereModel != nullptr) {
        animatedEntityServices->SetSphereModelContents(sphereModel,
            sphereModelContents);
    }
    if (!wasAddedToAimAssistList && serializedAimAssist) {
        animatedEntityServices->AddAimAssistTarget(this);
        wasAddedToAimAssistList = true;
    } else if (wasAddedToAimAssistList && !serializedAimAssist) {
        animatedEntityServices->RemoveAimAssistTarget(this);
        wasAddedToAimAssistList = false;
    }
}

// EA 0x82B8FBC0
void idPresentableAnimatedEntity::UpdateAimAssist() {
    serializedAimAssist = GetCanAimAssist();
    if (wasAddedToAimAssistList && !serializedAimAssist) {
        animatedEntityServices->RemoveAimAssistTarget(this);
        wasAddedToAimAssistList = false;
    } else if (!wasAddedToAimAssistList && serializedAimAssist) {
        animatedEntityServices->AddAimAssistTarget(this);
        wasAddedToAimAssistList = true;
    }
}
