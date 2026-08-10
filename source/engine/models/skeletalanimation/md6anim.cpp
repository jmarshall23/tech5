#include "models/skeletalanimation/md6anim.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/animation.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6skel.h"
#include "models/skeletalanimation/jobs/md6blend.h"
#include "models/skeletalanimation/md6util.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <malloc.h>
#include <vector>

namespace {

constexpr unsigned int MD6_ANIM_MAGIC = 641089869u;
constexpr unsigned int MAX_ANIM_DATA_SIZE = 256u * 1024u * 1024u;

bool ReadExact(idFile* file, void* data, unsigned int length) {
    return length == 0 || (file != nullptr && file->Read(data, length) == length);
}

bool WriteExact(idFile* file, const void* data, unsigned int length) {
    return length == 0 || (file != nullptr && file->Write(data, length) == length);
}

idMD6Anim::animationSettings_t DefaultSettings() {
    idMD6Anim::animationSettings_t settings{};
    settings.errorTolerance = 0.6f;
    settings.removeOrigin = true;
    settings.useForwardTranslation = true;
    settings.useLeftTranslation = true;
    settings.useUpTranslation = true;
    settings.useRotation = true;
    return settings;
}

bool TokenEquals(const idToken& token, const char* text) {
    return idStr::Icmp(token.c_str(), text) == 0;
}

unsigned int DecodeBitArray(const unsigned char* bits,
        const unsigned int numBits, unsigned char* indices) {
    unsigned int count = 0;
    for (unsigned int bitBase = 0; bitBase < numBits; bitBase += 8) {
        const unsigned char packed = bits[bitBase >> 3];
        for (unsigned int bit = 0; bit < 8 && bitBase + bit < numBits;
                ++bit) {
            if ((packed & (1u << bit)) != 0)
                indices[count++] = static_cast<unsigned char>(bitBase + bit);
        }
    }
    if (count != 0) {
        while ((count & 7u) != 0) {
            indices[count] = indices[count - 1];
            ++count;
        }
    }
    return count;
}

unsigned int AlignUp(const unsigned int value, const unsigned int alignment) {
    return (value + alignment - 1u) & ~(alignment - 1u);
}

void AlignBytes(std::vector<unsigned char>& bytes,
        const unsigned int alignment) {
    bytes.resize(AlignUp(static_cast<unsigned int>(bytes.size()), alignment),
        0);
}

unsigned int AppendBytes(std::vector<unsigned char>& bytes,
        const void* data, const unsigned int size) {
    const unsigned int offset = static_cast<unsigned int>(bytes.size());
    bytes.resize(offset + size);
    if (size != 0 && data != nullptr)
        std::memcpy(bytes.data() + offset, data, size);
    return offset;
}

template<typename Type>
unsigned int AppendValue(std::vector<unsigned char>& bytes,
        const Type& value) {
    return AppendBytes(bytes, &value, sizeof(value));
}

std::vector<unsigned char> EncodeRLE(
        const std::vector<unsigned char>& indices) {
    std::vector<unsigned char> encoded;
    encoded.push_back(static_cast<unsigned char>(indices.size()));
    std::size_t cursor = 0;
    while (cursor < indices.size()) {
        std::size_t run = 1;
        while (cursor + run < indices.size() && run < 127 &&
                indices[cursor + run] ==
                    static_cast<unsigned char>(indices[cursor] + run)) {
            ++run;
        }
        encoded.push_back(static_cast<unsigned char>(run));
        encoded.push_back(indices[cursor]);
        cursor += run;
    }
    return encoded;
}

void CompressQuaternion(const float* value, std::uint16_t packed[3]) {
    int omitted = 0;
    for (int component = 1; component < 4; ++component) {
        if (std::fabs(value[component]) > std::fabs(value[omitted]))
            omitted = component;
    }

    const float sign = value[omitted] < 0.0f ? -1.0f : 1.0f;
    constexpr float minimum = -0.7071067811865475244f;
    constexpr float scale = 23169.767899139602f;
    for (int stored = 0; stored < 3; ++stored) {
        const int component = (omitted + stored + 1) & 3;
        const float normalized = ((std::max)(minimum,
            (std::min)(-minimum, value[component] * sign)) - minimum) * scale;
        const int quantized = (std::max)(0, (std::min)(0x7FFF,
            static_cast<int>(normalized + 0.5f)));
        packed[stored] = static_cast<std::uint16_t>(quantized);
    }
    const unsigned int code = static_cast<unsigned int>(3 - omitted);
    packed[0] |= static_cast<std::uint16_t>((code & 1u) << 15);
    packed[1] |= static_cast<std::uint16_t>((code & 2u) << 14);
}

void NormalizeQuaternion(float* quaternion) {
    const float lengthSquared = quaternion[0] * quaternion[0] +
        quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2] +
        quaternion[3] * quaternion[3];
    if (lengthSquared <= 1.0e-20f) {
        quaternion[0] = quaternion[1] = quaternion[2] = 0.0f;
        quaternion[3] = 1.0f;
        return;
    }
    const float inverseLength = 1.0f / std::sqrt(lengthSquared);
    for (int component = 0; component < 4; ++component)
        quaternion[component] *= inverseLength;
    if (quaternion[3] < 0.0f) {
        for (int component = 0; component < 4; ++component)
            quaternion[component] = -quaternion[component];
    }
}

bool EqualValues(const float* first, const float* second,
        const int count, const float epsilon = 1.0e-6f) {
    for (int component = 0; component < count; ++component)
        if (std::fabs(first[component] - second[component]) > epsilon)
            return false;
    return true;
}

} // namespace

idTypedResourceList<idMD6Anim> idMD6Anim::resourceList("animation");
idMD6Anim::JointConversionFindCallback
    idMD6Anim::jointConversionFindCallback = nullptr;
idMD6Anim::JointConversionNameCallback
    idMD6Anim::jointConversionNameCallback = nullptr;
idMD6Anim::TextLoadCallback idMD6Anim::textLoadCallback = nullptr;
idMD6Anim::RewriteCallback idMD6Anim::rewriteCallback = nullptr;
bool idMD6Anim::skipJoints = false;

idMD6Anim::idMD6Anim()
    : skelName(""), animData(nullptr), jointConversionHandle(),
      jointConversionChecksum(), timestamp(~0u), phaseTrackTimestamp(~0u),
      settingsTimestamp(~0u), timeCode(0), origWorldPos(0.0f, 0.0f, 0.0f),
      origWorldRot(0.0f, 0.0f, 0.0f), origWorldScale(1.0f, 1.0f, 1.0f),
      startFrameOffset(0), endFrameOffset(0) {
    std::memset(&translatedBounds, 0, sizeof(translatedBounds));
    std::memset(&normalizedBounds, 0, sizeof(normalizedBounds));
}

idMD6Anim::~idMD6Anim() { FreeData(); }

void idMD6Anim::FreeData() {
    if (animData != nullptr) _aligned_free(animData);
    animData = nullptr;
    phaseTrack.Free();
}

idResourceList* idMD6Anim::GetResourceList() { return &resourceList; }

void idMD6Anim::SetCallbacks(JointConversionFindCallback findConversion,
        JointConversionNameCallback conversionName,
        TextLoadCallback textLoader, RewriteCallback rewrite) {
    jointConversionFindCallback = findConversion;
    jointConversionNameCallback = conversionName;
    textLoadCallback = textLoader;
    rewriteCallback = rewrite;
}

idMD6Anim* idMD6Anim::LoadAnim_UserChannels(const char* fileName) {
    skipJoints = true;
    idMD6Anim* result = static_cast<idMD6Anim*>(resourceList.Load(
        fileName, false, true));
    skipJoints = false;
    return result;
}

