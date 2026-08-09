#include "decls/decltable.h"

#include "idlib/lookuptable.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/parser.h"
#include "idlib/text/tokenstatic.h"

#include <cfloat>
#include <cstring>
#include <new>

void DeclTable_RemoveFromParmState(const idDeclTable* declaration);

idDeclInfoTemplate<idDeclTable> idDeclTable::resourceList(
    "table", "idDeclTable", "m2");

idDeclTable::idDeclTable() : left(0.0f), right(1.0f), table(nullptr) {
    void* const storage = mem.AllocWithLocation(
        "engine/decls/decltable.cpp: TAG_TABLE", sizeof(idLookupTable),
        TAG_TABLE, false, ALIGN_16, HEAP_DEFAULTHEAP);
    if (storage != nullptr) table = new (storage) idLookupTable();
}

idDeclTable::~idDeclTable() {
    DeclTable_RemoveFromParmState(this);
    if (table != nullptr) {
        table->~idLookupTable();
        mem.Free(table, ALIGN_16);
        table = nullptr;
    }
}

idDeclInfo* idDeclTable::GetDeclInfo() const { return &resourceList; }

void idDeclTable::FreeData() {
    if (table != nullptr) table->Clear();
}

const char* idDeclTable::DefaultDefinition() const {
    return "{ { 0 } }\n";
}

void idDeclTable::Parse(idParser* const parser) {
    if (parser == nullptr || table == nullptr) return;
    idToken token;
    bool clamp = false;
    float minimumValue = FLT_MAX;
    float maximumValue = -FLT_MAX;
    float implicitTime = 0.0f;
    float outputMinimum = 0.0f;
    float outputMaximum = 1.0f;
    table->Clear();

    while (parser->ReadToken(token)) {
        if (std::strcmp(token.c_str(), "}") == 0) break;
        if (_stricmp(token.c_str(), "snap") == 0) {
            table->SetSnap(true);
        } else if (_stricmp(token.c_str(), "clamp") == 0) {
            clamp = true;
        } else if (_stricmp(token.c_str(), "spline") == 0) {
            table->SetSpline(true);
        } else if (_stricmp(token.c_str(), "max") == 0) {
            outputMaximum = parser->ParseFloat();
        } else if (_stricmp(token.c_str(), "min") == 0) {
            outputMinimum = parser->ParseFloat();
        } else if (_stricmp(token.c_str(), "left") == 0) {
            left = parser->ParseFloat();
        } else if (_stricmp(token.c_str(), "right") == 0) {
            right = parser->ParseFloat();
        } else if (std::strcmp(token.c_str(), "{") == 0) {
            for (;;) {
                bool error = false;
                float value = parser->ParseFloat(&error);
                if (error) return;
                float time = implicitTime;
                if (parser->CheckTokenString(":") != 0) {
                    time = value;
                    value = parser->ParseFloat(&error);
                    if (error) return;
                }
                if (table->NumValues() >= 64) {
                    parser->Warning("more than %d points", 64);
                    return;
                }
                if (value < minimumValue) minimumValue = value;
                if (value > maximumValue) maximumValue = value;
                table->AddValue(time, value);
                implicitTime = time + 1.0f;
                if (!parser->ReadToken(token)) return;
                if (std::strcmp(token.c_str(), "}") == 0) break;
                if (std::strcmp(token.c_str(), ",") != 0) {
                    parser->Warning("expected comma or brace");
                    return;
                }
            }
        } else {
            parser->Warning("unknown token '%s'", token.c_str());
        }
    }

    if (table->NumValues() != 0
        && (minimumValue < 0.0f || maximumValue > 1.0f)) {
        table->NormalizeValues(minimumValue, maximumValue);
        const float range = maximumValue - minimumValue;
        outputMinimum = outputMinimum * range + minimumValue;
        outputMaximum = outputMaximum * range + minimumValue;
    }
    table->SetOutputRange(outputMinimum, outputMaximum);
    table->SetClamp(clamp);
    table->Finalize();
}
