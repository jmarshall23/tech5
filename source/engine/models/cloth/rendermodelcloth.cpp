#include "models/cloth/rendermodelcloth.h"

#include "idlib/filesystem/file.h"
#include "models/cloth/declcloth.h"
#include "models/cloth/jobs/clothgen.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <new>
#include <vector>

idRenderModelCloth::UpdateCallback idRenderModelCloth::updateCallback = nullptr;
idRenderModelCloth::ClothResolver idRenderModelCloth::clothResolver = nullptr;
idRenderModelCloth::BuildCallback idRenderModelCloth::buildCallback = nullptr;
idRenderModelCloth::SerializeCallback
    idRenderModelCloth::serializeCallback = nullptr;
idRenderModelCloth::JobSubmitCallback
    idRenderModelCloth::jobSubmitCallback = nullptr;

namespace {

bool WriteExact(idFile* file, const void* data, unsigned int bytes) {
    return file != nullptr && (bytes == 0 || file->Write(data, bytes) == bytes);
}

bool ReadExact(idFile* file, void* data, unsigned int bytes) {
    return file != nullptr && (bytes == 0 || file->Read(data, bytes) == bytes);
}

int ResolveAttachmentIndex(idRenderModelCloth::clothAttachInfo_t& attachment,
    const idClothSim& simulation, bool rect) {
    using anchor_t =
        idRenderModelCloth::clothAttachInfo_t::idClothAnchorType_t;
    switch (attachment.clothAnchorType) {
        case anchor_t::ANCHOR_CORNER1:
            attachment.row = 0; attachment.col = 0; break;
        case anchor_t::ANCHOR_CORNER2:
            attachment.row = simulation.height - 1;
            attachment.col = 0; break;
        case anchor_t::ANCHOR_CORNER3:
            attachment.row = simulation.height - 1;
            attachment.col = simulation.width - 1; break;
        case anchor_t::ANCHOR_CORNER4:
            attachment.row = 0;
            attachment.col = simulation.width - 1; break;
        case anchor_t::ANCHOR_MID1:
            attachment.row = simulation.height / 2;
            attachment.col = 0; break;
        case anchor_t::ANCHOR_MID2:
            attachment.row = simulation.height - 1;
            attachment.col = simulation.width / 2; break;
        case anchor_t::ANCHOR_MID3:
            attachment.row = simulation.height / 2;
            attachment.col = simulation.width - 1; break;
        case anchor_t::ANCHOR_MID4:
            attachment.row = 0;
            attachment.col = simulation.width / 2; break;
        case anchor_t::ANCHOR_CENTER:
            attachment.row = simulation.height / 2;
            attachment.col = simulation.width / 2; break;
        case anchor_t::ANCHOR_DEFINED:
            break;
        default:
            return -1;
    }
    attachment.row = (std::max)(0,
        (std::min)(simulation.height - 1, attachment.row));
    if (rect) {
        attachment.col = (std::max)(0,
            (std::min)(simulation.width - 1, attachment.col));
        return attachment.row * simulation.width + attachment.col;
    }
    const int rowWidth = attachment.row * 2 + 1;
    attachment.col = (std::max)(0,
        (std::min)(rowWidth - 1, attachment.col));
    return attachment.row * attachment.row + attachment.col;
}

void FreeOwnedSurfaceArrays(idRenderModelCloth& model) {
    for (int index = 0; index < model.surfaces.Num(); ++index) {
        idRenderModelSurface& surface = model.surfaces[index];
        if (surface.geometry == nullptr || surface.geometryIsReference)
            continue;
        delete[] surface.geometry->verts;
        delete[] surface.geometry->indexes;
        surface.geometry->verts = nullptr;
        surface.geometry->indexes = nullptr;
    }
}

} // namespace

idRenderModelCloth::idRenderModelCloth()
    : clothSimulation(nullptr), deferredVerts(nullptr), numVerts(0),
      currentIndex(0), clothBounds(nullptr), clothParms(nullptr), rect(false),
      clothSystem(nullptr), clothType(CLOTH_INVALID), width(0), height(0),
      vSpacing(0.0f), hSpacing(0.0f) {
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBuffer, 0, sizeof(indexBuffer));
}

