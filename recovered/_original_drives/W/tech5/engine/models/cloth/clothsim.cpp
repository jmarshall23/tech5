
// ========================================================================
// ?Reset@idClothSim@@QAAXXZ
// EA  : 0x827A7ED8
// RVA : 0x007A7ED8
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::Reset(idClothSim *this)
{
  int v1; // r10
  int v2; // r11
  idClothParticle *v3; // r9

  v1 = 0;
  if ( this->numClothParticles > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = &this->cloth[v2++];
      v3->state = 0;
    }
    while ( v1 < this->numClothParticles );
  }
}


// ========================================================================
// ?DebugDraw@idClothSim@@QAAXABVidVec3@@ABVidMat3@@PAVidRenderWorld@@H@Z
// EA  : 0x827A7F18
// RVA : 0x007A7F18
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::DebugDraw(
        idClothSim *this,
        const idVec3 *offset,
        const idMat3 *axis,
        idRenderWorld *renderWorld,
        int debugLevel)
{
  idRenderWorld_vtbl *v10; // r10
  int v11; // r27
  int v12; // r26
  idColor *v13; // r4
  idClothParticle *v14; // r11
  void (__fastcall *DebugPoint)(idRenderWorld *, const idVec4 *, const idVec3 *, const int, const bool); // ctr
  double z; // fp8
  double v17; // fp5
  double v18; // fp3
  idClothParticle *cloth; // r11
  float *p_x; // r11
  __int64 v21; // r6
  double v22; // fp9
  double v23; // fp4
  double v24; // fp2
  __int64 v25; // r10
  __int64 v26; // r8
  va *v27; // r3
  int v28; // r26
  int v29; // r27
  idClothSpring *list; // r11
  idClothSpring *v31; // r11
  idColor *v32; // r11
  bool edge; // zf
  float r; // r9
  float g; // r8
  double x; // fp0
  float b; // r7
  double y; // fp13
  float a; // r6
  double v40; // fp12
  idClothSpring *v41; // r11
  double v42; // fp11
  double v43; // fp10
  double v44; // fp9
  double v45; // fp8
  idClothSpring *v46; // r10
  idClothParticle *v47; // r9
  double v48; // fp7
  double v49; // fp6
  double v50; // fp5
  double v51; // fp4
  double v52; // fp3
  float *v53; // r11
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v55; // fp2
  double v56; // fp1
  float *v57; // r11
  double v58; // fp10
  double v59; // fp13
  double v60; // fp11
  double v61; // fp9
  int v62; // r27
  int v63; // r26
  double v64; // fp13
  idSphere *v65; // r24
  double v66; // fp11
  double v67; // fp10
  double v68; // fp9
  double v69; // fp8
  void (__fastcall *DebugSphere)(idRenderWorld *, const idVec4 *, const idSphere *, const int, const int, const bool); // r11
  double v71; // fp7
  double v72; // fp6
  double v73; // fp5
  double v74; // fp4
  double v75; // fp3
  double v76; // fp2
  double v77; // fp1
  double v78; // fp5
  double v79; // fp4
  int v80; // r27
  char *v81; // r11
  int v82; // r26
  double v83; // fp12
  int v84; // r24
  double v85; // fp11
  double v86; // fp10
  double v87; // fp8
  double v88; // fp9
  void (__fastcall *v89)(idRenderWorld *, const idVec4 *, const idSphere *, const int, const int, const bool); // r11
  double v90; // fp7
  double v91; // fp5
  double v92; // fp6
  double v93; // fp4
  double v94; // fp3
  double v95; // fp2
  double v96; // fp1
  double v97; // fp8
  double v98; // fp4
  int v99; // [sp+8h] [-11A8h]
  int v100; // [sp+Ch] [-11A4h]
  int v101; // [sp+10h] [-11A0h]
  int v102; // [sp+14h] [-119Ch]
  int v103; // [sp+18h] [-1198h]
  int v104; // [sp+1Ch] [-1194h]
  float v105; // [sp+60h] [-1150h] BYREF
  float v106; // [sp+64h] [-114Ch]
  float v107; // [sp+68h] [-1148h]
  float v108; // [sp+6Ch] [-1144h]
  float v109; // [sp+70h] [-1140h] BYREF
  float v110; // [sp+74h] [-113Ch]
  float v111; // [sp+78h] [-1138h]
  float radius; // [sp+7Ch] [-1134h]
  float v113; // [sp+80h] [-1130h] BYREF
  float v114; // [sp+84h] [-112Ch]
  float v115; // [sp+88h] [-1128h]
  int v116; // [sp+8Ch] [-1124h]
  float v117[4]; // [sp+90h] [-1120h] BYREF
  float v118[4]; // [sp+A0h] [-1110h] BYREF
  float v119[4]; // [sp+B0h] [-1100h] BYREF
  idVec3 v120; // [sp+C0h] [-10F0h] BYREF
  float v121[4]; // [sp+D0h] [-10E0h] BYREF
  float v122[4]; // [sp+E0h] [-10D0h] BYREF
  float v123[4]; // [sp+F0h] [-10C0h] BYREF
  idBounds v124; // [sp+100h] [-10B0h] BYREF
  va v125; // [sp+120h] [-1090h] BYREF

  if ( g_showClothBounds.valueInteger != 0 )
  {
    v120.x = 1.0;
    v120.y = 1.0;
    v120.z = 1.0;
    idBounds::FromTransformedBounds(this: &v124, bounds: &this->clothBounds, origin: offset, axis, scale: &v120);
    v122[0] = 1.0;
    v122[1] = 0.0;
    v10 = renderWorld->__vftable;
    v122[2] = 0.0;
    v122[3] = 1.0;
    v10->DebugBounds(this: renderWorld, a2: (const idVec4 *)v122, a3: &v124, a4: &vec3_origin, a5: 0, a6: false);
  }
  if ( debugLevel != 0 )
  {
    if ( debugLevel == 1 || debugLevel >= 4 )
    {
      v11 = 0;
      if ( this->numClothParticles > 0 )
      {
        v12 = 0;
        do
        {
          v13 = &idColor::colorGreen;
          v14 = &this->cloth[v12];
          if ( v14->anchored == 0 )
            v13 = &idColor::colorBlue;
          DebugPoint = renderWorld->DebugPoint;
          z = offset->z;
          v17 = (float)((float)(v14->origin.z * axis->mat[2].z)
                      + (float)((float)(v14->origin.x * axis->mat[0].z) + (float)(v14->origin.y * axis->mat[1].z)));
          v18 = (float)((float)((float)(v14->origin.z * axis->mat[2].y)
                              + (float)((float)(v14->origin.x * axis->mat[0].y) + (float)(v14->origin.y * axis->mat[1].y)))
                      + offset->y);
          v117[0] = offset->x
                  + (float)((float)(v14->origin.z * axis->mat[2].x)
                          + (float)((float)(v14->origin.x * axis->mat[0].x) + (float)(v14->origin.y * axis->mat[1].x)));
          v117[1] = v18;
          v117[2] = (float)v17 + (float)z;
          DebugPoint(this: renderWorld, a2: (const idVec4 *)v13, a3: (const idVec3 *)v117, a4: 0, a5: false);
          cloth = this->cloth;
          v123[0] = 1.0;
          p_x = &cloth[v12].origin.x;
          v123[1] = 1.0;
          v123[2] = 0.0;
          HIDWORD(v21) = v11;
          v123[3] = 1.0;
          v22 = offset->z;
          v23 = (float)((float)(p_x[2] * axis->mat[2].z)
                      + (float)((float)(*p_x * axis->mat[0].z) + (float)(p_x[1] * axis->mat[1].z)));
          v24 = (float)((float)((float)(p_x[2] * axis->mat[2].y)
                              + (float)((float)(*p_x * axis->mat[0].y) + (float)(p_x[1] * axis->mat[1].y)))
                      + offset->y);
          v119[0] = offset->x
                  + (float)((float)(p_x[2] * axis->mat[2].x)
                          + (float)((float)(*p_x * axis->mat[0].x) + (float)(p_x[1] * axis->mat[1].x)));
          v119[1] = v24;
          v119[2] = (float)v23 + (float)v22;
          v27 = va::va(
                  this: &v125,
                  fmt: "%d",
                  a3: v21,
                  a4: v26,
                  a5: v25,
                  a6: v99,
                  a7: v100,
                  a8: v101,
                  a9: v102,
                  a10: v103,
                  a11: v104);
          ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, _DWORD, double))renderWorld->DebugText)(
            a1: renderWorld,
            a2: v27,
            a3: v119,
            a4: renderWorld->DebugText,
            a5: v123,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.1);
          ++v11;
          ++v12;
        }
        while ( v11 < this->numClothParticles );
      }
    }
    if ( debugLevel == 2 || debugLevel >= 4 )
    {
      v28 = 0;
      if ( this->springs.num > 0 )
      {
        v29 = 0;
        do
        {
          v107 = -1.0;
          list = this->springs.list;
          v108 = -1.0;
          v31 = &list[v29];
          v106 = -1.0;
          v105 = -1.0;
          if ( v31->band )
          {
            v32 = &idColor::colorGreen;
          }
          else
          {
            edge = v31->edge;
            v32 = &idColor::colorMagenta;
            if ( !edge )
              v32 = &idColor::colorWhite;
          }
          r = v32->r;
          g = v32->g;
          x = axis->mat[2].x;
          b = v32->b;
          y = axis->mat[1].y;
          a = v32->a;
          v40 = axis->mat[1].z;
          v41 = this->springs.list;
          v42 = axis->mat[1].x;
          v105 = r;
          v43 = axis->mat[0].y;
          v106 = g;
          v44 = axis->mat[0].z;
          v107 = b;
          v45 = axis->mat[0].x;
          v108 = a;
          v46 = &v41[v29];
          v47 = this->cloth;
          v48 = axis->mat[2].y;
          v49 = axis->mat[2].z;
          v50 = offset->x;
          v51 = offset->y;
          v52 = offset->z;
          v53 = &v47[v41[v29].p2].origin.x;
          DebugLine = renderWorld->DebugLine;
          v55 = (float)((float)(axis->mat[2].z * v53[2])
                      + (float)((float)((float)v44 * *v53) + (float)((float)v40 * v53[1])));
          v56 = (float)(offset->y
                      + (float)((float)(axis->mat[2].y * v53[2])
                              + (float)((float)((float)v43 * *v53) + (float)((float)y * v53[1]))));
          v118[0] = offset->x
                  + (float)((float)(*v53 * (float)v45)
                          + (float)((float)((float)v42 * v53[1]) + (float)((float)x * v53[2])));
          v118[1] = v56;
          v118[2] = (float)v52 + (float)v55;
          v57 = &v47[v46->p1].origin.x;
          v58 = (float)((float)(*v57 * (float)v43) + (float)(v57[1] * (float)y));
          v59 = (float)((float)(*v57 * (float)v44) + (float)(v57[1] * (float)v40));
          v60 = (float)((float)(*v57 * (float)v45) + (float)((float)(v57[1] * (float)v42) + (float)(v57[2] * (float)x)));
          v61 = (float)((float)v51 + (float)((float)(v57[2] * (float)v48) + (float)v58));
          v121[2] = (float)v52 + (float)((float)(v57[2] * (float)v49) + (float)v59);
          v121[1] = v61;
          v121[0] = (float)v50 + (float)v60;
          DebugLine(
            this: renderWorld,
            a2: (const idVec4 *)&v105,
            a3: (const idVec3 *)v121,
            a4: (const idVec3 *)v118,
            a5: 0,
            a6: false);
          ++v28;
          ++v29;
        }
        while ( v28 < this->springs.num );
      }
    }
    if ( debugLevel > 2 )
    {
      v62 = 0;
      if ( this->permanentCollisionSpheres.num > 0 )
      {
        v63 = 0;
        do
        {
          v64 = axis->mat[2].x;
          v65 = &this->permanentCollisionSpheres.list[v63];
          v66 = axis->mat[1].y;
          v67 = axis->mat[2].z;
          v68 = axis->mat[0].x;
          v69 = axis->mat[0].y;
          DebugSphere = renderWorld->DebugSphere;
          v71 = axis->mat[1].z;
          v72 = axis->mat[1].x;
          v73 = axis->mat[2].y;
          v74 = axis->mat[0].z;
          v109 = v65->origin.x;
          v75 = offset->x;
          v110 = v65->origin.y;
          v76 = offset->y;
          v77 = offset->z;
          v111 = v65->origin.z;
          radius = v65->radius;
          v78 = (float)((float)(v111 * (float)v73) + (float)((float)((float)v69 * v109) + (float)(v110 * (float)v66)));
          v79 = (float)((float)(v109 * (float)v74) + (float)((float)((float)v71 * v110) + (float)((float)v67 * v111)));
          v109 = (float)v75
               + (float)((float)(v110 * (float)v72) + (float)((float)((float)v68 * v109) + (float)(v111 * (float)v64)));
          v110 = (float)v78 + (float)v76;
          v111 = (float)v79 + (float)v77;
          DebugSphere(
            this: renderWorld,
            a2: (const idVec4 *)&idColor::colorOrange,
            a3: (const idSphere *)&v109,
            a4: 12,
            a5: 0,
            a6: true);
          ++v62;
          ++v63;
        }
        while ( v62 < this->permanentCollisionSpheres.num );
      }
      v80 = 0;
      v81 = (char *)this + ((16 * this->currentDeferred) ^ 0x10);
      if ( *((int *)v81 + 46) > 0 )
      {
        v82 = 0;
        do
        {
          v83 = axis->mat[2].x;
          v84 = *((_DWORD *)v81 + 45) + v82;
          v85 = axis->mat[1].y;
          v86 = axis->mat[2].z;
          v87 = axis->mat[0].y;
          v88 = axis->mat[0].x;
          v89 = renderWorld->DebugSphere;
          v90 = axis->mat[1].z;
          v91 = axis->mat[2].y;
          v92 = axis->mat[1].x;
          v93 = axis->mat[0].z;
          v113 = *(float *)v84;
          v94 = offset->x;
          v114 = *(float *)(v84 + 4);
          v95 = offset->y;
          v96 = offset->z;
          v115 = *(float *)(v84 + 8);
          v116 = *(_DWORD *)(v84 + 12);
          v97 = (float)((float)((float)v87 * v113) + (float)(v114 * (float)v85));
          v98 = (float)((float)((float)(v113 * (float)v93)
                              + (float)((float)((float)v90 * v114) + (float)((float)v86 * v115)))
                      + (float)v96);
          v113 = (float)v94
               + (float)((float)(v114 * (float)v92) + (float)((float)((float)v88 * v113) + (float)(v115 * (float)v83)));
          v114 = (float)((float)(v115 * (float)v91) + (float)v97) + (float)v95;
          v115 = v98;
          v89(
            this: renderWorld,
            a2: (const idVec4 *)&idColor::colorOrange,
            a3: (const idSphere *)&v113,
            a4: 12,
            a5: 0,
            a6: true);
          ++v80;
          v82 += 16;
          v81 = (char *)this + ((16 * this->currentDeferred) ^ 0x10);
        }
        while ( v80 < *((_DWORD *)v81 + 46) );
      }
    }
  }
}


