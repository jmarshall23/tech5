#include "metricsframework.h"

#include "idlib/sys/sys_time.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <algorithm>
#include <cstdio>
#include <cstring>

namespace {

struct metricSlot_t {
    idMetricsFramework* owner;
    char name[128];
    char path[MAX_PATH];
    idMetricFile file;
};

struct frameworkConfig_t {
    idMetricsFramework* owner;
    char directory[MAX_PATH];
    int heartbeatMilliseconds;
};

metricSlot_t metricSlots[64] = {};
frameworkConfig_t frameworkConfigs[8] = {};

frameworkConfig_t& ConfigFor(idMetricsFramework* owner) {
    for (frameworkConfig_t& config : frameworkConfigs) {
        if (config.owner == owner) return config;
    }
    for (frameworkConfig_t& config : frameworkConfigs) {
        if (config.owner == nullptr) {
            config.owner = owner;
            std::strcpy(config.directory, "metrics");
            config.heartbeatMilliseconds = 250;
            return config;
        }
    }
    return frameworkConfigs[0];
}

void WriteU32(FILE* stream, const std::uint32_t value) {
    std::fwrite(&value, 1, sizeof(value), stream);
}

void WriteString(FILE* stream, const char* text) {
    const std::uint32_t length = static_cast<std::uint32_t>(std::strlen(text));
    WriteU32(stream, length);
    std::fwrite(text, 1, length, stream);
}

void SanitizeName(const char* source, char* destination, const int capacity) {
    int out = 0;
    for (const char* cursor = source; *cursor != '\0' && out + 1 < capacity;
            ++cursor) {
        const unsigned char value = static_cast<unsigned char>(*cursor);
        destination[out++] = (value >= 'a' && value <= 'z')
            || (value >= 'A' && value <= 'Z')
            || (value >= '0' && value <= '9') || value == '-' || value == '_'
            ? static_cast<char>(value) : '_';
    }
    destination[out] = '\0';
}

} // namespace

idMetricsFramework metricsFrameworkLocal;

idMetricsFramework::MachineInfo::MachineInfo()
    : idMetricRecord(idStr("MachineInfo")) {
}

void idMetricsFramework::MachineInfo::WriteHeader(idMetricFile* metricFile) {
    FILE* const stream = metricFile == nullptr ? nullptr
        : static_cast<FILE*>(metricFile->fileHandle);
    if (stream == nullptr) return;
    idMetricRecord::WriteHeader(metricFile);
    WriteU32(stream, 1);
    WriteString(stream, "BuildInfo");
    WriteU32(stream, 6);
}

void idMetricsFramework::MachineInfo::SerializeEntry(idMetricFile* metricFile) {
    FILE* const stream = metricFile == nullptr ? nullptr
        : static_cast<FILE*>(metricFile->fileHandle);
    if (stream == nullptr) return;
    idMetricRecord::SerializeEntry(metricFile);
    WriteString(stream, "tech5-recovery-pc");
}

idMetricsFramework::idMetricsFramework()
    : currentPushTime(0), currentWriteTime(0), currentPushFrame(0),
      lastCheckedPushFrame(0), currentState(0), baseHandle(0),
      isRecording(false), fileTable{nullptr, 256, 0, 255}, stateStream() {
    ConfigFor(this);
}

idMetricsFramework::~idMetricsFramework() {
    MetricsStop();
    for (frameworkConfig_t& config : frameworkConfigs) {
        if (config.owner == this) {
            std::memset(&config, 0, sizeof(config));
            break;
        }
    }
}

std::uint64_t idMetricsFramework::GetCurrentSystemTime() const {
    constexpr std::uint64_t WINDOWS_TO_UNIX_100NS = 116444736000000000ULL;
    const std::uint64_t systemTime = Sys_CurrentSystemTime();
    return systemTime >= WINDOWS_TO_UNIX_100NS
        ? (systemTime - WINDOWS_TO_UNIX_100NS) / 10000ULL : systemTime / 10000ULL;
}

int idMetricsFramework::GetPushFrame() {
    const std::uint64_t now = GetCurrentSystemTime();
    const int heartbeat = ConfigFor(this).heartbeatMilliseconds;
    ++lastCheckedPushFrame;
    if (currentPushTime == 0 || now - currentPushTime >=
            static_cast<std::uint64_t>(std::max(1, heartbeat))) {
        currentPushTime = now;
        currentPushFrame = lastCheckedPushFrame;
    }
    return currentPushFrame;
}

void idMetricsFramework::SetOutputDirectory(const char* directory) {
    frameworkConfig_t& config = ConfigFor(this);
    std::strncpy(config.directory,
        directory == nullptr || directory[0] == '\0' ? "metrics" : directory,
        sizeof(config.directory) - 1);
    config.directory[sizeof(config.directory) - 1] = '\0';
}

void idMetricsFramework::SetHeartbeatMilliseconds(const int milliseconds) {
    ConfigFor(this).heartbeatMilliseconds = std::max(1, milliseconds);
}

void idMetricsFramework::MetricsRecord() {
    isRecording = true;
    MachineInfo machineInfo;
    machineInfo.Serialize();
}

void idMetricsFramework::MetricsStop() {
    if (!isRecording && fileTable.numEntries == 0) return;
    for (metricSlot_t& slot : metricSlots) {
        if (slot.owner == this) {
            if (slot.file.fileHandle != nullptr) {
                std::fclose(static_cast<FILE*>(slot.file.fileHandle));
            }
            slot = metricSlot_t{};
        }
    }
    fileTable.numEntries = 0;
    isRecording = false;
    ++baseHandle;
}

void idMetricsFramework::OpenMetricFile(const idStr& filename,
        idMetricFile& metricFile) {
    frameworkConfig_t& config = ConfigFor(this);
    CreateDirectoryA(config.directory, nullptr);
    char safeName[128] = {};
    SanitizeName(filename.c_str(), safeName, sizeof(safeName));
    char path[MAX_PATH] = {};
    std::snprintf(path, sizeof(path), "%s\\%s.metric", config.directory,
        safeName[0] == '\0' ? "unnamed" : safeName);
    FILE* stream = nullptr;
    if (fopen_s(&stream, path, "wb") == 0) metricFile.fileHandle = stream;
}

idMetricFile* idMetricsFramework::GetFileHandle(const idStr& filename) {
    for (metricSlot_t& slot : metricSlots) {
        if (slot.owner == this && std::strcmp(slot.name, filename.c_str()) == 0) {
            return &slot.file;
        }
    }
    for (metricSlot_t& slot : metricSlots) {
        if (slot.owner == nullptr) {
            slot.owner = this;
            std::strncpy(slot.name, filename.c_str(), sizeof(slot.name) - 1);
            OpenMetricFile(filename, slot.file);
            if (slot.file.fileHandle == nullptr) {
                slot = metricSlot_t{};
                return nullptr;
            }
            ++fileTable.numEntries;
            return &slot.file;
        }
    }
    return nullptr;
}
