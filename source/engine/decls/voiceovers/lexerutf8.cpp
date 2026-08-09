#include "decls/voiceovers/lexerutf8.h"

#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"

#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

unsigned int DecodeUTF8(const unsigned char* cursor,
        const unsigned char* end, int& byteCount) {
    byteCount = 0;
    if (cursor == nullptr || cursor >= end) return 0;
    const unsigned int first = *cursor;
    if (first < 0x80) { byteCount = 1; return first; }
    int count = 0;
    unsigned int value = 0;
    if ((first & 0xE0) == 0xC0) { count = 2; value = first & 0x1F; }
    else if ((first & 0xF0) == 0xE0) { count = 3; value = first & 0x0F; }
    else if ((first & 0xF8) == 0xF0) { count = 4; value = first & 0x07; }
    else { byteCount = 1; return first; }
    if (cursor + count > end) { byteCount = 1; return first; }
    for (int index = 1; index < count; ++index) {
        if ((cursor[index] & 0xC0) != 0x80) {
            byteCount = 1;
            return first;
        }
        value = (value << 6) | (cursor[index] & 0x3F);
    }
    byteCount = count;
    return value;
}

void AppendBytes(idToken& token, const unsigned char* bytes, int count) {
    for (int index = 0; index < count; ++index)
        token.Append(static_cast<char>(bytes[index]));
}

} // namespace

idLexerUTF8::idLexerUTF8(const int lexerFlags)
    : filename(), flags(lexerFlags), buffer(nullptr), cur(nullptr), end(nullptr),
      prev(nullptr), len(0), lastline(0), line(0),
      punctuations(GetDefaultPunctuations()), punctuationtable(nullptr),
      nextpunctuation(nullptr), loaded(false), hadError(false),
      hadWarning(false) {
    CreatePunctuationTable(GetDefaultPunctuations());
}

idLexerUTF8::~idLexerUTF8() {
    if (punctuationtable != nullptr) mem.Free(punctuationtable, ALIGN_16);
    if (nextpunctuation != nullptr) mem.Free(nextpunctuation, ALIGN_16);
}

void idLexerUTF8::LoadMemory(const unsigned char* const pointer,
        const unsigned int length, const char* const name) {
    buffer = pointer;
    cur = pointer;
    end = pointer != nullptr ? pointer + length : nullptr;
    prev = nullptr;
    len = length;
    filename = name;
    line = lastline = 0;
    loaded = true;
    hadError = hadWarning = false;
}

void idLexerUTF8::UnreadToken() {
    if (prev != nullptr) {
        cur = prev;
        line = lastline;
    }
}

const char* idLexerUTF8::GetPunctuationFromId(const int id) const {
    for (int index = 0; punctuations[index].p != nullptr; ++index)
        if (punctuations[index].n == id) return punctuations[index].p;
    return "unknown punctuation";
}

bool idLexerUTF8::SkipWhitespace() {
    while (cur != nullptr && cur < end) {
        int bytes = 0;
        const unsigned int character = DecodeUTF8(cur, end, bytes);
        if (character > 0x20) break;
        if (character == '\n') ++line;
        cur += bytes;
    }
    return cur != nullptr && cur < end;
}

bool idLexerUTF8::ReadName(idToken& token) {
    token.type = TT_NAME;
    while (cur < end) {
        int bytes = 0;
        const unsigned int character = DecodeUTF8(cur, end, bytes);
        bool accepted = std::isalnum(static_cast<unsigned char>(character)) != 0
            || character == '_' || character > 0x7F;
        if ((flags & LEXFL_ONLYSTRINGS) != 0 && character == '-') accepted = true;
        if ((flags & LEXFL_ALLOWPATHNAMES) != 0
            && (character == '/' || character == '\\' || character == ':'
                || character == '.' || character == '@')) accepted = true;
        if ((flags & LEXFL_ALLOWWILDCARD) != 0 && character == '*')
            accepted = true;
        if (!accepted) break;
        AppendBytes(token, cur, bytes);
        cur += bytes;
    }
    token.subtype = token.Length();
    return true;
}