// ========================================================================
// ?SetOriginAxis@idClothSim@@QAAXABVidVec3@@ABVidMat3@@_N@Z
// EA  : 0x827A85B8
// RVA : 0x007A85B8
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::SetOriginAxis(
        idClothSim *this,
        const idVec3 *newOrigin,
        const idMat3 *newAxis,
        bool updateParticles)
{
  idVec3 *v4; // r9
  idVec3 *v5; // r8
  const idDeclCloth *clothDecl; // r30
  idList<idDeclCloth::ropeInfo,5> *p_ropeData; // r26
  int v8; // r25
  int v9; // r24
  idDeclCloth::ropeInfo *list; // r31
  int v11; // r27
  idDeclCloth::ropeInfo *v12; // r11
  int v13; // r7
  int num; // r6
  int v15; // r10
  idVec3 *v16; // r28
  int v17; // r6
  int v18; // r11
  double y; // fp4
  idClothParticle *v20; // r31
  double z; // fp3
  float *p_x; // r6
  double v23; // fp13
  double v24; // fp12
  idClothParticle *v25; // r11
  idVec3 *p_origin; // r11
  int v27; // r31
  int v28; // r10
  int v29; // r6
  float *v30; // r11
  idClothParticle *v31; // r7
  double x; // fp11
  double v33; // fp31
  double v34; // fp13
  double v35; // fp12
  idClothParticle *v36; // r11

  this->origin = *newOrigin;
  v4 = &newAxis->mat[1];
  v5 = &newAxis->mat[2];
  this->axis = *newAxis;
  if ( updateParticles )
  {
    clothDecl = this->clothDecl;
    if ( this->clothDecl->type == CLOTH_ROPE )
    {
      p_ropeData = &clothDecl->ropeData;
      v8 = 0;
      v9 = 0;
      if ( clothDecl->ropeData.num > 0 )
      {
        list = p_ropeData->list;
        v11 = 0;
        do
        {
          v12 = &list[v11];
          v13 = 0;
          num = list[v11].positions.num;
          if ( num > 0 )
          {
            v15 = v8;
            do
            {
              v16 = v12->positions.list;
              v17 = v12->positions.num;
              v18 = (int)&v12->positions.list[v17];
              y = newOrigin->y;
              v20 = &this->cloth[v15];
              z = newOrigin->z;
              p_x = &v16[v17 - v13++ - 1].x;
              v23 = (float)((float)((float)(p_x[2] - *(float *)(v18 - 4)) * newAxis->mat[2].z)
                          + (float)((float)(newAxis->mat[0].z * (float)(*p_x - *(float *)(v18 - 12)))
                                  + (float)((float)(p_x[1] - *(float *)(v18 - 8)) * newAxis->mat[1].z)));
              v24 = (float)((float)(newAxis->mat[0].y * (float)(*p_x - *(float *)(v18 - 12)))
                          + (float)((float)(newAxis->mat[1].y * (float)(p_x[1] - *(float *)(v18 - 8)))
                                  + (float)(newAxis->mat[2].y * (float)(p_x[2] - *(float *)(v18 - 4)))));
              v20->origin.x = newOrigin->x
                            + (float)((float)(v5->x * (float)(p_x[2] - *(float *)(v18 - 4)))
                                    + (float)((float)(newAxis->mat[0].x * (float)(*p_x - *(float *)(v18 - 12)))
                                            + (float)(v4->x * (float)(p_x[1] - *(float *)(v18 - 8)))));
              v20->origin.z = (float)z + (float)v23;
              v20->origin.y = (float)v24 + (float)y;
              v25 = &this->cloth[v15];
              v25->lastOrigin.x = v25->origin.x;
              v25->lastOrigin.y = v25->origin.y;
              v25->lastOrigin.z = v25->origin.z;
              p_origin = &this->cloth[v15++].origin;
              p_origin[4] = newAxis->mat[0];
              p_origin[5].x = v4->x;
              p_origin[5].y = newAxis->mat[1].y;
              p_origin[5].z = newAxis->mat[1].z;
              p_origin[6].x = v5->x;
              p_origin[6].y = newAxis->mat[2].y;
              p_origin[6].z = newAxis->mat[2].z;
              list = p_ropeData->list;
              v12 = &p_ropeData->list[v11];
              num = v12->positions.num;
            }
            while ( v13 < num );
          }
          ++v9;
          v8 += num;
          ++v11;
        }
        while ( v9 < clothDecl->ropeData.num );
      }
    }
    else
    {
      v27 = 0;
      if ( this->numClothParticles > 0 )
      {
        v28 = 0;
        v29 = 0;
        do
        {
          v30 = &clothDecl->particleData.list[v29].position.x;
          v31 = &this->cloth[v28];
          ++v27;
          ++v29;
          x = newOrigin->x;
          v33 = newOrigin->y;
          v34 = (float)((float)(*v30 * newAxis->mat[0].y)
                      + (float)((float)(v30[1] * newAxis->mat[1].y) + (float)(v30[2] * newAxis->mat[2].y)));
          v35 = (float)((float)(v30[2] * v5->x) + (float)((float)(*v30 * newAxis->mat[0].x) + (float)(v30[1] * v4->x)));
          v31->origin.z = newOrigin->z
                        + (float)((float)(*v30 * newAxis->mat[0].z)
                                + (float)((float)(v30[1] * newAxis->mat[1].z) + (float)(v30[2] * newAxis->mat[2].z)));
          v31->origin.y = (float)v34 + (float)v33;
          v31->origin.x = (float)x + (float)v35;
          v36 = &this->cloth[v28++];
          v36->lastOrigin.x = v36->origin.x;
          v36->lastOrigin.y = v36->origin.y;
          v36->lastOrigin.z = v36->origin.z;
        }
        while ( v27 < this->numClothParticles );
      }
    }
  }
}


