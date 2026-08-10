#include "models/skeletalanimation/declmd6.h"
#include "idlib/filesystem/file.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "models/skeletalanimation/md6anim.h"
#include "models/skeletalanimation/md6model.h"
#include "models/skeletalanimation/md6skel.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>

idDeclInfoTemplate<idDeclMD6> idDeclMD6::resourceList(
    "md6Def", "idDeclMD6", "md6def");

const char* const idDeclMD6::meshKitGroupNames[3] = {
    "Heads", "Gear", "Gore"
};

idDeclMD6::idDeclMD6()
    : config(new idMD6Blend::configInfo_t{}), model(nullptr),
      parentDecl(nullptr), numLoadErrors(0), curAliasHandle(0),
      morphVertices(nullptr), calcRefBoundsFromJoints(false),
      attachmentOverrideScale(-1.0f), modelCaps(0),
      userChannelWeightGroupOverride(0) {
    referenceBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    referenceBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    for (idStr& meshKit : meshKitDefault) meshKit = "";
}

idDeclMD6::~idDeclMD6() {
    FreeData();
    delete config;
    config = nullptr;
}

unsigned int idDeclMD6::GetDeclTimestamp() const {
    return idDecl::GetDeclTimestamp();
}

idDeclInfo* idDeclMD6::GetDeclInfo() const {
    return &resourceList;
}

bool idDeclMD6::RebuildTextSource() {
    idFile_String file;
    Write(&file, "");
    SetText(file.GetDataPtr(), static_cast<int>(file.Length()));
    return true;
}

const char* idDeclMD6::DefaultDefinition() const {
    return "{\n"
        "\tinit {\n"
        "\tmesh \"md6/default.md6mesh\"\n"
        "\t}\n"
        "\tuserProps {\n\t}\n"
        "\tjointGroups {\n\t}\n"
        "\tevents {\n\t}\n"
        "\taliases {\n\t}\n"
        "\tprops {\n\tprop \"_info\" {\n\t\t}\n\t}\n"
        "\teyeInfoCollection 0 {\n\t}\n"
        "}\n";
}

void idDeclMD6::LogMissingDecl() const {
}

namespace {

bool MD6TokenIs(const idToken& token, const char* text) {
    return idStr::Cmp(token.c_str(), text) == 0;
}

bool ReadMD6String(idParser& parser, idStr& value) {
    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) return false;
    value = token.c_str();
    return true;
}

void ParseUserProperty(idParser& parser, idVarArgs<6>& property,
        int& loadErrors) {
    idToken token;
    if (!parser.ExpectTokenType(TT_STRING, 0, token)) {
        ++loadErrors;
        return;
    }
    property.AddArg(token.c_str());
    if (!parser.ExpectTokenString("{")) {
        ++loadErrors;
        return;
    }

    while (parser.ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        if (MD6TokenIs(token, "bool")) {
            property.AddArg(parser.ParseBool());
        } else if (MD6TokenIs(token, "int")) {
            property.AddArg(parser.ParseInt());
        } else if (MD6TokenIs(token, "float")) {
            property.AddArg(parser.ParseFloat());
        } else if (MD6TokenIs(token, "vec3")) {
            idVec3 value(0.0f, 0.0f, 0.0f);
            if (parser.Parse1DMatrix(3, &value.x)) property.AddArg(value);
            else ++loadErrors;
        } else if (MD6TokenIs(token, "quat")) {
            idQuat value(0.0f, 0.0f, 0.0f, 1.0f);
            if (parser.Parse1DMatrix(4, &value.x)) property.AddArg(value);
            else ++loadErrors;
        } else if (MD6TokenIs(token, "vec4")) {
            idVec4 value(0.0f, 0.0f, 0.0f, 0.0f);
            if (parser.Parse1DMatrix(4, &value.x)) property.AddArg(value);
            else ++loadErrors;
        } else if (MD6TokenIs(token, "angles")) {
            idAngles value;
            if (parser.Parse1DMatrix(3, &value.pitch)) property.AddArg(value);
            else ++loadErrors;
        } else if (MD6TokenIs(token, "string")) {
            if (parser.ExpectTokenType(TT_STRING, 0, token))
                property.AddArg(token.c_str());
            else
                ++loadErrors;
        } else {
            parser.Error("Unknown user property type '%s'", token.c_str());
            ++loadErrors;
            if (parser.PeekTokenString("{")) parser.SkipBracedSection(true);
            else parser.SkipRestOfLine();
        }
    }
}

int WeightGroupForName(const char* name) {
    static const char* const names[MD6_WEIGHTGROUP_MAX] = {
        "MD6_WEIGHTGROUP_ALL", "MD6_WEIGHTGROUP_LEGS",
        "MD6_WEIGHTGROUP_TORSO", "MD6_WEIGHTGROUP_HEAD",
        "MD6_WEIGHTGROUP_FACE", "MD6_WEIGHTGROUP_MOUTH",
        "MD6_WEIGHTGROUP_EYELIDS", "MD6_WEIGHTGROUP_USER0"
    };
    for (int index = 0; index < MD6_WEIGHTGROUP_MAX; ++index) {
        if (idStr::Icmp(name, names[index]) == 0) return index;
    }
    return -1;
}

int MeshIndexForName(const idMD6Model* model, const char* name) {
    if (model == nullptr || name == nullptr) return -1;
    for (int index = 0; index < model->meshes.Num(); ++index) {
        if (model->meshes[index] != nullptr &&
                idStr::Icmp(model->meshes[index]->name.c_str(), name) == 0)
            return index;
    }
    return -1;
}

void AppendMeshKitMeshes(const idMD6Model* model, const char* text,
        idList<int, 19>& meshes, idParser& parser, const char* groupName,
        const char* kitName, int& loadErrors) {
    const char* cursor = text != nullptr ? text : "";
    while (*cursor != '\0') {
        while (std::isspace(static_cast<unsigned char>(*cursor)) != 0)
            ++cursor;
        const char* start = cursor;
        while (*cursor != '\0' &&
                std::isspace(static_cast<unsigned char>(*cursor)) == 0)
            ++cursor;
        if (cursor == start) break;
        idStr meshName;
        for (const char* value = start; value < cursor; ++value)
            meshName.Append(*value);
        const int meshIndex = MeshIndexForName(model, meshName.c_str());
        if (meshIndex >= 0) {
            meshes.AddUnique(meshIndex);
        } else {
            parser.Warning(
                "MeshKit Group(%s) Kit(%s) specifies an unknown mesh %s",
                groupName, kitName, meshName.c_str());
            ++loadErrors;
        }
    }
}

