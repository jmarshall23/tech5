#include "decls/voiceovers/declvisemeset.h"

#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

idDeclInfoTemplate<idDeclVisemeSet> idDeclVisemeSet::resourceList(
    "visemeSet", "idDeclVisemeSet", "vset");

idViseme::idViseme() : name(""), aliasName(""), viseme(-1) {}

idPhoneme::idPhoneme()
    : name(""), phoneme(-1), viseme(-1), weightScale(1.0f),
      durationScale(1.0f), timeOffsetMS(0) {}

idDeclVisemeSet::idDeclVisemeSet()
    : phonemeSet(), visemes(16), phonemes(16), silenceViseme(-1),
      silencePhoneme(-1) {}

idDeclVisemeSet::~idDeclVisemeSet() = default;
idDeclInfo* idDeclVisemeSet::GetDeclInfo() const { return &resourceList; }

const char* idDeclVisemeSet::DefaultDefinition() const {
    return "{\n"
        "\tphonemeSet \"\"\n"
        "\tvisemeSilence viseme_REST\n"
        "\tphonemeSilence x\n"
        "\tvisemes {\n"
        "\t}\n"
        "\tphonemes {\n"
        "\t}\n"
        "}\n";
}

int idDeclVisemeSet::VisemeForName(const char* const visemeName) const {
    if (visemeName == nullptr) return -1;
    for (int index = 0; index < visemes.Num(); ++index)
        if (_stricmp(visemes[index].name.c_str(), visemeName) == 0)
            return index;
    return -1;
}

int idDeclVisemeSet::PhonemeForName(const char* const phonemeName) const {
    if (phonemeName == nullptr) return -1;
    for (int index = 0; index < phonemes.Num(); ++index)
        if (_stricmp(phonemes[index].name.c_str(), phonemeName) == 0)
            return index;
    return -1;
}

void idDeclVisemeSet::FreeData() {
    visemes.Clear();
    phonemes.Clear();
}

unsigned int idDeclVisemeSet::Size() const {
    return static_cast<unsigned int>(
        12 * (2 * (phonemes.NumAllocated() + 4) + visemes.NumAllocated()));
}

void idDeclVisemeSet::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    idToken token;
    if (!parser->ExpectTokenString("phonemeSet")
        || parser->ExpectTokenType(TT_STRING, 0, token) == 0) return;
    phonemeSet = token.c_str();

    idStr silenceVisemeName;
    idStr silencePhonemeName;
    if (!parser->ExpectTokenString("visemeSilence")
        || parser->ExpectTokenType(TT_NAME, 0, token) == 0) return;
    silenceVisemeName = token.c_str();
    if (!parser->ExpectTokenString("phonemeSilence")
        || parser->ExpectTokenType(TT_NAME, 0, token) == 0) return;
    silencePhonemeName = token.c_str();

    if (!parser->ExpectTokenString("visemes")
        || parser->ExpectTokenType(TT_PUNCTUATION, P_BRACEOPEN, token) == 0)
        return;
    while (parser->ReadToken(token)) {
        if (token.type == TT_PUNCTUATION
            && token.subtype == P_BRACECLOSE) break;
        if (token.type != TT_NAME) {
            parser->Error("Expected a viseme name, read '%s'", token.c_str());
            return;
        }
        idViseme viseme;
        viseme.name.Set(token.c_str());
        viseme.viseme = visemes.Num();
        if (!parser->ExpectTokenString("{")
            || !parser->ExpectTokenString("alias")
            || parser->ExpectTokenType(TT_STRING, 0, token) == 0) return;
        viseme.aliasName.Set(token.c_str());
        visemes.Append(viseme);
        if (!parser->ExpectTokenString("}")) return;
    }

    if (!parser->ExpectTokenString("phonemes")
        || parser->ExpectTokenType(TT_PUNCTUATION, P_BRACEOPEN, token) == 0)
        return;
    while (parser->ReadToken(token)) {
        if (token.type == TT_PUNCTUATION
            && token.subtype == P_BRACECLOSE) break;
        if (token.type != TT_NAME) {
            parser->Error("Expected a phoneme name, but read '%s'",
                token.c_str());
            return;
        }
        const idStr phonemeName(token.c_str());
        idPhoneme phoneme;
        phoneme.name.Set(phonemeName.c_str());
        phoneme.phoneme = phonemes.Num();

        if (parser->CheckTokenType(TT_PUNCTUATION, P_BRACEOPEN, token) != 0) {
            while (parser->ReadToken(token)) {
                if (token.type == TT_PUNCTUATION
                    && token.subtype == P_BRACECLOSE) break;
                if (_stricmp(token.c_str(), "weightScale") == 0) {
                    phoneme.weightScale = parser->ParseFloat();
                    if (phoneme.weightScale < 0.0f)
                        parser->Error("Negative weight scale in phoneme '%s'",
                            phonemeName.c_str());
                } else if (_stricmp(token.c_str(), "durationScale") == 0) {
                    phoneme.durationScale = parser->ParseFloat();
                    if (phoneme.durationScale < 0.0f)
                        parser->Error(
                            "Negative duration scale in phoneme '%s'",
                            phonemeName.c_str());
                } else if (_stricmp(token.c_str(), "timeOffsetMS") == 0) {
                    phoneme.timeOffsetMS = parser->ParseInt();
                } else {
                    const int visemeIndex = VisemeForName(token.c_str());
                    if (visemeIndex < 0) {
                        parser->Error(
                            "Unknown token '%s' in phoneme '%s', expected phoneme property.",
                            token.c_str(), phonemeName.c_str());
                    } else if (phoneme.viseme >= 0) {
                        parser->Error(
                            "Multiple visemes specified in phoneme '%s'",
                            phonemeName.c_str());
                    } else {
                        phoneme.viseme = visemeIndex;
                    }
                }
            }
        } else {
            if (parser->ExpectTokenType(TT_PUNCTUATION, P_ASSIGN, token) == 0
                || parser->ExpectTokenType(TT_NAME, 0, token) == 0) return;
            phoneme.viseme = VisemeForName(token.c_str());
            if (phoneme.viseme < 0)
                parser->Error(
                    "Phoneme '%s' maps to viseme '%s', which does not exist.",
                    phonemeName.c_str(), token.c_str());
        }
        phonemes.Append(phoneme);
    }

    if (parser->ExpectTokenType(TT_PUNCTUATION, P_BRACECLOSE, token) == 0)
        return;
    silenceViseme = VisemeForName(silenceVisemeName.c_str());
    silencePhoneme = PhonemeForName(silencePhonemeName.c_str());
}
