#include "models/skeletalanimation/animation.h"

#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/hashing/crc16.h"
#include "idlib/text/cmdargs.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6alias.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6skel.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

constexpr unsigned int JOINT_CONVERSION_MAGIC = 70666829u;
constexpr int CONVERSION_TABLE_SIZE = 256;

bool ReadExact(idFile* file, void* data, const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteExact(idFile* file, const void* data, const unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

template<typename Handle>
short FindHandleIndex(const idList<Handle, 5>& table, const Handle handle) {
    if (!handle.IsValid()) return -1;
    for (int index = 0; index < table.Num(); ++index)
        if (table[index] == handle) return static_cast<short>(index);
    return -1;
}

jointHandle_t JointLookup(const char* name) {
    return animationLocal.FindJointHandle(name);
}

const char* JointName(const jointHandle_t handle) {
    return animationLocal.GetJointName(handle);
}

userChannelHandle_t UserLookup(const char* name) {
    return animationLocal.FindUserChannelHandle(name);
}

const char* UserName(const userChannelHandle_t handle) {
    return animationLocal.GetUserChannelName(handle);
}

jointConversionHandle_t ConversionLookup(const char* name) {
    return animationLocal.FindJointConversionHandle(name);
}

const char* ConversionName(const jointConversionHandle_t handle) {
    return animationLocal.GetJointConversionName(handle);
}

} // namespace

idTypedResourceList<idJointConversion>
    idJointConversion::resourceList("jointConversion");
idAnimationLocal animationLocal;
idAnimation* animation = &animationLocal;

idJointConversion::idJointConversion()
    : handle(), checksum(), timestamp(~0u) {
    tableJoints.SetNum(CONVERSION_TABLE_SIZE);
    tableUserChannels.SetNum(CONVERSION_TABLE_SIZE);
    for (int index = 0; index < CONVERSION_TABLE_SIZE; ++index) {
        tableJoints[index].Invalidate();
        tableUserChannels[index].Invalidate();
    }
}

idJointConversion::~idJointConversion() = default;

idResourceList* idJointConversion::GetResourceList() { return &resourceList; }

void idJointConversion::GenerateChecksum() {
    std::uint16_t value = 0xFFFFu;
    for (int index = 0; index < tableJoints.Num(); ++index) {
        if (!tableJoints[index].IsValid()) continue;
        const char* name = animationLocal.GetJointName(tableJoints[index]);
        if (name != nullptr)
            CRC16_UpdateChecksum(value, name,
                static_cast<int>(std::strlen(name)));
        const std::uint16_t conversionIndex =
            static_cast<std::uint16_t>(index);
        CRC16_UpdateChecksum(value, &conversionIndex,
            sizeof(conversionIndex));
    }
    for (int index = 0; index < tableUserChannels.Num(); ++index) {
        if (!tableUserChannels[index].IsValid()) continue;
        const char* name = animationLocal.GetUserChannelName(
            tableUserChannels[index]);
        if (name != nullptr)
            CRC16_UpdateChecksum(value, name,
                static_cast<int>(std::strlen(name)));
        const std::uint16_t conversionIndex =
            static_cast<std::uint16_t>(index);
        CRC16_UpdateChecksum(value, &conversionIndex,
            sizeof(conversionIndex));
    }
    checksum = value;
}

bool idJointConversion::LoadText(const char* fileName) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idParser parser(262704);
    if (!parser.LoadFile(fileName, false)) return false;
    timestamp = fileSystem->GetTimestamp(fileName, false);
    for (int index = 0; index < CONVERSION_TABLE_SIZE; ++index) {
        tableJoints[index].Invalidate();
        tableUserChannels[index].Invalidate();
    }
    if (!parser.ExpectTokenString("MD6JointConversionVersion") ||
            parser.ParseInt() != 2 ||
            !parser.ExpectTokenString("jointConversion") ||
            !parser.ExpectTokenString("{")) return false;
    idToken token;
    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        const jointHandle_t joint = animationLocal.RegisterJoint(token.c_str());
        const int target = parser.ParseInt();
        if (target < 0 || target >= CONVERSION_TABLE_SIZE) return false;
        const short previous = FindHandleIndex(tableJoints, joint);
        if (previous >= 0 && previous != target) return false;
        tableJoints[target] = joint;
    }
    if (!parser.ExpectTokenString("userChannelConversion") ||
            !parser.ExpectTokenString("{")) return false;
    while (parser.ReadToken(token)) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        const userChannelHandle_t channel =
            animationLocal.RegisterUserChannel(token.c_str());
        const int target = parser.ParseInt();
        if (target < 0 || target >= CONVERSION_TABLE_SIZE) return false;
        const short previous = FindHandleIndex(tableUserChannels, channel);
        if (previous >= 0 && previous != target) return false;
        tableUserChannels[target] = channel;
    }
    GenerateChecksum();
    return !parser.HadError();
}

