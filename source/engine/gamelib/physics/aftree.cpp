#include "gamelib/physics/aftree.h"

#include "gamelib/physics/afbody.h"
#include "gamelib/physics/clipmodel.h"

#include <algorithm>

void GameLib_FactorAFConstraintTree(const idAFTree& tree);
void GameLib_SolveAFConstraintTree(const idAFTree& tree,
    int auxiliaryIndex);
void GameLib_CalculateAFConstraintResponse(const idAFTree& tree,
    const idAFConstraint* constraint, int row, int auxiliaryIndex);
void GameLib_AccumulateAFConstraintForces(const idAFTree& tree,
    float timeStep);
void GameLib_DrawAFBodyLink(const idVec3& parentOrigin,
    const idVec3& childOrigin, const idVec4& color);

idAFTree::idAFTree()
    : sortedBodies(4) {
}

void idAFTree::SortBodies_r(idList<idAFBody*, 71>& sortedList,
    idAFBody* const body) {
    if (body == nullptr) return;
    sortedList.Append(body);
    body->tree = this;
    for (int index = 0; index < body->children.Num(); ++index) {
        idAFBody* const child = body->children[index];
        if (child != nullptr) {
            child->parent = body;
            SortBodies_r(sortedList, child);
        }
    }
}

void idAFTree::SortBodies() {
    idList<idAFBody*, 71> original = sortedBodies;
    idList<idAFBody*, 71> ordered(4);
    for (int index = 0; index < original.Num(); ++index) {
        idAFBody* const body = original[index];
        if (body != nullptr && body->parent == nullptr) {
            SortBodies_r(ordered, body);
        }
    }
    // A malformed or partially deserialized graph may have no root. Preserve
    // every body once instead of silently dropping it.
    for (int index = 0; index < original.Num(); ++index) {
        idAFBody* const body = original[index];
        bool found = false;
        for (int sorted = 0; sorted < ordered.Num(); ++sorted)
            if (ordered[sorted] == body) { found = true; break; }
        if (!found && body != nullptr) ordered.Append(body);
    }
    sortedBodies = ordered;
}

void idAFTree::SetMaxSubTreeAuxiliaryIndex() {
    for (int index = sortedBodies.Num() - 1; index >= 0; --index) {
        idAFBody* const body = sortedBodies[index];
        if (body == nullptr) continue;
        body->maxSubTreeAuxiliaryIndex = body->maxAuxiliaryIndex;
        for (int childIndex = 0; childIndex < body->children.Num();
             ++childIndex) {
            const idAFBody* const child = body->children[childIndex];
            if (child != nullptr) {
                body->maxSubTreeAuxiliaryIndex = (std::max)(
                    body->maxSubTreeAuxiliaryIndex,
                    child->maxSubTreeAuxiliaryIndex);
            }
        }
    }
}

void idAFTree::Factor() const {
    GameLib_FactorAFConstraintTree(*this);
}

void idAFTree::Solve(const int auxiliaryIndex) const {
    GameLib_SolveAFConstraintTree(*this, auxiliaryIndex);
}

void idAFTree::Response(const idAFConstraint* const constraint,
    const int row, const int auxiliaryIndex) const {
    if (constraint != nullptr) {
        GameLib_CalculateAFConstraintResponse(*this, constraint, row,
            auxiliaryIndex);
    }
}

void idAFTree::CalculateForces(const float timeStep) const {
    if (timeStep <= 0.0f) return;
    for (int index = 0; index < sortedBodies.Num(); ++index) {
        idAFBody* const body = sortedBodies[index];
        if (body == nullptr) continue;
        for (int component = 0; component < 6; ++component) {
            body->totalForce[component] =
                body->current.externalForce[component] +
                body->auxForce[component];
        }
        body->inverseWorldSpatialInertia.Multiply(body->acceleration,
            body->totalForce);
        const float inverseTimeStep = 1.0f / timeStep;
        for (int component = 0; component < 6; ++component) {
            body->acceleration[component] +=
                body->current.spatialVelocity[component] * inverseTimeStep;
            body->s[component] = 0.0f;
        }
        body->fl.isZero = 1;
    }
    GameLib_AccumulateAFConstraintForces(*this, timeStep);
}

void idAFTree::DebugDraw(const idVec4& color) const {
    for (int index = 1; index < sortedBodies.Num(); ++index) {
        const idAFBody* const body = sortedBodies[index];
        if (body == nullptr || body->parent == nullptr ||
            body->clipModel == nullptr || body->parent->clipModel == nullptr) {
            continue;
        }
        GameLib_DrawAFBodyLink(body->parent->clipModel->GetOrigin(),
            body->clipModel->GetOrigin(), color);
    }
}