void ParseMeshKits(idDeclMD6& declaration, idParser& parser) {
    idToken token;
    if (!parser.ExpectTokenString("{")) {
        ++declaration.numLoadErrors;
        return;
    }
    while (parser.ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        int groupIndex = -1;
        for (int index = 0; index < 3; ++index) {
            if (idStr::Icmp(token.c_str(),
                    idDeclMD6::meshKitGroupNames[index]) == 0) {
                groupIndex = index;
                break;
            }
        }
        if (groupIndex < 0) {
            parser.Error("Unknown mesh kit group '%s'", token.c_str());
            ++declaration.numLoadErrors;
            if (parser.PeekTokenString("{")) parser.SkipBracedSection(true);
            continue;
        }

        idList<idPair<idStr, idList<int, 19>>, 19>& kits =
            declaration.meshKitGroups[groupIndex];
        kits.Clear();
        if (parser.CheckTokenType(TT_NUMBER, 0, token)) {
            const int count = std::atoi(token.c_str());
            if (count > kits.NumAllocated()) kits.Resize(count);
        }
        if (!parser.ExpectTokenString("{")) {
            ++declaration.numLoadErrors;
            return;
        }

        while (parser.ReadToken(token)) {
            if (MD6TokenIs(token, "}")) break;
            if (!MD6TokenIs(token, "meshKit")) {
                parser.Error("Unknown token '%s' in mesh kit group '%s'",
                    token.c_str(),
                    idDeclMD6::meshKitGroupNames[groupIndex]);
                ++declaration.numLoadErrors;
                if (parser.PeekTokenString("{"))
                    parser.SkipBracedSection(true);
                continue;
            }

            idToken kitName;
            if (!parser.ExpectTokenType(TT_STRING, 0, kitName) ||
                    !parser.ExpectTokenString("{")) {
                ++declaration.numLoadErrors;
                return;
            }
            idPair<idStr, idList<int, 19>> kit;
            kit.first = kitName.c_str();
            bool isDefault = false;
            while (parser.ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (MD6TokenIs(token, "meshes")) {
                    idToken meshNames;
                    if (parser.ExpectTokenType(TT_STRING, 0, meshNames)) {
                        AppendMeshKitMeshes(declaration.model,
                            meshNames.c_str(), kit.second, parser,
                            idDeclMD6::meshKitGroupNames[groupIndex],
                            kit.first.c_str(), declaration.numLoadErrors);
                    } else {
                        ++declaration.numLoadErrors;
                    }
                } else if (MD6TokenIs(token, "isDefault")) {
                    isDefault = parser.ParseBool();
                } else {
                    parser.Error("Unknown token '%s' in mesh kit '%s'",
                        token.c_str(), kit.first.c_str());
                    ++declaration.numLoadErrors;
                }
            }
            if (isDefault)
                declaration.meshKitDefault[groupIndex] = kit.first;
            kits.Append(kit);
        }
        kits.Resize(kits.Num());
    }
}

void ParseWrinkleExpressions(idDeclMD6& declaration, idParser& parser) {
    idToken token;
    if (!parser.ExpectTokenString("{")) {
        ++declaration.numLoadErrors;
        return;
    }
    while (parser.ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        if (!MD6TokenIs(token, "regions")) {
            parser.Error("Unknown wrinkle-expression token '%s'",
                token.c_str());
            ++declaration.numLoadErrors;
            continue;
        }
        declaration.wrinkleMapRegionExpressions.Clear();
        if (parser.CheckTokenType(TT_NUMBER, 0, token)) {
            const int count = std::atoi(token.c_str());
            if (count > declaration.wrinkleMapRegionExpressions.NumAllocated())
                declaration.wrinkleMapRegionExpressions.Resize(count);
        }
        if (!parser.ExpectTokenString("{")) {
            ++declaration.numLoadErrors;
            return;
        }
        while (parser.ReadToken(token)) {
            if (MD6TokenIs(token, "}")) break;
            const int index = std::atoi(token.c_str());
            idToken expression;
            if (!parser.ExpectTokenType(TT_STRING, 0, expression) ||
                    index < 0) {
                ++declaration.numLoadErrors;
                continue;
            }
            if (declaration.wrinkleMapRegionExpressions.Num() <= index)
                declaration.wrinkleMapRegionExpressions.SetNum(index + 1);
            declaration.wrinkleMapRegionExpressions[index] =
                expression.c_str();
        }
    }
}

void ParseMorphVertices(idDeclMD6& declaration, idParser& parser) {
    declaration.morphDefList.Clear();
    idToken token;
    if (!parser.ExpectTokenString("{")) {
        ++declaration.numLoadErrors;
        return;
    }
    while (parser.ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        if (MD6TokenIs(token, "morphFile")) {
            idToken fileName;
            if (!parser.ExpectTokenType(TT_STRING, 0, fileName)) {
                ++declaration.numLoadErrors;
                continue;
            }
            idMorphDef definition;
            definition.fileName = fileName.c_str();
            declaration.morphDefList.Append(definition);
        } else if (MD6TokenIs(token, "morphVert")) {
            if (!parser.ExpectTokenString("{")) {
                ++declaration.numLoadErrors;
                continue;
            }
            idMorphDef definition;
            while (parser.ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (MD6TokenIs(token, "sphere") ||
                        MD6TokenIs(token, "ellipsoid")) {
                    definition.flags = idMorphDef::MORPHDEF_ELLIPSOID;
                } else if (MD6TokenIs(token, "box")) {
                    definition.flags = idMorphDef::MORPHDEF_BOX;
                } else if (MD6TokenIs(token, "jointname")) {
                    idToken jointName;
                    if (parser.ExpectTokenType(TT_STRING, 0, jointName))
                        definition.jointName = jointName.c_str();
                    else
                        ++declaration.numLoadErrors;
                } else if (MD6TokenIs(token, "pos")) {
                    if (!parser.Parse1DMatrix(3, &definition.pos.x))
                        ++declaration.numLoadErrors;
                } else if (MD6TokenIs(token, "size")) {
                    if (!parser.Parse1DMatrix(3, &definition.size.x))
                        ++declaration.numLoadErrors;
                } else {
                    parser.Error("Unknown morphVert token '%s'",
                        token.c_str());
                    ++declaration.numLoadErrors;
                }
            }
            declaration.morphDefList.Append(definition);
        } else {
            parser.Error("Read bad morph data for %s", declaration.GetName());
            ++declaration.numLoadErrors;
            if (parser.PeekTokenString("{")) parser.SkipBracedSection(true);
        }
    }
}

} // namespace

