#pragma once

#include "idlib/index.h"
#include "idlib/hashing/crc8.h"
#include "idlib/math/vector.h"
#include "models/skeletalanimation/jobs/md6animdata.h"
#include "models/skeletalanimation/jobs/md6skeldata.h"

#include <cstdint>

enum invalidJointIndex_t : int;
struct md6AnimCommand_t;
struct frameSetData_t {
    std::uint16_t firstROffset;
    std::uint16_t firstSOffset;
    std::uint16_t firstTOffset;
    std::uint16_t firstUOffset;
    std::uint16_t rangeROffset;
    std::uint16_t rangeSOffset;
    std::uint16_t rangeTOffset;
    std::uint16_t rangeUOffset;
    std::uint16_t RBitsOffset;
    std::uint16_t SBitsOffset;
    std::uint16_t TBitsOffset;
    std::uint16_t UBitsOffset;
    std::uint16_t nextROffset;
    std::uint16_t nextSOffset;
    std::uint16_t nextTOffset;
    std::uint16_t nextUOffset;
    std::uint16_t totalSize;
    std::uint16_t frameStart;
    std::uint16_t frameRange;
    std::uint8_t pad[10];
};

struct alignas(16) md6OriginDelta_t {
    md6OriginDelta_t();

    float deltaRotation[4];
    float deltaScale[4];
    float deltaTranslation[4];
    float animRotation[4];
    float animScale[4];
    float animTranslation[4];
    bool done;
    bool fudged;
    std::uint8_t pad[2];
    int time;
    float jointBounds[6];
};

struct md6BlendInfo_t {
    std::uint8_t op;
    std::uint8_t filterGroup;
    std::uint8_t originBlend;
    std::uint8_t pad;
    float currentAlpha;
};

class idMD6Blend {
public:
    enum blendOp_t : int {
        BOP_NO = 0,
        BOP_LERP,
        BOP_REF_LERP,
        BOP_ADD_LEFT,
        BOP_ADD_RIGHT,
        BOP_SUB_LEFT,
        BOP_SUB_RIGHT,
        BOP_BLEND,
        BOP_BLENDA,
        BOP_FUSION,
        BOP_MAX
    };

    enum originBlend_t : int {
        ORIGINBLEND_BRANCH = 0,
        ORIGINBLEND_LEFT = 1,
        ORIGINBLEND_RIGHT = 2,
        ORIGINBLEND_DEFAULT = ORIGINBLEND_BRANCH,
        ORIGINBLEND_SOURCE = ORIGINBLEND_LEFT,
        ORIGINBLEND_DEST = ORIGINBLEND_RIGHT,
        ORIGINBLEND_MAX = 3
    };

    enum jointModFlag_t : std::uint16_t {
        DRIVER_MODEL = 0x01,
        DRIVER_ROTATION = 0x02,
        DRIVER_SCALE = 0x04,
        DRIVER_TRANSLATION = 0x08,
        DRIVER_USERCHANNEL = 0x10,
        DRIVER_OVERRIDE = 0x20,
        POSE_REFERENCE = 0x40,
        POSE_FINAL = 0x80
    };

    struct configInfo_t {
        float visualOffset[4];
    };

    struct alignas(16) jointMod_t {
        float mat[12];
        float s[3];
        idIndex<short, invalidJointIndex_t> joint;
        std::uint16_t flags;
    };

    struct blendParms_t {
        const idMD6SkelData* skeleton;
        const configInfo_t* config;
        const md6AnimCommand_t* cmds;
        const jointMod_t* mods;
        const float* invertedBasePose;
        const float* invertedBasePoseQuat;
        const std::uint8_t* jointRemap;
        unsigned int numCmds;
        unsigned int numMods;
        unsigned int clearOriginTransform;
        unsigned int flags;
        idIndex<short, invalidJointIndex_t> boundsSkipJoint;
        std::uint16_t pad;
        float* referencePose;
        float* finalPose;
        float* renderPose;
        float* userChannels;
        md6OriginDelta_t* originDelta;
    };

    struct frameOffsets_t {
        std::uint8_t leftFrameOffset[256];
        std::uint8_t rightFrameOffset[256];
        std::uint16_t leftKeyOffset[256];
        std::uint16_t rightKeyOffset[256];
    };

    struct doubleStack_t {
        char* start;
        char* end;
        char* top;
        char* bot;
    };

