#include "gamelib/animstack/animweb/animwebeventhandler.h"

bool GameLib_AnimWebNodeMatchesEvent(const idDeclAnimWebNode* node,
    idAnimWebSubWebIndex subWeb, idAnimWebStateIndex state);
void GameLib_TriggerAnimWebEvent(idAnimator_AnimWeb* web,
    const idDeclAnimWebNode* node, animWebEvent_t eventType,
    const idAnimWebEvent& event, int eventParameter);

void idAnimWebEventHandler::ClearEvent(animWebEvent_t) {}
void idAnimWebEventHandler::ClearEvents() {}
void idAnimWebEventHandler::SetEvent(const idAnimator_AnimWeb*,
    idAnimWebSubWebIndex, idAnimWebStateIndex, animWebEvent_t, int,
    idAnimWebEvent::priority_t) {}
void idAnimWebEventHandler::TriggerEventType(idAnimator_AnimWeb*,
    const idDeclAnimWebNode*, animWebEvent_t, int) {}
bool idAnimWebEventHandler::IsEventPending(animWebEvent_t) const {
    return false;
}
bool idAnimWebEventHandler::IsAnyEventPending() const { return false; }

idAnimWebEventHandler_Zion::idAnimWebEventHandler_Zion() {
    for (idAnimWebEvent& event : events) {
        event.swi.Invalidate();
        event.si.Invalidate();
        event.eventNum = -1;
        event.priority = idAnimWebEvent::PRIORITY_LOW;
    }
}

void idAnimWebEventHandler_Zion::ClearEvent(
        const animWebEvent_t eventType) {
    if (eventType >= 0 && eventType < ANIMWEB_EVENT_MAX)
        events[eventType].eventNum = -1;
}

void idAnimWebEventHandler_Zion::ClearEvents() {
    for (idAnimWebEvent& event : events) event.eventNum = -1;
}

void idAnimWebEventHandler_Zion::SetEvent(
        const idAnimator_AnimWeb*, const idAnimWebSubWebIndex subWeb,
        const idAnimWebStateIndex state, const animWebEvent_t eventType,
        const int eventNum, const idAnimWebEvent::priority_t priority) {
    if (eventType < 0 || eventType >= ANIMWEB_EVENT_MAX) return;
    idAnimWebEvent& event = events[eventType];
    if (event.eventNum >= 0 && event.priority > priority) return;
    event.swi = subWeb;
    event.si = state;
    event.eventNum = eventNum;
    event.priority = priority;
}

void idAnimWebEventHandler_Zion::TriggerEventType(
        idAnimator_AnimWeb* const web, const idDeclAnimWebNode* const node,
        const animWebEvent_t eventType, const int eventParameter) {
    if (node == nullptr || eventType < 0 ||
            eventType >= ANIMWEB_EVENT_MAX) return;
    idAnimWebEvent& event = events[eventType];
    if (event.eventNum >= 0 && GameLib_AnimWebNodeMatchesEvent(
            node, event.swi, event.si)) {
        GameLib_TriggerAnimWebEvent(web, node, eventType, event,
            eventParameter);
        event.eventNum = -1;
    }
}

bool idAnimWebEventHandler_Zion::IsEventPending(
        const animWebEvent_t eventType) const {
    return eventType >= 0 && eventType < ANIMWEB_EVENT_MAX &&
        events[eventType].eventNum >= 0;
}

bool idAnimWebEventHandler_Zion::IsAnyEventPending() const {
    for (const idAnimWebEvent& event : events)
        if (event.eventNum >= 0) return true;
    return false;
}
