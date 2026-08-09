#pragma once

#include "../filesystem/file.h"
#include "../math/vector.h"
#include "../sys/sys_networking.h"

#include <algorithm>
#include <cstdint>

class idBitMsg {
public:
    idBitMsg();
    idBitMsg(unsigned char* data, int length);
    idBitMsg(const unsigned char* data, int length);

    void Init(unsigned char* data, int length);
    void Init(const unsigned char* data, int length);
    void BeginWriting();
    void BeginReading() const;

    void SetAllowOverflow(bool allow) { allowOverflow = allow; }
    bool IsOverflowed() const { return overflowed; }
    int GetSize() const { return curSize + (writeBit != 0 ? 1 : 0); }
    int GetMaxSize() const { return maxSize; }
    int GetReadCount() const { return readCount; }
    int GetRemainingData() const { return curSize - readCount; }
    unsigned char* GetWriteData() { return writeData; }
    const unsigned char* GetReadData() const { return readData; }

    void WriteBits(int value, int numBits);
    int ReadBits(int numBits) const;
    void WriteData(const void* data, int length);
    int ReadData(void* data, int length) const;
    void WriteString(const char* string, int maxLength = -1,
        bool make7Bit = true);
    int ReadString(char* buffer, int bufferSize) const;
    int ReadString(idStr& string) const;
    void WriteNetadr(const netadr_t& address);
    void ReadNetadr(netadr_t* address) const;
    void WriteDeltaShortCounter(int oldValue, int newValue);
    void WriteDeltaLongCounter(int oldValue, int newValue);
    int ReadDeltaShortCounter(int oldValue) const;
    int ReadDeltaLongCounter(int oldValue) const;

    template<class vector_t, int maxValue, int numBits>
    void WriteQuantizedVector(const vector_t& value) {
        const int quantizedMax = (1 << (numBits - 1)) - 1;
        const float scale = static_cast<float>(quantizedMax)
            / static_cast<float>(maxValue);
        for (int component = 0; component < value.GetDimension(); ++component) {
            int quantized = static_cast<int>(value[component] * scale);
            quantized = (std::max)(-quantizedMax,
                (std::min)(quantizedMax, quantized));
            WriteBits(quantized, -numBits);
        }
    }

    template<class vector_t, int maxValue, int numBits>
    void ReadQuantizedVector(vector_t& value) const {
        const int quantizedMax = (1 << (numBits - 1)) - 1;
        const float scale = static_cast<float>(maxValue)
            / static_cast<float>(quantizedMax);
        for (int component = 0; component < value.GetDimension(); ++component)
            value[component] = static_cast<float>(ReadBits(-numBits)) * scale;
    }

    template<int maxValue, int numBits>
    void WriteQuantizedUFloat(const float value) {
        const unsigned int storeMax = (1u << numBits) - 1u;
        const unsigned int scale = storeMax / static_cast<unsigned int>(maxValue);
        int quantized = static_cast<int>(value * static_cast<float>(scale));
        quantized = (std::max)(0,
            (std::min)(static_cast<int>(storeMax), quantized));
        WriteBits(quantized, numBits);
    }

    template<int maxValue, int numBits>
    float ReadQuantizedUFloat() const {
        const unsigned int storeMax = (1u << numBits) - 1u;
        const unsigned int scale = storeMax / static_cast<unsigned int>(maxValue);
        return scale != 0 ? static_cast<float>(ReadBits(numBits)) / scale : 0.0f;
    }

    unsigned char* writeData;
    const unsigned char* readData;
    int maxSize;
    int curSize;
    int writeBit;
    mutable int readCount;
    mutable int readBit;
    bool allowOverflow;
    bool overflowed;
    std::uint64_t tempValue;

private:
    bool CheckOverflow(int numBits);
    unsigned char* GetByteSpace(int length);
    void WriteDelta(int oldValue, int newValue, int numBits);
    int ReadDelta(int oldValue, int numBits) const;
};

class idFile_BitMsg : public idFile {
public:
    explicit idFile_BitMsg(idBitMsg& message);
    ~idFile_BitMsg() override = default;
    const char* GetName() const override { return name.c_str(); }
    const char* GetFullPath() const override { return name.c_str(); }
    unsigned int Read(void* data, unsigned int length) override;
    unsigned int Write(const void* data, unsigned int length) override;
    std::int64_t Length() const override;
    std::int64_t Tell() const override;
    fsDevice_t GetDevice() const override { return FS_DEVICE_MEMORY; }

    idStr name;
    int mode;
    idBitMsg* msg;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idBitMsg) == 40, "Recovered idBitMsg ABI changed");
static_assert(sizeof(idFile_BitMsg) == 48,
    "Recovered idFile_BitMsg ABI changed");
#endif

