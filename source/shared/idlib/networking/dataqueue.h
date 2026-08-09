#pragma once

#include "../containers/staticlist.h"

#include <cstdint>
#include <cstring>

template<int maxItems, int maxData>
class idDataQueue {
public:
    struct msgItem_t {
        int sequence;
        int length;
        int dataOffset;
    };

    idStaticList<msgItem_t, maxItems> items;
    int dataLength;
    std::uint8_t data[maxData];

    idDataQueue() : dataLength(0) {}

    bool Append(const int sequence, const std::uint8_t* first,
            const int firstLength, const std::uint8_t* second,
            const int secondLength) {
        if (firstLength < 0 || secondLength < 0
                || items.Num() == items.Max()
                || dataLength + firstLength + secondLength >= maxData) {
            return false;
        }
        msgItem_t* const item = items.Alloc();
        if (item == nullptr) return false;
        item->sequence = sequence;
        item->length = firstLength + secondLength;
        item->dataOffset = dataLength;
        if (firstLength > 0) {
            std::memcpy(&data[dataLength], first, firstLength);
            dataLength += firstLength;
        }
        if (secondLength > 0) {
            std::memcpy(&data[dataLength], second, secondLength);
            dataLength += secondLength;
        }
        return true;
    }

    void RemoveOlderThan(const int sequence) {
        int removeBytes = 0;
        while (items.Num() > 0 && items[0].sequence < sequence) {
            removeBytes += items[0].length;
            items.RemoveIndex(0);
        }
        if (removeBytes < dataLength) {
            if (removeBytes > 0) {
                std::memmove(data, data + removeBytes, dataLength - removeBytes);
                dataLength -= removeBytes;
            }
        } else {
            dataLength = 0;
        }
        int offset = 0;
        for (int index = 0; index < items.Num(); ++index) {
            items[index].dataOffset = offset;
            offset += items[index].length;
        }
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDataQueue<63, 8000>) == 8776,
    "Recovered idDataQueue<63,8000> ABI changed");
static_assert(sizeof(idDataQueue<64, 65536>) == 66324,
    "Recovered idDataQueue<64,65536> ABI changed");
#endif
