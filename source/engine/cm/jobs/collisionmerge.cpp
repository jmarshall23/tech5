#include "cm/jobs/collisionmerge.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

const queryResults_t* ResultAt(const queryResults_t* results,
    const int index, const int resultSize) {
    return reinterpret_cast<const queryResults_t*>(
        reinterpret_cast<const std::uint8_t*>(results) +
        static_cast<std::size_t>(index) * resultSize);
}

bool SameVertex(const idVec3& left, const idVec3& right) {
    return std::fabs(left.x - right.x) <= 0.1f &&
        std::fabs(left.y - right.y) <= 0.1f &&
        std::fabs(left.z - right.z) <= 0.1f;
}

bool SameTriangleCyclic(const std::int16_t* left,
    const std::int16_t* right) {
    return (left[0] == right[0] && left[1] == right[1] &&
               left[2] == right[2]) ||
        (left[0] == right[1] && left[1] == right[2] &&
            left[2] == right[0]) ||
        (left[0] == right[2] && left[1] == right[0] &&
            left[2] == right[1]);
}

} // namespace

void idCollisionDetectionMerge::MergeContentsResults(
    queryResults_t* const finalResult,
    const queryResults_t* const mergeResults, const int numMergeResults,
    const int resultSize) {
    if (numMergeResults <= 0) {
        return;
    }

    trace_t* const finalTrace =
        reinterpret_cast<trace_t*>(finalResult->data);
    *finalTrace = *reinterpret_cast<const trace_t*>(mergeResults->data);

    for (int index = 1; index < numMergeResults; ++index) {
        const trace_t& candidate = *reinterpret_cast<const trace_t*>(
            ResultAt(mergeResults, index, resultSize)->data);
        if (candidate.c.contentFlags != 0 &&
            finalTrace->c.contentFlags == 0) {
            *finalTrace = candidate;
        } else {
            finalTrace->c.contentFlags |= candidate.c.contentFlags;
        }
    }
}

void idCollisionDetectionMerge::MergeMotionResults(trace_t* const result,
    const trace_t* const rotation, const trace_t* const translation) {
    const idVec3 rotationEndPosition = rotation->endpos;
    const idMat3 rotationEndAxis = rotation->endAxis;
    const float fraction =
        (rotation->fraction + translation->fraction) * 0.5f;

    *result = rotation->fraction < 1.0f ? *rotation : *translation;
    result->fraction = fraction;
    result->endpos = rotationEndPosition;
    result->endAxis = rotationEndAxis;
}

void idCollisionDetectionMerge::MergeStepMoveResults(
    trace_t* const result, const trace_t* const down,
    const trace_t* const forward2, const trace_t* const forward1,
    const bool slideMove) {
    std::uint8_t flags = CONTACT_FLAG_NONE;
    if (down->fraction < 1.0f) {
        flags = CONTACT_FLAG_STEPMOVE_ONSOLID;
        if (down->c.normal.z > 0.70710677f) {
            flags |= CONTACT_FLAG_STEPMOVE_ONGROUND;
        }
    }

    if (slideMove &&
        (flags & CONTACT_FLAG_STEPMOVE_ONSOLID) != 0 &&
        (flags & CONTACT_FLAG_STEPMOVE_ONGROUND) == 0) {
        *result = *forward1;
        result->c.separation = 0.0f;
        return;
    }

    if (forward1->fraction >= 1.0f || forward2->fraction >= 1.0f) {
        result->fraction = 1.0f;
    } else {
        result->fraction =
            (1.0f - forward1->fraction) * forward2->fraction +
            forward1->fraction;
    }
    result->endpos = down->endpos;
    result->endAxis = down->endAxis;
    result->c = forward2->c;
    result->c.flags |= flags;
    result->c.separation = down->endpos.z - forward1->endpos.z;
}

bool ClipVelocity(idVec3& velocity, const idVec3* const planes,
    const int numPlanes) {
    for (int first = 0; first < numPlanes; ++first) {
        float into = velocity.Dot(planes[first]);
        if (into >= 0.05f) {
            continue;
        }
        const float firstScale = into >= 0.0f ? 0.99900097f : 1.001f;
        velocity = velocity - planes[first] * (into * firstScale);

        for (int second = 0; second < numPlanes; ++second) {
            if (second == first) {
                continue;
            }
            into = velocity.Dot(planes[second]);
            if (into >= 0.05f) {
                continue;
            }
            const float secondScale =
                into >= 0.0f ? 0.99900097f : 1.001f;
            velocity = velocity - planes[second] * (into * secondScale);
            if (velocity.Dot(planes[first]) >= 0.0f) {
                continue;
            }

            idVec3 crease = planes[first].Cross(planes[second]);
            if (crease.NormalizeFast() == 0.0f) {
                velocity.Zero();
                return true;
            }
            velocity = crease * velocity.Dot(crease);
            bool blocked = false;
            for (int third = 0; third < numPlanes; ++third) {
                if (third != first && third != second &&
                    velocity.Dot(planes[third]) < 0.05f) {
                    blocked = true;
                    break;
                }
            }
            if (blocked) {
                velocity.Zero();
                return true;
            }
        }
    }
    return false;
}

