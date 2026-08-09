#include "models/skeletalanimation/md6util.h"

#include "decls/animwebs/declanimweb.h"
#include "decls/animwebs/declanimwebnode.h"
#include "gamelib/animstack/animweb/animwebpath.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6anim.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

idMD6Util::WebResolverCallback idMD6Util::webResolverCallback = nullptr;
idMD6Util::AnimResolverCallback idMD6Util::animResolverCallback = nullptr;
idMD6Util::JointIndexCallback idMD6Util::jointIndexCallback = nullptr;
idMD6Util::PoseDecodeCallback idMD6Util::poseDecodeCallback = nullptr;

namespace {

idQuat InverseUnitQuat(const idQuat& quat) {
    const float lengthSqr = quat.x * quat.x + quat.y * quat.y +
        quat.z * quat.z + quat.w * quat.w;
    if (lengthSqr <= 1.0e-20f) return idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    const float inverse = 1.0f / lengthSqr;
    return idQuat(-quat.x * inverse, -quat.y * inverse,
        -quat.z * inverse, quat.w * inverse);
}

idQuat MultiplyQuat(const idQuat& left, const idQuat& right) {
    return idQuat(
        left.w * right.x + left.x * right.w + left.y * right.z -
            left.z * right.y,
        left.w * right.y - left.x * right.z + left.y * right.w +
            left.z * right.x,
        left.w * right.z + left.x * right.y - left.y * right.x +
            left.z * right.w,
        left.w * right.w - left.x * right.x - left.y * right.y -
            left.z * right.z);
}

idVec3 RotateVector(const idQuat& quat, const idVec3& vector) {
    const idQuat pure(vector.x, vector.y, vector.z, 0.0f);
    const idQuat rotated = MultiplyQuat(MultiplyQuat(quat, pure),
        InverseUnitQuat(quat));
    return idVec3(rotated.x, rotated.y, rotated.z);
}

idMat3 JointAxis(const idJointMat& joint) {
    return idMat3(joint.mat[0], joint.mat[1], joint.mat[2],
        joint.mat[4], joint.mat[5], joint.mat[6],
        joint.mat[8], joint.mat[9], joint.mat[10]);
}

idVec3 JointTranslation(const idJointMat& joint) {
    return idVec3(joint.mat[3], joint.mat[7], joint.mat[11]);
}

void SplitPath(const idAnimWebPath& path, idStr& webName,
        idStr& subWebName, idStr& stateName) {
    const char* text = path.c_str();
    const char* first = std::strchr(text, '/');
    const char* second = first != nullptr ? std::strchr(first + 1, '/') : nullptr;
    if (first == nullptr) {
        webName = "";
        subWebName = "";
        stateName = text;
        return;
    }
    const std::string webPart(text, static_cast<std::size_t>(first - text));
    webName = webPart.c_str();
    if (second == nullptr) {
        subWebName = "";
        stateName = first + 1;
        return;
    }
    const std::string subWebPart(first + 1,
        static_cast<std::size_t>(second - first - 1));
    subWebName = subWebPart.c_str();
    stateName = second + 1;
}

} // namespace

void idMD6Util::SetCallbacks(WebResolverCallback webResolver,
        AnimResolverCallback animResolver, JointIndexCallback jointIndex,
        PoseDecodeCallback poseDecoder) {
    webResolverCallback = webResolver;
    animResolverCallback = animResolver;
    jointIndexCallback = jointIndex;
    poseDecodeCallback = poseDecoder;
}

const idMD6Anim* idMD6Util::FindMD6Anim(const idDeclAnimWeb* web,
        const idAnimWebPath& webPath, const idDeclMD6* declaration,
        idAnimWebModelIndex modelIndex, const bool loadAnimation) {
    if (animResolverCallback != nullptr)
        return animResolverCallback(web, webPath, declaration, modelIndex,
            loadAnimation);

    idStr webName, subWebName, stateName;
    SplitPath(webPath, webName, subWebName, stateName);
    if (web == nullptr && webResolverCallback != nullptr)
        web = webResolverCallback(webName.c_str());
    if (web == nullptr) return nullptr;
    if (declaration == nullptr && web->models.Num() > 0)
        declaration = web->models[0];
    if (!modelIndex.IsValid()) modelIndex = idAnimWebModelIndex(0);
    const idAnimWebNodeIndex nodeIndex = web->GetNodeIndexForName(
        subWebName.c_str(), stateName.c_str());
    if (!nodeIndex.IsValid() || nodeIndex.Get() >= web->nodes.Num())
        return nullptr;
    const idDeclAnimWebNode* node = web->nodes[nodeIndex.Get()];
    if (node == nullptr) return nullptr;
    const idDeclAnimWebNode::idModelInfo* model =
        node->FindModelInfo(modelIndex);
    if (model == nullptr || model->animProps.Num() == 0) return nullptr;
    return loadAnimation
        ? model->animProps[0].SelectAndLoadAnim(declaration, 0)
        : model->animProps[0].SelectAnim(declaration, 0);
}

