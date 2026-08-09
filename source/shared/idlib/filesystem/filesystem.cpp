#include "filesystem.h"

#include "file_inzip.h"
#include "file_mtp.h"
#include "file_nfs.h"
#include "file_permanent.h"
#include "../lib_print.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace {

bool PrefixNoCase(const char* text, const char* prefix) {
    if (text == nullptr || prefix == nullptr) return false;
    return _strnicmp(text, prefix, std::strlen(prefix)) == 0;
}

bool EqualNoCase(const char* left, const char* right) {
    return _stricmp(left == nullptr ? "" : left,
        right == nullptr ? "" : right) == 0;
}

bool IsOSPathRecovered(const char* path) {
    if (path == nullptr || path[0] == '\0') return false;
    static const char* const prefixes[] = {
        "mtp:", "nfs:", "devkit:", "game:", "cache:", "dlc:", "saves:"
    };
    for (const char* prefix : prefixes) {
        if (PrefixNoCase(path, prefix)) return true;
    }
    return ((std::isalpha(static_cast<unsigned char>(path[0])) != 0)
            && path[1] == ':')
        || path[0] == '\\' || path[0] == '/';
}

bool IsNativeOSPath(const char* path) {
    return IsOSPathRecovered(path)
        && !PrefixNoCase(path, "mtp:") && !PrefixNoCase(path, "nfs:");
}

std::string SlashesToWindows(std::string path) {
    std::replace(path.begin(), path.end(), '/', '\\');
    return path;
}

std::string SlashesToGame(std::string path) {
    std::replace(path.begin(), path.end(), '\\', '/');
    return path;
}

std::string JoinPath(const char* base, const char* relativePath) {
    const char* relative = relativePath == nullptr ? "" : relativePath;
    if (IsOSPathRecovered(relative)) return SlashesToWindows(relative);

    std::string result = base == nullptr ? "" : base;
    if (!result.empty() && result.back() != '\\' && result.back() != '/')
        result.push_back('\\');
    while (*relative == '\\' || *relative == '/') ++relative;
    result += relative;
    result = SlashesToWindows(result);

    if (IsNativeOSPath(result.c_str())) {
        char fullPath[32768] = {};
        const DWORD amount = GetFullPathNameA(result.c_str(),
            static_cast<DWORD>(sizeof(fullPath)), fullPath, nullptr);
        if (amount > 0 && amount < sizeof(fullPath)) result.assign(fullPath);
    }
    return result;
}

std::string ParentPath(const std::string& path) {
    const std::size_t separator = path.find_last_of("\\/");
    if (separator == std::string::npos) return std::string();
    if (separator == 2 && path.size() >= 3 && path[1] == ':')
        return path.substr(0, 3);
    return path.substr(0, separator);
}

void CopyString(char* destination, const int destinationSize,
        const char* source) {
    if (destination == nullptr || destinationSize <= 0) return;
    _snprintf_s(destination, static_cast<std::size_t>(destinationSize),
        _TRUNCATE, "%s", source == nullptr ? "" : source);
}

std::string ExecutableDirectory() {
    char path[32768] = {};
    const DWORD amount = GetModuleFileNameA(nullptr, path,
        static_cast<DWORD>(sizeof(path)));
    if (amount == 0 || amount >= sizeof(path)) return ".";
    return ParentPath(path);
}

std::string EnvironmentPath(const char* name) {
    char value[32768] = {};
    const DWORD amount = GetEnvironmentVariableA(name, value,
        static_cast<DWORD>(sizeof(value)));
    return amount > 0 && amount < sizeof(value) ? value : "";
}

unsigned int NativeTimestamp(const char* path) {
    WIN32_FILE_ATTRIBUTE_DATA attributes = {};
    if (!GetFileAttributesExA(path, GetFileExInfoStandard, &attributes))
        return static_cast<unsigned int>(-1);
    ULARGE_INTEGER value = {};
    value.LowPart = attributes.ftLastWriteTime.dwLowDateTime;
    value.HighPart = attributes.ftLastWriteTime.dwHighDateTime;
    const std::uint64_t ticks = value.QuadPart > 116444736000000000ULL
        ? value.QuadPart - 116444736000000000ULL : 0;
    return static_cast<unsigned int>(ticks / 10000000ULL);
}

