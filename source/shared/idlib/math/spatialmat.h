#pragma once

#include "idlib/precompiled.h"

#include "spatialvec.h"

// Tungsten stores every spatial matrix in a six-row, eight-float-stride slab.
// The two padding floats per row are intentional: the Xenon implementation
// loads complete VMX vectors from each half-row.
class idSpatialMat {
public:
    static const int MAX_ROWS = 6;
    static const int MAX_COLUMNS = 6;
    static const int ROW_STRIDE = 8;

    idSpatialMat();
    idSpatialMat(int rows, int columns);
    idSpatialMat(const idSpatialMat& other);
    ~idSpatialMat();

    idSpatialMat& operator=(const idSpatialMat& other);

    void SetSize(int rows, int columns);
    void ChangeNumRows(int rows);
    void Zero(int rows, int columns);
    void Zero();
    void Set(const idMat3& m1, const idMat3& m2);
    void Set(const idMat3& m1, const idMat3& m2,
        const idMat3& m3, const idMat3& m4);
    void SetData(int rows, int columns, float* data);
    void Negate();

    void Transpose(idSpatialMat& dst) const;
    void Subtract(const idSpatialMat& other);

    void Multiply(idSpatialVec& dst, const idSpatialVec& vec) const;
    void MultiplyAdd(idSpatialVec& dst, const idSpatialVec& vec) const;
    void MultiplySub(idSpatialVec& dst, const idSpatialVec& vec) const;
    void TransposeMultiplyAdd(idSpatialVec& dst, const idSpatialVec& vec) const;
    void TransposeMultiplySub(idSpatialVec& dst, const idSpatialVec& vec) const;
    void Multiply(idSpatialMat& dst, const idSpatialMat& other) const;
    void TransposeMultiply(idSpatialMat& dst, const idSpatialMat& other) const;

    bool Inverse(idSpatialMat& dst) const;
    idSpatialVec SubSpatialVec(int row) const;

    int GetNumRows() const { return numRows; }
    int GetNumColumns() const { return numColumns; }
    int GetAllocatedRows() const { return allocatedRows; }
    float* ToFloatPtr() { return mat; }
    const float* ToFloatPtr() const { return mat; }

    float* operator[](int row) { return mat + row * ROW_STRIDE; }
    const float* operator[](int row) const { return mat + row * ROW_STRIDE; }
    float& operator()(int row, int column) { return mat[row * ROW_STRIDE + column]; }
    float operator()(int row, int column) const { return mat[row * ROW_STRIDE + column]; }

private:
    bool InverseNxN(idSpatialMat& dst, int dimension) const;
    bool Inverse1x1(idSpatialMat& dst) const;
    bool Inverse2x2(idSpatialMat& dst) const;
    bool Inverse3x3(idSpatialMat& dst) const;
    bool Inverse4x4(idSpatialMat& dst) const;
    bool Inverse5x5(idSpatialMat& dst) const;
    bool Inverse6x6(idSpatialMat& dst) const;
    void ClearPadding();

    int numRows;
    int numColumns;
    int allocatedRows;
    float* mat;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSpatialMat) == 16, "Recovered idSpatialMat ABI changed");
#endif

