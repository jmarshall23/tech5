#include "decls/voiceovers/voicetrack_events.h"

#include "idlib/filesystem/file.h"
#include "idlib/text/lexer.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <new>

int Decls_VoiceTrackVisemeForName(const idVoiceTrack* track,
    const char* name);
const char* Decls_VoiceTrackVisemeName(const idVoiceTrack* track, int viseme);
int Decls_VoiceMoodForName(const char* name);
const char* Decls_VoiceMoodName(int mood);
int Decls_VoiceFaceChannelForName(const char* name);
const char* Decls_VoiceFaceChannelName(int channel);
bool Decls_ParseVoiceGameEvent(idVoiceGameEvent& event, idVoiceTrack* track,
    idLexer& lexer);
void Decls_WriteVoiceGameEvent(const idVoiceGameEvent& event,
    const idVoiceTrack* track, idFile_String& file);

namespace {

constexpr int kRateFractionalBits = 8;
constexpr int kRateFractionalMask = (1 << kRateFractionalBits) - 1;
constexpr float kRateFractionalStep = 1.0f / kRateFractionalMask;

std::int16_t ClampShort(const int value) {
    return static_cast<std::int16_t>((std::max)(-32768, (std::min)(32767, value)));
}

std::uint16_t ClampUShort(const int value) {
    return static_cast<std::uint16_t>((std::max)(0, (std::min)(65535, value)));
}

std::uint8_t ClampByte(const int value) {
    return static_cast<std::uint8_t>((std::max)(0, (std::min)(255, value)));
}

void WriteEventBlock(const idVoiceEvent& event, idFile_String& file,
        const char* header) {
    file.WriteFloatString("\t\t%s {\n", header);
    file.WriteFloatString("\t\t\tstart %d\n", event.startMS);
    file.WriteFloatString("\t\t\tduration %d\n", event.durationMS);
}

void ParseEventTimes(idVoiceEvent& event, idLexer& lexer) {
    if (!lexer.ExpectTokenString("{")) return;
    if (lexer.CheckTokenString("start")) event.startMS = lexer.ParseInt();
    if (lexer.CheckTokenString("duration"))
        event.durationMS = ClampShort(lexer.ParseInt());
}

template<class eventType>
int FindFreeIndex(const idList<eventType, 66>& list) {
    for (int index = 0; index < list.Num(); ++index)
        if (list[index].eventType == VOICEEVENT_MAX) return index;
    return -1;
}

template<class eventType>
eventType* AllocateFrom(idList<eventType, 66>& list, const voiceEvent_t type,
        vtrEventHandle_t& handle) {
    int index = FindFreeIndex(list);
    if (index < 0) {
        index = list.Append(eventType());
        if (index < 0) return nullptr;
    } else {
        list[index] = eventType();
    }
    list[index].eventType = static_cast<std::uint8_t>(type);
    handle = vtrEventHandle_t(type, index);
    return &list[index];
}

template<class eventType>
void CondenseList(idList<eventType, 66>& list, const voiceEvent_t type,
        idList<vtrEventHandle_t, 5>& handles) {
    idList<int, 5> mapping(16);
    mapping.SetNum(list.Num());
    int write = 0;
    for (int read = 0; read < list.Num(); ++read) {
        if (list[read].eventType == VOICEEVENT_MAX) {
            mapping[read] = -1;
            continue;
        }
        mapping[read] = write;
        if (write != read) list[write] = list[read];
        ++write;
    }
    list.SetNum(write);
    for (int index = handles.Num() - 1; index >= 0; --index) {
        if (handles[index].eventType != type) continue;
        const int oldIndex = handles[index].index;
        if (oldIndex < 0 || oldIndex >= mapping.Num()
            || mapping[oldIndex] < 0) handles.RemoveIndex(index);
        else handles[index].index = static_cast<std::int16_t>(mapping[oldIndex]);
    }
}

template<class eventType>
void WriteEventList(const idList<eventType, 66>& list, idFile& file) {
    const int count = list.Num();
    file.Write(&count, sizeof(count));
    for (int index = 0; index < count; ++index) list[index].WriteBinary(file);
}

template<class eventType>
void ReadEventList(idList<eventType, 66>& list, idFile& file) {
    int count = 0;
    file.Read(&count, sizeof(count));
    count = (std::max)(0, count);
    list.SetNum(count);
    for (int index = 0; index < count; ++index) list[index].LoadBinary(file);
}

} // namespace

