#include "decls/voiceovers/voicetrack.h"

#include "decls/voiceovers/declvisemeset.h"
#include "idlib/filesystem/file.h"
#include "idlib/hashing/crc32.h"
#include "idlib/text/lexer.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cstring>
#include <new>

unsigned int Decls_VoiceTrackFileTimestamp(const char* fileName);
bool Decls_LoadVoiceTrackResource(idVoiceTrack& track);
bool Decls_ReadVoiceTrackText(const char* fileName, idStr& text,
    unsigned int& timestamp);
bool Decls_WriteVoiceTrackText(const char* fileName, const char* text,
    int length);
idFile* Decls_OpenVoiceTrackBinaryRead(const char* fileName);
idFile* Decls_OpenVoiceTrackBinaryWrite(const char* fileName);
void Decls_CloseVoiceTrackFile(idFile* file);
const idSoundShader* Decls_FindVoiceSoundShader(const char* name);
const char* Decls_VoiceSoundShaderName(const idSoundShader* shader);
int Decls_VoiceSoundShaderMaxLength(const idSoundShader* shader);
unsigned int Decls_VoiceSoundShaderTimestamp(const idSoundShader* shader);
unsigned int Decls_VoiceSoundShaderCRC(const idSoundShader* shader);

namespace {

constexpr unsigned int kVoiceTrackMagic = 0x20525456u; // "VTR "
constexpr int kVoiceFrameMS = 66;

template<class type>
bool WriteValue(idFile& file, const type& value) {
    return file.Write(&value, sizeof(value)) == sizeof(value);
}

template<class type>
bool ReadValue(idFile& file, type& value) {
    return file.Read(&value, sizeof(value)) == sizeof(value);
}

const char* SafeName(const char* name) { return name != nullptr ? name : ""; }

} // namespace

idTypedResourceList<idVoiceTrack> idVoiceTrack::resourceList("voicetrack");

const char* const idVoiceTrack::moodNames[MOOD_MAX] = {
    "none", "clear", "happy", "sad", "angry", "suspicious",
    "drunk", "sleepy", "nervous"
};
const char* const idVoiceTrack::moodAnimNames[MOOD_MAX] = {
    "", "", "happy", "sad", "angry", "suspicious",
    "drunk", "sleepy", "nervous"
};
const char* const idVoiceTrack::faceChannelNames[FACECHANNEL_MAX] = {
    "body", "legs", "torso", "head", "eyes", "emote_mouth",
    "emote_brow", "emote_face", "face", "bodyweb", "user"
};

idVoiceTrack::idFrameRefIndexBuffer::idFrameRefIndexBuffer()
    : curOffset(0), size(0), indices(nullptr) {}
idVoiceTrack::idFrameRefIndexBuffer::~idFrameRefIndexBuffer() { delete[] indices; }
void idVoiceTrack::idFrameRefIndexBuffer::Alloc(const int count) {
    delete[] indices;
    curOffset = 0;
    size = static_cast<std::uint16_t>((std::max)(0, (std::min)(65535, count)));
    indices = size != 0 ? new (std::nothrow) std::uint16_t[size] : nullptr;
}
void idVoiceTrack::idFrameRefIndexBuffer::Write(idFile& file) const {
    WriteValue(file, size); WriteValue(file, curOffset);
    if (size != 0) file.Write(indices, size * sizeof(*indices));
}
void idVoiceTrack::idFrameRefIndexBuffer::Read(idFile& file) {
    std::uint16_t count = 0, offset = 0;
    ReadValue(file, count); ReadValue(file, offset);
    Alloc(count); curOffset = offset;
    if (size != 0) file.Read(indices, size * sizeof(*indices));
}

