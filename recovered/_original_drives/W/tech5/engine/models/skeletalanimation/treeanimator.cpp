
// ========================================================================
// ?GetLastOriginRotation@idTreeAnimator@@QBAABVidQuat@@XZ
// EA  : 0x8285C6A8
// RVA : 0x0085C6A8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idQuat *__fastcall idTreeAnimator::GetLastOriginRotation(idTreeAnimator *this)
{
  return (const idQuat *)this->originDelta[1]->animRotation;
}


// ========================================================================
// ?GetLastOriginTranslation@idTreeAnimator@@QBAABVidVec3@@XZ
// EA  : 0x8285C6B8
// RVA : 0x0085C6B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idVec3 *__fastcall idTreeAnimator::GetLastOriginTranslation(idTreeAnimator *this)
{
  return (const idVec3 *)this->originDelta[1]->animTranslation;
}


// ========================================================================
// ?IsDeltaFudged@idTreeAnimator@@QBA_NXZ
// EA  : 0x8285C6C8
// RVA : 0x0085C6C8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

BOOL __fastcall idTreeAnimator::IsDeltaFudged(idTreeAnimator *this)
{
  return this->originDelta[1]->fudged;
}


// ========================================================================
// ?GetLastOriginDeltaTime@idTreeAnimator@@QBAHXZ
// EA  : 0x8285C6E0
// RVA : 0x0085C6E0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetLastOriginDeltaTime(idTreeAnimator *this)
{
  return this->originDelta[1]->time;
}


// ========================================================================
// ?SetRemoveOriginRotation@idTreeAnimator@@QAAX_N@Z
// EA  : 0x8285C6F0
// RVA : 0x0085C6F0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetRemoveOriginRotation(idTreeAnimator *this, const bool removeRotation)
{
  *((_BYTE *)this + 2164) = (removeRotation << 6) & 0x40 | *((_BYTE *)this + 2164) & 0xBF;
}


// ========================================================================
// ?GetRemoveOriginTranslation@idTreeAnimator@@QBA_NXZ
// EA  : 0x8285C708
// RVA : 0x0085C708
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

BOOL __fastcall idTreeAnimator::GetRemoveOriginTranslation(_BYTE *ptr)
{
  return (ptr[2164] & 0x40) != 0;
}


// ========================================================================
// ?SetOriginDeltaLookAhead@idTreeAnimator@@QAAX_N@Z
// EA  : 0x8285C718
// RVA : 0x0085C718
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetOriginDeltaLookAhead(idTreeAnimator *this, const bool lookAhead)
{
  *((_BYTE *)this + 2164) = (32 * lookAhead) & 0x20 | *((_BYTE *)this + 2164) & 0xDF;
}


// ========================================================================
// ?GetJointList@idTreeAnimator@@QBAXPBDAAV?$idList@V?$idIndex@FW4invalidJointIndex_t@@@@$04@@@Z
// EA  : 0x8285C730
// RVA : 0x0085C730
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::GetJointList(
        idTreeAnimator *this,
        const char *jointNames,
        idList<idIndex<short,enum invalidJointIndex_t>,5> *jointList)
{
  idDeclMD6 *decl; // r3

  decl = this->decl;
  if ( decl != nullptr )
    idDeclMD6::GetJointList(this: decl, joints: jointNames, jointList);
}


// ========================================================================
// ?Save@idTreeAnimator@@EBAXPAVidFile@@@Z
// EA  : 0x8285C748
// RVA : 0x0085C748
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::Save(idTreeAnimator *this, idFile *fp)
{
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v5; // r7
  idFile_vtbl *v6; // r9
  idFile_vtbl *v7; // r11
  idFile_vtbl *v8; // r7
  idFile_vtbl *v9; // r7
  _BYTE v10[4]; // [sp+50h] [-30h] BYREF
  int v11; // [sp+54h] [-2Ch] BYREF
  int v12[4]; // [sp+58h] [-28h] BYREF

  idRenderModel::Save(this, fp);
  Write = fp->Write;
  v11 = 48 * ((this->decl->model->skeleton->data->numJoints + 7) & 0xFFF8);
  Write(this: fp, a2: &this->lastBlendTime, a3: 4u);
  v5 = fp->__vftable;
  v10[0] = *((_BYTE *)this + 2164) >> 7;
  v5->Write(this: fp, a2: v10, a3: 1u);
  v6 = fp->__vftable;
  v10[0] = (*((_BYTE *)this + 2164) & 0x40) != 0;
  v6->Write(this: fp, a2: v10, a3: 1u);
  v7 = fp->__vftable;
  v10[0] = (*((_BYTE *)this + 2164) & 0x20) != 0;
  v7->Write(this: fp, a2: v10, a3: 1u);
  v8 = fp->__vftable;
  v10[0] = (*((_BYTE *)this + 2164) & 0x10) != 0;
  v8->Write(this: fp, a2: v10, a3: 1u);
  fp->Write(this: fp, a2: &this->deferredJobJointBuffer, a3: 4u);
  v9 = fp->__vftable;
  v12[0] = this->meshVisibility.num;
  v9->Write(this: fp, a2: v12, a3: 4u);
  fp->Write(this: fp, a2: this->meshVisibility.list, a3: this->meshVisibility.num);
  fp->Write(this: fp, a2: &v11, a3: 4u);
  fp->Write(this: fp, a2: this->joints[0], a3: v11 & 0xFFFFFFFC);
  fp->Write(this: fp, a2: this->joints[1], a3: v11 & 0xFFFFFFFC);
  fp->Write(this: fp, a2: &this->morphSkin, a3: 2u);
  fp->Write(this: fp, a2: &this->initialMorphValue, a3: 4u);
  fp->Write(this: fp, a2: &this->frameBounds, a3: 24u);
  fp->Write(this: fp, a2: &this->normalizedBounds, a3: 24u);
  fp->Write(this: fp, a2: &this->translatedBounds, a3: 24u);
  fp->Write(this: fp, a2: &this->skipJointForBounds, a3: 2u);
}


// ========================================================================
// ?GetSourceSurfaces@idTreeAnimator@@EBAPBV?$idList@UsourceSurface_t@@$04@@XZ
// EA  : 0x8285C9C8
// RVA : 0x0085C9C8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idList<sourceSurface_t,5> *__fastcall idTreeAnimator::GetSourceSurfaces(idTreeAnimator *this)
{
  return &this->decl->model->sourceSurfaces;
}


// ========================================================================
// ?ShowSkel@idTreeAnimator@@QBAXXZ
// EA  : 0x8285C9D8
// RVA : 0x0085C9D8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::ShowSkel(idTreeAnimator *this)
{
  idMat3 *p_axis; // r31
  double valueFloat; // fp30
  const idMD6Skel *skeleton; // r28
  double v5; // fp29
  BOOL v6; // r18
  idRenderWorldLocal *World; // r30
  double v8; // fp31
  int v9; // r11
  idJointMat *v10; // r11
  double z; // fp3
  double v12; // fp6
  double v13; // fp4
  double v14; // fp1
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp9
  double v21; // fp8
  idMD6SkelData *data; // r11
  int jointHandleTblOffset; // r9
  __int16 v24; // r8
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v25; // r22
  int v26; // r20
  int v27; // r27
  const char *v28; // r3
  const char *v29; // r28
  idJointMat *v30; // r11
  double v31; // fp3
  double v32; // fp6
  double v33; // fp4
  double v34; // fp1
  double v35; // fp0
  double v36; // fp13
  double v37; // fp8
  double v38; // fp11
  double v39; // fp10
  double v40; // fp9
  unsigned int v41; // r14
  char *v42; // r9
  unsigned int v43; // r26
  char *v44; // r11
  char *v45; // r23
  unsigned int v46; // r27
  const idHandle<unsigned short,enum invalidJointHandle_t,65535> *v47; // r25
  double x; // fp0
  double y; // fp13
  double v50; // fp12
  double v51; // fp11
  int v52; // r28
  double v53; // fp10
  double v54; // fp9
  double v55; // fp8
  double v56; // fp7
  double v57; // fp6
  int v58; // r10
  double v59; // fp5
  double v60; // fp4
  double v61; // fp3
  double v62; // fp2
  double v63; // fp1
  float *v64; // r11
  double v65; // fp2
  double v66; // fp12
  double v67; // fp11
  float *v68; // r11
  double v69; // fp13
  double v70; // fp12
  double v71; // fp11
  double v72; // fp10
  double v73; // fp9
  double v74; // fp8
  double v75; // fp7
  double v76; // fp6
  __int64 v77; // r10
  __int64 v78; // r6
  __int64 v79; // r8
  va *v80; // r3
  const char *v81; // r3
  __int64 v82; // r10
  __int64 v83; // r8
  va *v84; // r3
  int v85; // [sp+8h] [-1298h]
  int v86; // [sp+Ch] [-1294h]
  int v87; // [sp+10h] [-1290h]
  int v88; // [sp+14h] [-128Ch]
  int v89; // [sp+18h] [-1288h]
  int v90; // [sp+1Ch] [-1284h]
  float v91; // [sp+60h] [-1240h] BYREF
  float v92; // [sp+64h] [-123Ch]
  float v93; // [sp+68h] [-1238h]
  float v94; // [sp+70h] [-1230h] BYREF
  float v95; // [sp+74h] [-122Ch]
  float v96; // [sp+78h] [-1228h]
  float v97; // [sp+80h] [-1220h] BYREF
  float v98; // [sp+84h] [-121Ch]
  float v99; // [sp+88h] [-1218h]
  idMat3 v100; // [sp+90h] [-1210h] BYREF
  BOOL v101; // [sp+B4h] [-11ECh] BYREF
  idMD6Skel v102; // [sp+B8h] [-11E8h] BYREF
  float v103[4]; // [sp+F0h] [-11B0h] BYREF
  float v104[4]; // [sp+100h] [-11A0h] BYREF
  float v105[4]; // [sp+110h] [-1190h] BYREF
  float v106[4]; // [sp+120h] [-1180h] BYREF
  float v107[4]; // [sp+130h] [-1170h] BYREF
  float v108[4]; // [sp+140h] [-1160h] BYREF
  float v109[4]; // [sp+150h] [-1150h] BYREF
  float v110[4]; // [sp+160h] [-1140h] BYREF
  float v111[4]; // [sp+170h] [-1130h] BYREF
  float v112[4]; // [sp+180h] [-1120h] BYREF
  float v113[4]; // [sp+190h] [-1110h] BYREF
  idMat3 v114; // [sp+1A0h] [-1100h] BYREF
  va v115; // [sp+1D0h] [-10D0h] BYREF

  v102.trackedMemory = (int)&r_showSkel;
  if ( r_showSkel.valueInteger != 0 && r_showSkel.valueInteger != 3 )
  {
    p_axis = &this->g.axis;
    valueFloat = r_jointNameScale.valueFloat;
    skeleton = this->decl->model->skeleton;
    v5 = r_jointNameOffset.valueFloat;
    v6 = r_showRefPose.valueInteger == 0;
    v101 = v6;
    World = idRenderModel::GetWorld(this);
    v8 = r_jointAxisScale.valueFloat;
    if ( *r_jointName.valueString.data != 0 )
    {
      ((void (__fastcall *)(BOOL *))animation->RegisterJoint)(a1: &v101);
      v9 = SHIWORD(idMD6Skel::GetJointIndex(
                     this: &v102,
                     result: (idIndex<short,enum invalidJointIndex_t> *)skeleton,
                     handle: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)&v101)->__vftable);
      if ( v9 >= 0 )
      {
        v10 = &this->joints[v6][v9];
        z = this->g.origin.z;
        v12 = (float)((float)(p_axis->mat[1].z * v10->mat[7])
                    + (float)((float)(p_axis->mat[0].z * v10->mat[3]) + (float)(p_axis->mat[2].z * v10->mat[11])));
        v13 = (float)(this->g.origin.y
                    + (float)((float)(p_axis->mat[1].y * v10->mat[7])
                            + (float)((float)(p_axis->mat[0].y * v10->mat[3]) + (float)(p_axis->mat[2].y * v10->mat[11]))));
        v97 = this->g.origin.x
            + (float)((float)(p_axis->mat[0].x * v10->mat[3])
                    + (float)((float)(p_axis->mat[2].x * v10->mat[11]) + (float)(p_axis->mat[1].x * v10->mat[7])));
        v98 = v13;
        v99 = (float)z + (float)v12;
        v14 = v10->mat[9];
        v15 = v10->mat[5];
        v16 = v10->mat[1];
        v17 = v10->mat[8];
        v18 = v10->mat[4];
        v19 = v10->mat[0];
        v20 = v10->mat[10];
        v21 = v10->mat[6];
        v100.mat[2].x = v10->mat[2];
        v100.mat[2].y = v21;
        v100.mat[2].z = v20;
        v100.mat[1].z = v14;
        v100.mat[1].y = v15;
        v100.mat[1].x = v16;
        v100.mat[0].z = v17;
        v100.mat[0].y = v18;
        v100.mat[0].x = v19;
        idMat3::operator*=(this: &v100, a: p_axis);
        v110[0] = (float)(v100.mat[0].x * (float)v8) + v97;
        v110[1] = (float)(v100.mat[0].y * (float)v8) + v98;
        v110[2] = (float)(v100.mat[0].z * (float)v8) + v99;
        World->DebugLine(
          this: World,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: (const idVec3 *)&v97,
          a4: (const idVec3 *)v110,
          a5: 0,
          a6: false);
        v111[0] = (float)(v100.mat[1].x * (float)v8) + v97;
        v111[1] = (float)(v100.mat[1].y * (float)v8) + v98;
        v111[2] = (float)(v100.mat[1].z * (float)v8) + v99;
        World->DebugLine(
          this: World,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: (const idVec3 *)&v97,
          a4: (const idVec3 *)v111,
          a5: 0,
          a6: false);
        *(float *)&v102.data = (float)(v100.mat[2].x * (float)v8) + v97;
        *(float *)&v102.timestamp = (float)(v100.mat[2].y * (float)v8) + v98;
        *(float *)&v102.jointConversion.value = (float)(v100.mat[2].z * (float)v8) + v99;
        World->DebugLine(
          this: World,
          a2: (const idVec4 *)&idColor::colorBlue,
          a3: (const idVec3 *)&v97,
          a4: (const idVec3 *)&v102.data,
          a5: 0,
          a6: false);
        v112[0] = v97;
        v112[1] = v98;
        v112[2] = v99 + (float)v5;
        ((void (__fastcall *)(idRenderWorldLocal *, char *, float *, idRenderWorldLocal_vtbl *, idColor *, int, _DWORD, _DWORD, double))World->DebugText)(
          a1: World,
          a2: r_jointName.valueString.data,
          a3: v112,
          a4: World->__vftable,
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: valueFloat);
      }
    }
    else
    {
      data = skeleton->data;
      jointHandleTblOffset = data->jointHandleTblOffset;
      v24 = data->numJoints + 7;
      if ( *r_jointSubString.valueString.data != 0 )
      {
        if ( ((data->numJoints + 7) & 0xFFF8) != 0 )
        {
          v25 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((char *)data + jointHandleTblOffset);
          v26 = v24 & 0xFFF8;
          v27 = 0;
          do
          {
            if ( v25->value != 0xFFFF )
            {
              v28 = animation->GetJointName(this: animation, a2: v25);
              v29 = v28;
              if ( v28 != nullptr
                && idStr::Find(
                     searchIn: v28,
                     searchFor: r_jointSubString.valueString.data,
                     casesensitive: false,
                     start: 0,
                     end: -1) != -1 )
              {
                v30 = &this->joints[v6][v27];
                v31 = this->g.origin.z;
                v32 = (float)((float)(p_axis->mat[1].z * v30->mat[7])
                            + (float)((float)(p_axis->mat[0].z * v30->mat[3]) + (float)(p_axis->mat[2].z * v30->mat[11])));
                v33 = (float)(this->g.origin.y
                            + (float)((float)(p_axis->mat[1].y * v30->mat[7])
                                    + (float)((float)(p_axis->mat[0].y * v30->mat[3])
                                            + (float)(p_axis->mat[2].y * v30->mat[11]))));
                v94 = this->g.origin.x
                    + (float)((float)(p_axis->mat[0].x * v30->mat[3])
                            + (float)((float)(p_axis->mat[2].x * v30->mat[11]) + (float)(p_axis->mat[1].x * v30->mat[7])));
                v95 = v33;
                v96 = (float)v31 + (float)v32;
                v34 = v30->mat[10];
                v35 = v30->mat[5];
                v36 = v30->mat[4];
                v37 = v30->mat[0];
                v100.mat[2].x = v30->mat[2];
                v38 = v30->mat[1];
                v39 = v30->mat[9];
                v40 = v30->mat[8];
                v100.mat[2].y = v30->mat[6];
                v100.mat[2].z = v34;
                v100.mat[1].z = v39;
                v100.mat[1].y = v35;
                v100.mat[1].x = v38;
                v100.mat[0].z = v40;
                v100.mat[0].x = v37;
                v100.mat[0].y = v36;
                idMat3::operator*=(this: &v100, a: p_axis);
                v104[0] = (float)(v100.mat[0].x * (float)v8) + v94;
                v104[1] = (float)(v100.mat[0].y * (float)v8) + v95;
                v104[2] = (float)(v100.mat[0].z * (float)v8) + v96;
                World->DebugLine(
                  this: World,
                  a2: (const idVec4 *)&idColor::colorGreen,
                  a3: (const idVec3 *)&v94,
                  a4: (const idVec3 *)v104,
                  a5: 0,
                  a6: false);
                *(float *)&v102.name.str = (float)(v100.mat[1].x * (float)v8) + v94;
                *(float *)&v102.nextOnHashChain = (float)(v100.mat[1].y * (float)v8) + v95;
                *(float *)&v102.resourceListPtr = (float)(v100.mat[1].z * (float)v8) + v96;
                World->DebugLine(
                  this: World,
                  a2: (const idVec4 *)&idColor::colorRed,
                  a3: (const idVec3 *)&v94,
                  a4: (const idVec3 *)&v102.name,
                  a5: 0,
                  a6: false);
                v106[1] = (float)(v100.mat[2].y * (float)v8) + v95;
                v106[0] = (float)(v100.mat[2].x * (float)v8) + v94;
                v106[2] = (float)(v100.mat[2].z * (float)v8) + v96;
                World->DebugLine(
                  this: World,
                  a2: (const idVec4 *)&idColor::colorBlue,
                  a3: (const idVec3 *)&v94,
                  a4: (const idVec3 *)v106,
                  a5: 0,
                  a6: false);
                v113[0] = v94;
                v113[1] = v95;
                v113[2] = v96 + (float)v5;
                ((void (__fastcall *)(idRenderWorldLocal *, const char *, float *, idRenderWorldLocal_vtbl *, idColor *, int, _DWORD, _DWORD, double))World->DebugText)(
                  a1: World,
                  a2: v29,
                  a3: v113,
                  a4: World->__vftable,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: valueFloat);
              }
            }
            --v26;
            ++v25;
            ++v27;
          }
          while ( v26 != 0 );
        }
      }
      else
      {
        v41 = v24 & 0xFFF8;
        v42 = (char *)data + jointHandleTblOffset;
        v43 = 0;
        v44 = (char *)data + data->parentTblOffset;
        if ( (v24 & 0xFFF8) != 0 )
        {
          v45 = v44;
          v102.__vftable = (idMD6Skel_vtbl *)(v42 - v44);
          v46 = 0;
          do
          {
            v47 = (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)((char *)v102.__vftable
                                                                                   + (unsigned int)v45);
            if ( *(unsigned __int16 *)((char *)&v102.dtr_idResource + (unsigned int)v45) != 0xFFFF )
            {
              x = p_axis->mat[2].x;
              y = p_axis->mat[2].y;
              v50 = p_axis->mat[2].z;
              v51 = p_axis->mat[1].x;
              v52 = 4 * (v101 + 526);
              v53 = p_axis->mat[1].y;
              v54 = p_axis->mat[1].z;
              v55 = p_axis->mat[0].x;
              v56 = p_axis->mat[0].y;
              v57 = p_axis->mat[0].z;
              v58 = *(int *)((char *)&this->__vftable + v52);
              v59 = this->g.origin.x;
              v60 = this->g.origin.y;
              v61 = this->g.origin.z;
              v62 = (float)((float)(*(float *)(v58 + v46 + 12) * p_axis->mat[0].z)
                          + (float)((float)(*(float *)(v58 + v46 + 28) * p_axis->mat[1].z)
                                  + (float)(*(float *)(v58 + v46 + 44) * p_axis->mat[2].z)));
              v63 = (float)((float)((float)(*(float *)(v58 + v46 + 12) * p_axis->mat[0].y)
                                  + (float)((float)(*(float *)(v58 + v46 + 28) * p_axis->mat[1].y)
                                          + (float)(*(float *)(v58 + v46 + 44) * p_axis->mat[2].y)))
                          + this->g.origin.y);
              v91 = (float)((float)(*(float *)(v58 + v46 + 12) * p_axis->mat[0].x)
                          + (float)((float)(*(float *)(v58 + v46 + 28) * p_axis->mat[1].x)
                                  + (float)(*(float *)(v58 + v46 + 44) * p_axis->mat[2].x)))
                  + this->g.origin.x;
              v92 = v63;
              v93 = (float)v62 + (float)v61;
              if ( *(__int16 *)v45 >= 0 )
              {
                v64 = (float *)(48 * *(__int16 *)v45 + v58);
                v65 = (float)((float)(v64[7] * (float)v51) + (float)(v64[11] * (float)x));
                v66 = (float)((float)(v64[3] * (float)v57)
                            + (float)((float)(v64[7] * (float)v54) + (float)(v64[11] * (float)v50)));
                v67 = (float)((float)((float)(v64[3] * (float)v56)
                                    + (float)((float)(v64[7] * (float)v53) + (float)(v64[11] * (float)y)))
                            + (float)v60);
                v108[0] = (float)((float)(v64[3] * (float)v55) + (float)v65) + (float)v59;
                v108[1] = v67;
                v108[2] = (float)v66 + (float)v61;
                World->DebugLine(
                  this: World,
                  a2: (const idVec4 *)&idColor::colorLtGrey,
                  a3: (const idVec3 *)v108,
                  a4: (const idVec3 *)&v91,
                  a5: 0,
                  a6: false);
              }
              v68 = (float *)&(*(idTreeAnimator_vtbl **)((char *)&this->__vftable + v52))[v46 / 0x30];
              v69 = v68[6];
              v70 = v68[2];
              v71 = v68[9];
              v72 = v68[5];
              v73 = v68[1];
              v74 = v68[8];
              v75 = v68[4];
              v76 = *v68;
              v100.mat[2].z = v68[10];
              v100.mat[2].y = v69;
              v100.mat[2].x = v70;
              v100.mat[1].z = v71;
              v100.mat[1].y = v72;
              v100.mat[1].x = v73;
              v100.mat[0].z = v74;
              v100.mat[0].x = v76;
              v100.mat[0].y = v75;
              idMat3::operator*(this: &v114, result: &v100, a: p_axis);
              *((float *)&v102.idResource + 8) = (float)(v114.mat[0].z * (float)v8) + v93;
              *(float *)&v102.staleCount = (float)(v114.mat[0].y * (float)v8) + v92;
              *(float *)&v102.networkID = (float)(v114.mat[0].x * (float)v8) + v91;
              World->DebugLine(
                this: World,
                a2: (const idVec4 *)&idColor::colorGreen,
                a3: (const idVec3 *)&v91,
                a4: (const idVec3 *)&v102.networkID,
                a5: 0,
                a6: false);
              v103[1] = (float)(v114.mat[1].y * (float)v8) + v92;
              v103[0] = (float)(v114.mat[1].x * (float)v8) + v91;
              v103[2] = (float)(v114.mat[1].z * (float)v8) + v93;
              World->DebugLine(
                this: World,
                a2: (const idVec4 *)&idColor::colorRed,
                a3: (const idVec3 *)&v91,
                a4: (const idVec3 *)v103,
                a5: 0,
                a6: false);
              v105[0] = (float)(v114.mat[2].x * (float)v8) + v91;
              v105[1] = (float)(v114.mat[2].y * (float)v8) + v92;
              v105[2] = (float)(v114.mat[2].z * (float)v8) + v93;
              World->DebugLine(
                this: World,
                a2: (const idVec4 *)&idColor::colorBlue,
                a3: (const idVec3 *)&v91,
                a4: (const idVec3 *)v105,
                a5: 0,
                a6: false);
              LODWORD(v79) = v102.trackedMemory;
              if ( *(int *)(v102.trackedMemory + 32) <= 2 )
              {
                v81 = animation->GetJointName(this: animation, a2: v47);
                v109[0] = v91;
                v109[1] = v92;
                v109[2] = v93 + (float)v5;
                v84 = va::va(
                        this: &v115,
                        fmt: "%s:%d",
                        a3: __SPAIR64__((unsigned int)v81, v43),
                        a4: v83,
                        a5: v82,
                        a6: v85,
                        a7: v86,
                        a8: v87,
                        a9: v88,
                        a10: v89,
                        a11: v90);
                ((void (__fastcall *)(idRenderWorldLocal *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))World->DebugText)(
                  a1: World,
                  a2: v84,
                  a3: v109,
                  a4: World->DebugText,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: valueFloat);
              }
              else
              {
                HIDWORD(v78) = v43;
                v107[0] = v91;
                v107[1] = v92;
                v107[2] = v93 + (float)v5;
                v80 = va::va(
                        this: &v115,
                        fmt: "%d",
                        a3: v78,
                        a4: v79,
                        a5: v77,
                        a6: v85,
                        a7: v86,
                        a8: v87,
                        a9: v88,
                        a10: v89,
                        a11: v90);
                ((void (__fastcall *)(idRenderWorldLocal *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))World->DebugText)(
                  a1: World,
                  a2: v80,
                  a3: v107,
                  a4: World->DebugText,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: valueFloat);
              }
            }
            ++v43;
            v45 += 2;
            v46 += 48;
          }
          while ( v43 < v41 );
        }
      }
    }
  }
}


// ========================================================================
// ?CalcFrameBoundsFromJoints@idTreeAnimator@@AAAXXZ
// EA  : 0x8285D4B8
// RVA : 0x0085D4B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::CalcFrameBoundsFromJoints(idTreeAnimator *this)
{
  idBounds *p_frameBounds; // r11
  idVec3 *v2; // r9
  unsigned int v3; // r8
  const idMD6Model *model; // r6
  const idMD6Skel *skeleton; // r5
  idMD6SkelData *data; // r4
  unsigned int numJoints; // r6
  idJointMat *v8; // r4
  __int16 v9; // r7
  float *v10; // r10
  unsigned int v59; // ctr
  float *v60; // r10
  double y; // fp13
  double z; // fp12
  const idMD6Model *v75; // r7
  double v76; // fp5
  double v77; // fp4
  double v78; // fp13
  double v79; // fp12
  idMD6Blend::configInfo_t *config; // r8
  double v81; // fp1
  double v82; // fp5

  p_frameBounds = &this->frameBounds;
  v2 = &this->frameBounds.b[1];
  if ( this->frameBounds.b[0].x >= (double)this->frameBounds.b[1].x
    || this->frameBounds.b[0].y >= (double)this->frameBounds.b[1].y
    || this->frameBounds.b[0].z >= (double)this->frameBounds.b[1].z
    || (float)((float)((float)(this->frameBounds.b[1].z - this->frameBounds.b[0].z)
                     * (float)(this->frameBounds.b[1].y - this->frameBounds.b[0].y))
             * (float)(this->frameBounds.b[1].x - this->frameBounds.b[0].x)) <= 0.0 )
  {
    v3 = 0;
    model = this->decl->model;
    this->frameBounds.b[0].z = 1.0e30;
    this->frameBounds.b[0].y = 1.0e30;
    skeleton = model->skeleton;
    p_frameBounds->b[0].x = 1.0e30;
    data = skeleton->data;
    this->frameBounds.b[1].z = -1.0e30;
    this->frameBounds.b[1].y = -1.0e30;
    v2->x = -1.0e30;
    numJoints = data->numJoints;
    v8 = this->joints[1];
    if ( numJoints >= 4 )
    {
      v9 = 2;
      v10 = &v8[1].mat[7];
      do
      {
        if ( this->skipJointForBounds.value != (__int16)v3 )
        {
          _FP9 = (float)(p_frameBounds->b[0].x - *(v10 - 16));
          _FP5 = (float)(this->frameBounds.b[0].z - *(v10 - 8));
          _FP3 = (float)(*(v10 - 16) - v2->x);
          _FP7 = (float)(this->frameBounds.b[0].y - *(v10 - 12));
          _FP1 = (float)(*(v10 - 12) - this->frameBounds.b[1].y);
          _FP31 = (float)(*(v10 - 8) - this->frameBounds.b[1].z);
          __asm { fsel      f11, f9, f0, f11 }
          p_frameBounds->b[0].x = _FP11;
          __asm { fsel      f9, f5, f12, f8 }
          this->frameBounds.b[0].z = _FP9;
          __asm { fsel      f8, f3, f0, f6 }
          v2->x = _FP8;
          __asm { fsel      f10, f7, f13, f10 }
          this->frameBounds.b[0].y = _FP10;
          __asm { fsel      f7, f1, f13, f4 }
          this->frameBounds.b[1].y = _FP7;
          __asm { fsel      f6, f31, f12, f2 }
          this->frameBounds.b[1].z = _FP6;
        }
        if ( this->skipJointForBounds.value != (__int16)(v9 - 1) )
        {
          _FP9 = (float)(p_frameBounds->b[0].x - *(v10 - 4));
          _FP5 = (float)(this->frameBounds.b[0].z - v10[4]);
          _FP3 = (float)(*(v10 - 4) - v2->x);
          _FP7 = (float)(this->frameBounds.b[0].y - *v10);
          _FP1 = (float)(*v10 - this->frameBounds.b[1].y);
          _FP31 = (float)(v10[4] - this->frameBounds.b[1].z);
          __asm { fsel      f11, f9, f0, f11 }
          p_frameBounds->b[0].x = _FP11;
          __asm { fsel      f9, f5, f12, f8 }
          this->frameBounds.b[0].z = _FP9;
          __asm { fsel      f8, f3, f0, f6 }
          v2->x = _FP8;
          __asm { fsel      f10, f7, f13, f10 }
          this->frameBounds.b[0].y = _FP10;
          __asm { fsel      f7, f1, f13, f4 }
          this->frameBounds.b[1].y = _FP7;
          __asm { fsel      f6, f31, f12, f2 }
          this->frameBounds.b[1].z = _FP6;
        }
        if ( this->skipJointForBounds.value != v9 )
        {
          _FP9 = (float)(p_frameBounds->b[0].x - v10[8]);
          _FP5 = (float)(this->frameBounds.b[0].z - v10[16]);
          _FP3 = (float)(v10[8] - v2->x);
          _FP7 = (float)(this->frameBounds.b[0].y - v10[12]);
          _FP1 = (float)(v10[12] - this->frameBounds.b[1].y);
          _FP31 = (float)(v10[16] - this->frameBounds.b[1].z);
          __asm { fsel      f11, f9, f0, f11 }
          p_frameBounds->b[0].x = _FP11;
          __asm { fsel      f9, f5, f12, f8 }
          this->frameBounds.b[0].z = _FP9;
          __asm { fsel      f8, f3, f0, f6 }
          v2->x = _FP8;
          __asm { fsel      f10, f7, f13, f10 }
          this->frameBounds.b[0].y = _FP10;
          __asm { fsel      f7, f1, f13, f4 }
          this->frameBounds.b[1].y = _FP7;
          __asm { fsel      f6, f31, f12, f2 }
          this->frameBounds.b[1].z = _FP6;
        }
        if ( this->skipJointForBounds.value != (__int16)(v9 + 1) )
        {
          _FP9 = (float)(p_frameBounds->b[0].x - v10[20]);
          _FP5 = (float)(this->frameBounds.b[0].z - v10[28]);
          _FP3 = (float)(v10[20] - v2->x);
          _FP7 = (float)(this->frameBounds.b[0].y - v10[24]);
          _FP1 = (float)(v10[24] - this->frameBounds.b[1].y);
          _FP31 = (float)(v10[28] - this->frameBounds.b[1].z);
          __asm { fsel      f11, f9, f0, f11 }
          p_frameBounds->b[0].x = _FP11;
          __asm { fsel      f9, f5, f12, f8 }
          this->frameBounds.b[0].z = _FP9;
          __asm { fsel      f8, f3, f0, f6 }
          v2->x = _FP8;
          __asm { fsel      f10, f7, f13, f10 }
          this->frameBounds.b[0].y = _FP10;
          __asm { fsel      f7, f1, f13, f4 }
          this->frameBounds.b[1].y = _FP7;
          __asm { fsel      f6, f31, f12, f2 }
          this->frameBounds.b[1].z = _FP6;
        }
        v3 += 4;
        v10 += 48;
        v9 += 4;
      }
      while ( v3 < numJoints - 3 );
    }
    if ( v3 < numJoints )
    {
      v59 = numJoints - v3;
      v60 = &v8[v3].mat[7];
      do
      {
        if ( this->skipJointForBounds.value != (__int16)v3 )
        {
          _FP9 = (float)(p_frameBounds->b[0].x - *(v60 - 4));
          _FP5 = (float)(this->frameBounds.b[0].z - v60[4]);
          _FP3 = (float)(*(v60 - 4) - v2->x);
          _FP7 = (float)(this->frameBounds.b[0].y - *v60);
          _FP1 = (float)(*v60 - this->frameBounds.b[1].y);
          _FP31 = (float)(v60[4] - this->frameBounds.b[1].z);
          __asm { fsel      f11, f9, f0, f11 }
          p_frameBounds->b[0].x = _FP11;
          __asm { fsel      f9, f5, f12, f8 }
          this->frameBounds.b[0].z = _FP9;
          __asm { fsel      f8, f3, f0, f6 }
          v2->x = _FP8;
          __asm { fsel      f10, f7, f13, f10 }
          this->frameBounds.b[0].y = _FP10;
          __asm { fsel      f7, f1, f13, f4 }
          this->frameBounds.b[1].y = _FP7;
          __asm { fsel      f6, f31, f12, f2 }
          this->frameBounds.b[1].z = _FP6;
        }
        LOWORD(v3) = v3 + 1;
        v60 += 12;
        --v59;
      }
      while ( v59 != 0 );
    }
    p_frameBounds->b[0].x = p_frameBounds->b[0].x - (float)16.0;
    this->frameBounds.b[0].y = this->frameBounds.b[0].y - (float)16.0;
    this->frameBounds.b[0].z = this->frameBounds.b[0].z - (float)16.0;
    v2->x = v2->x + (float)16.0;
    this->frameBounds.b[1].y = this->frameBounds.b[1].y + (float)16.0;
    this->frameBounds.b[1].z = this->frameBounds.b[1].z + (float)16.0;
  }
  if ( p_frameBounds->b[0].x <= (double)v2->x )
  {
    y = this->frameBounds.b[0].y;
    z = this->frameBounds.b[0].z;
    v75 = this->decl->model;
    p_frameBounds->b[0].x = v75->minBoundsExpansion.x + p_frameBounds->b[0].x;
    this->frameBounds.b[0].y = v75->minBoundsExpansion.y + (float)y;
    this->frameBounds.b[0].z = v75->minBoundsExpansion.z + (float)z;
    v76 = this->frameBounds.b[1].y;
    v77 = this->frameBounds.b[1].z;
    this->frameBounds.b[1].x = this->frameBounds.b[1].x + v75->maxBoundsExpansion.x;
    this->frameBounds.b[1].y = v75->maxBoundsExpansion.y + (float)v76;
    this->frameBounds.b[1].z = v75->maxBoundsExpansion.z + (float)v77;
  }
  v78 = this->frameBounds.b[0].y;
  v79 = this->frameBounds.b[0].z;
  config = this->decl->config;
  p_frameBounds->b[0].x = config->visualOffset[0] + p_frameBounds->b[0].x;
  this->frameBounds.b[0].y = (float)v78 + config->visualOffset[1];
  this->frameBounds.b[0].z = config->visualOffset[2] + (float)v79;
  v81 = this->frameBounds.b[1].y;
  v82 = this->frameBounds.b[1].z;
  v2->x = v2->x + config->visualOffset[0];
  this->frameBounds.b[1].y = (float)v81 + config->visualOffset[1];
  this->frameBounds.b[1].z = (float)v82 + config->visualOffset[2];
}


