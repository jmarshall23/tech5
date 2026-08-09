#include "decls/declribbon.h"

idDeclInfoTemplate<idDeclRibbon> idDeclRibbon::resourceList(
    "ribbon", "idDeclRibbon", "ribbon");

idDeclRibbon::idDeclRibbon()
    : material(nullptr), duration(0), maxLength(0.0f), fadeInFraction(0.0f),
      fadeOutFraction(0.0f), gravity(0.0f, 0.0f, 0.0f),
      velocity(0.0f, 0.0f, 0.0f), startWidth(2.0f), endWidth(32.0f),
      color(1.0f, 1.0f, 1.0f, 1.0f), viewOriented(true),
      reorientNodes(false), textureRepeat(false),
      textureRepeatStretch(false), textureTMin(0.0f), textureTMax(1.0f),
      nodeSubdivision(0.0f), minNodeDistance(0.0f),
      helix{0.0f, 0.0f, 0.0f, idVec2(0.0f, 0.0f),
          idVec2(0.0f, 0.0f)},
      turbulence{0.0f, 0.0f, 1.0f,
          idVec4(0.93f, 1.0f, 0.91000003f, 0.73000002f)} {
}

idDeclInfo* idDeclRibbon::GetDeclInfo() const { return &resourceList; }