idVoiceTrack::idVoiceTrack(const char* const defaultVisemeSetName)
    : events(0), voiceEventManager(), frameRefs(nullptr), numFrameRefs(0),
      frameRefPadding(0), indexBuffer(), rebuildFrameRefs(true),
      visemeOffsetState(0), offsetState(0), statePadding(0), textLangKey(""),
      textId(), textCRC(0), lipsyncTextCRC(0), subtitleLangKey(""),
      subtitleId(), soundShader(nullptr), sampleTimestamp(0), sampleCRC(0),
      animName(), faceChannel(FACECHANNEL_BODY), blendInMS(250),
      blendOutMS(250), soundOffsetMS(66), visemeOffsetMS(0),
      animEventOffsetMS(0), moodEventOffsetMS(0), gameEventOffsetMS(0),
      textEventOffsetMS(0), flags{}, flagsPadding{}, weightScale(1.0f),
      defaultMood(MOOD_NONE), declVisemeSet(nullptr), timestamp(~0u),
      approximateDuration(-1) {
    flags.useRealTime = 1;
    if (defaultVisemeSetName != nullptr && defaultVisemeSetName[0] != '\0') {
        declVisemeSet = static_cast<const idDeclVisemeSet*>(
            idDeclVisemeSet::resourceList.FindWithInheritance(
                defaultVisemeSetName, true));
    }
}

idVoiceTrack::~idVoiceTrack() {
    voiceEventManager.FreeEvents(reinterpret_cast<idList<vtrEventHandle_t, 5>&>(events));
    delete[] frameRefs;
}

void idVoiceTrack::LoadResource() { Decls_LoadVoiceTrackResource(*this); }
bool idVoiceTrack::ReloadIfStale() {
    const unsigned int current = Decls_VoiceTrackFileTimestamp(GetName());
    if (current == timestamp) return false;
    LoadResource();
    return true;
}
void idVoiceTrack::WriteResourceFile() { Save(GetName()); }
idResourceList* idVoiceTrack::GetResourceList() { return &resourceList; }
mood_t idVoiceTrack::GetMoodForName(const char* const name) {
    for (int index = 0; index < MOOD_MAX; ++index)
        if (idStr::Icmp(moodNames[index], name) == 0) return static_cast<mood_t>(index);
    return MOOD_NONE;
}
faceChannel_t idVoiceTrack::GetFaceChannelForName(const char* const name) {
    for (int index = 0; index < FACECHANNEL_MAX; ++index)
        if (idStr::Icmp(faceChannelNames[index], name) == 0)
            return static_cast<faceChannel_t>(index);
    return FACECHANNEL_MAX;
}
const char* idVoiceTrack::GetMoodAnimName(const mood_t mood) {
    return mood >= 0 && mood < MOOD_MAX ? moodAnimNames[mood] : moodAnimNames[MOOD_CLEAR];
}
const char* idVoiceTrack::GetMoodName(const mood_t mood) {
    return mood >= 0 && mood < MOOD_MAX ? moodNames[mood] : moodNames[MOOD_CLEAR];
}
const char* idVoiceTrack::GetFaceChannelName(const faceChannel_t channel) {
    return channel >= 0 && channel < FACECHANNEL_MAX ? faceChannelNames[channel] : "invalid";
}
unsigned int idVoiceTrack::CalcTextCRC(const char* const text) {
    const char* const safe = SafeName(text);
    if (safe[0] == '#' && safe[1] == 's' && safe[2] == 't' && safe[3] == 'r') return 0;
    return CRC32_BlockChecksum(safe, static_cast<int>(std::strlen(safe)));
}

void idVoiceTrack::SetTrackTextId(const idStrId& id) {
    textId = id;
    textCRC = CalcTextCRC(textId.GetLocalizedString());
    if (id.IsValid()) textLangKey.Set(textId.GetKey());
}
void idVoiceTrack::SetSoundShader(const idSoundShader* const shader) {
    soundShader = shader;
    sampleTimestamp = shader != nullptr ? Decls_VoiceSoundShaderTimestamp(shader) : 0;
    sampleCRC = shader != nullptr ? Decls_VoiceSoundShaderCRC(shader) : 0;
}
bool idVoiceTrack::IsEdited() const {
    return flags.edited || voiceEventManager.NumEventType(VOICEEVENT_ANIM) > 0;
}
bool idVoiceTrack::IsCustomized() const {
    if (flags.edited || animName.Length() != 0 || flags.cycleAnim
        || flags.clearAnimAfter || flags.noLipSync || flags.suppressBlinking
        || weightScale != 1.0f || defaultMood != MOOD_NONE
        || soundOffsetMS != 66 || visemeOffsetMS != 0
        || animEventOffsetMS != 0 || moodEventOffsetMS != 0
        || gameEventOffsetMS != 0 || textEventOffsetMS != 0) return true;
    for (int index = 0; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr && (event->eventType == VOICEEVENT_GAMEEVENT
            || event->eventType == VOICEEVENT_ANIM
            || event->eventType == VOICEEVENT_MOOD)) return true;
    }
    return false;
}
int idVoiceTrack::Memory() const {
    return 4 * (numFrameRefs + events.NumAllocated() + 73);
}

