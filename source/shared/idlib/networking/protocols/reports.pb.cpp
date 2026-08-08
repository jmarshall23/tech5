#include "reports.pb.h"

#include <algorithm>
#include <cstring>
#include <limits>

namespace {

void WriteVarint(std::string& output, std::uint64_t value) {
    while (value >= 0x80) {
        output.push_back(static_cast<char>((value & 0x7f) | 0x80));
        value >>= 7;
    }
    output.push_back(static_cast<char>(value));
}

void WriteTag(std::string& output, const int number, const int wireType) {
    WriteVarint(output, (static_cast<std::uint64_t>(number) << 3) | wireType);
}

void WriteLengthDelimited(std::string& output, const int number,
        const std::string& value) {
    WriteTag(output, number, 2);
    WriteVarint(output, value.size());
    output.append(value);
}

bool ReadVarint(const unsigned char*& cursor, const unsigned char* end,
        std::uint64_t& value) {
    value = 0;
    for (int shift = 0; shift < 70 && cursor < end; shift += 7) {
        const unsigned char byteValue = *cursor++;
        if (shift < 64) value |= static_cast<std::uint64_t>(byteValue & 0x7f)
            << shift;
        if ((byteValue & 0x80) == 0) return shift < 64 || byteValue <= 1;
    }
    return false;
}

bool ReadLength(const unsigned char*& cursor, const unsigned char* end,
        const unsigned char*& fieldEnd) {
    std::uint64_t size = 0;
    if (!ReadVarint(cursor, end, size)
            || size > static_cast<std::uint64_t>(end - cursor)) return false;
    fieldEnd = cursor + static_cast<std::size_t>(size);
    return true;
}

bool SkipField(const int wireType, const unsigned char*& cursor,
        const unsigned char* end) {
    std::uint64_t ignored = 0;
    const unsigned char* fieldEnd = 0;
    switch (wireType) {
        case 0: return ReadVarint(cursor, end, ignored);
        case 1:
            if (end - cursor < 8) return false;
            cursor += 8;
            return true;
        case 2:
            if (!ReadLength(cursor, end, fieldEnd)) return false;
            cursor = fieldEnd;
            return true;
        case 5:
            if (end - cursor < 4) return false;
            cursor += 4;
            return true;
        default: return false;
    }
}

std::shared_ptr<google::protobuf::MessageLite> CloneMessage(
        const std::shared_ptr<google::protobuf::MessageLite>& source) {
    if (!source) return std::shared_ptr<google::protobuf::MessageLite>();
    std::shared_ptr<google::protobuf::MessageLite> result(source->New());
    std::string data;
    if (!source->SerializePartialToString(&data)
            || !result->ParseFromString(data)) {
        return std::shared_ptr<google::protobuf::MessageLite>();
    }
    return result;
}

} // namespace

namespace google {
namespace protobuf {

bool MessageLite::SerializeToArray(void* data, const int size) const {
    return IsInitialized() && SerializePartialToArray(data, size);
}

bool MessageLite::SerializePartialToString(std::string* output) const {
    if (output == 0) return false;
    const int size = ByteSize();
    output->resize(size);
    return size == 0 || SerializePartialToArray(&(*output)[0], size);
}

bool MessageLite::SerializeToString(std::string* output) const {
    return IsInitialized() && SerializePartialToString(output);
}

std::string MessageLite::SerializeAsString() const {
    std::string output;
    SerializeToString(&output);
    return output;
}

bool MessageLite::ParseFromString(const std::string& input) {
    return ParseFromArray(input.data(), static_cast<int>(input.size()));
}

} // namespace protobuf
} // namespace google

