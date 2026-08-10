#include "models/transparency/rendermodeltransparency.h"

#include "models/transparency/jobs/transparencybin.h"

#include <array>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <malloc.h>
#include <vector>

namespace {

constexpr int DEFAULT_SORTED_QUADS = 16384;
constexpr int MAX_EMISSIVE_INDICES = 3072;
constexpr float DEG_TO_RAD = 0.01745329251994329577f;

struct transparencyFrameStorage_t {
    int maxSortedQuads = DEFAULT_SORTED_QUADS;
    int numVertsAllocated = 0;
    int numSegmentAllocations = 0;
    int numVertsAllocatedUnsorted = 0;
    int frameBufferIndex = 0;
    bool initialized = false;
    bool sortEnabled = true;
    bool binningEnabled = false;
    bool emissivePassEnabled = true;
    float influenceNearDistance = 1.0f;
    float influenceFarDistance = 100000.0f;
    std::vector<idTransparencyVert> sortedVerts;
    std::vector<float> quadDepths;
    std::vector<std::uint8_t> emissiveQuads;
    std::array<transSortSegmentInfo_t,
        idRenderModelTransparency::MAX_SEGMENT_ALLOCATIONS> segmentInfo{};
    std::vector<std::uint16_t> sortedIndices;
    std::vector<std::uint16_t> emissiveIndices;
    std::vector<idTransparencyVert> unsortedVerts[3];
    std::vector<std::uint16_t> unsortedIndices;
    std::vector<idTransparencyVert> binnedVerts;
    std::vector<std::uint16_t> binnedIndices;
};

transparencyFrameStorage_t frameStorage;

void* AllocateAligned(std::size_t size) {
    void* memory = _aligned_malloc(size, 16);
    if (memory != nullptr) {
        std::memset(memory, 0, size);
    }
    return memory;
}

} // namespace

idRenderModelTransparency::MaterialResolver
    idRenderModelTransparency::materialResolver = nullptr;
idRenderModelTransparency::SortSubmitCallback
    idRenderModelTransparency::sortSubmitCallback = nullptr;
idRenderModelTransparency::BufferReferenceCallback
    idRenderModelTransparency::bufferReferenceCallback = nullptr;
idRenderModelTransparency::ViewExtractor
    idRenderModelTransparency::viewExtractor = nullptr;

idRenderModelTransparency::idRenderModelTransparency()
    : sortParms(static_cast<transSortParms_t*>(
          AllocateAligned(sizeof(transSortParms_t)))),
      sortResult(static_cast<transSortResult_t*>(
          AllocateAligned(16))),
      currentSphereIndex(0),
      visibleInfluenceSpheres(static_cast<visibleInfluenceSpheres_t*>(
          AllocateAligned(sizeof(visibleInfluenceSpheres_t)))),
      influenceSphereCullParms(static_cast<influenceSphereCullParms_t*>(
          AllocateAligned(sizeof(influenceSphereCullParms_t)))) {
    influenceSpheres[0] = static_cast<influenceSphere_t*>(
        AllocateAligned(sizeof(influenceSphere_t) * MAX_INFLUENCE_SPHERES));
    influenceSpheres[1] = static_cast<influenceSphere_t*>(
        AllocateAligned(sizeof(influenceSphere_t) * MAX_INFLUENCE_SPHERES));
    numInfluenceSpheres[0] = 0;
    numInfluenceSpheres[1] = 0;

    g.noInteractions = 1;
    g.noShadow = 1;
    g.addAlways = 1;
    for (int index = 0; index < 2; ++index) {
        idTriangles* const geometry = new idTriangles{};
        geometry->bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
        geometry->bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
        geometry->vertexMask = 3167;
        geometry->cpuVertexMask = 3167;
        geometry->allowGpuHosting = true;
        idRenderModelSurface surface{};
        surface.material = materialResolver != nullptr
            ? materialResolver(index != 0) : nullptr;
        surface.materialNum = index;
        surface.geometry = geometry;
        surface.geometryIsReference = false;
        AddSurface(surface);
    }
}

idRenderModelTransparency::~idRenderModelTransparency() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        if (!surfaces[index].geometryIsReference) {
            delete surfaces[index].geometry;
            surfaces[index].geometry = nullptr;
        }
    }
    _aligned_free(influenceSphereCullParms);
    _aligned_free(visibleInfluenceSpheres);
    _aligned_free(influenceSpheres[1]);
    _aligned_free(influenceSpheres[0]);
    _aligned_free(sortResult);
    _aligned_free(sortParms);
}

