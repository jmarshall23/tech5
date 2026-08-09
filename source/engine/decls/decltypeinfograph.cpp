#include "decls/decltypeinfograph.h"

#include "idlib/text/parser.h"

idTypeInfoGraphItem::~idTypeInfoGraphItem() = default;

void idTypeInfoGraphItem::GetDisplayName(idStr& displayName) const {
    displayName = name.c_str();
}

idTypeInfoSubGraph::idTypeInfoSubGraph()
    : subnodes(16), position(0.0f, 0.0f) {
}

idTypeInfoSubGraph::~idTypeInfoSubGraph() = default;

idColor idTypeInfoSubGraph::GetColor() const {
    return idColor::colorMdGrey;
}

idColor idTypeInfoGraphNode::GetColor() const {
    return idColor::colorLtGrey;
}

void idTypeInfoGraphNode::GetInfo(idStr& info,
        bool& showSelected) const {
    info.Clear();
    showSelected = false;
}

idColor idTypeInfoGraphLink::GetColor() const {
    return idColor::colorWhite;
}

void idTypeInfoGraphLink::GetDisplayName(idStr& displayName) const {
    displayName.Clear();
}

idDeclTypeInfoGraph::idDeclTypeInfoGraph()
    : subGraphs(16), nodes(16), links(16) {
}

idDeclTypeInfoGraph::~idDeclTypeInfoGraph() {
    for (int index = 0; index < subGraphs.Num(); ++index)
        delete subGraphs[index];
    for (int index = 0; index < nodes.Num(); ++index)
        delete nodes[index];
    for (int index = 0; index < links.Num(); ++index)
        delete links[index];
    subGraphs.ClearFree();
    nodes.ClearFree();
    links.ClearFree();
}

void idDeclTypeInfoGraph::Parse(idParser* const parser) {
    idDeclTypeInfo::Parse(parser);
    if (resourceError == nullptr) OnDeclParsed();
}

idGraphItemFactory<idTypeInfoSubGraph>*
idDeclTypeInfoGraph::GetMySubGraphFactory() {
    return GetSubGraphFactory();
}

idGraphItemFactory<idTypeInfoGraphNode>*
idDeclTypeInfoGraph::GetMyGraphNodeFactory() {
    return GetGraphNodeFactory();
}

idGraphItemFactory<idTypeInfoGraphLink>*
idDeclTypeInfoGraph::GetMyGraphLinkFactory() {
    return GetGraphLinkFactory();
}

bool idDeclTypeInfoGraph::CanCreateSubGraphs() const { return true; }
bool idDeclTypeInfoGraph::CanCreateNodesOutsideOfSubGraphs() const {
    return true;
}
bool idDeclTypeInfoGraph::AllowMultipleLinksBetweenNodes() const {
    return true;
}
bool idDeclTypeInfoGraph::AllowLinkBetweenNodes(int, int) const {
    return true;
}
void idDeclTypeInfoGraph::OnDeclParsed() {}
void idDeclTypeInfoGraph::OnCreateLink(idTypeInfoGraphLink*) {}
void idDeclTypeInfoGraph::OnDeleteLink(idTypeInfoGraphLink*) {}

idColor idDeclTypeInfoGraph::GetSubGraphColor(
        const idTypeInfoSubGraph* const subGraph) const {
    return subGraph != nullptr ? subGraph->GetColor() : idColor::colorBlack;
}

idColor idDeclTypeInfoGraph::GetNodeColor(
        const idTypeInfoGraphNode* const node) const {
    return node != nullptr ? node->GetColor() : idColor::colorBlack;
}

idColor idDeclTypeInfoGraph::GetLinkColor(
        const idTypeInfoGraphLink* const link) const {
    return link != nullptr ? link->GetColor() : idColor::colorBlack;
}

void idDeclTypeInfoGraph::GetNodeInfo(const idTypeInfoGraphNode* const node,
        idStr& info, bool& showSelected) const {
    if (node != nullptr) node->GetInfo(info, showSelected);
}

void idDeclTypeInfoGraph::GetMainContextMenuItems(
        idList<idContextMenuItemMain, 5>& items) const { items.Clear(); }
void idDeclTypeInfoGraph::GetSubGraphContextMenuItems(
        const idList<idTypeInfoSubGraph*, 5>&,
        idList<idContextMenuItemSubGraph, 5>& items) const { items.Clear(); }
void idDeclTypeInfoGraph::GetNodeContextMenuItems(
        const idList<idTypeInfoGraphNode*, 5>&,
        idList<idContextMenuItemNode, 5>& items) const { items.Clear(); }
void idDeclTypeInfoGraph::GetLinkContextMenuItems(
        const idList<idTypeInfoGraphLink*, 5>&,
        idList<idContextMenuItemLink, 5>& items) const { items.Clear(); }

void idDeclTypeInfoGraph::GetLinksFrom(const idTypeInfoGraphNode* const node,
        idList<const idTypeInfoGraphLink*, 5>& linksOut) const {
    if (node == nullptr) return;
    for (int index = 0; index < links.Num(); ++index) {
        const idTypeInfoGraphLink* const link = links[index];
        if (link == nullptr || link->startNodeIndex < 0
            || link->startNodeIndex >= nodes.Num()) continue;
        if (nodes[link->startNodeIndex] == node) linksOut.Append(link);
    }
}

idGraphItemFactory<idTypeInfoSubGraph>*
idDeclTypeInfoGraph::GetSubGraphFactory() {
    static idGraphItemFactory<idTypeInfoSubGraph> factory;
    return &factory;
}

idGraphItemFactory<idTypeInfoGraphNode>*
idDeclTypeInfoGraph::GetGraphNodeFactory() {
    static idGraphItemFactory<idTypeInfoGraphNode> factory;
    return &factory;
}

idGraphItemFactory<idTypeInfoGraphLink>*
idDeclTypeInfoGraph::GetGraphLinkFactory() {
    static idGraphItemFactory<idTypeInfoGraphLink> factory;
    return &factory;
}