namespace idreports {

bool LogEvent_Severity_IsValid(const int value) {
    return value == 80 || value == 70 || value == 60 || value == 50
        || value == 40 || value == 30 || value == 20 || value == 10
        || value == 0;
}

const char* LogEvent_Severity_Name(const LogEvent_Severity value) {
    switch (value) {
        case LogEvent_Severity_SEV_EMERGENCY: return "SEV_EMERGENCY";
        case LogEvent_Severity_SEV_ALERT: return "SEV_ALERT";
        case LogEvent_Severity_SEV_CRITICAL: return "SEV_CRITICAL";
        case LogEvent_Severity_SEV_ERROR: return "SEV_ERROR";
        case LogEvent_Severity_SEV_WARNING: return "SEV_WARNING";
        case LogEvent_Severity_SEV_NOTICE: return "SEV_NOTICE";
        case LogEvent_Severity_SEV_INFO: return "SEV_INFO";
        case LogEvent_Severity_SEV_DEBUG: return "SEV_DEBUG";
        case LogEvent_Severity_SEV_TRASH: return "SEV_TRASH";
        default: return "UNKNOWN";
    }
}

bool TargetPlatform_IsValid(const int value) {
    return value >= TARGET_WIN32 && value <= TARGET_LINUX;
}

const char* TargetPlatform_Name(const TargetPlatform value) {
    static const char* const names[] = {
        "TARGET_WIN32", "TARGET_X64", "TARGET_XBOX360", "TARGET_PS3",
        "TARGET_DURANGO", "TARGET_WIIU", "TARGET_IPHONE", "TARGET_OSX",
        "TARGET_LINUX"
    };
    return TargetPlatform_IsValid(value) ? names[value] : "UNKNOWN";
}

namespace internal {

FieldValue::FieldValue()
    : kind(FIELD_UNKNOWN), integer(0), real(0.0f), text(), message(),
      strings(), integers(), messages() {
}

ReportMessage::ReportMessage() : fields_() {
}

ReportMessage::ReportMessage(const ReportMessage& other) : fields_() {
    MergeFrom(other);
}

ReportMessage& ReportMessage::operator=(const ReportMessage& other) {
    if (this != &other) CopyFrom(other);
    return *this;
}

ReportMessage::~ReportMessage() {
}

void ReportMessage::Clear() {
    fields_.clear();
}

bool ReportMessage::HasField(const int number) const {
    return fields_.find(number) != fields_.end();
}

void ReportMessage::ClearField(const int number) {
    fields_.erase(number);
}

std::uint64_t ReportMessage::GetInteger(const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0 : found->second.integer;
}

void ReportMessage::SetInteger(const int number, const FieldKind kind,
        const std::uint64_t value) {
    FieldValue& field = fields_[number];
    field.kind = kind;
    field.integer = value;
}

float ReportMessage::GetFloat(const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0.0f : found->second.real;
}

void ReportMessage::SetFloat(const int number, const float value) {
    FieldValue& field = fields_[number];
    field.kind = FIELD_FLOAT;
    field.real = value;
}

const std::string& ReportMessage::GetString(const int number) const {
    static const std::string empty;
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? empty : found->second.text;
}

std::string* ReportMessage::MutableString(const int number) {
    FieldValue& field = fields_[number];
    field.kind = FIELD_STRING;
    return &field.text;
}

std::string* ReportMessage::ReleaseString(const int number) {
    const std::map<int, FieldValue>::iterator found = fields_.find(number);
    if (found == fields_.end()) return 0;
    std::string* result = new std::string(found->second.text);
    fields_.erase(found);
    return result;
}

void ReportMessage::SetString(const int number, const char* value,
        const std::size_t size) {
    FieldValue& field = fields_[number];
    field.kind = FIELD_STRING;
    field.text.assign(value == 0 ? "" : value, value == 0 ? 0 : size);
}

int ReportMessage::RepeatedIntegerSize(const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0
        : static_cast<int>(found->second.integers.size());
}

std::uint64_t ReportMessage::GetRepeatedInteger(const int number,
        const int index) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() || index < 0
        || index >= static_cast<int>(found->second.integers.size())
        ? 0 : found->second.integers[index];
}

void ReportMessage::SetRepeatedInteger(const int number, const int index,
        const FieldKind kind, const std::uint64_t value) {
    FieldValue& field = fields_[number];
    field.kind = kind;
    if (index >= 0 && index < static_cast<int>(field.integers.size())) {
        field.integers[index] = value;
    }
}

void ReportMessage::AddRepeatedInteger(const int number, const FieldKind kind,
        const std::uint64_t value) {
    FieldValue& field = fields_[number];
    field.kind = kind;
    field.integers.push_back(value);
}

int ReportMessage::RepeatedStringSize(const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0
        : static_cast<int>(found->second.strings.size());
}

const std::string& ReportMessage::GetRepeatedString(const int number,
        const int index) const {
    static const std::string empty;
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() || index < 0
        || index >= static_cast<int>(found->second.strings.size())
        ? empty : found->second.strings[index];
}

std::string* ReportMessage::MutableRepeatedString(const int number,
        const int index) {
    const std::map<int, FieldValue>::iterator found = fields_.find(number);
    return found == fields_.end() || index < 0
        || index >= static_cast<int>(found->second.strings.size())
        ? 0 : &found->second.strings[index];
}

std::string* ReportMessage::AddRepeatedString(const int number) {
    FieldValue& field = fields_[number];
    field.kind = FIELD_REPEATED_STRING;
    field.strings.push_back(std::string());
    return &field.strings.back();
}

void ReportMessage::SetRepeatedString(const int number, const int index,
        const char* value, const std::size_t size) {
    std::string* item = MutableRepeatedString(number, index);
    if (item != 0) item->assign(value == 0 ? "" : value,
        value == 0 ? 0 : size);
}

int ReportMessage::RepeatedMessageSize(const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0
        : static_cast<int>(found->second.messages.size());
}

const google::protobuf::MessageLite* ReportMessage::GetRepeatedMessage(
        const int number, const int index) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() || index < 0
        || index >= static_cast<int>(found->second.messages.size())
        ? 0 : found->second.messages[index].get();
}

