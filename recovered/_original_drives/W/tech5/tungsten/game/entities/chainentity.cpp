
// ========================================================================
// ?GetNormal@idVerletChain@@QBA?AVidVec3@@H@Z
// EA  : 0x82C0F650
// RVA : 0x00C0F650
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idVerletChain *__fastcall idVerletChain::GetNormal(idVerletChain *this, idVec3 *result, int pointId)
{
  float z; // r9
  unsigned __int16 *v4; // r11
  int v5; // r4
  float *v6; // r11
  float *v7; // r10
  double v8; // fp9
  double v9; // fp6
  double v10; // fp3
  double v13; // fp5
  double v14; // fp10
  double v15; // fp5

  z = result[1].z;
  v4 = (unsigned __int16 *)(LODWORD(result[3].x) + 4 * pointId);
  v5 = v4[1] + __ROL4__(v4[1], 2);
  v6 = (float *)(8 * (*v4 + __ROL4__(*v4, 2)) + LODWORD(z));
  v7 = (float *)(8 * v5 + LODWORD(z));
  v8 = (float)(v7[4] - v6[4]);
  v9 = (float)(v7[5] - v6[5]);
  v10 = (float)(v7[3] - v6[3]);
  _FP10 = (float)((float)((float)((float)v10 * (float)v10)
                        + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f7, f10, f11, f13 }
  v13 = __frsqrte(_FP7);
  v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                      * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                                                                                              * (float)0.5))
                                                                              * (float)v13)
                                                                      - (float)1.5)
                                                      * (float)v13)
                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                              + (float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v13
                                                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                                                              + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                                                                                      * (float)0.5))
                                                                      * (float)v13)
                                                              - (float)1.5)
                                              * (float)v13))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v13
                                                      * (float)((float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)((float)v9 * (float)v9)
                                                                              + (float)((float)v8 * (float)v8)))
                                                              * (float)0.5))
                                              * (float)v13)
                                      - (float)1.5)
                      * (float)v13));
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                              * (float)v13)
                                                                                      * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                      * (float)v13))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v13
                                                                                              * (float)((float)((float)((float)v10 * (float)v10) + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) * (float)0.5))
                                                                                      * (float)v13)
                                                                              - (float)1.5)
                                                              * (float)v13))
                                              * (float)((float)((float)((float)v10 * (float)v10)
                                                              + (float)((float)((float)v9 * (float)v9)
                                                                      + (float)((float)v8 * (float)v8)))
                                                      * (float)0.5))
                                      * (float)v14)
                              - (float)1.5)
              * (float)v14);
  *(float *)&this->__vftable = (float)(v7[3] - v6[3]) * (float)v15;
  *(float *)&this->constraints.list = (float)v8 * (float)v15;
  *(float *)&this->constraints.num = (float)v9 * (float)v15;
  return this;
}


// ========================================================================
// ?UpdateCooldown@idVerletChain@@QAA_NHHAAM@Z
// EA  : 0x82C0F730
// RVA : 0x00C0F730
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall idVerletChain::UpdateCooldown(idVerletChain *this, BOOL pointId, int gameTime, float *health)
{
  idVerletChain::particle_t *v6; // r31
  int timeStamp; // r11
  double v9; // fp1
  double v10; // fp0

  v6 = &this->points.list[pointId];
  timeStamp = v6->timeStamp;
  if ( timeStamp == 0 || timeStamp > gameTime )
    return 0;
  v9 = 0.0;
  v10 = (float)((float)__SPAIR64__(0x82000000, gameTime - timeStamp) * (float)0.00025000001);
  if ( v10 >= 0.0 )
  {
    v9 = 1.0;
    if ( v10 <= 1.0 )
      v9 = (float)((float)__SPAIR64__(0x82000000, gameTime - timeStamp) * (float)0.00025000001);
  }
  _FP8 = (float)(v6->health
               - (float)((float)((float)(this->maxHealth - v6->healthStamp)
                               * idLookupTable::TableLookupNormalized(
                                   this: &this->cooldownTable,
                                   time: v9,
                                   fastSearch: pointId))
                       + v6->healthStamp));
  __asm { fsel      f0, f8, f10, f9 }
  if ( __fabs((float)((float)_FP0 - v6->health)) <= 0.00000011920929 )
    return 0;
  if ( __fabs((float)((float)_FP0 - this->maxHealth)) <= 0.00000011920929 )
    v6->timeStamp = 0;
  v6->health = _FP0;
  *health = _FP0;
  return 1;
}


// ========================================================================
// ?GetBestPoint@idVerletChain@@QBAHABVidVec3@@@Z
// EA  : 0x82C0F830
// RVA : 0x00C0F830
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall idVerletChain::GetBestPoint(idVerletChain *this, const idVec3 *position)
{
  int num; // r7
  int result; // r3
  int v5; // r11
  double v6; // fp0
  idVerletChain::particle_t *list; // r6
  int v8; // r9
  float *p_x; // r10
  double v10; // fp9
  double v11; // fp7
  double v12; // fp5
  double v13; // fp9
  double v14; // fp7
  double v15; // fp5
  double v16; // fp9
  double v17; // fp7
  double v18; // fp5
  double v19; // fp9
  double v20; // fp7
  double v21; // fp5
  idVerletChain::particle_t *v22; // r8
  int v23; // r9
  int v24; // ctr
  double v25; // fp9
  double v26; // fp7
  double v27; // fp5

  num = this->points.num;
  result = -1;
  v5 = 0;
  v6 = 1.0e30;
  if ( num >= 4 )
  {
    list = this->points.list;
    v8 = 0;
    do
    {
      p_x = &list[v8].oldPos.x;
      v10 = (float)(list[v8].currentPos.z - position->z);
      v11 = (float)(list[v8].currentPos.x - position->x);
      v12 = (float)(list[v8].currentPos.y - position->y);
      if ( (float)((float)((float)v12 * (float)v12)
                 + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) < v6 )
      {
        v6 = (float)((float)((float)v12 * (float)v12)
                   + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)));
        result = v5;
      }
      v13 = (float)(p_x[15] - position->z);
      v14 = (float)(p_x[13] - position->x);
      v15 = (float)(p_x[14] - position->y);
      if ( (float)((float)((float)v15 * (float)v15)
                 + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) < v6 )
      {
        v6 = (float)((float)((float)v15 * (float)v15)
                   + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
        result = v5 + 1;
      }
      v16 = (float)(p_x[25] - position->z);
      v17 = (float)(p_x[23] - position->x);
      v18 = (float)(p_x[24] - position->y);
      if ( (float)((float)((float)v18 * (float)v18)
                 + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) < v6 )
      {
        v6 = (float)((float)((float)v18 * (float)v18)
                   + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)));
        result = v5 + 2;
      }
      v19 = (float)(p_x[35] - position->z);
      v20 = (float)(p_x[33] - position->x);
      v21 = (float)(p_x[34] - position->y);
      if ( (float)((float)((float)v21 * (float)v21)
                 + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) < v6 )
      {
        v6 = (float)((float)((float)v21 * (float)v21)
                   + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)));
        result = v5 + 3;
      }
      v5 += 4;
      v8 += 4;
    }
    while ( v5 < num - 3 );
  }
  if ( v5 < num )
  {
    v22 = this->points.list;
    v23 = v5;
    v24 = num - v5;
    do
    {
      v25 = (float)(v22[v23].currentPos.z - position->z);
      v26 = (float)(v22[v23].currentPos.x - position->x);
      v27 = (float)(v22[v23].currentPos.y - position->y);
      if ( (float)((float)((float)v27 * (float)v27)
                 + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) < v6 )
      {
        v6 = (float)((float)((float)v27 * (float)v27)
                   + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
        result = v5;
      }
      ++v5;
      ++v23;
      --v24;
    }
    while ( v24 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetBestConstraint@idVerletChain@@ABAHHABVidVec3@@@Z
// EA  : 0x82C0F9C0
// RVA : 0x00C0F9C0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall idVerletChain::GetBestConstraint(idVerletChain *this, int id, const idVec3 *position)
{
  int result; // r3
  idVerletChain::constraint_t *list; // r11
  double x; // fp0
  double z; // fp13
  double y; // fp12
  idVerletChain::particle_t *v8; // r8
  idVerletChain::constraint_t *v9; // r5
  float *p_x; // r11
  float *v11; // r10
  double v12; // fp9
  double v13; // fp8
  double v14; // fp5
  double v15; // fp4
  double v16; // fp1
  double v17; // fp0

  if ( id == 0 )
    return 0;
  if ( id == this->points.num - 1 )
    return id - 1;
  list = this->constraints.list;
  x = position->x;
  z = position->z;
  y = position->y;
  v8 = this->points.list;
  v9 = &list[id - 1];
  p_x = &v8[list[id].index2].oldPos.x;
  v11 = &v8[v9->index1].oldPos.x;
  result = id - 1;
  v12 = (float)(p_x[3] - (float)x);
  v13 = (float)(v11[3] - (float)x);
  v14 = (float)(v11[5] - (float)z);
  v15 = (float)(p_x[5] - (float)z);
  v16 = (float)(v11[4] - (float)y);
  v17 = (float)(p_x[4] - (float)y);
  if ( (float)((float)((float)v16 * (float)v16)
             + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) >= (double)(float)((float)((float)v17 * (float)v17) + (float)((float)((float)v15 * (float)v15) + (float)((float)v12 * (float)v12))) )
    return id;
  return result;
}


// ========================================================================
// ?Constrain@idVerletChain@@AAAXXZ
// EA  : 0x82C0FAB0
// RVA : 0x00C0FAB0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::Constrain(idVerletChain *this)
{
  int v1; // r25
  int valueInteger; // r24
  double v3; // fp0
  double v4; // fp30
  int num; // r11
  int i; // r8
  int v7; // r11
  idVerletChain::particle_t *list; // r7
  idVerletChain::constraint_t *v9; // r9
  float *p_x; // r10
  float *v11; // r11
  double v12; // fp8
  double v13; // fp6
  double v14; // fp5
  double v15; // fp3
  double v16; // fp4
  double v17; // fp10
  double v18; // fp7
  double v19; // fp6
  double v20; // fp3
  double v21; // fp7
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp9
  double v26; // fp6
  double v27; // fp5
  int v28; // r6
  int v29; // r7
  int v30; // r8
  idSphere *v31; // r9
  double v32; // fp6
  int v33; // r10
  idVerletChain::particle_t *v34; // r11
  float *v35; // r11
  double z; // fp4
  double x; // fp3
  double v38; // fp10
  double v39; // fp9
  double v40; // fp8
  double v41; // fp29
  double v44; // fp7
  double v45; // fp11
  double v46; // fp5
  int v47; // r30
  int v48; // r31
  int v49; // r5
  int v50; // r4
  idVerletChain::plane_t *v51; // r11
  _DWORD *v52; // r8
  int v53; // r10
  int v54; // r7
  int v55; // r8
  int v56; // r9
  idVerletChain::particle_t *v57; // r10
  float *v58; // r10
  double v61; // fp8
  double v62; // fp6
  idVerletChain::particle_t *v63; // r10
  float *v64; // r10
  double v67; // fp6
  double v68; // fp5
  idVerletChain::particle_t *v69; // r10
  float *v70; // r10
  double v73; // fp6
  double v74; // fp5
  idVerletChain::particle_t *v75; // r10
  float *v76; // r10
  double v79; // fp6
  double v80; // fp5
  int v81; // r9
  int v82; // ctr
  idVerletChain::particle_t *v83; // r10
  float *v84; // r10
  double v87; // fp6
  double v88; // fp5
  double v89; // fp3
  double v90; // fp2
  int v91; // r27
  double v92; // fp11
  double v93; // fp10
  int v94; // r6
  double v95; // fp9
  idVerletChain::constraint_t *v96; // r29
  idVerletChain::particle_t *v97; // r10
  int v98; // r5
  float *v99; // r11
  float *v100; // r9
  float *v101; // r8
  float *v102; // r7
  double v103; // fp3
  double v104; // fp6
  double v105; // fp5
  double v106; // fp2
  double v107; // fp4
  double v108; // fp29
  double v109; // fp5
  double v110; // fp4
  idVerletChain::particle_t *v111; // r9
  idVerletChain::constraint_t *v112; // r11
  double lengthSquared; // fp9
  float *v114; // r11
  float *v115; // r10
  double v116; // fp6
  double v117; // fp3
  double v118; // fp7

  v1 = 0;
  valueInteger = g_chainVerletIterations.valueInteger;
  if ( g_chainVerletIterations.valueInteger > 0 )
  {
    v3 = s_linkSize;
    v4 = s_stiffness;
    do
    {
      num = this->constraints.num;
      for ( i = 0; i < num; num = this->constraints.num )
      {
        if ( i % 2 != 0 )
          v7 = num - (i >> 1) - 1;
        else
          v7 = i >> 1;
        list = this->points.list;
        ++i;
        v9 = &this->constraints.list[v7];
        p_x = &list[v9->index1].oldPos.x;
        v11 = &list[v9->index2].oldPos.x;
        v12 = p_x[4];
        v13 = (float)(p_x[4] - v11[4]);
        v14 = p_x[5];
        v15 = (float)(p_x[5] - v11[5]);
        v16 = (float)(p_x[3] - v11[3]);
        v17 = (float)((float)v13
                    * (float)((float)(v9->lengthSquared
                                    / (float)((float)((float)((float)v16 * (float)v16)
                                                    + (float)((float)((float)v15 * (float)v15)
                                                            + (float)((float)v13 * (float)v13)))
                                            + v9->lengthSquared))
                            - (float)0.5));
        v18 = (float)((float)v15
                    * (float)((float)(v9->lengthSquared
                                    / (float)((float)((float)((float)v16 * (float)v16)
                                                    + (float)((float)((float)v15 * (float)v15)
                                                            + (float)((float)v13 * (float)v13)))
                                            + v9->lengthSquared))
                            - (float)0.5));
        v19 = (float)((float)((float)v16
                            * (float)((float)(v9->lengthSquared
                                            / (float)((float)((float)((float)v16 * (float)v16)
                                                            + (float)((float)((float)v15 * (float)v15)
                                                                    + (float)((float)v13 * (float)v13)))
                                                    + v9->lengthSquared))
                                    - (float)0.5))
                    * (float)((float)v4 * (float)0.5));
        v20 = (float)((float)v18 * (float)((float)v4 * (float)0.5));
        v22 = (float)((float)((float)v18 * (float)((float)v4 * (float)0.5)) * v9->ratio1);
        v21 = (float)((float)((float)v17 * (float)((float)v4 * (float)0.5)) * v9->ratio1);
        p_x[3] = p_x[3] + (float)((float)v19 * v9->ratio1);
        p_x[4] = (float)v12 + (float)v21;
        p_x[5] = (float)v14 + (float)v22;
        v23 = v11[4];
        v24 = v11[5];
        v25 = (float)((float)((float)v17 * (float)((float)v4 * (float)0.5)) * v9->ratio2);
        v27 = (float)(v11[3] - (float)((float)v19 * v9->ratio2));
        v26 = (float)((float)v20 * v9->ratio2);
        v11[3] = v27;
        v11[4] = (float)v23 - (float)v25;
        v11[5] = (float)v24 - (float)v26;
      }
      v28 = 0;
      if ( this->sphereCollisions.num > 0 )
      {
        v29 = 0;
        do
        {
          v30 = 0;
          v31 = &this->sphereCollisions.list[v29];
          v32 = (float)(v31->radius + (float)v3);
          if ( this->points.num > 0 )
          {
            v33 = 0;
            do
            {
              v34 = &this->points.list[v33];
              if ( !v34->anchor )
              {
                v35 = &v34->currentPos.x;
                z = v31->origin.z;
                x = v31->origin.x;
                v38 = (float)(v35[1] - v31->origin.y);
                v39 = (float)(v35[2] - v31->origin.z);
                v40 = (float)(*v35 - v31->origin.x);
                if ( (float)((float)((float)(*v35 - v31->origin.x) * (float)(*v35 - v31->origin.x))
                           + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38))) < (double)(float)((float)v32 * (float)v32) )
                {
                  v41 = (float)((float)((float)((float)(*v35 - v31->origin.x) * (float)(*v35 - v31->origin.x))
                                      + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                              * (float)0.5);
                  _FP28 = (float)((float)((float)((float)(*v35 - v31->origin.x) * (float)(*v35 - v31->origin.x))
                                        + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                                - idMath::FLT_SMALLEST_NON_DENORMAL);
                  __asm { fsel      f11, f28, f11, f7 }
                  v44 = __frsqrte(_FP11);
                  v45 = (float)((float)(v35[2] - v31->origin.z)
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41) * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44))
                                                                                              - (float)1.5)
                                                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                      * (float)v44))
                                                                      * (float)v41)
                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41)
                                                                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44)
                                                                                              - (float)1.5)
                                                                              * (float)v44)))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                      * (float)v44)
                                                                              * (float)v41)
                                                                      * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44)
                                                                                              - (float)1.5)
                                                                              * (float)v44))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)v41)
                                                                              * (float)v44)
                                                                      - (float)1.5)
                                                      * (float)v44))));
                  v46 = (float)(v31->origin.y
                              + (float)((float)((float)v38
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41) * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44)) - (float)1.5)
                                                                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44))
                                                                                      * (float)v41)
                                                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41) * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44)) - (float)1.5)
                                                                                      * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                              * (float)v44)))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44)
                                                                                              * (float)v41)
                                                                                      * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                              * (float)v44))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v44 * (float)v41)
                                                                                              * (float)v44)
                                                                                      - (float)1.5)
                                                                      * (float)v44))))
                                      * (float)v32));
                  v35[1] = v46;
                  *v35 = (float)x
                       + (float)((float)((float)v40
                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41) * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                               * (float)v44))
                                                                               * (float)v41)
                                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44) * (float)v41) * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5) * (float)v44))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                       * (float)v44)))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                               * (float)v44)
                                                                                       * (float)v41)
                                                                               * (float)((float)-(float)((float)((float)((float)v44 * (float)v41) * (float)v44) - (float)1.5)
                                                                                       * (float)v44))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v44 * (float)v41)
                                                                                       * (float)v44)
                                                                               - (float)1.5)
                                                               * (float)v44))))
                               * (float)v32);
                  v35[2] = (float)z + (float)((float)v45 * (float)v32);
                }
              }
              ++v30;
              ++v33;
            }
            while ( v30 < this->points.num );
          }
          ++v28;
          ++v29;
        }
        while ( v28 < this->sphereCollisions.num );
      }
      v47 = 0;
      if ( this->planeCollisions.num > 0 )
      {
        v48 = 0;
        do
        {
          v49 = v48 * 32 + 24;
          v50 = 2;
          v51 = &this->planeCollisions.list[v48];
          do
          {
            v52 = (_DWORD *)((char *)&this->planeCollisions.list->plane.a + v49);
            v53 = *(v52 - 2);
            v54 = *v52 + v53;
            v55 = v53;
            if ( v53 < v54 )
            {
              if ( v54 - v53 >= 4 )
              {
                v56 = v53;
                do
                {
                  v57 = &this->points.list[v56];
                  if ( !v57->anchor )
                  {
                    v58 = &v57->currentPos.x;
                    _FP7 = (float)((float)((float)(v51->plane.a
                                                 * (float)(*v58 - (float)((float)(v51->plane.a * (float)v3) * (float)2.0)))
                                         + (float)((float)(v51->plane.c
                                                         * (float)(v58[2]
                                                                 - (float)((float)(v51->plane.c * (float)v3) * (float)2.0)))
                                                 + (float)(v51->plane.b
                                                         * (float)(v58[1]
                                                                 - (float)((float)(v51->plane.b * (float)v3) * (float)2.0)))))
                                 + v51->plane.d);
                    __asm { fsel      f10, f7, f12, f7 }
                    if ( _FP10 < 0.0 )
                    {
                      v61 = (float)(v51->plane.b * (float)_FP10);
                      v62 = (float)(v51->plane.c * (float)_FP10);
                      *v58 = *v58 - (float)(v51->plane.a * (float)_FP10);
                      v58[1] = v58[1] - (float)v61;
                      v58[2] = v58[2] - (float)v62;
                    }
                  }
                  v63 = &this->points.list[v56];
                  if ( !v63[1].anchor )
                  {
                    v64 = &v63[1].currentPos.x;
                    _FP7 = (float)((float)((float)(v51->plane.a
                                                 * (float)(*v64 - (float)((float)(v51->plane.a * (float)v3) * (float)2.0)))
                                         + (float)((float)(v51->plane.c
                                                         * (float)(v64[2]
                                                                 - (float)((float)(v51->plane.c * (float)v3) * (float)2.0)))
                                                 + (float)(v51->plane.b
                                                         * (float)(v64[1]
                                                                 - (float)((float)(v51->plane.b * (float)v3) * (float)2.0)))))
                                 + v51->plane.d);
                    __asm { fsel      f10, f7, f12, f7 }
                    if ( _FP10 < 0.0 )
                    {
                      v67 = (float)(v51->plane.b * (float)_FP10);
                      v68 = (float)(v51->plane.c * (float)_FP10);
                      *v64 = *v64 - (float)(v51->plane.a * (float)_FP10);
                      v64[1] = v64[1] - (float)v67;
                      v64[2] = v64[2] - (float)v68;
                    }
                  }
                  v69 = &this->points.list[v56];
                  if ( !v69[2].anchor )
                  {
                    v70 = &v69[2].currentPos.x;
                    _FP7 = (float)((float)((float)(v51->plane.a
                                                 * (float)(*v70 - (float)((float)(v51->plane.a * (float)v3) * (float)2.0)))
                                         + (float)((float)(v51->plane.c
                                                         * (float)(v70[2]
                                                                 - (float)((float)(v51->plane.c * (float)v3) * (float)2.0)))
                                                 + (float)(v51->plane.b
                                                         * (float)(v70[1]
                                                                 - (float)((float)(v51->plane.b * (float)v3) * (float)2.0)))))
                                 + v51->plane.d);
                    __asm { fsel      f10, f7, f12, f7 }
                    if ( _FP10 < 0.0 )
                    {
                      v73 = (float)(v51->plane.b * (float)_FP10);
                      v74 = (float)(v51->plane.c * (float)_FP10);
                      *v70 = *v70 - (float)(v51->plane.a * (float)_FP10);
                      v70[1] = v70[1] - (float)v73;
                      v70[2] = v70[2] - (float)v74;
                    }
                  }
                  v75 = &this->points.list[v56];
                  if ( !v75[3].anchor )
                  {
                    v76 = &v75[3].currentPos.x;
                    _FP7 = (float)((float)((float)(v51->plane.a
                                                 * (float)(*v76 - (float)((float)(v51->plane.a * (float)v3) * (float)2.0)))
                                         + (float)((float)(v51->plane.c
                                                         * (float)(v76[2]
                                                                 - (float)((float)(v51->plane.c * (float)v3) * (float)2.0)))
                                                 + (float)(v51->plane.b
                                                         * (float)(v76[1]
                                                                 - (float)((float)(v51->plane.b * (float)v3) * (float)2.0)))))
                                 + v51->plane.d);
                    __asm { fsel      f10, f7, f12, f7 }
                    if ( _FP10 < 0.0 )
                    {
                      v79 = (float)(v51->plane.b * (float)_FP10);
                      v80 = (float)(v51->plane.c * (float)_FP10);
                      *v76 = *v76 - (float)(v51->plane.a * (float)_FP10);
                      v76[1] = v76[1] - (float)v79;
                      v76[2] = v76[2] - (float)v80;
                    }
                  }
                  v55 += 4;
                  v56 += 4;
                }
                while ( v55 < v54 - 3 );
              }
              if ( v55 < v54 )
              {
                v81 = v55;
                v82 = v54 - v55;
                do
                {
                  v83 = &this->points.list[v81];
                  if ( !v83->anchor )
                  {
                    v84 = &v83->currentPos.x;
                    _FP7 = (float)((float)((float)(v51->plane.a
                                                 * (float)(*v84 - (float)((float)(v51->plane.a * (float)v3) * (float)2.0)))
                                         + (float)((float)(v51->plane.c
                                                         * (float)(v84[2]
                                                                 - (float)((float)(v51->plane.c * (float)v3) * (float)2.0)))
                                                 + (float)(v51->plane.b
                                                         * (float)(v84[1]
                                                                 - (float)((float)(v51->plane.b * (float)v3) * (float)2.0)))))
                                 + v51->plane.d);
                    __asm { fsel      f10, f7, f12, f7 }
                    if ( _FP10 < 0.0 )
                    {
                      v87 = (float)(v51->plane.b * (float)_FP10);
                      v88 = (float)(v51->plane.c * (float)_FP10);
                      v89 = v84[1];
                      v90 = v84[2];
                      *v84 = *v84 - (float)(v51->plane.a * (float)_FP10);
                      v84[1] = (float)v89 - (float)v87;
                      v84[2] = (float)v90 - (float)v88;
                    }
                  }
                  ++v81;
                  --v82;
                }
                while ( v82 != 0 );
              }
            }
            --v50;
            v49 += 4;
          }
          while ( v50 != 0 );
          ++v47;
          ++v48;
        }
        while ( v47 < this->planeCollisions.num );
      }
      if ( g_chainVerletIterationDynamic.valueInteger != 0 )
      {
        v91 = this->constraints.num;
        v92 = 0.0;
        ++v1;
        v93 = 0.0;
        v94 = 0;
        v95 = 0.0;
        if ( v91 >= 2 )
        {
          v96 = this->constraints.list;
          v97 = this->points.list;
          v98 = 0;
          do
          {
            v94 += 2;
            v99 = &v97[v96[v98].index2].oldPos.x;
            v100 = &v97[v96[v98].index1].oldPos.x;
            v101 = &v97[v96[v98 + 1].index2].oldPos.x;
            v102 = &v97[v96[v98 + 1].index1].oldPos.x;
            v103 = (float)(v100[4] - v99[4]);
            v104 = (float)(v102[4] - v101[4]);
            v105 = (float)(v100[5] - v99[5]);
            v106 = (float)(v102[5] - v101[5]);
            v107 = (float)(v100[3] - v99[3]);
            v108 = (float)(v102[3] - v101[3]);
            v109 = (float)(v96[v98].lengthSquared
                         - (float)((float)((float)v107 * (float)v107)
                                 + (float)((float)((float)v105 * (float)v105) + (float)((float)v103 * (float)v103))));
            v110 = (float)(v96[v98 + 1].lengthSquared
                         - (float)((float)((float)v108 * (float)v108)
                                 + (float)((float)((float)v106 * (float)v106) + (float)((float)v104 * (float)v104))));
            v98 += 2;
            v92 = (float)((float)__fabs(v109) + (float)v92);
            v93 = (float)((float)__fabs(v110) + (float)v93);
          }
          while ( v94 < v91 - 1 );
        }
        if ( v94 < v91 )
        {
          v111 = this->points.list;
          v112 = &this->constraints.list[v94];
          lengthSquared = v112->lengthSquared;
          v115 = &v111[v112->index1].oldPos.x;
          v114 = &v111[v112->index2].oldPos.x;
          v116 = (float)(v115[4] - v114[4]);
          v117 = (float)(v115[5] - v114[5]);
          v118 = (float)(v115[3] - v114[3]);
          v95 = __fabs((float)((float)lengthSquared
                             - (float)((float)((float)v118 * (float)v118)
                                     + (float)((float)((float)v117 * (float)v117) + (float)((float)v116 * (float)v116)))));
        }
        if ( (float)((float)((float)v93 + (float)v92) + (float)v95) <= (double)(float)(g_chainVerletIterationDynamicError.valueFloat
                                                                                     * g_chainVerletIterationDynamicError.valueFloat) )
          valueInteger = 0;
        if ( v1 >= g_chainVerletIterationsMaxDynamic.valueInteger )
          return;
      }
      else
      {
        --valueInteger;
      }
    }
    while ( valueInteger > 0 );
  }
}


