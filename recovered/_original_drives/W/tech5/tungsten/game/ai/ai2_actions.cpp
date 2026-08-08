
// ========================================================================
// ?Action_LeapAttack@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82A29C50
// RVA : 0x00A29C50
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

void __fastcall idAI2::Action_LeapAttack(idAI2 *this, eventVoid *result, const idVec3 *leapTarget)
{
  idLib::Error(fmt: "FIXME: Action_LeapAttack not implemented!", result, leapTarget);
}


// ========================================================================
// ?Action_MoveToPoint@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4aiArrivalAction_t@@MW4aiActionBool_t@@0@Z
// EA  : 0x82A29C60
// RVA : 0x00A29C60
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToPoint(
        idAI2 *this,
        const idEntity *result,
        const idVec3 *dest,
        const aiArrivalAction_t stopUponArrival,
        double tolerance,
        const aiActionBool_t align,
        const idVec3 *alignDir,
        float *a8)
{
  double y; // fp11
  double z; // fp10
  double v12; // fp13
  double v13; // fp9
  double v14; // fp8
  idEventArg *v15; // r23
  const idEventArg *v17; // [sp+8h] [-258h]
  const idEventArg *v18; // [sp+Ch] [-254h]
  _BYTE v19[20]; // [sp+70h] [-1F0h] BYREF
  _BYTE v20[20]; // [sp+90h] [-1D0h] BYREF
  _BYTE v21[20]; // [sp+B0h] [-1B0h] BYREF
  _BYTE v22[20]; // [sp+D0h] [-190h] BYREF
  _BYTE v23[20]; // [sp+F0h] [-170h] BYREF
  float v24[5]; // [sp+110h] [-150h] BYREF
  float v25[5]; // [sp+130h] [-130h] BYREF
  float v26[5]; // [sp+150h] [-110h] BYREF
  int v27; // [sp+170h] [-F0h]
  int v28; // [sp+174h] [-ECh]
  const idEventArg *v29; // [sp+178h] [-E8h]
  const idEventArg *v30; // [sp+17Ch] [-E4h]
  _DWORD v31[5]; // [sp+190h] [-D0h] BYREF
  _DWORD v32[5]; // [sp+1B0h] [-B0h] BYREF
  idEventArg v33; // [sp+1D0h] [-90h] BYREF
  idEventReceiver v34[9]; // [sp+1F0h] [-70h] BYREF

  v32[1] = stopUponArrival;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  y = dest->y;
  z = dest->z;
  v12 = a8[2];
  v13 = *a8;
  v14 = a8[1];
  v25[1] = dest->x;
  v24[2] = v14;
  v24[1] = v13;
  v24[3] = v12;
  v25[2] = y;
  v25[3] = z;
  v26[1] = 0.1;
  HIBYTE(v24[0]) = 118;
  HIBYTE(v31[0]) = 105;
  v31[1] = alignDir != nullptr;
  HIBYTE(v26[0]) = 102;
  HIBYTE(v32[0]) = 105;
  HIBYTE(v25[0]) = 118;
  HIBYTE(v27) = 105;
  v28 = 33;
  v15 = idEventArg::idEventArg(this: &v33, data: result);
  memcpy(Dst: v23, Src: v24, Size: sizeof(v23));
  memcpy(Dst: v22, Src: v31, Size: sizeof(v22));
  memcpy(Dst: v21, Src: v26, Size: sizeof(v21));
  memcpy(Dst: v20, Src: v32, Size: sizeof(v20));
  memcpy(Dst: v19, Src: v25, Size: sizeof(v19));
  idEventReceiver::ProcessEvent(
    this: v34,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v15->type,
    arg1: (const idEventArg *)LODWORD(v15->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v15->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v27, 32),
    arg4: v29,
    arg5: v30,
    arg6: v17,
    arg7: v18);
  return this;
}


