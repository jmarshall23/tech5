#include "models/skeletalanimation/jointgroup.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "models/skeletalanimation/declmd6.h"

namespace {

bool JointTokenIs(const idToken& token, const char* text) {
    return idStr::Cmp(token.c_str(), text) == 0;
}

bool IsLegacyJointGroup(const char* token) {
    return idStr::Cmp(token, "radiusDamageGroup") == 0 ||
        idStr::Cmp(token, "headTrackingIKGroup") == 0 ||
        idStr::Cmp(token, "reparentGroup") == 0 ||
        idStr::Cmp(token, "upgradeGroup") == 0 ||
        idStr::Cmp(token, "autoblendGroup") == 0;
}

int JointGroupTypeForToken(const char* token) {
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        if (idStr::Icmp(token, idJointGroup::jointGroupNames[type]) == 0)
            return type;
    }
    // The recovered parser accepted the old name for the eye group.
    return idStr::Icmp(token, "misc") == 0
        ? idJointGroup::JOINTGROUP_EYES : -1;
}

void EnsureJointOffset(idJointGroup& group, const int index,
        const idVec3& value) {
    while (group.jointOffsets.Num() <= index)
        group.jointOffsets.Append(idVec3(0.0f, 0.0f, 0.0f));
    group.jointOffsets[index] = value;
}

void EnsureJointScalar(idJointGroup& group, const int index,
        const float value) {
    while (group.jointScalars.Num() <= index)
        group.jointScalars.Append(1.0f);
    group.jointScalars[index] = value;
}

} // namespace

const char* const idJointGroup::jointGroupNames[JOINTGROUP_MAX] = {
    "damageGroup", "painGroup", "twitchGroup", "deathGroup",
    "limbLossGroup", "headTrackingGroup", "focusGroup",
    "orientationGroup", "hitTestGroup", "eyeGroup", "feetGroup",
    "boundsGroup"
};

const char* const idJointGroup::jointGroupScalarNames[JOINTGROUP_MAX] = {
    "", "", "", "", "", "weight", "", "", "radius", "", "",
    "radius"
};

idJointGroup::SurfaceTypeResolver idJointGroup::surfaceTypeResolver = nullptr;
idJointGroup::SurfaceTypeNameCallback idJointGroup::surfaceTypeNameCallback =
    nullptr;

idJointGroup::idJointGroup(const jointGroup_t groupType)
    : type(groupType), args{3, true}, groupOffset(0.0f, 0.0f, 0.0f) {
}

void idJointGroup::SetSurfaceTypeResolver(
        const SurfaceTypeResolver resolver) {
    surfaceTypeResolver = resolver;
}

void idJointGroup::SetSurfaceTypeNameCallback(
        const SurfaceTypeNameCallback callback) {
    surfaceTypeNameCallback = callback;
}

