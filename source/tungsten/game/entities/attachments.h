#pragma once

#include "game/decls/declinventory.h"
#include "gamelib/animstack/animstacktypes.h"
#include "gamelib/effects/fxmanager.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"

class idAnimatedEntity;
class idDeclEntityDef;
class idEntity;
class idInventoryItem;
class idPresentable;

#ifndef TUNGSTEN_ATTACHMENT_HANDLE_DEFINED
#define TUNGSTEN_ATTACHMENT_HANDLE_DEFINED
enum invalidAttachment_t : int { INVALID_ATTACHMENT = -1 };
using idAttachmentHandle =
    idHandle<int, invalidAttachment_t, INVALID_ATTACHMENT>;
#endif

class idAttachment {
public:
    idAttachment();

    idPresentable* presentable;
    idInventoryItem* item;
    const idDeclParticle* particleFx;
    tagData_t particleFxTagData;
    idVec3 originOffset;
    idQuat savedRotOffset;
    idQuat rotOffset;
    idEntity* entity;
    idJointIndex jointIndex;
    int rotationAxis;
    idAttachmentHandle handle;
    bool isDetached;
    bool ignoreShowAll;
    bool isParticleFX;
    bool wasLinked;
    bool isHidden;
    bool isAnimated;
};

class idAttachmentCollection;

// Runtime ownership boundary for entity tables, presentables, render models,
// animation tags, inventory declarations, particles, and physics.  The
// recovered collection owns selection and lifecycle policy; engine objects
// remain on their original runtime side of this seam.
class idAttachmentServices {
public:
    virtual ~idAttachmentServices() = default;

    virtual int GetGameMilliseconds() const { return 0; }
    virtual bool HasParentAnimator(const idAnimatedEntity*) const {
        return false;
    }
    virtual void UpdateParent(idAnimatedEntity*) {}
    virtual void SyncAnimatedPresentable(idPresentable*, int) {}
    virtual idEntity* ResolveEntity(idEntity* entity) const { return entity; }
    virtual void DeletePresentable(idPresentable*) {}
    virtual bool CapturePresentableWorldTransform(idPresentable*,
        idVec3&, idMat3&) const { return false; }
    virtual void DetachPresentable(idPresentable*,
        const idVec3&, const idMat3&) {}
    virtual void AttachPresentable(idPresentable*, idAnimatedEntity*,
        idJointIndex) {}
    virtual void Present(idPresentable*) {}
    virtual bool UpdatePresentable(idAttachment&, int) { return true; }
    virtual void EmitAttachmentParticles(idAttachment&, int) {}
    virtual bool GetWorldSpaceAttachmentTransform(const idAnimatedEntity*,
        idJointIndex, const idVec3&, const idQuat&,
        idVec3&, idMat3&) const { return false; }
    virtual bool GetAttachmentWorldFrameDelta(const idAnimatedEntity*,
        idJointIndex, const idVec3&, const idQuat&,
        idVec3&, idMat3&) const { return false; }
    virtual void ShowPresentable(idPresentable*) {}
    virtual void HidePresentable(idPresentable*) {}
    virtual void ShowEntity(idEntity*) {}
    virtual void HideEntity(idEntity*) {}
    virtual bool IsVehicleAttachment(const idInventoryItem*) const {
        return false;
    }
    virtual bool IsInitiallyHidden(const idInventoryItem*) const {
        return false;
    }
    virtual idJointIndex ResolveJoint(
        const idAnimatedEntity*, std::uint16_t) const { return {}; }
    virtual bool RebindEntity(idEntity*, idAnimatedEntity*, idJointIndex,
        const tagData_t&) { return false; }
    virtual bool WasEntityLinked(idEntity*) const { return false; }
    virtual void UnbindEntity(idEntity*) {}
    virtual void RestoreEntityClip(idEntity*) {}
    virtual void RemoveEntity(idEntity*) {}
    virtual const char* GetModelName(
        const idAttachment&) const { return ""; }
    virtual const char* GetEntityModelName(
        const idEntity*) const { return ""; }
    virtual bool GetEntityAttachmentOffsets(idAnimatedEntity*, idEntity*,
        idJointIndex, idVec3&, idQuat&, bool&) { return false; }
    virtual bool BindEntity(idEntity*, idAnimatedEntity*, idJointIndex,
        const idVec3&, const idQuat&) { return false; }
    virtual bool ResolveTag(idAnimatedEntity*, const char*, const char*,
        tagData_t&) const { return false; }
    virtual idEntity* SpawnEntity(
        const idDeclEntityDef*, int) { return nullptr; }
    virtual const idDeclInventory* GetInventoryDecl(
        const idInventoryItem*) const { return nullptr; }
    virtual bool CreateInventoryAttachment(idAnimatedEntity*,
        const idDeclInventory*, const char*,
        const idDeclInventory::idAttachmentInfo*, idAttachment&) {
        return false;
    }
    virtual bool CreateModelAttachment(idAnimatedEntity*, const char*,
        const tagData_t&, idAttachment&) { return false; }
    virtual void CoupleInventoryItem(
        idInventoryItem*, idPresentable*) {}
    virtual void Warn(const char*) {}
};

