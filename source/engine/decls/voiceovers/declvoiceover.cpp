#include "decls/voiceovers/declvoiceover.h"

#include "idlib/text/str.h"

// Voice tracks are binary resources owned by the voice-track subsystem.  The
// recovered voice-over code only needs these three queries, so keeping the
// ownership boundary explicit lets this declaration compile before that
// subsystem's much larger implementation is materialized.
const char* Decls_VoiceTrackName(const idVoiceTrack* voiceTrack);
unsigned int Decls_VoiceTrackMemory(const idVoiceTrack* voiceTrack);
millisecond_t Decls_VoiceTrackApproximateDuration(
    const idVoiceTrack* voiceTrack);

idDeclInfoTemplate<idDeclVoiceOver> idDeclVoiceOver::resourceList(
    "voiceover", "idDeclVoiceOver", "vo");

idDeclVoiceOver::idDeclVoiceOver()
    : nextSampleToPlay(-1), tracks(0) {
}

idDeclVoiceOver::~idDeclVoiceOver() {
    tracks.Clear();
}

idDeclInfo* idDeclVoiceOver::GetDeclInfo() const {
    return &resourceList;
}

unsigned int idDeclVoiceOver::Size() const {
    unsigned int memory = static_cast<unsigned int>(
        sizeof(idDeclVoiceOver) + tracks.NumAllocated() * sizeof(tracks[0]));
    for (int index = 0; index < tracks.Num(); ++index) {
        if (tracks[index] != nullptr) {
            memory += Decls_VoiceTrackMemory(tracks[index]) - 292u;
        }
    }
    return memory;
}

const idVoiceTrack* idDeclVoiceOver::GetTrack(const int index) const {
    return index >= 0 && index < tracks.Num() ? tracks[index] : nullptr;
}

millisecond_t idDeclVoiceOver::GetMaxLength() const {
    millisecond_t maximum(0);
    for (int index = 0; index < tracks.Num(); ++index) {
        if (tracks[index] == nullptr) continue;
        const millisecond_t duration =
            Decls_VoiceTrackApproximateDuration(tracks[index]);
        if (duration > maximum) maximum = duration;
    }
    return maximum;
}

bool idDeclVoiceOver::AddTrack(idVoiceTrack* const voiceTrack) {
    if (voiceTrack == nullptr) return false;

    const char* const name = Decls_VoiceTrackName(voiceTrack);
    for (int index = 0; index < tracks.Num(); ++index) {
        if (tracks[index] != nullptr
            && idStr::Icmp(Decls_VoiceTrackName(tracks[index]), name) == 0) {
            return false;
        }
    }

    return tracks.Append(voiceTrack) >= 0;
}
