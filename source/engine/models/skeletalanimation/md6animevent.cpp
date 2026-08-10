#include "models/skeletalanimation/md6animevent.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "models/skeletalanimation/animevents.h"

#include <algorithm>
#include <malloc.h>
#include <new>
#include <unordered_map>

idMD6AnimEvent::ParseCallback idMD6AnimEvent::parseCallback = nullptr;
idMD6AnimEvent::EventNumberResolver idMD6AnimEvent::eventNumberResolver =
    nullptr;
idMD6AnimEvent::EventNameResolver idMD6AnimEvent::eventNameResolver = nullptr;

namespace {

std::unordered_map<unsigned int, idStr> recoveredEventNames;

bool EventTokenIs(const idToken& token, const char* text) {
    return idStr::Cmp(token.c_str(), text) == 0;
}

} // namespace

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

void idMD6AnimEvent::SetEventResolvers(
        const EventNumberResolver numberResolver,
        const EventNameResolver nameResolver) {
    eventNumberResolver = numberResolver;
    eventNameResolver = nameResolver;
}

bool idMD6AnimEvent::Parse(const idDeclMD6* md6, idParser& parser,
        int& loadErrors) {
    if (parseCallback != nullptr)
        return parseCallback(*this, md6, parser, loadErrors);

    idToken eventName;
    if (!parser.ExpectTokenType(TT_STRING, 0, eventName)) {
        ++loadErrors;
        return false;
    }
    recoveredEventNames[eventId.Get()] = eventName.c_str();
    const int resolvedNumber = eventNumberResolver != nullptr
        ? eventNumberResolver(eventName.c_str()) : -1;
    eventNum = static_cast<std::int16_t>(resolvedNumber >= -32768 &&
        resolvedNumber <= 32767 ? resolvedNumber : -1);
    args.ClearArgs();

    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return false;
    }
    idToken token;
    while (parser.ReadToken(token)) {
        if (EventTokenIs(token, "}")) break;
        if (EventTokenIs(token, "frame")) {
            frameNum = static_cast<std::int16_t>(parser.ParseInt());
        } else if (EventTokenIs(token, "row")) {
            row = static_cast<std::uint8_t>((std::max)(0,
                (std::min)(255, parser.ParseInt())));
        } else if (EventTokenIs(token, "locked")) {
            locked = parser.ParseBool();
        } else if (EventTokenIs(token, "bool")) {
            args.AddArg(parser.ParseBool());
        } else if (EventTokenIs(token, "int")) {
            args.AddArg(parser.ParseInt());
        } else if (EventTokenIs(token, "float")) {
            args.AddArg(parser.ParseFloat());
        } else if (EventTokenIs(token, "vec3")) {
            idVec3 value(0.0f, 0.0f, 0.0f);
            if (parser.Parse1DMatrix(3, &value.x)) args.AddArg(value);
            else ++loadErrors;
        } else if (EventTokenIs(token, "quat")) {
            idQuat value(0.0f, 0.0f, 0.0f, 1.0f);
            if (parser.Parse1DMatrix(4, &value.x)) args.AddArg(value);
            else ++loadErrors;
        } else if (EventTokenIs(token, "vec4")) {
            idVec4 value(0.0f, 0.0f, 0.0f, 0.0f);
            if (parser.Parse1DMatrix(4, &value.x)) args.AddArg(value);
            else ++loadErrors;
        } else if (EventTokenIs(token, "angles")) {
            idAngles value;
            if (parser.Parse1DMatrix(3, &value.pitch)) args.AddArg(value);
            else ++loadErrors;
        } else if (EventTokenIs(token, "string")) {
            idToken value;
            if (parser.ExpectTokenType(TT_STRING, 0, value))
                args.AddArg(value.c_str());
            else
                ++loadErrors;
        } else {
            parser.Warning("Unknown field '%s' in animation event '%s'",
                token.c_str(), eventName.c_str());
            ++loadErrors;
            parser.SkipRestOfLine();
        }
    }
    return true;
}

const char* idMD6AnimEvent::GetEventName() const {
    if (eventNameResolver != nullptr && eventNum >= 0) {
        const char* resolved = eventNameResolver(eventNum);
        if (resolved != nullptr && *resolved != '\0') return resolved;
    }
    const auto found = recoveredEventNames.find(eventId.Get());
    return found != recoveredEventNames.end()
        ? found->second.c_str() : "<unknown>";
}

void idMD6AnimEvent::Write(idFile_String& file, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%sevent \"%s\" {\n", prefix, GetEventName());
    file.Printf("%s\tframe %d\n", prefix, static_cast<int>(frameNum));
    file.Printf("%s\trow %u\n", prefix, static_cast<unsigned int>(row));
    file.Printf("%s\tlocked %d\n", prefix, locked ? 1 : 0);
    for (int index = 0; index < args.NumArgs(); ++index) {
        switch (args.GetArgType(index)) {
        case ARG_BOOL: {
            bool value = false; args.GetArg(index, value);
            file.Printf("%s\tbool %d\n", prefix, value ? 1 : 0);
            break;
        }
        case ARG_CHAR: {
            char value = 0; args.GetArg(index, value);
            file.Printf("%s\tint %d\n", prefix, static_cast<int>(value));
            break;
        }
        case ARG_INTEGER: {
            int value = 0; args.GetArg(index, value);
            file.Printf("%s\tint %d\n", prefix, value);
            break;
        }
        case ARG_FLOAT: {
            float value = 0.0f; args.GetArg(index, value);
            file.Printf("%s\tfloat %.9g\n", prefix, value);
            break;
        }
        case ARG_VECTOR: {
            idVec3 value; args.GetArg(index, value);
            file.Printf("%s\tvec3 ( %.9g %.9g %.9g )\n", prefix,
                value.x, value.y, value.z);
            break;
        }
        case ARG_QUAT: {
            idQuat value; args.GetArg(index, value);
            file.Printf("%s\tquat ( %.9g %.9g %.9g %.9g )\n", prefix,
                value.x, value.y, value.z, value.w);
            break;
        }
        case ARG_ANGLES: {
            idAngles value; args.GetArg(index, value);
            file.Printf("%s\tangles ( %.9g %.9g %.9g )\n", prefix,
                value.pitch, value.yaw, value.roll);
            break;
        }
        case ARG_VECTOR4: {
            idVec4 value; args.GetArg(index, value);
            file.Printf("%s\tvec4 ( %.9g %.9g %.9g %.9g )\n", prefix,
                value.x, value.y, value.z, value.w);
            break;
        }
        case ARG_STRING: {
            const char* value = ""; args.GetArg(index, value);
            file.Printf("%s\tstring \"%s\"\n", prefix,
                value != nullptr ? value : "");
            break;
        }
        default:
            break;
        }
    }
    file.Printf("%s}\n", prefix);
}
