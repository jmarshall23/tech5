
// ========================================================================
// CalcSpotShadowFactor
// EA  : 0x828D2390
// RVA : 0x008D2390
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

float __fastcall CalcSpotShadowFactor(const idRenderLightParms *lightParms, idVec3 *dir)
{
  double v2; // fp10
  double v3; // fp6
  double v4; // fp5
  double v5; // fp4
  double v6; // fp7
  double v7; // fp2
  double v8; // fp3
  double v9; // fp8
  double v10; // fp1
  double v12; // fp27
  double v14; // fp31
  double v15; // fp31
  double v16; // fp31
  double v17; // fp31
  double v18; // fp6
  double v19; // fp29
  double v20; // fp5
  double v25; // fp31
  double v26; // fp13
  double v27; // fp31
  double v28; // fp13
  double v29; // fp31
  double v30; // fp13
  double v31; // fp0
  double v32; // fp12
  double v33; // fp8
  float result; // fp1

  v2 = (float)((float)(lightParms->axis.mat[2].y * lightParms->target.z)
             + (float)((float)(lightParms->axis.mat[0].y * lightParms->target.x)
                     + (float)(lightParms->axis.mat[1].y * lightParms->target.y)));
  v3 = (float)((float)(lightParms->axis.mat[2].z * lightParms->target.z)
             + (float)((float)(lightParms->axis.mat[0].z * lightParms->target.x)
                     + (float)(lightParms->axis.mat[1].z * lightParms->target.y)));
  v4 = (float)((float)(lightParms->axis.mat[2].x * lightParms->target.z)
             + (float)((float)(lightParms->target.x * lightParms->axis.mat[0].x)
                     + (float)(lightParms->axis.mat[1].x * lightParms->target.y)));
  v5 = (float)((float)(lightParms->right.z * lightParms->axis.mat[2].x)
             + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].x)
                     + (float)(lightParms->right.y * lightParms->axis.mat[1].x)));
  v6 = (float)((float)(lightParms->up.z * lightParms->axis.mat[2].y)
             + (float)((float)(lightParms->up.x * lightParms->axis.mat[0].y)
                     + (float)(lightParms->up.y * lightParms->axis.mat[1].y)));
  v7 = (float)((float)(lightParms->up.z * lightParms->axis.mat[2].x)
             + (float)((float)(lightParms->up.x * lightParms->axis.mat[0].x)
                     + (float)(lightParms->up.y * lightParms->axis.mat[1].x)));
  v8 = (float)((float)(lightParms->right.z * lightParms->axis.mat[2].y)
             + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].y)
                     + (float)(lightParms->right.y * lightParms->axis.mat[1].y)));
  v9 = (float)((float)(lightParms->right.z * lightParms->axis.mat[2].z)
             + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].z)
                     + (float)(lightParms->right.y * lightParms->axis.mat[1].z)));
  v10 = (float)((float)(lightParms->up.z * lightParms->axis.mat[2].z)
              + (float)((float)(lightParms->up.x * lightParms->axis.mat[0].z)
                      + (float)(lightParms->up.y * lightParms->axis.mat[1].z)));
  _FP30 = (float)((float)((float)((float)v4 * (float)v4)
                        + (float)((float)((float)v3 * (float)v3) + (float)((float)v2 * (float)v2)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  v12 = __fsqrts((float)((float)((float)v4 * (float)v4)
                       + (float)((float)((float)v3 * (float)v3) + (float)((float)v2 * (float)v2))));
  __asm { fsel      f31, f30, f31, f13 }
  v14 = __frsqrte(_FP31);
  v15 = (float)((float)-(float)((float)((float)((float)v14
                                              * (float)((float)((float)((float)v4 * (float)v4)
                                                              + (float)((float)((float)v3 * (float)v3)
                                                                      + (float)((float)v2 * (float)v2)))
                                                      * (float)0.5))
                                      * (float)v14)
                              - (float)1.5)
              * (float)v14);
  v16 = (float)((float)-(float)((float)((float)((float)v15
                                              * (float)((float)((float)((float)v4 * (float)v4)
                                                              + (float)((float)((float)v3 * (float)v3)
                                                                      + (float)((float)v2 * (float)v2)))
                                                      * (float)0.5))
                                      * (float)v15)
                              - (float)1.5)
              * (float)v15);
  v17 = (float)((float)-(float)((float)((float)((float)v16
                                              * (float)((float)((float)((float)v4 * (float)v4)
                                                              + (float)((float)((float)v3 * (float)v3)
                                                                      + (float)((float)v2 * (float)v2)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v18 = (float)(dir->x
              * (float)((float)v12
                      / (float)((float)(dir->x
                                      * (float)((float)v17
                                              * (float)((float)(lightParms->axis.mat[2].x * lightParms->target.z)
                                                      + (float)((float)(lightParms->target.x * lightParms->axis.mat[0].x)
                                                              + (float)(lightParms->axis.mat[1].x * lightParms->target.y)))))
                              + (float)((float)(dir->y
                                              * (float)((float)((float)(lightParms->axis.mat[2].y * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].y
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].y
                                                                              * lightParms->target.y)))
                                                      * (float)v17))
                                      + (float)(dir->z
                                              * (float)((float)((float)(lightParms->axis.mat[2].z * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].z
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].z
                                                                              * lightParms->target.y)))
                                                      * (float)v17))))));
  v19 = (float)(dir->y
              * (float)((float)v12
                      / (float)((float)(dir->x
                                      * (float)((float)v17
                                              * (float)((float)(lightParms->axis.mat[2].x * lightParms->target.z)
                                                      + (float)((float)(lightParms->target.x * lightParms->axis.mat[0].x)
                                                              + (float)(lightParms->axis.mat[1].x * lightParms->target.y)))))
                              + (float)((float)(dir->y
                                              * (float)((float)((float)(lightParms->axis.mat[2].y * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].y
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].y
                                                                              * lightParms->target.y)))
                                                      * (float)v17))
                                      + (float)(dir->z
                                              * (float)((float)((float)(lightParms->axis.mat[2].z * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].z
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].z
                                                                              * lightParms->target.y)))
                                                      * (float)v17))))));
  v20 = (float)(dir->z
              * (float)((float)v12
                      / (float)((float)(dir->x
                                      * (float)((float)v17
                                              * (float)((float)(lightParms->axis.mat[2].x * lightParms->target.z)
                                                      + (float)((float)(lightParms->target.x * lightParms->axis.mat[0].x)
                                                              + (float)(lightParms->axis.mat[1].x * lightParms->target.y)))))
                              + (float)((float)(dir->y
                                              * (float)((float)((float)(lightParms->axis.mat[2].y * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].y
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].y
                                                                              * lightParms->target.y)))
                                                      * (float)v17))
                                      + (float)(dir->z
                                              * (float)((float)((float)(lightParms->axis.mat[2].z * lightParms->target.z)
                                                              + (float)((float)(lightParms->axis.mat[0].z
                                                                              * lightParms->target.x)
                                                                      + (float)(lightParms->axis.mat[1].z
                                                                              * lightParms->target.y)))
                                                      * (float)v17))))));
  _FP28 = (float)((float)((float)((float)v7 * (float)v7)
                        + (float)((float)((float)v10 * (float)v10) + (float)((float)v6 * (float)v6)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP25 = (float)((float)((float)((float)v5 * (float)v5)
                        + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f30, f28, f30, f13 }
  __asm { fsel      f13, f25, f31, f13 }
  v25 = __frsqrte(_FP30);
  v26 = __frsqrte(_FP13);
  v27 = (float)((float)-(float)((float)((float)((float)v25
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v25)
                              - (float)1.5)
              * (float)v25);
  v28 = (float)((float)-(float)((float)((float)((float)v26
                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)v26)
                              - (float)1.5)
              * (float)v26);
  v29 = (float)((float)-(float)((float)((float)((float)v27
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v6 * (float)v6)))
                                                      * (float)0.5))
                                      * (float)v27)
                              - (float)1.5)
              * (float)v27);
  v30 = (float)((float)-(float)((float)((float)((float)v28
                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  v31 = (float)((float)-(float)((float)((float)((float)v30
                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)v30)
                              - (float)1.5)
              * (float)v30);
  v32 = (float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v6 * (float)v6)))
                                                                                      * (float)0.5))
                                                                      * (float)v29)
                                                              - (float)1.5)
                                              * (float)v29)
                                      * (float)((float)(lightParms->up.z * lightParms->axis.mat[2].x)
                                              + (float)((float)(lightParms->up.x * lightParms->axis.mat[0].x)
                                                      + (float)(lightParms->up.y * lightParms->axis.mat[1].x))))
                              * (float)v18)
                      + (float)((float)((float)((float)v10
                                              * (float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v10 * (float)v10) + (float)((float)v6 * (float)v6)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      * (float)v20)
                              + (float)((float)((float)v6
                                              * (float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v10 * (float)v10) + (float)((float)v6 * (float)v6)))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      * (float)v19)))
              / (float)__fsqrts((float)((float)((float)v7 * (float)v7)
                                      + (float)((float)((float)v10 * (float)v10) + (float)((float)v6 * (float)v6)))));
  v33 = (float)((float)((float)((float)((float)v31
                                      * (float)((float)(lightParms->right.z * lightParms->axis.mat[2].x)
                                              + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].x)
                                                      + (float)(lightParms->right.y * lightParms->axis.mat[1].x))))
                              * (float)v18)
                      + (float)((float)((float)((float)((float)(lightParms->right.z * lightParms->axis.mat[2].z)
                                                      + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].z)
                                                              + (float)(lightParms->right.y * lightParms->axis.mat[1].z)))
                                              * (float)v31)
                                      * (float)v20)
                              + (float)((float)((float)((float)(lightParms->right.z * lightParms->axis.mat[2].y)
                                                      + (float)((float)(lightParms->right.x * lightParms->axis.mat[0].y)
                                                              + (float)(lightParms->right.y * lightParms->axis.mat[1].y)))
                                              * (float)v31)
                                      * (float)v19)))
              / (float)__fsqrts((float)((float)((float)v5 * (float)v5)
                                      + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))));
  _FP3 = -(float)((float)1.0
                - (float)__fsqrts((float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))));
  __asm { fsel      f2, f3, f10, f4 }
  _FP0 = (float)((float)1.0 - (float)((float)_FP2 * (float)4.0));
  __asm { fsel      f1, f0, f1, f11 }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?ShadowSample@shadowMap_t@@QBAMABVidVec3@@@Z
