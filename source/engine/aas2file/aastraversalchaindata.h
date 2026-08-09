#pragma once

#include "idlib/index.h"
#include "idlib/math/vector.h"

#include <cstdint>

enum aasType_t : int {
    AAS_MONSTER16 = 0,
    AAS_MONSTER24 = 1,
    AAS_MONSTER32 = 2,
    AAS_MONSTER48 = 3,
    AAS_MONSTER96 = 4,
    AAS_MONSTER128 = 5,
    AAS_MONSTER160 = 6,
    AAS_FILE_EXTENSION_MAX = 8
};

enum invalidReachability_t : int { INVALID_REACHABILITY_INDEX = -1 };
enum invalidAASAnimIndex_t : int { INVALID_AAS_ANIM_INDEX = -1 };
enum invalidAASTree_t : int { INVALID_AAS_TREE_INDEX = -1 };
enum invalidAASDependencyIndex_t : int { INVALID_AAS_DEPENDENCY_NODE = -1 };
enum invalidAASInteractionEntIndex_t : int { INVALID_AAS_INTERACTION_ENT = -1 };
enum invalidAASTraversalNameIndex_t : int { INVALID_AAS_TRAVERSAL_NAME = -1 };

struct aas2Traversal_t {
    idVec3 startPoint;
    idVec3 endPoint;
    idQuantizedVec3 orientationFwd;
    idQuantizedVec3 extrusionFwd;
    idIndex<short, invalidAASAnimIndex_t> animIndex;
    idIndex<short, invalidReachability_t> reachabilityIndex;
    idIndex<short, invalidAASDependencyIndex_t> dependencyIndex;
    idIndex<short, invalidAASInteractionEntIndex_t> interactionEntIndex;
    std::int16_t extrusionDistance;
    std::int16_t startAreaNum;
    std::int16_t endAreaNum;
    idIndex<short, invalidAASTraversalNameIndex_t> traversalNameIndex;
    std::uint32_t flags;

    aas2Traversal_t();
    void Clear();
    void CalcExtrusionPoint(idVec3& extrusionPoint, const idVec3& up) const;
};

using aasTraversalNameIndex_t =
    idIndex<short, invalidAASTraversalNameIndex_t>;

class idDeclAnimWeb;

class idAASTraversalChainData {
public:
    enum localFlags_t : int {
        EVASION_ONLY = 0x1,
        EMERGENCY_ONLY = 0x2,
        COMBAT_ONLY = 0x4,
        ENABLED = 0x8,
        RUN_WHEN_DONE = 0x10,
        DELTA_CORRECT = 0x20,
        MAX_FLAG_BITS = 6
    };
    enum localClass_t : int {
        CLASS_A = 0x1,
        CLASS_B = 0x2,
        CLASS_C = 0x4,
        CLASS_D = 0x8,
        CLASS_E = 0x10,
        MAX_CLASS_BITS = 5
    };

    struct flagMap_t { int gameFlag; int aasFlag; };

    aasType_t mAASType;
    localClass_t mClass;
    localFlags_t mFlags;
    idVec3 mExtrusionEndpoint;
    const idDeclAnimWeb* mAnimWeb;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(aas2Traversal_t) == 56,
    "Recovered aas2Traversal_t ABI changed");
static_assert(sizeof(idAASTraversalChainData) == 28,
    "Recovered idAASTraversalChainData ABI changed");
#endif