// ========================================================================
// ?SyncJoints@idTreeAnimator@@QAAXH@Z
// EA  : 0x8285D9A8
// RVA : 0x0085D9A8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SyncJoints(idTreeAnimator *this, const int time)
{
  int deferredJobJointBuffer; // r11
  int v4; // r11
  idPixelUnpackBuffer *v5; // r3
  idJointMat *v6; // r10
  idJointMat *v7; // r9
  md6OriginDelta_t *v8; // r7
  double Volume; // fp1
  char v10; // r11
  md6OriginDelta_t *v11; // r9
  idBounds *p_frameBounds; // r11
  idVec3 *v13; // r10
  double v14; // fp7
  double v15; // fp0
  double v16; // fp8
  double v17; // fp13
  double v18; // fp11
  double y; // fp13
  double z; // fp12
  const idMD6Model *model; // r7
  double v22; // fp5
  double v23; // fp1
  double v24; // fp10
  double v25; // fp7
  double v26; // fp5
  double v27; // fp3
  double v28; // fp2
  double v29; // fp1
  double v30; // fp13
  double v31; // fp12
  idMD6Blend::configInfo_t *config; // r8
  double v33; // fp4
  double v34; // fp3

  if ( (*((_BYTE *)this + 2164) & 0x80) != 0 )
  {
    deferredJobJointBuffer = this->deferredJobJointBuffer;
    if ( deferredJobJointBuffer >= 0 )
    {
      v4 = 16 * (deferredJobJointBuffer + 140);
      v5 = (idPixelUnpackBuffer *)((char *)this + v4);
      if ( *(int *)((char *)&this->__vftable + v4) < 0 )
        idVertexBuffer::UnmapBuffer(this: v5);
    }
    v6 = this->joints[2];
    this->joints[2] = this->joints[0];
    this->joints[0] = v6;
    v7 = this->joints[3];
    this->joints[3] = this->joints[1];
    this->joints[1] = v7;
    v8 = this->originDelta[0];
    this->originDelta[0] = this->originDelta[1];
    this->originDelta[1] = v8;
    if ( this->decl->calcRefBoundsFromJoints
      || (*((_BYTE *)this + 2164) & 0x10) != 0
      || (Volume = idBounds::GetVolume(this: &this->frameBounds), v10 = 0, Volume <= 0.0) )
    {
      v10 = 1;
    }
    if ( v10 != 0 )
    {
      v11 = this->originDelta[1];
      p_frameBounds = &this->frameBounds;
      v13 = &this->frameBounds.b[1];
      v14 = v11->jointBounds[3];
      v15 = v11->jointBounds[5];
      v16 = v11->jointBounds[0];
      v17 = v11->jointBounds[4];
      v18 = v11->jointBounds[2];
      this->frameBounds.b[0].y = v11->jointBounds[1];
      this->frameBounds.b[1].x = v14;
      this->frameBounds.b[1].y = v17;
      this->frameBounds.b[0].z = v18;
      this->frameBounds.b[1].z = v15;
      this->frameBounds.b[0].x = v16;
      if ( v16 <= v14 )
      {
        y = this->frameBounds.b[0].y;
        z = this->frameBounds.b[0].z;
        model = this->decl->model;
        p_frameBounds->b[0].x = p_frameBounds->b[0].x + model->minBoundsExpansion.x;
        this->frameBounds.b[0].y = model->minBoundsExpansion.y + (float)y;
        this->frameBounds.b[0].z = model->minBoundsExpansion.z + (float)z;
        v22 = this->frameBounds.b[1].y;
        this->frameBounds.b[1].x = model->maxBoundsExpansion.x + this->frameBounds.b[1].x;
        v23 = this->frameBounds.b[1].z;
        this->frameBounds.b[1].y = model->maxBoundsExpansion.y + (float)v22;
        this->frameBounds.b[1].z = model->maxBoundsExpansion.z + (float)v23;
      }
      v24 = this->g.scale.z;
      v25 = (float)(this->g.scale.y * this->frameBounds.b[0].y);
      v26 = (float)(this->g.scale.z * this->frameBounds.b[0].z);
      v27 = (float)(this->g.scale.x * v13->x);
      v28 = this->frameBounds.b[1].z;
      v29 = (float)(this->g.scale.y * this->frameBounds.b[1].y);
      p_frameBounds->b[0].x = this->g.scale.x * p_frameBounds->b[0].x;
      this->frameBounds.b[0].y = v25;
      this->frameBounds.b[0].z = v26;
      v13->x = v27;
      this->frameBounds.b[1].y = v29;
      this->frameBounds.b[1].z = (float)v24 * (float)v28;
      v30 = this->frameBounds.b[0].y;
      v31 = this->frameBounds.b[0].z;
      config = this->decl->config;
      p_frameBounds->b[0].x = p_frameBounds->b[0].x + config->visualOffset[0];
      this->frameBounds.b[0].y = config->visualOffset[1] + (float)v30;
      this->frameBounds.b[0].z = config->visualOffset[2] + (float)v31;
      v33 = this->frameBounds.b[1].y;
      v34 = this->frameBounds.b[1].z;
      v13->x = config->visualOffset[0] + v13->x;
      this->frameBounds.b[1].y = config->visualOffset[1] + (float)v33;
      this->frameBounds.b[1].z = (float)v34 + config->visualOffset[2];
    }
    *((_BYTE *)this + 2164) &= ~0x80u;
  }
}


// ========================================================================
// AnimationBlendJob
// EA  : 0x8285DC20
// RVA : 0x0085DC20
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall AnimationBlendJob(
        idMD6Blend::blendParms_t *blendParms,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  double v11; // fp8
  double v12; // fp7
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v17; // fp2
  double v18; // fp1
  int v19; // r12
  unsigned int LastError; // r3
  unsigned int flags; // r10
  unsigned int clearOriginTransform; // r9
  const float *back_chain[3]; // [sp+0h] [-130h]
  bool v24; // [sp+Fh] [-121h]
  const idMD6Blend::jointMod_t *v25; // [sp+10h] [-120h]
  unsigned int v26; // [sp+14h] [-11Ch]
  const float *v27; // [sp+18h] [-118h]
  const float *v28; // [sp+1Ch] [-114h]
  const unsigned __int8 *v29; // [sp+20h] [-110h]
  float *v30; // [sp+24h] [-10Ch]
  float *v31; // [sp+28h] [-108h]
  float *v32; // [sp+2Ch] [-104h]
  md6OriginDelta_t *v33; // [sp+30h] [-100h]
  float *v34; // [sp+34h] [-FCh]
  unsigned int v35; // [sp+38h] [-F8h]
  int v36; // [sp+3Ch] [-F4h]
  int v37; // [sp+40h] [-F0h]
  int v38; // [sp+44h] [-ECh]
  int v39; // [sp+48h] [-E8h]
  int v40; // [sp+4Ch] [-E4h]
  int v41; // [sp+50h] [-E0h]
  int v42; // [sp+58h] [-D8h]
  int v43; // [sp+60h] [-D0h]
  int v44; // [sp+68h] [-C8h]
  int v45; // [sp+70h] [-C0h]
  int v46; // [sp+78h] [-B8h]
  int v47; // [sp+80h] [-B0h]
  int v48; // [sp+88h] [-A8h]
  int v49; // [sp+90h] [-A0h]
  int v50; // [sp+98h] [-98h]
  int v51; // [sp+A0h] [-90h]
  int v52; // [sp+A8h] [-88h]
  int v53; // [sp+B4h] [-7Ch]

  ((void (*)(void))RtlCheckStack12)();
  *(const float **)((char *)back_chain + v19) = back_chain[0];
  if ( anim_recordTrace.valueInteger != 0 && blendParms->skeleton->numJoints > 0x60u && blendParms->numMods != 0 )
  {
    idCVar::SetBool(this: &anim_recordTrace, newValue: false, force: true);
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  flags = blendParms->flags;
  clearOriginTransform = blendParms->clearOriginTransform;
  v53 = 0;
  idMD6Blend::ExecuteCommands(
    skeleton: blendParms->skeleton,
    temp: (char *)(((unsigned int)&a10 + 3) & 0xFFFFFF80),
    tempSize: 0x10000u,
    cmds: blendParms->cmds,
    numCmds: blendParms->numCmds,
    clearOriginTransform: clearOriginTransform != 0,
    boundsSkipJoint: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)blendParms->boundsSkipJoint.value,
    useDualquat: flags != 0,
    a9: v18,
    a10: v17,
    a11: v16,
    a12: v15,
    a13: v14,
    a14: v13,
    a15: v12,
    a16: v11,
    originOffset: back_chain[2],
    addOffset: v24,
    jointMods: v25,
    numJointMods: v26,
    invertedBasePose: v27,
    invertedBasePoseQuat: v28,
    jointRemap: v29,
    refPose: v30,
    finalPose: v31,
    renderPose: v32,
    originDelta: v33,
    userChannels: v34,
    dmaTag: v35,
    a30: v36,
    a31: v37,
    a32: v38,
    a33: v39,
    a34: v40,
    a35: v41,
    a36: blendParms->config->visualOffset,
    a37: v42,
    a38: 1u,
    a39: v43,
    a40: blendParms->mods,
    a41: v44,
    a42: blendParms->numMods,
    a43: v45,
    originOffseta: blendParms->invertedBasePose,
    a45: v46,
    a46: blendParms->invertedBasePoseQuat,
    a47: v47,
    jointModsa: blendParms->jointRemap,
    a49: v48,
    numJointModsa: (const idMD6Blend::jointMod_t *)blendParms->referencePose,
    a51: v49,
    invertedBasePosea: blendParms->finalPose,
    a53: v50,
    invertedBasePoseQuata: blendParms->renderPose,
    a55: v51,
    jointRemapa: (unsigned __int8 *)blendParms->originDelta,
    a57: v52,
    refPosea: blendParms->userChannels);
  __lwsync();
  blendParms->originDelta->done = true;
}


// ========================================================================
// AnimationBlendJobToRSTU
// EA  : 0x8285DD58
// RVA : 0x0085DD58
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall AnimationBlendJobToRSTU(
        idMD6Blend::blendParms_t *blendParms,
        const idMD6Blend::jointMod_t *localR,
        float *localS,
        float *localT,
        float *localU,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)
{
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  double v22; // fp1
  int v23; // r12
  unsigned int LastError; // r3
  md6OriginDelta_t *originDelta; // r23
  float *finalPose; // r21
  const unsigned __int8 *jointRemap; // r20
  bool v28; // r8
  unsigned int numMods; // r19
  const idMD6Blend::jointMod_t *mods; // r11
  const idMD6Blend::configInfo_t *config; // r10
  const idIndex<short,enum invalidJointIndex_t> *value; // r9
  unsigned int numCmds; // r7
  const md6AnimCommand_t *cmds; // r6
  const idMD6SkelData *skeleton; // r3
  _DWORD back_chain[2]; // [sp+0h] [-120h]
  bool v37; // [sp+Bh] [-115h]
  const idMD6Blend::jointMod_t *v38; // [sp+Ch] [-114h]
  unsigned int v39; // [sp+10h] [-110h]
  const unsigned __int8 *v40; // [sp+14h] [-10Ch]
  float *v41; // [sp+18h] [-108h]
  float *v42; // [sp+1Ch] [-104h]
  float *v43; // [sp+20h] [-100h]
  float *v44; // [sp+24h] [-FCh]
  md6OriginDelta_t *v45; // [sp+28h] [-F8h]
  float *v46; // [sp+2Ch] [-F4h]
  unsigned int v47; // [sp+30h] [-F0h]
  int v48; // [sp+34h] [-ECh]
  int v49; // [sp+38h] [-E8h]
  int v50; // [sp+3Ch] [-E4h]
  int v51; // [sp+40h] [-E0h]
  int v52; // [sp+44h] [-DCh]
  int v53; // [sp+48h] [-D8h]
  int v54; // [sp+4Ch] [-D4h]
  int v55; // [sp+50h] [-D0h]
  int v56; // [sp+58h] [-C8h]
  int v57; // [sp+60h] [-C0h]
  int v58; // [sp+68h] [-B8h]
  int v59; // [sp+70h] [-B0h]
  int v60; // [sp+78h] [-A8h]
  int v61; // [sp+80h] [-A0h]
  int v62; // [sp+88h] [-98h]
  int v63; // [sp+90h] [-90h]
  int v64; // [sp+98h] [-88h]
  int v65; // [sp+A4h] [-7Ch]

  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v23) = back_chain[0];
  if ( anim_recordTrace.valueInteger != 0 && blendParms->skeleton->numJoints > 0x60u && blendParms->numMods != 0 )
  {
    idCVar::SetBool(this: &anim_recordTrace, newValue: false, force: true);
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  originDelta = blendParms->originDelta;
  finalPose = blendParms->finalPose;
  jointRemap = blendParms->jointRemap;
  v28 = blendParms->clearOriginTransform != 0;
  numMods = blendParms->numMods;
  mods = blendParms->mods;
  config = blendParms->config;
  value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)blendParms->boundsSkipJoint.value;
  numCmds = blendParms->numCmds;
  cmds = blendParms->cmds;
  skeleton = blendParms->skeleton;
  v65 = 0;
  idMD6Blend::ExecuteCommandsToRSTU(
    skeleton,
    temp: (char *)(((unsigned int)&a10 + 3) & 0xFFFFFF80),
    tempSize: 0x10000u,
    cmds,
    numCmds,
    clearOriginTransform: v28,
    boundsSkipJoint: value,
    originOffset: config->visualOffset,
    a9: v22,
    a10: v21,
    a11: v20,
    a12: v19,
    a13: v18,
    a14: v17,
    a15: v16,
    a16: v15,
    addOffset: v37,
    jointMods: v38,
    numJointMods: v39,
    jointRemap: v40,
    finalPose: v41,
    localR: v42,
    localS: v43,
    localT: v44,
    originDelta: v45,
    userChannels: v46,
    dmaTag: v47,
    a28: v48,
    a29: v49,
    a30: v50,
    a31: v51,
    a32: v52,
    a33: v53,
    a34: v54,
    a35: v55,
    a36: 1u,
    a37: v56,
    a38: mods,
    a39: v57,
    a40: numMods,
    a41: v58,
    a42: (int)jointRemap,
    a43: v59,
    a44: finalPose,
    a45: v60,
    jointModsa: localR,
    a47: v61,
    numJointModsa: localS,
    a49: v62,
    jointRemapa: (unsigned __int8 *)localT,
    a51: v63,
    finalPosea: originDelta->deltaRotation,
    a53: v64,
    localRa: localU);
  __lwsync();
  blendParms->originDelta->done = true;
}


// ========================================================================
// ?UpdateTime@idTreeAnimator@@QAAXH@Z
// EA  : 0x8285DE78
// RVA : 0x0085DE78
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTreeAnimator::UpdateTime(idTreeAnimator *this, const int time)
{
  idTreeAnimator::ShowSkel(this);
}


// ========================================================================
// ?GetModelSpaceJointBindTransform@idTreeAnimator@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x8285DE80
// RVA : 0x0085DE80
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetModelSpaceJointBindTransform(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        idVec3 *origin,
        idMat3 *axis)
{
  const idDeclMD6 *decl; // r10
  idMD6SkelData *data; // r10
  double v8; // fp13
  double v10; // fp12
  double v11; // fp10
  double v12; // fp9
  double v13; // fp8
  double v14; // fp7
  double v15; // fp6
  double v16; // fp5
  double v17; // fp4
  double v18; // fp3
  idMat3x4 v19; // [sp+50h] [-50h] BYREF

  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  if ( (__int16)jointIndex < 0 )
    return 0;
  data = decl->model->skeleton->data;
  if ( (__int16)jointIndex >= (int)data->numJoints )
    return 0;
  v19 = *(idMat3x4 *)((char *)&data->size + 48 * (__int16)jointIndex + data->inverseBasePoseOffset);
  idMat3x4::Invert(this: &v19);
  v8 = v19.mat[7];
  v10 = v19.mat[11];
  origin->x = v19.mat[3];
  origin->y = v8;
  origin->z = v10;
  v11 = v19.mat[1];
  v12 = v19.mat[2];
  v13 = v19.mat[4];
  v14 = v19.mat[5];
  v15 = v19.mat[6];
  v16 = v19.mat[8];
  v17 = v19.mat[9];
  v18 = v19.mat[10];
  axis->mat[0].x = v19.mat[0];
  axis->mat[1].x = v11;
  axis->mat[2].x = v12;
  axis->mat[0].y = v13;
  axis->mat[1].y = v14;
  axis->mat[2].y = v15;
  axis->mat[0].z = v16;
  axis->mat[1].z = v17;
  axis->mat[2].z = v18;
  return 1;
}


// ========================================================================
// ?GetModelSpaceJointTransform@idTreeAnimator@@QBA_NW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x8285DF80
// RVA : 0x0085DF80
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetModelSpaceJointTransform(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        idVec3 *origin,
        idMat3 *axis)
{
  const idDeclMD6 *decl; // r9
  idJointMat *v7; // r11

  decl = this->decl;
  if ( decl == nullptr || (__int16)jointIndex < 0 || (__int16)jointIndex >= (int)decl->model->skeleton->data->numJoints )
    return 0;
  v7 = &this->joints[pose != 0][(__int16)jointIndex];
  origin->x = v7->mat[3] * this->g.scale.x;
  origin->y = v7->mat[7] * this->g.scale.y;
  origin->z = v7->mat[11] * this->g.scale.z;
  axis->mat[0].x = v7->mat[0];
  axis->mat[0].y = v7->mat[4];
  axis->mat[0].z = v7->mat[8];
  axis->mat[1].x = v7->mat[1];
  axis->mat[1].y = v7->mat[5];
  axis->mat[1].z = v7->mat[9];
  axis->mat[2].x = v7->mat[2];
  axis->mat[2].y = v7->mat[6];
  axis->mat[2].z = v7->mat[10];
  return 1;
}


// ========================================================================
// ?GetWorldSpaceJointTransform@idTreeAnimator@@QBA_NW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x8285E060
// RVA : 0x0085E060
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetWorldSpaceJointTransform(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        idVec3 *origin,
        idMat3 *axis)
{
  idMat3 *v7; // r7
  float *v8; // r6
  double y; // fp9
  double z; // fp5
  double v11; // fp2
  double v12; // fp1

  if ( (__int16)jointIndex == -1 )
  {
    *origin = this->g.origin;
    *axis = this->g.axis;
    return 0;
  }
  else if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(this, pose, jointIndex, origin, axis) != 0 )
  {
    y = this->g.origin.y;
    z = this->g.origin.z;
    v11 = (float)((float)(this->g.axis.mat[2].y * v8[2])
                + (float)((float)(this->g.axis.mat[0].y * *v8) + (float)(this->g.axis.mat[1].y * v8[1])));
    v12 = (float)((float)(this->g.axis.mat[2].z * v8[2])
                + (float)((float)(this->g.axis.mat[0].z * *v8) + (float)(this->g.axis.mat[1].z * v8[1])));
    *v8 = this->g.origin.x
        + (float)((float)(*v8 * this->g.axis.mat[0].x)
                + (float)((float)(this->g.axis.mat[1].x * v8[1]) + (float)(this->g.axis.mat[2].x * v8[2])));
    v8[1] = (float)y + (float)v11;
    v8[2] = (float)z + (float)v12;
    idMat3::operator*=(this: v7, a: &this->g.axis);
    return 1;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetModelSpaceAttachmentTransform@idTreeAnimator@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@ABVidVec3@@ABVidQuat@@AAV3@AAVidMat3@@@Z
// EA  : 0x8285E1C0
// RVA : 0x0085E1C0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetModelSpaceAttachmentTransform(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const idVec3 *translationOffset,
        idMat3 *rotationOffset,
        idVec3 *origin,
        idMat3 *axis)
{
  double z; // fp3
  double x; // fp31
  double v14; // fp12
  double v15; // fp11
  idMat3 *v16; // r3
  idVec3 v17; // [sp+50h] [-D0h] BYREF
  idMat3 v18; // [sp+60h] [-C0h] BYREF
  idQuat v19; // [sp+90h] [-90h] BYREF
  idMat3 v20; // [sp+C0h] [-60h] BYREF

  if ( (__int16)jointIndex == -1 )
  {
    *origin = vec3_origin;
    *axis = mat3_identity;
    return 0;
  }
  else if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                               this,
                               pose: DRIVER_MODEL,
                               jointIndex,
                               origin: &v17,
                               axis: &v18) != 0 )
  {
    z = v17.z;
    x = v17.x;
    v14 = (float)((float)(v18.mat[1].z * (float)(this->g.scale.y * translationOffset->y))
                + (float)((float)(v18.mat[2].z * (float)(this->g.scale.z * translationOffset->z))
                        + (float)(v18.mat[0].z * (float)(this->g.scale.x * translationOffset->x))));
    v15 = (float)((float)(v18.mat[0].x * (float)(this->g.scale.x * translationOffset->x))
                + (float)((float)(v18.mat[2].x * (float)(this->g.scale.z * translationOffset->z))
                        + (float)(v18.mat[1].x * (float)(this->g.scale.y * translationOffset->y))));
    origin->y = v17.y
              + (float)((float)(v18.mat[1].y * (float)(this->g.scale.y * translationOffset->y))
                      + (float)((float)(v18.mat[2].y * (float)(this->g.scale.z * translationOffset->z))
                              + (float)(v18.mat[0].y * (float)(this->g.scale.x * translationOffset->x))));
    origin->z = (float)z + (float)v14;
    origin->x = (float)v15 + (float)x;
    v16 = idQuat::ToMat3(this: &v19, result: rotationOffset);
    *axis = *idMat3::operator*(this: &v20, result: v16, a: &v18);
    return 1;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetWorldSpaceAttachmentTransform@idTreeAnimator@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@ABVidVec3@@ABVidQuat@@AAV3@AAVidMat3@@@Z
// EA  : 0x8285E3B0
// RVA : 0x0085E3B0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetWorldSpaceAttachmentTransform(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const idVec3 *translationOffset,
        idMat3 *rotationOffset,
        idVec3 *origin,
        idMat3 *axis)
{
  double y; // fp9
  double z; // fp5
  double v12; // fp2
  double v13; // fp1

  if ( (unsigned __int8)idTreeAnimator::GetModelSpaceAttachmentTransform(
                          this,
                          jointIndex,
                          translationOffset,
                          rotationOffset,
                          origin,
                          axis) == 0 )
    return 0;
  y = this->g.origin.y;
  z = this->g.origin.z;
  v12 = (float)((float)(this->g.axis.mat[2].y * origin->z)
              + (float)((float)(this->g.axis.mat[0].y * origin->x) + (float)(this->g.axis.mat[1].y * origin->y)));
  v13 = (float)((float)(this->g.axis.mat[2].z * origin->z)
              + (float)((float)(this->g.axis.mat[0].z * origin->x) + (float)(this->g.axis.mat[1].z * origin->y)));
  origin->x = this->g.origin.x
            + (float)((float)(this->g.axis.mat[0].x * origin->x)
                    + (float)((float)(this->g.axis.mat[1].x * origin->y) + (float)(this->g.axis.mat[2].x * origin->z)));
  origin->y = (float)y + (float)v12;
  origin->z = (float)z + (float)v13;
  idMat3::operator*=(this: axis, a: &this->g.axis);
  return 1;
}


// ========================================================================
// ?GetModelSpaceJointFrameDeltas@idTreeAnimator@@QBA_NPBV?$idIndex@FW4invalidJointIndex_t@@@@HPAVidVec3@@PAVidMat3@@@Z
// EA  : 0x8285E478
// RVA : 0x0085E478
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetModelSpaceJointFrameDeltas(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *indices,
        int numIndices,
        idVec3 *transDeltas,
        idMat3 *rotDeltas)
{
  const idIndex<short,enum invalidJointIndex_t> *v6; // r29
  float *p_z; // r30
  char *v8; // r31
  int v9; // r28
  idJointMat *v10; // r8
  idJointMat *v11; // r7
  int value; // r10
  float *mat; // r10
  double v14; // fp0
  double v15; // fp13
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  int v19; // r9
  double v20; // fp4
  double v21; // fp3
  double v22; // fp2
  double v23; // fp1
  double v24; // fp0
  double v25; // fp13
  double v26; // fp12
  double v27; // fp11
  double v28; // fp10
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v32; // fp6
  double v33; // fp31
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  idVec3 *v37; // r3
  idMat3 v39; // [sp+50h] [-E0h] BYREF
  idMat3 v40; // [sp+80h] [-B0h] BYREF
  idMat3 v41[2]; // [sp+B0h] [-80h] BYREF

  if ( numIndices > 0 )
  {
    v6 = indices - 1;
    p_z = &transDeltas[-1].z;
    v8 = (char *)&rotDeltas[-1].mat[2].z;
    v9 = numIndices;
    do
    {
      v10 = this->joints[3];
      v11 = this->joints[1];
      value = v6[1].value;
      v14 = v10[value].mat[3];
      v15 = v10[value].mat[7];
      v16 = v10[value].mat[11];
      mat = v11[value].mat;
      v17 = (float)(mat[7] - (float)v15);
      v18 = mat[11];
      p_z[1] = mat[3] - (float)v14;
      p_z[2] = v17;
      p_z += 3;
      *p_z = (float)v18 - (float)v16;
      ++v6;
      v19 = v6->value;
      v20 = v11[v19].mat[0];
      v21 = v10[v19].mat[10];
      v22 = v10[v19].mat[6];
      v23 = v10[v19].mat[2];
      v24 = v10[v19].mat[9];
      v25 = v10[v19].mat[5];
      v26 = v10[v19].mat[1];
      v27 = v10[v19].mat[8];
      v28 = v10[v19].mat[4];
      v29 = v11[v19].mat[10];
      v30 = v11[v19].mat[6];
      v31 = v11[v19].mat[2];
      v32 = v11[v19].mat[9];
      v33 = v11[v19].mat[5];
      v34 = v11[v19].mat[1];
      v35 = v11[v19].mat[8];
      v36 = v11[v19].mat[4];
      v39.mat[0].x = v10[v19].mat[0];
      v40.mat[0].x = v20;
      v39.mat[2].z = v21;
      v39.mat[1].z = v22;
      v39.mat[0].z = v23;
      v39.mat[2].y = v24;
      v39.mat[1].y = v25;
      v39.mat[0].y = v26;
      v39.mat[2].x = v27;
      v39.mat[1].x = v28;
      v40.mat[2].z = v29;
      v40.mat[2].y = v30;
      v40.mat[2].x = v31;
      v40.mat[1].z = v32;
      v40.mat[1].y = v33;
      v40.mat[1].x = v34;
      v40.mat[0].z = v35;
      v40.mat[0].y = v36;
      v37 = (idVec3 *)idMat3::operator*(this: v41, result: &v40, a: &v39);
      *(idVec3 *)(v8 + 4) = *v37;
      --v9;
      *(idVec3 *)(v8 + 16) = v37[1];
      *((float *)v8 + 7) = v37[2].x;
      *((float *)v8 + 8) = v37[2].y;
      v8 += 36;
      *(float *)v8 = v37[2].z;
    }
    while ( v9 != 0 );
  }
  return 1;
}


