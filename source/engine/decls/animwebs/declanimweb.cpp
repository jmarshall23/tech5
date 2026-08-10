#include "decls/animwebs/declanimweb.h"

#include "decls/animwebs/declanimwebedge.h"
#include "decls/animwebs/declanimwebnode.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cstring>
#include <vector>

const idDeclMD6* Decls_FindMD6Declaration(const char* name);
const char* Decls_MD6DeclarationName(const idDeclMD6* declaration);

namespace {

const char* const nodePropNames[idDeclAnimWeb::NP_MAX] = {
    "showAnim", "showWrap", "showRate", "showDelta", "showBlendEq",
    "showTransition"
};

const char* const subWebBlendNames[idDeclAnimWeb::SUBWEBBLEND_MAX] = {
    "useSourceNode", "alwaysBlendOutAnywhere"
};

bool ReadQuotedOrName(idParser& parser, idToken& token) {
    if (parser.ReadToken(token) == 0) return false;
    return token.type == TT_STRING || token.type == TT_NAME;
}

} // namespace

idDeclInfoTemplate<idDeclAnimWeb> idDeclAnimWeb::resourceList(
    "animWeb", "idDeclAnimWeb", "aweb");

idDeclAnimWeb::stateList_t::stateList_t() : stateIndex{}, numStates(0) {}

idDeclAnimWeb::idSubWebInfo::idSubWebInfo()
    : nodes(16), name(""), color(1.0f, 1.0f, 1.0f, 1.0f),
      isHub(false), isVisible(true), used(false) {
}

idDeclAnimWeb::idEdgeCache::idEdgeCache()
    : destNodeIndex(), weightScale(16), flags(0) {
}

idDeclAnimWeb::idNodeCache::idNodeCache()
    : numEdges(0), flags(0), pad2(0), edgeIndexOffset(0) {
}

idDeclAnimWeb::idLayerInfo::idLayerInfo()
    : name(""), subWebsOnLayer(16), isVisible(true) {
}

idDeclAnimWeb::idSettings::idSettings()
    : editPos(0.0f, 0.0f, 1.0f), gridSize(32), snapToGrid(true),
      showGrid(true), alwaysShowIntraSubwebLinks(true),
      alwaysShowNodeProps(false), showAbbreviatedNodeProps(false),
      showIncomingLinks(false), isComposite(false), mergeModels(true),
      nodeProps{true, true, false, true, true, true},
      defaultBlendOutWindow(10), defaultBlendDuration(10),
      subWebBlend(SUBWEBBLEND_USE_SOURCE_NODE) {
}

idDeclAnimWeb::idDeclAnimWeb()
    : idDecl(), nodes(16), subWebs(16), states(16), models(16), edges(16),
      edgeCache(16), nodeCache(16), scalars(16), editorModels(16), layers(16),
      edgeIndexCache(nullptr), edgeIndexCacheSize(0), changeId(0),
      expandSubWebLinks(true), settings() {
}

idDeclAnimWeb::~idDeclAnimWeb() { FreeData(); }

const char* idDeclAnimWeb::DefaultDefinition() const {
    return "{\n\tprops {\n\t}\nstates {\n\t}\n\tsubWebs {\n\t}\n}\n";
}

idDeclInfo* idDeclAnimWeb::GetDeclInfo() const { return &resourceList; }

idAtomicString idDeclAnimWeb::GetStateNameAtomic(
        const stateIndex_t index) const {
    return index.IsValid() && index.Get() < states.Num()
        ? states[index.Get()].name : idAtomicString("");
}

idDeclAnimWeb::stateIndex_t idDeclAnimWeb::GetStateIndexForName(
        const char* const stateName) const {
    if (stateName == nullptr) return stateIndex_t();
    for (int index = 0; index < states.Num(); ++index)
        if (idStr::Icmp(states[index].name.c_str(), stateName) == 0)
            return stateIndex_t(static_cast<short>(index));
    return stateIndex_t();
}

idDeclAnimWeb::subWebIndex_t idDeclAnimWeb::GetSubWebIndexForName(
        const char* const subWebName) const {
    if (subWebName == nullptr || subWebName[0] == '\0') return subWebIndex_t();
    for (int index = 0; index < subWebs.Num(); ++index)
        if (idStr::Icmp(subWebs[index].name.c_str(), subWebName) == 0)
            return subWebIndex_t(static_cast<short>(index));
    return subWebIndex_t();
}

const char* idDeclAnimWeb::GetSubWebName(const subWebIndex_t index) const {
    return index.IsValid() && index.Get() < subWebs.Num()
        ? subWebs[index.Get()].name.c_str() : "";
}

idAtomicString idDeclAnimWeb::GetSubWebNameAtomic(
        const subWebIndex_t index) const {
    return index.IsValid() && index.Get() < subWebs.Num()
        ? subWebs[index.Get()].name : idAtomicString("");
}

