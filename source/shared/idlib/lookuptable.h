#pragma once

template<typename Type>
class idCatmullRomSpline;

template<>
class idCatmullRomSpline<float> {
public:
    enum boundary_t {
        FREE = 0,
        CLAMPED = 1,
        CLOSED = 2
    };

    float times[64];
    float values[64];
    int numKnots;
    mutable int currentIndex;
    bool changed;
    boundary_t boundaryType;
    float closeTime;

    void Sort();
    void Normalize(float totalTime);
    float ClampedTime(float time) const;
    int IndexForTime(float time, bool fastSearch) const;
    float TimeForIndex(int index) const;
    float ValueForIndex(int index) const;
    void Basis(int index, float time, float basisValues[4]) const;
    float GetCurrentValue(float time, bool fastSearch) const;
};

static_assert(
    sizeof(idCatmullRomSpline<float>) == 532,
    "Recovered idCatmullRomSpline<float> layout changed"
);

class idLookupTable {
public:
    idLookupTable();

    void SetSnap(bool enabled);
    void SetSpline(bool enabled);
    void Finalize();
    void SetClamp(bool enabled);
    void AddValue(float time, float value);
    void Clear();

    float TableLookupNormalized(float time, bool fastSearch) const;
    float TableLookup(float time, bool fastSearch) const;

private:
    bool clamp;
    bool snap;
    bool spline;
    float minimum;
    float maximum;
    idCatmullRomSpline<float> values;
};

static_assert(sizeof(idLookupTable) == 544, "idLookupTable ABI changed");
