#include "models/skeletalanimation/jobs/md6blend.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

namespace {

int Pad8(const int value) { return (value + 7) & ~7; }

const unsigned char* Bytes(const void* pointer) {
    return static_cast<const unsigned char*>(pointer);
}

unsigned char* Bytes(void* pointer) {
    return static_cast<unsigned char*>(pointer);
}

float* SkeletonFloats(const idMD6SkelData* skeleton,
        const unsigned int offset) {
    return reinterpret_cast<float*>(const_cast<unsigned char*>(
        Bytes(skeleton) + offset));
}

const short* ParentTable(const idMD6SkelData* skeleton) {
    return reinterpret_cast<const short*>(
        Bytes(skeleton) + skeleton->parentTblOffset);
}

struct Quat {
    float x, y, z, w;
};

Quat Normalize(const Quat& input) {
    const float length = std::sqrt(input.x * input.x + input.y * input.y +
        input.z * input.z + input.w * input.w);
    if (length <= 1.0e-30f) return { 0.0f, 0.0f, 0.0f, 1.0f };
    const float inverse = 1.0f / length;
    return { input.x * inverse, input.y * inverse, input.z * inverse,
        input.w * inverse };
}

Quat Multiply(const Quat& first, const Quat& second) {
    return Normalize({
        first.w * second.x + first.x * second.w + first.y * second.z -
            first.z * second.y,
        first.w * second.y - first.x * second.z + first.y * second.w +
            first.z * second.x,
        first.w * second.z + first.x * second.y - first.y * second.x +
            first.z * second.w,
        first.w * second.w - first.x * second.x - first.y * second.y -
            first.z * second.z
    });
}

Quat Inverse(const Quat& value) {
    return Normalize({ -value.x, -value.y, -value.z, value.w });
}

Quat LerpQuat(const Quat& first, Quat second, const float fraction) {
    const float dot = first.x * second.x + first.y * second.y +
        first.z * second.z + first.w * second.w;
    if (dot < 0.0f) {
        second.x = -second.x;
        second.y = -second.y;
        second.z = -second.z;
        second.w = -second.w;
    }
    return Normalize({
        first.x + (second.x - first.x) * fraction,
        first.y + (second.y - first.y) * fraction,
        first.z + (second.z - first.z) * fraction,
        first.w + (second.w - first.w) * fraction
    });
}

Quat MatrixQuat(const float* matrix) {
    const float trace = matrix[0] + matrix[5] + matrix[10];
    Quat result{};
    if (trace > 0.0f) {
        const float root = std::sqrt(trace + 1.0f);
        result.w = 0.5f * root;
        const float factor = 0.5f / root;
        result.x = (matrix[9] - matrix[6]) * factor;
        result.y = (matrix[2] - matrix[8]) * factor;
        result.z = (matrix[4] - matrix[1]) * factor;
    } else if (matrix[0] > matrix[5] && matrix[0] > matrix[10]) {
        const float root = std::sqrt((std::max)(0.0f,
            1.0f + matrix[0] - matrix[5] - matrix[10]));
        result.x = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.y = (matrix[1] + matrix[4]) * factor;
        result.z = (matrix[2] + matrix[8]) * factor;
        result.w = (matrix[9] - matrix[6]) * factor;
    } else if (matrix[5] > matrix[10]) {
        const float root = std::sqrt((std::max)(0.0f,
            1.0f + matrix[5] - matrix[0] - matrix[10]));
        result.y = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.x = (matrix[1] + matrix[4]) * factor;
        result.z = (matrix[6] + matrix[9]) * factor;
        result.w = (matrix[2] - matrix[8]) * factor;
    } else {
        const float root = std::sqrt((std::max)(0.0f,
            1.0f + matrix[10] - matrix[0] - matrix[5]));
        result.z = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.x = (matrix[2] + matrix[8]) * factor;
        result.y = (matrix[6] + matrix[9]) * factor;
        result.w = (matrix[4] - matrix[1]) * factor;
    }
    return Normalize(result);
}

void QuatMatrix(const Quat& input, const float* scale,
        const float* translation, float* matrix) {
    const Quat q = Normalize(input);
    const float xx = q.x * q.x, yy = q.y * q.y, zz = q.z * q.z;
    const float xy = q.x * q.y, xz = q.x * q.z, yz = q.y * q.z;
    const float wx = q.w * q.x, wy = q.w * q.y, wz = q.w * q.z;
    matrix[0] = (1.0f - 2.0f * (yy + zz)) * scale[0];
    matrix[1] = (2.0f * (xy - wz)) * scale[0];
    matrix[2] = (2.0f * (xz + wy)) * scale[0];
    matrix[3] = translation[0];
    matrix[4] = (2.0f * (xy + wz)) * scale[1];
    matrix[5] = (1.0f - 2.0f * (xx + zz)) * scale[1];
    matrix[6] = (2.0f * (yz - wx)) * scale[1];
    matrix[7] = translation[1];
    matrix[8] = (2.0f * (xz - wy)) * scale[2];
    matrix[9] = (2.0f * (yz + wx)) * scale[2];
    matrix[10] = (1.0f - 2.0f * (xx + yy)) * scale[2];
    matrix[11] = translation[2];
}

void MultiplyAffine(const float* left, const float* right, float* output) {
    float result[12];
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column)
            result[row * 4 + column] =
                left[row * 4 + 0] * right[column + 0] +
                left[row * 4 + 1] * right[column + 4] +
                left[row * 4 + 2] * right[column + 8];
        result[row * 4 + 3] = left[row * 4 + 0] * right[3] +
            left[row * 4 + 1] * right[7] +
            left[row * 4 + 2] * right[11] + left[row * 4 + 3];
    }
    std::memcpy(output, result, sizeof(result));
}

