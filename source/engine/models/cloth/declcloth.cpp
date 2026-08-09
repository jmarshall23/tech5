#include "models/cloth/declcloth.h"

#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>

namespace {

bool Key(const idToken& token, const char* name) {
    return idStr::Icmp(token.c_str(), name) == 0;
}

void ParseParticleFlags(idParser* parser,
    idDeclCloth::particleInfo_t& particle) {
    if (parser == nullptr || !parser->ExpectTokenString("{")) {
        return;
    }
    idTokenStatic<260> token;
    while (parser->ReadToken(token)) {
        if (Key(token, "}")) {
            break;
        }
        if (Key(token, "anchored")) {
            particle.anchored = true;
        } else if (Key(token, "forward")) {
            particle.forwardIndex = parser->ParseInt();
        } else if (Key(token, "right")) {
            particle.rightIndex = parser->ParseInt();
        } else {
            parser->Warning("idDeclCloth particle: bad token %s",
                token.c_str());
        }
    }
}

} // namespace

idDeclInfoTemplate<idDeclCloth> idDeclCloth::resourceList(
    "cloth", "idDeclCloth", "cloth");
idDeclCloth::MaterialResolver idDeclCloth::materialResolver = nullptr;
idDeclCloth::MD6Resolver idDeclCloth::md6Resolver = nullptr;
idDeclCloth::FXResolver idDeclCloth::fxResolver = nullptr;
idDeclCloth::JointResolver idDeclCloth::jointResolver = nullptr;
idDeclCloth::RopeChainResolver idDeclCloth::ropeChainResolver = nullptr;

idDeclCloth::idDeclCloth() {
    ResetValues();
}

void idDeclCloth::SetMaterialResolver(MaterialResolver resolver) {
    materialResolver = resolver;
}

void idDeclCloth::SetMD6Resolver(MD6Resolver resolver) {
    md6Resolver = resolver;
}

void idDeclCloth::SetFXResolver(FXResolver resolver) {
    fxResolver = resolver;
}

void idDeclCloth::SetJointResolver(JointResolver resolver) {
    jointResolver = resolver;
}

void idDeclCloth::SetRopeChainResolver(RopeChainResolver resolver) {
    ropeChainResolver = resolver;
}

idDeclInfo* idDeclCloth::GetDeclInfo() const {
    return &resourceList;
}

const char* idDeclCloth::DefaultDefinition() const {
    return "{\n\tmaterial\t_default\n\twidth\t\t12\n\theight\t\t12\n"
        "\thspacing\t12\n\tvspacing\t12\n}\n";
}

void idDeclCloth::ResetValues() {
    width = 0;
    height = 0;
    vSpacing = 0.0f;
    hSpacing = 0.0f;
    gravity = -1000.0f;
    mass = 10.0f;
    friction = 0.01f;
    collisionFriction = 0.01f;
    springLength = 1.0f;
    springFriction = 0.01f;
    springMaxLengthMultiplier = 2.0f;
    type = CLOTH_NONE;
    springType = CLOTH_SPRING_BANDED;
    material = nullptr;
    clothMD6 = nullptr;
    clothDeclFX = nullptr;
    md6IsBound = false;
    ropeData.Clear();
    particleData.Clear();
    springData.Clear();
}

void idDeclCloth::FreeData() {
    ropeData.ClearFree();
    particleData.ClearFree();
    springData.ClearFree();
    ResetValues();
}

