#pragma once

#include "decls/decl.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/pair.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/varargs.h"
#include "models/morphskingen.h"
#include "models/skeletalanimation/animation.h"
#include "models/skeletalanimation/animevents.h"
#include "models/skeletalanimation/eyeinfocollection.h"
#include "models/skeletalanimation/jobs/md6blend.h"
#include "models/skeletalanimation/jointgroup.h"
#include "models/skeletalanimation/md6alias.h"
#include "models/skeletalanimation/taginfo.h"
#include "gamelib/animstack/animstacktypes.h"

#include <cstdint>

class idFile_String;
class idJointMat;
class idMD6Anim;
class idMD6Model;
enum invalidUserChannelIndex_t : int;

class idDeclMD6 : public idDecl {
public:
    enum modelCaps_t : int {
        MODELCAP_LIPSYNC = 0x1,
        MODELCAP_FACESETUP = 0x2,
        MODELCAP_MOODS = 0x4,
        MODELCAP_GESTURES = 0x8
    };

    enum userPropEx_t : int {
        USERPROPEX_NONE = 0,
        USERPROPEX_DECL_START = 1,
        USERPROPEX_DECL_RENDERPROG = 1,
        USERPROPEX_DECL_AF,
        USERPROPEX_DECL_ENTITYDEF,
        USERPROPEX_DECL_MATERIAL,
        USERPROPEX_DECL_PARTICLES,
        USERPROPEX_DECL_CLOTH,
        USERPROPEX_DECL_SOUNDSHADER,
        USERPROPEX_DECL_MD6DEF,
        USERPROPEX_DECL_SKIN,
        USERPROPEX_DECL_TABLE,
        USERPROPEX_DECL_ENV,
        USERPROPEX_DECL_FX,
        USERPROPEX_DECL_VOICEOVER,
        USERPROPEX_DECL_ANIMWEB,
        USERPROPEX_DECL_VISEMESET,
        USERPROPEX_DECL_BREAKABLE,
        USERPROPEX_DECL_RIBBON,
        USERPROPEX_DECL_FLARE,
        USERPROPEX_DECL_END
    };

    struct alignas(4) includeDecl_t {
        const idDeclMD6* includeDecl;
        bool isOriginalInclude;
    };

    class idHeadTrackJoint {
    public:
        idIndex<short, invalidJointIndex_t> jointIdx;
        float pitchScale;
        float yawScale;
    };

    class idHeadTrackGroup {
    public:
        idAtomicString name;
        idList<idHeadTrackJoint, 5> trackJoints;
        idIndex<short, invalidJointIndex_t> focusJointIdx;
        idIndex<short, invalidJointIndex_t> orientationJointIdx;
        int blendTime;
    };

    struct animEventData_t {
        const idDeclMD6* definingDecl;
        const idAnimEvents::animEventInfo_t* info;
    };

    idDeclMD6();
    ~idDeclMD6() override;

    unsigned int GetDeclTimestamp() const override;
    idDeclInfo* GetDeclInfo() const override;
    bool RebuildTextSource() override;
    const char* DefaultDefinition() const override;
    void LogMissingDecl() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;
    void Write(idFile_String* file, const char* indent) const;
    bool FindAnimEvents(const idMD6Anim* animation, int startFrame,
        int endFrame,
        idStaticList<const idMD6AnimEvent*, 16>& events) const;

    aliasHandle_t StrongLoadAlias(const char* aliasName) const;
    aliasHandle_t FindAliasHandle(const char* aliasName) const;
    const idMD6Alias* FindAlias(aliasHandle_t aliasHandle,
        bool includeInherited = true) const;
    const idMD6Alias* FindAlias(const char* aliasName,
        bool includeInherited = true) const;
    const idMD6Anim* AnimForAlias(aliasHandle_t aliasHandle,
        bool load = true) const;
    bool GetJointsForAnimTime(idJointMat* joints,
        const idMD6Anim* animation, int timeMS, const idVec3& offset,
        bool removeOriginOffset) const;
    idIndex<short, invalidJointIndex_t> GetJointIndex(
        const char* jointName) const;
    idIndex<short, invalidJointIndex_t> GetJointIndex(
        jointHandle_t handle) const;
    const char* GetJointName(
        idIndex<short, invalidJointIndex_t> joint) const;
    void GetJointList(const char* joints,
        idList<idIndex<short, invalidJointIndex_t>, 5>& jointList) const;
    const idVarArgs<6>* FindUserProp(const char* propName) const;
    int GetHeadTrackGroupIndex(const char* groupName) const;
    bool IsChildOf(const idDeclMD6* declaration) const;
    md6WeightGroup_t GetUserChannelWeightGroup() const;
    void GetAliases(idList<const idMD6Alias*, 5>& output,
        bool includeInherited) const;
    bool GetCachedJoints(int eventNumber, const idMD6Anim* animation,
        idStaticList<const idCachedJoint*, 8>& joints) const;
    aliasHandle_t AddAlias(const idMD6Alias& alias,
        bool overload = false);
    void IncludeAnimDataFrom(const idDeclMD6* declaration);
    void InitUserChannelToAnimationAliasMap();
    void InitHeadTrackGroups();
    bool HasIncludedDecl(const idDeclMD6* declaration) const;

    static const char* const meshKitGroupNames[3];
    bool FindAnimEvents(const idMD6Anim* animation, int startFrame,
        int endFrame, int eventNum,
        idStaticList<const idMD6AnimEvent*, 16>& events) const;

    idMD6Blend::configInfo_t* config;
    const idMD6Model* model;
    idStr parent;
    const idDeclMD6* parentDecl;
    idList<includeDecl_t, 5> declsToIncludeAnimDataFrom;
    idBounds referenceBounds;
    int numLoadErrors;
    idJointGroupCollection jointGroupCollection;
    idPropsCollection props;
    idAnimEvents animEvents;
    idEyeInfoCollection eyeInfoCollection;
    idList<idVarArgs<6>, 19> userProps;
    idList<idMD6Alias, 19> aliases;
    idHashIndex aliasHash;
    std::uint16_t curAliasHandle;
    idList<idHeadTrackGroup, 5> headTrackGroups;
    idList<idPair<idStr, idList<int, 19>>, 19> meshKitGroups[3];
    idStr meshKitDefault[3];
    idMorphVertices* morphVertices;
    idList<idMorphDef, 115> morphDefList;
    bool calcRefBoundsFromJoints;
    idList<idStr, 5> wrinkleMapRegionExpressions;
    float attachmentOverrideScale;
    int modelCaps;
    int userChannelWeightGroupOverride;
    aliasHandle_t baseUserChannelAlias;
    idList<aliasHandle_t, 19> userChannelToAnimationAliasMap;
    idList<idPair<idIndex<short, invalidUserChannelIndex_t>,
        aliasHandle_t>, 19> userChannelToAnimationAliasOverrides;

    static idDeclInfoTemplate<idDeclMD6> resourceList;
};

static_assert(sizeof(idDeclMD6::includeDecl_t) == 8,
    "Recovered MD6 include-declaration ABI changed");
static_assert(sizeof(idDeclMD6::idHeadTrackJoint) == 12,
    "Recovered head-track joint ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDeclMD6::idHeadTrackGroup) == 28,
    "Recovered head-track group ABI changed");
static_assert(sizeof(idDeclMD6::animEventData_t) == 8,
    "Recovered animation-event data ABI changed");
static_assert(sizeof(idDeclMD6) == 756,
    "Recovered MD6 declaration ABI changed");
#endif
