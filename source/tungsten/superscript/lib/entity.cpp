#include "entity.h"
#include "string.h"
#include "sys.h"

// Inline/default construction has no standalone retail symbol. Script event
// return paths establish zero as the null-entity representation.
ssEntity::ssEntity()
    : spawnId(0) {
}

// Retail symbol: ??0ssEntity@@QAA@ABVssString@@@Z
// EA: 0x82EE6E50, RVA: 0x00EE6E50
ssEntity::ssEntity(const ssString& name)
    : spawnId(Tungsten_FindSuperScriptEntity(name.c_str())) {
    if (spawnId == 0) {
        const ssString message = "entity '" + name + "' not found";
        Warning(message);
    }
}

// Retail symbol: ??0ssEntity@@QAA@PBD@Z
// EA: 0x82EE6F30, RVA: 0x00EE6F30
ssEntity::ssEntity(const char* const name)
    : spawnId(Tungsten_FindSuperScriptEntity(name)) {
    if (spawnId == 0) {
        const ssString scriptName(name);
        const ssString message = "entity '" + scriptName + "' not found";
        Warning(message);
    }
}

// Retail symbol: ??0ssEntity@@QAA@H@Z
// EA: 0x82D5F1E0, RVA: 0x00D5F1E0
// Hex-Rays confused this four-byte type with XGRAPHICS::VRegTable; the PDB
// type and decorated signature resolve the operation to a scalar assignment.
ssEntity::ssEntity(const int entitySpawnId)
    : spawnId(entitySpawnId) {
}

// Retail symbol: ??0ssEntity@@QAA@ABV0@@Z
// EA: 0x82EE7048, RVA: 0x00EE7048
ssEntity::ssEntity(const ssEntity& entity)
    : spawnId(entity.spawnId) {
}