// EA  : 0x828D2600
// RVA : 0x008D2600
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

float __fastcall shadowMap_t::ShadowSample(shadowMap_t *this, const idVec3 *worldPoint)
{
  double v3; // fp1
  __int64 v4; // r9
  long double v5; // fp2
  unsigned int v6; // r28
  float *v7; // r30
  double v8; // fp31
  unsigned int v9; // r31
  double v10; // fp30
  int v11; // fp8
  double v12; // fp13
  int v13; // r6
  int width; // r9
  int v15; // r5
  int v16; // ctr
  int v17; // r4
  int v18; // r11
  int *v19; // r10
  unsigned __int16 *map; // r9
  int v21; // r11
  int i; // ctr
  double v25; // fp13
  double v26; // fp30
  unsigned int v27; // r27
  float *v28; // r31
  unsigned __int16 **v29; // r30
  int j; // r29
  unsigned int v31; // r11
  double v32; // fp28
  int v34; // [sp+50h] [-B0h] BYREF
  int v35; // [sp+54h] [-ACh]
  __int64 v36; // [sp+58h] [-A8h]
  _DWORD v37[2]; // [sp+60h] [-A0h] BYREF
  int v38; // [sp+64h] [-9Ch] BYREF
  float v39[5]; // [sp+70h] [-90h] BYREF
  char v40; // [sp+88h] [-78h] BYREF
  _BYTE v41[16]; // [sp+90h] [-70h] BYREF
  int v42; // [sp+A0h] [-60h]

  if ( this->useShadowMap && this->map != nullptr )
  {
    idRenderMatrix::TransformPoint(this: &this->mvp, in: worldPoint, out: (idVec4 *)v39);
    v6 = 0;
    v7 = &v39[2];
    v8 = 0.0;
    v9 = 0;
    do
    {
      LODWORD(v4) = this->width;
      v10 = (float)((float)(v39[v9] * (float)v4) + this->coordinateBias);
      *(double *)&v5 = v10;
      v36 = v4;
      v5 = floor(x: v5);
      v11 = (int)(float)*(double *)&v5;
      v38 = v11;
      v7[3] = (float)v10 - (float)*(double *)&v5;
      *(int *)((char *)&v34 + v9 * 4) = v11;
      if ( v11 >= 0 )
      {
        LODWORD(v4) = this->width;
        HIDWORD(v4) = this->width - 1;
        if ( (int)(float)*(double *)&v5 >= SHIDWORD(v4) )
        {
          v7[3] = 1.0;
          *(int *)((char *)&v34 + v9 * 4) = v4 - 2;
        }
      }
      else
      {
        v7[3] = 0.0;
        *(int *)((char *)&v34 + v9 * 4) = 0;
      }
      ++v9;
      v12 = (float)((float)1.0 - v7[3]);
      v7 += 2;
      *v7 = v12;
    }
    while ( v9 < 2 );
    v13 = v35;
    width = this->width;
    v15 = v34;
    v16 = 2;
    v17 = (v35 + 1) * this->width + v34;
    v18 = 0;
    v19 = &v38;
    do
    {
      *(v19++ - 1) = width * v13 + v15 + v18;
      *v19 = v17 + v18++;
      --v16;
    }
    while ( v16 != 0 );
    map = this->map;
    v21 = 0;
    v42 = 4;
    _R7 = v41;
    for ( i = 4; i != 0; --i )
    {
      _R10 = abs32(v37[v21]);
      __asm { dcbt      r10, r7 }
      *(_DWORD *)&v41[v21 * 4] = &map[_R10];
      ++v21;
    }
    v25 = v39[2];
    if ( v39[2] <= 1.0 )
    {
      if ( v25 < 0.0 )
        v25 = 0.0;
    }
    else
    {
      v25 = 1.0;
    }
    v26 = (float)((float)((float)v25 * (float)65535.0) + this->depthBias);
    v38 = (int)v26;
    v27 = (int)v26;
    do
    {
      v28 = (float *)&v40;
      v29 = (unsigned __int16 **)&v41[v6 * 4];
      for ( j = 2; j != 0; --j )
      {
        v31 = **v29;
        if ( v31 <= v27 )
        {
          if ( v31 == v27 )
          {
            v32 = *v28;
            *(double *)&v5 = v26;
            v5 = floor(x: v5);
            v8 = (float)((float)((float)((float)((float)1.0 - (float)((float)v26 - (float)*(double *)&v5)) * v39[v6 + 4])
                               * (float)v32)
                       + (float)v8);
          }
        }
        else
        {
          v8 = (float)((float)(v39[v6 + 4] * *v28) + (float)v8);
        }
        v29 += 2;
        ++v28;
      }
      ++v6;
    }
    while ( v6 < 2 );
    v3 = v8;
  }
  else
  {
    v3 = 1.0;
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?SamplesForPoint@ambientMap_t@@QBAXABVidVec3@@QAHQAUambientSample_t@@@Z
// EA  : 0x828D2870
// RVA : 0x008D2870
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ambientMap_t::SamplesForPoint(
        ambientMap_t *this,
        const idVec3 *worldPoint,
        int *cube,
        ambientSample_t *cubeSamples)
{
  int v4; // r2 OVERLAPPED
  ambientNode_t *nodes; // r26
  double x; // fp0
  double y; // fp13
  double z; // fp12
  unsigned int v11; // r29
  int v12; // r25
  unsigned int v13; // r28
  int v14; // r30
  unsigned int v15; // r27
  ambientNode_t *v16; // r5
  unsigned int v17; // r11
  unsigned int v18; // r10
  unsigned int v19; // r9
  int v20; // r8
  bool v21; // r4
  int v22; // r6
  char v23; // r29
  int v24; // r4
  ambientNode_t *v25; // r31
  int v26; // r8
  int v27; // r11
  int v28; // r6
  int v29; // r9
  int v30; // r10
  int v31; // r7
  int v32; // r4
  int v33; // r5
  unsigned int v34; // r30
  int v35; // r27
  unsigned int *v36; // r11
  ambientSample_t *samples; // r7
  int v38; // r11
  int i; // ctr
  int v42; // r10
  int v43; // ctr
  char *v44; // r11
  int v45; // r31
  int *v46; // r9
  int v47; // r30
  int v48; // r29
  int j; // ctr
  unsigned int v50; // r6
  __int128 v51; // r5
  int v52; // r7
  __int64 v53; // r9
  int v54; // r3
  char *v55; // r31
  int *v56; // r4
  char *v57; // r10
  char *v58; // r11
  int v59; // ctr
  int v60; // r6
  __int128 v61; // r30
  __int64 v62; // r9
  int v63; // r9
  int v64; // r8
  int v65; // r7
  int v66; // [sp+50h] [-1D0h] BYREF
  int v67; // [sp+54h] [-1CCh] BYREF
  int v68; // [sp+58h] [-1C8h] BYREF
  int v69; // [sp+5Ch] [-1C4h]
  int v70; // [sp+60h] [-1C0h]
  int v71; // [sp+64h] [-1BCh]
  int v72; // [sp+6Ch] [-1B4h] BYREF
  unsigned int v73; // [sp+70h] [-1B0h] BYREF
  unsigned int v74; // [sp+74h] [-1ACh] BYREF
  unsigned int v75; // [sp+78h] [-1A8h]
  unsigned int v76; // [sp+7Ch] [-1A4h]
  unsigned int v77; // [sp+80h] [-1A0h]
  unsigned int v78; // [sp+84h] [-19Ch]
  unsigned int v79; // [sp+88h] [-198h]
  unsigned int v80; // [sp+8Ch] [-194h]
  __int16 *v81; // [sp+90h] [-190h] BYREF
  char v82; // [sp+94h] [-18Ch] BYREF
  int v83; // [sp+B0h] [-170h]
  int v85; // [sp+BCh] [-164h]
  int v87; // [sp+C4h] [-15Ch]
  int v89; // [sp+CCh] [-154h]
  char v90; // [sp+D0h] [-150h] BYREF
  char v91; // [sp+F8h] [-128h] BYREF
  char v92; // [sp+118h] [-108h] BYREF

  nodes = this->nodes;
  if ( nodes != nullptr )
  {
    x = worldPoint->x;
    y = worldPoint->y;
    z = worldPoint->z;
    v87 = (int)x;
    v85 = (int)y;
    v89 = (int)z;
    v12 = -32768;
    v13 = (int)y;
    v14 = 0;
    v15 = (int)z;
    v66 = -32768;
    v67 = -32768;
    v68 = -32768;
    v69 = 0x8000;
    v70 = 0x8000;
    v71 = 0x8000;
    while ( 1 )
    {
      v16 = &nodes[v14];
      v17 = (v69 + v12) / 2;
      v18 = (v70 + v67) / 2;
      v19 = (v71 + v68) / 2;
      v11 = (int)x;
      v20 = ((((v11 ^ v17) & 0x80000000) == 0) + (v17 >= v11)) & 1;
      v21 = ((v15 ^ v19) & 0x80000000) == 0;
      v22 = (v21 + (v19 >= v15)) & 1;
      v14 = v16->children[(2 * ((2 * v22) | ((((v13 ^ v18) & 0x80000000) == 0) + (v18 >= v13)) & 1)) | v20];
      if ( (v14 & 0x8000) != 0 )
        break;
      *(&v66 + 3 * !(((((v11 ^ v17) & 0x80000000) == 0) + (v17 >= v11)) & 1)) = v17;
      *(&v67 + 3 * !(((((v13 ^ v18) & 0x80000000) == 0) + (v18 >= v13)) & 1)) = v18;
      *(&v68 + 3 * !((v21 + (v19 >= v15)) & 1)) = v19;
      v12 = v66;
    }
    v23 = 1;
    v24 = 0;
    v25 = v16;
    while ( (v25->children[0] & 0x8000) != 0 )
    {
      ++v24;
      v25 = (ambientNode_t *)((char *)v25 + 2);
      if ( v24 >= 8 )
        goto LABEL_11;
    }
    v23 = 0;
LABEL_11:
    if ( v23 != 0 )
    {
      v26 = v16->children[0] & 0x7FFF;
      v27 = v16->children[2] & 0x7FFF;
      v28 = v16->children[1] & 0x7FFF;
      v29 = v16->children[3] & 0x7FFF;
      v30 = v16->children[5];
      v31 = v16->children[6];
      v32 = v16->children[4] & 0x7FFF;
      v33 = v16->children[7];
      v73 = v26;
      v74 = v28;
      v75 = v27;
      v76 = v29;
      v77 = v32;
      v78 = v30 & 0xFFFF7FFF;
      v79 = v31 & 0xFFFF7FFF;
      v80 = v33 & 0xFFFF7FFF;
    }
    else
    {
      v34 = v14 & 0xFFFF7FFF;
      *(&v66 + 3 * (v20 ^ 1)) = v17;
      *(&v67 + 3 * !(((((v13 ^ v18) & 0x80000000) == 0) + (v18 >= v13)) & 1)) = v18;
      v73 = v34;
      *(&v68 + 3 * (v22 ^ 1)) = v19;
      v74 = v34;
      v75 = v34;
      v76 = v34;
      v77 = v34;
      v78 = v34;
      v79 = v34;
      v80 = v34;
      v12 = v66;
    }
    v35 = 1;
    v36 = &v74;
    do
    {
      if ( *v36 == *(v36 - 1) )
        break;
      ++v35;
      ++v36;
    }
    while ( v35 < 8 );
    samples = this->samples;
    v83 = v35;
    if ( v35 > 0 )
    {
      v38 = 0;
      for ( i = v35; i != 0; --i )
      {
        _R6 = &v81;
        _R10 = abs32(*(unsigned int *)((char *)&v73 + v38 * 4));
        __asm { dcbt      r10, r6 }
        (&v81)[v38++] = (__int16 *)&samples[_R10];
      }
    }
    v42 = 0;
    v43 = 8;
    v44 = &v91;
    v45 = v81[11];
    v46 = &v72;
    v47 = v81[10];
    v48 = v81[9];
    do
    {
      *++v46 = 0;
      --v43;
    }
    while ( v43 != 0 );
    for ( j = 8; j != 0; --j )
    {
      v50 = *(&v67 + 3 * ((v42 >> 1) & 1));
      LODWORD(v51) = *(&v66 + (v42 & 1) + ((2 * v42) & 2));
      DWORD2(v51) = *(&v68 + 3 * ((v42 >> 2) & 1));
      DWORD1(v51) = v50;
      ++v42;
      *((_QWORD *)v44 + 3) = v51;
      *((_QWORD *)v44 + 4) = *(_QWORD *)(&v4 - 1);
      *((_QWORD *)v44 + 5) = __PAIR64__(v50, DWORD2(v51));
      DWORD2(v51) = v45 - DWORD2(v51);
      v52 = (*(_QWORD *)((char *)&v51 + 4) * *(_QWORD *)((char *)&v51 + 4)) >> 32;
      v44 += 24;
      DWORD1(v51) = v48 - *((_DWORD *)v44 + 1);
      v53 = *(_QWORD *)(&v4 - 1) * *(_QWORD *)(&v4 - 1);
      LODWORD(v53) = ((__PAIR64__(DWORD1(v51), DWORD1(v51)) * DWORD1(v51)) >> 32) + (v47 - v50) * (v47 - v50);
      *(_QWORD *)(v52 + 8) = v53;
    }
    v54 = 1;
    if ( v35 > 1 )
    {
      v55 = &v82;
      do
      {
        v56 = (int *)&v73;
        v57 = &v90;
        v58 = &v92;
        v59 = 8;
        v60 = *(__int16 *)(*(_DWORD *)v55 + 20);
        do
        {
          *(_QWORD *)((char *)&v61 + 4) = *(_QWORD *)v57;
          LODWORD(v61) = v60 - *((_DWORD *)v58 + 1);
          v62 = v61 * v61;
          LODWORD(v62) = (__PAIR64__(v61, v61) * (unsigned int)v61) >> 32;
          if ( (int)v62 < *((_DWORD *)v57 + 1) )
          {
            *(_QWORD *)v57 = v62;
            *v56 = v54;
          }
          v58 += 24;
          v57 += 8;
          ++v56;
          --v59;
        }
        while ( v59 != 0 );
        ++v54;
        v55 += 4;
      }
      while ( v54 < v35 );
    }
    memcpy(Dst: cubeSamples, Src: (&v81)[v73], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[1], Src: (&v81)[v74], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[2], Src: (&v81)[v75], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[3], Src: (&v81)[v76], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[4], Src: (&v81)[v77], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[5], Src: (&v81)[v78], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[6], Src: (&v81)[v79], Size: sizeof(ambientSample_t));
    memcpy(Dst: &cubeSamples[7], Src: (&v81)[v80], Size: sizeof(ambientSample_t));
    v63 = v67;
    v64 = v68;
    v65 = v69 - v12;
    *cube = v12;
    cube[3] = v65;
    cube[1] = v63;
    cube[2] = v64;
  }
  else
  {
    memset(Dst: cubeSamples, Val: 0, Size: 0xC0u);
    cube[2] = -32768;
    cube[1] = -32768;
    *cube = -32768;
    cube[3] = 0x10000;
  }
}


// ========================================================================
// ?AmbientSample@ambientMap_t@@QBAXABVidVec3@@PAUambientColors_t@@@Z
// EA  : 0x828D2E38
// RVA : 0x008D2E38
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ambientMap_t::AmbientSample(ambientMap_t *this, const idVec3 *worldPoint, ambientColors_t *lighting)
{
  __int64 v3; // r15 OVERLAPPED
  ambientSample_t *v7; // r27
  int i; // r28
  __int64 v9; // r14 OVERLAPPED
  int v10; // r17
  int v11; // r22
  int v12; // r21
  int v13; // r20
  int v14; // r19
  int v15; // r16
  int v16; // r18
  __int64 v17; // r10
  unsigned __int8 *v18; // r11
  char *v19; // r4 OVERLAPPED
  __int128 v20; // r8 OVERLAPPED
  __int64 v21; // fp9
  int v22; // r8
  double v23; // fp6
  int v24; // r7
  int v25; // r6
  int v26; // r5
  double v27; // fp3
  double v28; // fp4
  double v29; // fp2
  double v30; // fp13
  double v31; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp7
  double v35; // fp5
  double v36; // fp8
  double v37; // fp6
  double v38; // fp1
  double v39; // fp0
  int v40; // ctr
  double v41; // fp13
  double v42; // fp12
  double v43; // fp11
  double v44; // fp10
  double v45; // fp9
  double v46; // fp8
  double v47; // fp7
  int v48; // r4
  int v49; // r3
  int v50; // r30
  int v51; // r29
  int v52; // r28
  int v53; // r27
  int v54; // r26
  int v55; // r25
  int v56; // r24
  int v57; // r23
  int v58; // r31
  int v59; // r16
  __int64 v60; // r17
  __int64 v61; // fp6
  __int64 v62; // fp5
  __int64 v63; // fp4
  double v64; // fp2
  __int128 v65; // r17
  __int64 v66; // fp6
  __int64 v67; // fp5
  __int64 v68; // fp1
  __int64 v69; // fp4
  int v70; // r10
  __int64 v71; // r17
  int v72; // r15
  __int64 v73; // fp2
  double v74; // fp6
  double v75; // fp5
  double v76; // fp3
  int v77; // [sp+68h] [-238h]
  int v78; // [sp+6Ch] [-234h]
  __int64 v79; // [sp+70h] [-230h] BYREF
  unsigned int v80; // [sp+78h] [-228h]
  int v81; // [sp+7Ch] [-224h]
  __int64 v82; // [sp+80h] [-220h]
  __int64 v83; // [sp+88h] [-218h]
  __int64 v84; // [sp+90h] [-210h]
  __int64 v85; // [sp+98h] [-208h]
  __int64 v86; // [sp+A0h] [-200h]
  __int64 v87; // [sp+A8h] [-1F8h]
  __int64 v88; // [sp+B0h] [-1F0h]
  __int64 v89; // [sp+B8h] [-1E8h]
  __int64 v90; // [sp+C0h] [-1E0h]
  __int64 v91; // [sp+C8h] [-1D8h]
  __int64 v92; // [sp+D0h] [-1D0h]
  __int64 v93; // [sp+D8h] [-1C8h]
  __int64 v94; // [sp+E0h] [-1C0h]
  __int64 v95; // [sp+E8h] [-1B8h]
  __int64 v96; // [sp+F0h] [-1B0h]
  __int64 v97; // [sp+F8h] [-1A8h]
  __int64 v98; // [sp+100h] [-1A0h]
  __int64 v99; // [sp+108h] [-198h]
  __int64 v100; // [sp+110h] [-190h]
  __int64 v101; // [sp+118h] [-188h]
  __int64 v102; // [sp+120h] [-180h]
  ambientSample_t v103; // [sp+130h] [-170h] BYREF
  char v104; // [sp+148h] [-158h] BYREF
  char v105; // [sp+15Eh] [-142h] BYREF
  char v106; // [sp+15Fh] [-141h] BYREF
  char v107; // [sp+160h] [-140h] BYREF
  char v108; // [sp+176h] [-12Ah] BYREF
  char v109; // [sp+177h] [-129h] BYREF
  char v110; // [sp+178h] [-128h] BYREF
  char v111; // [sp+18Eh] [-112h] BYREF
  char v112; // [sp+18Fh] [-111h] BYREF
  char v113; // [sp+190h] [-110h] BYREF
  char v114; // [sp+1A6h] [-FAh] BYREF
  char v115; // [sp+1A7h] [-F9h] BYREF
  char v116; // [sp+1A8h] [-F8h] BYREF
  char v117; // [sp+1BEh] [-E2h] BYREF
  char v118; // [sp+1BFh] [-E1h] BYREF
  char v119; // [sp+1C0h] [-E0h] BYREF
  char v120; // [sp+1D6h] [-CAh] BYREF
  char v121; // [sp+1D7h] [-C9h] BYREF
  char v122; // [sp+1D8h] [-C8h] BYREF

  if ( this->useForcedColors )
  {
    *lighting = this->forcedColors;
  }
  else if ( this->data != nullptr )
  {
    v7 = &v103;
    for ( i = 7; i >= 0; --i )
      memset(Dst: v7++, Val: 0, Size: 0x12u);
    ambientMap_t::SamplesForPoint(this, worldPoint, cube: (int *)&v79, cubeSamples: &v103);
    v10 = &v105 - (char *)lighting;
    v11 = &v120 - (char *)lighting;
    v77 = &v105 - (char *)lighting;
    v12 = &v117 - (char *)lighting;
    v13 = &v114 - (char *)lighting;
    v14 = &v111 - (char *)lighting;
    v15 = (char *)&v103.origin[2] - (char *)lighting;
    v78 = (char *)&v103.origin[2] - (char *)lighting;
    v16 = &v108 - (char *)lighting;
    HIDWORD(v17) = &v103.colors.channels[0][1];
    v18 = &lighting->channels[0][2];
    v19 = &v109;
    DWORD2(v20) = HIDWORD(v79);
    *(_QWORD *)&v20 = __PAIR64__(v80, v79);
    LODWORD(v20) = HIDWORD(v79);
    v21 = v20;
    DWORD2(v20) = v81;
    v22 = &v121 - (char *)lighting;
    v23 = (double)*(__int64 *)((char *)&v20 + 4);
    v24 = &v118 - (char *)lighting;
    v25 = &v115 - (char *)lighting;
    v27 = (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79)) * (float)((float)1.0 / (float)v23));
    v28 = (float)((float)(worldPoint->x - (float)v21) * (float)((float)1.0 / (float)v23));
    v29 = (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1)) * (float)((float)1.0 / (float)v23));
    v32 = (float)((float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1)) * (float)((float)1.0 / (float)v23))
                * (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79)) * (float)((float)1.0 / (float)v23)));
    v33 = (float)((float)((float)1.0 - (float)((float)(worldPoint->x - (float)v21) * (float)((float)1.0 / (float)v23)))
                * (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1)) * (float)((float)1.0 / (float)v23)));
    v30 = (float)((float)1.0
                - (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79)) * (float)((float)1.0 / (float)v23)));
    v34 = (float)((float)((float)1.0 - (float)((float)(worldPoint->x - (float)v21) * (float)((float)1.0 / (float)v23)))
                * (float)((float)1.0
                        - (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1))
                                * (float)((float)1.0 / (float)v23))));
    v35 = (float)((float)((float)1.0 - (float)((float)(worldPoint->x - (float)v21) * (float)((float)1.0 / (float)v23)))
                * (float)((float)1.0
                        - (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79))
                                * (float)((float)1.0 / (float)v23))));
    v31 = (float)((float)1.0
                - (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1)) * (float)((float)1.0 / (float)v23)));
    v36 = (float)((float)((float)1.0
                        - (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79))
                                * (float)((float)1.0 / (float)v23)))
                * (float)((float)1.0
                        - (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1))
                                * (float)((float)1.0 / (float)v23))));
    v37 = (float)((float)((float)1.0
                        - (float)((float)(worldPoint->z - (float)*(__int64 *)(&v19 - 1))
                                * (float)((float)1.0 / (float)v23)))
                * (float)((float)(worldPoint->y - (float)__SPAIR64__(v80, v79)) * (float)((float)1.0 / (float)v23)));
    v26 = &v112 - (char *)lighting;
    v38 = (float)((float)v30 * (float)v29);
    v39 = (float)((float)v32 * (float)v28);
    v40 = 6;
    v41 = (float)((float)v33 * (float)v27);
    v42 = (float)((float)v35 * (float)v31);
    v43 = (float)((float)v36 * (float)v28);
    v44 = (float)((float)v34 * (float)v27);
    v45 = (float)((float)v37 * (float)v28);
    v46 = (float)((float)v35 * (float)v29);
    v47 = (float)((float)v38 * (float)v28);
    v48 = &v109 - (char *)lighting;
    v49 = &v106 - (char *)lighting;
    v50 = (char *)&v103.origin[2] + 1 - (char *)lighting;
    v51 = &v122 - (char *)lighting;
    v52 = &v119 - (char *)lighting;
    v53 = &v116 - (char *)lighting;
    v54 = &v113 - (char *)lighting;
    v55 = &v110 - (char *)lighting;
    v56 = &v107 - (char *)lighting;
    v57 = &v104 - (char *)lighting;
    v58 = (char *)&v103 - (char *)lighting;
    while ( 1 )
    {
      LODWORD(v17) = v18[v15];
      v59 = v18[v16];
      LODWORD(v60) = v18[v10];
      LODWORD(v3) = v18[v14];
      v61 = v17;
      v62 = *(__int64 *)((char *)&v3 - 4);
      LODWORD(v17) = v3;
      HIDWORD(v60) = v18[v12];
      LODWORD(v3) = v18[v11];
      v102 = v17;
      v63 = v17;
      v90 = v60;
      v64 = (double)v60;
      LODWORD(v17) = *(unsigned __int8 *)(HIDWORD(v17) - 1);
      LODWORD(v60) = v18[v13];
      v101 = *(__int64 *)((char *)&v3 - 4);
      v94 = v17;
      v86 = v60;
      v84 = v3;
      LODWORD(v17) = (int)(float)((float)((float)v17 * (float)v42)
                                + (float)((float)((float)v3 * (float)v39)
                                        + (float)((float)((float)*(__int64 *)((char *)&v3 - 4) * (float)v41)
                                                + (float)((float)((float)v60 * (float)v47)
                                                        + (float)((float)((float)v63 * (float)v46)
                                                                + (float)((float)((float)v62 * (float)v45)
                                                                        + (float)((float)((float)v61 * (float)v43)
                                                                                + (float)((float)v64 * (float)v44))))))));
      if ( (int)v17 >= 0 )
      {
        if ( (int)v17 > 255 )
          LOBYTE(v17) = -1;
      }
      else
      {
        LOBYTE(v17) = 0;
      }
      DWORD2(v65) = v18[v48];
      LODWORD(v65) = v18[v49];
      DWORD1(v65) = v18[v26];
      LODWORD(v9) = v18[v25];
      *(v18 - 2) = v17;
      v88 = *(_QWORD *)((char *)&v65 + 4);
      v66 = *(_QWORD *)((char *)&v65 + 4);
      DWORD2(v65) = v18[v50];
      v92 = v65;
      v96 = *(__int64 *)((char *)&v9 - 4);
      v67 = *(__int64 *)((char *)&v9 - 4);
      v68 = v65;
      LODWORD(v65) = DWORD2(v65);
      v82 = v9;
      v100 = v65;
      v69 = v9;
      LODWORD(v9) = v18[v24];
      DWORD1(v65) = v18[v22];
      LODWORD(v65) = (unsigned __int8)*(_BYTE *)HIDWORD(v17);
      DWORD2(v65) = v9;
      v83 = v9;
      v85 = v65;
      v98 = *(__int64 *)((char *)&v9 - 4);
      v70 = (int)(float)((float)((float)(__int64)v65 * (float)v42)
                       + (float)((float)((float)*(__int64 *)((char *)&v9 - 4) * (float)v39)
                               + (float)((float)((float)v9 * (float)v41)
                                       + (float)((float)((float)v69 * (float)v47)
                                               + (float)((float)((float)v67 * (float)v46)
                                                       + (float)((float)((float)v66 * (float)v45)
                                                               + (float)((float)((float)v100 * (float)v43)
                                                                       + (float)((float)v68 * (float)v44))))))));
      if ( v70 >= 0 )
      {
        if ( v70 > 255 )
          LOBYTE(v70) = -1;
      }
      else
      {
        LOBYTE(v70) = 0;
      }
      LODWORD(v71) = v18[v57];
      v72 = v18[v54];
      HIDWORD(v71) = v18[v58];
      HIDWORD(v3) = v18[v55];
      v97 = *(__int64 *)((char *)&v3 + 4);
      v93 = v71;
      v73 = v71;
      LODWORD(v71) = v18[v53];
      v95 = *(__int64 *)((char *)&v3 - 4);
      HIDWORD(v71) = v18[v56];
      v87 = v3;
      v74 = (double)v3;
      LODWORD(v3) = v18[v52];
      v89 = v71;
      LODWORD(v71) = HIDWORD(v71);
      v99 = v3;
      v91 = v71;
      v75 = (double)v89;
      v76 = (double)v71;
      HIDWORD(v71) = v18[v51];
      *(v18 - 1) = v70;
      v79 = *(__int64 *)((char *)&v3 - 4);
      LODWORD(v17) = (int)(float)((float)((float)*(__int64 *)((char *)&v3 - 4) * (float)v39)
                                + (float)((float)((float)v3 * (float)v41)
                                        + (float)((float)((float)v75 * (float)v47)
                                                + (float)((float)((float)v74 * (float)v46)
                                                        + (float)((float)((float)v97 * (float)v45)
                                                                + (float)((float)((float)v76 * (float)v44)
                                                                        + (float)((float)((float)v95 * (float)v42)
                                                                                + (float)((float)v73 * (float)v43))))))));
      if ( (int)v17 >= 0 )
      {
        if ( (int)v17 > 255 )
          LOBYTE(v17) = -1;
      }
      else
      {
        LOBYTE(v17) = 0;
      }
      *v18 = v17;
      HIDWORD(v17) += 3;
      v18 += 3;
      if ( --v40 == 0 )
        break;
      v15 = v78;
      v10 = v77;
    }
  }
  else
  {
    memset(Dst: lighting, Val: 0, Size: sizeof(ambientColors_t));
  }
}


