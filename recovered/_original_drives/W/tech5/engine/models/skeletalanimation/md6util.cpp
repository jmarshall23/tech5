
// ========================================================================
// ?FindMD6Anim@idMD6Util@@SAPBVidMD6Anim@@PBVidDeclAnimWeb@@ABVidAnimWebPath@@PBVidDeclMD6@@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@_N@Z
// EA  : 0x82859BF0
// RVA : 0x00859BF0
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

const idMD6Anim *__fastcall idMD6Util::FindMD6Anim(
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *webRef,
        idAnimWebPath *webPath,
        const idDeclMD6 *declMD6,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const bool loadAnim)
{
  __int16 v7; // r27
  const idDeclAnimWeb *v9; // r3
  idDeclAnimWebNode *v10; // r9
  int v11; // r10
  unsigned int v12; // r11
  int v13; // r9
  const idMD6Anim *Anim; // r30
  __int16 v16; // [sp+50h] [-B0h] BYREF
  int v17; // [sp+54h] [-ACh]
  idStr v18; // [sp+60h] [-A0h] BYREF
  idStr v19; // [sp+80h] [-80h] BYREF
  idStr v20[3]; // [sp+A0h] [-60h] BYREF

  v20[0].len = 0;
  v20[0].allocedAndFlag = 20;
  v20[0].data = v20[0].baseBuffer;
  v20[0].baseBuffer[0] = 0;
  v7 = (__int16)modelIndex;
  v19.allocedAndFlag = 20;
  v19.data = v19.baseBuffer;
  v19.len = 0;
  v19.baseBuffer[0] = 0;
  v18.allocedAndFlag = 20;
  v18.data = v18.baseBuffer;
  v18.len = 0;
  v18.baseBuffer[0] = 0;
  idAnimWebPath::GetWebPathNames(this: webPath, webName: v20, subWebName: &v19, stateName: &v18);
  if ( webRef == nullptr )
  {
    v9 = v20[0].data != nullptr
       ? (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclAnimWeb::resourceList,
                                  name: v20[0].data,
                                  makeDefault: false)
       : nullptr;
    webRef = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v9;
    if ( v9 == nullptr )
      goto LABEL_23;
  }
  if ( declMD6 == nullptr )
  {
    if ( *(int *)&webRef[54].value <= 0 )
      declMD6 = nullptr;
    else
      declMD6 = **(const idDeclMD6 ***)&webRef[52].value;
  }
  idDeclAnimWeb::GetNodeIndexForName(
    this: (idDeclAnimWeb *)&v16,
    result: webRef,
    subWebName: v19.data,
    stateName: v18.data);
  if ( v16 >= 0
    && (v16 == -1 ? (v10 = nullptr) : (v10 = *(idDeclAnimWebNode **)(4 * v16 + *(_DWORD *)&webRef[28].value)),
        v7 >= 0
     && v7 < v10->modelInfo.num
     && (v11 = (int)&v10->modelInfo.list[v7]) != 0
     && (v17 = *(_DWORD *)(v11 + 16), v12 = v17, v17 > 0)
     && (v17 = *(_DWORD *)(v11 + 12), v13 = v17, v17 != 0)) )
  {
    v17 = v12;
    if ( loadAnim )
      Anim = idMD6AnimProps::SelectAndLoadAnim(
               this: (idMD6AnimProps *)(((__PAIR64__(v12 >> 31, 0) - v12) >> 32) & v13),
               declMD6,
               index: 0);
    else
      Anim = idMD6AnimProps::SelectAnim(
               this: (idMD6AnimProps *)(((__PAIR64__(v12 >> 31, 0) - v12) >> 32) & v13),
               declMD6,
               index: 0);
    idStr::FreeData(this: &v18);
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: v20);
    return Anim;
  }
  else
  {
LABEL_23:
    idStr::FreeData(this: &v18);
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: v20);
    return nullptr;
  }
}


