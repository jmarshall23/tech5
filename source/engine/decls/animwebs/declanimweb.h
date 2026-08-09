#pragma once

#include "decls/animwebs/animwebscalar.h"
#include "decls/decltypeinfo.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>

class idDeclAnimWebEdge;
class idDeclAnimWebNode;
class idDeclMD6;
class idFile_String;
class idParser;

class alignas(4) idDeclAnimWebTag {
public:
    idDeclAnimWebTag() : name(""), isDefault(false) {}

    idAtomicString name;
    bool isDefault;
};

class idDeclAnimWebTagGroup {
public:
    idDeclAnimWebTagGroup() : name(""), tagList(16) {}

    idAtomicString name;
    idList<idDeclAnimWebTag, 32> tagList;
};

class alignas(4) idDeclAnimWeb : public idDecl {
public:
    using nodeIndex_t = idAnimWebNodeIndex;
    using stateIndex_t = idAnimWebStateIndex;
    using subWebIndex_t = idAnimWebSubWebIndex;
    using edgeIndex_t = idAnimWebEdgeIndex;
    using modelIndex_t = idAnimWebModelIndex;

    enum invalidLayerIndex_t : int { INVALID_LAYER_INDEX = -1 };
    using layerIndex_t = idIndex<short, invalidLayerIndex_t>;

    enum nodeProps_t : int {
        NP_ANIM, NP_WRAP, NP_RATE, NP_DELTA, NP_BLENDEQ,
        NP_TRANSITION, NP_MAX
    };
    enum subWebBlend_t : int {
        SUBWEBBLEND_USE_SOURCE_NODE,
        SUBWEBBLEND_ALWAYS_BLEND_OUT_ANYWHERE,
        SUBWEBBLEND_MAX
    };

    struct stateList_t {
        stateIndex_t stateIndex[4];
        std::uint16_t numStates;

        stateList_t();
    };

    class idSubWebInfo {
    public:
        idSubWebInfo();

        idList<nodeIndex_t, 32> nodes;
        idAtomicString name;
        idColor color;
        bool isHub;
        bool isVisible;
        bool used;
    };

    class idStateInfo {
    public:
        idStateInfo() : name("") {}
        idAtomicString name;
    };

    struct idEdgeCache {
        idEdgeCache();
        nodeIndex_t destNodeIndex;
        std::uint8_t weightScale;
        std::uint8_t flags;
    };

    struct idNodeCache {
        idNodeCache();
        std::uint16_t numEdges;
        std::uint8_t flags;
        std::uint8_t pad2;
        unsigned int edgeIndexOffset;
    };

    class alignas(4) idLayerInfo {
    public:
        idLayerInfo();
        idAtomicString name;
        idList<idAtomicString, 5> subWebsOnLayer;
        bool isVisible;
    };

    class idSettings {
    public:
        idSettings();
        idVec3 editPos;
        int gridSize;
        bool snapToGrid;
        bool showGrid;
        bool alwaysShowIntraSubwebLinks;
        bool alwaysShowNodeProps;
        bool showAbbreviatedNodeProps;
        bool showIncomingLinks;
        bool isComposite;
        bool mergeModels;
        bool nodeProps[NP_MAX];
        int defaultBlendOutWindow;
        int defaultBlendDuration;
        subWebBlend_t subWebBlend;
    };

    idDeclAnimWeb();
    ~idDeclAnimWeb() override;

    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;
    idDeclInfo* GetDeclInfo() const override;

    idAtomicString GetStateNameAtomic(stateIndex_t index) const;
    stateIndex_t GetStateIndexForName(const char* name) const;
    subWebIndex_t GetSubWebIndexForName(const char* name) const;
    const char* GetSubWebName(subWebIndex_t index) const;
    idAtomicString GetSubWebNameAtomic(subWebIndex_t index) const;
    const char* GetStateName(stateIndex_t index) const;
    nodeIndex_t GetNodeIndexForName(const char* subWeb,
        const char* state) const;
    nodeIndex_t FindNodeIndex(subWebIndex_t subWeb,
        stateIndex_t state) const;
    nodeIndex_t FindNodeIndex(subWebIndex_t subWeb,
        const stateList_t& stateList, bool exact) const;
    modelIndex_t FindModelIndex(const idDeclMD6* model) const;
    const idList<idAnimWebScalar, 32>& GetScalars() const;
    const idDeclAnimWebEdge* FindEdge(nodeIndex_t source,
        nodeIndex_t destination) const;
    int FindNodeIndices(subWebIndex_t subWeb, stateIndex_t state,
        idList<nodeIndex_t, 5>& output) const;
    nodeIndex_t FindNodeIndices(subWebIndex_t subWeb,
        const stateList_t& stateList, idList<nodeIndex_t, 5>& output) const;

    subWebIndex_t AddSubWeb(const char* name);
    nodeIndex_t AddNode(subWebIndex_t subWeb, stateIndex_t state);
    nodeIndex_t AddNode(subWebIndex_t subWeb, const stateList_t& stateList);
    void AddNode(const char* subWeb, const char* state,
        nodeIndex_t& node, subWebIndex_t& subWebIndex,
        stateIndex_t& stateIndex);
    edgeIndex_t AllocEdge();
    void Write(idFile_String& file, const char* indent = "") const;

    static void Composite(idList<const idDeclAnimWeb*, 5>& declarations,
        idDeclAnimWeb* destination);

    idList<idDeclAnimWebNode*, 32> nodes;
    idList<idSubWebInfo, 32> subWebs;
    idList<idStateInfo, 32> states;
    idList<const idDeclMD6*, 32> models;
    idList<idDeclAnimWebEdge, 32> edges;
    idList<idEdgeCache, 32> edgeCache;
    idList<idNodeCache, 32> nodeCache;
    idList<idAnimWebScalar, 32> scalars;
    idList<idAtomicString, 32> editorModels;
    idList<idLayerInfo, 32> layers;
    edgeIndex_t* edgeIndexCache;
    unsigned int edgeIndexCacheSize;
    int changeId;
    bool expandSubWebLinks;
    idSettings settings;

    static idDeclInfoTemplate<idDeclAnimWeb> resourceList;
};

static_assert(sizeof(idDeclAnimWeb::stateList_t) == 10,
    "Recovered animation-web state-list ABI changed");
static_assert(sizeof(idDeclAnimWeb::idEdgeCache) == 4,
    "Recovered animation-web edge-cache ABI changed");
static_assert(sizeof(idDeclAnimWeb::idNodeCache) == 8,
    "Recovered animation-web node-cache ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAnimWebTag) == 8,
    "Recovered animation-web tag ABI changed");
static_assert(sizeof(idDeclAnimWebTagGroup) == 20,
    "Recovered animation-web tag-group ABI changed");
static_assert(sizeof(idDeclAnimWeb::idSubWebInfo) == 40,
    "Recovered animation-web sub-web ABI changed");
static_assert(sizeof(idDeclAnimWeb::idLayerInfo) == 24,
    "Recovered animation-web layer ABI changed");
static_assert(sizeof(idDeclAnimWeb::idSettings) == 44,
    "Recovered animation-web settings ABI changed");
static_assert(sizeof(idDeclAnimWeb) == 276,
    "Recovered animation-web declaration ABI changed");
#endif