struct Pose {
    std::vector<float> rotations;
    std::vector<float> scales;
    std::vector<float> translations;
    std::vector<float> users;
    std::vector<std::uint8_t> jointWeights;
    std::vector<std::uint8_t> userWeights;
};

void SizePose(const idMD6SkelData* skeleton, Pose& pose) {
    const int joints = Pad8(skeleton->numJoints);
    const int users = Pad8(skeleton->numUserChannels);
    pose.rotations.resize(joints * 4);
    pose.scales.resize(joints * 4);
    pose.translations.resize(joints * 4);
    pose.users.resize(users);
    pose.jointWeights.assign(joints, 255);
    pose.userWeights.assign(users, 255);
}

void BasePose(const idMD6SkelData* skeleton, Pose& pose,
        const bool additive) {
    SizePose(skeleton, pose);
    const int joints = Pad8(skeleton->numJoints);
    const int users = Pad8(skeleton->numUserChannels);
    const float* rotations = SkeletonFloats(skeleton,
        skeleton->basePoseOffset);
    const float* scales = rotations + joints * 4;
    const float* translations = rotations + joints * 7;
    const float* userDefaults = rotations + joints * 10;
    for (int joint = 0; joint < joints; ++joint) {
        if (additive) {
            pose.rotations[joint * 4 + 0] = 0.0f;
            pose.rotations[joint * 4 + 1] = 0.0f;
            pose.rotations[joint * 4 + 2] = 0.0f;
            pose.rotations[joint * 4 + 3] = 1.0f;
            pose.scales[joint * 4 + 0] = 1.0f;
            pose.scales[joint * 4 + 1] = 1.0f;
            pose.scales[joint * 4 + 2] = 1.0f;
            pose.translations[joint * 4 + 0] = 0.0f;
            pose.translations[joint * 4 + 1] = 0.0f;
            pose.translations[joint * 4 + 2] = 0.0f;
        } else {
            std::memcpy(&pose.rotations[joint * 4], rotations + joint * 4,
                4 * sizeof(float));
            std::memcpy(&pose.scales[joint * 4], scales + joint * 3,
                3 * sizeof(float));
            std::memcpy(&pose.translations[joint * 4],
                translations + joint * 3, 3 * sizeof(float));
        }
        pose.scales[joint * 4 + 3] = 1.0f;
        pose.translations[joint * 4 + 3] = 0.0f;
    }
    for (int channel = 0; channel < users; ++channel)
        pose.users[channel] = additive ? 0.0f : userDefaults[channel];
}

const std::uint16_t* AnimationMapCrcs(const idMD6AnimData* animation) {
    return reinterpret_cast<const std::uint16_t*>(animation + 1) + 1;
}

const std::uint16_t* AnimationMapOffsets(const idMD6AnimData* animation) {
    return AnimationMapCrcs(animation) + animation->numAnimMaps;
}

const frameSetData_t* FrameSetForFrame(const idMD6AnimData* animation,
        int frame, int& localFrame) {
    if (animation->numFrameSets == 0 ||
            animation->frameSetTblOffset >= animation->totalSize ||
            static_cast<unsigned int>(animation->frameSetOffsetTblOffset) +
                (static_cast<unsigned int>(animation->numFrameSets) + 1u) *
                    sizeof(std::uint32_t) > animation->totalSize)
        return nullptr;
    frame = (std::max)(0, (std::min)(frame,
        static_cast<int>(animation->numFrames) - 1));
    const unsigned char* base = Bytes(animation);
    const std::uint32_t* offsets = reinterpret_cast<const std::uint32_t*>(
        base + animation->frameSetOffsetTblOffset);
    int setIndex = 0;
    if (animation->numFrameSets > 1) {
        const std::uint8_t* table = base + animation->frameSetTblOffset;
        setIndex = (std::min)(static_cast<int>(animation->numFrameSets) - 1,
            static_cast<int>(table[frame]));
    }
    const std::uint32_t setOffset = offsets[setIndex] * 16u;
    if (setOffset > animation->totalSize ||
            animation->totalSize - setOffset < sizeof(frameSetData_t))
        return nullptr;
    const frameSetData_t* result = reinterpret_cast<const frameSetData_t*>(
        base + setOffset);
    localFrame = frame - result->frameStart;
    return result;
}

bool FrameBit(const std::uint8_t* bits, const int bytesPerChannel,
        const int channel, const int frame) {
    const std::uint8_t value = bits[channel * bytesPerChannel + frame / 8];
    return (value & (1u << (frame & 7))) != 0;
}