bool idLexerUTF8::ReadPunctuation(idToken& token) {
    int bestIndex = -1;
    int bestLength = 0;
    for (int index = 0; punctuations[index].p != nullptr; ++index) {
        const int length = static_cast<int>(std::strlen(punctuations[index].p));
        if (length > bestLength && cur + length <= end
            && std::memcmp(cur, punctuations[index].p, length) == 0) {
            bestIndex = index;
            bestLength = length;
        }
    }
    if (bestIndex < 0) return false;
    static_cast<idStr&>(token) = punctuations[bestIndex].p;
    token.type = TT_PUNCTUATION;
    token.subtype = punctuations[bestIndex].n;
    cur += bestLength;
    return true;
}

void idLexerUTF8::CreatePunctuationTable(
        const punctuation_t* const punctuationList) {
    if (punctuationtable != nullptr) mem.Free(punctuationtable, ALIGN_16);
    if (nextpunctuation != nullptr) mem.Free(nextpunctuation, ALIGN_16);
    int count = 0;
    while (punctuationList[count].p != nullptr) ++count;
    punctuationtable = static_cast<int*>(mem.AllocWithLocation(
        "engine/decls/voiceovers/lexerutf8.cpp: TAG_LEXER", 256 * sizeof(int),
        TAG_LEXER, false, ALIGN_16, HEAP_DEFAULTHEAP));
    nextpunctuation = static_cast<int*>(mem.AllocWithLocation(
        "engine/decls/voiceovers/lexerutf8.cpp: TAG_LEXER",
        static_cast<unsigned int>(count * sizeof(int)), TAG_LEXER, false,
        ALIGN_16, HEAP_DEFAULTHEAP));
    if (punctuationtable != nullptr)
        for (int index = 0; index < 256; ++index) punctuationtable[index] = -1;
    if (nextpunctuation != nullptr)
        for (int index = 0; index < count; ++index) nextpunctuation[index] = -1;
}

void idLexerUTF8::Error(const char* const format, ...) {
    hadError = true;
    if ((flags & LEXFL_NOERRORS) != 0) return;
    char message[1024];
    va_list arguments;
    va_start(arguments, format);
    _vsnprintf_s(message, sizeof(message), _TRUNCATE, format, arguments);
    va_end(arguments);
    if ((flags & LEXFL_NOFATALERRORS) != 0) {
        idLibPrint::Warning("file %s, line %d: %s", filename.c_str(), line,
            message);
        return;
    }
    idLibPrint::Error("file %s, line %d: %s", filename.c_str(), line,
        message);
}

bool idLexerUTF8::ReadNumber(idToken& token) {
    const unsigned char* const start = cur;
    bool seenDot = false;
    bool seenExponent = false;
    while (cur < end) {
        const unsigned char character = *cur;
        if (std::isdigit(character) != 0) { ++cur; continue; }
        if (character == '.' && !seenDot && !seenExponent) {
            seenDot = true; ++cur; continue;
        }
        if ((character == 'e' || character == 'E') && !seenExponent) {
            seenExponent = true; ++cur;
            if (cur < end && (*cur == '+' || *cur == '-')) ++cur;
            continue;
        }
        break;
    }
    AppendBytes(token, start, static_cast<int>(cur - start));
    token.type = TT_NUMBER;
    token.subtype = seenDot || seenExponent
        ? TT_DECIMAL | TT_FLOAT : TT_DECIMAL | TT_INTEGER;
    token.floatvalue = static_cast<float>(std::strtod(token.c_str(), nullptr));
    token.intvalue = static_cast<unsigned int>(std::strtoul(
        token.c_str(), nullptr, 0));
    return true;
}

bool idLexerUTF8::ReadEscapeCharacter(unsigned int& character) {
    if (cur >= end) return false;
    const unsigned char escaped = *cur++;
    switch (escaped) {
    case 'n': character = '\n'; break;
    case 'r': character = '\r'; break;
    case 't': character = '\t'; break;
    case 'v': character = '\v'; break;
    case 'b': character = '\b'; break;
    case 'f': character = '\f'; break;
    case 'a': character = '\a'; break;
    case '\\': character = '\\'; break;
    case '\'': character = '\''; break;
    case '"': character = '"'; break;
    default: character = escaped; break;
    }
    return true;
}