bool idMD6Anim::AnimIsOkForModel(const idMD6Model* model) const {
    if (model == nullptr || model->skeleton == nullptr ||
            model->skeleton->data == nullptr || animData == nullptr)
        return false;
    if (model->skeleton->jointConversion.IsValid())
        return model->skeleton->jointConversionChecksum ==
            jointConversionChecksum;
    if (animData->totalSize < sizeof(idMD6AnimData) + 4) return false;
    std::uint16_t animationParentCrc = 0;
    std::memcpy(&animationParentCrc,
        reinterpret_cast<const unsigned char*>(animData) +
            sizeof(idMD6AnimData) + 2, sizeof(animationParentCrc));
    return model->skeleton->data->parentTblCrc.value == animationParentCrc;
}

void idMD6Anim::VerifyRLEData(const char* animationName,
        const idList<unsigned char, 5>& rotationRLE,
        const idList<unsigned char, 5>& scaleRLE,
        const idList<unsigned char, 5>& translationRLE,
        const idList<unsigned char, 5>& userRLE,
        const idList<unsigned char, 5>& rotationBits,
        const idList<unsigned char, 5>& scaleBits,
        const idList<unsigned char, 5>& translationBits,
        const idList<unsigned char, 5>& userBits) const {
    const idList<unsigned char, 5>* rle[4] = {
        &rotationRLE, &scaleRLE, &translationRLE, &userRLE
    };
    const idList<unsigned char, 5>* bits[4] = {
        &rotationBits, &scaleBits, &translationBits, &userBits
    };
    bool valid = true;
    for (int channel = 0; channel < 4; ++channel) {
        unsigned char fromBits[272]{};
        unsigned char fromRLE[272]{};
        const unsigned int bitCount = DecodeBitArray(bits[channel]->Ptr(),
            static_cast<unsigned int>(bits[channel]->Num() * 8), fromBits);
        const unsigned int rleCount = rle[channel]->Num() == 0 ? 0
            : idMD6Blend::DecodeRLE(rle[channel]->Ptr(), 0xFFu, fromRLE);
        if (bitCount != rleCount ||
                std::memcmp(fromBits, fromRLE, bitCount) != 0) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        idLibPrint::Warning(
            "idMD6AnimData::VerifyRLEData - Verification failed for %s",
            animationName != nullptr ? animationName : "");
    }
}

bool idMD6Anim::VerifyBoundingBoxes(const idDeclMD6* declaration,
        const float epsilon, const float jointRadius) const {
    if (animData == nullptr) return false;
    if ((animData->flags & idMD6AnimData::ANIM_FLAG_IGNORE_BOUNDS) != 0)
        return true;
    if (declaration == nullptr || declaration->model == nullptr ||
            declaration->model->skeleton == nullptr ||
            declaration->model->skeleton->data == nullptr) return false;

    const idMD6Skel* skeleton = declaration->model->skeleton;
    const int numJoints = skeleton->data->numJoints;
    const int numFrames = animData->numFrames;
    if (numFrames <= 0) return true;
    const idBounds stored = translatedBounds.ToBounds();
    std::vector<idJointMat> joints(numJoints);
    for (int frame = 0; frame < numFrames; ++frame) {
        if (!skeleton->GetJointsForAnimFrame(joints.data(), this, frame,
                idVec3(0.0f, 0.0f, 0.0f), true)) return false;
        idBounds calculated;
        if (numJoints == 0) {
            calculated = declaration->referenceBounds;
        } else {
            const idVec3 root(joints[0].mat[3], joints[0].mat[7],
                joints[0].mat[11]);
            calculated[0] = root;
            calculated[1] = root;
            for (int joint = 1; joint < numJoints; ++joint) {
                const idVec3 point(joints[joint].mat[3],
                    joints[joint].mat[7], joints[joint].mat[11]);
                for (int axis = 0; axis < 3; ++axis) {
                    calculated[0][axis] = (std::min)(calculated[0][axis],
                        point[axis] - jointRadius);
                    calculated[1][axis] = (std::max)(calculated[1][axis],
                        point[axis] + jointRadius);
                }
            }
            if (numJoints == 1) {
                for (int axis = 0; axis < 3; ++axis) {
                    calculated[0][axis] = (std::min)(calculated[0][axis],
                        declaration->model->defaultBounds[0][axis]);
                    calculated[1][axis] = (std::max)(calculated[1][axis],
                        declaration->model->defaultBounds[1][axis]);
                }
            }
        }
        for (int axis = 0; axis < 3; ++axis) {
            if (calculated[0][axis] < stored[0][axis] - epsilon ||
                    calculated[1][axis] > stored[1][axis] + epsilon) {
                idLibPrint::Warning("Animation %s has joints outside bounds",
                    GetName());
                return false;
            }
        }
    }
    return true;
}

void idMD6Anim::GetAnimationDelta(idVec3* deltaTranslation,
        idMat3* deltaAxis) const {
    if (!idMD6Util::GetAnimDelta(this, deltaTranslation, deltaAxis)) {
        if (deltaTranslation != nullptr) deltaTranslation->Zero();
        if (deltaAxis != nullptr) *deltaAxis = idMat3(1.0f);
    }
}

bool idMD6Anim::LoadBinary(const char* fileName) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0;
    if (file.file == nullptr || !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != MD6_ANIM_MAGIC) return false;

    unsigned int newTimestamp = 0, newPhaseTimestamp = 0,
        newSettingsTimestamp = 0;
    int newTimeCode = 0;
    idBoundsShort newTranslated{}, newNormalized{};
    idStr conversionName;
    idHandle<unsigned short, invalidCrc_t, 65535> conversionChecksum;
    idVec3 worldPosition;
    idAngles worldRotation;
    idVec3 worldScale;
    std::int16_t firstOffset = 0, lastOffset = 0;
    unsigned int dataSize = 0;
    if (!ReadExact(file.file, &newTimestamp, sizeof(newTimestamp)) ||
            !ReadExact(file.file, &newPhaseTimestamp, sizeof(newPhaseTimestamp)) ||
            !ReadExact(file.file, &newSettingsTimestamp,
                sizeof(newSettingsTimestamp)) ||
            !ReadExact(file.file, &newTimeCode, sizeof(newTimeCode)) ||
            !ReadExact(file.file, &newTranslated, sizeof(newTranslated)) ||
            !ReadExact(file.file, &newNormalized, sizeof(newNormalized)) ||
            file->ReadString(conversionName) == 0 ||
            !ReadExact(file.file, &conversionChecksum,
                sizeof(conversionChecksum)) ||
            !ReadExact(file.file, &worldPosition, sizeof(worldPosition)) ||
            !ReadExact(file.file, &worldRotation, sizeof(worldRotation)) ||
            !ReadExact(file.file, &worldScale, sizeof(worldScale)) ||
            !ReadExact(file.file, &firstOffset, sizeof(firstOffset)) ||
            !ReadExact(file.file, &lastOffset, sizeof(lastOffset)) ||
            !ReadExact(file.file, &dataSize, sizeof(dataSize)) ||
            dataSize < sizeof(idMD6AnimData) || dataSize > MAX_ANIM_DATA_SIZE)
        return false;

    idMD6AnimData* replacement = static_cast<idMD6AnimData*>(
        _aligned_malloc(dataSize + 7u, 16));
    if (replacement == nullptr) return false;
    std::memset(replacement, 0, dataSize + 7u);
    if (!ReadExact(file.file, replacement, dataSize) ||
            replacement->totalSize != dataSize) {
        _aligned_free(replacement);
        return false;
    }
    idMD6PhaseTrack replacementPhase;
    if (!replacementPhase.LoadBinary(file.file)) {
        _aligned_free(replacement);
        return false;
    }

    FreeData();
    animData = replacement;
    phaseTrack.data = replacementPhase.data;
    replacementPhase.data = nullptr;
    timestamp = newTimestamp;
    phaseTrackTimestamp = newPhaseTimestamp;
    settingsTimestamp = newSettingsTimestamp;
    timeCode = newTimeCode;
    translatedBounds = newTranslated;
    normalizedBounds = newNormalized;
    jointConversionHandle = jointConversionFindCallback != nullptr
        ? jointConversionFindCallback(conversionName.c_str())
        : idHandle<unsigned short, invalidJointConversionHandle_t, 65535>();
    jointConversionChecksum = conversionChecksum;
    origWorldPos = worldPosition;
    origWorldRot = worldRotation;
    origWorldScale = worldScale;
    startFrameOffset = firstOffset;
    endFrameOffset = lastOffset;
    return true;
}

