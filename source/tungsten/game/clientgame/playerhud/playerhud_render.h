#pragma once

#include "../../../../shared/idlib/containers/list.h"

class idMaterial;
class idRenderModelGui;
class idRenderWorld;
class idSWF;
class idStr;
struct renderView_t;
struct sysEvent_t;

struct idHudValue {
    enum valueType_t { VALUE_INTEGER, VALUE_FLOAT, VALUE_BOOLEAN, VALUE_STRING };

    static idHudValue Integer(int value);
    static idHudValue Float(float value);
    static idHudValue Boolean(bool value);
    static idHudValue String(const char* value);

    valueType_t type;
    int integer;
    float number;
    const char* string;
};

struct idHudInfo {
    struct healthIndicator_t { int health{0}; int armor{0}; } healthIndicator;
    struct damageLocator_t {
        float directionX{0.0f};
        float directionY{0.0f};
        float intensity{0.0f};
    } damageLocator;
    struct weaponAmmoStatus_t {
        bool show{false};
        bool staticCounter{false};
        int nextAnimState{0};
        int ammoClipCount{0};
        int ammoTotalCount{0};
        int burstMode{0};
        bool dwAvailable{false};
        bool renderReceipt{false};
    } weaponAmmoStatus[4];
    struct combiner_t {
        bool hovered{false};
        int itemCount{0};
        int itemValues[5]{};
        const idMaterial* itemMaterials[5]{};
    };
    struct reticle_t {
        bool show{false};
        int pulsate{0};
        int iconIndex{-1};
        float useAmount{0.0f};
    } reticle;
    struct airSupply_t { bool show{false}; float percent{0.0f}; } airSupply;
    struct boss_t {
        int numBars{0};
        int visibleBars{0};
        float amount{0.0f};
    } boss;
    struct laserCutterStatus_t {
        bool show{false};
        float charge{0.0f};
        bool canShoot{false};
        int nextAnimState{0};
        bool cuttingMode{false};
        bool shootingFullAuto{false};
    } laserCutterStatus;
    struct laserCutterFuncLensStatus_t {
        bool showPrim{false};
        bool showSec{false};
        bool showStatic{false};
        int nextAnimState{0};
        int iconPrim{0};
        int iconSec{0};
        int iconStatic{0};
    } laserCutterFuncLensStatus;
    struct help_t {
        bool show{false};
        const idMaterial* icon{nullptr};
        const idMaterial* buttonImage{nullptr};
    } help;
    struct interactIcon_t {
        int usable{0};
        int itemCount{-1};
        const idMaterial* material{nullptr};
    };
    struct interact_t {
        idList<interactIcon_t, 5> icons;
        bool useCheckbox{false};
    } interact;
    struct minigame_t {
        int action{0};
        int type{0};
        int level{0};
        bool showHelp{false};
    } minigame;

    bool showBottomBar{false};
    bool showJournalIcon{false};
    idList<combiner_t, 5> combiners;
};

class idPlayerHudRenderServices {
public:
    virtual ~idPlayerHudRenderServices() = default;
    virtual void RegisterSWFResources(const char*) {}
    virtual idSWF* CreateSWF(const char*, bool) { return nullptr; }
    virtual void DestroySWF(idSWF*) {}
    virtual bool IsMainMenuActive() const { return false; }
    virtual bool ShowHud() const { return true; }
    virtual bool SaveGameHasWork() const { return false; }
    virtual bool IsGamePaused() const { return false; }
    virtual bool IsPlayerControlInhibited(idSWF*) const { return false; }
    virtual void ClearEmitter(idSWF*, bool) {}
    virtual bool HandleEvent(idSWF*, const sysEvent_t*) { return false; }
    virtual void SetListener(idSWF*, int) {}
    virtual void Activate(idSWF*, bool) {}
    virtual void Invoke(idSWF*, const char*, const idHudValue*, int) {}
    virtual void SetGlobalInteger(idSWF*, const char*, int) {}
    virtual int GetGlobalInteger(idSWF*, const char*) const { return 0; }
    virtual float GetGlobalFloat(idSWF*, const char*) const { return 0.0f; }
    virtual void SetIconMaterial(idSWF*, const char*, const idMaterial*) {}
    virtual void SetCombinerItemMaterial(idSWF*, int, int,
        const idMaterial*) {}
    virtual void Render(idSWF*, idRenderModelGui*, int, bool) {}
};

void Tungsten_SetPlayerHudRenderServices(idPlayerHudRenderServices* services);

class idPlayerHud_Render {
public:
    idPlayerHud_Render();
    virtual ~idPlayerHud_Render();

    static void NoteSwfForBuildGame();
    bool IsPlayerControlInhibited();
    void Cleanup();
    bool HandleGuiEvent(const sysEvent_t* event);
    void SetPlayerNum(int player);
    void Init(const idStr* mapName);
    void Render(idRenderModelGui* guiModel, idHudInfo& current,
        int currentTime, const renderView_t* renderView,
        const idRenderWorld* renderWorld);

    idSWF* GetHud() const { return hud; }
    int GetPlayerNum() const { return playerNum; }
    int GetMinigameResult() const { return minigameResult; }
    int GetMinigameStage() const { return minigameStage; }
    float GetMinigameRangeIndicator() const {
        return minigameRangeIndicator;
    }

private:
    void SetIconMaterial(const char* name, const idMaterial* material);

    idSWF* hud;
    bool showScoreboard;
    int playerNum;
    int minigameResult;
    int minigameStage;
    float minigameRangeIndicator;
};
