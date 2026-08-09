#include "decls/declmanagerlocal.h"

#include "idlib/csystems/autocomplete.h"
#include "idlib/hashing/crc32.h"
#include "idlib/lib_print.h"

#include <cstring>

void Decls_RegisterBuiltinDeclTypes(idDeclManagerLocal& manager);
void Decls_RegisterConsoleCommands(idDeclManagerLocal& manager);
void Decls_UnregisterConsoleCommands(idDeclManagerLocal& manager);
void Decls_CompleteText(idAutoComplete& completion, const char* text);
void Decls_ExecuteManagerCommand(const char* command,
    const idCmdArgs& arguments);
void Decls_RegisterFolder(idDeclManagerLocal& manager, const char* folder,
    const char* extension, idDeclInfo* defaultType);
void Decls_AddFileDependency(idDeclManagerLocal& manager,
    const char* declarationFile, const char* dependencyFile);
void Decls_PrintMultiplayerOverride(const char* declarationName);

idDeclManagerLocal declManagerLocal;
idDeclManager* declManager = &declManagerLocal;

idDeclManagerLocal::idDeclManagerLocal()
    : declTypes(0)
    , loadedFiles(0)
    , loadedFilesDynamicStartIndex(0)
    , declFileDependencies(0)
    , dependenciesDynamicStartIndex(0)
    , checksum(0)
    , multiplayerDeclOverrides(0)
    , registeredDeclLogTypes(0) {
}

idDeclManagerLocal::~idDeclManagerLocal() { Shutdown(); }

void idDeclManagerLocal::Init() {
    if (declTypes.Num() != 0) return;
    Decls_RegisterBuiltinDeclTypes(*this);
    Decls_RegisterConsoleCommands(*this);
    MarkStatic();
}

void idDeclManagerLocal::Shutdown() {
    Decls_UnregisterConsoleCommands(*this);
    for (int index = 0; index < loadedFiles.Num(); ++index)
        delete loadedFiles[index];
    loadedFiles.ClearFree();
    // Declaration type records are executable-lifetime statics materialized
    // by declholder/gamedecls, matching the recovered resource-list registry.
    // The manager owns only the pointer array, not those records.
    declTypes.ClearFree();
    declFileDependencies.ClearFree();
    multiplayerDeclOverrides.ClearFree();
    registeredDeclLogTypes.ClearFree();
    checksum = 0;
}

void idDeclManagerLocal::Reload(const bool force) {
    checksum = 0;
    for (int index = 0; index < loadedFiles.Num(); ++index) {
        idDeclFile* file = loadedFiles[index];
        if (file == nullptr) continue;
        if (force || file->SourceFileChanged(true)) {
            file->everReloaded = true;
            file->LoadAndParse();
        }
        checksum ^= static_cast<int>(file->checksum);
    }
}

void idDeclManagerLocal::MarkStatic() {
    loadedFilesDynamicStartIndex = loadedFiles.Num();
    dependenciesDynamicStartIndex = declFileDependencies.Num();
    for (int index = 0; index < declTypes.Num(); ++index) {
        idDeclInfo* type = declTypes[index];
        if (type == nullptr) continue;
        type->declSourceDynamicStartIndex = type->declSources.Num();
        for (int source = 0; source < type->declSources.Num(); ++source)
            type->declSources[source]->isStatic = true;
    }
    idAtomicString::MarkStatic();
}

void idDeclManagerLocal::FreeDynamic() {
    for (int index = 0; index < declTypes.Num(); ++index)
        if (declTypes[index] != nullptr) declTypes[index]->FreeDynamic();
    for (int index = loadedFiles.Num() - 1;
            index >= loadedFilesDynamicStartIndex; --index) {
        delete loadedFiles[index];
        loadedFiles.RemoveIndexFast(index);
    }
    declFileDependencies.SetNum(dependenciesDynamicStartIndex);
    idAtomicString::FreeDynamic();
}

void idDeclManagerLocal::RegisterDeclFolder(const char* const folder,
        const char* const extension, idDeclInfo* const defaultType) {
    if (folder == nullptr || extension == nullptr || defaultType == nullptr)
        return;
    if (declTypes.FindIndex(defaultType) < 0) declTypes.Append(defaultType);
    defaultType->defaultFolder.Set(folder);
    Decls_RegisterFolder(*this, folder, extension, defaultType);
}

int idDeclManagerLocal::GetNumDeclTypes() const { return declTypes.Num(); }