// ========================================================================
// ?SetAnchor@idClothSim@@QAAXH_N@Z
// EA  : 0x827A8908
// RVA : 0x007A8908
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::SetAnchor(idClothSim *this, int index, bool tempAnchor)
{
  const idDeclCloth *clothDecl; // r29
  int v4; // r28
  int v5; // r7
  int v6; // r6
  int v7; // r11
  idDeclCloth::ropeInfo *list; // r31
  int v9; // r10
  int num; // r8
  int v11; // r9
  int v12; // r11
  idClothParticle *v13; // r6

  if ( index < 0 || index >= this->numClothParticles )
  {
    idLib::Warning(fmt: "idClothSim::SetAnchor() - invalid index");
  }
  else
  {
    clothDecl = this->clothDecl;
    v4 = 0;
    if ( this->clothDecl->type == CLOTH_ROPE )
    {
      v5 = 0;
      v6 = 0;
      v7 = 0;
      if ( index >= 2 )
      {
        list = clothDecl->ropeData.list;
        v9 = 0;
        do
        {
          v7 += 2;
          num = list[v9].positions.num;
          v11 = list[v9 + 1].positions.num;
          v9 += 2;
          v5 += num;
          v6 += v11;
        }
        while ( v7 < index - 1 );
      }
      if ( v7 < index )
        v4 = clothDecl->ropeData.list[v7].positions.num;
      v12 = v6 + v5 + v4;
    }
    else
    {
      v12 = index;
    }
    v13 = &this->cloth[v12];
    if ( tempAnchor )
      v13->anchored = 2;
    else
      v13->anchored = 1;
  }
}


// ========================================================================
// ?SetAnchorPosition@idClothSim@@QAAXHABVidVec3@@@Z
// EA  : 0x827A8A08
// RVA : 0x007A8A08
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::SetAnchorPosition(idClothSim *this, int index, const idVec3 *org)
{
  const idDeclCloth *clothDecl; // r29
  int v4; // r28
  int v5; // r7
  int v6; // r6
  int v7; // r11
  idDeclCloth::ropeInfo *list; // r31
  int v9; // r10
  int num; // r8
  int v11; // r9
  int v12; // r11

  if ( index < 0 || index >= this->numClothParticles )
  {
    idLib::Warning(fmt: "idClothSim::SetAnchorPosition() - invalid index");
  }
  else
  {
    clothDecl = this->clothDecl;
    v4 = 0;
    if ( this->clothDecl->type == CLOTH_ROPE )
    {
      v5 = 0;
      v6 = 0;
      v7 = 0;
      if ( index >= 2 )
      {
        list = clothDecl->ropeData.list;
        v9 = 0;
        do
        {
          v7 += 2;
          num = list[v9].positions.num;
          v11 = list[v9 + 1].positions.num;
          v9 += 2;
          v5 += num;
          v6 += v11;
        }
        while ( v7 < index - 1 );
      }
      if ( v7 < index )
        v4 = clothDecl->ropeData.list[v7].positions.num;
      v12 = v6 + v5 + v4;
    }
    else
    {
      v12 = index;
    }
    this->cloth[v12].origin = *org;
  }
}


// ========================================================================
// ?SetAnchorAxis@idClothSim@@QAAXHABVidMat3@@@Z
// EA  : 0x827A8AF8
// RVA : 0x007A8AF8
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::SetAnchorAxis(idClothSim *this, int index, const idMat3 *modelAxis)
{
  const idDeclCloth *clothDecl; // r29
  int v4; // r28
  int v5; // r7
  int v6; // r6
  int v7; // r11
  idDeclCloth::ropeInfo *list; // r31
  int v9; // r10
  int num; // r8
  int v11; // r9
  int v12; // r11

  if ( index < 0 || index >= this->numClothParticles )
  {
    idLib::Warning(fmt: "idClothSim::SetAnchorAxis() - invalid index");
  }
  else
  {
    clothDecl = this->clothDecl;
    v4 = 0;
    if ( this->clothDecl->type == CLOTH_ROPE )
    {
      v5 = 0;
      v6 = 0;
      v7 = 0;
      if ( index >= 2 )
      {
        list = clothDecl->ropeData.list;
        v9 = 0;
        do
        {
          v7 += 2;
          num = list[v9].positions.num;
          v11 = list[v9 + 1].positions.num;
          v9 += 2;
          v5 += num;
          v6 += v11;
        }
        while ( v7 < index - 1 );
      }
      if ( v7 < index )
        v4 = clothDecl->ropeData.list[v7].positions.num;
      v12 = v6 + v5 + v4;
    }
    else
    {
      v12 = index;
    }
    this->cloth[v12].axis = *modelAxis;
  }
}


