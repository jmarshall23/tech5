#include "models/skeletalanimation/treeanimator.h"

#include "idlib/filesystem/file.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6allocator.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6mesh.h"
#include "models/skeletalanimation/md6model.h"
#include "network/serializer.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <malloc.h>
#include <new>
#include <vector>

namespace {

constexpr int MAX_TREE_COMMANDS = 128;

int Pad8(const int value) {
    return (value + 7) & ~7;
}

bool ReadExact(idFile* const file, void* const data,
        const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteExact(idFile* const file, const void* const data,
        const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

idVec3 JointOrigin(const idJointMat& joint) {
    return idVec3(joint.mat[3], joint.mat[7], joint.mat[11]);
}

idMat3 JointAxis(const idJointMat& joint) {
    return idMat3(
        joint.mat[0], joint.mat[4], joint.mat[8],
        joint.mat[1], joint.mat[5], joint.mat[9],
        joint.mat[2], joint.mat[6], joint.mat[10]);
}

void SetJointAxis(idJointMat& joint, const idMat3& axis) {
    joint.mat[0] = axis[0].x;
    joint.mat[1] = axis[1].x;
    joint.mat[2] = axis[2].x;
    joint.mat[4] = axis[0].y;
    joint.mat[5] = axis[1].y;
    joint.mat[6] = axis[2].y;
    joint.mat[8] = axis[0].z;
    joint.mat[9] = axis[1].z;
    joint.mat[10] = axis[2].z;
}

void IdentityJoint(idJointMat& joint) {
    std::memset(&joint, 0, sizeof(joint));
    joint.mat[0] = joint.mat[5] = joint.mat[10] = 1.0f;
}

idQuat MatrixQuat(const idMat3& matrix) {
    idQuat result;
    const float trace = matrix[0].x + matrix[1].y + matrix[2].z;
    if (trace > 0.0f) {
        const float root = std::sqrt(trace + 1.0f);
        result.w = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.x = (matrix[2].y - matrix[1].z) * factor;
        result.y = (matrix[0].z - matrix[2].x) * factor;
        result.z = (matrix[1].x - matrix[0].y) * factor;
    } else {
        const int next[3] = { 1, 2, 0 };
        int i = matrix[1].y > matrix[0].x ? 1 : 0;
        if (matrix[2].z > matrix[i][i]) i = 2;
        const int j = next[i];
        const int k = next[j];
        const float root = std::sqrt((std::max)(0.0f,
            matrix[i][i] - matrix[j][j] - matrix[k][k] + 1.0f));
        result[i] = 0.5f * root;
        const float factor = root > 0.0f ? 0.5f / root : 0.0f;
        result.w = (matrix[k][j] - matrix[j][k]) * factor;
        result[j] = (matrix[j][i] + matrix[i][j]) * factor;
        result[k] = (matrix[k][i] + matrix[i][k]) * factor;
    }
    return result.Normalize();
}

idQuat MultiplyQuat(const idQuat& first, const idQuat& second) {
    idQuat result(
        first.w * second.x + first.x * second.w + first.y * second.z -
            first.z * second.y,
        first.w * second.y - first.x * second.z + first.y * second.w +
            first.z * second.x,
        first.w * second.z + first.x * second.y - first.y * second.x +
            first.z * second.w,
        first.w * second.w - first.x * second.x - first.y * second.y -
            first.z * second.z);
    return result.Normalize();
}

idQuat InverseQuat(const idQuat& value) {
    return idQuat(-value.x, -value.y, -value.z, value.w);
}

idVec3 ScaleVector(const idVec3& value, const idVec3& scale) {
    return idVec3(value.x * scale.x, value.y * scale.y,
        value.z * scale.z);
}

bool IsBranch(const idMD6Node* const node) {
    if (node == nullptr) return false;
    return node->type == idMD6Node::NODE_BRANCH ||
        node->type == idMD6Node::NODE_BLEND_BRANCH ||
        node->type == idMD6Node::NODE_BLENDA_BRANCH ||
        node->type == idMD6Node::NODE_FUSION_BRANCH;
}

const idMD6Model* TreeModel(const idTreeAnimator& animator) {
    return animator.decl != nullptr ? animator.decl->model : nullptr;
}

const idMD6Skel* TreeSkeleton(const idTreeAnimator& animator) {
    const idMD6Model* const model = TreeModel(animator);
    return model != nullptr ? model->skeleton : nullptr;
}

int TreeJointCount(const idTreeAnimator& animator) {
    const idMD6Skel* const skeleton = TreeSkeleton(animator);
    return skeleton != nullptr && skeleton->data != nullptr
        ? skeleton->data->numJoints : 0;
}

idMD6Blend::jointMod_t MakeJointMod(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const std::uint16_t componentFlags) {
    idMD6Blend::jointMod_t modifier{};
    modifier.joint = joint;
    modifier.flags = static_cast<std::uint16_t>(
        idMD6Blend::POSE_FINAL | componentFlags);
    if (pose == 0) modifier.flags |= idMD6Blend::POSE_REFERENCE;
    if (transform == JOINTMOD_MODEL || transform == JOINTMOD_MODEL_OVERRIDE)
        modifier.flags |= idMD6Blend::DRIVER_MODEL;
    if (transform == JOINTMOD_LOCAL_OVERRIDE ||
            transform == JOINTMOD_MODEL_OVERRIDE)
        modifier.flags |= idMD6Blend::DRIVER_OVERRIDE;
    modifier.s[0] = modifier.s[1] = modifier.s[2] = 1.0f;
    modifier.mat[0] = modifier.mat[5] = modifier.mat[10] = 1.0f;
    return modifier;
}

} // namespace

idTreeAnimator::UpdateCallback idTreeAnimator::updateCallback = nullptr;
idTreeAnimator::CommitCallback idTreeAnimator::commitCallback = nullptr;
idTreeAnimator::AnimationResolver idTreeAnimator::animationResolverCallback = nullptr;
idTreeAnimator::SkinsResolver idTreeAnimator::skinsResolverCallback = nullptr;
idTreeAnimator::SkinIndexCallback idTreeAnimator::skinIndexCallback = nullptr;
idTreeAnimator::BufferSyncCallback idTreeAnimator::bufferSyncCallback = nullptr;
idTreeAnimator::MorphBufferCallback idTreeAnimator::morphBufferCallback = nullptr;
idTreeAnimator::TreeStoreCallback idTreeAnimator::treeStoreCallback = nullptr;
idTreeAnimator::TreeReadCallback idTreeAnimator::treeReadCallback = nullptr;

idTreeAnimator::idTreeAnimator(const idDeclMD6* const declaration)
    : decl(declaration), morphSkin(-1), skipJointForBounds(),
      initialMorphValue(0.0f), currentDeferred(0), commands(nullptr),
      blendParms(nullptr), lastBlendTime(-1), reserved(0),
      useDualQuatSkinning(0), skipSerialization(0), updateMorphBuffers(0),
      calcRefBoundsFromJoints(0), originDeltaLookAhead(0),
      clearOriginTransform(1), hasDeferredJoints(0),
      deferredJobJointBuffer(-1), nextRenderThreadJointBuffer(0),
      renderThreadJointBuffer(0), currentMorphBuffer(0) {
    std::memset(joints, 0, sizeof(joints));
    std::memset(originDelta, 0, sizeof(originDelta));
    frameBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    frameBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    normalizedBounds = frameBounds;
    translatedBounds = frameBounds;
    useDeferredPosition = true;
    g.castDimShadows = DIMSHADOW_ON;

    originDelta[0] = new (std::nothrow) md6OriginDelta_t;
    originDelta[1] = new (std::nothrow) md6OriginDelta_t;
    if (originDelta[0] != nullptr) originDelta[0]->done = true;
    if (originDelta[0] != nullptr && originDelta[1] != nullptr)
        *originDelta[1] = *originDelta[0];
    blendParms = new (std::nothrow) idMD6Blend::blendParms_t{};
    if (blendParms != nullptr) blendParms->originDelta = originDelta[0];
    commands = new (std::nothrow) md6AnimCommand_t[MAX_TREE_COMMANDS]{};
    if (commands != nullptr) {
        for (int index = 0; index < MAX_TREE_COMMANDS; ++index)
            commands[index].op = md6AnimCommand_t::OP_END;
    }

    const idMD6Model* const model = TreeModel(*this);
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    const int numJoints = TreeJointCount(*this);
    if (declaration != nullptr) {
        idStr modelName(declaration->GetName());
        modelName.SetFileExtension(".md6");
        SetName(modelName.c_str());
        referenceBounds = declaration->referenceBounds;
        frameBounds = normalizedBounds = translatedBounds = referenceBounds;
        calcRefBoundsFromJoints = declaration->calcRefBoundsFromJoints;
    }
    if (model == nullptr || skeleton == nullptr || skeleton->data == nullptr ||
            numJoints <= 0) {
        return;
    }

    const int paddedJoints = Pad8(numJoints);
    for (idJointMat*& pose : joints) {
        pose = new (std::nothrow) idJointMat[paddedJoints];
        if (pose != nullptr) {
            for (int joint = 0; joint < paddedJoints; ++joint)
                IdentityJoint(pose[joint]);
        }
    }
    const int paddedChannels = Pad8(skeleton->data->numUserChannels);
    for (idList<float, 17>& channels : userChannels) {
        channels.SetNum(paddedChannels);
        for (int index = 0; index < channels.Num(); ++index)
            channels[index] = 0.0f;
    }

    if (joints[JOINTS_GAME_REFERENCE] != nullptr) {
        std::vector<unsigned char> scratch(16384);
        const float zeroOffset[4] = {};
        const float* const visualOffset = declaration != nullptr &&
            declaration->config != nullptr
                ? declaration->config->visualOffset : zeroOffset;
        idMD6Blend::DecodeBasePose(skeleton->data, scratch.data(),
            static_cast<unsigned int>(scratch.size()), visualOffset, true,
            joints[JOINTS_GAME_REFERENCE]->mat);
        const unsigned int poseBytes = paddedJoints * sizeof(idJointMat);
        for (int pose = 1; pose < NUM_JOINT_ARRAYS; ++pose) {
            if (joints[pose] != nullptr)
                std::memcpy(joints[pose], joints[JOINTS_GAME_REFERENCE],
                    poseBytes);
        }
    }
    for (idJointBuffer& buffer : jointBuffers) {
        buffer.numJoints = paddedJoints;
        buffer.offsetInOtherBuffer = 0;
        buffer.apiObject = nullptr;
        buffer.flags = useDualQuatSkinning != 0;
    }

    meshVisibility.SetNum(model->meshes.Num());
    for (int index = 0; index < meshVisibility.Num(); ++index)
        meshVisibility[index] = true;
    for (int component = 0; component < MESH_KIT_NUM; ++component)
        HideKitsExcept(static_cast<meshKitComponents_t>(component),
            declaration->meshKitDefault[component].c_str());
    HideAllKits(MESH_KIT_GORE);
    morphSkin = model->morphSkin;
    InitializeSurfaces();
    InitializeMorphMaps();
}

idTreeAnimator::~idTreeAnimator() {
    FreeSurfaces();
    FreeMorphMaps();
    for (idJointMat*& pose : joints) {
        delete[] pose;
        pose = nullptr;
    }
    delete originDelta[0];
    delete originDelta[1];
    originDelta[0] = originDelta[1] = nullptr;
    delete blendParms;
    blendParms = nullptr;
    delete[] commands;
    commands = nullptr;
}

void idTreeAnimator::SetUpdateCallback(const UpdateCallback callback) {
    updateCallback = callback;
}

void idTreeAnimator::SetCommitCallback(const CommitCallback callback) {
    commitCallback = callback;
}

void idTreeAnimator::SetRuntimeCallbacks(
        const AnimationResolver animationResolver,
        const SkinsResolver skinsResolver, const SkinIndexCallback skinIndex,
        const BufferSyncCallback bufferSync,
        const MorphBufferCallback morphBuffer) {
    animationResolverCallback = animationResolver;
    skinsResolverCallback = skinsResolver;
    skinIndexCallback = skinIndex;
    bufferSyncCallback = bufferSync;
    morphBufferCallback = morphBuffer;
}

void idTreeAnimator::SetTreePersistenceCallbacks(
        const TreeStoreCallback store, const TreeReadCallback read) {
    treeStoreCallback = store;
    treeReadCallback = read;
}

void idTreeAnimator::Save(idFile* const file) {
    idRenderModel::Save(file);
    const int jointBytes = Pad8(NumJoints()) * sizeof(idJointMat);
    const std::uint8_t deferred = hasDeferredJoints != 0;
    const std::uint8_t removeOrigin = clearOriginTransform != 0;
    const std::uint8_t lookAhead = originDeltaLookAhead != 0;
    const std::uint8_t calcBounds = calcRefBoundsFromJoints != 0;
    const int visibilityCount = meshVisibility.Num();
    WriteExact(file, &lastBlendTime, sizeof(lastBlendTime));
    WriteExact(file, &deferred, sizeof(deferred));
    WriteExact(file, &removeOrigin, sizeof(removeOrigin));
    WriteExact(file, &lookAhead, sizeof(lookAhead));
    WriteExact(file, &calcBounds, sizeof(calcBounds));
    WriteExact(file, &deferredJobJointBuffer,
        sizeof(deferredJobJointBuffer));
    WriteExact(file, &visibilityCount, sizeof(visibilityCount));
    WriteExact(file, meshVisibility.Ptr(), visibilityCount);
    WriteExact(file, &jointBytes, sizeof(jointBytes));
    WriteExact(file, joints[JOINTS_GAME_REFERENCE], jointBytes);
    WriteExact(file, joints[JOINTS_GAME_FINAL], jointBytes);
    WriteExact(file, &morphSkin, sizeof(morphSkin));
    WriteExact(file, &initialMorphValue, sizeof(initialMorphValue));
    WriteExact(file, &frameBounds, sizeof(frameBounds));
    WriteExact(file, &normalizedBounds, sizeof(normalizedBounds));
    WriteExact(file, &translatedBounds, sizeof(translatedBounds));
    WriteExact(file, &skipJointForBounds, sizeof(skipJointForBounds));
}

bool idTreeAnimator::Load(idFile* const file) {
    if (!idRenderModel::Load(file)) return false;
    const int expectedJointBytes = Pad8(NumJoints()) * sizeof(idJointMat);
    std::uint8_t deferred = 0;
    std::uint8_t removeOrigin = 0;
    std::uint8_t lookAhead = 0;
    std::uint8_t calcBounds = 0;
    int visibilityCount = 0;
    int storedJointBytes = 0;
    if (!ReadExact(file, &lastBlendTime, sizeof(lastBlendTime)) ||
        !ReadExact(file, &deferred, sizeof(deferred)) ||
        !ReadExact(file, &removeOrigin, sizeof(removeOrigin)) ||
        !ReadExact(file, &lookAhead, sizeof(lookAhead)) ||
        !ReadExact(file, &calcBounds, sizeof(calcBounds)) ||
        !ReadExact(file, &deferredJobJointBuffer,
            sizeof(deferredJobJointBuffer)) ||
        !ReadExact(file, &visibilityCount, sizeof(visibilityCount)) ||
        visibilityCount < 0 || visibilityCount > 4096 ||
        !meshVisibility.SetNum(visibilityCount) ||
        !ReadExact(file, meshVisibility.Ptr(), visibilityCount) ||
        !ReadExact(file, &storedJointBytes, sizeof(storedJointBytes)) ||
        storedJointBytes != expectedJointBytes ||
        joints[JOINTS_GAME_REFERENCE] == nullptr ||
        joints[JOINTS_GAME_FINAL] == nullptr ||
        !ReadExact(file, joints[JOINTS_GAME_REFERENCE], expectedJointBytes) ||
        !ReadExact(file, joints[JOINTS_GAME_FINAL], expectedJointBytes) ||
        !ReadExact(file, &morphSkin, sizeof(morphSkin)) ||
        !ReadExact(file, &initialMorphValue, sizeof(initialMorphValue)) ||
        !ReadExact(file, &frameBounds, sizeof(frameBounds)) ||
        !ReadExact(file, &normalizedBounds, sizeof(normalizedBounds)) ||
        !ReadExact(file, &translatedBounds, sizeof(translatedBounds)) ||
        !ReadExact(file, &skipJointForBounds, sizeof(skipJointForBounds))) {
        return false;
    }
    hasDeferredJoints = deferred != 0;
    clearOriginTransform = removeOrigin != 0;
    originDeltaLookAhead = lookAhead != 0;
    calcRefBoundsFromJoints = calcBounds != 0;
    if (morphSkin != -1)
        SetMorphSkin(nullptr, morphSkin, initialMorphValue);
    if (joints[JOINTS_DEFERRED_REFERENCE] != nullptr)
        std::memcpy(joints[JOINTS_DEFERRED_REFERENCE],
            joints[JOINTS_GAME_REFERENCE], expectedJointBytes);
    if (joints[JOINTS_DEFERRED_FINAL] != nullptr)
        std::memcpy(joints[JOINTS_DEFERRED_FINAL],
            joints[JOINTS_GAME_FINAL], expectedJointBytes);
    SyncJoints(lastBlendTime);
    return true;
}

void idTreeAnimator::SerializeSnapshot(idSerializer* const serializer,
        const bool serializeParmBlock) {
    if (serializer == nullptr) return;
    bool skip = skipSerialization != 0;
    serializer->Serialize(skip);
    skipSerialization = skip;
    if (skip) return;
    idRenderModel::SerializeSnapshot(serializer, serializeParmBlock);
    bool removeOrigin = clearOriginTransform != 0;
    serializer->Serialize(removeOrigin);
    clearOriginTransform = removeOrigin;
    int count = meshVisibility.Num();
    serializer->SerializeUMax(count, 32);
    if (serializer->IsReading()) meshVisibility.SetNum(count);
    for (int index = 0; index < meshVisibility.Num(); ++index) {
        bool visible = meshVisibility[index];
        serializer->Serialize(visible);
        meshVisibility[index] = visible;
    }
    serializer->Serialize(morphSkin);
    if (serializer->IsReading() && morphSkin != -1)
        SetMorphSkin(nullptr, morphSkin, initialMorphValue);
}

idPropsCollection* idTreeAnimator::GetPropsCollection() {
    return decl != nullptr ? &const_cast<idDeclMD6*>(decl)->props : nullptr;
}

const idPropsCollection* idTreeAnimator::GetPropsCollection() const {
    return decl != nullptr ? &decl->props : nullptr;
}

const char* idTreeAnimator::GetModelDefName() const {
    return decl != nullptr ? decl->GetName() : "";
}

idJointGroupCollection* idTreeAnimator::GetJointGroupCollection() {
    return decl != nullptr
        ? &const_cast<idDeclMD6*>(decl)->jointGroupCollection : nullptr;
}

const idJointGroupCollection* idTreeAnimator::GetJointGroupCollection() const {
    return decl != nullptr ? &decl->jointGroupCollection : nullptr;
}

const idQuat& idTreeAnimator::GetLastOriginRotation() const {
    static const idQuat identity(0.0f, 0.0f, 0.0f, 1.0f);
    return originDelta[1] != nullptr
        ? *reinterpret_cast<const idQuat*>(originDelta[1]->animRotation)
        : identity;
}

const idVec3& idTreeAnimator::GetLastOriginTranslation() const {
    static const idVec3 zero(0.0f, 0.0f, 0.0f);
    return originDelta[1] != nullptr
        ? *reinterpret_cast<const idVec3*>(originDelta[1]->animTranslation)
        : zero;
}

bool idTreeAnimator::IsDeltaFudged() const {
    return originDelta[1] != nullptr && originDelta[1]->fudged;
}

int idTreeAnimator::GetLastOriginDeltaTime() const {
    return originDelta[1] != nullptr ? originDelta[1]->time : -1;
}

void idTreeAnimator::SetRemoveOriginRotation(const bool removeRotation) {
    clearOriginTransform = removeRotation;
}

bool idTreeAnimator::GetRemoveOriginTranslation() const {
    return clearOriginTransform != 0;
}

void idTreeAnimator::SetOriginDeltaLookAhead(const bool lookAhead) {
    originDeltaLookAhead = lookAhead;
}

void idTreeAnimator::GetJointList(const char* const jointNames,
        idList<idJointIndex, 5>& jointList) const {
    const idMD6Model* const model = TreeModel(*this);
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    if (model != nullptr && skeleton != nullptr)
        skeleton->GetJointList(model, jointNames, jointList);
}

void idTreeAnimator::ShowSkel() const {
    // Debug drawing is renderer-owned. Keeping this as a safe query point
    // preserves the original call surface without linking renderer globals.
}

void idTreeAnimator::CalcFrameBoundsFromJoints() {
    const int numJoints = NumJoints();
    if (numJoints <= 0 || joints[JOINTS_GAME_FINAL] == nullptr) return;
    frameBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    frameBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    const short* const parents = TreeSkeleton(*this)->ParentTable();
    for (int joint = 0; joint < numJoints; ++joint) {
        if (skipJointForBounds.IsValid()) {
            int ancestor = joint;
            while (ancestor >= 0) {
                if (ancestor == skipJointForBounds.Get()) break;
                ancestor = parents != nullptr ? parents[ancestor] : -1;
            }
            if (ancestor == skipJointForBounds.Get()) continue;
        }
        const idVec3 point = ScaleVector(
            JointOrigin(joints[JOINTS_GAME_FINAL][joint]), g.scale);
        for (int axis = 0; axis < 3; ++axis) {
            frameBounds[0][axis] = (std::min)(frameBounds[0][axis],
                point[axis]);
            frameBounds[1][axis] = (std::max)(frameBounds[1][axis],
                point[axis]);
        }
    }
    const idMD6Model* const model = TreeModel(*this);
    if (model != nullptr) {
        frameBounds[0] = frameBounds[0] + model->minBoundsExpansion;
        frameBounds[1] = frameBounds[1] + model->maxBoundsExpansion;
    }
    normalizedBounds = translatedBounds = frameBounds;
}

void idTreeAnimator::SyncJoints(const int time) {
    const idMD6Model* const model = TreeModel(*this);
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    const int numJoints = NumJoints();
    if (model == nullptr || skeleton == nullptr || skeleton->data == nullptr ||
            numJoints <= 0 || joints[JOINTS_GAME_FINAL] == nullptr ||
            joints[JOINTS_DEFERRED_FINAL] == nullptr) return;
    const float* const inversePose = reinterpret_cast<const float*>(
        skeleton->InverseBasePose());
    const float* const inverseQuats = reinterpret_cast<const float*>(
        skeleton->InverseBasePoseQuats());
    idMD6Blend::TransformModelMatrices(skeleton->data,
        model->jointRemap.Ptr(), joints[JOINTS_GAME_FINAL]->mat,
        inversePose, inverseQuats, joints[JOINTS_DEFERRED_FINAL]->mat,
        useDualQuatSkinning != 0, nullptr);
    if (joints[JOINTS_GAME_REFERENCE] != nullptr &&
            joints[JOINTS_DEFERRED_REFERENCE] != nullptr) {
        idMD6Blend::TransformModelMatrices(skeleton->data,
            model->jointRemap.Ptr(), joints[JOINTS_GAME_REFERENCE]->mat,
            inversePose, inverseQuats,
            joints[JOINTS_DEFERRED_REFERENCE]->mat,
            useDualQuatSkinning != 0, nullptr);
    }
    deferredJobJointBuffer = (deferredJobJointBuffer + 1) & 3;
    if (bufferSyncCallback != nullptr)
        bufferSyncCallback(this, deferredJobJointBuffer,
            joints[JOINTS_DEFERRED_FINAL], numJoints);
    lastBlendTime = time;
    hasDeferredJoints = 1;
    if (calcRefBoundsFromJoints) CalcFrameBoundsFromJoints();
}

void idTreeAnimator::UpdateTime(const int time) {
    SyncJoints(time);
}

bool idTreeAnimator::GetModelSpaceJointBindTransform(const idJointIndex joint,
        idVec3& origin, idMat3& axis) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    if (skeleton == nullptr || skeleton->data == nullptr || !joint.IsValid() ||
            joint.Get() >= skeleton->data->numJoints) return false;
    const idJointMat* const inverse = skeleton->InverseBasePose();
    if (inverse == nullptr) return false;
    idMat3x4 bind;
    std::memcpy(bind.mat, inverse[joint.Get()].mat, sizeof(bind.mat));
    bind.Invert();
    origin.Set(bind.mat[3], bind.mat[7], bind.mat[11]);
    axis = idMat3(bind.mat[0], bind.mat[4], bind.mat[8],
        bind.mat[1], bind.mat[5], bind.mat[9],
        bind.mat[2], bind.mat[6], bind.mat[10]);
    return true;
}

bool idTreeAnimator::GetModelSpaceJointTransform(const animationPose_t pose,
        const idJointIndex joint, idVec3& origin, idMat3& axis) const {
    if (!joint.IsValid() || joint.Get() >= NumJoints()) return false;
    const int poseIndex = pose != 0 ? JOINTS_GAME_FINAL
        : JOINTS_GAME_REFERENCE;
    if (joints[poseIndex] == nullptr) return false;
    const idJointMat& matrix = joints[poseIndex][joint.Get()];
    origin = ScaleVector(JointOrigin(matrix), g.scale);
    axis = JointAxis(matrix);
    return true;
}

bool idTreeAnimator::GetWorldSpaceJointTransform(const animationPose_t pose,
        const idJointIndex joint, idVec3& origin, idMat3& axis) const {
    if (!joint.IsValid()) {
        origin = g.origin;
        axis = g.axis;
        return false;
    }
    if (!GetModelSpaceJointTransform(pose, joint, origin, axis)) return false;
    LocalPointToGlobal(origin, origin);
    axis *= g.axis;
    return true;
}

bool idTreeAnimator::GetModelSpaceAttachmentTransform(
        const idJointIndex joint, const idVec3& translationOffset,
        const idQuat& rotationOffset, idVec3& origin, idMat3& axis) const {
    idVec3 jointOrigin;
    idMat3 jointAxis;
    if (!GetModelSpaceJointTransform(1, joint, jointOrigin, jointAxis)) {
        origin.Set(0.0f, 0.0f, 0.0f);
        axis = idMat3(1.0f);
        return false;
    }
    origin = jointOrigin + jointAxis * ScaleVector(translationOffset, g.scale);
    axis = rotationOffset.ToMat3() * jointAxis;
    return true;
}

bool idTreeAnimator::GetWorldSpaceAttachmentTransform(
        const idJointIndex joint, const idVec3& translationOffset,
        const idQuat& rotationOffset, idVec3& origin, idMat3& axis) const {
    if (!GetModelSpaceAttachmentTransform(joint, translationOffset,
            rotationOffset, origin, axis)) return false;
    LocalPointToGlobal(origin, origin);
    axis *= g.axis;
    return true;
}

bool idTreeAnimator::GetModelSpaceJointFrameDeltas(
        const idJointIndex* const indices, const int numIndices,
        idVec3* const translationDeltas,
        idMat3* const rotationDeltas) const {
    if (indices == nullptr || numIndices < 0) return false;
    for (int index = 0; index < numIndices; ++index) {
        if (!indices[index].IsValid() || indices[index].Get() >= NumJoints())
            return false;
        idVec3 referenceOrigin, finalOrigin;
        idMat3 referenceAxis, finalAxis;
        GetModelSpaceJointTransform(0, indices[index], referenceOrigin,
            referenceAxis);
        GetModelSpaceJointTransform(1, indices[index], finalOrigin,
            finalAxis);
        if (translationDeltas != nullptr)
            translationDeltas[index] = finalOrigin - referenceOrigin;
        if (rotationDeltas != nullptr)
            rotationDeltas[index] = finalAxis * referenceAxis.Transpose();
    }
    return true;
}

bool idTreeAnimator::GetWorldSpaceJointFrameDeltas(
        const idJointIndex* const indices, const int numIndices,
        idVec3* const translationDeltas,
        idMat3* const rotationDeltas) const {
    if (!GetModelSpaceJointFrameDeltas(indices, numIndices,
            translationDeltas, rotationDeltas)) return false;
    for (int index = 0; index < numIndices; ++index) {
        if (translationDeltas != nullptr)
            translationDeltas[index] = g.axis * translationDeltas[index];
        if (rotationDeltas != nullptr)
            rotationDeltas[index] = g.axis * rotationDeltas[index] *
                g.axis.Transpose();
    }
    return true;
}

bool idTreeAnimator::GetWorldSpaceAttachmentFrameDeltas(
        const idJointIndex joint, const idVec3& translationOffset,
        const idQuat& rotationOffset, idVec3& translationDelta,
        idMat3& rotationDelta) const {
    idVec3 referenceOrigin, finalOrigin;
    idMat3 referenceAxis, finalAxis;
    if (!GetModelSpaceJointTransform(0, joint, referenceOrigin,
            referenceAxis) ||
        !GetModelSpaceJointTransform(1, joint, finalOrigin, finalAxis))
        return false;
    const idVec3 scaledOffset = ScaleVector(translationOffset, g.scale);
    referenceOrigin = referenceOrigin + referenceAxis * scaledOffset;
    finalOrigin = finalOrigin + finalAxis * scaledOffset;
    referenceAxis = rotationOffset.ToMat3() * referenceAxis;
    finalAxis = rotationOffset.ToMat3() * finalAxis;
    translationDelta = g.axis * (finalOrigin - referenceOrigin);
    rotationDelta = g.axis * (finalAxis * referenceAxis.Transpose()) *
        g.axis.Transpose();
    return true;
}

bool idTreeAnimator::GetModelSpaceTagTransform(const tagData_t& tag,
        idVec3& origin, idMat3& axis) const {
    if (!tag.parentJoint.IsValid()) return false;
    return GetModelSpaceAttachmentTransform(GetJointIndex(tag.parentJoint),
        tag.trans, tag.rot, origin, axis);
}

bool idTreeAnimator::GetWorldSpaceTagTransform(const tagData_t& tag,
        idVec3& origin, idMat3& axis) const {
    if (!tag.parentJoint.IsValid()) return false;
    return GetWorldSpaceAttachmentTransform(GetJointIndex(tag.parentJoint),
        tag.trans, tag.rot, origin, axis);
}

int idTreeAnimator::NumJoints() const {
    return TreeJointCount(*this);
}

const char* idTreeAnimator::GetJointName(const idJointIndex joint) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    return skeleton != nullptr ? skeleton->GetJointName(joint.Get()) : nullptr;
}

