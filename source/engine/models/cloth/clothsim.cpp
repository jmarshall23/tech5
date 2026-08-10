#include "models/cloth/clothsim.h"

#include "models/cloth/declcloth.h"
#include "models/cloth/jobs/clothgen.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>

idClothSim::DebugDrawCallback idClothSim::debugDrawCallback = nullptr;

namespace {

idVec3 TransformPoint(const idVec3& origin, const idMat3& axis,
    const idVec3& point) {
    return origin + axis[0] * point.x + axis[1] * point.y +
        axis[2] * point.z;
}

idVec3 InverseTransformPoint(const idVec3& origin, const idMat3& axis,
    const idVec3& point) {
    const idVec3 delta = point - origin;
    return idVec3(delta.Dot(axis[0]), delta.Dot(axis[1]),
        delta.Dot(axis[2]));
}

void InitializeSimulation(idClothSim& simulation,
    const idDeclCloth* clothSystem) {
    simulation.clothDecl = clothSystem;
    simulation.width = 0;
    simulation.height = 0;
    simulation.hSpacing = 0.0f;
    simulation.vSpacing = 0.0f;
    simulation.origin.Zero();
    simulation.axis = idMat3(1.0f);
    simulation.windDirection.Zero();
    simulation.gravity.Set(0.0f, 0.0f, -1.0f);
    simulation.numIterations = 1;
    simulation.timeDelta = 0.016f;
    simulation.cloth = nullptr;
    simulation.numClothParticles = 0;
    simulation.currentDeferred = 0;
    simulation.clothBoundsFromJob = new (std::nothrow) idBounds{};
    simulation.clothBounds = idBounds{};
    simulation.clothParms = new (std::nothrow) clothParms_t{};
    simulation.isRect = false;
    simulation.collisionPlane[0] = idPlane(0.0f, 0.0f, 0.0f, 0.0f);
    simulation.collisionPlane[1] = idPlane(0.0f, 0.0f, 0.0f, 0.0f);
}

void AllocateParticles(idClothSim& simulation, int count) {
    delete[] simulation.cloth;
    simulation.cloth = nullptr;
    simulation.numClothParticles = (std::max)(0, count);
    if (simulation.numClothParticles == 0) {
        return;
    }
    simulation.cloth = new (std::nothrow)
        idClothParticle[simulation.numClothParticles];
    if (simulation.cloth == nullptr) {
        simulation.numClothParticles = 0;
        return;
    }
    for (int index = 0; index < simulation.numClothParticles; ++index) {
        simulation.cloth[index].Reset();
    }
}

void AppendSpring(idClothSim& simulation, int first, int second,
    bool band = false, bool edge = false) {
    if (simulation.cloth == nullptr || first < 0 || second < 0 ||
        first >= simulation.numClothParticles ||
        second >= simulation.numClothParticles || first == second) {
        return;
    }
    idClothSpring* spring = simulation.springs.Alloc();
    if (spring != nullptr) {
        const float friction = simulation.clothDecl != nullptr
            ? simulation.clothDecl->friction : 0.0f;
        spring->Init(friction, simulation.cloth, first, second, band, edge);
    }
}

void AppendGenericSpring(idClothSim& simulation, int first, int second) {
    if (simulation.cloth == nullptr || first < 0 || second < 0 ||
        first >= simulation.numClothParticles ||
        second >= simulation.numClothParticles || first == second) {
        return;
    }
    idClothSpring* spring = simulation.springs.Alloc();
    if (spring != nullptr) {
        const idDeclCloth* decl = simulation.clothDecl;
        const float length = (simulation.cloth[second].origin -
            simulation.cloth[first].origin).Length();
        spring->Init2(first, second, length,
            decl != nullptr ? decl->springFriction : 0.0f,
            decl != nullptr ? decl->springMaxLengthMultiplier : 1.0f);
    }
}

} // namespace

idClothSim::idClothSim(const idDeclCloth* clothSystem) {
    InitializeSimulation(*this, clothSystem);
    if (clothSystem == nullptr) {
        return;
    }
    switch (clothSystem->type) {
        case CLOTH_ROPE:
            GenerateRope();
            break;
        case CLOTH_SQUARE:
        case CLOTH_FLAG:
            GenerateSquare();
            break;
        case CLOTH_GENERIC:
            GenerateGeneric();
            break;
        default:
            break;
    }
}

