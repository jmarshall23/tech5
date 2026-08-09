#pragma once

#include "idlib/containers/staticlist.h"
#include "models/skeletalanimation/md6animevent.h"

#include <cstdint>

class idDeclMD6;
class idMD6Anim;
class idMD6Leaf;
class idMD6LeafPlay;
class idMD6Node;

class idAnimEventHandler {
public:
    struct trackedEvent_t {
        int startTime;
        std::int16_t eventNum;
        std::uint8_t initCounter;
        std::uint8_t pad;
        idHandle<unsigned int, invalidAnimEventId_t, 0> eventId;
        const idMD6Anim* anim;
        std::int16_t eventFrame;
        std::int16_t loopCount;
    };

    struct triggeredEvent_t : trackedEvent_t {
        const idMD6AnimEvent* event;
    };

    struct eventInfo_t {
        const idMD6Anim* anim;
        const idMD6Leaf* leaf;
        int startTime;
        std::uint8_t initCounter;
        std::uint16_t lastFrame;
        std::uint16_t curFrame;
        std::int16_t loopCount;
        bool canSkip;
    };

    using EventFilterCallback = bool (*)(const idMD6AnimEvent& event,
        bool leafCanSkip);

    idAnimEventHandler();
    ~idAnimEventHandler();

    bool FetchNextEvent(const idMD6Anim*& animation,
        const idMD6AnimEvent*& event);
    void OffsetTimes(int timeOffset);
    void BuildAnimEventList(const idDeclMD6* declaration,
        const idMD6Node* tree, int currentTime, int previousTime,
        int ticksPerSecond, const int* onlyEvents = nullptr,
        int onlyNumEvents = 0);

    static void SetEventFilterCallback(EventFilterCallback callback);

private:
    void AddPlayLeafToFrameList(idStaticList<eventInfo_t, 64>& frames,
        const idMD6LeafPlay* play, int currentTime, int previousTime,
        int ticksPerSecond, bool canSkip) const;
    void WalkTree(idStaticList<eventInfo_t, 64>& frames,
        const idMD6Node* node, int currentTime, int previousTime,
        int ticksPerSecond, bool canSkip = false) const;
    void BuildEventList(const idStaticList<eventInfo_t, 64>& frames,
        const idDeclMD6* declaration, int currentTime, int previousTime,
        int ticksPerSecond, const int* onlyEvents, int onlyNumEvents);

    idStaticList<trackedEvent_t, 32> trackedEvents;
    idStaticList<triggeredEvent_t, 32> triggeredEvents;
    int nextEventToFetch;

    static EventFilterCallback eventFilterCallback;
};

