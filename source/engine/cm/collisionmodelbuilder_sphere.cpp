#include "cm/collisionmodelbuilder.h"

#include "cm/collisionmodel.h"
#include "cm/jobs/spheremodel/spheremodel.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <malloc.h>

namespace {

cm_declMD6SphereExtractor_t declMD6SphereExtractor = nullptr;

int Align16(const int value) {
    return (value + 15) & ~15;
}

} // namespace

bool idCollisionModelBuilder::IsAnimatedRenderModel(
    const char* const fileName) {
    if (fileName == nullptr) {
        return false;
    }
    const char* const extension = std::strrchr(fileName, '.');
    if (extension == nullptr || extension[1] == '\0') {
        return false;
    }
    return _stricmp(extension + 1, "md6") == 0;
}

void idCollisionModelBuilder::SetDeclMD6SphereExtractor(
    const cm_declMD6SphereExtractor_t extractor) {
    declMD6SphereExtractor = extractor;
}

bool idCollisionModelBuilder::BuildForDeclMD6(
    idCollisionModelLocal* const model, const idDeclMD6* const md6Decl) {
    if (model == nullptr || md6Decl == nullptr
        || declMD6SphereExtractor == nullptr) {
        return false;
    }
    cm_sphereBuildSource_t source{};
    return declMD6SphereExtractor(md6Decl, source)
        && BuildForSpheres(model, source);
}

bool idCollisionModelBuilder::BuildForSpheres(
    idCollisionModelLocal* const model,
    const cm_sphereBuildSource_t& source) {
    if (model == nullptr || source.name == nullptr || source.spheres == nullptr
        || source.numSpheres <= 0 || source.numModelJoints <= 0
        || source.numModelJoints > 256 || source.numSpheres > 0xFFFF) {
        return false;
    }

    const int paddedSpheres = (source.numSpheres + 3) & ~3;
    const int jointOffset = 64;
    const int offsetXOffset = Align16(jointOffset + paddedSpheres);
    const int offsetYOffset = Align16(offsetXOffset + 4 * paddedSpheres);
    const int offsetZOffset = Align16(offsetYOffset + 4 * paddedSpheres);
    const int radiusOffset = Align16(offsetZOffset + 4 * paddedSpheres);
    const int surfaceTypeOffset = Align16(radiusOffset + 4 * paddedSpheres);
    const int totalSize = surfaceTypeOffset + paddedSpheres;
    if (totalSize > 0xFFFF || surfaceTypeOffset > 0xFFFF) {
        return false;
    }

    cm_sphereModel_t* const packed = static_cast<cm_sphereModel_t*>(
        _aligned_malloc(static_cast<std::size_t>(totalSize), 16));
    if (packed == nullptr) {
        return false;
    }
    std::memset(packed, 0, static_cast<std::size_t>(totalSize));
    packed->totalSize = static_cast<std::uint32_t>(totalSize);
    packed->timeStamp = source.timeStamp;
    packed->bounds = source.bounds;
    packed->contents = static_cast<std::uint32_t>(source.contents);
    packed->numModelJoints = static_cast<std::uint16_t>(
        source.numModelJoints);
    packed->numSpheres = static_cast<std::uint16_t>(source.numSpheres);
    packed->jointOffset = static_cast<std::uint16_t>(jointOffset);
    packed->offsetXOffset = static_cast<std::uint16_t>(offsetXOffset);
    packed->offsetYOffset = static_cast<std::uint16_t>(offsetYOffset);
    packed->offsetZOffset = static_cast<std::uint16_t>(offsetZOffset);
    packed->radiusOffset = static_cast<std::uint16_t>(radiusOffset);
    packed->surfTypeOffset = static_cast<std::uint16_t>(surfaceTypeOffset);

    cm_sphereModelPtrs_t pointers{};
    idSphereModelCollisionDetection::SetupCollisionSpherePtrs(
        packed, pointers);
    for (int index = 0; index < paddedSpheres; ++index) {
        const int sourceIndex = (std::min)(index, source.numSpheres - 1);
        const cm_collisionSphereDesc_t& sphere = source.spheres[sourceIndex];
        if (sphere.joint >= source.numModelJoints || sphere.radius < 0.0f) {
            _aligned_free(packed);
            return false;
        }
        pointers.joint[index] = sphere.joint;
        pointers.offsetX[index] = sphere.offset.x;
        pointers.offsetY[index] = sphere.offset.y;
        pointers.offsetZ[index] = sphere.offset.z;
        pointers.radius[index] = sphere.radius;
        pointers.surfType[index] = sphere.surfaceType;
    }

    model->FreeData();
    model->SetName(source.name);
    model->sourceFileTime = source.timeStamp;
    model->modelType = CM_SPHEREMODEL;
    model->bounds = source.bounds;
    model->contents = source.contents;
    model->isWorldModel = false;
    model->isTraceModel = false;
    model->isConvex = false;
    model->isStreamed = false;
    model->sphereModel = packed;
    return true;
}
