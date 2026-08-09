#include "decls/declenv.h"

#include "decls/declmanager.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <cstring>

void DeclEnv_ClearParmBlock(idParmBlock& block);
void DeclEnv_AppendParmBlock(idParmBlock& destination,
    const idParmBlock& source);
bool DeclEnv_ParseParmBlock(idParmBlock& block, idParser& parser);
float DeclEnv_GetBlendDuration(const idParmBlock& block);

idDeclInfoTemplate<idDeclEnv> idDeclEnv::resourceList(
    "env", "idDeclEnv", "env");

idDeclEnv::idDeclEnv()
    : parmBlock(THREAD_MAIN), parentDeclName(""), blendDuration(0.0f) {}

idDeclInfo* idDeclEnv::GetDeclInfo() const { return &resourceList; }

const char* idDeclEnv::DefaultDefinition() const {
    return "{\n"
        "\trenderParms {\n"
        "\t\tenvBlendTime\t\t\t2.2\n"
        "\t\tuserEnvMap\t\t\t\tenv/default_px\n"
        "\t\tambientEnvMap\t\t\tenv/ambiTest_px\n"
        "\t\tenvMapRotation\t\t\t{ 0, 0, 0 }\n"
        "\t\tcbShadow\t\t\t\t{ 0, 0, 0 }\n"
        "\t\tcbMidtone\t\t\t\t{ 0, 0, 0 }\n"
        "\t\tcbHighlight\t\t\t\t{ 0, 0, 0 }\n"
        "\t\tcbDesaturate\t\t\t0\n"
        "\t\tcbBrightness\t\t\t{ 1, 1, 1, 1 }\n"
        "\t\tcbColorDodge\t\t\t{ 0, 0, 0, 0 }\n"
        "\t\tcbColorBurn\t\t\t\t{ 1, 1, 1, 1 }\n"
        "\t\tcbColorMultiply\t\t\t{ 1, 1, 1, 1 }\n"
        "\t\tcbColorScreen\t\t\t{ 0, 0, 0, 0 }\n"
        "\t\tdepthBasedColorGrading\t{ 0, 0, 0, 0 }\n"
        "\t\tfogColor\t\t\t\t{ 0.2, 0.43, 0.5, 0.0 }\n"
        "\t\tfogScale\t\t\t\t0.00005\n"
        "\t\tfogStart\t\t\t\t0.0\n"
        "\t\tfogEnd\t\t\t\t\t32000.0\n"
        "\t\tnewAmbientScale\t\t\t{ 0.3, 0.3, 0.3 }\n"
        "\t\texposure\t\t\t\t1.0\n"
        "\t\tglareScale\t\t\t\t0.3\n"
        "\t\tdepthOfField\t\t\t{ 1.0, 1.0, 5500.0, 1.0 }\n"
        "\t\tscreenOverlay\t\t\t_white\n"
        "\t\toverlayOpacity\t\t\t0\n"
        "\t\tgrainMap\t\t\t\ttextures/common/postgrain\n"
        "\t\tgrainAmount\t\t\t\t0.03\n"
        "\t\tgrainHz\t\t\t\t\t20\n"
        "\t\tgrainLevelsMin\t\t\t0\n"
        "\t\tgrainLevelsMax\t\t\t1\n"
        "\t}\n"
        "}\n";
}

void idDeclEnv::FreeData() { DeclEnv_ClearParmBlock(parmBlock); }

void idDeclEnv::Parse(idParser* const parser) {
    if (parser == nullptr) return;
    FreeData();
    idParmBlock localBlock(THREAD_MAIN);
    idToken token;
    while (parser->ReadToken(token)) {
        if (std::strcmp(token.c_str(), "}") == 0) {
            DeclEnv_AppendParmBlock(parmBlock, localBlock);
            blendDuration = DeclEnv_GetBlendDuration(parmBlock);
            return;
        }
        if (_stricmp(token.c_str(), "inherit") == 0) {
            if (!parser->ExpectTokenString("{")
                || parser->ExpectAnyToken(token) == 0
                || !parser->ExpectTokenString("}")) {
                parser->Error("idDeclEnv::Parse Failed to parse inherit data");
                return;
            }
            const idDeclEnv* const base = static_cast<const idDeclEnv*>(
                resourceList.FindWithInheritance(token.c_str(), false));
            if (base != nullptr) {
                DeclEnv_AppendParmBlock(parmBlock, base->parmBlock);
                parentDeclName.Set(token.c_str());
                if (declManager != nullptr) declManager->AddDependency(this, base);
            } else {
                parser->Warning("idDeclEnv::Parse - Invalid base decl '%s'",
                    token.c_str());
                parentDeclName.Set("");
            }
        } else if (_stricmp(token.c_str(), "renderParms") == 0) {
            if (!parser->ExpectTokenString("{")) {
                parser->Error(
                    "idDeclEnv::Parse Unexpected token, missing '{'");
                return;
            }
            if (!DeclEnv_ParseParmBlock(localBlock, *parser)) return;
        }
    }
    parser->Error("idDeclEnv::Parse Unexpected End of File");
}