// ========================================================================
// __unwind$221458
// EA  : 0x82859E34
// RVA : 0x00859E34
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void _unwind_221458()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$221459
// EA  : 0x82859E5C
// RVA : 0x00859E5C
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void _unwind_221459()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$221460_0
// EA  : 0x82859E84
// RVA : 0x00859E84
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void _unwind_221460_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?GetAnimDelta@idMD6Util@@SA_NPBVidMD6Anim@@PAVidVec3@@PAVidMat3@@@Z
// EA  : 0x82859EB0
// RVA : 0x00859EB0
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

int __fastcall idMD6Util::GetAnimDelta(const idMD6Anim *md6anim, idVec3 *deltaOrigin, idMat3 *deltaAxis)
{
  idMD6AnimData *animData; // r11
  idQuat *startDelta; // r29
  float *endDelta; // r31
  idQuat *v8; // r3
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double x; // fp10
  double y; // fp9
  double z; // fp4
  double v15; // fp5
  double v16; // fp2
  double v17; // fp3
  double v18; // fp8
  double v19; // fp6
  idVec3 *v20; // r3
  idQuat *v21; // r3
  idVec3 v23; // [sp+50h] [-90h] BYREF
  idQuat v24; // [sp+60h] [-80h] BYREF
  idMat3 v25[3]; // [sp+70h] [-70h] BYREF

  if ( md6anim == nullptr )
    return 0;
  animData = md6anim->animData;
  startDelta = nullptr;
  if ( animData != nullptr )
  {
    startDelta = (idQuat *)animData->startDelta;
    endDelta = animData->endDelta;
  }
  else
  {
    endDelta = nullptr;
  }
  if ( deltaAxis != nullptr )
  {
    v8 = idQuat::Inverse(this: &v24, result: startDelta);
    v9 = *endDelta;
    v10 = endDelta[1];
    v11 = endDelta[2];
    x = v8->x;
    y = v8->y;
    z = v8->z;
    v15 = (float)((float)(endDelta[2] * v8->w) + (float)((float)(endDelta[3] * v8->z) + (float)(endDelta[1] * v8->x)));
    v16 = (float)((float)(*endDelta * v8->w) + (float)((float)(endDelta[2] * v8->y) + (float)(endDelta[3] * v8->x)));
    v17 = (float)((float)(endDelta[1] * v8->w) + (float)((float)(*endDelta * v8->z) + (float)(endDelta[3] * v8->y)));
    v25[0].mat[1].x = -(float)((float)(endDelta[2] * v8->z)
                             - (float)-(float)((float)(endDelta[1] * v8->y)
                                             - (float)((float)(endDelta[3] * v8->w) - (float)(*endDelta * v8->x))));
    v25[0].mat[0].z = -(float)((float)((float)v9 * (float)y) - (float)v15);
    v25[0].mat[0].x = -(float)((float)((float)v10 * (float)z) - (float)v16);
    v25[0].mat[0].y = -(float)((float)((float)v11 * (float)x) - (float)v17);
    *deltaAxis = *idQuat::ToMat3(this: (idQuat *)&v25[0].mat[2].z, result: v25);
  }
  if ( deltaOrigin != nullptr )
  {
    v18 = (float)(endDelta[9] - startDelta[2].y);
    v19 = (float)(endDelta[10] - startDelta[2].z);
    v23.x = endDelta[8] - startDelta[2].x;
    v23.y = v18;
    v23.z = v19;
    v20 = (idVec3 *)idQuat::Inverse(this: (idQuat *)&v25[0].mat[1].y, result: startDelta);
    v21 = idQuat::operator*(this: &v24, result: v20, a: &v23);
    deltaOrigin->x = v21->x;
    deltaOrigin->y = v21->y;
    deltaOrigin->z = v21->z;
  }
  return 1;
}


// ========================================================================
// ?GetDelta@idJointCache@idMD6Util@@QAA_NAAUanimDelta_t@2@PBD1@Z
// EA  : 0x8285A050
// RVA : 0x0085A050
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