const char* const idVoiceEvent::voiceEventNames[VOICEEVENT_MAX] = {
    "viseme", "visemeFrame", "gameEvent", "text", "punctuation",
    "anim", "mood"
};

void vtrEventHandle_t::WriteBinary(idFile& file) const {
    file.Write(&eventType, sizeof(eventType));
    file.Write(&index, sizeof(index));
}

void vtrEventHandle_t::LoadBinary(idFile& file) {
    file.Read(&eventType, sizeof(eventType));
    file.Read(&index, sizeof(index));
}

idVoiceEvent::idVoiceEvent()
    : startMS(-1), durationMS(0), eventType(VOICEEVENT_MAX) {}
idVoiceEvent::~idVoiceEvent() = default;

float idVoiceEvent::GetWeight(const int currentTimeMS, int) const {
    return currentTimeMS >= startMS && currentTimeMS <= startMS + durationMS
        ? 1.0f : 0.0f;
}

bool idVoiceEvent::IsWithinInterval(const int intervalStart,
        const int intervalEnd) const {
    const int eventEnd = startMS + durationMS;
    return (intervalEnd >= startMS && intervalEnd < eventEnd)
        || (intervalStart >= startMS && intervalStart < eventEnd)
        || (startMS > intervalStart && startMS < intervalEnd)
        || (eventEnd >= intervalStart && eventEnd < intervalEnd);
}

void idVoiceEvent::Write(const idVoiceTrack*, idFile_String& file) const {
    WriteEventBlock(*this, file, GetName());
    file.WriteFloatString("\t\t}\n");
}

void idVoiceEvent::Parse(idVoiceTrack*, idLexer& lexer) {
    ParseEventTimes(*this, lexer);
    lexer.ExpectTokenString("}");
}

bool idVoiceEvent::WriteBinary(idFile& file) const {
    return file.Write(&startMS, sizeof(startMS)) == sizeof(startMS)
        && file.Write(&durationMS, sizeof(durationMS)) == sizeof(durationMS);
}

bool idVoiceEvent::LoadBinary(idFile& file) {
    return file.Read(&startMS, sizeof(startMS)) == sizeof(startMS)
        && file.Read(&durationMS, sizeof(durationMS)) == sizeof(durationMS);
}

idVisemeEvent::idVisemeEvent() : idVoiceEvent(), visemeType(0xFF) {}

idViseme_Simple::idViseme_Simple()
    : idVisemeEvent(), peakTimeMS(0), peakWeight(0) {
    eventType = VOICEEVENT_VISEME_SIMPLE;
}

const char* idViseme_Simple::GetName() const {
    return voiceEventNames[VOICEEVENT_VISEME_SIMPLE];
}

float idViseme_Simple::GetWeight(const int currentTimeMS, int) const {
    const int elapsed = currentTimeMS - startMS;
    float envelope = 0.0f;
    if (elapsed < static_cast<int>(peakTimeMS)) {
        envelope = peakTimeMS != 0
            ? static_cast<float>(elapsed) / peakTimeMS : 1.0f;
    } else {
        const int falloff = durationMS - peakTimeMS;
        envelope = falloff > 0
            ? 1.0f - static_cast<float>(elapsed - peakTimeMS) / falloff : 0.0f;
    }
    envelope = (std::max)(0.0f, (std::min)(1.0f, envelope));
    return (peakWeight * (1.0f / 255.0f)) * envelope;
}

void idViseme_Simple::Write(const idVoiceTrack* const track,
        idFile_String& file) const {
    file.WriteFloatString("\t\t%s %s {\n", GetName(),
        Decls_VoiceTrackVisemeName(track, visemeType));
    file.WriteFloatString("\t\t\tstart %d\n\t\t\tduration %d\n",
        startMS, durationMS);
    file.WriteFloatString("\t\t\tpeakTime %u\n\t\t\tpeakWeight %u\n\t\t}\n",
        peakTimeMS, peakWeight);
}

void idViseme_Simple::Parse(idVoiceTrack* const track, idLexer& lexer) {
    idToken token;
    if (!lexer.ExpectTokenType(TT_NAME, 0, token)) return;
    int type = Decls_VoiceTrackVisemeForName(track, token.c_str());
    if (type < 0) {
        lexer.Warning("unknown viseme type '%s'; forced to silence", token.c_str());
        type = 0;
    }
    visemeType = ClampByte(type);
    ParseEventTimes(*this, lexer);
    if (lexer.CheckTokenString("peakTime")) peakTimeMS = ClampUShort(lexer.ParseInt());
    if (lexer.CheckTokenString("peakWeight")) peakWeight = ClampByte(lexer.ParseInt());
    lexer.ExpectTokenString("}");
}

