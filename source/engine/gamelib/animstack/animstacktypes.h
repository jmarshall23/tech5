#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idAnimStack;
class idClip;
class idDeclAnimWeb;
class idDeclAnimWebNode;
class idFile_String;
class idGameTimeManager;
class idMD6Anim;
class idParser;
class idTreeAnimator;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    unsigned long long index;
};
#endif

enum invalidAliasHandle_t : int;
using idAnimAliasHandle = idHandle<unsigned short, invalidAliasHandle_t,
    65535>;

// AnimWeb indices are all signed 16-bit values in tungsten.  Keeping the
// tags here prevents the separately recovered AnimWeb headers from creating
// incompatible aliases for the same ABI types.
enum invalidAnimWebNodeIndex_t : int;
enum invalidAnimWebSubWebIndex_t : int;
enum invalidAnimWebStateIndex_t : int;
enum invalidAnimWebModelIndex_t : int;
enum invalidAnimWebEdgeIndex_t : int;
enum invalidAnimWebHandle_t : int;
using idAnimWebNodeIndex = idIndex<short, invalidAnimWebNodeIndex_t>;
using idAnimWebSubWebIndex = idIndex<short, invalidAnimWebSubWebIndex_t>;
using idAnimWebStateIndex = idIndex<short, invalidAnimWebStateIndex_t>;
using idAnimWebModelIndex = idIndex<short, invalidAnimWebModelIndex_t>;
using idAnimWebEdgeIndex = idIndex<short, invalidAnimWebEdgeIndex_t>;
using idAnimWebHandle = idHandle<short, invalidAnimWebHandle_t, -1>;

struct idAnimWebStateList {
    idAnimWebStateIndex stateIndex[4];
    unsigned short numStates;
};

enum awPathResult_t : int {
    AWPATH_FAILED = 0,
    AWPATH_OK = 1,
    AWPATH_ALREADY_THERE = 2
};

enum interruptPath_t : int {
    INTR_PATH_NO = 0,
    INTR_PATH_YES = 1,
    INTR_PATH_IMMEDIATE = 2,
    INTR_PATH_MAX = 3
};

enum interruptBlend_t : int {
    INTR_BLEND_NO = 0,
    INTR_BLEND_YES = 1,
    INTR_BLEND_MULTI = 2,
    INTR_BLEND_MAX = 3
};

enum awCheckPathResult_t : int {
    CHECKPATH_OK = 0,
    CHECKPATH_WAIT = 1,
    CHECKPATH_INVALID_NODE = 2
};

enum idAnimWebDeltaMode_t : int {
    ANIMDELTA_DEFAULT = 0,
    ANIMDELTA_FULL = 1,
    ANIMDELTA_FULL_NOCLIP = 2,
    ANIMDELTA_FULL_GRAVITY = 3,
    ANIMDELTA_TURN = 4,
    ANIMDELTA_FULL_VELOCITY = 5,
    ANIMDELTA_FULL_DRIVE_AI = 6,
    ANIMDELTA_IGNORE = 7,
    ANIMDELTA_MAX = 8
};

enum gameTimeUnique_t : int;
enum invalidJointIndex_t : int;
enum invalidUserChannelIndex_t : int;
using animationPose_t = int;
using idJointIndex = idIndex<short, invalidJointIndex_t>;
using idUserChannelIndex = idIndex<short, invalidUserChannelIndex_t>;

enum md6WeightGroup_t : int {
    MD6_WEIGHTGROUP_ALL = 0,
    MD6_WEIGHTGROUP_LEGS = 1,
    MD6_WEIGHTGROUP_TORSO = 2,
    MD6_WEIGHTGROUP_HEAD = 3,
    MD6_WEIGHTGROUP_FACE = 4,
    MD6_WEIGHTGROUP_MOUTH = 5,
    MD6_WEIGHTGROUP_EYELIDS = 6,
    MD6_WEIGHTGROUP_USER0 = 7,
    MD6_WEIGHTGROUP_MAX = 8
};

enum serializeType_t : int {
    STYPE_GENERIC = 0,
    STYPE_AF = 1,
    STYPE_ANIMWEB_HANDS = 2,
    STYPE_WALK_IK = 3,
    STYPE_TORSO_TRACKER = 4,
    STYPE_PAIN = 5,
    STYPE_JOINTMOD = 6,
    STYPE_REACH_IK = 7,
    STYPE_MAX = 8
};

class idMD6Node {
public:
    enum nodeType_t : int {
        NODE_BRANCH = 0,
        NODE_LEAF_PAUSE = 1,
        NODE_LEAF_PLAY = 2,
        NODE_BLEND_BRANCH = 3,
        NODE_BLENDA_BRANCH = 4,
        NODE_FUSION_BRANCH = 5,
        NODE_BEST_LEAF = 6,
        NODE_TAG_FILTER = 7,
        NODE_NONE = 0xFF
    };

    std::uint8_t type;
};

class idMD6Branch : public idMD6Node {
public:
    enum blendType_t : int {
        BLEND_LINEAR = 0,
        BLEND_EASEIN = 1,
        BLEND_EASEOUT = 2,
        BLEND_EASEIN_EASEOUT = 3,
        BLEND_TYPE_COUNT = 4
    };