md6JointHandle_t idTreeAnimator::GetJointHandle(
        const idJointIndex joint) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    return skeleton != nullptr ? skeleton->GetJointHandle(joint.Get())
        : md6JointHandle_t();
}

idJointIndex idTreeAnimator::GetJointIndex(const char* const jointName) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    return skeleton != nullptr ? skeleton->GetJointIndex(jointName)
        : idJointIndex();
}

idJointIndex idTreeAnimator::GetJointIndex(
        const md6JointHandle_t handle) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    return skeleton != nullptr ? skeleton->GetJointIndex(handle)
        : idJointIndex();
}

idJointIndex idTreeAnimator::GetFirstChild(const idJointIndex joint) const {
    const idMD6Skel* const skeleton = TreeSkeleton(*this);
    const short* const parents = skeleton != nullptr
        ? skeleton->ParentTable() : nullptr;
    for (int index = 0; parents != nullptr && index < NumJoints(); ++index) {
        if (parents[index] == joint.Get())
            return idJointIndex(static_cast<short>(index));
    }
    return idJointIndex();
}

idJointIndex idTreeAnimator::GetFirstChild(const char* const jointName) const {
    return GetFirstChild(GetJointIndex(jointName));
}

void idTreeAnimator::SetUseDualQuaternion(const bool useDualQuaternion) {
    useDualQuatSkinning = useDualQuaternion;
    for (idJointBuffer& buffer : jointBuffers)
        buffer.flags = useDualQuaternion ? 1 : 0;
}

