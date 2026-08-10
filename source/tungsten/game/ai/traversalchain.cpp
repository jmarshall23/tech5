#include "traversalchain.h"

// Retail symbol: ?Spawn@idInfoTraversal@@QAAXXZ
// EA: 0x82B04900, RVA: 0x00B04900
void idInfoTraversal::Spawn() {
    if (aasTraversal) {
        Tungsten_RemoveInfoTraversal(this);
    }
}

// Retail symbol: ?Spawn@idInfoNavFlightVolume@@QAAXXZ
// EA: 0x82B04920, RVA: 0x00B04920
void idInfoNavFlightVolume::Spawn() {
    // The address is COMDAT-folded with an unrelated AI-event intensity
    // thunk in the retail image. The decorated source signature is a void
    // spawn callback and contributes no persistent state here.
}

// Retail symbol: ??0idInfo_TraversalPoint@@QAA@XZ
// EA: 0x82B04930, RVA: 0x00B04930
idInfo_TraversalPoint::idInfo_TraversalPoint() = default;

// Retail symbol: ??1idInfo_TraversalPoint@@UAA@XZ
// EA: 0x82B04970, RVA: 0x00B04970
idInfo_TraversalPoint::~idInfo_TraversalPoint() = default;

// Retail symbol: ??0idInfoTraversal@@QAA@XZ
// EA: 0x82B04988, RVA: 0x00B04988
idInfoTraversal::idInfoTraversal()
    : aasType(AAS_MONSTER48)
    , traversalAnim()
    , overrideAnim(ANIMOVERRIDE_NONE)
    , classA(false)
    , classB(false)
    , defaultEndpointOffset(16.0f)
    , classC(false)
    , classD(false)
    , classE(false)
    , evasionTraversalOnly(false)
    , emergencyTraversalOnly(false)
    , combatTraversalOnly(true)
    , aasTraversal(true)
    , enabled(true)
    , runWhenDone(true)
    , deltaCorrect(true)
    , longTraversal(false)
    , traversalEndpoint(16.0f, 0.0f, 0.0f)
    , extrusionEndpoint(0.0f, -16.0f, 0.0f) {
}

// Retail symbol: ??0idInfo_TraversalChain@@QAA@XZ
// EA: 0x82B04BE0, RVA: 0x00B04BE0
idInfo_TraversalChain::idInfo_TraversalChain()
    : idInfo_TraversalPoint()
    , mData{
        AAS_MONSTER48,
        static_cast<idAASTraversalChainData::localClass_t>(0),
        static_cast<idAASTraversalChainData::localFlags_t>(
            idAASTraversalChainData::DELTA_CORRECT
            | idAASTraversalChainData::RUN_WHEN_DONE
            | idAASTraversalChainData::ENABLED
            | idAASTraversalChainData::COMBAT_ONLY),
        idVec3(0.0f, 0.0f, 0.0f),
        nullptr }
    , mLinks(0) {
}

// Retail symbol: ??1idInfo_TraversalChain@@UAA@XZ
// EA: 0x82B04CB8, RVA: 0x00B04CB8
idInfo_TraversalChain::~idInfo_TraversalChain() = default;