bool idMD6Anim::WriteBinary(const char* fileName) const {
    if (fileName == nullptr || fileSystem == nullptr || animData == nullptr ||
            animData->totalSize < sizeof(idMD6AnimData)) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const char* conversionName = jointConversionNameCallback != nullptr
        ? jointConversionNameCallback(jointConversionHandle) : "";
    const unsigned int dataSize = animData->totalSize;
    return WriteExact(file.file, &MD6_ANIM_MAGIC, sizeof(MD6_ANIM_MAGIC)) &&
        WriteExact(file.file, &timestamp, sizeof(timestamp)) &&
        WriteExact(file.file, &phaseTrackTimestamp,
            sizeof(phaseTrackTimestamp)) &&
        WriteExact(file.file, &settingsTimestamp, sizeof(settingsTimestamp)) &&
        WriteExact(file.file, &timeCode, sizeof(timeCode)) &&
        WriteExact(file.file, &translatedBounds, sizeof(translatedBounds)) &&
        WriteExact(file.file, &normalizedBounds, sizeof(normalizedBounds)) &&
        file->WriteString(conversionName != nullptr ? conversionName : "") > 0 &&
        WriteExact(file.file, &jointConversionChecksum,
            sizeof(jointConversionChecksum)) &&
        WriteExact(file.file, &origWorldPos, sizeof(origWorldPos)) &&
        WriteExact(file.file, &origWorldRot, sizeof(origWorldRot)) &&
        WriteExact(file.file, &origWorldScale, sizeof(origWorldScale)) &&
        WriteExact(file.file, &startFrameOffset, sizeof(startFrameOffset)) &&
        WriteExact(file.file, &endFrameOffset, sizeof(endFrameOffset)) &&
        WriteExact(file.file, &dataSize, sizeof(dataSize)) &&
        WriteExact(file.file, animData, dataSize) && phaseTrack.WriteBinary(file.file);
}

