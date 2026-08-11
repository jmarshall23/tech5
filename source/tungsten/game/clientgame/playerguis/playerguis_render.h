#pragma once

#include "../../../../shared/idlib/networking/bitmsg.h"
#include "../../../../shared/idlib/text/str.h"

class idRenderModelGui;
class idRenderWorld;
class idSWF;
struct renderView_t;
struct sysEvent_t;

enum messageMode_t : int;

class idPlayerGuis_Render;

class idPlayerGuisRenderServices {
public:
    virtual ~idPlayerGuisRenderServices() = default;

    virtual bool IsMultiplayer() const { return false; }
    virtual bool IsCooperativeMatch() const { return false; }
    virtual bool HasGameLocal() const { return false; }
    virtual bool IsMainMenuActive() const { return false; }
    virtual void RegisterSWFResources(const char*) {}
    virtual idSWF* CreateSWF(const char*, bool) { return nullptr; }
    virtual void DestroySWF(idSWF*) {}
    virtual void ClearEmitter(idSWF*, bool) {}
    virtual void Activate(idSWF*, bool) {}
    virtual bool HandleEvent(idSWF*, const sysEvent_t*) { return false; }
    virtual bool IsPlayerControlInhibited(idSWF*) const { return false; }
    virtual void SetListener(idSWF*, int) {}
    virtual void Render(idSWF*, idRenderModelGui*, int, bool) {}
    virtual void SetGlobalInteger(idSWF*, const char*, int) {}
    virtual void SetGlobalString(idSWF*, const char*, const char*) {}
    virtual void InstallSendChatFunction(idSWF*, idPlayerGuis_Render*) {}
    virtual void InstallCancelChatFunction(idSWF*) {}
    virtual void Invoke(idSWF*, const char*) {}
    virtual void InvokeWithString(idSWF*, const char*, const char*) {}
    virtual void SendChatText(const char*, int) {}
    virtual void Warning(const char*) const {}
};

void Tungsten_SetPlayerGuisRenderServices(
    idPlayerGuisRenderServices* services);

class idPlayerGuis_Render {
public:
    enum playerGuis_t : int {
        GUI_TEXT_CHAT = 0,
        GUI_GAMEOVER = 1,
        GUI_NUM_GUIS = 2
    };

    struct playerGuisInfo_t {
        struct objectiveResults_t {
            struct playerResults_t {
                int score;
                int kills;
                int multiKills;
                int headshotKills;
                int assists;
                int defends;
                int revives;
            };

            bool show;
            int earnedCash;
            int killCount;
            int killBonus;
            int itemCount;
            int itemBonus;
            int collectNum;
            int collectMax;
            int time;
            int parTime;
            int bonusCash;
            int totalCash;
            playerResults_t playerObjectives[2];
            int totalTime;
            int collectibles;
            int collectiblesMax;
            int collectibleBonusScore;
            int finalScore;
            int rating;
        } objectiveResults;
    } playerGuiInfo;

    idPlayerGuis_Render();
    ~idPlayerGuis_Render();

    void Cleanup();
    static void NoteSwfForBuildGame();
    void DeactivateGuis();
    bool HandleGuiEvent(const sysEvent_t* event);
    bool IsPlayerControlInhibited();
    void SetPlayerNum(int player);
    void RenderGame(idRenderModelGui* guiModel, int currentTime,
        const renderView_t* renderView, const idRenderWorld* renderWorld);
    void HandleReliableGuiMsg(int type, idBitMsg& message);
    void SetupBindings();
    void Init(const idStr* mapName);
    void Render(idRenderModelGui* guiModel, int currentTime,
        const renderView_t* renderView, const idRenderWorld* renderWorld);
    void DisplayTextChatEntry();
    void DisplayTeamTextChatEntry();
    void DisplayTextChatMessage(const idStr& message);

    idSWF* GetGui(playerGuis_t gui) const { return guis[gui]; }
    int GetPlayerNum() const { return playerNum; }
    const idStr& GetTextChatHistory() const { return textChatHistory; }
    const playerGuisInfo_t::objectiveResults_t& GetObjectiveResults() const {
        return playerGuiInfo.objectiveResults;
    }

private:
    void Render_TextChat(int currentTime);

    idSWF* guis[GUI_NUM_GUIS];
    int playerNum;
    idStr textChatHistory;
};

class idSWFScriptFunction_SendChatText {
public:
    explicit idSWFScriptFunction_SendChatText(idPlayerGuis_Render* owner_)
        : owner(owner_) {}
    bool Call(const idStr* text, const int* mode, int parameterCount);

    idPlayerGuis_Render* owner;
};

class idSWFScriptFunction_CancelChatting {
public:
    explicit idSWFScriptFunction_CancelChatting(idSWF* gui_) : gui(gui_) {}
    void Call();

    idSWF* gui;
};
