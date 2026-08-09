#include "gamelib/animstack/animrecorder.h"

#include <cstring>

bool GameLib_OpenAnimRecording(idAnimRecorder& recorder, bool read);
void GameLib_CloseAnimRecording(idAnimRecorder& recorder);
void GameLib_WriteAnimRecordingHeader(idAnimRecorder& recorder);
bool GameLib_ReadAnimRecordingHeader(idAnimRecorder& recorder);
void GameLib_SerializeAnimRecordingFrame(idAnimRecorder& recorder,
    int* gameTime, idGameTimeManager* manager, bool paused);
void GameLib_ReadAnimRecordingFrames(idAnimRecorder& recorder,
    int gameTime);
unsigned short GameLib_GetAnimationNetworkID(const idAnimStack& stack,
    const idMD6Anim* animation, const char*& typeName,
    const char*& objectName);
unsigned short GameLib_GetDeclarationNetworkID(
    const idSerializer& serializer, const idDecl* declaration,
    const char*& typeName, const char*& objectName);
const idMD6Anim* GameLib_ResolveAnimationNetworkID(
    const idAnimStack& stack, const idAnimRecorder::NameStruct_t& name);
const idResource* GameLib_ResolveDeclarationNetworkID(
    const idSerializer& serializer,
    const idAnimRecorder::NameStruct_t& name);

idAnimRecorder* idAnimRecorder::instance = nullptr;
idAnimRecorder::allocFunction_t idAnimRecorder::allocFunction =
    &idAnimRecorder::AllocInstance;

idAnimRecorder::idAnimRecorder()
    : buffer{}
    , networkIDDict(16)
    , cachedGameTime(0)
    , cachedMessageSize(0)
    , dataStart(0)
    , compressor(nullptr)
    , file(nullptr)
    , activeSerializer(nullptr)
    , activeAnimStack(nullptr)
    , recordingFileMode(RECORDING_FILE_CLOSED)
    , isPaused(false) {
}

idAnimRecorder::~idAnimRecorder() { Stop(); }

idAnimRecorder* idAnimRecorder::AllocInstance() {
    return new idAnimRecorder();
}

idAnimRecorder* idAnimRecorder::GetInstance() {
    if (instance == nullptr) instance = AllocInstance();
    return instance;
}

void idAnimRecorder::KillInstance() {
    delete instance;
    instance = nullptr;
}

void idAnimRecorder::ValidateBlock(const unsigned char expectedType) {
    if (buffer[0] != expectedType) {
        Stop();
    }
}

void idAnimRecorder::WriteHeaderBlock() {
    buffer[0] = RECORD_HEADER_BLOCK;
    GameLib_WriteAnimRecordingHeader(*this);
}

bool idAnimRecorder::ReadHeaderBlock() {
    ValidateBlock(RECORD_HEADER_BLOCK);
    return recordingFileMode == RECORDING_FILE_READ &&
        GameLib_ReadAnimRecordingHeader(*this);
}

bool idAnimRecorder::OpenFile(const bool read) {
    CloseFile();
    if (!GameLib_OpenAnimRecording(*this, read)) return false;
    recordingFileMode = read ? RECORDING_FILE_READ : RECORDING_FILE_WRITE;
    ValidateFile(read);
    return recordingFileMode != RECORDING_FILE_CLOSED;
}

void idAnimRecorder::CloseFile() {
    if (recordingFileMode != RECORDING_FILE_CLOSED)
        GameLib_CloseAnimRecording(*this);
    compressor = nullptr;
    file = nullptr;
    activeSerializer = nullptr;
    recordingFileMode = RECORDING_FILE_CLOSED;
}

void idAnimRecorder::ValidateFile(const bool read) {
    if (read) {
        if (!ReadHeaderBlock()) CloseFile();
    } else {
        WriteHeaderBlock();
    }
}

void idAnimRecorder::Stop() {
    CloseFile();
    activeAnimStack = nullptr;
    networkIDDict.Clear();
    cachedGameTime = 0;
    cachedMessageSize = 0;
    dataStart = 0;
    isPaused = false;
}

void idAnimRecorder::RecordAnimStack(idAnimStack& stack) {
    if (OpenFile(false)) activeAnimStack = &stack;
}

void idAnimRecorder::PlaybackAnimStack(idAnimStack& stack) {
    if (OpenFile(true)) activeAnimStack = &stack;
}

void idAnimRecorder::ReadFrames(const int gameTime) {
    if (recordingFileMode == RECORDING_FILE_READ)
        GameLib_ReadAnimRecordingFrames(*this, gameTime);
}

void idAnimRecorder::Serialize(int* const gameTime,
        idGameTimeManager* const manager, const bool paused) {
    if (recordingFileMode == RECORDING_FILE_CLOSED || gameTime == nullptr)
        return;
    isPaused = paused;
    cachedGameTime = *gameTime;
    GameLib_SerializeAnimRecordingFrame(*this, gameTime, manager, paused);
}

unsigned short idAnimRecorder::AddAnimNetworkID(
        const idAnimStack& stack, const idMD6Anim* const animation) {
    const char* typeName = nullptr;
    const char* objectName = nullptr;
    const unsigned short id = GameLib_GetAnimationNetworkID(stack,
        animation, typeName, objectName);
    for (int index = 0; index < networkIDDict.Num(); ++index)
        if (networkIDDict[index].first == id) return id;
    networkIDDict.Append(networkNamePair_t{id,
        NameStruct_t{typeName, objectName}});
    return id;
}

unsigned short idAnimRecorder::AddDeclNetworkID(
        const idSerializer& serializer, const idDecl* const declaration) {
    const char* typeName = nullptr;
    const char* objectName = nullptr;
    const unsigned short id = GameLib_GetDeclarationNetworkID(serializer,
        declaration, typeName, objectName);
    for (int index = 0; index < networkIDDict.Num(); ++index)
        if (networkIDDict[index].first == id) return id;
    networkIDDict.Append(networkNamePair_t{id,
        NameStruct_t{typeName, objectName}});
    return id;
}

const idMD6Anim* idAnimRecorder::SerializeAnimNetworkID(
        const idAnimStack& stack, const unsigned short networkID) {
    for (int index = 0; index < networkIDDict.Num(); ++index)
        if (networkIDDict[index].first == networkID)
            return GameLib_ResolveAnimationNetworkID(stack,
                networkIDDict[index].second);
    return nullptr;
}

const idResource* idAnimRecorder::SerializeDeclNetworkID(
        const idSerializer& serializer, const unsigned short networkID) {
    for (int index = 0; index < networkIDDict.Num(); ++index)
        if (networkIDDict[index].first == networkID)
            return GameLib_ResolveDeclarationNetworkID(serializer,
                networkIDDict[index].second);
    return nullptr;
}
