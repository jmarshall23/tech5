#pragma once

#include "gamelib/animstack/animator_animweb.h"
#include "network/serializer.h"

class idAnimator_AnimWebHands : public idAnimator_AnimWeb {
public:
    idAnimator_AnimWebHands()
        : punchSelector(0.0f)
        , throwSelector(0.0f)
        , idleSelector(0.0f)
        , meleeReturnSelector(0.0f)
        , zoomSelector(0.0f)
        , weaponCondition(0.0f)
        , variationIndex(0.0f)
        , previousVariationIndex(0.0f)
        , weaponAnimVarIndex(0.0f)
        , attackVariation(0.0f) {
    }

    ~idAnimator_AnimWebHands() override = default;

    void SerializeSnapshot(idSerializer* serializer) override {
        if (serializer == nullptr || GetSerializeType() == STYPE_GENERIC)
            return;
        serializer->Serialize(punchSelector);
        serializer->Serialize(throwSelector);
        serializer->Serialize(idleSelector);
        serializer->Serialize(meleeReturnSelector);
        serializer->Serialize(zoomSelector);
        serializer->Serialize(weaponCondition);
        serializer->Serialize(variationIndex);
        serializer->Serialize(previousVariationIndex);
        serializer->Serialize(weaponAnimVarIndex);
        serializer->Serialize(attackVariation);
    }

    void InternalInitWeb() override {
        idAnimator_AnimWeb::InternalInitWeb();
        AddBlendVariable("punchSelector", &punchSelector,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("throwSelector", &throwSelector,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("idleSelector", &idleSelector,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("meleeReturnSelector", &meleeReturnSelector,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("zoomSelector", &zoomSelector,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("weaponCondition", &weaponCondition,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("variationIndex", &variationIndex,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("previousVariationIndex", &previousVariationIndex,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("weaponAnimVarIndex", &weaponAnimVarIndex,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
        AddBlendVariable("attackVariation", &attackVariation,
            idAnimWebScalarPair::FF_NO_OVERRIDE);
    }

    float punchSelector;
    float throwSelector;
    float idleSelector;
    float meleeReturnSelector;
    float zoomSelector;
    float weaponCondition;
    float variationIndex;
    float previousVariationIndex;
    float weaponAnimVarIndex;
    float attackVariation;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_AnimWebHands) == 688,
    "Recovered idAnimator_AnimWebHands ABI changed");
#endif
