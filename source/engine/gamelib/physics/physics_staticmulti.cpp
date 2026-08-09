#include "gamelib/physics/physics_staticmulti.h"

#include "gamelib/physics/clip.h"
#include "gamelib/physics/clipmodel.h"
#include "idlib/lib_print.h"
#include "idlib/math/rotation.h"

#include <algorithm>
#include <cstring>

bool GameLib_GetMasterPhysicsTransform(idPhysicsCallbacks* callbacks,
    idVec3& origin, idMat3& axis);

namespace {

const idVec3 kZeroVector(0.0f, 0.0f, 0.0f);
const idVec3 kDownVector(0.0f, 0.0f, -1.0f);
const idMat3 kIdentityAxis(1.0f);
const idBounds kZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};

staticPState_t DefaultState() {
    staticPState_t state{};
    state.worldOrigin.Zero();
    state.worldAxis = idMat3(1.0f);
    state.localOrigin.Zero();
    state.localAxis = idMat3(1.0f);
    return state;
}

void AddBounds(idBounds& destination, const idBounds& source,
    bool& initialized) {
    if (!initialized) {
        destination = source;
        initialized = true;
        return;
    }
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(destination[0][axis],
            source[0][axis]);
        destination[1][axis] = (std::max)(destination[1][axis],
            source[1][axis]);
    }
}

} // namespace

idPhysics_StaticMulti::idPhysics_StaticMulti()
    : idPhysics()
    , clipModels(16)
    , mass(16)
    , bounds(kZeroBounds)
    , absBounds(kZeroBounds)
    , hasMaster(false)
    , isOrientated(false)
    , current(16) {
    type = PHYSICS_STATICMULTI;
    clipModels.SetNum(1);
    mass.SetNum(1);
    current.SetNum(1);
    clipModels[0] = nullptr;
    mass[0] = 1.0f;
    current[0] = DefaultState();
}

idPhysics_StaticMulti::~idPhysics_StaticMulti() {
    for (int index = 0; index < clipModels.Num(); ++index) {
        if (clipModels[index] != nullptr) clipModels[index]->Delete();
        clipModels[index] = nullptr;
    }
}

bool idPhysics_StaticMulti::IsValidId(const int id) const {
    return id >= 0 && id < clipModels.Num();
}

void idPhysics_StaticMulti::LinkModel(const int id) {
    if (!IsValidId(id) || clipModels[id] == nullptr) return;
    clipModels[id]->Link(GetEntityNumber(), GetEntityNumber(), id,
        current[id].worldOrigin, current[id].worldAxis);
}

void idPhysics_StaticMulti::SetClipModel(idClipModel* const model,
        const float density, const int id, const bool freeOld) {
    if (id < 0) return;
    if (id >= clipModels.Num()) {
        const int oldNum = clipModels.Num();
        const int newNum = id + 1;
        if (!clipModels.SetNum(newNum) || !mass.SetNum(newNum)
                || !current.SetNum(newNum)) return;
        for (int index = oldNum; index < newNum; ++index) {
            clipModels[index] = nullptr;
            mass[index] = 1.0f;
            current[index] = DefaultState();
        }
    }
    if (clipModels[id] != nullptr && clipModels[id] != model && freeOld)
        clipModels[id]->Delete();
    clipModels[id] = model;
    if (model != nullptr) {
        if (model->GetNumTraceModels() != 0) {
            idVec3 centerOfMass;
            idMat3 inertia;
            model->GetMassProperties(density, mass[id], centerOfMass,
                inertia);
        } else {
            mass[id] = 1.0f;
        }
        LinkModel(id);
    }
    int newNum = clipModels.Num();
    while (newNum > 1 && clipModels[newNum - 1] == nullptr) --newNum;
    clipModels.SetNum(newNum);
    mass.SetNum(newNum);
    current.SetNum(newNum);
}

idClipModel* idPhysics_StaticMulti::GetClipModel(const int id) {
    if (IsValidId(id) && clipModels[id] != nullptr) return clipModels[id];
    return clip != nullptr ? clip->defaultClipModel : nullptr;
}

int idPhysics_StaticMulti::GetNumClipModels() { return clipModels.Num(); }

void idPhysics_StaticMulti::SetMass(const float newMass, const int id) {
    if (id == -1) {
        if (mass.Num() == 0) return;
        const float each = newMass / static_cast<float>(mass.Num());
        for (int index = 0; index < mass.Num(); ++index) mass[index] = each;
    } else if (IsValidId(id)) {
        mass[id] = newMass;
    }
}

float idPhysics_StaticMulti::GetMass(const int id) {
    if (id >= 0) return IsValidId(id) ? mass[id] : 0.0f;
    float total = 0.0f;
    for (int index = 0; index < mass.Num(); ++index) total += mass[index];
    return total;
}