bool idMD6Anim::CompressAnim(const idMD6Skel* skeleton,
        const int numFrames, const int frameRate, const float* rotations,
        const float* scales, const float* translations,
        const float* userChannels, const animationSettings_t& settings,
        const bool additive, const bool ignoreBounds) {
    if (skeleton == nullptr || skeleton->data == nullptr || numFrames <= 0 ||
            numFrames > 0xFFFF || frameRate <= 0 || frameRate > 0xFFFF)
        return false;
    const int numJoints = skipJoints ? 0 : skeleton->data->numJoints;
    const int numUsers = skeleton->data->numUserChannels;
    const int paddedJoints = (skeleton->data->numJoints + 7) & ~7;
    const int paddedUsers = (numUsers + 7) & ~7;
    if ((numJoints > 0 && (rotations == nullptr || scales == nullptr ||
             translations == nullptr)) ||
            (numUsers > 0 && userChannels == nullptr)) return false;

    std::vector<unsigned char> constant[4], animated[4];
    for (int joint = 0; joint < numJoints; ++joint) {
        bool constantRotation = true, constantScale = true,
            constantTranslation = true;
        for (int frame = 1; frame < numFrames; ++frame) {
            constantRotation = constantRotation && EqualValues(
                rotations + joint * 4,
                rotations + (frame * paddedJoints + joint) * 4, 4);
            constantScale = constantScale && EqualValues(
                scales + joint * 3,
                scales + (frame * paddedJoints + joint) * 3, 3);
            constantTranslation = constantTranslation && EqualValues(
                translations + joint * 3,
                translations + (frame * paddedJoints + joint) * 3, 3);
        }
        (constantRotation ? constant[0] : animated[0]).push_back(
            static_cast<unsigned char>(joint));
        (constantScale ? constant[1] : animated[1]).push_back(
            static_cast<unsigned char>(joint));
        (constantTranslation ? constant[2] : animated[2]).push_back(
            static_cast<unsigned char>(joint));
    }
    for (int channel = 0; channel < numUsers; ++channel) {
        bool isConstant = true;
        for (int frame = 1; frame < numFrames; ++frame) {
            if (!EqualValues(userChannels + channel,
                    userChannels + frame * paddedUsers + channel, 1)) {
                isConstant = false;
                break;
            }
        }
        (isConstant ? constant[3] : animated[3]).push_back(
            static_cast<unsigned char>(channel));
    }

    auto makeFrameSet = [&](const int frameStart, const int frameCount,
            std::vector<unsigned char>& setBytes) -> bool {
        setBytes.assign(sizeof(frameSetData_t), 0);
        frameSetData_t set{};
        set.frameStart = static_cast<std::uint16_t>(frameStart);
        set.frameRange = static_cast<std::uint16_t>(frameCount);
        const int bytesPerChannel = (frameCount + 7) / 8;
        auto localOffset = [&](const unsigned int offset,
                std::uint16_t& output) -> bool {
            if (offset > 0xFFFFu) return false;
            output = static_cast<std::uint16_t>(offset);
            return true;
        };
        auto appendRotationKeys = [&](const int frame,
                const std::vector<unsigned char>& channels) {
            for (const unsigned char joint : channels) {
                const float* value = rotations +
                    (frame * paddedJoints + joint) * 4;
                std::uint16_t packed[3];
                CompressQuaternion(value, packed);
                AppendBytes(setBytes, packed, sizeof(packed));
            }
        };
        auto appendTripleKeys = [&](const float* values, const int frame,
                const int stride,
                const std::vector<unsigned char>& channels) {
            for (const unsigned char channel : channels)
                AppendBytes(setBytes,
                    values + (frame * stride + channel) * 3,
                    3 * sizeof(float));
        };
        auto appendUserKeys = [&](const int frame,
                const std::vector<unsigned char>& channels) {
            for (const unsigned char channel : channels)
                AppendValue(setBytes,
                    userChannels[frame * paddedUsers + channel]);
        };

        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.firstROffset)) return false;
        appendRotationKeys(frameStart, animated[0]);
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.firstSOffset)) return false;
        appendTripleKeys(scales, frameStart, paddedJoints, animated[1]);
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.firstTOffset)) return false;
        appendTripleKeys(translations, frameStart, paddedJoints, animated[2]);
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.firstUOffset)) return false;
        appendUserKeys(frameStart, animated[3]);

        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.rangeROffset)) return false;
        for (const unsigned char joint : animated[0]) {
            for (int localFrame = 1; localFrame < frameCount; ++localFrame) {
                const float* value = rotations + ((frameStart + localFrame) *
                    paddedJoints + joint) * 4;
                std::uint16_t packed[3];
                CompressQuaternion(value, packed);
                AppendBytes(setBytes, packed, sizeof(packed));
            }
        }
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.rangeSOffset)) return false;
        for (const unsigned char joint : animated[1])
            for (int localFrame = 1; localFrame < frameCount; ++localFrame)
                AppendBytes(setBytes, scales + ((frameStart + localFrame) *
                    paddedJoints + joint) * 3, 3 * sizeof(float));
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.rangeTOffset)) return false;
        for (const unsigned char joint : animated[2])
            for (int localFrame = 1; localFrame < frameCount; ++localFrame)
                AppendBytes(setBytes, translations + ((frameStart + localFrame) *
                    paddedJoints + joint) * 3, 3 * sizeof(float));
        AlignBytes(setBytes, 16);
        if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                set.rangeUOffset)) return false;
        for (const unsigned char channel : animated[3])
            for (int localFrame = 1; localFrame < frameCount; ++localFrame)
                AppendValue(setBytes, userChannels[
                    (frameStart + localFrame) * paddedUsers + channel]);

        auto appendFrameBits = [&](const std::vector<unsigned char>& channels,
                std::uint16_t& offset) -> bool {
            AlignBytes(setBytes, 16);
            if (!localOffset(static_cast<unsigned int>(setBytes.size()),
                    offset)) return false;
            for (std::size_t channel = 0; channel < channels.size(); ++channel) {
                const unsigned int base = static_cast<unsigned int>(
                    setBytes.size());
                setBytes.resize(base + bytesPerChannel, 0);
                for (int frame = 1; frame < frameCount; ++frame)
                    setBytes[base + frame / 8] |=
                        static_cast<unsigned char>(0x80u >> (frame & 7));
            }
            return true;
        };
        if (!appendFrameBits(animated[0], set.RBitsOffset) ||
                !appendFrameBits(animated[1], set.SBitsOffset) ||
                !appendFrameBits(animated[2], set.TBitsOffset) ||
                !appendFrameBits(animated[3], set.UBitsOffset)) return false;
        AlignBytes(setBytes, 16);
        if (setBytes.size() > 0xFFFFu ||
                (setBytes.size() > 0x4000u && frameCount > 1)) return false;
        set.totalSize = static_cast<std::uint16_t>(setBytes.size());
        std::memcpy(set.pad, "_FRAMESET_", sizeof(set.pad));
        std::memcpy(setBytes.data(), &set, sizeof(set));
        return true;
    };

    std::vector<std::vector<unsigned char>> frameSets;
    int frameStart = 0;
    while (frameStart < numFrames) {
        int frameCount = (std::min)(62, numFrames - frameStart);
        std::vector<unsigned char> setBytes;
        while (frameCount > 0 && !makeFrameSet(frameStart, frameCount,
                setBytes)) frameCount /= 2;
        if (frameCount <= 0 || frameSets.size() >= 256) return false;
        frameSets.push_back(std::move(setBytes));
        frameStart += frameCount;
    }

    std::vector<unsigned char> bytes(sizeof(idMD6AnimData), 0);
    const std::uint16_t parentCrc = skeleton->data->parentTblCrc.Get();
    AppendValue(bytes, parentCrc);
    const unsigned int mapOffsetsPosition = static_cast<unsigned int>(
        bytes.size());
    bytes.resize(bytes.size() + 8 * sizeof(std::uint16_t), 0);
    std::uint16_t mapOffsets[8]{};
    for (int channel = 0; channel < 4; ++channel) {
        const std::vector<unsigned char> rle = EncodeRLE(constant[channel]);
        if (bytes.size() > 0xFFFFu) return false;
        mapOffsets[channel] = static_cast<std::uint16_t>(bytes.size());
        AppendBytes(bytes, rle.data(), static_cast<unsigned int>(rle.size()));
    }
    for (int channel = 0; channel < 4; ++channel) {
        const std::vector<unsigned char> rle = EncodeRLE(animated[channel]);
        if (bytes.size() > 0xFFFFu) return false;
        mapOffsets[channel + 4] = static_cast<std::uint16_t>(bytes.size());
        AppendBytes(bytes, rle.data(), static_cast<unsigned int>(rle.size()));
    }
    std::memcpy(bytes.data() + mapOffsetsPosition, mapOffsets,
        sizeof(mapOffsets));

    idMD6AnimData header{};
    header.numFrames = static_cast<std::uint16_t>(numFrames);
    header.frameRate = static_cast<std::uint16_t>(frameRate);
    header.numAnimMaps = 1;
    header.numFrameSets = static_cast<std::uint16_t>(frameSets.size());
    AlignBytes(bytes, 4);
    if (bytes.size() > 0xFFFFu) return false;
    header.constROffset = static_cast<std::uint16_t>(bytes.size());
    for (const unsigned char joint : constant[0]) {
        const float* value = rotations + joint * 4;
        std::uint16_t packed[3];
        CompressQuaternion(value, packed);
        AppendBytes(bytes, packed, sizeof(packed));
    }
    AlignBytes(bytes, 4);
    if (bytes.size() > 0xFFFFu) return false;
    header.constSOffset = static_cast<std::uint16_t>(bytes.size());
    for (const unsigned char joint : constant[1])
        AppendBytes(bytes, scales + joint * 3, 3 * sizeof(float));
    if (bytes.size() > 0xFFFFu) return false;
    header.constTOffset = static_cast<std::uint16_t>(bytes.size());
    for (const unsigned char joint : constant[2])
        AppendBytes(bytes, translations + joint * 3, 3 * sizeof(float));
    if (bytes.size() > 0xFFFFu) return false;
    header.constUOffset = static_cast<std::uint16_t>(bytes.size());
    for (const unsigned char channel : constant[3])
        AppendValue(bytes, userChannels[channel]);

    if (bytes.size() > 0xFFFFu) return false;
    header.frameSetTblOffset = static_cast<std::uint16_t>(bytes.size());
    std::vector<unsigned char> frameSetTable(numFrames, 0);
    for (std::size_t setIndex = 0; setIndex < frameSets.size(); ++setIndex) {
        const frameSetData_t* set = reinterpret_cast<const frameSetData_t*>(
            frameSets[setIndex].data());
        for (int frame = 0; frame < set->frameRange; ++frame)
            frameSetTable[set->frameStart + frame] =
                static_cast<unsigned char>(setIndex);
    }
    AppendBytes(bytes, frameSetTable.data(),
        static_cast<unsigned int>(frameSetTable.size()));
    AlignBytes(bytes, 4);
    if (bytes.size() > 0xFFFFu) return false;
    header.frameSetOffsetTblOffset = static_cast<std::uint16_t>(bytes.size());
    const unsigned int frameSetOffsetsPosition = static_cast<unsigned int>(
        bytes.size());
    bytes.resize(bytes.size() +
        (frameSets.size() + 1) * sizeof(std::uint32_t), 0);
    AlignBytes(bytes, 16);
    if (bytes.size() > 0xFFFFu) return false;
    header.size = static_cast<std::uint16_t>(bytes.size());
    std::vector<std::uint32_t> frameSetOffsets(frameSets.size() + 1, 0);
    for (std::size_t setIndex = 0; setIndex < frameSets.size(); ++setIndex) {
        AlignBytes(bytes, 16);
        frameSetOffsets[setIndex] =
            static_cast<std::uint32_t>(bytes.size() / 16u);
        AppendBytes(bytes, frameSets[setIndex].data(),
            static_cast<unsigned int>(frameSets[setIndex].size()));
    }
    for (std::size_t setIndex = 0; setIndex < frameSets.size(); ++setIndex) {
        const std::size_t nextIndex = setIndex + 1 < frameSets.size()
            ? setIndex + 1 : setIndex;
        const unsigned int setOffset = frameSetOffsets[setIndex] * 16u;
        const unsigned int nextOffset = frameSetOffsets[nextIndex] * 16u;
        frameSetData_t* set = reinterpret_cast<frameSetData_t*>(
            bytes.data() + setOffset);
        const frameSetData_t* next = reinterpret_cast<const frameSetData_t*>(
            bytes.data() + nextOffset);
        auto nextKeyOffset = [&](const std::uint16_t localOffset,
                std::uint16_t& output) -> bool {
            const unsigned int absolute = nextOffset + localOffset;
            if (absolute < setOffset || absolute - setOffset > 0xFFFFu)
                return false;
            output = static_cast<std::uint16_t>(absolute - setOffset);
            return true;
        };
        if (!nextKeyOffset(next->firstROffset, set->nextROffset) ||
                !nextKeyOffset(next->firstSOffset, set->nextSOffset) ||
                !nextKeyOffset(next->firstTOffset, set->nextTOffset) ||
                !nextKeyOffset(next->firstUOffset, set->nextUOffset))
            return false;
    }
    AlignBytes(bytes, 16);
    frameSetOffsets.back() = static_cast<std::uint32_t>(bytes.size() / 16u);
    std::memcpy(bytes.data() + frameSetOffsetsPosition,
        frameSetOffsets.data(), frameSetOffsets.size() * sizeof(std::uint32_t));
    if (bytes.size() > MAX_ANIM_DATA_SIZE) return false;
    header.totalSize = static_cast<unsigned int>(bytes.size());
    header.nextSize = 0;
    if (additive) header.flags |= idMD6AnimData::ANIM_FLAG_ADDITIVE;
    if (ignoreBounds) header.flags |= idMD6AnimData::ANIM_FLAG_IGNORE_BOUNDS;
    if (settings.useForwardTranslation)
        header.flags |= idMD6AnimData::ANIM_FLAG_USE_FORWARD_TRANSLATION;
    if (settings.useLeftTranslation)
        header.flags |= idMD6AnimData::ANIM_FLAG_USE_LEFT_TRANSLATION;
    if (settings.useUpTranslation)
        header.flags |= idMD6AnimData::ANIM_FLAG_USE_UP_TRANSLATION;
    if (settings.useRotation)
        header.flags |= idMD6AnimData::ANIM_FLAG_USE_ROTATION;
    if (settings.retargetAdditive)
        header.flags |= idMD6AnimData::ANIM_FLAG_RETARGET_ADDITIVE;
    if (settings.frameZeroDelta)
        header.flags |= idMD6AnimData::ANIM_FLAG_FRAME_ZERO_DELTA;
    if (numJoints > 0)
        header.flags |= idMD6AnimData::ANIM_FLAG_HAS_JOINT_DATA;
    if (numUsers > 0)
        header.flags |= idMD6AnimData::ANIM_FLAG_HAS_USER_CHANNEL_DATA;
    if ((header.flags & (idMD6AnimData::ANIM_FLAG_USE_FORWARD_TRANSLATION |
            idMD6AnimData::ANIM_FLAG_USE_LEFT_TRANSLATION |
            idMD6AnimData::ANIM_FLAG_USE_UP_TRANSLATION |
            idMD6AnimData::ANIM_FLAG_USE_ROTATION)) != 0)
        header.flags |= idMD6AnimData::ANIM_FLAG_HAS_ORIGIN_DELTA;

    if (numJoints > 0) {
        const int frames[2] = { 0, numFrames - 1 };
        float* deltas[2] = { header.startDelta, header.endDelta };
        for (int endpoint = 0; endpoint < 2; ++endpoint) {
            const int frame = frames[endpoint];
            std::memcpy(deltas[endpoint], rotations +
                frame * paddedJoints * 4, 4 * sizeof(float));
            std::memcpy(deltas[endpoint] + 4, scales +
                frame * paddedJoints * 3, 3 * sizeof(float));
            deltas[endpoint][7] = 1.0f;
            std::memcpy(deltas[endpoint] + 8, translations +
                frame * paddedJoints * 3, 3 * sizeof(float));
        }
    } else {
        header.startDelta[3] = header.endDelta[3] = 1.0f;
        header.startDelta[4] = header.startDelta[5] =
            header.startDelta[6] = 1.0f;
        header.endDelta[4] = header.endDelta[5] =
            header.endDelta[6] = 1.0f;
        header.startDelta[7] = header.endDelta[7] = 1.0f;
    }
    std::memcpy(bytes.data(), &header, sizeof(header));
    idMD6AnimData* replacement = static_cast<idMD6AnimData*>(
        _aligned_malloc(bytes.size() + 7u, 16));
    if (replacement == nullptr) return false;
    std::memset(replacement, 0, bytes.size() + 7u);
    std::memcpy(replacement, bytes.data(), bytes.size());
    FreeData();
    animData = replacement;
    return true;
}

