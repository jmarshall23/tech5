#include "../math/vector.h"
#include "../text/str.h"

#include "typeinfofile.h"

#include <algorithm>
#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <locale>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

struct Token {
    std::string text;
    bool quoted = false;
    bool whitespace = false;
};

struct TypeInfoState {
    std::string output;
    std::string input;
    std::string name;
    std::string lastWhitespace;
    std::string lastComment;
    std::size_t cursor = 0;
    int line = 1;
    bool hadError = false;
    bool hadWarning = false;
};

TypeInfoState* State(idTypeInfoFile* file, const bool create = true) {
    if (file->fp == nullptr && create) file->fp = new TypeInfoState;
    return static_cast<TypeInfoState*>(file->fp);
}

const TypeInfoState* State(const idTypeInfoFile* file) {
    return static_cast<const TypeInfoState*>(file->fp);
}

bool IsPunctuation(const char value) {
    switch (value) {
        case '{': case '}': case '[': case ']': case '=': case ';':
        case '!': case '<': case '>':
            return true;
        default:
            return false;
    }
}

void AppendEscape(std::string& result, const char value) {
    switch (value) {
        case 'n': result.push_back('\n'); break;
        case 'r': result.push_back('\r'); break;
        case 't': result.push_back('\t'); break;
        case 'v': result.push_back('\v'); break;
        case 'b': result.push_back('\b'); break;
        case 'f': result.push_back('\f'); break;
        case 'a': result.push_back('\a'); break;
        default: result.push_back(value); break;
    }
}

std::string Quote(const char* value) {
    std::string result(1, '"');
    const unsigned char* cursor = reinterpret_cast<const unsigned char*>(
        value == nullptr ? "" : value);
    for (; *cursor != 0; ++cursor) {
        switch (*cursor) {
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            case '\v': result += "\\v"; break;
            case '\b': result += "\\b"; break;
            case '\f': result += "\\f"; break;
            case '\a': result += "\\a"; break;
            case '\'': result += "\\'"; break;
            case '"': result += "\\\""; break;
            case '?': result += "\\?"; break;
            default: result.push_back(static_cast<char>(*cursor)); break;
        }
    }
    result.push_back('"');
    return result;
}

std::string Trim(std::string value) {
    while (!value.empty()
        && std::isspace(static_cast<unsigned char>(value.back())) != 0) {
        value.pop_back();
    }
    std::size_t first = 0;
    while (first < value.size()
        && std::isspace(static_cast<unsigned char>(value[first])) != 0) {
        ++first;
    }
    return value.substr(first);
}

void SkipWhitespace(TypeInfoState& state, bool& skipped) {
    const std::size_t begin = state.cursor;
    state.lastComment.clear();
    while (state.cursor < state.input.size()) {
        const char current = state.input[state.cursor];
        if (std::isspace(static_cast<unsigned char>(current)) != 0) {
            if (current == '\n') ++state.line;
            ++state.cursor;
            continue;
        }
        if (current == '/' && state.cursor + 1 < state.input.size()
            && state.input[state.cursor + 1] == '/') {
            state.cursor += 2;
            const std::size_t commentStart = state.cursor;
            while (state.cursor < state.input.size()
                && state.input[state.cursor] != '\n') {
                ++state.cursor;
            }
            state.lastComment = Trim(state.input.substr(
                commentStart, state.cursor - commentStart));
            continue;
        }
        if (current == '/' && state.cursor + 1 < state.input.size()
            && state.input[state.cursor + 1] == '*') {
            state.cursor += 2;
            const std::size_t commentStart = state.cursor;
            while (state.cursor + 1 < state.input.size()
                && !(state.input[state.cursor] == '*'
                    && state.input[state.cursor + 1] == '/')) {
                if (state.input[state.cursor] == '\n') ++state.line;
                ++state.cursor;
            }
            state.lastComment = Trim(state.input.substr(
                commentStart, state.cursor - commentStart));
            if (state.cursor + 1 < state.input.size()) state.cursor += 2;
            continue;
        }
        break;
    }
    state.lastWhitespace = state.input.substr(begin, state.cursor - begin);
    skipped = state.cursor != begin;
}