void idPhysics_StaticMulti::SetContents(const int contents, const int id) {
    if (id == -1) {
        for (int index = 0; index < clipModels.Num(); ++index)
            if (clipModels[index] != nullptr)
                clipModels[index]->SetContents(contents);
    } else if (IsValidId(id) && clipModels[id] != nullptr) {
        clipModels[id]->SetContents(contents);
    }
}

int idPhysics_StaticMulti::GetContents(const int id) {
    if (id >= 0) return IsValidId(id) && clipModels[id] != nullptr
        ? clipModels[id]->GetContents() : 0;
    int contents = 0;
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr)
            contents |= clipModels[index]->GetContents();
    return contents;
}

void idPhysics_StaticMulti::SetClipMask(int, int) {}
int idPhysics_StaticMulti::GetClipMask(int) { return 0; }

const idBounds* idPhysics_StaticMulti::GetBounds(const int id) {
    if (IsValidId(id) && clipModels[id] != nullptr)
        return &clipModels[id]->GetBounds();
    if (id != -1) return &kZeroBounds;
    bool initialized = false;
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr)
            AddBounds(bounds, clipModels[index]->GetBounds(), initialized);
    if (!initialized) return &kZeroBounds;
    const idVec3 origin = current.Num() != 0
        ? current[0].worldOrigin : kZeroVector;
    bounds[0] = bounds[0] - origin;
    bounds[1] = bounds[1] - origin;
    return &bounds;
}

const idBounds* idPhysics_StaticMulti::GetAbsBounds(const int id) {
    if (IsValidId(id) && clipModels[id] != nullptr)
        return &clipModels[id]->GetAbsBounds();
    if (id != -1) return &kZeroBounds;
    bool initialized = false;
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr)
            AddBounds(absBounds, clipModels[index]->GetAbsBounds(),
                initialized);
    return initialized ? &absBounds : &kZeroBounds;
}

bool idPhysics_StaticMulti::Evaluate(int, int) {
    if (!hasMaster || callbacks == nullptr) return false;
    idVec3 masterOrigin;
    idMat3 masterAxis;
    if (!GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
            masterAxis)) return false;
    bool moved = false;
    for (int index = 0; index < current.Num(); ++index) {
        const idVec3 oldOrigin = current[index].worldOrigin;
        const idMat3 oldAxis = current[index].worldAxis;
        current[index].worldOrigin = masterOrigin
            + masterAxis * current[index].localOrigin;
        current[index].worldAxis = isOrientated
            ? current[index].localAxis * masterAxis
            : current[index].localAxis;
        moved = moved
            || (current[index].worldOrigin - oldOrigin).LengthSqr() != 0.0f
            || (current[index].worldAxis[0] - oldAxis[0]).LengthSqr() != 0.0f
            || (current[index].worldAxis[1] - oldAxis[1]).LengthSqr() != 0.0f
            || (current[index].worldAxis[2] - oldAxis[2]).LengthSqr() != 0.0f;
        LinkModel(index);
    }
    return moved;
}

void idPhysics_StaticMulti::SetOrigin(const idVec3* const newOrigin,
        const int id) {
    if (newOrigin == nullptr || current.Num() == 0) return;
    if (id == -1) {
        const idVec3 translation = *newOrigin - current[0].worldOrigin;
        Translate(&translation, -1);
        return;
    }
    if (!IsValidId(id)) return;
    current[id].worldOrigin = *newOrigin;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current[id].localOrigin = masterAxis.Transpose()
                * (*newOrigin - masterOrigin);
    } else {
        current[id].localOrigin = *newOrigin;
    }
    LinkModel(id);
}

void idPhysics_StaticMulti::SetAxis(const idMat3* const newAxis,
        const int id) {
    if (newAxis == nullptr || current.Num() == 0) return;
    if (id == -1) {
        const idMat3 delta = current[0].worldAxis.Transpose() * *newAxis;
        const idVec3 pivot = current[0].worldOrigin;
        for (int index = 0; index < current.Num(); ++index) {
            current[index].worldOrigin = pivot
                + delta * (current[index].worldOrigin - pivot);
            current[index].worldAxis *= delta;
            current[index].localAxis *= delta;
            LinkModel(index);
        }
        return;
    }
    if (!IsValidId(id)) return;
    current[id].worldAxis = *newAxis;
    if (hasMaster && isOrientated && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current[id].localAxis = *newAxis * masterAxis.Transpose();
    } else {
        current[id].localAxis = *newAxis;
    }
    LinkModel(id);
}

