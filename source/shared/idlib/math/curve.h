#pragma once

#include "angles.h"
#include "vector.h"
#include "../containers/list.h"

template<class type_t>
class alignas(4) idCurve {
public:
    idCurve() : times(), values(), currentIndex(-1), changed(true) {}
    virtual ~idCurve() = default;

    virtual int AddValue(float time, const type_t& value) {
        int index = 0;
        while (index < times.Num() && times[index] < time) ++index;
        times.Insert(time, index);
        values.Insert(value, index);
        changed = true;
        currentIndex = -1;
        return index;
    }

    virtual void RemoveIndex(int index) {
        if (index < 0 || index >= times.Num()) return;
        times.RemoveIndex(index);
        values.RemoveIndex(index);
        changed = true;
        currentIndex = -1;
    }

    virtual void Clear() {
        times.Clear();
        values.Clear();
        currentIndex = -1;
        changed = true;
    }

    virtual void SetNumValues(int count) {
        times.SetNum(count);
        values.SetNum(count);
        currentIndex = -1;
        changed = true;
    }

    virtual type_t GetCurrentValue(float time) const {
        if (values.Num() == 0) return type_t();
        return values[IndexForTime(time)];
    }
    virtual type_t GetCurrentFirstDerivative(float) const { return type_t(); }
    virtual type_t GetCurrentSecondDerivative(float) const { return type_t(); }
    virtual bool IsDone(float time) const {
        return times.Num() == 0 || time >= times[times.Num() - 1];
    }
    virtual float GetLengthForTime(float time) const {
        return EstimateLengthForTime(time);
    }
    virtual float EstimateLengthForTime(float) const { return 0.0f; }

    int GetNumValues() const { return values.Num(); }
    float GetTime(int index) const { return times[index]; }
    const type_t& GetValue(int index) const { return values[index]; }
    type_t& GetValue(int index) { changed = true; return values[index]; }
    void SetTime(int index, float time) { times[index] = time; changed = true; }
    void SetValue(int index, const type_t& value) {
        values[index] = value;
        changed = true;
    }
    void ShiftTime(float delta) {
        for (int index = 0; index < times.Num(); ++index) times[index] += delta;
        changed = true;
    }
    void MakeUniform(float totalTime) {
        const int count = times.Num();
        if (count <= 1) return;
        const float step = totalTime / static_cast<float>(count - 1);
        for (int index = 0; index < count; ++index) times[index] = step * index;
        changed = true;
    }
    float MakeUniformMoveSpeed(float totalTime) {
        MakeUniform(totalTime);
        return totalTime;
    }
    void SetConstantSpeed(float totalTime) { MakeUniform(totalTime); }
    float GetLengthBetweenKnots(int, int) const { return 0.0f; }
    float GetTimeForLength(float length, float epsilon = 0.1f) const {
        return EstimateTimeForLength(length, epsilon);
    }
    float EstimateTimeForLength(float length, float) const { return length; }
    void GetBatchValues(const float* timesIn, type_t* valuesOut,
        type_t* derivativesOut, int count) const {
        for (int index = 0; index < count; ++index) {
            valuesOut[index] = GetCurrentValue(timesIn[index]);
            if (derivativesOut != nullptr) {
                derivativesOut[index] = GetCurrentFirstDerivative(timesIn[index]);
            }
        }
    }

    idList<float, 116> times;
    idList<type_t, 116> values;
    mutable int currentIndex;
    mutable bool changed;

protected:
    virtual idCurve<type_t>* CreateNewCurve() const {
        return new idCurve<type_t>();
    }

    int IndexForTime(float time) const {
        if (times.Num() <= 1) return 0;
        int low = 0;
        int high = times.Num();
        while (low < high) {
            const int middle = (low + high) / 2;
            if (times[middle] <= time) low = middle + 1;
            else high = middle;
        }
        currentIndex = low > 0 ? low - 1 : 0;
        return currentIndex;
    }

    float RombergIntegral(float, float, int) const { return 0.0f; }
};

template<class type_t>
class idCurve_Spline : public idCurve<type_t> {
public:
    idCurve_Spline() = default;
    ~idCurve_Spline() override = default;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idCurve<idVec4>) == 44,
    "Recovered idCurve<idVec4> ABI changed");
static_assert(sizeof(idCurve<idVec3>) == 44,
    "Recovered idCurve<idVec3> ABI changed");
static_assert(sizeof(idCurve<idAngles>) == 44,
    "Recovered idCurve<idAngles> ABI changed");
static_assert(sizeof(idCurve<idVec1>) == 44,
    "Recovered idCurve<idVec1> ABI changed");
#endif