idClothSim::idClothSim(int requestedWidth, int requestedHeight,
    float horizontalSpacing, float verticalSpacing,
    const idDeclCloth* clothSystem, bool rect) {
    InitializeSimulation(*this, clothSystem);
    width = (std::max)(1, requestedWidth);
    hSpacing = horizontalSpacing;
    vSpacing = verticalSpacing;
    isRect = rect;
    if (rect) {
        height = (std::max)(1, requestedHeight);
        AllocateParticles(*this, width * height);
        GenerateRect(clothSystem);
    } else {
        if ((width & 1) == 0) {
            ++width;
        }
        height = (width + 1) / 2;
        AllocateParticles(*this, height * height);
        GenerateTriangle(clothSystem);
    }
}

idClothSim::~idClothSim() {
    delete[] cloth;
    delete clothBoundsFromJob;
    delete clothParms;
}

void idClothSim::SetDebugDrawCallback(DebugDrawCallback callback) {
    debugDrawCallback = callback;
}

void idClothSim::DebugDraw(const idVec3& debugOrigin,
        const idMat3& debugAxis, idRenderWorld* const world,
        const int mode) {
    if (debugDrawCallback != nullptr)
        debugDrawCallback(*this, debugOrigin, debugAxis, world, mode);
}

void idClothSim::Reset() {
    for (int index = 0; index < numClothParticles; ++index) {
        cloth[index].state = 0;
    }
}

int idClothSim::ResolveParticleIndex(int publicIndex) const {
    if (publicIndex < 0) {
        return -1;
    }
    if (clothDecl == nullptr || clothDecl->type != CLOTH_ROPE) {
        return publicIndex < numClothParticles ? publicIndex : -1;
    }
    if (publicIndex >= clothDecl->ropeData.Num()) {
        return -1;
    }
    int offset = 0;
    for (int index = 0; index < publicIndex; ++index) {
        offset += clothDecl->ropeData[index].positions.Num();
    }
    return offset < numClothParticles ? offset : -1;
}

void idClothSim::SetOriginAxis(const idVec3& newOrigin,
    const idMat3& newAxis, bool updateParticles) {
    const idVec3 oldOrigin = origin;
    const idMat3 oldAxis = axis;
    origin = newOrigin;
    axis = newAxis;
    if (!updateParticles || cloth == nullptr) {
        return;
    }
    for (int index = 0; index < numClothParticles; ++index) {
        const idVec3 local = InverseTransformPoint(oldOrigin, oldAxis,
            cloth[index].origin);
        cloth[index].origin = TransformPoint(newOrigin, newAxis, local);
        cloth[index].lastOrigin = cloth[index].origin;
        cloth[index].axis = newAxis;
    }
}

void idClothSim::SetAnchor(int index, bool temporaryAnchor) {
    const int particleIndex = ResolveParticleIndex(index);
    if (particleIndex >= 0) {
        cloth[particleIndex].anchored = temporaryAnchor ? 2u : 1u;
    }
}

void idClothSim::SetAnchorPosition(int index, const idVec3& position) {
    const int particleIndex = ResolveParticleIndex(index);
    if (particleIndex >= 0) {
        cloth[particleIndex].origin = position;
        cloth[particleIndex].lastOrigin = position;
    }
}

void idClothSim::SetAnchorAxis(int index, const idMat3& modelAxis) {
    const int particleIndex = ResolveParticleIndex(index);
    if (particleIndex >= 0) {
        cloth[particleIndex].axis = modelAxis;
    }
}

void idClothSim::AddCollisionSphere(const idSphere& sphere,
    bool permanent) {
    idList<idSphere, 81>& temporary =
        temporaryCollisionSpheres[currentDeferred];
    if (permanentCollisionSpheres.Num() + temporary.Num() >= 1024) {
        return;
    }
    if (permanent) {
        permanentCollisionSpheres.Append(sphere);
    } else {
        temporary.Append(sphere);
    }
}

void idClothSim::AddWeaponTrace(const idVec3& start,
    const idVec3& direction, float strength, bool causesHoles) {
    clothWeaponTrace_t* trace = weaponTraces[currentDeferred].Alloc();
    if (trace == nullptr) {
        return;
    }
    trace->start = start;
    trace->dir = direction;
    trace->strength = strength;
    trace->causesHoles = causesHoles;
}

void idClothSim::GetRopeParticleOriginAxis(int index,
    idList<idVec3, 5>& origins, idList<idMat3, 5>& orientations) const {
    origins.Clear();
    orientations.Clear();
    if (clothDecl == nullptr || clothDecl->type != CLOTH_ROPE ||
        index < 0 || index >= clothDecl->ropeData.Num()) {
        return;
    }
    int offset = 0;
    for (int rope = 0; rope < index; ++rope) {
        offset += clothDecl->ropeData[rope].positions.Num();
    }
    const int count = clothDecl->ropeData[index].positions.Num();
    if (!origins.SetNum(count) || !orientations.SetNum(count)) {
        origins.Clear();
        orientations.Clear();
        return;
    }
    for (int point = 0; point < count && offset + point <
         numClothParticles; ++point) {
        origins[point] = cloth[offset + point].origin;
        orientations[point] = cloth[offset + point].axis;
    }
}

