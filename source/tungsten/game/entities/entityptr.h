#pragma once

#include <cstdint>

// All 75 PDB specializations share this single four-byte layout.  Resolution
// methods are declared here and will be connected to idGameLocal when the
// entity table is recovered; declarations are sufficient for classes that
// merely store an entity reference.
struct idEntityPtrSpawnId {
    std::int32_t value;
};

template<typename entityType>
class idEntityPtr {
public:
    idEntityPtr() : spawnId{0x1FFF} {}
    explicit idEntityPtr(const std::int32_t value) : spawnId{value} {}

    entityType* GetEntity() const;
    entityType* operator->() const;
    operator entityType*() const;

    bool IsValid() const { return spawnId.value != 0x1FFF; }
    std::int32_t GetSpawnId() const { return spawnId.value; }
    void SetSpawnId(const std::int32_t value) { spawnId.value = value; }
    void Invalidate() { spawnId.value = 0x1FFF; }

    idEntityPtrSpawnId spawnId;
};

static_assert(sizeof(idEntityPtrSpawnId) == 4,
    "Recovered entity spawn identifier layout changed");
static_assert(sizeof(idEntityPtr<int>) == 4,
    "Recovered idEntityPtr layout changed");