void idTreeAnimator::GetLastOriginDeltas(idVec3& translation) const {
    idQuat ignored;
    GetLastOriginDeltas(ignored, translation);
}

void idTreeAnimator::GetLastOriginDeltas(idQuat& rotation,
        idVec3& translation) const {
    const md6OriginDelta_t* const delta = originDelta[1];
    if (delta == nullptr) {
        rotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
        translation.Set(0.0f, 0.0f, 0.0f);
        return;
    }
    rotation = *reinterpret_cast<const idQuat*>(delta->deltaRotation);
    translation = ScaleVector(
        *reinterpret_cast<const idVec3*>(delta->deltaTranslation), g.scale);
}

void idTreeAnimator::GetLastOriginDeltas(idMat3& rotation,
        idVec3& translation) const {
    idQuat quaternion;
    GetLastOriginDeltas(quaternion, translation);
    rotation = quaternion.ToMat3();
}

void idTreeAnimator::GetTotalOriginTransform(idQuat& rotation,
        idVec3& translation) const {
    const md6OriginDelta_t* const delta = originDelta[1];
    if (delta == nullptr) {
        rotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
        translation.Set(0.0f, 0.0f, 0.0f);
        return;
    }
    rotation = *reinterpret_cast<const idQuat*>(delta->animRotation);
    translation = ScaleVector(
        *reinterpret_cast<const idVec3*>(delta->animTranslation), g.scale);
}

