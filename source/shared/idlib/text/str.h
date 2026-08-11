#pragma once

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cstdio>

// Exact tungsten idStr storage layout (tungsten.exe.h type 12142). This is a
// deliberately small ABI facade; more authoritative text methods will be
// added as text/str.cpp is reconstructed.
class idStr {
public:
    idStr()
        : len(0)
        , data(baseBuffer)
        , allocedAndFlag(20) {
        baseBuffer[0] = '\0';
    }

    idStr(const char* text)
        : idStr() {
        Assign(text);
    }

    idStr(const idStr& other)
        : idStr() {
        Assign(other.c_str());
    }

    ~idStr() {
        if (data != baseBuffer && !IsStaticBuffer()) {
            std::free(data);
        }
    }

    idStr& operator=(const idStr& other) {
        if (this != &other) {
            Assign(other.c_str());
        }
        return *this;
    }

    idStr& operator=(const char* text) {
        Assign(text);
        return *this;
    }

    const char* c_str() const {
        return data;
    }

    operator const char*() const {
        return data;
    }

    int Length() const {
        return len;
    }

    void CapLength(const int newLength) {
        const int cappedLength = (std::max)(newLength, 0);
        if (len <= cappedLength) {
            return;
        }
        len = cappedLength;
        data[len] = '\0';
    }

    bool IsEmpty() const {
        return len == 0;
    }

    void Clear() {
        len = 0;
        if (data != nullptr) {
            data[0] = '\0';
        }
    }

    // EA 0x82776B58
    void ToUpper() {
        for (int index = 0; data[index] != '\0'; ++index) {
            if (data[index] >= 'a' && data[index] <= 'z') {
                data[index] = static_cast<char>(data[index] - ('a' - 'A'));
            }
        }
    }

    void TrimWhitespaceRecovered() {
        while (len > 0
            && std::isspace(static_cast<unsigned char>(data[len - 1])) != 0) {
            data[--len] = '\0';
        }
        int amount = 0;
        while (amount < len
            && std::isspace(static_cast<unsigned char>(data[amount])) != 0) {
            ++amount;
        }
        if (amount > 0) {
            std::memmove(data, data + amount,
                static_cast<std::size_t>(len - amount + 1));
            len -= amount;
        }
    }

    // Recovered from shared/idlib/text/str.cpp. Resource names are lowercase,
    // use forward slashes, and discard leading slashes except for UNC names.
    void MakeNameCanonical() {
        for (int index = 0; index < len; ++index) {
            if (data[index] >= 'A' && data[index] <= 'Z') {
                data[index] = static_cast<char>(data[index] + ('a' - 'A'));
            } else if (data[index] == '\\') {
                data[index] = '/';
            }
        }
        if (!(len >= 2 && data[0] == '/' && data[1] == '/')) {
            int leading = 0;
            while (leading < len && data[leading] == '/') {
                ++leading;
            }
            if (leading > 0) {
                std::memmove(data, data + leading,
                    static_cast<std::size_t>(len - leading + 1));
                len -= leading;
            }
        }
    }

    void Append(const char* text) {
        if (text == nullptr || *text == '\0') {
            return;
        }
        const int appendLength = static_cast<int>(std::strlen(text));
        if (!EnsureAlloced(len + appendLength + 1)) {
            return;
        }
        std::memcpy(data + len, text, static_cast<std::size_t>(appendLength + 1));
        len += appendLength;
    }

    void Append(const char value) {
        if (!EnsureAlloced(len + 2)) {
            return;
        }
        data[len++] = value;
        data[len] = '\0';
    }

    void Append(const idStr& text) {
        Append(text.c_str());
    }

    idStr& StripFileExtension() {
        for (int index = len - 1; index >= 0; --index) {
            const char value = data[index];
            if (value == '\\' || value == '/') {
                break;
            }
            if (value == '.') {
                data[index] = '\0';
                len = index;
                break;
            }
        }
        return *this;
    }

    idStr& SetFileExtension(const char* extension) {
        StripFileExtension();
        if (extension != nullptr && extension[0] != '.') {
            Append('.');
        }
        Append(extension);
        return *this;
    }

