#include "aideathvolume.h"

const idEntity* Tungsten_ResolveAIDeathVolumeEntity(int spawnId);
const idEntity* Tungsten_GetAIDeathVolumeSelfEntity(
    const idAIDeathVolume* volume);
bool Tungsten_IsAIDeathVolumeTouchable(const idAIDeathVolume* volume);
void Tungsten_EnableAIDeathVolumeTouch(idAIDeathVolume* volume);
void Tungsten_DisableAIDeathVolumeTouch(idAIDeathVolume* volume);
void Tungsten_AIDeathVolumeBaseTouch(
    idAIDeathVolume* volume, idEntity* toucher, int clipModelId);
bool Tungsten_IsLivingAIDeathVolumeToucher(const idEntity* toucher);
void Tungsten_DamageAIDeathVolumeToucher(
    idEntity* toucher, const idEntity* inflictor, const idEntity* attacker,
    const idDeclDamage* damage, const idVec3& direction);
void Tungsten_PostAIDeathVolumeStop(
    idAIDeathVolume* volume, int delayMilliseconds);
void Tungsten_AIDeathVolumeError(const char* format, const char* name);
int Tungsten_GetEntitySpawnId(const idEntity* entity);

// Retail symbol: ??1idAIDeathVolume@@UAA@XZ
// EA: 0x82A422C0, RVA: 0x00A422C0
idAIDeathVolume::~idAIDeathVolume() = default;

// Retail symbol: ?Spawn@idAIDeathVolume@@QAAXXZ
// EA: 0x82A423D8, RVA: 0x00A423D8
void idAIDeathVolume::Spawn() {
    if (referenceDir.x * referenceDir.x
            + referenceDir.y * referenceDir.y
            + referenceDir.z * referenceDir.z < 0.01f) {
        Tungsten_AIDeathVolumeError(
            "idAIDeathVolume '%s' has a referenceDir with zero length",
            name.c_str());
    }
}

// Retail symbol: ??0idAIDeathVolume@@QAA@XZ
// EA: 0x82A42418, RVA: 0x00A42418
idAIDeathVolume::idAIDeathVolume()
    : referenceDir(1.0f, 0.0f, 0.0f)
    , unidirectional(true)
    , makeRagdollTouchTriggers(false)
    , killDuration(3.0f)
    , damageDecl(nullptr)
    , animFacingRefFwd()
    , animFacingRefLeft()
    , animFacingRefRight()
    , animFacingRefBack()
    , lastActivator()
    , name() {
}

// Retail symbol:
// ?Event_Touch@idAIDeathVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA: 0x82A42560, RVA: 0x00A42560
void idAIDeathVolume::Event_Touch(
        idEntity* const toucher, const int clipModelId) {
    Tungsten_AIDeathVolumeBaseTouch(this, toucher, clipModelId);
    if (!Tungsten_IsLivingAIDeathVolumeToucher(toucher)) {
        return;
    }
    const idEntity* attacker = Tungsten_ResolveAIDeathVolumeEntity(
        lastActivator.GetSpawnId());
    const idEntity* const self = Tungsten_GetAIDeathVolumeSelfEntity(this);
    if (attacker == nullptr) {
        attacker = self;
    }
    Tungsten_DamageAIDeathVolumeToucher(
        toucher, self, attacker, damageDecl, idVec3(0.0f, 0.0f, 1.0f));
}

// Retail symbol: ?Event_StopKilling@idAIDeathVolume@@QAA?AVeventVoid@@XZ
// EA: 0x82A42670, RVA: 0x00A42670
void idAIDeathVolume::Event_StopKilling() {
    Tungsten_DisableAIDeathVolumeTouch(this);
    lastActivator.Invalidate();
}

// Retail symbol: ?OnActivate@idAIDeathVolume@@UAAXPAVidEntity@@@Z
// EA: 0x82A426B8, RVA: 0x00A426B8
void idAIDeathVolume::OnActivate(idEntity* const activator) {
    if (Tungsten_IsAIDeathVolumeTouchable(this)) {
        Tungsten_DisableAIDeathVolumeTouch(this);
        lastActivator.Invalidate();
        return;
    }

    lastActivator.SetSpawnId(Tungsten_GetEntitySpawnId(activator));
    Tungsten_EnableAIDeathVolumeTouch(this);
    if (killDuration <= 0.0f) {
        Tungsten_DisableAIDeathVolumeTouch(this);
        lastActivator.Invalidate();
        return;
    }
    Tungsten_PostAIDeathVolumeStop(
        this, static_cast<int>(killDuration * 1000.0f));
}
