#include "idlib/text/lexer.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>

namespace {

#define LEX_PUNCTUATION(text, value) { const_cast<char*>(text), value }
const punctuation_t defaultPunctuations[] = {
    LEX_PUNCTUATION(">>=", P_RSHIFT_ASSIGN),
    LEX_PUNCTUATION("<<=", P_LSHIFT_ASSIGN),
    LEX_PUNCTUATION("...", P_PARMS),
    LEX_PUNCTUATION("##", P_PRECOMPMERGE),
    LEX_PUNCTUATION("&&", P_LOGIC_AND),
    LEX_PUNCTUATION("||", P_LOGIC_OR),
    LEX_PUNCTUATION(">=", P_LOGIC_GEQ),
    LEX_PUNCTUATION("<=", P_LOGIC_LEQ),
    LEX_PUNCTUATION("==", P_LOGIC_EQ),
    LEX_PUNCTUATION("!=", P_LOGIC_UNEQ),
    LEX_PUNCTUATION("*=", P_MUL_ASSIGN),
    LEX_PUNCTUATION("/=", P_DIV_ASSIGN),
    LEX_PUNCTUATION("%=", P_MOD_ASSIGN),
    LEX_PUNCTUATION("+=", P_ADD_ASSIGN),
    LEX_PUNCTUATION("-=", P_SUB_ASSIGN),
    LEX_PUNCTUATION("++", P_INC),
    LEX_PUNCTUATION("--", P_DEC),
    LEX_PUNCTUATION("&=", P_BIN_AND_ASSIGN),
    LEX_PUNCTUATION("|=", P_BIN_OR_ASSIGN),
    LEX_PUNCTUATION("^=", P_BIN_XOR_ASSIGN),
    LEX_PUNCTUATION(">>", P_RSHIFT),
    LEX_PUNCTUATION("<<", P_LSHIFT),
    LEX_PUNCTUATION("::", P_SCOPE_RESOLUTION),
    LEX_PUNCTUATION(".", P_MEMBER_SELECTION_OBJECT),
    LEX_PUNCTUATION("->", P_MEMBER_SELECTION_POINTER),
    LEX_PUNCTUATION(".*", P_POINTER_TO_MEMBER_OBJECT),
    LEX_PUNCTUATION("->*", P_POINTER_TO_MEMBER_POINTER),
    LEX_PUNCTUATION("*", P_MUL),
    LEX_PUNCTUATION("/", P_DIV),
    LEX_PUNCTUATION("%", P_MOD),
    LEX_PUNCTUATION("+", P_ADD),
    LEX_PUNCTUATION("-", P_SUB),
    LEX_PUNCTUATION("=", P_ASSIGN),
    LEX_PUNCTUATION("&", P_BIN_AND),
    LEX_PUNCTUATION("|", P_BIN_OR),
    LEX_PUNCTUATION("^", P_BIN_XOR),
    LEX_PUNCTUATION("~", P_BIN_NOT),
    LEX_PUNCTUATION("!", P_LOGIC_NOT),
    LEX_PUNCTUATION(">", P_LOGIC_GREATER),
    LEX_PUNCTUATION("<", P_LOGIC_LESS),
    LEX_PUNCTUATION(",", P_COMMA),
    LEX_PUNCTUATION(";", P_SEMICOLON),
    LEX_PUNCTUATION(":", P_COLON),
    LEX_PUNCTUATION("?", P_QUESTIONMARK),
    LEX_PUNCTUATION("(", P_PARENTHESESOPEN),
    LEX_PUNCTUATION(")", P_PARENTHESESCLOSE),
    LEX_PUNCTUATION("{", P_BRACEOPEN),
    LEX_PUNCTUATION("}", P_BRACECLOSE),
    LEX_PUNCTUATION("[", P_SQBRACKETOPEN),
    LEX_PUNCTUATION("]", P_SQBRACKETCLOSE),
    LEX_PUNCTUATION("\\", P_BACKSLASH),
    LEX_PUNCTUATION("#", P_PRECOMP),
    LEX_PUNCTUATION("$", P_DOLLAR),
    LEX_PUNCTUATION("'", P_APOSTROPHE),
    LEX_PUNCTUATION("\"", P_QUOTE),
    LEX_PUNCTUATION("@", P_AT),
    { nullptr, 0 }
};
#undef LEX_PUNCTUATION

bool IsNameStart(const int character) {
    return std::isalpha(static_cast<unsigned char>(character)) != 0
        || character == '_';
}

bool IsNameCharacter(const int character) {
    return std::isalnum(static_cast<unsigned char>(character)) != 0
        || character == '_';
}

void AppendRange(idStr& string, const char* first, const char* last) {
    while (first < last) string.Append(*first++);
}

bool TokenMatchesType(const idToken& token, const int type,
        const int subtype) {
    if (token.type != type) return false;
    if (type == TT_NUMBER) return (token.subtype & subtype) == subtype;
    if (type == TT_PUNCTUATION) return token.subtype == subtype;
    return true;
}

const char* TokenTypeName(const int type) {
    switch (type) {
    case TT_STRING: return "string";
    case TT_LITERAL: return "literal";
    case TT_NUMBER: return "number";
    case TT_NAME: return "name";
    case TT_PUNCTUATION: return "punctuation";
    default: return "unknown type";
    }
}

} // namespace