// ========================================================================
// ?GetWorldSpaceJointFrameDeltas@idTreeAnimator@@QBA_NPBV?$idIndex@FW4invalidJointIndex_t@@@@HPAVidVec3@@PAVidMat3@@@Z
// EA  : 0x8285E620
// RVA : 0x0085E620
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetWorldSpaceJointFrameDeltas(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *indices,
        int numIndices,
        idVec3 *transDeltas,
        idMat3 *rotDeltas)
{
  idRenderModelParms *p_g; // r25
  idMat3 *p_axis; // r30
  const idIndex<short,enum invalidJointIndex_t> *v8; // r27
  float *p_z; // r28
  char *v10; // r31
  int v11; // r26
  idJointMat *v12; // r23
  unsigned int value; // r24
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  float *Axis; // r3
  double v18; // fp1
  double v19; // fp0
  double v20; // fp30
  double v21; // fp29
  double v22; // fp31
  idRenderModelParms *Origin; // r3
  idJointMat *v24; // r11
  double v25; // fp12
  double v26; // fp31
  double v27; // fp3
  double v28; // fp1
  float *mat; // r11
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp7
  double v34; // fp6
  double v35; // fp5
  double v36; // fp4
  double v37; // fp3
  const idMat3 *v38; // r3
  idJointMat *v39; // r11
  double v40; // fp1
  double v41; // fp0
  double v42; // fp13
  double v43; // fp12
  double v44; // fp11
  double v45; // fp10
  double v46; // fp9
  double v47; // fp8
  idVec3 *v48; // r3
  idMat3 v50; // [sp+50h] [-190h] BYREF
  idMat3 v51; // [sp+80h] [-160h] BYREF
  idMat3 v52; // [sp+B0h] [-130h] BYREF
  idMat3 v53; // [sp+E0h] [-100h] BYREF
  idMat3 v54; // [sp+110h] [-D0h] BYREF
  idMat3 v55[2]; // [sp+140h] [-A0h] BYREF

  if ( numIndices > 0 )
  {
    p_g = &this->g;
    p_axis = &this->g.axis;
    v8 = indices - 1;
    p_z = &transDeltas[-1].z;
    v10 = (char *)&rotDeltas[-1].mat[2].z;
    v11 = numIndices;
    do
    {
      v12 = this->joints[3];
      value = v8[1].value;
      v14 = v12[value].mat[3];
      v15 = v12[value].mat[7];
      v16 = v12[value].mat[11];
      Axis = (float *)idRenderModel::GetAxis(this);
      v18 = (float)((float)(Axis[7] * (float)v16) + (float)(Axis[4] * (float)v15));
      v19 = (float)((float)(Axis[8] * (float)v16) + (float)(Axis[5] * (float)v15));
      v20 = (float)((float)(*Axis * (float)v14) + (float)((float)(Axis[6] * (float)v16) + (float)(Axis[3] * (float)v15)));
      v21 = (float)((float)(Axis[1] * (float)v14) + (float)v18);
      v22 = (float)((float)(Axis[2] * (float)v14) + (float)v19);
      Origin = idRenderModel::GetOrigin(this);
      v24 = &this->joints[1][value];
      v25 = (float)(Origin->origin.x + (float)v20);
      v26 = (float)(Origin->origin.z + (float)v22);
      v27 = (float)(p_g->origin.x
                  + (float)((float)(p_axis->mat[0].x * v24->mat[3])
                          + (float)((float)(p_axis->mat[2].x * v24->mat[11]) + (float)(p_axis->mat[1].x * v24->mat[7]))));
      v28 = (float)(p_g->origin.z
                  + (float)((float)(p_axis->mat[1].z * v24->mat[7])
                          + (float)((float)(p_axis->mat[0].z * v24->mat[3]) + (float)(p_axis->mat[2].z * v24->mat[11]))));
      p_z[2] = (float)(p_g->origin.y
                     + (float)((float)(p_axis->mat[1].y * v24->mat[7])
                             + (float)((float)(p_axis->mat[0].y * v24->mat[3]) + (float)(p_axis->mat[2].y * v24->mat[11]))))
             - (float)(Origin->origin.y + (float)v21);
      p_z[1] = (float)v27 - (float)v25;
      p_z += 3;
      *p_z = (float)v28 - (float)v26;
      mat = v12[v8[1].value].mat;
      v30 = mat[6];
      v31 = mat[2];
      v32 = mat[9];
      v33 = mat[5];
      v34 = mat[1];
      v35 = mat[8];
      v36 = mat[4];
      v37 = *mat;
      v53.mat[2].z = mat[10];
      v53.mat[2].y = v30;
      v53.mat[2].x = v31;
      v53.mat[1].z = v32;
      v53.mat[1].y = v33;
      v53.mat[1].x = v34;
      v53.mat[0].z = v35;
      v53.mat[0].x = v37;
      v53.mat[0].y = v36;
      v38 = idRenderModel::GetAxis(this);
      idMat3::operator*(this: &v54, result: &v53, a: v38);
      ++v8;
      v39 = &this->joints[1][v8->value];
      v40 = v39->mat[6];
      v41 = v39->mat[2];
      v42 = v39->mat[9];
      v43 = v39->mat[5];
      v44 = v39->mat[1];
      v45 = v39->mat[8];
      v46 = v39->mat[4];
      v47 = v39->mat[0];
      v52.mat[2].z = v39->mat[10];
      v52.mat[2].y = v40;
      v52.mat[2].x = v41;
      v52.mat[1].z = v42;
      v52.mat[1].y = v43;
      v52.mat[1].x = v44;
      v52.mat[0].z = v45;
      v52.mat[0].x = v47;
      v52.mat[0].y = v46;
      idMat3::operator*(this: &v50, result: &v52, a: p_axis);
      v51.mat[0].x = v50.mat[0].x;
      v51.mat[0].y = v50.mat[1].x;
      v51.mat[0].z = v50.mat[2].x;
      v51.mat[1].x = v50.mat[0].y;
      v51.mat[1].y = v50.mat[1].y;
      v51.mat[1].z = v50.mat[2].y;
      v51.mat[2].x = v50.mat[0].z;
      v51.mat[2].y = v50.mat[1].z;
      v51.mat[2].z = v50.mat[2].z;
      v48 = (idVec3 *)idMat3::operator*(this: v55, result: &v54, a: &v51);
      *(idVec3 *)(v10 + 4) = *v48;
      --v11;
      *(idVec3 *)(v10 + 16) = v48[1];
      *((float *)v10 + 7) = v48[2].x;
      *((float *)v10 + 8) = v48[2].y;
      v10 += 36;
      *(float *)v10 = v48[2].z;
    }
    while ( v11 != 0 );
  }
  return 1;
}


// ========================================================================
// ?GetWorldSpaceAttachmentFrameDeltas@idTreeAnimator@@QBA_NV?$idIndex@FW4invalidJointIndex_t@@@@ABVidVec3@@ABVidQuat@@AAV3@AAVidMat3@@@Z
// EA  : 0x8285E928
// RVA : 0x0085E928
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetWorldSpaceAttachmentFrameDeltas(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const idVec3 *tOffset,
        idMat3 *rOffset,
        idVec3 *tDelta,
        idMat3 *rDelta)
{
  idJointMat *v6; // r9
  double v7; // fp28
  double v9; // fp27
  unsigned int v10; // r10
  double v11; // fp26
  idJointMat *v12; // r10
  double v14; // fp8
  double v16; // fp7
  double v17; // fp5
  double v18; // fp3
  double v19; // fp2
  double v20; // fp1
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  double v25; // fp11
  double v26; // fp31
  double v27; // fp10
  double v28; // fp6
  double v29; // fp9
  double v30; // fp4
  double v31; // fp25
  double v32; // fp24
  double v33; // fp23
  double v34; // fp22
  double v35; // fp21
  double v36; // fp20
  double v37; // fp19
  double v38; // fp18
  double v39; // fp17
  double v40; // fp6
  double v41; // fp16
  double v42; // fp4
  double v43; // fp15
  double v44; // fp3
  double v45; // fp14
  double v46; // fp29
  double v47; // fp30
  double v48; // fp31
  idMat3 *v49; // r3
  double v50; // fp9
  double v51; // fp8
  double v52; // fp28
  double v53; // fp27
  double v54; // fp26
  idMat3 *v55; // r3
  BOOL useDeferredPosition; // r10
  float *p_deferredAxis; // r11
  idRenderModelParms *p_deferredOrigin; // r11
  double v59; // fp0
  double v60; // fp13
  double v61; // fp12
  double v62; // fp7
  double v63; // fp6
  idMat3 *p_axis; // r5
  double z; // fp13
  double v66; // fp8
  double v67; // fp6
  double v68; // fp6
  double v69; // fp4
  double x; // fp30
  double y; // fp29
  double v72; // fp28
  idMat3 *v73; // r3
  BOOL v74; // r10
  idRenderWorldLocal *World; // r31
  float v77; // [sp+50h] [-1B0h] BYREF
  float v78; // [sp+54h] [-1ACh]
  float v79; // [sp+58h] [-1A8h]
  float v80; // [sp+60h] [-1A0h] BYREF
  float v81; // [sp+64h] [-19Ch]
  float v82; // [sp+68h] [-198h]
  idMat3 v83; // [sp+70h] [-190h] BYREF
  idMat3 v84; // [sp+A0h] [-160h] BYREF
  float v85[4]; // [sp+C8h] [-138h] BYREF
  float v86[6]; // [sp+D8h] [-128h] BYREF
  idMat3 v87; // [sp+F0h] [-110h] BYREF
  idMat3 v88[5]; // [sp+120h] [-E0h] BYREF

  v6 = this->joints[3];
  v7 = (float)(this->g.scale.z * tOffset->z);
  v9 = (float)(this->g.scale.y * tOffset->y);
  v10 = (__int16)jointIndex;
  v11 = (float)(tOffset->x * this->g.scale.x);
  v14 = v6[v10].mat[10];
  v16 = v6[v10].mat[6];
  v17 = v6[v10].mat[2];
  v18 = (float)((float)(this->g.scale.z * tOffset->z) * v6[v10].mat[2]);
  v19 = v6[v10].mat[9];
  v20 = v6[v10].mat[5];
  v22 = v6[v10].mat[1];
  v23 = v6[v10].mat[8];
  v24 = v6[v10].mat[4];
  v25 = v6[v10].mat[0];
  v26 = v6[v10].mat[11];
  v27 = v6[v10].mat[3];
  v28 = (float)((float)((float)(this->g.scale.y * tOffset->y) * v6[v10].mat[9])
              + (float)((float)(this->g.scale.z * tOffset->z) * v6[v10].mat[10]));
  v29 = v6[v10].mat[7];
  v30 = (float)((float)((float)(this->g.scale.y * tOffset->y) * v6[v10].mat[5])
              + (float)((float)(this->g.scale.z * tOffset->z) * v6[v10].mat[6]));
  v12 = &this->joints[1][v10];
  v31 = v12->mat[10];
  v32 = v12->mat[6];
  v33 = v12->mat[2];
  v34 = v12->mat[9];
  v35 = v12->mat[5];
  v36 = v12->mat[1];
  v37 = v12->mat[8];
  v38 = v12->mat[4];
  v39 = v12->mat[0];
  v40 = (float)((float)((float)(tOffset->x * this->g.scale.x) * (float)v23) + (float)v28);
  v41 = v12->mat[3];
  v42 = (float)((float)((float)(tOffset->x * this->g.scale.x) * (float)v24) + (float)v30);
  v43 = v12->mat[7];
  v44 = (float)((float)((float)(tOffset->x * this->g.scale.x) * (float)v25)
              + (float)((float)((float)(this->g.scale.y * tOffset->y) * (float)v22) + (float)v18));
  v45 = v12->mat[11];
  v83.mat[2].z = v14;
  v83.mat[2].y = v16;
  v83.mat[2].x = v17;
  v83.mat[1].z = v19;
  v83.mat[1].y = v20;
  v83.mat[1].x = v22;
  v83.mat[0].z = v23;
  v46 = (float)((float)v40 + (float)v26);
  v83.mat[0].y = v24;
  v83.mat[0].x = v25;
  v47 = (float)((float)v42 + (float)v29);
  v84.mat[2].y = v32;
  v48 = (float)((float)v44 + (float)v27);
  v84.mat[2].x = v33;
  v84.mat[1].z = v34;
  v84.mat[1].y = v35;
  v84.mat[1].x = v36;
  v84.mat[0].x = v39;
  v84.mat[0].y = v38;
  v84.mat[0].z = v37;
  v84.mat[2].z = v31;
  v49 = idQuat::ToMat3(this: (idQuat *)v88, result: rOffset);
  idMat3::operator*(this: &v87, result: v49, a: &v83);
  v50 = (float)((float)((float)v11 * (float)v38)
              + (float)((float)((float)v9 * (float)v35) + (float)((float)v7 * (float)v32)));
  v51 = (float)((float)((float)v11 * (float)v37)
              + (float)((float)((float)v9 * (float)v34) + (float)((float)v7 * (float)v31)));
  v52 = (float)((float)((float)((float)v11 * (float)v39)
                      + (float)((float)((float)v9 * (float)v36) + (float)((float)v7 * (float)v33)))
              + (float)v41);
  v53 = (float)((float)v50 + (float)v43);
  v54 = (float)((float)v51 + (float)v45);
  v55 = idQuat::ToMat3(this: (idQuat *)v88, result: rOffset);
  idMat3::operator*(this: &v83, result: v55, a: &v84);
  useDeferredPosition = this->useDeferredPosition;
  p_deferredAxis = (float *)&this->deferredAxis;
  if ( !this->useDeferredPosition )
    p_deferredAxis = (float *)&this->g.axis;
  v59 = (float)((float)(*p_deferredAxis * (float)v48)
              + (float)((float)(p_deferredAxis[6] * (float)v46) + (float)(p_deferredAxis[3] * (float)v47)));
  v60 = (float)((float)(p_deferredAxis[1] * (float)v48)
              + (float)((float)(p_deferredAxis[7] * (float)v46) + (float)(p_deferredAxis[4] * (float)v47)));
  v61 = (float)((float)(p_deferredAxis[2] * (float)v48)
              + (float)((float)(p_deferredAxis[8] * (float)v46) + (float)(p_deferredAxis[5] * (float)v47)));
  p_deferredOrigin = (idRenderModelParms *)&this->deferredOrigin;
  if ( !this->useDeferredPosition )
    p_deferredOrigin = &this->g;
  v62 = (float)(p_deferredOrigin->origin.y + (float)v60);
  v63 = (float)(p_deferredOrigin->origin.z + (float)v61);
  v80 = (float)v59 + p_deferredOrigin->origin.x;
  v81 = v62;
  p_axis = &this->deferredAxis;
  v82 = v63;
  if ( !useDeferredPosition )
    p_axis = &this->g.axis;
  idMat3::operator*(this: &v84, result: &v87, a: p_axis);
  z = this->g.origin.z;
  v66 = (float)((float)(this->g.axis.mat[0].z * (float)v52)
              + (float)((float)(this->g.axis.mat[2].z * (float)v54) + (float)(this->g.axis.mat[1].z * (float)v53)));
  v67 = (float)(this->g.origin.y
              + (float)((float)(this->g.axis.mat[0].y * (float)v52)
                      + (float)((float)(this->g.axis.mat[2].y * (float)v54) + (float)(this->g.axis.mat[1].y * (float)v53))));
  v77 = this->g.origin.x
      + (float)((float)((float)v52 * this->g.axis.mat[0].x)
              + (float)((float)(this->g.axis.mat[2].x * (float)v54) + (float)(this->g.axis.mat[1].x * (float)v53)));
  v78 = v67;
  v79 = (float)z + (float)v66;
  idMat3::operator*(this: &v87, result: &v83, a: &this->g.axis);
  v68 = (float)(v78 - v81);
  v83.mat[0].y = v84.mat[1].x;
  v69 = (float)(v79 - v82);
  x = v84.mat[0].x;
  y = v84.mat[0].y;
  v72 = v84.mat[0].z;
  v83.mat[0].x = v84.mat[0].x;
  v83.mat[0].z = v84.mat[2].x;
  v83.mat[1].x = v84.mat[0].y;
  v83.mat[1].y = v84.mat[1].y;
  v83.mat[1].z = v84.mat[2].y;
  v83.mat[2].x = v84.mat[0].z;
  v83.mat[2].y = v84.mat[1].z;
  v83.mat[2].z = v84.mat[2].z;
  tDelta->x = v77 - v80;
  tDelta->y = v68;
  tDelta->z = v69;
  v73 = idMat3::operator*(this: v88, result: &v87, a: &v83);
  rDelta->mat[0].x = v73->mat[0].x;
  rDelta->mat[0].y = v73->mat[0].y;
  v74 = DEBUG_DRAW;
  rDelta->mat[0].z = v73->mat[0].z;
  rDelta->mat[1] = v73->mat[1];
  rDelta->mat[2] = v73->mat[2];
  if ( v74 )
  {
    World = idRenderModel::GetWorld(this);
    ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, double))World->DebugArrow)(
      a1: World,
      a2: &idColor::colorRed,
      a3: &v80,
      a4: &v77,
      a5: 2.0);
    v86[0] = (float)((float)x * (float)8.0) + v80;
    v86[1] = (float)((float)y * (float)8.0) + v81;
    v86[2] = (float)((float)v72 * (float)8.0) + v82;
    ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, char *, int, int, double))World->DebugArrow)(
      a1: World,
      a2: &idColor::colorPink,
      a3: &v80,
      a4: v86,
      a5: &aAvSsobjectVCom[20],
      a6: 10000,
      a7: 1,
      a8: 1.0);
    v85[0] = (float)(v87.mat[0].x * (float)8.0) + v77;
    v85[1] = (float)(v87.mat[0].y * (float)8.0) + v78;
    v85[2] = (float)(v87.mat[0].z * (float)8.0) + v79;
    ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, double))World->DebugArrow)(
      a1: World,
      a2: &idColor::colorLtGrey,
      a3: &v77,
      a4: v85,
      a5: 1.0);
  }
  return 1;
}


// ========================================================================
// ?NumJoints@idTreeAnimator@@QBAHXZ
// EA  : 0x8285EE08
// RVA : 0x0085EE08
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::NumJoints(idTreeAnimator *this)
{
  return this->decl->model->skeleton->data->numJoints;
}


// ========================================================================
// ?GetJointName@idTreeAnimator@@QBAPBDV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x8285EE20
// RVA : 0x0085EE20
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const char *__fastcall idTreeAnimator::GetJointName(
        idTreeAnimator *this,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  const idDeclMD6 *decl; // r11
  const idMD6Model *model; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *skeleton; // r11
  _WORD v6[4]; // [sp+50h] [-10h] BYREF

  decl = this->decl;
  if ( decl != nullptr
    && (model = decl->model) != nullptr
    && (skeleton = (idHandle<unsigned short,enum invalidJointHandle_t,65535> *)model->skeleton) != nullptr
    && (idMD6Skel::GetJointHandle(this: (idMD6Skel *)v6, result: skeleton, jointIdx: (__int16)jointIndex),
        v6[0] != 0xFFFF) )
  {
    return animation->GetJointName(
             this: animation,
             a2: (const idHandle<unsigned short,enum invalidJointHandle_t,65535> *)v6);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetJointHandle@idTreeAnimator@@QBA?AV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x8285EEB0
// RVA : 0x0085EEB0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::GetJointHandle(
        idTreeAnimator *this,
        idHandle<unsigned short,enum invalidJointHandle_t,65535> *result,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex)
{
  int v3; // r11
  idTreeAnimator *v4; // r31
  int v5; // r11
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *v6; // r4

  v3 = *(_DWORD *)&result[1016].value;
  v4 = this;
  if ( v3 == 0 || (v5 = *(_DWORD *)(v3 + 60)) == 0 )
  {
    HIWORD(this->__vftable) = -1;
    return v4;
  }
  v6 = *(idHandle<unsigned short,enum invalidJointHandle_t,65535> **)(v5 + 212);
  if ( v6 != nullptr )
  {
    idMD6Skel::GetJointHandle((idMD6Skel *)this, result: v6, jointIdx: (__int16)jointIndex);
    return v4;
  }
  HIWORD(this->__vftable) = -1;
  return this;
}


// ========================================================================
// ?SetUseDualQuaternion@idTreeAnimator@@QAAX_N@Z
// EA  : 0x8285EF38
// RVA : 0x0085EF38
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetUseDualQuaternion(idTreeAnimator *this, bool _useDualQuatSkinning)
{
  BOOL v2; // r8

  v2 = ((2 * _useDualQuatSkinning) & 2) != 0;
  *((_BYTE *)this + 2164) = (2 * _useDualQuatSkinning) & 2 | *((_BYTE *)this + 2164) & 0xFD;
  this->jointBuffers.ptr[0].flags = v2;
  this->jointBuffers.ptr[1].flags = v2;
  this->jointBuffers.ptr[2].flags = v2;
  this->jointBuffers.ptr[3].flags = v2;
}


// ========================================================================
// ?GetLastOriginDeltas@idTreeAnimator@@QBAXAAVidVec3@@@Z
// EA  : 0x8285EF68
// RVA : 0x0085EF68
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::GetLastOriginDeltas(idTreeAnimator *this, idVec3 *trans)
{
  md6OriginDelta_t *v2; // r11
  double v3; // fp0
  double v4; // fp8
  double v5; // fp5

  v2 = this->originDelta[1];
  v3 = v2->deltaTranslation[0];
  trans->x = v2->deltaTranslation[0];
  v4 = v2->deltaTranslation[1];
  trans->y = v2->deltaTranslation[1];
  v5 = v2->deltaTranslation[2];
  trans->z = v2->deltaTranslation[2];
  trans->x = this->g.scale.x * (float)v3;
  trans->y = this->g.scale.y * (float)v4;
  trans->z = this->g.scale.z * (float)v5;
}


// ========================================================================
// ?GetLastOriginDeltas@idTreeAnimator@@QBAXAAVidQuat@@AAVidVec3@@@Z
// EA  : 0x8285EFB8
// RVA : 0x0085EFB8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::GetLastOriginDeltas(idTreeAnimator *this, idQuat *rot, idVec3 *trans)
{
  md6OriginDelta_t *v3; // r11
  double v4; // fp4
  double v5; // fp7
  double v6; // fp6

  v3 = this->originDelta[1];
  rot->x = v3->deltaRotation[0];
  rot->y = v3->deltaRotation[1];
  rot->z = v3->deltaRotation[2];
  rot->w = v3->deltaRotation[3];
  v4 = v3->deltaTranslation[0];
  trans->x = v3->deltaTranslation[0];
  v5 = v3->deltaTranslation[1];
  trans->y = v3->deltaTranslation[1];
  v6 = v3->deltaTranslation[2];
  trans->z = v3->deltaTranslation[2];
  trans->x = this->g.scale.x * (float)v4;
  trans->y = this->g.scale.y * (float)v5;
  trans->z = this->g.scale.z * (float)v6;
}


// ========================================================================
// ?GetLastOriginDeltas@idTreeAnimator@@QBAXAAVidMat3@@AAVidVec3@@@Z
// EA  : 0x8285F028
// RVA : 0x0085F028
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::GetLastOriginDeltas(idTreeAnimator *this, idMat3 *rot, idVec3 *trans)
{
  md6OriginDelta_t *v3; // r28
  double v6; // fp13
  double v7; // fp2
  double v8; // fp1
  idQuat v9; // [sp+50h] [-50h] BYREF

  v3 = this->originDelta[1];
  *rot = *idQuat::ToMat3(this: &v9, result: (idMat3 *)v3);
  v6 = v3->deltaTranslation[0];
  trans->x = v3->deltaTranslation[0];
  v7 = v3->deltaTranslation[1];
  trans->y = v3->deltaTranslation[1];
  v8 = v3->deltaTranslation[2];
  trans->z = v3->deltaTranslation[2];
  trans->x = this->g.scale.x * (float)v6;
  trans->y = this->g.scale.y * (float)v7;
  trans->z = this->g.scale.z * (float)v8;
}


// ========================================================================
// ?GetTotalOriginTransform@idTreeAnimator@@QBAXAAVidQuat@@AAVidVec3@@@Z
// EA  : 0x8285F0E8
// RVA : 0x0085F0E8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::GetTotalOriginTransform(idTreeAnimator *this, idQuat *rot, idVec3 *trans)
{
  idQuat *v3; // r11
  double x; // fp4
  double y; // fp7
  double z; // fp6

  v3 = (idQuat *)this->originDelta[1];
  *rot = v3[3];
  x = v3[5].x;
  trans->x = v3[5].x;
  y = v3[5].y;
  trans->y = v3[5].y;
  z = v3[5].z;
  trans->z = v3[5].z;
  trans->x = this->g.scale.x * (float)x;
  trans->y = this->g.scale.y * (float)y;
  trans->z = this->g.scale.z * (float)z;
}


// ========================================================================
// ?GetVisualOffset@idTreeAnimator@@QBAABVidVec3@@XZ
// EA  : 0x8285F158
// RVA : 0x0085F158
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idMD6Blend::configInfo_t *__fastcall idTreeAnimator::GetVisualOffset(idTreeAnimator *this)
{
  return this->decl->config;
}


// ========================================================================
// ?SetKitSkin@idTreeAnimator@@QAAXPBD@Z
// EA  : 0x8285F168
// RVA : 0x0085F168
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetKitSkin(idTreeAnimator *this, const char *skin)
{
  idDeclSkins *v4; // r3
  int v5; // r3

  v4 = this->GetSkins(this);
  if ( v4 != nullptr && skin != nullptr )
  {
    v5 = idDeclSkins::IndexForSkin(this: v4, name: skin);
    if ( v5 >= 0 )
      this->g.customSkin = v5;
  }
}


// ========================================================================
// ?GetBlendedUserChannel@idTreeAnimator@@QBAMV?$idIndex@FW4invalidUserChannelIndex_t@@@@@Z
// EA  : 0x8285F1D0
// RVA : 0x0085F1D0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

float __fastcall idTreeAnimator::GetBlendedUserChannel(
        idTreeAnimator *this,
        idIndex<short,enum invalidUserChannelIndex_t> *index)
{
  char *v2; // r11
  double v3; // fp1

  if ( (__int16)index < 0
    || (v2 = (char *)this + ((16 * this->currentDeferred) ^ 0x10), (__int16)index >= *((_DWORD *)v2 + 531)) )
  {
    idLib::Warning(fmt: "idTreeAnimator::GetBlendedUserChannel index out of range");
    v3 = 0.0;
  }
  else
  {
    v3 = *(float *)(*((_DWORD *)v2 + 530) + 4 * (__int16)index);
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?FreeSurfaces@idTreeAnimator@@EAAXXZ
// EA  : 0x8285F2B0
// RVA : 0x0085F2B0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::FreeSurfaces(idTreeAnimator *this)
{
  int v2; // r28
  int v3; // r29
  idRenderModelSurface *v4; // r11
  idJointBuffer *joints; // r30
  idRenderModelSurface *list; // r4

  v2 = 0;
  if ( this->surfaces.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->surfaces.list[v3];
      joints = v4->joints;
      if ( joints != nullptr )
      {
        idJointBuffer::~idJointBuffer(this: v4->joints);
        idMem::Free(this: &mem, ptr: joints, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->surfaces.num );
  }
  if ( this->surfaces.listStatic == 0 || this->surfaces.listStatic == 2 )
  {
    list = this->surfaces.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->surfaces.list = nullptr;
    this->surfaces.size = 0;
  }
  this->surfaces.num = 0;
}


// ========================================================================
// ?FreeMorphMaps@idTreeAnimator@@AAAXXZ
// EA  : 0x8285F360
// RVA : 0x0085F360
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::FreeMorphMaps(idTreeAnimator *this)
{
  int v2; // r27
  int v3; // r30
  idTreeAnimator::morphMap_t *list; // r11
  idVertexBuffer *v5; // r29
  idTreeAnimator::morphMap_t *v6; // r11
  idVertexBuffer *v7; // r29
  idTreeAnimator::morphMap_t *v8; // r4

  v2 = 0;
  if ( this->morphMaps.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->morphMaps.list[v3].map, align: ALIGN_16);
      list = this->morphMaps.list;
      v5 = list[v3].buffers.ptr[0];
      if ( v5 != nullptr )
      {
        idVertexBuffer::~idVertexBuffer(this: list[v3].buffers.ptr[0]);
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
      v6 = &this->morphMaps.list[v3];
      v7 = v6->buffers.ptr[1];
      if ( v7 != nullptr )
      {
        idVertexBuffer::~idVertexBuffer(this: v6->buffers.ptr[1]);
        idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->morphMaps.num );
  }
  if ( this->morphMaps.listStatic == 0 || this->morphMaps.listStatic == 2 )
  {
    v8 = this->morphMaps.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->morphMaps.list = nullptr;
    this->morphMaps.size = 0;
  }
  this->morphMaps.num = 0;
}


// ========================================================================
// ?GetModelSpaceTagTransform@idTreeAnimator@@QBA_NABUtagData_t@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x8285F450
// RVA : 0x0085F450
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetModelSpaceTagTransform(
        idTreeAnimator *this,
        const tagData_t *tagData,
        idVec3 *origin,
        idMat3 *axis)
{
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r5
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r4
  idMD6Skel *JointIndex; // r3
  const idIndex<short,enum invalidJointIndex_t> *v13; // r4
  idMD6Skel var30; // [sp+50h] [-30h] BYREF

  p_parentJoint = &tagData->parentJoint;
  if ( tagData->parentJoint.value == 0xFFFF )
    return 0;
  model = this->decl->model;
  if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: &var30, result: skeleton, handle: p_parentJoint);
  }
  else
  {
    JointIndex = &var30;
    HIWORD(var30.__vftable) = -1;
  }
  v13 = (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(JointIndex->__vftable);
  if ( (__int16)v13 < 0 )
    return 0;
  else
    return idTreeAnimator::GetModelSpaceAttachmentTransform(
             this,
             jointIndex: v13,
             translationOffset: &tagData->trans,
             rotationOffset: (idMat3 *)&tagData->rot,
             origin,
             axis);
}


// ========================================================================
// ?GetWorldSpaceTagTransform@idTreeAnimator@@QBA_NABUtagData_t@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x8285F4F0
// RVA : 0x0085F4F0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetWorldSpaceTagTransform(
        idTreeAnimator *this,
        const tagData_t *tagData,
        idVec3 *origin,
        idMat3 *axis)
{
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r5
  idIndex<short,enum invalidJointIndex_t> *decl; // r4
  unsigned __int16 v11; // [sp+50h] [-30h] BYREF

  p_parentJoint = &tagData->parentJoint;
  if ( tagData->parentJoint.value == 0xFFFF )
    return 0;
  decl = (idIndex<short,enum invalidJointIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclMD6::GetJointIndex(this: (idDeclMD6 *)&v11, result: decl, handle: p_parentJoint);
  if ( (v11 & 0x8000u) != 0 )
    return 0;
  else
    return idTreeAnimator::GetWorldSpaceAttachmentTransform(
             this,
             jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v11,
             translationOffset: &tagData->trans,
             rotationOffset: (idMat3 *)&tagData->rot,
             origin,
             axis);
}


// ========================================================================
// ?GetSingleAnimFrame@idTreeAnimator@@QBAPBVidMD6Anim@@PAVidJointMat@@ABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@HABVidVec3@@_N@Z
// EA  : 0x8285F570
// RVA : 0x0085F570
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idMD6Anim *__fastcall idTreeAnimator::GetSingleAnimFrame(
        idTreeAnimator *this,
        idJointMat *joints,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *animAlias,
        int time,
        const idVec3 *offset,
        bool removeOriginOffset)
{
  const idMD6Alias *Alias; // r3
  const idMD6Anim *Existing; // r30
  const idMD6Anim *result; // r3
  bool JointsForAnimTime; // zf

  if ( animAlias->value == 0xFFFF )
    return nullptr;
  Alias = idDeclMD6::FindAlias(this: this->decl, aliasHandle: animAlias, includeInherited: true);
  Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                  this: &idMD6Anim::resourceList,
                                  name: (char *)Alias->animRefs.list->str,
                                  skipStaleCheck: false);
  if ( Existing == nullptr )
    return nullptr;
  JointsForAnimTime = idDeclMD6::GetJointsForAnimTime(
                        this: this->decl,
                        joints,
                        anim: Existing,
                        timeMS: time,
                        offset,
                        removeOriginOffset);
  result = Existing;
  if ( !JointsForAnimTime )
    return nullptr;
  return result;
}


// ========================================================================
// ?LookupAnimByAlias@idTreeAnimator@@SAPBVidMD6Anim@@PBVidDeclMD6@@PBD@Z
// EA  : 0x8285F610
// RVA : 0x0085F610
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idMD6Anim *__fastcall idTreeAnimator::LookupAnimByAlias(const idDeclMD6 *md6Decl, char *animName)
{
  const idMD6Alias *Alias; // r3
  const idMD6Alias *v5; // r31
  const idMD6Anim *result; // r3
  const char *v7; // r4
  unsigned __int16 value; // [sp+50h] [-30h] BYREF

  Alias = idDeclMD6::FindAlias(this: md6Decl, aliasName: animName, includeInherited: true);
  v5 = Alias;
  if ( Alias != nullptr )
  {
    value = Alias->aliasHandle.value;
    animation->StrongLoadAlias_2(
      this: animation,
      a2: md6Decl,
      a3: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&value);
    result = (const idMD6Anim *)idResourceList::FindExisting(
                                  this: &idMD6Anim::resourceList,
                                  name: (char *)v5->animRefs.list->str,
                                  skipStaleCheck: true);
  }
  else
  {
    result = (const idMD6Anim *)idResourceList::Load(
                                  this: &idMD6Anim::resourceList,
                                  name: animName,
                                  makeDefault: true,
                                  skipStaleCheck: false);
  }
  if ( result == nullptr )
  {
    if ( animName != nullptr )
      v7 = animName;
    else
      v7 = "n/a";
    idLib::Warning(fmt: "Invalid animation name '%s' for LookupAnimByAlias()!", v7);
    return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetSkins@idTreeAnimator@@UBAPBVidDeclSkins@@XZ
// EA  : 0x8285F6D8
// RVA : 0x0085F6D8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idDeclSkins *__fastcall idTreeAnimator::GetSkins(idTreeAnimator *this)
{
  const idMD6Model *model; // r11
  const idDecl *v3; // r30
  idStr v4; // [sp+50h] [-40h] BYREF

  model = this->decl->model;
  if ( model == nullptr )
    return nullptr;
  idStr::idStr(this: &v4, text: model->name.str);
  idStr::StripFileExtension(this: &v4);
  if ( v4.data != nullptr )
    v3 = idDeclInfo::FindWithInheritance(this: &idDeclSkins::resourceList, name: v4.data, makeDefault: false);
  else
    v3 = nullptr;
  idStr::FreeData(this: &v4);
  return (const idDeclSkins *)v3;
}


// ========================================================================
// __unwind$243033
// EA  : 0x8285F768
// RVA : 0x0085F768
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_243033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetMeshIndex@idTreeAnimator@@QBAHPBD@Z
// EA  : 0x8285F790
// RVA : 0x0085F790
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::GetMeshIndex(idTreeAnimator *this, const char *meshName)
{
  const idMD6Model *model; // r30
  int v4; // r29
  int i; // r31

  model = this->decl->model;
  if ( model == nullptr )
    return -1;
  v4 = 0;
  if ( model->meshes.num <= 0 )
    return -1;
  for ( i = 0; idStr::Icmp(s1: model->meshes.list[i]->name.data, s2: meshName) != 0; ++i )
  {
    if ( ++v4 >= model->meshes.num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?GetJointIndex@idTreeAnimator@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@PBD@Z
// EA  : 0x8285F810
// RVA : 0x0085F810
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::GetJointIndex(
        idTreeAnimator *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const char *jointName)
{
  int v4; // r11
  idIndex<short,enum invalidJointIndex_t> *v5; // r4
  idMD6Skel *JointIndex; // r3
  _WORD v8[8]; // [sp+50h] [-20h] BYREF

  v4 = *(_DWORD *)(*(_DWORD *)&result[1016].value + 60);
  if ( v4 != 0 && (v5 = *(idIndex<short,enum invalidJointIndex_t> **)(v4 + 212)) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: (idMD6Skel *)v8, result: v5, name: jointName);
  }
  else
  {
    JointIndex = (idMD6Skel *)v8;
    v8[0] = -1;
  }
  HIWORD(this->__vftable) = HIWORD(JointIndex->__vftable);
  return this;
}


// ========================================================================
// ?GetJointIndex@idTreeAnimator@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@ABV?$idHandle@GW4invalidJointHandle_t@@$0PPPP@@@@Z
// EA  : 0x8285F878
// RVA : 0x0085F878
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::GetJointIndex(
        idTreeAnimator *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const idHandle<unsigned short,enum invalidJointHandle_t,65535> *jointHandle)
{
  int v4; // r11
  idIndex<short,enum invalidJointIndex_t> *v5; // r4
  idMD6Skel *JointIndex; // r3
  _WORD v8[8]; // [sp+50h] [-20h] BYREF

  v4 = *(_DWORD *)(*(_DWORD *)&result[1016].value + 60);
  if ( v4 != 0 && (v5 = *(idIndex<short,enum invalidJointIndex_t> **)(v4 + 212)) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: (idMD6Skel *)v8, result: v5, handle: jointHandle);
  }
  else
  {
    JointIndex = (idMD6Skel *)v8;
    v8[0] = -1;
  }
  HIWORD(this->__vftable) = HIWORD(JointIndex->__vftable);
  return this;
}


// ========================================================================
// ?ApplyOriginDeltas@idTreeAnimator@@QBAXABVidMat3@@ABVidVec3@@AAV2@AAV3@1@Z
// EA  : 0x8285F8E0
// RVA : 0x0085F8E0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::ApplyOriginDeltas(
        idTreeAnimator *this,
        const idMat3 *axis,
        const idVec3 *origin,
        idMat3 *outAxis,
        idVec3 *outOrigin,
        const idVec3 *extraScale)
{
  md6OriginDelta_t *v6; // r30
  idMat3 *v13; // r3
  idMat3 *v14; // r3
  double v15; // fp11
  double z; // fp8
  double v17; // fp6
  double v18; // fp13
  double y; // fp10
  double v20; // fp12
  double v21; // fp8
  idVec3 v22; // [sp+50h] [-C0h] BYREF
  idQuat v23; // [sp+60h] [-B0h] BYREF
  idQuat v24; // [sp+70h] [-A0h] BYREF
  idMat3 v25[3]; // [sp+A0h] [-70h] BYREF

  v6 = this->originDelta[1];
  v13 = (idMat3 *)idQuat::Inverse(this: &v23, result: (idQuat *)v6);
  v14 = idQuat::ToMat3(this: &v24, result: v13);
  *outAxis = *idMat3::operator*(this: v25, result: v14, a: axis);
  idMat3::OrthoNormalizeSelf(this: outAxis);
  v15 = (float)(this->g.scale.z * v6->deltaTranslation[2]);
  z = extraScale->z;
  v17 = (float)((float)(this->g.scale.y * v6->deltaTranslation[1]) * extraScale->y);
  v22.x = (float)(this->g.scale.x * extraScale->x) * v6->deltaTranslation[0];
  v22.y = v17;
  v22.z = (float)v15 * (float)z;
  idQuat::operator*(this: &v23, result: (idVec3 *)v6->animRotation, a: &v22);
  v18 = (float)((float)(outAxis->mat[0].y * v23.x)
              + (float)((float)(outAxis->mat[1].y * v23.y) + (float)(outAxis->mat[2].y * v23.z)));
  y = origin->y;
  v20 = (float)((float)(v23.x * outAxis->mat[0].z)
              + (float)((float)(outAxis->mat[1].z * v23.y) + (float)(outAxis->mat[2].z * v23.z)));
  v21 = origin->z;
  outOrigin->x = origin->x
               + (float)((float)(outAxis->mat[2].x * v23.z)
                       + (float)((float)(outAxis->mat[0].x * v23.x) + (float)(outAxis->mat[1].x * v23.y)));
  outOrigin->y = (float)y + (float)v18;
  outOrigin->z = (float)v21 + (float)v20;
}


// ========================================================================
// ?ApplyOriginDeltas@idTreeAnimator@@QBAXABVidQuat@@ABVidVec3@@AAV2@AAV3@1@Z
// EA  : 0x8285FA68
// RVA : 0x0085FA68
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::ApplyOriginDeltas(
        idTreeAnimator *this,
        const idQuat *axis,
        const idVec3 *origin,
        idVec3 *outAxis,
        idVec3 *outOrigin,
        const idVec3 *extraScale)
{
  md6OriginDelta_t *v6; // r31
  idQuat *v13; // r3
  double z; // fp8
  double y; // fp10
  double x; // fp6
  double v17; // fp9
  double v18; // fp4
  double v19; // fp3
  double v20; // fp5
  double v21; // fp2
  double v22; // fp11
  double v23; // fp10
  double v24; // fp1
  double v27; // fp13
  double v28; // fp4
  double v29; // fp0
  double v30; // fp13
  double v31; // fp12
  double v32; // fp10
  double v33; // fp9
  double v34; // fp0
  double v35; // fp13
  idQuat v36; // [sp+50h] [-60h] BYREF
  idQuat v37[5]; // [sp+60h] [-50h] BYREF

  v6 = this->originDelta[1];
  v13 = idQuat::Inverse(this: v37, result: (idQuat *)v6);
  z = v13->z;
  y = axis->y;
  x = v13->x;
  v17 = axis->z;
  v18 = (float)((float)(axis->z * v13->y) + (float)((float)(v13->x * axis->w) + (float)(axis->x * v13->w)));
  v19 = (float)((float)(axis->w * v13->y) + (float)((float)(v13->z * axis->x) + (float)(axis->y * v13->w)));
  v20 = (float)-(float)((float)(axis->y * v13->y) - (float)((float)(axis->w * v13->w) - (float)(v13->x * axis->x)));
  v21 = (float)-(float)((float)(axis->x * v13->y)
                      - (float)((float)(v13->w * axis->z)
                              + (float)((float)(axis->y * v13->x) + (float)(v13->z * axis->w))));
  outAxis->z = -(float)((float)(axis->x * v13->y)
                      - (float)((float)(v13->w * axis->z)
                              + (float)((float)(axis->y * v13->x) + (float)(v13->z * axis->w))));
  v22 = (float)-(float)((float)((float)y * (float)z) - (float)v18);
  outAxis->x = -(float)((float)((float)y * (float)z) - (float)v18);
  v23 = (float)-(float)((float)((float)x * (float)v17) - (float)v19);
  outAxis->y = -(float)((float)((float)x * (float)v17) - (float)v19);
  v24 = (float)-(float)((float)((float)z * (float)v17) - (float)v20);
  outAxis[1].x = -(float)((float)((float)z * (float)v17) - (float)v20);
  _FP5 = (float)((float)((float)((float)v23 * (float)v23)
                       + (float)((float)((float)v22 * (float)v22)
                               + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f5, f6, f13 }
  v27 = __frsqrte(_FP4);
  v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
                                                                                              * (float)0.5))
                                                                              * (float)v27)
                                                                      - (float)1.5)
                                                      * (float)v27)
                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                              + (float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)((float)v24 * (float)v24)
                                                                              + (float)((float)v21 * (float)v21))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v27
                                                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                                                              + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
                                                                                      * (float)0.5))
                                                                      * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v27
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)((float)v24 * (float)v24)
                                                                                      + (float)((float)v21 * (float)v21))))
                                                              * (float)0.5))
                                              * (float)v27)
                                      - (float)1.5)
                      * (float)v27));
  v29 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21)))) * (float)0.5)) * (float)v27) - (float)1.5)
                                                                                      * (float)v27)
                                                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                                                              + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v27 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21)))) * (float)0.5)) * (float)v27)
                                                                                              - (float)1.5)
                                                                              * (float)v27))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v27
                                                                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
                                                                                              * (float)0.5))
                                                                              * (float)v27)
                                                                      - (float)1.5)
                                                      * (float)v27))
                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                      + (float)((float)((float)v22 * (float)v22)
                                                              + (float)((float)((float)v24 * (float)v24)
                                                                      + (float)((float)v21 * (float)v21))))
                                              * (float)0.5))
                              * (float)v28)
                      - (float)1.5);
  v30 = (float)((float)v29
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21)))) * (float)0.5))
                                                                                      * (float)v27)
                                                                              - (float)1.5)
                                                              * (float)v27)
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)((float)v24 * (float)v24)
                                                                                      + (float)((float)v21 * (float)v21))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v27
                                                                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)((float)v24 * (float)v24) + (float)((float)v21 * (float)v21))))
                                                                                              * (float)0.5))
                                                                              * (float)v27)
                                                                      - (float)1.5)
                                                      * (float)v27))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v27
                                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                                              + (float)((float)((float)v22 * (float)v22)
                                                                                      + (float)((float)((float)v24 * (float)v24)
                                                                                              + (float)((float)v21 * (float)v21))))
                                                                      * (float)0.5))
                                                      * (float)v27)
                                              - (float)1.5)
                              * (float)v27)));
  outAxis->x = (float)v22 * (float)v30;
  outAxis->y = (float)v30 * (float)-(float)((float)((float)x * (float)v17) - (float)v19);
  outAxis->z = (float)v21 * (float)v30;
  outAxis[1].x = (float)v24 * (float)v30;
  v31 = extraScale->z;
  v32 = (float)(this->g.scale.z * v6->deltaTranslation[2]);
  v33 = (float)((float)(this->g.scale.y * v6->deltaTranslation[1]) * extraScale->y);
  v36.x = (float)(this->g.scale.x * extraScale->x) * v6->deltaTranslation[0];
  v36.y = v33;
  v36.z = (float)v32 * (float)v31;
  idQuat::operator*(this: v37, result: (idVec3 *)v6->animRotation, a: (const idVec3 *)&v36);
  idQuat::operator*(this: &v36, result: outAxis, a: (const idVec3 *)v37);
  v34 = (float)(origin->y + v36.y);
  v35 = (float)(origin->z + v36.z);
  outOrigin->x = origin->x + v36.x;
  outOrigin->y = v34;
  outOrigin->z = v35;
}