void idPhysics_StaticMulti::Translate(const idVec3* const translation,
        const int id) {
    if (translation == nullptr) return;
    const int first = id == -1 ? 0 : id;
    const int last = id == -1 ? current.Num() : id + 1;
    if (first < 0 || last > current.Num()) return;
    for (int index = first; index < last; ++index) {
        current[index].worldOrigin = current[index].worldOrigin + *translation;
        current[index].localOrigin = current[index].localOrigin + *translation;
        LinkModel(index);
    }
}

void idPhysics_StaticMulti::Rotate(const idRotation* const rotation,
        const int id) {
    if (rotation == nullptr) return;
    const int first = id == -1 ? 0 : id;
    const int last = id == -1 ? current.Num() : id + 1;
    if (first < 0 || last > current.Num()) return;
    const idMat3 rotationAxis = rotation->ToMat3();
    for (int index = first; index < last; ++index) {
        current[index].worldOrigin = *rotation * current[index].worldOrigin;
        current[index].worldAxis *= rotationAxis;
        current[index].localOrigin = *rotation * current[index].localOrigin;
        current[index].localAxis *= rotationAxis;
        LinkModel(index);
    }
}

const idVec3* idPhysics_StaticMulti::GetOrigin(const int id) {
    return IsValidId(id) ? &current[id].worldOrigin : &kZeroVector;
}
const idMat3* idPhysics_StaticMulti::GetAxis(const int id) {
    return IsValidId(id) ? &current[id].worldAxis : &kIdentityAxis;
}
const idVec3* idPhysics_StaticMulti::GetLocalOrigin(const int id) {
    return IsValidId(id) ? &current[id].localOrigin : &kZeroVector;
}
const idMat3* idPhysics_StaticMulti::GetLocalAxis(const int id) {
    return IsValidId(id) ? &current[id].localAxis : &kIdentityAxis;
}

void idPhysics_StaticMulti::SetLinearVelocity(const idVec3*, int) {}
void idPhysics_StaticMulti::SetAngularVelocity(const idVec3*, int) {}
idVec3* idPhysics_StaticMulti::GetLinearVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
idVec3* idPhysics_StaticMulti::GetAngularVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
void idPhysics_StaticMulti::SetGravity(const idVec3*) {}
const idVec3* idPhysics_StaticMulti::GetGravity() { return &kZeroVector; }
const idVec3* idPhysics_StaticMulti::GetGravityNormal() {
    return &kDownVector;
}
void idPhysics_StaticMulti::SetWaterLevel(float, int) {}
float idPhysics_StaticMulti::GetWaterLevel(int) { return 0.0f; }
void idPhysics_StaticMulti::SetWaterViscosity(float, int) {}
float idPhysics_StaticMulti::GetWaterViscosity(int) { return 0.0f; }
void idPhysics_StaticMulti::SetWaterEntNum(int) {}
int idPhysics_StaticMulti::GetWaterEntNum() { return -1; }
void idPhysics_StaticMulti::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_StaticMulti::GetWaterSurfaceWrldHeight() { return 0.0f; }
void idPhysics_StaticMulti::GetImpactInfo(int, const idVec3*,
        impactInfo_t* const info) {
    if (info != nullptr) info->Zero();
}
void idPhysics_StaticMulti::ApplyImpulse(int, const idVec3*, const idVec3*) {}
void idPhysics_StaticMulti::ApplyForce(int, const idVec3*, const idVec3*) {}
void idPhysics_StaticMulti::Activate() {}
void idPhysics_StaticMulti::PutToRest() {}
bool idPhysics_StaticMulti::IsAtRest() { return true; }
bool idPhysics_StaticMulti::IsPushable(int) { return false; }
void idPhysics_StaticMulti::SaveState() {}
void idPhysics_StaticMulti::RestoreState() {}
void idPhysics_StaticMulti::UpdateTime(int) {}

void idPhysics_StaticMulti::ClipTranslation(trace_t* const results,
        const idVec3*, const idClipModel*) {
    if (results != nullptr) std::memset(results, 0, sizeof(*results));
    idLibPrint::Warning("idPhysics_StaticMulti::ClipTranslation called");
}

void idPhysics_StaticMulti::ClipRotation(trace_t* const results,
        const idRotation*, const idClipModel*) {
    if (results != nullptr) std::memset(results, 0, sizeof(*results));
    idLibPrint::Warning("idPhysics_StaticMulti::ClipRotation called");
}

int idPhysics_StaticMulti::ClipContents(const idClipModel* const model,
        int clipMask) {
    if (clip == nullptr) return 0;
    if (clipMask == 0) clipMask = -1;
    int contents = 0;
    for (int index = 0; index < clipModels.Num(); ++index) {
        idClipModel* self = clipModels[index];
        if (self == nullptr) continue;
        trace_t result{};
        if (model != nullptr) {
            clip->ContentsModel(result, self->GetOrigin(), self,
                self->GetAxis(), clipMask, model->GetOrigin(), model,
                model->GetAxis());
        } else {
            clip->Contents(&result, self->GetOrigin(), self,
                self->GetAxis(), clipMask, 0x1FFF,
                "idPhysics_StaticMulti::ClipContents");
        }
        contents |= result.c.contentFlags;
    }
    return contents;
}

