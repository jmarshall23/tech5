
// ========================================================================
// ?RemoveOldNodes@idRibbon@@QAAXH@Z
// EA  : 0x82715B60
// RVA : 0x00715B60
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::RemoveOldNodes(idRibbon *this, int currentTime)
{
  int numActiveNodes; // r11
  const idDeclRibbon *ribbonDecl; // r7
  double v4; // fp0
  int currHeadIdx; // r10
  int v6; // r11
  int v7; // r8
  int v8; // r10
  int duration; // r7
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r10

  numActiveNodes = this->numActiveNodes;
  if ( numActiveNodes != 0 )
  {
    ribbonDecl = this->ribbonDecl;
    if ( ribbonDecl != nullptr )
    {
      v4 = 0.0;
      if ( ribbonDecl->maxLength != 0.0 )
      {
        currHeadIdx = this->currHeadIdx;
        v6 = currHeadIdx - numActiveNodes;
        v7 = v6 + 1;
        if ( v6 + 1 <= currHeadIdx )
        {
          v8 = v6 + 129;
          do
          {
            v4 = (float)(this->ribbonNodes[v8 % 128].nodeLength + (float)v4);
            if ( v4 > ribbonDecl->maxLength )
              --this->numActiveNodes;
            ++v7;
            ++v8;
          }
          while ( v7 <= this->currHeadIdx );
        }
      }
      duration = ribbonDecl->duration;
      if ( duration <= 0 )
      {
        if ( this->ribbonState == RIBBON_DEACTIVATING )
          --this->numActiveNodes;
      }
      else
      {
        v10 = this->currHeadIdx;
        v11 = this->numActiveNodes;
        v12 = v10 - v11 + 1;
        if ( v12 <= v10 )
        {
          v13 = v10 - v11 + 129;
          do
          {
            if ( this->ribbonNodes[v13 % 128].spawnTime + duration < currentTime )
              --this->numActiveNodes;
            ++v12;
            ++v13;
          }
          while ( v12 <= this->currHeadIdx );
        }
      }
      if ( this->numActiveNodes <= 0 )
      {
        this->numActiveNodes = 0;
        this->explicitDefineBothEdges = false;
        this->ribbonState = RIBBON_INACTIVE;
      }
    }
  }
}


// ========================================================================
// ?GetRemainingTime@idRibbon@@QBAHH@Z
// EA  : 0x82715CB0
// RVA : 0x00715CB0
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

int __fastcall idRibbon::GetRemainingTime(idRibbon *this, const int currentTime)
{
  const idDeclRibbon *ribbonDecl; // r11
  int duration; // r7
  int currHeadIdx; // r11
  int v5; // r8
  int v6; // r10
  int numActiveNodes; // ctr
  int spawnTime; // r9

  ribbonDecl = this->ribbonDecl;
  if ( ribbonDecl == nullptr )
    return 0;
  duration = ribbonDecl->duration;
  if ( duration <= 0 )
    return 0;
  currHeadIdx = this->currHeadIdx;
  v5 = 0;
  if ( currHeadIdx - this->numActiveNodes + 1 <= currHeadIdx )
  {
    v6 = currHeadIdx - this->numActiveNodes + 129;
    numActiveNodes = this->numActiveNodes;
    do
    {
      spawnTime = this->ribbonNodes[v6 % 128].spawnTime;
      if ( spawnTime - currentTime + duration > v5 )
        v5 = spawnTime - currentTime + duration;
      ++v6;
      --numActiveNodes;
    }
    while ( numActiveNodes != 0 );
  }
  return v5;
}


// ========================================================================
// ?ResetNodes@idRibbon@@AAAXXZ
// EA  : 0x82715D48
// RVA : 0x00715D48
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::ResetNodes(idRibbon *this)
{
  float *p_w; // r11
  int v2; // ctr

  this->prevTime = -1;
  this->currHeadIdx = -1;
  p_w = &this->globalColor.w;
  v2 = 128;
  this->ribbonState = RIBBON_INACTIVE;
  this->spawnTime = 0;
  this->numActiveNodes = 0;
  this->explicitDefineBothEdges = false;
  do
  {
    p_w[3] = 0.0;
    p_w[2] = 0.0;
    p_w[1] = 0.0;
    p_w[6] = 0.0;
    p_w[5] = 0.0;
    p_w[4] = 0.0;
    p_w[9] = 0.0;
    p_w[8] = 0.0;
    p_w[7] = 0.0;
    p_w[12] = 0.0;
    p_w[11] = 0.0;
    p_w[10] = 0.0;
    p_w[16] = 0.0;
    p_w[15] = 0.0;
    p_w[14] = 0.0;
    p_w[13] = 0.0;
    p_w[17] = 0.0;
    p_w += 18;
    *p_w = 0.0;
    --v2;
  }
  while ( v2 != 0 );
}


// ========================================================================
// ?CalcTurbulence@idRibbon@@ABAXABVidVec3@@ABVidMat3@@AAV2@@Z
// EA  : 0x82715DD0
// RVA : 0x00715DD0
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::CalcTurbulence(
        idRibbon *this,
        const idVec3 *origin,
        const idMat3 *axis,
        idVec3 *turb,
        long double a5)
{
  const idDeclRibbon *ribbonDecl; // r10
  double magnitude; // fp30
  double frequency; // fp31
  double y; // fp28
  double z; // fp27
  double w; // fp29
  long double v14; // fp2
  double v15; // fp26
  long double v16; // fp2
  long double v17; // fp2
  double v18; // fp28
  long double v19; // fp2
  long double v20; // fp2
  double v21; // fp28
  long double v22; // fp2
  double v23; // fp8
  double v24; // fp7
  double x; // fp13
  double v26; // fp12
  double v27; // fp0
  double v28; // fp11

  turb->x = 0.0;
  turb->z = 0.0;
  turb->y = 0.0;
  ribbonDecl = this->ribbonDecl;
  if ( ribbonDecl != nullptr )
  {
    magnitude = ribbonDecl->turbulence.magnitude;
    frequency = ribbonDecl->turbulence.frequency;
    y = ribbonDecl->turbulence.magic.y;
    z = ribbonDecl->turbulence.magic.z;
    w = ribbonDecl->turbulence.magic.w;
    if ( magnitude > 0.00000011920929 )
    {
      *(double *)&a5 = (float)((float)(this->ribbonDecl->turbulence.magic.x * origin->x)
                             * ribbonDecl->turbulence.frequency);
      v14 = sin(x: a5);
      v15 = (float)*(double *)&v14;
      *(double *)&v14 = (float)((float)(origin->y * (float)w) * (float)frequency);
      v16 = cos(x: v14);
      turb->x = (float)v15 - (float)*(double *)&v16;
      *(double *)&v16 = (float)((float)(origin->y * (float)y) * (float)frequency);
      v17 = sin(x: v16);
      v18 = (float)*(double *)&v17;
      *(double *)&v17 = (float)((float)(origin->x * (float)w) * (float)frequency);
      v19 = cos(x: v17);
      *((double *)&v19 + 1) = (float)((float)v18 - (float)*(double *)&v19);
      turb->y = (float)v18 - (float)*(double *)&v19;
      *(double *)&v19 = (float)((float)(origin->z * (float)z) * (float)frequency);
      v20 = cos(x: v19);
      v21 = (float)*(double *)&v20;
      *(double *)&v20 = (float)((float)(origin->z * (float)w) * (float)frequency);
      v22 = sin(x: v20);
      v23 = (float)(turb->x * (float)magnitude);
      v24 = (float)(turb->y * (float)magnitude);
      turb->x = turb->x * (float)magnitude;
      turb->y = v24;
      turb->z = (float)((float)v21 - (float)*(double *)&v22) * (float)magnitude;
      x = axis->mat[0].x;
      v26 = axis->mat[0].y;
      v27 = (float)((float)(axis->mat[2].x * (float)((float)((float)v21 - (float)*(double *)&v22) * (float)magnitude))
                  + (float)(axis->mat[1].x * (float)v24));
      v28 = (float)((float)(axis->mat[0].z * (float)v23)
                  + (float)((float)(axis->mat[2].z
                                  * (float)((float)((float)v21 - (float)*(double *)&v22) * (float)magnitude))
                          + (float)(axis->mat[1].z * (float)v24)));
      *(double *)&v22 = (float)((float)(axis->mat[2].y
                                      * (float)((float)((float)v21 - (float)*(double *)&v22) * (float)magnitude))
                              + (float)(axis->mat[1].y * (float)v24));
      turb->z = v28;
      turb->y = (float)((float)v26 * (float)v23) + (float)*(double *)&v22;
      turb->x = (float)((float)x * (float)v23) + (float)v27;
    }
  }
}