bool NextToken(TypeInfoState& state, Token& token) {
    token = Token{};
    SkipWhitespace(state, token.whitespace);
    if (state.cursor >= state.input.size()) return false;

    const char first = state.input[state.cursor];
    if (first == '"') {
        token.quoted = true;
        ++state.cursor;
        while (state.cursor < state.input.size()) {
            const char current = state.input[state.cursor++];
            if (current == '"') return true;
            if (current == '\\' && state.cursor < state.input.size()) {
                AppendEscape(token.text, state.input[state.cursor++]);
            } else {
                if (current == '\n') ++state.line;
                token.text.push_back(current);
            }
        }
        state.hadError = true;
        return true;
    }
    if (IsPunctuation(first)) {
        token.text.assign(1, first);
        ++state.cursor;
        return true;
    }

    const std::size_t begin = state.cursor;
    while (state.cursor < state.input.size()) {
        const char current = state.input[state.cursor];
        if (std::isspace(static_cast<unsigned char>(current)) != 0
            || IsPunctuation(current)
            || (current == '/' && state.cursor + 1 < state.input.size()
                && (state.input[state.cursor + 1] == '/'
                    || state.input[state.cursor + 1] == '*'))) {
            break;
        }
        ++state.cursor;
    }
    if (state.cursor == begin) ++state.cursor;
    token.text = state.input.substr(begin, state.cursor - begin);
    return true;
}

struct ParserMark {
    std::size_t cursor;
    int line;
    std::string whitespace;
    std::string comment;
};

ParserMark Mark(const TypeInfoState& state) {
    return {state.cursor, state.line, state.lastWhitespace, state.lastComment};
}

void Restore(TypeInfoState& state, const ParserMark& mark) {
    state.cursor = mark.cursor;
    state.line = mark.line;
    state.lastWhitespace = mark.whitespace;
    state.lastComment = mark.comment;
}

bool CheckToken(TypeInfoState& state, const char* expected) {
    const ParserMark mark = Mark(state);
    Token token;
    if (NextToken(state, token) && token.text == expected) return true;
    Restore(state, mark);
    return false;
}

bool PeekToken(TypeInfoState& state, const char* expected) {
    const ParserMark mark = Mark(state);
    const bool result = CheckToken(state, expected);
    Restore(state, mark);
    return result;
}

bool ExpectToken(TypeInfoState& state, const char* expected) {
    if (CheckToken(state, expected)) return true;
    state.hadError = true;
    return false;
}

void Write(idTypeInfoFile* file, const std::string& text) {
    TypeInfoState* const state = State(file, false);
    if (state != nullptr) state->output += text;
}

std::string Indentation(bool& newline, const int indent) {
    std::string result;
    if (newline) result.push_back('\n');
    else newline = true;
    result.append(static_cast<std::size_t>(std::max(indent, 0)), '\t');
    return result;
}

std::string FormatFixed(const double value, const int precision) {
    std::ostringstream stream;
    stream.imbue(std::locale::classic());
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}

std::string FormatCompact(const float value, const int precision = 8) {
    std::string text = FormatFixed(value, precision);
    while (!text.empty() && text.back() == '0') text.pop_back();
    if (!text.empty() && text.back() == '.') text.pop_back();
    if (text == "-0") text = "0";
    return text;
}

bool ReadLong(TypeInfoState& state, long& value) {
    Token token;
    if (!NextToken(state, token)) {
        state.hadError = true;
        return false;
    }
    char* end = nullptr;
    value = std::strtol(token.text.c_str(), &end, 0);
    if (end == token.text.c_str() || *end != '\0') {
        state.hadError = true;
        return false;
    }
    return true;
}

