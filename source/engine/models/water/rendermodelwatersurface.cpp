#include "models/water/rendermodelwatersurface.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstdint>
#include <cstring>

namespace {

constexpr std::int32_t kWaterBinaryMagic = 72109399;

bool WriteExact(idFile* file, const void* data, unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

bool ReadExact(idFile* file, void* data, unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

std::uint8_t ColorByte(float value) {
    const int scaled = static_cast<int>(value * 255.0f + 0.5f);
    return static_cast<std::uint8_t>((std::max)(0, (std::min)(255, scaled)));
}

void DeleteGeometry(idList<idRenderModelSurface, 85>& surfaces) {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr || surfaces[index].geometryIsReference)
            continue;
        delete[] geometry->verts;
        delete[] geometry->indexes;
        delete geometry;
    }
    surfaces.Clear();
}

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddPoint(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

} // namespace

idRenderModelWaterSurface::UpdateCallback
    idRenderModelWaterSurface::updateCallback = nullptr;
idRenderModelWaterSurface::MaterialNameCallback
    idRenderModelWaterSurface::materialNameCallback = nullptr;
idRenderModelWaterSurface::MaterialResolver
    idRenderModelWaterSurface::materialResolver = nullptr;
idRenderModelWaterSurface::GradientCallback
    idRenderModelWaterSurface::gradientCallback = nullptr;
idRenderModelWaterSurface::BinaryOpenCallback
    idRenderModelWaterSurface::binaryOpenCallback = nullptr;
idRenderModelWaterSurface::BinaryCloseCallback
    idRenderModelWaterSurface::binaryCloseCallback = nullptr;

idRenderModelWaterSurface::idRenderModelWaterSurface()
    : waterSim(nullptr), deferredVerts(nullptr), currentIndex(0),
      waterGenBlockParms(nullptr), material(nullptr) {
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBuffer, 0, sizeof(indexBuffer));
    std::memset(&waterSimParms, 0, sizeof(waterSimParms));
    g.noInteractions = 1;
    g.noShadow = 1;
}

idRenderModelWaterSurface::idRenderModelWaterSurface(const char* modelName)
    : idRenderModelWaterSurface() {
    SetName(modelName != nullptr ? modelName : "");
    if (modelName != nullptr && *modelName != '\0') LoadModel(modelName);
}

idRenderModelWaterSurface::~idRenderModelWaterSurface() {
    FreeData();
}

void idRenderModelWaterSurface::FreeData() {
    delete waterSim;
    waterSim = nullptr;
    delete[] waterGenBlockParms;
    waterGenBlockParms = nullptr;
    deferredVerts = nullptr;
    DeleteGeometry(surfaces);
    currentIndex = 0;
}

void idRenderModelWaterSurface::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelWaterSurface::SetMaterialPersistenceCallbacks(
        MaterialNameCallback nameCallback, MaterialResolver resolver) {
    materialNameCallback = nameCallback;
    materialResolver = resolver;
}

void idRenderModelWaterSurface::SetGradientCallback(
        GradientCallback callback) {
    gradientCallback = callback;
}

void idRenderModelWaterSurface::SetBinaryFileCallbacks(
        BinaryOpenCallback openCallback, BinaryCloseCallback closeCallback) {
    binaryOpenCallback = openCallback;
    binaryCloseCallback = closeCallback;
}

bool idRenderModelWaterSurface::ConfigureSimulation(
        const waterSimParms_t& simulationParms) {
    if (simulationParms.spacing <= 0.0f ||
            simulationParms.timeStep <= 0.0f ||
            simulationParms.waterBounds[1].x <=
                simulationParms.waterBounds[0].x ||
            simulationParms.waterBounds[1].y <=
                simulationParms.waterBounds[0].y) {
        return false;
    }
    idWaterSurfaceSim* replacement = new idWaterSurfaceSim(
        simulationParms.waterBounds, simulationParms.spacing,
        simulationParms.damping, simulationParms.speed,
        simulationParms.timeStep);
    delete waterSim;
    waterSim = replacement;
    waterSimParms = simulationParms;
    waterSimParms.spacing = replacement->spacing;
    referenceBounds = simulationParms.waterBounds;
    return true;
}

