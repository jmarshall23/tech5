#include "cm/jobs/collisionquery.h"

#include "cm/jobs/polygonmodel/polygonmodel.h"
#include "cm/jobs/spheremodel/spheremodel.h"
#include "idlib/geometry/tracemodel.h"

#include <algorithm>
#include <cstring>

namespace {

idVec3 ModelToWorldVector(const idMat3& axis, const idVec3& value) {
    return idVec3(
        axis[0].x * value.x + axis[1].x * value.y + axis[2].x * value.z,
        axis[0].y * value.x + axis[1].y * value.y + axis[2].y * value.z,
        axis[0].z * value.x + axis[1].z * value.y + axis[2].z * value.z);
}

void FinishQuery(idTraceWork& tw, queryResults_t& results,
    const queryParms_t& parms) {
    if (results.query.status == QUERY_STATUS_PENDING) {
        results.query.status = QUERY_STATUS_SUCCESS;
    }
    for (int index = 0; index < 5; ++index) {
        results.query.profile[index] = static_cast<std::uint32_t>(
            tw.profile[index]);
    }
    results.query.type = parms.type;
    results.query.done = 1;
    results.query.merged = parms.autoMerge ? 1 : 0;
}

template <typename TraceFunction>
void ExecutePolygonOperation(idTraceWork& tw, queryResults_t& results,
    const queryParms_t& parms, const idTraceModel* trm,
    TraceFunction&& traceFunction) {
    trace_t startContents;
    if (parms.testQuery && trm != nullptr
        && (parms.type == TRACE_TRANSLATION
            || parms.type == TRACE_ROTATION)) {
        idPolygonModelCollisionDetection::StartContents(&tw, &startContents,
            parms.start, trm, parms.trmAxis, parms.contentMask,
            parms.modelOrigin, parms.modelAxis);
        traceFunction(tw);
        idPolygonModelCollisionDetection::FinishContents(&tw,
            parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
            parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
            parms.modelContentsOverride);
        if (startContents.c.contentFlags != 0) {
            results.query.status = static_cast<queryStatus_t>(
                results.query.status | QUERY_STATUS_BAD_START);
        }
    }

    switch (parms.type) {
    case TRACE_TRANSLATION:
        if (idPolygonModelCollisionDetection::StartTranslation(&tw,
                reinterpret_cast<trace_t*>(results.data), nullptr,
                parms.start, parms.end, trm, parms.trmAxis,
                parms.contentMask, parms.modelOrigin, parms.modelAxis)) {
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishTranslation(&tw,
                parms.start, parms.end, parms.modelOrigin, parms.modelAxis,
                parms.modelEntityNum, parms.modelPhysicsId,
                parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_TRANSLATION_POINT:
        if (idPolygonModelCollisionDetection::StartTranslationPoint(&tw,
                reinterpret_cast<trace_t*>(results.data), parms.start,
                parms.end, parms.contentMask, parms.modelOrigin,
                parms.modelAxis)) {
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishTranslation(&tw,
                parms.start, parms.end, parms.modelOrigin, parms.modelAxis,
                parms.modelEntityNum, parms.modelPhysicsId,
                parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_ROTATION:
        if (idPolygonModelCollisionDetection::StartRotation(&tw,
                reinterpret_cast<trace_t*>(results.data),
                parms.rotationOrigin, parms.rotationAxis,
                parms.rotationAngle, parms.start, trm, parms.trmAxis,
                parms.contentMask, parms.modelOrigin, parms.modelAxis)) {
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishRotation(&tw,
                parms.rotationOrigin, parms.rotationAxis,
                parms.rotationAngle, parms.start, parms.trmAxis,
                parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
                parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_ROTATION_POINT:
        if (idPolygonModelCollisionDetection::StartRotationPoint(&tw,
                reinterpret_cast<trace_t*>(results.data),
                parms.rotationOrigin, parms.rotationAxis,
                parms.rotationAngle, parms.start, parms.contentMask,
                parms.modelOrigin, parms.modelAxis)) {
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishRotation(&tw,
                parms.rotationOrigin, parms.rotationAxis,
                parms.rotationAngle, parms.start, parms.trmAxis,
                parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
                parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_CONTENTS:
        if (trm != nullptr) {
            idPolygonModelCollisionDetection::StartContents(&tw,
                reinterpret_cast<trace_t*>(results.data), parms.start,
                trm, parms.trmAxis, parms.contentMask, parms.modelOrigin,
                parms.modelAxis);
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishContents(&tw,
                parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
                parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_CONTENTS_POINT:
        idPolygonModelCollisionDetection::StartContentsPoint(&tw,
            reinterpret_cast<trace_t*>(results.data), parms.start,
            parms.contentMask, parms.modelOrigin, parms.modelAxis);
        traceFunction(tw);
        idPolygonModelCollisionDetection::FinishContents(&tw,
            parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
            parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
            parms.modelContentsOverride);
        break;
    case TRACE_CONTACTS_UNI_DIR:
    case TRACE_CONTACTS_OMNI_DIR:
        if (trm != nullptr) {
            contactsResult_t& contacts =
                *reinterpret_cast<contactsResult_t*>(results.data);
            contacts.numContacts = 0;
            idPolygonModelCollisionDetection::StartContacts(&tw, &contacts,
                parms.start, parms.dir, parms.depth, *trm,
                parms.trmAxis, parms.contentMask, parms.modelOrigin,
                parms.modelAxis);
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishContacts(&tw, 0,
                parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
                parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
                parms.modelContentsOverride);
        }
        break;
    case TRACE_CLIP:
        if (trm != nullptr) {
            clipResult_t& clip = *reinterpret_cast<clipResult_t*>(results.data);
            clip.numVerts = 0;
            clip.numIndices = 0;
            idPolygonModelCollisionDetection::StartClip(&tw, &clip,
                parms.start, *trm, parms.trmAxis, parms.contentMask,
                parms.modelOrigin, parms.modelAxis);
            traceFunction(tw);
            idPolygonModelCollisionDetection::FinishClip(&tw, 0,
                parms.modelOrigin, parms.modelAxis);
        }
        break;
    default:
        results.query.status = QUERY_STATUS_FAILED;
        break;
    }

    if (parms.testQuery && trm != nullptr
        && (parms.type == TRACE_TRANSLATION
            || parms.type == TRACE_ROTATION)) {
        const trace_t& motion = *reinterpret_cast<const trace_t*>(results.data);
        trace_t endContents;
        idPolygonModelCollisionDetection::StartContents(&tw, &endContents,
            motion.endpos, trm, motion.endAxis, parms.contentMask,
            parms.modelOrigin, parms.modelAxis);
        traceFunction(tw);
        idPolygonModelCollisionDetection::FinishContents(&tw,
            parms.modelOrigin, parms.modelAxis, parms.modelEntityNum,
            parms.modelPhysicsId, parms.modelBodyId, parms.selfId,
            parms.modelContentsOverride);
        if (endContents.c.contentFlags != 0) {
            results.query.status = static_cast<queryStatus_t>(
                results.query.status | QUERY_STATUS_FAILED);
        }
    }
    FinishQuery(tw, results, parms);
}

} // namespace

void idCollisionQueryExecute::ExecuteSubModelQuery(idTraceWork* const tw,
    queryResults_t& results, const queryParms_t* const parms,
    const idTraceModel* const trm,
    const cm_subModelData_t* const subModelData, const int subModelNum) {
    if (tw == nullptr || parms == nullptr || subModelData == nullptr) {
        results.query.status = QUERY_STATUS_FAILED;
        results.query.done = 1;
        return;
    }
    std::memset(tw->profile, 0, sizeof(tw->profile));
    ExecutePolygonOperation(*tw, results, *parms, trm,
        [subModelData, subModelNum](idTraceWork& work) {
            idPolygonModelCollisionDetection::TraceThroughSubModel(&work,
                subModelData, subModelNum);
        });
}

void idCollisionQueryExecute::ExecutePolygonModelQuery(idTraceWork* const tw,
    queryResults_t& results, const queryParms_t* const parms,
    const idTraceModel* const trm,
    const cm_polygonModel_t* const polygonModel) {
    if (tw == nullptr || parms == nullptr || polygonModel == nullptr) {
        results.query.status = QUERY_STATUS_FAILED;
        results.query.done = 1;
        return;
    }
    std::memset(tw->profile, 0, sizeof(tw->profile));
    ExecutePolygonOperation(*tw, results, *parms, trm,
        [polygonModel](idTraceWork& work) {
            idPolygonModelCollisionDetection::TraceThroughModel(&work,
                *polygonModel);
        });
}

void idCollisionQueryExecute::ExecuteSphereModelQuery(
    queryResults_t& results, const queryParms_t* const parms,
    const idJointMat* const modelJoints,
    const cm_sphereModel_t* const sphereModel) {
    if (parms == nullptr || sphereModel == nullptr) {
        results.query.status = QUERY_STATUS_FAILED;
        results.query.done = 1;
        return;
    }
    switch (parms->type) {
    case TRACE_TRANSLATION:
    case TRACE_TRANSLATION_POINT:
        idSphereModelCollisionDetection::TraceThroughModel(
            *reinterpret_cast<trace_t*>(results.data), *sphereModel,
            parms->start, parms->end, parms->depth, parms->trmAxis,
            modelJoints, parms->modelOrigin, parms->modelAxis,
            parms->modelEntityNum, parms->modelPhysicsId,
            parms->modelBodyId, parms->selfId,
            parms->modelContentsOverride);
        break;
    case TRACE_CONTACTS_UNI_DIR:
    case TRACE_CONTACTS_OMNI_DIR:
        reinterpret_cast<contactsResult_t*>(results.data)->numContacts = 0;
        break;
    case TRACE_CLIP:
        reinterpret_cast<clipResult_t*>(results.data)->numVerts = 0;
        reinterpret_cast<clipResult_t*>(results.data)->numIndices = 0;
        break;
    default: {
        trace_t& trace = *reinterpret_cast<trace_t*>(results.data);
        std::memset(&trace, 0, sizeof(trace));
        trace.fraction = 1.0f;
        trace.endpos = parms->end;
        trace.endAxis = parms->trmAxis;
        break;
    }
    }
    if (results.query.status == QUERY_STATUS_PENDING) {
        results.query.status = QUERY_STATUS_SUCCESS;
    }
    std::memset(results.query.profile, 0, sizeof(results.query.profile));
    results.query.type = parms->type;
    results.query.done = 1;
    results.query.merged = parms->autoMerge ? 1 : 0;
}

void idCollisionQueryExecute::SetupDependentParms(
    queryParms_t* const resultParms, const queryParms_t* const sourceParms,
    const queryResults_t* const modelPosition,
    const dependencyType_t dependencyType,
    const queryResults_t* const dependency1,
    const queryResults_t* const dependency2) {
    if (resultParms == nullptr || sourceParms == nullptr) {
        return;
    }
    *resultParms = *sourceParms;
    if (modelPosition != nullptr) {
        const trace_t& position =
            *reinterpret_cast<const trace_t*>(modelPosition->data);
        resultParms->modelOrigin = position.endpos;
        resultParms->modelAxis = position.endAxis;
    }
    const trace_t* const first = dependency1 != nullptr
        ? reinterpret_cast<const trace_t*>(dependency1->data) : nullptr;
    const trace_t* const second = dependency2 != nullptr
        ? reinterpret_cast<const trace_t*>(dependency2->data) : nullptr;
    if (first == nullptr && dependencyType != DEPENDENCY_NONE) {
        return;
    }
    switch (dependencyType) {
    case DEPENDENCY_NONE:
        break;
    case DEPENDENCY_MOTION_ROTATION:
        resultParms->start = first->endpos;
        resultParms->rotationOrigin = first->endpos;
        break;
    case DEPENDENCY_MOTION_CONTACTS:
        resultParms->start = first->endpos;
        resultParms->trmAxis = first->endAxis;
        break;
    case DEPENDENCY_STEPMOVE_STEP_UP:
    case DEPENDENCY_STEPMOVE_STEP_DOWN:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_1:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_2:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_3:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_4:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_1:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_2:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_3:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_4:
        resultParms->start = first->endpos;
        resultParms->end = (first->c.flags & CONTACT_FLAG_SLIDEMOVE_FINISHED)
            ? first->endpos
            : first->endpos + sourceParms->dir * sourceParms->depth;
        break;
    case DEPENDENCY_STEPMOVE_2ND_MOVE:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_1:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_2:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_3:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_4:
        resultParms->start = first->endpos;
        if (first->c.flags & CONTACT_FLAG_SLIDEMOVE_FINISHED) {
            resultParms->end = first->endpos;
        } else {
            idVec3 base = sourceParms->end;
            if (second != nullptr) {
                base = second->endpos
                    + second->c.normal * second->c.dist;
            }
            resultParms->end = base + sourceParms->dir
                * (sourceParms->depth * first->fraction);
        }
        break;
    case DEPENDENCY_STEPMOVE_CONTACTS:
    case DEPENDENCY_SLIDEMOVE_CONTACTS:
        resultParms->start = first->endpos;
        resultParms->end = first->endpos;
        break;
    case DEPENDENCY_SLIDEMOVE_SLIDE:
        resultParms->start = first->endpos;
        resultParms->end = (first->c.flags & CONTACT_FLAG_SLIDEMOVE_FINISHED)
            ? first->endpos
            : first->endpos + first->c.normal * first->c.dist;
        break;
    case DEPENDENCY_LOCAL_SPACE:
        resultParms->start = first->endpos
            + ModelToWorldVector(first->endAxis, sourceParms->start);
        resultParms->end = first->endpos
            + ModelToWorldVector(first->endAxis, sourceParms->end);
        resultParms->trmAxis = first->endAxis * sourceParms->trmAxis;
        break;
    default:
        break;
    }
}
