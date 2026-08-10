#include "fsmlog.h"

// Retail symbol: ?FromLast@idFSMLog@@QBAPBVidFSMLogEntry@@H@Z
// EA: 0x82AB4620, RVA: 0x00AB4620
const idFSMLogEntry* idFSMLog::FromLast(const int index) const {
    const int count = list.Num();
    if (count >= maxSize) {
        if (index >= maxSize || index < 0 || maxSize <= 0) {
            return nullptr;
        }
        int itemIndex = first - index - 1;
        if (itemIndex < 0) {
            itemIndex += maxSize;
        }
        return &list[itemIndex];
    }

    const int itemIndex = count - index - 1;
    return itemIndex >= 0 && itemIndex < count ? &list[itemIndex] : nullptr;
}

// Retail symbol: ??0idFSMLog@@QAA@H@Z
// EA: 0x82AB4690, RVA: 0x00AB4690
idFSMLog::idFSMLog(const int maximumSize)
    : list(0)
    , first(0)
    , maxSize(maximumSize) {
}

// Retail symbol: ??1idFSMLog@@QAA@XZ
// EA: 0x82AB46E8, RVA: 0x00AB46E8
idFSMLog::~idFSMLog() {
    Clear();
}

// Retail symbol: ?Alloc@idFSMLog@@QAAAAVidFSMLogEntry@@XZ
// EA: 0x82AB4968, RVA: 0x00AB4968
idFSMLogEntry* idFSMLog::Alloc() {
    if (maxSize <= 0) {
        return nullptr;
    }
    if (list.Num() < maxSize) {
        return list.Alloc();
    }
    const int allocatedIndex = first;
    ++first;
    if (first >= list.Num()) {
        first = 0;
    }
    return &list[allocatedIndex];
}
