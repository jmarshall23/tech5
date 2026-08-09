#include "decls/animwebs/animwebblendequation.h"

#include "idlib/text/lexer.h"
#include "idlib/text/str.h"
#include "idlib/text/tokenstatic.h"
#include "models/skeletalanimation/md6allocator.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

const idMD6Anim* Decls_AnimWebBlendAnimation(
    const idDeclAnimWebNode::idModelInfo& modelInfo,
    const idMD6Model* model, int animationIndex);
bool Decls_InitAnimWebBestLeaf(idMD6Node* node,
    const idDeclAnimWebNode::idModelInfo& modelInfo,
    const idList<idMD6Node*, 5>& leaves);
bool Decls_InitAnimWebTagFilter(idMD6Node* node,
    const idDeclAnimWebNode::idModelInfo& modelInfo, const char* groupName,
    idMD6Node* input);

namespace {

bool IsNumber(const idToken& token) { return token.type == TT_NUMBER; }

md6WeightGroup_t WeightGroupForName(const char* const name) {
    static const char* const names[MD6_WEIGHTGROUP_MAX] = {
        "all", "legs", "torso", "head", "face", "mouth", "eyelids",
        "user0"
    };
    for (int index = 0; index < MD6_WEIGHTGROUP_MAX; ++index)
        if (idStr::Icmp(name, names[index]) == 0)
            return static_cast<md6WeightGroup_t>(index);
    return MD6_WEIGHTGROUP_MAX;
}

int BlendOperation(const char* const name) {
    if (idStr::Icmp(name, "lerp") == 0) return 1;
    if (idStr::Icmp(name, "addl") == 0) return 3;
    if (idStr::Icmp(name, "addr") == 0) return 4;
    if (idStr::Icmp(name, "subl") == 0) return 5;
    if (idStr::Icmp(name, "subr") == 0) return 6;
    if (_strnicmp(name, "blend", 5) == 0) return 7;
    if (idStr::Icmp(name, "blenda") == 0) return 8;
    if (_strnicmp(name, "fusion", 6) == 0) return 9;
    return 0;
}

} // namespace

idAnimWebBlendEquation::animList_t::animList_t()
    : filterList(), animList(), tagList(), animPropIndex(-1) {
}

idAnimWebBlendEquation::existingNode_t::existingNode_t()
    : name{}, node(nullptr) {
}

idAnimWebBlendEquation::idAnimWebBlendEquation()
    : startTime(0), ticksPerSec(0), allocatedNodes(), expressionLevel(0) {
}

void idAnimWebBlendEquation::AllocateUndeclaredScalars(
        idList<idAnimWebScalar, 33>& scalars, idScalarMemBlock& block) {
    block.Free(scalars);
    int count = 0;
    for (int index = 0; index < scalars.Num(); ++index)
        if (scalars[index].scalarIndex < 0
            && scalars[index].scalarPtr == nullptr) ++count;
    if (count == 0) return;
    block.Alloc(count);
    int memoryIndex = 0;
    for (int index = 0; index < scalars.Num(); ++index) {
        idAnimWebScalar& scalar = scalars[index];
        if (scalar.scalarIndex >= 0 || scalar.scalarPtr != nullptr) continue;
        scalar.SetIndex(block, memoryIndex++);
        scalar.SetScalar(block,
            (scalar.flags & idAnimWebScalar::AWSFLAG_INIT_TO_1) != 0
                ? 1.0f : 0.0f);
    }
}

int idAnimWebBlendEquation::FindOrAddScalar(const char* const name,
        idList<idAnimWebScalar, 33>& scalars,
        idList<idAnimWebScalarPair, 33>& scalarPairs, int& pairIndex) {
    int scalarIndex = -1;
    for (int index = 0; index < scalars.Num(); ++index)
        if (idStr::Icmp(scalars[index].name.c_str(), name) == 0) {
            scalarIndex = index;
            break;
        }
    if (scalarIndex < 0) {
        idAnimWebScalar* const scalar = scalars.Alloc();
        if (scalar == nullptr) return -1;
        scalar->SetName(name);
        scalarIndex = scalars.Num() - 1;
    }
    idAnimWebScalarPair* const pair = scalarPairs.Alloc();
    if (pair == nullptr) return -1;
    pairIndex = scalarPairs.Num() - 1;
    pair->scalarIndex = scalarIndex;
    return scalarIndex;
}

