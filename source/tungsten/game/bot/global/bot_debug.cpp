#include "bot_debug.h"

#include <algorithm>
#include <cfloat>

namespace {
idBotDebugServices* g_debugServices = nullptr;
}

void Tungsten_SetBotDebugServices(idBotDebugServices* const services) {
    g_debugServices = services;
}

idGuiPage::idGuiPage(const char* const name)
    : isActive(false), eventQueue(0), renderX(0.0f), renderY(0.0f),
      pageName(name) {
}

idGuiPage::~idGuiPage() {
    eventQueue.Clear();
}

bool idGuiPage::HandleEvent(const sysEvent_t* const event) {
    if (event == nullptr) return false;
    if (InternalHandleEvent(event)) return true;
    eventQueue.Append(*event);
    return false;
}

void idGuiPage::Render(idEntity* const debugEntity,
        idDeviceContext& context) {
    InternalRender(debugEntity, context);
    eventQueue.Clear();
}

// Retail symbol: ?InternalRender@idBotWorldDebugGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA: 0x82B478B8, RVA: 0x00B478B8
void idBotWorldDebugGui::InternalRender(idEntity* const debugEntity,
        idDeviceContext& context) {
    if (debugEntity != nullptr && g_debugServices != nullptr) {
        g_debugServices->RenderBotPage(BOT_DEBUG_GUI_TYPE_WORLD,
            *debugEntity, context, 0, 1);
    }
}

// Retail symbol: ?InternalRender@idBotBehaviorTreeDebugGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA: 0x82B47960, RVA: 0x00B47960
void idBotBehaviorTreeDebugGui::InternalRender(
        idEntity* const debugEntity, idDeviceContext& context) {
    if (debugEntity != nullptr && g_debugServices != nullptr) {
        g_debugServices->RenderBotPage(BOT_DEBUG_GUI_TYPE_BEHAVIOR,
            *debugEntity, context, 0, 0);
    }
}

// Retail symbol: ?HandleEvent@idBotGUI@@QAA_NPBUsysEvent_t@@@Z
// EA: 0x82B47A00, RVA: 0x00B47A00
bool idBotGUI::HandleEvent(const sysEvent_t* const event) {
    if (g_debugServices == nullptr ||
            g_debugServices->GetBotGUIValue() == 0) {
        return false;
    }

    if (event != nullptr && event->evType == SE_KEY) {
        int page = -1;
        switch (event->evValue) {
        case 'R': page = 0; break;
        case 'O': page = 1; break;
        case 'P': page = 2; break;
        case 'Q': page = 3; break;
        case 'K': page = 4; break;
        case 'L': page = 5; break;
        case 'M': page = 6; break;
        case 'G': page = 7; break;
        case 'H': page = 8; break;
        case 'I': page = 9; break;
        default: break;
        }
        if (page >= 0) g_debugServices->SetBotGUIValue(page);
    }

    const int value = (std::max)(g_debugServices->GetBotGUIMinValue(),
        (std::min)(g_debugServices->GetBotGUIMaxValue(),
            g_debugServices->GetBotGUIValue()));
    g_debugServices->SetBotGUIValue(value);
    if (value > 0 && value < pages.Num() && pages[value] != nullptr) {
        return pages[value]->HandleEvent(event);
    }
    return false;
}

// Retail symbol: ?ShouldRender@idBotGUI@@AAA_NXZ
// EA: 0x82B47B80, RVA: 0x00B47B80
bool idBotGUI::ShouldRender() {
    if (g_debugServices != nullptr && initialized &&
            g_debugServices->GetBotGUIValue() != 0 &&
            g_debugServices->GetDebugPlayer() != nullptr &&
            !g_debugServices->IsClient() &&
            g_debugServices->GetNumConnectedPeers() == 0) {
        return true;
    }
    if (g_debugServices != nullptr) g_debugServices->SetBotGUIValue(0);
    return false;
}

// Retail symbol: ?RenderBaseGUI@idBotGUI@@AAAXAAVidDeviceContext@@@Z
// EA: 0x82B47C68, RVA: 0x00B47C68
void idBotGUI::RenderBaseGUI(idDeviceContext& context) {
    if (g_debugServices == nullptr) return;
    std::vector<idBotDebugPageLabel> labels;
    labels.reserve(static_cast<std::size_t>(pages.Num()));
    for (int index = 0; index < pages.Num(); ++index) {
        if (pages[index] != nullptr) {
            labels.push_back({ index, pages[index]->GetPageName() });
        }
    }
    g_debugServices->RenderPageMenu(labels, context, 1, 2);
}

// Retail symbol: ?InternalRender@idBotHudGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA: 0x82B47D68, RVA: 0x00B47D68
void idBotHudGui::InternalRender(idEntity* const debugEntity,
        idDeviceContext& context) {
    if (debugEntity != nullptr && g_debugServices != nullptr) {
        g_debugServices->RenderBotPage(BOT_DEBUG_GUI_TYPE_HUD,
            *debugEntity, context, 0, 0);
    }
}

