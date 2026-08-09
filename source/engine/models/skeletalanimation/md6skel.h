#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/list.h"
#include "idlib/geometry/jointtransform.h"
#include "idlib/handle.h"
#include "idlib/hashing/crc8.h"
#include "idlib/index.h"
#include "models/skeletalanimation/jobs/md6skeldata.h"

class idMD6Anim;
class idMD6Model;
enum invalidJointConversionHandle_t : int;
enum invalidJointHandle_t : int;
enum invalidUserChannelHandle_t : int;
enum invalidJointIndex_t : int;
enum invalidUserChannelIndex_t : int;

using md6JointHandle_t =
    idHandle<unsigned short, invalidJointHandle_t, 65535>;
using md6UserChannelHandle_t =
    idHandle<unsigned short, invalidUserChannelHandle_t, 65535>;
using md6JointIndex_t = idIndex<short, invalidJointIndex_t>;
using md6UserChannelIndex_t = idIndex<short, invalidUserChannelIndex_t>;

class idMD6Skel : public idResource {
public:
    using NameToJointHandleCallback = md6JointHandle_t (*)(const char* name);
    using JointHandleNameCallback = const char* (*)(md6JointHandle_t handle);
    using NameToUserHandleCallback = md6UserChannelHandle_t (*)(
        const char* name);
    using UserHandleNameCallback = const char* (*)(
        md6UserChannelHandle_t handle);
    using ConversionFindCallback = idHandle<unsigned short,
        invalidJointConversionHandle_t, 65535> (*)(const char* name);
    using ConversionNameCallback = const char* (*)(idHandle<unsigned short,
        invalidJointConversionHandle_t, 65535> handle);
    using PoseFrameCallback = bool (*)(const idMD6Skel* skeleton,
        idJointMat* joints, const idMD6Anim* animation, int frame,
        const idVec3& offset, bool removeOriginOffset);
    using PoseTimeCallback = bool (*)(const idMD6Skel* skeleton,
        idJointMat* joints, const idMD6Anim* animation, int time,
        const idVec3& offset, bool removeOriginOffset);
    using UserChannelCallback = bool (*)(const idMD6Skel* skeleton,
        float* channels, unsigned int channelsSize,
        const idMD6Anim* animation, float frame);
    using TextLoadCallback = bool (*)(idMD6Skel* skeleton,
        const char* fileName);

    enum jointOp_t : int {
        JOINTOP_INCLUDE_CHILDREN = 0x1,
        JOINTOP_SUBTRACT = 0x2
    };

    idMD6Skel();
    ~idMD6Skel() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;

    md6JointIndex_t GetJointIndex(md6JointHandle_t handle) const;
    md6JointIndex_t GetJointIndex(const char* name) const;
    md6JointHandle_t GetJointHandle(int jointIndex) const;
    md6UserChannelIndex_t GetUserChannelIndex(
        md6UserChannelHandle_t handle) const;
    md6UserChannelIndex_t GetUserChannelIndex(const char* name) const;
    md6UserChannelHandle_t GetUserChannelHandle(int channelIndex) const;
    bool IsJointChildOf(md6JointIndex_t joint,
        md6JointIndex_t parent) const;
    bool GetJointsForAnimFrame(idJointMat* joints, const idMD6Anim* animation,
        int frame, const idVec3& offset, bool removeOriginOffset) const;
    bool GetJointsForAnimTime(idJointMat* joints, const idMD6Anim* animation,
        int time, const idVec3& offset, bool removeOriginOffset) const;
    bool GetUserChannelsForAnimFrame(float* channels,
        unsigned int channelsSize, const idMD6Anim* animation,
        float frame) const;
    void GetJointList(const idMD6Model* model, const char* jointNames,
        idList<md6JointIndex_t, 5>& jointList) const;

    bool MakeSkeletonData(int numJoints, const float* basePoseMatrices,
        const md6JointHandle_t* jointHandles, const short* parents,
        int numUserChannels, const float* userChannelDefaults,
        const md6UserChannelHandle_t* userChannelHandles,
        const unsigned char* const jointWeights[8] = nullptr,
        const unsigned char* const userWeights[8] = nullptr);
    bool LoadBinary(const char* fileName);
    bool WriteBinary(const char* fileName) const;
    bool LoadText(const char* fileName);
    void FreeData();

    const float* BaseRotations() const;
    const float* BaseScales() const;
    const float* BaseTranslations() const;
    const float* UserChannelDefaults() const;
    const idJointMat* InverseBasePose() const;
    const idJointQuat* InverseBasePoseQuats() const;
    const short* ParentTable() const;

    static void SetRegistryCallbacks(NameToJointHandleCallback jointLookup,
        JointHandleNameCallback jointName, NameToUserHandleCallback userLookup,
        UserHandleNameCallback userName, ConversionFindCallback conversionFind,
        ConversionNameCallback conversionName);
    static void SetDecodeCallbacks(PoseFrameCallback frameDecoder,
        PoseTimeCallback timeDecoder, UserChannelCallback userDecoder);
    static void SetTextLoadCallback(TextLoadCallback callback);

    const idMD6Anim* defaultAnim;
    idMD6SkelData* data;
    unsigned int timestamp;
    idHandle<unsigned short, invalidJointConversionHandle_t, 65535>
        jointConversion;
    idHandle<unsigned short, invalidCrc_t, 65535> jointConversionChecksum;

    static idTypedResourceList<idMD6Skel> resourceList;

private:
    void AddChildren(md6JointIndex_t parent,
        idList<md6JointIndex_t, 5>& list) const;
    void SubtractChildren(md6JointIndex_t parent,
        idList<md6JointIndex_t, 5>& list) const;

    static NameToJointHandleCallback nameToJointHandleCallback;
    static JointHandleNameCallback jointHandleNameCallback;
    static NameToUserHandleCallback nameToUserHandleCallback;
    static UserHandleNameCallback userHandleNameCallback;
    static ConversionFindCallback conversionFindCallback;
    static ConversionNameCallback conversionNameCallback;
    static PoseFrameCallback poseFrameCallback;
    static PoseTimeCallback poseTimeCallback;
    static UserChannelCallback userChannelCallback;
    static TextLoadCallback textLoadCallback;
};
