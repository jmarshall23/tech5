
// ========================================================================
// ?InterpolateColor@idTriangleInterpolator@@CAIABUTriangle_t@1@MM@Z
// EA  : 0x827C95D0
// RVA : 0x007C95D0
// PDB : w:\tech5\engine\models\cuttable\triangleinterpolator.cpp
// ========================================================================

unsigned int __fastcall idTriangleInterpolator::InterpolateColor(
        const idTriangleInterpolator::Triangle_t *tri,
        double u,
        double v)
{
  idVec4 v7; // [sp+50h] [-50h] BYREF
  idVec4 v8; // [sp+60h] [-40h] BYREF
  idVec4 v9; // [sp+70h] [-30h] BYREF

  idColor::UnpackColor(color: tri->c0, unpackedColor: &v7);
  idColor::UnpackColor(color: tri->c1, unpackedColor: &v8);
  idColor::UnpackColor(color: tri->c2, unpackedColor: &v9);
  v7.x = (float)((float)((float)(v7.x * (float)((float)1.0 - (float)u)) + (float)(v8.x * (float)u))
               * (float)((float)1.0 - (float)v))
       + (float)(v9.x * (float)v);
  v7.y = (float)((float)((float)(v7.y * (float)((float)1.0 - (float)u)) + (float)(v8.y * (float)u))
               * (float)((float)1.0 - (float)v))
       + (float)(v9.y * (float)v);
  v7.z = (float)((float)((float)(v7.z * (float)((float)1.0 - (float)u)) + (float)(v8.z * (float)u))
               * (float)((float)1.0 - (float)v))
       + (float)(v9.z * (float)v);
  v7.w = (float)((float)((float)(v7.w * (float)((float)1.0 - (float)u)) + (float)(v8.w * (float)u))
               * (float)((float)1.0 - (float)v))
       + (float)(v9.w * (float)v);
  return idColor::PackColor(color: &v7);
}


// ========================================================================
// ?Clear@idTriangleInterpolator@@QAAXXZ
// EA  : 0x827C96F0
// RVA : 0x007C96F0
// PDB : w:\tech5\engine\models\cuttable\triangleinterpolator.cpp
// ========================================================================

void __fastcall idTriangleInterpolator::Clear(idTriangleInterpolator *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  __asm { vspltisw128 v63, 0 }
  _R11 = &this->refVert;
  _R10 = 16;
  __asm
  {
    vcmpequw128 v62, v95, v63
    stvx128   v63, r0, r11
    vsldoi128 v61, v95, v62, 4
    stvx128   v61, r11, r10
  }
  this->refNormal.z = 0.0;
  this->refNormal.y = 0.0;
  this->refNormal.x = 0.0;
  this->refLeft.z = 0.0;
  this->refLeft.y = 0.0;
  this->refLeft.x = 0.0;
  this->refDown.z = 0.0;
  this->refDown.y = 0.0;
  this->refDown.x = 0.0;
}


// ========================================================================
// ?Interpolate@idTriangleInterpolator@@QBA_NABVidVec2@@AAVidDrawVert@@AAV2@@Z
// EA  : 0x827C9768
// RVA : 0x007C9768
// PDB : w:\tech5\engine\models\cuttable\triangleinterpolator.cpp
// ========================================================================

