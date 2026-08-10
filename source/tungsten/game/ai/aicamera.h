#pragma once

#include "../../../engine/framework/usercmdgen.h"
#include "../../../shared/idlib/math/vector.h"

class idAnimatedEntity;
class idPlayer;

// Entity, collision, and view ownership remains in the corresponding game
// runtime units. The camera controller keeps the retail camera algorithm.
bool Tungsten_GetAICameraFocus(
    const idAnimatedEntity* target, idVec3& focus);
idVec3 Tungsten_TraceAICamera(
    const idAnimatedEntity* target, const idVec3& start, const idVec3& end);
void Tungsten_PrepareAICameraActionScript(
    idAnimatedEntity* target, const idVec3& aimPoint,
    const idVec3& interactionDirection);
float Tungsten_GetAICameraLerpScale();
float Tungsten_GetAICameraForwardOffset();
void Tungsten_RenderAICameraView(
    idAnimatedEntity* target, idPlayer* player,
    const idVec3& cameraPosition, const idMat3& cameraAxis);

class idAICamera_Control {
public:
    idAICamera_Control();
    virtual ~idAICamera_Control();

    void FlyTo(const idVec3& endPosition);
    void Draw(idPlayer* player);
    void Update(const usercmd_t& previousCommand,
        const usercmd_t& currentCommand, bool actionScriptRunning);

    idAnimatedEntity* target;
    bool flying;
    idVec3 flyTo;
    idVec3 camPos;
    idMat3 camAxis;
    idVec3 interactionNormal;
    idAngles angles;
    float distance;
};
