#include "aasobstacle.h"

namespace {

constexpr int AAS_AREA_OBSTACLE = 0x800;
constexpr int CONTENTS_AAS_OBSTACLE = 0x20000;
constexpr int ALL_CLIP_MODELS = -1;

} // namespace

// Retail symbol: ??0idAASObstacle@@QAA@XZ
// EA: 0x829EE340, RVA: 0x009EE340
idAASObstacle::idAASObstacle()
    : startOn(false)
    , dynamicObstacle(true)
    , travelFlags(AAS_TFL_INVALID)
    , enabled(false) {
}

// Retail symbol: ?ChangeAreaState@idAASObstacle@@AAAXXZ
// EA: 0x829EE398, RVA: 0x009EE398
void idAASObstacle::ChangeAreaState() {
    idPhysics* const physics = Tungsten_GetAASObstaclePhysics(*this);
    const idBounds* const bounds = Tungsten_GetAASObstacleAbsBounds(
        *physics, ALL_CLIP_MODELS);
    Tungsten_ChangeAASObstacleAreaTravelFlags(
        *bounds, AAS_AREA_OBSTACLE, static_cast<int>(travelFlags), enabled);

    if (!dynamicObstacle) {
        return;
    }

    const int contents = Tungsten_GetAASObstacleContents(
        *physics, ALL_CLIP_MODELS);
    if (enabled) {
        Tungsten_SetAASObstacleContents(
            *physics, contents | CONTENTS_AAS_OBSTACLE, ALL_CLIP_MODELS);
        Tungsten_LinkAASObstacleClip(*physics);
    } else {
        Tungsten_SetAASObstacleContents(
            *physics, contents & ~CONTENTS_AAS_OBSTACLE, ALL_CLIP_MODELS);
        Tungsten_UnlinkAASObstacleClip(*physics);
    }
}

// Retail symbol: ?Spawn@idAASObstacle@@QAAXXZ
// EA: 0x829EE498, RVA: 0x009EE498
void idAASObstacle::Spawn() {
    enabled = startOn;
    ChangeAreaState();
}

// Retail symbol: ?OnActivate@idAASObstacle@@EAAXPAVidEntity@@@Z
// EA: 0x829EE4A8, RVA: 0x009EE4A8
void idAASObstacle::OnActivate(idEntity* const activator) {
    (void)activator;
    enabled = !enabled;
    ChangeAreaState();
}
