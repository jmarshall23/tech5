#pragma once

#include <cctype>
#include <cstring>

class idCmdArgs {
public:
    idCmdArgs()
        : argc(0) {
        tokenized[0] = '\0';
    }

    idCmdArgs(const char* text, const bool keepAsStrings)
        : idCmdArgs() {
        TokenizeString(text, keepAsStrings);
    }

    idCmdArgs& operator=(const idCmdArgs& other) {
        if (this == &other) {
            return *this;
        }
        Clear();
        for (int index = 0; index < other.argc; ++index) {
            AppendArg(other.argv[index]);
        }
        return *this;
    }

    int Argc() const {
        return argc;
    }

    const char* Argv(const int arg) const {
        return arg >= 0 && arg < argc ? argv[arg] : "";
    }

    void Clear() {
        argc = 0;
        tokenized[0] = '\0';
    }

    void AppendArg(const char* text) {
        if (argc >= 64) {
            return;
        }
        const char* const source = text == nullptr ? "" : text;
        int used = 0;
        for (int index = 0; index < argc; ++index) {
            used += static_cast<int>(std::strlen(argv[index])) + 1;
        }
        const int length = static_cast<int>(std::strlen(source));
        if (used + length + 1 > 2048) {
            return;
        }
        argv[argc] = tokenized + used;
        std::memcpy(argv[argc], source, static_cast<std::size_t>(length + 1));
        ++argc;
    }

    void TokenizeString(const char* text, const bool keepAsStrings) {
        Clear();
        const char* cursor = text == nullptr ? "" : text;
        while (*cursor != '\0' && argc < 64) {
            while (std::isspace(static_cast<unsigned char>(*cursor)) != 0) {
                ++cursor;
            }
            if (*cursor == '\0') {
                break;
            }

            char token[2048];
            int tokenLength = 0;
            if (*cursor == '"') {
                ++cursor;
                while (*cursor != '\0' && *cursor != '"'
                    && tokenLength < 2047) {
                    token[tokenLength++] = *cursor++;
                }
                if (*cursor == '"') {
                    ++cursor;
                }
            } else {
                while (*cursor != '\0'
                    && std::isspace(static_cast<unsigned char>(*cursor)) == 0
                    && tokenLength < 2047) {
                    if (!keepAsStrings && IsPunctuation(*cursor)
                        && tokenLength == 0) {
                        token[tokenLength++] = *cursor++;
                        break;
                    }
                    if (!keepAsStrings && IsPunctuation(*cursor)) {
                        break;
                    }
                    token[tokenLength++] = *cursor++;
                }
            }
            token[tokenLength] = '\0';
            AppendArg(token);
        }
    }

private:
    int argc;
    char* argv[64];
    char tokenized[2048];

    static bool IsPunctuation(const char value) {
        switch (value) {
            case '{': case '}': case '(': case ')':
            case '[': case ']': case ',': case ';':
                return true;
            default:
                return false;
        }
    }
};

static_assert(sizeof(idCmdArgs) == 2308, "Recovered idCmdArgs ABI changed");
