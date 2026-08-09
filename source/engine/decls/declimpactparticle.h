#pragma once

#include "decls/decltypeinfo.h"

class idDeclParticle;

class idDeclImpactParticle : public idDeclTypeInfo {
public:
    idDeclImpactParticle();
    idDeclInfo* GetDeclInfo() const override;
    const idDeclParticle* GetImpactParticleForMaterial(int materialID) const;

    const idDeclParticle* defaultPrt;
    const idDeclParticle* metalPrt;
    const idDeclParticle* stonePrt;
    const idDeclParticle* fleshPrt;
    const idDeclParticle* woodPrt;
    const idDeclParticle* cardboardPrt;
    const idDeclParticle* liquidPrt;
    const idDeclParticle* glassPrt;
    const idDeclParticle* plasticPrt;
    const idDeclParticle* asphaltPrt;
    const idDeclParticle* dirtPrt;
    const idDeclParticle* concretePrt;
    const idDeclParticle* foliagePrt;
    const idDeclParticle* linoleumPrt;
    const idDeclParticle* fabricPrt;
    const idDeclParticle* rubberPrt;
    const idDeclParticle* rockPrt;
    const idDeclParticle* steamPipePrt;
    const idDeclParticle* waterPipePrt;
    const idDeclParticle* armorPrt;
    const idDeclParticle* sludgePrt;
    const idDeclParticle* shieldPrt;
    const idDeclParticle* bloodPoolPrt;
    const idDeclParticle* ashPrt;
    const idDeclParticle* mutantFleshPrt;
    const idDeclParticle* thickPaddingPrt;

    static idDeclInfoTemplate<idDeclImpactParticle> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclImpactParticle) == 168,
    "Recovered impact-particle declaration ABI changed");
#endif