bool ReadUnsignedLongValue(TypeInfoState& state, unsigned long& value) {
    Token token;
    if (!NextToken(state, token)) {
        state.hadError = true;
        return false;
    }
    char* end = nullptr;
    value = std::strtoul(token.text.c_str(), &end, 0);
    if (end == token.text.c_str() || *end != '\0') {
        state.hadError = true;
        return false;
    }
    return true;
}

bool ReadReal(TypeInfoState& state, double& value) {
    Token token;
    if (!NextToken(state, token)) {
        state.hadError = true;
        return false;
    }
    char* end = nullptr;
    value = std::strtod(token.text.c_str(), &end);
    if (end == token.text.c_str() || *end != '\0') {
        state.hadError = true;
        return false;
    }
    return true;
}

void Assign(idStr& target, const std::string& value) {
    target = value.c_str();
}

bool ParseAssignment(TypeInfoState& state, std::vector<Token>& parts) {
    parts.clear();
    for (int count = 0; count < 3; ++count) {
        Token token;
        if (!NextToken(state, token)) return false;
        if (token.text == "=" || token.text == "[") return false;
        parts.push_back(token);
        if (CheckToken(state, "=")) return true;
    }
    return false;
}

void SetTypeParts(const std::vector<Token>& parts, idStr& type, idStr& ops,
        idStr& name) {
    type.Clear();
    ops.Clear();
    name.Clear();
    if (parts.size() == 1) {
        Assign(name, parts[0].text);
    } else if (parts.size() == 2) {
        Assign(type, parts[0].text);
        Assign(name, parts[1].text);
    } else if (parts.size() == 3) {
        Assign(type, parts[0].text);
        Assign(ops, parts[1].text);
        Assign(name, parts[2].text);
    }
}

bool StringsEqual(const char* left, const char* right) {
    return std::strcmp(left == nullptr ? "" : left,
        right == nullptr ? "" : right) == 0;
}

bool TypeMatches(const std::vector<Token>& parts, const char* type,
        const char* ops, const char* name) {
    if (parts.size() == 1) return StringsEqual(parts[0].text.c_str(), name);
    if (parts.size() == 2) {
        return (type == nullptr || *type == 0
                || StringsEqual(parts[0].text.c_str(), type))
            && (ops == nullptr || *ops == 0)
            && StringsEqual(parts[1].text.c_str(), name);
    }
    return parts.size() == 3
        && (type == nullptr || *type == 0
            || StringsEqual(parts[0].text.c_str(), type))
        && (ops == nullptr || *ops == 0
            || StringsEqual(parts[1].text.c_str(), ops))
        && StringsEqual(parts[2].text.c_str(), name);
}

bool ParseArrayAssignment(TypeInfoState& state, std::vector<Token>& parts,
        int& index, const bool allowPlain) {
    parts.clear();
    index = -1;
    for (int count = 0; count < 3; ++count) {
        Token token;
        if (!NextToken(state, token)) return false;
        if (token.text == "=" || token.text == "[") return false;
        parts.push_back(token);
        if (CheckToken(state, "=")) return allowPlain;
        if (CheckToken(state, "[")) {
            unsigned long parsed = 0;
            if (!ReadUnsignedLongValue(state, parsed)) return false;
            index = static_cast<int>(parsed);
            return ExpectToken(state, "]") && ExpectToken(state, "=");
        }
    }
    return false;
}

void NormalizeExpected(idStr& actualType, idStr& actualOps,
        const char* expectedType, const char* expectedOps) {
    if (expectedType != nullptr && *expectedType != 0) {
        if (actualType.Length() == 0) {
            actualType = expectedType;
            actualOps = expectedOps == nullptr ? "" : expectedOps;
        }
    } else {
        actualType.Clear();
        actualOps.Clear();
    }
    if (expectedOps != nullptr && *expectedOps != 0) {
        if (actualOps.Length() == 0) actualOps = expectedOps;
    } else {
        actualOps.Clear();
    }
}

