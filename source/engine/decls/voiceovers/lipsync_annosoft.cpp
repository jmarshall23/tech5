#include "decls/voiceovers/lipsync_annosoft.h"

#include "decls/voiceovers/declvisemeset.h"
#include "decls/voiceovers/lexerutf8.h"
#include "decls/voiceovers/voicetrack.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>

bool Decls_ReadLipsyncIntermediate(const char* fileName, idStr& text);
bool Decls_WriteLipsyncAnimation(const char* fileName,
    const idDeclVisemeSet& visemeSet, const float* weights,
    int numFrames, int numVisemes);

namespace {

std::int16_t DurationFor(const idPhonemeTrack_Annosoft::idPhonemeEvent& event) {
    return static_cast<std::int16_t>((std::max)(0,
        (std::min)(32767, event.endMS - event.startMS)));
}

float SampleWeight(const idPhonemeTrack_Annosoft::idPhonemeEvent& event,
        const int timeMS) {
    if (event.numWeights <= 0 || event.weights == nullptr) return 0.0f;
    int before = -1, after = -1;
    for (int index = 0; index < event.numWeights; ++index) {
        if (event.weights[index].startMS <= timeMS
            && (before < 0 || event.weights[index].startMS
                > event.weights[before].startMS)) before = index;
        if (event.weights[index].startMS >= timeMS
            && (after < 0 || event.weights[index].startMS
                < event.weights[after].startMS)) after = index;
    }
    if (before < 0) return after >= 0 ? event.weights[after].weight : 0.0f;
    if (after < 0 || before == after) return event.weights[before].weight;
    const int span = event.weights[after].startMS - event.weights[before].startMS;
    if (span <= 0) return event.weights[before].weight;
    const float fraction = static_cast<float>(timeMS
        - event.weights[before].startMS) / span;
    return event.weights[before].weight
        + fraction * (event.weights[after].weight - event.weights[before].weight);
}

} // namespace

idPhonemeTrack_Annosoft::idPhonemeEvent::idPhonemeEvent()
    : type(-1), exType(EXPHONEME_MAX), startMS(0), endMS(0),
      numWeights(0), weightPadding(0), weights(nullptr), text() {}
idPhonemeTrack_Annosoft::idPhonemeEvent::idPhonemeEvent(
        const idPhonemeEvent& other) : idPhonemeEvent() { *this = other; }
idPhonemeTrack_Annosoft::idPhonemeEvent::~idPhonemeEvent() { delete[] weights; }
idPhonemeTrack_Annosoft::idPhonemeEvent&
idPhonemeTrack_Annosoft::idPhonemeEvent::operator=(
        const idPhonemeEvent& other) {
    if (this == &other) return *this;
    weight_t* replacement = other.numWeights > 0
        ? new (std::nothrow) weight_t[other.numWeights] : nullptr;
    if (replacement != nullptr && other.weights != nullptr)
        std::memcpy(replacement, other.weights,
            other.numWeights * sizeof(weight_t));
    delete[] weights;
    type = other.type; exType = other.exType; startMS = other.startMS;
    endMS = other.endMS; numWeights = other.numWeights;
    weights = replacement; text = other.text;
    return *this;
}

idPhonemeTrack_Annosoft::idPhonemeTrack_Annosoft() : phonemes(0) {}
idPhonemeTrack_Annosoft::~idPhonemeTrack_Annosoft() = default;

bool idPhonemeTrack_Annosoft::Load(const idDeclVisemeSet* const visemeSet,
        const char* const fileName) {
    idStr source;
    if (!Decls_ReadLipsyncIntermediate(fileName, source)) return false;
    idLexerUTF8 lexer(LEXFL_NOSTRINGS | LEXFL_REPORT_MULTIPLE_ERRORS);
    lexer.LoadMemory(reinterpret_cast<const std::uint8_t*>(source.c_str()),
        source.Length(), fileName);
    return Load(visemeSet, lexer);
}

