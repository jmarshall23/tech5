#include "decls/animwebs/declanimwebnode.h"

#include "decls/animwebs/declanimwebedge.h"
#include "gamelib/animstack/animweb/animwebpath.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>

bool Decls_AnimWebResolveAnim(const idDeclAnimWeb& declaration,
    int modelIndex, const char* name, idMD6AnimProps& properties);
const char* Decls_AnimWebAnimName(const idDeclMD6* model,
    const idMD6AnimProps& properties);
int Decls_AnimWebNodeCustomFlag(const char* name);
void Decls_AnimWebNodeCustomFlagNames(unsigned int flags, idStr& names);

namespace {

const char* const animDeltaNames[idDeclAnimWebNode::ANIMDELTA_MAX] = {
    "default", "full", "fullNoClip", "fullGravity", "turn",
    "fullVelocity", "fullDriveAI", "ignore"
};

int FindAnimDelta(const char* const name) {
    for (int index = 0; index < idDeclAnimWebNode::ANIMDELTA_MAX; ++index)
        if (idStr::Icmp(name, animDeltaNames[index]) == 0) return index;
    return idDeclAnimWebNode::ANIMDELTA_MAX;
}

} // namespace

idDeclAnimWebNode::idModelInfo::idModelInfo()
    : modelIndex(), blendEq(""), blendEqFixed(""), animProps(16),
      coordinates(nullptr), tagGroups(nullptr) {
}

idDeclAnimWebNode::idModelInfo::idModelInfo(const idModelInfo& other)
    : idModelInfo() {
    *this = other;
}

idDeclAnimWebNode::idModelInfo::~idModelInfo() {
    delete coordinates;
    delete tagGroups;
}

idDeclAnimWebNode::idModelInfo&
idDeclAnimWebNode::idModelInfo::operator=(const idModelInfo& other) {
    if (this == &other) return *this;
    modelIndex = other.modelIndex;
    blendEq = other.blendEq;
    blendEqFixed = other.blendEqFixed;
    animProps = other.animProps;
    if (other.coordinates != nullptr) {
        if (coordinates == nullptr) coordinates = new idList<float, 32>(16);
        *coordinates = *other.coordinates;
    } else {
        delete coordinates;
        coordinates = nullptr;
    }
    if (other.tagGroups != nullptr) {
        if (tagGroups == nullptr)
            tagGroups = new idList<idDeclAnimWebTagGroup, 32>(16);
        *tagGroups = *other.tagGroups;
    } else {
        delete tagGroups;
        tagGroups = nullptr;
    }
    return *this;
}

int idDeclAnimWebNode::idModelInfo::NumCoordinateDimensions() const {
    return coordinates != nullptr && coordinates->Num() > 0
        && animProps.Num() > 0 ? coordinates->Num() / animProps.Num() : 0;
}

void idDeclAnimWebNode::idModelInfo::SetNumCoordinateDimensions(
        const int count) {
    if (count <= 0) {
        delete coordinates;
        coordinates = nullptr;
        return;
    }
    if (coordinates == nullptr) coordinates = new idList<float, 32>(16);
    coordinates->SetNum(animProps.Num() * count);
    for (int index = 0; index < coordinates->Num(); ++index)
        (*coordinates)[index] = 0.0f;
}

void idDeclAnimWebNode::idModelInfo::SetCoordinate(
        const int propertyIndex, const idList<float, 5>& value) {
    if (coordinates == nullptr || propertyIndex < 0
        || propertyIndex >= animProps.Num()) return;
    const int dimensions = NumCoordinateDimensions();
    const int count = (std::min)(dimensions, value.Num());
    for (int index = 0; index < count; ++index)
        (*coordinates)[propertyIndex * dimensions + index] = value[index];
}

int idDeclAnimWebNode::idModelInfo::NumTagGroups() const {
    return tagGroups != nullptr ? tagGroups->Num() : 0;
}