idLexer::idLexer(const int flags_)
    : loaded(false), filename(""), allocated(0), buffer(nullptr),
      script_p(nullptr), end_p(nullptr), lastScript_p(nullptr),
      whiteSpaceStart_p(nullptr), whiteSpaceEnd_p(nullptr), fileTime(0),
      length(0), line(0), lastline(0), flags(flags_), punctuations(nullptr),
      punctuationtable(nullptr), nextpunctuation(nullptr), next(nullptr),
      errorMsg(), hadError(false), hadWarning(false) {
    SetPunctuations(nullptr);
}

idLexer::~idLexer() {
    FreeSource();
}

void idLexer::CreatePunctuationTable(const punctuation_t* const list) {
    if (punctuationtable != nullptr) std::free(punctuationtable);
    if (nextpunctuation != nullptr) std::free(nextpunctuation);
    punctuationtable = static_cast<int*>(std::malloc(256 * sizeof(int)));
    int count = 0;
    while (list != nullptr && list[count].p != nullptr) ++count;
    nextpunctuation = count > 0
        ? static_cast<int*>(std::malloc(count * sizeof(int))) : nullptr;
    if (punctuationtable == nullptr) return;
    std::fill(punctuationtable, punctuationtable + 256, -1);
    if (nextpunctuation != nullptr) {
        std::fill(nextpunctuation, nextpunctuation + count, -1);
    }
    // The recovered table chains longest spellings first for each byte.
    for (int index = 0; index < count; ++index) {
        const unsigned char first =
            static_cast<unsigned char>(list[index].p[0]);
        int* link = &punctuationtable[first];
        while (*link >= 0 && std::strlen(list[*link].p)
                >= std::strlen(list[index].p)) {
            link = &nextpunctuation[*link];
        }
        nextpunctuation[index] = *link;
        *link = index;
    }
}

void idLexer::SetPunctuations(const punctuation_t* punctuation) {
    if (punctuation == nullptr) punctuation = defaultPunctuations;
    CreatePunctuationTable(punctuation);
    punctuations = punctuation;
}

const char* idLexer::GetPunctuationFromId(const int id) const {
    if (punctuations == nullptr) return "unknown punctuation";
    for (int index = 0; punctuations[index].p != nullptr; ++index) {
        if (punctuations[index].n == id) return punctuations[index].p;
    }
    return "unknown punctuation";
}

int idLexer::GetPunctuationId(const char* const punctuation) const {
    if (punctuations == nullptr || punctuation == nullptr) return 0;
    for (int index = 0; punctuations[index].p != nullptr; ++index) {
        if (idStr::Cmp(punctuations[index].p, punctuation) == 0) {
            return punctuations[index].n;
        }
    }
    return 0;
}

bool idLexer::CheckString(const char* const string) const {
    if (script_p == nullptr || string == nullptr) return false;
    const std::size_t count = std::strlen(string);
    return script_p + count <= end_p
        && std::memcmp(script_p, string, count) == 0;
}

bool idLexer::LoadFile(const char* const fileName, const bool OSPath) {
    return LoadFilePartial(fileName, OSPath,
        (std::numeric_limits<int>::max)());
}

