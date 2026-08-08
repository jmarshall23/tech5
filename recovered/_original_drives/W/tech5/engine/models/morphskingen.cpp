
// ========================================================================
// ?SkinMeshMorphPoint@morphShape_t@@AAA_NABVidVec3@@AAV2@@Z
// EA  : 0x827DAB38
// RVA : 0x007DAB38
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

BOOL __fastcall morphShape_t::SkinMeshMorphPoint(morphShape_t *this, const idVec3 *inPoint, idVec3 *outPoint)
{
  int v3; // r31
  int v4; // r11
  int num; // r6
  double v6; // fp9
  double v7; // fp10
  idVec3 *list; // r7
  int v9; // r8
  float *p_x; // r10
  double v11; // fp8
  double v12; // fp6
  double v13; // fp4
  double v14; // fp0
  double v15; // fp8
  double v16; // fp6
  double v17; // fp4
  double v18; // fp0
  int v19; // r9
  idVec3 *v20; // r10
  double v21; // fp8
  double v22; // fp6
  double v23; // fp4
  double v24; // fp0
  double v25; // fp8
  double v26; // fp6
  double v27; // fp4
  double v28; // fp0
  idVec3 *v29; // r8
  int v30; // r9
  int v31; // ctr
  double v32; // fp8
  double v33; // fp6
  double v34; // fp4
  double v35; // fp0

  v3 = -1;
  v4 = 0;
  outPoint->z = 0.0;
  outPoint->y = 0.0;
  outPoint->x = 0.0;
  num = this->points.num;
  v6 = 1.0e30;
  v7 = `morphShape_t::SkinMeshMorphPoint'::`4'::thresh;
  if ( num >= 4 )
  {
    list = this->points.list;
    v9 = 0;
    do
    {
      p_x = &list[v9].x;
      v11 = (float)(list[v9].x - inPoint->x);
      v12 = (float)(list[v9].y - inPoint->y);
      v13 = (float)(list[v9].z - inPoint->z);
      v14 = (float)((float)((float)v13 * (float)v13)
                  + (float)((float)((float)v11 * (float)v11) + (float)((float)v12 * (float)v12)));
      if ( v14 < v7 && v14 < v6 )
      {
        v3 = v4;
        v6 = (float)((float)((float)v13 * (float)v13)
                   + (float)((float)((float)v11 * (float)v11) + (float)((float)v12 * (float)v12)));
      }
      v15 = (float)(p_x[4] - inPoint->y);
      v16 = (float)(p_x[3] - inPoint->x);
      v17 = (float)(p_x[5] - inPoint->z);
      v18 = (float)((float)((float)v17 * (float)v17)
                  + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)));
      if ( v18 < v7 && v18 < v6 )
      {
        v3 = v4 + 1;
        v6 = (float)((float)((float)v17 * (float)v17)
                   + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)));
      }
      v19 = v9 * 12 + 36;
      v20 = &list[v9 + 3];
      v21 = (float)(v20[-1].y - inPoint->y);
      v22 = (float)(v20[-1].x - inPoint->x);
      v23 = (float)(v20[-1].z - inPoint->z);
      v24 = (float)((float)((float)v23 * (float)v23)
                  + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)));
      if ( v24 < v7 && v24 < v6 )
      {
        v3 = v4 + 2;
        v6 = (float)((float)((float)v23 * (float)v23)
                   + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)));
      }
      v25 = (float)(*(float *)((char *)&list->x + v19) - inPoint->x);
      v26 = (float)(*(float *)((char *)&list->y + v19) - inPoint->y);
      v27 = (float)(*(float *)((char *)&list->z + v19) - inPoint->z);
      v28 = (float)((float)((float)v27 * (float)v27)
                  + (float)((float)((float)v25 * (float)v25) + (float)((float)v26 * (float)v26)));
      if ( v28 < v7 && v28 < v6 )
      {
        v3 = v4 + 3;
        v6 = (float)((float)((float)v27 * (float)v27)
                   + (float)((float)((float)v25 * (float)v25) + (float)((float)v26 * (float)v26)));
      }
      v4 += 4;
      v9 += 4;
    }
    while ( v4 < num - 3 );
  }
  if ( v4 < num )
  {
    v29 = this->points.list;
    v30 = v4;
    v31 = num - v4;
    do
    {
      v32 = (float)(v29[v30].x - inPoint->x);
      v33 = (float)(v29[v30].y - inPoint->y);
      v34 = (float)(v29[v30].z - inPoint->z);
      v35 = (float)((float)((float)v34 * (float)v34)
                  + (float)((float)((float)v32 * (float)v32) + (float)((float)v33 * (float)v33)));
      if ( v35 < v7 && v35 < v6 )
      {
        v3 = v4;
        v6 = (float)((float)((float)v34 * (float)v34)
                   + (float)((float)((float)v32 * (float)v32) + (float)((float)v33 * (float)v33)));
      }
      ++v4;
      ++v30;
      --v31;
    }
    while ( v31 != 0 );
  }
  return v3 != -1;
}


// ========================================================================
// ?SphereContainsPoint@morphShape_t@@AAA_NABVidVec3@@AAV2@@Z
// EA  : 0x827DAD28
// RVA : 0x007DAD28
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

BOOL __fastcall morphShape_t::SphereContainsPoint(morphShape_t *this, const idVec3 *inPoint, idVec3 *outPoint)
{
  double v3; // fp8
  double v4; // fp7
  double v5; // fp4

  outPoint->z = 0.0;
  outPoint->y = 0.0;
  outPoint->x = 0.0;
  v3 = (float)(inPoint->z - this->center.z);
  v4 = (float)(inPoint->x - this->center.x);
  v5 = (float)(inPoint->y - this->center.y);
  return (float)((float)((float)v5 * (float)v5)
               + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))) <= (double)this->radiusSqr;
}


// ========================================================================
// ?MakeSphere@morphShape_t@@AAA_NPAVidTriangles@@PBVidDrawVert@@PBVidDecl@@@Z
// EA  : 0x827DAD88
// RVA : 0x007DAD88
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall morphShape_t::MakeSphere(
        morphShape_t *this,
        idTriangles *morphTris,
        const idDrawVert *morphTriVerts,
        const idDecl *decl)
{
  int numVerts; // r9
  int v6; // r10
  float *p_z; // r11
  const idDrawVert *v56; // r11
  int v57; // ctr
  double v64; // fp8
  double v65; // fp7
  double v66; // fp13

  numVerts = morphTris->numVerts;
  if ( numVerts >= 16 )
  {
    v6 = 0;
    _FP0 = 1.0e30;
    _FP12 = -1.0e30;
    _FP13 = 1.0e30;
    _FP11 = 1.0e30;
    _FP9 = -1.0e30;
    _FP10 = -1.0e30;
    p_z = &morphTriVerts[1].xyz.z;
    do
    {
      v6 += 4;
      _FP6 = (float)((float)_FP0 - *(p_z - 10));
      _FP4 = (float)((float)_FP11 - *(p_z - 9));
      _FP1 = (float)(*(p_z - 10) - (float)_FP12);
      _FP3 = (float)((float)_FP13 - *(p_z - 8));
      _FP7 = (float)(*(p_z - 9) - (float)_FP10);
      _FP5 = (float)(*(p_z - 8) - (float)_FP9);
      __asm { fsel      f0, f6, f8, f0 }
      __asm
      {
        fsel      f12, f1, f8, f12
        fsel      f4, f4, f2, f11
      }
      __asm { fsel      f3, f3, f31, f13 }
      __asm { fsel      f7, f7, f2, f10 }
      __asm { fsel      f1, f5, f31, f9 }
      _FP23 = (float)((float)_FP0 - *(p_z - 2));
      _FP20 = (float)(*(p_z - 2) - (float)_FP12);
      _FP22 = (float)((float)_FP4 - *(p_z - 1));
      _FP21 = (float)((float)_FP3 - *p_z);
      _FP29 = (float)(*(p_z - 1) - (float)_FP7);
      _FP28 = (float)(*p_z - (float)_FP1);
      __asm
      {
        fsel      f0, f23, f30, f0
        fsel      f12, f20, f30, f12
        fsel      f4, f22, f27, f4
        fsel      f3, f21, f25, f3
        fsel      f7, f29, f27, f7
        fsel      f1, f28, f25, f1
      }
      _FP30 = (float)((float)_FP0 - p_z[6]);
      _FP27 = (float)(p_z[6] - (float)_FP12);
      _FP29 = (float)((float)_FP4 - p_z[7]);
      _FP28 = (float)((float)_FP3 - p_z[8]);
      _FP11 = (float)(p_z[7] - (float)_FP7);
      _FP13 = (float)(p_z[8] - (float)_FP1);
      __asm
      {
        fsel      f0, f30, f6, f0
        fsel      f12, f27, f6, f12
        fsel      f4, f29, f8, f4
        fsel      f3, f28, f2, f3
        fsel      f8, f11, f8, f7
        fsel      f7, f13, f2, f1
      }
      _FP6 = (float)((float)_FP0 - p_z[14]);
      _FP30 = (float)(p_z[14] - (float)_FP12);
      _FP2 = (float)((float)_FP4 - p_z[15]);
      _FP1 = (float)((float)_FP3 - p_z[16]);
      _FP9 = (float)(p_z[15] - (float)_FP8);
      _FP5 = (float)(p_z[16] - (float)_FP7);
      p_z += 32;
      __asm
      {
        fsel      f0, f6, f10, f0
        fsel      f12, f30, f10, f12
        fsel      f11, f2, f31, f4
        fsel      f13, f1, f24, f3
        fsel      f10, f9, f31, f8
        fsel      f9, f5, f24, f7
      }
    }
    while ( v6 < numVerts - 3 );
    if ( v6 < numVerts )
    {
      v56 = &morphTriVerts[v6];
      v57 = numVerts - v6;
      do
      {
        _FP4 = (float)((float)_FP13 - v56->xyz.z);
        _FP6 = (float)((float)_FP0 - v56->xyz.x);
        _FP2 = (float)(v56->xyz.x - (float)_FP12);
        _FP3 = (float)((float)_FP11 - v56->xyz.y);
        _FP30 = (float)(v56->xyz.z - (float)_FP9);
        _FP1 = (float)(v56->xyz.y - (float)_FP10);
        ++v56;
        __asm
        {
          fsel      f13, f4, f7, f13
          fsel      f0, f6, f8, f0
          fsel      f12, f2, f8, f12
          fsel      f11, f3, f31, f11
          fsel      f9, f30, f7, f9
          fsel      f10, f1, f31, f10
        }
        --v57;
      }
      while ( v57 != 0 );
    }
    v64 = (float)((float)_FP12 - (float)_FP0);
    v65 = (float)((float)_FP10 - (float)_FP11);
    this->center.x = (float)((float)_FP12 + (float)_FP0) * (float)0.5;
    this->center.z = (float)((float)_FP9 + (float)_FP13) * (float)0.5;
    v66 = (float)((float)_FP9 - (float)_FP13);
    this->center.y = (float)((float)_FP11 + (float)_FP10) * (float)0.5;
    if ( v64 <= v65 )
    {
      if ( v65 > v66 )
        v66 = (float)((float)_FP10 - (float)_FP11);
    }
    else if ( v64 > v66 )
    {
      v66 = (float)((float)_FP12 - (float)_FP0);
    }
    this->radius = (float)v66 * (float)0.5;
    this->radiusSqr = (float)((float)v66 * (float)0.5) * (float)((float)v66 * (float)0.5);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Bad Clip Sphere for %s, too few vertices", decl->name.str);
    return 0;
  }
}


