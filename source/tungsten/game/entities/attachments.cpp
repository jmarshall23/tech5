#include "game/entities/attachments.h"

#include <algorithm>

namespace {
idAttachmentServices defaultAttachmentServices;
idAttachmentServices* attachmentServices = &defaultAttachmentServices;

void ClearTransform(idVec3& translation, idMat3& rotation) {
    translation.Zero();
    rotation = idMat3(1.0f);
}
}

int idAttachmentCollection::handleCounter = 0;

idAttachmentCollection::idAttachmentCollection(idAnimatedEntity* const parent_)
    : parent(parent_), attachments() {
}

idAttachmentCollection::~idAttachmentCollection() {
    FreeAttachments();
}

void idAttachmentCollection::SetServices(
        idAttachmentServices* const services) {
    attachmentServices = services == nullptr
        ? &defaultAttachmentServices : services;
}

idAttachmentServices& idAttachmentCollection::Services() {
    return *attachmentServices;
}

// Retail: 0x82C07F80 ?ForIndex@idAttachmentCollection@@QAAPAVidAttachment@@H@Z
idAttachment* idAttachmentCollection::ForIndex(const int index) {
    return index >= 0 && index < attachments.Num()
        ? &attachments[index] : nullptr;
}

const idAttachment* idAttachmentCollection::ForIndex(const int index) const {
    return index >= 0 && index < attachments.Num()
        ? &attachments[index] : nullptr;
}

// Retail: 0x82C07FB0 ?JobSync@idAttachmentCollection@@QAAXXZ
void idAttachmentCollection::JobSync() {
    const int currentTime = Services().GetGameMilliseconds();
    for (int index = 0; index < attachments.Num(); ++index) {
        idAttachment& attachment = attachments[index];
        if (attachment.isAnimated && attachment.presentable != nullptr) {
            Services().SyncAnimatedPresentable(
                attachment.presentable, currentTime);
        }
    }
}

// Retail: 0x82C08048 ?FindAttachmentIndex@idAttachmentCollection@@...handle...
int idAttachmentCollection::FindAttachmentIndex(
        const idAttachmentHandle& handle) const {
    for (int index = 0; index < attachments.Num(); ++index) {
        if (attachments[index].handle == handle) {
            return index;
        }
    }
    return -1;
}

// Retail: 0x82C08108 ??0idAttachment@@QAA@XZ
idAttachment::idAttachment()
    : presentable(nullptr), item(nullptr), particleFx(nullptr),
      particleFxTagData{idVec3(0.0f, 0.0f, 0.0f),
          idQuat(0.0f, 0.0f, 0.0f, 0.0f), 0xFFFFu},
      originOffset(0.0f, 0.0f, 0.0f),
      savedRotOffset(0.0f, 0.0f, 0.0f, 0.0f),
      rotOffset(0.0f, 0.0f, 0.0f, 0.0f), entity(nullptr),
      jointIndex(), rotationAxis(-1), handle(), isDetached(false),
      ignoreShowAll(false), isParticleFX(false), wasLinked(false),
      isHidden(false), isAnimated(false) {
}

// Retail: 0x82C081A0 ?Get@idAttachmentCollection@@QBAPBVidAttachment@@...
const idAttachment* idAttachmentCollection::Get(
        const idAttachmentHandle& handle) const {
    return ForIndex(FindAttachmentIndex(handle));
}

// Retail: 0x82C081F0 ?GetEntity@idAttachmentCollection@@QAAPAVidEntity@@...
idEntity* idAttachmentCollection::GetEntity(
        const idAttachmentHandle& handle) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    return attachment == nullptr
        ? nullptr : Services().ResolveEntity(attachment->entity);
}

// Retail: 0x82C08280 ?DetachAttachment@idAttachmentCollection@@QAAX...
void idAttachmentCollection::DetachAttachment(
        const idAttachmentHandle& handle) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr || attachment->presentable == nullptr
            || !Services().HasParentAnimator(parent)) {
        return;
    }
    Services().UpdateParent(parent);
    idVec3 origin;
    idMat3 axis;
    if (Services().CapturePresentableWorldTransform(
            attachment->presentable, origin, axis)) {
        Services().DetachPresentable(attachment->presentable, origin, axis);
        attachment->isDetached = true;
    }
}