bool idMD6Anim::LoadFacetracksComposite(const char* basePath,
        const idMD6Skel* skeleton, const animationSettings_t& settings) {
    if (basePath == nullptr || skeleton == nullptr ||
            skeleton->data == nullptr || animation == nullptr) return false;
    std::vector<idStr> trackNames(skeleton->data->numUserChannels);
    int numTracks = 0;
    for (int handleIndex = 0;
            handleIndex < animation->GetNumUserChannels(); ++handleIndex) {
        const char* name = animation->GetUserChannelName(
            userChannelHandle_t(static_cast<unsigned short>(handleIndex)));
        if (name == nullptr || std::strstr(name, "facedata_") == nullptr)
            continue;
        const md6UserChannelIndex_t channel =
            skeleton->GetUserChannelIndex(name);
        if (!channel.IsValid() || channel.Get() < 0 ||
                channel.Get() >= skeleton->data->numUserChannels) continue;
        trackNames[channel.Get()] = name;
        numTracks = (std::max)(numTracks,
            static_cast<int>(channel.Get()) + 1);
    }
    if (numTracks <= 0) return false;

    const int paddedJoints = (skeleton->data->numJoints + 7) & ~7;
    const int paddedUsers = (skeleton->data->numUserChannels + 7) & ~7;
    std::vector<float> rotations(numTracks * paddedJoints * 4, 0.0f);
    std::vector<float> scales(numTracks * paddedJoints * 3, 1.0f);
    std::vector<float> translations(numTracks * paddedJoints * 3, 0.0f);
    std::vector<float> users(numTracks * paddedUsers, 0.0f);
    for (int frame = 0; frame < numTracks; ++frame)
        for (int joint = 0; joint < paddedJoints; ++joint)
            rotations[(frame * paddedJoints + joint) * 4 + 3] = 1.0f;

    for (int track = 0; track < numTracks; ++track) {
        if (trackNames[track].IsEmpty()) continue;
        idStr trackFile(basePath);
        trackFile.Append(trackNames[track].c_str());
        trackFile.Append(".md6anim");
        idParser trackParser(262704);
        if (!trackParser.LoadFile(trackFile.c_str(), false)) return false;
        idToken token;
        if (!trackParser.ReadToken(token) ||
                (!TokenEquals(token, "MD6_VERSION_STRING") &&
                 !TokenEquals(token, "MD6")) ||
                trackParser.ParseInt() != 7) return false;
        timestamp = (std::max)(timestamp,
            fileSystem->GetTimestamp(trackFile.c_str(), false));
        if (!trackParser.SkipUntilString("init") ||
                !trackParser.ExpectTokenString("{")) return false;
        int sourceJoints = 0;
        while (trackParser.ReadToken(token) && !TokenEquals(token, "}")) {
            if (TokenEquals(token, "numJoints"))
                sourceJoints = trackParser.ParseInt();
            else
                trackParser.SkipRestOfLine();
        }
        if (sourceJoints < 0 || sourceJoints > 255 ||
                !trackParser.SkipUntilString("joints") ||
                !trackParser.ExpectTokenString("{")) return false;
        std::vector<short> jointMap(sourceJoints, -1);
        for (int sourceJoint = 0; sourceJoint < sourceJoints; ++sourceJoint) {
            if (!trackParser.ReadToken(token)) return false;
            const md6JointIndex_t mapped =
                skeleton->GetJointIndex(token.c_str());
            if (!mapped.IsValid()) return false;
            jointMap[sourceJoint] = mapped.Get();
            trackParser.SkipRestOfLine();
        }
        if (!trackParser.ExpectTokenString("}") ||
                !trackParser.SkipUntilString("frames") ||
                !trackParser.ExpectTokenString("{") ||
                !trackParser.ExpectTokenString("frame")) return false;
        trackParser.ParseInt();
        if (!trackParser.ExpectTokenString("{")) return false;
        for (int sourceJoint = 0; sourceJoint < sourceJoints; ++sourceJoint) {
            if (!trackParser.ExpectTokenString("joint")) return false;
            const int declaredJoint = trackParser.ParseInt();
            if (!trackParser.ExpectTokenString("{")) return false;
            float rotation[4], scale[3], translation[3];
            if (!trackParser.ExpectTokenString("R") ||
                    !trackParser.Parse1DMatrix(4, rotation) ||
                    !trackParser.ExpectTokenString("S") ||
                    !trackParser.Parse1DMatrix(3, scale) ||
                    !trackParser.ExpectTokenString("T") ||
                    !trackParser.Parse1DMatrix(3, translation) ||
                    !trackParser.ExpectTokenString("}")) return false;
            const int sourceIndex = declaredJoint >= 0 &&
                declaredJoint < sourceJoints ? declaredJoint : sourceJoint;
            const int joint = jointMap[sourceIndex];
            if (joint < 0 || joint >= skeleton->data->numJoints) continue;
            NormalizeQuaternion(rotation);
            for (float& component : scale) {
                if (component < 0.0f || component > 50.0f)
                    component = 1.0f;
            }
            std::memcpy(rotations.data() +
                (track * paddedJoints + joint) * 4, rotation,
                sizeof(rotation));
            std::memcpy(scales.data() +
                (track * paddedJoints + joint) * 3, scale, sizeof(scale));
            std::memcpy(translations.data() +
                (track * paddedJoints + joint) * 3, translation,
                sizeof(translation));
        }
    }
    if (!CompressAnim(skeleton, numTracks, 30, rotations.data(),
            scales.data(), translations.data(), users.data(), settings,
            true, false)) return false;
    animData->flags |= idMD6AnimData::ANIM_FLAG_FACETRACKS_COMPOSITE |
        idMD6AnimData::ANIM_FLAG_ADDITIVE;
    return true;
}