int __fastcall idTriangleInterpolator::Interpolate(
        idTriangleInterpolator *this,
        const idVec2 *point,
        idDrawVert *vert,
        idVec2 *st)
{
  int num; // r9
  int v9; // r10
  idTriangleInterpolator::Triangle_t *list; // r8
  double x; // fp13
  int v12; // r11
  double y; // fp11
  double v14; // fp0
  idTriangleInterpolator::Triangle_t *v15; // r3
  double v16; // fp1
  double v17; // fp2
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  double v22; // fp28
  unsigned int v23; // r3
  double v24; // fp5
  double v25; // fp3
  double v26; // fp0
  double v27; // fp13

  num = this->triangles.num;
  v9 = 0;
  if ( num <= 0 )
    return 0;
  list = this->triangles.list;
  v12 = 0;
  v14 = -0.00000011920929;
  while ( 1 )
  {
    v15 = &list[v12];
    v16 = (float)((float)((float)(list[v12].d11
                                * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                        + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x))))
                        - (float)(list[v12].d01
                                * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                        + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x)))))
                * list[v12].invDenom);
    v17 = (float)((float)((float)(list[v12].d00
                                * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                        + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x))))
                        - (float)(list[v12].d01
                                * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                        + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x)))))
                * list[v12].invDenom);
    if ( v16 >= v14 && v17 >= v14 )
    {
      x = point->x;
      y = point->y;
      if ( (float)((float)((float)((float)(list[v12].d00
                                         * (float)((float)(list[v12].v1.y * (float)((float)y - list[v12].xy.y))
                                                 + (float)(list[v12].v1.x * (float)((float)x - list[v12].xy.x))))
                                 - (float)(list[v12].d01
                                         * (float)((float)(list[v12].v0.y * (float)((float)y - list[v12].xy.y))
                                                 + (float)(list[v12].v0.x * (float)((float)x - list[v12].xy.x)))))
                         * list[v12].invDenom)
                 + (float)((float)((float)(list[v12].d11
                                         * (float)((float)(list[v12].v0.y * (float)((float)y - list[v12].xy.y))
                                                 + (float)(list[v12].v0.x * (float)((float)x - list[v12].xy.x))))
                                 - (float)(list[v12].d01
                                         * (float)((float)(list[v12].v1.y * (float)((float)y - list[v12].xy.y))
                                                 + (float)(list[v12].v1.x * (float)((float)x - list[v12].xy.x)))))
                         * list[v12].invDenom)) <= (double)(float)((float)0.00000011920929 + (float)1.0) )
        break;
    }
    ++v9;
    ++v12;
    if ( v9 >= num )
      return 0;
  }
  v19 = (float)((float)((float)(v15->st0[0].x
                              * (float)((float)((float)(list[v12].d11
                                                      * (float)((float)(list[v12].v0.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v0.x
                                                                      * (float)(point->x - list[v12].xy.x))))
                                              - (float)(list[v12].d01
                                                      * (float)((float)(list[v12].v1.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v1.x
                                                                      * (float)(point->x - list[v12].xy.x)))))
                                      * list[v12].invDenom))
                      + v15->st[0].x)
              + (float)(v15->st1[0].x
                      * (float)((float)((float)(list[v12].d00
                                              * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x))))
                                      - (float)(list[v12].d01
                                              * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x)))))
                              * list[v12].invDenom)));
  v20 = (float)((float)(v15->st[0].y
                      + (float)(v15->st0[0].y
                              * (float)((float)((float)(list[v12].d11
                                                      * (float)((float)(list[v12].v0.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v0.x
                                                                      * (float)(point->x - list[v12].xy.x))))
                                              - (float)(list[v12].d01
                                                      * (float)((float)(list[v12].v1.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v1.x
                                                                      * (float)(point->x - list[v12].xy.x)))))
                                      * list[v12].invDenom)))
              + (float)(v15->st1[0].y
                      * (float)((float)((float)(list[v12].d00
                                              * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x))))
                                      - (float)(list[v12].d01
                                              * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x)))))
                              * list[v12].invDenom)));
  v21 = (float)((float)(v15->st[1].x
                      + (float)(v15->st0[1].x
                              * (float)((float)((float)(list[v12].d11
                                                      * (float)((float)(list[v12].v0.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v0.x
                                                                      * (float)(point->x - list[v12].xy.x))))
                                              - (float)(list[v12].d01
                                                      * (float)((float)(list[v12].v1.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v1.x
                                                                      * (float)(point->x - list[v12].xy.x)))))
                                      * list[v12].invDenom)))
              + (float)(v15->st1[1].x
                      * (float)((float)((float)(list[v12].d00
                                              * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x))))
                                      - (float)(list[v12].d01
                                              * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x)))))
                              * list[v12].invDenom)));
  v22 = (float)((float)(v15->st[1].y
                      + (float)(v15->st0[1].y
                              * (float)((float)((float)(list[v12].d11
                                                      * (float)((float)(list[v12].v0.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v0.x
                                                                      * (float)(point->x - list[v12].xy.x))))
                                              - (float)(list[v12].d01
                                                      * (float)((float)(list[v12].v1.y
                                                                      * (float)(point->y - list[v12].xy.y))
                                                              + (float)(list[v12].v1.x
                                                                      * (float)(point->x - list[v12].xy.x)))))
                                      * list[v12].invDenom)))
              + (float)(v15->st1[1].y
                      * (float)((float)((float)(list[v12].d00
                                              * (float)((float)(list[v12].v1.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v1.x * (float)(point->x - list[v12].xy.x))))
                                      - (float)(list[v12].d01
                                              * (float)((float)(list[v12].v0.y * (float)(point->y - list[v12].xy.y))
                                                      + (float)(list[v12].v0.x * (float)(point->x - list[v12].xy.x)))))
                              * list[v12].invDenom)));
  v23 = idTriangleInterpolator::InterpolateColor(tri: v15, u: v16, v: v17);
  vert->xyz.x = this->refVert.xyz.x;
  vert->xyz.y = this->refVert.xyz.y;
  vert->xyz.z = this->refVert.xyz.z;
  vert->st.x = this->refVert.st.x;
  vert->st.y = this->refVert.st.y;
  vert->normal[0] = this->refVert.normal[0];
  vert->normal[1] = this->refVert.normal[1];
  vert->normal[2] = this->refVert.normal[2];
  vert->normal[3] = this->refVert.normal[3];
  vert->tangent[0] = this->refVert.tangent[0];
  vert->tangent[1] = this->refVert.tangent[1];
  vert->tangent[2] = this->refVert.tangent[2];
  vert->tangent[3] = this->refVert.tangent[3];
  vert->color[0] = this->refVert.color[0];
  vert->color[1] = this->refVert.color[1];
  vert->color[2] = this->refVert.color[2];
  vert->color[3] = this->refVert.color[3];
  v24 = (float)(this->refDown.y * point->y);
  v25 = (float)(this->refDown.z * point->y);
  v26 = (float)(this->refLeft.y * point->x);
  v27 = (float)(this->refLeft.z * point->x);
  vert->xyz.x = (float)(point->x * this->refLeft.x) + (float)(this->refDown.x * point->y);
  vert->xyz.y = (float)v26 + (float)v24;
  vert->xyz.z = (float)v27 + (float)v25;
  vert->st.x = v19;
  vert->st.y = v20;
  vert->color[3] = HIBYTE(v23);
  vert->color[2] = BYTE1(v23);
  vert->color[1] = BYTE2(v23);
  vert->color[0] = v23;
  st->x = v21;
  st->y = v22;
  return 1;
}


