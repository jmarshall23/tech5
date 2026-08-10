#include "decls/animwebs/declanimwebnode.h"
#include "decls/declenv.h"
#include "decls/declflare.h"
#include "decls/declfx.h"
#include "decls/declribbon.h"
#include "decls/decltable.h"
#include "models/particles/declparticle.h"
#include "models/skeletalanimation/declmd6.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6animtree.h"
#include "renderer/declmaterial.h"
#include "renderer/declrenderparm.h"

#include <cstdlib>

namespace {

template<class resourceType>
const resourceType* LoadDecl(idResourceList& list, const char* name) {
    if (name == nullptr || name[0] == '\0') return nullptr;
    return static_cast<const resourceType*>(list.Load(name, true, false));
}

int ParseNumericFlag(const char* name) {
    if (name == nullptr || name[0] == '\0') return -1;
    char* end = nullptr;
    const long value = std::strtol(name, &end, 0);
    return end != name && *end == '\0' ? static_cast<int>(value) : -1;
}

} // namespace

const idDeclEnv* Decls_FindEnv(const char* name) {
    return LoadDecl<idDeclEnv>(idDeclEnv::resourceList, name);
}

const idDeclFlare* Decls_FindFlare(const char* name) {
    return LoadDecl<idDeclFlare>(idDeclFlare::resourceList, name);
}

const idDeclFX* Decls_FindFX(const char* name) {
    return LoadDecl<idDeclFX>(idDeclFX::resourceList, name);
}

const idDeclMD6* Decls_FindMD6Declaration(const char* name) {
    return LoadDecl<idDeclMD6>(idDeclMD6::resourceList, name);
}

const idDeclParticle* Decls_FindParticle(const char* name) {
    return LoadDecl<idDeclParticle>(idDeclParticle::resourceList, name);
}

const idDeclRenderParm* Decls_FindRenderParm(const char* name) {
    return LoadDecl<idDeclRenderParm>(idDeclRenderParm::resourceList, name);
}

const idDeclRibbon* Decls_FindRibbon(const char* name) {
    return LoadDecl<idDeclRibbon>(idDeclRibbon::resourceList, name);
}

const idDeclTable* Decls_FindTable(const char* name) {
    return LoadDecl<idDeclTable>(idDeclTable::resourceList, name);
}

const idMaterial* Decls_FindMaterial(const char* name) {
    return LoadDecl<idMaterial>(idMaterial::resourceList, name);
}

const char* Decls_AFMaterialName(const idMaterial* material) {
    return material != nullptr ? material->GetName() : "";
}

const char* Decls_MD6DeclarationName(const idDeclMD6* declaration) {
    return declaration != nullptr ? declaration->GetName() : "";
}

const char* Decls_FXResourceName(const void* resource) {
    return resource != nullptr
        ? reinterpret_cast<const idResource*>(resource)->GetName() : "";
}

int Decls_FXParticleDuration(const idDeclParticle* particle) {
    return particle != nullptr ? particle->maxSystemDuration : 0;
}

const char* Decls_FXConditionName(fxCondition_t condition) {
    return condition == FX_NONE ? "FX_NONE" : "FX_NONE";
}

fxCondition_t Decls_FXConditionForName(const char* name) {
    if (name == nullptr || idStr::Icmp(name, "FX_NONE") == 0
            || idStr::Icmp(name, "none") == 0)
        return FX_NONE;
    const int numeric = ParseNumericFlag(name);
    return static_cast<fxCondition_t>(numeric >= 0 ? numeric : FX_NONE);
}

