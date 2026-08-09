#pragma once

#include "idlib/text/lexer.h"

class idLexerUTF8 {
public:
    explicit idLexerUTF8(int lexerFlags = 0);
    ~idLexerUTF8();

    void LoadMemory(const unsigned char* pointer, unsigned int length,
        const char* name);
    void UnreadToken();
    const char* GetPunctuationFromId(int id) const;
    bool ReadToken(idToken& token);
    bool CheckTokenType(int type, int subtype, idToken& token);
    bool ExpectTokenType(int type, int subtype, idToken& token);
    bool ExpectTokenString(const char* string);
    bool CheckTokenString(const char* string);
    bool SkipBracedSection(bool parseFirstBrace = true);
    float ParseFloat();
    int ParseInt();
    void Error(const char* format, ...);

    bool HadError() const { return hadError; }
    bool HadWarning() const { return hadWarning; }

    idStr filename;
    int flags;
    const unsigned char* buffer;
    const unsigned char* cur;
    const unsigned char* end;
    const unsigned char* prev;
    unsigned int len;
    int lastline;
    int line;
    const punctuation_t* punctuations;
    int* punctuationtable;
    int* nextpunctuation;
    bool loaded;
    bool hadError;
    bool hadWarning;

private:
    bool SkipWhitespace();
    bool ReadName(idToken& token);
    bool ReadPunctuation(idToken& token);
    void CreatePunctuationTable(const punctuation_t* punctuationList);
    bool ReadNumber(idToken& token);
    bool ReadEscapeCharacter(unsigned int& character);
    bool ReadString(idToken& token, unsigned int quote);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLexerUTF8) == 80,
    "Recovered UTF-8 lexer ABI changed");
#endif
