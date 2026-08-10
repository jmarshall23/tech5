#pragma once

#include <cstdint>

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
