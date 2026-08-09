#include "models/cuttable/rendermodelcuttablebeams.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstring>
#include <new>

idRenderModelCuttableBeams::UpdateCallback
    idRenderModelCuttableBeams::updateCallback = nullptr;
idRenderModelCuttableBeams::MaterialResolver
    idRenderModelCuttableBeams::materialResolver = nullptr;
idRenderModelCuttableBeams::MaterialNameCallback
    idRenderModelCuttableBeams::materialNameCallback = nullptr;
idRenderModelCuttableBeams::GeometryUploadCallback
    idRenderModelCuttableBeams::geometryUploadCallback = nullptr;
float idRenderModelCuttableBeams::beamWidth = 0.75f;
float idRenderModelCuttableBeams::beamRepeat = 8.0f;
float idRenderModelCuttableBeams::crossingSize = 1.25f;
float idRenderModelCuttableBeams::endpointSize = 1.0f;
int idRenderModelCuttableBeams::currentBuffer = 0;

namespace {

idDrawVert BeamVertex(const idVec3& position, const idVec3& normal,
        const idVec3& tangent, float s, float t) {
    idDrawVert vertex{};
    vertex.xyz = position;
    vertex.st.Set(s, t);
    vertex.SetNormal(normal);
    vertex.SetTangent(tangent);
    vertex.SetBiTangent(normal.Cross(tangent));
    for (int component = 0; component < 4; ++component)
        vertex.color[component] = 255;
    return vertex;
}

void AppendQuad(idList<idDrawVert, 5>& vertices,
        idList<std::uint16_t, 5>& indices,
        const idDrawVert& a, const idDrawVert& b,
        const idDrawVert& c, const idDrawVert& d) {
    if (vertices.Num() + 4 > idRenderModelCuttableBeams::MAX_BEAM_VERTICES ||
            indices.Num() + 6 >
                idRenderModelCuttableBeams::MAX_BEAM_INDICES) return;
    const std::uint16_t base = static_cast<std::uint16_t>(vertices.Num());
    vertices.Append(a); vertices.Append(b); vertices.Append(c); vertices.Append(d);
    indices.Append(base); indices.Append(base + 1); indices.Append(base + 2);
    indices.Append(base); indices.Append(base + 2); indices.Append(base + 3);
}

} // namespace

idRenderModelCuttableBeams::idRenderModelCuttableBeams()
    : materialIncision(nullptr), materialIncisionCross(nullptr),
      graphManager(nullptr), graphHandle(-1) {
    g.noInteractions = 1;
    g.noShadow = 1;
    g.addAlways = 1;
    g.noGPUocclusionTest = 1;
    referenceBounds[0].Set(-1.0f, -1.0f, -1.0f);
    referenceBounds[1].Set(1.0f, 1.0f, 1.0f);
    SetMaxSurfaces(SURFACE_MAX);
    for (int index = 0; index < SURFACE_MAX; ++index) {
        idTriangles* geometry = new (std::nothrow) idTriangles{};
        if (geometry != nullptr) {
            geometry->bounds = referenceBounds;
            geometry->vertexMask = 31;
            geometry->cpuVertexMask = 31;
            geometry->vertexBuffer.usage = BU_DYNAMIC;
            geometry->indexBuffer.usage = BU_DYNAMIC;
        }
        idRenderModelSurface surface{};
        surface.geometry = geometry;
        surface.geometryIsReference = false;
        surface.materialNum = index;
        AddSurface(surface);
    }
    FinishSurfaces();
}

idRenderModelCuttableBeams::~idRenderModelCuttableBeams() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idTriangles* geometry = surfaces[index].geometry;
        if (geometry == nullptr) continue;
        delete[] geometry->verts;
        delete[] geometry->indexes;
        delete geometry;
        surfaces[index].geometry = nullptr;
    }
}

void idRenderModelCuttableBeams::Init() { currentBuffer = 0; }
void idRenderModelCuttableBeams::Shutdown() { currentBuffer = 0; }
void idRenderModelCuttableBeams::StartFrame() {
    currentBuffer = (currentBuffer + 1) % NUM_VERTEX_BUFFERS;
}
void idRenderModelCuttableBeams::EndFrame() {}

void idRenderModelCuttableBeams::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelCuttableBeams::SetMaterialCallbacks(
        MaterialResolver resolver, MaterialNameCallback nameCallback) {
    materialResolver = resolver;
    materialNameCallback = nameCallback;
}

