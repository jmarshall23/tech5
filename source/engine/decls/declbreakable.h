#pragma once

#include "decls/decltypeinfo.h"
#include "gamelib/effectphysics/effectphysicsbreakable.h"
#include "idlib/math/vector.h"

class idDeclParticle;
class idMaterial;
class idParser;

struct alignas(4) idBreakableSettings {
    idBreakableSettings();

    float linearFriction;
    float angularFriction;
    float contactFriction;
    float linearFrictionWater;
    float angularFrictionWater;
    float bouncyness;
    idVec3 gravityVector;
    bool worldCollisionOnly;
    bool simplePointCollision;
    float crazyBounceChance;
    float maxSimulationTime;
    const idDeclParticle* impactParticle;
    const idDeclParticle* deathParticle;
    const idDeclParticle* harmlessParticle;
    float stopSpeed;
    float maxLinearVelocity;
    float maxAngularVelocity;
    bool noShadows;
    int clipMask;
    float dampeningDecay;
};

struct alignas(4) idBreakablePieceDecal {
    idBreakablePieceDecal();

    const idMaterial* material;
    idVec2 size;
    float depth;
    float angle;
    idVec3 position;
    idVec3 direction;
    idList<int, 5> affectedPieces;
};

class alignas(4) idDeclBreakable : public idDecl {
public:
    idDeclBreakable();

    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    idDeclInfo* GetDeclInfo() const override;

    static int ContentsFromString(const char* text);
    static void GenerateDecalInfoFromModel(
        const idDeclBreakable* declaration, const char* decalModelName);

    idAtomicString modelName;
    int numPieces;
    idBreakableSettings settings;
    idList<idBreakableExplosion, 59> explosions;
    idList<idBreakableTrail, 59> trails;
    idList<int, 59> armoredPieces;
    idList<int, 59> healthPieces;
    idList<idBreakableDecal, 59> decals;
    idList<idBreakablePieceDecal, 5> pieceDecals;
    idBreakableSpark sparks;

    static idDeclInfoTemplate<idDeclBreakable> resourceList;

private:
    void Clear();
    void ParseArmoredPieces(idParser& parser);
    void ParseHealthPieces(idParser& parser);
    void ParseContents(idParser& parser, int& contents) const;
    void ParseSpark(idParser& parser);
    void ParseExplosion(idParser& parser);
    void ParseTrail(idParser& parser);
    void ParseDecals(idParser& parser);
    void ParsePieceDecal(idParser& parser);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBreakableSettings) == 84,
    "Recovered breakable settings ABI changed");
static_assert(sizeof(idBreakablePieceDecal) == 60,
    "Recovered piece-decal ABI changed");
static_assert(sizeof(idDeclBreakable) == 276,
    "Recovered breakable declaration ABI changed");
#endif