void idRenderModelWaterSurface::CreateGeometry(
        const idMaterial* newMaterial, const char* gradientImageName,
        const idVec3& origin, int width, int height, float spacing,
        int numBlocksX, int numBlocksY) {
    DeleteGeometry(surfaces);
    idTriangles* geometry = new idTriangles;
    std::memset(geometry, 0, sizeof(*geometry));
    geometry->numVerts = numBlocksX * numBlocksY * 256;
    geometry->numIndexes = (width - 1) * (height - 1) * 6;
    geometry->verts = new idDrawVert[geometry->numVerts];
    geometry->indexes = new std::uint16_t[geometry->numIndexes];
    geometry->vertexMask = geometry->cpuVertexMask = 0x1Fu;
    geometry->allowGpuHosting = true;
    ClearBounds(geometry->bounds);

    for (int blockY = 0; blockY < numBlocksY; ++blockY) {
        for (int blockX = 0; blockX < numBlocksX; ++blockX) {
            const int blockOffset = BlockPosToBlockLoc(blockX, blockY,
                numBlocksX);
            for (int localY = 0; localY < 16; ++localY) {
                for (int localX = 0; localX < 16; ++localX) {
                    int gridX = 0;
                    int gridY = 0;
                    BlockToGridPos(blockX, blockY, localX, localY,
                        gridX, gridY);
                    idDrawVert& vertex = geometry->verts[blockOffset +
                        localY * 16 + localX];
                    std::memset(&vertex, 0, sizeof(vertex));
                    vertex.xyz.Set(origin.x + gridX * spacing,
                        origin.y + gridY * spacing, origin.z);
                    vertex.st.Set(width > 1
                            ? static_cast<float>(gridX) / (width - 1) : 0.0f,
                        height > 1
                            ? static_cast<float>(gridY) / (height - 1) : 0.0f);
                    vertex.SetNormal(idVec3(0.0f, 0.0f, 1.0f));
                    vertex.SetTangent(idVec3(1.0f, 0.0f, 0.0f));
                    vertex.SetBiTangent(idVec3(0.0f, 1.0f, 0.0f));
                    idVec4 color(1.0f, 1.0f, 1.0f, 1.0f);
                    if (gradientCallback != nullptr &&
                            gradientImageName != nullptr) {
                        gradientCallback(gradientImageName, vertex.st.x,
                            vertex.st.y, color);
                    }
                    vertex.color[0] = ColorByte(color.x);
                    vertex.color[1] = ColorByte(color.y);
                    vertex.color[2] = ColorByte(color.z);
                    vertex.color[3] = ColorByte(color.w);
                    if (gridX < width && gridY < height)
                        AddPoint(geometry->bounds, vertex.xyz);
                }
            }
        }
    }

    int outputIndex = 0;
    for (int y = 0; y < height - 1; ++y) {
        for (int x = 0; x < width - 1; ++x) {
            const std::uint16_t a = static_cast<std::uint16_t>(
                GridPosToBlockLoc(x, y, numBlocksX, numBlocksY));
            const std::uint16_t b = static_cast<std::uint16_t>(
                GridPosToBlockLoc(x + 1, y, numBlocksX, numBlocksY));
            const std::uint16_t c = static_cast<std::uint16_t>(
                GridPosToBlockLoc(x, y + 1, numBlocksX, numBlocksY));
            const std::uint16_t d = static_cast<std::uint16_t>(
                GridPosToBlockLoc(x + 1, y + 1, numBlocksX, numBlocksY));
            if (((x + y) & 1) == 0) {
                geometry->indexes[outputIndex++] = a;
                geometry->indexes[outputIndex++] = d;
                geometry->indexes[outputIndex++] = b;
                geometry->indexes[outputIndex++] = a;
                geometry->indexes[outputIndex++] = c;
                geometry->indexes[outputIndex++] = d;
            } else {
                geometry->indexes[outputIndex++] = a;
                geometry->indexes[outputIndex++] = c;
                geometry->indexes[outputIndex++] = b;
                geometry->indexes[outputIndex++] = b;
                geometry->indexes[outputIndex++] = c;
                geometry->indexes[outputIndex++] = d;
            }
        }
    }
    idRenderModelSurface surface{};
    surface.material = newMaterial;
    surface.geometry = geometry;
    surface.geometryIsReference = false;
    AddSurface(surface);
    referenceBounds = geometry->bounds;
}

