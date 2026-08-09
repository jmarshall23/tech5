#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idAFBody;
class idAFConstraint;

class idAFTree {
public:
    idAFTree();

    void SortBodies();
    void SetMaxSubTreeAuxiliaryIndex();
    void Factor() const;
    void Solve(int auxiliaryIndex) const;
    void Response(const idAFConstraint* constraint, int row,
        int auxiliaryIndex) const;
    void CalculateForces(float timeStep) const;
    void DebugDraw(const idVec4& color) const;

    idList<idAFBody*, 71> sortedBodies;

private:
    void SortBodies_r(idList<idAFBody*, 71>& sortedList,
        idAFBody* body);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAFTree) == 16,
    "Recovered idAFTree ABI changed");
#endif
