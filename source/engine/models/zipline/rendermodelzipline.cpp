#include "models/zipline/rendermodelzipline.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>

namespace {

constexpr float kPi = 3.14159265358979323846f;

bool WriteExact(idFile* file, const void* data, unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

bool ReadExact(idFile* file, void* data, unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
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

idRenderModelZipline::UpdateCallback idRenderModelZipline::updateCallback =
    nullptr;
idRenderModelZipline::MaterialNameCallback
    idRenderModelZipline::materialNameCallback = nullptr;
idRenderModelZipline::MaterialResolver
    idRenderModelZipline::materialResolver = nullptr;

idRenderModelZipline::idRenderModelZipline()
    : material(nullptr), splineMaxSubdivisions(2),
      splineTessellationDistance(30), cableDiameter(1.0f),
      cableSubdivisions(5), time(0.0f), fractionBeforeLerp(0.5f),
      downDirection(false), dirty(2), sweptPoints(new sweptPoint_t[16]),
      currentSourceSpline(0), parms(new zipLineGenParms_t()),
      currentBuffer(0), numVertices(0), numIndices(0) {
    sourceSpline[0] = new idNonUniformBSpline<idVec3>();
    sourceSpline[1] = new idNonUniformBSpline<idVec3>();
    std::memset(sweptPoints, 0, sizeof(sweptPoint_t) * 16);
    std::memset(parms, 0, sizeof(*parms));
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(indexBuffer, 0, sizeof(indexBuffer));
    g.noInteractions = 1;
    g.noShadow = 1;
    BuildModel(nullptr, splineTessellationDistance, splineMaxSubdivisions,
        cableDiameter, cableSubdivisions);
}

idRenderModelZipline::~idRenderModelZipline() {
    FreeGeometry();
    delete[] sweptPoints;
    delete parms;
    delete sourceSpline[1];
    delete sourceSpline[0];
}

void idRenderModelZipline::FreeGeometry() {
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

void idRenderModelZipline::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelZipline::SetMaterialPersistenceCallbacks(
        MaterialNameCallback nameCallback, MaterialResolver resolver) {
    materialNameCallback = nameCallback;
    materialResolver = resolver;
}

void idRenderModelZipline::BuildModel(const idMaterial* newMaterial,
        int tessellationDistance, int maximumSubdivisions, float diameter,
        int radialSubdivisions) {
    material = newMaterial;
    splineTessellationDistance = (std::max)(1,
        (std::min)(1024, tessellationDistance));
    splineMaxSubdivisions = (std::max)(2,
        (std::min)(512, maximumSubdivisions));
    cableDiameter = (std::max)(0.1f, (std::min)(128.0f, diameter));
    cableSubdivisions = (std::max)(3,
        (std::min)(16, radialSubdivisions));

    for (int index = 0; index < cableSubdivisions; ++index) {
        const float angle = (2.0f * kPi * index) / cableSubdivisions;
        sweptPoints[index].pos.Set(std::cos(angle) * cableDiameter,
            std::sin(angle) * cableDiameter, 0.0f);
        sweptPoints[index].tangent.Set(-std::sin(angle),
            std::cos(angle), 0.0f);
        sweptPoints[index].s = static_cast<float>(index) /
            cableSubdivisions;
    }

    FreeGeometry();
    idTriangles* geometry = new idTriangles;
    std::memset(geometry, 0, sizeof(*geometry));
    const int maximumVertices = splineMaxSubdivisions * cableSubdivisions;
    const int maximumIndices = 6 * (splineMaxSubdivisions - 1) *
        cableSubdivisions;
    geometry->verts = new idDrawVert[maximumVertices];
    geometry->indexes = new std::uint16_t[maximumIndices];
    geometry->vertexMask = geometry->cpuVertexMask = 0x1Fu;
    geometry->allowGpuHosting = true;
    geometry->bounds[0].Zero();
    geometry->bounds[1].Zero();
    idRenderModelSurface surface{};
    surface.material = material;
    surface.geometry = geometry;
    surface.geometryIsReference = false;
    AddSurface(surface);
    g.origin.Zero();
    deferredOrigin.Zero();
    dirty = 2;
}

void idRenderModelZipline::SetSpline(
        const idCurve_Spline<idVec3>* spline, float sampleTime,
        float lerpFraction, bool travelsDown) {
    idNonUniformBSpline<idVec3>* destination =
        sourceSpline[currentSourceSpline];
    destination->Clear();
    ClearBounds(referenceBounds);
    if (spline != nullptr) {
        const int count = (std::min)(spline->values.Num(),
            idNonUniformBSpline<idVec3>::MAX_KNOTS);
        for (int index = 0; index < count; ++index) {
            destination->AddValue(spline->times[index],
                spline->values[index]);
            AddPoint(referenceBounds, spline->values[index]);
        }
    }
    if (destination->GetNumValues() == 0) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
    if (surfaces.Num() > 0 && surfaces[0].geometry != nullptr)
        surfaces[0].geometry->bounds = referenceBounds;
    time = sampleTime;
    fractionBeforeLerp = (std::max)(0.2f,
        (std::min)(0.8f, lerpFraction));
    downDirection = travelsDown;
    dirty = 2;
}

bool idRenderModelZipline::UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    if (surfaces.Num() == 0 || surfaces[0].geometry == nullptr ||
            dirty <= 0) {
        return false;
    }
    --dirty;
    idNonUniformBSpline<idVec3>* spline = sourceSpline[currentSourceSpline];
    if (spline->GetNumValues() < 2) return false;
    idTriangles* geometry = surfaces[0].geometry;
    parms->controlSpline = spline;
    parms->splineTessellationDistance = splineTessellationDistance;
    parms->splineMaxSubdivisions = splineMaxSubdivisions;
    parms->cableSubdivisions = cableSubdivisions;
    parms->cableDiameter = cableDiameter;
    parms->sweptPoints = sweptPoints;
    parms->time = time;
    parms->fractionBeforeLerp = fractionBeforeLerp;
    parms->downDirection = downDirection;
    parms->maxVertices = splineMaxSubdivisions * cableSubdivisions;
    parms->maxIndices = 6 * (splineMaxSubdivisions - 1) *
        cableSubdivisions;
    parms->vertices = geometry->verts;
    parms->indices = geometry->indexes;
    parms->numVertices = &numVertices;
    parms->numIndices = &numIndices;
    GenZipline(parms);
    geometry->numVerts = numVertices;
    geometry->numIndexes = numIndices;
    geometry->bounds = referenceBounds;
    currentSourceSpline ^= 1;
    currentBuffer = (currentBuffer + 1) % 3;
    CommitThisFrame();
    return true;
}

void idRenderModelZipline::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    const std::uint8_t hasMaterial = material != nullptr ? 1u : 0u;
    WriteExact(file, &hasMaterial, sizeof(hasMaterial));
    if (hasMaterial != 0) {
        const char* name = materialNameCallback != nullptr
            ? materialNameCallback(material) : "";
        file->WriteString(name != nullptr ? name : "");
    }
    WriteExact(file, &splineTessellationDistance,
        sizeof(splineTessellationDistance));
    WriteExact(file, &splineMaxSubdivisions, sizeof(splineMaxSubdivisions));
    WriteExact(file, &cableDiameter, sizeof(cableDiameter));
    WriteExact(file, &cableSubdivisions, sizeof(cableSubdivisions));
    WriteExact(file, &time, sizeof(time));
    WriteExact(file, &fractionBeforeLerp, sizeof(fractionBeforeLerp));
    const std::uint8_t travelsDown = downDirection ? 1u : 0u;
    WriteExact(file, &travelsDown, sizeof(travelsDown));
    const idNonUniformBSpline<idVec3>* spline =
        sourceSpline[currentSourceSpline];
    const std::int32_t count = spline->GetNumValues();
    WriteExact(file, &count, sizeof(count));
    for (int index = 0; index < count; ++index) {
        WriteExact(file, &spline->times[index], sizeof(float));
        WriteExact(file, &spline->values[index], sizeof(idVec3));
    }
}

bool idRenderModelZipline::Load(idFile* file) {
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
    int loadedTessellationDistance = 0;
    int loadedMaxSubdivisions = 0;
    float loadedDiameter = 0.0f;
    int loadedCableSubdivisions = 0;
    float loadedTime = 0.0f;
    float loadedFraction = 0.0f;
    std::uint8_t loadedDown = 0;
    std::int32_t count = 0;
    if (!ReadExact(file, &loadedTessellationDistance,
                sizeof(loadedTessellationDistance)) ||
            !ReadExact(file, &loadedMaxSubdivisions,
                sizeof(loadedMaxSubdivisions)) ||
            !ReadExact(file, &loadedDiameter, sizeof(loadedDiameter)) ||
            !ReadExact(file, &loadedCableSubdivisions,
                sizeof(loadedCableSubdivisions)) ||
            !ReadExact(file, &loadedTime, sizeof(loadedTime)) ||
            !ReadExact(file, &loadedFraction, sizeof(loadedFraction)) ||
            !ReadExact(file, &loadedDown, sizeof(loadedDown)) ||
            !ReadExact(file, &count, sizeof(count)) || count < 0 ||
            count > idNonUniformBSpline<idVec3>::MAX_KNOTS) {
        return false;
    }
    idNonUniformBSpline<idVec3> loadedSpline;
    ClearBounds(referenceBounds);
    for (int index = 0; index < count; ++index) {
        float knotTime = 0.0f;
        idVec3 value;
        if (!ReadExact(file, &knotTime, sizeof(knotTime)) ||
                !ReadExact(file, &value, sizeof(value))) {
            return false;
        }
        loadedSpline.AddValue(knotTime, value);
        AddPoint(referenceBounds, value);
    }
    BuildModel(loadedMaterial, loadedTessellationDistance,
        loadedMaxSubdivisions, loadedDiameter,
        loadedCableSubdivisions);
    *sourceSpline[currentSourceSpline] = loadedSpline;
    time = loadedTime;
    fractionBeforeLerp = (std::max)(0.2f,
        (std::min)(0.8f, loadedFraction));
    downDirection = loadedDown != 0;
    if (count == 0) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
    dirty = 2;
    CommitThisFrame();
    return true;
}
