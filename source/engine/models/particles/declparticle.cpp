#include "models/particles/declparticle.h"

#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"
#include "models/particles/jobs/staticparticlemodeldata.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace {

template<int count>
int NameToType(const char* name, const char* const (&names)[count]) {
    if (name == nullptr || *name == '\0') return -1;
    for (int index = 0; index < count; ++index) {
        if (idStr::Icmp(name, names[index]) == 0) return index;
    }
    return -1;
}

bool Key(const idToken& token, const char* name) {
    return idStr::Icmp(token.c_str(), name) == 0;
}

float TokenFloat(const idToken& token) {
    return std::strtof(token.c_str(), nullptr);
}

int ParseParmsOnLine(idParser* parser, float* parms, const int maxParms) {
    if (parser == nullptr || parms == nullptr || maxParms <= 0) return 0;
    int count = 0;
    idTokenStatic<256> token;
    while (count < maxParms && parser->ReadTokenOnLine(token) != 0) {
        if (idStr::Cmp(token.c_str(), "-") == 0) {
            if (parser->ReadTokenOnLine(token) == 0) break;
            parms[count++] = -TokenFloat(token);
        } else {
            parms[count++] = TokenFloat(token);
        }
    }
    return count;
}

void ParseBounds(idParser* parser, idBounds& bounds) {
    float values[6] = {};
    for (float& value : values) value = parser->ParseFloat();
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(0.0f, values[axis]);
        bounds[1][axis] = (std::max)(0.0f, values[axis + 3]);
    }
}

void WriteBounds(idFile* file, const char* name, const idBounds& bounds) {
    file->WriteFloatString(
        "\t\t%s\t \"%.3f\" \"%.3f\" \"%.3f\" "
        "\"%.3f\" \"%.3f\" \"%.3f\" \n",
        name, bounds[0].x, bounds[0].y, bounds[0].z,
        bounds[1].x, bounds[1].y, bounds[1].z);
}

void FinalizeStage(idParticleStage& stage, const idLookupTable* tables) {
    stage.maxParticleLife = (std::max)(0.0f,
        stage.systemProperties.particleLife.GetMaxParmVal(tables));
    stage.maxDeadTime = (std::max)(0.0f,
        stage.systemProperties.deadTime.GetMaxParmVal(tables));
    stage.cycleMsec = static_cast<int>(
        (stage.maxParticleLife + stage.maxDeadTime) * 1000.0f);
    stage.bunchTime = stage.systemProperties.emissionTime > 0.0f
        ? stage.systemProperties.emissionTime : stage.maxParticleLife;
    stage.orientation.numTrails = static_cast<std::int16_t>((std::max)(0,
        (std::min)(6, static_cast<int>(stage.orientation.numTrails))));
    const int vertsPerParticle = (std::max)(1, stage.NumVertsPerParticle());
    const int maximumParticles = (std::max)(1, 512 / vertsPerParticle);
    stage.systemProperties.totalParticles = static_cast<std::int16_t>(
        (std::max)(0, (std::min)(maximumParticles,
            static_cast<int>(stage.systemProperties.totalParticles))));
    stage.lodParms.totalParticles = static_cast<std::int16_t>(
        (std::max)(1, (std::min)(maximumParticles,
            static_cast<int>(stage.lodParms.totalParticles))));
}

const char* const distributionNames[] = {
    "rect", "cylinder", "sphere", "rect_surface", "cylinder_surface",
    "sphere_surface"
};
const char* const directionNames[] = { "cone", "outward", "speed" };
const char* const orientationNames[] = {
    "view", "trail", "aimed", "x", "y", "z", "xyz"
};
const char* const customNames[] = {
    "standard", "helix", "flies", "orbit", "drip"
};
const char* const textureFlipNames[] = { "none", "random", "always" };
const char* const animationNames[] = {
    "cycle_rate", "single_cycle_rate", "single_cycle"
};
const char* const sortNames[] = {
    "none", "newest_to_oldest", "oldest_to_newest"
};

} // namespace

idDeclParticle::MaterialResolver idDeclParticle::materialResolver = nullptr;
idDeclParticle::MaterialNameResolver idDeclParticle::materialNameResolver =
    nullptr;
idDeclParticle::StaticMeshResolver idDeclParticle::staticMeshResolver =
    nullptr;

idDeclParticle::idDeclParticle()
    : maxSystemDuration(0), lodRadius(0) {
    bounds[0].Set(0.0f, 0.0f, 0.0f);
    bounds[1].Set(0.0f, 0.0f, 0.0f);
}

idDeclParticle::~idDeclParticle() {
    FreeData();
}

void idDeclParticle::SetMaterialResolver(MaterialResolver resolver,
    MaterialNameResolver nameResolver) {
    materialResolver = resolver;
    materialNameResolver = nameResolver;
}

void idDeclParticle::SetStaticMeshResolver(StaticMeshResolver resolver) {
    staticMeshResolver = resolver;
}

const char* idDeclParticle::DefaultDefinition() const {
    return "{\n"
        "\t{\n"
        "\t\tmaterial\ttextures/particles/default\n"
        "\t\tcount\t\t5\n"
        "\t\ttime\t\tconstant 1.0\n"
        "\t\tspeedZ\t\tparametricIntegrate \"150.000\"\n"
        "\t}\n"
        "}\n";
}

