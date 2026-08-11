#pragma once

#include "../../../shared/idlib/math/vector.h"

class idAAS2;
class idBot;
class idEntity;

class idBotUtilsServices {
public:
    virtual ~idBotUtilsServices() = default;
    virtual const idAAS2* GetBotAAS(const idBot& bot) const = 0;
    virtual int GetBotAreaNum(const idBot& bot,
        const idAAS2& aas) const = 0;
    virtual idVec3 GetBotOrigin(const idBot& bot) const = 0;
    virtual idVec3 GetEntityOrigin(const idEntity& entity) const = 0;
    virtual idVec3 GetEntityForward(const idEntity& entity) const = 0;
    virtual float TraceAvoidFloor(const idBot& bot, const idAAS2& aas,
        int startAreaNum, const idVec3& start,
        const idVec3& end) const = 0;
};

void Tungsten_SetBotUtilsServices(idBotUtilsServices* services);

class idBotUtils {
public:
    static bool FindAvoidEntityPoint(const idBot* bot,
        const idEntity* entity, float moveDist, idVec3& point,
        const idVec3* anchorPoint, float anchorRadius);
};
