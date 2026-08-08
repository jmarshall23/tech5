#include "idlib/sys/sys_networking.h"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

namespace {

std::mutex networkMutex;
bool networkInitialized = false;
std::vector<std::string> localAddresses;

SOCKET ToSocket(const int value) {
    return static_cast<SOCKET>(static_cast<unsigned int>(value));
}

int FromSocket(const SOCKET value) {
    return static_cast<int>(value);
}

void ClearAddress(netadr_t& address) {
    std::memset(&address, 0, sizeof(address));
    address.type = NA_BAD;
}

void NetAdrToSockAdr(const netadr_t& source, sockaddr_in& destination) {
    std::memset(&destination, 0, sizeof(destination));
    destination.sin_family = AF_INET;
    if (source.type == NA_BROADCAST) {
        destination.sin_addr.s_addr = INADDR_BROADCAST;
    } else {
        std::memcpy(&destination.sin_addr.s_addr, source.ip, sizeof(source.ip));
    }
    destination.sin_port = htons(source.port);
}

void SockAdrToNetAdr(const sockaddr_in& source, netadr_t& destination) {
    std::memset(&destination, 0, sizeof(destination));
    std::memcpy(destination.ip, &source.sin_addr.s_addr, sizeof(destination.ip));
    destination.port = ntohs(source.sin_port);
    destination.type = ntohl(source.sin_addr.s_addr) == INADDR_LOOPBACK
        ? NA_LOOPBACK : NA_IP;
}

bool WaitForSocket(const SOCKET socketValue, const int timeoutMS,
        const bool write) {
    if (socketValue == INVALID_SOCKET) return false;
    fd_set set;
    FD_ZERO(&set);
    FD_SET(socketValue, &set);
    timeval timeout = {};
    timeout.tv_sec = timeoutMS < 0 ? 0 : timeoutMS / 1000;
    timeout.tv_usec = timeoutMS < 0 ? 0 : (timeoutMS % 1000) * 1000;
    const int result = select(0, write ? nullptr : &set,
        write ? &set : nullptr, nullptr, timeoutMS < 0 ? nullptr : &timeout);
    return result > 0 && FD_ISSET(socketValue, &set) != 0;
}

void EnsureNetworking() {
    std::lock_guard<std::mutex> guard(networkMutex);
    if (networkInitialized) return;
    WSADATA data = {};
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
        return;
    }
    networkInitialized = true;

    localAddresses.clear();
    char hostName[256] = {};
    if (gethostname(hostName, sizeof(hostName)) == 0) {
        addrinfo hints = {};
        hints.ai_family = AF_INET;
        addrinfo* result = nullptr;
        if (getaddrinfo(hostName, nullptr, &hints, &result) == 0) {
            for (addrinfo* item = result; item != nullptr; item = item->ai_next) {
                const sockaddr_in* address =
                    reinterpret_cast<const sockaddr_in*>(item->ai_addr);
                char text[INET_ADDRSTRLEN] = {};
                if (inet_ntop(AF_INET, &address->sin_addr, text, sizeof(text))
                        != nullptr
                        && std::find(localAddresses.begin(), localAddresses.end(), text)
                            == localAddresses.end()) {
                    localAddresses.emplace_back(text);
                }
            }
            freeaddrinfo(result);
        }
    }
    if (localAddresses.empty()) localAddresses.emplace_back("127.0.0.1");
}

} // namespace

bool idSimpleSerializer::Serialize(unsigned char& value) {
    if (data == nullptr || pos < 0 || pos + 1 > size) return false;
    if (writing) data[pos] = value;
    else value = data[pos];
    ++pos;
    return true;
}

bool idSimpleSerializer::Serialize(unsigned int& value) {
    if (data == nullptr || pos < 0 || pos + 4 > size) return false;
    if (writing) {
        data[pos + 0] = static_cast<unsigned char>(value >> 0);
        data[pos + 1] = static_cast<unsigned char>(value >> 8);
        data[pos + 2] = static_cast<unsigned char>(value >> 16);
        data[pos + 3] = static_cast<unsigned char>(value >> 24);
    } else {
        value = static_cast<unsigned int>(data[pos + 0])
            | (static_cast<unsigned int>(data[pos + 1]) << 8)
            | (static_cast<unsigned int>(data[pos + 2]) << 16)
            | (static_cast<unsigned int>(data[pos + 3]) << 24);
    }
    pos += 4;
    return true;
}

