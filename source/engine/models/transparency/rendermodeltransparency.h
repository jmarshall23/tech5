#pragma once

#include "models/rendermodel.h"
#include "models/transparency/jobs/influencespherecull.h"
#include "models/transparency/jobs/transparencysort.h"

struct transparencyViewParms_t {
    idVec3 viewOrigin;
    idMat3 viewAxis;
    float fovX;
    float fovY;
};

class alignas(16) idRenderModelTransparency : public idRenderModel {
public:
    static constexpr int MAX_INFLUENCE_SPHERES = 1024;
    static constexpr int MAX_SEGMENT_ALLOCATIONS = 1024;
    static constexpr int MAX_UNSORTED_QUADS = 4096;

    using MaterialResolver = const idMaterial* (*)(bool emissivePass);
    using SortSubmitCallback = bool (*)(transSortParms_t* parms,
        idRenderModelUpdateTools* tools);
    using BufferReferenceCallback = void (*)(idTriangles* geometry,
        int frameBufferIndex, bool emissivePass);
    using ViewExtractor = bool (*)(const idRenderView* view,
        transparencyViewParms_t& parms);

    idRenderModelTransparency();
    ~idRenderModelTransparency() override;

    static void Init();
    static void Shutdown();
    static void StartFrame();
    static void SetFrameCapacity(int maxSortedQuads);
    static int GetFrameCapacity();
    static void SetRuntimeCallbacks(MaterialResolver materialResolver,
        SortSubmitCallback sortSubmit,
        BufferReferenceCallback bufferReference);
    static void SetViewExtractor(ViewExtractor extractor);
    static void SetSortEnabled(bool enabled);
    static void SetBinningEnabled(bool enabled);
    static void SetEmissivePassEnabled(bool enabled);
    static void SetInfluenceCullDistances(float nearDistance,
        float farDistance);
    static bool AllocateQuadSegment(int numQuads,
        idTransparencyVert*& vertices, float*& quadDepths,
        int*& quadsUsed, bool hasEmissivePass);
    static bool AllocateUnsortedQuadSegment(int numQuads,
        idTransparencyVert*& vertices, int& indexOffset, int& vertCount);
    static const std::uint16_t* GetUnsortedIndices();
    static idTransparencyVert* GetUnsortedVertices();
    static idTransparencyVert* GetUnsortedVertices(int frameBufferIndex);
    static int GetNumUnsortedVertices();
    static int GetCurrentFrameBufferIndex();

    bool UpdateInView(const idRenderView* view,
        const idRenderView* previousView,
        idRenderModelUpdateTools* tools) override;

    void ClearInfluenceSpheres();
    bool AddInfluenceSphere(const idVec3& center, float innerRadius,
        float outerRadius, float angle);

    // Culls the bank filled during the current frame, then advances to the
    // other bank.  The renderer-facing overload converts an idRenderView to
    // these parameters in the renderer integration layer.
    void GenerateVisibleInfluenceSphereList(
        const influenceSphereCullParms_t& viewParms);
    void GenerateVisibleInfluenceSphereList(
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    void AddTransparencySortJob(idRenderModelUpdateTools* tools);
    void GenerateTransparencyRenderList(const idRenderView* currentView);

    const visibleInfluenceSpheres_t& GetVisibleInfluenceSpheres() const;
    int GetNumInfluenceSpheres() const;
    int GetCurrentSphereBank() const { return currentSphereIndex; }

    // Recovered opaque transparency-sort blocks.  Their definitions belong
    // to the renderer sort job and are deliberately not duplicated here.
    transSortParms_t* sortParms;
    transSortResult_t* sortResult;
    influenceSphere_t* influenceSpheres[2];
    int numInfluenceSpheres[2];
    int currentSphereIndex;
    visibleInfluenceSpheres_t* visibleInfluenceSpheres;
    influenceSphereCullParms_t* influenceSphereCullParms;

private:
    idRenderModelTransparency(const idRenderModelTransparency&) = delete;
    idRenderModelTransparency& operator=(
        const idRenderModelTransparency&) = delete;

    static MaterialResolver materialResolver;
    static SortSubmitCallback sortSubmitCallback;
    static BufferReferenceCallback bufferReferenceCallback;
    static ViewExtractor viewExtractor;
};
