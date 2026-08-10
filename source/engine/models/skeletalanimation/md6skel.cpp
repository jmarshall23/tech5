#include "models/skeletalanimation/md6skel.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/jobs/md6blend.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <malloc.h>
#include <sstream>
#include <string>
#include <vector>

namespace {

constexpr unsigned int MD6_SKEL_MAGIC = 137777997u;
constexpr unsigned int MD6_SKEL_CONFIG_MAGIC = 37112397u;
constexpr int MD6_SKEL_CONFIG_VERSION = 2;
constexpr int MAX_MD6_JOINTS = 256;
constexpr int MAX_MD6_USER_CHANNELS = 2048;

unsigned int Align16(unsigned int value) { return (value + 15u) & ~15u; }
int Pad8(int value) { return (value + 7) & ~7; }

bool ReadExact(idFile* file, void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteExact(idFile* file, const void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

idQuat MatrixToQuat(const idMat3& matrix) {
    idQuat result;
    const float trace = matrix[0].x + matrix[1].y + matrix[2].z;
    if (trace > 0.0f) {
        const float root = std::sqrt(trace + 1.0f);
        result.w = 0.5f * root;
        const float factor = 0.5f / root;
        result.x = (matrix[2].y - matrix[1].z) * factor;
        result.y = (matrix[0].z - matrix[2].x) * factor;
        result.z = (matrix[1].x - matrix[0].y) * factor;
    } else {
        const int next[3] = { 1, 2, 0 };
        int i = matrix[1].y > matrix[0].x ? 1 : 0;
        if (matrix[2].z > matrix[i][i]) i = 2;
        const int j = next[i], k = next[j];
        float root = std::sqrt((std::max)(0.0f,
            matrix[i][i] - matrix[j][j] - matrix[k][k] + 1.0f));
        result[i] = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.w = (matrix[k][j] - matrix[j][k]) * factor;
        result[j] = (matrix[j][i] + matrix[i][j]) * factor;
        result[k] = (matrix[k][i] + matrix[i][k]) * factor;
    }
    return result.Normalize();
}

idJointMat MultiplyAffine(const idJointMat& left, const idJointMat& right) {
    idJointMat result{};
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            result[row][column] = left[row][0] * right[0][column] +
                left[row][1] * right[1][column] +
                left[row][2] * right[2][column];
        }
        result[row][3] = left[row][0] * right[0][3] +
            left[row][1] * right[1][3] + left[row][2] * right[2][3] +
            left[row][3];
    }
    return result;
}

idJointMat InvertAffine(const idJointMat& source) {
    idMat3 axis(source.mat[0], source.mat[1], source.mat[2],
        source.mat[4], source.mat[5], source.mat[6],
        source.mat[8], source.mat[9], source.mat[10]);
    if (!axis.InverseSelf()) axis = idMat3(1.0f);
    const idVec3 translation(source.mat[3], source.mat[7], source.mat[11]);
    const idVec3 inverseTranslation = axis * (translation * -1.0f);
    idJointMat result{};
    for (int row = 0; row < 3; ++row) {
        result[row][0] = axis[row][0];
        result[row][1] = axis[row][1];
        result[row][2] = axis[row][2];
        result[row][3] = inverseTranslation[row];
    }
    return result;
}

} // namespace

idTypedResourceList<idMD6Skel> idMD6Skel::resourceList("skeleton");
idTypedResourceList<idMD6SkeletonConfig>
    idMD6SkeletonConfig::resourceList("skeletonconfig");
idMD6Skel::NameToJointHandleCallback idMD6Skel::nameToJointHandleCallback = nullptr;
idMD6Skel::JointHandleNameCallback idMD6Skel::jointHandleNameCallback = nullptr;
idMD6Skel::NameToUserHandleCallback idMD6Skel::nameToUserHandleCallback = nullptr;
idMD6Skel::UserHandleNameCallback idMD6Skel::userHandleNameCallback = nullptr;
idMD6Skel::ConversionFindCallback idMD6Skel::conversionFindCallback = nullptr;
idMD6Skel::ConversionNameCallback idMD6Skel::conversionNameCallback = nullptr;
idMD6Skel::PoseFrameCallback idMD6Skel::poseFrameCallback = nullptr;
idMD6Skel::PoseTimeCallback idMD6Skel::poseTimeCallback = nullptr;
idMD6Skel::UserChannelCallback idMD6Skel::userChannelCallback = nullptr;
idMD6Skel::TextLoadCallback idMD6Skel::textLoadCallback = nullptr;

idMD6Skel::idMD6Skel()
    : defaultAnim(nullptr), data(nullptr), timestamp(~0u), jointConversion(),
      jointConversionChecksum() {}

idMD6Skel::~idMD6Skel() { FreeData(); }

void idMD6Skel::FreeData() {
    if (data != nullptr) _aligned_free(data);
    data = nullptr;
    defaultAnim = nullptr;
}

idResourceList* idMD6Skel::GetResourceList() { return &resourceList; }

void idMD6Skel::SetRegistryCallbacks(NameToJointHandleCallback jointLookup,
        JointHandleNameCallback jointName, NameToUserHandleCallback userLookup,
        UserHandleNameCallback userName, ConversionFindCallback conversionFind,
        ConversionNameCallback conversionName) {
    nameToJointHandleCallback = jointLookup;
    jointHandleNameCallback = jointName;
    nameToUserHandleCallback = userLookup;
    userHandleNameCallback = userName;
    conversionFindCallback = conversionFind;
    conversionNameCallback = conversionName;
}

void idMD6Skel::SetDecodeCallbacks(PoseFrameCallback frameDecoder,
        PoseTimeCallback timeDecoder, UserChannelCallback userDecoder) {
    poseFrameCallback = frameDecoder;
    poseTimeCallback = timeDecoder;
    userChannelCallback = userDecoder;
}

