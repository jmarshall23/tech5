#include "spatialmat.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <malloc.h>

namespace {

constexpr std::size_t SPATIAL_MAT_FLOATS =
    idSpatialMat::MAX_ROWS * idSpatialMat::ROW_STRIDE;
constexpr std::size_t SPATIAL_MAT_BYTES =
    SPATIAL_MAT_FLOATS * sizeof(float);

float* AllocSpatialMat() {
    return static_cast<float*>(_aligned_malloc(SPATIAL_MAT_BYTES, 16));
}

bool IsValidSize(const int rows, const int columns) {
    return rows >= 0 && rows <= idSpatialMat::MAX_ROWS
        && columns >= 0 && columns <= idSpatialMat::MAX_COLUMNS;
}

} // namespace

idSpatialMat::idSpatialMat()
    : numRows(0), numColumns(0), allocatedRows(0), mat(nullptr) {
}

idSpatialMat::idSpatialMat(const int rows, const int columns)
    : idSpatialMat() {
    SetSize(rows, columns);
}

idSpatialMat::idSpatialMat(const idSpatialMat& other)
    : idSpatialMat() {
    *this = other;
}

idSpatialMat::~idSpatialMat() {
    if (mat != nullptr && allocatedRows > 0) {
        _aligned_free(mat);
    }
}

idSpatialMat& idSpatialMat::operator=(const idSpatialMat& other) {
    if (this == &other) {
        return *this;
    }
    SetSize(other.numRows, other.numColumns);
    if (mat != nullptr && other.mat != nullptr) {
        std::memcpy(mat, other.mat, SPATIAL_MAT_BYTES);
    }
    return *this;
}

void idSpatialMat::SetSize(const int rows, const int columns) {
    if (!IsValidSize(rows, columns)) {
        numRows = 0;
        numColumns = 0;
        return;
    }
    if (mat == nullptr) {
        mat = AllocSpatialMat();
        if (mat == nullptr) {
            numRows = 0;
            numColumns = 0;
            allocatedRows = 0;
            return;
        }
        allocatedRows = MAX_ROWS;
        std::memset(mat, 0, SPATIAL_MAT_BYTES);
    }
    numRows = rows;
    numColumns = columns;
    ClearPadding();
}

void idSpatialMat::ChangeNumRows(const int rows) {
    if (rows < 0 || rows > MAX_ROWS || mat == nullptr) {
        return;
    }
    if (rows != numRows) {
        const int firstClearedRow = std::min(rows, numRows);
        const int rowCount = std::max(rows, numRows) - firstClearedRow;
        if (rowCount > 0) {
            std::memset(mat + firstClearedRow * ROW_STRIDE, 0,
                static_cast<std::size_t>(rowCount * ROW_STRIDE) * sizeof(float));
        }
        numRows = rows;
    }
}

void idSpatialMat::Zero(const int rows, const int columns) {
    SetSize(rows, columns);
    Zero();
}

void idSpatialMat::Zero() {
    if (mat != nullptr) {
        std::memset(mat, 0, SPATIAL_MAT_BYTES);
    }
}

void idSpatialMat::Set(const idMat3& m1, const idMat3& m2) {
    SetSize(3, 6);
    if (mat == nullptr) {
        return;
    }
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            (*this)(row, column) = m1[row][column];
            (*this)(row, column + 3) = m2[row][column];
        }
    }
}

void idSpatialMat::Set(const idMat3& m1, const idMat3& m2,
        const idMat3& m3, const idMat3& m4) {
    SetSize(6, 6);
    if (mat == nullptr) {
        return;
    }
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            (*this)(row, column) = m1[row][column];
            (*this)(row, column + 3) = m2[row][column];
            (*this)(row + 3, column) = m3[row][column];
            (*this)(row + 3, column + 3) = m4[row][column];
        }
    }
}

void idSpatialMat::SetData(const int rows, const int columns, float* data) {
    if (!IsValidSize(rows, columns) || data == nullptr) {
        return;
    }
    if (mat != nullptr && allocatedRows > 0) {
        _aligned_free(mat);
    }
    numRows = rows;
    numColumns = columns;
    allocatedRows = -MAX_ROWS;
    mat = data;
    ClearPadding();
}