void idDeclAnimWebNode::idModelInfo::AddTagGroup() {
    if (tagGroups == nullptr)
        tagGroups = new idList<idDeclAnimWebTagGroup, 32>(16);
    tagGroups->Alloc();
}

void idDeclAnimWebNode::idModelInfo::UpdateTagGroupsList(const int count) {
    if (count <= 0) {
        delete tagGroups;
        tagGroups = nullptr;
        return;
    }
    if (tagGroups == nullptr)
        tagGroups = new idList<idDeclAnimWebTagGroup, 32>(16);
    tagGroups->SetNum(count);
}

void idDeclAnimWebNode::idModelInfo::CopyTagGroups(
        const idModelInfo& other) {
    const int count = other.tagGroups != nullptr ? other.tagGroups->Num() : 0;
    UpdateTagGroupsList(count);
    if (count <= 0) return;
    *tagGroups = *other.tagGroups;
    const int animCount = (std::min)(animProps.Num(), other.animProps.Num());
    for (int index = 0; index < animCount; ++index)
        animProps[index].tags = other.animProps[index].tags;
}

void idDeclAnimWebNode::idModelInfo::FixUpAnimVars(
        const idDeclMD6* const modelDeclaration) {
    std::string equation(blendEq.c_str());
    for (int index = 0; index < animProps.Num(); ++index) {
        char variable[32];
        std::snprintf(variable, sizeof(variable), "anim%d", index);
        const char* const animationName = Decls_AnimWebAnimName(
            modelDeclaration, animProps[index]);
        if (animationName == nullptr || animationName[0] == '\0') continue;
        std::size_t position = 0;
        while ((position = equation.find(variable, position))
                != std::string::npos) {
            equation.replace(position, std::strlen(variable), animationName);
            position += std::strlen(animationName);
        }
    }
    blendEqFixed.Set(equation.c_str());
}