idDeclInfo* idDeclManagerLocal::GetDeclType(
        const char* const typeName) const {
    if (typeName == nullptr) return nullptr;
    for (int index = 0; index < declTypes.Num(); ++index) {
        idDeclInfo* type = declTypes[index];
        if (type != nullptr && type->name != nullptr &&
                _stricmp(type->name, typeName) == 0) return type;
    }
    return nullptr;
}

idDeclInfo* idDeclManagerLocal::GetDeclType(const int index) const {
    return index >= 0 && index < declTypes.Num() ? declTypes[index] : nullptr;
}

idDeclInfo* idDeclManagerLocal::GetDeclTypeFromClassname(
        const char* const className) const {
    if (className == nullptr) return nullptr;
    for (int index = 0; index < declTypes.Num(); ++index) {
        idDeclInfo* type = declTypes[index];
        if (type != nullptr && type->classname != nullptr &&
                _stricmp(type->classname, className) == 0) return type;
    }
    return nullptr;
}

idDecl* idDeclManagerLocal::CreateNewDecl(idDeclInfo* const type,
        const char* const declarationName, const char* const fileName,
        const char* const sourceText) {
    if (type == nullptr || declarationName == nullptr) return nullptr;
    idDecl* declaration = static_cast<idDecl*>(type->Alloc(declarationName));
    if (declaration == nullptr) return nullptr;
    declaration->programaticallyDefined = true;
    declaration->SetText(sourceText != nullptr ? sourceText : "{}", 0);
    if (fileName != nullptr && *fileName != '\0') {
        idDeclFile* file = new idDeclFile(fileName, type);
        loadedFiles.Append(file);
        file->AddDecl(type, declarationName, 1, 0,
            declaration->textLength);
        declaration->declSource = file->firstDeclSourceInFile;
    }
    declaration->ReParse(true);
    return declaration;
}

void idDeclManagerLocal::AddDependency(idDecl* const declaration,
        const char* const dependencyFile) {
    if (declaration == nullptr || dependencyFile == nullptr) return;
    Decls_AddFileDependency(*this, declaration->GetFileName(),
        dependencyFile);
}

void idDeclManagerLocal::AddDependency(idDecl* const declaration,
        const idDecl* const dependency) {
    if (dependency != nullptr)
        AddDependency(declaration, dependency->GetFileName());
}

void idDeclManagerLocal::ArgCompletion_DeclTypeName(
        idAutoComplete* const completion) {
    if (completion == nullptr) return;
    for (int index = 0; index < declTypes.Num(); ++index)
        if (declTypes[index] != nullptr)
            Decls_CompleteText(*completion, declTypes[index]->name);
}

void idDeclManagerLocal::ArgCompletion_DeclName(
        idAutoComplete* const completion, idDeclInfo* const type) {
    if (completion == nullptr || type == nullptr) return;
    for (int index = 0; index < type->declSources.Num(); ++index)
        Decls_CompleteText(*completion,
            type->declSources[index]->name.c_str());
}

void idDeclManagerLocal::PrintMultiplayerDeclOverrides() const {
    for (int index = 0; index < multiplayerDeclOverrides.Num(); ++index)
        Decls_PrintMultiplayerOverride(multiplayerDeclOverrides[index].c_str());
}

void idDeclManagerLocal::GetLogDeclsList(
        idList<idStr, 5>& declarations) const {
    declarations = registeredDeclLogTypes;
}

void idDeclManagerLocal::ListDecls_f(const idCmdArgs& args) {
    Decls_ExecuteManagerCommand("listDecls", args);
}

void idDeclManagerLocal::TouchDecl_f(const idCmdArgs& args) {
    Decls_ExecuteManagerCommand("touchDecl", args);
}

void idDeclManagerLocal::ReExportDecls_f(const idCmdArgs& args) {
    Decls_ExecuteManagerCommand("reExportDecls", args);
}

void idDeclManagerLocal::MakeDeclTree_f(const idCmdArgs& args) {
    Decls_ExecuteManagerCommand("makeDeclTree", args);
}

void idDeclManagerLocal::ReloadDecls_f(const idCmdArgs& args) {
    Decls_ExecuteManagerCommand("reloadDecls", args);
}

void idDeclManagerLocal::GetDeclTextHeader(idDeclInfo* const type,
        const char* const declarationName, idStr& header) {
    header.Clear();
    if (type == nullptr || declarationName == nullptr) return;
    header = type->name != nullptr ? type->name : "decl";
    header.Append(" ");
    header.Append(declarationName);
    header.Append("\n");
}

void ShowAvailableDeclLogs(idAutoComplete& completion) {
    for (int index = 0;
            index < declManagerLocal.registeredDeclLogTypes.Num(); ++index)
        Decls_CompleteText(completion,
            declManagerLocal.registeredDeclLogTypes[index].c_str());
}
