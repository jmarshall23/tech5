#include "file_metrics.h"

#include "idlib/sys/sys_networking.h"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace {

idTCP metricsTCP;
unsigned char* sendQueue = nullptr;
int sendQueueSize = 0;
int sendIndex = 0;
int pendingIndex = 0;
char metricsServer[256] = "127.0.0.1";
unsigned short metricsPort = 8012;
int initialRetryTime = 1000;
int maximumRetryTime = 60000;
int retryTime = 0;
std::uint64_t timeoutWait = 0;
std::mutex metricsMutex;

std::uint64_t Milliseconds() {
    using namespace std::chrono;
    return static_cast<std::uint64_t>(duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()).count());
}

void PutUInt32LE(unsigned char* output, const unsigned int value) {
    output[0] = static_cast<unsigned char>(value);
    output[1] = static_cast<unsigned char>(value >> 8);
    output[2] = static_cast<unsigned char>(value >> 16);
    output[3] = static_cast<unsigned char>(value >> 24);
}

int StringBytes(const char* text) {
    return static_cast<int>(std::strlen(text == nullptr ? "" : text)) + 1;
}

} // namespace

idFile_Metrics::idFile_Metrics(const char* streamName)
    : uniqID(0), name(streamName == nullptr ? "" : streamName), bytesSent(0) {
}

idFile_Metrics::~idFile_Metrics() {
    CloseMetricsStream(name.c_str());
}

const char* idFile_Metrics::GetFullPath() const {
    const netadr_t address = metricsTCP.GetAddress();
    if (metricsTCP.IsOpen()) {
        fullpath.Format("metrics://%u.%u.%u.%u:%u/%s",
            static_cast<unsigned int>(address.ip[0]),
            static_cast<unsigned int>(address.ip[1]),
            static_cast<unsigned int>(address.ip[2]),
            static_cast<unsigned int>(address.ip[3]),
            static_cast<unsigned int>(address.port), name.c_str());
    } else {
        fullpath.Format("metrics://%s:%u/%s", metricsServer,
            static_cast<unsigned int>(metricsPort), name.c_str());
    }
    return fullpath.c_str();
}

int idFile_Metrics::Read(void*, int) {
    return 0;
}

int idFile_Metrics::Write(const void* buffer, const int len) {
    const int written = WriteInternal(name.c_str(), buffer, len);
    bytesSent += written;
    return written;
}

int idFile_Metrics::Seek(long, fsOrigin_t) {
    return -1;
}

void idFile_Metrics::Flush() {
    std::lock_guard<std::mutex> lock(metricsMutex);
    bool queueTraffic = false;
    FlushBufferedWrites(queueTraffic);
}

void idFile_Metrics::ForceFlush() {
    Flush();
}

idFile_Metrics* idFile_Metrics::OpenMetricsStream(const char* streamName) {
    return new idFile_Metrics(streamName);
}

void idFile_Metrics::CloseMetricsStream(const char* streamName) {
    std::lock_guard<std::mutex> lock(metricsMutex);
    if (!metricsTCP.IsOpen()) return;

    bool queueTraffic = false;
    FlushBufferedWrites(queueTraffic);

    static const char control[] = "CONTROL";
    static const char close[] = "CLOSE";
    const char* const safeName = streamName == nullptr ? "" : streamName;
    const int payloadSize = static_cast<int>(sizeof(control) + sizeof(close))
        + StringBytes(safeName);
    unsigned char prefix[4] = {};
    PutUInt32LE(prefix, static_cast<unsigned int>(payloadSize));
    BufferedWriteInternal(queueTraffic, prefix, sizeof(prefix));
    BufferedWriteInternal(queueTraffic, control, sizeof(control));
    BufferedWriteInternal(queueTraffic, close, sizeof(close));
    BufferedWriteInternal(queueTraffic, safeName, StringBytes(safeName));
    if (!queueTraffic) FlushBufferedWrites(queueTraffic);
}

void idFile_Metrics::ConfigureServer(const char* host, const unsigned short port,
        const int initialRetryMilliseconds,
        const int maximumRetryMilliseconds) {
    std::lock_guard<std::mutex> lock(metricsMutex);
    metricsTCP.Close();
    const char* const safeHost = host == nullptr || *host == '\0'
        ? "127.0.0.1" : host;
    std::strncpy(metricsServer, safeHost, sizeof(metricsServer) - 1);
    metricsServer[sizeof(metricsServer) - 1] = '\0';
    metricsPort = port;
    initialRetryTime = std::max(1, initialRetryMilliseconds);
    maximumRetryTime = std::max(initialRetryTime, maximumRetryMilliseconds);
    retryTime = 0;
    timeoutWait = 0;
    sendIndex = pendingIndex = 0;
}

