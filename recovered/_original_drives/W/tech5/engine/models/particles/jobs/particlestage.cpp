
// ========================================================================
// ??4idParticleStage@@QAAXABV0@@Z
// EA  : 0x827EA500
// RVA : 0x007EA500
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

void __fastcall idParticleStage::operator=(idParticleStage *this, const idParticleStage *src)
{
  int *p_diversity; // r10
  int *v3; // r9
  int v4; // ctr
  char v5; // r5
  char v6; // r6
  char v7; // r6
  char v8; // r8
  float *p_timeOffset; // r11
  float *v10; // r10
  int v11; // ctr
  prtTextureFlipMode_t *p_textureFlipT; // r11
  prtTextureFlipMode_t *v13; // r10
  int v14; // ctr
  idParticleStage::prtDistribution_t *p_distribution; // r11
  idParticleStage::prtDistribution_t *v16; // r10
  int v17; // ctr
  particleCalcType_t *p_calcType; // r11
  particleCalcType_t *v19; // r10
  int i; // ctr
  particleCalcType_t *v21; // r11
  particleCalcType_t *v22; // r10
  int j; // ctr
  float *p_z; // r11
  float *v25; // r10
  int v26; // ctr
  particleCalcType_t *v27; // r11
  particleCalcType_t *v28; // r10
  int k; // ctr
  particleCalcType_t *v30; // r11
  particleCalcType_t *v31; // r10
  int m; // ctr
  particleCalcType_t *v33; // r11
  particleCalcType_t *v34; // r10
  int n; // ctr
  particleCalcType_t *v36; // r11
  particleCalcType_t *v37; // r10
  int ii; // ctr
  particleCalcType_t *v39; // r11
  particleCalcType_t *v40; // r10
  int jj; // ctr
  bool *p_world; // r11
  bool *v43; // r10
  int kk; // ctr
  bool *v45; // r11
  bool *v46; // r10
  int mm; // ctr
  particleCalcType_t *v48; // r11
  particleCalcType_t *v49; // r10
  int nn; // ctr
  particleCalcType_t *v51; // r11
  particleCalcType_t *v52; // r10
  int i1; // ctr
  particleCalcType_t *v54; // r11
  particleCalcType_t *v55; // r10
  int i2; // ctr
  particleCalcType_t *v57; // r11
  particleCalcType_t *v58; // r10
  int i3; // ctr
  particleCalcType_t *v60; // r11
  particleCalcType_t *v61; // r10
  int i4; // ctr
  particleCalcType_t *v63; // r11
  particleCalcType_t *v64; // r10
  int i5; // ctr
  particleCalcType_t *v66; // r11
  particleCalcType_t *v67; // r10
  int i6; // ctr
  particleCalcType_t *v69; // r11
  particleCalcType_t *v70; // r10
  int i7; // ctr
  particleCalcType_t *v72; // r11
  particleCalcType_t *v73; // r10
  int i8; // ctr
  particleCalcType_t *v75; // r11
  particleCalcType_t *v76; // r10
  int i9; // ctr
  particleCalcType_t *v78; // r11
  particleCalcType_t *v79; // r10
  int i10; // ctr
  particleCalcType_t *v81; // r11
  particleCalcType_t *v82; // r10
  int i11; // ctr
  float *p_softParticleAlphaScale; // r11
  float *v85; // r10
  int v86; // ctr
  float *p_entityColorBlendVal; // r11
  float *v88; // r10
  int v89; // ctr
  particleCalcType_t *v90; // r11
  particleCalcType_t *v91; // r10
  int i12; // ctr
  particleCalcType_t *v93; // r11
  particleCalcType_t *v94; // r10
  int i13; // ctr
  bool *p_allowRotDirOverride; // r11
  bool *v97; // r10
  int i14; // ctr
  particleCalcType_t *v99; // r11
  particleCalcType_t *v100; // r10
  int i15; // ctr
  particleCalcType_t *v102; // r11
  particleCalcType_t *v103; // r10
  int i16; // ctr
  float *p_y; // r11
  float *v106; // r10
  int i17; // ctr
  particleCalcType_t *v108; // r11
  particleCalcType_t *v109; // r10
  int i18; // ctr
  particleCalcType_t *v111; // r11
  particleCalcType_t *v112; // r10
  int i19; // ctr
  particleCalcType_t *v114; // r11
  particleCalcType_t *v115; // r10
  int i20; // ctr
  unsigned __int16 *p_numColumns; // r11
  unsigned __int16 *v118; // r10
  int v119; // ctr
  idParticleStage::prtCustomPath_t *p_customPath; // r11
  idParticleStage::prtCustomPath_t *v121; // r10
  int v122; // ctr
  particleCalcType_t *v123; // r11
  particleCalcType_t *v124; // r10
  int i21; // ctr
  particleCalcType_t *v126; // r11
  particleCalcType_t *v127; // r10
  int i22; // ctr
  particleCalcType_t *v129; // r11
  particleCalcType_t *v130; // r10
  int i23; // ctr
  particleCalcType_t *v132; // r11
  particleCalcType_t *v133; // r10
  int i24; // ctr
  particleCalcType_t *v135; // r11
  particleCalcType_t *v136; // r10
  int i25; // ctr
  particleCalcType_t *v138; // r11
  particleCalcType_t *v139; // r10
  int i26; // ctr
  particleCalcType_t *v141; // r11
  particleCalcType_t *v142; // r10
  int i27; // ctr
  particleCalcType_t *v144; // r11
  particleCalcType_t *v145; // r10
  int i28; // ctr

  p_diversity = &src->systemProperties.diversity;
  v3 = &this->systemProperties.diversity;
  *((_BYTE *)this + 68) = *((_BYTE *)src + 68) & 8 | *((_BYTE *)this + 68) & 0xF7;
  v4 = 5;
  this->systemProperties.material = src->systemProperties.material;
  this->atlasScaleBias = src->atlasScaleBias;
  v5 = *((_BYTE *)this + 68) & 0x7F | *((_BYTE *)src + 68) & 0x80;
  *((_BYTE *)this + 68) = v5;
  v6 = *((_BYTE *)src + 68) & 0x40 | v5 & 0xBF;
  *((_BYTE *)this + 68) = v6;
  v7 = *((_BYTE *)src + 68) & 0x20 | v6 & 0xDF;
  *((_BYTE *)this + 68) = v7;
  v8 = *((_BYTE *)src + 68) & 0x10 | v7 & 0xEF;
  this->staticData = nullptr;
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
  *((_BYTE *)this + 68) = v8;
  this->systemProperties.totalParticles = src->systemProperties.totalParticles;
  this->systemProperties.diversity = src->systemProperties.diversity;
  this->systemProperties.cycles = src->systemProperties.cycles;
  this->cycleMsec = src->cycleMsec;
  this->bunchTime = src->bunchTime;
  do
  {
    *++v3 = *++p_diversity;
    --v4;
  }
  while ( v4 != 0 );
  this->maxParticleLife = src->maxParticleLife;
  p_timeOffset = &src->systemProperties.timeOffset;
  v10 = &this->systemProperties.timeOffset;
  this->maxDeadTime = src->maxDeadTime;
  v11 = 5;
  this->systemProperties.timeOffset = src->systemProperties.timeOffset;
  do
  {
    *++v10 = *++p_timeOffset;
    --v11;
  }
  while ( v11 != 0 );
  this->systemProperties.useSysTime = src->systemProperties.useSysTime;
  p_textureFlipT = &src->systemProperties.textureFlipT;
  v13 = &this->systemProperties.textureFlipT;
  this->systemProperties.spawnBunching = src->systemProperties.spawnBunching;
  v14 = 5;
  this->systemProperties.emissionTime = src->systemProperties.emissionTime;
  this->systemProperties.textureFlipS = src->systemProperties.textureFlipS;
  this->systemProperties.textureFlipT = src->systemProperties.textureFlipT;
  do
  {
    *++v13 = *++p_textureFlipT;
    --v14;
  }
  while ( v14 != 0 );
  p_distribution = &src->distribution;
  v16 = &this->distribution;
  this->systemProperties.sortType = src->systemProperties.sortType;
  v17 = 5;
  this->systemProperties.boundsExpansion = src->systemProperties.boundsExpansion;
  this->systemProperties.randomOnCycle = src->systemProperties.randomOnCycle;
  this->bounds = src->bounds;
  this->distribution.type = src->distribution.type;
  do
  {
    p_distribution = (idParticleStage::prtDistribution_t *)((char *)p_distribution + 4);
    v16 = (idParticleStage::prtDistribution_t *)((char *)v16 + 4);
    v16->type = p_distribution->type;
    --v17;
  }
  while ( v17 != 0 );
  p_calcType = &src->distribution.size[0].calcType;
  v19 = &this->distribution.size[0].calcType;
  for ( i = 5; i != 0; --i )
    *++v19 = *++p_calcType;
  v21 = &src->distribution.size[1].calcType;
  v22 = &this->distribution.size[1].calcType;
  for ( j = 5; j != 0; --j )
    *++v22 = *++v21;
  p_z = &src->direction.coneAxis.mat[2].z;
  v25 = &this->direction.coneAxis.mat[2].z;
  this->distribution.random = src->distribution.random;
  v26 = 5;
  this->orientation = src->orientation;
  this->direction = src->direction;
  do
  {
    *++v25 = *++p_z;
    --v26;
  }
  while ( v26 != 0 );
  v27 = &src->speed.speed[0].calcType;
  v28 = &this->speed.speed[0].calcType;
  for ( k = 5; k != 0; --k )
    *++v28 = *++v27;
  v30 = &src->speed.speed[1].calcType;
  v31 = &this->speed.speed[1].calcType;
  for ( m = 5; m != 0; --m )
    *++v31 = *++v30;
  v33 = &src->speed.speed[2].calcType;
  v34 = &this->speed.speed[2].calcType;
  for ( n = 5; n != 0; --n )
    *++v34 = *++v33;
  v36 = &src->acceleration.acceleration[0].calcType;
  v37 = &this->acceleration.acceleration[0].calcType;
  for ( ii = 5; ii != 0; --ii )
    *++v37 = *++v36;
  v39 = &src->acceleration.acceleration[1].calcType;
  v40 = &this->acceleration.acceleration[1].calcType;
  for ( jj = 5; jj != 0; --jj )
    *++v40 = *++v39;
  p_world = &src->acceleration.world;
  v43 = &this->acceleration.world;
  this->acceleration.world = src->acceleration.world;
  for ( kk = 5; kk != 0; --kk )
  {
    p_world += 4;
    v43 += 4;
    *(_DWORD *)v43 = *(_DWORD *)p_world;
  }
  v45 = &src->gravity.world;
  v46 = &this->gravity.world;
  this->gravity.world = src->gravity.world;
  for ( mm = 5; mm != 0; --mm )
  {
    v45 += 4;
    v46 += 4;
    *(_DWORD *)v46 = *(_DWORD *)v45;
  }
  v48 = &src->friction.friction[0].calcType;
  v49 = &this->friction.friction[0].calcType;
  for ( nn = 5; nn != 0; --nn )
    *++v49 = *++v48;
  v51 = &src->friction.friction[1].calcType;
  v52 = &this->friction.friction[1].calcType;
  for ( i1 = 5; i1 != 0; --i1 )
    *++v52 = *++v51;
  v54 = &src->friction.friction[2].calcType;
  v55 = &this->friction.friction[2].calcType;
  for ( i2 = 5; i2 != 0; --i2 )
    *++v55 = *++v54;
  v57 = &src->offset.offset[0].calcType;
  v58 = &this->offset.offset[0].calcType;
  for ( i3 = 5; i3 != 0; --i3 )
    *++v58 = *++v57;
  v60 = &src->offset.offset[1].calcType;
  v61 = &this->offset.offset[1].calcType;
  for ( i4 = 5; i4 != 0; --i4 )
    *++v61 = *++v60;
  v63 = &src->offset.offset[2].calcType;
  v64 = &this->offset.offset[2].calcType;
  for ( i5 = 5; i5 != 0; --i5 )
    *++v64 = *++v63;
  v66 = &src->spawnLocation.spawnLocation[0].calcType;
  v67 = &this->spawnLocation.spawnLocation[0].calcType;
  for ( i6 = 5; i6 != 0; --i6 )
    *++v67 = *++v66;
  v69 = &src->spawnLocation.spawnLocation[1].calcType;
  v70 = &this->spawnLocation.spawnLocation[1].calcType;
  for ( i7 = 5; i7 != 0; --i7 )
    *++v70 = *++v69;
  v72 = &src->spawnLocation.spawnLocation[2].calcType;
  v73 = &this->spawnLocation.spawnLocation[2].calcType;
  for ( i8 = 5; i8 != 0; --i8 )
    *++v73 = *++v72;
  v75 = &src->colorAttributes.baseColor[0].calcType;
  v76 = &this->colorAttributes.baseColor[0].calcType;
  for ( i9 = 5; i9 != 0; --i9 )
    *++v76 = *++v75;
  v78 = &src->colorAttributes.baseColor[1].calcType;
  v79 = &this->colorAttributes.baseColor[1].calcType;
  for ( i10 = 5; i10 != 0; --i10 )
    *++v79 = *++v78;
  v81 = &src->colorAttributes.baseColor[2].calcType;
  v82 = &this->colorAttributes.baseColor[2].calcType;
  for ( i11 = 5; i11 != 0; --i11 )
    *++v82 = *++v81;
  this->colorAttributes.fadeColor = src->colorAttributes.fadeColor;
  p_softParticleAlphaScale = &src->colorAttributes.softParticleAlphaScale;
  v85 = &this->colorAttributes.softParticleAlphaScale;
  v86 = 5;
  this->colorAttributes.fadeInFraction = src->colorAttributes.fadeInFraction;
  this->colorAttributes.fadeOutFraction = src->colorAttributes.fadeOutFraction;
  this->colorAttributes.fadeIndexFraction = src->colorAttributes.fadeIndexFraction;
  this->colorAttributes.softParticleAlphaScale = src->colorAttributes.softParticleAlphaScale;
  do
  {
    *++v85 = *++p_softParticleAlphaScale;
    --v86;
  }
  while ( v86 != 0 );
  p_entityColorBlendVal = &src->colorAttributes.entityColorBlendVal;
  v88 = &this->colorAttributes.entityColorBlendVal;
  this->colorAttributes.useGlobalShadows = src->colorAttributes.useGlobalShadows;
  v89 = 5;
  this->colorAttributes.minShadowVal = src->colorAttributes.minShadowVal;
  this->colorAttributes.entityColorBlendVal = src->colorAttributes.entityColorBlendVal;
  do
  {
    *++v88 = *++p_entityColorBlendVal;
    --v89;
  }
  while ( v89 != 0 );
  v90 = &src->rotation.rotation[0].calcType;
  v91 = &this->rotation.rotation[0].calcType;
  for ( i12 = 5; i12 != 0; --i12 )
    *++v91 = *++v90;
  v93 = &src->rotation.rotation[1].calcType;
  v94 = &this->rotation.rotation[1].calcType;
  for ( i13 = 5; i13 != 0; --i13 )
    *++v94 = *++v93;
  p_allowRotDirOverride = &src->rotation.allowRotDirOverride;
  v97 = &this->rotation.allowRotDirOverride;
  this->rotation.allowRotDirOverride = src->rotation.allowRotDirOverride;
  for ( i14 = 5; i14 != 0; --i14 )
  {
    p_allowRotDirOverride += 4;
    v97 += 4;
    *(_DWORD *)v97 = *(_DWORD *)p_allowRotDirOverride;
  }
  v99 = &src->initialRotation.initialAngle[0].calcType;
  v100 = &this->initialRotation.initialAngle[0].calcType;
  for ( i15 = 5; i15 != 0; --i15 )
    *++v100 = *++v99;
  v102 = &src->initialRotation.initialAngle[1].calcType;
  v103 = &this->initialRotation.initialAngle[1].calcType;
  for ( i16 = 5; i16 != 0; --i16 )
    *++v103 = *++v102;
  this->pivot = src->pivot;
  p_y = &src->pivot.pivotOffset.y;
  v106 = &this->pivot.pivotOffset.y;
  for ( i17 = 5; i17 != 0; --i17 )
    *++v106 = *++p_y;
  v108 = &src->size.size[0].calcType;
  v109 = &this->size.size[0].calcType;
  for ( i18 = 5; i18 != 0; --i18 )
    *++v109 = *++v108;
  v111 = &src->size.size[1].calcType;
  v112 = &this->size.size[1].calcType;
  for ( i19 = 5; i19 != 0; --i19 )
    *++v112 = *++v111;
  v114 = &src->size.size[2].calcType;
  v115 = &this->size.size[2].calcType;
  for ( i20 = 5; i20 != 0; --i20 )
    *++v115 = *++v114;
  p_numColumns = &src->texAnimation.numColumns;
  v118 = &this->texAnimation.numColumns;
  this->texAnimation.type = src->texAnimation.type;
  v119 = 5;
  this->texAnimation.numRows = src->texAnimation.numRows;
  this->texAnimation.numColumns = src->texAnimation.numColumns;
  do
  {
    p_numColumns += 2;
    v118 += 2;
    *(_DWORD *)v118 = *(_DWORD *)p_numColumns;
    --v119;
  }
  while ( v119 != 0 );
  p_customPath = &src->customPath;
  v121 = &this->customPath;
  this->texAnimation.startFrame = src->texAnimation.startFrame;
  v122 = 5;
  this->texAnimation.useRandomRow = src->texAnimation.useRandomRow;
  this->texAnimation.useFrameBlending = src->texAnimation.useFrameBlending;
  this->customPath.type = src->customPath.type;
  do
  {
    p_customPath = (idParticleStage::prtCustomPath_t *)((char *)p_customPath + 4);
    v121 = (idParticleStage::prtCustomPath_t *)((char *)v121 + 4);
    v121->type = p_customPath->type;
    --v122;
  }
  while ( v122 != 0 );
  v123 = &src->customPath.parms[0].calcType;
  v124 = &this->customPath.parms[0].calcType;
  for ( i21 = 5; i21 != 0; --i21 )
    *++v124 = *++v123;
  v126 = &src->customPath.parms[1].calcType;
  v127 = &this->customPath.parms[1].calcType;
  for ( i22 = 5; i22 != 0; --i22 )
    *++v127 = *++v126;
  v129 = &src->customPath.parms[2].calcType;
  v130 = &this->customPath.parms[2].calcType;
  for ( i23 = 5; i23 != 0; --i23 )
    *++v130 = *++v129;
  v132 = &src->customPath.parms[3].calcType;
  v133 = &this->customPath.parms[3].calcType;
  for ( i24 = 5; i24 != 0; --i24 )
    *++v133 = *++v132;
  v135 = &src->customPath.parms[4].calcType;
  v136 = &this->customPath.parms[4].calcType;
  for ( i25 = 5; i25 != 0; --i25 )
    *++v136 = *++v135;
  v138 = &src->genericParm.genericParm[0].calcType;
  v139 = &this->genericParm.genericParm[0].calcType;
  for ( i26 = 5; i26 != 0; --i26 )
    *++v139 = *++v138;
  v141 = &src->genericParm.genericParm[1].calcType;
  v142 = &this->genericParm.genericParm[1].calcType;
  for ( i27 = 5; i27 != 0; --i27 )
    *++v142 = *++v141;
  v144 = &src->genericParm.genericParm[2].calcType;
  v145 = &this->genericParm.genericParm[2].calcType;
  for ( i28 = 5; i28 != 0; --i28 )
    *++v145 = *++v144;
  this->lodParms = src->lodParms;
}


