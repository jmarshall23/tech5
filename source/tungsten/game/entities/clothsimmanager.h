#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/vector.h"
#include "models/cloth/clothsim.h"
#include "models/cloth/declcloth.h"

class idTreeAnimator;
class idClothSimManagerServices;

struct clothManagerWeaponTrace_t {
    idVec3 start;
    idVec3 direction;
    float strength;
    bool causesHoles;
    int type;

    clothManagerWeaponTrace_t();
};

class idClothSimManager {
public:
    struct clothSims_t {
        enum state_t : int {
            READY_TO_USE = 0,
            READY_TO_FREE = 1,
            IN_USE = 2
        };

        state_t state;
        idClothSim* clothSim;

        clothSims_t();
    };

    idClothSimManager();
    ~idClothSimManager();

    static void SetServices(idClothSimManagerServices* services);
    static idClothSimManagerServices& Services();

    void Update();
    void FreeCloth(idClothSim* clothSim);
    idClothSim* ReserveCloth(const idDeclCloth* declaration);
    void UpdateJointsWithClothSim(idTreeAnimator* animator,
        idClothSim* clothSim);
    void UpdateWeaponTraces(idClothSim* clothSim);
    void GetGeneralOriginAxis(idClothSim* clothSim, idVec3& origin,
        idMat3& axis);
    void AddCloth(const idDeclCloth* declaration);

    idStaticList<clothSims_t, 16> cloth;
};

class idClothSimManagerServices {
public:
    virtual ~idClothSimManagerServices() = default;

    virtual void Warn(const char*) {}
    virtual void Error(const char*) {}
    virtual bool GetAnimatorTransform(idTreeAnimator*, idVec3&,
        idMat3&) const { return false; }
    virtual bool GetJointWorldTransform(idTreeAnimator*, int,
        idVec3&, idMat3&) const { return false; }
    virtual void SetJointPosition(idTreeAnimator*, int,
        const idVec3&) {}
    virtual void SetJointAxis(idTreeAnimator*, int, const idMat3&) {}
    virtual void BlendTree(idTreeAnimator*) {}
    virtual void DebugJointAxis(const idVec3&, const idMat3&) {}
    virtual void GatherWeaponTraces(const idBounds&,
        idList<clothManagerWeaponTrace_t, 5>&) const {}
};

void Tungsten_ClothSimAllocationFailure(idClothSim* allocation);