// ========================================================================
// ?GetMovement@idVerletChain@@QBAXHHAAM0@Z
// EA  : 0x82C10388
// RVA : 0x00C10388
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::GetMovement(
        idVerletChain *this,
        int start,
        int end,
        float *maxMovement,
        float *avgMovement)
{
  __int64 v5; // r11
  int v6; // r31
  idVerletChain::particle_t *list; // r8
  double v8; // fp10
  double v9; // fp8
  double v10; // fp5
  double v13; // fp5
  double v14; // fp4
  double v15; // fp1
  double v18; // fp2
  double v19; // fp1
  double v20; // fp12
  double v23; // fp13
  double v24; // fp12
  double v25; // fp9
  idVerletChain::particle_t *v28; // r9
  int v29; // ctr
  double v30; // fp11
  double v31; // fp8
  double v32; // fp5

  *maxMovement = 0.0;
  *avgMovement = 0.0;
  if ( end - start > 0 )
  {
    v6 = start;
    if ( start < end )
    {
      if ( end - start >= 4 )
      {
        list = this->points.list;
        HIDWORD(v5) = 40 * start;
        do
        {
          v8 = (float)(*(float *)((char *)&list->oldPos.z + HIDWORD(v5))
                     - *(float *)((char *)&list->currentPos.z + HIDWORD(v5)));
          v9 = (float)(*(float *)((char *)&list->oldPos.x + HIDWORD(v5))
                     - *(float *)((char *)&list->currentPos.x + HIDWORD(v5)));
          v10 = (float)(*(float *)((char *)&list->oldPos.y + HIDWORD(v5))
                      - *(float *)((char *)&list->currentPos.y + HIDWORD(v5)));
          _FP1 = (float)((float)((float)((float)v10 * (float)v10)
                               + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))
                       - *maxMovement);
          __asm { fsel      f0, f1, f2, f13 }
          *maxMovement = _FP0;
          *avgMovement = *avgMovement
                       + (float)((float)((float)v10 * (float)v10)
                               + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)));
          v13 = (float)(*(float *)((char *)&list[1].oldPos.z + HIDWORD(v5))
                      - *(float *)((char *)&list[1].currentPos.z + HIDWORD(v5)));
          v14 = (float)(*(float *)((char *)&list[1].oldPos.x + HIDWORD(v5))
                      - *(float *)((char *)&list[1].currentPos.x + HIDWORD(v5)));
          v15 = (float)(*(float *)((char *)&list[1].oldPos.y + HIDWORD(v5))
                      - *(float *)((char *)&list[1].currentPos.y + HIDWORD(v5)));
          LODWORD(v5) = (char *)list + HIDWORD(v5) + 120;
          _FP12 = (float)((float)((float)((float)v15 * (float)v15)
                                + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)))
                        - *maxMovement);
          __asm { fsel      f11, f12, f13, f3 }
          *maxMovement = _FP11;
          *avgMovement = *avgMovement
                       + (float)((float)((float)v15 * (float)v15)
                               + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)));
          v18 = (float)(*(float *)(v5 - 32) - *(float *)(v5 - 40 + 20));
          v19 = (float)(*(float *)(v5 - 40) - *(float *)(v5 - 28));
          v20 = (float)(*(float *)(v5 - 36) - *(float *)(v5 - 24));
          _FP9 = (float)((float)((float)((float)v20 * (float)v20)
                               + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)))
                       - *maxMovement);
          __asm { fsel      f8, f9, f10, f0 }
          *maxMovement = _FP8;
          *avgMovement = *avgMovement
                       + (float)((float)((float)v20 * (float)v20)
                               + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
          v23 = (float)(*(float *)(v5 + 8) - *(float *)(v5 + 20));
          v24 = (float)(*(float *)v5 - *(float *)(v5 + 12));
          v25 = (float)(*(float *)(v5 + 4) - *(float *)(v5 + 16));
          _FP6 = (float)((float)((float)((float)v25 * (float)v25)
                               + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))
                       - *maxMovement);
          __asm { fsel      f5, f6, f7, f11 }
          *maxMovement = _FP5;
          v6 += 4;
          *avgMovement = *avgMovement
                       + (float)((float)((float)v25 * (float)v25)
                               + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)));
          HIDWORD(v5) += 160;
        }
        while ( v6 < end - 3 );
      }
      if ( v6 < end )
      {
        v28 = this->points.list;
        HIDWORD(v5) = 40 * v6;
        v29 = end - v6;
        do
        {
          v30 = (float)(*(float *)((char *)&v28->oldPos.z + HIDWORD(v5))
                      - *(float *)((char *)&v28->currentPos.z + HIDWORD(v5)));
          v31 = (float)(*(float *)((char *)&v28->oldPos.x + HIDWORD(v5))
                      - *(float *)((char *)&v28->currentPos.x + HIDWORD(v5)));
          v32 = (float)(*(float *)((char *)&v28->oldPos.y + HIDWORD(v5))
                      - *(float *)((char *)&v28->currentPos.y + HIDWORD(v5)));
          HIDWORD(v5) += 40;
          _FP1 = (float)((float)((float)((float)v32 * (float)v32)
                               + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                       - *maxMovement);
          __asm { fsel      f0, f1, f2, f0 }
          *maxMovement = _FP0;
          *avgMovement = *avgMovement
                       + (float)((float)((float)v32 * (float)v32)
                               + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)));
          --v29;
        }
        while ( v29 != 0 );
      }
    }
    LODWORD(v5) = end - start;
    *avgMovement = *avgMovement / (float)v5;
  }
}


// ========================================================================
// ?GetConstraint@idVerletChain@@QBAXHAAVidVec3@@0AAM@Z
// EA  : 0x82C105D0
// RVA : 0x00C105D0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::GetConstraint(
        idVerletChain *this,
        int id,
        idVec3 *pos1,
        idVec3 *pos2,
        float *restLengthDiff)
{
  idVerletChain::constraint_t *v5; // r8
  int index1; // r10
  int index2; // r11
  double v8; // fp12
  double v9; // fp6

  v5 = &this->constraints.list[id];
  *pos1 = vec3_origin;
  index1 = v5->index1;
  if ( index1 >= 0 )
    *pos1 = this->points.list[index1].currentPos;
  *pos2 = vec3_origin;
  index2 = v5->index2;
  if ( index2 >= 0 )
    *pos2 = this->points.list[index2].currentPos;
  v8 = (float)(pos2->z - pos1->z);
  v9 = (float)(pos2->y - pos1->y);
  *restLengthDiff = __fabs((float)(v5->length
                                 - (float)__fsqrts((float)((float)((float)v9 * (float)v9)
                                                         + (float)((float)((float)(pos2->x - pos1->x)
                                                                         * (float)(pos2->x - pos1->x))
                                                                 + (float)((float)v8 * (float)v8))))));
}


// ========================================================================
// ?GetSoundTransform@idFuncChain@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C10760
// RVA : 0x00C10760
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::GetSoundTransform(idFuncChain *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  *soundAxis = mat3_identity;
  *soundOrigin = this->breakPosition;
}


// ========================================================================
// ?buildChainClipModel_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C107D8
// RVA : 0x00C107D8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall buildChainClipModel_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const char *v3; // r4
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idFuncChain *v7; // r3
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  va *v12; // r3
  idStr *v13; // r3
  int v14; // [sp+8h] [-10D8h]
  int v15; // [sp+Ch] [-10D4h]
  int v16; // [sp+10h] [-10D0h]
  int v17; // [sp+14h] [-10CCh]
  int v18; // [sp+18h] [-10C8h]
  int v19; // [sp+1Ch] [-10C4h]
  idStr v20; // [sp+60h] [-1080h] BYREF
  idStr v21; // [sp+80h] [-1060h] BYREF
  idStr v22; // [sp+A0h] [-1040h] BYREF
  va v23; // [sp+C0h] [-1020h] BYREF

  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idStr::idStr(this: &v20, text: v2);
    if ( args->argc <= 2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[2];
    idStr::idStr(this: &v21, text: v3);
    v7 = (idFuncChain *)gameLocal->FindEntity(this: gameLocal, a2: v20.data);
    if ( v7 != nullptr )
    {
      if ( idFuncChain::CastTo(c: v7) != nullptr )
      {
        v13 = idStr::idStr(this: &v22, text: &v21);
        idStr::FreeData(this: v13);
      }
      else
      {
        HIDWORD(v11) = v20.data;
        v12 = va::va(
                this: &v23,
                fmt: "Entity '%s' is not a chain entity\n",
                a3: v11,
                a4: v10,
                a5: v9,
                a6: v14,
                a7: v15,
                a8: v16,
                a9: v17,
                a10: v18,
                a11: v19);
        idLib::Printf(fmt: v12->buffer);
      }
      idStr::FreeData(this: &v21);
    }
    else
    {
      HIDWORD(v6) = v20.data;
      v8 = va::va(
             this: &v23,
             fmt: "Couldn't find entity '%s'\n",
             a3: v6,
             a4: v5,
             a5: v4,
             a6: v14,
             a7: v15,
             a8: v16,
             a9: v17,
             a10: v18,
             a11: v19);
      idLib::Printf(fmt: v8->buffer);
      idStr::FreeData(this: &v21);
    }
    idStr::FreeData(this: &v20);
  }
  else
  {
    idLib::Printf(fmt: "Usage: buildChainClipModel <entity name> <optional output name>\n");
  }
}


// ========================================================================
// __unwind$495228
// EA  : 0x82C10900
// RVA : 0x00C10900
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_495228()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 96));
}


// ========================================================================
// __unwind$495229
// EA  : 0x82C10928
// RVA : 0x00C10928
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_495229()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 128));
}


// ========================================================================
// SetupCollisionSpherePtrsFromEntity
// EA  : 0x82C10950
// RVA : 0x00C10950
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall SetupCollisionSpherePtrsFromEntity(
        idAnimatedEntity *entity,
        cm_sphereModelPtrs_t *csPtrs,
        idVec3 *origin,
        idMat3 *axis,
        const idJointMat **modelJoints)
{
  int result; // r3
  idAnimatedEntity *v11; // r3
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v13; // r3
  idPresentableAnimatedEntity *v14; // r30
  idTreeAnimator *TreeAnimator; // r3
  idTreeAnimator *v16; // r31
  const idJointMat *v17; // r11
  idClipModel *sphereModel; // r3
  idCollisionModel *CollisionModel; // r3
  const cm_sphereModel_t **v20; // r29
  float *p_x; // r11
  float *p_deferredAxis; // r11

  if ( entity == nullptr )
    return 0;
  if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: entity) == 0 )
    return 0;
  v11 = idAnimatedEntity::CastTo(c: entity);
  if ( v11 == nullptr )
    return 0;
  presentable = v11->presentable;
  if ( presentable == nullptr )
    return 0;
  v13 = presentable->GetAnimatedEntityInterface(this: presentable);
  v14 = v13;
  if ( v13 == nullptr )
    return 0;
  TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v13);
  v16 = TreeAnimator;
  if ( TreeAnimator == nullptr )
    return 0;
  v17 = TreeAnimator->joints[1];
  *modelJoints = v17;
  if ( v17 == nullptr )
    return 0;
  if ( !v14->useSphereModel )
    return 0;
  sphereModel = v14->sphereModel;
  if ( sphereModel == nullptr )
    return 0;
  CollisionModel = idClipModel::GetCollisionModel(this: sphereModel, index: 0);
  v20 = (const cm_sphereModel_t **)_RTDynamicCast(
                                     inptr: CollisionModel,
                                     VfDelta: 0,
                                     SrcType: &idCollisionModel `RTTI Type Descriptor',
                                     TargetType: &idCollisionModelLocal `RTTI Type Descriptor',
                                     isReference: 0);
  if ( v20 == nullptr )
    return 0;
  idPresentable::UpdateModelTransform(this: v14);
  result = idSphereModelCollisionDetection::SetupCollisionSpherePtrs(csData: v20[26], csPtrs);
  p_x = &v16->deferredOrigin.x;
  if ( !v16->useDeferredPosition )
    p_x = &v16->g.origin.x;
  origin->x = *p_x;
  origin->y = p_x[1];
  origin->z = p_x[2];
  p_deferredAxis = (float *)&v16->deferredAxis;
  if ( !v16->useDeferredPosition )
    p_deferredAxis = (float *)&v16->g.axis;
  axis->mat[0].x = *p_deferredAxis;
  axis->mat[0].y = p_deferredAxis[1];
  axis->mat[0].z = p_deferredAxis[2];
  axis->mat[1].x = p_deferredAxis[3];
  axis->mat[1].y = p_deferredAxis[4];
  axis->mat[1].z = p_deferredAxis[5];
  axis->mat[2].x = p_deferredAxis[6];
  axis->mat[2].y = p_deferredAxis[7];
  axis->mat[2].z = p_deferredAxis[8];
  return result;
}


// ========================================================================
// ?OnActivate@idFuncChainGroup@@UAAXPAVidEntity@@@Z
// EA  : 0x82C10AE0
// RVA : 0x00C10AE0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChainGroup::OnActivate(idFuncChainGroup *this, idEntity *activator)
{
  int num; // r10
  char v3; // r8
  int v4; // r11
  int v5; // r9
  bool *list; // r10
  int v7; // r11
  int i; // ctr
  BOOL v9; // r10

  num = this->chains.num;
  v3 = 0;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      if ( (this->chains.list[v5].spawnId.value & 0x1FFF) == activator->entityNumber )
      {
        list = this->activeChains.list;
        v3 = list[v4];
        list[v4] = false;
      }
      num = this->chains.num;
      ++v4;
      ++v5;
    }
    while ( v4 < num );
  }
  if ( v3 != 0 )
  {
    v7 = 0;
    if ( num > 0 )
    {
      for ( i = num; i != 0; --i )
      {
        v9 = this->activeChains.list[v7++];
        v3 = v9 ? 0 : v3;
      }
    }
    if ( v3 != 0 )
      this->ActivateTargets(this, a2: this);
  }
}


// ========================================================================
// ?DisableChain@idFuncChain@@AAAXXZ
// EA  : 0x82C10B90
// RVA : 0x00C10B90
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::DisableChain(idFuncChain *this)
{
  idPhysics *Physics; // r3
  int v3; // r29
  int i; // r30
  idPhysics *v5; // r3
  int v6; // r3
  idPhysics *v7; // r3
  idPhysics *v8; // r3
  int value; // r4
  idEntity *v10; // r3
  idEntity *v11; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->GetNumClipModels(this: Physics);
  for ( i = 0; i < v3; ++i )
  {
    v5 = idEntity::GetPhysics(this);
    v6 = (int)v5->GetClipModel(this: v5, a2: i);
    if ( v6 != 0 && *(_BYTE *)(v6 + 8) != 0 )
      *(_BYTE *)(v6 + 8) = 0;
  }
  v7 = idEntity::GetPhysics(this);
  v7->DisableClip(this: v7);
  v8 = idEntity::GetPhysics(this);
  v8->UnlinkClip(this: v8);
  this->ActivateTargets(this, a2: this);
  value = this->chainGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
      if ( v11 != nullptr )
        idEntity::Activate(this: v11, activator: this);
    }
  }
}


