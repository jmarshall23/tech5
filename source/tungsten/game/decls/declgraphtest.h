#pragma once

#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <string>
#include <vector>

template<typename itemType>
class idGraphItemFactory {
public:
    struct registration_t {
        std::string className;
        std::string displayName;
    };

    void Register(const char* className, const char* displayName) {
        for (const registration_t& item : registrations) {
            if (item.className == className) return;
        }
        registrations.push_back({className, displayName});
    }
    int Num() const { return static_cast<int>(registrations.size()); }
    const registration_t& operator[](int index) const {
        return registrations[static_cast<std::size_t>(index)];
    }
private:
    std::vector<registration_t> registrations;
};

class idTypeInfoGraphLink {
public:
    virtual ~idTypeInfoGraphLink() = default;
};

class idTypeInfoGraphLinkTest : public idTypeInfoGraphLink {
public:
    bool enabled{true};
};

class idTypeInfoGraphLinkTest2 : public idTypeInfoGraphLinkTest {};

class idTypeInfoGraphNode {
public:
    virtual ~idTypeInfoGraphNode() = default;
    virtual idColor GetColor() const { return color; }

    idColor color{idColor(1.0f, 1.0f, 1.0f, 1.0f)};
    idList<idTypeInfoGraphLink*, 5> outgoing;
};

class idTypeInfoGraphNodeTest : public idTypeInfoGraphNode {};
class idTypeInfoGraphNodeTest2 : public idTypeInfoGraphNodeTest {};
class idTypeInfoSubGraph { public: virtual ~idTypeInfoSubGraph() = default; };
class idTypeInfoSubGraphTest : public idTypeInfoSubGraph {};
class idTypeInfoSubGraphTest2 : public idTypeInfoSubGraphTest {};

class idDeclTypeInfoGraph {
public:
    struct idContextMenuItemMain {
        idStr description;
        bool isChecked{false};
        void (*callback)(idDeclTypeInfoGraph*){nullptr};
    };
    struct idContextMenuItemLink {
        idStr description;
        bool enabled{false};
        void (*callback)(idDeclTypeInfoGraph*,
            const idList<idTypeInfoGraphLink*, 5>&){nullptr};
    };

    virtual ~idDeclTypeInfoGraph() = default;
    virtual idColor GetNodeColor(const idTypeInfoGraphNode* node) const;
    virtual void GetMainContextMenuItems(
        idList<idContextMenuItemMain, 5>&) const {}
    virtual void GetLinkContextMenuItems(
        const idList<idTypeInfoGraphLink*, 5>&,
        idList<idContextMenuItemLink, 5>&) const {}

    static idGraphItemFactory<idTypeInfoSubGraph>& GetSubGraphFactory();
    static idGraphItemFactory<idTypeInfoGraphNode>& GetGraphNodeFactory();
    static idGraphItemFactory<idTypeInfoGraphLink>& GetGraphLinkFactory();
};

class idDeclTypeInfoGraphTest : public idDeclTypeInfoGraph {
public:
    static void ToggleHighlightDeadEndLinks(idDeclTypeInfoGraph* graph);
    static void DisableLinks(idDeclTypeInfoGraph* graph,
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks);
    static void EnableLinks(idDeclTypeInfoGraph* graph,
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks);
    idColor GetNodeColor(const idTypeInfoGraphNode* node) const override;
    static idGraphItemFactory<idTypeInfoSubGraph>& GetSubGraphFactory();
    static idGraphItemFactory<idTypeInfoGraphNode>& GetGraphNodeFactory();
    static idGraphItemFactory<idTypeInfoGraphLink>& GetGraphLinkFactory();
    void GetMainContextMenuItems(
        idList<idContextMenuItemMain, 5>& menuItems) const override;
    static bool RegisterGraphTypes();

    bool highlightDeadEndNodes{false};
};

class idDeclTypeInfoGraphSingleTypeTest : public idDeclTypeInfoGraphTest {
public:
    void GetLinkContextMenuItems(
        const idList<idTypeInfoGraphLink*, 5>& selectedLinks,
        idList<idContextMenuItemLink, 5>& menuItems) const override;
    static idGraphItemFactory<idTypeInfoSubGraph>& GetSubGraphFactory();
    static idGraphItemFactory<idTypeInfoGraphNode>& GetGraphNodeFactory();
    static idGraphItemFactory<idTypeInfoGraphLink>& GetGraphLinkFactory();
    static bool RegisterGraphTypes();
};
