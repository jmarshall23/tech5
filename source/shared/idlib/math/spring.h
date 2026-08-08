#pragma once

#include "vector.h"

#include <algorithm>
#include <cmath>

template<typename vectorType>
struct idSpringDimension;

template<> struct idSpringDimension<idVec1> { static constexpr int value = 1; };
template<> struct idSpringDimension<idVec2> { static constexpr int value = 2; };
template<> struct idSpringDimension<idVec3> { static constexpr int value = 3; };

template<typename vectorType>
class idSpring {
public:
    idSpring()
        : maxSpeed(0.0f), hasPMax(false), hasPMin(false),
          k(1.0f), c(2.0f), m(1.0f), restLength(0.0f) {
        p0.Zero();
        p1.Zero();
        vel.Zero();
        pMin.Zero();
        pMax.Zero();
    }

    void SetConstants(float springConstant, const float dampingConstant) {
        k = std::min(10000.0f, std::max(0.0f, springConstant));
        c = dampingConstant < 0.0f ? 2.0f * std::sqrt(m * k)
            : dampingConstant;
    }

    void SetMass(const float mass) { m = mass > 0.0f ? mass : 1.0f; }
    void SetRestLength(const float length) { restLength = std::max(0.0f, length); }
    void SetMaxSpeed(const float speed) { maxSpeed = speed; }
    void SetAnchor(const vectorType& anchor) { p0 = anchor; }
    void SetPosition(const vectorType& position) { p1 = position; }
    void SetVelocity(const vectorType& velocity) { vel = velocity; }
    void SetMinimum(const vectorType& minimum) { pMin = minimum; hasPMin = true; }
    void SetMaximum(const vectorType& maximum) { pMax = maximum; hasPMax = true; }
    void ClearMinimum() { hasPMin = false; }
    void ClearMaximum() { hasPMax = false; }

    const vectorType& GetPosition() const { return p1; }
    const vectorType& GetVelocity() const { return vel; }

    void Update(float deltaTime) {
        while (deltaTime > 0.0f) {
            const float step = std::min(deltaTime, 0.0085f);
            deltaTime -= step;

            float distanceSquared = 0.0f;
            float difference[idSpringDimension<vectorType>::value];
            for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
                difference[index] = p1[index] - p0[index];
                distanceSquared += difference[index] * difference[index];
            }
            const float distance = std::sqrt(distanceSquared);
            const float inverseDistance = distance > 0.00001f ? 1.0f / distance : 0.0f;
            const float springForce = -(distance - restLength) * k;
            for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
                const float force = difference[index] * inverseDistance * springForce
                    - vel[index] * c;
                vel[index] += (force / m) * step;
            }

            float speedSquared = 0.0f;
            for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
                speedSquared += vel[index] * vel[index];
            }
            const float speed = std::sqrt(speedSquared);
            if (maxSpeed > 0.0f && speed > maxSpeed) {
                const float scale = maxSpeed / speed;
                for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
                    vel[index] *= scale;
                }
            }
            if (speed < 0.00001f) {
                vel.Zero();
            }
            for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
                p1[index] += vel[index] * step;
            }
            if (distance < 0.00001f) {
                p1 = p0;
            }
        }

        for (int index = 0; index < idSpringDimension<vectorType>::value; ++index) {
            if (hasPMin) {
                p1[index] = std::max(p1[index], pMin[index]);
            }
            if (hasPMax) {
                p1[index] = std::min(p1[index], pMax[index]);
            }
        }
    }

private:
    vectorType p0;
    vectorType p1;
    vectorType vel;
    float maxSpeed;
    vectorType pMin;
    vectorType pMax;
    bool hasPMax;
    bool hasPMin;
    float k;
    float c;
    float m;
    float restLength;
};

static_assert(sizeof(idSpring<idVec1>) == 44, "Recovered idSpring<idVec1> ABI changed");
static_assert(sizeof(idSpring<idVec2>) == 64, "Recovered idSpring<idVec2> ABI changed");
static_assert(sizeof(idSpring<idVec3>) == 84, "Recovered idSpring<idVec3> ABI changed");