bool idLexer::LoadFilePartial(const char* const fileName,
        const bool OSPath, const int maximumLength) {
    if (loaded) {
        idLibPrint::Error("LoadFile: another script already loaded");
    }
    if (fileSystem == nullptr || fileName == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    if (file.file == nullptr) return false;
    const std::int64_t fileLength = file->Length();
    length = static_cast<unsigned int>((std::max<std::int64_t>)(0,
        (std::min<std::int64_t>)(fileLength, maximumLength)));
    char* memory = static_cast<char*>(std::malloc(length + 1u));
    if (memory == nullptr) return false;
    if (file->Read(memory, length) != length) {
        std::free(memory);
        length = 0;
        return false;
    }
    memory[length] = '\0';
    buffer = memory;
    allocated = 1;
    fileTime = file->Timestamp();
    filename = OSPath ? file->GetFullPath() : file->GetName();
    loaded = true;
    script_p = buffer;
    end_p = buffer + length;
    lastScript_p = buffer;
    line = lastline = 1;
    return true;
}

bool idLexer::LoadMemory(const char* const pointer,
        const unsigned int memoryLength, const char* const name) {
    if (loaded) {
        idLibPrint::Error("LoadMemory: another script already loaded");
    }
    if (pointer == nullptr) return false;
    filename = name != nullptr ? name : "memory";
    buffer = pointer;
    length = memoryLength;
    fileTime = 0;
    script_p = pointer;
    end_p = pointer + memoryLength;
    lastScript_p = pointer;
    line = lastline = 1;
    allocated = 0;
    loaded = true;
    return true;
}

void idLexer::FreeSource() {
    if (punctuationtable != nullptr) {
        std::free(punctuationtable);
        punctuationtable = nullptr;
    }
    if (nextpunctuation != nullptr) {
        std::free(nextpunctuation);
        nextpunctuation = nullptr;
    }
    if (allocated != 0) std::free(const_cast<char*>(buffer));
    allocated = 0;
    buffer = nullptr;
    script_p = nullptr;
    end_p = nullptr;
    lastScript_p = nullptr;
    whiteSpaceStart_p = nullptr;
    whiteSpaceEnd_p = nullptr;
    length = 0;
    filename.Clear();
    loaded = false;
}

void idLexer::Reset() {
    whiteSpaceStart_p = nullptr;
    whiteSpaceEnd_p = nullptr;
    line = lastline = 1;
    script_p = lastScript_p = buffer;
}

bool idLexer::SetScriptP(const char* const pointer) {
    if (buffer == nullptr || end_p == nullptr
            || pointer < buffer || pointer > end_p) return false;
    script_p = pointer;
    return true;
}

void idLexer::UnreadToken() {
    script_p = lastScript_p;
    line = lastline;
}

bool idLexer::EndOfFile() const {
    return script_p == nullptr || end_p == nullptr || script_p >= end_p;
}

bool idLexer::HadError() const { return hadError; }
bool idLexer::HadWarning() const { return hadWarning; }

void idLexer::Error(const char* const format, ...) {
    hadError = true;
    if ((flags & LEXFL_NOERRORS) != 0) return;
    char detail[1024] = {};
    va_list arguments;
    va_start(arguments, format);
    _vsnprintf_s(detail, sizeof(detail), _TRUNCATE,
        format != nullptr ? format : "", arguments);
    va_end(arguments);
    char message[1400] = {};
    if ((flags & LEXFL_VCSTYLEREPORTS) != 0) {
        _snprintf_s(message, sizeof(message), _TRUNCATE,
            "%s(%d) : error : %s", filename.c_str(), line, detail);
    } else {
        _snprintf_s(message, sizeof(message), _TRUNCATE,
            "file %s, line %d: %s", filename.c_str(), line, detail);
    }
    if (errorMsg.Length() == 0) errorMsg = message;
    if ((flags & LEXFL_NOFATALERRORS) != 0) {
        idLibPrint::Warning("%s", message);
        return;
    }
    idLibPrint::Error("%s", message);
}

void idLexer::Warning(const char* const format, ...) {
    hadWarning = true;
    if ((flags & LEXFL_NOWARNINGS) != 0) return;
    char detail[1024] = {};
    va_list arguments;
    va_start(arguments, format);
    _vsnprintf_s(detail, sizeof(detail), _TRUNCATE,
        format != nullptr ? format : "", arguments);
    va_end(arguments);
    idLibPrint::Warning("file %s, line %d: %s",
        filename.c_str(), line, detail);
}

bool idLexer::SkipWhiteSpace(const bool currentLine) {
    if (script_p == nullptr || script_p >= end_p) return false;
    for (;;) {
        while (script_p < end_p
                && static_cast<unsigned char>(*script_p) <= 32u) {
            if (*script_p++ == '\n') {
                ++line;
                if (currentLine) return true;
            }
        }
        if (script_p >= end_p || *script_p == '\0') return false;
        if (script_p + 1 < end_p && script_p[0] == '/'
                && script_p[1] == '/') {
            script_p += 2;
            while (script_p < end_p && *script_p != '\0'
                    && *script_p != '\n') ++script_p;
            if (script_p < end_p && *script_p == '\n') {
                ++script_p;
                ++line;
                if (currentLine) return true;
                continue;
            }
            return false;
        }
        if (script_p + 1 < end_p && script_p[0] == '/'
                && script_p[1] == '*') {
            script_p += 2;
            while (script_p < end_p) {
                if (script_p + 1 < end_p && script_p[0] == '*'
                        && script_p[1] == '/') {
                    script_p += 2;
                    break;
                }
                if (*script_p == '\n') ++line;
                if (script_p + 1 < end_p && script_p[0] == '/'
                        && script_p[1] == '*') Warning("nested comment");
                ++script_p;
            }
            if (script_p >= end_p) return false;
            continue;
        }
        return true;
    }
}

bool idLexer::ReadEscapeCharacter(char* const character) {
    if (script_p == nullptr || script_p >= end_p || *script_p != '\\') {
        return false;
    }
    ++script_p;
    if (script_p >= end_p) return false;
    if ((flags & LEXFL_NOEMITSTRINGESCAPECHARS) != 0) {
        *character = *script_p++;
        return true;
    }
    const char escape = *script_p++;
    switch (escape) {
    case '\\': *character = '\\'; return true;
    case '\'': *character = '\''; return true;
    case '"': *character = '"'; return true;
    case '?': *character = '?'; return true;
    case 'a': *character = '\a'; return true;
    case 'b': *character = '\b'; return true;
    case 'f': *character = '\f'; return true;
    case 'n': *character = '\n'; return true;
    case 'r': *character = '\r'; return true;
    case 't': *character = '\t'; return true;
    case 'v': *character = '\v'; return true;
    case 'x': {
        unsigned int value = 0;
        int digits = 0;
        while (script_p < end_p
                && std::isxdigit(static_cast<unsigned char>(*script_p))) {
            const char digit = *script_p++;
            value = value * 16u + static_cast<unsigned int>(
                digit >= '0' && digit <= '9' ? digit - '0'
                : (digit | 32) - 'a' + 10);
            ++digits;
        }
        if (digits == 0) Error("unknown escape char");
        if (value > 255u) Warning("too large value in escape character");
        *character = static_cast<char>(value);
        return true;
    }
    default:
        if (escape >= '0' && escape <= '9') {
            unsigned int value = static_cast<unsigned int>(escape - '0');
            while (script_p < end_p && *script_p >= '0'
                    && *script_p <= '9') {
                value = value * 10u
                    + static_cast<unsigned int>(*script_p++ - '0');
            }
            if (value > 255u) Warning("too large value in escape character");
            *character = static_cast<char>(value);
            return true;
        }
        Error("unknown escape char");
        *character = escape;
        return false;
    }
}

bool idLexer::ReadString(idToken& token, const int quote) {
    token.type = quote == '"' ? TT_STRING : TT_LITERAL;
    ++script_p;
    for (;;) {
        while (script_p < end_p && *script_p != quote) {
            if (*script_p == '\0' || *script_p == '\n') {
                Error("missing trailing quote");
                return false;
            }
            if (*script_p == '\\'
                    && (flags & LEXFL_NOSTRINGESCAPECHARS) == 0) {
                if ((flags & LEXFL_NOEMITSTRINGESCAPECHARS) != 0) {
                    token.Append('\\');
                }
                char escaped = 0;
                if (!ReadEscapeCharacter(&escaped)) return false;
                token.Append(escaped);
            } else {
                token.Append(*script_p++);
            }
        }
        if (script_p >= end_p) {
            Error("missing trailing quote");
            return false;
        }
        ++script_p;
        if (quote != '"' || (flags & LEXFL_NOSTRINGCONCAT) != 0) break;
        const char* const afterQuote = script_p;
        const int quoteLine = line;
        if (!SkipWhiteSpace(false) || script_p >= end_p
                || *script_p != quote) {
            script_p = afterQuote;
            line = quoteLine;
            break;
        }
        ++script_p;
    }
    if (token.type == TT_LITERAL) {
        if ((flags & LEXFL_ALLOWMULTICHARLITERALS) == 0
                && token.Length() != 1) {
            Warning("literal is not one character long");
        }
        token.subtype = token.Length() > 0
            ? static_cast<unsigned char>(token.c_str()[0]) : 0;
    } else {
        token.subtype = token.Length();
    }
    return true;
}

bool idLexer::ReadRawStringBlock(idToken& token) {
    if (!CheckString("<%")) return false;
    script_p += 2;
    token.type = TT_STRING;
    while (script_p < end_p && !CheckString("%>")) {
        if (*script_p == '\n') ++line;
        token.Append(*script_p++);
    }
    if (script_p >= end_p) {
        Error("missing %%> for raw string block");
        return false;
    }
    script_p += 2;
    token.subtype = token.Length();
    return true;
}

bool idLexer::ReadName(idToken& token) {
    token.type = TT_NAME;
    while (script_p < end_p) {
        const char character = *script_p;
        const bool accepted = IsNameCharacter(character)
            || ((flags & LEXFL_ONLYSTRINGS) != 0 && character == '-')
            || ((flags & LEXFL_ALLOWPATHNAMES) != 0
                && (character == '/' || character == '\\'
                    || character == ':' || character == '.'
                    || character == '@'))
            || ((flags & LEXFL_ALLOWWILDCARD) != 0 && character == '*');
        if (!accepted) break;
        token.Append(character);
        ++script_p;
    }
    token.subtype = token.Length();
    return token.Length() != 0;
}

bool idLexer::ReadNumber(idToken& token) {
    token.type = TT_NUMBER;
    token.subtype = 0;
    const char* const start = script_p;
    bool isFloat = false;
    bool isHex = false;
    bool isBinary = false;
    bool isOctal = false;
    int dots = 0;
    if (script_p + 1 < end_p && script_p[0] == '0'
            && (script_p[1] == 'x' || script_p[1] == 'X')) {
        isHex = true;
        script_p += 2;
        while (script_p < end_p
                && std::isxdigit(static_cast<unsigned char>(*script_p))) {
            ++script_p;
        }
    } else if (script_p + 1 < end_p && script_p[0] == '0'
            && (script_p[1] == 'b' || script_p[1] == 'B')) {
        isBinary = true;
        script_p += 2;
        while (script_p < end_p && (*script_p == '0' || *script_p == '1')) {
            ++script_p;
        }
    } else {
        if (*script_p == '0' && script_p + 1 < end_p
                && script_p[1] != '.') isOctal = true;
        while (script_p < end_p) {
            const char character = *script_p;
            if (character >= '0' && character <= '9') {
                ++script_p;
                continue;
            }
            if (character == '.') {
                ++dots;
                ++script_p;
                continue;
            }
            break;
        }
        if (dots == 1) isFloat = true;
        if (script_p < end_p && (*script_p == 'e' || *script_p == 'E')) {
            isFloat = true;
            ++script_p;
            if (script_p < end_p && (*script_p == '+' || *script_p == '-')) {
                ++script_p;
            }
            while (script_p < end_p && std::isdigit(
                    static_cast<unsigned char>(*script_p))) ++script_p;
        }
        if (dots > 1 && (flags & LEXFL_ALLOWIPADDRESSES) != 0) {
            token.subtype |= TT_IPADDRESS;
            if (script_p < end_p && *script_p == ':') {
                token.subtype |= TT_IPPORT;
                ++script_p;
                while (script_p < end_p && std::isdigit(
                        static_cast<unsigned char>(*script_p))) ++script_p;
            }
        }
    }

    bool unsignedSuffix = false;
    bool longSuffix = false;
    while (script_p < end_p) {
        const char suffix = *script_p;
        if (suffix == 'u' || suffix == 'U') {
            unsignedSuffix = true;
            ++script_p;
        } else if (suffix == 'l' || suffix == 'L') {
            longSuffix = true;
            ++script_p;
        } else if (suffix == 'f' || suffix == 'F') {
            isFloat = true;
            ++script_p;
        } else {
            break;
        }
    }
    AppendRange(token, start, script_p);
    token.subtype |= isFloat ? TT_FLOAT : TT_INTEGER;
    token.subtype |= isHex ? TT_HEX : isBinary ? TT_BINARY
        : isOctal && !isFloat ? TT_OCTAL : TT_DECIMAL;
    if (unsignedSuffix) token.subtype |= TT_UNSIGNED;
    if (longSuffix) token.subtype |= TT_LONG;

    errno = 0;
    if (isBinary) {
        unsigned int value = 0;
        for (const char* cursor = start + 2; cursor < script_p
                && (*cursor == '0' || *cursor == '1'); ++cursor) {
            value = value * 2u + static_cast<unsigned int>(*cursor - '0');
        }
        token.intvalue = value;
        token.floatvalue = static_cast<float>(value);
    } else if (isFloat) {
        token.floatvalue = std::strtof(token.c_str(), nullptr);
        token.intvalue = static_cast<unsigned int>(token.floatvalue);
    } else {
        const int base = isHex ? 16 : isOctal ? 8 : 10;
        token.intvalue = static_cast<unsigned int>(
            std::strtoul(token.c_str(), nullptr, base));
        token.floatvalue = static_cast<float>(token.intvalue);
    }
    token.subtype |= TT_VALUESVALID;
    return script_p > start;
}

bool idLexer::ReadPunctuation(idToken& token) {
    if (punctuations == nullptr || script_p >= end_p) return false;
    int best = -1;
    std::size_t bestLength = 0;
    for (int index = 0; punctuations[index].p != nullptr; ++index) {
        const std::size_t count = std::strlen(punctuations[index].p);
        if (count <= bestLength || script_p + count > end_p) continue;
        if (std::memcmp(script_p, punctuations[index].p, count) == 0) {
            best = index;
            bestLength = count;
        }
    }
    if (best < 0) return false;
    static_cast<idStr&>(token) = punctuations[best].p;
    token.type = TT_PUNCTUATION;
    token.subtype = punctuations[best].n;
    script_p += bestLength;
    return true;
}

bool idLexer::ReadToken(idToken& token) {
    if (!loaded) idLibPrint::Error("ReadToken: no file loaded");
    if (script_p == nullptr || script_p >= end_p) return false;
    lastScript_p = script_p;
    lastline = line;
    token.Clear();
    token.type = 0;
    token.subtype = 0;
    token.intvalue = 0;
    token.floatvalue = 0.0f;
    token.flags = 0;
    whiteSpaceStart_p = script_p;
    token.whiteSpaceStart_p = script_p;
    if (!SkipWhiteSpace(false)) return false;
    if (script_p >= end_p) return false;
    whiteSpaceEnd_p = script_p;
    token.whiteSpaceEnd_p = script_p;
    token.line = line;
    token.linesCrossed = line - lastline;

    const char character = *script_p;
    if ((flags & LEXFL_ONLYSTRINGS) != 0) {
        if (character == '"' || character == '\'') {
            return ReadString(token, character);
        }
        return ReadName(token);
    }
    if (std::isdigit(static_cast<unsigned char>(character))
            || (character == '.' && script_p + 1 < end_p
                && std::isdigit(static_cast<unsigned char>(script_p[1])))) {
        if (!ReadNumber(token)) return false;
        if ((flags & LEXFL_ALLOWNUMBERNAMES) != 0
                && script_p < end_p && IsNameStart(*script_p)) {
            token.type = TT_NAME;
            while (script_p < end_p && IsNameCharacter(*script_p)) {
                token.Append(*script_p++);
            }
            token.subtype = token.Length();
        }
        return true;
    }
    if ((flags & LEXFL_ALLOWWILDCARD) != 0 && character == '*') {
        return ReadName(token);
    }
    if ((flags & LEXFL_NOSTRINGS) == 0
            && (character == '"' || character == '\'')) {
        return ReadString(token, character);
    }
    if (IsNameStart(character)
            || ((flags & LEXFL_ALLOWPATHNAMES) != 0 && character == '.')) {
        return ReadName(token);
    }
    if ((flags & LEXFL_ALLOWRAWSTRINGBLOCKS) != 0
            && CheckString("<%")) return ReadRawStringBlock(token);
    if (ReadPunctuation(token)) return true;
    Error("unknown punctuation %c", character);
    return false;
}

bool idLexer::ReadTokenOnLine(idToken& token) {
    const char* const previous = script_p;
    const int previousLine = line;
    if (!ReadToken(token)) return false;
    if (token.linesCrossed == 0) return true;
    script_p = previous;
    line = previousLine;
    return false;
}

bool idLexer::ExpectTokenString(const char* const string) {
    idToken token;
    if (!ReadToken(token)) {
        Error("couldn't find expected '%s'", string != nullptr ? string : "");
        return false;
    }
    if (idStr::Cmp(token.c_str(), string) != 0) {
        Error("expected '%s' but found '%s'", string, token.c_str());
        return false;
    }
    return true;
}

bool idLexer::ExpectTokenType(const int type, const int subtype,
        idToken& token) {
    if (!ReadToken(token)) {
        Error("couldn't read expected token");
        return false;
    }
    if (token.type != type) {
        Error("expected a %s but found '%s'", TokenTypeName(type),
            token.c_str());
        return false;
    }
    if (!TokenMatchesType(token, type, subtype)) {
        if (type == TT_PUNCTUATION) {
            Error("expected '%s' but found '%s'",
                GetPunctuationFromId(subtype), token.c_str());
        } else {
            Error("token '%s' has the wrong subtype", token.c_str());
        }
        return false;
    }
    return true;
}

bool idLexer::ExpectAnyToken(idToken& token) {
    if (ReadToken(token)) return true;
    Error("couldn't read expected token");
    return false;
}

bool idLexer::CheckTokenString(const char* const string) {
    idToken token;
    if (!ReadToken(token)) return false;
    if (idStr::Cmp(token.c_str(), string) == 0) return true;
    UnreadToken();
    return false;
}

bool idLexer::CheckTokenType(const int type, const int subtype,
        idToken& token) {
    idToken read;
    if (!ReadToken(read)) return false;
    if (!TokenMatchesType(read, type, subtype)) {
        UnreadToken();
        return false;
    }
    token = read;
    return true;
}

bool idLexer::PeekTokenString(const char* const string) {
    idToken token;
    if (!ReadToken(token)) return false;
    const bool result = idStr::Cmp(token.c_str(), string) == 0;
    UnreadToken();
    return result;
}

bool idLexer::PeekTokenType(const int type, const int subtype,
        idToken& token) {
    idToken read;
    if (!ReadToken(read)) return false;
    const bool result = TokenMatchesType(read, type, subtype);
    UnreadToken();
    if (result) token = read;
    return result;
}

bool idLexer::SkipUntilString(const char* const string) {
    idToken token;
    while (ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), string) == 0) return true;
    }
    return false;
}

