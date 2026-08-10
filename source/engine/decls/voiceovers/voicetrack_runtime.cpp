#include "decls/voiceovers/voicetrack.h"

#include "idlib/filesystem/filesystem.h"

#include <cstring>

unsigned int Decls_VoiceTrackFileTimestamp(const char* fileName) {
    return fileSystem != nullptr && fileName != nullptr
        ? fileSystem->GetTimestamp(fileName, false) : 0;
}

bool Decls_ReadVoiceTrackText(const char* fileName, idStr& text,
        unsigned int& timestamp) {
    text.Clear();
    timestamp = 0;
    if (fileSystem == nullptr || fileName == nullptr) return false;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, &timestamp);
    if (buffer == nullptr || length < 0) return false;
    const char* bytes = static_cast<const char*>(buffer);
    for (int index = 0; index < length; ++index) text.Append(bytes[index]);
    fileSystem->FreeFile(buffer);
    return true;
}

bool Decls_WriteVoiceTrackText(const char* fileName, const char* text,
        int length) {
    if (fileSystem == nullptr || fileName == nullptr || text == nullptr)
        return false;
    if (length < 0) length = static_cast<int>(std::strlen(text));
    return fileSystem->WriteFile(fileName, text,
        static_cast<unsigned int>(length), FSPATH_BASE)
        == static_cast<unsigned int>(length);
}

idFile* Decls_OpenVoiceTrackBinaryRead(const char* fileName) {
    return fileSystem != nullptr && fileName != nullptr
        ? fileSystem->OpenFileRead(fileName, false, true) : nullptr;
}

idFile* Decls_OpenVoiceTrackBinaryWrite(const char* fileName) {
    return fileSystem != nullptr && fileName != nullptr
        ? fileSystem->OpenFileWrite(fileName, FSPATH_BASE) : nullptr;
}

void Decls_CloseVoiceTrackFile(idFile* file) {
    delete file;
}

bool Decls_LoadVoiceTrackResource(idVoiceTrack& track) {
    track.voiceEventManager.FreeEvents(
        reinterpret_cast<idList<vtrEventHandle_t, 5>&>(track.events));
    delete[] track.frameRefs;
    track.frameRefs = nullptr;
    track.numFrameRefs = 0;

    char localizedName[256]{};
    const char* sourceName = idResource::GetLocalizedName(track.GetName(),
        localizedName, sizeof(localizedName));
    if (sourceName == nullptr || sourceName[0] == '\0')
        sourceName = track.GetName();

    char binaryName[256]{};
    bool hasBinaryName = fileSystem != nullptr
        && fileSystem->FixLongFilename("generated", "bvtr", sourceName,
            binaryName, sizeof(binaryName));
    const unsigned int timestamp = Decls_VoiceTrackFileTimestamp(sourceName);
    if (hasBinaryName && track.LoadBinary(binaryName, timestamp)) return true;
    if (!track.LoadText(sourceName)) {
        track.SetResourceError("Voicetrack '%s' does not exist.", sourceName);
        return false;
    }
    if (hasBinaryName) track.WriteBinary(binaryName);
    return true;
}
