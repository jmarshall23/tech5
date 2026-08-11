#pragma once

#include "game/entities/breakable.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/vector.h"

class idDeclEntityDef;
class idRenderModelDiscreteAnimation;
class idTreeAnimator;
class idBreakableManager;

struct breakableJoint_t {
    idJointIndex jointIndex;
    int pieceIndex = -1;
};

class idBreakableManagerServices {
public:
    virtual ~idBreakableManagerServices() = default;
    virtual const idDeclEntityDef* GetDeclaration(
        const idBreakable*) const { return nullptr; }
    virtual void PrepareForUse(idBreakable&, const idVec3&,
        const idMat3&) {}
    virtual bool IsRelaxedChatterEnabled(
        const idBreakable&) const { return false; }
    virtual bool HasAnimatorSkeleton(const idTreeAnimator*) const {
        return false;
    }
    virtual void GetAnimatorOrigin(
        const idTreeAnimator*, idVec3& origin) const { origin.Zero(); }
    virtual int GetPieceCount(
        const idRenderModelDiscreteAnimation*) const { return 0; }
    virtual void ResetModel(idRenderModelDiscreteAnimation*) {}
    virtual bool GetModelSpaceJointTransform(const idTreeAnimator*,
        idJointIndex, idVec3&, idMat3&) const { return false; }
    virtual bool GetPiecePosition(const idRenderModelDiscreteAnimation*,
        int, idVec3&, idMat3&) const { return false; }
    virtual bool GetInverseBasePose(const idTreeAnimator*,
        idJointIndex, idVec3&, idMat3&) const { return false; }
    virtual void SetPiecePosition(idRenderModelDiscreteAnimation*, int,
        const idVec3&, const idMat3&) {}
    virtual idRenderModelDiscreteAnimation* GetBreakableModel(
        idBreakable&) { return nullptr; }
    virtual idBreakable* SpawnBreakable(
        const idDeclEntityDef*) { return nullptr; }
    virtual bool HasValidBreakableModel(idBreakable*) const {
        return false;
    }
    virtual void PreparePooledBreakable(
        idBreakable&, const idVec3&) {}
    virtual void RemoveInvalidBreakable(idBreakable*) {}
    virtual void Warn(const char*) {}
};

class idBreakableManager {
public:
    struct breakables_t {
        idStaticList<idBreakable*, 16> entity;
        int next = 0;
    };

    static void SetServices(idBreakableManagerServices* services);
    static idBreakableManagerServices& Services();

    int FindBreakable(const idDeclEntityDef* declaration) const;
    idBreakable* UseBreakable(const idDeclEntityDef* declaration,
        const idVec3& origin, const idMat3& axis,
        const idVec3& direction, const idVec3* position,
        float impulse, float fadeTime);
    void ReactToMover();
    bool OrientBodies(const idTreeAnimator* animator,
        idRenderModelDiscreteAnimation* breakableModel,
        const idVec3& breakableOrigin, const idMat3& breakableAxis,
        const idList<breakableJoint_t, 5>& joints);
    void OrientAndUseBreakable(const idDeclEntityDef* declaration,
        const idVec3& origin, const idMat3& axis,
        const idVec3& explosionOrigin, float impulse,
        const idTreeAnimator* animator,
        const idList<breakableJoint_t, 5>& joints);
    void AddBreakable(
        const idDeclEntityDef* declaration, const idVec3& origin);

    idStaticList<breakables_t, 16> breakable;
};
