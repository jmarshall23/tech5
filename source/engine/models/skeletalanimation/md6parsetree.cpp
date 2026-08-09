#include "models/skeletalanimation/md6parsetree.h"

#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6animtree.h"
#include "models/skeletalanimation/md6model.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

constexpr std::uint16_t FRAME_LOOPED = 0x0004;
constexpr std::uint16_t FRAME_ANIMATOR_ORIGIN = 0x0008;
constexpr std::uint16_t FRAME_HAS_ORIGIN_DELTA = 0x0020;
constexpr std::uint16_t FRAME_EXTRAPOLATED_ORIGIN = 0x0040;
constexpr std::int16_t PAUSE_USE_STACK_TOP = 0x0001;
constexpr std::int16_t PAUSE_CLEAR_NON_MOD_WEIGHTS = 0x0002;
constexpr std::int16_t PAUSE_OVERRIDE_FRAME_BOUNDS = 0x0004;

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

void AddBounds(idBounds& destination, const idBounds& source) {
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(destination[0][axis],
            source[0][axis]);
        destination[1][axis] = (std::max)(destination[1][axis],
            source[1][axis]);
    }
}

float EaseAlpha(const idMD6Branch& branch) {
    const float alpha = (std::max)(0.0f,
        (std::min)(1.0f, branch.currentAlpha));
    switch (branch.blendType) {
    case idMD6Branch::BLEND_EASEIN:
        return branch.currentAlpha <= branch.targetAlpha
            ? alpha * alpha : alpha * (2.0f - alpha);
    case idMD6Branch::BLEND_EASEOUT:
        return branch.currentAlpha <= branch.targetAlpha
            ? alpha * (2.0f - alpha) : alpha * alpha;
    case idMD6Branch::BLEND_EASEIN_EASEOUT:
        if (alpha < 0.5f) return 2.0f * alpha * alpha;
        return 1.0f - 2.0f * (1.0f - alpha) * (1.0f - alpha);
    default:
        return alpha;
    }
}

struct FramePosition {
    std::int16_t frame;
    float fraction;
    unsigned int loops;
};

FramePosition GetFramePosition(const idMD6Leaf& leaf, const int time,
        const int ticksPerSecond) {
    FramePosition result{};
    if (leaf.anim == nullptr || leaf.anim->animData == nullptr ||
        leaf.anim->animData->numFrames == 0 || ticksPerSecond <= 0) {
        return result;
    }
    const int count = leaf.anim->animData->numFrames;
    float value = 0.0f;
    if (leaf.type == idMD6Node::NODE_LEAF_PAUSE) {
        value = static_cast<const idMD6LeafPause&>(leaf).frame;
    } else {
        const idMD6LeafPlay& play = static_cast<const idMD6LeafPlay&>(leaf);
        value = (time - play.startTime) * play.rateScale *
            leaf.anim->animData->frameRate /
            static_cast<float>(ticksPerSecond);
    }
    if (leaf.wrapMode == idMD6Leaf::WRAP_REPEAT && count > 1) {
        const float cycle = static_cast<float>(count - 1);
        result.loops = value >= 0.0f
            ? static_cast<unsigned int>(std::floor(value / cycle)) : 0;
        value = std::fmod(value, cycle);
        if (value < 0.0f) value += cycle;
    } else {
        value = (std::max)(0.0f,
            (std::min)(value, static_cast<float>(count - 1)));
    }
    result.frame = static_cast<std::int16_t>(std::floor(value));
    result.fraction = value - result.frame;
    return result;
}

