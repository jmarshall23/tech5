#include "string.h"

#include "vector.h"
#include "list.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <new>

ssString::ssString() {
    Init();
}

ssString::ssString(const char* const text) {
    Init();
    *this = text;
}

// Retail symbol: ??0ssString@@QAA@H@Z
// EA: 0x82EE7ED8, RVA: 0x00EE7ED8
ssString::ssString(int value) {
    Init();
    if (value == 0) {
        Append('0');
        return;
    }

    const bool negative = value < 0;
    unsigned int magnitude = negative
        ? 0u - static_cast<unsigned int>(value)
        : static_cast<unsigned int>(value);
    while (magnitude > 0) {
        Append(static_cast<char>('0' + magnitude % 10));
        magnitude /= 10;
    }
    if (negative) {
        Append('-');
    }
    Reverse();
}

// Retail symbol: ??0ssString@@QAA@MH@Z
// EA: 0x82EE7FD8, RVA: 0x00EE7FD8
ssString::ssString(const float value, const int precision) {
    Init();
    const int integerPart = static_cast<int>(value);
    if (value < 0.0f) {
        Append('-');
    }
    Append(ssString(integerPart < 0 ? -integerPart : integerPart));

    float fraction = value - static_cast<float>(integerPart);
    if (fraction < 0.0f) {
        fraction = -fraction;
    }
    if (fraction > 0.0f) {
        Append('.');
    }
    for (int index = 0; index < precision; ++index) {
        fraction *= 10.0f;
        if (fraction <= 0.0f) {
            break;
        }
        Append(static_cast<char>('0' + static_cast<int>(fraction) % 10));
    }
}

// Retail symbol: ??0ssString@@QAA@ABVssVector@@PBD@Z
// EA: 0x82EE83A8, RVA: 0x00EE83A8
ssString::ssString(const ssVector& value, const char* format) {
    Init();
    if (format == nullptr) {
        return;
    }
    for (; *format != '\0'; ++format) {
        switch (*format) {
        case 'x':
            Append(ssString(value.x, 3));
            break;
        case 'y':
            Append(ssString(value.y, 3));
            break;
        case 'z':
            Append(ssString(value.z, 3));
            break;
        default:
            Append(*format);
            break;
        }
    }
}

// Retail symbol: ??$?0H@ssString@@QAA@ABV?$ssList@H@@PBD@Z
// EA: 0x82EE9C10, RVA: 0x00EE9C10
ssString::ssString(const ssList<int>& values, const char* const separator) {
    Init();
    if (values.num <= 0) {
        return;
    }
    Append(ssString(values.data[0]));
    for (int index = 1; index < values.num; ++index) {
        Append(separator);
        Append(ssString(values.data[index]));
    }
}

ssString::ssString(const ssString& text) {
    Init();
    *this = text;
}

ssString::~ssString() {
    Empty();
}

// Retail symbol: ?Cmp@ssString@@QBAHPBD@Z
// EA: 0x82EE7058, RVA: 0x00EE7058
int ssString::Cmp(const char* const text) const {
    if (text == nullptr) {
        return 1;
    }
    const unsigned char* lhs =
        reinterpret_cast<const unsigned char*>(c_str());
    const unsigned char* rhs =
        reinterpret_cast<const unsigned char*>(text);
    while (*lhs == *rhs) {
        if (*lhs == 0) {
            return 0;
        }
        ++lhs;
        ++rhs;
    }
    return static_cast<int>(*lhs) - static_cast<int>(*rhs);
}

// Retail symbol: ?Icmp@ssString@@SAHPBD0@Z
// EA: 0x82EE70A8, RVA: 0x00EE70A8
int ssString::Icmp(const char* text, const char* text2) {
    if (text == nullptr) {
        return 0;
    }
    if (text2 == nullptr) {
        return 1;
    }
    for (;;) {
        int lhs = static_cast<unsigned char>(*text++);
        int rhs = static_cast<unsigned char>(*text2++);
        if (lhs >= 'a' && lhs <= 'z') {
            lhs -= 'a' - 'A';
        }
        if (rhs >= 'a' && rhs <= 'z') {
            rhs -= 'a' - 'A';
        }
        if (lhs != rhs) {
            // The retail implementation subtracts its second walk from its
            // first; only equality is used by generated script dispatch.
            return rhs - lhs;
        }
        if (lhs == 0) {
            return 0;
        }
    }
}

