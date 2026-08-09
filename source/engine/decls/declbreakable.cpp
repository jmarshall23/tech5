#include "decls/declbreakable.h"

#include "idlib/text/lexer.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

const idDeclParticle* Decls_FindParticle(const char* name);
const idDeclFX* Decls_FindFX(const char* name);
const idMaterial* Decls_FindMaterial(const char* name);
int Decls_LoadBreakableModelPieceCount(const char* modelName);
void Decls_GenerateBreakableDecalInfo(const idDeclBreakable* declaration,
    const char* decalModelName);

namespace {

template<int tag>
void ReadPieceSet(idParser& parser, const int numPieces,
        idList<int, tag>& output, const bool complement) {
    output.Clear();
    if (!parser.ExpectTokenString("{")) return;
    idList<int, 5> authored(16);
    idToken token;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        if (idStr::Cmp(token.c_str(), ",") == 0) continue;
        if (idStr::Icmp(token.c_str(), "all") == 0) {
            for (int index = 0; index < numPieces; ++index)
                authored.AddUnique(index);
            continue;
        }
        const int piece = std::atoi(token.c_str()) - 1;
        if (piece < 0 || piece >= numPieces) {
            parser.Warning("pieces { } number %d out of range\n", piece + 1);
            continue;
        }
        authored.AddUnique(piece);
    }
    if (complement) {
        for (int index = 0; index < numPieces; ++index)
            if (authored.FindIndex(index) < 0) output.Append(index);
    } else {
        for (int index = 0; index < authored.Num(); ++index)
            output.Append(authored[index]);
    }
}

const void* ReadDeclName(idParser& parser,
        const void* (*resolver)(const char*)) {
    idToken token;
    if (parser.ReadToken(token) == 0) return nullptr;
    return resolver(token.c_str());
}

const void* ResolveParticle(const char* name) {
    return Decls_FindParticle(name);
}
const void* ResolveFX(const char* name) { return Decls_FindFX(name); }
const void* ResolveMaterial(const char* name) { return Decls_FindMaterial(name); }

} // namespace

idDeclInfoTemplate<idDeclBreakable> idDeclBreakable::resourceList(
    "breakable", "idDeclBreakable", "break");

idBreakableSettings::idBreakableSettings()
    : linearFriction(0.0f), angularFriction(0.0f), contactFriction(0.0f),
      linearFrictionWater(0.0f), angularFrictionWater(0.0f), bouncyness(1.0f),
      gravityVector(0.0f, 0.0f, -250.0f), worldCollisionOnly(false),
      simplePointCollision(false), crazyBounceChance(0.0f),
      maxSimulationTime(5.0f), impactParticle(nullptr), deathParticle(nullptr),
      harmlessParticle(nullptr), stopSpeed(10.0f), maxLinearVelocity(5000.0f),
      maxAngularVelocity(3.1415927f * 4.0f), noShadows(false), clipMask(1),
      dampeningDecay(0.0f) {
}

idBreakablePieceDecal::idBreakablePieceDecal()
    : material(nullptr), size(0.0f, 0.0f), depth(0.0f), angle(0.0f),
      position(0.0f, 0.0f, 0.0f), direction(0.0f, 0.0f, 0.0f),
      affectedPieces(16) {
}

idDeclBreakable::idDeclBreakable()
    : idDecl(), modelName(""), numPieces(0), settings(), explosions(16),
      trails(16), armoredPieces(16), healthPieces(16), decals(16),
      pieceDecals(16), sparks() {
    Clear();
}

const char* idDeclBreakable::DefaultDefinition() const { return "{}\n"; }

idDeclInfo* idDeclBreakable::GetDeclInfo() const { return &resourceList; }

void idDeclBreakable::Clear() {
    numPieces = 0;
    settings.linearFriction = 0.6f;
    settings.angularFriction = 0.6f;
    settings.bouncyness = 0.6f;
    settings.contactFriction = 0.5f;
    settings.linearFrictionWater = 1.0f;
    settings.angularFrictionWater = 1.0f;
    settings.gravityVector = idVec3(0.0f, 0.0f, -250.0f);
    settings.worldCollisionOnly = false;
    settings.simplePointCollision = false;
    settings.crazyBounceChance = 0.0f;
    settings.noShadows = false;
    settings.maxSimulationTime = 10.0f;
    settings.dampeningDecay = 0.0f;
    explosions.ClearFree();
    trails.ClearFree();
    decals.ClearFree();
    pieceDecals.ClearFree();
    armoredPieces.Clear();
    healthPieces.Clear();
    sparks.materials.Clear();
}