void idPhysics_StaticMulti::DisableClip() {
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr) clipModels[index]->Disable();
}
void idPhysics_StaticMulti::EnableClip() {
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr) clipModels[index]->Enable();
}
void idPhysics_StaticMulti::UnlinkClip() {
    for (int index = 0; index < clipModels.Num(); ++index)
        if (clipModels[index] != nullptr) clipModels[index]->Unlink();
}
void idPhysics_StaticMulti::LinkClip() {
    for (int index = 0; index < clipModels.Num(); ++index) LinkModel(index);
}
bool idPhysics_StaticMulti::EvaluateContacts() { return false; }
int idPhysics_StaticMulti::GetNumContacts() { return 0; }
const contactInfo_t* idPhysics_StaticMulti::GetContact(int) {
    static contactInfo_t info{};
    std::memset(&info, 0, sizeof(info));
    return &info;
}
void idPhysics_StaticMulti::ClearContacts() {}
void idPhysics_StaticMulti::AddContactPhysics(idPhysics*) {}
void idPhysics_StaticMulti::RemoveContactPhysics(idPhysics*) {}
int idPhysics_StaticMulti::GetNumContactPhysics() { return 0; }
idPhysics* idPhysics_StaticMulti::GetContactPhysics(int) { return nullptr; }
void idPhysics_StaticMulti::ActivateContactPhysics() {}
bool idPhysics_StaticMulti::HasGroundContacts() { return false; }
bool idPhysics_StaticMulti::IsGroundEntity(int) { return false; }
bool idPhysics_StaticMulti::IsGroundClipModel(int, int) { return false; }
void idPhysics_StaticMulti::SetPushed(int) {}
idVec3* idPhysics_StaticMulti::GetPushedLinearVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
idVec3* idPhysics_StaticMulti::GetPushedAngularVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}

void idPhysics_StaticMulti::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        const bindFlags_t flags) {
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        if (!hasMaster) {
            const idMat3 inverse = masterAxis->Transpose();
            for (int index = 0; index < current.Num(); ++index) {
                current[index].localOrigin = inverse
                    * (current[index].worldOrigin - *masterOrigin);
                current[index].localAxis =
                    (static_cast<int>(flags) & 1) != 0
                    ? current[index].worldAxis * inverse
                    : current[index].worldAxis;
            }
        }
        hasMaster = true;
        isOrientated = (static_cast<int>(flags) & 1) != 0;
    } else {
        hasMaster = false;
    }
}

void idPhysics_StaticMulti::SetLocalOrigin(const idVec3* const newOrigin,
        const int id) {
    if (newOrigin == nullptr || current.Num() == 0) return;
    if (id == -1) {
        if (hasMaster && callbacks != nullptr) {
            idVec3 masterOrigin;
            idMat3 masterAxis;
            if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                    masterAxis)) {
                const idVec3 target = masterOrigin + masterAxis * *newOrigin;
                const idVec3 translation = target - current[0].worldOrigin;
                Translate(&translation, -1);
            }
        } else {
            const idVec3 translation = *newOrigin - current[0].worldOrigin;
            Translate(&translation, -1);
        }
        return;
    }
    if (!IsValidId(id)) return;
    current[id].localOrigin = *newOrigin;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current[id].worldOrigin = masterOrigin + masterAxis * *newOrigin;
    } else {
        current[id].worldOrigin = *newOrigin;
    }
    LinkModel(id);
}

void idPhysics_StaticMulti::SetLocalAxis(const idMat3* const newAxis,
        const int id) {
    if (newAxis == nullptr || current.Num() == 0) return;
    if (id == -1) {
        idMat3 target = *newAxis;
        if (hasMaster && isOrientated && callbacks != nullptr) {
            idVec3 masterOrigin;
            idMat3 masterAxis;
            if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                    masterAxis)) target *= masterAxis;
        }
        SetAxis(&target, -1);
        return;
    }
    if (!IsValidId(id)) return;
    current[id].localAxis = *newAxis;
    if (hasMaster && isOrientated && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) current[id].worldAxis = *newAxis * masterAxis;
    } else {
        current[id].worldAxis = *newAxis;
    }
    LinkModel(id);
}

int idPhysics_StaticMulti::GetBlockingEntityNum() { return 0x1FFF; }
int idPhysics_StaticMulti::GetLinearEndTime() { return 0; }
int idPhysics_StaticMulti::GetAngularEndTime() { return 0; }