void idJointGroup::Parse(idParser& parser, const idDeclMD6* declaration,
        int& loadErrors) {
    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) {
        ++loadErrors;
        return;
    }
    groupName.Set(token.c_str());
    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return;
    }

    const auto parseSurfaceType = [&]() {
        idToken surface;
        if (!parser.ReadToken(surface)) {
            ++loadErrors;
            return;
        }
        int value = args.surfType;
        bool resolved = surfaceTypeResolver != nullptr &&
            surfaceTypeResolver(surface.c_str(), value);
        if (!resolved && idStr::Icmp(surface.c_str(), "flesh") == 0) {
            value = 3;
            resolved = true;
        }
        if (!resolved && idStr::Icmp(surface.c_str(), "default") == 0) {
            value = 3;
            resolved = true;
        }
        if (!resolved && idStr::Icmp(surface.c_str(), "metal") == 0) {
            // The registered game enum is authoritative when installed.  One
            // is the recovered retail value for the only non-default surface
            // used by the shipped MD6 declarations.
            value = 1;
            resolved = true;
        }
        if (resolved) {
            args.surfType = value;
        } else {
            parser.Warning("Unknown surface type %s", surface.c_str());
            ++loadErrors;
        }
    };

    const auto parseArgs = [&]() {
        if (!parser.ExpectTokenString("{")) {
            ++loadErrors;
            return;
        }
        idToken arg;
        while (parser.ReadToken(arg)) {
            if (JointTokenIs(arg, "}")) break;
            if (JointTokenIs(arg, "vec3")) {
                if (!parser.Parse1DMatrix(3, &groupOffset.x)) ++loadErrors;
            } else if (JointTokenIs(arg, "surfType")) {
                parseSurfaceType();
            } else {
                parser.Warning(
                    "Unknown token '%s' while parsing args for joint group '%s' in decl '%s'",
                    arg.c_str(), groupName.c_str(),
                    declaration != nullptr ? declaration->GetName() : "");
                ++loadErrors;
            }
        }
    };

    const auto parseJointInfo = [&](const int index) {
        if (!parser.ExpectTokenString("{")) {
            ++loadErrors;
            return;
        }
        idToken info;
        while (parser.ReadToken(info)) {
            if (JointTokenIs(info, "}")) break;
            const char* scalarName = jointGroupScalarNames[type];
            if (scalarName[0] != '\0' && JointTokenIs(info, scalarName)) {
                EnsureJointScalar(*this, index, parser.ParseFloat());
            } else if (JointTokenIs(info, "offset")) {
                idVec3 offset(0.0f, 0.0f, 0.0f);
                if (parser.Parse1DMatrix(3, &offset.x)) {
                    EnsureJointOffset(*this, index, offset);
                } else {
                    ++loadErrors;
                }
            } else if (JointTokenIs(info, "surfType")) {
                parseSurfaceType();
            } else {
                parser.Warning(
                    "Unknown token '%s' while parsing joint scalar for joint group '%s', in decl '%s'",
                    info.c_str(), groupName.c_str(),
                    declaration != nullptr ? declaration->GetName() : "");
                ++loadErrors;
            }
        }
    };

    while (parser.ReadToken(token)) {
        if (JointTokenIs(token, "}")) break;
        if (JointTokenIs(token, "args") && parser.PeekTokenString("{")) {
            parseArgs();
            continue;
        }

        idStr jointName(token.c_str());
        jointName.MakeNameCanonical();
        const idIndex<short, invalidJointIndex_t> joint =
            declaration != nullptr ? declaration->GetJointIndex(jointName.c_str())
                                   : idIndex<short, invalidJointIndex_t>();
        if (!joint.IsValid()) {
            parser.Warning("Invalid joint name '%s' in joint group '%s' for decl '%s'",
                jointName.c_str(), groupName.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            if (parser.PeekTokenString("{")) parser.SkipBracedSection(true);
            ++loadErrors;
            continue;
        }

        const int index = joints.Append(joint);
        if (index < 0) {
            ++loadErrors;
            continue;
        }
        if (groupOffset.x != 0.0f || groupOffset.y != 0.0f ||
                groupOffset.z != 0.0f) {
            EnsureJointOffset(*this, index, groupOffset);
        }
        if (parser.PeekTokenString("{")) parseJointInfo(index);
    }
}

void idJointGroup::Write(const idDeclMD6* declaration,
        idFile_String& file, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%s%s \"%s\" {\n", prefix, jointGroupNames[type],
        groupName.c_str());
    if (groupOffset.x != 0.0f || groupOffset.y != 0.0f ||
            groupOffset.z != 0.0f || args.surfType != 3) {
        file.Printf("%s\targs {\n", prefix);
        if (groupOffset.x != 0.0f || groupOffset.y != 0.0f ||
                groupOffset.z != 0.0f) {
            file.Printf("%s\t\tvec3 ( %.9g %.9g %.9g )\n", prefix,
                groupOffset.x, groupOffset.y, groupOffset.z);
        }
        if (args.surfType != 3) {
            const char* surfaceName = surfaceTypeNameCallback != nullptr
                ? surfaceTypeNameCallback(args.surfType) : nullptr;
            if (surfaceName == nullptr) {
                if (args.surfType == 1) surfaceName = "Metal";
                else if (args.surfType == 3) surfaceName = "Flesh";
                else surfaceName = "Default";
            }
            file.Printf("%s\t\tsurfType %s\n", prefix, surfaceName);
        }
        file.Printf("%s\t}\n", prefix);
    }

    for (int index = 0; index < joints.Num(); ++index) {
        const char* jointName = declaration != nullptr
            ? declaration->GetJointName(joints[index]) : nullptr;
        if (jointName == nullptr) jointName = "<invalid>";
        const bool hasOffset = index < jointOffsets.Num();
        const bool hasScalar = index < jointScalars.Num() &&
            jointGroupScalarNames[type][0] != '\0';
        if (!hasOffset && !hasScalar) {
            file.Printf("%s\t%s\n", prefix, jointName);
            continue;
        }
        file.Printf("%s\t%s {\n", prefix, jointName);
        if (hasOffset) {
            file.Printf("%s\t\toffset ( %.9g %.9g %.9g )\n", prefix,
                jointOffsets[index].x, jointOffsets[index].y,
                jointOffsets[index].z);
        }
        if (hasScalar) {
            file.Printf("%s\t\t%s %.9g\n", prefix,
                jointGroupScalarNames[type], jointScalars[index]);
        }
        file.Printf("%s\t}\n", prefix);
    }
    file.Printf("%s}\n", prefix);
}

