#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\test\report.h
// Recovered logical types: 39
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 916; PDB kind: enum.
enum idreports::LogEvent_Severity : __int32
{
  LogEvent_Severity_SEV_EMERGENCY = 0x50,
  LogEvent_Severity_SEV_ALERT = 0x46,
  LogEvent_Severity_SEV_CRITICAL = 0x3C,
  LogEvent_Severity_SEV_ERROR = 0x32,
  LogEvent_Severity_SEV_WARNING = 0x28,
  LogEvent_Severity_SEV_NOTICE = 0x1E,
  LogEvent_Severity_SEV_INFO = 0x14,
  LogEvent_Severity_SEV_DEBUG = 0xA,
  LogEvent_Severity_SEV_TRASH = 0x0,
};

// IDA Local Type ordinal 917; PDB kind: enum.
enum idreports::TargetPlatform : __int32
{
  TARGET_WIN32 = 0x0,
  TARGET_X64 = 0x1,
  TARGET_XBOX360 = 0x2,
  TARGET_PS3 = 0x3,
  TARGET_DURANGO = 0x4,
  TARGET_WIIU = 0x5,
  TARGET_IPHONE = 0x6,
  TARGET_OSX = 0x7,
  TARGET_LINUX = 0x8,
};

// IDA Local Type ordinal 918; PDB kind: enum.
enum idreports::HeapType : __int32
{
  UNKNOWN_HEAP = 0x0,
  MAP_HEAP = 0x1,
  SYSTEM_HEAP = 0x2,
};

// IDA Local Type ordinal 919; PDB kind: enum.
enum idreports::Xbox360ConsoleType : __int32
{
  XBOX360_DEVELOPMENT_KIT = 0x0,
  XBOX360_TEST_KIT = 0x1,
  XBOX360_UNKNOWN_KIT = 0x2,
};

// IDA Local Type ordinal 1199; PDB kind: unknown.
enum idReportData::<unnamed_tag> : __int32
{
  MAX_SEVERITY = 0x5,
  MAX_DEVGROUP = 0x4,
  MAX_REPRODUCED = 0x5,
};

// IDA Local Type ordinal 12565; PDB kind: class.
class idreports::Xbox360VersionInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12566.
  virtual ~Xbox360VersionInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  unsigned int major_;
  unsigned int minor_;
  unsigned int build_;
  unsigned int qfe_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12571; PDB kind: class.
class idreports::SPURegisterInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12572.
  virtual ~SPURegisterInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  google::protobuf::RepeatedPtrField<idreports::BigUInt> gpr_;
  google::protobuf::RepeatedPtrField<idreports::BigUInt> fpscr_;
  unsigned int npc_;
  unsigned int srr0_;
  unsigned __int64 spu_cfg_;
  unsigned int spu_status_;
  unsigned int mb_stat_;
  google::protobuf::RepeatedField<unsigned int> spu_mb_;
  unsigned int ppu_mb_;
  unsigned int decrementer_;
  google::protobuf::RepeatedField<unsigned __int64> mfc_cq_sr_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12575; PDB kind: class.
class idreports::LogEvent : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12576.
  virtual ~LogEvent();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *timestamp_;
  std::string *message_;
  google::protobuf::RepeatedPtrField<std::string > tags_;
  std::string *data_;
  int severity_;
  int platform_;
  std::string *datatype_;
  google::protobuf::RepeatedPtrField<idreports::Attachment> externs_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12577; PDB kind: class.
class idreports::PS3ExceptionInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12578.
  virtual ~PS3ExceptionInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *exceptionname_;
  unsigned __int64 exceptioncode_;
  unsigned __int64 dar_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12579; PDB kind: struct.
struct idreports::StaticDescriptorInitializer_reports_2eproto
{
};

// IDA Local Type ordinal 12580; PDB kind: class.
class idreports::Xbox360KitInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12581.
  virtual ~Xbox360KitInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  idreports::Xbox360VersionInfo *basekernelversion_;
  idreports::Xbox360VersionInfo *kernelversion_;
  int kittype_;
  unsigned int systeminfoflags_;
  idreports::Xbox360VersionInfo *xdkversion_;
  std::string *consolename_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12582; PDB kind: class.