int idVoiceTrack::FindLastEvent() const {
    int bestIndex = -1, bestEnd = -1;
    for (int index = 0; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr && event->startMS + event->durationMS >= bestEnd) {
            bestEnd = event->startMS + event->durationMS;
            bestIndex = index;
        }
    }
    return bestIndex;
}
int idVoiceTrack::FindNextEventForFrame(const int startIndex,
        const int frame) const {
    const int start = frame * kVoiceFrameMS;
    const int end = start + kVoiceFrameMS;
    for (int index = startIndex + 1; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr && event->IsWithinInterval(start, end)) return index;
    }
    return -1;
}
millisecond_t idVoiceTrack::FindApproximateDuration() const {
    int duration = static_cast<int>(soundOffsetMS)
        + Decls_VoiceSoundShaderMaxLength(soundShader);
    for (int index = 0; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr) duration = (std::max)(duration,
            event->startMS + event->durationMS);
    }
    return millisecond_t(duration);
}
millisecond_t idVoiceTrack::FindExactDuration() const {
    return approximateDuration.Get() >= 0 ? approximateDuration
        : FindApproximateDuration();
}

void idVoiceTrack::OffsetEvents(const eventOffset_t direction,
        const bool visemesOnly) {
    const char state = static_cast<char>(direction);
    if (visemesOnly) {
        if (visemeOffsetState == state) return;
        visemeOffsetState = state;
    } else {
        if (offsetState == state) return;
        offsetState = state;
        visemeOffsetState = state;
    }
    for (int index = 0; index < events.Num(); ++index) {
        idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event == nullptr) continue;
        unsigned int amount = 0;
        switch (event->eventType) {
        case VOICEEVENT_VISEME_SIMPLE: case VOICEEVENT_VISEME_FRAME: amount = visemeOffsetMS; break;
        case VOICEEVENT_GAMEEVENT: amount = gameEventOffsetMS; break;
        case VOICEEVENT_TEXT: case VOICEEVENT_PUNCTUATION: amount = textEventOffsetMS; break;
        case VOICEEVENT_ANIM: amount = animEventOffsetMS; break;
        case VOICEEVENT_MOOD: amount = moodEventOffsetMS; break;
        default: continue;
        }
        if (visemesOnly && event->eventType != VOICEEVENT_VISEME_SIMPLE
            && event->eventType != VOICEEVENT_VISEME_FRAME) continue;
        event->startMS += static_cast<int>(amount) * direction;
    }
    rebuildFrameRefs = true;
}

void idVoiceTrack::FreeVisemeEvents(const bool freeTextToo) {
    voiceEventManager.FreeVisemeEvents(
        reinterpret_cast<idList<vtrEventHandle_t, 5>&>(events));
    if (freeTextToo) FreeTextEvents();
    delete[] frameRefs; frameRefs = nullptr; numFrameRefs = 0;
    visemeOffsetState = 0; rebuildFrameRefs = true;
}
void idVoiceTrack::FreeTextEvents() {
    voiceEventManager.FreeTextEvents(
        reinterpret_cast<idList<vtrEventHandle_t, 5>&>(events));
    delete[] frameRefs; frameRefs = nullptr; numFrameRefs = 0;
    rebuildFrameRefs = true;
}

