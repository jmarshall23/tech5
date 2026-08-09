#include "cm/collisionmodel.h"

#include "cm/collisionmodelbuilder.h"
#include "cm/jobs/polygonmodel/polygonmodel.h"
#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "cm/jobs/spheremodel/spheremodel.h"
#include "framework/resourcelist.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/text/str.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <algorithm>
#include <cfloat>
#include <cstdlib>
#include <malloc.h>

namespace {

constexpr std::uint32_t BCM_FILE_ID = 1111706934u;
constexpr int MAX_CM_FILE_COUNT = 1 << 20;
constexpr int MAX_CM_SUBMODEL_SIZE = 16 << 20;

bool ReadExact(idFile* const file, void* const data,
    const unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

bool WriteExact(idFile* const file, const void* const data,
    const unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

} // namespace

void SetupStreamAreaPtrs(streamAreasHeader_t* const header,
    streamAreasPtrs_t& pointers) {
    pointers.streamAreas = reinterpret_cast<streamArea_t*>(header + 1);
    pointers.streamAreaSubModels = reinterpret_cast<std::uint16_t*>(
        pointers.streamAreas + header->numStreamAreas);
    pointers.streamAreaNameBytes = reinterpret_cast<char*>(
        pointers.streamAreaSubModels + header->numStreamAreaSubModels);
}

const cm_subModelData_t* AcquireSubModelData(
    const cm_subModel_t& subModel) {
    InterlockedIncrement(reinterpret_cast<volatile LONG*>(
        const_cast<int*>(&subModel.numUsers)));
    if (*subModel.state == SUBMODEL_STATE_LOADED) {
        return subModel.data;
    }
    InterlockedDecrement(reinterpret_cast<volatile LONG*>(
        const_cast<int*>(&subModel.numUsers)));
    return reinterpret_cast<const cm_subModelData_t*>(&subModel);
}

void ReleaseSubModelData(const cm_subModel_t& subModel,
    const cm_subModelData_t* const data) {
    if (data != reinterpret_cast<const cm_subModelData_t*>(&subModel)) {
        InterlockedDecrement(reinterpret_cast<volatile LONG*>(
            const_cast<int*>(&subModel.numUsers)));
    }
}

idResourceList idCollisionModelLocal::resourceList("cm");

void* idCollisionModelLocal::operator new(const std::size_t size) {
    return _aligned_malloc(size, 16);
}

void idCollisionModelLocal::operator delete(void* const memory) {
    _aligned_free(memory);
}

idCollisionModelLocal::idCollisionModelLocal()
    : binaryFileTime(static_cast<std::uint32_t>(-1)),
      sourceFileTime(static_cast<std::uint32_t>(-1)),
      modelType(CM_POLYGONMODEL), bounds(), contents(0),
      isWorldModel(false), isTraceModel(false), isConvex(false),
      isStreamed(false), streamFilePtr(nullptr), polygonModel{},
      sphereModel(nullptr), streamAreas(nullptr), memoryMappedFile(nullptr) {
    bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
}

idCollisionModelLocal::~idCollisionModelLocal() {
    FreeData();
}

idResourceList* idCollisionModelLocal::GetResourceList() {
    return &resourceList;
}

int idCollisionModelLocal::GetTotalMemory() const {
    if (modelType == CM_SPHEREMODEL) {
        return static_cast<int>(sizeof(*this))
            + (sphereModel != nullptr
                ? static_cast<int>(sphereModel->totalSize) : 0);
    }
    int total = static_cast<int>(sizeof(*this))
        + static_cast<int>(sizeof(cm_modelTreeNode_t))
            * polygonModel.numModelTreeNodes
        + static_cast<int>(sizeof(cm_subModel_t))
            * polygonModel.numSubModels
        + polygonModel.numSubModels;
    for (int index = 0; index < polygonModel.numSubModels; ++index) {
        total += polygonModel.subModels[index].header.totalSize;
    }
    return total;
}

int idCollisionModelLocal::GetLoadedMemory() const {
    if (modelType == CM_SPHEREMODEL) {
        return GetTotalMemory();
    }
    int total = static_cast<int>(sizeof(*this))
        + static_cast<int>(sizeof(cm_modelTreeNode_t))
            * polygonModel.numModelTreeNodes
        + static_cast<int>(sizeof(cm_subModel_t))
            * polygonModel.numSubModels
        + polygonModel.numSubModels;
    for (int index = 0; index < polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data != nullptr) {
            total += data->header.loadedSize;
        }
        ReleaseSubModelData(subModel, data);
    }
    return total;
}

int idCollisionModelLocal::GetMaxResidentMemory(idVec3* const location) const {
    if (location != nullptr) {
        location->Zero();
    }
    return GetTotalMemory();
}

void idCollisionModelLocal::MakeDefault() {
    FreeData();
    modelType = CM_POLYGONMODEL;
    bounds[0].Set(-8.0f, -8.0f, -8.0f);
    bounds[1].Set(8.0f, 8.0f, 8.0f);
    contents = 1;
    isWorldModel = false;
    isTraceModel = false;
    isConvex = true;
    isStreamed = false;
    polygonModel.numModelTreeNodes = 0;
    polygonModel.modelTreeNodes = nullptr;
    polygonModel.numSubModels = 1;
    polygonModel.subModels = static_cast<cm_subModel_t*>(
        _aligned_malloc(sizeof(cm_subModel_t), 16));
    polygonModel.subModelState = static_cast<volatile std::uint8_t*>(
        _aligned_malloc(1, 16));
    cm_subModelData_t* const data = static_cast<cm_subModelData_t*>(
        _aligned_malloc(768, 16));
    if (polygonModel.subModels == nullptr
        || polygonModel.subModelState == nullptr || data == nullptr) {
        _aligned_free(data);
        FreeData();
        return;
    }
    std::memset(polygonModel.subModels, 0, sizeof(cm_subModel_t));
    cm_subModel_t& subModel = polygonModel.subModels[0];
    subModel.header.bounds = bounds;
    subModel.header.totalSize = 608;
    subModel.header.loadedSize = 608;
    subModel.data = idPolygonModelCollisionDetection::SetupSubModelForBounds(
        data, 768, bounds);
    subModel.fileOffset = -1;
    subModel.numUsers = 0;
    subModel.state = polygonModel.subModelState;
    *subModel.state = SUBMODEL_STATE_LOADED;
}

void idCollisionModelLocal::GetBinaryFileName(const char* const modelName,
    idStr& binaryFileName, bool& inMapFolder, bool& isWorld) {
    binaryFileName.Clear();
    inMapFolder = false;
    isWorld = false;
    if (modelName == nullptr) {
        return;
    }
    if (_strnicmp(modelName, "maps/", 5) != 0) {
        char generatedName[256] = {};
        fileSystem->FixLongFilename("generated", "bcm", modelName,
            generatedName, sizeof(generatedName));
        binaryFileName = generatedName;
        return;
    }
    inMapFolder = true;
    const std::size_t length = std::strlen(modelName);
    isWorld = length >= 5 && _stricmp(modelName + length - 5, "world") == 0;
    binaryFileName = modelName;
    binaryFileName.SetFileExtension("bcm");
}

bool idCollisionModelLocal::ReloadIfStale() {
    idStr binaryName;
    bool inMapFolder = false;
    bool world = false;
    GetBinaryFileName(GetName(), binaryName, inMapFolder, world);
    const std::uint32_t binaryTime = fileSystem->GetTimestamp(
        binaryName.c_str(), false);
    if (binaryTime == static_cast<std::uint32_t>(-1)
        && idCollisionModelBuilder::IsAnimatedRenderModel(GetName())) {
        return false;
    }
    if (binaryTime == binaryFileTime
        && (inMapFolder || fileSystem->GetTimestamp(GetName(), false)
            == sourceFileTime)) {
        return false;
    }
    if (binaryTime == binaryFileTime && !inMapFolder) {
        fileSystem->RemoveFile(binaryName.c_str(), FSPATH_BASE);
    }
    LoadResource();
    return true;
}

bool idCollisionModelLocal::Write_Binary() {
    if (modelType != CM_POLYGONMODEL || isStreamed) {
        return false;
    }
    idStr binaryName;
    bool inMapFolder = false;
    bool world = false;
    GetBinaryFileName(GetName(), binaryName, inMapFolder, world);
    idFileLocal file(fileSystem->OpenFileWrite(binaryName.c_str(),
        FSPATH_BASE));
    if (file.file == nullptr) {
        return false;
    }
    const std::uint8_t flags[4] = {
        static_cast<std::uint8_t>(isWorldModel),
        static_cast<std::uint8_t>(isTraceModel),
        static_cast<std::uint8_t>(isConvex), 0 };
    if (!WriteExact(file.file, &BCM_FILE_ID, 4)
        || !WriteExact(file.file, &sourceFileTime, 4)
        || !WriteExact(file.file, &bounds, sizeof(bounds))
        || !WriteExact(file.file, &contents, 4)
        || !WriteExact(file.file, flags, sizeof(flags))
        || !WriteExact(file.file, &polygonModel.numModelTreeNodes, 4)
        || (polygonModel.numModelTreeNodes > 0
            && !WriteExact(file.file, polygonModel.modelTreeNodes,
                static_cast<unsigned int>(sizeof(cm_modelTreeNode_t)
                    * polygonModel.numModelTreeNodes)))
        || !WriteExact(file.file, &polygonModel.numSubModels, 4)) {
        return false;
    }
    for (int index = 0; index < polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        const bool ok = data != nullptr
            && WriteExact(file.file, &subModel.header, sizeof(subModel.header))
            && (subModel.header.totalSize == 32
                || WriteExact(file.file, data,
                    static_cast<unsigned int>(subModel.header.totalSize)));
        ReleaseSubModelData(subModel, data);
        if (!ok) {
            return false;
        }
    }
    return WriteExact(file.file, &BCM_FILE_ID, 4);
}

bool idCollisionModelLocal::Load_Binary() {
    idStr binaryName;
    bool inMapFolder = false;
    bool world = false;
    GetBinaryFileName(GetName(), binaryName, inMapFolder, world);
    idFileLocal file(fileSystem->OpenFileRead(binaryName.c_str(), true,
        false));
    if (file.file == nullptr) {
        return false;
    }
    std::uint32_t magic = 0;
    std::uint8_t flags[4] = {};
    int numTreeNodes = 0;
    int numSubModels = 0;
    if (!ReadExact(file.file, &magic, 4) || magic != BCM_FILE_ID
        || !ReadExact(file.file, &sourceFileTime, 4)
        || !ReadExact(file.file, &bounds, sizeof(bounds))
        || !ReadExact(file.file, &contents, 4)
        || !ReadExact(file.file, flags, sizeof(flags))
        || !ReadExact(file.file, &numTreeNodes, 4)
        || numTreeNodes < 0 || numTreeNodes > MAX_CM_FILE_COUNT) {
        return false;
    }
    isWorldModel = flags[0] != 0;
    isTraceModel = flags[1] != 0;
    isConvex = flags[2] != 0;
    isStreamed = false;
    modelType = CM_POLYGONMODEL;
    polygonModel.numModelTreeNodes = numTreeNodes;
    if (numTreeNodes > 0) {
        polygonModel.modelTreeNodes = static_cast<cm_modelTreeNode_t*>(
            _aligned_malloc(sizeof(cm_modelTreeNode_t) * numTreeNodes, 16));
        if (polygonModel.modelTreeNodes == nullptr
            || !ReadExact(file.file, polygonModel.modelTreeNodes,
                static_cast<unsigned int>(sizeof(cm_modelTreeNode_t)
                    * numTreeNodes))) {
            FreeData();
            return false;
        }
    }
    if (!ReadExact(file.file, &numSubModels, 4) || numSubModels < 0
        || numSubModels > MAX_CM_FILE_COUNT) {
        FreeData();
        return false;
    }
    polygonModel.numSubModels = numSubModels;
    if (numSubModels > 0) {
        polygonModel.subModels = static_cast<cm_subModel_t*>(
            _aligned_malloc(sizeof(cm_subModel_t) * numSubModels, 16));
        polygonModel.subModelState = static_cast<volatile std::uint8_t*>(
            _aligned_malloc(numSubModels, 16));
        if (polygonModel.subModels == nullptr
            || polygonModel.subModelState == nullptr) {
            FreeData();
            return false;
        }
        std::memset(polygonModel.subModels, 0,
            sizeof(cm_subModel_t) * numSubModels);
    }
    for (int index = 0; index < numSubModels; ++index) {
        cm_subModel_t& subModel = polygonModel.subModels[index];
        if (!ReadExact(file.file, &subModel.header, sizeof(subModel.header))
            || subModel.header.totalSize < 32
            || subModel.header.totalSize > MAX_CM_SUBMODEL_SIZE) {
            FreeData();
            return false;
        }
        subModel.fileOffset = -1;
        subModel.numUsers = 0;
        subModel.state = &polygonModel.subModelState[index];
        if (subModel.header.totalSize > 32) {
            subModel.data = static_cast<cm_subModelData_t*>(_aligned_malloc(
                subModel.header.totalSize, 16));
            if (subModel.data == nullptr || !ReadExact(file.file,
                    subModel.data, subModel.header.totalSize)) {
                FreeData();
                return false;
            }
            *subModel.state = SUBMODEL_STATE_LOADED;
        } else {
            subModel.data = nullptr;
            *subModel.state = SUBMODEL_STATE_UNLOADED;
        }
    }
    if (!ReadExact(file.file, &magic, 4) || magic != BCM_FILE_ID) {
        FreeData();
        return false;
    }
    binaryFileTime = file.file->Timestamp();
    return true;
}

void idCollisionModelLocal::LoadResource() {
    FreeData();
    if (!Load_Binary()) {
        MakeDefault();
    }
}

bool idCollisionModelLocal::GetBounds(idBounds& outputBounds) const {
    outputBounds = bounds;
    return true;
}

bool idCollisionModelLocal::GetBox(idBox& box) const {
    box = idBox(bounds);
    return true;
}

bool idCollisionModelLocal::GetContents(int& outputContents) const {
    outputContents = contents;
    return true;
}

bool idCollisionModelLocal::GetVertex(const int vertexFeature,
    idVec3& vertex) const {
    if (modelType == CM_SPHEREMODEL) {
        return false;
    }
    const int subModelIndex = (vertexFeature >> 16) & 0x1FFF;
    const int vertexIndex = vertexFeature & 0xFFFF;
    if (subModelIndex < 0 || subModelIndex >= polygonModel.numSubModels) {
        return false;
    }

    const cm_subModel_t& subModel = polygonModel.subModels[subModelIndex];
    const cm_subModelData_t* const data = AcquireSubModelData(subModel);
    if (data == nullptr || data->header.loadedSize == 32 ||
        vertexIndex < 0 || vertexIndex >= data->numVertices) {
        ReleaseSubModelData(subModel, data);
        return false;
    }
    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, data);
    vertex = pointers.vertices[vertexIndex].p;
    ReleaseSubModelData(subModel, data);
    return true;
}