// ========================================================================
// ?MakeEllipsoid@morphShape_t@@AAA_NPAVidTriangles@@PBVidDrawVert@@PBVidDecl@@@Z
// EA  : 0x827DB010
// RVA : 0x007DB010
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall morphShape_t::MakeEllipsoid(
        morphShape_t *this,
        idTriangles *morphTris,
        const idDrawVert *morphTriVerts,
        const idDecl *decl)
{
  int numVerts; // r9
  int v7; // r10
  float *p_z; // r11
  const idDrawVert *v57; // r11
  int v58; // ctr
  idVec3 *p_center; // r30
  int v66; // r4
  int v67; // r8
  int v68; // r11
  int v69; // r3
  double v70; // fp0
  double v71; // fp9
  int v72; // r10
  float *v73; // r9
  double v74; // fp7
  double v75; // fp5
  double v76; // fp3
  double v77; // fp13
  double v78; // fp5
  double v79; // fp3
  double v80; // fp13
  double v81; // fp7
  double v82; // fp5
  double v83; // fp3
  double v84; // fp13
  double v85; // fp7
  double v86; // fp5
  double v87; // fp3
  double v88; // fp13
  float *v89; // r10
  int v90; // ctr
  double v91; // fp5
  double v92; // fp3
  double v93; // fp13
  const idDrawVert *v94; // r11
  const idDrawVert *v95; // r10
  double v96; // fp6
  double v97; // fp5
  idVec3 *p_yAxis; // r29
  double z; // fp0
  double v100; // fp13
  double v101; // fp10
  double x; // fp7
  double v103; // fp6
  double v104; // fp29
  double v106; // fp2
  double v108; // fp13
  double v109; // fp1
  double v110; // fp28
  double v111; // fp6
  double y; // fp5
  double v113; // fp27
  double v115; // fp1
  double v117; // fp12
  double v118; // fp8
  double v119; // fp26
  int (*RW)(void); // ctr
  double v121; // fp13
  double v122; // fp11
  double v123; // fp9
  double v124; // fp7
  double v125; // fp4
  double v126; // fp8
  double v127; // fp3
  double v128; // fp2
  int v129; // r3
  double v130; // fp9
  double v131; // fp4
  idRenderWorld *v132; // r3
  double v133; // fp1
  double v134; // fp10
  double v135; // fp9
  idRenderWorld *v136; // r3
  double v137; // fp2
  double v138; // fp0
  double v139; // fp8
  double v140; // fp6
  int v141; // r8
  double v142; // fp0
  double v143; // fp2
  double v144; // fp12
  int v145; // r10
  idDrawVert *verts; // r6
  int v147; // r9
  float *p_x; // r11
  int v149; // r7
  idDrawVert *v150; // r11
  idDrawVert *v151; // r9
  int v152; // r10
  int v153; // ctr
  double v154; // fp0
  double v155; // fp12
  double v157; // fp11
  float v158[4]; // [sp+50h] [-100h] BYREF
  float v159[4]; // [sp+60h] [-F0h] BYREF
  float v160[4]; // [sp+70h] [-E0h] BYREF
  float v161[4]; // [sp+80h] [-D0h] BYREF
  float v162[4]; // [sp+90h] [-C0h] BYREF
  float v163[30]; // [sp+A0h] [-B0h] BYREF

  numVerts = morphTris->numVerts;
  v7 = 0;
  _FP0 = 1.0e30;
  _FP12 = -1.0e30;
  _FP13 = 1.0e30;
  _FP11 = 1.0e30;
  _FP9 = -1.0e30;
  _FP10 = -1.0e30;
  if ( numVerts >= 4 )
  {
    p_z = &morphTriVerts[1].xyz.z;
    do
    {
      v7 += 4;
      _FP6 = (float)((float)_FP0 - *(p_z - 10));
      _FP4 = (float)((float)_FP11 - *(p_z - 9));
      _FP1 = (float)(*(p_z - 10) - (float)_FP12);
      _FP3 = (float)((float)_FP13 - *(p_z - 8));
      _FP7 = (float)(*(p_z - 9) - (float)_FP10);
      _FP5 = (float)(*(p_z - 8) - (float)_FP9);
      __asm { fsel      f0, f6, f8, f0 }
      __asm
      {
        fsel      f12, f1, f8, f12
        fsel      f4, f4, f2, f11
      }
      __asm { fsel      f3, f3, f31, f13 }
      __asm { fsel      f7, f7, f2, f10 }
      __asm { fsel      f1, f5, f31, f9 }
      _FP23 = (float)((float)_FP0 - *(p_z - 2));
      _FP20 = (float)(*(p_z - 2) - (float)_FP12);
      _FP22 = (float)((float)_FP4 - *(p_z - 1));
      _FP21 = (float)((float)_FP3 - *p_z);
      _FP29 = (float)(*(p_z - 1) - (float)_FP7);
      _FP28 = (float)(*p_z - (float)_FP1);
      __asm
      {
        fsel      f0, f23, f30, f0
        fsel      f12, f20, f30, f12
        fsel      f4, f22, f27, f4
        fsel      f3, f21, f25, f3
        fsel      f7, f29, f27, f7
        fsel      f1, f28, f25, f1
      }
      _FP30 = (float)((float)_FP0 - p_z[6]);
      _FP27 = (float)(p_z[6] - (float)_FP12);
      _FP29 = (float)((float)_FP4 - p_z[7]);
      _FP28 = (float)((float)_FP3 - p_z[8]);
      _FP11 = (float)(p_z[7] - (float)_FP7);
      _FP13 = (float)(p_z[8] - (float)_FP1);
      __asm
      {
        fsel      f0, f30, f6, f0
        fsel      f12, f27, f6, f12
        fsel      f4, f29, f8, f4
        fsel      f3, f28, f2, f3
        fsel      f8, f11, f8, f7
        fsel      f7, f13, f2, f1
      }
      _FP6 = (float)((float)_FP0 - p_z[14]);
      _FP30 = (float)(p_z[14] - (float)_FP12);
      _FP2 = (float)((float)_FP4 - p_z[15]);
      _FP1 = (float)((float)_FP3 - p_z[16]);
      _FP9 = (float)(p_z[15] - (float)_FP8);
      _FP5 = (float)(p_z[16] - (float)_FP7);
      p_z += 32;
      __asm
      {
        fsel      f0, f6, f10, f0
        fsel      f12, f30, f10, f12
        fsel      f11, f2, f31, f4
        fsel      f13, f1, f24, f3
        fsel      f10, f9, f31, f8
        fsel      f9, f5, f24, f7
      }
    }
    while ( v7 < numVerts - 3 );
  }
  if ( v7 < numVerts )
  {
    v57 = &morphTriVerts[v7];
    v58 = numVerts - v7;
    do
    {
      _FP4 = (float)((float)_FP13 - v57->xyz.z);
      _FP6 = (float)((float)_FP0 - v57->xyz.x);
      _FP2 = (float)(v57->xyz.x - (float)_FP12);
      _FP3 = (float)((float)_FP11 - v57->xyz.y);
      _FP30 = (float)(v57->xyz.z - (float)_FP9);
      _FP1 = (float)(v57->xyz.y - (float)_FP10);
      ++v57;
      __asm
      {
        fsel      f13, f4, f7, f13
        fsel      f0, f6, f8, f0
        fsel      f12, f2, f8, f12
        fsel      f11, f3, f31, f11
        fsel      f9, f30, f7, f9
        fsel      f10, f1, f31, f10
      }
      --v58;
    }
    while ( v58 != 0 );
  }
  p_center = &this->center;
  v66 = -1;
  v67 = -1;
  v68 = 0;
  this->center.z = (float)((float)_FP9 + (float)_FP13) * (float)0.5;
  this->center.x = (float)((float)_FP12 + (float)_FP0) * (float)0.5;
  this->center.y = (float)((float)_FP10 + (float)_FP11) * (float)0.5;
  v69 = morphTris->numVerts;
  v70 = -1.0e30;
  v71 = 1.0e30;
  if ( v69 >= 4 )
  {
    v72 = 2;
    v73 = &morphTriVerts[1].xyz.z;
    do
    {
      v74 = (float)(*(v73 - 8) - p_center->z);
      v75 = (float)(*(v73 - 10) - p_center->x);
      v76 = (float)(*(v73 - 9) - p_center->y);
      v77 = (float)((float)((float)v76 * (float)v76)
                  + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)));
      if ( v77 > v70 )
      {
        v70 = (float)((float)((float)v76 * (float)v76)
                    + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)));
        v66 = v68;
      }
      if ( v77 < v71 )
      {
        v71 = (float)((float)((float)v76 * (float)v76)
                    + (float)((float)((float)v75 * (float)v75) + (float)((float)v74 * (float)v74)));
        v67 = v68;
      }
      v78 = (float)(*(v73 - 2) - p_center->x);
      v79 = (float)(*(v73 - 1) - p_center->y);
      v80 = (float)((float)((float)v79 * (float)v79)
                  + (float)((float)((float)v78 * (float)v78)
                          + (float)((float)(*v73 - p_center->z) * (float)(*v73 - p_center->z))));
      if ( v80 > v70 )
      {
        v70 = (float)((float)((float)v79 * (float)v79)
                    + (float)((float)((float)v78 * (float)v78)
                            + (float)((float)(*v73 - this->center.z) * (float)(*v73 - this->center.z))));
        v66 = v72 - 1;
      }
      if ( v80 < v71 )
      {
        v71 = (float)((float)((float)v79 * (float)v79)
                    + (float)((float)((float)v78 * (float)v78)
                            + (float)((float)(*v73 - this->center.z) * (float)(*v73 - this->center.z))));
        v67 = v72 - 1;
      }
      v81 = (float)(v73[8] - p_center->z);
      v82 = (float)(v73[6] - p_center->x);
      v83 = (float)(v73[7] - p_center->y);
      v84 = (float)((float)((float)v83 * (float)v83)
                  + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)));
      if ( v84 > v70 )
      {
        v70 = (float)((float)((float)v83 * (float)v83)
                    + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)));
        v66 = v72;
      }
      if ( v84 < v71 )
      {
        v71 = (float)((float)((float)v83 * (float)v83)
                    + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)));
        v67 = v72;
      }
      v85 = (float)(v73[16] - p_center->z);
      v86 = (float)(v73[14] - p_center->x);
      v87 = (float)(v73[15] - p_center->y);
      v88 = (float)((float)((float)v87 * (float)v87)
                  + (float)((float)((float)v86 * (float)v86) + (float)((float)v85 * (float)v85)));
      if ( v88 > v70 )
      {
        v70 = (float)((float)((float)v87 * (float)v87)
                    + (float)((float)((float)v86 * (float)v86) + (float)((float)v85 * (float)v85)));
        v66 = v72 + 1;
      }
      if ( v88 < v71 )
      {
        v71 = (float)((float)((float)v87 * (float)v87)
                    + (float)((float)((float)v86 * (float)v86) + (float)((float)v85 * (float)v85)));
        v67 = v72 + 1;
      }
      v68 += 4;
      v73 += 32;
      v72 += 4;
    }
    while ( v68 < v69 - 3 );
  }
  if ( v68 < v69 )
  {
    v89 = &morphTriVerts[v68].xyz.z;
    v90 = v69 - v68;
    do
    {
      v91 = (float)(*(v89 - 2) - p_center->x);
      v92 = (float)(*(v89 - 1) - this->center.y);
      v93 = (float)((float)((float)v92 * (float)v92)
                  + (float)((float)((float)v91 * (float)v91)
                          + (float)((float)(*v89 - this->center.z) * (float)(*v89 - this->center.z))));
      if ( v93 > v70 )
      {
        v70 = (float)((float)((float)v92 * (float)v92)
                    + (float)((float)((float)v91 * (float)v91)
                            + (float)((float)(*v89 - this->center.z) * (float)(*v89 - this->center.z))));
        v66 = v68;
      }
      if ( v93 < v71 )
      {
        v71 = (float)((float)((float)v92 * (float)v92)
                    + (float)((float)((float)v91 * (float)v91)
                            + (float)((float)(*v89 - this->center.z) * (float)(*v89 - this->center.z))));
        v67 = v68;
      }
      ++v68;
      v89 += 8;
      --v90;
    }
    while ( v90 != 0 );
  }
  if ( v66 == -1 || v67 == -1 )
  {
    idLib::Warning(fmt: "Bad Clip ellipsoid for %s, couldn't determine min/max distances", decl->name.str);
    return 0;
  }
  else
  {
    v94 = &morphTriVerts[v66];
    v95 = &morphTriVerts[v67];
    v96 = (float)(v94->xyz.y - this->center.y);
    v97 = (float)(v94->xyz.z - this->center.z);
    this->zAxis.x = v94->xyz.x - p_center->x;
    this->zAxis.z = v97;
    this->zAxis.y = v96;
    p_yAxis = &this->yAxis;
    z = v95->xyz.z;
    v100 = this->center.z;
    v101 = (float)(v95->xyz.x - p_center->x);
    this->xAxis.y = v95->xyz.y - this->center.y;
    this->xAxis.x = v101;
    this->xAxis.z = (float)z - (float)v100;
    x = this->zAxis.x;
    v103 = this->zAxis.z;
    v104 = (float)((float)(this->zAxis.x * this->zAxis.x)
                 + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)));
    _FP3 = (float)((float)((float)(this->zAxis.x * this->zAxis.x)
                         + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v106 = (float)((float)((float)(this->zAxis.x * this->zAxis.x)
                         + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)))
                 * (float)0.5);
    __asm { fsel      f1, f3, f29, f13 }
    v108 = __frsqrte(_FP1);
    v109 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108
                                                                                         * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v108)
                                                                         - (float)1.5)
                                                         * (float)v108)
                                                 * (float)((float)((float)(this->zAxis.x * this->zAxis.x)
                                                                 + (float)((float)(this->zAxis.y * this->zAxis.y)
                                                                         + (float)(this->zAxis.z * this->zAxis.z)))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v108
                                                                                 * (float)((float)((float)(this->zAxis.x * this->zAxis.x)
                                                                                                 + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)))
                                                                                         * (float)0.5))
                                                                         * (float)v108)
                                                                 - (float)1.5)
                                                 * (float)v108))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v108
                                                         * (float)((float)((float)(this->zAxis.x * this->zAxis.x)
                                                                         + (float)((float)(this->zAxis.y * this->zAxis.y)
                                                                                 + (float)(this->zAxis.z * this->zAxis.z)))
                                                                 * (float)0.5))
                                                 * (float)v108)
                                         - (float)1.5)
                         * (float)v108));
    v110 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                                 * (float)v108)
                                                                                         * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z)))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                         * (float)v108))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v108
                                                                                                 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5))
                                                                                         * (float)v108)
                                                                                 - (float)1.5)
                                                                 * (float)v108))
                                                 * (float)v106)
                                         * (float)v109)
                                 - (float)1.5)
                 * (float)v109);
    this->zAxis.y = this->zAxis.y
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5)) * (float)v108) - (float)1.5) * (float)v108)
                                                                                                  * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5)) * (float)v108) - (float)1.5)
                                                                                                  * (float)v108))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v108 * (float)((float)((float)(this->zAxis.x * this->zAxis.x) + (float)((float)(this->zAxis.y * this->zAxis.y) + (float)(this->zAxis.z * this->zAxis.z))) * (float)0.5))
                                                                                                  * (float)v108)
                                                                                          - (float)1.5)
                                                                          * (float)v108))
                                                          * (float)v106)
                                                  * (float)v109)
                                          - (float)1.5)
                          * (float)v109);
    this->zAxis.x = (float)v110 * (float)x;
    this->zAxis.z = (float)v103 * (float)v110;
    v111 = this->xAxis.z;
    y = this->xAxis.y;
    v113 = (float)((float)(this->xAxis.z * this->xAxis.z)
                 + (float)((float)(this->xAxis.x * this->xAxis.x) + (float)(this->xAxis.y * this->xAxis.y)));
    _FP2 = (float)((float)((float)(this->xAxis.z * this->xAxis.z)
                         + (float)((float)(this->xAxis.x * this->xAxis.x) + (float)(this->xAxis.y * this->xAxis.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v115 = (float)((float)((float)(this->xAxis.z * this->xAxis.z)
                         + (float)((float)(this->xAxis.x * this->xAxis.x) + (float)(this->xAxis.y * this->xAxis.y)))
                 * (float)0.5);
    __asm { fsel      f13, f2, f27, f13 }
    v117 = __frsqrte(_FP13);
    v118 = (float)((float)-(float)((float)((float)((float)v117
                                                 * (float)((float)((float)(this->xAxis.z * this->xAxis.z)
                                                                 + (float)((float)(this->xAxis.x * this->xAxis.x)
                                                                         + (float)(this->xAxis.y * this->xAxis.y)))
                                                         * (float)0.5))
                                         * (float)v117)
                                 - (float)1.5)
                 * (float)v117);
    v119 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                 * (float)v118)
                                                                         - (float)1.5)
                                                         * (float)v118)
                                                 * (float)v115)
                                         * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                         * (float)v118)
                                                                 - (float)1.5)
                                                 * (float)v118))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118) - (float)1.5)
                         * (float)v118));
    RW = (int (*)(void))common->RW;
    v121 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                 * (float)v115)
                                                                                         * (float)v118)
                                                                                 - (float)1.5)
                                                                 * (float)v118)
                                                         * (float)v115)
                                                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                 * (float)v118)
                                                                         - (float)1.5)
                                                         * (float)v118))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118) - (float)1.5)
                                 * (float)v118))
                 * this->xAxis.x);
    this->xAxis.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                  * (float)v115)
                                                                                          * (float)v118)
                                                                                  - (float)1.5)
                                                                  * (float)v118)
                                                          * (float)v115)
                                                  * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                  * (float)v118)
                                                                          - (float)1.5)
                                                          * (float)v118))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118)
                                                  - (float)1.5)
                                  * (float)v118))
                  * this->xAxis.x;
    this->xAxis.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                  * (float)v115)
                                                                                          * (float)v118)
                                                                                  - (float)1.5)
                                                                  * (float)v118)
                                                          * (float)v115)
                                                  * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                  * (float)v118)
                                                                          - (float)1.5)
                                                          * (float)v118))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118)
                                                  - (float)1.5)
                                  * (float)v118))
                  * (float)y;
    v122 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                 * (float)v115)
                                                                                         * (float)v118)
                                                                                 - (float)1.5)
                                                                 * (float)v118)
                                                         * (float)v115)
                                                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                 * (float)v118)
                                                                         - (float)1.5)
                                                         * (float)v118))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118) - (float)1.5)
                                 * (float)v118))
                 * (float)v111);
    this->xAxis.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                  * (float)v115)
                                                                                          * (float)v118)
                                                                                  - (float)1.5)
                                                                  * (float)v118)
                                                          * (float)v115)
                                                  * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                  * (float)v118)
                                                                          - (float)1.5)
                                                          * (float)v118))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118)
                                                  - (float)1.5)
                                  * (float)v118))
                  * (float)v111;
    v123 = this->zAxis.x;
    v124 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118
                                                                                                 * (float)v115)
                                                                                         * (float)v118)
                                                                                 - (float)1.5)
                                                                 * (float)v118)
                                                         * (float)v115)
                                                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                 * (float)v118)
                                                                         - (float)1.5)
                                                         * (float)v118))
                                         - (float)1.5)
                         * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118) - (float)1.5)
                                 * (float)v118))
                 * (float)y);
    v125 = (float)(this->zAxis.x
                 * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                                 * (float)v118)
                                                                                         - (float)1.5)
                                                                         * (float)v118)
                                                                 * (float)v115)
                                                         * (float)((float)-(float)((float)((float)((float)v118
                                                                                                 * (float)v115)
                                                                                         * (float)v118)
                                                                                 - (float)1.5)
                                                                 * (float)v118))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118)
                                                         - (float)1.5)
                                         * (float)v118))
                         * (float)v111));
    v127 = (float)(this->zAxis.z
                 * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v118 * (float)v115)
                                                                                                 * (float)v118)
                                                                                         - (float)1.5)
                                                                         * (float)v118)
                                                                 * (float)v115)
                                                         * (float)((float)-(float)((float)((float)((float)v118
                                                                                                 * (float)v115)
                                                                                         * (float)v118)
                                                                                 - (float)1.5)
                                                                 * (float)v118))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)v118 * (float)v115) * (float)v118)
                                                         - (float)1.5)
                                         * (float)v118))
                         * (float)y));
    v126 = this->zAxis.y;
    v128 = (float)((float)v121 * this->zAxis.y);
    this->yAxis.y = (float)((float)v121 * this->zAxis.z) - (float)v125;
    this->yAxis.x = (float)((float)v126 * (float)v122) - (float)v127;
    this->yAxis.z = (float)((float)v123 * (float)v124) - (float)v128;
    v129 = RW();
    v158[2] = this->xAxis.z + this->center.z;
    v130 = p_center->x;
    v161[0] = 1.0;
    v161[1] = 0.0;
    v131 = (float)(this->xAxis.y + this->center.y);
    v158[0] = (float)v130 + this->xAxis.x;
    v161[2] = 0.0;
    v158[1] = v131;
    v161[3] = 1.0;
    (*(void (__fastcall **)(int, float *, idVec3 *, float *, int, _DWORD))(*(_DWORD *)v129 + 176))(
      a1: v129,
      a2: v161,
      a3: &this->center,
      a4: v158,
      a5: 60000,
      a6: 0);
    v132 = common->RW(this: common);
    v133 = (float)(p_center->x + this->yAxis.x);
    v134 = (float)(this->yAxis.y + this->center.y);
    v135 = (float)(this->yAxis.z + this->center.z);
    v162[0] = 0.0;
    v162[1] = 1.0;
    v159[0] = v133;
    v162[2] = 0.0;
    v159[1] = v134;
    v162[3] = 1.0;
    v159[2] = v135;
    v132->DebugLine(
      this: v132,
      a2: (const idVec4 *)v162,
      a3: &this->center,
      a4: (const idVec3 *)v159,
      a5: 60000,
      a6: false);
    v136 = common->RW(this: common);
    v137 = (float)(this->zAxis.y + this->center.y);
    v138 = (float)(this->zAxis.z + this->center.z);
    v163[0] = 0.0;
    v163[2] = 1.0;
    v160[1] = v137;
    v163[3] = 1.0;
    v160[2] = v138;
    v160[0] = this->zAxis.x + p_center->x;
    v163[1] = 0.0;
    v136->DebugLine(
      this: v136,
      a2: (const idVec4 *)v163,
      a3: &this->center,
      a4: (const idVec3 *)v160,
      a5: 60000,
      a6: false);
    v139 = this->zAxis.y;
    v140 = this->zAxis.z;
    v141 = 0;
    v142 = -1.0;
    this->zAxis.x = this->zAxis.x * (float)((float)1.0 / (float)((float)v110 * (float)v104));
    this->zAxis.y = (float)((float)1.0 / (float)((float)v110 * (float)v104)) * (float)v139;
    this->zAxis.z = (float)((float)1.0 / (float)((float)v110 * (float)v104)) * (float)v140;
    v143 = (float)((float)((float)1.0 / (float)((float)v119 * (float)v113)) * this->xAxis.y);
    this->xAxis.x = this->xAxis.x * (float)((float)1.0 / (float)((float)v119 * (float)v113));
    v144 = (float)((float)((float)1.0 / (float)((float)v119 * (float)v113)) * this->xAxis.z);
    this->xAxis.y = v143;
    this->xAxis.z = v144;
    v145 = morphTris->numVerts;
    if ( v145 >= 4 )
    {
      verts = morphTris->verts;
      v147 = 0;
      do
      {
        p_x = &verts[v147].xyz.x;
        if ( (float)((float)((float)(verts[v147].xyz.x - this->center.x) * this->yAxis.x)
                   + (float)((float)((float)(verts[v147].xyz.z - this->center.z) * this->yAxis.z)
                           + (float)((float)(verts[v147].xyz.y - this->center.y) * this->yAxis.y))) > v142 )
          v142 = (float)((float)((float)(verts[v147].xyz.x - p_center->x) * p_yAxis->x)
                       + (float)((float)((float)(verts[v147].xyz.z - this->center.z) * this->yAxis.z)
                               + (float)((float)(verts[v147].xyz.y - this->center.y) * this->yAxis.y)));
        if ( (float)((float)((float)(p_x[8] - this->center.x) * this->yAxis.x)
                   + (float)((float)((float)(p_x[10] - this->center.z) * this->yAxis.z)
                           + (float)((float)(p_x[9] - this->center.y) * this->yAxis.y))) > v142 )
          v142 = (float)((float)((float)(p_x[8] - p_center->x) * p_yAxis->x)
                       + (float)((float)((float)(p_x[10] - this->center.z) * this->yAxis.z)
                               + (float)((float)(p_x[9] - this->center.y) * this->yAxis.y)));
        v149 = v147 * 32 + 96;
        v150 = &verts[v147 + 3];
        if ( (float)((float)((float)(v150[-1].xyz.x - this->center.x) * this->yAxis.x)
                   + (float)((float)((float)(v150[-1].xyz.z - this->center.z) * this->yAxis.z)
                           + (float)((float)(v150[-1].xyz.y - this->center.y) * this->yAxis.y))) > v142 )
          v142 = (float)((float)((float)(v150[-1].xyz.x - p_center->x) * p_yAxis->x)
                       + (float)((float)((float)(v150[-1].xyz.z - this->center.z) * this->yAxis.z)
                               + (float)((float)(v150[-1].xyz.y - this->center.y) * this->yAxis.y)));
        if ( (float)((float)((float)(*(float *)((char *)&verts->xyz.x + v149) - this->center.x) * this->yAxis.x)
                   + (float)((float)((float)(*(float *)((char *)&verts->xyz.z + v149) - this->center.z) * this->yAxis.z)
                           + (float)((float)(*(float *)((char *)&verts->xyz.y + v149) - this->center.y) * this->yAxis.y))) > v142 )
          v142 = (float)((float)((float)(*(float *)((char *)&verts->xyz.x + v149) - p_center->x) * p_yAxis->x)
                       + (float)((float)((float)(*(float *)((char *)&verts->xyz.z + v149) - this->center.z)
                                       * this->yAxis.z)
                               + (float)((float)(*(float *)((char *)&verts->xyz.y + v149) - this->center.y)
                                       * this->yAxis.y)));
        v141 += 4;
        v147 += 4;
      }
      while ( v141 < v145 - 3 );
    }
    if ( v141 < v145 )
    {
      v151 = morphTris->verts;
      v153 = v145 - v141;
      v152 = v141;
      do
      {
        if ( (float)((float)((float)(v151[v152].xyz.x - this->center.x) * this->yAxis.x)
                   + (float)((float)((float)(v151[v152].xyz.z - this->center.z) * this->yAxis.z)
                           + (float)((float)(v151[v152].xyz.y - this->center.y) * this->yAxis.y))) > v142 )
          v142 = (float)((float)((float)(v151[v152].xyz.x - this->center.x) * this->yAxis.x)
                       + (float)((float)((float)(v151[v152].xyz.z - this->center.z) * this->yAxis.z)
                               + (float)((float)(v151[v152].xyz.y - this->center.y) * this->yAxis.y)));
        ++v152;
        --v153;
      }
      while ( v153 != 0 );
    }
    v154 = (float)((float)1.0 / (float)v142);
    v155 = this->yAxis.y;
    v157 = this->yAxis.z;
    p_yAxis->x = (float)v154 * p_yAxis->x;
    this->yAxis.y = (float)v155 * (float)v154;
    this->yAxis.z = (float)v157 * (float)v154;
    return 1;
  }
}


