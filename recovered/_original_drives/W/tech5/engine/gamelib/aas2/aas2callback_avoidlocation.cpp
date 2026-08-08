
// ========================================================================
// ?PathValid@idAAS2Callback_AvoidLocation@@UAA_NPBVidAAS2@@ABVidVec3@@1@Z
// EA  : 0x826AAA80
// RVA : 0x006AAA80
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_avoidlocation.cpp
// ========================================================================

int __fastcall idAAS2Callback_AvoidLocation::PathValid(
        idAAS2Callback_AvoidLocation *this,
        const idAAS2 *aas,
        const idVec3 *start,
        const idVec3 *end)
{
  int v7; // r29
  int i; // r31

  if ( this->obstacles == nullptr )
    return 1;
  v7 = 0;
  if ( this->numObstacles <= 0 )
    return 1;
  for ( i = 0; !idBounds::LineIntersection(this: &this->obstacles[i].expAbsBounds, start, end); ++i )
  {
    if ( ++v7 >= this->numObstacles )
      return 1;
  }
  return 0;
}


// ========================================================================
// ??0idAAS2Callback_AvoidLocation@@QAA@XZ
// EA  : 0x826AAB60
// RVA : 0x006AAB60
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_avoidlocation.cpp
// ========================================================================

idAAS2Callback_AvoidLocation *__fastcall idAAS2Callback_AvoidLocation::idAAS2Callback_AvoidLocation(
        idAAS2Callback_AvoidLocation *this)
{
  this->__vftable = (idAAS2Callback_AvoidLocation_vtbl *)&idAAS2Callback_AvoidLocation::`vftable';
  this->avoidLocation.z = 0.0;
  this->avoidLocation.y = 0.0;
  this->avoidLocation.x = 0.0;
  this->obstacles = nullptr;
  this->avoidDist = 0.0;
  this->numObstacles = 0;
  return this;
}


// ========================================================================
// ??1idAAS2Callback_AvoidLocation@@UAA@XZ
// EA  : 0x826AAB98
// RVA : 0x006AAB98
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_avoidlocation.cpp
// ========================================================================

void __fastcall idAAS2Callback_AvoidLocation::~idAAS2Callback_AvoidLocation(idAAS2Callback_AvoidLocation *this)
{
  this->obstacles = nullptr;
  this->__vftable = (idAAS2Callback_AvoidLocation_vtbl *)&idAAS2Callback::`vftable';
}


// ========================================================================
// ?AdditionalTravelTimeForPath@idAAS2Callback_AvoidLocation@@UAAHPBVidAAS2@@ABVidVec3@@1@Z
// EA  : 0x826AABB0
// RVA : 0x006AABB0
// PDB : w:\tech5\engine\gamelib\aas2\aas2callback_avoidlocation.cpp
// ========================================================================

int __fastcall idAAS2Callback_AvoidLocation::AdditionalTravelTimeForPath(
        idAAS2Callback_AvoidLocation *this,
        const idAAS2 *aas,
        const idVec3 *start,
        const idVec3 *end)
{
  double avoidDist; // fp2
  double y; // fp8
  double v6; // fp5
  double z; // fp7
  double v8; // fp3
  double x; // fp6
  int v10; // r9
  double v11; // fp11
  int v12; // r10
  double v13; // fp10
  double v14; // fp9
  float *v15; // r11
  int v16; // r8
  double v19; // fp13
  double v20; // fp13
  double v21; // fp13
  double v22; // fp13
  double v23; // fp12
  double v24; // fp5
  double v25; // fp4
  double v26; // fp13
  double v27; // fp0
  double v28; // fp5
  double v29; // fp4
  double v30; // fp3
  double v31; // fp0
  double v32; // fp0
  double v33; // fp13
  double v34; // fp12
  double v35; // fp0
  double v37; // [sp+0h] [-50h] BYREF
  float v38; // [sp+8h] [-48h]

  avoidDist = this->avoidDist;
  if ( avoidDist <= 0.0 )
    return 0;
  y = end->y;
  v6 = (float)(end->y - start->y);
  z = end->z;
  v8 = (float)(end->z - start->z);
  x = end->x;
  v10 = (char *)end - (char *)&v37;
  v11 = this->avoidLocation.y;
  v12 = 0;
  v13 = this->avoidLocation.z;
  v14 = this->avoidLocation.x;
  v15 = (float *)&v37;
  v16 = (char *)start - (char *)&v37;
  _FP25 = (float)((float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                        + (float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f25, f28, f13 }
  v19 = __frsqrte(_FP13);
  v20 = (float)((float)-(float)((float)((float)((float)v19
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v19)
                              - (float)1.5)
              * (float)v19);
  v21 = (float)((float)-(float)((float)((float)((float)v20
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)(end->y - start->y) * (float)v22);
  v24 = (float)((float)(end->z - start->z) * (float)v22);
  v25 = (float)((float)(end->x - start->x) * (float)v22);
  v26 = (float)((float)((float)(this->avoidLocation.x - start->x) * (float)((float)(end->x - start->x) * (float)v22))
              + (float)((float)((float)(this->avoidLocation.z - start->z)
                              * (float)((float)(end->z - start->z) * (float)v22))
                      + (float)((float)(this->avoidLocation.y - start->y)
                              * (float)((float)(end->y - start->y) * (float)v22))));
  v27 = (float)((float)v24 * (float)v26);
  v28 = (float)(start->x + (float)((float)v26 * (float)v25));
  v29 = (float)(start->y + (float)((float)v23 * (float)v26));
  v30 = (float)(start->z + (float)v27);
  v38 = start->z + (float)v27;
  while ( 1 )
  {
    v31 = *v15;
    if ( v31 > (float)(*(float *)((char *)v15 + v16) + (float)0.1)
      && v31 > (float)(*(float *)((char *)v15 + v10) + (float)0.1) )
    {
      break;
    }
    if ( v31 < (float)(*(float *)((char *)v15 + v16) - (float)0.1)
      && v31 < (float)(*(float *)((char *)v15 + v10) - (float)0.1) )
    {
      break;
    }
    ++v12;
    ++v15;
    if ( v12 >= 3 )
    {
      v32 = (float)((float)v11 - (float)v29);
      v33 = (float)((float)v13 - (float)v30);
      v34 = (float)((float)v14 - (float)v28);
      goto LABEL_10;
    }
  }
  v32 = (float)((float)v11 - (float)y);
  v33 = (float)((float)v13 - (float)z);
  v34 = (float)((float)v14 - (float)x);
LABEL_10:
  v35 = __fsqrts((float)((float)((float)v34 * (float)v34)
                       + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))));
  if ( v35 >= avoidDist )
    return 0;
  else
    return (int)(float)((float)((float)avoidDist - (float)v35) * (float)10.0);
}