bool idJointConversion::LoadBinary(const char* fileName) {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileRead(fileName, true, false));
    unsigned int magic = 0, jointCount = 0, userCount = 0;
    idHandle<unsigned short, invalidCrc_t, 65535> newChecksum;
    unsigned int newTimestamp = 0;
    if (file.file == nullptr ||
            !ReadExact(file.file, &magic, sizeof(magic)) ||
            magic != JOINT_CONVERSION_MAGIC ||
            !ReadExact(file.file, &newTimestamp, sizeof(newTimestamp)) ||
            !ReadExact(file.file, &newChecksum, sizeof(newChecksum)) ||
            !ReadExact(file.file, &jointCount, sizeof(jointCount)) ||
            jointCount > CONVERSION_TABLE_SIZE) return false;
    idList<jointHandle_t, 5> newJoints;
    newJoints.SetNum(jointCount);
    for (unsigned int index = 0; index < jointCount; ++index)
        newJoints[index].Invalidate();
    idStr registeredName;
    for (unsigned int index = 0; index < jointCount; ++index) {
        file.file->ReadString(registeredName);
        newJoints[index] = registeredName.Length() != 0
            ? animationLocal.RegisterJoint(registeredName.c_str())
            : jointHandle_t();
    }
    if (!ReadExact(file.file, &userCount, sizeof(userCount)) ||
            userCount > CONVERSION_TABLE_SIZE) return false;
    idList<userChannelHandle_t, 5> newUsers;
    newUsers.SetNum(userCount);
    for (unsigned int index = 0; index < userCount; ++index)
        newUsers[index].Invalidate();
    for (unsigned int index = 0; index < userCount; ++index) {
        file.file->ReadString(registeredName);
        newUsers[index] = registeredName.Length() != 0
            ? animationLocal.RegisterUserChannel(registeredName.c_str())
            : userChannelHandle_t();
    }
    tableJoints.Swap(newJoints);
    tableUserChannels.Swap(newUsers);
    checksum = newChecksum;
    timestamp = newTimestamp;
    return true;
}

bool idJointConversion::WriteBinary(const char* fileName) const {
    if (fileName == nullptr || fileSystem == nullptr) return false;
    idFileLocal file(fileSystem->OpenFileWrite(fileName, FSPATH_BASE));
    if (file.file == nullptr) return false;
    const unsigned int jointCount = tableJoints.Num();
    const unsigned int userCount = tableUserChannels.Num();
    if (!WriteExact(file.file, &JOINT_CONVERSION_MAGIC,
            sizeof(JOINT_CONVERSION_MAGIC))) return false;
    if (!WriteExact(file.file, &timestamp, sizeof(timestamp)) ||
            !WriteExact(file.file, &checksum, sizeof(checksum)) ||
            !WriteExact(file.file, &jointCount, sizeof(jointCount)))
        return false;
    for (unsigned int index = 0; index < jointCount; ++index) {
        const char* name = tableJoints[index].IsValid()
            ? animationLocal.GetJointName(tableJoints[index]) : "";
        file.file->WriteString(name != nullptr ? name : "");
    }
    if (!WriteExact(file.file, &userCount, sizeof(userCount))) return false;
    for (unsigned int index = 0; index < userCount; ++index) {
        const char* name = tableUserChannels[index].IsValid()
            ? animationLocal.GetUserChannelName(tableUserChannels[index]) : "";
        file.file->WriteString(name != nullptr ? name : "");
    }
    return true;
}