// ========================================================================
// ?MakeSkinMesh@morphShape_t@@AAA_NPAVidTriangles@@PBVidDrawVert@@PBVidDecl@@@Z
// EA  : 0x827DB970
// RVA : 0x007DB970
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall morphShape_t::MakeSkinMesh(
        morphShape_t *this,
        idTriangles *morphTris,
        const idDrawVert *morphTriVerts,
        const idDecl *decl)
{
  int v5; // r29
  idList<idVec3,5> *p_points; // r31
  float *p_z; // r30
  int granularity; // r4
  int size; // r11
  bool v10; // cr58
  signed int v11; // r10
  int v12; // r4
  int v13; // r11
  int num; // r11
  float *p_x; // r11

  v5 = 0;
  if ( morphTris->numVerts > 0 )
  {
    p_points = &this->points;
    p_z = &morphTriVerts->xyz.z;
    do
    {
      if ( p_points->list != nullptr )
        goto LABEL_7;
      granularity = p_points->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( idList<idVec3,59>::Resize(this: p_points, newsize: granularity) )
      {
LABEL_7:
        size = p_points->size;
        if ( p_points->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v10 = !idList<idVec3,59>::Resize(this: p_points, newsize: size + 1);
        }
        else
        {
          v11 = p_points->granularity;
          if ( p_points->granularity != 0 )
          {
            v13 = size + v11;
            __twllei(v11, 0);
            __twlgei(v11 & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
            v10 = !idList<idVec3,59>::Resize(this: p_points, newsize: v13 - v13 % v11);
          }
          else
          {
            v12 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v12 == 0 )
                v12 = 1;
              v10 = !idList<idVec3,59>::Resize(this: p_points, newsize: v12);
            }
            else
            {
              v10 = !idList<idVec3,59>::Resize(this: p_points, newsize: 0x7FFFFFFF);
            }
          }
        }
        if ( !v10 )
        {
LABEL_18:
          num = p_points->num;
          if ( num < p_points->size )
          {
            p_x = &p_points->list[num].x;
            *p_x = *(p_z - 2);
            p_x[1] = *(p_z - 1);
            p_x[2] = *p_z;
            ++p_points->num;
          }
        }
      }
      ++v5;
      p_z += 8;
    }
    while ( v5 < morphTris->numVerts );
  }
  return 1;
}


