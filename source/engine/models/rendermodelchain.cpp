#include "models/rendermodelchain.h"

#include "idlib/filesystem/file.h"
#include "models/static/staticmodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idRenderModelChain::UpdateCallback idRenderModelChain::updateCallback = nullptr;

idRenderModelChain::idRenderModelChain()
    : currentJointBuffer(0), currentMorphBuffer(0), numMorphVertices(0),
      numMorphLinkVertices(0), numLinks(0), linkSize(0.0f),
      morphMaterial(nullptr), reserved(0), updateJointBuffers(0),
      updateMorphBuffers(0) {
    std::memset(jointBuffers, 0, sizeof(jointBuffers));
    std::memset(morphBuffers, 0, sizeof(morphBuffers));
    genInfo = {};
    genInfo.rotateRandom = true;
}

void idRenderModelChain::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

bool idRenderModelChain::UpdateInView(const idRenderView* currentView,
    const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

int idRenderModelChain::GetNumLinks() const {
    return numLinks;
}

const idJointMat& idRenderModelChain::GetLinkPosition(const int link) const {
    static const idJointMat identity = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f
    };
    return link >= 0 && link < transforms.Num() ? transforms[link] : identity;
}

void idRenderModelChain::SetLinkPosition(const int link,
        const idVec3& origin, const idMat3& axis) {
    if (link < 0 || link >= transforms.Num()) return;
    idJointMat& transform = transforms[link];
    transform.mat[0] = axis[0].x;
    transform.mat[1] = axis[1].x;
    transform.mat[2] = axis[2].x;
    transform.mat[3] = origin.x;
    transform.mat[4] = axis[0].y;
    transform.mat[5] = axis[1].y;
    transform.mat[6] = axis[2].y;
    transform.mat[7] = origin.y;
    transform.mat[8] = axis[0].z;
    transform.mat[9] = axis[1].z;
    transform.mat[10] = axis[2].z;
    transform.mat[11] = origin.z;
    updateJointBuffers = 1;
}

void idRenderModelChain::SetLinkMorphAmount(const int link,
        const float amount) {
    if (link < 0 || link >= numLinks || numMorphLinkVertices <= 0 ||
        morphMap.Num() < 4 * numMorphLinkVertices * numLinks) return;
    const int encoded = (std::max)(0, (std::min)(255,
        static_cast<int>(amount * 255.89999f)));
    const int base = 4 * numMorphLinkVertices * link;
    for (int vertex = 0; vertex < numMorphLinkVertices; ++vertex)
        morphMap[base + vertex * 4 + 3] =
            static_cast<unsigned char>(encoded);
    updateMorphBuffers = 1;
}

void idRenderModelChain::RemoveSmoothSkinning(const int link) {
    if (link < 0 || link + 1 >= transforms.Num()) return;
    // Smooth-skin removal in the original edits packed joint weights in the
    // renderer vertex buffer. Preserve the observable link spacing and mark
    // the morph/geometry data dirty for the renderer adapter.
    updateMorphBuffers = 1;
}

bool idRenderModelChain::CommitSubclass() {
    if (updateJointBuffers != 0 && transforms.Num() > 0) {
        referenceBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        referenceBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        for (int link = 0; link < transforms.Num(); ++link) {
            const idVec3 point(transforms[link].mat[3],
                transforms[link].mat[7], transforms[link].mat[11]);
            for (int axis = 0; axis < 3; ++axis) {
                referenceBounds[0][axis] = (std::min)(
                    referenceBounds[0][axis], point[axis] - 8.0f);
                referenceBounds[1][axis] = (std::max)(
                    referenceBounds[1][axis], point[axis] + 8.0f);
            }
        }
        currentJointBuffer ^= 1;
        updateJointBuffers = 0;
    }
    if (updateMorphBuffers != 0) {
        currentMorphBuffer ^= 1;
        updateMorphBuffers = 0;
    }
    return true;
}

void idRenderModelChain::Save(idFile* file) {
    idRenderModel::Save(file);
    if (file == nullptr) return;
    const bool hasMorphMaterial = morphMaterial != nullptr;
    file->Write(&hasMorphMaterial, 1);
    if (hasMorphMaterial)
        file->WriteString(idStaticModel::MaterialName(morphMaterial));
    file->WriteString(chainLinkModel.c_str());
    const int splineCount = splineSettings.Num();
    file->Write(&splineCount, 4);
    for (int index = 0; index < splineCount; ++index)
        file->Write(&splineSettings[index], sizeof(splinePoint_t));
    file->Write(&genInfo.rotateRandom, 1);
    file->Write(&genInfo.smoothSkinning, 1);
    file->Write(&genInfo.startRotation, 4);
    file->Write(&numLinks, 4);
    for (int link = 0; link < numLinks; ++link) {
        const idJointMat& transform = transforms[link];
        const float axis[9] = {
            transform.mat[0], transform.mat[4], transform.mat[8],
            transform.mat[1], transform.mat[5], transform.mat[9],
            transform.mat[2], transform.mat[6], transform.mat[10]
        };
        const float origin[3] = {transform.mat[3], transform.mat[7],
            transform.mat[11]};
        file->Write(axis, sizeof(axis));
        file->Write(origin, sizeof(origin));
    }
    const bool hasMorph = numMorphVertices != 0;
    file->Write(&hasMorph, 1);
    if (hasMorph && numMorphLinkVertices > 0) {
        for (int link = 0; link < numLinks; ++link) {
            const unsigned char value = morphMap[
                4 * link * numMorphLinkVertices + 3];
            file->Write(&value, 1);
        }
    }
}

