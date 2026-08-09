#include "decls/declentitydef.h"

#include "decls/declmanager.h"
#include "idlib/filesystem/file.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"
#include "idlib/typeinfo/typeinfofile.h"
#include "idlib/typeinfo/typeinfotree.h"

#include <algorithm>
#include <cstring>

bool Decls_EntityDefIsSubclassOf(const char* className,
    const char* superClassName);
bool Decls_RebuildEntityDefText(idDeclEntityDef& declaration);

namespace {

int ParserOffset(const idParser& parser) {
    return parser.scriptstack != nullptr
        ? parser.scriptstack->GetFileOffset() : 0;
}

int ParserLine(const idParser& parser) {
    return parser.scriptstack != nullptr
        ? parser.scriptstack->GetLineNum() : 0;
}

bool SameVec3(const idVec3& left, const idVec3& right) {
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

bool SameColor(const idColor& left, const idColor& right) {
    return left.r == right.r && left.g == right.g
        && left.b == right.b && left.a == right.a;
}

const idDeclEntityDef* FindEntityDef(const char* name,
        const bool makeDefault) {
    if (name == nullptr || name[0] == '\0') return nullptr;
    return static_cast<const idDeclEntityDef*>(
        idDeclEntityDef::resourceList.FindWithInheritance(name, makeDefault));
}

} // namespace

idDeclInfoTemplate<idDeclEntityDef> idDeclEntityDef::resourceList(
    "entityDef", "idDeclEntityDef", "def");

idEntityDefEditorVars::idEntityDefEditorVars()
    : editorName(), color(1.0f, 1.0f, 1.0f, 1.0f), size(0.0f, 0.0f, 0.0f),
      originOffset(0.0f, 0.0f, 0.0f), material(""), animName(""),
      animFrame(0), reserved(0), noClip(0), instantiable(1), placeable(1),
      showInRenderMode(0), showFixedBox(0), showOrientation(0), rotatable(0) {
}

bool idEntityDefEditorVars::Parse(idParser& parser) {
    if (parser.CheckTokenString("editorVars") == 0) return false;
    if (!parser.ExpectTokenString("{")) return true;

    bool deprecated = false;
    idToken name;
    while (parser.CheckTokenString("}") == 0) {
        if (parser.ExpectAnyToken(name) == 0
            || !parser.ExpectTokenString("=")) break;
        const char* const key = name.c_str();
        if (idStr::Icmp(key, "rotatable") == 0) rotatable = parser.ParseBool();
        else if (idStr::Icmp(key, "showOrientation") == 0) showOrientation = parser.ParseBool();
        else if (idStr::Icmp(key, "noClip") == 0) noClip = parser.ParseBool();
        else if (idStr::Icmp(key, "showFixedBox") == 0) showFixedBox = parser.ParseBool();
        else if (idStr::Icmp(key, "showInRenderMode") == 0) showInRenderMode = parser.ParseBool();
        else if (idStr::Icmp(key, "placeable") == 0) placeable = parser.ParseBool();
        else if (idStr::Icmp(key, "instantiable") == 0) instantiable = parser.ParseBool();
        else if (idStr::Icmp(key, "color") == 0) {
            parser.CheckTokenString("(");
            color.r = parser.ParseFloat(); parser.CheckTokenString(",");
            color.g = parser.ParseFloat(); parser.CheckTokenString(",");
            color.b = parser.ParseFloat(); parser.CheckTokenString(",");
            color.a = parser.ParseFloat(); parser.CheckTokenString(")");
        } else if (idStr::Icmp(key, "size") == 0) {
            parser.CheckTokenString("(");
            size.x = parser.ParseFloat(); parser.CheckTokenString(",");
            size.y = parser.ParseFloat(); parser.CheckTokenString(",");
            size.z = parser.ParseFloat(); parser.CheckTokenString(")");
        } else if (idStr::Icmp(key, "originOffset") == 0) {
            parser.CheckTokenString("(");
            originOffset.x = parser.ParseFloat(); parser.CheckTokenString(",");
            originOffset.y = parser.ParseFloat(); parser.CheckTokenString(",");
            originOffset.z = parser.ParseFloat(); parser.CheckTokenString(")");
        } else if (idStr::Icmp(key, "material") == 0) {
            if (parser.ExpectTokenType(TT_STRING, 0, name) != 0)
                material.Set(name.c_str());
        } else if (idStr::Icmp(key, "animName") == 0) {
            if (parser.ExpectTokenType(TT_STRING, 0, name) != 0)
                animName.Set(name.c_str());
        } else if (idStr::Icmp(key, "animFrame") == 0) {
            animFrame = parser.ParseInt();
        } else if (idStr::Icmp(key, "deprecated") == 0) {
            deprecated = parser.ParseBool();
        } else if (idStr::Icmp(key, "editorName") == 0) {
            if (parser.ExpectTokenType(TT_STRING, 0, name) != 0)
                editorName = name.c_str();
        }
        parser.SkipUntilString(";");
    }
    if (deprecated) placeable = 0;
    return true;
}

bool idEntityDefEditorVars::Write(const idDeclEntityDef* const parentDef,
        idFile& file) const {
    const idEntityDefEditorVars defaults;
    const idEntityDefEditorVars& parent = parentDef != nullptr
        ? parentDef->editorVars : defaults;
    file.WriteFloatString("\teditorVars {\n");
#define WRITE_BOOL(name) \
    if (parentDef == nullptr || name != parent.name) \
        file.WriteFloatString("\t\t" #name " = %s;\n", name ? "true" : "false")
    WRITE_BOOL(rotatable);
    WRITE_BOOL(showOrientation);
    WRITE_BOOL(showFixedBox);
    WRITE_BOOL(showInRenderMode);
#undef WRITE_BOOL
    file.WriteFloatString("\t\tplaceable = %s;\n", placeable ? "true" : "false");
    if (parentDef == nullptr || !SameColor(color, parent.color))
        file.WriteFloatString("\t\tcolor = ( %f, %f, %f, %f );\n",
            color.r, color.g, color.b, color.a);
    if (parentDef == nullptr || !SameVec3(size, parent.size))
        file.WriteFloatString("\t\tsize = ( %f, %f, %f );\n",
            size.x, size.y, size.z);
    if (parentDef == nullptr || !SameVec3(originOffset, parent.originOffset))
        file.WriteFloatString("\t\toriginOffset = ( %f, %f, %f );\n",
            originOffset.x, originOffset.y, originOffset.z);
    if (parentDef == nullptr || material != parent.material)
        file.WriteFloatString("\t\tmaterial = \"%s\";\n", material.c_str());
    if (parentDef == nullptr || animName != parent.animName)
        file.WriteFloatString("\t\tanimName = \"%s\";\n", animName.c_str());
    if (parentDef == nullptr || animFrame != parent.animFrame)
        file.WriteFloatString("\t\tanimFrame = %d;\n", animFrame);
    if (parentDef == nullptr || idStr::Cmp(editorName.c_str(),
            parent.editorName.c_str()) != 0)
        file.WriteFloatString("\t\teditorName = \"%s\";\n", editorName.c_str());
    file.WriteFloatString("\t}\n");
    return true;
}

idDeclEntityDef::idDeclEntityDef()
    : inherit(""), className(""), editorVars(), stateOffset(0),
      stateLineNumberOffset(0), expandInheritance(true),
      entityStateWithInheritanceText(), listedParent(this) {
}

idDeclEntityDef::~idDeclEntityDef() = default;

idDeclInfo* idDeclEntityDef::GetDeclInfo() const { return &resourceList; }

const char* idDeclEntityDef::DefaultDefinition() const {
    return "{\n\tinherit = \"\";\n\tclass = \"idEntity\";\n"
           "\tedit = {\n\t}\n}\n";
}

const char* idDeclEntityDef::GetEntityState() const {
    const char* const text = GetText();
    return text != nullptr ? text + (std::max)(0, stateOffset) : "";
}

int idDeclEntityDef::GetEntityStateLength() const {
    return (std::max)(0, textLength - stateOffset);
}

int idDeclEntityDef::GetEntityStateLineNumber() const {
    return GetLineNum() + stateLineNumberOffset;
}

int idDeclEntityDef::GetEntityStateWithInheritanceLength() const {
    return entityStateWithInheritanceText.Length();
}

void idDeclEntityDef::FreeData() {
    inherit.Set("");
    className.Set("");
    stateOffset = 0;
    stateLineNumberOffset = 0;
}

void idDeclEntityDef::SetInherit(const char* const value) {
    inherit.Set(value);
}

void idDeclEntityDef::SetClass(const char* const value) {
    className.Set(value);
}

bool idDeclEntityDef::IsParent(const idDeclEntityDef* const child) const {
    if (child == this) return true;
    return listedParent != nullptr && listedParent != this
        && listedParent->IsParent(child);
}

void idDeclEntityDef::BuildText(const char* const inheritName,
        const char* const classType) {
    idStr text;
    text.Format("{\n\tinherit = \"%s\";\n\tclass = \"%s\";\n"
        "\tedit = {\n\t}\n}", inheritName != nullptr ? inheritName : "",
        classType != nullptr ? classType : "");
    SetText(text.c_str());
    ReParse(false);
}

void idDeclEntityDef::SetEntityState(const idTypeInfoTree& tree,
        const bool onlyDiff, const bool writeEditorVars) {
    idTypeInfoFile file(2);
    file.WriteMemoryFile();
    file.settings.resolveEntityPointers = false;
    file.settings.resolveModelPointers = false;
    file.settings.writeModifier = idTypeInfoSettings::WRITE_DEF_AND_EDIT_ONLY;
    file.settings.writeType = false;
    tree.Write(file, onlyDiff);
    SetEntityState(file.GetTypeInfoString(), writeEditorVars);
}

void idDeclEntityDef::SetEntityState(const char* const state,
        const bool writeEditorVars) {
    const char* const safeState = state != nullptr ? state : "";
    int indentation = 0;
    while (safeState[indentation] == '\t') ++indentation;

    idFile_Memory file;
    file.WriteFloatString("{\n");
    const idDeclEntityDef* parent = FindEntityDef(inherit.c_str(), true);
    if (!inherit.IsEmpty()) {
        for (int index = 0; index < indentation; ++index) file.WriteFloatString("\t");
        file.WriteFloatString("inherit = \"%s\";\n", inherit.c_str());
    }
    if (inherit.IsEmpty() || parent == nullptr
        || idStr::Cmp(className.c_str(), parent->className.c_str()) != 0) {
        for (int index = 0; index < indentation; ++index) file.WriteFloatString("\t");
        file.WriteFloatString("class = \"%s\";\n", className.c_str());
    }
    if (writeEditorVars) editorVars.Write(parent, file);
    file.Write(safeState, static_cast<int>(std::strlen(safeState)));
    file.WriteFloatString("\n");
    for (int index = 0; index < indentation - 1; ++index) file.WriteFloatString("\t");
    file.WriteFloatString("}");
    SetText(file.GetDataPtr());
    ReParse(false);
}

void idDeclEntityDef::SetInheritedClass(const bool writeEditorVars) {
    const idDeclEntityDef* const parent = FindEntityDef(inherit.c_str(), false);
    if (parent == nullptr
        || idStr::Cmp(className.c_str(), parent->className.c_str()) == 0) return;

    const char* state = GetEntityState();
    const char* const edit = std::strchr(state, '{');
    if (edit == nullptr) return;
    idFile_Memory file;
    file.WriteFloatString("{\n\tinherit = \"%s\";\n", inherit.c_str());
    if (writeEditorVars) editorVars.Write(parent, file);
    file.WriteFloatString("\tedit = %s", edit);
    SetText(file.GetDataPtr());
    ReParse(false);
}

void idDeclEntityDef::GetTextWithInheritance(idStr& text,
        const bool stripWhiteSpace) const {
    text = "{\n";
    if (!inherit.IsEmpty()) {
        idStr line;
        line.Format("inherit = \"%s\";\n", inherit.c_str());
        text.Append(line);
    }
    idStr line;
    line.Format("class = \"%s\";\nexpandInheritance = false;\n",
        className.c_str());
    text.Append(line);
    text.Append(entityStateWithInheritanceText);
    text.ReplaceRecovered("\n", "\n\t");
    text.Append("\n}");
    if (stripWhiteSpace) {
        text.ReplaceRecovered("\t", " ");
        text.ReplaceRecovered("\r", "");
        text.ReplaceRecovered("\n", "");
        text.ReplaceRecovered("   ", " ");
        text.ReplaceRecovered("  ", " ");
    }
}

void idDeclEntityDef::SetupEntityStateWithInheritance_r(
        idTypeInfoTree& tree) {
    if (!inherit.IsEmpty()) {
        const idDeclEntityDef* const parent = FindEntityDef(inherit.c_str(), false);
        if (parent != nullptr) {
            const_cast<idDeclEntityDef*>(parent)
                ->SetupEntityStateWithInheritance_r(tree);
            listedParent = parent->listedParent != nullptr
                ? parent->listedParent : parent;
        }
    }
    idTypeInfoFile file(0);
    if (file.ReadMemory(GetEntityState(), GetEntityStateLength(),
            GetFileName(), GetEntityStateLineNumber())) {
        tree.ParseOverwrite(file);
    }
}

void idDeclEntityDef::SetupEntityStateWithInheritance() {
    listedParent = this;
    if (expandInheritance) {
        idTypeInfoTree tree;
        SetupEntityStateWithInheritance_r(tree);
        idTypeInfoFile file(0);
        file.WriteMemoryFile();
        file.settings.resolveEntityPointers = false;
        file.settings.resolveModelPointers = false;
        tree.Write(file, false);
        entityStateWithInheritanceText = file.GetTypeInfoString();
    } else {
        idStr state;
        for (int index = 0; index < GetEntityStateLength(); ++index)
            state.Append(GetEntityState()[index]);
        entityStateWithInheritanceText = state;
        if (!inherit.IsEmpty()) listedParent = FindEntityDef(inherit.c_str(), false);
    }
}

void idDeclEntityDef::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    stateOffset = ParserOffset(*parser);
    inherit.Set("");
    idToken token;
    if (parser->CheckTokenString("inherit") != 0) {
        parser->ExpectTokenString("=");
        if (parser->ExpectTokenType(TT_STRING, 0, token) != 0)
            inherit.Set(token.c_str());
        parser->ExpectTokenString(";");
        stateOffset = ParserOffset(*parser);
    }

    className.Set("");
    if (parser->CheckTokenString("class") != 0) {
        parser->ExpectTokenString("=");
        if (parser->ExpectTokenType(TT_STRING, 0, token) != 0)
            className.Set(token.c_str());
        parser->ExpectTokenString(";");
        stateOffset = ParserOffset(*parser);
    }

    if (!inherit.IsEmpty()) {
        const idDeclEntityDef* const parent = FindEntityDef(inherit.c_str(), false);
        if (parent != nullptr) {
            if (declManager != nullptr) declManager->AddDependency(this, parent);
            const bool authoredPlaceable = editorVars.placeable != 0;
            editorVars = parent->editorVars;
            editorVars.placeable = authoredPlaceable;
            if (className.IsEmpty()) className.Set(parent->className.c_str());
            else if (!Decls_EntityDefIsSubclassOf(className.c_str(),
                    parent->className.c_str())) {
                parser->Error("Class %s does not derive from %s",
                    className.c_str(), parent->className.c_str());
            }
        } else {
            parser->Warning("Unknown entityDef '%s' inherited by '%s'",
                inherit.c_str(), GetName());
            if (className.IsEmpty()) className.Set("idEntity");
        }
    }
    if (className.IsEmpty()) parser->Error("No class specified");

    if (parser->CheckTokenString("expandInheritance") != 0) {
        parser->ExpectTokenString("=");
        expandInheritance = parser->ParseBool();
        parser->ExpectTokenString(";");
        stateOffset = ParserOffset(*parser);
    }
    if (editorVars.Parse(*parser)) stateOffset = ParserOffset(*parser);
    stateLineNumberOffset = ParserLine(*parser) - GetLineNum();
    SetupEntityStateWithInheritance();
}

bool idDeclEntityDef::RebuildTextSource() {
    return Decls_RebuildEntityDefText(*this);
}
