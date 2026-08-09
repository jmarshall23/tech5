#pragma once

#include "surface.h"

class alignas(4) idSurface_Patch : public idSurface {
public:
    idSurface_Patch();
    idSurface_Patch(const idSurface_Patch& other);
    ~idSurface_Patch();

    void SetSize(int patchWidth, int patchHeight);
    void Subdivide(float horizontalError, float verticalError,
        float maxLength, bool generateNormals);
    void SubdivideExplicit(int horizontalSubdivisions,
        int verticalSubdivisions, bool generateNormals,
        bool removeLinearColumnsRows);

    int width;
    int height;
    int maxWidth;
    int maxHeight;
    bool expanded;

private:
    void Collapse();
    void Expand();
    void GenerateIndexes();
    void GenerateNormals();
    void ProjectPointOntoVector(const idVec3& point,
        const idVec3& start, const idVec3& end, idVec3& projected);
    void PutOnCurve();
    void RemoveLinearColumnsRows();
    void ResizeExpanded(int newHeight, int newWidth);
    void SampleSinglePatch(const idDrawVert (*controlPoints)[3],
        int baseCol, int baseRow, int width, int height, int horzSub,
        idDrawVert* out) const;
    void SampleSinglePatchPoint(const idDrawVert (*controlPoints)[3],
        float u, float v, idDrawVert* out) const;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSurface_Patch) == 84,
    "Recovered idSurface_Patch ABI changed");
#endif