void idVoiceTrack::MergeVisemes() {
    for (int left = 0; left < events.Num(); ++left) {
        idViseme_Simple* first = dynamic_cast<idViseme_Simple*>(
            voiceEventManager.GetEvent(events[left]));
        if (first == nullptr) continue;
        for (int right = events.Num() - 1; right > left; --right) {
            idViseme_Simple* second = dynamic_cast<idViseme_Simple*>(
                voiceEventManager.GetEvent(events[right]));
            if (second == nullptr || second->visemeType != first->visemeType) continue;
            if (!first->IsWithinInterval(second->startMS,
                    second->startMS + second->durationMS)) continue;
            const int end = (std::max)(first->startMS + first->durationMS,
                second->startMS + second->durationMS);
            first->startMS = (std::min)(first->startMS, second->startMS);
            first->durationMS = static_cast<std::int16_t>(end - first->startMS);
            first->peakWeight = (std::max)(first->peakWeight, second->peakWeight);
            second->eventType = VOICEEVENT_MAX;
            events.RemoveIndex(right);
        }
    }
    voiceEventManager.Condense(
        reinterpret_cast<idList<vtrEventHandle_t, 5>&>(events));
    rebuildFrameRefs = true;
}

void idVoiceTrack::BuildFrameRefs() {
    if (!rebuildFrameRefs) return;
    delete[] frameRefs; frameRefs = nullptr; numFrameRefs = 0;
    int duration = FindApproximateDuration().Get();
    if (duration < 0) duration = 0;
    const int frameCount = duration / kVoiceFrameMS + 1;
    idList<std::uint16_t, 5> gathered(32);
    idList<idFrameRef, 5> refs(32);
    refs.SetNum(frameCount);
    for (int frame = 0; frame < frameCount; ++frame) {
        refs[frame].offset = static_cast<std::uint16_t>(gathered.Num());
        refs[frame].numIndices = 0;
        for (int eventIndex = FindNextEventForFrame(-1, frame);
             eventIndex >= 0;
             eventIndex = FindNextEventForFrame(eventIndex, frame)) {
            gathered.Append(static_cast<std::uint16_t>(eventIndex));
            ++refs[frame].numIndices;
        }
    }
    numFrameRefs = static_cast<std::int16_t>((std::min)(32767, frameCount));
    frameRefs = numFrameRefs > 0 ? new (std::nothrow) idFrameRef[numFrameRefs] : nullptr;
    for (int index = 0; frameRefs != nullptr && index < numFrameRefs; ++index)
        frameRefs[index] = refs[index];
    indexBuffer.Alloc(gathered.Num());
    indexBuffer.curOffset = static_cast<std::uint16_t>(gathered.Num());
    for (int index = 0; index < gathered.Num() && indexBuffer.indices != nullptr; ++index)
        indexBuffer.indices[index] = gathered[index];
    rebuildFrameRefs = false;
}

void idVoiceTrack::GetEvents(const int start, const int end,
        const voiceEvent_t type, idList<const idVoiceEvent*, 5>& output) const {
    output.Clear();
    for (int index = 0; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr && (type == VOICEEVENT_MAX || event->eventType == type)
            && event->IsWithinInterval(start, end)) output.Append(event);
    }
}
void idVoiceTrack::GetEventsForFrameRef(const int frameRef,
        const voiceEvent_t type, idList<const idVoiceEvent*, 5>& output) const {
    output.Clear();
    if (frameRef < 0 || frameRef >= numFrameRefs || frameRefs == nullptr) return;
    const idFrameRef& ref = frameRefs[frameRef];
    for (int index = 0; index < ref.numIndices; ++index) {
        const int eventIndex = indexBuffer.indices[ref.offset + index];
        if (eventIndex < 0 || eventIndex >= events.Num()) continue;
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[eventIndex]);
        if (event != nullptr && (type == VOICEEVENT_MAX || event->eventType == type))
            output.Append(event);
    }
}
idVoiceEvent* idVoiceTrack::AllocEvent(const voiceEvent_t type,
        vtrEventHandle_t& handle) {
    idVoiceEvent* const event = voiceEventManager.AllocEvent(type, handle);
    if (event != nullptr) events.Append(handle);
    rebuildFrameRefs = true;
    return event;
}