// ========================================================================
// ?AddTriangle@idTriangleInterpolator@@AAAXABVidVec3@@0ABVidDrawVert@@11ABVidVec2@@22@Z
// EA  : 0x827C9CA0
// RVA : 0x007C9CA0
// PDB : w:\tech5\engine\models\cuttable\triangleinterpolator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idTriangleInterpolator::AddTriangle(
        idTriangleInterpolator *this,
        const idVec3 *left,
        const idVec3 *down,
        const idDrawVert *v0,
        const idDrawVert *v1,
        const idDrawVert *v2,
        const idVec2 *orgST0,
        const idVec2 *orgST1,
        const idVec2 *orgST2,
        int a10,
        int a11,
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
        float *a28)
{
  double z; // fp30
  __int64 v29; // r9 OVERLAPPED
  double v30; // fp8
  double v31; // fp4
  idVec2 v32; // r4
  __int64 v33; // r11 OVERLAPPED
  double v34; // fp9
  double v35; // fp8
  double v36; // fp5
  double v37; // fp4
  double v38; // fp1
  double v39; // fp31
  double v42; // fp2
  double v43; // fp2
  double v44; // fp2
  double v45; // fp2
  double v46; // fp30
  double v47; // fp28
  double v48; // fp27
  double v49; // fp26
  double v50; // fp25
  double v51; // fp24
  double v52; // fp4
  double v53; // fp14
  double v54; // fp17
  double v55; // fp18
  double v56; // fp28
  double v58; // fp10
  double v59; // fp8
  double v61; // fp22
  double v62; // fp22
  double v63; // fp22
  double v64; // fp22
  double v65; // fp25
  double v66; // fp23
  double v67; // fp31
  double v68; // fp23
  double v69; // fp1
  double v70; // fp29
  double v71; // fp3
  double v72; // fp2
  double v73; // fp6
  double v74; // fp9
  double v75; // fp5
  double v76; // fp7
  double v79; // fp13
  double v80; // fp13
  double v81; // fp13
  double v82; // fp20
  double v83; // fp11
  double v84; // fp19
  double v85; // fp21
  int v86; // r5
  int v87; // r6
  double v88; // fp24
  double v89; // fp23
  double v90; // fp25
  double v91; // fp27
  double v92; // fp1
  double v93; // fp26
  double v94; // fp31
  double v95; // fp21
  int v96; // r6
  int v97; // r5
  idVec2 st; // [sp+50h] [-160h]
  float v99; // [sp+60h] [-150h]
  __int64 v100; // [sp+88h] [-128h]
  idTriangleInterpolator::Triangle_t v101; // [sp+90h] [-120h] BYREF

  z = v2->xyz.z;
  v30 = (float)((float)(v2->xyz.x * down->x) + (float)(v2->xyz.y * down->y));
  v31 = (float)((float)(v2->xyz.x * left->x) + (float)(v2->xyz.y * left->y));
  v29 = (__int64)*orgST0;
  v33 = (__int64)*orgST1;
  *(__int64 *)((char *)&v29 - 4) = *(_QWORD *)(HIDWORD(v29) + 12);
  v34 = (float)((float)(down->z * v0->xyz.z) + (float)((float)(down->x * v0->xyz.x) + (float)(down->y * v0->xyz.y)));
  st = v0->st;
  v35 = (float)((float)((float)z * down->z) + (float)v30);
  v36 = (float)((float)(v0->xyz.z * left->z) + (float)((float)(left->x * v0->xyz.x) + (float)(v0->xyz.y * left->y)));
  v37 = (float)((float)((float)z * left->z) + (float)v31);
  v100 = *(_QWORD *)a28;
  v38 = (float)((float)(v1->xyz.z * left->z) + (float)((float)(v1->xyz.x * left->x) + (float)(v1->xyz.y * left->y)));
  v39 = (float)((float)(v1->xyz.z * down->z) + (float)((float)(v1->xyz.x * down->x) + (float)(v1->xyz.y * down->y)));
  _FP2 = (float)((float)((float)((float)((float)v37 - (float)v36) * (float)((float)v37 - (float)v36))
                       + (float)((float)((float)v35 - (float)v34) * (float)((float)v35 - (float)v34)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f2, f3, f13 }
  v42 = __frsqrte(_FP2);
  v43 = (float)((float)-(float)((float)((float)((float)v42
                                              * (float)((float)((float)((float)((float)v37 - (float)v36)
                                                                      * (float)((float)v37 - (float)v36))
                                                              + (float)((float)((float)v35 - (float)v34)
                                                                      * (float)((float)v35 - (float)v34)))
                                                      * (float)0.5))
                                      * (float)v42)
                              - (float)1.5)
              * (float)v42);
  v44 = (float)((float)-(float)((float)((float)((float)v43
                                              * (float)((float)((float)((float)((float)v37 - (float)v36)
                                                                      * (float)((float)v37 - (float)v36))
                                                              + (float)((float)((float)v35 - (float)v34)
                                                                      * (float)((float)v35 - (float)v34)))
                                                      * (float)0.5))
                                      * (float)v43)
                              - (float)1.5)
              * (float)v43);
  v45 = (float)((float)-(float)((float)((float)((float)v44
                                              * (float)((float)((float)((float)((float)v37 - (float)v36)
                                                                      * (float)((float)v37 - (float)v36))
                                                              + (float)((float)((float)v35 - (float)v34)
                                                                      * (float)((float)v35 - (float)v34)))
                                                      * (float)0.5))
                                      * (float)v44)
                              - (float)1.5)
              * (float)v44);
  v46 = (float)((float)v34 - (float)((float)((float)v35 - (float)v34) * (float)v45));
  v47 = (float)((float)1.0
              / (float)((float)v45
                      * (float)((float)((float)((float)v37 - (float)v36) * (float)((float)v37 - (float)v36))
                              + (float)((float)((float)v35 - (float)v34) * (float)((float)v35 - (float)v34)))));
  v48 = (float)((float)((float)((float)v37
                              - (float)((float)(v0->xyz.z * left->z)
                                      + (float)((float)(left->x * v0->xyz.x) + (float)(v0->xyz.y * left->y))))
                      * (float)v45)
              + (float)v37);
  v49 = (float)((float)((float)((float)v35
                              - (float)((float)(down->z * v0->xyz.z)
                                      + (float)((float)(down->x * v0->xyz.x) + (float)(down->y * v0->xyz.y))))
                      * (float)v45)
              + (float)v35);
  v50 = (float)((float)((float)v34 - (float)((float)((float)v35 - (float)v34) * (float)v45))
              - (float)((float)(v1->xyz.z * down->z)
                      + (float)((float)(v1->xyz.x * down->x) + (float)(v1->xyz.y * down->y))));
  v51 = (float)((float)((float)v36 - (float)((float)((float)v37 - (float)v36) * (float)v45))
              - (float)((float)(v1->xyz.z * left->z)
                      + (float)((float)(v1->xyz.x * left->x) + (float)(v1->xyz.y * left->y))));
  v32 = v1->st;
  v99 = *a28 - *(float *)&v33;
  v53 = *(float *)&v33;
  v54 = (float)((float)(*a28 - *(float *)&v29)
              * (float)((float)1.0
                      / (float)((float)v45
                              * (float)((float)((float)((float)v37 - (float)v36) * (float)((float)v37 - (float)v36))
                                      + (float)((float)((float)v35 - (float)v34) * (float)((float)v35 - (float)v34))))));
  v55 = (float)(v32.x - *((float *)&v29 + 1));
  _FP16 = (float)((float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v58 = (float)(*((float *)&v29 + 1)
              + (float)((float)(*((float *)&v29 + 1) - st.x)
                      * (float)((float)1.0
                              / (float)((float)v45
                                      * (float)((float)((float)((float)v37 - (float)v36)
                                                      * (float)((float)v37 - (float)v36))
                                              + (float)((float)((float)v35 - (float)v34)
                                                      * (float)((float)v35 - (float)v34)))))));
  __asm { fsel      f22, f16, f23, f13 }
  v61 = __frsqrte(_FP22);
  v62 = (float)((float)-(float)((float)((float)((float)v61
                                              * (float)((float)((float)((float)v51 * (float)v51)
                                                              + (float)((float)v50 * (float)v50))
                                                      * (float)0.5))
                                      * (float)v61)
                              - (float)1.5)
              * (float)v61);
  v63 = (float)((float)-(float)((float)((float)((float)v62
                                              * (float)((float)((float)((float)v51 * (float)v51)
                                                              + (float)((float)v50 * (float)v50))
                                                      * (float)0.5))
                                      * (float)v62)
                              - (float)1.5)
              * (float)v62);
  v64 = (float)((float)-(float)((float)((float)((float)v63
                                              * (float)((float)((float)((float)v51 * (float)v51)
                                                              + (float)((float)v50 * (float)v50))
                                                      * (float)0.5))
                                      * (float)v63)
                              - (float)1.5)
              * (float)v63);
  v66 = (float)((float)v64 * (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)));
  v65 = (float)((float)((float)((float)v34 - (float)((float)((float)v35 - (float)v34) * (float)v45))
                      - (float)((float)(v1->xyz.z * down->z)
                              + (float)((float)(v1->xyz.x * down->x) + (float)(v1->xyz.y * down->y))))
              * (float)v64);
  v67 = (float)((float)v39
              - (float)((float)((float)((float)v34 - (float)((float)((float)v35 - (float)v34) * (float)v45)) - (float)v39)
                      * (float)v64));
  v59 = (float)(*(float *)&v33
              + (float)((float)(*(float *)&v33 - st.y)
                      * (float)((float)1.0
                              / (float)((float)v45
                                      * (float)((float)((float)((float)v37 - (float)v36)
                                                      * (float)((float)v37 - (float)v36))
                                              + (float)((float)((float)v35 - (float)v34)
                                                      * (float)((float)v35 - (float)v34)))))));
  v68 = (float)((float)1.0 / (float)v66);
  v70 = (float)((float)((float)((float)((float)v36 - (float)((float)((float)v37 - (float)v36) * (float)v45)) - (float)v38)
                      * (float)v64)
              + (float)((float)v36 - (float)((float)((float)v37 - (float)v36) * (float)v45)));
  v69 = (float)((float)v38
              - (float)((float)((float)((float)v36 - (float)((float)((float)v37 - (float)v36) * (float)v45)) - (float)v38)
                      * (float)v64));
  v52 = *a28;
  v71 = (float)((float)(*(float *)&v29 - *(float *)&v33) * (float)v68);
  v72 = (float)((float)(*((float *)&v29 + 1) - *((float *)&v33 + 1)) * (float)v68);
  v73 = (float)(v32.x - (float)((float)(st.x - v32.x) * (float)v68));
  v74 = (float)((float)(st.x - (float)((float)(*((float *)&v29 + 1) - st.x) * (float)v47))
              + (float)((float)(st.x - v32.x) * (float)v68));
  v75 = (float)(*a28 - (float)((float)(st.y - *a28) * (float)v68));
  v76 = (float)((float)(st.y - (float)((float)(*(float *)&v33 - st.y) * (float)v47))
              + (float)((float)(st.y - *a28) * (float)v68));
  _FP22 = (float)((float)((float)((float)((float)v69 - (float)v48) * (float)((float)v69 - (float)v48))
                        + (float)((float)((float)v67 - (float)v49) * (float)((float)v67 - (float)v49)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f22, f23, f13 }
  v79 = __frsqrte(_FP13);
  v80 = (float)((float)-(float)((float)((float)((float)v79
                                              * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                      * (float)((float)v69 - (float)v48))
                                                              + (float)((float)((float)v67 - (float)v49)
                                                                      * (float)((float)v67 - (float)v49)))
                                                      * (float)0.5))
                                      * (float)v79)
                              - (float)1.5)
              * (float)v79);
  v81 = (float)((float)-(float)((float)((float)((float)v80
                                              * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                      * (float)((float)v69 - (float)v48))
                                                              + (float)((float)((float)v67 - (float)v49)
                                                                      * (float)((float)v67 - (float)v49)))
                                                      * (float)0.5))
                                      * (float)v80)
                              - (float)1.5)
              * (float)v80);
  v82 = (float)(*(float *)&v29 - (float)((float)(*a28 - *(float *)&v29) * (float)v47));
  v56 = (float)((float)(a28[1] - *((float *)&v29 + 1)) * (float)v47);
  v83 = *((float *)&v33 + 1);
  v84 = (float)(*((float *)&v29 + 1) - (float)v56);
  v85 = (float)(*(float *)&v33 - *a28);
  v101.xy.x = v70;
  LODWORD(v32.y) = v0->color[3];
  LODWORD(v33) = v0->color[2];
  v101.xy.y = (float)v65 + (float)v46;
  HIDWORD(v33) = __ROL4__(LODWORD(v32.y), 8);
  LODWORD(v29) = v0->color[1];
  LODWORD(v32.y) = v1->color[3];
  v86 = HIDWORD(v33) | v33;
  HIDWORD(v33) = v1->color[2];
  v87 = v0->color[0];
  v101.st[0].x = v74;
  v88 = (float)((float)((float)v69 - (float)v48)
              * (float)((float)-(float)((float)((float)((float)v81
                                                      * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                              * (float)((float)v69 - (float)v48))
                                                                      + (float)((float)((float)v67 - (float)v49)
                                                                              * (float)((float)v67 - (float)v49)))
                                                              * (float)0.5))
                                              * (float)v81)
                                      - (float)1.5)
                      * (float)v81));
  v89 = (float)((float)((float)-(float)((float)((float)((float)v81
                                                      * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                              * (float)((float)v69 - (float)v48))
                                                                      + (float)((float)((float)v67 - (float)v49)
                                                                              * (float)((float)v67 - (float)v49)))
                                                              * (float)0.5))
                                              * (float)v81)
                                      - (float)1.5)
                      * (float)v81)
              * (float)((float)((float)((float)v69 - (float)v48) * (float)((float)v69 - (float)v48))
                      + (float)((float)((float)v67 - (float)v49) * (float)((float)v67 - (float)v49))));
  v90 = (float)((float)((float)v67 - (float)v49)
              * (float)((float)-(float)((float)((float)((float)v81
                                                      * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                              * (float)((float)v69 - (float)v48))
                                                                      + (float)((float)((float)v67 - (float)v49)
                                                                              * (float)((float)v67 - (float)v49)))
                                                              * (float)0.5))
                                              * (float)v81)
                                      - (float)1.5)
                      * (float)v81));
  LODWORD(v33) = __ROL4__(LODWORD(v32.y), 8) | HIDWORD(v33);
  HIDWORD(v33) = (((v86 << 8) | (unsigned int)v29) << 8) | v87;
  LODWORD(v29) = v1->color[1];
  v101.st[0].y = v76;
  v91 = (float)((float)v48
              - (float)((float)((float)v69 - (float)v48)
                      * (float)((float)-(float)((float)((float)((float)v81
                                                              * (float)((float)((float)((float)((float)v69 - (float)v48)
                                                                                      * (float)((float)v69 - (float)v48))
                                                                              + (float)((float)((float)v67 - (float)v49)
                                                                                      * (float)((float)v67 - (float)v49)))
                                                                      * (float)0.5))
                                                      * (float)v81)
                                              - (float)1.5)
                              * (float)v81)));
  v101.st[1].x = (float)v82 + (float)v71;
  v92 = (float)((float)v88 + (float)v69);
  v101.c0 = HIDWORD(v33);
  v93 = (float)((float)v49 - (float)v90);
  v94 = (float)((float)v90 + (float)v67);
  v101.v1.x = (float)v92 - (float)v70;
  v101.v0.y = (float)v93 - v101.xy.y;
  v101.v0.x = (float)v91 - (float)v70;
  v95 = (float)((float)v85 * (float)((float)1.0 / (float)v89));
  v101.v1.y = (float)v94 - v101.xy.y;
  v101.d11 = (float)(v101.v1.y * v101.v1.y) + (float)(v101.v1.x * v101.v1.x);
  v101.st1[0].x = (float)((float)v73 + (float)((float)v55 * (float)((float)1.0 / (float)v89))) - (float)v74;
  v101.d00 = (float)(v101.v0.x * v101.v0.x) + (float)(v101.v0.y * v101.v0.y);
  v101.d01 = (float)(v101.v0.y * v101.v1.y) + (float)(v101.v0.x * v101.v1.x);
  v101.st1[0].y = (float)((float)v75 + (float)(v99 * (float)((float)1.0 / (float)v89))) - (float)v76;
  v96 = __ROL4__(*(unsigned __int8 *)(HIDWORD(v29) + 31), 8) | *(unsigned __int8 *)(HIDWORD(v29) + 30);
  HIDWORD(v33) = *(unsigned __int8 *)(HIDWORD(v29) + 29);
  v97 = v1->color[0];
  v101.st0[0].x = (float)((float)v58 - (float)((float)v55 * (float)((float)1.0 / (float)v89))) - (float)v74;
  LODWORD(v32.y) = *(unsigned __int8 *)(HIDWORD(v29) + 28);
  v101.st0[0].y = (float)((float)v59 - (float)(v99 * (float)((float)1.0 / (float)v89))) - (float)v76;
  v101.st[1].y = (float)v84 + (float)v72;
  v101.st1[1].x = (float)((float)((float)v53 - (float)v71) + (float)v95) - v101.st[1].x;
  v101.st0[1].x = (float)((float)((float)v52 + (float)v54) - (float)v95) - v101.st[1].x;
  v101.c1 = ((((_DWORD)v33 << 8) | (unsigned int)v29) << 8) | v97;
  v101.st1[1].y = (float)((float)((float)v83 - (float)v72)
                        + (float)((float)((float)v83 - *((float *)&v100 + 1)) * (float)((float)1.0 / (float)v89)))
                - v101.st[1].y;
  v101.st0[1].y = (float)((float)(*((float *)&v100 + 1) + (float)v56)
                        - (float)((float)((float)v83 - *((float *)&v100 + 1)) * (float)((float)1.0 / (float)v89)))
                - v101.st[1].y;
  v101.c2 = (((v96 << 8) | HIDWORD(v33)) << 8) | LODWORD(v32.y);
  v101.invArea = (float)1.0
               / (float)((float)((float)((float)v93 - (float)v94) * v101.v1.x)
                       - (float)((float)((float)v91 - (float)v92) * v101.v1.y));
  v101.invDenom = (float)1.0 / (float)((float)(v101.d11 * v101.d00) - (float)(v101.d01 * v101.d01));
  idList<idTriangleInterpolator::Triangle_t,5>::Append(
    this: (idList<idTriangleInterpolator::Triangle_t,5> *)LODWORD(v32.x),
    obj: &v101);
}


