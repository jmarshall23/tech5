#pragma once

#include "decls/animwebs/animwebscalar.h"
#include "decls/animwebs/declanimwebnode.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"
#include "idlib/containers/staticlist.h"

class idLexer;
class idMD6Allocator;
class idMD6Filter;
class idMD6Model;

class alignas(4) idAnimWebBlendEquation {
public:
    enum result_t : int {
        PARSE_OK,
        PARSE_ERROR_UNKNOWN_TOKEN,
        PARSE_SYNTAX_ERROR,
        PARSE_MISSING_CURLY_OPEN_BRACE,
        PARSE_MISSING_CURLY_CLOSE_BRACE,
        PARSE_MISSING_COMMA,
        PARSE_UNKNOWN_SCALAR,
        PARSE_UNKNOWN_ANIMATION,
        PARSE_OUT_OF_MIXERS,
        PARSE_UNSUPPORTED_VARIABLE_REFERENCE,
        PARSE_MAX
    };

    struct animList_t {
        animList_t();
        idStaticList<idMD6Filter*, 10> filterList;
        idStaticList<idMD6Node*, 256> animList;
        idStaticList<unsigned int, 256> tagList;
        int animPropIndex;
    };

    struct existingNode_t {
        existingNode_t();
        char name[8];
        idMD6Node* node;
    };

    idAnimWebBlendEquation();

    bool Parse(const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* model, idMD6Allocator* allocator,
        int startTime, int ticksPerSecond, const char* equation,
        idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes, idMD6Node*& root,
        idList<idAnimWebScalarPair, 33>& scalarPairs);

    static void AllocateUndeclaredScalars(
        idList<idAnimWebScalar, 33>& scalars, idScalarMemBlock& block);

    int startTime;
    int ticksPerSec;
    idStaticList<idMD6Node*, 64> allocatedNodes;
    int expressionLevel;

private:
    struct scalarValue_t {
        int scalarIndex;
        int pairIndex;
        float immediate;
        bool copyOnPlay;
    };

    idMD6Node* ParseExpression(idLexer& lexer,
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* model, idMD6Allocator& allocator,
        idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes,
        idList<idAnimWebScalarPair, 33>& scalarPairs);
    idMD6Node* ParseNamedNode(const char* name, idLexer& lexer,
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* model, idMD6Allocator& allocator,
        idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes,
        idList<idAnimWebScalarPair, 33>& scalarPairs);
    scalarValue_t ParseScalar(idLexer& lexer,
        idList<idAnimWebScalar, 33>& scalars,
        idList<idAnimWebScalarPair, 33>& scalarPairs);
    int FindOrAddScalar(const char* name,
        idList<idAnimWebScalar, 33>& scalars,
        idList<idAnimWebScalarPair, 33>& scalarPairs,
        int& pairIndex);
    idMD6Branch* AllocBranch(idMD6Allocator& allocator,
        idMD6Node::nodeType_t type, idMD6Node* left, idMD6Node* right,
        float alpha, md6WeightGroup_t weightGroup);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimWebBlendEquation::existingNode_t) == 12,
    "Recovered animation-web existing-node ABI changed");
static_assert(sizeof(idAnimWebBlendEquation::animList_t) == 2140,
    "Recovered animation-web animation-list ABI changed");
static_assert(sizeof(idAnimWebBlendEquation) == 284,
    "Recovered animation-web blend-equation ABI changed");
#endif