void idRenderModelWaterSurface::BuildWaterModel(
        const idMaterial* newMaterial, const idBounds& waterBounds,
        float spacing, float damping, float speed, float timeStep,
        const char* gradientImageName) {
    FreeData();
    waterSimParms.spacing = spacing;
    waterSimParms.damping = damping;
    waterSimParms.speed = speed;
    waterSimParms.timeStep = timeStep;
    waterSimParms.waterBounds = waterBounds;
    if (!ConfigureSimulation(waterSimParms)) return;
    material = newMaterial;
    const int blockCount = waterSim->numBlocksX * waterSim->numBlocksY;
    waterGenBlockParms = blockCount > 0
        ? new deferredWaterBlockGenParms_t[blockCount] : nullptr;
    if (waterGenBlockParms != nullptr)
        std::memset(waterGenBlockParms, 0,
            sizeof(*waterGenBlockParms) * blockCount);
    CreateGeometry(material, gradientImageName, waterSim->origin,
        static_cast<int>(waterSim->width),
        static_cast<int>(waterSim->height), waterSim->spacing,
        waterSim->numBlocksX, waterSim->numBlocksY);

    idTriangles* geometry = surfaces.Num() > 0
        ? surfaces[0].geometry : nullptr;
    if (geometry != nullptr) {
        for (int y = 1; y + 1 < static_cast<int>(waterSim->height); ++y) {
            for (int x = 1; x + 1 < static_cast<int>(waterSim->width); ++x) {
                const idDrawVert& vertex = geometry->verts[
                    GridPosToBlockLoc(x, y, waterSim->numBlocksX,
                        waterSim->numBlocksY)];
                idVec4 simulation(
                    vertex.color[0] * (1.0f / 255.0f),
                    vertex.color[1] * (1.0f / 255.0f),
                    vertex.color[2] > 127 ? 1.0f : 0.0f,
                    vertex.color[3] * (1.0f / 255.0f));
                waterSim->SetSimulationParms(x, y, simulation);
            }
        }
    }
    CommitThisFrame();
}

bool idRenderModelWaterSurface::CheckValid(
        const idWaterSurfaceSim* simulation,
        const idBounds&) const {
    if (simulation == nullptr || waterSim == nullptr ||
            surfaces.Num() != 1 || surfaces[0].geometry == nullptr) {
        return false;
    }
    const idTriangles* geometry = surfaces[0].geometry;
    return geometry->numVerts ==
            simulation->numBlocksX * simulation->numBlocksY * 256 &&
        geometry->numIndexes == 6 *
            (static_cast<int>(simulation->height) - 1) *
            (static_cast<int>(simulation->width) - 1);
}