bool idPhonemeTrack_Annosoft::Load(const idDeclVisemeSet* const visemeSet,
        idLexerUTF8& lexer) {
    phonemes.Clear();
    if (visemeSet == nullptr || !lexer.CheckTokenString("phonemes")) {
        lexer.Error("Unsupported format");
        return false;
    }
    // Annosoft only needs the no-strings mode while recognizing the format
    // marker.  The recovered loader clears this bit before reading quoted
    // word and punctuation records.
    lexer.flags &= ~LEXFL_NOSTRINGS;
    if (!lexer.ExpectTokenString("{")) return false;
    idToken token;
    while (lexer.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Cmp(token.c_str(), "env") == 0) {
            if (!lexer.ExpectTokenType(TT_NAME, 0, token)) return false;
            if (idStr::Cmp(token.c_str(), "x") == 0) {
                lexer.SkipBracedSection(true);
                continue;
            }
            idPhonemeEvent* const event = phonemes.Alloc();
            if (event == nullptr) return false;
            event->type = visemeSet->PhonemeForName(token.c_str());
            event->exType = EXPHONEME_PHONEME;
            if (!lexer.ExpectTokenString("{")
                || !lexer.ExpectTokenString("start")) return false;
            event->startMS = lexer.ParseInt();
            lexer.ExpectTokenString("end"); event->endMS = lexer.ParseInt();
            lexer.ExpectTokenString("weights");
            event->numWeights = static_cast<std::int16_t>((std::max)(0,
                (std::min)(32767, lexer.ParseInt())));
            if (!lexer.ExpectTokenString("{")) return false;
            event->weights = event->numWeights > 0
                ? new (std::nothrow) weight_t[event->numWeights] : nullptr;
            for (int index = 0; index < event->numWeights; ++index) {
                event->weights[index].startMS = lexer.ParseInt();
                event->weights[index].endMS = lexer.ParseInt();
                event->weights[index].weight = lexer.ParseFloat();
            }
            lexer.ExpectTokenString("}");
            lexer.ExpectTokenString("}");
        } else if (idStr::Cmp(token.c_str(), "word") == 0
                || idStr::Cmp(token.c_str(), "punct") == 0) {
            const extendedPhoneme_t extended = idStr::Cmp(token.c_str(), "word") == 0
                ? EXPHONEME_WORD : EXPHONEME_PUNCTUATION;
            if (!lexer.ExpectTokenType(TT_STRING, 0, token)
                || !lexer.ExpectTokenString("{")) return false;
            idPhonemeEvent* const event = phonemes.Alloc();
            if (event == nullptr) return false;
            event->exType = extended;
            event->text = token.c_str();
            lexer.ExpectTokenString("start"); event->startMS = lexer.ParseInt();
            lexer.ExpectTokenString("end"); event->endMS = lexer.ParseInt();
            lexer.ExpectTokenString("}");
        } else {
            // Unknown Annosoft records are self-delimiting braced blocks.
            if (lexer.CheckTokenString("{")) lexer.SkipBracedSection(false);
        }
    }
    return !lexer.HadError();
}

int idPhonemeTrack_Annosoft::GetNumFrames() const {
    int endMS = 0;
    for (int index = 0; index < phonemes.Num(); ++index)
        if (phonemes[index].exType == EXPHONEME_PHONEME)
            endMS = (std::max)(endMS, phonemes[index].endMS);
    return 30 * endMS / 1000;
}