    void Format(const char* format, ...) {
        char buffer[4096];
        va_list arguments;
        va_start(arguments, format);
        const int count = _vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE,
            format != nullptr ? format : "", arguments);
        va_end(arguments);
        if (count >= 0) Assign(buffer);
        else Clear();
    }

    void ReplaceRecovered(const char* oldText, const char* newText) {
        if (oldText == nullptr || oldText[0] == '\0') {
            return;
        }
        const char* const replacement = newText == nullptr ? "" : newText;
        const int oldLength = static_cast<int>(std::strlen(oldText));
        idStr result;
        const char* cursor = data;
        for (;;) {
            const char* const match = std::strstr(cursor, oldText);
            if (match == nullptr) {
                result.Append(cursor);
                break;
            }
            const int prefixLength = static_cast<int>(match - cursor);
            for (int index = 0; index < prefixLength; ++index) {
                result.Append(cursor[index]);
            }
            result.Append(replacement);
            cursor = match + oldLength;
        }
        Assign(result.c_str());
    }

    static int Cmp(const char* left, const char* right) {
        const char* const safeLeft = left == nullptr ? "" : left;
        const char* const safeRight = right == nullptr ? "" : right;
        return std::strcmp(safeLeft, safeRight);
    }

    // Recovered shared/idlib/text/str.cpp returns -1, 0, or 1 rather than
    // exposing the implementation-defined magnitude from strncmp.
    static int Cmpn(const char* left, const char* right, int count) {
        const unsigned char* a = reinterpret_cast<const unsigned char*>(
            left == nullptr ? "" : left);
        const unsigned char* b = reinterpret_cast<const unsigned char*>(
            right == nullptr ? "" : right);
        while (count-- > 0) {
            if (*a != *b) {
                return *a < *b ? -1 : 1;
            }
            if (*a == 0) {
                return 0;
            }
            ++a;
            ++b;
        }
        return 0;
    }

    static int Icmp(const char* left, const char* right) {
        const unsigned char* a = reinterpret_cast<const unsigned char*>(
            left == nullptr ? "" : left);
        const unsigned char* b = reinterpret_cast<const unsigned char*>(
            right == nullptr ? "" : right);
        while (*a != 0 && *b != 0) {
            const int difference = std::tolower(*a) - std::tolower(*b);
            if (difference != 0) return difference;
            ++a;
            ++b;
        }
        return std::tolower(*a) - std::tolower(*b);
    }

    bool operator==(const idStr& other) const {
        return Cmp(c_str(), other.c_str()) == 0;
    }

    bool operator!=(const idStr& other) const {
        return !(*this == other);
    }

    bool operator<(const idStr& other) const {
        return Cmp(c_str(), other.c_str()) < 0;
    }

protected:
    int len;
    char* data;
    int allocedAndFlag;
    char baseBuffer[20];

    void UseStaticBufferRecovered(char* buffer, const int capacity) {
        if (data != baseBuffer && !IsStaticBuffer()) {
            std::free(data);
        }
        data = buffer;
        len = 0;
        allocedAndFlag = capacity | static_cast<int>(0x80000000u);
        if (data != nullptr && capacity > 0) {
            data[0] = '\0';
        }
    }

private:

    int GetAlloced() const {
        return allocedAndFlag & 0x7FFFFFFF;
    }

    bool IsStaticBuffer() const {
        return (static_cast<unsigned int>(allocedAndFlag) & 0x80000000u) != 0;
    }

    bool EnsureAlloced(const int amount) {
        if (amount <= GetAlloced()) {
            return true;
        }
        if (IsStaticBuffer()) {
            return false;
        }

        const int newAmount = (std::max)(amount, amount + amount / 2);
        char* const replacement = static_cast<char*>(
            std::malloc(static_cast<std::size_t>(newAmount))
        );
        if (replacement == nullptr) {
            return false;
        }
        if (data != nullptr) {
            std::memcpy(replacement, data,
                static_cast<std::size_t>(len + 1));
        } else {
            replacement[0] = '\0';
        }
        if (data != baseBuffer) {
            std::free(data);
        }
        data = replacement;
        allocedAndFlag = newAmount;
        return true;
    }

    void Assign(const char* text) {
        const char* const source = text == nullptr ? "" : text;
        const int sourceLength = static_cast<int>(std::strlen(source));
        if (!EnsureAlloced(sourceLength + 1)) {
            return;
        }
        std::memmove(data, source, static_cast<std::size_t>(sourceLength + 1));
        len = sourceLength;
    }
};

static_assert(sizeof(idStr) == 32, "Recovered idStr ABI changed");
