#pragma once

#include "cm/collisiontypes.h"
#include "cm/jobs/collisionquery.h"
#include "framework/resource.h"
#include "idlib/bv/box.h"
#include "idlib/geometry/winding.h"
#include "idlib/index.h"

#include <cstddef>

class idFile;
class idJointMat;
class idMemoryMappedFile;
class idResourceList;
class idStr;

enum invalidJointIndex_t : int {
    INVALID_JOINT_INDEX = -1
};

class idCollisionModel : public idResource {
public:
    ~idCollisionModel() override = default;

    virtual cmType_t GetModelType() const = 0;
    virtual bool GetBounds(idBounds& bounds) const = 0;
    virtual bool GetBox(idBox& box) const = 0;
    virtual bool GetContents(int& contents) const = 0;
    virtual bool GetVertex(int vertexFeature, idVec3& vertex) const = 0;
    virtual bool GetEdge(int edgeFeature, idVec3& start,
        idVec3& end) const = 0;
    virtual bool GetPolygon(int polygonFeature,
        idFixedWinding& winding) const = 0;
    virtual int GetPolytope(int polytopeFeature, idPlane* planes,
        int maxPlanes) const = 0;
    virtual int GetPolytopes(int* polytopeNumPlanes, int maxPolytopes,
        idPlane* planes, int maxPlanes) const = 0;
    virtual idIndex<short, invalidJointIndex_t> GetJoint(
        int sphereFeature) const = 0;
};

class idCollisionModelLocal final : public idCollisionModel {
public:
    static void* operator new(std::size_t size);
    static void operator delete(void* memory);

    idCollisionModelLocal();
    ~idCollisionModelLocal() override;

    idResourceList* GetResourceList() override;
    cmType_t GetModelType() const override { return modelType; }
    bool GetBounds(idBounds& outputBounds) const override;
    bool GetBox(idBox& box) const override;
    bool GetContents(int& outputContents) const override;
    bool GetVertex(int vertexFeature, idVec3& vertex) const override;
    bool GetEdge(int edgeFeature, idVec3& start,
        idVec3& end) const override;
    bool GetPolygon(int polygonFeature,
        idFixedWinding& winding) const override;
    int GetPolytope(int polytopeFeature, idPlane* planes,
        int maxPlanes) const override;
    int GetPolytopes(int* polytopeNumPlanes, int maxPolytopes,
        idPlane* planes, int maxPlanes) const override;
    idIndex<short, invalidJointIndex_t> GetJoint(
        int sphereFeature) const override;

    int GetTotalMemory() const;
    int GetLoadedMemory() const;
    int GetMaxResidentMemory(idVec3* location) const;
    void MakeDefault();
    static void GetBinaryFileName(const char* modelName,
        idStr& binaryFileName, bool& inMapFolder, bool& isWorld);
    bool Write_Binary();
    bool Load_Binary();
    void LoadResource() override;
    bool ReloadIfStale() override;
    void FreeData();

    static idResourceList resourceList;

    std::uint32_t binaryFileTime;
    std::uint32_t sourceFileTime;
    cmType_t modelType;
    idBounds bounds;
    int contents;
    bool isWorldModel;
    bool isTraceModel;
    bool isConvex;
    bool isStreamed;
    idFile* streamFilePtr;
    cm_polygonModel_t polygonModel;
    cm_sphereModel_t* sphereModel;
    streamAreasHeader_t* streamAreas;
    idMemoryMappedFile* memoryMappedFile;
};

struct idPositionedCollisionModel {
    idCollisionModel* model;
    const idJointMat* modelJoints;
    idVec3 modelOrigin;
    idMat3 modelAxis;
    int modelEntityNum;
    int modelPhysicsId;
    int modelBodyId;
    int modelContentsOverride;
    idCollisionQuery modelQuery;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCollisionModel) == 36,
    "Recovered idCollisionModel ABI changed");
static_assert(sizeof(idCollisionModelLocal) == 116,
    "Recovered idCollisionModelLocal ABI changed");
static_assert(sizeof(idPositionedCollisionModel) == 80,
    "Recovered idPositionedCollisionModel ABI changed");
#endif