std::string FormatMessage(const char* format, va_list args) {
    char buffer[4096];
    const int amount = std::vsnprintf(buffer, sizeof(buffer),
        format == nullptr ? "" : format, args);
    if (amount < 0) return format == nullptr ? "" : format;
    return std::string(buffer,
        static_cast<std::size_t>(std::min(amount,
            static_cast<int>(sizeof(buffer) - 1))));
}

struct StringTableState { std::deque<std::string> values; };
std::mutex stringTablesMutex;
std::unordered_map<const idTypeInfoStrings*, StringTableState> stringTables;

} // namespace

idTypeInfoSettings::idTypeInfoSettings()
    : writeModifier(WRITE_ALL_PROPERTIES), resolveEntityPointers(true),
      resolveModelPointers(true), skipMarkedObjects(false),
      skipScriptObjects(false), writeComments(true), writeType(true) {}

idTypeInfoSettings::idTypeInfoSettings(const bool entities, const bool models)
    : idTypeInfoSettings() {
    resolveEntityPointers = entities;
    resolveModelPointers = models;
}

idTypeInfoSettings::idTypeInfoSettings(const bool entities, const bool models,
        const bool skipMarked)
    : idTypeInfoSettings(entities, models) {
    skipMarkedObjects = skipMarked;
}

idTypeInfoFile::idTypeInfoFile(const int initialIndent)
    : settings(), fp(nullptr), src{}, indent(initialIndent), newline(false) {
    settings.writeComments = false;
}

idTypeInfoFile::~idTypeInfoFile() {
    delete State(this, false);
    fp = nullptr;
}

bool idTypeInfoFile::WriteMemoryFile() {
    delete State(this, false);
    fp = new TypeInfoState;
    return fp != nullptr;
}

const char* idTypeInfoFile::GetTypeInfoString() const {
    const TypeInfoState* const state = State(this);
    return state == nullptr ? "" : state->output.c_str();
}

bool idTypeInfoFile::ReadMemory(const char* data, const int length,
        const char* sourceName, const int startLine) {
    TypeInfoState* const state = State(this);
    state->input.assign(data == nullptr ? "" : data,
        data == nullptr || length <= 0 ? 0 : static_cast<std::size_t>(length));
    state->name = sourceName == nullptr ? "" : sourceName;
    state->cursor = 0;
    state->line = std::max(startLine, 1);
    state->hadError = false;
    state->hadWarning = false;
    state->lastWhitespace.clear();
    state->lastComment.clear();
    return data != nullptr || length == 0;
}

bool idTypeInfoFile::ReadMemoryFile() {
    TypeInfoState* const state = State(this, false);
    if (state == nullptr) return false;
    state->input = state->output;
    state->cursor = 0;
    state->line = 1;
    state->hadError = false;
    state->hadWarning = false;
    return true;
}

void idTypeInfoFile::WriteOpeningBrace() {
    if (State(this, false) != nullptr) {
        Write(this, "{");
        ++indent;
    }
}

void idTypeInfoFile::ReadOpeningBrace() {
    TypeInfoState* const state = State(this);
    ExpectToken(*state, "{");
    ++indent;
}

bool idTypeInfoFile::CheckOpeningBrace() {
    TypeInfoState* const state = State(this);
    if (!CheckToken(*state, "{")) return false;
    ++indent;
    return true;
}

void idTypeInfoFile::WriteClosingBrace() {
    if (State(this, false) == nullptr) return;
    --indent;
    Write(this, Indentation(newline, indent) + "}");
}

void idTypeInfoFile::ReadClosingBrace() {
    --indent;
    ExpectToken(*State(this), "}");
}

bool idTypeInfoFile::CheckClosingBrace() {
    TypeInfoState* const state = State(this);
    if (!CheckToken(*state, "}")) return false;
    --indent;
    return true;
}

bool idTypeInfoFile::PeekClosingBrace() {
    return PeekToken(*State(this), "}");
}

void idTypeInfoFile::WriteSkipObject(const bool skip) {
    if (skip) Write(this, "! ");
}

