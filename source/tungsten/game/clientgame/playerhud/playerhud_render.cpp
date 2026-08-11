#include "playerhud_render.h"

#include <initializer_list>

namespace {
idPlayerHudRenderServices* g_playerHudServices = nullptr;

void InvokeHud(idSWF* const hud, const char* const function,
        const std::initializer_list<idHudValue> values) {
    if (g_playerHudServices != nullptr)
        g_playerHudServices->Invoke(hud, function, values.begin(),
            static_cast<int>(values.size()));
}
} // namespace

idHudValue idHudValue::Integer(const int value) {
    return {VALUE_INTEGER, value, 0.0f, nullptr};
}

idHudValue idHudValue::Float(const float value) {
    return {VALUE_FLOAT, 0, value, nullptr};
}

idHudValue idHudValue::Boolean(const bool value) {
    return {VALUE_BOOLEAN, value ? 1 : 0, 0.0f, nullptr};
}

idHudValue idHudValue::String(const char* const value) {
    return {VALUE_STRING, 0, 0.0f, value != nullptr ? value : ""};
}

void Tungsten_SetPlayerHudRenderServices(
        idPlayerHudRenderServices* const services) {
    g_playerHudServices = services;
}

// Retail symbol: ?NoteSwfForBuildGame@idPlayerHud_Render@@SAXXZ
// EA: 0x82B64118, RVA: 0x00B64118
void idPlayerHud_Render::NoteSwfForBuildGame() {
    if (g_playerHudServices != nullptr)
        g_playerHudServices->RegisterSWFResources("tunghud");
}

// Retail symbol: ??0idPlayerHud_Render@@QAA@XZ
// EA: 0x82B64128, RVA: 0x00B64128
idPlayerHud_Render::idPlayerHud_Render()
    : hud(nullptr), showScoreboard(false), playerNum(-1),
      minigameResult(-1), minigameStage(0),
      minigameRangeIndicator(0.0f) {}

// Retail symbol: ?IsPlayerControlInhibited@idPlayerHud_Render@@QAA_NXZ
// EA: 0x82B64150, RVA: 0x00B64150
bool idPlayerHud_Render::IsPlayerControlInhibited() {
    if (hud == nullptr || g_playerHudServices == nullptr) return false;
    return g_playerHudServices->IsMainMenuActive() ||
        g_playerHudServices->IsPlayerControlInhibited(hud);
}

// Retail symbol: ?Cleanup@idPlayerHud_Render@@QAAXXZ
// EA: 0x82B641E0, RVA: 0x00B641E0
void idPlayerHud_Render::Cleanup() {
    if (hud != nullptr && g_playerHudServices != nullptr)
        g_playerHudServices->ClearEmitter(hud, true);
}

// Retail symbol: ?HandleGuiEvent@idPlayerHud_Render@@QAA_NPBUsysEvent_t@@@Z
// EA: 0x82B641F8, RVA: 0x00B641F8
bool idPlayerHud_Render::HandleGuiEvent(const sysEvent_t* const event) {
    return hud != nullptr && g_playerHudServices != nullptr &&
        g_playerHudServices->HandleEvent(hud, event);
}

// Retail symbol: ?SetPlayerNum@idPlayerHud_Render@@QAAXH@Z
// EA: 0x82B64210, RVA: 0x00B64210
void idPlayerHud_Render::SetPlayerNum(const int player) {
    playerNum = player;
    if (hud != nullptr && g_playerHudServices != nullptr)
        g_playerHudServices->SetListener(hud, player + 1);
}

// Retail symbol: ?Init@idPlayerHud_Render@@QAAXPBVidStr@@@Z
// EA: 0x82B64228, RVA: 0x00B64228
void idPlayerHud_Render::Init(const idStr*) {
    if (g_playerHudServices != nullptr)
        hud = g_playerHudServices->CreateSWF("tunghud", false);
}

// Retail symbol: ??1idPlayerHud_Render@@UAA@XZ
// EA: 0x82B642E8, RVA: 0x00B642E8
idPlayerHud_Render::~idPlayerHud_Render() {
    if (hud != nullptr && g_playerHudServices != nullptr)
        g_playerHudServices->DestroySWF(hud);
    hud = nullptr;
}

// Retail symbol: ?SetIconMaterial@idPlayerHud_Render@@AAAXPBDPBVidMaterial@@@Z
// EA: 0x82B643C0, RVA: 0x00B643C0
void idPlayerHud_Render::SetIconMaterial(const char* const name,
        const idMaterial* const material) {
    if (hud != nullptr && g_playerHudServices != nullptr)
        g_playerHudServices->SetIconMaterial(hud, name, material);
}