void idJointConversion::MakeDefault(const char* fileName,
        const idList<idStr, 5>* jointNames,
        const idList<idStr, 5>* userChannelNames) {
    if (fileName == nullptr || fileSystem == nullptr) return;
    char binaryName[1024];
    if (!fileSystem->FixLongFilename("generated", "bmd6jointconversion",
            fileName, binaryName, sizeof(binaryName))) return;
    idJointConversion conversion;
    conversion.timestamp = ~0u;
    const int jointCount = jointNames != nullptr
        ? (std::min)(jointNames->Num(), CONVERSION_TABLE_SIZE) : 0;
    conversion.tableJoints.SetNum(jointCount);
    for (int index = 0; index < jointCount; ++index)
        conversion.tableJoints[index] = animationLocal.RegisterJoint(
            (*jointNames)[index].c_str());
    const int channelCount = userChannelNames != nullptr
        ? (std::min)(userChannelNames->Num(), CONVERSION_TABLE_SIZE) : 0;
    conversion.tableUserChannels.SetNum(channelCount);
    for (int index = 0; index < channelCount; ++index)
        conversion.tableUserChannels[index] =
            animationLocal.RegisterUserChannel(
                (*userChannelNames)[index].c_str());
    conversion.GenerateChecksum();
    conversion.WriteBinary(binaryName);
}

void idJointConversion::LoadResource() {
    bool loaded = false;
    if (fileSystem != nullptr) {
        char binaryName[1024];
        if (fileSystem->FixLongFilename("generated", "bmd6jointconversion",
                GetName(), binaryName, sizeof(binaryName)))
            loaded = LoadBinary(binaryName);
        if (!loaded) {
            loaded = LoadText(GetName());
            if (loaded && fileSystem->FixLongFilename("generated",
                    "bmd6jointconversion", GetName(), binaryName,
                    sizeof(binaryName))) WriteBinary(binaryName);
        }
    }
    if (!loaded) SetResourceError("failed to load joint conversion '%s'",
        GetName());
    else ClearResourceError();
}

bool idJointConversion::ReloadIfStale() {
    if (fileSystem == nullptr ||
            fileSystem->GetTimestamp(GetName(), false) == timestamp)
        return false;
    LoadResource();
    return true;
}

void idJointConversion::WriteResourceFile() {
    if (fileSystem == nullptr) return;
    char binaryName[1024];
    if (fileSystem->FixLongFilename("generated", "bmd6jointconversion",
            GetName(), binaryName, sizeof(binaryName))) WriteBinary(binaryName);
}

void idJointConversion::Print() {
    std::printf("%s: crc %u\n", GetName(), checksum.Get());
}

void idJointConversion::List() { Print(); }

idAnimationLocal::idAnimationLocal() : originJointHandle() {}
idAnimationLocal::~idAnimationLocal() { Shutdown(); }

void idAnimationLocal::Initialize() {
    if (!originJointHandle.IsValid()) originJointHandle = RegisterJoint("origin");
    idMD6Skel::SetRegistryCallbacks(JointLookup, JointName, UserLookup,
        UserName, ConversionLookup, ConversionName);
    idMD6Anim::SetCallbacks(ConversionLookup, ConversionName, nullptr, nullptr);
}

void idAnimationLocal::Shutdown() {
    for (int index = 0; index < conversions.Num(); ++index)
        if (conversions[index].conversion != nullptr &&
                conversions[index].conversion->resourceListPtr == nullptr)
            delete conversions[index].conversion;
    joints.ClearFree();
    userChannels.ClearFree();
    conversions.ClearFree();
    aliases.ClearFree();
    originJointHandle.Invalidate();
}

