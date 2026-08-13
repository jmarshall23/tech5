#include "game/entities/misc.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

namespace {
idMiscServices defaultMiscServices;
idMiscServices* miscServices = &defaultMiscServices;
idFuncWind* globalWind = nullptr;

constexpr float kPi = 3.14159265358979323846f;

float Clamp01(const float value) {
    return std::max(0.0f, std::min(1.0f, value));
}

idVec3 Normalize(const idVec3& value) {
    const float length = value.Length();
    return length > 0.00001f ? value * (1.0f / length)
        : idVec3(1.0f, 0.0f, 0.0f);
}

idVec4 ColorVector(const idColor& value) {
    return idVec4(value.r, value.g, value.b, value.a);
}

idColor ColorValue(const idVec4& value) {
    return idColor(value.x, value.y, value.z, value.w);
}

float RandomVariance(const float center, const float variance) {
    return center + (Tungsten_MiscServices().RandomFloat() * 2.0f - 1.0f)
        * variance;
}

int RandomDuration(const int minimum, const int maximum) {
    return Tungsten_MiscServices().RandomInt(minimum, maximum);
}

void BeginWindCycle(idMiscWindInterpolation& interpolation,
        const float start, const float end, const int minimumDuration,
        const int maximumDuration) {
    interpolation.startValue = start;
    interpolation.endValue = end;
    interpolation.startTime = Tungsten_MiscServices().GetGameMilliseconds();
    interpolation.duration = std::max(1,
        RandomDuration(minimumDuration, maximumDuration));
}

const idSoundShader* SelectAnnouncement(
        const idList<const idSoundShader*, 5>& choices, int& last) {
    if (choices.Num() == 0) return nullptr;
    int selected = Tungsten_MiscServices().RandomInt(0, choices.Num() - 1);
    if (choices.Num() > 1 && selected == last) {
        selected = (selected + 1) % choices.Num();
    }
    last = selected;
    return choices[selected];
}

const idDeclVoiceOver* SelectVoiceOver(
        const idList<const idDeclVoiceOver*, 5>& choices, int& last) {
    if (choices.Num() == 0) return nullptr;
    int selected = Tungsten_MiscServices().RandomInt(0, choices.Num() - 1);
    if (choices.Num() > 1 && selected == last) {
        selected = (selected + 1) % choices.Num();
    }
    last = selected;
    return choices[selected];
}
} // namespace

void idMiscFadeState::Start(const float newFrom, const float newTo,
        const int duration, const int currentTime,
        const bool disableStipple) {
    from = newFrom;
    to = newTo;
    startTime = currentTime;
    endTime = currentTime + std::max(0, duration);
    noStipple = disableStipple;
}

float idMiscFadeState::Evaluate(const int currentTime) const {
    if (endTime <= startTime) return to;
    const float fraction = Clamp01(static_cast<float>(currentTime - startTime)
        / static_cast<float>(endTime - startTime));
    return from + (to - from) * fraction;
}

bool idMiscFadeState::IsActive(const int currentTime) const {
    return endTime > startTime && currentTime < endTime;
}

float idMiscWindInterpolation::Evaluate(const int currentTime) const {
    if (duration <= 0) return endValue;
    const float fraction = Clamp01(static_cast<float>(currentTime - startTime)
        / static_cast<float>(duration));
    const float eased = 0.5f - 0.5f * std::cos(fraction * kPi);
    return startValue + (endValue - startValue) * eased;
}

bool idMiscWindInterpolation::IsDone(const int currentTime) const {
    return duration <= 0 || currentTime >= startTime + duration;
}

int idMiscServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
int idMiscServices::GetGameFrame() const {
    const int step = std::max(1, GetGameMillisecondsPerFrame());
    return GetGameMilliseconds() / step;
}
int idMiscServices::GetGameMillisecondsPerFrame() const {
    return idEntity::Services().GetGameMillisecondsPerFrame();
}
float idMiscServices::RandomFloat() { return 0.5f; }
int idMiscServices::RandomInt(const int minimum, const int maximum) {
    if (maximum <= minimum) return minimum;
    return minimum + (maximum - minimum) / 2;
}
float idMiscServices::SampleTable(const idDeclTable*, float) const {
    return 1.0f;
}
bool idMiscServices::IsEntityVisible(const idEntity& entity) const {
    return !entity.flags.hidden && !entity.removed;
}
bool idMiscServices::IsRendered(const idEntity& entity) const {
    return IsEntityVisible(entity);
}
bool idMiscServices::IsMultiplayer() const { return false; }
void idMiscServices::MarkDynamicSceneModel(idEntity&) {}
void idMiscServices::SetBinaryModelState(const char*, bool) {}
idPlayer* idMiscServices::PlayerFromEntity(idEntity*) const { return nullptr; }
idPlayer* idMiscServices::GetPrimaryPlayer() const { return nullptr; }
void idMiscServices::ActivateDynamicJob(idPlayer&, const idDeclJob*, bool) {}
void idMiscServices::ConfigureInformationClip(idEntity& entity) {
    entity.contents = 2113536;
}
void idMiscServices::ConfigureStaticEntity(idEntity&, bool, bool) {}
void idMiscServices::UpdateDynamicEntity(idDynamicEntity&, const idVec4&,
    float, const idVec3&, float) {}
void idMiscServices::OpenParticleEditor(idParticleEmitter&) {}
void idMiscServices::UpdateParticleEditor(idParticleEmitter&) {}
idPresentable* idMiscServices::AllocateParticlePresentable(
    idParticleEmitter&, idRenderModel*) { return nullptr; }
void idMiscServices::ConfigureParticle(idParticleEmitter&,
    const idDeclParticle*) {}
void idMiscServices::UpdateParticle(idParticleEmitter&) {}
void idMiscServices::TriggerParticle(idParticleEmitter&, bool) {}
void idMiscServices::EmitSmokeParticle(idParticleEmitter&,
    const idDeclParticle*, int, const idVec3&, float) {}
idPresentable* idMiscServices::AllocateElectricBoltPresentable(
    idElectricBoltEmitter&, idRenderModel*) { return nullptr; }
void idMiscServices::AllocateElectricBolt(idElectricBoltEmitter&,
    const idDeclElectricBolt*) {}
void idMiscServices::FreeElectricBolt(idElectricBoltEmitter&) {}
void idMiscServices::StartElectricBolt(idElectricBoltEmitter&, int,
    const idVec3&, const idVec3&, float) {}
void idMiscServices::StartElectricBoltPath(idElectricBoltEmitter&,
    idSplinePath*, int, float) {}
void idMiscServices::UpdateElectricBolt(idElectricBoltEmitter&,
    idSplinePath*, int, bool) {}
void idMiscServices::StopElectricBolt(idElectricBoltEmitter&) {}
void idMiscServices::StartRibbon(idRibbonEmitter&, const idDeclRibbon*, int) {}
void idMiscServices::UpdateRibbon(idRibbonEmitter&, int) {}
void idMiscServices::StopRibbon(idRibbonEmitter&) {}
void idMiscServices::StartFlare(idLensFlare&, const idDeclFlare*) {}
void idMiscServices::UpdateFlare(idLensFlare&, int) {}
void idMiscServices::StopFlare(idLensFlare&) {}
void idMiscServices::SetGodRays(idGodRays&, bool) {}
void idMiscServices::UpdateWind(idEntity&, const idVec3&, float, int) {}
void idMiscServices::EnableWindInfluence(idEntity&, bool) {}
void idMiscServices::GiveStoredInventory(idEntity&,
    const idMiscInventoryEntry&) {}
void idMiscServices::ClearPlayerInventory(idPlayer&) {}
void idMiscServices::GivePlayerInventory(idPlayer&,
    const idDeclInventory*, int) {}
void idMiscServices::RegisterCoopStartingInventory(idEntity*) {}
void idMiscServices::ConfigureDebrisModel(idEntity&, idRenderModel*) {}
void idMiscServices::ConfigureDebrisScale(idEntity&, const idVec3&) {}
void idMiscServices::MimicEntity(idEntity&, idEntity&, bool) {}
void idMiscServices::PlayAnnouncement(idEntity&, const idSoundShader*) {}
void idMiscServices::PlayAnnouncementVoiceOver(idEntity&,
    const idDeclVoiceOver*, const idStrId&) {}
void idMiscServices::StopAnnouncements(idEntity&) {}
bool idMiscServices::SetupGui(idGuiEntity&) { return true; }
void idMiscServices::ReleaseGui(idGuiEntity&) {}
void idMiscServices::UpdateGuiModel(idGuiEntity&, int) {}
void idMiscServices::InvokeGui(idGuiEntity&, const char*, const char*) {}
void idMiscServices::ChangeGuiState(idGuiEntity&,
    idGuiEntityInitialState, idGuiEntityInitialState) {}
void idMiscServices::SetGuiFloat(idGuiEntity&, const char*, float) {}
void idMiscServices::SetGuiString(idGuiEntity&, const char*, const char*) {}
bool idMiscServices::PostGuiEvent(idGuiEntity&, const char*, const char*,
    const idList<idStr, 5>&) { return false; }
void idMiscServices::PlayGuiSound(idGuiEntity&, const idSoundShader*) {}
void idMiscServices::CreateCloth(idFuncCloth&, const idDeclCloth*) {}
void idMiscServices::InitializeCloth(idFuncCloth&, const idVec3&) {}
void idMiscServices::UpdateClothCollisions(idFuncCloth&, bool, bool, bool) {}
void idMiscServices::UpdateCloth(idFuncCloth&, const idVec3&, int) {}
void idMiscServices::ReleaseCloth(idFuncCloth&) {}
float idMiscServices::GetDamageAmount(const idDeclDamage*) const { return 0.0f; }
bool idMiscServices::IsTriggerDamage(const idEntity*) const { return false; }
idPresentable* idMiscServices::PrepareRegimeChild(idRegimeTile&,
    idRegimeTile&) { return nullptr; }
