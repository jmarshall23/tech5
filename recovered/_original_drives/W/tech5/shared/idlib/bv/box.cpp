
// ========================================================================
// ?AddPoint@idBox@@QAA_NABVidVec3@@@Z
// EA  : 0x82EF8728
// RVA : 0x00EF8728
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

int __fastcall idBox::AddPoint(idBox *this, const idVec3 *v)
{
  idVec3 *p_extents; // r28
  double y; // fp30
  double v7; // fp27
  double v8; // fp26
  double v9; // fp22
  double z; // fp11
  double v11; // fp21
  idMat3 *p_axis; // r30
  double v13; // fp20
  double x; // fp31
  double v15; // fp25
  double v16; // fp24
  double v17; // fp23
  double v18; // fp29
  double v19; // fp28
  double v20; // fp19
  double v21; // fp2
  double v22; // fp3
  double v23; // fp0
  double v24; // fp1
  double v25; // fp10
  double v26; // fp8
  double v27; // fp9
  double v28; // fp5
  double v29; // fp10
  double v30; // fp11
  double v31; // fp10
  double v32; // fp9
  int v33; // r11
  float *p_x; // r11
  double v35; // fp9
  double v36; // fp3
  double v37; // fp1
  double v38; // fp31
  double v39; // fp30
  double v40; // fp29
  double v41; // fp28
  double v42; // fp27
  double v43; // fp26
  double v44; // fp25
  double v45; // fp24
  double v46; // fp23
  double Volume; // fp16
  double v60; // fp13
  double v61; // fp12
  double v62; // fp11
  double v63; // fp7
  double v64; // fp6
  double v65; // fp5
  double v66; // fp4
  double v67; // fp6
  double v68; // fp5
  double v69; // fp12
  double v70; // fp10
  double v71; // fp4
  double v72; // fp12
  double v73; // fp10
  idBounds v74; // [sp+50h] [-110h] BYREF
  idBounds v75; // [sp+70h] [-F0h] BYREF
  idMat3 v76[4]; // [sp+90h] [-D0h] BYREF

  p_extents = &this->extents;
  if ( this->extents.x < 0.0 )
  {
    this->extents.z = 0.0;
    this->extents.y = 0.0;
    p_extents->x = 0.0;
    this->center = *v;
    this->axis.mat[2].z = 1.0;
    this->axis.mat[1].y = 1.0;
    this->axis.mat[0].x = 1.0;
    this->axis.mat[1].z = 0.0;
    this->axis.mat[0].z = 0.0;
    this->axis.mat[0].y = 0.0;
    this->axis.mat[2].y = 0.0;
    this->axis.mat[2].x = 0.0;
    this->axis.mat[1].x = 0.0;
    return 1;
  }
  y = this->center.y;
  v7 = this->axis.mat[1].y;
  v8 = this->axis.mat[2].y;
  v9 = this->axis.mat[0].y;
  z = v->z;
  v11 = this->axis.mat[0].z;
  p_axis = &this->axis;
  v13 = this->axis.mat[1].z;
  x = this->center.x;
  v15 = this->axis.mat[1].x;
  v16 = this->axis.mat[2].x;
  v17 = this->axis.mat[0].x;
  v18 = this->center.z;
  v19 = v->x;
  v20 = this->axis.mat[2].z;
  v21 = this->extents.y;
  v22 = p_extents->x;
  v23 = this->extents.z;
  v24 = (float)((float)(v->x * this->axis.mat[2].x) + (float)(this->axis.mat[2].y * v->y));
  v25 = (float)((float)(this->axis.mat[1].z * this->center.z)
              + (float)((float)(this->axis.mat[1].x * this->center.x) + (float)(this->axis.mat[1].y * this->center.y)));
  v26 = (float)((float)(this->axis.mat[2].z * this->center.z)
              + (float)((float)(this->axis.mat[2].x * this->center.x) + (float)(this->axis.mat[2].y * this->center.y)));
  v27 = (float)((float)(this->axis.mat[0].z * this->center.z)
              + (float)((float)(this->axis.mat[0].x * this->center.x) + (float)(this->axis.mat[0].y * this->center.y)));
  v28 = (float)((float)(v->x * this->axis.mat[1].x)
              + (float)((float)(this->axis.mat[1].y * v->y) + (float)(this->axis.mat[1].z * v->z)));
  v74.b[0].x = (float)(v->x * this->axis.mat[0].x)
             + (float)((float)(this->axis.mat[0].y * v->y) + (float)(this->axis.mat[0].z * v->z));
  v74.b[0].y = v28;
  v74.b[0].z = (float)((float)v20 * (float)z) + (float)v24;
  v75.b[1].y = (float)v21 + (float)v25;
  v75.b[0].y = (float)v25 - (float)v21;
  v75.b[1].x = (float)v22 + (float)v27;
  v75.b[0].x = (float)v27 - (float)v22;
  v75.b[1].z = (float)v23 + (float)v26;
  v75.b[0].z = (float)v26 - (float)v23;
  if ( (unsigned __int8)idBounds::AddPointExpanded(this: &v75, v: v74.b) == 0 )
    return 0;
  v29 = (float)(v->z - (float)v18);
  v76[0].mat[0].y = v->y - (float)y;
  v76[0].mat[0].x = (float)v19 - (float)x;
  v76[0].mat[0].z = v29;
  idVec3::NormalizeFast(this: v76[0].mat);
  v30 = (float)((float)((float)v15 * v76[0].mat[0].x)
              + (float)((float)((float)v7 * v76[0].mat[0].y) + (float)((float)v13 * v76[0].mat[0].z)));
  v31 = (float)((float)((float)v17 * v76[0].mat[0].x)
              + (float)((float)((float)v9 * v76[0].mat[0].y) + (float)((float)v11 * v76[0].mat[0].z)));
  v32 = (float)((float)((float)v16 * v76[0].mat[0].x)
              + (float)((float)((float)v8 * v76[0].mat[0].y) + (float)((float)v20 * v76[0].mat[0].z)));
  if ( v31 >= v30 )
  {
    v33 = 1;
    if ( v30 < v32 )
      goto LABEL_10;
LABEL_9:
    v33 = 2;
    goto LABEL_10;
  }
  if ( v31 >= v32 )
    goto LABEL_9;
  v33 = 0;
LABEL_10:
  p_x = &this->axis.mat[v33].x;
  v35 = p_x[2];
  v36 = (float)(v76[0].mat[0].z
              * (float)((float)(*p_x * v76[0].mat[0].x)
                      + (float)((float)(p_x[2] * v76[0].mat[0].z) + (float)(p_x[1] * v76[0].mat[0].y))));
  v37 = (float)(p_x[1]
              - (float)(v76[0].mat[0].y
                      * (float)((float)(*p_x * v76[0].mat[0].x)
                              + (float)((float)(p_x[2] * v76[0].mat[0].z) + (float)(p_x[1] * v76[0].mat[0].y)))));
  v76[0].mat[1].x = *p_x
                  - (float)(v76[0].mat[0].x
                          * (float)((float)(*p_x * v76[0].mat[0].x)
                                  + (float)((float)(p_x[2] * v76[0].mat[0].z) + (float)(p_x[1] * v76[0].mat[0].y))));
  v76[0].mat[1].y = v37;
  v76[0].mat[1].z = (float)v35 - (float)v36;
  idVec3::NormalizeFast(this: &v76[0].mat[1]);
  v76[0].mat[2].x = (float)(v76[0].mat[1].z * v76[0].mat[0].y) - (float)(v76[0].mat[0].z * v76[0].mat[1].y);
  v76[0].mat[2].y = (float)(v76[0].mat[0].z * v76[0].mat[1].x) - (float)(v76[0].mat[1].z * v76[0].mat[0].x);
  v76[0].mat[2].z = (float)(v76[0].mat[1].y * v76[0].mat[0].x) - (float)(v76[0].mat[0].y * v76[0].mat[1].x);
  idBox::AxisProjection(this, ax: v76, bounds: &v74);
  v38 = v76[0].mat[0].y;
  v39 = v76[0].mat[1].y;
  v40 = v76[0].mat[2].y;
  v41 = v76[0].mat[0].x;
  v42 = v76[0].mat[1].x;
  v43 = v76[0].mat[2].x;
  v44 = v76[0].mat[0].z;
  v45 = v76[0].mat[1].z;
  v46 = v76[0].mat[2].z;
  _FP6 = (float)(v74.b[0].x
               - (float)((float)(v76[0].mat[0].z * v->z)
                       + (float)((float)(v->x * v76[0].mat[0].x) + (float)(v76[0].mat[0].y * v->y))));
  _FP5 = (float)(v74.b[0].y
               - (float)((float)(v76[0].mat[1].z * v->z)
                       + (float)((float)(v->x * v76[0].mat[1].x) + (float)(v76[0].mat[1].y * v->y))));
  _FP4 = (float)(v74.b[0].z
               - (float)((float)(v76[0].mat[2].z * v->z)
                       + (float)((float)(v->x * v76[0].mat[2].x) + (float)(v76[0].mat[2].y * v->y))));
  _FP3 = (float)((float)((float)(v76[0].mat[0].z * v->z)
                       + (float)((float)(v->x * v76[0].mat[0].x) + (float)(v76[0].mat[0].y * v->y)))
               - v74.b[1].x);
  _FP2 = (float)((float)((float)(v76[0].mat[1].z * v->z)
                       + (float)((float)(v->x * v76[0].mat[1].x) + (float)(v76[0].mat[1].y * v->y)))
               - v74.b[1].y);
  _FP20 = (float)((float)((float)(v76[0].mat[2].z * v->z)
                        + (float)((float)(v->x * v76[0].mat[2].x) + (float)(v76[0].mat[2].y * v->y)))
                - v74.b[1].z);
  __asm { fsel      f19, f6, f1, f0 }
  v74.b[0].x = _FP19;
  __asm { fsel      f18, f5, f8, f13 }
  v74.b[0].y = _FP18;
  __asm { fsel      f17, f4, f7, f12 }
  v74.b[0].z = _FP17;
  __asm { fsel      f22, f3, f1, f11 }
  v74.b[1].x = _FP22;
  __asm { fsel      f21, f2, f8, f10 }
  v74.b[1].y = _FP21;
  __asm { fsel      f20, f20, f7, f9 }
  v74.b[1].z = _FP20;
  Volume = idBounds::GetVolume(this: &v75);
  if ( Volume >= idBounds::GetVolume(this: &v74) )
  {
    this->center.x = (float)((float)_FP22 + (float)_FP19) * 0.5;
    this->center.y = (float)((float)_FP21 + (float)_FP18) * (float)0.5;
    this->center.z = (float)((float)_FP20 + (float)_FP17) * (float)0.5;
    p_extents->x = (float)_FP22 - (float)((float)((float)_FP22 + (float)_FP19) * 0.5);
    p_extents->y = (float)_FP21 - (float)((float)((float)_FP21 + (float)_FP18) * (float)0.5);
    p_extents->z = (float)_FP20 - (float)((float)((float)_FP20 + (float)_FP17) * (float)0.5);
    v71 = this->center.z;
    v72 = (float)((float)((float)v38 * this->center.x) + (float)((float)v39 * this->center.y));
    v73 = (float)((float)((float)v44 * this->center.x) + (float)((float)v45 * this->center.y));
    this->center.x = (float)((float)v41 * this->center.x)
                   + (float)((float)((float)v42 * this->center.y) + (float)((float)v43 * this->center.z));
    this->center.y = (float)((float)v40 * (float)v71) + (float)v72;
    this->center.z = (float)((float)v46 * (float)v71) + (float)v73;
    p_axis->mat[0].x = v41;
    this->axis.mat[1].x = v42;
    this->axis.mat[0].y = v38;
    this->axis.mat[0].z = v44;
    this->axis.mat[1].y = v39;
    this->axis.mat[1].z = v45;
    this->axis.mat[2].x = v43;
    this->axis.mat[2].y = v40;
    this->axis.mat[2].z = v46;
  }
  else
  {
    v60 = v75.b[1].x;
    v61 = v75.b[1].y;
    v62 = v75.b[1].z;
    v63 = (float)(v75.b[0].y + v75.b[1].y);
    v64 = (float)(v75.b[0].z + v75.b[1].z);
    v65 = (float)((float)(v75.b[0].x + v75.b[1].x) * 0.5);
    this->center.x = (float)(v75.b[0].x + v75.b[1].x) * 0.5;
    this->center.y = (float)v63 * (float)0.5;
    this->center.z = (float)v64 * (float)0.5;
    p_extents->x = (float)v60 - (float)v65;
    p_extents->y = (float)v61 - (float)((float)v63 * (float)0.5);
    p_extents->z = (float)v62 - (float)((float)v64 * (float)0.5);
    v66 = this->center.x;
    v67 = this->axis.mat[0].y;
    v68 = this->axis.mat[0].z;
    v69 = (float)((float)(this->axis.mat[1].y * this->center.y) + (float)(this->axis.mat[2].y * this->center.z));
    v70 = (float)((float)(this->axis.mat[1].z * this->center.y) + (float)(this->axis.mat[2].z * this->center.z));
    this->center.x = (float)(this->axis.mat[0].x * this->center.x)
                   + (float)((float)(this->axis.mat[1].x * this->center.y)
                           + (float)(this->axis.mat[2].x * this->center.z));
    this->center.y = (float)((float)v67 * (float)v66) + (float)v69;
    this->center.z = (float)((float)v68 * (float)v66) + (float)v70;
  }
  return 1;
}


