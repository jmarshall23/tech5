#pragma once

#include "framework/entityinterface.h"
#include "idlib/handle.h"
#include "idlib/index.h"

class idAnimStack;
class idDeclEntityDef;
class idDeclVoiceOver;
class idEventDef;
class idGame;
class idMD6Anim;
class idPhysics;
class idTreeAnimator;
class idTypeInfoObject;
struct tagData_t;
enum bindFlags_t : int;
enum invalidAttachment_t : int;
enum invalidJointIndex_t : int;
enum lightClass_t : int;

using editorAttachmentHandle_t =
    idHandle<int, invalidAttachment_t, -1>;
using editorJointIndex_t = idIndex<short, invalidJointIndex_t>;

// Runtime owner for the entity, physics, attachment, and reflection calls
// made by the retail editor interface. The editor translation unit retains
// the recovered control flow while this boundary prevents it from inventing
// layouts for the still-unrecovered central entity classes.
class idEntityInterfaceServices {
public:
    virtual ~idEntityInterfaceServices() = default;

    virtual void Lock(idGame*) {}
    virtual void Unlock(idGame*) {}
    virtual void SetWorldOrigin(idEntity*, const idVec3&) {}
    virtual void SetWorldAxis(idEntity*, const idMat3&) {}
    virtual void UpdateVisuals(idEntity*) {}
    virtual bool GetWorldSpaceTagTransform(idEntity*, const char*,
        const char*, idVec3&, idMat3&) { return false; }
    virtual void BindToJoint(idEntity*, idEntity*, editorJointIndex_t,
        bool) {}
    virtual void Unbind(idEntity*) {}
    virtual editorAttachmentHandle_t AttachRenderModel(idEntity*,
        const char*, const char*, const char*) { return {}; }
    virtual bool DetachRenderModel(idEntity*, editorAttachmentHandle_t) {
        return false;
    }
    virtual int GetNumAttachments(idEntity*) { return 0; }
    virtual idRenderModel* GetAttachment(idEntity*,
        editorAttachmentHandle_t) { return nullptr; }
    virtual bool RebindAttachment(idEntity*, editorAttachmentHandle_t,
        const tagData_t&) { return false; }
    virtual void GetWorldOrigin(idEntity*, idVec3& value) { value.Zero(); }
    virtual void TranslateWorld(idEntity*, const idVec3&) {}
    virtual void GetWorldAxis(idEntity*, idMat3& value) {
        value = idMat3(1.0f);
    }
    virtual void GetLocalOrigin(idEntity*, idVec3& value) { value.Zero(); }
    virtual void SetLocalOrigin(idEntity*, const idVec3&) {}
    virtual void GetLocalAxis(idEntity*, idMat3& value) {
        value = idMat3(1.0f);
    }
    virtual void SetLocalAxis(idEntity*, const idMat3&) {}
    virtual void GetSpawnPosition(idEntity*, idVec3& value) { value.Zero(); }
    virtual void SetSpawnPosition(idEntity*, const idVec3&) {}
    virtual void GetSpawnOrientation(idEntity*, idMat3& value) {
        value = idMat3(1.0f);
    }
    virtual void SetSpawnOrientation(idEntity*, const idMat3&) {}
    virtual void SetModel(idEntity*, idRenderModel*) {}
    virtual void SetModel(idEntity*, const char*) {}
    virtual void StopSound(idEntity*) {}
    virtual void SetColor(idEntity*, const idColor&) {}
    virtual idRenderModel* GetRenderModel(idEntity*) { return nullptr; }
    virtual void DeleteEntity(idGame*, idEntity*) {}
    virtual idPhysics* GetPhysics(idEntity*) { return nullptr; }
    virtual bool RespondsToEvent(idEntity*, const idEventDef&) {
        return false;
    }
    virtual const char* GetEntityName(idEntity*) { return ""; }
    virtual const idDeclEntityDef* GetEntityDef(idEntity*) { return nullptr; }
    virtual idTypeInfoObject* CreateTypeInfoObject(idGame*, idEntity*) {
        return nullptr;
    }
    virtual void DestroyTypeInfoObject(idTypeInfoObject*) {}
    virtual bool OnCustomFunctionCall(idEntity*) { return false; }
};

class idEntityInterfaceLocal : public idEntityInterface {
public:
    idEntityInterfaceLocal(idGame* game, idEntity* entity);
    ~idEntityInterfaceLocal() override;

    static void SetServices(idEntityInterfaceServices* services);
    static idEntityInterfaceServices& Services();

