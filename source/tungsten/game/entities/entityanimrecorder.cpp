#include "game/entities/entityanimrecorder.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace {
idEntityAnimRecorderServices defaultRecorderServices;
idEntityAnimRecorderServices* recorderServices = &defaultRecorderServices;
idEntityAnimRecorder* recorderInstance = nullptr;
constexpr int ENTITY_RECORDER_VERSION = 1;

template<class Type>
void AppendValue(std::vector<std::uint8_t>& buffer, const Type& value) {
    const std::uint8_t* bytes = reinterpret_cast<const std::uint8_t*>(&value);
    buffer.insert(buffer.end(), bytes, bytes + sizeof(Type));
}

template<class Type>
bool ReadValue(const std::vector<std::uint8_t>& buffer,
        std::size_t& cursor, Type& value) {
    if (cursor + sizeof(Type) > buffer.size()) return false;
    std::memcpy(&value, buffer.data() + cursor, sizeof(Type));
    cursor += sizeof(Type);
    return true;
}

idQuat MatrixToQuat(const idMat3& matrix) {
    const float trace = matrix[0].x + matrix[1].y + matrix[2].z;
    idQuat result;
    if (trace > 0.0f) {
        const float scale = std::sqrt(trace + 1.0f) * 2.0f;
        result.w = 0.25f * scale;
        result.x = (matrix[2].y - matrix[1].z) / scale;
        result.y = (matrix[0].z - matrix[2].x) / scale;
        result.z = (matrix[1].x - matrix[0].y) / scale;
    } else if (matrix[0].x > matrix[1].y
            && matrix[0].x > matrix[2].z) {
        const float scale = std::sqrt(1.0f + matrix[0].x
            - matrix[1].y - matrix[2].z) * 2.0f;
        result.w = (matrix[2].y - matrix[1].z) / scale;
        result.x = 0.25f * scale;
        result.y = (matrix[0].y + matrix[1].x) / scale;
        result.z = (matrix[0].z + matrix[2].x) / scale;
    } else if (matrix[1].y > matrix[2].z) {
        const float scale = std::sqrt(1.0f + matrix[1].y
            - matrix[0].x - matrix[2].z) * 2.0f;
        result.w = (matrix[0].z - matrix[2].x) / scale;
        result.x = (matrix[0].y + matrix[1].x) / scale;
        result.y = 0.25f * scale;
        result.z = (matrix[1].z + matrix[2].y) / scale;
    } else {
        const float scale = std::sqrt(1.0f + matrix[2].z
            - matrix[0].x - matrix[1].y) * 2.0f;
        result.w = (matrix[1].x - matrix[0].y) / scale;
        result.x = (matrix[0].z + matrix[2].x) / scale;
        result.y = (matrix[1].z + matrix[2].y) / scale;
        result.z = 0.25f * scale;
    }
    result.Normalize();
    return result;
}
} // namespace

bool idEntityAnimRecorderServices::HasValidAnimationStack(
        const idEntity&) const { return false; }
const char* idEntityAnimRecorderServices::GetAnimationDeclarationName(
        const idEntity&) const { return ""; }
void idEntityAnimRecorderServices::BeginRecordAnimationStack(idEntity&) {}
void idEntityAnimRecorderServices::BeginPlaybackAnimationStack(idEntity&) {}
void idEntityAnimRecorderServices::StopBaseRecorder(
        idEntityAnimRecorder&) {}
void idEntityAnimRecorderServices::SerializeBaseRecorder(
        idEntityAnimRecorder&, int&, bool) {}
void idEntityAnimRecorderServices::ReadBaseFrames(
        idEntityAnimRecorder&, int) {}
idEntity* idEntityAnimRecorderServices::FindEntityByNumber(int) const {
    return nullptr;
}
void idEntityAnimRecorderServices::ReportWarning(const char*) {}
void idEntityAnimRecorderServices::ReportError(const char*) {}
void idEntityAnimRecorderServices::PrintUsage(const char*) {}

idEntityAnimRecorder::idEntityAnimRecorder()
    : orientation(0.0f, 0.0f, 0.0f, 1.0f),
      position(0.0f, 0.0f, 0.0f), activeEntityNumber(-1),
      activeEntity(nullptr), recordingFileMode(RECORDING_FILE_NONE),
      isPaused(false), dataStart(0), buffer(), cursor(0),
      recordedDeclName() {}

void idEntityAnimRecorder::SetServices(
        idEntityAnimRecorderServices* const services) {
    recorderServices = services == nullptr ? &defaultRecorderServices : services;
}

idEntityAnimRecorderServices& idEntityAnimRecorder::Services() {
    return *recorderServices;
}

idEntityAnimRecorder* idEntityAnimRecorder::GetInstance() {
    if (recorderInstance == nullptr) recorderInstance = AllocInstance();
    return recorderInstance;
}