idRenderModelCloth::idRenderModelCloth(const idDeclCloth* system)
    : idRenderModelCloth() {
    clothSystem = system;
}

idRenderModelCloth::~idRenderModelCloth() {
    FreeOwnedSurfaceArrays(*this);
    delete clothSimulation;
    delete[] deferredVerts;
    delete clothBounds;
    delete clothParms;
}

void idRenderModelCloth::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelCloth::SetClothResolver(ClothResolver resolver) {
    clothResolver = resolver;
}

void idRenderModelCloth::SetBuildCallback(BuildCallback callback) {
    buildCallback = callback;
}

void idRenderModelCloth::SetSerializeCallback(SerializeCallback callback) {
    serializeCallback = callback;
}

void idRenderModelCloth::SetJobSubmitCallback(JobSubmitCallback callback) {
    jobSubmitCallback = callback;
}

void idRenderModelCloth::Save(idFile* file) {
    if (file == nullptr) return;
    const std::uint8_t hasCloth = clothSystem != nullptr ? 1u : 0u;
    WriteExact(file, &hasCloth, sizeof(hasCloth));
    if (hasCloth != 0) file->WriteString(clothSystem->GetName());
    const std::uint32_t attachmentCount =
        static_cast<std::uint32_t>(attachPoints.Num());
    WriteExact(file, &clothType, sizeof(clothType));
    WriteExact(file, &attachmentCount, sizeof(attachmentCount));
    for (int index = 0; index < attachPoints.Num(); ++index) {
        const clothAttachInfo_t& attachment = attachPoints[index];
        WriteExact(file, &attachment.point, sizeof(attachment.point));
        WriteExact(file, &attachment.clothAnchorType,
            sizeof(attachment.clothAnchorType));
        WriteExact(file, &attachment.row, sizeof(attachment.row));
        WriteExact(file, &attachment.col, sizeof(attachment.col));
    }
    WriteExact(file, &width, sizeof(width));
    WriteExact(file, &height, sizeof(height));
    WriteExact(file, &vSpacing, sizeof(vSpacing));
    WriteExact(file, &hSpacing, sizeof(hSpacing));
    const std::uint32_t sphereCount =
        static_cast<std::uint32_t>(collisionSpheres.Num());
    WriteExact(file, &sphereCount, sizeof(sphereCount));
    WriteExact(file, collisionSpheres.Ptr(),
        sphereCount * static_cast<unsigned int>(sizeof(idVec4)));
}

bool idRenderModelCloth::Load(idFile* file) {
    if (file == nullptr) return false;
    std::uint8_t hasCloth = 0;
    if (!ReadExact(file, &hasCloth, sizeof(hasCloth))) return false;
    clothSystem = nullptr;
    if (hasCloth != 0) {
        idStr clothName;
        if (file->ReadString(clothName) == 0 || clothResolver == nullptr ||
            (clothSystem = clothResolver(clothName.c_str(), true)) == nullptr) {
            return false;
        }
    }
    std::uint32_t attachmentCount = 0;
    if (!ReadExact(file, &clothType, sizeof(clothType)) ||
        !ReadExact(file, &attachmentCount, sizeof(attachmentCount)) ||
        attachmentCount > 1024 ||
        !attachPoints.SetNum(static_cast<int>(attachmentCount))) return false;
    for (int index = 0; index < attachPoints.Num(); ++index) {
        clothAttachInfo_t& attachment = attachPoints[index];
        attachment.tempAnchor = false;
        if (!ReadExact(file, &attachment.point, sizeof(attachment.point)) ||
            !ReadExact(file, &attachment.clothAnchorType,
                sizeof(attachment.clothAnchorType)) ||
            !ReadExact(file, &attachment.row, sizeof(attachment.row)) ||
            !ReadExact(file, &attachment.col, sizeof(attachment.col))) {
            return false;
        }
    }
    std::uint32_t sphereCount = 0;
    if (!ReadExact(file, &width, sizeof(width)) ||
        !ReadExact(file, &height, sizeof(height)) ||
        !ReadExact(file, &vSpacing, sizeof(vSpacing)) ||
        !ReadExact(file, &hSpacing, sizeof(hSpacing)) ||
        !ReadExact(file, &sphereCount, sizeof(sphereCount)) ||
        sphereCount > 1024 ||
        !collisionSpheres.SetNum(static_cast<int>(sphereCount)) ||
        !ReadExact(file, collisionSpheres.Ptr(),
            sphereCount * static_cast<unsigned int>(sizeof(idVec4)))) {
        return false;
    }
    CreateClothSim(clothSystem, clothType, attachPoints, collisionSpheres,
        width, height, hSpacing, vSpacing);
    return clothSimulation != nullptr;
}