template<typename Type>
void AnimatedTriples(const std::uint8_t* channels, const int channelCount,
        const int frame, const int numFrames, const float fraction,
        const Type* firstKeys, const Type* nextKeys,
        const std::uint8_t* frameBits, float* output, const int outputStride,
        const float valueScale) {
    const int bytesPerChannel = (numFrames + 7) / 8;
    int nextCursor = 0;
    for (int channel = 0; channel < channelCount; ++channel) {
        int leftFrame = 0, rightFrame = numFrames > 1 ? numFrames - 1 : 0;
        int leftKey = -1, rightKey = -1;
        int keyAtFrame = -1;
        for (int scan = 1; scan < numFrames; ++scan) {
            if (!FrameBit(frameBits, bytesPerChannel, channel, scan)) continue;
            ++keyAtFrame;
            if (scan <= frame) {
                leftFrame = scan;
                leftKey = nextCursor + keyAtFrame;
            } else if (rightKey < 0) {
                rightFrame = scan;
                rightKey = nextCursor + keyAtFrame;
            }
        }
        const int keysForChannel = keyAtFrame + 1;
        const Type* left = leftKey < 0 ? firstKeys + channel * 3
            : nextKeys + leftKey * 3;
        const Type* right = rightKey < 0 ? left : nextKeys + rightKey * 3;
        float interpolation = fraction;
        if (rightFrame > leftFrame)
            interpolation = (static_cast<float>(frame - leftFrame) +
                fraction) / static_cast<float>(rightFrame - leftFrame);
        interpolation = (std::max)(0.0f, (std::min)(1.0f, interpolation));
        const int target = channels[channel] * outputStride;
        for (int component = 0; component < 3; ++component) {
            const float a = static_cast<float>(left[component]) * valueScale;
            const float b = static_cast<float>(right[component]) * valueScale;
            output[target + component] = a + (b - a) * interpolation;
        }
        nextCursor += keysForChannel;
    }
}

void AnimatedScalars(const std::uint8_t* channels, const int channelCount,
        const int frame, const int numFrames, const float fraction,
        const float* firstKeys, const float* nextKeys,
        const std::uint8_t* frameBits, float* output) {
    const int bytesPerChannel = (numFrames + 7) / 8;
    int nextCursor = 0;
    for (int channel = 0; channel < channelCount; ++channel) {
        int leftFrame = 0;
        int rightFrame = numFrames > 1 ? numFrames - 1 : 0;
        int leftKey = -1;
        int rightKey = -1;
        int keyAtFrame = -1;
        for (int scan = 1; scan < numFrames; ++scan) {
            if (!FrameBit(frameBits, bytesPerChannel, channel, scan))
                continue;
            ++keyAtFrame;
            if (scan <= frame) {
                leftFrame = scan;
                leftKey = nextCursor + keyAtFrame;
            } else if (rightKey < 0) {
                rightFrame = scan;
                rightKey = nextCursor + keyAtFrame;
            }
        }
        const int keysForChannel = keyAtFrame + 1;
        const float left = leftKey < 0 ? firstKeys[channel]
            : nextKeys[leftKey];
        const float right = rightKey < 0 ? left : nextKeys[rightKey];
        float interpolation = fraction;
        if (rightFrame > leftFrame) {
            interpolation = (static_cast<float>(frame - leftFrame) +
                fraction) / static_cast<float>(rightFrame - leftFrame);
        }
        interpolation = (std::max)(0.0f,
            (std::min)(1.0f, interpolation));
        output[channels[channel]] = left +
            (right - left) * interpolation;
        nextCursor += keysForChannel;
    }
}

void AnimatedRotations(const std::uint8_t* channels, const int channelCount,
        const int frame, const int numFrames, const float fraction,
        const std::int16_t* firstKeys, const std::int16_t* nextKeys,
        const std::uint8_t* frameBits, float* output) {
    std::vector<float> xyz(Pad8(channelCount) * 4, 0.0f);
    std::vector<std::uint8_t> sequential(Pad8(channelCount), 0);
    for (int index = 0; index < channelCount; ++index)
        sequential[index] = static_cast<std::uint8_t>(index);
    AnimatedTriples(sequential.data(), channelCount, frame, numFrames, fraction,
        firstKeys, nextKeys, frameBits, xyz.data(), 4, 1.0f / 32767.0f);
    for (int index = 0; index < channelCount; ++index) {
        const int target = channels[index] * 4;
        const float x = xyz[index * 4 + 0];
        const float y = xyz[index * 4 + 1];
        const float z = xyz[index * 4 + 2];
        const float w = std::sqrt((std::max)(0.0f,
            1.0f - x * x - y * y - z * z));
        output[target + 0] = x;
        output[target + 1] = y;
        output[target + 2] = z;
        output[target + 3] = w;
    }
}