// ========================================================================
// ??1idVerletChain@@UAA@XZ
// EA  : 0x82C10E68
// RVA : 0x00C10E68
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::~idVerletChain(idVerletChain *this)
{
  idList<idVehicleState *,5> *p_constraints; // r27

  this->__vftable = (idVerletChain_vtbl *)&idVerletChain::`vftable';
  p_constraints = (idList<idVehicleState *,5> *)&this->constraints;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->points);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orientations);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollisions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planeCollisions);
  idLookupTable::Clear(this: &this->cooldownTable);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planeCollisions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollisions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forces);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orientations);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->points);
  idList<idThread *,58>::Clear(this: p_constraints);
}


// ========================================================================
// __unwind$496993
// EA  : 0x82C10F1C
// RVA : 0x00C10F1C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496993()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 4));
}


// ========================================================================
// __unwind$496994
// EA  : 0x82C10F48
// RVA : 0x00C10F48
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496994()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 20));
}


// ========================================================================
// __unwind$496995
// EA  : 0x82C10F74
// RVA : 0x00C10F74
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496995()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 36));
}


// ========================================================================
// __unwind$496996
// EA  : 0x82C10FA0
// RVA : 0x00C10FA0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496996()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 52));
}


// ========================================================================
// __unwind$496997
// EA  : 0x82C10FCC
// RVA : 0x00C10FCC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496997()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 68));
}


// ========================================================================
// __unwind$496998
// EA  : 0x82C10FF8
// RVA : 0x00C10FF8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_496998()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 4180));
}


// ========================================================================
// ?Integrate@idVerletChain@@AAAXMM@Z
// EA  : 0x82C11028
// RVA : 0x00C11028
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::Integrate(idVerletChain *this, double deltaTime, double gravityScale)
{
  double v3; // fp10
  double v4; // fp9
  double v5; // fp8
  idVerletChain::plane_t *list; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r31
  int v12; // r9
  double v13; // fp3
  double v14; // fp4
  double v15; // fp6
  idVerletChain::particle_t *v16; // r11
  bool v17; // r10
  double v18; // fp0
  float v19; // r29
  float v20; // r10
  double v21; // fp12
  idVerletChain::particle_t *v22; // r11
  idVerletChain::particle_t *v23; // r11
  int v24; // r8
  int v25; // r10
  double v26; // fp0
  idVerletChain::particle_t *v27; // r11
  double v28; // fp30
  idVerletChain::particle_t *v29; // r11
  idVerletChain::particle_t *v30; // r11
  int num; // r11
  int v32; // r4
  idList<idVerletChain::force_t,5> *p_forces; // r10
  int v34; // r31
  unsigned int v35; // ctr
  int v36; // r5
  idVerletChain::force_t *v37; // r11
  double v38; // fp11
  double v39; // fp9
  idVec3 *p_currentPos; // r9
  int v41; // r11
  int v42; // r11
  idVerletChain::force_t *v43; // r11
  int v44; // r9
  int v45; // r11
  double v46; // fp9
  double v47; // fp10
  idVec3 *v48; // r9
  int v49; // r9
  int v50; // r11
  int v51; // r11
  idVerletChain::force_t *v52; // r11
  int v53; // r9
  int v54; // r6
  int v55; // r8
  char *v56; // r11
  double v57; // fp9
  double v58; // fp12
  idVec3 *v59; // r9
  int v60; // r11
  int v61; // r11
  float *v62; // r11
  int v63; // r9
  char *v64; // r11
  double v65; // fp9
  idVec3 *v66; // r9
  double v67; // fp13
  int v68; // r9
  int v69; // r11
  int v70; // r11
  float *v71; // r11
  int v72; // r9
  idList<idVerletChain::force_t,5> *v73; // r9
  int v74; // r6
  int v75; // ctr
  idVerletChain::force_t *v76; // r11
  int pointId; // r10
  double v78; // fp13
  double v79; // fp12
  double v80; // fp11
  idVec3 *v81; // r10
  double v82; // fp3
  double v83; // fp2
  int v84; // r11
  int v85; // r11
  idVerletChain::force_t *v86; // r11
  int v87; // r10
  float v88; // [sp+0h] [-70h]
  float x; // [sp+0h] [-70h]
  float v90; // [sp+4h] [-6Ch]
  float y; // [sp+4h] [-6Ch]
  float v92; // [sp+8h] [-68h]
  float v93; // [sp+8h] [-68h]
  float v94; // [sp+14h] [-5Ch]
  float z; // [sp+18h] [-58h]

  v3 = (float)((float)((float)(vec3_up.x * s_gravity) * (float)((float)deltaTime * (float)deltaTime))
             * (float)gravityScale);
  v4 = (float)((float)((float)(vec3_up.y * s_gravity) * (float)((float)deltaTime * (float)deltaTime))
             * (float)gravityScale);
  v5 = (float)((float)((float)(vec3_up.z * s_gravity) * (float)((float)deltaTime * (float)deltaTime))
             * (float)gravityScale);
  if ( this->planeCollisions.num <= 0 || this->planeCollisions.list->numPoints[0] <= 0 )
  {
    v24 = 0;
    if ( this->points.num > 0 )
    {
      v25 = 0;
      v26 = s_frictionAir;
      do
      {
        v27 = &this->points.list[v25];
        if ( !v27->anchor )
        {
          y = v27->currentPos.y;
          z = v27->oldPos.z;
          v93 = v27->currentPos.z;
          v94 = v27->oldPos.y;
          v28 = (float)(v27->oldPos.x * (float)((float)1.0 - (float)v26));
          x = v27->currentPos.x;
          v29 = &this->points.list[v25];
          v29->oldPos.x = x;
          v29->oldPos.y = y;
          v29->oldPos.z = v93;
          v30 = &this->points.list[v25];
          v30->currentPos.x = (float)((float)(x * (float)((float)2.0 - (float)v26)) - (float)v28) + (float)v3;
          v30->currentPos.y = (float)((float)(y * (float)((float)2.0 - (float)v26))
                                    - (float)(v94 * (float)((float)1.0 - (float)v26)))
                            + (float)v4;
          v30->currentPos.z = (float)((float)(v93 * (float)((float)2.0 - (float)v26))
                                    - (float)(z * (float)((float)1.0 - (float)v26)))
                            + (float)v5;
        }
        ++v24;
        ++v25;
      }
      while ( v24 < this->points.num );
    }
  }
  else
  {
    list = this->planeCollisions.list;
    v7 = 0;
    v8 = list->startIndex[0];
    v9 = list->startIndex[1];
    v10 = list->numPoints[0] + v8;
    v11 = list->numPoints[1] + v9;
    if ( this->points.num > 0 )
    {
      v12 = 0;
      v13 = s_sizeFric;
      v14 = s_frictionFloor;
      v15 = s_frictionAir;
      do
      {
        v16 = &this->points.list[v12];
        if ( !v16->anchor )
        {
          v17 = v7 >= v8 && v7 < v10 || v7 >= v9 && v7 < v11;
          if ( v17
            && (float)((float)((float)(list->plane.a * v16->currentPos.x)
                             + (float)((float)(v16->currentPos.z * list->plane.c)
                                     + (float)(v16->currentPos.y * list->plane.b)))
                     + list->plane.d) < v13 )
          {
            v18 = v14;
          }
          else
          {
            v18 = v15;
          }
          v19 = v16->currentPos.y;
          v90 = v16->oldPos.y;
          v20 = v16->currentPos.x;
          v21 = v16->currentPos.z;
          v88 = v16->oldPos.x;
          v92 = v16->oldPos.z;
          v22 = &this->points.list[v12];
          v22->oldPos.y = v19;
          v22->oldPos.x = v20;
          v22->oldPos.z = v21;
          v23 = &this->points.list[v12];
          v23->currentPos.x = (float)((float)(v20 * (float)((float)2.0 - (float)v18))
                                    - (float)(v88 * (float)((float)1.0 - (float)v18)))
                            + (float)v3;
          v23->currentPos.y = (float)((float)(v19 * (float)((float)2.0 - (float)v18))
                                    - (float)(v90 * (float)((float)1.0 - (float)v18)))
                            + (float)v4;
          v23->currentPos.z = (float)((float)((float)v21 * (float)((float)2.0 - (float)v18))
                                    - (float)(v92 * (float)((float)1.0 - (float)v18)))
                            + (float)v5;
        }
        ++v7;
        ++v12;
      }
      while ( v7 < this->points.num );
    }
  }
  num = this->forces.num;
  v32 = num - 1;
  if ( num - 1 >= 0 )
  {
    if ( num >= 4 )
    {
      v34 = num - 3;
      v35 = (unsigned int)this->forces.num >> 2;
      p_forces = &this->forces;
      v36 = v32;
      do
      {
        v37 = &p_forces->list[v36];
        --v37->numSteps;
        v38 = (float)(v37->force.y * (float)((float)deltaTime * (float)deltaTime));
        v39 = (float)(v37->force.z * (float)((float)deltaTime * (float)deltaTime));
        p_currentPos = &this->points.list[v37->pointId].currentPos;
        p_currentPos->x = p_currentPos->x + (float)(v37->force.x * (float)((float)deltaTime * (float)deltaTime));
        p_currentPos->y = p_currentPos->y + (float)v38;
        p_currentPos->z = p_currentPos->z + (float)v39;
        if ( v37->numSteps <= 0 && v32 >= 0 )
        {
          v41 = this->forces.num;
          if ( v32 < v41 )
          {
            v42 = v41 - 1;
            this->forces.num = v42;
            if ( v32 != v42 )
            {
              v44 = (int)&p_forces->list[v42];
              v43 = &p_forces->list[v36];
              v43->force.x = *(float *)v44;
              v43->force.y = *(float *)(v44 + 4);
              v43->force.z = *(float *)(v44 + 8);
              v43->numSteps = *(_DWORD *)(v44 + 12);
              v43->pointId = *(_DWORD *)(v44 + 16);
            }
          }
        }
        v45 = (int)&p_forces->list[v36 - 1];
        --*(_DWORD *)(v45 + 12);
        v46 = (float)(*(float *)(v45 + 4) * (float)((float)deltaTime * (float)deltaTime));
        v47 = (float)(*(float *)(v45 + 8) * (float)((float)deltaTime * (float)deltaTime));
        v48 = &this->points.list[*(_DWORD *)(v45 + 16)].currentPos;
        v48->x = v48->x + (float)(*(float *)v45 * (float)((float)deltaTime * (float)deltaTime));
        v48->y = v48->y + (float)v46;
        v48->z = v48->z + (float)v47;
        if ( *(int *)(v45 + 12) <= 0 )
        {
          v49 = v34 + 1;
          if ( v34 + 1 >= 0 )
          {
            v50 = this->forces.num;
            if ( v49 < v50 )
            {
              v51 = v50 - 1;
              this->forces.num = v51;
              if ( v49 != v51 )
              {
                v53 = (int)&p_forces->list[v51];
                v52 = &p_forces->list[v36];
                v52[-1].force.x = *(float *)v53;
                v52[-1].force.y = *(float *)(v53 + 4);
                v52[-1].force.z = *(float *)(v53 + 8);
                v52[-1].numSteps = *(_DWORD *)(v53 + 12);
                v52[-1].pointId = *(_DWORD *)(v53 + 16);
              }
            }
          }
        }
        v54 = v36 * 20 - 60;
        v55 = v36 * 20 - 60 + 20;
        v56 = (char *)p_forces->list + v55;
        --*((_DWORD *)v56 + 3);
        v57 = (float)(*((float *)v56 + 1) * (float)((float)deltaTime * (float)deltaTime));
        v58 = (float)(*((float *)v56 + 2) * (float)((float)deltaTime * (float)deltaTime));
        v59 = &this->points.list[*((_DWORD *)v56 + 4)].currentPos;
        v59->x = v59->x + (float)(*(float *)v56 * (float)((float)deltaTime * (float)deltaTime));
        v59->y = v59->y + (float)v57;
        v59->z = v59->z + (float)v58;
        if ( *((int *)v56 + 3) <= 0 && v34 >= 0 )
        {
          v60 = this->forces.num;
          if ( v34 < v60 )
          {
            v61 = v60 - 1;
            this->forces.num = v61;
            if ( v34 != v61 )
            {
              v63 = (int)&p_forces->list[v61];
              v62 = (float *)((char *)&p_forces->list->force.x + v55);
              *v62 = *(float *)v63;
              v62[1] = *(float *)(v63 + 4);
              v62[2] = *(float *)(v63 + 8);
              v62[3] = *(float *)(v63 + 12);
              v62[4] = *(float *)(v63 + 16);
            }
          }
        }
        v64 = (char *)p_forces->list + v54;
        --*((_DWORD *)v64 + 3);
        v65 = (float)(*((float *)v64 + 1) * (float)((float)deltaTime * (float)deltaTime));
        v66 = &this->points.list[*((_DWORD *)v64 + 4)].currentPos;
        v67 = (float)(*((float *)v64 + 2) * (float)((float)deltaTime * (float)deltaTime));
        v66->x = v66->x + (float)(*(float *)v64 * (float)((float)deltaTime * (float)deltaTime));
        v66->y = v66->y + (float)v65;
        v66->z = v66->z + (float)v67;
        if ( *((int *)v64 + 3) <= 0 )
        {
          v68 = v34 - 1;
          if ( v34 - 1 >= 0 )
          {
            v69 = this->forces.num;
            if ( v68 < v69 )
            {
              v70 = v69 - 1;
              this->forces.num = v70;
              if ( v68 != v70 )
              {
                v72 = (int)&p_forces->list[v70];
                v71 = (float *)((char *)&p_forces->list->force.x + v54);
                *v71 = *(float *)v72;
                v71[1] = *(float *)(v72 + 4);
                v71[2] = *(float *)(v72 + 8);
                v71[3] = *(float *)(v72 + 12);
                v71[4] = *(float *)(v72 + 16);
              }
            }
          }
        }
        v32 -= 4;
        v36 -= 4;
        v34 -= 4;
        --v35;
      }
      while ( v35 != 0 );
    }
    if ( v32 >= 0 )
    {
      v73 = &this->forces;
      v74 = v32;
      v75 = v32 + 1;
      do
      {
        v76 = &v73->list[v74];
        pointId = v76->pointId;
        v78 = v76->force.y;
        v79 = v76->force.z;
        v80 = (float)(v76->force.x * (float)((float)deltaTime * (float)deltaTime));
        --v76->numSteps;
        v81 = &this->points.list[pointId].currentPos;
        v82 = (float)(v81->y + (float)((float)v78 * (float)((float)deltaTime * (float)deltaTime)));
        v83 = (float)(v81->z + (float)((float)v79 * (float)((float)deltaTime * (float)deltaTime)));
        v81->x = v81->x + (float)v80;
        v81->y = v82;
        v81->z = v83;
        if ( v76->numSteps <= 0 && v32 >= 0 )
        {
          v84 = this->forces.num;
          if ( v32 < v84 )
          {
            v85 = v84 - 1;
            this->forces.num = v85;
            if ( v32 != v85 )
            {
              v87 = (int)&v73->list[v85];
              v86 = &v73->list[v74];
              v86->force.x = *(float *)v87;
              v86->force.y = *(float *)(v87 + 4);
              v86->force.z = *(float *)(v87 + 8);
              v86->numSteps = *(_DWORD *)(v87 + 12);
              v86->pointId = *(_DWORD *)(v87 + 16);
            }
          }
        }
        --v32;
        --v74;
        --v75;
      }
      while ( v75 != 0 );
    }
  }
}


// ========================================================================
// ??0idFuncChainGroup@@QAA@XZ
// EA  : 0x82C11820
// RVA : 0x00C11820
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idFuncChainGroup *__fastcall idFuncChainGroup::idFuncChainGroup(idFuncChainGroup *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idFuncChainGroup_vtbl *)&idFuncChainGroup::`vftable';
  this->chains.list = nullptr;
  this->chains.granularity = 0;
  this->chains.memTag = 5;
  this->chains.listStatic = 0;
  this->chains.size = 0;
  this->chains.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chains);
  this->activeChains.list = nullptr;
  this->activeChains.granularity = 0;
  this->activeChains.memTag = 5;
  this->activeChains.listStatic = 0;
  this->activeChains.size = 0;
  this->activeChains.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeChains);
  return this;
}


// ========================================================================
// __unwind$497367
// EA  : 0x82C1189C
// RVA : 0x00C1189C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_497367()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$497368
// EA  : 0x82C118C4
// RVA : 0x00C118C4
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_497368()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// ??1idFuncChainGroup@@UAA@XZ
// EA  : 0x82C118F8
// RVA : 0x00C118F8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChainGroup::~idFuncChainGroup(idFuncChainGroup *this)
{
  this->__vftable = (idFuncChainGroup_vtbl *)&idFuncChainGroup::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeChains);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->chains);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$497597
// EA  : 0x82C11954
// RVA : 0x00C11954
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_497597()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$497598_0
// EA  : 0x82C1197C
// RVA : 0x00C1197C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_497598_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// ?BindEndPoint@idFuncChain@@AAAXABUbinddef_t@1@AAUbind_t@1@@Z
// EA  : 0x82C119A8
// RVA : 0x00C119A8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::BindEndPoint(
        idFuncChain *this,
        const idFuncChain::binddef_t *bindInfo,
        idFuncChain::bind_t *bind)
{
  idEntity *v5; // r3
  idEntity *v6; // r3
  idAnimatedEntity *v7; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r4
  idAnimatedEntity *v9; // r3
  __int16 v10; // r9
  unsigned __int16 v11; // r11
  idPropsCollection *decl; // r11
  tagData_t *Tag; // r3
  unsigned __int16 value; // r11
  unsigned __int16 v15; // [sp+50h] [-30h] BYREF

  if ( gameLocal->spawnIds.ptr[bindInfo->bindToObject.spawnId.value & 0x1FFF] == bindInfo->bindToObject.spawnId.value >> 13 )
  {
    v5 = gameLocal->entities.ptr[bindInfo->bindToObject.spawnId.value & 0x1FFF];
    if ( v5 != nullptr )
    {
      v6 = idEntity::CastTo(c: v5);
      v7 = (idAnimatedEntity *)v6;
      if ( v6 != nullptr )
      {
        TreeAnimatorFromPresentable = nullptr;
        if ( bindInfo->bindToJoint.len <= 0 && bindInfo->bindToTag.len <= 0 )
          goto LABEL_11;
        if ( (unsigned __int8)idAnimatedEntity::IsTypeOf(c: v6) == 0 )
        {
          idLib::Warning(fmt: "idFuncChain::BindEndPoint: entity '%s' does not support skeletal models.", v7->name.data);
          return;
        }
        v9 = idAnimatedEntity::CastTo(c: v7);
        if ( v9 != nullptr
          && (TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v9)) != nullptr )
        {
LABEL_11:
          if ( bindInfo->bindToJoint.len <= 0 )
          {
            if ( bindInfo->bindToTag.len <= 0 )
            {
              bind->bindMaster.spawnId.value = (gameLocal->spawnIds.ptr[v7->entityNumber] << 13) | v7->entityNumber;
              value = NULL_JOINT.value;
              bind->bindJoint.value = -1;
              bind->bindTag.parentJoint.value = value;
            }
            else
            {
              decl = (idPropsCollection *)TreeAnimatorFromPresentable->decl;
              if ( decl != nullptr && decl != (idPropsCollection *)-352 )
              {
                Tag = (tagData_t *)idPropsCollection::GetTag(
                                     this: decl + 22,
                                     propName: "_info",
                                     tagName: bindInfo->bindToTag.data);
                bind->bindMaster.spawnId.value = (gameLocal->spawnIds.ptr[v7->entityNumber] << 13) | v7->entityNumber;
                bind->bindTag = *Tag;
                bind->bindJoint.value = -1;
              }
              else
              {
                idLib::Warning(
                  fmt: "idFuncChain::BindEndPoint: tree animated entity '%s' does not have a 'props' collection.",
                  v7->name.data);
              }
            }
          }
          else
          {
            idTreeAnimator::GetJointIndex(
              this: (idTreeAnimator *)&v15,
              result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
              jointName: bindInfo->bindToJoint.data);
            v10 = v15;
            if ( v15 == 0xFFFF )
            {
              idLib::Warning(
                fmt: "idFuncChain::BindEndPoint: joint '%s' not found on entity '%s'.",
                bindInfo->bindToJoint.data,
                v7->name.data);
            }
            else
            {
              bind->bindMaster.spawnId.value = (gameLocal->spawnIds.ptr[v7->entityNumber] << 13) | v7->entityNumber;
              v11 = NULL_JOINT.value;
              bind->bindJoint.value = v10;
              bind->bindTag.parentJoint.value = v11;
            }
          }
        }
        else
        {
          idLib::Warning(fmt: "idFuncChain::BindEndPoint: entity '%s' does not use a skeletal model.", v7->name.data);
        }
      }
    }
  }
}


// ========================================================================
// ?BuildPhysics@idFuncChain@@AAAXXZ
// EA  : 0x82C11C08
// RVA : 0x00C11C08
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::BuildPhysics(idFuncChain *this)
{
  int brokenLink; // r11
  idPhysics *v3; // r3
  idPhysics *v4; // r3
  idPhysics *Physics; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  void *v7; // r30
  idPhysics_StaticMulti *v8; // r3
  idPhysics_StaticMulti *v9; // r3
  __int16 *p_granularity; // r10
  float z; // r7
  float *p_z; // r11
  int v13; // ctr
  float *chainLinkModel; // r11
  const idMaterial *v15; // r18
  int num; // r25
  double v17; // fp15
  double v20; // fp16
  double v21; // fp23
  double v22; // fp22
  double v23; // fp21
  double v24; // fp26
  double v25; // fp25
  double v26; // fp24
  int i; // r30
  idVerletChain::particle_t *list; // r26
  int v29; // r27
  idVerletChain::particle_t *v30; // r11
  float v31; // r9
  float v32; // r8
  double v33; // fp29
  double v34; // fp30
  double v35; // fp28
  int v36; // r30
  int v37; // r11
  float v38; // r8
  float v39; // r7
  double v40; // fp6
  double v43; // fp5
  double v44; // fp7
  double v45; // fp7
  double v46; // fp4
  double v47; // fp3
  double v48; // fp2
  double v49; // fp1
  double v50; // fp7
  double v51; // fp6
  double v52; // fp3
  double v54; // fp4
  double v56; // fp5
  double v57; // fp1
  double v58; // fp7
  double v59; // fp6
  int v60; // r23
  int v61; // r11
  encounterGroupRole_t *v62; // r20
  int v63; // r27
  double v64; // fp20
  double v65; // fp19
  double v66; // fp18
  encounterGroupRole_t *v67; // r26
  double v68; // fp22
  idVerletChain::particle_t *v69; // r7
  int v70; // r28
  float *p_x; // r10
  float *v72; // r9
  double v73; // fp26
  double v74; // fp25
  double v75; // fp24
  float *v76; // r10
  double v77; // fp13
  double v78; // fp12
  double v79; // fp0
  double v80; // fp9
  double v81; // fp8
  double v82; // fp11
  double v83; // fp10
  double v84; // fp13
  double v87; // fp1
  double v88; // fp4
  double v89; // fp1
  double v90; // fp4
  float *v91; // r11
  float v92; // r6
  float v93; // r8
  float v94; // r7
  float *v95; // r10
  idSysMutex *p_viewNoteMutex; // r11
  int v97; // ctr
  double v98; // fp29
  double v99; // fp28
  double v100; // fp30
  idClipModel *v101; // r3
  idClipModel *v102; // r30
  double v105; // fp7
  double v106; // fp0
  double v107; // fp11
  double v108; // fp28
  double v109; // fp30
  double v110; // fp29
  idPhysics *physicsObject; // r3
  encounterGroupRole_t v112[2]; // [sp+50h] [-850h] BYREF
  idVec3 v113; // [sp+58h] [-848h] BYREF
  float x; // [sp+68h] [-838h]
  float y; // [sp+6Ch] [-834h]
  float v116; // [sp+70h] [-830h]
  idVec3 v117; // [sp+78h] [-828h] BYREF
  idVec3 v118; // [sp+88h] [-818h] BYREF
  float v119; // [sp+98h] [-808h] BYREF
  float v120; // [sp+9Ch] [-804h]
  float v121; // [sp+A0h] [-800h]
  float v122; // [sp+A8h] [-7F8h] BYREF
  float v123; // [sp+ACh] [-7F4h]
  float v124; // [sp+B0h] [-7F0h]
  float v125[6]; // [sp+B8h] [-7E8h] BYREF
  idList<enum encounterGroupRole_t,5> v126; // [sp+D0h] [-7D0h] BYREF
  idMat3 v127; // [sp+E0h] [-7C0h] BYREF
  idBounds v128; // [sp+110h] [-790h] BYREF
  idMat3 v129; // [sp+130h] [-770h] BYREF
  idMat3 v130; // [sp+160h] [-740h] BYREF
  idTraceModel v131; // [sp+190h] [-710h] BYREF

  if ( !this->generatedPhysics )
  {
    brokenLink = this->brokenLink;
    this->generatedPhysics = true;
    if ( brokenLink == -1 )
    {
      if ( this->clipModelInfo.type != CLIPMODEL_NONE )
      {
        Physics = idEntity::GetPhysics(this);
        Physics->SetContents(this: Physics, a2: 1, a3: -1);
      }
      else
      {
        RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
        v7 = _RTDynamicCast(
               inptr: RenderModelFromPresentable,
               VfDelta: 0,
               SrcType: &idRenderModel `RTTI Type Descriptor',
               TargetType: &idRenderModelChain `RTTI Type Descriptor',
               isReference: 0);
        if ( v7 != nullptr )
        {
          v8 = (idPhysics_StaticMulti *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                          size: 0x98u,
                                          tag: TAG_NEW,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
          v112[0] = (encounterGroupRole_t)v8;
          if ( v8 != nullptr )
            v9 = idPhysics_StaticMulti::idPhysics_StaticMulti(this: v8);
          else
            v9 = nullptr;
          this->physicsObject = v9;
          idPhysics::InitPhysics(
            this: v9,
            clip_: &clientGame->clip,
            callbacks_: &this->physicsCallbacks,
            entityNumber_: this->entityNumber);
          p_granularity = &v126.granularity;
          z = this->spawnPosition.z;
          p_z = &this->spawnPosition.z;
          v13 = 9;
          y = this->spawnPosition.y;
          v116 = z;
          x = this->spawnPosition.x;
          do
          {
            ++p_z;
            p_granularity += 2;
            *(float *)p_granularity = *p_z;
            --v13;
          }
          while ( v13 != 0 );
          chainLinkModel = (float *)this->chainLinkModel;
          v15 = nullptr;
          num = this->verlet.points.num;
          v17 = (float)((float)(chainLinkModel[28] - chainLinkModel[25]) * (float)0.5);
          _FP3 = (float)((float)((float)(chainLinkModel[26] - chainLinkModel[23]) * (float)0.5)
                       - (float)((float)(chainLinkModel[27] - chainLinkModel[24]) * (float)0.5));
          __asm { fsel      f2, f3, f5, f4 }
          v20 = (float)((float)_FP2 + (float)0.5);
          if ( *((int *)v7 + 277) > 0 )
            v15 = **((const idMaterial ***)v7 + 276);
          v21 = this->verlet.refForward.x;
          v22 = this->verlet.refForward.y;
          v23 = this->verlet.refForward.z;
          v24 = this->verlet.refLeft.x;
          v112[0] = (encounterGroupRole_t)&this->verlet.refForward;
          v25 = this->verlet.refLeft.y;
          v26 = this->verlet.refLeft.z;
          v112[0] = (encounterGroupRole_t)&this->verlet.refLeft;
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v126);
          for ( i = 0; i < num - 1; i = v36 + 1 )
          {
            list = this->verlet.points.list;
            v29 = 1;
            v112[0] = ROLE_DEFEND;
            v30 = &list[i];
            v31 = v30->currentPos.y;
            v32 = v30->currentPos.z;
            v122 = v30->currentPos.x;
            v123 = v31;
            v124 = v32;
            idVerletChain::GetNormal(this: (idVerletChain *)&v118, result: (idVec3 *)&this->verlet, pointId: i);
            v33 = v118.y;
            v34 = v118.x;
            v35 = v118.z;
            if ( (float)((float)(v118.z * v118.z) + (float)((float)(v118.x * v118.x) + (float)(v118.y * v118.y))) <= 0.00000011920929 )
            {
              v118.x = v21;
              v34 = v21;
              v118.y = v22;
              v33 = v22;
              v118.z = v23;
              v35 = v23;
            }
            v117.z = (float)((float)v33 * (float)v24) - (float)((float)v25 * (float)v34);
            v117.y = (float)((float)v26 * (float)v34) - (float)((float)v35 * (float)v24);
            v117.x = (float)((float)v35 * (float)v25) - (float)((float)v33 * (float)v26);
            idVec3::NormalizeFast(this: &v117);
            v113.z = (float)(v117.y * (float)v34) - (float)((float)v33 * v117.x);
            v113.y = (float)((float)v35 * v117.x) - (float)(v117.z * (float)v34);
            v113.x = (float)(v117.z * (float)v33) - (float)(v117.y * (float)v35);
            idVec3::NormalizeFast(this: &v113);
            v36 = i + 1;
            if ( v36 < num )
            {
              v37 = v36;
              while ( 1 )
              {
                v38 = list[v37].currentPos.x;
                v39 = list[v37].currentPos.z;
                v120 = list[v37].currentPos.y;
                v119 = v38;
                v121 = v39;
                v40 = (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                            + (float)((float)((float)(v120 - v123) * (float)(v120 - v123))
                                    + (float)((float)(v39 - v124) * (float)(v39 - v124))));
                _FP5 = (float)((float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                     + (float)((float)((float)(v120 - v123) * (float)(v120 - v123))
                                             + (float)((float)(v39 - v124) * (float)(v39 - v124))))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                __asm { fsel      f7, f5, f6, f0 }
                v43 = __frsqrte(_FP7);
                v44 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5))
                                                                                            * (float)v43)
                                                                                    - (float)1.5)
                                                                    * (float)v43)
                                                            * (float)((float)v40 * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v43
                                                                                            * (float)((float)v40 * (float)0.5))
                                                                                    * (float)v43)
                                                                            - (float)1.5)
                                                            * (float)v43))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5))
                                                            * (float)v43)
                                                    - (float)1.5)
                                    * (float)v43));
                v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43) * (float)((float)v40 * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5)) * (float)v43)
                                                                                            - (float)1.5)
                                                                            * (float)v43))
                                                            * (float)((float)v40 * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5)) * (float)v43) - (float)1.5) * (float)v43)
                                                                                            * (float)((float)v40 * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5)) * (float)v43) - (float)1.5)
                                                                                            * (float)v43))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v43 * (float)((float)v40 * (float)0.5))
                                                                                            * (float)v43)
                                                                                    - (float)1.5)
                                                                    * (float)v43)))
                                            - (float)1.5)
                            * (float)v44);
                v46 = (float)(v123
                            + (float)((float)v33
                                    * (float)((float)v45
                                            * (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                                    + (float)((float)((float)(v120 - v123) * (float)(v120 - v123))
                                                            + (float)((float)(v39 - v124) * (float)(v39 - v124)))))));
                v48 = (float)((float)((float)((float)(v39 - v124) * (float)v45) * (float)v35)
                            + (float)((float)((float)((float)(v38 - v122) * (float)v45) * (float)v34)
                                    + (float)((float)((float)(v120 - v123) * (float)v45) * (float)v33)));
                v47 = (float)((float)(v124
                                    + (float)((float)v35
                                            * (float)((float)v45
                                                    * (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                                            + (float)((float)((float)(v120 - v123) * (float)(v120 - v123))
                                                                    + (float)((float)(v39 - v124) * (float)(v39 - v124)))))))
                            + (float)(v113.z * (float)v20));
                v49 = (float)((float)((float)(v123
                                            + (float)((float)v33
                                                    * (float)((float)v45
                                                            * (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                                                    + (float)((float)((float)(v120 - v123)
                                                                                    * (float)(v120 - v123))
                                                                            + (float)((float)(v39 - v124)
                                                                                    * (float)(v39 - v124)))))))
                                    + (float)(v113.y * (float)v20))
                            - v123);
                v51 = (float)((float)((float)(v124
                                            + (float)((float)v35
                                                    * (float)((float)v45
                                                            * (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                                                    + (float)((float)((float)(v120 - v123)
                                                                                    * (float)(v120 - v123))
                                                                            + (float)((float)(v39 - v124)
                                                                                    * (float)(v39 - v124)))))))
                                    + (float)(v113.z * (float)v20))
                            - v124);
                v50 = (float)((float)((float)((float)((float)v34
                                                    * (float)((float)v45
                                                            * (float)((float)((float)(v38 - v122) * (float)(v38 - v122))
                                                                    + (float)((float)((float)(v120 - v123)
                                                                                    * (float)(v120 - v123))
                                                                            + (float)((float)(v39 - v124)
                                                                                    * (float)(v39 - v124))))))
                                            + v122)
                                    + (float)(v113.x * (float)v20))
                            - v122);
                v52 = (float)((float)((float)((float)v47 - v124) * (float)((float)v47 - v124))
                            + (float)((float)((float)v50 * (float)v50)
                                    + (float)((float)((float)((float)v46 + (float)(v113.y * (float)v20)) - v123)
                                            * (float)((float)((float)v46 + (float)(v113.y * (float)v20)) - v123))));
                _FP5 = (float)((float)v52 - idMath::FLT_SMALLEST_NON_DENORMAL);
                v54 = (float)((float)v52 * (float)0.5);
                __asm { fsel      f3, f5, f3, f0 }
                v56 = __frsqrte(_FP3);
                v57 = (float)((float)v49
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54) * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56))
                                                                    * (float)v54)
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54)
                                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56)))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56)
                                                                            * (float)v54)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56))
                                                            - (float)1.5)
                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54)
                                                                            * (float)v56)
                                                                    - (float)1.5)
                                                    * (float)v56))));
                v58 = (float)((float)v50
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54) * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56))
                                                                    * (float)v54)
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54)
                                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56)))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56)
                                                                            * (float)v54)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56))
                                                            - (float)1.5)
                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54)
                                                                            * (float)v56)
                                                                    - (float)1.5)
                                                    * (float)v56))));
                v59 = (float)((float)v51
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54) * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                            - (float)1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56))
                                                                    * (float)v54)
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56) * (float)v54)
                                                                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5) * (float)v56))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56)))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56) - (float)1.5)
                                                                                    * (float)v56)
                                                                            * (float)v54)
                                                                    * (float)((float)-(float)((float)((float)((float)v56 * (float)v54) * (float)v56)
                                                                                            - (float)1.5)
                                                                            * (float)v56))
                                                            - (float)1.5)
                                            * (float)((float)-(float)((float)((float)((float)v56 * (float)v54)
                                                                            * (float)v56)
                                                                    - (float)1.5)
                                                    * (float)v56))));
                if ( v48 < (float)((float)((float)v59 * (float)v35)
                                 + (float)((float)((float)v58 * (float)v34) + (float)((float)v57 * (float)v33))) )
                  break;
                ++v36;
                ++v29;
                ++v37;
                if ( v36 >= num )
                  goto LABEL_23;
              }
              --v36;