const idVec3& idTreeAnimator::GetVisualOffset() const {
    static const idVec3 zero(0.0f, 0.0f, 0.0f);
    return decl != nullptr && decl->config != nullptr
        ? *reinterpret_cast<const idVec3*>(decl->config->visualOffset)
        : zero;
}

void idTreeAnimator::ApplyOriginDeltas(const idMat3& rotationDelta,
        const idVec3& translationDelta, idMat3& rotation,
        idVec3& translation, idVec3& velocity) const {
    const idVec3 worldDelta = rotation * ScaleVector(translationDelta,
        g.scale);
    translation = translation + worldDelta;
    velocity = velocity + worldDelta;
    rotation *= rotationDelta;
}

void idTreeAnimator::ApplyOriginDeltas(const idQuat& rotationDelta,
        const idVec3& translationDelta, idQuat& rotation,
        idVec3& translation, idVec3& velocity) const {
    const idVec3 worldDelta = rotation.ToMat3() *
        ScaleVector(translationDelta, g.scale);
    translation = translation + worldDelta;
    velocity = velocity + worldDelta;
    rotation = MultiplyQuat(rotation, rotationDelta);
}

const idDeclSkins* idTreeAnimator::GetSkins() const {
    return skinsResolverCallback != nullptr
        ? skinsResolverCallback(this) : nullptr;
}

