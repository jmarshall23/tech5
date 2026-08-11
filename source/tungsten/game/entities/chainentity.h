#pragma once

#include "entityptr.h"
#include "game/gamesys/eventarg.h"
#include "idlib/bv/sphere.h"
#include "idlib/containers/list.h"
#include "idlib/lookuptable.h"
#include "idlib/math/plane.h"
#include "idlib/math/vector.h"
#include "idlib/text/cmdargs.h"
#include "idlib/text/str.h"

#include <cstdint>

class idAnimatedEntity;
class idDeclDamage;
class idEntity;
class idFuncChain;
class idFuncChainGroup;
class idFuncChainServices;
class idJointMat;
class idSoundShader;
struct cm_sphereModelPtrs_t;
struct trace_t;

struct damageMorph_t {
    float amount[4];
    int index[4];

    damageMorph_t();
};

// Particle/constraint state is independent of the game entity runtime and is
// kept as a complete local implementation of the retail Verlet solver.
class idVerletChain {
public:
    struct particle_t {
        idVec3 oldPos;
        idVec3 currentPos;
        float health;
        float healthStamp;
        int timeStamp;
        bool anchor;
        std::uint8_t padding[3];

        particle_t();
        explicit particle_t(const idVec3& position);
    };

    struct constraint_t {
        int index1;
        int index2;
        float ratio1;
        float ratio2;
        float length;
        float lengthSquared;
    };

    struct orientation_t {
        std::uint16_t index1;
        std::uint16_t index2;
    };

    struct force_t {
        idVec3 force;
        int numSteps;
        int pointId;

        force_t();
        force_t(const idVec3& value, int steps, int point);
    };

    struct plane_t {
        idPlane plane;
        int startIndex[2];
        int numPoints[2];

        plane_t();
    };

    struct settings_t {
        idVec3 gravity;
        float frictionAir;
        float frictionFloor;
        float floorFrictionDistance;
        float linkRadius;
        float stiffness;
        float lengthAdjustment;
        float frameSeconds;
        int iterations;
        int maximumDynamicIterations;
        float dynamicIterationError;
        bool anchorStart;
        bool anchorEnd;
        bool enabled;
        bool dynamicIterations;

        settings_t();
    };

    idVerletChain();
    virtual ~idVerletChain();

    idVec3 GetNormal(int pointId) const;
    bool UpdateCooldown(int pointId, int gameTime, float& health);
    int GetBestPoint(const idVec3& position) const;
    int GetBestConstraint(int id, const idVec3& position) const;
    void GetMovement(int start, int end, float& maxMovement,
        float& avgMovement) const;
    void GetConstraint(int id, idVec3& pos1, idVec3& pos2,
        float& restLengthDiff) const;
    void BuildConstraints(float health);
    bool Damage(int constraintId, int gameTime, float damage,
        damageMorph_t& morph);
    void Update(bool clearCollisionSpheres, bool isStiff,
        float gravityScale);
    void AddCollisionPlane(const idPlane& plane, bool skipStart,
        bool skipEnd);
    void ForceUpdate(int numSimulations, float gravityScale);

    idList<constraint_t, 5> constraints;
    idList<particle_t, 5> points;
    idList<orientation_t, 5> orientations;
    idList<force_t, 5> forces;
    idList<idSphere, 5> sphereCollisions;
    idList<plane_t, 5> planeCollisions;
    idVec3 refForward;
    idVec3 refLeft;
    idVec3 refDown;
    float maxHealth;
    int brokenPointIndex;
    settings_t settings;

private:
    void Constrain();
    void Integrate(float deltaTime, float gravityScale);

    idLookupTable cooldownTable;
};

class idFuncChain {
public:
    struct binddef_t {
        binddef_t();

        idEntityPtr<idEntity> bindToObject;
        idStr bindToJoint;
        idStr bindToTag;
    };

    struct chaindef_t {
        chaindef_t();

        idVec3 startPosition;
        idVec3 endPosition;
        float extraLength;
        binddef_t startBindInfo;
        binddef_t endBindInfo;
        bool randomRotate;
        bool smoothSkinning;
        float startRotation;
    };

    struct bind_t {
        idEntityPtr<idEntity> bindMaster;
        std::int16_t bindJoint;
        std::uint16_t bindTagParentJoint;
        idVec3 bindTagTranslation;
        idMat3 bindTagAxis;

        bind_t();
    };

    struct origin_t {
        bind_t bind;
        idVec3 position;

        origin_t();
    };

    struct chain_t {
        origin_t start;
        origin_t end;
    };

    struct sphere_t {
        binddef_t bindInfo;
        origin_t origin;
        float radius;

        sphere_t();
    };

    struct plane_t {
        idVec3 center;
        idVec3 normal;
        bool startSegment;
        bool endSegment;

        plane_t();
    };

    idFuncChain();
    virtual ~idFuncChain();

    static void SetServices(idFuncChainServices* services);
    static idFuncChainServices& Services();