void idMiscServices::SetRegimeChildPowered(idRegimeTile&,
    idMiscRegimeChild&, bool) {}
void idMiscServices::ScheduleRegimePropagation(idRegimeTile& tile,
        const bool powered, int) {
    if (powered) tile.Event_PowerUp();
    else tile.Event_PowerDown();
}

void Tungsten_SetMiscServices(idMiscServices* const services) {
    miscServices = services != nullptr ? services : &defaultMiscServices;
}
idMiscServices& Tungsten_MiscServices() { return *miscServices; }

// Retail: 0x82C6E130 ??0idDynamicSceneEntity@@QAA@XZ
idDynamicSceneEntity::idDynamicSceneEntity() = default;

// Retail: 0x82C6ED18 ?Spawn@idDynamicSceneEntity@@QAAXXZ
void idDynamicSceneEntity::Spawn() {
    Tungsten_MiscServices().MarkDynamicSceneModel(*this);
}

// Retail: 0x82C6E170 ??0idBinaryModel@@QAA@XZ
idBinaryModel::idBinaryModel() : invisible(false) {}

// Retail: 0x82C6E1B8 ?IsVisible@idBinaryModel@@EAA_NXZ
bool idBinaryModel::IsVisible() const { return !invisible; }

// Retail: 0x82C6E1C8 ?Event_IsHidden@idBinaryModel@@AAA?AVeventInt@@XZ
int idBinaryModel::Event_IsHidden() const { return invisible ? 1 : 0; }

// Retail: 0x82C6ED50 ?Spawn@idBinaryModel@@QAAXXZ
void idBinaryModel::Spawn() {
    Tungsten_MiscServices().SetBinaryModelState(name.c_str(), !invisible);
}

// Retail: 0x82C6ED80 ?OnActivate@idBinaryModel@@EAAXPAVidEntity@@@Z
void idBinaryModel::OnActivate(idEntity*) {
    if (invisible) Show(); else Hide();
}

// Retail: 0x82C6EDB8 ?Hide@idBinaryModel@@EAAXXZ
void idBinaryModel::Hide() {
    if (invisible) return;
    invisible = true;
    flags.hidden = true;
    Tungsten_MiscServices().SetBinaryModelState(name.c_str(), false);
}

// Retail: 0x82C6EDF8 ?Show@idBinaryModel@@EAAXXZ
void idBinaryModel::Show() {
    if (!invisible) return;
    invisible = false;
    flags.hidden = false;
    Tungsten_MiscServices().SetBinaryModelState(name.c_str(), true);
}

// Retail: 0x824FA7A0 ??1idFuncShadowCaster@@UAA@XZ
idFuncShadowCaster::~idFuncShadowCaster() = default;

// Retail: 0x82C6E3E8 ??0idDynamicJob@@QAA@XZ
idDynamicJob::idDynamicJob()
    : jobDecl(nullptr), endJob(true), forceActivateOnPlayer(true) {}

// Retail: 0x82C6E438 ?OnActivate@idDynamicJob@@EAAXPAVidEntity@@@Z
void idDynamicJob::OnActivate(idEntity* activator) {
    idPlayer* player = Tungsten_MiscServices().PlayerFromEntity(activator);
    if (player == nullptr && forceActivateOnPlayer) {
        player = Tungsten_MiscServices().GetPrimaryPlayer();
    }
    if (player != nullptr && jobDecl != nullptr) {
        Tungsten_MiscServices().ActivateDynamicJob(*player, jobDecl, endJob);
    }
}

// Retail: 0x82C70AA8 ??0idInformationEntity@@QAA@XZ
idInformationEntity::idInformationEntity()
    : message(), customIcon(nullptr) {}

// Retail: 0x82C6E4C0 ?Spawn@idInformationEntity@@QAAXXZ
void idInformationEntity::Spawn() {
    Tungsten_MiscServices().ConfigureInformationClip(*this);
}

// Retail: 0x82C70B68 ?ModifyCrosshairInfo@idInformationEntity@@...
bool idInformationEntity::ModifyCrosshairInfo(const idEntity*, const void*,
        int, void* crosshairInfo) const {
    if (crosshairInfo == nullptr) return false;
    idCrosshairInfo& info = *static_cast<idCrosshairInfo*>(crosshairInfo);
    info.color = idColor(1.0f, 1.0f, 1.0f, 1.0f);
    info.textColor = idColor(1.0f, 1.0f, 1.0f, 1.0f);
    info.text = message;
    if (customIcon != nullptr) {
        idCrosshairCustomIcon icon{customIcon, 0, false};
        info.icons.Append(icon);
        info.material = CHMATERIAL_CUSTOM;
    }
    return false;
}

// Retail: 0x82C6E558 ?Spawn@idWorldClipBounds@@QAAXXZ
void idWorldClipBounds::Spawn() { Remove(); }

// Retail: 0x82C6E568 ??0idHorizonScale@@QAA@XZ
idHorizonScale::idHorizonScale()
    : radiusInner(1024.0f), radiusOuter(2048.0f) {}

// Retail: 0x82C73F20 ?Spawn@idHorizonScale@@QAAXXZ
void idHorizonScale::Spawn() {
    if (targets.Num() > 0) BecomeActive(1);
}

// Retail: 0x82C771E8 ?Think@idHorizonScale@@UAAXXZ
void idHorizonScale::Think() {
    const float innerSquared = radiusInner * radiusInner;
    const float outerSquared = radiusOuter * radiusOuter;
    const float denominator = outerSquared - innerSquared;
    if (denominator <= 0.0f) return;
    for (int index = 0; index < targets.Num(); ++index) {
        idEntity* targetEntity = targets[index];
        if (targetEntity == nullptr
                || !Tungsten_MiscServices().IsEntityVisible(*targetEntity)) {
            continue;
        }
        const float dx = targetEntity->origin.x - origin.x;
        const float dy = targetEntity->origin.y - origin.y;
        const float fraction = Clamp01((dx * dx + dy * dy - innerSquared)
            / denominator);
        const float horizonScale = 1.0f - fraction * 0.9999f;
        const idVec3 requested(horizonScale, horizonScale, horizonScale);
        if ((targetEntity->scale - requested).LengthSqr() > 0.00000001f) {
            targetEntity->SetScale(requested);
        }
    }
}

// Retail: 0x82C6E708 ??0idStaticEntity@@QAA@XZ
idStaticEntity::idStaticEntity() : bsp(false), aas(false) {
    flags.forcePhysicsUpdate = true;
}

// Retail: 0x82C71058 ?Spawn@idStaticEntity@@QAAXXZ
void idStaticEntity::Spawn() {
    contents = 1;
    Tungsten_MiscServices().ConfigureStaticEntity(*this, bsp, aas);
}

// Retail: 0x82C71140 ??0idDynamicEntity@@QAA@XZ
idDynamicEntity::idDynamicEntity()
    : hide(false), castsDimShadows(false), solid(true),
      megaModelSpawnPosition(0.0f, 0.0f, 0.0f), highlightColor(0),
      colorModulateTable(nullptr), colorModulateTimeScale(1.0f),
      colorModulateActive(false), spawnTime(0), active(false),
      runGui(false), fade(), colorPreModulate(0.0f, 0.0f, 0.0f, 0.0f) {
    flags.forcePhysicsUpdate = true;
    SetClipReplicationFlags(true, true);
}

// Retail: 0x82C497B0 ??1idDynamicEntity@@UAA@XZ
idDynamicEntity::~idDynamicEntity() = default;

// Retail: 0x82C71278 ?Spawn@idDynamicEntity@@QAAXXZ
void idDynamicEntity::Spawn() {
    contents = solid && !hide ? 1 : 0;
    if (hide) idEntity::Hide();
    if (megaModel && megaModelSpawnPosition.LengthSqr() > 0.0f) {
        SetOrigin(megaModelSpawnPosition);
    }
    spawnTime = Tungsten_MiscServices().GetGameMilliseconds();
    active = false;
    fade = idMiscFadeState();
    idEntity::GetColor(colorPreModulate);
    if (colorModulateTable != nullptr && colorModulateActive) BecomeActive(1);
}

// Retail: 0x82C6E7C8 ?UpdateColorModulate@idDynamicEntity@@AAAXXZ
void idDynamicEntity::UpdateColorModulate() {
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    float modulation = 1.0f;
    if (colorModulateTable != nullptr && colorModulateActive) {
        modulation = Tungsten_MiscServices().SampleTable(colorModulateTable,
            now * 0.001f * colorModulateTimeScale);
    }
    const idVec4 modulated(colorPreModulate.x * modulation,
        colorPreModulate.y * modulation, colorPreModulate.z * modulation,
        colorPreModulate.w * modulation);
    const idVec3 wind = globalWind != nullptr
        ? globalWind->GetCurrentWindDirection()
        : idVec3(0.0f, 0.0f, 0.0f);
    const float strength = globalWind != nullptr
        ? globalWind->GetCurrentWindStrength() : 0.0f;
    const float fadeValue = fade.endTime > 0 ? fade.Evaluate(now) : 1.0f;
    Tungsten_MiscServices().UpdateDynamicEntity(*this, modulated,
        fadeValue, wind, strength);
}

// Retail: 0x82C6E8D8 ?Hide@idDynamicEntity@@UAAXXZ
void idDynamicEntity::Hide() {
    idEntity::Hide();
    contents = 0;
}