void idDeclParticle::FreeData() {
    for (int index = 0; index < stages.Num(); ++index) {
        delete stages[index];
    }
    stages.ClearFree();
    stageNames.ClearFree();
    stageInheritNames.ClearFree();
    tableDecls.ClearFree();
    tables.ClearFree();
    maxSystemDuration = 0;
    lodRadius = 0;
    bounds[0].Set(0.0f, 0.0f, 0.0f);
    bounds[1].Set(0.0f, 0.0f, 0.0f);
}

unsigned int idDeclParticle::Size() const {
    unsigned int total = static_cast<unsigned int>(sizeof(*this));
    total += static_cast<unsigned int>(
        stages.NumAllocated() * sizeof(idParticleStage*));
    total += static_cast<unsigned int>(
        stageNames.NumAllocated() * sizeof(idAtomicString));
    total += static_cast<unsigned int>(
        stageInheritNames.NumAllocated() * sizeof(idAtomicString));
    total += static_cast<unsigned int>(
        tableDecls.NumAllocated() * sizeof(const idDeclTable*));
    total += static_cast<unsigned int>(
        tables.NumAllocated() * sizeof(idLookupTable));
    for (int index = 0; index < stages.Num(); ++index) {
        if (stages[index] != nullptr) {
            total += sizeof(idParticleStage);
        }
    }
    return total;
}

idParticleStage* idDeclParticle::CreateNewStage() {
    return new idParticleStage();
}

idParticleStage* idDeclParticle::FindStageByName(const char* stageName) {
    return const_cast<idParticleStage*>(
        static_cast<const idDeclParticle*>(this)->FindStageByName(stageName));
}

const idParticleStage* idDeclParticle::FindStageByName(
    const char* stageName) const {
    if (stageName == nullptr || *stageName == '\0') return nullptr;
    const int count = (std::min)(stages.Num(), stageNames.Num());
    for (int index = 0; index < count; ++index) {
        if (idStr::Icmp(stageNames[index].c_str(), stageName) == 0) {
            return stages[index];
        }
    }
    return nullptr;
}

int idDeclParticle::CalcLodForDistance(const float distanceSquared) const {
    if (lodRadius <= 0) return 0;
    const float radiusSquared = static_cast<float>(lodRadius * lodRadius);
    int distanceBand = static_cast<int>(distanceSquared / radiusSquared);
    distanceBand = (std::max)(0, (std::min)(3, distanceBand));
    return 3 - distanceBand;
}

const idLookupTable* idDeclParticle::GetTables() const {
    return tables.Ptr();
}

void idDeclParticle::UpdateBounds() {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    for (int index = 0; index < stages.Num(); ++index) {
        idParticleStage* stage = stages[index];
        if (stage == nullptr) continue;
        stage->CalculateBounds(GetTables());
        for (int axis = 0; axis < 3; ++axis) {
            bounds[0][axis] = (std::min)(bounds[0][axis],
                stage->bounds[0][axis]);
            bounds[1][axis] = (std::max)(bounds[1][axis],
                stage->bounds[1][axis]);
        }
    }
    const idVec3 size = bounds[1] - bounds[0];
    if (bounds[0].x >= bounds[1].x || bounds[0].y >= bounds[1].y
        || bounds[0].z >= bounds[1].z
        || size.x * size.y * size.z <= 0.1f) {
        bounds[0].Set(-8.0f, -8.0f, -8.0f);
        bounds[1].Set(8.0f, 8.0f, 8.0f);
    }
}

void idDeclParticle::UpdateMaxSystemDuration() {
    maxSystemDuration = 0;
    for (int index = 0; index < stages.Num(); ++index) {
        const idParticleStage* stage = stages[index];
        if (stage == nullptr) continue;
        const int duration = static_cast<int>(
            stage->systemProperties.timeOffset * 1000.0f)
            + stage->cycleMsec;
        maxSystemDuration = (std::max)(maxSystemDuration, duration);
    }
}