bool IsDirectoryNative(const char* path) {
    const DWORD attributes = GetFileAttributesA(path);
    return attributes != INVALID_FILE_ATTRIBUTES
        && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

bool ExtensionMatches(const char* name, const char* extension) {
    if (extension == nullptr || extension[0] == '\0') return true;
    const char* wanted = extension;
    while (*wanted == '*' || *wanted == '.') ++wanted;
    const char* actual = std::strrchr(name, '.');
    if (actual == nullptr) return false;
    return EqualNoCase(actual + 1, wanted);
}

std::string WithExtension(std::string path, const char* extension) {
    const std::size_t separator = path.find_last_of("\\/");
    const std::size_t dot = path.find_last_of('.');
    if (dot != std::string::npos
        && (separator == std::string::npos || dot > separator)) {
        path.erase(dot);
    }
    if (extension != nullptr && extension[0] != '\0') {
        if (extension[0] != '.') path.push_back('.');
        path += extension;
    }
    return path;
}

const char* StripRecoveredBasePrefix(const char* path) {
    if (path == nullptr) return "";
    if (PrefixNoCase(path, "base/") || PrefixNoCase(path, "base\\"))
        return path + 5;
    if ((path[0] == '/' || path[0] == '\\')
        && (PrefixNoCase(path + 1, "base/")
            || PrefixNoCase(path + 1, "base\\"))) {
        return path + 6;
    }
    while ((path[0] == '/' && path[1] != '/')
        || (path[0] == '\\' && path[1] != '\\')) ++path;
    return path;
}

void ListNativeFiles(const char* directory, const char* extension,
        idList<idStr>& list) {
    const std::string search = JoinPath(directory, "*");
    WIN32_FIND_DATAA findData = {};
    HANDLE handle = FindFirstFileA(search.c_str(), &findData);
    if (handle == INVALID_HANDLE_VALUE) return;
    const bool wantDirectories = extension != nullptr
        && extension[0] == '/' && extension[1] == '\0';
    do {
        const bool isDirectory =
            (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
        if (wantDirectories != isDirectory) continue;
        if (!wantDirectories && !ExtensionMatches(findData.cFileName, extension))
            continue;
        list.Append(idStr(findData.cFileName));
    } while (FindNextFileA(handle, &findData));
    FindClose(handle);
}

} // namespace

idFileSystemLocal fileSystemLocal;
idFileSystem* fileSystem = &fileSystemLocal;

idFileSystem::~idFileSystem() = default;

idFileList::idFileList() : basePath(), list(16) {}

idCachedZipFile::idCachedZipFile()
    : zipFileName(), relativeZipFileName(), handle(nullptr), numFiles(0),
      fileList(nullptr), next(nullptr) {
    std::memset(hashTable, 0, sizeof(hashTable));
}

idCachedZipFile::~idCachedZipFile() {
    delete[] fileList;
    fileList = nullptr;
    handle = nullptr;
}

unsigned int idFile_Stat::Read(void*, unsigned int) {
    idLibPrint::Error("Read is not allowed with idFile_Stat");
}

unsigned int idFile_Stat::Write(const void*, unsigned int) {
    idLibPrint::Error("Write is not allowed with idFile_Stat");
}

unsigned int idFile_Stat::ReadOfs(std::int64_t, void*, unsigned int) {
    idLibPrint::Error("ReadOfs is not allowed with idFile_Stat");
}

unsigned int idFile_Stat::WriteOfs(std::int64_t, const void*, unsigned int) {
    idLibPrint::Error("WriteOfs is not allowed with idFile_Stat");
}

void idFile_Stat::SetLength(unsigned int) {
    idLibPrint::Error("SetLength is not allowed with idFile_Stat");
}

int idFile_Stat::Seek(std::int64_t, fsOrigin_t) {
    idLibPrint::Error("Seeking is not allowed with idFile_Stat");
}

idFileSystemLocal::idFileSystemLocal()
    : searchPaths(16), cachedZipFiles(nullptr), loadCount(0), loadStack(0),
      pathBase(), pathCache(), pathInstall(), pathSave(), preCallback(nullptr),
      postCallback(nullptr), cacheStatCallback(nullptr), cacheCallback(nullptr),
      patchCallback(nullptr) {}

idFileSystemLocal::~idFileSystemLocal() {
    ClearZipCache();
}

bool idFileSystemLocal::CopyGameFile(idFile* source, idFile* destination) {
    if (source == nullptr || destination == nullptr) return false;
    unsigned char buffer[4096];
    std::int64_t total = 0;
    for (;;) {
        const unsigned int amount = source->Read(buffer, sizeof(buffer));
        if (amount == 0) break;
        if (destination->Write(buffer, amount) != amount) {
            idLibPrint::Warning("Write didn't match requested size");
            return false;
        }
        total += amount;
    }
    source->Seek(0, FS_SEEK_SET);
    if (total != source->Length())
        idLibPrint::Warning("Total bytes written doesn't match filesize");
    return total == source->Length();
}

int idFileSystemLocal::ReadFile(const char* relativePath, void** buffer,
        unsigned int* timestamp) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (relativePath == nullptr || relativePath[0] == '\0') {
        idLibPrint::Warning("idFileSystemLocal::ReadFile with empty name");
        return -1;
    }
    if (timestamp != nullptr) *timestamp = static_cast<unsigned int>(-1);
    if (buffer != nullptr) *buffer = nullptr;
    idFileLocal file(OpenFileRead(relativePath, buffer != nullptr, false));
    if (file.file == nullptr) return -1;
    const std::int64_t fileLength = file->Length();
    if (fileLength < 0 || fileLength > INT_MAX) return -1;
    const int length = static_cast<int>(fileLength);
    if (timestamp != nullptr) *timestamp = file->Timestamp();
    if (buffer != nullptr) {
        ++loadCount;
        ++loadStack;
        unsigned char* data = static_cast<unsigned char*>(
            std::malloc(static_cast<std::size_t>(length) + 1));
        if (data == nullptr) {
            --loadStack;
            return -1;
        }
        const unsigned int amount = file->Read(data,
            static_cast<unsigned int>(length));
        if (amount != static_cast<unsigned int>(length)) {
            std::free(data);
            --loadStack;
            return -1;
        }
        data[length] = 0;
        *buffer = data;
    }
    return length;
}

