#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

#include <cstdint>

class idFile;
class idFile_String;
class idLexer;
class idVoiceTrack;

enum voiceEvent_t : int {
    VOICEEVENT_VISEME_SIMPLE = 0,
    VOICEEVENT_VISEME_FRAME = 1,
    VOICEEVENT_GAMEEVENT = 2,
    VOICEEVENT_TEXT = 3,
    VOICEEVENT_PUNCTUATION = 4,
    VOICEEVENT_ANIM = 5,
    VOICEEVENT_MOOD = 6,
    VOICEEVENT_MAX = 7
};

enum mood_t : int {
    MOOD_NONE, MOOD_CLEAR, MOOD_HAPPY, MOOD_SAD, MOOD_ANGRY,
    MOOD_SUSPICIOUS, MOOD_DRUNK, MOOD_SLEEPY, MOOD_NERVOUS, MOOD_MAX
};

struct vtrEventHandle_t {
    std::int16_t eventType;
    std::int16_t index;

    vtrEventHandle_t(voiceEvent_t type = VOICEEVENT_MAX, int eventIndex = -1)
        : eventType(static_cast<std::int16_t>(type)),
          index(static_cast<std::int16_t>(eventIndex)) {}
    void WriteBinary(idFile& file) const;
    void LoadBinary(idFile& file);
    bool IsValid() const { return eventType >= 0 && eventType < VOICEEVENT_MAX && index >= 0; }
};

class idVoiceEvent {
public:
    idVoiceEvent();
    virtual ~idVoiceEvent();

    virtual const char* GetName() const { return "invalid"; }
    virtual float GetWeight(int currentTimeMS, int gameMSPerFrame) const;
    virtual bool IsInstantaneous() const { return durationMS == 0; }
    virtual bool IsWithinInterval(int startIntervalMS, int endIntervalMS) const;
    virtual void Write(const idVoiceTrack* track, idFile_String& file) const;
    virtual void Parse(idVoiceTrack* track, idLexer& lexer);
    virtual bool WriteBinary(idFile& file) const;
    virtual bool LoadBinary(idFile& file);
    virtual unsigned int Memory() const { return sizeof(*this); }

    int startMS;
    std::int16_t durationMS;
    std::uint8_t eventType;

    static const char* const voiceEventNames[VOICEEVENT_MAX];
};

class alignas(4) idVisemeEvent : public idVoiceEvent {
public:
    idVisemeEvent();
    std::uint8_t visemeType;
};

class idViseme_Simple : public idVisemeEvent {
public:
    idViseme_Simple();
    const char* GetName() const override;
    float GetWeight(int currentTimeMS, int gameMSPerFrame) const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    unsigned int Memory() const override { return sizeof(*this); }
    bool operator==(const idViseme_Simple& other) const;

    std::uint16_t peakTimeMS;
    std::uint8_t peakWeight;
};

class alignas(4) idViseme_Frame : public idVisemeEvent {
public:
    idViseme_Frame();
    ~idViseme_Frame() override;
    const char* GetName() const override;
    float GetWeight(int currentTimeMS, int gameMSPerFrame) const override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    unsigned int Memory() const override { return sizeof(*this) + numWeights; }
    void SetWeights(const std::uint8_t* values, std::uint8_t count);
    void MergeWeights(const idViseme_Frame& other, int gameMSPerFrame);

    std::uint8_t numWeights;
    std::uint8_t* weights;
};

struct idVoiceGameArgs {
    std::uint16_t numArgs;
    std::uint16_t argSize;
    std::uint16_t buffSize;
    std::uint16_t argOffsets[2];
    std::uint8_t argTypes[2];
    std::uint8_t argExTypes[2];
    std::uint8_t* args;

    idVoiceGameArgs();
    idVoiceGameArgs(const idVoiceGameArgs& other);
    ~idVoiceGameArgs();
    idVoiceGameArgs& operator=(const idVoiceGameArgs& other);
};

class idVoiceGameEvent : public idVoiceEvent {
public:
    idVoiceGameEvent();
    const char* GetName() const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    unsigned int Memory() const override { return sizeof(*this) + args.buffSize; }
    bool operator==(const idVoiceGameEvent& other) const;