bool idViseme_Simple::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file)
        && file.Write(&visemeType, sizeof(visemeType)) == sizeof(visemeType)
        && file.Write(&peakTimeMS, sizeof(peakTimeMS)) == sizeof(peakTimeMS)
        && file.Write(&peakWeight, sizeof(peakWeight)) == sizeof(peakWeight);
}

bool idViseme_Simple::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_VISEME_SIMPLE;
    return idVoiceEvent::LoadBinary(file)
        && file.Read(&visemeType, sizeof(visemeType)) == sizeof(visemeType)
        && file.Read(&peakTimeMS, sizeof(peakTimeMS)) == sizeof(peakTimeMS)
        && file.Read(&peakWeight, sizeof(peakWeight)) == sizeof(peakWeight);
}

bool idViseme_Simple::operator==(const idViseme_Simple& other) const {
    return eventType == other.eventType && startMS == other.startMS
        && durationMS == other.durationMS && visemeType == other.visemeType
        && peakTimeMS == other.peakTimeMS && peakWeight == other.peakWeight;
}

idViseme_Frame::idViseme_Frame()
    : idVisemeEvent(), numWeights(0), weights(nullptr) {
    eventType = VOICEEVENT_VISEME_FRAME;
}
idViseme_Frame::~idViseme_Frame() { delete[] weights; }
const char* idViseme_Frame::GetName() const { return voiceEventNames[VOICEEVENT_VISEME_FRAME]; }

float idViseme_Frame::GetWeight(const int currentTimeMS,
        const int gameMSPerFrame) const {
    if (weights == nullptr || gameMSPerFrame <= 0) return 0.0f;
    const int frame = (currentTimeMS - startMS) / gameMSPerFrame;
    return frame >= 0 && frame < numWeights ? weights[frame] / 255.0f : 0.0f;
}

void idViseme_Frame::SetWeights(const std::uint8_t* const values,
        const std::uint8_t count) {
    delete[] weights;
    numWeights = count;
    weights = count != 0 ? new (std::nothrow) std::uint8_t[count] : nullptr;
    if (weights != nullptr && values != nullptr) std::memcpy(weights, values, count);
}

void idViseme_Frame::MergeWeights(const idViseme_Frame& other,
        const int gameMSPerFrame) {
    if (gameMSPerFrame <= 0) return;
    const int mergedStart = (std::min)(startMS, other.startMS);
    const int mergedEnd = (std::max)(startMS + durationMS,
        other.startMS + other.durationMS);
    const int count = (std::max)(0, (mergedEnd - mergedStart) / gameMSPerFrame);
    std::uint8_t* merged = count != 0
        ? new (std::nothrow) std::uint8_t[count] : nullptr;
    if (merged == nullptr && count != 0) return;
    for (int frame = 0; frame < count; ++frame) {
        const int time = mergedStart + frame * gameMSPerFrame;
        merged[frame] = ClampByte(static_cast<int>(255.0f
            * (std::max)(GetWeight(time, gameMSPerFrame),
                other.GetWeight(time, gameMSPerFrame))));
    }
    delete[] weights;
    weights = merged;
    numWeights = ClampByte(count);
    startMS = mergedStart;
    durationMS = ClampShort(mergedEnd - mergedStart);
}

bool idViseme_Frame::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file)
        && file.Write(&visemeType, 1) == 1
        && file.Write(&numWeights, 1) == 1
        && file.Write(weights, numWeights) == numWeights;
}
bool idViseme_Frame::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_VISEME_FRAME;
    std::uint8_t count = 0;
    if (!idVoiceEvent::LoadBinary(file) || file.Read(&visemeType, 1) != 1
        || file.Read(&count, 1) != 1) return false;
    SetWeights(nullptr, count);
    return count == 0 || file.Read(weights, count) == count;
}

idVoiceGameArgs::idVoiceGameArgs()
    : numArgs(0), argSize(0), buffSize(0), argOffsets{}, argTypes{},
      argExTypes{}, args(nullptr) {}
idVoiceGameArgs::idVoiceGameArgs(const idVoiceGameArgs& other)
    : idVoiceGameArgs() { *this = other; }
