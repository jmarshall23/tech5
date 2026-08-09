#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"
#include "idlib/text/str.h"

#include <cstring>

class idDeclFX;

struct idGraphItemType {
    idAtomicString className;
    idAtomicString displayedName;
};

template<class itemType>
class idGraphItemFactory {
public:
    struct idTypeCreationPair {
        idGraphItemType type;
        itemType* (*creationFunction)();
    };

    idGraphItemFactory() : registry(16) {}
    virtual ~idGraphItemFactory() = default;

    itemType* Create(const char* itemClassName) const {
        if (itemClassName == nullptr) return nullptr;
        for (int index = 0; index < registry.Num(); ++index) {
            const idTypeCreationPair& entry = registry[index];
            if (std::strcmp(entry.type.className.c_str(), itemClassName) == 0) {
                itemType* const item = entry.creationFunction != nullptr
                    ? entry.creationFunction() : nullptr;
                if (item != nullptr) item->className.Set(itemClassName);
                return item;
            }
        }
        return nullptr;
    }

    idList<idTypeCreationPair, 87> registry;
};

class idTypeInfoGraphItem {
public:
    idTypeInfoGraphItem() : name(""), className("") {}
    virtual ~idTypeInfoGraphItem();
    virtual idColor GetColor() const = 0;
    virtual void GetDisplayName(idStr& displayName) const;

    idAtomicString name;
    idAtomicString className;
};

class idTypeInfoSubGraph : public idTypeInfoGraphItem {
public:
    idTypeInfoSubGraph();
    ~idTypeInfoSubGraph() override;
    idColor GetColor() const override;

    idList<int, 5> subnodes;
    idVec2 position;
};

class idTypeInfoGraphNode : public idTypeInfoGraphItem {
public:
    idTypeInfoGraphNode() : position(0.0f, 0.0f) {}
    idColor GetColor() const override;
    virtual void GetInfo(idStr& info, bool& showSelected) const;

    idVec2 position;
};

class idTypeInfoGraphLink : public idTypeInfoGraphItem {
public:
    idTypeInfoGraphLink() : startNodeIndex(-1), endNodeIndex(-1) {}
    idColor GetColor() const override;
    void GetDisplayName(idStr& displayName) const override;

    int startNodeIndex;
    int endNodeIndex;
};

class idDeclTypeInfoGraph : public idDeclTypeInfo {
public:
    class idContextMenuItemBase {
    public:
        idContextMenuItemBase()
            : isEnabled(true), isChecked(false) {}
        virtual ~idContextMenuItemBase() = default;
        idStr description;
        bool isEnabled;
        bool isChecked;
    };

    class idContextMenuItemMain : public idContextMenuItemBase {
    public:
        idContextMenuItemMain() : callback(nullptr) {}
        void (*callback)(idDeclTypeInfoGraph*);
    };
    class idContextMenuItemSubGraph : public idContextMenuItemBase {
    public:
        idContextMenuItemSubGraph() : callback(nullptr) {}
        void (*callback)(idDeclTypeInfoGraph*,
            const idList<idTypeInfoSubGraph*, 5>*);
    };
    class idContextMenuItemNode : public idContextMenuItemBase {
    public:
        idContextMenuItemNode() : callback(nullptr) {}
        void (*callback)(idDeclTypeInfoGraph*,
            const idList<idTypeInfoGraphNode*, 5>*);
    };
    class idContextMenuItemLink : public idContextMenuItemBase {
    public:
        idContextMenuItemLink() : callback(nullptr) {}
        void (*callback)(idDeclTypeInfoGraph*,
            const idList<idTypeInfoGraphLink*, 5>*);
    };

    idDeclTypeInfoGraph();
    ~idDeclTypeInfoGraph() override;
    void Parse(idParser* parser) override;

    virtual idGraphItemFactory<idTypeInfoSubGraph>* GetMySubGraphFactory();
    virtual idGraphItemFactory<idTypeInfoGraphNode>* GetMyGraphNodeFactory();
    virtual idGraphItemFactory<idTypeInfoGraphLink>* GetMyGraphLinkFactory();
    virtual bool CanCreateSubGraphs() const;
    virtual bool CanCreateNodesOutsideOfSubGraphs() const;
    virtual bool AllowMultipleLinksBetweenNodes() const;
    virtual bool AllowLinkBetweenNodes(int startNodeIndex,
        int endNodeIndex) const;
    virtual void OnDeclParsed();
    virtual void OnCreateLink(idTypeInfoGraphLink* link);
    virtual void OnDeleteLink(idTypeInfoGraphLink* link);
    virtual idColor GetSubGraphColor(const idTypeInfoSubGraph* subGraph) const;
    virtual idColor GetNodeColor(const idTypeInfoGraphNode* node) const;
    virtual idColor GetLinkColor(const idTypeInfoGraphLink* link) const;
    virtual void GetNodeInfo(const idTypeInfoGraphNode* node, idStr& info,
        bool& showSelected) const;
    virtual void GetMainContextMenuItems(
        idList<idContextMenuItemMain, 5>& items) const;
    virtual void GetSubGraphContextMenuItems(
        const idList<idTypeInfoSubGraph*, 5>& selection,
        idList<idContextMenuItemSubGraph, 5>& items) const;
    virtual void GetNodeContextMenuItems(
        const idList<idTypeInfoGraphNode*, 5>& selection,
        idList<idContextMenuItemNode, 5>& items) const;
    virtual void GetLinkContextMenuItems(
        const idList<idTypeInfoGraphLink*, 5>& selection,
        idList<idContextMenuItemLink, 5>& items) const;

    void GetLinksFrom(const idTypeInfoGraphNode* node,
        idList<const idTypeInfoGraphLink*, 5>& linksOut) const;

    static idGraphItemFactory<idTypeInfoSubGraph>* GetSubGraphFactory();
    static idGraphItemFactory<idTypeInfoGraphNode>* GetGraphNodeFactory();
    static idGraphItemFactory<idTypeInfoGraphLink>* GetGraphLinkFactory();

    idList<idTypeInfoSubGraph*, 5> subGraphs;
    idList<idTypeInfoGraphNode*, 5> nodes;
    idList<idTypeInfoGraphLink*, 5> links;
};

class idDeclTypeInfoGraphTest : public idDeclTypeInfoGraph {
public:
    idDeclTypeInfoGraphTest()
        : highlightDeadEndNodes(false), someOtherBool(false), fxDecl(nullptr) {}
    virtual bool HighlightDeadEndNodes() const { return highlightDeadEndNodes; }
    virtual void SetHighlightDeadEndNodes(bool enabled) {
        highlightDeadEndNodes = enabled;
    }

    bool highlightDeadEndNodes;
    bool someOtherBool;
    idDeclFX* fxDecl;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTypeInfoGraphItem) == 12,
    "Recovered graph-item ABI changed");
static_assert(sizeof(idTypeInfoSubGraph) == 36,
    "Recovered subgraph ABI changed");
static_assert(sizeof(idTypeInfoGraphNode) == 20,
    "Recovered graph-node ABI changed");
static_assert(sizeof(idTypeInfoGraphLink) == 20,
    "Recovered graph-link ABI changed");
static_assert(sizeof(idDeclTypeInfoGraph) == 112,
    "Recovered type-info graph ABI changed");
#endif
