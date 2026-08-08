#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <ws2tcpip.h>

#include <cstdint>

#ifndef __SYS_PUBLIC__
enum netadrtype_t {
    NA_BAD = 0,
    NA_LOOPBACK,
    NA_BROADCAST,
    NA_IP
};

struct netadr_t {
    netadrtype_t type;
    unsigned char ip[4];
    unsigned short port;
};
#endif

class idSimpleSerializer {
public:
    idSimpleSerializer(unsigned char* buffer, int bufferSize, bool write)
        : data(buffer), size(bufferSize), pos(0), writing(write) {
    }

    bool Serialize(unsigned char& value);
    bool Serialize(unsigned int& value);
    bool SerializeBytes(char* bytes, unsigned int& numBytes);
    bool SerializeString(char* text, int maxSize);

    int GetPos() const { return pos; }
    int GetSize() const { return size; }
    int GetSerializedSize() const { return writing ? pos : size; }
    bool IsWriting() const { return writing; }

private:
    unsigned char* data;
    int size;
    int pos;
    bool writing;
};

#ifndef __SYS_PUBLIC__
class idUDP {
public:
    idUDP();
    virtual ~idUDP();

    bool InitForPort(int portNumber, bool useBackend = false);
    void Close();
    bool GetPacket(netadr_t& from, void* data, int& size, int maxSize);
    bool GetPacketBlocking(netadr_t& from, void* data, int& size, int maxSize,
        int timeoutMS);
    void SendPacket(netadr_t to, const void* data, int size);

    int GetPort() const { return bound_to.port; }
    netadr_t GetAdr() const { return bound_to; }
    bool IsOpen() const { return netSocket != 0; }
    void SetSilent(bool value) { silent = value; }
    bool GetSilent() const { return silent; }

    int packetsRead;
    int bytesRead;
    int packetsWritten;
    int bytesWritten;

private:
    netadr_t bound_to;
    int netSocket;
    bool silent;
};
#endif

class idTCP {
public:
    idTCP();
    virtual ~idTCP();

    bool Connect(const char* host, unsigned short port, bool nonBlocking = false,
        bool silent = false, bool nagle = true);
    bool Select(int timeoutMS);
    bool IsOpen() const;
    void Close();
    int Read(void* data, int size);
    int ReadBlocking(void* data, int size, int timeoutMS);
    int Write(const void* data, int size);
    int WriteBlocking(const void* data, int size, int timeoutMS);
    bool WriteDataBlock(const char* buffer, int size, int timeoutMS);
    int ReadDataBlock(char* buffer, int bufferSize, int timeoutMS);

    netadr_t GetAddress() const { return address; }

private:
    netadr_t address;
    int fd;
};

#ifndef __SYS_PUBLIC__
void Sys_InitNetworking();
void Sys_ShutdownNetworking();
bool Sys_StringToNetAdr(const char* text, netadr_t* address, bool doDNSResolve);
const char* Sys_NetAdrToString(const netadr_t& address);
bool Sys_IsLANAddress(const netadr_t& address);
bool Sys_CompareNetAdrBase(const netadr_t& left, const netadr_t& right);
int Sys_GetLocalIPCount();
const char* Sys_GetLocalIP(int index);
#endif

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(netadr_t) == 12, "Recovered netadr_t ABI changed");
static_assert(sizeof(idSimpleSerializer) == 16,
    "Recovered idSimpleSerializer ABI changed");
#ifndef __SYS_PUBLIC__
static_assert(sizeof(idUDP) == 40, "Recovered idUDP ABI changed");
#endif
static_assert(sizeof(idTCP) == 20, "Recovered idTCP ABI changed");
#endif