LABEL_23:
              v112[0] = v29;
            }
            idList<idAnimWebBlendTree *,5>::Append(this: &v126, obj: v112);
          }
          v60 = v126.num;
          v61 = 0;
          v62 = v126.list;
          v63 = 0;
          if ( v126.num > 0 )
          {
            v64 = v116;
            v65 = y;
            v66 = x;
            v67 = v126.list;
            v68 = -v20;
            do
            {
              v69 = this->verlet.points.list;
              v70 = *v67 + v61;
              p_x = &v69[v61].oldPos.x;
              v72 = &v69[v70 - 1].oldPos.x;
              v73 = p_x[4];
              v74 = p_x[5];
              v75 = p_x[3];
              v77 = (float)(v72[4] - p_x[4]);
              v78 = (float)(v72[5] - p_x[5]);
              v79 = (float)(v72[3] - p_x[3]);
              v76 = &v69[v61 + 1].oldPos.x;
              v80 = v76[3];
              v81 = v76[4];
              v82 = v77;
              v83 = v78;
              if ( v70 - 1 > v61 )
              {
                _FP4 = (float)((float)((float)((float)v78 * (float)v78)
                                     + (float)((float)((float)v79 * (float)v79) + (float)((float)v77 * (float)v77)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                __asm { fsel      f2, f4, f5, f11 }
                v87 = __frsqrte(_FP2);
                v88 = (float)((float)-(float)((float)((float)((float)v87
                                                            * (float)((float)((float)((float)v78 * (float)v78)
                                                                            + (float)((float)((float)v79 * (float)v79)
                                                                                    + (float)((float)v77 * (float)v77)))
                                                                    * (float)0.5))
                                                    * (float)v87)
                                            - (float)1.5)
                            * (float)v87);
                v89 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v87
                                                                                            * (float)((float)((float)((float)v78 * (float)v78) + (float)((float)((float)v79 * (float)v79) + (float)((float)v77 * (float)v77))) * (float)0.5))
                                                                                    * (float)v87)
                                                                            - (float)1.5)
                                                            * (float)v87)
                                                    * (float)((float)((float)((float)v78 * (float)v78)
                                                                    + (float)((float)((float)v79 * (float)v79)
                                                                            + (float)((float)v77 * (float)v77)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v87
                                                                                    * (float)((float)((float)((float)v78 * (float)v78) + (float)((float)((float)v79 * (float)v79) + (float)((float)v77 * (float)v77)))
                                                                                            * (float)0.5))
                                                                            * (float)v87)
                                                                    - (float)1.5)
                                                    * (float)v87))
                                    - (float)1.5);
                v90 = (float)((float)-(float)((float)((float)((float)((float)v89 * (float)v88)
                                                            * (float)((float)((float)((float)v78 * (float)v78)
                                                                            + (float)((float)((float)v79 * (float)v79)
                                                                                    + (float)((float)v77 * (float)v77)))
                                                                    * (float)0.5))
                                                    * (float)((float)v89 * (float)v88))
                                            - (float)1.5)
                            * (float)((float)v89 * (float)v88));
                v82 = (float)((float)v77 * (float)v90);
                v83 = (float)((float)v78 * (float)v90);
                v84 = (float)((float)v90
                            * (float)((float)((float)v78 * (float)v78)
                                    + (float)((float)((float)v79 * (float)v79) + (float)((float)v77 * (float)v77))));
                v79 = (float)((float)v79 * (float)v90);
              }
              else
              {
                v84 = v17;
              }
              if ( v61 >= v61 + 1 )
              {
                v124 = (float)v74 - v76[5];
                v123 = (float)v73 - (float)v81;
                v122 = (float)v75 - (float)v80;
                v91 = &v122;
              }
              else
              {
                v121 = v76[5] - (float)v74;
                v120 = (float)v81 - (float)v73;
                v119 = (float)v80 - (float)v75;
                v91 = &v119;
              }
              v92 = v91[2];
              v93 = *v91;
              v94 = v91[1];
              v95 = &v131.offset.z;
              v128.b[0].x = v68;
              v128.b[0].y = v68;
              v116 = v92;
              x = v93;
              y = v94;
              v128.b[0].z = -v17;
              v128.b[1].x = v20;
              v128.b[1].y = v20;
              v128.b[1].z = (float)v17 + (float)v84;
              v131.offset.x = 0.0;
              v131.offset.y = 0.0;
              v113.x = v93;
              v131.offset.z = 0.0;
              v113.y = v94;
              memset(&v131.type, 0, 20);
              p_viewNoteMutex = &analysisClient.viewNoteMutex;
              v97 = 6;
              v113.z = v92;
              v98 = (float)(v92 + (float)((float)((float)v83 - v92) * (float)0.5));
              v99 = (float)((float)((float)((float)v79 - v93) * (float)0.5) + v93);
              v100 = (float)(v94 + (float)((float)((float)v82 - v94) * (float)0.5));
              do
              {
                ++p_viewNoteMutex;
                *++v95 = *(float *)&p_viewNoteMutex->handle;
                --v97;
              }
              while ( v97 != 0 );
              v131.radius = 0.0;
              v131.isConvex = false;
              v131.pad[2] = 0;
              v131.pad[1] = 0;
              v131.pad[0] = 0;
              idTraceModel::SetupBox(this: &v131, boxBounds: &v128);
              v101 = (idClipModel *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0xD8u,
                                      tag: TAG_CLIPMODEL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
              v112[0] = (encounterGroupRole_t)v101;
              if ( v101 != nullptr )
                v102 = idClipModel::idClipModel(
                         this: v101,
                         clip: &clientGame->clip,
                         trm: &v131,
                         numTraceModels: 1,
                         material: v15);
              else
                v102 = nullptr;
              v102->bodyMask = -1;
              v102->bodyId = v63;
              _FP10 = (float)((float)((float)((float)v98 * (float)v98)
                                    + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100)))
                            - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f9, f10, f11, f0 }
              v105 = __frsqrte(_FP9);
              v106 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                           * (float)v105)
                                                                                   - (float)1.5)
                                                                   * (float)v105)
                                                           * (float)((float)((float)((float)v98 * (float)v98)
                                                                           + (float)((float)((float)v99 * (float)v99)
                                                                                   + (float)((float)v100 * (float)v100)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v105
                                                                                           * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                   * (float)v105)
                                                                           - (float)1.5)
                                                           * (float)v105))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v105
                                                                   * (float)((float)((float)((float)v98 * (float)v98)
                                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                                           + (float)((float)v100 * (float)v100)))
                                                                           * (float)0.5))
                                                           * (float)v105)
                                                   - (float)1.5)
                                   * (float)v105));
              v107 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105) * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105)
                                                                                           - (float)1.5)
                                                                           * (float)v105))
                                                           * (float)((float)((float)((float)v98 * (float)v98)
                                                                           + (float)((float)((float)v99 * (float)v99)
                                                                                   + (float)((float)v100 * (float)v100)))
                                                                   * (float)0.5))
                                                   * (float)v106)
                                           - (float)1.5)
                           * (float)v106);
              v108 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105) * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105))
                                                                                           - (float)1.5)
                                                                           * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v98 * (float)v98) + (float)((float)((float)v99 * (float)v99) + (float)((float)v100 * (float)v100))) * (float)0.5)) * (float)v105) - (float)1.5)
                                                                                   * (float)v105))
                                                                   * (float)((float)((float)((float)v98 * (float)v98)
                                                                                   + (float)((float)((float)v99 * (float)v99)
                                                                                           + (float)((float)v100 * (float)v100)))
                                                                           * (float)0.5))
                                                           * (float)v106)
                                                   - (float)1.5)
                                   * (float)v106)
                           * (float)v99);
              v113.x = v108;
              v109 = (float)((float)v107 * (float)v100);
              v113.y = v109;
              v110 = (float)((float)v107 * (float)v98);
              v113.z = v110;
              idVec3::NormalVectors(this: &v113, left: &v117, down: &v118);
              v129.mat[2].x = v108;
              v129.mat[2].y = v109;
              v129.mat[2].z = v110;
              v129.mat[0].x = v117.x;
              v129.mat[0].y = v117.y;
              v129.mat[0].z = v117.z;
              v129.mat[1].x = v118.x;
              v129.mat[1].y = v118.y;
              v129.mat[1].z = v118.z;
              idMat3::operator*(this: &v130, result: &v129, a: &v127);
              physicsObject = this->physicsObject;
              v125[2] = (float)v64
                      + (float)((float)(v127.mat[0].z * (float)v75)
                              + (float)((float)(v127.mat[2].z * (float)v74) + (float)(v127.mat[1].z * (float)v73)));
              v125[1] = (float)v65
                      + (float)((float)(v127.mat[0].y * (float)v75)
                              + (float)((float)(v127.mat[2].y * (float)v74) + (float)(v127.mat[1].y * (float)v73)));
              v125[0] = (float)((float)(v127.mat[0].x * (float)v75)
                              + (float)((float)(v127.mat[2].x * (float)v74) + (float)(v127.mat[1].x * (float)v73)))
                      + (float)v66;
              ((void (__fastcall *)(idPhysics *, idClipModel *, double))physicsObject->SetClipModel)(
                a1: physicsObject,
                a2: v102,
                a3: 1.0);
              this->physicsObject->SetOrigin(this: this->physicsObject, a2: (const idVec3 *)v125, a3: v63);
              this->physicsObject->SetAxis(this: this->physicsObject, a2: &v130, a3: v63++);
              v61 = v70;
              ++v67;
            }
            while ( v63 < v60 );
          }
          this->physicsObject->SetContents(this: this->physicsObject, a2: 1, a3: -1);
          this->physicsObject->PutToRest(this: this->physicsObject);
          idEntity::SetPhysics(this, phys: this->physicsObject);
          if ( (v126.listStatic == 0 || v126.listStatic == 2) && v62 != nullptr )
            idMem::Free(this: &mem, ptr: v62, align: ALIGN_16);
        }
      }
    }
    else
    {
      v3 = idEntity::GetPhysics(this);
      v3->UnlinkClip(this: v3);
      v4 = idEntity::GetPhysics(this);
      v4->DisableClip(this: v4);
    }
  }
}


// ========================================================================
// __unwind$498013
// EA  : 0x82C1255C
// RVA : 0x00C1255C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall _unwind_498013(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 2208 + 80), tag: a2);
}


// ========================================================================
// __unwind$498014
// EA  : 0x82C12584
// RVA : 0x00C12584
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_498014()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2208 + 208));
}


// ========================================================================
// __unwind$498015
// EA  : 0x82C125AC
// RVA : 0x00C125AC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_498015()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2208 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?GetWorldPosition@idFuncChain@@ABA_NABUorigin_t@1@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C125D8
// RVA : 0x00C125D8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall idFuncChain::GetWorldPosition(
        idFuncChain *this,
        const idFuncChain::origin_t *origin,
        idVec3 *worldOrigin,
        idMat3 *worldAxis)
{
  int value; // r10
  idFuncChain::bind_t *p_bind; // r29
  idEntity *v10; // r3
  idAnimatedEntity *v11; // r3
  idEntity *v12; // r26
  idAnimatedEntity *v13; // r30
  idPresentable *v14; // r3
  idPresentableAnimatedEntity *v15; // r3
  idPresentable *v16; // r30
  idPhysics *v17; // r3
  float *v18; // r3
  idPhysics *v19; // r3
  float *v20; // r3
  int result; // r3
  idTreeAnimator *v22; // r26
  idAnimatedEntity *v23; // r3
  idAnimatedEntity *v24; // r3
  idEntity *v25; // r30
  idEntity *v26; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idIndex<short,enum invalidJointIndex_t> *v28; // r3
  idTreeAnimator *v29; // r30
  double v30; // fp8
  double v31; // fp6
  idPresentable *v32; // r3
  idPresentable *v33; // r30
  idIndex<short,enum invalidJointIndex_t> *TreeAnimator; // r25
  double v35; // fp8
  double v36; // fp6
  idEntity *v37; // r3
  idPresentable *presentable; // r11
  idEntity *v39; // r30
  float y; // r9
  float z; // r8
  idEntity *v42; // r3
  idPresentable *v43; // r11
  idEntity *v44; // r30
  char *v45; // r10
  idPresentable *p_z; // r11
  int i; // ctr
  idEntity *v48; // r3
  idPhysics *Physics; // r3
  int v50; // r3
  float v51; // r7
  float v52; // r6
  idEntity *v53; // r3
  idPhysics *v54; // r3
  int v55; // r3
  char *v56; // r10
  _DWORD *v57; // r11
  int j; // ctr
  double v59; // fp0
  double v60; // fp13
  double v61; // fp12
  double v62; // fp11
  double v63; // fp10
  double v64; // fp9
  double v65; // fp8
  double v66; // fp7
  double v67; // fp6
  double v68; // fp30
  double v69; // fp2
  double v70; // fp4
  double v71; // fp3
  double v72; // fp9
  double v73; // fp7
  double v74; // fp2
  double v75; // fp0
  _WORD v76[4]; // [sp+50h] [-C0h] BYREF
  float x; // [sp+58h] [-B8h]
  float v78; // [sp+5Ch] [-B4h]
  float v79; // [sp+60h] [-B0h]
  idVec3 v80; // [sp+68h] [-A8h] BYREF
  idVec3 v81; // [sp+78h] [-98h] BYREF
  char v82; // [sp+8Ch] [-84h] BYREF
  float v83; // [sp+90h] [-80h]
  float v84; // [sp+94h] [-7Ch]
  float v85; // [sp+98h] [-78h]
  float v86; // [sp+9Ch] [-74h]
  float v87; // [sp+A0h] [-70h]
  float v88; // [sp+A4h] [-6Ch]
  float v89; // [sp+A8h] [-68h]
  float v90; // [sp+ACh] [-64h]
  float v91; // [sp+B0h] [-60h]

  value = origin->bind.bindMaster.spawnId.value;
  p_bind = &origin->bind;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v11 = (idAnimatedEntity *)idEntity::CastTo(c: v10), v12 = v11, v11 != nullptr) )
  {
    if ( (unsigned __int16)p_bind->bindJoint.value >= 0x8000u )
    {
      if ( p_bind->bindTag.parentJoint.value == 0xFFFF )
      {
        if ( idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster)->presentable != nullptr )
        {
          v37 = idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
          presentable = v37->presentable;
          v39 = v37;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v37);
            presentable = v39->presentable;
          }
          y = presentable->origin.y;
          z = presentable->origin.z;
          x = presentable->origin.x;
          v78 = y;
          v79 = z;
          v42 = idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
          v43 = v42->presentable;
          v44 = v42;
          if ( v43 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v42);
            v43 = v44->presentable;
          }
          v45 = &v82;
          p_z = (idPresentable *)&v43->origin.z;
          for ( i = 9; i != 0; --i )
          {
            p_z = (idPresentable *)((char *)p_z + 4);
            v45 += 4;
            *(_DWORD *)v45 = p_z->__vftable;
          }
        }
        else
        {
          v48 = idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
          Physics = idEntity::GetPhysics(this: v48);
          v50 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          v51 = *(float *)(v50 + 4);
          v52 = *(float *)(v50 + 8);
          x = *(float *)v50;
          v78 = v51;
          v79 = v52;
          v53 = idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
          v54 = idEntity::GetPhysics(this: v53);
          v55 = (int)v54->GetAxis(this: v54, a2: 0);
          v56 = &v82;
          v57 = (_DWORD *)(v55 - 4);
          for ( j = 9; j != 0; --j )
          {
            ++v57;
            v56 += 4;
            *(_DWORD *)v56 = *v57;
          }
        }
        v59 = v86;
        v60 = v87;
        v61 = v88;
        v62 = v89;
        v63 = v90;
        v64 = v91;
        v65 = v83;
        v66 = v84;
        v67 = v85;
        v68 = v78;
        v69 = v79;
        v70 = (float)((float)(v84 * origin->position.x)
                    + (float)((float)(v90 * origin->position.z) + (float)(v87 * origin->position.y)));
        v71 = (float)((float)(v85 * origin->position.x)
                    + (float)((float)(v91 * origin->position.z) + (float)(v88 * origin->position.y)));
        worldOrigin->x = (float)((float)(v83 * origin->position.x)
                               + (float)((float)(v89 * origin->position.z) + (float)(v86 * origin->position.y)))
                       + x;
        worldOrigin->y = (float)v68 + (float)v70;
        worldOrigin->z = (float)v69 + (float)v71;
        worldAxis->mat[0].x = v65;
        worldAxis->mat[1].x = v59;
        worldAxis->mat[0].y = v66;
        worldAxis->mat[0].z = v67;
        worldAxis->mat[1].y = v60;
        worldAxis->mat[1].z = v61;
        worldAxis->mat[2].x = v62;
        worldAxis->mat[2].y = v63;
        worldAxis->mat[2].z = v64;
        return 1;
      }
      else
      {
        v23 = (idAnimatedEntity *)idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
        v24 = idAnimatedEntity::CastTo(c: v23);
        v25 = v24;
        if ( v24 != nullptr )
        {
          v32 = v24->presentable;
          if ( v32 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v25);
            v32 = v25->presentable;
          }
          result = (int)v32->GetAnimatedEntityInterface(this: v32);
          v33 = (idPresentable *)result;
          if ( result != 0 )
          {
            TreeAnimator = (idIndex<short,enum invalidJointIndex_t> *)idPresentableAnimatedEntity::GetTreeAnimator(this: (idPresentableAnimatedEntity *)result);
            idPresentable::UpdateModelTransform(this: v33);
            idTreeAnimator::GetJointIndex(
              this: (idTreeAnimator *)v76,
              result: TreeAnimator,
              jointHandle: &p_bind->bindTag.parentJoint);
            v35 = (float)(p_bind->bindTag.trans.y + origin->position.y);
            v36 = (float)(p_bind->bindTag.trans.z + origin->position.z);
            v81.x = p_bind->bindTag.trans.x + origin->position.x;
            v81.y = v35;
            v81.z = v36;
            idTreeAnimator::GetWorldSpaceAttachmentTransform(
              this: (idTreeAnimator *)TreeAnimator,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v76[0],
              translationOffset: &v81,
              rotationOffset: (idMat3 *)&p_bind->bindTag.rot,
              origin: worldOrigin,
              axis: worldAxis);
            return 1;
          }
          else
          {
            *worldOrigin = vec3_origin;
            *worldAxis = mat3_identity;
          }
        }
        else
        {
          v26 = idEntityPtr<idEntity const>::operator->(this: &p_bind->bindMaster);
          RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v26);
          if ( RenderModelFromPresentable != nullptr
            && (v28 = (idIndex<short,enum invalidJointIndex_t> *)_RTDynamicCast(
                                                                   inptr: RenderModelFromPresentable,
                                                                   VfDelta: 0,
                                                                   SrcType: &idRenderModel `RTTI Type Descriptor',
                                                                   TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                                                   isReference: 0),
                v29 = (idTreeAnimator *)v28,
                v28 != nullptr) )
          {
            idTreeAnimator::GetJointIndex(
              this: (idTreeAnimator *)v76,
              result: v28,
              jointHandle: &p_bind->bindTag.parentJoint);
            v30 = (float)(p_bind->bindTag.trans.y + origin->position.y);
            v31 = (float)(p_bind->bindTag.trans.z + origin->position.z);
            v80.x = p_bind->bindTag.trans.x + origin->position.x;
            v80.y = v30;
            v80.z = v31;
            idTreeAnimator::GetWorldSpaceAttachmentTransform(
              this: v29,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v76[0],
              translationOffset: &v80,
              rotationOffset: (idMat3 *)&p_bind->bindTag.rot,
              origin: worldOrigin,
              axis: worldAxis);
            return 1;
          }
          else
          {
            *worldOrigin = vec3_origin;
            *worldAxis = mat3_identity;
            return 1;
          }
        }
      }
    }
    else
    {
      v13 = idAnimatedEntity::CastTo(c: v11);
      v14 = v13->presentable;
      if ( v14 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v13);
        v14 = v13->presentable;
      }
      v15 = v14->GetAnimatedEntityInterface(this: v14);
      v16 = v15;
      if ( v15 != nullptr )
      {
        v22 = idPresentableAnimatedEntity::GetTreeAnimator(this: v15);
        idPresentable::UpdateModelTransform(this: v16);
        idTreeAnimator::GetWorldSpaceAttachmentTransform(
          this: v22,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_bind->bindJoint.value,
          translationOffset: &origin->position,
          rotationOffset: (idMat3 *)&quat_identity,
          origin: worldOrigin,
          axis: worldAxis);
        return 1;
      }
      else
      {
        v17 = idEntity::GetPhysics(this: v12);
        v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
        worldOrigin->x = *v18;
        worldOrigin->y = v18[1];
        worldOrigin->z = v18[2];
        v19 = idEntity::GetPhysics(this: v12);
        v20 = (float *)v19->GetAxis(this: v19, a2: 0);
        worldAxis->mat[0].x = *v20;
        worldAxis->mat[0].y = v20[1];
        worldAxis->mat[0].z = v20[2];
        worldAxis->mat[1].x = v20[3];
        worldAxis->mat[1].y = v20[4];
        worldAxis->mat[1].z = v20[5];
        worldAxis->mat[2].x = v20[6];
        worldAxis->mat[2].y = v20[7];
        worldAxis->mat[2].z = v20[8];
        return 0;
      }
    }
  }
  else
  {
    worldAxis->mat[0].x = this->spawnOrientation.mat[0].x;
    worldAxis->mat[0].y = this->spawnOrientation.mat[0].y;
    worldAxis->mat[0].z = this->spawnOrientation.mat[0].z;
    worldAxis->mat[1].x = this->spawnOrientation.mat[1].x;
    worldAxis->mat[1].y = this->spawnOrientation.mat[1].y;
    worldAxis->mat[1].z = this->spawnOrientation.mat[1].z;
    worldAxis->mat[2].x = this->spawnOrientation.mat[2].x;
    worldAxis->mat[2].y = this->spawnOrientation.mat[2].y;
    worldAxis->mat[2].z = this->spawnOrientation.mat[2].z;
    v72 = this->spawnPosition.x;
    v73 = this->spawnPosition.z;
    v74 = (float)((float)(origin->position.x * this->spawnOrientation.mat[0].x)
                + (float)((float)(this->spawnOrientation.mat[1].x * origin->position.y)
                        + (float)(this->spawnOrientation.mat[2].x * origin->position.z)));
    v75 = (float)((float)(this->spawnOrientation.mat[0].z * origin->position.x)
                + (float)((float)(this->spawnOrientation.mat[1].z * origin->position.y)
                        + (float)(this->spawnOrientation.mat[2].z * origin->position.z)));
    worldOrigin->y = this->spawnPosition.y
                   + (float)((float)(this->spawnOrientation.mat[0].y * origin->position.x)
                           + (float)((float)(this->spawnOrientation.mat[1].y * origin->position.y)
                                   + (float)(this->spawnOrientation.mat[2].y * origin->position.z)));
    worldOrigin->x = (float)v72 + (float)v74;
    worldOrigin->z = (float)v73 + (float)v75;
    return 1;
  }
  return result;
}


// ========================================================================
// ?Spawn@idFuncChainGroup@@QAAXXZ
// EA  : 0x82C13068
// RVA : 0x00C13068
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChainGroup::Spawn(idFuncChainGroup *this)
{
  int num; // r4
  char v2; // [sp+50h] [-10h] BYREF

  num = this->chains.num;
  v2 = 1;
  idList<bool,5>::SetNum(this: &this->activeChains, newNum: num, initValue: (bool *)&v2);
}


// ========================================================================
// ?Event_SpawnBindEndPoints@idFuncChain@@AAA?AVeventVoid@@XZ
// EA  : 0x82C130A0
// RVA : 0x00C130A0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idFuncChain *__fastcall idFuncChain::Event_SpawnBindEndPoints(idFuncChain *this, idFuncChain *result)
{
  int value; // r9
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  int v8; // r26
  int v9; // r30
  float *p_value; // r11
  idFuncChain::sphere_t *v11; // r29
  int v12; // r9
  idEntity *v13; // r3
  double x; // fp8
  double v15; // fp7
  float *v16; // r11
  double v17; // fp11
  double y; // fp10
  double z; // fp9
  double v20; // fp6
  double v21; // fp5
  double v22; // fp4
  double v23; // fp3
  float v24; // r8
  double v25; // fp2
  double v26; // fp1
  double v27; // fp31
  double v28; // fp30
  double v29; // fp29
  double v30; // fp31
  float *v31; // r11
  double v32; // fp11
  double v33; // fp7
  double v34; // fp4
  double v35; // fp13
  double v36; // fp12
  float v38; // [sp+54h] [-9Ch]
  float v39; // [sp+58h] [-98h]
  idVec3 v40; // [sp+60h] [-90h] BYREF
  idMat3 v41; // [sp+70h] [-80h] BYREF

  idFuncChain::BindEndPoint(this: result, bindInfo: &result->chainDef.startBindInfo, bind: &result->state.start.bind);
  value = result->state.start.bind.bindMaster.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
      result->state.start.position = vec3_origin;
  }
  idFuncChain::BindEndPoint(this: result, bindInfo: &result->chainDef.endBindInfo, bind: &result->state.end.bind);
  v6 = result->state.end.bind.bindMaster.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 )
  {
    v7 = gameLocal->entities.ptr[v6 & 0x1FFF];
    if ( v7 != nullptr && idEntity::CastTo(c: v7) != nullptr )
      result->state.end.position = vec3_origin;
  }
  v8 = 0;
  if ( result->collisions.num > 0 )
  {
    v9 = 0;
    do
    {
      p_value = (float *)&result->collisions.list[v9].bindInfo.bindToObject.spawnId.value;
      p_value[21] = p_value[17];
      p_value[22] = p_value[18];
      p_value[23] = p_value[19];
      idFuncChain::BindEndPoint(
        this: result,
        bindInfo: &result->collisions.list[v9].bindInfo,
        bind: &result->collisions.list[v9].origin.bind);
      v11 = &result->collisions.list[v9];
      v12 = v11->origin.bind.bindMaster.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 )
      {
        v13 = gameLocal->entities.ptr[v12 & 0x1FFF];
        if ( v13 != nullptr
          && idEntity::CastTo(c: v13) != nullptr
          && (unsigned __int16)v11->origin.bind.bindJoint.value >= 0x8000u
          && v11->origin.bind.bindTag.parentJoint.value == 0xFFFF )
        {
          x = result->spawnOrientation.mat[1].x;
          v15 = result->spawnOrientation.mat[0].x;
          v16 = (float *)&result->collisions.list[v9].bindInfo.bindToObject.spawnId.value;
          v17 = result->spawnOrientation.mat[2].x;
          y = result->spawnOrientation.mat[0].y;
          z = result->spawnOrientation.mat[0].z;
          v20 = result->spawnOrientation.mat[1].y;
          v21 = result->spawnOrientation.mat[2].y;
          v22 = result->spawnOrientation.mat[1].z;
          v23 = result->spawnOrientation.mat[2].z;
          v24 = v16[21];
          v25 = result->spawnPosition.x;
          v26 = result->spawnPosition.y;
          v27 = result->spawnPosition.z;
          v39 = v16[23];
          v38 = v16[22];
          *((idVec3 *)v16 + 7) = vec3_origin;
          v28 = (float)((float)v26
                      + (float)((float)((float)v21 * v39) + (float)((float)((float)v20 * v38) + (float)((float)y * v24))));
          v29 = (float)((float)v25
                      + (float)((float)(v24 * (float)v15) + (float)((float)((float)x * v38) + (float)((float)v17 * v39))));
          v30 = (float)((float)v27
                      + (float)((float)((float)v23 * v39) + (float)((float)((float)v22 * v38) + (float)((float)z * v24))));
          idFuncChain::GetWorldPosition(
            this: result,
            origin: &result->collisions.list[v9].origin,
            worldOrigin: &v40,
            worldAxis: &v41);
          v31 = (float *)&result->collisions.list[v9].bindInfo.bindToObject.spawnId.value;
          v32 = (float)((float)v29 - v40.x);
          v33 = v41.mat[1].x;
          v34 = v41.mat[2].x;
          v35 = (float)((float)(v41.mat[1].y * (float)((float)v28 - v40.y))
                      + (float)(v41.mat[1].z * (float)((float)v30 - v40.z)));
          v36 = (float)((float)(v41.mat[2].y * (float)((float)v28 - v40.y))
                      + (float)(v41.mat[2].z * (float)((float)v30 - v40.z)));
          v31[21] = (float)(v41.mat[0].x * (float)((float)v29 - v40.x))
                  + (float)((float)(v41.mat[0].y * (float)((float)v28 - v40.y))
                          + (float)(v41.mat[0].z * (float)((float)v30 - v40.z)));
          v31[22] = (float)((float)v33 * (float)v32) + (float)v35;
          v31[23] = (float)((float)v34 * (float)v32) + (float)v36;
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < result->collisions.num );
  }
  return this;
}


// ========================================================================
// ??0idVerletChain@@QAA@XZ
// EA  : 0x82C13B10
// RVA : 0x00C13B10
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idVerletChain *__fastcall idVerletChain::idVerletChain(idVerletChain *this)
{
  idList<idVehicleState *,5> *p_constraints; // r25
  float z; // r11

  this->__vftable = (idVerletChain_vtbl *)&idVerletChain::`vftable';
  p_constraints = (idList<idVehicleState *,5> *)&this->constraints;
  this->constraints.list = nullptr;
  this->constraints.granularity = 0;
  this->constraints.memTag = 5;
  this->constraints.listStatic = 0;
  this->constraints.size = 0;
  this->constraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  this->points.list = nullptr;
  this->points.granularity = 0;
  this->points.memTag = 5;
  this->points.listStatic = 0;
  this->points.size = 0;
  this->points.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->points);
  this->orientations.list = nullptr;
  this->orientations.granularity = 0;
  this->orientations.memTag = 5;
  this->orientations.listStatic = 0;
  this->orientations.size = 0;
  this->orientations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orientations);
  this->forces.list = nullptr;
  this->forces.granularity = 0;
  this->forces.memTag = 5;
  this->forces.listStatic = 0;
  this->forces.size = 0;
  this->forces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forces);
  this->sphereCollisions.num = 0;
  this->sphereCollisions.granularity = 1;
  this->sphereCollisions.size = 256;
  this->sphereCollisions.list = this->sphereCollisions.staticList;
  this->sphereCollisions.memTag = 5;
  this->sphereCollisions.listStatic = 1;
  this->planeCollisions.num = 0;
  this->planeCollisions.size = 6;
  this->planeCollisions.granularity = 1;
  this->planeCollisions.list = this->planeCollisions.staticList;
  this->planeCollisions.memTag = 5;
  this->planeCollisions.listStatic = 1;
  this->refForward = vec3_origin;
  this->refLeft = vec3_origin;
  this->refDown.x = vec3_origin.x;
  this->refDown.y = vec3_origin.y;
  z = vec3_origin.z;
  this->maxHealth = 45.0;
  this->refDown.z = z;
  this->cooldownTable._min = 0.0;
  this->cooldownTable._max = 1.0;
  this->cooldownTable.clamp = false;
  this->cooldownTable.snap = false;
  this->cooldownTable.spline = false;
  this->cooldownTable.values.closeTime = 0.0;
  this->cooldownTable.values.numKnots = 0;
  this->cooldownTable.values.currentIndex = -1;
  this->cooldownTable.values.changed = false;
  this->cooldownTable.values.boundaryType = 0;
  idList<idThread *,58>::Clear(this: p_constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->points);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->orientations);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forces);
  if ( this->sphereCollisions.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollisions);
  this->sphereCollisions.num = __CFADD__(-this->sphereCollisions.size, this->sphereCollisions.size ^ 0x80000000)
                             ? 0
                             : this->sphereCollisions.size;
  if ( this->planeCollisions.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planeCollisions);
  this->planeCollisions.num = __CFADD__(-this->planeCollisions.size, this->planeCollisions.size ^ 0x80000000)
                            ? 0
                            : this->planeCollisions.size;
  idLookupTable::Clear(this: &this->cooldownTable);
  this->cooldownTable._min = 0.0;
  this->cooldownTable._max = 1.0;
  idLookupTable::SetClamp(this: &this->cooldownTable, b: true);
  idLookupTable::SetSpline(this: &this->cooldownTable, b: true);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.0, v: 0.0);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.039436601, v: 0.081871301);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.132394, v: 0.24561401);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.24507, v: 0.40935701);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.469484, v: 0.654971);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 0.72018802, v: 0.859649);
  idLookupTable::AddValue(this: &this->cooldownTable, t: 1.0, v: 1.0);
  idLookupTable::Finalize(this: &this->cooldownTable);
  this->brokenPointIndex = -1;
  return this;
}