int idDeclBreakable::ContentsFromString(const char* const text) {
    if (text == nullptr) return 0;
    idLexer lexer;
    lexer.LoadMemory(text, static_cast<unsigned int>(std::strlen(text)),
        "idDeclBreakable::ContentsFromString");
    int contents = 0;
    idToken token;
    while (lexer.ReadToken(token)) {
        const char* const value = token.c_str();
        if (idStr::Icmp(value, "none") == 0
            || idStr::Cmp(value, ",") == 0) continue;
        if (idStr::Icmp(value, "solid") == 0) contents |= 0x00001;
        else if (idStr::Icmp(value, "ikclip") == 0) contents |= 0x00100;
        else if (idStr::Icmp(value, "ai") == 0) contents |= 0x00400;
        else if (idStr::Icmp(value, "corpse") == 0) contents |= 0x01000;
        else if (idStr::Icmp(value, "playerclip") == 0) contents |= 0x00008;
        else if (idStr::Icmp(value, "monsterclip") == 0) contents |= 0x00010;
        else if (idStr::Icmp(value, "vehicleclip") == 0) contents |= 0x00020;
        else if (idStr::Icmp(value, "vehicle") == 0) contents |= 0x10000;
        else break;
    }
    return contents;
}

void idDeclBreakable::ParseArmoredPieces(idParser& parser) {
    armoredPieces.SetNum(numPieces);
    for (int index = 0; index < armoredPieces.Num(); ++index)
        armoredPieces[index] = 0;
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        if (idStr::Cmp(token.c_str(), ",") == 0) continue;
        const int piece = std::atoi(token.c_str()) - 1;
        const int armor = parser.ParseInt();
        if (piece < 0 || piece >= armoredPieces.Num())
            parser.Error("Unknown piece '%d' in breakable '%s' in armored piece structure.",
                piece + 1, GetName());
        else armoredPieces[piece] = armor;
    }
}

void idDeclBreakable::ParseHealthPieces(idParser& parser) {
    healthPieces.SetNum(numPieces);
    for (int index = 0; index < healthPieces.Num(); ++index)
        healthPieces[index] = 0;
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        if (idStr::Cmp(token.c_str(), ",") == 0) continue;
        const int piece = std::atoi(token.c_str()) - 1;
        const int health = parser.ParseInt();
        if (piece < 0 || piece >= healthPieces.Num())
            parser.Error("Health piece index %d/%d is out of range in breakable '%s'",
                piece, healthPieces.Num(), GetName());
        else healthPieces[piece] = health;
    }
}

void idDeclBreakable::ParseContents(idParser& parser, int& contents) const {
    idStr text;
    idToken token;
    while (parser.ReadToken(token) != 0) {
        text.Append(token.c_str());
        if (parser.CheckTokenString(",") == 0) break;
        text.Append(',');
    }
    contents = ContentsFromString(text.c_str());
}

void idDeclBreakable::ParseSpark(idParser& parser) {
    sparks.sizeMin = sparks.sizeMax = 1.0f;
    sparks.velocityScaleMin = sparks.velocityScaleMax = 1.0f;
    sparks.materials.Clear();
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        const char* const property = token.c_str();
        if (idStr::Icmp(property, "sizeMin") == 0)
            sparks.sizeMin = parser.ParseFloat();
        else if (idStr::Icmp(property, "sizeMax") == 0)
            sparks.sizeMax = parser.ParseFloat();
        else if (idStr::Icmp(property, "velocityScaleMin") == 0)
            sparks.velocityScaleMin = parser.ParseFloat();
        else if (idStr::Icmp(property, "velocityScaleMax") == 0)
            sparks.velocityScaleMax = parser.ParseFloat();
        else if (idStr::Icmp(property, "material") == 0) {
            if (!parser.ExpectTokenString("{")) return;
            while (parser.ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0) {
                const idMaterial* const material = Decls_FindMaterial(token.c_str());
                if (material == nullptr)
                    parser.Error("Could not find material '%s' for breakable '%s'.",
                        token.c_str(), GetName());
                else sparks.materials.Append(material);
            }
        } else parser.Warning("Bad token '%s'\n", property);
    }
}