void DecodePose(const idMD6SkelData* skeleton,
        const idMD6AnimData* animation, const int frame,
        const float frameFraction, Pose& pose) {
    const bool additive = (animation->flags &
        (idMD6AnimData::ANIM_FLAG_ADDITIVE |
         idMD6AnimData::ANIM_FLAG_RETARGET_ADDITIVE)) != 0;
    BasePose(skeleton, pose, additive);
    const int paddedJoints = Pad8(skeleton->numJoints);
    const int paddedUsers = Pad8(skeleton->numUserChannels);
    if ((animation->flags & idMD6AnimData::ANIM_FLAG_HAS_JOINT_DATA) == 0 &&
            (animation->flags &
                idMD6AnimData::ANIM_FLAG_HAS_USER_CHANNEL_DATA) == 0)
        return;
    const unsigned int mapsEnd = sizeof(idMD6AnimData) + 2u +
        static_cast<unsigned int>(animation->numAnimMaps) *
            (sizeof(std::uint16_t) + 8u * sizeof(std::uint16_t));
    if (animation->numAnimMaps == 0 || mapsEnd > animation->totalSize)
        return;
    int map = idMD6Blend::GetAnimMapIndex(animation,
        skeleton->parentTblCrc);
    if (map < 0) map = 0;
    const std::uint16_t* offsets = AnimationMapOffsets(animation) + map * 8;
    std::uint8_t rotationChannels[264]{}, scaleChannels[264]{},
        translationChannels[264]{}, userChannels[2056]{};
    const unsigned char* base = Bytes(animation);
    const int constR = idMD6Blend::DecodeRLE(base + offsets[0],
        static_cast<std::uint16_t>(paddedJoints), rotationChannels);
    const int constS = idMD6Blend::DecodeRLE(base + offsets[1],
        static_cast<std::uint16_t>(paddedJoints), scaleChannels);
    const int constT = idMD6Blend::DecodeRLE(base + offsets[2],
        static_cast<std::uint16_t>(paddedJoints), translationChannels);
    const int constU = paddedUsers > 0 ? idMD6Blend::DecodeRLE(
        base + offsets[3], static_cast<std::uint16_t>(paddedUsers),
        userChannels) : 0;
    const std::int16_t* constantRotations =
        reinterpret_cast<const std::int16_t*>(base + animation->constROffset);
    for (int index = 0; index < constR; ++index) {
        const int joint = rotationChannels[index];
        const float x = constantRotations[index * 3 + 0] / 32767.0f;
        const float y = constantRotations[index * 3 + 1] / 32767.0f;
        const float z = constantRotations[index * 3 + 2] / 32767.0f;
        pose.rotations[joint * 4 + 0] = x;
        pose.rotations[joint * 4 + 1] = y;
        pose.rotations[joint * 4 + 2] = z;
        pose.rotations[joint * 4 + 3] = std::sqrt((std::max)(0.0f,
            1.0f - x * x - y * y - z * z));
    }
    const float* constantScales = reinterpret_cast<const float*>(
        base + animation->constSOffset);
    const float* constantTranslations = reinterpret_cast<const float*>(
        base + animation->constTOffset);
    const float* constantUsers = reinterpret_cast<const float*>(
        base + animation->constUOffset);
    for (int index = 0; index < constS; ++index)
        std::memcpy(&pose.scales[scaleChannels[index] * 4],
            constantScales + index * 3, 3 * sizeof(float));
    for (int index = 0; index < constT; ++index)
        std::memcpy(&pose.translations[translationChannels[index] * 4],
            constantTranslations + index * 3, 3 * sizeof(float));
    for (int index = 0; index < constU; ++index)
        pose.users[userChannels[index]] = constantUsers[index];

    int localFrame = 0;
    const frameSetData_t* set = FrameSetForFrame(animation, frame, localFrame);
    if (set == nullptr) return;
    const int animR = idMD6Blend::DecodeRLE(base + offsets[4],
        static_cast<std::uint16_t>(paddedJoints), rotationChannels);
    const int animS = idMD6Blend::DecodeRLE(base + offsets[5],
        static_cast<std::uint16_t>(paddedJoints), scaleChannels);
    const int animT = idMD6Blend::DecodeRLE(base + offsets[6],
        static_cast<std::uint16_t>(paddedJoints), translationChannels);
    const int animU = paddedUsers > 0 ? idMD6Blend::DecodeRLE(
        base + offsets[7], static_cast<std::uint16_t>(paddedUsers),
        userChannels) : 0;
    const unsigned char* setBase = reinterpret_cast<const unsigned char*>(set);
    AnimatedRotations(rotationChannels, animR, localFrame, set->frameRange,
        frameFraction, reinterpret_cast<const std::int16_t*>(
            setBase + set->firstROffset),
        reinterpret_cast<const std::int16_t*>(setBase + set->nextROffset),
        setBase + set->RBitsOffset, pose.rotations.data());
    AnimatedTriples(scaleChannels, animS, localFrame, set->frameRange,
        frameFraction, reinterpret_cast<const float*>(setBase +
            set->firstSOffset), reinterpret_cast<const float*>(setBase +
            set->nextSOffset), setBase + set->SBitsOffset,
        pose.scales.data(), 4, 1.0f);
    AnimatedTriples(translationChannels, animT, localFrame, set->frameRange,
        frameFraction, reinterpret_cast<const float*>(setBase +
            set->firstTOffset), reinterpret_cast<const float*>(setBase +
            set->nextTOffset), setBase + set->TBitsOffset,
        pose.translations.data(), 4, 1.0f);
    if (animU > 0) {
        const float* first = reinterpret_cast<const float*>(
            setBase + set->firstUOffset);
        AnimatedScalars(userChannels, animU, localFrame, set->frameRange,
            frameFraction, first,
            reinterpret_cast<const float*>(setBase + set->nextUOffset),
            setBase + set->UBitsOffset, pose.users.data());
    }
}