void idCollisionDetectionMerge::InitSlideMoveState(
    slideMoveState_t* const state, const idVec3& velocity,
    const idVec3& gravityVector) {
    state->velocity = velocity;
    state->endVelocity.Zero();
    std::memset(&state->firstContact, 0, sizeof(state->firstContact));
    state->fractionRemaining = 1.0f;
    state->steppedUp = 0.0f;
    state->startNormal = velocity;
    state->startNormal.NormalizeFast();
    state->numPlanes = 0;
    state->pad = 0;

    const float gravityLength = gravityVector.Length();
    if (gravityLength > 1.01f) {
        const float gravityScale = (gravityLength - 1.0f) / gravityLength;
        state->endVelocity = velocity + gravityVector * gravityScale;
        state->velocity = (velocity + state->endVelocity) * 0.5f;
    }
}

bool idCollisionDetectionMerge::UpdateSlideMoveState(
    slideMoveState_t* const state, trace_t* const trace) {
    state->fractionRemaining *= 1.0f - trace->fraction;
    state->steppedUp += trace->c.separation;
    if (trace->fraction >= 1.0f) {
        state->fractionRemaining = 0.0f;
        trace->c.flags |= CONTACT_FLAG_SLIDEMOVE_FINISHED;
        return true;
    }
    if (state->firstContact.type == CONTACT_NONE) {
        state->firstContact = trace->c;
    }

    bool duplicatePlane = false;
    for (int index = 0; index < state->numPlanes; ++index) {
        if (state->planes[index].Dot(trace->c.normal) > 0.99900001f) {
            const float into = state->velocity.Dot(trace->c.normal);
            const float scale = into >= 0.0f ? 0.99900097f : 1.001f;
            state->velocity = state->velocity -
                trace->c.normal * (into * scale);
            duplicatePlane = true;
            break;
        }
    }

    if (!duplicatePlane) {
        if (state->numPlanes >= 4) {
            state->fractionRemaining = 0.0f;
            state->velocity.Zero();
            trace->c.flags |= CONTACT_FLAG_SLIDEMOVE_FINISHED;
            return true;
        }
        state->planes[state->numPlanes++] = trace->c.normal;
        if (ClipVelocity(state->velocity, state->planes,
                state->numPlanes)) {
            state->fractionRemaining = 0.0f;
            state->velocity.Zero();
            trace->c.flags |= CONTACT_FLAG_SLIDEMOVE_FINISHED;
            return true;
        }
        if (state->startNormal.Dot(state->velocity) < 0.01f) {
            state->velocity = state->velocity - state->startNormal *
                state->velocity.Dot(state->startNormal);
        }
    }

    trace->c.normal = state->velocity;
    trace->c.dist = state->fractionRemaining;
    return false;
}

void idCollisionDetectionMerge::FinishSlideMoveState(
    slideMoveState_t* const state, trace_t* const trace) {
    if (state->velocity.LengthSqr() != 0.0f &&
        state->endVelocity.LengthSqr() != 0.0f) {
        ClipVelocity(state->endVelocity, state->planes,
            state->numPlanes);
        state->velocity = state->endVelocity;
    }
    trace->c = state->firstContact;
    trace->c.normal = state->velocity;
    trace->c.dist = state->fractionRemaining;
    trace->c.separation = state->steppedUp;
}

void idCollisionDetectionMerge::MergeTraceResults(
    queryResults_t* const finalResult,
    const queryResults_t* const mergeResults, const int numMergeResults,
    const int resultSize) {
    if (numMergeResults <= 0) {
        return;
    }

    trace_t* const finalTrace =
        reinterpret_cast<trace_t*>(finalResult->data);
    *finalTrace = *reinterpret_cast<const trace_t*>(mergeResults->data);
    for (int index = 1; index < numMergeResults; ++index) {
        const trace_t& candidate = *reinterpret_cast<const trace_t*>(
            ResultAt(mergeResults, index, resultSize)->data);
        if (candidate.fraction < finalTrace->fraction) {
            *finalTrace = candidate;
        }
    }
}

