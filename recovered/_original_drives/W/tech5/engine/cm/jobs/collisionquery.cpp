
// ========================================================================
// ?ExecuteSubModelQuery@idCollisionQueryExecute@@SAXPAVidTraceWork@@AAUqueryResults_t@@PBUqueryParms_t@@PBVidTraceModel@@PBUcm_subModelData_t@@H@Z
// EA  : 0x825E56F0
// RVA : 0x005E56F0
// PDB : w:\tech5\engine\cm\jobs\collisionquery.cpp
// ========================================================================

void __fastcall idCollisionQueryExecute::ExecuteSubModelQuery(
        idTraceWork *tw,
        queryResults_t *results,
        const queryParms_t *parms,
        const idTraceModel *trm,
        const cm_subModelData_t *subModelData,
        int subModelNum)
{
  const idMat3 *v13; // [sp+8h] [-888h]
  int v14; // [sp+8h] [-888h]
  int v15; // [sp+8h] [-888h]
  const idMat3 *v16; // [sp+Ch] [-884h]
  int v17; // [sp+Ch] [-884h]
  int v18; // [sp+10h] [-880h]
  int v19; // [sp+14h] [-87Ch]
  trace_t v20; // [sp+B0h] [-7E0h] BYREF
  trace_t v21; // [sp+480h] [-410h] BYREF

  tw->profile[0] = 0;
  tw->profile[1] = 0;
  tw->profile[2] = 0;
  tw->profile[3] = 0;
  tw->profile[4] = 0;
  if ( parms->testQuery && (parms->type == TRACE_TRANSLATION || parms->type == TRACE_ROTATION) )
  {
    idPolygonModelCollisionDetection::StartContents(
      tw,
      result: &v20,
      start: &parms->start,
      trm,
      trmAxis: &parms->trmAxis,
      contentMask: parms->contentMask,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis);
    idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
    idPolygonModelCollisionDetection::FinishContents(
      tw,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis,
      modelEntityNum: parms->modelEntityNum,
      modelPhysicsId: parms->modelPhysicsId,
      modelId: parms->modelBodyId,
      selfId: parms->selfId,
      modelContentsOverride: parms->modelContentsOverride);
    if ( v20.c.contentFlags != 0 )
      results->query.status |= 2u;
  }
  if ( (unsigned int)(parms->type - 1) <= 8 )
  {
    if ( parms->type == TRACE_TRANSLATION_POINT )
    {
      if ( !idPolygonModelCollisionDetection::StartTranslationPoint(
              tw,
              result: (trace_t *)results->data,
              start: &parms->start,
              end: &parms->end,
              contentMask: parms->contentMask,
              modelOrigin: &parms->modelOrigin,
              modelAxis: &parms->modelAxis) )
        goto LABEL_28;
      goto LABEL_19;
    }
    if ( parms->type == TRACE_ROTATION )
    {
      if ( idPolygonModelCollisionDetection::StartRotation(
             tw,
             result: (trace_t *)results->data,
             rorg: &parms->rotationOrigin,
             axis: &parms->rotationAxis,
             angle: parms->rotationAngle,
             start: (const idVec3 *)subModelData,
             trm: (const idTraceModel *)&parms->start,
             trmAxis: (const idMat3 *)trm,
             contentMask: (int)&parms->trmAxis,
             modelOrigin: v13->mat,
             modelAxis: v16) )
      {
        idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
        idPolygonModelCollisionDetection::FinishRotation(
          tw,
          rorg: &parms->rotationOrigin,
          axis: &parms->rotationAxis,
          angle: parms->rotationAngle,
          start: (const idVec3 *)parms->selfId,
          trmAxis: (const idMat3 *)&parms->start,
          modelOrigin: parms->trmAxis.mat,
          modelAxis: (const idMat3 *)&parms->modelOrigin,
          modelEntityNum: (int)&parms->modelAxis,
          modelPhysicsId: v14,
          modelBodyId: v17,
          selfId: v18,
          modelContentsOverride: v19);
      }
      goto LABEL_28;
    }
    if ( parms->type != TRACE_ROTATION_POINT )
    {
      switch ( parms->type )
      {
        case TRACE_CONTENTS:
          idPolygonModelCollisionDetection::StartContents(
            tw,
            result: (trace_t *)results->data,
            start: &parms->start,
            trm,
            trmAxis: &parms->trmAxis,
            contentMask: parms->contentMask,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis);
          idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
          idPolygonModelCollisionDetection::FinishContents(
            tw,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: parms->modelContentsOverride);
          goto LABEL_28;
        case TRACE_CONTENTS_POINT:
          idPolygonModelCollisionDetection::StartContentsPoint(
            tw,
            result: (trace_t *)results->data,
            start: &parms->start,
            contentMask: parms->contentMask,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis);
          idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
          idPolygonModelCollisionDetection::FinishContents(
            tw,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: parms->modelContentsOverride);
          goto LABEL_28;
        case TRACE_CONTACTS_UNI_DIR:
        case TRACE_CONTACTS_OMNI_DIR:
          *(_DWORD *)results->data = 0;
          idPolygonModelCollisionDetection::StartContacts(
            tw,
            result: (contactsResult_t *)results->data,
            start: &parms->start,
            dir: &parms->dir,
            depth: parms->depth,
            trm: (const idTraceModel *)subModelData,
            trmAxis: (const idMat3 *)trm,
            contentMask: (int)&parms->trmAxis,
            modelOrigin: (const idVec3 *)parms->contentMask,
            modelAxis: v13);
          idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
          idPolygonModelCollisionDetection::FinishContacts(
            tw,
            firstContact: 0,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelBodyId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: v15);
          goto LABEL_28;
        default:
          break;
      }
      if ( parms->type != TRACE_TRANSLATION )
      {
        *(_DWORD *)results->data = 0;
        *(_DWORD *)&results->data[4] = 0;
        idPolygonModelCollisionDetection::StartClip(
          tw,
          result: (clipResult_t *)results->data,
          start: &parms->start,
          trm,
          trmAxis: &parms->trmAxis,
          contentMask: parms->contentMask,
          modelOrigin: &parms->modelOrigin,
          modelAxis: &parms->modelAxis);
        idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
        idPolygonModelCollisionDetection::FinishClip(
          tw,
          firstClipVert: 0,
          modelOrigin: &parms->modelOrigin,
          modelAxis: &parms->modelAxis);
        goto LABEL_28;
      }
      if ( !idPolygonModelCollisionDetection::StartTranslation(
              tw,
              result: (trace_t *)results->data,
              contacts: nullptr,
              start: &parms->start,
              end: &parms->end,
              trm,
              trmAxis: &parms->trmAxis,
              contentMask: parms->contentMask,
              modelOrigin: v13->mat,
              modelAxis: v16) )
        goto LABEL_28;
LABEL_19:
      idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
      idPolygonModelCollisionDetection::FinishTranslation(
        tw,
        start: &parms->start,
        end: &parms->end,
        modelOrigin: &parms->modelOrigin,
        modelAxis: &parms->modelAxis,
        modelEntityNum: parms->modelEntityNum,
        modelPhysicsId: parms->modelPhysicsId,
        modelBodyId: parms->modelBodyId,
        selfId: (int)v13,
        modelContentsOverride: (int)v16);
      goto LABEL_28;
    }
    if ( idPolygonModelCollisionDetection::StartRotationPoint(
           tw,
           result: (trace_t *)results->data,
           rorg: &parms->rotationOrigin,
           axis: &parms->rotationAxis,
           angle: parms->rotationAngle,
           start: (const idVec3 *)subModelData,
           contentMask: (int)&parms->start,
           modelOrigin: (const idVec3 *)parms->contentMask,
           modelAxis: (const idMat3 *)&parms->modelOrigin) )
    {
      idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
      idPolygonModelCollisionDetection::FinishRotation(
        tw,
        rorg: &parms->rotationOrigin,
        axis: &parms->rotationAxis,
        angle: parms->rotationAngle,
        start: (const idVec3 *)parms->modelPhysicsId,
        trmAxis: (const idMat3 *)&parms->start,
        modelOrigin: parms->trmAxis.mat,
        modelAxis: (const idMat3 *)&parms->modelOrigin,
        modelEntityNum: (int)&parms->modelAxis,
        modelPhysicsId: (int)v13,
        modelBodyId: (int)v16,
        selfId: v18,
        modelContentsOverride: v19);
    }
  }
LABEL_28:
  if ( parms->testQuery && (parms->type == TRACE_TRANSLATION || parms->type == TRACE_ROTATION) )
  {
    idPolygonModelCollisionDetection::StartContents(
      tw,
      result: &v21,
      start: (const idVec3 *)&results->data[4],
      trm,
      trmAxis: (const idMat3 *)&results->data[16],
      contentMask: parms->contentMask,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis);
    idPolygonModelCollisionDetection::TraceThroughSubModel(tw, subModelData, subModelNum);
    idPolygonModelCollisionDetection::FinishContents(
      tw,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis,
      modelEntityNum: parms->modelEntityNum,
      modelPhysicsId: parms->modelPhysicsId,
      modelId: parms->modelBodyId,
      selfId: parms->selfId,
      modelContentsOverride: parms->modelContentsOverride);
    if ( v21.c.contentFlags != 0 )
      results->query.status |= 4u;
  }
  if ( results->query.status == QUERY_STATUS_PENDING )
    results->query.status = QUERY_STATUS_SUCCESS;
  results->query.profile[0] = tw->profile[0];
  results->query.profile[1] = tw->profile[1];
  results->query.profile[2] = tw->profile[2];
  results->query.profile[3] = tw->profile[3];
  results->query.profile[4] = tw->profile[4];
  results->query.type = parms->type;
  results->query.done = 1;
  results->query.merged = parms->autoMerge;
}


