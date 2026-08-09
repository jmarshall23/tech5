#include "models/skeletalanimation/jointgroup.h"

#include "idlib/text/str.h"

idJointGroupCollection::idJointGroupCollection() = default;

void idJointGroupCollection::Free() {
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        jointGroupsByType[type].ClearFree();
    }
    jointGroups.ClearFree();
}

const idJointGroup* idJointGroupCollection::GetJointGroup(
    const jointGroupHandle_t handle) const {
    if (!handle.IsValid()) return nullptr;
    for (int index = 0; index < jointGroups.Num(); ++index) {
        if (jointGroups[index].handle == handle) return &jointGroups[index];
    }
    return nullptr;
}

idJointGroup* idJointGroupCollection::GetJointGroupForName(
    const idJointGroup::jointGroup_t type, const char* name) {
    return const_cast<idJointGroup*>(
        static_cast<const idJointGroupCollection*>(this)
            ->GetJointGroupForName(type, name));
}

const idJointGroup* idJointGroupCollection::GetJointGroupForName(
    const idJointGroup::jointGroup_t type, const char* name) const {
    const int index = GetJointGroupIndex(type, name);
    return index >= 0 ? jointGroupsByType[type][index] : nullptr;
}

int idJointGroupCollection::GetJointGroupIndex(
    const idJointGroup::jointGroup_t type, const char* name) const {
    if (type < 0 || type >= idJointGroup::JOINTGROUP_MAX
        || name == nullptr) {
        return -1;
    }
    const idList<idJointGroup*, 30>& groups = jointGroupsByType[type];
    for (int index = 0; index < groups.Num(); ++index) {
        if (idStr::Icmp(groups[index]->groupName.c_str(), name) == 0) {
            return index;
        }
    }
    return -1;
}

int idJointGroupCollection::NumJointGroupsForType(
    const idJointGroup::jointGroup_t type) const {
    return type >= 0 && type < idJointGroup::JOINTGROUP_MAX
        ? jointGroupsByType[type].Num() : 0;
}

const idJointGroup* idJointGroupCollection::GetJointGroupForIndex(
    const idJointGroup::jointGroup_t type, const int index) const {
    if (type < 0 || type >= idJointGroup::JOINTGROUP_MAX || index < 0
        || index >= jointGroupsByType[type].Num()) {
        return nullptr;
    }
    return jointGroupsByType[type][index];
}

const idJointGroup* idJointGroupCollection::GetJointGroupForJoint(
    const idJointGroup::jointGroup_t type,
    const idIndex<short, invalidJointIndex_t> joint) const {
    if (type < 0 || type >= idJointGroup::JOINTGROUP_MAX) return nullptr;
    const idList<idJointGroup*, 30>& groups = jointGroupsByType[type];
    for (int group = 0; group < groups.Num(); ++group) {
        for (int index = 0; index < groups[group]->joints.Num(); ++index) {
            if (groups[group]->joints[index] == joint) return groups[group];
        }
    }
    return nullptr;
}

jointGroupHandle_t idJointGroupCollection::GetJointGroupHandle(
    const idJointGroup::jointGroup_t type,
    const idIndex<short, invalidJointIndex_t> joint) const {
    const idJointGroup* group = GetJointGroupForJoint(type, joint);
    return group != nullptr ? group->handle : jointGroupHandle_t();
}

idJointGroup* idJointGroupCollection::AddJointGroup(const char* name,
    const idJointGroup::jointGroup_t type) {
    if (type < 0 || type >= idJointGroup::JOINTGROUP_MAX) return nullptr;
    idJointGroup group;
    group.type = type;
    group.groupName.Set(name != nullptr ? name : "");
    group.args.surfType = 0;
    group.args.active = true;
    group.groupOffset.Set(0.0f, 0.0f, 0.0f);
    group.handle = jointGroupHandle_t(jointGroups.Num() + 1);
    if (jointGroups.Append(group) < 0) return nullptr;
    idJointGroup* added = &jointGroups[jointGroups.Num() - 1];
    jointGroupsByType[type].Append(added);
    return added;
}

void idJointGroupCollection::Condense() {
    jointGroups.Resize(jointGroups.Num());
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        jointGroupsByType[type].Resize(jointGroupsByType[type].Num());
    }
}