idParticleStage* idDeclParticle::ParseParticleStage(idParser* parser,
    const char* stageName, idStr& inheritFrom) {
    if (parser == nullptr) return nullptr;
    idParticleStage* stage = CreateNewStage();
    if (stage == nullptr) return nullptr;
    stage->Default(GetTables());
    inheritFrom.Clear();

    idTokenStatic<256> token;
    int parsedProperties = 0;
    auto parseParm = [&](idParticleParm& parm) {
        ParseParticleParm(parser, &parm, tableDecls, tables);
    };
    auto readEnum = [&](int (*converter)(const char*)) -> int {
        if (!parser->ReadToken(token)) return -1;
        return converter(token.c_str());
    };

    while (parser->ReadToken(token)) {
        if (Key(token, "}")) break;

        if (Key(token, "inherit")) {
            if (parsedProperties != 0) {
                parser->Error("Particle '%s' stage '%s': inherit must come "
                    "before all other properties", GetName(), stageName);
                delete stage;
                return nullptr;
            }
            if (!parser->ReadToken(token)) {
                parser->Error("Particle stage inherit has no stage name");
                delete stage;
                return nullptr;
            }
            const idParticleStage* parent = FindStageByName(token.c_str());
            if (parent == nullptr) {
                parser->Error("Particle '%s': invalid inherited stage '%s'",
                    GetName(), token.c_str());
                delete stage;
                return nullptr;
            }
            *stage = *parent;
            inheritFrom = token.c_str();
            continue;
        }
        ++parsedProperties;

        if (Key(token, "bounds")) {
            ParseBounds(parser, stage->bounds);
        } else if (Key(token, "material")) {
            if (parser->ReadToken(token)) {
                stage->SetMaterial(materialResolver != nullptr
                    ? materialResolver(token.c_str()) : nullptr);
            }
        } else if (Key(token, "staticMesh")) {
            if (parser->ReadToken(token)) {
                const idStaticParticleModelData* staticMesh =
                    staticMeshResolver != nullptr
                    ? staticMeshResolver(token.c_str())
                    : static_cast<const idStaticParticleModelData*>(
                        idStaticParticleModelData::resourceList.Load(
                            token.c_str(), true));
                stage->SetStaticMesh(staticMesh);
            }
        } else if (Key(token, "count")) {
            stage->systemProperties.totalParticles =
                static_cast<std::int16_t>(parser->ParseInt());
        } else if (Key(token, "time")) {
            parseParm(stage->systemProperties.particleLife);
        } else if (Key(token, "cycles")) {
            stage->systemProperties.cycles =
                static_cast<std::int16_t>(parser->ParseInt());
        } else if (Key(token, "timeOffset")) {
            stage->systemProperties.timeOffset = parser->ParseFloat();
        } else if (Key(token, "diversity")) {
            stage->systemProperties.diversity = parser->ParseInt() & 0x7FFF;
        } else if (Key(token, "useSysTime")) {
            stage->systemProperties.useSysTime = parser->ParseFloat();
        } else if (Key(token, "emissionTime")) {
            stage->systemProperties.emissionTime = parser->ParseFloat();
        } else if (Key(token, "deadTime")) {
            parseParm(stage->systemProperties.deadTime);
        } else if (Key(token, "randomDistribution")) {
            stage->distribution.random = parser->ParseBool();
        } else if (Key(token, "bunching")) {
            stage->systemProperties.spawnBunching = parser->ParseFloat();
        } else if (Key(token, "distributionType")) {
            const int type = readEnum(ParticleDistributionNameToType);
            if (type < 0) parser->Error("bad distribution type: %s",
                token.c_str());
            else stage->distribution.type =
                static_cast<prtDistributionType_t>(type);
        } else if (Key(token, "distribSizeX")) {
            parseParm(stage->distribution.size[0]);
        } else if (Key(token, "distribSizeY")) {
            parseParm(stage->distribution.size[1]);
        } else if (Key(token, "distribSizeZ")) {
            parseParm(stage->distribution.size[2]);
        } else if (Key(token, "direction") || Key(token, "frictionTime")) {
            if (parser->CheckTokenString("{") != 0) {
                while (parser->ReadToken(token) && !Key(token, "}")) {
                    if (Key(token, "type")) {
                        const int type = readEnum(ParticleDirectionNameToType);
                        if (type < 0) parser->Error("bad direction type: %s",
                            token.c_str());
                        else stage->direction.type =
                            static_cast<prtDirectionType_t>(type);
                    } else if (Key(token, "parms")) {
                        ParseParmsOnLine(parser, stage->direction.parms, 4);
                    } else if (Key(token, "angleOffsetStart")) {
                        ParseParmsOnLine(parser,
                            stage->direction.angleOffsetStart, 2);
                    } else if (Key(token, "angleOffsetRange")) {
                        ParseParmsOnLine(parser,
                            stage->direction.angleOffsetRange, 2);
                    } else {
                        parser->Warning("unknown direction token %s",
                            token.c_str());
                        parser->SkipRestOfLine();
                    }
                }
            } else {
                const int type = readEnum(ParticleDirectionNameToType);
                if (type < 0) parser->Error("bad direction type: %s",
                    token.c_str());
                else stage->direction.type =
                    static_cast<prtDirectionType_t>(type);
                ParseParmsOnLine(parser, stage->direction.parms, 4);
            }
            stage->direction.coneAxis = idAngles(stage->direction.parms[1],
                stage->direction.parms[2], stage->direction.parms[3]).ToMat3();
        } else if (Key(token, "orientation")) {
            if (parser->CheckTokenString("{") != 0) {
                while (parser->ReadToken(token) && !Key(token, "}")) {
                    if (Key(token, "type")) {
                        const int type = readEnum(ParticleOrientationNameToType);
                        if (type < 0) parser->Error("bad orientation type: %s",
                            token.c_str());
                        else stage->orientation.type =
                            static_cast<prtOrientationType_t>(type);
                    } else if (Key(token, "world")) {
                        stage->orientation.world = parser->ParseBool();
                    } else if (Key(token, "viewFade")) {
                        stage->orientation.viewFade = parser->ParseFloat();
                    } else if (Key(token, "segmentLength")) {
                        stage->orientation.segmentLength = parser->ParseFloat();
                    } else if (Key(token, "numTrails")) {
                        stage->orientation.numTrails =
                            static_cast<std::int16_t>(parser->ParseInt());
                    } else if (Key(token, "aimedSafeQuad")) {
                        stage->orientation.aimedSafeQuad = parser->ParseBool();
                    } else if (Key(token, "aimedSafeQuadAlign")) {
                        stage->orientation.aimedSafeQuadAlign =
                            parser->ParseFloat();
                    } else if (Key(token, "orientToVelOnly")) {
                        stage->orientation.orientToVelOnly = parser->ParseBool();
                    } else if (Key(token, "depthOffset")) {
                        stage->orientation.depthOffset = parser->ParseFloat();
                    } else {
                        parser->Warning("unknown orientation token %s",
                            token.c_str());
                        parser->SkipRestOfLine();
                    }
                }
            } else {
                if (!parser->ReadToken(token)) break;
                if (Key(token, "world")) {
                    stage->orientation.world = true;
                    if (!parser->ReadToken(token)) break;
                }
                const int type = ParticleOrientationNameToType(token.c_str());
                if (type < 0) parser->Error("bad orientation type: %s",
                    token.c_str());
                else stage->orientation.type =
                    static_cast<prtOrientationType_t>(type);
                if (stage->orientation.type == POR_TRAIL) {
                    stage->orientation.numTrails =
                        static_cast<std::int16_t>(parser->ParseInt());
                    stage->orientation.segmentLength = parser->ParseFloat();
                } else if (stage->orientation.type == POR_AIMED) {
                    stage->orientation.segmentLength = parser->ParseFloat();
                    idTokenStatic<256> option;
                    if (parser->ReadTokenOnLine(option) != 0) {
                        stage->orientation.orientToVelOnly =
                            std::atoi(option.c_str()) != 0;
                    }
                    if (parser->ReadTokenOnLine(option) != 0) {
                        stage->orientation.viewFade = TokenFloat(option);
                    }
                }
            }
        } else if (Key(token, "customPathType")) {
            const int type = readEnum(ParticleCustomNameToType);
            if (type < 0) parser->Error("bad custom path type: %s",
                token.c_str());
            else stage->customPath.type = static_cast<prtCustomPthType_t>(type);
        } else if (Key(token, "customPathParm0")) {
            parseParm(stage->customPath.parms[0]);
        } else if (Key(token, "customPathParm1")) {
            parseParm(stage->customPath.parms[1]);
        } else if (Key(token, "customPathParm2")) {
            parseParm(stage->customPath.parms[2]);
        } else if (Key(token, "customPathParm3")) {
            parseParm(stage->customPath.parms[3]);
        } else if (Key(token, "customPathParm4")) {
            parseParm(stage->customPath.parms[4]);
        } else if (Key(token, "speedX")) {
            parseParm(stage->speed.speed[0]);
        } else if (Key(token, "speedY")) {
            parseParm(stage->speed.speed[1]);
        } else if (Key(token, "speedZ")) {
            parseParm(stage->speed.speed[2]);
        } else if (Key(token, "worldAcceleration")) {
            stage->acceleration.world = parser->ParseBool();
        } else if (Key(token, "accelerationX")) {
            parseParm(stage->acceleration.acceleration[0]);
        } else if (Key(token, "accelerationY")) {
            parseParm(stage->acceleration.acceleration[1]);
        } else if (Key(token, "accelerationZ")) {
            parseParm(stage->acceleration.acceleration[2]);
        } else if (Key(token, "frictionX")) {
            parseParm(stage->friction.friction[0]);
        } else if (Key(token, "frictionY")) {
            parseParm(stage->friction.friction[1]);
        } else if (Key(token, "frictionZ")) {
            parseParm(stage->friction.friction[2]);
        } else if (Key(token, "rotationSpeedX")) {
            parseParm(stage->rotation.rotation[0]);
        } else if (Key(token, "rotationSpeedY")) {
            parseParm(stage->rotation.rotation[1]);
        } else if (Key(token, "rotationSpeedZ")) {
            parseParm(stage->rotation.rotation[2]);
        } else if (Key(token, "angleX")) {
            parseParm(stage->initialRotation.initialAngle[0]);
        } else if (Key(token, "angleY")) {
            parseParm(stage->initialRotation.initialAngle[1]);
        } else if (Key(token, "angleZ")) {
            parseParm(stage->initialRotation.initialAngle[2]);
        } else if (Key(token, "spawnLocX")) {
            parseParm(stage->spawnLocation.spawnLocation[0]);
        } else if (Key(token, "spawnLocY")) {
            parseParm(stage->spawnLocation.spawnLocation[1]);
        } else if (Key(token, "spawnLocZ")) {
            parseParm(stage->spawnLocation.spawnLocation[2]);
        } else if (Key(token, "pivotX")) {
            stage->pivot.pivotOffset.x = parser->ParseFloat();
        } else if (Key(token, "pivotY")) {
            stage->pivot.pivotOffset.y = parser->ParseFloat();
        } else if (Key(token, "sizeX")) {
            parseParm(stage->size.size[0]);
        } else if (Key(token, "sizeY")) {
            parseParm(stage->size.size[1]);
        } else if (Key(token, "sizeZ")) {
            parseParm(stage->size.size[2]);
        } else if (Key(token, "aspect")) {
            parseParm(stage->size.aspectRatio);
        } else if (Key(token, "fadeIn")) {
            stage->colorAttributes.fadeInFraction = parser->ParseFloat();
        } else if (Key(token, "fadeOut")) {
            stage->colorAttributes.fadeOutFraction = parser->ParseFloat();
        } else if (Key(token, "fadeIndex")) {
            stage->colorAttributes.fadeIndexFraction = parser->ParseFloat();
        } else if (Key(token, "softParticleAlphaScale")) {
            const float scale = parser->ParseFloat();
            stage->colorAttributes.softParticleAlphaScale =
                1.0f / (std::max)(1.0f, scale);
        } else if (Key(token, "minShadowVal")) {
            stage->colorAttributes.minShadowVal = parser->ParseFloat();
        } else if (Key(token, "entityColorBlendVal")) {
            stage->colorAttributes.entityColorBlendVal = parser->ParseFloat();
        } else if (Key(token, "brightness")) {
            parseParm(stage->colorAttributes.brightness);
        } else if (Key(token, "genericParmR")) {
            parseParm(stage->genericParm.genericParm[0]);
        } else if (Key(token, "genericParmG")) {
            parseParm(stage->genericParm.genericParm[1]);
        } else if (Key(token, "genericParmB")) {
            parseParm(stage->genericParm.genericParm[2]);
        } else if (Key(token, "genericParmA")) {
            parseParm(stage->genericParm.genericParm[3]);
        } else if (Key(token, "useGlobalShadows")) {
            stage->colorAttributes.useGlobalShadows = parser->ParseBool();
        } else if (Key(token, "colorR")) {
            parseParm(stage->colorAttributes.baseColor[0]);
        } else if (Key(token, "colorG")) {
            parseParm(stage->colorAttributes.baseColor[1]);
        } else if (Key(token, "colorB")) {
            parseParm(stage->colorAttributes.baseColor[2]);
        } else if (Key(token, "colorA")) {
            parseParm(stage->colorAttributes.baseColor[3]);
        } else if (Key(token, "fadeColor")) {
            stage->colorAttributes.fadeColor.x = parser->ParseFloat();
            stage->colorAttributes.fadeColor.y = parser->ParseFloat();
            stage->colorAttributes.fadeColor.z = parser->ParseFloat();
            stage->colorAttributes.fadeColor.w = parser->ParseFloat();
        } else if (Key(token, "offsetX")) {
            parseParm(stage->offset.offset[0]);
        } else if (Key(token, "offsetY")) {
            parseParm(stage->offset.offset[1]);
        } else if (Key(token, "offsetZ")) {
            parseParm(stage->offset.offset[2]);
        } else if (Key(token, "animationFrames")) {
            stage->texAnimation.numColumns = static_cast<std::uint16_t>(
                (std::max)(1, (std::min)(64, parser->ParseInt())));
        } else if (Key(token, "animationRows")) {
            stage->texAnimation.numRows = static_cast<std::uint16_t>(
                (std::max)(1, (std::min)(4, parser->ParseInt())));
        } else if (Key(token, "animationRate")) {
            parseParm(stage->texAnimation.rate);
        } else if (Key(token, "useRndStartFrame")) {
            if (parser->ParseBool()) stage->texAnimation.startFrame = -1;
        } else if (Key(token, "animationStartFrame")) {
            stage->texAnimation.startFrame =
                static_cast<std::int16_t>(parser->ParseInt());
        } else if (Key(token, "useRndAnimRow")) {
            stage->texAnimation.useRandomRow = parser->ParseBool();
        } else if (Key(token, "animationType")) {
            const int type = readEnum(ParticleAnimationNameToType);
            if (type < 0) parser->Error("bad animation type: %s",
                token.c_str());
            else stage->texAnimation.type =
                static_cast<prtAnimationType_t>(type);
        } else if (Key(token, "skipAnimCrossFade")) {
            stage->texAnimation.useFrameBlending = !parser->ParseBool();
        } else if (Key(token, "rndFlipTexS")) {
            const int type = readEnum(ParticleTextureFlipNameToType);
            if (type < 0) parser->Error("bad texture flip type: %s",
                token.c_str());
            else stage->systemProperties.textureFlipS =
                static_cast<prtTextureFlipMode_t>(type);
        } else if (Key(token, "rndFlipTexT")) {
            const int type = readEnum(ParticleTextureFlipNameToType);
            if (type < 0) parser->Error("bad texture flip type: %s",
                token.c_str());
            else stage->systemProperties.textureFlipT =
                static_cast<prtTextureFlipMode_t>(type);
        } else if (Key(token, "allowRotDirOverride")) {
            stage->rotation.allowRotDirOverride = parser->ParseBool();
        } else if (Key(token, "boundsExpansion")) {
            stage->systemProperties.boundsExpansion = parser->ParseFloat();
        } else if (Key(token, "randomOnCycle")) {
            stage->systemProperties.randomOnCycle = parser->ParseBool();
        } else if (Key(token, "gravity")) {
            if (parser->ReadToken(token)) {
                if (Key(token, "world")) stage->gravity.world = true;
                else parser->UnreadToken(token);
            }
            parseParm(stage->gravity.gravity);
        } else if (Key(token, "windBias")) {
            parseParm(stage->systemProperties.windBias);
        } else if (Key(token, "sortType")) {
            const int type = readEnum(ParticleSortNameToType);
            if (type < 0) parser->Error("bad sort type: %s", token.c_str());
            else stage->systemProperties.sortType =
                static_cast<prtSortType_t>(type);
        } else if (Key(token, "lodCount")) {
            stage->lodParms.totalParticles = static_cast<std::int16_t>(
                (std::max)(1, parser->ParseInt()));
        } else if (Key(token, "lodScale")) {
            stage->lodParms.sizeScale = parser->ParseFloat();
        } else if (Key(token, "lodLerpAmount")) {
            stage->lodParms.lerpAmount = parser->ParseFloat();
        } else if (Key(token, "lodRadius")) {
            stage->lodParms.radius =
                static_cast<std::int16_t>(parser->ParseInt());
        } else {
            parser->Warning("Particle '%s' stage '%s': unknown token %s",
                GetName(), stageName != nullptr ? stageName : "",
                token.c_str());
            parser->SkipRestOfLine();
        }
    }

    FinalizeStage(*stage, GetTables());
    return stage;
}