void idDeclMD6::Parse(idParser* parser) {
    if (parser == nullptr) return;
    FreeData();
    config->visualOffset[0] = 0.0f;
    config->visualOffset[1] = 0.0f;
    config->visualOffset[2] = 0.0f;
    config->visualOffset[3] = 0.0f;

    idToken token;
    if (!parser->ReadToken(token)) return;
    if (MD6TokenIs(token, "{")) {
        if (!parser->ReadToken(token)) return;
    }
    if (!MD6TokenIs(token, "init")) {
        parser->Error("Expected 'init' in md6Def '%s'", GetName());
        ++numLoadErrors;
        return;
    }
    if (!parser->ExpectTokenString("{")) {
        ++numLoadErrors;
        return;
    }

    const idMD6Model* localModel = nullptr;
    const idDeclMD6* localParent = nullptr;
    idVec3 localOffset(0.0f, 0.0f, 0.0f);
    bool hasLocalOffset = false;
    bool localCalcBounds = false;
    bool hasLocalCalcBounds = false;
    idList<idStr, 5> includeNames;

    while (parser->ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        if (idStr::Icmp(token.c_str(), "inherit") == 0) {
            idStr name;
            if (!ReadMD6String(*parser, name)) {
                ++numLoadErrors;
                continue;
            }
            parent = name;
            localParent = name.IsEmpty() ? nullptr
                : static_cast<const idDeclMD6*>(
                    resourceList.FindWithInheritance(name.c_str(), false));
            if (localParent == nullptr && !name.IsEmpty()) {
                parser->Error("Parent md6Def '%s' does not exist for '%s'",
                    name.c_str(), GetName());
                ++numLoadErrors;
            }
        } else if (idStr::Icmp(token.c_str(), "mesh") == 0) {
            idStr modelName;
            if (!ReadMD6String(*parser, modelName)) {
                ++numLoadErrors;
                continue;
            }
            localModel = static_cast<const idMD6Model*>(
                idMD6Model::resourceList.Load(modelName.c_str(), true,
                    false));
            if (localModel == nullptr) {
                parser->Error("Failed to load model '%s' for md6def '%s'",
                    modelName.c_str(), GetName());
                ++numLoadErrors;
            }
        } else if (idStr::Icmp(token.c_str(), "offset") == 0) {
            hasLocalOffset = parser->Parse1DMatrix(3, &localOffset.x);
            if (!hasLocalOffset) ++numLoadErrors;
        } else if (idStr::Icmp(token.c_str(),
                "calcRefBoundsFromJoints") == 0) {
            localCalcBounds = parser->ParseBool();
            hasLocalCalcBounds = true;
        } else if (idStr::Icmp(token.c_str(),
                "includeAnimDataFrom") == 0) {
            idStr includeName;
            if (ReadMD6String(*parser, includeName))
                includeNames.Append(includeName);
            else
                ++numLoadErrors;
        } else {
            parser->Error("Unknown token '%s' in 'init' block in md6Def '%s'",
                token.c_str(), GetName());
            ++numLoadErrors;
        }
    }

    parentDecl = localParent;
    if (parentDecl != nullptr) {
        model = parentDecl->model;
        for (int component = 0; component < 4; ++component)
            config->visualOffset[component] =
                parentDecl->config->visualOffset[component];
        calcRefBoundsFromJoints = parentDecl->calcRefBoundsFromJoints;
        modelCaps = parentDecl->modelCaps;
        attachmentOverrideScale = parentDecl->attachmentOverrideScale;
        userChannelWeightGroupOverride = -1;
        morphDefList = parentDecl->morphDefList;
        for (int group = 0; group < 3; ++group) {
            meshKitDefault[group] = parentDecl->meshKitDefault[group];
            if (localModel == nullptr || localModel == parentDecl->model)
                meshKitGroups[group] = parentDecl->meshKitGroups[group];
        }
    }
    if (localModel != nullptr) model = localModel;
    if (hasLocalOffset) {
        config->visualOffset[0] = localOffset.x;
        config->visualOffset[1] = localOffset.y;
        config->visualOffset[2] = localOffset.z;
    }
    if (hasLocalCalcBounds) calcRefBoundsFromJoints = localCalcBounds;

    for (int includeIndex = 0; includeIndex < includeNames.Num();
            ++includeIndex) {
        const idDeclMD6* included = static_cast<const idDeclMD6*>(
            resourceList.FindWithInheritance(
                includeNames[includeIndex].c_str(), false));
        if (included == nullptr) {
            parser->Error(
                "md6Def '%s' does not exist for including animations for '%s'",
                includeNames[includeIndex].c_str(), GetName());
            ++numLoadErrors;
        } else {
            IncludeAnimDataFrom(included);
        }
    }

    if (model == nullptr) {
        parser->Error("No md6model specified for md6Def '%s'", GetName());
        ++numLoadErrors;
    } else {
        referenceBounds = model->defaultBounds;
    }

    bool wrinkleExpressionsParsed = false;
    while (parser->ReadToken(token)) {
        if (MD6TokenIs(token, "}")) break;
        if (MD6TokenIs(token, "modelCaps")) {
            if (!parser->ExpectTokenString("{")) {
                ++numLoadErrors;
                continue;
            }
            while (parser->ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (MD6TokenIs(token, "lipsync")) modelCaps |= MODELCAP_LIPSYNC;
                else if (MD6TokenIs(token, "faceSetup")) modelCaps |= MODELCAP_FACESETUP;
                else if (MD6TokenIs(token, "moods")) modelCaps |= MODELCAP_MOODS;
                else if (MD6TokenIs(token, "gestures")) modelCaps |= MODELCAP_GESTURES;
                else {
                    parser->Error("Unknown model capability '%s' in md6Def '%s'",
                        token.c_str(), GetName());
                    ++numLoadErrors;
                }
            }
        } else if (MD6TokenIs(token, "attachmentOverrideScale")) {
            attachmentOverrideScale = parser->ParseFloat();
        } else if (MD6TokenIs(token, "userProps")) {
            if (!parser->ExpectTokenString("{")) {
                ++numLoadErrors;
                continue;
            }
            while (parser->ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (!MD6TokenIs(token, "prop")) {
                    parser->Error("Unknown token '%s' in userProps block in md6Def '%s'",
                        token.c_str(), GetName());
                    ++numLoadErrors;
                    continue;
                }
                idVarArgs<6> property;
                ParseUserProperty(*parser, property, numLoadErrors);
                userProps.Append(property);
            }
        } else if (MD6TokenIs(token, "jointGroups")) {
            numLoadErrors += jointGroupCollection.Parse(*parser, this);
        } else if (MD6TokenIs(token, "events")) {
            animEvents.Parse(this, *parser, numLoadErrors);
        } else if (MD6TokenIs(token, "aliases")) {
            if (!parser->ExpectTokenString("{")) {
                ++numLoadErrors;
                continue;
            }
            while (parser->ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (!MD6TokenIs(token, "alias")) {
                    parser->Error("Unknown token '%s', expected 'alias'",
                        token.c_str());
                    ++numLoadErrors;
                    continue;
                }
                idMD6Alias alias;
                alias.Parse(this, *parser, numLoadErrors);
                if (FindAlias(alias.name.c_str(), false) == nullptr)
                    AddAlias(alias, false);
                else {
                    parser->Warning("Alias '%s' is defined more than once in decl '%s'",
                        alias.name.c_str(), GetName());
                    ++numLoadErrors;
                }
            }
        } else if (MD6TokenIs(token, "props")) {
            numLoadErrors += props.Parse(*parser, this);
        } else if (MD6TokenIs(token, "eyeInfoCollection")) {
            eyeInfoCollection.Parse(this, *parser, numLoadErrors);
        } else if (MD6TokenIs(token, "morphVerts")) {
            ParseMorphVertices(*this, *parser);
        } else if (MD6TokenIs(token, "morphSkin")) {
            if (!parser->ExpectTokenString("{")) {
                ++numLoadErrors;
                continue;
            }
            while (parser->ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                if (MD6TokenIs(token, "projectionModel") ||
                        MD6TokenIs(token, "outputPath")) {
                    if (!parser->ReadToken(token)) ++numLoadErrors;
                } else {
                    parser->Warning("Unknown morphSkin token '%s'",
                        token.c_str());
                    ++numLoadErrors;
                }
            }
        } else if (MD6TokenIs(token, "meshKits")) {
            ParseMeshKits(*this, *parser);
        } else if (MD6TokenIs(token, "wrinkleExpressions")) {
            wrinkleExpressionsParsed = true;
            ParseWrinkleExpressions(*this, *parser);
        } else if (MD6TokenIs(token,
                "userChannelToAnimationAliasOverrides")) {
            if (!parser->ExpectTokenString("{")) {
                ++numLoadErrors;
                continue;
            }
            while (parser->ReadToken(token)) {
                if (MD6TokenIs(token, "}")) break;
                idStr channelName(token.c_str());
                idToken aliasName;
                if (!parser->ExpectTokenString(":") ||
                        !parser->ExpectTokenType(TT_STRING, 0, aliasName)) {
                    ++numLoadErrors;
                    continue;
                }
                const md6UserChannelIndex_t channel = model != nullptr &&
                        model->skeleton != nullptr
                    ? model->skeleton->GetUserChannelIndex(channelName.c_str())
                    : md6UserChannelIndex_t();
                const aliasHandle_t alias = FindAliasHandle(aliasName.c_str());
                if (channel.IsValid() && alias.IsValid()) {
                    userChannelToAnimationAliasOverrides.Append(
                        idPair<idIndex<short, invalidUserChannelIndex_t>,
                            aliasHandle_t>(channel, alias));
                } else {
                    parser->Warning(
                        "Invalid user channel '%s' or animation alias '%s'",
                        channelName.c_str(), aliasName.c_str());
                    ++numLoadErrors;
                }
            }
        } else if (MD6TokenIs(token, "baseUserChannel")) {
            if (!parser->ExpectTokenString("{") ||
                    !parser->ExpectTokenType(TT_STRING, 0, token)) {
                ++numLoadErrors;
                continue;
            }
            baseUserChannelAlias = FindAliasHandle(token.c_str());
            if (!baseUserChannelAlias.IsValid()) ++numLoadErrors;
            if (!parser->ExpectTokenString("}")) ++numLoadErrors;
        } else if (MD6TokenIs(token,
                "userChannelWeightGroupOverride")) {
            if (!parser->ExpectTokenString("{") ||
                    !parser->ExpectTokenType(TT_STRING, 0, token)) {
                ++numLoadErrors;
                continue;
            }
            const int group = WeightGroupForName(token.c_str());
            if (group < 0) {
                parser->Warning("Unknown MD6 weight group '%s'",
                    token.c_str());
                ++numLoadErrors;
            } else if (parentDecl == nullptr ||
                    group != parentDecl->GetUserChannelWeightGroup()) {
                userChannelWeightGroupOverride = group;
            }
            if (!parser->ExpectTokenString("}")) ++numLoadErrors;
        } else if (MD6TokenIs(token, "{")) {
            parser->SkipBracedSection(false);
        } else {
            parser->Error("Unknown token '%s' in md6Def '%s'",
                token.c_str(), GetName());
            ++numLoadErrors;
            if (parser->PeekTokenString("{")) parser->SkipBracedSection(true);
        }
    }

    if (parentDecl != nullptr) {
        for (int index = 0; index < parentDecl->userProps.Num(); ++index) {
            const idVarArgs<6>& inherited = parentDecl->userProps[index];
            const char* propertyName = nullptr;
            if (inherited.GetArg(0, propertyName) &&
                    FindUserProp(propertyName) == nullptr)
                userProps.Append(inherited);
        }
        jointGroupCollection.DuplicateInherited(this, parentDecl,
            &parentDecl->jointGroupCollection);
        props.DuplicateInherited(&parentDecl->props);
        eyeInfoCollection.DuplicateInherited(this,
            &parentDecl->eyeInfoCollection);
        if (!wrinkleExpressionsParsed)
            wrinkleMapRegionExpressions =
                parentDecl->wrinkleMapRegionExpressions;
    }
    jointGroupCollection.Condense();
    InitUserChannelToAnimationAliasMap();
    InitHeadTrackGroups();
    if (!animEvents.CacheTransforms(this)) ++numLoadErrors;

    if (morphDefList.Num() > 0) {
        morphVertices = static_cast<idMorphVertices*>(
            idMorphVertices::resourceList.Load(GetName(), true, false));
        if (morphVertices == nullptr) ++numLoadErrors;
    }
}

