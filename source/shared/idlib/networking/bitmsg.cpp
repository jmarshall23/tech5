#include "bitmsg.h"

#include <cstring>

idBitMsg::idBitMsg()
    : writeData(nullptr), readData(nullptr), maxSize(0), curSize(0),
      writeBit(0), readCount(0), readBit(0), allowOverflow(false),
      overflowed(false), tempValue(0) {}

idBitMsg::idBitMsg(unsigned char* data, const int length) : idBitMsg() {
    Init(data, length);
}

idBitMsg::idBitMsg(const unsigned char* data, const int length) : idBitMsg() {
    Init(data, length);
}

void idBitMsg::Init(unsigned char* data, const int length) {
    writeData = data;
    readData = data;
    maxSize = length;
    BeginWriting();
}

void idBitMsg::Init(const unsigned char* data, const int length) {
    writeData = nullptr;
    readData = data;
    maxSize = curSize = length;
    writeBit = 0;
    BeginReading();
    allowOverflow = overflowed = false;
    tempValue = 0;
}

void idBitMsg::BeginWriting() {
    curSize = writeBit = readCount = readBit = 0;
    overflowed = false;
    tempValue = 0;
}

void idBitMsg::BeginReading() const {
    readCount = readBit = 0;
}

bool idBitMsg::CheckOverflow(const int numBits) {
    if (curSize * 8 + writeBit + numBits <= maxSize * 8) return false;
    if (!allowOverflow || numBits > maxSize * 8) {
        overflowed = true;
        return true;
    }
    curSize = writeBit = 0;
    tempValue = 0;
    overflowed = true;
    return false;
}

unsigned char* idBitMsg::GetByteSpace(const int length) {
    if (writeData == nullptr || length < 0) return nullptr;
    if (writeBit != 0) {
        ++curSize;
        writeBit = 0;
        tempValue = 0;
    }
    if (CheckOverflow(length * 8)) return nullptr;
    unsigned char* const result = writeData + curSize;
    curSize += length;
    return result;
}

void idBitMsg::WriteBits(const int value, int numBits) {
    if (writeData == nullptr || numBits == 0 || numBits < -31 || numBits > 32)
        return;
    if (numBits < 0) numBits = -numBits;
    if (CheckOverflow(numBits)) return;
    std::uint32_t bits = static_cast<std::uint32_t>(value);
    if (numBits < 32) bits &= (1u << numBits) - 1u;
    for (int bit = 0; bit < numBits; ++bit) {
        if (writeBit == 0) writeData[curSize] = 0;
        if ((bits & (1u << bit)) != 0)
            writeData[curSize] |= static_cast<unsigned char>(1u << writeBit);
        if (++writeBit == 8) {
            writeBit = 0;
            ++curSize;
        }
    }
    tempValue = writeBit != 0 ? writeData[curSize] : 0;
}

int idBitMsg::ReadBits(int numBits) const {
    if (readData == nullptr || numBits == 0 || numBits < -31 || numBits > 32)
        return -1;
    const bool signedValue = numBits < 0;
    if (signedValue) numBits = -numBits;
    const int availableBits = (curSize - readCount) * 8
        + (readBit != 0 ? 8 - readBit : 0);
    if (numBits > availableBits) return -1;
    std::uint32_t result = 0;
    for (int bit = 0; bit < numBits; ++bit) {
        if (readBit == 0) ++readCount;
        if ((readData[readCount - 1] & (1u << readBit)) != 0)
            result |= 1u << bit;
        readBit = (readBit + 1) & 7;
    }
    if (signedValue && numBits < 32 && (result & (1u << (numBits - 1))) != 0)
        result |= ~((1u << numBits) - 1u);
    return static_cast<int>(result);
}

void idBitMsg::WriteData(const void* data, const int length) {
    unsigned char* const destination = GetByteSpace(length);
    if (destination != nullptr && data != nullptr && length > 0)
        std::memcpy(destination, data, static_cast<std::size_t>(length));
}

int idBitMsg::ReadData(void* data, const int length) const {
    if (length <= 0 || readData == nullptr) return 0;
    readBit = 0;
    const int amount = (std::min)(length, curSize - readCount);
    if (data != nullptr && amount > 0)
        std::memcpy(data, readData + readCount, static_cast<std::size_t>(amount));
    readCount += amount;
    return amount;
}