int __fastcall idMD6Util::idJointCache::GetDelta(
        idMD6Util::idJointCache *this,
        idMD6Util::animDelta_t *delta,
        const char *jointName,
        const char *refJointName)
{
  const idDeclAnimWeb *webRef; // r11
  idIndex<short,enum invalidJointIndex_t> *md6Decl; // r29
  float *mat; // r11
  double v10; // fp0
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  double v19; // fp5
  double v20; // fp4
  double v21; // fp3
  float *v22; // r11
  double v23; // fp9
  double v24; // fp7
  double v25; // fp5
  idAngles *v26; // r30
  idAngles *v27; // r3
  double v28; // fp5
  double v29; // fp3
  __int16 v31; // [sp+50h] [-F0h] BYREF
  __int16 v32; // [sp+52h] [-EEh] BYREF
  idMat3 v33; // [sp+58h] [-E8h] BYREF
  float v34; // [sp+7Ch] [-C4h]
  float v35; // [sp+80h] [-C0h]
  float v36; // [sp+84h] [-BCh]
  float v37; // [sp+88h] [-B8h]
  float v38; // [sp+8Ch] [-B4h]
  float v39; // [sp+90h] [-B0h]
  idAngles v40; // [sp+A0h] [-A0h] BYREF
  float v41; // [sp+ACh] [-94h]
  float v42; // [sp+B0h] [-90h]
  float v43; // [sp+B4h] [-8Ch]
  float v44; // [sp+B8h] [-88h]
  float v45; // [sp+BCh] [-84h]
  float v46; // [sp+C0h] [-80h]
  idMat3 v47; // [sp+C8h] [-78h] BYREF
  idAngles v48[6]; // [sp+F0h] [-50h] BYREF

  if ( !this->validJointCache )
    return 0;
  webRef = this->webRef;
  if ( webRef != nullptr )
  {
    if ( webRef->models.num <= 0 )
      return 0;
    md6Decl = (idIndex<short,enum invalidJointIndex_t> *)*webRef->models.list;
  }
  else
  {
    md6Decl = (idIndex<short,enum invalidJointIndex_t> *)this->md6Decl;
  }
  if ( md6Decl == nullptr )
    return 0;
  idDeclMD6::GetJointIndex(this: (idDeclMD6 *)&v31, result: md6Decl, jointName);
  idDeclMD6::GetJointIndex(this: (idDeclMD6 *)&v32, result: md6Decl, jointName: refJointName);
  if ( v31 < 0 || v32 < 0 )
    return 0;
  mat = this->jointMatrices[v31].mat;
  v10 = mat[3];
  v11 = mat[7];
  v12 = mat[11];
  v13 = *mat;
  v33.mat[2].x = *mat;
  v14 = mat[1];
  v34 = mat[1];
  v15 = mat[2];
  v37 = mat[2];
  v16 = mat[4];
  v33.mat[2].y = mat[4];
  v17 = mat[5];
  v35 = mat[5];
  v18 = mat[6];
  v38 = mat[6];
  v19 = mat[8];
  v33.mat[2].z = mat[8];
  v20 = mat[9];
  v36 = mat[9];
  v21 = mat[10];
  v39 = mat[10];
  if ( v31 == v32 )
  {
    delta->deltaTranslation.x = v10;
    delta->deltaTranslation.y = v11;
    delta->deltaTranslation.z = v12;
    delta->deltaAxis.mat[0].x = v13;
    delta->deltaAxis.mat[1].x = v14;
    delta->deltaAxis.mat[0].y = v16;
    delta->deltaAxis.mat[0].z = v19;
    delta->deltaAxis.mat[1].y = v17;
    delta->deltaAxis.mat[1].z = v20;
    delta->deltaAxis.mat[2].x = v15;
    delta->deltaAxis.mat[2].y = v18;
    delta->deltaAxis.mat[2].z = v21;
    return 1;
  }
  else
  {
    v22 = this->jointMatrices[v32].mat;
    v23 = (float)((float)v10 - v22[3]);
    v24 = (float)((float)v11 - v22[7]);
    v25 = (float)((float)v12 - v22[11]);
    v40.pitch = *v22;
    v41 = v22[1];
    v44 = v22[2];
    v40.yaw = v22[4];
    v42 = v22[5];
    v45 = v22[6];
    v40.roll = v22[8];
    v43 = v22[9];
    v46 = v22[10];
    delta->deltaTranslation.x = v23;
    delta->deltaTranslation.y = v24;
    delta->deltaTranslation.z = v25;
    v26 = idMat3::ToAngles(this: &v47, result: &v40);
    v27 = idMat3::ToAngles(this: (idMat3 *)&v47.mat[1].y, result: (idAngles *)&v33.mat[2]);
    v28 = (float)(v27->roll - v26->roll);
    v29 = (float)(v27->yaw - v26->yaw);
    v33.mat[0].x = v27->pitch - v26->pitch;
    v33.mat[0].z = v28;
    v33.mat[0].y = v29;
    delta->deltaAxis = *idAngles::ToMat3(this: v48, result: &v33);
    return 1;
  }
}