void idAnimationLocal::FreeDynamic() { aliases.Clear(); }
const char* idAnimationLocal::GetOriginJointName() const { return "origin"; }
jointHandle_t idAnimationLocal::GetOriginJointHandle() const {
    return originJointHandle;
}

jointHandle_t idAnimationLocal::RegisterJoint(const char* name) {
    const jointHandle_t found = FindJointHandle(name);
    if (found.IsValid()) return found;
    if (name == nullptr || joints.Num() >= 65535) return jointHandle_t();
    joints.Append(idStr(name));
    return jointHandle_t(static_cast<unsigned short>(joints.Num() - 1));
}

jointHandle_t idAnimationLocal::FindJointHandle(const char* name) const {
    if (name == nullptr) return jointHandle_t();
    for (int index = 0; index < joints.Num(); ++index)
        if (idStr::Icmp(joints[index].c_str(), name) == 0)
            return jointHandle_t(static_cast<unsigned short>(index));
    return jointHandle_t();
}

const char* idAnimationLocal::GetJointName(const jointHandle_t handle) const {
    return handle.IsValid() && handle.Get() < joints.Num()
        ? joints[handle.Get()].c_str() : "";
}

userChannelHandle_t idAnimationLocal::RegisterUserChannel(const char* name) {
    const userChannelHandle_t found = FindUserChannelHandle(name);
    if (found.IsValid()) return found;
    if (name == nullptr || userChannels.Num() >= 65535)
        return userChannelHandle_t();
    userChannels.Append(idStr(name));
    return userChannelHandle_t(
        static_cast<unsigned short>(userChannels.Num() - 1));
}

userChannelHandle_t idAnimationLocal::FindUserChannelHandle(
        const char* name) const {
    if (name == nullptr) return userChannelHandle_t();
    for (int index = 0; index < userChannels.Num(); ++index)
        if (idStr::Icmp(userChannels[index].c_str(), name) == 0)
            return userChannelHandle_t(static_cast<unsigned short>(index));
    return userChannelHandle_t();
}

const char* idAnimationLocal::GetUserChannelName(
        const userChannelHandle_t handle) const {
    return handle.IsValid() && handle.Get() < userChannels.Num()
        ? userChannels[handle.Get()].c_str() : "";
}

int idAnimationLocal::GetNumUserChannels() const { return userChannels.Num(); }

void idAnimationLocal::MakeDefaultJointConversion(const char* name,
        const idList<idStr, 5>* jointNames,
        const idList<idStr, 5>* channelNames) {
    if (name == nullptr) return;
    idJointConversion::MakeDefault(name, jointNames, channelNames);
    idJointConversion* conversion = new idJointConversion;
    conversion->SetName(name);
    if (jointNames != nullptr) {
        for (int index = 0; index < jointNames->Num() &&
                index < CONVERSION_TABLE_SIZE; ++index)
            conversion->tableJoints[index] =
                RegisterJoint((*jointNames)[index].c_str());
    }
    if (channelNames != nullptr) {
        for (int index = 0; index < channelNames->Num() &&
                index < CONVERSION_TABLE_SIZE; ++index)
            conversion->tableUserChannels[index] =
                RegisterUserChannel((*channelNames)[index].c_str());
    }
    conversion->GenerateChecksum();
    conversionEntry_t entry{};
    entry.conversion = conversion;
    entry.name = name;
    conversion->handle = static_cast<unsigned short>(conversions.Num());
    conversions.Append(entry);
}

jointConversionHandle_t idAnimationLocal::LoadJointConversion(
        const char* name) {
    const jointConversionHandle_t found = FindJointConversionHandle(name);
    if (found.IsValid()) return found;
    idJointConversion* conversion = static_cast<idJointConversion*>(
        idJointConversion::resourceList.Load(name, false, false));
    if (conversion == nullptr) return jointConversionHandle_t();
    conversionEntry_t entry{};
    entry.conversion = conversion;
    entry.name = name;
    conversion->handle = static_cast<unsigned short>(conversions.Num());
    conversions.Append(entry);
    return conversion->handle;
}