bool idLexer::SkipRestOfLine() {
    idToken token;
    while (ReadToken(token)) {
        if (token.linesCrossed != 0) {
            UnreadToken();
            return true;
        }
    }
    return false;
}

bool idLexer::SkipBracedSection(const bool parseFirstBrace) {
    int depth = parseFirstBrace ? 0 : 1;
    idToken token;
    while (ReadToken(token)) {
        if (token.type != TT_PUNCTUATION) continue;
        if (idStr::Cmp(token.c_str(), "{") == 0) ++depth;
        else if (idStr::Cmp(token.c_str(), "}") == 0 && --depth <= 0) {
            return true;
        }
    }
    return false;
}

bool idLexer::ParseBracedSectionExact(idStr& out,
        const bool parseFirstBrace, const char openBrace,
        const char closeBrace) {
    out.Clear();
    int depth = 1;
    if (parseFirstBrace) {
        char brace[2] = { openBrace, '\0' };
        if (!ExpectTokenString(brace)) return false;
        out.Append(openBrace);
    }
    idToken token;
    while (ReadToken(token)) {
        idStr whiteSpace;
        GetWhiteSpaceBeforeToken(token, whiteSpace);
        out.Append(whiteSpace);
        if (token.type == TT_STRING) {
            out.Append('"'); out.Append(token); out.Append('"');
        } else if (token.type == TT_LITERAL) {
            out.Append('\''); out.Append(token); out.Append('\'');
        } else {
            out.Append(token);
        }
        if (token.type != TT_STRING) {
            if (token.Length() > 0 && token.c_str()[0] == openBrace) ++depth;
            else if (token.Length() > 0
                    && token.c_str()[0] == closeBrace && --depth <= 0) {
                return true;
            }
        }
    }
    return false;
}

