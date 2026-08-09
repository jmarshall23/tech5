#pragma once

#include "models/rendermodel.h"

#include <cstdint>
#include <string>
#include <vector>

struct idImportCorner {
    int position = -1;
    int texCoord = -1;
    int normal = -1;
    int color = -1;
};

struct idImportTriangle {
    idImportCorner corners[3];
    int material = -1;
    unsigned int smoothingGroup = 0;
};

struct idImportMaterial {
    std::string name;
    std::string diffuseMap;
    bool twoSided = false;
};

struct idImportModel {
    std::vector<idVec3> positions;
    std::vector<idVec2> texCoords;
    std::vector<idVec3> normals;
    std::vector<std::uint32_t> colors;
    std::vector<idImportMaterial> materials;
    std::vector<idImportTriangle> triangles;
};

class idASEModel : public idImportModel {};

class idOBJModel : public idImportModel {
public:
    bool Save(const char* fileName) const;
    bool Load(const char* fileName);
    bool AddGroupGeometry(const char* groupName,
        const idList<idTriangles*, 5>& geometry,
        const idList<const idMaterial*, 5>& materials);
};

struct lwLayer {
    int index = 0;
    std::string name;
    idImportModel model;
    lwLayer* next = nullptr;
};

struct lwObject {
    lwLayer* layer = nullptr;
    int nlayers = 0;
};

idASEModel* ASE_Parse(const char* text, bool verbose = false);
idASEModel* ASE_Load(const char* fileName);
void ASE_Free(idASEModel* model);

idOBJModel* OBJ_Load(const char* fileName);

lwObject* lwGetObject(const char* fileName, float scale,
    unsigned int* timestamp = nullptr, int* failId = nullptr);
lwObject* lwGetObject5(const char* fileName, float scale,
    unsigned int* timestamp = nullptr, int* failId = nullptr);
void lwFreeObject(lwObject* object);
void lwFreeLayer(lwLayer* layer);
void lwForceSmoothSurfaces(lwObject* object, float smoothAngle);