void idSpatialMat::ClearPadding() {
    if (mat == nullptr) {
        return;
    }
    for (int row = 0; row < MAX_ROWS; ++row) {
        const int first = row < numRows ? numColumns : 0;
        std::fill(mat + row * ROW_STRIDE + first,
            mat + (row + 1) * ROW_STRIDE, 0.0f);
    }
}

void idSpatialMat::Negate() {
    if (mat == nullptr) {
        return;
    }
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < ROW_STRIDE; ++column) {
            (*this)[row][column] = -(*this)[row][column];
        }
    }
}

void idSpatialMat::Transpose(idSpatialMat& dst) const {
    float values[MAX_ROWS][MAX_COLUMNS] = {};
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < numColumns; ++column) {
            values[column][row] = (*this)(row, column);
        }
    }
    dst.Zero(numColumns, numRows);
    for (int row = 0; row < numColumns; ++row) {
        for (int column = 0; column < numRows; ++column) {
            dst(row, column) = values[row][column];
        }
    }
}

void idSpatialMat::Subtract(const idSpatialMat& other) {
    if (mat == nullptr || other.mat == nullptr
            || numRows != other.numRows || numColumns != other.numColumns) {
        return;
    }
    for (int index = 0; index < MAX_ROWS * ROW_STRIDE; ++index) {
        mat[index] -= other.mat[index];
    }
}

void idSpatialMat::Multiply(idSpatialVec& dst, const idSpatialVec& vec) const {
    float result[MAX_ROWS] = {};
    const int terms = std::min(numColumns, vec.GetSize());
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < terms; ++column) {
            result[row] += (*this)(row, column) * vec[column];
        }
    }
    dst.SetSize(numRows);
    for (int row = 0; row < numRows; ++row) {
        dst[row] = result[row];
    }
}

void idSpatialMat::MultiplyAdd(idSpatialVec& dst, const idSpatialVec& vec) const {
    if (dst.GetSize() < numRows) {
        dst.SetSize(numRows);
    }
    const int terms = std::min(numColumns, vec.GetSize());
    for (int row = 0; row < numRows; ++row) {
        float value = 0.0f;
        for (int column = 0; column < terms; ++column) {
            value += (*this)(row, column) * vec[column];
        }
        dst[row] += value;
    }
}

void idSpatialMat::MultiplySub(idSpatialVec& dst, const idSpatialVec& vec) const {
    if (dst.GetSize() < numRows) {
        dst.SetSize(numRows);
    }
    const int terms = std::min(numColumns, vec.GetSize());
    for (int row = 0; row < numRows; ++row) {
        float value = 0.0f;
        for (int column = 0; column < terms; ++column) {
            value += (*this)(row, column) * vec[column];
        }
        dst[row] -= value;
    }
}

void idSpatialMat::TransposeMultiplyAdd(idSpatialVec& dst,
        const idSpatialVec& vec) const {
    if (dst.GetSize() < numColumns) {
        dst.SetSize(numColumns);
    }
    const int terms = std::min(numRows, vec.GetSize());
    for (int column = 0; column < numColumns; ++column) {
        float value = 0.0f;
        for (int row = 0; row < terms; ++row) {
            value += (*this)(row, column) * vec[row];
        }
        dst[column] += value;
    }
}

void idSpatialMat::TransposeMultiplySub(idSpatialVec& dst,
        const idSpatialVec& vec) const {
    if (dst.GetSize() < numColumns) {
        dst.SetSize(numColumns);
    }
    const int terms = std::min(numRows, vec.GetSize());
    for (int column = 0; column < numColumns; ++column) {
        float value = 0.0f;
        for (int row = 0; row < terms; ++row) {
            value += (*this)(row, column) * vec[row];
        }
        dst[column] -= value;
    }
}

void idSpatialMat::Multiply(idSpatialMat& dst,
        const idSpatialMat& other) const {
    if (numColumns != other.numRows) {
        dst.Zero(0, 0);
        return;
    }
    float values[MAX_ROWS][MAX_COLUMNS] = {};
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < other.numColumns; ++column) {
            for (int term = 0; term < numColumns; ++term) {
                values[row][column] +=
                    (*this)(row, term) * other(term, column);
            }
        }
    }
    dst.Zero(numRows, other.numColumns);
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < other.numColumns; ++column) {
            dst(row, column) = values[row][column];
        }
    }
}