// Retail: 0x82C6E968 ?Show@idDynamicEntity@@UAAXXZ
void idDynamicEntity::Show() {
    idEntity::Show();
    if (solid) contents = 1;
}

// Retail: 0x82C6EA00 ?OnActivate@idDynamicEntity@@EAAXPAVidEntity@@@Z
void idDynamicEntity::OnActivate(idEntity*) {
    spawnTime = Tungsten_MiscServices().GetGameMilliseconds();
    active = !active;
    if (active) Show(); else Hide();
}

// Retail: 0x82C6EB08 ?Event_Fade@idDynamicEntity@@AAA?AVeventVoid@@MMM@Z
void idDynamicEntity::Event_Fade(const float from, const float to,
        const float seconds) {
    fade.Start(from, to, static_cast<int>(seconds * 1000.0f),
        Tungsten_MiscServices().GetGameMilliseconds(), false);
    BecomeActive(1);
}

// Retail: 0x82C6EB88 ?Event_FadeNoStipple@idDynamicEntity@@...
void idDynamicEntity::Event_FadeNoStipple(const float from, const float to,
        const float seconds) {
    fade.Start(from, to, static_cast<int>(seconds * 1000.0f),
        Tungsten_MiscServices().GetGameMilliseconds(), true);
    BecomeActive(1);
}

// Retail: 0x82C6EC08 ?Event_ActivateColorModulate@idDynamicEntity@@...
void idDynamicEntity::Event_ActivateColorModulate() {
    if (colorModulateActive) return;
    colorModulateActive = true;
    if (colorModulateTable != nullptr) {
        BecomeActive(1);
        UpdateColorModulate();
    }
}

// Retail: 0x82C6EC78 ?Event_DeactivateColorModulate@idDynamicEntity@@...
void idDynamicEntity::Event_DeactivateColorModulate() {
    if (!colorModulateActive) return;
    colorModulateActive = false;
    Tungsten_MiscServices().UpdateDynamicEntity(*this, colorPreModulate,
        1.0f, idVec3(0.0f, 0.0f, 0.0f), 0.0f);
}

// Retail: 0x82C714F0 ?SetColor@idDynamicEntity@@UAAXMMMM@Z
void idDynamicEntity::SetColor(const float red, const float green,
        const float blue, const float alpha) {
    colorPreModulate = idVec4(red, green, blue, alpha);
    idEntity::SetColor(red, green, blue, alpha);
    UpdateColorModulate();
}

// Retail: 0x82C715B0 ?SetColor@idDynamicEntity@@UAAXMMM@Z
void idDynamicEntity::SetColor(const float red, const float green,
        const float blue) { SetColor(red, green, blue, 1.0f); }

// Retail: 0x82C71678 ?SetColor@idDynamicEntity@@UAAXABVidVec3@@@Z
void idDynamicEntity::SetColor(const idVec3& value) {
    SetColor(value.x, value.y, value.z, 1.0f);
}

// Retail: 0x82C71748 ?SetColor@idDynamicEntity@@UAAXABVidVec4@@@Z
void idDynamicEntity::SetColor(const idVec4& value) {
    SetColor(value.x, value.y, value.z, value.w);
}

// Retail: 0x82C71818 ?SetColor@idDynamicEntity@@UAAXABVidColor@@@Z
void idDynamicEntity::SetColor(const idColor& value) {
    SetColor(value.r, value.g, value.b, value.a);
}

// Retail: 0x82C718E8 ?GetColor@idMover@@UBAXAAVidVec3@@@Z
void idDynamicEntity::GetColor(idVec3& out) const {
    out.Set(colorPreModulate.x, colorPreModulate.y, colorPreModulate.z);
}

// Retail: 0x82C71A60 ?GetColor@idMover@@UBAXAAVidVec4@@@Z
void idDynamicEntity::GetColor(idVec4& out) const { out = colorPreModulate; }

// Retail: 0x82C719A0 ?GetColor@idDynamicEntity@@UBAXAAVidColor@@@Z
void idDynamicEntity::GetColor(idColor& out) const {
    out = ColorValue(colorPreModulate);
}

// Retail: 0x82C77300 ?Think@idDynamicEntity@@UAAXXZ
void idDynamicEntity::Think() {
    idEntity::Think();
    if ((thinkFlags & 1) == 0) return;
    UpdateColorModulate();
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    if (!fade.IsActive(now) && colorModulateTable == nullptr
            && globalWind == nullptr) {
        BecomeInactive(1);
    }
}

// Retail: 0x82C71B20 ??0idParticleEmitter@@QAA@XZ
idParticleEmitter::idParticleEmitter()
    : fadeIn(0.5f), hidden(false), fadeOut(0.5f), startOff(false),
      alphaScale(1.0f), cycleTrigger(false), useGlobalShadows(false),
      useSmokeSystem(false), startDelay(0),
      distributionScale(1.0f, 1.0f, 1.0f), smokeSystemRate(1),
      inheritMasterVelocity(false), masterVelocityScale(1.0f),
      particleSystem(nullptr), particleConfigured(false) {}

// Retail: 0x82C6EE40 ??1idParticleEmitter@@UAA@XZ
idParticleEmitter::~idParticleEmitter() = default;

// Retail: 0x82C6E200 ?ShowEditingDialog@idParticleEmitter@@UAAXXZ
void idParticleEmitter::ShowEditingDialog() {
    Tungsten_MiscServices().OpenParticleEditor(*this);
}

// Retail: 0x82C6E220 ?UpdateEditingDialog@idParticleEmitter@@UAAXXZ
void idParticleEmitter::UpdateEditingDialog() {
    Tungsten_MiscServices().UpdateParticleEditor(*this);
}

// Retail: 0x82C6EED0 ?AllocPresentable@idParticleEmitter@@...
idPresentable* idParticleEmitter::AllocPresentable(idRenderModel* model) {
    return Tungsten_MiscServices().AllocateParticlePresentable(*this, model);
}

// Retail: 0x82C6EF70 ?Hide@idParticleEmitter@@UAAXXZ
void idParticleEmitter::Hide() {
    idDynamicEntity::Hide();
    BecomeInactive(1);
    hidden = true;
    Tungsten_MiscServices().TriggerParticle(*this, false);
    if (GetBindMaster() != nullptr) Unbind();
}

// Retail: 0x82C71C18 ?Show@idParticleEmitter@@UAAXXZ
void idParticleEmitter::Show() {
    idDynamicEntity::Show();
    BecomeActive(1);
    hidden = false;
    UpdatePresentable();
}

// Retail: 0x82C6EFC8 ?GetScale@idParticleEmitter@@UBAXAAVidVec3@@@Z
void idParticleEmitter::GetScale(idVec3& out) const {
    out = distributionScale;
}

// Retail: 0x82C71C60 ?SetScale@idParticleEmitter@@UAAXABVidVec3@@@Z
void idParticleEmitter::SetScale(const idVec3& value) {
    distributionScale = value;
    idEntity::SetScale(value);
    UpdatePresentable();
}

// Retail: 0x82C6EFE8 ?UpdatePresentable@idParticleEmitter@@AAAXXZ
void idParticleEmitter::UpdatePresentable() {
    Tungsten_MiscServices().UpdateParticle(*this);
}

// Retail: 0x82C71D10 ?SetParticle@idParticleEmitter@@AAAXPBVidDeclParticle@@@Z
void idParticleEmitter::SetParticle(const idDeclParticle* particle) {
    particleSystem = particle;
    particleConfigured = particle != nullptr;
    SetNoShadows(true);
    Tungsten_MiscServices().ConfigureParticle(*this, particle);
    UpdatePresentable();
}

// Retail: 0x82C6F0F0 ?OnActivate@idParticleEmitter@@UAAXPAVidEntity@@@Z
void idParticleEmitter::OnActivate(idEntity*) {
    if (cycleTrigger || hidden) {
        Event_TriggerShow();
        return;
    }
    Tungsten_MiscServices().TriggerParticle(*this, false);
    if (fadeOut <= 0.0f) {
        Hide();
    } else {
        Event_Fade(1.0f, 0.0f, fadeOut);
    }
}

// Retail: 0x82C741D8 ?Spawn@idParticleEmitter@@QAAXXZ
void idParticleEmitter::Spawn() {
    if (!useSmokeSystem) SetParticle(particleSystem);
    hidden = startOff;
    if (startOff) {
        idDynamicEntity::Hide();
        UpdateVisuals();
    } else {
        if (useSmokeSystem) BecomeActive(1);
        UpdatePresentable();
    }
}

// Retail: 0x82C74278 ?Event_TriggerShow@idParticleEmitter@@...
void idParticleEmitter::Event_TriggerShow() {
    Show();
    if (!useSmokeSystem && !particleConfigured) SetParticle(particleSystem);
    if (fadeIn > 0.0f) Event_Fade(0.0f, 1.0f, fadeIn);
    Tungsten_MiscServices().TriggerParticle(*this, true);
    ActivateTargets(this);
}

// Retail: 0x82C745C8 ?UpdateModifiedProperties@idParticleEmitter@@UAAXXZ
void idParticleEmitter::UpdateModifiedProperties() {
    particleConfigured = false;
    SetParticle(particleSystem);
}

// Retail: 0x82C77460 ?Think@idParticleEmitter@@UAAXXZ
void idParticleEmitter::Think() {
    idDynamicEntity::Think();
    if ((thinkFlags & 1) == 0) return;
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    if (useSmokeSystem && particleSystem != nullptr
            && (smokeSystemRate <= 1
                || Tungsten_MiscServices().GetGameFrame()
                    % smokeSystemRate == 0)) {
        idEntity* source = this;
        if (inheritMasterVelocity && GetBindMaster() != nullptr) {
            source = GetBindMaster();
        }
        const idVec3 velocity = source->linearVelocity * masterVelocityScale;
        Tungsten_MiscServices().EmitSmokeParticle(*this, particleSystem,
            now, velocity, Tungsten_MiscServices().RandomFloat());
    }
    if (fade.endTime > 0 && !fade.IsActive(now)
            && fade.to <= 0.0f && !cycleTrigger) {
        Hide();
    }
}

