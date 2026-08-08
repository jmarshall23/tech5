
// ========================================================================
// ?InternalUpdateAttached@idAIEventWedge@@MAA?AW4aiEventUpdateResult_t@idAIEvent@@H@Z
// EA  : 0x82A47090
// RVA : 0x00A47090
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventwedge.cpp
// ========================================================================

idAIEvent::aiEventUpdateResult_t __fastcall idAIEventWedge::InternalUpdateAttached(idAIEventWedge *this, int curTime)
{
  this->lastRefresh = -1;
  return idAIEvent::InternalUpdateAttached(this, curTime);
}


// ========================================================================
// ??0idAIEventWedge@@QAA@XZ
// EA  : 0x82A47130
// RVA : 0x00A47130
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventwedge.cpp
// ========================================================================

idAIEventWedge *__fastcall idAIEventWedge::idAIEventWedge(idAIEventWedge *this)
{
  int v2; // r9
  int v3; // r11
  int i; // ctr
  int v5; // r8

  idAIEvent::idAIEvent(this);
  this->__vftable = (idAIEventWedge_vtbl *)&idAIEventWedge::`vftable';
  v2 = 18;
  this->dir.z = 0.0;
  this->dir.y = 0.0;
  this->dir.x = 0.0;
  this->lastRefresh = -1;
  this->radius = 0.0;
  do
  {
    v3 = 0;
    for ( i = 3; i != 0; --i )
    {
      v5 = 4 * (v2 + v3++);
      *(float *)((char *)&this->__vftable + v5) = 0.0;
    }
    v2 += 3;
  }
  while ( v2 < 27 );
  memset(Dst: &this->planes, Val: 0, Size: sizeof(this->planes));
  return this;
}


// ========================================================================
// ?Cache@idAIEventWedge@@ABAXH@Z
// EA  : 0x82A471D0
// RVA : 0x00A471D0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventwedge.cpp
// ========================================================================

void __fastcall idAIEventWedge::Cache(idAIEventWedge *this, int curTime)
{
  idVec3 *p_dir; // r28
  const idDeclAiEvent *eventDecl; // r11
  double arcWidthDegrees; // fp13
  idVec3 *v7; // r30
  float *v8; // r3
  double v9; // fp5
  double v10; // fp4
  double x; // fp0
  double y; // fp13
  idVec3 *p_origin; // r29
  double z; // fp12
  const idDeclAiEvent *v15; // r11
  double v16; // fp13
  float *v17; // r3
  double v18; // fp11
  double v19; // fp9
  double v20; // fp1
  double v21; // fp13
  double v22; // fp10
  double v23; // fp8
  double v24; // fp0
  double v25; // fp13
  double v26; // fp12
  const idDeclAiEvent *v27; // r11
  double heightMax; // fp0
  double v29; // fp12
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp7
  double v34; // fp6
  double v35; // fp4
  double v36; // fp5
  double v37; // fp3
  const idDeclAiEvent *v38; // r11
  double heightMin; // fp0
  double v40; // fp11
  double v41; // fp9
  double v42; // fp8
  double v43; // fp7
  double v44; // fp6
  double v45; // fp5
  idVec3 v46; // [sp+50h] [-120h] BYREF
  idRotation v47; // [sp+60h] [-110h] BYREF
  idRotation v48; // [sp+B0h] [-C0h] BYREF
  idVec3 v49[3]; // [sp+100h] [-70h] BYREF

  if ( this->lastRefresh < curTime )
  {
    p_dir = &this->dir;
    if ( (float)((float)(this->dir.y * this->dir.y)
               + (float)((float)(this->dir.z * this->dir.z) + (float)(this->dir.x * this->dir.x))) >= 1.0 )
    {
      this->axis = *idVec3::ToMat3(this: v49, result: (idMat3 *)&this->dir);
      eventDecl = this->eventDecl;
      if ( eventDecl != nullptr )
        arcWidthDegrees = eventDecl->arcWidthDegrees;
      else
        arcWidthDegrees = 0.0;
      v7 = &this->axis.mat[2];
      idRotation::idRotation(
        this: &v48,
        rotationOrigin: &vec3_origin,
        rotationVec: &this->axis.mat[2],
        rotationAngle: (float)((float)arcWidthDegrees * (float)-0.5));
      v8 = (float *)idRotation::ToMat3(this: &v48);
      v9 = (float)((float)((float)((float)(v8[2] * p_dir->x)
                                 + (float)((float)(v8[5] * p_dir->y) + (float)(v8[8] * p_dir->z)))
                         * this->axis.mat[2].y)
                 - (float)((float)((float)(v8[1] * p_dir->x)
                                 + (float)((float)(v8[4] * p_dir->y) + (float)(v8[7] * p_dir->z)))
                         * this->axis.mat[2].z));
      v10 = (float)((float)((float)((float)(p_dir->x * *v8)
                                  + (float)((float)(v8[3] * p_dir->y) + (float)(v8[6] * p_dir->z)))
                          * this->axis.mat[2].z)
                  - (float)((float)((float)(v8[2] * p_dir->x)
                                  + (float)((float)(v8[5] * p_dir->y) + (float)(v8[8] * p_dir->z)))
                          * this->axis.mat[2].x));
      v46.z = (float)((float)((float)((float)(v8[1] * p_dir->x)
                                    + (float)((float)(v8[4] * p_dir->y) + (float)(v8[7] * p_dir->z)))
                            * this->axis.mat[2].x)
                    - (float)((float)((float)(p_dir->x * *v8)
                                    + (float)((float)(v8[3] * p_dir->y) + (float)(v8[6] * p_dir->z)))
                            * this->axis.mat[2].y))
            * (float)-1.0;
      v46.x = (float)v9 * (float)-1.0;
      v46.y = (float)v10 * (float)-1.0;
      idVec3::NormalizeFast(this: &v46);
      x = v46.x;
      y = v46.y;
      p_origin = &this->origin;
      z = v46.z;
      this->planes.ptr[2].a = v46.x;
      this->planes.ptr[2].b = y;
      this->planes.ptr[2].c = z;
      this->planes.ptr[2].d = -(float)((float)(this->origin.y * (float)y)
                                     + (float)((float)((float)z * this->origin.z) + (float)((float)x * this->origin.x)));
      v15 = this->eventDecl;
      if ( v15 != nullptr )
        v16 = v15->arcWidthDegrees;
      else
        v16 = 0.0;
      idRotation::idRotation(
        this: &v47,
        rotationOrigin: &vec3_origin,
        rotationVec: &this->axis.mat[2],
        rotationAngle: (float)((float)v16 * (float)0.5));
      v17 = (float *)idRotation::ToMat3(this: &v47);
      v18 = this->axis.mat[2].y;
      v19 = this->axis.mat[2].z;
      v20 = (float)((float)(p_dir->x * *v17) + (float)((float)(v17[3] * p_dir->y) + (float)(v17[6] * p_dir->z)));
      v21 = (float)((float)(v17[2] * p_dir->x) + (float)((float)(v17[5] * p_dir->y) + (float)(v17[8] * p_dir->z)));
      v22 = (float)((float)((float)(v17[1] * p_dir->x) + (float)((float)(v17[4] * p_dir->y) + (float)(v17[7] * p_dir->z)))
                  * this->axis.mat[2].z);
      v23 = (float)((float)((float)(v17[2] * p_dir->x) + (float)((float)(v17[5] * p_dir->y) + (float)(v17[8] * p_dir->z)))
                  * v7->x);
      v46.z = (float)((float)((float)(v17[1] * p_dir->x)
                            + (float)((float)(v17[4] * p_dir->y) + (float)(v17[7] * p_dir->z)))
                    * this->axis.mat[2].x)
            - (float)(this->axis.mat[2].y
                    * (float)((float)(p_dir->x * *v17) + (float)((float)(v17[3] * p_dir->y) + (float)(v17[6] * p_dir->z))));
      v46.x = (float)((float)v21 * (float)v18) - (float)v22;
      v46.y = (float)((float)v19 * (float)v20) - (float)v23;
      idVec3::NormalizeFast(this: &v46);
      v24 = v46.x;
      v25 = v46.y;
      v26 = v46.z;
      this->planes.ptr[3].a = v46.x;
      this->planes.ptr[3].b = v25;
      this->planes.ptr[3].c = v26;
      this->planes.ptr[3].d = -(float)((float)(this->origin.y * (float)v25)
                                     + (float)((float)((float)v26 * this->origin.z)
                                             + (float)((float)v24 * this->origin.x)));
      v27 = this->eventDecl;
      if ( v27 != nullptr )
        heightMax = v27->heightMax;
      else
        heightMax = 0.0;
      v29 = (float)(this->axis.mat[2].y * (float)heightMax);
      v30 = this->origin.y;
      v31 = (float)(this->axis.mat[2].y * (float)-1.0);
      v32 = (float)(this->axis.mat[2].z * (float)heightMax);
      v33 = v7->x;
      v34 = this->origin.z;
      v35 = (float)((float)heightMax * v7->x);
      v36 = (float)(this->axis.mat[2].z * (float)-1.0);
      v37 = p_origin->x;
      this->planes.ptr[0].c = this->axis.mat[2].z * (float)-1.0;
      this->planes.ptr[0].b = v31;
      this->planes.ptr[0].a = (float)v33 * (float)-1.0;
      this->planes.ptr[0].d = -(float)((float)((float)((float)v33 * (float)-1.0) * (float)((float)v35 + (float)v37))
                                     + (float)((float)((float)v36 * (float)((float)v32 + (float)v34))
                                             + (float)((float)v31 * (float)((float)v30 + (float)v29))));
      v38 = this->eventDecl;
      if ( v38 != nullptr )
        heightMin = v38->heightMin;
      else
        heightMin = 0.0;
      v40 = (float)((float)heightMin * v7->x);
      v41 = (float)(this->axis.mat[2].y * (float)heightMin);
      v42 = p_origin->x;
      v43 = (float)(this->axis.mat[2].z * (float)heightMin);
      v44 = this->origin.y;
      v45 = this->origin.z;
      this->planes.ptr[1].a = v7->x;
      this->planes.ptr[1].b = this->axis.mat[2].y;
      this->planes.ptr[1].c = this->axis.mat[2].z;
      this->planes.ptr[1].d = -(float)((float)(v7->x * (float)((float)v42 - (float)v40))
                                     + (float)((float)((float)((float)v44 - (float)v41) * this->axis.mat[2].y)
                                             + (float)(this->axis.mat[2].z * (float)((float)v45 - (float)v43))));
      this->lastRefresh = curTime;
    }
  }
}


// ========================================================================
// ?InternalIsTouching@idAIEventWedge@@MBA_NPBVidEntity@@H@Z
// EA  : 0x82A475A8
// RVA : 0x00A475A8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventwedge.cpp
// ========================================================================

int __fastcall idAIEventWedge::InternalIsTouching(idAIEventWedge *this, idEntity *ent, int curTime)
{
  idPhysics *Physics; // r29
  idBounds *v6; // r28
  float *v7; // r3
  double v9; // fp10
  double v10; // fp7
  double v11; // fp4
  double v14; // fp5
  double v15; // fp5
  double v16; // fp31
  double v17; // fp0
  int v18; // r30
  idArray<idPlane,4> *i; // r31
  float v20; // [sp+50h] [-50h] BYREF
  float v21; // [sp+54h] [-4Ch] BYREF
  idVec3 v22; // [sp+58h] [-48h] BYREF

  Physics = idEntity::GetPhysics(this: ent);
  v6 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  if ( this->radius != 0.0 )
  {
    v9 = (float)(v7[2] - this->origin.z);
    v10 = (float)(v7[1] - this->origin.y);
    v11 = (float)(*v7 - this->origin.x);
    _FP9 = (float)((float)((float)((float)v11 * (float)v11)
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f9, f1, f13 }
    v14 = __frsqrte(_FP6);
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                + (float)((float)((float)v10 * (float)v10)
                                                                        + (float)((float)v9 * (float)v9)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                                + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                        * (float)0.5))
                                                                        * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)v14)
                                        - (float)1.5)
                        * (float)v14));
    v16 = (float)((float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15)
                * (float)((float)((float)v11 * (float)v11)
                        + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
    v22.x = (float)v11
          * (float)((float)-(float)((float)((float)((float)v15
                                                  * (float)((float)((float)((float)v11 * (float)v11)
                                                                  + (float)((float)((float)v10 * (float)v10)
                                                                          + (float)((float)v9 * (float)v9)))
                                                          * (float)0.5))
                                          * (float)v15)
                                  - (float)1.5)
                  * (float)v15);
    v22.y = (float)v10
          * (float)((float)-(float)((float)((float)((float)v15
                                                  * (float)((float)((float)((float)v11 * (float)v11)
                                                                  + (float)((float)((float)v10 * (float)v10)
                                                                          + (float)((float)v9 * (float)v9)))
                                                          * (float)0.5))
                                          * (float)v15)
                                  - (float)1.5)
                  * (float)v15);
    v22.z = (float)v9
          * (float)((float)-(float)((float)((float)((float)v15
                                                  * (float)((float)((float)((float)v11 * (float)v11)
                                                                  + (float)((float)((float)v10 * (float)v10)
                                                                          + (float)((float)v9 * (float)v9)))
                                                          * (float)0.5))
                                          * (float)v15)
                                  - (float)1.5)
                  * (float)v15);
    if ( v16 >= 1.0 )
    {
      idBounds::AxisProjection(this: v6, dir: &v22, min: &v21, max: &v20);
      v17 = (float)((float)v16 - (float)(v20 - v21));
      if ( v17 >= 0.0 )
      {
        if ( v17 > v16 )
          v17 = v16;
      }
      else
      {
        v17 = 0.0;
      }
      if ( v17 <= this->radius )
      {
        idAIEventWedge::Cache(this, curTime);
        v18 = 0;
        for ( i = &this->planes;
              idBounds::PlaneSide(this: v6, plane: i->ptr, epsilon: 0.1) != 1;
              i = (idArray<idPlane,4> *)((char *)i + 16) )
        {
          if ( ++v18 >= 4 )
            return 1;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?InternalDrawDebug@idAIEventWedge@@MBAXHHH@Z
// EA  : 0x82A47778
// RVA : 0x00A47778
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventwedge.cpp
// ========================================================================

void __fastcall idAIEventWedge::InternalDrawDebug(
        idAIEventWedge *this,
        const int level,
        int curTime,
        const int duration)
{
  idVec3 *p_dir; // r26
  const idDeclAiEvent *eventDecl; // r10
  double v7; // fp1
  double v8; // fp6
  double v9; // fp4
  double v10; // fp3
  double v11; // fp9
  double v12; // fp8
  double v17; // fp7
  double v18; // fp2
  double v19; // fp12
  double v20; // fp11
  double v21; // fp10
  double v22; // fp7
  double v23; // fp2
  double v24; // fp10
  double v25; // fp7
  double v26; // fp2
  double v27; // fp12
  double v28; // fp11
  double v29; // fp10
  double v30; // fp12
  double heightMax; // fp0
  double v32; // fp7
  double v33; // fp12
  double v34; // fp11
  double v35; // fp10
  double v36; // fp30
  double v37; // fp29
  double v38; // fp28
  double heightMin; // fp9
  double v40; // fp7
  double v41; // fp6
  double v42; // fp5
  double v43; // fp13
  double x; // fp2
  double v45; // fp1
  double radius; // fp4
  double v47; // fp3
  double y; // fp0
  double z; // fp9
  double v50; // fp8
  double v51; // fp7
  double v52; // fp6
  int GameMsPerFrame; // r3
  int v54; // r3
  double v55; // fp5
  double v56; // fp3
  double v57; // fp1
  double v58; // fp0
  double v59; // fp13
  int v60; // r3
  int v61; // r3
  int v62; // r3
  int v63; // r3
  int v64; // r3
  double v65; // fp28
  double v66; // fp27
  double v67; // fp26
  double v68; // fp0
  double v69; // fp11
  double v70; // fp3
  double v71; // fp11
  double v72; // fp0
  double v73; // fp1
  double v74; // fp12
  float v75; // [sp+50h] [-120h] BYREF
  float v76; // [sp+54h] [-11Ch]
  float v77; // [sp+58h] [-118h]
  float v78; // [sp+5Ch] [-114h] BYREF
  float v79; // [sp+60h] [-110h]
  float v80; // [sp+64h] [-10Ch]
  float v81; // [sp+70h] [-100h] BYREF
  float v82; // [sp+74h] [-FCh]
  float v83; // [sp+78h] [-F8h]
  float v84; // [sp+7Ch] [-F4h] BYREF
  float v85; // [sp+80h] [-F0h]
  float v86; // [sp+84h] [-ECh]
  float v87; // [sp+90h] [-E0h] BYREF
  float v88; // [sp+94h] [-DCh]
  float v89; // [sp+98h] [-D8h]
  float v90; // [sp+9Ch] [-D4h] BYREF
  float v91; // [sp+A0h] [-D0h]
  float v92; // [sp+A4h] [-CCh]
  float v93; // [sp+A8h] [-C8h] BYREF
  float v94; // [sp+ACh] [-C4h]
  float v95; // [sp+B0h] [-C0h]
  float v96; // [sp+B8h] [-B8h] BYREF
  float v97; // [sp+BCh] [-B4h]
  float v98; // [sp+C0h] [-B0h]
  float v99[4]; // [sp+C8h] [-A8h] BYREF
  float v100[4]; // [sp+D8h] [-98h] BYREF
  float v101[16]; // [sp+E8h] [-88h] BYREF

  p_dir = &this->dir;
  idAIEventWedge::Cache(this, curTime);
  if ( (float)((float)(this->dir.z * this->dir.z)
             + (float)((float)(this->dir.x * this->dir.x) + (float)(this->dir.y * this->dir.y))) >= 1.0 )
  {
    eventDecl = this->eventDecl;
    v7 = (float)((float)(this->axis.mat[2].x * this->planes.ptr[2].b)
               - (float)(this->planes.ptr[2].a * this->axis.mat[2].y));
    v8 = (float)((float)(this->axis.mat[2].y * this->planes.ptr[2].c)
               - (float)(this->axis.mat[2].z * this->planes.ptr[2].b));
    v9 = (float)((float)((float)(this->planes.ptr[3].b * this->axis.mat[2].x)
                       - (float)(this->planes.ptr[3].a * this->axis.mat[2].y))
               * (float)-1.0);
    v10 = (float)((float)(this->planes.ptr[2].a * this->axis.mat[2].z)
                - (float)(this->axis.mat[2].x * this->planes.ptr[2].c));
    v11 = (float)((float)((float)(this->axis.mat[2].y * this->planes.ptr[3].c)
                        - (float)(this->axis.mat[2].z * this->planes.ptr[3].b))
                * (float)-1.0);
    v12 = (float)((float)((float)(this->planes.ptr[3].a * this->axis.mat[2].z)
                        - (float)(this->planes.ptr[3].c * this->axis.mat[2].x))
                * (float)-1.0);
    _FP7 = (float)((float)((float)((float)v10 * (float)v10)
                         + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    _FP2 = (float)((float)((float)((float)v12 * (float)v12)
                         + (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f11, f7, f11, f12 }
    __asm { fsel      f10, f2, f10, f12 }
    v17 = __frsqrte(_FP11);
    v18 = __frsqrte(_FP10);
    v19 = (float)v17;
    v20 = (float)v18;
    v21 = (float)((float)v17
                * (float)((float)((float)((float)v10 * (float)v10)
                                + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                        * (float)0.5));
    v22 = (float)((float)v18
                * (float)((float)((float)((float)v12 * (float)v12)
                                + (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9)))
                        * (float)0.5));
    v23 = (float)-(float)((float)((float)v21 * (float)v19) - (float)1.5);
    v24 = (float)-(float)((float)((float)v22 * (float)v20) - (float)1.5);
    v25 = (float)((float)v23 * (float)v19);
    v27 = (float)((float)((float)v23 * (float)v19)
                * (float)((float)((float)((float)v10 * (float)v10)
                                + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                        * (float)0.5));
    v26 = (float)((float)v24 * (float)v20);
    v28 = (float)((float)((float)v24 * (float)v20)
                * (float)((float)((float)((float)v12 * (float)v12)
                                + (float)((float)((float)v11 * (float)v11) + (float)((float)v9 * (float)v9)))
                        * (float)0.5));
    v29 = (float)-(float)((float)((float)v27 * (float)v25) - (float)1.5);
    v30 = (float)-(float)((float)((float)v28 * (float)v26) - (float)1.5);
    heightMax = 0.0;
    v32 = (float)((float)-(float)((float)((float)((float)((float)v29 * (float)v25)
                                                * (float)((float)((float)((float)v10 * (float)v10)
                                                                + (float)((float)((float)v8 * (float)v8)
                                                                        + (float)((float)v7 * (float)v7)))
                                                        * (float)0.5))
                                        * (float)((float)v29 * (float)v25))
                                - (float)1.5)
                * (float)((float)v29 * (float)v25));
    v34 = (float)((float)((float)(this->planes.ptr[2].a * this->axis.mat[2].z)
                        - (float)(this->axis.mat[2].x * this->planes.ptr[2].c))
                * (float)v32);
    v35 = (float)((float)((float)(this->axis.mat[2].x * this->planes.ptr[2].b)
                        - (float)(this->planes.ptr[2].a * this->axis.mat[2].y))
                * (float)v32);
    v36 = (float)((float)((float)((float)(this->axis.mat[2].y * this->planes.ptr[3].c)
                                - (float)(this->axis.mat[2].z * this->planes.ptr[3].b))
                        * (float)-1.0)
                * (float)((float)-(float)((float)((float)((float)((float)v30 * (float)v26)
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)((float)v30 * (float)v26))
                                        - (float)1.5)
                        * (float)((float)v30 * (float)v26)));
    v37 = (float)((float)((float)((float)(this->planes.ptr[3].a * this->axis.mat[2].z)
                                - (float)(this->planes.ptr[3].c * this->axis.mat[2].x))
                        * (float)-1.0)
                * (float)((float)-(float)((float)((float)((float)((float)v30 * (float)v26)
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)((float)v30 * (float)v26))
                                        - (float)1.5)
                        * (float)((float)v30 * (float)v26)));
    v38 = (float)((float)((float)((float)(this->planes.ptr[3].b * this->axis.mat[2].x)
                                - (float)(this->planes.ptr[3].a * this->axis.mat[2].y))
                        * (float)-1.0)
                * (float)((float)-(float)((float)((float)((float)((float)v30 * (float)v26)
                                                        * (float)((float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)v9 * (float)v9)))
                                                                * (float)0.5))
                                                * (float)((float)v30 * (float)v26))
                                        - (float)1.5)
                        * (float)((float)v30 * (float)v26)));
    v33 = (float)((float)v32
                * (float)((float)(this->axis.mat[2].y * this->planes.ptr[2].c)
                        - (float)(this->axis.mat[2].z * this->planes.ptr[2].b)));
    if ( eventDecl != nullptr )
      heightMin = eventDecl->heightMin;
    else
      heightMin = 0.0;
    v40 = (float)(this->axis.mat[2].x * (float)-heightMin);
    v41 = (float)(this->axis.mat[2].y * (float)-heightMin);
    v42 = (float)(this->axis.mat[2].z * (float)-heightMin);
    if ( eventDecl != nullptr )
      heightMax = eventDecl->heightMax;
    v43 = (float)(this->axis.mat[2].x * (float)heightMax);
    x = this->origin.x;
    v45 = (float)(this->axis.mat[2].z * (float)heightMax);
    radius = this->radius;
    v47 = (float)(this->axis.mat[2].y * (float)heightMax);
    y = this->origin.y;
    z = this->origin.z;
    v50 = (float)(this->origin.x + (float)v40);
    v51 = (float)(this->origin.y + (float)v41);
    v52 = (float)(this->origin.z + (float)v42);
    v75 = v50;
    v76 = v51;
    v77 = v52;
    v78 = (float)x + (float)v43;
    v80 = (float)z + (float)v45;
    v79 = (float)y + (float)v47;
    v81 = (float)((float)radius * (float)v33) + (float)v50;
    v82 = (float)((float)v34 * (float)radius) + (float)v51;
    v83 = (float)((float)v35 * (float)radius) + (float)v52;
    v84 = (float)((float)radius * (float)v33) + v78;
    v85 = (float)((float)v34 * (float)radius) + v79;
    v86 = (float)((float)v35 * (float)radius) + v80;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v75,
      a4: (const idVec3 *)&v81,
      a5: GameMsPerFrame,
      a6: true);
    v54 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v78,
      a4: (const idVec3 *)&v84,
      a5: v54,
      a6: true);
    v55 = (float)((float)((float)v37 * this->radius) + v76);
    v56 = (float)((float)((float)v38 * this->radius) + v77);
    v57 = (float)(v78 + (float)(this->radius * (float)v36));
    v58 = (float)(v79 + (float)((float)v37 * this->radius));
    v59 = (float)(v80 + (float)((float)v38 * this->radius));
    v87 = (float)(this->radius * (float)v36) + v75;
    v88 = v55;
    v89 = v56;
    v90 = v57;
    v91 = v58;
    v92 = v59;
    v60 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v75,
      a4: (const idVec3 *)&v87,
      a5: v60,
      a6: true);
    v61 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v78,
      a4: (const idVec3 *)&v90,
      a5: v61,
      a6: true);
    v62 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v75,
      a4: (const idVec3 *)&v78,
      a5: v62,
      a6: true);
    v63 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v87,
      a4: (const idVec3 *)&v90,
      a5: v63,
      a6: true);
    v64 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v81,
      a4: (const idVec3 *)&v84,
      a5: v64,
      a6: true);
    v65 = (float)((float)(v78 - v75) * (float)0.5);
    v66 = (float)((float)(v79 - v76) * (float)0.5);
    v67 = (float)((float)(v80 - v77) * (float)0.5);
    v93 = (float)((float)((float)(v90 - v87) * (float)0.5) + v87) + (float)((float)(v78 - v75) * (float)0.5);
    v94 = (float)((float)((float)(v91 - v88) * (float)0.5) + v88) + (float)((float)(v79 - v76) * (float)0.5);
    v95 = (float)((float)((float)(v92 - v89) * (float)0.5) + v89) + (float)((float)(v80 - v77) * (float)0.5);
    idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v68 = (float)(this->planes.ptr[3].c * (float)32.0);
    v69 = (float)((float)(this->planes.ptr[3].b * (float)32.0) + v94);
    v101[0] = (float)(this->planes.ptr[3].a * (float)32.0) + v93;
    v101[1] = v69;
    v101[2] = (float)v68 + v95;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorOrange,
      a3: &v93,
      a4: v101,
      a5: 4.0);
    v96 = (float)((float)((float)(v84 - v81) * (float)0.5) + v81) + (float)v65;
    v97 = (float)((float)((float)(v85 - v82) * (float)0.5) + v82) + (float)v66;
    v98 = (float)((float)((float)(v86 - v83) * (float)0.5) + v83) + (float)v67;
    idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v70 = (float)(this->planes.ptr[2].c * (float)32.0);
    v71 = (float)((float)(this->planes.ptr[2].b * (float)32.0) + v97);
    v99[0] = (float)(this->planes.ptr[2].a * (float)32.0) + v96;
    v99[1] = v71;
    v99[2] = (float)v70 + v98;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorRed,
      a3: &v96,
      a4: v99,
      a5: 4.0);
    idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v72 = (float)(this->radius * this->dir.z);
    v73 = this->origin.z;
    v74 = (float)((float)(this->radius * this->dir.y) + this->origin.y);
    v100[0] = (float)(this->radius * p_dir->x) + this->origin.x;
    v100[1] = v74;
    v100[2] = (float)v72 + (float)v73;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorGreen,
      a3: &this->origin,
      a4: v100,
      a5: 4.0);
  }
}