void ApplyModifiers(const idMD6SkelData* skeleton, Pose& pose,
        const idMD6Blend::jointMod_t* modifiers,
        const unsigned int numModifiers) {
    if (modifiers == nullptr) return;
    for (unsigned int index = 0; index < numModifiers; ++index) {
        const idMD6Blend::jointMod_t& modifier = modifiers[index];
        const int target = modifier.joint.Get();
        if (target < 0) continue;
        if ((modifier.flags & idMD6Blend::DRIVER_USERCHANNEL) != 0) {
            if (target < skeleton->numUserChannels)
                pose.users[target] = modifier.mat[0];
            continue;
        }
        if (target >= skeleton->numJoints) continue;
        const bool overrideValue =
            (modifier.flags & idMD6Blend::DRIVER_OVERRIDE) != 0;
        if ((modifier.flags & idMD6Blend::DRIVER_ROTATION) != 0) {
            const Quat value = MatrixQuat(modifier.mat);
            Quat current{ pose.rotations[target * 4 + 0],
                pose.rotations[target * 4 + 1],
                pose.rotations[target * 4 + 2],
                pose.rotations[target * 4 + 3] };
            const Quat result = overrideValue ? value : Multiply(current, value);
            std::memcpy(&pose.rotations[target * 4], &result, 4 * sizeof(float));
        }
        if ((modifier.flags & idMD6Blend::DRIVER_SCALE) != 0) {
            for (int component = 0; component < 3; ++component)
                pose.scales[target * 4 + component] = overrideValue
                    ? modifier.s[component]
                    : pose.scales[target * 4 + component] *
                        modifier.s[component];
        }
        if ((modifier.flags & idMD6Blend::DRIVER_TRANSLATION) != 0) {
            const float translation[3] = {
                modifier.mat[3], modifier.mat[7], modifier.mat[11] };
            for (int component = 0; component < 3; ++component)
                pose.translations[target * 4 + component] = overrideValue
                    ? translation[component]
                    : pose.translations[target * 4 + component] +
                        translation[component];
        }
    }
}

float FilterAlpha(const idMD6SkelData* skeleton, const int group,
        const int index, const float alpha, const bool userChannel) {
    if (group < 0 || group >= 8) return alpha;
    const std::uint16_t offset = userChannel
        ? skeleton->userWeightOffsets[group]
        : skeleton->jointWeightOffsets[group];
    return offset == 0 ? alpha : alpha *
        static_cast<float>(Bytes(skeleton)[offset + index]) / 255.0f;
}

void BlendPoses(const idMD6SkelData* skeleton, const Pose& first,
        const Pose& second, const md6BlendInfo_t& info, Pose& output) {
    SizePose(skeleton, output);
    const int joints = Pad8(skeleton->numJoints);
    const int users = Pad8(skeleton->numUserChannels);
    for (int joint = 0; joint < joints; ++joint) {
        const float alpha = FilterAlpha(skeleton, info.filterGroup, joint,
            info.currentAlpha, false);
        const Quat a{ first.rotations[joint * 4 + 0],
            first.rotations[joint * 4 + 1], first.rotations[joint * 4 + 2],
            first.rotations[joint * 4 + 3] };
        const Quat b{ second.rotations[joint * 4 + 0],
            second.rotations[joint * 4 + 1], second.rotations[joint * 4 + 2],
            second.rotations[joint * 4 + 3] };
        Quat rotation;
        if (info.op == idMD6Blend::BOP_ADD_LEFT ||
                info.op == idMD6Blend::BOP_ADD_RIGHT) {
            const Quat delta = LerpQuat({0.0f, 0.0f, 0.0f, 1.0f}, b, alpha);
            rotation = Multiply(a, delta);
        } else if (info.op == idMD6Blend::BOP_SUB_LEFT ||
                info.op == idMD6Blend::BOP_SUB_RIGHT) {
            const Quat delta = LerpQuat({0.0f, 0.0f, 0.0f, 1.0f},
                Inverse(b), alpha);
            rotation = Multiply(a, delta);
        } else {
            rotation = LerpQuat(a, b, alpha);
        }
        std::memcpy(&output.rotations[joint * 4], &rotation,
            4 * sizeof(float));
        for (int component = 0; component < 3; ++component) {
            const int element = joint * 4 + component;
            if (info.op == idMD6Blend::BOP_ADD_LEFT ||
                    info.op == idMD6Blend::BOP_ADD_RIGHT) {
                output.scales[element] = first.scales[element] +
                    (second.scales[element] - 1.0f) * alpha;
                output.translations[element] = first.translations[element] +
                    second.translations[element] * alpha;
            } else if (info.op == idMD6Blend::BOP_SUB_LEFT ||
                    info.op == idMD6Blend::BOP_SUB_RIGHT) {
                output.scales[element] = first.scales[element] -
                    (second.scales[element] - 1.0f) * alpha;
                output.translations[element] = first.translations[element] -
                    second.translations[element] * alpha;
            } else {
                output.scales[element] = first.scales[element] +
                    (second.scales[element] - first.scales[element]) * alpha;
                output.translations[element] = first.translations[element] +
                    (second.translations[element] -
                        first.translations[element]) * alpha;
            }
        }
        output.scales[joint * 4 + 3] = 1.0f;
        output.translations[joint * 4 + 3] = 0.0f;
    }
    for (int channel = 0; channel < users; ++channel) {
        const float alpha = FilterAlpha(skeleton, info.filterGroup, channel,
            info.currentAlpha, true);
        output.users[channel] = first.users[channel] +
            (second.users[channel] - first.users[channel]) * alpha;
    }
}

