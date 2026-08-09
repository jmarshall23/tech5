#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "idlib/containers/hashindex.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdint>

class idDecl;
class idDeclFile;
class idDeclInfo;
class idParser;

struct idDeclSource {
    idAtomicString name;
    idDeclFile* sourceFile;
    int sourceLine;
    idDeclSource* nextInFile;
    bool isStatic;
    int sourceTextOffset;
    int sourceTextLength;

    idDeclSource();
    const char* GetFileName() const;
};

class idDecl : public idResource {
public:
    idDecl();
    ~idDecl() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;
    void Print() override;
    void List() override;

    virtual unsigned int GetDeclTimestamp() const;
    virtual idDeclInfo* GetDeclInfo() const;
    virtual bool RebuildTextSource();
    virtual bool SetImplicitText();
    virtual const char* DefaultDefinition() const;
    virtual void LogMissingDecl() const;
    virtual void Parse(idParser* parser);
    virtual void FreeData();
    virtual unsigned int Size() const;

    int GetLineNum() const;
    bool SourceFileExists() const;
    bool EverReloaded() const;
    bool IsImplicit() const;
    const char* GetFileName() const;
    void SetText(const char* text, int length = 0);
    const char* GetText() const;
    void MakeDefault();
    void Revert();
    bool ReplaceSourceFileText(bool force);
    void ReParse(bool force);

    char* textSource;
    int textLength;
    unsigned int md5Checksum;
    bool programaticallyDefined;
    idDeclSource* declSource;

protected:
    void DefineFromSource(idDeclSource* source);
    void DeleteUnusedText();

    friend class idDeclManagerLocal;
};

class idDeclFile {
public:
    idDeclFile(const char* fileName = nullptr,
        idDeclInfo* defaultDeclarationType = nullptr);

    bool SourceFileChanged(bool updateTimestamp) const;
    void FreeDynamic();
    void AddDecl(idDeclInfo* type, const char* name, int sourceLine,
        int sourceOffset, int sourceLength);
    int LoadAndParse();

    bool hadRedefinition;
    idAtomicString fileName;
    idDeclInfo* defaultType;
    unsigned int timestamp;
    unsigned int checksum;
    int fileSize;
    int numLines;
    bool everReloaded;
    idDeclSource* firstDeclSourceInFile;
    idList<int, 46> dependencies;
    int dependenciesDynamicStartIndex;
    idList<idStr, 5> includeFiles;
};

class idDeclInfo : public idResourceList {
public:
    idDeclInfo(const char* identifier = nullptr,
        const char* className = nullptr, const char* fileExtension = nullptr);
    ~idDeclInfo() override;

    idResource* Alloc(const char* resourceName) override;
    int AllocSize() override;
    virtual idDecl* AllocDecl();

    idDeclSource* FindDeclSource(const char* declarationName) const;
    const idDecl* FindWithInheritance(const char* declarationName,
        bool makeDefault) const;
    void FreeDynamic();
    void AddDeclSource(idDeclSource* source);

    const char* name;
    const char* classname;
    const char* fileExtension;
    idAtomicString nameExtension;
    idAtomicString defaultFolder;
    idDeclInfo* parent;
    void (*onReload)(const idDecl* declaration);
    idList<idDeclSource*, 46> declSources;
    idHashIndex declSourceHash;
    int declSourceDynamicStartIndex;
};

template<class declarationType>
class idDeclInfoTemplate : public idDeclInfo {
public:
    idDeclInfoTemplate(const char* identifier, const char* className,
            const char* extension)
        : idDeclInfo(identifier, className, extension) {
    }

    idDecl* AllocDecl() override { return new declarationType(); }
    int AllocSize() override { return sizeof(declarationType); }
};

using fxDecl = class idDeclFX*;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclSource) == 28,
    "Recovered declaration-source ABI changed");
static_assert(sizeof(idDeclFile) == 72,
    "Recovered declaration-file ABI changed");
static_assert(sizeof(idDeclInfo) == 1124,
    "Recovered declaration-info ABI changed");
static_assert(sizeof(idDecl) == 56,
    "Recovered base declaration ABI changed");
#endif