idAnimWebBlendEquation::scalarValue_t idAnimWebBlendEquation::ParseScalar(
        idLexer& lexer, idList<idAnimWebScalar, 33>& scalars,
        idList<idAnimWebScalarPair, 33>& scalarPairs) {
    scalarValue_t result = {-1, -1, 0.0f, false};
    idToken token;
    if (!lexer.ReadToken(token)) {
        lexer.Error("Expected a scalar variable name or a number");
        return result;
    }
    if (IsNumber(token)) {
        result.immediate = static_cast<float>(std::atof(token.c_str()));
        return result;
    }
    if (idStr::Cmp(token.c_str(), "#") == 0
        || idStr::Icmp(token.c_str(), "onplay") == 0) {
        result.copyOnPlay = true;
        if (!lexer.ExpectTokenType(TT_NAME, 0, token)) return result;
    } else if (token.type != TT_NAME) {
        lexer.Error("Expected a scalar variable name or a number, got \"%s\"",
            token.c_str());
        return result;
    }
    result.scalarIndex = FindOrAddScalar(token.c_str(), scalars,
        scalarPairs, result.pairIndex);
    return result;
}

idMD6Branch* idAnimWebBlendEquation::AllocBranch(idMD6Allocator& allocator,
        const idMD6Node::nodeType_t type, idMD6Node* const left,
        idMD6Node* const right, const float alpha,
        const md6WeightGroup_t weightGroup) {
    idMD6Branch* const branch = reinterpret_cast<idMD6Branch*>(
        allocator.Alloc(type));
    if (branch == nullptr) return nullptr;
    branch->type = static_cast<std::uint8_t>(type);
    branch->left = left;
    branch->right = right;
    branch->leftTimeOverride = -1;
    branch->rightTimeOverride = -1;
    branch->filterGroup = static_cast<std::uint8_t>(weightGroup);
    branch->op = 0;
    branch->originBlend = 0;
    branch->currentAlpha = alpha;
    branch->targetAlpha = alpha;
    branch->alphaRate = 0.0f;
    branch->blendType = idMD6Branch::BLEND_LINEAR;
    allocatedNodes.Append(branch);
    return branch;
}

