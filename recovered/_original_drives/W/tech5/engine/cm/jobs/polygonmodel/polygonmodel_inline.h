
// ========================================================================
// ?CM_BoundsPlaneSide@@YAHABVidVec4@@0ABVidPlane@@@Z
// EA  : 0x825E53C0
// RVA : 0x005E53C0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

int __fastcall CM_BoundsPlaneSide(const idVec4 *boundsMin, const idVec4 *boundsMax, const idPlane *plane)
{
  double v3; // fp4
  double v4; // fp3
  double v5; // fp1
  int result; // r3
  double v7; // fp13

  v3 = __fabs((float)((float)(boundsMax->x - (float)((float)(boundsMin->x + boundsMax->x) * (float)0.5)) * plane->a));
  v4 = __fabs((float)((float)(boundsMax->y - (float)((float)(boundsMin->y + boundsMax->y) * (float)0.5)) * plane->b));
  v5 = __fabs((float)((float)(boundsMax->z - (float)((float)(boundsMin->z + boundsMax->z) * (float)0.5)) * plane->c));
  if ( (float)((float)((float)((float)(plane->a * (float)((float)(boundsMin->x + boundsMax->x) * (float)0.5))
                             + (float)((float)(plane->b * (float)((float)(boundsMin->y + boundsMax->y) * (float)0.5))
                                     + (float)(plane->c * (float)((float)(boundsMin->z + boundsMax->z) * (float)0.5))))
                     + plane->d)
             - (float)((float)((float)v4 + (float)v3) + (float)v5)) > 0.1 )
    return 0;
  v7 = (float)((float)((float)((float)v4 + (float)v3) + (float)v5)
             + (float)((float)((float)(plane->a * (float)((float)(boundsMin->x + boundsMax->x) * (float)0.5))
                             + (float)((float)(plane->b * (float)((float)(boundsMin->y + boundsMax->y) * (float)0.5))
                                     + (float)(plane->c * (float)((float)(boundsMin->z + boundsMax->z) * (float)0.5))))
                     + plane->d));
  result = 1;
  if ( v7 >= -0.1 )
    return 3;
  return result;
}


// ========================================================================
// ?CM_BoundsShortPlaneCull@@YA_NABVidBoundsShort@@ABVidPlane@@M@Z
// EA  : 0x825E5480
// RVA : 0x005E5480
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