void idDeclParticle::Parse(idParser* parser) {
    FreeData();
    if (parser == nullptr) return;

    idTokenStatic<256> token;
    if (!parser->ReadToken(token)) return;
    if (Key(token, "{")) {
        if (!parser->ReadToken(token)) return;
    }

    while (!Key(token, "}")) {
        if (Key(token, "bounds")) {
            ParseBounds(parser, bounds);
        } else {
            idStr stageName(token.c_str());
            if (Key(token, "{")) stageName.Clear();
            else if (!parser->ExpectTokenString("{")) break;

            idStr inheritedName;
            idParticleStage* stage = ParseParticleStage(parser,
                stageName.c_str(), inheritedName);
            if (stage == nullptr) break;
            if (stages.Append(stage) < 0) {
                delete stage;
                break;
            }
            stageNames.Append(idAtomicString(stageName.c_str()));
            stageInheritNames.Append(idAtomicString(inheritedName.c_str()));
        }
        if (!parser->ReadToken(token)) break;
    }

    UpdateBounds();
    UpdateMaxSystemDuration();
    lodRadius = 0;
    for (int index = 0; index < stages.Num(); ++index) {
        lodRadius = (std::max)(lodRadius,
            static_cast<int>(stages[index]->lodParms.radius));
    }
}

