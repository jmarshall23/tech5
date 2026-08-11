#include "game/editor/entityinterfacelocal.h"

namespace {
idEntityInterfaceServices defaultServices;
idEntityInterfaceServices* activeServices = &defaultServices;

class ScopedEditorGameLock {
public:
    explicit ScopedEditorGameLock(idGame* gameValue)
        : game(gameValue) {
        idEntityInterfaceLocal::Services().Lock(game);
    }
    ~ScopedEditorGameLock() {
        idEntityInterfaceLocal::Services().Unlock(game);
    }
private:
    idGame* game;
};
}

void idEntityInterfaceLocal::SetServices(
        idEntityInterfaceServices* services) {
    activeServices = services == nullptr ? &defaultServices : services;
}

idEntityInterfaceServices& idEntityInterfaceLocal::Services() {
    return *activeServices;
}

// EA 0x82BDA710
bool idEntityInterfaceLocal::IsValid() {
    ScopedEditorGameLock lock(Game());
    return entityPtr != nullptr;
}

// EA 0x82BDA7B8
void idEntityInterfaceLocal::SetWorldOrigin(const idVec3* origin) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && origin != nullptr) {
        Services().SetWorldOrigin(entityPtr, *origin);
    }
}

// EA 0x82BDA848
void idEntityInterfaceLocal::SetWorldAxis(const idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && axis != nullptr) {
        Services().SetWorldAxis(entityPtr, *axis);
    }
}

// EA 0x82BDA8E8
void idEntityInterfaceLocal::UpdateVisuals() {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().UpdateVisuals(entityPtr);
}

// EA 0x82BDA980
bool idEntityInterfaceLocal::GetWorldSpaceTagTransform(
        const char* propertyName, const char* tagName,
        idVec3* origin, idMat3* axis) {
    return entityPtr != nullptr && origin != nullptr && axis != nullptr &&
        Services().GetWorldSpaceTagTransform(entityPtr, propertyName,
            tagName, *origin, *axis);
}

// EA 0x82BDA9E8
void idEntityInterfaceLocal::BindToJoint(idEntity* master,
        const editorJointIndex_t joint, const bindFlags_t flags) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) {
        Services().BindToJoint(entityPtr, master, joint,
            (static_cast<int>(flags) & 1) != 0);
    }
}

// EA 0x82BDAA90
void idEntityInterfaceLocal::Unbind() {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().Unbind(entityPtr);
}

// EA 0x82BDAB30
bool idEntityInterfaceLocal::DetachRenderModel(
        const editorAttachmentHandle_t handle) {
    ScopedEditorGameLock lock(Game());
    return entityPtr != nullptr &&
        Services().DetachRenderModel(entityPtr, handle);
}

// EA 0x82BDAC08
bool idEntityInterfaceLocal::RebindAttachment(
        const editorAttachmentHandle_t handle, const tagData_t& tagData) {
    ScopedEditorGameLock lock(Game());
    return entityPtr != nullptr &&
        Services().RebindAttachment(entityPtr, handle, tagData);
}

// EA 0x82BDACE8
void idEntityInterfaceLocal::SetModel(const char* modelName) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().SetModel(entityPtr, modelName);
}

// EA 0x82BDAD88
void idEntityInterfaceLocal::SetModel(idRenderModel* model) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().SetModel(entityPtr, model);
}

// EA 0x82BDAE28
void idEntityInterfaceLocal::StopSound() {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().StopSound(entityPtr);
}

// EA 0x82BDAED0
void idEntityInterfaceLocal::SetColor(const idColor* color) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && color != nullptr) {
        Services().SetColor(entityPtr, *color);
    }
}

// EA 0x82BDAF70
idRenderModel* idEntityInterfaceLocal::GetRenderEntity() {
    ScopedEditorGameLock lock(Game());
    return entityPtr == nullptr ? nullptr : Services().GetRenderModel(entityPtr);
}

// EA 0x82BDB018
void idEntityInterfaceLocal::DeleteEntity() {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr) Services().DeleteEntity(game, entityPtr);
}

// EA 0x82BDB0C8
idEntity* idEntityInterfaceLocal::GetEntity() {
    ScopedEditorGameLock lock(Game());
    return entityPtr;
}

// EA 0x82BDB128
idPhysics* idEntityInterfaceLocal::GetPhysics() {
    ScopedEditorGameLock lock(Game());
    return entityPtr == nullptr ? nullptr : Services().GetPhysics(entityPtr);
}

// EA 0x82BDB1C8
bool idEntityInterfaceLocal::GetLightSpotlight() {
    ScopedEditorGameLock lock(Game());
    return false;
}

// EA 0x82BDB210
float idEntityInterfaceLocal::GetAnimTime() {
    ScopedEditorGameLock lock(Game());
    return 0.0f;
}

// EA 0x82BDB258
bool idEntityInterfaceLocal::GetCastShadows() {
    ScopedEditorGameLock lock(Game());
    return true;
}

// EA 0x82BDB2A0
void idEntityInterfaceLocal::SetRemoveOriginRotation(bool) {
    ScopedEditorGameLock lock(Game());
}

// EA 0x82BDB2E8
bool idEntityInterfaceLocal::RespondsToEvent(const idEventDef& event) {
    ScopedEditorGameLock lock(Game());
    return entityPtr != nullptr && Services().RespondsToEvent(entityPtr, event);
}

