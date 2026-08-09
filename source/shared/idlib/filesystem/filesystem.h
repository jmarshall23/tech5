#pragma once

#include "file.h"
#include "../containers/hashindex.h"
#include "../containers/list.h"
#include "../text/cmdargs.h"

enum sysFolder_t : int {
    FOLDER_ERROR = -1,
    FOLDER_NO = 0,
    FOLDER_YES = 1
};

class idFileList {
public:
    idFileList();

    const char* GetBasePath() const { return basePath.c_str(); }
    int GetNumFiles() const { return list.Num(); }
    const char* GetFile(int index) const { return list[index].c_str(); }

    idStr basePath;
    idList<idStr> list;
};

class idZippedFile {
public:
    idStr name;
    unsigned int pos;
    idZippedFile* next;
};

class idCachedZipFile {
public:
    idCachedZipFile();
    ~idCachedZipFile();

    idStr zipFileName;
    idStr relativeZipFileName;
    void* handle;
    int numFiles;
    idZippedFile* hashTable[128];
    idZippedFile* fileList;
    idCachedZipFile* next;
};

using filePreCallback_t = idFile* (*)(const char* relativePath);
using filePostCallback_t = void (*)(const char* relativePath, idFile* file);
using fileCacheCallback_t = idFile* (*)(const char* relativePath);
using filePatchCallback_t = idFile* (*)(const char* relativePath);

class idFileSystem {
public:
    virtual ~idFileSystem();
    virtual void Init() = 0;
    virtual void ReInit(const char* gameFolder) = 0;
    virtual bool IsInitialized() const = 0;
    virtual void SetFilePreCallback(filePreCallback_t callback) = 0;
    virtual void SetFilePostCallback(filePostCallback_t callback) = 0;
    virtual void SetFileCacheCallback(fileCacheCallback_t statCallback,
        fileCacheCallback_t cacheCallback) = 0;
    virtual void SetFilePatchCallback(filePatchCallback_t callback) = 0;
    virtual idFileList* ListFiles(const char* relativePath,
        const char* extension, bool sort = false,
        bool fullRelativePath = false) = 0;
    virtual idFileList* ListFilesTree(const char* relativePath,
        const char* extension, bool sort = false) = 0;
    virtual void FreeFileList(idFileList* fileList) = 0;
    virtual bool IsRelativePath(const char* path) const = 0;
    virtual idStr RelativePathToOSPath(const char* relativePath,
        fsPath_t basePath) const = 0;
    virtual void RelativePathToOSPath(const char* relativePath, char* osPath,
        int osPathSize, fsPath_t basePath) const = 0;
    virtual bool OSPathToRelativePath(const char* osPath,
        char* relativePath, int relativePathSize) = 0;
    virtual bool FixLongFilename(const char* basePath,
        const char* extension, const char* inputPath, char* fixedPath,
        int fixedPathSize) const = 0;
    virtual void CreateOSPath(const char* osPath) = 0;
    virtual bool FileExists(const char* relativePath,
        bool allowCopyFiles = true) = 0;
    virtual bool IsWritable(const char* relativePath) const = 0;
    virtual sysFolder_t IsFolder(const char* relativePath,
        fsPath_t basePath) const = 0;
    virtual unsigned int GetTimestamp(const char* relativePath,
        bool allowCopyFiles = true) = 0;
    virtual void GetNumberedFilename(int& index, const char* prefix,
        const char* extension, idStr& result, bool zeroPad = false) = 0;
    virtual int ReadFile(const char* relativePath, void** buffer,
        unsigned int* timestamp = nullptr) = 0;
    virtual void FreeFile(void* buffer) = 0;
    virtual unsigned int WriteFile(const char* relativePath,
        const void* buffer, unsigned int length, fsPath_t basePath) = 0;
    virtual bool RemoveFile(const char* relativePath, fsPath_t basePath) = 0;
    virtual bool RemoveDir(const char* relativePath) = 0;
    virtual bool RenameFile(const char* from, const char* to,
        fsPath_t basePath) = 0;
    virtual idFile* OpenFileRead(const char* relativePath,
        bool allowCopyFiles = true, bool uncompressedOnly = false) = 0;
    virtual idFile* OpenFileWrite(const char* relativePath,
        fsPath_t basePath) = 0;
    virtual idFile* OpenFileWritePermanent(const char* relativePath,
        fsPath_t basePath) = 0;
    virtual idFile* OpenFileReadWrite(const char* relativePath, bool create,
        fsPath_t basePath) = 0;
    virtual idFile* OpenFileAppend(const char* relativePath,
        fsPath_t basePath) = 0;
    virtual const char* GetBasePathStr(fsPath_t basePath) const = 0;
    virtual idStr GeneratedPath(const char* relativePath) const = 0;
    virtual std::int64_t GetFileLength(const char* relativePath) = 0;
    virtual void ClearZipCache() = 0;
    virtual bool CopyGameFile(const char* from, const char* to,
        fsPath_t basePath) = 0;
};

class idFile_InZip;

class idFileSystemLocal : public idFileSystem {
public:
    idFileSystemLocal();
    ~idFileSystemLocal() override;

