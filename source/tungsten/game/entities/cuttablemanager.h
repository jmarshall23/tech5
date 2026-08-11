#pragma once

#include "game/entities/cuttable.h"
#include "gamelib/effectphysics/effectphysicscuttable.h"
#include "idlib/containers/list.h"
#include "models/rendermodel.h"

class idClip;
class idPhysics;
class idRenderModelCuttableSurface;
class idRenderWorld;
class idSoundWorld;
class idCuttableManager;

class idCuttableManagerServices {
public:
    virtual ~idCuttableManagerServices() = default;

    virtual idVertexBuffer* AllocateVertexBuffer(int bytes,
        unsigned int vertexMask);
    virtual idIndexBuffer* AllocateIndexBuffer(int bytes);
    virtual void ResizeVertexBuffer(idVertexBuffer& buffer, int bytes,
        unsigned int vertexMask);
    virtual void ResizeIndexBuffer(idIndexBuffer& buffer, int bytes);
    virtual void UploadVertexBuffer(idVertexBuffer& buffer,
        const void* data, int bytes);
    virtual void UploadIndexBuffer(idIndexBuffer& buffer,
        const void* data, int bytes);
    virtual void FreeVertexBuffer(idVertexBuffer* buffer);
    virtual void FreeIndexBuffer(idIndexBuffer* buffer);
    virtual int GetShowPhysics() const;
};

class idCuttableManager {
public:
    idCuttableManager();
    ~idCuttableManager();

    static void SetServices(idCuttableManagerServices* services);
    static idCuttableManagerServices& Services();

    void SubmitCollisionQueries();
    int Emit(const cuttablePhysicsEmitInfo_t& emitInfo,
        const idList<idDrawVert, 5>& vertices,
        const idList<idVec2, 5>& st,
        const idList<unsigned short, 5>& indices);
    void ClearCuttable(int index);
    void Update(int currentTime, unsigned int gameMsPerFrame);
    void Shutdown();
    void UpdateModel(int infoHandle, Contour* outer, Contour* inner);
    void Init(idRenderWorld* renderWorld, idSoundWorld* soundWorld,
        idClip* clip);
    int AllocateCuttable(const idStr& name,
        idRenderModelCuttableSurface* renderModel, idPhysics* physics);

    idList<cuttableInfo_t, 5> infoCuttables;
    idList<idStr, 5> nameCuttables;
    idList<idVertexBuffer*, 5> vertexBuffers;
    idList<idVertexBuffer*, 5> stBuffers;
    idList<idIndexBuffer*, 5> indexBuffers;
    idEffectPhysicsCuttable effectPhysics;
    int freeBuffer;

private:
    int AllocateBuffer();
};