void idMD6Skel::SetTextLoadCallback(TextLoadCallback callback) {
    textLoadCallback = callback;
}

const float* idMD6Skel::BaseRotations() const {
    return data != nullptr ? reinterpret_cast<const float*>(
        reinterpret_cast<const unsigned char*>(data) + data->basePoseOffset)
        : nullptr;
}

const float* idMD6Skel::BaseScales() const {
    return data != nullptr ? BaseRotations() + 4 * Pad8(data->numJoints) : nullptr;
}

const float* idMD6Skel::BaseTranslations() const {
    return data != nullptr ? BaseRotations() + 7 * Pad8(data->numJoints) : nullptr;
}

const float* idMD6Skel::UserChannelDefaults() const {
    return data != nullptr ? BaseRotations() + 10 * Pad8(data->numJoints) : nullptr;
}

const idJointMat* idMD6Skel::InverseBasePose() const {
    return data != nullptr ? reinterpret_cast<const idJointMat*>(
        reinterpret_cast<const unsigned char*>(data) +
            data->inverseBasePoseOffset) : nullptr;
}

const idJointQuat* idMD6Skel::InverseBasePoseQuats() const {
    return data != nullptr ? reinterpret_cast<const idJointQuat*>(
        reinterpret_cast<const unsigned char*>(data) +
            data->inverseBasePoseQuatOffset) : nullptr;
}

const short* idMD6Skel::ParentTable() const {
    return data != nullptr ? reinterpret_cast<const short*>(
        reinterpret_cast<const unsigned char*>(data) + data->parentTblOffset)
        : nullptr;
}

md6JointHandle_t idMD6Skel::GetJointHandle(const int jointIndex) const {
    if (data == nullptr || jointIndex < 0 || jointIndex >= data->numJoints)
        return md6JointHandle_t();
    const md6JointHandle_t* handles = reinterpret_cast<const md6JointHandle_t*>(
        reinterpret_cast<const unsigned char*>(data) +
            data->jointHandleTblOffset);
    return handles[jointIndex];
}

const char* idMD6Skel::GetJointName(const int jointIndex) const {
    const md6JointHandle_t handle = GetJointHandle(jointIndex);
    return handle.IsValid() && jointHandleNameCallback != nullptr
        ? jointHandleNameCallback(handle) : nullptr;
}

md6JointIndex_t idMD6Skel::GetJointIndex(const md6JointHandle_t handle) const {
    if (data == nullptr || !handle.IsValid()) return md6JointIndex_t();
    for (int index = 0; index < data->numJoints; ++index)
        if (GetJointHandle(index) == handle)
            return md6JointIndex_t(static_cast<short>(index));
    return md6JointIndex_t();
}

md6JointIndex_t idMD6Skel::GetJointIndex(const char* name) const {
    return nameToJointHandleCallback != nullptr && name != nullptr
        ? GetJointIndex(nameToJointHandleCallback(name)) : md6JointIndex_t();
}

md6UserChannelHandle_t idMD6Skel::GetUserChannelHandle(
        const int channelIndex) const {
    if (data == nullptr || channelIndex < 0 ||
            channelIndex >= data->numUserChannels)
        return md6UserChannelHandle_t();
    const md6UserChannelHandle_t* handles =
        reinterpret_cast<const md6UserChannelHandle_t*>(
            reinterpret_cast<const unsigned char*>(data) +
                data->userChannelHandleTblOffset);
    return handles[channelIndex];
}

md6UserChannelIndex_t idMD6Skel::GetUserChannelIndex(
        const md6UserChannelHandle_t handle) const {
    if (data == nullptr || !handle.IsValid()) return md6UserChannelIndex_t();
    for (int index = 0; index < data->numUserChannels; ++index)
        if (GetUserChannelHandle(index) == handle)
            return md6UserChannelIndex_t(static_cast<short>(index));
    return md6UserChannelIndex_t();
}

md6UserChannelIndex_t idMD6Skel::GetUserChannelIndex(
        const char* name) const {
    return nameToUserHandleCallback != nullptr && name != nullptr
        ? GetUserChannelIndex(nameToUserHandleCallback(name))
        : md6UserChannelIndex_t();
}

bool idMD6Skel::IsJointChildOf(md6JointIndex_t joint,
        md6JointIndex_t parent) const {
    if (data == nullptr || !joint.IsValid() || !parent.IsValid() ||
            joint.Get() >= data->numJoints || parent.Get() >= data->numJoints)
        return false;
    const short* parents = ParentTable();
    int current = parents[joint.Get()];
    while (current >= 0 && current < data->numJoints) {
        if (current == parent.Get()) return true;
        current = parents[current];
    }
    return false;
}