bool idPhonemeTrack_Annosoft::GetVoiceTrack(idVoiceTrack& output,
        int) const {
    output.FreeVisemeEvents(true);
    output.rebuildFrameRefs = false;
    const idDeclVisemeSet* const visemeSet = output.declVisemeSet;
    if (visemeSet == nullptr) return false;

    for (int index = 0; index < phonemes.Num(); ++index) {
        const idPhonemeEvent& source = phonemes[index];
        vtrEventHandle_t handle;
        if (source.exType == EXPHONEME_WORD) {
            idVoiceTextEvent* const event = static_cast<idVoiceTextEvent*>(
                output.AllocEvent(VOICEEVENT_TEXT, handle));
            if (event == nullptr) continue;
            event->text = source.text; event->startMS = source.startMS;
            event->durationMS = DurationFor(source);
        } else if (source.exType == EXPHONEME_PUNCTUATION) {
            idVoicePunctuationEvent* const event =
                static_cast<idVoicePunctuationEvent*>(
                    output.AllocEvent(VOICEEVENT_PUNCTUATION, handle));
            if (event == nullptr) continue;
            event->punctuation = source.text.Length() ? source.text.c_str()[0] : 0;
            event->startMS = source.startMS; event->durationMS = DurationFor(source);
        } else if (source.exType == EXPHONEME_PHONEME
                && source.type >= 0 && source.type < visemeSet->phonemes.Num()) {
            const idPhoneme& phoneme = visemeSet->phonemes[source.type];
            if (phoneme.viseme < 0 || phoneme.viseme >= visemeSet->visemes.Num()) continue;
            idViseme_Simple* const event = static_cast<idViseme_Simple*>(
                output.AllocEvent(VOICEEVENT_VISEME_SIMPLE, handle));
            if (event == nullptr) continue;
            const int adjustedStart = 16 * ((source.startMS + phoneme.timeOffsetMS) / 16);
            event->startMS = adjustedStart;
            event->durationMS = static_cast<std::int16_t>((std::max)(0,
                (std::min)(32767, static_cast<int>((source.endMS - adjustedStart)
                    * phoneme.durationScale))));
            event->visemeType = static_cast<std::uint8_t>(
                visemeSet->visemes[phoneme.viseme].viseme);
            int peakIndex = -1;
            for (int weight = 0; weight < source.numWeights; ++weight)
                if (peakIndex < 0 || source.weights[weight].weight
                    > source.weights[peakIndex].weight) peakIndex = weight;
            if (peakIndex >= 0) {
                event->peakTimeMS = static_cast<std::uint16_t>((std::max)(0,
                    (std::min)(65535, source.weights[peakIndex].startMS
                        - adjustedStart)));
                const float scaled = source.weights[peakIndex].weight
                    * phoneme.weightScale;
                event->peakWeight = static_cast<std::uint8_t>((std::max)(0,
                    (std::min)(255, static_cast<int>(scaled * 255.0f))));
            }
        }
    }
    output.OffsetVisemeEvents(idVoiceTrack::EVENTOFFSET_FORWARDS);
    output.MergeVisemes();
    output.rebuildFrameRefs = true;
    output.BuildFrameRefs();
    return true;
}

bool idPhonemeTrack_Annosoft::GenerateAnimation(const char* const fileName,
        const idDeclVisemeSet* const visemeSet) const {
    if (fileName == nullptr || visemeSet == nullptr) return false;
    const int frames = GetNumFrames();
    const int visemes = visemeSet->visemes.Num();
    idList<float, 32> channelWeights(64);
    channelWeights.SetNum(frames * visemes);
    for (int index = 0; index < channelWeights.Num(); ++index)
        channelWeights[index] = 0.0f;
    for (int eventIndex = 0; eventIndex < phonemes.Num(); ++eventIndex) {
        const idPhonemeEvent& event = phonemes[eventIndex];
        if (event.exType != EXPHONEME_PHONEME || event.type < 0
            || event.type >= visemeSet->phonemes.Num()) continue;
        const int viseme = visemeSet->phonemes[event.type].viseme;
        if (viseme < 0 || viseme >= visemes) continue;
        for (int frame = 0; frame < frames; ++frame) {
            const int time = frame * 1000 / 30;
            channelWeights[viseme * frames + frame] = (std::max)(
                channelWeights[viseme * frames + frame],
                (std::max)(0.0f, SampleWeight(event, time)));
        }
    }
    return Decls_WriteLipsyncAnimation(fileName, *visemeSet,
        channelWeights.Ptr(), frames, visemes);
}

