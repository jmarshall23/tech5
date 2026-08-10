#pragma once

// SuperScript entity values are the serialized game spawn identity, not a
// native pointer. Zero is the script null-entity value.
class ssString;

int Tungsten_FindSuperScriptEntity(const char* name);

class ssEntity {
public:
    ssEntity();
    explicit ssEntity(const ssString& name);
    explicit ssEntity(const char* name);
    explicit ssEntity(int entitySpawnId);
    ssEntity(const ssEntity& entity);

    int spawnId;
};

static_assert(sizeof(ssEntity) == 4,
    "Recovered SuperScript entity ABI changed");