void idRenderModelCuttableBeams::SetGeometryUploadCallback(
        GeometryUploadCallback callback) {
    geometryUploadCallback = callback;
}

void idRenderModelCuttableBeams::SetBeamParameters(float width,
        float repeat, float crossing, float endpoint) {
    beamWidth = std::max(0.0f, width);
    beamRepeat = std::max(0.001f, repeat);
    crossingSize = std::max(0.0f, crossing);
    endpointSize = std::max(0.0f, endpoint);
}

void idRenderModelCuttableBeams::Create(
        const idMaterial* incision, const idMaterial* crossing) {
    materialIncision = incision;
    materialIncisionCross = crossing;
}

void idRenderModelCuttableBeams::Update(
        idCutterGraphManager* manager, int handle) {
    graphManager = manager;
    graphHandle = handle;
    CommitThisFrame();
}

void idRenderModelCuttableBeams::SetBounds(const idBounds& bounds) {
    referenceBounds[0].Set(bounds[0].x - 1.0f, bounds[0].y - 1.0f,
        bounds[0].z - 1.0f);
    referenceBounds[1].Set(bounds[1].x + 1.0f, bounds[1].y + 1.0f,
        bounds[1].z + 1.0f);
    for (int index = 0; index < surfaces.Num(); ++index)
        if (surfaces[index].geometry != nullptr)
            surfaces[index].geometry->bounds = referenceBounds;
}

void idRenderModelCuttableBeams::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    const idMaterial* materials[2] = {
        materialIncision, materialIncisionCross
    };
    for (const idMaterial* material : materials) {
        const std::uint8_t present = material != nullptr ? 1 : 0;
        file->Write(&present, sizeof(present));
        if (present != 0) {
            const char* name = materialNameCallback != nullptr
                ? materialNameCallback(material) : "";
            file->WriteString(name != nullptr ? name : "");
        }
    }
}

bool idRenderModelCuttableBeams::Load(idFile* file) {
    if (file == nullptr) return false;
    const idMaterial** materials[2] = {
        &materialIncision, &materialIncisionCross
    };
    for (const idMaterial** material : materials) {
        std::uint8_t present = 0;
        if (file->Read(&present, sizeof(present)) != sizeof(present))
            return false;
        *material = nullptr;
        if (present != 0) {
            idStr name;
            file->ReadString(name);
            *material = materialResolver != nullptr
                ? materialResolver(name.c_str()) : nullptr;
        }
    }
    return true;
}

void idRenderModelCuttableBeams::UploadSurface(int surfaceIndex,
        const idMaterial* material,
        const idList<idDrawVert, 5>& vertices,
        const idList<std::uint16_t, 5>& indices) {
    if (surfaceIndex < 0 || surfaceIndex >= surfaces.Num()) return;
    idRenderModelSurface& surface = surfaces[surfaceIndex];
    idTriangles* geometry = surface.geometry;
    if (geometry == nullptr) return;
    delete[] geometry->verts;
    delete[] geometry->indexes;
    geometry->verts = vertices.Num() > 0
        ? new (std::nothrow) idDrawVert[vertices.Num()] : nullptr;
    geometry->indexes = indices.Num() > 0
        ? new (std::nothrow) std::uint16_t[indices.Num()] : nullptr;
    if (geometry->verts != nullptr)
        std::memcpy(geometry->verts, vertices.Ptr(),
            vertices.Num() * sizeof(idDrawVert));
    if (geometry->indexes != nullptr)
        std::memcpy(geometry->indexes, indices.Ptr(),
            indices.Num() * sizeof(std::uint16_t));
    geometry->numVerts = geometry->verts != nullptr ? vertices.Num() : 0;
    geometry->numIndexes = geometry->indexes != nullptr ? indices.Num() : 0;
    geometry->vertexBuffer.apiObject = geometry->verts;
    geometry->vertexBuffer.size = geometry->numVerts * sizeof(idDrawVert);
    geometry->indexBuffer.apiObject = geometry->indexes;
    geometry->indexBuffer.size = geometry->numIndexes * sizeof(std::uint16_t);
    surface.material = material;
    if (geometryUploadCallback != nullptr)
        geometryUploadCallback(this, surfaceIndex, geometry);
}