// Retail: 0x82C72180 ??0idElectricBoltEmitter@@QAA@XZ
idElectricBoltEmitter::idElectricBoltEmitter()
    : maxConeAngle(360.0f), minResetTime(500), maxResetTime(1250),
      startOff(false), electricBoltSystem(nullptr), sndPowerDown(nullptr),
      sndPowerUp(nullptr), length(10.0f, 20.0f), controlPath(nullptr),
      loopControlPath(false), controlPathGrowTime(0),
      electricBoltAllocated(false), nextResetTime(-1) {}

// Retail: 0x82C72230 ??1idElectricBoltEmitter@@UAA@XZ
idElectricBoltEmitter::~idElectricBoltEmitter() {
    if (electricBoltAllocated) Tungsten_MiscServices().FreeElectricBolt(*this);
    electricBoltAllocated = false;
}

// Retail: 0x82C6F230 ?AllocPresentable@idElectricBoltEmitter@@...
idPresentable* idElectricBoltEmitter::AllocPresentable(idRenderModel* model) {
    return Tungsten_MiscServices().AllocateElectricBoltPresentable(*this,
        model);
}

// Retail: 0x82C6F2F8 ?GetNextEndPos@idElectricBoltEmitter@@...
idVec3 idElectricBoltEmitter::GetNextEndPos(idEntity* targetEntity) {
    if (targetEntity != nullptr) {
        return targetEntity->origin
            + (targetEntity->bounds[0] + targetEntity->bounds[1]) * 0.5f;
    }
    const float yaw = (Tungsten_MiscServices().RandomFloat() * 2.0f - 1.0f)
        * 180.0f;
    const float cone = (Tungsten_MiscServices().RandomFloat() * 2.0f - 1.0f)
        * maxConeAngle * 0.5f;
    const float yawRadians = yaw * kPi / 180.0f;
    const float coneRadians = cone * kPi / 180.0f;
    const idVec3 radial = axis[1] * std::cos(yawRadians)
        + axis[2] * std::sin(yawRadians);
    const idVec3 direction = Normalize(axis[0] * std::cos(coneRadians)
        + radial * std::sin(coneRadians));
    const float distance = length.x + (length.y - length.x)
        * Tungsten_MiscServices().RandomFloat();
    return origin + direction * distance;
}

// Retail: 0x82C6F9A8 ?Hide@idElectricBoltEmitter@@UAAXXZ
void idElectricBoltEmitter::Hide() {
    idDynamicEntity::Hide();
    Tungsten_MiscServices().StopElectricBolt(*this);
    if (sndPowerDown != nullptr) StartSoundShader(1, sndPowerDown, 0, true);
}

// Retail: 0x82C6F9D8 ?Show@idElectricBoltEmitter@@UAAXXZ
void idElectricBoltEmitter::Show() {
    idDynamicEntity::Show();
    BecomeActive(1);
}

// Retail: 0x82C6FA08 ?Event_Deactivate@idElectricBoltEmitter@@...
void idElectricBoltEmitter::Event_Deactivate() { Hide(); }

// Retail: 0x82C722F0 ?SetControlPath@idElectricBoltEmitter@@...
void idElectricBoltEmitter::SetControlPath(idSplinePath* path) {
    controlPath = path;
}

// Retail: 0x82C747F0 ?GetNextTarget@idElectricBoltEmitter@@AAAPAVidEntity@@XZ
idEntity* idElectricBoltEmitter::GetNextTarget() {
    if (targets.Num() == 0) return nullptr;
    return targets[Tungsten_MiscServices().RandomInt(0, targets.Num() - 1)];
}

// Retail: 0x82C748D0 ?ResetTarget@idElectricBoltEmitter@@AAAXXZ
void idElectricBoltEmitter::ResetTarget() {
    if (!electricBoltAllocated) return;
    idEntity* selected = GetNextTarget();
    const idVec3 end = GetNextEndPos(selected);
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    Tungsten_MiscServices().StartElectricBolt(*this, now, origin, end,
        Tungsten_MiscServices().RandomFloat());
    nextResetTime = now + RandomDuration(minResetTime, maxResetTime);
    if (selected != nullptr) selected->ActivateTargets(this);
}

// Retail: 0x82C775D0 ?TurnOn@idElectricBoltEmitter@@AAAXXZ
void idElectricBoltEmitter::TurnOn() {
    if (sndPowerUp != nullptr) StartSoundShader(1, sndPowerUp, 0, true);
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    if (controlPath != nullptr) {
        Tungsten_MiscServices().StartElectricBoltPath(*this, controlPath,
            now, Tungsten_MiscServices().RandomFloat());
    } else {
        ResetTarget();
    }
}

// Retail: 0x82C77708 ?OnActivate@idElectricBoltEmitter@@UAAXPAVidEntity@@@Z
void idElectricBoltEmitter::OnActivate(idEntity*) {
    if (!electricBoltAllocated) {
        Tungsten_MiscServices().AllocateElectricBolt(*this,
            electricBoltSystem);
        electricBoltAllocated = true;
    }
    if (flags.hidden) {
        Show();
        TurnOn();
    } else {
        Hide();
    }
}

// Retail: 0x82C78598 ?Spawn@idElectricBoltEmitter@@QAAXXZ
void idElectricBoltEmitter::Spawn() {
    if (electricBoltAllocated) Tungsten_MiscServices().FreeElectricBolt(*this);
    Tungsten_MiscServices().AllocateElectricBolt(*this, electricBoltSystem);
    electricBoltAllocated = true;
    if (startOff) Hide();
    else {
        Show();
        TurnOn();
    }
}

// Retail: 0x82C78798 ?UpdateControlPath@idElectricBoltEmitter@@...
void idElectricBoltEmitter::UpdateControlPath(idSplinePath* path) {
    if (path != nullptr) {
        Tungsten_MiscServices().UpdateElectricBolt(*this, path,
            Tungsten_MiscServices().GetGameMilliseconds(), loopControlPath);
    }
}

// Retail: 0x82C78980 ?Think@idElectricBoltEmitter@@UAAXXZ
void idElectricBoltEmitter::Think() {
    idDynamicEntity::Think();
    if ((thinkFlags & 1) == 0 || !electricBoltAllocated) return;
    UpdateControlPath(controlPath);
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    Tungsten_MiscServices().UpdateElectricBolt(*this, controlPath, now,
        loopControlPath);
    if (nextResetTime > 0 && now > nextResetTime) ResetTarget();
}

// Retail: 0x82C72410 ??0idRibbonEmitter@@QAA@XZ
idRibbonEmitter::idRibbonEmitter()
    : hidden(false), startOff(false), cycleTrigger(false),
      declRibbon(nullptr), ribbonActive(false) {}

// Retail: 0x82C6F9F8 ??1idRibbonEmitter@@UAA@XZ
idRibbonEmitter::~idRibbonEmitter() {
    if (ribbonActive) Tungsten_MiscServices().StopRibbon(*this);
}

// Retail: 0x82C6FA58 ?Spawn@idRibbonEmitter@@QAAXXZ
void idRibbonEmitter::Spawn() {
    hidden = startOff;
    if (startOff) Hide();
    else Show();
}

// Retail: 0x82C6FAE0 ?Show@idRibbonEmitter@@UAAXXZ
void idRibbonEmitter::Show() {
    idDynamicEntity::Show();
    hidden = false;
    ribbonActive = true;
    Tungsten_MiscServices().StartRibbon(*this, declRibbon,
        Tungsten_MiscServices().GetGameMilliseconds());
    BecomeActive(1);
}

void idRibbonEmitter::Hide() {
    idDynamicEntity::Hide();
    hidden = true;
    if (ribbonActive) Tungsten_MiscServices().StopRibbon(*this);
    ribbonActive = false;
    BecomeInactive(1);
}

// Retail: 0x82C6FB20 ?OnActivate@idRibbonEmitter@@UAAXPAVidEntity@@@Z
void idRibbonEmitter::OnActivate(idEntity*) {
    if (cycleTrigger || hidden) Show(); else Hide();
}

// Retail: 0x82C77908 ?Think@idRibbonEmitter@@UAAXXZ
void idRibbonEmitter::Think() {
    idDynamicEntity::Think();
    if ((thinkFlags & 1) != 0 && ribbonActive) {
        Tungsten_MiscServices().UpdateRibbon(*this,
            Tungsten_MiscServices().GetGameMilliseconds());
    }
}

// Retail: 0x82C724F8 ??0idLensFlare@@QAA@XZ
idLensFlare::idLensFlare()
    : startOff(false), cycleTrigger(false), declFlare(nullptr),
      quadSize(16.0f), fadeStart(400.0f), fadeEnd(0.0f),
      sunDirection(0.0f, 0.0f, 0.0f), sunGlareSnd(nullptr),
      sunGlareSndVolumeTbl(nullptr), sunGlareSndPitchTbl(nullptr),
      sunGlareEnv(nullptr), sunGlareEnvFadeOutTime(1000),
      sunGlareEnvDotThreshold(0.9f), colorModulateTbl(nullptr),
      modulateTimeScale(1.0f), occlusionQuadOffset(0.0f, 0.0f, 0.0f),
      autospriteOcclusionQuad(false), maxSunGlareScale(2.0f),
      sunGlareEnvActive(false), flareInitialized(false) {}