// Retail symbol: ??0idBotHudGui@@QAA@XZ
// EA: 0x82B47F80, RVA: 0x00B47F80
idBotHudGui::idBotHudGui() : idGuiPage("Bot Info") {
}

// Retail symbol: ??0idBotWorldDebugGui@@QAA@XZ
// EA: 0x82B480B0, RVA: 0x00B480B0
idBotWorldDebugGui::idBotWorldDebugGui()
    : idGuiPage("Bot World State") {
}

// Retail symbol: ??0idBotBehaviorTreeDebugGui@@QAA@XZ
// EA: 0x82B481E0, RVA: 0x00B481E0
idBotBehaviorTreeDebugGui::idBotBehaviorTreeDebugGui()
    : idGuiPage("Bot Behavior Debug") {
}

// Retail symbol: ??0idBotGUI@@QAA@XZ
// EA: 0x82B48308, RVA: 0x00B48308
idBotGUI::idBotGUI()
    : initialized(false), firstDraw(true), oldGuiTextScale(0.0f),
      pages(0), guiModel(nullptr) {
    pages.Clear();
}

// Retail symbol: ??1idBotGUI@@QAA@XZ
// EA: 0x82B48388, RVA: 0x00B48388
idBotGUI::~idBotGUI() {
    if (guiModel != nullptr && g_debugServices != nullptr) {
        g_debugServices->MarkGuiModelForDeletion(*guiModel);
    }
    pages.Clear();
}

// Retail symbol: ?FindBotDebugEntity@idBotGUI@@AAAXXZ
// EA: 0x82B48418, RVA: 0x00B48418
void idBotGUI::FindBotDebugEntity() {
    if (g_debugServices == nullptr) return;
    idEntity* const debugPlayer = g_debugServices->GetDebugPlayer();
    if (debugPlayer == nullptr) return;

    std::vector<idEntity*> botEntities;
    g_debugServices->GetBotEntities(botEntities);
    if (botEntities.empty()) return;

    idEntity* closestBot = nullptr;
    float closestDistanceSqr = FLT_MAX;
    const idVec3 debugOrigin =
        g_debugServices->GetEntityOrigin(*debugPlayer);
    for (idEntity* const candidate : botEntities) {
        if (candidate == nullptr ||
                !g_debugServices->IsPlayer(*candidate) ||
                !g_debugServices->IsLobbyUserValid(*candidate)) {
            continue;
        }
        const idVec3 delta =
            g_debugServices->GetEntityOrigin(*candidate) - debugOrigin;
        const float distanceSqr = delta.LengthSqr();
        if (distanceSqr < closestDistanceSqr) {
            closestDistanceSqr = distanceSqr;
            closestBot = candidate;
        }
    }
    g_debugServices->SetBotDebugEntity(closestBot);
}

// Retail symbol: ?DrawGUI@idBotGUI@@QAAPAVidRenderModelGui@@PAVidEntity@@@Z
// EA: 0x82B485E8, RVA: 0x00B485E8
idRenderModelGui* idBotGUI::DrawGUI(idEntity* const entity) {
    if (g_debugServices == nullptr) return nullptr;
    if (g_debugServices->IsDeveloperGUIActive()) {
        firstDraw = true;
        return nullptr;
    }

    if (g_debugServices->GetBotGUIValue() != 0 && ShouldRender()) {
        if (entity != nullptr && g_debugServices->IsPlayer(*entity) &&
                g_debugServices->IsLobbyUserValid(*entity)) {
            g_debugServices->DrawDebugBounds(*entity);
            if (firstDraw) {
                firstDraw = false;
                oldGuiTextScale = g_debugServices->GetGuiTextScale();
                g_debugServices->SetGuiTextScale(0.35f);
            }
            if (guiModel == nullptr) return nullptr;
            idDeviceContext* const context =
                g_debugServices->BeginGuiFrame(*guiModel);
            if (context == nullptr) return nullptr;
            RenderBaseGUI(*context);
            const int page = g_debugServices->GetBotGUIValue();
            if (page >= 0 && page < pages.Num() && pages[page] != nullptr) {
                pages[page]->Render(entity, *context);
            }
            return guiModel;
        }
        if (entity != nullptr) g_debugServices->SetBotDebugEntity(nullptr);
        FindBotDebugEntity();
        return nullptr;
    }

    if (!firstDraw) {
        firstDraw = true;
        g_debugServices->SetGuiTextScale(oldGuiTextScale);
    }
    return nullptr;
}

// Retail symbol: ?Init@idBotGUI@@QAAXXZ
// EA: 0x82B48910, RVA: 0x00B48910
void idBotGUI::Init() {
    if (initialized) {
        if (g_debugServices != nullptr) {
            g_debugServices->Warning(
                "Trying to Init idBotGUI when its already Init!");
        }
        return;
    }
    initialized = true;
    pages.Append(nullptr);
    pages.Append(new idBotHudGui());
    pages.Append(new idBotWorldDebugGui());
    pages.Append(new idBotBehaviorTreeDebugGui());
    guiModel = g_debugServices != nullptr
        ? g_debugServices->CreateGuiModel() : nullptr;
}