// ========================================================================
// ?CalcHelix@idRibbon@@ABAXHABVidVec3@@ABVidMat3@@0AAV2@@Z
// EA  : 0x82715F50
// RVA : 0x00715F50
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::CalcHelix(
        idRibbon *this,
        int currentTime,
        const idVec3 *origin,
        const idMat3 *axis,
        __int64 helix,
        long double a6)
{
  float *v9; // r29
  const idDeclRibbon *ribbonDecl; // r11
  double radius; // fp30
  __int64 v12; // r10
  double rotationScale; // fp0
  double v14; // fp5
  double v15; // fp29
  long double v16; // fp2
  double v17; // fp11
  const idDeclRibbon *v18; // r27
  long double v21; // fp2
  double v22; // fp0
  double v23; // fp29
  long double v24; // fp2
  double y; // fp12
  double z; // fp11
  double v27; // fp3
  float v28[2]; // [sp+50h] [-70h] BYREF
  _QWORD v29[7]; // [sp+58h] [-68h] BYREF

  v9 = (float *)helix;
  *(float *)helix = 0.0;
  *(float *)(helix + 8) = 0.0;
  *(float *)(helix + 4) = 0.0;
  ribbonDecl = this->ribbonDecl;
  if ( ribbonDecl != nullptr )
  {
    radius = ribbonDecl->helix.radius;
    if ( radius > 0.00000011920929 )
    {
      HIDWORD(v12) = this->spawnTime;
      LODWORD(v12) = currentTime;
      rotationScale = ribbonDecl->helix.rotationScale;
      LODWORD(helix) = HIDWORD(v12);
      v29[1] = v12;
      v29[0] = helix;
      *(double *)&a6 = (float)((float)((float)rotationScale * (float)v12) + (float)helix);
      idMath::SinCos(a: a6, s: (float *)this, c: v28, a4: (float *)v29);
      v14 = (float)(origin->y - this->spawnOrg.y);
      v15 = (float)(this->spawnOrg.y + origin->y);
      *((double *)&v16 + 1) = (float)(origin->z - this->spawnOrg.z);
      v17 = (float)(origin->x - this->spawnOrg.x);
      v18 = this->ribbonDecl;
      *(double *)&v16 = (float)(v18->helix.distortion0.x * (float)(this->spawnOrg.x + origin->x));
      _FP3 = (float)((float)1.0
                   - (float)((float)__fsqrts((float)((float)((float)v17 * (float)v17)
                                                   + (float)((float)((float)*((double *)&v16 + 1)
                                                                   * (float)*((double *)&v16 + 1))
                                                           + (float)((float)v14 * (float)v14))))
                           * (float)0.0049999999));
      __asm { fsel      f28, f3, f4, f0 }
      v21 = cos(x: v16);
      *((double *)&v21 + 1) = v28[0];
      v22 = (float)*(double *)&v21;
      *(double *)&v21 = (float)(v18->helix.distortion0.y * (float)v15);
      v23 = (float)((float)(v18->helix.distortion1.x * (float)v22) + (float)(v28[0] * (float)radius));
      v24 = sin(x: v21);
      y = axis->mat[0].y;
      z = axis->mat[0].z;
      v27 = (float)((float)(axis->mat[1].y * (float)((float)v23 * (float)_FP28))
                  + (float)(axis->mat[2].y
                          * (float)((float)((float)(v18->helix.distortion1.y * (float)*(double *)&v24)
                                          + (float)(*(float *)v29 * (float)radius))
                                  * (float)_FP28)));
      *((double *)&v24 + 1) = (float)((float)(axis->mat[1].z * (float)((float)v23 * (float)_FP28))
                                    + (float)(axis->mat[2].z
                                            * (float)((float)((float)(v18->helix.distortion1.y * (float)*(double *)&v24)
                                                            + (float)(*(float *)v29 * (float)radius))
                                                    * (float)_FP28)));
      *v9 = (float)(axis->mat[0].x * (float)0.0)
          + (float)((float)(axis->mat[1].x * (float)((float)v23 * (float)_FP28))
                  + (float)(axis->mat[2].x
                          * (float)((float)((float)(v18->helix.distortion1.y * (float)*(double *)&v24)
                                          + (float)(*(float *)v29 * (float)radius))
                                  * (float)_FP28)));
      v9[1] = (float)((float)y * (float)0.0) + (float)v27;
      v9[2] = (float)((float)z * (float)0.0) + (float)*((double *)&v24 + 1);
    }
  }
}


// ========================================================================
// ??0idRibbon@@QAA@PBVidDeclRibbon@@@Z
// EA  : 0x827160F0
// RVA : 0x007160F0
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

idRibbon *__fastcall idRibbon::idRibbon(idRibbon *this, const idDeclRibbon *decl)
{
  float z; // r6
  int v3; // ctr
  float *p_w; // r11
  float *p_y; // r9
  float *v6; // r11
  int i; // ctr

  this->ribbonState = RIBBON_INACTIVE;
  this->spawnOrg.x = vec3_origin.x;
  this->spawnOrg.y = vec3_origin.y;
  z = vec3_origin.z;
  this->startVariance = 0.0;
  this->spawnOrg.z = z;
  this->spawnTime = 0;
  this->numActiveNodes = 0;
  v3 = 128;
  this->currHeadIdx = -1;
  p_w = &this->globalColor.w;
  this->prevTime = -1;
  p_y = &this->spawnOrg.y;
  this->prevOrigin = vec3_origin;
  this->prevOrigin2 = vec3_origin;
  this->ribbonDecl = decl;
  this->globalColor = (idVec4)idColor::colorWhite;
  do
  {
    p_w[3] = 0.0;
    p_w[2] = 0.0;
    p_y += 18;
    *p_y = 0.0;
    p_w[6] = 0.0;
    p_w[5] = 0.0;
    p_w[4] = 0.0;
    p_w[9] = 0.0;
    p_w[8] = 0.0;
    p_w[7] = 0.0;
    p_w[12] = 0.0;
    p_w[11] = 0.0;
    p_w[10] = 0.0;
    p_w[16] = 0.0;
    p_w[15] = 0.0;
    p_w[14] = 0.0;
    p_w[13] = 0.0;
    p_w[17] = 0.0;
    p_w += 18;
    *p_w = 0.0;
    --v3;
  }
  while ( v3 != 0 );
  this->explicitDefineBothEdges = false;
  v6 = &this->globalColor.w;
  for ( i = 128; i != 0; --i )
  {
    v6[3] = 0.0;
    v6[2] = 0.0;
    v6[1] = 0.0;
    v6[6] = 0.0;
    v6[5] = 0.0;
    v6[4] = 0.0;
    v6[9] = 0.0;
    v6[8] = 0.0;
    v6[7] = 0.0;
    v6[12] = 0.0;
    v6[11] = 0.0;
    v6[10] = 0.0;
    v6[16] = 0.0;
    v6[15] = 0.0;
    v6[14] = 0.0;
    v6[13] = 0.0;
    v6[17] = 0.0;
    v6 += 18;
    *v6 = 0.0;
  }
  return this;
}