bool idSimpleSerializer::SerializeBytes(char* bytes, unsigned int& numBytes) {
    const unsigned int capacity = numBytes;
    if (!Serialize(numBytes)) return false;
    if (!writing && numBytes > capacity) {
        numBytes = 0;
        return false;
    }
    if (numBytes > static_cast<unsigned int>(size - pos)
            || (numBytes > 0 && bytes == nullptr)) {
        return false;
    }
    if (writing) std::memcpy(data + pos, bytes, numBytes);
    else std::memcpy(bytes, data + pos, numBytes);
    pos += static_cast<int>(numBytes);
    return true;
}

bool idSimpleSerializer::SerializeString(char* text, const int maxSize) {
    if (text == nullptr || maxSize <= 0) return false;
    unsigned int bytes = writing
        ? static_cast<unsigned int>(std::strlen(text))
        : static_cast<unsigned int>(maxSize - 1);
    if (!SerializeBytes(text, bytes)) return false;
    if (!writing) text[bytes] = '\0';
    return true;
}

void Sys_InitNetworking() {
    EnsureNetworking();
}

void Sys_ShutdownNetworking() {
    std::lock_guard<std::mutex> guard(networkMutex);
    if (!networkInitialized) return;
    localAddresses.clear();
    WSACleanup();
    networkInitialized = false;
}

bool Sys_StringToNetAdr(const char* text, netadr_t* address,
        const bool doDNSResolve) {
    if (text == nullptr || address == nullptr) return false;
    EnsureNetworking();

    std::string host(text);
    unsigned short port = 0;
    const std::size_t separator = host.rfind(':');
    if (separator != std::string::npos) {
        const long parsed = std::strtol(host.c_str() + separator + 1, nullptr, 10);
        if (parsed < 0 || parsed > 65535) return false;
        port = static_cast<unsigned short>(parsed);
        host.resize(separator);
    }
    if (host == "localhost") host = "127.0.0.1";

    sockaddr_in socketAddress = {};
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, host.c_str(), &socketAddress.sin_addr) != 1) {
        if (!doDNSResolve) return false;
        addrinfo hints = {};
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        addrinfo* result = nullptr;
        if (getaddrinfo(host.c_str(), nullptr, &hints, &result) != 0
                || result == nullptr) {
            if (result != nullptr) freeaddrinfo(result);
            return false;
        }
        socketAddress.sin_addr =
            reinterpret_cast<sockaddr_in*>(result->ai_addr)->sin_addr;
        freeaddrinfo(result);
    }
    SockAdrToNetAdr(socketAddress, *address);
    return true;
}

const char* Sys_NetAdrToString(const netadr_t& address) {
    thread_local char result[64];
    const char* prefix = address.type == NA_LOOPBACK ? "127.0.0.1" : nullptr;
    char ipText[INET_ADDRSTRLEN] = {};
    in_addr ipAddress = {};
    std::memcpy(&ipAddress.s_addr, address.ip, sizeof(address.ip));
    if (prefix == nullptr) {
        prefix = inet_ntop(AF_INET, &ipAddress, ipText, sizeof(ipText));
    }
    if (prefix == nullptr) prefix = "0.0.0.0";
    if (address.port != 0) {
        std::snprintf(result, sizeof(result), "%s:%u", prefix, address.port);
    } else {
        std::snprintf(result, sizeof(result), "%s", prefix);
    }
    return result;
}

bool Sys_IsLANAddress(const netadr_t& address) {
    if (address.type == NA_LOOPBACK) return true;
    if (address.type != NA_IP) return false;
    return address.ip[0] == 10
        || (address.ip[0] == 172 && address.ip[1] >= 16 && address.ip[1] <= 31)
        || (address.ip[0] == 192 && address.ip[1] == 168)
        || address.ip[0] == 127;
}

