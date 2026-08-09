#pragma once

#include "decls/declmanager.h"

class idCmdArgs;

struct alignas(4) declFileDependency_t {
    idAtomicString fileName;
    unsigned int timestamp;
    bool dirty;
};

class idDeclManagerLocal : public idDeclManager {
public:
    idDeclManagerLocal();
    ~idDeclManagerLocal() override;

    void Init() override;
    void Shutdown() override;
    void Reload(bool force) override;
    void MarkStatic() override;
    void FreeDynamic() override;
    void RegisterDeclFolder(const char* folder, const char* extension,
        idDeclInfo* defaultType) override;
    int GetNumDeclTypes() const override;
    idDeclInfo* GetDeclType(const char* typeName) const override;
    idDeclInfo* GetDeclType(int index) const override;
    idDeclInfo* GetDeclTypeFromClassname(
        const char* className) const override;
    idDecl* CreateNewDecl(idDeclInfo* type, const char* declarationName,
        const char* fileName, const char* sourceText) override;
    void AddDependency(idDecl* declaration,
        const char* dependencyFile) override;
    void AddDependency(idDecl* declaration,
        const idDecl* dependency) override;
    void ArgCompletion_DeclTypeName(idAutoComplete* completion) override;
    void ArgCompletion_DeclName(idAutoComplete* completion,
        idDeclInfo* type) override;
    void PrintMultiplayerDeclOverrides() const override;

    void GetLogDeclsList(idList<idStr, 5>& declarations) const;

    static void ListDecls_f(const idCmdArgs& args);
    static void TouchDecl_f(const idCmdArgs& args);
    static void ReExportDecls_f(const idCmdArgs& args);
    static void MakeDeclTree_f(const idCmdArgs& args);
    static void ReloadDecls_f(const idCmdArgs& args);
    static void GetDeclTextHeader(idDeclInfo* type,
        const char* declarationName, idStr& header);

    idList<idDeclInfo*, 46> declTypes;
    idList<idDeclFile*, 46> loadedFiles;
    int loadedFilesDynamicStartIndex;
    idList<declFileDependency_t, 46> declFileDependencies;
    int dependenciesDynamicStartIndex;
    int checksum;
    idList<idStr, 5> multiplayerDeclOverrides;
    idList<idStr, 5> registeredDeclLogTypes;
};

void ShowAvailableDeclLogs(idAutoComplete& completion);

extern idDeclManagerLocal declManagerLocal;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(declFileDependency_t) == 12,
    "Recovered declaration dependency ABI changed");
static_assert(sizeof(idDeclManagerLocal) == 96,
    "Recovered local declaration-manager ABI changed");
#endif
