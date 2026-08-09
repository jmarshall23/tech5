#pragma once

#include "decls/voiceovers/voicetrack_events.h"
#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/langdict.h"
#include "idlib/typesafenumber.h"

#include <cstdint>

class idDeclVisemeSet;
class idFile;
class idFile_String;
class idLexer;
class idSoundShader;
enum millisecondUnique_t : int;

using millisecond_t = idTypesafeNumber<int, millisecondUnique_t>;

enum faceChannel_t : int {
    FACECHANNEL_BODY, FACECHANNEL_LEGS, FACECHANNEL_TORSO,
    FACECHANNEL_HEAD, FACECHANNEL_EYES, FACECHANNEL_EMOTE_MOUTH,
    FACECHANNEL_EMOTE_BROW, FACECHANNEL_EMOTE_FACE, FACECHANNEL_FACE,
    FACECHANNEL_BODYWEB, FACECHANNEL_USER_CHANNEL, FACECHANNEL_MAX
};

class alignas(4) idVoiceTrack : public idResource {
public:
    enum eventOffset_t : int {
        EVENTOFFSET_FORWARDS = 1,
        EVENTOFFSET_BACKWARDS = -1
    };

    struct idFrameRef {
        std::uint16_t offset;
        std::uint16_t numIndices;
    };

    class idFrameRefIndexBuffer {
    public:
        idFrameRefIndexBuffer();
        ~idFrameRefIndexBuffer();
        void Alloc(int count);
        void Write(idFile& file) const;
        void Read(idFile& file);

        std::uint16_t curOffset;
        std::uint16_t size;
        std::uint16_t* indices;
    };

    struct flags_t {
        unsigned char useExactDuration : 1;
        unsigned char useRealTime : 1;
        unsigned char edited : 1;
        unsigned char compressed : 1;
        unsigned char suppressBlinking : 1;
        unsigned char noLipSync : 1;
        unsigned char clearAnimAfter : 1;
        unsigned char cycleAnim : 1;
    };

    struct idSubtitleText {
        idStr word;
        millisecond_t time;
    };
    struct frameInfo_t { int frame; int loop; };
    struct localizedVTROnDisc {
        char name[256]; char lang[16]; int offset; int size; void* data;
    };

    explicit idVoiceTrack(const char* defaultVisemeSetName = nullptr);
    ~idVoiceTrack() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;

    static mood_t GetMoodForName(const char* name);
    static faceChannel_t GetFaceChannelForName(const char* name);
    static const char* GetMoodAnimName(mood_t mood);
    static const char* GetMoodName(mood_t mood);
    static const char* GetFaceChannelName(faceChannel_t channel);
    static unsigned int CalcTextCRC(const char* text);

    void SetTrackTextId(const idStrId& id);
    void SetSoundShader(const idSoundShader* shader);
    bool IsEdited() const;
    bool IsCustomized() const;
    int Memory() const;
    int FindLastEvent() const;
    int FindNextEventForFrame(int startIndex, int frame) const;
    millisecond_t FindApproximateDuration() const;
    millisecond_t FindExactDuration() const;
    void OffsetEvents(eventOffset_t direction, bool visemesOnly);
    void OffsetVisemeEvents(eventOffset_t direction) {
        OffsetEvents(direction, true);
    }
    void FreeVisemeEvents(bool freeTextToo);
    void FreeTextEvents();
    void MergeVisemes();
    void BuildFrameRefs();
    void GetEvents(int startMS, int endMS, voiceEvent_t type,
        idList<const idVoiceEvent*, 5>& output) const;
    void GetEventsForFrameRef(int frameRef, voiceEvent_t type,
        idList<const idVoiceEvent*, 5>& output) const;
    idVoiceEvent* AllocEvent(voiceEvent_t type, vtrEventHandle_t& handle);

    void Write(idFile_String& output) const;
    void Parse(idLexer& lexer);
    bool LoadText(const char* fileName);
    bool LoadBinary(const char* fileName, unsigned int sourceTimestamp);
    bool WriteBinary(const char* fileName) const;
    bool Save(const char* fileName) const;

    idList<vtrEventHandle_t, 66> events;
    idVoiceEventManager voiceEventManager;
    idFrameRef* frameRefs;
    std::int16_t numFrameRefs;
    std::uint16_t frameRefPadding;
    idFrameRefIndexBuffer indexBuffer;
    bool rebuildFrameRefs;
    char visemeOffsetState;
    char offsetState;
    char statePadding;
    idAtomicString textLangKey;
    idStrId textId;
    unsigned int textCRC;
    unsigned int lipsyncTextCRC;
    idAtomicString subtitleLangKey;
    idStrId subtitleId;
    const idSoundShader* soundShader;
    unsigned int sampleTimestamp;
    unsigned int sampleCRC;
    idStr animName;
    faceChannel_t faceChannel;
    std::int16_t blendInMS;
    std::int16_t blendOutMS;
    unsigned int soundOffsetMS;
    unsigned int visemeOffsetMS;
    unsigned int animEventOffsetMS;
    unsigned int moodEventOffsetMS;
    unsigned int gameEventOffsetMS;
    unsigned int textEventOffsetMS;
    flags_t flags;
    std::uint8_t flagsPadding[3];
    float weightScale;
    mood_t defaultMood;
    const idDeclVisemeSet* declVisemeSet;
    unsigned int timestamp;
    millisecond_t approximateDuration;

    static idTypedResourceList<idVoiceTrack> resourceList;
    static const char* const moodNames[MOOD_MAX];
    static const char* const moodAnimNames[MOOD_MAX];
    static const char* const faceChannelNames[FACECHANNEL_MAX];
};

static_assert(sizeof(idVoiceTrack::idFrameRef) == 4,
    "Recovered voice frame-reference ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idVoiceTrack::idFrameRefIndexBuffer) == 8,
    "Recovered frame-reference index buffer ABI changed");
static_assert(sizeof(idVoiceTrack) == 292,
    "Recovered voice-track ABI changed");
#endif