void idRenderModelCuttableBeams::BuildIncisions(
        const graphTree_t& tree) {
    idList<idDrawVert, 5> vertices;
    idList<std::uint16_t, 5> indices;
    idVec3 normal(0.0f, 0.0f, 1.0f), left, up;
    if (graphManager != nullptr)
        graphManager->GetNormalVectors(graphHandle, normal, left, up);
    float textureDistance = 0.0f;
    const float halfWidth = beamWidth * 0.5f;
    for (int branchIndex = 0; branchIndex < tree.branches.Num();
            ++branchIndex) {
        const graphBranch_t& branch = tree.branches[branchIndex];
        textureDistance = 0.0f;
        for (int index = 0; index + 1 < branch.num; ++index) {
            const idVec3& start = tree.positions[branch.index + index];
            const idVec3& end = tree.positions[branch.index + index + 1];
            idVec3 direction = end - start;
            const float length = direction.NormalizeFast();
            if (length <= 0.0f) continue;
            idVec3 side = direction.Cross(normal);
            if (side.NormalizeFast() == 0.0f) side = left;
            side = side * halfWidth;
            const float s0 = textureDistance / beamRepeat;
            textureDistance += length;
            const float s1 = textureDistance / beamRepeat;
            AppendQuad(vertices, indices,
                BeamVertex(start - side, normal, direction, s0, 0.0f),
                BeamVertex(start + side, normal, direction, s0, 1.0f),
                BeamVertex(end + side, normal, direction, s1, 1.0f),
                BeamVertex(end - side, normal, direction, s1, 0.0f));
        }
    }
    UploadSurface(SURFACE_INCISIONS, materialIncision, vertices, indices);
}

void idRenderModelCuttableBeams::BuildIncisionCrossings(
        const graphTree_t& tree) {
    idList<idDrawVert, 5> vertices;
    idList<std::uint16_t, 5> indices;
    idVec3 normal(0.0f, 0.0f, 1.0f), left(1.0f, 0.0f, 0.0f),
        up(0.0f, 1.0f, 0.0f);
    if (graphManager != nullptr)
        graphManager->GetNormalVectors(graphHandle, normal, left, up);
    const idVec3 dx = left * crossingSize;
    const idVec3 dy = up * crossingSize;
    for (int index = 0; index < tree.intersections.Num(); ++index) {
        const idVec3& center = tree.intersections[index];
        AppendQuad(vertices, indices,
            BeamVertex(center - dx - dy, normal, left, 0.0f, 0.0f),
            BeamVertex(center + dx - dy, normal, left, 1.0f, 0.0f),
            BeamVertex(center + dx + dy, normal, left, 1.0f, 1.0f),
            BeamVertex(center - dx + dy, normal, left, 0.0f, 1.0f));
    }
    UploadSurface(SURFACE_INCISIONCROSSINGS, materialIncisionCross,
        vertices, indices);
}

void idRenderModelCuttableBeams::BuildIncisionEndpoints(
        const graphTree_t& tree) {
    idList<idDrawVert, 5> vertices;
    idList<std::uint16_t, 5> indices;
    idVec3 normal(0.0f, 0.0f, 1.0f), left(1.0f, 0.0f, 0.0f),
        up(0.0f, 1.0f, 0.0f);
    if (graphManager != nullptr)
        graphManager->GetNormalVectors(graphHandle, normal, left, up);
    const idVec3 dx = left * endpointSize;
    const idVec3 dy = up * endpointSize;
    for (int index = 0; index < tree.endpoints.Num(); ++index) {
        const idVec3& center = tree.endpoints[index];
        AppendQuad(vertices, indices,
            BeamVertex(center - dx - dy, normal, left, 0.0f, 0.0f),
            BeamVertex(center + dx - dy, normal, left, 1.0f, 0.0f),
            BeamVertex(center + dx + dy, normal, left, 1.0f, 1.0f),
            BeamVertex(center - dx + dy, normal, left, 0.0f, 1.0f));
    }
    UploadSurface(SURFACE_INCISIONENDPOINTS, materialIncisionCross,
        vertices, indices);
}

bool idRenderModelCuttableBeams::UpdateInView(
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    if (graphManager == nullptr ||
            !graphManager->IsGraphValid(graphHandle)) return false;
    graphTree_t tree;
    graphManager->BuildGraphTree(graphHandle, tree);
    BuildIncisions(tree);
    BuildIncisionCrossings(tree);
    BuildIncisionEndpoints(tree);
    return true;
}