void SetFrameSet(const idMD6AnimData* animation, const int frame,
        const frameSetData_t*& data, std::uint16_t& size,
        std::int16_t& frameInSet) {
    data = nullptr;
    size = 0;
    frameInSet = static_cast<std::int16_t>(frame);
    if (animation == nullptr || animation->numFrameSets == 0 || frame < 0 ||
        frame >= animation->numFrames || animation->frameSetTblOffset == 0 ||
        animation->frameSetOffsetTblOffset == 0) return;
    const auto* bytes = reinterpret_cast<const std::uint8_t*>(animation);
    const std::uint8_t setIndex = bytes[animation->frameSetTblOffset + frame];
    if (setIndex >= animation->numFrameSets) return;
    const auto* offsets = reinterpret_cast<const std::uint32_t*>(bytes +
        animation->frameSetOffsetTblOffset);
    const std::uint32_t first = offsets[setIndex] * 16u;
    const std::uint32_t next = offsets[setIndex + 1] * 16u +
        animation->nextSize;
    if (first >= animation->totalSize || next <= first ||
        next > animation->totalSize) return;
    data = reinterpret_cast<const frameSetData_t*>(bytes + first);
    size = static_cast<std::uint16_t>((std::min)(next - first, 65535u));
    frameInSet = static_cast<std::int16_t>(frame - data->frameStart);
}

struct ParseContext {
    const idMD6Model* model;
    int previousTime;
    int currentTime;
    unsigned int ticksPerSecond;
    md6AnimCommand_t* commands;
    int maxPayloadCommands;
    int count;
    idBounds* frameBounds;
    idBounds* translatedBounds;
    idBounds* normalizedBounds;
    md6OriginDelta_t* originDelta;
    unsigned short animatorFlags;
};

md6AnimCommand_t* AllocateCommand(ParseContext& context) {
    if (context.count >= context.maxPayloadCommands) return nullptr;
    md6AnimCommand_t* command = &context.commands[context.count++];
    std::memset(command, 0, sizeof(*command));
    return command;
}