// ========================================================================
// ?StartRibbon@idRibbon@@QAAXHABVidVec3@@@Z
// EA  : 0x82716278
// RVA : 0x00716278
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::StartRibbon(idRibbon *this, const int spawnTime_, const idVec3 *spawnOrg_)
{
  int v3; // r4
  int v4; // r3
  __int64 v5; // r6
  int v6; // r7

  idRibbon::ResetNodes(this);
  *(_DWORD *)(v4 + 16) = v3;
  *(float *)(v6 + 4) = *(float *)HIDWORD(v5);
  *(float *)(v6 + 8) = *(float *)(HIDWORD(v5) + 4);
  *(float *)(v6 + 12) = *(float *)(HIDWORD(v5) + 8);
  *(_DWORD *)v6 = 0;
  LODWORD(v5) = ((1664525 * idRibbon::random.seed + 1013904223) >> 10) & 0x7FFF;
  idRibbon::random.seed = 1664525 * idRibbon::random.seed + 1013904223;
  *(float *)(v6 + 28) = (float)v5 * (float)0.000030518509;
}


// ========================================================================
// ?AddNode@idRibbon@@AAAXHABVidVec3@@0ABVidMat3@@0ABVidVec4@@@Z
// EA  : 0x82716308
// RVA : 0x00716308
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::AddNode(
        idRibbon *this,
        int currentTime,
        const idVec3 *origin,
        const idVec3 *origin2,
        const idMat3 *axis,
        const idVec3 *velocity,
        const idVec4 *color,
        long double a8)
{
  double x; // fp28
  double y; // fp29
  double z; // fp30
  __int64 v18; // r8
  double v19; // fp25
  double v20; // fp26
  double v21; // fp27
  long double v22; // fp2
  long double v23; // fp2
  __int64 v24; // r8
  long double v25; // fp2
  double v26; // fp13
  double v27; // fp12
  double v28; // fp11
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  int v32; // r11
  idRibbon::ribbonNode_t *v33; // r11
  double v34; // fp3
  double v35; // fp4
  double v36; // fp6
  double v37; // fp2
  double v38; // fp1
  double v39; // fp13
  double v40; // fp12
  double v41; // fp11
  const idDeclRibbon *ribbonDecl; // r10
  double v43; // fp10
  double v44; // fp9
  double v45; // fp13
  double v46; // fp12
  double v47; // fp11
  const idDeclRibbon *v48; // r10
  double v49; // fp3
  double v50; // fp1
  const idDeclRibbon *v51; // r10
  double v52; // fp13
  double v53; // fp10
  double v54; // fp9
  double v55; // fp4
  double v56; // fp3
  float *v57; // r10
  double v58; // fp7
  double v59; // fp5
  double v60; // fp3
  double v61; // fp11
  double v63; // fp9
  double v65; // fp7
  int numActiveNodes; // r11
  idVec3 v67; // [sp+50h] [-E0h] BYREF
  float v68; // [sp+60h] [-D0h] BYREF
  float v69; // [sp+64h] [-CCh]
  float v70; // [sp+68h] [-C8h]
  idVec3 v71; // [sp+70h] [-C0h] BYREF
  float v72; // [sp+80h] [-B0h] BYREF
  float v73; // [sp+84h] [-ACh]
  float v74; // [sp+88h] [-A8h]

  if ( this->ribbonDecl != nullptr )
  {
    this->explicitDefineBothEdges = origin != origin2;
    v71.x = 0.0;
    x = 0.0;
    v71.y = 0.0;
    y = 0.0;
    v71.z = 0.0;
    z = 0.0;
    v67.x = 0.0;
    v67.y = 0.0;
    v67.z = 0.0;
    idRibbon::CalcTurbulence(this, origin, axis, turb: &v71, a5: a8);
    LODWORD(v18) = &v72;
    HIDWORD(v18) = velocity;
    v68 = 0.0;
    v69 = 0.0;
    v70 = 0.0;
    v72 = 0.0;
    v73 = 0.0;
    v74 = 0.0;
    v19 = 0.0;
    v20 = 0.0;
    v21 = 0.0;
    idRibbon::CalcHelix(this, currentTime, origin, axis, helix: v18, a6: v22);
    if ( this->explicitDefineBothEdges )
    {
      idRibbon::CalcTurbulence(this, origin: origin2, axis, turb: &v67, a5: v23);
      LODWORD(v24) = &v68;
      HIDWORD(v24) = velocity;
      idRibbon::CalcHelix(this, currentTime, origin: origin2, axis, helix: v24, a6: v25);
      z = v67.z;
      y = v67.y;
      x = v67.x;
      v21 = v70;
      v20 = v69;
      v19 = v68;
    }
    v26 = v71.x;
    v27 = v71.y;
    v28 = v71.z;
    v29 = v72;
    v30 = v73;
    v31 = v74;
    v32 = (this->currHeadIdx + 1) % 128;
    this->currHeadIdx = v32;
    v33 = &this->ribbonNodes[v32];
    v33->spawnTime = currentTime;
    v34 = (float)(origin->y + (float)v27);
    v35 = (float)(origin->z + (float)v28);
    v33->origin.x = (float)(origin->x + (float)v26) + (float)v29;
    v33->origin.y = (float)v34 + (float)v30;
    v33->origin.z = (float)v35 + (float)v31;
    if ( this->explicitDefineBothEdges )
    {
      v36 = (float)((float)x + (float)v26);
      v37 = (float)(origin2->y + (float)y);
      v38 = (float)(origin2->z + (float)z);
      v39 = (float)((float)y + (float)v27);
      v40 = (float)((float)z + (float)v28);
      v41 = (float)((float)v19 + (float)v29);
      v33->origin2.x = (float)(origin2->x + (float)x) + (float)v19;
      v33->origin2.y = (float)v37 + (float)v20;
      v33->origin2.z = (float)v38 + (float)v21;
      ribbonDecl = this->ribbonDecl;
      v43 = (float)((float)((float)v20 + (float)v30) * ribbonDecl->helix.velocity);
      v44 = (float)((float)((float)v21 + (float)v31) * ribbonDecl->helix.velocity);
      v45 = (float)((float)(velocity->y
                          + (float)((float)(ribbonDecl->velocity.x * axis->mat[0].y)
                                  + (float)((float)(axis->mat[1].y * ribbonDecl->velocity.y)
                                          + (float)(axis->mat[2].y * ribbonDecl->velocity.z))))
                  + (float)((float)((float)v39 * ribbonDecl->turbulence.velocity) * (float)0.5));
      v46 = (float)((float)(velocity->z
                          + (float)((float)(ribbonDecl->velocity.x * axis->mat[0].z)
                                  + (float)((float)(axis->mat[1].z * ribbonDecl->velocity.y)
                                          + (float)(axis->mat[2].z * ribbonDecl->velocity.z))))
                  + (float)((float)((float)v40 * ribbonDecl->turbulence.velocity) * (float)0.5));
      v47 = (float)((float)((float)(velocity->x
                                  + (float)((float)(ribbonDecl->velocity.x * axis->mat[0].x)
                                          + (float)((float)(axis->mat[1].x * ribbonDecl->velocity.y)
                                                  + (float)(axis->mat[2].x * ribbonDecl->velocity.z))))
                          + (float)((float)((float)v36 * ribbonDecl->turbulence.velocity) * (float)0.5))
                  + (float)((float)v41 * ribbonDecl->helix.velocity));
    }
    else
    {
      v48 = this->ribbonDecl;
      v49 = (float)(v48->helix.velocity * (float)v29);
      v43 = (float)((float)v30 * v48->helix.velocity);
      v44 = (float)((float)v31 * v48->helix.velocity);
      v50 = (float)((float)(velocity->x
                          + (float)((float)(v48->velocity.x * axis->mat[0].x)
                                  + (float)((float)(axis->mat[1].x * v48->velocity.y)
                                          + (float)(axis->mat[2].x * v48->velocity.z))))
                  + (float)(v48->turbulence.velocity * (float)v26));
      v45 = (float)((float)(velocity->y
                          + (float)((float)(v48->velocity.x * axis->mat[0].y)
                                  + (float)((float)(axis->mat[1].y * v48->velocity.y)
                                          + (float)(axis->mat[2].y * v48->velocity.z))))
                  + (float)((float)v27 * v48->turbulence.velocity));
      v46 = (float)((float)(velocity->z
                          + (float)((float)(v48->velocity.x * axis->mat[0].z)
                                  + (float)((float)(axis->mat[1].z * v48->velocity.y)
                                          + (float)(axis->mat[2].z * v48->velocity.z))))
                  + (float)((float)v28 * v48->turbulence.velocity));
      v47 = (float)((float)v50 + (float)v49);
    }
    v33->velocity.z = (float)v46 + (float)v44;
    v33->velocity.y = (float)v45 + (float)v43;
    v33->velocity.x = v47;
    v51 = this->ribbonDecl;
    v52 = color->y;
    v53 = color->x;
    v54 = v51->color.y;
    v55 = v51->color.x;
    v56 = (float)(v51->color.w * color->w);
    v33->color.z = v51->color.z * color->z;
    v33->color.w = v56;
    v33->color.y = (float)v54 * (float)v52;
    v33->color.x = (float)v55 * (float)v53;
    v33->orientVec.x = axis->mat[0].x;
    v33->orientVec.y = axis->mat[0].y;
    v33->orientVec.z = axis->mat[0].z;
    if ( this->ribbonDecl->maxLength != 0.0 )
    {
      if ( this->numActiveNodes != 0 )
      {
        v57 = (float *)((char *)this + 72 * ((this->currHeadIdx + 127) % 128));
        v58 = (float)(origin->z - v57[22]);
        v59 = (float)(origin->x - v57[20]);
        v60 = (float)(origin->y - v57[21]);
        v61 = (float)((float)((float)v60 * (float)v60)
                    + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)));
        _FP10 = (float)((float)((float)((float)v60 * (float)v60)
                              + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        v63 = (float)((float)((float)((float)v60 * (float)v60)
                            + (float)((float)((float)v59 * (float)v59) + (float)((float)v58 * (float)v58)))
                    * (float)0.5);
        __asm { fsel      f8, f10, f11, f12 }
        v65 = __frsqrte(_FP8);
        v33->nodeLength = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65) * (float)v63)
                                                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                                                                - (float)1.5)
                                                                                * (float)v65))
                                                                * (float)v63)
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65)
                                                                                                * (float)v63)
                                                                                        * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5)
                                                                                                * (float)v65))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)v63)
                                                                                                * (float)v65)
                                                                                        - (float)1.5)
                                                                        * (float)v65)))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                                                                - (float)1.5)
                                                                                * (float)v65)
                                                                        * (float)v63)
                                                                * (float)((float)-(float)((float)((float)((float)v65 * (float)v63)
                                                                                                * (float)v65)
                                                                                        - (float)1.5)
                                                                        * (float)v65))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                                - (float)1.5)
                                                * (float)v65)))
                        * (float)v61;
      }
      else
      {
        v33->nodeLength = 0.0;
      }
    }
    numActiveNodes = this->numActiveNodes;
    if ( numActiveNodes < 128 )
      this->numActiveNodes = numActiveNodes + 1;
  }
}


