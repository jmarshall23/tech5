#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idAnimStack;
class idClip;
class idGameTimeManager;
class idMD6Anim;

enum gameTimeUnique_t : int;

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

class idMD6LeafPause : public idMD6Node {
public:
    std::uint8_t nodePadding[3];
    const idMD6Anim* anim;
    std::uint8_t weightGroup;
    std::uint8_t wrapMode;
    std::uint8_t initCounter;
    std::uint8_t pad;
    int currentDeferred;
    idMD6OpaqueList animMods[2];
    std::int16_t flags;
    std::uint8_t framePadding[2];
    float frame;
    idBounds bounds;

    void Init(const idMD6Anim* animation, float animationFrame,
        std::uint8_t animationWrapMode, md6WeightGroup_t animationWeightGroup) {
        frame = animationFrame;
        anim = animation;
        flags = 0;
        weightGroup = static_cast<std::uint8_t>(animationWeightGroup);
        wrapMode = animationWrapMode;
    }
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