void FrameFromInfo(const idMD6SkelData* skeleton,
        const md6FrameInfo_t& info, Pose& pose) {
    if (info.animData == nullptr) {
        BasePose(skeleton, pose, false);
        return;
    }
    DecodePose(skeleton, info.animData, info.frame,
        info.frameFraction, pose);
    ApplyModifiers(skeleton, pose, info.animMods,
        info.animModsSize / sizeof(idMD6Blend::jointMod_t));
}

} // namespace

int idMD6Blend::GetAnimMapIndex(const idMD6AnimData* animation,
        const idHandle<unsigned short, invalidCrc_t, 65535> parentTableCrc) {
    if (animation == nullptr || animation->numAnimMaps == 0 ||
            sizeof(idMD6AnimData) + 2u +
                static_cast<unsigned int>(animation->numAnimMaps) *
                    sizeof(std::uint16_t) > animation->totalSize)
        return -1;
    const std::uint16_t* maps = AnimationMapCrcs(animation);
    for (int index = 0; index < animation->numAnimMaps; ++index)
        if (maps[index] == parentTableCrc.Get()) return index;
    return -1;
}

unsigned int idMD6Blend::DecodeRLE(const std::uint8_t* encoded,
        const std::uint16_t sentinel, std::uint8_t* indices) {
    if (encoded == nullptr || indices == nullptr) return 0;
    const unsigned int count = (std::min)(static_cast<unsigned int>(encoded[0]),
        static_cast<unsigned int>((std::min)(sentinel,
            static_cast<std::uint16_t>(255))));
    unsigned int output = 0, cursor = 1;
    while (output < count) {
        const std::uint8_t command = encoded[cursor++];
        const unsigned int run = command & 0x7Fu;
        if ((command & 0x80u) != 0) {
            for (unsigned int index = 0; index < run && output < count; ++index)
                indices[output++] = static_cast<std::uint8_t>(sentinel);
        } else {
            std::uint8_t value = encoded[cursor++];
            for (unsigned int index = 0; index < run && output < count; ++index)
                indices[output++] = value < sentinel ? value++
                    : static_cast<std::uint8_t>(sentinel);
        }
    }
    const unsigned int padded = (count + 7u) & ~7u;
    while (output < padded)
        indices[output++] = static_cast<std::uint8_t>(sentinel);
    return count;
}

void idMD6Blend::DecodeUserChannelsForAnimFrame(
        const idMD6SkelData* skeleton, const idMD6AnimData* animation,
        const float frame, float* output, const unsigned int outputBytes) {
    if (skeleton == nullptr || animation == nullptr || output == nullptr ||
            outputBytes < skeleton->numUserChannels * sizeof(float)) return;
    Pose pose;
    const int integralFrame = static_cast<int>(std::floor(frame));
    DecodePose(skeleton, animation, integralFrame,
        frame - integralFrame, pose);
    std::memcpy(output, pose.users.data(),
        skeleton->numUserChannels * sizeof(float));
}

void idMD6Blend::TransformLocalJointsToModelMatrices(
        const idMD6SkelData* skeleton, void*, unsigned int,
        const jointMod_t* modifiers, const unsigned int numModifiers,
        const float* originOffset, const bool addOffset,
        const float* rotations, const float* scales, const float* translations,
        float* outputMatrices, float*) {
    if (skeleton == nullptr || rotations == nullptr || scales == nullptr ||
            translations == nullptr || outputMatrices == nullptr) return;
    Pose pose;
    SizePose(skeleton, pose);
    std::memcpy(pose.rotations.data(), rotations,
        Pad8(skeleton->numJoints) * 4 * sizeof(float));
    std::memcpy(pose.scales.data(), scales,
        Pad8(skeleton->numJoints) * 4 * sizeof(float));
    std::memcpy(pose.translations.data(), translations,
        Pad8(skeleton->numJoints) * 4 * sizeof(float));
    ApplyModifiers(skeleton, pose, modifiers, numModifiers);
    const short* parents = ParentTable(skeleton);
    for (int joint = 0; joint < skeleton->numJoints; ++joint) {
        float local[12];
        const Quat rotation{ pose.rotations[joint * 4 + 0],
            pose.rotations[joint * 4 + 1], pose.rotations[joint * 4 + 2],
            pose.rotations[joint * 4 + 3] };
        float translation[3] = { pose.translations[joint * 4 + 0],
            pose.translations[joint * 4 + 1],
            pose.translations[joint * 4 + 2] };
        if (joint == 0 && originOffset != nullptr) {
            for (int component = 0; component < 3; ++component)
                translation[component] = addOffset
                    ? translation[component] + originOffset[component]
                    : originOffset[component];
        }
        QuatMatrix(rotation, &pose.scales[joint * 4], translation, local);
        if (parents[joint] >= 0 && parents[joint] < joint)
            MultiplyAffine(outputMatrices + parents[joint] * 12, local,
                outputMatrices + joint * 12);
        else
            std::memcpy(outputMatrices + joint * 12, local, sizeof(local));
    }
}