// ========================================================================
// ?CalculateLightContribution@@YA_NABV?$idODSObject@VidRenderLightCommitted@@@@PBUshadowMap_t@@ABVidVec3@@AAV3@3@Z
// EA  : 0x828D33C8
// RVA : 0x008D33C8
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

int __fastcall CalculateLightContribution(
        const idODSObject<idRenderLightCommitted> *light,
        shadowMap_t *shadowMap,
        const idVec3 *samplePoint,
        idVec3 *lightDir,
        idVec3 *lightColor)
{
  const idRenderLightCommitted *objectPtr; // r11
  double v11; // fp12
  double v12; // fp11
  double v13; // fp9
  lightType_t lightType; // r10
  double v15; // fp30
  double v16; // fp31
  double v17; // fp12
  double v19; // fp12
  double v20; // fp8
  double v21; // fp6
  double v22; // fp10
  double v23; // fp9
  idVec4 v24; // [sp+50h] [-50h] BYREF

  idRenderMatrix::TransformPoint(this: &light->objectPtr->baseLightProject, in: samplePoint, out: &v24);
  objectPtr = light->objectPtr;
  v11 = (float)(v24.x * (float)((float)1.0 / v24.w));
  v12 = (float)(v24.y * (float)((float)1.0 / v24.w));
  v13 = (float)(v24.z * (float)((float)1.0 / v24.w));
  lightType = light->objectPtr->r.lightType;
  if ( lightType == LIGHT_PARALLEL )
  {
    v15 = 0.0;
    if ( v11 < 0.0 || v11 > 1.0 || v12 < 0.0 || v12 > 1.0 || v13 < 0.0 || v13 > 1.0 )
      goto LABEL_17;
    v16 = 1.0;
    goto LABEL_23;
  }
  v17 = (float)((float)((float)((float)((float)(v24.y * (float)((float)1.0 / v24.w)) - (float)0.5)
                              * (float)((float)(v24.y * (float)((float)1.0 / v24.w)) - (float)0.5))
                      + (float)((float)((float)(v24.x * (float)((float)1.0 / v24.w)) - (float)0.5)
                              * (float)((float)(v24.x * (float)((float)1.0 / v24.w)) - (float)0.5)))
              * (float)4.0);
  if ( v17 >= 1.0 )
  {
LABEL_10:
    lightColor->z = 0.0;
    lightColor->y = 0.0;
    lightColor->x = 0.0;
    lightDir->z = 0.0;
    lightDir->y = 0.0;
    lightDir->x = 0.0;
    return 0;
  }
  if ( v17 >= 0.25 )
    v16 = (float)-(float)((float)((float)((float)__fsqrts(v17) - (float)0.5) * (float)2.0) - (float)1.0);
  else
    v16 = 1.0;
  v15 = 0.0;
  if ( lightType == LIGHT_SPOT )
  {
    if ( v13 < 0.0 || v13 > 1.0 )
      goto LABEL_17;
  }
  else if ( lightType == LIGHT_POINT )
  {
    v19 = __fabs((float)((float)((float)(v24.z * (float)((float)1.0 / v24.w)) - (float)0.5) * (float)2.0));
    if ( v19 > 1.0 )
      goto LABEL_10;
    if ( v19 >= 0.5 )
      v16 = (float)((float)-(float)((float)((float)((float)v19 - (float)0.5) * (float)2.0) - (float)1.0) * (float)v16);
  }
  if ( v16 <= 0.0 )
    goto LABEL_17;
LABEL_23:
  if ( lightType != LIGHT_PARALLEL )
  {
    v20 = (float)(objectPtr->globalLightOrigin.y - samplePoint->y);
    v21 = (float)(objectPtr->globalLightOrigin.z - samplePoint->z);
    lightDir->x = objectPtr->globalLightOrigin.x - samplePoint->x;
    lightDir->y = v20;
    lightDir->z = v21;
    goto LABEL_27;
  }
  v16 = (float)(shadowMap_t::ShadowSample(this: shadowMap, worldPoint: samplePoint) * (float)v16);
  if ( v16 == v15 )
  {
LABEL_17:
    lightColor->z = v15;
    lightColor->y = v15;
    lightColor->x = v15;
    lightDir->z = v15;
    lightDir->y = v15;
    lightDir->x = v15;
    return 0;
  }
  objectPtr = light->objectPtr;
  lightDir->x = light->objectPtr->r.lightCenter.x;
  lightDir->y = objectPtr->r.lightCenter.y;
  lightDir->z = objectPtr->r.lightCenter.z;
LABEL_27:
  v22 = (float)(objectPtr->currentColor.y * (float)v16);
  v23 = (float)(objectPtr->currentColor.z * (float)v16);
  lightColor->x = objectPtr->currentColor.x * (float)v16;
  lightColor->y = v22;
  lightColor->z = v23;
  idVec3::NormalizeFast(this: lightDir);
  return 1;
}


