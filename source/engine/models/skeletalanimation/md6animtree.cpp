#include "models/skeletalanimation/md6animtree.h"

#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6phasetrack.h"
#include "models/skeletalanimation/md6skel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace idMD6AnimTree {
namespace {

constexpr std::int16_t PAUSE_USE_STACK_TOP = 1;
constexpr std::int16_t PAUSE_CLEAR_NON_MOD_WEIGHTS = 2;
constexpr std::int16_t PAUSE_OVERRIDE_FRAME_BOUNDS = 4;
TagFilterCallback tagFilterCallback = nullptr;

template<typename Type, int DestinationTag, int SourceTag>
void CopyList(idList<Type, DestinationTag>& destination,
        const idList<Type, SourceTag>& source) {
    destination.SetNum(source.Num());
    for (int index = 0; index < source.Num(); ++index)
        destination[index] = source[index];
}

int FrameCount(const idMD6Leaf& leaf) {
    return leaf.anim != nullptr && leaf.anim->animData != nullptr
        ? leaf.anim->animData->numFrames : 0;
}

float WrappedFrame(const idMD6LeafPlay& leaf, float frame) {
    const int count = FrameCount(leaf);
    if (count <= 0) return 0.0f;
    if (leaf.wrapMode == idMD6Leaf::WRAP_REPEAT) {
        frame = std::fmod(frame, static_cast<float>(count));
        if (frame < 0.0f) frame += count;
        return frame;
    }
    return (std::max)(0.0f, (std::min)(frame,
        static_cast<float>(count - 1)));
}

void SelectOneDimensional(idMD6BlendBranch_Base& branch, const float value) {
    const int count = (std::min)(branch.coordinateList.Num(),
        branch.animationList.Num());
    if (count <= 0) {
        branch.left = branch.right = nullptr;
        branch.currentAlpha = 0.0f;
        return;
    }
    int right = 0;
    while (right < count && branch.coordinateList[right] < value) ++right;
    if (right <= 0) {
        branch.left = branch.right = branch.animationList[0];
        branch.currentAlpha = 0.0f;
    } else if (right >= count) {
        branch.left = branch.right = branch.animationList[count - 1];
        branch.currentAlpha = 0.0f;
    } else {
        const int left = right - 1;
        branch.left = branch.animationList[left];
        branch.right = branch.animationList[right];
        const float range = branch.coordinateList[right] -
            branch.coordinateList[left];
        branch.currentAlpha = range != 0.0f
            ? (value - branch.coordinateList[left]) / range : 0.0f;
    }
    branch.targetAlpha = branch.currentAlpha;
}

} // namespace

void SetTagFilterCallback(TagFilterCallback callback) {
    tagFilterCallback = callback;
}

bool IsValid(const idMD6Node* node) {
    return node != nullptr && node->type <= idMD6Node::NODE_TAG_FILTER;
}

void Clear(idMD6LeafPlay& leaf) {
    std::memset(&leaf, 0, sizeof(leaf));
    leaf.type = idMD6Node::NODE_LEAF_PLAY;
    leaf.rateScale = 1.0f;
}

void Init(idMD6LeafPlay& leaf, const idMD6Anim* animation,
        const int gameTime, const int syncGroup, const int syncEnabled,
        const float rate, const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup) {
    Clear(leaf);
    leaf.anim = animation;
    leaf.weightGroup = static_cast<std::uint8_t>(weightGroup);
    leaf.wrapMode = static_cast<std::uint8_t>(wrapMode);
    leaf.startTime = gameTime;
    leaf.rateScale = rate;
    leaf.syncGroup = static_cast<std::uint8_t>(syncGroup);
    leaf.syncEnabled = static_cast<std::uint8_t>(syncEnabled != 0);
}

void Restart(idMD6LeafPlay& leaf, const int gameTime, int,
        const int startFrame, const idMD6Leaf::wrapMode_t wrapMode) {
    leaf.wrapMode = static_cast<std::uint8_t>(wrapMode);
    SetFrame(leaf, gameTime, 1000,
        static_cast<unsigned short>((std::max)(0, startFrame)));
    ++leaf.initCounter;
}

