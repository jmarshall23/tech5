#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"

enum invalidJointGroupHandle : int;
enum invalidJointIndex_t : int;

using jointGroupHandle_t = idHandle<int, invalidJointGroupHandle, 0>;

class idJointGroup {
public:
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

    jointGroup_t type;
    idAtomicString groupName;
    idList<idIndex<short, invalidJointIndex_t>, 30> joints;
    idList<idVec3, 30> jointOffsets;
    idList<float, 30> jointScalars;
    jointGroupArgs_t args;
    idVec3 groupOffset;
    jointGroupHandle_t handle;
};

class idJointGroupCollection {
public:
    idJointGroupCollection();

    void Free();
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
};

static_assert(sizeof(idJointGroup::jointGroupArgs_t) == 8,
    "Recovered joint-group arguments ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idJointGroupCollection) == 208,
    "Recovered joint-group collection ABI changed");
#endif