// ========================================================================
// ?AddTriangles@idTriangleInterpolator@@QAAXPBVidDrawVert@@PBVidVec2@@PBGH@Z
// EA  : 0x827CA130
// RVA : 0x007CA130
// PDB : w:\tech5\engine\models\cuttable\triangleinterpolator.cpp
// ========================================================================

void __fastcall idTriangleInterpolator::AddTriangles(
        idTriangleInterpolator *this,
        const idDrawVert *verts,
        const idVec2 *st,
        const unsigned __int16 *indices,
        int numIndices)
{
  int v9; // r26
  float *v10; // r30
  float *v11; // r11
  float *v12; // r10
  const unsigned __int16 *v13; // r28
  double v14; // fp1
  double v15; // fp3
  double v16; // fp5
  double v17; // fp13
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp2
  double v24; // fp3
  double v25; // fp10
  double v28; // fp8
  double v29; // fp6
  double v30; // fp12
  double v31; // fp10
  double v32; // fp8
  float z; // r3
  float x; // r11
  float y; // r10
  float v36; // r9
  int size; // r8
  float v38; // r7
  const unsigned __int16 *v39; // r30
  unsigned int v40; // r28
  int v41; // r7
  int v42; // r6
  const idVec2 *v43; // [sp+8h] [-C8h]
  int v44; // [sp+Ch] [-C4h]
  int v45; // [sp+10h] [-C0h]
  int v46; // [sp+14h] [-BCh]
  int v47; // [sp+18h] [-B8h]
  int v48; // [sp+1Ch] [-B4h]
  int v49; // [sp+20h] [-B0h]
  int v50; // [sp+24h] [-ACh]
  int v51; // [sp+28h] [-A8h]
  int v52; // [sp+2Ch] [-A4h]
  int v53; // [sp+30h] [-A0h]
  int v54; // [sp+34h] [-9Ch]
  int v55; // [sp+38h] [-98h]
  int v56; // [sp+3Ch] [-94h]
  int v57; // [sp+40h] [-90h]
  int v58; // [sp+44h] [-8Ch]
  int v59; // [sp+48h] [-88h]
  int v60; // [sp+4Ch] [-84h]
  int v61; // [sp+50h] [-80h]
  idVec3 v62; // [sp+60h] [-70h] BYREF
  idVec3 v63; // [sp+70h] [-60h] BYREF

  v9 = numIndices / 3;
  if ( numIndices / 3 > 0 )
  {
    v10 = (float *)((char *)&verts->xyz.x + __ROL4__(*indices, 5));
    v11 = (float *)((char *)&verts->xyz.x + __ROL4__(indices[2], 5));
    v12 = (float *)((char *)&verts->xyz.x + __ROL4__(indices[1], 5));
    v13 = indices + 1;
    v14 = (float)(*v12 - *v10);
    v15 = (float)(v11[2] - v12[2]);
    v16 = (float)(v11[1] - v12[1]);
    v17 = (float)(v12[1] - v10[1]);
    v18 = (float)((float)(v12[1] - v10[1]) * (float)(*v11 - *v12));
    v19 = (float)((float)(v12[2] - v10[2]) * (float)(v11[1] - v12[1]));
    v20 = (float)((float)((float)(v12[2] - v10[2]) * (float)(*v11 - *v12))
                - (float)((float)(v11[2] - v12[2]) * (float)(*v12 - *v10)));
    this->refNormal.y = (float)((float)(v12[2] - v10[2]) * (float)(*v11 - *v12))
                      - (float)((float)(v11[2] - v12[2]) * (float)(*v12 - *v10));
    v21 = (float)((float)((float)v16 * (float)v14) - (float)v18);
    this->refNormal.z = (float)((float)v16 * (float)v14) - (float)v18;
    v22 = (float)((float)((float)v17 * (float)v15) - (float)v19);
    this->refNormal.x = (float)((float)v17 * (float)v15) - (float)v19;
    v23 = v20;
    v24 = v21;
    v25 = (float)((float)((float)v21 * (float)v21)
                + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)));
    _FP9 = (float)((float)((float)((float)v21 * (float)v21)
                         + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f10, f13 }
    v28 = (float)((float)v25 * (float)0.5);
    v29 = __frsqrte(_FP7);
    v30 = (float)((float)-(float)((float)((float)((float)v29 * (float)((float)v25 * (float)0.5)) * (float)v29)
                                - (float)1.5)
                * (float)v29);
    v31 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                * (float)((float)v25 * (float)0.5))
                                                                        * (float)v29)
                                                                - (float)1.5)
                                                * (float)v29)
                                        * (float)((float)v25 * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)v25 * (float)0.5))
                                                                * (float)v29)
                                                        - (float)1.5)
                                        * (float)v29))
                        - (float)1.5);
    v32 = (float)((float)((float)v31 * (float)v30) * (float)v28);
    this->refNormal.x = (float)v22
                      * (float)((float)-(float)((float)((float)v32 * (float)((float)v31 * (float)v30)) - (float)1.5)
                              * (float)((float)v31 * (float)v30));
    this->refNormal.y = (float)v23
                      * (float)((float)-(float)((float)((float)v32 * (float)((float)v31 * (float)v30)) - (float)1.5)
                              * (float)((float)v31 * (float)v30));
    this->refNormal.z = (float)v24
                      * (float)((float)-(float)((float)((float)v32 * (float)((float)v31 * (float)v30)) - (float)1.5)
                              * (float)((float)v31 * (float)v30));
    idVec3::NormalVectors(this: &this->refNormal, left: &this->refLeft, down: &this->refDown);
    this->refVert.xyz.x = *v10;
    this->refVert.xyz.y = v10[1];
    this->refVert.xyz.z = v10[2];
    this->refVert.st.x = v10[3];
    this->refVert.st.y = v10[4];
    this->refVert.normal[0] = *((_BYTE *)v10 + 20);
    this->refVert.normal[1] = *((_BYTE *)v10 + 21);
    this->refVert.normal[2] = *((_BYTE *)v10 + 22);
    this->refVert.normal[3] = *((_BYTE *)v10 + 23);
    this->refVert.tangent[0] = *((_BYTE *)v10 + 24);
    this->refVert.tangent[1] = *((_BYTE *)v10 + 25);
    this->refVert.tangent[2] = *((_BYTE *)v10 + 26);
    this->refVert.tangent[3] = *((_BYTE *)v10 + 27);
    this->refVert.color[0] = *((_BYTE *)v10 + 28);
    this->refVert.color[1] = *((_BYTE *)v10 + 29);
    this->refVert.color[2] = *((_BYTE *)v10 + 30);
    this->refVert.color[3] = *((_BYTE *)v10 + 31);
    z = this->refLeft.z;
    x = this->refDown.x;
    y = this->refDown.y;
    v36 = this->refDown.z;
    size = this->triangles.size;
    v38 = this->refLeft.x;
    v63.y = this->refLeft.y;
    v63.x = v38;
    v63.z = z;
    v62.x = x;
    v62.y = y;
    v62.z = v36;
    if ( v9 > size )
      idList<idTriangleInterpolator::Triangle_t,5>::Resize(this: &this->triangles, newsize: v9);
    idList<idTriangleInterpolator::Triangle_t,5>::SetNum(this: &this->triangles, newNum: 0);
    if ( numIndices > 0 )
    {
      v39 = v13 - 4;
      v40 = (numIndices - 1) / 3u + 1;
      do
      {
        v41 = v39[5];
        v42 = v39[4];
        v39 += 3;
        idTriangleInterpolator::AddTriangle(
          this,
          left: &v63,
          down: &v62,
          v0: (const idDrawVert *)((char *)verts + __ROL4__(*v39, 5)),
          v1: (const idDrawVert *)((char *)verts + __ROL4__(v42, 5)),
          v2: (const idDrawVert *)((char *)verts + __ROL4__(v41, 5)),
          orgST0: (const idVec2 *)((char *)st + __ROL4__(*v39, 3)),
          orgST1: (const idVec2 *)((char *)st + __ROL4__(v42, 3)),
          orgST2: v43,
          a10: v44,
          a11: v45,
          a12: v46,
          a13: v47,
          a14: v48,
          a15: v49,
          a16: v50,
          a17: v51,
          a18: v52,
          a19: v53,
          a20: v54,
          a21: v55,
          a22: v56,
          a23: v57,
          a24: v58,
          a25: v59,
          a26: v60,
          a27: v61,
          a28: (float *)((char *)&st->x + __ROL4__(v41, 3)));
        --v40;
      }
      while ( v40 != 0 );
    }
  }
}