// ========================================================================
// ?IntersectsBox@idBox@@QBA_NABV1@@Z
// EA  : 0x82EF8C38
// RVA : 0x00EF8C38
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

BOOL __fastcall idBox::IntersectsBox(idBox *this, const idBox *a)
{
  double v2; // fp19
  double v4; // fp21
  double v5; // fp25
  double v6; // fp18
  double v7; // fp24
  double v8; // fp26
  double v9; // fp23
  double v10; // fp7
  double v11; // fp13
  float v12; // [sp+0h] [-C0h]
  float v13; // [sp+4h] [-BCh]
  float v14; // [sp+8h] [-B8h]
  float v15; // [sp+Ch] [-B4h]
  float v16; // [sp+10h] [-B0h]
  float v17; // [sp+14h] [-ACh]
  float v18; // [sp+20h] [-A0h]

  v13 = (float)(a->axis.mat[1].z * this->axis.mat[0].z)
      + (float)((float)(a->axis.mat[1].x * this->axis.mat[0].x) + (float)(a->axis.mat[1].y * this->axis.mat[0].y));
  v12 = (float)(this->axis.mat[0].z * a->axis.mat[0].z)
      + (float)((float)(this->axis.mat[0].x * a->axis.mat[0].x) + (float)(this->axis.mat[0].y * a->axis.mat[0].y));
  v2 = __fabs(v12);
  v14 = (float)(a->axis.mat[2].z * this->axis.mat[0].z)
      + (float)((float)(a->axis.mat[2].x * this->axis.mat[0].x) + (float)(a->axis.mat[2].y * this->axis.mat[0].y));
  if ( __fabs((float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                    + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                            + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z))))) > (float)((float)((float)(a->extents.z * (float)__fabs(v14)) + (float)((float)(a->extents.x * (float)v2) + (float)(a->extents.y * (float)__fabs(v13)))) + this->extents.x) )
    return false;
  v16 = (float)(this->axis.mat[1].z * a->axis.mat[1].z)
      + (float)((float)(this->axis.mat[1].x * a->axis.mat[1].x) + (float)(this->axis.mat[1].y * a->axis.mat[1].y));
  v15 = (float)(this->axis.mat[1].z * a->axis.mat[0].z)
      + (float)((float)(this->axis.mat[1].x * a->axis.mat[0].x) + (float)(this->axis.mat[1].y * a->axis.mat[0].y));
  v17 = (float)(this->axis.mat[1].z * a->axis.mat[2].z)
      + (float)((float)(this->axis.mat[1].x * a->axis.mat[2].x) + (float)(this->axis.mat[1].y * a->axis.mat[2].y));
  v4 = __fabs(v16);
  v5 = __fabs(v15);
  v6 = __fabs(v17);
  if ( __fabs((float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                    + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                            + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))) > (float)((float)((float)(a->extents.z * (float)v6) + (float)((float)(a->extents.x * (float)v5) + (float)(a->extents.y * (float)v4))) + this->extents.y) )
    return false;
  v7 = __fabs((float)((float)(this->axis.mat[2].z * a->axis.mat[1].z)
                    + (float)((float)(a->axis.mat[1].x * this->axis.mat[2].x)
                            + (float)(a->axis.mat[1].y * this->axis.mat[2].y))));
  v8 = __fabs((float)((float)(this->axis.mat[2].z * a->axis.mat[2].z)
                    + (float)((float)(a->axis.mat[2].x * this->axis.mat[2].x)
                            + (float)(a->axis.mat[2].y * this->axis.mat[2].y))));
  v9 = __fabs((float)((float)(this->axis.mat[2].z * a->axis.mat[0].z)
                    + (float)((float)(a->axis.mat[0].x * this->axis.mat[2].x)
                            + (float)(a->axis.mat[0].y * this->axis.mat[2].y))));
  v18 = (float)(this->axis.mat[2].z * a->axis.mat[2].z)
      + (float)((float)(a->axis.mat[2].x * this->axis.mat[2].x) + (float)(a->axis.mat[2].y * this->axis.mat[2].y));
  if ( __fabs((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                    + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                            + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))) > (float)((float)((float)(a->extents.z * (float)v8) + (float)((float)(a->extents.x * (float)v9) + (float)(a->extents.y * (float)v7))) + this->extents.z) )
    return false;
  if ( __fabs((float)((float)(a->axis.mat[0].x * (float)(a->center.x - this->center.x))
                    + (float)((float)(a->axis.mat[0].y * (float)(a->center.y - this->center.y))
                            + (float)(a->axis.mat[0].z * (float)(a->center.z - this->center.z))))) > (float)((float)((float)(this->extents.x * (float)v2) + (float)((float)(this->extents.z * (float)v9) + (float)(this->extents.y * (float)v5))) + a->extents.x) )
    return false;
  v10 = __fabs(v13);
  if ( __fabs((float)((float)(a->axis.mat[1].x * (float)(a->center.x - this->center.x))
                    + (float)((float)(a->axis.mat[1].y * (float)(a->center.y - this->center.y))
                            + (float)(a->axis.mat[1].z * (float)(a->center.z - this->center.z))))) > (float)((float)((float)(this->extents.x * (float)v10) + (float)((float)(this->extents.z * (float)v7) + (float)(this->extents.y * (float)v4))) + a->extents.y) )
    return false;
  v11 = __fabs(v14);
  return __fabs((float)((float)(a->axis.mat[2].x * (float)(a->center.x - this->center.x))
                      + (float)((float)(a->axis.mat[2].y * (float)(a->center.y - this->center.y))
                              + (float)(a->axis.mat[2].z * (float)(a->center.z - this->center.z))))) <= (float)((float)((float)(this->extents.x * (float)v11) + (float)((float)(this->extents.z * (float)v8) + (float)(this->extents.y * (float)v6))) + a->extents.z)
      && __fabs((float)((float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v15)
                      - (float)((float)((float)(this->axis.mat[2].z * a->axis.mat[0].z)
                                      + (float)((float)(a->axis.mat[0].x * this->axis.mat[2].x)
                                              + (float)(a->axis.mat[0].y * this->axis.mat[2].y)))
                              * (float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(a->extents.y * (float)v11) + (float)(a->extents.z * (float)v10)) + (float)((float)(this->extents.z * (float)v5) + (float)(this->extents.y * (float)v9)))
      && __fabs((float)((float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v16)
                      - (float)((float)((float)(this->axis.mat[2].z * a->axis.mat[1].z)
                                      + (float)((float)(a->axis.mat[1].x * this->axis.mat[2].x)
                                              + (float)(a->axis.mat[1].y * this->axis.mat[2].y)))
                              * (float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(a->extents.x * (float)v11) + (float)(a->extents.z * (float)v2)) + (float)((float)(this->extents.z * (float)v4) + (float)(this->extents.y * (float)v7)))
      && __fabs((float)((float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v17)
                      - (float)(v18
                              * (float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(a->extents.x * (float)v10) + (float)(a->extents.y * (float)v2)) + (float)((float)(this->extents.z * (float)v6) + (float)(this->extents.y * (float)v8)))
      && __fabs((float)((float)((float)((float)(this->axis.mat[2].z * a->axis.mat[0].z)
                                      + (float)((float)(a->axis.mat[0].x * this->axis.mat[2].x)
                                              + (float)(a->axis.mat[0].y * this->axis.mat[2].y)))
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z)))))
                      - (float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v12))) <= (float)((float)((float)(a->extents.y * (float)v6)
                                                        + (float)(a->extents.z * (float)v4))
                                                + (float)((float)(this->extents.z * (float)v2)
                                                        + (float)(this->extents.x * (float)v9)))
      && __fabs((float)((float)((float)((float)(this->axis.mat[2].z * a->axis.mat[1].z)
                                      + (float)((float)(a->axis.mat[1].x * this->axis.mat[2].x)
                                              + (float)(a->axis.mat[1].y * this->axis.mat[2].y)))
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z)))))
                      - (float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v13))) <= (float)((float)((float)(a->extents.x * (float)v6)
                                                        + (float)(a->extents.z * (float)v5))
                                                + (float)((float)(this->extents.z * (float)v10)
                                                        + (float)(this->extents.x * (float)v7)))
      && __fabs((float)((float)(v18
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z)))))
                      - (float)((float)((float)((float)(a->center.x - this->center.x) * this->axis.mat[2].x)
                                      + (float)((float)(this->axis.mat[2].z * (float)(a->center.z - this->center.z))
                                              + (float)((float)(a->center.y - this->center.y) * this->axis.mat[2].y)))
                              * v14))) <= (float)((float)((float)(a->extents.x * (float)v4)
                                                        + (float)(a->extents.y * (float)v5))
                                                + (float)((float)(this->extents.z * (float)v11)
                                                        + (float)(this->extents.x * (float)v8)))
      && __fabs((float)((float)((float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))
                              * v12)
                      - (float)(v15
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(this->extents.y * (float)v2) + (float)(this->extents.x * (float)v5)) + (float)((float)(a->extents.y * (float)v8) + (float)(a->extents.z * (float)v7)))
      && __fabs((float)((float)((float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))
                              * v13)
                      - (float)(v16
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(this->extents.y * (float)v10) + (float)(this->extents.x * (float)v4)) + (float)((float)(a->extents.x * (float)v8) + (float)(a->extents.z * (float)v9)))
      && __fabs((float)((float)((float)((float)(this->axis.mat[1].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[1].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[1].z * (float)(a->center.z - this->center.z))))
                              * v14)
                      - (float)(v17
                              * (float)((float)(this->axis.mat[0].x * (float)(a->center.x - this->center.x))
                                      + (float)((float)(this->axis.mat[0].y * (float)(a->center.y - this->center.y))
                                              + (float)(this->axis.mat[0].z * (float)(a->center.z - this->center.z))))))) <= (float)((float)((float)(this->extents.y * (float)v11) + (float)(this->extents.x * (float)v6)) + (float)((float)(a->extents.x * (float)v7) + (float)(a->extents.y * (float)v9)));
}