void idRenderModelCloth::SerializeSnapshot(idSerializer* serializer,
    bool writing) {
    if (serializeCallback != nullptr)
        serializeCallback(this, serializer, writing);
}

void idRenderModelCloth::CreateClothSim(const idDeclCloth* clothDecl,
    idClothType_t type, const idList<clothAttachInfo_t, 5>& attachments,
    const idList<idVec4, 5>& spheres, int widthOverride,
    int heightOverride, float horizontalSpacingOverride,
    float verticalSpacingOverride) {
    delete clothSimulation;
    clothSimulation = nullptr;
    clothSystem = clothDecl;
    clothType = type;
    attachPoints = attachments;
    collisionSpheres = spheres;
    if (clothDecl == nullptr || type <= CLOTH_INVALID ||
        type >= MAX_CLOTH_TYPE) return;
    width = widthOverride > 0 ? widthOverride : clothDecl->width;
    height = heightOverride > 0 ? heightOverride : clothDecl->height;
    hSpacing = horizontalSpacingOverride > 0.0f
        ? horizontalSpacingOverride : clothDecl->hSpacing;
    vSpacing = verticalSpacingOverride > 0.0f
        ? verticalSpacingOverride : clothDecl->vSpacing;
    rect = type != CLOTH_FLAG_TRIANGLE && type != CLOTH_TARP_TRIANGLE;
    clothSimulation = new (std::nothrow) idClothSim(width, height,
        hSpacing, vSpacing, clothDecl, rect);
    if (clothSimulation == nullptr) return;
    for (int index = 0; index < attachPoints.Num(); ++index) {
        const int particleIndex = ResolveAttachmentIndex(attachPoints[index],
            *clothSimulation, rect);
        if (particleIndex >= 0) {
            clothSimulation->SetAnchor(particleIndex,
                attachPoints[index].tempAnchor);
            clothSimulation->SetAnchorPosition(particleIndex,
                attachPoints[index].point);
        }
    }
    for (int index = 0; index < collisionSpheres.Num(); ++index) {
        const idVec4& packed = collisionSpheres[index];
        clothSimulation->AddCollisionSphere(
            idSphere(idVec3(packed.x, packed.y, packed.z), packed.w), true);
    }
    BuildClothModel();
}

