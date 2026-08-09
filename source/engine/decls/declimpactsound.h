#pragma once

#include "decls/decltypeinfo.h"

class idSoundShader;

class idDeclImpactSound : public idDeclTypeInfo {
public:
    idDeclImpactSound();
    idDeclInfo* GetDeclInfo() const override;
    const idSoundShader* GetImpactSoundForMaterial(int materialID) const;

    const idSoundShader* defaultSound;
    const idSoundShader* metalSound;
    const idSoundShader* stoneSound;
    const idSoundShader* fleshSound;
    const idSoundShader* woodSound;
    const idSoundShader* cardboardSound;
    const idSoundShader* liquidSound;
    const idSoundShader* glassSound;
    const idSoundShader* plasticSound;
    const idSoundShader* asphaltSound;
    const idSoundShader* dirtSound;
    const idSoundShader* concreteSound;
    const idSoundShader* foliageSound;
    const idSoundShader* linoleumSound;
    const idSoundShader* fabricSound;
    const idSoundShader* rubberSound;
    const idSoundShader* rockSound;
    const idSoundShader* steamPipeSound;
    const idSoundShader* waterPipeSound;
    const idSoundShader* armorSound;
    const idSoundShader* sludgeSound;
    const idSoundShader* impNestSound;
    const idSoundShader* hollowMetalSound;
    const idSoundShader* sheetMetalSound;
    const idSoundShader* fleshPlayerSound;
    const idSoundShader* bloodPoolSound;
    const idSoundShader* ashSound;
    const idSoundShader* mutantFleshSound;
    const idSoundShader* thickPaddingSound;
    const idSoundShader* playerAPCMetalSound;
    const idSoundShader* ricketyMetalSound;
    const idSoundShader* ricketyWoodSound;
    int soundInterval;

    static idDeclInfoTemplate<idDeclImpactSound> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclImpactSound) == 196,
    "Recovered impact-sound declaration ABI changed");
#endif