google::protobuf::MessageLite* ReportMessage::MutableRepeatedMessage(
        const int number, const int index) {
    const std::map<int, FieldValue>::iterator found = fields_.find(number);
    return found == fields_.end() || index < 0
        || index >= static_cast<int>(found->second.messages.size())
        ? 0 : found->second.messages[index].get();
}

google::protobuf::MessageLite* ReportMessage::AddRepeatedMessage(
        const int number) {
    std::shared_ptr<google::protobuf::MessageLite> value(
        NewMessageForField(number));
    if (!value) return 0;
    FieldValue& field = fields_[number];
    field.kind = FIELD_REPEATED_MESSAGE;
    field.messages.push_back(value);
    return value.get();
}

const google::protobuf::MessageLite* ReportMessage::GetMessage(
        const int number) const {
    const std::map<int, FieldValue>::const_iterator found = fields_.find(number);
    return found == fields_.end() ? 0 : found->second.message.get();
}

google::protobuf::MessageLite* ReportMessage::MutableMessage(const int number) {
    FieldValue& field = fields_[number];
    field.kind = FIELD_MESSAGE;
    if (!field.message) field.message.reset(NewMessageForField(number));
    return field.message.get();
}

google::protobuf::MessageLite* ReportMessage::ReleaseMessage(const int number) {
    const std::map<int, FieldValue>::iterator found = fields_.find(number);
    if (found == fields_.end() || !found->second.message) return 0;
    google::protobuf::MessageLite* result = found->second.message->New();
    std::string data;
    found->second.message->SerializePartialToString(&data);
    result->ParseFromString(data);
    fields_.erase(found);
    return result;
}

void ReportMessage::SetAllocatedMessage(const int number,
        google::protobuf::MessageLite* value) {
    if (value == 0) {
        ClearField(number);
        return;
    }
    FieldValue& field = fields_[number];
    field.kind = FIELD_MESSAGE;
    field.message.reset(value);
}

google::protobuf::MessageLite* ReportMessage::NewMessageForField(int) const {
    return 0;
}

