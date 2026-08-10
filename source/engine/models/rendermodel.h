#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/geometry/drawvert.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/geometry/screenrect.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"
#include "renderer/parmblock.h"

#include <cstdint>

class idDeclRenderParm;
class idDeclSkins;
class idFile;
class idMaterial;
class idRenderModel;
class idRenderModelCommitted;
class idRenderModelUpdateTools;
class idRenderView;
class idRenderWorld;
class idRenderMatrix;
class idSerializer;
class idTriangles;
struct approximateLighting_t;
struct decalParams_t;

enum invalidDecalHandle_t : int;
enum invalidJointIndex_t : int;
using decalHandle_t = idHandle<int, invalidDecalHandle_t, -1>;
using idJointIndex = idIndex<short, invalidJointIndex_t>;

enum renderMode_t : int {
    RENDER_MODE_MANUAL = 0,
    RENDER_MODE_AUTOMATIC = 1,
    RENDER_MODE_BINK = 2
};

enum dimShadow_t : int {
    DIMSHADOW_OFF = 0,
    DIMSHADOW_ON = 1,
    DIMSHADOW_HIGH_QUALITY = 2
};

enum highlightColor_t : int {
    HIGHLIGHT_COLOR_NONE = 0,
    HIGHLIGHT_COLOR_USE = 1,
    HIGHLIGHT_COLOR_LOOT = 2,
    HIGHLIGHT_COLOR_ITEM = 3,
    HIGHLIGHT_COLOR_EXPLODE = 4,
    HIGHLIGHT_COLOR_MAX
};

enum bufferUsageType_t : int {
    BU_DEFAULT = 0,
    BU_STATIC = 1,
    BU_DYNAMIC = 2
};

// Renderer-owned handles recovered here as ABI-only PODs.  Models may retain
// and reference them, but mapping/allocation remains a renderer operation.
class idVertexBuffer {
public:
    int size;
    int offsetInOtherBuffer;
    void* apiObject;
    bufferUsageType_t usage;
};

class idIndexBuffer {
public:
    int size;
    int offsetInOtherBuffer;
    void* apiObject;
    bufferUsageType_t usage;
};

class idJointBuffer {
public:
    int numJoints;
    int offsetInOtherBuffer;
    void* apiObject;
    int flags;
};

class idVertexScaleAndBias {
public:
    idVec3 xyzScale;
    idVec3 xyzBias;
    idVec2 stScale;
    idVec2 stBias;
};

class idTriangles {
public:
    idBounds bounds;
    bool generateNormals;
    int numIndexes;
    int numVerts;
    int detailOffset;
    bool allowGpuHosting;
    idVertexScaleAndBias vsb;
    unsigned int cpuVertexMask;
    idDrawVert* verts;
    std::uint16_t* indexes;
    unsigned int vertexMask;
    idVertexBuffer vertexBuffer;
    idIndexBuffer indexBuffer;
};

#include "renderer/rendermodelparms.h"
#include "renderer/rendermodelsurface.h"

struct sourceSurface_t {
    const idMaterial* mtr;
    int mtrChecksum;
    int renderSurface;
    int firstVertex;
    int lastVertex;
};

struct idRenderParm {
    const idDeclRenderParm* parm;
    parmValue_t value;
};

class idRenderModel {
public:
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using MaterialResolver = const idMaterial* (*)(const char* name,
        bool makeDefault);
    using ParmBlockSaveCallback = bool (*)(const idParmBlock* block,
        idFile* file);
    using ParmBlockLoadCallback = bool (*)(idParmBlock* block,
        idFile* file);
    using SnapshotMaterialCallback = void (*)(idSerializer* serializer,
        const idMaterial*& material);
    using SnapshotParmBlockCallback = void (*)(idSerializer* serializer,
        idParmBlock* block);
    using ScheduleCommitCallback = bool (*)(idRenderModel* model);
    using CommitCallback = void (*)(idRenderModel* model,
        bool subclassChanged);
    using WorldResolver = idRenderWorld* (*)(const idRenderModel* model);
    using IntegerResolver = int (*)(const idRenderModel* model);
    using VisibilityResolver = bool (*)(const idRenderModel* model);
    using ClearOcclusionCallback = void (*)(idRenderModel* model);
    using NameCommitCallback = void (*)(idRenderModel* model,
        const char* name);
    using SurfaceCommitCallback = void (*)(idRenderModel* model,
        const idList<idRenderModelSurface, 85>& surfaces);
    using ParmSetCallback = void (*)(idParmBlock* block,
        const idDeclRenderParm* parm, const parmValue_t& value);
    using SurfaceResourceFreeCallback = void (*)(idRenderModelSurface& surface);
    using DecalCreateCallback = decalHandle_t (*)(idRenderModel* model,
        const decalParams_t* parms, int startTime,
        const idVec3& position, const idVec3& direction,
        idMat3& decalWorldAxis);
    using DecalPositionCallback = bool (*)(idRenderModel* model,
        decalHandle_t handle, const idVec3& position,
        const idMat3& axis);
    using DecalRemoveCallback = bool (*)(idRenderModel* model,
        decalHandle_t handle);

