#include "game/decls/declgraphtest.h"

idColor idDeclTypeInfoGraph::GetNodeColor(
        const idTypeInfoGraphNode* node) const {
    return node != nullptr ? node->GetColor()
        : idColor(1.0f, 1.0f, 1.0f, 1.0f);
}

idGraphItemFactory<idTypeInfoSubGraph>&
idDeclTypeInfoGraph::GetSubGraphFactory() {
    static idGraphItemFactory<idTypeInfoSubGraph> factory;
    return factory;
}

idGraphItemFactory<idTypeInfoGraphNode>&
idDeclTypeInfoGraph::GetGraphNodeFactory() {
    static idGraphItemFactory<idTypeInfoGraphNode> factory;
    return factory;
}

idGraphItemFactory<idTypeInfoGraphLink>&
idDeclTypeInfoGraph::GetGraphLinkFactory() {
    static idGraphItemFactory<idTypeInfoGraphLink> factory;
    return factory;
}

// EA 0x82BBE880
void idDeclTypeInfoGraphTest::ToggleHighlightDeadEndLinks(
        idDeclTypeInfoGraph* graph) {
    auto* testGraph = dynamic_cast<idDeclTypeInfoGraphTest*>(graph);
    if (testGraph != nullptr) {
        testGraph->highlightDeadEndNodes =
            !testGraph->highlightDeadEndNodes;
    }
}

// EA 0x82BBEC30
void idDeclTypeInfoGraphTest::DisableLinks(idDeclTypeInfoGraph*,
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks) {
    for (int index = 0; index < selectedLinks.Num(); ++index) {
        auto* link = dynamic_cast<idTypeInfoGraphLinkTest*>(
            selectedLinks[index]);
        if (link != nullptr) link->enabled = false;
    }
}

// EA 0x82BBECB0
void idDeclTypeInfoGraphTest::EnableLinks(idDeclTypeInfoGraph*,
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks) {
    for (int index = 0; index < selectedLinks.Num(); ++index) {
        auto* link = dynamic_cast<idTypeInfoGraphLinkTest*>(
            selectedLinks[index]);
        if (link != nullptr) link->enabled = true;
    }
}

// EA 0x82BBF298
idColor idDeclTypeInfoGraphTest::GetNodeColor(
        const idTypeInfoGraphNode* node) const {
    idColor color = idDeclTypeInfoGraph::GetNodeColor(node);
    if (highlightDeadEndNodes && node != nullptr
            && node->outgoing.Num() == 0) {
        color.r = 1.0f - color.r;
        color.g = 1.0f - color.g;
        color.b = 1.0f - color.b;
    }
    return color;
}

// EA 0x82BC0120
idGraphItemFactory<idTypeInfoSubGraph>&
idDeclTypeInfoGraphTest::GetSubGraphFactory() {
    static idGraphItemFactory<idTypeInfoSubGraph> factory;
    return factory;
}

// EA 0x82BC01C0
idGraphItemFactory<idTypeInfoGraphNode>&
idDeclTypeInfoGraphTest::GetGraphNodeFactory() {
    static idGraphItemFactory<idTypeInfoGraphNode> factory;
    return factory;
}

// EA 0x82BC0260
idGraphItemFactory<idTypeInfoGraphLink>&
idDeclTypeInfoGraphTest::GetGraphLinkFactory() {
    static idGraphItemFactory<idTypeInfoGraphLink> factory;
    return factory;
}

// EA 0x82BC02F8
void idDeclTypeInfoGraphTest::GetMainContextMenuItems(
        idList<idContextMenuItemMain, 5>& menuItems) const {
    idContextMenuItemMain* item = menuItems.Alloc();
    if (item == nullptr) return;
    item->description = "Highlight Deadend Nodes";
    item->isChecked = highlightDeadEndNodes;
    item->callback = ToggleHighlightDeadEndLinks;
}