const char* idLexer::ParseRestOfLine(idStr& out) {
    out.Clear();
    if (script_p == nullptr) return out.c_str();
    const char* first = script_p;
    while (script_p < end_p && *script_p != '\0' && *script_p != '\n') {
        ++script_p;
    }
    const char* last = script_p;
    while (first < last && static_cast<unsigned char>(*first) <= 32u) ++first;
    while (last > first && static_cast<unsigned char>(last[-1]) <= 32u) --last;
    AppendRange(out, first, last);
    if (script_p < end_p && *script_p == '\n') {
        ++script_p;
        ++line;
    }
    return out.c_str();
}

const char* idLexer::ParseCompleteLine(idStr& out) {
    out.Clear();
    if (script_p == nullptr) return out.c_str();
    const char* const first = script_p;
    while (script_p < end_p && *script_p != '\0') {
        const char character = *script_p++;
        if (character == '\n') {
            ++line;
            break;
        }
    }
    AppendRange(out, first, script_p);
    return out.c_str();
}

int idLexer::ParseInt() {
    idToken token;
    if (!ReadToken(token)) {
        Error("couldn't read expected integer");
        return 0;
    }
    bool negative = false;
    if (token.type == TT_PUNCTUATION
            && idStr::Cmp(token.c_str(), "-") == 0) {
        negative = true;
        if (!ExpectTokenType(TT_NUMBER, TT_INTEGER, token)) return 0;
    } else if (token.type != TT_NUMBER
            || (token.subtype & TT_INTEGER) == 0) {
        Error("expected integer value, found '%s'", token.c_str());
        return 0;
    }
    const int value = static_cast<int>(token.intvalue);
    return negative ? -value : value;
}