bool idRenderModelWaterSurface::UpdateSimulation() {
    if (waterSim == nullptr || surfaces.Num() != 1 ||
            surfaces[0].geometry == nullptr ||
            waterGenBlockParms == nullptr) {
        return false;
    }
    idTriangles* geometry = surfaces[0].geometry;
    const int readBuffer = waterSim->currentDeferred ^ 1;
    const int writeBuffer = waterSim->currentDeferred;
    idBounds updatedBounds;
    ClearBounds(updatedBounds);
    int parmIndex = 0;
    for (int blockY = 0; blockY < waterSim->numBlocksY; ++blockY) {
        for (int blockX = 0; blockX < waterSim->numBlocksX; ++blockX) {
            deferredWaterBlockGenParms_t& block =
                waterGenBlockParms[parmIndex++];
            const int offset = BlockPosToBlockLoc(blockX, blockY,
                waterSim->numBlocksX);
            block.currBlock = waterSim->waveHeight[readBuffer].Ptr() + offset;
            block.prevBlock = waterSim->waveHeight[writeBuffer].Ptr() + offset;
            block.currBlockL = blockX > 0
                ? waterSim->waveHeight[readBuffer].Ptr() +
                    BlockPosToBlockLoc(blockX - 1, blockY,
                        waterSim->numBlocksX)
                : waterSim->dummyBlock.Ptr();
            block.currBlockR = blockX + 1 < waterSim->numBlocksX
                ? waterSim->waveHeight[readBuffer].Ptr() +
                    BlockPosToBlockLoc(blockX + 1, blockY,
                        waterSim->numBlocksX)
                : waterSim->dummyBlock.Ptr();
            block.currBlockU = blockY > 0
                ? waterSim->waveHeight[readBuffer].Ptr() +
                    BlockPosToBlockLoc(blockX, blockY - 1,
                        waterSim->numBlocksX)
                : waterSim->dummyBlock.Ptr();
            block.currBlockD = blockY + 1 < waterSim->numBlocksY
                ? waterSim->waveHeight[readBuffer].Ptr() +
                    BlockPosToBlockLoc(blockX, blockY + 1,
                        waterSim->numBlocksX)
                : waterSim->dummyBlock.Ptr();
            block.blockLocX = static_cast<std::uint16_t>(blockX);
            block.blockLocY = static_cast<std::uint16_t>(blockY);
            block.simulationParms = waterSim->simulateParms.Ptr() + offset;
            block.vertGradient = waterSim->vertGradient.Ptr() + offset;
            block.disturbances =
                waterSim->waterDisturbances[waterSim->currentDeferred].Ptr();
            block.numDisturbances = waterSim->numDisturbances;
            block.spacing = waterSim->spacing;
            block.speed = waterSim->speed;
            block.damping = waterSim->damping;
            block.timeDelta = waterSim->GetTimeStep();
            block.waterOrg = waterSim->origin;
            block.gridWidth = static_cast<std::uint16_t>(waterSim->width);
            block.gridHeight = static_cast<std::uint16_t>(waterSim->height);
            block.verts = geometry->verts + offset;
            ApplyDisturbances(&block);
            GenWaterSurface(&block, block.prevBlock);
            for (int local = 0; local < 256; ++local)
                AddPoint(updatedBounds, block.verts[local].xyz);
        }
    }
    geometry->bounds = updatedBounds;
    referenceBounds = updatedBounds;
    waterSim->Swap();
    currentIndex = (currentIndex + 1) % 3;
    CommitThisFrame();
    return true;
}

bool idRenderModelWaterSurface::UpdateInView(
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    return UpdateSimulation();
}

void idRenderModelWaterSurface::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    const std::uint8_t hasMaterial = material != nullptr ? 1u : 0u;
    WriteExact(file, &hasMaterial, sizeof(hasMaterial));
    if (hasMaterial != 0) {
        const char* name = materialNameCallback != nullptr
            ? materialNameCallback(material) : "";
        file->WriteString(name != nullptr ? name : "");
    }
    WriteExact(file, &waterSimParms.waterBounds,
        sizeof(waterSimParms.waterBounds));
    WriteExact(file, &waterSimParms.spacing, sizeof(waterSimParms.spacing));
    WriteExact(file, &waterSimParms.damping, sizeof(waterSimParms.damping));
    WriteExact(file, &waterSimParms.speed, sizeof(waterSimParms.speed));
    WriteExact(file, &waterSimParms.timeStep, sizeof(waterSimParms.timeStep));
}

