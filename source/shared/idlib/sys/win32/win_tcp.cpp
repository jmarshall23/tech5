#include "idlib/sys/sys_networking.h"

#include <cstring>

namespace {

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
        std::memcpy(&destination.sin_addr.s_addr, source.ip,
            sizeof(source.ip));
    }
    destination.sin_port = htons(source.port);
}

bool WaitForSocket(const SOCKET socketValue, const int timeoutMS,
        const bool write) {
    if (socketValue == INVALID_SOCKET) {
        return false;
    }
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

} // namespace

bool idSimpleSerializer::Serialize(unsigned char& value) {
    if (data == nullptr || pos < 0 || pos + 1 > size) {
        return false;
    }
    if (writing) {
        data[pos] = value;
    } else {
        value = data[pos];
    }
    ++pos;
    return true;
}

bool idSimpleSerializer::Serialize(unsigned int& value) {
    if (data == nullptr || pos < 0 || pos + 4 > size) {
        return false;
    }
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

bool idSimpleSerializer::SerializeBytes(char* bytes,
        unsigned int& numBytes) {
    const unsigned int capacity = numBytes;
    if (!Serialize(numBytes)) {
        return false;
    }
    if (!writing && numBytes > capacity) {
        numBytes = 0;
        return false;
    }
    if (numBytes > static_cast<unsigned int>(size - pos)
            || (numBytes > 0 && bytes == nullptr)) {
        return false;
    }
    if (writing) {
        std::memcpy(data + pos, bytes, numBytes);
    } else {
        std::memcpy(bytes, data + pos, numBytes);
    }
    pos += static_cast<int>(numBytes);
    return true;
}

bool idSimpleSerializer::SerializeString(char* text, const int maxSize) {
    if (text == nullptr || maxSize <= 0) {
        return false;
    }
    unsigned int bytes = writing
        ? static_cast<unsigned int>(std::strlen(text))
        : static_cast<unsigned int>(maxSize - 1);
    if (!SerializeBytes(text, bytes)) {
        return false;
    }
    if (!writing) {
        text[bytes] = '\0';
    }
    return true;
}

idTCP::idTCP() : fd(0) {
    ClearAddress(address);
}

idTCP::~idTCP() {
    Close();
}

bool idTCP::Connect(const char* host, const unsigned short port,
        const bool nonBlocking, const bool, const bool nagle) {
    Close();
    Sys_InitNetworking();
    if (!Sys_StringToNetAdr(host, &address, true)) {
        return false;
    }
    if (address.port == 0) {
        address.port = port;
    }
    address.type = address.type == NA_LOOPBACK ? NA_LOOPBACK : NA_IP;

    sockaddr_in destination = {};
    NetAdrToSockAdr(address, destination);
    const SOCKET socketValue = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketValue == INVALID_SOCKET) {
        return false;
    }

    const BOOL noDelay = nagle ? FALSE : TRUE;
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

bool idTCP::IsOpen() const {
    return fd != 0;
}

void idTCP::Close() {
    if (fd != 0) {
        closesocket(ToSocket(fd));
    }
    fd = 0;
}

int idTCP::Read(void* data, const int dataSize) {
    if (!IsOpen() || data == nullptr || dataSize < 0) {
        return -1;
    }
    const int result = recv(ToSocket(fd), static_cast<char*>(data), dataSize, 0);
    if (result > 0) {
        return result;
    }
    if (result == 0) {
        Close();
        return -2;
    }
    if (WSAGetLastError() == WSAEWOULDBLOCK) {
        return 0;
    }
    Close();
    return -1;
}

int idTCP::ReadBlocking(void* data, const int dataSize,
        const int timeoutMS) {
    int total = 0;
    while (total < dataSize && WaitForSocket(ToSocket(fd), timeoutMS, false)) {
        const int received = Read(static_cast<char*>(data) + total,
            dataSize - total);
        if (received < 0) {
            return received;
        }
        total += received;
    }
    return total;
}

int idTCP::Write(const void* data, const int dataSize) {
    if (!IsOpen() || data == nullptr || dataSize < 0) {
        return -1;
    }
    const int result = send(ToSocket(fd), static_cast<const char*>(data),
        dataSize, 0);
    if (result >= 0) {
        return result;
    }
    if (WSAGetLastError() == WSAEWOULDBLOCK) {
        return 0;
    }
    Close();
    return -1;
}

int idTCP::WriteBlocking(const void* data, const int dataSize,
        const int timeoutMS) {
    int total = 0;
    while (total < dataSize && WaitForSocket(ToSocket(fd), timeoutMS, true)) {
        const int sent = Write(static_cast<const char*>(data) + total,
            dataSize - total);
        if (sent < 0) {
            return sent;
        }
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
            != sizeof(lengthData)) {
        return -1;
    }
    unsigned int length = 0;
    idSimpleSerializer serializer(lengthData, sizeof(lengthData), false);
    if (!serializer.Serialize(length)
            || length > static_cast<unsigned int>(bufferSize)) {
        return -1;
    }
    return ReadBlocking(buffer, static_cast<int>(length), timeoutMS)
        == static_cast<int>(length) ? static_cast<int>(length) : -1;
}
