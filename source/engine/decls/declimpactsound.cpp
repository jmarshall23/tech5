#include "decls/declimpactsound.h"

idDeclInfoTemplate<idDeclImpactSound> idDeclImpactSound::resourceList(
    "impactSounds", "idDeclImpactSound", "tdef");

idDeclImpactSound::idDeclImpactSound()
    : defaultSound(nullptr), metalSound(nullptr), stoneSound(nullptr),
      fleshSound(nullptr), woodSound(nullptr), cardboardSound(nullptr),
      liquidSound(nullptr), glassSound(nullptr), plasticSound(nullptr),
      asphaltSound(nullptr), dirtSound(nullptr), concreteSound(nullptr),
      foliageSound(nullptr), linoleumSound(nullptr), fabricSound(nullptr),
      rubberSound(nullptr), rockSound(nullptr), steamPipeSound(nullptr),
      waterPipeSound(nullptr), armorSound(nullptr), sludgeSound(nullptr),
      impNestSound(nullptr), hollowMetalSound(nullptr), sheetMetalSound(nullptr),
      fleshPlayerSound(nullptr), bloodPoolSound(nullptr), ashSound(nullptr),
      mutantFleshSound(nullptr), thickPaddingSound(nullptr),
      playerAPCMetalSound(nullptr), ricketyMetalSound(nullptr),
      ricketyWoodSound(nullptr), soundInterval(100) {
}

idDeclInfo* idDeclImpactSound::GetDeclInfo() const { return &resourceList; }

const idSoundShader* idDeclImpactSound::GetImpactSoundForMaterial(
        const int materialID) const {
    switch (materialID) {
    case 1: return metalSound;
    case 2: return stoneSound;
    case 3: return fleshSound;
    case 4: return woodSound;
    case 5: return cardboardSound;
    case 6: return liquidSound;
    case 7: return glassSound;
    case 8: return plasticSound;
    case 9: return asphaltSound;
    case 10: return dirtSound;
    case 11: return concreteSound;
    case 12: return foliageSound;
    case 13: return linoleumSound;
    case 14: return fabricSound;
    case 15: return rubberSound;
    case 16: return rockSound;
    case 17: return steamPipeSound;
    case 18: return waterPipeSound;
    case 19: return armorSound;
    case 20: return sludgeSound;
    case 21: return impNestSound;
    case 22: return hollowMetalSound;
    case 23: return fleshPlayerSound;
    case 25: return bloodPoolSound;
    case 26: return ashSound;
    case 27: return mutantFleshSound;
    case 28: return thickPaddingSound;
    case 29: return playerAPCMetalSound;
    case 30: return ricketyMetalSound;
    case 31: return ricketyWoodSound;
    case 32: return sheetMetalSound;
    default: return defaultSound;
    }
}