// ========================================================================
// ?LocalLighting@@YAXPBUapproximateLightingParms_t@@@Z
// EA  : 0x828D3648
// RVA : 0x008D3648
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

void __fastcall LocalLighting(const approximateLightingParms_t *parms)
{
  int v2; // r11
  int i; // ctr
  int numLights; // r5
  int v5; // r7
  int v6; // r8
  long double v7; // fp4
  double v8; // fp2
  const idRenderLightCommitted **lights; // r6
  int v10; // r9
  float *p_w; // r10
  const idRenderLightCommitted *v12; // r11
  double y; // fp0
  double v14; // fp5
  double z; // fp13
  double v16; // fp1
  double x; // fp12
  double v18; // fp31
  double v19; // fp11
  double v20; // fp6
  double v21; // fp5
  double v22; // fp5
  double v23; // fp8
  double v24; // fp31
  double v25; // fp6
  double v26; // fp1
  double v27; // fp10
  double v28; // fp9
  double v29; // fp27
  double v30; // fp26
  double v31; // fp6
  int v32; // r28
  double v35; // fp5
  double v36; // fp8
  double v37; // fp5
  int j; // r31
  long double v39; // fp2
  int v40; // r29
  long double v41; // fp2
  approximateLighting_t v42; // [sp+50h] [-100h] BYREF

  if ( parms->contributions != nullptr )
  {
    v2 = 0;
    for ( i = 16; i != 0; --i )
      parms->contributions[v2++].light = nullptr;
  }
  numLights = parms->numLights;
  v5 = 0;
  v6 = 0;
  *((double *)&v7 + 1) = 0.0;
  v42.primeLightColor.z = 0.0;
  *(double *)&v7 = 0.0;
  v42.primeLightColor.y = 0.0;
  v8 = 0.0;
  v42.primeLightDir.w = 0.0;
  v42.primeLightColor.x = 0.0;
  v42.primeLightColor.w = 0.0;
  v42.channelLighting[0].w = 0.0;
  v42.channelLighting[0].z = 0.0;
  v42.channelLighting[0].y = 0.0;
  v42.channelLighting[0].x = 0.0;
  v42.channelLighting[1].w = 0.0;
  v42.channelLighting[1].z = 0.0;
  v42.channelLighting[1].y = 0.0;
  v42.channelLighting[1].x = 0.0;
  v42.channelLighting[2].w = 0.0;
  v42.channelLighting[2].z = 0.0;
  v42.channelLighting[2].y = 0.0;
  v42.channelLighting[2].x = 0.0;
  v42.channelLighting[3].w = 0.0;
  v42.channelLighting[3].z = 0.0;
  v42.channelLighting[3].y = 0.0;
  v42.channelLighting[3].x = 0.0;
  v42.channelLighting[4].w = 0.0;
  v42.channelLighting[4].z = 0.0;
  v42.channelLighting[4].y = 0.0;
  v42.channelLighting[4].x = 0.0;
  v42.channelLighting[5].w = 0.0;
  v42.channelLighting[5].z = 0.0;
  v42.channelLighting[5].y = 0.0;
  v42.channelLighting[5].x = 0.0;
  v42.lightingModel.x = 1.0;
  if ( numLights > 0 )
  {
    lights = parms->lights;
    v10 = 0;
    p_w = &v42.primeLightColor.w;
    do
    {
      v12 = lights[v10];
      if ( v12->r.lightFalloff == LIGHT_FALLOFF_RADIAL )
      {
        if ( v5 >= 3 )
          break;
        y = v12->globalLightOrigin.y;
        v14 = (float)(parms->samplePoint.y - v12->globalLightOrigin.y);
        z = v12->globalLightOrigin.z;
        v16 = (float)(parms->samplePoint.z - v12->globalLightOrigin.z);
        x = v12->globalLightOrigin.x;
        v18 = (float)(parms->samplePoint.x - v12->globalLightOrigin.x);
        v19 = v12->r.lightRadius.x;
        v20 = (float)(v12->r.lightRadius.x - (float)1.0);
        v21 = __fsqrts((float)((float)((float)v18 * (float)v18)
                             + (float)((float)((float)v16 * (float)v16) + (float)((float)v14 * (float)v14))));
        if ( v21 <= v20 )
          v20 = v21;
        v22 = v12->currentColor.x;
        v24 = v12->currentColor.z;
        ++v5;
        v25 = (float)((float)1.0 - (float)((float)v20 / v12->r.lightRadius.x));
        v26 = (float)((float)(v12->globalLightOrigin.x - parms->samplePoint.x) * (float)v25);
        v23 = v12->currentColor.y;
        v27 = (float)((float)(v12->globalLightOrigin.y - parms->samplePoint.y) * (float)v25);
        v28 = (float)((float)(v12->globalLightOrigin.z - parms->samplePoint.z) * (float)v25);
        v29 = (float)(v12->currentColor.x * (float)v25);
        v30 = (float)(v12->currentColor.y * (float)v25);
        v31 = (float)(v12->currentColor.z * (float)v25);
        v42.primeLightDir.x = (float)v26 + (float)v8;
        v42.primeLightDir.y = (float)v27 + (float)*(double *)&v7;
        v42.primeLightDir.z = (float)v28 + (float)*((double *)&v7 + 1);
        v42.primeLightColor.x = (float)v29 + v42.primeLightColor.x;
        v42.primeLightColor.y = v42.primeLightColor.y + (float)v30;
        v42.primeLightColor.z = v42.primeLightColor.z + (float)v31;
        p_w[1] = x;
        p_w[2] = y;
        p_w[3] = z;
        p_w[5] = v22;
        p_w[6] = v23;
        p_w[7] = v24;
        p_w += 8;
        *p_w = v19;
        *((double *)&v7 + 1) = v42.primeLightDir.z;
        *(double *)&v7 = v42.primeLightDir.y;
        v8 = v42.primeLightDir.x;
      }
      ++v6;
      ++v10;
    }
    while ( v6 < numLights );
  }
  v32 = 0;
  _FP8 = (float)((float)((float)((float)v8 * (float)v8)
                       + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1))
                               + (float)((float)*(double *)&v7 * (float)*(double *)&v7)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f9, f13 }
  v35 = __frsqrte(_FP6);
  v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                                      * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7)))
                                                                                              * (float)0.5))
                                                                              * (float)v35)
                                                                      - (float)1.5)
                                                      * (float)v35)
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)((float)*((double *)&v7 + 1)
                                                                              * (float)*((double *)&v7 + 1))
                                                                      + (float)((float)*(double *)&v7
                                                                              * (float)*(double *)&v7)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v35
                                                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                                                              + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7)))
                                                                                      * (float)0.5))
                                                                      * (float)v35)
                                                              - (float)1.5)
                                              * (float)v35))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v35
                                                      * (float)((float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)((float)*((double *)&v7 + 1)
                                                                                      * (float)*((double *)&v7 + 1))
                                                                              + (float)((float)*(double *)&v7
                                                                                      * (float)*(double *)&v7)))
                                                              * (float)0.5))
                                              * (float)v35)
                                      - (float)1.5)
                      * (float)v35));
  v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                              * (float)v35)
                                                                                      * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7))) * (float)0.5)) * (float)v35) - (float)1.5)
                                                                                      * (float)v35))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v35
                                                                                              * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)((float)*((double *)&v7 + 1) * (float)*((double *)&v7 + 1)) + (float)((float)*(double *)&v7 * (float)*(double *)&v7))) * (float)0.5))
                                                                                      * (float)v35)
                                                                              - (float)1.5)
                                                              * (float)v35))
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)((float)*((double *)&v7 + 1)
                                                                              * (float)*((double *)&v7 + 1))
                                                                      + (float)((float)*(double *)&v7
                                                                              * (float)*(double *)&v7)))
                                                      * (float)0.5))
                                      * (float)v36)
                              - (float)1.5)
              * (float)v36);
  v42.primeLightDir.x = (float)v37 * (float)v8;
  v42.primeLightDir.y = (float)*(double *)&v7 * (float)v37;
  v42.primeLightDir.z = (float)*((double *)&v7 + 1) * (float)v37;
  do
  {
    for ( j = 0; j < 3; ++j )
    {
      *((double *)&v39 + 1) = 2.200000047683716;
      v40 = 4 * (v32 + j);
      *(double *)&v39 = *(float *)((char *)&v42.channelLighting[1].x + v40);
      v41 = pow(x: v39, y: v7);
      *(float *)((char *)&v42.channelLighting[1].x + v40) = *(double *)&v41;
    }
    v32 += 8;
  }
  while ( v32 < 24 );
  approximateLighting_t::operator=(this: parms->lighting, __that: &v42);
}