// ========================================================================
// ??1idClothSim@@QAA@XZ
// EA  : 0x827A8D38
// RVA : 0x007A8D38
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::~idClothSim(idClothSim *this)
{
  idMem::Free(this: &mem, ptr: this->cloth, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->clothBoundsFromJob, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->clothParms, align: ALIGN_16);
  `eh vector destructor iterator'(
    ptr: this->weaponTraces,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector destructor iterator'(
    ptr: this->temporaryCollisionSpheres,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->permanentCollisionSpheres);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springs);
}


// ========================================================================
// __unwind$222371
// EA  : 0x827A8DD0
// RVA : 0x007A8DD0
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_222371()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 148));
}


// ========================================================================
// __unwind$222372
// EA  : 0x827A8DFC
// RVA : 0x007A8DFC
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_222372()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$222373
// EA  : 0x827A8E28
// RVA : 0x007A8E28
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_222373()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 180),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$222374
// EA  : 0x827A8E64
// RVA : 0x007A8E64
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_222374()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 212),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?GenerateGeneric@idClothSim@@AAAXXZ
// EA  : 0x827A9030
// RVA : 0x007A9030
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GenerateGeneric(idClothSim *this)
{
  idList<idDeclCloth::particleInfo_t,5> *p_particleData; // r28
  idList<idDeclCloth::springInfo_t,5> *p_springData; // r26
  int num; // r11
  int v5; // r11
  idClothParticle *v6; // r3
  int numClothParticles; // r4
  int v8; // r27
  int v9; // r30
  int v10; // r29
  float *p_x; // r10
  idClothParticle *v12; // r11
  double mass; // fp13
  int v14; // r30
  int size; // r11
  int v16; // r28
  int v17; // r29
  int v18; // r30
  idDeclCloth::springInfo_t *v19; // r11
  idClothParticle *cloth; // r10
  int index2; // r8
  int index1; // r4
  float *v23; // r11
  float *v24; // r10
  double v25; // fp9
  double v26; // fp6
  const idSphere *v27; // r4
  idList<idSphere,81> *v28; // r3

  p_particleData = &this->clothDecl->particleData;
  p_springData = &this->clothDecl->springData;
  if ( this->clothDecl->particleData.num != 0 && this->clothDecl->springData.num != 0 )
  {
    num = this->clothDecl->particleData.num;
    this->height = 1;
    this->width = num;
    v5 = p_particleData->num;
    this->numClothParticles = v5;
    v6 = (idClothParticle *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(481) : TAG_CLOTH",
                              size: (96 * v5 + 15) & 0xFFFFFFF0,
                              tag: TAG_CLOTH,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    numClothParticles = this->numClothParticles;
    this->cloth = v6;
    v8 = 0;
    if ( numClothParticles > 0 )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        idClothParticle::Reset(this: &this->cloth[v9]);
        p_x = &p_particleData->list[v10].position.x;
        v12 = &this->cloth[v9];
        mass = this->clothDecl->mass;
        v12->origin.x = *p_x;
        v12->origin.y = p_x[1];
        v12->origin.z = p_x[2];
        v12->lastOrigin.x = *p_x;
        v12->lastOrigin.y = p_x[1];
        v12->lastOrigin.z = p_x[2];
        v12->mass = mass;
        if ( p_particleData->list[v10].anchored )
          this->cloth[v9].anchored = 1;
        ++v8;
        ++v10;
        ++v9;
      }
      while ( v8 < this->numClothParticles );
    }
    v14 = p_springData->num;
    if ( v14 <= this->springs.size
      || (unsigned __int8)idList<idClothSpring,81>::Resize(this: &this->springs, newsize: p_springData->num) != 0 )
    {
      size = this->springs.size;
      if ( v14 < size )
        size = v14;
      this->springs.num = size;
    }
    v16 = 0;
    if ( p_springData->num > 0 )
    {
      v17 = 0;
      v18 = 0;
      do
      {
        v19 = &p_springData->list[v18];
        cloth = this->cloth;
        index2 = v19->index2;
        index1 = v19->index1;
        v23 = &cloth->origin.x + 8 * index2 + 8 * __ROL4__(index2, 1);
        v24 = &cloth->origin.x + 8 * index1 + 8 * __ROL4__(index1, 1);
        v25 = (float)(v24[1] - v23[1]);
        v26 = (float)(v24[2] - v23[2]);
        idClothSpring::Init2(
          this: &this->springs.list[v17],
          p1: index1,
          p2: index2,
          springLength: __fsqrts((float)((float)((float)v26 * (float)v26)
                         + (float)((float)((float)v25 * (float)v25)
                                 + (float)((float)(*v24 - *v23) * (float)(*v24 - *v23))))),
          springFriction: this->clothDecl->springFriction,
          springLengthMultiplier: this->clothDecl->springMaxLengthMultiplier);
        ++v16;
        ++v18;
        ++v17;
      }
      while ( v16 < p_springData->num );
    }
  }
  else
  {
    idLib::Error(fmt: "Bad flag data in %s", this->clothDecl->name.str);
    idList<idSphere,5>::Append(this: v28, obj: v27);
  }
}


// ========================================================================
// ?GenerateRope@idClothSim@@AAAXXZ
// EA  : 0x827A94C0
// RVA : 0x007A94C0
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GenerateRope(idClothSim *this)
{
  idList<idDeclCloth::ropeInfo,5> *p_ropeData; // r28
  int num; // r11
  int v4; // r10
  int v5; // r11
  idDeclCloth::ropeInfo *v6; // r9
  int v7; // r27
  int v8; // r24
  int v9; // r29
  int v10; // r31
  int v11; // r26
  idClothParticle *v12; // r11
  double mass; // fp0
  float *p_x; // r10
  int v15; // r11
  int size; // r10
  idClothSpring *list; // r9
  idClothSpring *v18; // r3
  idDeclCloth::ropeInfo *v19; // r11
  idVec3 *v20; // r9
  int v21; // r10
  float *v22; // r11
  float *v23; // r10
  double v24; // fp12
  double v25; // fp9
  idDeclCloth::ropeInfo *v26; // r11
  double v27; // fp0
  float *v28; // r10
  idClothParticle *v29; // r11
  double x; // fp13
  int v31; // r11

  p_ropeData = &this->clothDecl->ropeData;
  num = this->clothDecl->ropeData.num;
  if ( num <= 0 )
    idLib::Error(fmt: "Bad rope data in %s", this->clothDecl->name.str);
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      ++v4;
      v6 = &p_ropeData->list[v5++];
      this->numClothParticles += v6->positions.num;
    }
    while ( v4 < p_ropeData->num );
  }
  this->cloth = (idClothParticle *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(387) : TAG_CLOTH",
                                     size: (96 * this->numClothParticles + 15) & 0xFFFFFFF0,
                                     tag: TAG_CLOTH,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  v7 = 0;
  v8 = 0;
  if ( p_ropeData->num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = 0;
      if ( p_ropeData->list[v9].positions.num - 1 > 0 )
      {
        v11 = v7;
        do
        {
          idClothParticle::Reset(this: &this->cloth[v11]);
          v12 = &this->cloth[v11];
          mass = this->clothDecl->mass;
          p_x = &p_ropeData->list[v9].positions.list[p_ropeData->list[v9].positions.num - v10 - 1].x;
          v12->origin.x = *p_x;
          v12->origin.y = p_x[1];
          v12->origin.z = p_x[2];
          v12->lastOrigin.x = *p_x;
          v12->lastOrigin.y = p_x[1];
          v12->lastOrigin.z = p_x[2];
          v12->mass = mass;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v15 = this->springs.num;
          size = this->springs.size;
          list = this->springs.list;
          if ( v15 >= size )
          {
            v18 = &list[size - 1];
          }
          else
          {
            v18 = &list[v15];
            this->springs.num = v15 + 1;
          }
          v19 = &p_ropeData->list[v9];
          v20 = v19->positions.list;
          v21 = v19->positions.num - v10;
          v22 = &v19->positions.list[v21 - 2].x;
          v23 = &v20[v21 - 1].x;
          v24 = (float)(v23[1] - v22[1]);
          v25 = (float)(v23[2] - v22[2]);
          idClothSpring::Init2(
            this: v18,
            p1: v10 + v7,
            p2: v10 + v7 + 1,
            springLength: __fsqrts((float)((float)((float)(*v23 - *v22) * (float)(*v23 - *v22))
                           + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))),
            springFriction: this->clothDecl->springFriction,
            springLengthMultiplier: this->clothDecl->springMaxLengthMultiplier);
          ++v10;
          ++v11;
        }
        while ( v10 < p_ropeData->list[v9].positions.num - 1 );
      }
      this->cloth[v7].anchored = 1;
      idClothParticle::Reset(this: &this->cloth[p_ropeData->list[v9].positions.num - 1 + v7]);
      ++v8;
      v26 = &p_ropeData->list[v9];
      v27 = this->clothDecl->mass;
      v28 = &v26->positions.list->x;
      x = v26->positions.list->x;
      v29 = &this->cloth[v26->positions.num + v7];
      v29[-1].origin.x = x;
      v29[-1].origin.y = v28[1];
      v29[-1].origin.z = v28[2];
      v29[-1].lastOrigin.x = *v28;
      v29[-1].lastOrigin.y = v28[1];
      v29[-1].lastOrigin.z = v28[2];
      v29[-1].mass = v27;
      v31 = p_ropeData->list[v9++].positions.num;
      v7 += v31;
    }
    while ( v8 < p_ropeData->num );
  }
}


// ========================================================================
// ?GenerateSquare@idClothSim@@AAAXXZ
// EA  : 0x827A9818
// RVA : 0x007A9818
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GenerateSquare(idClothSim *this)
{
  const idDeclCloth *clothDecl; // r28
  int width; // r5
  int height; // r11
  int v5; // r11
  idClothParticle *v6; // r3
  int numClothParticles; // r4
  int v8; // r27
  int v9; // r30
  int v10; // r29
  float *p_x; // r10
  idClothParticle *v12; // r11
  double mass; // fp13
  int i; // r26
  int j; // r27
  int v16; // r11
  int v17; // r28
  idList<idClothSpring,81> *p_springs; // r30
  int v19; // r29
  int num; // r11
  int size; // r10
  idClothSpring *v22; // r3
  idClothParticle *cloth; // r10
  float *v24; // r11
  float *v25; // r10
  double v26; // fp12
  double v27; // fp9
  int v28; // r29
  int v29; // r11
  int v30; // r10
  idClothSpring *list; // r9
  idClothSpring *v32; // r3
  idClothParticle *v33; // r10
  float *v34; // r11
  float *v35; // r10
  double v36; // fp12
  double v37; // fp9

  clothDecl = this->clothDecl;
  if ( this->clothDecl->particleData.num == 0 )
    idLib::Error(fmt: "Bad flag data in %s", clothDecl->name.str);
  width = clothDecl->width;
  this->width = width;
  height = clothDecl->height;
  this->height = height;
  v5 = height * width;
  this->numClothParticles = v5;
  v6 = (idClothParticle *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(429) : TAG_CLOTH",
                            size: (96 * v5 + 15) & 0xFFFFFFF0,
                            tag: TAG_CLOTH,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  numClothParticles = this->numClothParticles;
  this->cloth = v6;
  v8 = 0;
  if ( numClothParticles > 0 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      idClothParticle::Reset(this: &this->cloth[v9]);
      p_x = &clothDecl->particleData.list[v10].position.x;
      v12 = &this->cloth[v9];
      mass = this->clothDecl->mass;
      v12->origin.x = *p_x;
      v12->origin.y = p_x[1];
      v12->origin.z = p_x[2];
      v12->lastOrigin.x = *p_x;
      v12->lastOrigin.y = p_x[1];
      v12->lastOrigin.z = p_x[2];
      v12->mass = mass;
      if ( clothDecl->particleData.list[v10].anchored )
        this->cloth[v9].anchored = 1;
      ++v8;
      ++v10;
      ++v9;
    }
    while ( v8 < this->numClothParticles );
  }
  for ( i = 0; i < this->height; ++i )
  {
    for ( j = 0; j < this->width; ++j )
    {
      v16 = this->width;
      v17 = v16 * i + j;
      if ( i < this->height - 1 )
      {
        p_springs = &this->springs;
        v19 = (i + 1) * v16 + j;
        idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
        num = this->springs.num;
        size = this->springs.size;
        if ( num >= size )
        {
          v22 = &p_springs->list[size - 1];
        }
        else
        {
          v22 = &p_springs->list[num];
          this->springs.num = num + 1;
        }
        cloth = this->cloth;
        v24 = &cloth[v19].origin.x;
        v25 = &cloth[v17].origin.x;
        v26 = (float)(v25[1] - v24[1]);
        v27 = (float)(v25[2] - v24[2]);
        idClothSpring::Init2(
          this: v22,
          p1: v17,
          p2: v19,
          springLength: __fsqrts((float)((float)((float)(*v25 - *v24) * (float)(*v25 - *v24))
                         + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)))),
          springFriction: this->clothDecl->springFriction,
          springLengthMultiplier: this->clothDecl->springMaxLengthMultiplier);
      }
      if ( j > 0 )
      {
        v28 = this->width * i + j - 1;
        idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
        v29 = this->springs.num;
        v30 = this->springs.size;
        list = this->springs.list;
        if ( v29 >= v30 )
        {
          v32 = &list[v30 - 1];
        }
        else
        {
          v32 = &list[v29];
          this->springs.num = v29 + 1;
        }
        v33 = this->cloth;
        v34 = &v33[v28].origin.x;
        v35 = &v33[v17].origin.x;
        v36 = (float)(v35[1] - v34[1]);
        v37 = (float)(v35[2] - v34[2]);
        idClothSpring::Init2(
          this: v32,
          p1: v17,
          p2: v28,
          springLength: __fsqrts((float)((float)((float)(*v35 - *v34) * (float)(*v35 - *v34))
                         + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))),
          springFriction: this->clothDecl->springFriction,
          springLengthMultiplier: this->clothDecl->springMaxLengthMultiplier);
      }
    }
  }
}


// ========================================================================
// ?AddCollisionSphere@idClothSim@@QAAXABVidSphere@@_N@Z
// EA  : 0x827A9B48
// RVA : 0x007A9B48
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::AddCollisionSphere(
        idClothSim *this,
        const idSphere *collisionSphere,
        bool isAPermanentSphere)
{
  char *v3; // r11

  v3 = (char *)this + 16 * this->currentDeferred;
  if ( *((_DWORD *)v3 + 46) + this->permanentCollisionSpheres.num < 1024 )
  {
    if ( isAPermanentSphere )
      idList<idSphere,5>::Append(this: &this->permanentCollisionSpheres, obj: collisionSphere);
    else
      idList<idSphere,5>::Append(this: (idList<idSphere,81> *)(v3 + 180), obj: collisionSphere);
  }
}


// ========================================================================
// ?GetRopeParticleOriginAxis@idClothSim@@QBAXHAAV?$idList@VidVec3@@$04@@AAV?$idList@VidMat3@@$04@@@Z
// EA  : 0x827A9B88
// RVA : 0x007A9B88
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GetRopeParticleOriginAxis(
        idClothSim *this,
        int index,
        idList<idVec3,5> *originList,
        idList<idMat3,5> *axisList)
{
  int v7; // r8
  int v8; // r7
  int v9; // r31
  int v10; // r11
  int v11; // r10
  idDeclCloth::ropeInfo *list; // r3
  int num; // r6
  int v14; // r9
  idDeclCloth::ropeInfo *v15; // r4
  unsigned int v16; // r30
  idDeclCloth::ropeInfo *v17; // r11
  int v18; // r28
  int v19; // r31
  int size; // r11
  idDeclCloth::ropeInfo *v21; // r11
  int v22; // r31
  int v23; // r11
  int v24; // r6
  idDeclCloth::ropeInfo *v25; // r3
  idClothParticle *cloth; // r5
  int v27; // r7
  int v28; // r8
  int v29; // r9
  idVec3 *v30; // r10
  float *v31; // r10

  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( index >= 2 )
  {
    v11 = 0;
    list = this->clothDecl->ropeData.list;
    do
    {
      v10 += 2;
      num = list[v11].positions.num;
      v14 = list[v11 + 1].positions.num;
      v11 += 2;
      v7 += num;
      v8 += v14;
    }
    while ( v10 < index - 1 );
  }
  if ( v10 < index )
  {
    v15 = &this->clothDecl->ropeData.list[v10++];
    v9 = v15->positions.num;
  }
  v16 = v10;
  v17 = this->clothDecl->ropeData.list;
  v18 = v8 + v7 + v9;
  v19 = v17[v16].positions.num;
  if ( v19 <= originList->size || idList<idVec3,59>::Resize(this: originList, newsize: v17[v16].positions.num) )
  {
    size = originList->size;
    if ( v19 < size )
      size = v19;
    originList->num = size;
  }
  v21 = this->clothDecl->ropeData.list;
  v22 = v21[v16].positions.num;
  if ( v22 <= axisList->size
    || (unsigned __int8)idList<idMat3,5>::Resize(this: axisList, newsize: v21[v16].positions.num) != 0 )
  {
    v23 = axisList->size;
    if ( v22 < v23 )
      v23 = v22;
    axisList->num = v23;
  }
  v24 = 0;
  v25 = &this->clothDecl->ropeData.list[v16];
  if ( v25->positions.num > 0 )
  {
    cloth = this->cloth;
    v27 = 0;
    v28 = 0;
    v29 = v18;
    do
    {
      ++v24;
      v30 = &originList->list[v28++];
      v30->x = cloth[v29].origin.x;
      v30->y = cloth[v29].origin.y;
      v30->z = cloth[v29].origin.z;
      v31 = (float *)&axisList->list[v27++];
      *v31 = cloth[v29].axis.mat[0].x;
      v31[1] = cloth[v29].axis.mat[0].y;
      v31[2] = cloth[v29].axis.mat[0].z;
      v31[3] = cloth[v29].axis.mat[1].x;
      v31[4] = cloth[v29].axis.mat[1].y;
      v31[5] = cloth[v29].axis.mat[1].z;
      v31[6] = cloth[v29].axis.mat[2].x;
      v31[7] = cloth[v29].axis.mat[2].y;
      v31[8] = cloth[v29++].axis.mat[2].z;
    }
    while ( v24 < v25->positions.num );
  }
}


// ========================================================================
// ??0idClothSim@@QAA@PBVidDeclCloth@@@Z
// EA  : 0x827A9EE8
// RVA : 0x007A9EE8
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

idClothSim *__fastcall idClothSim::idClothSim(idClothSim *this, const idDeclCloth *clothSystem)
{
  int v2; // ctr
  float *p_y; // r10
  float *p_z; // r9
  idBounds *v6; // r3
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r3
  clothType_t type; // [sp+50h] [-40h]

  this->clothDecl = clothSystem;
  this->width = 0;
  this->height = 0;
  this->hSpacing = 0.0;
  this->vSpacing = 0.0;
  this->origin = vec3_origin;
  v2 = 9;
  p_y = &mat2_identity.mat[1].y;
  p_z = &this->origin.z;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->windDirection = vec3_origin;
  this->gravity.x = 0.0;
  this->gravity.y = 0.0;
  this->gravity.z = -1.0;
  this->numIterations = 1;
  this->timeDelta = 0.016000001;
  this->cloth = nullptr;
  this->numClothParticles = 0;
  this->currentDeferred = 0;
  this->clothBoundsFromJob = nullptr;
  this->isRect = false;
  this->springs.list = nullptr;
  this->springs.granularity = 0;
  this->springs.memTag = 81;
  this->springs.listStatic = 0;
  this->springs.size = 0;
  this->springs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springs);
  this->permanentCollisionSpheres.list = nullptr;
  this->permanentCollisionSpheres.granularity = 0;
  this->permanentCollisionSpheres.memTag = 81;
  this->permanentCollisionSpheres.listStatic = 0;
  this->permanentCollisionSpheres.size = 0;
  this->permanentCollisionSpheres.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->permanentCollisionSpheres);
  `eh vector constructor iterator'(
    ptr: this->temporaryCollisionSpheres,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<idSphere,81>::idList<idSphere,81>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector constructor iterator'(
    ptr: this->weaponTraces,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<idSphere,81>::idList<idSphere,81>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->clothParms = (clothParms_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(63) : TAG_CLOTH",
                                       size: 0xACu,
                                       tag: TAG_CLOTH,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  v6 = (idBounds *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(64) : TAG_CLOTH",
                     size: 0x18u,
                     tag: TAG_CLOTH,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
  this->clothBoundsFromJob = v6;
  v6->b[1].z = 0.0;
  v6->b[1].y = 0.0;
  v6->b[1].x = 0.0;
  v6->b[0].z = 0.0;
  v6->b[0].y = 0.0;
  v6->b[0].x = 0.0;
  this->clothBounds.b[1].z = 0.0;
  this->clothBounds.b[1].y = 0.0;
  this->clothBounds.b[1].x = 0.0;
  this->clothBounds.b[0].z = 0.0;
  this->clothBounds.b[0].y = 0.0;
  this->clothBounds.b[0].x = 0.0;
  type = this->clothDecl->type;
  switch ( type )
  {
    case CLOTH_ROPE:
      idClothSim::GenerateRope(this);
LABEL_9:
      this->collisionPlane[0].d = 0.0;
      this->collisionPlane[0].c = 0.0;
      this->collisionPlane[0].b = 0.0;
      this->collisionPlane[0].a = 0.0;
      this->collisionPlane[1].d = 0.0;
      this->collisionPlane[1].c = 0.0;
      this->collisionPlane[1].b = 0.0;
      this->collisionPlane[1].a = 0.0;
      return this;
    case CLOTH_SQUARE:
      idClothSim::GenerateSquare(this);
      goto LABEL_9;
    case CLOTH_GENERIC:
      idClothSim::GenerateGeneric(this);
      goto LABEL_9;
    default:
      break;
  }
  idLib::Error(fmt: "idClothSim - unsupported type");
  return _LN107(a1: v11, a2: v10, a3: v9, a4: v8);
}


// ========================================================================
// $LN107
// EA  : 0x827AA178
// RVA : 0x007AA178
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _LN107()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 148));
}