void idDeclBreakable::ParseExplosion(idParser& parser) {
    idBreakableExplosion explosion;
    explosion.delay = 0;
    explosion.useLinear = false;
    explosion.activateAllDelay = -1;
    explosion.duration = 200;
    explosion.radius = 0.0f;
    explosion.impulse = 3000.0f;
    explosion.falloff = 0.2f;
    explosion.angular = 0.0f;
    explosion.distTimeScaleDelay = 0.0f;
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    bool excluded = false;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        const char* const property = token.c_str();
        if (idStr::Icmp(property, "particle") == 0)
            explosion.particle = static_cast<const idDeclParticle*>(
                ReadDeclName(parser, ResolveParticle));
        else if (idStr::Icmp(property, "fx") == 0)
            explosion.fx = static_cast<const idDeclFX*>(
                ReadDeclName(parser, ResolveFX));
        else if (idStr::Icmp(property, "position") == 0)
            parser.Parse1DMatrix(3, &explosion.position.x);
        else if (idStr::Icmp(property, "radius") == 0)
            explosion.radius = parser.ParseFloat();
        else if (idStr::Icmp(property, "impulse") == 0)
            explosion.impulse = parser.ParseFloat();
        else if (idStr::Icmp(property, "falloff") == 0)
            explosion.falloff = parser.ParseFloat();
        else if (idStr::Icmp(property, "angular") == 0)
            explosion.angular = parser.ParseFloat();
        else if (idStr::Icmp(property, "delay") == 0)
            explosion.delay = parser.ParseInt();
        else if (idStr::Icmp(property, "activateAllDelay") == 0)
            explosion.activateAllDelay = parser.ParseInt();
        else if (idStr::Icmp(property, "duration") == 0)
            explosion.duration = parser.ParseInt();
        else if (idStr::Icmp(property, "excludePieces") == 0) {
            ReadPieceSet(parser, numPieces, explosion.pieces, true);
            excluded = true;
        } else parser.Warning("Bad token '%s'\n", property);
    }
    if (!excluded)
        for (int index = 0; index < numPieces; ++index)
            explosion.pieces.Append(index);
    explosions.Append(explosion);
}

void idDeclBreakable::ParseTrail(idParser& parser) {
    idBreakableTrail trail;
    trail.glowQuadSize = 20.0f;
    trail.minTrailVelocity = 10.0f;
    trail.minBounceVelocity = 10.0f;
    trail.trailSpacing = 20.0f;
    trail.trailVelocityScale = 0.0f;
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    bool hasPieces = false;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        const char* const property = token.c_str();
        if (idStr::Icmp(property, "particleTrail") == 0)
            trail.particleTrail = static_cast<const idDeclParticle*>(
                ReadDeclName(parser, ResolveParticle));
        else if (idStr::Icmp(property, "particleBounce") == 0)
            trail.particleBounce = static_cast<const idDeclParticle*>(
                ReadDeclName(parser, ResolveParticle));
        else if (idStr::Icmp(property, "particleDie") == 0)
            trail.particleDie = static_cast<const idDeclParticle*>(
                ReadDeclName(parser, ResolveParticle));
        else if (idStr::Icmp(property, "glowQuadMaterial") == 0)
            trail.glowQuadMaterial = static_cast<const idMaterial*>(
                ReadDeclName(parser, ResolveMaterial));
        else if (idStr::Icmp(property, "glowQuadSize") == 0)
            trail.glowQuadSize = parser.ParseFloat();
        else if (idStr::Icmp(property, "fadeInDuration") == 0)
            trail.fadeInDuration = parser.ParseInt();
        else if (idStr::Icmp(property, "fadeOutDuration") == 0)
            trail.fadeOutDuration = parser.ParseInt();
        else if (idStr::Icmp(property, "minTrailVelocity") == 0)
            trail.minTrailVelocity = parser.ParseFloat();
        else if (idStr::Icmp(property, "minBounceVelocity") == 0)
            trail.minBounceVelocity = parser.ParseFloat();
        else if (idStr::Icmp(property, "trailSpacing") == 0)
            trail.trailSpacing = parser.ParseFloat();
        else if (idStr::Icmp(property, "trailVelocityScale") == 0)
            trail.trailVelocityScale = parser.ParseFloat();
        else if (idStr::Icmp(property, "delay") == 0)
            trail.delay = parser.ParseInt();
        else if (idStr::Icmp(property, "duration") == 0)
            trail.duration = parser.ParseInt();
        else if (idStr::Icmp(property, "pieces") == 0) {
            ReadPieceSet(parser, numPieces, trail.pieces, false);
            hasPieces = true;
        } else parser.Warning("Bad token '%s'\n", property);
    }
    if (!hasPieces)
        for (int index = 0; index < numPieces; ++index) trail.pieces.Append(index);
    trails.Append(trail);
}