void idRenderModelCloth::BuildClothModel() {
    if (clothSimulation == nullptr || clothSystem == nullptr ||
        clothSimulation->width <= 0 || clothSimulation->height <= 0) return;
    FreeOwnedSurfaceArrays(*this);
    FreeSurfaces();
    delete[] deferredVerts;
    deferredVerts = nullptr;
    delete clothBounds;
    clothBounds = new (std::nothrow) idBounds{};
    if (clothParms == nullptr)
        clothParms = new (std::nothrow) clothParms_t{};
    numVerts = clothSimulation->numClothParticles;
    deferredVerts = new (std::nothrow) idDrawVert[numVerts];
    if (deferredVerts == nullptr || clothBounds == nullptr ||
        clothParms == nullptr) return;

    std::vector<std::uint16_t> indexes;
    if (rect) {
        for (int row = 0; row + 1 < clothSimulation->height; ++row) {
            for (int column = 0; column + 1 < clothSimulation->width;
                 ++column) {
                const std::uint16_t a = static_cast<std::uint16_t>(
                    row * clothSimulation->width + column);
                const std::uint16_t b = static_cast<std::uint16_t>(a + 1);
                const std::uint16_t c = static_cast<std::uint16_t>(
                    a + clothSimulation->width);
                const std::uint16_t d = static_cast<std::uint16_t>(c + 1);
                indexes.push_back(a); indexes.push_back(b); indexes.push_back(c);
                indexes.push_back(b); indexes.push_back(d); indexes.push_back(c);
            }
        }
    } else {
        for (int row = 0; row + 1 < clothSimulation->height; ++row) {
            const int currentStart = row * row;
            const int nextStart = (row + 1) * (row + 1);
            for (int column = 0; column < row * 2 + 1; ++column) {
                const std::uint16_t a = static_cast<std::uint16_t>(
                    currentStart + column);
                const std::uint16_t b = static_cast<std::uint16_t>(
                    nextStart + column);
                const std::uint16_t c = static_cast<std::uint16_t>(
                    nextStart + column + 1);
                const std::uint16_t d = static_cast<std::uint16_t>(
                    nextStart + column + 2);
                indexes.push_back(a); indexes.push_back(b); indexes.push_back(c);
                indexes.push_back(a); indexes.push_back(c); indexes.push_back(d);
            }
        }
    }

    *clothParms = clothParms_t{};
    clothParms->type = clothSystem->type;
    clothParms->cloth = clothSimulation->cloth;
    clothParms->numClothParticles = clothSimulation->numClothParticles;
    clothParms->springs = clothSimulation->springs.Ptr();
    clothParms->numSprings = clothSimulation->springs.Num();
    clothParms->vertices = deferredVerts;
    clothParms->bounds = clothBounds;
    clothParms->axis = idMat3(1.0f);
    clothParms->width = clothSimulation->width;
    clothParms->height = clothSimulation->height;
    clothParms->numIterations = 1;
    clothParms->rect = rect;
    ClothGenJob(*clothParms);
    for (int index = 0; index < numVerts; ++index) {
        const int row = rect ? index / clothSimulation->width
            : static_cast<int>(std::sqrt(static_cast<float>(index)));
        const int column = rect ? index % clothSimulation->width
            : index - row * row;
        deferredVerts[index].st.Set(
            clothSimulation->height > 1
                ? static_cast<float>(row) /
                    static_cast<float>(clothSimulation->height - 1) : 0.0f,
            clothSimulation->width > 1
                ? static_cast<float>(column) /
                    static_cast<float>(clothSimulation->width - 1) : 0.0f);
        deferredVerts[index].color[0] = 255;
        deferredVerts[index].color[1] = 255;
        deferredVerts[index].color[2] = 255;
        deferredVerts[index].color[3] = 255;
    }

    idTriangles* const geometry = new (std::nothrow) idTriangles{};
    if (geometry != nullptr) {
        geometry->numVerts = numVerts;
        geometry->numIndexes = static_cast<int>(indexes.size());
        geometry->verts = new (std::nothrow) idDrawVert[numVerts];
        geometry->indexes = indexes.empty() ? nullptr
            : new (std::nothrow) std::uint16_t[indexes.size()];
        if (geometry->verts != nullptr)
            std::memcpy(geometry->verts, deferredVerts,
                sizeof(idDrawVert) * numVerts);
        if (geometry->indexes != nullptr)
            std::memcpy(geometry->indexes, indexes.data(),
                sizeof(std::uint16_t) * indexes.size());
        geometry->vertexMask = geometry->cpuVertexMask = 0x1Fu;
        geometry->allowGpuHosting = true;
        geometry->bounds = *clothBounds;
        idRenderModelSurface surface{};
        surface.material = clothSystem->material;
        surface.geometry = geometry;
        surface.geometryIsReference = false;
        AddSurface(surface);
        FinishSurfaces();
    }
    if (clothSimulation->clothBoundsFromJob != nullptr)
        *clothSimulation->clothBoundsFromJob = *clothBounds;
    clothSimulation->clothBounds = *clothBounds;
    referenceBounds = *clothBounds;
    if (buildCallback != nullptr) {
        buildCallback(this, deferredVerts, numVerts, indexes.data(),
            static_cast<int>(indexes.size()), clothSystem->material);
    }
}