void idRenderModelTransparency::Init() {
    if (frameStorage.initialized) return;
    const int sortedQuads = (std::max)(2, frameStorage.maxSortedQuads);
    frameStorage.sortedVerts.resize(sortedQuads * 4);
    frameStorage.quadDepths.resize(sortedQuads);
    frameStorage.emissiveQuads.resize(sortedQuads);
    frameStorage.sortedIndices.resize(sortedQuads * 6);
    frameStorage.emissiveIndices.resize(MAX_EMISSIVE_INDICES);
    for (std::vector<idTransparencyVert>& vertices :
            frameStorage.unsortedVerts) {
        vertices.resize(MAX_UNSORTED_QUADS * 4);
    }
    frameStorage.unsortedIndices.resize(MAX_UNSORTED_QUADS * 6);
    frameStorage.binnedVerts.resize(sortedQuads * 4);
    frameStorage.binnedIndices.resize(sortedQuads * 6);
    for (int quad = 0; quad < MAX_UNSORTED_QUADS; ++quad) {
        const std::uint16_t base = static_cast<std::uint16_t>(quad * 4);
        std::uint16_t* const indices =
            frameStorage.unsortedIndices.data() + quad * 6;
        indices[0] = base;
        indices[1] = static_cast<std::uint16_t>(base + 2);
        indices[2] = static_cast<std::uint16_t>(base + 3);
        indices[3] = base;
        indices[4] = static_cast<std::uint16_t>(base + 3);
        indices[5] = static_cast<std::uint16_t>(base + 1);
    }
    frameStorage.initialized = true;
    frameStorage.frameBufferIndex = 0;
    frameStorage.numVertsAllocated = 0;
    frameStorage.numSegmentAllocations = 0;
    frameStorage.numVertsAllocatedUnsorted = 0;
}

void idRenderModelTransparency::Shutdown() {
    frameStorage.sortedVerts.clear();
    frameStorage.sortedVerts.shrink_to_fit();
    frameStorage.quadDepths.clear();
    frameStorage.quadDepths.shrink_to_fit();
    frameStorage.emissiveQuads.clear();
    frameStorage.emissiveQuads.shrink_to_fit();
    frameStorage.sortedIndices.clear();
    frameStorage.sortedIndices.shrink_to_fit();
    frameStorage.emissiveIndices.clear();
    frameStorage.emissiveIndices.shrink_to_fit();
    for (std::vector<idTransparencyVert>& vertices :
            frameStorage.unsortedVerts) {
        vertices.clear();
        vertices.shrink_to_fit();
    }
    frameStorage.unsortedIndices.clear();
    frameStorage.unsortedIndices.shrink_to_fit();
    frameStorage.binnedVerts.clear();
    frameStorage.binnedVerts.shrink_to_fit();
    frameStorage.binnedIndices.clear();
    frameStorage.binnedIndices.shrink_to_fit();
    frameStorage.initialized = false;
    frameStorage.numVertsAllocated = 0;
    frameStorage.numSegmentAllocations = 0;
    frameStorage.numVertsAllocatedUnsorted = 0;
}

void idRenderModelTransparency::StartFrame() {
    Init();
    frameStorage.numVertsAllocated = 0;
    frameStorage.numSegmentAllocations = 0;
    frameStorage.numVertsAllocatedUnsorted = 0;
    frameStorage.frameBufferIndex = (frameStorage.frameBufferIndex + 1) % 3;
}

void idRenderModelTransparency::SetFrameCapacity(
        const int maxSortedQuads) {
    const int capacity = (std::max)(2, maxSortedQuads);
    if (capacity == frameStorage.maxSortedQuads) return;
    const bool wasInitialized = frameStorage.initialized;
    if (wasInitialized) Shutdown();
    frameStorage.maxSortedQuads = capacity;
    if (wasInitialized) Init();
}

int idRenderModelTransparency::GetFrameCapacity() {
    return frameStorage.maxSortedQuads;
}

void idRenderModelTransparency::SetRuntimeCallbacks(
        const MaterialResolver material,
        const SortSubmitCallback sortSubmit,
        const BufferReferenceCallback bufferReference) {
    materialResolver = material;
    sortSubmitCallback = sortSubmit;
    bufferReferenceCallback = bufferReference;
}