void idFileSystemLocal::FreeFile(void* buffer) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (buffer == nullptr)
        idLibPrint::FatalError("idFileSystemLocal::FreeFile( NULL )");
    --loadStack;
    std::free(buffer);
}

const char* idFileSystemLocal::GetBasePathStr(const fsPath_t basePath) const {
    switch (basePath) {
        case FSPATH_BASE: return pathBase.c_str();
        case FSPATH_CACHE:
            if (pathCache.Length() > 0) return pathCache.c_str();
            // Recovered code deliberately falls through to the save path.
        case FSPATH_SAVE:
            return pathSave.Length() > 0 ? pathSave.c_str() : pathBase.c_str();
        case FSPATH_INSTALL: return pathInstall.c_str();
        default: return "";
    }
}

void idFileSystemLocal::GetNumberedFilename(int& lastNumber,
        const char* base, const char* extension, idStr& outputFilename,
        const bool overrideProduction) {
    if (++lastNumber > 99999) lastNumber = 99999;
    while (lastNumber < 99999) {
        outputFilename.Format("%s%05i.%s", base == nullptr ? "" : base,
            lastNumber, extension == nullptr ? "" : extension);
        if (!FileExists(outputFilename.c_str(), overrideProduction)) break;
        ++lastNumber;
    }
}

bool idFileSystemLocal::IsInitialized() const {
    return searchPaths.Num() > 0;
}

idFile* idFileSystemLocal::OpenFromMTP(const char* path, fsMode_t mode) {
    idFile_MTP* file = new idFile_MTP();
    const char* remotePath = PrefixNoCase(path, "mtp:") ? path + 4 : path;
    if (file->Open(remotePath, mode)) return file;
    delete file;
    return nullptr;
}

idFile* idFileSystemLocal::OpenFromNFS(const char* path, fsMode_t mode,
        bool create) {
    idFile_Nfs* file = new idFile_Nfs();
    if (file->Open(path, mode, create, create)) return file;
    delete file;
    return nullptr;
}

bool idFileSystemLocal::IsRelativePath(const char* path) const {
    return !IsOSPathRecovered(path);
}

void idFileSystemLocal::CreateOSPath(const char* osPath) {
    if (osPath == nullptr || osPath[0] == '\0') return;
    if (PrefixNoCase(osPath, "nfs:")) {
        idFile_Nfs::CreateOsPath(osPath);
        return;
    }
    if (!IsNativeOSPath(osPath)) return;
    std::string path = SlashesToWindows(osPath);
    for (std::size_t index = 1; index < path.size(); ++index) {
        if (path[index] != '\\') continue;
        if (index == 2 && path[1] == ':') continue;
        if (index == 1 && path[0] == '\\') continue;
        const char saved = path[index];
        path[index] = '\0';
        if (path[0] != '\0') CreateDirectoryA(path.c_str(), nullptr);
        path[index] = saved;
    }
}

idStr idFileSystemLocal::BuildOSPath(const char* base,
        const char* relativePath) const {
    return idStr(JoinPath(base, relativePath).c_str());
}

