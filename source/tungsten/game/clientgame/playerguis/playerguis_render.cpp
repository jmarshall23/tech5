#include "playerguis_render.h"

#include <cstring>

namespace {
idPlayerGuisRenderServices* g_playerGuiServices = nullptr;
}

void Tungsten_SetPlayerGuisRenderServices(
        idPlayerGuisRenderServices* const services) {
    g_playerGuiServices = services;
}

// Retail symbol: ?Cleanup@idPlayerGuis_Render@@QAAXXZ
// EA: 0x82B62A90, RVA: 0x00B62A90
void idPlayerGuis_Render::Cleanup() {
    if (g_playerGuiServices == nullptr) return;
    for (idSWF* const gui : guis) {
        if (gui != nullptr) g_playerGuiServices->ClearEmitter(gui, true);
    }
}

// Retail symbol: ?NoteSwfForBuildGame@idPlayerGuis_Render@@SAXXZ
// EA: 0x82B62AE8, RVA: 0x00B62AE8
void idPlayerGuis_Render::NoteSwfForBuildGame() {
    if (g_playerGuiServices == nullptr) return;
    g_playerGuiServices->RegisterSWFResources("tunggameover");
    if (g_playerGuiServices->IsMultiplayer())
        g_playerGuiServices->RegisterSWFResources("online_textchat");
}

// Retail symbol: ?DeactivateGuis@idPlayerGuis_Render@@QAAXXZ
// EA: 0x82B62B40, RVA: 0x00B62B40
void idPlayerGuis_Render::DeactivateGuis() {
    if (g_playerGuiServices != nullptr && guis[GUI_GAMEOVER] != nullptr)
        g_playerGuiServices->Activate(guis[GUI_GAMEOVER], false);
}

// Retail symbol: ?HandleGuiEvent@idPlayerGuis_Render@@QAA_NPBUsysEvent_t@@@Z
// EA: 0x82B62BA0, RVA: 0x00B62BA0
bool idPlayerGuis_Render::HandleGuiEvent(const sysEvent_t* const event) {
    if (g_playerGuiServices == nullptr) return false;
    for (int index = GUI_NUM_GUIS - 1; index >= 0; --index) {
        if (guis[index] != nullptr &&
                g_playerGuiServices->HandleEvent(guis[index], event))
            return true;
    }
    return false;
}

// Retail symbol: ?IsPlayerControlInhibited@idPlayerGuis_Render@@QAA_NXZ
// EA: 0x82B62C00, RVA: 0x00B62C00
bool idPlayerGuis_Render::IsPlayerControlInhibited() {
    if (g_playerGuiServices == nullptr) return false;
    for (idSWF* const gui : guis) {
        if (gui != nullptr &&
                g_playerGuiServices->IsPlayerControlInhibited(gui))
            return true;
    }
    return false;
}

// Retail symbol: ?SetPlayerNum@idPlayerGuis_Render@@QAAXH@Z
// EA: 0x82B62C70, RVA: 0x00B62C70
void idPlayerGuis_Render::SetPlayerNum(const int player) {
    playerNum = player;
    if (g_playerGuiServices == nullptr) return;
    for (idSWF* const gui : guis) {
        if (gui != nullptr) g_playerGuiServices->SetListener(gui, player + 1);
    }
}

// Retail symbol: ?RenderGame@idPlayerGuis_Render@@QAAXPAVidRenderModelGui@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA: 0x82B62CB8, RVA: 0x00B62CB8
void idPlayerGuis_Render::RenderGame(idRenderModelGui* const guiModel,
        const int currentTime, const renderView_t*, const idRenderWorld*) {
    if (g_playerGuiServices == nullptr || guis[GUI_GAMEOVER] == nullptr)
        return;
    if (g_playerGuiServices->IsMultiplayer() ||
            !g_playerGuiServices->HasGameLocal() ||
            !g_playerGuiServices->IsMainMenuActive()) {
        g_playerGuiServices->Render(guis[GUI_GAMEOVER], guiModel,
            currentTime, false);
    }
}