bool idCollisionModelLocal::GetEdge(const int edgeFeature, idVec3& start,
    idVec3& end) const {
    if (modelType == CM_SPHEREMODEL) {
        return false;
    }
    const int subModelIndex = (edgeFeature >> 16) & 0x1FFF;
    const int edgeIndex = edgeFeature & 0xFFFF;
    if (subModelIndex < 0 || subModelIndex >= polygonModel.numSubModels) {
        return false;
    }

    const cm_subModel_t& subModel = polygonModel.subModels[subModelIndex];
    const cm_subModelData_t* const data = AcquireSubModelData(subModel);
    if (data == nullptr || data->header.loadedSize == 32 || edgeIndex < 0 ||
        edgeIndex >= data->numEdges) {
        ReleaseSubModelData(subModel, data);
        return false;
    }
    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, data);
    const cm_edge_t& edge = pointers.edges[edgeIndex];
    start = pointers.vertices[edge.vertexNum[0]].p;
    end = pointers.vertices[edge.vertexNum[1]].p;
    ReleaseSubModelData(subModel, data);
    return true;
}

bool idCollisionModelLocal::GetPolygon(const int polygonFeature,
    idFixedWinding& winding) const {
    if (modelType == CM_SPHEREMODEL) {
        return false;
    }
    const int subModelIndex = (polygonFeature >> 16) & 0x1FFF;
    const int polygonIndex = polygonFeature & 0xFFFF;
    if (subModelIndex < 0 || subModelIndex >= polygonModel.numSubModels) {
        return false;
    }

    const cm_subModel_t& subModel = polygonModel.subModels[subModelIndex];
    const cm_subModelData_t* const data = AcquireSubModelData(subModel);
    if (data == nullptr || data->header.loadedSize == 32 ||
        polygonIndex < 0 || polygonIndex >= data->numPolygons) {
        ReleaseSubModelData(subModel, data);
        return false;
    }
    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, data);
    winding.Clear();
    const cm_polygon_t& polygon = pointers.polygons[polygonIndex];
    for (int index = 0; index < polygon.numEdges; ++index) {
        const std::uint16_t edgeReference =
            pointers.polygonEdges[polygon.firstEdge + index];
        const cm_edge_t& edge =
            pointers.edges[CM_EdgeIndex(edgeReference)];
        const cm_vertex_t& source = pointers.vertices[
            CM_EdgeStartVertex(edge, edgeReference)];
        idVec5 point;
        point.x = source.p.x;
        point.y = source.p.y;
        point.z = source.p.z;
        point.s = static_cast<float>(source.st[0]);
        point.t = static_cast<float>(source.st[1]);
        winding.AddPoint(point);
    }
    ReleaseSubModelData(subModel, data);
    return true;
}