class idreports::MemoryInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12583.
  virtual ~MemoryInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  unsigned int inuse_;
  unsigned int physicalmb_;
  unsigned int physicalfree_;
  unsigned int pagingfile_;
  unsigned int pagingfree_;
  unsigned int useraddress_;
  unsigned int userfree_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12584; PDB kind: class.
class idreports::Attachment : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12585.
  virtual ~Attachment();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *attachment_;
  std::string *filename_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12586; PDB kind: class.
class idreports::ViewNoteReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12587.
  virtual ~ViewNoteReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *game_;
  std::string *username_;
  std::string *reportedby_;
  std::string *platform_;
  bool issingleplayer_;
  int buildnumbermajor_;
  std::string *timestamp_;
  std::string *launchcommand_;
  std::string *vtfilepath_;
  std::string *vtfilepathvmtroverride_;
  std::string *bugtitle_;
  std::string *tasktype_;
  std::string *reprosteps_;
  std::string *details_;
  std::string *severity_;
  std::string *mappath_;
  std::string *priority_;
  idreports::Attachment *attachment_;
  int buildnumberminor_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12588; PDB kind: class.
class idreports::PS3VMRegionStats : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12589.
  virtual ~PS3VMRegionStats();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *regionname_;
  int virtualsizeinbytes_;
  int uncommittedpages_;
  int physicalpages_;
  int diskpages_;
  int maxpages_;
  int committedpages_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12590; PDB kind: class.
class idreports::ExceptionInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12591.
  virtual ~ExceptionInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *expcode_;
  std::string *expaddress_;
  int expflags_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12592; PDB kind: class.
class idreports::XenonRegisterInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12593.
  virtual ~XenonRegisterInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *msr_;
  std::string *iar_;
  std::string *lr_;
  std::string *ctr_;
  std::string *fpscr_;
  google::protobuf::RepeatedPtrField<std::string > fpr_;
  std::string *cr_;
  std::string *xer_;
  google::protobuf::RepeatedPtrField<std::string > gpr_;
  std::string *vscr_;
  google::protobuf::RepeatedPtrField<std::string > vr_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12594; PDB kind: class.
class idreports::XenonMemoryInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12595.
  virtual ~XenonMemoryInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  unsigned int totalpages_;
  unsigned int availablepages_;
  unsigned int stackpages_;
  unsigned int virtualpagetablepages_;
  unsigned int systempagetablepages_;
  unsigned int poolpages_;
  unsigned int virtualmappedpages_;
  unsigned int imagepages_;
  unsigned int filecachepages_;
  unsigned int contiguouspages_;
  unsigned int debuggerpages_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12596; PDB kind: class.
class idreports::Xbox360CrashReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12597.
  virtual ~Xbox360CrashReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *game_;
  std::string *username_;
  std::string *platform_;
  int buildnumbermajor_;
  int buildnumberminor_;
  std::string *buildstring_;
  std::string *timestamp_;
  std::string *launchcommand_;
  std::string *vtfilepath_;
  std::string *vtfilepathvmtroverride_;
  std::string *mappath_;
  idreports::Xbox360KitInfo *kitinfo_;
  google::protobuf::RepeatedPtrField<std::string > callstack_;
  idreports::ExceptionInfo *exception_;
  idreports::XenonRegisterInfo *registers_;
  idreports::XenonMemoryInfo *consolememory_;
  idreports::XenonMemoryInfo *titlememory_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12598; PDB kind: class.
class idreports::StringIDReferenceReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12599.
  virtual ~StringIDReferenceReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  google::protobuf::RepeatedPtrField<std::string > stringids_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12600; PDB kind: class.
class idreports::CallstackLine : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12601.
  virtual ~CallstackLine();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *functioncall_;
  int line_;
  int bytepos_;
  std::string *filename_;
  std::string *address_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12602; PDB kind: class.
