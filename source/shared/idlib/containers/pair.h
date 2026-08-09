#pragma once

// Generic form inferred from the ten concrete layouts in the recovered PDB.
// Keeping the fields public also matches all recovered direct member access.
template<typename firstType, typename secondType>
class idPair {
public:
    firstType first;
    secondType second;

    idPair() = default;

    idPair(const firstType& firstValue, const secondType& secondValue)
        : first(firstValue)
        , second(secondValue) {
    }
};