idStr idFileSystemLocal::BuildOSPath(const fsPath_t basePath,
        const char* relativePath) const {
    const std::string gameRoot = JoinPath(GetBasePathStr(basePath), "base");
    return idStr(JoinPath(gameRoot.c_str(), relativePath).c_str());
}

idStr idFileSystemLocal::GeneratedPath(const char* appendedPath) const {
    const std::string generated = JoinPath("generated", appendedPath);
    return idStr(SlashesToGame(generated).c_str());
}

bool idFileSystemLocal::FixLongFilename(const char* basePath,
        const char* extension, const char* inputPath, char* fixedPath,
        const int fixedPathSize) const {
    if (fixedPath == nullptr || fixedPathSize <= 0) return false;
    const char* relative = inputPath == nullptr ? "" : inputPath;
    if (PrefixNoCase(relative, "../../")) relative += 6;

    std::string input = WithExtension(SlashesToGame(relative), extension);
    const std::size_t slash = input.find_last_of('/');
    const std::string directory = slash == std::string::npos
        ? "" : input.substr(0, slash + 1);
    std::string filename = slash == std::string::npos
        ? input : input.substr(slash + 1);
    const std::size_t dot = filename.find_last_of('.');
    const std::string suffix = dot == std::string::npos
        ? "" : filename.substr(dot);
    std::string stem = dot == std::string::npos
        ? filename : filename.substr(0, dot);

    std::string recoveredPath = directory;
    if (filename.size() >= 38) {
        while (stem.size() > 30) {
            recoveredPath += stem.substr(0, 30);
            recoveredPath.push_back('/');
            stem.erase(0, 30);
        }
    }
    recoveredPath += stem + suffix;
    const std::string result = JoinPath(basePath, recoveredPath.c_str());
    CopyString(fixedPath, fixedPathSize, result.c_str());
    return true;
}

bool idFileSystemLocal::OSPathToRelativePath(const char* osPath,
        char* relativePath, const int relativePathSize) {
    if (relativePath == nullptr || relativePathSize <= 0) return false;
    relativePath[0] = '\0';
    if (osPath == nullptr) return false;
    for (int index = 0; index < searchPaths.Num(); ++index) {
        const std::string root = SlashesToWindows(searchPaths[index].c_str());
        const std::string candidate = SlashesToWindows(osPath);
        if (_strnicmp(root.c_str(), candidate.c_str(), root.size()) != 0)
            continue;
        const char* suffix = candidate.c_str() + root.size();
        while (*suffix == '\\' || *suffix == '/') ++suffix;
        const std::string gamePath = SlashesToGame(suffix);
        CopyString(relativePath, relativePathSize, gamePath.c_str());
        return true;
    }
    idLibPrint::Warning("idFileSystem::OSPathToRelativePath failed on %s",
        osPath);
    return false;
}

void idFileSystemLocal::RelativePathToOSPath(const char* relativePath,
        char* osPath, const int osPathSize, const fsPath_t basePath) const {
    const idStr result = BuildOSPath(basePath, relativePath);
    CopyString(osPath, osPathSize, result.c_str());
}

idStr idFileSystemLocal::RelativePathToOSPath(const char* relativePath,
        const fsPath_t basePath) const {
    return BuildOSPath(basePath, relativePath);
}

bool idFileSystemLocal::RemoveDir(const char* relativePath) {
    bool result = true;
    if (pathSave.Length() > 0) {
        const idStr savePath = BuildOSPath(FSPATH_SAVE, relativePath);
        result = PrefixNoCase(savePath.c_str(), "nfs:")
            ? idFile_Nfs::RemoveFile(savePath.c_str())
            : RemoveDirectoryA(savePath.c_str()) != FALSE;
    }
    const idStr basePath = BuildOSPath(FSPATH_BASE, relativePath);
    const bool baseResult = PrefixNoCase(basePath.c_str(), "nfs:")
        ? idFile_Nfs::RemoveFile(basePath.c_str())
        : RemoveDirectoryA(basePath.c_str()) != FALSE;
    return result && baseResult;
}

bool idFileSystemLocal::RenameFile(const char* relativePath,
        const char* newName, const fsPath_t basePath) {
    const idStr oldPath = BuildOSPath(basePath, relativePath);
    const idStr newPath = BuildOSPath(basePath, newName);
    if (PrefixNoCase(relativePath, "nfs:"))
        return idFile_Nfs::RenameFile(oldPath.c_str(), newPath.c_str());
    if (MoveFileExA(oldPath.c_str(), newPath.c_str(),
            MOVEFILE_REPLACE_EXISTING) != FALSE) return true;
    idLibPrint::Warning("RenameFile( %s, %s ) error %lu", newPath.c_str(),
        oldPath.c_str(), GetLastError());
    return false;
}