bool idLexerUTF8::ReadString(idToken& token, const unsigned int quote) {
    ++cur;
    token.type = quote == '"' ? TT_STRING : TT_LITERAL;
    while (cur < end) {
        if (*cur == quote) { ++cur; token.subtype = token.Length(); return true; }
        if (*cur == '\n') {
            Error("newline inside string");
            return false;
        }
        if (*cur == '\\' && (flags & LEXFL_NOSTRINGESCAPECHARS) == 0) {
            ++cur;
            unsigned int character = 0;
            if (!ReadEscapeCharacter(character)) return false;
            token.Append(static_cast<char>(character));
        } else {
            int bytes = 0;
            DecodeUTF8(cur, end, bytes);
            AppendBytes(token, cur, bytes);
            cur += bytes;
        }
    }
    Error("missing trailing quote");
    return false;
}

bool idLexerUTF8::ReadToken(idToken& token) {
    token.Clear();
    token.type = token.subtype = token.flags = 0;
    prev = cur;
    lastline = line;
    if (!SkipWhitespace()) return false;
    token.line = line;
    token.linesCrossed = line - lastline;
    int bytes = 0;
    const unsigned int first = DecodeUTF8(cur, end, bytes);
    int nextBytes = 0;
    const unsigned int next = DecodeUTF8(cur + bytes, end, nextBytes);
    if ((flags & LEXFL_ONLYSTRINGS) != 0 && first != '"' && first != '\'')
        return ReadName(token);
    if (std::isdigit(static_cast<unsigned char>(first)) != 0
        || (first == '.' && std::isdigit(static_cast<unsigned char>(next)) != 0))
        return ReadNumber(token);
    if ((flags & LEXFL_NOSTRINGS) == 0 && (first == '"' || first == '\''))
        return ReadString(token, first);
    if (std::isalpha(static_cast<unsigned char>(first)) != 0 || first == '_'
        || first > 0x7F || ((flags & LEXFL_ALLOWPATHNAMES) != 0 && first == '.'))
        return ReadName(token);
    if (!ReadPunctuation(token)) {
        Error("unknown punctuation %c", static_cast<char>(first));
        cur += bytes;
    }
    return true;
}

bool idLexerUTF8::CheckTokenType(const int type, const int subtype,
        idToken& token) {
    idToken read;
    if (!ReadToken(read)) return false;
    const bool matches = read.type == type
        && (type == TT_NUMBER ? (read.subtype & subtype) == subtype
            : type != TT_PUNCTUATION || read.subtype == subtype);
    if (!matches) { UnreadToken(); return false; }
    token = read;
    return true;
}

bool idLexerUTF8::ExpectTokenType(const int type, const int subtype,
        idToken& token) {
    if (!ReadToken(token)) {
        Error("couldn't read expected token");
        return false;
    }
    if (token.type != type
        || (type == TT_NUMBER && (token.subtype & subtype) != subtype)
        || (type == TT_PUNCTUATION && token.subtype != subtype)) {
        Error("unexpected token '%s'", token.c_str());
        return false;
    }
    return true;
}

bool idLexerUTF8::ExpectTokenString(const char* const string) {
    idToken token;
    if (!ReadToken(token)) {
        Error("couldn't find expected '%s'", string);
        return false;
    }
    if (std::strcmp(token.c_str(), string) != 0) {
        Error("expected '%s' but found '%s'", string, token.c_str());
        return false;
    }
    return true;
}

bool idLexerUTF8::CheckTokenString(const char* const string) {
    idToken token;
    if (!ReadToken(token)) return false;
    if (std::strcmp(token.c_str(), string) == 0) return true;
    UnreadToken();
    return false;
}

bool idLexerUTF8::SkipBracedSection(const bool parseFirstBrace) {
    int depth = parseFirstBrace ? 0 : 1;
    idToken token;
    while (ReadToken(token)) {
        if (token.type == TT_PUNCTUATION) {
            if (std::strcmp(token.c_str(), "{") == 0) ++depth;
            else if (std::strcmp(token.c_str(), "}") == 0) --depth;
        }
        if (depth == 0) return true;
    }
    return false;
}

float idLexerUTF8::ParseFloat() {
    idToken token;
    bool negative = CheckTokenString("-");
    if (!ExpectTokenType(TT_NUMBER, 0, token)) return 0.0f;
    const float value = static_cast<float>(std::strtod(token.c_str(), nullptr));
    return negative ? -value : value;
}

int idLexerUTF8::ParseInt() {
    idToken token;
    const bool negative = CheckTokenString("-");
    if (!ExpectTokenType(TT_NUMBER, TT_INTEGER, token)) return 0;
    const int value = static_cast<int>(std::strtol(token.c_str(), nullptr, 0));
    return negative ? -value : value;
}