bool idMD6Skel::MakeSkeletonData(const int numJoints,
        const float* basePose, const md6JointHandle_t* jointHandles,
        const short* parents, const int numUserChannels,
        const float* userChannelDefaults,
        const md6UserChannelHandle_t* userChannelHandles,
        const unsigned char* const jointWeights[8],
        const unsigned char* const userWeights[8]) {
    if (numJoints < 0 || numJoints > MAX_MD6_JOINTS || numUserChannels < 0 ||
            numUserChannels > MAX_MD6_USER_CHANNELS ||
            (numJoints > 0 && (basePose == nullptr ||
             jointHandles == nullptr || parents == nullptr)) ||
            (numUserChannels > 0 && (userChannelDefaults == nullptr ||
             userChannelHandles == nullptr))) return false;
    const int paddedJoints = Pad8(numJoints);
    const int paddedUsers = Pad8(numUserChannels);
    unsigned int cursor = sizeof(idMD6SkelData);
    const unsigned int basePoseOffset = cursor;
    cursor = Align16(cursor + 40u * paddedJoints + 4u * paddedUsers);
    const unsigned int inverseOffset = cursor;
    cursor = Align16(cursor + sizeof(idJointMat) * paddedJoints);
    const unsigned int inverseQuatOffset = cursor;
    cursor = Align16(cursor + sizeof(idJointQuat) * paddedJoints);
    const unsigned int parentOffset = cursor;
    cursor = Align16(cursor + sizeof(short) * paddedJoints);
    const unsigned int jointHandleOffset = cursor;
    cursor = Align16(cursor + sizeof(md6JointHandle_t) * paddedJoints);
    const unsigned int userHandleOffset = cursor;
    cursor = Align16(cursor + sizeof(md6UserChannelHandle_t) * paddedUsers);
    unsigned int jointWeightOffset[8]{};
    unsigned int userWeightOffset[8]{};
    for (int group = 0; group < 8; ++group) {
        if (jointWeights != nullptr && jointWeights[group] != nullptr) {
            jointWeightOffset[group] = cursor;
            cursor = Align16(cursor + paddedJoints);
        }
    }
    for (int group = 0; group < 8; ++group) {
        if (userWeights != nullptr && userWeights[group] != nullptr) {
            userWeightOffset[group] = cursor;
            cursor = Align16(cursor + paddedUsers);
        }
    }
    if (cursor > 0xFFFFu) return false;
    idMD6SkelData* replacement = static_cast<idMD6SkelData*>(
        _aligned_malloc(cursor, 16));
    if (replacement == nullptr) return false;
    std::memset(replacement, 0, cursor);
    replacement->size = static_cast<std::uint16_t>(cursor);
    replacement->numJoints = static_cast<std::uint16_t>(numJoints);
    replacement->numUserChannels = static_cast<std::uint16_t>(numUserChannels);
    replacement->basePoseOffset = static_cast<std::uint16_t>(basePoseOffset);
    replacement->inverseBasePoseOffset =
        static_cast<std::uint16_t>(inverseOffset);
    replacement->inverseBasePoseQuatOffset =
        static_cast<std::uint16_t>(inverseQuatOffset);
    replacement->parentTblOffset = static_cast<std::uint16_t>(parentOffset);
    replacement->jointHandleTblOffset =
        static_cast<std::uint16_t>(jointHandleOffset);
    replacement->userChannelHandleTblOffset =
        static_cast<std::uint16_t>(userHandleOffset);
    for (int group = 0; group < 8; ++group) {
        replacement->jointWeightOffsets[group] =
            static_cast<std::uint16_t>(jointWeightOffset[group]);
        replacement->userWeightOffsets[group] =
            static_cast<std::uint16_t>(userWeightOffset[group]);
    }

    float* rotations = reinterpret_cast<float*>(
        reinterpret_cast<unsigned char*>(replacement) + basePoseOffset);
    float* scales = rotations + 4 * paddedJoints;
    float* translations = rotations + 7 * paddedJoints;
    float* users = rotations + 10 * paddedJoints;
    idJointMat* inverse = reinterpret_cast<idJointMat*>(
        reinterpret_cast<unsigned char*>(replacement) + inverseOffset);
    idJointQuat* inverseQuats = reinterpret_cast<idJointQuat*>(
        reinterpret_cast<unsigned char*>(replacement) + inverseQuatOffset);
    short* parentTable = reinterpret_cast<short*>(
        reinterpret_cast<unsigned char*>(replacement) + parentOffset);
    md6JointHandle_t* outputJointHandles =
        reinterpret_cast<md6JointHandle_t*>(
            reinterpret_cast<unsigned char*>(replacement) + jointHandleOffset);
    md6UserChannelHandle_t* outputUserHandles =
        reinterpret_cast<md6UserChannelHandle_t*>(
            reinterpret_cast<unsigned char*>(replacement) + userHandleOffset);
    for (int index = 0; index < paddedJoints; ++index) {
        parentTable[index] = -1;
        outputJointHandles[index].Invalidate();
        rotations[index * 4 + 3] = 1.0f;
        scales[index * 3 + 0] = scales[index * 3 + 1] =
            scales[index * 3 + 2] = 1.0f;
    }
    for (int index = 0; index < paddedUsers; ++index)
        outputUserHandles[index].Invalidate();

    idJointMat modelMatrices[MAX_MD6_JOINTS]{};
    const float* inputRotations = numJoints > 0 ? basePose : nullptr;
    const float* inputScales = numJoints > 0
        ? basePose + 4 * paddedJoints : nullptr;
    const float* inputTranslations = numJoints > 0
        ? basePose + 8 * paddedJoints : nullptr;
    for (int index = 0; index < numJoints; ++index) {
        idQuat rotation(inputRotations[index * 4 + 0],
            inputRotations[index * 4 + 1],
            inputRotations[index * 4 + 2],
            inputRotations[index * 4 + 3]);
        rotation.Normalize();
        if (rotation.w < 0.0f) {
            rotation.x = -rotation.x; rotation.y = -rotation.y;
            rotation.z = -rotation.z; rotation.w = -rotation.w;
        }
        const idVec3 scale(inputScales[index * 4 + 0],
            inputScales[index * 4 + 1], inputScales[index * 4 + 2]);
        const idVec3 translation(inputTranslations[index * 4 + 0],
            inputTranslations[index * 4 + 1],
            inputTranslations[index * 4 + 2]);
        rotations[index * 4 + 0] = rotation.x;
        rotations[index * 4 + 1] = rotation.y;
        rotations[index * 4 + 2] = rotation.z;
        rotations[index * 4 + 3] = rotation.w;
        scales[index * 3 + 0] = scale.x;
        scales[index * 3 + 1] = scale.y;
        scales[index * 3 + 2] = scale.z;
        translations[index * 3 + 0] = translation.x;
        translations[index * 3 + 1] = translation.y;
        translations[index * 3 + 2] = translation.z;
        parentTable[index] = parents[index];
        outputJointHandles[index] = jointHandles[index];
        idMat3 axis = rotation.ToMat3();
        axis[0] = axis[0] * scale.x;
        axis[1] = axis[1] * scale.y;
        axis[2] = axis[2] * scale.z;
        idJointMat local{};
        for (int row = 0; row < 3; ++row) {
            local[row][0] = axis[row][0];
            local[row][1] = axis[row][1];
            local[row][2] = axis[row][2];
            local[row][3] = translation[row];
        }
        modelMatrices[index] = parents[index] >= 0 && parents[index] < index
            ? MultiplyAffine(modelMatrices[parents[index]], local) : local;
        inverse[index] = InvertAffine(modelMatrices[index]);
        const idMat3 inverseAxis(inverse[index].mat[0], inverse[index].mat[1],
            inverse[index].mat[2], inverse[index].mat[4], inverse[index].mat[5],
            inverse[index].mat[6], inverse[index].mat[8], inverse[index].mat[9],
            inverse[index].mat[10]);
        const idQuat inverseRotation = MatrixToQuat(inverseAxis);
        inverseQuats[index].Rotation() = inverseRotation;
        inverseQuats[index].Translation().Set(inverse[index].mat[3],
            inverse[index].mat[7], inverse[index].mat[11]);
        inverseQuats[index].jointQuat[7] = 0.0f;
    }
    if (numUserChannels > 0) {
        std::memcpy(users, userChannelDefaults,
            numUserChannels * sizeof(float));
        std::memcpy(outputUserHandles, userChannelHandles,
            numUserChannels * sizeof(md6UserChannelHandle_t));
    }
    for (int group = 0; group < 8; ++group) {
        if (jointWeightOffset[group] != 0)
            std::memcpy(reinterpret_cast<unsigned char*>(replacement) +
                jointWeightOffset[group], jointWeights[group], numJoints);
        if (userWeightOffset[group] != 0)
            std::memcpy(reinterpret_cast<unsigned char*>(replacement) +
                userWeightOffset[group], userWeights[group], numUserChannels);
    }
    std::uint16_t crc = 0;
    for (int index = 0; index < paddedJoints; ++index)
        crc = static_cast<std::uint16_t>((crc * 33u) ^
            static_cast<unsigned short>(parentTable[index]));
    replacement->parentTblCrc = crc;
    FreeData();
    data = replacement;
    return true;
}