const char* Decls_FXExtraConditionName(fxExtraCondition_t condition) {
    struct Entry { fxExtraCondition_t value; const char* name; };
    static const Entry entries[] = {
        {FX_EXTRA_COND_NONE, "FX_EXTRA_COND_NONE"},
        {FX_EXTRA_COND_WEAP_AMMOTYPE_0, "FX_EXTRA_COND_WEAP_AMMOTYPE_0"},
        {FX_EXTRA_COND_WEAP_AMMOTYPE_1, "FX_EXTRA_COND_WEAP_AMMOTYPE_1"},
        {FX_EXTRA_COND_WEAP_AMMOTYPE_2, "FX_EXTRA_COND_WEAP_AMMOTYPE_2"},
        {FX_EXTRA_COND_WEAP_AMMOTYPE_3, "FX_EXTRA_COND_WEAP_AMMOTYPE_3"},
        {FX_EXTRA_COND_WEAP_ATTACK_DEFAULT, "FX_EXTRA_COND_WEAP_ATTACK_DEFAULT"},
        {FX_EXTRA_COND_WEAP_ATTACK_LEFT, "FX_EXTRA_COND_WEAP_ATTACK_LEFT"},
        {FX_EXTRA_COND_WEAP_ATTACK_RIGHT, "FX_EXTRA_COND_WEAP_ATTACK_RIGHT"},
        {FX_EXTRA_COND_WEAP_ATTACK_LEFT2, "FX_EXTRA_COND_WEAP_ATTACK_LEFT2"},
        {FX_EXTRA_COND_WEAP_ATTACK_RIGHT2, "FX_EXTRA_COND_WEAP_ATTACK_RIGHT2"},
        {FX_EXTRA_COND_SMALL, "FX_EXTRA_COND_SMALL"},
        {FX_EXTRA_COND_MEDIUM, "FX_EXTRA_COND_MEDIUM"},
        {FX_EXTRA_COND_LARGE, "FX_EXTRA_COND_LARGE"},
        {FX_EXTRA_COND_ENGINE_1, "FX_EXTRA_COND_ENGINE_1"},
        {FX_EXTRA_COND_ENGINE_2, "FX_EXTRA_COND_ENGINE_2"}
    };
    for (const Entry& entry : entries)
        if (entry.value == condition) return entry.name;
    return "FX_EXTRA_COND_NONE";
}

fxExtraCondition_t Decls_FXExtraConditionForName(const char* name) {
    if (name == nullptr) return FX_EXTRA_COND_NONE;
    static const fxExtraCondition_t values[] = {
        FX_EXTRA_COND_NONE,
        FX_EXTRA_COND_WEAP_AMMOTYPE_0, FX_EXTRA_COND_WEAP_AMMOTYPE_1,
        FX_EXTRA_COND_WEAP_AMMOTYPE_2, FX_EXTRA_COND_WEAP_AMMOTYPE_3,
        FX_EXTRA_COND_WEAP_ATTACK_DEFAULT, FX_EXTRA_COND_WEAP_ATTACK_LEFT,
        FX_EXTRA_COND_WEAP_ATTACK_RIGHT, FX_EXTRA_COND_WEAP_ATTACK_LEFT2,
        FX_EXTRA_COND_WEAP_ATTACK_RIGHT2, FX_EXTRA_COND_SMALL,
        FX_EXTRA_COND_MEDIUM, FX_EXTRA_COND_LARGE,
        FX_EXTRA_COND_ENGINE_1, FX_EXTRA_COND_ENGINE_2
    };
    for (fxExtraCondition_t value : values)
        if (idStr::Icmp(name, Decls_FXExtraConditionName(value)) == 0)
            return value;
    const int numeric = ParseNumericFlag(name);
    return static_cast<fxExtraCondition_t>(
        numeric >= 0 ? numeric : FX_EXTRA_COND_NONE);
}

void Decls_AFGetJointList(const idDeclMD6* model, const char* expression,
        idList<idIndex<short, invalidJointIndex_t>, 71>& joints) {
    joints.Clear();
    if (model == nullptr || expression == nullptr) return;
    idList<idIndex<short, invalidJointIndex_t>, 5> recovered;
    model->GetJointList(expression, recovered);
    joints.SetNum(recovered.Num());
    for (int index = 0; index < recovered.Num(); ++index)
        joints[index] = recovered[index];
}

