#include "metricrecord.h"

#include "metricsframework.h"

#include <cstdio>
#include <cstring>

namespace {

FILE* MetricStream(idMetricFile* metricFile) {
    return metricFile == nullptr ? nullptr
        : static_cast<FILE*>(metricFile->fileHandle);
}

void WriteU32(FILE* stream, const std::uint32_t value) {
    unsigned char bytes[4] = {
        static_cast<unsigned char>(value >> 0),
        static_cast<unsigned char>(value >> 8),
        static_cast<unsigned char>(value >> 16),
        static_cast<unsigned char>(value >> 24)
    };
    std::fwrite(bytes, 1, sizeof(bytes), stream);
}

void WriteU64(FILE* stream, const std::uint64_t value) {
    WriteU32(stream, static_cast<std::uint32_t>(value));
    WriteU32(stream, static_cast<std::uint32_t>(value >> 32));
}

void WriteString(FILE* stream, const char* text) {
    const char* const safeText = text == nullptr ? "" : text;
    const std::uint32_t length = static_cast<std::uint32_t>(std::strlen(safeText));
    WriteU32(stream, length);
    if (length > 0) std::fwrite(safeText, 1, length, stream);
}

} // namespace

idMetricRecord::idMetricRecord(const idStr& recordName)
    : name(recordName), baseName(recordName) {
}

void idMetricRecord::WriteHeader(idMetricFile* metricFile) {
    FILE* const stream = MetricStream(metricFile);
    if (stream == nullptr) return;
    WriteU32(stream, 1);
    WriteString(stream, "entryTime");
    WriteU32(stream, 0);
}

void idMetricRecord::SerializeEntry(idMetricFile* metricFile) {
    FILE* const stream = MetricStream(metricFile);
    if (stream == nullptr) return;
    const std::uint64_t now = metricsFrameworkLocal.GetCurrentSystemTime();
    WriteU32(stream, static_cast<std::uint32_t>(now - metricFile->startTime));
}

void idMetricRecord::AppendToName(const idStr& suffix) {
    name = baseName;
    name.Append(suffix);
}

void idMetricFile::WriteFileInfo(const idStr& metricName) {
    FILE* const stream = MetricStream(this);
    if (stream == nullptr) return;
    startTime = metricsFrameworkLocal.GetCurrentSystemTime();
    WriteString(stream, "IDMETRIC");
    WriteU32(stream, 1);
    WriteString(stream, metricName.c_str());
    WriteU64(stream, startTime);
}

void idMetricRecord::Serialize() {
    if (!metricsFrameworkLocal.IsRecording()) return;
    idMetricFile* const metricFile = metricsFrameworkLocal.GetFileHandle(name);
    if (metricFile == nullptr || metricFile->fileHandle == nullptr) return;
    if (!metricFile->headerWritten) {
        metricFile->headerWritten = true;
        metricFile->WriteFileInfo(name);
        WriteHeader(metricFile);
    }
    SerializeEntry(metricFile);
}