idMD6Node* idAnimWebBlendEquation::ParseNamedNode(const char* const name,
        idLexer& lexer, const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* const model, idMD6Allocator& allocator,
        idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes,
        idList<idAnimWebScalarPair, 33>& scalarPairs) {
    for (int index = 0; index < existingNodes.Num(); ++index)
        if (idStr::Icmp(existingNodes[index].name, name) == 0)
            return existingNodes[index].node;

    int animationIndex = -1;
    scalarValue_t animationSelector = {-1, -1, 0.0f, false};
    if (idStr::Icmp(name, "anim") == 0 && lexer.CheckTokenString("[")) {
        animationSelector = ParseScalar(lexer, scalars, scalarPairs);
        animationIndex = static_cast<int>(animationSelector.immediate);
        lexer.ExpectTokenString("]");
    } else if (_strnicmp(name, "anim", 4) == 0) {
        animationIndex = std::atoi(name + 4);
    }
    if (animationIndex < 0 || animationIndex >= modelInfo.animProps.Num()) {
        lexer.Error("'%s' is not a valid animation or leaf node name.", name);
        return nullptr;
    }

    md6WeightGroup_t weightGroup = MD6_WEIGHTGROUP_ALL;
    if (lexer.PeekTokenString("filtered") || lexer.PeekTokenString("masked")
        || lexer.PeekTokenString("weighted")) {
        idToken token;
        lexer.ReadToken(token);
        lexer.CheckTokenString("by");
        if (lexer.ReadToken(token)) {
            if (IsNumber(token))
                weightGroup = static_cast<md6WeightGroup_t>(
                    (std::max)(0, (std::min)(MD6_WEIGHTGROUP_MAX - 1,
                        std::atoi(token.c_str()))));
            else {
                weightGroup = WeightGroupForName(token.c_str());
                if (weightGroup == MD6_WEIGHTGROUP_MAX) {
                    lexer.Error("Unknown weight group name '%s'", token.c_str());
                    weightGroup = MD6_WEIGHTGROUP_ALL;
                }
            }
        }
    }

    scalarValue_t rate = {-1, -1, 1.0f, false};
    if (lexer.PeekTokenString("scaled")) {
        lexer.CheckTokenString("scaled");
        lexer.CheckTokenString("by");
        rate = ParseScalar(lexer, scalars, scalarPairs);
        if (rate.scalarIndex < 0 && (rate.immediate <= 0.0f
                || rate.immediate >= 9.0f))
            lexer.Error("Specified rate scale is out of range. Must be between 0.0f and 9.0f");
    }

    scalarValue_t pause = {-1, -1, 0.0f, false};
    const bool paused = lexer.PeekTokenString("paused");
    if (paused) {
        lexer.CheckTokenString("paused");
        lexer.CheckTokenString("at");
        pause = ParseScalar(lexer, scalars, scalarPairs);
        if (pause.scalarIndex < 0 && (pause.immediate < 0.0f
                || pause.immediate > 1.0f))
            lexer.Error("Specified normalized pause frame is out of range. Must be between 0.0f and 1.0f");
    }

    const idMD6Anim* const animation = Decls_AnimWebBlendAnimation(
        modelInfo, model, animationIndex);
    idMD6Node* node = nullptr;
    if (paused) {
        idMD6LeafPause* const leaf = reinterpret_cast<idMD6LeafPause*>(
            allocator.Alloc(idMD6Node::NODE_LEAF_PAUSE));
        if (leaf != nullptr) {
            leaf->Init(animation, pause.immediate,
                static_cast<std::uint8_t>(modelInfo.animProps[animationIndex].wrap),
                weightGroup);
            node = leaf;
        }
    } else {
        idMD6LeafPlay* const leaf = reinterpret_cast<idMD6LeafPlay*>(
            allocator.Alloc(idMD6Node::NODE_LEAF_PLAY));
        if (leaf != nullptr) {
            leaf->Init(animation, startTime,
                rate.scalarIndex < 0 ? rate.immediate : 1.0f,
                modelInfo.animProps[animationIndex].wrap, weightGroup);
            node = leaf;
        }
    }
    if (node == nullptr) return nullptr;
    allocatedNodes.Append(node);

    if (animationSelector.scalarIndex >= 0) {
        idAnimWebScalarPair& pair = scalarPairs[animationSelector.pairIndex];
        pair.node = node;
        pair.fieldType = idAnimWebScalarPair::FT_ANIMATION;
        pair.fieldFlags = animationSelector.copyOnPlay
            ? idAnimWebScalarPair::FF_COPY_ON_PLAY
            : idAnimWebScalarPair::FF_NO_OVERRIDE;
    }
    if (rate.scalarIndex >= 0) {
        idAnimWebScalarPair& pair = scalarPairs[rate.pairIndex];
        pair.node = node;
        pair.fieldType = idAnimWebScalarPair::FT_RATE_SCALE;
        pair.fieldFlags = rate.copyOnPlay
            ? idAnimWebScalarPair::FF_COPY_ON_PLAY
            : idAnimWebScalarPair::FF_NO_OVERRIDE;
        scalars[rate.scalarIndex].flags |= idAnimWebScalar::AWSFLAG_INIT_TO_1;
    }
    if (pause.scalarIndex >= 0) {
        idAnimWebScalarPair& pair = scalarPairs[pause.pairIndex];
        pair.node = node;
        pair.fieldType = idAnimWebScalarPair::FT_PAUSE_FRAME;
        pair.fieldFlags = pause.copyOnPlay
            ? idAnimWebScalarPair::FF_COPY_ON_PLAY
            : idAnimWebScalarPair::FF_NO_OVERRIDE;
    }
    return node;
}

