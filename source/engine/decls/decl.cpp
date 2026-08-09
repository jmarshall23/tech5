#include "decls/decl.h"

#include "idlib/hashing/md5.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"

#include <algorithm>
#include <cstring>

bool Decls_ReadSourceText(const idDeclSource* source, idStr& text);
bool Decls_WriteSourceText(const idDecl& declaration, bool force);
bool Decls_ParseText(idDecl& declaration, const char* text, int length,
    bool force);
unsigned int Decls_GetFileTimestamp(const char* fileName);
bool Decls_DeclFileChanged(const idDeclFile& file, bool updateTimestamp);
int Decls_LoadAndParseFile(idDeclFile& file);
void Decls_PrintDeclaration(const idDecl& declaration, bool listOnly);

idDeclSource::idDeclSource()
    : name()
    , sourceFile(nullptr)
    , sourceLine(0)
    , nextInFile(nullptr)
    , isStatic(false)
    , sourceTextOffset(0)
    , sourceTextLength(0) {
}

const char* idDeclSource::GetFileName() const {
    return sourceFile != nullptr ? sourceFile->fileName.c_str() : "";
}

idDecl::idDecl()
    : idResource()
    , textSource(nullptr)
    , textLength(0)
    , md5Checksum(0)
    , programaticallyDefined(false)
    , declSource(nullptr) {
}

idDecl::~idDecl() {
    if (textSource != nullptr) {
        mem.Free(textSource);
        textSource = nullptr;
    }
}

int idDecl::GetLineNum() const {
    return declSource != nullptr ? declSource->sourceLine : 0;
}

unsigned int idDecl::Size() const {
    return static_cast<unsigned int>(textLength + sizeof(idDecl));
}

bool idDecl::SourceFileExists() const {
    return declSource != nullptr && declSource->sourceFile != nullptr &&
        declSource->sourceFile->fileSize > 0;
}

bool idDecl::EverReloaded() const {
    return declSource != nullptr && declSource->sourceFile != nullptr &&
        declSource->sourceFile->everReloaded;
}

bool idDecl::IsImplicit() const {
    return !programaticallyDefined && declSource == nullptr &&
        std::strstr(name.c_str(), ".decl") == nullptr;
}

const char* idDecl::GetFileName() const {
    return SourceFileExists() ? declSource->GetFileName() : name.c_str();
}

void idDecl::SetText(const char* const text, int length) {
    if (textSource != nullptr) {
        mem.Free(textSource);
        textSource = nullptr;
    }
    textLength = 0;
    md5Checksum = 0;
    if (text == nullptr) return;
    if (length <= 0) length = static_cast<int>(std::strlen(text));
    while (length > 0 && (text[length - 1] == '\n' ||
            text[length - 1] == '\r' || text[length - 1] == ' ')) --length;
    textSource = static_cast<char*>(mem.AllocWithLocation(
        "decl.cpp: declaration text", static_cast<unsigned int>(length + 1),
        TAG_DECLTEXT, false, ALIGN_16));
    if (textSource == nullptr) return;
    std::memcpy(textSource, text, static_cast<std::size_t>(length));
    textSource[length] = '\0';
    textLength = length;
    md5Checksum = MD5_BlockChecksum(textSource,
        static_cast<unsigned int>(textLength));
}

const char* idDecl::GetText() const {
    return textSource != nullptr ? textSource : "";
}

void idDecl::MakeDefault() {
    const char* definition = DefaultDefinition();
    SetText(definition != nullptr ? definition : "{}", 0);
    resourceError = "defaulted";
    FreeData();
    Decls_ParseText(*this, textSource, textLength, true);
    DeleteUnusedText();
}

void idDecl::List() { Decls_PrintDeclaration(*this, true); }
void idDecl::Print() { Decls_PrintDeclaration(*this, false); }

void idDecl::Revert() {
    if (declSource != nullptr) DefineFromSource(declSource);
    ReParse(true);
}

void idDecl::DefineFromSource(idDeclSource* const source) {
    declSource = source;
    if (source == nullptr) return;
    SetName(source->name.c_str());
    idStr text;
    if (Decls_ReadSourceText(source, text))
        SetText(text.c_str(), text.Length());
}

void idDecl::DeleteUnusedText() {
    if (textSource != nullptr) {
        mem.Free(textSource);
        textSource = nullptr;
    }
    textLength = 0;
}

bool idDecl::ReloadIfStale() {
    if (declSource == nullptr || declSource->sourceFile == nullptr)
        return false;
    if (!declSource->sourceFile->SourceFileChanged(false)) return false;
    declSource->sourceFile->everReloaded = true;
    DefineFromSource(declSource);
    ReParse(true);
    return true;
}

unsigned int idDecl::GetDeclTimestamp() const {
    return declSource != nullptr && declSource->sourceFile != nullptr
        ? declSource->sourceFile->timestamp : 0;
}

idDeclInfo* idDecl::GetDeclInfo() const {
    return static_cast<idDeclInfo*>(resourceListPtr);
}

idResourceList* idDecl::GetResourceList() { return GetDeclInfo(); }

bool idDecl::RebuildTextSource() { return textSource != nullptr; }
bool idDecl::SetImplicitText() { return false; }
const char* idDecl::DefaultDefinition() const { return "{}"; }

void idDecl::LogMissingDecl() const {
    idLibPrint::Warning("missing declaration '%s'", name.c_str());
}

void idDecl::Parse(idParser*) {}
void idDecl::FreeData() {}

