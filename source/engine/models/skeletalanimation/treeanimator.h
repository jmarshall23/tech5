#pragma once

#include "idlib/containers/array.h"
#include "idlib/geometry/jointtransform.h"
#include "gamelib/animstack/animstacktypes.h"
#include "models/rendermodel.h"
#include "models/skeletalanimation/animation.h"
#include "models/skeletalanimation/jobs/md6blend.h"
#include "models/skeletalanimation/md6skel.h"
#include "models/skeletalanimation/taginfo.h"
#include "models/skeletalanimation/userchannelexpression.h"

#include <cstdint>

class idDeclMD6;
class idAnimStack;
class idBitMsg;
class idDeclSkins;
class idFile;
class idJointGroupCollection;
class idMD6Allocator;
class idMD6Anim;
class idMD6Model;
class idMD6Node;
class idParallelJobList;
class idPropsCollection;
class idSerializer;

enum meshKitComponents_t : int {
    MESH_KIT_HEADS = 0,
    MESH_KIT_GEAR,
    MESH_KIT_GORE,
    MESH_KIT_NUM
};

class idTreeAnimator : public idRenderModel {
public:
    enum jointArray_t : int {
        JOINTS_GAME_REFERENCE = 0,
        JOINTS_GAME_FINAL,
        JOINTS_DEFERRED_REFERENCE,
        JOINTS_DEFERRED_FINAL,
        NUM_JOINT_ARRAYS
    };

    struct morphMap_t {
        std::uint8_t* map;
        idArray<idVertexBuffer*, 2> buffers;
    };

    struct meshHandle_t {
        idList<int, 5> indices;
        idStr name;
    };

    using UpdateCallback = bool (*)(idTreeAnimator* animator,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using CommitCallback = bool (*)(idTreeAnimator* animator);
    using AnimationResolver = const idMD6Anim* (*)(
        const idDeclMD6* declaration, const char* nameOrAlias);
    using SkinsResolver = const idDeclSkins* (*)(
        const idTreeAnimator* animator);
    using SkinIndexCallback = int (*)(const idDeclSkins* skins,
        const char* name);
    using BufferSyncCallback = void (*)(idTreeAnimator* animator,
        int pose, const idJointMat* joints, int numJoints);
    using MorphBufferCallback = void (*)(idTreeAnimator* animator,
        int meshIndex, int bufferIndex, const std::uint8_t* values,
        int valueCount);
    using TreeStoreCallback = bool (*)(const idMD6Model* model,
        int timeMilliseconds, int ticksPerSecond, const idAnimStack& stack,
        idMD6Node* root, idBitMsg& nodes, idBitMsg& leaves,
        idBitMsg& modifiers);
    using TreeReadCallback = idMD6Node* (*)(const idAnimStack& stack,
        idMD6Allocator* allocator, idBitMsg& nodes, idBitMsg& leaves,
        idBitMsg& modifiers);

    explicit idTreeAnimator(const idDeclMD6* declaration = nullptr);
    ~idTreeAnimator() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void SetCommitCallback(CommitCallback callback);
    static void SetRuntimeCallbacks(AnimationResolver animationResolver,
        SkinsResolver skinsResolver, SkinIndexCallback skinIndex,
        BufferSyncCallback bufferSync, MorphBufferCallback morphBuffer);
    static void SetTreePersistenceCallbacks(TreeStoreCallback store,
        TreeReadCallback read);

    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    void SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) override;
    const idDeclSkins* GetSkins() const override;
    decalHandle_t AddDecalFromPoint(const decalParams_t* parms,
        int startTime, const idVec3& position, const idVec3& direction,
        idJointIndex joint) override;
    void FreeSurfaces() override;
    const idList<sourceSurface_t, 5>* GetSourceSurfaces() const override;
    bool CommitSubclass() override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

    idPropsCollection* GetPropsCollection();
    const idPropsCollection* GetPropsCollection() const;
    const char* GetModelDefName() const;
    idJointGroupCollection* GetJointGroupCollection();
    const idJointGroupCollection* GetJointGroupCollection() const;

    const idQuat& GetLastOriginRotation() const;
    const idVec3& GetLastOriginTranslation() const;
    bool IsDeltaFudged() const;
    int GetLastOriginDeltaTime() const;
    void SetRemoveOriginRotation(bool removeRotation);
    bool GetRemoveOriginTranslation() const;
    void SetOriginDeltaLookAhead(bool lookAhead);
    void GetJointList(const char* jointNames,
        idList<idJointIndex, 5>& jointList) const;
    void ShowSkel() const;
    void CalcFrameBoundsFromJoints();
    void SyncJoints(int time);
    void UpdateTime(int time);