// Retail symbol: ?HandleReliableGuiMsg@idPlayerGuis_Render@@QAAXHAAVidBitMsg@@@Z
// EA: 0x82B62D48, RVA: 0x00B62D48
void idPlayerGuis_Render::HandleReliableGuiMsg(const int type,
        idBitMsg& message) {
    if (type != 19) return;
    playerGuiInfo.objectiveResults.show = true;
    const int playerCount = message.ReadBits(8);
    for (int playerIndex = 0; playerIndex < playerCount; ++playerIndex) {
        int values[7];
        for (int field = 0; field < 7; ++field)
            values[field] = message.ReadBits(32);
        if (playerIndex < 2) {
            playerGuiInfo.objectiveResults.playerObjectives[playerIndex] = {
                values[0], values[1], values[2], values[3], values[4],
                values[5], values[6]
            };
        }
    }
    playerGuiInfo.objectiveResults.totalTime = message.ReadBits(32);
    playerGuiInfo.objectiveResults.collectibles = message.ReadBits(32);
    playerGuiInfo.objectiveResults.collectiblesMax = message.ReadBits(32);
    playerGuiInfo.objectiveResults.collectibleBonusScore =
        message.ReadBits(32);
    playerGuiInfo.objectiveResults.finalScore = message.ReadBits(32);
    playerGuiInfo.objectiveResults.rating = message.ReadBits(8);
}

// Retail symbol: ??1idPlayerGuis_Render@@QAA@XZ
// EA: 0x82B62E78, RVA: 0x00B62E78
idPlayerGuis_Render::~idPlayerGuis_Render() {
    if (g_playerGuiServices != nullptr) {
        for (idSWF*& gui : guis) {
            if (gui != nullptr) g_playerGuiServices->DestroySWF(gui);
            gui = nullptr;
        }
    }
}

// Retail symbol: ??0idPlayerGuis_Render@@QAA@XZ
// EA: 0x82B62F18, RVA: 0x00B62F18
idPlayerGuis_Render::idPlayerGuis_Render()
    : playerGuiInfo(), guis{nullptr, nullptr}, playerNum(0),
      textChatHistory() {
    std::memset(&playerGuiInfo, 0, sizeof(playerGuiInfo));
}

// Retail symbol: `idPlayerGuis_Render::Init'::`15'::idSWFScriptFunction_SendChatText::Call
// EA: 0x82B62FD0, RVA: 0x00B62FD0
bool idSWFScriptFunction_SendChatText::Call(const idStr* const text,
        const int* const mode, const int parameterCount) {
    if (parameterCount != 2 || text == nullptr || mode == nullptr) {
        if (g_playerGuiServices != nullptr)
            g_playerGuiServices->Warning(
                "Invalid parameters for sendChatText!");
        return false;
    }
    if (g_playerGuiServices != nullptr)
        g_playerGuiServices->SendChatText(text->c_str(), *mode);
    return true;
}

// Retail symbol: ?SetupBindings@idPlayerGuis_Render@@QAAXXZ
// EA: 0x82B630F0, RVA: 0x00B630F0
void idPlayerGuis_Render::SetupBindings() {
    if (g_playerGuiServices == nullptr) return;
    struct Binding { const char* name; int value; };
    static const Binding bindings[] = {
        {"UP", 200}, {"DOWN", 208}, {"LEFT", 203}, {"RIGHT", 205},
        {"ENTER", 28}, {"BACKSPACE", 14}, {"TAB", 15},
        {"JOY3", 258}, {"JOY10", 265},
        {"SWF_TEXT_RENDER_NORMAL", 0},
        {"SWF_TEXT_RENDER_RANDOM_APPEAR", 1},
        {"SWF_TEXT_RENDER_RANDOM_APPEAR_CAPS", 2},
        {"SWF_TEXT_RENDER_PARAGRAPH", 3},
        {"SWF_TEXT_RENDER_AUTOSCROLL", 4},
        {"MESSAGEMODE_ALL", 0}, {"MESSAGEMODE_TEAM", 1}
    };
    for (idSWF* const gui : guis) {
        if (gui == nullptr) continue;
        for (const Binding& binding : bindings)
            g_playerGuiServices->SetGlobalInteger(gui, binding.name,
                binding.value);
    }
}

// Retail symbol: ?Render_TextChat@idPlayerGuis_Render@@AAAXH@Z
// EA: 0x82B63818, RVA: 0x00B63818
void idPlayerGuis_Render::Render_TextChat(const int) {
    if (g_playerGuiServices == nullptr || guis[GUI_TEXT_CHAT] == nullptr)
        return;
    g_playerGuiServices->Activate(guis[GUI_TEXT_CHAT], true);
    g_playerGuiServices->SetGlobalString(guis[GUI_TEXT_CHAT],
        "textchathistory", textChatHistory.c_str());
}