// ========================================================================
// __unwind$501454
// EA  : 0x82C13E4C
// RVA : 0x00C13E4C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 4));
}


// ========================================================================
// __unwind$501455
// EA  : 0x82C13E78
// RVA : 0x00C13E78
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501455()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 20));
}


// ========================================================================
// __unwind$501456
// EA  : 0x82C13EA4
// RVA : 0x00C13EA4
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 36));
}


// ========================================================================
// __unwind$501457
// EA  : 0x82C13ED0
// RVA : 0x00C13ED0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 52));
}


// ========================================================================
// __unwind$501458
// EA  : 0x82C13EFC
// RVA : 0x00C13EFC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 68));
}


// ========================================================================
// __unwind$501459
// EA  : 0x82C13F28
// RVA : 0x00C13F28
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_501459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 4180));
}


// ========================================================================
// ?BuildConstraints@idVerletChain@@QAAXM@Z
// EA  : 0x82C13F58
// RVA : 0x00C13F58
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::BuildConstraints(idVerletChain *this, double health)
{
  int v4; // r4
  double v5; // fp30
  int v6; // r11
  int v7; // r29
  int v8; // r30
  idVerletChain::particle_t *list; // r10
  float *p_x; // r9
  idVerletChain::particle_t *v11; // r11
  double v12; // fp13
  double v13; // fp0
  double v14; // fp9
  double v15; // fp6
  double v16; // fp3
  int num; // r4
  int v18; // r11
  int v19; // r30
  int v20; // r11
  int v21; // r6
  int v22; // r11
  int v23; // r10
  idVerletChain::particle_t *v24; // r9
  idVerletChain::particle_t *v25; // r11
  double v26; // fp8
  double v27; // fp11
  double v28; // fp6
  double v29; // fp3
  double v30; // fp5
  double v31; // fp11
  double v34; // fp9
  double v35; // fp7
  double v36; // fp13
  double v37; // fp11
  double v38; // fp9
  idVerletChain::orientation_t v39[4]; // [sp+50h] [-70h] BYREF
  drawSurf_t v40; // [sp+60h] [-60h] BYREF

  if ( this->points.num > 0 )
  {
    if ( s_anchor1 )
      this->points.list->anchor = true;
    if ( s_anchor2 )
      this->points.list[this->points.num - 1].anchor = true;
  }
  v4 = this->points.num - 1;
  v5 = s_lengthAdjustment;
  if ( v4 > this->constraints.size )
    idList<HQDXTjob_t,34>::Resize(this: (idList<idSWF::imageToPack_t,72> *)&this->constraints, newsize: v4);
  v6 = 0;
  if ( this->points.num - 1 > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = v6 + 1;
      v40.material = (const idMaterial *)v6;
      list = this->points.list;
      v40.prog = (const idDeclRenderProg *)(v6 + 1);
      p_x = &list[v7].oldPos.x;
      v11 = &list[v6 + 1];
      if ( !list[v7].anchor )
        break;
      if ( !v11->anchor )
      {
        v12 = 0.0;
LABEL_14:
        if ( v11->anchor )
          v13 = 0.0;
        else
          v13 = 1.0;
        v14 = (float)(v11->currentPos.y - p_x[4]);
        v15 = (float)(v11->currentPos.z - p_x[5]);
        v16 = (float)(v11->currentPos.x - p_x[3]);
        *(float *)&v40.modelSurface = (float)((float)1.0 / (float)((float)v13 + (float)v12)) * (float)v13;
        *(float *)&v40.model = (float)((float)1.0 / (float)((float)v13 + (float)v12)) * (float)v12;
        v40.sort = (float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                         + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))))
                 * (float)v5;
        *(float *)&v40.isWorld = v40.sort * v40.sort;
        idList<idVerletChain::constraint_t,5>::Append(this: (idList<drawSurf_t,3> *)&this->constraints, obj: &v40);
      }
      v6 = v8;
      ++v7;
      if ( v8 >= this->points.num - 1 )
        goto LABEL_19;
    }
    v12 = 1.0;
    goto LABEL_14;
  }
LABEL_19:
  num = this->points.num;
  if ( num > this->orientations.size )
    idList<idVerletChain::orientation_t,5>::Resize(this: &this->orientations, newsize: num);
  v18 = 0;
  if ( this->points.num - 1 > 0 )
  {
    do
    {
      v19 = v18 + 1;
      v39[0].index1 = v18;
      v39[0].index2 = v18 + 1;
      idList<idVerletChain::orientation_t,5>::Append(this: &this->orientations, obj: v39);
      v18 = v19;
    }
    while ( v19 < this->points.num - 1 );
  }
  v20 = this->points.num;
  v39[0].index1 = v20 - 2;
  v39[0].index2 = v20 - 1;
  idList<idVerletChain::orientation_t,5>::Append(this: &this->orientations, obj: v39);
  v21 = this->points.num;
  this->maxHealth = health;
  v22 = 0;
  if ( v21 > 0 )
  {
    v23 = 0;
    do
    {
      ++v22;
      v24 = &this->points.list[v23++];
      v24->health = health;
    }
    while ( v22 < this->points.num );
  }
  v25 = this->points.list;
  v26 = (float)(v25[1].currentPos.y - v25->currentPos.y);
  v27 = (float)(v25[1].currentPos.x - v25->currentPos.x);
  v28 = (float)(v25[1].currentPos.z - v25->currentPos.z);
  this->refForward.x = v25[1].currentPos.x - v25->currentPos.x;
  this->refForward.y = v26;
  this->refForward.z = v28;
  v29 = v26;
  v30 = v27;
  v31 = (float)((float)((float)v28 * (float)v28)
              + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)));
  _FP10 = (float)((float)v31 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f13 }
  v34 = (float)((float)v31 * (float)0.5);
  v35 = __frsqrte(_FP8);
  v36 = (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v31 * (float)0.5)) * (float)v35) - (float)1.5)
              * (float)v35);
  v37 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v35
                                                                              * (float)((float)v31 * (float)0.5))
                                                                      * (float)v35)
                                                              - (float)1.5)
                                              * (float)v35)
                                      * (float)((float)v31 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v35 * (float)((float)v31 * (float)0.5))
                                                              * (float)v35)
                                                      - (float)1.5)
                                      * (float)v35))
                      - (float)1.5);
  v38 = (float)((float)((float)v37 * (float)v36) * (float)v34);
  this->refForward.x = (float)v30
                     * (float)((float)-(float)((float)((float)v38 * (float)((float)v37 * (float)v36)) - (float)1.5)
                             * (float)((float)v37 * (float)v36));
  this->refForward.y = (float)v29
                     * (float)((float)-(float)((float)((float)v38 * (float)((float)v37 * (float)v36)) - (float)1.5)
                             * (float)((float)v37 * (float)v36));
  this->refForward.z = (float)v28
                     * (float)((float)-(float)((float)((float)v38 * (float)((float)v37 * (float)v36)) - (float)1.5)
                             * (float)((float)v37 * (float)v36));
  idVec3::NormalVectors(this: &this->refForward, left: &this->refLeft, down: &this->refDown);
}


// ========================================================================
// ?Damage@idVerletChain@@QAA_NHHMAAUdamageMorph_t@@@Z
// EA  : 0x82C14290
// RVA : 0x00C14290
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

int __fastcall idVerletChain::Damage(
        idVerletChain *this,
        int constraintId,
        int gameTime,
        double damage,
        damageMorph_t *morph,
        int a6)
{
  int v8; // r28
  int v9; // r26
  idVerletChain::constraint_t *v10; // r11
  int v11; // r23
  int index1; // r27
  int index2; // r21
  int v14; // r20
  double health; // fp27
  idVerletChain::particle_t *v16; // r10
  double v17; // fp0
  double v18; // fp28
  idVerletChain::particle_t *v19; // r10
  double v20; // fp0
  idVerletChain::particle_t *list; // r11
  idList<idVerletChain::particle_t,5> *p_points; // r31
  int v23; // r24
  double v24; // fp29
  int v25; // r25
  idVerletChain::particle_t *v26; // r11
  double v27; // fp30
  int v28; // r29
  char *v29; // r10
  bool *p_anchor; // r11
  int i; // ctr
  int v32; // r3
  idVerletChain::constraint_t *v33; // r10
  double v34; // fp13
  double v35; // fp0
  int result; // r3
  char v37; // [sp+4Ch] [-C4h] BYREF
  idVerletChain::particle_t v38; // [sp+50h] [-C0h] BYREF

  v8 = constraintId;
  v9 = -1;
  v10 = &this->constraints.list[constraintId];
  v11 = -1;
  index1 = v10->index1;
  index2 = v10->index2;
  if ( constraintId > 0 )
    v9 = v10[-1].index1;
  if ( constraintId < this->constraints.num - 1 )
    v11 = v10[1].index2;
  v14 = 0;
  if ( v9 >= 0 )
  {
    v16 = &this->points.list[v9];
    health = v16->health;
    if ( health > 1.0 )
    {
      v17 = (float)-(float)((float)((float)damage * (float)0.5) - v16->health);
      if ( v17 >= 1.0 )
      {
        if ( v17 <= health )
          health = (float)-(float)((float)((float)damage * (float)0.5) - v16->health);
      }
      else
      {
        health = 1.0;
      }
    }
  }
  else
  {
    health = 0.0;
  }
  if ( v11 >= 0 )
  {
    v19 = &this->points.list[v11];
    v18 = v19->health;
    if ( v18 > 1.0 )
    {
      v20 = (float)-(float)((float)((float)damage * (float)0.5) - v19->health);
      if ( v20 >= 1.0 )
      {
        if ( v20 <= v18 )
          v18 = (float)-(float)((float)((float)damage * (float)0.5) - v19->health);
      }
      else
      {
        v18 = 1.0;
      }
    }
  }
  else
  {
    v18 = 0.0;
  }
  list = this->points.list;
  p_points = &this->points;
  v23 = index1;
  v24 = (float)(list[index1].health - (float)damage);
  if ( v24 < 0.00000011920929 )
  {
    v24 = 0.0;
    v14 = 1;
  }
  v25 = index2;
  v26 = &list[index2];
  v27 = (float)(v26->health - (float)damage);
  if ( v27 < 0.00000011920929 )
  {
    v27 = 0.0;
    v14 = 1;
  }
  v28 = gameTime + 1000;
  if ( (_BYTE)v14 != 0 )
  {
    this->brokenPointIndex = index2;
    v29 = &v37;
    p_anchor = &v26[-1].anchor;
    for ( i = 10; i != 0; --i )
    {
      p_anchor += 4;
      v29 += 4;
      *(_DWORD *)v29 = *(_DWORD *)p_anchor;
    }
    v38.anchor = false;
    v32 = idList<idVerletChain::particle_t,5>::Append(this: &this->points, obj: &v38);
    this->orientations.list[index1].index2 = v32;
    this->constraints.list[v8].index2 = v32;
    v33 = &this->constraints.list[v8];
    if ( p_points->list[v33->index1].anchor )
      v34 = 0.0;
    else
      v34 = 1.0;
    if ( p_points->list[v33->index2].anchor )
      v35 = 0.0;
    else
      v35 = 1.0;
    v28 += 4000;
    v33->ratio1 = (float)((float)1.0 / (float)((float)v35 + (float)v34)) * (float)v34;
    this->constraints.list[v8].ratio2 = (float)((float)1.0 / (float)((float)v35 + (float)v34)) * (float)v35;
  }
  *(float *)a6 = (float)1.0 - (float)((float)health / this->maxHealth);
  *(float *)(a6 + 4) = (float)1.0 - (float)((float)v24 / this->maxHealth);
  *(float *)(a6 + 8) = (float)1.0 - (float)((float)v27 / this->maxHealth);
  *(float *)(a6 + 12) = (float)1.0 - (float)((float)v18 / this->maxHealth);
  *(_DWORD *)(a6 + 16) = v9;
  *(_DWORD *)(a6 + 20) = index1;
  *(_DWORD *)(a6 + 24) = index2;
  *(_DWORD *)(a6 + 28) = v11;
  if ( v9 >= 0 )
  {
    p_points->list[v9].health = health;
    p_points->list[v9].healthStamp = health;
    p_points->list[v9].timeStamp = v28;
  }
  result = v14;
  p_points->list[v23].timeStamp = v28;
  p_points->list[v23].health = v24;
  p_points->list[v23].healthStamp = v24;
  p_points->list[v25].timeStamp = v28;
  p_points->list[v25].healthStamp = v27;
  p_points->list[v25].health = v27;
  if ( v11 >= 0 )
  {
    p_points->list[v11].health = v18;
    p_points->list[v11].healthStamp = v18;
    p_points->list[v11].timeStamp = v28;
  }
  return result;
}


// ========================================================================
// ?Update@idVerletChain@@QAAX_N0M@Z
// EA  : 0x82C14610
// RVA : 0x00C14610
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::Update(
        idVerletChain *this,
        bool clearCollisionSpheres,
        bool isStiff,
        double gravityScale)
{
  double v8; // fp1
  idVerletChain *v9; // r3

  gameLocal->GetGameSecPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  if ( !isStiff && g_chainVerlet.valueInteger != 0 )
  {
    idVerletChain::Integrate(this, deltaTime: v8, gravityScale);
    idVerletChain::Constrain(this: v9);
  }
  if ( clearCollisionSpheres )
  {
    idList<idSphere,5>::SetNum(this: (idList<idVec4,5> *)&this->sphereCollisions, newNum: 0);
    idList<idVerletChain::plane_t,5>::SetNum(this: &this->planeCollisions, newNum: 0);
  }
}


