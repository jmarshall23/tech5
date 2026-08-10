#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idRenderModelGui;
class idFont;
class idLexer;
struct sysEvent_t;

class idDebugMenu {
public:
    virtual ~idDebugMenu() = default;
    virtual bool Init() = 0;
    virtual bool IsActive() = 0;
    virtual bool HandleGuiEvent(const sysEvent_t*) = 0;
    virtual idRenderModelGui* Render() = 0;
};

class idDebugMenuLocal : public idDebugMenu {
public:
    struct CEntry {
        CEntry();
        CEntry& operator=(const CEntry& other);

        bool valid;
        int shortcut;
        idStr title;
        idStr description;
        idStr cmd;
        idStr entityValid;
        idStr entityDescr;
        idVec4 color;
    };
    class CGroup { public: idStr title; idList<CEntry, 3> items; };

    idDebugMenuLocal();
    ~idDebugMenuLocal() override;
    bool Init() override;
    bool IsActive() override;
    bool HandleGuiEvent(const sysEvent_t*) override;
    idRenderModelGui* Render() override;

    bool modKeyPressed;
    int selectedGroup;
    int selectedItem;
    int startItem;
    idRenderModelGui* guiModel;
    const idFont* font;
    idList<CGroup, 3> groups;

private:
    static bool idLexerJSON_ExpectLiteralToken(idLexer& src,
        const char* token);
    static bool idLexerJSON_ExpectString(idLexer& src,
        const char* string);
    bool ReadEntry(idLexer& src, CEntry& entry);
    bool ReadEntries(idLexer& src, CGroup& group);
    bool ReadGroup(idLexer& src);
    bool LoadMenu();
};

extern idDebugMenuLocal debugMenuLocal;
extern idDebugMenu* debugMenu;