void idMD6Blend::DecodeBasePose(const idMD6SkelData* skeleton, void* temp,
        const unsigned int tempSize, const float* originOffset,
        const bool addOffset, float* outputMatrices) {
    if (skeleton == nullptr || outputMatrices == nullptr) return;
    Pose pose;
    BasePose(skeleton, pose, false);
    TransformLocalJointsToModelMatrices(skeleton, temp, tempSize, nullptr, 0,
        originOffset, addOffset, pose.rotations.data(), pose.scales.data(),
        pose.translations.data(), outputMatrices, nullptr);
}

void idMD6Blend::DecodeSingleFrame(const idMD6SkelData* skeleton, void* temp,
        const unsigned int tempSize, const idMD6AnimData* animation,
        const int frame, const int ticksPerSecond,
        const bool clearOriginTransform, const float* originOffset,
        const bool addOffset, float* outputMatrices,
        float* outputUserChannels) {
    if (skeleton == nullptr || animation == nullptr) return;
    const float animationFrame = ticksPerSecond > 0
        ? static_cast<float>(frame) * animation->frameRate /
            static_cast<float>(ticksPerSecond)
        : static_cast<float>(frame);
    const int firstFrame = static_cast<int>(std::floor(animationFrame));
    Pose pose;
    DecodePose(skeleton, animation, firstFrame,
        animationFrame - firstFrame, pose);
    if (clearOriginTransform && skeleton->numJoints > 0) {
        pose.rotations[0] = pose.rotations[1] = pose.rotations[2] = 0.0f;
        pose.rotations[3] = 1.0f;
        pose.translations[0] = pose.translations[1] =
            pose.translations[2] = 0.0f;
    }
    TransformLocalJointsToModelMatrices(skeleton, temp, tempSize, nullptr, 0,
        originOffset, addOffset, pose.rotations.data(), pose.scales.data(),
        pose.translations.data(), outputMatrices, nullptr);
    if (outputUserChannels != nullptr)
        std::memcpy(outputUserChannels, pose.users.data(),
            skeleton->numUserChannels * sizeof(float));
}

void idMD6Blend::DecodeSingleFrameWithOriginDeltaScale(
        const idMD6SkelData* skeleton, void* temp, const unsigned int tempSize,
        const idMD6AnimData* animation, const int frame,
        const int ticksPerSecond, const bool clearOriginTransform,
        const float* originOffset, const bool addOffset, float* outputMatrices,
        float* outputUserChannels, const float* originDeltaScale) {
    DecodeSingleFrame(skeleton, temp, tempSize, animation, frame,
        ticksPerSecond, clearOriginTransform, originOffset, addOffset,
        outputMatrices, outputUserChannels);
    if (outputMatrices != nullptr && originDeltaScale != nullptr) {
        outputMatrices[3] *= originDeltaScale[0];
        outputMatrices[7] *= originDeltaScale[1];
        outputMatrices[11] *= originDeltaScale[2];
    }
}

void idMD6Blend::TransformModelMatrices(const idMD6SkelData* skeleton,
        const std::uint8_t* remap, const float* inputMatrices,
        const float* inverseMatrices, const float*, float* outputMatrices,
        const bool, float*) {
    if (skeleton == nullptr || inputMatrices == nullptr ||
            outputMatrices == nullptr) return;
    if (inverseMatrices == nullptr)
        inverseMatrices = reinterpret_cast<const float*>(Bytes(skeleton) +
            skeleton->inverseBasePoseOffset);
    for (int joint = 0; joint < skeleton->numJoints; ++joint) {
        const int destination = remap != nullptr ? remap[joint] : joint;
        MultiplyAffine(inputMatrices + joint * 12,
            inverseMatrices + joint * 12, outputMatrices + destination * 12);
    }
}

void idMD6Blend::CalculatePoseBounds(const idMD6SkelData* skeleton,
        const float* finalPose,
        const idIndex<short, invalidJointIndex_t> boundsSkipJoint,
        md6OriginDelta_t* originDelta) {
    if (skeleton == nullptr || finalPose == nullptr || originDelta == nullptr)
        return;
    originDelta->jointBounds[0] = originDelta->jointBounds[1] =
        originDelta->jointBounds[2] = 1.0e30f;
    originDelta->jointBounds[3] = originDelta->jointBounds[4] =
        originDelta->jointBounds[5] = -1.0e30f;
    for (int joint = 0; joint < skeleton->numJoints; ++joint) {
        if (boundsSkipJoint.IsValid() && joint == boundsSkipJoint.Get())
            continue;
        const float* matrix = finalPose + joint * 12;
        for (int component = 0; component < 3; ++component) {
            const float value = matrix[component * 4 + 3];
            originDelta->jointBounds[component] = (std::min)(
                originDelta->jointBounds[component], value);
            originDelta->jointBounds[component + 3] = (std::max)(
                originDelta->jointBounds[component + 3], value);
        }
    }
}