// ========================================================================
// ?LineIntersection@idBox@@QBA_NABVidVec3@@0@Z
// EA  : 0x82EF9028
// RVA : 0x00EF9028
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

BOOL __fastcall idBox::LineIntersection(idBox *this, const idVec3 *start, const idVec3 *end)
{
  double v3; // fp25
  double v5; // fp2
  double v6; // fp7
  double v7; // fp0
  double v8; // fp12

  v3 = __fabs((float)((float)(this->axis.mat[0].z * (float)((float)(end->z - start->z) * (float)0.5))
                    + (float)((float)(this->axis.mat[0].x * (float)((float)(end->x - start->x) * (float)0.5))
                            + (float)(this->axis.mat[0].y * (float)((float)(end->y - start->y) * (float)0.5)))));
  if ( __fabs((float)((float)(this->axis.mat[0].x
                            * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                    - this->center.x))
                    + (float)((float)(this->axis.mat[0].y
                                    * (float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                            - this->center.y))
                            + (float)(this->axis.mat[0].z
                                    * (float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                            - this->center.z))))) > (float)(this->extents.x + (float)v3) )
    return false;
  v5 = __fabs((float)((float)(this->axis.mat[1].z * (float)((float)(end->z - start->z) * (float)0.5))
                    + (float)((float)(this->axis.mat[1].x * (float)((float)(end->x - start->x) * (float)0.5))
                            + (float)(this->axis.mat[1].y * (float)((float)(end->y - start->y) * (float)0.5)))));
  if ( __fabs((float)((float)(this->axis.mat[1].x
                            * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                    - this->center.x))
                    + (float)((float)(this->axis.mat[1].y
                                    * (float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                            - this->center.y))
                            + (float)(this->axis.mat[1].z
                                    * (float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                            - this->center.z))))) > (float)(this->extents.y + (float)v5) )
    return false;
  v6 = __fabs((float)((float)(this->axis.mat[2].z * (float)((float)(end->z - start->z) * (float)0.5))
                    + (float)((float)(this->axis.mat[2].x * (float)((float)(end->x - start->x) * (float)0.5))
                            + (float)(this->axis.mat[2].y * (float)((float)(end->y - start->y) * (float)0.5)))));
  if ( __fabs((float)((float)(this->axis.mat[2].x
                            * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                    - this->center.x))
                    + (float)((float)(this->axis.mat[2].y
                                    * (float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                            - this->center.y))
                            + (float)(this->axis.mat[2].z
                                    * (float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                            - this->center.z))))) > (float)(this->extents.z + (float)v6) )
    return false;
  v7 = (float)((float)((float)((float)(end->z - start->z) * (float)0.5)
                     * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5)) - this->center.x))
             - (float)((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5)) - this->center.z)
                     * (float)((float)(end->x - start->x) * (float)0.5)));
  if ( __fabs((float)((float)(this->axis.mat[0].x
                            * (float)((float)((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                                    - this->center.z)
                                            * (float)((float)(end->y - start->y) * (float)0.5))
                                    - (float)((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                                    - this->center.y)
                                            * (float)((float)(end->z - start->z) * (float)0.5))))
                    + (float)((float)(this->axis.mat[0].y * (float)v7)
                            + (float)(this->axis.mat[0].z
                                    * (float)((float)((float)((float)(start->y
                                                                    + (float)((float)(end->y - start->y) * (float)0.5))
                                                            - this->center.y)
                                                    * (float)((float)(end->x - start->x) * (float)0.5))
                                            - (float)((float)((float)(end->y - start->y) * (float)0.5)
                                                    * (float)((float)(start->x
                                                                    + (float)((float)(end->x - start->x) * (float)0.5))
                                                            - this->center.x))))))) > (float)((float)(this->extents.z * (float)v5)
                                                                                            + (float)(this->extents.y * (float)v6))
    || __fabs((float)((float)(this->axis.mat[1].x
                            * (float)((float)((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                                    - this->center.z)
                                            * (float)((float)(end->y - start->y) * (float)0.5))
                                    - (float)((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                                    - this->center.y)
                                            * (float)((float)(end->z - start->z) * (float)0.5))))
                    + (float)((float)(this->axis.mat[1].y * (float)v7)
                            + (float)(this->axis.mat[1].z
                                    * (float)((float)((float)((float)(start->y
                                                                    + (float)((float)(end->y - start->y) * (float)0.5))
                                                            - this->center.y)
                                                    * (float)((float)(end->x - start->x) * (float)0.5))
                                            - (float)((float)((float)(end->y - start->y) * (float)0.5)
                                                    * (float)((float)(start->x
                                                                    + (float)((float)(end->x - start->x) * (float)0.5))
                                                            - this->center.x))))))) > (float)((float)(this->extents.z * (float)v3)
                                                                                            + (float)(this->extents.x * (float)v6)) )
  {
    return false;
  }
  v8 = (float)(this->axis.mat[2].z
             * (float)((float)((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                     - this->center.y)
                             * (float)((float)(end->x - start->x) * (float)0.5))
                     - (float)((float)((float)(end->y - start->y) * (float)0.5)
                             * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                     - this->center.x))));
  return __fabs((float)((float)(this->axis.mat[2].x
                              * (float)((float)((float)((float)(start->z
                                                              + (float)((float)(end->z - start->z) * (float)0.5))
                                                      - this->center.z)
                                              * (float)((float)(end->y - start->y) * (float)0.5))
                                      - (float)((float)((float)(start->y
                                                              + (float)((float)(end->y - start->y) * (float)0.5))
                                                      - this->center.y)
                                              * (float)((float)(end->z - start->z) * (float)0.5))))
                      + (float)((float)(this->axis.mat[2].y
                                      * (float)((float)((float)((float)(end->z - start->z) * (float)0.5)
                                                      * (float)((float)(start->x
                                                                      + (float)((float)(end->x - start->x) * (float)0.5))
                                                              - this->center.x))
                                              - (float)((float)((float)(start->z
                                                                      + (float)((float)(end->z - start->z) * (float)0.5))
                                                              - this->center.z)
                                                      * (float)((float)(end->x - start->x) * (float)0.5))))
                              + (float)v8))) <= (float)((float)(this->extents.y * (float)v3)
                                                      + (float)(this->extents.x * (float)v5));
}