// ========================================================================
// ?ClearMorphPoints@idTreeAnimator@@QAAXXZ
// EA  : 0x8285FC30
// RVA : 0x0085FC30
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::ClearMorphPoints(idTreeAnimator *this)
{
  int v1; // r4
  const idMD6Model *model; // r6
  int v3; // r8
  int v4; // r5
  unsigned __int8 *map; // r10
  int v6; // r11
  idTriangles *tris; // r9
  unsigned __int8 *v8; // r10

  if ( this->morphMaps.num != 0 )
  {
    v1 = 0;
    model = this->decl->model;
    if ( model->meshes.num > 0 )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        map = this->morphMaps.list[v4].map;
        if ( map != nullptr )
        {
          v6 = 0;
          tris = model->meshes.list[v3]->tris;
          if ( tris->numVerts > 0 )
          {
            v8 = map - 1;
            do
            {
              ++v6;
              v8 += 4;
              *v8 = 0;
            }
            while ( v6 < tris->numVerts );
          }
        }
        ++v1;
        ++v4;
        ++v3;
      }
      while ( v1 < model->meshes.num );
    }
    *((_BYTE *)this + 2164) |= 8u;
  }
}


// ========================================================================
// ?BitShiftMorphPoints@idTreeAnimator@@QAAXI@Z
// EA  : 0x8285FCD8
// RVA : 0x0085FCD8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::BitShiftMorphPoints(idTreeAnimator *this, unsigned int bitShift)
{
  int v2; // r5
  const idMD6Model *model; // r6
  int v4; // r8
  int v5; // r7
  unsigned __int8 *map; // r11
  idTriangles *tris; // r9
  int v8; // r10
  unsigned __int8 *v9; // r11
  int v10; // r31
  int v11; // r10
  unsigned __int8 *v12; // r11
  int v13; // r31

  if ( this->morphMaps.num != 0 )
  {
    if ( bitShift != 0 && bitShift <= 2 )
    {
      v2 = 0;
      model = this->decl->model;
      if ( model->meshes.num > 0 )
      {
        v4 = 0;
        v5 = 0;
        do
        {
          map = this->morphMaps.list[v5].map;
          if ( map != nullptr )
          {
            tris = model->meshes.list[v4]->tris;
            if ( bitShift == 1 )
            {
              v8 = 0;
              if ( tris->numVerts > 0 )
              {
                v9 = map - 1;
                do
                {
                  ++v8;
                  v10 = v9[4] >> 1;
                  v9 += 4;
                  *v9 = v10;
                }
                while ( v8 < tris->numVerts );
              }
            }
            else
            {
              v11 = 0;
              if ( tris->numVerts > 0 )
              {
                v12 = map - 1;
                do
                {
                  ++v11;
                  v13 = v12[4] >> 2;
                  v12 += 4;
                  *v12 = v13;
                }
                while ( v11 < tris->numVerts );
              }
            }
          }
          ++v2;
          ++v5;
          ++v4;
        }
        while ( v2 < model->meshes.num );
      }
      *((_BYTE *)this + 2164) |= 8u;
    }
    else
    {
      idLib::Warning(fmt: "idTreeAnimator::BitShiftMorphPoints() - only accepts a or 2 as a parameter.");
    }
  }
}


// ========================================================================
// ?GetFirstChild@idTreeAnimator@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@V2@@Z
// EA  : 0x8285FE10
// RVA : 0x0085FE10
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::GetFirstChild(
        idTreeAnimator *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const idIndex<short,enum invalidJointIndex_t> *parentJoint)
{
  int v3; // r11
  int v4; // r11
  int v5; // r9
  int v6; // r10
  __int16 v7; // r11

  v3 = *(_DWORD *)(*(_DWORD *)&result[1016].value + 60);
  if ( v3 != 0 )
    v4 = *(_DWORD *)(v3 + 212);
  else
    v4 = 0;
  if ( v4 != 0 && (v5 = *(_DWORD *)(v4 + 40), v6 = 0, *(_WORD *)(v5 + 2) != 0) )
  {
    while ( 1 )
    {
      v7 = v6;
      if ( *(__int16 *)(*(unsigned __int16 *)(v5 + 14) + 2 * (__int16)v6 + v5) == (__int16)parentJoint )
        break;
      if ( ++v6 >= *(unsigned __int16 *)(v5 + 2) )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v7 = -1;
  }
  HIWORD(this->__vftable) = v7;
  return this;
}


// ========================================================================
// ?UpdateTree_r@idTreeAnimator@@CAXPBVidMD6Model@@HHPAVidMD6Node@@@Z
// EA  : 0x8285FE88
// RVA : 0x0085FE88
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::UpdateTree_r(
        const idMD6Model *model,
        int timeMSec,
        int ticksPerSec,
        idMD6FusionBranch *node,
        __int64 a5)
{
  int type; // r11
  int v10; // r11
  char v11; // r11
  bool v12; // zf
  idMD6Node *left; // r6

  while ( 1 )
  {
    type = node->type;
    switch ( type )
    {
      case 5:
        HIDWORD(a5) = model->skeleton;
        idMD6FusionBranch::Update(this: node, forceUpdate: false, gameTime: timeMSec, ticksPerSec, skeleton: a5);
        break;
      case 3:
        idMD6BlendBranch::Update(this: node, forceUpdate: false, isSorted: true);
        break;
      case 4:
        idMD6BlendAdditiveBranch::Update(this: (idMD6BlendAdditiveBranch *)node, forceUpdate: false);
        break;
      case 6:
        idMD6BestLeaf::Update(this: (idMD6BestLeaf *)node);
        break;
      default:
        break;
    }
    v10 = node->type;
    if ( node->type == 0 || v10 == 3 || v10 == 4 || (v12 = v10 != 5, v11 = 0, !v12) )
      v11 = 1;
    if ( v11 == 0 )
      break;
    left = node->left;
    if ( left != nullptr )
      idTreeAnimator::UpdateTree_r(model, timeMSec, ticksPerSec, node: left);
    node = (idMD6FusionBranch *)node->right;
  }
}


// ========================================================================
// ?FreeTree_r@idTreeAnimator@@CAXPAVidMD6Allocator@@PAVidMD6Node@@@Z
// EA  : 0x8285FF78
// RVA : 0x0085FF78
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::FreeTree_r(idMD6Allocator *allocator, idMD6Node *node)
{
  int type; // r11
  char v5; // r11
  bool v6; // zf

  if ( node != nullptr )
  {
    type = node->type;
    if ( node->type == 0 || type == 3 || type == 4 || (v6 = type != 5, v5 = 0, !v6) )
      v5 = 1;
    if ( v5 != 0 )
    {
      idTreeAnimator::FreeTree_r(allocator, node: *(idMD6Node **)&node[4].type);
      idTreeAnimator::FreeTree_r(allocator, node: *(idMD6Node **)&node[8].type);
    }
    if ( allocator != nullptr )
      allocator->Free(this: allocator, a2: node);
    else
      idMem::Free(this: &mem, ptr: node, align: ALIGN_16);
  }
}


// ========================================================================
// ?ShowKit@idTreeAnimator@@QAA?AVidStr@@W4meshKitComponents_t@@PBD@Z
// EA  : 0x82860038
// RVA : 0x00860038
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::ShowKit(
        idTreeAnimator *this,
        idStr *result,
        meshKitComponents_t kitType,
        const char *name)
{
  int v7; // r11
  int v8; // r31
  __int32 v9; // r27
  __int32 v10; // r29
  int v11; // r30
  int v12; // r10
  int v13; // r11
  int v15; // r11
  int v16; // r10
  int v17; // r9
  int v18; // r5

  if ( name == nullptr )
    goto LABEL_7;
  if ( *name == 0 )
    goto LABEL_7;
  v7 = *(_DWORD *)&result[63].baseBuffer[4];
  v8 = 0;
  v9 = 16 * (kitType + 33);
  if ( *(int *)(v9 + v7) <= 0 )
    goto LABEL_7;
  v10 = 16 * kitType;
  v11 = 0;
  v12 = 16 * kitType + v7;
  while ( idStr::Icmp(s1: *(const char **)(*(_DWORD *)(v12 + 524) + v11 + 4), s2: name) != 0 )
  {
    v13 = *(_DWORD *)&result[63].baseBuffer[4];
    ++v8;
    v11 += 48;
    v12 = v10 + v13;
    if ( v8 >= *(_DWORD *)(v9 + v13) )
      goto LABEL_7;
  }
  if ( v8 >= 0 )
  {
    v15 = 0;
    v16 = *(_DWORD *)(*(_DWORD *)&result[63].baseBuffer[4] + v10 + 524) + 48 * v8;
    if ( *(int *)(v16 + 36) > 0 )
    {
      v17 = 0;
      do
      {
        ++v15;
        v18 = *(_DWORD *)(*(_DWORD *)(v16 + 32) + v17);
        v17 += 4;
        *(_BYTE *)(v18 + *(_DWORD *)&result[63].baseBuffer[8]) = 1;
      }
      while ( v15 < *(_DWORD *)(v16 + 36) );
    }
    idStr::idStr((idStr *)this, text: name);
    return this;
  }
  else
  {
LABEL_7:
    idStr::idStr((idStr *)this, text: &byte_8200D768);
    return this;
  }
}


// ========================================================================
// ?HideKit@idTreeAnimator@@QAAXW4meshKitComponents_t@@PBD@Z
// EA  : 0x82860178
// RVA : 0x00860178
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::HideKit(idTreeAnimator *this, meshKitComponents_t kitType, const char *name)
{
  const idDeclMD6 *decl; // r11
  __int32 v4; // r25
  int v7; // r28
  __int32 v8; // r26
  int v9; // r29
  char *v10; // r10
  int v11; // r31
  int v12; // r10
  int v13; // r11
  int v14; // r7
  const idDeclMD6 *v15; // r11

  decl = this->decl;
  v4 = 16 * (kitType + 33);
  v7 = 0;
  if ( *(int *)((char *)&decl->__vftable + v4) > 0 )
  {
    v8 = 16 * kitType;
    v9 = 0;
    v10 = (char *)decl + 16 * kitType;
    do
    {
      v11 = *((_DWORD *)v10 + 131) + v9;
      if ( idStr::Icmp(s1: *(const char **)(v11 + 4), s2: name) == 0 )
      {
        v12 = 0;
        if ( *(int *)(v11 + 36) > 0 )
        {
          v13 = 0;
          do
          {
            ++v12;
            v14 = *(_DWORD *)(v13 + *(_DWORD *)(v11 + 32));
            v13 += 4;
            this->meshVisibility.list[v14] = false;
          }
          while ( v12 < *(_DWORD *)(v11 + 36) );
        }
      }
      v15 = this->decl;
      ++v7;
      v9 += 48;
      v10 = (char *)v15 + v8;
    }
    while ( v7 < *(int *)((char *)&v15->__vftable + v4) );
  }
}


// ========================================================================
// ?HideKitsExcept@idTreeAnimator@@QAAXW4meshKitComponents_t@@PBD@Z
// EA  : 0x82860230
// RVA : 0x00860230
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::HideKitsExcept(idTreeAnimator *this, meshKitComponents_t kitType, const char *name)
{
  int v6; // r23
  const idDeclMD6 *decl; // r11
  int v8; // r30
  __int32 v9; // r27
  __int32 v10; // r29
  int v11; // r31
  char *v12; // r10
  const idDeclMD6 *v13; // r11
  const idDeclMD6 *v14; // r10
  int v15; // r7
  __int32 v16; // r6
  int v17; // r8
  int v18; // r11
  idPair<idStr,idList<int,19> > *v19; // r10
  int v20; // r9
  int v21; // r3
  int v22; // r11
  int v23; // r10
  int v24; // r9
  int v25; // r5

  v6 = -1;
  if ( name != nullptr && *name != 0 )
  {
    decl = this->decl;
    v8 = 0;
    v9 = 16 * (kitType + 33);
    if ( *(int *)((char *)&decl->__vftable + v9) > 0 )
    {
      v10 = 16 * kitType;
      v11 = 0;
      v12 = (char *)decl + 16 * kitType;
      while ( idStr::Icmp(s1: *(const char **)(*((_DWORD *)v12 + 131) + v11 + 4), s2: name) != 0 )
      {
        v13 = this->decl;
        ++v8;
        v11 += 48;
        v12 = (char *)v13 + v10;
        if ( v8 >= *(int *)((char *)&v13->__vftable + v9) )
          goto LABEL_9;
      }
      v6 = v8;
    }
  }
LABEL_9:
  v14 = this->decl;
  v15 = 0;
  v16 = 16 * (kitType + 33);
  if ( *(int *)((char *)&v14->__vftable + v16) > 0 )
  {
    v17 = 0;
    do
    {
      if ( v15 != v6 )
      {
        v18 = 0;
        v19 = &v14->meshKitGroups[kitType].list[v17];
        if ( v19->second.num > 0 )
        {
          v20 = 0;
          do
          {
            ++v18;
            v21 = v19->second.list[v20++];
            this->meshVisibility.list[v21] = false;
          }
          while ( v18 < v19->second.num );
        }
      }
      v14 = this->decl;
      ++v15;
      ++v17;
    }
    while ( v15 < *(int *)((char *)&v14->__vftable + v16) );
  }
  if ( v6 != -1 )
  {
    v22 = 0;
    v23 = (int)&v14->meshKitGroups[kitType].list[v6];
    if ( *(int *)(v23 + 36) > 0 )
    {
      v24 = 0;
      do
      {
        ++v22;
        v25 = *(_DWORD *)(*(_DWORD *)(v23 + 32) + v24);
        v24 += 4;
        this->meshVisibility.list[v25] = true;
      }
      while ( v22 < *(_DWORD *)(v23 + 36) );
    }
  }
}


// ========================================================================
// ?HideAllKits@idTreeAnimator@@QAAXW4meshKitComponents_t@@@Z
// EA  : 0x828603C0
// RVA : 0x008603C0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::HideAllKits(idTreeAnimator *this, meshKitComponents_t kitType)
{
  const idDeclMD6 *decl; // r11
  __int32 v3; // r31
  int v4; // r7
  __int32 v5; // r5
  int v6; // r8
  char *v7; // r10
  int v8; // r11
  int v9; // r9
  int v10; // r10
  int v11; // r4
  const idDeclMD6 *v12; // r11

  decl = this->decl;
  v3 = 16 * (kitType + 33);
  v4 = 0;
  if ( *(int *)((char *)&decl->__vftable + v3) > 0 )
  {
    v5 = 16 * kitType;
    v6 = 0;
    v7 = (char *)decl + 16 * kitType;
    do
    {
      v8 = 0;
      v9 = *((_DWORD *)v7 + 131) + v6;
      if ( *(int *)(v9 + 36) > 0 )
      {
        v10 = 0;
        do
        {
          ++v8;
          v11 = *(_DWORD *)(v10 + *(_DWORD *)(v9 + 32));
          v10 += 4;
          this->meshVisibility.list[v11] = false;
        }
        while ( v8 < *(_DWORD *)(v9 + 36) );
      }
      v12 = this->decl;
      ++v4;
      v6 += 48;
      v7 = (char *)v12 + v5;
    }
    while ( v4 < *(int *)((char *)&v12->__vftable + v3) );
  }
}


// ========================================================================
// SerializeJointMods
// EA  : 0x82860520
// RVA : 0x00860520
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall SerializeJointMods(idSerializer *ser, idMD6Blend::jointMod_t *jointMods, int numMods)
{
  idIndex<short,enum invalidJointIndex_t> *p_joint; // r31
  int v5; // r26
  int v6; // r27
  int value; // r11
  unsigned __int16 Bits; // r29
  idBitMsg *msg; // r3
  idIndex<short,enum invalidJointIndex_t> *v10; // r11
  int v11; // r29
  idBitMsg *v12; // r3
  __int64 v13; // r8
  idBitMsg *v14; // r3
  idBitMsg *v15; // r3
  idBitMsg *v16; // r3
  double v17; // fp13
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp9
  double v22; // fp8
  double v23; // fp7
  double v24; // fp6
  double w; // fp13
  double v26; // fp12
  double v27; // fp9
  double z; // fp8
  double v29; // fp7
  double v30; // fp6
  unsigned __int16 v31; // [sp+50h] [-70h] BYREF
  int v32; // [sp+54h] [-6Ch]
  idQuat v33; // [sp+60h] [-60h] BYREF
  float v34; // [sp+70h] [-50h]
  float v35; // [sp+74h] [-4Ch]
  float v36; // [sp+78h] [-48h]
  float v37; // [sp+7Ch] [-44h]
  float v38; // [sp+80h] [-40h]

  if ( numMods > 0 )
  {
    p_joint = &jointMods->joint;
    v5 = numMods;
    v6 = 32 - _cntlzw(0xFFu);
    do
    {
      value = p_joint->value;
      if ( value == NULL_JOINT_INDEX.value )
        LOWORD(value) = -1;
      Bits = value;
      msg = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: msg, (unsigned __int16)value, numBits: 16);
      else
        Bits = idBitMsg::ReadBits(this: msg, numBits: 16);
      if ( Bits == 0xFFFF )
      {
        v10 = &NULL_JOINT_INDEX;
      }
      else
      {
        v31 = Bits;
        v10 = (idIndex<short,enum invalidJointIndex_t> *)&v31;
      }
      v11 = (unsigned __int16)p_joint[1].value;
      p_joint->value = v10->value;
      v12 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v12, value: v11, numBits: v6);
      else
        LOWORD(v11) = idBitMsg::ReadBits(this: v12, numBits: v6);
      p_joint[1].value = v11;
      if ( (v11 & 4) != 0 )
      {
        idSerializer::SerializeUQ<255,8>(this: ser, value: (float *)&p_joint[-6].value);
        idSerializer::SerializeUQ<255,8>(this: ser, value: (float *)&p_joint[-4].value);
        idSerializer::SerializeUQ<255,8>(this: ser, value: (float *)&p_joint[-2].value);
      }
      if ( (p_joint[1].value & 8) != 0 )
      {
        v14 = ser->msg;
        if ( ser->writing )
        {
          v32 = *(int *)&p_joint[-24].value;
          idBitMsg::WriteBits(this: v14, value: v32, numBits: 32);
        }
        else
        {
          *(_DWORD *)&p_joint[-24].value = idBitMsg::ReadBits(this: v14, numBits: 32);
        }
        v15 = ser->msg;
        if ( ser->writing )
        {
          v32 = *(int *)&p_joint[-16].value;
          idBitMsg::WriteBits(this: v15, value: v32, numBits: 32);
        }
        else
        {
          *(_DWORD *)&p_joint[-16].value = idBitMsg::ReadBits(this: v15, numBits: 32);
        }
        v16 = ser->msg;
        if ( ser->writing )
        {
          v32 = *(int *)&p_joint[-8].value;
          idBitMsg::WriteBits(this: v16, value: v32, numBits: 32);
        }
        else
        {
          *(_DWORD *)&p_joint[-8].value = idBitMsg::ReadBits(this: v16, numBits: 32);
        }
      }
      if ( (p_joint[1].value & 2) != 0 )
      {
        if ( ser->writing )
        {
          v17 = *(float *)&p_joint[-28].value;
          v18 = *(float *)&p_joint[-26].value;
          v19 = *(float *)&p_joint[-22].value;
          v20 = *(float *)&p_joint[-20].value;
          v21 = *(float *)&p_joint[-18].value;
          v22 = *(float *)&p_joint[-14].value;
          v23 = *(float *)&p_joint[-12].value;
          v24 = *(float *)&p_joint[-10].value;
          v33.x = *(float *)&p_joint[-30].value;
          v33.w = v17;
          v36 = v18;
          v33.y = v19;
          v34 = v20;
          v37 = v21;
          v33.z = v22;
          v35 = v23;
          v38 = v24;
        }
        idSerializer::SerializeQ(this: ser, axis: &v33, bits: 15, a4: v13);
        if ( !ser->writing )
        {
          w = v33.w;
          v26 = v36;
          *(float *)&p_joint[-30].value = v33.x;
          *(float *)&p_joint[-28].value = w;
          *(float *)&p_joint[-26].value = v26;
          *(float *)&p_joint[-22].value = v33.y;
          v27 = v37;
          *(float *)&p_joint[-20].value = v34;
          z = v33.z;
          *(float *)&p_joint[-18].value = v27;
          v29 = v35;
          *(float *)&p_joint[-14].value = z;
          v30 = v38;
          *(float *)&p_joint[-12].value = v29;
          *(float *)&p_joint[-10].value = v30;
        }
      }
      --v5;
      p_joint += 32;
    }
    while ( v5 != 0 );
  }
}