// Retail: 0x82C6FAD8 ??1idLensFlare@@UAA@XZ
idLensFlare::~idLensFlare() {
    if (flareInitialized) Tungsten_MiscServices().StopFlare(*this);
}

// Retail: 0x82C6FB60 ?Hide@idLensFlare@@UAAXXZ
void idLensFlare::Hide() {
    idDynamicEntity::Hide();
    BecomeInactive(1);
    Tungsten_MiscServices().StopFlare(*this);
}

// Retail: 0x82C6FBA0 ?Show@idLensFlare@@UAAXXZ
void idLensFlare::Show() {
    idDynamicEntity::Show();
    BecomeActive(1);
    if (!flareInitialized) SetFlare();
}

// Retail: 0x82C72668 ?SetFlare@idLensFlare@@AAAXXZ
void idLensFlare::SetFlare() {
    if (declFlare == nullptr || flareInitialized) return;
    Tungsten_MiscServices().StartFlare(*this, declFlare);
    flareInitialized = true;
}

// Retail: 0x82C727E0 ?OnActivate@idLensFlare@@UAAXPAVidEntity@@@Z
void idLensFlare::OnActivate(idEntity*) {
    if (cycleTrigger && !flags.hidden && flareInitialized) Hide();
    else {
        SetFlare();
        Show();
    }
}

// Retail: 0x82C74A48 ?Spawn@idLensFlare@@QAAXXZ
void idLensFlare::Spawn() {
    if (startOff) Hide();
    else {
        SetFlare();
        BecomeActive(1);
    }
    if (sunGlareSnd != nullptr && sunDirection.LengthSqr() > 0.0f) {
        StartSoundShader(1, sunGlareSnd, 0, true);
        SetSoundVolume(1, -60.0f);
    }
}

// Retail: 0x82C74B20 ?Think@idLensFlare@@UAAXXZ
void idLensFlare::Think() {
    if (UpdateDormant()) return;
    RunPhysics();
    UpdateFX();
    if ((thinkFlags & 1) != 0 && flareInitialized) {
        Tungsten_MiscServices().UpdateFlare(*this,
            Tungsten_MiscServices().GetGameMilliseconds());
    }
}

// Retail: 0x82C6FC60 ??0idGodRays@@QAA@XZ
idGodRays::idGodRays()
    : isRelativeToCamera(true), direction(-512.0f, 264.0f, 536.0f),
      sourceSize(256), size(1280), raysColor(1.0f, 1.0f, 1.0f, 1.0f),
      colorScale(0.015f), texture(nullptr), enabled(false) {}

// Retail: 0x82C6FD10 ??1idGodRays@@UAA@XZ
idGodRays::~idGodRays() {
    enabled = false;
    Tungsten_MiscServices().SetGodRays(*this, false);
}

// Retail: 0x82C6FDC0 ?OnActivate@idGodRays@@UAAXPAVidEntity@@@Z
void idGodRays::OnActivate(idEntity*) {
    enabled = !enabled;
    Tungsten_MiscServices().SetGodRays(*this, enabled);
}

// Retail: 0x82C728B8 ?Spawn@idGodRays@@QAAXXZ
void idGodRays::Spawn() {
    if (sourceSize < 0 || size < sourceSize) {
        enabled = false;
        return;
    }
    OnActivate(this);
}

// Retail: 0x82C72DD0 ??0idFuncWind@@QAA@XZ
idFuncWind::idFuncWind()
    : sndWindLevel1(nullptr), sndWindLevel2(nullptr), sndWindLevel3(nullptr),
      minWindVolume(-60.0f), maxWindVolume(-30.0f),
      minGustDuration(10000), maxGustDuration(15000),
      minDistance(1024.0f), maxDistance(2048.0f),
      windStrengthStartVal(10.0f), windStrengthEndVal(30.0f),
      windAngle(0.0f), startOff(false), cycleTrigger(false),
      globalWind(false), fadeOut(0), windStrength() {}

// Retail: 0x82C6E2F8 ?Show@idFuncWind@@UAAXXZ
void idFuncWind::Show() {
    idEntity::Show();
    BecomeActive(1);
}

// Retail: 0x82C6E330 ?Hide@idFuncWind@@UAAXXZ
void idFuncWind::Hide() {
    idEntity::Hide();
    BecomeInactive(1);
    if (GetBindMaster() != nullptr) Unbind();
}

// Retail: 0x82C6FF50 ?GetCurrentWindDirection@idFuncWind@@...
idVec3 idFuncWind::GetCurrentWindDirection() const {
    const float radians = windAngle * kPi / 180.0f;
    return idVec3(std::cos(radians), std::sin(radians), 0.0f);
}

// Retail: 0x82C72F10 ?StartWind@idFuncWind@@AAAXXZ
void idFuncWind::StartWind() {
    BeginWindCycle(windStrength, windStrengthStartVal,
        windStrengthEndVal, minGustDuration, maxGustDuration);
    if (sndWindLevel1 != nullptr) StartSoundShader(10, sndWindLevel1, 0, true);
    if (sndWindLevel2 != nullptr) StartSoundShader(11, sndWindLevel2, 0, true);
    if (sndWindLevel3 != nullptr) StartSoundShader(12, sndWindLevel3, 0, true);
    SetSoundVolume(10, -60.0f);
    SetSoundVolume(11, -60.0f);
    SetSoundVolume(12, -60.0f);
}

// Retail: 0x82C73098 ?OnActivate@idFuncWind@@EAAXPAVidEntity@@@Z
void idFuncWind::OnActivate(idEntity*) {
    if (cycleTrigger || flags.hidden) {
        Show();
        StartWind();
    } else {
        const float seconds = fadeOut * 0.001f;
        FadeSound(10, -60.0f, seconds, false);
        FadeSound(11, -60.0f, seconds, false);
        FadeSound(12, -60.0f, seconds, false);
        windStrength = idMiscWindInterpolation();
        Hide();
    }
}

// Retail: 0x82C758B0 ?Spawn@idFuncWind@@QAAXXZ
void idFuncWind::Spawn() {
    if (globalWind) globalWind = this;
    if (startOff) {
        Hide();
        UpdateVisuals();
    } else {
        StartWind();
        Show();
    }
}

// Retail: 0x82C75950 ?Think@idFuncWind@@UAAXXZ
void idFuncWind::Think() {
    idEntity::Think();
    if ((thinkFlags & 1) == 0) return;
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    float strength = windStrength.Evaluate(now);
    if (windStrength.IsDone(now)) {
        const float next = strength <= windStrengthStartVal
            ? windStrengthEndVal : windStrengthStartVal;
        BeginWindCycle(windStrength, strength, next,
            minGustDuration, maxGustDuration);
        strength = windStrength.Evaluate(now);
    }
    SetSoundVolume(10, maxWindVolume + strength);
    SetSoundVolume(11, minWindVolume + strength);
    SetSoundVolume(12, minWindVolume + strength);
    Tungsten_MiscServices().UpdateWind(*this,
        GetCurrentWindDirection(), strength, -1);
    UpdateVisuals();
}

// Retail: 0x82C75B40 ?GetCurrentWindStrength@idFuncWind@@QBAMXZ
float idFuncWind::GetCurrentWindStrength() const {
    return windStrength.Evaluate(
        Tungsten_MiscServices().GetGameMilliseconds());
}

// Retail: 0x82C731A8 ??0idWindEmitter@@QAA@XZ
idWindEmitter::idWindEmitter()
    : sndBaseWind(nullptr), sndGustOverlay{nullptr, nullptr, nullptr},
      gustWeight(0.5f), minWindVolume(-60.0f), maxWindVolume(-30.0f),
      minDistance(1024.0f), maxDistance(2048.0f),
      minGustDuration(10000), maxGustDuration(15000),
      windStrengthStartVal(10.0f), windStrengthEndVal(30.0f),
      windAngle(0.0f), gustCrossFadeTime(1500), startOff(false),
      fadeOut(0.0f), cycleTrigger(false), windStrength(),
      currGustOverlayIdx(-1) {}

// Retail: 0x82C6FFA8 ??1idWindEmitter@@UAA@XZ
idWindEmitter::~idWindEmitter() {
    Tungsten_MiscServices().EnableWindInfluence(*this, false);
}

// Retail: 0x82C70040 ?GetNextGustOverlay@idWindEmitter@@ABAHXZ
int idWindEmitter::GetNextGustOverlay() const {
    if (Tungsten_MiscServices().RandomFloat() <= gustWeight) return -1;
    const int result = Tungsten_MiscServices().RandomInt(0, 2);
    return result == currGustOverlayIdx ? -1 : result;
}

// Retail: 0x82C700F0 ?GetCurrentWindDirection@idWindEmitter@@...
idVec3 idWindEmitter::GetCurrentWindDirection() const {
    const float radians = windAngle * kPi / 180.0f;
    return idVec3(std::cos(radians), std::sin(radians), 0.0f);
}

float idWindEmitter::GetCurrentWindStrength() const {
    return windStrength.Evaluate(
        Tungsten_MiscServices().GetGameMilliseconds());
}

// Retail: 0x82C733B8 ?StartWind@idWindEmitter@@AAAXXZ
void idWindEmitter::StartWind() {
    BeginWindCycle(windStrength, windStrengthStartVal,
        windStrengthEndVal, minGustDuration, maxGustDuration);
    if (sndBaseWind != nullptr) StartSoundShader(10, sndBaseWind, 0, true);
    for (int index = 0; index < 3; ++index) {
        if (sndGustOverlay[index] != nullptr) {
            StartSoundShader(11 + index, sndGustOverlay[index], 0, true);
            SetSoundVolume(11 + index, -60.0f);
        }
    }
    SetSoundVolume(10, -60.0f);
}

