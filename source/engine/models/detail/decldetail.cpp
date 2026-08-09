#include "models/detail/decldetail.h"

#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

idDeclInfoTemplate<idDeclDetail> idDeclDetail::resourceList(
    "detail", "idDeclDetail", "detail");

idDeclDetail::idDeclDetail()
    : modelName(""), colorVariance(1.0f, 1.0f, 1.0f) {
}

idDeclInfo* idDeclDetail::GetDeclInfo() const {
    return &resourceList;
}

const char* idDeclDetail::DefaultDefinition() const {
    return "{\n\tmodel\t_default\n}\n";
}

void idDeclDetail::Parse(idParser* const parser) {
    modelName.Set("");
    colorVariance.Set(1.0f, 1.0f, 1.0f);
    if (parser == nullptr) return;

    idTokenStatic<260> token;
    while (parser->ReadToken(token)) {
        if (idStr::Icmp(token.c_str(), "}") == 0) break;
        if (idStr::Icmp(token.c_str(), "model") == 0) {
            if (!parser->ExpectAnyToken(token)) break;
            modelName.Set(token.c_str());
        } else if (idStr::Icmp(token.c_str(), "colorVariance") == 0) {
            colorVariance.x = parser->ParseFloat();
            colorVariance.y = parser->ParseFloat();
            colorVariance.z = parser->ParseFloat();
        } else if (idStr::Icmp(token.c_str(), "{") != 0) {
            parser->Warning("idDeclDetail::Parse - bad token %s",
                token.c_str());
        }
    }
}