idMD6Node* idAnimWebBlendEquation::ParseExpression(idLexer& lexer,
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* const model, idMD6Allocator& allocator,
        idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes,
        idList<idAnimWebScalarPair, 33>& scalarPairs) {
    idToken token;
    if (!lexer.ReadToken(token)) {
        lexer.Error("Empty token");
        return nullptr;
    }
    if (idStr::Cmp(token.c_str(), "(") == 0) {
        idMD6Node* const node = ParseExpression(lexer, modelInfo, model,
            allocator, scalars, existingNodes, scalarPairs);
        lexer.ExpectTokenString(")");
        return node;
    }

    const idStr operation(token.c_str());
    const int blendOperation = BlendOperation(operation.c_str());
    const bool selection = idStr::Cmp(operation.c_str(), "select") == 0
        || idStr::Cmp(operation.c_str(), "choose") == 0;
    if (blendOperation != 0 || selection) {
        if (!lexer.ExpectTokenString("(")) return nullptr;
        idMD6Node* const left = ParseExpression(lexer, modelInfo, model,
            allocator, scalars, existingNodes, scalarPairs);
        if (!lexer.ExpectTokenString(",")) return left;
        idMD6Node* const right = ParseExpression(lexer, modelInfo, model,
            allocator, scalars, existingNodes, scalarPairs);
        scalarValue_t alpha = {-1, -1, 0.5f, false};
        if (lexer.CheckTokenString(","))
            alpha = ParseScalar(lexer, scalars, scalarPairs);
        lexer.ExpectTokenString(")");

        idMD6Node::nodeType_t type = idMD6Node::NODE_BRANCH;
        if (blendOperation == 8) type = idMD6Node::NODE_BLENDA_BRANCH;
        else if (blendOperation == 9) type = idMD6Node::NODE_FUSION_BRANCH;
        idMD6Branch* const branch = AllocBranch(allocator, type, left, right,
            alpha.scalarIndex < 0 ? alpha.immediate : 0.0f,
            MD6_WEIGHTGROUP_ALL);
        if (branch == nullptr) return nullptr;
        branch->op = static_cast<std::uint8_t>(selection ? 7 : blendOperation);
        if (alpha.scalarIndex >= 0) {
            idAnimWebScalarPair& pair = scalarPairs[alpha.pairIndex];
            pair.node = branch;
            pair.fieldType = idAnimWebScalarPair::FT_CUR_ALPHA;
            pair.fieldFlags = alpha.copyOnPlay
                ? idAnimWebScalarPair::FF_COPY_ON_PLAY
                : idAnimWebScalarPair::FF_NO_OVERRIDE;
        }
        return branch;
    }

    if (idStr::Cmp(operation.c_str(), "best") == 0) {
        if (!lexer.ExpectTokenString("(")) return nullptr;
        idList<idMD6Node*, 5> leaves(16);
        while (!lexer.PeekTokenString(")")) {
            idMD6Node* const leaf = ParseExpression(lexer, modelInfo, model,
                allocator, scalars, existingNodes, scalarPairs);
            if (leaf != nullptr) leaves.Append(leaf);
            if (!lexer.CheckTokenString(",")) break;
        }
        lexer.ExpectTokenString(")");
        idMD6Node* const best = allocator.Alloc(idMD6Node::NODE_BEST_LEAF);
        if (best != nullptr) {
            best->type = idMD6Node::NODE_BEST_LEAF;
            allocatedNodes.Append(best);
            Decls_InitAnimWebBestLeaf(best, modelInfo, leaves);
        }
        return best;
    }

    if (idStr::Cmp(operation.c_str(), "filter") == 0) {
        if (!lexer.ExpectTokenString("(")) return nullptr;
        idToken group;
        if (!lexer.ReadToken(group)) return nullptr;
        lexer.ExpectTokenString(",");
        idMD6Node* const input = ParseExpression(lexer, modelInfo, model,
            allocator, scalars, existingNodes, scalarPairs);
        lexer.ExpectTokenString(")");
        idMD6Node* const filter = allocator.Alloc(idMD6Node::NODE_TAG_FILTER);
        if (filter != nullptr) {
            filter->type = idMD6Node::NODE_TAG_FILTER;
            allocatedNodes.Append(filter);
            Decls_InitAnimWebTagFilter(filter, modelInfo, group.c_str(), input);
        }
        return filter;
    }

    return ParseNamedNode(operation.c_str(), lexer, modelInfo, model,
        allocator, scalars, existingNodes, scalarPairs);
}

bool idAnimWebBlendEquation::Parse(
        const idDeclAnimWebNode::idModelInfo& modelInfo,
        const idMD6Model* const model, idMD6Allocator* const allocator,
        const int startTime_, const int ticksPerSecond,
        const char* const equation, idList<idAnimWebScalar, 33>& scalars,
        idList<existingNode_t, 5>& existingNodes, idMD6Node*& root,
        idList<idAnimWebScalarPair, 33>& scalarPairs) {
    root = nullptr;
    allocatedNodes.Clear();
    expressionLevel = 0;
    startTime = startTime_;
    ticksPerSec = ticksPerSecond;
    if (allocator == nullptr || equation == nullptr || equation[0] == '\0')
        return false;

    idLexer lexer(LEXFL_NOFATALERRORS | LEXFL_ALLOWNUMBERNAMES);
    if (!lexer.LoadMemory(equation,
            static_cast<unsigned int>(std::strlen(equation)),
            "idAnimWebBlendEquation::Parse")) return false;
    root = ParseExpression(lexer, modelInfo, model, *allocator, scalars,
        existingNodes, scalarPairs);
    idToken extra;
    if (lexer.ReadToken(extra))
        lexer.Error("idAnimWebBlendEquation::Parse: unexpected token '%s'",
            extra.c_str());
    if (root == nullptr || lexer.HadError()) {
        for (int index = allocatedNodes.Num() - 1; index >= 0; --index)
            allocator->Free(allocatedNodes[index]);
        allocatedNodes.Clear();
        root = nullptr;
        return false;
    }
    return true;
}