jointConversionHandle_t idAnimationLocal::FindJointConversionHandle(
        const char* name) const {
    if (name == nullptr) return jointConversionHandle_t();
    for (int index = 0; index < conversions.Num(); ++index)
        if (idStr::Icmp(conversions[index].name.c_str(), name) == 0)
            return jointConversionHandle_t(static_cast<unsigned short>(index));
    return jointConversionHandle_t();
}

const char* idAnimationLocal::GetJointConversionName(
        const jointConversionHandle_t handle) const {
    return handle.IsValid() && handle.Get() < conversions.Num()
        ? conversions[handle.Get()].name.c_str() : "";
}

void idAnimationLocal::UnregisterJointConversion(
        idJointConversion* conversion) {
    for (int index = 0; index < conversions.Num(); ++index) {
        if (conversions[index].conversion == conversion) {
            conversions[index].conversion = nullptr;
            conversions[index].name.Clear();
            return;
        }
    }
}

short idAnimationLocal::GetJointIndex(const jointConversionHandle_t conversion,
        const jointHandle_t joint) const {
    return conversion.IsValid() && conversion.Get() < conversions.Num() &&
            conversions[conversion.Get()].conversion != nullptr
        ? FindHandleIndex(conversions[conversion.Get()].conversion->tableJoints,
            joint) : -1;
}

short idAnimationLocal::GetJointIndex(const jointConversionHandle_t conversion,
        const char* jointName) const {
    return GetJointIndex(conversion, FindJointHandle(jointName));
}

short idAnimationLocal::GetJointIndex(const char* conversionName,
        const char* jointName) const {
    return GetJointIndex(FindJointConversionHandle(conversionName), jointName);
}

idHandle<unsigned short, invalidCrc_t, 65535>
idAnimationLocal::GetJointConversionCrc(
        const jointConversionHandle_t conversion) const {
    return conversion.IsValid() && conversion.Get() < conversions.Num() &&
            conversions[conversion.Get()].conversion != nullptr
        ? conversions[conversion.Get()].conversion->checksum
        : idHandle<unsigned short, invalidCrc_t, 65535>();
}

short idAnimationLocal::GetUserChannelIndex(
        const jointConversionHandle_t conversion,
        const userChannelHandle_t channel) const {
    return conversion.IsValid() && conversion.Get() < conversions.Num() &&
            conversions[conversion.Get()].conversion != nullptr
        ? FindHandleIndex(
            conversions[conversion.Get()].conversion->tableUserChannels,
            channel) : -1;
}

short idAnimationLocal::GetUserChannelIndex(
        const jointConversionHandle_t conversion, const char* channelName) const {
    return GetUserChannelIndex(conversion,
        FindUserChannelHandle(channelName));
}

short idAnimationLocal::GetUserChannelIndex(const char* conversionName,
        const char* channelName) const {
    return GetUserChannelIndex(FindJointConversionHandle(conversionName),
        channelName);
}

aliasHandle_t idAnimationLocal::RegisterAlias(
        const idDeclMD6* declaration, const char* name) {
    aliasHandle_t handle = FindAliasHandle(name);
    if (!handle.IsValid()) {
        aliasEntry_t entry;
        entry.name = name != nullptr ? name : "";
        const int index = aliases.Append(entry);
        if (index < 0 || index >= 65535) return aliasHandle_t();
        handle = aliasHandle_t(static_cast<unsigned short>(index));
    }
    if (declaration != nullptr)
        aliases[handle.Get()].declarations.AddUnique(declaration);
    return handle;
}

void idAnimationLocal::UnregisterAlias(const idDeclMD6* declaration,
        const aliasHandle_t handle) {
    if (handle.IsValid() && handle.Get() < aliases.Num())
        aliases[handle.Get()].declarations.Remove(declaration);
}

void idAnimationLocal::UnregisterAliases(const idDeclMD6* declaration) {
    for (int index = 0; index < aliases.Num(); ++index)
        aliases[index].declarations.Remove(declaration);
}