    struct alignas(4) decalData_t {
        decalHandle_t handle;
        idVec3 relativePos;
        idMat3 relativeAxis;
        idJointIndex jointId;
    };

    virtual void Save(idFile* file);
    virtual bool Load(idFile* file);
    virtual void SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock);
    virtual const idDeclSkins* GetSkins() const;
    virtual decalHandle_t AddDecalFromPoint(const decalParams_t* parms,
        int startTime, const idVec3& position, const idVec3& direction,
        idJointIndex joint);
    virtual bool RemoveDecal(decalHandle_t handle);
    virtual void RemoveDecals();
    virtual void FreeSurfaces();
    virtual bool CommitSubclass();
    virtual bool UpdateInView(const idRenderView* view,
        const idRenderView* previousView, idRenderModelUpdateTools* tools);
    virtual const idList<sourceSurface_t, 5>* GetSourceSurfaces() const;
    virtual ~idRenderModel();

    void SetName(const char* modelName);
    const char* GetName() const { return name.c_str(); }
    void AddSurface(const idRenderModelSurface& surface);
    void SetMaxSurfaces(int maximum);
    void FinishSurfaces();
    void CommitThisFrame();
    void Commit();
    void CommitSurfaces();
    void SetViewport(int x, int y, int width, int height);
    void ClearOcclusionQuery();
    void SetParm(const idDeclRenderParm* parm, const parmValue_t& value);
    void SetParm(const idDeclRenderParm* parm, float scalar);
    void SetParm(const idDeclRenderParm* parm, const idVec3& value);
    void SetParm(const idDeclRenderParm* parm, const idVec4& value);
    static void SetMaterialPersistenceCallbacks(MaterialNameCallback name,
        MaterialResolver resolver);
    static void SetParmBlockPersistenceCallbacks(ParmBlockSaveCallback save,
        ParmBlockLoadCallback load);
    static void SetSnapshotPersistenceCallbacks(
        SnapshotMaterialCallback material,
        SnapshotParmBlockCallback parmBlock);
    static void SetRuntimeCallbacks(ScheduleCommitCallback scheduleCommit,
        CommitCallback commit, WorldResolver worldResolver,
        IntegerResolver indexResolver,
        IntegerResolver referenceCountResolver,
        VisibilityResolver visibilityResolver,
        ClearOcclusionCallback clearOcclusion,
        NameCommitCallback commitName,
        SurfaceCommitCallback commitSurfaces);
    static void SetDecalCallbacks(DecalCreateCallback create,
        DecalPositionCallback position, DecalRemoveCallback remove);
    static void SetModelResourceCallbacks(ParmSetCallback setParm,
        SurfaceResourceFreeCallback freeSurfaceResources);
    idParmBlock* GetParmBlock();
    const idParmBlock* GetParmBlock() const;
    bool IsRendered() const;
    int GetNumReferences() const;
    int GetIndex() const;
    idRenderWorld* GetWorld() const;
    const idRenderMatrix& GetModelMatrix() const;
    idParmBlock* GetRenderParmBlock();
    const idParmBlock* GetRenderParmBlock() const;
    const approximateLighting_t& GetApproximateLighting() const;
    void SetLitTransSortFlag();
    bool SetDecalPosition(decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis);
    void GlobalPointToLocal(const idVec3& input, idVec3& output) const;
    void LocalPointToGlobal(const idVec3& input, idVec3& output) const;

    alignas(16) idAtomicString name;
    const char* debugName;
    idVec3 deferredOrigin;
    idMat3 deferredAxis;
    bool useDeferredPosition;
    bool deferredPositionInitialized;
    bool deleteOnSync;
    bool unlinked;
    bool needWriteToSnapshot;
    idRenderModel* nextOnCommitList;
    int needCommitFrameNum;
    idRenderModelCommitted* committed;
    idBounds referenceBounds;
    idRenderModelParms g;
    idStaticParmBlock<32> gameParmBlock;
    idList<idRenderModelSurface, 85> surfaces;
    idStaticList<decalData_t, 16> decalData;