// ========================================================================
// ?GetSingleAnimFrame@idTreeAnimator@@QBAPBVidMD6Anim@@PAVidJointMat@@PBDHABVidVec3@@_N@Z
// EA  : 0x828607B8
// RVA : 0x008607B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

const idMD6Anim *__fastcall idTreeAnimator::GetSingleAnimFrame(
        idTreeAnimator *this,
        idJointMat *joints,
        char *animName,
        int time,
        const idVec3 *offset,
        bool removeOriginOffset)
{
  const idMD6Anim *v11; // r31
  const idMD6Anim *result; // r3
  bool JointsForAnimTime; // zf

  v11 = idTreeAnimator::LookupAnimByAlias(md6Decl: this->decl, animName);
  if ( v11 == nullptr )
    return nullptr;
  JointsForAnimTime = idDeclMD6::GetJointsForAnimTime(
                        this: this->decl,
                        joints,
                        anim: v11,
                        timeMS: time,
                        offset,
                        removeOriginOffset);
  result = v11;
  if ( !JointsForAnimTime )
    return nullptr;
  return result;
}


// ========================================================================
// ?SetFrameFromAnim@idTreeAnimator@@QAAXPBVidMD6Anim@@H_N1PBVidVec3@@@Z
// EA  : 0x82860828
// RVA : 0x00860828
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetFrameFromAnim(
        idTreeAnimator *this,
        const idMD6Anim *anim,
        int frame,
        bool updateRenderModel,
        bool checkForOriginTranslation,
        const idVec3 *translationScale)
{
  const idDeclMD6 *decl; // r11
  const idMD6Model *model; // r22
  __int64 v12; // r10
  bool v13; // r26
  int v14; // r25
  const idMD6Skel *skeleton; // r28
  idMD6AnimData *animData; // r29
  size_t v17; // r23
  idJointMat *v18; // r9
  const idMD6SkelData *data; // r3
  int v20; // r12
  int currentDeferred; // r11
  __int64 v22; // r8
  char v23; // r27
  const idDeclMD6 *v24; // r10
  __int64 v25; // r8
  const idMD6Skel *v26; // r11
  const float *v27; // r7
  const float *v28; // r6
  _DWORD back_chain[2]; // [sp+0h] [-E0h]
  bool v30; // [sp+Bh] [-D5h]
  float *v31; // [sp+Ch] [-D4h]
  float *v32; // [sp+10h] [-D0h]
  const float *v33; // [sp+14h] [-CCh]
  int v34; // [sp+18h] [-C8h]
  int v35; // [sp+1Ch] [-C4h]
  int v36; // [sp+20h] [-C0h]
  int v37; // [sp+24h] [-BCh]
  int v38; // [sp+28h] [-B8h]
  int v39; // [sp+2Ch] [-B4h]
  int v40; // [sp+30h] [-B0h]
  int v41; // [sp+34h] [-ACh]
  int v42; // [sp+38h] [-A8h]
  int v43; // [sp+3Ch] [-A4h]
  int v44; // [sp+40h] [-A0h]
  int v45; // [sp+44h] [-9Ch]
  int v46; // [sp+48h] [-98h]
  int v47; // [sp+4Ch] [-94h]
  int v48; // [sp+50h] [-90h]
  unsigned __int8 v49; // [sp+57h] [-89h]
  int v50; // [sp+58h] [-88h]
  idJointMat *v51; // [sp+5Ch] [-84h]
  int v52; // [sp+60h] [-80h]
  int v53; // [sp+68h] [-78h]
  const idVec3 *v54; // [sp+6Ch] [-74h]
  float v55; // [sp+70h] [-70h] BYREF
  int v56; // [sp+74h] [-6Ch]

  if ( anim != nullptr )
  {
    decl = this->decl;
    if ( decl != nullptr )
    {
      model = decl->model;
      if ( model != nullptr )
      {
        LODWORD(v12) = 960 * frame;
        HIDWORD(v12) = byte_821B0000;
        v13 = false;
        v56 = (int)(float)((float)v12 * (float)0.033333335);
        v14 = v56;
        if ( checkForOriginTranslation )
          v13 = (*((_BYTE *)this + 2164) & 0x40) != 0;
        skeleton = model->skeleton;
        if ( skeleton != nullptr )
        {
          animData = anim->animData;
          v17 = 48 * ((skeleton->data->numJoints + 7) & 0xFFF8);
          if ( !idMD6Anim::AnimIsOkForModel(this: anim, model) )
            idLib::Error(fmt: "Skeleton mismatch: model '%s', anim '%s'", model->name.str, anim->name.str);
          ((void (*)(void))RtlCheckStack12)();
          v18 = this->joints[1];
          data = skeleton->data;
          *(_DWORD *)((char *)back_chain + v20) = back_chain[0];
          currentDeferred = this->currentDeferred;
          v51 = v18;
          if ( translationScale != nullptr )
          {
            v23 = *((_BYTE *)this + 2164);
            v24 = this->decl;
            v54 = translationScale;
            v49 = (_cntlzw(v13) & 0x20) != 0;
            HIDWORD(v25) = v14;
            LODWORD(v25) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            idMD6Blend::DecodeSingleFrameWithOriginDeltaScale(
              skeleton: data,
              temp: &v55,
              tempSize: 0x4000u,
              animData,
              ticksPerSec: v25,
              clearOriginTransform: (v23 & 0x40) != 0,
              originOffset: v24->config->visualOffset,
              offsetAdd: v30,
              outPose: v31,
              outUserChannels: v32,
              originDeltaScale: v33,
              a12: v34,
              a13: v35,
              a14: v36,
              a15: v37,
              a16: v38,
              a17: v39,
              a18: v40,
              a19: v41,
              a20: v42,
              a21: v43,
              a22: v44,
              a23: v45,
              a24: v46,
              a25: v47,
              a26: v48,
              a27: v49,
              a28: v50,
              a29: (int)v18,
              a30: v52,
              a31: *(void **)((char *)&this->userChannels[0].list + ((16 * currentDeferred) ^ 0x10)),
              a32: v53,
              a33: &translationScale->x);
          }
          else
          {
            LODWORD(v22) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
            HIDWORD(v22) = v14;
            idMD6Blend::DecodeSingleFrame(
              skeleton: data,
              temp: &v55,
              tempSize: 0x4000u,
              animData,
              ticksPerSec: v22,
              clearOriginTransform: (*((_BYTE *)this + 2164) & 0x40) != 0,
              originOffset: this->decl->config->visualOffset,
              offsetAdd: v30,
              outPose: v31,
              outUserChannels: v32,
              a11: (int)v33,
              a12: v34,
              a13: v35,
              a14: v36,
              a15: v37,
              a16: v38,
              a17: v39,
              a18: v40,
              a19: v41,
              a20: v42,
              a21: v43,
              a22: v44,
              a23: v45,
              a24: v46,
              a25: v47,
              a26: v48,
              a27: (_cntlzw(v13) & 0x20) != 0,
              a28: v50,
              a29: (int)v18,
              a30: v52,
              a31: *(void **)((char *)&this->userChannels[0].list + ((16 * currentDeferred) ^ 0x10)));
          }
          v26 = model->skeleton;
          if ( v26 != nullptr )
            v27 = (const float *)((char *)&v26->data->size + v26->data->inverseBasePoseQuatOffset);
          else
            v27 = nullptr;
          if ( v26 != nullptr )
            v28 = (const float *)((char *)&v26->data->size + v26->data->inverseBasePoseOffset);
          else
            v28 = nullptr;
          idMD6Blend::TransformModelMatrices(
            skeleton: skeleton->data,
            remap: model->jointRemap.list,
            inMatrices1: this->joints[1]->mat,
            inMatrices2: v28,
            invertedRefPoseQuat: v27,
            outMatrices: this->joints[0]->mat,
            useDualQuat: (*((_BYTE *)this + 2164) & 2) != 0,
            quatTemp: nullptr);
          idJointBuffer::Update(
            this: &this->jointBuffers.ptr[this->nextRenderThreadJointBuffer],
            joints: this->joints[0]->mat,
            numUpdateJoints: v17 / 0x30);
          memcpy(Dst: this->joints[0], Src: this->joints[1], Size: v17);
          this->frameBounds.b[1].z = 0.0;
          this->frameBounds.b[1].y = 0.0;
          this->frameBounds.b[1].x = 0.0;
          this->frameBounds.b[0].z = 0.0;
          this->frameBounds.b[0].y = 0.0;
          this->frameBounds.b[0].x = 0.0;
          idTreeAnimator::CalcFrameBoundsFromJoints(this);
          if ( updateRenderModel )
            ((void (*)(void))this->CommitSubclass)();
        }
      }
    }
  }
}


// ========================================================================
// ?GetFirstChild@idTreeAnimator@@QBA?AV?$idIndex@FW4invalidJointIndex_t@@@@PBD@Z
// EA  : 0x82860AD0
// RVA : 0x00860AD0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::GetFirstChild(
        idTreeAnimator *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        const char *parentName)
{
  unsigned __int16 v6; // [sp+50h] [-20h] BYREF

  idMD6Skel::GetJointIndex(
    this: (idMD6Skel *)&v6,
    result: *(idIndex<short,enum invalidJointIndex_t> **)(*(_DWORD *)(*(_DWORD *)&result[1016].value + 60) + 212),
    name: parentName);
  return idTreeAnimator::GetFirstChild(this, result, parentJoint: (const idIndex<short,enum invalidJointIndex_t> *)v6);
}


// ========================================================================
// ?UpdateTree@idTreeAnimator@@SAXPBVidMD6Model@@HHPAVidMD6Node@@@Z
// EA  : 0x82860B28
// RVA : 0x00860B28
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTreeAnimator::UpdateTree(
        const idMD6Model *model,
        int timeMSec,
        int ticksPerSec,
        idMD6FusionBranch *node,
        __int64 a5)
{
  idTreeAnimator::UpdateTree_r(model, timeMSec, ticksPerSec, node, a5);
}


// ========================================================================
// ?StoreTree_r@idTreeAnimator@@CAXPBVidMD6Model@@HHABVidAnimStack@@PAVidMD6Node@@AAVidBitMsg@@33@Z
// EA  : 0x82860B30
// RVA : 0x00860B30
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::StoreTree_r(
        const idMD6Model *model,
        int timeMSec,
        int ticksPerSec,
        const idAnimStack *animStack,
        __int64 typesMsg,
        idBitMsg *branchMsg,
        idBitMsg *leafMsg)
{
  unsigned __int8 *v11; // r31
  idBitMsg *v12; // r25
  int v15; // r11
  int v16; // r10
  char v17; // r11
  BOOL v18; // r23
  unsigned int v19; // r11
  __int64 v20; // r10
  int v21; // r4
  char v22; // r11
  idAnimRecorder *v23; // r3
  const idMD6Anim *v24; // r29
  unsigned __int16 v25; // r3
  int v26; // r11
  double v27; // fp31
  __int64 v28; // r11
  idSerializer v29; // [sp+50h] [-60h] BYREF

  v11 = (unsigned __int8 *)HIDWORD(typesMsg);
  v12 = (idBitMsg *)typesMsg;
  while ( 1 )
  {
    v15 = *v11;
    switch ( v15 )
    {
      case 5:
        HIDWORD(typesMsg) = model->skeleton;
        idMD6FusionBranch::Update(
          this: (idMD6FusionBranch *)v11,
          forceUpdate: false,
          gameTime: timeMSec,
          ticksPerSec,
          skeleton: typesMsg);
        break;
      case 3:
        idMD6BlendBranch::Update(this: (idMD6BlendBranch *)v11, forceUpdate: false, isSorted: true);
        break;
      case 4:
        idMD6BlendAdditiveBranch::Update(this: (idMD6BlendAdditiveBranch *)v11, forceUpdate: false);
        break;
      case 6:
        idMD6BestLeaf::Update(this: (idMD6BestLeaf *)v11);
        break;
      default:
        break;
    }
    v16 = *v11;
    if ( *v11 == 0 || v16 == 3 || v16 == 4 || (v17 = 0, v16 == 5) )
      v17 = 1;
    if ( v17 == 0 )
      break;
    idBitMsg::WriteBits(this: v12, value: 0, numBits: 2);
    idBitMsg::WriteBits(this: branchMsg, value: v11[20], numBits: 3);
    idBitMsg::WriteBits(this: branchMsg, value: v11[21], numBits: 4);
    v29.msg = (idBitMsg *)(int)(float)(*((float *)v11 + 6) * (float)255.0);
    idBitMsg::WriteBits(this: branchMsg, value: (int)v29.msg, numBits: 8);
    v29.msg = (idBitMsg *)(int)(float)(*((float *)v11 + 7) * (float)255.0);
    idBitMsg::WriteBits(this: branchMsg, value: (int)v29.msg, numBits: 8);
    v29.msg = (idBitMsg *)(int)(float)(*((float *)v11 + 8) * (float)255.0);
    idBitMsg::WriteBits(this: branchMsg, value: (int)v29.msg, numBits: 16);
    idBitMsg::WriteBits(this: branchMsg, value: v11[22], numBits: 8);
    v18 = *((_DWORD *)v11 + 1) != 0;
    idBitMsg::WriteBits(this: branchMsg, value: v18, numBits: 1);
    if ( v18 )
      idTreeAnimator::StoreTree_r(
        model,
        timeMSec,
        ticksPerSec,
        animStack,
        node: *((idMD6Node **)v11 + 1),
        typesMsg: v12,
        branchMsg,
        leafMsg);
    v11 = *((unsigned __int8 **)v11 + 2);
  }
  if ( v16 == 6 )
  {
    v19 = *((_DWORD *)v11 + 2);
    if ( v19 != 0 )
    {
      LODWORD(v20) = *((unsigned __int16 *)v11 + 44);
      HIDWORD(v20) = v19 >> 31;
      v11 = *(unsigned __int8 **)(((4 * (((v20 - (unsigned __int64)v19) >> 32) & (unsigned __int16)v20)) & 0x3FFFC)
                                + *((_DWORD *)v11 + 1));
    }
    else
    {
      v11 = nullptr;
    }
  }
  v21 = *v11;
  if ( v21 == 1 || (v22 = 0, v21 == 2) )
    v22 = 1;
  if ( v22 != 0 )
  {
    idBitMsg::WriteBits(this: v12, value: v21, numBits: 2);
    idBitMsg::WriteBits(this: leafMsg, value: v11[8], numBits: 3);
    idBitMsg::WriteBits(this: leafMsg, value: v11[9], numBits: 1);
    v23 = idAnimRecorder::instance;
    v24 = *((const idMD6Anim **)v11 + 1);
    if ( idAnimRecorder::instance == nullptr )
    {
      v23 = idAnimRecorder::allocFunction();
      idAnimRecorder::instance = v23;
    }
    v25 = idAnimRecorder::AddAnimNetworkID(this: v23, animStack, anim: v24);
    idBitMsg::WriteBits(this: leafMsg, value: v25, numBits: 16);
    v26 = *v11;
    if ( v26 == 2 )
    {
      idBitMsg::WriteBits(this: leafMsg, value: *((_DWORD *)v11 + 3), numBits: 32);
      v29.msg = (idBitMsg *)(int)(float)(idSoundEmitterLocal::GetVolumeAdjustment(this: (bfx::Orienter *)v11)
                                       * (float)255.0);
      idBitMsg::WriteBits(this: leafMsg, value: (int)v29.msg, numBits: 16);
    }
    else if ( v26 == 1 )
    {
      v27 = *((float *)v11 + 13);
      LODWORD(v28) = idMD6Leaf::GetFrameRate(this: (idMD6Leaf *)v11);
      v29.msg = (idBitMsg *)(int)(float)((float)v28 * (float)v27);
      idBitMsg::WriteBits(this: leafMsg, value: (int)v29.msg, numBits: 16);
      idBitMsg::WriteBits(this: leafMsg, value: *((_DWORD *)v11 + 5), numBits: 8);
      idBitMsg::WriteBits(this: leafMsg, value: *((__int16 *)v11 + 24), numBits: 4);
      v29.msg = leafMsg;
      v29.writing = true;
      SerializeJointMods(
        ser: &v29,
        jointMods: *(idMD6Blend::jointMod_t **)&v11[16 * (*((_DWORD *)v11 + 3) & 1) + 16],
        numMods: *((_DWORD *)v11 + 5));
    }
  }
}


// ========================================================================
// ?FreeTree@idTreeAnimator@@SAXPAVidMD6Allocator@@PAVidMD6Node@@@Z
// EA  : 0x82860EC8
// RVA : 0x00860EC8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTreeAnimator::FreeTree(idMD6Allocator *allocator, idMD6Node *node)
{
  idTreeAnimator::FreeTree_r(allocator, node);
}


// ========================================================================
// ?InitializeMorphMaps@idTreeAnimator@@AAAXXZ
// EA  : 0x82860ED8
// RVA : 0x00860ED8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::InitializeMorphMaps(idTreeAnimator *this)
{
  const idMD6Model *model; // r17
  int num; // r29
  idList<idTreeAnimator::morphMap_t,16> *p_morphMaps; // r30
  int size; // r11
  int v6; // r18
  int v7; // r26
  int v8; // r27
  int v9; // r22
  int v10; // r23
  idMD6Mesh *v11; // r29
  idTreeAnimator::morphMap_t *list; // r28
  int i; // r28
  idIndexBuffer *v14; // r3
  idIndexBuffer *v15; // r3
  int v16; // r11
  idTreeAnimator::morphMap_t *v17; // r28
  int j; // r28
  idIndexBuffer *v19; // r3
  idIndexBuffer *v20; // r3
  int v21; // r10

  model = this->decl->model;
  num = model->meshes.num;
  p_morphMaps = &this->morphMaps;
  idTreeAnimator::FreeMorphMaps(this);
  if ( num <= this->morphMaps.size
    || (unsigned __int8)idList<testAlloc_t,5>::Resize(
                          this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&this->morphMaps,
                          newsize: num) != 0 )
  {
    size = this->morphMaps.size;
    if ( num < size )
      size = num;
    this->morphMaps.num = size;
  }
  if ( num > 0 )
  {
    v6 = num;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    do
    {
      p_morphMaps->list[v8].map = nullptr;
      p_morphMaps->list[v10].buffers.ptr[0] = nullptr;
      p_morphMaps->list[v10].buffers.ptr[1] = nullptr;
      v11 = model->meshes.list[v9];
      if ( v11->morphMap.list != nullptr )
      {
        list = p_morphMaps->list;
        list[v8].map = (unsigned __int8 *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(441) : TAG_MORPH",
                                            size: 4 * v11->numVerts,
                                            tag: TAG_MORPH,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
        memcpy(Dst: p_morphMaps->list[v8].map, Src: v11->morphMap.list, Size: 4 * v11->numVerts);
        for ( i = 0; i < 2; ++i )
        {
          v14 = (idIndexBuffer *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x10u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
          if ( v14 != nullptr )
            v15 = idIndexBuffer::idIndexBuffer(this: v14);
          else
            v15 = nullptr;
          v16 = v7 + i;
          p_morphMaps->list->buffers.ptr[v16] = (idVertexBuffer *)v15;
          idVertexBuffer::AllocBufferObject(
            this: p_morphMaps->list->buffers.ptr[v16],
            data: v11->morphMap.list,
            allocSize: 4 * v11->numVerts,
            vertexMask: 4,
            allocUsage: BU_DYNAMIC);
        }
      }
      else if ( this->decl->morphVertices != nullptr )
      {
        v17 = p_morphMaps->list;
        v17[v8].map = (unsigned __int8 *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(449) : TAG_MORPH",
                                           size: 4 * v11->numVerts,
                                           tag: TAG_MORPH,
                                           zeroBuffer: true,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
        for ( j = 0; j < 2; ++j )
        {
          v19 = (idIndexBuffer *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x10u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
          if ( v19 != nullptr )
            v20 = idIndexBuffer::idIndexBuffer(this: v19);
          else
            v20 = nullptr;
          v21 = v7 + j;
          p_morphMaps->list->buffers.ptr[v21] = (idVertexBuffer *)v20;
          idVertexBuffer::AllocBufferObject(
            this: p_morphMaps->list->buffers.ptr[v21],
            data: p_morphMaps->list[v8].map,
            allocSize: 4 * v11->numVerts,
            vertexMask: 4,
            allocUsage: BU_DYNAMIC);
        }
      }
      --v6;
      ++v9;
      ++v8;
      v7 += 3;
      ++v10;
    }
    while ( v6 != 0 );
  }
}


// ========================================================================
// __unwind$246161
// EA  : 0x82861150
// RVA : 0x00861150
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall _unwind_246161(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 80), tag: a2);
}


// ========================================================================
// __unwind$246162
// EA  : 0x82861178
// RVA : 0x00861178
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall _unwind_246162(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 80), tag: a2);
}


// ========================================================================
// ?SetMorphSkin@idTreeAnimator@@QAAXPBDHM@Z
// EA  : 0x828611A0
// RVA : 0x008611A0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetMorphSkin(
        idTreeAnimator *this,
        const char *skinName,
        int skinIndex,
        double morphAmount)
{
  const idDeclSkins *v8; // r3
  const idDeclRenderParm *useSkinBlending; // r30
  idStaticParmBlock<32> *ParmBlock; // r3
  int v11; // r3
  const idDeclRenderParm *v12; // r29
  idStaticParmBlock<32> *v13; // r3
  const idDeclMD6 *decl; // r11
  double v15; // fp30
  double v16; // fp31
  const idDeclRenderParm *v17; // r30
  idStaticParmBlock<32> *v18; // r3
  unsigned __int8 v19; // r11
  int v20; // r6
  unsigned int v21; // r5
  int v22; // r8
  int v23; // r7
  idMD6Mesh *v24; // r9
  int v25; // r11
  unsigned __int8 *v26; // r10
  parmValue_t v27; // [sp+50h] [-50h] BYREF

  if ( skinName == nullptr )
    goto LABEL_12;
  v8 = this->GetSkins(this);
  if ( v8 == nullptr )
  {
    useSkinBlending = rp->useSkinBlending;
    ParmBlock = idRenderModel::GetParmBlock(this);
    idParmBlock::ClearParm(this: ParmBlock, parm: useSkinBlending);
    idLib::Printf(fmt: "no skins defined for model '%s'\n", this->name.str);
    return;
  }
  if ( *skinName != 0 )
  {
    v11 = idDeclSkins::IndexForSkin(this: v8, name: skinName);
  }
  else
  {
    if ( skinIndex < 0 || skinIndex >= v8->skins.num )
      goto LABEL_10;
    v11 = skinIndex;
  }
  if ( v11 == -1 )
  {
LABEL_10:
    this->morphSkin = -1;
    v12 = rp->useSkinBlending;
    v13 = idRenderModel::GetParmBlock(this);
    idParmBlock::ClearParm(this: v13, parm: v12);
    idLib::Error(fmt: "no skin found with name '%s' for model '%s'\n", skinName, this->name.str);
  }
  this->morphSkin = v11;
LABEL_12:
  decl = this->decl;
  this->initialMorphValue = morphAmount;
  if ( this->morphMaps.num != decl->model->meshes.num )
    idTreeAnimator::InitializeMorphMaps(this);
  v15 = 0.0;
  if ( morphAmount > 0.0 )
    v16 = 1.0;
  else
    v16 = 0.0;
  v17 = rp->useSkinBlending;
  v18 = idRenderModel::GetParmBlock(this);
  v27.value[3] = v16;
  v27.value[2] = v16;
  v27.value[1] = v16;
  v27.value[0] = v16;
  idParmBlock::SetParm(this: v18, parm: v17, parmValue: &v27);
  if ( morphAmount >= 0.0 )
  {
    if ( morphAmount <= 1.0 )
      v15 = morphAmount;
    else
      v15 = 1.0;
  }
  v27.swizzle[1] = (int)(float)((float)v15 * (float)255.0);
  v19 = v27.swizzle[1];
  if ( v27.swizzle[1] >= 0 )
  {
    if ( v27.swizzle[1] > 255 )
      v19 = -1;
  }
  else
  {
    v19 = 0;
  }
  v20 = 0;
  v21 = v19 | 0x80808000;
  if ( this->morphMaps.num > 0 )
  {
    v22 = 0;
    v23 = 0;
    do
    {
      v24 = this->decl->model->meshes.list[v23];
      if ( v24->morphMap.list == nullptr )
      {
        v25 = 0;
        if ( v24->numVerts > 0 )
        {
          v26 = this->morphMaps.list[v22].map - 4;
          do
          {
            ++v25;
            v26 += 4;
            *(_DWORD *)v26 = v21;
          }
          while ( v25 < v24->numVerts );
        }
      }
      ++v20;
      ++v23;
      ++v22;
    }
    while ( v20 < this->morphMaps.num );
  }
  *((_BYTE *)this + 2164) |= 8u;
}


// ========================================================================
// ?MorphLocation@idTreeAnimator@@QAAXMH@Z
// EA  : 0x82861408
// RVA : 0x00861408
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::MorphLocation(idTreeAnimator *this, double morphAmount, int morphIndex, int a4)
{
  const idDeclMD6 *decl; // r11
  idMorphVertices *morphVertices; // r10
  idList<idMorphVertices::vertSet,5> *p_morphVertSet; // r29
  const idMD6Model *model; // r22
  const idDeclRenderParm *useSkinBlending; // r31
  idStaticParmBlock<32> *ParmBlock; // r3
  int num; // r7
  int v14; // r21
  int v15; // r23
  int v16; // r30
  idMorphVertices::vertSet *list; // r11
  int *p_meshNum; // r9
  int v19; // r10
  unsigned __int8 *map; // r25
  int v21; // r27
  int numVerts; // r26
  int v23; // r31
  int v24; // r28
  idMorphVertices::vertSet *v25; // r10
  int v26; // r11
  unsigned __int8 *v27; // r11
  char v28; // r10
  parmValue_t v29; // [sp+50h] [-90h] BYREF

  if ( morphAmount > 0.0 )
  {
    decl = this->decl;
    morphVertices = decl->morphVertices;
    if ( morphVertices != nullptr )
    {
      p_morphVertSet = &morphVertices->morphVertSet;
      if ( morphVertices->morphVertSet.num != 0 )
      {
        model = decl->model;
        if ( this->morphMaps.num != model->meshes.num )
          idTreeAnimator::InitializeMorphMaps(this);
        useSkinBlending = rp->useSkinBlending;
        ParmBlock = idRenderModel::GetParmBlock(this);
        v29.value[3] = 1.0;
        v29.value[2] = 1.0;
        v29.value[1] = 1.0;
        v29.value[0] = 1.0;
        idParmBlock::SetParm(this: ParmBlock, parm: useSkinBlending, parmValue: &v29);
        num = p_morphVertSet->num;
        v14 = 0;
        v29.swizzle[1] = (int)(float)((float)morphAmount * (float)255.0);
        v15 = v29.swizzle[1];
        if ( num > 0 )
        {
          v16 = 0;
          do
          {
            list = p_morphVertSet->list;
            p_meshNum = &p_morphVertSet->list[v16].meshNum;
            v19 = *p_meshNum;
            if ( *p_meshNum >= 0 && v19 < model->meshes.num )
            {
              map = this->morphMaps.list[v19].map;
              if ( map != nullptr && p_meshNum[1] == a4 )
              {
                v21 = 0;
                numVerts = model->meshes.list[v19]->numVerts;
                if ( p_meshNum[19] > 0 )
                {
                  v23 = 0;
                  v24 = 0;
                  do
                  {
                    v25 = &list[v16];
                    v26 = list[v16].vertices.list[v24];
                    if ( v26 < numVerts )
                    {
                      v27 = &map[4 * v26];
                      if ( v25->morphDirection.num > 0 )
                      {
                        *v27 = v25->morphDirection.list[v23];
                        v27[1] = p_morphVertSet->list[v16].morphDirection.list[v23 + 1];
                        v27[2] = p_morphVertSet->list[v16].morphDirection.list[v23 + 2];
                      }
                      v28 = v27[3] + v15;
                      if ( (unsigned int)v27[3] + v15 > 0xFF )
                        v28 = -1;
                      v27[3] = v28;
                    }
                    else
                    {
                      idLib::Warning(fmt: "%s has bad morphing data", this->name.str);
                    }
                    list = p_morphVertSet->list;
                    ++v21;
                    ++v24;
                    v23 += 3;
                  }
                  while ( v21 < p_morphVertSet->list[v16].vertices.num );
                }
              }
            }
            ++v14;
            ++v16;
          }
          while ( v14 < p_morphVertSet->num );
        }
        *((_BYTE *)this + 2164) |= 8u;
      }
      else
      {
        idLib::Warning(fmt: "decl '%s' needs to have it's damage vertices generated to morph.", decl->name.str);
      }
    }
  }
}


