#pragma once

#include "../../../../engine/framework/sysevent.h"
#include "../../../../shared/idlib/containers/list.h"
#include "../../../../shared/idlib/math/vector.h"
#include "../../../../shared/idlib/text/str.h"

#include <vector>

class idDeviceContext;
class idEntity;
class idRenderModelGui;

enum botDebugGuiType_t : int {
    BOT_DEBUG_GUI_TYPE_HUD = 0,
    BOT_DEBUG_GUI_TYPE_WORLD = 1,
    BOT_DEBUG_GUI_TYPE_BEHAVIOR = 2,
    BOT_DEBUG_GUI_TYPE_MAX = 3,

    // Names used by idBot's recovered public API.
    BOT_DEBUG_GUI_HUD = BOT_DEBUG_GUI_TYPE_HUD,
    BOT_DEBUG_GUI_WORLD = BOT_DEBUG_GUI_TYPE_WORLD,
    BOT_DEBUG_GUI_BEHAVIOR_TREE = BOT_DEBUG_GUI_TYPE_BEHAVIOR
};

struct idBotDebugPageLabel {
    int keyNumber;
    const char* pageName;
};

class idBotDebugServices {
public:
    virtual ~idBotDebugServices() = default;

    virtual int GetBotGUIValue() const = 0;
    virtual int GetBotGUIMinValue() const = 0;
    virtual int GetBotGUIMaxValue() const = 0;
    virtual void SetBotGUIValue(int value) = 0;
    virtual bool IsDeveloperGUIActive() const = 0;
    virtual bool IsClient() const = 0;
    virtual int GetNumConnectedPeers() const = 0;

    virtual idEntity* GetDebugPlayer() const = 0;
    virtual void GetBotEntities(std::vector<idEntity*>& entities) const = 0;
    virtual bool IsPlayer(const idEntity& entity) const = 0;
    virtual bool IsLobbyUserValid(const idEntity& entity) const = 0;
    virtual idVec3 GetEntityOrigin(const idEntity& entity) const = 0;
    virtual void SetBotDebugEntity(idEntity* entity) = 0;

    virtual void RenderBotPage(botDebugGuiType_t debugType,
        idEntity& debugEntity, idDeviceContext& context,
        int horizontalAlignment, int verticalAlignment) = 0;
    virtual void RenderPageMenu(
        const std::vector<idBotDebugPageLabel>& labels,
        idDeviceContext& context, int horizontalAlignment,
        int verticalAlignment) = 0;

    virtual idRenderModelGui* CreateGuiModel() = 0;
    virtual void MarkGuiModelForDeletion(idRenderModelGui& model) = 0;
    virtual idDeviceContext* BeginGuiFrame(idRenderModelGui& model) = 0;
    virtual void DrawDebugBounds(const idEntity& entity) = 0;
    virtual float GetGuiTextScale() const = 0;
    virtual void SetGuiTextScale(float scale) = 0;
    virtual void Warning(const char* message) = 0;
};

void Tungsten_SetBotDebugServices(idBotDebugServices* services);

class idGuiPage {
public:
    explicit idGuiPage(const char* name);
    virtual ~idGuiPage();

    bool HandleEvent(const sysEvent_t* event);
    void Render(idEntity* debugEntity, idDeviceContext& context);

    const char* GetPageName() const { return pageName.c_str(); }
    int GetQueuedEventCount() const { return eventQueue.Num(); }

protected:
    virtual bool InternalHandleEvent(const sysEvent_t*) { return false; }
    virtual void InternalRender(idEntity* debugEntity,
        idDeviceContext& context) = 0;

    bool isActive;
    idList<sysEvent_t, 5> eventQueue;
    float renderX;
    float renderY;
    idStr pageName;
};

class idBotHudGui final : public idGuiPage {
public:
    idBotHudGui();

private:
    void InternalRender(idEntity* debugEntity,
        idDeviceContext& context) override;
};

class idBotWorldDebugGui final : public idGuiPage {
public:
    idBotWorldDebugGui();

private:
    void InternalRender(idEntity* debugEntity,
        idDeviceContext& context) override;
};

class idBotBehaviorTreeDebugGui final : public idGuiPage {
public:
    idBotBehaviorTreeDebugGui();

private:
    void InternalRender(idEntity* debugEntity,
        idDeviceContext& context) override;
};

class idBotGUI {
public:
    idBotGUI();
    ~idBotGUI();

    bool HandleEvent(const sysEvent_t* event);
    idRenderModelGui* DrawGUI(idEntity* entity);
    void Init();

    bool IsInitialized() const { return initialized; }
    bool IsFirstDraw() const { return firstDraw; }
    int GetPageCount() const { return pages.Num(); }
    const idGuiPage* GetPage(int index) const {
        return index >= 0 && index < pages.Num() ? pages[index] : nullptr;
    }
    idRenderModelGui* GetGuiModel() const { return guiModel; }

private:
    bool ShouldRender();
    void RenderBaseGUI(idDeviceContext& context);
    void FindBotDebugEntity();

    bool initialized;
    bool firstDraw;
    float oldGuiTextScale;
    idList<idGuiPage*, 5> pages;
    idRenderModelGui* guiModel;
};