void idDeclBreakable::ParseDecals(idParser& parser) {
    idBreakableDecal decal;
    decal.lifetime = 10000;
    decal.fadeOutStartTime = 2000;
    decal.fadeInEndTime = 0;
    decal.minSize = idVec2(32.0f, 32.0f);
    decal.maxSize = idVec2(32.0f, 32.0f);
    decal.minBounceVelocity = 10.0f;
    decal.decalSpacing = 3000.0f;
    decal.depth = 8.0f;
    if (!parser.ExpectTokenString("{")) return;
    idToken token;
    bool hasPieces = false;
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        const char* const property = token.c_str();
        if (idStr::Icmp(property, "minSizeX") == 0) decal.minSize.x = parser.ParseFloat();
        else if (idStr::Icmp(property, "minSizeY") == 0) decal.minSize.y = parser.ParseFloat();
        else if (idStr::Icmp(property, "maxSizeX") == 0) decal.maxSize.x = parser.ParseFloat();
        else if (idStr::Icmp(property, "maxSizeY") == 0) decal.maxSize.y = parser.ParseFloat();
        else if (idStr::Icmp(property, "lifetime") == 0) decal.lifetime = parser.ParseInt();
        else if (idStr::Icmp(property, "fadetime") == 0) decal.fadeOutStartTime = parser.ParseInt();
        else if (idStr::Icmp(property, "fadeInEndTime") == 0) decal.fadeInEndTime = parser.ParseInt();
        else if (idStr::Icmp(property, "decalSpacing") == 0) decal.decalSpacing = parser.ParseFloat();
        else if (idStr::Icmp(property, "minBounceVelocity") == 0) decal.minBounceVelocity = parser.ParseFloat();
        else if (idStr::Icmp(property, "splatterOnBounce") == 0) decal.splatterOnBounce = parser.ParseBool();
        else if (idStr::Icmp(property, "splatterOnRest") == 0) decal.splatterOnRest = parser.ParseBool();
        else if (idStr::Icmp(property, "depth") == 0) decal.depth = parser.ParseFloat();
        else if (idStr::Icmp(property, "materials") == 0) {
            if (!parser.ExpectTokenString("{")) return;
            while (parser.ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0) {
                const idMaterial* const material = Decls_FindMaterial(token.c_str());
                if (material != nullptr) decal.materials.Append(material);
                else parser.Warning("Could not find material '%s' for breakable '%s'.",
                    token.c_str(), GetName());
            }
        } else if (idStr::Icmp(property, "pieces") == 0) {
            ReadPieceSet(parser, numPieces, decal.pieces, false);
            hasPieces = true;
        } else parser.Warning("Bad token '%s'\n", property);
    }
    if (!hasPieces)
        for (int index = 0; index < numPieces; ++index) decal.pieces.Append(index);
    if (decal.depth < 0.001f) parser.Warning("Decal depth is too small");
    if (decal.materials.Num() == 0) parser.Warning("No valid materials found");
    if (decal.minSize.x > decal.maxSize.x || decal.minSize.y > decal.maxSize.y)
        parser.Warning("Decals have bad sizes");
    decals.Append(decal);
}

void idDeclBreakable::ParsePieceDecal(idParser& parser) {
    if (!parser.ExpectTokenString("{")) return;
    idBreakablePieceDecal decal;
    idToken token;
    if (parser.ReadToken(token) == 0) return;
    decal.material = Decls_FindMaterial(token.c_str());
    if (decal.material == nullptr)
        parser.Error("Could not find material '%s' for breakable '%s'.",
            token.c_str(), GetName());
    parser.Parse1DMatrix(2, &decal.size.x);
    decal.depth = parser.ParseFloat();
    decal.angle = parser.ParseFloat();
    parser.Parse1DMatrix(3, &decal.position.x);
    parser.Parse1DMatrix(3, &decal.direction.x);
    if (!parser.ExpectTokenString("{")) {
        parser.Error("Bad Parsing");
        return;
    }
    while (parser.ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0)
        decal.affectedPieces.Append(std::atoi(token.c_str()));
    parser.ExpectTokenString("}");
    pieceDecals.Append(decal);
}