// ========================================================================
// ?ExecutePolygonModelQuery@idCollisionQueryExecute@@SAXPAVidTraceWork@@AAUqueryResults_t@@PBUqueryParms_t@@PBVidTraceModel@@PBUcm_polygonModel_t@@@Z
// EA  : 0x825E5CF0
// RVA : 0x005E5CF0
// PDB : w:\tech5\engine\cm\jobs\collisionquery.cpp
// ========================================================================

void __fastcall idCollisionQueryExecute::ExecutePolygonModelQuery(
        idTraceWork *tw,
        queryResults_t *results,
        const queryParms_t *parms,
        const idTraceModel *trm,
        const cm_polygonModel_t *polygonModel)
{
  const idMat3 *v11; // [sp+8h] [-878h]
  int v12; // [sp+8h] [-878h]
  int v13; // [sp+8h] [-878h]
  const idMat3 *v14; // [sp+Ch] [-874h]
  int v15; // [sp+Ch] [-874h]
  int v16; // [sp+10h] [-870h]
  int v17; // [sp+14h] [-86Ch]
  trace_t v18; // [sp+B0h] [-7D0h] BYREF
  trace_t v19; // [sp+480h] [-400h] BYREF

  tw->profile[0] = 0;
  tw->profile[1] = 0;
  tw->profile[2] = 0;
  tw->profile[3] = 0;
  tw->profile[4] = 0;
  if ( parms->testQuery && (parms->type == TRACE_TRANSLATION || parms->type == TRACE_ROTATION) )
  {
    idPolygonModelCollisionDetection::StartContents(
      tw,
      result: &v18,
      start: &parms->start,
      trm,
      trmAxis: &parms->trmAxis,
      contentMask: parms->contentMask,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis);
    idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
    idPolygonModelCollisionDetection::FinishContents(
      tw,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis,
      modelEntityNum: parms->modelEntityNum,
      modelPhysicsId: parms->modelPhysicsId,
      modelId: parms->modelBodyId,
      selfId: parms->selfId,
      modelContentsOverride: parms->modelContentsOverride);
    if ( v18.c.contentFlags != 0 )
      results->query.status |= 2u;
  }
  if ( (unsigned int)(parms->type - 1) <= 8 )
  {
    if ( parms->type == TRACE_TRANSLATION_POINT )
    {
      if ( !idPolygonModelCollisionDetection::StartTranslationPoint(
              tw,
              result: (trace_t *)results->data,
              start: &parms->start,
              end: &parms->end,
              contentMask: parms->contentMask,
              modelOrigin: &parms->modelOrigin,
              modelAxis: &parms->modelAxis) )
        goto LABEL_28;
      goto LABEL_19;
    }
    if ( parms->type == TRACE_ROTATION )
    {
      if ( idPolygonModelCollisionDetection::StartRotation(
             tw,
             result: (trace_t *)results->data,
             rorg: &parms->rotationOrigin,
             axis: &parms->rotationAxis,
             angle: parms->rotationAngle,
             start: (const idVec3 *)polygonModel,
             trm: (const idTraceModel *)&parms->start,
             trmAxis: (const idMat3 *)trm,
             contentMask: (int)&parms->trmAxis,
             modelOrigin: v11->mat,
             modelAxis: v14) )
      {
        idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
        idPolygonModelCollisionDetection::FinishRotation(
          tw,
          rorg: &parms->rotationOrigin,
          axis: &parms->rotationAxis,
          angle: parms->rotationAngle,
          start: (const idVec3 *)parms->selfId,
          trmAxis: (const idMat3 *)&parms->start,
          modelOrigin: parms->trmAxis.mat,
          modelAxis: (const idMat3 *)&parms->modelOrigin,
          modelEntityNum: (int)&parms->modelAxis,
          modelPhysicsId: v12,
          modelBodyId: v15,
          selfId: v16,
          modelContentsOverride: v17);
      }
      goto LABEL_28;
    }
    if ( parms->type != TRACE_ROTATION_POINT )
    {
      switch ( parms->type )
      {
        case TRACE_CONTENTS:
          idPolygonModelCollisionDetection::StartContents(
            tw,
            result: (trace_t *)results->data,
            start: &parms->start,
            trm,
            trmAxis: &parms->trmAxis,
            contentMask: parms->contentMask,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis);
          idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
          idPolygonModelCollisionDetection::FinishContents(
            tw,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: parms->modelContentsOverride);
          goto LABEL_28;
        case TRACE_CONTENTS_POINT:
          idPolygonModelCollisionDetection::StartContentsPoint(
            tw,
            result: (trace_t *)results->data,
            start: &parms->start,
            contentMask: parms->contentMask,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis);
          idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
          idPolygonModelCollisionDetection::FinishContents(
            tw,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: parms->modelContentsOverride);
          goto LABEL_28;
        case TRACE_CONTACTS_UNI_DIR:
        case TRACE_CONTACTS_OMNI_DIR:
          *(_DWORD *)results->data = 0;
          idPolygonModelCollisionDetection::StartContacts(
            tw,
            result: (contactsResult_t *)results->data,
            start: &parms->start,
            dir: &parms->dir,
            depth: parms->depth,
            trm: (const idTraceModel *)polygonModel,
            trmAxis: (const idMat3 *)trm,
            contentMask: (int)&parms->trmAxis,
            modelOrigin: (const idVec3 *)parms->contentMask,
            modelAxis: v11);
          idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
          idPolygonModelCollisionDetection::FinishContacts(
            tw,
            firstContact: 0,
            modelOrigin: &parms->modelOrigin,
            modelAxis: &parms->modelAxis,
            modelEntityNum: parms->modelEntityNum,
            modelPhysicsId: parms->modelPhysicsId,
            modelBodyId: parms->modelBodyId,
            selfId: parms->selfId,
            modelContentsOverride: v13);
          goto LABEL_28;
        default:
          break;
      }
      if ( parms->type != TRACE_TRANSLATION )
      {
        *(_DWORD *)&results->data[4] = 0;
        *(_DWORD *)results->data = 0;
        idPolygonModelCollisionDetection::StartClip(
          tw,
          result: (clipResult_t *)results->data,
          start: &parms->start,
          trm,
          trmAxis: &parms->trmAxis,
          contentMask: parms->contentMask,
          modelOrigin: &parms->modelOrigin,
          modelAxis: &parms->modelAxis);
        idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
        idPolygonModelCollisionDetection::FinishClip(
          tw,
          firstClipVert: 0,
          modelOrigin: &parms->modelOrigin,
          modelAxis: &parms->modelAxis);
        goto LABEL_28;
      }
      if ( !idPolygonModelCollisionDetection::StartTranslation(
              tw,
              result: (trace_t *)results->data,
              contacts: nullptr,
              start: &parms->start,
              end: &parms->end,
              trm,
              trmAxis: &parms->trmAxis,
              contentMask: parms->contentMask,
              modelOrigin: v11->mat,
              modelAxis: v14) )
        goto LABEL_28;
LABEL_19:
      idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
      idPolygonModelCollisionDetection::FinishTranslation(
        tw,
        start: &parms->start,
        end: &parms->end,
        modelOrigin: &parms->modelOrigin,
        modelAxis: &parms->modelAxis,
        modelEntityNum: parms->modelEntityNum,
        modelPhysicsId: parms->modelPhysicsId,
        modelBodyId: parms->modelBodyId,
        selfId: (int)v11,
        modelContentsOverride: (int)v14);
      goto LABEL_28;
    }
    if ( idPolygonModelCollisionDetection::StartRotationPoint(
           tw,
           result: (trace_t *)results->data,
           rorg: &parms->rotationOrigin,
           axis: &parms->rotationAxis,
           angle: parms->rotationAngle,
           start: (const idVec3 *)polygonModel,
           contentMask: (int)&parms->start,
           modelOrigin: (const idVec3 *)parms->contentMask,
           modelAxis: (const idMat3 *)&parms->modelOrigin) )
    {
      idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
      idPolygonModelCollisionDetection::FinishRotation(
        tw,
        rorg: &parms->rotationOrigin,
        axis: &parms->rotationAxis,
        angle: parms->rotationAngle,
        start: (const idVec3 *)parms->modelPhysicsId,
        trmAxis: (const idMat3 *)&parms->start,
        modelOrigin: parms->trmAxis.mat,
        modelAxis: (const idMat3 *)&parms->modelOrigin,
        modelEntityNum: (int)&parms->modelAxis,
        modelPhysicsId: (int)v11,
        modelBodyId: (int)v14,
        selfId: v16,
        modelContentsOverride: v17);
    }
  }
LABEL_28:
  if ( parms->testQuery && (parms->type == TRACE_TRANSLATION || parms->type == TRACE_ROTATION) )
  {
    idPolygonModelCollisionDetection::StartContents(
      tw,
      result: &v19,
      start: (const idVec3 *)&results->data[4],
      trm,
      trmAxis: (const idMat3 *)&results->data[16],
      contentMask: parms->contentMask,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis);
    idPolygonModelCollisionDetection::TraceThroughModel(tw, model: polygonModel);
    idPolygonModelCollisionDetection::FinishContents(
      tw,
      modelOrigin: &parms->modelOrigin,
      modelAxis: &parms->modelAxis,
      modelEntityNum: parms->modelEntityNum,
      modelPhysicsId: parms->modelPhysicsId,
      modelId: parms->modelBodyId,
      selfId: parms->selfId,
      modelContentsOverride: parms->modelContentsOverride);
    if ( v19.c.contentFlags != 0 )
      results->query.status |= 4u;
  }
  if ( results->query.status == QUERY_STATUS_PENDING )
    results->query.status = QUERY_STATUS_SUCCESS;
  results->query.profile[0] = tw->profile[0];
  results->query.profile[1] = tw->profile[1];
  results->query.profile[2] = tw->profile[2];
  results->query.profile[3] = tw->profile[3];
  results->query.profile[4] = tw->profile[4];
  results->query.type = parms->type;
  results->query.done = 1;
  results->query.merged = parms->autoMerge;
}