bool idMD6Skel::GetJointsForAnimFrame(idJointMat* joints,
        const idMD6Anim* animation, const int frame, const idVec3& offset,
        const bool removeOriginOffset) const {
    if (joints == nullptr || data == nullptr) return false;
    if (poseFrameCallback != nullptr && animation != nullptr)
        return poseFrameCallback(this, joints, animation, frame, offset,
            removeOriginOffset);
    if (animation != nullptr && animation->animData != nullptr) {
        idMD6Blend::DecodeSingleFrame(data, nullptr, 0,
            animation->animData, frame, 0, removeOriginOffset, &offset.x,
            !removeOriginOffset, reinterpret_cast<float*>(joints), nullptr);
        return true;
    }
    const float* rotations = BaseRotations();
    const float* scales = BaseScales();
    const float* translations = BaseTranslations();
    idJointMat modelMatrices[MAX_MD6_JOINTS]{};
    for (int index = 0; index < data->numJoints; ++index) {
        const idQuat rotation(rotations[index * 4], rotations[index * 4 + 1],
            rotations[index * 4 + 2], rotations[index * 4 + 3]);
        idMat3 axis = rotation.ToMat3();
        axis[0] = axis[0] * scales[index * 3];
        axis[1] = axis[1] * scales[index * 3 + 1];
        axis[2] = axis[2] * scales[index * 3 + 2];
        idJointMat local{};
        for (int row = 0; row < 3; ++row) {
            local[row][0] = axis[row][0]; local[row][1] = axis[row][1];
            local[row][2] = axis[row][2];
            local[row][3] = translations[index * 3 + row];
        }
        const int parent = ParentTable()[index];
        modelMatrices[index] = parent >= 0 && parent < index
            ? MultiplyAffine(modelMatrices[parent], local) : local;
        joints[index] = modelMatrices[index];
    }
    if (data->numJoints > 0 && !removeOriginOffset) {
        joints[0].mat[3] += offset.x;
        joints[0].mat[7] += offset.y;
        joints[0].mat[11] += offset.z;
    }
    return true;
}

bool idMD6Skel::GetJointsForAnimTime(idJointMat* joints,
        const idMD6Anim* animation, const int time, const idVec3& offset,
        const bool removeOriginOffset) const {
    if (poseTimeCallback != nullptr && animation != nullptr)
        return poseTimeCallback(this, joints, animation, time, offset,
            removeOriginOffset);
    int frame = 0;
    if (animation != nullptr && animation->animData != nullptr &&
            animation->animData->frameRate > 0) {
        frame = static_cast<int>((static_cast<long long>(time) *
            animation->animData->frameRate) / 1000);
        frame = (std::max)(0, (std::min)(frame,
            static_cast<int>(animation->animData->numFrames) - 1));
    }
    return GetJointsForAnimFrame(joints, animation, frame, offset,
        removeOriginOffset);
}