void idCollisionDetectionMerge::MergeContactsResults(
    queryResults_t* const finalResult,
    const queryResults_t* const mergeResults, const int numMergeResults,
    const int resultSize) {
    struct normalGroup_t {
        const contactInfo_t* contacts[12];
        int numContacts;
    } groups[12] = {};

    int numGroups = 0;
    for (int resultIndex = 0; resultIndex < numMergeResults;
         ++resultIndex) {
        const contactsResult_t& source =
            *reinterpret_cast<const contactsResult_t*>(
                ResultAt(mergeResults, resultIndex, resultSize)->data);
        const int sourceCount = (std::min)(source.numContacts, 12);
        for (int contactIndex = 0; contactIndex < sourceCount;
             ++contactIndex) {
            const contactInfo_t* const contact =
                &source.contacts[contactIndex];
            int groupIndex = 0;
            for (; groupIndex < numGroups; ++groupIndex) {
                if (groups[groupIndex].contacts[0]->normal.Dot(
                        contact->normal) > 0.90630776f) {
                    break;
                }
            }
            if (groupIndex == numGroups) {
                if (numGroups >= 12) {
                    continue;
                }
                groups[numGroups++].numContacts = 0;
            }
            normalGroup_t& group = groups[groupIndex];
            if (group.numContacts < 12) {
                group.contacts[group.numContacts++] = contact;
            }
        }
    }

    contactsResult_t& destination =
        *reinterpret_cast<contactsResult_t*>(finalResult->data);
    destination.numContacts = 0;
    for (int groupIndex = 0; groupIndex < numGroups; ++groupIndex) {
        const normalGroup_t& group = groups[groupIndex];
        const contactInfo_t* unique[12];
        int numUnique = 0;
        for (int contactIndex = 0; contactIndex < group.numContacts;
             ++contactIndex) {
            const contactInfo_t* const candidate =
                group.contacts[contactIndex];
            bool duplicate = false;
            for (int uniqueIndex = 0; uniqueIndex < numUnique;
                 ++uniqueIndex) {
                if ((candidate->point - unique[uniqueIndex]->point)
                        .LengthSqr() < 1.0f) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                unique[numUnique++] = candidate;
            }
        }

        int selected[3] = {0, 1, 2};
        int numSelected = numUnique;
        if (numUnique > 3) {
            float largestAreaSqr = 0.0f;
            for (int first = 0; first < numUnique - 2; ++first) {
                for (int second = first + 1; second < numUnique - 1;
                     ++second) {
                    for (int third = second + 1; third < numUnique;
                         ++third) {
                        const idVec3 side1 =
                            unique[second]->point - unique[first]->point;
                        const idVec3 side2 =
                            unique[third]->point - unique[first]->point;
                        const float areaSqr =
                            side1.Cross(side2).LengthSqr();
                        if (areaSqr > largestAreaSqr) {
                            largestAreaSqr = areaSqr;
                            selected[0] = first;
                            selected[1] = second;
                            selected[2] = third;
                        }
                    }
                }
            }
            numSelected = 3;
        }

        for (int uniqueIndex = 0; uniqueIndex < numUnique &&
             destination.numContacts < 12; ++uniqueIndex) {
            bool useContact = numUnique <= 3;
            if (numUnique > 3) {
                for (int selection = 0; selection < numSelected;
                     ++selection) {
                    useContact |= selected[selection] == uniqueIndex;
                }
            }
            if (useContact) {
                destination.contacts[destination.numContacts++] =
                    *unique[uniqueIndex];
            }
        }
    }
}

void idCollisionDetectionMerge::MergeClipResults(
    queryResults_t* const finalResult,
    const queryResults_t* const mergeResults, const int numMergeResults,
    const int resultSize) {
    if (numMergeResults <= 0) {
        return;
    }

    clipResult_t* const finalClip =
        reinterpret_cast<clipResult_t*>(finalResult->data);
    *finalClip = *reinterpret_cast<const clipResult_t*>(mergeResults->data);

    for (int resultIndex = 1; resultIndex < numMergeResults; ++resultIndex) {
        const clipResult_t& source =
            *reinterpret_cast<const clipResult_t*>(
                ResultAt(mergeResults, resultIndex, resultSize)->data);
        std::int16_t vertexRemap[32];
        for (int vertex = 0; vertex < source.numVerts && vertex < 32;
             ++vertex) {
            vertexRemap[vertex] = -1;
            for (int existing = 0; existing < finalClip->numVerts;
                 ++existing) {
                if (SameVertex(source.verts[vertex],
                        finalClip->verts[existing])) {
                    vertexRemap[vertex] = static_cast<std::int16_t>(existing);
                    break;
                }
            }
            if (vertexRemap[vertex] == -1 && finalClip->numVerts < 32) {
                vertexRemap[vertex] =
                    static_cast<std::int16_t>(finalClip->numVerts);
                finalClip->verts[finalClip->numVerts++] =
                    source.verts[vertex];
            }
        }

        for (int sourceIndex = 0;
             sourceIndex + 2 < source.numIndices && sourceIndex + 2 < 264;
             sourceIndex += 3) {
            const int sourceA = source.indices[sourceIndex];
            const int sourceB = source.indices[sourceIndex + 1];
            const int sourceC = source.indices[sourceIndex + 2];
            if (sourceA < 0 || sourceA >= 32 || sourceB < 0 ||
                sourceB >= 32 || sourceC < 0 || sourceC >= 32) {
                continue;
            }
            const std::int16_t candidate[3] = {
                vertexRemap[sourceA], vertexRemap[sourceB],
                vertexRemap[sourceC]};
            if (candidate[0] == -1 || candidate[1] == -1 ||
                candidate[2] == -1) {
                continue;
            }

            bool duplicate = false;
            for (int existing = 0; existing + 2 < finalClip->numIndices;
                 existing += 3) {
                if (SameTriangleCyclic(candidate,
                        &finalClip->indices[existing])) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate && finalClip->numIndices + 3 <= 264) {
                finalClip->indices[finalClip->numIndices++] = candidate[0];
                finalClip->indices[finalClip->numIndices++] = candidate[1];
                finalClip->indices[finalClip->numIndices++] = candidate[2];
            }
        }
    }
}