    std::int16_t eventNum;
    idVoiceGameArgs args;
};

class idVoiceTextEvent : public idVoiceEvent {
public:
    idVoiceTextEvent();
    const char* GetName() const override;
    float GetWeight(int currentTimeMS, int gameMSPerFrame) const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    unsigned int Memory() const override { return sizeof(*this) + text.Length(); }
    bool operator==(const idVoiceTextEvent& other) const;

    idStr text;
};

class alignas(4) idVoicePunctuationEvent : public idVoiceEvent {
public:
    idVoicePunctuationEvent();
    const char* GetName() const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    bool operator==(const idVoicePunctuationEvent& other) const;

    char punctuation;
};

class idVoiceAnimEvent : public idVoiceEvent {
public:
    explicit idVoiceAnimEvent(float initialRate = 1.0f);
    const char* GetName() const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    bool operator==(const idVoiceAnimEvent& other) const;
    float GetRate() const;
    void SetRate(float value);

    idAtomicString animName;
    std::int16_t channel;
    std::uint16_t blendInDurationMS;
    std::uint16_t blendOutDurationMS;
    std::uint16_t startFrame;
    std::uint16_t rate;
    bool looping;
};

class idVoiceMoodEvent : public idVoiceEvent {
public:
    idVoiceMoodEvent();
    const char* GetName() const override;
    void Write(const idVoiceTrack* track, idFile_String& file) const override;
    void Parse(idVoiceTrack* track, idLexer& lexer) override;
    bool WriteBinary(idFile& file) const override;
    bool LoadBinary(idFile& file) override;
    bool operator==(const idVoiceMoodEvent& other) const;

    mood_t mood;
};

class idVoiceEventManager {
public:
    idVoiceEventManager();
    ~idVoiceEventManager();

    idVoiceEvent* GetEvent(const vtrEventHandle_t& handle);
    const idVoiceEvent* GetEvent(const vtrEventHandle_t& handle) const;
    int NumEventType(voiceEvent_t type) const;
    idVoiceEvent* AllocEvent(voiceEvent_t type, vtrEventHandle_t& handle);
    void FreeEvents(idList<vtrEventHandle_t, 5>& events);
    void FreeVisemeEvents(idList<vtrEventHandle_t, 5>& events);
    void FreeTextEvents(idList<vtrEventHandle_t, 5>& events);
    void Condense(idList<vtrEventHandle_t, 5>& events);
    void WriteBinary(idFile& file) const;
    void LoadBinary(idFile& file);

    idList<idViseme_Simple, 66> eventsVisemeSimple;
    idList<idVoiceGameEvent, 66> eventsGame;
    idList<idVoiceTextEvent, 66> eventsText;
    idList<idVoicePunctuationEvent, 66> eventsPunc;
    idList<idVoiceAnimEvent, 66> eventsAnim;
    idList<idVoiceMoodEvent, 66> eventsMood;
};

static_assert(sizeof(vtrEventHandle_t) == 4,
    "Recovered voice-event handle ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idVoiceEvent) == 12, "Recovered voice-event ABI changed");
static_assert(sizeof(idVisemeEvent) == 16, "Recovered viseme-event ABI changed");
static_assert(sizeof(idViseme_Simple) == 20, "Recovered simple-viseme ABI changed");
static_assert(sizeof(idVoiceGameArgs) == 20, "Recovered game-event arguments ABI changed");
static_assert(sizeof(idVoiceGameEvent) == 36, "Recovered game-event ABI changed");
static_assert(sizeof(idVoiceTextEvent) == 44, "Recovered text-event ABI changed");
static_assert(sizeof(idVoicePunctuationEvent) == 16, "Recovered punctuation-event ABI changed");
static_assert(sizeof(idVoiceAnimEvent) == 28, "Recovered animation-event ABI changed");
static_assert(sizeof(idVoiceMoodEvent) == 16, "Recovered mood-event ABI changed");
static_assert(sizeof(idVoiceEventManager) == 96, "Recovered voice-event manager ABI changed");
#endif
