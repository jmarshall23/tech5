#include "gamelib/effectphysics/effectphysicsboxfountain.h"

#include "gamelib/physics/tracemodelcache.h"
#include "idlib/geometry/tracemodel.h"

// Renderer ownership is an engine boundary outside GameLib. The renderer port
// provides this operation when idRenderModel is activated; keeping it external
// avoids fabricating a partial render-model layout here.
void GameLib_MarkRenderModelForDeletion(idRenderModelManyBoxes* model);

idEffectPhysicsBoxFountain::idEffectPhysicsBoxFountain()
    : broadPhase()
    , properties()
    , rigidBodies(0)
    , manyBoxes(nullptr)
    , lastFireTime(0)
    , currentFireRigidBody(0)
    , startOrigin()
    , spawnOrigin()
    , spawnObject()
    , random() {
    startOrigin.Zero();
    spawnOrigin.Zero();
}

idEffectPhysicsBoxFountain::~idEffectPhysicsBoxFountain() {
    if (manyBoxes != nullptr) {
        GameLib_MarkRenderModelForDeletion(manyBoxes);
    }
    spawnObject.overlap.Clear();
    rigidBodies.Clear();
}

void idEffectPhysicsBoxFountain::Init(
    idClip* const clip,
    idTraceModelCache* const traceModelCache,
    const int entityNumber) {
    broadPhase.Init(clip, traceModelCache);

    idBounds bounds;
    bounds[0].Set(-16.0f, -16.0f, -16.0f);
    bounds[1].Set(16.0f, 16.0f, 16.0f);
    idTraceModel traceModel;
    traceModel.SetupBox(bounds);
    const int traceModelIndex = traceModelCache->AllocTraceModel(
        traceModel, nullptr);
    properties.Setup(&broadPhase, traceModelIndex, 10.0f);

    startOrigin.Set(0.0f, 0.0f, 64.0f);
    spawnOrigin.Set(0.0f, 0.0f, 160.0f);
    broadPhase.AddObject(
        &spawnObject, spawnOrigin, idMat3(1.0f), &bounds);
    spawnObject.entityNum = entityNumber;
}
