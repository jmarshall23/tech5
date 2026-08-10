#pragma once

#include "../../../engine/aas2file/aastraversalchaindata.h"
#include "../../../engine/gamelib/animstack/animweb/animwebpath.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/math/vector.h"
#include "../entities/entityptr.h"
#include "../gametooldefs.h"

class idDeclAnimWeb;

void Tungsten_RemoveInfoTraversal(class idInfoTraversal* traversal);

class idInfo_TraversalPoint {
public:
    idInfo_TraversalPoint();
    virtual ~idInfo_TraversalPoint();
};

class idInfoTraversal {
public:
    idInfoTraversal();
    virtual ~idInfoTraversal() = default;

    void Spawn();

    aasType_t aasType;
    idAnimWebPath traversalAnim;
    overrideAnim_t overrideAnim;
    bool classA;
    bool classB;
    float defaultEndpointOffset;
    bool classC;
    bool classD;
    bool classE;
    bool evasionTraversalOnly;
    bool emergencyTraversalOnly;
    bool combatTraversalOnly;
    bool aasTraversal;
    bool enabled;
    bool runWhenDone;
    bool deltaCorrect;
    bool longTraversal;
    idVec3 traversalEndpoint;
    idVec3 extrusionEndpoint;
};

class idInfoNavFlightVolume {
public:
    void Spawn();
};

class idInfo_TraversalChain : public idInfo_TraversalPoint {
public:
    struct idLink {
        idEntityPtr<idInfo_TraversalPoint> mTarget;
        idAnimWebPath mAnim;
    };

    idInfo_TraversalChain();
    ~idInfo_TraversalChain() override;

    idAASTraversalChainData mData;
    idList<idLink, 5> mLinks;
};