aliasHandle_t idAnimationLocal::FindAliasHandle(const idDeclMD6* declaration,
        const char* name) const {
    const aliasHandle_t handle = FindAliasHandle(name);
    return handle.IsValid() && declaration != nullptr &&
            aliases[handle.Get()].declarations.FindIndex(declaration) >= 0
        ? handle : aliasHandle_t();
}

aliasHandle_t idAnimationLocal::FindAliasHandle(const char* name) const {
    if (name == nullptr) return aliasHandle_t();
    for (int index = 0; index < aliases.Num(); ++index)
        if (idStr::Icmp(aliases[index].name.c_str(), name) == 0)
            return aliasHandle_t(static_cast<unsigned short>(index));
    return aliasHandle_t();
}

const char* idAnimationLocal::FindAliasName(const aliasHandle_t handle) const {
    return handle.IsValid() && handle.Get() < aliases.Num()
        ? aliases[handle.Get()].name.c_str() : "";
}

aliasHandle_t idAnimationLocal::AddStrongAliasRef(const char* name) {
    aliasHandle_t handle = FindAliasHandle(name);
    if (!handle.IsValid()) handle = RegisterAlias(nullptr, name);
    if (handle.IsValid()) ++aliases[handle.Get()].strongReferences;
    return handle;
}

aliasHandle_t idAnimationLocal::StrongLoadAlias(const idDeclMD6* declaration,
        const char* name) {
    const aliasHandle_t handle = RegisterAlias(declaration, name);
    if (handle.IsValid()) ++aliases[handle.Get()].strongReferences;
    return handle;
}

const idMD6Alias* idAnimationLocal::StrongLoadAlias(
        const idDeclMD6* declaration, const aliasHandle_t handle) {
    if (declaration == nullptr || !handle.IsValid()) return nullptr;
    for (int index = 0; index < declaration->aliases.Num(); ++index) {
        if (declaration->aliases[index].aliasHandle == handle) {
            ++aliases[handle.Get()].strongReferences;
            declaration->aliases[index].LoadAnims(declaration);
            return &declaration->aliases[index];
        }
    }
    return nullptr;
}

void idAnimationLocal::FinalizeAliasRefs() {
    for (int index = 0; index < aliases.Num(); ++index)
        if (aliases[index].strongReferences < 0)
            aliases[index].strongReferences = 0;
}

void idAnimationLocal::GetAliasRefs(const aliasHandle_t handle,
        const bool strongOnly,
        idList<const idDeclMD6*, 5>& references) const {
    references.Clear();
    if (!handle.IsValid() || handle.Get() >= aliases.Num() ||
            (strongOnly && aliases[handle.Get()].strongReferences == 0))
        return;
    references = aliases[handle.Get()].declarations;
}

void idAnimationLocal::VerifyAnimations(const idCmdArgs* const args) {
    float epsilon = 0.1f;
    float jointRadius = 1.0f;
    if (args != nullptr && args->Argc() > 1) {
        epsilon = std::strtof(args->Argv(1), nullptr);
    }
    if (args != nullptr && args->Argc() > 2) {
        jointRadius = std::strtof(args->Argv(2), nullptr);
    }
    for (int aliasIndex = 0; aliasIndex < aliases.Num(); ++aliasIndex) {
        const aliasHandle_t handle(
            static_cast<unsigned short>(aliasIndex));
        const aliasEntry_t& entry = aliases[aliasIndex];
        for (int declarationIndex = 0;
                declarationIndex < entry.declarations.Num();
                ++declarationIndex) {
            const idDeclMD6* const declaration =
                entry.declarations[declarationIndex];
            if (declaration == nullptr) continue;
            const idMD6Anim* const animationForAlias =
                declaration->AnimForAlias(handle, false);
            if (animationForAlias != nullptr) {
                animationForAlias->VerifyBoundingBoxes(declaration,
                    epsilon, jointRadius);
            }
        }
    }
}