bool idMD6Anim::LoadText(const char* fileName,
        const float* errorToleranceOverride) {
    if (textLoadCallback != nullptr)
        return textLoadCallback(this, fileName, errorToleranceOverride);
    if (fileName == nullptr || fileSystem == nullptr) return false;

    animationSettings_t settings;
    const bool settingsLoaded = LoadAnim_Settings(fileName, settings,
        &settingsTimestamp, false);
    idParser parser(262704);
    if (!parser.LoadFile(fileName, false)) return false;
    idToken token;
    if (!parser.ReadToken(token) ||
            (!TokenEquals(token, "MD6_VERSION_STRING") &&
             !TokenEquals(token, "MD6")) || parser.ParseInt() != 7)
        return false;
    timestamp = fileSystem->GetTimestamp(fileName, false);

    idStr skeletonName;
    int sourceFrames = 0, frameRate = 30, sourceJoints = 0,
        sourceUsers = 0;
    float embeddedErrorTolerance = 0.6f;
    bool hasEmbeddedErrorTolerance = false;
    bool additive = false, ignoreBounds = false;
    bool embeddedForward = true, embeddedLeft = true, embeddedUp = true,
        embeddedRotation = true, embeddedRetarget = false,
        embeddedFacetracks = false, embeddedFrameZero = false;
    idBounds parsedBounds;
    parsedBounds[0].Zero();
    parsedBounds[1].Zero();
    translatedBounds.SetBounds(parsedBounds);
    normalizedBounds.SetBounds(parsedBounds);
    timeCode = 0;
    origWorldPos.Zero();
    origWorldRot.pitch = origWorldRot.yaw = origWorldRot.roll = 0.0f;
    origWorldScale.Set(1.0f, 1.0f, 1.0f);

    if (!parser.ExpectTokenString("init") ||
            !parser.ExpectTokenString("{")) return false;
    while (parser.ReadToken(token) && !TokenEquals(token, "}")) {
        if (TokenEquals(token, "commandLine") ||
                TokenEquals(token, "sourceAnim") ||
                TokenEquals(token, "subtractiveAnim") ||
                TokenEquals(token, "maskName") ||
                TokenEquals(token, "rotationMask") ||
                TokenEquals(token, "scaleMask") ||
                TokenEquals(token, "translationMask") ||
                TokenEquals(token, "sourceTake")) {
            if (!parser.ReadToken(token)) return false;
        } else if (TokenEquals(token, "skeletonName")) {
            if (!parser.ReadToken(token)) return false;
            skeletonName = token.c_str();
        } else if (TokenEquals(token, "numFrames")) {
            sourceFrames = parser.ParseInt();
        } else if (TokenEquals(token, "frameRate")) {
            frameRate = parser.ParseInt();
        } else if (TokenEquals(token, "numJoints")) {
            sourceJoints = parser.ParseInt();
        } else if (TokenEquals(token, "numUserChannels")) {
            sourceUsers = parser.ParseInt();
        } else if (TokenEquals(token, "maxErrorRotation") ||
                TokenEquals(token, "maxErrorScale") ||
                TokenEquals(token, "maxErrorTranslation") ||
                TokenEquals(token, "maxErrorUser")) {
            parser.ParseFloat();
        } else if (TokenEquals(token, "errorTolerance")) {
            embeddedErrorTolerance = parser.ParseFloat();
            hasEmbeddedErrorTolerance = true;
        } else if (TokenEquals(token, "bounds") ||
                TokenEquals(token, "translatedBounds") ||
                TokenEquals(token, "normalizedBounds")) {
            idBounds bounds;
            if (!parser.Parse1DMatrix(3, &bounds[0].x) ||
                    !parser.Parse1DMatrix(3, &bounds[1].x)) return false;
            if (TokenEquals(token, "bounds") ||
                    TokenEquals(token, "translatedBounds"))
                translatedBounds.SetBounds(bounds);
            if (TokenEquals(token, "bounds") ||
                    TokenEquals(token, "normalizedBounds"))
                normalizedBounds.SetBounds(bounds);
        } else if (TokenEquals(token, "startFrame")) {
            timeCode = parser.ParseInt();
        } else if (TokenEquals(token, "worldPos")) {
            if (!parser.Parse1DMatrix(3, &origWorldPos.x)) return false;
        } else if (TokenEquals(token, "worldRot")) {
            if (!parser.Parse1DMatrix(3, &origWorldRot.pitch)) return false;
        } else if (TokenEquals(token, "worldScale")) {
            if (!parser.Parse1DMatrix(3, &origWorldScale.x)) return false;
        } else {
            parser.SkipRestOfLine();
        }
    }
    if (sourceFrames <= 0 || sourceFrames > 0xFFFF || frameRate != 30 ||
            sourceJoints < 0 || sourceJoints > 255 || sourceUsers < 0 ||
            sourceUsers > 255 || skeletonName.IsEmpty()) return false;
    const idMD6Skel* skeleton = static_cast<const idMD6Skel*>(
        idMD6Skel::resourceList.Load(skeletonName.c_str(), false, false));
    if (skeleton == nullptr || skeleton->data == nullptr) return false;

    if (!parser.ExpectTokenString("flags") ||
            !parser.ExpectTokenString("{")) return false;
    while (parser.ReadToken(token) && !TokenEquals(token, "}")) {
        if (TokenEquals(token, "additive")) additive = true;
        else if (TokenEquals(token, "ignoreBounds")) ignoreBounds = true;
        else if (TokenEquals(token, "useForwardTranslation"))
            embeddedForward = true;
        else if (TokenEquals(token, "useLeftTranslation"))
            embeddedLeft = true;
        else if (TokenEquals(token, "useUpTranslation")) embeddedUp = true;
        else if (TokenEquals(token, "useRotation") ||
                TokenEquals(token, "useYawRotation"))
            embeddedRotation = true;
        else if (TokenEquals(token, "retargetAdditive"))
            embeddedRetarget = true;
        else if (TokenEquals(token, "facetracksComposite"))
            embeddedFacetracks = true;
        else if (TokenEquals(token, "frameZeroDelta"))
            embeddedFrameZero = true;
    }
    if (!settingsLoaded) {
        settings = DefaultSettings();
        settings.errorTolerance = hasEmbeddedErrorTolerance
            ? embeddedErrorTolerance : settings.errorTolerance;
        settings.useForwardTranslation = embeddedForward;
        settings.useLeftTranslation = embeddedLeft;
        settings.useUpTranslation = embeddedUp;
        settings.useRotation = embeddedRotation;
        settings.retargetAdditive = embeddedRetarget;
        settings.facetracksComposite = embeddedFacetracks;
        settings.frameZeroDelta = embeddedFrameZero;
    }
    if (errorToleranceOverride != nullptr)
        settings.errorTolerance = *errorToleranceOverride;
    int firstFrame = settings.startFrameOffset;
    int lastFrame = sourceFrames - settings.endFrameOffset;
    if (firstFrame < 0 || lastFrame > sourceFrames ||
            lastFrame - firstFrame < 2) {
        firstFrame = 0;
        lastFrame = sourceFrames;
    }
    startFrameOffset = static_cast<std::int16_t>(firstFrame);
    endFrameOffset = static_cast<std::int16_t>(sourceFrames - lastFrame);

    std::vector<short> sourceParents(sourceJoints, -1);
    std::vector<short> jointMap(sourceJoints, -1);
    if (!parser.ExpectTokenString("joints") ||
            !parser.ExpectTokenString("{")) return false;
    for (int joint = 0; joint < sourceJoints; ++joint) {
        if (!parser.ReadToken(token)) return false;
        sourceParents[joint] = static_cast<short>(parser.ParseInt());
        const md6JointIndex_t mapped = skeleton->GetJointIndex(token.c_str());
        if (!skipJoints && !mapped.IsValid()) return false;
        jointMap[joint] = mapped.Get();
        parser.ParseFloat();
    }
    if (!parser.ExpectTokenString("}")) return false;

    std::vector<short> userMap(sourceUsers, -1);
    if (parser.CheckTokenString("userChannels")) {
        if (!parser.ExpectTokenString("{")) return false;
        for (int channel = 0; channel < sourceUsers; ++channel) {
            if (!parser.ReadToken(token)) return false;
            const md6UserChannelIndex_t mapped =
                skeleton->GetUserChannelIndex(token.c_str());
            if (!skipJoints && !mapped.IsValid()) return false;
            userMap[channel] = skipJoints
                ? static_cast<short>(channel) : mapped.Get();
        }
        if (!parser.ExpectTokenString("}")) return false;
    } else {
        for (int channel = 0; channel < sourceUsers; ++channel)
            userMap[channel] = channel < skeleton->data->numUserChannels
                ? static_cast<short>(channel) : static_cast<short>(-1);
    }

    const char* masks[3] = {
        "rotationMask", "scaleMask", "translationMask" };
    for (const char* mask : masks) {
        if (!parser.ExpectTokenString(mask)) return false;
        if (!parser.SkipBracedSection(true)) return false;
    }

    if (settings.facetracksComposite) {
        if (!parser.ExpectTokenString("facetracksComposite") ||
                !parser.ExpectTokenString("{") ||
                !parser.ExpectTokenString("facesetupBasePath") ||
                !parser.ReadToken(token)) return false;
        const idStr basePath(token.c_str());
        if (!parser.ExpectTokenString("}")) return false;
        if (!LoadFacetracksComposite(basePath.c_str(), skeleton, settings))
            return false;
        skelName = idAtomicString(skeletonName.c_str());
        jointConversionHandle = skeleton->jointConversion;
        jointConversionChecksum = skeleton->jointConversionChecksum;
        return true;
    }

    const int targetFrames = lastFrame - firstFrame;
    const int paddedJoints = (skeleton->data->numJoints + 7) & ~7;
    const int paddedUsers = (skeleton->data->numUserChannels + 7) & ~7;
    std::vector<float> rotations(targetFrames * paddedJoints * 4, 0.0f);
    std::vector<float> scales(targetFrames * paddedJoints * 3, 1.0f);
    std::vector<float> translations(targetFrames * paddedJoints * 3, 0.0f);
    std::vector<float> users(targetFrames * paddedUsers, 0.0f);
    const float* baseR = skeleton->BaseRotations();
    const float* baseS = skeleton->BaseScales();
    const float* baseT = skeleton->BaseTranslations();
    const float* baseU = skeleton->UserChannelDefaults();
    const bool additivePose = additive || settings.retargetAdditive;
    for (int frame = 0; frame < targetFrames; ++frame) {
        if (paddedJoints > 0 && !additivePose) {
            std::memcpy(rotations.data() + frame * paddedJoints * 4, baseR,
                paddedJoints * 4 * sizeof(float));
            std::memcpy(scales.data() + frame * paddedJoints * 3, baseS,
                paddedJoints * 3 * sizeof(float));
            std::memcpy(translations.data() + frame * paddedJoints * 3,
                baseT, paddedJoints * 3 * sizeof(float));
        } else if (paddedJoints > 0) {
            for (int joint = 0; joint < paddedJoints; ++joint)
                rotations[(frame * paddedJoints + joint) * 4 + 3] = 1.0f;
        }
        if (paddedUsers > 0 && !additivePose)
            std::memcpy(users.data() + frame * paddedUsers, baseU,
                paddedUsers * sizeof(float));
    }

    if (!parser.ExpectTokenString("frames") ||
            !parser.ExpectTokenString("{")) return false;
    for (int sourceFrame = 0; sourceFrame < sourceFrames; ++sourceFrame) {
        if (!parser.ExpectTokenString("frame")) return false;
        parser.ParseInt();
        if (!parser.ExpectTokenString("{")) return false;
        for (int sourceJoint = 0; sourceJoint < sourceJoints; ++sourceJoint) {
            if (!parser.ExpectTokenString("joint")) return false;
            const int declaredJoint = parser.ParseInt();
            if (!parser.ExpectTokenString("{")) return false;
            float rotation[4], scale[3], translation[3];
            if (!parser.ExpectTokenString("R") ||
                    !parser.Parse1DMatrix(4, rotation) ||
                    !parser.ExpectTokenString("S") ||
                    !parser.Parse1DMatrix(3, scale) ||
                    !parser.ExpectTokenString("T") ||
                    !parser.Parse1DMatrix(3, translation) ||
                    !parser.ExpectTokenString("}")) return false;
            NormalizeQuaternion(rotation);
            const int sourceIndex = declaredJoint >= 0 &&
                declaredJoint < sourceJoints ? declaredJoint : sourceJoint;
            const int targetJoint = jointMap[sourceIndex];
            if (sourceFrame >= firstFrame && sourceFrame < lastFrame &&
                    targetJoint >= 0 && targetJoint <
                        skeleton->data->numJoints) {
                const int outputFrame = sourceFrame - firstFrame;
                std::memcpy(rotations.data() +
                    (outputFrame * paddedJoints + targetJoint) * 4,
                    rotation, sizeof(rotation));
                std::memcpy(scales.data() +
                    (outputFrame * paddedJoints + targetJoint) * 3,
                    scale, sizeof(scale));
                std::memcpy(translations.data() +
                    (outputFrame * paddedJoints + targetJoint) * 3,
                    translation, sizeof(translation));
            }
        }
        if (!parser.ExpectTokenString("}")) return false;
    }
    if (!parser.ExpectTokenString("}")) return false;

    if (parser.CheckTokenString("userChannels")) {
        if (!parser.ExpectTokenString("{")) return false;
        std::vector<float> sourceValues(sourceUsers, 0.0f);
        for (int sourceFrame = 0; sourceFrame < sourceFrames; ++sourceFrame) {
            if (!parser.Parse1DMatrix(sourceUsers, sourceValues.data()))
                return false;
            if (sourceFrame < firstFrame || sourceFrame >= lastFrame) continue;
            const int outputFrame = sourceFrame - firstFrame;
            for (int sourceChannel = 0; sourceChannel < sourceUsers;
                    ++sourceChannel) {
                const int targetChannel = userMap[sourceChannel];
                if (targetChannel >= 0 && targetChannel <
                        skeleton->data->numUserChannels)
                    users[outputFrame * paddedUsers + targetChannel] =
                        sourceValues[sourceChannel];
            }
        }
        if (!parser.ExpectTokenString("}")) return false;
    }
    if (parser.CheckTokenString("mappedSkeletons") &&
            !parser.SkipBracedSection(true)) return false;
    if (parser.HadError()) return false;

    if (!CompressAnim(skeleton, targetFrames, frameRate, rotations.data(),
            scales.data(), translations.data(), users.data(), settings,
            additive, ignoreBounds)) return false;
    skelName = idAtomicString(skeletonName.c_str());
    jointConversionHandle = skeleton->jointConversion;
    jointConversionChecksum = skeleton->jointConversionChecksum;
    idStr phaseName(fileName);
    phaseName.SetFileExtension("ptrack");
    phaseTrackTimestamp = fileSystem->GetTimestamp(phaseName.c_str(), false);
    phaseTrack.LoadText(phaseName.c_str(), this);
    return true;
}

