#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idDeclEntityDef;
class idBounceSparks;

class idBounceSparksServices {
public:
    virtual ~idBounceSparksServices() = default;
    virtual void SetThinkActive(idBounceSparks&, bool) {}
    virtual void ReportBadData(const idBounceSparks&) {}
    virtual int GetGameMilliseconds() const { return 0; }
    virtual float RandomFloat() { return 0.0f; }
    virtual void GetOrigin(const idBounceSparks&, idVec3& origin) const {
        origin.Zero();
    }
    virtual void AddBreakable(
        const idDeclEntityDef*, const idVec3&) {}
    virtual void UseBreakable(const idDeclEntityDef*, const idVec3&,
        const idMat3&, const idVec3&, const idVec3&, float,
        const idList<int, 5>&) {}
};

class idBounceSparks {
public:
    struct sparkTimings_t {
        float minDelay = 0.0f;
        float maxDelay = 0.0f;
    };

    idBounceSparks();
    virtual ~idBounceSparks();

    static void SetServices(idBounceSparksServices* services);
    static idBounceSparksServices& Services();

    void Spawn();
    virtual void Think();

    const idDeclEntityDef* declBreakable;
    float minTimeBetweenBursts;
    float maxTimeBetweenBursts;
    idVec3 burstDirection;
    float impulse;
    idList<sparkTimings_t, 5> sparkTimings;
    int nextSparkTime;
};
