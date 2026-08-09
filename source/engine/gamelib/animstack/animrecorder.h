#pragma once

#include "idlib/containers/array.h"
#include "idlib/containers/list.h"
#include "idlib/containers/pair.h"

class idAnimStack;
class idCompressor;
class idDecl;
class idFile;
class idGameTimeManager;
class idMD6Anim;
class idResource;
class idSerializer;

class idAnimRecorder {
public:
    enum blockType_t : int {
        RECORD_HEADER_BLOCK = 0,
        ANIM_STACK_BLOCK = 1,
        INVALID_BLOCK = 2
    };
    enum recordingFileMode_t : int {
        RECORDING_FILE_CLOSED = 0,
        RECORDING_FILE_READ = 1,
        RECORDING_FILE_WRITE = 2
    };
    struct NameStruct_t {
        const char* typeName;
        const char* objectName;
    };
    using networkNamePair_t = idPair<unsigned short, NameStruct_t>;
    using allocFunction_t = idAnimRecorder* (*)();

    idAnimRecorder();
    virtual void Serialize(int* gameTime, idGameTimeManager* manager,
        bool paused);
    virtual void Stop();
    virtual void ReadFrames(int gameTime);
    virtual ~idAnimRecorder();
    virtual void WriteHeaderBlock();
    virtual bool ReadHeaderBlock();

    static idAnimRecorder* AllocInstance();
    static void KillInstance();
    static idAnimRecorder* GetInstance();

    void RecordAnimStack(idAnimStack& stack);
    void PlaybackAnimStack(idAnimStack& stack);
    unsigned short AddAnimNetworkID(const idAnimStack& stack,
        const idMD6Anim* animation);
    unsigned short AddDeclNetworkID(const idSerializer& serializer,
        const idDecl* declaration);
    const idMD6Anim* SerializeAnimNetworkID(const idAnimStack& stack,
        unsigned short networkID);
    const idResource* SerializeDeclNetworkID(const idSerializer& serializer,
        unsigned short networkID);

    idArray<unsigned char, 1282> buffer;
    idList<networkNamePair_t, 5> networkIDDict;
    int cachedGameTime;
    int cachedMessageSize;
    int dataStart;
    idCompressor* compressor;
    idFile* file;
    idSerializer* activeSerializer;
    idAnimStack* activeAnimStack;
    recordingFileMode_t recordingFileMode;
    bool isPaused;

private:
    void ValidateBlock(unsigned char expectedType);
    void CloseFile();
    bool OpenFile(bool read);
    void ValidateFile(bool read);

    static idAnimRecorder* instance;
    static allocFunction_t allocFunction;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimRecorder::NameStruct_t) == 8,
    "Recovered recorder name ABI changed");
static_assert(sizeof(idAnimRecorder::networkNamePair_t) == 12,
    "Recovered recorder dictionary-pair ABI changed");
static_assert(sizeof(idAnimRecorder) == 1340,
    "Recovered idAnimRecorder ABI changed");
#endif