bool ReportMessage::IsInitialized() const {
    if (!HasRequiredFields()) return false;
    for (std::map<int, FieldValue>::const_iterator field = fields_.begin();
            field != fields_.end(); ++field) {
        if (field->second.message && !field->second.message->IsInitialized()) {
            return false;
        }
        for (std::size_t index = 0; index < field->second.messages.size();
                ++index) {
            if (field->second.messages[index]
                    && !field->second.messages[index]->IsInitialized()) {
                return false;
            }
        }
    }
    return true;
}

bool ReportMessage::Serialize(std::string& output) const {
    output.clear();
    for (std::map<int, FieldValue>::const_iterator iterator = fields_.begin();
            iterator != fields_.end(); ++iterator) {
        const int number = iterator->first;
        const FieldValue& field = iterator->second;
        switch (field.kind) {
            case FIELD_STRING:
                WriteLengthDelimited(output, number, field.text);
                break;
            case FIELD_UINT32:
            case FIELD_UINT64:
            case FIELD_INT32:
            case FIELD_INT64:
            case FIELD_ENUM:
            case FIELD_BOOL:
                WriteTag(output, number, 0);
                WriteVarint(output, field.integer);
                break;
            case FIELD_FLOAT: {
                WriteTag(output, number, 5);
                std::uint32_t bits = 0;
                std::memcpy(&bits, &field.real, sizeof(bits));
                output.push_back(static_cast<char>(bits));
                output.push_back(static_cast<char>(bits >> 8));
                output.push_back(static_cast<char>(bits >> 16));
                output.push_back(static_cast<char>(bits >> 24));
                break;
            }
            case FIELD_MESSAGE:
                if (field.message) {
                    std::string nested;
                    field.message->SerializePartialToString(&nested);
                    WriteLengthDelimited(output, number, nested);
                }
                break;
            case FIELD_REPEATED_STRING:
                for (std::size_t index = 0; index < field.strings.size(); ++index) {
                    WriteLengthDelimited(output, number, field.strings[index]);
                }
                break;
            case FIELD_REPEATED_UINT32:
            case FIELD_REPEATED_UINT64:
                for (std::size_t index = 0; index < field.integers.size(); ++index) {
                    WriteTag(output, number, 0);
                    WriteVarint(output, field.integers[index]);
                }
                break;
            case FIELD_REPEATED_MESSAGE:
                for (std::size_t index = 0; index < field.messages.size(); ++index) {
                    if (field.messages[index]) {
                        std::string nested;
                        field.messages[index]->SerializePartialToString(&nested);
                        WriteLengthDelimited(output, number, nested);
                    }
                }
                break;
            default: break;
        }
    }
    return true;
}

int ReportMessage::ByteSize() const {
    std::string output;
    Serialize(output);
    return static_cast<int>(output.size());
}

bool ReportMessage::SerializePartialToArray(void* data, const int size) const {
    if (size < 0 || (data == 0 && size != 0)) return false;
    std::string output;
    Serialize(output);
    if (size < static_cast<int>(output.size())) return false;
    if (!output.empty()) std::memcpy(data, output.data(), output.size());
    return true;
}