unsigned int idLexer::ParseUnsignedInt() {
    idToken token;
    if (!ExpectTokenType(TT_NUMBER, TT_INTEGER, token)) return 0;
    return token.intvalue;
}

bool idLexer::ParseBool() {
    idToken token;
    if (!ReadToken(token)) {
        Error("couldn't read expected boolean");
        return false;
    }
    if (token.type == TT_NUMBER) return token.intvalue != 0;
    if (idStr::Cmp(token.c_str(), "true") == 0) return true;
    if (idStr::Cmp(token.c_str(), "false") == 0) return false;
    Error("expected boolean value, found '%s'", token.c_str());
    return false;
}

float idLexer::ParseFloat(bool* const errorFlag) {
    if (errorFlag != nullptr) *errorFlag = false;
    idToken token;
    if (!ReadToken(token)) {
        if (errorFlag != nullptr) {
            Warning("couldn't read expected floating point number");
            *errorFlag = true;
        } else Error("couldn't read expected floating point number");
        return 0.0f;
    }
    bool negative = false;
    if (token.type == TT_PUNCTUATION
            && idStr::Cmp(token.c_str(), "-") == 0) {
        negative = true;
        if (!ExpectTokenType(TT_NUMBER, 0, token)) {
            if (errorFlag != nullptr) *errorFlag = true;
            return 0.0f;
        }
    } else if (token.type != TT_NUMBER) {
        if (errorFlag != nullptr) {
            Warning("expected float value, found '%s'", token.c_str());
            *errorFlag = true;
        } else Error("expected float value, found '%s'", token.c_str());
        return 0.0f;
    }
    return negative ? -token.floatvalue : token.floatvalue;
}