// ========================================================================
// ?UpdateCache@idJointCache@idMD6Util@@AAAXXZ
// EA  : 0x8285A2C8
// RVA : 0x0085A2C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void __fastcall idMD6Util::idJointCache::UpdateCache(idMD6Util::idJointCache *this)
{
  const idDeclAnimWeb *webRef; // r11
  const idDeclMD6 *md6Decl; // r10
  int frameNum; // r28
  int v5; // r10
  const idMD6AnimData *v6; // r4
  int v7; // r9
  int v8; // r27
  int v9; // r12
  int gameHz; // r8
  signed int frameRate; // r26
  int value; // r11
  const idMD6SkelData *v13; // r3
  void *v14; // r6
  __int64 v15; // r8
  _DWORD back_chain[2]; // [sp+0h] [-B0h]
  bool v17; // [sp+Bh] [-A5h]
  float *v18; // [sp+Ch] [-A4h]
  float *v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]
  int v27; // [sp+30h] [-80h]
  int v28; // [sp+34h] [-7Ch]
  int v29; // [sp+38h] [-78h]
  int v30; // [sp+3Ch] [-74h]
  int v31; // [sp+40h] [-70h]
  int v32; // [sp+44h] [-6Ch]
  int v33; // [sp+48h] [-68h]
  int v34; // [sp+4Ch] [-64h]
  int v35; // [sp+50h] [-60h]
  unsigned __int8 v36; // [sp+57h] [-59h]
  int v37; // [sp+58h] [-58h]
  idMD6Util::idJointCache *v38; // [sp+5Ch] [-54h]
  int v39; // [sp+60h] [-50h]
  void *v40; // [sp+64h] [-4Ch]
  float v41; // [sp+70h] [-40h] BYREF

  webRef = this->webRef;
  md6Decl = this->md6Decl;
  this->validJointCache = false;
  if ( webRef != nullptr )
  {
    if ( webRef->models.num <= 0 )
      return;
    md6Decl = *webRef->models.list;
  }
  if ( md6Decl != nullptr && md6Decl->model != nullptr && this->md6anim != nullptr )
  {
    ((void (*)(void))RtlCheckStack12)();
    frameNum = this->frameNum;
    v6 = *(const idMD6AnimData **)(v5 + 40);
    v8 = *(_DWORD *)(v7 + 212);
    *(_DWORD *)((char *)back_chain + v9) = back_chain[0];
    gameHz = timeManager.gameHz;
    frameRate = v6->frameRate;
    value = timeManager.gameTimePerFrame.value;
    v13 = *(const idMD6SkelData **)(v8 + 40);
    __twllei(frameRate, 0);
    v40 = v14;
    LODWORD(v15) = value * gameHz;
    v38 = this;
    v36 = 1;
    HIDWORD(v15) = frameNum * (int)v15 / frameRate;
    __twlgei(frameRate & ~(__ROL4__(frameNum * v15, 1) - 1), 0xFFFFFFFF);
    idMD6Blend::DecodeSingleFrame(
      skeleton: v13,
      temp: &v41,
      tempSize: 0x4000u,
      animData: v6,
      ticksPerSec: v15,
      clearOriginTransform: false,
      originOffset: &vec3_origin.x,
      offsetAdd: v17,
      outPose: v18,
      outUserChannels: v19,
      a11: v20,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: v37,
      a29: (int)v38,
      a30: v39,
      a31: v40);
    this->validJointCache = true;
  }
}