bool idFileSystemLocal::IsWritable(const char* relativePath) const {
    const idStr path = BuildOSPath(FSPATH_BASE, relativePath);
    const DWORD attributes = GetFileAttributesA(path.c_str());
    if (attributes != INVALID_FILE_ATTRIBUTES)
        return (attributes & FILE_ATTRIBUTE_READONLY) == 0;
    const std::string parent = ParentPath(path.c_str());
    const DWORD parentAttributes = GetFileAttributesA(parent.c_str());
    return parentAttributes != INVALID_FILE_ATTRIBUTES
        && (parentAttributes & FILE_ATTRIBUTE_READONLY) == 0;
}

sysFolder_t idFileSystemLocal::IsFolder(const char* relativePath,
        const fsPath_t basePath) const {
    const idStr path = BuildOSPath(basePath, relativePath);
    const DWORD attributes = GetFileAttributesA(path.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) return FOLDER_ERROR;
    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0
        ? FOLDER_YES : FOLDER_NO;
}

void idFileSystemLocal::ListOSFiles(const char* directory,
        const char* extension, idList<idStr>& list) {
    const char* const filter = extension == nullptr ? "" : extension;
    if (PrefixNoCase(directory, "nfs:")) {
        idFile_Nfs::ListFiles(directory, filter, list);
    } else if (PrefixNoCase(directory, "mtp:")) {
        idFile_MTP file;
        file.List(directory, filter, list);
    } else {
        ListNativeFiles(directory, filter, list);
    }
}

idCachedZipFile* idFileSystemLocal::LoadZipFile(const char*, const char*) {
    // The recovered implementation is activated with recovered unzip.cpp.
    return nullptr;
}

std::int64_t idFileSystemLocal::GetFileLength(const char* relativePath) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization");
    if (relativePath == nullptr || relativePath[0] == '\0') {
        idLibPrint::Warning("idFileSystemLocal::GetFileLength with empty name");
        return -1;
    }
    idFileLocal file(OpenFileRead(relativePath, false, false));
    return file.file == nullptr ? -1 : file->Length();
}

idFile* idFileSystemLocal::OpenFileAppend(const char* relativePath,
        const fsPath_t basePath) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    const idStr osPath = BuildOSPath(basePath, relativePath);
    if (PrefixNoCase(osPath.c_str(), "nfs:"))
        return OpenFromNFS(osPath.c_str(), FS_APPEND, true);
    if (PrefixNoCase(osPath.c_str(), "mtp:"))
        return OpenFromMTP(osPath.c_str(), FS_APPEND);
    CreateOSPath(osPath.c_str());
    idFile_Permanent* file = new idFile_Permanent(relativePath,
        osPath.c_str(), FS_APPEND, false);
    if (file->IsOpen()) return file;
    delete file;
    return nullptr;
}

void idFileSystemLocal::SetFilePreCallback(filePreCallback_t callback) {
    preCallback = callback;
}

void idFileSystemLocal::SetFilePostCallback(filePostCallback_t callback) {
    postCallback = callback;
}

void idFileSystemLocal::SetFileCacheCallback(fileCacheCallback_t statCallback,
        fileCacheCallback_t callback) {
    cacheStatCallback = statCallback;
    cacheCallback = callback;
}

void idFileSystemLocal::SetFilePatchCallback(filePatchCallback_t callback) {
    patchCallback = callback;
}

bool idFileSystemLocal::CopyGameFile(const char* from, const char* to,
        const fsPath_t basePath) {
    idFileLocal source(OpenFileRead(from, false, false));
    idFileLocal destination(OpenFileWritePermanent(to, basePath));
    return source.file != nullptr && destination.file != nullptr
        && CopyGameFile(source.file, destination.file);
}

idFile_InZip* idFileSystemLocal::ReadFileFromZip(idCachedZipFile*,
        const char*, bool) {
    // The recovered implementation is activated with recovered file_inzip.cpp.
    return nullptr;
}