bool ReportMessage::ParseFromArray(const void* data, const int size) {
    if (size < 0 || (data == 0 && size != 0)) return false;
    Clear();
    const unsigned char* cursor = static_cast<const unsigned char*>(data);
    const unsigned char* const end = cursor + size;
    while (cursor < end) {
        std::uint64_t tag = 0;
        if (!ReadVarint(cursor, end, tag) || tag == 0) return false;
        const int number = static_cast<int>(tag >> 3);
        const int wireType = static_cast<int>(tag & 7);
        const FieldKind kind = FieldKindForNumber(number);
        if (kind == FIELD_UNKNOWN) {
            if (!SkipField(wireType, cursor, end)) return false;
            continue;
        }

        std::uint64_t integer = 0;
        const unsigned char* fieldEnd = 0;
        if (kind == FIELD_STRING || kind == FIELD_REPEATED_STRING
                || kind == FIELD_MESSAGE || kind == FIELD_REPEATED_MESSAGE) {
            if (wireType != 2 || !ReadLength(cursor, end, fieldEnd)) return false;
            if (kind == FIELD_STRING) {
                SetString(number, reinterpret_cast<const char*>(cursor),
                    static_cast<std::size_t>(fieldEnd - cursor));
            } else if (kind == FIELD_REPEATED_STRING) {
                std::string* item = AddRepeatedString(number);
                item->assign(reinterpret_cast<const char*>(cursor),
                    static_cast<std::size_t>(fieldEnd - cursor));
            } else {
                google::protobuf::MessageLite* nested = kind == FIELD_MESSAGE
                    ? MutableMessage(number) : AddRepeatedMessage(number);
                if (nested == 0 || !nested->ParseFromArray(cursor,
                        static_cast<int>(fieldEnd - cursor))) return false;
            }
            cursor = fieldEnd;
        } else if (kind == FIELD_FLOAT) {
            if (wireType != 5 || end - cursor < 4) return false;
            const std::uint32_t bits = static_cast<std::uint32_t>(cursor[0])
                | (static_cast<std::uint32_t>(cursor[1]) << 8)
                | (static_cast<std::uint32_t>(cursor[2]) << 16)
                | (static_cast<std::uint32_t>(cursor[3]) << 24);
            float value = 0.0f;
            std::memcpy(&value, &bits, sizeof(value));
            SetFloat(number, value);
            cursor += 4;
        } else if ((kind == FIELD_REPEATED_UINT32
                || kind == FIELD_REPEATED_UINT64) && wireType == 2) {
            if (!ReadLength(cursor, end, fieldEnd)) return false;
            while (cursor < fieldEnd) {
                if (!ReadVarint(cursor, fieldEnd, integer)) return false;
                AddRepeatedInteger(number, kind, integer);
            }
        } else {
            if (wireType != 0 || !ReadVarint(cursor, end, integer)) return false;
            if (kind == FIELD_REPEATED_UINT32
                    || kind == FIELD_REPEATED_UINT64) {
                AddRepeatedInteger(number, kind, integer);
            } else {
                SetInteger(number, kind, integer);
            }
        }
    }
    return true;
}

void ReportMessage::CopyFrom(const google::protobuf::MessageLite& other) {
    Clear();
    MergeFrom(other);
}

void ReportMessage::MergeFrom(const google::protobuf::MessageLite& other) {
    const ReportMessage* source = dynamic_cast<const ReportMessage*>(&other);
    if (source == 0 || source == this || source->GetTypeName() != GetTypeName()) {
        return;
    }
    for (std::map<int, FieldValue>::const_iterator iterator =
            source->fields_.begin(); iterator != source->fields_.end(); ++iterator) {
        const FieldValue& incoming = iterator->second;
        FieldValue& destination = fields_[iterator->first];
        if (incoming.kind == FIELD_REPEATED_STRING) {
            destination.kind = incoming.kind;
            destination.strings.insert(destination.strings.end(),
                incoming.strings.begin(), incoming.strings.end());
        } else if (incoming.kind == FIELD_REPEATED_UINT32
                || incoming.kind == FIELD_REPEATED_UINT64) {
            destination.kind = incoming.kind;
            destination.integers.insert(destination.integers.end(),
                incoming.integers.begin(), incoming.integers.end());
        } else if (incoming.kind == FIELD_REPEATED_MESSAGE) {
            destination.kind = incoming.kind;
            for (std::size_t index = 0; index < incoming.messages.size(); ++index) {
                destination.messages.push_back(CloneMessage(incoming.messages[index]));
            }
        } else {
            destination = incoming;
            if (incoming.message) destination.message = CloneMessage(incoming.message);
        }
    }
}

void ReportMessage::Swap(ReportMessage* other) {
    if (other != 0) fields_.swap(other->fields_);
}

} // namespace internal

void protobuf_AddDesc_reports_2eproto() {
}

void protobuf_ShutdownFile_reports_2eproto() {
}

} // namespace idreports

