#include "models/skeletalanimation/md6animevent.h"

#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/animevents.h"

#include <malloc.h>
#include <new>

idMD6AnimEvent::ParseCallback idMD6AnimEvent::parseCallback = nullptr;

bool idCachedJoint::operator==(const idCachedJoint& other) const {
    return jointIndex == other.jointIndex && frameNum == other.frameNum &&
        trans.x == other.trans.x && trans.y == other.trans.y &&
        trans.z == other.trans.z && rot.x == other.rot.x &&
        rot.y == other.rot.y && rot.z == other.rot.z && rot.w == other.rot.w;
}

idMD6AnimEvent::idMD6AnimEvent()
    : cachedJoint(nullptr), eventNum(-1), frameNum(0),
      eventId(idAnimEvents::GetNextEventId()), locked(false), row(0) {}

idMD6AnimEvent::idMD6AnimEvent(const idMD6AnimEvent& other)
    : idMD6AnimEvent() {
    Copy(other);
}

idMD6AnimEvent::~idMD6AnimEvent() {
    if (cachedJoint != nullptr) _aligned_free(cachedJoint);
    cachedJoint = nullptr;
}

idMD6AnimEvent& idMD6AnimEvent::operator=(const idMD6AnimEvent& other) {
    Copy(other);
    return *this;
}

void idMD6AnimEvent::SetCachedJoint(
        const idIndex<short, invalidJointIndex_t>& joint, const int frame,
        const idVec3& translation, const idQuat& rotation) {
    if (cachedJoint == nullptr) {
        cachedJoint = static_cast<idCachedJoint*>(
            _aligned_malloc(sizeof(idCachedJoint), 16));
        if (cachedJoint == nullptr) return;
        new (cachedJoint) idCachedJoint;
    }
    cachedJoint->jointIndex = joint;
    cachedJoint->frameNum = static_cast<std::int16_t>(frame);
    cachedJoint->trans = translation;
    cachedJoint->rot = rotation;
}

void idMD6AnimEvent::Copy(const idMD6AnimEvent& other) {
    if (&other == this) return;
    if (other.cachedJoint != nullptr) {
        SetCachedJoint(other.cachedJoint->jointIndex,
            other.cachedJoint->frameNum, other.cachedJoint->trans,
            other.cachedJoint->rot);
    } else if (cachedJoint != nullptr) {
        _aligned_free(cachedJoint);
        cachedJoint = nullptr;
    }
    args = other.args;
    eventNum = other.eventNum;
    frameNum = other.frameNum;
    eventId = other.eventId;
    locked = other.locked;
    row = other.row;
}

bool idMD6AnimEvent::operator==(const idMD6AnimEvent& other) const {
    if (args != other.args || eventNum != other.eventNum ||
            frameNum != other.frameNum || eventId != other.eventId ||
            locked != other.locked || row != other.row) return false;
    if (cachedJoint == nullptr || other.cachedJoint == nullptr)
        return cachedJoint == other.cachedJoint;
    return *cachedJoint == *other.cachedJoint;
}

void idMD6AnimEvent::SetParseCallback(ParseCallback callback) {
    parseCallback = callback;
}

bool idMD6AnimEvent::Parse(const idDeclMD6* md6, idParser& parser,
        int& loadErrors) {
    if (parseCallback != nullptr)
        return parseCallback(*this, md6, parser, loadErrors);

    // Event signatures are registered by the game DLL, outside the model
    // subsystem. Consume the complete event declaration so the owning MD6
    // parser remains synchronized, and report that resolution is unavailable.
    idToken eventName;
    if (!parser.ReadToken(eventName)) {
        ++loadErrors;
        return false;
    }
    parser.SkipBracedSection(true);
    eventNum = -1;
    ++loadErrors;
    return false;
}