// ========================================================================
// ?Action_MoveToPointNoFail@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4aiArrivalAction_t@@MW4aiActionBool_t@@0PBVidDeclVoiceOver@@@Z
// EA  : 0x82A29DB8
// RVA : 0x00A29DB8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToPointNoFail(
        idAI2 *this,
        const idEntity *result,
        const idVec3 *dest,
        const aiArrivalAction_t stopUponArrival,
        double tolerance,
        const aiActionBool_t align,
        const idVec3 *alignDir,
        const idDeclVoiceOver *declVoiceOver,
        int a9)
{
  double y; // fp11
  double z; // fp10
  double v13; // fp13
  double v14; // fp9
  double v15; // fp8
  idEventArg *v16; // r22
  const idEventArg *v18; // [sp+8h] [-298h]
  const idEventArg *v19; // [sp+Ch] [-294h]
  const idEventArg *v20; // [sp+10h] [-290h]
  _BYTE v21[20]; // [sp+70h] [-230h] BYREF
  _BYTE v22[20]; // [sp+90h] [-210h] BYREF
  _BYTE v23[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v24[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v25[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v26[20]; // [sp+110h] [-190h] BYREF
  float v27[5]; // [sp+130h] [-170h] BYREF
  float v28[5]; // [sp+150h] [-150h] BYREF
  float v29[5]; // [sp+170h] [-130h] BYREF
  _DWORD v30[5]; // [sp+190h] [-110h] BYREF
  char v31; // [sp+1B0h] [-F0h]
  int v32; // [sp+1B4h] [-ECh]
  const idEventArg *v33; // [sp+1B8h] [-E8h]
  const idEventArg *v34; // [sp+1BCh] [-E4h]
  _DWORD v35[5]; // [sp+1D0h] [-D0h] BYREF
  _DWORD v36[5]; // [sp+1F0h] [-B0h] BYREF
  idEventArg v37; // [sp+210h] [-90h] BYREF
  idEventReceiver v38[9]; // [sp+230h] [-70h] BYREF

  v35[1] = a9;
  v30[1] = stopUponArrival;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  y = dest->y;
  z = dest->z;
  v13 = *(float *)&declVoiceOver->name.str;
  v14 = *(float *)&declVoiceOver->__vftable;
  v15 = *(float *)&declVoiceOver->trackedMemory;
  v28[1] = dest->x;
  v27[2] = v15;
  v27[1] = v14;
  v27[3] = v13;
  v28[2] = y;
  v28[3] = z;
  v29[1] = 0.1;
  HIBYTE(v35[0]) = 100;
  HIBYTE(v27[0]) = 118;
  HIBYTE(v36[0]) = 105;
  v36[1] = alignDir != nullptr;
  HIBYTE(v29[0]) = 102;
  HIBYTE(v30[0]) = 105;
  HIBYTE(v28[0]) = 118;
  v31 = 105;
  v32 = 33;
  v16 = idEventArg::idEventArg(this: &v37, data: result);
  memcpy(Dst: v26, Src: v35, Size: sizeof(v26));
  memcpy(Dst: v25, Src: v27, Size: sizeof(v25));
  memcpy(Dst: v24, Src: v36, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v29, Size: sizeof(v23));
  memcpy(Dst: v22, Src: v30, Size: sizeof(v22));
  memcpy(Dst: v21, Src: v28, Size: sizeof(v21));
  idEventReceiver::ProcessEvent(
    this: v38,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v16->type,
    arg1: (const idEventArg *)LODWORD(v16->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v16->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(LODWORD(v16->value.q[3]), 32),
    arg4: v33,
    arg5: v34,
    arg6: v18,
    arg7: v19,
    arg8: v20);
  return this;
}


// ========================================================================
// ?Action_MoveToEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiArrivalAction_t@@MW4aiActionBool_t@@ABVidVec3@@@Z
// EA  : 0x82A29F38
// RVA : 0x00A29F38
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToEntity(
        idAI2 *this,
        const idEntity *result,
        const idEntity *ent,
        const aiArrivalAction_t stopUponArrival,
        double reachedDistance,
        const aiActionBool_t align,
        const idVec3 *alignDir,
        float *a8)
{
  double v9; // fp13
  double v10; // fp12
  idEventArg *v12; // r24
  idEventArg *v13; // r23
  const idEventArg *v15; // [sp+8h] [-258h]
  const idEventArg *v16; // [sp+Ch] [-254h]
  _BYTE v17[20]; // [sp+70h] [-1F0h] BYREF
  _BYTE v18[20]; // [sp+90h] [-1D0h] BYREF
  _BYTE v19[20]; // [sp+B0h] [-1B0h] BYREF
  _BYTE v20[20]; // [sp+D0h] [-190h] BYREF
  _BYTE v21[20]; // [sp+F0h] [-170h] BYREF
  float v22[5]; // [sp+110h] [-150h] BYREF
  _DWORD v23[5]; // [sp+130h] [-130h] BYREF
  int v24; // [sp+150h] [-110h]
  int v25; // [sp+154h] [-10Ch]
  const idEventArg *v26; // [sp+158h] [-108h]
  const idEventArg *v27; // [sp+15Ch] [-104h]
  _DWORD v28[5]; // [sp+170h] [-F0h] BYREF
  float v29[5]; // [sp+190h] [-D0h] BYREF
  idEventArg v30; // [sp+1B0h] [-B0h] BYREF
  idEventArg v31; // [sp+1D0h] [-90h] BYREF
  idEventReceiver v32[9]; // [sp+1F0h] [-70h] BYREF

  v23[1] = stopUponArrival;
  v29[1] = reachedDistance;
  HIBYTE(v28[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v9 = *a8;
  v10 = a8[1];
  v22[3] = a8[2];
  v22[2] = v10;
  v22[1] = v9;
  HIBYTE(v22[0]) = 118;
  v28[1] = alignDir != nullptr;
  HIBYTE(v29[0]) = 102;
  HIBYTE(v23[0]) = 105;
  HIBYTE(v24) = 105;
  v25 = 33;
  v12 = idEventArg::idEventArg(this: &v30, data: ent);
  v13 = idEventArg::idEventArg(this: &v31, data: result);
  memcpy(Dst: v21, Src: v22, Size: sizeof(v21));
  memcpy(Dst: v20, Src: v28, Size: sizeof(v20));
  memcpy(Dst: v19, Src: v29, Size: sizeof(v19));
  memcpy(Dst: v18, Src: v23, Size: sizeof(v18));
  memcpy(Dst: v17, Src: v12, Size: sizeof(v17));
  idEventReceiver::ProcessEvent(
    this: v32,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v13->type,
    arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v24, 32),
    arg4: v26,
    arg5: v27,
    arg6: v15,
    arg7: v16);
  return this;
}


// ========================================================================
// ?Action_MoveToEntityNoFail@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiArrivalAction_t@@MW4aiActionBool_t@@ABVidVec3@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82A2A078
// RVA : 0x00A2A078
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToEntityNoFail(
        idAI2 *this,
        const idEntity *result,
        const idEntity *ent,
        const aiArrivalAction_t stopUponArrival,
        double reachedDistance,
        const aiActionBool_t align,
        const idVec3 *alignDir,
        const idDeclVoiceOver *declVoiceOver,
        int a9)
{
  double v11; // fp13
  double v12; // fp12
  idEventArg *v13; // r23
  idEventArg *v14; // r22
  const idEventArg *v16; // [sp+8h] [-298h]
  const idEventArg *v17; // [sp+Ch] [-294h]
  const idEventArg *v18; // [sp+10h] [-290h]
  _BYTE v19[20]; // [sp+70h] [-230h] BYREF
  _BYTE v20[20]; // [sp+90h] [-210h] BYREF
  _BYTE v21[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v22[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v23[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v24[20]; // [sp+110h] [-190h] BYREF
  float v25[5]; // [sp+130h] [-170h] BYREF
  _DWORD v26[5]; // [sp+150h] [-150h] BYREF
  int v27; // [sp+170h] [-130h]
  int v28; // [sp+174h] [-12Ch]
  const idEventArg *v29; // [sp+178h] [-128h]
  const idEventArg *v30; // [sp+17Ch] [-124h]
  _DWORD v31[5]; // [sp+190h] [-110h] BYREF
  _DWORD v32[5]; // [sp+1B0h] [-F0h] BYREF
  float v33[5]; // [sp+1D0h] [-D0h] BYREF
  idEventArg v34; // [sp+1F0h] [-B0h] BYREF
  idEventArg v35; // [sp+210h] [-90h] BYREF
  idEventReceiver v36[9]; // [sp+230h] [-70h] BYREF

  v32[1] = a9;
  v26[1] = stopUponArrival;
  v33[1] = reachedDistance;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v11 = *(float *)&declVoiceOver->__vftable;
  v12 = *(float *)&declVoiceOver->trackedMemory;
  v25[3] = *(float *)&declVoiceOver->name.str;
  v25[2] = v12;
  v25[1] = v11;
  HIBYTE(v31[0]) = 105;
  HIBYTE(v32[0]) = 100;
  HIBYTE(v25[0]) = 118;
  v31[1] = alignDir != nullptr;
  HIBYTE(v33[0]) = 102;
  HIBYTE(v26[0]) = 105;
  HIBYTE(v27) = 105;
  v28 = 33;
  v13 = idEventArg::idEventArg(this: &v34, data: ent);
  v14 = idEventArg::idEventArg(this: &v35, data: result);
  memcpy(Dst: v24, Src: v32, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v25, Size: sizeof(v23));
  memcpy(Dst: v22, Src: v31, Size: sizeof(v22));
  memcpy(Dst: v21, Src: v33, Size: sizeof(v21));
  memcpy(Dst: v20, Src: v26, Size: sizeof(v20));
  memcpy(Dst: v19, Src: v13, Size: sizeof(v19));
  idEventReceiver::ProcessEvent(
    this: v36,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v14->type,
    arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v27, 32),
    arg4: v29,
    arg5: v30,
    arg6: v16,
    arg7: v17,
    arg8: v18);
  return this;
}


// ========================================================================
// ?Action_MoveToPathPoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A2A1D8
// RVA : 0x00A2A1D8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToPathPoint(idAI2 *this, const idEntity *result, const idEntity *pathPoint)
{
  idEventArg *v5; // r28
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  int v9; // [sp+90h] [-B0h]
  int v10; // [sp+94h] [-ACh]
  idEventArg v11; // [sp+B0h] [-90h] BYREF
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  if ( pathPoint == nullptr )
    idLib::Error(fmt: "Invalid pathPoint for Action_MovetoPathPoint on entity '%s'", result->name.data);
  HIBYTE(v9) = 105;
  v10 = 33;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v5 = idEventArg::idEventArg(this: &v11, data: pathPoint);
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v5, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v9, 32));
  return this;
}


// ========================================================================
// ?Action_MoveToPathPointNoFail@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82A2A2A0
// RVA : 0x00A2A2A0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToPathPointNoFail(
        idAI2 *this,
        const idEntity *result,
        const idEntity *pathPoint,
        const idDeclVoiceOver *declVoiceOver)
{
  idEventArg *v6; // r27
  idEventArg *v7; // r26
  _BYTE v9[20]; // [sp+70h] [-110h] BYREF
  _BYTE v10[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v11[5]; // [sp+B0h] [-D0h] BYREF
  int v12; // [sp+D0h] [-B0h]
  int v13; // [sp+D4h] [-ACh]
  const idEventArg *v14; // [sp+D8h] [-A8h]
  idEventArg v15; // [sp+F0h] [-90h] BYREF
  idEventArg v16; // [sp+110h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+130h] [-50h] BYREF

  if ( pathPoint == nullptr )
    idLib::Error(fmt: "Invalid pathPoint for Action_MovetoPathPointNoFail on entity '%s'", result->name.data);
  v11[1] = declVoiceOver;
  HIBYTE(v11[0]) = 100;
  HIBYTE(v12) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v13 = 33;
  v6 = idEventArg::idEventArg(this: &v15, data: pathPoint);
  v7 = idEventArg::idEventArg(this: &v16, data: result);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  memcpy(Dst: v9, Src: v6, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v12, 32),
    arg4: v14);
  return this;
}


// ========================================================================
// ?Action_MoveToCover@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4coverAction_t@@W4posture_t@@0@Z
// EA  : 0x82A2A388
// RVA : 0x00A2A388
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToCover(
        idAI2 *this,
        const idEntity *result,
        const idVec3 *dest,
        const coverAction_t coverAction,
        const posture_t posture,
        const idVec3 *alignDir)
{
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v11; // fp10
  double v12; // fp9
  idEventArg *v13; // r23
  const idEventArg *v15; // [sp+8h] [-258h]
  const idEventArg *v16; // [sp+Ch] [-254h]
  _BYTE v17[20]; // [sp+70h] [-1F0h] BYREF
  _BYTE v18[20]; // [sp+90h] [-1D0h] BYREF
  _BYTE v19[20]; // [sp+B0h] [-1B0h] BYREF
  _BYTE v20[20]; // [sp+D0h] [-190h] BYREF
  _BYTE v21[20]; // [sp+F0h] [-170h] BYREF
  float v22[5]; // [sp+110h] [-150h] BYREF
  float v23[5]; // [sp+130h] [-130h] BYREF
  _DWORD v24[5]; // [sp+150h] [-110h] BYREF
  int v25; // [sp+170h] [-F0h]
  int v26; // [sp+174h] [-ECh]
  const idEventArg *v27; // [sp+178h] [-E8h]
  const idEventArg *v28; // [sp+17Ch] [-E4h]
  _DWORD v29[5]; // [sp+190h] [-D0h] BYREF
  _DWORD v30[5]; // [sp+1B0h] [-B0h] BYREF
  idEventArg v31; // [sp+1D0h] [-90h] BYREF
  idEventReceiver v32[9]; // [sp+1F0h] [-70h] BYREF

  v24[1] = posture;
  v30[1] = coverAction;
  v29[1] = 1;
  HIBYTE(v29[0]) = 105;
  HIBYTE(v22[0]) = 118;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  x = dest->x;
  y = dest->y;
  z = dest->z;
  v11 = alignDir->x;
  v12 = alignDir->y;
  v22[3] = alignDir->z;
  v22[2] = v12;
  v22[1] = v11;
  v23[1] = x;
  HIBYTE(v24[0]) = 105;
  v23[2] = y;
  HIBYTE(v30[0]) = 105;
  v23[3] = z;
  HIBYTE(v23[0]) = 118;
  HIBYTE(v25) = 105;
  v26 = 33;
  v13 = idEventArg::idEventArg(this: &v31, data: result);
  memcpy(Dst: v21, Src: v22, Size: sizeof(v21));
  memcpy(Dst: v20, Src: v29, Size: sizeof(v20));
  memcpy(Dst: v19, Src: v24, Size: sizeof(v19));
  memcpy(Dst: v18, Src: v30, Size: sizeof(v18));
  memcpy(Dst: v17, Src: v23, Size: sizeof(v17));
  idEventReceiver::ProcessEvent(
    this: v32,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v13->type,
    arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v13->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v25, 32),
    arg4: v27,
    arg5: v28,
    arg6: v15,
    arg7: v16);
  return this;
}


// ========================================================================
// ?Action_UseZipline@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A2A4C8
// RVA : 0x00A2A4C8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_UseZipline(idAI2 *this, const idEntity *result, const idEntity *ent)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+70h] [-80h] BYREF
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  idEventArg::idEventArg(this: &v7, data: ent);
  v5 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetMovePushStatus@idAI2@@QAA?AVeventVoid@@W4aiMovePushStatus_t@@@Z
// EA  : 0x82A2A550
// RVA : 0x00A2A550
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetMovePushStatus(
        idAI2 *this,
        const idEntity *result,
        const aiMovePushStatus_t pushMoveStatus)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_Idle@idAI2@@QAA?AVeventVoid@@HW4aiIdleTurn_t@@@Z
// EA  : 0x82A2A5D8
// RVA : 0x00A2A5D8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Idle(idAI2 *this, const idEntity *result, int time, const aiIdleTurn_t idleTurnType)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  int v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v9[1] = idleTurnType;
  v11 = time;
  HIBYTE(v9[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = time != 0;
  HIBYTE(v10) = 105;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_Pain@idAI2@@QAA?AVeventVoid@@W4painType_t@@W4aiDirection_t@@MPBD@Z
// EA  : 0x82A2A680
// RVA : 0x00A2A680
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Pain(
        idAI2 *this,
        const idEntity *result,
        const painType_t painType,
        const aiDirection_t direction,
        double intensity,
        const char *jointGroupName)
{
  idEventArg *v8; // r3
  idEventArg v10; // [sp+50h] [-50h] BYREF
  idEventReceiver v11[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v8 = idEventArg::idEventArg(this: &v10, data: result);
  idEventReceiver::ProcessEvent(
    this: v11,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_StandToCrouch@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A700
// RVA : 0x00A2A700
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_StandToCrouch(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_CrouchToStand@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A780
// RVA : 0x00A2A780
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_CrouchToStand(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_PullTriggerRight@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A800
// RVA : 0x00A2A800
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PullTriggerRight(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_ReleaseTriggerRight@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A880
// RVA : 0x00A2A880
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ReleaseTriggerRight(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_PullTriggerLeft@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A900
// RVA : 0x00A2A900
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PullTriggerLeft(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_ReleaseTriggerLeft@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2A980
// RVA : 0x00A2A980
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ReleaseTriggerLeft(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_WaitForAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@@Z
// EA  : 0x82A2AA00
// RVA : 0x00A2AA00
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForAnim(idAI2 *this, const idEntity *result, const idAnimWebPath *animWebNode)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_WaitForAnimVia@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@0@Z
// EA  : 0x82A2AA88
// RVA : 0x00A2AA88
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForAnimVia(
        idAI2 *this,
        const idEntity *result,
        const idAnimWebPath *destAnimWebNode,
        const idAnimWebPath *viaAnimWebNode)
{
  char *data; // r7
  idEventArg *v7; // r27
  _BYTE v9[20]; // [sp+70h] [-D0h] BYREF
  int v10; // [sp+90h] [-B0h]
  char *v11; // [sp+94h] [-ACh]
  _DWORD v12[5]; // [sp+B0h] [-90h] BYREF
  idEventArg v13; // [sp+D0h] [-70h] BYREF
  idEventReceiver v14[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(v12[0]) = 49;
  HIBYTE(v10) = 49;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  data = destAnimWebNode->data;
  v12[1] = viaAnimWebNode->data;
  v11 = data;
  v7 = idEventArg::idEventArg(this: &v13, data: result);
  memcpy(Dst: v9, Src: v12, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v14,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_LoopAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@H@Z
// EA  : 0x82A2AB30
// RVA : 0x00A2AB30
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_LoopAnim(
        idAI2 *this,
        const idEntity *result,
        const idAnimWebPath *aliasName,
        const int milliseconds)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  char *data; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v9[1] = milliseconds;
  HIBYTE(v9[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  data = aliasName->data;
  HIBYTE(v10) = 49;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_LoopAnimExitAtEnd@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@HH@Z
// EA  : 0x82A2ABD8
// RVA : 0x00A2ABD8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_LoopAnimExitAtEnd(
        idAI2 *this,
        const idEntity *result,
        const idAnimWebPath *animWebNode,
        const int milliseconds,
        const int framesFromEnd)
{
  idEventArg *v7; // r26
  _BYTE v9[20]; // [sp+70h] [-110h] BYREF
  _BYTE v10[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v11[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+D0h] [-B0h] BYREF
  int v13; // [sp+F0h] [-90h]
  char *data; // [sp+F4h] [-8Ch]
  const idEventArg *v15; // [sp+F8h] [-88h]
  idEventArg v16; // [sp+110h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+130h] [-50h] BYREF

  v11[1] = framesFromEnd;
  v12[1] = milliseconds;
  HIBYTE(v11[0]) = 105;
  HIBYTE(v12[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  data = animWebNode->data;
  HIBYTE(v13) = 49;
  v7 = idEventArg::idEventArg(this: &v16, data: result);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  memcpy(Dst: v9, Src: v12, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32),
    arg4: v15);
  return this;
}


// ========================================================================
// ?Action_StartAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@W4aiActionBool_t@@1@Z
// EA  : 0x82A2ACA0
// RVA : 0x00A2ACA0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_StartAnim(
        idAI2 *this,
        const idEntity *result,
        const idAnimWebPath *animWebNode,
        const aiActionBool_t finishBlend,
        const aiActionBool_t wait)
{
  char *data; // r8
  idEventArg *v8; // r26
  _BYTE v10[20]; // [sp+70h] [-110h] BYREF
  _BYTE v11[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v12[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v13[5]; // [sp+D0h] [-B0h] BYREF
  int v14; // [sp+F0h] [-90h]
  char *v15; // [sp+F4h] [-8Ch]
  const idEventArg *v16; // [sp+F8h] [-88h]
  idEventArg v17; // [sp+110h] [-70h] BYREF
  idEventReceiver v18[6]; // [sp+130h] [-50h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  data = animWebNode->data;
  HIBYTE(v12[0]) = 105;
  v12[1] = wait != AIACTION_FALSE;
  v15 = data;
  HIBYTE(v13[0]) = 105;
  v13[1] = finishBlend != AIACTION_FALSE;
  HIBYTE(v14) = 49;
  v8 = idEventArg::idEventArg(this: &v17, data: result);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  memcpy(Dst: v10, Src: v13, Size: sizeof(v10));
  idEventReceiver::ProcessEvent(
    this: v18,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v14, 32),
    arg4: v16);
  return this;
}


// ========================================================================
// ?Action_WaitForTraversalAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@W4aiActionBool_t@@@Z
// EA  : 0x82A2AD78
// RVA : 0x00A2AD78
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForTraversalAnim(
        idAI2 *this,
        const idEntity *result,
        const idAnimWebPath *animWebNode,
        const aiActionBool_t runWhenDone)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  char *data; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  data = animWebNode->data;
  HIBYTE(v9[0]) = 105;
  v9[1] = runWhenDone != AIACTION_FALSE;
  HIBYTE(v10) = 49;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_ChangeAnimState@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@W4aiAnimWait_t@@@Z
// EA  : 0x82A2AE28
// RVA : 0x00A2AE28
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ChangeAnimState(
        idAI2 *this,
        const idEntity *result,
        aiAnimWeb_t animweb,
        const idAnimWebPath *destNode,
        const aiAnimWait_t wait)
{
  idEventArg *v7; // r26
  _BYTE v9[20]; // [sp+70h] [-110h] BYREF
  _BYTE v10[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v11[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+D0h] [-B0h] BYREF
  int v13; // [sp+F0h] [-90h]
  aiAnimWeb_t v14; // [sp+F4h] [-8Ch]
  const idEventArg *v15; // [sp+F8h] [-88h]
  idEventArg v16; // [sp+110h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+130h] [-50h] BYREF

  v11[1] = wait;
  v14 = animweb;
  HIBYTE(v11[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = wait != AIANIMWAIT_DONT_WAIT;
  v12[1] = destNode->data;
  HIBYTE(v12[0]) = 49;
  HIBYTE(v13) = 105;
  v7 = idEventArg::idEventArg(this: &v16, data: result);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  memcpy(Dst: v9, Src: v12, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32),
    arg4: v15);
  return this;
}


// ========================================================================
// ?Action_ChangeAnimStateVia@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@1W4aiAnimWait_t@@@Z
// EA  : 0x82A2AEF0
// RVA : 0x00A2AEF0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ChangeAnimStateVia(
        idAI2 *this,
        const idEntity *result,
        aiAnimWeb_t animweb,
        const idAnimWebPath *destNode,
        const idAnimWebPath *viaNode,
        const aiAnimWait_t wait)
{
  char *data; // r6
  idEventArg *v9; // r25
  _BYTE v11[20]; // [sp+70h] [-160h] BYREF
  _BYTE v12[20]; // [sp+90h] [-140h] BYREF
  _BYTE v13[20]; // [sp+B0h] [-120h] BYREF
  _DWORD v14[5]; // [sp+D0h] [-100h] BYREF
  _DWORD v15[5]; // [sp+F0h] [-E0h] BYREF
  _DWORD v16[5]; // [sp+110h] [-C0h] BYREF
  int v17; // [sp+130h] [-A0h]
  aiAnimWeb_t v18; // [sp+134h] [-9Ch]
  const idEventArg *v19; // [sp+138h] [-98h]
  const idEventArg *v20; // [sp+13Ch] [-94h]
  idEventArg v21; // [sp+150h] [-80h] BYREF
  idEventReceiver v22[8]; // [sp+170h] [-60h] BYREF

  v14[1] = wait;
  v18 = animweb;
  HIBYTE(v14[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = wait != AIANIMWAIT_DONT_WAIT;
  data = destNode->data;
  v15[1] = viaNode->data;
  v16[1] = data;
  HIBYTE(v15[0]) = 49;
  HIBYTE(v16[0]) = 49;
  HIBYTE(v17) = 105;
  v9 = idEventArg::idEventArg(this: &v21, data: result);
  memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
  memcpy(Dst: v12, Src: v15, Size: sizeof(v12));
  memcpy(Dst: v11, Src: v16, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v22,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v9->type,
    arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v17, 32),
    arg4: v19,
    arg5: v20);
  return this;
}


// ========================================================================
// ?Action_ForceAnimState@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@HW4aiAnimWait_t@@@Z
// EA  : 0x82A2AFD8
// RVA : 0x00A2AFD8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ForceAnimState(
        idAI2 *this,
        const idEntity *result,
        aiAnimWeb_t animweb,
        const idAnimWebPath *destNode,
        const int blendDurationMS,
        const aiAnimWait_t wait)
{
  idEventArg *v8; // r25
  _BYTE v10[20]; // [sp+70h] [-160h] BYREF
  _BYTE v11[20]; // [sp+90h] [-140h] BYREF
  _BYTE v12[20]; // [sp+B0h] [-120h] BYREF
  _DWORD v13[5]; // [sp+D0h] [-100h] BYREF
  _DWORD v14[5]; // [sp+F0h] [-E0h] BYREF
  _DWORD v15[5]; // [sp+110h] [-C0h] BYREF
  int v16; // [sp+130h] [-A0h]
  aiAnimWeb_t v17; // [sp+134h] [-9Ch]
  const idEventArg *v18; // [sp+138h] [-98h]
  const idEventArg *v19; // [sp+13Ch] [-94h]
  idEventArg v20; // [sp+150h] [-80h] BYREF
  idEventReceiver v21[8]; // [sp+170h] [-60h] BYREF

  v13[1] = wait;
  v14[1] = blendDurationMS;
  v17 = animweb;
  HIBYTE(v13[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = wait != AIANIMWAIT_DONT_WAIT;
  v15[1] = destNode->data;
  HIBYTE(v14[0]) = 105;
  HIBYTE(v15[0]) = 49;
  HIBYTE(v16) = 105;
  v8 = idEventArg::idEventArg(this: &v20, data: result);
  memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
  memcpy(Dst: v11, Src: v14, Size: sizeof(v11));
  memcpy(Dst: v10, Src: v15, Size: sizeof(v10));
  idEventReceiver::ProcessEvent(
    this: v21,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v16, 32),
    arg4: v18,
    arg5: v19);
  return this;
}


// ========================================================================
// ?Action_Dodge@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82A2B0C0
// RVA : 0x00A2B0C0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Dodge(idAI2 *this, eventVoid *result, const idVec3 *dodgeFrom)
{
  idLib::Warning(fmt: "idAI2::Action_Dodge is called, but not implemented", result, dodgeFrom);
  return this;
}


// ========================================================================
// ?Action_Wait@idAI2@@QAA?AVeventVoid@@H@Z
// EA  : 0x82A2B0F8
// RVA : 0x00A2B0F8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Wait(idAI2 *this, const idEntity *result, const int milliseconds)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_Melee@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@@Z
// EA  : 0x82A2B180
// RVA : 0x00A2B180
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Melee(idAI2 *this, const idEntity *result, overrideAnim_t overrideAnim)
{
  idEventArg *v5; // r26
  _BYTE v7[20]; // [sp+70h] [-110h] BYREF
  _BYTE v8[20]; // [sp+90h] [-F0h] BYREF
  float v9[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v10[5]; // [sp+D0h] [-B0h] BYREF
  int v11; // [sp+F0h] [-90h]
  overrideAnim_t v12; // [sp+F4h] [-8Ch]
  const idEventArg *v13; // [sp+F8h] [-88h]
  idEventArg v14; // [sp+110h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+130h] [-50h] BYREF

  v12 = overrideAnim;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v9[1] = vec3_origin.x;
  v9[2] = vec3_origin.y;
  v9[3] = vec3_origin.z;
  HIBYTE(v9[0]) = 118;
  HIBYTE(v10[0]) = 105;
  v10[1] = 0;
  HIBYTE(v11) = 105;
  v5 = idEventArg::idEventArg(this: &v14, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  memcpy(Dst: v7, Src: v10, Size: sizeof(v7));
  idEventReceiver::ProcessEvent(
    this: v15,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v11, 32),
    arg4: v13);
  return this;
}


// ========================================================================
// ?Action_TurnToPoint@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82A2B260
// RVA : 0x00A2B260
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_TurnToPoint(idAI2 *this, const idEntity *result, const idVec3 *point)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_TurnToEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A2B2F8
// RVA : 0x00A2B2F8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_TurnToEntity(idAI2 *this, const idEntity *result, const idEntity *ent)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+70h] [-80h] BYREF
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  idEventArg::idEventArg(this: &v7, data: ent);
  v5 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_TurnToEntityWithOffset@idAI2@@QAA?AVeventVoid@@PBVidEntity@@M@Z
// EA  : 0x82A2B380
// RVA : 0x00A2B380
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_TurnToEntityWithOffset(
        idAI2 *this,
        const idEntity *result,
        const idEntity *ent,
        double yawOffset)
{
  idEventArg *v6; // r28
  idEventArg *v7; // r27
  _BYTE v9[20]; // [sp+70h] [-D0h] BYREF
  float v10[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v11; // [sp+B0h] [-90h] BYREF
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v10[1] = yawOffset;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  HIBYTE(v10[0]) = 102;
  v6 = idEventArg::idEventArg(this: &v11, data: ent);
  v7 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v6->type, 32));
  return this;
}


// ========================================================================
// ?Action_Dive@idAI2@@QAA?AVeventVoid@@MM@Z
// EA  : 0x82A2B428
// RVA : 0x00A2B428
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Dive(idAI2 *this, const idEntity *result, double diveYaw, double faceYaw)
{
  idEventArg *v6; // r26
  _BYTE v8[20]; // [sp+70h] [-110h] BYREF
  _BYTE v9[20]; // [sp+90h] [-F0h] BYREF
  float v10[5]; // [sp+B0h] [-D0h] BYREF
  float v11[5]; // [sp+D0h] [-B0h] BYREF
  int v12; // [sp+F0h] [-90h]
  int v13; // [sp+F4h] [-8Ch]
  const idEventArg *v14; // [sp+F8h] [-88h]
  idEventArg v15; // [sp+110h] [-70h] BYREF
  idEventReceiver v16[6]; // [sp+130h] [-50h] BYREF

  v10[1] = faceYaw;
  v11[1] = diveYaw;
  HIBYTE(v10[0]) = 102;
  HIBYTE(v11[0]) = 102;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  HIBYTE(v12) = 105;
  v13 = 33;
  v6 = idEventArg::idEventArg(this: &v15, data: result);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  memcpy(Dst: v8, Src: v11, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v16,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v12, 32),
    arg4: v14);
  return this;
}


// ========================================================================
// ?Action_WaitForEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@M@Z
// EA  : 0x82A2B4F0
// RVA : 0x00A2B4F0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForEntity(idAI2 *this, const idEntity *result, const idEntity *ent, double range)
{
  idEventArg *v6; // r28
  idEventArg *v7; // r27
  _BYTE v9[20]; // [sp+70h] [-D0h] BYREF
  float v10[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v11; // [sp+B0h] [-90h] BYREF
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v10[1] = range;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  HIBYTE(v10[0]) = 102;
  v6 = idEventArg::idEventArg(this: &v11, data: ent);
  v7 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v6->type, 32));
  return this;
}


// ========================================================================
// ?Action_EnterVehicle@idAI2@@QAA?AVeventVoid@@PBVidEntity@@0@Z
// EA  : 0x82A2B598
// RVA : 0x00A2B598
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnterVehicle(
        idAI2 *this,
        const idEntity *result,
        const idEntity *vehicle,
        const idEntity *vai)
{
  idEventArg *v7; // r28
  idEventArg *v8; // r29
  idEventArg *v9; // r27
  _BYTE v11[20]; // [sp+70h] [-D0h] BYREF
  idEventArg v12; // [sp+90h] [-B0h] BYREF
  idEventArg v13; // [sp+B0h] [-90h] BYREF
  idEventArg v14; // [sp+D0h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v7 = idEventArg::idEventArg(this: &v12, data: vai);
  v8 = idEventArg::idEventArg(this: &v13, data: vehicle);
  v9 = idEventArg::idEventArg(this: &v14, data: result);
  memcpy(Dst: v11, Src: v7, Size: sizeof(v11));
  idEventReceiver::ProcessEvent(
    this: v15,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v9->type,
    arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v8->type, 32));
  return this;
}


// ========================================================================
// ?Action_PlayVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidDeclVoiceOver@@W4aiActionBool_t@@@Z
// EA  : 0x82A2B648
// RVA : 0x00A2B648
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PlayVoiceOver(
        idAI2 *this,
        const idEntity *result,
        const idDeclVoiceOver *decl,
        const aiActionBool_t waitUntilFinished)
{
  idEventArg *v8; // r27
  _BYTE v10[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v11[5]; // [sp+90h] [-B0h] BYREF
  int v12; // [sp+B0h] [-90h]
  const idDeclVoiceOver *v13; // [sp+B4h] [-8Ch]
  idEventArg v14; // [sp+D0h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+F0h] [-50h] BYREF

  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclVoiceOver::resourceList )
  {
    v13 = decl;
    HIBYTE(v11[0]) = 105;
    HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
    v11[1] = waitUntilFinished != AIACTION_FALSE;
    HIBYTE(v12) = 100;
    v8 = idEventArg::idEventArg(this: &v14, data: result);
    memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
    idEventReceiver::ProcessEvent(
      this: v15,
      result: (idEventArg *)&result[77].spawnPosition.z,
      ev: *(const idEventDef **)&v8->type,
      arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v12, 32));
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Action_PlayVoiceOver",
      decl,
      declInfo: &idDeclVoiceOver::resourceList);
    return this;
  }
}


// ========================================================================
// ?Action_PlayInteractionVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidDeclVoiceOver@@PBVidEntity@@M_N@Z
// EA  : 0x82A2B750
// RVA : 0x00A2B750
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PlayInteractionVoiceOver(
        idAI2 *this,
        const idEntity *result,
        const idDeclVoiceOver *decl,
        const idEntity *trackEntity,
        double abortDistance,
        const bool abortScript,
        unsigned __int8 a7)
{
  idEventArg *v13; // r26
  idEventArg *v14; // r25
  _BYTE v16[20]; // [sp+70h] [-160h] BYREF
  _BYTE v17[20]; // [sp+90h] [-140h] BYREF
  _BYTE v18[20]; // [sp+B0h] [-120h] BYREF
  _DWORD v19[5]; // [sp+D0h] [-100h] BYREF
  float v20[5]; // [sp+F0h] [-E0h] BYREF
  int v21; // [sp+110h] [-C0h]
  const idDeclVoiceOver *v22; // [sp+114h] [-BCh]
  const idEventArg *v23; // [sp+118h] [-B8h]
  const idEventArg *v24; // [sp+11Ch] [-B4h]
  idEventArg v25; // [sp+130h] [-A0h] BYREF
  idEventArg v26; // [sp+150h] [-80h] BYREF
  idEventReceiver v27[2]; // [sp+170h] [-60h] BYREF

  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclVoiceOver::resourceList )
  {
    v22 = decl;
    v20[1] = abortDistance;
    HIBYTE(v19[0]) = 105;
    v19[1] = a7;
    HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
    HIBYTE(v20[0]) = 102;
    HIBYTE(v21) = 100;
    v13 = idEventArg::idEventArg(this: &v25, data: trackEntity);
    v14 = idEventArg::idEventArg(this: &v26, data: result);
    memcpy(Dst: v18, Src: v19, Size: sizeof(v18));
    memcpy(Dst: v17, Src: v20, Size: sizeof(v17));
    memcpy(Dst: v16, Src: v13, Size: sizeof(v16));
    idEventReceiver::ProcessEvent(
      this: v27,
      result: (idEventArg *)&result[77].spawnPosition.z,
      ev: *(const idEventDef **)&v14->type,
      arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v21, 32),
      arg4: v23,
      arg5: v24);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Action_PlayInteractionVoiceOver",
      decl,
      declInfo: &idDeclVoiceOver::resourceList);
    return this;
  }
}


// ========================================================================
// ?Action_StopVoiceOver@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2B8A8
// RVA : 0x00A2B8A8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_StopVoiceOver(idAI2 *this, idAI2 *result)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  idAIVoiceController::StopVoiceOver(this: &result->aiVolatile.voiceController, ai: result);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  idFaceMgr::Reset(this: &result->aiVolatile.faceMgr, owner: result, ta: TreeAnimatorFromPresentable);
  return this;
}


// ========================================================================
// ?Action_PlayOverrideAnim@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@W4aiActionBool_t@@@Z
// EA  : 0x82A2B908
// RVA : 0x00A2B908
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PlayOverrideAnim(
        idAI2 *this,
        const idEntity *result,
        const overrideAnim_t overrideAnim,
        const aiActionBool_t cycle)
{
  idEventArg *v6; // r3
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v6 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_PlayOverrideAnimInterrupt@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@W4aiActionBool_t@@@Z
// EA  : 0x82A2B990
// RVA : 0x00A2B990
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PlayOverrideAnimInterrupt(
        idAI2 *this,
        const idEntity *result,
        const overrideAnim_t overrideAnim,
        const aiActionBool_t cycle)
{
  idEventArg *v6; // r3
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v6 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_HolsterWeapon@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2BA18
// RVA : 0x00A2BA18
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_HolsterWeapon(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_DrawWeapon@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2BA98
// RVA : 0x00A2BA98
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_DrawWeapon(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_PerformCoverAction@idAI2@@QAA?AVeventVoid@@W4coverAction_t@@H@Z
// EA  : 0x82A2BB18
// RVA : 0x00A2BB18
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_PerformCoverAction(
        idAI2 *this,
        const idEntity *result,
        coverAction_t coverAction,
        const int duration)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  coverAction_t v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v9[1] = duration;
  v11 = coverAction;
  HIBYTE(v9[0]) = 105;
  HIBYTE(v10) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_WaitForPlayerInteraction@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2BBB8
// RVA : 0x00A2BBB8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForPlayerInteraction(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+90h] [-60h] BYREF
  idEventReceiver v7[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v4->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_WaitForPlayerInteractionDist@idAI2@@QAA?AVeventVoid@@M@Z
// EA  : 0x82A2BC48
// RVA : 0x00A2BC48
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForPlayerInteractionDist(idAI2 *this, const idEntity *result, double maxDistance)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_WaitForAIVar@idAI2@@QAA?AVeventVoid@@PBDW4aiVarOp_t@@0@Z
// EA  : 0x82A2BCD0
// RVA : 0x00A2BCD0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_WaitForAIVar(
        idAI2 *this,
        const idEntity *result,
        const char *name,
        const aiVarOp_t op,
        const char *value)
{
  idEventArg *v7; // r26
  _BYTE v9[20]; // [sp+70h] [-110h] BYREF
  _BYTE v10[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v11[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+D0h] [-B0h] BYREF
  int v13; // [sp+F0h] [-90h]
  const char *v14; // [sp+F4h] [-8Ch]
  const idEventArg *v15; // [sp+F8h] [-88h]
  idEventArg v16; // [sp+110h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+130h] [-50h] BYREF

  v11[1] = value;
  v12[1] = op;
  v14 = name;
  HIBYTE(v11[0]) = 115;
  HIBYTE(v13) = 115;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 1;
  HIBYTE(v12[0]) = 105;
  v7 = idEventArg::idEventArg(this: &v16, data: result);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  memcpy(Dst: v9, Src: v12, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32),
    arg4: v15);
  return this;
}


// ========================================================================
// ?Action_SetAlertCycle@idAI2@@QAA?AVeventVoid@@W4alertCycle_t@@@Z
// EA  : 0x82A2BD90
// RVA : 0x00A2BD90
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetAlertCycle(idAI2 *this, const idEntity *result, const alertCycle_t alertCycle)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetSubWeb@idAI2@@QAA?AVeventVoid@@W4aiSubWeb_t@@@Z
// EA  : 0x82A2BE18
// RVA : 0x00A2BE18
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetSubWeb(idAI2 *this, const idEntity *result, const aiSubWeb_t subWeb)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetFocus@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiActionBool_t@@11W4aimPoint_t@@@Z
// EA  : 0x82A2BEA0
// RVA : 0x00A2BEA0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetFocus(
        idAI2 *this,
        const idEntity *result,
        const idEntity *ent,
        const aiActionBool_t aiming,
        const aiActionBool_t keepFocusInView,
        const aiActionBool_t trackOnlyVisible,
        const aimPoint_t aimPoint)
{
  idEventArg *v9; // r25
  idEventArg *v10; // r24
  const idEventArg *v12; // [sp+8h] [-208h]
  _BYTE v13[20]; // [sp+70h] [-1A0h] BYREF
  _BYTE v14[20]; // [sp+90h] [-180h] BYREF
  _BYTE v15[20]; // [sp+B0h] [-160h] BYREF
  _BYTE v16[20]; // [sp+D0h] [-140h] BYREF
  _DWORD v17[5]; // [sp+F0h] [-120h] BYREF
  _DWORD v18[5]; // [sp+110h] [-100h] BYREF
  _DWORD v19[5]; // [sp+130h] [-E0h] BYREF
  _DWORD v20[5]; // [sp+150h] [-C0h] BYREF
  idEventArg v21; // [sp+170h] [-A0h] BYREF
  idEventArg v22; // [sp+190h] [-80h] BYREF
  idEventReceiver v23[8]; // [sp+1B0h] [-60h] BYREF

  v18[1] = aimPoint;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v20[1] = trackOnlyVisible != AIACTION_FALSE;
  v19[1] = keepFocusInView != AIACTION_FALSE;
  HIBYTE(v18[0]) = 105;
  HIBYTE(v20[0]) = 105;
  HIBYTE(v19[0]) = 105;
  HIBYTE(v17[0]) = 105;
  v17[1] = aiming != AIACTION_FALSE;
  v9 = idEventArg::idEventArg(this: &v21, data: ent);
  v10 = idEventArg::idEventArg(this: &v22, data: result);
  memcpy(Dst: v16, Src: v18, Size: sizeof(v16));
  memcpy(Dst: v15, Src: v20, Size: sizeof(v15));
  memcpy(Dst: v14, Src: v19, Size: sizeof(v14));
  memcpy(Dst: v13, Src: v17, Size: sizeof(v13));
  idEventReceiver::ProcessEvent(
    this: v23,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v10->type,
    arg1: (const idEventArg *)LODWORD(v10->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v10->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v9->type, 32),
    arg4: (const idEventArg *)LODWORD(v9->value.v[1]),
    arg5: (const idEventArg *)LODWORD(v9->value.v[2]),
    arg6: v12);
  return this;
}


// ========================================================================
// ?Action_ClearLookFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2BFB8
// RVA : 0x00A2BFB8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ClearLookFocus(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_ClearAimFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2C038
// RVA : 0x00A2C038
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ClearAimFocus(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_SetAimPoint@idAI2@@QAA?AVeventVoid@@W4aimPoint_t@@@Z
// EA  : 0x82A2C0B8
// RVA : 0x00A2C0B8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetAimPoint(idAI2 *this, const idEntity *result, const aimPoint_t aimPoint)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetFireMode@idAI2@@QAA?AVeventVoid@@W4aiFireMode_t@@@Z
// EA  : 0x82A2C140
// RVA : 0x00A2C140
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetFireMode(idAI2 *this, const idEntity *result, const aiFireMode_t fireMode)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetScriptAbort@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA  : 0x82A2C1C8
// RVA : 0x00A2C1C8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetScriptAbort(
        idAI2 *this,
        const idEntity *result,
        const aiActionBool_t AbortOnCombat,
        const aiActionBool_t AbortOnSearch)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  BOOL v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v9[1] = (_cntlzw(AbortOnSearch - 1) & 0x20) != 0;
  HIBYTE(v9[0]) = 105;
  HIBYTE(v10) = 105;
  v11 = (_cntlzw(AbortOnCombat - 1) & 0x20) != 0;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_SetPosture@idAI2@@QAA?AVeventVoid@@W4posture_t@@@Z
// EA  : 0x82A2C280
// RVA : 0x00A2C280
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetPosture(idAI2 *this, const idEntity *result, const posture_t state)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetWalkState@idAI2@@QAA?AVeventVoid@@W4walkState_t@@@Z
// EA  : 0x82A2C308
// RVA : 0x00A2C308
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetWalkState(idAI2 *this, const idEntity *result, const walkState_t state)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetSitState@idAI2@@QAA?AVeventVoid@@W4sitState_t@@@Z
// EA  : 0x82A2C390
// RVA : 0x00A2C390
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetSitState(idAI2 *this, const idEntity *result, const sitState_t state)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetStandState@idAI2@@QAA?AVeventVoid@@W4standState_t@@@Z
// EA  : 0x82A2C418
// RVA : 0x00A2C418
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetStandState(idAI2 *this, const idEntity *result, const standState_t state)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetIdleState@idAI2@@QAA?AVeventVoid@@W4runIndexType_t@@@Z
// EA  : 0x82A2C4A0
// RVA : 0x00A2C4A0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetIdleState(idAI2 *this, const idEntity *result, const runIndexType_t _indexType)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_IgnorePlayerApproach@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2C528
// RVA : 0x00A2C528
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_IgnorePlayerApproach(
        idAI2 *this,
        const idEntity *result,
        const aiActionBool_t permanent)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_NoticePlayerApproach@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2C5B8
// RVA : 0x00A2C5B8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_NoticePlayerApproach(
        idAI2 *this,
        const idEntity *result,
        const aiActionBool_t permanent)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_GiveItem@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclInventory@@@Z
// EA  : 0x82A2C648
// RVA : 0x00A2C648
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_GiveItem(
        idAI2 *this,
        const idEntity *result,
        const idEntity *giveTo,
        const idDeclInventory *itemDecl)
{
  idEventArg *v8; // r28
  idEventArg *v9; // r27
  _BYTE v11[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v13; // [sp+B0h] [-90h] BYREF
  idEventArg v14; // [sp+D0h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+F0h] [-50h] BYREF

  if ( itemDecl != nullptr && itemDecl->GetDeclInfo(this: itemDecl) == &idDeclInventory::resourceList )
  {
    v12[1] = itemDecl;
    HIBYTE(v12[0]) = 100;
    HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
    v8 = idEventArg::idEventArg(this: &v13, data: giveTo);
    v9 = idEventArg::idEventArg(this: &v14, data: result);
    memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
    idEventReceiver::ProcessEvent(
      this: v15,
      result: (idEventArg *)&result[77].spawnPosition.z,
      ev: *(const idEventDef **)&v9->type,
      arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v8->type, 32));
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Action_GiveItem",
      decl: itemDecl,
      declInfo: &idDeclInventory::resourceList);
    return this;
  }
}


// ========================================================================
// ?Action_TakeItem@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclInventory@@@Z
// EA  : 0x82A2C748
// RVA : 0x00A2C748
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_TakeItem(
        idAI2 *this,
        const idEntity *result,
        const idEntity *takeFrom,
        const idDeclInventory *itemDecl)
{
  idEventArg *v8; // r28
  idEventArg *v9; // r27
  _BYTE v11[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v13; // [sp+B0h] [-90h] BYREF
  idEventArg v14; // [sp+D0h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+F0h] [-50h] BYREF

  if ( itemDecl != nullptr && itemDecl->GetDeclInfo(this: itemDecl) == &idDeclInventory::resourceList )
  {
    v12[1] = itemDecl;
    HIBYTE(v12[0]) = 100;
    HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
    v8 = idEventArg::idEventArg(this: &v13, data: takeFrom);
    v9 = idEventArg::idEventArg(this: &v14, data: result);
    memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
    idEventReceiver::ProcessEvent(
      this: v15,
      result: (idEventArg *)&result[77].spawnPosition.z,
      ev: *(const idEventDef **)&v9->type,
      arg1: (const idEventArg *)LODWORD(v9->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v9->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v8->type, 32));
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idAI2::Action_TakeItem",
      decl: itemDecl,
      declInfo: &idDeclInventory::resourceList);
    return this;
  }
}


// ========================================================================
// ?GetPlayerTarget@idAI2@@QBAPAVidPlayer@@W4aiPlayer_t@@@Z
// EA  : 0x82A2C848
// RVA : 0x00A2C848
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idPlayer *__fastcall idAI2::GetPlayerTarget(idAI2 *this, unsigned int player)
{
  idPhysics *Physics; // r3
  float *v4; // r28
  idPlayer *v5; // r27
  int v6; // r30
  double v7; // fp31
  idPlayer *v8; // r3
  idPlayer *v9; // r31
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp10
  double v13; // fp8
  int v15; // r30
  double v16; // fp31
  idPlayer *v17; // r3
  idPlayer *v18; // r31
  idPhysics *v19; // r3
  float *v20; // r3
  double v21; // fp10
  double v22; // fp8
  int v23; // r29
  double v24; // fp31
  idPlayer *v25; // r3
  idPlayer *v26; // r31
  idTungstenHealth *p_playerHealth; // r30
  int v28; // r29
  double v29; // fp31
  idPlayer *v30; // r3
  idPlayer *v31; // r31
  idTungstenHealth *v32; // r30

  Physics = idEntity::GetPhysics(this);
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v5 = nullptr;
  if ( player > 3 )
    return v5;
  if ( player == 1 )
  {
    v15 = 0;
    v16 = 0.0;
    do
    {
      v17 = idGameLocal::GetPlayer(this: gameLocal, i: v15);
      v18 = v17;
      if ( v17 != nullptr )
      {
        v19 = idEntity::GetPhysics(this: v17);
        v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
        v21 = (float)(v20[1] - v4[1]);
        v22 = (float)(v20[2] - v4[2]);
        if ( (float)((float)((float)(*v20 - *v4) * (float)(*v20 - *v4))
                   + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))) > v16 )
        {
          v5 = v18;
          v16 = (float)((float)((float)(*v20 - *v4) * (float)(*v20 - *v4))
                      + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)));
        }
      }
      ++v15;
    }
    while ( v15 < 6 );
    return v5;
  }
  if ( player == 2 )
  {
    v23 = 0;
    v24 = 3.4028235e38;
    do
    {
      v25 = idGameLocal::GetPlayer(this: gameLocal, i: v23);
      v26 = v25;
      if ( v25 != nullptr )
      {
        p_playerHealth = &v25->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v25->playerHealth.GetTotalCurHealth_Impl)(a1: &v25->playerHealth) < v24 )
        {
          v5 = v26;
          v24 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetTotalCurHealth_Impl)(a1: p_playerHealth);
        }
      }
      ++v23;
    }
    while ( v23 < 6 );
    return v5;
  }
  if ( player != 0 )
  {
    v28 = 0;
    v29 = 0.0;
    do
    {
      v30 = idGameLocal::GetPlayer(this: gameLocal, i: v28);
      v31 = v30;
      if ( v30 != nullptr )
      {
        v32 = &v30->playerHealth;
        if ( ((double (__fastcall *)(idTungstenHealth *))v30->playerHealth.GetTotalCurHealth_Impl)(a1: &v30->playerHealth) > v29 )
        {
          v5 = v31;
          v29 = ((double (__fastcall *)(idTungstenHealth *))v32->GetTotalCurHealth_Impl)(a1: v32);
        }
      }
      ++v28;
    }
    while ( v28 < 6 );
    return v5;
  }
  v6 = 0;
  v7 = 3.4028235e38;
  do
  {
    v8 = idGameLocal::GetPlayer(this: gameLocal, i: v6);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = idEntity::GetPhysics(this: v8);
      v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
      v12 = (float)(v11[1] - v4[1]);
      v13 = (float)(v11[2] - v4[2]);
      if ( (float)((float)((float)(*v11 - *v4) * (float)(*v11 - *v4))
                 + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) < v7 )
      {
        v5 = v9;
        v7 = (float)((float)((float)(*v11 - *v4) * (float)(*v11 - *v4))
                   + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)));
      }
    }
    ++v6;
  }
  while ( v6 < 6 );
  return v5;
}


// ========================================================================
// ?Action_SetPlayerEnemy@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA  : 0x82A2CAD0
// RVA : 0x00A2CAD0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetPlayerEnemy(idAI2 *this, const idEntity *result, const aiPlayer_t player)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetEnemy@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A2CB58
// RVA : 0x00A2CB58
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetEnemy(idAI2 *this, const idEntity *result, const idEntity *entity)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+70h] [-80h] BYREF
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  idEventArg::idEventArg(this: &v7, data: entity);
  v5 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SearchToTarget@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA  : 0x82A2CBE0
// RVA : 0x00A2CBE0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SearchToTarget(idAI2 *this, const idEntity *result, const idEntity *target)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+70h] [-80h] BYREF
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  idEventArg::idEventArg(this: &v7, data: target);
  v5 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetPlayerFocus@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@W4aiActionBool_t@@1@Z
// EA  : 0x82A2CC68
// RVA : 0x00A2CC68
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetPlayerFocus(
        idAI2 *this,
        const idEntity *result,
        aiPlayer_t player,
        const aiActionBool_t aiming,
        const aiActionBool_t keepFocusInView)
{
  idEventArg *v7; // r24
  const idEventArg *v9; // [sp+8h] [-208h]
  _BYTE v10[20]; // [sp+70h] [-1A0h] BYREF
  _BYTE v11[20]; // [sp+90h] [-180h] BYREF
  _BYTE v12[20]; // [sp+B0h] [-160h] BYREF
  _BYTE v13[20]; // [sp+D0h] [-140h] BYREF
  _DWORD v14[5]; // [sp+F0h] [-120h] BYREF
  _DWORD v15[5]; // [sp+110h] [-100h] BYREF
  int v16; // [sp+130h] [-E0h]
  aiPlayer_t v17; // [sp+134h] [-DCh]
  const idEventArg *v18; // [sp+138h] [-D8h]
  const idEventArg *v19; // [sp+13Ch] [-D4h]
  _DWORD v20[5]; // [sp+150h] [-C0h] BYREF
  _DWORD v21[5]; // [sp+170h] [-A0h] BYREF
  idEventArg v22; // [sp+190h] [-80h] BYREF
  idEventReceiver v23[8]; // [sp+1B0h] [-60h] BYREF

  v17 = player;
  HIBYTE(v15[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v20[1] = keepFocusInView != AIACTION_FALSE;
  v15[1] = 1;
  HIBYTE(v21[0]) = 105;
  v14[1] = aiming != AIACTION_FALSE;
  v21[1] = 1;
  HIBYTE(v20[0]) = 105;
  HIBYTE(v14[0]) = 105;
  HIBYTE(v16) = 105;
  v7 = idEventArg::idEventArg(this: &v22, data: result);
  memcpy(Dst: v13, Src: v15, Size: sizeof(v13));
  memcpy(Dst: v12, Src: v21, Size: sizeof(v12));
  memcpy(Dst: v11, Src: v20, Size: sizeof(v11));
  memcpy(Dst: v10, Src: v14, Size: sizeof(v10));
  idEventReceiver::ProcessEvent(
    this: v23,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v16, 32),
    arg4: v18,
    arg5: v19,
    arg6: v9);
  return this;
}


// ========================================================================
// ?Action_SetActionNodeGroup@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA  : 0x82A2CD70
// RVA : 0x00A2CD70
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetActionNodeGroup(idAI2 *this, const idEntity *result, const char *group)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_Trigger@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82A2CDF8
// RVA : 0x00A2CDF8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_Trigger(idAI2 *this, const idEntity *result, idEntity *ent)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+70h] [-80h] BYREF
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  idEventArg::idEventArg(this: &v7, data: ent);
  v5 = idEventArg::idEventArg(this: &v8, data: result);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_EnableDamage@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA  : 0x82A2CE80
// RVA : 0x00A2CE80
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnableDamage(
        idAI2 *this,
        const idEntity *result,
        const aiActionBool_t enabled,
        const aiActionBool_t permanent)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  BOOL v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(v9[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v9[1] = permanent != AIACTION_FALSE;
  HIBYTE(v10) = 105;
  v11 = enabled != AIACTION_FALSE;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_EnablePain@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2CF30
// RVA : 0x00A2CF30
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnablePain(idAI2 *this, const idEntity *result, const aiActionBool_t enabled)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_EnableAutoFocus@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA  : 0x82A2CFC0
// RVA : 0x00A2CFC0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnableAutoFocus(
        idAI2 *this,
        const idEntity *result,
        const aiActionBool_t enabled,
        const aiActionBool_t permanent)
{
  idEventArg *v6; // r27
  _BYTE v8[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v9[5]; // [sp+90h] [-B0h] BYREF
  int v10; // [sp+B0h] [-90h]
  BOOL v11; // [sp+B4h] [-8Ch]
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  HIBYTE(v9[0]) = 105;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v9[1] = permanent != AIACTION_FALSE;
  HIBYTE(v10) = 105;
  v11 = enabled != AIACTION_FALSE;
  v6 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v8, Src: v9, Size: sizeof(v8));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v6->type,
    arg1: (const idEventArg *)LODWORD(v6->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v6->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v10, 32));
  return this;
}


// ========================================================================
// ?Action_EnableBodyRotation@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2D070
// RVA : 0x00A2D070
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnableBodyRotation(idAI2 *this, const idEntity *result, const aiActionBool_t enabled)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_EnableWalkIK@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2D100
// RVA : 0x00A2D100
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnableWalkIK(idAI2 *this, const idEntity *result, const aiActionBool_t enabled)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_EnableHeadTracking@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA  : 0x82A2D190
// RVA : 0x00A2D190
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_EnableHeadTracking(idAI2 *this, const idEntity *result, const aiActionBool_t enabled)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ForceOpenCombat@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA  : 0x82A2D220
// RVA : 0x00A2D220
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ForceOpenCombat(idAI2 *this, const idEntity *result, const aiPlayer_t player)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ForceAwarenessByDistance@idAI2@@QAA?AVeventVoid@@M_N0@Z
// EA  : 0x82A2D2A8
// RVA : 0x00A2D2A8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ForceAwarenessByDistance(
        idAI2 *this,
        const idEntity *result,
        double radius,
        bool playerFlag,
        bool aiFlag,
        unsigned __int8 a6)
{
  idEventArg *v8; // r26
  _BYTE v10[20]; // [sp+70h] [-110h] BYREF
  _BYTE v11[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v12[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v13[5]; // [sp+D0h] [-B0h] BYREF
  int v14; // [sp+F0h] [-90h]
  float v15; // [sp+F4h] [-8Ch]
  const idEventArg *v16; // [sp+F8h] [-88h]
  idEventArg v17; // [sp+110h] [-70h] BYREF
  idEventReceiver v18[6]; // [sp+130h] [-50h] BYREF

  v15 = radius;
  v12[1] = a6;
  v13[1] = aiFlag;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  HIBYTE(v12[0]) = 105;
  HIBYTE(v13[0]) = 105;
  HIBYTE(v14) = 102;
  v8 = idEventArg::idEventArg(this: &v17, data: result);
  memcpy(Dst: v11, Src: v12, Size: sizeof(v11));
  memcpy(Dst: v10, Src: v13, Size: sizeof(v10));
  idEventReceiver::ProcessEvent(
    this: v18,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v14, 32),
    arg4: v16);
  return this;
}


// ========================================================================
// ?Action_ForcePlayerInteraction@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA  : 0x82A2D370
// RVA : 0x00A2D370
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ForcePlayerInteraction(idAI2 *this, const idEntity *result, const aiPlayer_t player)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetAIVar@idAI2@@QAA?AVeventVoid@@PBDW4aiVarType_t@@0@Z
// EA  : 0x82A2D3F8
// RVA : 0x00A2D3F8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetAIVar(
        idAI2 *this,
        const idEntity *result,
        const char *name,
        const aiVarType_t type,
        const char *value)
{
  idEventArg *v7; // r26
  _BYTE v9[20]; // [sp+70h] [-110h] BYREF
  _BYTE v10[20]; // [sp+90h] [-F0h] BYREF
  _DWORD v11[5]; // [sp+B0h] [-D0h] BYREF
  _DWORD v12[5]; // [sp+D0h] [-B0h] BYREF
  int v13; // [sp+F0h] [-90h]
  const char *v14; // [sp+F4h] [-8Ch]
  const idEventArg *v15; // [sp+F8h] [-88h]
  idEventArg v16; // [sp+110h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+130h] [-50h] BYREF

  v11[1] = value;
  v12[1] = type;
  v14 = name;
  HIBYTE(v11[0]) = 115;
  HIBYTE(v13) = 115;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  HIBYTE(v12[0]) = 105;
  v7 = idEventArg::idEventArg(this: &v16, data: result);
  memcpy(Dst: v10, Src: v11, Size: sizeof(v10));
  memcpy(Dst: v9, Src: v12, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v17,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v13, 32),
    arg4: v15);
  return this;
}


// ========================================================================
// ?Action_SetScriptFlag@idAI2@@QAA?AVeventVoid@@W4aiActionScriptFlags_t@@@Z
// EA  : 0x82A2D4B8
// RVA : 0x00A2D4B8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetScriptFlag(idAI2 *this, const idEntity *result, const aiActionScriptFlags_t flag)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ClearScriptFlag@idAI2@@QAA?AVeventVoid@@W4aiActionScriptFlags_t@@@Z
// EA  : 0x82A2D540
// RVA : 0x00A2D540
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ClearScriptFlag(idAI2 *this, const idEntity *result, const aiActionScriptFlags_t flag)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetPerceptionFlag@idAI2@@QAA?AVeventVoid@@W4aiPerceptionFlags_t@@@Z
// EA  : 0x82A2D5C8
// RVA : 0x00A2D5C8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetPerceptionFlag(idAI2 *this, const idEntity *result, const aiPerceptionFlags_t flag)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ClearPerceptionFlag@idAI2@@QAA?AVeventVoid@@W4aiPerceptionFlags_t@@@Z
// EA  : 0x82A2D650
// RVA : 0x00A2D650
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ClearPerceptionFlag(
        idAI2 *this,
        const idEntity *result,
        const aiPerceptionFlags_t flag)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ClearWorldState@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2D6D8
// RVA : 0x00A2D6D8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ClearWorldState(idAI2 *this, const idEntity *result)
{
  idEventArg *v4; // r3
  idEventArg v6; // [sp+50h] [-50h] BYREF
  idEventReceiver v7[2]; // [sp+70h] [-30h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v4 = idEventArg::idEventArg(this: &v6, data: result);
  idEventReceiver::ProcessEvent(
    this: v7,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v4->type,
    arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
  return this;
}


// ========================================================================
// ?Action_ShowAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA  : 0x82A2D758
// RVA : 0x00A2D758
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ShowAttachment(idAI2 *this, const idEntity *result, const char *slotName)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_HideAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA  : 0x82A2D7E0
// RVA : 0x00A2D7E0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_HideAttachment(idAI2 *this, const idEntity *result, const char *slotName)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_DropAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA  : 0x82A2D868
// RVA : 0x00A2D868
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_DropAttachment(idAI2 *this, const idEntity *result, const char *slotName)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetMoveMode@idAI2@@QAA?AVeventVoid@@W4aiMovementMode_t@@@Z
// EA  : 0x82A2D8F0
// RVA : 0x00A2D8F0
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetMoveMode(idAI2 *this, const idEntity *result, const aiMovementMode_t moveMode)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_SetAccuracy@idAI2@@QAA?AVeventVoid@@W4aiAccuracy_t@@@Z
// EA  : 0x82A2D978
// RVA : 0x00A2D978
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_SetAccuracy(idAI2 *this, const idEntity *result, const aiAccuracy_t accuracy)
{
  idEventArg *v5; // r3
  idEventArg v7; // [sp+90h] [-60h] BYREF
  idEventReceiver v8[5]; // [sp+B0h] [-40h] BYREF

  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  v5 = idEventArg::idEventArg(this: &v7, data: result);
  idEventReceiver::ProcessEvent(
    this: v8,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v5->value.v[2]));
  return this;
}


// ========================================================================
// ?Action_ScriptedAnimWeb@idAI2@@QAA?AVeventVoid@@PBVidEntity@@H@Z
// EA  : 0x82A2DA00
// RVA : 0x00A2DA00
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ScriptedAnimWeb(
        idAI2 *this,
        const idEntity *result,
        const idEntity *scriptedAnimWeb,
        const int loopInterval)
{
  idEventArg *v6; // r28
  idEventArg *v7; // r27
  _BYTE v9[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v10[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v11; // [sp+B0h] [-90h] BYREF
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v10[1] = loopInterval;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  HIBYTE(v10[0]) = 105;
  v6 = idEventArg::idEventArg(this: &v11, data: scriptedAnimWeb);
  v7 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v6->type, 32));
  return this;
}


// ========================================================================
// ?Action_MoveToScenePoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4moveToScenePointFlags_t@@@Z
// EA  : 0x82A2DAA8
// RVA : 0x00A2DAA8
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_MoveToScenePoint(
        idAI2 *this,
        const idEntity *result,
        const idEntity *scenepoint,
        const moveToScenePointFlags_t mtspFlags)
{
  idEventArg *v6; // r28
  idEventArg *v7; // r27
  _BYTE v9[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v10[5]; // [sp+90h] [-B0h] BYREF
  idEventArg v11; // [sp+B0h] [-90h] BYREF
  idEventArg v12; // [sp+D0h] [-70h] BYREF
  idEventReceiver v13[6]; // [sp+F0h] [-50h] BYREF

  v10[1] = mtspFlags;
  HIBYTE(result[77].spawnOrientation.mat[1].x) = 0;
  HIBYTE(v10[0]) = 105;
  v6 = idEventArg::idEventArg(this: &v11, data: scenepoint);
  v7 = idEventArg::idEventArg(this: &v12, data: result);
  memcpy(Dst: v9, Src: v10, Size: sizeof(v9));
  idEventReceiver::ProcessEvent(
    this: v13,
    result: (idEventArg *)&result[77].spawnPosition.z,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v6->type, 32));
  return this;
}


// ========================================================================
// ?Action_ReloadWeapon@idAI2@@QAA?AVeventVoid@@W4equipSlot_t@@PBD@Z
// EA  : 0x82A2DB50
// RVA : 0x00A2DB50
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ReloadWeapon(idAI2 *this, idActor *result, equipSlot_t slot, const char *ammoDeclName)
{
  idWeapon *EquippedWeapon; // r28
  const idDeclAmmo *v9; // r30
  const idInventoryCollection *v11; // r3
  idEventArg *v12; // r28
  _BYTE v13[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-B0h] BYREF
  int v15; // [sp+B0h] [-90h]
  equipSlot_t v16; // [sp+B4h] [-8Ch]
  idEventArg v17; // [sp+D0h] [-70h] BYREF
  idEventReceiver v18[6]; // [sp+F0h] [-50h] BYREF

  EquippedWeapon = idActor::GetEquippedWeapon(this: result, slot);
  if ( EquippedWeapon != nullptr )
  {
    if ( ammoDeclName == nullptr
      || (v9 = (const idDeclAmmo *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclAmmo::resourceList,
                                     name: ammoDeclName,
                                     makeDefault: false)) == nullptr )
    {
      idLib::Warning(fmt: "idAI2::Action_ReloadWeapon - unknown ammo decl '%s'", ammoDeclName);
      return this;
    }
    v11 = result->GetInventory_2(this: result);
    if ( idWeapon::CanReload(this: EquippedWeapon, inventory: v11, ammoDecl: v9, secondaryAmmo: false) )
    {
      v14[1] = v9;
      v16 = slot;
      HIBYTE(v14[0]) = 100;
      HIBYTE(v15) = 105;
      HIBYTE(result[5].inventory.net_addedItems[43].itemDecl) = 1;
      v12 = idEventArg::idEventArg(this: &v17, data: result);
      memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
      idEventReceiver::ProcessEvent(
        this: v18,
        result: (idEventArg *)&result[5].inventory.net_addedItems[41].setCount,
        ev: *(const idEventDef **)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v15, 32));
    }
  }
  return this;
}


// ========================================================================
// ?Action_ReloadWeaponTorso@idAI2@@QAA?AVeventVoid@@W4equipSlot_t@@PBD@Z
// EA  : 0x82A2DC90
// RVA : 0x00A2DC90
// PDB : w:\tech5\tungsten\game\ai\ai2_actions.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Action_ReloadWeaponTorso(
        idAI2 *this,
        idActor *result,
        equipSlot_t slot,
        const char *ammoDeclName)
{
  idWeapon *EquippedWeapon; // r28
  const idDeclAmmo *v9; // r30
  const idInventoryCollection *v11; // r3
  idEventArg *v12; // r28
  _BYTE v13[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-B0h] BYREF
  int v15; // [sp+B0h] [-90h]
  equipSlot_t v16; // [sp+B4h] [-8Ch]
  idEventArg v17; // [sp+D0h] [-70h] BYREF
  idEventReceiver v18[6]; // [sp+F0h] [-50h] BYREF

  idLib::Warning(fmt: "idAI2::Action_ReloadWeaponTorso is called");
  EquippedWeapon = idActor::GetEquippedWeapon(this: result, slot);
  if ( EquippedWeapon != nullptr )
  {
    if ( ammoDeclName == nullptr
      || (v9 = (const idDeclAmmo *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclAmmo::resourceList,
                                     name: ammoDeclName,
                                     makeDefault: false)) == nullptr )
    {
      idLib::Warning(fmt: "idAI2::Action_ReloadWeaponTorso - unknown ammo decl '%s'", ammoDeclName);
      return this;
    }
    v11 = result->GetInventory_2(this: result);
    if ( idWeapon::CanReload(this: EquippedWeapon, inventory: v11, ammoDecl: v9, secondaryAmmo: false) )
    {
      v14[1] = v9;
      v16 = slot;
      HIBYTE(v14[0]) = 100;
      HIBYTE(v15) = 105;
      HIBYTE(result[5].inventory.net_addedItems[43].itemDecl) = 1;
      v12 = idEventArg::idEventArg(this: &v17, data: result);
      memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
      idEventReceiver::ProcessEvent(
        this: v18,
        result: (idEventArg *)&result[5].inventory.net_addedItems[41].setCount,
        ev: *(const idEventDef **)&v12->type,
        arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v15, 32));
    }
  }
  return this;
}

