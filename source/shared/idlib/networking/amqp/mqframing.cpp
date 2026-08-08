#include "mqcommon.h"

#ifdef nullptr
#undef nullptr
#endif
#ifdef snprintf
#undef snprintf
#endif

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

void StoreUInt32BE(unsigned char* destination, const unsigned int value) {
    destination[0] = static_cast<unsigned char>(value >> 24);
    destination[1] = static_cast<unsigned char>(value >> 16);
    destination[2] = static_cast<unsigned char>(value >> 8);
    destination[3] = static_cast<unsigned char>(value);
}

} // namespace

idMQFrame::idMQFrame()
    : type(0), channel(0), data(), readPos(0), locked(false),
      resetReadBitBuffer(true), readBitBuffer(0), readBitMask(0),
      flushWriteBitBuffer(false), writeBitBuffer(0), writeBitMask(1),
      readPresenceBuffer(0), readPresencePosition(0), writePresenceBuffer(0),
      writePresencePosition(0) {
}

idMQFrame::idMQFrame(const unsigned char frameType,
        const unsigned short channelNumber)
    : idMQFrame() {
    type = frameType;
    channel = channelNumber;
}

void idMQFrame::Clear() {
    type = 0;
    channel = 0;
    data.Clear();
    readPos = 0;
    locked = false;
    resetReadBitBuffer = true;
    readBitBuffer = 0;
    readBitMask = 0;
    flushWriteBitBuffer = false;
    writeBitBuffer = 0;
    writeBitMask = 1;
    readPresenceBuffer = readPresencePosition = 0;
    writePresenceBuffer = writePresencePosition = 0;
}

void idMQFrame::ReadData(void* destination, const int length) {
    resetReadBitBuffer = true;
    if (destination == nullptr || length <= 0) return;
    const int available = std::max(0, data.Num() - readPos);
    const int amount = std::min(length, available);
    if (amount > 0) std::memcpy(destination, data.Ptr() + readPos, amount);
    if (amount < length) {
        std::memset(static_cast<unsigned char*>(destination) + amount, 0,
            length - amount);
    }
    readPos += amount;
}

void idMQFrame::FlushWriteBitBuffer() {
    if (!flushWriteBitBuffer) return;
    data.Append(writeBitBuffer);
    flushWriteBitBuffer = false;
    writeBitBuffer = 0;
    writeBitMask = 1;
}

void idMQFrame::WriteData(const void* source, const int length) {
    FlushWriteBitBuffer();
    if (source == nullptr || length <= 0) return;
    const unsigned char* bytes = static_cast<const unsigned char*>(source);
    for (int index = 0; index < length; ++index) data.Append(bytes[index]);
}

unsigned char idMQFrame::ReadByte() {
    unsigned char value = 0;
    ReadData(&value, sizeof(value));
    return value;
}

unsigned short idMQFrame::ReadUInt16() {
    unsigned char bytes[2] = {};
    ReadData(bytes, sizeof(bytes));
    return static_cast<unsigned short>((bytes[0] << 8) | bytes[1]);
}

unsigned int idMQFrame::ReadUInt32() {
    unsigned char bytes[4] = {};
    ReadData(bytes, sizeof(bytes));
    return (static_cast<unsigned int>(bytes[0]) << 24)
        | (static_cast<unsigned int>(bytes[1]) << 16)
        | (static_cast<unsigned int>(bytes[2]) << 8)
        | static_cast<unsigned int>(bytes[3]);
}

std::uint64_t idMQFrame::ReadUInt64() {
    const std::uint64_t high = ReadUInt32();
    const std::uint64_t low = ReadUInt32();
    return (high << 32) | low;
}

bool idMQFrame::ReadBool() {
    if (resetReadBitBuffer || readBitMask == 0 || readBitMask > 0x80) {
        if (readPos >= data.Num()) return false;
        readBitBuffer = data[readPos++];
        readBitMask = 1;
        resetReadBitBuffer = false;
    }
    const bool result = (readBitBuffer & readBitMask) != 0;
    readBitMask <<= 1;
    return result;
}