// ========================================================================
// ?SerializeSnapshot@idTreeAnimator@@UAAXAAVidSerializer@@_N@Z
// EA  : 0x82861648
// RVA : 0x00861648
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SerializeSnapshot(idTreeAnimator *this, idSerializer *ser, bool serializeParmBlock)
{
  char v3; // r10
  idBitMsg *msg; // r3
  bool v8; // r29
  char v9; // r9
  char v10; // r3
  int num; // r8
  idList<bool,17> *p_meshVisibility; // r27
  int i; // r29
  idBitMsg *v14; // r3
  bool v15; // r28
  __int16 morphSkin; // r10
  idBitMsg *v17; // r3
  int v18; // r29
  int v19; // r5
  int v20; // [sp+50h] [-40h] BYREF

  v3 = *((_BYTE *)this + 2164);
  msg = ser->msg;
  v8 = (v3 & 4) != 0;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: (v3 & 4) != 0, numBits: 1);
  else
    v8 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  v9 = (4 * v8) & 4 | *((_BYTE *)this + 2164) & 0xFB;
  *((_BYTE *)this + 2164) = v9;
  if ( (v9 & 4) == 0 )
  {
    idRenderModel::SerializeSnapshot(this, ser, serializeParmBlock);
    v10 = idSerializer::SerializeBoolNonRef(this: ser, value: (*((_BYTE *)this + 2164) & 0x40) != 0);
    num = this->meshVisibility.num;
    *((_BYTE *)this + 2164) = (v10 << 6) & 0x40 | *((_BYTE *)this + 2164) & 0xBF;
    v20 = num;
    idSerializer::SerializeUMax(this: ser, value: &v20, maxSize: 0x20u);
    p_meshVisibility = &this->meshVisibility;
    idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&this->meshVisibility, newNum: v20);
    for ( i = 0; i < this->meshVisibility.num; ++i )
    {
      v14 = ser->msg;
      v15 = p_meshVisibility->list[i];
      if ( ser->writing )
        idBitMsg::WriteBits(this: v14, value: p_meshVisibility->list[i], numBits: 1);
      else
        v15 = (_cntlzw(idBitMsg::ReadBits(this: v14, numBits: 1) - 1) & 0x20) != 0;
      p_meshVisibility->list[i] = v15;
    }
    morphSkin = this->morphSkin;
    v17 = ser->msg;
    v18 = morphSkin;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v17, value: morphSkin, numBits: -16);
    else
      this->morphSkin = idBitMsg::ReadBits(this: v17, numBits: -16);
    if ( !ser->writing && v18 == -1 )
    {
      v19 = this->morphSkin;
      if ( v19 != -1 )
        idTreeAnimator::SetMorphSkin(this, skinName: nullptr, skinIndex: v19, morphAmount: 0.0);
    }
  }
}


// ========================================================================
// ?StoreTree@idTreeAnimator@@SAXPBVidMD6Model@@HHABVidAnimStack@@PAVidMD6Node@@AAVidBitMsg@@33@Z
// EA  : 0x828617F0
// RVA : 0x008617F0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTreeAnimator::StoreTree(
        const idMD6Model *model,
        int timeMSec,
        int ticksPerSec,
        const idAnimStack *animStack,
        __int64 typesMsg,
        idBitMsg *branchMsg,
        idBitMsg *leafMsg)
{
  idTreeAnimator::StoreTree_r(model, timeMSec, ticksPerSec, animStack, typesMsg, branchMsg, leafMsg);
}


// ========================================================================
// ?ReadTree_r@idTreeAnimator@@CAPAVidMD6Node@@ABVidAnimStack@@PAVidMD6Allocator@@AAVidBitMsg@@22@Z
// EA  : 0x82861800
// RVA : 0x00861800
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idTreeAnimator::ReadTree_r(
        const idAnimStack *animStack,
        idMD6Allocator *allocator,
        idBitMsg *typesMsg,
        idBitMsg *branchMsg,
        idBitMsg *leafMsg)
{
  unsigned int Bits; // r3
  idMD6Node *v11; // r30
  idMD6Node *v12; // r3
  __int64 v13; // r7
  __int64 v14; // r11
  idMD6LeafPlay *v16; // r30
  idMD6LeafPlay *v17; // r3
  idMD6LeafPlay *v18; // r3
  unsigned __int16 v19; // r28
  idAnimRecorder *v20; // r3
  const idMD6Anim *v21; // r3
  __int64 v22; // r7
  int startTime; // r4
  __int64 v24; // r10
  int v25; // r5
  idMD6LeafPause *v26; // r30
  idMD6LeafPause *v27; // r3
  idMD6LeafPause *v28; // r3
  unsigned __int16 v29; // r28
  idAnimRecorder *Instance; // r3
  const idMD6Anim *v31; // r3
  int v32; // r28
  signed int FrameRate; // r3
  __int64 v34; // r7
  unsigned __int8 v35; // r3
  __int64 v36; // r10
  int v37; // r7
  int v38; // r6
  int v39; // r5
  __int16 v40; // r3
  __int64 v41; // [sp+50h] [-60h] BYREF

  Bits = idBitMsg::ReadBits(this: typesMsg, numBits: 2);
  if ( Bits > 5 )
    return nullptr;
  if ( Bits == 1 )
  {
    if ( allocator != nullptr )
    {
      v26 = (idMD6LeafPause *)allocator->Alloc(this: allocator, a2: 1);
    }
    else
    {
      v27 = (idMD6LeafPause *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x50u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      HIDWORD(v41) = v27;
      if ( v27 != nullptr )
        v28 = idMD6LeafPause::idMD6LeafPause(this: v27);
      else
        v28 = nullptr;
      v26 = v28;
    }
    v26->weightGroup = idBitMsg::ReadBits(this: leafMsg, numBits: 3);
    v26->wrapMode = idBitMsg::ReadBits(this: leafMsg, numBits: 1);
    v29 = idBitMsg::ReadBits(this: leafMsg, numBits: 16);
    Instance = idAnimRecorder::GetInstance();
    idAnimRecorder::SerializeAnimNetworkID(this: Instance, animStack, animNetworkID: v29);
    v26->anim = v31;
    v32 = (unsigned __int16)idBitMsg::ReadBits(this: leafMsg, numBits: 16);
    FrameRate = idMD6Leaf::GetFrameRate(this: v26);
    LODWORD(v34) = v32 / FrameRate;
    v41 = v34;
    v26->frame = (float)v34;
    __twllei(FrameRate, 0);
    __twlgei(FrameRate & ~(__ROL4__(v32, 1) - 1), 0xFFFFFFFF);
    v35 = idBitMsg::ReadBits(this: leafMsg, numBits: 8);
    idMD6LeafPause::SetNumAnimMods(this: v26, n: v35, a3: v39, a4: v38, a5: v37, a6: v36);
    v40 = idBitMsg::ReadBits(this: leafMsg, numBits: 4);
    LODWORD(v41) = leafMsg;
    v26->flags = v40;
    HIBYTE(v41) = 0;
    SerializeJointMods(
      ser: (idSerializer *)&v41,
      jointMods: v26->animMods[v26->currentDeferred & 1].list,
      numMods: v26->animMods[0].num);
    return (idMD6LeafPlay *)v26;
  }
  else if ( Bits == 2 )
  {
    if ( allocator != nullptr )
    {
      v16 = (idMD6LeafPlay *)allocator->Alloc(this: allocator, a2: 2);
    }
    else
    {
      v17 = (idMD6LeafPlay *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x18u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
      HIDWORD(v41) = v17;
      if ( v17 != nullptr )
        v18 = idMD6LeafPlay::idMD6LeafPlay(this: v17);
      else
        v18 = nullptr;
      v16 = v18;
    }
    v16->weightGroup = idBitMsg::ReadBits(this: leafMsg, numBits: 3);
    v16->wrapMode = idBitMsg::ReadBits(this: leafMsg, numBits: 1);
    v19 = idBitMsg::ReadBits(this: leafMsg, numBits: 16);
    v20 = idAnimRecorder::GetInstance();
    idAnimRecorder::SerializeAnimNetworkID(this: v20, animStack, animNetworkID: v19);
    v16->anim = v21;
    v16->startTime = idBitMsg::ReadBits(this: leafMsg, numBits: 32);
    LODWORD(v22) = (unsigned __int16)idBitMsg::ReadBits(this: leafMsg, numBits: 16);
    startTime = v16->startTime;
    v41 = v22;
    idMD6LeafPlay::SetRateScale(
      this: v16,
      gameTime: startTime,
      rs: (float)((float)v22 * (float)0.0039215689),
      a4: v25,
      a5: SHIDWORD(v22),
      a6: v22,
      a7: (int)byte_821B0000,
      a8: v24);
    return v16;
  }
  else
  {
    if ( allocator != nullptr )
    {
      v11 = allocator->Alloc(this: allocator, a2: 0);
    }
    else
    {
      v12 = (idMD6Node *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x28u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      if ( v12 != nullptr )
      {
        v12->type = 0;
        *(_DWORD *)&v12[4].type = 0;
        *(_DWORD *)&v12[8].type = 0;
        *(_DWORD *)&v12[12].type = -1;
        v11 = v12;
        *(_DWORD *)&v12[16].type = -1;
        v12[20].type = 8;
        *(float *)&v12[24].type = 0.0;
        v12[21].type = 10;
        *(float *)&v12[28].type = 0.0;
        v12[22].type = 0;
        *(float *)&v12[32].type = 0.0;
        *(_DWORD *)&v12[36].type = 0;
      }
      else
      {
        v11 = nullptr;
      }
    }
    v11[20].type = idBitMsg::ReadBits(this: branchMsg, numBits: 3);
    v11[21].type = idBitMsg::ReadBits(this: branchMsg, numBits: 4);
    LODWORD(v13) = (unsigned __int8)idBitMsg::ReadBits(this: branchMsg, numBits: 8);
    *(float *)&v11[24].type = (float)v13 * (float)0.0039215689;
    *(float *)&v11[28].type = (float)((unsigned __int8)idBitMsg::ReadBits(this: branchMsg, numBits: 8) | 0x1000000000uLL)
                            * (float)0.0039215689;
    LODWORD(v14) = (unsigned __int16)idBitMsg::ReadBits(this: branchMsg, numBits: 16);
    v41 = v14;
    *(float *)&v11[32].type = (float)v14 * (float)0.0039215689;
    v11[22].type = idBitMsg::ReadBits(this: branchMsg, numBits: 8);
    if ( idBitMsg::ReadBits(this: branchMsg, numBits: 1) != 0 )
      *(_DWORD *)&v11[4].type = idTreeAnimator::ReadTree_r(animStack, allocator, typesMsg, branchMsg, leafMsg);
    else
      *(_DWORD *)&v11[4].type = 0;
    *(_DWORD *)&v11[8].type = idTreeAnimator::ReadTree_r(animStack, allocator, typesMsg, branchMsg, leafMsg);
    return (idMD6LeafPlay *)v11;
  }
}


// ========================================================================
// __unwind$246881
// EA  : 0x82861C78
// RVA : 0x00861C78
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall _unwind_246881(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// __unwind$246882
// EA  : 0x82861CA0
// RVA : 0x00861CA0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall _unwind_246882(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?Load@idTreeAnimator@@EAA_NPAVidFile@@@Z
// EA  : 0x82861CC8
// RVA : 0x00861CC8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::Load(idTreeAnimator *this, idFile *fp)
{
  const idMD6Model *model; // r27
  size_t v6; // r26
  int morphSkin; // r5
  const idMD6Skel *skeleton; // r11
  const float *v9; // r7
  const float *v10; // r6
  idArray<idJointBuffer,4> *p_jointBuffers; // r29
  int i; // r30
  idJointMat *v13; // r4
  idJointMat *v14; // r3
  _BYTE v15[4]; // [sp+50h] [-40h] BYREF
  int v16[15]; // [sp+54h] [-3Ch] BYREF

  if ( (unsigned __int8)idRenderModel::Load(this, fp) == 0 )
    return 0;
  model = this->decl->model;
  v6 = 48 * ((model->skeleton->data->numJoints + 7) & 0xFFF8);
  if ( fp->Read(this: fp, a2: &this->lastBlendTime, a3: 4u) == 0 )
    return 0;
  if ( fp->Read(this: fp, a2: v15, a3: 1u) == 0 )
    return 0;
  *((_BYTE *)this + 2164) = (v15[0] << 7) | *((_BYTE *)this + 2164) & 0x7F;
  if ( fp->Read(this: fp, a2: v15, a3: 1u) == 0 )
    return 0;
  *((_BYTE *)this + 2164) = (v15[0] << 6) & 0x40 | *((_BYTE *)this + 2164) & 0xBF;
  if ( fp->Read(this: fp, a2: v15, a3: 1u) == 0 )
    return 0;
  *((_BYTE *)this + 2164) = (32 * v15[0]) & 0x20 | *((_BYTE *)this + 2164) & 0xDF;
  if ( fp->Read(this: fp, a2: v15, a3: 1u) == 0 )
    return 0;
  *((_BYTE *)this + 2164) = (16 * v15[0]) & 0x10 | *((_BYTE *)this + 2164) & 0xEF;
  if ( fp->Read(this: fp, a2: &this->deferredJobJointBuffer, a3: 4u) == 0 )
    return 0;
  if ( fp->Read(this: fp, a2: v16, a3: 4u) == 0 )
    return 0;
  idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&this->meshVisibility, newNum: v16[0]);
  if ( fp->Read(this: fp, a2: this->meshVisibility.list, a3: this->meshVisibility.num) == 0
    || fp->Read(this: fp, a2: v16, a3: 4u) == 0
    || fp->Read(this: fp, a2: this->joints[0], a3: v6 & 0xFFFFFFFC) == 0
    || fp->Read(this: fp, a2: this->joints[1], a3: v6 & 0xFFFFFFFC) == 0
    || fp->Read(this: fp, a2: &this->morphSkin, a3: 2u) == 0
    || fp->Read(this: fp, a2: &this->initialMorphValue, a3: 4u) == 0 )
  {
    return 0;
  }
  morphSkin = this->morphSkin;
  if ( morphSkin != -1 )
    idTreeAnimator::SetMorphSkin(
      this,
      skinName: &byte_8200D768,
      skinIndex: morphSkin,
      morphAmount: this->initialMorphValue);
  if ( fp->Read(this: fp, a2: &this->frameBounds, a3: 24u) == 0
    || fp->Read(this: fp, a2: &this->normalizedBounds, a3: 24u) == 0
    || fp->Read(this: fp, a2: &this->translatedBounds, a3: 24u) == 0
    || fp->Read(this: fp, a2: &this->skipJointForBounds, a3: 2u) == 0 )
  {
    return 0;
  }
  skeleton = model->skeleton;
  if ( skeleton != nullptr )
    v9 = (const float *)((char *)&skeleton->data->size + skeleton->data->inverseBasePoseQuatOffset);
  else
    v9 = nullptr;
  if ( skeleton != nullptr )
    v10 = (const float *)((char *)&skeleton->data->size + skeleton->data->inverseBasePoseOffset);
  else
    v10 = nullptr;
  idMD6Blend::TransformModelMatrices(
    skeleton: skeleton->data,
    remap: model->jointRemap.list,
    inMatrices1: this->joints[1]->mat,
    inMatrices2: v10,
    invertedRefPoseQuat: v9,
    outMatrices: this->joints[3]->mat,
    useDualQuat: (*((_BYTE *)this + 2164) & 2) != 0,
    quatTemp: nullptr);
  p_jointBuffers = &this->jointBuffers;
  for ( i = 4; i != 0; --i )
  {
    idJointBuffer::Update(this: p_jointBuffers->ptr, joints: this->joints[3]->mat, numUpdateJoints: v6 / 0x30);
    p_jointBuffers = (idArray<idJointBuffer,4> *)((char *)p_jointBuffers + 16);
  }
  v13 = this->joints[0];
  v14 = this->joints[2];
  *((_BYTE *)this + 2164) &= ~0x80u;
  memcpy(Dst: v14, Src: v13, Size: v6);
  memcpy(Dst: this->joints[3], Src: this->joints[1], Size: v6);
  return 1;
}


// ========================================================================
// ?InitializeSurfaces@idTreeAnimator@@AAAXXZ
// EA  : 0x828620C8
// RVA : 0x008620C8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::InitializeSurfaces(idTreeAnimator *this)
{
  idList<idRenderModelSurface,85> *p_surfaces; // r27
  const idMD6Model *model; // r7
  int num; // r30
  int size; // r11
  int v6; // r29
  int v7; // r30
  idJointBuffer *v8; // r3
  idJointBuffer *v9; // r3
  idRenderModelSurface *v10; // r11

  p_surfaces = &this->surfaces;
  this->FreeSurfaces(this);
  model = this->decl->model;
  num = model->meshes.num;
  if ( num <= this->surfaces.size
    || (unsigned __int8)idList<idRenderModelSurface,85>::Resize(this: &this->surfaces, newsize: model->meshes.num) != 0 )
  {
    size = this->surfaces.size;
    if ( num < size )
      size = num;
    this->surfaces.num = size;
  }
  v6 = 0;
  if ( this->surfaces.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (idJointBuffer *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                              size: 0x10u,
                              tag: TAG_NEW,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      if ( v8 != nullptr )
        v9 = idJointBuffer::idJointBuffer(this: v8);
      else
        v9 = nullptr;
      ++v6;
      v10 = &p_surfaces->list[v7++];
      v10->joints = v9;
    }
    while ( v6 < this->surfaces.num );
  }
}


// ========================================================================
// __unwind$247443
// EA  : 0x828621B8
// RVA : 0x008621B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall _unwind_247443(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?CommitSubclass@idTreeAnimator@@EAA_NXZ
// EA  : 0x828621E0
// RVA : 0x008621E0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

int __fastcall idTreeAnimator::CommitSubclass(idTreeAnimator *this)
{
  const idDeclMD6 *decl; // r11
  const idMD6Model *model; // r19
  char v5; // r3
  __int64 v6; // r9
  char v7; // r10
  unsigned __int8 v8; // r6
  int v9; // r4
  int v10; // r7
  int v11; // r5
  int v12; // r11
  idTriangles *tris; // r8
  int v14; // r10
  unsigned __int8 *v15; // r3
  int v16; // r26
  double v17; // fp29
  int v18; // r29
  int v19; // r27
  idTriangles *v20; // r31
  float *p_x; // r7
  int v22; // r9
  int v23; // r11
  unsigned __int8 v24; // r8
  int v25; // r5
  int v26; // r7
  int v27; // r6
  int v28; // r11
  idTriangles *v29; // r8
  int v30; // r10
  idPixelUnpackBuffer *v31; // r3
  char v32; // r20
  int v33; // r26
  int v34; // r27
  int v35; // r23
  int v36; // r24
  int v37; // r25
  idRenderModelSurface *v38; // r31
  const idMaterial *customMaterial; // r11
  idMD6Mesh *v40; // r29
  const idMaterial *material; // r28
  int customSkin; // r11
  double x; // fp0
  int v44; // r7
  double v45; // fp13
  int morphSkin; // r11
  idJointBuffer *joints; // r3
  idVertexBuffer *vb; // r11
  idTreeAnimator::morphMap_t *list; // r10
  unsigned __int8 *map; // r4
  idMat3 *v51; // r11
  int i; // ctr
  idMat3 *v53; // r11
  int j; // ctr
  int v55; // r31
  int v56; // r29
  char *v57; // r11
  double v58; // fp1
  int v59; // r9
  idMat3 *v60; // r10
  int num; // r11
  const idDeclRenderParm *r; // r31
  idStaticParmBlock<32> *ParmBlock; // r3
  const idDeclRenderParm *v64; // r31
  idStaticParmBlock<32> *v65; // r3
  const idDeclRenderParm *v66; // r31
  idStaticParmBlock<32> *v67; // r3
  const idDeclRenderParm *v68; // r31
  idStaticParmBlock<32> *v69; // r3
  int deferredJobJointBuffer; // r11
  int v71; // r25
  idRenderModelParms *p_g; // r28
  int v73; // r27
  idRenderModel::decalData_t *v74; // r29
  idMat3 *p_relativeAxis; // r4
  __int16 value; // r10
  double v77; // fp13
  double v78; // fp12
  double v79; // fp11
  double y; // fp10
  double v81; // fp9
  double v82; // fp8
  double v83; // fp7
  double v84; // fp6
  idJointMat *v85; // r11
  double v86; // fp5
  double v87; // fp4
  double v88; // fp3
  double v89; // fp2
  double v90; // fp1
  double v91; // fp28
  double v92; // fp24
  double v93; // fp26
  double v94; // fp27
  double v95; // fp0
  double v96; // fp23
  double v97; // fp21
  double v98; // fp25
  double v99; // fp22
  double v100; // fp19
  double v101; // fp20
  double v102; // fp29
  double v103; // fp18
  double v104; // fp26
  double v105; // fp17
  double v106; // fp31
  double v107; // fp13
  double v108; // fp12
  double v109; // fp0
  double v110; // fp13
  idMat3 *v111; // r3
  float *v112; // r3
  double z; // fp8
  double v114; // fp5
  double v115; // fp3
  parmValue_t v116; // [sp+50h] [-1D0h] BYREF
  idVec3 v117; // [sp+60h] [-1C0h] BYREF
  idMat3 v118; // [sp+70h] [-1B0h] BYREF
  idMat3 v119; // [sp+A0h] [-180h] BYREF
  idMat3 v120; // [sp+D0h] [-150h] BYREF
  idMat3 v121[4]; // [sp+100h] [-120h] BYREF

  this->renderThreadJointBuffer = this->nextRenderThreadJointBuffer;
  this->referenceBounds = this->frameBounds;
  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  model = decl->model;
  if ( model == nullptr )
    return 0;
  if ( r_showSkel.valueInteger > 1 )
  {
    this->FreeSurfaces(this);
    idTreeAnimator::FreeMorphMaps(this);
    return 1;
  }
  if ( this->surfaces.num != model->meshes.num )
    idTreeAnimator::InitializeSurfaces(this);
  if ( this->morphMaps.num != model->meshes.num )
  {
    idTreeAnimator::InitializeMorphMaps(this);
    *((_BYTE *)this + 2164) |= 8u;
  }
  if ( r_testMorphMaps.valueInteger != 0 )
  {
    v5 = renderSystem->FrameNumber(this: renderSystem);
    HIDWORD(v6) = v5 & 0x40;
    if ( (v5 & 0x40) != 0 )
      v7 = v5 & 0x3F;
    else
      v7 = 63 - (v5 & 0x3F);
    v8 = 4 * v7;
    switch ( r_testMorphMaps.valueInteger )
    {
      case 1:
        v9 = 0;
        if ( model->meshes.num > 0 )
        {
          v10 = 0;
          v11 = 0;
          do
          {
            if ( this->morphMaps.list[v10].map != nullptr )
            {
              v12 = 0;
              tris = model->meshes.list[v11]->tris;
              if ( tris->numVerts > 0 )
              {
                v14 = 0;
                do
                {
                  ++v12;
                  v15 = &this->morphMaps.list[v10].map[v14];
                  v14 += 4;
                  v15[3] = v8;
                }
                while ( v12 < tris->numVerts );
              }
            }
            ++v9;
            ++v11;
            ++v10;
          }
          while ( v9 < model->meshes.num );
        }
        break;
      case 2:
        LODWORD(v6) = (unsigned __int8)(4 * v7);
        v16 = 0;
        v17 = (float)((float)((float)((float)(model->defaultBounds.b[1].x - model->defaultBounds.b[0].x) * (float)v6)
                            * (float)0.00390625)
                    + model->defaultBounds.b[0].x);
        *(_QWORD *)v116.value = v6;
        if ( model->meshes.num > 0 )
        {
          v18 = 0;
          v19 = 0;
          do
          {
            if ( this->morphMaps.list[v18].map != nullptr )
            {
              v20 = model->meshes.list[v19]->tris;
              p_x = &v20->verts->xyz.x;
              if ( (v20->vertexBuffer.size & 0x7FFFFFFF) != 0 )
                p_x = (float *)idVertexBuffer::MapBuffer(this: &v20->vertexBuffer, mapType: BM_READ);
              v22 = 0;
              if ( v20->numVerts > 0 )
              {
                v23 = 0;
                do
                {
                  v116.swizzle[1] = (int)(float)-(float)((float)((float)__fabs((float)(*p_x - (float)v17)) * (float)4.0)
                                                       - (float)255.0);
                  if ( v116.swizzle[1] >= 0 )
                  {
                    v24 = -1;
                    if ( v116.swizzle[1] <= 255 )
                      v24 = v116.swizzle[1];
                  }
                  else
                  {
                    v24 = 0;
                  }
                  ++v22;
                  p_x += 8;
                  this->morphMaps.list[v18].map[v23 + 3] = v24;
                  v23 += 4;
                }
                while ( v22 < v20->numVerts );
              }
              if ( (v20->vertexBuffer.size & 0x7FFFFFFF) != 0 )
                idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&v20->vertexBuffer);
            }
            ++v16;
            ++v19;
            ++v18;
          }
          while ( v16 < model->meshes.num );
        }
        break;
      case 3:
        v25 = 0;
        if ( model->meshes.num > 0 )
        {
          v26 = 0;
          v27 = 0;
          do
          {
            if ( this->morphMaps.list[v26].map != nullptr )
            {
              v28 = 0;
              v29 = model->meshes.list[v27]->tris;
              if ( v29->numVerts > 0 )
              {
                v30 = 0;
                do
                {
                  ++v28;
                  this->morphMaps.list[v26].map[v30 + 3] = 0;
                  v30 += 4;
                }
                while ( v28 < v29->numVerts );
              }
            }
            ++v25;
            ++v27;
            ++v26;
          }
          while ( v25 < model->meshes.num );
        }
        break;
      default:
        break;
    }
    *((_BYTE *)this + 2164) |= 8u;
  }
  if ( (*((_BYTE *)this + 2164) & 8) != 0 )
    this->currentMorphBuffer ^= 1u;
  v31 = (idPixelUnpackBuffer *)&this->jointBuffers.ptr[this->renderThreadJointBuffer];
  if ( v31->size < 0 )
    idVertexBuffer::UnmapBuffer(this: v31);
  v32 = 0;
  v33 = 0;
  if ( model->meshes.num > 0 )
  {
    v34 = 0;
    v35 = 0;
    v36 = 0;
    v37 = 0;
    while ( 1 )
    {
      v38 = &this->surfaces.list[v37];
      v38->material = nullptr;
      if ( this->meshVisibility.list[v33] )
        break;
LABEL_78:
      ++v33;
      ++v37;
      ++v36;
      ++v35;
      ++v34;
      if ( v33 >= model->meshes.num )
        goto LABEL_79;
    }
    customMaterial = this->g.customMaterial;
    v40 = model->meshes.list[v36];
    if ( customMaterial != nullptr )
    {
      v38->skinOffsets.w = 0.0;
      material = customMaterial;
      v38->skinOffsets.z = 0.0;
      v38->skinOffsets.y = 0.0;
      v38->skinOffsets.x = 0.0;
LABEL_67:
      if ( material != nullptr && material->coverage != MC_INVISIBLE )
      {
        v38->referenceMask = 3;
        v38->geometryIsReference = true;
        v38->material = material;
        joints = v38->joints;
        v38->geometry = v40->tris;
        idJointBuffer::Reference(
          this: joints,
          other: &this->jointBuffers.ptr[this->renderThreadJointBuffer],
          jointRefOffset: v40->jointOffset,
          numRefJoints: v40->numJoints);
        if ( v40->stSets.num <= 0 )
          vb = nullptr;
        else
          vb = v40->stSets.list->vb;
        v38->stMap = vb;
        if ( (*((_BYTE *)this + 2164) & 8) != 0 )
        {
          list = this->morphMaps.list;
          map = list[v35].map;
          if ( map != nullptr )
          {
            idVertexBuffer::Update(
              this: list[v34].buffers.ptr[this->currentMorphBuffer],
              data: map,
              updateSize: 4 * v38->geometry->numVerts,
              vertexMask: 4);
            v38->morphMap = this->morphMaps.list[v34].buffers.ptr[this->currentMorphBuffer];
          }
        }
        if ( (*((_BYTE *)v38->material + 72) & 1) != 0 && this->wrinkleMapExpressions.num != 0 )
          v32 = 1;
      }
      goto LABEL_78;
    }
    customSkin = this->g.customSkin;
    if ( customSkin < 0 || customSkin >= v40->skinRemaps.num )
    {
      material = v40->material;
    }
    else
    {
      material = v40->skinRemaps.list[customSkin].mtr;
      if ( material == idMaterial::CompatibleGenericMaterial(this: material) )
      {
        x = v40->skinRemaps.list[this->g.customSkin].texOffset.x;
        v38->skinOffsets.x = v40->skinRemaps.list[this->g.customSkin].texOffset.x;
        v38->skinOffsets.z = x;
        v44 = (int)&v40->skinRemaps.list[this->g.customSkin];
        v45 = *(float *)(v44 + 8);
        v38->skinOffsets.w = *(float *)(v44 + 8);
        v38->skinOffsets.y = v45;
LABEL_64:
        morphSkin = this->morphSkin;
        if ( morphSkin >= 0 && morphSkin < v40->skinRemaps.num )
        {
          v38->skinOffsets.z = v40->skinRemaps.list[morphSkin].texOffset.x;
          v38->skinOffsets.w = v40->skinRemaps.list[this->morphSkin].texOffset.y;
        }
        goto LABEL_67;
      }
    }
    v38->skinOffsets.x = 0.0;
    v38->skinOffsets.y = 0.0;
    v38->skinOffsets.z = 0.0;
    v38->skinOffsets.w = 0.0;
    goto LABEL_64;
  }
LABEL_79:
  if ( v32 != 0 )
  {
    v51 = &v120;
    v120.mat[0].x = 0.0;
    for ( i = 7; i != 0; --i )
    {
      v51 = (idMat3 *)((char *)v51 + 4);
      v51->mat[0].x = 0.0;
    }
    v118.mat[0].x = 0.0;
    v53 = &v118;
    for ( j = 7; j != 0; --j )
    {
      v53 = (idMat3 *)((char *)v53 + 4);
      v53->mat[0].x = 0.0;
    }
    v55 = 0;
    if ( this->wrinkleMapExpressions.num > 0 )
    {
      v56 = 0;
      do
      {
        v57 = (char *)this + ((16 * this->currentDeferred) ^ 0x10);
        v58 = idUserChannelExpression::Eval(
                this: &this->wrinkleMapExpressions.list[v56],
                userChannels: *((const float **)v57 + 530),
                numChannels: *((_DWORD *)v57 + 531));
        v59 = 4 * (v55 >> 1);
        v60 = &v118;
        if ( (v55 & 1) == 0 )
          v60 = &v120;
        num = this->wrinkleMapExpressions.num;
        ++v55;
        *(float *)((char *)&v60->mat[0].x + v59) = v58;
        ++v56;
      }
      while ( v55 < num );
    }
    r = (const idDeclRenderParm *)rp_wrinkleFactor0.r;
    ParmBlock = idRenderModel::GetParmBlock(this);
    v116.value[0] = v120.mat[0].x;
    v116.value[1] = v120.mat[0].y;
    v116.value[2] = v120.mat[0].z;
    v116.value[3] = v120.mat[1].x;
    idParmBlock::SetParm(this: ParmBlock, parm: r, parmValue: &v116);
    v64 = (const idDeclRenderParm *)rp_wrinkleFactor1.r;
    v65 = idRenderModel::GetParmBlock(this);
    v116.value[0] = v118.mat[0].x;
    v116.value[1] = v118.mat[0].y;
    v116.value[2] = v118.mat[0].z;
    v116.value[3] = v118.mat[1].x;
    idParmBlock::SetParm(this: v65, parm: v64, parmValue: &v116);
    v66 = (const idDeclRenderParm *)rp_wrinkleFactor2.r;
    v67 = idRenderModel::GetParmBlock(this);
    v116.value[0] = v120.mat[1].y;
    v116.value[1] = v120.mat[1].z;
    v116.value[2] = v120.mat[2].x;
    v116.value[3] = v120.mat[2].y;
    idParmBlock::SetParm(this: v67, parm: v66, parmValue: &v116);
    v68 = (const idDeclRenderParm *)rp_wrinkleFactor3.r;
    v69 = idRenderModel::GetParmBlock(this);
    v116.value[0] = v118.mat[1].y;
    v116.value[1] = v118.mat[1].z;
    v116.value[2] = v118.mat[2].x;
    v116.value[3] = v118.mat[2].y;
    idParmBlock::SetParm(this: v69, parm: v68, parmValue: &v116);
  }
  deferredJobJointBuffer = this->deferredJobJointBuffer;
  if ( deferredJobJointBuffer >= 0 )
    this->nextRenderThreadJointBuffer = deferredJobJointBuffer;
  v71 = this->decalData.num - 1;
  *((_BYTE *)this + 2164) &= ~8u;
  if ( v71 >= 0 )
  {
    p_g = &this->g;
    v73 = v71;
    do
    {
      v74 = &this->decalData.list[v73];
      p_relativeAxis = &v74->relativeAxis;
      value = v74->jointId.value;
      if ( value == NULL_JOINT_INDEX.value )
      {
        z = this->g.origin.z;
        v114 = (float)((float)(this->g.axis.mat[0].z * v74->relativePos.x)
                     + (float)((float)(this->g.axis.mat[1].z * v74->relativePos.y)
                             + (float)(this->g.axis.mat[2].z * v74->relativePos.z)));
        v115 = (float)((float)((float)(this->g.axis.mat[0].y * v74->relativePos.x)
                             + (float)((float)(this->g.axis.mat[1].y * v74->relativePos.y)
                                     + (float)(this->g.axis.mat[2].y * v74->relativePos.z)))
                     + this->g.origin.y);
        v117.x = (float)((float)(this->g.axis.mat[0].x * v74->relativePos.x)
                       + (float)((float)(this->g.axis.mat[1].x * v74->relativePos.y)
                               + (float)(this->g.axis.mat[2].x * v74->relativePos.z)))
               + p_g->origin.x;
        v117.y = v115;
        v117.z = (float)v114 + (float)z;
        v112 = (float *)idMat3::operator*(this: v121, result: p_relativeAxis, a: &this->g.axis);
      }
      else
      {
        v77 = v74->relativePos.x;
        v78 = v74->relativePos.z;
        v79 = this->g.axis.mat[1].x;
        y = this->g.axis.mat[1].y;
        v81 = this->g.axis.mat[1].z;
        v82 = this->g.axis.mat[2].x;
        v83 = this->g.axis.mat[2].y;
        v84 = this->g.axis.mat[2].z;
        v85 = &this->joints[1][value];
        v86 = this->g.axis.mat[0].x;
        v87 = this->g.axis.mat[0].y;
        v88 = this->g.axis.mat[0].z;
        v89 = p_g->origin.x;
        v90 = this->g.origin.y;
        v91 = v85->mat[9];
        v92 = v85->mat[1];
        v93 = (float)(v74->relativePos.y * v85->mat[9]);
        v94 = v85->mat[4];
        v95 = (float)(v74->relativePos.y * v85->mat[1]);
        v96 = v85->mat[8];
        v97 = v85->mat[0];
        v98 = v85->mat[6];
        v99 = v85->mat[10];
        v100 = v85->mat[2];
        v101 = v85->mat[7];
        v102 = (float)((float)(v74->relativePos.x * v85->mat[4]) + (float)(v74->relativePos.y * v85->mat[5]));
        v118.mat[1].y = v85->mat[5];
        v103 = v85->mat[11];
        v104 = (float)((float)((float)v77 * (float)v96) + (float)v93);
        v105 = v85->mat[3];
        v106 = this->g.origin.z;
        v118.mat[0].y = v94;
        v118.mat[0].z = v96;
        v118.mat[1].x = v92;
        v118.mat[1].z = v91;
        v118.mat[0].x = v97;
        v118.mat[2].y = v98;
        v118.mat[2].x = v100;
        v118.mat[2].z = v99;
        v107 = (float)((float)((float)v78 * (float)v100) + (float)((float)((float)v77 * (float)v97) + (float)v95));
        v109 = (float)((float)((float)((float)v78 * (float)v99) + (float)v104) + (float)v103);
        v108 = (float)((float)((float)((float)v78 * (float)v98) + (float)v102) + (float)v101);
        v110 = (float)((float)v107 + (float)v105);
        v117.x = (float)((float)((float)v86 * (float)v110)
                       + (float)((float)((float)v82 * (float)v109) + (float)((float)v79 * (float)v108)))
               + (float)v89;
        v117.y = (float)((float)((float)v87 * (float)v110)
                       + (float)((float)((float)v83 * (float)v109) + (float)((float)y * (float)v108)))
               + (float)v90;
        v117.z = (float)((float)((float)v88 * (float)v110)
                       + (float)((float)((float)v84 * (float)v109) + (float)((float)v81 * (float)v108)))
               + (float)v106;
        v111 = idMat3::operator*(this: &v120, result: p_relativeAxis, a: &v118);
        v112 = (float *)idMat3::operator*(this: v121, result: v111, a: &this->g.axis);
      }
      v119.mat[0].x = *v112;
      v119.mat[0].y = v112[1];
      v119.mat[0].z = v112[2];
      v119.mat[1].x = v112[3];
      v119.mat[1].y = v112[4];
      v119.mat[1].z = v112[5];
      v119.mat[2].x = v112[6];
      v119.mat[2].y = v112[7];
      v119.mat[2].z = v112[8];
      if ( !idRenderModel::SetDecalPosition(
              this,
              decalHandle: (const idHandle<int,enum invalidDecalHandle_t,-1> *)v74->handle.value,
              decalWorldPosition: &v117,
              decalWorldAxis: &v119) )
        idList<idRenderModel::decalData_t,5>::RemoveIndexFast(this: &this->decalData, index: v71);
      --v71;
      --v73;
    }
    while ( v71 >= 0 );
  }
  return 1;
}


// ========================================================================
// ?AddDecalFromPoint@idTreeAnimator@@EAA?AV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@PBUdecalParams_t@@HABVidVec3@@1V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82862D20
// RVA : 0x00862D20
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::AddDecalFromPoint(
        idTreeAnimator *this,
        idRenderModel *result,
        const decalParams_t *decalParms,
        int startTime,
        const idVec3 *pos,
        const idVec3 *dir,
        idIndex<short,enum invalidJointIndex_t> *jointId)
{
  __int16 v9; // r30
  int value; // r11
  float *v11; // r11
  double v12; // fp10
  double v13; // fp8
  double v14; // fp0
  double v15; // fp7
  double v16; // fp5
  double v17; // fp4
  double v18; // fp3
  double v19; // fp2
  double v20; // fp13
  double v21; // fp12
  double v22; // fp6
  float *v23; // r3
  idMat3 v25; // [sp+50h] [-C0h] BYREF
  idMat3 v26; // [sp+80h] [-90h] BYREF
  idRenderModel::decalData_t v27; // [sp+B0h] [-60h] BYREF

  v9 = (__int16)jointId;
  value = -1;
  if ( result->decalData.num < result->decalData.size )
  {
    v27.handle.value = -1;
    v27.jointId.value = -1;
    idRenderModel::InitDecalData(this: result, decal: &v27, decalParms, startTime, pos, dir);
    if ( v9 != NULL_JOINT_INDEX.value )
    {
      v11 = (float *)(48 * v9 + *(_DWORD *)&result[1].needWriteToSnapshot);
      v12 = (float)(v27.relativePos.z - v11[11]);
      v13 = v11[9];
      v14 = (float)(v27.relativePos.x - v11[3]);
      v15 = v11[8];
      v16 = (float)(v27.relativePos.y - v11[7]);
      v17 = v11[6];
      v18 = v11[5];
      v19 = v11[4];
      v25.mat[2].z = v11[10];
      v25.mat[2].y = v13;
      v25.mat[2].x = v15;
      v20 = v11[2];
      v21 = v11[1];
      v22 = *v11;
      v25.mat[0].x = *v11;
      v25.mat[1].z = v17;
      v25.mat[1].y = v18;
      v25.mat[1].x = v19;
      v25.mat[0].z = v20;
      v25.mat[0].y = v21;
      v27.relativePos.x = (float)((float)v14 * (float)v22)
                        + (float)((float)((float)v16 * (float)v19) + (float)((float)v12 * (float)v15));
      v27.relativePos.y = (float)((float)v14 * (float)v21)
                        + (float)((float)((float)v16 * (float)v18) + (float)((float)v12 * (float)v13));
      v27.relativePos.z = (float)((float)v14 * (float)v20)
                        + (float)((float)((float)v16 * (float)v17) + (float)((float)v12 * v25.mat[2].z));
      v23 = (float *)idMat3::operator*(this: &v26, result: &v27.relativeAxis, a: &v25);
      v27.relativeAxis.mat[0].x = *v23;
      v27.relativeAxis.mat[0].y = v23[1];
      v27.relativeAxis.mat[0].z = v23[2];
      v27.relativeAxis.mat[1].x = v23[3];
      v27.relativeAxis.mat[1].y = v23[4];
      v27.relativeAxis.mat[1].z = v23[5];
      v27.relativeAxis.mat[2].x = v23[6];
      v27.relativeAxis.mat[2].y = v23[7];
      v27.relativeAxis.mat[2].z = v23[8];
      v27.jointId.value = v9;
    }
    idList<idRenderModel::decalData_t,5>::Append(this: &result->decalData, obj: &v27);
    value = v27.handle.value;
  }
  this->__vftable = (idTreeAnimator_vtbl *)value;
  return this;
}


// ========================================================================
// ?ReadTree@idTreeAnimator@@SAPAVidMD6Node@@ABVidAnimStack@@PAVidMD6Allocator@@AAVidBitMsg@@22@Z
// EA  : 0x82862EA8
// RVA : 0x00862EA8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

// attributes: thunk
idMD6LeafPlay *__fastcall idTreeAnimator::ReadTree(
        const idAnimStack *animStack,
        idMD6Allocator *allocator,
        idBitMsg *typesMsg,
        idBitMsg *branchMsg,
        idBitMsg *leafMsg)
{
  return idTreeAnimator::ReadTree_r(animStack, allocator, typesMsg, branchMsg, leafMsg);
}


// ========================================================================
// ?BlendTreeInternal@idTreeAnimator@@AAAXHHHHPAVidMD6Node@@PAVidParallelJobList@@PAM222@Z
// EA  : 0x82862FF0
// RVA : 0x00862FF0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::BlendTreeInternal(
        idTreeAnimator *this,
        int currentTime,
        const int previousTime,
        int gameMsPerFrame,
        unsigned int ticksPerSec,
        idMD6LeafPlay *tree,
        idParallelJobList *parallelJobList,
        const idMD6Blend::jointMod_t *localR,
        float *localS,
        float *localT,
        float *localU,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        float *a28,
        int a29,
        float *a30,
        int a31,
        float *a32)
{
  char v40; // r10
  char v41; // r10
  BOOL v42; // r6
  int nextRenderThreadJointBuffer; // r11
  int deferredJobJointBuffer; // r9
  int v45; // r30
  int v46; // r4
  int v47; // r11
  int v48; // r11
  int v49; // r11
  char v50; // r9
  char v51; // r11
  char v52; // r30
  double x; // fp31
  double v54; // fp30
  double y; // fp0
  double z; // fp13
  double v57; // fp12
  double v58; // fp11
  const idMD6Skel *skeleton; // r11
  const idMD6Skel *v60; // r11
  idMD6Blend::blendParms_t *blendParms; // r4
  idMD6Blend::blendParms_t *v62; // r10
  int currentDeferred; // r9
  char *v64; // r8
  int v65; // r7
  idMD6Blend::blendParms_t *v66; // r6
  int value; // r5
  idPixelUnpackBuffer *v68; // r3
  idPixelUnpackBuffer *v69; // r3
  size_t v70; // r29
  _QWORD *v71; // r10
  int v72; // ctr
  _QWORD *v73; // r11
  md6OriginDelta_t *v74; // r9
  idBounds *p_frameBounds; // r11
  double v76; // fp8
  double v77; // fp0
  double v78; // fp7
  double v79; // fp13
  double v80; // fp11
  double v81; // fp10
  double v82; // fp13
  double v83; // fp12
  const idMD6Model *model; // r7
  double v85; // fp4
  double v86; // fp1
  double v87; // fp13
  double v88; // fp12
  idMD6Blend::configInfo_t *config; // r8
  double v90; // fp4
  int v91; // r10
  idBounds *v92; // [sp+8h] [-E8h]
  int v93; // [sp+8h] [-E8h]
  idBounds *v94; // [sp+Ch] [-E4h]
  int v95; // [sp+Ch] [-E4h]
  md6OriginDelta_t *v96; // [sp+10h] [-E0h]
  unsigned __int16 v97; // [sp+16h] [-DAh]
  int v98; // [sp+18h] [-D8h]
  int v99; // [sp+1Ch] [-D4h]
  int v100; // [sp+20h] [-D0h]
  int v101; // [sp+24h] [-CCh]
  int v102; // [sp+28h] [-C8h]
  int v103; // [sp+2Ch] [-C4h]
  int v104; // [sp+30h] [-C0h]
  int v105; // [sp+34h] [-BCh]
  int v106; // [sp+38h] [-B8h]
  int v107; // [sp+3Ch] [-B4h]
  int v108; // [sp+40h] [-B0h]
  int v109; // [sp+44h] [-ACh]
  int v110; // [sp+48h] [-A8h]
  int v111; // [sp+4Ch] [-A4h]
  int v112; // [sp+50h] [-A0h]
  int v113; // [sp+58h] [-98h]
  int v114; // [sp+60h] [-90h]
  int v115; // [sp+68h] [-88h]
  idBounds v116; // [sp+70h] [-80h] BYREF

  if ( tree != nullptr && (unsigned __int8)idMD6Node::IsValid(this: tree) != 0
    || *(int *)((char *)&this->jointMods[0].num + ((16 * this->currentDeferred) & 0x10)) != 0 )
  {
    this->lastBlendTime = currentTime;
    if ( localR == nullptr && !this->blendParms->originDelta->done )
    {
      do
        Sys_Yield();
      while ( !this->blendParms->originDelta->done );
    }
    v40 = *((_BYTE *)this + 2164);
    if ( ((v40 & 2) != 0) != (r_forceDualQuatSkinning.valueInteger != 0) )
    {
      v41 = (2 * (r_forceDualQuatSkinning.valueInteger != 0)) & 2 | v40 & 0xFD;
      v42 = (v41 & 2) != 0;
      *((_BYTE *)this + 2164) = v41;
      this->jointBuffers.ptr[0].flags = v42;
      this->jointBuffers.ptr[1].flags = v42;
      this->jointBuffers.ptr[2].flags = v42;
      this->jointBuffers.ptr[3].flags = v42;
    }
    nextRenderThreadJointBuffer = this->nextRenderThreadJointBuffer;
    deferredJobJointBuffer = this->deferredJobJointBuffer;
    v45 = (nextRenderThreadJointBuffer + 1) % 4;
    if ( deferredJobJointBuffer == v45 )
    {
      if ( nextRenderThreadJointBuffer == this->renderThreadJointBuffer )
      {
        if ( this->jointBuffers.ptr[v45].numJoints < 0 )
        {
          idLib::Warning(fmt: "More than one deferred blend on a single frame: %s", this->name.str);
          v47 = (v45 + 1) % 4;
          if ( this->jointBuffers.ptr[v47].numJoints >= 0 && v47 != this->renderThreadJointBuffer )
            v45 = (v45 + 1) % 4;
          v48 = (v45 + 2) % 4;
          if ( this->jointBuffers.ptr[v48].numJoints >= 0 && v48 != this->renderThreadJointBuffer )
            v45 = (v45 + 2) % 4;
          v49 = (v45 + 3) % 4;
          if ( this->jointBuffers.ptr[v49].numJoints >= 0 && v49 != this->renderThreadJointBuffer )
            v45 = (v45 + 3) % 4;
          if ( this->jointBuffers.ptr[v45].numJoints < 0 )
          {
            idLib::Warning(
              fmt: "idTreeAnimator::BlendTree: to many animblends to single target in single frame to recover at all: %s",
              this->name.str);
            return;
          }
        }
      }
      else
      {
        idJointBuffer::Swap(
          this: &this->jointBuffers.ptr[nextRenderThreadJointBuffer],
          other: &this->jointBuffers.ptr[deferredJobJointBuffer]);
      }
    }
    this->deferredJobJointBuffer = v45;
    if ( currentTime - previousTime >= 0 )
    {
      v46 = gameMsPerFrame;
      if ( currentTime - previousTime <= gameMsPerFrame )
        v46 = currentTime - previousTime;
    }
    else
    {
      v46 = 0;
    }
    this->translatedBounds.b[0].z = 1.0e30;
    this->translatedBounds.b[0].y = 1.0e30;
    this->translatedBounds.b[0].x = 1.0e30;
    this->translatedBounds.b[1].z = -1.0e30;
    this->translatedBounds.b[1].y = -1.0e30;
    this->translatedBounds.b[1].x = -1.0e30;
    this->normalizedBounds.b[0].z = 1.0e30;
    this->normalizedBounds.b[0].y = 1.0e30;
    this->normalizedBounds.b[0].x = 1.0e30;
    this->normalizedBounds.b[1].z = -1.0e30;
    this->normalizedBounds.b[1].y = -1.0e30;
    this->normalizedBounds.b[1].x = -1.0e30;
    v50 = (*((_BYTE *)this + 2164) & 0x40) != 0;
    if ( (*((_BYTE *)this + 2164) & 0x20) != 0 )
      v50 |= 2u;
    this->blendParms->skeleton = this->decl->model->skeleton->data;
    this->blendParms->config = this->decl->config;
    this->blendParms->cmds = this->commands;
    this->blendParms->numCmds = ParseTree(
                                  model: this->decl->model,
                                  lastTimeMSec: currentTime - v46,
                                  timeMSec: currentTime,
                                  ticksPerSec,
                                  tree,
                                  cmds: this->commands,
                                  maxCmds: 128,
                                  frameBounds: &v116,
                                  translatedBounds: v92,
                                  normalizedBounds: v94,
                                  originDelta: v96,
                                  animatorFlags: v97,
                                  a13: v98,
                                  a14: v99,
                                  a15: v100,
                                  a16: v101,
                                  a17: v102,
                                  a18: v103,
                                  a19: v104,
                                  a20: v105,
                                  a21: v106,
                                  a22: v107,
                                  a23: v108,
                                  a24: v109,
                                  a25: v110,
                                  a26: v111,
                                  a27: v112,
                                  a28: &this->translatedBounds,
                                  a29: v113,
                                  a30: &this->normalizedBounds,
                                  a31: v114,
                                  a32: (int)this->originDelta[0],
                                  a33: v115,
                                  a34: v50);
    if ( this->decl->calcRefBoundsFromJoints || (v51 = 0, (*((_BYTE *)this + 2164) & 0x10) != 0) )
      v51 = 1;
    v52 = v51;
    if ( v51 == 0 )
    {
      x = v116.b[0].x;
      v54 = v116.b[1].x;
      if ( v116.b[0].x <= (double)v116.b[1].x && (unsigned __int8)idBounds::IsZero(this: &v116) == 0 )
      {
        y = v116.b[0].y;
        z = v116.b[0].z;
        this->frameBounds.b[0].x = x;
        v57 = v116.b[1].y;
        this->frameBounds.b[0].y = y;
        this->frameBounds.b[0].z = z;
        this->frameBounds.b[1].x = v54;
        v58 = v116.b[1].z;
        this->frameBounds.b[1].y = v57;
        this->frameBounds.b[1].z = v58;
        idTreeAnimator::CalcFrameBoundsFromJoints(this);
      }
    }
    this->blendParms->mods = this->jointMods[this->currentDeferred].list;
    this->blendParms->numMods = this->jointMods[this->currentDeferred].num;
    skeleton = this->decl->model->skeleton;
    if ( skeleton != nullptr )
      skeleton = (const idMD6Skel *)((char *)skeleton->data + skeleton->data->inverseBasePoseOffset);
    this->blendParms->invertedBasePose = (const float *)skeleton;
    v60 = this->decl->model->skeleton;
    if ( v60 != nullptr )
      v60 = (const idMD6Skel *)((char *)v60->data + v60->data->inverseBasePoseQuatOffset);
    this->blendParms->invertedBasePoseQuat = (const float *)v60;
    this->blendParms->jointRemap = this->decl->model->jointRemap.list;
    this->blendParms->referencePose = this->joints[2]->mat;
    this->blendParms->finalPose = this->joints[3]->mat;
    this->blendParms->renderPose = idJointBuffer::MapBuffer(
                                     this: &this->jointBuffers.ptr[this->deferredJobJointBuffer],
                                     mapType: BM_WRITE_NOSYNC);
    this->blendParms->clearOriginTransform = (*((_BYTE *)this + 2164) & 0x40) != 0;
    this->blendParms->flags = (*((_BYTE *)this + 2164) & 2) != 0;
    this->blendParms->originDelta = this->originDelta[0];
    this->blendParms->originDelta->time = currentTime;
    blendParms = this->blendParms;
    blendParms->originDelta->done = false;
    v62 = this->blendParms;
    currentDeferred = this->currentDeferred;
    v64 = (char *)this + 16 * currentDeferred;
    v65 = *((_DWORD *)v64 + 530);
    v62->userChannels = (float *)v65;
    v66 = this->blendParms;
    value = (unsigned __int16)this->skipJointForBounds.value;
    v66->boundsSkipJoint.value = value;
    if ( localR != nullptr )
    {
      AnimationBlendJobToRSTU(
        blendParms: this->blendParms,
        localR,
        localS: a28,
        localT: a30,
        localU: a32,
        a6: (int)v64,
        a7: currentDeferred,
        a8: (int)v62,
        a9: v93,
        a10: v95);
      v68 = (idPixelUnpackBuffer *)&this->jointBuffers.ptr[this->deferredJobJointBuffer];
      if ( v68->size < 0 )
        idVertexBuffer::UnmapBuffer(this: v68);
      v69 = (idPixelUnpackBuffer *)&this->jointBuffers.ptr[this->renderThreadJointBuffer];
      if ( v69->size < 0 )
        idVertexBuffer::UnmapBuffer(this: v69);
      *((_BYTE *)this + 2164) &= ~0x80u;
    }
    else if ( parallelJobList == nullptr
           || (v62 = (idMD6Blend::blendParms_t *)&r_forceNonDeferredAnimBlend,
               r_forceNonDeferredAnimBlend.valueInteger != 0) )
    {
      AnimationBlendJob(
        blendParms: this->blendParms,
        a2: (int)blendParms,
        a3: value,
        a4: (int)v66,
        a5: v65,
        a6: (int)v64,
        a7: currentDeferred,
        a8: (int)v62,
        a9: v93,
        a10: v95);
      v70 = 48 * ((this->decl->model->skeleton->data->numJoints + 7) & 0xFFF8);
      memcpy(Dst: this->joints[0], Src: this->joints[2], Size: v70);
      memcpy(Dst: this->joints[1], Src: this->joints[3], Size: v70);
      v71 = (_QWORD *)&this->originDelta[1][-1].jointBounds[4];
      v72 = 16;
      v73 = (_QWORD *)&this->originDelta[0][-1].jointBounds[4];
      do
      {
        *++v71 = *++v73;
        --v72;
      }
      while ( v72 != 0 );
      idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->jointBuffers.ptr[this->deferredJobJointBuffer]);
      *((_BYTE *)this + 2164) &= ~0x80u;
    }
    else
    {
      if ( r_useAnimBlendJobs.valueInteger == 1 )
        idParallelJobList::AddJob(
          this: parallelJobList,
          function: (void (__fastcall *)(void *))AnimationBlendJob,
          data: this->blendParms);
      else
        AnimationBlendJob(
          blendParms: this->blendParms,
          a2: (int)blendParms,
          a3: value,
          a4: (int)v66,
          a5: v65,
          a6: (int)v64,
          a7: currentDeferred,
          a8: (int)&r_useAnimBlendJobs,
          a9: v93,
          a10: v95);
      v52 = 0;
      *((_BYTE *)this + 2164) |= 0x80u;
    }
    if ( v52 != 0 )
    {
      v74 = this->originDelta[1];
      p_frameBounds = &this->frameBounds;
      v76 = v74->jointBounds[3];
      v77 = v74->jointBounds[5];
      v78 = v74->jointBounds[0];
      v79 = v74->jointBounds[4];
      v80 = v74->jointBounds[2];
      v81 = v74->jointBounds[1];
      this->frameBounds.b[0].x = v74->jointBounds[0];
      this->frameBounds.b[1].z = v77;
      this->frameBounds.b[0].y = v81;
      this->frameBounds.b[0].z = v80;
      this->frameBounds.b[1].x = v76;
      this->frameBounds.b[1].y = v79;
      if ( v78 <= v76 )
      {
        v82 = this->frameBounds.b[0].y;
        v83 = this->frameBounds.b[0].z;
        model = this->decl->model;
        p_frameBounds->b[0].x = p_frameBounds->b[0].x + model->minBoundsExpansion.x;
        this->frameBounds.b[0].y = model->minBoundsExpansion.y + (float)v82;
        this->frameBounds.b[0].z = model->minBoundsExpansion.z + (float)v83;
        v85 = this->frameBounds.b[1].y;
        v86 = this->frameBounds.b[1].z;
        this->frameBounds.b[1].x = model->maxBoundsExpansion.x + this->frameBounds.b[1].x;
        this->frameBounds.b[1].y = model->maxBoundsExpansion.y + (float)v85;
        this->frameBounds.b[1].z = model->maxBoundsExpansion.z + (float)v86;
      }
      v87 = this->frameBounds.b[0].y;
      v88 = this->frameBounds.b[0].z;
      config = this->decl->config;
      p_frameBounds->b[0].x = p_frameBounds->b[0].x + config->visualOffset[0];
      this->frameBounds.b[0].y = config->visualOffset[1] + (float)v87;
      this->frameBounds.b[0].z = config->visualOffset[2] + (float)v88;
      v90 = this->frameBounds.b[1].y;
      this->frameBounds.b[1].x = this->frameBounds.b[1].x + config->visualOffset[0];
      this->frameBounds.b[1].y = config->visualOffset[1] + (float)v90;
      this->frameBounds.b[1].z = this->frameBounds.b[1].z + config->visualOffset[2];
    }
    v91 = this->currentDeferred ^ 1;
    this->currentDeferred = v91;
    idList<idMD6Blend::jointMod_t,17>::SetNum(this: &this->jointMods[v91], newNum: 0);
  }
}