int idCollisionModelLocal::GetPolytope(const int polytopeFeature,
    idPlane* const planes, const int maxPlanes) const {
    if (modelType == CM_SPHEREMODEL || planes == nullptr ||
        maxPlanes <= 0) {
        return 0;
    }
    const int subModelIndex = (polytopeFeature >> 16) & 0x1FFF;
    const int polytopeIndex = polytopeFeature & 0xFFFF;
    if (subModelIndex < 0 || subModelIndex >= polygonModel.numSubModels) {
        return 0;
    }

    const cm_subModel_t& subModel = polygonModel.subModels[subModelIndex];
    const cm_subModelData_t* const data = AcquireSubModelData(subModel);
    if (data == nullptr || data->header.loadedSize == 32 ||
        polytopeIndex < 0 || polytopeIndex >= data->numPolytopes) {
        ReleaseSubModelData(subModel, data);
        return 0;
    }
    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, data);
    const cm_polytope_t& polytope = pointers.polytopes[polytopeIndex];
    const int count = (std::min)(maxPlanes,
        static_cast<int>(polytope.numPlanes));
    for (int index = 0; index < count; ++index) {
        planes[index] = pointers.polytopePlanes[polytope.firstPlane + index];
    }
    ReleaseSubModelData(subModel, data);
    return count;
}