// ========================================================================
// ?UpdatePosition@idRibbon@@QAAXHABVidVec3@@0ABVidMat3@@0ABVidVec4@@@Z
// EA  : 0x827167B8
// RVA : 0x007167B8
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::UpdatePosition(
        idRibbon *this,
        int currentTime,
        const idVec3 *origin,
        __int64 axis,
        const idVec3 *velocity,
        const idVec4 *color,
        long double a7)
{
  const idDeclRibbon *ribbonDecl; // r11
  __int64 v11; // r28
  double v14; // fp10
  double v15; // fp7
  double v16; // fp4
  idVec3 *p_prevOrigin; // r29
  double v18; // fp0
  double v19; // fp13
  double v20; // fp12
  int prevTime; // r4
  long double v22; // fp2
  bool v23; // r20
  double v24; // fp7
  int v25; // r11
  int v26; // r22
  __int64 v27; // r11
  int v28; // r24
  double v29; // fp31
  const idMat3 *v30; // r7
  __int64 v31; // r4
  double v32; // fp0
  float y; // r19
  float v34; // r18
  float x; // r16
  float z; // r17
  float v37; // r15
  float v38; // r14
  float v39; // r10
  int v40; // r11
  float v41; // r11
  long double v42; // fp2
  float v43; // r10
  float v44; // r19
  float v45; // r18
  float v46; // r11
  double v47; // fp11
  double v48; // fp12
  int v49; // r10
  long double v50; // fp2
  idVec4 v51; // [sp+60h] [-160h] BYREF
  int v52; // [sp+70h] [-150h]
  float v53; // [sp+74h] [-14Ch]
  float v54; // [sp+78h] [-148h]
  float v55; // [sp+80h] [-140h]
  float v56; // [sp+84h] [-13Ch]
  float v57; // [sp+88h] [-138h]
  __int64 v58; // [sp+90h] [-130h]
  float v59; // [sp+98h] [-128h]
  float v60; // [sp+9Ch] [-124h]
  int v61; // [sp+A0h] [-120h]
  float v62; // [sp+A8h] [-118h]
  float v63; // [sp+ACh] [-114h]
  float v64; // [sp+B0h] [-110h]
  float v65; // [sp+B8h] [-108h]
  float v66; // [sp+BCh] [-104h]
  float v67; // [sp+C0h] [-100h]
  float v68; // [sp+C8h] [-F8h]
  float v69; // [sp+CCh] [-F4h]
  float v70; // [sp+D0h] [-F0h]
  idVec3 v71; // [sp+D8h] [-E8h] BYREF
  idVec3 v72; // [sp+E8h] [-D8h] BYREF
  __int64 v73; // [sp+F8h] [-C8h]
  __int64 v74; // [sp+100h] [-C0h]
  int v76; // [sp+10Ch] [-B4h]

  ribbonDecl = this->ribbonDecl;
  v11 = axis;
  if ( ribbonDecl != nullptr && this->ribbonState == RIBBON_ACTIVE )
  {
    if ( ribbonDecl->minNodeDistance <= 0.0
      || (v14 = (float)(this->prevOrigin.y - origin->y),
          v15 = (float)(this->prevOrigin.z - origin->z),
          v16 = (float)(this->prevOrigin.x - origin->x),
          *((double *)&a7 + 1) = (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)),
          *(double *)&a7 = (float)((float)((float)v16 * (float)v16)
                                 + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))),
          *(double *)&a7 > (float)(ribbonDecl->minNodeDistance * ribbonDecl->minNodeDistance)) )
    {
      p_prevOrigin = &this->prevOrigin;
      v18 = (float)(this->prevOrigin.x - origin->x);
      v19 = (float)(this->prevOrigin.z - origin->z);
      v20 = (float)(this->prevOrigin.y - origin->y);
      if ( (float)((float)((float)v20 * (float)v20)
                 + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) >= 1000000.0 )
      {
        v51.x = 0.0;
        v51.y = 0.0;
        v51.z = 0.0;
        prevTime = this->prevTime;
        v51.w = 1.0;
        idRibbon::AddNode(
          this,
          currentTime: prevTime,
          origin: &this->prevOrigin,
          origin2: &this->prevOrigin,
          (const idMat3 *)axis,
          velocity: &vec3_origin,
          color: &v51,
          a8: a7);
        v51.x = 0.0;
        v51.y = 0.0;
        v51.z = 0.0;
        v51.w = 1.0;
        idRibbon::AddNode(
          this,
          currentTime,
          origin,
          origin2: origin,
          axis: (const idMat3 *)v11,
          velocity: &vec3_origin,
          color: &v51,
          a8: v22);
        this->prevTime = currentTime;
        p_prevOrigin->x = origin->x;
        this->prevOrigin.y = origin->y;
        this->prevOrigin.z = origin->z;
        return;
      }
      v23 = origin != (const idVec3 *)HIDWORD(axis);
      if ( ribbonDecl->nodeSubdivision > 0.0 && this->prevTime >= 0 )
      {
        v24 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18)
                                            + (float)((float)((float)v19 * (float)v19) + (float)((float)v20 * (float)v20))))
                    / ribbonDecl->nodeSubdivision);
        v25 = (int)v24 + 1;
        if ( v25 >= 128 )
        {
          v26 = 128;
LABEL_11:
          HIDWORD(v27) = 0x82000000;
          v28 = 0;
          if ( v26 > 0 )
          {
            LODWORD(v27) = currentTime;
            v29 = (float)v27;
            do
            {
              LODWORD(v27) = v28;
              v30 = (const idMat3 *)v11;
              HIDWORD(v31) = this;
              v32 = (float)((float)((float)v27 + (float)1.0) * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v26)));
              if ( v23 )
              {
                y = origin->y;
                v34 = this->prevOrigin.y;
                v58 = v11;
                x = this->prevOrigin2.x;
                LODWORD(v11) = *(_DWORD *)HIDWORD(v11);
                z = this->prevOrigin.z;
                v37 = this->prevOrigin2.y;
                v38 = this->prevOrigin2.z;
                v69 = y;
                v56 = v34;
                v62 = x;
                v52 = v11;
                v57 = z;
                v63 = v37;
                v64 = v38;
                LODWORD(v31) = LODWORD(origin->z);
                v39 = *(float *)(HIDWORD(v11) + 8);
                v53 = *(float *)(HIDWORD(v11) + 4);
                v40 = this->prevTime;
                v70 = *((float *)&v31 + 1);
                LODWORD(v31) = v40;
                v73 = v31;
                v54 = v39;
                v41 = p_prevOrigin->x;
                v68 = origin->x;
                v55 = v41;
                *((double *)&v42 + 1) = (float)v31;
                v51.x = (float)((float)(v68 - v41) * (float)v32) + v41;
                v51.y = (float)((float)(y - v34) * (float)v32) + v34;
                v72.x = (float)((float)(*((float *)&v11 + 1) - x) * (float)v32) + x;
                v72.y = (float)((float)(v53 - v37) * (float)v32) + v37;
                *(double *)&v42 = (float)((float)((float)(v39 - v38) * (float)v32) + v38);
                v72.z = (float)((float)(v39 - v38) * (float)v32) + v38;
                v51.z = (float)((float)(v70 - z) * (float)v32) + z;
                v76 = (int)(float)((float)((float)((float)v29 - (float)v31) * (float)v32) + (float)v31);
                idRibbon::AddNode(
                  this,
                  currentTime: v76,
                  origin: (const idVec3 *)&v51,
                  origin2: &v72,
                  axis: v30,
                  velocity,
                  color,
                  a8: v42);
                v11 = v58;
              }
              else
              {
                v43 = this->prevOrigin.y;
                LODWORD(v31) = LODWORD(this->prevOrigin.z);
                v44 = origin->x;
                v45 = origin->y;
                v59 = p_prevOrigin->x;
                v46 = origin->z;
                v61 = v31;
                v47 = *((float *)&v31 + 1);
                v60 = v43;
                v48 = v43;
                v49 = this->prevTime;
                v65 = v44;
                v67 = v46;
                LODWORD(v31) = v49;
                v66 = v45;
                v74 = v31;
                *((double *)&v50 + 1) = (float)(v46 - (float)v47);
                v71.x = (float)((float)(v44 - v59) * (float)v32) + v59;
                v71.z = (float)((float)(v46 - (float)v47) * (float)v32) + (float)v47;
                *(double *)&v50 = (float)((float)v29 - (float)v31);
                v71.y = (float)((float)(v45 - (float)v48) * (float)v32) + (float)v48;
                LODWORD(v58) = (int)(float)((float)((float)((float)v29 - (float)v31) * (float)v32) + (float)v31);
                idRibbon::AddNode(
                  this,
                  currentTime: v58,
                  origin: &v71,
                  origin2: &v71,
                  axis: (const idMat3 *)v11,
                  velocity,
                  color,
                  a8: v50);
              }
              ++v28;
            }
            while ( v28 < v26 );
          }