bool idTypeInfoFile::CheckSkipObject() {
    return CheckToken(*State(this), "!");
}

bool idTypeInfoFile::CheckType(const char* type, const char* ops,
        const char* name) {
    TypeInfoState* const state = State(this);
    const ParserMark mark = Mark(*state);
    std::vector<Token> parts;
    if (ParseAssignment(*state, parts) && TypeMatches(parts, type, ops, name)) {
        return true;
    }
    Restore(*state, mark);
    return false;
}

void idTypeInfoFile::WriteType(const char* type, const char* ops,
        const char* name) {
    if (State(this, false) == nullptr) return;
    const char* const safeName = name == nullptr ? "" : name;
    const unsigned char first = static_cast<unsigned char>(*safeName);
    const bool plainName = std::isalpha(first) != 0 || first == '_';
    const std::string outputName = plainName ? safeName : Quote(safeName);
    std::string output = Indentation(newline, indent);
    if (settings.writeType && type != nullptr && *type != 0) {
        output += Quote(type);
        output.push_back(' ');
        if (ops != nullptr && *ops != 0) {
            output += Quote(ops);
            output.push_back(' ');
        }
    }
    output += outputName;
    output += " = ";
    Write(this, output);
}

bool idTypeInfoFile::ReadType(idStr& type, idStr& ops, idStr& name) {
    TypeInfoState* const state = State(this);
    std::vector<Token> parts;
    if (!ParseAssignment(*state, parts) || parts.empty()) {
        state->hadError = true;
        return false;
    }
    SetTypeParts(parts, type, ops, name);
    return true;
}

bool idTypeInfoFile::ExpectType(const char* type, const char* ops,
        const char* name) {
    idStr actualType, actualOps, actualName;
    if (!ReadType(actualType, actualOps, actualName)) return false;
    NormalizeExpected(actualType, actualOps, type, ops);
    const bool result = StringsEqual(actualType.c_str(), type)
        && StringsEqual(actualOps.c_str(), ops)
        && StringsEqual(actualName.c_str(), name);
    if (!result) State(this)->hadWarning = true;
    return result;
}

void idTypeInfoFile::WriteArrayElementType(const char* type, const char* ops,
        const char* name, const int index) {
    std::ostringstream stream;
    stream.imbue(std::locale::classic());
    stream << (name == nullptr ? "" : name) << '[' << index << ']';
    WriteType(type, ops, stream.str().c_str());
}

bool idTypeInfoFile::ReadArrayElementType(idStr& type, idStr& ops,
        idStr& name, int& index) {
    TypeInfoState* const state = State(this);
    std::vector<Token> parts;
    if (!ParseArrayAssignment(*state, parts, index, false) || parts.empty()) {
        state->hadError = true;
        index = -1;
        return false;
    }
    SetTypeParts(parts, type, ops, name);
    return true;
}

bool idTypeInfoFile::CheckArrayElementType(idStr& type, idStr& ops,
        idStr& name, int& index) {
    TypeInfoState* const state = State(this);
    const ParserMark mark = Mark(*state);
    std::vector<Token> parts;
    if (ParseArrayAssignment(*state, parts, index, true) && !parts.empty()) {
        SetTypeParts(parts, type, ops, name);
        return true;
    }
    Restore(*state, mark);
    type.Clear();
    ops.Clear();
    name.Clear();
    index = -1;
    return false;
}

bool idTypeInfoFile::ExpectArrayElementType(const char* type, const char* ops,
        const char* name, int& index) {
    idStr actualType, actualOps, actualName;
    if (!ReadArrayElementType(actualType, actualOps, actualName, index)) {
        return false;
    }
    NormalizeExpected(actualType, actualOps, type, ops);
    const bool result = StringsEqual(actualType.c_str(), type)
        && StringsEqual(actualOps.c_str(), ops)
        && StringsEqual(actualName.c_str(), name);
    if (!result) State(this)->hadWarning = true;
    return result;
}