// EA 0x82BC0358
void idDeclTypeInfoGraphSingleTypeTest::GetLinkContextMenuItems(
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks,
        idList<idContextMenuItemLink, 5>& menuItems) const {
    bool hasEnabled = false;
    bool hasDisabled = false;
    for (int index = 0; index < selectedLinks.Num(); ++index) {
        const auto* link = dynamic_cast<const idTypeInfoGraphLinkTest*>(
            selectedLinks[index]);
        if (link == nullptr) continue;
        hasEnabled |= link->enabled;
        hasDisabled |= !link->enabled;
    }
    idContextMenuItemLink* enable = menuItems.Alloc();
    if (enable != nullptr) {
        enable->description = selectedLinks.Num() > 1
            ? "Enable Links" : "Enable Link";
        enable->enabled = hasDisabled;
        enable->callback = EnableLinks;
    }
    idContextMenuItemLink* disable = menuItems.Alloc();
    if (disable != nullptr) {
        disable->description = selectedLinks.Num() > 1
            ? "Disable Links" : "Disable Link";
        disable->enabled = hasEnabled;
        disable->callback = DisableLinks;
    }
}

// EA 0x82BC0500
idGraphItemFactory<idTypeInfoSubGraph>&
idDeclTypeInfoGraphSingleTypeTest::GetSubGraphFactory() {
    static idGraphItemFactory<idTypeInfoSubGraph> factory;
    return factory;
}

// EA 0x82BC05A0
idGraphItemFactory<idTypeInfoGraphNode>&
idDeclTypeInfoGraphSingleTypeTest::GetGraphNodeFactory() {
    static idGraphItemFactory<idTypeInfoGraphNode> factory;
    return factory;
}

// EA 0x82BC0640
idGraphItemFactory<idTypeInfoGraphLink>&
idDeclTypeInfoGraphSingleTypeTest::GetGraphLinkFactory() {
    static idGraphItemFactory<idTypeInfoGraphLink> factory;
    return factory;
}

// EA 0x82BC0B90
bool idDeclTypeInfoGraphTest::RegisterGraphTypes() {
    GetSubGraphFactory().Register("idTypeInfoSubGraphTest",
        "basic subgraph");
    GetSubGraphFactory().Register("idTypeInfoSubGraphTest2",
        "white subgraph");
    GetGraphNodeFactory().Register("idTypeInfoGraphNodeTest",
        "basic node");
    GetGraphNodeFactory().Register("idTypeInfoGraphNodeTest2",
        "red node");
    GetGraphLinkFactory().Register("idTypeInfoGraphLinkTest",
        "basic link");
    GetGraphLinkFactory().Register("idTypeInfoGraphLinkTest2",
        "pink link");
    idDeclTypeInfoGraph::GetSubGraphFactory().Register(
        "idTypeInfoSubGraphTest", "basic subgraph");
    idDeclTypeInfoGraph::GetSubGraphFactory().Register(
        "idTypeInfoSubGraphTest2", "white subgraph");
    idDeclTypeInfoGraph::GetGraphNodeFactory().Register(
        "idTypeInfoGraphNodeTest", "basic node");
    idDeclTypeInfoGraph::GetGraphNodeFactory().Register(
        "idTypeInfoGraphNodeTest2", "red node");
    idDeclTypeInfoGraph::GetGraphLinkFactory().Register(
        "idTypeInfoGraphLinkTest", "basic link");
    idDeclTypeInfoGraph::GetGraphLinkFactory().Register(
        "idTypeInfoGraphLinkTest2", "pink link");
    return true;
}

// EA 0x82BC0E40
bool idDeclTypeInfoGraphSingleTypeTest::RegisterGraphTypes() {
    GetSubGraphFactory().Register("idTypeInfoSubGraphTest",
        "idTypeInfoSubGraphTest");
    GetGraphNodeFactory().Register("idTypeInfoGraphNodeTest",
        "idTypeInfoGraphNodeTest");
    GetGraphLinkFactory().Register("idTypeInfoGraphLinkTest",
        "idTypeInfoGraphLinkTest");
    idDeclTypeInfoGraph::GetSubGraphFactory().Register(
        "idTypeInfoSubGraphTest", "idTypeInfoSubGraphTest");
    idDeclTypeInfoGraph::GetGraphNodeFactory().Register(
        "idTypeInfoGraphNodeTest", "idTypeInfoGraphNodeTest");
    idDeclTypeInfoGraph::GetGraphLinkFactory().Register(
        "idTypeInfoGraphLinkTest", "idTypeInfoGraphLinkTest");
    return true;
}