void idRenderModelTransparency::SetViewExtractor(
        const ViewExtractor extractor) {
    viewExtractor = extractor;
}

void idRenderModelTransparency::SetSortEnabled(const bool enabled) {
    frameStorage.sortEnabled = enabled;
}

void idRenderModelTransparency::SetBinningEnabled(const bool enabled) {
    frameStorage.binningEnabled = enabled;
}

void idRenderModelTransparency::SetEmissivePassEnabled(const bool enabled) {
    frameStorage.emissivePassEnabled = enabled;
}

void idRenderModelTransparency::SetInfluenceCullDistances(
        const float nearDistance, const float farDistance) {
    frameStorage.influenceNearDistance = (std::max)(0.0f, nearDistance);
    frameStorage.influenceFarDistance = (std::max)(
        frameStorage.influenceNearDistance, farDistance);
}

bool idRenderModelTransparency::AllocateQuadSegment(const int numQuads,
        idTransparencyVert*& vertices, float*& depths, int*& quadsUsed,
        const bool hasEmissivePass) {
    vertices = nullptr;
    depths = nullptr;
    quadsUsed = nullptr;
    Init();
    if (numQuads <= 0 ||
        frameStorage.numVertsAllocated / 4 + numQuads >=
            frameStorage.maxSortedQuads ||
        frameStorage.numSegmentAllocations >=
            MAX_SEGMENT_ALLOCATIONS - 1) {
        return false;
    }
    transSortSegmentInfo_t& segment = frameStorage.segmentInfo[
        frameStorage.numSegmentAllocations++];
    segment.segmentOffset = frameStorage.numVertsAllocated / 4;
    segment.quadsAllocated = numQuads;
    segment.quadsUsed = 0;
    segment.emissivePass = hasEmissivePass;
    vertices = frameStorage.sortedVerts.data() +
        frameStorage.numVertsAllocated;
    depths = frameStorage.quadDepths.data() + segment.segmentOffset;
    quadsUsed = &segment.quadsUsed;
    frameStorage.numVertsAllocated += numQuads * 4;
    return true;
}

bool idRenderModelTransparency::AllocateUnsortedQuadSegment(
        const int numQuads, idTransparencyVert*& vertices,
        int& indexOffset, int& vertCount) {
    vertices = nullptr;
    indexOffset = 0;
    vertCount = 0;
    Init();
    if (numQuads <= 0 ||
        frameStorage.numVertsAllocatedUnsorted / 4 + numQuads >=
            MAX_UNSORTED_QUADS) {
        return false;
    }
    vertices = frameStorage.unsortedVerts[
        frameStorage.frameBufferIndex].data() +
        frameStorage.numVertsAllocatedUnsorted;
    indexOffset = 6 * (frameStorage.numVertsAllocatedUnsorted / 4);
    vertCount = 4 * numQuads;
    frameStorage.numVertsAllocatedUnsorted += vertCount;
    return true;
}

const std::uint16_t* idRenderModelTransparency::GetUnsortedIndices() {
    Init();
    return frameStorage.unsortedIndices.data();
}

idTransparencyVert* idRenderModelTransparency::GetUnsortedVertices() {
    Init();
    return frameStorage.unsortedVerts[
        frameStorage.frameBufferIndex].data();
}

idTransparencyVert* idRenderModelTransparency::GetUnsortedVertices(
        const int frameBufferIndex) {
    Init();
    if (frameBufferIndex < 0 || frameBufferIndex >= 3) return nullptr;
    return frameStorage.unsortedVerts[frameBufferIndex].data();
}

int idRenderModelTransparency::GetNumUnsortedVertices() {
    return frameStorage.numVertsAllocatedUnsorted;
}

int idRenderModelTransparency::GetCurrentFrameBufferIndex() {
    return frameStorage.frameBufferIndex;
}

bool idRenderModelTransparency::UpdateInView(
        const idRenderView* const currentView,
        const idRenderView* const nextView,
        idRenderModelUpdateTools* const tools) {
    GenerateVisibleInfluenceSphereList(currentView,
        nextView != nullptr ? nextView : currentView, tools);
    AddTransparencySortJob(tools);
    GenerateTransparencyRenderList(currentView);
    return surfaces.Num() > 0 && surfaces[0].geometry != nullptr &&
        surfaces[0].geometry->numIndexes > 0;
}