void idRenderModelCloth::SetupClothJob(
        idParallelJobList* const parallelJobList,
        idDrawVert* const vertices) {
    if (clothSimulation == nullptr || clothParms == nullptr
        || clothBounds == nullptr
        || clothSimulation->numClothParticles > 100) return;
    const int deferred = clothSimulation->currentDeferred;
    clothParms_t& parameters = *clothParms;
    parameters = clothParms_t{};
    parameters.type = CLOTH_FLAG;
    parameters.numIterations = clothSimulation->numIterations;
    clothSimulation->numIterations = 1;
    idList<idSphere, 81>& collisions =
        clothSimulation->temporaryCollisionSpheres[deferred];
    for (int index = 0;
            index < clothSimulation->permanentCollisionSpheres.Num();
            ++index) {
        collisions.Append(clothSimulation->permanentCollisionSpheres[index]);
    }
    parameters.cloth = clothSimulation->cloth;
    parameters.numClothParticles = clothSimulation->numClothParticles;
    parameters.springs = clothSimulation->springs.Ptr();
    parameters.numSprings = clothSimulation->springs.Num();
    parameters.collisions = collisions.Ptr();
    parameters.numCollisions = collisions.Num();
    parameters.collisionPlane = clothSimulation->collisionPlane[deferred];
    parameters.hasCollisionPlane =
        parameters.collisionPlane.Normal().LengthSqr() > 0.0f;
    parameters.collisionFriction = clothSimulation->clothDecl != nullptr
        ? clothSimulation->clothDecl->collisionFriction : 0.0f;
    parameters.weaponTraces =
        clothSimulation->weaponTraces[deferred].Ptr();
    parameters.numWeaponTraces =
        clothSimulation->weaponTraces[deferred].Num();
    parameters.vertices = vertices;
    parameters.bounds = clothBounds;
    parameters.org = clothSimulation->origin;
    parameters.axis = clothSimulation->axis;
    parameters.friction = clothSystem != nullptr
        ? clothSystem->friction : 0.0f;
    parameters.gravity = clothSimulation->gravity;
    parameters.windDirection = clothSimulation->windDirection;
    parameters.width = clothSimulation->width;
    parameters.height = clothSimulation->height;
    parameters.vSpacing = clothSimulation->vSpacing;
    parameters.hSpacing = clothSimulation->hSpacing;
    parameters.timeDelta = clothSimulation->timeDelta;
    parameters.rect = clothSimulation->isRect;

    const bool submitted = parallelJobList != nullptr
        && jobSubmitCallback != nullptr
        && jobSubmitCallback(parallelJobList, &parameters);
    if (!submitted) ClothGenJob(parameters);
    if (clothSimulation->clothBoundsFromJob != nullptr)
        *clothSimulation->clothBoundsFromJob = *clothBounds;
    clothSimulation->Swap();
}

bool idRenderModelCloth::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    if (clothSimulation == nullptr || deferredVerts == nullptr
        || surfaces.Num() == 0 || surfaces[0].geometry == nullptr)
        return false;
    SetupClothJob(nullptr, deferredVerts);
    idTriangles* const geometry = surfaces[0].geometry;
    if (geometry->verts != nullptr)
        std::memcpy(geometry->verts, deferredVerts,
            sizeof(idDrawVert) * numVerts);
    geometry->bounds = *clothBounds;
    referenceBounds = *clothBounds;
    currentIndex = (currentIndex + 1) % 3;
    CommitSurfaces();
    return true;
}
