#include "models/particles/jobs/particleparm.h"

#include "idlib/lookuptable.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

float RandomRange(idRandom2& random, const float minimum,
    const float maximum) {
    return minimum + (maximum - minimum) * random.RandomFloat();
}

float ApplyVariance(idRandom2& random, const float value,
    const float variance) {
    return value + random.CRandomFloat() * variance * value;
}

float Lookup(const idLookupTable* tables, const int index,
    const float fraction) {
    return tables != nullptr && index >= 0
        ? tables[index].TableLookup(fraction, true)
        : 0.0f;
}

float LookupMaximum(const idLookupTable* tables, const int index) {
    if (tables == nullptr || index < 0) {
        return 0.0f;
    }
    // idLookupTable keeps the recovered cached output maximum at byte 8,
    // but the read-only idlib contract intentionally leaves it private.
    float maximum = 0.0f;
    std::memcpy(&maximum,
        reinterpret_cast<const unsigned char*>(&tables[index]) + 8,
        sizeof(maximum));
    return maximum;
}

} // namespace

void idParticleParm::Clear() {
    val0 = 0.0f;
    val1 = 0.0f;
    variance = 0.0f;
    tableIdx = -1;
    table2Idx = -1;
    calcType = PARTICLE_CALC_NONE;
}

void idParticleParm::SetCalcTypeFromEditType(
    const particleEditCalcType_t editType) {
    switch (editType) {
    case PARTICLE_EDIT_CALC_CONSTANT:
    case PARTICLE_EDIT_CALC_MINMAX:
        calcType = PARTICLE_CALC_GENERIC;
        break;
    case PARTICLE_EDIT_CALC_CURVE:
    case PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS:
    case PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT:
        calcType = PARTICLE_CALC_CURVE_GENERIC;
        break;
    case PARTICLE_EDIT_CALC_CURVE_MOD_CURVE:
        calcType = PARTICLE_CALC_CURVE_MOD_CURVE;
        break;
    case PARTICLE_EDIT_CALC_CURVE_ADD_CURVE:
        calcType = PARTICLE_CALC_CURVE_ADD_CURVE;
        break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_EVAL:
        calcType = PARTICLE_CALC_PARAMETRIC_EVAL;
        break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE:
        calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE;
        break;
    case PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX;
        break;
    default:
        calcType = PARTICLE_CALC_NONE;
        break;
    }
}

particleEditCalcType_t idParticleParm::GetEditCalcType() const {
    switch (calcType) {
    case PARTICLE_CALC_GENERIC:
        return val0 == val1 ? PARTICLE_EDIT_CALC_CONSTANT
                            : PARTICLE_EDIT_CALC_MINMAX;
    case PARTICLE_CALC_CURVE_GENERIC:
        if (variance != 0.0f) {
            return PARTICLE_EDIT_CALC_CURVE_VARIANCE_MOD_CONSTANT;
        }
        return val0 == 1.0f && val1 == 0.0f
            ? PARTICLE_EDIT_CALC_CURVE
            : PARTICLE_EDIT_CALC_CURVE_SCALE_BIAS;
    case PARTICLE_CALC_CURVE_MOD_CURVE:
        return PARTICLE_EDIT_CALC_CURVE_MOD_CURVE;
    case PARTICLE_CALC_CURVE_ADD_CURVE:
        return PARTICLE_EDIT_CALC_CURVE_ADD_CURVE;
    case PARTICLE_CALC_PARAMETRIC_EVAL:
        return PARTICLE_EDIT_CALC_PARAMETRIC_EVAL;
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE:
        return PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE;
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        return PARTICLE_EDIT_CALC_PARAMETRIC_INTEGRATE_MINMAX;
    default:
        return PARTICLE_EDIT_CALC_NONE;
    }
}

float idParticleParm::GetMaxParmVal(const idLookupTable* tables) const {
    switch (calcType) {
    case PARTICLE_CALC_CURVE_GENERIC: {
        const float maximum = LookupMaximum(tables, tableIdx);
        return (maximum + variance * maximum) * val0 + val1;
    }
    case PARTICLE_CALC_GENERIC: {
        const float maximum = (std::max)(val0, val1);
        return maximum + variance * maximum;
    }
    case PARTICLE_CALC_CURVE_MOD_CURVE:
        return LookupMaximum(tables, tableIdx)
            * LookupMaximum(tables, table2Idx);
    case PARTICLE_CALC_CURVE_ADD_CURVE:
        return LookupMaximum(tables, tableIdx)
            + LookupMaximum(tables, table2Idx);
    case PARTICLE_CALC_PARAMETRIC_EVAL:
        return (1.0f + variance) * val1;
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE:
        return 0.5f * (val0 + val1) * (1.0f + variance);
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        return (std::max)(val0, val1) * (1.0f + variance);
    default:
        return 0.0f;
    }
}

float idParticleParm::Compute(const idLookupTable* tables,
    const float fraction, idRandom2& random) const {
    switch (calcType) {
    case PARTICLE_CALC_CURVE_GENERIC:
        if (tables == nullptr || tableIdx < 0) return val1;
        return ApplyVariance(random, Lookup(tables, tableIdx, fraction),
            variance) * val0 + val1;
    case PARTICLE_CALC_GENERIC:
        return ApplyVariance(random, RandomRange(random, val0, val1),
            variance);
    case PARTICLE_CALC_CURVE_MOD_CURVE:
        return Lookup(tables, tableIdx, fraction)
            * Lookup(tables, table2Idx, fraction);
    case PARTICLE_CALC_CURVE_ADD_CURVE:
        return Lookup(tables, tableIdx, fraction)
            + Lookup(tables, table2Idx, fraction);
    case PARTICLE_CALC_PARAMETRIC_EVAL:
        return ApplyVariance(random, val0 + (val1 - val0) * fraction,
            variance);
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE: {
        const float integrated =
            (val0 + 0.5f * (val1 - val0) * fraction) * fraction;
        return ApplyVariance(random, integrated, variance);
    }
    case PARTICLE_CALC_PARAMETRIC_INTEGRATE_MINMAX:
        return ApplyVariance(random,
            RandomRange(random, val0, val1) * fraction, variance);
    default:
        return 0.0f;
    }
}

void SetParticleParmAsIntegrate(idParticleParm* parm, const float from,
    const float to, const float variance) {
    if (parm == nullptr) return;
    parm->val0 = from;
    parm->val1 = to;
    parm->variance = variance;
    parm->calcType = PARTICLE_CALC_PARAMETRIC_INTEGRATE;
}

void SetParticleParmAsEval(idParticleParm* parm, const float from,
    const float to, const float variance) {
    if (parm == nullptr) return;
    parm->val0 = from;
    parm->val1 = to;
    parm->variance = variance;
    parm->calcType = PARTICLE_CALC_PARAMETRIC_EVAL;
}

void SetParticleParmAsConstant(idParticleParm* parm, const float value,
    const float variance) {
    if (parm == nullptr) return;
    parm->val0 = value;
    parm->val1 = value;
    parm->variance = variance;
    parm->calcType = PARTICLE_CALC_GENERIC;
}

void SetParticleParmAsMinMax(idParticleParm* parm, const float minimum,
    const float maximum) {
    if (parm == nullptr) return;
    parm->val0 = minimum;
    parm->val1 = maximum;
    parm->variance = 0.0f;
    parm->calcType = PARTICLE_CALC_GENERIC;
}