const char* idDeclAnimWeb::GetStateName(const stateIndex_t index) const {
    return index.IsValid() && index.Get() < states.Num()
        ? states[index.Get()].name.c_str() : "";
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::FindNodeIndex(
        const subWebIndex_t subWeb, const stateIndex_t state) const {
    if (!subWeb.IsValid() || !state.IsValid()
        || subWeb.Get() >= subWebs.Num()) return nodeIndex_t();
    const idSubWebInfo& info = subWebs[subWeb.Get()];
    for (int index = 0; index < info.nodes.Num(); ++index) {
        const int nodeNumber = info.nodes[index].Get();
        if (nodeNumber < 0 || nodeNumber >= nodes.Num()
            || nodes[nodeNumber] == nullptr) continue;
        const idDeclAnimWebNode& node = *nodes[nodeNumber];
        if (node.states.numStates > 0 && node.states.stateIndex[0] == state)
            return node.nodeIndex;
    }
    return nodeIndex_t();
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::FindNodeIndex(
        const subWebIndex_t subWeb, const stateList_t& stateList,
        const bool exact) const {
    if (!subWeb.IsValid() || subWeb.Get() >= subWebs.Num())
        return nodeIndex_t();
    const idSubWebInfo& info = subWebs[subWeb.Get()];
    idDeclAnimWebNode* best = nullptr;
    int bestMatches = 0;
    for (int index = 0; index < info.nodes.Num(); ++index) {
        const int nodeNumber = info.nodes[index].Get();
        if (nodeNumber < 0 || nodeNumber >= nodes.Num()) continue;
        idDeclAnimWebNode* const node = nodes[nodeNumber];
        if (node == nullptr) continue;
        const int matches = node->MatchStates(stateList);
        if (matches == stateList.numStates) return node->nodeIndex;
        if (matches > bestMatches) { bestMatches = matches; best = node; }
    }
    return !exact && best != nullptr ? best->nodeIndex : nodeIndex_t();
}

idDeclAnimWeb::modelIndex_t idDeclAnimWeb::FindModelIndex(
        const idDeclMD6* const model) const {
    for (int index = 0; index < models.Num(); ++index)
        if (models[index] == model)
            return modelIndex_t(static_cast<short>(index));
    return modelIndex_t();
}

const idList<idAnimWebScalar, 32>& idDeclAnimWeb::GetScalars() const {
    return scalars;
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::GetNodeIndexForName(
        const char* const subWeb, const char* const state) const {
    return FindNodeIndex(GetSubWebIndexForName(subWeb),
        GetStateIndexForName(state));
}

const idDeclAnimWebEdge* idDeclAnimWeb::FindEdge(
        const nodeIndex_t source, const nodeIndex_t destination) const {
    if (!source.IsValid() || source.Get() >= nodes.Num()
        || nodes[source.Get()] == nullptr) return nullptr;
    const idDeclAnimWebNode& node = *nodes[source.Get()];
    for (int index = 0; index < node.edges.Num(); ++index) {
        const int edgeNumber = node.edges[index].Get();
        if (edgeNumber >= 0 && edgeNumber < edges.Num()
            && edgeNumber < edgeCache.Num()
            && edgeCache[edgeNumber].destNodeIndex == destination)
            return &edges[edgeNumber];
    }
    return nullptr;
}

int idDeclAnimWeb::FindNodeIndices(const subWebIndex_t subWeb,
        const stateIndex_t state, idList<nodeIndex_t, 5>& output) const {
    output.Clear();
    if (!subWeb.IsValid() || subWeb.Get() >= subWebs.Num()) return 0;
    const idSubWebInfo& info = subWebs[subWeb.Get()];
    for (int index = 0; index < info.nodes.Num(); ++index) {
        const int nodeNumber = info.nodes[index].Get();
        if (nodeNumber < 0 || nodeNumber >= nodes.Num()
            || nodes[nodeNumber] == nullptr) continue;
        const idDeclAnimWebNode& node = *nodes[nodeNumber];
        for (int stateNumber = 0; stateNumber < node.states.numStates;
                ++stateNumber) {
            if (node.states.stateIndex[stateNumber] == state) {
                output.Append(node.nodeIndex);
                break;
            }
        }
    }
    return output.Num();
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::FindNodeIndices(
        const subWebIndex_t subWeb, const stateList_t& stateList,
        idList<nodeIndex_t, 5>& output) const {
    output.Clear();
    if (!subWeb.IsValid() || subWeb.Get() >= subWebs.Num())
        return nodeIndex_t();
    const idSubWebInfo& info = subWebs[subWeb.Get()];
    for (int index = 0; index < info.nodes.Num(); ++index) {
        const int nodeNumber = info.nodes[index].Get();
        if (nodeNumber >= 0 && nodeNumber < nodes.Num()
            && nodes[nodeNumber] != nullptr
            && nodes[nodeNumber]->MatchStates(stateList) == stateList.numStates)
            output.Append(nodes[nodeNumber]->nodeIndex);
    }
    return output.Num() > 0 ? output[0] : nodeIndex_t();
}

idDeclAnimWeb::subWebIndex_t idDeclAnimWeb::AddSubWeb(
        const char* const subWebName) {
    subWebIndex_t index = GetSubWebIndexForName(subWebName);
    if (index.IsValid()) return index;
    idSubWebInfo* const info = subWebs.Alloc();
    if (info == nullptr) return subWebIndex_t();
    info->name.Set(subWebName != nullptr ? subWebName : "");
    ++changeId;
    return subWebIndex_t(static_cast<short>(subWebs.Num() - 1));
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::AddNode(
        const subWebIndex_t subWeb, const stateIndex_t state) {
    nodeIndex_t index = FindNodeIndex(subWeb, state);
    if (index.IsValid()) return index;
    if (!subWeb.IsValid() || subWeb.Get() >= subWebs.Num()) return nodeIndex_t();
    index = nodeIndex_t(static_cast<short>(nodes.Num()));
    idDeclAnimWebNode* const node = new idDeclAnimWebNode(index, subWeb, state);
    nodes.Append(node);
    subWebs[subWeb.Get()].nodes.Append(index);
    ++changeId;
    return index;
}

idDeclAnimWeb::nodeIndex_t idDeclAnimWeb::AddNode(
        const subWebIndex_t subWeb, const stateList_t& stateList) {
    nodeIndex_t index = FindNodeIndex(subWeb, stateList, true);
    if (index.IsValid()) return index;
    if (!subWeb.IsValid() || subWeb.Get() >= subWebs.Num()) return nodeIndex_t();
    index = nodeIndex_t(static_cast<short>(nodes.Num()));
    idDeclAnimWebNode* const node = new idDeclAnimWebNode(index, subWeb,
        stateList);
    nodes.Append(node);
    subWebs[subWeb.Get()].nodes.Append(index);
    ++changeId;
    return index;
}

void idDeclAnimWeb::AddNode(const char* const subWebName,
        const char* const stateName, nodeIndex_t& node,
        subWebIndex_t& subWebIndex, stateIndex_t& stateIndex) {
    subWebIndex = AddSubWeb(subWebName);
    stateIndex = GetStateIndexForName(stateName);
    if (!stateIndex.IsValid()) {
        idStateInfo* const state = states.Alloc();
        if (state == nullptr) { node.Invalidate(); return; }
        state->name.Set(stateName != nullptr ? stateName : "");
        stateIndex = stateIndex_t(static_cast<short>(states.Num() - 1));
        ++changeId;
    }
    node = AddNode(subWebIndex, stateIndex);
    ++changeId;
}

idDeclAnimWeb::edgeIndex_t idDeclAnimWeb::AllocEdge() {
    const edgeIndex_t index(static_cast<short>(edges.Num()));
    edges.Alloc();
    edgeCache.Alloc();
    return index;
}

unsigned int idDeclAnimWeb::Size() const {
    unsigned int bytes = 276;
    for (int index = 0; index < nodes.Num(); ++index)
        if (nodes[index] != nullptr) bytes += nodes[index]->Size();
    for (int index = 0; index < subWebs.Num(); ++index)
        bytes += 2u * static_cast<unsigned int>(
            subWebs[index].nodes.NumAllocated() + 20);
    bytes += 4u * static_cast<unsigned int>(states.Num());
    bytes += 4u * (2u * (4u * edges.NumAllocated()
        + nodeCache.NumAllocated()) + edgeCache.NumAllocated()
        + models.NumAllocated());
    return bytes + edgeIndexCacheSize;
}

void idDeclAnimWeb::FreeData() {
    for (int index = 0; index < nodes.Num(); ++index) delete nodes[index];
    nodes.ClearFree();
    subWebs.ClearFree();
    states.ClearFree();
    models.ClearFree();
    edges.ClearFree();
    edgeCache.ClearFree();
    nodeCache.ClearFree();
    scalars.ClearFree();
    editorModels.ClearFree();
    layers.ClearFree();
    delete[] edgeIndexCache;
    edgeIndexCache = nullptr;
    edgeIndexCacheSize = 0;
    ++changeId;
}

void idDeclAnimWeb::Write(idFile_String& file, const char* const indent) const {
    const char* const tabs = indent != nullptr ? indent : "";
    file.WriteFloatString("%s{\n%s\tprops {\n", tabs, tabs);
    file.WriteFloatString("%s\t\teditPos ( %g %g %g )\n", tabs,
        settings.editPos.x, settings.editPos.y, settings.editPos.z);
    file.WriteFloatString("%s\t\tgridSize %d\n", tabs, settings.gridSize);
    file.WriteFloatString("%s\t\tsnapToGrid %d\n", tabs,
        settings.snapToGrid ? 1 : 0);
    file.WriteFloatString("%s\t\tshowGrid %d\n", tabs,
        settings.showGrid ? 1 : 0);
    file.WriteFloatString("%s\t\talwaysShowIntraSubwebLinks %d\n", tabs,
        settings.alwaysShowIntraSubwebLinks ? 1 : 0);
    file.WriteFloatString("%s\t\tdefaultBlendOutWindow %d\n", tabs,
        settings.defaultBlendOutWindow);
    file.WriteFloatString("%s\t\tdefaultBlendDuration %d\n", tabs,
        settings.defaultBlendDuration);
    file.WriteFloatString("%s\t\tsubWebBlend \"%s\"\n", tabs,
        subWebBlendNames[settings.subWebBlend < SUBWEBBLEND_MAX
            ? settings.subWebBlend : SUBWEBBLEND_USE_SOURCE_NODE]);
    file.WriteFloatString("%s\t\talwaysShowNodeProps %d\n", tabs,
        settings.alwaysShowNodeProps ? 1 : 0);
    file.WriteFloatString("%s\t\tshowAbbreviatedNodeProps %d\n", tabs,
        settings.showAbbreviatedNodeProps ? 1 : 0);
    file.WriteFloatString("%s\t\tshowIncomingLinks %d\n", tabs,
        settings.showIncomingLinks ? 1 : 0);
    file.WriteFloatString("%s\t\tmergeModels %d\n", tabs,
        settings.mergeModels ? 1 : 0);
    for (int property = 0; property < NP_MAX; ++property)
        file.WriteFloatString("%s\t\t%s %d\n", tabs,
            nodePropNames[property], settings.nodeProps[property] ? 1 : 0);
    if (models.Num() > 0) {
        file.WriteFloatString("%s\t\tmodels {\n", tabs);
        for (int index = 0; index < models.Num(); ++index)
            file.WriteFloatString("%s\t\t\t\"%s\"\n", tabs,
                Decls_MD6DeclarationName(models[index]));
        file.WriteFloatString("%s\t\t}\n", tabs);
    }
    if (editorModels.Num() > 0) {
        file.WriteFloatString("%s\t\teditorModels {\n", tabs);
        for (int index = 0; index < editorModels.Num(); ++index)
            file.WriteFloatString("%s\t\t\t\"%s\"\n", tabs,
                editorModels[index].c_str());
        file.WriteFloatString("%s\t\t}\n", tabs);
    }
    file.WriteFloatString("%s\t}\n", tabs);

    if (layers.Num() > 0) {
        file.WriteFloatString("%s\tlayers {\n", tabs);
        for (int index = 0; index < layers.Num(); ++index) {
            const idLayerInfo& layer = layers[index];
            file.WriteFloatString("%s\t\tlayer \"%s\" {\n", tabs,
                layer.name.c_str());
            file.WriteFloatString("%s\t\t\tvisible %d\n", tabs,
                layer.isVisible ? 1 : 0);
            file.WriteFloatString("%s\t\t\tsubwebs {\n", tabs);
            for (int subWeb = 0; subWeb < layer.subWebsOnLayer.Num(); ++subWeb)
                file.WriteFloatString("%s\t\t\t\t\"%s\"\n", tabs,
                    layer.subWebsOnLayer[subWeb].c_str());
            file.WriteFloatString("%s\t\t\t}\n%s\t\t}\n", tabs, tabs);
        }
        file.WriteFloatString("%s\t}\n", tabs);
    }

    file.WriteFloatString("%s\tstates {\n", tabs);
    for (int index = 0; index < states.Num(); ++index)
        file.WriteFloatString("%s\t\tstate \"%s\" {\n%s\t\t}\n", tabs,
            states[index].name.c_str(), tabs);
    file.WriteFloatString("%s\t}\n", tabs);
    if (scalars.Num() > 0) {
        file.WriteFloatString("%s\tscalars {\n", tabs);
        for (int index = 0; index < scalars.Num(); ++index)
            file.WriteFloatString("%s\t\t%s %d\n", tabs,
                scalars[index].name.c_str(),
                (scalars[index].flags & idAnimWebScalar::AWSFLAG_INIT_TO_1) != 0);
        file.WriteFloatString("%s\t}\n", tabs);
    }
    file.WriteFloatString("%s\tsubWebs {\n", tabs);
    for (int subWeb = 0; subWeb < subWebs.Num(); ++subWeb) {
        const idSubWebInfo& info = subWebs[subWeb];
        file.WriteFloatString("%s\t\t// sub-web \"%s\"\n", tabs,
            info.name.c_str());
        file.WriteFloatString("%s\t\tsubWeb \"%s\" {\n", tabs,
            info.name.c_str());
        file.WriteFloatString("%s\t\t\tprops {\n", tabs);
        file.WriteFloatString("%s\t\t\t\tcolor ( %g %g %g %g )\n", tabs,
            info.color.r, info.color.g, info.color.b, info.color.a);
        file.WriteFloatString("%s\t\t\t\thub %d\n", tabs,
            info.isHub ? 1 : 0);
        file.WriteFloatString("%s\t\t\t\tvisible %d\n", tabs,
            info.isVisible ? 1 : 0);
        file.WriteFloatString("%s\t\t\t}\n", tabs);
        for (int node = 0; node < info.nodes.Num(); ++node) {
            const int nodeNumber = info.nodes[node].Get();
            if (nodeNumber < 0 || nodeNumber >= nodes.Num()
                || nodes[nodeNumber] == nullptr) continue;
            idStr nodeIndent(tabs); nodeIndent.Append("\t\t\t");
            nodes[nodeNumber]->Write(this, file, nodeIndent.c_str());
        }
        file.WriteFloatString("%s\t\t}\n", tabs);
    }
    file.WriteFloatString("%s\t}\n%s}\n", tabs, tabs);
}

void idDeclAnimWeb::Composite(idList<const idDeclAnimWeb*, 5>& declarations,
        idDeclAnimWeb* const destination) {
    if (destination == nullptr) return;
    destination->FreeData();
    if (declarations.Num() > 0 && declarations[0] != nullptr)
        destination->settings = declarations[0]->settings;
    destination->settings.isComposite = true;

    for (int declarationIndex = 0; declarationIndex < declarations.Num();
            ++declarationIndex) {
        const idDeclAnimWeb* const source = declarations[declarationIndex];
        if (source == nullptr || source == destination) continue;
        std::vector<modelIndex_t> modelMap(source->models.Num());
        std::vector<stateIndex_t> stateMap(source->states.Num());
        std::vector<subWebIndex_t> subWebMap(source->subWebs.Num());
        std::vector<nodeIndex_t> nodeMap(source->nodes.Num());

        for (int index = 0; index < source->models.Num(); ++index) {
            modelIndex_t mapped = destination->FindModelIndex(source->models[index]);
            if (!mapped.IsValid()) {
                destination->models.Append(source->models[index]);
                mapped = modelIndex_t(static_cast<short>(
                    destination->models.Num() - 1));
            }
            modelMap[index] = mapped;
        }
        for (int index = 0; index < source->states.Num(); ++index) {
            stateIndex_t mapped = destination->GetStateIndexForName(
                source->states[index].name.c_str());
            if (!mapped.IsValid()) {
                destination->states.Append(source->states[index]);
                mapped = stateIndex_t(static_cast<short>(
                    destination->states.Num() - 1));
            }
            stateMap[index] = mapped;
        }
        for (int index = 0; index < source->subWebs.Num(); ++index) {
            subWebIndex_t mapped = destination->AddSubWeb(
                source->subWebs[index].name.c_str());
            idSubWebInfo& target = destination->subWebs[mapped.Get()];
            target.color = source->subWebs[index].color;
            target.isHub = source->subWebs[index].isHub;
            target.isVisible = source->subWebs[index].isVisible;
            target.used = source->subWebs[index].used;
            subWebMap[index] = mapped;
        }
        for (int index = 0; index < source->nodes.Num(); ++index) {
            const idDeclAnimWebNode* const sourceNode = source->nodes[index];
            if (sourceNode == nullptr) continue;
            stateList_t mappedStates;
            mappedStates.numStates = sourceNode->states.numStates;
            for (int state = 0; state < mappedStates.numStates; ++state) {
                const int oldState = sourceNode->states.stateIndex[state].Get();
                mappedStates.stateIndex[state] = oldState >= 0
                    && oldState < static_cast<int>(stateMap.size())
                    ? stateMap[oldState] : stateIndex_t();
            }
            const int oldSubWeb = sourceNode->subWebIndex.Get();
            const subWebIndex_t mappedSubWeb = oldSubWeb >= 0
                && oldSubWeb < static_cast<int>(subWebMap.size())
                ? subWebMap[oldSubWeb] : subWebIndex_t();
            const nodeIndex_t mapped = destination->AddNode(mappedSubWeb,
                mappedStates);
            idDeclAnimWebNode* const targetNode = destination->nodes[mapped.Get()];
            targetNode->animDelta = sourceNode->animDelta;
            targetNode->flags = sourceNode->flags;
            targetNode->customFlags = sourceNode->customFlags;
            targetNode->settings = sourceNode->settings;
            targetNode->modelInfo.Clear();
            for (int model = 0; model < sourceNode->modelInfo.Num(); ++model) {
                idDeclAnimWebNode::idModelInfo info = sourceNode->modelInfo[model];
                const int oldModel = info.modelIndex.Get();
                if (oldModel >= 0 && oldModel < static_cast<int>(modelMap.size()))
                    info.modelIndex = modelMap[oldModel];
                targetNode->modelInfo.Append(info);
            }
            targetNode->edges.Clear();
            nodeMap[index] = mapped;
        }
        for (int index = 0; index < source->nodes.Num(); ++index) {
            const idDeclAnimWebNode* const sourceNode = source->nodes[index];
            if (sourceNode == nullptr || !nodeMap[index].IsValid()) continue;
            idDeclAnimWebNode* const targetNode =
                destination->nodes[nodeMap[index].Get()];
            for (int local = 0; local < sourceNode->edges.Num(); ++local) {
                const int oldEdge = sourceNode->edges[local].Get();
                if (oldEdge < 0 || oldEdge >= source->edges.Num()
                    || oldEdge >= source->edgeCache.Num()) continue;
                const edgeIndex_t newEdge = destination->AllocEdge();
                destination->edges[newEdge.Get()] = source->edges[oldEdge];
                idEdgeCache cache = source->edgeCache[oldEdge];
                const int oldDestination = cache.destNodeIndex.Get();
                cache.destNodeIndex = oldDestination >= 0
                    && oldDestination < static_cast<int>(nodeMap.size())
                    ? nodeMap[oldDestination] : nodeIndex_t();
                const int oldSubWeb = source->edges[oldEdge].destSubWebIndex;
                if (oldSubWeb >= 0 && oldSubWeb < static_cast<int>(subWebMap.size()))
                    destination->edges[newEdge.Get()].destSubWebIndex =
                        subWebMap[oldSubWeb].Get();
                destination->edgeCache[newEdge.Get()] = cache;
                targetNode->edges.Append(newEdge);
            }
        }
        for (int scalar = 0; scalar < source->scalars.Num(); ++scalar) {
            bool found = false;
            for (int existing = 0; existing < destination->scalars.Num();
                    ++existing)
                if (idStr::Icmp(destination->scalars[existing].name.c_str(),
                        source->scalars[scalar].name.c_str()) == 0) {
                    found = true; break;
                }
            if (!found) destination->scalars.Append(source->scalars[scalar]);
        }
    }
}

void idDeclAnimWeb::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    FreeData();
    ++changeId;
    idToken token;
    idList<const idDeclAnimWeb*, 5> compositeDeclarations(16);

    if (!parser->ExpectTokenString("props")
        || !parser->ExpectTokenString("{")) return;
    while (parser->ReadToken(token) != 0) {
        if (idStr::Cmp(token.c_str(), "}") == 0) break;
        const char* const property = token.c_str();
        if (idStr::Cmp(property, "editPos") == 0)
            parser->Parse1DMatrix(3, &settings.editPos.x);
        else if (idStr::Cmp(property, "gridSize") == 0)
            settings.gridSize = parser->ParseInt();
        else if (idStr::Cmp(property, "snapToGrid") == 0)
            settings.snapToGrid = parser->ParseBool();
        else if (idStr::Cmp(property, "showGrid") == 0)
            settings.showGrid = parser->ParseBool();
        else if (idStr::Cmp(property, "alwaysShowIntraSubwebLinks") == 0)
            settings.alwaysShowIntraSubwebLinks = parser->ParseBool();
        else if (idStr::Cmp(property, "alwaysShowNodeProps") == 0)
            settings.alwaysShowNodeProps = parser->ParseBool();
        else if (idStr::Cmp(property, "showAbbreviatedNodeProps") == 0)
            settings.showAbbreviatedNodeProps = parser->ParseBool();
        else if (idStr::Cmp(property, "showIncomingLinks") == 0)
            settings.showIncomingLinks = parser->ParseBool();
        else if (idStr::Cmp(property, "defaultBlendOutWindow") == 0)
            settings.defaultBlendOutWindow = parser->ParseInt();
        else if (idStr::Cmp(property, "defaultBlendDuration") == 0)
            settings.defaultBlendDuration = parser->ParseInt();
        else if (idStr::Cmp(property, "mergeModels") == 0)
            settings.mergeModels = parser->ParseBool();
        else if (idStr::Cmp(property, "subWebBlend") == 0) {
            if (!ReadQuotedOrName(*parser, token)) return;
            settings.subWebBlend = SUBWEBBLEND_MAX;
            for (int index = 0; index < SUBWEBBLEND_MAX; ++index)
                if (idStr::Icmp(token.c_str(), subWebBlendNames[index]) == 0)
                    settings.subWebBlend = static_cast<subWebBlend_t>(index);
            if (settings.subWebBlend == SUBWEBBLEND_MAX)
                parser->Error("Unknown subWebBlend type: '%s'", token.c_str());
        } else if (idStr::Cmp(property, "models") == 0) {
            if (!parser->ExpectTokenString("{")) return;
            while (parser->ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0) {
                const idDeclMD6* const model =
                    Decls_FindMD6Declaration(token.c_str());
                if (model != nullptr) models.Append(model);
                else parser->Error("Could not find model '%s' in 'models' block.",
                    token.c_str());
            }
        } else if (idStr::Cmp(property, "editorModels") == 0) {
            if (!parser->ExpectTokenString("{")) return;
            while (parser->ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0)
                editorModels.Append(idAtomicString(token.c_str()));
        } else if (idStr::Cmp(property, "composite") == 0) {
            if (!parser->ExpectTokenString("{")) return;
            while (parser->ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0) {
                const idDeclAnimWeb* const source = static_cast<const idDeclAnimWeb*>(
                    resourceList.FindWithInheritance(token.c_str(), false));
                if (source != nullptr) compositeDeclarations.Append(source);
                else parser->Error("Could not find animweb decl: '%s'",
                    token.c_str());
            }
            settings.isComposite = true;
        } else {
            bool found = false;
            for (int index = 0; index < NP_MAX; ++index) {
                if (idStr::Cmp(property, nodePropNames[index]) == 0) {
                    settings.nodeProps[index] = parser->ParseBool();
                    found = true;
                    break;
                }
            }
            if (!found && idStr::Cmp(property, "showWeakRefs") == 0) {
                parser->ParseBool();
                found = true;
            }
            if (!found)
                parser->Error("Unknown token '%s' in 'props' block.", property);
        }
    }
    if (settings.isComposite) {
        Composite(compositeDeclarations, this);
        return;
    }

    if (parser->CheckTokenString("layers") != 0) {
        if (!parser->ExpectTokenString("{")) return;
        while (parser->ReadToken(token) != 0
                && idStr::Cmp(token.c_str(), "}") != 0) {
            if (idStr::Cmp(token.c_str(), "layer") != 0) {
                parser->Error("Unknown token '%s' in 'layers' block.",
                    token.c_str());
                continue;
            }
            if (!ReadQuotedOrName(*parser, token)) return;
            idLayerInfo* const layer = layers.Alloc();
            if (layer == nullptr) return;
            layer->name.Set(token.c_str());
            if (!parser->ExpectTokenString("{")) return;
            while (parser->ReadToken(token) != 0
                    && idStr::Cmp(token.c_str(), "}") != 0) {
                if (idStr::Cmp(token.c_str(), "visible") == 0)
                    layer->isVisible = parser->ParseBool();
                else if (idStr::Cmp(token.c_str(), "subwebs") == 0) {
                    if (!parser->ExpectTokenString("{")) return;
                    while (parser->ReadToken(token) != 0
                            && idStr::Cmp(token.c_str(), "}") != 0)
                        layer->subWebsOnLayer.Append(
                            idAtomicString(token.c_str()));
                } else parser->Error("Unknown token '%s' in 'layer' block.",
                    token.c_str());
            }
        }
    }

    if (!parser->ExpectTokenString("states")
        || !parser->ExpectTokenString("{")) return;
    while (parser->ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        if (idStr::Cmp(token.c_str(), "state") != 0) {
            parser->Error("Unknown token '%s' in 'states' block.", token.c_str());
            continue;
        }
        if (!ReadQuotedOrName(*parser, token)) return;
        idStateInfo* const state = states.Alloc();
        if (state == nullptr) return;
        state->name.Set(token.c_str());
        if (!parser->ExpectTokenString("{")) return;
        while (parser->ReadToken(token) != 0
                && idStr::Cmp(token.c_str(), "}") != 0)
            if (idStr::Cmp(token.c_str(), "destination") != 0)
                parser->Error("Unknown token '%s' in 'state' block.",
                    token.c_str());
    }

    if (parser->CheckTokenString("scalars") != 0) {
        if (!parser->ExpectTokenString("{")) return;
        while (parser->ReadToken(token) != 0
                && idStr::Cmp(token.c_str(), "}") != 0) {
            idAnimWebScalar* const scalar = scalars.Alloc();
            if (scalar == nullptr) return;
            scalar->Init(token.c_str(), static_cast<unsigned char>(
                parser->ParseInt() != 0), nullptr);
        }
    }

    if (!parser->ExpectTokenString("subWebs")
        || !parser->ExpectTokenString("{")) return;
    while (parser->ReadToken(token) != 0
            && idStr::Cmp(token.c_str(), "}") != 0) {
        if (idStr::Cmp(token.c_str(), "subWeb") != 0) {
            parser->Error("Unknown token '%s' in 'subWebs' block.",
                token.c_str());
            continue;
        }
        if (!ReadQuotedOrName(*parser, token)) return;
        const idStr subWebName(token.c_str());
        const subWebIndex_t subWeb = AddSubWeb(subWebName.c_str());
        if (!parser->ExpectTokenString("{")) return;
        while (parser->ReadToken(token) != 0
                && idStr::Cmp(token.c_str(), "}") != 0) {
            if (idStr::Cmp(token.c_str(), "props") == 0) {
                if (!parser->ExpectTokenString("{")) return;
                while (parser->ReadToken(token) != 0
                        && idStr::Cmp(token.c_str(), "}") != 0) {
                    if (idStr::Cmp(token.c_str(), "color") == 0)
                        parser->Parse1DMatrix(4, &subWebs[subWeb.Get()].color.r);
                    else if (idStr::Cmp(token.c_str(), "hub") == 0)
                        subWebs[subWeb.Get()].isHub = parser->ParseBool();
                    else if (idStr::Cmp(token.c_str(), "visible") == 0)
                        subWebs[subWeb.Get()].isVisible = parser->ParseBool();
                    else parser->Error(
                        "Unexpected token '%s' in subWeb 'props' block.",
                        token.c_str());
                }
            } else if (idStr::Cmp(token.c_str(), "node") == 0) {
                stateList_t stateList;
                while (parser->ReadToken(token) != 0
                        && idStr::Cmp(token.c_str(), "{") != 0) {
                    if (stateList.numStates >= 4) {
                        parser->Error("Node contains too many states.");
                        return;
                    }
                    stateIndex_t state = GetStateIndexForName(token.c_str());
                    if (!state.IsValid()) {
                        idStateInfo* const newState = states.Alloc();
                        if (newState == nullptr) return;
                        newState->name.Set(token.c_str());
                        state = stateIndex_t(static_cast<short>(states.Num() - 1));
                    }
                    stateList.stateIndex[stateList.numStates++] = state;
                }
                const nodeIndex_t node = AddNode(subWeb, stateList);
                if (node.IsValid()) nodes[node.Get()]->Parse(this, *parser);
            } else parser->Error("Unknown token '%s' in 'subWeb' block.",
                token.c_str());
        }
    }

    if (expandSubWebLinks)
        for (int index = 0; index < nodes.Num(); ++index)
            if (nodes[index] != nullptr) nodes[index]->CreateSubWebEdges(this);

    delete[] edgeIndexCache;
    edgeIndexCacheSize = static_cast<unsigned int>(edgeCache.Num()
        * sizeof(edgeIndex_t));
    edgeIndexCache = edgeCache.Num() > 0
        ? new edgeIndex_t[edgeCache.Num()] : nullptr;
    nodeCache.SetNum(nodes.Num());
    edgeIndex_t* cursor = edgeIndexCache;
    for (int index = 0; index < nodes.Num(); ++index) {
        idNodeCache& cache = nodeCache[index];
        const idDeclAnimWebNode* const node = nodes[index];
        cache.numEdges = node != nullptr
            ? static_cast<std::uint16_t>(node->edges.Num()) : 0;
        cache.edgeIndexOffset = cursor != nullptr
            ? static_cast<unsigned int>(cursor - edgeIndexCache) : 0;
        cache.flags = node != nullptr ? node->flags : 0;
        if (node != nullptr)
            for (int edge = 0; edge < node->edges.Num(); ++edge)
                *cursor++ = node->edges[edge];
    }
}

int Decls_AnimWebNodeSubWebIndex(const idDeclAnimWebNode* node) {
    return node != nullptr ? node->subWebIndex.Get() : -1;
}

const char* Decls_AnimWebSubWebName(const idDeclAnimWeb* declaration,
        const int subWebIndex) {
    return declaration != nullptr
        ? declaration->GetSubWebName(idDeclAnimWeb::subWebIndex_t(
            static_cast<short>(subWebIndex))) : "";
}

const char* Decls_AnimWebNodeStateName(
        const idDeclAnimWeb* declaration, const int nodeIndex) {
    if (declaration == nullptr || nodeIndex < 0
        || nodeIndex >= declaration->nodes.Num()
        || declaration->nodes[nodeIndex] == nullptr
        || declaration->nodes[nodeIndex]->states.numStates == 0) return "";
    return declaration->GetStateName(
        declaration->nodes[nodeIndex]->states.stateIndex[0]);
}

int Decls_AnimWebNodeSubWebIndex(const idDeclAnimWeb* declaration,
        const int nodeIndex) {
    return declaration != nullptr && nodeIndex >= 0
        && nodeIndex < declaration->nodes.Num()
        && declaration->nodes[nodeIndex] != nullptr
        ? declaration->nodes[nodeIndex]->subWebIndex.Get() : -1;
}

int Decls_AnimWebAddNode(idDeclAnimWeb* declaration,
        const char* subWebName, const char* stateName,
        int& subWebIndex, int& stateIndex) {
    if (declaration == nullptr) return -1;
    idDeclAnimWeb::nodeIndex_t node;
    idDeclAnimWeb::subWebIndex_t subWeb;
    idDeclAnimWeb::stateIndex_t state;
    declaration->AddNode(subWebName, stateName, node, subWeb, state);
    subWebIndex = subWeb.Get();
    stateIndex = state.Get();
    return node.Get();
}

int Decls_AnimWebAddSubWeb(idDeclAnimWeb* declaration,
        const char* subWebName) {
    return declaration != nullptr
        ? declaration->AddSubWeb(subWebName).Get() : -1;
}