bool Sys_CompareNetAdrBase(const netadr_t& left, const netadr_t& right) {
    if (left.type != right.type) return false;
    if (left.type == NA_LOOPBACK) return true;
    if (left.type != NA_IP && left.type != NA_BROADCAST) return false;
    return std::memcmp(left.ip, right.ip, sizeof(left.ip)) == 0;
}

int Sys_GetLocalIPCount() {
    EnsureNetworking();
    return static_cast<int>(localAddresses.size());
}

const char* Sys_GetLocalIP(const int index) {
    EnsureNetworking();
    return index >= 0 && index < static_cast<int>(localAddresses.size())
        ? localAddresses[index].c_str() : nullptr;
}

idUDP::idUDP()
    : packetsRead(0), bytesRead(0), packetsWritten(0), bytesWritten(0),
      netSocket(0), silent(false) {
    ClearAddress(bound_to);
}

idUDP::~idUDP() { Close(); }

bool idUDP::InitForPort(const int portNumber, const bool) {
    Close();
    EnsureNetworking();
    const SOCKET socketValue = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketValue == INVALID_SOCKET) return false;
    u_long nonBlocking = 1;
    ioctlsocket(socketValue, FIONBIO, &nonBlocking);
    BOOL broadcast = TRUE;
    setsockopt(socketValue, SOL_SOCKET, SO_BROADCAST,
        reinterpret_cast<const char*>(&broadcast), sizeof(broadcast));

    sockaddr_in bindAddress = {};
    bindAddress.sin_family = AF_INET;
    bindAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    bindAddress.sin_port = htons(static_cast<unsigned short>(portNumber));
    if (bind(socketValue, reinterpret_cast<sockaddr*>(&bindAddress),
            sizeof(bindAddress)) == SOCKET_ERROR) {
        closesocket(socketValue);
        return false;
    }
    int addressLength = sizeof(bindAddress);
    getsockname(socketValue, reinterpret_cast<sockaddr*>(&bindAddress), &addressLength);
    SockAdrToNetAdr(bindAddress, bound_to);
    netSocket = FromSocket(socketValue);
    return true;
}

void idUDP::Close() {
    if (netSocket != 0) closesocket(ToSocket(netSocket));
    netSocket = 0;
    ClearAddress(bound_to);
}

bool idUDP::GetPacket(netadr_t& from, void* data, int& dataSize,
        const int maxSize) {
    if (!IsOpen() || data == nullptr || maxSize <= 0) return false;
    sockaddr_in source = {};
    int sourceLength = sizeof(source);
    const int received = recvfrom(ToSocket(netSocket), static_cast<char*>(data),
        maxSize, 0, reinterpret_cast<sockaddr*>(&source), &sourceLength);
    if (received == SOCKET_ERROR) return false;
    SockAdrToNetAdr(source, from);
    dataSize = received;
    ++packetsRead;
    bytesRead += received;
    return true;
}

bool idUDP::GetPacketBlocking(netadr_t& from, void* data, int& dataSize,
        const int maxSize, const int timeoutMS) {
    return WaitForSocket(ToSocket(netSocket), timeoutMS, false)
        && GetPacket(from, data, dataSize, maxSize);
}

void idUDP::SendPacket(const netadr_t to, const void* data, const int dataSize) {
    if (!IsOpen() || data == nullptr || dataSize < 0 || to.type == NA_BAD) return;
    sockaddr_in destination = {};
    NetAdrToSockAdr(to, destination);
    const int sent = sendto(ToSocket(netSocket), static_cast<const char*>(data),
        dataSize, 0, reinterpret_cast<const sockaddr*>(&destination),
        sizeof(destination));
    if (sent >= 0) {
        ++packetsWritten;
        bytesWritten += sent;
    }
}

idTCP::idTCP() : fd(0) { ClearAddress(address); }
idTCP::~idTCP() { Close(); }

