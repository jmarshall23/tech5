#include "decls/decl.h"

#include "idlib/hashing/md5.h"
#include "idlib/hashing/crc32.h"
#include "idlib/lib_print.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/lexer.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cstring>
#include <string>

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

bool Decls_ReadSourceText(const idDeclSource* source, idStr& text) {
    text.Clear();
    if (source == nullptr || source->sourceFile == nullptr
            || fileSystem == nullptr) return false;
    void* buffer = nullptr;
    const int length = fileSystem->ReadFile(
        source->sourceFile->fileName.c_str(), &buffer, nullptr);
    if (buffer == nullptr || length < 0) return false;
    const int offset = (std::max)(0, source->sourceTextOffset);
    const int count = (std::max)(0, (std::min)(source->sourceTextLength,
        length - offset));
    std::string recovered(static_cast<const char*>(buffer) + offset,
        static_cast<std::size_t>(count));
    fileSystem->FreeFile(buffer);
    text = recovered.c_str();
    return true;
}

bool Decls_WriteSourceText(const idDecl& declaration, bool force) {
    if (declaration.declSource == nullptr
            || declaration.declSource->sourceFile == nullptr
            || fileSystem == nullptr) return false;
    idDeclSource* source = declaration.declSource;
    idDeclFile* sourceFile = source->sourceFile;
    void* oldBuffer = nullptr;
    const int oldLength = fileSystem->ReadFile(
        sourceFile->fileName.c_str(), &oldBuffer, nullptr);
    if (oldLength < 0 && !force) return false;
    const int offset = oldLength > 0
        ? (std::max)(0, (std::min)(source->sourceTextOffset, oldLength)) : 0;
    const int oldCount = oldLength > 0
        ? (std::max)(0, (std::min)(source->sourceTextLength,
            oldLength - offset)) : 0;
    std::string output;
    if (oldBuffer != nullptr && offset > 0)
        output.append(static_cast<const char*>(oldBuffer),
            static_cast<std::size_t>(offset));
    output.append(declaration.GetText(),
        static_cast<std::size_t>(declaration.textLength));
    if (oldBuffer != nullptr && offset + oldCount < oldLength)
        output.append(static_cast<const char*>(oldBuffer) + offset + oldCount,
            static_cast<std::size_t>(oldLength - offset - oldCount));
    if (oldBuffer != nullptr) fileSystem->FreeFile(oldBuffer);
    const unsigned int written = fileSystem->WriteFile(
        sourceFile->fileName.c_str(), output.data(),
        static_cast<unsigned int>(output.size()), FSPATH_BASE);
    if (written != output.size()) return false;
    source->sourceTextLength = declaration.textLength;
    sourceFile->fileSize = static_cast<int>(output.size());
    sourceFile->timestamp = fileSystem->GetTimestamp(
        sourceFile->fileName.c_str(), false);
    sourceFile->checksum = CRC32_BlockChecksum(output.data(),
        static_cast<int>(output.size()));
    return true;
}

bool Decls_ParseText(idDecl& declaration, const char* text, int length,
        bool) {
    if (text == nullptr) return false;
    if (length <= 0) length = static_cast<int>(std::strlen(text));
    idParser parser(LEXFL_NOFATALERRORS | LEXFL_NOSTRINGCONCAT
        | LEXFL_ALLOWPATHNAMES);
    if (!parser.LoadMemory(text, length, declaration.GetFileName()))
        return false;
    if (!parser.ExpectTokenString("{")) return false;
    declaration.Parse(&parser);
    return !parser.HadError();
}

unsigned int Decls_GetFileTimestamp(const char* fileName) {
    return fileSystem != nullptr && fileName != nullptr
        ? fileSystem->GetTimestamp(fileName, false) : 0;
}

bool Decls_DeclFileChanged(const idDeclFile& file, bool updateTimestamp) {
    const unsigned int timestamp = Decls_GetFileTimestamp(file.fileName.c_str());
    const bool changed = timestamp != file.timestamp;
    if (updateTimestamp)
        const_cast<idDeclFile&>(file).timestamp = timestamp;
    return changed;
}

int Decls_LoadAndParseFile(idDeclFile& file) {
    if (fileSystem == nullptr || file.fileName.IsEmpty()) return 0;
    void* buffer = nullptr;
    unsigned int timestamp = 0;
    const int length = fileSystem->ReadFile(file.fileName.c_str(), &buffer,
        &timestamp);
    if (buffer == nullptr || length <= 0) return 0;
    file.FreeDynamic();
    file.timestamp = timestamp;
    file.fileSize = length;
    file.checksum = CRC32_BlockChecksum(buffer, length);
    file.numLines = 1;

    idLexer lexer(LEXFL_NOFATALERRORS | LEXFL_NOSTRINGCONCAT
        | LEXFL_ALLOWPATHNAMES);
    if (!lexer.LoadMemory(static_cast<const char*>(buffer),
            static_cast<unsigned int>(length), file.fileName.c_str())) {
        fileSystem->FreeFile(buffer);
        return 0;
    }

    int declarations = 0;
    idToken token;
    while (lexer.ReadToken(token)) {
        idDeclInfo* type = file.defaultType;
        idStr declarationName;
        const int sourceLine = token.line;
        const int sourceOffset = token.whiteSpaceStart_p != nullptr
            ? static_cast<int>(token.whiteSpaceStart_p
                - static_cast<const char*>(buffer))
            : lexer.GetFileOffset() - token.Length();

        if (idStr::Cmp(token.c_str(), "{") == 0) {
            declarationName = file.fileName.c_str();
            declarationName.StripFileExtension();
            if (type == nullptr || !lexer.SkipBracedSection(false)) break;
        } else {
            idResourceList* list = idResourceList::ForTypeName(token.c_str());
            if (list != nullptr) type = static_cast<idDeclInfo*>(list);
            else if (type != nullptr) declarationName = token.c_str();
            if (declarationName.IsEmpty() && !lexer.ReadToken(token)) break;
            if (declarationName.IsEmpty()) declarationName = token.c_str();
            if (!lexer.ExpectTokenString("{")) break;
            if (!lexer.SkipBracedSection(false)) break;
        }
        const int sourceEnd = lexer.GetFileOffset();
        file.AddDecl(type, declarationName.c_str(), sourceLine,
            sourceOffset, sourceEnd - sourceOffset);
        ++declarations;
        file.numLines = lexer.GetLineNum();
    }
    fileSystem->FreeFile(buffer);
    return declarations;
}

void Decls_PrintDeclaration(const idDecl& declaration, bool listOnly) {
    if (listOnly) {
        idLibPrint::Printf("%s\n", declaration.GetName());
        return;
    }
    idLibPrint::Printf("%s (%s:%d)\n%s\n", declaration.GetName(),
        declaration.GetFileName(), declaration.GetLineNum(),
        declaration.GetText());
}