aliasHandle_t idDeclMD6::StrongLoadAlias(const char* aliasName) const {
    return animation != nullptr
        ? animation->StrongLoadAlias(this, aliasName)
        : FindAliasHandle(aliasName);
}

aliasHandle_t idDeclMD6::FindAliasHandle(const char* aliasName) const {
    if (aliasName == nullptr || *aliasName == '\0') return aliasHandle_t();
    if (animation != nullptr) {
        const aliasHandle_t handle =
            animation->FindAliasHandle(this, aliasName);
        if (handle.IsValid()) return handle;
    }
    const idMD6Alias* alias = FindAlias(aliasName, true);
    return alias != nullptr ? alias->aliasHandle : aliasHandle_t();
}

const idMD6Alias* idDeclMD6::FindAlias(const aliasHandle_t aliasHandle,
        const bool includeInherited) const {
    if (!aliasHandle.IsValid()) return nullptr;
    for (int index = 0; index < aliases.Num(); ++index) {
        if (aliases[index].aliasHandle == aliasHandle) return &aliases[index];
    }
    if (!includeInherited) return nullptr;
    if (parentDecl != nullptr) {
        const idMD6Alias* inherited =
            parentDecl->FindAlias(aliasHandle, true);
        if (inherited != nullptr) return inherited;
    }
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index) {
        const idDeclMD6* included =
            declsToIncludeAnimDataFrom[index].includeDecl;
        if (included == nullptr) continue;
        const idMD6Alias* alias = included->FindAlias(aliasHandle, false);
        if (alias != nullptr) return alias;
    }
    return nullptr;
}

const idMD6Alias* idDeclMD6::FindAlias(const char* aliasName,
        const bool includeInherited) const {
    if (aliasName == nullptr) return nullptr;
    for (int index = 0; index < aliases.Num(); ++index) {
        if (idStr::Icmp(aliases[index].name.c_str(), aliasName) == 0)
            return &aliases[index];
    }
    if (!includeInherited) return nullptr;
    if (parentDecl != nullptr) {
        const idMD6Alias* inherited = parentDecl->FindAlias(aliasName, true);
        if (inherited != nullptr) return inherited;
    }
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index) {
        const idDeclMD6* included =
            declsToIncludeAnimDataFrom[index].includeDecl;
        if (included == nullptr) continue;
        const idMD6Alias* alias = included->FindAlias(aliasName, false);
        if (alias != nullptr) return alias;
    }
    return nullptr;
}

const idMD6Anim* idDeclMD6::AnimForAlias(const aliasHandle_t aliasHandle,
        const bool load) const {
    if (!aliasHandle.IsValid()) return nullptr;
    const idMD6Alias* alias = FindAlias(aliasHandle, true);
    if (alias != nullptr && alias->animRefs.Num() > 0) {
        idResource* resource = idMD6Anim::resourceList.FindExisting(
            alias->animRefs[0].c_str(), true);
        if (resource == nullptr && load) {
            resource = idMD6Anim::resourceList.Load(
                alias->animRefs[0].c_str(), true, true);
        }
        return static_cast<const idMD6Anim*>(resource);
    }
    if (!load || animation == nullptr) return nullptr;
    const char* aliasName = animation->FindAliasName(aliasHandle);
    return aliasName != nullptr
        ? static_cast<const idMD6Anim*>(idMD6Anim::resourceList.Load(
            aliasName, true, true))
        : nullptr;
}

