#pragma once

#include "decls/animwebs/animprops.h"
#include "decls/animwebs/declanimweb.h"

class idDeclMD6;
class idFile_String;
class idAnimWebPath;
class idParser;
class idStr;

class alignas(4) idDeclAnimWebNode {
public:
    enum nodeFlag_t : int {
        NODEFLAG_START_TRANSITION = 0x01,
        NODEFLAG_STOP_TRANSITION = 0x02,
        NODEFLAG_STEP_TRANSITION = 0x04,
        NODEFLAG_TURN_TRANSITION = 0x08,
        NODEFLAG_BLENDOUT = 0x10,
        NODEFLAG_ADDITIVECAMERA = 0x20,
        NODEFLAG_GENERIC_TRANSITION = 0x40,
        NODEFLAG_HIDE = 0x80
    };
    enum animDelta_t : int {
        ANIMDELTA_DEFAULT,
        ANIMDELTA_FULL,
        ANIMDELTA_FULL_NOCLIP,
        ANIMDELTA_FULL_GRAVITY,
        ANIMDELTA_TURN,
        ANIMDELTA_FULL_VELOCITY,
        ANIMDELTA_FULL_DRIVE_AI,
        ANIMDELTA_IGNORE,
        ANIMDELTA_MAX
    };

    class idModelInfo {
    public:
        idModelInfo();
        idModelInfo(const idModelInfo& other);
        ~idModelInfo();
        idModelInfo& operator=(const idModelInfo& other);

        int NumCoordinateDimensions() const;
        void SetNumCoordinateDimensions(int count);
        void SetCoordinate(int propertyIndex,
            const idList<float, 5>& value);
        int NumTagGroups() const;
        void AddTagGroup();
        void UpdateTagGroupsList(int count);
        void CopyTagGroups(const idModelInfo& other);
        void FixUpAnimVars(const idDeclMD6* modelDeclaration);
        void Parse(idDeclAnimWeb* declaration, idDeclAnimWebNode* node,
            idParser& parser);
        void Write(const idDeclAnimWeb* declaration,
            idDeclAnimWeb::subWebIndex_t subWebIndex,
            const idDeclMD6* modelDeclaration, idFile_String& file,
            const char* indent) const;

        idDeclAnimWeb::modelIndex_t modelIndex;
        idAtomicString blendEq;
        idAtomicString blendEqFixed;
        idList<idMD6AnimProps, 32> animProps;
        idList<float, 32>* coordinates;
        idList<idDeclAnimWebTagGroup, 32>* tagGroups;
    };

    struct toolSettings_t {
        toolSettings_t() : pos(0.0f, 0.0f, 0.0f) {}
        idVec3 pos;
    };

    idDeclAnimWebNode(idDeclAnimWeb::nodeIndex_t nodeIndex,
        idDeclAnimWeb::subWebIndex_t subWebIndex,
        idDeclAnimWeb::stateIndex_t stateIndex);
    idDeclAnimWebNode(idDeclAnimWeb::nodeIndex_t nodeIndex,
        idDeclAnimWeb::subWebIndex_t subWebIndex,
        const idDeclAnimWeb::stateList_t& stateIndices);
    ~idDeclAnimWebNode();

    int MatchStates(const idDeclAnimWeb::stateList_t& stateList) const;
    void GetPath(const idDeclAnimWeb* declaration, idAnimWebPath& path) const;
    void GetStateName(const idDeclAnimWeb* declaration, idStr& name) const;
    void GetStateName(const idDeclAnimWeb* declaration, int state,
        idStr& name) const;
    void GetName(const idDeclAnimWeb* declaration, idStr& name) const;
    const idModelInfo* FindModelInfo(idDeclAnimWeb::modelIndex_t model) const;
    idModelInfo* FindModelInfo(idDeclAnimWeb::modelIndex_t model);
    bool IsLooping() const;
    unsigned int Size() const;
    int NumAnims(idDeclAnimWeb::modelIndex_t model) const;
    const idMD6Anim* GetAnim(idDeclAnimWeb::modelIndex_t model,
        int animation) const;
    void CreateSubWebEdges(idDeclAnimWeb* declaration);
    void Write(const idDeclAnimWeb* declaration, idFile_String& file,
        const char* indent) const;
    void AddModelInfo(const idModelInfo& info,
        idDeclAnimWeb::modelIndex_t model);
    bool Parse(idDeclAnimWeb* declaration, idParser& parser);

    idDeclAnimWeb::nodeIndex_t nodeIndex;
    idDeclAnimWeb::subWebIndex_t subWebIndex;
    idDeclAnimWeb::stateList_t states;
    std::uint8_t animDelta;
    std::uint8_t flags;
    std::uint16_t customFlags;
    idList<idDeclAnimWeb::edgeIndex_t, 32> edges;
    idList<idModelInfo, 32> modelInfo;
    toolSettings_t settings;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclAnimWebNode::idModelInfo) == 36,
    "Recovered animation-web model-info ABI changed");
static_assert(sizeof(idDeclAnimWebNode) == 64,
    "Recovered animation-web node ABI changed");
#endif