idFile* idFileSystemLocal::OpenFileRead(const char* relativePath,
        const bool allowCopyFiles, const bool uncompressedOnly) {
    if (patchCallback != nullptr) {
        idFile* patched = patchCallback(relativePath);
        if (patched != nullptr) return patched;
    }
    if (preCallback != nullptr && allowCopyFiles) {
        idFile* preOpened = preCallback(relativePath);
        const std::size_t length = relativePath == nullptr
            ? 0 : std::strlen(relativePath);
        const bool loadout = length >= 8
            && EqualNoCase(relativePath + length - 8, ".loadout");
        if (preOpened != nullptr || !loadout) return preOpened;
    }
    if (cacheCallback != nullptr && allowCopyFiles) {
        idFile* cached = cacheCallback(relativePath);
        if (cached != nullptr) return cached;
    } else if (cacheStatCallback != nullptr && !allowCopyFiles) {
        idFile* stat = cacheStatCallback(relativePath);
        if (stat != nullptr) return stat;
    }
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (relativePath == nullptr)
        idLibPrint::FatalError(
            "idFileSystemLocal::OpenFileRead: NULL 'relativePath' parameter passed\n");

    const char* path = StripRecoveredBasePrefix(relativePath);
    if (path[0] == '\0') return nullptr;
    idFile* result = nullptr;
    idStr foundPath;
    for (int index = 0; index < searchPaths.Num() && result == nullptr;
            ++index) {
        const idStr osPath = BuildOSPath(searchPaths[index].c_str(), path);
        if (PrefixNoCase(osPath.c_str(), "mtp:")) {
            result = OpenFromMTP(osPath.c_str(),
                uncompressedOnly ? FS_READ_NO_BUFFERING : FS_READ);
        } else if (PrefixNoCase(osPath.c_str(), "nfs:")) {
            result = OpenFromNFS(osPath.c_str(), FS_READ, false);
        } else {
            idFile_Permanent* permanent = new idFile_Permanent(path,
                osPath.c_str(),
                uncompressedOnly ? FS_READ_NO_BUFFERING : FS_READ, false);
            if (permanent->IsOpen()) result = permanent;
            else delete permanent;
        }
        if (result != nullptr) foundPath = osPath;
    }

    // Recovered arbitrary-zip lookup remains tied to the pending unzip port.
    if (result != nullptr && postCallback != nullptr)
        postCallback(foundPath.c_str(), result);
    return result;
}

int idFileSystemLocal::AddUnique(const char* name, idList<idStr>& list,
        idHashIndex& hash) const {
    const int key = hash.GenerateKeyForString(name, false);
    for (int index = hash.First(key); index >= 0; index = hash.Next(index)) {
        if (EqualNoCase(list[index].c_str(), name)) return index;
    }
    const int index = list.Append(idStr(name));
    if (index >= 0) hash.Add(key, index);
    return index;
}

void idFileSystemLocal::GetExtensionList(const char* extensions,
        idList<idStr>& extensionList) const {
    const char* cursor = extensions == nullptr ? "" : extensions;
    for (;;) {
        const char* separator = std::strchr(cursor, '|');
        const std::size_t amount = separator == nullptr
            ? std::strlen(cursor) : static_cast<std::size_t>(separator - cursor);
        std::string extension(cursor, amount);
        extensionList.Append(idStr(extension.c_str()));
        if (separator == nullptr) break;
        cursor = separator + 1;
    }
}

int idFileSystemLocal::GetFileList(const char* relativePath,
        const idList<idStr>& extensions, idList<idStr>& list,
        idHashIndex& hash, const bool fullRelativePath) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (relativePath == nullptr || extensions.Num() == 0) return 0;
    for (int pathIndex = 0; pathIndex < searchPaths.Num(); ++pathIndex) {
        const idStr directory = BuildOSPath(searchPaths[pathIndex].c_str(),
            relativePath);
        for (int extensionIndex = 0; extensionIndex < extensions.Num();
                ++extensionIndex) {
            idList<idStr> found;
            ListOSFiles(directory.c_str(), extensions[extensionIndex].c_str(),
                found);
            for (int fileIndex = 0; fileIndex < found.Num(); ++fileIndex) {
                if (EqualNoCase(found[fileIndex].c_str(), ".")
                    || EqualNoCase(found[fileIndex].c_str(), "..")) continue;
                if (fullRelativePath && relativePath[0] != '\0') {
                    std::string full = SlashesToGame(relativePath);
                    if (!full.empty() && full.back() != '/') full.push_back('/');
                    full += found[fileIndex].c_str();
                    AddUnique(full.c_str(), list, hash);
                } else {
                    AddUnique(found[fileIndex].c_str(), list, hash);
                }
            }
        }
    }
    return list.Num();
}

