#pragma once

// The IDA local-type export for this header also contained unrelated GPU
// register types.  Only idAIUtils is part of the Tungsten header surface.
class idAIUtils {
public:
    static float CalcDecelerationDistance(float currentVelocity,
        float decelerationRate);
    static float CalcExactDecelerationRate(float currentVelocity,
        float distance);
};
