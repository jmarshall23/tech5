
// ========================================================================
// ?CullInfluenceSpheresForView@@YAXPBUinfluenceSphereCullParms_t@@@Z
// EA  : 0x82889B10
// RVA : 0x00889B10
// PDB : w:\tech5\engine\models\transparency\jobs\influencespherecull.cpp
// ========================================================================

void __fastcall CullInfluenceSpheresForView(const influenceSphereCullParms_t *parms)
{
  int numInfluenceSpheres; // r26
  int v2; // r6
  double nearDist; // fp30
  double farDist; // fp28
  int v5; // r31
  double x; // fp31
  int v7; // r30
  double y; // fp29
  const influenceSphere_t *influenceSpheres; // r5
  double v10; // fp4
  int v11; // r4
  double v12; // fp3
  int *v13; // r27
  double z; // fp2
  float *p_y; // r29
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  double v19; // fp12
  double v20; // fp11
  double v21; // fp10
  double v22; // fp13
  double v23; // fp0
  double v24; // fp9
  double v25; // fp10
  double v26; // fp12
  double v27; // fp11
  double v28; // fp0
  double v29; // fp12
  int v30; // r8
  const influenceSphere_t *v31; // r9
  _DWORD *v32; // r11
  const influenceSphere_t *v33; // r7
  int *v34; // r11
  int v35; // ctr
  int v36; // r5
  int v37; // r9
  int v38; // r7
  const influenceSphere_t *v39; // r10
  float *v40; // r11
  _BYTE v41[1024]; // [sp+10h] [-1490h] BYREF
  _DWORD v42[36]; // [sp+410h] [-1090h] BYREF

  numInfluenceSpheres = parms->numInfluenceSpheres;
  v2 = 0;
  nearDist = parms->nearDist;
  farDist = parms->farDist;
  v5 = 0;
  x = parms->fov.x;
  v7 = 0;
  y = parms->fov.y;
  if ( numInfluenceSpheres > 0 )
  {
    influenceSpheres = parms->influenceSpheres;
    v10 = parms->viewOrg.x;
    v11 = 0;
    v12 = parms->viewOrg.y;
    v13 = v42;
    z = parms->viewOrg.z;
    p_y = &influenceSpheres->center.y;
    v16 = parms->viewFwd.x;
    v17 = parms->viewFwd.y;
    v18 = parms->viewFwd.z;
    do
    {
      v19 = (float)(p_y[1] - (float)z);
      v20 = (float)(influenceSpheres[v11].center.x - (float)v10);
      v21 = (float)(*p_y - (float)v12);
      v22 = (float)(p_y[3] * (float)2.0);
      v41[v7] = 0;
      v23 = (float)((float)((float)v17 * (float)v21)
                  + (float)((float)((float)v16 * (float)v20) + (float)((float)v18 * (float)v19)));
      if ( (float)((float)((float)((float)v17 * (float)v21)
                         + (float)((float)((float)v16 * (float)v20) + (float)((float)v18 * (float)v19)))
                 + (float)v22) >= nearDist
        && (float)((float)((float)((float)v17 * (float)v21)
                         + (float)((float)((float)v16 * (float)v20) + (float)((float)v18 * (float)v19)))
                 - (float)v22) <= farDist )
      {
        v24 = (float)((float)((float)((float)v17 * (float)v21)
                            + (float)((float)((float)v16 * (float)v20) + (float)((float)v18 * (float)v19)))
                    * (float)x);
        v25 = (float)((float)v21
                    - (float)((float)v17
                            * (float)((float)((float)v17 * (float)v21)
                                    + (float)((float)((float)v16 * (float)v20) + (float)((float)v18 * (float)v19)))));
        v26 = (float)((float)v19 - (float)((float)v18 * (float)v23));
        v27 = (float)((float)v20 - (float)((float)v16 * (float)v23));
        if ( (float)((float)((float)((float)v27 * parms->viewLeft.x)
                           + (float)((float)(parms->viewLeft.z * (float)v26) + (float)(parms->viewLeft.y * (float)v25)))
                   + (float)v22) >= -v24
          && (float)((float)((float)((float)v27 * parms->viewLeft.x)
                           + (float)((float)(parms->viewLeft.z * (float)v26) + (float)(parms->viewLeft.y * (float)v25)))
                   - (float)v22) <= v24 )
        {
          v28 = (float)((float)v23 * (float)y);
          v29 = (float)((float)(parms->viewUp.x * (float)v27)
                      + (float)((float)(parms->viewUp.z * (float)v26) + (float)(parms->viewUp.y * (float)v25)));
          if ( (float)((float)v29 + (float)v22) >= -v28 && (float)((float)v29 - (float)v22) <= v28 )
          {
            *v13 = v7;
            v30 = 0;
            if ( v5 > 0 )
            {
              v31 = parms->influenceSpheres;
              v32 = v42;
              v33 = &v31[v11];
              while ( v33->angle <= (double)v31[*v32].angle )
              {
                ++v30;
                ++v32;
                v33 = &v31[v11];
                if ( v30 >= v5 )
                  goto LABEL_18;
              }
              if ( v5 > v30 )
              {
                v34 = v13;
                v35 = v5 - v30;
                do
                {
                  *v34 = *(v34 - 1);
                  --v34;
                  --v35;
                }
                while ( v35 != 0 );
              }
              v42[v30] = v7;
            }
LABEL_18:
            v41[v7] = 1;
            if ( v5 >= 256 )
            {
              v41[*v13] = 0;
            }
            else
            {
              ++v5;
              ++v13;
            }
          }
        }
      }
      ++v7;
      ++v11;
      p_y += 6;
    }
    while ( v7 < numInfluenceSpheres );
  }
  v36 = 0;
  if ( numInfluenceSpheres > 0 )
  {
    v37 = 0;
    v38 = 0;
    do
    {
      if ( v41[v36] != 0 )
      {
        ++v2;
        v39 = &parms->influenceSpheres[v38];
        v40 = (float *)((char *)&parms->visibleInfluenceSpheres->numSpheres + v37);
        v37 += 24;
        v40[4] = v39->center.x;
        v40[5] = v39->center.y;
        v40[6] = v39->center.z;
        v40[7] = v39->innerRadius;
        v40[8] = v39->outerRadius;
        v40[9] = v39->angle;
      }
      ++v36;
      ++v38;
    }
    while ( v36 < parms->numInfluenceSpheres );
  }
  parms->visibleInfluenceSpheres->numSpheres = v2;
}


// ========================================================================
// `dynamic initializer for 'register_CullInfluenceSpheresForView''
// EA  : 0x83345030
// RVA : 0x01345030
// PDB : w:\tech5\engine\models\transparency\jobs\influencespherecull.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_CullInfluenceSpheresForView__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_CullInfluenceSpheresForView,
           function: (void (__fastcall *)(void *))CullInfluenceSpheresForView,
           name: "CullInfluenceSpheresForView");
}

