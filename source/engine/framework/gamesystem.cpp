#include "framework/gamesystem.h"

#include "framework/framework_hooks.h"
#include "idlib/filesystem/file_savegame.h"

idGameSystemLocal gameSystemLocalObject;
idGameSystem* gameSystem = &gameSystemLocalObject;

idGameSystemLocal::idGameSystemLocal() : httpServer(nullptr) {
}

idGameSystemLocal::~idGameSystemLocal() {
    Shutdown();
}

void idGameSystemLocal::Init() {
    httpServer = nullptr;
    if (frameworkHooks.initGameSystem != nullptr) {
        frameworkHooks.initGameSystem();
    }
}

void idGameSystemLocal::Shutdown() {
    if (frameworkHooks.shutdownGameSystem != nullptr) {
        frameworkHooks.shutdownGameSystem();
    }
    for (int index = 0; index < retainedFiles.Num(); ++index) {
        delete retainedFiles[index];
    }
    retainedFiles.Clear();
    httpServer = nullptr;
}

bool idGameSystemLocal::AllocGame(idGame** const game,
        const idGameSpawnInfo* const spawnInfo, idFile* const saveFile) {
    if (game == nullptr) return false;
    *game = nullptr;
    return frameworkHooks.allocGame != nullptr
        && frameworkHooks.allocGame(game, spawnInfo, saveFile);
}

void idGameSystemLocal::FreeGame(idGame** const game) {
    if (game == nullptr || *game == nullptr) return;
    if (frameworkHooks.freeGame != nullptr) {
        frameworkHooks.freeGame(game);
    }
    *game = nullptr;
}

void idGameSystemLocal::MinimalGameCleanup(idGame** const game) {
    if (game == nullptr || *game == nullptr) return;
    if (frameworkHooks.minimalGameCleanup != nullptr) {
        frameworkHooks.minimalGameCleanup(game);
    }
    *game = nullptr;
}