bool idJointGroup::Equal(const idDeclMD6* myDeclaration,
        const idJointGroup& other,
        const idDeclMD6* otherDeclaration) const {
    if (type != other.type || idStr::Cmp(groupName.c_str(),
            other.groupName.c_str()) != 0 ||
            joints.Num() != other.joints.Num() ||
            jointOffsets.Num() != other.jointOffsets.Num() ||
            jointScalars.Num() != other.jointScalars.Num() ||
            args.surfType != other.args.surfType) return false;
    for (int index = 0; index < jointOffsets.Num(); ++index) {
        const idVec3& left = jointOffsets[index];
        const idVec3& right = other.jointOffsets[index];
        if (left.x != right.x || left.y != right.y || left.z != right.z)
            return false;
    }
    for (int index = 0; index < jointScalars.Num(); ++index)
        if (jointScalars[index] != other.jointScalars[index]) return false;
    for (int index = 0; index < joints.Num(); ++index) {
        const char* leftName = myDeclaration != nullptr
            ? myDeclaration->GetJointName(joints[index]) : nullptr;
        const char* rightName = otherDeclaration != nullptr
            ? otherDeclaration->GetJointName(other.joints[index]) : nullptr;
        if (leftName == nullptr || rightName == nullptr ||
                idStr::Cmp(leftName, rightName) != 0) return false;
    }
    return true;
}

void idJointGroup::Copy(const idDeclMD6* myDeclaration,
        const idDeclMD6* otherDeclaration, const idJointGroup& other) {
    type = other.type;
    groupName = other.groupName;
    args = other.args;
    joints.Clear();
    for (int index = 0; index < other.joints.Num(); ++index) {
        const char* jointName = otherDeclaration != nullptr
            ? otherDeclaration->GetJointName(other.joints[index]) : nullptr;
        joints.Append(myDeclaration != nullptr && jointName != nullptr
            ? myDeclaration->GetJointIndex(jointName)
            : idIndex<short, invalidJointIndex_t>());
    }
    jointOffsets = other.jointOffsets;
    jointScalars = other.jointScalars;
}

idJointGroupCollection::idJointGroupCollection() = default;

void idJointGroupCollection::RebuildTypeViews() {
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type)
        jointGroupsByType[type].Clear();
    for (int index = 0; index < jointGroups.Num(); ++index) {
        idJointGroup& group = jointGroups[index];
        if (group.type >= 0 && group.type < idJointGroup::JOINTGROUP_MAX)
            jointGroupsByType[group.type].Append(&group);
    }
}

void idJointGroupCollection::Free() {
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        jointGroupsByType[type].ClearFree();
    }
    jointGroups.ClearFree();
}

