#pragma once

#include "idlib/containers/staticlist.h"

class idFile;
class idFile_SaveGame;
class idGame;
class mgHttpServer;
struct idGameSpawnInfo;

class idGameSystem {
public:
    virtual ~idGameSystem() = default;
    virtual void Init() = 0;
    virtual void Shutdown() = 0;
    virtual bool AllocGame(idGame**, const idGameSpawnInfo*, idFile*) = 0;
    virtual void FreeGame(idGame**) = 0;
    virtual void MinimalGameCleanup(idGame**) = 0;
};

class idGameSystemLocal : public idGameSystem {
public:
    idGameSystemLocal();
    ~idGameSystemLocal() override;
    void Init() override;
    void Shutdown() override;
    bool AllocGame(idGame**, const idGameSpawnInfo*, idFile*) override;
    void FreeGame(idGame** game) override;
    void MinimalGameCleanup(idGame**) override;
    idStaticList<idFile_SaveGame*, 2> retainedFiles;
    mgHttpServer* httpServer;
};

extern idGameSystemLocal gameSystemLocalObject;
extern idGameSystem* gameSystem;