    idMD6Node* left;
    idMD6Node* right;
    int leftTimeOverride;
    int rightTimeOverride;
    std::uint8_t filterGroup;
    std::uint8_t op;
    std::uint8_t originBlend;
    float currentAlpha;
    float targetAlpha;
    float alphaRate;
    blendType_t blendType;
};

// The leaf layout is materialized only to the extent proven by the recovered
// md6animtree and idAnimator_Paused bodies. The two list records remain opaque
// until the joint-mod translation unit is activated.
struct idMD6OpaqueList {
    void* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;
};

class idMD6Leaf : public idMD6Node {
public:
    enum wrapMode_t : int {
        WRAP_CLAMP = 0,
        WRAP_REPEAT = 1,
        WRAP_MAX = 2
    };

    const idMD6Anim* anim;
    std::uint8_t weightGroup;
    std::uint8_t wrapMode;
    std::uint8_t initCounter;
    std::uint8_t pad;
};

class alignas(4) idMD6LeafPlay : public idMD6Leaf {
public:
    int startTime;
    float rateScale;
    std::uint8_t syncGroup;
    std::uint8_t syncEnabled;
    std::uint8_t tailPadding[2];

    void Init(const idMD6Anim* animation, int gameTime, float rate,
        wrapMode_t wrap, md6WeightGroup_t group) {
        type = NODE_LEAF_PLAY;
        anim = animation;
        weightGroup = static_cast<std::uint8_t>(group);
        wrapMode = static_cast<std::uint8_t>(wrap);
        initCounter = 0;
        pad = 0;
        startTime = gameTime;
        rateScale = rate;
        syncGroup = 0;
        syncEnabled = 0;
        tailPadding[0] = tailPadding[1] = 0;
    }
};

class idMD6LeafPause : public idMD6Leaf {
public:
    int currentDeferred;
    idMD6OpaqueList animMods[2];
    std::int16_t flags;
    std::uint8_t framePadding[2];
    float frame;
    idBounds bounds;

    void Init(const idMD6Anim* animation, float animationFrame,
        std::uint8_t animationWrapMode, md6WeightGroup_t animationWeightGroup) {
        type = NODE_LEAF_PAUSE;
        frame = animationFrame;
        anim = animation;
        flags = 0;
        weightGroup = static_cast<std::uint8_t>(animationWeightGroup);
        wrapMode = animationWrapMode;
    }
};

struct blendParms_t {
    enum blendFlags_t : int {
        BLENDFLAG_SOURCE_END_RELATIVE = 1,
        BLENDFLAG_DEST_END_RELATIVE = 2,
        BLENDFLAG_CONVERT_SOURCE_TO_RELATIVE = 4,
        BLENDFLAG_CONVERT_DEST_TO_RELATIVE = 8
    };
    struct parms_t {
        const idMD6Anim* srcAnim;
        const idMD6Anim* destAnim;
        std::int16_t sourceStartFrame;
        std::int16_t sourceDuration;
        std::int16_t destStartFrame;
        std::int16_t destDuration;
        char flags;
        char originBlend;
        char blendType;
    } parms;

    blendParms_t();

    int GetDuration() const;
    int GetDurationMS() const;
    void Write(idFile_String& file, const char* indent) const;
    bool GetSourceFrames(const idMD6Anim* anim, std::int16_t& firstFrame,
        std::int16_t& lastFrame) const;
    bool GetDestFrames(const idMD6Anim* anim, std::int16_t& firstFrame,
        std::int16_t& duration) const;
    void SetDestStartFrame(int frame);
    void SetDuration(int frames);
    void SetDurationMS(int milliseconds);
    void Parse(idDeclAnimWeb* declaration, idDeclAnimWebNode* node,
        const char* toSubWebName, const char* toStateName, idParser& parser);

private:
    bool GetRelativeFrames(const idMD6Anim* anim, bool endRelative,
        const std::int16_t& inFirstFrame, const std::int16_t& inDuration,
        std::int16_t& outFirstRelativeFrame,
        std::int16_t& outLastRelativeFrame) const;
};

struct idGameTimeManagerPtr {
    idGameTimeManager* gameTimeManager;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idMD6Node) == 1,
    "Recovered idMD6Node ABI changed");
static_assert(sizeof(idMD6Branch) == 40,
    "Recovered idMD6Branch ABI changed");
static_assert(sizeof(idMD6OpaqueList) == 16,
    "Recovered MD6 opaque list ABI changed");
static_assert(sizeof(idMD6LeafPause) == 80,
    "Recovered idMD6LeafPause ABI changed");
static_assert(sizeof(idGameTimeManagerPtr) == 4,
    "Recovered idGameTimeManagerPtr ABI changed");
#endif
static_assert(sizeof(idMD6LeafPlay) == 24,
    "Recovered idMD6LeafPlay ABI changed");
static_assert(sizeof(blendParms_t) == 20,
    "Recovered blend parameters ABI changed");
static_assert(sizeof(idClipQuery) == 8,
    "Recovered clip-query ABI changed");
static_assert(sizeof(idAnimWebStateList) == 10,
    "Recovered AnimWeb state-list ABI changed");