void idDeclBreakable::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    Clear();
    idToken token;
    while (parser->ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        const char* const property = token.c_str();
        if (idStr::Icmp(property, "model") == 0) {
            if (parser->ReadToken(token) == 0) return;
            modelName.Set(token.c_str());
            numPieces = Decls_LoadBreakableModelPieceCount(modelName.c_str());
        } else if (idStr::Icmp(property, "linearFriction") == 0) settings.linearFriction = parser->ParseFloat();
        else if (idStr::Icmp(property, "angularFriction") == 0) settings.angularFriction = parser->ParseFloat();
        else if (idStr::Icmp(property, "contactFriction") == 0) settings.contactFriction = parser->ParseFloat();
        else if (idStr::Icmp(property, "linearFrictionWater") == 0) settings.linearFrictionWater = parser->ParseFloat();
        else if (idStr::Icmp(property, "angularFrictionWater") == 0) settings.angularFrictionWater = parser->ParseFloat();
        else if (idStr::Icmp(property, "bouncyness") == 0) settings.bouncyness = parser->ParseFloat();
        else if (idStr::Icmp(property, "dampeningDecay") == 0) settings.dampeningDecay = parser->ParseFloat();
        else if (idStr::Icmp(property, "gravity") == 0) {
            settings.gravityVector.x = parser->ParseFloat();
            settings.gravityVector.y = parser->ParseFloat();
            settings.gravityVector.z = parser->ParseFloat();
        } else if (idStr::Icmp(property, "worldCollisionOnly") == 0) settings.worldCollisionOnly = parser->ParseBool();
        else if (idStr::Icmp(property, "simplePointCollision") == 0) settings.simplePointCollision = parser->ParseBool();
        else if (idStr::Icmp(property, "crazyBounceChance") == 0) settings.crazyBounceChance = parser->ParseFloat();
        else if (idStr::Icmp(property, "maxSimulationTime") == 0) settings.maxSimulationTime = parser->ParseFloat();
        else if (idStr::Icmp(property, "stopSpeed") == 0) settings.stopSpeed = parser->ParseFloat();
        else if (idStr::Icmp(property, "maxLinearVelocity") == 0) settings.maxLinearVelocity = parser->ParseFloat();
        else if (idStr::Icmp(property, "maxAngularVelocity") == 0) settings.maxAngularVelocity = parser->ParseFloat();
        else if (idStr::Icmp(property, "noShadows") == 0) settings.noShadows = parser->ParseBool();
        else if (idStr::Icmp(property, "impactParticle") == 0) settings.impactParticle = static_cast<const idDeclParticle*>(ReadDeclName(*parser, ResolveParticle));
        else if (idStr::Icmp(property, "deathParticle") == 0) settings.deathParticle = static_cast<const idDeclParticle*>(ReadDeclName(*parser, ResolveParticle));
        else if (idStr::Icmp(property, "harmlessParticle") == 0) settings.harmlessParticle = static_cast<const idDeclParticle*>(ReadDeclName(*parser, ResolveParticle));
        else if (idStr::Icmp(property, "impactSoundTable") == 0) parser->ReadToken(token);
        else if (idStr::Icmp(property, "explosion") == 0) ParseExplosion(*parser);
        else if (idStr::Icmp(property, "trail") == 0) ParseTrail(*parser);
        else if (idStr::Icmp(property, "armoredPieces") == 0) ParseArmoredPieces(*parser);
        else if (idStr::Icmp(property, "healthPieces") == 0) ParseHealthPieces(*parser);
        else if (idStr::Icmp(property, "decals") == 0) ParseDecals(*parser);
        else if (idStr::Icmp(property, "contents") == 0) ParseContents(*parser, settings.clipMask);
        else if (idStr::Icmp(property, "spark") == 0) ParseSpark(*parser);
        else if (idStr::Icmp(property, "pieceDecal") == 0) ParsePieceDecal(*parser);
        else parser->Warning("Bad token '%s'\n", property);
    }
    if (modelName.IsEmpty()) parser->Warning("No model specified for breakable\n");
}

void idDeclBreakable::GenerateDecalInfoFromModel(
        const idDeclBreakable* const declaration,
        const char* const decalModelName) {
    if (declaration != nullptr && decalModelName != nullptr)
        Decls_GenerateBreakableDecalInfo(declaration, decalModelName);
}