// ========================================================================
// ??0morphShape_t@@QAA@PAVidTriangles@@PBVidDrawVert@@PBDPBVidDecl@@@Z
// EA  : 0x827DBB08
// RVA : 0x007DBB08
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

morphShape_t *__fastcall morphShape_t::morphShape_t(
        morphShape_t *this,
        idTriangles *morphTris,
        const idDrawVert *morphTriVerts,
        const char *matName,
        const idDecl *decl)
{
  float z; // r6
  morphShape_t::shapeType_t v11; // r11

  this->type = 0;
  this->center = vec3_origin;
  this->xAxis = vec3_origin;
  this->yAxis = vec3_origin;
  this->zAxis.x = vec3_origin.x;
  this->zAxis.y = vec3_origin.y;
  z = vec3_origin.z;
  this->length = 0.0;
  this->radius = 0.0;
  this->zAxis.z = z;
  this->radiusSqr = 0.0;
  this->points.list = nullptr;
  this->points.granularity = 0;
  this->points.memTag = 5;
  this->points.listStatic = 0;
  this->points.size = 0;
  this->points.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->points);
  if ( strstr(str1: matName, str2: "skinmesh") != nullptr )
  {
    if ( (unsigned __int8)morphShape_t::MakeSkinMesh(this, morphTris, morphTriVerts, decl) != 0 )
    {
      v11 = SKIN_MESH;
LABEL_13:
      this->type = v11;
    }
  }
  else if ( strstr(str1: matName, str2: "clipsphere") != nullptr )
  {
    if ( (unsigned __int8)morphShape_t::MakeSphere(this, morphTris, morphTriVerts, decl) != 0 )
    {
      v11 = CLIP_SPHERE;
      goto LABEL_13;
    }
  }
  else if ( strstr(str1: matName, str2: "skinsphere") != nullptr )
  {
    if ( (unsigned __int8)morphShape_t::MakeSphere(this, morphTris, morphTriVerts, decl) != 0 )
    {
      v11 = SKIN_SPHERE;
      goto LABEL_13;
    }
  }
  else if ( strstr(str1: matName, str2: "clipellipsoid") != nullptr
         && (unsigned __int8)morphShape_t::MakeEllipsoid(this, morphTris, morphTriVerts, decl) != 0 )
  {
    v11 = CLIP_ELLIPSOID;
    goto LABEL_13;
  }
  return this;
}


// ========================================================================
// __unwind$233679
// EA  : 0x827DBCF0
// RVA : 0x007DBCF0
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_233679()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 64));
}


// ========================================================================
// ?ReloadIfStale@idMorphVertices@@UAA_NXZ
// EA  : 0x827DBD90
// RVA : 0x007DBD90
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall idMorphVertices::ReloadIfStale(idMorphVertices *this)
{
  const char *str; // r4
  const idDecl *v3; // r3
  const idDecl *v4; // r29
  int v5; // r3
  char v6; // r11
  unsigned int timestampModel; // r11
  bool v8; // zf
  idStr v10[2]; // [sp+50h] [-40h] BYREF

  str = this->name.str;
  if ( str != nullptr )
  {
    v3 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: str, makeDefault: false);
    v4 = v3;
    if ( v3 != nullptr && v3[1].trackedMemory != 0 )
    {
      if ( this->timestampDecl == -1
        || (v5 = v3->GetDeclTimestamp(this: (idDecl *)v3), v6 = 0, this->timestampDecl != v5) )
      {
        v6 = 1;
      }
      if ( v6 == 0 )
      {
        timestampModel = this->timestampModel;
        if ( timestampModel == -1 || (v8 = timestampModel == *(_DWORD *)(v4[1].trackedMemory + 68), v6 = 0, !v8) )
          v6 = 1;
      }
      if ( v6 == 0 )
        return 0;
      idStr::idStr(this: v10, text: "generated/skins/morphVertices/");
      idStr::Append(this: v10, text: *(char **)(v4[1].trackedMemory + 8));
      idStr::SetFileExtension(this: v10, extension: ".morph");
      fileSystem->RemoveFile(this: fileSystem, a2: v10[0].data, a3: FSPATH_BASE);
      idList<idMorphVertices::vertSet,5>::Clear(this: (idList<idMorphVertices::vertSet,115> *)&this->morphVertSet);
      this->LoadResource(this);
      idStr::FreeData(this: v10);
    }
  }
  return 1;
}


