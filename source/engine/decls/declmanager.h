#pragma once

#include "decls/decl.h"

class idAutoComplete;

class idDeclManager {
public:
    virtual ~idDeclManager() = default;
    virtual void Init() = 0;
    virtual void Shutdown() = 0;
    virtual void Reload(bool force) = 0;
    virtual void MarkStatic() = 0;
    virtual void FreeDynamic() = 0;
    virtual void RegisterDeclFolder(const char* folder,
        const char* extension, idDeclInfo* defaultType) = 0;
    virtual int GetNumDeclTypes() const = 0;
    virtual idDeclInfo* GetDeclType(const char* typeName) const = 0;
    virtual idDeclInfo* GetDeclType(int index) const = 0;
    virtual idDeclInfo* GetDeclTypeFromClassname(
        const char* className) const = 0;
    virtual idDecl* CreateNewDecl(idDeclInfo* type, const char* name,
        const char* fileName, const char* sourceText) = 0;
    virtual void AddDependency(idDecl* declaration,
        const char* dependencyFile) = 0;
    virtual void AddDependency(idDecl* declaration,
        const idDecl* dependency) = 0;
    virtual void ArgCompletion_DeclTypeName(idAutoComplete* completion) = 0;
    virtual void ArgCompletion_DeclName(idAutoComplete* completion,
        idDeclInfo* type) = 0;
    virtual void PrintMultiplayerDeclOverrides() const = 0;
};

extern idDeclManager* declManager;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclManager) == 4,
    "Recovered declaration-manager interface ABI changed");
#endif