// ========================================================================
// __unwind$223537_0
// EA  : 0x827AA1A4
// RVA : 0x007AA1A4
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_223537_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 164));
}


// ========================================================================
// __unwind$223538_0
// EA  : 0x827AA1D0
// RVA : 0x007AA1D0
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_223538_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 180),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$223539_0
// EA  : 0x827AA20C
// RVA : 0x007AA20C
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_223539_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 212),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?GenerateTriangle@idClothSim@@AAAXPBVidDeclCloth@@@Z
// EA  : 0x827AA248
// RVA : 0x007AA248
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GenerateTriangle(idClothSim *this, const idDeclCloth *clothSystem)
{
  int height; // r11
  int v5; // r9
  int v6; // r10
  int v7; // r5
  double v8; // fp0
  double v9; // fp13
  double v10; // fp11
  int v11; // r6
  double mass; // fp10
  int v13; // r11
  idClothParticle *v14; // r8
  int v15; // r8
  unsigned __int8 v16; // r30
  unsigned __int8 v17; // r30
  int v18; // r27
  int v19; // r28
  int v20; // r23
  int i; // r25
  double friction; // fp31
  idClothParticle *v23; // r4
  int num; // r11
  int size; // r10
  idClothSpring *list; // r9
  idClothSpring *v27; // r3
  double v28; // fp31
  idClothParticle *v29; // r4
  int v30; // r11
  int v31; // r10
  idClothSpring *v32; // r9
  idClothSpring *v33; // r3
  idList<idClothSpring,81> *p_springs; // r30
  double v35; // fp31
  idClothParticle *v36; // r4
  int v37; // r11
  int v38; // r10
  idClothSpring *v39; // r9
  idClothSpring *v40; // r3
  double v41; // fp31
  idClothParticle *v42; // r4
  int v43; // r11
  int v44; // r10
  idClothSpring *v45; // r9
  idClothSpring *v46; // r3
  double v47; // fp31
  idClothParticle *v48; // r4
  int v49; // r11
  int v50; // r10
  idClothSpring *v51; // r9
  idClothSpring *v52; // r3
  double v53; // fp31
  idList<idClothSpring,81> *v54; // r30
  char v55; // r29
  idClothParticle *v56; // r4
  int v57; // r11
  int v58; // r10
  idClothSpring *v59; // r9
  idClothSpring *v60; // r3
  double v61; // fp31
  idClothParticle *v62; // r4
  int v63; // r11
  int v64; // r10
  idClothSpring *v65; // r9
  idClothSpring *v66; // r3
  double v67; // fp31
  idClothParticle *v68; // r4
  int v69; // r11
  int v70; // r10
  idClothSpring *v71; // r9
  idClothSpring *v72; // r3

  height = this->height;
  v5 = 1;
  v6 = 0;
  v7 = 0;
  v8 = 0.0;
  v9 = 0.0;
  if ( height > 0 )
  {
    while ( 1 )
    {
      v10 = v8;
      v11 = 0;
      if ( v5 > 0 )
        break;
LABEL_20:
      height = this->height;
      ++v7;
      v5 += 2;
      v8 = (float)((float)v10 - this->hSpacing);
      v9 = (float)(this->vSpacing + (float)v9);
      if ( v7 >= height )
        goto LABEL_21;
    }
    while ( 1 )
    {
      mass = clothSystem->mass;
      v13 = v6;
      v14 = &this->cloth[v6];
      v14->origin.x = v8;
      v14->origin.y = v9;
      v14->origin.z = 0.0;
      v14->lastOrigin.x = v8;
      v14->lastOrigin.y = v9;
      v14->lastOrigin.z = 0.0;
      v14->mass = mass;
      v8 = (float)(this->hSpacing + (float)v8);
      if ( v6 != 0 )
      {
        v15 = this->height - 1;
        if ( v7 == v15 )
        {
          if ( v11 == 0 )
          {
            this->cloth[v13].neighbors[0] = v6 - v5 + 2;
            this->cloth[v13].neighbors[1] = v6 + 1;
            this->cloth[v13].neighbors[2] = v6;
            this->cloth[v13].neighbors[3] = v6;
            goto LABEL_19;
          }
          if ( v7 == v15 && v11 == v5 - 1 )
          {
            this->cloth[v13].neighbors[0] = v6 - v5;
            this->cloth[v13].neighbors[1] = v6;
            this->cloth[v13].neighbors[2] = v6;
            this->cloth[v13].neighbors[3] = v6 - 1;
            goto LABEL_19;
          }
        }
        if ( v11 != 0 )
        {
          if ( v11 == v5 - 1 )
          {
            v16 = v6 - 1;
            this->cloth[v13].neighbors[0] = v6 - v5;
            this->cloth[v13].neighbors[1] = v6;
            this->cloth[v13].neighbors[2] = v6 + v5 + 2;
LABEL_18:
            this->cloth[v13].neighbors[3] = v16;
            goto LABEL_19;
          }
          v17 = v6 + 1;
          if ( v7 != v15 )
          {
            this->cloth[v13].neighbors[0] = v6 - v5 + 1;
            this->cloth[v13].neighbors[1] = v17;
            v16 = v6 - 1;
            this->cloth[v13].neighbors[2] = v6 + v5 + 1;
            goto LABEL_18;
          }
          this->cloth[v13].neighbors[0] = v6 - v5 + 1;
          this->cloth[v13].neighbors[1] = v17;
          this->cloth[v13].neighbors[2] = v6;
          this->cloth[v13].neighbors[3] = v6 - 1;
        }
        else
        {
          this->cloth[v13].neighbors[0] = v6 - v5 + 2;
          this->cloth[v13].neighbors[1] = v6 + 1;
          this->cloth[v13].neighbors[2] = v6 + v5;
          this->cloth[v13].neighbors[3] = v6;
        }
      }
      else
      {
        this->cloth->neighbors[0] = 0;
        this->cloth->neighbors[1] = 3;
        this->cloth->neighbors[2] = 2;
        this->cloth->neighbors[3] = 0;
      }
LABEL_19:
      ++v11;
      ++v6;
      if ( v11 >= v5 )
        goto LABEL_20;
    }
  }
LABEL_21:
  v18 = 1;
  v19 = 0;
  v20 = 0;
  if ( height > 0 )
  {
    do
    {
      for ( i = 0; i < v18; ++v19 )
      {
        if ( i < v18 - 1 )
        {
          friction = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          num = this->springs.num;
          size = this->springs.size;
          list = this->springs.list;
          if ( num >= size )
          {
            v27 = &list[size - 1];
          }
          else
          {
            v27 = &list[num];
            this->springs.num = num + 1;
          }
          idClothSpring::Init(
            this: v27,
            friction,
            cloth: v23,
            p1: (int)this->cloth,
            p2: v19,
            band: v19 + 1,
            edge: false);
        }
        if ( i < v18 - 2 )
        {
          v28 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v30 = this->springs.num;
          v31 = this->springs.size;
          v32 = this->springs.list;
          if ( v30 >= v31 )
          {
            v33 = &v32[v31 - 1];
          }
          else
          {
            v33 = &v32[v30];
            this->springs.num = v30 + 1;
          }
          idClothSpring::Init(
            this: v33,
            friction: v28,
            cloth: v29,
            p1: (int)this->cloth,
            p2: v19,
            band: v19 + 2,
            edge: true);
        }
        if ( v20 < this->height - 1 )
        {
          p_springs = &this->springs;
          v35 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v37 = this->springs.num;
          v38 = this->springs.size;
          v39 = this->springs.list;
          if ( v37 >= v38 )
          {
            v40 = &v39[v38 - 1];
          }
          else
          {
            v40 = &v39[v37];
            this->springs.num = v37 + 1;
          }
          idClothSpring::Init(
            this: v40,
            friction: v35,
            cloth: v36,
            p1: (int)this->cloth,
            p2: v19,
            band: v19 + v18 + 1,
            edge: false);
          v41 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v43 = this->springs.num;
          v44 = this->springs.size;
          v45 = p_springs->list;
          if ( v43 >= v44 )
          {
            v46 = &v45[v44 - 1];
          }
          else
          {
            v46 = &v45[v43];
            this->springs.num = v43 + 1;
          }
          idClothSpring::Init(
            this: v46,
            friction: v41,
            cloth: v42,
            p1: (int)this->cloth,
            p2: v19,
            band: v19 + v18 + 2,
            edge: false);
          v47 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v49 = this->springs.num;
          v50 = this->springs.size;
          v51 = p_springs->list;
          if ( v49 >= v50 )
          {
            v52 = &v51[v50 - 1];
          }
          else
          {
            v52 = &v51[v49];
            this->springs.num = v49 + 1;
          }
          idClothSpring::Init(
            this: v52,
            friction: v47,
            cloth: v48,
            p1: (int)this->cloth,
            p2: v19,
            band: v18 + v19,
            edge: false);
        }
        if ( v20 < this->height - 2 )
        {
          v53 = clothSystem->friction;
          v54 = &this->springs;
          v55 = 2 * (v18 + 2) + v19;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v57 = this->springs.num;
          v58 = this->springs.size;
          v59 = this->springs.list;
          if ( v57 >= v58 )
          {
            v60 = &v59[v58 - 1];
          }
          else
          {
            v60 = &v59[v57];
            this->springs.num = v57 + 1;
          }
          idClothSpring::Init(
            this: v60,
            friction: v53,
            cloth: v56,
            p1: (int)this->cloth,
            p2: v19,
            band: 2 * (v18 + 2) + v19,
            edge: true);
          v61 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v63 = this->springs.num;
          v64 = this->springs.size;
          v65 = v54->list;
          if ( v63 >= v64 )
          {
            v66 = &v65[v64 - 1];
          }
          else
          {
            v66 = &v65[v63];
            this->springs.num = v63 + 1;
          }
          idClothSpring::Init(
            this: v66,
            friction: v61,
            cloth: v62,
            p1: (int)this->cloth,
            p2: v19,
            band: v55 - 2,
            edge: true);
          v67 = clothSystem->friction;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v69 = this->springs.num;
          v70 = this->springs.size;
          v71 = v54->list;
          if ( v69 >= v70 )
          {
            v72 = &v71[v70 - 1];
          }
          else
          {
            v72 = &v71[v69];
            this->springs.num = v69 + 1;
          }
          idClothSpring::Init(
            this: v72,
            friction: v67,
            cloth: v68,
            p1: (int)this->cloth,
            p2: v19,
            band: v55 + 2,
            edge: true);
        }
        ++i;
      }
      ++v20;
      v18 += 2;
    }
    while ( v20 < this->height );
  }
}