bool idMD6Util::GetAnimDelta(const idMD6Anim* animation,
        idVec3* deltaOrigin, idMat3* deltaAxis) {
    if (animation == nullptr || animation->animData == nullptr) return false;
    const float* start = animation->animData->startDelta;
    const float* end = animation->animData->endDelta;
    const idQuat startRotation(start[0], start[1], start[2], start[3]);
    const idQuat endRotation(end[0], end[1], end[2], end[3]);
    const idQuat inverseStart = InverseUnitQuat(startRotation);
    if (deltaAxis != nullptr)
        *deltaAxis = MultiplyQuat(endRotation, inverseStart).ToMat3();
    if (deltaOrigin != nullptr) {
        const idVec3 translation(end[8] - start[8], end[9] - start[9],
            end[10] - start[10]);
        *deltaOrigin = RotateVector(inverseStart, translation);
    }
    return true;
}

idMD6Util::idJointCache::idJointCache(const idDeclMD6* declaration,
        const idMD6Anim* animation, const int frame)
    : webRef(nullptr), md6Decl(declaration), md6anim(animation), frameNum(frame),
      validJointCache(false) {
    std::memset(jointMatrices, 0, sizeof(jointMatrices));
    if (md6anim != nullptr) {
        if (frameNum == FRAME_LAST && md6anim->animData != nullptr)
            frameNum = md6anim->animData->numFrames - 1;
        UpdateCache();
    }
}

idMD6Util::idJointCache::idJointCache(const idAnimWebPath& webPath,
        const int frame)
    : webRef(nullptr), md6Decl(nullptr), md6anim(nullptr), frameNum(frame),
      validJointCache(false) {
    std::memset(jointMatrices, 0, sizeof(jointMatrices));
    idStr webName, subWebName, stateName;
    SplitPath(webPath, webName, subWebName, stateName);
    const idDeclAnimWeb* web = webResolverCallback != nullptr
        ? webResolverCallback(webName.c_str()) : nullptr;
    Set(web, webPath, frame);
}

void idMD6Util::idJointCache::Set(const idDeclAnimWeb* web,
        const idAnimWebPath& webPath, const int frame) {
    webRef = web;
    md6Decl = web != nullptr && web->models.Num() > 0 ? web->models[0] : nullptr;
    md6anim = FindMD6Anim(web, webPath, md6Decl, idAnimWebModelIndex(0), false);
    frameNum = frame;
    validJointCache = false;
    if (md6anim != nullptr) {
        if (frameNum == FRAME_LAST && md6anim->animData != nullptr)
            frameNum = md6anim->animData->numFrames - 1;
        UpdateCache();
    }
}

void idMD6Util::idJointCache::UpdateCache() {
    validJointCache = false;
    if (md6Decl == nullptr || md6anim == nullptr ||
            md6anim->animData == nullptr || poseDecodeCallback == nullptr ||
            frameNum < 0 || frameNum >= md6anim->animData->numFrames) return;
    validJointCache = poseDecodeCallback(md6Decl, md6anim, frameNum,
        jointMatrices, 256);
}

bool idMD6Util::idJointCache::GetDelta(animDelta_t& delta,
        const char* jointName, const char* refJointName) const {
    if (!validJointCache || md6Decl == nullptr || jointIndexCallback == nullptr ||
            jointName == nullptr || refJointName == nullptr) return false;
    const int joint = jointIndexCallback(md6Decl, jointName);
    const int reference = jointIndexCallback(md6Decl, refJointName);
    if (joint < 0 || joint >= 256 || reference < 0 || reference >= 256)
        return false;
    delta.deltaTranslation = JointTranslation(jointMatrices[joint]);
    delta.deltaAxis = JointAxis(jointMatrices[joint]);
    if (joint != reference) {
        delta.deltaTranslation = delta.deltaTranslation -
            JointTranslation(jointMatrices[reference]);
        delta.deltaAxis = JointAxis(jointMatrices[reference]).Transpose() *
            delta.deltaAxis;
    }
    return true;
}