bool idMD6Anim::RewriteText(const char* fileName) {
    return rewriteCallback != nullptr && rewriteCallback(fileName);
}

bool idMD6Anim::LoadAnim_Settings(const char* animationFileName,
        animationSettings_t& settings, unsigned int* settingsTime,
        const bool loadFromAnim) {
    settings = DefaultSettings();
    if (animationFileName == nullptr || fileSystem == nullptr) return false;
    idStr settingsName(animationFileName);
    settingsName.SetFileExtension("md6settings");
    if (settingsTime != nullptr)
        *settingsTime = fileSystem->GetTimestamp(settingsName.c_str(), false);
    idParser parser(262704);
    const char* sourceName = loadFromAnim ? animationFileName
        : settingsName.c_str();
    if (!parser.LoadFile(sourceName, false)) return false;
    idToken token;
    if (!parser.ReadToken(token)) return false;
    if (TokenEquals(token, "MD6_VERSION_STRING") || TokenEquals(token, "MD6")) {
        const int version = parser.ParseInt();
        if (version < 5 || version > 7) return false;
    } else {
        parser.UnreadToken(token);
    }
    if (parser.SkipUntilString("init")) parser.ExpectTokenString("{");
    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (TokenEquals(token, "maxErrorRotation") ||
                TokenEquals(token, "maxErrorScale") ||
                TokenEquals(token, "maxErrorTranslation") ||
                TokenEquals(token, "maxErrorUser")) {
            parser.ParseFloat();
        } else if (TokenEquals(token, "errorTolerance")) {
            settings.errorTolerance = parser.ParseFloat();
        } else if (TokenEquals(token, "startFrameOffset")) {
            settings.startFrameOffset = parser.ParseInt();
        } else if (TokenEquals(token, "endFrameOffset")) {
            settings.endFrameOffset = parser.ParseInt();
        } else if (TokenEquals(token, "removeOrigin")) {
            settings.removeOrigin = parser.ParseBool();
        } else if (TokenEquals(token, "useForwardTranslation")) {
            settings.useForwardTranslation = parser.ParseBool();
        } else if (TokenEquals(token, "useLeftTranslation")) {
            settings.useLeftTranslation = parser.ParseBool();
        } else if (TokenEquals(token, "useUpTranslation")) {
            settings.useUpTranslation = parser.ParseBool();
        } else if (TokenEquals(token, "useRotation")) {
            settings.useRotation = parser.ParseBool();
        } else if (TokenEquals(token, "retargetAdditive")) {
            settings.retargetAdditive = parser.ParseBool();
        } else if (TokenEquals(token, "facetracksComposite")) {
            settings.facetracksComposite = parser.ParseBool();
        } else if (TokenEquals(token, "frameZeroDelta")) {
            settings.frameZeroDelta = parser.ParseBool();
        } else if (TokenEquals(token, "flags")) {
            if (!parser.ExpectTokenString("{")) return false;
            while (parser.ReadToken(token) &&
                    idStr::Cmp(token.c_str(), "}") != 0) {
                if (TokenEquals(token, "useForwardTranslation"))
                    settings.useForwardTranslation = true;
                else if (TokenEquals(token, "useLeftTranslation"))
                    settings.useLeftTranslation = true;
                else if (TokenEquals(token, "useUpTranslation"))
                    settings.useUpTranslation = true;
                else if (TokenEquals(token, "useRotation") ||
                         TokenEquals(token, "useYawRotation"))
                    settings.useRotation = true;
                else if (TokenEquals(token, "retargetAdditive"))
                    settings.retargetAdditive = true;
                else if (TokenEquals(token, "facetracksComposite"))
                    settings.facetracksComposite = true;
                else if (TokenEquals(token, "frameZeroDelta"))
                    settings.frameZeroDelta = true;
            }
        } else {
            parser.SkipRestOfLine();
        }
    }
    return !parser.HadError();
}

