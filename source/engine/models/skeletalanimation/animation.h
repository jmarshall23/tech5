#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/hashing/crc8.h"
#include "idlib/math/random.h"
#include "idlib/text/str.h"
#include "framework/resource.h"
#include "framework/resourcelist.h"

class idDeclMD6;
class idJointConversion;
class idMD6Alias;

enum invalidAliasHandle_t : int;
enum invalidJointConversionHandle_t : int;
enum invalidJointHandle_t : int;
enum invalidUserChannelHandle_t : int;

using aliasHandle_t =
    idHandle<unsigned short, invalidAliasHandle_t, 65535>;
using jointConversionHandle_t =
    idHandle<unsigned short, invalidJointConversionHandle_t, 65535>;
using jointHandle_t =
    idHandle<unsigned short, invalidJointHandle_t, 65535>;
using userChannelHandle_t =
    idHandle<unsigned short, invalidUserChannelHandle_t, 65535>;

// Platform-neutral animation registry interface.  The recovered executable
// used hidden return pointers for the small handle values; normal C++ return
// values preserve the data ABI without exposing the Xbox calling convention.
class idAnimation {
public:
    virtual ~idAnimation() = default;
    virtual void Initialize() = 0;
    virtual void Shutdown() = 0;
    virtual void FreeDynamic() = 0;
    virtual const char* GetOriginJointName() const = 0;
    virtual jointHandle_t GetOriginJointHandle() const = 0;
    virtual jointHandle_t RegisterJoint(const char* name) = 0;
    virtual jointHandle_t FindJointHandle(const char* name) const = 0;
    virtual const char* GetJointName(jointHandle_t handle) const = 0;
    virtual userChannelHandle_t RegisterUserChannel(const char* name) = 0;
    virtual userChannelHandle_t FindUserChannelHandle(
        const char* name) const = 0;
    virtual const char* GetUserChannelName(
        userChannelHandle_t handle) const = 0;
    virtual int GetNumUserChannels() const = 0;
    virtual void MakeDefaultJointConversion(const char* name,
        const idList<idStr, 5>* joints,
        const idList<idStr, 5>* userChannels) = 0;
    virtual jointConversionHandle_t FindJointConversionHandle(
        const char* name) const = 0;
    virtual const char* GetJointConversionName(
        jointConversionHandle_t handle) const = 0;
    virtual void UnregisterJointConversion(idJointConversion* conversion) = 0;
    virtual short GetJointIndex(jointConversionHandle_t conversion,
        jointHandle_t joint) const = 0;
    virtual short GetJointIndex(jointConversionHandle_t conversion,
        const char* jointName) const = 0;
    virtual short GetJointIndex(const char* conversionName,
        const char* jointName) const = 0;
    virtual idHandle<unsigned short, invalidCrc_t, 65535>
        GetJointConversionCrc(jointConversionHandle_t conversion) const = 0;
    virtual short GetUserChannelIndex(jointConversionHandle_t conversion,
        userChannelHandle_t channel) const = 0;
    virtual short GetUserChannelIndex(jointConversionHandle_t conversion,
        const char* channelName) const = 0;
    virtual short GetUserChannelIndex(const char* conversionName,
        const char* channelName) const = 0;
    virtual aliasHandle_t RegisterAlias(const idDeclMD6* declaration,
        const char* name) = 0;
    virtual void UnregisterAlias(const idDeclMD6* declaration,
        aliasHandle_t handle) = 0;
    virtual void UnregisterAliases(const idDeclMD6* declaration) = 0;
    virtual aliasHandle_t FindAliasHandle(const idDeclMD6* declaration,
        const char* name) const = 0;
    virtual aliasHandle_t FindAliasHandle(const char* name) const = 0;
    virtual const char* FindAliasName(aliasHandle_t handle) const = 0;
    virtual aliasHandle_t AddStrongAliasRef(const char* name) = 0;
    virtual aliasHandle_t StrongLoadAlias(const idDeclMD6* declaration,
        const char* name) = 0;
    virtual const idMD6Alias* StrongLoadAlias(
        const idDeclMD6* declaration, aliasHandle_t handle) = 0;
    virtual void FinalizeAliasRefs() = 0;
    virtual void GetAliasRefs(aliasHandle_t handle, bool strongOnly,
        idList<const idDeclMD6*, 5>& references) const = 0;