// ========================================================================
// ?FromPoints@idBox@@QAAXPBVidVec3@@H@Z
// EA  : 0x82EF9200
// RVA : 0x00EF9200
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

void __fastcall idBox::FromPoints(idBox *this, const idVec3 *points, int numPoints)
{
  __int64 v6; // r11
  double v7; // fp12
  double v8; // fp9
  double v9; // fp5
  double v10; // fp1
  double v11; // fp13
  double v12; // fp10
  double v13; // fp6
  double v14; // fp4
  double v15; // fp1
  int v16; // ctr
  float *p_z; // r11
  double y; // fp11
  double z; // fp10
  double x; // fp13
  double v21; // fp12
  double v22; // fp11
  int v23; // r10
  double v24; // fp28
  double v25; // fp2
  double v26; // fp10
  double v27; // fp3
  double v28; // fp8
  double v29; // fp4
  double v30; // fp9
  double v31; // fp5
  double v32; // fp30
  double v33; // fp6
  double v34; // fp31
  double v35; // fp7
  double v36; // fp1
  double v37; // fp24
  double v38; // fp23
  double v39; // fp22
  double v40; // fp26
  double v41; // fp25
  double v42; // fp27
  double v43; // fp0
  double v44; // fp13
  double v45; // fp12
  double v46; // fp11
  const idVec3 *v47; // r11
  double v48; // fp20
  double v49; // fp18
  double v50; // fp21
  double v51; // fp19
  double v52; // fp17
  const idVec3 *v53; // r11
  double v54; // fp12
  double v55; // fp11
  double v56; // fp12
  double v57; // fp1
  double v58; // fp31
  double v59; // fp30
  double v60; // fp29
  double v61; // fp27
  double v62; // fp26
  double v63; // fp25
  float *mat; // r9
  int numColumns; // r11
  float *p; // r4
  int v67; // r7
  float *v68; // r10
  idVec3 *v69; // r28
  int v70; // r3
  double v71; // fp11
  idVec3 *v72; // r27
  double v73; // fp10
  idMat3 *p_axis; // r29
  double v75; // fp2
  double v76; // fp1
  int v77; // r11
  __int64 v82; // r11
  double v85; // fp8
  double v86; // fp7
  double v87; // fp6
  double v88; // fp5
  double v89; // fp4
  double v90; // fp3
  double v91; // fp1
  double v92; // fp2
  double v93; // fp31
  double v94; // fp30
  double v95; // fp27
  double v96; // fp26
  double v97; // fp25
  double v98; // fp24
  double v99; // fp23
  double v100; // fp18
  double v101; // fp20
  double v102; // fp22
  double v103; // fp21
  double v104; // fp17
  double v105; // fp19
  double v106; // fp16
  double v107; // fp29
  double v108; // fp28
  double v109; // fp2
  double v110; // fp30
  double v111; // fp26
  double v112; // fp29
  double v113; // fp31
  double v114; // fp30
  double v115; // fp28
  double v116; // fp23
  double v117; // fp24
  double v118; // fp27
  double v119; // fp25
  double v124; // fp14
  double v127; // fp24
  double v162; // fp26
  int v165; // ctr
  const idVec3 *v166; // r11
  double v167; // fp29
  double v168; // fp27
  double v169; // fp26
  double v170; // fp24
  double v171; // fp8
  double v172; // fp29
  double v173; // fp27
  int v180; // r21
  double v181; // fp29
  int v182; // r24
  const idMat3 *v183; // r3
  double v188; // fp2
  double v191; // fp31
  double v192; // fp30
  double v193; // fp29
  double v194; // fp14
  double v195; // fp30
  double v196; // fp24
  double v237; // fp1
  int v240; // ctr
  const idVec3 *v241; // r11
  double v242; // fp27
  double v243; // fp26
  double v244; // fp25
  double v245; // fp24
  double v246; // fp1
  double v247; // fp27
  double v248; // fp26
  double v249; // fp1
  double v256; // fp0
  const idMat3 *v257; // r3
  int v259; // r10
  double v265; // fp8
  const idVec3 *v266; // r11
  double v267; // fp7
  double v268; // fp6
  double v269; // fp5
  double v270; // fp4
  double v271; // fp3
  double v272; // fp1
  double v273; // fp2
  double v274; // fp24
  double v275; // fp19
  double v276; // fp16
  double v277; // fp26
  double v278; // fp23
  double v279; // fp29
  double v280; // fp30
  double v281; // fp31
  double v282; // fp28
  double v283; // fp20
  double v284; // fp25
  double v285; // fp27
  double v286; // fp21
  double v287; // fp24
  double v293; // fp21
  double v294; // fp24
  double v329; // fp26
  int v333; // ctr
  const idVec3 *v334; // r11
  double v335; // fp28
  double v336; // fp27
  double v337; // fp26
  double v338; // fp29
  double v339; // fp27
  double v340; // fp28
  double v347; // fp11
  double v348; // fp5
  double v349; // fp4
  double v350; // fp7
  double v351; // fp5
  double v352; // fp10
  double v353; // fp9
  float v354[36]; // [sp+50h] [-2C0h] BYREF
  float v355[28]; // [sp+E0h] [-230h] BYREF
  float v356; // [sp+150h] [-1C0h]
  float v357; // [sp+154h] [-1BCh]
  idMatX v358; // [sp+160h] [-1B0h] BYREF
  float angle; // [sp+170h] [-1A0h]
  __int64 v360; // [sp+178h] [-198h]
  idVecX v361; // [sp+180h] [-190h] BYREF
  float v362; // [sp+18Ch] [-184h]
  float v363; // [sp+190h] [-180h]
  idMat3 v364; // [sp+1A0h] [-170h] BYREF
  __int64 v365; // [sp+1C8h] [-148h]
  idRotation v366[3]; // [sp+1D0h] [-140h] BYREF

  if ( numPoints <= 0 )
  {
    this->center.z = 0.0;
    this->center.y = 0.0;
    this->center.x = 0.0;
    this->extents.z = 0.0;
    this->extents.y = 0.0;
    this->extents.x = 0.0;
    this->axis.mat[2].z = 1.0;
    this->axis.mat[1].y = 1.0;
    this->axis.mat[0].x = 1.0;
    this->axis.mat[1].z = 0.0;
    this->axis.mat[0].z = 0.0;
    this->axis.mat[0].y = 0.0;
    this->axis.mat[2].y = 0.0;
    this->axis.mat[2].x = 0.0;
    this->axis.mat[1].x = 0.0;
    return;
  }
  HIDWORD(v6) = 1;
  this->center = *points;
  if ( numPoints > 1 )
  {
    if ( numPoints - 1 >= 4 )
    {
      LODWORD(v6) = &points->z;
      do
      {
        HIDWORD(v6) += 4;
        v7 = (float)(*(float *)(v6 + 4) + this->center.x);
        this->center.x = *(float *)(v6 + 4) + this->center.x;
        v8 = (float)(*(float *)(v6 + 8) + this->center.y);
        this->center.y = *(float *)(v6 + 8) + this->center.y;
        v9 = (float)(*(float *)(v6 + 12) + this->center.z);
        this->center.z = *(float *)(v6 + 12) + this->center.z;
        v10 = (float)(*(float *)(v6 + 16) + (float)v7);
        this->center.x = *(float *)(v6 + 16) + (float)v7;
        v11 = (float)(*(float *)(v6 + 20) + (float)v8);
        this->center.y = *(float *)(v6 + 20) + (float)v8;
        v12 = (float)(*(float *)(v6 + 24) + (float)v9);
        this->center.z = *(float *)(v6 + 24) + (float)v9;
        v13 = (float)(*(float *)(v6 + 28) + (float)v10);
        this->center.x = *(float *)(v6 + 28) + (float)v10;
        v14 = (float)(*(float *)(v6 + 32) + (float)v11);
        this->center.y = *(float *)(v6 + 32) + (float)v11;
        v15 = (float)(*(float *)(v6 + 36) + (float)v12);
        this->center.z = *(float *)(v6 + 36) + (float)v12;
        this->center.x = *(float *)(v6 + 40) + (float)v13;
        this->center.y = *(float *)(v6 + 44) + (float)v14;
        LODWORD(v6) = v6 + 48;
        this->center.z = *(float *)v6 + (float)v15;
      }
      while ( SHIDWORD(v6) < numPoints - 3 );
    }
    if ( SHIDWORD(v6) < numPoints )
    {
      v16 = numPoints - HIDWORD(v6);
      p_z = &points[HIDWORD(v6) - 1].z;
      do
      {
        y = this->center.y;
        this->center.x = p_z[1] + this->center.x;
        z = this->center.z;
        this->center.y = p_z[2] + (float)y;
        p_z += 3;
        this->center.z = *p_z + (float)z;
        --v16;
      }
      while ( v16 != 0 );
    }
  }
  LODWORD(v6) = numPoints;
  x = this->center.x;
  v21 = this->center.y;
  v360 = v6;
  v22 = this->center.z;
  v24 = 0.0;
  v363 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  v33 = 0.0;
  v34 = 0.0;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  v39 = 0.0;
  v40 = 0.0;
  v41 = 0.0;
  v42 = 0.0;
  v43 = (float)((float)1.0 / (float)v6);
  v44 = (float)((float)x * (float)((float)1.0 / (float)v6));
  this->center.x = v44;
  v45 = (float)((float)v21 * (float)((float)1.0 / (float)v6));
  this->center.y = v45;
  v46 = (float)((float)v22 * (float)((float)1.0 / (float)v6));
  v23 = 0;
  this->center.z = v46;
  if ( numPoints >= 2 )
  {
    v47 = points - 1;
    do
    {
      v23 += 2;
      v48 = (float)(v47[1].x - (float)v44);
      v49 = (float)(v47[1].z - (float)v46);
      v50 = (float)(v47[1].y - (float)v45);
      v51 = (float)(v47[2].z - (float)v46);
      v52 = (float)(v47[2].y - (float)v45);
      v35 = (float)((float)((float)v48 * (float)v48) + (float)v35);
      v31 = (float)((float)((float)(v47[1].z - (float)v46) * (float)(v47[1].x - (float)v44)) + (float)v31);
      v33 = (float)((float)((float)(v47[1].y - (float)v45) * (float)(v47[1].x - (float)v44)) + (float)v33);
      v26 = (float)((float)((float)v51 * (float)v51) + (float)v26);
      v30 = (float)((float)((float)v52 * (float)v52) + (float)v30);
      v28 = (float)((float)((float)(v47[2].y - (float)v45) * (float)(v47[2].z - (float)v46)) + (float)v28);
      v29 = (float)((float)((float)v50 * (float)v50) + (float)v29);
      v27 = (float)((float)((float)(v47[1].z - (float)v46) * (float)(v47[1].y - (float)v45)) + (float)v27);
      v47 += 2;
      v25 = (float)((float)((float)v49 * (float)v49) + (float)v25);
      v36 = (float)((float)((float)(v47->x - (float)v44) * (float)(v47->x - (float)v44)) + (float)v36);
      v34 = (float)((float)((float)v52 * (float)(v47->x - (float)v44)) + (float)v34);
      v32 = (float)((float)((float)v51 * (float)(v47->x - (float)v44)) + (float)v32);
    }
    while ( v23 < numPoints - 1 );
  }
  if ( v23 < numPoints )
  {
    v53 = &points[v23];
    v54 = (float)(v53->z - this->center.z);
    v55 = (float)(v53->y - this->center.y);
    v37 = (float)((float)(v53->x - this->center.x) * (float)(v53->x - this->center.x));
    v42 = (float)((float)v54 * (float)v54);
    v40 = (float)((float)v55 * (float)v55);
    v41 = (float)((float)(v53->y - this->center.y) * (float)(v53->z - this->center.z));
    v38 = (float)((float)(v53->y - this->center.y) * (float)(v53->x - this->center.x));
    v39 = (float)((float)(v53->z - this->center.z) * (float)(v53->x - this->center.x));
  }
  v56 = (float)((float)v33 + (float)v34);
  memset(&v358, 0, sizeof(v358));
  v58 = (float)((float)((float)((float)v35 + (float)v36) + (float)v37) * (float)v43);
  v57 = (float)((float)((float)v25 + (float)v26) + (float)v42);
  v60 = (float)((float)((float)((float)v31 + (float)v32) + (float)v39) * (float)v43);
  v59 = (float)((float)((float)v56 + (float)v38) * (float)v43);
  v61 = (float)((float)((float)((float)v29 + (float)v30) + (float)v40) * (float)v43);
  v62 = (float)((float)((float)((float)v27 + (float)v28) + (float)v41) * (float)v43);
  v63 = (float)((float)v57 * (float)v43);
  memset(&v361, 0, sizeof(v361));
  v354[16] = v355[8];
  idVecX::SetData(this: &v361, length: 3, data: v355);
  idMatX::SetData(this: &v358, rows: 3, columns: 3, data: v354);
  *v358.mat = v58;
  v358.mat[1] = v59;
  v358.mat[2] = v60;
  v358.mat[v358.numColumns] = v59;
  v358.mat[v358.numColumns + 1] = v61;
  v358.mat[v358.numColumns + 2] = v62;
  v358.mat[2 * v358.numColumns] = v60;
  v358.mat[2 * v358.numColumns + 1] = v62;
  v358.mat[2 * v358.numColumns + 2] = v63;
  idMatX::Eigen_SolveSymmetric(this: &v358, eigenValues: &v361);
  idMatX::Eigen_SortIncreasing(this: &v358, eigenValues: &v361);
  mat = v358.mat;
  numColumns = v358.numColumns;
  p = v361.p;
  v67 = v358.numColumns + 1;
  this->axis.mat[1].x = v358.mat[1];
  v68 = &mat[2 * numColumns];
  v69 = &this->axis.mat[1];
  v70 = numColumns + 2;
  v362 = 0.5;
  v71 = mat[v67];
  this->axis.mat[1].y = mat[v67];
  v72 = &this->axis.mat[2];
  v73 = v68[1];
  this->axis.mat[1].z = v68[1];
  p_axis = &this->axis;
  this->axis.mat[2].x = mat[2];
  v75 = (float)(mat[v70] * (float)v73);
  this->axis.mat[2].y = mat[v70];
  v76 = (float)((float)((float)v71 * v68[2]) - (float)v75);
  this->axis.mat[2].z = v68[2];
  this->axis.mat[0].x = v76;
  this->axis.mat[0].y = (float)(this->axis.mat[1].z * this->axis.mat[2].x)
                      - (float)(this->axis.mat[2].z * this->axis.mat[1].x);
  this->axis.mat[0].z = (float)(this->axis.mat[2].y * this->axis.mat[1].x)
                      - (float)(this->axis.mat[1].y * this->axis.mat[2].x);
  if ( __fabs((float)(*p - p[1])) < 0.1 )
  {
    v77 = 2;
LABEL_21:
    _FP0 = 1.0e30;
    _FP12 = -1.0e30;
    _FP13 = 1.0e30;
    _FP10 = 1.0e30;
    v82 = (unsigned int)&this->axis.mat[v77];
    _FP11 = -1.0e30;
    v366[0].vec = *(idVec3 *)v82;
    _FP9 = -1.0e30;
    if ( numPoints >= 4 )
    {
      v85 = this->axis.mat[2].z;
      LODWORD(v82) = points - 1;
      v86 = this->axis.mat[2].y;
      v87 = v72->x;
      v88 = this->axis.mat[1].z;
      v89 = this->axis.mat[1].y;
      v90 = v69->x;
      v91 = this->axis.mat[0].z;
      v92 = this->axis.mat[0].y;
      v356 = p_axis->mat[0].x;
      do
      {
        v93 = *(float *)(v82 + 20);
        v94 = *(float *)(v82 + 16);
        v95 = *(float *)(v82 + 32);
        v96 = (float)(*(float *)(v82 + 20) * (float)v85);
        v97 = *(float *)(v82 + 24);
        v98 = *(float *)(v82 + 40);
        v99 = (float)(*(float *)(v82 + 32) * (float)v91);
        v100 = *(float *)(v82 + 28);
        v101 = (float)(*(float *)(v82 + 40) * (float)v92);
        v102 = (float)(*(float *)(v82 + 24) * (float)v90);
        v103 = *(float *)(v82 + 12);
        v104 = (float)((float)v86 * *(float *)(v82 + 28));
        v105 = *(float *)(v82 + 36);
        v106 = *(float *)(v82 + 44);
        v107 = (float)((float)(*(float *)(v82 + 16) * (float)v89) + (float)(*(float *)(v82 + 20) * (float)v88));
        v108 = (float)((float)(*(float *)(v82 + 12) * v356) + (float)(*(float *)(v82 + 16) * (float)v92));
        angle = *(float *)(v82 + 52);
        v109 = this->axis.mat[0].z;
        v110 = (float)((float)((float)v94 * (float)v86) + (float)v96);
        v111 = *(float *)(v82 + 56);
        LODWORD(v82) = v82 + 48;
        v357 = *(float *)v82;
        v90 = v69->x;
        v89 = this->axis.mat[1].y;
        v112 = (float)((float)((float)v103 * v69->x) + (float)v107);
        v113 = (float)((float)((float)v93 * (float)v109) + (float)v108);
        v114 = (float)((float)((float)v103 * (float)v87) + (float)v110);
        v115 = (float)((float)(this->axis.mat[0].y * (float)v100) + (float)((float)((float)v97 * v356) + (float)v99));
        v116 = (float)((float)(this->axis.mat[1].y * (float)v100)
                     + (float)((float)((float)v95 * (float)v88) + (float)v102));
        v118 = (float)((float)((float)v97 * (float)v87) + (float)((float)((float)v95 * (float)v85) + (float)v104));
        v119 = (float)((float)((float)v106 * (float)v109) + (float)((float)((float)v105 * v356) + (float)v101));
        _FP2 = (float)((float)_FP0 - (float)v112);
        _FP21 = (float)((float)_FP10 - (float)v113);
        _FP20 = (float)((float)_FP13 - (float)v114);
        _FP18 = (float)((float)v113 - (float)_FP9);
        v124 = (float)((float)((float)v105 * this->axis.mat[1].x)
                     + (float)((float)((float)v98 * this->axis.mat[1].y) + (float)((float)v106 * (float)v88)));
        v117 = (float)((float)((float)v98 * (float)v86) + (float)((float)v106 * (float)v85));
        _FP15 = (float)((float)v114 - (float)_FP11);
        _FP16 = (float)((float)v112 - (float)_FP12);
        v127 = (float)((float)((float)v105 * (float)v87) + (float)v117);
        __asm
        {
          fsel      f0, f2, f29, f0
          fsel      f10, f21, f31, f10
          fsel      f2, f20, f30, f13
          fsel      f13, f18, f31, f9
          fsel      f11, f15, f30, f11
          fsel      f12, f16, f29, f12
        }
        _FP30 = (float)((float)_FP0 - (float)v116);
        _FP29 = (float)((float)_FP10 - (float)v115);
        _FP22 = (float)((float)_FP2 - (float)v118);
        _FP21 = (float)((float)v115 - (float)_FP13);
        _FP18 = (float)((float)v118 - (float)_FP11);
        _FP20 = (float)((float)v116 - (float)_FP12);
        __asm
        {
          fsel      f0, f30, f23, f0
          fsel      f10, f29, f28, f10
          fsel      f30, f22, f27, f2
          fsel      f13, f21, f28, f13
          fsel      f11, f18, f27, f11
          fsel      f12, f20, f23, f12
        }
        _FP29 = (float)((float)_FP0 - (float)v124);
        _FP28 = (float)((float)_FP10 - (float)v119);
        _FP27 = (float)((float)_FP30 - (float)v127);
        v92 = this->axis.mat[0].y;
        _FP23 = (float)((float)v119 - (float)_FP13);
        _FP21 = (float)((float)v127 - (float)_FP11);
        HIDWORD(v82) += 4;
        _FP22 = (float)((float)v124 - (float)_FP12);
        __asm { fsel      f0, f29, f14, f0 }
        __asm
        {
          fsel      f30, f27, f24, f30
          fsel      f10, f28, f25, f10
          fsel      f29, f23, f25, f13
          fsel      f11, f21, f24, f11
          fsel      f12, f22, f14, f12
        }
        v91 = this->axis.mat[0].z;
        _FP28 = (float)((float)_FP0
                      - (float)((float)(v357 * this->axis.mat[1].x)
                              + (float)((float)(angle * this->axis.mat[1].y) + (float)((float)v111 * (float)v88))));
        _FP27 = (float)((float)_FP30
                      - (float)((float)(v357 * (float)v87)
                              + (float)((float)(angle * (float)v86) + (float)((float)v111 * (float)v85))));
        _FP24 = (float)((float)((float)(v357 * (float)v87)
                              + (float)((float)(angle * (float)v86) + (float)((float)v111 * (float)v85)))
                      - (float)_FP11);
        _FP25 = (float)((float)((float)(v357 * this->axis.mat[1].x)
                              + (float)((float)(angle * this->axis.mat[1].y) + (float)((float)v111 * (float)v88)))
                      - (float)_FP12);
        v162 = (float)((float)((float)v111 * this->axis.mat[0].z)
                     + (float)((float)(v357 * v356) + (float)(angle * this->axis.mat[0].y)));
        __asm
        {
          fsel      f0, f28, f31, f0
          fsel      f13, f27, f9, f30
          fsel      f11, f24, f9, f11
          fsel      f12, f25, f31, f12
        }
        _FP9 = (float)((float)_FP10 - (float)v162);
        _FP31 = (float)((float)v162 - (float)_FP29);
        __asm
        {
          fsel      f10, f9, f26, f10
          fsel      f9, f31, f26, f29
        }
      }
      while ( SHIDWORD(v82) < numPoints - 3 );
      v24 = v363;
    }
    if ( SHIDWORD(v82) < numPoints )
    {
      v165 = numPoints - HIDWORD(v82);
      v166 = &points[HIDWORD(v82) - 1];
      do
      {
        v167 = v166[1].y;
        v168 = v166[1].z;
        v169 = (float)(v166[1].y * this->axis.mat[0].y);
        ++v166;
        v170 = (float)((float)((float)v167 * this->axis.mat[1].y) + (float)(v166->x * this->axis.mat[1].x));
        v171 = (float)((float)(v166->x * this->axis.mat[0].x)
                     + (float)((float)((float)v168 * this->axis.mat[0].z) + (float)v169));
        v172 = (float)((float)((float)v167 * this->axis.mat[2].y)
                     + (float)((float)(v166->x * this->axis.mat[2].x) + (float)((float)v168 * this->axis.mat[2].z)));
        _FP26 = (float)((float)_FP10
                      - (float)((float)(v166->x * this->axis.mat[0].x)
                              + (float)((float)((float)v168 * this->axis.mat[0].z) + (float)v169)));
        v173 = (float)((float)((float)v168 * this->axis.mat[1].z) + (float)v170);
        _FP25 = (float)((float)_FP13 - (float)v172);
        _FP24 = (float)((float)_FP0 - (float)v173);
        _FP23 = (float)((float)v173 - (float)_FP12);
        _FP22 = (float)((float)v172 - (float)_FP11);
        _FP21 = (float)((float)v171 - (float)_FP9);
        __asm
        {
          fsel      f10, f26, f8, f10
          fsel      f13, f25, f29, f13
          fsel      f0, f24, f27, f0
          fsel      f12, f23, f27, f12
          fsel      f11, f22, f29, f11
          fsel      f9, f21, f8, f9
        }
        --v165;
      }
      while ( v165 != 0 );
    }
    if ( _FP10 >= _FP9 || _FP0 >= _FP12 || _FP13 >= _FP11 )
      v356 = v24;
    else
      v356 = (float)((float)((float)_FP11 - (float)_FP13) * (float)((float)_FP12 - (float)_FP0))
           * (float)((float)_FP9 - (float)_FP10);
    angle = v24;
    v180 = 8;
    v181 = 30.0;
    v357 = 30.0;
    do
    {
      v182 = -1;
      *(float *)&v360 = angle;
      do
      {
        LODWORD(v82) = v182;
        v366[0].axisValid = false;
        v365 = v82;
        v366[0].angle = (float)((float)v82 * (float)v181) + *(float *)&v360;
        v183 = idRotation::ToMat3(this: v366);
        idMat3::operator*(this: &v364, result: &this->axis, a: v183);
        _FP0 = 1.0e30;
        _FP12 = -1.0e30;
        _FP13 = 1.0e30;
        HIDWORD(v82) = 0;
        _FP10 = 1.0e30;
        v188 = v364.mat[0].y;
        _FP11 = -1.0e30;
        _FP9 = -1.0e30;
        v191 = v364.mat[0].z;
        v192 = v364.mat[0].x;
        if ( numPoints >= 4 )
        {
          LODWORD(v82) = points - 1;
          do
          {
            v193 = *(float *)(v82 + 52);
            v194 = *(float *)(v82 + 56);
            v195 = (float)((float)(v364.mat[0].z * *(float *)(v82 + 20))
                         + (float)((float)((float)v192 * *(float *)(v82 + 12))
                                 + (float)((float)v188 * *(float *)(v82 + 16))));
            v196 = (float)((float)(v364.mat[0].z * *(float *)(v82 + 44))
                         + (float)((float)(v364.mat[0].x * *(float *)(v82 + 36))
                                 + (float)((float)v188 * *(float *)(v82 + 40))));
            _FP20 = (float)((float)_FP10 - (float)v195);
            _FP19 = (float)((float)_FP0
                          - (float)((float)(v364.mat[1].z * *(float *)(v82 + 20))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 12))
                                          + (float)(v364.mat[1].y * *(float *)(v82 + 16)))));
            _FP18 = (float)((float)_FP13
                          - (float)((float)(v364.mat[2].z * *(float *)(v82 + 20))
                                  + (float)((float)(v364.mat[2].x * *(float *)(v82 + 12))
                                          + (float)(v364.mat[2].y * *(float *)(v82 + 16)))));
            _FP16 = (float)((float)((float)(v364.mat[1].z * *(float *)(v82 + 20))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 12))
                                          + (float)(v364.mat[1].y * *(float *)(v82 + 16))))
                          - (float)_FP12);
            _FP15 = (float)((float)((float)(v364.mat[2].z * *(float *)(v82 + 20))
                                  + (float)((float)(v364.mat[2].x * *(float *)(v82 + 12))
                                          + (float)(v364.mat[2].y * *(float *)(v82 + 16))))
                          - (float)_FP11);
            _FP17 = (float)((float)v195 - (float)_FP9);
            __asm
            {
              fsel      f10, f20, f30, f10
              fsel      f0, f19, f27, f0
              fsel      f13, f18, f25, f13
              fsel      f12, f16, f27, f12
              fsel      f11, f15, f25, f11
              fsel      f9, f17, f30, f9
            }
            _FP30 = (float)((float)_FP10
                          - (float)((float)(v364.mat[0].y * *(float *)(v82 + 28))
                                  + (float)((float)(v364.mat[0].x * *(float *)(v82 + 24))
                                          + (float)((float)v191 * *(float *)(v82 + 32)))));
            _FP22 = (float)((float)_FP0
                          - (float)((float)(v364.mat[1].y * *(float *)(v82 + 28))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 24))
                                          + (float)(v364.mat[1].z * *(float *)(v82 + 32)))));
            _FP21 = (float)((float)_FP13
                          - (float)((float)(v364.mat[2].z * *(float *)(v82 + 32))
                                  + (float)((float)(v364.mat[2].y * *(float *)(v82 + 28))
                                          + (float)(v364.mat[2].x * *(float *)(v82 + 24)))));
            _FP19 = (float)((float)((float)(v364.mat[1].y * *(float *)(v82 + 28))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 24))
                                          + (float)(v364.mat[1].z * *(float *)(v82 + 32))))
                          - (float)_FP12);
            _FP18 = (float)((float)((float)(v364.mat[2].z * *(float *)(v82 + 32))
                                  + (float)((float)(v364.mat[2].y * *(float *)(v82 + 28))
                                          + (float)(v364.mat[2].x * *(float *)(v82 + 24))))
                          - (float)_FP11);
            _FP20 = (float)((float)((float)(v364.mat[0].y * *(float *)(v82 + 28))
                                  + (float)((float)(v364.mat[0].x * *(float *)(v82 + 24))
                                          + (float)((float)v191 * *(float *)(v82 + 32))))
                          - (float)_FP9);
            __asm
            {
              fsel      f10, f30, f2, f10
              fsel      f0, f22, f31, f0
              fsel      f13, f21, f28, f13
              fsel      f12, f19, f31, f12
              fsel      f11, f18, f28, f11
              fsel      f9, f20, f2, f9
            }
            _FP2 = (float)((float)_FP10
                         - (float)((float)(v364.mat[0].z * *(float *)(v82 + 44))
                                 + (float)((float)(v364.mat[0].x * *(float *)(v82 + 36))
                                         + (float)((float)v188 * *(float *)(v82 + 40)))));
            _FP31 = (float)((float)_FP0
                          - (float)((float)(v364.mat[1].z * *(float *)(v82 + 44))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 36))
                                          + (float)(v364.mat[1].y * *(float *)(v82 + 40)))));
            _FP30 = (float)((float)_FP13
                          - (float)((float)(v364.mat[2].z * *(float *)(v82 + 44))
                                  + (float)((float)(v364.mat[2].x * *(float *)(v82 + 36))
                                          + (float)(v364.mat[2].y * *(float *)(v82 + 40)))));
            _FP22 = (float)((float)((float)(v364.mat[1].z * *(float *)(v82 + 44))
                                  + (float)((float)(v364.mat[1].x * *(float *)(v82 + 36))
                                          + (float)(v364.mat[1].y * *(float *)(v82 + 40))))
                          - (float)_FP12);
            _FP21 = (float)((float)((float)(v364.mat[2].z * *(float *)(v82 + 44))
                                  + (float)((float)(v364.mat[2].x * *(float *)(v82 + 36))
                                          + (float)(v364.mat[2].y * *(float *)(v82 + 40))))
                          - (float)_FP11);
            LODWORD(v82) = v82 + 48;
            _FP28 = (float)((float)v196 - (float)_FP9);
            __asm
            {
              fsel      f10, f2, f24, f10
              fsel      f0, f31, f23, f0
              fsel      f13, f30, f26, f13
            }
            v188 = v364.mat[0].y;
            __asm { fsel      f12, f22, f23, f12 }
            v192 = v364.mat[0].x;
            v191 = v364.mat[0].z;
            __asm { fsel      f9, f28, f24, f9 }
            _FP28 = (float)((float)_FP0
                          - (float)((float)(v364.mat[1].z * (float)v194)
                                  + (float)((float)(v364.mat[1].x * *(float *)v82) + (float)(v364.mat[1].y * (float)v193))));
            HIDWORD(v82) += 4;
            __asm { fsel      f11, f21, f26, f11 }
            _FP26 = (float)((float)_FP13
                          - (float)((float)(v364.mat[2].z * (float)v194)
                                  + (float)((float)(v364.mat[2].x * *(float *)v82) + (float)(v364.mat[2].y * (float)v193))));
            __asm { fsel      f0, f28, f25, f0 }
            _FP24 = (float)((float)((float)(v364.mat[2].z * (float)v194)
                                  + (float)((float)(v364.mat[2].x * *(float *)v82) + (float)(v364.mat[2].y * (float)v193)))
                          - (float)_FP11);
            __asm { fsel      f13, f26, f27, f13 }
            v237 = (float)((float)(v364.mat[0].z * (float)v194)
                         + (float)((float)(v364.mat[0].x * *(float *)v82) + (float)(v364.mat[0].y * (float)v193)));
            _FP29 = (float)((float)((float)(v364.mat[1].z * (float)v194)
                                  + (float)((float)(v364.mat[1].x * *(float *)v82) + (float)(v364.mat[1].y * (float)v193)))
                          - (float)_FP12);
            __asm
            {
              fsel      f12, f29, f25, f12
              fsel      f11, f24, f27, f11
            }
            _FP29 = (float)((float)_FP10 - (float)v237);
            _FP28 = (float)((float)v237 - (float)_FP9);
            __asm
            {
              fsel      f10, f29, f1, f10
              fsel      f9, f28, f1, f9
            }
          }
          while ( SHIDWORD(v82) < numPoints - 3 );
          v24 = v363;
          v181 = v357;
        }
        if ( SHIDWORD(v82) < numPoints )
        {
          v240 = numPoints - HIDWORD(v82);
          v241 = &points[HIDWORD(v82) - 1];
          do
          {
            v242 = v241[1].z;
            v243 = (float)(v241[1].z * (float)v191);
            v244 = v241[1].y;
            v245 = (float)(v364.mat[2].z * v241[1].z);
            ++v241;
            v246 = (float)((float)(v241->x * v364.mat[1].x) + (float)((float)v242 * v364.mat[1].z));
            v247 = (float)((float)((float)v244 * (float)v188) + (float)((float)(v241->x * (float)v192) + (float)v243));
            v248 = (float)((float)(v364.mat[2].y * (float)v244) + (float)((float)(v364.mat[2].x * v241->x) + (float)v245));
            v249 = (float)((float)((float)v244 * v364.mat[1].y) + (float)v246);
            _FP24 = (float)((float)_FP13
                          - (float)((float)(v364.mat[2].y * (float)v244)
                                  + (float)((float)(v364.mat[2].x * v241->x) + (float)v245)));
            _FP25 = (float)((float)_FP10 - (float)v247);
            _FP23 = (float)((float)_FP0 - (float)v249);
            _FP22 = (float)((float)v249 - (float)_FP12);
            _FP21 = (float)((float)v248 - (float)_FP11);
            _FP20 = (float)((float)v247 - (float)_FP9);
            __asm
            {
              fsel      f10, f25, f27, f10
              fsel      f13, f24, f26, f13
              fsel      f0, f23, f1, f0
              fsel      f12, f22, f1, f12
              fsel      f11, f21, f26, f11
              fsel      f9, f20, f27, f9
            }
            --v240;
          }
          while ( v240 != 0 );
        }
        if ( _FP10 >= _FP9 || _FP0 >= _FP12 || _FP13 >= _FP11 )
          v256 = v24;
        else
          v256 = (float)((float)((float)((float)_FP11 - (float)_FP13) * (float)((float)_FP12 - (float)_FP0))
                       * (float)((float)_FP9 - (float)_FP10));
        if ( v256 < v356 )
        {
          angle = v366[0].angle;
          v356 = v256;
        }
        v182 += 2;
      }
      while ( v182 <= 1 );
      --v180;
      v181 = (float)((float)v181 * v362);
      v357 = v181;
    }
    while ( v180 != 0 );
    v366[0].axisValid = false;
    v366[0].angle = angle;
    v257 = idRotation::ToMat3(this: v366);
    idMat3::operator*=(this: &this->axis, a: v257);
    mat = v358.mat;
    p = v361.p;
    goto LABEL_52;
  }
  if ( __fabs((float)(*p - p[2])) < 0.1 )
  {
    v77 = 1;
    goto LABEL_21;
  }
  if ( __fabs((float)(p[1] - p[2])) < 0.1 )
  {
    v77 = 0;
    goto LABEL_21;
  }
