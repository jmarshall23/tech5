#pragma once

#include "../bv/bounds.h"
#include "../containers/list.h"
#include "../math/plane.h"
#include "../sys/sys_alloc.h"

class idWinding {
public:
    idWinding();
    idWinding(const idWinding& other);
    virtual ~idWinding();

    idWinding& operator=(const idWinding& other);
    virtual void Clear();
    virtual bool ReAllocate(int numPoints, bool keep = false);
    void AddPoint(const idVec3& point);
    void AddPoint(const idVec5& point);
    void AddToConvexHull(const idVec3& point, const idVec3& normal,
        float epsilon = 0.1f);
    void BaseForPlane(const idVec3& normal, float distance,
        float size = 65536.0f);
    bool ClipInPlace(const idPlane& plane, float epsilon = 0.1f,
        bool keepOn = false);
    void GetBounds(idBounds& bounds) const;
    idVec3 GetCenter() const;
    void GetPlane(idPlane& plane) const;
    bool IsHuge(float radius) const;
    bool PointInside(const idVec3& normal, const idVec3& point,
        float epsilon) const;
    void ReverseSelf();

    int GetNumPoints() const { return numPoints; }
    const idVec5& operator[](int index) const { return p[index]; }
    idVec5& operator[](int index) { return p[index]; }

    int numPoints;
    idVec5* p;
    int allocedSize;
};

class idFixedWinding : public idWinding {
public:
    idFixedWinding();
    idFixedWinding(const idFixedWinding& other);
    idFixedWinding& operator=(const idFixedWinding& other);
    ~idFixedWinding() override;
    void Clear() override;
    bool ReAllocate(int numPoints, bool keep = false) override;
    int SplitInPlace(const idPlane& plane, float epsilon,
        idFixedWinding* back);

    idVec5 data[64];
};

class idCarveWinding {
public:
    int otherPlaneNum;
    idList<int, TAG_AAS> edges;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idWinding) == 16, "Recovered idWinding ABI changed");
static_assert(sizeof(idFixedWinding) == 1296,
    "Recovered idFixedWinding ABI changed");
static_assert(sizeof(idCarveWinding) == 20,
    "Recovered idCarveWinding ABI changed");
#endif