idVoiceGameArgs::~idVoiceGameArgs() { delete[] args; }
idVoiceGameArgs& idVoiceGameArgs::operator=(const idVoiceGameArgs& other) {
    if (this == &other) return *this;
    std::uint8_t* replacement = other.buffSize != 0
        ? new (std::nothrow) std::uint8_t[other.buffSize] : nullptr;
    if (replacement != nullptr && other.args != nullptr)
        std::memcpy(replacement, other.args, other.buffSize);
    delete[] args;
    numArgs = other.numArgs; argSize = other.argSize; buffSize = other.buffSize;
    std::memcpy(argOffsets, other.argOffsets, sizeof(argOffsets));
    std::memcpy(argTypes, other.argTypes, sizeof(argTypes));
    std::memcpy(argExTypes, other.argExTypes, sizeof(argExTypes));
    args = replacement;
    return *this;
}

idVoiceGameEvent::idVoiceGameEvent()
    : idVoiceEvent(), eventNum(-1), args() { eventType = VOICEEVENT_GAMEEVENT; }
const char* idVoiceGameEvent::GetName() const { return voiceEventNames[VOICEEVENT_GAMEEVENT]; }
void idVoiceGameEvent::Write(const idVoiceTrack* track, idFile_String& file) const {
    Decls_WriteVoiceGameEvent(*this, track, file);
}
void idVoiceGameEvent::Parse(idVoiceTrack* track, idLexer& lexer) {
    Decls_ParseVoiceGameEvent(*this, track, lexer);
}
bool idVoiceGameEvent::WriteBinary(idFile& file) const {
    if (!idVoiceEvent::WriteBinary(file)) return false;
    file.Write(&eventNum, sizeof(eventNum));
    file.Write(&args.numArgs, sizeof(args.numArgs));
    file.Write(&args.argSize, sizeof(args.argSize));
    return args.argSize == 0 || file.Write(args.args, args.argSize) == args.argSize;
}
bool idVoiceGameEvent::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_GAMEEVENT;
    if (!idVoiceEvent::LoadBinary(file)) return false;
    file.Read(&eventNum, sizeof(eventNum));
    file.Read(&args.numArgs, sizeof(args.numArgs));
    file.Read(&args.argSize, sizeof(args.argSize));
    idVoiceGameArgs replacement;
    replacement.numArgs = args.numArgs;
    replacement.argSize = args.argSize;
    replacement.buffSize = args.argSize;
    replacement.args = args.argSize != 0 ? new (std::nothrow) std::uint8_t[args.argSize] : nullptr;
    if (args.argSize != 0 && (replacement.args == nullptr
        || file.Read(replacement.args, args.argSize) != args.argSize)) return false;
    args = replacement;
    return true;
}
bool idVoiceGameEvent::operator==(const idVoiceGameEvent& other) const {
    return startMS == other.startMS && durationMS == other.durationMS
        && eventNum == other.eventNum && args.argSize == other.args.argSize
        && (args.argSize == 0 || std::memcmp(args.args, other.args.args,
            args.argSize) == 0);
}

idVoiceTextEvent::idVoiceTextEvent() : idVoiceEvent(), text() { eventType = VOICEEVENT_TEXT; }
const char* idVoiceTextEvent::GetName() const { return voiceEventNames[VOICEEVENT_TEXT]; }
float idVoiceTextEvent::GetWeight(const int time, int) const {
    return time >= startMS && time <= startMS + durationMS ? 1.0f : 0.0f;
}
void idVoiceTextEvent::Write(const idVoiceTrack*, idFile_String& file) const {
    file.WriteFloatString("\t\t%s \"%s\" {\n", GetName(), text.c_str());
    file.WriteFloatString("\t\t\tstart %d\n\t\t\tduration %d\n\t\t}\n", startMS, durationMS);
}
void idVoiceTextEvent::Parse(idVoiceTrack*, idLexer& lexer) {
    idToken token;
    if (lexer.ExpectTokenType(TT_STRING, 0, token)) text = token.c_str();
    ParseEventTimes(*this, lexer);
    lexer.ExpectTokenString("}");
}
bool idVoiceTextEvent::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file) && file.WriteString(text) != 0;
}
bool idVoiceTextEvent::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_TEXT;
    return idVoiceEvent::LoadBinary(file) && file.ReadString(text) != 0;
}
bool idVoiceTextEvent::operator==(const idVoiceTextEvent& other) const {
    return startMS == other.startMS && durationMS == other.durationMS
        && text == other.text;
}

