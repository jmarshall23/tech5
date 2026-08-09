#include "models/foliage/declfoliage.h"

#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>

namespace {

bool Key(const idToken& token, const char* name) {
    return idStr::Icmp(token.c_str(), name) == 0;
}

foliageShape_t ShapeForName(const char* name) {
    if (idStr::Icmp(name, "doubles") == 0) return FOLIAGE_SHAPE_DOUBLES;
    if (idStr::Icmp(name, "triples") == 0) return FOLIAGE_SHAPE_TRIPLES;
    if (idStr::Icmp(name, "fixedsprites") == 0)
        return FOLIAGE_SHAPE_FIXEDSPRITES;
    return FOLIAGE_SHAPE_AUTOSPRITES;
}

} // namespace

idDeclInfoTemplate<idDeclFoliage> idDeclFoliage::resourceList(
    "foliage", "idDeclFoliage", "foliage");
idDeclFoliage::MaterialResolver idDeclFoliage::materialResolver = nullptr;

idDeclFoliage::idDeclFoliage() {
    Clear();
}

void idDeclFoliage::SetMaterialResolver(MaterialResolver resolver) {
    materialResolver = resolver;
}

idDeclInfo* idDeclFoliage::GetDeclInfo() const {
    return &resourceList;
}

const char* idDeclFoliage::DefaultDefinition() const {
    return "{\n\tmaterial\tfoliage/default\n\tquadWidth\t64\n"
        "\tquadHeight\t64\n\tshape\t\tautosprites\n}\n";
}

void idDeclFoliage::Clear() {
    quadWidth = 0;
    quadHeight = 0;
    widthVariance = 0.0f;
    heightVariance = 0.0f;
    colorVariance.Set(1.0f, 1.0f, 1.0f);
    rndFlipHoriz = false;
    swayMagnitude = 0.0f;
    material = nullptr;
    shape = FOLIAGE_SHAPE_AUTOSPRITES;
    stampMaterials.Clear();
    stampScale = 1.0f;
    for (int index = 0; index < 4; ++index) {
        stampParms[index] = 1.0f;
        stampCovers[index] = 1.0f;
    }
    stampBlendMode.Set("none");
    isReferenceType = false;
    isSinglePlacement = false;
}

void idDeclFoliage::Parse(idParser* const parser) {
    Clear();
    if (parser == nullptr) return;
    idTokenStatic<260> token;
    while (parser->ReadToken(token)) {
        if (Key(token, "}")) break;
        if (Key(token, "{") ) continue;
        if (Key(token, "quadWidth")) {
            quadWidth = static_cast<std::uint16_t>((std::max)(0,
                (std::min)(65535, parser->ParseInt())));
        } else if (Key(token, "quadHeight")) {
            quadHeight = static_cast<std::uint16_t>((std::max)(0,
                (std::min)(65535, parser->ParseInt())));
        } else if (Key(token, "widthVariance")) {
            widthVariance = parser->ParseFloat();
        } else if (Key(token, "heightVariance")) {
            heightVariance = parser->ParseFloat();
        } else if (Key(token, "colorVariance")) {
            colorVariance.x = parser->ParseFloat();
            colorVariance.y = parser->ParseFloat();
            colorVariance.z = parser->ParseFloat();
        } else if (Key(token, "rndFlipHoriz")) {
            rndFlipHoriz = parser->ParseBool();
        } else if (Key(token, "swayMagnitude")) {
            swayMagnitude = parser->ParseFloat();
        } else if (Key(token, "material")) {
            if (!parser->ExpectAnyToken(token)) break;
            material = materialResolver != nullptr
                ? materialResolver(token.c_str(), true) : nullptr;
        } else if (Key(token, "shape")) {
            if (!parser->ExpectAnyToken(token)) break;
            shape = ShapeForName(token.c_str());
        } else if (Key(token, "stampMaterial")) {
            stampMaterials.Clear();
            while (parser->ReadTokenOnLine(token) != 0) {
                const idMaterial* const stamp = materialResolver != nullptr
                    ? materialResolver(token.c_str(), false) : nullptr;
                if (stamp != nullptr) stampMaterials.Append(stamp);
            }
        } else if (Key(token, "stampScale")) {
            stampScale = parser->ParseFloat();
        } else if (Key(token, "stampParms")) {
            if (!parser->Parse1DMatrix(4, stampParms))
                parser->Error("Invalid stampParms parameter: %s\n",
                    GetName());
        } else if (Key(token, "stampCovers")) {
            if (!parser->Parse1DMatrix(4, stampCovers))
                parser->Error("Invalid stampCovers parameter: %s\n",
                    GetName());
        } else if (Key(token, "stampBlendMode")) {
            if (!parser->ExpectAnyToken(token)) break;
            stampBlendMode.Set(token.c_str());
        } else if (Key(token, "referenceType")) {
            isReferenceType = parser->ParseBool();
        } else if (Key(token, "singlePlacement")) {
            isSinglePlacement = parser->ParseBool();
        } else {
            parser->Warning("idDeclFoliage::Parse - bad token %s",
                token.c_str());
        }
    }
}
