#pragma once

#include "decls/decl.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idMaterial;

enum foliageShape_t : int {
    FOLIAGE_SHAPE_AUTOSPRITES = 0,
    FOLIAGE_SHAPE_DOUBLES,
    FOLIAGE_SHAPE_TRIPLES,
    FOLIAGE_SHAPE_FIXEDSPRITES,
    FOLIAGE_SHAPE_NUM
};

class alignas(4) idDeclFoliage : public idDecl {
public:
    using MaterialResolver = const idMaterial* (*)(const char* name,
        bool makeDefault);

    idDeclFoliage();

    idDeclInfo* GetDeclInfo() const override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void Clear();

    static void SetMaterialResolver(MaterialResolver resolver);

    std::uint16_t quadWidth;
    std::uint16_t quadHeight;
    float widthVariance;
    float heightVariance;
    idVec3 colorVariance;
    bool rndFlipHoriz;
    float swayMagnitude;
    const idMaterial* material;
    unsigned int shape;
    idList<const idMaterial*, 5> stampMaterials;
    float stampScale;
    float stampParms[4];
    float stampCovers[4];
    idAtomicString stampBlendMode;
    bool isReferenceType;
    bool isSinglePlacement;

    static idDeclInfoTemplate<idDeclFoliage> resourceList;

private:
    static MaterialResolver materialResolver;
};