bool idMD6Skel::GetUserChannelsForAnimFrame(float* channels,
        const unsigned int channelsSize, const idMD6Anim* animation,
        const float frame) const {
    if (channels == nullptr || data == nullptr ||
            channelsSize < data->numUserChannels * sizeof(float)) return false;
    if (userChannelCallback != nullptr && animation != nullptr)
        return userChannelCallback(this, channels, channelsSize, animation,
            frame);
    if (animation != nullptr && animation->animData != nullptr) {
        idMD6Blend::DecodeUserChannelsForAnimFrame(data,
            animation->animData, frame, channels, channelsSize);
        return true;
    }
    std::memcpy(channels, UserChannelDefaults(),
        data->numUserChannels * sizeof(float));
    return true;
}

void idMD6Skel::AddChildren(md6JointIndex_t parent,
        idList<md6JointIndex_t, 5>& list) const {
    if (data == nullptr || !parent.IsValid()) return;
    for (int index = 0; index < data->numJoints; ++index) {
        if (ParentTable()[index] == parent.Get()) {
            const md6JointIndex_t child(static_cast<short>(index));
            list.AddUnique(child);
            AddChildren(child, list);
        }
    }
}

void idMD6Skel::SubtractChildren(md6JointIndex_t parent,
        idList<md6JointIndex_t, 5>& list) const {
    if (data == nullptr || !parent.IsValid()) return;
    for (int index = 0; index < data->numJoints; ++index) {
        if (ParentTable()[index] == parent.Get()) {
            const md6JointIndex_t child(static_cast<short>(index));
            list.Remove(child);
            SubtractChildren(child, list);
        }
    }
}

void idMD6Skel::GetJointList(const idMD6Model*, const char* jointNames,
        idList<md6JointIndex_t, 5>& jointList) const {
    jointList.Clear();
    if (jointNames == nullptr) return;
    std::istringstream stream(jointNames);
    std::string token;
    bool includeChildren = false, subtract = false;
    while (stream >> token) {
        if (token == "*") { includeChildren = true; continue; }
        if (token == "-") { subtract = true; continue; }
        if (!token.empty() && token[0] == '-') {
            subtract = true;
            token.erase(token.begin());
        }
        if (!token.empty() && token.back() == '*') {
            includeChildren = true;
            token.pop_back();
        }
        const md6JointIndex_t joint = GetJointIndex(token.c_str());
        if (!joint.IsValid()) { includeChildren = subtract = false; continue; }
        if (subtract) {
            jointList.Remove(joint);
            if (includeChildren) SubtractChildren(joint, jointList);
        } else {
            jointList.AddUnique(joint);
            if (includeChildren) AddChildren(joint, jointList);
        }
        includeChildren = subtract = false;
    }
}

bool idMD6Skel::LoadBinary(const char* fileName) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0, sourceTimestamp = 0, size = 0;
    if (file.file == nullptr || !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != MD6_SKEL_MAGIC ||
            !ReadExact(file.file, &sourceTimestamp, sizeof(sourceTimestamp)) ||
            !ReadExact(file.file, &size, sizeof(size)) ||
            size < sizeof(idMD6SkelData) || size > 0xFFFFu) return false;
    idMD6SkelData* replacement = static_cast<idMD6SkelData*>(
        _aligned_malloc(size, 16));
    if (replacement == nullptr) return false;
    if (!ReadExact(file.file, replacement, size) || replacement->size != size ||
            replacement->numJoints > MAX_MD6_JOINTS ||
            replacement->numUserChannels > MAX_MD6_USER_CHANNELS) {
        _aligned_free(replacement);
        return false;
    }
    idStr conversionName;
    file->ReadString(conversionName);
    idHandle<unsigned short, invalidCrc_t, 65535> conversionChecksum;
    if (!ReadExact(file.file, &conversionChecksum, sizeof(conversionChecksum))) {
        _aligned_free(replacement);
        return false;
    }
    md6JointHandle_t* joints = reinterpret_cast<md6JointHandle_t*>(
        reinterpret_cast<unsigned char*>(replacement) +
            replacement->jointHandleTblOffset);
    for (int index = 0; index < Pad8(replacement->numJoints); ++index) {
        idStr jointName;
        file->ReadString(jointName);
        joints[index] = jointName.Length() == 0 || nameToJointHandleCallback == nullptr
            ? md6JointHandle_t() : nameToJointHandleCallback(jointName.c_str());
    }
    md6UserChannelHandle_t* users =
        reinterpret_cast<md6UserChannelHandle_t*>(
            reinterpret_cast<unsigned char*>(replacement) +
                replacement->userChannelHandleTblOffset);
    for (int index = 0; index < Pad8(replacement->numUserChannels); ++index) {
        idStr channelName;
        file->ReadString(channelName);
        users[index] = channelName.Length() == 0 || nameToUserHandleCallback == nullptr
            ? md6UserChannelHandle_t()
            : nameToUserHandleCallback(channelName.c_str());
    }
    float* channelDefaults = reinterpret_cast<float*>(
        reinterpret_cast<unsigned char*>(replacement) +
        replacement->basePoseOffset + 40 * Pad8(replacement->numJoints));
    if (!ReadExact(file.file, channelDefaults,
            Pad8(replacement->numUserChannels) * sizeof(float)) ||
            !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != MD6_SKEL_MAGIC) {
        _aligned_free(replacement);
        return false;
    }
    FreeData();
    data = replacement;
    timestamp = sourceTimestamp;
    jointConversion = conversionFindCallback != nullptr
        ? conversionFindCallback(conversionName.c_str())
        : idHandle<unsigned short, invalidJointConversionHandle_t, 65535>();
    jointConversionChecksum = conversionChecksum;
    return true;
}