void idSpatialMat::TransposeMultiply(idSpatialMat& dst,
        const idSpatialMat& other) const {
    if (numRows != other.numRows) {
        dst.Zero(0, 0);
        return;
    }
    float values[MAX_ROWS][MAX_COLUMNS] = {};
    for (int row = 0; row < numColumns; ++row) {
        for (int column = 0; column < other.numColumns; ++column) {
            for (int term = 0; term < numRows; ++term) {
                values[row][column] +=
                    (*this)(term, row) * other(term, column);
            }
        }
    }
    dst.Zero(numColumns, other.numColumns);
    for (int row = 0; row < numColumns; ++row) {
        for (int column = 0; column < other.numColumns; ++column) {
            dst(row, column) = values[row][column];
        }
    }
}

bool idSpatialMat::Inverse(idSpatialMat& dst) const {
    if (numRows != numColumns || numRows < 1 || numRows > MAX_ROWS) {
        return false;
    }
    switch (numRows) {
        case 1: return Inverse1x1(dst);
        case 2: return Inverse2x2(dst);
        case 3: return Inverse3x3(dst);
        case 4: return Inverse4x4(dst);
        case 5: return Inverse5x5(dst);
        case 6: return Inverse6x6(dst);
        default: return false;
    }
}

bool idSpatialMat::InverseNxN(idSpatialMat& dst, const int dimension) const {
    double work[MAX_ROWS][MAX_ROWS * 2] = {};
    for (int row = 0; row < dimension; ++row) {
        for (int column = 0; column < dimension; ++column) {
            work[row][column] = (*this)(row, column);
        }
        work[row][dimension + row] = 1.0;
    }

    for (int pivotColumn = 0; pivotColumn < dimension; ++pivotColumn) {
        int pivotRow = pivotColumn;
        for (int row = pivotColumn + 1; row < dimension; ++row) {
            if (std::fabs(work[row][pivotColumn])
                    > std::fabs(work[pivotRow][pivotColumn])) {
                pivotRow = row;
            }
        }
        if (std::fabs(work[pivotRow][pivotColumn]) < 1.0e-14) {
            return false;
        }
        if (pivotRow != pivotColumn) {
            for (int column = 0; column < dimension * 2; ++column) {
                std::swap(work[pivotRow][column], work[pivotColumn][column]);
            }
        }
        const double reciprocal = 1.0 / work[pivotColumn][pivotColumn];
        for (int column = 0; column < dimension * 2; ++column) {
            work[pivotColumn][column] *= reciprocal;
        }
        for (int row = 0; row < dimension; ++row) {
            if (row == pivotColumn) {
                continue;
            }
            const double scale = work[row][pivotColumn];
            for (int column = 0; column < dimension * 2; ++column) {
                work[row][column] -= scale * work[pivotColumn][column];
            }
        }
    }

    dst.Zero(dimension, dimension);
    for (int row = 0; row < dimension; ++row) {
        for (int column = 0; column < dimension; ++column) {
            dst(row, column) = static_cast<float>(work[row][dimension + column]);
        }
    }
    return true;
}

bool idSpatialMat::Inverse1x1(idSpatialMat& dst) const { return InverseNxN(dst, 1); }
bool idSpatialMat::Inverse2x2(idSpatialMat& dst) const { return InverseNxN(dst, 2); }
bool idSpatialMat::Inverse3x3(idSpatialMat& dst) const { return InverseNxN(dst, 3); }
bool idSpatialMat::Inverse4x4(idSpatialMat& dst) const { return InverseNxN(dst, 4); }
bool idSpatialMat::Inverse5x5(idSpatialMat& dst) const { return InverseNxN(dst, 5); }
bool idSpatialMat::Inverse6x6(idSpatialMat& dst) const { return InverseNxN(dst, 6); }

idSpatialVec idSpatialMat::SubSpatialVec(const int row) const {
    idSpatialVec result;
    if (mat != nullptr && row >= 0 && row < numRows) {
        result.SetData(MAX_COLUMNS, mat + row * ROW_STRIDE);
    }
    return result;
}