idFileList* idFileSystemLocal::ListFiles(const char* relativePath,
        const char* extension, const bool sort, const bool fullRelativePath) {
    idFileList* result = new idFileList();
    result->basePath = relativePath;
    idList<idStr> extensions;
    GetExtensionList(extension, extensions);
    idHashIndex hash(4096, 4096, TAG_HASHINDEX);
    GetFileList(relativePath, extensions, result->list, hash,
        fullRelativePath);
    if (sort && result->list.Num() > 1)
        std::sort(result->list.Ptr(), result->list.Ptr() + result->list.Num());
    return result;
}

int idFileSystemLocal::GetFileListTree(const char* relativePath,
        const idList<idStr>& extensions, idList<idStr>& list,
        idHashIndex& hash) {
    idList<idStr> directoryExtension;
    directoryExtension.Append(idStr("/"));
    idList<idStr> directories;
    idHashIndex directoryHash(1024, 128, TAG_HASHINDEX);
    GetFileList(relativePath, directoryExtension, directories, directoryHash,
        true);
    for (int index = 0; index < directories.Num(); ++index) {
        const char* directory = directories[index].c_str();
        const char* leaf = std::strrchr(directory, '/');
        leaf = leaf == nullptr ? directory : leaf + 1;
        if (leaf[0] != '.' && !EqualNoCase(directory, relativePath))
            GetFileListTree(directory, extensions, list, hash);
    }
    return GetFileList(relativePath, extensions, list, hash, true);
}

idFileList* idFileSystemLocal::ListFilesTree(const char* relativePath,
        const char* extension, const bool sort) {
    idFileList* result = new idFileList();
    result->basePath = relativePath;
    idList<idStr> extensions;
    GetExtensionList(extension, extensions);
    idHashIndex hash(4096, 4096, TAG_HASHINDEX);
    GetFileListTree(relativePath, extensions, result->list, hash);
    if (sort && result->list.Num() > 1)
        std::sort(result->list.Ptr(), result->list.Ptr() + result->list.Num());
    return result;
}

void idFileSystemLocal::AddGameDirectory(const char* rootPath,
        const char* gameFolder) {
    std::string path = SlashesToGame(JoinPath(rootPath, gameFolder));
    if (!path.empty() && path.back() != '/') path.push_back('/');
    const idStr value(path.c_str());
    if (searchPaths.FindIndex(value) < 0) searchPaths.Insert(value, 0);
}

void idFileSystemLocal::ReInit(const char* basePath) {
    pathBase = basePath;
    searchPaths.ClearFree();
    AddGameDirectory(pathBase.c_str(), "base");
}

void idFileSystemLocal::ClearZipCache() {
    while (cachedZipFiles != nullptr) {
        idCachedZipFile* next = cachedZipFiles->next;
        delete cachedZipFiles;
        cachedZipFiles = next;
    }
}

void idFileSystemLocal::FreeFileList(idFileList* fileList) {
    delete fileList;
}

void idFileSystemLocal::Init() {
    pathBase = EnvironmentPath("TECH5_BASE_PATH").c_str();
    pathCache = EnvironmentPath("TECH5_CACHE_PATH").c_str();
    pathSave = EnvironmentPath("TECH5_SAVE_PATH").c_str();
    pathInstall = EnvironmentPath("TECH5_INSTALL_PATH").c_str();
    if (pathBase.Length() == 0) pathBase = ExecutableDirectory().c_str();
    if (pathInstall.Length() == 0) pathInstall = pathBase;
    searchPaths.ClearFree();
    AddGameDirectory(pathBase.c_str(), "base");
    if (pathSave.Length() > 0) AddGameDirectory(pathSave.c_str(), "base");
    if (pathInstall.Length() > 0)
        AddGameDirectory(pathInstall.c_str(), "base");
}

bool idFileSystemLocal::RemoveFile(const char* relativePath,
        const fsPath_t basePath) {
    const idStr path = BuildOSPath(basePath, relativePath);
    if (PrefixNoCase(path.c_str(), "nfs:"))
        return idFile_Nfs::RemoveFile(path.c_str());
    DWORD attributes = GetFileAttributesA(path.c_str());
    if (attributes != INVALID_FILE_ATTRIBUTES
        && (attributes & FILE_ATTRIBUTE_READONLY) != 0) {
        SetFileAttributesA(path.c_str(), attributes & ~FILE_ATTRIBUTE_READONLY);
    }
    return DeleteFileA(path.c_str()) != FALSE;
}

bool idFileSystemLocal::FileExists(const char* relativePath,
        const bool allowCopyFiles) {
    return GetTimestamp(relativePath, allowCopyFiles)
        != static_cast<unsigned int>(-1);
}

