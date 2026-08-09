#pragma once

#include "gamelib/physics/physics_dynamicbase.h"
#include "idlib/containers/list.h"
#include "idlib/math/curve.h"
#include "idlib/math/interpolate.h"

class idPush;

struct parametricPState_t {
    int time;
    int atRest;
    idVec3 worldOrigin;
    idAngles worldAngles;
    idMat3 worldAxis;
    idVec3 localOrigin;
    idAngles localAngles;
    idExtrapolate<idVec3> linearExtrapolation;
    idExtrapolate<idAngles> angularExtrapolation;
    idInterpolateAccelDecelLinear<idVec3> linearInterpolation;
    idInterpolateAccelDecelLinear<idAngles> angularInterpolation;
    idCurve_Spline<idVec3>* spline;
    idCurve_Spline<idAngles>* angularSpline;
    idInterpolateAccelDecelLinear<float> splineInterpolate;
    bool useSplineAngles;

    parametricPState_t();
};

class idPhysics_Parametric : public idPhysics_DynamicBase {
public:
    idPhysics_Parametric();
    ~idPhysics_Parametric() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    idClipModel* GetClipModel(int) override;
    int GetNumClipModels() override;
    void SetMass(float, int) override;
    float GetMass(int) override;
    void SetContents(int, int) override;
    int GetContents(int) override;
    const idBounds* GetBounds(int) override;
    const idBounds* GetAbsBounds(int) override;
    void SetOrigin(const idVec3*, int) override;
    void SetAxis(const idMat3*, int) override;
    void Translate(const idVec3*, int) override;
    void Rotate(const idRotation*, int) override;
    const idVec3* GetOrigin(int) override;
    const idMat3* GetAxis(int) override;
    const idVec3* GetLocalOrigin(int) override;
    const idMat3* GetLocalAxis(int) override;
    void SetLinearVelocity(const idVec3*, int) override;
    void SetAngularVelocity(const idVec3*, int) override;
    idVec3* GetLinearVelocity(idVec3*, int) override;
    idVec3* GetAngularVelocity(idVec3*, int) override;
    void SetWaterEntNum(int) override;
    int GetWaterEntNum() override;
    void SetWaterSurfaceWrldHeight(float) override;
    float GetWaterSurfaceWrldHeight() override;
    void GetImpactInfo(int, const idVec3*, impactInfo_t*) override;
    void ApplyImpulse(int, const idVec3*, const idVec3*) override;
    void ApplyForce(int, const idVec3*, const idVec3*) override;
    void Activate() override;
    void PutToRest() override;
    bool IsAtRest() override;
    bool IsPushable(int) override;
    void SaveState() override;
    void RestoreState() override;
    bool Evaluate(int, int) override;
    void UpdateTime(int) override;
    void ClipRotation(trace_t*, const idRotation*, const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;
    void SetPushed(int) override;
    idVec3* GetPushedLinearVelocity(idVec3*, int) override;
    idVec3* GetPushedAngularVelocity(idVec3*, int) override;
    void SetMaster(bool, const idVec3*, const idMat3*, bindFlags_t) override;
    void SetLocalOrigin(const idVec3*, int) override;
    void SetLocalAxis(const idMat3*, int) override;
    int GetBlockingEntityNum() override;
    int GetLinearEndTime() override;
    int GetAngularEndTime() override;

    bool IsOutsideWorld() override;

    void SetPusher(idPush* push, int flags);
    bool IsPusher() const;
    idCurve_Spline<idVec3>* GetSpline();
    const idAngles* GetLocalAngles() const;
    void SetLinearExtrapolation(extrapolation_t type, int currentTime,
        int startTime, int duration, const idVec3& base,
        const idVec3& baseSpeed, const idVec3& speed);
    void SetAngularExtrapolation(extrapolation_t type, int currentTime,
        int startTime, int duration, const idAngles& base,
        const idAngles& baseSpeed, const idAngles& speed);
    idAngles GetCurrentAngularExtrapolationAngles(int time) const;
    void SetLinearInterpolation(int currentTime, int startTime,
        int accelTime, int decelTime, int duration,
        const idVec3& start, const idVec3& end);
    void SetAngularInterpolation(int currentTime, int startTime,
        int accelTime, int decelTime, int duration,
        const idAngles& start, const idAngles& end);
    void SetSpline(idCurve_Spline<idVec3>* spline, int accelTime,
        int decelTime, bool useSplineAngles,
        idCurve_Spline<idAngles>* angularSpline = nullptr);
    void SetWorldOrientation(const idVec3& origin, const idMat3& axis);
    void ClearWorldOrientation();
    void ForceUpdateSpatialVelocity(int timeStepMSec);
    extrapolation_t GetAngularExtrapolationType() const;

    parametricPState_t current;
    parametricPState_t saved;
    idVec6 spatialVelocity;
    int blockingPhysicsId;
    idBounds absBounds;
    idPush* pusher;
    bool isPusher;
    idClipModel* clipModel;
    int pushFlags;
    bool hasMaster;
    bool isOrientated;
    bool hasWorldOrientation;
    idMat3 worldAxis;
    idVec3 worldOrigin;
};

class idPhysics_ParametricMM;
struct parametricSplineBatchInfo_tMM {
    float DistanceFromMe;
    idPhysics_ParametricMM* PhysObj;
};

struct parametricPState_tMM {
    int time;
    float length;
    float totalLength;
    int atRest;
    idVec3 worldOrigin;
    idMat3 worldAxis;
    idVec3 localOrigin;
    idMat3 localAxis;
    idExtrapolate<idVec3> linearExtrapolation;
    idExtrapolate<float> angularExtrapolation;
    idMat3 angularExtrapolationStartAxis;
    idVec3 angularExtrapolationRotVec;
    idVec3 linearVelocity;
    idVec3 angularVelocity;
    idInterpolateAccelDecelLinear<idVec3> linearInterpolation;
    idInterpolateAccelDecelLinear<idQuat> angularInterpolation;
    idInterpolateAccelLinearEx<float> splineInterpolate;
    idInterpolate<idQuat> splineAngleInterpolate;
    idCurve_Spline<idVec3>* spline;
    idVec3 splineDerivative;
    bool useSplineAngles;
    int pauseTime;
    idExtrapolate<float> oscillationExtrapolation[3];
    bool oscillationZRelative;
    idInterpolate<idVec3> localOffsetInterpolation;
    idPhysics_ParametricMM* splineMaster;
    idInterpolate<idVec3> localOriginScaleInterpolation;
    idList<parametricSplineBatchInfo_tMM, 5> splineChilds;
    bool splineDummy;