// Retail: 0x82C46208 ?Stop@idEntityAnimRecorder@@UAAXXZ
void idEntityAnimRecorder::Stop() {
    Services().StopBaseRecorder(*this);
    activeEntityNumber = -1;
    activeEntity = nullptr;
    recordingFileMode = RECORDING_FILE_NONE;
    isPaused = false;
}

// Retail: 0x82C46248 ?ReadFrames@idEntityAnimRecorder@@UAAXH@Z
void idEntityAnimRecorder::ReadFrames(const int numFrames) {
    for (int frame = 0; frame < numFrames; ++frame) {
        std::uint8_t block = 0;
        if (!ReadValue(buffer, cursor, block) || block != ENTITY_BLOCK
                || !ReadValue(buffer, cursor, orientation)
                || !ReadValue(buffer, cursor, position)
                || !ReadValue(buffer, cursor, block)
                || block != ENTITY_END_BLOCK) {
            Services().ReportWarning("invalid entity animation frame block");
            Stop();
            return;
        }
        Services().ReadBaseFrames(*this, 1);
    }
}

// Retail: 0x82C462E8 ?RecordEntity@idEntityAnimRecorder@@QAAXAAVidEntity@@@Z
void idEntityAnimRecorder::RecordEntity(idEntity& entity) {
    if (!Services().HasValidAnimationStack(entity)) {
        Services().ReportWarning("record entity has no valid MD6 animation stack");
        Stop();
        return;
    }
    activeEntity = &entity;
    activeEntityNumber = entity.entityNumber;
    recordingFileMode = RECORDING_FILE_WRITE;
    buffer.clear();
    cursor = 0;
    Services().BeginRecordAnimationStack(entity);
    WriteHeaderBlock();
}

// Retail: 0x82C463B0 ?PlaybackEntity@idEntityAnimRecorder@@QAAXAAVidEntity@@@Z
void idEntityAnimRecorder::PlaybackEntity(idEntity& entity) {
    if (!Services().HasValidAnimationStack(entity)) {
        Services().ReportWarning("playback entity has no valid MD6 animation stack");
        Stop();
        return;
    }
    activeEntity = &entity;
    activeEntityNumber = entity.entityNumber;
    recordingFileMode = RECORDING_FILE_READ;
    cursor = 0;
    Services().BeginPlaybackAnimationStack(entity);
    if (!ReadHeaderBlock()) Stop();
}

// Retail: 0x82C46480 ?WriteHeaderBlock@idEntityAnimRecorder@@MAAXXZ
void idEntityAnimRecorder::WriteHeaderBlock() {
    if (activeEntity == nullptr) {
        Services().ReportError("cannot write entity recorder header without an entity");
        return;
    }
    const char* declaration = Services().GetAnimationDeclarationName(
        *activeEntity);
    if (declaration == nullptr || *declaration == '\0') {
        Services().ReportError("cannot write entity recorder header without an MD6 declaration");
        return;
    }
    recordedDeclName = declaration;
    const std::uint8_t block = ENTITY_HEADER_BLOCK;
    AppendValue(buffer, block);
    AppendValue(buffer, ENTITY_RECORDER_VERSION);
    const std::uint32_t length = static_cast<std::uint32_t>(
        std::strlen(declaration) + 1);
    AppendValue(buffer, length);
    buffer.insert(buffer.end(), declaration, declaration + length);
    const std::uint32_t endMarker = length + 4;
    AppendValue(buffer, endMarker);
    dataStart = static_cast<int>(buffer.size());
}

// Retail: 0x82C46618 $LN45_1
void idEntityAnimHeaderCleanup() {}

// Retail: 0x82C46640 ?Serialize@idEntityAnimRecorder@@UAAXAAHAAVidGameTimeManager@@_N@Z
void idEntityAnimRecorder::Serialize(int& gameTime, const bool writing) {
    if (activeEntity == nullptr) {
        Services().ReportError("cannot serialize entity animation without an entity");
        return;
    }
    if (writing) {
        idMat3 axis;
        activeEntity->GetModelTransform(position, axis);
        orientation = MatrixToQuat(axis);
        const std::uint8_t startBlock = ENTITY_BLOCK;
        const std::uint8_t endBlock = ENTITY_END_BLOCK;
        AppendValue(buffer, startBlock);
        AppendValue(buffer, orientation);
        AppendValue(buffer, position);
        AppendValue(buffer, endBlock);
    } else {
        ReadFrames(1);
    }
    Services().SerializeBaseRecorder(*this, gameTime, writing);
    if (!writing && activeEntity != nullptr) {
        activeEntity->SetAxis(orientation.ToMat3());
        activeEntity->SetOrigin(position);
    }
}