void idClothSim::GenerateGeneric() {
    if (clothDecl == nullptr || clothDecl->particleData.Num() == 0) {
        return;
    }
    width = clothDecl->particleData.Num();
    height = 1;
    isRect = false;
    AllocateParticles(*this, width);
    springs.Clear();
    for (int index = 0; index < numClothParticles; ++index) {
        const idDeclCloth::particleInfo_t& info =
            clothDecl->particleData[index];
        cloth[index].origin = TransformPoint(origin, axis, info.position);
        cloth[index].lastOrigin = cloth[index].origin;
        cloth[index].mass = clothDecl->mass;
        cloth[index].anchored = info.anchored ? 1u : 0u;
        cloth[index].neighbors[0] = static_cast<std::uint8_t>(
            info.forwardIndex >= 0 && info.forwardIndex < width
                ? info.forwardIndex : index);
        cloth[index].neighbors[1] = static_cast<std::uint8_t>(
            info.rightIndex >= 0 && info.rightIndex < width
                ? info.rightIndex : index);
        cloth[index].neighbors[2] = static_cast<std::uint8_t>(index);
        cloth[index].neighbors[3] = static_cast<std::uint8_t>(index);
    }
    for (int index = 0; index < clothDecl->springData.Num(); ++index) {
        AppendGenericSpring(*this, clothDecl->springData[index].index1,
            clothDecl->springData[index].index2);
    }
}

void idClothSim::GenerateRope() {
    if (clothDecl == nullptr || clothDecl->ropeData.Num() == 0) {
        return;
    }
    int totalParticles = 0;
    for (int rope = 0; rope < clothDecl->ropeData.Num(); ++rope) {
        totalParticles += clothDecl->ropeData[rope].positions.Num();
    }
    width = totalParticles;
    height = 1;
    isRect = false;
    AllocateParticles(*this, totalParticles);
    springs.Clear();
    int offset = 0;
    for (int rope = 0; rope < clothDecl->ropeData.Num(); ++rope) {
        const idDeclCloth::ropeInfo& info = clothDecl->ropeData[rope];
        for (int point = 0; point < info.positions.Num(); ++point) {
            idClothParticle& particle = cloth[offset + point];
            particle.origin = TransformPoint(origin, axis,
                info.positions[point]);
            particle.lastOrigin = particle.origin;
            particle.mass = clothDecl->mass;
            if (point < info.inverseAxis.Num()) {
                particle.axis = info.inverseAxis[point];
            }
            if (point < info.indexOfJointToAttachTo.Num() &&
                info.indexOfJointToAttachTo[point].IsValid()) {
                particle.anchored = 1;
            }
            if (point > 0) {
                AppendGenericSpring(*this, offset + point - 1,
                    offset + point);
            }
        }
        offset += info.positions.Num();
    }
}

void idClothSim::GenerateSquare() {
    if (clothDecl == nullptr) {
        return;
    }
    width = (std::max)(1, clothDecl->width);
    height = (std::max)(1, clothDecl->height);
    hSpacing = clothDecl->hSpacing;
    vSpacing = clothDecl->vSpacing;
    isRect = true;
    AllocateParticles(*this, width * height);
    GenerateRect(clothDecl);
}

void idClothSim::GenerateRect(const idDeclCloth* clothSystem) {
    if (cloth == nullptr || clothSystem == nullptr) {
        return;
    }
    springs.Clear();
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width; ++column) {
            const int index = row * width + column;
            idClothParticle& particle = cloth[index];
            const idVec3 local(column * hSpacing, row * vSpacing, 0.0f);
            particle.origin = TransformPoint(origin, axis, local);
            particle.lastOrigin = particle.origin;
            particle.mass = clothSystem->mass;
            particle.neighbors[0] = static_cast<std::uint8_t>(
                row > 0 ? index - width : index);
            particle.neighbors[1] = static_cast<std::uint8_t>(
                column + 1 < width ? index + 1 : index);
            particle.neighbors[2] = static_cast<std::uint8_t>(
                row + 1 < height ? index + width : index);
            particle.neighbors[3] = static_cast<std::uint8_t>(
                column > 0 ? index - 1 : index);

            if (column + 1 < width) {
                AppendSpring(*this, index, index + 1);
            }
            if (row + 1 < height) {
                AppendSpring(*this, index, index + width);
            }
            if (clothSystem->springType != CLOTH_SPRING_QUAD &&
                row + 1 < height) {
                if (column + 1 < width) {
                    AppendSpring(*this, index, index + width + 1);
                }
                if (column > 0) {
                    AppendSpring(*this, index, index + width - 1);
                }
            }
            if (clothSystem->springType == CLOTH_SPRING_BANDED) {
                if (column + 2 < width) {
                    AppendSpring(*this, index, index + 2, true, true);
                }
                if (row + 2 < height) {
                    AppendSpring(*this, index, index + width * 2,
                        true, true);
                }
            }
        }
    }
}

