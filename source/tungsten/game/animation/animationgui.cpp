#include "animationgui.h"

#include "../../../engine/gamelib/animstack/animstacktypes.h"
#include "../../../engine/models/skeletalanimation/md6anim.h"

#include <algorithm>
#include <cmath>

namespace {

idAnimationGUIFontLoader g_fontLoader = nullptr;
idAnimationGUIAnimInfoProvider g_animInfoProvider = nullptr;
idAnimationGUIDrawTreeCallback g_drawTreeCallback = nullptr;
idAnimationGUIDrawDebugCallback g_drawDebugCallback = nullptr;

bool GetAnimationInfo(const idMD6Anim* const animation,
        int& frameCount, int& frameRate) {
    frameCount = 0;
    frameRate = 30;
    if (g_animInfoProvider != nullptr) {
        return g_animInfoProvider(animation, frameCount, frameRate);
    }
    if (animation == nullptr || animation->animData == nullptr) {
        return false;
    }
    frameCount = animation->animData->numFrames;
    frameRate = animation->animData->frameRate;
    return frameCount > 0 && frameRate > 0;
}

} // namespace

void Tungsten_SetAnimationGUIFontLoader(
        const idAnimationGUIFontLoader loader) {
    g_fontLoader = loader;
}

void Tungsten_SetAnimationGUIAnimInfoProvider(
        const idAnimationGUIAnimInfoProvider provider) {
    g_animInfoProvider = provider;
}

void Tungsten_SetAnimationGUIDrawTreeCallback(
        const idAnimationGUIDrawTreeCallback callback) {
    g_drawTreeCallback = callback;
}

void Tungsten_SetAnimationGUIDrawDebugCallback(
        const idAnimationGUIDrawDebugCallback callback) {
    g_drawDebugCallback = callback;
}

// Retail symbol: ??0idAnimationGUI@@QAA@XZ
// EA: 0x82B2C680, RVA: 0x00B2C680
idAnimationGUI::idAnimationGUI()
    : guiModel(nullptr), font(g_fontLoader != nullptr
        ? g_fontLoader("arial_black") : nullptr) {
}

// Retail symbol: ?GetAnimTime@@YAMPBVidMD6Leaf@@HH@Z
// EA: 0x82B2C6D8, RVA: 0x00B2C6D8
float GetAnimTime(const idMD6Leaf* const leaf,
        const int timeMilliseconds, const int ticksPerSecond) {
    if (leaf == nullptr || leaf->anim == nullptr || ticksPerSecond <= 0) {
        return 0.0f;
    }

    int frameCount = 0;
    int frameRate = 30;
    if (!GetAnimationInfo(leaf->anim, frameCount, frameRate)
            || frameCount <= 0 || frameRate <= 0) {
        return 0.0f;
    }

    float frame = 0.0f;
    if (leaf->type == idMD6Node::NODE_LEAF_PAUSE) {
        frame = static_cast<const idMD6LeafPause*>(leaf)->frame;
    } else if (leaf->type == idMD6Node::NODE_LEAF_PLAY) {
        const idMD6LeafPlay* const play
            = static_cast<const idMD6LeafPlay*>(leaf);
        frame = (std::max)(0, timeMilliseconds - play->startTime)
            * play->rateScale * frameRate
            / static_cast<float>(ticksPerSecond);
    }

    if (leaf->wrapMode == idMD6Leaf::WRAP_REPEAT && frameCount > 1) {
        const float cycle = static_cast<float>(frameCount - 1);
        frame = std::fmod(frame, cycle);
        if (frame < 0.0f) {
            frame += cycle;
        }
    } else {
        frame = (std::max)(0.0f,
            (std::min)(frame, static_cast<float>(frameCount - 1)));
    }
    return frame / static_cast<float>(frameRate);
}

// Retail symbol: ?DrawAnimTree_r@idAnimationGUI@@AAAXAAVidStr@@AAVidGUIRect@@PBVidMD6Node@@@Z
// EA: 0x82B2C900, RVA: 0x00B2C900
void idAnimationGUI::DrawAnimTree_r(idStr& indentation,
        idGUIRect& rectangle, const idMD6Node* const treeNode) {
    if (treeNode != nullptr && g_drawTreeCallback != nullptr) {
        g_drawTreeCallback(indentation, rectangle, treeNode);
    }
}

// Retail symbol: ?DrawDebugGUI@idAnimationGUI@@QAAPAVidRenderModelGui@@PAVidEntity@@@Z
// EA: 0x82B2CB08, RVA: 0x00B2CB08
idRenderModelGui* idAnimationGUI::DrawDebugGUI(idEntity* const entity) {
    if (entity == nullptr || font == nullptr
            || g_drawDebugCallback == nullptr) {
        return nullptr;
    }
    guiModel = g_drawDebugCallback(entity, font, guiModel);
    return guiModel;
}