LABEL_22:
          this->prevTime = currentTime;
          p_prevOrigin->x = origin->x;
          this->prevOrigin.y = origin->y;
          this->prevOrigin.z = origin->z;
          if ( v23 )
          {
            this->prevOrigin2.x = *(float *)HIDWORD(v11);
            this->prevOrigin2.y = *(float *)(HIDWORD(v11) + 4);
            this->prevOrigin2.z = *(float *)(HIDWORD(v11) + 8);
          }
          return;
        }
        v26 = (int)v24 + 1;
        if ( v25 > 1 )
          goto LABEL_11;
      }
      if ( origin == (const idVec3 *)HIDWORD(axis) )
        HIDWORD(axis) = origin;
      idRibbon::AddNode(
        this,
        currentTime,
        origin,
        origin2: (const idVec3 *)HIDWORD(axis),
        (const idMat3 *)axis,
        velocity,
        color,
        a8: a7);
      goto LABEL_22;
    }
  }
}


// ========================================================================
// ?UpdatePosition@idRibbon@@QAAXHABVidVec3@@ABVidMat3@@0ABVidVec4@@@Z
// EA  : 0x82716CA0
// RVA : 0x00716CA0
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

void __fastcall idRibbon::UpdatePosition(
        idRibbon *this,
        int currentTime,
        const idVec3 *origin,
        __int64 velocity,
        const idVec3 *color,
        long double a6,
        int a7,
        const idVec4 *a8)
{
  idRibbon::UpdatePosition(this, currentTime, origin, axis: velocity, velocity: color, color: a8, a7: a6);
}