    bool GetModelSpaceJointBindTransform(idJointIndex joint,
        idVec3& origin, idMat3& axis) const;
    bool GetModelSpaceJointTransform(animationPose_t pose,
        idJointIndex joint, idVec3& origin, idMat3& axis) const;
    bool GetWorldSpaceJointTransform(animationPose_t pose,
        idJointIndex joint, idVec3& origin, idMat3& axis) const;
    bool GetModelSpaceAttachmentTransform(idJointIndex joint,
        const idVec3& translationOffset, const idQuat& rotationOffset,
        idVec3& origin, idMat3& axis) const;
    bool GetWorldSpaceAttachmentTransform(idJointIndex joint,
        const idVec3& translationOffset, const idQuat& rotationOffset,
        idVec3& origin, idMat3& axis) const;
    bool GetModelSpaceJointFrameDeltas(const idJointIndex* indices,
        int numIndices, idVec3* translationDeltas,
        idMat3* rotationDeltas) const;
    bool GetWorldSpaceJointFrameDeltas(const idJointIndex* indices,
        int numIndices, idVec3* translationDeltas,
        idMat3* rotationDeltas) const;
    bool GetWorldSpaceAttachmentFrameDeltas(idJointIndex joint,
        const idVec3& translationOffset, const idQuat& rotationOffset,
        idVec3& translationDelta, idMat3& rotationDelta) const;
    bool GetModelSpaceTagTransform(const tagData_t& tag,
        idVec3& origin, idMat3& axis) const;
    bool GetWorldSpaceTagTransform(const tagData_t& tag,
        idVec3& origin, idMat3& axis) const;

    int NumJoints() const;
    const char* GetJointName(idJointIndex joint) const;
    md6JointHandle_t GetJointHandle(idJointIndex joint) const;
    idJointIndex GetJointIndex(const char* name) const;
    idJointIndex GetJointIndex(md6JointHandle_t handle) const;
    idJointIndex GetFirstChild(idJointIndex joint) const;
    idJointIndex GetFirstChild(const char* jointName) const;
    void SetUseDualQuaternion(bool useDualQuaternion);
    void GetLastOriginDeltas(idVec3& translation) const;
    void GetLastOriginDeltas(idQuat& rotation, idVec3& translation) const;
    void GetLastOriginDeltas(idMat3& rotation, idVec3& translation) const;
    void GetTotalOriginTransform(idQuat& rotation,
        idVec3& translation) const;
    const idVec3& GetVisualOffset() const;
    void ApplyOriginDeltas(const idMat3& rotationDelta,
        const idVec3& translationDelta, idMat3& rotation,
        idVec3& translation, idVec3& velocity) const;
    void ApplyOriginDeltas(const idQuat& rotationDelta,
        const idVec3& translationDelta, idQuat& rotation,
        idVec3& translation, idVec3& velocity) const;

    void SetKitSkin(const char* skin);
    float GetBlendedUserChannel(idUserChannelIndex index) const;
    idStr ShowKit(meshKitComponents_t component, const char* name);
    void HideKit(meshKitComponents_t component, const char* name);
    void HideKitsExcept(meshKitComponents_t component, const char* name);
    void HideAllKits(meshKitComponents_t component);
    int GetMeshIndex(const char* meshName) const;

    const idMD6Anim* GetSingleAnimFrame(idJointMat* outputJoints,
        aliasHandle_t alias, int time, const idVec3& offset,
        bool removeOriginOffset) const;
    const idMD6Anim* GetSingleAnimFrame(idJointMat* outputJoints,
        const char* animationName, int time, const idVec3& offset,
        bool removeOriginOffset) const;
    static const idMD6Anim* LookupAnimByAlias(
        const idDeclMD6* declaration, const char* animationName);
    void SetFrameFromAnim(const idMD6Anim* animation, int frame,
        bool removeOriginOffset, bool updateBounds,
        const idVec3* offset = nullptr);

    void InitializeSurfaces();
    void InitializeMorphMaps();
    void FreeMorphMaps();
    void SetMorphSkin(const char* skinName, int skinIndex,
        float morphAmount);
    void MorphLocation(float amount, int location);
    void ClearMorphPoints();
    void BitShiftMorphPoints(unsigned int shift);