bool idMD6Skel::WriteBinary(const char* fileName) const {
    if (fileName == nullptr || fileSystem == nullptr || data == nullptr)
        return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const unsigned int size = data->size;
    const char* conversionName = conversionNameCallback != nullptr
        ? conversionNameCallback(jointConversion) : "";
    if (!WriteExact(file.file, &MD6_SKEL_MAGIC, sizeof(MD6_SKEL_MAGIC)) ||
            !WriteExact(file.file, &timestamp, sizeof(timestamp)) ||
            !WriteExact(file.file, &size, sizeof(size)) ||
            !WriteExact(file.file, data, size) ||
            file->WriteString(conversionName != nullptr ? conversionName : "") == 0 ||
            !WriteExact(file.file, &jointConversionChecksum,
                sizeof(jointConversionChecksum))) return false;
    for (int index = 0; index < Pad8(data->numJoints); ++index) {
        const md6JointHandle_t handle = index < data->numJoints
            ? GetJointHandle(index) : md6JointHandle_t();
        const char* name = handle.IsValid() && jointHandleNameCallback != nullptr
            ? jointHandleNameCallback(handle) : "";
        file->WriteString(name != nullptr ? name : "");
    }
    for (int index = 0; index < Pad8(data->numUserChannels); ++index) {
        const md6UserChannelHandle_t handle = index < data->numUserChannels
            ? GetUserChannelHandle(index) : md6UserChannelHandle_t();
        const char* name = handle.IsValid() && userHandleNameCallback != nullptr
            ? userHandleNameCallback(handle) : "";
        file->WriteString(name != nullptr ? name : "");
    }
    return WriteExact(file.file, UserChannelDefaults(),
            Pad8(data->numUserChannels) * sizeof(float)) &&
        WriteExact(file.file, &MD6_SKEL_MAGIC, sizeof(MD6_SKEL_MAGIC));
}