void idVoiceTrack::Write(idFile_String& output) const {
    const_cast<idVoiceTrack*>(this)->OffsetEvents(EVENTOFFSET_BACKWARDS, false);
    output.WriteFloatString("%s {\n", GetName());
    output.WriteFloatString("\tvisemeSet \"%s\"\n",
        declVisemeSet != nullptr ? declVisemeSet->GetName() : "");
    output.WriteFloatString("\tdefaultMood \"%s\"\n", GetMoodName(defaultMood));
    output.WriteFloatString("\tweightScale %f\n", weightScale);
    output.WriteFloatString("\tsoundOffsetMS %u\n\tvisemeOffsetMS %u\n",
        soundOffsetMS, visemeOffsetMS);
    output.WriteFloatString("\tanimEventOffsetMS %u\n\tmoodEventOffsetMS %u\n",
        animEventOffsetMS, moodEventOffsetMS);
    output.WriteFloatString("\tgameEventOffsetMS %u\n\ttextEventOffsetMS %u\n",
        gameEventOffsetMS, textEventOffsetMS);
    output.WriteFloatString("\tedited %d\n", flags.edited ? 1 : 0);
    output.WriteFloatString("\ttext {\n\t\tid \"%s\"\n\t\tcrc %u\n\t\tlipsyncTextCrc %u\n\t}\n",
        textLangKey.c_str(), textCRC, lipsyncTextCRC);
    output.WriteFloatString("\tsubtitles {\n\t\tid \"%s\"\n\t}\n",
        subtitleLangKey.c_str());
    output.WriteFloatString("\tsample {\n\t\tshader \"%s\"\n\t\ttimestamp %u\n\t\tcrc %u\n\t\tcompressed %d\n\t}\n",
        Decls_VoiceSoundShaderName(soundShader), sampleTimestamp, sampleCRC,
        flags.compressed ? 1 : 0);
    output.WriteFloatString("\tanim {\n\t\talias \"%s\"\n\t\tchannel \"%s\"\n",
        animName.c_str(), GetFaceChannelName(faceChannel));
    output.WriteFloatString("\t\tblendInMS %d\n\t\tblendOutMS %d\n\t\tcycle %d\n\t\tclear %d\n",
        blendInMS, blendOutMS, flags.cycleAnim ? 1 : 0, flags.clearAnimAfter ? 1 : 0);
    output.WriteFloatString("\t\tnolipsync %d\n\t\tsuppressBlinking %d\n\t\tuseRealTime %d\n\t}\n",
        flags.noLipSync ? 1 : 0, flags.suppressBlinking ? 1 : 0,
        flags.useRealTime ? 1 : 0);
    output.WriteFloatString("\tevents %d {\n", events.Num());
    for (int index = 0; index < events.Num(); ++index) {
        const idVoiceEvent* event = voiceEventManager.GetEvent(events[index]);
        if (event != nullptr) event->Write(this, output);
    }
    output.WriteFloatString("\t}\n}\n");
    const_cast<idVoiceTrack*>(this)->OffsetEvents(EVENTOFFSET_FORWARDS, false);
}

