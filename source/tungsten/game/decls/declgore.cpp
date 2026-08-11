#include "game/decls/declgorebehavior.h"

// EA 0x82BBE7A0
idDeclGoreBehavior::idDeclGoreBehavior()
    : bodyExplosion{0.5f, 0.5f, 0.5f, 1, 1}
    , enableLimbloss(false)
    , enableHeadShots(false)
    , enableBodyWound(false)
    , enableFullBodyExplosion(false)
    , enableGoreWhenAlive(false) {
}

