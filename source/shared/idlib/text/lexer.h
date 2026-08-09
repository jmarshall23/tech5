#pragma once

#include "token.h"

#include <cstdarg>

struct punctuation_t {
    char* p;
    int n;
};

const punctuation_t* GetDefaultPunctuations();

// Recovered from the lexer PDB enums and the subtype tests in lexer.cpp.
enum lexerTokenType_t : int {
    TT_STRING = 1,
    TT_LITERAL = 2,
    TT_NUMBER = 3,
    TT_NAME = 4,
    TT_PUNCTUATION = 5
};

enum lexerNumberSubtype_t : int {
    TT_INTEGER = 0x0001,
    TT_DECIMAL = 0x0002,
    TT_HEX = 0x0004,
    TT_OCTAL = 0x0008,
    TT_BINARY = 0x0010,
    TT_LONG = 0x0020,
    TT_UNSIGNED = 0x0040,
    TT_FLOAT = 0x0080,
    TT_IPADDRESS = 0x0100,
    TT_IPPORT = 0x0200,
    TT_VALUESVALID = 0x0400,
    TT_INFINITE = 0x0800,
    TT_INDEFINITE = 0x1000,
    TT_NAN = 0x2000
};

enum lexerPunctuation_t : int {
    P_RSHIFT_ASSIGN = 0, P_LSHIFT_ASSIGN, P_PARMS, P_PRECOMPMERGE,
    P_LOGIC_AND, P_LOGIC_OR, P_LOGIC_GEQ, P_LOGIC_LEQ, P_LOGIC_EQ,
    P_LOGIC_UNEQ, P_MUL_ASSIGN, P_DIV_ASSIGN, P_MOD_ASSIGN,
    P_ADD_ASSIGN, P_SUB_ASSIGN, P_INC, P_DEC, P_BIN_AND_ASSIGN,
    P_BIN_OR_ASSIGN, P_BIN_XOR_ASSIGN, P_RSHIFT, P_LSHIFT,
    P_SCOPE_RESOLUTION, P_MEMBER_SELECTION_OBJECT,
    P_MEMBER_SELECTION_POINTER, P_POINTER_TO_MEMBER_OBJECT,
    P_POINTER_TO_MEMBER_POINTER, P_MUL, P_DIV, P_MOD, P_ADD, P_SUB,
    P_ASSIGN, P_BIN_AND, P_BIN_OR, P_BIN_XOR, P_BIN_NOT, P_LOGIC_NOT,
    P_LOGIC_GREATER, P_LOGIC_LESS, P_COMMA, P_SEMICOLON, P_COLON,
    P_QUESTIONMARK, P_PARENTHESESOPEN, P_PARENTHESESCLOSE, P_BRACEOPEN,
    P_BRACECLOSE, P_SQBRACKETOPEN, P_SQBRACKETCLOSE, P_BACKSLASH,
    P_PRECOMP, P_DOLLAR, P_APOSTROPHE, P_QUOTE, P_AT
};

enum lexerFlags_t : int {
    LEXFL_NOERRORS = 0x1,
    LEXFL_NOWARNINGS = 0x2,
    LEXFL_NOFATALERRORS = 0x4,
    LEXFL_VCSTYLEREPORTS = 0x8,
    LEXFL_NOSTRINGCONCAT = 0x10,
    LEXFL_NOSTRINGESCAPECHARS = 0x20,
    LEXFL_NODOLLARPRECOMPILE = 0x40,
    LEXFL_NOBASEINCLUDES = 0x80,
    LEXFL_NOGLOBALDEFINES = 0x100,
    LEXFL_ALLOWPATHNAMES = 0x200,
    LEXFL_ALLOWNUMBERNAMES = 0x400,
    LEXFL_ALLOWIPADDRESSES = 0x800,
    LEXFL_ALLOWFLOATEXCEPTIONS = 0x1000,
    LEXFL_ALLOWMULTICHARLITERALS = 0x2000,
    LEXFL_ALLOWBACKSLASHSTRINGCONCAT = 0x4000,
    LEXFL_ONLYSTRINGS = 0x8000,
    LEXFL_NOEMITSTRINGESCAPECHARS = 0x10000,
    LEXFL_ALLOWRAWSTRINGBLOCKS = 0x20000,
    LEXFL_THROWFATAL = 0x40000,
    LEXFL_NOSTRINGS = 0x80000,
    LEXFL_ALLOWWILDCARD = 0x100000,
    LEXFL_REPORT_MULTIPLE_ERRORS = 0x200000
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