// Retail symbol: ?Init@idPlayerGuis_Render@@QAAXPBVidStr@@@Z
// EA: 0x82B638E0, RVA: 0x00B638E0
void idPlayerGuis_Render::Init(const idStr*) {
    if (g_playerGuiServices == nullptr) return;
    if (!g_playerGuiServices->IsMultiplayer() ||
            g_playerGuiServices->IsCooperativeMatch()) {
        guis[GUI_GAMEOVER] =
            g_playerGuiServices->CreateSWF("tunggameover", true);
    } else {
        guis[GUI_GAMEOVER] = nullptr;
    }
    if (g_playerGuiServices->IsMultiplayer()) {
        guis[GUI_TEXT_CHAT] =
            g_playerGuiServices->CreateSWF("online_textchat", true);
    } else {
        guis[GUI_TEXT_CHAT] = nullptr;
    }
    if (guis[GUI_TEXT_CHAT] != nullptr)
        g_playerGuiServices->InstallSendChatFunction(
            guis[GUI_TEXT_CHAT], this);
    SetupBindings();
    DeactivateGuis();
    if (guis[GUI_TEXT_CHAT] != nullptr)
        g_playerGuiServices->Activate(guis[GUI_TEXT_CHAT], true);
}

// Retail symbol: ?Render@idPlayerGuis_Render@@QAAXPAVidRenderModelGui@@HPBUrenderView_t@@PBVidRenderWorld@@@Z
// EA: 0x82B63B60, RVA: 0x00B63B60
void idPlayerGuis_Render::Render(idRenderModelGui* const guiModel,
        const int currentTime, const renderView_t*, const idRenderWorld*) {
    Render_TextChat(currentTime);
    if (g_playerGuiServices != nullptr && guis[GUI_TEXT_CHAT] != nullptr)
        g_playerGuiServices->Render(guis[GUI_TEXT_CHAT], guiModel,
            currentTime, false);
}

// Retail symbol: ?Call@idSWFScriptFunction_CancelChatting@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA: 0x82B63BB0, RVA: 0x00B63BB0
void idSWFScriptFunction_CancelChatting::Call() {
    if (g_playerGuiServices != nullptr && gui != nullptr)
        g_playerGuiServices->Activate(gui, false);
}

// Retail symbol: ?DisplayTextChatEntry@idPlayerGuis_Render@@QAAXXZ
// EA: 0x82B63D00, RVA: 0x00B63D00
void idPlayerGuis_Render::DisplayTextChatEntry() {
    if (g_playerGuiServices == nullptr || guis[GUI_TEXT_CHAT] == nullptr)
        return;
    g_playerGuiServices->Invoke(guis[GUI_TEXT_CHAT], "ShowTextChatBox");
    g_playerGuiServices->InstallCancelChatFunction(guis[GUI_TEXT_CHAT]);
}

// Retail symbol: ?DisplayTeamTextChatEntry@idPlayerGuis_Render@@QAAXXZ
// EA: 0x82B63E88, RVA: 0x00B63E88
void idPlayerGuis_Render::DisplayTeamTextChatEntry() {
    if (g_playerGuiServices == nullptr || guis[GUI_TEXT_CHAT] == nullptr)
        return;
    g_playerGuiServices->Invoke(guis[GUI_TEXT_CHAT],
        "ShowTeamTextChatBox");
    g_playerGuiServices->InstallCancelChatFunction(guis[GUI_TEXT_CHAT]);
}

// Retail symbol: ?DisplayTextChatMessage@idPlayerGuis_Render@@QAAXABVidStr@@@Z
// EA: 0x82B64010, RVA: 0x00B64010
void idPlayerGuis_Render::DisplayTextChatMessage(const idStr& message) {
    if (g_playerGuiServices == nullptr || guis[GUI_TEXT_CHAT] == nullptr)
        return;
    textChatHistory.Append("\n");
    textChatHistory.Append(message);
    g_playerGuiServices->Activate(guis[GUI_TEXT_CHAT], true);
    g_playerGuiServices->InvokeWithString(guis[GUI_TEXT_CHAT],
        "TextChatUpdated", message.c_str());
}