void idFile_Metrics::ShutdownTransport() {
    std::lock_guard<std::mutex> lock(metricsMutex);
    metricsTCP.Close();
    std::free(sendQueue);
    sendQueue = nullptr;
    sendQueueSize = sendIndex = pendingIndex = 0;
    retryTime = 0;
    timeoutWait = 0;
}

bool idFile_Metrics::EnsureConnection() {
    if (metricsTCP.IsOpen()) return true;
    if (Milliseconds() < timeoutWait || metricsPort == 0) return false;

    // A blocking connect gives the PC port a definite connected state.  All
    // subsequent writes retain the non-blocking short-write queue semantics.
    if (metricsTCP.Connect(metricsServer, metricsPort, false, true, true)) {
        retryTime = 0;
        timeoutWait = 0;
        return true;
    }

    retryTime = retryTime == 0 ? initialRetryTime
        : std::min(maximumRetryTime, retryTime * 2);
    timeoutWait = Milliseconds() + static_cast<std::uint64_t>(retryTime);
    return false;
}

void idFile_Metrics::WriteToQueue(const void* buffer, const int len) {
    if (buffer == nullptr || len <= 0) return;
    const int retained = pendingIndex - sendIndex;
    const int required = retained + len;
    if (required > sendQueueSize) {
        int newSize = std::max(1024, sendQueueSize);
        while (newSize < required) newSize *= 2;
        unsigned char* const replacement = static_cast<unsigned char*>(
            std::malloc(static_cast<std::size_t>(newSize)));
        if (replacement == nullptr) return;
        if (retained > 0) {
            std::memcpy(replacement, sendQueue + sendIndex,
                static_cast<std::size_t>(retained));
        }
        std::free(sendQueue);
        sendQueue = replacement;
        sendQueueSize = newSize;
        sendIndex = 0;
        pendingIndex = retained;
    } else if (sendIndex > 0 && pendingIndex + len > sendQueueSize) {
        if (retained > 0) {
            std::memmove(sendQueue, sendQueue + sendIndex,
                static_cast<std::size_t>(retained));
        }
        sendIndex = 0;
        pendingIndex = retained;
    }
    std::memcpy(sendQueue + pendingIndex, buffer, static_cast<std::size_t>(len));
    pendingIndex += len;
}

void idFile_Metrics::BufferedWriteInternal(bool& queueTraffic,
        const void* buffer, const int len) {
    if (buffer == nullptr || len <= 0) return;
    if (queueTraffic) {
        WriteToQueue(buffer, len);
        return;
    }
    const int written = metricsTCP.Write(buffer, len);
    const int validWritten = std::max(0, written);
    if (written != len) {
        queueTraffic = true;
        WriteToQueue(static_cast<const unsigned char*>(buffer) + validWritten,
            len - validWritten);
    }
}

void idFile_Metrics::FlushBufferedWrites(bool& queueTraffic) {
    if (!metricsTCP.IsOpen() || sendIndex >= pendingIndex) {
        if (sendIndex >= pendingIndex) sendIndex = pendingIndex = 0;
        return;
    }
    const int available = pendingIndex - sendIndex;
    const int written = metricsTCP.Write(sendQueue + sendIndex, available);
    if (written > 0) sendIndex += written;
    if (written < available) queueTraffic = true;
    if (sendIndex >= pendingIndex) sendIndex = pendingIndex = 0;
}

void idFile_Metrics::WriteFrame(bool& queueTraffic, const char* streamName,
        const void* buffer, const int len) {
    const char* const safeName = streamName == nullptr ? "" : streamName;
    const int nameBytes = StringBytes(safeName);
    unsigned char prefix[4] = {};
    PutUInt32LE(prefix, static_cast<unsigned int>(nameBytes + len));
    BufferedWriteInternal(queueTraffic, prefix, sizeof(prefix));
    BufferedWriteInternal(queueTraffic, safeName, nameBytes);
    BufferedWriteInternal(queueTraffic, buffer, len);
}

int idFile_Metrics::WriteInternal(const char* streamName,
        const void* buffer, const int len) {
    if (buffer == nullptr || len <= 0) return 0;
    std::lock_guard<std::mutex> lock(metricsMutex);
    if (!EnsureConnection()) return 0;

    bool queueTraffic = false;
    FlushBufferedWrites(queueTraffic);
    WriteFrame(queueTraffic, streamName, buffer, len);
    return len;
}