// Retail: 0x82C083B0 ?ReattachAttachment@idAttachmentCollection@@QAAX...
void idAttachmentCollection::ReattachAttachment(
        const idAttachmentHandle& handle) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr || attachment->presentable == nullptr
            || !Services().HasParentAnimator(parent)) {
        return;
    }
    Services().UpdateParent(parent);
    Services().AttachPresentable(
        attachment->presentable, parent, attachment->jointIndex);
    Services().Present(attachment->presentable);
    attachment->isDetached = false;
}

void idAttachmentCollection::RemoveIndex(
        const int index, const bool deletePresentable) {
    if (index < 0 || index >= attachments.Num()) {
        return;
    }
    if (deletePresentable && attachments[index].presentable != nullptr) {
        Services().DeletePresentable(attachments[index].presentable);
        attachments[index].presentable = nullptr;
    }
    attachments.RemoveIndexFast(index);
}

// Retail: 0x82C08470 ?RemoveAttachment@idAttachmentCollection@@QAAXPBVidInventoryItem@@@Z
void idAttachmentCollection::RemoveAttachment(
        const idInventoryItem* const item) {
    for (int index = 0; index < attachments.Num(); ++index) {
        if (attachments[index].item == item) {
            RemoveIndex(index, true);
            return;
        }
    }
}

// Retail: 0x82C08500 ?RemoveAttachment@idAttachmentCollection@@QAAX...handle...
void idAttachmentCollection::RemoveAttachment(
        const idAttachmentHandle& handle) {
    RemoveIndex(FindAttachmentIndex(handle), true);
}

// Retail: 0x82C08558 ?FindAttachment@idAttachmentCollection@@...idInventoryItem...
idAttachmentHandle idAttachmentCollection::FindAttachment(
        idInventoryItem* const item) const {
    for (int index = 0; index < attachments.Num(); ++index) {
        if (attachments[index].item == item) {
            return attachments[index].handle;
        }
    }
    return {};
}

// Retail: 0x82C085C0 ?UpdateRenderModelAttachments@idAttachmentCollection@@QAAXXZ
void idAttachmentCollection::UpdateRenderModelAttachments() {
    const int currentTime = Services().GetGameMilliseconds();
    for (int index = 0; index < attachments.Num(); ++index) {
        idAttachment& attachment = attachments[index];
        if (Services().ResolveEntity(attachment.entity) != nullptr) {
            continue;
        }
        if (attachment.presentable == nullptr) {
            RemoveIndex(index--, false);
            continue;
        }
        if (attachment.isHidden || !attachment.jointIndex.IsValid()) {
            continue;
        }
        if (Services().UpdatePresentable(attachment, currentTime)
                && attachment.particleFx != nullptr) {
            Services().EmitAttachmentParticles(attachment, currentTime);
        }
    }
}

// Retail: 0x82C089C0 ?GetWorldSpaceAttachmentTransform@idAttachmentCollection@@...
void idAttachmentCollection::GetWorldSpaceAttachmentTransform(
        const idAttachmentHandle& handle,
        idVec3& origin, idMat3& axis) const {
    const idAttachment* const attachment = Get(handle);
    if (attachment == nullptr || !Services().HasParentAnimator(parent)) {
        ClearTransform(origin, axis);
        return;
    }
    Services().UpdateParent(parent);
    if (!Services().GetWorldSpaceAttachmentTransform(parent,
            attachment->jointIndex, attachment->originOffset,
            attachment->rotOffset, origin, axis)) {
        ClearTransform(origin, axis);
    }
}

// Retail: 0x82C08A98 ?GetAttachmentWorldFrameDelta@idAttachmentCollection@@...
void idAttachmentCollection::GetAttachmentWorldFrameDelta(
        const idAttachmentHandle& handle,
        idVec3& translation, idMat3& rotation) const {
    const idAttachment* const attachment = Get(handle);
    if (attachment == nullptr || !Services().HasParentAnimator(parent)) {
        ClearTransform(translation, rotation);
        return;
    }
    Services().UpdateParent(parent);
    if (!Services().GetAttachmentWorldFrameDelta(parent,
            attachment->jointIndex, attachment->originOffset,
            attachment->rotOffset, translation, rotation)) {
        ClearTransform(translation, rotation);
    }
}