idStr idMQFrame::ReadShortString() {
    const int length = ReadByte();
    idStr result;
    for (int index = 0; index < length && readPos < data.Num(); ++index) {
        result.Append(static_cast<char>(data[readPos++]));
    }
    resetReadBitBuffer = true;
    return result;
}

void idMQFrame::ReadString(idMQList<unsigned char>& value) {
    const unsigned int length = ReadUInt32();
    value.Clear();
    for (unsigned int index = 0; index < length && readPos < data.Num();
            ++index) value.Append(data[readPos++]);
}

void idMQFrame::WriteByte(const unsigned char value) {
    WriteData(&value, sizeof(value));
}

void idMQFrame::WriteUInt16(const unsigned short value) {
    const unsigned char bytes[2] = {
        static_cast<unsigned char>(value >> 8),
        static_cast<unsigned char>(value)
    };
    WriteData(bytes, sizeof(bytes));
}

void idMQFrame::WriteUInt32(const unsigned int value) {
    unsigned char bytes[4];
    StoreUInt32BE(bytes, value);
    WriteData(bytes, sizeof(bytes));
}

void idMQFrame::WriteUInt64(const std::uint64_t value) {
    WriteUInt32(static_cast<unsigned int>(value >> 32));
    WriteUInt32(static_cast<unsigned int>(value));
}

void idMQFrame::WriteBool(const bool value) {
    if (writeBitMask == 0 || writeBitMask > 0x80) FlushWriteBitBuffer();
    if (value) writeBitBuffer |= static_cast<unsigned char>(writeBitMask);
    flushWriteBitBuffer = true;
    writeBitMask <<= 1;
}

void idMQFrame::WriteShortString(const idStr& value) {
    const int length = std::min(value.Length(), 255);
    WriteByte(static_cast<unsigned char>(length));
    WriteData(value.c_str(), length);
}

void idMQFrame::WriteString(const idMQList<unsigned char>& value) {
    WriteUInt32(value.Num());
    if (value.Num() > 0) WriteData(value.Ptr(), value.Num());
}

void idMQFrame::WriteTable(const idMQTable& value) {
    FlushWriteBitBuffer();
    const int lengthOffset = data.Num();
    WriteUInt32(0);
    const int tableStart = data.Num();
    for (int index = 0; index < value.GetNumKeyVals(); ++index) {
        const idMQKeyValue* entry = value.GetKeyVal(index);
        WriteShortString(entry->GetKey());
        WriteByte('S');
        const idStr& text = entry->GetValue();
        WriteUInt32(text.Length());
        WriteData(text.c_str(), text.Length());
    }
    StoreUInt32BE(data.Ptr() + lengthOffset, data.Num() - tableStart);
}

void idMQFrame::ReadTable(idMQTable& value) {
    value.Clear();
    const unsigned int length = ReadUInt32();
    const int end = std::min(data.Num(), readPos + static_cast<int>(length));
    while (readPos < end) {
        const idStr key = ReadShortString();
        const unsigned char fieldType = ReadByte();
        idStr text;
        if (fieldType == 'S') {
            const unsigned int stringLength = ReadUInt32();
            for (unsigned int i = 0; i < stringLength && readPos < end; ++i) {
                text.Append(static_cast<char>(data[readPos++]));
            }
        } else if (fieldType == 't') {
            text = ReadByte() != 0 ? "1" : "0";
        } else if (fieldType == 'I') {
            char buffer[32];
            std::snprintf(buffer, sizeof(buffer), "%d",
                static_cast<int>(ReadUInt32()));
            text = buffer;
        } else if (fieldType == 'l') {
            char buffer[32];
            std::snprintf(buffer, sizeof(buffer), "%llu",
                static_cast<unsigned long long>(ReadUInt64()));
            text = buffer;
        } else if (fieldType == 'V') {
            text.Clear();
        } else {
            // Unknown table values cannot be sized safely without the full
            // AMQP type grammar, so consume the remaining declared table.
            readPos = end;
            break;
        }
        value.Set(key.c_str(), text.c_str());
    }
    readPos = end;
    resetReadBitBuffer = true;
}