bool SetupFrameCommand(ParseContext& context, const idMD6Leaf& leaf,
        const int time) {
    if (context.count >= context.maxPayloadCommands) return false;
    md6AnimCommand_t command{};
    command.op = md6AnimCommand_t::OP_DECODE_AND_PUSH;
    command.frameInfo.weightGroup = leaf.weightGroup;

    const idMD6Anim* animation = leaf.anim;
    if (animation != nullptr) {
        if (context.model != nullptr &&
            !animation->AnimIsOkForModel(context.model)) return false;
        const FramePosition position = GetFramePosition(leaf, time,
            context.ticksPerSecond);
        const FramePosition previous = GetFramePosition(leaf,
            context.previousTime, context.ticksPerSecond);
        command.animName = animation->GetName();
        command.frameInfo.animData = animation->animData;
        command.frameInfo.animInfoSize = animation->animData != nullptr
            ? animation->animData->size : 0;
        command.frameInfo.frame = position.frame;
        command.frameInfo.frameFraction = position.fraction;
        command.frameInfo.originFrame = previous.frame;
        command.frameInfo.originFrameFraction = previous.fraction;
        if (position.loops > previous.loops)
            command.frameInfo.flags |= FRAME_LOOPED;
        if ((context.animatorFlags & 1u) != 0)
            command.frameInfo.flags |= FRAME_ANIMATOR_ORIGIN;

        SetFrameSet(animation->animData, position.frame,
            command.frameInfo.frameSetData,
            command.frameInfo.frameSetSize,
            command.frameInfo.frameSetFrame);
        command.frameInfo.originFrameSetData = command.frameInfo.frameSetData;
        command.frameInfo.originFrameSetSize =
            command.frameInfo.frameSetSize;
        command.frameInfo.originFrameSetFrame =
            command.frameInfo.frameSetFrame;
        if (previous.frame != position.frame) {
            SetFrameSet(animation->animData, previous.frame,
                command.frameInfo.originFrameSetData,
                command.frameInfo.originFrameSetSize,
                command.frameInfo.originFrameSetFrame);
        }

        if (animation->animData != nullptr &&
            (context.animatorFlags & 1u) != 0 &&
            (animation->animData->flags &
             (idMD6AnimData::ANIM_FLAG_USE_FORWARD_TRANSLATION |
              idMD6AnimData::ANIM_FLAG_USE_LEFT_TRANSLATION |
              idMD6AnimData::ANIM_FLAG_USE_UP_TRANSLATION |
              idMD6AnimData::ANIM_FLAG_USE_ROTATION)) != 0) {
            command.frameInfo.flags |= FRAME_HAS_ORIGIN_DELTA;
            if ((context.animatorFlags & 2u) != 0)
                command.frameInfo.flags |= FRAME_EXTRAPOLATED_ORIGIN;
        }

        if (animation->animData == nullptr ||
            (animation->animData->flags &
             (idMD6AnimData::ANIM_FLAG_IGNORE_BOUNDS |
              idMD6AnimData::ANIM_FLAG_ADDITIVE)) == 0) {
            const idBounds translated = animation->translatedBounds.ToBounds();
            const idBounds normalized = animation->normalizedBounds.ToBounds();
            AddBounds(*context.translatedBounds, translated);
            AddBounds(*context.normalizedBounds, normalized);
            AddBounds(*context.frameBounds,
                ((context.animatorFlags & 1u) != 0 &&
                 animation->animData != nullptr &&
                 (animation->animData->flags &
                  (idMD6AnimData::ANIM_FLAG_USE_FORWARD_TRANSLATION |
                   idMD6AnimData::ANIM_FLAG_USE_LEFT_TRANSLATION |
                   idMD6AnimData::ANIM_FLAG_USE_UP_TRANSLATION)) != 0)
                    ? normalized : translated);
        }
    }

    if (leaf.type == idMD6Node::NODE_LEAF_PAUSE) {
        const idMD6LeafPause& pause =
            static_cast<const idMD6LeafPause&>(leaf);
        const idMD6OpaqueList& modifiers =
            pause.animMods[pause.currentDeferred & 1];
        command.frameInfo.animMods =
            static_cast<const idMD6Blend::jointMod_t*>(modifiers.list);
        command.frameInfo.animModsSize = static_cast<std::uint16_t>(
            (std::min)(modifiers.num *
                static_cast<int>(sizeof(idMD6Blend::jointMod_t)), 65535));
        if ((pause.flags & PAUSE_USE_STACK_TOP) != 0)
            command.frameInfo.flags |= PAUSE_USE_STACK_TOP;
        if ((pause.flags & PAUSE_CLEAR_NON_MOD_WEIGHTS) != 0)
            command.frameInfo.flags |= PAUSE_CLEAR_NON_MOD_WEIGHTS;
        if ((pause.flags & PAUSE_OVERRIDE_FRAME_BOUNDS) != 0) {
            *context.frameBounds = pause.bounds;
            *context.translatedBounds = pause.bounds;
            *context.normalizedBounds = pause.bounds;
        } else {
            AddBounds(*context.frameBounds, pause.bounds);
            AddBounds(*context.translatedBounds, pause.bounds);
            AddBounds(*context.normalizedBounds, pause.bounds);
        }
    }
    context.commands[context.count++] = command;
    return true;
}

idMD6Node* ResolveNode(idMD6Node* node) {
    if (node == nullptr || node->type != idMD6Node::NODE_BEST_LEAF)
        return node;
    idMD6BestLeaf* best = static_cast<idMD6BestLeaf*>(node);
    idMD6AnimTree::Update(*best);
    if (best->leafList.Num() == 0) return nullptr;
    return best->leafList[best->bestLeafIndex % best->leafList.Num()];
}