// ========================================================================
// ?ClearJointMods@idTreeAnimator@@QAAXXZ
// EA  : 0x82863830
// RVA : 0x00863830
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::ClearJointMods(idTreeAnimator *this)
{
  char *v1; // r11
  char *v2; // r31

  v1 = (char *)this + 16 * this->currentDeferred;
  v2 = v1 + 2068;
  if ( *((int *)v1 + 519) < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v1 + 2068));
  *((_DWORD *)v2 + 1) = __CFADD__(-*((_DWORD *)v2 + 2), *((_DWORD *)v2 + 2) ^ 0x80000000) ? 0 : *((_DWORD *)v2 + 2);
}


// ========================================================================
// ?SetJointMat3x4@idTreeAnimator@@QAAXW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidMat3x4@@_N@Z
// EA  : 0x82863910
// RVA : 0x00863910
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetJointMat3x4(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const jointModTransform_t type,
        const idMat3x4 *mat,
        bool setPos)
{
  __int16 v7; // r30
  __int16 v12; // r11

  v7 = (__int16)jointIndex;
  _R3 = idList<idMD6Blend::jointMod_t,17>::Alloc(this: &this->jointMods[this->currentDeferred]);
  __asm { dcbt      0, r3 }
  v12 = 130;
  if ( setPos )
    v12 = 138;
  if ( (type == JOINTMOD_MODEL || type == JOINTMOD_MODEL_OVERRIDE) && (v12 |= 1u, type == JOINTMOD_MODEL_OVERRIDE)
    || type == JOINTMOD_LOCAL_OVERRIDE )
  {
    v12 |= 0x20u;
  }
  if ( pose == 0 )
    v12 |= 0x40u;
  _R3->joint.value = v7;
  _R3->flags = v12;
  memcpy(Dst: (void *)_R3, Src: mat, Size: 0x30u);
}


// ========================================================================
// ?SetJointPosAxisScale@idTreeAnimator@@QAAXW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidVec3@@ABVidMat3@@3@Z
// EA  : 0x828639B8
// RVA : 0x008639B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetJointPosAxisScale(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const jointModTransform_t type,
        const idVec3 *pos,
        const idMat3 *axis,
        const idVec3 *scale)
{
  __int16 v8; // r27
  __int16 v14; // r11

  v8 = (__int16)jointIndex;
  _R3 = idList<idMD6Blend::jointMod_t,17>::Alloc(this: &this->jointMods[this->currentDeferred]);
  __asm { dcbt      0, r3 }
  v14 = 142;
  if ( (type == JOINTMOD_MODEL || type == JOINTMOD_MODEL_OVERRIDE) && (v14 = 143, type == JOINTMOD_MODEL_OVERRIDE)
    || type == JOINTMOD_LOCAL_OVERRIDE )
  {
    v14 |= 0x20u;
  }
  if ( pose == 0 )
    v14 |= 0x40u;
  _R3->joint.value = v8;
  _R3->flags = v14;
  _R3->mat[3] = pos->x;
  _R3->mat[7] = pos->y;
  _R3->mat[11] = pos->z;
  _R3->mat[0] = axis->mat[0].x;
  _R3->mat[1] = axis->mat[1].x;
  _R3->mat[2] = axis->mat[2].x;
  _R3->mat[4] = axis->mat[0].y;
  _R3->mat[5] = axis->mat[1].y;
  _R3->mat[6] = axis->mat[2].y;
  _R3->mat[8] = axis->mat[0].z;
  _R3->mat[9] = axis->mat[1].z;
  _R3->mat[10] = axis->mat[2].z;
  _R3->s[0] = scale->x;
  _R3->s[1] = scale->y;
  _R3->s[2] = scale->z;
}


// ========================================================================
// ?SetJointPos@idTreeAnimator@@QAAXW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidVec3@@@Z
// EA  : 0x82863AC0
// RVA : 0x00863AC0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetJointPos(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const jointModTransform_t type,
        const idVec3 *pos)
{
  __int16 v6; // r29
  __int16 v10; // r11

  v6 = (__int16)jointIndex;
  _R3 = idList<idMD6Blend::jointMod_t,17>::Alloc(this: &this->jointMods[this->currentDeferred]);
  __asm { dcbt      0, r3 }
  v10 = 136;
  if ( (type == JOINTMOD_MODEL || type == JOINTMOD_MODEL_OVERRIDE) && (v10 = 137, type == JOINTMOD_MODEL_OVERRIDE)
    || type == JOINTMOD_LOCAL_OVERRIDE )
  {
    v10 |= 0x20u;
  }
  if ( pose == 0 )
    v10 |= 0x40u;
  _R3->joint.value = v6;
  _R3->flags = v10;
  _R3->mat[3] = pos->x;
  _R3->mat[7] = pos->y;
  _R3->mat[11] = pos->z;
}


// ========================================================================
// ?SetJointAxis@idTreeAnimator@@QAAXW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidMat3@@@Z
// EA  : 0x82863B60
// RVA : 0x00863B60
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetJointAxis(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const jointModTransform_t type,
        const idMat3 *axis)
{
  __int16 v6; // r29
  __int16 v10; // r11

  v6 = (__int16)jointIndex;
  _R3 = idList<idMD6Blend::jointMod_t,17>::Alloc(this: &this->jointMods[this->currentDeferred]);
  __asm { dcbt      0, r3 }
  v10 = 130;
  if ( (type == JOINTMOD_MODEL || type == JOINTMOD_MODEL_OVERRIDE) && (v10 = 131, type == JOINTMOD_MODEL_OVERRIDE)
    || type == JOINTMOD_LOCAL_OVERRIDE )
  {
    v10 |= 0x20u;
  }
  if ( pose == 0 )
    v10 |= 0x40u;
  _R3->joint.value = v6;
  _R3->flags = v10;
  _R3->mat[0] = axis->mat[0].x;
  _R3->mat[1] = axis->mat[1].x;
  _R3->mat[2] = axis->mat[2].x;
  _R3->mat[4] = axis->mat[0].y;
  _R3->mat[5] = axis->mat[1].y;
  _R3->mat[6] = axis->mat[2].y;
  _R3->mat[8] = axis->mat[0].z;
  _R3->mat[9] = axis->mat[1].z;
  _R3->mat[10] = axis->mat[2].z;
}