void idClothSim::GenerateTriangle(const idDeclCloth* clothSystem) {
    if (cloth == nullptr || clothSystem == nullptr) {
        return;
    }
    springs.Clear();
    for (int row = 0; row < height; ++row) {
        const int count = row * 2 + 1;
        const int rowStart = row * row;
        for (int column = 0; column < count; ++column) {
            const int index = rowStart + column;
            const float centeredColumn = static_cast<float>(column - row);
            const idVec3 local(centeredColumn * hSpacing,
                row * vSpacing, 0.0f);
            cloth[index].origin = TransformPoint(origin, axis, local);
            cloth[index].lastOrigin = cloth[index].origin;
            cloth[index].mass = clothSystem->mass;
            if (column > 0) {
                AppendSpring(*this, index - 1, index);
            }
            if (row > 0) {
                const int previousStart = (row - 1) * (row - 1);
                if (column > 0) {
                    AppendSpring(*this, previousStart + column - 1,
                        index);
                }
                if (column < count - 1) {
                    AppendSpring(*this, previousStart + column, index);
                }
            }
        }
    }
}

void idClothSim::Swap() {
    currentDeferred ^= 1;
    temporaryCollisionSpheres[currentDeferred].Clear();
    weaponTraces[currentDeferred].Clear();
    collisionPlane[currentDeferred] = idPlane(0.0f, 0.0f, 0.0f, 0.0f);
    if (clothBoundsFromJob != nullptr) {
        clothBounds = *clothBoundsFromJob;
    }
    for (int index = 0; index < numClothParticles; ++index) {
        if (cloth[index].anchored == 2) {
            cloth[index].anchored = 0;
        }
    }
}

void idClothSim::Run(void*) {
    if (clothParms == nullptr || cloth == nullptr ||
        numClothParticles <= 0 || numClothParticles > 100) {
        return;
    }
    idList<idSphere, 81>& collisions =
        temporaryCollisionSpheres[currentDeferred];
    for (int index = 0; index < permanentCollisionSpheres.Num(); ++index) {
        if (collisions.Num() >= 1024) {
            break;
        }
        collisions.Append(permanentCollisionSpheres[index]);
    }

    *clothParms = clothParms_t{};
    clothParms->type = clothDecl != nullptr ? clothDecl->type : CLOTH_NONE;
    clothParms->cloth = cloth;
    clothParms->numClothParticles = numClothParticles;
    clothParms->springs = springs.Ptr();
    clothParms->numSprings = springs.Num();
    clothParms->collisions = collisions.Ptr();
    clothParms->numCollisions = collisions.Num();
    clothParms->weaponTraces = weaponTraces[currentDeferred].Ptr();
    clothParms->numWeaponTraces = weaponTraces[currentDeferred].Num();
    clothParms->vertices = nullptr;
    clothParms->bounds = clothBoundsFromJob;
    clothParms->org = origin;
    clothParms->axis = axis;
    clothParms->friction = clothDecl != nullptr ? clothDecl->friction : 0.0f;
    clothParms->gravity.Set(0.0f, 0.0f,
        clothDecl != nullptr ? clothDecl->gravity : -1.0f);
    clothParms->windDirection = windDirection;
    clothParms->collisionPlane = collisionPlane[currentDeferred];
    clothParms->hasCollisionPlane =
        collisionPlane[currentDeferred].Normal().LengthSqr() > 0.0f;
    clothParms->collisionFriction = clothDecl != nullptr
        ? clothDecl->collisionFriction : 0.0f;
    clothParms->width = width;
    clothParms->height = height;
    clothParms->vSpacing = vSpacing;
    clothParms->hSpacing = hSpacing;
    clothParms->timeDelta = timeDelta;
    clothParms->numIterations = (std::max)(1, numIterations);
    clothParms->rect = isRect;
    ClothGenJob(*clothParms);
    Swap();
}