void idCollisionDetectionMerge::MergeQueryResults(
    queryResults_t* const finalResult, const int resultSize,
    const traceType_t type, const queryResults_t* const mergeResults,
    const int numMergeResults, slideMoveState_t* const slideMoveState,
    const dependencyType_t dependencyType,
    const queryResults_t* const dependency1,
    const queryResults_t* const dependency2) {
    switch (type) {
    case TRACE_CONTENTS:
    case TRACE_CONTENTS_POINT:
        MergeContentsResults(finalResult, mergeResults, numMergeResults,
            resultSize);
        break;
    case TRACE_CONTACTS_UNI_DIR:
    case TRACE_CONTACTS_OMNI_DIR:
        MergeContactsResults(finalResult, mergeResults, numMergeResults,
            resultSize);
        break;
    case TRACE_TRANSLATION:
    case TRACE_TRANSLATION_POINT:
    case TRACE_ROTATION:
    case TRACE_ROTATION_POINT:
        MergeTraceResults(finalResult, mergeResults, numMergeResults,
            resultSize);
        break;
    case TRACE_CLIP:
        MergeClipResults(finalResult, mergeResults, numMergeResults,
            resultSize);
        break;
    default:
        break;
    }

    switch (dependencyType) {
    case DEPENDENCY_MOTION_ROTATION:
        MergeMotionResults(
            reinterpret_cast<trace_t*>(finalResult->data),
            reinterpret_cast<const trace_t*>(finalResult->data),
            reinterpret_cast<const trace_t*>(dependency1->data));
        break;
    case DEPENDENCY_MOTION_CONTACTS: {
        const trace_t& motion =
            *reinterpret_cast<const trace_t*>(dependency1->data);
        contactsResult_t& contacts =
            *reinterpret_cast<contactsResult_t*>(finalResult->data);
        if (motion.fraction < 1.0f && contacts.numContacts == 0) {
            contacts.contacts[0] = motion.c;
            contacts.numContacts = 1;
        }
        break;
    }
    case DEPENDENCY_STEPMOVE_STEP_DOWN:
        MergeStepMoveResults(
            reinterpret_cast<trace_t*>(finalResult->data),
            reinterpret_cast<const trace_t*>(finalResult->data),
            reinterpret_cast<const trace_t*>(dependency1->data),
            reinterpret_cast<const trace_t*>(dependency2->data), false);
        break;
    case DEPENDENCY_SLIDEMOVE_STEP_UP_2:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_3:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_4:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_2:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_3:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_4:
    case DEPENDENCY_SLIDEMOVE_SLIDE:
        if (slideMoveState->fractionRemaining <= 0.0f) {
            reinterpret_cast<trace_t*>(finalResult->data)->c.flags |=
                CONTACT_FLAG_SLIDEMOVE_FINISHED;
        }
        break;
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_1:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_2:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_3:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_4: {
        trace_t* const trace =
            reinterpret_cast<trace_t*>(finalResult->data);
        MergeStepMoveResults(trace, trace,
            reinterpret_cast<const trace_t*>(dependency1->data),
            reinterpret_cast<const trace_t*>(dependency2->data), true);
        if (slideMoveState->fractionRemaining > 0.0f) {
            UpdateSlideMoveState(slideMoveState, trace);
        } else {
            trace->c.flags |= CONTACT_FLAG_SLIDEMOVE_FINISHED;
        }
        if (dependencyType == DEPENDENCY_SLIDEMOVE_STEP_DOWN_4) {
            FinishSlideMoveState(slideMoveState, trace);
        }
        break;
    }
    default:
        break;
    }

    finalResult->query.type = type;
    finalResult->query.done = 1;
    finalResult->query.merged = 1;
    finalResult->query.status = mergeResults->query.status;
}
