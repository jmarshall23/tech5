#pragma once

#include "gamelib/effectphysics/effectphysicscuttable.h"
#include "idlib/containers/linklist.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"
#include "models/cuttable/cuttergraph.h"

class Contour;
class idClipModel;
class idCollisionGrid;
class idCollisionModel;
class idCutterClip;
class idDeclDamage;
class idDeclImpactSound;
class idEntity;
class idFile;
class idPhysics;
class idPresentable;
class idRenderModel;
class idRenderModelCuttableBeams;
class idRenderModelCuttableSurface;
struct trace_t;
class idCuttable;

struct cuttableStateInfo_t {
    idStr name;
    bool graphValid;

    cuttableStateInfo_t() : name(), graphValid(false) {}
};

struct cuttableInfo_t {
    idRenderModelCuttableSurface* renderModel;
    idPhysics* physics;
    Contour* outerContour;
    Contour* innerContour;

    cuttableInfo_t()
        : renderModel(nullptr), physics(nullptr), outerContour(nullptr),
          innerContour(nullptr) {}
};

struct idCuttableContourPoints {
    idList<idVec2i, 5> points;
};

class idCuttableServices {
public:
    virtual ~idCuttableServices() = default;

    virtual idPresentable* AllocPresentable(idCuttable&, idRenderModel*);
    virtual void RegisterCuttable(idCuttable&);
    virtual void UnregisterCuttable(idCuttable&);
    virtual void ClearCuttable(int infoHandle);
    virtual idCutterGraphManager* GetGraphManager();
    virtual idCutterClip* GetClipHelper();
    virtual bool ShouldSaveCuttableState() const;

    virtual idStr GetRenderWorldName() const;
    virtual idRenderModelCuttableSurface* LoadCuttableSurface(
        const idStr& assetName);
    virtual bool SurfaceHasGeometry(
        const idRenderModelCuttableSurface* model) const;
    virtual idCollisionGrid* LoadCollisionGrid(const idStr& assetName);
    virtual bool CollisionGridIsValid(const idCollisionGrid* grid) const;
    virtual void ReleaseCollisionGrid(idCollisionGrid* grid);
    virtual idPhysics* CreatePhysics(idCuttable&);
    virtual void AttachModelAndPhysics(idCuttable&);
    virtual int AllocateCuttableInfo(const idStr& name,
        idRenderModelCuttableSurface* model, idPhysics* physics);
    virtual idRenderModelCuttableBeams* CreateBeamModel(idCuttable&);
    virtual void ConfigureBeamModel(idCuttable&);
    virtual void SetAllClipTransforms(idCuttable&, const idVec3&,
        const idMat3&);
    virtual void UpdateVisuals(idCuttable&);
    virtual void SetThinkActive(idCuttable&, bool active);
    virtual void SetHidden(idCuttable&, bool hidden);

    virtual void DetachClipModels(idCuttable&);
    virtual bool RebuildClipModels(idCuttable&,
        const idList<idCuttableContourPoints, 5>& inactiveFills);
    virtual void ReleaseRuntimeResources(idCuttable&);

    virtual void GetTransform(const idCuttable&, idVec3& origin,
        idMat3& axis) const;
    virtual bool DebugCuttable() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual void DebugDrawGraph(idCutterGraphManager&, int graphHandle,
        int lifeTime);
    virtual void UpdateBeamModel(idCuttable&, idCutterGraphManager&,
        int graphHandle, const idVec3& origin, const idMat3& axis);
    virtual void RunPhysics(idCuttable&);
    virtual void UpdateEffects(idCuttable&);

    virtual int GetGameMilliseconds() const;
    virtual int GetEntityNumber(const idCuttable&) const;
    virtual bool EmitCutPiece(const cuttablePhysicsEmitInfo_t& emitInfo,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& textureCoordinates,
        const idList<unsigned short, 5>& indices);
    virtual void UpdateCuttableModel(int infoHandle, Contour* outer,
        Contour* inner);
    virtual void InvalidateCuttableModel(idCuttable&);
    virtual void Warning(const char* message);

    virtual int GetDamageTypes(const idDeclDamage* damage) const;
    virtual bool GetDamageCutPoint(const trace_t* trace,
        idVec3& cutPoint) const;
};

class idCuttable {
public:
    idCuttable();
    virtual ~idCuttable();

    static void SetServices(idCuttableServices* services);
    static idCuttableServices& Services();

    virtual idPresentable* AllocPresentable(idRenderModel* renderModel);
    void CreateStateInfo(cuttableStateInfo_t& state) const;
    bool GetPolygon(idList<idVec2i, 5>& points,
        idCutterClip* cutterClip);
    static void WriteLevelStateToFile(idFile* file,
        idList<cuttableStateInfo_t, 5>& stateInfo,
        idCutterGraphState& graphState);
    static void ReadLevelStateFromFile(idFile* file,
        idList<cuttableStateInfo_t, 5>& stateInfo,
        idCutterGraphState& graphState);
    void BuildClipModel();
    void Spawn();
    virtual void Think();
    void ApplyStateInfo(const cuttableStateInfo_t& state);
    void PushCut(idVec3 point, const idVec3& direction);
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);

    idStr name;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    int thinkFlags;
    int entityNumber;

    idPhysics* physicsObj;
    idLinkList<idCuttable> cuttableNode;
    idCollisionGrid* collisionGrid;
    idRenderModelCuttableSurface* cutModel;
    idRenderModelCuttableBeams* beamModel;
    idClipModel* clipModel;
    idClipModel* gridClipModel;
    idCollisionModel* collisionModel;
    idCollisionModel* gridCollisionModel;
    int graphHandle;
    int infoHandle;
    const idDeclImpactSound* impactTable;
    int nestedPolygons;
    int connectedPolygons;
};