void idTypeInfoFile::WriteBool(const bool value) {
    Write(this, value ? "true;" : "false;");
}

void idTypeInfoFile::ReadBool(bool& value) {
    TypeInfoState* const state = State(this);
    Token token;
    if (NextToken(*state, token) && token.text == "true") value = true;
    else if (token.text == "false") value = false;
    else state->hadWarning = true;
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteChar(const char value) {
    Write(this, std::to_string(static_cast<int>(value)) + ";");
}

void idTypeInfoFile::ReadChar(char& value) {
    long parsed = 0; TypeInfoState* state = State(this);
    if (ReadLong(*state, parsed)) value = static_cast<char>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteUnsignedChar(const unsigned char value) {
    Write(this, std::to_string(static_cast<unsigned int>(value)) + ";");
}

void idTypeInfoFile::ReadUnsignedChar(unsigned char& value) {
    unsigned long parsed = 0; TypeInfoState* state = State(this);
    if (ReadUnsignedLongValue(*state, parsed)) value = static_cast<unsigned char>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteWChar(const wchar_t value) {
    Write(this, std::to_string(static_cast<int>(value)) + ";");
}

void idTypeInfoFile::ReadWChar(wchar_t& value) {
    long parsed = 0; TypeInfoState* state = State(this);
    if (ReadLong(*state, parsed)) value = static_cast<wchar_t>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteShort(const short value) {
    Write(this, std::to_string(static_cast<int>(value)) + ";");
}

void idTypeInfoFile::ReadShort(short& value) {
    long parsed = 0; TypeInfoState* state = State(this);
    if (ReadLong(*state, parsed)) value = static_cast<short>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteUnsignedShort(const unsigned short value) {
    Write(this, std::to_string(static_cast<unsigned int>(value)) + ";");
}

void idTypeInfoFile::ReadUnsignedShort(unsigned short& value) {
    unsigned long parsed = 0; TypeInfoState* state = State(this);
    if (ReadUnsignedLongValue(*state, parsed)) value = static_cast<unsigned short>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteUnsignedLong(const unsigned long value) {
    Write(this, std::to_string(value) + ";");
}

void idTypeInfoFile::ReadUnsignedLong(unsigned long& value) {
    TypeInfoState* state = State(this);
    ReadUnsignedLongValue(*state, value);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteInt(const int value) {
    Write(this, std::to_string(value) + ";");
}

void idTypeInfoFile::ReadInt(int& value) {
    long parsed = 0; TypeInfoState* state = State(this);
    if (ReadLong(*state, parsed)) value = static_cast<int>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteFloat(const float value) {
    Write(this, FormatFixed(value, 6) + ";");
}

void idTypeInfoFile::ReadFloat(float& value) {
    double parsed = 0.0; TypeInfoState* state = State(this);
    if (ReadReal(*state, parsed)) value = static_cast<float>(parsed);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteDouble(const double value) {
    Write(this, FormatFixed(value, 6) + ";");
}

void idTypeInfoFile::ReadDouble(double& value) {
    TypeInfoState* state = State(this);
    ReadReal(*state, value);
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteStr(const char* value) {
    Write(this, Quote(value) + ";");
}

void idTypeInfoFile::ReadStr(idStr& value) {
    TypeInfoState* const state = State(this);
    Token token;
    if (NextToken(*state, token) && token.quoted) Assign(value, token.text);
    else value.Clear();
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteValueString(const idStr& value) {
    Write(this, std::string(value.c_str()) + ";");
}

void idTypeInfoFile::ReadValueString(idStr& value) {
    TypeInfoState* const state = State(this);
    value.Clear();
    bool first = true;
    Token token;
    while (NextToken(*state, token)) {
        if (token.text == ";") return;
        if (!first && token.whitespace) value.Append(' ');
        const std::string text = token.quoted ? Quote(token.text.c_str()) : token.text;
        value.Append(text.c_str());
        first = false;
    }
    state->hadError = true;
}

void idTypeInfoFile::WriteNullPointer() { Write(this, "NULL;"); }

void idTypeInfoFile::ReadNullPointer() {
    TypeInfoState* state = State(this);
    ExpectToken(*state, "NULL");
    ExpectToken(*state, ";");
}

bool idTypeInfoFile::CheckNullPointer() {
    TypeInfoState* state = State(this);
    const ParserMark mark = Mark(*state);
    if (CheckToken(*state, "NULL") && ExpectToken(*state, ";")) return true;
    Restore(*state, mark);
    return false;
}

void idTypeInfoFile::WriteUnknown() { Write(this, "<unknown>;"); }

void idTypeInfoFile::ReadUnknown() {
    TypeInfoState* const state = State(this);
    int depth = 0;
    Token token;
    while (NextToken(*state, token)) {
        if (token.text == "{") ++depth;
        else if (token.text == "}") {
            --depth;
            if (depth <= 0) return;
        } else if (token.text == ";" && depth <= 0) return;
    }
}

bool idTypeInfoFile::CheckUnknown() {
    TypeInfoState* state = State(this);
    if (!CheckToken(*state, "<")) return false;
    ReadUnknown();
    return true;
}

void idTypeInfoFile::WriteVec3(const idVec3& value) {
    WriteOpeningBrace();
    WriteType("float", "", "x"); WriteFloat(value.x);
    WriteType("float", "", "y"); WriteFloat(value.y);
    WriteType("float", "", "z"); WriteFloat(value.z);
    WriteClosingBrace();
}

void idTypeInfoFile::ReadVec3(idVec3& value) {
    ReadOpeningBrace();
    if (CheckType("float", "", "x")) ReadFloat(value.x);
    if (CheckType("float", "", "y")) ReadFloat(value.y);
    if (CheckType("float", "", "z")) ReadFloat(value.z);
    ReadClosingBrace();
}

void idTypeInfoFile::WriteVecX(const idVecX& value) {
    std::ostringstream stream;
    stream.imbue(std::locale::classic());
    stream << value.GetSize();
    for (int index = 0; index < value.GetSize(); ++index) {
        stream << ' ' << FormatCompact(value[index]);
    }
    stream << ';';
    Write(this, stream.str());
}

void idTypeInfoFile::ReadVecX(idVecX& value) {
    long count = 0; TypeInfoState* state = State(this);
    if (!ReadLong(*state, count)) return;
    value.SetSize(static_cast<int>(count));
    for (int index = 0; index < value.GetSize(); ++index) {
        double parsed = 0.0;
        if (ReadReal(*state, parsed)) value[index] = static_cast<float>(parsed);
    }
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteMatX(const idMatX& value) {
    std::ostringstream stream;
    stream.imbue(std::locale::classic());
    stream << value.GetNumRows() << ' ' << value.GetNumColumns();
    for (int row = 0; row < value.GetNumRows(); ++row) {
        for (int column = 0; column < value.GetNumColumns(); ++column) {
            stream << ' ' << FormatCompact(value[row][column]);
        }
    }
    stream << ';';
    Write(this, stream.str());
}

void idTypeInfoFile::ReadMatX(idMatX& value) {
    long rows = 0, columns = 0; TypeInfoState* state = State(this);
    if (!ReadLong(*state, rows) || !ReadLong(*state, columns)) return;
    value.SetSize(static_cast<int>(rows), static_cast<int>(columns));
    for (int row = 0; row < value.GetNumRows(); ++row) {
        for (int column = 0; column < value.GetNumColumns(); ++column) {
            double parsed = 0.0;
            if (ReadReal(*state, parsed)) value[row][column] = static_cast<float>(parsed);
        }
    }
    ExpectToken(*state, ";");
}

void idTypeInfoFile::WriteAngles(const idAngles& value) {
    WriteOpeningBrace();
    WriteType("float", "", "pitch"); WriteFloat(value.pitch);
    WriteType("float", "", "yaw"); WriteFloat(value.yaw);
    WriteType("float", "", "roll"); WriteFloat(value.roll);
    WriteClosingBrace();
}

void idTypeInfoFile::ReadAngles(idAngles& value) {
    ReadOpeningBrace();
    if (ExpectType("float", "", "pitch")) ReadFloat(value.pitch);
    if (ExpectType("float", "", "yaw")) ReadFloat(value.yaw);
    if (ExpectType("float", "", "roll")) ReadFloat(value.roll);
    ReadClosingBrace();
}

void idTypeInfoFile::WriteColor(const idColor& value) {
    const float* const values = reinterpret_cast<const float*>(&value);
    WriteOpeningBrace();
    WriteType("float", "", "r"); WriteFloat(values[0]);
    WriteType("float", "", "g"); WriteFloat(values[1]);
    WriteType("float", "", "b"); WriteFloat(values[2]);
    WriteType("float", "", "a"); WriteFloat(values[3]);
    WriteClosingBrace();
}

void idTypeInfoFile::ReadColor(idColor& value) {
    float* const values = reinterpret_cast<float*>(&value);
    ReadOpeningBrace();
    if (CheckType("float", "", "r")) ReadFloat(values[0]);
    if (CheckType("float", "", "g")) ReadFloat(values[1]);
    if (CheckType("float", "", "b")) ReadFloat(values[2]);
    if (CheckType("float", "", "a")) ReadFloat(values[3]);
    ReadClosingBrace();
}

void idTypeInfoFile::WriteComment(const char* comment) {
    if (settings.writeComments && comment != nullptr && *comment != 0) {
        Write(this, std::string("\t/* ") + comment + " */");
    }
}

void idTypeInfoFile::ReadComment(idStr& comment) {
    TypeInfoState* const state = State(this);
    bool skipped = false;
    SkipWhitespace(*state, skipped);
    if (!state->lastComment.empty()) Assign(comment, state->lastComment);
    else comment.Clear();
}

void idTypeInfoFile::Error(const char* format, ...) {
    TypeInfoState* const state = State(this);
    va_list args; va_start(args, format);
    state->lastComment = FormatMessage(format, args);
    va_end(args);
    state->hadError = true;
}

void idTypeInfoFile::Warning(const char* format, ...) {
    TypeInfoState* const state = State(this);
    va_list args; va_start(args, format);
    state->lastComment = FormatMessage(format, args);
    va_end(args);
    state->hadWarning = true;
}

bool idTypeInfoFile::HadError() const {
    const TypeInfoState* const state = State(this);
    return state != nullptr && state->hadError;
}

const char* idTypeInfoFile::OutputTabs(bool& outputNewline, const int count) {
    static thread_local std::string tabs;
    tabs = Indentation(outputNewline, count);
    return tabs.c_str();
}

const char* idTypeInfoStrings::GetStringForIndex(const int index) const {
    std::lock_guard<std::mutex> lock(stringTablesMutex);
    const auto found = stringTables.find(this);
    if (found == stringTables.end() || index < 0
        || index >= static_cast<int>(found->second.values.size())) return "";
    return found->second.values[static_cast<std::size_t>(index)].c_str();
}

int idTypeInfoStrings::FindString(const char* string) {
    const std::string value = string == nullptr ? "" : string;
    std::lock_guard<std::mutex> lock(stringTablesMutex);
    std::deque<std::string>& values = stringTables[this].values;
    for (std::size_t index = 0; index < values.size(); ++index) {
        if (values[index] == value) return static_cast<int>(index);
    }
    values.push_back(value);
    return static_cast<int>(values.size() - 1);
}

void idTypeInfoStrings::Shutdown() {
    std::lock_guard<std::mutex> lock(stringTablesMutex);
    stringTables.erase(this);
    std::memset(strings, 0, sizeof(strings));
    std::memset(stringHash, 0, sizeof(stringHash));
}
