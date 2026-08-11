#pragma once

#include "../../../../engine/network/serializer.h"

#include <cstdint>

#ifndef TUNGSTEN_NET_BOOL_EVENT_T_DEFINED
#define TUNGSTEN_NET_BOOL_EVENT_T_DEFINED
struct netBoolEvent_t {
    netBoolEvent_t() : count(0), lastCount(0) {}

    void Serialize(idSerializer& serializer) {
        serializer.SerializeUMax(count, 7);
    }

    int count;
    int lastCount;
};
#endif

// Every recovered PDB specialization has the same one-word spawn identifier.
// Resolution remains owned by idClientGame and is recovered with its callers.
template<class presentableType>
class idPresentablePtr {
public:
    idPresentablePtr() : spawnId(0) {}
    explicit idPresentablePtr(const std::uint32_t id) : spawnId(id) {}

    presentableType* operator->() const;
    presentableType* Get() const;
    bool IsValid() const;

    std::uint32_t spawnId;
};

static_assert(sizeof(idPresentablePtr<void>) == 4,
    "Recovered presentable-pointer ABI changed");