// ========================================================================
// ?SetMaterial@idParticleStage@@QAAXPBVidMaterial@@@Z
// EA  : 0x827EAD30
// RVA : 0x007EAD30
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

void __fastcall idParticleStage::SetMaterial(idParticleStage *this, const idMaterial *mtr)
{
  char v2; // r7
  char v3; // r7
  char v4; // r9
  const idDeclRenderProg *v5; // r11

  this->systemProperties.material = mtr;
  if ( mtr != nullptr )
  {
    this->atlasScaleBias = mtr->atlasScaleBias;
    v2 = (8 * *((_BYTE *)mtr + 72)) & 0x40 | *((_BYTE *)this + 68) & 0xBF;
    *((_BYTE *)this + 68) = v2;
    v3 = (8 * *((_BYTE *)mtr + 72)) & 0x20 | v2 & 0xDF;
    *((_BYTE *)this + 68) = v3;
    v4 = (16 * (mtr->progs[4] != nullptr)) & 0x10 | v3 & 0xEF;
    *((_BYTE *)this + 68) = v4;
    v5 = mtr->progs[6];
    if ( (v4 & 0x40) != 0 )
    {
      *((_BYTE *)this + 68) = v4 | 0x80;
    }
    else if ( v5 != nullptr )
    {
      *((_BYTE *)this + 68) = (((v5->glState & 0x38) != 8) << 7) | *((_BYTE *)this + 68) & 0x7F;
    }
  }
}


