#pragma once

#include "idlib/color.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

class idEntity;
class idGame;
class idRenderModel;

class idEntityInterface {
public:
    virtual ~idEntityInterface() = default;
    virtual bool IsValid() = 0;
    virtual idGame* Game() = 0;
    virtual void GetWorldOrigin(idVec3*) = 0;
    virtual void SetWorldOrigin(const idVec3*) = 0;
    virtual void TranslateWorld(const idVec3*) = 0;
    virtual void GetWorldAxis(idMat3*) = 0;
    virtual void SetWorldAxis(const idMat3*) = 0;
    virtual void UpdateVisuals() = 0;
    virtual void SetModel(idRenderModel*) = 0;
    virtual void SetModel(const char*) = 0;
    virtual void SetColor(const idColor*) = 0;
    virtual idEntity* GetEntity() = 0;
    virtual const char* GetEntityName() = 0;
    virtual void DeleteEntity() = 0;
    virtual void AddReference() = 0;
    virtual void RemoveReference() = 0;
    virtual int GetReferenceCount() = 0;
};