void idVoiceTrack::Parse(idLexer& lexer) {
    idToken token;
    if (!lexer.ExpectTokenString("{")) return;
    while (lexer.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        const char* key = token.c_str();
        if (idStr::Icmp(key, "visemeSet") == 0) {
            if (lexer.ExpectTokenType(TT_STRING, 0, token))
                declVisemeSet = static_cast<const idDeclVisemeSet*>(
                    idDeclVisemeSet::resourceList.FindWithInheritance(token.c_str(), true));
        } else if (idStr::Icmp(key, "defaultMood") == 0) {
            if (lexer.ExpectAnyToken(token)) defaultMood = GetMoodForName(token.c_str());
        } else if (idStr::Icmp(key, "weightScale") == 0) weightScale = lexer.ParseFloat();
        else if (idStr::Icmp(key, "soundOffsetMS") == 0) soundOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "visemeOffsetMS") == 0) visemeOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "animEventOffsetMS") == 0) animEventOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "moodEventOffsetMS") == 0) moodEventOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "gameEventOffsetMS") == 0) gameEventOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "textEventOffsetMS") == 0) textEventOffsetMS = lexer.ParseUnsignedInt();
        else if (idStr::Icmp(key, "edited") == 0) flags.edited = lexer.ParseBool();
        else if (idStr::Icmp(key, "text") == 0 && lexer.ExpectTokenString("{")) {
            while (!lexer.CheckTokenString("}")) {
                if (!lexer.ExpectAnyToken(token)) break;
                if (idStr::Icmp(token.c_str(), "id") == 0 && lexer.ExpectAnyToken(token)) {
                    textLangKey.Set(token.c_str()); textId.Set(token.c_str());
                } else if (idStr::Icmp(token.c_str(), "crc") == 0) textCRC = lexer.ParseUnsignedInt();
                else if (idStr::Icmp(token.c_str(), "lipsyncTextCrc") == 0) lipsyncTextCRC = lexer.ParseUnsignedInt();
                else lexer.SkipRestOfLine();
            }
        } else if (idStr::Icmp(key, "subtitles") == 0 && lexer.ExpectTokenString("{")) {
            while (!lexer.CheckTokenString("}")) {
                if (!lexer.ExpectAnyToken(token)) break;
                if (idStr::Icmp(token.c_str(), "id") == 0 && lexer.ExpectAnyToken(token)) {
                    subtitleLangKey.Set(token.c_str()); subtitleId.Set(token.c_str());
                } else lexer.SkipRestOfLine();
            }
        } else if (idStr::Icmp(key, "sample") == 0 && lexer.ExpectTokenString("{")) {
            while (!lexer.CheckTokenString("}")) {
                if (!lexer.ExpectAnyToken(token)) break;
                if (idStr::Icmp(token.c_str(), "shader") == 0 && lexer.ExpectAnyToken(token)) soundShader = Decls_FindVoiceSoundShader(token.c_str());
                else if (idStr::Icmp(token.c_str(), "timestamp") == 0) sampleTimestamp = lexer.ParseUnsignedInt();
                else if (idStr::Icmp(token.c_str(), "crc") == 0) sampleCRC = lexer.ParseUnsignedInt();
                else if (idStr::Icmp(token.c_str(), "compressed") == 0) flags.compressed = lexer.ParseBool();
                else lexer.SkipRestOfLine();
            }
        } else if (idStr::Icmp(key, "anim") == 0 && lexer.ExpectTokenString("{")) {
            while (!lexer.CheckTokenString("}")) {
                if (!lexer.ExpectAnyToken(token)) break;
                if (idStr::Icmp(token.c_str(), "alias") == 0 && lexer.ExpectAnyToken(token)) animName = token.c_str();
                else if (idStr::Icmp(token.c_str(), "channel") == 0 && lexer.ExpectAnyToken(token)) faceChannel = GetFaceChannelForName(token.c_str());
                else if (idStr::Icmp(token.c_str(), "blendInMS") == 0) blendInMS = static_cast<std::int16_t>(lexer.ParseInt());
                else if (idStr::Icmp(token.c_str(), "blendOutMS") == 0) blendOutMS = static_cast<std::int16_t>(lexer.ParseInt());
                else if (idStr::Icmp(token.c_str(), "cycle") == 0) flags.cycleAnim = lexer.ParseBool();
                else if (idStr::Icmp(token.c_str(), "clear") == 0) flags.clearAnimAfter = lexer.ParseBool();
                else if (idStr::Icmp(token.c_str(), "nolipsync") == 0) flags.noLipSync = lexer.ParseBool();
                else if (idStr::Icmp(token.c_str(), "suppressBlinking") == 0) flags.suppressBlinking = lexer.ParseBool();
                else if (idStr::Icmp(token.c_str(), "useRealTime") == 0) flags.useRealTime = lexer.ParseBool();
                else lexer.SkipRestOfLine();
            }
        } else if (idStr::Icmp(key, "events") == 0) {
            lexer.ParseInt(); lexer.ExpectTokenString("{");
            while (!lexer.CheckTokenString("}")) {
                if (!lexer.ExpectAnyToken(token)) break;
                voiceEvent_t type = VOICEEVENT_MAX;
                for (int eventType = 0; eventType < VOICEEVENT_MAX; ++eventType)
                    if (idStr::Icmp(token.c_str(), idVoiceEvent::voiceEventNames[eventType]) == 0)
                        type = static_cast<voiceEvent_t>(eventType);
                vtrEventHandle_t handle;
                idVoiceEvent* event = AllocEvent(type, handle);
                if (event != nullptr) event->Parse(this, lexer); else lexer.SkipBracedSection(true);
            }
        } else lexer.SkipRestOfLine();
    }
    approximateDuration = FindApproximateDuration();
    OffsetEvents(EVENTOFFSET_FORWARDS, false);
    BuildFrameRefs();
}

