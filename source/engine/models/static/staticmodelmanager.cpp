#include "models/static/staticmodelmanager.h"

#include "models/skeletalanimation/md6model.h"

#include <cstring>

idStaticModelManagerLocal localModelManager;
idStaticModelManager* staticModelManager = &localModelManager;

namespace {

idStaticModel* MakeSquare(const char* name, const float low) {
    idStaticModel* model = new idStaticModel;
    model->SetName(name);
    idTriangles* geometry = new idTriangles{};
    geometry->numVerts = 4;
    geometry->numIndexes = 6;
    geometry->cpuVertexMask = geometry->vertexMask = 0x1Fu;
    geometry->allowGpuHosting = true;
    geometry->verts = new idDrawVert[4]{};
    geometry->indexes = new std::uint16_t[6]{3, 0, 2, 2, 0, 1};
    const idVec3 positions[4] = {{low, low, 0.0f}, {1.0f, low, 0.0f},
        {1.0f, 1.0f, 0.0f}, {low, 1.0f, 0.0f}};
    for (int index = 0; index < 4; ++index) {
        geometry->verts[index].xyz = positions[index];
        geometry->verts[index].st.Set((index == 1 || index == 2) ? 1.0f : 0.0f,
            index >= 2 ? 1.0f : 0.0f);
        geometry->verts[index].SetNormal(idVec3(0.0f, 0.0f, 1.0f));
        geometry->verts[index].SetTangent(idVec3(1.0f, 0.0f, 0.0f));
        geometry->verts[index].tangent[3] = 255;
        std::memset(geometry->verts[index].color, 255, 4);
    }
    geometry->bounds[0].Set(low, low, 0.0f);
    geometry->bounds[1].Set(1.0f, 1.0f, 0.0f);
    idStaticModelSurface surface;
    surface.geometry = geometry;
    model->AddSurface(surface);
    model->FinishStaticModel(false);
    model->isReloadable = false;
    return model;
}

} // namespace

void idStaticModelManagerLocal::AddStaticModel(idStaticModel* model) {
    if (model == nullptr) return;
    model->isReloadable = false;
    idStaticModel::resourceList.Add(model);
}

void idStaticModelManagerLocal::ReloadModels() {
    idStaticModel::resourceList.ReloadStaleResources();
    idMD6Model::resourceList.ReloadStaleResources();
}

void idStaticModelManagerLocal::CalculateStats(idStats* stats) {
    if (stats == nullptr) return;
    *stats = {};
    for (int modelIndex = 0;
         modelIndex < idStaticModel::resourceList.num; ++modelIndex) {
        const idStaticModel* model = static_cast<const idStaticModel*>(
            idStaticModel::resourceList.Index(modelIndex));
        if (model == nullptr) continue;
        ++stats->inUse;
        stats->totalCPUMem += model->CPUMemory();
        stats->totalGPUMem += model->GPUMemory();
        for (int surfaceIndex = 0; surfaceIndex < model->surfaces.Num();
             ++surfaceIndex) {
            const idTriangles* geometry = model->surfaces[surfaceIndex].geometry;
            if (geometry == nullptr) continue;
            ++stats->totalSurfaces;
            stats->totalVerts += geometry->numVerts;
            stats->totalTriangles += geometry->numIndexes / 3;
        }
    }
}

const idStaticModel* idStaticModelManagerLocal::FindStaticModel(
        const char* modelName, const bool makeDefault) {
    if (modelName == nullptr || modelName[0] == '\0') return nullptr;
    idStr canonical(modelName);
    if (std::strncmp(canonical.c_str(), "maps/", 5) == 0) {
        const char* slash = std::strrchr(canonical.c_str(), '/');
        const char* dot = std::strrchr(canonical.c_str(), '.');
        if (dot == nullptr || (slash != nullptr && dot < slash))
            canonical.Append(".bmodel");
    }
    canonical.MakeNameCanonical();
    idResource* resource = idStaticModel::resourceList.Load(
        canonical.c_str(), makeDefault, false);
    if (resource == nullptr) return nullptr;
    if (resource->resourceError != nullptr && !makeDefault) return nullptr;
    return static_cast<const idStaticModel*>(resource);
}

void idStaticModelManagerLocal::Init() {
    if (idStaticModel::resourceList.Lookup("_default") != nullptr) return;
    idStaticModel* defaultModel = new idStaticModel;
    defaultModel->SetName("_default");
    defaultModel->MakeDefaultModel(-8.0f, 8.0f);
    AddStaticModel(defaultModel);

    idStaticModel* unitCube = new idStaticModel;
    unitCube->SetName("_unitCube");
    unitCube->MakeSimpleCube(-1.0f, 1.0f);
    AddStaticModel(unitCube);

    idStaticModel* zeroOneCube = new idStaticModel;
    zeroOneCube->SetName("_zeroOneCube");
    zeroOneCube->MakeSimpleCube(0.0f, 1.0f);
    AddStaticModel(zeroOneCube);

    idStaticModel* extrudeBox = new idStaticModel;
    extrudeBox->SetName("_extrudeBox");
    extrudeBox->MakeExtrudeBox();
    AddStaticModel(extrudeBox);

    AddStaticModel(MakeSquare("_unitSquare", -1.0f));
    AddStaticModel(MakeSquare("_zeroOneSquare", 0.0f));
}
