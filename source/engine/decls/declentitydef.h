#pragma once

#include "decls/decl.h"
#include "idlib/color.h"
#include "idlib/math/vector.h"

class idFile;
class idParser;
class idTypeInfoTree;

class alignas(4) idEntityDefEditorVars {
public:
    idEntityDefEditorVars();

    bool Parse(idParser& parser);
    bool Write(const class idDeclEntityDef* parentDef, idFile& file) const;

    idStr editorName;
    idColor color;
    idVec3 size;
    idVec3 originOffset;
    idAtomicString material;
    idAtomicString animName;
    int animFrame;
    unsigned char reserved : 1;
    unsigned char noClip : 1;
    unsigned char instantiable : 1;
    unsigned char placeable : 1;
    unsigned char showInRenderMode : 1;
    unsigned char showFixedBox : 1;
    unsigned char showOrientation : 1;
    unsigned char rotatable : 1;
};

class alignas(4) idDeclEntityDef : public idDecl {
public:
    idDeclEntityDef();
    ~idDeclEntityDef() override;

    idDeclInfo* GetDeclInfo() const override;
    bool RebuildTextSource() override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override { return sizeof(*this); }

    virtual void SetInherit(const char* value);
    virtual void SetClass(const char* value);
    virtual const char* GetInherit() const { return inherit.c_str(); }
    virtual const char* GetClass() const { return className.c_str(); }
    virtual const char* GetEntityState() const;
    virtual int GetEntityStateLength() const;
    virtual int GetEntityStateLineNumber() const;
    virtual const char* GetEntityStateWithInheritance() const {
        return entityStateWithInheritanceText.c_str();
    }
    virtual int GetEntityStateWithInheritanceLength() const;
    virtual int GetEntityStateWithInheritanceLineNumber() const {
        return GetEntityStateLineNumber();
    }
    virtual void SetInheritedClass(bool writeEditorVars);
    virtual void SetEntityState(const char* state, bool writeEditorVars);
    virtual void SetEntityState(const idTypeInfoTree& tree, bool onlyDiff,
        bool writeEditorVars);
    virtual const idDeclEntityDef* GetListedParent() const {
        return listedParent;
    }
    virtual bool IsParent(const idDeclEntityDef* child) const;
    virtual void BuildText(const char* inheritName, const char* classType);
    virtual void GetTextWithInheritance(idStr& text,
        bool stripWhiteSpace) const;

    idAtomicString inherit;
    idAtomicString className;
    idEntityDefEditorVars editorVars;
    int stateOffset;
    int stateLineNumberOffset;
    bool expandInheritance;
    idStr entityStateWithInheritanceText;
    const idDeclEntityDef* listedParent;

    static idDeclInfoTemplate<idDeclEntityDef> resourceList;

private:
    void SetupEntityStateWithInheritance();
    void SetupEntityStateWithInheritance_r(idTypeInfoTree& tree);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEntityDefEditorVars) == 88,
    "Recovered entity-def editor variables ABI changed");
static_assert(sizeof(idDeclEntityDef) == 200,
    "Recovered entity-def declaration ABI changed");
#endif