int idCollisionModelLocal::GetPolytopes(int* const polytopeNumPlanes,
    const int maxPolytopes, idPlane* const planes,
    const int maxPlanes) const {
    if (modelType == CM_SPHEREMODEL || polytopeNumPlanes == nullptr ||
        planes == nullptr || maxPolytopes <= 0 || maxPlanes <= 0) {
        return 0;
    }

    int outputPolytopes = 0;
    int outputPlanes = 0;
    for (int subModelIndex = 0;
         subModelIndex < polygonModel.numSubModels &&
         outputPolytopes < maxPolytopes;
         ++subModelIndex) {
        const cm_subModel_t& subModel =
            polygonModel.subModels[subModelIndex];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data == nullptr || data->header.loadedSize == 32) {
            ReleaseSubModelData(subModel, data);
            continue;
        }
        cm_subModelPtrs_t pointers{};
        idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
            pointers, data);
        for (int polytopeIndex = 0;
             polytopeIndex < data->numPolytopes &&
             outputPolytopes < maxPolytopes;
             ++polytopeIndex) {
            const cm_polytope_t& polytope =
                pointers.polytopes[polytopeIndex];
            const int count = (std::min)(
                static_cast<int>(polytope.numPlanes),
                maxPlanes - outputPlanes);
            if (count <= 0) {
                break;
            }
            polytopeNumPlanes[outputPolytopes++] = count;
            for (int index = 0; index < count; ++index) {
                planes[outputPlanes++] = pointers.polytopePlanes[
                    polytope.firstPlane + index];
            }
        }
        ReleaseSubModelData(subModel, data);
    }
    return outputPolytopes;
}