void idRenderModelTransparency::ClearInfluenceSpheres() {
    numInfluenceSpheres[currentSphereIndex] = 0;
}

bool idRenderModelTransparency::AddInfluenceSphere(const idVec3& center,
    float innerRadius, float outerRadius, float angle) {
    int& count = numInfluenceSpheres[currentSphereIndex];
    if (influenceSpheres[currentSphereIndex] == nullptr ||
        count >= MAX_INFLUENCE_SPHERES) {
        return false;
    }

    influenceSphere_t& sphere = influenceSpheres[currentSphereIndex][count++];
    sphere.center = center;
    sphere.innerRadius = innerRadius;
    sphere.outerRadius = outerRadius;
    sphere.angle = angle;
    return true;
}

void idRenderModelTransparency::GenerateVisibleInfluenceSphereList(
    const influenceSphereCullParms_t& viewParms) {
    if (visibleInfluenceSpheres == nullptr ||
        influenceSphereCullParms == nullptr) {
        return;
    }

    *influenceSphereCullParms = viewParms;
    influenceSphereCullParms->influenceSpheres =
        influenceSpheres[currentSphereIndex];
    influenceSphereCullParms->numInfluenceSpheres =
        numInfluenceSpheres[currentSphereIndex];
    influenceSphereCullParms->visibleInfluenceSpheres =
        visibleInfluenceSpheres;

    CullInfluenceSpheresForView(influenceSphereCullParms);
    currentSphereIndex ^= 1;
}

void idRenderModelTransparency::GenerateVisibleInfluenceSphereList(
        const idRenderView*, const idRenderView* const nextView,
        idRenderModelUpdateTools*) {
    if (visibleInfluenceSpheres == nullptr) return;
    transparencyViewParms_t view{};
    if (nextView == nullptr || viewExtractor == nullptr ||
        !viewExtractor(nextView, view)) {
        visibleInfluenceSpheres->numSpheres = 0;
        return;
    }
    influenceSphereCullParms_t parms{};
    parms.nearDist = frameStorage.influenceNearDistance;
    parms.farDist = frameStorage.influenceFarDistance;
    parms.fov.Set(
        std::tan(view.fovX * DEG_TO_RAD * 0.5f),
        std::tan(view.fovY * DEG_TO_RAD * 0.5f));
    parms.viewOrg = view.viewOrigin;
    parms.viewFwd = view.viewAxis[0];
    parms.viewLeft = view.viewAxis[1];
    parms.viewUp = view.viewAxis[2];
    GenerateVisibleInfluenceSphereList(parms);
}

void idRenderModelTransparency::AddTransparencySortJob(
        idRenderModelUpdateTools* const tools) {
    Init();
    if (sortParms == nullptr || sortResult == nullptr) return;
    std::memset(sortResult, 0, sizeof(*sortResult));
    std::memset(frameStorage.emissiveQuads.data(), 0,
        frameStorage.emissiveQuads.size());
    sortParms->verts = frameStorage.sortedVerts.data();
    sortParms->numQuadsToSort = frameStorage.numVertsAllocated / 4;
    sortParms->quadDepths = frameStorage.quadDepths.data();
    sortParms->emissiveQuads = frameStorage.emissiveQuads.data();
    sortParms->segmentInfo = frameStorage.segmentInfo.data();
    sortParms->numSegmentAllocations =
        frameStorage.numSegmentAllocations;
    sortParms->collapse = false;
    sortParms->sort = frameStorage.sortEnabled;
    sortParms->indices = frameStorage.sortedIndices.data();
    sortParms->maxIndices = static_cast<int>(
        frameStorage.sortedIndices.size());
    sortParms->indices2 = frameStorage.emissiveIndices.data();
    sortParms->maxIndices2 = static_cast<int>(
        frameStorage.emissiveIndices.size());
    sortParms->sortResult = sortResult;

    if (sortSubmitCallback != nullptr &&
        sortSubmitCallback(sortParms, tools)) {
        return;
    }
    TransparencySortQuads(sortParms);
    TransparencyTriIndGen(sortParms, 0);
    TransparencyEmissiveTriIndGen(sortParms, 0);
}