const idMD6Anim* AnimWeb_LoadAnim(const char* name, bool makeDefault) {
    if (name == nullptr || name[0] == '\0') return nullptr;
    return static_cast<const idMD6Anim*>(
        idMD6Anim::resourceList.Load(name, makeDefault, false));
}

const char* AnimWeb_GetAnimName(const idMD6Anim* animation) {
    return animation != nullptr ? animation->GetName() : "";
}

int AnimWeb_GetAnimNumFrames(const idMD6Anim* animation) {
    return animation != nullptr && animation->animData != nullptr
        ? animation->animData->numFrames : 0;
}

const idMD6Anim* AnimWeb_SelectAliasAnim(const idDeclMD6* declaration,
        idAnimAliasHandle aliasHandle, int index, bool load) {
    if (declaration == nullptr || !aliasHandle.IsValid()) return nullptr;
    const idMD6Alias* alias = declaration->FindAlias(aliasHandle, true);
    if (alias == nullptr || index < 0 || index >= alias->animRefs.Num())
        return nullptr;
    const char* name = alias->animRefs[index].c_str();
    idResource* resource = idMD6Anim::resourceList.FindExisting(name, true);
    if (resource == nullptr && load)
        resource = idMD6Anim::resourceList.Load(name, false, true);
    return static_cast<const idMD6Anim*>(resource);
}

bool Decls_AnimWebResolveAnim(const idDeclAnimWeb& declaration,
        int modelIndex, const char* name, idMD6AnimProps& properties) {
    if (name == nullptr || name[0] == '\0') return false;
    const idDeclMD6* model = modelIndex >= 0
            && modelIndex < declaration.models.Num()
        ? declaration.models[modelIndex] : nullptr;
    if (model != nullptr) {
        const aliasHandle_t handle = model->FindAliasHandle(name);
        if (handle.IsValid()) {
            properties.SetAliasHandle(handle);
            return true;
        }
    }
    const idMD6Anim* animation = AnimWeb_LoadAnim(name, true);
    properties.SetAnim(animation);
    return animation != nullptr;
}

const char* Decls_AnimWebAnimName(const idDeclMD6* model,
        const idMD6AnimProps& properties) {
    if (properties.aliasHandle.IsValid() && model != nullptr) {
        const idMD6Alias* alias = model->FindAlias(properties.aliasHandle, true);
        return alias != nullptr ? alias->name.c_str() : "";
    }
    return AnimWeb_GetAnimName(properties.anim);
}

const idMD6Anim* Decls_AnimWebBlendAnimation(
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* model, int animationIndex) {
    if (animationIndex < 0 || animationIndex >= modelInfo.animProps.Num())
        return nullptr;
    const idMD6Anim* animation = modelInfo.animProps[animationIndex].anim;
    return animation != nullptr
            && (model == nullptr || animation->AnimIsOkForModel(model))
        ? animation : nullptr;
}

const char* AnimWeb_GetOriginBlendName(char value) {
    static const char* const names[] = {
        "ORIGINBLEND_DEFAULT", "ORIGINBLEND_SOURCE", "ORIGINBLEND_DEST"
    };
    const unsigned int index = static_cast<unsigned char>(value);
    return index < 3 ? names[index] : "ORIGINBLEND_DEFAULT";
}

bool AnimWeb_ParseOriginBlend(const char* name, char& value) {
    if (name == nullptr) return false;
    static const char* const names[][2] = {
        {"ORIGINBLEND_DEFAULT", "ORIGINBLEND_BRANCH"},
        {"ORIGINBLEND_SOURCE", "ORIGINBLEND_LEFT"},
        {"ORIGINBLEND_DEST", "ORIGINBLEND_RIGHT"}
    };
    for (int index = 0; index < 3; ++index) {
        if (idStr::Icmp(name, names[index][0]) == 0
                || idStr::Icmp(name, names[index][1]) == 0) {
            value = static_cast<char>(index);
            return true;
        }
    }
    value = static_cast<char>(idMD6Blend::ORIGINBLEND_MAX);
    return false;
}