bool idDeclMD6::GetJointsForAnimTime(idJointMat* joints,
        const idMD6Anim* animationResource, const int timeMS,
        const idVec3& offset, const bool removeOriginOffset) const {
    return model != nullptr && model->GetJointsForAnimTime(joints,
        animationResource, timeMS, offset, removeOriginOffset);
}

idIndex<short, invalidJointIndex_t> idDeclMD6::GetJointIndex(
        const char* jointName) const {
    return model != nullptr && model->skeleton != nullptr
        ? model->skeleton->GetJointIndex(jointName)
        : idIndex<short, invalidJointIndex_t>();
}

idIndex<short, invalidJointIndex_t> idDeclMD6::GetJointIndex(
        const jointHandle_t handle) const {
    return model != nullptr && model->skeleton != nullptr
        ? model->skeleton->GetJointIndex(handle)
        : idIndex<short, invalidJointIndex_t>();
}

const char* idDeclMD6::GetJointName(
        const idIndex<short, invalidJointIndex_t> joint) const {
    return model != nullptr && model->skeleton != nullptr && joint.IsValid()
        ? model->skeleton->GetJointName(joint.Get()) : nullptr;
}

void idDeclMD6::GetJointList(const char* joints,
        idList<idIndex<short, invalidJointIndex_t>, 5>& jointList) const {
    if (model != nullptr && model->skeleton != nullptr)
        model->skeleton->GetJointList(model, joints, jointList);
}

const idVarArgs<6>* idDeclMD6::FindUserProp(const char* propName) const {
    if (propName == nullptr) return nullptr;
    for (int index = 0; index < userProps.Num(); ++index) {
        const char* name = nullptr;
        if (userProps[index].GetArg(0, name) && name != nullptr &&
                idStr::Icmp(name, propName) == 0)
            return &userProps[index];
    }
    return nullptr;
}

int idDeclMD6::GetHeadTrackGroupIndex(const char* groupName) const {
    if (groupName == nullptr) return -1;
    for (int index = 0; index < headTrackGroups.Num(); ++index) {
        if (idStr::Icmp(headTrackGroups[index].name.c_str(), groupName) == 0)
            return index;
    }
    return -1;
}

bool idDeclMD6::IsChildOf(const idDeclMD6* declaration) const {
    if (declaration == nullptr) return false;
    for (const idDeclMD6* current = parentDecl; current != nullptr;
            current = current->parentDecl) {
        if (current == declaration) return true;
    }
    for (int includeIndex = 0;
            includeIndex < declsToIncludeAnimDataFrom.Num(); ++includeIndex) {
        for (const idDeclMD6* current =
                 declsToIncludeAnimDataFrom[includeIndex].includeDecl;
             current != nullptr; current = current->parentDecl) {
            if (current == declaration) return true;
        }
    }
    return false;
}

md6WeightGroup_t idDeclMD6::GetUserChannelWeightGroup() const {
    for (const idDeclMD6* current = this; current != nullptr;
            current = current->parentDecl) {
        if (current->userChannelWeightGroupOverride >= 0 &&
                current->userChannelWeightGroupOverride <
                    MD6_WEIGHTGROUP_MAX) {
            return static_cast<md6WeightGroup_t>(
                current->userChannelWeightGroupOverride);
        }
    }
    return MD6_WEIGHTGROUP_ALL;
}

void idDeclMD6::GetAliases(idList<const idMD6Alias*, 5>& output,
        const bool includeInherited) const {
    for (int index = 0; index < aliases.Num(); ++index) {
        bool found = false;
        for (int existing = 0; existing < output.Num(); ++existing) {
            if (idStr::Icmp(output[existing]->name.c_str(),
                    aliases[index].name.c_str()) == 0) {
                found = true;
                break;
            }
        }
        if (!found) output.Append(&aliases[index]);
    }
    if (!includeInherited) return;
    if (parentDecl != nullptr) parentDecl->GetAliases(output, true);
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index) {
        const idDeclMD6* included =
            declsToIncludeAnimDataFrom[index].includeDecl;
        if (included != nullptr) included->GetAliases(output, false);
    }
}

bool idDeclMD6::GetCachedJoints(const int eventNumber,
        const idMD6Anim* animationResource,
        idStaticList<const idCachedJoint*, 8>& joints) const {
    joints.Clear();
    if (animationResource == nullptr) return false;
    const idAtomicStringT<md6AnimAtomicString_t> animationReference(
        animationResource->GetName());

    const auto mergeFrom = [&](const idDeclMD6* declaration) {
        if (declaration == nullptr) return;
        const idAnimEvents::animEventInfo_t* info =
            declaration->animEvents.FindAnimEventInfo(animationReference);
        if (info == nullptr) return;
        idStaticList<const idCachedJoint*, 8> incoming;
        info->GetCachedJoints(eventNumber, incoming);
        for (int source = 0; source < incoming.Num(); ++source) {
            bool found = false;
            for (int destination = 0; destination < joints.Num();
                    ++destination) {
                if (joints[destination]->jointIndex ==
                        incoming[source]->jointIndex) {
                    found = true;
                    break;
                }
            }
            if (!found && joints.Num() < joints.Max())
                joints.Append(incoming[source]);
        }
    };

    mergeFrom(this);
    for (const idDeclMD6* current = parentDecl; current != nullptr;
            current = current->parentDecl)
        mergeFrom(current);
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index)
        mergeFrom(declsToIncludeAnimDataFrom[index].includeDecl);
    return joints.Num() != 0;
}

aliasHandle_t idDeclMD6::AddAlias(const idMD6Alias& input,
        const bool overload) {
    if (!overload) {
        if (parentDecl != nullptr) {
            const idMD6Alias* inherited =
                parentDecl->FindAlias(input.name.c_str(), true);
            if (inherited != nullptr && input.IsInherited(*inherited))
                return inherited->aliasHandle;
        }
        for (int index = 0; index < declsToIncludeAnimDataFrom.Num();
                ++index) {
            const idDeclMD6* included =
                declsToIncludeAnimDataFrom[index].includeDecl;
            const idMD6Alias* inherited = included != nullptr
                ? included->FindAlias(input.name.c_str(), true) : nullptr;
            if (inherited != nullptr && input.IsInherited(*inherited))
                return inherited->aliasHandle;
        }
    }

    aliasHandle_t handle = animation != nullptr
        ? animation->RegisterAlias(this, input.name.c_str())
        : aliasHandle_t(curAliasHandle++);
    if (!handle.IsValid()) return handle;
    const int index = aliases.Append(input);
    if (index < 0) return aliasHandle_t();
    aliases[index].aliasHandle = handle;
    aliasHash.Add(handle.Get(), index);
    return handle;
}

bool idDeclMD6::HasIncludedDecl(const idDeclMD6* declaration) const {
    if (declaration == nullptr) return false;
    if (declaration == this || declaration == parentDecl) return true;
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index) {
        if (declsToIncludeAnimDataFrom[index].includeDecl == declaration)
            return true;
    }
    return false;
}