// ========================================================================
// ?AddCollisionPlane@idVerletChain@@QAAXABVidPlane@@_N1@Z
// EA  : 0x82C146B8
// RVA : 0x00C146B8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::AddCollisionPlane(
        idVerletChain *this,
        const idPlane *plane,
        bool skipStart,
        bool skipEnd)
{
  BOOL v4; // r11
  float b; // r8
  float c; // r7
  bool v7; // cr58
  float d; // r5
  int v9; // r7
  idLobbyBackend *brokenPointIndex; // r9
  int v11; // r7
  idSessionKeyMgr::sessionKey_t v12; // [sp+50h] [-30h] BYREF

  v4 = skipStart;
  b = plane->b;
  c = plane->c;
  v7 = !skipStart;
  d = plane->d;
  v12.refCount = LODWORD(plane->a);
  *(float *)v12.sessionID.ab = b;
  *(float *)&v12.sessionID.ab[4] = c;
  *(float *)v12.keyExchangeKey.ab = d;
  if ( !v7 )
    goto LABEL_5;
  if ( !skipEnd )
  {
    *(_DWORD *)&v12.keyExchangeKey.ab[12] = this->points.num;
LABEL_9:
    *(_DWORD *)&v12.keyExchangeKey.ab[4] = 0;
    goto LABEL_10;
  }
  if ( v4 )
  {
LABEL_5:
    v9 = this->points.num - this->brokenPointIndex - 1;
    *(_DWORD *)&v12.keyExchangeKey.ab[4] = this->brokenPointIndex;
    *(_DWORD *)&v12.keyExchangeKey.ab[12] = v9;
LABEL_10:
    *(_DWORD *)&v12.keyExchangeKey.ab[8] = 0;
    v12.lobbyOwner = nullptr;
    goto LABEL_11;
  }
  if ( !skipEnd )
  {
    *(_DWORD *)&v12.keyExchangeKey.ab[12] = 0;
    goto LABEL_9;
  }
  brokenPointIndex = (idLobbyBackend *)this->brokenPointIndex;
  v11 = this->points.num - 1;
  *(_DWORD *)&v12.keyExchangeKey.ab[12] = 1;
  *(_DWORD *)&v12.keyExchangeKey.ab[8] = 0;
  *(_DWORD *)&v12.keyExchangeKey.ab[4] = v11;
  v12.lobbyOwner = brokenPointIndex;
LABEL_11:
  idList<idSessionKeyMgr::sessionKey_t,5>::Append(
    this: (idList<idSessionKeyMgr::sessionKey_t,5> *)&this->planeCollisions,
    obj: &v12);
}


// ========================================================================
// ?Damage@idFuncChain@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C147A0
// RVA : 0x00C147A0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

float __fastcall idFuncChain::Damage(
        idFuncChain *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  long double v13; // fp2
  long double v14; // fp2
  double v15; // fp11
  float v16; // r23
  double v17; // fp30
  double v18; // fp29
  unsigned __int8 v19; // r11
  int v20; // r29
  double v21; // fp1
  double v22; // fp31
  float x; // r10
  double v24; // fp0
  float y; // r9
  double v26; // fp13
  double v27; // fp10
  double v28; // fp2
  int BestPoint; // r4
  int BestConstraint; // r29
  unsigned __int8 v31; // r26
  int v32; // r3
  damageMorph_t *v33; // r6
  unsigned __int8 v34; // r3
  int v35; // r25
  float v36; // r28
  float v37; // r29
  float *v38; // r3
  double v39; // fp28
  double v40; // fp27
  double v41; // fp26
  double v42; // fp0
  double v43; // fp2
  double v44; // fp1
  double v45; // fp30
  double v46; // fp29
  double v47; // fp25
  double v48; // fp1
  double v49; // fp30
  double v50; // fp29
  double v51; // fp28
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelChain *v53; // r3
  idRenderModelChain *v54; // r30
  const idSoundShader *soundBreak; // r5
  idMat3 v57; // [sp+50h] [-110h] BYREF
  float v58[4]; // [sp+80h] [-E0h] BYREF
  int v59; // [sp+90h] [-D0h]
  float v60; // [sp+94h] [-CCh]
  float v61; // [sp+98h] [-C8h]
  int v62; // [sp+9Ch] [-C4h]
  idMat3 v63; // [sp+A0h] [-C0h] BYREF

  *(double *)&v13 = (float)(s_Time
                          / (float)__SPAIR64__(
                                     (idJoystickXenon *)&joystick.joyAxis[0][2],
                                     idGameTimeManager::GetGameMsPerFrame(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED)));
  v14 = ceil(x: v13);
  v15 = (float)*(double *)&v14;
  LODWORD(v16) = 1;
  v17 = s_forceMin;
  v18 = s_forceMax;
  LODWORD(v57.mat[0].y) = (int)v15;
  if ( (int)v15 >= 1 )
    LODWORD(v16) = (int)v15;
  if ( damageDef->maxDamage < (double)this->maxHealth || (v19 = 1, (damageDef->damageTypes & 0x80) == 0) )
    v19 = 0;
  v20 = v19;
  if ( v19 != 0 || (this->damageTypes & damageDef->damageTypes) != 0 )
  {
    v22 = (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale);
    if ( v20 != 0 )
      v22 = (float)(this->maxHealth + (float)1.0);
    idMat3::Inverse(this: &v63, result: &this->spawnOrientation);
    x = this->spawnPosition.x;
    v24 = a8[15];
    y = this->spawnPosition.y;
    v26 = a8[16];
    v57.mat[0].z = this->spawnPosition.z;
    v57.mat[0].x = x;
    v57.mat[0].y = y;
    v27 = (float)(a8[14] - x);
    v28 = (float)((float)(v63.mat[0].z * (float)(a8[14] - x))
                + (float)((float)(v63.mat[2].z * (float)((float)v26 - v57.mat[0].z))
                        + (float)(v63.mat[1].z * (float)((float)v24 - y))));
    v57.mat[0].x = (float)(v63.mat[0].x * (float)(a8[14] - x))
                 + (float)((float)(v63.mat[2].x * (float)((float)v26 - v57.mat[0].z))
                         + (float)(v63.mat[1].x * (float)((float)v24 - y)));
    v57.mat[0].y = (float)(v63.mat[0].y * (float)v27)
                 + (float)((float)(v63.mat[2].y * (float)((float)v26 - v57.mat[0].z))
                         + (float)(v63.mat[1].y * (float)((float)v24 - y)));
    v57.mat[0].z = v28;
    BestPoint = idVerletChain::GetBestPoint(this: &this->verlet, position: v57.mat);
    if ( BestPoint >= 0 )
      BestConstraint = idVerletChain::GetBestConstraint(this: &this->verlet, id: BestPoint, position: v57.mat);
    else
      BestConstraint = -1;
    v31 = 0;
    if ( BestConstraint >= 0 )
    {
      v32 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v34 = idVerletChain::Damage(
              this: &this->verlet,
              constraintId: BestConstraint,
              gameTime: v32,
              damage: v22,
              morph: v33,
              a6: (int)v58);
      v35 = v34;
      v36 = v61;
      v31 = v34;
      v37 = v60;
      if ( v34 != 0 )
      {
        v38 = (float *)idMat3::Inverse(this: &v57, result: &this->spawnOrientation);
        v39 = (float)((float)(trace->fraction * *v38)
                    + (float)((float)(v38[3] * trace->endpos.x) + (float)(v38[6] * trace->endpos.y)));
        v40 = (float)((float)(v38[7] * trace->endpos.y)
                    + (float)((float)(v38[1] * trace->fraction) + (float)(v38[4] * trace->endpos.x)));
        v41 = (float)((float)(v38[8] * trace->endpos.y)
                    + (float)((float)(v38[2] * trace->fraction) + (float)(v38[5] * trace->endpos.x)));
        v42 = RandomFloat(min: v17, max: v18);
        v43 = v18;
        v44 = v17;
        v45 = (float)((float)v39 * (float)v42);
        v46 = (float)((float)v40 * (float)v42);
        v47 = (float)((float)v41 * (float)v42);
        v48 = RandomFloat(min: v44, max: v43);
        v57.mat[0].x = v45;
        v57.mat[1].y = v37;
        v57.mat[0].y = v46;
        v57.mat[1].x = v16;
        v57.mat[0].z = v47;
        v49 = (float)((float)v39 * (float)v48);
        v50 = (float)((float)v40 * (float)v48);
        v51 = (float)((float)v41 * (float)v48);
        idList<idVerletChain::force_t,5>::Append(this: &this->verlet.forces, obj: (const idVerletChain::force_t *)&v57);
        v57.mat[0].x = v49;
        v57.mat[0].y = v50;
        v57.mat[1].y = v36;
        v57.mat[0].z = v51;
        v57.mat[1].x = v16;
        idList<idVerletChain::force_t,5>::Append(this: &this->verlet.forces, obj: (const idVerletChain::force_t *)&v57);
        *(float *)&this->brokenLink = v37;
      }
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      v53 = (idRenderModelChain *)_RTDynamicCast(
                                    inptr: RenderModelFromPresentable,
                                    VfDelta: 0,
                                    SrcType: &idRenderModel `RTTI Type Descriptor',
                                    TargetType: &idRenderModelChain `RTTI Type Descriptor',
                                    isReference: 0);
      v54 = v53;
      if ( v53 != nullptr )
      {
        if ( v59 >= 0 )
          idRenderModelChain::SetLinkMorphAmount(this: v53, id: v59, amount: v58[0]);
        idRenderModelChain::SetLinkMorphAmount(this: v54, id: SLODWORD(v37), amount: v58[1]);
        idRenderModelChain::SetLinkMorphAmount(this: v54, id: SLODWORD(v36), amount: v58[2]);
        if ( v62 >= 0 )
          idRenderModelChain::SetLinkMorphAmount(this: v54, id: v62, amount: v58[3]);
        if ( v35 != 0 )
          idRenderModelChain::RemoveSmoothSkinning(this: v54, id: this->brokenLink);
      }
    }
    if ( v31 != 0 )
    {
      idFuncChain::DisableChain(this);
      this->breakPosition.x = a8[1];
      this->breakPosition.y = a8[2];
      this->breakPosition.z = a8[3];
      soundBreak = this->soundBreak;
      if ( soundBreak != nullptr )
      {
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_FX,
          shader: soundBreak,
          soundShaderFlags: 0,
          peerMask: 0xFFu);
        idEntity::UpdateSound(this);
      }
    }
    v21 = v22;
  }
  else
  {
    v21 = 0.0;
  }
  return *((float *)&v21 + 1);
}


// ========================================================================
// ?AddCollisionInfo@idFuncChain@@AAAXXZ
// EA  : 0x82C14BC0
// RVA : 0x00C14BC0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::AddCollisionInfo(idFuncChain *this)
{
  char *v1; // r10
  float *p_z; // r11
  int i; // ctr
  float y; // r10
  float z; // r9
  double v7; // fp31
  double v8; // fp30
  int v9; // r30
  int v10; // r31
  int v11; // r30
  int v12; // r31
  idFuncChain::plane_t *v13; // r11
  double v14; // fp12
  double v15; // fp11
  double v16; // fp10
  double v17; // fp9
  char v18; // r7
  double v19; // fp8
  bool v20; // r6
  int v21; // r23
  int v22; // r25
  idEntityPtr<idEntity> *list; // r11
  int value; // r9
  idEntity *v25; // r3
  idAnimatedEntity *v26; // r3
  int v27; // r27
  double v28; // fp31
  const idJointMat *v29; // r26
  double v30; // fp30
  int v31; // r30
  double v32; // fp29
  double v33; // fp28
  int v34; // r31
  double v35; // fp27
  double v36; // fp26
  double v37; // fp25
  double v38; // fp24
  double v39; // fp23
  double c; // fp22
  int v41; // r11
  double v42; // fp8
  double v43; // fp7
  double v44; // fp6
  float *v45; // r11
  double v46; // fp17
  double v47; // fp7
  double v48; // fp6
  double v49; // fp4
  double v50; // fp3
  double v51; // fp7
  double v52; // fp6
  double v53; // fp9
  float v54; // [sp+50h] [-1C0h] BYREF
  float x; // [sp+58h] [-1B8h]
  float v56; // [sp+5Ch] [-1B4h]
  float v57; // [sp+60h] [-1B0h]
  idSphere v58; // [sp+70h] [-1A0h] BYREF
  idPlane v59; // [sp+80h] [-190h] BYREF
  idMat3 v60; // [sp+90h] [-180h] BYREF
  float v61; // [sp+B4h] [-15Ch]
  float v62; // [sp+B8h] [-158h]
  float v63; // [sp+BCh] [-154h]
  float v64; // [sp+C0h] [-150h]
  float v65; // [sp+C4h] [-14Ch]
  char v66; // [sp+CCh] [-144h] BYREF
  idMat3 v67; // [sp+D0h] [-140h] BYREF
  idVec3 v68; // [sp+F8h] [-118h] BYREF
  cm_sphereModelPtrs_t v69; // [sp+110h] [-100h] BYREF

  v1 = &v66;
  p_z = &this->spawnPosition.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v1 += 4;
    *(float *)v1 = *p_z;
  }
  y = this->spawnPosition.y;
  z = this->spawnPosition.z;
  x = this->spawnPosition.x;
  v56 = y;
  v57 = z;
  v7 = z;
  v8 = y;
  idMat3::Inverse(this: &v60, result: &v67);
  v9 = 0;
  if ( this->collisions.num > 0 )
  {
    v10 = 0;
    do
    {
      idFuncChain::GetWorldPosition(
        this,
        origin: &this->collisions.list[v10].origin,
        worldOrigin: &v68,
        worldAxis: &v67);
      v58.radius = this->collisions.list[v10].radius;
      v58.origin.x = (float)(v60.mat[0].x * (float)(v68.x - x))
                   + (float)((float)(v60.mat[2].x * (float)(v68.z - (float)v7))
                           + (float)(v60.mat[1].x * (float)(v68.y - (float)v8)));
      v58.origin.y = (float)(v60.mat[0].y * (float)(v68.x - x))
                   + (float)((float)(v60.mat[2].y * (float)(v68.z - (float)v7))
                           + (float)(v60.mat[1].y * (float)(v68.y - (float)v8)));
      v58.origin.z = (float)(v60.mat[0].z * (float)(v68.x - x))
                   + (float)((float)(v60.mat[2].z * (float)(v68.z - (float)v7))
                           + (float)(v60.mat[1].z * (float)(v68.y - (float)v8)));
      idList<idSphere,5>::Append(this: (idList<idSphere,81> *)&this->verlet.sphereCollisions, obj: &v58);
      ++v9;
      ++v10;
    }
    while ( v9 < this->collisions.num );
  }
  v11 = 0;
  if ( this->collisionPlanes.num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = &this->collisionPlanes.list[v12];
      v14 = (float)(v13->center.y * v13->normal.y);
      v15 = v13->normal.z;
      v16 = v13->center.z;
      v17 = v13->normal.x;
      v18 = _cntlzw(v13->startSegment);
      v19 = v13->center.x;
      v20 = (_cntlzw(v13->endSegment) & 0x20) != 0;
      v59.b = v13->normal.y;
      v59.c = v15;
      v59.a = v17;
      v59.d = -(float)((float)((float)v17 * (float)v19) + (float)((float)((float)v16 * (float)v15) + (float)v14));
      idVerletChain::AddCollisionPlane(this: &this->verlet, plane: &v59, skipStart: (v18 & 0x20) != 0, skipEnd: v20);
      ++v11;
      ++v12;
    }
    while ( v11 < this->collisionPlanes.num );
  }
  v21 = 0;
  if ( this->animCollisions.num > 0 )
  {
    v22 = 0;
    do
    {
      list = this->animCollisions.list;
      v54 = 0.0;
      value = list[v22].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v25 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v26 = (idAnimatedEntity *)idEntity::CastTo(c: v25);
      }
      else
      {
        v26 = nullptr;
      }
      v27 = SetupCollisionSpherePtrsFromEntity(
              entity: v26,
              csPtrs: &v69,
              origin: (idVec3 *)&v59,
              axis: &v67,
              modelJoints: (const idJointMat **)&v54);
      if ( v27 > 0 )
      {
        v28 = v67.mat[2].z;
        v29 = (const idJointMat *)LODWORD(v54);
        v30 = v67.mat[2].y;
        v31 = 0;
        v32 = v67.mat[2].x;
        v33 = v67.mat[1].z;
        v34 = 0;
        v35 = v67.mat[1].y;
        v36 = v67.mat[1].x;
        v37 = v67.mat[0].z;
        v38 = v67.mat[0].y;
        v39 = v67.mat[0].x;
        c = v59.c;
        do
        {
          v65 = v60.mat[0].y;
          v64 = v60.mat[0].z;
          v41 = v69.joint[v31];
          v42 = v69.offsetY[v34];
          v43 = v69.offsetZ[v34];
          v58.radius = v69.radius[v34];
          v44 = v69.offsetX[v34];
          v63 = v60.mat[1].z;
          v45 = &v29->mat[4 * v41 + 4 * __ROL4__(v41, 1)];
          v61 = v60.mat[1].y;
          v62 = v60.mat[0].x;
          v54 = v60.mat[1].x;
          v46 = (float)((float)(v45[6] * (float)v43) + (float)(v45[5] * (float)v42));
          v49 = (float)((float)((float)(v45[8] * (float)v44)
                              + (float)((float)(v45[10] * (float)v43) + (float)(v45[9] * (float)v42)))
                      + v45[11]);
          v47 = (float)((float)(*v45 * (float)v44) + (float)((float)(v45[2] * (float)v43) + (float)(v45[1] * (float)v42)));
          v48 = (float)((float)((float)(v45[4] * (float)v44) + (float)v46) + v45[7]);
          v50 = (float)((float)v47 + v45[3]);
          v53 = (float)((float)((float)((float)((float)v39 * (float)((float)v47 + v45[3]))
                                      + (float)((float)((float)v32 * (float)v49) + (float)((float)v36 * (float)v48)))
                              + v59.a)
                      - x);
          v51 = (float)((float)((float)v37 * (float)((float)v47 + v45[3]))
                      + (float)((float)((float)v28 * (float)v49) + (float)((float)v33 * (float)v48)));
          v52 = (float)((float)((float)v38 * (float)v50)
                      + (float)((float)((float)v30 * (float)v49) + (float)((float)v35 * (float)v48)));
          v58.origin.x = (float)((float)v53 * v60.mat[0].x)
                       + (float)((float)((float)((float)(v59.b + (float)v52) - v56) * v60.mat[1].x)
                               + (float)((float)((float)((float)c + (float)v51) - v57) * v60.mat[2].x));
          v58.origin.y = (float)(v60.mat[0].y * (float)v53)
                       + (float)((float)((float)((float)(v59.b + (float)v52) - v56) * v60.mat[1].y)
                               + (float)((float)((float)((float)c + (float)v51) - v57) * v60.mat[2].y));
          v58.origin.z = (float)(v60.mat[0].z * (float)v53)
                       + (float)((float)((float)((float)(v59.b + (float)v52) - v56) * v60.mat[1].z)
                               + (float)((float)((float)((float)c + (float)v51) - v57) * v60.mat[2].z));
          idList<idSphere,5>::Append(this: (idList<idSphere,81> *)&this->verlet.sphereCollisions, obj: &v58);
          ++v31;
          ++v34;
        }
        while ( v31 < v27 );
      }
      ++v21;
      ++v22;
    }
    while ( v21 < this->animCollisions.num );
  }
}