class idreports::CPUInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12603.
  virtual ~CPUInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *cpuid_;
  int packages_;
  int cores_;
  int logical_;
  float frequency_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12605; PDB kind: class.
class idreports::PS3MemoryInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12606.
  virtual ~PS3MemoryInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  unsigned int totalsystemmemory_;
  unsigned int usedsystemmemory_;
  unsigned int availablesystemmemory_;
  unsigned int unaccountedfor_;
  unsigned int pmem_total_;
  unsigned int pmem_used_;
  unsigned __int64 page_in_;
  unsigned __int64 page_out_;
  unsigned __int64 page_fault_ppu_;
  unsigned __int64 page_fault_spu_;
  google::protobuf::RepeatedPtrField<idreports::PS3VMRegionStats> regions_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12607; PDB kind: class.
class idreports::AssertReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12608.
  virtual ~AssertReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *mapname_;
  std::string *filename_;
  std::string *expression_;
  std::string *username_;
  unsigned int line_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12609; PDB kind: class.
class idreports::BigUInt : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12610.
  virtual ~BigUInt();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  unsigned __int64 lowpart_;
  unsigned __int64 highpart_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12611; PDB kind: class.
class __declspec(align(8)) idreports::PPURegisterInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12612.
  virtual ~PPURegisterInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  google::protobuf::RepeatedField<unsigned __int64> gpr_;
  unsigned __int64 xer_;
  unsigned __int64 lr_;
  unsigned __int64 ctr_;
  unsigned int cr_;
  unsigned int fpscr_;
  unsigned __int64 pc_;
  google::protobuf::RepeatedField<unsigned __int64> fpr_;
  google::protobuf::RepeatedPtrField<idreports::BigUInt> vr_;
  idreports::BigUInt *vscr_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12614; PDB kind: class.
class __declspec(align(8)) idreports::PS3CrashReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12615.
  virtual ~PS3CrashReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *game_;
  std::string *username_;
  std::string *platform_;
  int buildnumbermajor_;
  int buildnumberminor_;
  std::string *buildstring_;
  std::string *timestamp_;
  std::string *launchcommand_;
  std::string *vtfilepath_;
  std::string *vtfilepathvmtroverride_;
  std::string *mappath_;
  google::protobuf::RepeatedField<unsigned __int64> callstack_;
  idreports::PS3ExceptionInfo *exception_;
  idreports::PPURegisterInfo *ppuregisters_;
  google::protobuf::RepeatedPtrField<idreports::SPURegisterInfo> spuregisters_;
  idreports::PS3MemoryInfo *memoryinfo_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12616; PDB kind: class.
class idreports::CrashReportResult : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12617.
  virtual ~CrashReportResult();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  __int64 bugid_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12618; PDB kind: class.
class idreports::MapWarning : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12619.
  virtual ~MapWarning();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *message_;
  google::protobuf::RepeatedField<unsigned int> marks_;
  unsigned int count_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12620; PDB kind: class.
class idreports::RegisterInfo : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12621.
  virtual ~RegisterInfo();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *edi_;
  std::string *esi_;
  std::string *eax_;
  std::string *ebx_;
  std::string *ecx_;
  std::string *edx_;
  std::string *eip_;
  std::string *ebp_;
  std::string *esp_;
  std::string *eflags_;
  std::string *segcs_;
  std::string *segss_;
  int platform_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12622; PDB kind: class.
class idreports::HeapCategoryUsage : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12623.
  virtual ~HeapCategoryUsage();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *categoryname_;
  unsigned int totalever_;
  unsigned int totalcurrent_;
  unsigned int totalsize_;
  unsigned int totalwaste_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12625; PDB kind: class.
class idreports::MapReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12626.
  virtual ~MapReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *mapname_;
  std::string *username_;
  std::string *machinename_;
  std::string *platform_;
  std::string *game_;
  std::string *buildversion_;
  std::string *buildtimestamp_;
  google::protobuf::RepeatedPtrField<idreports::MapWarning> warnings_;
  unsigned int loadtime_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12628; PDB kind: class.