bool idRenderModelWaterSurface::Load(idFile* file) {
    if (!idRenderModel::Load(file)) return false;
    std::uint8_t hasMaterial = 0;
    if (!ReadExact(file, &hasMaterial, sizeof(hasMaterial))) return false;
    const idMaterial* loadedMaterial = nullptr;
    if (hasMaterial != 0) {
        idStr materialName;
        if (file->ReadString(materialName) == 0 ||
                materialResolver == nullptr ||
                (loadedMaterial = materialResolver(materialName.c_str(),
                    true)) == nullptr) {
            return false;
        }
    }
    waterSimParms_t loaded{};
    if (!ReadExact(file, &loaded.waterBounds, sizeof(loaded.waterBounds)) ||
            !ReadExact(file, &loaded.spacing, sizeof(loaded.spacing)) ||
            !ReadExact(file, &loaded.damping, sizeof(loaded.damping)) ||
            !ReadExact(file, &loaded.speed, sizeof(loaded.speed)) ||
            !ReadExact(file, &loaded.timeStep, sizeof(loaded.timeStep))) {
        return false;
    }
    BuildWaterModel(loadedMaterial, loaded.waterBounds, loaded.spacing,
        loaded.damping, loaded.speed, loaded.timeStep, nullptr);
    return waterSim != nullptr;
}

bool idRenderModelWaterSurface::WriteBinary(const char* modelName) const {
    if (binaryOpenCallback == nullptr) return false;
    idFile* file = binaryOpenCallback(modelName, true);
    const bool result = WriteBinary(file);
    if (binaryCloseCallback != nullptr) binaryCloseCallback(file);
    return result;
}

bool idRenderModelWaterSurface::WriteBinary(idFile* file) const {
    if (file == nullptr || surfaces.Num() != 1 ||
            surfaces[0].geometry == nullptr) {
        return false;
    }
    const idTriangles* geometry = surfaces[0].geometry;
    if (!WriteExact(file, &kWaterBinaryMagic, sizeof(kWaterBinaryMagic)))
        return false;
    const char* name = material != nullptr && materialNameCallback != nullptr
        ? materialNameCallback(material) : "";
    if (file->WriteString(name != nullptr ? name : "") == 0) return false;
    return WriteExact(file, &waterSimParms.spacing,
               sizeof(waterSimParms.spacing)) &&
        WriteExact(file, &waterSimParms.damping,
            sizeof(waterSimParms.damping)) &&
        WriteExact(file, &waterSimParms.speed, sizeof(waterSimParms.speed)) &&
        WriteExact(file, &waterSimParms.timeStep,
            sizeof(waterSimParms.timeStep)) &&
        WriteExact(file, &waterSimParms.waterBounds,
            sizeof(waterSimParms.waterBounds)) &&
        WriteExact(file, &geometry->bounds, sizeof(geometry->bounds)) &&
        WriteExact(file, &geometry->numVerts, sizeof(geometry->numVerts)) &&
        WriteExact(file, &geometry->numIndexes,
            sizeof(geometry->numIndexes)) &&
        WriteExact(file, geometry->verts,
            geometry->numVerts * static_cast<unsigned int>(sizeof(idDrawVert))) &&
        WriteExact(file, geometry->indexes,
            geometry->numIndexes * static_cast<unsigned int>(sizeof(std::uint16_t)));
}

bool idRenderModelWaterSurface::LoadBinary(const char* modelName) {
    if (binaryOpenCallback == nullptr) return false;
    idFile* file = binaryOpenCallback(modelName, false);
    const bool result = LoadBinary(file);
    if (binaryCloseCallback != nullptr) binaryCloseCallback(file);
    return result;
}