class idAttachmentCollection {
public:
    explicit idAttachmentCollection(idAnimatedEntity* parent = nullptr);
    ~idAttachmentCollection();

    static void SetServices(idAttachmentServices* services);
    static idAttachmentServices& Services();

    idAttachment* ForIndex(int index);
    const idAttachment* ForIndex(int index) const;
    int Num() const { return attachments.Num(); }
    void JobSync();
    int FindAttachmentIndex(const idAttachmentHandle& handle) const;
    int FindAttachmentIndex(const idEntity* entity) const;
    int FindAttachmentIndex(const char* modelName) const;
    const idAttachment* Get(const idAttachmentHandle& handle) const;
    idEntity* GetEntity(const idAttachmentHandle& handle);
    void DetachAttachment(const idAttachmentHandle& handle);
    void ReattachAttachment(const idAttachmentHandle& handle);
    void RemoveAttachment(const idInventoryItem* item);
    void RemoveAttachment(const idAttachmentHandle& handle);
    void RemoveAttachment(const idEntity* entity);
    void RemoveAttachment(const char* modelName);
    idAttachmentHandle FindAttachment(idInventoryItem* item) const;
    idAttachmentHandle FindAttachment(const char* modelName,
        idJointIndex jointIndex) const;
    idAttachmentHandle FindAttachment(const char* modelName) const;
    void UpdateRenderModelAttachments();
    void GetWorldSpaceAttachmentTransform(const idAttachmentHandle& handle,
        idVec3& origin, idMat3& axis) const;
    void GetAttachmentWorldFrameDelta(const idAttachmentHandle& handle,
        idVec3& translation, idMat3& rotation) const;
    void ShowAttachments(bool hideVehicleAttachments);
    void HideAttachments();
    void ShowAttachment(const idAttachmentHandle& handle);
    void HideAttachment(const idAttachmentHandle& handle,
        bool ignoreShowAll);
    bool RebindAttachment(const idAttachmentHandle& handle,
        const tagData_t& tagData);
    void FreeAttachments();

    idAttachmentHandle AddAttachment(idEntity* entity,
        idJointIndex jointIndex);
    idAttachmentHandle AddAttachment(idEntity* entity,
        const tagData_t& tagData);
    idAttachmentHandle AddAttachment(idEntity* entity, const char* tag);
    idAttachmentHandle AddAttachment(const idDeclEntityDef* entityDef,
        const char* tag, int forceReplicationFlags);
    idAttachmentHandle AddAttachment(const idDeclInventory* declaration,
        const char* tagName,
        const idDeclInventory::idAttachmentInfo* fxAttachInfo);
    idAttachmentHandle AddAttachment(idInventoryItem* item,
        const char* tagName,
        const idDeclInventory::idAttachmentInfo* fxAttachInfo);
    idAttachmentHandle AddAttachment(const char* modelName,
        const char* propName, const char* tag,
        const tagData_t* tagInfo, bool allowDuplicate);
    idAttachmentHandle AddAttachment(
        const char* modelName, const char* tag);

    idAnimatedEntity* parent;
    idList<idAttachment, 5> attachments;

private:
    idAttachmentHandle CommitAttachment(idAttachment& attachment,
        int replaceIndex = -1);
    void RemoveIndex(int index, bool deletePresentable);

    static int handleCounter;
};
