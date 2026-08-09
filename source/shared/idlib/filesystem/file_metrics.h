#pragma once

#include "file.h"

class idFile_Metrics : public idFile {
public:
    explicit idFile_Metrics(const char* streamName);
    ~idFile_Metrics() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override;
    unsigned int Read(void* buffer, unsigned int len) override;
    unsigned int Write(const void* buffer, unsigned int len) override;
    std::int64_t Length() const override { return bytesSent; }
    std::int64_t Tell() const override { return bytesSent; }
    int Seek(std::int64_t offset, fsOrigin_t origin) override;
    void Flush() override;
    void ForceFlush() override;

    static idFile_Metrics* OpenMetricsStream(const char* streamName);
    static void CloseMetricsStream(const char* streamName);

    // PC recovery controls.  The original values came from metrics_* CVars.
    static void ConfigureServer(const char* host, unsigned short port,
        int initialRetryMilliseconds = 1000,
        int maximumRetryMilliseconds = 60000);
    static void ShutdownTransport();

private:
    static int WriteInternal(const char* streamName, const void* buffer, int len);
    static void WriteToQueue(const void* buffer, int len);
    static void BufferedWriteInternal(bool& queueTraffic,
        const void* buffer, int len);
    static void FlushBufferedWrites(bool& queueTraffic);
    static bool EnsureConnection();
    static void WriteFrame(bool& queueTraffic, const char* streamName,
        const void* buffer, int len);

    idStr name;
    mutable idStr fullpath;
    int bytesSent;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_Metrics) == 76,
    "Recovered idFile_Metrics ABI changed");
#endif
