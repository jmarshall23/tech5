#include "models/skeletalanimation/md6animeventhandler.h"

#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6animtree.h"

#include <algorithm>
#include <cmath>

idAnimEventHandler::EventFilterCallback
    idAnimEventHandler::eventFilterCallback = nullptr;

namespace {

bool EventIsRequested(const int eventNumber, const int* onlyEvents,
        const int onlyNumEvents) {
    if (onlyEvents == nullptr || onlyNumEvents <= 0) return true;
    for (int index = 0; index < onlyNumEvents; ++index)
        if (onlyEvents[index] == eventNumber) return true;
    return false;
}

int TotalLoopCount(const idMD6LeafPlay& leaf, const int time,
        const int ticksPerSecond) {
    if (leaf.wrapMode != idMD6Leaf::WRAP_REPEAT || leaf.anim == nullptr ||
        leaf.anim->animData == nullptr || ticksPerSecond <= 0 ||
        leaf.anim->animData->numFrames <= 1) {
        return 0;
    }
    const float rawFrame = (time - leaf.startTime) * leaf.rateScale *
        leaf.anim->animData->frameRate /
        static_cast<float>(ticksPerSecond);
    return static_cast<int>(std::floor(rawFrame /
        (leaf.anim->animData->numFrames - 1)));
}

const idMD6Node* ResolveBestLeaf(const idMD6Node* node) {
    if (node == nullptr || node->type != idMD6Node::NODE_BEST_LEAF)
        return node;
    const idMD6BestLeaf* best = static_cast<const idMD6BestLeaf*>(node);
    if (best->leafList.Num() == 0) return nullptr;
    return best->leafList[best->bestLeafIndex % best->leafList.Num()];
}

} // namespace

idAnimEventHandler::idAnimEventHandler() : nextEventToFetch(0) {
}

idAnimEventHandler::~idAnimEventHandler() = default;

void idAnimEventHandler::SetEventFilterCallback(
        const EventFilterCallback callback) {
    eventFilterCallback = callback;
}

bool idAnimEventHandler::FetchNextEvent(const idMD6Anim*& animation,
        const idMD6AnimEvent*& event) {
    if (nextEventToFetch >= triggeredEvents.Num()) {
        animation = nullptr;
        event = nullptr;
        return false;
    }
    const triggeredEvent_t& triggered = triggeredEvents[nextEventToFetch++];
    animation = triggered.anim;
    event = triggered.event;
    return true;
}

void idAnimEventHandler::OffsetTimes(const int timeOffset) {
    for (int index = 0; index < trackedEvents.Num(); ++index)
        trackedEvents[index].startTime += timeOffset;
}

void idAnimEventHandler::AddPlayLeafToFrameList(
        idStaticList<eventInfo_t, 64>& frames,
        const idMD6LeafPlay* play, const int currentTime,
        const int previousTime, const int ticksPerSecond,
        const bool canSkip) const {
    if (play == nullptr || play->anim == nullptr ||
        frames.Num() >= frames.Max()) return;
    eventInfo_t info{};
    info.anim = play->anim;
    info.lastFrame = idMD6AnimTree::GetFrame(*play, previousTime,
        ticksPerSecond);
    info.curFrame = idMD6AnimTree::GetFrame(*play, currentTime,
        ticksPerSecond);
    info.leaf = play;
    info.loopCount = static_cast<std::int16_t>(TotalLoopCount(*play,
        currentTime, ticksPerSecond));
    info.startTime = play->startTime;
    info.initCounter = play->initCounter;
    info.canSkip = canSkip;
    frames.Append(info);
}

void idAnimEventHandler::WalkTree(idStaticList<eventInfo_t, 64>& frames,
        const idMD6Node* node, const int currentTime,
        const int previousTime, const int ticksPerSecond,
        const bool canSkip) const {
    if (node == nullptr || frames.Num() >= frames.Max()) return;
    node = ResolveBestLeaf(node);
    if (node == nullptr) return;
    if (node->type == idMD6Node::NODE_LEAF_PLAY) {
        AddPlayLeafToFrameList(frames,
            static_cast<const idMD6LeafPlay*>(node), currentTime,
            previousTime, ticksPerSecond, canSkip);
        return;
    }
    if (node->type != idMD6Node::NODE_BRANCH &&
        node->type != idMD6Node::NODE_BLEND_BRANCH &&
        node->type != idMD6Node::NODE_BLENDA_BRANCH &&
        node->type != idMD6Node::NODE_FUSION_BRANCH) {
        return;
    }

    const idMD6Branch* branch = static_cast<const idMD6Branch*>(node);
    bool leftCanSkip = canSkip;
    bool rightCanSkip = canSkip;
    if (branch->filterGroup == MD6_WEIGHTGROUP_ALL &&
        (branch->op < idMD6Blend::BOP_ADD_LEFT ||
         branch->op > idMD6Blend::BOP_SUB_RIGHT)) {
        leftCanSkip = leftCanSkip || branch->currentAlpha > 0.5f;
        rightCanSkip = rightCanSkip || branch->currentAlpha <= 0.5f;
    }
    WalkTree(frames, branch->left, currentTime, previousTime,
        ticksPerSecond, leftCanSkip);
    WalkTree(frames, branch->right, currentTime, previousTime,
        ticksPerSecond, rightCanSkip);
}