BOOL __fastcall CM_BoundsShortPlaneCull(
        const idBoundsShort *bs,
        const idPlane *plane,
        double cmpdist,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18)
{
  char v23; // cr56
  char v24; // cr57
  char v25; // cr58
  char v26; // cr59
  char v27; // r6
  unsigned __int8 v29; // cr56
  unsigned __int8 v30; // cr57

  __asm { lvx128    v63, r0, r3 }
  _R10 = 16;
  __asm
  {
    lvx128    v61, r0, r4
    vsldoi128 v60, v95, v63, 6
  }
  _R9 = &vmx_float_one;
  __asm { vupkhsh128 v59, v63 }
  _R8 = 64;
  _R7 = &a18;
  __asm
  {
    vupkhsh128 v58, v60
    vcsxwfp128 v57, v59, 0
    lvx128    v62, r9, r10
    lvx128    v63, r9, r8
    vand128   v56, v93, v63
    lvx128    v63, r0, r9
    vcsxwfp128 v55, v58, 0
    lvlx128   v54, r0, r7
    vspltw128 v53, v54, 0
    vaddfp128 v52, v89, v55
    vmulfp128 v51, v84, v62
    vsubfp128 v50, v87, v51
    vrlimi128 v51, v63, 1, 0
    vmsum4fp128 v49, v93, v51
    vmsum3fp128 v48, v88, v50
    vaddfp128 v47, v80, v53
    vcmpgtfp128. v46, v81, v47
  }
  v27 = (v23 << 7) | (v24 << 6) | (32 * v25) | (16 * v26);
  _R5 = 48;
  __asm
  {
    lvx128    v63, r9, r5
    vxor128   v45, v79, v63
    vcmpgtfp128. v44, v77, v49
  }
  return (((v29 << 7) | (v30 << 6)) & 0x80) != 0 || v27 < 0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''
// EA  : 0x833360C8
// RVA : 0x013360C8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps__()
{
  vmx_float_firstOnePlusTwoUlps.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''
// EA  : 0x833360F0
// RVA : 0x013360F0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity__()
{
  vmx_float_posInfinity.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''
// EA  : 0x83336118
// RVA : 0x01336118
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity__()
{
  vmx_float_negInfinity.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_0
// EA  : 0x83336140
// RVA : 0x01336140
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___0()
{
  vmx_float_firstOnePlusTwoUlps_0.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_0
// EA  : 0x83336168
// RVA : 0x01336168
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___0()
{
  vmx_float_posInfinity_0.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_0.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_0.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_0.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_0
// EA  : 0x83336190
// RVA : 0x01336190
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___0()
{
  vmx_float_negInfinity_0.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_0.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_0.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_0.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_1
// EA  : 0x833361B8
// RVA : 0x013361B8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___1()
{
  vmx_float_firstOnePlusTwoUlps_1.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_1
// EA  : 0x833361E0
// RVA : 0x013361E0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___1()
{
  vmx_float_posInfinity_1.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_1.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_1.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_1.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_1
// EA  : 0x83336208
// RVA : 0x01336208
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___1()
{
  vmx_float_negInfinity_1.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_1.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_1.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_1.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_2
// EA  : 0x83336230
// RVA : 0x01336230
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___2()
{
  vmx_float_firstOnePlusTwoUlps_2.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_2
// EA  : 0x83336258
// RVA : 0x01336258
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___2()
{
  vmx_float_posInfinity_2.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_2.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_2.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_2.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_2
// EA  : 0x83336280
// RVA : 0x01336280
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___2()
{
  vmx_float_negInfinity_2.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_2.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_2.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_2.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_3
// EA  : 0x833362A8
// RVA : 0x013362A8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___3()
{
  vmx_float_firstOnePlusTwoUlps_3.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_3
// EA  : 0x833362D0
// RVA : 0x013362D0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___3()
{
  vmx_float_posInfinity_3.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_3.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_3.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_3.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_3
// EA  : 0x833362F8
// RVA : 0x013362F8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___3()
{
  vmx_float_negInfinity_3.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_3.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_3.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_3.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_4
// EA  : 0x83336320
// RVA : 0x01336320
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___4()
{
  vmx_float_firstOnePlusTwoUlps_4.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_4
// EA  : 0x83336348
// RVA : 0x01336348
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___4()
{
  vmx_float_posInfinity_4.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_4.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_4.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_4.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_4
// EA  : 0x83336370
// RVA : 0x01336370
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___4()
{
  vmx_float_negInfinity_4.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_4.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_4.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_4.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_5
// EA  : 0x83336398
// RVA : 0x01336398
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___5()
{
  vmx_float_firstOnePlusTwoUlps_5.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_5
// EA  : 0x833363C0
// RVA : 0x013363C0
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___5()
{
  vmx_float_posInfinity_5.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_5.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_5.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_5.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_5
// EA  : 0x833363E8
// RVA : 0x013363E8
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___5()
{
  vmx_float_negInfinity_5.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_5.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_5.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_5.vector4_f32[3] = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_firstOnePlusTwoUlps''_6
// EA  : 0x83336410
// RVA : 0x01336410
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_firstOnePlusTwoUlps___6()
{
  vmx_float_firstOnePlusTwoUlps_6.vector4_f32[0] = (float)((float)0.00000011920929 * (float)2.0) + (float)1.0;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_posInfinity''_6
// EA  : 0x83336438
// RVA : 0x01336438
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_posInfinity___6()
{
  vmx_float_posInfinity_6.vector4_f32[0] = 1.0e30;
  vmx_float_posInfinity_6.vector4_f32[1] = 1.0e30;
  vmx_float_posInfinity_6.vector4_f32[2] = 1.0e30;
  vmx_float_posInfinity_6.vector4_f32[3] = 1.0e30;
}


// ========================================================================
// `dynamic initializer for 'vmx_float_negInfinity''_6
// EA  : 0x83336460
// RVA : 0x01336460
// PDB : w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel_inline.h
// ========================================================================

void _dynamic_initializer_for__vmx_float_negInfinity___6()
{
  vmx_float_negInfinity_6.vector4_f32[0] = -1.0e30;
  vmx_float_negInfinity_6.vector4_f32[1] = -1.0e30;
  vmx_float_negInfinity_6.vector4_f32[2] = -1.0e30;
  vmx_float_negInfinity_6.vector4_f32[3] = -1.0e30;
}