// Retail: 0x82C08B70 ?ShowAttachments@idAttachmentCollection@@QAAX_N@Z
void idAttachmentCollection::ShowAttachments(
        const bool hideVehicleAttachments) {
    for (int index = 0; index < attachments.Num(); ++index) {
        idAttachment& attachment = attachments[index];
        if (Services().ResolveEntity(attachment.entity) != nullptr
                || attachment.ignoreShowAll || attachment.presentable == nullptr
                || (hideVehicleAttachments
                    && Services().IsVehicleAttachment(attachment.item))
                || Services().IsInitiallyHidden(attachment.item)) {
            continue;
        }
        Services().ShowPresentable(attachment.presentable);
        attachment.isHidden = false;
    }
}

// Retail: 0x82C08C58 ?HideAttachments@idAttachmentCollection@@QAAXXZ
void idAttachmentCollection::HideAttachments() {
    for (int index = 0; index < attachments.Num(); ++index) {
        idAttachment& attachment = attachments[index];
        if (Services().ResolveEntity(attachment.entity) == nullptr
                && attachment.presentable != nullptr) {
            Services().HidePresentable(attachment.presentable);
            attachment.isHidden = true;
        }
    }
}

// Retail: 0x82C08CF0 ?ShowAttachment@idAttachmentCollection@@QAAX...handle...
void idAttachmentCollection::ShowAttachment(
        const idAttachmentHandle& handle) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr) {
        return;
    }
    idEntity* const entity = Services().ResolveEntity(attachment->entity);
    if (entity != nullptr) {
        Services().ShowEntity(entity);
    } else if (attachment->presentable != nullptr) {
        Services().ShowPresentable(attachment->presentable);
        attachment->isHidden = false;
    }
}

// Retail: 0x82C08DF8 ?HideAttachment@idAttachmentCollection@@QAAX...handle..._N@Z
void idAttachmentCollection::HideAttachment(
        const idAttachmentHandle& handle, const bool ignoreShowAll) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr) {
        return;
    }
    idEntity* const entity = Services().ResolveEntity(attachment->entity);
    if (entity != nullptr) {
        Services().HideEntity(entity);
    } else if (attachment->presentable != nullptr) {
        Services().HidePresentable(attachment->presentable);
        attachment->ignoreShowAll = ignoreShowAll;
        attachment->isHidden = true;
    }
}

// Retail: 0x82C08EF8 ?FindAttachmentIndex@idAttachmentCollection@@ABAHPBVidEntity@@@Z
int idAttachmentCollection::FindAttachmentIndex(
        const idEntity* const entity) const {
    for (int index = 0; index < attachments.Num(); ++index) {
        if (Services().ResolveEntity(attachments[index].entity) == entity) {
            return index;
        }
    }
    return -1;
}

// Retail: 0x82C08FB0 ?RebindAttachment@idAttachmentCollection@@QAA_N...tagData_t...
bool idAttachmentCollection::RebindAttachment(
        const idAttachmentHandle& handle, const tagData_t& tagData) {
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr || !Services().HasParentAnimator(parent)) {
        return false;
    }
    Services().UpdateParent(parent);
    attachment->jointIndex = Services().ResolveJoint(
        parent, tagData.parentJoint);
    attachment->originOffset = tagData.trans;
    attachment->rotOffset = tagData.rot;
    if (attachment->presentable != nullptr) {
        Services().AttachPresentable(attachment->presentable,
            parent, attachment->jointIndex);
        Services().Present(attachment->presentable);
        return true;
    }
    idEntity* const entity = Services().ResolveEntity(attachment->entity);
    return entity == nullptr || Services().RebindEntity(
        entity, parent, attachment->jointIndex, tagData);
}

// Retail: 0x82C09168 ?RemoveAttachment@idAttachmentCollection@@QAAXPBVidEntity@@@Z
void idAttachmentCollection::RemoveAttachment(
        const idEntity* const entity) {
    if (entity == nullptr) {
        Services().Warn("attempt to remove a null entity attachment");
        return;
    }
    const int index = FindAttachmentIndex(entity);
    if (index < 0) {
        Services().Warn("attempt to remove an entity attachment that does not exist");
        return;
    }
    idEntity* const attached = Services().ResolveEntity(
        attachments[index].entity);
    if (attached != nullptr) {
        Services().UnbindEntity(attached);
        if (attachments[index].wasLinked) {
            Services().RestoreEntityClip(attached);
        }
    }
    RemoveIndex(index, false);
}

// Retail: 0x82C09268 ?FindAttachment@idAttachmentCollection@@...PBD...jointIndex...
idAttachmentHandle idAttachmentCollection::FindAttachment(
        const char* const modelName, const idJointIndex jointIndex) const {
    for (int index = 0; index < attachments.Num(); ++index) {
        const idAttachment& attachment = attachments[index];
        if (attachment.jointIndex == jointIndex
                && idStr::Icmp(Services().GetModelName(attachment),
                    modelName) == 0) {
            return attachment.handle;
        }
    }
    return {};
}