bool idRenderModelChain::Load(idFile* file) {
    if (file == nullptr) return false;
    idRenderModel::Load(file);
    bool hasMorphMaterial = false;
    idStr materialName;
    if (file->Read(&hasMorphMaterial, 1) != 1) return false;
    if (hasMorphMaterial && file->ReadString(materialName) <= 0) return false;
    morphMaterial = hasMorphMaterial
        ? idStaticModel::ResolveMaterial(materialName.c_str()) : nullptr;
    if (file->ReadString(chainLinkModel) <= 0) return false;
    int splineCount = 0;
    if (file->Read(&splineCount, 4) != 4 || splineCount < 0 ||
        splineCount > (1 << 20) || !splineSettings.SetNum(splineCount))
        return false;
    for (int index = 0; index < splineCount; ++index)
        if (file->Read(&splineSettings[index], sizeof(splinePoint_t)) !=
                sizeof(splinePoint_t)) return false;
    if (file->Read(&genInfo.rotateRandom, 1) != 1 ||
        file->Read(&genInfo.smoothSkinning, 1) != 1 ||
        file->Read(&genInfo.startRotation, 4) != 4 ||
        file->Read(&numLinks, 4) != 4 || numLinks < 0 ||
        numLinks > (1 << 16) || !transforms.SetNum(numLinks)) return false;
    for (int link = 0; link < numLinks; ++link) {
        float axisValues[9], origin[3];
        if (file->Read(axisValues, sizeof(axisValues)) != sizeof(axisValues) ||
            file->Read(origin, sizeof(origin)) != sizeof(origin)) return false;
        const idMat3 axis(axisValues[0], axisValues[3], axisValues[6],
            axisValues[1], axisValues[4], axisValues[7],
            axisValues[2], axisValues[5], axisValues[8]);
        SetLinkPosition(link, idVec3(origin[0], origin[1], origin[2]), axis);
    }
    bool hasMorph = false;
    if (file->Read(&hasMorph, 1) != 1) return false;
    if (hasMorph && numMorphLinkVertices > 0) {
        for (int link = 0; link < numLinks; ++link) {
            unsigned char value = 0;
            if (file->Read(&value, 1) != 1) return false;
            SetLinkMorphAmount(link, value * (1.0f / 255.0f));
        }
    }
    updateJointBuffers = 1;
    return true;
}

void idRenderModelChain::BuildModel(
        const idCurve_NURBS<idVec3>& spline) {
    splineSettings.Clear();
    for (int index = 0; index < spline.GetNumValues(); ++index) {
        splinePoint_t point;
        point.value = spline.GetValue(index);
        point.time = spline.GetTime(index);
        splineSettings.Append(point);
    }
    if (splineSettings.Num() == 0) {
        numLinks = 0;
        transforms.Clear();
        return;
    }
    float totalLength = 0.0f;
    for (int index = 1; index < splineSettings.Num(); ++index)
        totalLength += (splineSettings[index].value -
            splineSettings[index - 1].value).Length();
    if (linkSize <= 0.0f) linkSize = 8.0f;
    numLinks = (std::max)(1,
        static_cast<int>(std::ceil(totalLength / linkSize)) + 1);
    transforms.SetNum(numLinks);

    for (int link = 0; link < numLinks; ++link) {
        const float target = numLinks > 1
            ? totalLength * link / static_cast<float>(numLinks - 1) : 0.0f;
        float traversed = 0.0f;
        int segment = 0;
        while (segment + 1 < splineSettings.Num()) {
            const float segmentLength = (splineSettings[segment + 1].value -
                splineSettings[segment].value).Length();
            if (traversed + segmentLength >= target) break;
            traversed += segmentLength;
            ++segment;
        }
        const int next = (std::min)(segment + 1,
            splineSettings.Num() - 1);
        const idVec3 delta = splineSettings[next].value -
            splineSettings[segment].value;
        const float segmentLength = delta.Length();
        const float fraction = segmentLength > 1.0e-6f
            ? (target - traversed) / segmentLength : 0.0f;
        const idVec3 origin = splineSettings[segment].value +
            delta * fraction;
        idVec3 forward = delta;
        if (forward.NormalizeFast() == 0.0f)
            forward.Set(1.0f, 0.0f, 0.0f);
        idVec3 up(0.0f, 0.0f, 1.0f);
        if (std::fabs(forward.Dot(up)) > 0.99f) up.Set(0.0f, 1.0f, 0.0f);
        idVec3 side = up.Cross(forward);
        side.NormalizeFast();
        up = forward.Cross(side);
        up.NormalizeFast();
        SetLinkPosition(link, origin, idMat3(
            forward.x, side.x, up.x,
            forward.y, side.y, up.y,
            forward.z, side.z, up.z));
    }
}

void idRenderModelChain::Build(const chainGenerateInfo_t& generateInfo,
        const idStr& linkModel, const idMaterial* material,
        const idCurve_NURBS<idVec3>& spline) {
    genInfo = generateInfo;
    chainLinkModel = linkModel;
    morphMaterial = material;
    linkSize = 8.0f;
    if (idResource* resource = idStaticModel::resourceList.Load(
            linkModel.c_str(), false)) {
        const idStaticModel* staticModel =
            static_cast<const idStaticModel*>(resource);
        const float extent = staticModel->referenceBounds[1].x -
            staticModel->referenceBounds[0].x;
        if (extent > 0.0f) linkSize = extent;
    }
    BuildModel(spline);
    updateJointBuffers = 1;
}
