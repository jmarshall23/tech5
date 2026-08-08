#pragma once

// Reconstructed from the protobuf 2.4 generated code in the Tungsten Xbox 360
// image.  This keeps the original protobuf-lite surface and wire format while
// avoiding a dependency on the obsolete 2.4 runtime in the Windows port.

#include <cstddef>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace google {
namespace protobuf {

class MessageLite {
public:
    virtual ~MessageLite() {}
    virtual std::string GetTypeName() const = 0;
    virtual MessageLite* New() const = 0;
    virtual void Clear() = 0;
    virtual bool IsInitialized() const = 0;
    virtual int ByteSize() const = 0;
    virtual int GetCachedSize() const { return ByteSize(); }
    virtual bool SerializePartialToArray(void* data, int size) const = 0;
    virtual bool ParseFromArray(const void* data, int size) = 0;

    bool SerializeToArray(void* data, int size) const;
    bool SerializePartialToString(std::string* output) const;
    bool SerializeToString(std::string* output) const;
    std::string SerializeAsString() const;
    bool ParseFromString(const std::string& input);
};

} // namespace protobuf
} // namespace google

namespace idreports {

enum LogEvent_Severity {
    LogEvent_Severity_SEV_EMERGENCY = 80,
    LogEvent_Severity_SEV_ALERT = 70,
    LogEvent_Severity_SEV_CRITICAL = 60,
    LogEvent_Severity_SEV_ERROR = 50,
    LogEvent_Severity_SEV_WARNING = 40,
    LogEvent_Severity_SEV_NOTICE = 30,
    LogEvent_Severity_SEV_INFO = 20,
    LogEvent_Severity_SEV_DEBUG = 10,
    LogEvent_Severity_SEV_TRASH = 0
};

bool LogEvent_Severity_IsValid(int value);
const char* LogEvent_Severity_Name(LogEvent_Severity value);

enum TargetPlatform {
    TARGET_WIN32 = 0,
    TARGET_X64 = 1,
    TARGET_XBOX360 = 2,
    TARGET_PS3 = 3,
    TARGET_DURANGO = 4,
    TARGET_WIIU = 5,
    TARGET_IPHONE = 6,
    TARGET_OSX = 7,
    TARGET_LINUX = 8
};

bool TargetPlatform_IsValid(int value);
const char* TargetPlatform_Name(TargetPlatform value);

enum HeapType {
    UNKNOWN_HEAP = 0,
    MAP_HEAP = 1,
    SYSTEM_HEAP = 2
};

enum Xbox360ConsoleType {
    XBOX360_DEVELOPMENT_KIT = 0,
    XBOX360_TEST_KIT = 1,
    XBOX360_UNKNOWN_KIT = 2
};

class BigUInt;
class Attachment;
class LogEvent;
class MemoryInfo;
class ExceptionInfo;
class CallstackLine;
class AssertReport;
class MapWarning;
class MapReport;
class ViewNoteReport;
class StringIDReferenceReport;
class CPUInfo;
class RegisterInfo;
class HeapCategoryUsage;
class HeapUsage;
class Xbox360VersionInfo;
class Xbox360KitInfo;
class XenonRegisterInfo;
class XenonMemoryInfo;
class PPURegisterInfo;
class SPURegisterInfo;
class PS3ExceptionInfo;
class PS3VMRegionStats;
class PS3MemoryInfo;
class CrashReport;
class Xbox360CrashReport;
class PS3CrashReport;
class CrashReportResult;

namespace internal {

enum FieldKind {
    FIELD_UNKNOWN,
    FIELD_STRING,
    FIELD_UINT32,
    FIELD_UINT64,
    FIELD_INT32,
    FIELD_INT64,
    FIELD_ENUM,
    FIELD_BOOL,
    FIELD_FLOAT,
    FIELD_MESSAGE,
    FIELD_REPEATED_STRING,
    FIELD_REPEATED_UINT32,
    FIELD_REPEATED_UINT64,
    FIELD_REPEATED_MESSAGE
};

struct FieldValue {
    FieldValue();
    FieldKind kind;
    std::uint64_t integer;
    float real;
    std::string text;
    std::shared_ptr<google::protobuf::MessageLite> message;
    std::vector<std::string> strings;
    std::vector<std::uint64_t> integers;
    std::vector<std::shared_ptr<google::protobuf::MessageLite> > messages;
};

class ReportMessage : public google::protobuf::MessageLite {
public:
    ReportMessage();
    ReportMessage(const ReportMessage& other);
    ReportMessage& operator=(const ReportMessage& other);
    virtual ~ReportMessage();

    void Clear() override;
    bool IsInitialized() const override;
    int ByteSize() const override;
    bool SerializePartialToArray(void* data, int size) const override;
    bool ParseFromArray(const void* data, int size) override;

