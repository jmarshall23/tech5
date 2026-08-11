#include "bot_commands.h"

#include "../../../shared/idlib/text/str.h"

#include <cstdlib>

namespace {
idBotCommandServices* g_commandServices = nullptr;

bool NameIsInUse(const std::vector<const char*>& names,
        const char* const candidate) {
    for (const char* const name : names) {
        if (idStr::Icmp(name, candidate) == 0) {
            return true;
        }
    }
    return false;
}
} // namespace

void Tungsten_SetBotCommandServices(
        idBotCommandServices* const services) {
    g_commandServices = services;
}

// Retail symbol: ?Cmd_RemoveBot_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82B40BF0, RVA: 0x00B40BF0
void Cmd_RemoveBot_f(const idCmdArgs& args) {
    if (g_commandServices == nullptr || g_commandServices->IsClient()) {
        return;
    }

    if (args.Argc() < 2) {
        for (int clientNumber = 0; clientNumber < 6; ++clientNumber) {
            if (g_commandServices->IsRemovableBot(clientNumber)) {
                g_commandServices->RemoveBot(clientNumber);
            }
        }
        return;
    }

    const int clientNumber = std::atoi(args.Argv(1));
    if (g_commandServices->IsRemovableBot(clientNumber)) {
        g_commandServices->RemoveBot(clientNumber);
    }
}

// Retail symbol: ?Cmd_AddBot_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82B40DD0, RVA: 0x00B40DD0
void Cmd_AddBot_f(const idCmdArgs&) {
    if (g_commandServices == nullptr || g_commandServices->IsClient()
            || !g_commandServices->IsInGame()) {
        return;
    }

    std::vector<const char*> currentNames;
    g_commandServices->GetLobbyUserNames(currentNames);
    std::vector<const idDeclBot*> availableDefinitions;
    g_commandServices->GetLoadedBotDefs(availableDefinitions);

    while (!availableDefinitions.empty()) {
        int index = g_commandServices->RandomIndex(
            static_cast<int>(availableDefinitions.size()));
        if (index < 0 || index >= static_cast<int>(availableDefinitions.size())) {
            index = 0;
        }
        const idDeclBot* const definition = availableDefinitions[index];
        const char* const name = definition != nullptr
            ? g_commandServices->GetBotName(*definition) : "";
        if (definition != nullptr && !NameIsInUse(currentNames, name)) {
            g_commandServices->AllocateBot(name, *definition);
            return;
        }
        availableDefinitions[index] = availableDefinitions.back();
        availableDefinitions.pop_back();
    }

    g_commandServices->Warning(
        "CMD: 'bot_add' - Can't Add Bot - No Valid Bot Defs Available!");
}

// Retail symbol: ?InitBotCommands@@YAXXZ
// EA: 0x82B411A8, RVA: 0x00B411A8
void InitBotCommands() {
    if (g_commandServices == nullptr) {
        return;
    }
    g_commandServices->AddCommand(
        "bot_add", Cmd_AddBot_f, "Spawns a bot");
    g_commandServices->AddCommand("bot_remove", Cmd_RemoveBot_f,
        "If clientNum passed, removes bot with that clientNum, else removes all bots");
}