protected:
    idRenderModel();

private:
    void InitDecalData(decalData_t& decal, const decalParams_t* parms,
        int startTime, const idVec3& position, const idVec3& direction);

    static MaterialNameCallback materialNameCallback;
    static MaterialResolver materialResolver;
    static ParmBlockSaveCallback parmBlockSaveCallback;
    static ParmBlockLoadCallback parmBlockLoadCallback;
    static SnapshotMaterialCallback snapshotMaterialCallback;
    static SnapshotParmBlockCallback snapshotParmBlockCallback;
    static ScheduleCommitCallback scheduleCommitCallback;
    static CommitCallback commitCallback;
    static WorldResolver worldResolver;
    static IntegerResolver indexResolver;
    static IntegerResolver referenceCountResolver;
    static VisibilityResolver visibilityResolver;
    static ClearOcclusionCallback clearOcclusionCallback;
    static NameCommitCallback nameCommitCallback;
    static SurfaceCommitCallback surfaceCommitCallback;
    static ParmSetCallback parmSetCallback;
    static SurfaceResourceFreeCallback surfaceResourceFreeCallback;
    static DecalCreateCallback decalCreateCallback;
    static DecalPositionCallback decalPositionCallback;
    static DecalRemoveCallback decalRemoveCallback;
};

bool CompareEqualMat3(const idMat3& left, const idMat3& right);

class idStrRenderModel : public idStr {
public:
    using idStr::idStr;
};

class idRenderModelInfo {
public:
    idRenderModel* model;
    std::uint8_t staticShadowsFromDynamicModel : 1;
    std::uint8_t forceAcceptDimShadows : 1;
    std::uint8_t allowUpShadows : 1;
    std::uint8_t allowHighQualityDimShadows : 1;
    std::uint8_t forceDimShadows : 1;
    std::uint8_t noShadows : 1;
    std::uint8_t noAmbient : 1;
    std::uint8_t allowInline : 1;
    std::uint8_t reserved : 3;
    std::uint8_t rebakeModel : 1;
    std::uint8_t megatexturedModel : 1;
    std::uint8_t occluder : 1;
    std::uint8_t noLocalLighting : 1;
    std::uint8_t privateLightOnly : 1;
    float maxTexelDensity;
    float maxVisibleRange;
    float fadeVisibilityOver;
    float dimShadowClipZ;
    const idMaterial* customMaterial;
    idVec3 scale;
    idColor color;
    idList<idRenderParm, 5> renderParms;
    const idMaterial* parmBlock;
    idStrRenderModel editorModel;
    int traceGroup;
    float radiosityScale;
    float staticReflectionStrength;
    bool ownedByPresentable;
    idRenderModelInfo* next;
};

static_assert(sizeof(sourceSurface_t) == 20,
    "Recovered source-surface ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idVertexBuffer) == 16,
    "Recovered vertex-buffer ABI changed");
static_assert(sizeof(idIndexBuffer) == 16,
    "Recovered index-buffer ABI changed");
static_assert(sizeof(idJointBuffer) == 16,
    "Recovered joint-buffer ABI changed");
static_assert(sizeof(idVertexScaleAndBias) == 40,
    "Recovered vertex scale/bias ABI changed");
static_assert(sizeof(idTriangles) == 132,
    "Recovered triangle-surface ABI changed");
static_assert(sizeof(idRenderModel::decalData_t) == 56,
    "Recovered render-model decal data ABI changed");
#endif