    void CopyFrom(const google::protobuf::MessageLite& other);
    void MergeFrom(const google::protobuf::MessageLite& other);
    void Swap(ReportMessage* other);

protected:
    bool HasField(int number) const;
    void ClearField(int number);
    std::uint64_t GetInteger(int number) const;
    void SetInteger(int number, FieldKind kind, std::uint64_t value);
    float GetFloat(int number) const;
    void SetFloat(int number, float value);
    const std::string& GetString(int number) const;
    std::string* MutableString(int number);
    std::string* ReleaseString(int number);
    void SetString(int number, const char* value, std::size_t size);
    int RepeatedIntegerSize(int number) const;
    std::uint64_t GetRepeatedInteger(int number, int index) const;
    void SetRepeatedInteger(int number, int index, FieldKind kind,
        std::uint64_t value);
    void AddRepeatedInteger(int number, FieldKind kind, std::uint64_t value);
    int RepeatedStringSize(int number) const;
    const std::string& GetRepeatedString(int number, int index) const;
    std::string* MutableRepeatedString(int number, int index);
    std::string* AddRepeatedString(int number);
    void SetRepeatedString(int number, int index, const char* value,
        std::size_t size);
    int RepeatedMessageSize(int number) const;
    const google::protobuf::MessageLite* GetRepeatedMessage(int number,
        int index) const;
    google::protobuf::MessageLite* MutableRepeatedMessage(int number,
        int index);
    google::protobuf::MessageLite* AddRepeatedMessage(int number);
    const google::protobuf::MessageLite* GetMessage(int number) const;
    google::protobuf::MessageLite* MutableMessage(int number);
    google::protobuf::MessageLite* ReleaseMessage(int number);
    void SetAllocatedMessage(int number, google::protobuf::MessageLite* value);

