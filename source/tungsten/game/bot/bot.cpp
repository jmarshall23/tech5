#include "bot.h"

#include "behaviortree/bot_bt_root.h"

#include <cstring>

namespace {
idBotServices* g_services = nullptr;

short AngleToShort(const float angle) {
    return static_cast<short>(static_cast<int>(angle * 182.04445f));
}
} // namespace

void Tungsten_SetBotServices(idBotServices* const services) {
    g_services = services;
}

// Retail symbol: ?OnDeath@idBot@@QAAXPBVidEntity@@@Z
// EA: 0x82B3DFD0, RVA: 0x00B3DFD0
void idBot::OnDeath(const idEntity*) {
    if (g_services != nullptr) {
        g_services->ResetGoal(*this);
        g_services->ClearWorldVolatileData(*this);
    }
}

// Retail symbol: ?SetupUcmdsForNewFrame@idBot@@IAAXXZ
// EA: 0x82B3E008, RVA: 0x00B3E008
void idBot::SetupUcmdsForNewFrame() {
    const int nextFrame = usercmd.clientGameFrame + 1;
    std::memset(&usercmd, 0, sizeof(usercmd));
    usercmd.clientGameFrame = nextFrame;
    usercmd.serverGameTime = g_services != nullptr
        ? g_services->GetServerGameTime() : 0;
    usercmd.commandFlags |= 0x40U;
}

// Retail symbol: ?OnTakeDamage@idBot@@QAAXPBVidEntity@@@Z
// EA: 0x82B3E070, RVA: 0x00B3E070
void idBot::OnTakeDamage(const idEntity* const attacker) {
    if (attacker != nullptr && g_services != nullptr) {
        g_services->RecordDamage(
            *this, attacker, g_services->GetScaledGameTime());
    }
}

// Retail symbol: ?HandleViewCmds@idBot@@IAAXXZ
// EA: 0x82B3E148, RVA: 0x00B3E148
void idBot::HandleViewCmds() {
    if (g_services == nullptr) {
        return;
    }
    const idAngles desired = g_services->GetDesiredViewAngles(*this);
    const idAngles view = g_services->GetOwnerViewAngles(*this);
    usercmd.angles[0] = AngleToShort(desired.pitch - view.pitch);
    usercmd.angles[1] = AngleToShort(desired.yaw - view.yaw);
    usercmd.angles[2] = 0;
}

// Retail symbol: ?InitBehaviorTree@idBot@@IAAXXZ
// EA: 0x82B3E208, RVA: 0x00B3E208
void idBot::InitBehaviorTree() {
    behaviorTree = new idBotBehaviorTree();
    behaviorTree->RootInit(this, g_services != nullptr
        ? g_services->GetScaledGameTime() : 0);
}

// Retail symbol: ?InitWeaponState@idBot@@IAAXXZ
// EA: 0x82B3E2D8, RVA: 0x00B3E2D8
void idBot::InitWeaponState() {
    weaponState = g_services != nullptr
        ? g_services->CreateWeaponState(*this) : nullptr;
}

// Retail symbol: ?InitWorldState@idBot@@IAAXXZ
// EA: 0x82B3E388, RVA: 0x00B3E388
void idBot::InitWorldState() {
    worldState = g_services != nullptr
        ? g_services->CreateWorldState(*this) : nullptr;
}

// Retail symbol: ?InitMoveState@idBot@@IAAXXZ
// EA: 0x82B3E438, RVA: 0x00B3E438
void idBot::InitMoveState() {
    moveState = g_services != nullptr
        ? g_services->CreateMoveState(*this) : nullptr;
}

// Retail symbol: ?InitAimState@idBot@@IAAXXZ
// EA: 0x82B3E4E8, RVA: 0x00B3E4E8
void idBot::InitAimState() {
    aimState = g_services != nullptr
        ? g_services->CreateAimState(*this) : nullptr;
}

// Retail symbol: ?ProjectTopDown@idBot@@QBAXAAVidVec3@@@Z
// EA: 0x82B3E590, RVA: 0x00B3E590
void idBot::ProjectTopDown(idVec3& point) const {
    if (g_services != nullptr) {
        g_services->ProjectTopDown(*this, point);
    }
}

// Retail symbol: ??0idBot@@QAA@PAVidPlayer@@PBVidDeclBot@@@Z
// EA: 0x82B3E7B8, RVA: 0x00B3E7B8
idBot::idBot(idPlayer* const newOwner, const idDeclBot* const botDef)
    : isControllingAFKPlayer(false), debugName(nullptr),
      behaviorTree(nullptr), aimState(nullptr), worldState(nullptr),
      moveState(nullptr), weaponState(nullptr), behaviorDef(botDef),
      owner(newOwner), goalTask(), usercmd() {
    std::memset(&usercmd, 0, sizeof(usercmd));
    if (g_services != nullptr && !g_services->BotSystemsInitialized()) {
        g_services->ReportBotSystemsNotInitialized();
    }
    SetupUcmdsForNewFrame();
    InitBehaviorTree();
    InitWorldState();
    InitMoveState();
    InitAimState();
    InitWeaponState();
    isControllingAFKPlayer = botDef == nullptr;
    debugName = g_services != nullptr ? g_services->GetDebugName(*this) : nullptr;
}

// Retail compiler cleanup label retained through ordinary member lifetime.
// EA: 0x82B3E96C, RVA: 0x00B3E96C
static void Tungsten_BotConstructorCleanupLabel() {
}

