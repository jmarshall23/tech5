#pragma once

#include "decls/animwebs/animwebscalar.h"
#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idAnimator_BlendEq : public idAnimator_Base {
public:
    struct idNamedAnim {
        const idMD6Anim* anim;
        unsigned char wrapMode;
        unsigned char weightGroup;
        float rate;
    };

    idAnimator_BlendEq();
    ~idAnimator_BlendEq() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    void InternalStart(const idAnimStack* stack, int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime) override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    void SetNamedAnims(const idList<idNamedAnim, 33>& animations);
    void SetBlendEquation(idAnimStack* stack, int startTime,
        const char* equation, const void* modelInfo = nullptr);
    void ParseBlendEquation(idAnimStack* stack, int startTime,
        const void* modelInfo = nullptr);

    idStr blendEq;
    idMD6Branch* mergeBranch;
    idList<idAnimWebScalar, 33> scalars;
    idList<idAnimWebScalarPair, 33> scalarPairs;
    idScalarMemBlock* scalarMem;
    idList<idNamedAnim, 33> namedAnims;

private:
    void CopyScalars(const idAnimStack* stack, int currentTime,
        unsigned char fieldFlags);
};

class idAnimatorParms_BlendEq : public idAnimatorParms_Base {
public:
    idStr blendEq;
    idList<idAnimWebScalar, 5> scalars;
    idScalarMemBlock* scalarMem;
    idList<idAnimator_BlendEq::idNamedAnim, 5> anims;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_BlendEq::idNamedAnim) == 12,
    "Recovered named-animation ABI changed");
static_assert(sizeof(idAnimator_BlendEq) == 128,
    "Recovered idAnimator_BlendEq ABI changed");
static_assert(sizeof(idAnimatorParms_BlendEq) == 124,
    "Recovered blend-equation parameters ABI changed");
#endif