void idMQFrame::WritePropertyPresence(const bool present) {
    if (writePresencePosition < 15 && present) {
        writePresenceBuffer |= static_cast<unsigned short>(
            0x8000u >> writePresencePosition);
    }
    ++writePresencePosition;
}

void idMQFrame::FinalizeWritePresence() {
    WriteUInt16(writePresenceBuffer);
    writePresenceBuffer = 0;
    writePresencePosition = 0;
}

bool idMQFrame::ReadPropertyPresence() {
    if (readPresencePosition == 0) readPresenceBuffer = ReadUInt16();
    const bool result = readPresencePosition < 15
        && (readPresenceBuffer & (0x8000u >> readPresencePosition)) != 0;
    ++readPresencePosition;
    return result;
}

void idMQFrame::FinalizeReadPresence() {
    readPresenceBuffer = 0;
    readPresencePosition = 0;
}

void idMQFrame::FinalizeFrame() { FlushWriteBitBuffer(); }

int idMQFrame::ReadFromStream(idMQTCP& stream) {
    Clear();
    unsigned int payloadSize = 0;
    if (stream.ReadByte(type) != 1 || stream.ReadUInt16(channel) != 2
            || stream.ReadUInt32(payloadSize) != 4) return -1;
    if (payloadSize > 128u * 1024u * 1024u) return -1;
    data.SetNum(static_cast<int>(payloadSize));
    if (payloadSize != 0 && stream.Read(data.Ptr(), payloadSize, true, 5000)
            != static_cast<int>(payloadSize)) return -1;
    unsigned char frameEnd = 0;
    if (stream.ReadByte(frameEnd) != 1 || frameEnd != AMQP_FRAME_END) return -1;
    return static_cast<int>(payloadSize) + 8;
}

int idMQFrame::WriteToStream(idMQTCP& stream) {
    FinalizeFrame();
    unsigned char header[7] = {
        type,
        static_cast<unsigned char>(channel >> 8),
        static_cast<unsigned char>(channel),
        0, 0, 0, 0
    };
    StoreUInt32BE(header + 3, data.Num());
    if (stream.Write(header, sizeof(header), true, 5000) != sizeof(header)) {
        return -1;
    }
    if (data.Num() > 0 && stream.Write(data.Ptr(), data.Num(), true, 5000)
            != data.Num()) return -1;
    const unsigned char frameEnd = AMQP_FRAME_END;
    if (stream.Write(&frameEnd, 1, true, 5000) != 1) return -1;
    return data.Num() + 8;
}

idMQFrameHandler::idMQFrameHandler(const amqpEndpoint_t& endpointValue)
    : endpoint(endpointValue), readLock(), writeLock(), tcp() {
}

idMQFrameHandler::~idMQFrameHandler() { Close(); }

bool idMQFrameHandler::Connect() {
    return tcp.Connect(endpoint.host.c_str(), endpoint.port,
        endpoint.nonBlocking, endpoint.silent);
}

void idMQFrameHandler::Close() { tcp.Close(); }

int idMQFrameHandler::SendFrame(idMQFrame& frame) {
    idScopedCriticalSection lock(writeLock);
    return frame.WriteToStream(tcp);
}

int idMQFrameHandler::ReadFrame(idMQFrame& frame) {
    idScopedCriticalSection lock(readLock);
    return frame.ReadFromStream(tcp);
}

bool idMQFrameHandler::SendHeader() {
    const unsigned char protocol[8] = {
        'A', 'M', 'Q', 'P', 1, 1,
        static_cast<unsigned char>(endpoint.majorVersion),
        static_cast<unsigned char>(endpoint.minorVersion)
    };
    return tcp.Write(protocol, sizeof(protocol), true, 5000)
        == sizeof(protocol);
}