LABEL_52:
  _FP11 = 1.0e30;
  v259 = 0;
  _FP0 = -1.0e30;
  _FP10 = 1.0e30;
  _FP9 = 1.0e30;
  _FP13 = -1.0e30;
  _FP12 = -1.0e30;
  if ( numPoints >= 4 )
  {
    v265 = this->axis.mat[2].z;
    v266 = points - 1;
    v267 = this->axis.mat[2].y;
    v268 = v72->x;
    v269 = this->axis.mat[1].z;
    v270 = this->axis.mat[1].y;
    v271 = v69->x;
    v272 = this->axis.mat[0].z;
    v273 = this->axis.mat[0].y;
    v356 = p_axis->mat[0].x;
    do
    {
      v274 = v266[3].y;
      v275 = v266[3].x;
      v276 = v266[3].z;
      v277 = v266[4].z;
      v278 = v266[4].y;
      v279 = (float)((float)(v266[1].x * v69->x)
                   + (float)((float)(v266[1].y * (float)v270) + (float)(v266[1].z * (float)v269)));
      v270 = this->axis.mat[1].y;
      v280 = (float)((float)(v266[1].x * (float)v268)
                   + (float)((float)((float)v267 * v266[1].y) + (float)((float)v265 * v266[1].z)));
      v281 = (float)((float)(v266[1].z * this->axis.mat[0].z)
                   + (float)((float)(v266[1].x * v356) + (float)(v266[1].y * (float)v273)));
      v282 = (float)((float)(this->axis.mat[0].y * v266[2].y)
                   + (float)((float)(v266[2].x * v356) + (float)(v266[2].z * (float)v272)));
      v283 = (float)((float)(v266[3].z * this->axis.mat[0].z)
                   + (float)((float)(v266[3].x * v356) + (float)(v266[3].y * (float)v273)));
      v284 = (float)((float)(this->axis.mat[1].y * v266[2].y)
                   + (float)((float)((float)v269 * v266[2].z) + (float)(v266[2].x * (float)v271)));
      v271 = v69->x;
      v285 = (float)((float)((float)v267 * v266[2].y)
                   + (float)((float)((float)v265 * v266[2].z) + (float)(v266[2].x * (float)v268)));
      v286 = (float)((float)(v266[3].y * this->axis.mat[1].y) + (float)(v266[3].z * (float)v269));
      v266 += 4;
      *(float *)&v360 = v266->x;
      v287 = (float)((float)((float)v267 * (float)v274) + (float)((float)v265 * (float)v276));
      _FP2 = (float)((float)_FP11 - (float)v279);
      v357 = (float)v280 - (float)_FP13;
      _FP17 = (float)((float)_FP10 - (float)v280);
      _FP18 = (float)((float)_FP9 - (float)v281);
      _FP16 = (float)((float)v281 - (float)_FP12);
      _FP15 = (float)((float)v279 - (float)_FP0);
      v293 = (float)((float)((float)v275 * (float)v271) + (float)v286);
      v294 = (float)((float)((float)v275 * (float)v268) + (float)v287);
      __asm
      {
        fsel      f11, f2, f29, f11
        fsel      f2, f17, f30, f10
        fsel      f9, f18, f31, f9
        fsel      f12, f16, f31, f12
        fsel      f10, f15, f29, f0
      }
      _FP31 = v357;
      __asm { fsel      f0, f31, f30, f13 }
      _FP30 = (float)((float)_FP11 - (float)v284);
      _FP29 = (float)((float)_FP9 - (float)v282);
      _FP22 = (float)((float)_FP2 - (float)v285);
      _FP19 = (float)((float)v282 - (float)_FP12);
      _FP18 = (float)((float)v284 - (float)_FP10);
      _FP17 = (float)((float)v285 - (float)_FP0);
      __asm
      {
        fsel      f11, f30, f25, f11
        fsel      f9, f29, f28, f9
        fsel      f30, f22, f27, f2
        fsel      f12, f19, f28, f12
        fsel      f10, f18, f25, f10
        fsel      f0, f17, f27, f0
      }
      _FP29 = (float)((float)_FP11 - (float)v293);
      _FP28 = (float)((float)_FP9 - (float)v283);
      _FP27 = (float)((float)_FP30 - (float)v294);
      v273 = this->axis.mat[0].y;
      _FP22 = (float)((float)v293 - (float)_FP10);
      _FP19 = (float)((float)v294 - (float)_FP0);
      v259 += 4;
      _FP25 = (float)((float)v283 - (float)_FP12);
      __asm { fsel      f11, f29, f21, f11 }
      __asm
      {
        fsel      f30, f27, f24, f30
        fsel      f9, f28, f20, f9
        fsel      f29, f22, f21, f10
      }
      v272 = this->axis.mat[0].z;
      __asm
      {
        fsel      f28, f19, f24, f0
        fsel      f12, f25, f20, f12
      }
      _FP0 = (float)((float)_FP11
                   - (float)((float)(*(float *)&v360 * (float)v271)
                           + (float)((float)((float)v278 * (float)v270) + (float)((float)v277 * (float)v269))));
      _FP27 = (float)((float)_FP30
                    - (float)((float)(*(float *)&v360 * (float)v268)
                            + (float)((float)((float)v267 * (float)v278) + (float)((float)v265 * (float)v277))));
      _FP25 = (float)((float)((float)(*(float *)&v360 * (float)v271)
                            + (float)((float)((float)v278 * (float)v270) + (float)((float)v277 * (float)v269)))
                    - (float)_FP29);
      _FP24 = (float)((float)((float)(*(float *)&v360 * (float)v268)
                            + (float)((float)((float)v267 * (float)v278) + (float)((float)v265 * (float)v277)))
                    - (float)_FP28);
      v329 = (float)((float)((float)v277 * this->axis.mat[0].z)
                   + (float)((float)(*(float *)&v360 * v356) + (float)((float)v278 * this->axis.mat[0].y)));
      __asm
      {
        fsel      f11, f0, f31, f11
        fsel      f10, f27, f13, f30
        fsel      f0, f25, f31, f29
      }
      _FP31 = (float)((float)_FP9 - (float)v329);
      _FP30 = (float)((float)v329 - (float)_FP12);
      __asm
      {
        fsel      f13, f24, f13, f28
        fsel      f9, f31, f26, f9
        fsel      f12, f30, f26, f12
      }
    }
    while ( v259 < numPoints - 3 );
  }
  if ( v259 < numPoints )
  {
    v333 = numPoints - v259;
    v334 = &points[v259 - 1];
    do
    {
      v335 = v334[1].y;
      v336 = (float)(v334[1].z * this->axis.mat[0].z);
      v337 = (float)(v334[1].z * this->axis.mat[2].z);
      v338 = (float)((float)(v334[1].z * this->axis.mat[1].z) + (float)(v334[1].y * this->axis.mat[1].y));
      ++v334;
      v339 = (float)((float)((float)v335 * this->axis.mat[0].y)
                   + (float)((float)(v334->x * this->axis.mat[0].x) + (float)v336));
      v340 = (float)((float)((float)v335 * this->axis.mat[2].y)
                   + (float)((float)(v334->x * this->axis.mat[2].x) + (float)v337));
      _FP26 = (float)((float)_FP10 - (float)v340);
      _FP25 = (float)((float)_FP11 - (float)((float)(v334->x * v69->x) + (float)v338));
      _FP24 = (float)((float)((float)(v334->x * v69->x) + (float)v338) - (float)_FP0);
      _FP29 = (float)((float)_FP9 - (float)v339);
      _FP23 = (float)((float)v340 - (float)_FP13);
      _FP22 = (float)((float)v339 - (float)_FP12);
      __asm
      {
        fsel      f9, f29, f27, f9
        fsel      f10, f26, f28, f10
        fsel      f11, f25, f8, f11
        fsel      f0, f24, f8, f0
        fsel      f13, f23, f28, f13
        fsel      f12, f22, f27, f12
      }
      --v333;
    }
    while ( v333 != 0 );
  }
  v348 = (float)((float)((float)_FP0 + (float)_FP11) * v362);
  v347 = v362;
  this->center.y = v348;
  this->center.x = (float)((float)_FP12 + (float)_FP9) * (float)v347;
  this->center.z = (float)((float)_FP13 + (float)_FP10) * (float)v347;
  this->extents.y = (float)_FP0 - (float)v348;
  this->extents.x = (float)_FP12 - (float)((float)((float)_FP12 + (float)_FP9) * (float)v347);
  this->extents.z = (float)_FP13 - (float)((float)((float)_FP13 + (float)_FP10) * (float)v347);
  v349 = this->center.x;
  v350 = this->axis.mat[0].y;
  v351 = this->axis.mat[0].z;
  v352 = (float)((float)(this->axis.mat[2].y * this->center.z) + (float)(this->axis.mat[1].y * this->center.y));
  v353 = (float)((float)(this->axis.mat[2].z * this->center.z) + (float)(this->axis.mat[1].z * this->center.y));
  this->center.x = (float)(this->center.x * this->axis.mat[0].x)
                 + (float)((float)(this->axis.mat[2].x * this->center.z) + (float)(this->axis.mat[1].x * this->center.y));
  this->center.y = (float)((float)v350 * (float)v349) + (float)v352;
  this->center.z = (float)((float)v351 * (float)v349) + (float)v353;
  if ( p != nullptr && (p < idVecX::tempPtr || p >= idVecX::tempPtr + 1024) && v361.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: p, align: ALIGN_16);
    mat = v358.mat;
  }
  if ( mat != nullptr && v358.alloced != -1 )
    idMem::Free(this: &mem, ptr: mat, align: ALIGN_16);
}


