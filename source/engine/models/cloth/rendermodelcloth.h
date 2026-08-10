#pragma once

#include "models/cloth/clothsim.h"
#include "models/rendermodel.h"

class idDeclCloth;
class idParallelJobList;

class alignas(16) idRenderModelCloth : public idRenderModel {
public:
    enum idClothType_t : int {
        CLOTH_INVALID = 0,
        CLOTH_GENERATED,
        CLOTH_FLAG_SQUARE,
        CLOTH_FLAG_TRIANGLE,
        CLOTH_TARP_SQUARE,
        CLOTH_TARP_TRIANGLE,
        MAX_CLOTH_TYPE
    };

    struct alignas(4) clothAttachInfo_t {
        enum idClothAnchorType_t : int {
            ANCHOR_INVALID = 0,
            ANCHOR_CORNER1,
            ANCHOR_CORNER2,
            ANCHOR_CORNER3,
            ANCHOR_CORNER4,
            ANCHOR_MID1,
            ANCHOR_MID2,
            ANCHOR_MID3,
            ANCHOR_MID4,
            ANCHOR_CENTER,
            ANCHOR_DEFINED,
            MAX_ANCHOR_TYPE
        };

        idVec3 point;
        idClothAnchorType_t clothAnchorType;
        int row;
        int col;
        bool tempAnchor;
    };

    using UpdateCallback = bool (*)(idRenderModelCloth* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using ClothResolver = const idDeclCloth* (*)(const char* name,
        bool makeDefault);
    using BuildCallback = void (*)(idRenderModelCloth* model,
        const idDrawVert* vertices, int numVertices,
        const std::uint16_t* indexes, int numIndexes,
        const idMaterial* material);
    using SerializeCallback = void (*)(idRenderModelCloth* model,
        idSerializer* serializer, bool writing);
    using JobSubmitCallback = bool (*)(idParallelJobList* jobList,
        clothParms_t* parameters);

    idRenderModelCloth();
    explicit idRenderModelCloth(const idDeclCloth* clothSystem);
    ~idRenderModelCloth() override;
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetClothResolver(ClothResolver resolver);
    static void SetBuildCallback(BuildCallback callback);
    static void SetSerializeCallback(SerializeCallback callback);
    static void SetJobSubmitCallback(JobSubmitCallback callback);
    void Save(idFile* file) override;
    bool Load(idFile* file) override;
    void SerializeSnapshot(idSerializer* serializer, bool writing) override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    void CreateClothSim(const idDeclCloth* clothDecl,
        idClothType_t type, const idList<clothAttachInfo_t, 5>& attachments,
        const idList<idVec4, 5>& spheres, int widthOverride = 0,
        int heightOverride = 0, float horizontalSpacingOverride = 0.0f,
        float verticalSpacingOverride = 0.0f);
    void BuildClothModel();

    idClothSim* clothSimulation;
    idVertexBuffer vertexBuffer[3];
    idIndexBuffer indexBuffer;
    idDrawVert* deferredVerts;
    int numVerts;
    int currentIndex;
    idBounds* clothBounds;
    clothParms_t* clothParms;
    bool rect;
    const idDeclCloth* clothSystem;
    idClothType_t clothType;
    idList<clothAttachInfo_t, 5> attachPoints;
    idList<idVec4, 5> collisionSpheres;
    int width;
    int height;
    float vSpacing;
    float hSpacing;

private:
    void SetupClothJob(idParallelJobList* parallelJobList,
        idDrawVert* vertices);
    static UpdateCallback updateCallback;
    static ClothResolver clothResolver;
    static BuildCallback buildCallback;
    static SerializeCallback serializeCallback;
    static JobSubmitCallback jobSubmitCallback;
};

static_assert(sizeof(idRenderModelCloth::clothAttachInfo_t) == 28,
    "Recovered cloth attachment ABI changed");