bool idLexer::Parse1DMatrix(const int x, float* const matrix,
        const bool expectCommas) {
    if (!ExpectTokenString("(")) return false;
    for (int index = 0; index < x; ++index) {
        matrix[index] = ParseFloat();
        if (expectCommas && index != x - 1
                && !ExpectTokenString(",")) return false;
    }
    return ExpectTokenString(")");
}

bool idLexer::Parse2DMatrix(const int y, const int x,
        float* const matrix) {
    if (!ExpectTokenString("(")) return false;
    for (int index = 0; index < y; ++index) {
        if (!Parse1DMatrix(x, matrix + index * x, false)) return false;
    }
    return ExpectTokenString(")");
}

int idLexer::GetLastWhiteSpace(idStr& whiteSpace) const {
    whiteSpace.Clear();
    if (whiteSpaceStart_p == nullptr || whiteSpaceEnd_p == nullptr) return 0;
    AppendRange(whiteSpace, whiteSpaceStart_p, whiteSpaceEnd_p);
    return whiteSpace.Length();
}

int idLexer::GetNextWhiteSpace(idStr& whiteSpace,
        const bool currentLine) {
    whiteSpaceStart_p = script_p;
    SkipWhiteSpace(currentLine);
    whiteSpaceEnd_p = script_p;
    return GetLastWhiteSpace(whiteSpace);
}

bool idLexer::GetWhiteSpaceBeforeToken(const idToken& token,
        idStr& whiteSpace) const {
    whiteSpace.Clear();
    if (buffer == nullptr || token.whiteSpaceStart_p == nullptr
            || token.whiteSpaceEnd_p == nullptr
            || token.whiteSpaceStart_p < buffer
            || token.whiteSpaceEnd_p < token.whiteSpaceStart_p
            || token.whiteSpaceEnd_p > end_p) return false;
    AppendRange(whiteSpace, token.whiteSpaceStart_p,
        token.whiteSpaceEnd_p);
    return true;
}