const char* Lipsync_GetDictFileName(const char* const language) {
    static idStr path;
    path.Format("lipsync/%s.dic", language != nullptr ? language : "");
    return path.c_str();
}

const char* Lipsync_IntermediateFilePathFromSampleName(
        const char* const sampleName, idStr& filePath) {
    filePath = sampleName != nullptr ? sampleName : "";
    filePath.StripFileExtension();
    filePath.SetFileExtension("anno");
    return filePath.c_str();
}

bool ConvertPhonemesToAnim(const char* const inputFile,
        const idDeclVisemeSet* const visemeSet) {
    if (inputFile == nullptr || visemeSet == nullptr) return false;
    idPhonemeTrack_Annosoft track;
    if (!track.Load(visemeSet, inputFile)) return false;
    idStr output(inputFile);
    output.SetFileExtension("md6anim");
    return track.GenerateAnimation(output.c_str(), visemeSet);
}

bool Decls_ReadLipsyncIntermediate(const char* fileName, idStr& text) {
    text.Clear();
    if (fileSystem == nullptr || fileName == nullptr) return false;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(fileName, &buffer, nullptr);
    if (buffer == nullptr || length < 0) return false;
    const char* bytes = static_cast<const char*>(buffer);
    for (int index = 0; index < length; ++index) text.Append(bytes[index]);
    fileSystem->FreeFile(buffer);
    return true;
}

bool Decls_WriteLipsyncAnimation(const char* fileName,
        const idDeclVisemeSet& visemeSet, const float* weights,
        int numFrames, int numVisemes) {
    if (fileSystem == nullptr || fileName == nullptr || weights == nullptr
            || numFrames < 0 || numVisemes < 0) return false;
    idFile* file = fileSystem->OpenFileWrite(fileName, FSPATH_BASE);
    if (file == nullptr) return false;
    file->Printf("MD6 7\ninit {\n");
    file->Printf("\tcommandLine \"-ex anim -startframe 0 -endframe %i -framerate 30.000000 -errorTolerance 0.600000\"\n",
        (std::max)(0, numFrames - 1));
    file->Printf("\tsourceAnim \"\"\n\tsubtractiveAnim \"\"\n");
    file->Printf("\trotationMask \"\"\n\tscaleMask \"\"\n\ttranslationMask \"\"\n");
    file->Printf("\tskeletonName \"\"\n\tmeshName \"\"\n");
    file->Printf("\tnumFrames %i\n\tframeRate 30\n\tnumJoints 0\n",
        numFrames);
    file->Printf("\tnumUserChannels %i\n", numVisemes);
    file->Printf("\ttranslatedBounds ( 0 0 0 ) ( 0 0 0 )\n");
    file->Printf("\tnormalizedBounds ( 0 0 0 ) ( 0 0 0 )\n");
    file->Printf("\terrorTolerance 0.600000\n}\n\nflags {\n}\n\njoints {\n}\n\n");
    file->Printf("userChannels {\n");
    for (int index = 0; index < numVisemes; ++index) {
        const char* name = index < visemeSet.visemes.Num()
            ? visemeSet.visemes[index].name.c_str() : "";
        file->Printf("\t\"%s\"\n", name);
    }
    file->Printf("}\n\nrotationMask {\n}\n\nscaleMask {\n}\n\ntranslationMask {\n}\n\nframes {\n}\n\n");
    file->Printf("userChannels {\n");
    for (int frame = 0; frame < numFrames; ++frame) {
        file->Printf("\t(");
        for (int channel = 0; channel < numVisemes; ++channel)
            file->WriteFloatString(" %g",
                weights[channel * numFrames + frame]);
        file->Printf(" )\n");
    }
    file->Printf("}\n");
    delete file;
    return true;
}