// ========================================================================
// ?Think@idFuncChain@@UAAXXZ
// EA  : 0x82C14FF0
// RVA : 0x00C14FF0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::Think(idFuncChain *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelChain *v3; // r3
  idRenderModelChain *v4; // r19
  int NumLinks; // r3
  char *v6; // r10
  int v7; // r18
  float *p_z; // r11
  int i; // ctr
  float y; // r10
  float z; // r9
  double v12; // fp20
  idVerletChain::particle_t *list; // r8
  double v14; // fp19
  double v15; // fp18
  double v16; // fp5
  double v17; // fp1
  double v18; // fp12
  double v19; // fp7
  double v20; // fp6
  double v21; // fp4
  idVerletChain::particle_t *v22; // r11
  double v23; // fp9
  double v24; // fp6
  double v25; // fp5
  char v26; // r11
  bool v27; // r25
  double v28; // fp29
  double v29; // fp28
  double v30; // fp27
  double v31; // fp26
  double v32; // fp25
  double v33; // fp24
  double v34; // fp23
  double v35; // fp22
  double v36; // fp21
  int v37; // r28
  int v38; // r30
  int v39; // r29
  idColor *v40; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idSphere *v44; // r3
  double v45; // fp3
  double v46; // fp1
  int brokenLink; // r10
  double v48; // fp30
  double valueFloat; // fp1
  long double v50; // fp2
  long double v51; // fp2
  BOOL randomRotate; // r7
  double v53; // fp14
  double v54; // fp13
  double v55; // fp8
  int v56; // r11
  double v57; // fp7
  const char *str; // r9
  double v59; // fp17
  double v60; // fp16
  double v61; // fp15
  int v62; // r8
  int v63; // r27
  int v64; // r24
  int v65; // r30
  int v66; // r25
  char updated; // r29
  idVerletChain::particle_t *v68; // r11
  idVec3 *y_low; // r9
  double v70; // fp13
  double v71; // fp0
  double v72; // fp12
  double v73; // fp6
  double v74; // fp5
  double v75; // fp4
  double v78; // fp2
  double v79; // fp1
  double v80; // fp1
  double v81; // fp0
  double v82; // fp13
  double v83; // fp12
  double v86; // fp4
  double v87; // fp8
  const idMat3 *v88; // r3
  double v89; // fp8
  double v90; // fp7
  double v91; // fp6
  double v92; // fp5
  double v93; // fp4
  double v94; // fp3
  double v95; // fp2
  double v96; // fp1
  double v97; // fp0
  float v98; // r10
  int v99; // r11
  float v100; // r5
  int v101; // r30
  int v102; // r3
  const idJointMat *v103; // r3
  double v104; // fp13
  double v105; // fp12
  int v106; // r29
  int v107; // r30
  int v108; // r28
  int v109; // r3
  const idJointMat *LinkPosition; // r3
  double v111; // fp13
  double v112; // fp12
  const idJointMat *v113; // r3
  double v114; // fp10
  double v115; // fp9
  idSoundEmitter *emitter1; // r3
  idSoundEmitter *emitter2; // r3
  int v118; // r30
  int v119; // r28
  int v120; // r27
  idVerletChain::particle_t *v121; // r10
  float v122; // r3
  float v123; // r9
  float v124; // r10
  double v125; // fp16
  double v126; // fp15
  double v127; // fp17
  int v128; // r28
  double v131; // fp30
  double v132; // fp1
  double v133; // fp0
  double v134; // fp11
  double v135; // fp9
  double v136; // fp6
  idPresentable *presentable; // r3
  float v138; // [sp+8h] [-548h]
  float v139; // [sp+Ch] [-544h]
  float v140; // [sp+10h] [-540h]
  float v141; // [sp+14h] [-53Ch]
  float v142; // [sp+18h] [-538h]
  float v143; // [sp+1Ch] [-534h]
  float v144; // [sp+20h] [-530h]
  float v145; // [sp+24h] [-52Ch]
  float v146; // [sp+28h] [-528h]
  float v147; // [sp+2Ch] [-524h]
  float v148; // [sp+30h] [-520h]
  float v149; // [sp+34h] [-51Ch]
  float v150; // [sp+38h] [-518h]
  float v151; // [sp+3Ch] [-514h]
  float v152; // [sp+40h] [-510h]
  float v153; // [sp+44h] [-50Ch]
  float v154; // [sp+48h] [-508h]
  float v155; // [sp+4Ch] [-504h]
  float v156; // [sp+60h] [-4F0h] BYREF
  float maxHealth; // [sp+64h] [-4ECh] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v158[2]; // [sp+68h] [-4E8h] BYREF
  float x; // [sp+70h] [-4E0h]
  float v160; // [sp+74h] [-4DCh]
  float v161; // [sp+78h] [-4D8h]
  float v162; // [sp+7Ch] [-4D4h]
  float v163; // [sp+80h] [-4D0h] BYREF
  float v164; // [sp+84h] [-4CCh]
  float v165; // [sp+88h] [-4C8h]
  idVec3 v166; // [sp+90h] [-4C0h] BYREF
  idVec3 v167; // [sp+A0h] [-4B0h] BYREF
  idVec3 v168; // [sp+B0h] [-4A0h] BYREF
  float v169; // [sp+C0h] [-490h] BYREF
  float v170; // [sp+C4h] [-48Ch]
  float v171; // [sp+C8h] [-488h]
  char v172; // [sp+CCh] [-484h] BYREF
  idMat3 v173; // [sp+D0h] [-480h] BYREF
  idMat3 v174; // [sp+100h] [-450h] BYREF
  float v175; // [sp+124h] [-42Ch]
  float v176; // [sp+130h] [-420h] BYREF
  float v177; // [sp+134h] [-41Ch]
  float v178; // [sp+138h] [-418h]
  float radius; // [sp+13Ch] [-414h]
  idColor v180; // [sp+140h] [-410h] BYREF
  float v181[4]; // [sp+150h] [-400h] BYREF
  idVec3 v182; // [sp+160h] [-3F0h] BYREF
  float v183[4]; // [sp+170h] [-3E0h] BYREF
  float v184[4]; // [sp+180h] [-3D0h] BYREF
  float v185[4]; // [sp+190h] [-3C0h] BYREF
  float v186[4]; // [sp+1A0h] [-3B0h] BYREF
  idVec3 v187; // [sp+1B0h] [-3A0h] BYREF
  float v188; // [sp+1C0h] [-390h] BYREF
  float v189; // [sp+1C4h] [-38Ch]
  float v190; // [sp+1C8h] [-388h]
  float v191[4]; // [sp+1D0h] [-380h] BYREF
  int x_low; // [sp+1E0h] [-370h]
  idVec3 *v193; // [sp+1E4h] [-36Ch]
  idMat3 v194; // [sp+1F0h] [-360h] BYREF
  float v195[4]; // [sp+220h] [-330h] BYREF
  idMat3 v196; // [sp+230h] [-320h] BYREF
  soundShaderParms_t v197; // [sp+260h] [-2F0h] BYREF
  soundShaderParms_t v198; // [sp+300h] [-250h] BYREF
  soundShaderParms_t v199[2]; // [sp+3A0h] [-1B0h] BYREF

  if ( !idEntity::UpdateDormant(this) )
  {
    idEntity::Think(this);
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
    v3 = (idRenderModelChain *)_RTDynamicCast(
                                 inptr: RenderModelFromPresentable,
                                 VfDelta: 0,
                                 SrcType: &idRenderModel `RTTI Type Descriptor',
                                 TargetType: &idRenderModelChain `RTTI Type Descriptor',
                                 isReference: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      NumLinks = idRenderModelChain::GetNumLinks(this: v3);
      v6 = &v172;
      v7 = NumLinks;
      p_z = &this->spawnPosition.z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v6 += 4;
        *(float *)v6 = *p_z;
      }
      y = this->spawnPosition.y;
      z = this->spawnPosition.z;
      x = this->spawnPosition.x;
      v160 = y;
      v161 = z;
      idMat3::Inverse(this: &v174, result: &v173);
      idFuncChain::GetWorldPosition(this, origin: &this->state.start, worldOrigin: &v187, worldAxis: &v194);
      v12 = v161;
      list = this->verlet.points.list;
      v14 = x;
      v15 = v160;
      v16 = (float)(v187.y - v160);
      v17 = v174.mat[1].y;
      v18 = v174.mat[1].z;
      v19 = (float)((float)(v174.mat[0].y * (float)(v187.x - x)) + (float)(v174.mat[2].y * (float)(v187.z - v161)));
      v20 = (float)((float)(v174.mat[0].z * (float)(v187.x - x)) + (float)(v174.mat[2].z * (float)(v187.z - v161)));
      v21 = (float)((float)(v174.mat[1].x * (float)(v187.y - v160))
                  + (float)((float)(v174.mat[0].x * (float)(v187.x - x))
                          + (float)(v174.mat[2].x * (float)(v187.z - v161))));
      list->oldPos.x = (float)(v174.mat[1].x * (float)(v187.y - v160))
                     + (float)((float)(v174.mat[0].x * (float)(v187.x - x))
                             + (float)(v174.mat[2].x * (float)(v187.z - v161)));
      list->oldPos.y = (float)((float)v17 * (float)v16) + (float)v19;
      list->oldPos.z = (float)((float)v18 * (float)v16) + (float)v20;
      list->currentPos.x = v21;
      list->currentPos.y = (float)((float)v17 * (float)v16) + (float)v19;
      list->currentPos.z = (float)((float)v18 * (float)v16) + (float)v20;
      idFuncChain::GetWorldPosition(this, origin: &this->state.end, worldOrigin: &v182, worldAxis: &v194);
      v22 = &this->verlet.points.list[v7 - 1];
      v23 = (float)((float)((float)(v182.z - (float)v12) * v174.mat[2].x)
                  + (float)((float)((float)(v182.x - (float)v14) * v174.mat[0].x)
                          + (float)((float)(v182.y - (float)v15) * v174.mat[1].x)));
      v24 = (float)((float)((float)(v182.z - (float)v12) * v174.mat[2].y)
                  + (float)((float)(v174.mat[0].y * (float)(v182.x - (float)v14))
                          + (float)((float)(v182.y - (float)v15) * v174.mat[1].y)));
      v25 = (float)((float)((float)(v182.z - (float)v12) * v174.mat[2].z)
                  + (float)((float)(v174.mat[0].z * (float)(v182.x - (float)v14))
                          + (float)((float)(v182.y - (float)v15) * v174.mat[1].z)));
      v22->oldPos.x = (float)((float)(v182.z - (float)v12) * v174.mat[2].x)
                    + (float)((float)((float)(v182.x - (float)v14) * v174.mat[0].x)
                            + (float)((float)(v182.y - (float)v15) * v174.mat[1].x));
      v22->oldPos.y = v24;
      v22->oldPos.z = v25;
      v22->currentPos.x = v23;
      v22->currentPos.y = v24;
      v22->currentPos.z = v25;
      if ( this->chainDef.extraLength > 0.00000011920929 || (v26 = 1, this->brokenLink != -1) )
        v26 = 0;
      v27 = v26;
      idFuncChain::AddCollisionInfo(this);
      v28 = v173.mat[2].z;
      v29 = v173.mat[2].y;
      v30 = v173.mat[2].x;
      v31 = v173.mat[1].z;
      v32 = v173.mat[1].y;
      v33 = v173.mat[1].x;
      v34 = v173.mat[0].z;
      v35 = v173.mat[0].y;
      v36 = v173.mat[0].x;
      if ( g_chainVerletCollision.valueInteger != 0 )
      {
        v37 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v38 = 0;
        if ( this->verlet.sphereCollisions.num > 0 )
        {
          v39 = 0;
          do
          {
            v40 = &idColor::colorGreen;
            if ( v38 >= this->collisions.num )
              v40 = &idColor::colorBlue;
            g = v40->g;
            b = v40->b;
            a = v40->a;
            v195[0] = v40->r;
            v195[1] = g;
            v195[2] = b;
            v195[3] = a;
            v44 = &this->verlet.sphereCollisions.list[v39];
            v176 = v44->origin.x;
            v177 = v44->origin.y;
            v178 = v44->origin.z;
            radius = v44->radius;
            v45 = (float)((float)((float)v28 * v178) + (float)((float)((float)v34 * v176) + (float)((float)v31 * v177)));
            v46 = (float)((float)((float)((float)v29 * v178)
                                + (float)((float)((float)v35 * v176) + (float)((float)v32 * v177)))
                        + (float)v15);
            v176 = (float)((float)((float)v30 * v178) + (float)((float)((float)v36 * v176) + (float)((float)v33 * v177)))
                 + (float)v14;
            v177 = v46;
            v178 = (float)v45 + (float)v12;
            clientGame->renderWorld->DebugSphere(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)v195,
              a3: (const idSphere *)&v176,
              a4: 12,
              a5: v37,
              a6: false);
            ++v38;
            ++v39;
          }
          while ( v38 < this->verlet.sphereCollisions.num );
        }
      }
      brokenLink = this->brokenLink;
      v48 = 1.0;
      v162 = 1.0;
      if ( brokenLink == -1 )
        valueFloat = g_chainVerletGravityScale.valueFloat;
      else
        valueFloat = 1.0;
      idVerletChain::Update(this: &this->verlet, clearCollisionSpheres: true, isStiff: v27, gravityScale: valueFloat);
      *(double *)&v50 = (float)(this->chainDef.startRotation * (float)0.0027777778);
      v51 = floor(x: v50);
      randomRotate = this->chainDef.randomRotate;
      v53 = 0.0;
      v175 = (float)-(float)((float)((float)*(double *)&v51 * (float)360.0) - this->chainDef.startRotation)
           * idMath::M_DEG2RAD;
      v156 = 0.0;
      if ( randomRotate )
        v54 = 90.0;
      else
        v54 = 0.0;
      v55 = this->verlet.refForward.y;
      v56 = 0;
      v57 = this->verlet.refForward.z;
      str = this->chainLinkModel->name.str;
      v59 = this->verlet.refLeft.x;
      v60 = this->verlet.refLeft.y;
      v61 = this->verlet.refLeft.z;
      v62 = *(unsigned __int8 *)str;
      x = this->verlet.refForward.x;
      v160 = v55;
      v161 = v57;
      v191[2] = idMath::M_DEG2RAD * (float)v54;
      v191[0] = (float)((float)v54 * (float)0.0) * idMath::M_DEG2RAD;
      v191[3] = (float)((float)v54 * (float)3.0) * idMath::M_DEG2RAD;
      v191[1] = (float)((float)v54 * (float)2.0) * idMath::M_DEG2RAD;
      if ( v62 != 0 )
      {
        do
        {
          ++str;
          v56 = 31 * v56 + (unsigned __int8)v62;
          LOBYTE(v62) = *str;
        }
        while ( *str != 0 );
      }
      v63 = v56;
      v64 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v65 = 0;
      if ( v7 > 0 )
      {
        v66 = 0;
        do
        {
          maxHealth = this->maxHealth;
          updated = idVerletChain::UpdateCooldown(this: &this->verlet, pointId: v65, gameTime: v64, health: &maxHealth);
          v68 = &this->verlet.points.list[v66];
          y_low = (idVec3 *)LODWORD(v68->currentPos.y);
          x_low = LODWORD(v68->currentPos.x);
          v193 = y_low;
          idVerletChain::GetNormal(this: (idVerletChain *)&v167, result: (idVec3 *)&this->verlet, pointId: v65);
          v70 = v167.y;
          v71 = v167.x;
          v72 = v167.z;
          if ( (float)((float)(v167.z * v167.z) + (float)((float)(v167.x * v167.x) + (float)(v167.y * v167.y))) <= 0.00000011920929 )
          {
            v71 = x;
            v70 = v160;
            v72 = v161;
            v167.x = x;
            v167.y = v160;
            v167.z = v161;
          }
          v173.mat[2].x = v71;
          v173.mat[2].y = v70;
          v173.mat[2].z = v72;
          v73 = (float)((float)((float)v70 * (float)v59) - (float)((float)v60 * (float)v71));
          v63 = 1103515245 * v63 + 12345;
          v74 = (float)((float)((float)v72 * (float)v60) - (float)((float)v70 * (float)v61));
          v75 = (float)((float)((float)v61 * (float)v71) - (float)((float)v72 * (float)v59));
          v158[0].value = v191[((v63 >> 16) & 0x7FFF) - 2 * (((v63 >> 16) & 0x7FFF) >> 1) + ((2 * v65) & 2)] + v175;
          _FP8 = (float)((float)((float)((float)v75 * (float)v75)
                               + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f3, f8, f9, f11 }
          v78 = __frsqrte(_FP3);
          v79 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v78
                                                                                              * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5))
                                                                                      * (float)v78)
                                                                              - (float)1.5)
                                                              * (float)v78)
                                                      * (float)((float)((float)((float)v75 * (float)v75)
                                                                      + (float)((float)((float)v74 * (float)v74)
                                                                              + (float)((float)v73 * (float)v73)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v78
                                                                                      * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73)))
                                                                                              * (float)0.5))
                                                                              * (float)v78)
                                                                      - (float)1.5)
                                                      * (float)v78))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v78
                                                              * (float)((float)((float)((float)v75 * (float)v75)
                                                                              + (float)((float)((float)v74 * (float)v74)
                                                                                      + (float)((float)v73 * (float)v73)))
                                                                      * (float)0.5))
                                                      * (float)v78)
                                              - (float)1.5)
                              * (float)v78));
          v173.mat[0].x = (float)v74
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78) * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78)
                                                                                                - (float)1.5)
                                                                                * (float)v78))
                                                                * (float)((float)((float)((float)v75 * (float)v75)
                                                                                + (float)((float)((float)v74 * (float)v74)
                                                                                        + (float)((float)v73 * (float)v73)))
                                                                        * (float)0.5))
                                                        * (float)v79)
                                                - (float)1.5)
                                * (float)v79);
          v173.mat[0].y = (float)v75
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78) * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78)
                                                                                                - (float)1.5)
                                                                                * (float)v78))
                                                                * (float)((float)((float)((float)v75 * (float)v75)
                                                                                + (float)((float)((float)v74 * (float)v74)
                                                                                        + (float)((float)v73 * (float)v73)))
                                                                        * (float)0.5))
                                                        * (float)v79)
                                                - (float)1.5)
                                * (float)v79);
          v173.mat[0].z = (float)v73
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78) * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78) - (float)1.5) * (float)v78))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v78 * (float)((float)((float)((float)v75 * (float)v75) + (float)((float)((float)v74 * (float)v74) + (float)((float)v73 * (float)v73))) * (float)0.5)) * (float)v78)
                                                                                                - (float)1.5)
                                                                                * (float)v78))
                                                                * (float)((float)((float)((float)v75 * (float)v75)
                                                                                + (float)((float)((float)v74 * (float)v74)
                                                                                        + (float)((float)v73 * (float)v73)))
                                                                        * (float)0.5))
                                                        * (float)v79)
                                                - (float)1.5)
                                * (float)v79);
          v80 = (float)(v173.mat[0].z * (float)v71);
          v81 = (float)((float)(v173.mat[0].y * (float)v71) - (float)((float)v70 * v173.mat[0].x));
          v82 = (float)((float)(v173.mat[0].z * (float)v70) - (float)(v173.mat[0].y * (float)v72));
          v83 = (float)((float)((float)v72 * v173.mat[0].x) - (float)v80);
          _FP7 = (float)((float)((float)((float)v83 * (float)v83)
                               + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f5, f7, f8, f11 }
          v86 = __frsqrte(_FP5);
          v87 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86
                                                                                              * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                      * (float)v86)
                                                                              - (float)1.5)
                                                              * (float)v86)
                                                      * (float)((float)((float)((float)v83 * (float)v83)
                                                                      + (float)((float)((float)v82 * (float)v82)
                                                                              + (float)((float)v81 * (float)v81)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v86
                                                                                      * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81)))
                                                                                              * (float)0.5))
                                                                              * (float)v86)
                                                                      - (float)1.5)
                                                      * (float)v86))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v86
                                                              * (float)((float)((float)((float)v83 * (float)v83)
                                                                              + (float)((float)((float)v82 * (float)v82)
                                                                                      + (float)((float)v81 * (float)v81)))
                                                                      * (float)0.5))
                                                      * (float)v86)
                                              - (float)1.5)
                              * (float)v86));
          v173.mat[1].x = (float)v82
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86)
                                                                                                - (float)1.5)
                                                                                * (float)v86))
                                                                * (float)((float)((float)((float)v83 * (float)v83)
                                                                                + (float)((float)((float)v82 * (float)v82)
                                                                                        + (float)((float)v81 * (float)v81)))
                                                                        * (float)0.5))
                                                        * (float)v87)
                                                - (float)1.5)
                                * (float)v87);
          v173.mat[1].y = (float)v83
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86)
                                                                                                - (float)1.5)
                                                                                * (float)v86))
                                                                * (float)((float)((float)((float)v83 * (float)v83)
                                                                                + (float)((float)((float)v82 * (float)v82)
                                                                                        + (float)((float)v81 * (float)v81)))
                                                                        * (float)0.5))
                                                        * (float)v87)
                                                - (float)1.5)
                                * (float)v87);
          v173.mat[1].z = (float)v81
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86) * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86) - (float)1.5) * (float)v86))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v86 * (float)((float)((float)((float)v83 * (float)v83) + (float)((float)((float)v82 * (float)v82) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v86)
                                                                                                - (float)1.5)
                                                                                * (float)v86))
                                                                * (float)((float)((float)((float)v83 * (float)v83)
                                                                                + (float)((float)((float)v82 * (float)v82)
                                                                                        + (float)((float)v81 * (float)v81)))
                                                                        * (float)0.5))
                                                        * (float)v87)
                                                - (float)1.5)
                                * (float)v87);
          v88 = idMat3::idMat3(this: &v196, axis: &v167, angle: v158);
          idMat3::operator*(this: &v194, result: &v173, a: v88);
          idRenderModelChain::SetLinkPosition(
            this: v4,
            id: x_low,
            origin: v193,
            axis: (idMat3 *)LODWORD(v194.mat[0].x),
            a5: SLODWORD(v194.mat[0].z),
            a6: SLODWORD(v194.mat[1].y),
            a7: SLODWORD(v194.mat[2].x),
            a8: SLODWORD(v194.mat[2].y),
            a9: v96,
            a10: v95,
            a11: v94,
            a12: v93,
            a13: v92,
            a14: v91,
            a15: v90,
            a16: v89,
            a17: v138,
            a18: v139,
            a19: v140,
            a20: v141,
            a21: v142,
            a22: v143,
            a23: v144,
            a24: v145,
            a25: v146,
            a26: v147,
            a27: v148,
            a28: v149,
            a29: v150,
            a30: v151,
            a31: v152,
            a32: v153,
            a33: v154,
            a34: v155,
            a35: v194.mat[2].z);
          if ( updated != 0 )
          {
            v97 = maxHealth;
            if ( maxHealth >= (double)v156 )
            {
              if ( v97 > this->maxHealth )
                v97 = this->maxHealth;
            }
            else
            {
              v97 = v156;
            }
            idRenderModelChain::SetLinkMorphAmount(
              this: v4,
              id: v65,
              amount: (float)(v162 - (float)((float)v97 / this->maxHealth)));
          }
          ++v65;
          ++v66;
        }
        while ( v65 < v7 );
        v53 = v156;
        v48 = v162;
      }
      if ( idRenderModelChain::GetNumLinks(this: v4) > 0 )
      {
        v98 = this->spawnPosition.x;
        v156 = v53;
        v99 = this->brokenLink;
        v100 = this->spawnPosition.z;
        v164 = this->spawnPosition.y;
        v163 = v98;
        v165 = v100;
        v169 = v98;
        v170 = v164;
        v171 = v100;
        if ( v99 >= 0 )
        {
          maxHealth = v53;
          v106 = v99 / 2;
          v107 = -1 - (idRenderModelChain::GetNumLinks(this: v4) - this->brokenLink) / 2;
          v108 = idRenderModelChain::GetNumLinks(this: v4) + v107;
          idVerletChain::GetMovement(
            this: &this->verlet,
            start: 0,
            end: this->brokenLink,
            maxMovement: &v156,
            avgMovement: &maxHealth);
          if ( maxHealth > (double)needAvgMovement )
          {
            if ( this->emitter1 == nullptr )
              this->emitter1 = clientGame->soundWorld->AllocSoundEmitter(this: clientGame->soundWorld);
            if ( this->soundRattle != nullptr
              && !this->emitter1->IsCurrentlyPlaying(this: this->emitter1, a2: SND_CHANNEL_FX) )
            {
              soundShaderParms_t::Clear(this: &v198);
              v198.soundShaderFlags = 0;
              this->emitter1->StartSound(this: this->emitter1, a2: SND_CHANNEL_FX, a3: this->soundRattle, a4: &v198);
            }
          }
          v109 = idRenderModelChain::GetNumLinks(this: v4);
          idVerletChain::GetMovement(
            this: &this->verlet,
            start: this->brokenLink,
            end: v109,
            maxMovement: &v156,
            avgMovement: &maxHealth);
          if ( maxHealth > (double)needAvgMovement )
          {
            if ( this->emitter2 == nullptr )
              this->emitter2 = clientGame->soundWorld->AllocSoundEmitter(this: clientGame->soundWorld);
            if ( this->soundRattle != nullptr
              && !this->emitter2->IsCurrentlyPlaying(this: this->emitter2, a2: SND_CHANNEL_FX) )
            {
              soundShaderParms_t::Clear(this: v199);
              v199[0].soundShaderFlags = 0;
              this->emitter2->StartSound(this: this->emitter2, a2: SND_CHANNEL_FX, a3: this->soundRattle, a4: v199);
            }
          }
          LinkPosition = idRenderModelChain::GetLinkPosition(this: v4, id: v106);
          v111 = LinkPosition->mat[7];
          v112 = LinkPosition->mat[11];
          v163 = LinkPosition->mat[3];
          v164 = v111;
          v165 = v112;
          v113 = idRenderModelChain::GetLinkPosition(this: v4, id: v108);
          v114 = v113->mat[7];
          v115 = v113->mat[11];
          v169 = v113->mat[3];
          v170 = v114;
          v171 = v115;
        }
        else
        {
          v158[0].value = v53;
          v101 = idRenderModelChain::GetNumLinks(this: v4) / 2;
          v102 = idRenderModelChain::GetNumLinks(this: v4);
          idVerletChain::GetMovement(
            this: &this->verlet,
            start: 0,
            end: v102,
            maxMovement: &v158[0].value,
            avgMovement: &v156);
          if ( v156 > (double)needAvgMovement )
          {
            if ( this->emitter1 == nullptr )
              this->emitter1 = clientGame->soundWorld->AllocSoundEmitter(this: clientGame->soundWorld);
            if ( this->soundRattle != nullptr
              && !this->emitter1->IsCurrentlyPlaying(this: this->emitter1, a2: SND_CHANNEL_FX) )
            {
              soundShaderParms_t::Clear(this: &v197);
              v197.soundShaderFlags = 0;
              this->emitter1->StartSound(this: this->emitter1, a2: SND_CHANNEL_FX, a3: this->soundRattle, a4: &v197);
            }
          }
          v103 = idRenderModelChain::GetLinkPosition(this: v4, id: v101);
          v104 = v103->mat[7];
          v105 = v103->mat[11];
          v163 = v103->mat[3];
          v164 = v104;
          v165 = v105;
        }
        emitter1 = this->emitter1;
        if ( emitter1 != nullptr && emitter1->IsCurrentlyPlaying(this: emitter1, a2: SND_CHANNEL_FX) )
          this->emitter1->UpdateEmitter(
            this: this->emitter1,
            a2: (const idVec3 *)&v163,
            a3: &mat3_identity,
            a4: &vec3_origin,
            a5: this->entityNumber + 1);
        emitter2 = this->emitter2;
        if ( emitter2 != nullptr && emitter2->IsCurrentlyPlaying(this: emitter2, a2: SND_CHANNEL_FX) )
          this->emitter2->UpdateEmitter(
            this: this->emitter2,
            a2: (const idVec3 *)&v169,
            a3: &mat3_identity,
            a4: &vec3_origin,
            a5: this->entityNumber + 1);
      }
      if ( g_chainVerletDebug.valueInteger != 0 )
      {
        v118 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v119 = 0;
        if ( this->verlet.points.num - 1 > 0 )
        {
          v120 = 0;
          do
          {
            v121 = &this->verlet.points.list[v120];
            v122 = v121->currentPos.x;
            v123 = v121->currentPos.z;
            v124 = v121->currentPos.y;
            x = v122;
            v161 = v123;
            v160 = v124;
            v125 = (float)((float)((float)((float)v35 * v122)
                                 + (float)((float)(v124 * (float)v32) + (float)(v123 * (float)v29)))
                         + (float)v15);
            v189 = (float)((float)((float)v35 * v122) + (float)((float)(v124 * (float)v32) + (float)(v123 * (float)v29)))
                 + (float)v15;
            v183[1] = v189;
            v126 = (float)((float)((float)((float)v34 * v122)
                                 + (float)((float)(v124 * (float)v31) + (float)(v123 * (float)v28)))
                         + (float)v12);
            v190 = (float)((float)((float)v34 * v122) + (float)((float)(v124 * (float)v31) + (float)(v123 * (float)v28)))
                 + (float)v12;
            v127 = (float)((float)((float)(v123 * (float)v30)
                                 + (float)((float)(v122 * (float)v36) + (float)(v124 * (float)v33)))
                         + (float)v14);
            v183[2] = v190;
            v183[0] = (float)((float)((float)(v123 * (float)v30)
                                    + (float)((float)(v122 * (float)v36) + (float)(v124 * (float)v33)))
                            + (float)v14)
                    + (float)2.0;
            v188 = (float)((float)((float)(v123 * (float)v30)
                                 + (float)((float)(v122 * (float)v36) + (float)(v124 * (float)v33)))
                         + (float)v14)
                 - (float)2.0;
            clientGame->renderWorld->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorWhite,
              a3: (const idVec3 *)&v188,
              a4: (const idVec3 *)v183,
              a5: v118,
              a6: false);
            v181[0] = v127;
            v181[1] = (float)v125 + (float)2.0;
            v181[2] = v126;
            v186[0] = v127;
            v186[1] = (float)v125 - (float)2.0;
            v186[2] = v126;
            clientGame->renderWorld->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorWhite,
              a3: (const idVec3 *)v186,
              a4: (const idVec3 *)v181,
              a5: v118,
              a6: false);
            v184[0] = v127;
            v184[1] = v125;
            v184[2] = (float)v126 + (float)2.0;
            v185[0] = v127;
            v185[1] = v125;
            v185[2] = (float)v126 - (float)2.0;
            clientGame->renderWorld->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorWhite,
              a3: (const idVec3 *)v185,
              a4: (const idVec3 *)v184,
              a5: v118,
              a6: false);
            ++v119;
            ++v120;
          }
          while ( v119 < this->verlet.points.num - 1 );
        }
        v128 = 0;
        _FP12 = (float)((float)0.0000099999997 - g_chainVerletError.valueFloat);
        __asm { fsel      f11, f12, f0, f13 }
        v131 = (float)((float)v48 / (float)_FP11);
        if ( this->verlet.constraints.num > 0 )
        {
          do
          {
            idVerletChain::GetConstraint(
              this: &this->verlet,
              id: v128,
              pos1: &v168,
              pos2: &v166,
              restLengthDiff: &v158[0].value);
            v132 = (float)(v158[0].value * (float)v131);
            if ( v132 >= v53 )
            {
              if ( v132 > v162 )
                v132 = v162;
            }
            else
            {
              v132 = v53;
            }
            v180.a = -1.0;
            v180.b = -1.0;
            v180.g = -1.0;
            v180.r = -1.0;
            v133 = (float)((float)((float)v34 * v168.x)
                         + (float)((float)(v168.y * (float)v31) + (float)(v168.z * (float)v28)));
            v134 = (float)((float)((float)v34 * v166.x)
                         + (float)((float)(v166.y * (float)v31) + (float)(v166.z * (float)v28)));
            v135 = (float)((float)((float)((float)v35 * v168.x)
                                 + (float)((float)(v168.y * (float)v32) + (float)(v168.z * (float)v29)))
                         + (float)v15);
            v168.x = (float)((float)(v168.z * (float)v30)
                           + (float)((float)(v168.x * (float)v36) + (float)(v168.y * (float)v33)))
                   + (float)v14;
            v168.y = v135;
            v168.z = (float)v133 + (float)v12;
            v136 = (float)((float)((float)((float)v35 * v166.x)
                                 + (float)((float)(v166.y * (float)v32) + (float)(v166.z * (float)v29)))
                         + (float)v15);
            v166.x = (float)((float)(v166.z * (float)v30)
                           + (float)((float)(v166.x * (float)v36) + (float)(v166.y * (float)v33)))
                   + (float)v14;
            v166.y = v136;
            v166.z = (float)v134 + (float)v12;
            idColor::Lerp(this: &v180, from: &idColor::colorWhite, to: &idColor::colorRed, lerp: v132);
            clientGame->renderWorld->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&v180,
              a3: &v168,
              a4: &v166,
              a5: v118,
              a6: false);
            ++v128;
          }
          while ( v128 < this->verlet.constraints.num );
        }
      }
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->Present(this: presentable);
    idEntity::UpdatePVSAreas(this);
  }
}


