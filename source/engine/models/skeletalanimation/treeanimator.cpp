#include "models/skeletalanimation/treeanimator.h"

#include <cstring>

idTreeAnimator::UpdateCallback idTreeAnimator::updateCallback = nullptr;
idTreeAnimator::CommitCallback idTreeAnimator::commitCallback = nullptr;

idTreeAnimator::idTreeAnimator(const idDeclMD6* declaration)
    : decl(declaration), morphSkin(-1), initialMorphValue(0.0f),
      currentDeferred(0), commands(nullptr), blendParms(nullptr),
      lastBlendTime(0), reserved(0), useDualQuatSkinning(0),
      skipSerialization(0), updateMorphBuffers(0),
      calcRefBoundsFromJoints(0), originDeltaLookAhead(0),
      clearOriginTransform(0), hasDeferredJoints(0),
      deferredJobJointBuffer(0), nextRenderThreadJointBuffer(0),
      renderThreadJointBuffer(0), currentMorphBuffer(0) {
    std::memset(joints, 0, sizeof(joints));
    std::memset(originDelta, 0, sizeof(originDelta));
    frameBounds[0].Set(0.0f, 0.0f, 0.0f);
    frameBounds[1].Set(0.0f, 0.0f, 0.0f);
    normalizedBounds = frameBounds;
    translatedBounds = frameBounds;
}

idTreeAnimator::~idTreeAnimator() = default;

void idTreeAnimator::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idTreeAnimator::SetCommitCallback(CommitCallback callback) {
    commitCallback = callback;
}

bool idTreeAnimator::CommitSubclass() {
    return commitCallback != nullptr ? commitCallback(this) : false;
}

bool idTreeAnimator::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}