void idTreeAnimator::SetKitSkin(const char* const skin) {
    const idDeclSkins* const skins = GetSkins();
    if (skins != nullptr && skin != nullptr && skinIndexCallback != nullptr) {
        const int index = skinIndexCallback(skins, skin);
        if (index >= 0) g.customSkin = index;
    }
}

float idTreeAnimator::GetBlendedUserChannel(
        const idUserChannelIndex index) const {
    const int stable = currentDeferred ^ 1;
    if (!index.IsValid() || index.Get() >= userChannels[stable].Num())
        return 0.0f;
    return userChannels[stable][index.Get()];
}

idStr idTreeAnimator::ShowKit(const meshKitComponents_t component,
        const char* const kitName) {
    if (decl == nullptr || component < 0 || component >= MESH_KIT_NUM ||
            kitName == nullptr || kitName[0] == '\0') return idStr("");
    const auto& groups = decl->meshKitGroups[component];
    for (int group = 0; group < groups.Num(); ++group) {
        if (idStr::Icmp(groups[group].first.c_str(), kitName) != 0) continue;
        for (int item = 0; item < groups[group].second.Num(); ++item) {
            const int mesh = groups[group].second[item];
            if (mesh >= 0 && mesh < meshVisibility.Num())
                meshVisibility[mesh] = true;
        }
        return idStr(kitName);
    }
    return idStr("");
}

