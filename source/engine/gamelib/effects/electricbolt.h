#pragma once

#include "idlib/containers/staticlist.h"
#include "idlib/math/vector.h"

class idDeclElectricBolt;
class idDeclTable;
class idMaterial;
class idRenderModelBeam;

// Recovered declaration-facing data used by the bolt generator.  The decl
// system owns the real idDeclElectricBolt and exposes this stable view to
// GameLib through GameLib_GetElectricBoltParameters.
struct idElectricBoltParameters {
    const idMaterial* material;
    bool applyGradient;
    int revealTime;
    float startWidth;
    float endWidth;
    float maxDeviation;
    idVec4 color;
    float brightness;
    int subdivisions;
    float branchProbability;
    int maxBranchLevels;
    float branchStartWidth;
    float branchEndWidth;
    idVec2 branchLength;
    float maxBranchAngle;
    int branchSubdivisions;
    float maxBranchDeviation;
    const idDeclTable* jitterTable;
    const idDeclTable* jitterFalloffTable;
    float jitterDecay;
    float jitterSpeed;
    idVec2 jitterLeftMag;
    idVec2 jitterUpMag;
    bool useBranchOverride;
    const idMaterial* branchMaterial;
    int branchFrames;
    int branchWidth;
};

struct eboltControlNode_t {
    idVec3 startPos;
    idVec3 endPos;
};

struct boltStats_t {
    int numNodes;
    int numBranches;
    float invTotalLength;
    idVec3 boltStartPos;
    int boltStartTime;
};

struct segment_t {
    idVec3 startPos;
    idVec3 endPos;
    float lengthFrac;
};

class idElectricBolt {
public:
    idElectricBolt();
    ~idElectricBolt();

    void Init(idRenderModelBeam* beamModel,
        const idDeclElectricBolt* eboltDecl);
    void UpdateControlNodes(
        const idStaticList<eboltControlNode_t, 32>& controlNodes);
    void StartElectricBolt(int startTime, const idVec3& startPos,
        const idVec3& endPos, float diversity);
    void StartElectricBolt(int startTime,
        const idStaticList<eboltControlNode_t, 32>& controlNodes,
        float diversity);
    void StopElectricBolt();
    void Update(int currentTime);

    const idDeclElectricBolt* eboltDecl;
    idRenderModelBeam* beamModel;
    idStaticList<eboltControlNode_t, 32> controlNodes;
    int startTime;
    int diversity;
};

static_assert(sizeof(eboltControlNode_t) == 24,
    "Recovered electric-bolt control-node ABI changed");
static_assert(sizeof(boltStats_t) == 28,
    "Recovered electric-bolt statistics ABI changed");
static_assert(sizeof(segment_t) == 28,
    "Recovered electric-bolt segment ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idElectricBolt) == 800,
    "Recovered idElectricBolt ABI changed");
#endif