// ========================================================================
// __unwind$234248
// EA  : 0x827DBED0
// RVA : 0x007DBED0
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_234248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idMorphVertices@@QAA@XZ
// EA  : 0x827DC050
// RVA : 0x007DC050
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

idMorphVertices *__fastcall idMorphVertices::idMorphVertices(idMorphVertices *this)
{
  idResource::idResource(this);
  this->__vftable = (idMorphVertices_vtbl *)&idMorphVertices::`vftable';
  this->morphVertSet.granularity = 0;
  this->morphVertSet.memTag = 5;
  this->morphVertSet.listStatic = 0;
  this->morphVertSet.list = nullptr;
  this->morphVertSet.size = 0;
  this->morphVertSet.num = 0;
  return this;
}


// ========================================================================
// __unwind$234443
// EA  : 0x827DC0C0
// RVA : 0x007DC0C0
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_234443()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?ProcessModel@idMorphVertGen@@CAXABVidMD6Model@@PBVidDeclMD6@@ABVidMorphDef@@AAVidMorphVertices@@@Z
// EA  : 0x827DC4C0
// RVA : 0x007DC4C0
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __fastcall idMorphVertGen::ProcessModel(
        const idMD6Model *model,
        const idDeclMD6 *decl,
        const idMorphDef *morphDef,
        idMorphVertices *vertices)
{
  int v8; // r19
  double x; // fp23
  double y; // fp24
  double z; // fp25
  int JointGroupIndex; // r3
  const idJointGroup *JointGroupForIndex; // r3
  __int16 value; // r10
  const idMD6Skel *skeleton; // r11
  int v16; // r11
  int v17; // r21
  idVec3 *p_size; // r27
  idVec3 *p_pos; // r26
  int v20; // r23
  unsigned int flags; // r11
  idMD6Mesh **list; // r10
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  double v26; // fp11
  char v27; // r25
  double v28; // fp10
  double v29; // fp9
  idTriangles *tris; // r28
  idDrawVert *verts; // r3
  int v32; // r30
  double v33; // fp31
  float *p_y; // r29
  double v35; // fp11
  double v36; // fp9
  int v37; // r29
  double v38; // fp31
  double v39; // fp30
  double v40; // fp29
  double v41; // fp27
  double v42; // fp28
  double v43; // fp26
  float *p_z; // r30
  double v45; // fp12
  double v46; // fp13
  double v47; // fp0
  char v48; // r11
  float v49[4]; // [sp+50h] [-180h] BYREF
  idMat3x4 v50; // [sp+60h] [-170h] BYREF
  idMorphVertices::vertSet v51; // [sp+90h] [-140h] BYREF

  if ( idStr::Cmp(s1: morphDef->jointName.data, s2: "none") != 0 )
  {
    JointGroupIndex = idJointGroupCollection::GetJointGroupIndex(
                        this: &decl->jointGroupCollection,
                        type: JOINTGROUP_HITTEST,
                        name: morphDef->jointName.data);
    v8 = JointGroupIndex;
    if ( JointGroupIndex < 0 )
    {
      idLib::Warning(fmt: "Joint '%s' not found for model def '%s'", morphDef->jointName.data, decl->name.str);
      return;
    }
    JointGroupForIndex = idJointGroupCollection::GetJointGroupForIndex(
                           this: &decl->jointGroupCollection,
                           type: JOINTGROUP_HITTEST,
                           index: JointGroupIndex);
    if ( JointGroupForIndex == nullptr || JointGroupForIndex->joints.num == 0 )
    {
      idLib::Warning(
        fmt: "Error parsing damage decls for '%s'.  No joint group found or jointList is NULL",
        decl->name.str);
      return;
    }
    value = JointGroupForIndex->joints.list->value;
    if ( value < 0 )
    {
      idLib::Warning(fmt: "Invalid joint when parsing damage decls for '%s'", decl->name.str);
      return;
    }
    skeleton = decl->model->skeleton;
    if ( skeleton != nullptr )
      v16 = (int)skeleton->data + skeleton->data->inverseBasePoseOffset;
    else
      v16 = 0;
    v50 = *(idMat3x4 *)(48 * value + v16);
    idMat3x4::Invert(this: &v50);
    z = (float)(v50.mat[11]
              + (float)((float)(v50.mat[10] * morphDef->pos.z)
                      + (float)((float)(v50.mat[8] * morphDef->pos.x) + (float)(v50.mat[9] * morphDef->pos.y))));
    y = (float)(v50.mat[7]
              + (float)((float)(v50.mat[6] * morphDef->pos.z)
                      + (float)((float)(v50.mat[4] * morphDef->pos.x) + (float)(v50.mat[5] * morphDef->pos.y))));
    x = (float)(v50.mat[3]
              + (float)((float)(morphDef->pos.x * v50.mat[0])
                      + (float)((float)(v50.mat[1] * morphDef->pos.y) + (float)(v50.mat[2] * morphDef->pos.z))));
  }
  else
  {
    v8 = 0;
    x = vec3_origin.x;
    y = vec3_origin.y;
    z = vec3_origin.z;
  }
  v17 = 0;
  if ( model->meshes.num > 0 )
  {
    p_size = &morphDef->size;
    p_pos = &morphDef->pos;
    v20 = 0;
    do
    {
      idMorphVertices::vertSet::vertSet(this: &v51);
      flags = morphDef->flags;
      list = model->meshes.list;
      v23 = p_pos->x;
      v24 = morphDef->pos.y;
      v51.meshNum = v17;
      v25 = morphDef->pos.z;
      v51.jointGroupIndex = v8;
      v26 = p_size->x;
      v27 = 0;
      v28 = morphDef->size.y;
      v51.flags = flags;
      v29 = morphDef->size.z;
      v51.pos.x = v23;
      v51.pos.y = v24;
      v51.pos.z = v25;
      v51.size.x = v26;
      v51.size.y = v28;
      v51.size.z = v29;
      tris = list[v20]->tris;
      verts = tris->verts;
      if ( verts != nullptr
        || (tris->vertexBuffer.size & 0x7FFFFFFF) != 0
        && (verts = (idDrawVert *)idVertexBuffer::MapBuffer(this: &tris->vertexBuffer, mapType: BM_READ),
            v27 = 1,
            verts != nullptr) )
      {
        if ( (morphDef->flags & 1) != 0 )
        {
          v32 = 0;
          if ( tris->numVerts > 0 )
          {
            v33 = (float)(p_size->x * p_size->x);
            p_y = &verts->xyz.y;
            do
            {
              v35 = (float)(*(p_y - 1) - (float)x);
              v36 = (float)(p_y[1] - (float)z);
              if ( (float)((float)((float)v36 * (float)v36)
                         + (float)((float)((float)v35 * (float)v35)
                                 + (float)((float)(*p_y - (float)y) * (float)(*p_y - (float)y)))) <= v33 )
              {
                HIWORD(v49[0]) = v32;
                idList<unsigned short,72>::Append(
                  this: (idList<unsigned short,5> *)&v51.vertices,
                  obj: (unsigned __int16 *)v49);
              }
              ++v32;
              p_y += 8;
            }
            while ( v32 < tris->numVerts );
          }
        }
        else
        {
          v37 = 0;
          v38 = (float)(morphDef->size.z + morphDef->pos.z);
          v39 = (float)(morphDef->pos.z - morphDef->size.z);
          v40 = (float)(morphDef->size.y + morphDef->pos.y);
          v41 = (float)(morphDef->pos.y - morphDef->size.y);
          v42 = (float)(p_size->x + p_pos->x);
          v43 = (float)(p_pos->x - p_size->x);
          if ( tris->numVerts > 0 )
          {
            p_z = &verts->xyz.z;
            do
            {
              v45 = *(p_z - 2);
              v49[0] = *(p_z - 2);
              if ( v45 < v43 )
                goto LABEL_34;
              v46 = *(p_z - 1);
              v49[0] = *(p_z - 1);
              if ( v46 < v41
                || (v47 = *p_z, v49[0] = *p_z, v47 < v39)
                || (v49[0] = v45, v45 > v42)
                || (v49[0] = v46, v46 > v40)
                || (v49[0] = v47, v48 = 1, v47 > v38) )
              {
LABEL_34:
                v48 = 0;
              }
              if ( v48 != 0 )
              {
                HIWORD(v49[0]) = v37;
                idList<unsigned short,72>::Append(
                  this: (idList<unsigned short,5> *)&v51.vertices,
                  obj: (unsigned __int16 *)v49);
              }
              ++v37;
              p_z += 8;
            }
            while ( v37 < tris->numVerts );
          }
        }
        if ( v27 != 0 )
          idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)&tris->vertexBuffer);
        if ( v51.vertices.num != 0 )
          idList<idMorphVertices::vertSet,5>::Append(this: &vertices->morphVertSet, obj: &v51);
        if ( v51.morphDirection.listStatic == 0 || v51.morphDirection.listStatic == 2 )
        {
          if ( v51.morphDirection.list != nullptr )
            idMem::Free(this: &mem, ptr: v51.morphDirection.list, align: ALIGN_16);
          v51.morphDirection.list = nullptr;
          v51.morphDirection.size = 0;
        }
        v51.morphDirection.num = 0;
        if ( v51.vertices.listStatic == 0 || v51.vertices.listStatic == 2 )
        {
          if ( v51.vertices.list != nullptr )
            idMem::Free(this: &mem, ptr: v51.vertices.list, align: ALIGN_16);
          v51.vertices.list = nullptr;
          v51.vertices.size = 0;
        }
        v51.vertices.num = 0;
      }
      else
      {
        idLib::Warning(fmt: "idMorphVertGen::ProcessModel(). Unable to Map vertex buffer for '%s", model->name.str);
        idMorphVertices::vertSet::~vertSet(this: &v51);
      }
      ++v17;
      ++v20;
    }
    while ( v17 < model->meshes.num );
  }
}


// ========================================================================
// __unwind$235358_0
// EA  : 0x827DC95C
// RVA : 0x007DC95C
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_235358_0()
{
  int v0; // r12

  idMorphVertices::vertSet::~vertSet(this: (idMorphVertices::vertSet *)(v0 - 464 + 144));
}


// ========================================================================
// __unwind$235888
// EA  : 0x827DC984
// RVA : 0x007DC984
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_235888()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 464 + 216));
}


// ========================================================================
// ?Load_Binary@idMorphVertices@@QAA_NXZ
// EA  : 0x827DC9B8
// RVA : 0x007DC9B8
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall idMorphVertices::Load_Binary(idMorphVertices *this)
{
  const char *str; // r4
  const idDecl *v3; // r3
  const idDecl *v4; // r29
  idFile *v5; // r3
  int v6; // r28
  idList<idMorphVertices::vertSet,115> *p_morphVertSet; // r29
  int v8; // r30
  idFileLocal v10; // [sp+50h] [-70h] BYREF
  int v11; // [sp+54h] [-6Ch] BYREF
  int v12; // [sp+58h] [-68h] BYREF
  int v13; // [sp+5Ch] [-64h] BYREF
  unsigned int v14; // [sp+60h] [-60h] BYREF
  idStr v15[2]; // [sp+70h] [-50h] BYREF

  str = this->name.str;
  if ( str != nullptr
    && (v3 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: str, makeDefault: false),
        v4 = v3,
        v3 != nullptr) )
  {
    if ( v3[1].trackedMemory != 0 )
    {
      idStr::idStr(this: v15, text: "generated/skins/morphVertices/");
      idStr::Append(this: v15, text: *(char **)(v4[1].trackedMemory + 8));
      idStr::SetFileExtension(this: v15, extension: ".morph");
      v5 = fileSystem->OpenFileRead(this: fileSystem, a2: v15[0].data, a3: 1, a4: 0);
      v10.file = v5;
      if ( v5 != nullptr && (int)v5->Length(this: v5) > 0 )
      {
        v10.file->Read(this: v10.file, a2: &v11, a3: 4u);
        if ( v11 == 88625229 )
        {
          v10.file->Read(this: v10.file, a2: &this->timestampDecl, a3: 4u);
          v10.file->Read(this: v10.file, a2: &this->timestampModel, a3: 4u);
          v6 = 0;
          v12 = 0;
          v10.file->Read(this: v10.file, a2: &v12, a3: 4u);
          p_morphVertSet = (idList<idMorphVertices::vertSet,115> *)&this->morphVertSet;
          idList<idMorphVertices::vertSet,115>::SetNum(
            this: (idList<idMorphVertices::vertSet,115> *)&this->morphVertSet,
            newNum: v12);
          if ( this->morphVertSet.num > 0 )
          {
            v8 = 0;
            do
            {
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8], a3: 4u);
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8].jointGroupIndex, a3: 4u);
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8].flags, a3: 4u);
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8].pos, a3: 12u);
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8].size, a3: 12u);
              v10.file->Read(this: v10.file, a2: &p_morphVertSet->list[v8].axis, a3: 36u);
              v10.file->Read(this: v10.file, a2: &v13, a3: 4u);
              idList<unsigned short,115>::SetNum(
                this: (idList<unsigned short,72> *)&p_morphVertSet->list[v8].vertices,
                newNum: v13);
              v10.file->Read(this: v10.file, a2: p_morphVertSet->list[v8].vertices.list, a3: 2 * v13);
              v10.file->Read(this: v10.file, a2: &v14, a3: 4u);
              idList<unsigned char,19>::SetNum(
                this: (idList<unsigned char,37> *)&p_morphVertSet->list[v8].morphDirection,
                newNum: v14);
              v10.file->Read(this: v10.file, a2: p_morphVertSet->list[v8].morphDirection.list, a3: v14);
              ++v6;
              ++v8;
            }
            while ( v6 < p_morphVertSet->num );
          }
          v10.file->Read(this: v10.file, a2: &v11, a3: 4u);
          if ( v11 == 88625229 )
          {
            idFileLocal::~idFileLocal(this: &v10);
            idStr::FreeData(this: v15);
            return 1;
          }
          idList<idMorphVertices::vertSet,5>::Clear(this: p_morphVertSet);
          idFileLocal::~idFileLocal(this: &v10);
        }
        else
        {
          idLib::Printf(fmt: "Magic Fail -- %d vs %d\n", v11, 88625229);
          idFileLocal::~idFileLocal(this: &v10);
        }
      }
      else
      {
        idFileLocal::~idFileLocal(this: &v10);
      }
      idStr::FreeData(this: v15);
    }
    else if ( idLib::production == PROD_DEVELOPMENT || (*((_BYTE *)&v3->idResource + 32) & 0x80) != 0 )
    {
      idLib::Warning(fmt: "idMorphVertices failed to find model '%s'", this->name.str);
    }
  }
  else
  {
    idLib::Warning(fmt: "idMorphVertices failed to find md6Def '%s'", this->name.str);
  }
  return 0;
}


// ========================================================================
// __unwind$236038
// EA  : 0x827DCD8C
// RVA : 0x007DCD8C
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$236039
// EA  : 0x827DCDB4
// RVA : 0x007DCDB4
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236039()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 192 + 80));
}


// ========================================================================
// ?OptimizeVertices@idMorphVertGen@@CAXAAVidMorphVertices@@0@Z
// EA  : 0x827DCE60
// RVA : 0x007DCE60
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __fastcall idMorphVertGen::OptimizeVertices(idMorphVertices *outputVerts, idMorphVertices *inputVerts)
{
  int size; // r11
  idVehicleState **list; // r25
  int v6; // r22
  bool *v7; // r23
  int v8; // r27
  char *v9; // r10
  int i; // ctr
  int v11; // r7
  int v12; // r8
  idMorphVertices::vertSet *v13; // r11
  int v14; // r10
  char *v15; // r11
  int v16; // r9
  int v17; // r6
  idList<idMorphVertices::vertSet,5> *p_morphVertSet; // r28
  int num; // r11
  int v20; // r10
  int v21; // r30
  idMorphVertices::vertSet *v22; // r8
  int v23; // r28
  idMorphVertices::vertSet *v24; // r11
  idMorphVertices::vertSet *v25; // r11
  _DWORD v26[4]; // [sp+50h] [-A0h] BYREF
  idList<idVehicleState *,5> v27; // [sp+60h] [-90h] BYREF
  idList<bool,5> v28[8]; // [sp+70h] [-80h] BYREF

  memset(&v27, 0, 14);
  *(_WORD *)&v27.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v27);
  size = v27.size;
  if ( v27.size < 0x10000 )
  {
    if ( !idList<unsigned char,25>::Resize(this: (idList<unsigned char,37> *)&v27, newsize: 0x10000) )
      goto LABEL_6;
    size = v27.size;
  }
  v27.num = 0x10000;
  if ( size <= 0x10000 )
    v27.num = size;
LABEL_6:
  memset(v28, 0, 14);
  v28[0].memTag = 5;
  v28[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v28);
  HIBYTE(v26[0]) = 0;
  idList<bool,5>::SetNum(this: v28, newNum: inputVerts->morphVertSet.num, initValue: (const bool *)v26);
  list = v27.list;
  v6 = 0;
  v7 = v28[0].list;
  if ( inputVerts->morphVertSet.num > 0 )
  {
    v8 = 0;
    do
    {
      if ( !v7[v6] )
      {
        v7[v6] = true;
        v9 = (char *)list - 1;
        for ( i = 0x10000; i != 0; --i )
          *++v9 = 0;
        v11 = v6;
        if ( v6 < inputVerts->morphVertSet.num )
        {
          v12 = v8 * 104;
          do
          {
            v13 = inputVerts->morphVertSet.list;
            if ( v13[v8].jointGroupIndex == *(int *)((char *)&v13->jointGroupIndex + v12)
              && v13[v8].meshNum == *(int *)((char *)&v13->meshNum + v12) )
            {
              v7[v11] = true;
              v14 = 0;
              v15 = (char *)inputVerts->morphVertSet.list + v12;
              if ( *((int *)v15 + 19) > 0 )
              {
                v16 = 0;
                do
                {
                  ++v14;
                  v17 = *(unsigned __int16 *)(*((_DWORD *)v15 + 18) + v16);
                  v16 += 2;
                  *((_BYTE *)list + v17) = 1;
                  v15 = (char *)inputVerts->morphVertSet.list + v12;
                }
                while ( v14 < *((_DWORD *)v15 + 19) );
              }
            }
            ++v11;
            v12 += 104;
          }
          while ( v11 < inputVerts->morphVertSet.num );
        }
        p_morphVertSet = &outputVerts->morphVertSet;
        idList<idMorphVertices::vertSet,5>::PreAllocateWithGranularity(
          this: &outputVerts->morphVertSet,
          newSize: outputVerts->morphVertSet.num + 1);
        num = outputVerts->morphVertSet.num;
        v20 = outputVerts->morphVertSet.size;
        if ( num >= v20 )
        {
          v21 = (int)&p_morphVertSet->list[v20 - 1];
        }
        else
        {
          v21 = (int)&p_morphVertSet->list[num];
          outputVerts->morphVertSet.num = num + 1;
        }
        v22 = &inputVerts->morphVertSet.list[v8];
        v23 = 0;
        v26[0] = v21 + 24;
        *(_DWORD *)(v21 + 8) = v22->flags;
        *(_DWORD *)(v21 + 4) = inputVerts->morphVertSet.list[v8].jointGroupIndex;
        *(_DWORD *)v21 = inputVerts->morphVertSet.list[v8].meshNum;
        v24 = &inputVerts->morphVertSet.list[v8];
        *(float *)(v21 + 12) = v24->pos.x;
        *(float *)(v21 + 16) = v24->pos.y;
        *(float *)(v21 + 20) = v24->pos.z;
        v25 = &inputVerts->morphVertSet.list[v8];
        *(float *)(v21 + 24) = v25->size.x;
        *(float *)(v21 + 28) = v25->size.y;
        *(float *)(v21 + 32) = v25->size.z;
        do
        {
          if ( *((_BYTE *)list + v23) != 0 )
          {
            HIWORD(v26[0]) = v23;
            idList<unsigned short,72>::Append(
              this: (idList<unsigned short,5> *)(v21 + 72),
              obj: (unsigned __int16 *)v26);
          }
          ++v23;
        }
        while ( v23 < 0x10000 );
      }
      ++v6;
      ++v8;
    }
    while ( v6 < inputVerts->morphVertSet.num );
  }
  if ( (v28[0].listStatic == 0 || v28[0].listStatic == 2) && v7 != nullptr )
    idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
  if ( (v27.listStatic == 0 || v27.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$236416
// EA  : 0x827DD170
// RVA : 0x007DD170
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236416()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$236417
// EA  : 0x827DD198
// RVA : 0x007DD198
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236417()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// ?GenerateMorphVertsFromFile@idMorphVertGen@@SAXPBVidDeclMD6@@PBDAAVidMorphVertices@@@Z
// EA  : 0x827DD1C8
// RVA : 0x007DD1C8
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __fastcall idMorphVertGen::GenerateMorphVertsFromFile(
        const idDeclMD6 *decl,
        const char *genFile,
        idMorphVertices *vertices)
{
  const idDeclMD6 *v3; // r27
  idMorphVertices *v5; // r23
  const char *v6; // r19
  idStaticModelSurface *v7; // r25
  idTriangles *geometry; // r30
  const idDrawVert *verts; // r29
  unsigned __int16 *indexes; // r28
  idMorphVertices::vertSet *v11; // r3
  double v12; // fp13
  float x; // r5
  double v14; // fp12
  idMorphVertices::vertSet *v15; // r3
  double v16; // fp13
  float v17; // r11
  double v18; // fp10
  double v19; // fp9
  double v20; // fp8
  double v21; // fp7
  double v22; // fp6
  double v23; // fp5
  double v24; // fp3
  double v25; // fp11
  int v26; // r26
  int v27; // r23
  int v28; // r30
  int materialNum; // r11
  char v30; // r27
  int v31; // r28
  const idVec3 *v32; // r3
  int v33; // r29
  const idVec3 *v34; // r30
  bool v35; // r3
  double v36; // fp0
  double v37; // fp30
  double v38; // fp27
  _DWORD v39[2]; // [sp+50h] [-370h] BYREF
  unsigned int v40; // [sp+58h] [-368h]
  idVec3 v41; // [sp+60h] [-360h] BYREF
  const char *model; // [sp+6Ch] [-354h]
  int v43; // [sp+70h] [-350h]
  const char *v44; // [sp+74h] [-34Ch]
  float v45; // [sp+78h] [-348h]
  float y; // [sp+7Ch] [-344h]
  float z; // [sp+80h] [-340h]
  float v48; // [sp+88h] [-338h]
  float v49; // [sp+8Ch] [-334h]
  float v50; // [sp+90h] [-330h]
  morphShape_t v51; // [sp+A0h] [-320h] BYREF
  idMorphVertices::vertSet v52; // [sp+F0h] [-2D0h] BYREF
  idStaticModel v53; // [sp+160h] [-260h] BYREF

  v3 = decl;
  v5 = vertices;
  if ( decl != nullptr )
  {
    if ( genFile != nullptr )
    {
      model = (const char *)decl->model;
      v6 = model;
      if ( model != nullptr )
      {
        idStaticModel::idStaticModel(this: &v53);
        idResource::SetName(this: &v53, _name: genFile);
        idStaticModel::PristineLoadResource(this: &v53);
        if ( v53.surfaces.num != 0 )
        {
          v43 = 0;
          if ( v53.surfaces.num > 0 )
          {
            v40 = 0;
            model = "%s - Could not find vertices for %s";
            v44 = "%s - Could not find material for %s";
            do
            {
              v7 = &v53.surfaces.list[v40 / 0x48];
              geometry = v53.surfaces.list[v40 / 0x48].geometry;
              verts = geometry->verts;
              indexes = geometry->indexes;
              if ( v53.surfaces.list[v40 / 0x48].material != nullptr )
              {
                if ( verts != nullptr
                  || (verts = (const idDrawVert *)idVertexBuffer::MapBuffer(
                                                    this: &geometry->vertexBuffer,
                                                    mapType: BM_READ)) != nullptr )
                {
                  if ( indexes != nullptr
                    || idIndexBuffer::MapBuffer(this: &geometry->indexBuffer, mapType: BM_READ) != nullptr )
                  {
                    morphShape_t::morphShape_t(
                      this: &v51,
                      morphTris: geometry,
                      morphTriVerts: verts,
                      matName: v7->material->name.str,
                      decl: v3);
                    if ( v51.type != 0 )
                    {
                      if ( v51.type == CLIP_SPHERE )
                      {
                        v11 = idList<idMorphVertices::vertSet,5>::Alloc(this: &v5->morphVertSet);
                        v11->flags = 8;
                        v11->jointGroupIndex = v7->materialNum;
                        v11->meshNum = -1;
                        y = v51.center.y;
                        z = v51.center.z;
                        v12 = v51.center.y;
                        x = v51.center.x;
                        v11->pos.x = v51.center.x;
                        v14 = z;
                        v11->pos.y = v12;
                        v39[0] = &v11->size;
                        v11->pos.z = v14;
                        v45 = x;
                        v11->size.x = v51.radius;
                        v11->size.y = 0.0;
                        v11->size.z = 0.0;
                      }
                      else if ( v51.type == CLIP_ELLIPSOID )
                      {
                        v15 = idList<idMorphVertices::vertSet,5>::Alloc(this: &v5->morphVertSet);
                        v15->flags = 16;
                        v15->jointGroupIndex = v7->materialNum;
                        v15->meshNum = -1;
                        v49 = v51.center.y;
                        v16 = v51.center.y;
                        v50 = v51.center.z;
                        v17 = v51.center.x;
                        v15->pos.x = v51.center.x;
                        v15->pos.y = v16;
                        v15->pos.z = v50;
                        v39[0] = &v15->axis.mat[2];
                        v18 = v51.yAxis.x;
                        v48 = v17;
                        v19 = v51.yAxis.y;
                        v20 = v51.yAxis.z;
                        v21 = v51.zAxis.x;
                        v22 = v51.zAxis.y;
                        v23 = v51.zAxis.z;
                        v24 = v51.xAxis.y;
                        v25 = v51.xAxis.z;
                        v15->axis.mat[0].x = v51.xAxis.x;
                        v15->axis.mat[1].x = v18;
                        v15->axis.mat[0].y = v24;
                        v15->axis.mat[0].z = v25;
                        v15->axis.mat[1].y = v19;
                        v15->axis.mat[1].z = v20;
                        v15->axis.mat[2].x = v21;
                        v15->axis.mat[2].y = v22;
                        v15->axis.mat[2].z = v23;
                      }
                      else
                      {
                        v26 = 0;
                        if ( *((int *)v6 + 38) > 0 )
                        {
                          v27 = 0;
                          do
                          {
                            v28 = *(_DWORD *)(v27 + *((_DWORD *)v6 + 37));
                            if ( strstr(str1: *(const char **)(*(_DWORD *)(v28 + 32) + 8), str2: "gore") == nullptr )
                            {
                              idMorphVertices::vertSet::vertSet(this: &v52);
                              materialNum = v7->materialNum;
                              v52.meshNum = v26;
                              v52.flags = 4;
                              v30 = 0;
                              v52.pos.x = vec3_origin.x;
                              v52.pos.z = vec3_origin.z;
                              v52.jointGroupIndex = materialNum;
                              v52.size.y = vec3_origin.y;
                              v52.size.z = vec3_origin.z;
                              v52.pos.y = vec3_origin.y;
                              v52.size.x = vec3_origin.x;
                              v31 = *(_DWORD *)(v28 + 104);
                              v32 = *(const idVec3 **)(v31 + 88);
                              if ( v32 != nullptr
                                || (*(_DWORD *)(v31 + 100) & 0x7FFFFFFF) != 0
                                && (v32 = (const idVec3 *)idVertexBuffer::MapBuffer(
                                                            this: (idVertexBuffer *)(v31 + 100),
                                                            mapType: BM_READ),
                                    v30 = 1,
                                    v32 != nullptr) )
                              {
                                v33 = 0;
                                if ( *(int *)(v31 + 32) > 0 )
                                {
                                  v34 = v32;
                                  do
                                  {
                                    if ( v51.type == SKIN_MESH )
                                      v35 = morphShape_t::SkinMeshMorphPoint(this: &v51, inPoint: v34, outPoint: &v41);
                                    else
                                      v35 = v51.type == SKIN_SPHERE
                                         && morphShape_t::SphereContainsPoint(this: &v51, inPoint: v34, outPoint: &v41);
                                    if ( v35 )
                                    {
                                      if ( ((LODWORD(v41.y) | LODWORD(v41.z) | LODWORD(v41.x)) & 0x7FFFFFFF) != 0 )
                                      {
                                        v36 = (float)((float)((float)((float)(v41.x * (float)0.03125) * (float)0.5)
                                                            + (float)0.5)
                                                    * (float)255.0);
                                        v41.x = (float)((float)((float)(v41.x * (float)0.03125) * (float)0.5)
                                                      + (float)0.5)
                                              * (float)255.0;
                                        v37 = (float)((float)((float)((float)(v41.y * (float)0.03125) * (float)0.5)
                                                            + (float)0.5)
                                                    * (float)255.0);
                                        v41.y = (float)((float)((float)(v41.y * (float)0.03125) * (float)0.5)
                                                      + (float)0.5)
                                              * (float)255.0;
                                        v38 = (float)((float)((float)((float)(v41.z * (float)0.03125) * (float)0.5)
                                                            + (float)0.5)
                                                    * (float)255.0);
                                        v41.z = (float)((float)((float)(v41.z * (float)0.03125) * (float)0.5)
                                                      + (float)0.5)
                                              * (float)255.0;
                                        v39[1] = (int)v36;
                                        if ( (int)v36 >= 0 )
                                        {
                                          HIBYTE(v39[0]) = -1;
                                          if ( (int)v36 <= 255 )
                                            HIBYTE(v39[0]) = (int)v36;
                                        }
                                        else
                                        {
                                          HIBYTE(v39[0]) = 0;
                                        }
                                        idList<unsigned char,25>::Append(
                                          this: (idList<unsigned char,37> *)&v52.morphDirection,
                                          obj: (const unsigned __int8 *)v39);
                                        v39[1] = (int)v37;
                                        if ( (int)v37 >= 0 )
                                        {
                                          HIBYTE(v39[0]) = -1;
                                          if ( (int)v37 <= 255 )
                                            HIBYTE(v39[0]) = (int)v37;
                                        }
                                        else
                                        {
                                          HIBYTE(v39[0]) = 0;
                                        }
                                        idList<unsigned char,25>::Append(
                                          this: (idList<unsigned char,37> *)&v52.morphDirection,
                                          obj: (const unsigned __int8 *)v39);
                                        v39[1] = (int)v38;
                                        if ( (int)v38 >= 0 )
                                        {
                                          HIBYTE(v39[0]) = -1;
                                          if ( (int)v38 <= 255 )
                                            HIBYTE(v39[0]) = (int)v38;
                                        }
                                        else
                                        {
                                          HIBYTE(v39[0]) = 0;
                                        }
                                        idList<unsigned char,25>::Append(
                                          this: (idList<unsigned char,37> *)&v52.morphDirection,
                                          obj: (const unsigned __int8 *)v39);
                                      }
                                      HIWORD(v39[0]) = v33;
                                      idList<unsigned short,72>::Append(
                                        this: (idList<unsigned short,5> *)&v52.vertices,
                                        obj: (unsigned __int16 *)v39);
                                    }
                                    ++v33;
                                    v34 = (const idVec3 *)((char *)v34 + 32);
                                  }
                                  while ( v33 < *(_DWORD *)(v31 + 32) );
                                }
                                if ( v30 != 0 )
                                  idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)(v31 + 100));
                                if ( v52.vertices.num != 0 )
                                  idList<idMorphVertices::vertSet,5>::Append(this: &vertices->morphVertSet, obj: &v52);
                              }
                              else
                              {
                                idLib::Warning(
                                  fmt: "%s - Unable to Map vertex buffer for '%s",
                                  "idMorphVertGen::GenerateMorphVertsFromFile",
                                  *((const char **)v6 + 2));
                              }
                              idMorphVertices::vertSet::~vertSet(this: &v52);
                              v3 = decl;
                            }
                            ++v26;
                            v27 += 4;
                          }
                          while ( v26 < *((_DWORD *)v6 + 38) );
                          v5 = vertices;
                        }
                      }
                    }
                    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v51.points);
                  }
                  else
                  {
                    idLib::Warning(
                      fmt: "%s - Could not find indexes for %s",
                      "idMorphVertGen::GenerateMorphVertsFromFile",
                      v3->name.str);
                  }
                }
                else
                {
                  idLib::Warning(fmt: model, "idMorphVertGen::GenerateMorphVertsFromFile", v3->name.str);
                }
              }
              else
              {
                idLib::Warning(fmt: v44, "idMorphVertGen::GenerateMorphVertsFromFile", v3->name.str);
              }
              ++v43;
              v40 += 72;
            }
            while ( v43 < v53.surfaces.num );
          }
        }
        else
        {
          idLib::Warning(fmt: "%s - Unable to load '%s'", "idMorphVertGen::GenerateMorphVertsFromFile", genFile);
        }
        idStaticModel::~idStaticModel(this: &v53);
      }
      else
      {
        idLib::Warning(fmt: "%s - %s has no model", "idMorphVertGen::GenerateMorphVertsFromFile", decl->name.str);
      }
    }
    else
    {
      idLib::Warning(fmt: "%s - NULL projectionMeshName", "idMorphVertGen::GenerateMorphVertsFromFile");
    }
  }
  else
  {
    idLib::Warning(fmt: "%s - NULL decl", "idMorphVertGen::GenerateMorphVertsFromFile");
  }
}


// ========================================================================
// __unwind$236658
// EA  : 0x827DD810
// RVA : 0x007DD810
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236658()
{
  int v0; // r12

  idStaticModel::~idStaticModel(this: (idStaticModel *)(v0 - 960 + 352));
}


// ========================================================================
// __unwind$236659
// EA  : 0x827DD838
// RVA : 0x007DD838
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236659()
{
  int v0; // r12

  idCrosshairInfo::~idCrosshairInfo(this: (idDeclFlare *)(v0 - 960 + 160));
}


// ========================================================================
// __unwind$236660
// EA  : 0x827DD860
// RVA : 0x007DD860
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_236660()
{
  int v0; // r12

  idMorphVertices::vertSet::~vertSet(this: (idMorphVertices::vertSet *)(v0 - 960 + 240));
}


// ========================================================================
// ?GenerateMorphVerts@idMorphVertGen@@SAXPBVidDeclMD6@@ABV?$idList@VidMorphDef@@$04@@AAVidMorphVertices@@@Z
// EA  : 0x827DD890
// RVA : 0x007DD890
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __fastcall idMorphVertGen::GenerateMorphVerts(
        const idDeclMD6 *decl,
        const idList<idMorphDef,5> *morphDef,
        idMorphVertices *verts)
{
  int v6; // r28
  int v7; // r29
  idMorphDef *v8; // r5
  int v9; // r28
  int v10; // r29
  idMorphDef *v11; // r11
  idMorphVertices v12[2]; // [sp+50h] [-80h] BYREF

  if ( decl != nullptr )
  {
    if ( decl->model != nullptr )
    {
      if ( morphDef->num != 0 )
      {
        idMorphVertices::idMorphVertices(this: v12);
        v6 = 0;
        if ( morphDef->num > 0 )
        {
          v7 = 0;
          do
          {
            v8 = &morphDef->list[v7];
            if ( v8->fileName.len == 0 )
              idMorphVertGen::ProcessModel(model: decl->model, decl, morphDef: v8, vertices: v12);
            ++v6;
            ++v7;
          }
          while ( v6 < morphDef->num );
        }
        idMorphVertGen::OptimizeVertices(outputVerts: verts, inputVerts: v12);
        v9 = 0;
        if ( morphDef->num > 0 )
        {
          v10 = 0;
          do
          {
            v11 = &morphDef->list[v10];
            if ( v11->fileName.len != 0 )
              idMorphVertGen::GenerateMorphVertsFromFile(decl, genFile: v11->fileName.data, vertices: verts);
            ++v9;
            ++v10;
          }
          while ( v9 < morphDef->num );
        }
        if ( v12[0].morphVertSet.listStatic == 0 || v12[0].morphVertSet.listStatic == 2 )
        {
          if ( v12[0].morphVertSet.list != nullptr )
            idListArrayDelete<idMorphVertices::vertSet>(
              ptr: (char *)v12[0].morphVertSet.list,
              num: v12[0].morphVertSet.size);
          v12[0].morphVertSet.list = nullptr;
          v12[0].morphVertSet.size = 0;
        }
        v12[0].morphVertSet.num = 0;
        idResource::~idResource(this: &v12[0]);
      }
      else
      {
        idLib::Warning(fmt: "idMorphVertGen::GenMorphVerts() - no morphDef passed in for %s.", decl->name.str);
      }
    }
    else
    {
      idLib::Warning(fmt: "idMorphVertGen::GenMorphVerts() - no model passed in for %s.", decl->name.str);
    }
  }
  else
  {
    idLib::Warning(fmt: "idMorphVertGen::GenMorphVerts() - null decl passed in");
  }
}


// ========================================================================
// __unwind$237058
// EA  : 0x827DD9F8
// RVA : 0x007DD9F8
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_237058()
{
  int v0; // r12

  idMorphVertices::~idMorphVertices(this: (idMorphVertices *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$237120
// EA  : 0x827DDA20
// RVA : 0x007DDA20
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_237120()
{
  int v0; // r12

  idResource::~idResource(this: (idResource *)(v0 - 208 + 80));
}


// ========================================================================
// ?Write_Binary@idMorphVertices@@QAA_NXZ
// EA  : 0x827DDA50
// RVA : 0x007DDA50
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

int __fastcall idMorphVertices::Write_Binary(idMorphVertices *this)
{
  const char *str; // r4
  const idDecl *v3; // r3
  _DWORD *v4; // r30
  idList<idMorphVertices::vertSet,5> *p_morphVertSet; // r29
  int v7; // r28
  int v8; // r30
  idFileLocal v9; // [sp+50h] [-70h] BYREF
  int v10; // [sp+54h] [-6Ch] BYREF
  int v11; // [sp+58h] [-68h] BYREF
  int v12; // [sp+5Ch] [-64h] BYREF
  int num; // [sp+60h] [-60h] BYREF
  int v14; // [sp+64h] [-5Ch] BYREF
  int v15; // [sp+68h] [-58h] BYREF
  int v16; // [sp+6Ch] [-54h] BYREF
  idStr v17[2]; // [sp+70h] [-50h] BYREF

  str = this->name.str;
  if ( str != nullptr
    && (v3 = idDeclInfo::FindWithInheritance(this: &idDeclMD6::resourceList, name: str, makeDefault: false),
        v4 = &v3->__vftable,
        v3 != nullptr) )
  {
    if ( v3[1].trackedMemory != 0 )
    {
      idStr::idStr(this: v17, text: "generated/skins/morphVertices/");
      idStr::Append(this: v17, text: *(char **)(v4[15] + 8));
      idStr::SetFileExtension(this: v17, extension: ".morph");
      v9.file = fileSystem->OpenFileWrite(this: fileSystem, a2: v17[0].data, a3: 0);
      if ( v9.file != nullptr )
      {
        idLib::Printf(fmt: "Writing %s\n", v17[0].data);
        v10 = 88625229;
        v9.file->Write(this: v9.file, a2: &v10, a3: 4u);
        v11 = (*(int (__fastcall **)(_DWORD *))(*v4 + 28))(a1: v4);
        v9.file->Write(this: v9.file, a2: &v11, a3: 4u);
        v12 = *(_DWORD *)(v4[15] + 68);
        v9.file->Write(this: v9.file, a2: &v12, a3: 4u);
        idMorphVertGen::GenerateMorphVerts(
          decl: (const idDeclMD6 *)v4,
          morphDef: (const idList<idMorphDef,5> *)v4 + 42,
          verts: this);
        p_morphVertSet = &this->morphVertSet;
        num = p_morphVertSet->num;
        v9.file->Write(this: v9.file, a2: &num, a3: 4u);
        v7 = 0;
        if ( p_morphVertSet->num > 0 )
        {
          v8 = 0;
          do
          {
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8], a3: 4u);
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8].jointGroupIndex, a3: 4u);
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8].flags, a3: 4u);
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8].pos, a3: 12u);
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8].size, a3: 12u);
            v9.file->Write(this: v9.file, a2: &p_morphVertSet->list[v8].axis, a3: 36u);
            v14 = p_morphVertSet->list[v8].vertices.num;
            v9.file->Write(this: v9.file, a2: &v14, a3: 4u);
            v9.file->Write(
              this: v9.file,
              a2: p_morphVertSet->list[v8].vertices.list,
              a3: 2 * p_morphVertSet->list[v8].vertices.num);
            v15 = p_morphVertSet->list[v8].morphDirection.num;
            v9.file->Write(this: v9.file, a2: &v15, a3: 4u);
            v9.file->Write(
              this: v9.file,
              a2: p_morphVertSet->list[v8].morphDirection.list,
              a3: p_morphVertSet->list[v8].morphDirection.num);
            ++v7;
            ++v8;
          }
          while ( v7 < p_morphVertSet->num );
        }
        v16 = 88625229;
        v9.file->Write(this: v9.file, a2: &v16, a3: 4u);
        idFileLocal::~idFileLocal(this: &v9);
        idStr::FreeData(this: v17);
        return 1;
      }
      else
      {
        idLib::Warning(fmt: "idMorphVertices::Write_Binary() : Could not open %s", v17[0].data);
        idFileLocal::~idFileLocal(this: &v9);
        idStr::FreeData(this: v17);
        return 0;
      }
    }
    else
    {
      idLib::Warning(fmt: "idMorphVertices::Write_Binary() : failed to findmodel for '%s'", this->name.str);
      return 0;
    }
  }
  else
  {
    idLib::Warning(fmt: "idMorphVertices::Write_Binary() : failed to find md6Def '%s'", this->name.str);
    return 0;
  }
}


// ========================================================================
// __unwind$237181
// EA  : 0x827DDDF8
// RVA : 0x007DDDF8
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_237181()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$237182
// EA  : 0x827DDE20
// RVA : 0x007DDE20
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void _unwind_237182()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 192 + 80));
}


// ========================================================================
// ?LoadResource@idMorphVertices@@UAAXXZ
// EA  : 0x827DDE48
// RVA : 0x007DDE48
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __fastcall idMorphVertices::LoadResource(idMorphVertices *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // [sp+8h] [-68h]
  int v6; // [sp+Ch] [-64h]
  int v7; // [sp+10h] [-60h]
  int v8; // [sp+14h] [-5Ch]
  int v9; // [sp+18h] [-58h]
  int v10; // [sp+1Ch] [-54h]

  if ( md6_ForceGenMorphVerts.valueInteger != 0 || (unsigned __int8)idMorphVertices::Load_Binary(this) == 0 )
  {
    idCVar::SetBool(this: &md6_ForceGenMorphVerts, newValue: false, force: true);
    if ( (unsigned int)idLib::production <= PROD_BUILDING && (unsigned __int8)idMorphVertices::Write_Binary(this) == 0 )
    {
      HIDWORD(v4) = this->name.str;
      idResource::SetResourceError(
        this,
        fmt: "idMorphVertices load resource failed '%s'",
        a3: v4,
        a4: v3,
        a5: v2,
        a6: v5,
        a7: v6,
        a8: v7,
        a9: v8,
        a10: v9,
        a11: v10);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'idMorphVertices::resourceList''
// EA  : 0x83342EE0
// RVA : 0x01342EE0
// PDB : w:\tech5\engine\models\morphskingen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idMorphVertices::resourceList__()
{
  idResourceList::idResourceList(this: &idMorphVertices::resourceList, typeName: "morphVertices");
  idMorphVertices::resourceList.__vftable = (idTypedResourceList<idMorphVertices>_vtbl *)&idTypedResourceList<idMorphVertices>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idMorphVertices::resourceList__);
}