// Retail: 0x82C73558 ?OnActivate@idWindEmitter@@EAAXPAVidEntity@@@Z
void idWindEmitter::OnActivate(idEntity*) {
    if (cycleTrigger || flags.hidden) {
        Show();
        StartWind();
    } else {
        FadeSound(10, -60.0f, fadeOut * 0.001f, false);
        if (currGustOverlayIdx >= 0) {
            FadeSound(11 + currGustOverlayIdx, -60.0f,
                fadeOut * 0.001f, false);
        }
        windStrength = idMiscWindInterpolation();
        Hide();
    }
}

// Retail: 0x82C75BB8 ?Spawn@idWindEmitter@@QAAXXZ
void idWindEmitter::Spawn() {
    Tungsten_MiscServices().EnableWindInfluence(*this, true);
    if (startOff) {
        Hide();
        UpdateVisuals();
    } else {
        Show();
        StartWind();
    }
}

// Retail: 0x82C75CC0 ?Think@idWindEmitter@@UAAXXZ
void idWindEmitter::Think() {
    idEntity::Think();
    if ((thinkFlags & 1) == 0) return;
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    float strength = windStrength.Evaluate(now);
    if (windStrength.IsDone(now)) {
        const float next = strength <= windStrengthStartVal
            ? windStrengthEndVal : windStrengthStartVal;
        BeginWindCycle(windStrength, strength, next,
            minGustDuration, maxGustDuration);
        const int overlay = GetNextGustOverlay();
        if (currGustOverlayIdx >= 0) {
            FadeSound(11 + currGustOverlayIdx, -60.0f,
                gustCrossFadeTime * 0.001f, false);
        }
        if (overlay >= 0 && sndGustOverlay[overlay] != nullptr) {
            StartSoundShader(11 + overlay, sndGustOverlay[overlay], 0, true);
            FadeSound(11 + overlay, 0.0f,
                gustCrossFadeTime * 0.001f, false);
        }
        currGustOverlayIdx = overlay;
        strength = windStrength.Evaluate(now);
    }
    SetSoundVolume(10, maxWindVolume + strength);
    Tungsten_MiscServices().UpdateWind(*this,
        GetCurrentWindDirection(), strength, currGustOverlayIdx);
    UpdateVisuals();
}

// Retail: 0x82C77EC8 ??0idInventoryStorage@@QAA@XZ
idInventoryStorage::idInventoryStorage() : inventory(), startingInventory() {}

// Retail: 0x82C77F08 ??1idInventoryStorage@@UAA@XZ
idInventoryStorage::~idInventoryStorage() = default;

// Retail: 0x82C70140 ?Spawn@idInventoryStorage@@QAAXXZ
void idInventoryStorage::Spawn() {
    for (int index = 0; index < startingInventory.Num(); ++index) {
        const idMiscInventoryEntry& entry = startingInventory[index];
        if (entry.item == nullptr || entry.count <= 0) continue;
        inventory.Append(entry);
        Tungsten_MiscServices().GiveStoredInventory(*this, entry);
    }
}

// Retail: 0x82C73870 ??0idDebrisEntity@@QAA@XZ
idDebrisEntity::idDebrisEntity() : dieTime(0) {
    solid = false;
    hide = false;
}

// Retail: 0x82C73908 ??1idDebrisEntity@@UAA@XZ
idDebrisEntity::~idDebrisEntity() = default;

// Retail: 0x82C70218 ?Spawn@idDebrisEntity@@QAAXXZ
void idDebrisEntity::Spawn() { flags.forcePhysicsUpdate = true; }

// Retail: 0x82C6E380 ?SetModelByName@idDebrisEntity@@UAAXPBD@Z
void idDebrisEntity::SetModelByName(const char* value) {
    idEntity::SetModelByName(value);
}

// Retail: 0x82C739F8 ?SetModel@idDebrisEntity@@UAAXPAVidRenderModel@@@Z
void idDebrisEntity::SetModel(idRenderModel* model) {
    idEntity::SetModel(model);
    Tungsten_MiscServices().ConfigureDebrisModel(*this, model);
}

// Retail: 0x82C70230 ?SetScale@idDebrisEntity@@UAAXABVidVec3@@@Z
void idDebrisEntity::SetScale(const idVec3& value) {
    idEntity::SetScale(value);
    Tungsten_MiscServices().ConfigureDebrisScale(*this, value);
}

// Retail: 0x82C780F8 ?Think@idDebrisEntity@@UAAXXZ
void idDebrisEntity::Think() {
    idDynamicEntity::Think();
    if (dieTime < Tungsten_MiscServices().GetGameMilliseconds()) {
        Hide();
        BecomeInactive(3);
    }
    RunPhysics();
}

// Retail: 0x82C765F0 ??0idAnnouncementManager@@QAA@XZ
idAnnouncementManager::idAnnouncementManager()
    : startDelay(0.0f), startDelayVariance(0.0f), startActive(true),
      iterationDelay(120.0f), iterationVariance(0.0f),
      chancePerIteration(1.0f), doVoiceOver(true),
      firstAnnouncement(nullptr), announcements(),
      firstAnnouncementVO(nullptr), announcementsVO(), talkerName(),
      active(false), playedFirst(false), nextPlayTime(0),
      lastAnnouncement(-1) {}

// Retail: 0x82C770D8 ??1idAnnouncementManager@@UAA@XZ
idAnnouncementManager::~idAnnouncementManager() = default;

// Retail: 0x82C705D8 ?Activate@idAnnouncementManager@@AAAXXZ
void idAnnouncementManager::Activate() {
    active = true;
    playedFirst = false;
    nextPlayTime = Tungsten_MiscServices().GetGameMilliseconds()
        + static_cast<int>(RandomVariance(startDelay,
            startDelayVariance) * 1000.0f);
    BecomeActive(1);
}

// Retail: 0x82C73BD8 ?Show@idAnnouncementManager@@UAAXXZ
void idAnnouncementManager::Show() {
    idEntity::Show();
    if (!active) Activate();
}

// Retail: 0x82C73C18 ?Spawn@idAnnouncementManager@@QAAXXZ
void idAnnouncementManager::Spawn() { if (startActive) Activate(); }

// Retail: 0x82C73C30 ?Deactivate@idAnnouncementManager@@AAAXXZ
void idAnnouncementManager::Deactivate() {
    active = false;
    BecomeInactive(1);
    Tungsten_MiscServices().StopAnnouncements(*this);
}

// Retail: 0x82C73CF0 ?PlayVoiceOver@idAnnouncementManager@@AAAXXZ
void idAnnouncementManager::PlayVoiceOver() {
    const idDeclVoiceOver* selected = nullptr;
    if (!playedFirst && firstAnnouncementVO != nullptr) {
        selected = firstAnnouncementVO;
    } else {
        selected = SelectVoiceOver(announcementsVO, lastAnnouncement);
    }
    playedFirst = true;
    if (selected != nullptr) {
        Tungsten_MiscServices().PlayAnnouncementVoiceOver(*this,
            selected, talkerName);
    }
}

// Retail: 0x82C76778 ?PlaySound@idAnnouncementManager@@AAAXXZ
void idAnnouncementManager::PlaySound() {
    if (doVoiceOver) {
        PlayVoiceOver();
        return;
    }
    const idSoundShader* selected = nullptr;
    if (!playedFirst && firstAnnouncement != nullptr) {
        selected = firstAnnouncement;
    } else {
        selected = SelectAnnouncement(announcements, lastAnnouncement);
    }
    playedFirst = true;
    if (selected != nullptr) {
        Tungsten_MiscServices().PlayAnnouncement(*this, selected);
    }
}

// Retail: 0x82C76720 ?Hide@idAnnouncementManager@@UAAXXZ
void idAnnouncementManager::Hide() {
    idEntity::Hide();
    if (active) Deactivate();
}

// Retail: 0x82C76760 ?OnActivate@idAnnouncementManager@@UAAXPAVidEntity@@@Z
void idAnnouncementManager::OnActivate(idEntity*) {
    if (active) Deactivate(); else Activate();
}

// Retail: 0x82C78110 ?Think@idAnnouncementManager@@UAAXXZ
void idAnnouncementManager::Think() {
    if (!active) return;
    const int now = Tungsten_MiscServices().GetGameMilliseconds();
    if (now <= nextPlayTime) return;
    if (!playedFirst
            || Tungsten_MiscServices().RandomFloat() <= chancePerIteration) {
        PlaySound();
    }
    nextPlayTime = now + static_cast<int>(RandomVariance(iterationDelay,
        iterationVariance) * 1000.0f);
}

// Retail: 0x82C76968 ??0idGuiEntity@@QAA@XZ
idGuiEntity::idGuiEntity()
    : used(false), initialState(INIT_STATE_INVALID),
      activeState(INIT_STATE_INVALID), nextState(INIT_STATE_INVALID),
      usable(false), guiSwf(nullptr), guiModel(nullptr), target(nullptr),
      initializedGuis(false), triggeredSound(nullptr), disableSaves(false),
      guiActive(false) {
    flags.canBecomeDormant = false;
}

// Retail: 0x82C78260 ??1idGuiEntity@@UAA@XZ
idGuiEntity::~idGuiEntity() {
    Tungsten_MiscServices().ReleaseGui(*this);
}

// Retail: 0x82C6E388 ?IsEverUsable@idGuiEntity@@UBA_NPBVidEntity@@@Z
bool idGuiEntity::IsEverUsable(const idEntity*) const { return usable; }

// Retail: 0x82C706C0 ?UpdateGuiModel@idGuiEntity@@AAAXXZ
void idGuiEntity::UpdateGuiModel() {
    Tungsten_MiscServices().UpdateGuiModel(*this,
        Tungsten_MiscServices().GetGameMilliseconds());
}