int idJointGroupCollection::Parse(idParser& parser,
        const idDeclMD6* declaration) {
    idToken token;
    int loadErrors = 0;
    if (!parser.ExpectTokenString("{")) return 1;

    while (parser.ReadToken(token)) {
        if (JointTokenIs(token, "}")) break;
        if (JointTokenIs(token, "{")) {
            parser.SkipBracedSection(false);
            continue;
        }
        if (JointTokenIs(token, "jointGroup")) continue;

        const int groupType = JointGroupTypeForToken(token.c_str());
        if (groupType >= 0) {
            idJointGroup group(
                static_cast<idJointGroup::jointGroup_t>(groupType));
            group.Parse(parser, declaration, loadErrors);
            if (GetJointGroupForName(group.type,
                    group.groupName.c_str()) != nullptr) {
                parser.Warning("Duplicate joint group '%s' in modeldef '%s'",
                    group.groupName.c_str(),
                    declaration != nullptr ? declaration->GetName() : "");
                ++loadErrors;
                continue;
            }
            idJointGroup* added = AddJointGroup(group.groupName.c_str(),
                group.type);
            if (added != nullptr) {
                const jointGroupHandle_t handle = added->handle;
                *added = group;
                added->handle = handle;
                RebuildTypeViews();
            } else {
                ++loadErrors;
            }
            continue;
        }

        if (IsLegacyJointGroup(token.c_str())) {
            parser.SkipBracedSection(true);
        } else {
            parser.Warning(
                "Unknown token '%s' while parsing joint group collection for modeldef '%s'",
                token.c_str(),
                declaration != nullptr ? declaration->GetName() : "");
            ++loadErrors;
            if (parser.PeekTokenString("{")) parser.SkipBracedSection(true);
        }
    }
    Condense();
    return loadErrors;
}

void idJointGroupCollection::DuplicateInherited(const idDecl* declaration,
        const idDeclMD6* parentDeclaration,
        const idJointGroupCollection* parentCollection) {
    if (parentCollection == nullptr) return;
    const idDeclMD6* localDeclaration =
        dynamic_cast<const idDeclMD6*>(declaration);

    for (int groupIndex = 0;
            groupIndex < parentCollection->jointGroups.Num(); ++groupIndex) {
        const idJointGroup& inherited =
            parentCollection->jointGroups[groupIndex];
        if (GetJointGroupForName(inherited.type,
                inherited.groupName.c_str()) != nullptr) continue;

        idJointGroup* local = AddJointGroup(inherited.groupName.c_str(),
            inherited.type);
        if (local == nullptr) continue;
        const jointGroupHandle_t localHandle = local->handle;
        *local = inherited;
        local->handle = localHandle;
        local->joints.Clear();
        local->jointOffsets.Clear();
        local->jointScalars.Clear();

        for (int jointIndex = 0; jointIndex < inherited.joints.Num();
                ++jointIndex) {
            idIndex<short, invalidJointIndex_t> mapped =
                inherited.joints[jointIndex];
            if (localDeclaration != nullptr && parentDeclaration != nullptr) {
                const char* jointName = parentDeclaration->GetJointName(mapped);
                mapped = localDeclaration->GetJointIndex(jointName);
            }
            if (!mapped.IsValid()) continue;
            local->joints.Append(mapped);
            if (jointIndex < inherited.jointOffsets.Num())
                local->jointOffsets.Append(inherited.jointOffsets[jointIndex]);
            if (jointIndex < inherited.jointScalars.Num())
                local->jointScalars.Append(inherited.jointScalars[jointIndex]);
        }
        RebuildTypeViews();
    }
}

void idJointGroupCollection::Write(idFile_String& file,
        const idDeclMD6* declaration, const char* indent) const {
    const char* prefix = indent != nullptr ? indent : "";
    file.Printf("%sjointGroups {\n", prefix);
    idStr groupIndent(prefix);
    groupIndent.Append("\t");
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        for (int index = 0; index < jointGroupsByType[type].Num(); ++index) {
            const idJointGroup* group = jointGroupsByType[type][index];
            if (group != nullptr)
                group->Write(declaration, file, groupIndent.c_str());
        }
    }
    file.Printf("%s}\n", prefix);
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
    if (GetJointGroupForName(type, name) != nullptr) return nullptr;
    idJointGroup group(type);
    group.groupName.Set(name != nullptr ? name : "");
    group.handle = jointGroupHandle_t(jointGroups.Num() + 1);
    if (jointGroups.Append(group) < 0) return nullptr;
    RebuildTypeViews();
    idJointGroup* added = &jointGroups[jointGroups.Num() - 1];
    return added;
}

void idJointGroupCollection::Condense() {
    jointGroups.Resize(jointGroups.Num());
    RebuildTypeViews();
    for (int type = 0; type < idJointGroup::JOINTGROUP_MAX; ++type) {
        jointGroupsByType[type].Resize(jointGroupsByType[type].Num());
    }
}