void idBitMsg::WriteDelta(const int oldValue, const int newValue,
        const int numBits) {
    WriteBits(oldValue != newValue, 1);
    if (oldValue != newValue) WriteBits(newValue, numBits);
}

int idBitMsg::ReadDelta(const int oldValue, const int numBits) const {
    return ReadBits(1) != 0 ? ReadBits(numBits) : oldValue;
}

void idBitMsg::WriteString(const char* string, const int maxLength,
        const bool make7Bit) {
    const char* const source = string != nullptr ? string : "";
    int length = static_cast<int>(std::strlen(source));
    if (maxLength >= 0 && length >= maxLength) length = (std::max)(0, maxLength - 1);
    unsigned char* const destination = GetByteSpace(length + 1);
    if (destination == nullptr) return;
    for (int index = 0; index < length; ++index) {
        const unsigned char value = static_cast<unsigned char>(source[index]);
        destination[index] = make7Bit && value > 127 ? '.' : value;
    }
    destination[length] = 0;
}

int idBitMsg::ReadString(char* buffer, const int bufferSize) const {
    if (buffer == nullptr || bufferSize <= 0) return 0;
    readBit = 0;
    int length = 0;
    while (readCount < curSize) {
        unsigned char value = readData[readCount++];
        if (value == 0 || value == 255) break;
        if (value == '%') value = '.';
        if (length < bufferSize - 1) buffer[length++] = static_cast<char>(value);
    }
    buffer[length] = 0;
    return length;
}

int idBitMsg::ReadString(idStr& string) const {
    char buffer[4096];
    const int length = ReadString(buffer, sizeof(buffer));
    string = buffer;
    return length;
}

void idBitMsg::WriteNetadr(const netadr_t& address) {
    WriteData(address.ip, 4);
    WriteBits(address.port, 16);
    WriteBits(address.type, 8);
}

void idBitMsg::ReadNetadr(netadr_t* address) const {
    if (address == nullptr) return;
    ReadData(address->ip, 4);
    address->port = static_cast<unsigned short>(ReadBits(16));
    address->type = static_cast<netadrtype_t>(ReadBits(8));
}

void idBitMsg::WriteDeltaShortCounter(const int oldValue, const int newValue) {
    const int delta = newValue - oldValue;
    unsigned int magnitude = delta < 0 ? -delta : delta;
    int bits = 1;
    while (magnitude >>= 1) ++bits;
    WriteBits(bits - 1, 4);
    WriteBits(delta, -(bits + 1));
}

void idBitMsg::WriteDeltaLongCounter(const int oldValue, const int newValue) {
    const int delta = newValue - oldValue;
    unsigned int magnitude = delta < 0 ? -delta : delta;
    int bits = 1;
    while (magnitude >>= 1) ++bits;
    WriteBits(bits - 1, 5);
    WriteBits(delta, -(bits + 1));
}

int idBitMsg::ReadDeltaShortCounter(const int oldValue) const {
    const int bits = ReadBits(4) + 1;
    return oldValue + ReadBits(-(bits + 1));
}

int idBitMsg::ReadDeltaLongCounter(const int oldValue) const {
    const int bits = ReadBits(5) + 1;
    return oldValue + ReadBits(-(bits + 1));
}

idFile_BitMsg::idFile_BitMsg(idBitMsg& message)
    : idFile(), name("*bitmsg*"), mode(FS_READ_WRITE), msg(&message) {}

unsigned int idFile_BitMsg::Read(void* data, const unsigned int length) {
    return static_cast<unsigned int>(msg != nullptr
        ? msg->ReadData(data, static_cast<int>(length)) : 0);
}

unsigned int idFile_BitMsg::Write(const void* data, const unsigned int length) {
    if (msg == nullptr || mode == FS_READ) return 0;
    msg->WriteData(data, static_cast<int>(length));
    return length;
}

std::int64_t idFile_BitMsg::Length() const {
    return msg != nullptr ? msg->GetSize() : 0;
}

std::int64_t idFile_BitMsg::Tell() const {
    if (msg == nullptr) return 0;
    return mode == FS_READ ? msg->GetReadCount() : msg->GetSize();
}

