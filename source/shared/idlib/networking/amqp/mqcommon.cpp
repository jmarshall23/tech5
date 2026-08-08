#include "mqcommon.h"

#ifdef nullptr
#undef nullptr
#endif

#include <algorithm>
#include <cstring>

namespace {

unsigned short Swap16(const unsigned short value) {
    return static_cast<unsigned short>((value >> 8) | (value << 8));
}

unsigned int Swap32(const unsigned int value) {
    return ((value & 0x000000FFu) << 24)
        | ((value & 0x0000FF00u) << 8)
        | ((value & 0x00FF0000u) >> 8)
        | ((value & 0xFF000000u) >> 24);
}

} // namespace

amqpEndpoint_t::amqpEndpoint_t()
    : host("localhost"), port(5672), username("guest"), password("guest"),
      vhost("/"), channelMax(0), frameMax(0), heartbeat(0),
      nonBlocking(true), silent(true), minorVersion(0), majorVersion(8) {
}

idMQTCP::idMQTCP() = default;
idMQTCP::~idMQTCP() { Close(); }

bool idMQTCP::Connect(const char* host, const unsigned short port,
        const bool nonBlocking, const bool silent) {
    return tcp.Connect(host, port, nonBlocking, silent, false);
}

void idMQTCP::Close() { tcp.Close(); }
bool idMQTCP::IsOpen() const { return tcp.IsOpen(); }

int idMQTCP::Read(void* data, const int size, const bool blocking,
        const int timeoutMS) {
    return blocking ? tcp.ReadBlocking(data, size, timeoutMS)
                    : tcp.Read(data, size);
}

int idMQTCP::Write(const void* data, const int size, const bool blocking,
        const int timeoutMS) {
    return blocking ? tcp.WriteBlocking(data, size, timeoutMS)
                    : tcp.Write(data, size);
}

int idMQTCP::ReadByte(unsigned char& value, const bool blocking,
        const int timeoutMS) {
    return Read(&value, sizeof(value), blocking, timeoutMS);
}

int idMQTCP::ReadUInt16(unsigned short& value, const bool blocking,
        const int timeoutMS) {
    const int amount = Read(&value, sizeof(value), blocking, timeoutMS);
    if (amount == sizeof(value)) value = Swap16(value);
    return amount;
}

int idMQTCP::ReadUInt32(unsigned int& value, const bool blocking,
        const int timeoutMS) {
    const int amount = Read(&value, sizeof(value), blocking, timeoutMS);
    if (amount == sizeof(value)) value = Swap32(value);
    return amount;
}

idMQBuffer::idMQBuffer() : body(), readPos(0) {}

void idMQBuffer::Clear() {
    body.Clear();
    readPos = 0;
}

void idMQBuffer::WriteData(const void* source, const int size) {
    if (source == nullptr || size <= 0) return;
    const unsigned char* bytes = static_cast<const unsigned char*>(source);
    for (int index = 0; index < size; ++index) body.Append(bytes[index]);
}

void idMQBuffer::WriteUInt16(unsigned short value, const bool bigEndian) {
    if (bigEndian) value = Swap16(value);
    WriteData(&value, sizeof(value));
}

void idMQBuffer::WriteUInt32(unsigned int value, const bool bigEndian) {
    if (bigEndian) value = Swap32(value);
    WriteData(&value, sizeof(value));
}