class idreports::HeapUsage : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12629.
  virtual ~HeapUsage();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  int heaptype_;
  unsigned int totalever_;
  unsigned int totalcurrent_;
  unsigned int totalsize_;
  google::protobuf::RepeatedPtrField<idreports::HeapCategoryUsage> categories_;
  unsigned int totalwaste_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 12631; PDB kind: class.
class idreports::CrashReport : public google::protobuf::MessageLite
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12632.
  virtual ~CrashReport();
  virtual std::string *GetTypeName(std::string *result);
  virtual google::protobuf::MessageLite *New();
  virtual void Clear();
  virtual bool IsInitialized();
  virtual std::string *InitializationErrorString(std::string *result);
  virtual void CheckTypeAndMergeFrom(const google::protobuf::MessageLite *);
  virtual bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream *);
  virtual int ByteSize();
  virtual void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream *);
  virtual unsigned __int8 *SerializeWithCachedSizesToArray(unsigned __int8 *);
  virtual int GetCachedSize();

  std::string *game_;
  std::string *username_;
  std::string *platform_;
  int buildnumbermajor_;
  int buildnumberminor_;
  std::string *buildstring_;
  std::string *timestamp_;
  std::string *launchcommand_;
  std::string *vtfilepath_;
  std::string *vtfilepathvmtroverride_;
  std::string *bugtitle_;
  std::string *reprosteps_;
  std::string *details_;
  std::string *severity_;
  std::string *component_;
  std::string *mappath_;
  std::string *priority_;
  std::string *localfilename_;
  std::string *dmppath_;
  google::protobuf::RepeatedPtrField<std::string > consolehistory_;
  google::protobuf::RepeatedPtrField<idreports::CallstackLine> callstack_;
  idreports::ExceptionInfo *exception_;
  idreports::RegisterInfo *registers_;
  idreports::Attachment *attachment_;
  idreports::CPUInfo *cpuinfo_;
  idreports::MemoryInfo *meminfo_;
  int _cached_size_;
  unsigned int _has_bits_[1];
};

// IDA Local Type ordinal 17425; PDB kind: class.
class idReport
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17426.
  virtual ~idReport();
  virtual void WriteReport();

  idFile *html;
  idXMLWriter *xmlWriter;
  idStr reportPath;
  idStr pathSuffix;
  idFolderReport *reportParent;
  idList<enum testStatus_t,5> childResults;
  testStatus_t finalResult;
};

// IDA Local Type ordinal 17432; PDB kind: class.
class idTestReport : public idReport
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17433.
  virtual ~idTestReport();
  virtual void WriteReport();

  idList<idStr,5> types;
  idList<idStr,5> infos;
  idList<testReportField_t,5> testReportFields;
};

// IDA Local Type ordinal 17678; PDB kind: class.
class idReportData
{
public:
  idStr userName;
  idStr platform;
  idStr buildMessage;
  int buildNumberMajor;
  int buildNumberMinor;
  idStr cpuID;
  int coreNum;
  int logicalNum;
  int packageNum;
  float cpuFrequency;
  idStr launchCommand;
  idStr vtFilePathCvar;
  idStr vtFilePathVmtrOverrideCvar;
  idStr title;
  idStr steps;
  idStr details;
  idStr severity;
  idStr component;
  idStr reproduced;
  idStr style;
  idStr mapPath;
  idStr priority;
  idStr systemInfo;
  idStr localFilename;
  idStr dmpPath;
  idList<idStr,5> originalCallstack;
  idStr callstack;
  idStr exception;
  idStr registers;
  idStr attachFilename;
  idStr fullFunctionDetails;
  idStr someFunctionDetails;
};

// IDA Local Type ordinal 32081; PDB kind: typedef.
typedef void *HREPORT;

// IDA Local Type ordinal 34168; PDB kind: unknown.
struct idreports;