    void BlendTreeInternal(int currentTime, int previousTime,
        int gameMillisecondsPerFrame, int ticksPerSecond, idMD6Node* tree,
        idParallelJobList* parallelJobList, float* localRotation,
        float* localScale, float* localTranslation, float* localUserChannels);

    static void UpdateTree(const idMD6Model* model, int timeMilliseconds,
        int ticksPerSecond, idMD6Node* root);
    static void FreeTree(idMD6Allocator* allocator, idMD6Node* root);
    static bool StoreTree(const idMD6Model* model, int timeMilliseconds,
        int ticksPerSecond, const idAnimStack& stack, idMD6Node* root,
        idBitMsg& nodes, idBitMsg& leaves, idBitMsg& modifiers);
    static idMD6Node* ReadTree(const idAnimStack& stack,
        idMD6Allocator* allocator, idBitMsg& nodes, idBitMsg& leaves,
        idBitMsg& modifiers);

    void ClearJointMods();
    void SetJointMat3x4(animationPose_t pose, idJointIndex joint,
        jointModTransform_t transform, const idMat3x4& matrix,
        bool overrideUserChannels = false);
    void SetJointPosAxisScale(animationPose_t pose, idJointIndex joint,
        jointModTransform_t transform, const idVec3& position,
        const idMat3& axis, const idVec3& scale);
    void SetJointPos(animationPose_t pose, idJointIndex joint,
        jointModTransform_t transform, const idVec3& position);
    void SetJointAxis(animationPose_t pose, idJointIndex joint,
        jointModTransform_t transform, const idMat3& axis);
    void SetJointScale(animationPose_t pose, idJointIndex joint,
        jointModTransform_t transform, const idVec3& scale);

    const idDeclMD6* decl;
    idList<bool, 17> meshVisibility;
    std::int16_t morphSkin;
    idIndex<short, invalidJointIndex_t> skipJointForBounds;
    float initialMorphValue;
    int currentDeferred;
    md6AnimCommand_t* commands;
    idList<idMD6Blend::jointMod_t, 17> jointMods[2];
    idMD6Blend::blendParms_t* blendParms;
    idJointMat* joints[NUM_JOINT_ARRAYS];
    idList<float, 17> userChannels[2];
    md6OriginDelta_t* originDelta[2];
    int lastBlendTime;
    std::uint8_t reserved : 1;
    std::uint8_t useDualQuatSkinning : 1;
    std::uint8_t skipSerialization : 1;
    std::uint8_t updateMorphBuffers : 1;
    std::uint8_t calcRefBoundsFromJoints : 1;
    std::uint8_t originDeltaLookAhead : 1;
    std::uint8_t clearOriginTransform : 1;
    std::uint8_t hasDeferredJoints : 1;
    idBounds frameBounds;
    idBounds normalizedBounds;
    idBounds translatedBounds;
    idArray<idJointBuffer, NUM_JOINT_ARRAYS> jointBuffers;
    idList<float, 5> userChannelBuffers[NUM_JOINT_ARRAYS];
    int deferredJobJointBuffer;
    int nextRenderThreadJointBuffer;
    int renderThreadJointBuffer;
    idList<morphMap_t, 16> morphMaps;
    int currentMorphBuffer;
    idList<idUserChannelExpression, 5> wrinkleMapExpressions;

private:
    idMD6Blend::jointMod_t* FindOrCreateJointMod(animationPose_t pose,
        idJointIndex joint, jointModTransform_t transform);
    const idMD6Blend::jointMod_t* FindJointMod(animationPose_t pose,
        idJointIndex joint) const;
    void LatchDeferredState();
    static void UpdateTree_r(const idMD6Model* model, int timeMilliseconds,
        int ticksPerSecond, idMD6Node* root);
    static void FreeTree_r(idMD6Allocator* allocator, idMD6Node* root);

    static UpdateCallback updateCallback;
    static CommitCallback commitCallback;
    static AnimationResolver animationResolverCallback;
    static SkinsResolver skinsResolverCallback;
    static SkinIndexCallback skinIndexCallback;
    static BufferSyncCallback bufferSyncCallback;
    static MorphBufferCallback morphBufferCallback;
    static TreeStoreCallback treeStoreCallback;
    static TreeReadCallback treeReadCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTreeAnimator::morphMap_t) == 12,
    "Recovered tree-animator morph-map ABI changed");
#endif
