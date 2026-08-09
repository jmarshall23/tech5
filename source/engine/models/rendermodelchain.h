#pragma once

#include "idlib/geometry/jointtransform.h"
#include "idlib/math/curve.h"
#include "models/rendermodel.h"

template<class type_t>
class idCurve_NURBS : public idCurve_Spline<type_t> {
};

struct chainGenerateInfo_t {
    bool rotateRandom;
    bool smoothSkinning;
    float startRotation;
};

class alignas(16) idRenderModelChain : public idRenderModel {
public:
    struct splinePoint_t {
        idVec3 value;
        float time;
    };

    using UpdateCallback = bool (*)(idRenderModelChain* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);

    idRenderModelChain();
    ~idRenderModelChain() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    bool CommitSubclass() override;
    void Save(idFile* file) override;
    bool Load(idFile* file) override;

    int GetNumLinks() const;
    const idJointMat& GetLinkPosition(int link) const;
    void SetLinkPosition(int link, const idVec3& origin,
        const idMat3& axis);
    void SetLinkMorphAmount(int link, float amount);
    void RemoveSmoothSkinning(int link);
    void Build(const chainGenerateInfo_t& generateInfo,
        const idStr& linkModel, const idMaterial* material,
        const idCurve_NURBS<idVec3>& spline);

    idJointBuffer jointBuffers[2];
    idVertexBuffer morphBuffers[2];
    int currentJointBuffer;
    int currentMorphBuffer;
    int numMorphVertices;
    int numMorphLinkVertices;
    int numLinks;
    float linkSize;
    idList<idJointMat, 85> transforms;
    idList<unsigned char, 85> morphMap;
    idList<splinePoint_t, 85> splineSettings;
    idStr chainLinkModel;
    const idMaterial* morphMaterial;
    std::uint8_t reserved : 6;
    std::uint8_t updateJointBuffers : 1;
    std::uint8_t updateMorphBuffers : 1;
    chainGenerateInfo_t genInfo;

private:
    void BuildModel(const idCurve_NURBS<idVec3>& spline);
    static UpdateCallback updateCallback;
};

static_assert(sizeof(idRenderModelChain::splinePoint_t) == 16,
    "Recovered chain spline-point ABI changed");
static_assert(sizeof(chainGenerateInfo_t) == 8,
    "Recovered chain generation-info ABI changed");