bool idVoiceTrack::LoadText(const char* const fileName) {
    idStr text;
    unsigned int sourceTimestamp = 0;
    if (!Decls_ReadVoiceTrackText(fileName, text, sourceTimestamp)) return false;
    idLexer lexer;
    if (!lexer.LoadMemory(text.c_str(), text.Length(), fileName)) return false;
    idToken nameToken;
    if (!lexer.ReadToken(nameToken)) return false;
    SetName(nameToken.c_str());
    timestamp = sourceTimestamp;
    Parse(lexer);
    return !lexer.HadError();
}

bool idVoiceTrack::Save(const char* const fileName) const {
    idFile_String output(fileName);
    Write(output);
    return Decls_WriteVoiceTrackText(fileName, output.GetDataPtr(),
        static_cast<int>(output.Length()));
}

bool idVoiceTrack::WriteBinary(const char* const fileName) const {
    idFile* const file = Decls_OpenVoiceTrackBinaryWrite(fileName);
    if (file == nullptr) return false;
    bool result = WriteValue(*file, kVoiceTrackMagic)
        && WriteValue(*file, timestamp)
        && file->WriteString(declVisemeSet != nullptr ? declVisemeSet->GetName() : "") != 0
        && file->WriteString(textLangKey.c_str()) != 0
        && WriteValue(*file, textCRC) && WriteValue(*file, lipsyncTextCRC)
        && file->WriteString(subtitleLangKey.c_str()) != 0
        && file->WriteString(Decls_VoiceSoundShaderName(soundShader)) != 0
        && WriteValue(*file, sampleTimestamp) && WriteValue(*file, sampleCRC)
        && file->WriteString(animName) != 0 && WriteValue(*file, faceChannel)
        && WriteValue(*file, blendInMS) && WriteValue(*file, blendOutMS)
        && WriteValue(*file, soundOffsetMS) && WriteValue(*file, visemeOffsetMS)
        && WriteValue(*file, animEventOffsetMS) && WriteValue(*file, moodEventOffsetMS)
        && WriteValue(*file, gameEventOffsetMS) && WriteValue(*file, textEventOffsetMS);
    const std::uint8_t storedFlags[6] = { static_cast<std::uint8_t>(flags.cycleAnim),
        static_cast<std::uint8_t>(flags.clearAnimAfter), static_cast<std::uint8_t>(flags.noLipSync),
        static_cast<std::uint8_t>(flags.suppressBlinking), static_cast<std::uint8_t>(flags.compressed),
        static_cast<std::uint8_t>(flags.edited) };
    result = result && file->Write(storedFlags, sizeof(storedFlags)) == sizeof(storedFlags)
        && WriteValue(*file, weightScale) && WriteValue(*file, defaultMood)
        && WriteValue(*file, approximateDuration);
    indexBuffer.Write(*file); WriteValue(*file, numFrameRefs);
    for (int index = 0; index < numFrameRefs; ++index) {
        WriteValue(*file, frameRefs[index].offset);
        WriteValue(*file, frameRefs[index].numIndices);
    }
    voiceEventManager.WriteBinary(*file);
    const int eventCount = events.Num(); WriteValue(*file, eventCount);
    for (int index = 0; index < eventCount; ++index) events[index].WriteBinary(*file);
    result = result && WriteValue(*file, kVoiceTrackMagic);
    Decls_CloseVoiceTrackFile(file);
    return result;
}

