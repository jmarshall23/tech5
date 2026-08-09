#pragma once

#include "idlib/containers/array.h"
#include "idlib/geometry/jointtransform.h"
#include "models/rendermodel.h"
#include "models/skeletalanimation/jobs/md6blend.h"
#include "models/skeletalanimation/userchannelexpression.h"

#include <cstdint>

class idDeclMD6;

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

    explicit idTreeAnimator(const idDeclMD6* declaration = nullptr);
    ~idTreeAnimator() override;

    static void SetUpdateCallback(UpdateCallback callback);
    static void SetCommitCallback(CommitCallback callback);
    bool CommitSubclass() override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

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
    static UpdateCallback updateCallback;
    static CommitCallback commitCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTreeAnimator::morphMap_t) == 12,
    "Recovered tree-animator morph-map ABI changed");
#endif
