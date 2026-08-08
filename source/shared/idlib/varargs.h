#pragma once

#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <limits>
#include <malloc.h>

enum argTypes_t {
    ARG_BOOL = 1,
    ARG_CHAR = 2,
    ARG_INTEGER = 3,
    ARG_FLOAT = 4,
    ARG_VECTOR = 5,
    ARG_QUAT = 6,
    ARG_ANGLES = 7,
    ARG_STRING = 8,
    ARG_DECL = 9,
    ARG_ENTITY = 10,
    ARG_CLASS = 11,
    ARG_VECTOR4 = 12,
    ARG_ANIMALIAS = 13,
    ARG_SPAWNID = 14,
    ARG_TYPES_MAX = 15
};

// Compact heterogeneous argument storage recovered from animation, voice and
// FSM call sites. MAX_ARGS is part of the object ABI (2, 4 and 6 occur).
template<int MAX_ARGS>
class idVarArgs {
public:
    idVarArgs()
        : numArgs(0), argSize(0), buffSize(0), args(nullptr) {
        std::memset(argOffsets, 0, sizeof(argOffsets));
        std::memset(argTypes, 0, sizeof(argTypes));
        std::memset(argExTypes, 0, sizeof(argExTypes));
    }

    idVarArgs(const idVarArgs& other)
        : idVarArgs() {
        Copy(other);
    }

    idVarArgs(idVarArgs&& other) noexcept
        : numArgs(other.numArgs), argSize(other.argSize), buffSize(other.buffSize),
          args(other.args) {
        std::memcpy(argOffsets, other.argOffsets, sizeof(argOffsets));
        std::memcpy(argTypes, other.argTypes, sizeof(argTypes));
        std::memcpy(argExTypes, other.argExTypes, sizeof(argExTypes));
        other.ResetWithoutFree();
    }

    ~idVarArgs() { Free(); }

    idVarArgs& operator=(const idVarArgs& other) {
        Copy(other);
        return *this;
    }

    idVarArgs& operator=(idVarArgs&& other) noexcept {
        if (this != &other) {
            Free();
            numArgs = other.numArgs;
            argSize = other.argSize;
            buffSize = other.buffSize;
            args = other.args;
            std::memcpy(argOffsets, other.argOffsets, sizeof(argOffsets));
            std::memcpy(argTypes, other.argTypes, sizeof(argTypes));
            std::memcpy(argExTypes, other.argExTypes, sizeof(argExTypes));
            other.ResetWithoutFree();
        }
        return *this;
    }

    void ClearArgs() {
        Free();
        std::memset(argOffsets, 0, sizeof(argOffsets));
        std::memset(argTypes, 0, sizeof(argTypes));
        std::memset(argExTypes, 0, sizeof(argExTypes));
    }

    int NumArgs() const { return numArgs; }
    int GetArgSize() const { return argSize; }
    int GetArgType(const int index) const {
        return IsValidIndex(index) ? argTypes[index] : 0;
    }
    int GetArgExType(const int index) const {
        return IsValidIndex(index) ? argExTypes[index] : 0;
    }

    void AddArg(const bool value, const std::uint8_t exType = 0) {
        const std::uint8_t stored = value ? 1 : 0;
        AddRaw(ARG_BOOL, exType, &stored, sizeof(stored));
    }
    void AddArg(const char value, const std::uint8_t exType = 0) {
        AddRaw(ARG_CHAR, exType, &value, sizeof(value));
    }
    void AddArg(const int value, const std::uint8_t exType = 0) {
        AddRaw(ARG_INTEGER, exType, &value, sizeof(value));
    }
    void AddArg(const float value, const std::uint8_t exType = 0) {
        AddRaw(ARG_FLOAT, exType, &value, sizeof(value));
    }
    void AddArg(const idVec3& value, const std::uint8_t exType = 0) {
        AddRaw(ARG_VECTOR, exType, &value, 12);
    }
    void AddArg(const idQuat& value, const std::uint8_t exType = 0) {
        AddRaw(ARG_QUAT, exType, &value, 16);
    }
    void AddArg(const idAngles& value, const std::uint8_t exType = 0) {
        AddRaw(ARG_ANGLES, exType, &value, 12);
    }
    void AddArg(const idVec4& value, const std::uint8_t exType = 0) {
        AddRaw(ARG_VECTOR4, exType, &value, 16);
    }
    void AddArg(const char* value, const std::uint8_t exType = 0) {
        const char* const text = value == nullptr ? "" : value;
        AddRaw(ARG_STRING, exType, text,
            static_cast<unsigned int>(std::strlen(text) + 1));
    }

    void AddHandleArg(const int value, const std::uint8_t type,
            const std::uint8_t exType = 0) {
        AddRaw(type, exType, &value, sizeof(value));
    }