// Retail: 0x82C70818 ?PauseThink@idGuiEntity@@UAAXXZ
void idGuiEntity::PauseThink() { if (initializedGuis) UpdateGuiModel(); }

// Retail: 0x82C70838 ?IsGuiActive@idGuiEntity@@QBA_NXZ
bool idGuiEntity::IsGuiActive() const { return guiActive; }

// Retail: 0x82C70858 ?Event_ResetGuiEntity@idGuiEntity@@...
void idGuiEntity::Event_ResetGuiEntity() {
    guiActive = false;
    guiActive = true;
    activeState = INIT_STATE_INVALID;
    nextState = initialState;
}

// Retail: 0x82C708C0 ?Event_MoveToState@idGuiEntity@@...
void idGuiEntity::Event_MoveToState(const idGuiEntityInitialState state) {
    if (activeState != INIT_STATE_ONLINE) nextState = state;
}

// Retail: 0x82C708D8 ?Event_EnableInteract@idGuiEntity@@...
void idGuiEntity::Event_EnableInteract(const bool enable) {
    nextState = enable ? INIT_STATE_READY : INIT_STATE_OFFLINE;
}

// Retail: 0x82C708F8 ?ModifyCrosshairInfo@idGuiEntity@@...
bool idGuiEntity::ModifyCrosshairInfo(const idEntity*, const void*, int,
        void* crosshairInfo) const {
    if (crosshairInfo == nullptr) return false;
    idCrosshairInfo& info = *static_cast<idCrosshairInfo*>(crosshairInfo);
    info.color = idColor(1.0f, 1.0f, 1.0f, 1.0f);
    info.textColor = idColor(1.0f, 1.0f, 1.0f, 1.0f);
    info.colorState = used ? CROSSHAIR_COLOR_NEGATIVE
        : CROSSHAIR_COLOR_NORMAL;
    info.textColorState = used ? CROSSHAIR_TEXT_COLOR_NEGATIVE
        : CROSSHAIR_TEXT_COLOR_NORMAL;
    info.material = used ? CHMATERIAL_PROP : CHMATERIAL_DOOR;
    return true;
}

// Retail: 0x82C783E0 ?SetupGuiCallbacks@idGuiEntity@@AAAXXZ
void idGuiEntity::SetupGuiCallbacks() {
    initializedGuis = Tungsten_MiscServices().SetupGui(*this);
    guiActive = initializedGuis;
}

// Retail closures at 0x82C78888, 0x82C788A0, 0x82C79238,
// 0x82C79348, and 0x82C793B0.
void idGuiEntity::CallbackReactivateUsable() { used = false; }

bool idGuiEntity::CallbackTrigger(const char* entityName) {
    idEntity* entity = idEntity::Services().FindEntity(entityName);
    if (entity == nullptr) return false;
    entity->Activate(this);
    return true;
}

bool idGuiEntity::CallbackTriggerTarget() {
    if (target == nullptr) return false;
    target->Activate(this);
    return true;
}

void idGuiEntity::CallbackPlayGuiSound() {
    if (triggeredSound != nullptr) {
        Tungsten_MiscServices().PlayGuiSound(*this, triggeredSound);
    }
}

bool idGuiEntity::CallbackPostEvent(const char* entityName,
        const char* eventName, const idList<idStr, 5>& arguments) {
    return Tungsten_MiscServices().PostGuiEvent(*this, entityName,
        eventName, arguments);
}

// Retail: 0x82C79A90 ?SetFloat@idGuiEntity@@QAAXPBDM@Z
void idGuiEntity::SetFloat(const char* variableName, const float value) {
    Tungsten_MiscServices().SetGuiFloat(*this, variableName, value);
}

// Retail: 0x82C79B28 ?SetString@idGuiEntity@@QAAXPBD0@Z
void idGuiEntity::SetString(const char* variableName, const char* value) {
    Tungsten_MiscServices().SetGuiString(*this, variableName, value);
}

// Retail: 0x82C7A6B8 ?Spawn@idGuiEntity@@QAAXXZ
void idGuiEntity::Spawn() {
    SetupGuiCallbacks();
    if (!initializedGuis) {
        Remove();
        return;
    }
    nextState = initialState;
    if (initialState != INIT_STATE_READY) used = true;
    BecomeActive(1);
}

// Retail: 0x82C7AFE0 ?UpdateGuiState@idGuiEntity@@QAAXXZ
void idGuiEntity::UpdateGuiState() {
    if (nextState == activeState || !initializedGuis) return;
    Tungsten_MiscServices().ChangeGuiState(*this, activeState, nextState);
    activeState = nextState;
}

// Retail: 0x82C7B118 ?OnActivate@idGuiEntity@@UAAXPAVidEntity@@@Z
void idGuiEntity::OnActivate(idEntity* activator) {
    Tungsten_MiscServices().InvokeGui(*this, "triggered",
        activator != nullptr ? activator->name.c_str() : "");
}

// Retail: 0x82C7B1B0 ?Use@idGuiEntity@@UAA_NPAVidEntity@@...
bool idGuiEntity::Use(idEntity* activator, int) {
    if (used || activator == nullptr) return false;
    used = true;
    Tungsten_MiscServices().InvokeGui(*this, "use",
        activator->name.c_str());
    if (target != nullptr) target->Activate(activator);
    return true;
}

// Retail: 0x82C7B2E0 ?Think@idGuiEntity@@UAAXXZ
void idGuiEntity::Think() {
    if (!initializedGuis) {
        SetupGuiCallbacks();
        return;
    }
    if (UpdateDormant()) return;
    UpdateGuiModel();
    RunPhysics();
    UpdateFX();
    UpdateVisuals();
    UpdatePVSAreas();
    UpdateGuiState();
}

// Retail: 0x82C74028 ?RandomPath@idPathCorner@@SAPAV1@PBVidEntity@@0@Z
idPathCorner* idPathCorner::RandomPath(const idEntity* source,
        const idEntity* ignore) {
    if (source == nullptr) return nullptr;
    idList<idPathCorner*, 5> choices;
    for (int index = 0; index < source->targets.Num(); ++index) {
        idEntity* candidate = source->targets[index];
        if (candidate == nullptr || candidate == ignore) continue;
        idPathCorner* corner = dynamic_cast<idPathCorner*>(candidate);
        if (corner != nullptr) choices.Append(corner);
    }
    if (choices.Num() == 0) return nullptr;
    return choices[Tungsten_MiscServices().RandomInt(0, choices.Num() - 1)];
}

// Retail: 0x82C74190 ?Event_RandomPath@idPathCorner@@...
idPathCorner* idPathCorner::Event_RandomPath() {
    return RandomPath(this, nullptr);
}

// Retail: 0x82C74E20 ??0idFuncCloth@@QAA@XZ
idFuncCloth::idFuncCloth()
    : clothType(CLOTH_GENERATED), attachPoints(), clothSystem(nullptr),
      widthOverride(0), heightOverride(0), hSpacingOverride(0.0f),
      vSpacingOverride(0.0f), sphereCollision(), collidesWithPlayers(true),
      collidesWithAI(true), influencedByWind(false),
      influencedByBullets(true), clothModel(nullptr),
      clothInitialized(false) {}

// Retail: 0x82C74F48 ??1idFuncCloth@@UAA@XZ
idFuncCloth::~idFuncCloth() {
    if (clothInitialized) Tungsten_MiscServices().ReleaseCloth(*this);
}

// Retail: 0x82C77A18 ?InitialSetup@idFuncCloth@@QAAXXZ
void idFuncCloth::InitialSetup() {
    idVec3 wind(0.0f, 0.0f, 0.0f);
    if (influencedByWind && globalWind != nullptr) {
        wind = globalWind->GetCurrentWindDirection()
            * globalWind->GetCurrentWindStrength();
    }
    Tungsten_MiscServices().InitializeCloth(*this, wind);
}

// Retail: 0x82C78A20 ?Spawn@idFuncCloth@@QAAXXZ
void idFuncCloth::Spawn() {
    if (clothSystem == nullptr || clothType == CLOTH_INVALID) return;
    Tungsten_MiscServices().CreateCloth(*this, clothSystem);
    clothInitialized = true;
    InitialSetup();
    BecomeActive(1);
}

// Retail: 0x82C79C00 ?UpdateCloth@idFuncCloth@@IAAXXZ
void idFuncCloth::UpdateCloth() {
    if (!clothInitialized) return;
    idVec3 wind(0.0f, 0.0f, 0.0f);
    if (influencedByWind && globalWind != nullptr) {
        const float rotation = (Tungsten_MiscServices().RandomFloat()
            * 2.0f - 1.0f) * 22.5f * kPi / 180.0f;
        const idVec3 direction = globalWind->GetCurrentWindDirection();
        wind = idVec3(direction.x * std::cos(rotation)
                - direction.y * std::sin(rotation),
            direction.x * std::sin(rotation)
                + direction.y * std::cos(rotation), direction.z)
            * globalWind->GetCurrentWindStrength();
    }
    Tungsten_MiscServices().UpdateCloth(*this, wind,
        Tungsten_MiscServices().GetGameMilliseconds());
}

// Retail: 0x82C7A1D8 ?UpdateCollisions@idFuncCloth@@IAAXXZ
void idFuncCloth::UpdateCollisions() {
    if (clothInitialized) {
        Tungsten_MiscServices().UpdateClothCollisions(*this,
            collidesWithPlayers, collidesWithAI, influencedByBullets);
    }
}