void idDeclAnimWebNode::idModelInfo::Parse(idDeclAnimWeb* const declaration,
        idDeclAnimWebNode* const node, idParser& parser) {
    if (declaration == nullptr || node == nullptr) return;
    ++declaration->changeId;
    if (!parser.ExpectTokenString("tree") || !parser.ExpectTokenString("{"))
        return;
    modelIndex = idDeclAnimWeb::modelIndex_t(0);
    if (parser.CheckTokenString("modelIndex") != 0)
        modelIndex = idDeclAnimWeb::modelIndex_t(
            static_cast<short>(parser.ParseInt()));

    idToken token;
    if (!parser.ExpectTokenString("blendEq")
        || parser.ExpectTokenType(TT_STRING, 0, token) == 0) return;
    blendEq.Set(token.c_str()[0] != '\0' ? token.c_str() : "anim0");

    while (parser.CheckTokenString("tagGroup") != 0) {
        AddTagGroup();
        idDeclAnimWebTagGroup& group = (*tagGroups)[tagGroups->Num() - 1];
        if (parser.ExpectTokenType(TT_STRING, 0, token) == 0
            || !parser.ExpectTokenString("{")) return;
        group.name.Set(token.c_str());
        while (parser.CheckTokenString("tag") != 0) {
            idDeclAnimWebTag tag;
            if (parser.ExpectTokenType(TT_STRING, 0, token) == 0) return;
            tag.name.Set(token.c_str());
            tag.isDefault = parser.ParseInt() != 0;
            group.tagList.Append(tag);
        }
        parser.ExpectTokenString("}");
    }

    if (!parser.ExpectTokenString("anims") || !parser.ExpectTokenString("{"))
        return;
    while (parser.ReadToken(token) != 0) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Cmp(token.c_str(), "alias") != 0) {
            parser.Error("Unknown token '%s' in 'anims' block.", token.c_str());
            continue;
        }
        if (!parser.ExpectTokenString("{") || !parser.ExpectTokenString("name")
            || parser.ExpectTokenType(TT_STRING, 0, token) == 0) return;
        idStr animationName(token.c_str());
        idMD6AnimProps* const properties = animProps.Alloc();
        if (properties == nullptr) return;
        Decls_AnimWebResolveAnim(*declaration, modelIndex.Get(),
            animationName.c_str(), *properties);

        idList<float, 5> coordinateValues(6);
        while (parser.ReadToken(token) != 0) {
            if (idStr::Cmp(token.c_str(), "}") == 0) break;
            if (idStr::Cmp(token.c_str(), "wrap") == 0) {
                if (parser.ExpectTokenType(TT_NAME, 0, token) == 0) return;
                if (idStr::Icmp(token.c_str(), "repeat") == 0)
                    properties->wrap = idMD6Leaf::WRAP_REPEAT;
                else if (idStr::Icmp(token.c_str(), "clamp") == 0)
                    properties->wrap = idMD6Leaf::WRAP_CLAMP;
                else parser.Error("Unknown wrap mode '%s'", token.c_str());
            } else if (idStr::Cmp(token.c_str(), "rate") == 0) {
                properties->rate = parser.ParseFloat();
            } else if (idStr::Cmp(token.c_str(), "tags") == 0) {
                while (parser.ReadTokenOnLine(token) != 0) {
                    unsigned int bit = 1;
                    bool found = false;
                    if (tagGroups != nullptr) {
                        for (int group = 0; group < tagGroups->Num() && !found;
                                ++group) {
                            for (int tag = 0;
                                    tag < (*tagGroups)[group].tagList.Num();
                                    ++tag, bit <<= 1) {
                                if (idStr::Cmp((*tagGroups)[group].tagList[tag]
                                        .name.c_str(), token.c_str()) == 0) {
                                    properties->tags |= bit;
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (!found)
                        parser.Warning("Unknown tag '%s'", token.c_str());
                }
            } else if (idStr::Cmp(token.c_str(), "coordinate") == 0) {
                if (!parser.ExpectTokenString("(")) return;
                coordinateValues.Clear();
                while (parser.ReadToken(token) != 0
                        && idStr::Cmp(token.c_str(), ")") != 0) {
                    if (idStr::Cmp(token.c_str(), ",") == 0) continue;
                    coordinateValues.Append(static_cast<float>(
                        std::atof(token.c_str())));
                }
            } else {
                parser.Error("Unknown token '%s' in 'alias' block.",
                    token.c_str());
            }
        }
        if (coordinateValues.Num() > 0) {
            const int dimensions = coordinateValues.Num();
            if (coordinates == nullptr) {
                SetNumCoordinateDimensions(dimensions);
            } else if (coordinates->Num() < animProps.Num() * dimensions) {
                coordinates->SetNum(animProps.Num() * dimensions);
            }
            const int offset = (animProps.Num() - 1) * dimensions;
            for (int index = 0; index < dimensions; ++index)
                (*coordinates)[offset + index] = coordinateValues[index];
        }
    }
    parser.ExpectTokenString("}");
    const idDeclMD6* const model = modelIndex.IsValid()
        && modelIndex.Get() < declaration->models.Num()
        ? declaration->models[modelIndex.Get()] : nullptr;
    FixUpAnimVars(model);
}

void idDeclAnimWebNode::idModelInfo::Write(
        const idDeclAnimWeb* const declaration,
        const idDeclAnimWeb::subWebIndex_t, const idDeclMD6* const model,
        idFile_String& file, const char* const indent) const {
    const char* const tabs = indent != nullptr ? indent : "";
    file.WriteFloatString("%stree {\n", tabs);
    if (modelIndex.Get() != 0)
        file.WriteFloatString("%s\tmodelIndex %d\n", tabs, modelIndex.Get());
    file.WriteFloatString("%s\tblendEq \"%s\"\n", tabs, blendEq.c_str());
    if (tagGroups != nullptr) {
        for (int groupIndex = 0; groupIndex < tagGroups->Num(); ++groupIndex) {
            const idDeclAnimWebTagGroup& group = (*tagGroups)[groupIndex];
            file.WriteFloatString("%s\ttagGroup \"%s\" {\n", tabs,
                group.name.c_str());
            for (int tagIndex = 0; tagIndex < group.tagList.Num(); ++tagIndex) {
                const idDeclAnimWebTag& tag = group.tagList[tagIndex];
                file.WriteFloatString("%s\t\ttag \"%s\" %d\n", tabs,
                    tag.name.c_str(), tag.isDefault ? 1 : 0);
            }
            file.WriteFloatString("%s\t}\n", tabs);
        }
    }
    file.WriteFloatString("%s\tanims {\n", tabs);
    const int dimensions = coordinates != nullptr && animProps.Num() > 0
        ? coordinates->Num() / animProps.Num() : 0;
    for (int index = 0; index < animProps.Num(); ++index) {
        const idMD6AnimProps& properties = animProps[index];
        file.WriteFloatString("%s\t\talias {\n", tabs);
        file.WriteFloatString("%s\t\t\tname \"%s\"\n", tabs,
            Decls_AnimWebAnimName(model, properties));
        if (properties.wrap == idMD6Leaf::WRAP_REPEAT)
            file.WriteFloatString("%s\t\t\twrap repeat\n", tabs);
        if (properties.rate != 1.0f)
            file.WriteFloatString("%s\t\t\trate %g\n", tabs, properties.rate);
        if (properties.tags != 0 && tagGroups != nullptr) {
            file.WriteFloatString("%s\t\t\ttags", tabs);
            unsigned int bit = 1;
            for (int group = 0; group < tagGroups->Num(); ++group) {
                for (int tag = 0; tag < (*tagGroups)[group].tagList.Num();
                        ++tag, bit <<= 1) {
                    if ((properties.tags & bit) != 0)
                        file.WriteFloatString(" %s",
                            (*tagGroups)[group].tagList[tag].name.c_str());
                }
            }
            file.WriteFloatString("\n");
        }
        if (dimensions > 0) {
            file.WriteFloatString("%s\t\t\tcoordinate (", tabs);
            for (int dimension = 0; dimension < dimensions; ++dimension)
                file.WriteFloatString("%s%g", dimension != 0 ? ", " : " ",
                    (*coordinates)[index * dimensions + dimension]);
            file.WriteFloatString(" )\n");
        }
        file.WriteFloatString("%s\t\t}\n", tabs);
    }
    file.WriteFloatString("%s\t}\n%s}\n", tabs, tabs);
    (void)declaration;
}

idDeclAnimWebNode::idDeclAnimWebNode(
        const idDeclAnimWeb::nodeIndex_t nodeIndex_,
        const idDeclAnimWeb::subWebIndex_t subWebIndex_,
        const idDeclAnimWeb::stateIndex_t stateIndex_)
    : nodeIndex(nodeIndex_), subWebIndex(subWebIndex_), states(), animDelta(0),
      flags(0), customFlags(0), edges(16), modelInfo(16), settings() {
    states.numStates = 1;
    states.stateIndex[0] = stateIndex_;
}

idDeclAnimWebNode::idDeclAnimWebNode(
        const idDeclAnimWeb::nodeIndex_t nodeIndex_,
        const idDeclAnimWeb::subWebIndex_t subWebIndex_,
        const idDeclAnimWeb::stateList_t& stateIndices)
    : nodeIndex(nodeIndex_), subWebIndex(subWebIndex_), states(stateIndices),
      animDelta(0), flags(0), customFlags(0), edges(16), modelInfo(16),
      settings() {
}

idDeclAnimWebNode::~idDeclAnimWebNode() = default;

int idDeclAnimWebNode::MatchStates(
        const idDeclAnimWeb::stateList_t& stateList) const {
    int matches = 0;
    for (int ours = 0; ours < states.numStates; ++ours) {
        for (int theirs = 0; theirs < stateList.numStates; ++theirs) {
            if (states.stateIndex[ours] == stateList.stateIndex[theirs]) {
                ++matches;
                break;
            }
        }
    }
    return matches;
}

void idDeclAnimWebNode::GetPath(const idDeclAnimWeb* const declaration,
        idAnimWebPath& path) const {
    path.SetPath(declaration != nullptr ? declaration->GetName() : "",
        declaration != nullptr ? declaration->GetSubWebName(subWebIndex) : "",
        declaration != nullptr && states.numStates > 0
            ? declaration->GetStateName(states.stateIndex[0]) : "");
}

void idDeclAnimWebNode::GetStateName(
        const idDeclAnimWeb* const declaration, idStr& name) const {
    GetStateName(declaration, 0, name);
}

void idDeclAnimWebNode::GetStateName(const idDeclAnimWeb* const declaration,
        const int state, idStr& name) const {
    name = declaration != nullptr && state >= 0 && state < states.numStates
        ? declaration->GetStateName(states.stateIndex[state]) : "";
}

void idDeclAnimWebNode::GetName(const idDeclAnimWeb* const declaration,
        idStr& name) const {
    name = declaration != nullptr ? declaration->GetSubWebName(subWebIndex) : "";
    for (int state = 0; state < states.numStates; ++state) {
        name.Append('/');
        name.Append(declaration != nullptr
            ? declaration->GetStateName(states.stateIndex[state]) : "");
    }
}

const idDeclAnimWebNode::idModelInfo* idDeclAnimWebNode::FindModelInfo(
        const idDeclAnimWeb::modelIndex_t model) const {
    for (int index = 0; index < modelInfo.Num(); ++index)
        if (modelInfo[index].modelIndex == model) return &modelInfo[index];
    return nullptr;
}

idDeclAnimWebNode::idModelInfo* idDeclAnimWebNode::FindModelInfo(
        const idDeclAnimWeb::modelIndex_t model) {
    return const_cast<idModelInfo*>(
        static_cast<const idDeclAnimWebNode*>(this)->FindModelInfo(model));
}

bool idDeclAnimWebNode::IsLooping() const {
    for (int model = 0; model < modelInfo.Num(); ++model)
        for (int animation = 0; animation < modelInfo[model].animProps.Num();
                ++animation)
            if (modelInfo[model].animProps[animation].wrap
                    == idMD6Leaf::WRAP_REPEAT) return true;
    return false;
}

unsigned int idDeclAnimWebNode::Size() const {
    return static_cast<unsigned int>(2
        * (18 * modelInfo.NumAllocated() + edges.NumAllocated() + 32));
}

int idDeclAnimWebNode::NumAnims(
        const idDeclAnimWeb::modelIndex_t model) const {
    const idModelInfo* const info = FindModelInfo(model);
    return info != nullptr ? info->animProps.Num() : 0;
}

const idMD6Anim* idDeclAnimWebNode::GetAnim(
        const idDeclAnimWeb::modelIndex_t model, const int animation) const {
    const idModelInfo* const info = FindModelInfo(model);
    if (info == nullptr || animation < 0 || animation >= info->animProps.Num())
        return nullptr;
    return info->animProps[animation].anim;
}

void idDeclAnimWebNode::CreateSubWebEdges(idDeclAnimWeb* const declaration) {
    if (declaration == nullptr) return;
    const int originalCount = edges.Num();
    for (int local = 0; local < originalCount; ++local) {
        const int edgeNumber = edges[local].Get();
        if (edgeNumber < 0 || edgeNumber >= declaration->edges.Num()
            || edgeNumber >= declaration->edgeCache.Num()) continue;
        idDeclAnimWeb::idEdgeCache cache = declaration->edgeCache[edgeNumber];
        if (cache.destNodeIndex.IsValid()) continue;
        const int subWeb = declaration->edges[edgeNumber].destSubWebIndex;
        if (subWeb < 0 || subWeb >= declaration->subWebs.Num()) continue;
        const idDeclAnimWeb::idSubWebInfo& target = declaration->subWebs[subWeb];
        if (target.nodes.Num() == 0) continue;
        cache.destNodeIndex = target.nodes[0];
        declaration->edgeCache[edgeNumber] = cache;
        for (int targetNode = 1; targetNode < target.nodes.Num(); ++targetNode) {
            const idDeclAnimWeb::edgeIndex_t clone = declaration->AllocEdge();
            declaration->edges[clone.Get()] = declaration->edges[edgeNumber];
            cache.destNodeIndex = target.nodes[targetNode];
            declaration->edgeCache[clone.Get()] = cache;
            edges.Append(clone);
        }
    }
}

void idDeclAnimWebNode::Write(const idDeclAnimWeb* const declaration,
        idFile_String& file, const char* const indent) const {
    if (declaration == nullptr) return;
    const char* const tabs = indent != nullptr ? indent : "";
    file.WriteFloatString("%snode ", tabs);
    for (int state = 0; state < states.numStates; ++state)
        file.WriteFloatString("\"%s\" ",
            declaration->GetStateName(states.stateIndex[state]));
    file.WriteFloatString("{\n%s\tprops {\n", tabs);
    if (animDelta != ANIMDELTA_DEFAULT && animDelta < ANIMDELTA_MAX)
        file.WriteFloatString("%s\t\tdelta %s\n", tabs,
            animDeltaNames[animDelta]);
    file.WriteFloatString("%s\t\tpos ( %g %g %g )\n", tabs,
        settings.pos.x, settings.pos.y, settings.pos.z);
    const struct { unsigned int bit; const char* name; } flagNames[] = {
        { NODEFLAG_START_TRANSITION, "startTransition" },
        { NODEFLAG_STOP_TRANSITION, "stopTransition" },
        { NODEFLAG_STEP_TRANSITION, "stepTransition" },
        { NODEFLAG_TURN_TRANSITION, "turnTransition" },
        { NODEFLAG_BLENDOUT, "blendOutNode" },
        { NODEFLAG_ADDITIVECAMERA, "additiveCamera" },
        { NODEFLAG_GENERIC_TRANSITION, "genericTransition" },
        { NODEFLAG_HIDE, "hide" }
    };
    for (const auto& entry : flagNames)
        if ((flags & entry.bit) != 0)
            file.WriteFloatString("%s\t\t%s\n", tabs, entry.name);
    if (customFlags != 0) {
        idStr names;
        Decls_AnimWebNodeCustomFlagNames(customFlags, names);
        file.WriteFloatString("%s\t\tcustomFlags %s\n", tabs,
            names.c_str());
    }
    file.WriteFloatString("%s\t}\n%s\tblendTrees {\n", tabs, tabs);
    for (int model = 0; model < modelInfo.Num(); ++model) {
        idStr treeIndent(tabs); treeIndent.Append("\t\t");
        const int modelNumber = modelInfo[model].modelIndex.Get();
        const idDeclMD6* const modelDeclaration = modelNumber >= 0
            && modelNumber < declaration->models.Num()
            ? declaration->models[modelNumber] : nullptr;
        modelInfo[model].Write(declaration, subWebIndex, modelDeclaration,
            file, treeIndent.c_str());
    }
    file.WriteFloatString("%s\t}\n%s\tedges {\n", tabs, tabs);
    for (int index = 0; index < edges.Num(); ++index) {
        const int edgeNumber = edges[index].Get();
        if (edgeNumber < 0 || edgeNumber >= declaration->edges.Num()
            || edgeNumber >= declaration->edgeCache.Num()) continue;
        idStr edgeIndent(tabs); edgeIndent.Append("\t\t");
        declaration->edges[edgeNumber].Write(declaration, this,
            reinterpret_cast<const idAnimWebEdgeCache*>(
                &declaration->edgeCache[edgeNumber]), file,
            edgeIndent.c_str());
    }
    file.WriteFloatString("%s\t}\n%s}\n", tabs, tabs);
}

void idDeclAnimWebNode::AddModelInfo(const idModelInfo& info,
        const idDeclAnimWeb::modelIndex_t model) {
    idModelInfo* existing = FindModelInfo(model);
    if (existing == nullptr) {
        modelInfo.Append(info);
        existing = &modelInfo[modelInfo.Num() - 1];
    } else {
        *existing = info;
    }
    existing->modelIndex = model;
}

bool idDeclAnimWebNode::Parse(idDeclAnimWeb* const declaration,
        idParser& parser) {
    if (declaration == nullptr) return false;
    ++declaration->changeId;
    edges.Clear();
    if (!parser.ExpectTokenString("props") || !parser.ExpectTokenString("{"))
        return false;
    idToken token;
    while (parser.ReadToken(token) != 0) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        const char* const property = token.c_str();
        if (idStr::Cmp(property, "delta") == 0) {
            if (parser.ReadToken(token) == 0) return false;
            animDelta = static_cast<std::uint8_t>(FindAnimDelta(token.c_str()));
            if (animDelta == ANIMDELTA_MAX)
                parser.Error("Unknown animDelta value '%s' in anim web '%s'.",
                    token.c_str(), declaration->GetName());
        } else if (idStr::Cmp(property, "startTransition") == 0
                || idStr::Cmp(property, "transition") == 0) {
            flags |= NODEFLAG_START_TRANSITION;
        } else if (idStr::Cmp(property, "stopTransition") == 0) {
            flags |= NODEFLAG_STOP_TRANSITION;
        } else if (idStr::Cmp(property, "stepTransition") == 0) {
            flags |= NODEFLAG_STEP_TRANSITION;
        } else if (idStr::Cmp(property, "turnTransition") == 0) {
            flags |= NODEFLAG_TURN_TRANSITION;
        } else if (idStr::Cmp(property, "blendOutNode") == 0) {
            flags |= NODEFLAG_BLENDOUT;
        } else if (idStr::Cmp(property, "additiveCamera") == 0) {
            flags |= NODEFLAG_ADDITIVECAMERA;
        } else if (idStr::Cmp(property, "hide") == 0) {
            flags |= NODEFLAG_HIDE;
        } else if (idStr::Cmp(property, "genericTransition") == 0) {
            flags |= NODEFLAG_GENERIC_TRANSITION;
        } else if (idStr::Cmp(property, "customFlags") == 0) {
            while (parser.ReadTokenOnLine(token) != 0) {
                const int value = Decls_AnimWebNodeCustomFlag(token.c_str());
                if (value >= 0) customFlags |= static_cast<std::uint16_t>(value);
                else parser.Warning("unrecognized custom flag '%s'",
                    token.c_str());
            }
        } else if (idStr::Cmp(property, "pos") == 0) {
            parser.Parse1DMatrix(3, &settings.pos.x);
        } else {
            parser.Error("Unknown token '%s' in anim web node 'props' block.",
                property);
        }
    }

    if (!parser.ExpectTokenString("blendTrees")
        || !parser.ExpectTokenString("{")) return false;
    modelInfo.Clear();
    while (parser.PeekTokenString("tree") != 0) {
        idModelInfo* const info = modelInfo.Alloc();
        if (info == nullptr) return false;
        info->Parse(declaration, this, parser);
    }
    if (!parser.ExpectTokenString("}") || !parser.ExpectTokenString("edges")
        || !parser.ExpectTokenString("{")) return false;
    while (parser.ReadToken(token) != 0) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        if (idStr::Cmp(token.c_str(), "edge") != 0) {
            parser.Error("Unknown token '%s' in 'edges' block.", token.c_str());
            continue;
        }
        idDeclAnimWebEdge edge;
        idDeclAnimWeb::idEdgeCache cache;
        edge.Parse(declaration, this,
            reinterpret_cast<idAnimWebEdgeCache*>(&cache), parser);
        const idDeclAnimWeb::edgeIndex_t edgeIndex = declaration->AllocEdge();
        declaration->edges[edgeIndex.Get()] = edge;
        declaration->edgeCache[edgeIndex.Get()] = cache;
        edges.Append(edgeIndex);
    }
    return true;
}