    idRandom2 randomNumberGenerator;
};

class idJointConversion : public idResource {
public:
    idJointConversion();
    ~idJointConversion() override;

    void LoadResource() override;
    bool ReloadIfStale() override;
    void WriteResourceFile() override;
    idResourceList* GetResourceList() override;
    void Print() override;
    void List() override;

    bool LoadText(const char* fileName);
    bool LoadBinary(const char* fileName);
    bool WriteBinary(const char* fileName) const;
    void GenerateChecksum();

    jointConversionHandle_t handle;
    idList<jointHandle_t, 5> tableJoints;
    idList<userChannelHandle_t, 5> tableUserChannels;
    idHandle<unsigned short, invalidCrc_t, 65535> checksum;
    unsigned int timestamp;

    static idTypedResourceList<idJointConversion> resourceList;
};

class idAnimationLocal final : public idAnimation {
public:
    idAnimationLocal();
    ~idAnimationLocal() override;

    void Initialize() override;
    void Shutdown() override;
    void FreeDynamic() override;
    const char* GetOriginJointName() const override;
    jointHandle_t GetOriginJointHandle() const override;
    jointHandle_t RegisterJoint(const char* name) override;
    jointHandle_t FindJointHandle(const char* name) const override;
    const char* GetJointName(jointHandle_t handle) const override;
    userChannelHandle_t RegisterUserChannel(const char* name) override;
    userChannelHandle_t FindUserChannelHandle(
        const char* name) const override;
    const char* GetUserChannelName(
        userChannelHandle_t handle) const override;
    int GetNumUserChannels() const override;
    void MakeDefaultJointConversion(const char* name,
        const idList<idStr, 5>* joints,
        const idList<idStr, 5>* userChannels) override;
    jointConversionHandle_t FindJointConversionHandle(
        const char* name) const override;
    const char* GetJointConversionName(
        jointConversionHandle_t handle) const override;
    void UnregisterJointConversion(idJointConversion* conversion) override;
    short GetJointIndex(jointConversionHandle_t conversion,
        jointHandle_t joint) const override;
    short GetJointIndex(jointConversionHandle_t conversion,
        const char* jointName) const override;
    short GetJointIndex(const char* conversionName,
        const char* jointName) const override;
    idHandle<unsigned short, invalidCrc_t, 65535>
        GetJointConversionCrc(
            jointConversionHandle_t conversion) const override;
    short GetUserChannelIndex(jointConversionHandle_t conversion,
        userChannelHandle_t channel) const override;
    short GetUserChannelIndex(jointConversionHandle_t conversion,
        const char* channelName) const override;
    short GetUserChannelIndex(const char* conversionName,
        const char* channelName) const override;
    aliasHandle_t RegisterAlias(const idDeclMD6* declaration,
        const char* name) override;
    void UnregisterAlias(const idDeclMD6* declaration,
        aliasHandle_t handle) override;
    void UnregisterAliases(const idDeclMD6* declaration) override;
    aliasHandle_t FindAliasHandle(const idDeclMD6* declaration,
        const char* name) const override;
    aliasHandle_t FindAliasHandle(const char* name) const override;
    const char* FindAliasName(aliasHandle_t handle) const override;
    aliasHandle_t AddStrongAliasRef(const char* name) override;
    aliasHandle_t StrongLoadAlias(const idDeclMD6* declaration,
        const char* name) override;
    const idMD6Alias* StrongLoadAlias(const idDeclMD6* declaration,
        aliasHandle_t handle) override;
    void FinalizeAliasRefs() override;
    void GetAliasRefs(aliasHandle_t handle, bool strongOnly,
        idList<const idDeclMD6*, 5>& references) const override;

    jointConversionHandle_t LoadJointConversion(const char* name);

private:
    struct conversionEntry_t {
        idJointConversion* conversion;
        idStr name;
    };
    struct aliasEntry_t {
        idStr name;
        idList<const idDeclMD6*, 5> declarations;
        int strongReferences;

        aliasEntry_t() : strongReferences(0) {}
    };

    idList<idStr, 30> joints;
    idList<idStr, 30> userChannels;
    idList<conversionEntry_t, 30> conversions;
    idList<aliasEntry_t, 30> aliases;
    jointHandle_t originJointHandle;
};

extern idAnimationLocal animationLocal;
extern idAnimation* animation;
