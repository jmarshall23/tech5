#pragma once

#include "gamelib/timeline/timelinekeyanimdata.h"
#include "idlib/math/angles.h"
#include "idlib/text/str.h"

class idDeclEnv;
class idSoundShader;

// Local type 14673 is present in tungsten.exe.h without a PDB source path.
class idAnimAliasRef : public idStr {
public:
    idAnimAliasRef() = default;
    explicit idAnimAliasRef(const char *value) : idStr(value) {}
};

enum tlEventType_t : int {
    TL_EVENT_NONE = 0,
    TL_EVENT_ANIM = 1,
    TL_EVENT_SOUND = 2,
    TL_EVENT_TELEPORT = 3,
    TL_EVENT_SETKEY = 4,
    TL_EVENT_ANIMKEY = 5,
    TL_EVENT_ACTIVATE = 6,
    TL_EVENT_SETENV = 7,
    TL_EVENT_MAX = 8,
};

// Reconstructed from tungsten.exe.h local type 19107 and the constructor in
// timelineeventdata.cpp.
struct tlEventData_t {
    tlEventData_t();

    int time;
    int duration;
    tlEventType_t type;
    idAnimAliasRef anim;
    bool useAnimPos;
    const idSoundShader *sound;
    idVec3 worldPos;
    idAngles worldRot;
    tlKeyId_t keyName;
    idStr keyValue;
    mgTimelineKeyAnimData keyAnimData;
    bool activateStart;
    bool activateEnd;
    const idDeclEnv *env;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(tlEventData_t) == 160,
    "Recovered tlEventData_t ABI changed");
#endif