idVoicePunctuationEvent::idVoicePunctuationEvent()
    : idVoiceEvent(), punctuation(0) { eventType = VOICEEVENT_PUNCTUATION; }
const char* idVoicePunctuationEvent::GetName() const { return voiceEventNames[VOICEEVENT_PUNCTUATION]; }
void idVoicePunctuationEvent::Write(const idVoiceTrack*, idFile_String& file) const {
    file.WriteFloatString("\t\t%s '%c' {\n", GetName(), punctuation);
    file.WriteFloatString("\t\t\tstart %d\n\t\t\tduration %d\n\t\t}\n", startMS, durationMS);
}
void idVoicePunctuationEvent::Parse(idVoiceTrack*, idLexer& lexer) {
    idToken token;
    if (lexer.ExpectAnyToken(token)) punctuation = token.Length() ? token.c_str()[0] : 0;
    ParseEventTimes(*this, lexer);
    lexer.ExpectTokenString("}");
}
bool idVoicePunctuationEvent::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file) && file.Write(&punctuation, 1) == 1;
}
bool idVoicePunctuationEvent::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_PUNCTUATION;
    return idVoiceEvent::LoadBinary(file) && file.Read(&punctuation, 1) == 1;
}
bool idVoicePunctuationEvent::operator==(const idVoicePunctuationEvent& other) const {
    return startMS == other.startMS && durationMS == other.durationMS
        && punctuation == other.punctuation;
}

idVoiceAnimEvent::idVoiceAnimEvent(const float initialRate)
    : idVoiceEvent(), animName(""), channel(0), blendInDurationMS(0),
      blendOutDurationMS(0), startFrame(0), rate(0), looping(false) {
    eventType = VOICEEVENT_ANIM;
    SetRate(initialRate);
}
const char* idVoiceAnimEvent::GetName() const { return voiceEventNames[VOICEEVENT_ANIM]; }
float idVoiceAnimEvent::GetRate() const {
    return static_cast<float>(rate >> kRateFractionalBits)
        + (rate & kRateFractionalMask) * kRateFractionalStep;
}
void idVoiceAnimEvent::SetRate(const float value) {
    const float safe = (std::max)(0.0f, value);
    const int whole = static_cast<int>(std::floor(safe));
    const int fraction = static_cast<int>((safe - whole) / kRateFractionalStep);
    rate = static_cast<std::uint16_t>((whole << kRateFractionalBits)
        | (fraction & kRateFractionalMask));
}
void idVoiceAnimEvent::Write(const idVoiceTrack*, idFile_String& file) const {
    file.WriteFloatString("\t\t%s \"%s\" {\n", GetName(), animName.c_str());
    file.WriteFloatString("\t\t\tstart %d\n\t\t\tduration %d\n", startMS, durationMS);
    file.WriteFloatString("\t\t\tchannel %s\n\t\t\tblendIn %u\n\t\t\tblendOut %u\n",
        Decls_VoiceFaceChannelName(channel), blendInDurationMS, blendOutDurationMS);
    file.WriteFloatString("\t\t\tstartFrame %u\n\t\t\trate %g\n\t\t\tlooping %d\n\t\t}\n",
        startFrame, GetRate(), looping ? 1 : 0);
}
void idVoiceAnimEvent::Parse(idVoiceTrack*, idLexer& lexer) {
    idToken token;
    if (lexer.ExpectTokenType(TT_STRING, 0, token)) animName.Set(token.c_str());
    ParseEventTimes(*this, lexer);
    while (!lexer.CheckTokenString("}")) {
        if (!lexer.ExpectAnyToken(token)) break;
        if (idStr::Icmp(token.c_str(), "channel") == 0) {
            if (lexer.ExpectAnyToken(token)) channel = ClampShort(Decls_VoiceFaceChannelForName(token.c_str()));
        } else if (idStr::Icmp(token.c_str(), "blendIn") == 0) blendInDurationMS = ClampUShort(lexer.ParseInt());
        else if (idStr::Icmp(token.c_str(), "blendOut") == 0) blendOutDurationMS = ClampUShort(lexer.ParseInt());
        else if (idStr::Icmp(token.c_str(), "startFrame") == 0) startFrame = ClampUShort(lexer.ParseInt());
        else if (idStr::Icmp(token.c_str(), "rate") == 0) SetRate(lexer.ParseFloat());
        else if (idStr::Icmp(token.c_str(), "looping") == 0) looping = lexer.ParseBool();
        else lexer.SkipRestOfLine();
    }
}
bool idVoiceAnimEvent::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file)
        && file.WriteString(animName.c_str()) != 0
        && file.Write(&channel, sizeof(channel)) == sizeof(channel)
        && file.Write(&blendInDurationMS, 9) == 9;
}
bool idVoiceAnimEvent::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_ANIM;
    idStr name;
    if (!idVoiceEvent::LoadBinary(file) || file.ReadString(name) == 0) return false;
    animName.Set(name.c_str());
    if (file.Read(&channel, sizeof(channel)) != sizeof(channel)) return false;
    return file.Read(&blendInDurationMS, 9) == 9;
}
bool idVoiceAnimEvent::operator==(const idVoiceAnimEvent& other) const {
    return startMS == other.startMS && durationMS == other.durationMS
        && animName == other.animName && channel == other.channel
        && blendInDurationMS == other.blendInDurationMS
        && blendOutDurationMS == other.blendOutDurationMS
        && startFrame == other.startFrame && rate == other.rate
        && looping == other.looping;
}

