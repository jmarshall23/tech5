#include "game/entities/clothsimmanager.h"

#include <algorithm>
#include <cmath>

namespace {
constexpr float kDirectionEpsilon = 1.1920929e-7f;

idClothSimManagerServices defaultClothManagerServices;
idClothSimManagerServices* clothManagerServices =
    &defaultClothManagerServices;

idVec3 ParticlePosition(const idClothSim& simulation, const int index) {
    if (index < 0 || index >= simulation.numClothParticles
            || simulation.cloth == nullptr) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    return simulation.cloth[index].origin;
}

idVec3 UnitDirection(const idVec3& from, const idVec3& to,
        const idVec3& fallback) {
    idVec3 direction = to - from;
    if (direction.NormalizeFast() <= kDirectionEpsilon) {
        direction = fallback;
        direction.NormalizeFast();
    }
    return direction;
}

idMat3 SquareParticleAxis(const idClothSim& simulation, const int row,
        const int column, const int width, const int height) {
    const int index = row * width + column;
    const idVec3 position = ParticlePosition(simulation, index);
    const int vertical = row + 1 < height ? index + width : index - width;
    const int horizontal = column + 1 < width ? index + 1 : index - 1;
    const idVec3 forward = row + 1 < height
        ? UnitDirection(position, ParticlePosition(simulation, vertical),
            idVec3(0.0f, 0.0f, 1.0f))
        : UnitDirection(ParticlePosition(simulation, vertical), position,
            idVec3(0.0f, 0.0f, 1.0f));
    const idVec3 right = column + 1 < width
        ? UnitDirection(position, ParticlePosition(simulation, horizontal),
            idVec3(1.0f, 0.0f, 0.0f))
        : UnitDirection(ParticlePosition(simulation, horizontal), position,
            idVec3(1.0f, 0.0f, 0.0f));
    idVec3 normal = right.Cross(forward);
    if (normal.NormalizeFast() <= kDirectionEpsilon) {
        normal.Set(0.0f, 1.0f, 0.0f);
    }
    idVec3 correctedRight = forward.Cross(normal);
    correctedRight.NormalizeFast();
    return idMat3(forward.x, forward.y, forward.z,
        correctedRight.x, correctedRight.y, correctedRight.z,
        normal.x, normal.y, normal.z);
}

idMat3 GenericParticleAxis(const idClothSim& simulation,
        const idDeclCloth::particleInfo_t& particle, const int index) {
    if (particle.forwardIndex < 0 && particle.rightIndex < 0) {
        return idMat3(1.0f);
    }
    const idVec3 position = ParticlePosition(simulation, index);
    const idVec3 forward = UnitDirection(position,
        ParticlePosition(simulation, particle.forwardIndex),
        idVec3(0.0f, 1.0f, 0.0f));
    idVec3 reference;
    if (particle.rightIndex < 0) {
        reference.Set(0.0f, 0.0f, 1.0f);
    } else {
        reference = UnitDirection(
            ParticlePosition(simulation, particle.rightIndex), position,
            idVec3(0.0f, 0.0f, 1.0f));
    }
    idVec3 first = reference.Cross(forward);
    if (first.NormalizeFast() <= kDirectionEpsilon) {
        first.Set(1.0f, 0.0f, 0.0f);
    }
    idVec3 third = forward.Cross(first);
    third.NormalizeFast();
    return idMat3(first.x, first.y, first.z,
        forward.x, forward.y, forward.z,
        third.x, third.y, third.z);
}
}

clothManagerWeaponTrace_t::clothManagerWeaponTrace_t()
    : start(0.0f, 0.0f, 0.0f)
    , direction(0.0f, 0.0f, 0.0f)
    , strength(0.0f)
    , causesHoles(false)
    , type(0) {
}

idClothSimManager::clothSims_t::clothSims_t()
    : state(READY_TO_USE), clothSim(nullptr) {
}

idClothSimManager::idClothSimManager()
    : cloth() {
}

void idClothSimManager::SetServices(
        idClothSimManagerServices* const services) {
    clothManagerServices = services == nullptr
        ? &defaultClothManagerServices : services;
}

idClothSimManagerServices& idClothSimManager::Services() {
    return *clothManagerServices;
}

// Retail: 0x82C16AD0 ?Update@idClothSimManager@@QAAXXZ
void idClothSimManager::Update() {
    for (int index = 0; index < cloth.Num(); ++index) {
        if (cloth[index].state == clothSims_t::READY_TO_FREE) {
            cloth[index].state = clothSims_t::READY_TO_USE;
        }
    }
}