// Retail: 0x82C093D8 ?FreeAttachments@idAttachmentCollection@@QAAXXZ
void idAttachmentCollection::FreeAttachments() {
    for (int index = 0; index < attachments.Num(); ++index) {
        idAttachment& attachment = attachments[index];
        idEntity* const entity = Services().ResolveEntity(attachment.entity);
        if (entity != nullptr) {
            Services().RemoveEntity(entity);
            attachment.entity = nullptr;
        } else if (attachment.presentable != nullptr) {
            Services().DeletePresentable(attachment.presentable);
            attachment.presentable = nullptr;
        }
    }
    attachments.ClearFree();
}

// Retail: 0x82C09538 ?FindAttachmentIndex@idAttachmentCollection@@ABAHPBD@Z
int idAttachmentCollection::FindAttachmentIndex(
        const char* const modelName) const {
    for (int index = 0; index < attachments.Num(); ++index) {
        if (idStr::Icmp(Services().GetModelName(attachments[index]),
                modelName) == 0) {
            return index;
        }
    }
    return -1;
}

// Retail: 0x82C09670 ?RemoveAttachment@idAttachmentCollection@@QAAXPBD@Z
void idAttachmentCollection::RemoveAttachment(const char* const modelName) {
    RemoveIndex(FindAttachmentIndex(modelName), true);
}

// Retail: 0x82C096C0 ?FindAttachment@idAttachmentCollection@@...PBD@Z
idAttachmentHandle idAttachmentCollection::FindAttachment(
        const char* const modelName) const {
    const int index = FindAttachmentIndex(modelName);
    return index < 0 ? idAttachmentHandle() : attachments[index].handle;
}

idAttachmentHandle idAttachmentCollection::CommitAttachment(
        idAttachment& attachment, const int replaceIndex) {
    const int assignedHandle = handleCounter++;
    if (handleCounter < 0) {
        handleCounter = 0;
    }
    attachment.handle = assignedHandle;
    if (replaceIndex >= 0 && replaceIndex < attachments.Num()) {
        attachments[replaceIndex] = attachment;
    } else if (attachments.Append(attachment) < 0) {
        return {};
    }
    return attachment.handle;
}

// Retail: 0x82C09968 ?AddAttachment@idAttachmentCollection@@...idEntity...jointIndex...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        idEntity* const entity, const idJointIndex jointIndex) {
    if (entity == nullptr || !Services().HasParentAnimator(parent)) {
        Services().Warn("cannot add entity attachment without entity and animator");
        return {};
    }
    Services().UpdateParent(parent);
    idAttachment attachment;
    attachment.entity = entity;
    attachment.jointIndex = jointIndex;
    if (!Services().GetEntityAttachmentOffsets(parent, entity, jointIndex,
            attachment.originOffset, attachment.rotOffset,
            attachment.wasLinked)
            || !Services().BindEntity(entity, parent, jointIndex,
                attachment.originOffset, attachment.rotOffset)) {
        return {};
    }
    attachment.savedRotOffset = attachment.rotOffset;
    return CommitAttachment(attachment);
}

// Retail: 0x82C09C10 ?AddAttachment@idAttachmentCollection@@...idEntity...tagData_t...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        idEntity* const entity, const tagData_t& tagData) {
    if (entity == nullptr || !Services().HasParentAnimator(parent)) {
        return {};
    }
    Services().UpdateParent(parent);
    idAttachment attachment;
    attachment.entity = entity;
    attachment.jointIndex = Services().ResolveJoint(
        parent, tagData.parentJoint);
    attachment.originOffset = tagData.trans;
    attachment.rotOffset = tagData.rot;
    attachment.savedRotOffset = tagData.rot;
    attachment.wasLinked = Services().WasEntityLinked(entity);
    if (!Services().BindEntity(entity, parent, attachment.jointIndex,
            attachment.originOffset, attachment.rotOffset)) {
        return {};
    }
    return CommitAttachment(attachment, FindAttachmentIndex(entity));
}