    virtual FieldKind FieldKindForNumber(int number) const = 0;
    virtual google::protobuf::MessageLite* NewMessageForField(int number) const;
    virtual bool HasRequiredFields() const = 0;

private:
    bool Serialize(std::string& output) const;
    std::map<int, FieldValue> fields_;
};

} // namespace internal

#define IDR_DECL_string(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    const std::string& name() const { return GetString(number); } \
    void set_##name(const std::string& value) { SetString(number, value.data(), value.size()); } \
    void set_##name(const char* value) { SetString(number, value ? value : "", value ? std::char_traits<char>::length(value) : 0); } \
    void set_##name(const char* value, std::size_t size) { SetString(number, value, size); } \
    std::string* mutable_##name() { return MutableString(number); } \
    std::string* release_##name() { return ReleaseString(number); } \
    void set_allocated_##name(std::string* value) { if (value) { set_##name(*value); delete value; } else { clear_##name(); } }

#define IDR_DECL_uint32(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    std::uint32_t name() const { return static_cast<std::uint32_t>(GetInteger(number)); } \
    void set_##name(std::uint32_t value) { SetInteger(number, internal::FIELD_UINT32, value); }

#define IDR_DECL_uint64(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    std::uint64_t name() const { return GetInteger(number); } \
    void set_##name(std::uint64_t value) { SetInteger(number, internal::FIELD_UINT64, value); }

#define IDR_DECL_int32(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    std::int32_t name() const { return static_cast<std::int32_t>(GetInteger(number)); } \
    void set_##name(std::int32_t value) { SetInteger(number, internal::FIELD_INT32, static_cast<std::uint64_t>(static_cast<std::int64_t>(value))); }

#define IDR_DECL_int64(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    std::int64_t name() const { return static_cast<std::int64_t>(GetInteger(number)); } \
    void set_##name(std::int64_t value) { SetInteger(number, internal::FIELD_INT64, static_cast<std::uint64_t>(value)); }

#define IDR_DECL_enum(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    type name() const { return static_cast<type>(GetInteger(number)); } \
    void set_##name(type value) { SetInteger(number, internal::FIELD_ENUM, static_cast<std::uint64_t>(value)); }

#define IDR_DECL_bool(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    bool name() const { return GetInteger(number) != 0; } \
    void set_##name(bool value) { SetInteger(number, internal::FIELD_BOOL, value ? 1 : 0); }

#define IDR_DECL_float(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    float name() const { return GetFloat(number); } \
    void set_##name(float value) { SetFloat(number, value); }

#define IDR_DECL_message(name, number, type) \
    bool has_##name() const { return HasField(number); } \
    void clear_##name() { ClearField(number); } \
    const type& name() const { const google::protobuf::MessageLite* value = GetMessage(number); return value ? *static_cast<const type*>(value) : type::default_instance(); } \
    type* mutable_##name() { return static_cast<type*>(MutableMessage(number)); } \
    type* release_##name() { return static_cast<type*>(ReleaseMessage(number)); } \
    void set_allocated_##name(type* value) { SetAllocatedMessage(number, value); }

#define IDR_DECL_repeated_string(name, number, type) \
    int name##_size() const { return RepeatedStringSize(number); } \
    void clear_##name() { ClearField(number); } \
    const std::string& name(int index) const { return GetRepeatedString(number, index); } \
    std::string* mutable_##name(int index) { return MutableRepeatedString(number, index); } \
    std::string* add_##name() { return AddRepeatedString(number); } \
    void add_##name(const std::string& value) { std::string* item = AddRepeatedString(number); *item = value; } \
    void add_##name(const char* value) { std::string* item = AddRepeatedString(number); *item = value ? value : ""; } \
    void set_##name(int index, const std::string& value) { SetRepeatedString(number, index, value.data(), value.size()); } \
    void set_##name(int index, const char* value) { SetRepeatedString(number, index, value ? value : "", value ? std::char_traits<char>::length(value) : 0); }

#define IDR_DECL_repeated_uint32(name, number, type) \
    int name##_size() const { return RepeatedIntegerSize(number); } \
    void clear_##name() { ClearField(number); } \
    std::uint32_t name(int index) const { return static_cast<std::uint32_t>(GetRepeatedInteger(number, index)); } \
    void set_##name(int index, std::uint32_t value) { SetRepeatedInteger(number, index, internal::FIELD_REPEATED_UINT32, value); } \
    void add_##name(std::uint32_t value) { AddRepeatedInteger(number, internal::FIELD_REPEATED_UINT32, value); }

#define IDR_DECL_repeated_uint64(name, number, type) \
    int name##_size() const { return RepeatedIntegerSize(number); } \
    void clear_##name() { ClearField(number); } \
    std::uint64_t name(int index) const { return GetRepeatedInteger(number, index); } \
    void set_##name(int index, std::uint64_t value) { SetRepeatedInteger(number, index, internal::FIELD_REPEATED_UINT64, value); } \
    void add_##name(std::uint64_t value) { AddRepeatedInteger(number, internal::FIELD_REPEATED_UINT64, value); }

#define IDR_DECL_repeated_message(name, number, type) \
    int name##_size() const { return RepeatedMessageSize(number); } \
    void clear_##name() { ClearField(number); } \
    const type& name(int index) const { return *static_cast<const type*>(GetRepeatedMessage(number, index)); } \
    type* mutable_##name(int index) { return static_cast<type*>(MutableRepeatedMessage(number, index)); } \
    type* add_##name() { return static_cast<type*>(AddRepeatedMessage(number)); }

#define IDR_KIND_string(name, number, type) case number: return internal::FIELD_STRING;
#define IDR_KIND_uint32(name, number, type) case number: return internal::FIELD_UINT32;
#define IDR_KIND_uint64(name, number, type) case number: return internal::FIELD_UINT64;
#define IDR_KIND_int32(name, number, type) case number: return internal::FIELD_INT32;
#define IDR_KIND_int64(name, number, type) case number: return internal::FIELD_INT64;
#define IDR_KIND_enum(name, number, type) case number: return internal::FIELD_ENUM;
#define IDR_KIND_bool(name, number, type) case number: return internal::FIELD_BOOL;
#define IDR_KIND_float(name, number, type) case number: return internal::FIELD_FLOAT;
#define IDR_KIND_message(name, number, type) case number: return internal::FIELD_MESSAGE;
#define IDR_KIND_repeated_string(name, number, type) case number: return internal::FIELD_REPEATED_STRING;
#define IDR_KIND_repeated_uint32(name, number, type) case number: return internal::FIELD_REPEATED_UINT32;
#define IDR_KIND_repeated_uint64(name, number, type) case number: return internal::FIELD_REPEATED_UINT64;
#define IDR_KIND_repeated_message(name, number, type) case number: return internal::FIELD_REPEATED_MESSAGE;

#define IDR_FACTORY_string(name, number, type)
#define IDR_FACTORY_uint32(name, number, type)
#define IDR_FACTORY_uint64(name, number, type)
#define IDR_FACTORY_int32(name, number, type)
#define IDR_FACTORY_int64(name, number, type)
#define IDR_FACTORY_enum(name, number, type)
#define IDR_FACTORY_bool(name, number, type)
#define IDR_FACTORY_float(name, number, type)
#define IDR_FACTORY_repeated_string(name, number, type)
#define IDR_FACTORY_repeated_uint32(name, number, type)
#define IDR_FACTORY_repeated_uint64(name, number, type)
#define IDR_FACTORY_message(name, number, type) case number: return new type;
#define IDR_FACTORY_repeated_message(name, number, type) case number: return new type;

#define IDR_REQUIRE(kind, name, number, type) if (!HasField(number)) return false;
#define IDR_DECLARE(kind, name, number, type) IDR_DECL_##kind(name, number, type)
#define IDR_KIND(kind, name, number, type) IDR_KIND_##kind(name, number, type)
#define IDR_FACTORY(kind, name, number, type) IDR_FACTORY_##kind(name, number, type)

#define IDR_CLASS(name, fields, required, extras) \
class name : public internal::ReportMessage { \
public: \
    name() {} \
    name(const name& other) : internal::ReportMessage() { MergeFrom(other); } \
    name& operator=(const name& other) { if (this != &other) CopyFrom(other); return *this; } \
    std::string GetTypeName() const override { return "idreports." #name; } \
    name* New() const override { return new name; } \
    static const name& default_instance() { static const name value; return value; } \
    void CopyFrom(const name& other) { internal::ReportMessage::CopyFrom(other); } \
    void MergeFrom(const name& other) { internal::ReportMessage::MergeFrom(other); } \
    void Swap(name* other) { internal::ReportMessage::Swap(other); } \
    fields(IDR_DECLARE) \
    extras \
protected: \
    internal::FieldKind FieldKindForNumber(int number) const override { switch (number) { fields(IDR_KIND) default: return internal::FIELD_UNKNOWN; } } \
    google::protobuf::MessageLite* NewMessageForField(int number) const override { switch (number) { case -1: return 0; fields(IDR_FACTORY) default: return 0; } } \
    bool HasRequiredFields() const override { required(IDR_REQUIRE) return true; } \
};

#define IDR_NO_FIELDS(F)
#define IDR_NO_EXTRAS

#define IDR_BIGUINT_FIELDS(F) \
    F(uint64, lowpart, 1, int) \
    F(uint64, highpart, 2, int)
#define IDR_BIGUINT_REQUIRED(F) IDR_BIGUINT_FIELDS(F)
IDR_CLASS(BigUInt, IDR_BIGUINT_FIELDS, IDR_BIGUINT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_ATTACHMENT_FIELDS(F) \
    F(string, attachment, 1, int) \
    F(string, filename, 2, int)
#define IDR_ATTACHMENT_REQUIRED(F) IDR_ATTACHMENT_FIELDS(F)
IDR_CLASS(Attachment, IDR_ATTACHMENT_FIELDS, IDR_ATTACHMENT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_MEMORYINFO_FIELDS(F) \
    F(uint32, inuse, 1, int) F(uint32, physicalmb, 2, int) \
    F(uint32, physicalfree, 3, int) F(uint32, pagingfile, 4, int) \
    F(uint32, pagingfree, 5, int) F(uint32, useraddress, 6, int) \
    F(uint32, userfree, 7, int)
#define IDR_MEMORYINFO_REQUIRED(F) IDR_MEMORYINFO_FIELDS(F)
IDR_CLASS(MemoryInfo, IDR_MEMORYINFO_FIELDS, IDR_MEMORYINFO_REQUIRED, IDR_NO_EXTRAS)

#define IDR_EXCEPTIONINFO_FIELDS(F) \
    F(string, expcode, 1, int) F(enum, expflags, 2, int) \
    F(string, expaddress, 3, int)
#define IDR_EXCEPTIONINFO_REQUIRED(F) IDR_EXCEPTIONINFO_FIELDS(F)
IDR_CLASS(ExceptionInfo, IDR_EXCEPTIONINFO_FIELDS, IDR_EXCEPTIONINFO_REQUIRED, IDR_NO_EXTRAS)

#define IDR_CALLSTACKLINE_FIELDS(F) \
    F(string, functioncall, 1, int) F(int32, line, 2, int) \
    F(int32, bytepos, 3, int) F(string, filename, 4, int) \
    F(string, address, 5, int)
#define IDR_CALLSTACKLINE_REQUIRED(F) IDR_CALLSTACKLINE_FIELDS(F)
IDR_CLASS(CallstackLine, IDR_CALLSTACKLINE_FIELDS, IDR_CALLSTACKLINE_REQUIRED, IDR_NO_EXTRAS)

#define IDR_MAPWARNING_FIELDS(F) \
    F(string, message, 1, int) F(repeated_uint32, marks, 2, int) \
    F(uint32, count, 3, int)
#define IDR_MAPWARNING_REQUIRED(F) F(string, message, 1, int)
IDR_CLASS(MapWarning, IDR_MAPWARNING_FIELDS, IDR_MAPWARNING_REQUIRED, IDR_NO_EXTRAS)

#define IDR_CPUINFO_FIELDS(F) \
    F(string, cpuid, 1, int) F(int32, packages, 2, int) \
    F(int32, cores, 3, int) F(int32, logical, 4, int) \
    F(float, frequency, 5, int)
#define IDR_CPUINFO_REQUIRED(F) IDR_CPUINFO_FIELDS(F)
IDR_CLASS(CPUInfo, IDR_CPUINFO_FIELDS, IDR_CPUINFO_REQUIRED, IDR_NO_EXTRAS)

#define IDR_REGISTERINFO_FIELDS(F) \
    F(string, edi, 1, int) F(string, esi, 2, int) F(string, eax, 3, int) \
    F(string, ebx, 4, int) F(string, ecx, 5, int) F(string, edx, 6, int) \
    F(string, eip, 7, int) F(string, ebp, 8, int) F(string, esp, 9, int) \
    F(string, eflags, 10, int) F(string, segcs, 11, int) \
    F(string, segss, 12, int) F(enum, platform, 13, TargetPlatform)
#define IDR_REGISTERINFO_REQUIRED(F) IDR_REGISTERINFO_FIELDS(F)
IDR_CLASS(RegisterInfo, IDR_REGISTERINFO_FIELDS, IDR_REGISTERINFO_REQUIRED, IDR_NO_EXTRAS)

#define IDR_HEAPCATEGORY_FIELDS(F) \
    F(string, categoryname, 1, int) F(uint32, totalever, 2, int) \
    F(uint32, totalcurrent, 3, int) F(uint32, totalsize, 4, int) \
    F(uint32, totalwaste, 5, int)
#define IDR_HEAPCATEGORY_REQUIRED(F) IDR_HEAPCATEGORY_FIELDS(F)
IDR_CLASS(HeapCategoryUsage, IDR_HEAPCATEGORY_FIELDS, IDR_HEAPCATEGORY_REQUIRED, IDR_NO_EXTRAS)

#define IDR_XBOXVERSION_FIELDS(F) \
    F(uint32, major, 1, int) F(uint32, minor, 2, int) \
    F(uint32, build, 3, int) F(uint32, qfe, 4, int)
#define IDR_XBOXVERSION_REQUIRED(F) IDR_XBOXVERSION_FIELDS(F)
IDR_CLASS(Xbox360VersionInfo, IDR_XBOXVERSION_FIELDS, IDR_XBOXVERSION_REQUIRED, IDR_NO_EXTRAS)

#define IDR_XENONMEMORY_FIELDS(F) \
    F(uint32, totalpages, 1, int) F(uint32, availablepages, 2, int) \
    F(uint32, stackpages, 3, int) F(uint32, virtualpagetablepages, 4, int) \
    F(uint32, systempagetablepages, 5, int) F(uint32, poolpages, 6, int) \
    F(uint32, virtualmappedpages, 7, int) F(uint32, imagepages, 8, int) \
    F(uint32, filecachepages, 9, int) F(uint32, contiguouspages, 10, int) \
    F(uint32, debuggerpages, 11, int)
#define IDR_XENONMEMORY_REQUIRED(F) IDR_XENONMEMORY_FIELDS(F)
IDR_CLASS(XenonMemoryInfo, IDR_XENONMEMORY_FIELDS, IDR_XENONMEMORY_REQUIRED, IDR_NO_EXTRAS)

#define IDR_PS3EXCEPTION_FIELDS(F) \
    F(string, exceptionname, 1, int) F(uint64, exceptioncode, 2, int) \
    F(uint64, dar, 3, int)
#define IDR_PS3EXCEPTION_REQUIRED(F) \
    F(string, exceptionname, 1, int) F(uint64, exceptioncode, 2, int)
IDR_CLASS(PS3ExceptionInfo, IDR_PS3EXCEPTION_FIELDS, IDR_PS3EXCEPTION_REQUIRED, IDR_NO_EXTRAS)

#define IDR_PS3VMREGION_FIELDS(F) \
    F(string, regionname, 1, int) F(int32, virtualsizeinbytes, 3, int) \
    F(int32, uncommittedpages, 4, int) F(int32, physicalpages, 5, int) \
    F(int32, diskpages, 6, int) F(int32, maxpages, 7, int) \
    F(int32, committedpages, 8, int)
#define IDR_PS3VMREGION_REQUIRED(F) IDR_PS3VMREGION_FIELDS(F)
IDR_CLASS(PS3VMRegionStats, IDR_PS3VMREGION_FIELDS, IDR_PS3VMREGION_REQUIRED, IDR_NO_EXTRAS)

#define IDR_LOGEVENT_FIELDS(F) \
    F(string, timestamp, 1, int) F(enum, severity, 2, LogEvent_Severity) \
    F(string, message, 3, int) F(repeated_string, tags, 4, int) \
    F(string, data, 5, int) F(string, datatype, 6, int) \
    F(repeated_message, externs, 7, Attachment) \
    F(enum, platform, 8, TargetPlatform)
#define IDR_LOGEVENT_REQUIRED(F) \
    F(string, timestamp, 1, int) F(string, message, 3, int)
#define IDR_LOGEVENT_EXTRAS \
    typedef LogEvent_Severity Severity; \
    static const Severity SEV_EMERGENCY = LogEvent_Severity_SEV_EMERGENCY; \
    static const Severity SEV_ALERT = LogEvent_Severity_SEV_ALERT; \
    static const Severity SEV_CRITICAL = LogEvent_Severity_SEV_CRITICAL; \
    static const Severity SEV_ERROR = LogEvent_Severity_SEV_ERROR; \
    static const Severity SEV_WARNING = LogEvent_Severity_SEV_WARNING; \
    static const Severity SEV_NOTICE = LogEvent_Severity_SEV_NOTICE; \
    static const Severity SEV_INFO = LogEvent_Severity_SEV_INFO; \
    static const Severity SEV_DEBUG = LogEvent_Severity_SEV_DEBUG; \
    static const Severity SEV_TRASH = LogEvent_Severity_SEV_TRASH;
IDR_CLASS(LogEvent, IDR_LOGEVENT_FIELDS, IDR_LOGEVENT_REQUIRED, IDR_LOGEVENT_EXTRAS)

#define IDR_ASSERTREPORT_FIELDS(F) \
    F(string, mapname, 1, int) F(string, filename, 2, int) \
    F(uint32, line, 3, int) F(string, expression, 4, int) \
    F(string, username, 5, int)
#define IDR_ASSERTREPORT_REQUIRED(F) \
    F(string, mapname, 1, int) F(string, filename, 2, int) \
    F(uint32, line, 3, int) F(string, expression, 4, int)
IDR_CLASS(AssertReport, IDR_ASSERTREPORT_FIELDS, IDR_ASSERTREPORT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_MAPREPORT_FIELDS(F) \
    F(string, mapname, 1, int) F(uint32, loadtime, 2, int) \
    F(string, username, 3, int) F(string, machinename, 4, int) \
    F(string, platform, 5, int) F(string, game, 6, int) \
    F(string, buildversion, 7, int) F(string, buildtimestamp, 8, int) \
    F(repeated_message, warnings, 9, MapWarning)
#define IDR_MAPREPORT_REQUIRED(F) \
    F(string, mapname, 1, int) F(uint32, loadtime, 2, int) \
    F(string, platform, 5, int) F(string, game, 6, int) \
    F(string, buildversion, 7, int) F(string, buildtimestamp, 8, int)
IDR_CLASS(MapReport, IDR_MAPREPORT_FIELDS, IDR_MAPREPORT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_VIEWNOTE_FIELDS(F) \
    F(string, game, 1, int) F(string, username, 2, int) \
    F(string, reportedby, 3, int) F(bool, issingleplayer, 4, int) \
    F(string, platform, 5, int) F(int32, buildnumbermajor, 6, int) \
    F(int32, buildnumberminor, 7, int) F(string, timestamp, 9, int) \
    F(string, launchcommand, 10, int) F(string, vtfilepath, 11, int) \
    F(string, vtfilepathvmtroverride, 12, int) F(string, bugtitle, 13, int) \
    F(string, tasktype, 14, int) F(string, reprosteps, 15, int) \
    F(string, details, 16, int) F(string, severity, 17, int) \
    F(string, mappath, 19, int) F(string, priority, 20, int) \
    F(message, attachment, 22, Attachment)
#define IDR_VIEWNOTE_REQUIRED(F) \
    F(string, game, 1, int) F(string, username, 2, int) \
    F(string, reportedby, 3, int) F(bool, issingleplayer, 4, int) \
    F(string, platform, 5, int) F(int32, buildnumbermajor, 6, int) \
    F(int32, buildnumberminor, 7, int) F(string, timestamp, 9, int) \
    F(string, launchcommand, 10, int) F(string, vtfilepath, 11, int) \
    F(string, vtfilepathvmtroverride, 12, int) F(string, bugtitle, 13, int) \
    F(string, tasktype, 14, int) F(string, reprosteps, 15, int) \
    F(string, details, 16, int) F(string, severity, 17, int)
IDR_CLASS(ViewNoteReport, IDR_VIEWNOTE_FIELDS, IDR_VIEWNOTE_REQUIRED, IDR_NO_EXTRAS)

#define IDR_STRINGID_FIELDS(F) F(repeated_string, stringids, 1, int)
IDR_CLASS(StringIDReferenceReport, IDR_STRINGID_FIELDS, IDR_NO_FIELDS, IDR_NO_EXTRAS)

#define IDR_HEAPUSAGE_FIELDS(F) \
    F(enum, heaptype, 1, HeapType) F(uint32, totalever, 2, int) \
    F(uint32, totalcurrent, 3, int) F(uint32, totalsize, 4, int) \
    F(uint32, totalwaste, 5, int) \
    F(repeated_message, categories, 6, HeapCategoryUsage)
#define IDR_HEAPUSAGE_REQUIRED(F) \
    F(enum, heaptype, 1, HeapType) F(uint32, totalever, 2, int) \
    F(uint32, totalcurrent, 3, int) F(uint32, totalsize, 4, int) \
    F(uint32, totalwaste, 5, int)
IDR_CLASS(HeapUsage, IDR_HEAPUSAGE_FIELDS, IDR_HEAPUSAGE_REQUIRED, IDR_NO_EXTRAS)

#define IDR_XBOXKIT_FIELDS(F) \
    F(enum, kittype, 1, Xbox360ConsoleType) \
    F(message, basekernelversion, 2, Xbox360VersionInfo) \
    F(message, kernelversion, 3, Xbox360VersionInfo) \
    F(message, xdkversion, 4, Xbox360VersionInfo) \
    F(uint32, systeminfoflags, 5, int) F(string, consolename, 6, int)
#define IDR_XBOXKIT_REQUIRED(F) IDR_XBOXKIT_FIELDS(F)
IDR_CLASS(Xbox360KitInfo, IDR_XBOXKIT_FIELDS, IDR_XBOXKIT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_XENONREGISTER_FIELDS(F) \
    F(string, msr, 1, int) F(string, iar, 2, int) F(string, lr, 3, int) \
    F(string, ctr, 4, int) F(string, fpscr, 5, int) \
    F(repeated_string, fpr, 6, int) F(string, cr, 7, int) \
    F(string, xer, 8, int) F(repeated_string, gpr, 9, int) \
    F(string, vscr, 10, int) F(repeated_string, vr, 11, int)
#define IDR_XENONREGISTER_REQUIRED(F) \
    F(string, msr, 1, int) F(string, iar, 2, int) F(string, lr, 3, int) \
    F(string, ctr, 4, int) F(string, fpscr, 5, int) \
    F(string, cr, 7, int) F(string, xer, 8, int) F(string, vscr, 10, int)
IDR_CLASS(XenonRegisterInfo, IDR_XENONREGISTER_FIELDS, IDR_XENONREGISTER_REQUIRED, IDR_NO_EXTRAS)

#define IDR_PPUREGISTER_FIELDS(F) \
    F(repeated_uint64, gpr, 1, int) F(uint32, cr, 2, int) \
    F(uint64, xer, 3, int) F(uint64, lr, 4, int) F(uint64, ctr, 5, int) \
    F(uint64, pc, 6, int) F(repeated_uint64, fpr, 7, int) \
    F(uint32, fpscr, 8, int) F(repeated_message, vr, 9, BigUInt) \
    F(message, vscr, 10, BigUInt)
#define IDR_PPUREGISTER_REQUIRED(F) \
    F(uint32, cr, 2, int) F(uint64, xer, 3, int) F(uint64, lr, 4, int) \
    F(uint64, ctr, 5, int) F(uint64, pc, 6, int) \
    F(uint32, fpscr, 8, int) F(message, vscr, 10, BigUInt)
IDR_CLASS(PPURegisterInfo, IDR_PPUREGISTER_FIELDS, IDR_PPUREGISTER_REQUIRED, IDR_NO_EXTRAS)

#define IDR_SPUREGISTER_FIELDS(F) \
    F(repeated_message, gpr, 1, BigUInt) F(uint32, npc, 2, int) \
    F(repeated_message, fpscr, 3, BigUInt) F(uint32, srr0, 4, int) \
    F(uint32, spu_status, 5, int) F(uint64, spu_cfg, 6, int) \
    F(uint32, mb_stat, 7, int) F(uint32, ppu_mb, 8, int) \
    F(repeated_uint32, spu_mb, 9, int) F(uint32, decrementer, 10, int) \
    F(repeated_uint64, mfc_cq_sr, 11, int)
#define IDR_SPUREGISTER_REQUIRED(F) \
    F(uint32, npc, 2, int) F(uint32, srr0, 4, int) \
    F(uint32, spu_status, 5, int) F(uint64, spu_cfg, 6, int) \
    F(uint32, mb_stat, 7, int) F(uint32, ppu_mb, 8, int) \
    F(uint32, decrementer, 10, int)
IDR_CLASS(SPURegisterInfo, IDR_SPUREGISTER_FIELDS, IDR_SPUREGISTER_REQUIRED, IDR_NO_EXTRAS)

#define IDR_PS3MEMORY_FIELDS(F) \
    F(uint32, totalsystemmemory, 1, int) F(uint32, usedsystemmemory, 2, int) \
    F(uint32, availablesystemmemory, 3, int) F(uint32, unaccountedfor, 4, int) \
    F(uint32, pmem_total, 5, int) F(uint32, pmem_used, 6, int) \
    F(uint64, page_in, 7, int) F(uint64, page_out, 8, int) \
    F(uint64, page_fault_ppu, 9, int) F(uint64, page_fault_spu, 10, int) \
    F(repeated_message, regions, 11, PS3VMRegionStats)
#define IDR_PS3MEMORY_REQUIRED(F) \
    F(uint32, totalsystemmemory, 1, int) F(uint32, usedsystemmemory, 2, int) \
    F(uint32, availablesystemmemory, 3, int) F(uint32, unaccountedfor, 4, int) \
    F(uint32, pmem_total, 5, int) F(uint32, pmem_used, 6, int) \
    F(uint64, page_in, 7, int) F(uint64, page_out, 8, int) \
    F(uint64, page_fault_ppu, 9, int) F(uint64, page_fault_spu, 10, int)
IDR_CLASS(PS3MemoryInfo, IDR_PS3MEMORY_FIELDS, IDR_PS3MEMORY_REQUIRED, IDR_NO_EXTRAS)

#define IDR_COMMON_CRASH_FIELDS(F) \
    F(string, game, 1, int) F(string, username, 2, int) \
    F(string, platform, 3, int) F(int32, buildnumbermajor, 4, int) \
    F(int32, buildnumberminor, 5, int) F(string, buildstring, 6, int) \
    F(string, timestamp, 7, int) F(string, launchcommand, 8, int) \
    F(string, vtfilepath, 9, int) F(string, vtfilepathvmtroverride, 10, int)

#define IDR_CRASHREPORT_FIELDS(F) \
    IDR_COMMON_CRASH_FIELDS(F) F(string, bugtitle, 11, int) \
    F(string, reprosteps, 12, int) F(string, details, 13, int) \
    F(string, severity, 14, int) F(string, component, 15, int) \
    F(string, mappath, 16, int) F(string, priority, 17, int) \
    F(string, localfilename, 18, int) F(string, dmppath, 19, int) \
    F(repeated_message, callstack, 20, CallstackLine) \
    F(message, exception, 21, ExceptionInfo) F(message, registers, 22, RegisterInfo) \
    F(message, attachment, 23, Attachment) F(message, cpuinfo, 24, CPUInfo) \
    F(message, meminfo, 25, MemoryInfo) \
    F(repeated_string, consolehistory, 26, int)
#define IDR_CRASHREPORT_REQUIRED(F) \
    IDR_COMMON_CRASH_FIELDS(F) F(string, bugtitle, 11, int) \
    F(string, reprosteps, 12, int) F(string, details, 13, int) \
    F(string, severity, 14, int) F(string, component, 15, int) \
    F(string, localfilename, 18, int)
IDR_CLASS(CrashReport, IDR_CRASHREPORT_FIELDS, IDR_CRASHREPORT_REQUIRED, IDR_NO_EXTRAS)

#define IDR_XBOXCRASH_FIELDS(F) \
    IDR_COMMON_CRASH_FIELDS(F) F(string, mappath, 11, int) \
    F(message, kitinfo, 12, Xbox360KitInfo) \
    F(repeated_string, callstack, 13, int) \
    F(message, exception, 14, ExceptionInfo) \
    F(message, registers, 15, XenonRegisterInfo) \
    F(message, consolememory, 16, XenonMemoryInfo) \
    F(message, titlememory, 17, XenonMemoryInfo)
#define IDR_XBOXCRASH_REQUIRED(F) \
    IDR_COMMON_CRASH_FIELDS(F) F(message, kitinfo, 12, Xbox360KitInfo)
IDR_CLASS(Xbox360CrashReport, IDR_XBOXCRASH_FIELDS, IDR_XBOXCRASH_REQUIRED, IDR_NO_EXTRAS)

#define IDR_PS3CRASH_FIELDS(F) \
    IDR_COMMON_CRASH_FIELDS(F) F(string, mappath, 11, int) \
    F(repeated_uint64, callstack, 12, int) \
    F(message, exception, 13, PS3ExceptionInfo) \
    F(message, ppuregisters, 14, PPURegisterInfo) \
    F(repeated_message, spuregisters, 15, SPURegisterInfo) \
    F(message, memoryinfo, 16, PS3MemoryInfo)
#define IDR_PS3CRASH_REQUIRED(F) IDR_COMMON_CRASH_FIELDS(F)
IDR_CLASS(PS3CrashReport, IDR_PS3CRASH_FIELDS, IDR_PS3CRASH_REQUIRED, IDR_NO_EXTRAS)

#define IDR_CRASHRESULT_FIELDS(F) F(int64, bugid, 1, int)
#define IDR_CRASHRESULT_REQUIRED(F) IDR_CRASHRESULT_FIELDS(F)
IDR_CLASS(CrashReportResult, IDR_CRASHRESULT_FIELDS, IDR_CRASHRESULT_REQUIRED, IDR_NO_EXTRAS)

#undef IDR_CLASS
#undef IDR_DECLARE
#undef IDR_KIND
#undef IDR_FACTORY
#undef IDR_REQUIRE

void protobuf_AddDesc_reports_2eproto();
void protobuf_ShutdownFile_reports_2eproto();

} // namespace idreports