// Retail: 0x82C16B18 ?FreeCloth@idClothSimManager@@QAAXPAVidClothSim@@@Z
void idClothSimManager::FreeCloth(idClothSim* const clothSim) {
    if (clothSim == nullptr) {
        return;
    }
    for (int index = 0; index < cloth.Num(); ++index) {
        if (cloth[index].clothSim == clothSim) {
            cloth[index].state = clothSims_t::READY_TO_FREE;
            return;
        }
    }
}

// Retail: 0x82C16B70 ?ReserveCloth@idClothSimManager@@QAAPAVidClothSim@@PBVidDeclCloth@@@Z
idClothSim* idClothSimManager::ReserveCloth(
        const idDeclCloth* const declaration) {
    if (declaration == nullptr) {
        Services().Error(
            "idClothSimManager::ReserveCloth called with null declaration");
        return nullptr;
    }
    for (int index = 0; index < cloth.Num(); ++index) {
        clothSims_t& entry = cloth[index];
        if (entry.clothSim != nullptr
                && entry.clothSim->clothDecl == declaration
                && entry.state == clothSims_t::READY_TO_USE) {
            entry.state = clothSims_t::IN_USE;
            entry.clothSim->Reset();
            return entry.clothSim;
        }
    }
    return nullptr;
}

// Retail: 0x82C16C40 ??1idClothSimManager@@QAA@XZ
idClothSimManager::~idClothSimManager() {
    for (int index = 0; index < cloth.Num(); ++index) {
        delete cloth[index].clothSim;
        cloth[index].clothSim = nullptr;
    }
    cloth.Clear();
}

// Retail: 0x82C16D30 ?UpdateJointsWithClothSim@idClothSimManager@@QAAXPAVidTreeAnimator@@PAVidClothSim@@@Z
void idClothSimManager::UpdateJointsWithClothSim(
        idTreeAnimator* const animator, idClothSim* const simulation) {
    if (animator == nullptr || simulation == nullptr
            || simulation->clothDecl == nullptr) {
        Services().Warn(
            "idClothSimManager::UpdateJointsWithClothSim called with null input");
        return;
    }
    idVec3 modelOrigin;
    idMat3 modelAxis(1.0f);
    if (!Services().GetAnimatorTransform(
            animator, modelOrigin, modelAxis)) {
        return;
    }
    const idMat3 inverseModelAxis = modelAxis.Transpose();
    const idDeclCloth& declaration = *simulation->clothDecl;

    if (declaration.type == CLOTH_SQUARE) {
        for (int index = 0; index < declaration.particleData.Num(); ++index) {
            const idDeclCloth::particleInfo_t& particle =
                declaration.particleData[index];
            if (particle.anchored) {
                idVec3 jointOrigin;
                idMat3 jointAxis;
                if (Services().GetJointWorldTransform(animator,
                        particle.jointIndex.Get(),
                        jointOrigin, jointAxis)) {
                    simulation->SetAnchorPosition(index, jointOrigin);
                }
            }
        }
        for (int row = 0; row < declaration.height; ++row) {
            for (int column = 0; column < declaration.width; ++column) {
                const int index = row * declaration.width + column;
                if (index >= declaration.particleData.Num()) {
                    continue;
                }
                const idDeclCloth::particleInfo_t& particle =
                    declaration.particleData[index];
                const idVec3 localPosition = inverseModelAxis
                    * (ParticlePosition(*simulation, index) - modelOrigin);
                const idMat3 localAxis = SquareParticleAxis(*simulation,
                    row, column, declaration.width, declaration.height)
                        * inverseModelAxis;
                Services().SetJointAxis(animator,
                    particle.jointIndex.Get(), localAxis);
                if (!particle.anchored) {
                    Services().SetJointPosition(animator,
                        particle.jointIndex.Get(), localPosition);
                }
            }
        }
    } else if (declaration.type == CLOTH_GENERIC) {
        for (int index = 0; index < declaration.particleData.Num(); ++index) {
            const idDeclCloth::particleInfo_t& particle =
                declaration.particleData[index];
            if (particle.anchored) {
                idVec3 jointOrigin;
                idMat3 jointAxis;
                if (Services().GetJointWorldTransform(animator,
                        particle.jointIndex.Get(),
                        jointOrigin, jointAxis)) {
                    simulation->SetAnchorPosition(index, jointOrigin);
                }
            }
        }
        for (int index = 1;
                index < declaration.particleData.Num(); ++index) {
            const idDeclCloth::particleInfo_t& particle =
                declaration.particleData[index];
            const idVec3 localPosition = inverseModelAxis
                * (ParticlePosition(*simulation, index) - modelOrigin);
            const idMat3 localAxis = GenericParticleAxis(
                *simulation, particle, index) * inverseModelAxis;
            Services().SetJointAxis(animator,
                particle.jointIndex.Get(), localAxis);
            Services().SetJointPosition(animator,
                particle.jointIndex.Get(), localPosition);
        }
    } else if (declaration.type == CLOTH_ROPE) {
        for (int ropeIndex = 0;
                ropeIndex < declaration.ropeData.Num(); ++ropeIndex) {
            const idDeclCloth::ropeInfo& rope =
                declaration.ropeData[ropeIndex];
            if (rope.positions.Num() > 32) {
                Services().Warn("Too many rope particles");
                continue;
            }
            idList<idVec3, 5> origins;
            idList<idMat3, 5> axes;
            simulation->GetRopeParticleOriginAxis(
                ropeIndex, origins, axes);
            const int count = (std::min)(origins.Num(),
                rope.indexOfJointToAttachTo.Num());
            for (int index = 0; index < count; ++index) {
                origins[index] = inverseModelAxis
                    * (origins[index] - modelOrigin);
                if (index < axes.Num()) {
                    axes[index] *= inverseModelAxis;
                }
                const int joint = rope.indexOfJointToAttachTo[
                    rope.indexOfJointToAttachTo.Num() - index - 1].Get();
                if (index + 1 < count && index < axes.Num()) {
                    Services().SetJointAxis(animator, joint, axes[index]);
                    Services().DebugJointAxis(origins[index], axes[index]);
                }
                Services().SetJointPosition(animator, joint, origins[index]);
            }
            simulation->SetAnchorPosition(ropeIndex, modelOrigin);
            simulation->SetAnchorAxis(ropeIndex, modelAxis);
        }
    }
    Services().BlendTree(animator);
}