void idMD6Anim::MakeDefault(const idMD6Skel* skeleton) {
    FreeData();
    animData = static_cast<idMD6AnimData*>(
        _aligned_malloc(sizeof(idMD6AnimData), 16));
    if (animData == nullptr) return;
    std::memset(animData, 0, sizeof(*animData));
    animData->totalSize = sizeof(*animData);
    animData->size = sizeof(*animData);
    animData->flags = idMD6AnimData::ANIM_FLAG_DEFAULTED;
    animData->numFrames = 1;
    animData->frameRate = 30;
    animData->startDelta[3] = 1.0f;
    animData->endDelta[3] = 1.0f;
    origWorldScale.Set(1.0f, 1.0f, 1.0f);
}

void idMD6Anim::LoadResource() {
    FreeData();
    if (fileSystem == nullptr) return;
    idStr binaryName = fileSystem->GeneratedPath(GetName());
    binaryName.SetFileExtension("bmd6anim");
    if (LoadBinary(binaryName.c_str())) return;
    if (LoadText(GetName(), nullptr)) WriteBinary(binaryName.c_str());
}

bool idMD6Anim::ReloadIfStale() {
    if (fileSystem == nullptr) return false;
    const unsigned int sourceTimestamp = fileSystem->GetTimestamp(
        GetName(), false);
    idStr settingsName(GetName());
    settingsName.SetFileExtension("md6settings");
    const unsigned int currentSettingsTimestamp = fileSystem->GetTimestamp(
        settingsName.c_str(), false);
    if (sourceTimestamp == timestamp &&
            currentSettingsTimestamp == settingsTimestamp) return false;
    LoadResource();
    return true;
}