// ========================================================================
// ?ForceUpdate@idVerletChain@@QAAXHM@Z
// EA  : 0x82C15F08
// RVA : 0x00C15F08
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idVerletChain::ForceUpdate(idVerletChain *this, int numSimulations, double gravityScale)
{
  int i; // r29
  bool v7; // r31
  double v8; // fp1
  idVerletChain *v9; // r3

  for ( i = 1; i <= numSimulations; ++i )
  {
    v7 = (_cntlzw(numSimulations - i) & 0x20) != 0;
    gameLocal->GetGameSecPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    if ( g_chainVerlet.valueInteger != 0 )
    {
      idVerletChain::Integrate(this, deltaTime: v8, gravityScale);
      idVerletChain::Constrain(this: v9);
    }
    if ( v7 )
    {
      if ( this->sphereCollisions.size < 0 )
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollisions);
      this->sphereCollisions.num = __CFADD__(-this->sphereCollisions.size, this->sphereCollisions.size ^ 0x80000000)
                                 ? 0
                                 : this->sphereCollisions.size;
      if ( v7 )
      {
        if ( this->planeCollisions.size < 0 )
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->planeCollisions);
        this->planeCollisions.num = __CFADD__(-this->planeCollisions.size, this->planeCollisions.size ^ 0x80000000)
                                  ? 0
                                  : this->planeCollisions.size;
      }
    }
  }
}


// ========================================================================
// ??0idFuncChain@@QAA@XZ
// EA  : 0x82C16020
// RVA : 0x00C16020
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idFuncChain *__fastcall idFuncChain::idFuncChain(idFuncChain *this)
{
  idEntity::idEntity(this);
  this->physicsObject = nullptr;
  this->__vftable = (idFuncChain_vtbl *)&idFuncChain::`vftable';
  this->chainLinkModel = nullptr;
  idFuncChain::chaindef_t::chaindef_t(this: &this->chainDef);
  this->chainGroup.spawnId.value = 0x1FFF;
  this->morphMaterial = nullptr;
  this->collisions.granularity = 0;
  this->collisions.memTag = 5;
  this->collisions.listStatic = 0;
  this->collisions.list = nullptr;
  this->collisions.size = 0;
  this->collisions.num = 0;
  this->collisionPlanes.list = nullptr;
  this->collisionPlanes.granularity = 0;
  this->collisionPlanes.memTag = 5;
  this->collisionPlanes.listStatic = 0;
  this->collisionPlanes.size = 0;
  this->collisionPlanes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collisionPlanes);
  this->animCollisions.list = nullptr;
  this->animCollisions.granularity = 0;
  this->animCollisions.memTag = 5;
  this->animCollisions.listStatic = 0;
  this->animCollisions.size = 0;
  this->animCollisions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animCollisions);
  this->soundBreak = nullptr;
  this->soundRattle = nullptr;
  this->highlight = false;
  this->damageTypes = DAMAGETYPE_LASER_CUTTING;
  this->maxHealth = 45.0;
  this->breakPosition.x = 0.0;
  this->breakPosition.y = 0.0;
  this->breakPosition.z = 0.0;
  this->generatedPhysics = false;
  idFuncChain::chain_t::chain_t(this: &this->state);
  this->emitter1 = nullptr;
  this->brokenLink = -1;
  this->emitter2 = nullptr;
  idVerletChain::idVerletChain(this: &this->verlet);
  *(_BYTE *)&this->flags |= 0x40u;
  return this;
}


// ========================================================================
// __unwind$504357
// EA  : 0x82C1614C
// RVA : 0x00C1614C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504357()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$504358_0
// EA  : 0x82C16174
// RVA : 0x00C16174
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504358_0()
{
  int v0; // r12

  idFuncChain::chaindef_t::~chaindef_t(this: (idFuncChain::chaindef_t *)(*(_DWORD *)(v0 - 128 + 148) + 808));
}


// ========================================================================
// __unwind$504359_0
// EA  : 0x82C161A0
// RVA : 0x00C161A0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504359_0()
{
  int v0; // r12

  idList<idFuncChain::sphere_t,5>::~idList<idFuncChain::sphere_t,5>(this: (idList<idFuncChain::sphere_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 988));
}


// ========================================================================
// __unwind$504360_0
// EA  : 0x82C161CC
// RVA : 0x00C161CC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504360_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1004));
}


// ========================================================================
// __unwind$504361_0
// EA  : 0x82C161F8
// RVA : 0x00C161F8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504361_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1020));
}


// ========================================================================
// ??1idFuncChain@@UAA@XZ
// EA  : 0x82C16230
// RVA : 0x00C16230
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::~idFuncChain(idFuncChain *this)
{
  idPhysics *physicsObject; // r3
  char *list; // r3

  this->__vftable = (idFuncChain_vtbl *)&idFuncChain::`vftable';
  if ( this->physicsObject != nullptr )
  {
    idEntity::SetPhysics(this, phys: nullptr);
    physicsObject = this->physicsObject;
    if ( physicsObject != nullptr )
      ((void (__fastcall *)(idPhysics *, int))physicsObject->dtr_idPhysics)(a1: physicsObject, a2: 1);
    this->physicsObject = nullptr;
  }
  idVerletChain::~idVerletChain(this: &this->verlet);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animCollisions);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collisionPlanes);
  if ( this->collisions.listStatic == 0 || this->collisions.listStatic == 2 )
  {
    list = (char *)this->collisions.list;
    if ( list != nullptr )
      idListArrayDelete<idFuncChain::sphere_t>(ptr: list, num: this->collisions.size);
    this->collisions.list = nullptr;
    this->collisions.size = 0;
  }
  this->collisions.num = 0;
  idFuncChain::chaindef_t::~chaindef_t(this: &this->chainDef);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$504455
// EA  : 0x82C162F4
// RVA : 0x00C162F4
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504455()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$504456
// EA  : 0x82C1631C
// RVA : 0x00C1631C
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504456()
{
  int v0; // r12

  idFuncChain::chaindef_t::~chaindef_t(this: (idFuncChain::chaindef_t *)(*(_DWORD *)(v0 - 112 + 132) + 808));
}


// ========================================================================
// __unwind$504457
// EA  : 0x82C16348
// RVA : 0x00C16348
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504457()
{
  int v0; // r12

  idList<idFuncChain::sphere_t,5>::~idList<idFuncChain::sphere_t,5>(this: (idList<idFuncChain::sphere_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 988));
}


// ========================================================================
// __unwind$504458
// EA  : 0x82C16374
// RVA : 0x00C16374
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1004));
}


// ========================================================================
// __unwind$504459
// EA  : 0x82C163A0
// RVA : 0x00C163A0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504459()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1020));
}


// ========================================================================
// __unwind$504460
// EA  : 0x82C163CC
// RVA : 0x00C163CC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504460()
{
  int v0; // r12

  idVerletChain::~idVerletChain(this: (idVerletChain *)(*(_DWORD *)(v0 - 112 + 132) + 1188));
}


// ========================================================================
// ?Spawn@idFuncChain@@QAAXXZ
// EA  : 0x82C16400
// RVA : 0x00C16400
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::Spawn(idFuncChain *this)
{
  idRenderModel *v2; // r25
  idRenderModelChain *v3; // r28
  float z; // r6
  double extraLength; // fp10
  float y; // r5
  float v7; // r4
  float x; // r9
  double v9; // fp12
  double v10; // fp11
  float v11; // r11
  float v12; // r10
  float v13; // r5
  float v14; // r8
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  const idVec3 *v22; // r4
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  const idVec3 *v30; // r4
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  double v34; // fp5
  double v35; // fp4
  double v36; // fp3
  double v37; // fp2
  double v38; // fp1
  bool randomRotate; // r11
  bool smoothSkinning; // r10
  double startRotation; // fp13
  long double v42; // fp2
  long double v43; // fp2
  idRenderModel *chainLinkModel; // r7
  int i; // r29
  const idJointMat *LinkPosition; // r3
  double v47; // fp0
  double v48; // fp13
  double v49; // fp12
  idPresentable *presentable; // r11
  idRenderModel *model; // r9
  idPresentable *v52; // r11
  float *v53; // r11
  idPresentable *v54; // r11
  float v55; // [sp+8h] [-188h]
  float v56; // [sp+8h] [-188h]
  float v57; // [sp+8h] [-188h]
  float v58; // [sp+Ch] [-184h]
  float v59; // [sp+Ch] [-184h]
  float v60; // [sp+Ch] [-184h]
  float v61; // [sp+10h] [-180h]
  float v62; // [sp+10h] [-180h]
  float v63; // [sp+10h] [-180h]
  float v64; // [sp+14h] [-17Ch]
  float v65; // [sp+14h] [-17Ch]
  float v66; // [sp+14h] [-17Ch]
  float v67; // [sp+18h] [-178h]
  float v68; // [sp+18h] [-178h]
  float v69; // [sp+18h] [-178h]
  float v70; // [sp+1Ch] [-174h]
  float v71; // [sp+1Ch] [-174h]
  float v72; // [sp+1Ch] [-174h]
  idVec3 v73; // [sp+58h] [-138h] BYREF
  chainGenerateInfo_t v74; // [sp+68h] [-128h] BYREF
  float v75; // [sp+70h] [-120h]
  float v76; // [sp+74h] [-11Ch]
  float v77; // [sp+78h] [-118h]
  idVec3 v78; // [sp+80h] [-110h] BYREF
  idVec3 v79; // [sp+90h] [-100h] BYREF
  idVerletChain::particle_t v80; // [sp+A0h] [-F0h] BYREF
  idCurve_NURBS<idVec3> v81; // [sp+D0h] [-C0h] BYREF
  idStr v82; // [sp+120h] [-70h] BYREF

  if ( this->chainLinkModel != nullptr )
  {
    v2 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_chain", a3: 1, a4: -1);
    v3 = (idRenderModelChain *)_RTDynamicCast(
                                 inptr: v2,
                                 VfDelta: 0,
                                 SrcType: &idRenderModel `RTTI Type Descriptor',
                                 TargetType: &idRenderModelChain `RTTI Type Descriptor',
                                 isReference: 0);
    if ( v3 != nullptr )
    {
      z = this->chainDef.endPosition.z;
      extraLength = this->chainDef.extraLength;
      y = this->chainDef.startPosition.y;
      v7 = this->chainDef.endPosition.y;
      x = this->chainDef.startPosition.x;
      v77 = this->chainDef.startPosition.z;
      v9 = v77;
      v73.z = z;
      v76 = y;
      v10 = y;
      v73.y = v7;
      v11 = this->chainDef.endPosition.x;
      v75 = x;
      v12 = y;
      v13 = this->chainDef.endPosition.z;
      v78.y = v12;
      v73.x = v11;
      v14 = this->chainDef.endPosition.x;
      v78.x = x;
      v78.z = v77;
      v79.y = v7;
      v79.z = v13;
      v79.x = v14;
      this->breakPosition.x = (float)((float)(v11 - x) * (float)0.5) + x;
      v73.x = (float)((float)(v11 - x) * (float)0.5) + x;
      this->breakPosition.y = (float)v10 + (float)((float)(v7 - (float)v10) * (float)0.5);
      v73.y = (float)v10 + (float)((float)(v7 - (float)v10) * (float)0.5);
      this->breakPosition.z = (float)((float)v9 + (float)((float)(z - (float)v9) * (float)0.5)) - (float)extraLength;
      v73.z = (float)((float)v9 + (float)((float)(z - (float)v9) * (float)0.5)) - (float)extraLength;
      idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: &v81);
      idCurve_NURBS<idAngles>::Clear(this: &v81);
      if ( this->chainDef.extraLength <= 0.00000011920929 )
      {
        idCurve_NURBS<idVec3>::AddValue(
          this: &v81,
          time: 0.0,
          value: (const idVec3 *)&unk_82390000,
          a4: &v78,
          a5: v21,
          a6: v20,
          a7: v19,
          a8: v18,
          a9: v17,
          a10: v16,
          a11: v15,
          a12: v55,
          a13: v58,
          a14: v61,
          a15: v64,
          a16: v67,
          a17: v70);
        v38 = 1.0;
      }
      else
      {
        idCurve_NURBS<idVec3>::AddValue(
          this: &v81,
          time: 0.0,
          value: (const idVec3 *)&unk_82390000,
          a4: &v78,
          a5: v21,
          a6: v20,
          a7: v19,
          a8: v18,
          a9: v17,
          a10: v16,
          a11: v15,
          a12: v55,
          a13: v58,
          a14: v61,
          a15: v64,
          a16: v67,
          a17: v70);
        idCurve_NURBS<idVec3>::AddValue(
          this: &v81,
          time: 1.0,
          value: v22,
          a4: &v73,
          a5: v29,
          a6: v28,
          a7: v27,
          a8: v26,
          a9: v25,
          a10: v24,
          a11: v23,
          a12: v56,
          a13: v59,
          a14: v62,
          a15: v65,
          a16: v68,
          a17: v71);
        v38 = 2.0;
      }
      idCurve_NURBS<idVec3>::AddValue(
        this: &v81,
        time: v38,
        value: v30,
        a4: &v79,
        a5: v37,
        a6: v36,
        a7: v35,
        a8: v34,
        a9: v33,
        a10: v32,
        a11: v31,
        a12: v57,
        a13: v60,
        a14: v63,
        a15: v66,
        a16: v69,
        a17: v72);
      randomRotate = this->chainDef.randomRotate;
      smoothSkinning = this->chainDef.smoothSkinning;
      v74.startRotation = 0.0;
      startRotation = this->chainDef.startRotation;
      v74.rotateRandom = randomRotate;
      v74.smoothSkinning = smoothSkinning;
      *(double *)&v42 = (float)((float)startRotation * (float)0.0027777778);
      v43 = floor(x: v42);
      chainLinkModel = this->chainLinkModel;
      v74.startRotation = -(float)((float)((float)*(double *)&v43 * (float)360.0) - this->chainDef.startRotation);
      idStr::idStr(this: &v82, text: chainLinkModel->name.str);
      idRenderModelChain::Build(
        this: v3,
        genInfo_: &v74,
        modelName: &v82,
        morphMaterial_: this->morphMaterial,
        spline: (idVec3 *)&v81);
      idStr::FreeData(this: &v82);
      for ( i = 0; i < idRenderModelChain::GetNumLinks(this: v3); ++i )
      {
        LinkPosition = idRenderModelChain::GetLinkPosition(this: v3, id: i);
        v80.healthStamp = 0.0;
        v80.anchor = false;
        v80.timeStamp = 0;
        v47 = LinkPosition->mat[3];
        v48 = LinkPosition->mat[7];
        v49 = LinkPosition->mat[11];
        v80.oldPos.x = LinkPosition->mat[3];
        v80.oldPos.y = v48;
        v80.oldPos.z = v49;
        v80.currentPos.x = v47;
        v80.currentPos.y = v48;
        v80.currentPos.z = v49;
        idList<idVerletChain::particle_t,5>::Append(this: &this->verlet.points, obj: &v80);
      }
      idVerletChain::BuildConstraints(this: &this->verlet, health: this->maxHealth);
      if ( v81.weights.listStatic == 0 || v81.weights.listStatic == 2 )
      {
        if ( v81.weights.list != nullptr )
          idMem::Free(this: &mem, ptr: v81.weights.list, align: ALIGN_16);
        v81.weights.list = nullptr;
        v81.weights.size = 0;
      }
      v81.weights.num = 0;
      idCurve<idVec3>::~idCurve<idVec3>(this: &v81);
    }
    this->SetModel(this, a2: v2);
    this->state.start.position.x = this->chainDef.startPosition.x;
    this->state.start.position.y = this->chainDef.startPosition.y;
    this->state.start.position.z = this->chainDef.startPosition.z;
    this->state.end.position.x = this->chainDef.endPosition.x;
    this->state.end.position.y = this->chainDef.endPosition.y;
    this->state.end.position.z = this->chainDef.endPosition.z;
    if ( this->highlight )
    {
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      model = presentable->model;
      presentable->highlightColor = HIGHLIGHT_COLOR_USE;
      model->g.highlightColor = HIGHLIGHT_COLOR_USE;
    }
    v52 = this->presentable;
    if ( v52 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v52 = this->presentable;
    }
    v52->origin.x = this->spawnPosition.x;
    v52->origin.y = this->spawnPosition.y;
    v52->origin.z = this->spawnPosition.z;
    v53 = (float *)this->presentable;
    if ( v53 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v53 = (float *)this->presentable;
    }
    v53[33] = this->spawnOrientation.mat[0].x;
    v53[34] = this->spawnOrientation.mat[0].y;
    v53[35] = this->spawnOrientation.mat[0].z;
    v53[36] = this->spawnOrientation.mat[1].x;
    v53[37] = this->spawnOrientation.mat[1].y;
    v53[38] = this->spawnOrientation.mat[1].z;
    v53[39] = this->spawnOrientation.mat[2].x;
    v53[40] = this->spawnOrientation.mat[2].y;
    v53[41] = this->spawnOrientation.mat[2].z;
    v54 = this->presentable;
    if ( v54 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v54 = this->presentable;
    }
    v54->Present(this: v54);
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    idLib::Warning(fmt: "idFuncChain '%s' has NULL chainLinkModel", this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
}


// ========================================================================
// __unwind$504527
// EA  : 0x82C168C4
// RVA : 0x00C168C4
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504527()
{
  int v0; // r12

  idCurve_NURBS<idVec3>::~idCurve_NURBS<idVec3>(this: (idCurve_NURBS<idVec3> *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$504528
// EA  : 0x82C168EC
// RVA : 0x00C168EC
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 288));
}


// ========================================================================
// __unwind$504694
// EA  : 0x82C16914
// RVA : 0x00C16914
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void _unwind_504694()
{
  int v0; // r12

  idCurve_NonUniformBSpline<idVec3>::~idCurve_NonUniformBSpline<idVec3>(this: (idCurve_NonUniformBSpline<idVec3> *)(v0 - 400 + 208));
}


// ========================================================================
// ?InitialSetup@idFuncChain@@QAAXXZ
// EA  : 0x82C16940
// RVA : 0x00C16940
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __fastcall idFuncChain::InitialSetup(idFuncChain *this)
{
  int v2; // r30
  double valueFloat; // fp1
  idPresentable *presentable; // r3
  idPresentable_vtbl *v5; // r10
  void (*Present)(void); // r9
  char v7; // [sp+50h] [-20h] BYREF

  if ( !this->generatedPhysics )
    idFuncChain::Event_SpawnBindEndPoints(this: (idFuncChain *)&v7, result: this);
  v2 = s_numSimulations;
  if ( this->chainDef.extraLength > 0.00000011920929 )
  {
    idFuncChain::AddCollisionInfo(this);
    if ( this->brokenLink == -1 )
      valueFloat = g_chainVerletGravityScale.valueFloat;
    else
      valueFloat = 1.0;
    idVerletChain::ForceUpdate(this: &this->verlet, numSimulations: v2, gravityScale: valueFloat);
  }
  idFuncChain::BuildPhysics(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = presentable->__vftable;
  presentable->origin.x = this->spawnPosition.x;
  presentable->origin.y = this->spawnPosition.y;
  Present = (void (*)(void))v5->Present;
  presentable->origin.z = this->spawnPosition.z;
  presentable->axis.mat[0].x = this->spawnOrientation.mat[0].x;
  presentable->axis.mat[0].y = this->spawnOrientation.mat[0].y;
  presentable->axis.mat[0].z = this->spawnOrientation.mat[0].z;
  presentable->axis.mat[1].x = this->spawnOrientation.mat[1].x;
  presentable->axis.mat[1].y = this->spawnOrientation.mat[1].y;
  presentable->axis.mat[1].z = this->spawnOrientation.mat[1].z;
  presentable->axis.mat[2].x = this->spawnOrientation.mat[2].x;
  presentable->axis.mat[2].y = this->spawnOrientation.mat[2].y;
  presentable->axis.mat[2].z = this->spawnOrientation.mat[2].z;
  Present();
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletDebug''
// EA  : 0x83375658
// RVA : 0x01375658
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletDebug__()
{
  idCVar::idCVar(
    this: &g_chainVerletDebug,
    name: "g_chainVerletDebug",
    value: "0",
    flags: 1,
    description: "Enables / Disables debug display of chains verlet integration system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletError''
// EA  : 0x833756B0
// RVA : 0x013756B0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletError__()
{
  idCVar::idCVar(
    this: &g_chainVerletError,
    name: "g_chainVerletError",
    value: "2.0",
    flags: 4,
    description: "Error threshold before constraint is fully red in g_chainVerletDebug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletError__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletCollision''
// EA  : 0x83375708
// RVA : 0x01375708
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletCollision__()
{
  idCVar::idCVar(
    this: &g_chainVerletCollision,
    name: "g_chainVerletCollision",
    value: "0",
    flags: 1,
    description: "Enables / Disables debug display of chains verlet collision primitives",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletCollision__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerlet''
// EA  : 0x83375760
// RVA : 0x01375760
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerlet__()
{
  idCVar::idCVar(
    this: &g_chainVerlet,
    name: "g_chainVerlet",
    value: "1",
    flags: 1,
    description: "If true, chains will be verlet simulated",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerlet__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletIterations''
// EA  : 0x833757B8
// RVA : 0x013757B8
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletIterations__()
{
  idCVar::idCVar(
    this: &g_chainVerletIterations,
    name: "g_chainVerletIterations",
    value: "4",
    flags: 2,
    description: "Number of iterations constrain will run after integration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletIterations__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletGravityScale''
// EA  : 0x83375810
// RVA : 0x01375810
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletGravityScale__()
{
  idCVar::idCVar(
    this: &g_chainVerletGravityScale,
    name: "g_chainVerletGravityScale",
    value: "0.25",
    flags: 4,
    description: "Gravity scale on chain when not split in half",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletGravityScale__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletIterationDynamic''
// EA  : 0x83375868
// RVA : 0x01375868
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletIterationDynamic__()
{
  idCVar::idCVar(
    this: &g_chainVerletIterationDynamic,
    name: "g_chainVerletIterationDynamic",
    value: "0",
    flags: 1,
    description: "Enable / Disables dynamic iteration integration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletIterationDynamic__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletIterationDynamicError''
// EA  : 0x833758C0
// RVA : 0x013758C0
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletIterationDynamicError__()
{
  idCVar::idCVar(
    this: &g_chainVerletIterationDynamicError,
    name: "g_chainVerletIterationDynamicError",
    value: "2.0",
    flags: 4,
    description: "Minimum error length allowed in order to stop integrate",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletIterationDynamicError__);
}


// ========================================================================
// `dynamic initializer for 'g_chainVerletIterationsMaxDynamic''
// EA  : 0x83375918
// RVA : 0x01375918
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_chainVerletIterationsMaxDynamic__()
{
  idCVar::idCVar(
    this: &g_chainVerletIterationsMaxDynamic,
    name: "g_chainVerletIterationsMaxDynamic",
    value: "4",
    flags: 2,
    description: "Maximum number of iterations dynamic integration is allowed to run.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_chainVerletIterationsMaxDynamic__);
}


// ========================================================================
// `dynamic initializer for 'buildChainClipModel_v''
// EA  : 0x83375970
// RVA : 0x01375970
// PDB : w:\tech5\tungsten\game\entities\chainentity.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__buildChainClipModel_v__()
{
  return idCommandLink::idCommandLink(
           this: &buildChainClipModel_v,
           cmdName: "buildChainClipModel",
           function: buildChainClipModel_f,
           description: "Export bounding boxes to be used as clip for chain links in their current state",
           argCompletion: idGameLocal::ArgCompletion_EntityName);
}