bool idDecl::ReplaceSourceFileText(const bool force) {
    return RebuildTextSource() && Decls_WriteSourceText(*this, force);
}

void idDecl::ReParse(const bool force) {
    FreeData();
    resourceError = nullptr;
    if (textSource == nullptr ||
            !Decls_ParseText(*this, textSource, textLength, force)) {
        MakeDefault();
    }
    DeleteUnusedText();
}

void idDecl::LoadResource() {
    if (textSource == nullptr && declSource != nullptr)
        DefineFromSource(declSource);
    if (textSource == nullptr) {
        if (SetImplicitText()) {
            programaticallyDefined = true;
        } else {
            LogMissingDecl();
            MakeDefault();
            return;
        }
    }
    ReParse(false);
}

void idDecl::WriteResourceFile() { ReplaceSourceFileText(false); }

idDeclFile::idDeclFile(const char* const newFileName,
        idDeclInfo* const defaultDeclarationType)
    : hadRedefinition(false)
    , fileName(newFileName != nullptr ? newFileName : "")
    , defaultType(defaultDeclarationType)
    , timestamp(0)
    , checksum(0)
    , fileSize(0)
    , numLines(0)
    , everReloaded(false)
    , firstDeclSourceInFile(nullptr)
    , dependencies(0)
    , dependenciesDynamicStartIndex(0)
    , includeFiles(0) {
}

bool idDeclFile::SourceFileChanged(const bool updateTimestamp) const {
    return Decls_DeclFileChanged(*this, updateTimestamp);
}

void idDeclFile::FreeDynamic() {
    dependencies.SetNum((std::max)(0, dependenciesDynamicStartIndex));
    includeFiles.Clear();
    for (idDeclSource* source = firstDeclSourceInFile; source != nullptr;
            source = source->nextInFile) {
        if (!source->isStatic) source->sourceTextLength = 0;
    }
}

void idDeclFile::AddDecl(idDeclInfo* const type,
        const char* const declarationName, const int declarationLine,
        const int sourceOffset, const int sourceLength) {
    if (type == nullptr || declarationName == nullptr) return;
    idDeclSource* source = type->FindDeclSource(declarationName);
    if (source == nullptr) {
        source = new idDeclSource();
        source->name.Set(declarationName);
        type->AddDeclSource(source);
    } else if (source->sourceFile != nullptr && source->sourceFile != this) {
        hadRedefinition = true;
    }
    source->sourceFile = this;
    source->sourceLine = declarationLine;
    source->sourceTextOffset = sourceOffset;
    source->sourceTextLength = sourceLength;
    source->nextInFile = firstDeclSourceInFile;
    firstDeclSourceInFile = source;
}

int idDeclFile::LoadAndParse() { return Decls_LoadAndParseFile(*this); }

idDeclInfo::idDeclInfo(const char* const identifier,
        const char* const className, const char* const extension)
    : idResourceList(identifier)
    , name(identifier)
    , classname(className)
    , fileExtension(extension)
    , nameExtension(extension != nullptr ? extension : "")
    , defaultFolder()
    , parent(nullptr)
    , onReload(nullptr)
    , declSources(0)
    , declSourceHash(1024, 1024, TAG_DECL)
    , declSourceDynamicStartIndex(0) {
}

idDeclInfo::~idDeclInfo() {
    for (int index = 0; index < declSources.Num(); ++index)
        delete declSources[index];
    declSources.ClearFree();
}

idDecl* idDeclInfo::AllocDecl() { return new idDecl(); }
int idDeclInfo::AllocSize() { return sizeof(idDecl); }

idResource* idDeclInfo::Alloc(const char* const resourceName) {
    idDecl* declaration = AllocDecl();
    if (declaration == nullptr) return nullptr;
    declaration->SetName(resourceName);
    declaration->declSource = FindDeclSource(resourceName);
    Add(declaration);
    return declaration;
}

idDeclSource* idDeclInfo::FindDeclSource(
        const char* const declarationName) const {
    if (declarationName == nullptr) return nullptr;
    for (int index = 0; index < declSources.Num(); ++index) {
        if (_stricmp(declSources[index]->name.c_str(), declarationName) == 0)
            return declSources[index];
    }
    return nullptr;
}

const idDecl* idDeclInfo::FindWithInheritance(
        const char* const declarationName, const bool makeDefault) const {
    idDeclInfo* current = const_cast<idDeclInfo*>(this);
    while (current != nullptr) {
        if (idResource* resource = current->FindExisting(declarationName))
            return static_cast<idDecl*>(resource);
        current = current->parent;
    }
    return makeDefault
        ? static_cast<const idDecl*>(const_cast<idDeclInfo*>(this)->Load(
            declarationName, true)) : nullptr;
}

void idDeclInfo::FreeDynamic() {
    for (int index = declSources.Num() - 1;
            index >= declSourceDynamicStartIndex; --index) {
        delete declSources[index];
        declSources.RemoveIndexFast(index);
    }
    declSourceHash.Clear();
    for (int index = 0; index < declSources.Num(); ++index)
        declSourceHash.Add(declSourceHash.GenerateKeyForString(
            declSources[index]->name.c_str(), false), index);
}

void idDeclInfo::AddDeclSource(idDeclSource* const source) {
    if (source == nullptr || FindDeclSource(source->name.c_str()) != nullptr)
        return;
    const int index = declSources.Append(source);
    if (index >= 0)
        declSourceHash.Add(declSourceHash.GenerateKeyForString(
            source->name.c_str(), false), index);
}