// ========================================================================
// __unwind$116116
// EA  : 0x82EFA21C
// RVA : 0x00EFA21C
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

void _unwind_116116()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 528 + 96));
}


// ========================================================================
// __unwind$116117
// EA  : 0x82EFA244
// RVA : 0x00EFA244
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

void _unwind_116117()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 528 + 128));
}


// ========================================================================
// ?ToPoints@idBox@@QBAXQAVidVec3@@@Z
// EA  : 0x82EFA270
// RVA : 0x00EFA270
// PDB : w:\tech5\shared\idlib\bv\box.cpp
// ========================================================================

void __fastcall idBox::ToPoints(idBox *this, idVec3 *points)
{
  double v2; // fp11
  double v3; // fp8
  double v4; // fp31
  double v5; // fp2
  double v6; // fp0
  double v7; // fp12
  double v8; // fp9
  double v9; // fp7
  double v10; // fp5
  double v11; // fp3
  double v12; // fp1
  double v13; // fp13

  v2 = (float)(this->center.x - (float)(this->axis.mat[0].x * this->extents.x));
  v3 = (float)(this->center.y - (float)(this->axis.mat[0].y * this->extents.x));
  v4 = (float)(this->center.z - (float)(this->axis.mat[0].z * this->extents.x));
  v5 = (float)(this->center.x + (float)(this->axis.mat[0].x * this->extents.x));
  v6 = (float)(this->center.y + (float)(this->axis.mat[0].y * this->extents.x));
  v7 = (float)(this->center.z + (float)(this->axis.mat[0].z * this->extents.x));
  v8 = (float)((float)(this->axis.mat[2].x * this->extents.z) + (float)(this->axis.mat[1].x * this->extents.y));
  v9 = (float)((float)(this->axis.mat[2].y * this->extents.z) + (float)(this->axis.mat[1].y * this->extents.y));
  v10 = (float)((float)(this->axis.mat[2].z * this->extents.z) + (float)(this->axis.mat[1].z * this->extents.y));
  v11 = (float)((float)(this->axis.mat[1].x * this->extents.y) - (float)(this->axis.mat[2].x * this->extents.z));
  v12 = (float)((float)(this->axis.mat[1].y * this->extents.y) - (float)(this->axis.mat[2].y * this->extents.z));
  v13 = (float)((float)(this->axis.mat[1].z * this->extents.y) - (float)(this->axis.mat[2].z * this->extents.z));
  points->x = (float)(this->center.x - (float)(this->axis.mat[0].x * this->extents.x))
            - (float)((float)(this->axis.mat[2].x * this->extents.z) + (float)(this->axis.mat[1].x * this->extents.y));
  points->y = (float)v3 - (float)v9;
  points->z = (float)v4 - (float)v10;
  points[1].x = (float)v5 - (float)v8;
  points[1].y = (float)v6 - (float)v9;
  points[1].z = (float)v7 - (float)v10;
  points[2].x = (float)v11 + (float)v5;
  points[2].y = (float)v12 + (float)v6;
  points[2].z = (float)v13 + (float)v7;
  points[3].x = (float)v11 + (float)v2;
  points[3].y = (float)v12 + (float)v3;
  points[3].z = (float)v13 + (float)v4;
  points[4].x = (float)v2 - (float)v11;
  points[4].y = (float)v3 - (float)v12;
  points[4].z = (float)v4 - (float)v13;
  points[5].x = (float)v5 - (float)v11;
  points[5].y = (float)v6 - (float)v12;
  points[5].z = (float)v7 - (float)v13;
  points[6].x = (float)v8 + (float)v5;
  points[6].y = (float)v9 + (float)v6;
  points[6].z = (float)v10 + (float)v7;
  points[7].x = (float)v8 + (float)v2;
  points[7].y = (float)v9 + (float)v3;
  points[7].z = (float)v10 + (float)v4;
}