// ========================================================================
// ?UpdateGeometry@idRibbon@@QAAXHPAVidRenderModelBeam@@ABVidMat3@@ABVidVec3@@@Z
// EA  : 0x82716CB8
// RVA : 0x00716CB8
// PDB : w:\tech5\engine\gamelib\effects\ribbon.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRibbon::UpdateGeometry(
        idRibbon *this,
        int currentTime,
        idRenderModelBeam *beamModel,
        const idMat3 *axis,
        __int64 translate,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        const idMat3 *a17)
{
  int numActiveNodes; // r11
  int v20; // r14
  float *v21; // r31
  int *p_numActiveNodes; // r30
  const idDeclRibbon **p_ribbonDecl; // r23
  double v24; // fp17
  double v25; // fp16
  double v26; // fp18
  idList<idVehicleState *,5> *v27; // r3
  idList<beamNodeParms_t,5> *v28; // r15
  double v29; // fp19
  double v30; // fp21
  double v31; // fp20
  int i; // r10
  int v33; // r11
  float *v34; // r11
  double v35; // fp10
  double v36; // fp7
  int v37; // r20
  __int64 v39; // r10
  double v40; // fp25
  double v48; // fp29
  int v49; // r11
  int v50; // r29
  int v51; // r11
  int v52; // r10
  __int64 v53; // r5
  char *v54; // r10
  int v55; // r24
  float *v56; // r30 OVERLAPPED
  char *v57; // r11
  __int64 v58; // r8
  float *v59; // r31
  double v60; // fp30
  double v61; // fp28
  int num; // r11
  int size; // r10
  beamNodeParms_t *list; // r10
  float *p_x; // r11
  double v67; // fp10
  double v68; // fp3
  double v69; // fp1
  double v70; // fp0
  double v71; // fp5
  double v72; // fp7
  double v73; // fp11
  double v74; // fp10
  double v75; // fp10
  double v76; // fp3
  double v77; // fp1
  double v78; // fp0
  double v79; // fp6
  double v80; // fp5
  double v81; // fp10
  double v82; // fp12
  const idDeclRibbon *v83; // r10
  double v84; // fp6
  double v85; // fp4
  double fadeInFraction; // fp0
  double v87; // fp3
  double v88; // fp0
  double fadeOutFraction; // fp13
  const idMat3 *v94; // r10
  double z; // fp12
  int j; // ctr
  __int64 v100; // r10
  double v103; // fp10
  double v104; // fp13
  const idDeclRibbon *v105; // r5
  double textureTMin; // fp12
  double textureTMax; // fp11
  int v113; // r31
  double v115; // fp0
  double v116; // fp13
  double v118; // fp7
  __int64 v126; // r10
  const idMaterial *material; // r10
  float w; // r9
  float x; // r7
  float y; // r5
  int v131; // r11
  beamNodeParms_t *v132; // r9
  int v134; // [sp+60h] [-1D0h]
  float v135; // [sp+68h] [-1C8h] BYREF
  float v136; // [sp+6Ch] [-1C4h] BYREF
  float v137; // [sp+70h] [-1C0h] BYREF
  float *p_z; // [sp+74h] [-1BCh]
  float v139; // [sp+78h] [-1B8h] BYREF
  float v140; // [sp+7Ch] [-1B4h] BYREF
  float v141; // [sp+80h] [-1B0h] BYREF
  float *p_y; // [sp+84h] [-1ACh]
  float *p_w; // [sp+88h] [-1A8h]
  float v144; // [sp+90h] [-1A0h] BYREF
  float v145; // [sp+94h] [-19Ch] BYREF
  float v146; // [sp+98h] [-198h] BYREF
  float v147; // [sp+A0h] [-190h] BYREF
  float v148; // [sp+A4h] [-18Ch] BYREF
  float v149; // [sp+A8h] [-188h] BYREF
  float v150[3]; // [sp+B0h] [-180h] BYREF
  float v151; // [sp+BCh] [-174h]
  float v152; // [sp+C0h] [-170h]
  float v153; // [sp+C4h] [-16Ch]
  float v154; // [sp+C8h] [-168h]
  float v155; // [sp+CCh] [-164h]
  __int64 v156; // [sp+D0h] [-160h]
  __int64 v157; // [sp+D8h] [-158h]
  __int64 v158; // [sp+E0h] [-150h]
  __int64 v159; // [sp+E8h] [-148h]
  unsigned __int64 v160; // [sp+F0h] [-140h]
  __int64 v161; // [sp+F8h] [-138h]

  _R12 = -304;
  __asm { stvx128   v127, r1, r12 }
  numActiveNodes = this->numActiveNodes;
  v20 = currentTime;
  a13 = currentTime;
  a17 = axis;
  v21 = (float *)HIDWORD(translate);
  p_numActiveNodes = &this->numActiveNodes;
  if ( numActiveNodes >= 2 )
  {
    p_ribbonDecl = &this->ribbonDecl;
    if ( this->ribbonDecl != nullptr )
    {
      LODWORD(translate) = (*p_ribbonDecl)->duration;
      v24 = (float)((float)1.0 / (*p_ribbonDecl)->fadeInFraction);
      v134 = translate;
      v25 = (float)((float)1.0 / (*p_ribbonDecl)->fadeOutFraction);
      v26 = (float)((float)1.0 / (float)((float)translate * (float)0.001));
      v27 = (idList<idVehicleState *,5> *)idRenderModelBeam::DrawBeamAlloc(this: beamModel);
      v28 = (idList<beamNodeParms_t,5> *)v27;
      if ( v27 != nullptr )
      {
        v29 = 0.0;
        v30 = 0.0;
        v31 = 0.0;
        if ( ((*((_DWORD *)v21 + 2) | *(_DWORD *)v21 | *((_DWORD *)v21 + 1)) & 0x7FFFFFFF) != 0
          || (*p_ribbonDecl)->maxLength != 0.0 )
        {
          for ( i = 0; i < *p_numActiveNodes - 1; v34[22] = (float)v36 + v21[2] )
          {
            v33 = this->currHeadIdx - i++;
            v34 = (float *)((char *)this + 72 * ((v33 + 128) % 128));
            v35 = v34[21];
            v29 = (float)(v34[37] + (float)v29);
            v34[20] = *v21 + v34[20];
            v36 = v34[22];
            v34[21] = (float)v35 + v21[1];
          }
          v29 = (float)((float)1.0 / (float)v29);
        }
        idList<idThread *,58>::Clear(this: v27);
        v37 = 0;
        _R21 = 2;
        LODWORD(v39) = *p_numActiveNodes - 1;
        v40 = (float)((float)1.0 / (float)v39);
        if ( (int)v39 > 0 )
        {
          __asm { vspltisw128 v127, 0 }
          p_y = &this->globalColor.y;
          p_z = &this->globalColor.z;
          p_w = &this->globalColor.w;
          _R22 = 1;
          _R17 = -2;
          _R18 = -1;
          _R27 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
          _R26 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
          _R25 = &_vmx_3f8000003f8000003f8000003f800000;
          _R19 = &vec3_origin;
          while ( 1 )
          {
            v48 = 0.5;
            v49 = this->currHeadIdx - v37 + 128;
            HIDWORD(v58) = (v49 / 128) << 7;
            v50 = v49 % 128;
            v52 = 8 * (v49 % 128);
            v51 = v49 % 128 + 127;
            HIDWORD(v53) = v51 / 128;
            v54 = (char *)this + 8 * v50 + 8 * v52;
            v55 = v51 % 128;
            v56 = (float *)(v54 + 80);
            v57 = (char *)this + 72 * (v51 % 128);
            LODWORD(v58) = v20 - *((_DWORD *)v54 + 36);
            v59 = (float *)(v57 + 80);
            v158 = v58;
            LODWORD(v53) = v20 - *((_DWORD *)v57 + 36);
            v161 = v53;
            v60 = (float)((float)v58 * (float)0.001);
            v61 = (float)((float)v53 * (float)0.001);
            if ( v134 > 0 )
            {
              v48 = (float)((float)((float)v58 * (float)0.001) * (float)v26);
              if ( v48 >= 0.0 )
              {
                if ( v48 > 1.0 )
                  v48 = 1.0;
              }
              else
              {
                v48 = 0.0;
              }
            }
            idList<beamNodeParms_t,5>::PreAllocateWithGranularity(this: v28, newSize: v28->num + 1);
            num = v28->num;
            size = v28->size;
            if ( num >= size )
            {
              p_x = &v28->list[size - 1].startPos.x;
            }
            else
            {
              list = v28->list;
              v28->num = num + 1;
              p_x = &list[num].startPos.x;
            }
            v67 = v56[1];
            v68 = v56[2];
            v69 = (float)((float)(v56[7] - (*p_ribbonDecl)->gravity.y) * (float)v60);
            v70 = (float)((float)(v56[8] - (*p_ribbonDecl)->gravity.z) * (float)v60);
            *p_x = *v56 + (float)((float)(v56[6] - (*p_ribbonDecl)->gravity.x) * (float)v60);
            p_x[1] = (float)v67 + (float)v69;
            p_x[2] = (float)v68 + (float)v70;
            v71 = v59[1];
            v72 = *v59;
            v73 = (float)((float)(v59[7] - (*p_ribbonDecl)->gravity.y) * (float)v61);
            v74 = (float)((float)(v59[6] - (*p_ribbonDecl)->gravity.x) * (float)v61);
            p_x[5] = v59[2] + (float)((float)(v59[8] - (*p_ribbonDecl)->gravity.z) * (float)v61);
            p_x[4] = (float)v71 + (float)v73;
            p_x[3] = (float)v72 + (float)v74;
            p_x[19] = (float)((float)((float)((*p_ribbonDecl)->endWidth - (*p_ribbonDecl)->startWidth) * (float)v48)
                            + (*p_ribbonDecl)->startWidth)
                    * (float)0.5;
            if ( this->explicitDefineBothEdges )
            {
              v75 = v56[5];
              v76 = v56[3];
              v77 = (float)((float)(v56[8] - (*p_ribbonDecl)->gravity.z) * (float)v60);
              v78 = (float)((float)(v56[6] - (*p_ribbonDecl)->gravity.x) * (float)v60);
              p_x[7] = v56[4] + (float)((float)(v56[7] - (*p_ribbonDecl)->gravity.y) * (float)v60);
              p_x[8] = (float)v75 + (float)v77;
              p_x[6] = (float)v78 + (float)v76;
              v79 = v59[5];
              v80 = v59[3];
              v81 = (float)((float)(v59[6] - (*p_ribbonDecl)->gravity.x) * (float)v61);
              v82 = (float)((float)(v59[8] - (*p_ribbonDecl)->gravity.z) * (float)v61);
              p_x[10] = v59[4] + (float)((float)(v59[7] - (*p_ribbonDecl)->gravity.y) * (float)v61);
              p_x[9] = (float)v81 + (float)v80;
              p_x[11] = (float)v79 + (float)v82;
            }
            v83 = *p_ribbonDecl;
            v84 = (float)(v56[13] * *p_y);
            v85 = (float)(v56[14] * *p_z);
            fadeInFraction = (*p_ribbonDecl)->fadeInFraction;
            v87 = (float)(v56[15] * *p_w);
            v150[0] = this->globalColor.x * v56[12];
            v150[1] = v84;
            v150[2] = v85;
            v151 = v87;
            if ( fadeInFraction <= 0.0 || v48 >= fadeInFraction )
            {
              fadeOutFraction = v83->fadeOutFraction;
              if ( fadeOutFraction <= 0.0 || (float)((float)1.0 - (float)v48) >= fadeOutFraction )
                goto LABEL_29;
              v88 = (float)((float)((float)1.0 - (float)v48) * (float)v25);
            }
            else
            {
              v88 = (float)((float)v48 * (float)v24);
            }
            v151 = v88;
LABEL_29:
            _R9 = v150;
            _R8 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
            _R10 = p_x + 20;
            _R7 = 3;
            __asm
            {
              lvx128    v63, r0, r8
              lvx128    v62, r0, r9
              vmulfp128 v61, v94, v63
              vcfpsxws128 v60, v61, 0
              vpkswss128 v59, v92, v60
              vpkshus128 v0, v91, v59
              stvebx    v0, 0, r10
              stvebx    v0, r10, r22
              stvebx    v0, r10, r21
              stvebx    v0, r10, r7
            }
            if ( (*p_ribbonDecl)->reorientNodes )
            {
              v94 = a17;
              p_x[12] = a17->mat[0].x;
              p_x[13] = v94->mat[0].y;
              z = v94->mat[0].z;
            }
            else
            {
              p_x[12] = v56[9];
              p_x[13] = v56[10];
              z = v56[11];
            }
            p_x[14] = z;
            _R10 = (char *)p_x + 86;
            _R9 = 8;
            _R8 = 4;
            for ( j = 4; j != 0; --j )
            {
              __asm
              {
                vmr128    v58, v127
                lvlx128   v57, r0, r19
                lvlx128   v56, r19, r8
                lvlx128   v55, r19, r9
                lvx128    v63, r0, r25
                vrlimi128 v58, v57, 8, 0
                lvx128    v0, r0, r26
                lvx128    v13, r0, r27
                vrlimi128 v58, v56, 4, 3
                vrlimi128 v58, v55, 2, 2
                vaddfp128 v12, v90, v63
                vmaddfp   v0, v12, v0, v13
                vcfpsxws128 v54, v0, 0
                vpkswss128 v53, v86, v54
                vpkshus128 v0, v85, v53
                stvebx    v0, r10, r17
                stvebx    v0, r10, r18
                stvebx    v0, 0, r10
              }
              _R10 += 4;
            }
            LODWORD(v100) = *p_ribbonDecl;
            HIDWORD(v100) = (*p_ribbonDecl)->textureRepeatStretch;
            if ( (*p_ribbonDecl)->textureRepeatStretch )
            {
              LODWORD(v100) = v37;
              v136 = -1.0;
              _R7 = &v136;
              _R6 = &v137;
              v103 = (float)v100;
              v104 = (float)(this->startVariance * (float)2.0);
              v156 = v100;
              __asm
              {
                vmr128    v52, v127
                lvx128    v63, r0, r25
              }
              v105 = *p_ribbonDecl;
              __asm { lvx128    v13, r0, r27 }
              __asm { lvx128    v0, r0, r26 }
              _R8 = &v135;
              _R4 = &v140;
              __asm { vmr128    v51, v127 }
              v160 = __PAIR64__(&v135, v50);
              textureTMin = v105->textureTMin;
              _R3 = &v141;
              textureTMax = v105->textureTMax;
              _R5 = &v139;
              v113 = v55;
              __asm { vmr128    v41, v127 }
              v137 = (float)v104 - (float)1.0;
              v157 = *(_QWORD *)(&v56 - 1);
              v135 = (float)((float)((float)v100 * (float)v40) * (float)2.0) - (float)1.0;
              _R10 = p_x + 21;
              __asm { lvlx128   v49, r0, r7 }
              __asm { lvlx128   v48, r0, r6 }
              v115 = (float)*(__int64 *)(&v56 - 1);
              _R31 = &v147;
              v116 = (float)__SPAIR64__(&v135, v50);
              __asm
              {
                lvlx128   v50, r0, r8
                vrlimi128 v52, v50, 8, 0
                vrlimi128 v52, v49, 4, 3
                vrlimi128 v52, v48, 2, 2
                vaddfp128 v12, v84, v63
                vmaddfp   v0, v12, v0, v13
                vcfpsxws128 v47, v0, 0
                vpkswss128 v46, v79, v47
                vpkshus128 v0, v78, v46
                stvebx    v0, 0, r10
                stvebx    v0, r10, r22
                stvebx    v0, r10, r21
              }
              _R10 = p_x + 22;
              v118 = (float)((float)(this->startVariance * (float)2.0) - (float)1.0);
              v139 = (float)((float)((float)v103 * (float)v40) * (float)2.0) - (float)1.0;
              v140 = 1.0;
              v141 = v118;
              __asm { lvlx128   v45, r0, r4 }
              _R4 = &v148;
              __asm { lvlx128   v44, r0, r3 }
              _R3 = &v149;
              __asm
              {
                lvx128    v63, r0, r25
                lvx128    v0, r0, r26
                lvx128    v13, r0, r27
                lvlx128   v43, r0, r5
                vrlimi128 v51, v43, 8, 0
                vrlimi128 v51, v45, 4, 3
                vrlimi128 v51, v44, 2, 2
                vaddfp128 v12, v83, v63
                vmaddfp   v0, v12, v0, v13
                vcfpsxws128 v42, v0, 0
                vpkswss128 v39, v74, v42
              }
              _R8 = &v145;
              __asm { vmr128    v40, v127 }
              _R6 = &v146;
              _R7 = &v144;
              __asm
              {
                vpkshus128 v0, v71, v39
                stvebx    v0, 0, r10
                stvebx    v0, r10, r22
                stvebx    v0, r10, r21
              }
              _R10 = p_x + 23;
              v148 = -1.0;
              v147 = (float)((float)((float)((float)v103 * (float)v40) + (float)v40) * (float)2.0) - (float)1.0;
              v149 = (float)(this->startVariance * (float)2.0) - (float)1.0;
              __asm
              {
                lvlx128   v38, r0, r4
                lvlx128   v36, r0, r3
                lvx128    v63, r0, r25
                lvx128    v13, r0, r27
                lvx128    v0, r0, r26
                lvlx128   v37, r0, r31
                vrlimi128 v41, v37, 8, 0
                vrlimi128 v41, v38, 4, 3
                vrlimi128 v41, v36, 2, 2
                vaddfp128 v12, v73, v63
                vmaddfp   v0, v12, v0, v13
                vcfpsxws128 v35, v0, 0
                vpkswss128 v34, v67, v35
                vpkshus128 v0, v66, v34
                stvebx    v0, 0, r10
                stvebx    v0, r10, r22
                stvebx    v0, r10, r21
              }
              _R10 = p_x + 24;
              v144 = v147;
              v145 = 1.0;
              __asm
              {
                lvx128    v63, r0, r25
                lvx128    v13, r0, r27
                lvx128    v0, r0, r26
              }
              v146 = (float)(this->startVariance * (float)2.0) - (float)1.0;
              __asm
              {
                lvlx128   v33, r0, r8
                lvlx128   v62, r0, r6
                lvlx128   v32, r0, r7
                vrlimi128 v40, v32, 8, 0
                vrlimi128 v40, v33, 4, 3
                vrlimi128 v40, v62, 2, 2
                vaddfp128 v12, v72, v63
                vmaddfp   v0, v12, v0, v13
                vcfpsxws128 v61, v0, 0
                vpkswss128 v60, v93, v61
                vpkshus128 v0, v92, v60
                stvebx    v0, 0, r10
                stvebx    v0, r10, r22
                stvebx    v0, r10, r21
              }
            }
            else if ( *(_BYTE *)(v100 + 134) != 0 )
            {
              v116 = 0.0;
              v115 = 1.0;
              textureTMin = (*p_ribbonDecl)->textureTMin;
              textureTMax = (*p_ribbonDecl)->textureTMax;
            }
            else if ( *(float *)(v100 + 72) == 0.0 )
            {
              LODWORD(v126) = v37;
              HIDWORD(v126) = *p_ribbonDecl;
              v159 = v126;
              textureTMin = *(float *)(HIDWORD(v126) + 136);
              textureTMax = *(float *)(HIDWORD(v126) + 140);
              v116 = (float)((float)v126 * (float)v40);
              v115 = (float)((float)((float)v126 * (float)v40) + (float)v40);
            }
            else
            {
              v30 = (float)(v56[17] + (float)v30);
              v116 = v31;
              textureTMin = (*p_ribbonDecl)->textureTMin;
              textureTMax = (*p_ribbonDecl)->textureTMax;
              v115 = (float)((float)v30 * (float)v29);
              v31 = v115;
            }
            material = (*p_ribbonDecl)->material;
            if ( material != nullptr && (*((_BYTE *)material + 72) & 4) != 0 )
            {
              w = material->atlasScaleBias.w;
              x = material->atlasScaleBias.x;
              y = material->atlasScaleBias.y;
              v154 = material->atlasScaleBias.z;
              v155 = w;
              v152 = x;
              v153 = y;
              v116 = (float)((float)((float)((float)v116 + (float)((float)0.5 / (float)(v152 * (float)4096.0))) * v152)
                           + v154);
              v115 = (float)((float)((float)((float)v115 - (float)((float)0.5 / (float)(v152 * (float)4096.0))) * v152)
                           + v154);
              textureTMin = (float)((float)((float)((float)textureTMin
                                                  + (float)((float)0.5 / (float)(v153 * (float)4096.0)))
                                          * v153)
                                  + w);
              textureTMax = (float)((float)((float)((float)textureTMax
                                                  - (float)((float)0.5 / (float)(v153 * (float)4096.0)))
                                          * v153)
                                  + w);
            }
            p_x[15] = v116;
            ++v37;
            p_x[16] = v115;
            p_x[18] = textureTMax;
            p_x[17] = textureTMin;
            if ( v37 >= this->numActiveNodes - 1 )
              break;
            v20 = a13;
          }
        }
        if ( this->explicitDefineBothEdges )
          v131 = 2;
        else
          v131 = (_cntlzw((*p_ribbonDecl)->viewOriented) & 0x20) != 0;
        v132 = (beamNodeParms_t *)(*p_ribbonDecl)->material;
        v28[801].num = v131;
        v28[801].list = v132;
      }
    }
  }
  _R0 = -304;
  __asm { lvx128    v127, r1, r0 }
}