void idTreeAnimator::HideKit(const meshKitComponents_t component,
        const char* const kitName) {
    if (decl == nullptr || component < 0 || component >= MESH_KIT_NUM ||
            kitName == nullptr) return;
    const auto& groups = decl->meshKitGroups[component];
    for (int group = 0; group < groups.Num(); ++group) {
        if (idStr::Icmp(groups[group].first.c_str(), kitName) != 0) continue;
        for (int item = 0; item < groups[group].second.Num(); ++item) {
            const int mesh = groups[group].second[item];
            if (mesh >= 0 && mesh < meshVisibility.Num())
                meshVisibility[mesh] = false;
        }
    }
}

void idTreeAnimator::HideKitsExcept(const meshKitComponents_t component,
        const char* const kitName) {
    if (decl == nullptr || component < 0 || component >= MESH_KIT_NUM) return;
    const auto& groups = decl->meshKitGroups[component];
    for (int group = 0; group < groups.Num(); ++group) {
        const bool show = kitName != nullptr && kitName[0] != '\0' &&
            idStr::Icmp(groups[group].first.c_str(), kitName) == 0;
        for (int item = 0; item < groups[group].second.Num(); ++item) {
            const int mesh = groups[group].second[item];
            if (mesh >= 0 && mesh < meshVisibility.Num())
                meshVisibility[mesh] = show;
        }
    }
}

void idTreeAnimator::HideAllKits(const meshKitComponents_t component) {
    HideKitsExcept(component, nullptr);
}

int idTreeAnimator::GetMeshIndex(const char* const meshName) const {
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr || meshName == nullptr) return -1;
    for (int index = 0; index < model->meshes.Num(); ++index) {
        const idMD6Mesh* const mesh = model->meshes[index];
        if (mesh != nullptr && idStr::Icmp(mesh->name.c_str(), meshName) == 0)
            return index;
    }
    return -1;
}

const idMD6Anim* idTreeAnimator::LookupAnimByAlias(
        const idDeclMD6* declaration, const char* const animationName) {
    if (declaration == nullptr || animationName == nullptr ||
            animationResolverCallback == nullptr) return nullptr;
    for (const idDeclMD6* current = declaration; current != nullptr;
            current = current->parentDecl) {
        for (int index = 0; index < current->aliases.Num(); ++index) {
            const idMD6Alias& alias = current->aliases[index];
            if (idStr::Icmp(alias.name.c_str(), animationName) == 0 &&
                    alias.animRefs.Num() > 0) {
                return animationResolverCallback(declaration,
                    alias.animRefs[0].c_str());
            }
        }
    }
    return animationResolverCallback(declaration, animationName);
}

const idMD6Anim* idTreeAnimator::GetSingleAnimFrame(
        idJointMat* const outputJoints, const aliasHandle_t aliasHandle,
        const int time, const idVec3& offset,
        const bool removeOriginOffset) const {
    if (decl == nullptr || !aliasHandle.IsValid()) return nullptr;
    for (const idDeclMD6* current = decl; current != nullptr;
            current = current->parentDecl) {
        for (int index = 0; index < current->aliases.Num(); ++index) {
            const idMD6Alias& alias = current->aliases[index];
            if (alias.aliasHandle != aliasHandle || alias.animRefs.Num() == 0)
                continue;
            const idMD6Anim* const animation = animationResolverCallback != nullptr
                ? animationResolverCallback(decl, alias.animRefs[0].c_str())
                : nullptr;
            const idMD6Model* const model = TreeModel(*this);
            return animation != nullptr && model != nullptr &&
                model->GetJointsForAnimTime(outputJoints, animation, time,
                    offset, removeOriginOffset) ? animation : nullptr;
        }
    }
    return nullptr;
}

const idMD6Anim* idTreeAnimator::GetSingleAnimFrame(
        idJointMat* const outputJoints, const char* const animationName,
        const int time, const idVec3& offset,
        const bool removeOriginOffset) const {
    const idMD6Anim* const animation = LookupAnimByAlias(decl, animationName);
    const idMD6Model* const model = TreeModel(*this);
    return animation != nullptr && model != nullptr &&
        model->GetJointsForAnimTime(outputJoints, animation, time, offset,
            removeOriginOffset) ? animation : nullptr;
}

void idTreeAnimator::SetFrameFromAnim(const idMD6Anim* const animation,
        const int frame, const bool removeOriginOffset,
        const bool updateBounds, const idVec3* const offset) {
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr || animation == nullptr ||
            joints[JOINTS_GAME_REFERENCE] == nullptr) return;
    const idVec3 zero(0.0f, 0.0f, 0.0f);
    if (!model->GetJointsForAnimFrame(joints[JOINTS_GAME_REFERENCE],
            animation, frame, offset != nullptr ? *offset : zero,
            removeOriginOffset)) return;
    const int bytes = Pad8(NumJoints()) * sizeof(idJointMat);
    if (joints[JOINTS_GAME_FINAL] != nullptr)
        std::memcpy(joints[JOINTS_GAME_FINAL],
            joints[JOINTS_GAME_REFERENCE], bytes);
    SyncJoints(frame);
    if (updateBounds) CalcFrameBoundsFromJoints();
}

void idTreeAnimator::FreeSurfaces() {
    surfaces.ClearFree();
}

const idList<sourceSurface_t, 5>* idTreeAnimator::GetSourceSurfaces() const {
    const idMD6Model* const model = TreeModel(*this);
    return model != nullptr ? &model->sourceSurfaces : nullptr;
}

void idTreeAnimator::InitializeSurfaces() {
    FreeSurfaces();
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr || !surfaces.SetNum(model->meshes.Num())) return;
    for (int index = 0; index < surfaces.Num(); ++index) {
        idRenderModelSurface& surface = surfaces[index];
        std::memset(&surface, 0, sizeof(surface));
        surface.geometryIsReference = true;
        surface.referenceMask = 3;
        surface.joints = &jointBuffers[renderThreadJointBuffer];
    }
}

void idTreeAnimator::FreeMorphMaps() {
    for (int index = 0; index < morphMaps.Num(); ++index) {
        delete[] morphMaps[index].map;
        morphMaps[index].map = nullptr;
        morphMaps[index].buffers[0] = nullptr;
        morphMaps[index].buffers[1] = nullptr;
    }
    morphMaps.ClearFree();
}

