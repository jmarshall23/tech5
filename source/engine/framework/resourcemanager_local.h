#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\resourcemanager_local.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23578; PDB kind: class.
class __declspec(align(4)) idResourceManagerLocal : public idResourceManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23579.
  virtual ~idResourceManagerLocal();
  virtual void Init();
  virtual void Init2(const bool);
  virtual void Shutdown();
  virtual void CancelToTerminate();
  virtual void CloseOpenFileHandles();
  virtual bool ReOpenFileHandles();
  virtual void StartupComplete();
  virtual void SetFileHook();
  virtual void ReleaseFileHook();
  virtual bool AllocGameWithResourceFile(idGame **, const idGameSpawnInfo *, idFile *, const char *);
  virtual idFile_Memory *LoadCacheFile(const char *);
  virtual idFile_Memory *LoadPatchFile(const char *);
  virtual idFile_Stat *StatCacheFile(const char *);
  virtual idFile_Stat *StatPatchFile(const char *);
  virtual bool GetCacheFileInfo(const char *, __int64 *, unsigned int *, unsigned int *, unsigned int *, bool);
  virtual bool GetPatchFileInfo(const char *, __int64 *, unsigned int *, unsigned int *, unsigned int *, int *);
  virtual idFile *GetCacheFile();
  virtual idFile *GetPatchFile(const int);
  virtual idFile *GetStreamFile();
  virtual idFile *GetCachedStreamFile();
  virtual idFile *GetLocalizedStreamFile();
  virtual bool IsResourceFile(idFile *);
  virtual void SetResourceFilePlatform(unsigned int);
  virtual unsigned int GetBuildPlatforms();
  virtual void BeginEntity(const char *, const idList<idStr,5> *);
  virtual void EndEntity();
  virtual const idList<idStr,5> *GetLanguages();
  virtual bool ExcludeImage(const char *);
  virtual bool ExcludeFont(const char *);
  virtual int GetCurrentDiscNumber();

  idFile *resourceFile;
  idFile *streamFile;
  idFile *localizedStreamFile;
  idFile *cachedStreamFile;
  idStaticList<idFile *,32> patchFiles;
  unsigned int tableOffset;
  unsigned int tableLength;
  unsigned int resourceMagic;
  idResourceAnnotation *currentSortedResource;
  idResource *currentResource;
  idList<idResourceFileEntry,99> writtenResourceTable;
  idList<idResourceFileEntry,99> fileTable;
  int fileTableResource;
  idList<idResourceCacheEntry,99> cacheTable;
  idHashIndex cacheHash;
  idList<idResourceCacheEntry,99> patchTable;
  idHashIndex patchHash;
  unsigned int filePlatformBits;
  unsigned int buildPlatforms;
  int lastUPacifierMsec;
  idList<idStr,5> languages;
  bool denyFonts;
  volatile bool cancelToTerminate;
};
