#pragma once

#include "decls/animwebs/blendparms.h"

#include <cstdint>

class idDeclAnimWeb;
class idDeclAnimWebNode;
class idFile_String;
class idParser;

struct idAnimWebEdgeCache {
    std::int16_t destNodeIndex;
    std::uint8_t weightScale;
    std::uint8_t flags;
};

class alignas(4) idDeclAnimWebEdge {
public:
    enum edgeFlags_t : int {
        EDGEFLAG_RANDOM_WEIGHT = 1
    };

    idDeclAnimWebEdge();
    virtual ~idDeclAnimWebEdge();

    void Parse(idDeclAnimWeb* declaration, idDeclAnimWebNode* sourceNode,
        idAnimWebEdgeCache* edgeCache, idParser& parser);
    void Write(const idDeclAnimWeb* declaration,
        const idDeclAnimWebNode* sourceNode,
        const idAnimWebEdgeCache* edgeCache, idFile_String& file,
        const char* indent) const;

    std::int16_t destSubWebIndex;
    blendParms_t blendParms;
    std::uint16_t customFlags;
};

static_assert(sizeof(idAnimWebEdgeCache) == 4,
    "Recovered animation-web edge-cache ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAnimWebEdge) == 32,
    "Recovered animation-web edge ABI changed");
#endif
