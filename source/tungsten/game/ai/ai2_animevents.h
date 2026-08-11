#pragma once

#include "idlib/math/vector.h"

class idMD6Anim;
class idCmdArgs;

#ifndef TUNGSTEN_EVENT_VOID_DEFINED
#define TUNGSTEN_EVENT_VOID_DEFINED
struct eventVoid {};
#endif

enum aiExtendedClipModelStatus_t : int;
enum aiFoci_t : int;
enum deathImpulse_t : int;
enum fxCondition_t : int;
enum voiceMsg_t : int;

// Synchronous, non-owning envelope for animation events whose concrete
// engine owners (animator, inventory, effects, physics, and renderer) live
// outside the recovered game module.
struct idAI2AnimEventCall {
    const char* eventName;
    const idMD6Anim* animation;
    const void* objects[4];
    const idVec3* vectors[2];
    const char* strings[2];
    int integers[4];
    float scalars[4];
    bool booleans[4];

    idAI2AnimEventCall(const char* eventNameValue,
            const idMD6Anim* animationValue)
        : eventName(eventNameValue), animation(animationValue), objects{},
          vectors{}, strings{}, integers{}, scalars{}, booleans{} {
    }
};

using idAI2AccelSimCallback = void (*)(const idCmdArgs& args);
void Tungsten_SetAI2AccelSimCallback(idAI2AccelSimCallback callback);
void accelSim_f(const idCmdArgs& args);
