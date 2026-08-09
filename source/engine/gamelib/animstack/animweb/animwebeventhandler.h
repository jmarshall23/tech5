#pragma once

#include "gamelib/animstack/animstacktypes.h"

class idAnimator_AnimWeb;
class idDeclAnimWebNode;

enum animWebEvent_t : int {
    ANIMWEB_EVENT_NONE = -1,
    ANIMWEB_EVENT_START_BLEND_IN = 0,
    ANIMWEB_EVENT_START_BLEND_OUT,
    ANIMWEB_EVENT_END_BLEND_IN,
    ANIMWEB_EVENT_END_BLEND_OUT,
    ANIMWEB_EVENT_DEST_START_BLEND_IN,
    ANIMWEB_EVENT_DEST_END_BLEND_IN,
    ANIMWEB_EVENT_DEST_CLAMPED,
    ANIMWEB_EVENT_BLEND_NEXT_FRAME,
    ANIMWEB_EVENT_CLAMP_NEXT_FRAME,
    ANIMWEB_EVENT_MAX
};

class idAnimWebEvent {
public:
    enum priority_t : int {
        PRIORITY_LOW = 0,
        PRIORITY_MISC = 0,
        PRIORITY_DEATH = 1,
        PRIORITY_MAX = 2
    };

    idAnimWebSubWebIndex swi;
    idAnimWebStateIndex si;
    int eventNum;
    priority_t priority;
};

class idAnimWebEventHandler {
public:
    virtual void ClearEvent(animWebEvent_t eventType);
    virtual void ClearEvents();
    virtual void SetEvent(const idAnimator_AnimWeb* web,
        idAnimWebSubWebIndex subWeb, idAnimWebStateIndex state,
        animWebEvent_t eventType, int eventNum,
        idAnimWebEvent::priority_t priority);
    virtual void TriggerEventType(idAnimator_AnimWeb* web,
        const idDeclAnimWebNode* node, animWebEvent_t eventType,
        int eventParameter);
    virtual bool IsEventPending(animWebEvent_t eventType) const;
    virtual bool IsAnyEventPending() const;
};

class idAnimWebEventHandler_Zion : public idAnimWebEventHandler {
public:
    idAnimWebEventHandler_Zion();

    void ClearEvent(animWebEvent_t eventType) override;
    void ClearEvents() override;
    void SetEvent(const idAnimator_AnimWeb* web,
        idAnimWebSubWebIndex subWeb, idAnimWebStateIndex state,
        animWebEvent_t eventType, int eventNum,
        idAnimWebEvent::priority_t priority) override;
    void TriggerEventType(idAnimator_AnimWeb* web,
        const idDeclAnimWebNode* node, animWebEvent_t eventType,
        int eventParameter) override;
    bool IsEventPending(animWebEvent_t eventType) const override;
    bool IsAnyEventPending() const override;

    idAnimWebEvent events[ANIMWEB_EVENT_MAX];
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimWebEvent) == 12,
    "Recovered animation-web event ABI changed");
static_assert(sizeof(idAnimWebEventHandler) == 4,
    "Recovered animation-web event-handler ABI changed");
static_assert(sizeof(idAnimWebEventHandler_Zion) == 112,
    "Recovered Zion event-handler ABI changed");
#endif