bool idVoiceTrack::LoadBinary(const char* const fileName,
        const unsigned int sourceTimestamp) {
    idFile* const file = Decls_OpenVoiceTrackBinaryRead(fileName);
    if (file == nullptr) return false;
    unsigned int magic = 0, storedTimestamp = 0;
    bool result = ReadValue(*file, magic) && magic == kVoiceTrackMagic
        && ReadValue(*file, storedTimestamp)
        && (sourceTimestamp == 0 || sourceTimestamp == ~0u || sourceTimestamp == storedTimestamp);
    idStr value;
    if (result) {
        timestamp = storedTimestamp;
        file->ReadString(value); declVisemeSet = static_cast<const idDeclVisemeSet*>(
            idDeclVisemeSet::resourceList.FindWithInheritance(value.c_str(), true));
        file->ReadString(value); textLangKey.Set(value.c_str()); textId.Set(value.c_str());
        result = ReadValue(*file, textCRC) && ReadValue(*file, lipsyncTextCRC);
        file->ReadString(value); subtitleLangKey.Set(value.c_str()); subtitleId.Set(value.c_str());
        file->ReadString(value); soundShader = Decls_FindVoiceSoundShader(value.c_str());
        result = result && ReadValue(*file, sampleTimestamp) && ReadValue(*file, sampleCRC);
        file->ReadString(animName);
        result = result && ReadValue(*file, faceChannel) && ReadValue(*file, blendInMS)
            && ReadValue(*file, blendOutMS) && ReadValue(*file, soundOffsetMS)
            && ReadValue(*file, visemeOffsetMS) && ReadValue(*file, animEventOffsetMS)
            && ReadValue(*file, moodEventOffsetMS) && ReadValue(*file, gameEventOffsetMS)
            && ReadValue(*file, textEventOffsetMS);
        std::uint8_t storedFlags[6]{};
        result = result && file->Read(storedFlags, sizeof(storedFlags)) == sizeof(storedFlags);
        flags.cycleAnim = storedFlags[0]; flags.clearAnimAfter = storedFlags[1];
        flags.noLipSync = storedFlags[2]; flags.suppressBlinking = storedFlags[3];
        flags.compressed = storedFlags[4]; flags.edited = storedFlags[5];
        result = result && ReadValue(*file, weightScale) && ReadValue(*file, defaultMood)
            && ReadValue(*file, approximateDuration);
        indexBuffer.Read(*file); ReadValue(*file, numFrameRefs);
        delete[] frameRefs;
        frameRefs = numFrameRefs > 0 ? new (std::nothrow) idFrameRef[numFrameRefs] : nullptr;
        for (int index = 0; index < numFrameRefs; ++index) {
            ReadValue(*file, frameRefs[index].offset);
            ReadValue(*file, frameRefs[index].numIndices);
        }
        voiceEventManager.LoadBinary(*file);
        int eventCount = 0; ReadValue(*file, eventCount);
        events.SetNum((std::max)(0, eventCount));
        for (int index = 0; index < events.Num(); ++index) events[index].LoadBinary(*file);
        result = result && ReadValue(*file, magic) && magic == kVoiceTrackMagic;
    }
    Decls_CloseVoiceTrackFile(file);
    visemeOffsetState = 1; offsetState = 1; rebuildFrameRefs = false;
    return result;
}

// Cross-translation-unit queries used by the recovered voice-over and event
// code while retaining voice-track ownership here.
const char* Decls_VoiceTrackName(const idVoiceTrack* track) {
    return track != nullptr ? track->GetName() : "";
}
unsigned int Decls_VoiceTrackMemory(const idVoiceTrack* track) {
    return track != nullptr ? static_cast<unsigned int>(track->Memory()) : 0;
}
millisecond_t Decls_VoiceTrackApproximateDuration(const idVoiceTrack* track) {
    return track != nullptr ? track->FindApproximateDuration() : millisecond_t(0);
}
int Decls_VoiceTrackVisemeForName(const idVoiceTrack* track, const char* name) {
    return track != nullptr && track->declVisemeSet != nullptr
        ? track->declVisemeSet->VisemeForName(name) : -1;
}
const char* Decls_VoiceTrackVisemeName(const idVoiceTrack* track, int viseme) {
    if (track == nullptr || track->declVisemeSet == nullptr) return "";
    for (int index = 0; index < track->declVisemeSet->visemes.Num(); ++index) {
        if (track->declVisemeSet->visemes[index].viseme == viseme)
            return track->declVisemeSet->visemes[index].name.c_str();
    }
    return "";
}
int Decls_VoiceMoodForName(const char* name) { return idVoiceTrack::GetMoodForName(name); }
const char* Decls_VoiceMoodName(int mood) {
    return idVoiceTrack::GetMoodName(static_cast<mood_t>(mood));
}
int Decls_VoiceFaceChannelForName(const char* name) {
    return idVoiceTrack::GetFaceChannelForName(name);
}
const char* Decls_VoiceFaceChannelName(int channel) {
    return idVoiceTrack::GetFaceChannelName(static_cast<faceChannel_t>(channel));
}