idVoiceMoodEvent::idVoiceMoodEvent() : idVoiceEvent(), mood(MOOD_NONE) {
    eventType = VOICEEVENT_MOOD;
}
const char* idVoiceMoodEvent::GetName() const { return voiceEventNames[VOICEEVENT_MOOD]; }
void idVoiceMoodEvent::Write(const idVoiceTrack*, idFile_String& file) const {
    file.WriteFloatString("\t\t%s %s {\n", GetName(), Decls_VoiceMoodName(mood));
    file.WriteFloatString("\t\t\tstart %d\n\t\t\tduration %d\n\t\t}\n", startMS, durationMS);
}
void idVoiceMoodEvent::Parse(idVoiceTrack*, idLexer& lexer) {
    idToken token;
    if (lexer.ExpectAnyToken(token)) mood = static_cast<mood_t>(Decls_VoiceMoodForName(token.c_str()));
    ParseEventTimes(*this, lexer);
    lexer.ExpectTokenString("}");
}
bool idVoiceMoodEvent::WriteBinary(idFile& file) const {
    return idVoiceEvent::WriteBinary(file) && file.Write(&mood, sizeof(mood)) == sizeof(mood);
}
bool idVoiceMoodEvent::LoadBinary(idFile& file) {
    eventType = VOICEEVENT_MOOD;
    return idVoiceEvent::LoadBinary(file) && file.Read(&mood, sizeof(mood)) == sizeof(mood);
}
bool idVoiceMoodEvent::operator==(const idVoiceMoodEvent& other) const {
    return startMS == other.startMS && durationMS == other.durationMS && mood == other.mood;
}

idVoiceEventManager::idVoiceEventManager()
    : eventsVisemeSimple(0), eventsGame(0), eventsText(0), eventsPunc(0),
      eventsAnim(0), eventsMood(0) {}
idVoiceEventManager::~idVoiceEventManager() = default;

idVoiceEvent* idVoiceEventManager::GetEvent(const vtrEventHandle_t& handle) {
    return const_cast<idVoiceEvent*>(
        static_cast<const idVoiceEventManager*>(this)->GetEvent(handle));
}
const idVoiceEvent* idVoiceEventManager::GetEvent(const vtrEventHandle_t& handle) const {
    const int index = handle.index;
    switch (handle.eventType) {
    case VOICEEVENT_VISEME_SIMPLE: return index >= 0 && index < eventsVisemeSimple.Num() ? &eventsVisemeSimple[index] : nullptr;
    case VOICEEVENT_GAMEEVENT: return index >= 0 && index < eventsGame.Num() ? &eventsGame[index] : nullptr;
    case VOICEEVENT_TEXT: return index >= 0 && index < eventsText.Num() ? &eventsText[index] : nullptr;
    case VOICEEVENT_PUNCTUATION: return index >= 0 && index < eventsPunc.Num() ? &eventsPunc[index] : nullptr;
    case VOICEEVENT_ANIM: return index >= 0 && index < eventsAnim.Num() ? &eventsAnim[index] : nullptr;
    case VOICEEVENT_MOOD: return index >= 0 && index < eventsMood.Num() ? &eventsMood[index] : nullptr;
    default: return nullptr;
    }
}