// ========================================================================
// ?SetStaticMesh@idParticleStage@@QAAXPBVidStaticParticleModelData@@@Z
// EA  : 0x827EADE8
// RVA : 0x007EADE8
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

void __fastcall idParticleStage::SetStaticMesh(idParticleStage *this, const idStaticParticleModelData *_staticData)
{
  this->staticData = _staticData;
  if ( _staticData != nullptr )
  {
    this->numStaticVerts = _staticData->numStaticVerts;
    this->staticVerts = _staticData->staticVerts;
  }
}


// ========================================================================
// ??0idParticleStage@@QAA@XZ
// EA  : 0x827EAE08
// RVA : 0x007EAE08
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

idParticleStage *__fastcall idParticleStage::idParticleStage(idParticleStage *this)
{
  float *v1; // r31
  int v2; // ctr

  this->staticData = nullptr;
  this->staticVerts = nullptr;
  this->maxParticleLife = 0.0;
  this->numStaticVerts = 0;
  this->maxDeadTime = 0.0;
  this->cycleMsec = 0;
  this->bunchTime = 0.0;
  this->atlasScaleBias.z = 0.0;
  this->atlasScaleBias.w = 0.0;
  this->atlasScaleBias.x = 1.0;
  this->atlasScaleBias.y = 1.0;
  *((_BYTE *)this + 68) &= 7u;
  this->systemProperties.particleLife.val0 = 0.0;
  this->systemProperties.particleLife.val1 = 0.0;
  this->systemProperties.particleLife.tableIdx = -1;
  this->systemProperties.particleLife.variance = 0.0;
  this->systemProperties.particleLife.table2Idx = -1;
  this->systemProperties.particleLife.calcType = PARTICLE_CALC_NONE;
  this->systemProperties.deadTime.val0 = 0.0;
  this->systemProperties.deadTime.val1 = 0.0;
  this->systemProperties.deadTime.tableIdx = -1;
  this->systemProperties.deadTime.variance = 0.0;
  this->systemProperties.deadTime.table2Idx = -1;
  this->systemProperties.deadTime.calcType = PARTICLE_CALC_NONE;
  this->systemProperties.windBias.val0 = 0.0;
  this->systemProperties.windBias.val1 = 0.0;
  this->systemProperties.windBias.tableIdx = -1;
  this->systemProperties.windBias.variance = 0.0;
  this->systemProperties.windBias.table2Idx = -1;
  this->systemProperties.windBias.calcType = PARTICLE_CALC_NONE;
  this->distribution.size[0].val0 = 0.0;
  this->distribution.size[0].val1 = 0.0;
  this->distribution.size[0].tableIdx = -1;
  this->distribution.size[0].variance = 0.0;
  this->distribution.size[0].table2Idx = -1;
  this->distribution.size[1].val0 = 0.0;
  this->distribution.size[0].calcType = PARTICLE_CALC_NONE;
  this->distribution.size[1].val1 = 0.0;
  this->distribution.size[1].tableIdx = -1;
  this->distribution.size[1].variance = 0.0;
  this->distribution.size[1].table2Idx = -1;
  this->distribution.size[2].val0 = 0.0;
  this->distribution.size[1].calcType = PARTICLE_CALC_NONE;
  this->distribution.size[2].val1 = 0.0;
  this->distribution.size[2].tableIdx = -1;
  this->distribution.size[2].variance = 0.0;
  this->distribution.size[2].table2Idx = -1;
  this->distribution.size[2].calcType = PARTICLE_CALC_NONE;
  this->speed.speed[0].val0 = 0.0;
  this->speed.speed[0].val1 = 0.0;
  this->speed.speed[0].tableIdx = -1;
  this->speed.speed[0].variance = 0.0;
  this->speed.speed[0].table2Idx = -1;
  this->speed.speed[1].val0 = 0.0;
  this->speed.speed[0].calcType = PARTICLE_CALC_NONE;
  this->speed.speed[1].val1 = 0.0;
  this->speed.speed[1].tableIdx = -1;
  this->speed.speed[1].variance = 0.0;
  this->speed.speed[1].table2Idx = -1;
  this->speed.speed[2].val0 = 0.0;
  this->speed.speed[1].calcType = PARTICLE_CALC_NONE;
  this->speed.speed[2].val1 = 0.0;
  this->speed.speed[2].tableIdx = -1;
  this->speed.speed[2].variance = 0.0;
  this->speed.speed[2].table2Idx = -1;
  this->speed.speed[2].calcType = PARTICLE_CALC_NONE;
  this->acceleration.acceleration[0].val0 = 0.0;
  this->acceleration.acceleration[0].val1 = 0.0;
  this->acceleration.acceleration[0].tableIdx = -1;
  this->acceleration.acceleration[0].variance = 0.0;
  this->acceleration.acceleration[0].table2Idx = -1;
  this->acceleration.acceleration[1].val0 = 0.0;
  this->acceleration.acceleration[0].calcType = PARTICLE_CALC_NONE;
  this->acceleration.acceleration[1].val1 = 0.0;
  this->acceleration.acceleration[1].tableIdx = -1;
  this->acceleration.acceleration[1].variance = 0.0;
  this->acceleration.acceleration[1].table2Idx = -1;
  this->acceleration.acceleration[2].val0 = 0.0;
  this->acceleration.acceleration[1].calcType = PARTICLE_CALC_NONE;
  this->acceleration.acceleration[2].val1 = 0.0;
  this->acceleration.acceleration[2].tableIdx = -1;
  this->acceleration.acceleration[2].variance = 0.0;
  this->acceleration.acceleration[2].table2Idx = -1;
  this->acceleration.acceleration[2].calcType = PARTICLE_CALC_NONE;
  this->gravity.gravity.val0 = 0.0;
  this->gravity.gravity.val1 = 0.0;
  this->gravity.gravity.tableIdx = -1;
  this->gravity.gravity.variance = 0.0;
  this->gravity.gravity.table2Idx = -1;
  this->gravity.gravity.calcType = PARTICLE_CALC_NONE;
  this->friction.friction[0].val0 = 0.0;
  this->friction.friction[0].val1 = 0.0;
  this->friction.friction[0].tableIdx = -1;
  this->friction.friction[0].variance = 0.0;
  this->friction.friction[0].table2Idx = -1;
  this->friction.friction[1].val0 = 0.0;
  this->friction.friction[0].calcType = PARTICLE_CALC_NONE;
  this->friction.friction[1].val1 = 0.0;
  this->friction.friction[1].tableIdx = -1;
  this->friction.friction[1].variance = 0.0;
  this->friction.friction[1].table2Idx = -1;
  this->friction.friction[2].val0 = 0.0;
  this->friction.friction[1].calcType = PARTICLE_CALC_NONE;
  this->friction.friction[2].val1 = 0.0;
  this->friction.friction[2].tableIdx = -1;
  this->friction.friction[2].variance = 0.0;
  this->friction.friction[2].table2Idx = -1;
  this->friction.friction[2].calcType = PARTICLE_CALC_NONE;
  this->offset.offset[0].val0 = 0.0;
  this->offset.offset[0].val1 = 0.0;
  this->offset.offset[0].tableIdx = -1;
  this->offset.offset[0].variance = 0.0;
  this->offset.offset[0].table2Idx = -1;
  this->offset.offset[1].val0 = 0.0;
  this->offset.offset[0].calcType = PARTICLE_CALC_NONE;
  this->offset.offset[1].val1 = 0.0;
  this->offset.offset[1].tableIdx = -1;
  this->offset.offset[1].variance = 0.0;
  this->offset.offset[1].table2Idx = -1;
  this->offset.offset[2].val0 = 0.0;
  this->offset.offset[1].calcType = PARTICLE_CALC_NONE;
  this->offset.offset[2].val1 = 0.0;
  this->offset.offset[2].tableIdx = -1;
  this->offset.offset[2].variance = 0.0;
  this->offset.offset[2].table2Idx = -1;
  this->offset.offset[2].calcType = PARTICLE_CALC_NONE;
  this->spawnLocation.spawnLocation[0].val0 = 0.0;
  this->spawnLocation.spawnLocation[0].val1 = 0.0;
  this->spawnLocation.spawnLocation[0].tableIdx = -1;
  this->spawnLocation.spawnLocation[0].variance = 0.0;
  this->spawnLocation.spawnLocation[0].table2Idx = -1;
  this->spawnLocation.spawnLocation[1].val0 = 0.0;
  this->spawnLocation.spawnLocation[0].calcType = PARTICLE_CALC_NONE;
  this->spawnLocation.spawnLocation[1].val1 = 0.0;
  this->spawnLocation.spawnLocation[1].tableIdx = -1;
  this->spawnLocation.spawnLocation[1].variance = 0.0;
  this->spawnLocation.spawnLocation[1].table2Idx = -1;
  this->spawnLocation.spawnLocation[2].val0 = 0.0;
  this->spawnLocation.spawnLocation[1].calcType = PARTICLE_CALC_NONE;
  this->spawnLocation.spawnLocation[2].val1 = 0.0;
  this->spawnLocation.spawnLocation[2].tableIdx = -1;
  this->spawnLocation.spawnLocation[2].variance = 0.0;
  this->spawnLocation.spawnLocation[2].table2Idx = -1;
  this->spawnLocation.spawnLocation[2].calcType = PARTICLE_CALC_NONE;
  this->colorAttributes.baseColor[0].val0 = 0.0;
  this->colorAttributes.baseColor[0].val1 = 0.0;
  this->colorAttributes.baseColor[0].tableIdx = -1;
  this->colorAttributes.baseColor[0].variance = 0.0;
  this->colorAttributes.baseColor[0].table2Idx = -1;
  this->colorAttributes.baseColor[1].val0 = 0.0;
  this->colorAttributes.baseColor[1].val1 = 0.0;
  this->colorAttributes.baseColor[0].calcType = PARTICLE_CALC_NONE;
  this->colorAttributes.baseColor[1].variance = 0.0;
  this->colorAttributes.baseColor[1].tableIdx = -1;
  this->colorAttributes.baseColor[2].val0 = 0.0;
  this->colorAttributes.baseColor[1].table2Idx = -1;
  this->colorAttributes.baseColor[2].val1 = 0.0;
  this->colorAttributes.baseColor[1].calcType = PARTICLE_CALC_NONE;
  this->colorAttributes.baseColor[2].variance = 0.0;
  this->colorAttributes.baseColor[2].tableIdx = -1;
  this->colorAttributes.baseColor[3].val0 = 0.0;
  this->colorAttributes.baseColor[2].table2Idx = -1;
  this->colorAttributes.baseColor[3].val1 = 0.0;
  this->colorAttributes.baseColor[2].calcType = PARTICLE_CALC_NONE;
  this->colorAttributes.baseColor[3].variance = 0.0;
  this->colorAttributes.baseColor[3].tableIdx = -1;
  this->colorAttributes.baseColor[3].table2Idx = -1;
  this->colorAttributes.baseColor[3].calcType = PARTICLE_CALC_NONE;
  this->colorAttributes.brightness.val0 = 0.0;
  this->colorAttributes.brightness.val1 = 0.0;
  this->colorAttributes.brightness.tableIdx = -1;
  this->colorAttributes.brightness.variance = 0.0;
  this->colorAttributes.brightness.table2Idx = -1;
  this->colorAttributes.brightness.calcType = PARTICLE_CALC_NONE;
  this->rotation.rotation[0].val0 = 0.0;
  this->rotation.rotation[0].val1 = 0.0;
  this->rotation.rotation[0].tableIdx = -1;
  this->rotation.rotation[0].variance = 0.0;
  this->rotation.rotation[0].table2Idx = -1;
  this->rotation.rotation[1].val0 = 0.0;
  this->rotation.rotation[0].calcType = PARTICLE_CALC_NONE;
  this->rotation.rotation[1].val1 = 0.0;
  this->rotation.rotation[1].tableIdx = -1;
  this->rotation.rotation[1].variance = 0.0;
  this->rotation.rotation[1].table2Idx = -1;
  this->rotation.rotation[2].val0 = 0.0;
  this->rotation.rotation[1].calcType = PARTICLE_CALC_NONE;
  this->rotation.rotation[2].val1 = 0.0;
  this->rotation.rotation[2].tableIdx = -1;
  this->rotation.rotation[2].variance = 0.0;
  this->rotation.rotation[2].table2Idx = -1;
  this->rotation.rotation[2].calcType = PARTICLE_CALC_NONE;
  this->initialRotation.initialAngle[0].val0 = 0.0;
  this->initialRotation.initialAngle[0].val1 = 0.0;
  this->initialRotation.initialAngle[0].tableIdx = -1;
  this->initialRotation.initialAngle[0].variance = 0.0;
  this->initialRotation.initialAngle[0].table2Idx = -1;
  this->initialRotation.initialAngle[1].val0 = 0.0;
  this->initialRotation.initialAngle[0].calcType = PARTICLE_CALC_NONE;
  this->initialRotation.initialAngle[1].val1 = 0.0;
  this->initialRotation.initialAngle[1].tableIdx = -1;
  this->initialRotation.initialAngle[1].variance = 0.0;
  this->initialRotation.initialAngle[1].table2Idx = -1;
  this->initialRotation.initialAngle[2].val0 = 0.0;
  this->initialRotation.initialAngle[1].calcType = PARTICLE_CALC_NONE;
  this->initialRotation.initialAngle[2].val1 = 0.0;
  this->initialRotation.initialAngle[2].tableIdx = -1;
  this->initialRotation.initialAngle[2].variance = 0.0;
  this->initialRotation.initialAngle[2].table2Idx = -1;
  this->initialRotation.initialAngle[2].calcType = PARTICLE_CALC_NONE;
  this->size.size[0].val0 = 0.0;
  this->size.size[0].val1 = 0.0;
  this->size.size[0].tableIdx = -1;
  this->size.size[0].variance = 0.0;
  this->size.size[0].table2Idx = -1;
  this->size.size[1].val0 = 0.0;
  this->size.size[0].calcType = PARTICLE_CALC_NONE;
  this->size.size[1].val1 = 0.0;
  this->size.size[1].tableIdx = -1;
  this->size.size[1].variance = 0.0;
  this->size.size[1].table2Idx = -1;
  this->size.size[2].val0 = 0.0;
  this->size.size[1].calcType = PARTICLE_CALC_NONE;
  this->size.size[2].val1 = 0.0;
  this->size.size[2].tableIdx = -1;
  this->size.size[2].variance = 0.0;
  this->size.size[2].table2Idx = -1;
  this->size.size[2].calcType = PARTICLE_CALC_NONE;
  this->size.aspectRatio.val0 = 0.0;
  this->size.aspectRatio.val1 = 0.0;
  this->size.aspectRatio.tableIdx = -1;
  this->size.aspectRatio.variance = 0.0;
  this->size.aspectRatio.table2Idx = -1;
  this->size.aspectRatio.calcType = PARTICLE_CALC_NONE;
  this->texAnimation.rate.val0 = 0.0;
  this->texAnimation.rate.val1 = 0.0;
  this->texAnimation.rate.tableIdx = -1;
  this->texAnimation.rate.variance = 0.0;
  this->texAnimation.rate.table2Idx = -1;
  this->texAnimation.rate.calcType = PARTICLE_CALC_NONE;
  this->customPath.parms[0].val0 = 0.0;
  this->customPath.parms[0].val1 = 0.0;
  this->customPath.parms[0].tableIdx = -1;
  this->customPath.parms[0].variance = 0.0;
  this->customPath.parms[0].table2Idx = -1;
  this->customPath.parms[1].val0 = 0.0;
  this->customPath.parms[0].calcType = PARTICLE_CALC_NONE;
  this->customPath.parms[1].val1 = 0.0;
  this->customPath.parms[1].tableIdx = -1;
  this->customPath.parms[1].variance = 0.0;
  this->customPath.parms[1].table2Idx = -1;
  this->customPath.parms[2].val0 = 0.0;
  this->customPath.parms[1].calcType = PARTICLE_CALC_NONE;
  this->customPath.parms[2].val1 = 0.0;
  this->customPath.parms[2].tableIdx = -1;
  this->customPath.parms[2].variance = 0.0;
  this->customPath.parms[2].table2Idx = -1;
  this->customPath.parms[3].val0 = 0.0;
  this->customPath.parms[2].calcType = PARTICLE_CALC_NONE;
  this->customPath.parms[3].val1 = 0.0;
  this->customPath.parms[3].tableIdx = -1;
  this->customPath.parms[3].variance = 0.0;
  this->customPath.parms[3].table2Idx = -1;
  this->customPath.parms[4].val0 = 0.0;
  this->customPath.parms[3].calcType = PARTICLE_CALC_NONE;
  this->customPath.parms[4].val1 = 0.0;
  this->customPath.parms[4].tableIdx = -1;
  this->customPath.parms[4].variance = 0.0;
  this->customPath.parms[4].table2Idx = -1;
  this->customPath.parms[4].calcType = PARTICLE_CALC_NONE;
  this->genericParm.genericParm[0].val0 = 0.0;
  this->genericParm.genericParm[0].val1 = 0.0;
  this->genericParm.genericParm[0].tableIdx = -1;
  this->genericParm.genericParm[0].variance = 0.0;
  this->genericParm.genericParm[0].table2Idx = -1;
  this->genericParm.genericParm[1].val0 = 0.0;
  this->genericParm.genericParm[0].calcType = PARTICLE_CALC_NONE;
  this->genericParm.genericParm[1].val1 = 0.0;
  this->genericParm.genericParm[1].tableIdx = -1;
  this->genericParm.genericParm[1].variance = 0.0;
  this->genericParm.genericParm[1].table2Idx = -1;
  this->genericParm.genericParm[2].val0 = 0.0;
  this->genericParm.genericParm[1].calcType = PARTICLE_CALC_NONE;
  this->genericParm.genericParm[2].val1 = 0.0;
  this->genericParm.genericParm[2].tableIdx = -1;
  this->genericParm.genericParm[2].variance = 0.0;
  this->genericParm.genericParm[2].table2Idx = -1;
  this->genericParm.genericParm[3].val0 = 0.0;
  this->genericParm.genericParm[2].calcType = PARTICLE_CALC_NONE;
  this->genericParm.genericParm[3].val1 = 0.0;
  this->genericParm.genericParm[3].tableIdx = -1;
  this->genericParm.genericParm[3].variance = 0.0;
  this->genericParm.genericParm[3].table2Idx = -1;
  this->genericParm.genericParm[3].calcType = PARTICLE_CALC_NONE;
  this->systemProperties.material = nullptr;
  this->systemProperties.particleLife.val0 = 0.0;
  this->systemProperties.particleLife.val1 = 0.0;
  this->systemProperties.particleLife.tableIdx = -1;
  this->systemProperties.particleLife.variance = 0.0;
  this->systemProperties.particleLife.table2Idx = -1;
  this->systemProperties.deadTime.val0 = 0.0;
  this->systemProperties.deadTime.tableIdx = -1;
  this->systemProperties.deadTime.val1 = 0.0;
  this->systemProperties.deadTime.table2Idx = -1;
  this->systemProperties.deadTime.variance = 0.0;
  this->systemProperties.timeOffset = 0.0;
  this->systemProperties.useSysTime = 0.0;
  this->systemProperties.spawnBunching = 0.0;
  this->systemProperties.emissionTime = 0.0;
  this->systemProperties.totalParticles = 0;
  this->systemProperties.boundsExpansion = 0.0;
  this->systemProperties.diversity = 0;
  this->systemProperties.cycles = 0;
  this->systemProperties.textureFlipT = PTEXTURE_FLIP_NONE;
  this->systemProperties.sortType = PSORT_TYPE_NONE;
  this->systemProperties.randomOnCycle = true;
  this->systemProperties.textureFlipS = PTEXTURE_FLIP_NONE;
  this->systemProperties.windBias.val0 = 0.0;
  this->systemProperties.windBias.val1 = 0.0;
  this->systemProperties.windBias.tableIdx = -1;
  this->systemProperties.windBias.variance = 0.0;
  this->systemProperties.windBias.table2Idx = -1;
  this->bounds.b[0].z = 1.0e30;
  v1 = &this->direction.angleOffsetStart[1];
  v2 = 2;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  this->distribution.type = PDIST_RECT;
  this->distribution.size[0].val0 = 0.0;
  this->distribution.size[0].tableIdx = -1;
  this->distribution.size[0].val1 = 0.0;
  this->distribution.size[0].table2Idx = -1;
  this->distribution.size[0].variance = 0.0;
  this->distribution.size[1].tableIdx = -1;
  this->distribution.size[1].val0 = 0.0;
  this->distribution.size[1].table2Idx = -1;
  this->distribution.size[1].val1 = 0.0;
  this->distribution.size[1].variance = 0.0;
  this->distribution.size[2].tableIdx = -1;
  this->distribution.size[2].val0 = 0.0;
  this->distribution.size[2].table2Idx = -1;
  this->distribution.size[2].val1 = 0.0;
  this->distribution.size[2].variance = 0.0;
  this->distribution.random = true;
  this->orientation.segmentLength = 0.0;
  this->orientation.type = POR_VIEW;
  this->orientation.viewFade = 1.0;
  this->orientation.numTrails = 0;
  this->orientation.aimedSafeQuadAlign = 1.0;
  this->orientation.orientToVelOnly = false;
  this->orientation.depthOffset = 0.0;
  this->orientation.world = false;
  this->orientation.aimedSafeQuad = false;
  this->direction.type = PDIR_CONE;
  this->direction.parms[0] = 0.0;
  this->direction.parms[1] = 0.0;
  this->direction.parms[2] = 0.0;
  this->direction.parms[3] = 0.0;
  this->direction.coneAxis = mat3_identity;
  do
  {
    *(v1++ - 1) = 0.0;
    *v1 = 0.0;
    --v2;
  }
  while ( v2 != 0 );
  this->speed.speed[0].val0 = 0.0;
  this->speed.speed[0].tableIdx = -1;
  this->speed.speed[0].val1 = 0.0;
  this->speed.speed[0].table2Idx = -1;
  this->speed.speed[0].variance = 0.0;
  this->speed.speed[1].tableIdx = -1;
  this->speed.speed[1].val0 = 0.0;
  this->speed.speed[1].table2Idx = -1;
  this->speed.speed[1].val1 = 0.0;
  this->speed.speed[1].variance = 0.0;
  this->speed.speed[2].tableIdx = -1;
  this->speed.speed[2].val0 = 0.0;
  this->speed.speed[2].table2Idx = -1;
  this->speed.speed[2].val1 = 0.0;
  this->speed.speed[2].variance = 0.0;
  this->acceleration.acceleration[0].tableIdx = -1;
  this->acceleration.acceleration[0].val0 = 0.0;
  this->acceleration.acceleration[0].table2Idx = -1;
  this->acceleration.acceleration[0].val1 = 0.0;
  this->acceleration.acceleration[0].variance = 0.0;
  this->acceleration.acceleration[1].tableIdx = -1;
  this->acceleration.acceleration[1].val0 = 0.0;
  this->acceleration.acceleration[1].table2Idx = -1;
  this->acceleration.acceleration[1].val1 = 0.0;
  this->acceleration.acceleration[1].variance = 0.0;
  this->acceleration.acceleration[2].tableIdx = -1;
  this->acceleration.acceleration[2].val0 = 0.0;
  this->acceleration.acceleration[2].table2Idx = -1;
  this->acceleration.acceleration[2].val1 = 0.0;
  this->acceleration.acceleration[2].variance = 0.0;
  this->acceleration.world = false;
  this->gravity.gravity.val0 = 0.0;
  this->gravity.gravity.tableIdx = -1;
  this->gravity.gravity.val1 = 0.0;
  this->gravity.gravity.table2Idx = -1;
  this->gravity.gravity.variance = 0.0;
  this->gravity.world = false;
  this->friction.friction[0].val0 = 0.0;
  this->friction.friction[0].tableIdx = -1;
  this->friction.friction[0].val1 = 0.0;
  this->friction.friction[0].table2Idx = -1;
  this->friction.friction[0].variance = 0.0;
  this->friction.friction[1].tableIdx = -1;
  this->friction.friction[1].val0 = 0.0;
  this->friction.friction[1].table2Idx = -1;
  this->friction.friction[1].val1 = 0.0;
  this->friction.friction[1].variance = 0.0;
  this->friction.friction[2].tableIdx = -1;
  this->friction.friction[2].val0 = 0.0;
  this->friction.friction[2].table2Idx = -1;
  this->friction.friction[2].val1 = 0.0;
  this->friction.friction[2].variance = 0.0;
  this->offset.offset[0].tableIdx = -1;
  this->offset.offset[0].val0 = 0.0;
  this->offset.offset[0].table2Idx = -1;
  this->offset.offset[0].val1 = 0.0;
  this->offset.offset[0].variance = 0.0;
  this->offset.offset[1].tableIdx = -1;
  this->offset.offset[1].val0 = 0.0;
  this->offset.offset[1].table2Idx = -1;
  this->offset.offset[1].val1 = 0.0;
  this->offset.offset[1].variance = 0.0;
  this->offset.offset[2].tableIdx = -1;
  this->offset.offset[2].val0 = 0.0;
  this->offset.offset[2].table2Idx = -1;
  this->offset.offset[2].val1 = 0.0;
  this->offset.offset[2].variance = 0.0;
  this->spawnLocation.spawnLocation[0].tableIdx = -1;
  this->spawnLocation.spawnLocation[0].val0 = 0.0;
  this->spawnLocation.spawnLocation[0].table2Idx = -1;
  this->spawnLocation.spawnLocation[0].val1 = 0.0;
  this->spawnLocation.spawnLocation[0].variance = 0.0;
  this->spawnLocation.spawnLocation[1].tableIdx = -1;
  this->spawnLocation.spawnLocation[1].val0 = 0.0;
  this->spawnLocation.spawnLocation[1].table2Idx = -1;
  this->spawnLocation.spawnLocation[1].val1 = 0.0;
  this->spawnLocation.spawnLocation[1].variance = 0.0;
  this->spawnLocation.spawnLocation[2].tableIdx = -1;
  this->spawnLocation.spawnLocation[2].val0 = 0.0;
  this->spawnLocation.spawnLocation[2].val1 = 0.0;
  this->spawnLocation.spawnLocation[2].variance = 0.0;
  this->spawnLocation.spawnLocation[2].table2Idx = -1;
  this->colorAttributes.baseColor[0].val0 = 0.0;
  this->colorAttributes.baseColor[0].val1 = 0.0;
  this->colorAttributes.baseColor[0].tableIdx = -1;
  this->colorAttributes.baseColor[0].variance = 0.0;
  this->colorAttributes.baseColor[0].table2Idx = -1;
  this->colorAttributes.baseColor[1].val0 = 0.0;
  this->colorAttributes.baseColor[1].tableIdx = -1;
  this->colorAttributes.baseColor[1].val1 = 0.0;
  this->colorAttributes.baseColor[1].table2Idx = -1;
  this->colorAttributes.baseColor[1].variance = 0.0;
  this->colorAttributes.baseColor[2].tableIdx = -1;
  this->colorAttributes.baseColor[2].val0 = 0.0;
  this->colorAttributes.baseColor[2].table2Idx = -1;
  this->colorAttributes.baseColor[2].val1 = 0.0;
  this->colorAttributes.baseColor[2].variance = 0.0;
  this->colorAttributes.baseColor[3].tableIdx = -1;
  this->colorAttributes.baseColor[3].val0 = 0.0;
  this->colorAttributes.baseColor[3].table2Idx = -1;
  this->colorAttributes.baseColor[3].val1 = 0.0;
  this->colorAttributes.baseColor[3].variance = 0.0;
  this->colorAttributes.brightness.tableIdx = -1;
  this->colorAttributes.brightness.val0 = 0.0;
  this->colorAttributes.brightness.table2Idx = -1;
  this->colorAttributes.brightness.val1 = 0.0;
  this->colorAttributes.brightness.variance = 0.0;
  this->colorAttributes.fadeColor.x = 0.0;
  this->colorAttributes.fadeColor.y = 0.0;
  this->colorAttributes.fadeColor.z = 0.0;
  this->colorAttributes.fadeColor.w = 0.0;
  this->colorAttributes.useGlobalShadows = false;
  this->colorAttributes.fadeInFraction = 0.0;
  this->colorAttributes.fadeOutFraction = 0.0;
  this->colorAttributes.fadeIndexFraction = 0.0;
  this->colorAttributes.softParticleAlphaScale = 1.0;
  this->colorAttributes.minShadowVal = 0.0;
  this->colorAttributes.entityColorBlendVal = 1.0;
  this->rotation.rotation[0].tableIdx = -1;
  this->rotation.rotation[0].val0 = 0.0;
  this->rotation.rotation[0].table2Idx = -1;
  this->rotation.rotation[0].val1 = 0.0;
  this->rotation.rotation[0].variance = 0.0;
  this->rotation.rotation[1].tableIdx = -1;
  this->rotation.rotation[1].val0 = 0.0;
  this->rotation.rotation[1].table2Idx = -1;
  this->rotation.rotation[1].val1 = 0.0;
  this->rotation.rotation[1].variance = 0.0;
  this->rotation.rotation[2].tableIdx = -1;
  this->rotation.rotation[2].val0 = 0.0;
  this->rotation.rotation[2].table2Idx = -1;
  this->rotation.rotation[2].val1 = 0.0;
  this->rotation.rotation[2].variance = 0.0;
  this->rotation.allowRotDirOverride = true;
  this->initialRotation.initialAngle[0].val0 = 0.0;
  this->initialRotation.initialAngle[0].tableIdx = -1;
  this->initialRotation.initialAngle[0].val1 = 0.0;
  this->initialRotation.initialAngle[0].table2Idx = -1;
  this->initialRotation.initialAngle[0].variance = 0.0;
  this->initialRotation.initialAngle[1].tableIdx = -1;
  this->initialRotation.initialAngle[1].val0 = 0.0;
  this->initialRotation.initialAngle[1].table2Idx = -1;
  this->initialRotation.initialAngle[1].val1 = 0.0;
  this->initialRotation.initialAngle[1].variance = 0.0;
  this->initialRotation.initialAngle[2].tableIdx = -1;
  this->initialRotation.initialAngle[2].val0 = 0.0;
  this->initialRotation.initialAngle[2].table2Idx = -1;
  this->initialRotation.initialAngle[2].val1 = 0.0;
  this->initialRotation.initialAngle[2].variance = 0.0;
  this->pivot.pivotOffset.x = 0.0;
  this->pivot.pivotOffset.y = 0.0;
  this->size.size[0].tableIdx = -1;
  this->size.size[0].val0 = 0.0;
  this->size.size[0].table2Idx = -1;
  this->size.size[0].val1 = 0.0;
  this->size.size[0].variance = 0.0;
  this->size.size[1].tableIdx = -1;
  this->size.size[1].val0 = 0.0;
  this->size.size[1].table2Idx = -1;
  this->size.size[1].val1 = 0.0;
  this->size.size[1].variance = 0.0;
  this->size.size[2].val0 = 0.0;
  this->size.size[2].val1 = 0.0;
  this->size.size[2].tableIdx = -1;
  this->size.size[2].variance = 0.0;
  this->size.size[2].table2Idx = -1;
  this->size.aspectRatio.val0 = 0.0;
  this->size.aspectRatio.tableIdx = -1;
  this->size.aspectRatio.val1 = 0.0;
  this->size.aspectRatio.table2Idx = -1;
  this->size.aspectRatio.variance = 0.0;
  this->texAnimation.type = PANIM_TYPE_SINGLE_CYCLE;
  this->texAnimation.numRows = 0;
  this->texAnimation.numColumns = 0;
  this->texAnimation.rate.val0 = 0.0;
  this->texAnimation.rate.val1 = 0.0;
  this->texAnimation.rate.tableIdx = -1;
  this->texAnimation.rate.variance = 0.0;
  this->texAnimation.rate.table2Idx = -1;
  this->texAnimation.startFrame = 0;
  *(_WORD *)&this->texAnimation.useRandomRow = 1;
  this->customPath.type = PPATH_STANDARD;
  this->customPath.parms[0].val0 = 0.0;
  this->customPath.parms[0].val1 = 0.0;
  this->customPath.parms[0].tableIdx = -1;
  this->customPath.parms[0].variance = 0.0;
  this->customPath.parms[0].table2Idx = -1;
  this->customPath.parms[1].tableIdx = -1;
  this->customPath.parms[1].table2Idx = -1;
  this->customPath.parms[1].val0 = 0.0;
  this->customPath.parms[1].val1 = 0.0;
  this->customPath.parms[1].variance = 0.0;
  this->customPath.parms[2].tableIdx = -1;
  this->customPath.parms[2].table2Idx = -1;
  this->customPath.parms[2].val0 = 0.0;
  this->customPath.parms[2].val1 = 0.0;
  this->customPath.parms[2].variance = 0.0;
  this->customPath.parms[3].tableIdx = -1;
  this->customPath.parms[3].table2Idx = -1;
  this->customPath.parms[3].val0 = 0.0;
  this->customPath.parms[3].val1 = 0.0;
  this->customPath.parms[3].variance = 0.0;
  this->customPath.parms[4].tableIdx = -1;
  this->customPath.parms[4].table2Idx = -1;
  this->customPath.parms[4].val0 = 0.0;
  this->customPath.parms[4].val1 = 0.0;
  this->customPath.parms[4].variance = 0.0;
  this->genericParm.genericParm[0].tableIdx = -1;
  this->genericParm.genericParm[0].val0 = 0.0;
  this->genericParm.genericParm[0].table2Idx = -1;
  this->genericParm.genericParm[0].val1 = 0.0;
  this->genericParm.genericParm[0].variance = 0.0;
  this->genericParm.genericParm[1].tableIdx = -1;
  this->genericParm.genericParm[1].val0 = 0.0;
  this->genericParm.genericParm[1].table2Idx = -1;
  this->genericParm.genericParm[1].val1 = 0.0;
  this->genericParm.genericParm[1].variance = 0.0;
  this->genericParm.genericParm[2].tableIdx = -1;
  this->genericParm.genericParm[2].val0 = 0.0;
  this->genericParm.genericParm[2].table2Idx = -1;
  this->genericParm.genericParm[2].val1 = 0.0;
  this->genericParm.genericParm[2].variance = 0.0;
  this->genericParm.genericParm[3].tableIdx = -1;
  this->genericParm.genericParm[3].val0 = 0.0;
  this->genericParm.genericParm[3].table2Idx = -1;
  this->genericParm.genericParm[3].val1 = 0.0;
  this->genericParm.genericParm[3].variance = 0.0;
  this->lodParms.totalParticles = 1;
  this->lodParms.sizeScale = 1.0;
  this->lodParms.radius = 0;
  this->lodParms.lerpAmount = 0.0;
  return this;
}