int GetFrameRate(const idMD6Leaf& leaf) {
    return leaf.anim != nullptr && leaf.anim->animData != nullptr
        ? leaf.anim->animData->frameRate : 0;
}

int GetLength(const idMD6Leaf& leaf, const int ticksPerSecond) {
    const int rate = GetFrameRate(leaf);
    return rate > 0 ? FrameCount(leaf) * ticksPerSecond / rate : 0;
}

int GetFrameTime(const idMD6LeafPlay& leaf, const int frame) {
    const int rate = GetFrameRate(leaf);
    return rate > 0 && leaf.rateScale != 0.0f
        ? leaf.startTime + static_cast<int>(frame * 1000.0f /
            (rate * leaf.rateScale)) : leaf.startTime;
}

int GetAnimLength(const idMD6LeafPlay& leaf, const int ticksPerSecond,
        const bool scaled) {
    const int length = GetLength(leaf, ticksPerSecond);
    return scaled && leaf.rateScale != 0.0f
        ? static_cast<int>(length / std::fabs(leaf.rateScale)) : length;
}

float GetFloatFrame(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond) {
    if (ticksPerSecond <= 0) return 0.0f;
    return WrappedFrame(leaf, (gameTime - leaf.startTime) * leaf.rateScale *
        GetFrameRate(leaf) / static_cast<float>(ticksPerSecond));
}

unsigned short GetFrame(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond) {
    return static_cast<unsigned short>(GetFloatFrame(leaf, gameTime,
        ticksPerSecond));
}

void SetFloatFrame(idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond, const float frame) {
    const int rate = GetFrameRate(leaf);
    if (rate <= 0 || leaf.rateScale == 0.0f) leaf.startTime = gameTime;
    else leaf.startTime = gameTime - static_cast<int>(frame * ticksPerSecond /
        (rate * leaf.rateScale));
}

void SetFrame(idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond, const unsigned short frame) {
    SetFloatFrame(leaf, gameTime, ticksPerSecond, static_cast<float>(frame));
}

void SetRateScale(idMD6LeafPlay& leaf, const int gameTime, const float scale,
        const int ticksPerSecond) {
    const float frame = GetFloatFrame(leaf, gameTime, ticksPerSecond);
    leaf.rateScale = scale;
    SetFloatFrame(leaf, gameTime, ticksPerSecond, frame);
}

int GetLoopCount(const idMD6LeafPlay& leaf, const int startTime,
        const int endTime, const int ticksPerSecond) {
    const int count = FrameCount(leaf);
    if (count <= 0 || leaf.wrapMode != idMD6Leaf::WRAP_REPEAT) return 0;
    const float start = (startTime - leaf.startTime) * leaf.rateScale *
        GetFrameRate(leaf) / ticksPerSecond;
    const float end = (endTime - leaf.startTime) * leaf.rateScale *
        GetFrameRate(leaf) / ticksPerSecond;
    return static_cast<int>(std::floor(end / count) -
        std::floor(start / count));
}

bool IsPlaying(const idMD6LeafPlay& leaf, const int startTime,
        const int endTime, const int ticksPerSecond,
        const bool includeLastFrame) {
    if (leaf.anim == nullptr || leaf.anim->animData == nullptr) return false;
    if (leaf.wrapMode == idMD6Leaf::WRAP_REPEAT) return true;
    const float first = GetFloatFrame(leaf, startTime, ticksPerSecond);
    const float rawEnd = (endTime - leaf.startTime) * leaf.rateScale *
        GetFrameRate(leaf) / ticksPerSecond;
    const float last = FrameCount(leaf) - (includeLastFrame ? 0.0f : 1.0f);
    return first < last && rawEnd <= last;
}

