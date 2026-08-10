#pragma once

#include "../entities/entityptr.h"
#include "gamelib/animstack/animweb/animwebpath.h"
#include "../../../shared/idlib/math/vector.h"
#include "../../../shared/idlib/text/str.h"

class idDeclDamage;
class idEntity;

class idAIDeathVolume {
public:
    idAIDeathVolume();
    virtual ~idAIDeathVolume();

    void Spawn();
    void Event_Touch(idEntity* toucher, int clipModelId);
    void Event_StopKilling();
    virtual void OnActivate(idEntity* activator);

    void SetName(const char* value) { name = value; }
    const char* GetName() const { return name.c_str(); }

    idVec3 referenceDir;
    bool unidirectional;
    bool makeRagdollTouchTriggers;
    float killDuration;
    const idDeclDamage* damageDecl;
    idAnimWebPath animFacingRefFwd;
    idAnimWebPath animFacingRefLeft;
    idAnimWebPath animFacingRefRight;
    idAnimWebPath animFacingRefBack;
    idEntityPtr<idEntity> lastActivator;

private:
    idStr name;
};