// Retail: 0x82C17E30 ?UpdateWeaponTraces@idClothSimManager@@QAAXPAVidClothSim@@@Z
void idClothSimManager::UpdateWeaponTraces(idClothSim* const simulation) {
    if (simulation == nullptr) {
        return;
    }
    idBounds bounds = simulation->clothBounds;
    bounds.b[0] = bounds.b[0] - idVec3(5.0f, 5.0f, 5.0f);
    bounds.b[1] = bounds.b[1] + idVec3(5.0f, 5.0f, 5.0f);
    idList<clothManagerWeaponTrace_t, 5> traces;
    Services().GatherWeaponTraces(bounds, traces);
    for (int index = 0; index < traces.Num(); ++index) {
        const clothManagerWeaponTrace_t& trace = traces[index];
        if (trace.type != 2) {
            simulation->AddWeaponTrace(trace.start, trace.direction,
                trace.strength, trace.causesHoles);
        }
    }
}

// Retail: 0x82C17FE0 ?GetGeneralOriginAxis@idClothSimManager@@QAAXPAVidClothSim@@AAVidVec3@@AAVidMat3@@@Z
void idClothSimManager::GetGeneralOriginAxis(
        idClothSim* const simulation, idVec3& origin, idMat3& axis) {
    origin.Zero();
    axis = idMat3(1.0f);
    if (simulation == nullptr) {
        Services().Warn(
            "idClothSimManager::GetGeneralOriginAxis called with null cloth");
        return;
    }
    if (simulation->clothDecl == nullptr
            || simulation->clothDecl->type != CLOTH_ROPE
            || simulation->clothDecl->ropeData.Num() == 0) {
        return;
    }
    if (simulation->clothDecl->ropeData[0].positions.Num() > 32) {
        Services().Warn("Too many rope particles");
        return;
    }
    idList<idVec3, 5> origins;
    idList<idMat3, 5> axes;
    simulation->GetRopeParticleOriginAxis(0, origins, axes);
    if (origins.Num() > 0) {
        origin = origins[0];
    }
    if (axes.Num() > 0) {
        axis = axes[0];
        axis.OrthoNormalizeSelf();
    }
}

// Retail: 0x82C18228 ?AddCloth@idClothSimManager@@QAAXPBVidDeclCloth@@@Z
void idClothSimManager::AddCloth(const idDeclCloth* const declaration) {
    if (declaration == nullptr) {
        Services().Error(
            "idClothSimManager::AddCloth called with null declaration");
        return;
    }
    if (cloth.Num() >= cloth.Max()) {
        return;
    }
    int matching = 0;
    for (int index = 0; index < cloth.Num(); ++index) {
        if (cloth[index].clothSim != nullptr
                && cloth[index].clothSim->clothDecl == declaration) {
            ++matching;
        }
    }
    if (matching >= 4) {
        return;
    }
    clothSims_t entry;
    entry.clothSim = new idClothSim(declaration);
    entry.state = clothSims_t::READY_TO_USE;
    cloth.Append(entry);
}

// Retail: 0x82C18324 $LN30_1
void Tungsten_ClothSimAllocationFailure(idClothSim* const allocation) {
    delete allocation;
}