    static int GetAnimMapIndex(const idMD6AnimData* animation,
        idHandle<unsigned short, invalidCrc_t, 65535> parentTableCrc);
    static unsigned int DecodeRLE(const std::uint8_t* encoded,
        std::uint16_t sentinel, std::uint8_t* indices);
    static void DecodeUserChannelsForAnimFrame(const idMD6SkelData* skeleton,
        const idMD6AnimData* animation, float frame, float* output,
        unsigned int outputBytes);
    static void DecodeBasePose(const idMD6SkelData* skeleton, void* temp,
        unsigned int tempSize, const float* originOffset, bool addOffset,
        float* outputMatrices);
    static void DecodeSingleFrame(const idMD6SkelData* skeleton, void* temp,
        unsigned int tempSize, const idMD6AnimData* animation, int frame,
        int ticksPerSecond, bool clearOriginTransform,
        const float* originOffset, bool addOffset, float* outputMatrices,
        float* outputUserChannels);
    static void DecodeSingleFrameWithOriginDeltaScale(
        const idMD6SkelData* skeleton, void* temp, unsigned int tempSize,
        const idMD6AnimData* animation, int frame, int ticksPerSecond,
        bool clearOriginTransform, const float* originOffset, bool addOffset,
        float* outputMatrices, float* outputUserChannels,
        const float* originDeltaScale);
    static void TransformLocalJointsToModelMatrices(
        const idMD6SkelData* skeleton, void* temp, unsigned int tempSize,
        const jointMod_t* modifiers, unsigned int numModifiers,
        const float* originOffset, bool addOffset, const float* rotations,
        const float* scales, const float* translations,
        float* outputMatrices, float* quaternionTemp = nullptr);
    static void TransformModelMatrices(const idMD6SkelData* skeleton,
        const std::uint8_t* remap, const float* inputMatrices,
        const float* inverseMatrices, const float* inverseQuaternions,
        float* outputMatrices, bool useDualQuaternion,
        float* quaternionTemp = nullptr);
    static void CalculatePoseBounds(const idMD6SkelData* skeleton,
        const float* finalPose,
        idIndex<short, invalidJointIndex_t> boundsSkipJoint,
        md6OriginDelta_t* originDelta);
    static void ExecuteCommands(const blendParms_t& parameters, void* temp,
        unsigned int tempSize, bool useDualQuaternion = false);
    static void ExecuteCommandsToRSTU(const blendParms_t& parameters,
        void* temp, unsigned int tempSize, float* rotations, float* scales,
        float* translations, float* userChannels);
};

struct md6FrameInfo_t {
    const idMD6AnimData* animData;
    const frameSetData_t* frameSetData;
    const idMD6Blend::jointMod_t* animMods;
    std::uint16_t flags;
    std::uint16_t weightGroup;
    std::uint16_t animInfoSize;
    std::uint16_t frameSetSize;
    std::uint16_t animModsSize;
    std::int16_t frame;
    float frameFraction;
    std::int16_t frameSetFrame;
    std::int16_t originFrame;
    float originFrameFraction;
    std::int16_t originFrameSetFrame;
    std::uint16_t originFrameSetSize;
    const frameSetData_t* originFrameSetData;
};

struct md6AnimCommand_t {
    enum op_t : int {
        OP_NO = 0,
        OP_END = 1,
        OP_DECODE_AND_PUSH = 2,
        OP_DECODE_FACECOMPOSITE_AND_BLEND = 3,
        OP_POP_AND_BLEND = 4
    };

    op_t op;
    md6FrameInfo_t frameInfo;
    md6BlendInfo_t blendInfo;
    int debugCommand;
    const char* animName;
};

static_assert(sizeof(md6BlendInfo_t) == 8,
    "Recovered MD6 blend-info ABI changed");
static_assert(sizeof(md6OriginDelta_t) == 128,
    "Recovered MD6 origin-delta ABI changed");
static_assert(sizeof(idMD6Blend::jointMod_t) == 64,
    "Recovered MD6 joint-modifier ABI changed");
static_assert(sizeof(idMD6Blend::frameOffsets_t) == 1536,
    "Recovered MD6 frame-offset ABI changed");
static_assert(sizeof(frameSetData_t) == 48,
    "Recovered MD6 frame-set ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMD6Blend::blendParms_t) == 0x44,
    "Recovered MD6 blend-parameter ABI changed");
static_assert(sizeof(idMD6Blend::doubleStack_t) == 16,
    "Recovered MD6 double-stack ABI changed");
#endif