// ========================================================================
// ?Swap@idClothSim@@AAAXXZ
// EA  : 0x827AA908
// RVA : 0x007AA908
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::Swap(idClothSim *this)
{
  int v2; // r10
  char *v3; // r11
  char *v4; // r30
  char *v5; // r11
  char *v6; // r30
  float *v7; // r11
  float *clothBoundsFromJob; // r10

  v2 = this->currentDeferred ^ 1;
  this->currentDeferred = v2;
  v3 = (char *)this + 16 * v2;
  v4 = v3 + 212;
  if ( *((int *)v3 + 55) < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v3 + 212));
  *((_DWORD *)v4 + 1) = __CFADD__(-*((_DWORD *)v4 + 2), *((_DWORD *)v4 + 2) ^ 0x80000000) ? 0 : *((_DWORD *)v4 + 2);
  v5 = (char *)this + 16 * this->currentDeferred;
  v6 = v5 + 180;
  if ( *((int *)v5 + 47) < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(v5 + 180));
  *((_DWORD *)v6 + 1) = __CFADD__(-*((_DWORD *)v6 + 2), *((_DWORD *)v6 + 2) ^ 0x80000000) ? 0 : *((_DWORD *)v6 + 2);
  v7 = (float *)((char *)this + 16 * this->currentDeferred);
  v7[64] = 0.0;
  v7[63] = 0.0;
  v7[62] = 0.0;
  v7[61] = 0.0;
  clothBoundsFromJob = (float *)this->clothBoundsFromJob;
  this->clothBounds.b[0].x = *clothBoundsFromJob;
  this->clothBounds.b[0].y = clothBoundsFromJob[1];
  this->clothBounds.b[0].z = clothBoundsFromJob[2];
  this->clothBounds.b[1].x = clothBoundsFromJob[3];
  this->clothBounds.b[1].y = clothBoundsFromJob[4];
  this->clothBounds.b[1].z = clothBoundsFromJob[5];
}