bool idTCP::Connect(const char* host, const unsigned short port,
        const bool nonBlocking, const bool, const bool nagle) {
    Close();
    EnsureNetworking();
    if (!Sys_StringToNetAdr(host, &address, true)) return false;
    if (address.port == 0) address.port = port;
    address.type = address.type == NA_LOOPBACK ? NA_LOOPBACK : NA_IP;
    sockaddr_in destination = {};
    NetAdrToSockAdr(address, destination);
    const SOCKET socketValue = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketValue == INVALID_SOCKET) return false;
    BOOL noDelay = nagle ? FALSE : TRUE;
    setsockopt(socketValue, IPPROTO_TCP, TCP_NODELAY,
        reinterpret_cast<const char*>(&noDelay), sizeof(noDelay));
    if (nonBlocking) {
        u_long mode = 1;
        ioctlsocket(socketValue, FIONBIO, &mode);
    }
    const int result = connect(socketValue,
        reinterpret_cast<const sockaddr*>(&destination), sizeof(destination));
    if (result == SOCKET_ERROR) {
        const int error = WSAGetLastError();
        if (!nonBlocking || (error != WSAEWOULDBLOCK
                && error != WSAEINPROGRESS && error != WSAEALREADY)) {
            closesocket(socketValue);
            return false;
        }
    }
    fd = FromSocket(socketValue);
    return true;
}

bool idTCP::Select(const int timeoutMS) {
    return WaitForSocket(ToSocket(fd), timeoutMS, false);
}

bool idTCP::IsOpen() const { return fd != 0; }

void idTCP::Close() {
    if (fd != 0) closesocket(ToSocket(fd));
    fd = 0;
}

int idTCP::Read(void* data, const int dataSize) {
    if (!IsOpen() || data == nullptr || dataSize < 0) return -1;
    const int result = recv(ToSocket(fd), static_cast<char*>(data), dataSize, 0);
    if (result > 0) return result;
    if (result == 0) {
        Close();
        return -2;
    }
    if (WSAGetLastError() == WSAEWOULDBLOCK) return 0;
    Close();
    return -1;
}

int idTCP::ReadBlocking(void* data, const int dataSize, const int timeoutMS) {
    int total = 0;
    while (total < dataSize && WaitForSocket(ToSocket(fd), timeoutMS, false)) {
        const int received = Read(static_cast<char*>(data) + total, dataSize - total);
        if (received < 0) return received;
        total += received;
    }
    return total;
}

int idTCP::Write(const void* data, const int dataSize) {
    if (!IsOpen() || data == nullptr || dataSize < 0) return -1;
    const int result = send(ToSocket(fd), static_cast<const char*>(data), dataSize, 0);
    if (result >= 0) return result;
    if (WSAGetLastError() == WSAEWOULDBLOCK) return 0;
    Close();
    return -1;
}

int idTCP::WriteBlocking(const void* data, const int dataSize, const int timeoutMS) {
    int total = 0;
    while (total < dataSize && WaitForSocket(ToSocket(fd), timeoutMS, true)) {
        const int sent = Write(static_cast<const char*>(data) + total, dataSize - total);
        if (sent < 0) return sent;
        total += sent;
    }
    return total;
}

bool idTCP::WriteDataBlock(const char* buffer, const int dataSize,
        const int timeoutMS) {
    unsigned char lengthData[4] = {};
    unsigned int length = static_cast<unsigned int>(dataSize);
    idSimpleSerializer serializer(lengthData, sizeof(lengthData), true);
    return serializer.Serialize(length)
        && WriteBlocking(lengthData, sizeof(lengthData), timeoutMS)
            == sizeof(lengthData)
        && WriteBlocking(buffer, dataSize, timeoutMS) == dataSize;
}

int idTCP::ReadDataBlock(char* buffer, const int bufferSize,
        const int timeoutMS) {
    unsigned char lengthData[4] = {};
    if (ReadBlocking(lengthData, sizeof(lengthData), timeoutMS)
            != sizeof(lengthData)) return -1;
    unsigned int length = 0;
    idSimpleSerializer serializer(lengthData, sizeof(lengthData), false);
    if (!serializer.Serialize(length) || length > static_cast<unsigned int>(bufferSize)) {
        return -1;
    }
    return ReadBlocking(buffer, static_cast<int>(length), timeoutMS)
        == static_cast<int>(length) ? static_cast<int>(length) : -1;
}