void idDeclParticle::WriteStage(idFile* file,
    const idParticleStage& stage, const char* stageName,
    const idParticleStage&, const char* parentName) const {
    if (file == nullptr) return;
    file->WriteFloatString("\t\"%s\" {\n\n",
        stageName != nullptr ? stageName : "");
    if (parentName != nullptr && *parentName != '\0') {
        file->WriteFloatString("\t\t%-25s\t\"%s\"\n", "inherit",
            parentName);
    }
    WriteBounds(file, "bounds", stage.bounds);

    if (stage.systemProperties.material != nullptr
            && materialNameResolver != nullptr) {
        const char* materialName = materialNameResolver(
            stage.systemProperties.material);
        if (materialName != nullptr && *materialName != '\0') {
            file->WriteFloatString("\t\t%-25s\t%s\n", "material",
                materialName);
        }
    }
    if (stage.staticData != nullptr) {
        file->WriteFloatString("\t\t%-25s\t%s\n", "staticMesh",
            stage.staticData->GetName());
    }

    const idStr emptyInfo;
    const idStr forceWrite("write");
    idParticleParm unusedDefault;
    unusedDefault.Clear();
    auto writeParm = [&](const char* name, const idParticleParm& parm) {
        WriteParticleParm(file, name, parm, unusedDefault, tableDecls,
            emptyInfo, forceWrite);
    };

    file->WriteFloatString("\t\t%-25s\t%i\n", "count",
        stage.systemProperties.totalParticles);
    writeParm("time", stage.systemProperties.particleLife);
    file->WriteFloatString("\t\t%-25s\t%i\n", "cycles",
        stage.systemProperties.cycles);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "bunching",
        stage.systemProperties.spawnBunching);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "timeOffset",
        stage.systemProperties.timeOffset);
    file->WriteFloatString("\t\t%-25s\t%i\n", "diversity",
        stage.systemProperties.diversity);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "useSysTime",
        stage.systemProperties.useSysTime);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "emissionTime",
        stage.systemProperties.emissionTime);
    writeParm("deadTime", stage.systemProperties.deadTime);
    file->WriteFloatString("\t\t%-25s\t%i\n", "randomDistribution",
        stage.distribution.random ? 1 : 0);
    file->WriteFloatString("\t\t%-25s\t%s\n", "distributionType",
        distributionNames[(std::max)(0, (std::min)(
            NUM_PDIST_TYPES - 1, static_cast<int>(stage.distribution.type)))]);
    writeParm("distribSizeX", stage.distribution.size[0]);
    writeParm("distribSizeY", stage.distribution.size[1]);
    writeParm("distribSizeZ", stage.distribution.size[2]);

    file->WriteFloatString("\t\tdirection {\n");
    file->WriteFloatString("\t\t\ttype %s\n", directionNames[
        (std::max)(0, (std::min)(NUM_PDIR_TYPES - 1,
            static_cast<int>(stage.direction.type)))]);
    file->WriteFloatString("\t\t\tparms %.3f %.3f %.3f %.3f\n",
        stage.direction.parms[0], stage.direction.parms[1],
        stage.direction.parms[2], stage.direction.parms[3]);
    file->WriteFloatString("\t\t\tangleOffsetStart %.3f %.3f\n",
        stage.direction.angleOffsetStart[0],
        stage.direction.angleOffsetStart[1]);
    file->WriteFloatString("\t\t\tangleOffsetRange %.3f %.3f\n",
        stage.direction.angleOffsetRange[0],
        stage.direction.angleOffsetRange[1]);
    file->WriteFloatString("\t\t}\n");

    file->WriteFloatString("\t\torientation {\n");
    file->WriteFloatString("\t\t\ttype %s\n", orientationNames[
        (std::max)(0, (std::min)(NUM_POR_TYPES - 1,
            static_cast<int>(stage.orientation.type)))]);
    file->WriteFloatString("\t\t\tworld %i\n",
        stage.orientation.world ? 1 : 0);
    file->WriteFloatString("\t\t\tnumTrails %i\n",
        stage.orientation.numTrails);
    file->WriteFloatString("\t\t\tsegmentLength %.3f\n",
        stage.orientation.segmentLength);
    file->WriteFloatString("\t\t\tviewFade %.3f\n",
        stage.orientation.viewFade);
    file->WriteFloatString("\t\t\torientToVelOnly %i\n",
        stage.orientation.orientToVelOnly ? 1 : 0);
    file->WriteFloatString("\t\t\taimedSafeQuad %i\n",
        stage.orientation.aimedSafeQuad ? 1 : 0);
    file->WriteFloatString("\t\t\taimedSafeQuadAlign %.3f\n",
        stage.orientation.aimedSafeQuadAlign);
    file->WriteFloatString("\t\t\tdepthOffset %.3f\n",
        stage.orientation.depthOffset);
    file->WriteFloatString("\t\t}\n");

    file->WriteFloatString("\t\t%-25s\t%s\n", "customPathType",
        customNames[(std::max)(0, (std::min)(NUM_PCUSTOM_TYPES - 1,
            static_cast<int>(stage.customPath.type)))]);
    for (int index = 0; index < 5; ++index) {
        char name[32];
        _snprintf_s(name, sizeof(name), _TRUNCATE, "customPathParm%d", index);
        writeParm(name, stage.customPath.parms[index]);
    }
    writeParm("speedX", stage.speed.speed[0]);
    writeParm("speedY", stage.speed.speed[1]);
    writeParm("speedZ", stage.speed.speed[2]);
    file->WriteFloatString("\t\t%-25s\t%i\n", "worldAcceleration",
        stage.acceleration.world ? 1 : 0);
    writeParm("accelerationX", stage.acceleration.acceleration[0]);
    writeParm("accelerationY", stage.acceleration.acceleration[1]);
    writeParm("accelerationZ", stage.acceleration.acceleration[2]);
    writeParm("frictionX", stage.friction.friction[0]);
    writeParm("frictionY", stage.friction.friction[1]);
    writeParm("frictionZ", stage.friction.friction[2]);
    writeParm("rotationSpeedX", stage.rotation.rotation[0]);
    writeParm("rotationSpeedY", stage.rotation.rotation[1]);
    writeParm("rotationSpeedZ", stage.rotation.rotation[2]);
    writeParm("angleX", stage.initialRotation.initialAngle[0]);
    writeParm("angleY", stage.initialRotation.initialAngle[1]);
    writeParm("angleZ", stage.initialRotation.initialAngle[2]);
    writeParm("spawnLocX", stage.spawnLocation.spawnLocation[0]);
    writeParm("spawnLocY", stage.spawnLocation.spawnLocation[1]);
    writeParm("spawnLocZ", stage.spawnLocation.spawnLocation[2]);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "pivotX",
        stage.pivot.pivotOffset.x);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "pivotY",
        stage.pivot.pivotOffset.y);
    writeParm("sizeX", stage.size.size[0]);
    writeParm("sizeY", stage.size.size[1]);
    writeParm("sizeZ", stage.size.size[2]);
    writeParm("aspect", stage.size.aspectRatio);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "fadeIn",
        stage.colorAttributes.fadeInFraction);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "fadeOut",
        stage.colorAttributes.fadeOutFraction);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "fadeIndex",
        stage.colorAttributes.fadeIndexFraction);
    file->WriteFloatString(
        "\t\t%-25s\t%.3f %.3f %.3f %.3f\n", "fadeColor",
        stage.colorAttributes.fadeColor.x, stage.colorAttributes.fadeColor.y,
        stage.colorAttributes.fadeColor.z, stage.colorAttributes.fadeColor.w);
    writeParm("colorR", stage.colorAttributes.baseColor[0]);
    writeParm("colorG", stage.colorAttributes.baseColor[1]);
    writeParm("colorB", stage.colorAttributes.baseColor[2]);
    writeParm("colorA", stage.colorAttributes.baseColor[3]);
    writeParm("brightness", stage.colorAttributes.brightness);
    writeParm("genericParmR", stage.genericParm.genericParm[0]);
    writeParm("genericParmG", stage.genericParm.genericParm[1]);
    writeParm("genericParmB", stage.genericParm.genericParm[2]);
    writeParm("genericParmA", stage.genericParm.genericParm[3]);
    const float softScale = stage.colorAttributes.softParticleAlphaScale > 0.0f
        ? 1.0f / stage.colorAttributes.softParticleAlphaScale : 1.0f;
    file->WriteFloatString("\t\t%-25s\t%.3f\n",
        "softParticleAlphaScale", softScale);
    file->WriteFloatString("\t\t%-25s\t%i\n", "useGlobalShadows",
        stage.colorAttributes.useGlobalShadows ? 1 : 0);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "minShadowVal",
        stage.colorAttributes.minShadowVal);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "entityColorBlendVal",
        stage.colorAttributes.entityColorBlendVal);

    file->WriteFloatString("\t\t%-25s\t%i\n", "animationFrames",
        stage.texAnimation.numColumns);
    file->WriteFloatString("\t\t%-25s\t%i\n", "animationRows",
        stage.texAnimation.numRows);
    writeParm("animationRate", stage.texAnimation.rate);
    if (stage.texAnimation.startFrame < 0) {
        file->WriteFloatString("\t\t%-25s\t1\n", "useRndStartFrame");
    } else {
        file->WriteFloatString("\t\t%-25s\t%i\n", "animationStartFrame",
            stage.texAnimation.startFrame);
    }
    file->WriteFloatString("\t\t%-25s\t%i\n", "useRndAnimRow",
        stage.texAnimation.useRandomRow ? 1 : 0);
    file->WriteFloatString("\t\t%-25s\t%s\n", "animationType",
        animationNames[(std::max)(0, (std::min)(NUM_PANIM_TYPES - 1,
            static_cast<int>(stage.texAnimation.type)))]);
    file->WriteFloatString("\t\t%-25s\t%i\n", "skipAnimCrossFade",
        stage.texAnimation.useFrameBlending ? 0 : 1);
    file->WriteFloatString("\t\t%-25s\t%s\n", "rndFlipTexS",
        textureFlipNames[(std::max)(0, (std::min)(
            NUM_PTEXTURE_FLIP_TYPES - 1,
            static_cast<int>(stage.systemProperties.textureFlipS)))]);
    file->WriteFloatString("\t\t%-25s\t%s\n", "rndFlipTexT",
        textureFlipNames[(std::max)(0, (std::min)(
            NUM_PTEXTURE_FLIP_TYPES - 1,
            static_cast<int>(stage.systemProperties.textureFlipT)))]);
    file->WriteFloatString("\t\t%-25s\t%i\n", "allowRotDirOverride",
        stage.rotation.allowRotDirOverride ? 1 : 0);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "boundsExpansion",
        stage.systemProperties.boundsExpansion);
    file->WriteFloatString("\t\t%-25s\t%i\n", "randomOnCycle",
        stage.systemProperties.randomOnCycle ? 1 : 0);
    const idStr gravityInfo(stage.gravity.world ? "world" : "");
    WriteParticleParm(file, "gravity", stage.gravity.gravity, unusedDefault,
        tableDecls, gravityInfo, forceWrite);
    writeParm("windBias", stage.systemProperties.windBias);
    file->WriteFloatString("\t\t%-25s\t%s\n", "sortType",
        sortNames[(std::max)(0, (std::min)(NUM_PSORT_TYPES - 1,
            static_cast<int>(stage.systemProperties.sortType)))]);
    file->WriteFloatString("\t\t%-25s\t%i\n", "lodCount",
        stage.lodParms.totalParticles);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "lodScale",
        stage.lodParms.sizeScale);
    file->WriteFloatString("\t\t%-25s\t%.3f\n", "lodLerpAmount",
        stage.lodParms.lerpAmount);
    file->WriteFloatString("\t\t%-25s\t%i\n", "lodRadius",
        stage.lodParms.radius);
    file->WriteFloatString("\n\t}\n");
}