bool idMD6Skel::Parse(idParser& parser) {
    idToken token;
    if (!parser.ReadToken(token) ||
            (idStr::Icmp(token.c_str(), "MD6_VERSION_STRING") != 0 &&
             idStr::Icmp(token.c_str(), "MD6") != 0)) {
        parser.Error("Invalid skeleton asset tag '%s'", token.c_str());
        return false;
    }
    const int version = parser.ParseInt();
    if (version != 1) {
        parser.Error("Invalid skeleton version %d. Should be version %d.",
            version, 1);
        return false;
    }
    if (!parser.ExpectTokenString("init") ||
            !parser.ExpectTokenString("{")) return false;

    int numJoints = 0;
    int numUserChannels = 0;
    idStr jointConversionName;
    idStr userChannelFile;
    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Icmp(token.c_str(), "commandLine") == 0 ||
                idStr::Icmp(token.c_str(), "sourceFile") == 0) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) return false;
        } else if (idStr::Icmp(token.c_str(), "numJoints") == 0) {
            numJoints = parser.ParseInt();
        } else if (idStr::Icmp(token.c_str(), "numUserChannels") == 0) {
            numUserChannels = parser.ParseInt();
        } else if (idStr::Icmp(token.c_str(), "jointconversion") == 0) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) return false;
            jointConversionName = token.c_str();
        } else if (idStr::Icmp(token.c_str(), "userChannelFile") == 0) {
            if (!parser.ExpectTokenType(TT_STRING, 0, token)) return false;
            userChannelFile = token.c_str();
        } else {
            parser.Error("Unknown token '%s' in 'init' section",
                token.c_str());
            return false;
        }
    }

    idParser externalUsers(LEXFL_NOSTRINGESCAPECHARS |
        LEXFL_NOSTRINGCONCAT | LEXFL_ALLOWPATHNAMES);
    idParser* userParser = &parser;
    if (!userChannelFile.IsEmpty()) {
        if (!externalUsers.LoadFile(userChannelFile.c_str(), false)) {
            parser.Error("UserChannels file not found %s",
                userChannelFile.c_str());
            return false;
        }
        if (!externalUsers.ReadToken(token) ||
                (idStr::Icmp(token.c_str(), "MD6_VERSION_STRING") != 0 &&
                 idStr::Icmp(token.c_str(), "MD6") != 0)) return false;
        const int userVersion = externalUsers.ParseInt();
        if (userVersion != 0 && userVersion != 2) {
            externalUsers.Error(
                "Invalid userchannel version %d. Should be version %d",
                userVersion, 2);
            return false;
        }
        if (!externalUsers.ExpectTokenString("numUserChannels"))
            return false;
        numUserChannels = externalUsers.ParseInt();
        userParser = &externalUsers;
    }
    if (numJoints < 0 || numJoints >= MAX_MD6_JOINTS ||
            numUserChannels < 0 || numUserChannels >= 256) {
        parser.Error("Invalid skeleton dimensions %d joints, %d user channels",
            numJoints, numUserChannels);
        return false;
    }

    const int paddedJoints = Pad8(numJoints);
    const int paddedUsers = Pad8(numUserChannels);
    std::vector<float> basePose(12 * paddedJoints, 0.0f);
    std::vector<md6JointHandle_t> jointHandles(paddedJoints);
    std::vector<short> parents(paddedJoints, -1);
    std::array<std::vector<unsigned char>, 8> jointWeights;
    std::array<bool, 8> jointWeightUsed{};
    for (int group = 0; group < 8; ++group)
        jointWeights[group].resize(paddedJoints, 0);
    for (int index = 0; index < paddedJoints; ++index) {
        basePose[index * 4 + 3] = 1.0f;
        basePose[4 * paddedJoints + index * 4 + 0] = 1.0f;
        basePose[4 * paddedJoints + index * 4 + 1] = 1.0f;
        basePose[4 * paddedJoints + index * 4 + 2] = 1.0f;
    }

    if (!parser.ExpectTokenString("joints") ||
            !parser.ExpectTokenString("{")) return false;
    for (int index = 0; index < numJoints; ++index) {
        if (!parser.ExpectTokenType(TT_STRING, 0, token)) return false;
        idStr jointName(token.c_str());
        jointName.MakeNameCanonical();
        jointHandles[index] = nameToJointHandleCallback != nullptr
            ? nameToJointHandleCallback(jointName.c_str())
            : md6JointHandle_t();
        const int parent = parser.ParseInt();
        if (parent < -1 || parent >= numJoints) {
            parser.Error("Invalid parent for joint '%s'", jointName.c_str());
            return false;
        }
        parents[index] = static_cast<short>(parent);
        float weights[8]{};
        if (!parser.Parse1DMatrix(8, weights)) return false;
        weights[0] = 1.0f;
        for (int group = 0; group < 8; ++group) {
            const int packed = static_cast<int>(weights[group] * 255.0f +
                0.5f);
            const unsigned char value = static_cast<unsigned char>(
                (std::max)(0, (std::min)(255, packed)));
            jointWeights[group][index] = value;
            jointWeightUsed[group] = jointWeightUsed[group] || value != 0;
        }
        if (!parser.Parse1DMatrix(4, &basePose[index * 4]) ||
                !parser.Parse1DMatrix(3, &basePose[
                    4 * paddedJoints + index * 4]) ||
                !parser.Parse1DMatrix(3, &basePose[
                    8 * paddedJoints + index * 4])) return false;
    }
    if (!parser.ExpectTokenString("}")) return false;

    std::vector<float> userDefaults(paddedUsers, 0.0f);
    std::vector<md6UserChannelHandle_t> userHandles(paddedUsers);
    std::array<std::vector<unsigned char>, 8> userWeights;
    std::array<bool, 8> userWeightUsed{};
    for (int group = 0; group < 8; ++group)
        userWeights[group].resize(paddedUsers, 0);
    if (userParser->CheckTokenString("userChannels") != 0) {
        if (!userParser->ExpectTokenString("{")) return false;
        for (int index = 0; index < numUserChannels; ++index) {
            if (!userParser->ExpectTokenType(TT_STRING, 0, token))
                return false;
            idStr channelName(token.c_str());
            channelName.MakeNameCanonical();
            userHandles[index] = nameToUserHandleCallback != nullptr
                ? nameToUserHandleCallback(channelName.c_str())
                : md6UserChannelHandle_t();
            float weights[8]{};
            if (!userParser->Parse1DMatrix(8, weights)) return false;
            for (int group = 0; group < 8; ++group) {
                const int packed = static_cast<int>(weights[group] *
                    255.0f + 0.5f);
                const unsigned char value = static_cast<unsigned char>(
                    (std::max)(0, (std::min)(255, packed)));
                userWeights[group][index] = value;
                userWeightUsed[group] = userWeightUsed[group] || value != 0;
            }
            userDefaults[index] = userParser->ParseFloat();
        }
        if (!userParser->ExpectTokenString("}")) return false;
    } else if (numUserChannels != 0) {
        userParser->Error("Missing userChannels block");
        return false;
    }

    const unsigned char* jointWeightPointers[8]{};
    const unsigned char* userWeightPointers[8]{};
    for (int group = 0; group < 8; ++group) {
        if (jointWeightUsed[group])
            jointWeightPointers[group] = jointWeights[group].data();
        if (userWeightUsed[group])
            userWeightPointers[group] = userWeights[group].data();
    }
    if (!MakeSkeletonData(numJoints, basePose.data(), jointHandles.data(),
            parents.data(), numUserChannels, userDefaults.data(),
            userHandles.data(), jointWeightPointers, userWeightPointers))
        return false;

    if (jointConversionName.IsEmpty()) {
        jointConversionName = GetName();
        jointConversionName.Append("_default.md6jointconversion");
    }
    jointConversion = conversionFindCallback != nullptr
        ? conversionFindCallback(jointConversionName.c_str())
        : idHandle<unsigned short, invalidJointConversionHandle_t, 65535>();
    jointConversionChecksum.Invalidate();
    return !parser.HadError() && !userParser->HadError();
}

bool idMD6Skel::LoadText(const char* fileName) {
    if (textLoadCallback != nullptr) return textLoadCallback(this, fileName);
    if (fileName == nullptr) return false;
    idParser parser(LEXFL_NOSTRINGESCAPECHARS | LEXFL_NOSTRINGCONCAT |
        LEXFL_ALLOWPATHNAMES);
    if (!parser.LoadFile(fileName, false) || !Parse(parser)) return false;
    timestamp = fileSystem != nullptr
        ? fileSystem->GetTimestamp(fileName, false) : ~0u;
    return true;
}

void idMD6Skel::LoadResource() {
    FreeData();
    if (fileSystem == nullptr) return;
    idStr binary = fileSystem->GeneratedPath(GetName());
    binary.SetFileExtension("bmd6skl");
    if (!LoadBinary(binary.c_str())) {
        if (!LoadText(GetName()))
            MakeSkeletonData(0, nullptr, nullptr, nullptr, 0, nullptr,
                nullptr, nullptr, nullptr);
        WriteBinary(binary.c_str());
    }
}

bool idMD6Skel::ReloadIfStale() {
    if (fileSystem == nullptr) return false;
    const unsigned int current = fileSystem->GetTimestamp(GetName(), false);
    if (current == timestamp) return false;
    LoadResource();
    return true;
}

idMD6SkeletonConfig::idMD6SkeletonConfig()
    : boundsDecl(nullptr) {
}

idResourceList* idMD6SkeletonConfig::GetResourceList() {
    return &resourceList;
}