unsigned int idFileSystemLocal::GetTimestamp(const char* relativePath,
        const bool allowCopyFiles) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (relativePath == nullptr || relativePath[0] == '\0')
        idLibPrint::FatalError(
            "idFileSystemLocal::GetTimestamp with empty name\n");
    idFileLocal file(OpenFileRead(relativePath, allowCopyFiles, false));
    return file.file == nullptr ? static_cast<unsigned int>(-1)
        : file->Timestamp();
}

bool idFileSystemLocal::PreOpenFileWrite(const char* relativePath,
        fsPath_t& basePath, idStr& osPath) const {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    if (relativePath == nullptr || relativePath[0] == '\0') return false;
    if (PrefixNoCase(relativePath, "generated")) basePath = FSPATH_SAVE;
    osPath = BuildOSPath(basePath, relativePath);
    return true;
}

idFile* idFileSystemLocal::OpenFileWritePermanent(const char* relativePath,
        fsPath_t basePath) {
    idStr osPath;
    if (!PreOpenFileWrite(relativePath, basePath, osPath)) return nullptr;
    if (PrefixNoCase(osPath.c_str(), "mtp:"))
        return OpenFromMTP(osPath.c_str(), FS_WRITE);
    if (PrefixNoCase(osPath.c_str(), "nfs:"))
        return OpenFromNFS(osPath.c_str(), FS_WRITE, true);
    CreateOSPath(osPath.c_str());
    idFile_Permanent* file = new idFile_Permanent(relativePath,
        osPath.c_str(), FS_WRITE, false);
    if (file->IsOpen()) return file;
    delete file;
    return nullptr;
}

idFile* idFileSystemLocal::OpenFileReadWrite(const char* relativePath,
        const bool create, const fsPath_t basePath) {
    if (!IsInitialized())
        idLibPrint::FatalError("Filesystem call made without initialization\n");
    const idStr osPath = BuildOSPath(basePath, relativePath);
    if (PrefixNoCase(osPath.c_str(), "mtp:"))
        return OpenFromMTP(osPath.c_str(), FS_READ_WRITE);
    if (PrefixNoCase(osPath.c_str(), "nfs:"))
        return OpenFromNFS(osPath.c_str(), FS_READ_WRITE, create);
    CreateOSPath(osPath.c_str());
    idFile_Permanent* file = new idFile_Permanent(relativePath,
        osPath.c_str(), FS_READ_WRITE, create);
    if (file->IsOpen()) return file;
    delete file;
    return nullptr;
}

idFile* idFileSystemLocal::OpenFileWrite(const char* relativePath,
        const fsPath_t basePath) {
    // Atomic buffering is restored with the remaining recovered file.cpp body.
    return OpenFileWritePermanent(relativePath, basePath);
}

unsigned int idFileSystemLocal::WriteFile(const char* relativePath,
        const void* buffer, const unsigned int length,
        const fsPath_t basePath) {
    idFileLocal file(OpenFileWrite(relativePath, basePath));
    if (file.file == nullptr)
        idLibPrint::Error("Failed to open %s\n", relativePath);
    return file->Write(buffer, length);
}

void idFileSystemLocal::Copy_f(const idCmdArgs& args) {
    if (args.Argc() == 3)
        fileSystemLocal.CopyGameFile(args.Argv(1), args.Argv(2), FSPATH_BASE);
}

void idFileSystemLocal::Dir_f(const idCmdArgs& args) {
    const char* path = args.Argc() > 1 ? args.Argv(1) : "";
    const char* extension = args.Argc() > 2 ? args.Argv(2) : "";
    idFileList* files = fileSystemLocal.ListFiles(path, extension, true, false);
    for (int index = 0; index < files->GetNumFiles(); ++index)
        idLibPrint::Printf("%s\n", files->GetFile(index));
    fileSystemLocal.FreeFileList(files);
}

void idFileSystemLocal::DirTree_f(const idCmdArgs& args) {
    const char* path = args.Argc() > 1 ? args.Argv(1) : "";
    const char* extension = args.Argc() > 2 ? args.Argv(2) : "";
    idFileList* files = fileSystemLocal.ListFilesTree(path, extension, true);
    for (int index = 0; index < files->GetNumFiles(); ++index)
        idLibPrint::Printf("%s\n", files->GetFile(index));
    fileSystemLocal.FreeFileList(files);
}

void idFileSystemLocal::Path_f(const idCmdArgs&) {
    idLibPrint::Printf("Current search path:\n");
    for (int index = 0; index < fileSystemLocal.searchPaths.Num(); ++index)
        idLibPrint::Printf("%s\n", fileSystemLocal.searchPaths[index].c_str());
}