void idAnimEventHandler::BuildEventList(
        const idStaticList<eventInfo_t, 64>& frames,
        const idDeclMD6* declaration, const int currentTime, int,
        const int ticksPerSecond, const int* onlyEvents,
        const int onlyNumEvents) {
    triggeredEvents.Clear();
    if (declaration == nullptr) return;

    // Stop tracking an event once its originating leaf/restart/loop is gone
    // or playback has advanced past its frame.
    for (int trackedIndex = trackedEvents.Num() - 1;
         trackedIndex >= 0; --trackedIndex) {
        const trackedEvent_t& tracked = trackedEvents[trackedIndex];
        bool alive = false;
        for (int frameIndex = 0; frameIndex < frames.Num(); ++frameIndex) {
            const eventInfo_t& frame = frames[frameIndex];
            if (tracked.anim == frame.anim &&
                tracked.loopCount == frame.loopCount &&
                tracked.initCounter == frame.initCounter) {
                const idMD6LeafPlay* play =
                    static_cast<const idMD6LeafPlay*>(frame.leaf);
                alive = play != nullptr && idMD6AnimTree::GetFrame(*play,
                    currentTime, ticksPerSecond) < tracked.eventFrame;
                break;
            }
        }
        if (!alive) trackedEvents.RemoveIndexFast(trackedIndex);
    }

    idStaticList<const idMD6AnimEvent*, 16> selected;
    for (int frameIndex = 0; frameIndex < frames.Num(); ++frameIndex) {
        const eventInfo_t& frame = frames[frameIndex];
        if (!declaration->FindAnimEvents(frame.anim, frame.lastFrame,
                frame.curFrame, selected)) continue;
        for (int eventIndex = 0; eventIndex < selected.Num(); ++eventIndex) {
            const idMD6AnimEvent* event = selected[eventIndex];
            if (!EventIsRequested(event->eventNum, onlyEvents,
                    onlyNumEvents)) continue;
            if (eventFilterCallback != nullptr &&
                !eventFilterCallback(*event, frame.canSkip)) continue;

            bool duplicate = false;
            for (int trackedIndex = trackedEvents.Num() - 1;
                 trackedIndex >= 0; --trackedIndex) {
                const trackedEvent_t& tracked = trackedEvents[trackedIndex];
                if (tracked.eventId == event->eventId &&
                    tracked.loopCount == frame.loopCount &&
                    tracked.initCounter == frame.initCounter) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate || triggeredEvents.Num() >= triggeredEvents.Max())
                continue;

            triggeredEvent_t triggered{};
            triggered.startTime = frame.startTime;
            triggered.eventNum = event->eventNum;
            triggered.initCounter = frame.initCounter;
            triggered.eventId = event->eventId;
            triggered.anim = frame.anim;
            triggered.eventFrame = event->frameNum;
            triggered.loopCount = frame.loopCount;
            triggered.event = event;
            triggeredEvents.Append(triggered);
        }
    }

    for (int index = 0; index < triggeredEvents.Num(); ++index) {
        if (trackedEvents.Num() >= trackedEvents.Max()) break;
        trackedEvents.Append(static_cast<const trackedEvent_t&>(
            triggeredEvents[index]));
    }
}

void idAnimEventHandler::BuildAnimEventList(const idDeclMD6* declaration,
        const idMD6Node* tree, const int currentTime,
        const int previousTime, const int ticksPerSecond,
        const int* onlyEvents, const int onlyNumEvents) {
    idStaticList<eventInfo_t, 64> frames;
    WalkTree(frames, tree, currentTime, previousTime, ticksPerSecond);
    BuildEventList(frames, declaration, currentTime, previousTime,
        ticksPerSecond, onlyEvents, onlyNumEvents);
    nextEventToFetch = 0;
}

