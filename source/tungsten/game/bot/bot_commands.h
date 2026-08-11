#pragma once

#include "../../../shared/idlib/text/cmdargs.h"

#include <vector>

class idDeclBot;

using botCommandFunction_t = void (*)(const idCmdArgs& args);

class idBotCommandServices {
public:
    virtual ~idBotCommandServices() = default;

    virtual bool IsClient() const = 0;
    virtual bool IsInGame() const = 0;
    virtual bool IsRemovableBot(int clientNumber) const = 0;
    virtual void RemoveBot(int clientNumber) = 0;
    virtual void GetLobbyUserNames(
        std::vector<const char*>& names) const = 0;
    virtual void GetLoadedBotDefs(
        std::vector<const idDeclBot*>& definitions) const = 0;
    virtual const char* GetBotName(const idDeclBot& definition) const = 0;
    virtual int RandomIndex(int count) = 0;
    virtual void AllocateBot(const char* name,
        const idDeclBot& definition) = 0;
    virtual void Warning(const char* message) = 0;
    virtual void AddCommand(const char* name, botCommandFunction_t function,
        const char* description) = 0;
};

void Tungsten_SetBotCommandServices(idBotCommandServices* services);
void Cmd_RemoveBot_f(const idCmdArgs& args);
void Cmd_AddBot_f(const idCmdArgs& args);
void InitBotCommands();