    void Init() override;
    void ReInit(const char* gameFolder) override;
    bool IsInitialized() const override;
    void SetFilePreCallback(filePreCallback_t callback) override;
    void SetFilePostCallback(filePostCallback_t callback) override;
    void SetFileCacheCallback(fileCacheCallback_t statCallback,
        fileCacheCallback_t cacheCallback) override;
    void SetFilePatchCallback(filePatchCallback_t callback) override;
    idFileList* ListFiles(const char* relativePath, const char* extension,
        bool sort, bool fullRelativePath) override;
    idFileList* ListFilesTree(const char* relativePath,
        const char* extension, bool sort) override;
    void FreeFileList(idFileList* fileList) override;
    bool IsRelativePath(const char* path) const override;
    idStr RelativePathToOSPath(const char* relativePath,
        fsPath_t basePath) const override;
    void RelativePathToOSPath(const char* relativePath, char* osPath,
        int osPathSize, fsPath_t basePath) const override;
    bool OSPathToRelativePath(const char* osPath, char* relativePath,
        int relativePathSize) override;
    bool FixLongFilename(const char* basePath, const char* extension,
        const char* inputPath, char* fixedPath,
        int fixedPathSize) const override;
    void CreateOSPath(const char* osPath) override;
    bool FileExists(const char* relativePath, bool allowCopyFiles) override;
    bool IsWritable(const char* relativePath) const override;
    sysFolder_t IsFolder(const char* relativePath,
        fsPath_t basePath) const override;
    unsigned int GetTimestamp(const char* relativePath,
        bool allowCopyFiles) override;
    void GetNumberedFilename(int& index, const char* prefix,
        const char* extension, idStr& result, bool zeroPad) override;
    int ReadFile(const char* relativePath, void** buffer,
        unsigned int* timestamp) override;
    void FreeFile(void* buffer) override;
    unsigned int WriteFile(const char* relativePath, const void* buffer,
        unsigned int length, fsPath_t basePath) override;
    bool RemoveFile(const char* relativePath, fsPath_t basePath) override;
    bool RemoveDir(const char* relativePath) override;
    bool RenameFile(const char* from, const char* to,
        fsPath_t basePath) override;
    idFile* OpenFileRead(const char* relativePath, bool allowCopyFiles,
        bool uncompressedOnly) override;
    idFile* OpenFileWrite(const char* relativePath,
        fsPath_t basePath) override;
    idFile* OpenFileWritePermanent(const char* relativePath,
        fsPath_t basePath) override;
    idFile* OpenFileReadWrite(const char* relativePath, bool create,
        fsPath_t basePath) override;
    idFile* OpenFileAppend(const char* relativePath,
        fsPath_t basePath) override;
    const char* GetBasePathStr(fsPath_t basePath) const override;
    idStr GeneratedPath(const char* relativePath) const override;
    std::int64_t GetFileLength(const char* relativePath) override;
    void ClearZipCache() override;
    bool CopyGameFile(const char* from, const char* to,
        fsPath_t basePath) override;
    bool CopyGameFile(idFile* source, idFile* destination);

    static void Copy_f(const idCmdArgs& args);
    static void Dir_f(const idCmdArgs& args);
    static void DirTree_f(const idCmdArgs& args);
    static void Path_f(const idCmdArgs& args);

    idList<idStr, TAG_FILE> searchPaths;
    idCachedZipFile* cachedZipFiles;
    int loadCount;
    int loadStack;
    idStr pathBase;
    idStr pathCache;
    idStr pathInstall;
    idStr pathSave;
    filePreCallback_t preCallback;
    filePostCallback_t postCallback;
    fileCacheCallback_t cacheStatCallback;
    fileCacheCallback_t cacheCallback;
    filePatchCallback_t patchCallback;

private:
    void AddGameDirectory(const char* rootPath, const char* gameFolder);
    int AddUnique(const char* name, idList<idStr>& list,
        idHashIndex& hash) const;
    idStr BuildOSPath(const char* root, const char* relativePath) const;
    idStr BuildOSPath(fsPath_t basePath, const char* relativePath) const;
    void GetExtensionList(const char* extensions,
        idList<idStr>& extensionList) const;
    int GetFileList(const char* relativePath,
        const idList<idStr>& extensions, idList<idStr>& list,
        idHashIndex& hash, bool fullRelativePath);
    int GetFileListTree(const char* relativePath,
        const idList<idStr>& extensions, idList<idStr>& list,
        idHashIndex& hash);
    void ListOSFiles(const char* directory, const char* extension,
        idList<idStr>& list);
    idCachedZipFile* LoadZipFile(const char* zipFile,
        const char* relativeZipFile);
    idFile* OpenFromMTP(const char* path, fsMode_t mode);
    idFile* OpenFromNFS(const char* path, fsMode_t mode, bool create);
    bool PreOpenFileWrite(const char* relativePath, fsPath_t& basePath,
        idStr& osPath) const;
    idFile_InZip* ReadFileFromZip(idCachedZipFile* zip,
        const char* relativePath, bool uncompressedOnly);
};

extern idFileSystem* fileSystem;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFileList) == 48, "Recovered idFileList ABI changed");
static_assert(sizeof(idZippedFile) == 40,
    "Recovered idZippedFile ABI changed");
static_assert(sizeof(idCachedZipFile) == 592,
    "Recovered idCachedZipFile ABI changed");
static_assert(sizeof(idFileSystem) == 4,
    "Recovered idFileSystem ABI changed");
static_assert(sizeof(idFileSystemLocal) == 180,
    "Recovered idFileSystemLocal ABI changed");
#endif