void idRenderModelTransparency::GenerateTransparencyRenderList(
        const idRenderView* const currentView) {
    if (sortResult == nullptr || surfaces.Num() < 2 ||
        surfaces[0].geometry == nullptr ||
        surfaces[1].geometry == nullptr) {
        return;
    }

    int numVertices = sortResult->numCollapsedVerts;
    int numIndices = sortResult->numSortedQuads * 6;
    int numEmissiveQuads = frameStorage.emissivePassEnabled
        ? sortResult->numEmissiveQuads : 0;
    idTransparencyVert* renderVertices = frameStorage.sortedVerts.data();
    std::uint16_t* renderIndices = frameStorage.sortedIndices.data();

    transparencyViewParms_t view{};
    if (frameStorage.binningEnabled && currentView != nullptr &&
        viewExtractor != nullptr && viewExtractor(currentView, view) &&
        numVertices > 0 && numIndices > 0) {
        std::vector<bin_t> bins(TRANSPARENCY_BIN_COUNT);
        std::vector<node_t> nodes(TRANSPARENCY_BIN_NODE_COUNT);
        std::vector<idTransparencyVert> temporary(
            frameStorage.sortedVerts.size());
        std::vector<int> remap(frameStorage.sortedVerts.size());
        deferredTransparencyBinParms_t parms{};
        parms.verts = frameStorage.sortedVerts.data();
        parms.numVerts = numVertices;
        parms.indices = frameStorage.sortedIndices.data();
        parms.numIndices = numIndices;
        parms.viewOrigin = view.viewOrigin;
        parms.viewAxis = view.viewAxis;
        parms.fovX = std::tan(view.fovX * DEG_TO_RAD * 0.5f);
        parms.fovY = std::tan(view.fovY * DEG_TO_RAD * 0.5f);
        parms.bins = bins.data();
        parms.numBins = 0;
        parms.nodes = nodes.data();
        parms.numNodes = 0;
        parms.tempBinVerts = temporary.data();
        parms.numBinVerts = 0;
        parms.maxBinVerts = static_cast<int>(temporary.size());
        parms.vertexRemap = remap.data();
        parms.binVerts = frameStorage.binnedVerts.data();
        parms.binIndices = frameStorage.binnedIndices.data();
        parms.numBinIndices = 0;
        parms.maxBinIndices = static_cast<int>(
            frameStorage.binnedIndices.size());
        BinQuads(&parms);
        renderVertices = frameStorage.binnedVerts.data();
        renderIndices = frameStorage.binnedIndices.data();
        numVertices = parms.numBinVerts;
        numIndices = parms.numBinIndices;
        numEmissiveQuads = 0;
    }

    idRenderModelSurface& sortedSurface = surfaces[0];
    sortedSurface.material = materialResolver != nullptr
        ? materialResolver(false) : sortedSurface.material;
    sortedSurface.geometry->numVerts = numVertices;
    sortedSurface.geometry->numIndexes = numIndices;
    sortedSurface.geometry->verts =
        reinterpret_cast<idDrawVert*>(renderVertices);
    sortedSurface.geometry->indexes = renderIndices;
    if (bufferReferenceCallback != nullptr) {
        bufferReferenceCallback(sortedSurface.geometry,
            frameStorage.frameBufferIndex, false);
    }

    idRenderModelSurface& emissiveSurface = surfaces[1];
    emissiveSurface.material = materialResolver != nullptr
        ? materialResolver(true) : emissiveSurface.material;
    emissiveSurface.geometry->numVerts = numEmissiveQuads * 4;
    emissiveSurface.geometry->numIndexes = numEmissiveQuads * 6;
    emissiveSurface.geometry->verts = reinterpret_cast<idDrawVert*>(
        frameStorage.sortedVerts.data());
    emissiveSurface.geometry->indexes =
        frameStorage.emissiveIndices.data();
    if (bufferReferenceCallback != nullptr) {
        bufferReferenceCallback(emissiveSurface.geometry,
            frameStorage.frameBufferIndex, true);
    }

    std::memset(sortResult, 0, sizeof(*sortResult));
}

const visibleInfluenceSpheres_t&
idRenderModelTransparency::GetVisibleInfluenceSpheres() const {
    static const visibleInfluenceSpheres_t empty{};
    return visibleInfluenceSpheres != nullptr
        ? *visibleInfluenceSpheres : empty;
}

int idRenderModelTransparency::GetNumInfluenceSpheres() const {
    return numInfluenceSpheres[currentSphereIndex];
}