idIndex<short, invalidJointIndex_t> idCollisionModelLocal::GetJoint(
    const int sphereFeature) const {
    if (sphereModel == nullptr || sphereFeature < 0 ||
        sphereFeature >= sphereModel->numSpheres) {
        return idIndex<short, invalidJointIndex_t>();
    }
    cm_sphereModelPtrs_t pointers{};
    idSphereModelCollisionDetection::SetupCollisionSpherePtrs(
        sphereModel, pointers);
    return idIndex<short, invalidJointIndex_t>(
        static_cast<short>(pointers.joint[sphereFeature]));
}

void idCollisionModelLocal::FreeData() {
    if (memoryMappedFile == nullptr) {
        for (int index = 0; index < polygonModel.numSubModels; ++index) {
            _aligned_free(polygonModel.subModels[index].data);
        }
    }
    _aligned_free(polygonModel.modelTreeNodes);
    _aligned_free(polygonModel.subModels);
    _aligned_free(const_cast<std::uint8_t*>(polygonModel.subModelState));
    polygonModel = {};
    _aligned_free(sphereModel);
    sphereModel = nullptr;
    _aligned_free(streamAreas);
    streamAreas = nullptr;
    streamFilePtr = nullptr;
    memoryMappedFile = nullptr;
    binaryFileTime = static_cast<std::uint32_t>(-1);
    sourceFileTime = static_cast<std::uint32_t>(-1);
}
