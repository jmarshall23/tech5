#include "models/skeletalanimation/md6anim.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6skel.h"
#include "models/skeletalanimation/md6util.h"

#include <algorithm>
#include <cstring>
#include <malloc.h>

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
    settings.useForwardTranslation = true;
    settings.useLeftTranslation = true;
    settings.useUpTranslation = true;
    settings.useRotation = true;
    return settings;
}

bool TokenEquals(const idToken& token, const char* text) {
    return idStr::Icmp(token.c_str(), text) == 0;
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

bool idMD6Anim::LoadText(const char* fileName,
        const float* errorToleranceOverride) {
    return textLoadCallback != nullptr &&
        textLoadCallback(this, fileName, errorToleranceOverride);
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
    if (skeleton != nullptr && skeleton->data != nullptr) {
        if (skeleton->data->numJoints > 0)
            animData->flags |= idMD6AnimData::ANIM_FLAG_HAS_JOINT_DATA;
        if (skeleton->data->numUserChannels > 0)
            animData->flags |= idMD6AnimData::ANIM_FLAG_HAS_USER_CHANNEL_DATA;
    }
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