void idTreeAnimator::InitializeMorphMaps() {
    FreeMorphMaps();
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr || !morphMaps.SetNum(model->meshes.Num())) return;
    for (int index = 0; index < morphMaps.Num(); ++index) {
        morphMap_t& destination = morphMaps[index];
        destination.map = nullptr;
        destination.buffers[0] = destination.buffers[1] = nullptr;
        const idMD6Mesh* const mesh = model->meshes[index];
        if (mesh == nullptr || mesh->numVerts <= 0 ||
                (mesh->morphMap.IsEmpty() &&
                 (decl == nullptr || decl->morphVertices == nullptr)))
            continue;
        const int bytes = mesh->numVerts * 4;
        destination.map = new (std::nothrow) std::uint8_t[bytes]{};
        if (destination.map != nullptr && !mesh->morphMap.IsEmpty()) {
            std::memcpy(destination.map, mesh->morphMap.Ptr(),
                (std::min)(bytes, mesh->morphMap.Num()));
        }
    }
}

void idTreeAnimator::SetMorphSkin(const char* const skinName,
        const int skinIndex, const float morphAmount) {
    if (skinName != nullptr) {
        const idDeclSkins* const skins = GetSkins();
        const int resolved = skinName[0] != '\0' && skins != nullptr &&
                skinIndexCallback != nullptr
            ? skinIndexCallback(skins, skinName) : skinIndex;
        morphSkin = resolved >= 0 ? static_cast<std::int16_t>(resolved) : -1;
    } else if (skinIndex >= -1) {
        morphSkin = static_cast<std::int16_t>(skinIndex);
    }
    initialMorphValue = morphAmount;
    const idMD6Model* const model = TreeModel(*this);
    if (model != nullptr && morphMaps.Num() != model->meshes.Num())
        InitializeMorphMaps();
    const int alpha = static_cast<int>((std::max)(0.0f,
        (std::min)(1.0f, morphAmount)) * 255.0f);
    for (int meshIndex = 0; model != nullptr &&
            meshIndex < morphMaps.Num(); ++meshIndex) {
        const idMD6Mesh* const mesh = model->meshes[meshIndex];
        std::uint8_t* const map = morphMaps[meshIndex].map;
        if (mesh == nullptr || map == nullptr || !mesh->morphMap.IsEmpty())
            continue;
        for (int vertex = 0; vertex < mesh->numVerts; ++vertex) {
            map[vertex * 4 + 0] = 0;
            map[vertex * 4 + 1] = 128;
            map[vertex * 4 + 2] = 128;
            map[vertex * 4 + 3] = static_cast<std::uint8_t>(alpha);
        }
    }
    updateMorphBuffers = 1;
}

void idTreeAnimator::MorphLocation(const float amount, const int location) {
    if (amount <= 0.0f || decl == nullptr || decl->morphVertices == nullptr)
        return;
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr) return;
    if (morphMaps.Num() != model->meshes.Num()) InitializeMorphMaps();
    const int add = static_cast<int>(amount * 255.0f);
    const auto& sets = decl->morphVertices->morphVertSet;
    for (int setIndex = 0; setIndex < sets.Num(); ++setIndex) {
        const idMorphVertices::vertSet& set = sets[setIndex];
        if (set.meshNum < 0 || set.meshNum >= model->meshes.Num() ||
                set.jointGroupIndex != location) continue;
        const idMD6Mesh* const mesh = model->meshes[set.meshNum];
        std::uint8_t* const map = morphMaps[set.meshNum].map;
        if (mesh == nullptr || map == nullptr) continue;
        for (int item = 0; item < set.vertices.Num(); ++item) {
            const int vertex = set.vertices[item];
            if (vertex < 0 || vertex >= mesh->numVerts) continue;
            std::uint8_t* const value = map + vertex * 4;
            const int direction = item * 3;
            if (direction + 2 < set.morphDirection.Num()) {
                value[0] = set.morphDirection[direction + 0];
                value[1] = set.morphDirection[direction + 1];
                value[2] = set.morphDirection[direction + 2];
            }
            value[3] = static_cast<std::uint8_t>((std::min)(255,
                static_cast<int>(value[3]) + add));
        }
    }
    updateMorphBuffers = 1;
}

void idTreeAnimator::ClearMorphPoints() {
    const idMD6Model* const model = TreeModel(*this);
    for (int meshIndex = 0; model != nullptr &&
            meshIndex < morphMaps.Num(); ++meshIndex) {
        const idMD6Mesh* const mesh = model->meshes[meshIndex];
        std::uint8_t* const map = morphMaps[meshIndex].map;
        for (int vertex = 0; mesh != nullptr && map != nullptr &&
                vertex < mesh->numVerts; ++vertex)
            map[vertex * 4 + 3] = 0;
    }
    updateMorphBuffers = 1;
}

void idTreeAnimator::BitShiftMorphPoints(const unsigned int shift) {
    if (shift == 0 || shift > 2) return;
    const idMD6Model* const model = TreeModel(*this);
    for (int meshIndex = 0; model != nullptr &&
            meshIndex < morphMaps.Num(); ++meshIndex) {
        const idMD6Mesh* const mesh = model->meshes[meshIndex];
        std::uint8_t* const map = morphMaps[meshIndex].map;
        for (int vertex = 0; mesh != nullptr && map != nullptr &&
                vertex < mesh->numVerts; ++vertex)
            map[vertex * 4 + 3] >>= shift;
    }
    updateMorphBuffers = 1;
}

void idTreeAnimator::UpdateTree_r(const idMD6Model*, const int,
        const int, idMD6Node* const root) {
    if (!IsBranch(root)) return;
    idMD6Branch* const branch = static_cast<idMD6Branch*>(root);
    UpdateTree_r(nullptr, 0, 0, branch->left);
    UpdateTree_r(nullptr, 0, 0, branch->right);
}

void idTreeAnimator::UpdateTree(const idMD6Model* const model,
        const int first, const int second, idMD6Node* const root) {
    UpdateTree_r(model, first, second, root);
}

void idTreeAnimator::FreeTree_r(idMD6Allocator* const allocator,
        idMD6Node* const root) {
    if (root == nullptr) return;
    if (IsBranch(root)) {
        idMD6Branch* const branch = static_cast<idMD6Branch*>(root);
        FreeTree_r(allocator, branch->left);
        FreeTree_r(allocator, branch->right);
    }
    if (allocator != nullptr) allocator->Free(root);
    else _aligned_free(root);
}

void idTreeAnimator::FreeTree(idMD6Allocator* const allocator,
        idMD6Node* const root) {
    FreeTree_r(allocator, root);
}

bool idTreeAnimator::StoreTree(const idMD6Model* const model,
        const int modelIndex, const int time, const idAnimStack& stack,
        idMD6Node* const root, idBitMsg& nodes, idBitMsg& leaves,
        idBitMsg& modifiers) {
    return treeStoreCallback != nullptr && treeStoreCallback(model,
        modelIndex, time, stack, root, nodes, leaves, modifiers);
}