const char* AnimWeb_GetBlendTypeName(char value) {
    static const char* const names[] = {
        "BLEND_LINEAR", "BLEND_EASEIN", "BLEND_EASEOUT",
        "BLEND_EASEIN_EASEOUT"
    };
    const unsigned int index = static_cast<unsigned char>(value);
    return index < 4 ? names[index] : "BLEND_LINEAR";
}

bool AnimWeb_ParseBlendType(const char* name, char& value) {
    if (name == nullptr) return false;
    static const char* const names[] = {
        "BLEND_LINEAR", "BLEND_EASEIN", "BLEND_EASEOUT",
        "BLEND_EASEIN_EASEOUT"
    };
    for (int index = 0; index < 4; ++index) {
        if (idStr::Icmp(name, names[index]) == 0) {
            value = static_cast<char>(index);
            return true;
        }
    }
    value = static_cast<char>(idMD6Branch::BLEND_TYPE_COUNT);
    return false;
}

int Decls_AnimWebEdgeCustomFlag(const char* name) {
    return ParseNumericFlag(name);
}

int Decls_AnimWebNodeCustomFlag(const char* name) {
    return ParseNumericFlag(name);
}

void Decls_AnimWebNodeCustomFlagNames(unsigned int flags, idStr& names) {
    names.Clear();
    if (flags != 0) names.Format("0x%X", flags);
}

bool Decls_InitAnimWebBestLeaf(idMD6Node* node,
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idList<idMD6Node*, 5>& leaves) {
    if (node == nullptr || node->type != idMD6Node::NODE_BEST_LEAF)
        return false;
    idMD6BestLeaf* best = static_cast<idMD6BestLeaf*>(node);
    best->leafList.SetNum(leaves.Num());
    best->tagList.SetNum(leaves.Num());
    for (int index = 0; index < leaves.Num(); ++index) {
        best->leafList[index] = leaves[index];
        best->tagList[index] = index < modelInfo.animProps.Num()
            ? modelInfo.animProps[index].tags : 0;
        if (leaves[index] != nullptr
                && leaves[index]->type == idMD6Node::NODE_TAG_FILTER)
            best->filterList.Append(static_cast<idMD6Filter*>(leaves[index]));
    }
    best->bestLeafIndex = static_cast<std::uint16_t>(-1);
    if (modelInfo.tagGroups != nullptr && modelInfo.tagGroups->Num() > 0) {
        best->tagGroup = &(*modelInfo.tagGroups)[0];
        for (int tag = 0; tag < best->tagGroup->tagList.Num(); ++tag)
            if (best->tagGroup->tagList[tag].isDefault) {
                best->defaultTag = 1u << tag;
                break;
            }
    }
    return best->leafList.Num() != 0;
}

bool Decls_InitAnimWebTagFilter(idMD6Node* node,
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const char* groupName, idMD6Node*) {
    if (node == nullptr || node->type != idMD6Node::NODE_TAG_FILTER
            || groupName == nullptr || modelInfo.tagGroups == nullptr)
        return false;
    idMD6TagFilter* filter = static_cast<idMD6TagFilter*>(node);
    for (int index = 0; index < modelInfo.tagGroups->Num(); ++index) {
        const idDeclAnimWebTagGroup& group = (*modelInfo.tagGroups)[index];
        if (idStr::Icmp(group.name.c_str(), groupName) == 0) {
            filter->tagGroup = &group;
            filter->tagGroupIndex = static_cast<std::uint8_t>(index);
            filter->tagMask = group.tagList.Num() >= 32
                ? ~0u : ((1u << group.tagList.Num()) - 1u);
            return true;
        }
    }
    return false;
}
