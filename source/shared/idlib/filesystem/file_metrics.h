#pragma once

// The recovery target still uses Doom 3 BFG's portable idFile implementation
// as its base file layer.  idFile_Metrics retains the tungsten data layout and
// supplies the additional network-backed stream behavior recovered from the
// Xbox 360 executable.
#include "idlib/precompiled.h"

// BFG emulates the C++11 keyword for its original compiler.  Recovery sources
// use the real C++14 keyword and the standard library.
#ifdef nullptr
#undef nullptr
#endif

class idFile_Metrics : public idFile {
public:
    explicit idFile_Metrics(const char* streamName);
    ~idFile_Metrics() override;

    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override;
    int Read(void* buffer, int len) override;
    int Write(const void* buffer, int len) override;
    int Length() const override { return bytesSent; }
    int Tell() const override { return bytesSent; }
    int Seek(long offset, fsOrigin_t origin) override;
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

    // idTech 5 added uniqID to idFile; BFG's portable base predates it.  Keep
    // the field in the same derived-object position to preserve tungsten ABI.
    unsigned int uniqID;
    idStr name;
    mutable idStr fullpath;
    int bytesSent;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idFile_Metrics) == 76,
    "Recovered idFile_Metrics ABI changed");
#endif
