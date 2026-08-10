#pragma once

#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/varargs.h"

#include <cstdint>

enum invalidAnimEventId_t : int;
enum invalidJointIndex_t : int;
class idDeclMD6;
class idFile_String;
class idParser;

struct idCachedJoint {
    bool operator==(const idCachedJoint& other) const;
    bool operator!=(const idCachedJoint& other) const {
        return !(*this == other);
    }

    idIndex<short, invalidJointIndex_t> jointIndex;
    std::int16_t frameNum;
    idVec3 trans;
    idQuat rot;
};

class alignas(4) idMD6AnimEvent {
public:
    using ParseCallback = bool (*)(idMD6AnimEvent& event,
        const idDeclMD6* md6, idParser& parser, int& loadErrors);
    using EventNumberResolver = int (*)(const char* eventName);
    using EventNameResolver = const char* (*)(int eventNumber);

    idMD6AnimEvent();
    idMD6AnimEvent(const idMD6AnimEvent& other);
    ~idMD6AnimEvent();
    idMD6AnimEvent& operator=(const idMD6AnimEvent& other);

    void SetCachedJoint(const idIndex<short, invalidJointIndex_t>& joint,
        int frame, const idVec3& translation, const idQuat& rotation);
    void Copy(const idMD6AnimEvent& other);
    bool Parse(const idDeclMD6* md6, idParser& parser, int& loadErrors);
    void Write(idFile_String& file, const char* indent) const;
    const char* GetEventName() const;
    bool operator==(const idMD6AnimEvent& other) const;
    bool operator!=(const idMD6AnimEvent& other) const {
        return !(*this == other);
    }

    static void SetParseCallback(ParseCallback callback);
    static void SetEventResolvers(EventNumberResolver numberResolver,
        EventNameResolver nameResolver);

    idVarArgs<4> args;
    idCachedJoint* cachedJoint;
    std::int16_t eventNum;
    std::int16_t frameNum;
    idHandle<unsigned int, invalidAnimEventId_t, 0> eventId;
    bool locked;
    std::uint8_t row;

private:
    static ParseCallback parseCallback;
    static EventNumberResolver eventNumberResolver;
    static EventNameResolver eventNameResolver;
};

static_assert(sizeof(idCachedJoint) == 32,
    "Recovered cached-joint ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMD6AnimEvent) == 44,
    "Recovered MD6 animation-event ABI changed");
#endif
