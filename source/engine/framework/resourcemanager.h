#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\resourcemanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18479; PDB kind: class.
class idResourceManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18480.
  virtual ~idResourceManager();
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

};

// IDA Local Type ordinal 23418; PDB kind: struct.
struct jpeg_source_mgr
{
  const unsigned __int8 *next_input_byte;
  unsigned int bytes_in_buffer;
  void (__fastcall *init_source)(jpeg_decompress_struct *);
  unsigned __int8 (__fastcall *fill_input_buffer)(jpeg_decompress_struct *);
  void (__fastcall *skip_input_data)(jpeg_decompress_struct *, int);
  unsigned __int8 (__fastcall *resync_to_restart)(jpeg_decompress_struct *, int);
  void (__fastcall *term_source)(jpeg_decompress_struct *);
};