// ========================================================================
// ?Run@idClothSim@@QAAXPAVidParallelJobList@@@Z
// EA  : 0x827AAA10
// RVA : 0x007AAA10
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::Run(idClothSim *this, idParallelJobList *parallelJobList)
{
  clothParms_t *clothParms; // r11
  float *v5; // r11
  clothParms_t *v6; // r11
  double gravity; // fp1
  clothParms_t *v8; // r11
  const idDeclCloth **v9; // r11
  clothParms_t *v10; // r10

  if ( this->numClothParticles <= 100 )
  {
    this->clothParms->type = this->clothDecl->type;
    this->clothParms->numIterations = 1;
    this->clothParms->cloth = this->cloth;
    this->clothParms->numClothParticles = this->numClothParticles;
    this->clothParms->springs = this->springs.list;
    this->clothParms->numSprings = this->springs.num;
    idList<idSphere,81>::Append(
      this: &this->temporaryCollisionSpheres[this->currentDeferred],
      other: &this->permanentCollisionSpheres);
    this->clothParms->collisions = this->temporaryCollisionSpheres[this->currentDeferred].list;
    this->clothParms->numCollisions = this->temporaryCollisionSpheres[this->currentDeferred].num;
    this->clothParms->weaponTraces = this->weaponTraces[this->currentDeferred].list;
    this->clothParms->numWeaponTraces = this->weaponTraces[this->currentDeferred].num;
    this->clothParms->vertices = nullptr;
    this->clothParms->bounds = this->clothBoundsFromJob;
    clothParms = this->clothParms;
    clothParms->org.x = this->origin.x;
    clothParms->org.y = this->origin.y;
    clothParms->org.z = this->origin.z;
    v5 = (float *)this->clothParms;
    v5[14] = this->axis.mat[0].x;
    v5[15] = this->axis.mat[0].y;
    v5[16] = this->axis.mat[0].z;
    v5[17] = this->axis.mat[1].x;
    v5[18] = this->axis.mat[1].y;
    v5[19] = this->axis.mat[1].z;
    v5[20] = this->axis.mat[2].x;
    v5[21] = this->axis.mat[2].y;
    v5[22] = this->axis.mat[2].z;
    this->clothParms->friction = this->clothDecl->friction;
    v6 = this->clothParms;
    gravity = this->clothDecl->gravity;
    v6->gravity.x = 0.0;
    v6->gravity.z = gravity;
    v6->gravity.y = 0.0;
    v8 = this->clothParms;
    v8->windDirection.x = this->windDirection.x;
    v8->windDirection.y = this->windDirection.y;
    v8->windDirection.z = this->windDirection.z;
    v9 = &this->clothDecl + 4 * this->currentDeferred;
    v10 = this->clothParms;
    LODWORD(v10->collisionPlane.a) = v9[61];
    LODWORD(v10->collisionPlane.b) = v9[62];
    LODWORD(v10->collisionPlane.c) = v9[63];
    LODWORD(v10->collisionPlane.d) = v9[64];
    this->clothParms->hasCollisionPlane = ((LODWORD(this->collisionPlane[this->currentDeferred].c)
                                          | LODWORD(this->collisionPlane[this->currentDeferred].b)
                                          | LODWORD(this->collisionPlane[this->currentDeferred].a))
                                         & 0x7FFFFFFF) != 0;
    this->clothParms->collisionFriction = this->clothDecl->collisionFriction;
    this->clothParms->width = this->width;
    this->clothParms->height = this->height;
    this->clothParms->vSpacing = this->vSpacing;
    this->clothParms->hSpacing = this->hSpacing;
    this->clothParms->rect = this->isRect;
    this->clothParms->timeDelta = this->timeDelta;
    if ( parallelJobList != nullptr && clothsim_useJobs.valueInteger == 1 )
      idParallelJobList::AddJob(
        this: parallelJobList,
        function: (void (__fastcall *)(void *))ClothGenJob,
        data: this->clothParms);
    else
      ClothGenJob(clothParms: this->clothParms);
    idClothSim::Swap(this);
  }
}


// ========================================================================
// ?GenerateRect@idClothSim@@AAAXPBVidDeclCloth@@@Z
// EA  : 0x827AAD68
// RVA : 0x007AAD68
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::GenerateRect(
        idClothSim *this,
        const idDeclCloth *clothSystem,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  int height; // r11
  int i; // r6
  int width; // r11
  int v12; // r7
  double v13; // fp13
  double hSpacing; // fp12
  double v15; // fp8
  double mass; // fp7
  double v17; // fp6
  idClothParticle *v18; // r11
  idClothParticle *cloth; // r11
  unsigned __int8 v20; // r5
  char *v21; // r4
  int v22; // r27
  int v23; // r11
  int v24; // r28
  double friction; // fp31
  int v26; // r29
  idClothParticle *v27; // r4
  int num; // r11
  int size; // r10
  idClothSpring *list; // r9
  idClothSpring *v31; // r3
  int v32; // r10
  double v33; // fp31
  char v34; // r29
  int v35; // r26
  idClothParticle *v36; // r4
  int v37; // r11
  int v38; // r10
  idClothSpring *v39; // r9
  idClothSpring *v40; // r3
  int v41; // r10
  double v42; // fp31
  char v43; // r29
  int v44; // r26
  idClothParticle *v45; // r4
  int v46; // r11
  int v47; // r10
  idClothSpring *v48; // r9
  idClothSpring *v49; // r3
  int v50; // r11
  double v51; // fp31
  char v52; // r29
  int v53; // r26
  idClothParticle *v54; // r4
  int v55; // r11
  int v56; // r10
  idClothSpring *v57; // r9
  idClothSpring *v58; // r3
  double v59; // fp31
  int v60; // r29
  idClothParticle *v61; // r4
  int v62; // r11
  int v63; // r10
  idClothSpring *v64; // r9
  idClothSpring *v65; // r3
  int v66; // r11
  double v67; // fp31
  char v68; // r29
  int v69; // r26
  idClothParticle *v70; // r4
  int v71; // r11
  int v72; // r10
  idClothSpring *v73; // r9
  idClothSpring *v74; // r3

  height = this->height;
  for ( i = 0; i < height; ++i )
  {
    width = this->width;
    v12 = 0;
    if ( width > 0 )
    {
      LODWORD(a7) = i;
      v13 = (float)a7;
      do
      {
        LODWORD(a7) = v12;
        hSpacing = this->hSpacing;
        v15 = (float)a7;
        LODWORD(a7) = width * i + v12;
        mass = clothSystem->mass;
        v17 = (float)(this->vSpacing * (float)v13);
        HIDWORD(a7) = 96 * a7;
        v18 = &this->cloth[a7];
        v18->origin.x = (float)v15 * this->hSpacing;
        v18->origin.z = 0.0;
        v18->origin.y = v17;
        v18->lastOrigin.x = (float)v15 * (float)hSpacing;
        v18->lastOrigin.y = v17;
        v18->lastOrigin.z = 0.0;
        v18->mass = mass;
        if ( i != 0 )
        {
          cloth = this->cloth;
          if ( i == this->height - 1 )
          {
            cloth->neighbors[HIDWORD(a7)] = a7 - HIBYTE(this->width);
            this->cloth->neighbors[HIDWORD(a7) + 2] = a7;
          }
          else
          {
            cloth->neighbors[HIDWORD(a7)] = a7 - HIBYTE(this->width);
            this->cloth->neighbors[HIDWORD(a7) + 2] = a7 + this->width;
          }
        }
        else
        {
          this->cloth->neighbors[HIDWORD(a7)] = a7;
          this->cloth->neighbors[HIDWORD(a7) + 2] = a7 + this->width;
        }
        if ( v12 != 0 )
        {
          v20 = a7 - 1;
          v21 = (char *)this->cloth + HIDWORD(a7);
          if ( v12 == this->width - 1 )
          {
            v21[89] = a7;
            this->cloth->neighbors[HIDWORD(a7) + 3] = v20;
          }
          else
          {
            v21[89] = a7 + 1;
            HIDWORD(a7) += this->cloth;
            *(_BYTE *)(HIDWORD(a7) + 91) = v20;
          }
        }
        else
        {
          this->cloth->neighbors[HIDWORD(a7) + 1] = a7 + 1;
          this->cloth->neighbors[HIDWORD(a7) + 3] = a7;
        }
        width = this->width;
        ++v12;
      }
      while ( v12 < width );
    }
    height = this->height;
  }
  v22 = 0;
  if ( height > 0 )
  {
    while ( 1 )
    {
      v23 = this->width;
      v24 = 0;
      if ( v23 > 0 )
        break;
LABEL_52:
      if ( ++v22 >= this->height )
        return;
    }
    while ( 1 )
    {
      if ( v24 >= v23 - 1 )
        goto LABEL_28;
      friction = clothSystem->friction;
      v26 = v22 * this->width + v24;
      idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
      num = this->springs.num;
      size = this->springs.size;
      list = this->springs.list;
      if ( num >= size )
      {
        v31 = &list[size - 1];
      }
      else
      {
        v31 = &list[num];
        this->springs.num = num + 1;
      }
      idClothSpring::Init(this: v31, friction, cloth: v27, p1: (int)this->cloth, p2: v26, band: v26 + 1, edge: false);
      if ( clothSystem->springType != CLOTH_SPRING_QUAD )
        break;
LABEL_35:
      if ( v22 < this->height - 1 )
      {
        v50 = this->width;
        v51 = clothSystem->friction;
        v52 = (v22 + 1) * v50 + v24;
        v53 = v50 * v22 + v24;
        idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
        v55 = this->springs.num;
        v56 = this->springs.size;
        v57 = this->springs.list;
        if ( v55 >= v56 )
        {
          v58 = &v57[v56 - 1];
        }
        else
        {
          v58 = &v57[v55];
          this->springs.num = v55 + 1;
        }
        idClothSpring::Init(this: v58, friction: v51, cloth: v54, p1: (int)this->cloth, p2: v53, band: v52, edge: false);
      }
      if ( clothSystem->springType == CLOTH_SPRING_BANDED )
      {
        if ( v24 < this->width - 2 )
        {
          v59 = clothSystem->friction;
          v60 = v22 * this->width + v24;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v62 = this->springs.num;
          v63 = this->springs.size;
          v64 = this->springs.list;
          if ( v62 >= v63 )
          {
            v65 = &v64[v63 - 1];
          }
          else
          {
            v65 = &v64[v62];
            this->springs.num = v62 + 1;
          }
          idClothSpring::Init(
            this: v65,
            friction: v59,
            cloth: v61,
            p1: (int)this->cloth,
            p2: v60,
            band: v60 + 2,
            edge: true);
        }
        if ( v22 < this->height - 2 )
        {
          v66 = this->width;
          v67 = clothSystem->friction;
          v68 = (v22 + 2) * v66 + v24;
          v69 = v66 * v22 + v24;
          idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
          v71 = this->springs.num;
          v72 = this->springs.size;
          v73 = this->springs.list;
          if ( v71 >= v72 )
          {
            v74 = &v73[v72 - 1];
          }
          else
          {
            v74 = &v73[v71];
            this->springs.num = v71 + 1;
          }
          idClothSpring::Init(
            this: v74,
            friction: v67,
            cloth: v70,
            p1: (int)this->cloth,
            p2: v69,
            band: v68,
            edge: true);
        }
      }
      v23 = this->width;
      if ( ++v24 >= v23 )
        goto LABEL_52;
    }
    if ( v22 < this->height - 1 )
    {
      v32 = this->width;
      v33 = clothSystem->friction;
      v34 = (v22 + 1) * v32 + v24 + 1;
      v35 = v32 * v22 + v24;
      idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
      v37 = this->springs.num;
      v38 = this->springs.size;
      v39 = this->springs.list;
      if ( v37 >= v38 )
      {
        v40 = &v39[v38 - 1];
      }
      else
      {
        v40 = &v39[v37];
        this->springs.num = v37 + 1;
      }
      idClothSpring::Init(this: v40, friction: v33, cloth: v36, p1: (int)this->cloth, p2: v35, band: v34, edge: false);
    }
LABEL_28:
    if ( clothSystem->springType != CLOTH_SPRING_QUAD && v24 > 0 && v22 < this->height - 1 )
    {
      v41 = this->width;
      v42 = clothSystem->friction;
      v43 = (v22 + 1) * v41 + v24 - 1;
      v44 = v41 * v22 + v24;
      idList<idClothSpring,81>::PreAllocateWithGranularity(this: &this->springs, newSize: this->springs.num + 1);
      v46 = this->springs.num;
      v47 = this->springs.size;
      v48 = this->springs.list;
      if ( v46 >= v47 )
      {
        v49 = &v48[v47 - 1];
      }
      else
      {
        v49 = &v48[v46];
        this->springs.num = v46 + 1;
      }
      idClothSpring::Init(this: v49, friction: v42, cloth: v45, p1: (int)this->cloth, p2: v44, band: v43, edge: false);
    }
    goto LABEL_35;
  }
}


