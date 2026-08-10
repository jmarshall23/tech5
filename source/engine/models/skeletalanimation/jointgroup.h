#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"

class idDecl;
class idDeclMD6;
class idFile_String;
class idParser;

enum invalidJointGroupHandle : int;
enum invalidJointIndex_t : int;

using jointGroupHandle_t = idHandle<int, invalidJointGroupHandle, 0>;

class idJointGroup {
public:
    using SurfaceTypeResolver = bool (*)(const char* name, int& value);
    using SurfaceTypeNameCallback = const char* (*)(int value);
    enum jointGroup_t : int {
        JOINTGROUP_DAMAGE = 0,
        JOINTGROUP_PAIN,
        JOINTGROUP_TWITCH,
        JOINTGROUP_DEATH,
        JOINTGROUP_LIMBLOSS,
        JOINTGROUP_HEADTRACKING,
        JOINTGROUP_FOCUS,
        JOINTGROUP_ORIENTATION,
        JOINTGROUP_HITTEST,
        JOINTGROUP_EYES,
        JOINTGROUP_FEET,
        JOINTGROUP_BOUNDS,
        JOINTGROUP_MAX
    };

    struct jointGroupArgs_t {
        int surfType;
        bool active;
    };

    explicit idJointGroup(jointGroup_t type = JOINTGROUP_DAMAGE);
    void Parse(idParser& parser, const idDeclMD6* declaration,
        int& loadErrors);
    void Write(const idDeclMD6* declaration, idFile_String& file,
        const char* indent) const;
    bool Equal(const idDeclMD6* myDeclaration,
        const idJointGroup& other,
        const idDeclMD6* otherDeclaration) const;
    void Copy(const idDeclMD6* myDeclaration,
        const idDeclMD6* otherDeclaration, const idJointGroup& other);
    static void SetSurfaceTypeResolver(SurfaceTypeResolver resolver);
    static void SetSurfaceTypeNameCallback(SurfaceTypeNameCallback callback);

    static const char* const jointGroupNames[JOINTGROUP_MAX];
    static const char* const jointGroupScalarNames[JOINTGROUP_MAX];

    jointGroup_t type;
    idAtomicString groupName;
    idList<idIndex<short, invalidJointIndex_t>, 30> joints;
    idList<idVec3, 30> jointOffsets;
    idList<float, 30> jointScalars;
    jointGroupArgs_t args;
    idVec3 groupOffset;
    jointGroupHandle_t handle;

private:
    static SurfaceTypeResolver surfaceTypeResolver;
    static SurfaceTypeNameCallback surfaceTypeNameCallback;
};

class idJointGroupCollection {
public:
    idJointGroupCollection();

    void Free();
    int Parse(idParser& parser, const idDeclMD6* declaration);
    void DuplicateInherited(const idDecl* declaration,
        const idDeclMD6* parentDeclaration,
        const idJointGroupCollection* parentCollection);
    void Write(idFile_String& file, const idDeclMD6* declaration,
        const char* indent) const;
    const idJointGroup* GetJointGroup(jointGroupHandle_t handle) const;
    idJointGroup* GetJointGroupForName(idJointGroup::jointGroup_t type,
        const char* name);
    const idJointGroup* GetJointGroupForName(
        idJointGroup::jointGroup_t type, const char* name) const;
    int GetJointGroupIndex(idJointGroup::jointGroup_t type,
        const char* name) const;
    int NumJointGroupsForType(idJointGroup::jointGroup_t type) const;
    const idJointGroup* GetJointGroupForIndex(
        idJointGroup::jointGroup_t type, int index) const;
    const idJointGroup* GetJointGroupForJoint(
        idJointGroup::jointGroup_t type,
        idIndex<short, invalidJointIndex_t> joint) const;
    jointGroupHandle_t GetJointGroupHandle(idJointGroup::jointGroup_t type,
        idIndex<short, invalidJointIndex_t> joint) const;
    idJointGroup* AddJointGroup(const char* name,
        idJointGroup::jointGroup_t type);
    void Condense();

    idList<idJointGroup, 30> jointGroups;
    idList<idJointGroup*, 30>
        jointGroupsByType[idJointGroup::JOINTGROUP_MAX];

private:
    void RebuildTypeViews();
};

static_assert(sizeof(idJointGroup::jointGroupArgs_t) == 8,
    "Recovered joint-group arguments ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idJointGroupCollection) == 208,
    "Recovered joint-group collection ABI changed");
#endif
