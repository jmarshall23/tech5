#include "sound/soundshader.h"

const idSoundShader* Decls_FindSoundShader(const char* name) {
    if (name == nullptr || name[0] == '\0') return nullptr;
    return static_cast<const idSoundShader*>(
        idSoundShader::resourceList.Load(name, true, false));
}

const idSoundShader* Decls_FindVoiceSoundShader(const char* name) {
    return Decls_FindSoundShader(name);
}

const char* Decls_VoiceSoundShaderName(const idSoundShader* shader) {
    return shader != nullptr ? shader->GetName() : "";
}

int Decls_VoiceSoundShaderMaxLength(const idSoundShader* shader) {
    return shader != nullptr ? shader->GetMaxLength() : 0;
}

unsigned int Decls_VoiceSoundShaderTimestamp(const idSoundShader* shader) {
    return shader != nullptr ? shader->GetDeclTimestamp() : 0;
}

unsigned int Decls_VoiceSoundShaderCRC(const idSoundShader* shader) {
    return shader != nullptr ? shader->md5Checksum : 0;
}

void Decls_FXSoundProperties(const idSoundShader* sound, bool& looping,
        int& durationMilliseconds, soundChannel_t& channel) {
    if (sound == nullptr) {
        looping = false;
        durationMilliseconds = 0;
        channel = SND_CHANNEL_ANY;
        return;
    }
    looping = (sound->parms.soundShaderFlags & SSF_LOOPING) != 0;
    durationMilliseconds = sound->GetMaxLength();
    channel = sound->parms.soundChannel;
}