void Clear(idMD6LeafPause& leaf) {
    leaf.type = idMD6Node::NODE_LEAF_PAUSE;
    leaf.anim = nullptr;
    leaf.weightGroup = MD6_WEIGHTGROUP_ALL;
    leaf.wrapMode = idMD6Leaf::WRAP_CLAMP;
    leaf.initCounter = 0;
    leaf.currentDeferred = 0;
    leaf.flags = 0;
    leaf.frame = 0.0f;
    leaf.bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    leaf.bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void Init(idMD6LeafPause& leaf, const idMD6Anim* animation,
        const float frame, const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup) {
    Clear(leaf);
    leaf.anim = animation;
    leaf.frame = frame;
    leaf.wrapMode = static_cast<std::uint8_t>(wrapMode);
    leaf.weightGroup = static_cast<std::uint8_t>(weightGroup);
}

void SetUseStackTop(idMD6LeafPause& leaf, const bool enabled) {
    leaf.flags = enabled ? leaf.flags | PAUSE_USE_STACK_TOP
        : leaf.flags & ~PAUSE_USE_STACK_TOP;
}

void SetClearNonModWeights(idMD6LeafPause& leaf, const bool enabled) {
    leaf.flags = enabled ? leaf.flags | PAUSE_CLEAR_NON_MOD_WEIGHTS
        : leaf.flags & ~PAUSE_CLEAR_NON_MOD_WEIGHTS;
}

void SetOverrideFrameBounds(idMD6LeafPause& leaf, const bool enabled) {
    leaf.flags = enabled ? leaf.flags | PAUSE_OVERRIDE_FRAME_BOUNDS
        : leaf.flags & ~PAUSE_OVERRIDE_FRAME_BOUNDS;
}

void SetNumAnimMods(idMD6LeafPause& leaf, const int count) {
    for (idMD6OpaqueList& list : leaf.animMods)
        list.num = (std::max)(0, (std::min)(count, list.size));
}

void Init(idMD6Branch& branch, idMD6Node* left, idMD6Node* right,
        const idMD6Blend::blendOp_t operation,
        const idMD6Blend::originBlend_t originBlend, const float currentAlpha,
        const float targetAlpha, const float alphaRate,
        const md6WeightGroup_t filterGroup,
        const idMD6Branch::blendType_t blendType) {
    branch.type = idMD6Node::NODE_BRANCH;
    branch.left = left;
    branch.right = right;
    branch.leftTimeOverride = branch.rightTimeOverride = -1;
    branch.filterGroup = static_cast<std::uint8_t>(filterGroup);
    branch.op = static_cast<std::uint8_t>(operation);
    branch.originBlend = static_cast<std::uint8_t>(originBlend);
    branch.currentAlpha = currentAlpha;
    branch.targetAlpha = targetAlpha;
    branch.alphaRate = alphaRate;
    branch.blendType = blendType;
}

void UpdateCurrentAlpha(idMD6Branch& branch, const int time,
        const int previousTime, const int ticksPerSecond) {
    if (branch.currentAlpha == branch.targetAlpha || ticksPerSecond <= 0) return;
    float step = branch.alphaRate * (time - previousTime) / ticksPerSecond;
    if (branch.blendType == idMD6Branch::BLEND_EASEIN)
        step *= branch.currentAlpha;
    else if (branch.blendType == idMD6Branch::BLEND_EASEOUT)
        step *= 1.0f - branch.currentAlpha;
    else if (branch.blendType == idMD6Branch::BLEND_EASEIN_EASEOUT)
        step *= 4.0f * branch.currentAlpha * (1.0f - branch.currentAlpha);
    if (branch.targetAlpha < branch.currentAlpha) step = -std::fabs(step);
    else step = std::fabs(step);
    branch.currentAlpha = step >= 0.0f
        ? (std::min)(branch.targetAlpha, branch.currentAlpha + step)
        : (std::max)(branch.targetAlpha, branch.currentAlpha + step);
}

bool IsBlendFinished(const idMD6Branch& branch) {
    return branch.currentAlpha == branch.targetAlpha;
}
bool IsChildBlendedOut(const idMD6Branch& branch, const idMD6Node* child) {
    return (child == branch.left && branch.currentAlpha >= 1.0f) ||
        (child == branch.right && branch.currentAlpha <= 0.0f);
}
bool IsBlendingOut(const idMD6Branch& branch) {
    return branch.targetAlpha < branch.currentAlpha;
}
bool IsBlendingIn(const idMD6Branch& branch) {
    return branch.targetAlpha > branch.currentAlpha;
}

void Init(idMD6BlendAdditiveBranch& branch, idMD6Node* baseAnimation,
        const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations, const float coordinate,
        const md6WeightGroup_t weightGroup) {
    branch.type = idMD6Node::NODE_BLENDA_BRANCH;
    CopyList(branch.coordinateList, coordinates);
    CopyList(branch.animationList, animations);
    branch.baseAnimation = baseAnimation;
    branch.currentCoordinate = coordinate;
    branch.activeCoordinate = coordinate;
    branch.filterGroup = static_cast<std::uint8_t>(weightGroup);
    branch.op = idMD6Blend::BOP_ADD_RIGHT;
    Update(branch, true);
}

void Update(idMD6BlendAdditiveBranch& branch, const bool force) {
    if (!force && branch.activeCoordinate == branch.currentCoordinate) return;
    branch.activeCoordinate = branch.currentCoordinate;
    SelectOneDimensional(branch, branch.activeCoordinate);
    if (branch.left == nullptr) branch.left = branch.baseAnimation;
}

void Init(idMD6BlendBranch& branch, const std::uint8_t dimensions,
        const idList<idUserChannelIndex, 5>& userChannelIndices,
        const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations,
        const idList<float, 5>& initialCoordinates,
        const md6WeightGroup_t weightGroup, const int flags) {
    branch.type = idMD6Node::NODE_BLEND_BRANCH;
    branch.numDimensions = dimensions;
    CopyList(branch.userChannelIndices, userChannelIndices);
    CopyList(branch.coordinateList, coordinates);
    CopyList(branch.animationList, animations);
    CopyList(branch.currentCoordinate, initialCoordinates);
    CopyList(branch.activeCoordinate, initialCoordinates);
    branch.isAngleWrapped = (flags & MD6_BLENDBRANCH_ANGLEWRAP) != 0;
    branch.filterGroup = static_cast<std::uint8_t>(weightGroup);
    branch.op = idMD6Blend::BOP_LERP;
    Update(branch, true, true);
}

void Update(idMD6BlendBranch& branch, const bool force, const bool snap) {
    if (branch.currentCoordinate.Num() == 0) return;
    bool changed = force || branch.activeCoordinate.Num() !=
        branch.currentCoordinate.Num();
    for (int index = 0; !changed && index < branch.currentCoordinate.Num();
            ++index)
        changed = branch.activeCoordinate[index] != branch.currentCoordinate[index];
    if (!changed) return;
    branch.activeCoordinate = branch.currentCoordinate;
    // One-dimensional branches use exact interval blending. Higher-dimensional
    // branches select the nearest sample, which is stable outside the hull.
    if (branch.numDimensions <= 1) {
        SelectOneDimensional(branch, branch.activeCoordinate[0]);
    } else {
        int best = -1;
        float bestDistance = 1.0e30f;
        for (int animation = 0; animation < branch.animationList.Num(); ++animation) {
            float distance = 0.0f;
            for (int dimension = 0; dimension < branch.numDimensions; ++dimension) {
                const int coordinate = animation * branch.numDimensions + dimension;
                if (coordinate >= branch.coordinateList.Num()) break;
                float delta = branch.coordinateList[coordinate] -
                    branch.activeCoordinate[dimension];
                if (branch.isAngleWrapped) {
                    while (delta > 180.0f) delta -= 360.0f;
                    while (delta < -180.0f) delta += 360.0f;
                }
                distance += delta * delta;
            }
            if (distance < bestDistance) { bestDistance = distance; best = animation; }
        }
        branch.left = branch.right = best >= 0 ? branch.animationList[best] : nullptr;
        branch.currentAlpha = branch.targetAlpha = snap ? 0.0f : branch.currentAlpha;
    }
}

void Init(idMD6FusionBranch& branch, const std::uint8_t dimensions,
        const idList<idUserChannelIndex, 5>& userChannelIndices,
        const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations,
        const idList<float, 5>& initialCoordinates,
        const md6WeightGroup_t weightGroup, const int flags) {
    Init(static_cast<idMD6BlendBranch&>(branch), dimensions,
        userChannelIndices, coordinates, animations, initialCoordinates,
        weightGroup, flags);
    branch.type = idMD6Node::NODE_FUSION_BRANCH;
    branch.phaseToFrameLookupData.Clear();
}

void Update(idMD6FusionBranch& branch, const bool force, int, int,
        const idMD6Skel*) {
    Update(static_cast<idMD6BlendBranch&>(branch), force, false);
}

void Init(idMD6TagFilter& filter, const std::uint8_t groupIndex,
        const unsigned int tagMask, const std::uint8_t bias,
        const idDeclAnimWebTagGroup* group) {
    filter.type = idMD6Node::NODE_TAG_FILTER;
    filter.tagGroupIndex = groupIndex;
    filter.tagMask = tagMask;
    filter.tagBias = bias;
    filter.tagGroup = group;
}

bool Filter(const idMD6TagFilter& filter, const unsigned int tag,
        const idMD6DebugFilterLogicHelper_t& helper) {
    return tagFilterCallback != nullptr
        ? tagFilterCallback(filter, tag, helper)
        : (tag & filter.tagMask) == filter.tagMask;
}

void Init(idMD6BestLeaf& best, const std::uint8_t groupIndex,
        const unsigned int desiredTag, const std::uint8_t bias,
        const idList<idMD6Node*, 5>& leaves,
        const idList<unsigned int, 5>& tags,
        const idList<idMD6Filter*, 5>& filters,
        const unsigned int defaultTag, const idDeclAnimWebTagGroup* group) {
    best.type = idMD6Node::NODE_BEST_LEAF;
    CopyList(best.leafList, leaves);
    CopyList(best.tagList, tags);
    CopyList(best.filterList, filters);
    best.tagGroup = group;
    best.desiredTag = desiredTag;
    best.activeTag = defaultTag;
    best.defaultTag = defaultTag;
    best.bestLeafIndex = 0;
    best.tagBias = bias;
    best.tagGroupIndex = groupIndex;
    Init(best.tagGroupFilter, groupIndex, desiredTag, bias, group);
    Update(best);
}

void Update(idMD6BestLeaf& best) {
    int selected = -1;
    for (int index = 0; index < best.leafList.Num(); ++index) {
        const unsigned int tag = index < best.tagList.Num()
            ? best.tagList[index] : 0;
        bool accepted = (tag & best.desiredTag) == best.desiredTag;
        if (accepted && index < best.filterList.Num() &&
                best.filterList[index] != nullptr &&
                best.filterList[index]->type == idMD6Node::NODE_TAG_FILTER)
            accepted = Filter(*static_cast<idMD6TagFilter*>(
                best.filterList[index]), tag, best.debugFilterLogicHelper);
        if (accepted) { selected = index; break; }
    }
    if (selected < 0) {
        for (int index = 0; index < best.tagList.Num(); ++index)
            if (best.tagList[index] == best.defaultTag) { selected = index; break; }
    }
    if (selected < 0 && best.leafList.Num() > 0) selected = 0;
    best.bestLeafIndex = static_cast<std::uint16_t>((std::max)(0, selected));
    best.activeTag = selected >= 0 && selected < best.tagList.Num()
        ? best.tagList[selected] : best.defaultTag;
}

} // namespace idMD6AnimTree
