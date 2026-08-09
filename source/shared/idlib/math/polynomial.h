#pragma once

#include "idlib/math/complex.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <new>

class idPolynomial {
public:
    int degree;
    int allocated;
    float* coefficient;

    idPolynomial() : degree(-1), allocated(0), coefficient(nullptr) {}
    explicit idPolynomial(const int newDegree) : idPolynomial() { Zero(newDegree); }
    idPolynomial(const idPolynomial& other) : idPolynomial() { *this = other; }
    ~idPolynomial() { delete[] coefficient; }

    idPolynomial& operator=(const idPolynomial& other) {
        if (this != &other) {
            Resize(other.degree, false);
            std::copy(other.coefficient, other.coefficient + other.degree + 1,
                coefficient);
        }
        return *this;
    }

    float operator[](const int index) const {
        assert(index >= 0 && index <= degree); return coefficient[index];
    }
    float& operator[](const int index) {
        assert(index >= 0 && index <= degree); return coefficient[index];
    }
    void Zero() { if (coefficient != nullptr) std::fill(coefficient, coefficient + degree + 1, 0.0f); }
    void Zero(const int newDegree) { Resize(newDegree, false); Zero(); }
    int GetDimension() const { return degree + 1; }
    int GetDegree() const { return degree; }
    float GetValue(const float x) const {
        float result = 0.0f;
        for (int index = degree; index >= 0; --index) result = result * x + coefficient[index];
        return result;
    }
    idComplex GetValue(const idComplex& x) const {
        idComplex result(0.0f, 0.0f);
        for (int index = degree; index >= 0; --index)
            result = result * x + coefficient[index];
        return result;
    }
    idPolynomial GetDerivative() const {
        idPolynomial result((std::max)(degree - 1, 0));
        if (degree <= 0) { result[0] = 0.0f; return result; }
        for (int index = 1; index <= degree; ++index)
            result[index - 1] = coefficient[index] * static_cast<float>(index);
        return result;
    }
    idPolynomial GetAntiDerivative() const {
        idPolynomial result(degree + 1);
        result[0] = 0.0f;
        for (int index = 0; index <= degree; ++index)
            result[index + 1] = coefficient[index] / static_cast<float>(index + 1);
        return result;
    }
    bool Compare(const idPolynomial& other) const {
        if (degree != other.degree) return false;
        for (int index = 0; index <= degree; ++index)
            if (coefficient[index] != other.coefficient[index]) return false;
        return true;
    }
    bool Compare(const idPolynomial& other, const float epsilon) const {
        if (degree != other.degree) return false;
        for (int index = 0; index <= degree; ++index)
            if (std::fabs(coefficient[index] - other.coefficient[index]) > epsilon) return false;
        return true;
    }
    bool operator==(const idPolynomial& other) const { return Compare(other); }
    bool operator!=(const idPolynomial& other) const { return !Compare(other); }

private:
    void Resize(const int newDegree, const bool keep) {
        assert(newDegree >= 0);
        const int required = newDegree + 1;
        if (required > allocated) {
            const int newAllocated = (required + 3) & ~3;
            float* replacement = new float[newAllocated];
            std::fill(replacement, replacement + newAllocated, 0.0f);
            if (keep && coefficient != nullptr) {
                std::copy(coefficient,
                    coefficient + (std::min)(degree + 1, required), replacement);
            }
            delete[] coefficient;
            coefficient = replacement;
            allocated = newAllocated;
        } else if (!keep && coefficient != nullptr) {
            std::fill(coefficient, coefficient + allocated, 0.0f);
        }
        degree = newDegree;
    }
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPolynomial) == 12, "Recovered idPolynomial ABI changed");
#endif