    bool GetArg(const int index, bool& value) const {
        std::uint8_t stored = 0;
        if (!GetRaw(index, ARG_BOOL, &stored, sizeof(stored))) return false;
        value = stored != 0;
        return true;
    }
    bool GetArg(const int index, char& value) const {
        return GetRaw(index, ARG_CHAR, &value, sizeof(value));
    }
    bool GetArg(const int index, int& value) const {
        return GetRaw(index, ARG_INTEGER, &value, sizeof(value));
    }
    bool GetArg(const int index, float& value) const {
        return GetRaw(index, ARG_FLOAT, &value, sizeof(value));
    }
    bool GetArg(const int index, idVec3& value) const {
        return GetRaw(index, ARG_VECTOR, &value, 12);
    }
    bool GetArg(const int index, idQuat& value) const {
        return GetRaw(index, ARG_QUAT, &value, 16);
    }
    bool GetArg(const int index, idAngles& value) const {
        return GetRaw(index, ARG_ANGLES, &value, 12);
    }
    bool GetArg(const int index, idVec4& value) const {
        return GetRaw(index, ARG_VECTOR4, &value, 16);
    }
    bool GetArg(const int index, idStr& value) const {
        const char* text = nullptr;
        if (!GetArg(index, text)) return false;
        value = text;
        return true;
    }
    bool GetArg(const int index, const char*& value) const {
        if (!IsValidIndex(index) || argTypes[index] != ARG_STRING) return false;
        value = reinterpret_cast<const char*>(args + argOffsets[index]);
        return true;
    }
    bool GetArg(const int index, void*& value) const {
        if (!IsValidIndex(index) || (argTypes[index] != ARG_DECL
                && argTypes[index] != ARG_ENTITY && argTypes[index] != ARG_CLASS)) {
            return false;
        }
        std::memcpy(&value, args + argOffsets[index], sizeof(value));
        return true;
    }
    bool GetHandleArg(const int index, int& value,
            const std::uint8_t type) const {
        return GetRaw(index, type, &value, sizeof(value));
    }

    bool Equal(const idVarArgs& other) const {
        return numArgs == other.numArgs && argSize == other.argSize
            && std::memcmp(argOffsets, other.argOffsets, sizeof(argOffsets)) == 0
            && std::memcmp(argTypes, other.argTypes, sizeof(argTypes)) == 0
            && std::memcmp(argExTypes, other.argExTypes, sizeof(argExTypes)) == 0
            && (argSize == 0 || std::memcmp(args, other.args, argSize) == 0);
    }

    bool operator==(const idVarArgs& other) const { return Equal(other); }
    bool operator!=(const idVarArgs& other) const { return !Equal(other); }

private:
    bool IsValidIndex(const int index) const {
        return index >= 0 && index < numArgs;
    }

    bool Grow(const unsigned int amount) {
        if (amount == 0) return true;
        const unsigned int needed = static_cast<unsigned int>(argSize) + amount;
        if (needed > std::numeric_limits<std::uint16_t>::max()) return false;
        if (needed <= buffSize) return true;
        unsigned int newSize = std::max(needed,
            static_cast<unsigned int>(buffSize) * 2u);
        unsigned char* const replacement = static_cast<unsigned char*>(
            _aligned_malloc(newSize, 16));
        if (replacement == nullptr) return false;
        if (args != nullptr && argSize > 0) {
            std::memcpy(replacement, args, argSize);
        }
        _aligned_free(args);
        args = replacement;
        buffSize = static_cast<std::uint16_t>(newSize);
        return true;
    }

    bool AddRaw(const std::uint8_t type, const std::uint8_t exType,
            const void* source, const unsigned int bytes) {
        if (numArgs >= MAX_ARGS || source == nullptr || !Grow(bytes)) return false;
        argTypes[numArgs] = type;
        argExTypes[numArgs] = exType;
        argOffsets[numArgs] = argSize;
        std::memcpy(args + argSize, source, bytes);
        argSize = static_cast<std::uint16_t>(argSize + bytes);
        ++numArgs;
        return true;
    }

    bool GetRaw(const int index, const std::uint8_t type,
            void* destination, const unsigned int bytes) const {
        if (!IsValidIndex(index) || argTypes[index] != type
                || destination == nullptr
                || static_cast<unsigned int>(argOffsets[index]) + bytes > argSize) {
            return false;
        }
        std::memcpy(destination, args + argOffsets[index], bytes);
        return true;
    }

    void Copy(const idVarArgs& other) {
        if (this == &other) return;
        ClearArgs();
        if (other.buffSize > 0 && !Grow(other.buffSize)) return;
        numArgs = other.numArgs;
        argSize = other.argSize;
        std::memcpy(argOffsets, other.argOffsets, sizeof(argOffsets));
        std::memcpy(argTypes, other.argTypes, sizeof(argTypes));
        std::memcpy(argExTypes, other.argExTypes, sizeof(argExTypes));
        if (argSize > 0) std::memcpy(args, other.args, argSize);
    }

    void Free() {
        _aligned_free(args);
        ResetWithoutFree();
    }

    void ResetWithoutFree() {
        numArgs = 0;
        argSize = 0;
        buffSize = 0;
        args = nullptr;
    }

    std::uint16_t numArgs;
    std::uint16_t argSize;
    std::uint16_t buffSize;
    std::uint16_t argOffsets[MAX_ARGS];
    std::uint8_t argTypes[MAX_ARGS];
    std::uint8_t argExTypes[MAX_ARGS];
    unsigned char* args;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idVarArgs<2>) == 20, "Recovered idVarArgs<2> ABI changed");
static_assert(sizeof(idVarArgs<4>) == 28, "Recovered idVarArgs<4> ABI changed");
static_assert(sizeof(idVarArgs<6>) == 36, "Recovered idVarArgs<6> ABI changed");
#endif