idMD6Node* idTreeAnimator::ReadTree(const idAnimStack& stack,
        idMD6Allocator* const allocator, idBitMsg& nodes, idBitMsg& leaves,
        idBitMsg& modifiers) {
    return treeReadCallback != nullptr
        ? treeReadCallback(stack, allocator, nodes, leaves, modifiers)
        : nullptr;
}

idMD6Blend::jointMod_t* idTreeAnimator::FindOrCreateJointMod(
        const animationPose_t pose, const idJointIndex joint,
        const jointModTransform_t transform) {
    if (!joint.IsValid() || joint.Get() >= NumJoints()) return nullptr;
    idList<idMD6Blend::jointMod_t, 17>& modifiers =
        jointMods[currentDeferred];
    for (int index = modifiers.Num() - 1; index >= 0; --index) {
        if (modifiers[index].joint == joint) return &modifiers[index];
    }
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform, 0);
    const int index = modifiers.Append(modifier);
    return index >= 0 ? &modifiers[index] : nullptr;
}

const idMD6Blend::jointMod_t* idTreeAnimator::FindJointMod(
        const animationPose_t, const idJointIndex joint) const {
    const idList<idMD6Blend::jointMod_t, 17>& modifiers =
        jointMods[currentDeferred];
    for (int index = modifiers.Num() - 1; index >= 0; --index) {
        if (modifiers[index].joint == joint) return &modifiers[index];
    }
    return nullptr;
}

void idTreeAnimator::ClearJointMods() {
    jointMods[currentDeferred].Clear();
}

void idTreeAnimator::SetJointMat3x4(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const idMat3x4& matrix, const bool setPosition) {
    idList<idMD6Blend::jointMod_t, 17>& modifiers =
        jointMods[currentDeferred];
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform,
        static_cast<std::uint16_t>(idMD6Blend::DRIVER_ROTATION |
            (setPosition ? idMD6Blend::DRIVER_TRANSLATION : 0)));
    std::memcpy(modifier.mat, matrix.mat, sizeof(modifier.mat));
    modifiers.Append(modifier);
}

void idTreeAnimator::SetJointPosAxisScale(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const idVec3& position, const idMat3& axis, const idVec3& scale) {
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform,
        idMD6Blend::DRIVER_TRANSLATION | idMD6Blend::DRIVER_ROTATION |
        idMD6Blend::DRIVER_SCALE);
    modifier.mat[3] = position.x;
    modifier.mat[7] = position.y;
    modifier.mat[11] = position.z;
    ::SetJointAxis(*reinterpret_cast<idJointMat*>(modifier.mat), axis);
    modifier.s[0] = scale.x;
    modifier.s[1] = scale.y;
    modifier.s[2] = scale.z;
    jointMods[currentDeferred].Append(modifier);
}

void idTreeAnimator::SetJointPos(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const idVec3& position) {
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform,
        idMD6Blend::DRIVER_TRANSLATION);
    modifier.mat[3] = position.x;
    modifier.mat[7] = position.y;
    modifier.mat[11] = position.z;
    jointMods[currentDeferred].Append(modifier);
}

void idTreeAnimator::SetJointAxis(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const idMat3& axis) {
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform,
        idMD6Blend::DRIVER_ROTATION);
    ::SetJointAxis(*reinterpret_cast<idJointMat*>(modifier.mat), axis);
    jointMods[currentDeferred].Append(modifier);
}

void idTreeAnimator::SetJointScale(const animationPose_t pose,
        const idJointIndex joint, const jointModTransform_t transform,
        const idVec3& scale) {
    idMD6Blend::jointMod_t modifier = MakeJointMod(pose, joint, transform,
        idMD6Blend::DRIVER_SCALE);
    modifier.s[0] = scale.x;
    modifier.s[1] = scale.y;
    modifier.s[2] = scale.z;
    jointMods[currentDeferred].Append(modifier);
}

void idTreeAnimator::LatchDeferredState() {
    renderThreadJointBuffer = nextRenderThreadJointBuffer;
    if (deferredJobJointBuffer >= 0)
        nextRenderThreadJointBuffer = deferredJobJointBuffer;
    referenceBounds = frameBounds;
    if (originDelta[0] != nullptr && originDelta[1] != nullptr)
        *originDelta[1] = *originDelta[0];
}

bool idTreeAnimator::CommitSubclass() {
    LatchDeferredState();
    const idMD6Model* const model = TreeModel(*this);
    if (model == nullptr) return false;
    if (surfaces.Num() != model->meshes.Num()) InitializeSurfaces();
    if (morphMaps.Num() != model->meshes.Num()) InitializeMorphMaps();
    if (updateMorphBuffers) currentMorphBuffer ^= 1;
    for (int index = 0; index < model->meshes.Num(); ++index) {
        idRenderModelSurface& surface = surfaces[index];
        const idMD6Mesh* const mesh = model->meshes[index];
        surface.material = nullptr;
        surface.geometry = nullptr;
        surface.morphMap = nullptr;
        if (mesh == nullptr || index >= meshVisibility.Num() ||
                !meshVisibility[index]) continue;
        surface.material = g.customMaterial != nullptr
            ? g.customMaterial
            : g.customSkin >= 0 && g.customSkin < mesh->skinRemaps.Num()
                ? mesh->skinRemaps[g.customSkin].mtr : mesh->material;
        surface.geometry = mesh->tris;
        surface.joints = &jointBuffers[renderThreadJointBuffer];
        surface.stMap = mesh->stSets.Num() > 0 ? mesh->stSets[0].vb : nullptr;
        surface.skinOffsets.Set(0.0f, 0.0f, 0.0f, 0.0f);
        if (g.customSkin >= 0 && g.customSkin < mesh->skinRemaps.Num()) {
            surface.skinOffsets.x = mesh->skinRemaps[g.customSkin].texOffset.x;
            surface.skinOffsets.y = mesh->skinRemaps[g.customSkin].texOffset.y;
        }
        if (morphSkin >= 0 && morphSkin < mesh->skinRemaps.Num()) {
            surface.skinOffsets.z = mesh->skinRemaps[morphSkin].texOffset.x;
            surface.skinOffsets.w = mesh->skinRemaps[morphSkin].texOffset.y;
        }
        if (updateMorphBuffers && morphBufferCallback != nullptr &&
                morphMaps[index].map != nullptr) {
            morphBufferCallback(this, index, currentMorphBuffer,
                morphMaps[index].map, mesh->numVerts * 4);
        }
        surface.morphMap = morphMaps[index].buffers[currentMorphBuffer];
    }
    updateMorphBuffers = 0;
    const bool nativeResult = true;
    return commitCallback != nullptr ? commitCallback(this) : nativeResult;
}

bool idTreeAnimator::UpdateInView(const idRenderView* const currentView,
        const idRenderView* const nextView,
        idRenderModelUpdateTools* const tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

decalHandle_t idTreeAnimator::AddDecalFromPoint(
        const decalParams_t* const parms, const int startTime,
        const idVec3& position, const idVec3& direction,
        const idJointIndex joint) {
    return idRenderModel::AddDecalFromPoint(parms, startTime, position,
        direction, joint);
}