void idDeclCloth::Parse(idParser* parser) {
    ResetValues();
    if (parser == nullptr) {
        return;
    }

    idTokenStatic<260> token;
    while (parser->ReadToken(token)) {
        if (Key(token, "}")) {
            break;
        }
        if (Key(token, "{")) {
            continue;
        }
        if (Key(token, "width")) {
            width = parser->ParseInt();
        } else if (Key(token, "height")) {
            height = parser->ParseInt();
        } else if (Key(token, "vspacing")) {
            vSpacing = parser->ParseFloat();
        } else if (Key(token, "hspacing")) {
            hSpacing = parser->ParseFloat();
        } else if (Key(token, "springs")) {
            if (!parser->ExpectAnyToken(token)) {
                break;
            }
            if (Key(token, "quad")) {
                springType = CLOTH_SPRING_QUAD;
            } else if (Key(token, "cross")) {
                springType = CLOTH_SPRING_CROSS;
            } else {
                springType = CLOTH_SPRING_BANDED;
            }
        } else if (Key(token, "mass")) {
            mass = parser->ParseFloat();
        } else if (Key(token, "friction")) {
            friction = parser->ParseFloat();
        } else if (Key(token, "collisionfriction")) {
            collisionFriction = parser->ParseFloat();
        } else if (Key(token, "gravity")) {
            gravity = parser->ParseFloat();
        } else if (Key(token, "springLength")) {
            springLength = parser->ParseFloat();
        } else if (Key(token, "springFriction")) {
            springFriction = parser->ParseFloat();
        } else if (Key(token, "springMaxLengthMultiplier")) {
            springMaxLengthMultiplier = parser->ParseFloat();
        } else if (Key(token, "material")) {
            if (!parser->ExpectAnyToken(token)) {
                break;
            }
            material = materialResolver != nullptr
                ? materialResolver(token.c_str(), true) : nullptr;
        } else if (Key(token, "clothDeclFX")) {
            if (!parser->ExpectAnyToken(token)) {
                break;
            }
            clothDeclFX = fxResolver != nullptr
                ? fxResolver(token.c_str(), true) : nullptr;
        } else if (Key(token, "noBind")) {
            md6IsBound = false;
        } else if (Key(token, "generic")) {
            type = CLOTH_GENERIC;
            if (!parser->ExpectTokenString("{") ||
                !parser->ExpectAnyToken(token)) {
                break;
            }
            clothMD6 = md6Resolver != nullptr
                ? md6Resolver(token.c_str(), false) : nullptr;
            const int particleCount = parser->ParseInt();
            if (particleCount < 0 || particleCount > 64 ||
                !particleData.SetNum(particleCount)) {
                parser->Error("Invalid num particles for %s: %d",
                    GetName(), particleCount);
                return;
            }
            for (int index = 0; index < particleCount; ++index) {
                if (!parser->ExpectAnyToken(token)) {
                    return;
                }
                particleInfo_t& particle = particleData[index];
                particle.position.Zero();
                particle.jointIndex.Invalidate();
                particle.forwardIndex = -1;
                particle.rightIndex = -1;
                particle.anchored = false;
                idMat3 inverseAxis(1.0f);
                if (jointResolver != nullptr) {
                    jointResolver(clothMD6, token.c_str(),
                        particle.jointIndex, particle.position, inverseAxis);
                }
                ParseParticleFlags(parser, particle);
            }
            if (!parser->ExpectTokenString("springs") ||
                !parser->ExpectTokenString("{")) {
                return;
            }
            const int springCount = parser->ParseInt();
            if (springCount < 0 || !springData.SetNum(springCount)) {
                parser->Error("Invalid spring count for %s", GetName());
                return;
            }
            for (int index = 0; index < springCount; ++index) {
                const int first = parser->ParseInt();
                const int second = parser->ParseInt();
                if (first < 0 || second < 0 || first >= particleCount ||
                    second >= particleCount || first > 255 || second > 255) {
                    parser->Error("Invalid spring %d in %s", index,
                        GetName());
                    return;
                }
                springData[index].index1 = static_cast<std::uint8_t>(first);
                springData[index].index2 = static_cast<std::uint8_t>(second);
                if (parser->CheckTokenString("{")) {
                    parser->SkipBracedSection(false);
                }
            }
            parser->ExpectTokenString("}");
            parser->ExpectTokenString("}");
        } else if (Key(token, "square")) {
            type = CLOTH_SQUARE;
            if (!parser->ExpectTokenString("{") ||
                !parser->ExpectAnyToken(token)) {
                break;
            }
            clothMD6 = md6Resolver != nullptr
                ? md6Resolver(token.c_str(), false) : nullptr;
            width = parser->ParseInt();
            height = parser->ParseInt();
            if (width < 2 || height < 2 || width > 16 || height > 16 ||
                !particleData.SetNum(width * height)) {
                parser->Error("Invalid cloth dimensions %d x %d",
                    width, height);
                return;
            }
            for (int index = 0; index < particleData.Num(); ++index) {
                if (!parser->ExpectAnyToken(token)) {
                    return;
                }
                particleInfo_t& particle = particleData[index];
                particle.position.Zero();
                particle.jointIndex.Invalidate();
                particle.forwardIndex = -1;
                particle.rightIndex = -1;
                particle.anchored = false;
                idMat3 inverseAxis(1.0f);
                if (jointResolver != nullptr) {
                    jointResolver(clothMD6, token.c_str(),
                        particle.jointIndex, particle.position, inverseAxis);
                }
                ParseParticleFlags(parser, particle);
            }
            parser->ExpectTokenString("}");
        } else if (Key(token, "ropeModel") || Key(token, "rope")) {
            type = CLOTH_ROPE;
            if (!parser->ExpectTokenString("{") ||
                !parser->ExpectAnyToken(token)) {
                break;
            }
            clothMD6 = md6Resolver != nullptr
                ? md6Resolver(token.c_str(), false) : nullptr;
            while (parser->ReadToken(token) && !Key(token, "}")) {
                if (Key(token, "noBind")) {
                    const int count = parser->ParseInt();
                    const float spacing = parser->ParseFloat();
                    if (count < 2 || count > 100) {
                        parser->Error("Invalid rope particle count %d",
                            count);
                        return;
                    }
                    ropeInfo* rope = ropeData.Alloc();
                    if (rope == nullptr) {
                        return;
                    }
                    for (int point = 0; point < count; ++point) {
                        rope->positions.Append(idVec3(0.0f,
                            static_cast<float>(count - point - 1) * spacing,
                            0.0f));
                        rope->inverseAxis.Append(idMat3(1.0f));
                        rope->indexOfJointToAttachTo.Append(
                            idIndex<short, invalidJointIndex_t>());
                    }
                    md6IsBound = false;
                } else {
                    const int count = parser->ParseInt();
                    if (count < 2 || count > 100) {
                        parser->Error("Invalid rope particle count %d",
                            count);
                        return;
                    }
                    ropeInfo* rope = ropeData.Alloc();
                    if (rope == nullptr || ropeChainResolver == nullptr ||
                        !ropeChainResolver(clothMD6, token.c_str(), count,
                            *rope)) {
                        parser->Error("Unable to resolve rope chain %s",
                            token.c_str());
                        return;
                    }
                    md6IsBound = true;
                }
            }
        } else {
            parser->Warning("idDeclCloth::Parse - bad token %s",
                token.c_str());
        }
    }
}