bool idDeclParticle::RebuildTextSource() {
    idFile_Memory file;
    file.WriteFloatString("{\n");
    WriteBounds(&file, "bounds", bounds);

    idParticleStage defaultStage;
    defaultStage.Default(GetTables());
    for (int index = 0; index < stages.Num(); ++index) {
        const char* name = index < stageNames.Num()
            ? stageNames[index].c_str() : "";
        char generatedName[32];
        if (name == nullptr || *name == '\0') {
            _snprintf_s(generatedName, sizeof(generatedName), _TRUNCATE,
                "stage%d", index);
            name = generatedName;
        }
        const char* inheritedName = index < stageInheritNames.Num()
            ? stageInheritNames[index].c_str() : "";
        const idParticleStage* parent = FindStageByName(inheritedName);
        WriteStage(&file, *stages[index], name,
            parent != nullptr ? *parent : defaultStage, inheritedName);
    }
    file.WriteFloatString("}\n");
    SetText(file.GetDataPtr(), static_cast<int>(file.Length()));
    return true;
}

void idDeclParticle::LogMissingDecl() const {
    idDecl::LogMissingDecl();
}

int ParticleDistributionNameToType(const char* name) {
    int type = NameToType(name, distributionNames);
    if (type >= 0) return type;
    static const char* const legacy[] = { "rect", "cylinder", "sphere",
        "rectSurface", "cylinderSurface", "sphereSurface" };
    return NameToType(name, legacy);
}

int ParticleDirectionNameToType(const char* name) {
    return NameToType(name, directionNames);
}

int ParticleOrientationNameToType(const char* name) {
    return NameToType(name, orientationNames);
}

int ParticleCustomNameToType(const char* name) {
    return NameToType(name, customNames);
}

int ParticleTextureFlipNameToType(const char* name) {
    return NameToType(name, textureFlipNames);
}

int ParticleAnimationNameToType(const char* name) {
    int type = NameToType(name, animationNames);
    if (type >= 0) return type;
    static const char* const legacy[] = {
        "cycleRate", "singleCycleRate", "singleCycle"
    };
    return NameToType(name, legacy);
}

int ParticleSortNameToType(const char* name) {
    int type = NameToType(name, sortNames);
    if (type >= 0) return type;
    static const char* const legacy[] = {
        "none", "newestToOldest", "oldestToNewest"
    };
    return NameToType(name, legacy);
}