// ========================================================================
// ?Set@idJointCache@idMD6Util@@QAAXPBVidDeclAnimWeb@@ABVidAnimWebPath@@H@Z
// EA  : 0x8285A3C0
// RVA : 0x0085A3C0
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void __fastcall idMD6Util::idJointCache::Set(
        idMD6Util::idJointCache *this,
        const idDeclAnimWeb *webRef,
        idAnimWebPath *webPath,
        int frameNum)
{
  const idDeclMD6 *v6; // r11
  const idMD6Anim *MD6Anim; // r3
  int numFrames; // r11

  this->webRef = webRef;
  this->validJointCache = false;
  if ( webRef != nullptr )
    v6 = *webRef->models.list;
  else
    v6 = nullptr;
  this->md6Decl = v6;
  MD6Anim = idMD6Util::FindMD6Anim(
              (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)webRef,
              webPath,
              declMD6: nullptr,
              modelIndex: nullptr,
              loadAnim: false);
  this->md6anim = MD6Anim;
  if ( MD6Anim != nullptr )
  {
    if ( frameNum == -1 )
    {
      numFrames = MD6Anim->animData->numFrames;
      this->validJointCache = false;
      this->frameNum = numFrames - 1;
    }
    else
    {
      this->frameNum = frameNum;
      this->validJointCache = false;
    }
    idMD6Util::idJointCache::UpdateCache(this);
  }
}


// ========================================================================
// ??0idJointCache@idMD6Util@@QAA@PBVidDeclMD6@@PBVidMD6Anim@@H@Z
// EA  : 0x8285A468
// RVA : 0x0085A468
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

idMD6Util::idJointCache *__fastcall idMD6Util::idJointCache::idJointCache(
        idMD6Util::idJointCache *this,
        const idDeclMD6 *decl,
        const idMD6Anim *anim,
        int frameNum)
{
  this->md6Decl = decl;
  this->md6anim = anim;
  this->webRef = nullptr;
  this->validJointCache = false;
  if ( anim != nullptr )
  {
    if ( frameNum == -1 )
      this->frameNum = anim->animData->numFrames - 1;
    else
      this->frameNum = frameNum;
    this->validJointCache = false;
    idMD6Util::idJointCache::UpdateCache(this);
  }
  return this;
}


// ========================================================================
// ??0idJointCache@idMD6Util@@QAA@ABVidAnimWebPath@@H@Z
// EA  : 0x8285A4E8
// RVA : 0x0085A4E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

idMD6Util::idJointCache *__fastcall idMD6Util::idJointCache::idJointCache(
        idMD6Util::idJointCache *this,
        idAnimWebPath *webPath,
        int frameNum)
{
  const idDeclAnimWeb *v6; // r4
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  this->md6Decl = nullptr;
  this->webRef = nullptr;
  v8[0].allocedAndFlag = 20;
  v8[0].data = v8[0].baseBuffer;
  this->md6anim = nullptr;
  v8[0].len = 0;
  v8[0].baseBuffer[0] = 0;
  idAnimWebPath::GetWebName(this: webPath, webName: v8);
  if ( v8[0].data != nullptr )
    v6 = (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclAnimWeb::resourceList,
                                  name: v8[0].data,
                                  makeDefault: false);
  else
    v6 = nullptr;
  this->webRef = v6;
  idMD6Util::idJointCache::Set(this, webRef: v6, webPath, frameNum);
  idStr::FreeData(this: v8);
  return this;
}


// ========================================================================
// __unwind$226457_0
// EA  : 0x8285A588
// RVA : 0x0085A588
// PDB : w:\tech5\engine\models\skeletalanimation\md6util.cpp
// ========================================================================

void _unwind_226457_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}