    parametricPState_tMM();
};

class idPhysics_ParametricMM : public idPhysics_DynamicBase {
public:
    idPhysics_ParametricMM();
    ~idPhysics_ParametricMM() override;
    void SetClipModel(idClipModel*, float, int, bool) override;
    idClipModel* GetClipModel(int) override;
    int GetNumClipModels() override;
    void SetMass(float, int) override;
    float GetMass(int) override;
    void SetContents(int, int) override;
    int GetContents(int) override;
    const idBounds* GetBounds(int) override;
    const idBounds* GetAbsBounds(int) override;
    void SetOrigin(const idVec3*, int) override;
    void SetAxis(const idMat3*, int) override;
    void Translate(const idVec3*, int) override;
    void Rotate(const idRotation*, int) override;
    const idVec3* GetOrigin(int) override;
    const idMat3* GetAxis(int) override;
    const idVec3* GetLocalOrigin(int) override;
    const idMat3* GetLocalAxis(int) override;
    void SetLinearVelocity(const idVec3*, int) override;
    void SetAngularVelocity(const idVec3*, int) override;
    idVec3* GetLinearVelocity(idVec3*, int) override;
    idVec3* GetAngularVelocity(idVec3*, int) override;
    void SetWaterEntNum(int) override;
    int GetWaterEntNum() override;
    void SetWaterSurfaceWrldHeight(float) override;
    float GetWaterSurfaceWrldHeight() override;
    void GetImpactInfo(int, const idVec3*, impactInfo_t*) override;
    void ApplyImpulse(int, const idVec3*, const idVec3*) override;
    void ApplyForce(int, const idVec3*, const idVec3*) override;
    void Activate() override;
    void PutToRest() override;
    bool IsAtRest() override;
    bool IsPushable(int) override;
    void SaveState() override;
    void RestoreState() override;
    bool Evaluate(int, int) override;
    void UpdateTime(int) override;
    void ClipRotation(trace_t*, const idRotation*, const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;
    void SetPushed(int) override;
    idVec3* GetPushedLinearVelocity(idVec3*, int) override;
    idVec3* GetPushedAngularVelocity(idVec3*, int) override;
    void SetMaster(bool, const idVec3*, const idMat3*, bindFlags_t) override;
    void SetLocalOrigin(const idVec3*, int) override;
    void SetLocalAxis(const idMat3*, int) override;
    int GetBlockingEntityNum() override;
    int GetLinearEndTime() override;
    int GetAngularEndTime() override;
    bool IsOutsideWorld() override;

    void SetPusher(idPush* push, int flags);
    idCurve_Spline<idVec3>* GetSpline();
    void SetUseSplineAngles(bool value);
    void PauseParametricUntil(int resumeTime);
    void SetLinearExtrapolation(extrapolation_t type, int currentTime,
        int startTime, int duration, const idVec3& base,
        const idVec3& baseSpeed, const idVec3& speed);
    void SetAngularExtrapolation(extrapolation_t type, int currentTime,
        int startTime, int duration, const idMat3& startAxis,
        const idVec3& rotationVector, float baseSpeed, float speed);
    void SetSpline(idCurve_Spline<idVec3>* spline, int accelTime,
        int decelTime, bool useSplineAngles);

    parametricPState_tMM current;
    parametricPState_tMM saved;
    int blockingPhysicsId;
    idBounds absBounds;
    idPush* pusher;
    bool isPusher;
    idClipModel* clipModel;
    int pushFlags;
    bool hasMaster;
    bool isOrientated;
    bool hasWorldOrientation;
    idMat3 worldAxis;
    idVec3 worldOrigin;
    int collideClipMask;
    bool collideCallbackEnabled;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(parametricPState_t) == 496,
    "Recovered parametric state ABI changed");
static_assert(sizeof(idPhysics_Parametric) == 1232,
    "Recovered idPhysics_Parametric ABI changed");
static_assert(sizeof(parametricPState_tMM) == 872,
    "Recovered MM parametric state ABI changed");
static_assert(sizeof(idPhysics_ParametricMM) == 1968,
    "Recovered idPhysics_ParametricMM ABI changed");
#endif