bool idRenderModelWaterSurface::LoadBinary(idFile* file) {
    std::int32_t magic = 0;
    if (!ReadExact(file, &magic, sizeof(magic)) ||
            magic != kWaterBinaryMagic) {
        return false;
    }
    idStr materialName;
    if (file->ReadString(materialName) == 0) return false;
    const idMaterial* loadedMaterial = nullptr;
    if (materialName.Length() != 0) {
        if (materialResolver == nullptr ||
                (loadedMaterial = materialResolver(materialName.c_str(),
                    true)) == nullptr) {
            return false;
        }
    }
    waterSimParms_t loaded{};
    idBounds geometryBounds;
    int vertexCount = 0;
    int indexCount = 0;
    if (!ReadExact(file, &loaded.spacing, sizeof(loaded.spacing)) ||
            !ReadExact(file, &loaded.damping, sizeof(loaded.damping)) ||
            !ReadExact(file, &loaded.speed, sizeof(loaded.speed)) ||
            !ReadExact(file, &loaded.timeStep, sizeof(loaded.timeStep)) ||
            !ReadExact(file, &loaded.waterBounds,
                sizeof(loaded.waterBounds)) ||
            !ReadExact(file, &geometryBounds, sizeof(geometryBounds)) ||
            !ReadExact(file, &vertexCount, sizeof(vertexCount)) ||
            !ReadExact(file, &indexCount, sizeof(indexCount)) ||
            vertexCount <= 0 || vertexCount > 65536 ||
            indexCount <= 0 || indexCount > 6 * 65536) {
        return false;
    }
    idDrawVert* vertices = new idDrawVert[vertexCount];
    std::uint16_t* indices = new std::uint16_t[indexCount];
    if (!ReadExact(file, vertices,
                vertexCount * static_cast<unsigned int>(sizeof(idDrawVert))) ||
            !ReadExact(file, indices,
                indexCount * static_cast<unsigned int>(sizeof(std::uint16_t)))) {
        delete[] indices;
        delete[] vertices;
        return false;
    }
    FreeData();
    material = loadedMaterial;
    waterSimParms = loaded;
    if (!ConfigureSimulation(loaded)) {
        delete[] indices;
        delete[] vertices;
        return false;
    }
    idTriangles* geometry = new idTriangles;
    std::memset(geometry, 0, sizeof(*geometry));
    geometry->bounds = geometryBounds;
    geometry->numVerts = vertexCount;
    geometry->numIndexes = indexCount;
    geometry->verts = vertices;
    geometry->indexes = indices;
    geometry->vertexMask = geometry->cpuVertexMask = 0x1Fu;
    geometry->allowGpuHosting = true;
    idRenderModelSurface surface{};
    surface.material = material;
    surface.geometry = geometry;
    surface.geometryIsReference = false;
    AddSurface(surface);
    referenceBounds = geometryBounds;
    const int blockCount = waterSim->numBlocksX * waterSim->numBlocksY;
    waterGenBlockParms = new deferredWaterBlockGenParms_t[blockCount];
    std::memset(waterGenBlockParms, 0,
        sizeof(*waterGenBlockParms) * blockCount);
    for (int y = 1; y + 1 < static_cast<int>(waterSim->height); ++y) {
        for (int x = 1; x + 1 < static_cast<int>(waterSim->width); ++x) {
            const idDrawVert& vertex = vertices[GridPosToBlockLoc(x, y,
                waterSim->numBlocksX, waterSim->numBlocksY)];
            const idVec4 simulation(
                vertex.color[0] * (1.0f / 255.0f),
                vertex.color[1] * (1.0f / 255.0f),
                vertex.color[2] > 127 ? 1.0f : 0.0f,
                vertex.color[3] * (1.0f / 255.0f));
            waterSim->SetSimulationParms(x, y, simulation);
        }
    }
    CommitThisFrame();
    return CheckValid(waterSim, loaded.waterBounds);
}

bool idRenderModelWaterSurface::LoadModel(const char* modelName) {
    return LoadBinary(modelName);
}