// ========================================================================
// ?ApproximateLightingJob@@YAXPBUapproximateLightingParms_t@@@Z
// EA  : 0x828D3928
// RVA : 0x008D3928
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ApproximateLightingJob(const approximateLightingParms_t *parms, int a2, __int64 a3, __int64 a4)
{
  int v4; // r2 OVERLAPPED
  __int64 v5; // r30 OVERLAPPED
  int v6; // r11
  int i; // ctr
  BOOL noAmbient; // r10
  int v9; // r10
  double v10; // fp0
  double z; // fp28
  double y; // fp29
  double x; // fp30
  double v14; // fp14
  double v15; // fp15
  double v16; // fp16
  double v17; // fp17
  double v18; // fp18
  double v19; // fp19
  double v20; // fp20
  double v21; // fp21
  double v22; // fp22
  double v23; // fp23
  double v24; // fp25
  double v25; // fp26
  double v26; // fp27
  int v27; // r7 OVERLAPPED
  int v28; // r31
  __int128 v29; // r6 OVERLAPPED
  __int64 v30; // r9 OVERLAPPED
  __int64 v31; // r11 OVERLAPPED
  __int64 v32; // fp12
  __int64 v33; // fp10
  double v34; // fp9
  double v35; // fp7
  int v36; // r7
  double v37; // fp4
  double v38; // fp1
  double v39; // fp11
  double v40; // fp8
  double v41; // fp5
  int v42; // r27
  char v43; // r24
  int v44; // r25
  int v45; // r28
  int v46; // r26
  int v47; // r30
  int v48; // r31
  int v49; // r10
  int v50; // r11
  double v51; // fp8
  double v52; // fp5
  double v53; // fp0
  double v54; // fp13
  float *v55; // r11
  double v56; // fp1
  int v57; // r10
  double v58; // fp11
  double v59; // fp10
  double v60; // fp9
  float *v61; // r11
  double v62; // fp5
  double v63; // fp4
  double v64; // fp0
  double v65; // fp13
  int v66; // ctr
  int v67; // r11
  double v68; // fp10
  double v69; // fp8
  double v70; // fp9
  double v71; // fp0
  double v72; // fp0
  double v73; // fp13
  double v74; // fp12
  double v75; // fp11
  double v76; // fp2
  double v77; // fp10
  double v78; // fp2
  double v79; // fp10
  double v82; // fp3
  double v83; // fp8
  double v84; // fp3
  double v85; // fp4
  int v86; // r11
  int j; // r8
  float *v88; // r10
  double v89; // fp10
  double v90; // fp8
  double v91; // fp9
  double v92; // fp13
  double v93; // fp12
  double v94; // fp11
  double v95; // fp0
  double v96; // fp0
  double v97; // fp10
  double v98; // fp13
  char *v99; // r10
  double v100; // fp0
  double v101; // fp10
  double v102; // fp9
  float *p_z; // r11
  int k; // ctr
  int v105; // r7
  __int64 v106; // r4
  double v107; // fp11
  double v108; // fp9
  double v109; // fp10
  double v110; // fp13
  double v111; // fp10
  idVec3 v112; // [sp+50h] [-360h] BYREF
  idVec3 v113; // [sp+60h] [-350h] BYREF
  char v114; // [sp+6Fh] [-341h] BYREF
  ambientColors_t v115; // [sp+70h] [-340h] BYREF
  __int64 v116; // [sp+88h] [-328h]
  __int64 v117; // [sp+90h] [-320h]
  approximateLighting_t v118; // [sp+A0h] [-310h] BYREF
  _QWORD v119[70]; // [sp+130h] [-280h] BYREF

  HIDWORD(v5) = parms;
  if ( parms->lightingModel == LM_LOCAL_LIGHTS )
  {
    LocalLighting(parms);
    return;
  }
  if ( parms->contributions != nullptr )
  {
    v6 = 0;
    for ( i = 16; i != 0; --i )
      parms->contributions[v6++].light = nullptr;
  }
  noAmbient = parms->noAmbient;
  memset(&v115, 0, sizeof(v115));
  if ( noAmbient )
    memset(&v115, 0, sizeof(v115));
  else
    ambientMap_t::AmbientSample(
      this: (ambientMap_t *)parms->ambientMap,
      worldPoint: &parms->samplePoint,
      lighting: &v115);
  v9 = *(unsigned __int8 *)(HIDWORD(v5) + 41);
  v10 = (float)(*(float *)(HIDWORD(v5) + 44) * (float)0.0039215689);
  v118.primeLightDir.w = 0.0;
  z = 0.0;
  v118.channelLighting[0].w = 0.0;
  y = 0.0;
  v118.channelLighting[0].z = 0.0;
  x = 0.0;
  v118.channelLighting[1].w = 0.0;
  v14 = 0.0;
  v118.channelLighting[0].y = 0.0;
  v15 = 0.0;
  v118.channelLighting[2].w = 0.0;
  v16 = 0.0;
  v118.channelLighting[0].x = 0.0;
  v17 = 0.0;
  v118.channelLighting[3].w = 0.0;
  v18 = 0.0;
  v118.channelLighting[1].z = 0.0;
  v19 = 0.0;
  v118.channelLighting[4].w = 0.0;
  v20 = 0.0;
  v118.channelLighting[1].y = 0.0;
  v21 = 0.0;
  v118.channelLighting[5].w = 0.0;
  v22 = 0.0;
  v118.channelLighting[1].x = 0.0;
  v23 = 0.0;
  v118.lightingModel.x = 0.0;
  v24 = 0.0;
  v118.channelLighting[2].z = 0.0;
  v25 = 0.0;
  v118.channelLighting[2].y = 0.0;
  v26 = 0.0;
  v118.primeLightColor.w = 0.0;
  v118.primeLightDir.z = 0.0;
  v118.primeLightDir.y = 0.0;
  v118.primeLightDir.x = 0.0;
  v118.channelLighting[2].x = 0.0;
  v118.channelLighting[3].z = 0.0;
  v118.channelLighting[3].y = 0.0;
  v118.channelLighting[3].x = 0.0;
  v118.channelLighting[4].z = 0.0;
  v118.channelLighting[4].y = 0.0;
  v118.channelLighting[4].x = 0.0;
  v118.channelLighting[5].z = 0.0;
  v118.channelLighting[5].y = 0.0;
  v118.channelLighting[5].x = 0.0;
  *(float *)&v117 = v10;
  if ( v9 != 0 )
  {
    LODWORD(a4) = v115.channels[1][0];
    v118.primeLightDir.w = 0.0;
    v117 = a4;
    v118.primeLightDir.z = 0.0;
    v118.primeLightDir.y = 0.0;
    v27 = v115.channels[0][1];
    v118.primeLightDir.x = 0.0;
    v28 = v115.channels[0][2];
    LODWORD(v29) = v115.channels[1][1];
    v118.primeLightColor.w = 0.0;
    HIDWORD(v30) = v115.channels[2][2];
    DWORD1(v29) = v115.channels[1][2];
    DWORD2(v29) = v115.channels[0][1];
    LODWORD(v31) = v115.channels[2][0];
    v118.primeLightColor.z = 0.0;
    HIDWORD(v31) = v115.channels[0][0];
    v118.primeLightColor.y = 0.0;
    v32 = v29;
    HIDWORD(v29) = v115.channels[0][0];
    v33 = v31;
    LODWORD(v30) = v115.channels[2][1];
    LODWORD(v29) = v115.channels[0][0];
    v118.primeLightColor.x = 0.0;
    LODWORD(v5) = v115.channels[3][1];
    LODWORD(v31) = v115.channels[3][0];
    HIDWORD(v31) = v115.channels[5][1];
    v34 = (double)v30;
    LODWORD(v30) = v115.channels[4][0];
    v35 = (double)v31;
    LODWORD(v31) = v115.channels[3][2];
    v116 = v31;
    DWORD2(v29) = v115.channels[5][2];
    v37 = (float)*(__int64 *)(&v4 - 1);
    *(_QWORD *)&v113.x = v5;
    v38 = (float)*(__int64 *)&v29;
    HIDWORD(v29) = v115.channels[4][1];
    v39 = (float)*(__int64 *)(&v27 - 1);
    HIDWORD(v30) = v115.channels[4][2];
    v119[2] = v30;
    v119[3] = *(_QWORD *)(&v4 - 1);
    v40 = (float)((float)*(__int64 *)&v27 * (float)v10);
    v36 = v115.channels[5][0];
    v119[1] = *(__int64 *)((char *)&v30 + 4);
    v119[0] = *(__int64 *)((char *)&v30 - 4);
    *(_QWORD *)&v112.x = *(_QWORD *)((char *)&v29 + 4);
    v118.channelLighting[0].y = v40;
    v118.channelLighting[1].x = (float)v117 * (float)v10;
    v117 = *(_QWORD *)((char *)&v29 - 4);
    v118.channelLighting[0].x = (float)v37 * (float)v10;
    v118.channelLighting[1].y = (float)v32 * (float)v10;
    v41 = (double)*(__int64 *)(&v4 - 1);
    v118.channelLighting[1].z = (float)v38 * (float)v10;
    v118.channelLighting[2].x = (float)v33 * (float)v10;
    HIDWORD(v29) = *(_DWORD *)HIDWORD(v5);
    v118.channelLighting[2].y = (float)v34 * (float)v10;
    v118.channelLighting[3].x = (float)v35 * (float)v10;
    v118.channelLighting[0].z = (float)*(__int64 *)((char *)&v5 - 4) * (float)v10;
    v118.channelLighting[2].z = (float)v39 * (float)v10;
    v118.channelLighting[3].y = (float)v5 * (float)v10;
    v118.channelLighting[3].z = (float)v31 * (float)v10;
    v118.channelLighting[4].y = (float)v41 * (float)v10;
    v118.channelLighting[4].x = (float)v30 * (float)v10;
    v118.channelLighting[4].z = (float)*(__int64 *)((char *)&v30 + 4) * (float)v10;
    v118.channelLighting[5].x = (float)*(__int64 *)((char *)&v29 - 4) * (float)v10;
    v118.channelLighting[5].y = (float)*(__int64 *)((char *)&v30 - 4) * (float)v10;
    v118.channelLighting[5].z = (float)*(__int64 *)((char *)&v29 + 4) * (float)v10;
    approximateLighting_t::operator=(this: (approximateLighting_t *)HIDWORD(v29), __that: &v118);
    return;
  }
  v42 = 0;
  v43 = 0;
  v44 = 0;
  if ( *(int *)(HIDWORD(v5) + 20) > 0 )
  {
    v45 = 0;
    v46 = 0;
    v47 = 0;
    do
    {
      v48 = *(_DWORD *)(v46 + *(_DWORD *)(HIDWORD(v5) + 16));
      v49 = *(_DWORD *)(v48 + 68);
      HIDWORD(v119[0]) = v48;
      if ( v49 == 5 || v49 == 6 || (v50 = 0, v49 == 3) )
        v50 = 1;
      if ( *(unsigned __int8 *)(HIDWORD(v5) + 42) == v50
        && v49 != 1
        && (unsigned __int8)CalculateLightContribution(
                              light: (const idODSObject<idRenderLightCommitted> *)v119,
                              shadowMap: *(shadowMap_t **)(HIDWORD(v5) + 12),
                              samplePoint: (const idVec3 *)(HIDWORD(v5) + 24),
                              lightDir: &v112,
                              lightColor: &v113) != 0 )
      {
        v51 = (float)(v113.z * *(float *)(HIDWORD(v5) + 56));
        v52 = *(float *)(v48 + 176);
        v53 = (float)(*(float *)(v48 + 168) * (float)(v113.x * *(float *)(HIDWORD(v5) + 56)));
        v54 = (float)(*(float *)(v48 + 172) * (float)(v113.y * *(float *)(HIDWORD(v5) + 56)));
        v113.x = *(float *)(v48 + 168) * (float)(v113.x * *(float *)(HIDWORD(v5) + 56));
        v113.y = v54;
        v113.z = (float)v52 * (float)v51;
        if ( v42 < 16 )
        {
          if ( *(_DWORD *)(HIDWORD(v5) + 4) != 0 )
          {
            *(_DWORD *)(v45 + *(_DWORD *)(HIDWORD(v5) + 4)) = *(_DWORD *)(v46 + *(_DWORD *)(HIDWORD(v5) + 16));
            v55 = (float *)(v45 + *(_DWORD *)(HIDWORD(v5) + 4));
            v55[1] = v53;
            v55[2] = v54;
            v55[3] = (float)v52 * (float)v51;
          }
          if ( *(_DWORD *)(v48 + 68) == 6 )
          {
            if ( v43 == 0 || *(_BYTE *)(v48 + 76) == 0 )
            {
              x = v112.x;
              y = v112.y;
              v26 = v53;
              z = v112.z;
              v25 = v54;
              v24 = (float)((float)v52 * (float)v51);
              v56 = 1.0;
              if ( *(_DWORD *)(v48 + 64) == 1 )
                v56 = CalcSpotShadowFactor(lightParms: (const idRenderLightParms *)(v48 + 8), dir: &v112);
              if ( *(_BYTE *)(v48 + 76) != 0 )
                v56 = 0.0;
              v118.primeLightColor.w = (float)1.0 - (float)v56;
              v43 = 1;
            }
          }
          else
          {
            v57 = *(unsigned __int8 *)(v48 + 76);
            v58 = v112.x;
            v59 = v112.y;
            v60 = v112.z;
            v61 = (float *)((char *)&v119[29] + v47);
            *(float *)((char *)&v119[28] + v47) = v112.x;
            ++v42;
            *(float *)((char *)&v119[4] + v47) = v53;
            v45 += 16;
            *(float *)((char *)&v119[4] + v47 + 4) = v54;
            *(float *)((char *)&v119[5] + v47) = (float)v52 * (float)v51;
            v47 += 12;
            *(v61 - 1) = v59;
            *v61 = v60;
            if ( v57 == 0 && v43 == 0 )
            {
              v62 = __fsqrts((float)((float)((float)v54 * (float)v54)
                                   + (float)((float)((float)v53 * (float)v53)
                                           + (float)((float)((float)v52 * (float)v51) * (float)((float)v52 * (float)v51)))));
              v63 = (float)((float)v62 * *(float *)(v48 + 180));
              v64 = (float)((float)v58 * (float)((float)v62 * *(float *)(v48 + 180)));
              v65 = (float)((float)v59 * (float)((float)v62 * *(float *)(v48 + 180)));
              v112.y = (float)v59 * (float)((float)v62 * *(float *)(v48 + 180));
              v112.x = v64;
              v112.z = (float)v60 * (float)v63;
              x = (float)((float)v64 + (float)x);
              y = (float)((float)v65 + (float)y);
              z = (float)(v112.z + (float)z);
            }
          }
        }
      }
      ++v44;
      v46 += 4;
    }
    while ( v44 < *(_DWORD *)(HIDWORD(v5) + 20) );
    v118.primeLightDir.z = z;
    v118.primeLightDir.y = y;
    v118.primeLightDir.x = x;
  }
  if ( v43 != 0 )
  {
    if ( v42 <= 0 )
      goto LABEL_70;
    v66 = v42;
    v67 = 0;
    do
    {
      v68 = *(float *)((char *)&v119[28] + v67);
      v69 = *(float *)((char *)&v119[29] + v67);
      v70 = *(float *)((char *)&v119[28] + v67 + 4);
      v71 = (float)((float)((float)__fabs(v70) + (float)__fabs(v68)) + (float)__fabs(v69));
      if ( v71 > idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        v72 = (float)((float)1.0 / (float)v71);
        v73 = *(float *)((char *)&v119[4] + v67);
        v74 = *(float *)((char *)&v119[4] + v67 + 4);
        v75 = *(float *)((char *)&v119[5] + v67);
        if ( v68 <= 0.0 )
        {
          v77 = -v68;
          v78 = (float)((float)(*(float *)((char *)&v119[5] + v67) * (float)v77) * (float)v72);
          v118.channelLighting[1].x = v118.channelLighting[1].x
                                    + (float)((float)(*(float *)((char *)&v119[4] + v67) * (float)v77) * (float)v72);
          v118.channelLighting[1].y = v118.channelLighting[1].y + (float)((float)((float)v74 * (float)v77) * (float)v72);
          v118.channelLighting[1].z = v118.channelLighting[1].z + (float)v78;
        }
        else
        {
          v76 = (float)((float)(*(float *)((char *)&v119[5] + v67) * *(float *)((char *)&v119[28] + v67)) * (float)v72);
          v118.channelLighting[0].x = v118.channelLighting[0].x
                                    + (float)((float)(*(float *)((char *)&v119[4] + v67)
                                                    * *(float *)((char *)&v119[28] + v67))
                                            * (float)v72);
          v118.channelLighting[0].y = v118.channelLighting[0].y + (float)((float)((float)v74 * (float)v68) * (float)v72);
          v118.channelLighting[0].z = v118.channelLighting[0].z + (float)v76;
        }
        if ( v70 <= 0.0 )
        {
          v17 = (float)((float)v17 + (float)((float)((float)v73 * (float)-v70) * (float)v72));
          v16 = (float)((float)v16 + (float)((float)((float)v74 * (float)-v70) * (float)v72));
          v15 = (float)((float)v15 + (float)((float)((float)v75 * (float)-v70) * (float)v72));
        }
        else
        {
          v118.channelLighting[2].y = v118.channelLighting[2].y + (float)((float)((float)v74 * (float)v70) * (float)v72);
          v118.channelLighting[2].z = v118.channelLighting[2].z + (float)((float)((float)v75 * (float)v70) * (float)v72);
          v14 = (float)((float)v14 + (float)((float)((float)v73 * (float)v70) * (float)v72));
        }
        if ( v69 <= 0.0 )
        {
          v23 = (float)((float)v23 + (float)((float)((float)v73 * (float)-v69) * (float)v72));
          v22 = (float)((float)v22 + (float)((float)((float)v74 * (float)-v69) * (float)v72));
          v21 = (float)((float)v21 + (float)((float)((float)v75 * (float)-v69) * (float)v72));
        }
        else
        {
          v20 = (float)((float)v20 + (float)((float)((float)v73 * (float)v69) * (float)v72));
          v19 = (float)((float)v19 + (float)((float)((float)v74 * (float)v69) * (float)v72));
          v18 = (float)((float)v18 + (float)((float)((float)v75 * (float)v69) * (float)v72));
        }
      }
      v67 += 12;
      --v66;
    }
    while ( v66 != 0 );
  }
  else
  {
    if ( z < 0.0 )
      z = 0.0;
    v79 = (float)(*(float *)(HIDWORD(v5) + 60) + (float)z);
    _FP6 = (float)((float)((float)((float)v79 * (float)v79)
                         + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f8, f7 }
    v82 = __frsqrte(_FP4);
    v83 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82
                                                                                        * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y)))
                                                                                                * (float)0.5))
                                                                                * (float)v82)
                                                                        - (float)1.5)
                                                        * (float)v82)
                                                * (float)((float)((float)((float)v79 * (float)v79)
                                                                + (float)((float)((float)x * (float)x)
                                                                        + (float)((float)y * (float)y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v82
                                                                                * (float)((float)((float)((float)v79 * (float)v79)
                                                                                                + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y)))
                                                                                        * (float)0.5))
                                                                        * (float)v82)
                                                                - (float)1.5)
                                                * (float)v82))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v82
                                                        * (float)((float)((float)((float)v79 * (float)v79)
                                                                        + (float)((float)((float)x * (float)x)
                                                                                + (float)((float)y * (float)y)))
                                                                * (float)0.5))
                                                * (float)v82)
                                        - (float)1.5)
                        * (float)v82));
    v84 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                                * (float)v82)
                                                                                        * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                        * (float)v82))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v82
                                                                                                * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y))) * (float)0.5))
                                                                                        * (float)v82)
                                                                                - (float)1.5)
                                                                * (float)v82))
                                                * (float)((float)((float)((float)v79 * (float)v79)
                                                                + (float)((float)((float)x * (float)x)
                                                                        + (float)((float)y * (float)y)))
                                                        * (float)0.5))
                                        * (float)v83)
                                - (float)1.5)
                * (float)v83);
    v118.primeLightDir.x = (float)v84 * (float)x;
    v118.primeLightDir.y = (float)y * (float)v84;
    v85 = (float)((float)v79 * (float)v84);
    v118.primeLightDir.z = (float)v79 * (float)v84;
    v118.primeLightDir.w = (float)v84 * (float)0.0;
    if ( v42 <= 0 )
      goto LABEL_70;
    v86 = 0;
    for ( j = v42; j != 0; --j )
    {
      a3 = *(_QWORD *)((char *)&v119[28] + v86 + 4);
      v88 = (float *)((char *)&v119[5] + v86);
      v112.x = *(float *)((char *)&v119[28] + v86);
      v89 = v112.x;
      *(_QWORD *)&v112.y = a3;
      v90 = *((float *)&a3 + 1);
      v91 = *(float *)&a3;
      if ( (float)((float)(*((float *)&a3 + 1) * (float)v85)
                 + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                         + (float)(*(float *)&a3 * (float)((float)y * (float)v84)))) <= 0.0 )
      {
        v92 = *(float *)((char *)&v119[4] + v86);
        v93 = *(v88 - 1);
        v94 = *v88;
      }
      else
      {
        v92 = (float)(*(float *)((char *)&v119[4] + v86)
                    * (float)((float)1.0
                            - (float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84))))));
        v93 = (float)((float)((float)1.0
                            - (float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84)))))
                    * *(v88 - 1));
        v94 = (float)((float)((float)1.0
                            - (float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84)))))
                    * *v88);
        v26 = (float)((float)(*(float *)((char *)&v119[4] + v86)
                            * (float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84)))))
                    + (float)v26);
        v25 = (float)((float)((float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84))))
                            * *(v88 - 1))
                    + (float)v25);
        v24 = (float)((float)((float)((float)(*((float *)&a3 + 1) * (float)v85)
                                    + (float)((float)(v112.x * (float)((float)v84 * (float)x))
                                            + (float)(*(float *)&a3 * (float)((float)y * (float)v84))))
                            * *v88)
                    + (float)v24);
      }
      v95 = (float)((float)((float)__fabs(v91) + (float)__fabs(v89)) + (float)__fabs(v90));
      if ( v95 > idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        v96 = (float)((float)1.0 / (float)v95);
        if ( v89 <= 0.0 )
        {
          v97 = -v89;
          v118.channelLighting[1].x = (float)((float)((float)v97 * (float)v92) * (float)v96) + v118.channelLighting[1].x;
          v118.channelLighting[1].y = (float)((float)((float)v93 * (float)v97) * (float)v96) + v118.channelLighting[1].y;
          v118.channelLighting[1].z = (float)((float)((float)v94 * (float)v97) * (float)v96) + v118.channelLighting[1].z;
        }
        else
        {
          v118.channelLighting[0].x = v118.channelLighting[0].x + (float)((float)((float)v92 * v112.x) * (float)v96);
          v118.channelLighting[0].y = v118.channelLighting[0].y + (float)((float)((float)v93 * v112.x) * (float)v96);
          v118.channelLighting[0].z = v118.channelLighting[0].z + (float)((float)((float)v94 * v112.x) * (float)v96);
        }
        if ( v91 <= 0.0 )
        {
          v17 = (float)((float)((float)((float)-v91 * (float)v92) * (float)v96) + (float)v17);
          v15 = (float)((float)((float)((float)v94 * (float)-v91) * (float)v96) + (float)v15);
          v16 = (float)((float)((float)((float)v93 * (float)-v91) * (float)v96) + (float)v16);
        }
        else
        {
          v118.channelLighting[2].y = v118.channelLighting[2].y
                                    + (float)((float)((float)v93 * *(float *)&a3) * (float)v96);
          v118.channelLighting[2].z = v118.channelLighting[2].z
                                    + (float)((float)((float)v94 * *(float *)&a3) * (float)v96);
          v14 = (float)((float)v14 + (float)((float)(*(float *)&a3 * (float)v92) * (float)v96));
        }
        if ( v90 <= 0.0 )
        {
          v23 = (float)((float)((float)((float)-v90 * (float)v92) * (float)v96) + (float)v23);
          v22 = (float)((float)((float)((float)v93 * (float)-v90) * (float)v96) + (float)v22);
          v21 = (float)((float)((float)((float)v94 * (float)-v90) * (float)v96) + (float)v21);
        }
        else
        {
          v20 = (float)((float)v20 + (float)((float)(*((float *)&a3 + 1) * (float)v92) * (float)v96));
          v19 = (float)((float)v19 + (float)((float)((float)v93 * *((float *)&a3 + 1)) * (float)v96));
          v18 = (float)((float)v18 + (float)((float)((float)v94 * *((float *)&a3 + 1)) * (float)v96));
        }
      }
      v86 += 12;
    }
  }
  v118.channelLighting[2].x = v14;
  v118.channelLighting[3].x = v17;
  v118.channelLighting[3].y = v16;
  v118.channelLighting[3].z = v15;
  v118.channelLighting[4].x = v20;
  v118.channelLighting[4].y = v19;
  v118.channelLighting[4].z = v18;
  v118.channelLighting[5].x = v23;
  v118.channelLighting[5].y = v22;
  v118.channelLighting[5].z = v21;