// Retail: 0x82C7A498 ?Think@idFuncCloth@@UAAXXZ
void idFuncCloth::Think() {
    if (!clothInitialized) return;
    idEntity::Think();
    UpdateCollisions();
    UpdateCloth();
    UpdateVisuals();
}

// Retail: 0x82C77C70 ??0idRegimeTile@@QAA@XZ
idRegimeTile::idRegimeTile()
    : powerDownTime(5000), sndPowerDown(nullptr), sndReactivate(nullptr),
      propogationDelay(150), fadeTime(1500), pulseOnTime(3000),
      pulseOffTime(250), maxHealth(70.0f), nonEMPDamageScale(0.0f),
      healthReadout(nullptr), startOff(true), pulseEnabled(true),
      ignoresPulse(false), damageable(false), takeTriggerDmgOnly(false),
      master(true), shouldFadeOnActivate(true),
      tileType(REGIME_TILE_CHILD), tileChildren(), health(0.0f),
      childPropagationDelay(1500), nextActivateIdx(0), powered(false) {}

// Retail: 0x82C75280 ??1idRegimeTile@@UAA@XZ
idRegimeTile::~idRegimeTile() = default;

// Retail: 0x82C6E240 ?TurnOn@idRegimeTile@@AAAXXZ
void idRegimeTile::TurnOn() {
    if (sndReactivate != nullptr) StartSoundShader(1, sndReactivate, 0, true);
    Show();
    if (shouldFadeOnActivate) {
        fade.Start(0.0f, 1.0f, fadeTime,
            Tungsten_MiscServices().GetGameMilliseconds(), false);
        BecomeActive(1);
    }
    health = maxHealth;
    powered = true;
}

// Retail: 0x82C72968 ?Spawn@idRegimeTile@@QAAXXZ
void idRegimeTile::Spawn() {
    flags.takesDamage = damageable;
    if (damageable || master) {
        if (startOff) {
            Hide();
            powered = false;
        } else {
            TurnOn();
        }
        Event_PostSpawn();
    }
}

// Retail: 0x82C72A70 ?Damage@idRegimeTile@@UAAMPAVidEntity@@...
float idRegimeTile::Damage(idEntity* inflictor, idEntity*,
        const idDeclDamage* damage, const float damageScale,
        const idVec3&, trace_t*) {
    if (!damageable || !powered || damage == nullptr) return 0.0f;
    if (takeTriggerDmgOnly
            && !Tungsten_MiscServices().IsTriggerDamage(inflictor)) {
        return 0.0f;
    }
    const float amount = Tungsten_MiscServices().GetDamageAmount(damage)
        * damageScale * nonEMPDamageScale;
    health -= amount;
    if (healthReadout != nullptr) {
        const float fraction = maxHealth > 0.0f
            ? Clamp01(health / maxHealth) : 0.0f;
        healthReadout->SetColor(fraction, fraction, fraction, 1.0f);
    }
    if (health <= 0.0f) OnActivate(inflictor);
    return amount;
}

// Retail: 0x82C72C58 ?TurnOff@idRegimeTile@@AAAXXZ
void idRegimeTile::TurnOff() {
    StopSound(1, true);
    if (sndPowerDown != nullptr) StartSoundShader(2, sndPowerDown, 0, true);
    powered = false;
    if (shouldFadeOnActivate) {
        fade.Start(1.0f, 0.0f, fadeTime,
            Tungsten_MiscServices().GetGameMilliseconds(), false);
        BecomeActive(1);
    } else {
        Hide();
    }
    if (healthReadout != nullptr) {
        healthReadout->SetColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
}

// Retail: 0x82C75408 ?OnActivate@idRegimeTile@@EAAXPAVidEntity@@@Z
void idRegimeTile::OnActivate(idEntity*) {
    nextActivateIdx = 0;
    const bool poweringUp = !powered;
    if (poweringUp) TurnOn(); else TurnOff();
    if (tileChildren.Num() > 0) {
        Tungsten_MiscServices().ScheduleRegimePropagation(*this,
            poweringUp, propogationDelay);
    }
}

// Retail: 0x82C754B8 ?Event_PowerDown@idRegimeTile@@...
void idRegimeTile::Event_PowerDown() {
    if (nextActivateIdx < 0 || nextActivateIdx >= tileChildren.Num()) return;
    const int level = tileChildren[nextActivateIdx].index;
    while (nextActivateIdx < tileChildren.Num()
            && tileChildren[nextActivateIdx].index == level) {
        idMiscRegimeChild& child = tileChildren[nextActivateIdx++];
        Tungsten_MiscServices().SetRegimeChildPowered(*this, child, false);
        if (child.childEntity != nullptr) child.childEntity->Activate(this);
    }
    if (nextActivateIdx < tileChildren.Num()) {
        Tungsten_MiscServices().ScheduleRegimePropagation(*this, false,
            childPropagationDelay);
    }
}

// Retail: 0x82C757F8 ?Event_PowerUp@idRegimeTile@@...
void idRegimeTile::Event_PowerUp() {
    if (nextActivateIdx < 0 || nextActivateIdx >= tileChildren.Num()) return;
    const int level = tileChildren[nextActivateIdx].index;
    while (nextActivateIdx < tileChildren.Num()
            && tileChildren[nextActivateIdx].index == level) {
        idMiscRegimeChild& child = tileChildren[nextActivateIdx++];
        Tungsten_MiscServices().SetRegimeChildPowered(*this, child, true);
        if (child.childEntity != nullptr) child.childEntity->Activate(this);
    }
    if (nextActivateIdx < tileChildren.Num()) {
        Tungsten_MiscServices().ScheduleRegimePropagation(*this, true,
            childPropagationDelay);
    }
}

// Retail: 0x82C7A840 ?Event_PostSpawn@idRegimeTile@@...
void idRegimeTile::Event_PostSpawn() {
    tileChildren.Clear();
    struct PendingChild { idEntity* entity; int depth; };
    idList<PendingChild, 5> pending;
    for (int index = 0; index < targets.Num(); ++index) {
        if (targets[index] != nullptr) pending.Append({targets[index], 1});
    }
    for (int cursor = 0; cursor < pending.Num() && cursor < 128; ++cursor) {
        PendingChild item = pending[cursor];
        idRegimeTile* child = dynamic_cast<idRegimeTile*>(item.entity);
        if (child == nullptr) continue;
        idMiscRegimeChild recovered;
        recovered.index = item.depth;
        recovered.childEntity = child;
        recovered.sndPowerDown = child->sndPowerDown;
        recovered.sndReactivate = child->sndReactivate;
        recovered.presentable = Tungsten_MiscServices().PrepareRegimeChild(
            *this, *child);
        tileChildren.Append(recovered);
        for (int targetIndex = 0; targetIndex < child->targets.Num();
                ++targetIndex) {
            if (child->targets[targetIndex] != nullptr) {
                pending.Append({child->targets[targetIndex], item.depth + 1});
            }
        }
    }
    BecomeInactive(1);
}

// Retail: 0x82C763F8 ??0idEntityImposter@@QAA@XZ
idEntityImposter::idEntityImposter()
    : original(nullptr), animated(false), mimicking(false) {}

// Retail: 0x82C73680 ?Spawn@idEntityImposter@@QAAXXZ
void idEntityImposter::Spawn() {
    mimicking = false;
    if (original != nullptr) Event_MimicEntity();
}

// Retail: 0x82C736E8 ?Event_MimicEntity@idEntityImposter@@...
void idEntityImposter::Event_MimicEntity() {
    if (original == nullptr) return;
    Tungsten_MiscServices().MimicEntity(*this, *original, animated);
    mimicking = true;
    BecomeActive(1);
}

// Retail: 0x82C780D0 ?Think@idEntityImposter@@UAAXXZ
void idEntityImposter::Think() {
    if (mimicking && Tungsten_MiscServices().IsRendered(*this)) {
        idDynamicEntity::Think();
        UpdateVisuals();
    }
}

// Retail: 0x82C77160 ??0idCoopStartingInventory@@QAA@XZ
idCoopStartingInventory::idCoopStartingInventory()
    : playerOneItemList(), playerTwoItemList(), mirrorPlayerOne(false) {}

// Retail: 0x82C771F0 ??1idCoopStartingInventory@@UAA@XZ
idCoopStartingInventory::~idCoopStartingInventory() = default;

// Retail: 0x82C76B30 ?GiveItems@idCoopStartingInventory@@QAAXPAVidPlayer@@@Z
void idCoopStartingInventory::GiveItems(idPlayer* player) {
    if (player == nullptr) return;
    Tungsten_MiscServices().ClearPlayerInventory(*player);
    const idList<itemListElement_t, 5>* items = &playerOneItemList;
    if (!mirrorPlayerOne && playerTwoItemList.Num() > 0) {
        items = &playerTwoItemList;
    }
    for (int index = 0; index < items->Num(); ++index) {
        const itemListElement_t& entry = (*items)[index];
        if (entry.item != nullptr && entry.count > 0) {
            Tungsten_MiscServices().GivePlayerInventory(*player,
                entry.item, entry.count);
        }
    }
}

// Retail: 0x82C78540 ?Spawn@idCoopStartingInventory@@QAAXXZ
void idCoopStartingInventory::Spawn() {
    Tungsten_MiscServices().RegisterCoopStartingInventory(this);
}

// Retail: 0x82C70490 ??0idReferenceMap@@QAA@XZ
idReferenceMap::idReferenceMap() : mapname(), zeroTransform(false) {}

// Retail: 0x82C704F8 ??1idReferenceMap@@UAA@XZ
idReferenceMap::~idReferenceMap() = default;

// Retail: 0x82C6E390 ?Spawn@idReferenceMap@@QAAXXZ
void idReferenceMap::Spawn() {
    contents = 0;
    Remove();
}