// EA 0x82BDB3F8
void idEntityInterfaceLocal::GetWorldOrigin(idVec3* origin) {
    ScopedEditorGameLock lock(Game());
    if (origin == nullptr) return;
    if (entityPtr == nullptr) origin->Zero();
    else Services().GetWorldOrigin(entityPtr, *origin);
}

// EA 0x82BDB4A0
void idEntityInterfaceLocal::TranslateWorld(const idVec3* translation) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && translation != nullptr) {
        Services().TranslateWorld(entityPtr, *translation);
    }
}

// EA 0x82BDB538
void idEntityInterfaceLocal::GetWorldAxis(idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (axis == nullptr) return;
    if (entityPtr == nullptr) *axis = idMat3(1.0f);
    else Services().GetWorldAxis(entityPtr, *axis);
}

// EA 0x82BDB630
editorAttachmentHandle_t idEntityInterfaceLocal::AttachRenderModel(
        const char* modelName, const char* propertyName,
        const char* tagName) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr == nullptr) return {};
    return Services().AttachRenderModel(entityPtr, modelName,
        propertyName, tagName);
}

// EA 0x82BDB730
idRenderModel* idEntityInterfaceLocal::GetAttachment(
        const editorAttachmentHandle_t handle) {
    ScopedEditorGameLock lock(Game());
    return entityPtr == nullptr
        ? nullptr : Services().GetAttachment(entityPtr, handle);
}

// EA 0x82BDB828
void idEntityInterfaceLocal::GetLocalOrigin(idVec3* origin) {
    ScopedEditorGameLock lock(Game());
    if (origin == nullptr) return;
    if (entityPtr == nullptr) origin->Zero();
    else Services().GetLocalOrigin(entityPtr, *origin);
}

// EA 0x82BDB9F8
void idEntityInterfaceLocal::SetLocalOrigin(const idVec3* origin) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && origin != nullptr) {
        Services().SetLocalOrigin(entityPtr, *origin);
    }
}

// EA 0x82BDBA90
void idEntityInterfaceLocal::GetLocalAxis(idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (axis == nullptr) return;
    if (entityPtr == nullptr) *axis = idMat3(1.0f);
    else Services().GetLocalAxis(entityPtr, *axis);
}

// EA 0x82BDBC58
void idEntityInterfaceLocal::SetLocalAxis(const idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && axis != nullptr) {
        Services().SetLocalAxis(entityPtr, *axis);
    }
}

// EA 0x82BDBCF0
void idEntityInterfaceLocal::GetSpawnPosition(idVec3* position) {
    ScopedEditorGameLock lock(Game());
    if (position == nullptr) return;
    if (entityPtr == nullptr) position->Zero();
    else Services().GetSpawnPosition(entityPtr, *position);
}

// EA 0x82BDBD98
void idEntityInterfaceLocal::SetSpawnPosition(const idVec3* position) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && position != nullptr) {
        Services().SetSpawnPosition(entityPtr, *position);
    }
}

// EA 0x82BDBE40
void idEntityInterfaceLocal::GetSpawnOrientation(idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (axis == nullptr) return;
    if (entityPtr == nullptr) *axis = idMat3(1.0f);
    else Services().GetSpawnOrientation(entityPtr, *axis);
}

// EA 0x82BDBF38
void idEntityInterfaceLocal::SetSpawnOrientation(const idMat3* axis) {
    ScopedEditorGameLock lock(Game());
    if (entityPtr != nullptr && axis != nullptr) {
        Services().SetSpawnOrientation(entityPtr, *axis);
    }
}

// EA 0x82BDC028
void idEntityInterfaceLocal::GetViewAngles(idAngles* angles) {
    ScopedEditorGameLock lock(Game());
    if (angles != nullptr) *angles = idAngles(0.0f, 0.0f, 0.0f);
}

// EA 0x82BDC090
const char* idEntityInterfaceLocal::GetEntityName() {
    ScopedEditorGameLock lock(Game());
    return entityPtr == nullptr ? "" : Services().GetEntityName(entityPtr);
}

// EA 0x82BDC130
const idDeclEntityDef* idEntityInterfaceLocal::GetEntityDef() {
    return entityPtr == nullptr ? nullptr : Services().GetEntityDef(entityPtr);
}

// EA 0x82BDC168
idEntityInterfaceLocal::idEntityInterfaceLocal(idGame* gameValue,
        idEntity* entity)
    : entityPtr(entity)
    , typeInfoObject(nullptr)
    , game(gameValue)
    , refCount(0) {
    typeInfoObject = Services().CreateTypeInfoObject(game, entityPtr);
}

// EA 0x82BDC280
idEntityInterfaceLocal::~idEntityInterfaceLocal() {
    Services().DestroyTypeInfoObject(typeInfoObject);
    typeInfoObject = nullptr;
}

// EA 0x82BDC310
int idEntityInterfaceLocal::GetNumAttachments() {
    ScopedEditorGameLock lock(Game());
    return entityPtr == nullptr ? 0 : Services().GetNumAttachments(entityPtr);
}

// EA 0x82BDC458
bool idEntityInterfaceLocal::OnCustomFunctionCall() {
    ScopedEditorGameLock lock(Game());
    return entityPtr != nullptr && Services().OnCustomFunctionCall(entityPtr);
}
