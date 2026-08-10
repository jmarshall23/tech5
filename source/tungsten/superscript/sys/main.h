#pragma once

class idGameSuperInterface;
class idSSObject;
struct ssEnumTypeInfo_t;
struct ssMetaData_t;
struct ssVarInfo_t;

class idSuperScript {
public:
    virtual ~idSuperScript() = default;
    virtual idGameSuperInterface* Lock(idGameSuperInterface* gameInterface) = 0;
    virtual void RegisterCVars() = 0;
    virtual const char** GetObjectList() = 0;
    virtual idSSObject* AllocObject(const char* typeName) = 0;
    virtual ssVarInfo_t* GetVariablesFor(const char* typeName) = 0;
    virtual const char* GetCommentTextFor(const char* typeName) = 0;
    virtual ssEnumTypeInfo_t* GetEnumTypeInfoFor(const char* typeName) = 0;
    virtual int GetTypeSize(const char* typeName) = 0;
    virtual ssMetaData_t* GetMetaDataFor(const char* typeName) = 0;
    virtual void* AllocType(const char* typeName, int count) = 0;
    virtual bool CheckVersionCRC(unsigned int crc) = 0;
};

class idSuperScriptLocal : public idSuperScript {
public:
    idGameSuperInterface* Lock(idGameSuperInterface* newInterface) override;
    void RegisterCVars() override;

    // Implemented by the generated reflection/object translation units.
    const char** GetObjectList() override;
    idSSObject* AllocObject(const char* typeName) override;
    ssVarInfo_t* GetVariablesFor(const char* typeName) override;
    const char* GetCommentTextFor(const char* typeName) override;
    ssEnumTypeInfo_t* GetEnumTypeInfoFor(const char* typeName) override;
    int GetTypeSize(const char* typeName) override;
    ssMetaData_t* GetMetaDataFor(const char* typeName) override;
    void* AllocType(const char* typeName, int count) override;
    bool CheckVersionCRC(unsigned int crc) override;
};

extern idGameSuperInterface* gameInterface;
extern idSuperScriptLocal superScriptLocal;

void Tungsten_RegisterStaticSuperScriptCVars();
idSuperScript* GetSuperScriptAPI(int version);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idSuperScript) == 4,
    "Recovered SuperScript interface ABI changed");
static_assert(sizeof(idSuperScriptLocal) == 4,
    "Recovered local SuperScript interface ABI changed");
#endif