void idDeclMD6::IncludeAnimDataFrom(const idDeclMD6* declaration) {
    if (declaration == nullptr || HasIncludedDecl(declaration)) return;
    includeDecl_t direct{declaration, true};
    declsToIncludeAnimDataFrom.Append(direct);
    if (declaration->parentDecl != nullptr &&
            !HasIncludedDecl(declaration->parentDecl)) {
        includeDecl_t inherited{declaration->parentDecl, false};
        declsToIncludeAnimDataFrom.Append(inherited);
    }
    for (int index = 0;
            index < declaration->declsToIncludeAnimDataFrom.Num(); ++index) {
        const idDeclMD6* transitive =
            declaration->declsToIncludeAnimDataFrom[index].includeDecl;
        if (transitive != nullptr && !HasIncludedDecl(transitive)) {
            includeDecl_t inherited{transitive, false};
            declsToIncludeAnimDataFrom.Append(inherited);
        }
    }
}

void idDeclMD6::InitUserChannelToAnimationAliasMap() {
    userChannelToAnimationAliasMap.Clear();
    if (model == nullptr || model->skeleton == nullptr ||
            model->skeleton->data == nullptr) return;
    const int count = model->skeleton->data->numUserChannels;
    for (int channel = 0; channel < count; ++channel) {
        aliasHandle_t alias;
        for (int index = 0;
                index < userChannelToAnimationAliasOverrides.Num(); ++index) {
            if (userChannelToAnimationAliasOverrides[index].first.Get() ==
                    channel) {
                alias = userChannelToAnimationAliasOverrides[index].second;
                break;
            }
        }
        if (!alias.IsValid() && parentDecl != nullptr &&
                channel < parentDecl->userChannelToAnimationAliasMap.Num()) {
            alias = parentDecl->userChannelToAnimationAliasMap[channel];
        }
        userChannelToAnimationAliasMap.Append(alias);
    }
}

void idDeclMD6::InitHeadTrackGroups() {
    headTrackGroups.Clear();
    if (model == nullptr || model->skeleton == nullptr) return;
    const idMD6Skel* skeleton = model->skeleton;
    const int groupCount = jointGroupCollection.NumJointGroupsForType(
        idJointGroup::JOINTGROUP_HEADTRACKING);

    for (int groupIndex = 0; groupIndex < groupCount; ++groupIndex) {
        const idJointGroup* source = jointGroupCollection.GetJointGroupForIndex(
            idJointGroup::JOINTGROUP_HEADTRACKING, groupIndex);
        if (source == nullptr || source->joints.Num() == 0) continue;

        idStr focusName(source->groupName.c_str());
        focusName.Append("_focus");
        idStr orientationName(source->groupName.c_str());
        orientationName.Append("_orientation");
        const idJointGroup* focus = jointGroupCollection.GetJointGroupForName(
            idJointGroup::JOINTGROUP_FOCUS, focusName.c_str());
        const idJointGroup* orientation =
            jointGroupCollection.GetJointGroupForName(
                idJointGroup::JOINTGROUP_ORIENTATION,
                orientationName.c_str());
        if (focus == nullptr || focus->joints.Num() == 0 ||
                orientation == nullptr || orientation->joints.Num() == 0) {
            ++numLoadErrors;
            continue;
        }

        idList<idHeadTrackJoint, 5> unsorted;
        idList<int, 5> parentCounts;
        float totalWeight = 0.0f;
        for (int jointIndex = 0; jointIndex < source->joints.Num();
                ++jointIndex) {
            idHeadTrackJoint joint;
            joint.jointIdx = source->joints[jointIndex];
            const float weight = jointIndex < source->jointScalars.Num()
                ? source->jointScalars[jointIndex] : 1.0f;
            joint.pitchScale = weight;
            joint.yawScale = weight;
            unsorted.Append(joint);
            totalWeight += weight;

            int parents = 0;
            for (int candidate = 0; candidate < source->joints.Num();
                    ++candidate) {
                if (candidate != jointIndex && skeleton->IsJointChildOf(
                        source->joints[jointIndex],
                        source->joints[candidate]))
                    ++parents;
            }
            parentCounts.Append(parents);
        }

        idHeadTrackGroup group;
        group.name.Set(source->groupName.c_str());
        group.focusJointIdx = focus->joints[0];
        group.orientationJointIdx = orientation->joints[0];
        idStr canonicalName(source->groupName.c_str());
        canonicalName.MakeNameCanonical();
        group.blendTime = std::strstr(canonicalName.c_str(), "look") != nullptr
            ? 500 : 250;

        while (unsorted.Num() > 0) {
            int best = 0;
            for (int candidate = 1; candidate < parentCounts.Num();
                    ++candidate) {
                if (parentCounts[candidate] < parentCounts[best])
                    best = candidate;
            }
            group.trackJoints.Append(unsorted[best]);
            unsorted.RemoveIndexFast(best);
            parentCounts.RemoveIndexFast(best);
        }

        if (totalWeight > 0.0f) {
            const float inverseWeight = 1.0f / totalWeight;
            for (int index = 0; index < group.trackJoints.Num(); ++index) {
                group.trackJoints[index].pitchScale *= inverseWeight;
                group.trackJoints[index].yawScale *= inverseWeight;
            }
        }

        bool hierarchyValid = true;
        for (int index = 1; index < group.trackJoints.Num(); ++index) {
            if (!skeleton->IsJointChildOf(
                    group.trackJoints[index].jointIdx,
                    group.trackJoints[index - 1].jointIdx)) {
                hierarchyValid = false;
                break;
            }
        }
        if (hierarchyValid) headTrackGroups.Append(group);
        else ++numLoadErrors;
    }
}

void idDeclMD6::FreeData() {
    if (animation != nullptr) animation->UnregisterAliases(this);
    model = nullptr;
    parent = "";
    parentDecl = nullptr;
    declsToIncludeAnimDataFrom.ClearFree();
    numLoadErrors = 0;
    jointGroupCollection.Free();
    props.Free();
    animEvents.Free();
    eyeInfoCollection.Free();
    userProps.ClearFree();
    aliases.ClearFree();
    aliasHash.Clear();
    curAliasHandle = 0;
    headTrackGroups.ClearFree();
    for (int index = 0; index < 3; ++index) {
        meshKitGroups[index].ClearFree();
        meshKitDefault[index] = "";
    }
    morphVertices = nullptr;
    morphDefList.ClearFree();
    calcRefBoundsFromJoints = false;
    wrinkleMapRegionExpressions.ClearFree();
    attachmentOverrideScale = -1.0f;
    modelCaps = 0;
    userChannelWeightGroupOverride = 0;
    baseUserChannelAlias.Invalidate();
    userChannelToAnimationAliasMap.ClearFree();
    userChannelToAnimationAliasOverrides.ClearFree();
    if (config != nullptr) {
        config->visualOffset[0] = 0.0f;
        config->visualOffset[1] = 0.0f;
        config->visualOffset[2] = 0.0f;
        config->visualOffset[3] = 0.0f;
    }
    referenceBounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    referenceBounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}

unsigned int idDeclMD6::Size() const {
    unsigned int total = sizeof(*this);
    total += declsToIncludeAnimDataFrom.MemoryUsed();
    total += jointGroupCollection.jointGroups.MemoryUsed();
    total += props.props.MemoryUsed();
    total += animEvents.list.MemoryUsed();
    total += eyeInfoCollection.eyeInfos.MemoryUsed();
    total += userProps.MemoryUsed() + aliases.MemoryUsed();
    total += headTrackGroups.MemoryUsed();
    total += morphDefList.MemoryUsed();
    total += wrinkleMapRegionExpressions.MemoryUsed();
    total += userChannelToAnimationAliasMap.MemoryUsed();
    total += userChannelToAnimationAliasOverrides.MemoryUsed();
    for (const auto& groups : meshKitGroups) total += groups.MemoryUsed();
    return total;
}