// Retail symbol: ?Find@ssString@@QBAHDH@Z
// EA: 0x82EE7118, RVA: 0x00EE7118
int ssString::Find(const char value, int start) const {
    if (start < 0) {
        start = 0;
    }
    for (int index = start; index < len; ++index) {
        if (data[index] == value) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?ToLower@ssString@@QAAXXZ
// EA: 0x82EE7168, RVA: 0x00EE7168
void ssString::ToLower() {
    for (int index = 0; index < len; ++index) {
        if (data[index] >= 'A' && data[index] <= 'Z') {
            data[index] += 'a' - 'A';
        }
    }
}

// Retail symbol: ?ToUpper@ssString@@QAAXXZ
// EA: 0x82EE71B8, RVA: 0x00EE71B8
void ssString::ToUpper() {
    for (int index = 0; index < len; ++index) {
        if (data[index] >= 'a' && data[index] <= 'z') {
            data[index] -= 'a' - 'A';
        }
    }
}

// Retail symbol: ?Empty@ssString@@QAAXXZ
// EA: 0x82EE7208, RVA: 0x00EE7208
void ssString::Empty() {
    std::free(data);
    data = nullptr;
    alloced = 0;
    len = 0;
}

// Retail symbol: ?Reverse@ssString@@QAAXXZ
// EA: 0x82EE7268, RVA: 0x00EE7268
void ssString::Reverse() {
    for (int index = 0; index < len / 2; ++index) {
        const int opposite = len - index - 1;
        const char temporary = data[index];
        data[index] = data[opposite];
        data[opposite] = temporary;
    }
}

// Retail symbol: ?Init@ssString@@AAAXXZ
// EA: 0x82EE72B8, RVA: 0x00EE72B8
void ssString::Init() {
    len = 0;
    data = nullptr;
    alloced = 0;
    threadId = 0;
}

// Retail symbol: ?Allocate@ssString@@AAAXH@Z
// EA: 0x82EE7330, RVA: 0x00EE7330
void ssString::Allocate(const int count) {
    std::free(data);
    alloced = count;
    data = nullptr;
    len = 0;
    if (count > 0) {
        data = static_cast<char*>(std::malloc(static_cast<unsigned int>(count)));
        if (data == nullptr) {
            alloced = 0;
            throw std::bad_alloc();
        }
    }
}

// Retail symbol: ??4ssString@@QAAXABV0@@Z
// EA: 0x82EE73A8, RVA: 0x00EE73A8
void ssString::operator=(const ssString& text) {
    if (this == &text) {
        return;
    }
    Allocate(text.len + 1);
    if (text.len > 0) {
        std::memcpy(data, text.data, static_cast<unsigned int>(text.len));
    }
    len = text.len;
    data[len] = '\0';
}

// Retail symbol: ??4ssString@@QAAXPBD@Z
// EA: 0x82EE7428, RVA: 0x00EE7428
void ssString::operator=(const char* const text) {
    const char* const source = text != nullptr ? text : "";
    const int sourceLength = static_cast<int>(std::strlen(source));
    if (sourceLength >= alloced) {
        Allocate(sourceLength + 1);
    }
    if (sourceLength > 0) {
        std::memcpy(data, source, static_cast<unsigned int>(sourceLength));
    }
    len = sourceLength;
    data[len] = '\0';
}

// Retail symbol: ??4ssString@@QAAXD@Z
// EA: 0x82EE7540, RVA: 0x00EE7540
void ssString::operator=(const char value) {
    Allocate(2);
    len = 1;
    data[0] = value;
    data[1] = '\0';
}

// Retail symbol: ??AssString@@QAAAADH@Z
// EA: 0x82EE7598, RVA: 0x00EE7598
char& ssString::operator[](const int index) {
    assert(index >= 0 && index < len);
    return data[index];
}

const char& ssString::operator[](const int index) const {
    assert(index >= 0 && index < len);
    return data[index];
}

// Retail symbol: ?Right@ssString@@QBA?AV1@H@Z
// EA: 0x82EE75F8, RVA: 0x00EE75F8
ssString ssString::Right(const int count) const {
    if (count < 0) {
        return ssString("");
    }
    return ssString(len >= count ? data + len - count : c_str());
}

// Retail symbol: ?Skip@ssString@@QBA?AV1@H@Z
// EA: 0x82EE7678, RVA: 0x00EE7678
ssString ssString::Skip(const int count) const {
    if (count < 0) {
        return ssString("");
    }
    return ssString(len >= count ? data + count : c_str());
}

// Retail symbol: ?Find@ssString@@QBAHABV1@H@Z
// EA: 0x82EE76F0, RVA: 0x00EE76F0
int ssString::Find(const ssString& value, int start) const {
    if (start < 0) {
        start = 0;
    }
    if (value.len == 0) {
        return -1;
    }
    const int lastStart = len - value.len;
    for (int index = start; index <= lastStart; ++index) {
        if (std::memcmp(data + index, value.data,
                static_cast<unsigned int>(value.len)) == 0) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?EnsureAllocated@ssString@@AAAXH@Z
// EA: 0x82EE77B0, RVA: 0x00EE77B0
void ssString::EnsureAllocated(const int count) {
    if (alloced >= count) {
        return;
    }
    char* const replacement =
        static_cast<char*>(std::malloc(static_cast<unsigned int>(count)));
    if (replacement == nullptr) {
        throw std::bad_alloc();
    }
    if (data != nullptr) {
        std::memcpy(replacement, data, static_cast<unsigned int>(len + 1));
        std::free(data);
    }
    data = replacement;
    alloced = count;
}

// Retail symbol: ?Left@ssString@@QBA?AV1@H@Z
// EA: 0x82EE78C0, RVA: 0x00EE78C0
ssString ssString::Left(const int count) const {
    if (count < 0) {
        return ssString("");
    }
    if (len < count) {
        return ssString(*this);
    }
    ssString result;
    result.EnsureAllocated(count + 1);
    if (count > 0) {
        std::memcpy(result.data, data, static_cast<unsigned int>(count));
    }
    result.len = count;
    result.data[count] = '\0';
    return result;
}

// Retail symbol: ?Mid@ssString@@QBA?AV1@HH@Z
// EA: 0x82EE7A70, RVA: 0x00EE7A70
ssString ssString::Mid(int start, int count) const {
    if (count < 0) {
        return ssString("");
    }
    if (start < 0) {
        start = 0;
    }
    if (start > len) {
        start = len;
    }
    if (start + count > len) {
        count = len - start;
    }
    ssString result;
    result.EnsureAllocated(count + 1);
    if (count > 0) {
        std::memcpy(result.data, data + start,
            static_cast<unsigned int>(count));
    }
    result.len = count;
    result.data[count] = '\0';
    return result;
}

// Retail symbol: ?Append@ssString@@QAAXD@Z
// EA: 0x82EE7C18, RVA: 0x00EE7C18
void ssString::Append(const char value) {
    if (value == '\0') {
        return;
    }
    EnsureAllocated(len + 2);
    data[len++] = value;
    data[len] = '\0';
}

// Retail symbol: ?Append@ssString@@QAAXABV1@@Z
// EA: 0x82EE7C88, RVA: 0x00EE7C88
void ssString::Append(const ssString& value) {
    if (value.len == 0) {
        return;
    }
    if (this == &value) {
        const ssString copy(value);
        Append(copy);
        return;
    }
    EnsureAllocated(len + value.len + 1);
    std::memcpy(data + len, value.data,
        static_cast<unsigned int>(value.len));
    len += value.len;
    data[len] = '\0';
}

// Retail symbol: ?Append@ssString@@QAAXPBD@Z
// EA: 0x82EE7D30, RVA: 0x00EE7D30
void ssString::Append(const char* const value) {
    if (value == nullptr) {
        return;
    }
    const int appendLength = static_cast<int>(std::strlen(value));
    if (appendLength == 0) {
        return;
    }
    // Preserve an aliased substring if growth invalidates the original data.
    if (data != nullptr && value >= data && value <= data + len) {
        const ssString copy(value);
        Append(copy);
        return;
    }
    EnsureAllocated(len + appendLength + 1);
    std::memcpy(data + len, value, static_cast<unsigned int>(appendLength));
    len += appendLength;
    data[len] = '\0';
}

// Retail symbol: ??H@YA?AVssString@@ABV0@0@Z
// EA: 0x82EE81B0, RVA: 0x00EE81B0
ssString operator+(const ssString& lhs, const ssString& rhs) {
    ssString result(lhs);
    result.Append(rhs);
    return result;
}

// Retail symbol: ??H@YA?AVssString@@ABV0@PBD@Z
// EA: 0x82EE8258, RVA: 0x00EE8258
ssString operator+(const ssString& lhs, const char* const rhs) {
    ssString result(lhs);
    result.Append(rhs);
    return result;
}

// Retail symbol: ??H@YA?AVssString@@PBDABV0@@Z
// EA: 0x82EE8300, RVA: 0x00EE8300
ssString operator+(const char* const lhs, const ssString& rhs) {
    ssString result(lhs);
    result.Append(rhs);
    return result;
}
