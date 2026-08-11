#pragma once

#include "game/entities/entity.h"

#include <cstdint>
#include <vector>

struct idEntityAnimCommandArgs {
    std::vector<const char*> arguments;
    int Argc() const { return static_cast<int>(arguments.size()); }
    const char* Argv(int index) const {
        return index >= 0 && index < Argc() ? arguments[index] : "";
    }
};

class idEntityAnimRecorder;

class idEntityAnimRecorderServices {
public:
    virtual ~idEntityAnimRecorderServices() = default;
    virtual bool HasValidAnimationStack(const idEntity& entity) const;
    virtual const char* GetAnimationDeclarationName(
        const idEntity& entity) const;
    virtual void BeginRecordAnimationStack(idEntity& entity);
    virtual void BeginPlaybackAnimationStack(idEntity& entity);
    virtual void StopBaseRecorder(idEntityAnimRecorder& recorder);
    virtual void SerializeBaseRecorder(idEntityAnimRecorder& recorder,
        int& gameTime, bool writing);
    virtual void ReadBaseFrames(idEntityAnimRecorder& recorder,
        int numFrames);
    virtual idEntity* FindEntityByNumber(int entityNumber) const;
    virtual void ReportWarning(const char* message);
    virtual void ReportError(const char* message);
    virtual void PrintUsage(const char* message);
};

class idEntityAnimRecorder {
public:
    enum blockType_t {
        ENTITY_BLOCK = 3,
        ENTITY_HEADER_BLOCK = 4,
        ENTITY_END_BLOCK = 5
    };
    enum fileMode_t {
        RECORDING_FILE_NONE = 0,
        RECORDING_FILE_WRITE,
        RECORDING_FILE_READ
    };

    idEntityAnimRecorder();
    virtual ~idEntityAnimRecorder() = default;
    static void SetServices(idEntityAnimRecorderServices* services);
    static idEntityAnimRecorderServices& Services();
    static idEntityAnimRecorder* GetInstance();
    static idEntityAnimRecorder* AllocInstance();

    virtual void Stop();
    virtual void ReadFrames(int numFrames);
    void RecordEntity(idEntity& entity);
    void PlaybackEntity(idEntity& entity);
    virtual void WriteHeaderBlock();
    virtual void Serialize(int& gameTime, bool writing);
    virtual bool ReadHeaderBlock();

    idQuat orientation;
    idVec3 position;
    int activeEntityNumber;
    idEntity* activeEntity;
    fileMode_t recordingFileMode;
    bool isPaused;
    int dataStart;
    std::vector<std::uint8_t> buffer;
    std::size_t cursor;
    idStr recordedDeclName;
};

void anim_recordEntity_f(const idEntityAnimCommandArgs& args);
void anim_playbackEntity_f(const idEntityAnimCommandArgs& args);
void anim_stop_f(const idEntityAnimCommandArgs& args);
void anim_pausePlayback_f(const idEntityAnimCommandArgs& args);
void anim_frameStepPlayback_f(const idEntityAnimCommandArgs& args);
void idEntityAnimHeaderCleanup();