LABEL_70:
  v98 = *(float *)(HIDWORD(v5) + 52);
  v99 = &v114;
  v100 = *(float *)(HIDWORD(v5) + 48);
  v101 = (float)((float)v25 * *(float *)(HIDWORD(v5) + 52));
  v102 = (float)((float)v24 * *(float *)(HIDWORD(v5) + 52));
  v118.primeLightColor.x = *(float *)(HIDWORD(v5) + 52) * (float)v26;
  v118.primeLightColor.y = v101;
  v118.primeLightColor.z = v102;
  v118.primeLightColor.w = v118.primeLightColor.w * (float)v98;
  p_z = &v118.primeLightColor.z;
  for ( k = 6; k != 0; --k )
  {
    LODWORD(a3) = (unsigned __int8)v99[1];
    v105 = (unsigned __int8)v99[2];
    v99 += 3;
    LODWORD(v106) = (unsigned __int8)*v99;
    v107 = p_z[4];
    HIDWORD(v106) = v105;
    v108 = (float)(p_z[3] * (float)v100);
    v109 = (float)(p_z[2] * (float)v100);
    v110 = *(float *)&v117;
    v116 = a3;
    *(_QWORD *)&v112.x = *(_QWORD *)(&v4 - 1);
    *(_QWORD *)&v113.x = v106;
    p_z[3] = (float)((float)*(__int64 *)(&v4 - 1) * *(float *)&v117) + (float)v108;
    v111 = (float)((float)((float)a3 * (float)v110) + (float)v109);
    HIDWORD(a3) = v105;
    p_z[2] = v111;
    p_z += 4;
    *p_z = (float)((float)v106 * (float)v110) + (float)((float)v107 * (float)v100);
  }
  approximateLighting_t::operator=(this: *(approximateLighting_t **)HIDWORD(v5), __that: &v118);
}


// ========================================================================
// `dynamic initializer for 'register_ApproximateLightingJob''
// EA  : 0x8334C198
// RVA : 0x0134C198
// PDB : w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_ApproximateLightingJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_ApproximateLightingJob,
           function: (void (__fastcall *)(void *))ApproximateLightingJob,
           name: "ApproximateLightingJob");
}