// ========================================================================
// ?SetJointScale@idTreeAnimator@@QAAXW4animationPose_t@@V?$idIndex@FW4invalidJointIndex_t@@@@W4jointModTransform_t@@ABVidVec3@@@Z
// EA  : 0x82863C30
// RVA : 0x00863C30
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::SetJointScale(
        idTreeAnimator *this,
        animationPose_t pose,
        const idIndex<short,enum invalidJointIndex_t> *jointIndex,
        const jointModTransform_t type,
        const idVec3 *scale)
{
  __int16 v6; // r29
  __int16 v10; // r11

  v6 = (__int16)jointIndex;
  _R3 = idList<idMD6Blend::jointMod_t,17>::Alloc(this: &this->jointMods[this->currentDeferred]);
  __asm { dcbt      0, r3 }
  v10 = 132;
  if ( (type == JOINTMOD_MODEL || type == JOINTMOD_MODEL_OVERRIDE) && (v10 = 133, type == JOINTMOD_MODEL_OVERRIDE)
    || type == JOINTMOD_LOCAL_OVERRIDE )
  {
    v10 |= 0x20u;
  }
  if ( pose == 0 )
    v10 |= 0x40u;
  _R3->joint.value = v6;
  _R3->flags = v10;
  _R3->s[0] = scale->x;
  _R3->s[1] = scale->y;
  _R3->s[2] = scale->z;
}


// ========================================================================
// ??0idTreeAnimator@@QAA@PBVidDeclMD6@@@Z
// EA  : 0x82863D98
// RVA : 0x00863D98
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idTreeAnimator *__fastcall idTreeAnimator::idTreeAnimator(idTreeAnimator *this, const idDeclMD6 *declMD6)
{
  __int64 v2; // r26
  char v5; // r11
  const idDeclMD6 *decl; // r8
  const idMD6Model *model; // r18
  const idMD6Skel *skeleton; // r19
  float v9; // r11
  __int16 v10; // r9
  unsigned int v11; // r24
  idMD6SkelData *data; // r9
  int v13; // r11
  int v14; // r10
  md6OriginDelta_t *v15; // r3
  md6OriginDelta_t *v16; // r11
  md6OriginDelta_t *v17; // r11
  md6OriginDelta_t *v18; // r11
  md6OriginDelta_t *v19; // r11
  md6OriginDelta_t *v20; // r11
  idMD6Blend::blendParms_t *v21; // r3
  md6OriginDelta_t *v22; // r5
  int v23; // r11
  int i; // ctr
  const idDeclMD6 *v25; // r10
  idJointMat *v26; // r8
  const idMD6SkelData *v27; // r3
  int v28; // r12
  const idMD6Skel *v29; // r11
  const float *v30; // r7
  const float *v31; // r6
  int *p_flags; // r25
  int v33; // r22
  BOOL v34; // r20
  float *p_referenceBounds; // r11
  float *v36; // r11
  idVec3 *v37; // r6
  double v38; // fp7
  float *v39; // r11
  idVec3 *v40; // r5
  double v41; // fp1
  float *v42; // r11
  idVec3 *v43; // r4
  double v44; // fp9
  double v45; // fp7
  int num; // r29
  int size; // r11
  int v48; // r11
  int j; // ctr
  meshKitComponents_t v50; // r29
  int *p_num; // r28
  const idDeclMD6 *v52; // r11
  const idDeclMD6 *v53; // r7
  const idMD6Model *v54; // r11
  char v55; // r6
  int v56; // r10
  idMD6Mesh **list; // r8
  int v58; // r11
  idList<idStr,5> *p_wrinkleMapRegionExpressions; // r27
  int v60; // r29
  int v61; // r11
  int v62; // r28
  int v63; // r29
  const char **v64; // r11
  _DWORD back_chain[20]; // [sp+0h] [-120h]
  float v67; // [sp+50h] [-D0h] BYREF
  idStr v68; // [sp+60h] [-C0h] BYREF

  idRenderModel::idRenderModel(this);
  this->decl = declMD6;
  LODWORD(v2) = 0;
  this->__vftable = (idTreeAnimator_vtbl *)&idTreeAnimator::`vftable';
  this->meshVisibility.list = nullptr;
  this->meshVisibility.granularity = 0;
  this->meshVisibility.memTag = 17;
  this->meshVisibility.listStatic = 0;
  this->meshVisibility.size = 0;
  this->meshVisibility.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->meshVisibility);
  this->morphSkin = -1;
  this->skipJointForBounds.value = -1;
  this->currentDeferred = 0;
  this->initialMorphValue = 0.0;
  LODWORD(v67) = &this->skipJointForBounds;
  `eh vector constructor iterator'(
    ptr: this->jointMods,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<float,17>::idList<float,17>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  *(_QWORD *)this->joints = v2;
  *(_QWORD *)&this->joints[2] = v2;
  `eh vector constructor iterator'(
    ptr: this->userChannels,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<float,17>::idList<float,17>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  v5 = *((_BYTE *)this + 2164);
  this->lastBlendTime = -1;
  *((_BYTE *)this + 2164) = v5 & 1 | 0x40;
  `eh vector constructor iterator'(
    ptr: &this->jointBuffers,
    size: 0x10u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idJointBuffer::idJointBuffer,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  `eh vector constructor iterator'(
    ptr: this->userChannelBuffers,
    size: 0x10u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idList<idVehicleKey *,5>::idList<idVehicleKey *,5>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->deferredJobJointBuffer = -1;
  this->nextRenderThreadJointBuffer = 0;
  this->renderThreadJointBuffer = 0;
  this->morphMaps.list = nullptr;
  this->morphMaps.granularity = 0;
  this->morphMaps.memTag = 16;
  this->morphMaps.listStatic = 0;
  this->morphMaps.size = 0;
  this->morphMaps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->morphMaps);
  this->currentMorphBuffer = 0;
  this->wrinkleMapExpressions.granularity = 0;
  this->wrinkleMapExpressions.memTag = 5;
  this->wrinkleMapExpressions.listStatic = 0;
  this->wrinkleMapExpressions.list = nullptr;
  this->wrinkleMapExpressions.size = 0;
  this->wrinkleMapExpressions.num = 0;
  LODWORD(v67) = &this->normalizedBounds;
  this->frameBounds.b[0].z = 1.0e30;
  this->frameBounds.b[0].y = 1.0e30;
  this->frameBounds.b[0].x = 1.0e30;
  this->frameBounds.b[1].z = -1.0e30;
  this->frameBounds.b[1].y = -1.0e30;
  this->frameBounds.b[1].x = -1.0e30;
  this->translatedBounds.b[0].z = 1.0e30;
  this->translatedBounds.b[0].y = 1.0e30;
  this->translatedBounds.b[0].x = 1.0e30;
  this->translatedBounds.b[1].z = -1.0e30;
  this->translatedBounds.b[1].y = -1.0e30;
  this->translatedBounds.b[1].x = -1.0e30;
  this->normalizedBounds.b[0].z = 1.0e30;
  this->normalizedBounds.b[0].y = 1.0e30;
  this->normalizedBounds.b[0].x = 1.0e30;
  this->normalizedBounds.b[1].z = -1.0e30;
  this->normalizedBounds.b[1].y = -1.0e30;
  this->normalizedBounds.b[1].x = -1.0e30;
  this->useDeferredPosition = true;
  idStr::idStr(this: &v68, text: this->decl->name.str);
  idStr::SetFileExtension(this: &v68, extension: ".md6");
  idRenderModel::SetName(this, name_: v68.data);
  decl = this->decl;
  this->g.castDimShadows = DIMSHADOW_ON;
  model = decl->model;
  if ( model == nullptr )
    idLib::Error(fmt: "md6 model has been purged");
  skeleton = model->skeleton;
  v9 = *(float *)&skeleton->data;
  if ( ((*(unsigned __int16 *)(LODWORD(v9) + 2) + 7) & 0xFFF8) == 0 )
    idLib::Error(fmt: "md6 model '%s' has no joints", model->name.str);
  v10 = *(_WORD *)(LODWORD(v9) + 2);
  v67 = v9;
  v11 = 48 * ((v10 + 7) & 0xFFF8);
  this->joints[0] = (idJointMat *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(133) : TAG_MD6_JOINTBUFFERS",
                                    size: v11,
                                    tag: TAG_MD6_JOINTBUFFERS,
                                    zeroBuffer: false,
                                    align: ALIGN_128,
                                    heap: HEAP_DEFAULTHEAP);
  this->joints[1] = (idJointMat *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(134) : TAG_MD6_JOINTBUFFERS",
                                    size: v11,
                                    tag: TAG_MD6_JOINTBUFFERS,
                                    zeroBuffer: false,
                                    align: ALIGN_128,
                                    heap: HEAP_DEFAULTHEAP);
  this->joints[2] = (idJointMat *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(135) : TAG_MD6_JOINTBUFFERS",
                                    size: v11,
                                    tag: TAG_MD6_JOINTBUFFERS,
                                    zeroBuffer: false,
                                    align: ALIGN_128,
                                    heap: HEAP_DEFAULTHEAP);
  this->joints[3] = (idJointMat *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(136) : TAG_MD6_JOINTBUFFERS",
                                    size: v11,
                                    tag: TAG_MD6_JOINTBUFFERS,
                                    zeroBuffer: false,
                                    align: ALIGN_128,
                                    heap: HEAP_DEFAULTHEAP);
  idList<float,5>::SetNum(
    this: (idList<float,5> *)&this->userChannels[1],
    newNum: (skeleton->data->numUserChannels + 7) & 0xFFF8);
  idList<float,5>::SetNum(
    this: (idList<float,5> *)this->userChannels,
    newNum: (skeleton->data->numUserChannels + 7) & 0xFFF8);
  data = skeleton->data;
  v13 = 0;
  if ( ((data->numUserChannels + 7) & 0xFFF8) != 0 )
  {
    v14 = 0;
    do
    {
      ++v13;
      this->userChannels[1].list[v14] = 0.0;
      this->userChannels[0].list[v14++] = 0.0;
    }
    while ( v13 < ((data->numUserChannels + 7) & 0xFFF8) );
  }
  this->originDelta[1] = (md6OriginDelta_t *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(145) : TAG_MD6_MISC",
                                               size: 0x80u,
                                               tag: TAG_MD6_MISC,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
  v15 = (md6OriginDelta_t *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(146) : TAG_MD6_MISC",
                              size: 0x80u,
                              tag: TAG_MD6_MISC,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  this->originDelta[0] = v15;
  v15->deltaRotation[1] = 0.0;
  v15->deltaRotation[2] = 0.0;
  v15->deltaRotation[0] = 0.0;
  v67 = *(float *)&v15;
  v15->deltaRotation[3] = 1.0;
  v16 = this->originDelta[0];
  v16->deltaScale[1] = 1.0;
  v16->deltaScale[3] = 1.0;
  v16->deltaScale[2] = 1.0;
  v16->deltaScale[0] = 1.0;
  v17 = this->originDelta[0];
  v17->deltaTranslation[3] = 0.0;
  v17->deltaTranslation[2] = 0.0;
  v17->deltaTranslation[1] = 0.0;
  v17->deltaTranslation[0] = 0.0;
  v18 = this->originDelta[0];
  v18->animRotation[2] = 0.0;
  v18->animRotation[1] = 0.0;
  v18->animRotation[0] = 0.0;
  v18->animRotation[3] = 1.0;
  v19 = this->originDelta[0];
  v19->animScale[3] = 1.0;
  v19->animScale[2] = 1.0;
  v19->animScale[1] = 1.0;
  v19->animScale[0] = 1.0;
  v20 = this->originDelta[0];
  v20->animTranslation[3] = 0.0;
  v20->animTranslation[0] = 0.0;
  v20->animTranslation[2] = 0.0;
  v20->animTranslation[1] = 0.0;
  this->originDelta[0]->time = -1;
  this->originDelta[0]->done = true;
  memcpy(Dst: this->originDelta[1], Src: this->originDelta[0], Size: sizeof(md6OriginDelta_t));
  v21 = (idMD6Blend::blendParms_t *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(159) : TAG_MD6_MISC",
                                      size: 0x44u,
                                      tag: TAG_MD6_MISC,
                                      zeroBuffer: true,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  v22 = this->originDelta[0];
  this->blendParms = v21;
  v21->originDelta = v22;
  this->commands = (md6AnimCommand_t *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\models\\skeletalanimation\\TreeAnimator.cpp(162) : TAG_MD6_MISC",
                                         size: 0x2000u,
                                         tag: TAG_MD6_MISC,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  v23 = 0;
  for ( i = 128; i != 0; --i )
    this->commands[v23++].op = OP_END;
  ((void (*)(void))RtlCheckStack12)();
  v25 = this->decl;
  v26 = this->joints[0];
  v27 = skeleton->data;
  *(_DWORD *)((char *)back_chain + v28) = back_chain[0];
  idMD6Blend::DecodeBasePose(
    skeleton: v27,
    temp: &v67,
    tempSize: 0x4000u,
    originOffset: v25->config->visualOffset,
    offsetAdd: 1u,
    outPose: v26->mat);
  v29 = model->skeleton;
  if ( v29 != nullptr )
    v30 = (const float *)((char *)&v29->data->size + v29->data->inverseBasePoseQuatOffset);
  else
    v30 = nullptr;
  if ( v29 != nullptr )
    v31 = (const float *)((char *)&v29->data->size + v29->data->inverseBasePoseOffset);
  else
    v31 = nullptr;
  idMD6Blend::TransformModelMatrices(
    skeleton: skeleton->data,
    remap: model->jointRemap.list,
    inMatrices1: this->joints[0]->mat,
    inMatrices2: v31,
    invertedRefPoseQuat: v30,
    outMatrices: this->joints[2]->mat,
    useDualQuat: false,
    quatTemp: nullptr);
  p_flags = &this->jointBuffers.ptr[0].flags;
  v33 = 4;
  v34 = (*((_BYTE *)this + 2164) & 2) != 0;
  do
  {
    idJointBuffer::AllocBufferObject(
      this: (idJointBuffer *)(p_flags - 3),
      joints: this->joints[2]->mat,
      numAllocJoints: v11 / 0x30);
    *p_flags = v34;
    --v33;
    p_flags += 4;
  }
  while ( v33 != 0 );
  memcpy(Dst: this->joints[1], Src: this->joints[0], Size: v11);
  memcpy(Dst: this->joints[2], Src: this->joints[0], Size: v11);
  memcpy(Dst: this->joints[3], Src: this->joints[0], Size: v11);
  LODWORD(v67) = &this->translatedBounds;
  p_referenceBounds = (float *)&this->decl->referenceBounds;
  LODWORD(v67) = &this->decl->referenceBounds.b[1];
  this->referenceBounds.b[0].x = *p_referenceBounds;
  this->referenceBounds.b[0].y = p_referenceBounds[1];
  this->referenceBounds.b[0].z = p_referenceBounds[2];
  this->referenceBounds.b[1].x = p_referenceBounds[3];
  this->referenceBounds.b[1].y = p_referenceBounds[4];
  this->referenceBounds.b[1].z = p_referenceBounds[5];
  v36 = (float *)&this->decl->referenceBounds;
  v37 = &this->decl->referenceBounds.b[1];
  this->frameBounds.b[0].x = *v36;
  v38 = v36[1];
  v67 = *(float *)&v37;
  this->frameBounds.b[0].y = v38;
  this->frameBounds.b[0].z = v36[2];
  this->frameBounds.b[1].x = v36[3];
  this->frameBounds.b[1].y = v36[4];
  this->frameBounds.b[1].z = v36[5];
  v39 = (float *)&this->decl->referenceBounds;
  v40 = &this->decl->referenceBounds.b[1];
  this->normalizedBounds.b[0].x = *v39;
  v41 = v39[1];
  v67 = *(float *)&v40;
  this->normalizedBounds.b[0].y = v41;
  this->normalizedBounds.b[0].z = v39[2];
  this->normalizedBounds.b[1].x = v39[3];
  this->normalizedBounds.b[1].y = v39[4];
  this->normalizedBounds.b[1].z = v39[5];
  v42 = (float *)&this->decl->referenceBounds;
  v43 = &this->decl->referenceBounds.b[1];
  this->translatedBounds.b[0].x = *v42;
  v44 = v42[1];
  v67 = *(float *)&v43;
  this->translatedBounds.b[0].y = v44;
  this->translatedBounds.b[0].z = v42[2];
  v45 = v42[3];
  LODWORD(v67) = &this->translatedBounds.b[1];
  this->translatedBounds.b[1].x = v45;
  this->translatedBounds.b[1].y = v42[4];
  this->translatedBounds.b[1].z = v42[5];
  num = model->meshes.num;
  if ( num > this->meshVisibility.size )
    idList<unsigned char,25>::Resize(
      this: (idList<unsigned char,37> *)&this->meshVisibility,
      newsize: model->meshes.num);
  if ( num <= this->meshVisibility.size
    || idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&this->meshVisibility, newsize: num) )
  {
    size = this->meshVisibility.size;
    if ( num < size )
      size = num;
    this->meshVisibility.num = size;
  }
  v48 = 0;
  if ( num > 0 )
  {
    for ( j = num; j != 0; --j )
      this->meshVisibility.list[v48++] = true;
  }
  v50 = MESH_KIT_HEADS;
  p_num = &declMD6->meshKitGroups[1].num;
  do
  {
    p_num += 8;
    idTreeAnimator::HideKitsExcept(this, kitType: v50++, name: (const char *)*p_num);
  }
  while ( v50 < MESH_KIT_NUM );
  v52 = this->decl;
  this->morphSkin = model->morphSkin;
  if ( v52 != nullptr && v52->morphVertices != nullptr )
    idTreeAnimator::SetMorphSkin(this, skinName: nullptr, skinIndex: -1, morphAmount: 0.0);
  idTreeAnimator::HideAllKits(this, kitType: MESH_KIT_GORE);
  v53 = this->decl;
  if ( v53->wrinkleMapRegionExpressions.num != 0 )
  {
    v54 = v53->model;
    v55 = 0;
    v56 = 0;
    v67 = *(float *)&v54->meshes.num;
    if ( SLODWORD(v67) > 0 )
    {
      list = v54->meshes.list;
      v58 = 0;
      while ( (*((_BYTE *)list[v58]->material + 72) & 1) == 0 )
      {
        ++v56;
        ++v58;
        if ( v56 >= SLODWORD(v67) )
          goto LABEL_40;
      }
      v55 = 1;
    }
LABEL_40:
    if ( v55 != 0 )
    {
      p_wrinkleMapRegionExpressions = &v53->wrinkleMapRegionExpressions;
      v60 = v53->wrinkleMapRegionExpressions.num;
      if ( v60 <= this->wrinkleMapExpressions.size
        || (unsigned __int8)idList<idUserChannelExpression,5>::Resize(
                              this: &this->wrinkleMapExpressions,
                              newsize: v53->wrinkleMapRegionExpressions.num) != 0 )
      {
        v61 = this->wrinkleMapExpressions.size;
        if ( v60 < v61 )
          v61 = v60;
        this->wrinkleMapExpressions.num = v61;
      }
      v62 = 0;
      if ( p_wrinkleMapRegionExpressions->num > 0 )
      {
        v63 = 0;
        do
        {
          v64 = (const char **)((char *)p_wrinkleMapRegionExpressions->list + v2);
          if ( (int)*v64 > 0 )
            idUserChannelExpression::Parse(
              this: &this->wrinkleMapExpressions.list[v63],
              exprStr: v64[1],
              decl: this->decl);
          ++v62;
          LODWORD(v2) = v2 + 32;
          ++v63;
        }
        while ( v62 < p_wrinkleMapRegionExpressions->num );
      }
    }
  }
  idStr::FreeData(this: &v68);
  return this;
}


// ========================================================================
// $LN393
// EA  : 0x828646FC
// RVA : 0x008646FC
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _LN393()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 288 + 308));
}


// ========================================================================
// __unwind$250468
// EA  : 0x82864724
// RVA : 0x00864724
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250468()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 2036));
}


// ========================================================================
// __unwind$250469
// EA  : 0x82864750
// RVA : 0x00864750
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250469()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 288 + 308) + 2068),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$250470
// EA  : 0x8286478C
// RVA : 0x0086478C
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250470()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 288 + 308) + 2120),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$250471
// EA  : 0x828647C8
// RVA : 0x008647C8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250471()
{
  int v0; // r12

  idArray<idJointBuffer,4>::~idArray<idJointBuffer,4>(this: (idArray<idJointBuffer,4> *)(*(_DWORD *)(v0 - 288 + 308)
                                                                                       + 2240));
}


// ========================================================================
// __unwind$250472
// EA  : 0x828647F4
// RVA : 0x008647F4
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250472()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 288 + 308) + 2304),
    size: 0x10u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$250473
// EA  : 0x82864830
// RVA : 0x00864830
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250473()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 2380));
}


// ========================================================================
// __unwind$250474
// EA  : 0x8286485C
// RVA : 0x0086485C
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250474()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 288 + 308) + 2400));
}


// ========================================================================
// __unwind$250475
// EA  : 0x82864888
// RVA : 0x00864888
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_250475()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// ??1idTreeAnimator@@MAA@XZ
// EA  : 0x828648B8
// RVA : 0x008648B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __fastcall idTreeAnimator::~idTreeAnimator(idTreeAnimator *this)
{
  int v2; // r29
  idArray<idJointBuffer,4> *p_jointBuffers; // r28
  char *list; // r3
  idTreeAnimator::morphMap_t *v5; // r4
  bool *v6; // r4

  this->__vftable = (idTreeAnimator_vtbl *)&idTreeAnimator::`vftable';
  idMem::Free(this: &mem, ptr: this->joints[0], align: ALIGN_128);
  idMem::Free(this: &mem, ptr: this->joints[1], align: ALIGN_128);
  idMem::Free(this: &mem, ptr: this->joints[2], align: ALIGN_128);
  idMem::Free(this: &mem, ptr: this->joints[3], align: ALIGN_128);
  idMem::Free(this: &mem, ptr: this->originDelta[0], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->originDelta[1], align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->blendParms, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->commands, align: ALIGN_16);
  idTreeAnimator::FreeSurfaces(this);
  idTreeAnimator::FreeMorphMaps(this);
  if ( (*((_BYTE *)this + 2164) & 0x80) != 0 )
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&this->jointBuffers.ptr[this->deferredJobJointBuffer]);
  v2 = 4;
  p_jointBuffers = &this->jointBuffers;
  do
  {
    idJointBuffer::FreeBufferObject(this: p_jointBuffers->ptr);
    --v2;
    p_jointBuffers = (idArray<idJointBuffer,4> *)((char *)p_jointBuffers + 16);
  }
  while ( v2 != 0 );
  if ( this->wrinkleMapExpressions.listStatic == 0 || this->wrinkleMapExpressions.listStatic == 2 )
  {
    list = (char *)this->wrinkleMapExpressions.list;
    if ( list != nullptr )
      idListArrayDelete<idStateData::transition_t>(ptr: list, num: this->wrinkleMapExpressions.size);
    this->wrinkleMapExpressions.list = nullptr;
    this->wrinkleMapExpressions.size = 0;
  }
  this->wrinkleMapExpressions.num = 0;
  if ( this->morphMaps.listStatic == 0 || this->morphMaps.listStatic == 2 )
  {
    v5 = this->morphMaps.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->morphMaps.list = nullptr;
    this->morphMaps.size = 0;
  }
  this->morphMaps.num = 0;
  `eh vector destructor iterator'(
    ptr: this->userChannelBuffers,
    size: 0x10u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector destructor iterator'(
    ptr: &this->jointBuffers,
    size: 0x10u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idJointBuffer::~idJointBuffer);
  `eh vector destructor iterator'(
    ptr: this->userChannels,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector destructor iterator'(
    ptr: this->jointMods,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( this->meshVisibility.listStatic == 0 || this->meshVisibility.listStatic == 2 )
  {
    v6 = this->meshVisibility.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->meshVisibility.list = nullptr;
    this->meshVisibility.size = 0;
  }
  this->meshVisibility.num = 0;
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$251292
// EA  : 0x82864ADC
// RVA : 0x00864ADC
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251292()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$251293
// EA  : 0x82864B04
// RVA : 0x00864B04
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251293()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2036));
}


// ========================================================================
// __unwind$251294
// EA  : 0x82864B30
// RVA : 0x00864B30
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251294()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2068),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$251295
// EA  : 0x82864B6C
// RVA : 0x00864B6C
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251295()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2120),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$251296
// EA  : 0x82864BA8
// RVA : 0x00864BA8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251296()
{
  int v0; // r12

  idArray<idJointBuffer,4>::~idArray<idJointBuffer,4>(this: (idArray<idJointBuffer,4> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                       + 2240));
}


// ========================================================================
// __unwind$251297
// EA  : 0x82864BD4
// RVA : 0x00864BD4
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251297()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2304),
    size: 0x10u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$251298
// EA  : 0x82864C10
// RVA : 0x00864C10
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251298()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2380));
}


// ========================================================================
// __unwind$251299
// EA  : 0x82864C3C
// RVA : 0x00864C3C
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _unwind_251299()
{
  int v0; // r12

  idList<idComponentTimeLine::idTimeLineEntity,5>::~idList<idComponentTimeLine::idTimeLineEntity,5>(this: (idList<idVOChainState,5> *)(*(_DWORD *)(v0 - 144 + 164) + 2400));
}


// ========================================================================
// `dynamic initializer for 'r_debugHitTraceModels''
// EA  : 0x83344560
// RVA : 0x01344560
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugHitTraceModels__()
{
  idCVar::idCVar(
    this: &r_debugHitTraceModels,
    name: "r_debugHitTraceModels",
    value: "0",
    flags: 2,
    description: "+/-1: draws hit test spheres on test, +/-2: draws every frame, < 0 for depth test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugHitTraceModels__);
}


// ========================================================================
// `dynamic initializer for 'r_showSkel''
// EA  : 0x833445B8
// RVA : 0x013445B8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showSkel__()
{
  idCVar::idCVar(
    this: &r_showSkel,
    name: "r_showSkel",
    value: "0",
    flags: 2,
    description: "draw the skeleton when model animates, 1 = draw model with skeleton, 2 = draw skeleton only",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY",
    a9: (int)&loc_825D0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,3>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showSkel__);
}


// ========================================================================
// `dynamic initializer for 'r_showRefPose''
// EA  : 0x83344620
// RVA : 0x01344620
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showRefPose__()
{
  idCVar::idCVar(
    this: &r_showRefPose,
    name: "r_showRefPose",
    value: "0",
    flags: 1,
    description: "selects the pose to draw with r_showskel, 0 = draw the final pose, 1 = draw the reference pose",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showRefPose__);
}


// ========================================================================
// `dynamic initializer for 'r_jointNameScale''
// EA  : 0x83344678
// RVA : 0x01344678
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jointNameScale__()
{
  idCVar::idCVar(
    this: &r_jointNameScale,
    name: "r_jointNameScale",
    value: "0.02",
    flags: 4,
    description: "size of joint names when r_showskel is set to 1",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jointNameScale__);
}


// ========================================================================
// `dynamic initializer for 'r_jointNameOffset''
// EA  : 0x833446D0
// RVA : 0x013446D0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jointNameOffset__()
{
  idCVar::idCVar(
    this: &r_jointNameOffset,
    name: "r_jointNameOffset",
    value: "0.5",
    flags: 4,
    description: "offset of joint names when r_showskel is set to 1",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jointNameOffset__);
}


// ========================================================================
// `dynamic initializer for 'r_jointAxisScale''
// EA  : 0x83344728
// RVA : 0x01344728
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jointAxisScale__()
{
  idCVar::idCVar(
    this: &r_jointAxisScale,
    name: "r_jointAxisScale",
    value: "1.0",
    flags: 4,
    description: "scale of joint axes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jointAxisScale__);
}


// ========================================================================
// `dynamic initializer for 'r_jointName''
// EA  : 0x83344780
// RVA : 0x01344780
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jointName__()
{
  idCVar::idCVar(
    this: &r_jointName,
    name: "r_jointName",
    value: &byte_8200D768,
    flags: 0,
    description: "name of model joint to render",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jointName__);
}


// ========================================================================
// `dynamic initializer for 'r_jointSubString''
// EA  : 0x833447D8
// RVA : 0x013447D8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_jointSubString__()
{
  idCVar::idCVar(
    this: &r_jointSubString,
    name: "r_jointSubString",
    value: &byte_8200D768,
    flags: 0,
    description: "render all joints with this substring in the name",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_jointSubString__);
}


// ========================================================================
// `dynamic initializer for 'r_testMorphMaps''
// EA  : 0x83344830
// RVA : 0x01344830
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_testMorphMaps__()
{
  idCVar::idCVar(
    this: &r_testMorphMaps,
    name: "r_testMorphMaps",
    value: "0",
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_testMorphMaps__);
}


// ========================================================================
// `dynamic initializer for 'r_forceNonDeferredAnimBlend''
// EA  : 0x83344888
// RVA : 0x01344888
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceNonDeferredAnimBlend__()
{
  idCVar::idCVar(
    this: &r_forceNonDeferredAnimBlend,
    name: "r_forceNonDeferredAnimBlend",
    value: "0",
    flags: 0,
    description: "1 = force non-deferred animation blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceNonDeferredAnimBlend__);
}


// ========================================================================
// `dynamic initializer for 'r_useAnimBlendJobs''
// EA  : 0x833448E0
// RVA : 0x013448E0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_useAnimBlendJobs__()
{
  idCVar::idCVar(
    this: &r_useAnimBlendJobs,
    name: "r_useAnimBlendJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_useAnimBlendJobs__);
}


// ========================================================================
// `dynamic initializer for 'r_forceDualQuatSkinning''
// EA  : 0x83344948
// RVA : 0x01344948
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_forceDualQuatSkinning__()
{
  idCVar::idCVar(
    this: &r_forceDualQuatSkinning,
    name: "r_forceDualQuatSkinning",
    value: "0",
    flags: 1,
    description: "0 = off, 1 = on",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_forceDualQuatSkinning__);
}


// ========================================================================
// `dynamic initializer for 'anim_recordTrace''
// EA  : 0x833449A0
// RVA : 0x013449A0
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_recordTrace__()
{
  idCVar::idCVar(
    this: &anim_recordTrace,
    name: "anim_recordTrace",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_recordTrace__);
}


// ========================================================================
// `dynamic initializer for 'rp_wrinkleFactor0''
// EA  : 0x833449F8
// RVA : 0x013449F8
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_wrinkleFactor0__()
{
  rp_wrinkleFactor0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_wrinkleFactor0;
}


// ========================================================================
// `dynamic initializer for 'rp_wrinkleFactor1''
// EA  : 0x83344A18
// RVA : 0x01344A18
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_wrinkleFactor1__()
{
  rp_wrinkleFactor1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_wrinkleFactor1;
}


// ========================================================================
// `dynamic initializer for 'rp_wrinkleFactor2''
// EA  : 0x83344A38
// RVA : 0x01344A38
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_wrinkleFactor2__()
{
  rp_wrinkleFactor2.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_wrinkleFactor2;
}


// ========================================================================
// `dynamic initializer for 'rp_wrinkleFactor3''
// EA  : 0x83344A58
// RVA : 0x01344A58
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_wrinkleFactor3__()
{
  rp_wrinkleFactor3.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_wrinkleFactor3;
}


// ========================================================================
// `dynamic initializer for 'rp_wrinkleScale''
// EA  : 0x83344A78
// RVA : 0x01344A78
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

void _dynamic_initializer_for__rp_wrinkleScale__()
{
  rp_wrinkleScale.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_wrinkleScale;
}


// ========================================================================
// `dynamic initializer for 'register_AnimationBlendJob''
// EA  : 0x83344A98
// RVA : 0x01344A98
// PDB : w:\tech5\engine\models\skeletalanimation\treeanimator.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_AnimationBlendJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_AnimationBlendJob,
           function: (void (__fastcall *)(void *))AnimationBlendJob,
           name: "AnimationBlendJob");
}