// ========================================================================
// ?ExecuteSphereModelQuery@idCollisionQueryExecute@@SAXAAUqueryResults_t@@PBUqueryParms_t@@PBVidJointMat@@PBUcm_sphereModel_t@@@Z
// EA  : 0x825E62C8
// RVA : 0x005E62C8
// PDB : w:\tech5\engine\cm\jobs\collisionquery.cpp
// ========================================================================

void __fastcall idCollisionQueryExecute::ExecuteSphereModelQuery(
        queryResults_t *results,
        const queryParms_t *parms,
        const idVec3 *modelJoints,
        const cm_sphereModel_t *sphereModel)
{
  int v6; // [sp+8h] [-B8h]
  int v7; // [sp+Ch] [-B4h]
  int v8; // [sp+10h] [-B0h]
  int v9; // [sp+14h] [-ACh]
  int v10; // [sp+18h] [-A8h]

  if ( (unsigned int)(parms->type - 1) <= 8 )
  {
    switch ( parms->type )
    {
      case TRACE_TRANSLATION_POINT:
LABEL_10:
        idSphereModelCollisionDetection::TraceThroughModel(
          trace: (trace_t *)results->data,
          csData: sphereModel,
          start: &parms->start,
          end: &parms->end,
          radius: parms->depth,
          trmAxis: (const idMat3 *)parms->selfId,
          modelJoints: (const idJointMat *)&parms->trmAxis,
          modelOrigin: modelJoints,
          modelAxis: (const idMat3 *)&parms->modelOrigin,
          modelEntityNum: v6,
          modelPhysicsId: v7,
          modelBodyId: v8,
          selfId: v9,
          modelContentsOverride: v10);
        break;
      case TRACE_ROTATION:
      case TRACE_ROTATION_POINT:
      case TRACE_CONTENTS:
      case TRACE_CONTENTS_POINT:
        *(float *)results->data = 1.0;
        *(idVec3 *)&results->data[4] = parms->end;
        *(idMat3 *)&results->data[16] = parms->trmAxis;
        memset(Dst: &results->data[52], Val: 0, Size: 0x4Cu);
        break;
      case TRACE_CONTACTS_UNI_DIR:
      case TRACE_CONTACTS_OMNI_DIR:
LABEL_13:
        *(_DWORD *)results->data = 0;
        break;
      case TRACE_TRANSLATION:
        goto LABEL_10;
      default:
        *(_DWORD *)&results->data[4] = 0;
        goto LABEL_13;
    }
  }
  if ( results->query.status == QUERY_STATUS_PENDING )
    results->query.status = QUERY_STATUS_SUCCESS;
  results->query.profile[0] = 0;
  results->query.profile[1] = 0;
  results->query.profile[2] = 0;
  results->query.profile[3] = 0;
  results->query.profile[4] = 0;
  results->query.type = parms->type;
  results->query.done = 1;
  results->query.merged = parms->autoMerge;
}