void idDeclMD6::Write(idFile_String* file, const char* indent) const {
    if (file == nullptr) return;
    const char* prefix = indent != nullptr ? indent : "";
    idStr childIndent(prefix);
    childIndent.Append("\t");
    const char* child = childIndent.c_str();

    file->Printf("%s{\n", prefix);
    file->Printf("%sinit {\n", child);
    if (!parent.IsEmpty())
        file->Printf("%s\tinherit \"%s\"\n", child, parent.c_str());
    for (int index = 0; index < declsToIncludeAnimDataFrom.Num(); ++index) {
        const includeDecl_t& included = declsToIncludeAnimDataFrom[index];
        if (included.isOriginalInclude && included.includeDecl != nullptr) {
            file->Printf("%s\tincludeAnimDataFrom \"%s\"\n", child,
                included.includeDecl->GetName());
        }
    }
    if (model != nullptr)
        file->Printf("%s\tmesh \"%s\"\n", child, model->GetName());
    file->Printf("%s\toffset ( %.9g %.9g %.9g )\n", child,
        config != nullptr ? config->visualOffset[0] : 0.0f,
        config != nullptr ? config->visualOffset[1] : 0.0f,
        config != nullptr ? config->visualOffset[2] : 0.0f);
    file->Printf("%s\tcalcRefBoundsFromJoints %d\n", child,
        calcRefBoundsFromJoints ? 1 : 0);
    file->Printf("%s}\n", child);

    file->Printf("%smodelCaps {\n", child);
    if ((modelCaps & MODELCAP_LIPSYNC) != 0)
        file->Printf("%s\tlipsync\n", child);
    if ((modelCaps & MODELCAP_FACESETUP) != 0)
        file->Printf("%s\tfaceSetup\n", child);
    if ((modelCaps & MODELCAP_MOODS) != 0)
        file->Printf("%s\tmoods\n", child);
    if ((modelCaps & MODELCAP_GESTURES) != 0)
        file->Printf("%s\tgestures\n", child);
    file->Printf("%s}\n", child);
    if (attachmentOverrideScale >= 0.0f)
        file->Printf("%sattachmentOverrideScale %.9g\n", child,
            attachmentOverrideScale);

    const auto writeArgument = [&](const idVarArgs<6>& arguments,
            const int argumentIndex, const char* argumentIndent) {
        switch (arguments.GetArgType(argumentIndex)) {
        case ARG_BOOL: {
            bool value = false; arguments.GetArg(argumentIndex, value);
            file->Printf("%sbool %d\n", argumentIndent, value ? 1 : 0);
            break;
        }
        case ARG_CHAR: {
            char value = 0; arguments.GetArg(argumentIndex, value);
            file->Printf("%sint %d\n", argumentIndent,
                static_cast<int>(value));
            break;
        }
        case ARG_INTEGER: {
            int value = 0; arguments.GetArg(argumentIndex, value);
            file->Printf("%sint %d\n", argumentIndent, value);
            break;
        }
        case ARG_FLOAT: {
            float value = 0.0f; arguments.GetArg(argumentIndex, value);
            file->Printf("%sfloat %.9g\n", argumentIndent, value);
            break;
        }
        case ARG_VECTOR: {
            idVec3 value; arguments.GetArg(argumentIndex, value);
            file->Printf("%svec3 ( %.9g %.9g %.9g )\n", argumentIndent,
                value.x, value.y, value.z);
            break;
        }
        case ARG_QUAT: {
            idQuat value; arguments.GetArg(argumentIndex, value);
            file->Printf("%squat ( %.9g %.9g %.9g %.9g )\n",
                argumentIndent, value.x, value.y, value.z, value.w);
            break;
        }
        case ARG_ANGLES: {
            idAngles value; arguments.GetArg(argumentIndex, value);
            file->Printf("%sangles ( %.9g %.9g %.9g )\n",
                argumentIndent, value.pitch, value.yaw, value.roll);
            break;
        }
        case ARG_VECTOR4: {
            idVec4 value; arguments.GetArg(argumentIndex, value);
            file->Printf("%svec4 ( %.9g %.9g %.9g %.9g )\n",
                argumentIndent, value.x, value.y, value.z, value.w);
            break;
        }
        case ARG_STRING: {
            const char* value = "";
            arguments.GetArg(argumentIndex, value);
            file->Printf("%sstring \"%s\"\n", argumentIndent,
                value != nullptr ? value : "");
            break;
        }
        default:
            break;
        }
    };

    file->Printf("%suserProps {\n", child);
    idStr propertyIndent(child);
    propertyIndent.Append("\t");
    idStr argumentIndent(propertyIndent);
    argumentIndent.Append("\t");
    for (int propertyIndex = 0; propertyIndex < userProps.Num();
            ++propertyIndex) {
        const idVarArgs<6>& property = userProps[propertyIndex];
        const char* propertyName = "";
        property.GetArg(0, propertyName);
        file->Printf("%sprop \"%s\" {\n", propertyIndent.c_str(),
            propertyName != nullptr ? propertyName : "");
        for (int argument = 1; argument < property.NumArgs(); ++argument)
            writeArgument(property, argument, argumentIndent.c_str());
        file->Printf("%s}\n", propertyIndent.c_str());
    }
    file->Printf("%s}\n", child);

    jointGroupCollection.Write(*file, this, child);
    animEvents.Write(*file, child);
    file->Printf("%saliases {\n", child);
    idStr aliasIndent(child);
    aliasIndent.Append("\t");
    for (int index = 0; index < aliases.Num(); ++index)
        aliases[index].Write(this, *file, aliasIndent.c_str());
    file->Printf("%s}\n", child);
    props.Write(*file, this, child);
    eyeInfoCollection.Write(this, *file, child);

    if (morphDefList.Num() > 0) {
        file->Printf("%smorphVerts {\n", child);
        for (int index = 0; index < morphDefList.Num(); ++index) {
            const idMorphDef& definition = morphDefList[index];
            if (definition.flags == 0) {
                file->Printf("%s\tmorphFile \"%s\"\n", child,
                    definition.fileName.c_str());
                continue;
            }
            file->Printf("%s\tmorphVert {\n", child);
            file->Printf("%s\t\t%s\n", child,
                (definition.flags & idMorphDef::MORPHDEF_ELLIPSOID) != 0
                    ? "sphere" : "box");
            file->Printf("%s\t\tjointname \"%s\"\n", child,
                definition.jointName.c_str());
            file->Printf("%s\t\tpos ( %.9g %.9g %.9g )\n", child,
                definition.pos.x, definition.pos.y, definition.pos.z);
            file->Printf("%s\t\tsize ( %.9g %.9g %.9g )\n", child,
                definition.size.x, definition.size.y, definition.size.z);
            file->Printf("%s\t}\n", child);
        }
        file->Printf("%s}\n", child);
    }

    bool hasMeshKits = false;
    for (int group = 0; group < 3; ++group)
        hasMeshKits = hasMeshKits || meshKitGroups[group].Num() > 0;
    if (hasMeshKits) {
        file->Printf("%smeshKits {\n", child);
        for (int group = 0; group < 3; ++group) {
            if (meshKitGroups[group].Num() == 0) continue;
            file->Printf("%s\t%s %d {\n", child, meshKitGroupNames[group],
                meshKitGroups[group].Num());
            for (int kitIndex = 0;
                    kitIndex < meshKitGroups[group].Num(); ++kitIndex) {
                const idPair<idStr, idList<int, 19>>& kit =
                    meshKitGroups[group][kitIndex];
                file->Printf("%s\t\tmeshKit \"%s\" {\n", child,
                    kit.first.c_str());
                idStr meshNames;
                if (model != nullptr) {
                    for (int meshIndex = 0; meshIndex < kit.second.Num();
                            ++meshIndex) {
                        const int index = kit.second[meshIndex];
                        if (index < 0 || index >= model->meshes.Num() ||
                                model->meshes[index] == nullptr) continue;
                        if (!meshNames.IsEmpty()) meshNames.Append(' ');
                        meshNames.Append(model->meshes[index]->name.c_str());
                    }
                }
                file->Printf("%s\t\t\tmeshes \"%s\"\n", child,
                    meshNames.c_str());
                if (idStr::Icmp(meshKitDefault[group].c_str(),
                        kit.first.c_str()) == 0)
                    file->Printf("%s\t\t\tisDefault true\n", child);
                file->Printf("%s\t\t}\n", child);
            }
            file->Printf("%s\t}\n", child);
        }
        file->Printf("%s}\n", child);
    }

    if (wrinkleMapRegionExpressions.Num() > 0) {
        file->Printf("%swrinkleExpressions {\n", child);
        file->Printf("%s\tregions %d {\n", child,
            wrinkleMapRegionExpressions.Num());
        for (int index = 0;
                index < wrinkleMapRegionExpressions.Num(); ++index) {
            file->Printf("%s\t\t%d \"%s\"\n", child, index,
                wrinkleMapRegionExpressions[index].c_str());
        }
        file->Printf("%s\t}\n", child);
        file->Printf("%s}\n", child);
    }

    if (userChannelToAnimationAliasOverrides.Num() > 0) {
        file->Printf("%suserChannelToAnimationAliasOverrides {\n", child);
        for (int index = 0;
                index < userChannelToAnimationAliasOverrides.Num(); ++index) {
            const auto& overrideInfo =
                userChannelToAnimationAliasOverrides[index];
            const char* channelName = model != nullptr
                ? model->GetUserChannelName(overrideInfo.first) : "";
            const idMD6Alias* alias = FindAlias(overrideInfo.second, true);
            const char* aliasName = alias != nullptr
                ? alias->name.c_str() : "";
            file->Printf("%s\t%s : \"%s\"\n", child,
                channelName != nullptr ? channelName : "", aliasName);
        }
        file->Printf("%s}\n", child);
    }
    if (baseUserChannelAlias.IsValid()) {
        const idMD6Alias* alias = FindAlias(baseUserChannelAlias, true);
        file->Printf("%sbaseUserChannel {\n", child);
        file->Printf("%s\t\"%s\"\n", child,
            alias != nullptr ? alias->name.c_str() : "");
        file->Printf("%s}\n", child);
    }
    if (userChannelWeightGroupOverride >= 0 &&
            userChannelWeightGroupOverride < MD6_WEIGHTGROUP_MAX) {
        static const char* const groupNames[MD6_WEIGHTGROUP_MAX] = {
            "MD6_WEIGHTGROUP_ALL", "MD6_WEIGHTGROUP_LEGS",
            "MD6_WEIGHTGROUP_TORSO", "MD6_WEIGHTGROUP_HEAD",
            "MD6_WEIGHTGROUP_FACE", "MD6_WEIGHTGROUP_MOUTH",
            "MD6_WEIGHTGROUP_EYELIDS", "MD6_WEIGHTGROUP_USER0"
        };
        file->Printf("%suserChannelWeightGroupOverride {\n", child);
        file->Printf("%s\t\"%s\"\n", child,
            groupNames[userChannelWeightGroupOverride]);
        file->Printf("%s}\n", child);
    }
    file->Printf("%s}\n", prefix);
}

