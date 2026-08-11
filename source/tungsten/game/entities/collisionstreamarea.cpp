#include "game/entities/collisionstreamarea.h"

namespace {
idCollisionStreamAreaServices defaultCollisionStreamAreaServices;
idCollisionStreamAreaServices* collisionStreamAreaServices =
    &defaultCollisionStreamAreaServices;
}

idCollisionStreamArea::idCollisionStreamArea()
    : streamArea(-1), registeredSpawnId(0x1FFF) {
}

void idCollisionStreamArea::SetServices(
        idCollisionStreamAreaServices* const services) {
    collisionStreamAreaServices = services == nullptr
        ? &defaultCollisionStreamAreaServices : services;
}

idCollisionStreamAreaServices& idCollisionStreamArea::Services() {
    return *collisionStreamAreaServices;
}

// Retail: 0x82C18350 ?OnActivate@idCollisionStreamArea@@UAAXPAVidEntity@@@Z
void idCollisionStreamArea::OnActivate(idEntity*) {
    if (streamArea >= 0) {
        Services().AddStreamArea(*this, streamArea);
    }
}

// Retail: 0x82C18410 ??1idCollisionStreamArea@@UAA@XZ
idCollisionStreamArea::~idCollisionStreamArea() {
    if (registeredSpawnId != 0x1FFF) {
        Services().UnregisterStreamAreaEntity(registeredSpawnId);
        registeredSpawnId = 0x1FFF;
    }
}

// Retail: 0x82C18480 ?Spawn@idCollisionStreamArea@@QAAXXZ
void idCollisionStreamArea::Spawn() {
    Services().UnlinkClip(*this);
    streamArea = Services().FindStreamArea(*this);
    registeredSpawnId = Services().GetSpawnId(*this);
    Services().RegisterStreamAreaEntity(registeredSpawnId);
}