    bool IsValid() override;
    idGame* Game() override { return game; }
    void GetWorldOrigin(idVec3* origin) override;
    void SetWorldOrigin(const idVec3* origin) override;
    void TranslateWorld(const idVec3* translation) override;
    void GetWorldAxis(idMat3* axis) override;
    void SetWorldAxis(const idMat3* axis) override;
    void UpdateVisuals() override;
    bool GetWorldSpaceTagTransform(const char* propertyName,
        const char* tagName, idVec3* origin, idMat3* axis);
    void BindToJoint(idEntity* master, editorJointIndex_t joint,
        bindFlags_t flags);
    void Unbind();
    editorAttachmentHandle_t AttachRenderModel(const char* modelName,
        const char* propertyName, const char* tagName);
    bool DetachRenderModel(editorAttachmentHandle_t handle);
    int GetNumAttachments();
    idRenderModel* GetAttachment(editorAttachmentHandle_t handle);
    bool RebindAttachment(editorAttachmentHandle_t handle,
        const tagData_t& tagData);
    void GetLocalOrigin(idVec3* origin);
    void SetLocalOrigin(const idVec3* origin);
    void GetLocalAxis(idMat3* axis);
    void SetLocalAxis(const idMat3* axis);
    void GetSpawnPosition(idVec3* position);
    void SetSpawnPosition(const idVec3* position);
    void GetSpawnOrientation(idMat3* axis);
    void SetSpawnOrientation(const idMat3* axis);
    void SetModel(idRenderModel* model) override;
    void SetModel(const char* modelName) override;
    void StopSound();
    void SetColor(const idColor* color) override;
    idRenderModel* GetRenderEntity();
    void DeleteEntity() override;
    void GetViewAngles(idAngles* angles);
    void GetEyePosition(idVec3* eyePosition) { eyePosition->Zero(); }

    virtual idTreeAnimator* GetTreeAnimator(int) { return nullptr; }
    virtual idAnimStack* GetAnimStack() { return nullptr; }
    virtual bool PlayAnim(const idMD6Anim*, bool) { return false; }
    virtual bool PlayVTR(const idDeclVoiceOver*, int) { return false; }
    virtual bool StopVTR() { return false; }
    virtual bool IsAnimPlaying() { return false; }
    virtual void ShowUncompressed(bool) {}
    virtual void SetRemoveOriginTranslation(bool) {}
    virtual void SetRemoveOriginRotation(bool);
    virtual bool GetRemoveOriginTranslation() { return false; }
    virtual bool GetRemoveOriginRotation() { return false; }
    virtual void SetAnimTime(float) {}
    virtual float GetAnimTime();
    virtual int GetCurrentAnimFrame() { return 0; }

    void AddReference() override { ++refCount; }
    void RemoveReference() override { --refCount; }
    int GetReferenceCount() override { return refCount; }
    idTypeInfoObject* GetTypeInfoObject() { return typeInfoObject; }
    const idDeclEntityDef* GetEntityDef();
    idEntity* GetEntity() override;
    const char* GetEntityName() override;

    void SetLightColor(const idColor*) {}
    void GetLightColor(idColor*) {}
    void SetLightRadius(const idVec3*) {}
    void GetLightRadius(idVec3*) {}
    void SetCastShadows(bool) {}
    bool GetCastShadows();
    void SetLightMaterial(const char*) {}
    void SetLightSpotlight(bool) {}
    bool GetLightSpotlight();
    void SetLightParallel(bool) {}
    bool GetLightParallel() { return false; }
    void SetLightCenter(const idVec3*) {}
    void GetLightCenter(idVec3*) {}
    void SetLightTarget(const idVec3*) {}
    void SetLightRight(const idVec3*) {}
    void SetLightUp(const idVec3*) {}
    void SetLightStart(const idVec3*) {}
    void SetLightEnd(const idVec3*) {}
    void SetLightClass(lightClass_t) {}
    void ReInit() {}
    void SetPreviewTime(int) {}
    int GetPreviewTime() { return 0; }
    void RestartPlayback() {}
    void StopPlayback() {}
    bool RespondsToEvent(const idEventDef& event);
    bool OnCustomFunctionCall();

protected:
    idPhysics* GetPhysics();

    idEntity* entityPtr;
    idTypeInfoObject* typeInfoObject;
    idGame* game;
    int refCount;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEntityInterfaceLocal) == 20,
    "Recovered local entity-interface ABI changed");
#endif