// Retail symbol: ??1idBot@@UAA@XZ
// EA: 0x82B3E9A0, RVA: 0x00B3E9A0
idBot::~idBot() {
    delete behaviorTree;
    behaviorTree = nullptr;
    if (g_services != nullptr) {
        g_services->DestroyAimState(aimState);
        g_services->DestroyWorldState(worldState);
        g_services->DestroyMoveState(moveState);
        g_services->DestroyWeaponState(weaponState);
    }
    aimState = nullptr;
    worldState = nullptr;
    moveState = nullptr;
    weaponState = nullptr;
    behaviorDef = nullptr;
    owner = nullptr;
}

// Retail symbol: ?HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED@idBot@@QAAXXZ
// EA: 0x82B3EAE8, RVA: 0x00B3EAE8
void idBot::HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED() {
    if (g_services != nullptr && g_services->WeaponsAllowed()
            && !g_services->IsOwnerDead(*this)
            && g_services->HasValidGoalEnemy(*this)
            && (g_services->GetGoalEnemyTargetFlags(*this) & 8U) != 0U
            && g_services->GetGoalEnemyDot(*this) > 0.0f
            && g_services->RandomPercent() < 80U
            && g_services->GetGoalEnemyHealth(*this) > 0.0f) {
        usercmd.buttons = 1U;
    }
}

// Retail symbol: ?RunDebugChecks@idBot@@IAAXXZ
// EA: 0x82B3EC50, RVA: 0x00B3EC50
void idBot::RunDebugChecks() {
    if (g_services != nullptr) {
        g_services->RunDebugChecks(*this);
    }
}

// Retail symbol: ?UpdateBotDebugHud@idBot@@IBAXAAVidGuiListBox@@@Z
// EA: 0x82B3F1D0, RVA: 0x00B3F1D0
void idBot::UpdateBotDebugHud(idGuiListBox& infoList) const {
    if (g_services != nullptr) {
        g_services->UpdateBotDebugHud(*this, infoList);
    }
}

// Retail symbol: ?UpdateBotGUI@idBot@@QBAXAAVidGuiListBox@@W4botDebugGuiType_t@@@Z
// EA: 0x82B3F6F8, RVA: 0x00B3F6F8
void idBot::UpdateBotGUI(idGuiListBox& infoList,
        const botDebugGuiType_t debugType) const {
    if (debugType == BOT_DEBUG_GUI_HUD) {
        UpdateBotDebugHud(infoList);
    } else if (debugType == BOT_DEBUG_GUI_WORLD) {
        if (g_services != nullptr) {
            g_services->RenderWorldInfo(*this, infoList);
        }
    } else if (debugType == BOT_DEBUG_GUI_BEHAVIOR_TREE
            && behaviorTree != nullptr) {
        behaviorTree->DebugRenderGui(this, &infoList, 0);
    }
}

// Retail symbol: ?UpdateUcmd@idBot@@IAAXXZ
// EA: 0x82B3F748, RVA: 0x00B3F748
void idBot::UpdateUcmd() {
    if (g_services != nullptr && !g_services->IsOwnerDead(*this)) {
        HandleViewCmds();
        g_services->UpdateMoveCommands(*this, usercmd);
    }
}

// Retail symbol: ?UpdateBehaviorTree@idBot@@IAAXXZ
// EA: 0x82B3F828, RVA: 0x00B3F828
void idBot::UpdateBehaviorTree() {
    if (behaviorTree != nullptr) {
        behaviorTree->RootThink(this, g_services != nullptr
            ? g_services->GetScaledGameTime() : 0);
    }
}

// Retail symbol: ?UpdateWorldState@idBot@@IAAXXZ
// EA: 0x82B3F8F8, RVA: 0x00B3F8F8
void idBot::UpdateWorldState() {
    if (g_services != nullptr && !g_services->IsOwnerDead(*this)) {
        g_services->UpdateWorldState(*this);
        goalTask.goalEnemyTargetRecordIndex =
            g_services->HasValidGoalEnemy(*this)
            ? g_services->GetGoalEnemyRecordIndex(*this) : -1;
    }
}

// Retail symbol: ?UpdateAimState@idBot@@IAAXXZ
// EA: 0x82B3FA70, RVA: 0x00B3FA70
void idBot::UpdateAimState() {
    if (g_services != nullptr && !g_services->IsOwnerDead(*this)) {
        g_services->UpdateAimState(*this);
    }
}

// Retail symbol: ?UpdateWeaponState@idBot@@IAAXXZ
// EA: 0x82B3FB40, RVA: 0x00B3FB40
void idBot::UpdateWeaponState() {
    if (g_services != nullptr && !g_services->IsOwnerDead(*this)) {
        g_services->UpdateWeaponState(*this);
        HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED();
    }
}

// Retail symbol: ?UpdateMoveState@idBot@@IAAXXZ
// EA: 0x82B3FC20, RVA: 0x00B3FC20
void idBot::UpdateMoveState() {
    if (g_services != nullptr && !g_services->IsOwnerDead(*this)) {
        g_services->UpdateMoveState(*this);
    }
}

// Retail symbol: ?Think@idBot@@QAAXXZ
// EA: 0x82B3FCE8, RVA: 0x00B3FCE8
void idBot::Think() {
    SetupUcmdsForNewFrame();
    RunDebugChecks();
    if (g_services == nullptr) {
        return;
    }
    if (!g_services->IsBotThinkingPaused()) {
        UpdateWorldState();
        UpdateBehaviorTree();
        UpdateMoveState();
        UpdateWeaponState();
        UpdateAimState();
        UpdateUcmd();
        if (!g_services->IsOwnerDead(*this)) {
            g_services->PostUpdateAimState(*this);
        }
    }
    g_services->SubmitUserCommand(*this, usercmd);
}
