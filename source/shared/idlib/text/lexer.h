#pragma once

#include "token.h"

#include <cstdarg>

struct punctuation_t {
    char* p;
    int n;
};

class alignas(4) idLexer {
public:
    explicit idLexer(int flags = 0);
    ~idLexer();

    bool LoadFile(const char* fileName, bool OSPath = false);
    bool LoadFilePartial(const char* fileName, bool OSPath, int length);
    bool LoadMemory(const char* pointer, unsigned int length,
        const char* name);
    void FreeSource();
    void Reset();
    bool SetScriptP(const char* pointer);
    void SetPunctuations(const punctuation_t* punctuation);

    bool ReadToken(idToken& token);
    bool ReadTokenOnLine(idToken& token);
    void UnreadToken();
    bool ExpectTokenString(const char* string);
    bool ExpectTokenType(int type, int subtype, idToken& token);
    bool ExpectAnyToken(idToken& token);
    bool CheckTokenString(const char* string);
    bool CheckTokenType(int type, int subtype, idToken& token);
    bool PeekTokenString(const char* string);
    bool PeekTokenType(int type, int subtype, idToken& token);

    bool SkipUntilString(const char* string);
    bool SkipRestOfLine();
    bool SkipBracedSection(bool parseFirstBrace = true);
    bool SkipWhiteSpace(bool currentLine);
    bool ParseBracedSectionExact(idStr& out, bool parseFirstBrace,
        char openBrace = '{', char closeBrace = '}');
    const char* ParseRestOfLine(idStr& out);
    const char* ParseCompleteLine(idStr& out);
    int ParseInt();
    unsigned int ParseUnsignedInt();
    bool ParseBool();
    float ParseFloat(bool* errorFlag = nullptr);
    bool Parse1DMatrix(int x, float* matrix, bool expectCommas = false);
    bool Parse2DMatrix(int y, int x, float* matrix);

    int GetLastWhiteSpace(idStr& whiteSpace) const;
    int GetNextWhiteSpace(idStr& whiteSpace, bool currentLine);
    bool GetWhiteSpaceBeforeToken(const idToken& token,
        idStr& whiteSpace) const;
    const char* GetPunctuationFromId(int id) const;
    int GetPunctuationId(const char* punctuation) const;
    bool EndOfFile() const;
    bool HadError() const;
    bool HadWarning() const;
    const char* GetFileName() const { return filename.c_str(); }
    int GetFileOffset() const {
        return script_p == nullptr || buffer == nullptr
            ? 0 : static_cast<int>(script_p - buffer);
    }
    int GetLineNum() const { return line; }

    void Error(const char* format, ...);
    void Warning(const char* format, ...);

    bool loaded;
    idStr filename;
    int allocated;
    const char* buffer;
    const char* script_p;
    const char* end_p;
    const char* lastScript_p;
    const char* whiteSpaceStart_p;
    const char* whiteSpaceEnd_p;
    unsigned int fileTime;
    unsigned int length;
    int line;
    int lastline;
    int flags;
    const punctuation_t* punctuations;
    int* punctuationtable;
    int* nextpunctuation;
    idLexer* next;
    idStr errorMsg;
    bool hadError;
    bool hadWarning;

private:
    bool CheckString(const char* string) const;
    void CreatePunctuationTable(const punctuation_t* punctuation);
    bool ReadEscapeCharacter(char* character);
    bool ReadName(idToken& token);
    bool ReadNumber(idToken& token);
    bool ReadPunctuation(idToken& token);
    bool ReadRawStringBlock(idToken& token);
    bool ReadString(idToken& token, int quote);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(punctuation_t) == 8,
    "Recovered punctuation_t ABI changed");
static_assert(sizeof(idLexer) == 136, "Recovered idLexer ABI changed");
#endif
