#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/bv/boundsshort.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/hashing/crc8.h"
#include "idlib/math/vector.h"
#include "models/skeletalanimation/jobs/md6animdata.h"
#include "models/skeletalanimation/md6phasetrack.h"

enum invalidJointConversionHandle_t : int;
class idDeclMD6;
class idMD6Model;
class idMD6Skel;

class idMD6Anim : public idResource {
public:
    using JointConversionFindCallback = idHandle<unsigned short,
        invalidJointConversionHandle_t, 65535> (*)(const char* name);
    using JointConversionNameCallback = const char* (*)(
        idHandle<unsigned short, invalidJointConversionHandle_t, 65535> handle);
    using TextLoadCallback = bool (*)(idMD6Anim* animation,
        const char* fileName, const float* errorToleranceOverride);
    using RewriteCallback = bool (*)(const char* fileName);
    enum channel_t : int {
        ROTATION_CHANNEL = 0,
        SCALE_CHANNEL,
        TRANSLATION_CHANNEL,
        USER_CHANNEL
    };

    struct animationSettings_t {
        float errorTolerance;
        int startFrameOffset;
        int endFrameOffset;
        bool removeOrigin;
        bool useForwardTranslation;
        bool useLeftTranslation;
        bool useUpTranslation;
        bool useRotation;
        bool retargetAdditive;
        bool facetracksComposite;
        bool frameZeroDelta;
    };

    idMD6Anim();
    ~idMD6Anim() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;

    bool AnimIsOkForModel(const idMD6Model* model) const;
    bool VerifyBoundingBoxes(const idDeclMD6* declaration,
        float epsilon, float jointRadius) const;
    void GetAnimationDelta(idVec3* deltaTranslation,
        idMat3* deltaAxis) const;
    bool LoadBinary(const char* fileName);
    bool WriteBinary(const char* fileName) const;
    bool LoadText(const char* fileName,
        const float* errorToleranceOverride = nullptr);
    void MakeDefault(const idMD6Skel* skeleton);
    void FreeData();

    static idMD6Anim* LoadAnim_UserChannels(const char* fileName);
    static bool LoadAnim_Settings(const char* animationFileName,
        animationSettings_t& settings, unsigned int* timestamp = nullptr,
        bool loadFromAnim = false);
    static bool RewriteText(const char* fileName);
    static void SetCallbacks(JointConversionFindCallback findConversion,
        JointConversionNameCallback conversionName,
        TextLoadCallback textLoader, RewriteCallback rewrite);

    idAtomicString skelName;
    idMD6AnimData* animData;
    idMD6PhaseTrack phaseTrack;
    idBoundsShort translatedBounds;
    idBoundsShort normalizedBounds;
    idHandle<unsigned short, invalidJointConversionHandle_t, 65535>
        jointConversionHandle;
    idHandle<unsigned short, invalidCrc_t, 65535> jointConversionChecksum;
    unsigned int timestamp;
    unsigned int phaseTrackTimestamp;
    unsigned int settingsTimestamp;
    int timeCode;
    idVec3 origWorldPos;
    idAngles origWorldRot;
    idVec3 origWorldScale;
    std::int16_t startFrameOffset;
    std::int16_t endFrameOffset;

    static idTypedResourceList<idMD6Anim> resourceList;

private:
    bool CompressAnim(const idMD6Skel* skeleton, int numFrames,
        int frameRate, const float* rotations, const float* scales,
        const float* translations, const float* userChannels,
        const animationSettings_t& settings, bool additive,
        bool ignoreBounds);
    bool LoadFacetracksComposite(const char* basePath,
        const idMD6Skel* skeleton, const animationSettings_t& settings);
    void VerifyRLEData(const char* animationName,
        const idList<unsigned char, 5>& rotationRLE,
        const idList<unsigned char, 5>& scaleRLE,
        const idList<unsigned char, 5>& translationRLE,
        const idList<unsigned char, 5>& userRLE,
        const idList<unsigned char, 5>& rotationBits,
        const idList<unsigned char, 5>& scaleBits,
        const idList<unsigned char, 5>& translationBits,
        const idList<unsigned char, 5>& userBits) const;
    static JointConversionFindCallback jointConversionFindCallback;
    static JointConversionNameCallback jointConversionNameCallback;
    static TextLoadCallback textLoadCallback;
    static RewriteCallback rewriteCallback;
    static bool skipJoints;
};

static_assert(sizeof(idMD6Anim::animationSettings_t) == 20,
    "Recovered MD6 animation settings ABI changed");