void idMD6Blend::ExecuteCommandsToRSTU(const blendParms_t& parameters,
        void*, unsigned int, float* rotations, float* scales,
        float* translations, float* userChannels) {
    if (parameters.skeleton == nullptr || rotations == nullptr ||
            scales == nullptr || translations == nullptr) return;
    std::vector<Pose> stack;
    for (unsigned int commandIndex = 0; commandIndex < parameters.numCmds;
            ++commandIndex) {
        const md6AnimCommand_t& command = parameters.cmds[commandIndex];
        if (command.op == md6AnimCommand_t::OP_END) break;
        if (command.op == md6AnimCommand_t::OP_DECODE_AND_PUSH ||
                command.op ==
                    md6AnimCommand_t::OP_DECODE_FACECOMPOSITE_AND_BLEND) {
            Pose pose;
            FrameFromInfo(parameters.skeleton, command.frameInfo, pose);
            if (command.op ==
                    md6AnimCommand_t::OP_DECODE_FACECOMPOSITE_AND_BLEND &&
                    !stack.empty()) {
                Pose blended;
                BlendPoses(parameters.skeleton, stack.back(), pose,
                    command.blendInfo, blended);
                stack.back() = blended;
            } else {
                stack.push_back(pose);
            }
        } else if (command.op == md6AnimCommand_t::OP_POP_AND_BLEND &&
                stack.size() >= 2) {
            Pose second = stack.back();
            stack.pop_back();
            Pose first = stack.back();
            stack.pop_back();
            Pose blended;
            BlendPoses(parameters.skeleton, first, second,
                command.blendInfo, blended);
            stack.push_back(blended);
        }
    }
    Pose result;
    if (stack.empty()) BasePose(parameters.skeleton, result, false);
    else result = stack.back();
    ApplyModifiers(parameters.skeleton, result, parameters.mods,
        parameters.numMods);
    std::memcpy(rotations, result.rotations.data(),
        Pad8(parameters.skeleton->numJoints) * 4 * sizeof(float));
    std::memcpy(scales, result.scales.data(),
        Pad8(parameters.skeleton->numJoints) * 4 * sizeof(float));
    std::memcpy(translations, result.translations.data(),
        Pad8(parameters.skeleton->numJoints) * 4 * sizeof(float));
    if (userChannels != nullptr)
        std::memcpy(userChannels, result.users.data(),
            Pad8(parameters.skeleton->numUserChannels) * sizeof(float));
}

void idMD6Blend::ExecuteCommands(const blendParms_t& parameters, void* temp,
        const unsigned int tempSize, const bool useDualQuaternion) {
    if (parameters.skeleton == nullptr) return;
    const int paddedJoints = Pad8(parameters.skeleton->numJoints);
    const int paddedUsers = Pad8(parameters.skeleton->numUserChannels);
    std::vector<float> rotations(paddedJoints * 4);
    std::vector<float> scales(paddedJoints * 4);
    std::vector<float> translations(paddedJoints * 4);
    std::vector<float> users(paddedUsers);
    ExecuteCommandsToRSTU(parameters, temp, tempSize, rotations.data(),
        scales.data(), translations.data(), users.data());
    std::vector<float> modelMatrices(parameters.skeleton->numJoints * 12);
    const float* origin = parameters.config != nullptr
        ? parameters.config->visualOffset : nullptr;
    TransformLocalJointsToModelMatrices(parameters.skeleton, temp, tempSize,
        parameters.mods, parameters.numMods, origin, true, rotations.data(),
        scales.data(), translations.data(), modelMatrices.data(), nullptr);
    if (parameters.referencePose != nullptr)
        std::memcpy(parameters.referencePose, modelMatrices.data(),
            parameters.skeleton->numJoints * 12 * sizeof(float));
    if (parameters.finalPose != nullptr)
        std::memcpy(parameters.finalPose, modelMatrices.data(),
            parameters.skeleton->numJoints * 12 * sizeof(float));
    if (parameters.renderPose != nullptr)
        TransformModelMatrices(parameters.skeleton, parameters.jointRemap,
            modelMatrices.data(), parameters.invertedBasePose,
            parameters.invertedBasePoseQuat, parameters.renderPose,
            useDualQuaternion, nullptr);
    if (parameters.userChannels != nullptr)
        std::memcpy(parameters.userChannels, users.data(),
            paddedUsers * sizeof(float));
    if (parameters.originDelta != nullptr) {
        CalculatePoseBounds(parameters.skeleton, modelMatrices.data(),
            parameters.boundsSkipJoint, parameters.originDelta);
        parameters.originDelta->done = true;
    }
}
