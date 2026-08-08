#pragma once

#include <cstdint>

class idStr;
class idVec3;
class idVecX;
class idMatX;
class idAngles;
class idColor;

struct idTypeInfoSettings {
    enum writeModifier_t {
        WRITE_ALL_PROPERTIES = 0,
        WRITE_DEF_AND_EDIT_ONLY = 1,
        WRITE_EDIT_ONLY = 2
    };

    idTypeInfoSettings();
    idTypeInfoSettings(bool resolveEntityPointers,
        bool resolveModelPointers);
    idTypeInfoSettings(bool resolveEntityPointers,
        bool resolveModelPointers, bool skipMarkedObjects);

    writeModifier_t writeModifier;
    bool resolveEntityPointers;
    bool resolveModelPointers;
    bool skipMarkedObjects;
    bool skipScriptObjects;
    bool writeComments;
    bool writeType;
};

class idTypeInfoFile {
public:
    explicit idTypeInfoFile(int indent = 0);
    ~idTypeInfoFile();

    idTypeInfoFile(const idTypeInfoFile&) = delete;
    idTypeInfoFile& operator=(const idTypeInfoFile&) = delete;

    bool WriteMemoryFile();
    const char* GetTypeInfoString() const;
    bool ReadMemory(const char* data, int length, const char* name,
        int startLine = 1);
    bool ReadMemoryFile();

    void WriteOpeningBrace();
    void ReadOpeningBrace();
    bool CheckOpeningBrace();
    void WriteClosingBrace();
    void ReadClosingBrace();
    bool CheckClosingBrace();
    bool PeekClosingBrace();

    void WriteSkipObject(bool skip);
    bool CheckSkipObject();

    bool CheckType(const char* type, const char* ops, const char* name);
    void WriteType(const char* type, const char* ops, const char* name);
    bool ReadType(idStr& type, idStr& ops, idStr& name);
    bool ExpectType(const char* type, const char* ops, const char* name);

    void WriteArrayElementType(const char* type, const char* ops,
        const char* name, int index);
    bool ReadArrayElementType(idStr& type, idStr& ops, idStr& name,
        int& index);
    bool CheckArrayElementType(idStr& type, idStr& ops, idStr& name,
        int& index);
    bool ExpectArrayElementType(const char* type, const char* ops,
        const char* name, int& index);

    void WriteBool(bool value);
    void ReadBool(bool& value);
    void WriteChar(char value);
    void ReadChar(char& value);
    void WriteUnsignedChar(unsigned char value);
    void ReadUnsignedChar(unsigned char& value);
    void WriteWChar(wchar_t value);
    void ReadWChar(wchar_t& value);
    void WriteShort(short value);
    void ReadShort(short& value);
    void WriteUnsignedShort(unsigned short value);
    void ReadUnsignedShort(unsigned short& value);
    void WriteUnsignedLong(unsigned long value);
    void ReadUnsignedLong(unsigned long& value);
    void WriteInt(int value);
    void ReadInt(int& value);
    void WriteFloat(float value);
    void ReadFloat(float& value);
    void WriteDouble(double value);
    void ReadDouble(double& value);

    void WriteStr(const char* value);
    void ReadStr(idStr& value);
    void WriteValueString(const idStr& value);
    void ReadValueString(idStr& value);

    void WriteNullPointer();
    void ReadNullPointer();
    bool CheckNullPointer();
    void WriteUnknown();
    void ReadUnknown();
    bool CheckUnknown();

    void WriteVec3(const idVec3& value);
    void ReadVec3(idVec3& value);
    void WriteVecX(const idVecX& value);
    void ReadVecX(idVecX& value);
    void WriteMatX(const idMatX& value);
    void ReadMatX(idMatX& value);
    void WriteAngles(const idAngles& value);
    void ReadAngles(idAngles& value);
    void WriteColor(const idColor& value);
    void ReadColor(idColor& value);

    void WriteComment(const char* comment);
    void ReadComment(idStr& comment);
    void Error(const char* format, ...);
    void Warning(const char* format, ...);
    bool HadError() const;

    static const char* OutputTabs(bool& newline, int indent);

    idTypeInfoSettings settings;
    void* fp;
    std::uint8_t src[136];
    int indent;
    bool newline;
};

class idTypeInfoStrings {
public:
    const char* GetStringForIndex(int index) const;
    int FindString(const char* string);
    void Shutdown();

private:
    std::uint32_t strings[4];
    std::uint32_t stringHash[8];
};

static_assert(sizeof(idTypeInfoSettings) == 12,
    "Recovered idTypeInfoSettings layout changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTypeInfoFile) == 160,
    "Recovered idTypeInfoFile layout changed");
static_assert(sizeof(idTypeInfoStrings) == 48,
    "Recovered idTypeInfoStrings layout changed");
#endif