// Retail: 0x82C09EF8 ?AddAttachment@idAttachmentCollection@@...idEntity...PBD@Z
idAttachmentHandle idAttachmentCollection::AddAttachment(
        idEntity* const entity, const char* const tag) {
    if (entity == nullptr || !Services().HasParentAnimator(parent)) {
        return {};
    }
    tagData_t tagData{};
    tagData.parentJoint = 0xFFFFu;
    if (!Services().ResolveTag(parent,
            Services().GetEntityModelName(entity), tag, tagData)
            || tagData.parentJoint == 0xFFFFu) {
        Services().Warn("entity attachment tag was not found");
        return {};
    }
    return AddAttachment(entity, tagData);
}

// Retail: 0x82C0A040 ?AddAttachment@idAttachmentCollection@@...idDeclEntityDef...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        const idDeclEntityDef* const entityDef, const char* const tag,
        const int forceReplicationFlags) {
    if (entityDef == nullptr) {
        return {};
    }
    idEntity* const entity = Services().SpawnEntity(
        entityDef, forceReplicationFlags);
    if (entity == nullptr) {
        Services().Warn("failed to spawn attachment entity");
        return {};
    }
    return AddAttachment(entity, tag);
}

// Retail: 0x82C0A0F0 ?AddAttachment@idAttachmentCollection@@...idDeclInventory...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        const idDeclInventory* const declaration, const char* const tagName,
        const idDeclInventory::idAttachmentInfo* const fxAttachInfo) {
    if (declaration == nullptr || !Services().HasParentAnimator(parent)) {
        return {};
    }
    Services().UpdateParent(parent);
    idAttachment attachment;
    if (!Services().CreateInventoryAttachment(parent, declaration,
            tagName, fxAttachInfo, attachment)) {
        return {};
    }
    attachment.savedRotOffset = attachment.rotOffset;
    return CommitAttachment(attachment);
}

// Retail: 0x82C0AA48 ?AddAttachment@idAttachmentCollection@@...idInventoryItem...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        idInventoryItem* const item, const char* const tagName,
        const idDeclInventory::idAttachmentInfo* const fxAttachInfo) {
    const idDeclInventory* const declaration =
        Services().GetInventoryDecl(item);
    const idAttachmentHandle handle = AddAttachment(
        declaration, tagName, fxAttachInfo);
    idAttachment* const attachment = ForIndex(FindAttachmentIndex(handle));
    if (attachment == nullptr) {
        return {};
    }
    attachment->item = item;
    Services().CoupleInventoryItem(item, attachment->presentable);
    return handle;
}

// Retail: 0x82C0ABB0 ?AddAttachment@idAttachmentCollection@@...model...tagData...
idAttachmentHandle idAttachmentCollection::AddAttachment(
        const char* const modelName, const char* const propName,
        const char* const tag, const tagData_t* const suppliedTagInfo,
        const bool allowDuplicate) {
    if (modelName == nullptr || !Services().HasParentAnimator(parent)) {
        return {};
    }
    Services().UpdateParent(parent);
    tagData_t resolvedTag{};
    resolvedTag.parentJoint = 0xFFFFu;
    const tagData_t* tagInfo = suppliedTagInfo;
    if (tagInfo == nullptr) {
        const char* const property = propName == nullptr
            ? modelName : propName;
        if (!Services().ResolveTag(parent, property, tag, resolvedTag)) {
            Services().Warn("static attachment tag was not found");
            return {};
        }
        tagInfo = &resolvedTag;
    }
    if (tagInfo->parentJoint == 0xFFFFu) {
        return {};
    }
    const idJointIndex jointIndex = Services().ResolveJoint(
        parent, tagInfo->parentJoint);
    if (!allowDuplicate) {
        const idAttachmentHandle existing = FindAttachment(
            modelName, jointIndex);
        if (existing.IsValid()) {
            return existing;
        }
    }
    idAttachment attachment;
    attachment.jointIndex = jointIndex;
    attachment.originOffset = tagInfo->trans;
    attachment.rotOffset = tagInfo->rot;
    attachment.savedRotOffset = tagInfo->rot;
    if (!Services().CreateModelAttachment(
            parent, modelName, *tagInfo, attachment)) {
        Services().Warn("failed to allocate attachment render model");
        return {};
    }
    return CommitAttachment(attachment);
}

// Retail: 0x82C0B330 ?AddAttachment@idAttachmentCollection@@...PBD0@Z
idAttachmentHandle idAttachmentCollection::AddAttachment(
        const char* const modelName, const char* const tag) {
    return AddAttachment(modelName, nullptr, tag, nullptr, true);
}
