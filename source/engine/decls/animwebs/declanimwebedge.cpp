#include "decls/animwebs/declanimwebedge.h"

#include "idlib/filesystem/file.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <algorithm>
#include <cmath>

// The web owns its state, sub-web and node tables.  These queries correspond
// directly to the calls in the recovered edge parser and are implemented by
// declanimweb.cpp once that owner translation unit is materialized.
int Decls_AnimWebNodeSubWebIndex(const idDeclAnimWebNode* node);
const char* Decls_AnimWebSubWebName(const idDeclAnimWeb* declaration,
    int subWebIndex);
const char* Decls_AnimWebNodeStateName(const idDeclAnimWeb* declaration,
    int nodeIndex);
int Decls_AnimWebNodeSubWebIndex(const idDeclAnimWeb* declaration,
    int nodeIndex);
int Decls_AnimWebAddNode(idDeclAnimWeb* declaration, const char* subWebName,
    const char* stateName, int& subWebIndex, int& stateIndex);
int Decls_AnimWebAddSubWeb(idDeclAnimWeb* declaration,
    const char* subWebName);
int Decls_AnimWebEdgeCustomFlag(const char* name);

idDeclAnimWebEdge::idDeclAnimWebEdge()
    : destSubWebIndex(-1), blendParms(), customFlags(0) {
}

idDeclAnimWebEdge::~idDeclAnimWebEdge() = default;

void idDeclAnimWebEdge::Parse(idDeclAnimWeb* const declaration,
        idDeclAnimWebNode* const sourceNode,
        idAnimWebEdgeCache* const edgeCache, idParser& parser) {
    if (declaration == nullptr || sourceNode == nullptr || edgeCache == nullptr) {
        parser.Error("idDeclAnimWebEdge: missing parse owner");
        return;
    }
    if (!parser.ExpectTokenString("{")) return;

    idStr destinationSubWeb(Decls_AnimWebSubWebName(declaration,
        Decls_AnimWebNodeSubWebIndex(sourceNode)));
    idToken token;
    if (!parser.ExpectTokenString("toState")
        || parser.ExpectTokenType(TT_STRING, 0, token) == 0) {
        return;
    }
    idStr destinationState(token.c_str());

    std::uint8_t flags = static_cast<std::uint8_t>(edgeCache->flags & ~1u);
    if (parser.CheckTokenString("toSubWeb") != 0) {
        if (parser.ExpectTokenType(TT_STRING, 0, token) == 0) return;
        destinationSubWeb = token.c_str();
    }
    if (parser.CheckTokenString("weightScale") != 0) {
        const int fixed = static_cast<int>(parser.ParseFloat() * 16.0f);
        edgeCache->weightScale = static_cast<std::uint8_t>(
            (std::max)(0, (std::min)(255, fixed)));
    }
    if (parser.CheckTokenString("randomizeWeight") != 0) {
        if (parser.ParseBool()) flags |= EDGEFLAG_RANDOM_WEIGHT;
    }
    if (parser.CheckTokenString("blendParms") != 0) {
        blendParms.Parse(declaration, sourceNode, destinationSubWeb.c_str(),
            destinationState.c_str(), parser);
    }
    if (parser.CheckTokenString("customFlags") != 0) {
        while (parser.ReadTokenOnLine(token) != 0) {
            const int flag = Decls_AnimWebEdgeCustomFlag(token.c_str());
            if (flag >= 0) customFlags |= static_cast<std::uint16_t>(flag);
            else parser.Warning("unrecognized custom flag '%s'", token.c_str());
        }
    }

    if (destinationState.Length() != 0) {
        int stateIndex = -1;
        int subWebIndex = -1;
        edgeCache->destNodeIndex = static_cast<std::int16_t>(
            Decls_AnimWebAddNode(declaration, destinationSubWeb.c_str(),
                destinationState.c_str(), subWebIndex, stateIndex));
        destSubWebIndex = static_cast<std::int16_t>(subWebIndex);
    } else if (destinationSubWeb.Length() != 0) {
        edgeCache->destNodeIndex = -1;
        destSubWebIndex = static_cast<std::int16_t>(
            Decls_AnimWebAddSubWeb(declaration, destinationSubWeb.c_str()));
    } else {
        parser.Error("idDeclAnimWebEdge: sub-web name cannot be empty.");
    }
    edgeCache->flags = flags;
    parser.ExpectTokenString("}");
}

void idDeclAnimWebEdge::Write(const idDeclAnimWeb* const declaration,
        const idDeclAnimWebNode*, const idAnimWebEdgeCache* const edgeCache,
        idFile_String& file, const char* const indent) const {
    if (declaration == nullptr || edgeCache == nullptr) return;
    const char* const tabs = indent != nullptr ? indent : "";
    file.WriteFloatString("%sedge {\n", tabs);
    file.WriteFloatString("%s\ttoState \"%s\"\n", tabs,
        edgeCache->destNodeIndex >= 0
            ? Decls_AnimWebNodeStateName(declaration,
                edgeCache->destNodeIndex) : "");

    const int sourceSubWeb = edgeCache->destNodeIndex >= 0
        ? Decls_AnimWebNodeSubWebIndex(declaration,
            edgeCache->destNodeIndex) : -1;
    if (destSubWebIndex != sourceSubWeb) {
        file.WriteFloatString("%s\ttoSubWeb \"%s\"\n", tabs,
            Decls_AnimWebSubWebName(declaration, destSubWebIndex));
    }
    const float weightScale = edgeCache->weightScale * (1.0f / 16.0f);
    if (weightScale != 1.0f)
        file.WriteFloatString("%s\tweightScale %g\n", tabs, weightScale);
    if ((edgeCache->flags & EDGEFLAG_RANDOM_WEIGHT) != 0)
        file.WriteFloatString("%s\trandomizeWeight 1\n", tabs);

    idStr blendIndent(tabs);
    blendIndent.Append("\t");
    blendParms.Write(file, blendIndent.c_str());
    file.WriteFloatString("%s}\n", tabs);
}