// ========================================================================
// ?AddWeaponTrace@idClothSim@@QAAXABVidVec3@@0M_N@Z
// EA  : 0x827AB380
// RVA : 0x007AB380
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __fastcall idClothSim::AddWeaponTrace(
        idClothSim *this,
        const idVec3 *start,
        const idVec3 *dir,
        double strength,
        bool causesHoles,
        bool a6)
{
  clothWeaponTrace_t *v10; // r3

  v10 = idList<clothWeaponTrace_t,81>::Alloc(this: &this->weaponTraces[this->currentDeferred]);
  v10->start = *start;
  v10->dir = *dir;
  v10->causesHoles = a6;
  v10->strength = strength;
}


// ========================================================================
// ??0idClothSim@@QAA@HHMMPBVidDeclCloth@@_N@Z
// EA  : 0x827AB400
// RVA : 0x007AB400
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

idClothSim *__fastcall idClothSim::idClothSim(
        idClothSim *this,
        int w,
        int h,
        double hGridSpacing,
        double vGridSpacing,
        const idDeclCloth *clothSystem,
        bool rect,
        const idDeclCloth *a8,
        bool a9)
{
  float *p_y; // r9
  int v16; // ctr
  float *p_z; // r10
  int v19; // r29
  idBounds *v20; // r3
  int v21; // r11
  __int64 v22; // r10
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  idClothParticle *v27; // r3
  int numClothParticles; // r4
  int v29; // r28

  this->clothDecl = a8;
  this->origin = vec3_origin;
  p_y = &mat2_identity.mat[1].y;
  v16 = 9;
  p_z = &this->origin.z;
  do
  {
    *++p_z = *++p_y;
    --v16;
  }
  while ( v16 != 0 );
  v19 = 0;
  this->windDirection = vec3_origin;
  this->gravity.x = 0.0;
  this->gravity.y = 0.0;
  this->gravity.z = -1.0;
  this->numIterations = 1;
  this->timeDelta = 0.016000001;
  this->currentDeferred = 0;
  this->clothBoundsFromJob = nullptr;
  this->springs.list = nullptr;
  this->springs.granularity = 0;
  this->springs.memTag = 81;
  this->springs.listStatic = 0;
  this->springs.size = 0;
  this->springs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->springs);
  this->permanentCollisionSpheres.list = nullptr;
  this->permanentCollisionSpheres.granularity = 0;
  this->permanentCollisionSpheres.memTag = 81;
  this->permanentCollisionSpheres.listStatic = 0;
  this->permanentCollisionSpheres.size = 0;
  this->permanentCollisionSpheres.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->permanentCollisionSpheres);
  `eh vector constructor iterator'(
    ptr: this->temporaryCollisionSpheres,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<idSphere,81>::idList<idSphere,81>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  `eh vector constructor iterator'(
    ptr: this->weaponTraces,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<idSphere,81>::idList<idSphere,81>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( w * h > 100 )
    idLib::Error(
      fmt: "Cloth system '%s' has too many particles (%d).  Decrease the width and/or height to be less than %d.",
      a8->name.str,
      w * h,
      100);
  this->clothParms = (clothParms_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(101) : TAG_CLOTH",
                                       size: 0xACu,
                                       tag: TAG_CLOTH,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  v20 = (idBounds *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(102) : TAG_CLOTH",
                      size: 0x18u,
                      tag: TAG_CLOTH,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  this->clothBoundsFromJob = v20;
  v20->b[1].z = 0.0;
  v20->b[1].y = 0.0;
  v20->b[1].x = 0.0;
  v20->b[0].z = 0.0;
  v20->b[0].y = 0.0;
  v20->b[0].x = 0.0;
  this->clothBounds.b[1].z = 0.0;
  this->clothBounds.b[1].y = 0.0;
  this->clothBounds.b[1].x = 0.0;
  this->clothBounds.b[0].z = 0.0;
  this->clothBounds.b[0].y = 0.0;
  this->clothBounds.b[0].x = 0.0;
  this->width = w;
  this->isRect = a9;
  if ( a9 )
  {
    this->height = h;
    this->numClothParticles = w * h;
  }
  else
  {
    if ( (w & 1) == 0 )
      this->width = w + 1;
    v21 = (this->width + 1) / 2;
    this->height = v21;
    this->numClothParticles = v21 * v21;
  }
  v27 = (idClothParticle *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\models\\cloth\\ClothSim.cpp(120) : TAG_CLOTH",
                             size: (96 * this->numClothParticles + 15) & 0xFFFFFFF0,
                             tag: TAG_CLOTH,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  numClothParticles = this->numClothParticles;
  this->cloth = v27;
  v29 = 0;
  if ( numClothParticles > 0 )
  {
    do
    {
      idClothParticle::Reset(this: &this->cloth[v19]);
      ++v29;
      ++v19;
    }
    while ( v29 < this->numClothParticles );
  }
  this->hSpacing = hGridSpacing;
  this->vSpacing = vGridSpacing;
  if ( a9 )
    idClothSim::GenerateRect(this, clothSystem: a8, a3: v26, a4: v25, a5: v24, a6: v23, a7: v22);
  else
    idClothSim::GenerateTriangle(this, clothSystem: a8);
  this->collisionPlane[0].d = 0.0;
  this->collisionPlane[0].c = 0.0;
  this->collisionPlane[0].b = 0.0;
  this->collisionPlane[0].a = 0.0;
  this->collisionPlane[1].d = 0.0;
  this->collisionPlane[1].c = 0.0;
  this->collisionPlane[1].b = 0.0;
  this->collisionPlane[1].a = 0.0;
  return this;
}


// ========================================================================
// $LN95
// EA  : 0x827AB748
// RVA : 0x007AB748
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _LN95()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 148));
}


// ========================================================================
// __unwind$225027
// EA  : 0x827AB774
// RVA : 0x007AB774
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_225027()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 164));
}


// ========================================================================
// __unwind$225028
// EA  : 0x827AB7A0
// RVA : 0x007AB7A0
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_225028()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 208 + 228) + 180),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$225029
// EA  : 0x827AB7DC
// RVA : 0x007AB7DC
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void _unwind_225029()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 208 + 228) + 212),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// `dynamic initializer for 'g_showClothBounds''
// EA  : 0x833421C0
// RVA : 0x013421C0
// PDB : w:\tech5\engine\models\cloth\clothsim.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showClothBounds__()
{
  idCVar::idCVar(
    this: &g_showClothBounds,
    name: "g_showClothBounds",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showClothBounds__);
}

