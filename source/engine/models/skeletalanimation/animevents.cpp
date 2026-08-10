#include "models/skeletalanimation/animevents.h"

#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"

idHandle<unsigned int, invalidAnimEventId_t, 0> idAnimEvents::curEventId(0);
idAnimEvents::CacheTransformsCallback idAnimEvents::cacheTransformsCallback =
    nullptr;

idHandle<unsigned int, invalidAnimEventId_t, 0>
idAnimEvents::GetNextEventId() {
    ++curEventId.value;
    if (curEventId.value == 0) curEventId.value = 1;
    return curEventId;
}

bool idAnimEvents::animEventInfo_t::operator==(
    const animEventInfo_t& other) const {
    if (idStr::Icmp(animRef.c_str(), other.animRef.c_str()) != 0 ||
            events.Num() != other.events.Num()) return false;
    for (int index = 0; index < events.Num(); ++index) {
        if (events[index] != other.events[index]) return false;
    }
    return true;
}

bool idAnimEvents::animEventInfo_t::GetCachedJoints(const int eventNumber,
    idStaticList<const idCachedJoint*, 8>& joints) const {
    joints.Clear();
    for (int index = 0; index < events.Num(); ++index) {
        const idMD6AnimEvent& event = events[index];
        if (event.eventNum == eventNumber && event.cachedJoint != nullptr) {
            joints.Append(event.cachedJoint);
        }
    }
    return joints.Num() != 0;
}

idAnimEvents::idAnimEvents() = default;

idAnimEvents::~idAnimEvents() {
    Free();
}

void idAnimEvents::Parse(const idDeclMD6* declaration, idParser& parser,
        int& loadErrors) {
    idToken token;
    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return;
    }

    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Cmp(token.c_str(), "anim") != 0) {
            parser.Error("Unknown token '%s' while reading 'animEvents' block.",
                token.c_str());
            ++loadErrors;
            continue;
        }

        idToken animationName;
        if (!parser.ExpectTokenType(TT_STRING, 0, animationName) ||
                !parser.ExpectTokenString("{")) {
            ++loadErrors;
            break;
        }
        animationName.MakeNameCanonical();

        animEventInfo_t info;
        info.animRef.Set(animationName.c_str());
        while (parser.ReadToken(token)) {
            if (idStr::Cmp(token.c_str(), "}") == 0) break;
            if (idStr::Cmp(token.c_str(), "event") != 0) {
                parser.Error("Unknown token '%s' while reading 'anim' block.",
                    token.c_str());
                ++loadErrors;
                continue;
            }

            idMD6AnimEvent event;
            if (event.Parse(declaration, parser, loadErrors))
                info.events.Append(event);
        }

        const int index = list.Append(info);
        if (index >= 0) {
            hashIndex.Add(hashIndex.GenerateKeyForString(
                info.animRef.c_str(), false), index);
        } else {
            ++loadErrors;
        }
    }
}

void idAnimEvents::SetCacheTransformsCallback(
        const CacheTransformsCallback callback) {
    cacheTransformsCallback = callback;
}

bool idAnimEvents::CacheTransforms(idDeclMD6* declaration) {
    return declaration != nullptr && (cacheTransformsCallback == nullptr ||
        cacheTransformsCallback(*this, *declaration));
}

void idAnimEvents::Write(idFile_String& file, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%sevents {\n", prefix);
    idStr eventIndent(prefix);
    eventIndent.Append("\t\t");
    for (int infoIndex = 0; infoIndex < list.Num(); ++infoIndex) {
        const animEventInfo_t& info = list[infoIndex];
        file.Printf("%s\tanim \"%s\" {\n", prefix,
            info.animRef.c_str());
        for (int eventIndex = 0; eventIndex < info.events.Num();
                ++eventIndex) {
            info.events[eventIndex].Write(file, eventIndent.c_str());
        }
        file.Printf("%s\t}\n", prefix);
    }
    file.Printf("%s}\n", prefix);
}

int idAnimEvents::FindAnimEventInfoIndex(
    const idAtomicStringT<md6AnimAtomicString_t>& animation) const {
    for (int index = 0; index < list.Num(); ++index) {
        if (list[index].animRef == animation) return index;
    }
    return -1;
}

idAnimEvents::animEventInfo_t* idAnimEvents::FindAnimEventInfo(
    const idAtomicStringT<md6AnimAtomicString_t>& animation) {
    return const_cast<animEventInfo_t*>(
        static_cast<const idAnimEvents*>(this)->FindAnimEventInfo(animation));
}

const idAnimEvents::animEventInfo_t* idAnimEvents::FindAnimEventInfo(
    const idAtomicStringT<md6AnimAtomicString_t>& animation) const {
    const int index = FindAnimEventInfoIndex(animation);
    return index >= 0 ? &list[index] : nullptr;
}

namespace {

void InsertEventSorted(idStaticList<const idMD6AnimEvent*, 16>& events,
        const idMD6AnimEvent* event) {
    if (event == nullptr || events.Num() >= events.Max()) return;
    int index = 0;
    while (index < events.Num()) {
        const idMD6AnimEvent* current = events[index];
        if (event->frameNum < current->frameNum ||
            (event->frameNum == current->frameNum &&
             event->row < current->row)) {
            break;
        }
        ++index;
    }
    events.Insert(event, index);
}

bool IsFrameInRange(const int frame, const int startFrame,
        const int endFrame) {
    return startFrame <= endFrame
        ? frame >= startFrame && frame <= endFrame
        : frame >= startFrame || frame <= endFrame;
}

} // namespace

bool idAnimEvents::FindAnimEvents(
        const idAtomicStringT<md6AnimAtomicString_t>& animation,
        const int startFrame, const int endFrame,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    events.Clear();
    const animEventInfo_t* info = FindAnimEventInfo(animation);
    if (info == nullptr) return false;
    for (int index = 0; index < info->events.Num(); ++index) {
        const idMD6AnimEvent& event = info->events[index];
        if (IsFrameInRange(event.frameNum, startFrame, endFrame))
            InsertEventSorted(events, &event);
    }
    return events.Num() != 0;
}

bool idAnimEvents::FindAnimEvents(
        const idAtomicStringT<md6AnimAtomicString_t>& animation,
        const int startFrame, const int endFrame, const int eventNum,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    events.Clear();
    const animEventInfo_t* info = FindAnimEventInfo(animation);
    if (info == nullptr) return false;
    for (int index = 0; index < info->events.Num(); ++index) {
        const idMD6AnimEvent& event = info->events[index];
        if (event.eventNum == eventNum &&
            IsFrameInRange(event.frameNum, startFrame, endFrame)) {
            InsertEventSorted(events, &event);
        }
    }
    return events.Num() != 0;
}

void idAnimEvents::Free() {
    hashIndex.Clear();
    list.ClearFree();
}
