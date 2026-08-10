#include "models/skeletalanimation/md6animtree.h"

#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6phasetrack.h"
#include "models/skeletalanimation/md6skel.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <limits>
#include <vector>

namespace idMD6AnimTree {
namespace {

constexpr std::int16_t PAUSE_USE_STACK_TOP = 1;
constexpr std::int16_t PAUSE_CLEAR_NON_MOD_WEIGHTS = 2;
constexpr std::int16_t PAUSE_OVERRIDE_FRAME_BOUNDS = 4;
TagFilterCallback tagFilterCallback = nullptr;
unsigned int bestLeafRandomSeed = 0x6D2B79F5u;

unsigned int PopCount(unsigned int value) {
    value = value - ((value >> 1) & 0x55555555u);
    value = (value & 0x33333333u) + ((value >> 2) & 0x33333333u);
    value = (value + (value >> 4)) & 0x0F0F0F0Fu;
    return (value * 0x01010101u) >> 24;
}

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
        const int cycleFrames = (std::max)(1, count - 1);
        frame = std::fmod(frame, static_cast<float>(cycleFrames));
        if (frame < 0.0f) frame += cycleFrames;
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

float WrapAngleDelta(float delta) {
    while (delta > 180.0f) delta -= 360.0f;
    while (delta < -180.0f) delta += 360.0f;
    return delta;
}

float CoordinateDelta(const idMD6BlendBranch& branch, const int point,
        const int dimension, const float target) {
    const int offset = point * branch.numDimensions + dimension;
    if (offset < 0 || offset >= branch.coordinateList.Num()) return 0.0f;
    float delta = branch.coordinateList[offset] - target;
    return branch.isAngleWrapped && dimension == 0
        ? WrapAngleDelta(delta) : delta;
}

bool SolveLinearSystem(const int dimensions, float* matrix, float* values,
        float* output) {
    if (dimensions <= 0 || dimensions > 6 || matrix == nullptr ||
            values == nullptr || output == nullptr) return false;
    constexpr float epsilon = 1.0e-8f;
    for (int pivot = 0; pivot < dimensions; ++pivot) {
        int best = pivot;
        for (int row = pivot + 1; row < dimensions; ++row)
            if (std::fabs(matrix[row * dimensions + pivot]) >
                    std::fabs(matrix[best * dimensions + pivot])) best = row;
        if (std::fabs(matrix[best * dimensions + pivot]) < epsilon)
            return false;
        if (best != pivot) {
            for (int column = pivot; column < dimensions; ++column)
                std::swap(matrix[pivot * dimensions + column],
                    matrix[best * dimensions + column]);
            std::swap(values[pivot], values[best]);
        }
        const float divisor = matrix[pivot * dimensions + pivot];
        for (int column = pivot; column < dimensions; ++column)
            matrix[pivot * dimensions + column] /= divisor;
        values[pivot] /= divisor;
        for (int row = 0; row < dimensions; ++row) {
            if (row == pivot) continue;
            const float factor = matrix[row * dimensions + pivot];
            if (factor == 0.0f) continue;
            for (int column = pivot; column < dimensions; ++column)
                matrix[row * dimensions + column] -= factor *
                    matrix[pivot * dimensions + column];
            values[row] -= factor * values[pivot];
        }
    }
    for (int index = 0; index < dimensions; ++index)
        output[index] = values[index];
    return true;
}

struct barycentricResult_t {
    std::vector<int> indices;
    std::vector<float> weights;
};

barycentricResult_t ComputeBarycentric(const idMD6BlendBranch& branch) {
    barycentricResult_t best;
    const int dimensions = branch.numDimensions;
    const int pointCount = (std::min)(branch.animationList.Num(),
        dimensions > 0 ? branch.coordinateList.Num() / dimensions : 0);
    if (dimensions <= 0 || dimensions > 6 || pointCount <= 0 ||
            branch.currentCoordinate.Num() < dimensions) return best;

    std::vector<std::pair<float, int>> distanceOrder;
    distanceOrder.reserve(pointCount);
    for (int point = 0; point < pointCount; ++point) {
        float distance = 0.0f;
        for (int dimension = 0; dimension < dimensions; ++dimension) {
            const float delta = CoordinateDelta(branch, point, dimension,
                branch.currentCoordinate[dimension]);
            distance += delta * delta;
        }
        if (distance <= 1.0e-12f) {
            best.indices.assign(dimensions + 1, point);
            best.weights.assign(dimensions + 1, 0.0f);
            best.weights[0] = 1.0f;
            return best;
        }
        distanceOrder.emplace_back(distance, point);
    }
    std::sort(distanceOrder.begin(), distanceOrder.end());

    const int candidateLimit = dimensions <= 3 ? 24 : 15;
    std::vector<int> candidates;
    candidates.reserve((std::min)(pointCount, candidateLimit));
    auto addCandidate = [&candidates](const int point) {
        if (std::find(candidates.begin(), candidates.end(), point) ==
                candidates.end()) candidates.push_back(point);
    };
    for (int dimension = 0; dimension < dimensions; ++dimension) {
        int minimum = 0, maximum = 0;
        for (int point = 1; point < pointCount; ++point) {
            if (branch.coordinateList[point * dimensions + dimension] <
                    branch.coordinateList[minimum * dimensions + dimension])
                minimum = point;
            if (branch.coordinateList[point * dimensions + dimension] >
                    branch.coordinateList[maximum * dimensions + dimension])
                maximum = point;
        }
        addCandidate(minimum);
        addCandidate(maximum);
    }
    for (const auto& entry : distanceOrder) {
        if (static_cast<int>(candidates.size()) >=
                (std::min)(pointCount, candidateLimit)) break;
        addCandidate(entry.second);
    }

    const int simplexSize = dimensions + 1;
    if (static_cast<int>(candidates.size()) < simplexSize) {
        const int nearest = distanceOrder.front().second;
        best.indices.assign(simplexSize, nearest);
        best.weights.assign(simplexSize, 0.0f);
        best.weights[0] = 1.0f;
        return best;
    }

    float bestPenalty = std::numeric_limits<float>::max();
    float bestRadius = std::numeric_limits<float>::max();
    std::vector<int> combination(simplexSize);
    int combinationsTested = 0;
    std::function<void(int, int)> enumerate = [&](const int depth,
            const int start) {
        if (combinationsTested >= 250000) return;
        if (depth != simplexSize) {
            for (int index = start;
                    index <= static_cast<int>(candidates.size()) -
                        (simplexSize - depth); ++index) {
                combination[depth] = candidates[index];
                enumerate(depth + 1, index + 1);
                if (combinationsTested >= 250000) break;
            }
            return;
        }
        ++combinationsTested;
        float matrix[36] = {};
        float values[6] = {};
        float solution[6] = {};
        const int anchor = combination[dimensions];
        for (int row = 0; row < dimensions; ++row) {
            values[row] = -CoordinateDelta(branch, anchor, row,
                branch.currentCoordinate[row]);
            const float anchorCoordinate = branch.currentCoordinate[row] +
                CoordinateDelta(branch, anchor, row,
                    branch.currentCoordinate[row]);
            for (int column = 0; column < dimensions; ++column) {
                const float pointCoordinate = branch.currentCoordinate[row] +
                    CoordinateDelta(branch, combination[column], row,
                        branch.currentCoordinate[row]);
                matrix[row * dimensions + column] = pointCoordinate -
                    anchorCoordinate;
            }
        }
        if (!SolveLinearSystem(dimensions, matrix, values, solution)) return;
        std::vector<float> weights(simplexSize);
        float sum = 0.0f;
        float penalty = 0.0f;
        float radius = 0.0f;
        for (int index = 0; index < dimensions; ++index) {
            weights[index] = solution[index];
            sum += weights[index];
        }
        weights[dimensions] = 1.0f - sum;
        for (int index = 0; index < simplexSize; ++index) {
            if (weights[index] < 0.0f)
                penalty += weights[index] * weights[index];
            else if (weights[index] > 1.0f) {
                const float excess = weights[index] - 1.0f;
                penalty += excess * excess;
            }
            const auto found = std::find_if(distanceOrder.begin(),
                distanceOrder.end(), [&](const std::pair<float, int>& item) {
                    return item.second == combination[index];
                });
            if (found != distanceOrder.end()) radius += found->first;
        }
        if (penalty < bestPenalty - 1.0e-8f ||
                (std::fabs(penalty - bestPenalty) <= 1.0e-8f &&
                    radius < bestRadius)) {
            bestPenalty = penalty;
            bestRadius = radius;
            best.indices = combination;
            best.weights = weights;
        }
    };
    enumerate(0, 0);

    if (best.indices.empty()) {
        const int nearest = distanceOrder.front().second;
        best.indices.assign(simplexSize, nearest);
        best.weights.assign(simplexSize, 0.0f);
        best.weights[0] = 1.0f;
        return best;
    }
    float total = 0.0f;
    for (float& weight : best.weights) {
        weight = (std::max)(0.0f, (std::min)(1.0f, weight));
        total += weight;
    }
    if (total <= 1.0e-8f) {
        best.weights.assign(simplexSize, 0.0f);
        best.weights[0] = 1.0f;
    } else {
        for (float& weight : best.weights) weight /= total;
    }
    return best;
}

} // namespace

void SetTagFilterCallback(TagFilterCallback callback) {
    tagFilterCallback = callback;
}

bool IsValid(const idMD6Node* node) {
    if (node == nullptr) return false;
    if (node->type == idMD6Node::NODE_LEAF_PLAY ||
            node->type == idMD6Node::NODE_LEAF_PAUSE)
        return static_cast<const idMD6Leaf*>(node)->weightGroup !=
            MD6_WEIGHTGROUP_MAX;
    if (node->type == idMD6Node::NODE_BEST_LEAF)
        return static_cast<const idMD6BestLeaf*>(node)->leafList.Num() != 0;
    if (node->type == idMD6Node::NODE_BRANCH ||
            node->type == idMD6Node::NODE_BLEND_BRANCH ||
            node->type == idMD6Node::NODE_BLENDA_BRANCH ||
            node->type == idMD6Node::NODE_FUSION_BRANCH) {
        const idMD6Branch* branch = static_cast<const idMD6Branch*>(node);
        return branch->left != nullptr && branch->right != nullptr;
    }
    return false;
}

void Clear(idMD6LeafPlay& leaf) {
    std::memset(&leaf, 0, sizeof(leaf));
    leaf.type = idMD6Node::NODE_LEAF_PLAY;
    leaf.anim = nullptr;
    leaf.weightGroup = MD6_WEIGHTGROUP_MAX;
    leaf.wrapMode = idMD6Leaf::WRAP_MAX;
    leaf.rateScale = 1.0f;
}

void Init(idMD6LeafPlay& leaf, const idMD6Anim* animation,
        const int gameTime, const int ticksPerSecond, const int frame,
        const float rate, const idMD6Leaf::wrapMode_t wrapMode,
        const md6WeightGroup_t weightGroup) {
    Clear(leaf);
    leaf.anim = animation;
    leaf.weightGroup = static_cast<std::uint8_t>(weightGroup);
    leaf.wrapMode = static_cast<std::uint8_t>(wrapMode);
    leaf.rateScale = rate;
    leaf.initCounter = 1;
    leaf.syncGroup = 0;
    leaf.syncEnabled = 0;
    SetFrame(leaf, gameTime, ticksPerSecond,
        static_cast<unsigned short>((std::max)(0, frame)));
}

void Restart(idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond, const int frame,
        const idMD6Leaf::wrapMode_t wrapMode) {
    leaf.wrapMode = static_cast<std::uint8_t>(wrapMode);
    ++leaf.initCounter;
    SetFrame(leaf, gameTime, ticksPerSecond,
        static_cast<unsigned short>((std::max)(0, frame)));
}

int GetFrameRate(const idMD6Leaf& leaf) {
    return leaf.anim != nullptr && leaf.anim->animData != nullptr
        ? leaf.anim->animData->frameRate : 30;
}

int GetLength(const idMD6Leaf& leaf, const int ticksPerSecond) {
    const int rate = GetFrameRate(leaf);
    return rate > 0 && FrameCount(leaf) > 0
        ? (FrameCount(leaf) - 1) * ticksPerSecond / rate : 0;
}

void SetFrameTime(idMD6LeafPlay& leaf, const int gameTime,
        const int targetTime) {
    leaf.startTime = leaf.rateScale != 0.0f
        ? gameTime - static_cast<int>(targetTime / leaf.rateScale)
        : gameTime;
}

int GetFrameTime(const idMD6LeafPlay& leaf, const int gameTime) {
    if (gameTime < leaf.startTime) return 0;
    return static_cast<int>((gameTime - leaf.startTime) * leaf.rateScale);
}

int GetFrameTicks(const idMD6LeafPlay& leaf, const int gameTime) {
    return GetFrameTime(leaf, gameTime);
}

int GetAnimLength(const idMD6LeafPlay& leaf, const int ticksPerSecond,
        const bool scaled) {
    const int length = GetLength(leaf, ticksPerSecond);
    return scaled && leaf.rateScale != 0.0f
        ? static_cast<int>(length / std::fabs(leaf.rateScale)) : length;
}

int GetAnimTicks(const idMD6LeafPlay& leaf, const int ticksPerSecond) {
    return GetAnimLength(leaf, ticksPerSecond, true);
}

float GetFloatFrame(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond) {
    if (ticksPerSecond <= 0) return 0.0f;
    return WrappedFrame(leaf, (std::max)(0, gameTime - leaf.startTime) *
        leaf.rateScale *
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
    if (leaf.rateScale == scale) return;
    const int frameTime = GetFrameTime(leaf, gameTime);
    leaf.rateScale = scale >= 0.0f ? scale : 1.0f;
    SetFrameTime(leaf, gameTime, frameTime);
}

int GetLoopCount(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond) {
    const int cycleFrames = FrameCount(leaf) - 1;
    if (leaf.anim == nullptr || cycleFrames <= 0 ||
            leaf.wrapMode == idMD6Leaf::WRAP_CLAMP || ticksPerSecond <= 0)
        return 0;
    const int elapsed = GetFrameTime(leaf, gameTime);
    return (elapsed * GetFrameRate(leaf) / ticksPerSecond) / cycleFrames;
}

bool IsPlaying(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond, const bool clampIgnoreExtraFrame) {
    if (leaf.anim == nullptr || leaf.anim->animData == nullptr) return false;
    if (leaf.wrapMode == idMD6Leaf::WRAP_REPEAT) return true;
    if (!clampIgnoreExtraFrame &&
            (leaf.anim->animData->flags & 0x1Eu) != 0) {
        const int oneFrame = ticksPerSecond / GetFrameRate(leaf);
        return gameTime - leaf.startTime <
            GetAnimLength(leaf, ticksPerSecond, true) + oneFrame;
    }
    return GetFrame(leaf, gameTime, ticksPerSecond) <
        FrameCount(leaf) - 1;
}

bool IsPlaying(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond) {
    return IsPlaying(leaf, gameTime, ticksPerSecond, false);
}

bool IsPlaying(const idMD6LeafPlay& leaf, const int gameTime,
        const int ticksPerSecond, const idMD6Leaf::wrapMode_t wrapMode) {
    if (leaf.anim == nullptr || leaf.anim->animData == nullptr) return false;
    if (wrapMode != idMD6Leaf::WRAP_CLAMP) return true;
    if ((leaf.anim->animData->flags & 0x1Eu) != 0) {
        const int oneFrame = ticksPerSecond / GetFrameRate(leaf);
        return gameTime - leaf.startTime <
            GetAnimLength(leaf, ticksPerSecond, true) + oneFrame;
    }
    return GetFrame(leaf, gameTime, ticksPerSecond) <
        FrameCount(leaf) - 1;
}

void Clear(idMD6LeafPause& leaf) {
    leaf.type = idMD6Node::NODE_LEAF_PAUSE;
    leaf.anim = nullptr;
    leaf.weightGroup = MD6_WEIGHTGROUP_MAX;
    leaf.wrapMode = idMD6Leaf::WRAP_MAX;
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
    if (time <= previousTime || ticksPerSecond <= 0 ||
            branch.currentAlpha == branch.targetAlpha) return;
    const float step = branch.alphaRate *
        (time - previousTime) / static_cast<float>(ticksPerSecond);
    if (branch.targetAlpha > branch.currentAlpha)
        branch.currentAlpha = (std::min)(branch.targetAlpha,
            branch.currentAlpha + step);
    else
        branch.currentAlpha = (std::max)(branch.targetAlpha,
            branch.currentAlpha - step);
}

bool IsBlendFinished(const idMD6Branch& branch) {
    return branch.alphaRate == 0.0f ||
        branch.currentAlpha == branch.targetAlpha;
}
bool IsChildBlendedOut(const idMD6Branch& branch, const idMD6Node* child) {
    if (child == nullptr) return true;
    if ((branch.targetAlpha > 0.0f && branch.targetAlpha < 1.0f) ||
            branch.filterGroup != MD6_WEIGHTGROUP_ALL) return false;
    return (child == branch.left && branch.currentAlpha >= 1.0f) ||
        (child == branch.right && branch.currentAlpha <= 0.0f);
}
bool IsBlendingOut(const idMD6Branch& branch) {
    return branch.currentAlpha > 0.0f && branch.targetAlpha == 0.0f &&
        branch.alphaRate != 0.0f;
}
bool IsBlendingIn(const idMD6Branch& branch) {
    return branch.currentAlpha < 1.0f && branch.targetAlpha >= 1.0f &&
        branch.alphaRate != 0.0f;
}

void Init(idMD6BlendAdditiveBranch& branch, idMD6Node* baseAnimation,
        const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations, const float coordinate,
        const md6WeightGroup_t weightGroup) {
    branch.type = idMD6Node::NODE_BLENDA_BRANCH;
    InitCoordinateNodePairs(branch, 1, coordinates, animations, 0);
    branch.baseAnimation = baseAnimation;
    branch.currentCoordinate = coordinate;
    branch.activeCoordinate = coordinate;
    branch.filterGroup = static_cast<std::uint8_t>(weightGroup);
    branch.op = idMD6Blend::BOP_BLENDA;
    branch.originBlend = idMD6Blend::ORIGINBLEND_BRANCH;
    branch.alphaRate = 0.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
    Update(branch, true);
    branch.targetAlpha = branch.currentAlpha;
}

void FindAnimation(const idMD6BlendAdditiveBranch& branch,
        idMD6Node*& animation, float& alpha) {
    animation = nullptr;
    alpha = 0.0f;
    const int count = (std::min)(branch.coordinateList.Num(),
        branch.animationList.Num());
    if (count <= 0) return;
    int nearest = 0;
    float nearestDistance = std::fabs(branch.coordinateList[0] -
        branch.currentCoordinate);
    for (int index = 1; index < count; ++index) {
        const float distance = std::fabs(branch.coordinateList[index] -
            branch.currentCoordinate);
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearest = index;
        }
    }
    animation = branch.animationList[nearest];
    const float sample = branch.coordinateList[nearest];
    if (std::fabs(sample) <= 1.0e-20f) {
        alpha = 1.0f;
    } else if (sample > 0.0f) {
        alpha = (std::max)(0.0f, (std::min)(1.0f,
            branch.currentCoordinate / sample));
    } else {
        alpha = (std::max)(0.0f, (std::min)(1.0f,
            branch.currentCoordinate / sample));
    }
}

void Update(idMD6BlendAdditiveBranch& branch, const bool force) {
    if (!force && std::fabs(branch.activeCoordinate -
            branch.currentCoordinate) < 1.0e-30f) return;
    branch.activeCoordinate = branch.currentCoordinate;
    idMD6Node* selected = nullptr;
    float alpha = 0.0f;
    FindAnimation(branch, selected, alpha);
    branch.left = branch.baseAnimation;
    branch.right = selected;
    branch.currentAlpha = branch.targetAlpha = alpha;
}

void InitCoordinateNodePairs(idMD6BlendBranch_Base& branch,
        const int dimensions, const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations, const int flags) {
    const int usableDimensions = (std::max)(1, dimensions);
    const int pointCount = (std::min)(animations.Num(),
        coordinates.Num() / usableDimensions);
    std::vector<int> order(pointCount);
    for (int index = 0; index < pointCount; ++index) order[index] = index;
    if (usableDimensions <= 1 || (flags & MD6_BLENDBRANCH_ANGLEWRAP) != 0) {
        std::stable_sort(order.begin(), order.end(), [&](const int left,
                const int right) {
            for (int dimension = 0; dimension < usableDimensions;
                    ++dimension) {
                const float a = coordinates[left * usableDimensions + dimension];
                const float b = coordinates[right * usableDimensions + dimension];
                if (a < b) return true;
                if (a > b) return false;
            }
            return left < right;
        });
    }
    branch.coordinateList.SetNum(pointCount * usableDimensions);
    branch.animationList.SetNum(pointCount);
    for (int output = 0; output < pointCount; ++output) {
        const int input = order[output];
        branch.animationList[output] = animations[input];
        for (int dimension = 0; dimension < usableDimensions; ++dimension)
            branch.coordinateList[output * usableDimensions + dimension] =
                coordinates[input * usableDimensions + dimension];
    }
}

void Init(idMD6BlendBranch& branch, const std::uint8_t dimensions,
        const idList<idUserChannelIndex, 5>& userChannelIndices,
        const idList<float, 5>& coordinates,
        const idList<idMD6Node*, 5>& animations,
        const idList<float, 5>& initialCoordinates,
        const md6WeightGroup_t weightGroup, const int flags) {
    branch.type = idMD6Node::NODE_BLEND_BRANCH;
    branch.numDimensions = (std::max)(static_cast<std::uint8_t>(1),
        (std::min)(dimensions, static_cast<std::uint8_t>(6)));
    CopyList(branch.userChannelIndices, userChannelIndices);
    InitCoordinateNodePairs(branch, branch.numDimensions, coordinates,
        animations, flags);
    CopyList(branch.currentCoordinate, initialCoordinates);
    CopyList(branch.activeCoordinate, initialCoordinates);
    branch.isAngleWrapped = (flags & MD6_BLENDBRANCH_ANGLEWRAP) != 0;
    branch.filterGroup = static_cast<std::uint8_t>(weightGroup);
    branch.op = idMD6Blend::BOP_BLEND;
    branch.originBlend = idMD6Blend::ORIGINBLEND_BRANCH;
    branch.alphaRate = 0.0f;
    branch.blendType = idMD6Branch::BLEND_LINEAR;
    const int nestedCount = (std::max)(0,
        static_cast<int>(branch.numDimensions) - 1);
    branch.branchList.SetNum(nestedCount);
    for (int index = 0; index < nestedCount; ++index) {
        idMD6Branch& nested = branch.branchList[index];
        Init(nested, nullptr,
            index + 1 < nestedCount
                ? static_cast<idMD6Node*>(&branch.branchList[index + 1])
                : nullptr,
            idMD6Blend::BOP_LERP, idMD6Blend::ORIGINBLEND_BRANCH,
            0.0f, 0.0f, 0.0f, weightGroup,
            idMD6Branch::BLEND_LINEAR);
    }
    branch.right = nestedCount > 0
        ? static_cast<idMD6Node*>(&branch.branchList[0]) : nullptr;
    Update(branch, true, true);
    branch.targetAlpha = branch.currentAlpha;
}

void FindAnimation(idMD6BlendBranch& branch, const bool isSorted,
        idMD6Node*& leftAnimation, idMD6Node*& rightAnimation,
        float& alpha) {
    leftAnimation = rightAnimation = nullptr;
    alpha = 0.0f;
    const int count = branch.animationList.Num();
    if (count <= 0 || branch.currentCoordinate.Num() <= 0) return;
    if (count == 1) {
        leftAnimation = rightAnimation = branch.animationList[0];
        branch.activeIndices.SetNum(2);
        branch.activeIndices[0] = branch.activeIndices[1] = 0;
        return;
    }
    const float target = branch.currentCoordinate[0];
    int left = -1, right = -1;
    if (isSorted) {
        right = 0;
        while (right < count && branch.coordinateList[
                right * branch.numDimensions] < target) ++right;
        if (right <= 0) left = right = 0;
        else if (right >= count) left = right = count - 1;
        else left = right - 1;
    } else {
        float leftDelta = std::numeric_limits<float>::max();
        float rightDelta = std::numeric_limits<float>::max();
        for (int index = 0; index < count; ++index) {
            float delta = branch.coordinateList[index *
                branch.numDimensions] - target;
            if (branch.isAngleWrapped) delta = WrapAngleDelta(delta);
            if (delta <= 0.0f && -delta < leftDelta) {
                leftDelta = -delta;
                left = index;
            }
            if (delta >= 0.0f && delta < rightDelta) {
                rightDelta = delta;
                right = index;
            }
        }
        if (left < 0) left = right;
        if (right < 0) right = left;
    }
    if (left < 0 || right < 0) return;
    leftAnimation = branch.animationList[left];
    rightAnimation = branch.animationList[right];
    if (left != right) {
        const float leftValue = branch.coordinateList[
            left * branch.numDimensions];
        float range = branch.coordinateList[right * branch.numDimensions] -
            leftValue;
        float offset = target - leftValue;
        if (branch.isAngleWrapped) {
            range = WrapAngleDelta(range);
            offset = WrapAngleDelta(offset);
        }
        if (std::fabs(range) > 1.0e-20f)
            alpha = (std::max)(0.0f, (std::min)(1.0f, offset / range));
    }
    branch.activeIndices.SetNum(2);
    branch.activeIndices[0] = left;
    branch.activeIndices[1] = right;
}

bool SolveGaussian(const int dimensions, float* matrix, float* values,
        float* output) {
    return SolveLinearSystem(dimensions, matrix, values, output);
}

bool BuildPointList(idMD6BlendBranch& branch, idList<int, 5>& indices) {
    const barycentricResult_t result = ComputeBarycentric(branch);
    indices.SetNum(static_cast<int>(result.indices.size()));
    for (int index = 0; index < indices.Num(); ++index)
        indices[index] = result.indices[index];
    return indices.Num() != 0;
}

void FindBarycentric(idMD6BlendBranch& branch,
        idList<idPair<float, idMD6Node*>, 5>& leaves) {
    leaves.Clear();
    const barycentricResult_t result = ComputeBarycentric(branch);
    const int count = (std::min)(static_cast<int>(result.indices.size()),
        static_cast<int>(result.weights.size()));
    branch.activeIndices.SetNum(count);
    for (int index = 0; index < count; ++index) {
        const int point = result.indices[index];
        branch.activeIndices[index] = point;
        leaves.Append(idPair<float, idMD6Node*>(result.weights[index],
            point >= 0 && point < branch.animationList.Num()
                ? branch.animationList[point] : nullptr));
    }
    std::stable_sort(leaves.Ptr(), leaves.Ptr() + leaves.Num(),
        [](const idPair<float, idMD6Node*>& left,
                const idPair<float, idMD6Node*>& right) {
            return left.first < right.first;
        });
}

void Update(idMD6BlendBranch& branch, const bool force,
        const bool isSorted) {
    if (branch.currentCoordinate.Num() == 0) return;
    bool changed = force || branch.activeCoordinate.Num() !=
        branch.currentCoordinate.Num();
    for (int index = 0; !changed && index < branch.currentCoordinate.Num();
            ++index)
        changed = branch.activeCoordinate[index] != branch.currentCoordinate[index];
    if (!changed) return;
    branch.activeCoordinate = branch.currentCoordinate;
    if (branch.numDimensions <= 1) {
        idMD6Node* left = nullptr;
        idMD6Node* right = nullptr;
        float alpha = 0.0f;
        FindAnimation(branch, isSorted, left, right, alpha);
        branch.left = left;
        branch.right = right;
        branch.currentAlpha = branch.targetAlpha = alpha;
    } else {
        idList<idPair<float, idMD6Node*>, 5> leaves;
        FindBarycentric(branch, leaves);
        if (leaves.Num() == 0) {
            branch.left = branch.right = nullptr;
            branch.currentAlpha = branch.targetAlpha = 0.0f;
            return;
        }
        idMD6Branch* current = &branch;
        float remaining = 1.0f;
        const int leftCount = (std::min)(branch.numDimensions,
            static_cast<std::uint8_t>(leaves.Num() - 1));
        for (int index = 0; index < leftCount; ++index) {
            const float weight = leaves[index].first;
            current->left = leaves[index].second;
            current->currentAlpha = current->targetAlpha =
                remaining > 1.0e-20f
                    ? (std::max)(0.0f, (std::min)(1.0f,
                        (remaining - weight) / remaining)) : 0.0f;
            remaining = (std::max)(0.0f, remaining - weight);
            if (index + 1 < leftCount)
                current = &branch.branchList[index];
        }
        current->right = leaves[leaves.Num() - 1].second;
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
    branch.op = idMD6Blend::BOP_FUSION;
    const int animationCount = branch.animationList.Num();
    branch.phaseToFrameLookupData.SetNum(animationCount * 256);
    for (int index = 0; index < branch.phaseToFrameLookupData.Num(); ++index)
        branch.phaseToFrameLookupData[index] = 0xFFFFu;

    for (int animationIndex = 0; animationIndex < animationCount;
            ++animationIndex) {
        idMD6Node* node = branch.animationList[animationIndex];
        if (node == nullptr || (node->type != idMD6Node::NODE_LEAF_PLAY &&
                node->type != idMD6Node::NODE_LEAF_PAUSE)) continue;
        const idMD6Anim* animation = static_cast<idMD6Leaf*>(node)->anim;
        if (animation == nullptr || animation->animData == nullptr ||
                !animation->phaseTrack.IsValid(animation)) continue;
        const int frameCount = animation->phaseTrack.data != nullptr
            ? animation->phaseTrack.data->numFrames : 0;
        if (frameCount <= 0) continue;

        int sums[256] = {};
        int counts[256] = {};
        for (int frame = 0; frame < frameCount; ++frame) {
            unsigned char phase = 0;
            if (!animation->phaseTrack.GetPhase(frame, phase)) continue;
            sums[phase] += frame;
            ++counts[phase];
        }
        std::vector<int> known;
        const int base = animationIndex * 256;
        for (int phase = 0; phase < 256; ++phase) {
            if (counts[phase] == 0) continue;
            branch.phaseToFrameLookupData[base + phase] =
                static_cast<unsigned short>(sums[phase] / counts[phase]);
            known.push_back(phase);
        }
        if (known.empty()) continue;
        if (known.size() == 1) {
            const unsigned short frame = branch.phaseToFrameLookupData[
                base + known[0]];
            for (int phase = 0; phase < 256; ++phase)
                branch.phaseToFrameLookupData[base + phase] = frame;
            continue;
        }
        for (int segment = 0; segment < static_cast<int>(known.size());
                ++segment) {
            const int phase0 = known[segment];
            const int phase1 = segment + 1 < static_cast<int>(known.size())
                ? known[segment + 1] : known[0] + 256;
            const int frame0 = branch.phaseToFrameLookupData[base + phase0];
            int frameDelta = static_cast<int>(
                branch.phaseToFrameLookupData[base + (phase1 & 255)]) - frame0;
            while (frameDelta > frameCount / 2) frameDelta -= frameCount;
            while (frameDelta < -frameCount / 2) frameDelta += frameCount;
            const int span = phase1 - phase0;
            for (int phase = phase0 + 1; phase < phase1; ++phase) {
                int frame = frame0 + static_cast<int>(std::lround(
                    frameDelta * (phase - phase0) / static_cast<float>(span)));
                frame %= frameCount;
                if (frame < 0) frame += frameCount;
                branch.phaseToFrameLookupData[base + (phase & 255)] =
                    static_cast<unsigned short>(frame);
            }
        }
    }
}

void Update(idMD6FusionBranch& branch, const bool force, const int gameTime,
        const int ticksPerSecond, const idMD6Skel* skeleton) {
    idMD6BlendBranch& blend = static_cast<idMD6BlendBranch&>(branch);
    Update(blend, force, branch.userChannelIndices.Num() == 0);

    idList<idPair<float, idMD6Node*>, 5> weightedNodes;
    if (branch.numDimensions <= 1) {
        if (branch.left != nullptr && branch.left == branch.right) {
            weightedNodes.Append(idPair<float, idMD6Node*>(1.0f,
                branch.left));
        } else {
            if (branch.left != nullptr)
                weightedNodes.Append(idPair<float, idMD6Node*>(
                    1.0f - branch.currentAlpha, branch.left));
            if (branch.right != nullptr)
                weightedNodes.Append(idPair<float, idMD6Node*>(
                    branch.currentAlpha, branch.right));
        }
    } else {
        FindBarycentric(blend, weightedNodes);
    }
    if (weightedNodes.Num() == 0 || ticksPerSecond <= 0) return;

    idMD6Node* masterNode = nullptr;
    float masterWeight = -1.0f;
    float weightedDuration = 0.0f;
    for (int index = 0; index < weightedNodes.Num(); ++index) {
        idMD6Node* node = weightedNodes[index].second;
        const float weight = weightedNodes[index].first;
        if (node == nullptr || (node->type != idMD6Node::NODE_LEAF_PLAY &&
                node->type != idMD6Node::NODE_LEAF_PAUSE)) continue;
        weightedDuration += GetLength(*static_cast<idMD6Leaf*>(node),
            ticksPerSecond) * weight;
        if (weight > masterWeight) {
            masterWeight = weight;
            masterNode = node;
        }
    }
    if (masterNode == nullptr || weightedDuration <= 1.0e-20f) return;

    const float inverseDuration = 1.0f / weightedDuration;
    for (int index = 0; index < weightedNodes.Num(); ++index) {
        idMD6Node* node = weightedNodes[index].second;
        if (node != nullptr && node->type == idMD6Node::NODE_LEAF_PLAY) {
            idMD6LeafPlay& play = *static_cast<idMD6LeafPlay*>(node);
            SetRateScale(play, gameTime,
                GetLength(play, ticksPerSecond) * inverseDuration,
                ticksPerSecond);
        }
    }

    const idMD6Leaf& masterLeaf = *static_cast<idMD6Leaf*>(masterNode);
    if (masterLeaf.anim == nullptr || masterLeaf.anim->animData == nullptr ||
            !masterLeaf.anim->phaseTrack.IsValid(masterLeaf.anim)) return;
    const float masterFrame = masterNode->type == idMD6Node::NODE_LEAF_PLAY
        ? GetFloatFrame(*static_cast<idMD6LeafPlay*>(masterNode), gameTime,
            ticksPerSecond)
        : static_cast<idMD6LeafPause*>(masterNode)->frame;
    const int masterFrameCount = masterLeaf.anim->phaseTrack.data != nullptr
        ? masterLeaf.anim->phaseTrack.data->numFrames : 0;
    if (masterFrameCount <= 0) return;
    const int frame0 = static_cast<int>(std::floor(masterFrame));
    const int frame1 = (frame0 + 1) % masterFrameCount;
    unsigned char phase0 = 0, phase1 = 0;
    if (!masterLeaf.anim->phaseTrack.GetPhase(frame0, phase0) ||
            !masterLeaf.anim->phaseTrack.GetPhase(frame1, phase1)) return;
    int phaseDelta = static_cast<int>(phase1) - static_cast<int>(phase0);
    if (phaseDelta > 127) phaseDelta -= 256;
    if (phaseDelta < -128) phaseDelta += 256;
    int phase = static_cast<int>(std::lround(phase0 + phaseDelta *
        (masterFrame - std::floor(masterFrame)))) & 255;

    std::vector<float> decodedChannels;
    if (skeleton != nullptr && skeleton->data != nullptr &&
            skeleton->data->numUserChannels > 0)
        decodedChannels.resize(skeleton->data->numUserChannels);
    for (int animationIndex = 0;
            animationIndex < branch.animationList.Num(); ++animationIndex) {
        idMD6Node* node = branch.animationList[animationIndex];
        if (node == nullptr || node == masterNode ||
                (node->type != idMD6Node::NODE_LEAF_PLAY &&
                    node->type != idMD6Node::NODE_LEAF_PAUSE)) continue;
        const int lookup = animationIndex * 256 + phase;
        if (lookup < 0 || lookup >= branch.phaseToFrameLookupData.Num())
            continue;
        const unsigned short desiredFrame =
            branch.phaseToFrameLookupData[lookup];
        if (desiredFrame == 0xFFFFu) continue;
        idMD6Leaf& leaf = *static_cast<idMD6Leaf*>(node);
        if (node->type == idMD6Node::NODE_LEAF_PLAY) {
            idMD6LeafPlay& play = *static_cast<idMD6LeafPlay*>(node);
            const int currentFrame = GetFrame(play, gameTime, ticksPerSecond);
            const int count = FrameCount(play);
            int difference = std::abs(static_cast<int>(desiredFrame) -
                currentFrame);
            if (count > 1) difference = (std::min)(difference,
                count - 1 - difference);
            if (difference > 3)
                SetFrame(play, gameTime, ticksPerSecond, desiredFrame);
        } else {
            static_cast<idMD6LeafPause*>(node)->frame =
                static_cast<float>(desiredFrame);
        }
        if (!decodedChannels.empty() && leaf.anim != nullptr &&
                leaf.anim->animData != nullptr &&
                branch.userChannelIndices.Num() > 0) {
            idMD6Blend::DecodeUserChannelsForAnimFrame(skeleton->data,
                leaf.anim->animData, static_cast<float>(desiredFrame),
                decodedChannels.data(), static_cast<unsigned int>(
                    decodedChannels.size() * sizeof(float)));
            for (int dimension = 0;
                    dimension < branch.numDimensions &&
                    dimension < branch.userChannelIndices.Num(); ++dimension) {
                const int channel = branch.userChannelIndices[dimension].Get();
                if (channel >= 0 && channel <
                        static_cast<int>(decodedChannels.size()))
                    branch.coordinateList[animationIndex *
                        branch.numDimensions + dimension] =
                            decodedChannels[channel];
            }
        }
    }
    Update(blend, force && masterNode->type == idMD6Node::NODE_LEAF_PLAY,
        branch.userChannelIndices.Num() == 0);
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

void Init(idMD6BestLeaf& best, const std::uint8_t tagBias,
        const unsigned int tagMask, const std::uint8_t tagGroupIndex,
        const idList<idMD6Node*, 5>& leaves,
        const idList<unsigned int, 5>& tags,
        const idList<idMD6Filter*, 5>& filters,
        const unsigned int defaultTag, const idDeclAnimWebTagGroup* group) {
    best.type = idMD6Node::NODE_BEST_LEAF;
    CopyList(best.leafList, leaves);
    CopyList(best.tagList, tags);
    CopyList(best.filterList, filters);
    best.tagGroup = group;
    best.desiredTag = 0;
    best.activeTag = 0;
    best.defaultTag = defaultTag;
    best.bestLeafIndex = 0xFFFFu;
    best.tagBias = tagBias;
    best.tagGroupIndex = tagGroupIndex;
    Init(best.tagGroupFilter, tagGroupIndex, tagMask, tagBias, group);
}

void Update(idMD6BestLeaf& best) {
    const int count = (std::min)(best.leafList.Num(), best.tagList.Num());
    if (count > 0 && best.bestLeafIndex != 0xFFFFu &&
            best.desiredTag == best.activeTag) {
        best.desiredTag = 0;
        return;
    }
    std::vector<bool> skipped(count, false);
    auto applyFilter = [&](const idMD6TagFilter& filter,
            const unsigned int desired) {
        const unsigned int desiredBits = desired & filter.tagMask;
        bool any = false;
        for (int index = 0; index < count; ++index) {
            if (skipped[index]) continue;
            const unsigned int candidate = best.tagList[index];
            bool accepted = desiredBits != 0
                ? (candidate & desiredBits) != 0
                : (candidate & filter.tagMask) == 0;
            if (tagFilterCallback != nullptr)
                accepted = accepted && tagFilterCallback(filter, candidate,
                    best.debugFilterLogicHelper);
            if (!accepted) skipped[index] = true;
            else any = true;
        }
        return any;
    };
    auto applyWithFallback = [&](const idMD6TagFilter& filter) {
        const std::vector<bool> original = skipped;
        if (!applyFilter(filter, best.desiredTag)) {
            skipped = original;
            if (!applyFilter(filter, best.defaultTag)) skipped = original;
        }
    };
    for (int index = best.filterList.Num() - 1; index >= 0; --index) {
        idMD6Filter* filter = best.filterList[index];
        if (filter != nullptr &&
                filter->type == idMD6Node::NODE_TAG_FILTER)
            applyWithFallback(*static_cast<idMD6TagFilter*>(filter));
    }
    applyWithFallback(best.tagGroupFilter);

    unsigned int bestScore = 0;
    std::vector<int> choices;
    for (int index = 0; index < count; ++index) {
        if (skipped[index]) continue;
        const unsigned int tag = best.tagList[index];
        const unsigned int desiredMatches = 32u -
            PopCount(best.desiredTag ^ tag);
        const unsigned int defaultMatches = 32u -
            PopCount(best.defaultTag ^ tag);
        const unsigned int score = desiredMatches * 100u + defaultMatches;
        if (choices.empty() || score > bestScore) {
            bestScore = score;
            choices.clear();
        }
        if (score == bestScore) choices.push_back(index);
    }
    const unsigned int requestedTag = best.desiredTag;
    best.desiredTag = 0;
    best.activeTag = requestedTag;
    if (choices.empty()) {
        best.bestLeafIndex = 0xFFFFu;
        return;
    }
    bestLeafRandomSeed = bestLeafRandomSeed * 1664525u + 1013904223u;
    const unsigned int random = (bestLeafRandomSeed >> 10) & 0x7FFFu;
    best.bestLeafIndex = static_cast<std::uint16_t>(
        choices[random % choices.size()]);
}

} // namespace idMD6AnimTree