// ========================================================================
// ?Default@idParticleStage@@QAAXPBVidLookupTable@@@Z
// EA  : 0x827EB820
// RVA : 0x007EB820
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

void __fastcall idParticleStage::Default(idParticleStage *this, const idLookupTable *tables)
{
  idParticleParm *p_particleLife; // r28
  const idMaterial *material; // r6
  const idMaterial *v6; // r4
  char v7; // r11
  bool v8; // r10
  float *v9; // r10
  int v10; // ctr
  idParticleParm *parms; // r25
  int v12; // r26
  double MaxParmVal; // fp1
  double v14; // fp30
  double v15; // fp1
  double emissionTime; // fp0

  p_particleLife = &this->systemProperties.particleLife;
  this->systemProperties.material = (const idMaterial *)mtrDefaultParticle.r;
  this->atlasScaleBias = *(idVec4 *)&mtrDefaultParticle.r[1].resourceError;
  material = this->systemProperties.material;
  v6 = material;
  v7 = (8 * *((_BYTE *)material + 72)) & 0x40 | *((_BYTE *)this + 68) & 0xBF;
  *((_BYTE *)this + 68) = v7;
  LOBYTE(material) = (8 * *((_BYTE *)material + 72)) & 0x20 | v7 & 0xDF;
  *((_BYTE *)this + 68) = (_BYTE)material;
  v8 = v6->progs[4] != nullptr;
  this->staticData = nullptr;
  this->staticVerts = nullptr;
  this->numStaticVerts = 0;
  this->systemProperties.totalParticles = 20;
  this->systemProperties.diversity = 0;
  this->systemProperties.cycles = 0;
  *((_BYTE *)this + 68) = (16 * v8) & 0x10 | (unsigned __int8)material & 0x6F;
  SetParticleParmAsConstant(parm: &this->systemProperties.particleLife, constantVal: 1.5, variance: 0.0);
  this->systemProperties.timeOffset = 0.0;
  SetParticleParmAsConstant(parm: &this->systemProperties.deadTime, constantVal: 0.0, variance: 0.0);
  this->systemProperties.useSysTime = 0.0;
  this->systemProperties.textureFlipS = PTEXTURE_FLIP_NONE;
  this->systemProperties.emissionTime = 0.0;
  this->systemProperties.textureFlipT = PTEXTURE_FLIP_NONE;
  this->systemProperties.spawnBunching = 1.0;
  SetParticleParmAsConstant(parm: &this->systemProperties.windBias, constantVal: 0.0, variance: 0.0);
  this->systemProperties.boundsExpansion = 0.0;
  this->systemProperties.sortType = PSORT_TYPE_NONE;
  this->systemProperties.randomOnCycle = true;
  this->distribution.type = PDIST_RECT;
  SetParticleParmAsConstant(parm: this->distribution.size, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->distribution.size[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->distribution.size[2], constantVal: 0.0, variance: 0.0);
  this->orientation.segmentLength = 0.0;
  this->orientation.world = false;
  this->orientation.viewFade = 1.0;
  this->orientation.aimedSafeQuad = false;
  this->direction.parms[1] = 0.0;
  this->direction.parms[3] = 0.0;
  this->orientation.aimedSafeQuadAlign = 1.0;
  this->distribution.random = true;
  this->orientation.depthOffset = 0.0;
  this->orientation.type = POR_VIEW;
  this->direction.parms[2] = 0.0;
  this->orientation.numTrails = 0;
  this->orientation.orientToVelOnly = false;
  this->direction.parms[0] = 90.0;
  this->direction.type = PDIR_CONE;
  v9 = &this->direction.parms[3];
  v10 = 2;
  this->direction.coneAxis = mat3_identity;
  do
  {
    v9[3] = 0.0;
    *++v9 = 0.0;
    --v10;
  }
  while ( v10 != 0 );
  SetParticleParmAsIntegrate(parm: this->speed.speed, from: 0.0, to: 0.0, variance: 0.0);
  SetParticleParmAsIntegrate(parm: &this->speed.speed[1], from: 0.0, to: 0.0, variance: 0.0);
  SetParticleParmAsIntegrate(parm: &this->speed.speed[2], from: 0.0, to: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: this->acceleration.acceleration, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->acceleration.acceleration[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->acceleration.acceleration[2], constantVal: 0.0, variance: 0.0);
  this->acceleration.world = false;
  SetParticleParmAsConstant(parm: &this->gravity.gravity, constantVal: 0.0, variance: 0.0);
  this->gravity.world = false;
  SetParticleParmAsConstant(parm: this->friction.friction, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->friction.friction[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->friction.friction[2], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: this->offset.offset, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->offset.offset[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->offset.offset[2], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: this->spawnLocation.spawnLocation, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->spawnLocation.spawnLocation[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->spawnLocation.spawnLocation[2], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: this->colorAttributes.baseColor, constantVal: 1.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->colorAttributes.baseColor[1], constantVal: 1.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->colorAttributes.baseColor[2], constantVal: 1.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->colorAttributes.baseColor[3], constantVal: 1.0, variance: 0.0);
  this->colorAttributes.fadeColor.x = 0.0;
  this->colorAttributes.fadeColor.y = 0.0;
  this->colorAttributes.fadeColor.z = 0.0;
  this->colorAttributes.fadeColor.w = 0.0;
  this->colorAttributes.fadeIndexFraction = 0.0;
  this->colorAttributes.fadeInFraction = 0.1;
  this->colorAttributes.fadeOutFraction = 0.25;
  this->colorAttributes.softParticleAlphaScale = 1.0;
  SetParticleParmAsConstant(parm: &this->colorAttributes.brightness, constantVal: 1.0, variance: 0.0);
  this->colorAttributes.entityColorBlendVal = 1.0;
  this->colorAttributes.useGlobalShadows = false;
  this->colorAttributes.minShadowVal = 0.2;
  SetParticleParmAsIntegrate(parm: this->rotation.rotation, from: 0.0, to: 0.0, variance: 0.0);
  SetParticleParmAsIntegrate(parm: &this->rotation.rotation[1], from: 0.0, to: 0.0, variance: 0.0);
  SetParticleParmAsIntegrate(parm: &this->rotation.rotation[2], from: 0.0, to: 0.0, variance: 0.0);
  this->rotation.allowRotDirOverride = true;
  SetParticleParmAsMinMax(parm: this->initialRotation.initialAngle, min: -360.0, max: 360.0);
  SetParticleParmAsMinMax(parm: &this->initialRotation.initialAngle[1], min: -360.0, max: 360.0);
  SetParticleParmAsMinMax(parm: &this->initialRotation.initialAngle[2], min: -360.0, max: 360.0);
  this->pivot.pivotOffset.x = 0.0;
  this->pivot.pivotOffset.y = 0.0;
  SetParticleParmAsEval(parm: this->size.size, from: 4.0, to: 4.0, variance: 0.0);
  SetParticleParmAsEval(parm: &this->size.size[1], from: 4.0, to: 4.0, variance: 0.0);
  SetParticleParmAsEval(parm: &this->size.size[2], from: 4.0, to: 4.0, variance: 0.0);
  SetParticleParmAsEval(parm: &this->size.aspectRatio, from: 1.0, to: 1.0, variance: 0.0);
  this->texAnimation.numRows = 1;
  this->texAnimation.numColumns = 1;
  this->texAnimation.type = PANIM_TYPE_SINGLE_CYCLE;
  SetParticleParmAsConstant(parm: &this->texAnimation.rate, constantVal: 0.0, variance: 0.0);
  this->texAnimation.startFrame = 0;
  this->texAnimation.useRandomRow = false;
  parms = this->customPath.parms;
  this->texAnimation.useFrameBlending = true;
  v12 = 5;
  this->customPath.type = PPATH_STANDARD;
  do
  {
    SetParticleParmAsConstant(parm: parms, constantVal: 0.0, variance: 0.0);
    --v12;
    ++parms;
  }
  while ( v12 != 0 );
  SetParticleParmAsConstant(parm: this->genericParm.genericParm, constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->genericParm.genericParm[1], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->genericParm.genericParm[2], constantVal: 0.0, variance: 0.0);
  SetParticleParmAsConstant(parm: &this->genericParm.genericParm[3], constantVal: 0.0, variance: 0.0);
  this->lodParms.sizeScale = 1.0;
  this->lodParms.totalParticles = 1;
  this->lodParms.lerpAmount = 0.0;
  this->lodParms.radius = 0;
  MaxParmVal = idParticleParm::GetMaxParmVal(this: p_particleLife, tables);
  this->maxParticleLife = MaxParmVal;
  v14 = MaxParmVal;
  v15 = idParticleParm::GetMaxParmVal(this: &this->systemProperties.deadTime, tables);
  this->maxDeadTime = v15;
  emissionTime = this->systemProperties.emissionTime;
  this->cycleMsec = (int)(float)((float)((float)v15 + (float)v14) * (float)1000.0);
  if ( emissionTime <= 0.0 )
    this->bunchTime = v14;
  else
    this->bunchTime = emissionTime;
}


// ========================================================================
// ?CalculateBounds@idParticleStage@@AAAXPBVidLookupTable@@@Z
// EA  : 0x827EBDD8
// RVA : 0x007EBDD8
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idParticleStage::CalculateBounds(idParticleStage *this, idLookupTable *tables)
{
  int v2; // r6
  float *p_bounds; // r31
  __int16 totalParticles; // r4
  idVec3 *v7; // r23
  unsigned int v8; // r28
  double v9; // fp29
  double maxParticleLife; // fp4
  int v11; // r21
  __int64 v12; // r10 OVERLAPPED
  int v13; // r29
  __int64 v14; // r8
  idRandom2 *v15; // r5
  float *v16; // r3
  int v17; // r30
  int v18; // r11
  idParticleStage::prtSize_t *p_size; // r3
  __int64 v32; // r8
  idRandom2 *v33; // r5
  __int64 v34; // r8
  idRandom2 *v35; // r5
  double v36; // fp30
  __int64 v37; // r8
  idRandom2 *v38; // r5
  double v39; // fp1
  int v40; // r11
  int i; // ctr
  double v42; // fp9
  double v43; // fp5
  double v44; // fp2
  double v45; // fp3
  double v46; // fp1
  double v47; // fp6
  double v48; // fp7
  unsigned __int64 v49; // [sp+50h] [-230h] BYREF
  float v50; // [sp+58h] [-228h] BYREF
  float v51; // [sp+5Ch] [-224h]
  float v52; // [sp+60h] [-220h]
  idVec3 v53; // [sp+68h] [-218h] BYREF
  idVec3 v54; // [sp+78h] [-208h] BYREF
  particleInput_t v55; // [sp+90h] [-1F0h] BYREF
  idRandom2 v56; // [sp+190h] [-F0h] BYREF
  float v57; // [sp+194h] [-ECh]
  float v58; // [sp+198h] [-E8h]
  float v59; // [sp+19Ch] [-E4h]
  float v60; // [sp+1A0h] [-E0h]
  float v61; // [sp+1A4h] [-DCh]
  unsigned int v62; // [sp+1A8h] [-D8h]
  unsigned int v63; // [sp+1ACh] [-D4h]
  idMat3 v64[2]; // [sp+1C0h] [-C0h] BYREF

  v55.tables = tables;
  v55.stage = this;
  v2 = 0x82000000;
  this->bounds.b[0].z = 1.0e30;
  p_bounds = (float *)&this->bounds;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  v55.view = nullptr;
  this->bounds.b[1].y = -1.0e30;
  v55.staticVerts = nullptr;
  this->bounds.b[1].x = -1.0e30;
  totalParticles = this->systemProperties.totalParticles;
  v55.numInfluenceSpheres = 0;
  v55.influenceSpheres = nullptr;
  v7 = &this->bounds.b[1];
  v8 = 0;
  v55.totalParticles = totalParticles;
  v56.seed = totalParticles;
  HIDWORD(v12) = &vec3_up;
  v9 = 0.0;
  maxParticleLife = this->maxParticleLife;
  v55.localViewLeft.x = 0.0;
  v55.localViewLeft.y = 1.0;
  v55.localViewLeft.z = 0.0;
  v55.entityColor.x = 1.0;
  v55.entityColor.y = 1.0;
  v55.entityColor.z = 1.0;
  v55.entityColor.w = 1.0;
  v55.fade = 1.0;
  v55.alphaScaleOverride = 1.0;
  v55.shadow = 1.0;
  v55.distribScale.x = 1.0;
  v55.distribScale.y = 1.0;
  v55.distribScale.z = 1.0;
  v55.sizeScale = 1.0;
  v55.stageAxis.mat[0].x = mat3_identity.mat[0].x;
  v55.stageAxis.mat[0].z = mat3_identity.mat[0].z;
  v55.stageAxis.mat[0].y = mat3_identity.mat[0].y;
  v55.stageAxis.mat[1].x = mat3_identity.mat[1].x;
  v55.stageAxis.mat[1].y = mat3_identity.mat[1].y;
  v55.stageAxis.mat[1].z = mat3_identity.mat[1].z;
  v55.stageAxis.mat[2].x = mat3_identity.mat[2].x;
  v55.stageAxis.mat[2].y = mat3_identity.mat[2].y;
  v55.stageAxis.mat[2].z = mat3_identity.mat[2].z;
  v55.modelAxis.mat[0] = mat3_identity.mat[0];
  v55.modelAxis.mat[1].x = mat3_identity.mat[1].x;
  v55.modelAxis.mat[1].y = mat3_identity.mat[1].y;
  v55.modelAxis.mat[1].z = mat3_identity.mat[1].z;
  v55.modelAxis.mat[2].x = mat3_identity.mat[2].x;
  v55.modelAxis.mat[2].y = mat3_identity.mat[2].y;
  v55.modelAxis.mat[2].z = mat3_identity.mat[2].z;
  v55.globalAxis.mat[0] = mat3_identity.mat[0];
  v11 = 100;
  LODWORD(v12) = 1013841920;
  v55.globalOrigin.x = vec3_origin.x;
  v55.localVelocity.x = vec3_origin.x;
  v55.localViewOrg.x = vec3_origin.x;
  v55.wind.x = vec3_origin.x;
  v55.globalOrigin.y = vec3_origin.y;
  v55.localVelocity.y = vec3_origin.y;
  v55.localViewOrg.y = vec3_origin.y;
  v55.wind.y = vec3_origin.y;
  v55.globalAxis.mat[1].x = mat3_identity.mat[1].x;
  v55.globalAxis.mat[1].y = mat3_identity.mat[1].y;
  v55.globalAxis.mat[1].z = mat3_identity.mat[1].z;
  v55.globalAxis.mat[2].x = mat3_identity.mat[2].x;
  v55.globalAxis.mat[2].y = mat3_identity.mat[2].y;
  v55.globalAxis.mat[2].z = mat3_identity.mat[2].z;
  v55.globalOrigin.z = vec3_origin.z;
  v55.localVelocity.z = vec3_origin.z;
  v55.localViewUp.x = vec3_up.x;
  v55.localViewUp.y = vec3_up.y;
  v55.localViewUp.z = vec3_up.z;
  v55.localViewOrg.z = vec3_origin.z;
  v55.wind.z = vec3_origin.z;
  v13 = (int)(float)((float)maxParticleLife * (float)1000.0);
  v59 = maxParticleLife;
  v14 = __PAIR64__(&mat3_identity, v13);
  v49 = __PAIR64__(&mat3_identity, v13);
  do
  {
    v63 = v8;
    v62 = v8;
    v8 = 1664525 * v8 + 1013904223;
    v16 = (float *)ParticleStageAxis(
                     result: v64,
                     stage: this,
                     diversity: (v8 >> 10) & 0x7FFF,
                     a4: v2,
                     a5: SHIDWORD(v14),
                     a6: v12);
    v55.stageAxis.mat[0].x = *v16;
    v17 = 0;
    v55.stageAxis.mat[0].y = v16[1];
    v55.stageAxis.mat[0].z = v16[2];
    v55.stageAxis.mat[1].x = v16[3];
    v55.stageAxis.mat[1].y = v16[4];
    v55.stageAxis.mat[1].z = v16[5];
    v55.stageAxis.mat[2].x = v16[6];
    v55.stageAxis.mat[2].y = v16[7];
    for ( v55.stageAxis.mat[2].z = v16[8]; v17 < v13; p_bounds[5] = _FP5 )
    {
      if ( v17 + 16 > v13 )
        v17 = v13 - 1;
      v18 = v17;
      v49 = *(__int64 *)((char *)&v12 - 4);
      v60 = (float)*(__int64 *)((char *)&v12 - 4) * (float)((float)1.0 / (float)__SPAIR64__(&mat3_identity, v13));
      v57 = (float)*(__int64 *)((char *)&v12 - 4) * (float)0.001;
      v61 = v60;
      v58 = v57;
      ParticleOrigin(result: &v53, inputs: &v55, g: &v56, origin: &v54, a5: v14);
      v17 += 16;
      _FP8 = (float)(*p_bounds - v54.x);
      _FP4 = (float)(p_bounds[2] - v54.z);
      _FP2 = (float)(v54.x - v7->x);
      _FP6 = (float)(p_bounds[1] - v54.y);
      _FP11 = (float)(v54.y - p_bounds[4]);
      _FP28 = (float)(v54.z - p_bounds[5]);
      __asm { fsel      f10, f8, f0, f10 }
      *p_bounds = _FP10;
      __asm { fsel      f8, f4, f12, f7 }
      p_bounds[2] = _FP8;
      __asm { fsel      f7, f2, f0, f5 }
      v7->x = _FP7;
      __asm { fsel      f9, f6, f13, f9 }
      p_bounds[1] = _FP9;
      __asm { fsel      f6, f11, f13, f3 }
      p_bounds[4] = _FP6;
      __asm { fsel      f5, f28, f12, f1 }
    }
    --v11;
  }
  while ( v11 != 0 );
  v53 = vec3_origin;
  HIDWORD(v49) = v8;
  do
  {
    p_size = &this->size;
    if ( this->staticData != nullptr )
    {
      v50 = idParticleParm::Compute(
              this: p_size->size,
              (idRandom2 *)tables,
              frac: v9,
              rand: v15,
              a5: (idRandom2 *)&v49,
              a6: v14);
      v51 = idParticleParm::Compute(
              this: &this->size.size[1],
              (idRandom2 *)tables,
              frac: v9,
              rand: v33,
              a5: (idRandom2 *)&v49,
              a6: v32);
      v52 = idParticleParm::Compute(
              this: &this->size.size[2],
              (idRandom2 *)tables,
              frac: v9,
              rand: v35,
              a5: (idRandom2 *)&v49,
              a6: v34);
    }
    else
    {
      v36 = idParticleParm::Compute(
              this: p_size->size,
              (idRandom2 *)tables,
              frac: v9,
              rand: v15,
              a5: (idRandom2 *)&v49,
              a6: v14);
      v39 = idParticleParm::Compute(
              this: &this->size.aspectRatio,
              (idRandom2 *)tables,
              frac: v9,
              rand: v38,
              a5: (idRandom2 *)&v49,
              a6: v37);
      if ( this->orientation.type == POR_AIMED )
      {
        v51 = this->orientation.segmentLength * (float)v39;
      }
      else
      {
        if ( v39 > 1.0 )
          v36 = (float)((float)v39 * (float)v36);
        v51 = v36;
      }
      v50 = v36;
      v52 = v36;
    }
    v40 = 0;
    for ( i = 3; i != 0; --i )
    {
      if ( *(float *)((char *)&v50 + v40) > (double)*(float *)((char *)&v53.x + v40) )
        *(float *)((char *)&v53.x + v40) = *(float *)((char *)&v50 + v40);
      v40 += 4;
    }
    v9 = (float)((float)v9 + (float)0.015625);
  }
  while ( v9 <= 1.0 );
  v42 = p_bounds[2];
  v43 = *p_bounds;
  v44 = (float)((float)(v53.y + (float)8.0) + this->systemProperties.boundsExpansion);
  v45 = (float)((float)(v53.z + (float)8.0) + this->systemProperties.boundsExpansion);
  v46 = (float)((float)(v53.x + (float)8.0) + this->systemProperties.boundsExpansion);
  p_bounds[1] = p_bounds[1] - (float)((float)(v53.y + (float)8.0) + this->systemProperties.boundsExpansion);
  p_bounds[2] = (float)v42 - (float)v45;
  *p_bounds = (float)v43 - (float)v46;
  v47 = (float)(v7->x + (float)v46);
  v48 = (float)((float)v45 + v7->z);
  v7->y = (float)v44 + v7->y;
  v7->x = v47;
  v7->z = v48;
}


// ========================================================================
// `dynamic initializer for 'mtrDefaultParticle''
// EA  : 0x83342F50
// RVA : 0x01342F50
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.cpp
// ========================================================================

void _dynamic_initializer_for__mtrDefaultParticle__()
{
  mtrDefaultParticle.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mtrDefaultParticle;
}