// Retail: 0x82C467B8 ?anim_recordEntity_f@@YAXABVidCmdArgs@@@Z
void anim_recordEntity_f(const idEntityAnimCommandArgs& args) {
    if (args.Argc() != 2) {
        idEntityAnimRecorder::Services().PrintUsage(
            "USAGE: anim_recordEntity <entity number>");
        return;
    }
    idEntity* const entity = idEntityAnimRecorder::Services()
        .FindEntityByNumber(std::atoi(args.Argv(1)));
    if (entity == nullptr) idEntityAnimRecorder::GetInstance()->Stop();
    else idEntityAnimRecorder::GetInstance()->RecordEntity(*entity);
}

// Retail: 0x82C468F8 ?anim_playbackEntity_f@@YAXABVidCmdArgs@@@Z
void anim_playbackEntity_f(const idEntityAnimCommandArgs& args) {
    if (args.Argc() != 2) {
        idEntityAnimRecorder::Services().PrintUsage(
            "USAGE: anim_playbackEntity <entity number>");
        return;
    }
    idEntity* const entity = idEntityAnimRecorder::Services()
        .FindEntityByNumber(std::atoi(args.Argv(1)));
    if (entity == nullptr) idEntityAnimRecorder::GetInstance()->Stop();
    else idEntityAnimRecorder::GetInstance()->PlaybackEntity(*entity);
}

// Retail: 0x82C46A38 ?anim_stop_f@@YAXABVidCmdArgs@@@Z
void anim_stop_f(const idEntityAnimCommandArgs& args) {
    if (args.Argc() != 1) {
        idEntityAnimRecorder::Services().PrintUsage("USAGE: anim_stop");
        return;
    }
    idEntityAnimRecorder::GetInstance()->Stop();
}

// Retail: 0x82C46AC0 ?anim_pausePlayback_f@@YAXABVidCmdArgs@@@Z
void anim_pausePlayback_f(const idEntityAnimCommandArgs& args) {
    if (args.Argc() != 1) {
        idEntityAnimRecorder::Services().PrintUsage(
            "USAGE: anim_pausePlayback");
        return;
    }
    idEntityAnimRecorder* const recorder = idEntityAnimRecorder::GetInstance();
    recorder->isPaused = !recorder->isPaused;
}

// Retail: 0x82C46B48 ?anim_frameStepPlayback_f@@YAXABVidCmdArgs@@@Z
void anim_frameStepPlayback_f(const idEntityAnimCommandArgs& args) {
    if (args.Argc() > 2) {
        idEntityAnimRecorder::Services().PrintUsage(
            "USAGE: anim_frameStepPlayback [number of frames]");
        return;
    }
    idEntityAnimRecorder* const recorder = idEntityAnimRecorder::GetInstance();
    if (recorder->recordingFileMode != idEntityAnimRecorder::RECORDING_FILE_READ) {
        return;
    }
    const int frames = args.Argc() == 1 ? 1 : std::atoi(args.Argv(1));
    recorder->isPaused = true;
    recorder->ReadFrames(std::max(0, frames));
}

// Retail: 0x82C46C40 ?ReadHeaderBlock@idEntityAnimRecorder@@MAA_NXZ
bool idEntityAnimRecorder::ReadHeaderBlock() {
    std::uint8_t block = 0;
    int version = -1;
    std::uint32_t length = 0;
    if (!ReadValue(buffer, cursor, block) || block != ENTITY_HEADER_BLOCK) {
        Services().ReportWarning("wrong entity recorder header block type");
        return false;
    }
    if (!ReadValue(buffer, cursor, version)
            || version != ENTITY_RECORDER_VERSION) {
        Services().ReportWarning("wrong entity recorder version");
        return false;
    }
    if (!ReadValue(buffer, cursor, length) || length == 0
            || cursor + length > buffer.size()) {
        Services().ReportWarning("invalid entity recorder declaration length");
        return false;
    }
    const char* const recorded = reinterpret_cast<const char*>(
        buffer.data() + cursor);
    const char* const expected = activeEntity != nullptr
        ? Services().GetAnimationDeclarationName(*activeEntity) : "";
    if (recorded[length - 1] != '\0' || expected == nullptr
            || std::strcmp(recorded, expected) != 0) {
        Services().ReportWarning("entity recorder MD6 declaration mismatch");
        return false;
    }
    recordedDeclName = recorded;
    cursor += length;
    std::uint32_t endMarker = 0;
    if (!ReadValue(buffer, cursor, endMarker)
            || endMarker != length + 4) {
        Services().ReportWarning("wrong entity recorder header end marker");
        return false;
    }
    dataStart = static_cast<int>(cursor);
    return true;
}

// Retail: 0x82C46E98 ?AllocInstance@idEntityAnimRecorder@@KAPAVidAnimRecorder@@XZ
idEntityAnimRecorder* idEntityAnimRecorder::AllocInstance() {
    return new idEntityAnimRecorder();
}