int idVoiceEventManager::NumEventType(const voiceEvent_t type) const {
    int count = 0;
    const int capacity = type == VOICEEVENT_VISEME_SIMPLE ? eventsVisemeSimple.Num()
        : type == VOICEEVENT_GAMEEVENT ? eventsGame.Num()
        : type == VOICEEVENT_TEXT ? eventsText.Num()
        : type == VOICEEVENT_PUNCTUATION ? eventsPunc.Num()
        : type == VOICEEVENT_ANIM ? eventsAnim.Num()
        : type == VOICEEVENT_MOOD ? eventsMood.Num() : 0;
    for (int index = 0; index < capacity; ++index) {
        const idVoiceEvent* event = GetEvent(vtrEventHandle_t(type, index));
        if (event != nullptr && event->eventType != VOICEEVENT_MAX) ++count;
    }
    return count;
}

idVoiceEvent* idVoiceEventManager::AllocEvent(const voiceEvent_t type,
        vtrEventHandle_t& handle) {
    switch (type) {
    case VOICEEVENT_VISEME_SIMPLE: return AllocateFrom(eventsVisemeSimple, type, handle);
    case VOICEEVENT_GAMEEVENT: return AllocateFrom(eventsGame, type, handle);
    case VOICEEVENT_TEXT: return AllocateFrom(eventsText, type, handle);
    case VOICEEVENT_PUNCTUATION: return AllocateFrom(eventsPunc, type, handle);
    case VOICEEVENT_ANIM: return AllocateFrom(eventsAnim, type, handle);
    case VOICEEVENT_MOOD: return AllocateFrom(eventsMood, type, handle);
    default: handle = vtrEventHandle_t(); return nullptr;
    }
}

void idVoiceEventManager::FreeEvents(idList<vtrEventHandle_t, 5>& handles) {
    for (int index = 0; index < handles.Num(); ++index) {
        idVoiceEvent* const event = GetEvent(handles[index]);
        if (event != nullptr) event->eventType = VOICEEVENT_MAX;
    }
    handles.Clear();
}
void idVoiceEventManager::FreeVisemeEvents(idList<vtrEventHandle_t, 5>& handles) {
    for (int index = handles.Num() - 1; index >= 0; --index) {
        if (handles[index].eventType == VOICEEVENT_VISEME_SIMPLE
            || handles[index].eventType == VOICEEVENT_VISEME_FRAME) {
            idVoiceEvent* const event = GetEvent(handles[index]);
            if (event != nullptr) event->eventType = VOICEEVENT_MAX;
            handles.RemoveIndex(index);
        }
    }
}
void idVoiceEventManager::FreeTextEvents(idList<vtrEventHandle_t, 5>& handles) {
    for (int index = handles.Num() - 1; index >= 0; --index) {
        if (handles[index].eventType == VOICEEVENT_TEXT) {
            idVoiceEvent* const event = GetEvent(handles[index]);
            if (event != nullptr) event->eventType = VOICEEVENT_MAX;
            handles.RemoveIndex(index);
        }
    }
}
void idVoiceEventManager::Condense(idList<vtrEventHandle_t, 5>& handles) {
    CondenseList(eventsVisemeSimple, VOICEEVENT_VISEME_SIMPLE, handles);
    CondenseList(eventsGame, VOICEEVENT_GAMEEVENT, handles);
    CondenseList(eventsText, VOICEEVENT_TEXT, handles);
    CondenseList(eventsPunc, VOICEEVENT_PUNCTUATION, handles);
    CondenseList(eventsAnim, VOICEEVENT_ANIM, handles);
    CondenseList(eventsMood, VOICEEVENT_MOOD, handles);
}
void idVoiceEventManager::WriteBinary(idFile& file) const {
    WriteEventList(eventsVisemeSimple, file); WriteEventList(eventsGame, file);
    WriteEventList(eventsText, file); WriteEventList(eventsPunc, file);
    WriteEventList(eventsAnim, file); WriteEventList(eventsMood, file);
}
void idVoiceEventManager::LoadBinary(idFile& file) {
    ReadEventList(eventsVisemeSimple, file); ReadEventList(eventsGame, file);
    ReadEventList(eventsText, file); ReadEventList(eventsPunc, file);
    ReadEventList(eventsAnim, file); ReadEventList(eventsMood, file);
}