    void GetSoundTransform(idVec3& soundOrigin, idMat3& soundAxis) const;
    void BindEndPoint(const binddef_t& bindInfo, bind_t& bind);
    void BuildPhysics();
    bool GetWorldPosition(const origin_t& origin, idVec3& worldOrigin,
        idMat3& worldAxis) const;
    eventVoid Event_SpawnBindEndPoints();
    float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);
    void AddCollisionInfo();
    void Think();
    void Spawn();
    void InitialSetup();
    void DisableChain();

    idStr name;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    const void* chainLinkModel;
    chaindef_t chainDef;
    idEntityPtr<idFuncChainGroup> chainGroup;
    const void* morphMaterial;
    idList<sphere_t, 5> collisions;
    idList<plane_t, 5> collisionPlanes;
    idList<idEntityPtr<idEntity>, 5> animCollisions;
    const idSoundShader* soundBreak;
    const idSoundShader* soundRattle;
    bool highlight;
    unsigned int damageTypes;
    float maxHealth;
    idVec3 breakPosition;
    bool generatedPhysics;
    chain_t state;
    void* emitter1;
    void* emitter2;
    int brokenLink;
    idVerletChain verlet;
    void* physicsObject;
};

class idFuncChainGroup {
public:
    idFuncChainGroup();
    virtual ~idFuncChainGroup();

    void OnActivate(idEntity* activator);
    void Spawn();

    idList<idEntityPtr<idFuncChain>, 5> chains;
    idList<bool, 5> activeChains;
};

// Entity lookup, skeletal binding, render-model mutation, sound, and physics
// are owned by the central game runtime.  The leaf translation unit calls
// this complete seam at each recovered dependency point.
class idFuncChainServices {
public:
    virtual ~idFuncChainServices() = default;

    virtual float GetFrameSeconds() const { return 1.0f / 60.0f; }
    virtual int GetGameTime() const { return 0; }
    virtual int GetEntityNumber(const idEntity*) const { return -1; }
    virtual idEntity* ResolveEntity(int) const { return nullptr; }
    virtual idFuncChain* ResolveChain(int) const { return nullptr; }
    virtual idFuncChainGroup* ResolveChainGroup(int) const { return nullptr; }
    virtual void ActivateTargets(idFuncChain&) {}
    virtual void ActivateTargets(idFuncChainGroup&) {}
    virtual void ActivateChainGroup(idFuncChainGroup&, idFuncChain&) {}
    virtual void Warn(const char*) {}
    virtual void Print(const char*) {}

    virtual bool ResolveBinding(const idFuncChain::binddef_t&,
        idFuncChain::bind_t&) { return false; }
    virtual bool ResolveWorldPosition(const idFuncChain::origin_t&,
        idVec3&, idMat3&) const { return false; }

    virtual idFuncChain* FindChain(const char*) const { return nullptr; }
    virtual void BuildChainClipModel(idFuncChain&, const char*) {}
    virtual bool BuildRenderChain(idFuncChain&,
        idList<idVec3, 5>&) { return false; }
    virtual void RemoveEntity(idFuncChain&) {}
    virtual void SetHighlight(idFuncChain&, bool) {}
    virtual void SetLinkPosition(idFuncChain&, int, const idVec3&,
        const idMat3&) {}
    virtual void SetLinkMorphAmount(idFuncChain&, int, float) {}
    virtual void RemoveSmoothSkinning(idFuncChain&, int) {}
    virtual void Present(idFuncChain&) {}

    virtual void BuildPhysics(idFuncChain&, bool) {}
    virtual void DisablePhysics(idFuncChain&) {}
    virtual void GatherAnimatedCollisionSpheres(idEntity*,
        const idVec3&, const idMat3&, idList<idSphere, 5>&) {}
    virtual int SetupCollisionSpherePtrs(idAnimatedEntity*,
        cm_sphereModelPtrs_t*, idVec3&, idMat3&,
        const idJointMat*&) { return 0; }

    virtual unsigned int GetDamageTypes(const idDeclDamage*) const {
        return 0;
    }
    virtual float GetDamageAmount(const idDeclDamage*) const { return 0.0f; }
    virtual float GetMaximumDamage(const idDeclDamage*) const { return 0.0f; }
    virtual bool GetTraceImpact(const trace_t*, idVec3&) const {
        return false;
    }
    virtual void StartBreakSound(idFuncChain&) {}
    virtual void StartOrUpdateRattle(idFuncChain&, int,
        const idVec3&, float) {}
    virtual bool IsDormant(idFuncChain&) const { return false; }
};

void buildChainClipModel_f(const idCmdArgs& args);
int SetupCollisionSpherePtrsFromEntity(idAnimatedEntity* entity,
    cm_sphereModelPtrs_t* spherePointers, idVec3* origin, idMat3* axis,
    const idJointMat** modelJoints);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFuncChain::binddef_t) == 68,
    "Recovered chain binding definition ABI changed");
static_assert(sizeof(idFuncChain::chaindef_t) == 172,
    "Recovered chain definition ABI changed");
static_assert(sizeof(idVerletChain::particle_t) == 40,
    "Recovered Verlet particle ABI changed");
static_assert(sizeof(idVerletChain::constraint_t) == 24,
    "Recovered Verlet constraint ABI changed");
static_assert(sizeof(idVerletChain::force_t) == 20,
    "Recovered Verlet force ABI changed");
static_assert(sizeof(idVerletChain::plane_t) == 32,
    "Recovered Verlet plane ABI changed");
#endif