// ========================================================================
// ?SetupDependentParms@idCollisionQueryExecute@@SAXPAUqueryParms_t@@PBU2@PBUqueryResults_t@@W4dependencyType_t@@22@Z
// EA  : 0x825E6448
// RVA : 0x005E6448
// PDB : w:\tech5\engine\cm\jobs\collisionquery.cpp
// ========================================================================

void __fastcall idCollisionQueryExecute::SetupDependentParms(
        queryParms_t *resultParms,
        const queryParms_t *sourceParms,
        const queryResults_t *modelPosition,
        const dependencyType_t dependencyType,
        const queryResults_t *dependency1,
        const queryResults_t *dependency2)
{
  unsigned __int8 *data; // r11
  float *v13; // r10
  float *v14; // r11
  float *v15; // r11
  double v16; // fp10
  double v17; // fp4
  double v18; // fp6
  double v19; // fp2
  double y; // fp1
  double x; // fp10
  double v22; // fp3
  double v23; // fp2
  float *v24; // r11
  float *v25; // r11
  double v26; // fp4
  double v27; // fp11
  double v28; // fp3
  double v29; // fp10
  float *v30; // r10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp6
  double v34; // fp5
  double z; // fp11
  double v36; // fp0
  double v37; // fp3
  double v38; // fp2
  double v39; // fp11
  double v40; // fp10
  double v41; // fp7
  double v42; // fp8
  float *v43; // r11
  double v44; // fp5
  double v45; // fp4
  double v46; // fp11
  double v47; // fp2
  double v48; // fp9
  double v49; // fp8
  double v50; // fp6
  double v51; // fp5
  unsigned __int8 *v52; // r4
  float *v53; // r11
  double v54; // fp9
  double v55; // fp8
  double v56; // fp5
  double v57; // fp6
  double v58; // fp4
  double v59; // fp3
  double v60; // fp2
  double v61; // fp1
  double v62; // fp11
  double v63; // fp7
  double v64; // fp6
  double v65; // fp9
  double v66; // fp5
  double v67; // fp3
  double v68; // fp2
  double v69; // fp1
  double v70; // fp5
  double v71; // fp4
  double v72; // fp9
  double v73; // fp8
  idMat3 v74[2]; // [sp+50h] [-60h] BYREF

  queryParms_t::operator=(this: resultParms, __that: sourceParms);
  if ( modelPosition != nullptr )
  {
    resultParms->modelOrigin.x = *(float *)&modelPosition->data[4];
    resultParms->modelOrigin.y = *(float *)&modelPosition->data[8];
    resultParms->modelOrigin.z = *(float *)&modelPosition->data[12];
    resultParms->modelAxis.mat[0].x = *(float *)&modelPosition->data[16];
    resultParms->modelAxis.mat[0].y = *(float *)&modelPosition->data[20];
    resultParms->modelAxis.mat[0].z = *(float *)&modelPosition->data[24];
    resultParms->modelAxis.mat[1].x = *(float *)&modelPosition->data[28];
    resultParms->modelAxis.mat[1].y = *(float *)&modelPosition->data[32];
    resultParms->modelAxis.mat[1].z = *(float *)&modelPosition->data[36];
    resultParms->modelAxis.mat[2].x = *(float *)&modelPosition->data[40];
    resultParms->modelAxis.mat[2].y = *(float *)&modelPosition->data[44];
    resultParms->modelAxis.mat[2].z = *(float *)&modelPosition->data[48];
  }
  data = nullptr;
  if ( dependency1 != nullptr )
    data = dependency1->data;
  v13 = nullptr;
  if ( dependency2 != nullptr )
    v13 = (float *)dependency2->data;
  switch ( dependencyType )
  {
    case DEPENDENCY_MOTION_ROTATION:
      v14 = (float *)(data + 4);
      resultParms->start.x = *v14;
      resultParms->start.y = v14[1];
      resultParms->start.z = v14[2];
      resultParms->rotationOrigin.x = *v14;
      resultParms->rotationOrigin.y = v14[1];
      resultParms->rotationOrigin.z = v14[2];
      break;
    case DEPENDENCY_MOTION_CONTACTS:
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      resultParms->trmAxis.mat[0].x = *((float *)data + 4);
      resultParms->trmAxis.mat[0].y = *((float *)data + 5);
      resultParms->trmAxis.mat[0].z = *((float *)data + 6);
      resultParms->trmAxis.mat[1].x = *((float *)data + 7);
      resultParms->trmAxis.mat[1].y = *((float *)data + 8);
      resultParms->trmAxis.mat[1].z = *((float *)data + 9);
      resultParms->trmAxis.mat[2].x = *((float *)data + 10);
      resultParms->trmAxis.mat[2].y = *((float *)data + 11);
      resultParms->trmAxis.mat[2].z = *((float *)data + 12);
      break;
    case DEPENDENCY_STEPMOVE_STEP_UP:
    case DEPENDENCY_STEPMOVE_STEP_DOWN:
      v15 = (float *)(data + 4);
      resultParms->start.x = *v15;
      resultParms->start.y = v15[1];
      resultParms->start.z = v15[2];
      v16 = v15[2];
      v17 = (float)(sourceParms->dir.y * sourceParms->depth);
      v18 = v15[1];
      v19 = (float)(sourceParms->dir.z * sourceParms->depth);
      resultParms->end.x = *v15 + (float)(sourceParms->dir.x * sourceParms->depth);
      resultParms->end.y = (float)v17 + (float)v18;
      resultParms->end.z = (float)v16 + (float)v19;
      break;
    case DEPENDENCY_STEPMOVE_2ND_MOVE:
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      y = sourceParms->end.y;
      x = sourceParms->end.x;
      v22 = (float)(sourceParms->dir.x * (float)(sourceParms->depth * *(float *)data));
      v23 = (float)(sourceParms->dir.y * (float)(sourceParms->depth * *(float *)data));
      resultParms->end.z = sourceParms->end.z
                         + (float)(sourceParms->dir.z * (float)(sourceParms->depth * *(float *)data));
      resultParms->end.x = (float)x + (float)v22;
      resultParms->end.y = (float)y + (float)v23;
      break;
    case DEPENDENCY_STEPMOVE_CONTACTS:
    case DEPENDENCY_SLIDEMOVE_CONTACTS:
      v24 = (float *)(data + 4);
      resultParms->start.x = *v24;
      resultParms->start.y = v24[1];
      resultParms->start.z = v24[2];
      resultParms->end.x = *v24;
      resultParms->end.y = v24[1];
      resultParms->end.z = v24[2];
      break;
    case DEPENDENCY_SLIDEMOVE_STEP_UP_1:
      v25 = (float *)(data + 4);
      resultParms->start.x = *v25;
      resultParms->start.y = v25[1];
      resultParms->start.z = v25[2];
      v26 = (float)(sourceParms->dir.y * sourceParms->depth);
      v27 = v25[2];
      v28 = (float)(sourceParms->dir.z * sourceParms->depth);
      v29 = v25[1];
      resultParms->end.x = *v25 + (float)(sourceParms->dir.x * sourceParms->depth);
      resultParms->end.y = (float)v26 + (float)v29;
      resultParms->end.z = (float)v27 + (float)v28;
      break;
    case DEPENDENCY_SLIDEMOVE_STEP_UP_2:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_3:
    case DEPENDENCY_SLIDEMOVE_STEP_UP_4:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_2:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_3:
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_4:
      v30 = (float *)(data + 4);
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      if ( (data[124] & 0x20) != 0 )
        goto LABEL_16;
      v31 = (float)(sourceParms->dir.y * sourceParms->depth);
      v32 = (float)(sourceParms->dir.z * sourceParms->depth);
      v33 = *((float *)data + 2);
      v34 = *((float *)data + 3);
      resultParms->end.x = (float)(sourceParms->dir.x * sourceParms->depth) + *v30;
      resultParms->end.y = (float)v31 + (float)v33;
      resultParms->end.z = (float)v34 + (float)v32;
      break;
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_1:
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      z = sourceParms->end.z;
      v36 = sourceParms->end.y;
      v37 = (float)(sourceParms->dir.y * (float)(sourceParms->depth * *(float *)data));
      v38 = (float)(sourceParms->dir.z * (float)(sourceParms->depth * *(float *)data));
      resultParms->end.x = sourceParms->end.x
                         + (float)(sourceParms->dir.x * (float)(sourceParms->depth * *(float *)data));
      resultParms->end.y = (float)v36 + (float)v37;
      resultParms->end.z = (float)z + (float)v38;
      break;
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_2:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_3:
    case DEPENDENCY_SLIDEMOVE_2ND_MOVE_4:
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      if ( (data[124] & 0x20) != 0 )
      {
        resultParms->end.x = *((float *)data + 1);
        resultParms->end.y = *((float *)data + 2);
        resultParms->end.z = *((float *)data + 3);
      }
      else
      {
        v39 = (float)(v13[2] + (float)(v13[18] * v13[20]));
        v40 = (float)(v13[3] + (float)(v13[19] * v13[20]));
        v41 = (float)(sourceParms->dir.z * (float)(sourceParms->depth * *(float *)data));
        v42 = (float)(sourceParms->dir.y * (float)(sourceParms->depth * *(float *)data));
        resultParms->end.x = (float)((float)(v13[20] * v13[17]) + v13[1])
                           + (float)(sourceParms->dir.x * (float)(sourceParms->depth * *(float *)data));
        resultParms->end.z = (float)v40 + (float)v41;
        resultParms->end.y = (float)v39 + (float)v42;
      }
      break;
    case DEPENDENCY_SLIDEMOVE_STEP_DOWN_1:
      v43 = (float *)(data + 4);
      resultParms->start.x = *v43;
      resultParms->start.y = v43[1];
      resultParms->start.z = v43[2];
      v44 = (float)(sourceParms->dir.z * sourceParms->depth);
      v45 = (float)(sourceParms->dir.x * sourceParms->depth);
      v46 = *v43;
      v47 = v43[2];
      resultParms->end.y = (float)(sourceParms->dir.y * sourceParms->depth) + v43[1];
      resultParms->end.z = (float)v47 + (float)v44;
      resultParms->end.x = (float)v45 + (float)v46;
      break;
    case DEPENDENCY_SLIDEMOVE_SLIDE:
      v30 = (float *)(data + 4);
      resultParms->start.x = *((float *)data + 1);
      resultParms->start.y = *((float *)data + 2);
      resultParms->start.z = *((float *)data + 3);
      if ( (data[124] & 0x20) != 0 )
      {
LABEL_16:
        resultParms->end.x = *v30;
        resultParms->end.y = v30[1];
        resultParms->end.z = v30[2];
      }
      else
      {
        v48 = (float)(*((float *)data + 18) * *((float *)data + 20));
        v49 = (float)(*((float *)data + 19) * *((float *)data + 20));
        v50 = *((float *)data + 2);
        v51 = *((float *)data + 3);
        resultParms->end.x = (float)(*((float *)data + 20) * *((float *)data + 17)) + *v30;
        resultParms->end.y = (float)v48 + (float)v50;
        resultParms->end.z = (float)v51 + (float)v49;
      }
      break;
    case DEPENDENCY_LOCAL_SPACE:
      v52 = data + 16;
      v54 = (float)(sourceParms->start.z * *((float *)data + 10));
      v55 = (float)(sourceParms->start.x * *((float *)data + 5));
      v56 = (float)(sourceParms->start.z * *((float *)data + 12));
      v57 = *((float *)data + 7);
      v58 = *((float *)data + 8);
      v59 = *((float *)data + 6);
      v60 = *((float *)data + 4);
      v61 = *((float *)data + 11);
      v62 = *((float *)data + 9);
      v53 = (float *)(data + 4);
      v63 = v53[1];
      v64 = (float)((float)(sourceParms->start.y * (float)v57) + (float)v54);
      v65 = v53[2];
      v66 = (float)((float)(sourceParms->start.x * (float)v59) + (float)v56);
      v67 = (float)((float)(sourceParms->start.z * (float)v61)
                  + (float)((float)(sourceParms->start.y * (float)v58) + (float)v55));
      v69 = (float)((float)((float)(sourceParms->start.x * (float)v60) + (float)v64) + *v53);
      v68 = (float)((float)(sourceParms->start.y * (float)v62) + (float)v66);
      resultParms->start.x = v69;
      resultParms->start.y = (float)v67 + (float)v63;
      resultParms->start.z = (float)v65 + (float)v68;
      v70 = v53[2];
      v71 = v53[1];
      v72 = (float)((float)(*((float *)v52 + 7) * sourceParms->end.z)
                  + (float)((float)(*((float *)v52 + 1) * sourceParms->end.x)
                          + (float)(*((float *)v52 + 4) * sourceParms->end.y)));
      v73 = (float)((float)(*((float *)v52 + 5) * sourceParms->end.y)
                  + (float)((float)(*((float *)v52 + 8) * sourceParms->end.z)
                          + (float)(sourceParms->end.x * *((float *)v52 + 2))));
      resultParms->end.x = (float)((float)(sourceParms->end.x * *(float *)v52)
                                 + (float)((float)(sourceParms->end.y * *((float *)v52 + 3))
                                         + (float)(sourceParms->end.z * *((float *)v52 + 6))))
                         + *v53;
      resultParms->end.y = (float)v72 + (float)v71;
      resultParms->end.z = (float)v70 + (float)v73;
      resultParms->trmAxis = *idMat3::operator*(this: v74, result: (idMat3 *)v52, a: &sourceParms->trmAxis);
      break;
    default:
      return;
  }
}

