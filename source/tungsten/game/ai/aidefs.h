#pragma once

#include "../../../shared/idlib/typesafenumber.h"

// Unit tag used by the retail idTypesafeNumber specialization for scaled
// game-clock ticks.
enum gameTimeUnique_t : int {};
using gameTime_t = idTypesafeNumber<int, gameTimeUnique_t>;

int GetEndTimeByFrames(int frameCount);

int GetRandomInterval(int minValue, int maxValue);
float GetRandomInterval(float minValue, float maxValue);
int GetRandomIntervalBySeconds(float minSeconds, float maxSeconds);

int RandomInt(int maxValue);
int RandomInt(int minValue, int maxValue);
float RandomFloat();
float RandomFloat(float maxValue);
float RandomFloat(float minValue, float maxValue);

gameTime_t SecondsToTicks(float seconds);

// Engine-owned random and scaled-clock state used by the recovered helpers.
unsigned int& Tungsten_GetAIRandomSeed();
int Tungsten_GetAIGameMilliseconds();
int Tungsten_GetAIGameMillisecondsPerRealSecond();
