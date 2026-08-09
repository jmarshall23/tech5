#pragma once

#include "cm/jobs/collisionquery.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>

class idAASClipLink;
class idClip;
class idCollisionModel;
class idMaterial;
class idSerializer;
class idTraceModel;
class idTreeAnimator;
struct clipSector_t;

enum clipMode_t : int {
    CLIPMODE_INTERSECT = 0,
    CLIPMODE_UNION = 1,
    CLIPMODE_DIFFERENCE = 2,
    CLIPMODE_XOR = 3
};

struct clipLink_t {
    class idClipModel* clipModel;
    clipSector_t* sector;
    clipLink_t* prevInSector;
    clipLink_t* nextInSector;
    clipLink_t* nextLink;
};

class idClipModel {
public:
    idClipModel();
    idClipModel(idClip* ownerClip, const char* modelName,
        const idMaterial* material = nullptr);
    idClipModel(idClip* ownerClip, idCollisionModel* model);
    idClipModel(idClip* ownerClip, const idTraceModel* traceModel,
        int traceModelIndex, const idMaterial* material = nullptr);
    idClipModel(idClip* ownerClip, idTreeAnimator* animator);
    idClipModel(idClip* ownerClip, const idClipModel& other);
    virtual ~idClipModel();

    void Delete();
    void Unlink();
    void Link();
    void Link(int entityNum, int ownerNum, int physicsBodyId,
        const idVec3& newOrigin, const idMat3& newAxis);
    void Link(int entityNum, int ownerNum, int physicsBodyId,
        const idVec3& newOrigin, const idMat3& newAxis,
        const idBounds& newBounds);
    void SetContents(int newContents);
    int GetContents() const { return contents; }
    void Enable() { enabled = true; }
    void Disable() { enabled = false; }
    bool IsEnabled() const { return enabled; }
    bool IsLinked() const { return clipLinks != nullptr; }
    bool IsDeleted() const { return deleted; }
    int GetEntityNumber() const { return entityNumber; }
    int GetOwnerNumber() const { return ownerNumber; }
    int GetPhysicsId() const { return physicsId; }
    int GetBodyId() const { return bodyId; }
    int GetBodyMask() const { return bodyMask; }
    void SetBodyMask(int mask) { bodyMask = mask; }
    const idVec3& GetOrigin() const { return origin; }
    const idMat3& GetAxis() const { return axis; }
    const idBounds& GetBounds() const { return bounds; }
    const idBounds& GetAbsBounds() const { return absBounds; }
    idCollisionModel* GetCollisionModel() const;
    const idTraceModel* GetTraceModel(int index = 0) const;
    int GetNumTraceModels() const { return traceModels.Num(); }
    void GetMassProperties(float density, float& mass,
        idVec3& centerOfMass, idMat3& inertiaTensor) const;
    void Serialize(idSerializer& serializer);

    bool enabled;
    bool deleted;
    int entityNumber;
    int ownerNumber;
    int physicsId;
    int bodyId;
    int bodyMask;
    idVec3 origin;
    idMat3 axis;
    idBounds bounds;
    idBounds absBounds;
    int contents;
    idCollisionModel* collisionModel;
    idList<int, 13> traceModels;
    idTreeAnimator* animatedModel;
    idClip* clip;
    clipLink_t* clipLinks;
    idCollisionQuery collisionQuery;
    int touchCount;
    idClipModel* nextDeleted;
    idAASClipLink* aasLinks[8];

private:
    idCollisionModel* NoTraceModelWarning() const;
    void Init(idClip* ownerClip);
    void FreeModel();
    bool LoadCollisionModel(const char* modelName,
        const idMaterial* material);
    void LoadCollisionModel(idCollisionModel* model);
    void LoadTraceModel(const idTraceModel* traceModel, int traceModelIndex,
        const idMaterial* material);
    void LoadAnimator(idTreeAnimator* animator);
    void Link_r(clipSector_t* sector);
};

class idStrClipModel : public idAtomicString {
public:
    using idAtomicString::idAtomicString;
};

class idClipModelInfo {
public:
    enum clipModelType_t : int {
        CLIPMODEL_NONE = 0,
        CLIPMODEL_RENDERMODEL = 1,
        CLIPMODEL_CUSTOM = 2,
        CLIPMODEL_BOX = 3,
        CLIPMODEL_CYLINDER = 4,
        CLIPMODEL_CONE = 5,
        CLIPMODEL_BOUNDINGBOX = 6
    };

    clipModelType_t type;
    idVec3 size;
    idVec3 offset;
    int numSides;
    idStrClipModel clipModelName;
    bool clipShrink;
    bool allowInline;
    bool softObstacle;
    const idMaterial* overrideClipMaterial;
};

struct cbp_model_s {
    int state[16];
    int count0[16];
    int count1[16];
};

static_assert(sizeof(clipLink_t) == sizeof(void*) * 5,
    "Recovered clip-link ABI changed");
static_assert(sizeof(cbp_model_s) == 192,
    "Recovered clip-model predictor ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idClipModel) == 216,
    "Recovered idClipModel ABI changed");
static_assert(sizeof(idClipModelInfo) == 44,
    "Recovered idClipModelInfo ABI changed");
#endif