bool ParseNode(ParseContext& context, idMD6Node* node, int time) {
    node = ResolveNode(node);
    if (node == nullptr) {
        md6AnimCommand_t* command = AllocateCommand(context);
        if (command == nullptr) return false;
        command->op = md6AnimCommand_t::OP_DECODE_AND_PUSH;
        return true;
    }
    if (node->type == idMD6Node::NODE_LEAF_PLAY ||
        node->type == idMD6Node::NODE_LEAF_PAUSE) {
        return SetupFrameCommand(context, *static_cast<idMD6Leaf*>(node),
            time);
    }
    if (node->type != idMD6Node::NODE_BRANCH &&
        node->type != idMD6Node::NODE_BLEND_BRANCH &&
        node->type != idMD6Node::NODE_BLENDA_BRANCH &&
        node->type != idMD6Node::NODE_FUSION_BRANCH) {
        return false;
    }

    idMD6Branch& branch = *static_cast<idMD6Branch*>(node);
    idMD6AnimTree::UpdateCurrentAlpha(branch, time,
        context.previousTime, context.ticksPerSecond);
    if (node->type == idMD6Node::NODE_BLEND_BRANCH)
        idMD6AnimTree::Update(*static_cast<idMD6BlendBranch*>(node),
            false, true);
    else if (node->type == idMD6Node::NODE_BLENDA_BRANCH)
        idMD6AnimTree::Update(*static_cast<idMD6BlendAdditiveBranch*>(node),
            false);
    else if (node->type == idMD6Node::NODE_FUSION_BRANCH)
        idMD6AnimTree::Update(*static_cast<idMD6FusionBranch*>(node), false,
            time, context.ticksPerSecond,
            context.model != nullptr ? context.model->skeleton : nullptr);

    const int beforeLeft = context.count;
    const int leftTime = branch.leftTimeOverride >= 0
        ? branch.leftTimeOverride : time;
    const bool haveLeft = branch.left != nullptr &&
        ParseNode(context, branch.left, leftTime);
    const int beforeRight = context.count;
    const int rightTime = branch.rightTimeOverride >= 0
        ? branch.rightTimeOverride : time;
    const bool haveRight = branch.right != nullptr &&
        ParseNode(context, branch.right, rightTime);

    if (!haveLeft && !haveRight) {
        context.count = beforeLeft;
        return false;
    }
    if (!haveLeft && haveRight) return true;
    if (haveLeft && !haveRight) {
        context.count = beforeRight;
        return true;
    }
    md6AnimCommand_t* blend = AllocateCommand(context);
    if (blend == nullptr) return false;
    blend->op = md6AnimCommand_t::OP_POP_AND_BLEND;
    blend->blendInfo.op = branch.op;
    blend->blendInfo.filterGroup = branch.filterGroup;
    blend->blendInfo.originBlend = branch.originBlend;
    blend->blendInfo.currentAlpha = EaseAlpha(branch);
    return true;
}

} // namespace

int ParseTree(const idMD6Model* model, const int previousTime,
        const int currentTime, const unsigned int ticksPerSecond,
        idMD6Node* tree, md6AnimCommand_t* commands, const int maxCommands,
        idBounds& frameBounds, idBounds& translatedBounds,
        idBounds& normalizedBounds, md6OriginDelta_t* originDelta,
        const unsigned short animatorFlags) {
    if (commands == nullptr || maxCommands <= 0) return 0;
    ClearBounds(frameBounds);
    ClearBounds(translatedBounds);
    ClearBounds(normalizedBounds);
    if (originDelta != nullptr) originDelta->done = false;

    ParseContext context{model, previousTime, currentTime, ticksPerSecond,
        commands, maxCommands - 1, 0, &frameBounds, &translatedBounds,
        &normalizedBounds, originDelta, animatorFlags};
    if (!idMD6AnimTree::IsValid(tree) ||
        !ParseNode(context, tree, currentTime)) {
        context.count = 0;
        md6AnimCommand_t* base = AllocateCommand(context);
        if (base != nullptr) base->op = md6AnimCommand_t::OP_DECODE_AND_PUSH;
    }
    std::memset(&commands[context.count], 0, sizeof(commands[context.count]));
    commands[context.count].op = md6AnimCommand_t::OP_END;
    return context.count + 1;
}

