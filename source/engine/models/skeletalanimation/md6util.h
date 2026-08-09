#pragma once

#include "idlib/geometry/jointtransform.h"
#include "idlib/index.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"
#include "gamelib/animstack/animstacktypes.h"

#include <cstdint>

class idDeclAnimWeb;
class idDeclMD6;
class idMD6Anim;
class idAnimWebPath;

class idMD6Util {
public:
    struct animDelta_t;

    using WebResolverCallback = const idDeclAnimWeb* (*)(const char* webName);
    using AnimResolverCallback = const idMD6Anim* (*)(
        const idDeclAnimWeb* web, const idAnimWebPath& path,
        const idDeclMD6* declaration, idAnimWebModelIndex modelIndex,
        bool loadAnimation);
    using JointIndexCallback = int (*)(const idDeclMD6* declaration,
        const char* jointName);
    using PoseDecodeCallback = bool (*)(const idDeclMD6* declaration,
        const idMD6Anim* animation, int frame, idJointMat* joints,
        int maxJoints);
    enum frame_t : int {
        FRAME_FIRST = 0,
        FRAME_LAST = -1
    };

    class alignas(16) idJointCache {
    public:
        idJointCache(const idDeclMD6* declaration = nullptr,
            const idMD6Anim* animation = nullptr, int frame = FRAME_FIRST);
        idJointCache(const idAnimWebPath& webPath, int frame = FRAME_FIRST);

        bool GetDelta(animDelta_t& delta, const char* jointName,
            const char* refJointName) const;
        void Set(const idDeclAnimWeb* web, const idAnimWebPath& webPath,
            int frame);

        idJointMat jointMatrices[256];
        const idDeclAnimWeb* webRef;
        const idDeclMD6* md6Decl;
        const idMD6Anim* md6anim;
        int frameNum;
        bool validJointCache;

    private:
        void UpdateCache();
    };

    struct animDelta_t {
        idVec3 deltaTranslation;
        idMat3 deltaAxis;
    };

    struct idAnimWebBlendInfo {
        std::int16_t startBlendFrame;
        std::int16_t endBlendFrame;
    };

    static const idMD6Anim* FindMD6Anim(const idDeclAnimWeb* web,
        const idAnimWebPath& webPath, const idDeclMD6* declaration,
        idAnimWebModelIndex modelIndex, bool loadAnimation);
    static bool GetAnimDelta(const idMD6Anim* animation,
        idVec3* deltaOrigin, idMat3* deltaAxis);
    static void SetCallbacks(WebResolverCallback webResolver,
        AnimResolverCallback animResolver, JointIndexCallback jointIndex,
        PoseDecodeCallback poseDecoder);

private:
    static WebResolverCallback webResolverCallback;
    static AnimResolverCallback animResolverCallback;
    static JointIndexCallback jointIndexCallback;
    static PoseDecodeCallback poseDecodeCallback;
};

static_assert(sizeof(idMD6Util::animDelta_t) == 48,
    "Recovered MD6 animation-delta ABI changed");
static_assert(sizeof(idMD6Util::idAnimWebBlendInfo) == 4,
    "Recovered animation-web blend information ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMD6Util::idJointCache) == 12320,
    "Recovered MD6 joint-cache ABI changed");
#endif
