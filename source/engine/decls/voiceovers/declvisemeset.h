#pragma once

#include "decls/decl.h"

struct idViseme {
    idViseme();
    idAtomicString name;
    idAtomicString aliasName;
    int viseme;
};

struct idPhoneme {
    idPhoneme();
    idAtomicString name;
    int phoneme;
    int viseme;
    float weightScale;
    float durationScale;
    int timeOffsetMS;
};

class idDeclVisemeSet : public idDecl {
public:
    idDeclVisemeSet();
    ~idDeclVisemeSet() override;
    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;

    int VisemeForName(const char* visemeName) const;
    int PhonemeForName(const char* phonemeName) const;

    idStr phonemeSet;
    idList<idViseme, 69> visemes;
    idList<idPhoneme, 70> phonemes;
    int silenceViseme;
    int silencePhoneme;

    static idDeclInfoTemplate<idDeclVisemeSet> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idViseme) == 12, "Recovered viseme ABI changed");
static_assert(sizeof(idPhoneme) == 24, "Recovered phoneme ABI changed");
static_assert(sizeof(idDeclVisemeSet) == 128,
    "Recovered viseme-set declaration ABI changed");
#endif
