#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idDeclVisemeSet;
class idLexerUTF8;
class idVoiceTrack;

class idPhonemeTrack {
public:
    virtual ~idPhonemeTrack() = default;
    virtual bool Load(const idDeclVisemeSet* visemeSet, idLexerUTF8& lexer) = 0;
    virtual bool Load(const idDeclVisemeSet* visemeSet, const char* fileName) = 0;
    virtual bool GetVoiceTrack(idVoiceTrack& output, int generationFlags) const = 0;
};

class idPhonemeTrack_Annosoft : public idPhonemeTrack {
public:
    enum extendedPhoneme_t : int {
        EXPHONEME_PHONEME,
        EXPHONEME_WORD,
        EXPHONEME_PUNCTUATION,
        EXPHONEME_MAX
    };

    struct weight_t { int startMS; int endMS; float weight; };

    class idPhonemeEvent {
    public:
        idPhonemeEvent();
        idPhonemeEvent(const idPhonemeEvent& other);
        ~idPhonemeEvent();
        idPhonemeEvent& operator=(const idPhonemeEvent& other);

        int type;
        extendedPhoneme_t exType;
        int startMS;
        int endMS;
        std::int16_t numWeights;
        std::uint16_t weightPadding;
        weight_t* weights;
        idStr text;
    };

    idPhonemeTrack_Annosoft();
    ~idPhonemeTrack_Annosoft() override;
    bool Load(const idDeclVisemeSet* visemeSet, idLexerUTF8& lexer) override;
    bool Load(const idDeclVisemeSet* visemeSet, const char* fileName) override;
    bool GetVoiceTrack(idVoiceTrack& output, int generationFlags) const override;

    int GetNumFrames() const;
    bool GenerateAnimation(const char* fileName,
        const idDeclVisemeSet* visemeSet) const;

    idList<idPhonemeEvent, 68> phonemes;
};

const char* Lipsync_GetDictFileName(const char* language);
const char* Lipsync_IntermediateFilePathFromSampleName(const char* sampleName,
    idStr& filePath);
bool ConvertPhonemesToAnim(const char* inputFile,
    const idDeclVisemeSet* visemeSet);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhonemeTrack_Annosoft::weight_t) == 12,
    "Recovered Annosoft phoneme-weight ABI changed");
static_assert(sizeof(idPhonemeTrack_Annosoft::idPhonemeEvent) == 56,
    "Recovered Annosoft phoneme-event ABI changed");
static_assert(sizeof(idPhonemeTrack_Annosoft) == 20,
    "Recovered Annosoft phoneme-track ABI changed");
#endif