namespace {

void MergeAnimEvents(
        const idStaticList<const idMD6AnimEvent*, 16>& incoming,
        idStaticList<const idMD6AnimEvent*, 16>& result) {
    for (int sourceIndex = 0; sourceIndex < incoming.Num(); ++sourceIndex) {
        const idMD6AnimEvent* event = incoming[sourceIndex];
        int destination = 0;
        while (destination < result.Num()) {
            const idMD6AnimEvent* current = result[destination];
            if (event->frameNum == current->frameNum &&
                event->row == current->row) {
                event = nullptr; // The nearer declaration overrides this row.
                break;
            }
            if (event->frameNum < current->frameNum ||
                (event->frameNum == current->frameNum &&
                 event->row < current->row)) {
                break;
            }
            ++destination;
        }
        if (event != nullptr && result.Num() < result.Max())
            result.Insert(event, destination);
    }
}

template<typename Finder>
bool FindInheritedAnimEvents(const idDeclMD6& declaration,
        Finder&& finder,
        idStaticList<const idMD6AnimEvent*, 16>& events) {
    events.Clear();
    finder(declaration.animEvents, events);

    idStaticList<const idMD6AnimEvent*, 16> inherited;
    for (const idDeclMD6* current = declaration.parentDecl;
         current != nullptr; current = current->parentDecl) {
        inherited.Clear();
        finder(current->animEvents, inherited);
        MergeAnimEvents(inherited, events);
    }
    for (int includeIndex = 0;
         includeIndex < declaration.declsToIncludeAnimDataFrom.Num();
         ++includeIndex) {
        for (const idDeclMD6* current = declaration
                 .declsToIncludeAnimDataFrom[includeIndex].includeDecl;
             current != nullptr; current = current->parentDecl) {
            inherited.Clear();
            finder(current->animEvents, inherited);
            MergeAnimEvents(inherited, events);
        }
    }
    return events.Num() != 0;
}

} // namespace

bool idDeclMD6::FindAnimEvents(const idMD6Anim* animation,
        const int startFrame, const int endFrame,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    if (animation == nullptr) {
        events.Clear();
        return false;
    }
    const idAtomicStringT<md6AnimAtomicString_t> reference(
        animation->GetName());
    return FindInheritedAnimEvents(*this,
        [&](const idAnimEvents& source,
            idStaticList<const idMD6AnimEvent*, 16>& destination) {
            source.FindAnimEvents(reference, startFrame, endFrame,
                destination);
        }, events);
}

bool idDeclMD6::FindAnimEvents(const idMD6Anim* animation,
        const int startFrame, const int endFrame, const int eventNum,
        idStaticList<const idMD6AnimEvent*, 16>& events) const {
    if (animation == nullptr) {
        events.Clear();
        return false;
    }
    const idAtomicStringT<md6AnimAtomicString_t> reference(
        animation->GetName());
    return FindInheritedAnimEvents(*this,
        [&](const idAnimEvents& source,
            idStaticList<const idMD6AnimEvent*, 16>& destination) {
            source.FindAnimEvents(reference, startFrame, endFrame,
                eventNum, destination);
        }, events);
}
