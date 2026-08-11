#pragma once

#include "idlib/math/vector.h"

class idAnimatedEntity;
class idClothSim;
class idDeclCloth;
class idDeclEntityDef;
class idTreeAnimator;

class idClothComponentServices {
public:
    virtual ~idClothComponentServices() = default;
    virtual bool HasClothModel(const idDeclCloth*) const { return false; }
    virtual idTreeAnimator* GetTreeAnimator(idAnimatedEntity*) const {
        return nullptr;
    }
    virtual bool AnimatorMatchesCloth(idTreeAnimator*,
        const idDeclCloth*) const { return false; }
    virtual idClothSim* ReserveCloth(const idDeclCloth*) { return nullptr; }
    virtual void FreeCloth(idClothSim*) {}
    virtual bool GetEntityTransform(idAnimatedEntity*, idVec3&,
        idMat3&) const { return false; }
    virtual void SetClothTransform(idClothSim*, const idVec3&,
        const idMat3&, bool) {}
    virtual void RegisterBreakable(const idDeclEntityDef*,
        const idVec3&) {}
    virtual idVec3 GetTestWind() const {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    virtual void SetWind(idClothSim*, const idVec3&) {}
    virtual bool IsDetached(idClothSim*) const { return false; }
    virtual int GetJointCount(idTreeAnimator*) const { return 0; }
    virtual void HideJoint(idTreeAnimator*, int) {}
    virtual void UpdateJoints(idTreeAnimator*, idClothSim*) {}
    virtual bool GetClothTransform(idClothSim*, idVec3&, idMat3&) const {
        return false;
    }
    virtual void UseBreakable(const idDeclEntityDef*, const idVec3&,
        const idMat3&) {}
    virtual void UpdateWeaponTraces(idClothSim*) {}
    virtual void RunCloth(idClothSim*) {}
    virtual bool DebugEnabled() const { return false; }
    virtual void DebugDraw(idClothSim*) {}
};

void Tungsten_SetClothComponentServices(idClothComponentServices* services);

class idClothComponent {
public:
    idClothComponent();
    ~idClothComponent();
    void Init(idAnimatedEntity* animatedEntity);
    void Update();

    const idDeclCloth* clothDecl;
    idDeclEntityDef* gibEntity;
    idAnimatedEntity* animatedEntity;
    idClothSim* clothSim;
    bool isDetached;
};
