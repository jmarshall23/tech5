#include "decls/declflare.h"

idDeclInfoTemplate<idDeclFlare> idDeclFlare::resourceList(
    "flare", "idDeclFlare", "flare");

idDeclFlare::idDeclFlare()
    : subflares(16), reservedFlags(0), useAltViewVecCalc(0),
      viewAngleFade(0.0f), invViewAngleFade(1.0f), brightness(1.0f) {
}

idDeclInfo* idDeclFlare::GetDeclInfo() const { return &resourceList; }