// Retail symbol: ?Render@idPlayerHud_Render@@QAAXPAVidRenderModelGui@@AAVidHudInfo@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA: 0x82B644B8, RVA: 0x00B644B8
void idPlayerHud_Render::Render(idRenderModelGui* const guiModel,
        idHudInfo& current, const int currentTime, const renderView_t*,
        const idRenderWorld*) {
    if (hud == nullptr || g_playerHudServices == nullptr ||
            !g_playerHudServices->ShowHud()) return;

    const bool saving = g_playerHudServices->SaveGameHasWork();
    if (g_playerHudServices->IsGamePaused() && !saving) return;
    g_playerHudServices->Activate(hud, true);

    InvokeHud(hud, "UpdateBottomBar", {
        idHudValue::Boolean(current.showBottomBar)
    });
    InvokeHud(hud, "UpdateHealthAndArmor", {
        idHudValue::Integer(current.healthIndicator.health),
        idHudValue::Integer(current.healthIndicator.armor),
        idHudValue::Float(current.damageLocator.directionX),
        idHudValue::Float(current.damageLocator.directionY),
        idHudValue::Float(current.damageLocator.intensity)
    });

    const idHudInfo::weaponAmmoStatus_t& rightPrimary =
        current.weaponAmmoStatus[0];
    const idHudInfo::weaponAmmoStatus_t& rightSecondary =
        current.weaponAmmoStatus[1];
    InvokeHud(hud, "UpdateAmmoGroupRight", {
        idHudValue::Boolean(rightPrimary.show),
        idHudValue::Boolean(rightSecondary.show),
        idHudValue::Boolean(rightPrimary.staticCounter),
        idHudValue::Integer(rightPrimary.nextAnimState),
        idHudValue::Integer(rightPrimary.ammoClipCount),
        idHudValue::Integer(rightPrimary.ammoTotalCount -
            rightPrimary.ammoClipCount),
        idHudValue::Integer(rightPrimary.burstMode),
        idHudValue::Integer(rightSecondary.ammoClipCount),
        idHudValue::Integer(rightSecondary.ammoTotalCount -
            rightSecondary.ammoClipCount),
        idHudValue::Integer(rightSecondary.burstMode),
        idHudValue::Boolean(rightPrimary.dwAvailable)
    });

    const idHudInfo::weaponAmmoStatus_t& leftPrimary =
        current.weaponAmmoStatus[2];
    const idHudInfo::weaponAmmoStatus_t& leftSecondary =
        current.weaponAmmoStatus[3];
    InvokeHud(hud, "UpdateAmmoGroupLeft", {
        idHudValue::Boolean(leftPrimary.show),
        idHudValue::Boolean(leftSecondary.show),
        idHudValue::Boolean(leftPrimary.staticCounter),
        idHudValue::Integer(leftPrimary.nextAnimState),
        idHudValue::Integer(leftPrimary.ammoClipCount),
        idHudValue::Integer(leftPrimary.burstMode),
        idHudValue::Integer(leftSecondary.ammoClipCount),
        idHudValue::Integer(leftSecondary.burstMode)
    });
    for (idHudInfo::weaponAmmoStatus_t& ammo : current.weaponAmmoStatus)
        ammo.renderReceipt = true;

    InvokeHud(hud, "UpdateSaving", {idHudValue::Boolean(saving)});

    for (int index = 0; index < current.combiners.NumAllocated(); ++index) {
        if (index >= current.combiners.Num()) {
            InvokeHud(hud, "UpdateCombinerHide", {
                idHudValue::Integer(index)
            });
            continue;
        }
        const idHudInfo::combiner_t& combiner = current.combiners[index];
        idHudValue values[8] = {
            idHudValue::Integer(index),
            idHudValue::Boolean(combiner.hovered),
            idHudValue::Integer(combiner.itemCount),
            idHudValue::Integer(combiner.itemValues[0]),
            idHudValue::Integer(combiner.itemValues[1]),
            idHudValue::Integer(combiner.itemValues[2]),
            idHudValue::Integer(combiner.itemValues[3]),
            idHudValue::Integer(combiner.itemValues[4])
        };
        g_playerHudServices->Invoke(hud, "UpdateCombinerCombine", values, 8);
        if (combiner.itemCount >= 1 && combiner.itemCount <= 5) {
            for (int item = 0; item < combiner.itemCount && item < 5;
                    ++item) {
                if (combiner.itemMaterials[item] != nullptr)
                    g_playerHudServices->SetCombinerItemMaterial(hud,
                        index, item, combiner.itemMaterials[item]);
            }
        }
    }

    InvokeHud(hud, "UpdateCrosshair", {
        idHudValue::Boolean(current.reticle.show),
        idHudValue::Integer(current.reticle.pulsate)
    });
    InvokeHud(hud, "UpdateAirSupply", {
        idHudValue::Boolean(current.airSupply.show),
        idHudValue::Float(current.airSupply.percent * 100.0f)
    });
    InvokeHud(hud, "UpdateBoss", {
        idHudValue::Integer(current.boss.numBars),
        idHudValue::Integer(current.boss.visibleBars),
        idHudValue::Float(current.boss.amount)
    });
    InvokeHud(hud, "UpdateLaserCutter", {
        idHudValue::Boolean(current.laserCutterStatus.show),
        idHudValue::Float(current.laserCutterStatus.charge),
        idHudValue::Boolean(current.laserCutterStatus.canShoot),
        idHudValue::Integer(current.laserCutterStatus.nextAnimState),
        idHudValue::Boolean(current.laserCutterStatus.cuttingMode),
        idHudValue::Boolean(current.laserCutterStatus.shootingFullAuto)
    });
    InvokeHud(hud, "UpdateFunctionalityLenses", {
        idHudValue::Boolean(current.laserCutterFuncLensStatus.showPrim),
        idHudValue::Boolean(current.laserCutterFuncLensStatus.showSec),
        idHudValue::Boolean(current.laserCutterFuncLensStatus.showStatic),
        idHudValue::Integer(
            current.laserCutterFuncLensStatus.nextAnimState),
        idHudValue::Integer(current.laserCutterFuncLensStatus.iconPrim),
        idHudValue::Integer(current.laserCutterFuncLensStatus.iconSec),
        idHudValue::Integer(current.laserCutterFuncLensStatus.iconStatic)
    });

    const bool hasReticleIcon = current.reticle.iconIndex != -1;
    if (!hasReticleIcon && current.help.show) {
        InvokeHud(hud, "UpdateInteraction", {
            idHudValue::Integer(1), idHudValue::String(""),
            idHudValue::Integer(-1), idHudValue::Integer(1),
            idHudValue::Integer(0), idHudValue::Integer(-1),
            idHudValue::Integer(0), idHudValue::Integer(-1),
            idHudValue::Integer(0), idHudValue::Integer(0)
        });
        SetIconMaterial("_interaction_icon0", current.help.icon);
        if (current.help.buttonImage != nullptr)
            SetIconMaterial("_interaction_usebutton",
                current.help.buttonImage);
    } else {
        idHudValue values[10] = {
            idHudValue::Integer(hasReticleIcon ? 1 : 0),
            idHudValue::String(""),
            idHudValue::Float(current.reticle.useAmount),
            idHudValue::Integer(-1), idHudValue::Integer(-1),
            idHudValue::Integer(-1), idHudValue::Integer(-1),
            idHudValue::Integer(-1), idHudValue::Integer(-1),
            idHudValue::Boolean(current.interact.useCheckbox)
        };
        for (int icon = 0; icon < 3 && icon < current.interact.icons.Num();
                ++icon) {
            values[3 + icon * 2] =
                idHudValue::Integer(current.interact.icons[icon].usable);
            values[4 + icon * 2] =
                idHudValue::Integer(current.interact.icons[icon].itemCount);
        }
        g_playerHudServices->Invoke(hud, "UpdateInteraction", values, 10);
        static const char* const iconNames[3] = {
            "_interaction_icon0", "_interaction_icon1",
            "_interaction_icon2"
        };
        for (int icon = 0; icon < 3; ++icon) {
            SetIconMaterial(iconNames[icon],
                icon < current.interact.icons.Num()
                    ? current.interact.icons[icon].material : nullptr);
        }
        SetIconMaterial("_interaction_usebutton", nullptr);
    }

    InvokeHud(hud, "UpdateJobNotification", {
        idHudValue::Boolean(current.showJournalIcon)
    });
    if (current.minigame.action == 1) {
        g_playerHudServices->SetGlobalInteger(hud, "minigame_result", -1);
        InvokeHud(hud, "Minigame_Start", {
            idHudValue::Integer(current.minigame.type),
            idHudValue::Integer(current.minigame.level),
            idHudValue::Boolean(current.minigame.showHelp)
        });
    } else if (current.minigame.action == 2) {
        InvokeHud(hud, "Minigame_End", {});
    }
    minigameResult =
        g_playerHudServices->GetGlobalInteger(hud, "minigame_result");
    minigameRangeIndicator =
        g_playerHudServices->GetGlobalFloat(hud,
            "minigame_rangeindicator");
    minigameStage =
        g_playerHudServices->GetGlobalInteger(hud, "minigame_stage");

    if (!g_playerHudServices->IsMainMenuActive())
        g_playerHudServices->Render(hud, guiModel, currentTime, false);
}