bool idMD6SkeletonConfig::WriteSkeletonConfig_Binary(
        const char* fileName) const {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const int count = instances.Num();
    if (!WriteExact(file.file, &MD6_SKEL_CONFIG_MAGIC,
                sizeof(MD6_SKEL_CONFIG_MAGIC)) ||
            !WriteExact(file.file, &count, sizeof(count))) return false;
    for (int index = 0; index < count; ++index) {
        const instance_t& instance = instances[index];
        const char* skeletonName = instance.skeleton != nullptr
            ? instance.skeleton->GetName() : "";
        if (!WriteExact(file.file, &instance.timestamp,
                    sizeof(instance.timestamp)) ||
                file->WriteString(skeletonName != nullptr
                    ? skeletonName : "") == 0) return false;
    }
    const char* boundsName = boundsDecl != nullptr
        ? boundsDecl->GetName() : "";
    return file->WriteString(boundsName != nullptr ? boundsName : "") != 0;
}

bool idMD6SkeletonConfig::ReadSkeletonConfig_Binary(
        const char* fileName) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0;
    int count = 0;
    if (file.file == nullptr ||
            !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != MD6_SKEL_CONFIG_MAGIC ||
            !ReadExact(file.file, &count, sizeof(count)) ||
            count < 0 || count > 0x10000) return false;

    idList<instance_t, 5> loaded;
    loaded.SetNum(count);
    for (int index = 0; index < count; ++index) {
        idStr skeletonName;
        if (!ReadExact(file.file, &loaded[index].timestamp,
                    sizeof(loaded[index].timestamp))) return false;
        file->ReadString(skeletonName);
        loaded[index].skeleton = skeletonName.IsEmpty() ? nullptr
            : static_cast<const idMD6Skel*>(idMD6Skel::resourceList.Load(
                skeletonName.c_str(), true, false));
    }
    idStr boundsName;
    file->ReadString(boundsName);
    const idDeclMD6* loadedBounds = boundsName.IsEmpty() ? nullptr
        : static_cast<const idDeclMD6*>(idDeclMD6::resourceList.Load(
            boundsName.c_str(), true, false));
    instances = loaded;
    boundsDecl = loadedBounds;
    return true;
}

bool idMD6SkeletonConfig::LoadSkeletonConfig(const char* basePath) {
    if (basePath == nullptr || fileSystem == nullptr) return false;
    idFileList* files = fileSystem->ListFilesTree(basePath, "md6skl", true);
    if (files == nullptr) return false;

    idList<instance_t, 5> loaded;
    loaded.SetNum(files->GetNumFiles());
    for (int index = 0; index < files->GetNumFiles(); ++index) {
        const idMD6Skel* skeleton = static_cast<const idMD6Skel*>(
            idMD6Skel::resourceList.Load(files->GetFile(index), false,
                false));
        loaded[index].skeleton = skeleton;
        loaded[index].timestamp = skeleton != nullptr
            ? skeleton->timestamp : ~0u;
    }
    fileSystem->FreeFileList(files);

    const idDeclMD6* loadedBounds = nullptr;
    idStr configPath(basePath);
    configPath.Append("/.skeletonconfig");
    idParser parser(LEXFL_NOSTRINGESCAPECHARS | LEXFL_NOSTRINGCONCAT |
        LEXFL_ALLOWPATHNAMES);
    if (parser.LoadFile(configPath.c_str(), false)) {
        idToken header;
        if (!parser.ReadToken(header)) return false;
        const int version = parser.ParseInt();
        if (version != MD6_SKEL_CONFIG_VERSION) {
            parser.Error("Invalid skeleton config version %d. Should be version %d.",
                version, MD6_SKEL_CONFIG_VERSION);
            return false;
        }
        idToken boundsName;
        if (!parser.ExpectTokenType(TT_STRING, 0, boundsName)) return false;
        loadedBounds = static_cast<const idDeclMD6*>(
            idDeclMD6::resourceList.Load(boundsName.c_str(), true, false));
        if (loadedBounds == nullptr) {
            parser.Error("Skeleton config had invalid md6Decl %s.",
                boundsName.c_str());
            return false;
        }
    }
    instances = loaded;
    boundsDecl = loadedBounds;
    return true;
}

void idMD6SkeletonConfig::LoadResource() {
    instances.Clear();
    boundsDecl = nullptr;
    if (fileSystem == nullptr) return;
    idStr binary = fileSystem->GeneratedPath(GetName());
    binary.SetFileExtension("bmd6skeletonconfig");
    if (!ReadSkeletonConfig_Binary(binary.c_str()) &&
            LoadSkeletonConfig(GetName()))
        WriteSkeletonConfig_Binary(binary.c_str());
}

bool idMD6SkeletonConfig::ReloadIfStale() {
    if (fileSystem == nullptr) return false;
    idFileList* files = fileSystem->ListFilesTree(GetName(), "md6skl", true);
    bool stale = files == nullptr
        ? instances.Num() != 0
        : files->GetNumFiles() != instances.Num();
    if (files != nullptr && !stale) {
        for (int fileIndex = 0; fileIndex < files->GetNumFiles() && !stale;
                ++fileIndex) {
            const char* fileName = files->GetFile(fileIndex);
            bool found = false;
            for (int instanceIndex = 0; instanceIndex < instances.Num();
                    ++instanceIndex) {
                const instance_t& instance = instances[instanceIndex];
                if (instance.skeleton == nullptr ||
                        idStr::Icmp(instance.skeleton->GetName(),
                            fileName) != 0) continue;
                found = true;
                stale = fileSystem->GetTimestamp(fileName, false) !=
                    instance.timestamp;
                break;
            }
            if (!found) stale = true;
        }
    }
    if (files != nullptr) fileSystem->FreeFileList(files);
    if (!stale) return false;
    LoadResource();
    return true;
}
