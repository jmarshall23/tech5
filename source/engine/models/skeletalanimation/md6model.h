#pragma once

#include "framework/resource.h"
#include "framework/resourcelist.h"
#include "models/rendermodel.h"
#include "models/skeletalanimation/md6mesh.h"
#include "models/skeletalanimation/md6skel.h"

class idMD6Anim;

class idMD6Model : public idResource {
public:
    using SkeletonResolver = const idMD6Skel* (*)(const char* name);
    using SkeletonNameCallback = const char* (*)(const idMD6Skel* skeleton);
    using MaterialResolver = const idMaterial* (*)(const char* name);
    using MaterialNameCallback = const char* (*)(const idMaterial* material);
    using ChecksumCallback = unsigned int (*)(const void* declaration);
    using SourceSurfaceRemapCallback = void (*)(idMD6Model* model);
    using GenerateCallback = bool (*)(idMD6Model* model,
        const char* sourceFileName);
    using UserChannelNameCallback = const char* (*)(
        md6UserChannelHandle_t handle);

    idMD6Model();
    ~idMD6Model() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;
    void Print() override;
    void PrintDetailed() const;
    void List() override;

    bool GetJointsForAnimFrame(idJointMat* joints, const idMD6Anim* animation,
        int frame, const idVec3& offset, bool removeOriginOffset) const;
    bool GetJointsForAnimTime(idJointMat* joints, const idMD6Anim* animation,
        int timeMS, const idVec3& offset, bool removeOriginOffset) const;
    bool GetUserChannelsForAnimFrame(float* channels,
        unsigned int channelsSize, const idMD6Anim* animation,
        float frame) const;
    const char* GetUserChannelName(md6UserChannelIndex_t index) const;

    bool LoadBinary(const char* fileName, bool explicitFile = false);
    bool WriteBinary(const char* fileName) const;
    bool LoadFileNoRemap(const char* fileName);
    void RemapSourceSurfaces();
    void FreeData();
    unsigned int Memory() const;
    bool Equals(const idMD6Model& other) const;

    static void SetResourceCallbacks(SkeletonResolver skeletonResolver,
        SkeletonNameCallback skeletonName, MaterialResolver materialResolver,
        MaterialNameCallback materialName, ChecksumCallback checksum,
        SourceSurfaceRemapCallback remap, GenerateCallback generator,
        UserChannelNameCallback userChannelName);

    idStr filename;
    unsigned int timestamp;
    unsigned int skelTimestamp;
    idBounds defaultBounds;
    bool remapForSkinning;
    unsigned int skinChecksum;
    idStr morphSkinName;
    int morphSkin;
    int numMeshesBeforeSplitting;
    idList<idMD6Mesh*, 19> meshes;
    idList<unsigned char, 19> jointRemap;
    idList<sourceSurface_t, 5> sourceSurfaces;
    idList<const idMaterial*, 5> materials;
    const idMD6Skel* skeleton;
    idVec3 minBoundsExpansion;
    idVec3 maxBoundsExpansion;

    static idTypedResourceList<idMD6Model> resourceList;

private:
    static SkeletonResolver skeletonResolverCallback;
    static SkeletonNameCallback skeletonNameCallback;
    static MaterialResolver materialResolverCallback;
    static MaterialNameCallback materialNameCallback;
    static ChecksumCallback checksumCallback;
    static SourceSurfaceRemapCallback sourceSurfaceRemapCallback;
    static GenerateCallback generateCallback;
    static UserChannelNameCallback userChannelNameCallback;
};

bool TrianglesAreEqual(const idTriangles& first, const idTriangles& second);
