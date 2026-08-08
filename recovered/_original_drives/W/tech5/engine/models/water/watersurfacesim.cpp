
// ========================================================================
// ?GetTimeStep@idWaterSurfaceSim@@QBAMXZ
// EA  : 0x8288FDF8
// RVA : 0x0088FDF8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

float __fastcall idWaterSurfaceSim::GetTimeStep(idWaterSurfaceSim *this)
{
  double timeStep; // fp1

  timeStep = this->timeStep;
  return *((float *)&timeStep + 1);
}


// ========================================================================
// ?Swap@idWaterSurfaceSim@@QAAXXZ
// EA  : 0x8288FE00
// RVA : 0x0088FE00
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::Swap(idWaterSurfaceSim *this)
{
  int v1; // r9

  v1 = this->currentDeferred ^ 1;
  this->numDisturbances = 0;
  this->currentDeferred = v1;
}


// ========================================================================
// ?GlobalToLocalPos@idWaterSurfaceSim@@AAAXABVidVec3@@AAV2@PBVidRenderModel@@@Z
// EA  : 0x82890000
// RVA : 0x00890000
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::GlobalToLocalPos(
        idWaterSurfaceSim *this,
        const idVec3 *globalPos,
        idVec3 *localPos,
        idRenderModel *rmod)
{
  double v6; // fp7
  double v7; // fp6

  idRenderModel::GlobalPointToLocal(this: rmod, in: globalPos, out: localPos);
  v6 = (float)(localPos->y - this->origin.y);
  v7 = (float)(localPos->z - this->origin.z);
  localPos->x = localPos->x - this->origin.x;
  localPos->y = v6;
  localPos->z = v7;
}


// ========================================================================
// ?LocalToGridSpacePos@idWaterSurfaceSim@@AAAXABVidVec3@@AAH1@Z
// EA  : 0x82890070
// RVA : 0x00890070
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::LocalToGridSpacePos(
        idWaterSurfaceSim *this,
        const idVec3 *localPos,
        int *xpos,
        int *ypos,
        long double a5)
{
  long double v9; // fp2
  long double v10; // fp2

  *(double *)&a5 = (float)((float)(localPos->x / this->spacing) + (float)0.5);
  v9 = floor(x: a5);
  *xpos = (int)(float)*(double *)&v9;
  *(double *)&v9 = (float)((float)(localPos->y / this->spacing) + (float)0.5);
  v10 = floor(x: v9);
  *ypos = (int)(float)*(double *)&v10;
}


// ========================================================================
// ?AddRipple@idWaterSurfaceSim@@QAAXABVidVec3@@MMPBVidRenderModel@@@Z
// EA  : 0x828900E8
// RVA : 0x008900E8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::AddRipple(
        idWaterSurfaceSim *this,
        const idVec3 *pos,
        double mag,
        double radius,
        const idRenderModel *rmod,
        int a6,
        idRenderModel *a7)
{
  float y; // r10
  float z; // r9
  long double v12; // fp2
  int numDisturbances; // r11
  double x; // fp0
  int v15; // r4
  int currentDeferred; // r9
  int v17; // r3
  double v18; // fp13
  waterDisturbanceParms_t *v19; // r11
  int v20; // [sp+50h] [-50h] BYREF
  int v21; // [sp+54h] [-4Ch] BYREF
  idVec3 v22; // [sp+58h] [-48h] BYREF
  idVec3 v23[2]; // [sp+68h] [-38h] BYREF

  if ( this->visible && this->numDisturbances < 100 )
  {
    y = pos->y;
    z = pos->z;
    v22.x = pos->x;
    v22.y = y;
    v22.z = z;
    idWaterSurfaceSim::GlobalToLocalPos(this, globalPos: &v22, localPos: v23, rmod: a7);
    idWaterSurfaceSim::LocalToGridSpacePos(this, localPos: v23, xpos: &v20, ypos: &v21, a5: v12);
    numDisturbances = this->numDisturbances;
    x = v23[0].x;
    v15 = v20;
    currentDeferred = this->currentDeferred;
    v17 = v21;
    v18 = v23[0].y;
    this->numDisturbances = numDisturbances + 1;
    v19 = &this->waterDisturbances[currentDeferred].list[numDisturbances];
    v19->gridX = v15;
    v19->gridY = v17;
    v19->loc.x = x;
    v19->loc.y = v18;
    v19->parms.x = mag;
    v19->type = WATER_DISTURBANCE_TYPE_RIPPLE;
    v19->radius = radius;
  }
}


// ========================================================================
// ?AddFancyRipple@idWaterSurfaceSim@@QAAXABVidVec3@@PBVidRenderModel@@MMMMM@Z
// EA  : 0x828901D8
// RVA : 0x008901D8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::AddFancyRipple(
        idWaterSurfaceSim *this,
        const idVec3 *pos,
        idRenderModel *rmod,
        double amp,
        double freq,
        double fade1,
        double fade2,
        double currDist)
{
  float y; // r10
  float z; // r9
  int numDisturbances; // r11
  double x; // fp0
  double v18; // fp13
  char *v19; // r4
  int v20; // r11
  idVec3 v21; // [sp+50h] [-60h] BYREF
  idVec3 v22; // [sp+60h] [-50h] BYREF

  if ( this->visible && this->numDisturbances < 100 )
  {
    y = pos->y;
    z = pos->z;
    v21.x = pos->x;
    v21.y = y;
    v21.z = z;
    idWaterSurfaceSim::GlobalToLocalPos(this, globalPos: &v21, localPos: &v22, rmod);
    numDisturbances = this->numDisturbances;
    x = v22.x;
    v18 = v22.y;
    v19 = (char *)this + 16 * this->currentDeferred;
    this->numDisturbances = numDisturbances + 1;
    v20 = *((_DWORD *)v19 + 37) + 48 * numDisturbances;
    *(float *)(v20 + 12) = x;
    *(float *)(v20 + 16) = v18;
    *(_DWORD *)v20 = 2;
    *(float *)(v20 + 20) = amp;
    *(float *)(v20 + 24) = freq;
    *(float *)(v20 + 28) = fade1;
    *(float *)(v20 + 32) = fade2;
    *(float *)(v20 + 36) = currDist;
  }
}


// ========================================================================
// ?AddDrop@idWaterSurfaceSim@@QAAXIIMM@Z
// EA  : 0x828902C0
// RVA : 0x008902C0
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::AddDrop(idWaterSurfaceSim *this, int xpos, int ypos, double radius, double mag)
{
  int numDisturbances; // r11
  int currentDeferred; // r10
  waterDisturbanceParms_t *v7; // r11

  if ( this->visible )
  {
    numDisturbances = this->numDisturbances;
    if ( numDisturbances < 100 )
    {
      currentDeferred = this->currentDeferred;
      this->numDisturbances = numDisturbances + 1;
      v7 = &this->waterDisturbances[currentDeferred].list[numDisturbances];
      v7->gridX = xpos;
      v7->gridY = ypos;
      v7->parms.x = mag;
      v7->radius = radius;
      v7->type = WATER_DISTURBANCE_TYPE_DROPLET;
    }
  }
}


// ========================================================================
// ?AddWave@idWaterSurfaceSim@@QAAXABVidVec2@@MMMM@Z
// EA  : 0x82890320
// RVA : 0x00890320
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::AddWave(
        idWaterSurfaceSim *this,
        const idVec2 *waveDir,
        double freq,
        double phase,
        double amp,
        double waveExp)
{
  int numDisturbances; // r11
  int currentDeferred; // r8
  waterDisturbanceParms_t *v8; // r11

  if ( this->visible )
  {
    numDisturbances = this->numDisturbances;
    if ( numDisturbances < 100 )
    {
      currentDeferred = this->currentDeferred;
      this->numDisturbances = numDisturbances + 1;
      v8 = &this->waterDisturbances[currentDeferred].list[numDisturbances];
      v8->loc = *waveDir;
      v8->type = WATER_DISTURBANCE_TYPE_WAVE;
      v8->parms.y = freq;
      v8->parms.z = phase;
      v8->parms.w = waveExp;
      v8->parms.x = amp;
    }
  }
}


// ========================================================================
// ?SetSimulationParms@idWaterSurfaceSim@@QAAXIIABVidVec4@@@Z
// EA  : 0x82890390
// RVA : 0x00890390
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::SetSimulationParms(
        idWaterSurfaceSim *this,
        int gridX,
        int gridY,
        const idVec4 *parms)
{
  unsigned __int8 v6; // r11
  int v7; // r8
  unsigned __int8 v8; // r11
  int v9; // r9
  unsigned __int8 v10; // r11
  int v11; // r10
  int v12; // r11
  int v13; // [sp+50h] [-30h] BYREF
  int v15; // [sp+5Ch] [-24h]

  GridPosToBlockLoc(gridX, gridY, numBlocksX: this->numBlocksX, numBlocksY: this->numBlocksY, blockPos: &v13);
  v15 = (int)(float)(parms->z * (float)255.0);
  v6 = v15;
  if ( v15 >= 0 )
  {
    if ( v15 > 255 )
      v6 = -1;
  }
  else
  {
    v6 = 0;
  }
  v7 = v6;
  v15 = (int)(float)(parms->x * (float)255.0);
  v8 = v15;
  if ( v15 >= 0 )
  {
    if ( v15 > 255 )
      v8 = -1;
  }
  else
  {
    v8 = 0;
  }
  v9 = v8;
  v15 = (int)(float)(parms->y * (float)255.0);
  v10 = v15;
  if ( v15 >= 0 )
  {
    if ( v15 > 255 )
      v10 = -1;
  }
  else
  {
    v10 = 0;
  }
  v11 = v10;
  v15 = (int)(float)(parms->w * (float)255.0);
  if ( v15 >= 0 )
  {
    if ( v15 <= 255 )
      v12 = (unsigned __int8)v15;
    else
      v12 = 255;
  }
  else
  {
    v12 = 0;
  }
  this->simulateParms.list[v13] = (((((v12 << 8) & 0xFF00 | v11) << 8) | v9) << 8) | v7;
}


// ========================================================================
// ?ApplyRadiusEffect@idWaterSurfaceSim@@QAAXABVidVec3@@PBVidRenderModel@@MM@Z
// EA  : 0x828904F8
// RVA : 0x008904F8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::ApplyRadiusEffect(
        idWaterSurfaceSim *this,
        const idVec3 *pos,
        idRenderModel *rmod,
        double radius,
        double fade)
{
  float y; // r9
  float z; // r8
  double v10; // fp25
  double v11; // fp24
  long double v12; // fp2
  long double v13; // fp2
  double v14; // fp6
  int v15; // r29
  long double v16; // fp2
  double v17; // fp31
  int v18; // r30
  long double v19; // fp2
  signed int v20; // r9
  int v21; // r11
  int v22; // r25
  signed int v23; // r9
  signed int v24; // r26
  signed int v25; // r27
  int v26; // r28
  __int64 v27; // r11
  int v28; // r30
  double v29; // fp23
  double v30; // fp13
  double v31; // fp9
  double v32; // fp30
  __int64 v34; // r8
  unsigned __int8 y_low; // r29
  int v37; // [sp+50h] [-D0h] BYREF
  int v38; // [sp+58h] [-C8h] BYREF
  int v39; // [sp+5Ch] [-C4h]
  __int64 v40; // [sp+60h] [-C0h]
  __int64 v41; // [sp+68h] [-B8h]
  idVec3 v42; // [sp+70h] [-B0h] BYREF
  idVec3 v43; // [sp+80h] [-A0h] BYREF

  y = pos->y;
  z = pos->z;
  v43.x = pos->x;
  v43.y = y;
  v43.z = z;
  idRenderModel::GlobalPointToLocal(this: rmod, in: &v43, out: &v42);
  v10 = (float)(v42.x - this->origin.x);
  v11 = (float)(v42.y - this->origin.y);
  *(double *)&v12 = (float)((float)((float)(v42.x - this->origin.x) / this->spacing) + (float)0.5);
  v13 = floor(x: v12);
  v14 = (float)((float)v11 / this->spacing);
  v39 = (int)(float)*(double *)&v13;
  v15 = v39;
  *(double *)&v13 = (float)((float)v14 + (float)0.5);
  v16 = floor(x: v13);
  *((double *)&v16 + 1) = (float)((float)radius / this->spacing);
  v17 = (float)((float)radius * (float)radius);
  v39 = (int)(float)*(double *)&v16;
  v18 = v39;
  *(double *)&v16 = (float)((float)*((double *)&v16 + 1) + (float)0.5);
  v19 = floor(x: v16);
  v20 = this->height - 1;
  v39 = (int)(float)*(double *)&v19;
  v21 = v18 - v39;
  if ( v18 - v39 >= 1 )
  {
    if ( v21 > v20 )
      v21 = v20;
  }
  else
  {
    v21 = 1;
  }
  if ( v39 + v18 >= 1 )
  {
    v22 = v20;
    if ( v39 + v18 <= v20 )
      v22 = v39 + v18;
  }
  else
  {
    v22 = 1;
  }
  v23 = this->width - 1;
  if ( v15 - v39 >= 1 )
  {
    v24 = this->width - 1;
    if ( v15 - v39 <= v23 )
      v24 = v15 - v39;
  }
  else
  {
    v24 = 1;
  }
  if ( v39 + v15 >= 1 )
  {
    v25 = this->width - 1;
    if ( v39 + v15 <= v23 )
      v25 = v39 + v15;
  }
  else
  {
    v25 = 1;
  }
  v26 = v21;
  if ( v21 < v22 )
  {
    HIDWORD(v27) = 0x82000000;
    do
    {
      v28 = v24;
      if ( v24 < v25 )
      {
        LODWORD(v27) = v26;
        v40 = v27;
        v29 = (float)v27;
        do
        {
          LODWORD(v27) = v28;
          v30 = (float)((float)((float)v29 * this->spacing) - (float)v11);
          v31 = (float)((float)((float)v27 * this->spacing) - (float)v10);
          v41 = v27;
          v32 = (float)((float)((float)v30 * (float)v30) + (float)((float)v31 * (float)v31));
          if ( v32 < v17 )
          {
            GridPosToBlockLoc(
              gridX: v28,
              gridY: v26,
              numBlocksX: this->numBlocksX,
              numBlocksY: this->numBlocksY,
              blockPos: &v37);
            _FP0 = (float)((float)v17 - (float)v32);
            LODWORD(v34) = this->vertGradient.list[v37];
            __asm { fsel      f13, f0, f0, f28 }
            *(_QWORD *)&v42.x = v34;
            LODWORD(v43.y) = (int)(float)((float)((float)((float)v34 * (float)0.0039215689)
                                                - (float)((float)((float)_FP13 / (float)v17) * (float)fade))
                                        * (float)255.0);
            if ( v43.y >= 0.0 )
            {
              y_low = -1;
              if ( SLODWORD(v43.y) <= 255 )
                y_low = LOBYTE(v43.y);
            }
            else
            {
              y_low = 0;
            }
            GridPosToBlockLoc(
              gridX: v28,
              gridY: v26,
              numBlocksX: this->numBlocksX,
              numBlocksY: this->numBlocksY,
              blockPos: &v38);
            HIDWORD(v27) = v38;
            this->vertGradient.list[v38] = y_low;
          }
          ++v28;
        }
        while ( v28 < v25 );
      }
      ++v26;
    }
    while ( v26 < v22 );
  }
}


// ========================================================================
// ?SetupLocalPos@idWaterSurfaceSim@@AAAXAAVidVec3@@HHPBM@Z
// EA  : 0x828907A0
// RVA : 0x008907A0
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::SetupLocalPos(
        idWaterSurfaceSim *this,
        idVec3 *result,
        __int64 gridY,
        const float *prevHM,
        __int64 a5)
{
  double spacing; // fp0
  __int64 v8; // [sp+50h] [-20h] BYREF

  LODWORD(a5) = HIDWORD(gridY);
  spacing = this->spacing;
  v8 = HIDWORD(gridY);
  result->x = (float)a5 * (float)spacing;
  result->y = (float)gridY * this->spacing;
  GridPosToBlockLoc(
    gridX: SHIDWORD(gridY),
    gridY,
    numBlocksX: this->numBlocksX,
    numBlocksY: this->numBlocksY,
    blockPos: (int *)&v8);
  result->z = prevHM[HIDWORD(v8)];
}


// ========================================================================
// ?ClearRadiusEffects@idWaterSurfaceSim@@QAAXXZ
// EA  : 0x82890848
// RVA : 0x00890848
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::ClearRadiusEffects(idWaterSurfaceSim *this)
{
  memset(Dst: this->vertGradient.list, Val: 255, Size: this->vertGradient.size);
}


// ========================================================================
// ?GetSurfacePositionAtPoint@idWaterSurfaceSim@@QAA_NAAVidVec3@@PAVidRenderModelWaterSurface@@AAM0@Z
// EA  : 0x82890858
// RVA : 0x00890858
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idWaterSurfaceSim::GetSurfacePositionAtPoint(
        idWaterSurfaceSim *this,
        idVec3 *pos,
        idRenderModelWaterSurface *waterSurfaceModel,
        float *retWaveHeight,
        idVec3 *normal)
{
  idVec3 *p_origin; // r27
  double v11; // fp25
  double v12; // fp26
  double v13; // fp28
  double v14; // fp30
  long double v15; // fp2
  long double v16; // fp2
  double v17; // fp7
  signed int v18; // r28
  __int64 v19; // r11
  __int64 v20; // r26
  double v21; // fp29
  double v22; // fp27
  __int64 v23; // r10
  long double v24; // fp2
  double v25; // fp10
  signed int v26; // r30
  int v27; // r11
  __int64 v28; // r11
  char *v29; // r4
  __int64 v30; // r10
  const float *v31; // r29
  bool v32; // r11
  double v33; // fp30
  const float *v34; // r7
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r10
  const float *v38; // r7
  idWaterSurfaceSim *v39; // r3
  __int64 v40; // r6
  __int64 v41; // r10
  double z; // fp11
  double x; // fp10
  double v44; // fp12
  double v45; // fp6
  double y; // fp9
  double v47; // fp1
  double v48; // fp5
  double v49; // fp2
  double v50; // fp4
  double v51; // fp3
  double v52; // fp30
  double v53; // fp2
  double v54; // fp1
  double v57; // fp6
  double v58; // fp6
  double v59; // fp12
  double v60; // fp13
  double v61; // fp0
  double v62; // fp6
  double v63; // fp3
  double v64; // fp10
  double v65; // fp0
  int v66; // r31
  double v67; // fp4
  double v68; // fp1
  float *p_z; // r11
  double v70; // fp10
  double v71; // fp8
  double v72; // fp6
  __int64 v74; // [sp+50h] [-110h]
  idVec3 v75[2]; // [sp+58h] [-108h] BYREF
  idVec3 v76; // [sp+70h] [-F0h] BYREF
  idVec3 v77; // [sp+7Ch] [-E4h] BYREF
  idVec3 v78[10]; // [sp+88h] [-D8h] BYREF

  p_origin = &this->origin;
  idRenderModel::GlobalPointToLocal(this: waterSurfaceModel, in: pos, out: v75);
  v11 = (float)(v75[0].x - this->origin.x);
  v12 = (float)(v75[0].y - this->origin.y);
  v13 = (float)(v75[0].z - this->origin.z);
  v14 = (float)((float)(v75[0].x - this->origin.x) / this->spacing);
  *(double *)&v15 = (float)((float)((float)(v75[0].x - this->origin.x) / this->spacing) + (float)0.5);
  v16 = floor(x: v15);
  v17 = (float)*(double *)&v16;
  v18 = this->width - 1;
  LODWORD(v19) = (int)v17;
  if ( (int)v17 < v18 )
  {
    HIDWORD(v19) = (int)v17;
    if ( (float)*(__int64 *)((char *)&v19 + 4) <= v14 )
    {
      v18 = (int)v17;
      HIDWORD(v20) = v19 + 1;
    }
    else
    {
      v18 = v19 - 1;
      HIDWORD(v20) = (int)v17;
    }
  }
  else
  {
    HIDWORD(v20) = this->width - 2;
  }
  LODWORD(v19) = v18;
  v21 = (float)((float)v12 / this->spacing);
  *(double *)&v16 = (float)((float)((float)v12 / this->spacing) + (float)0.5);
  v22 = (float)((float)v14 - (float)v19);
  v24 = floor(x: v16);
  v25 = (float)*(double *)&v24;
  v26 = this->height - 1;
  v27 = (int)v25;
  if ( (int)v25 < v26 )
  {
    LODWORD(v23) = (int)v25;
    if ( (float)v23 <= v21 )
    {
      v26 = (int)v25;
      LODWORD(v20) = v27 + 1;
    }
    else
    {
      v26 = v27 - 1;
      LODWORD(v20) = (int)v25;
    }
  }
  else
  {
    LODWORD(v20) = this->height - 2;
  }
  LODWORD(v28) = v26;
  HIDWORD(v28) = this->currentDeferred;
  v74 = v28;
  v29 = (char *)this + 16 * HIDWORD(v28);
  LODWORD(v30) = _cntlzw(v18 % 2);
  HIDWORD(v30) = v26 % 2;
  v31 = *((const float **)v29 + 25);
  v32 = (v30 & 0x20) != 0;
  v33 = (float)((float)v21 - (float)v74);
  if ( v26 % 2 != 0 )
  {
    LODWORD(v30) = _cntlzw((v30 & 0x20) != 0);
    v32 = (v30 & 0x20) != 0;
  }
  v34 = *((const float **)v29 + 25);
  LODWORD(v35) = v26;
  if ( v32 )
  {
    HIDWORD(v35) = v18;
    idWaterSurfaceSim::SetupLocalPos(this, result: &v76, gridY: v35, prevHM: v34, a5: v30);
    idWaterSurfaceSim::SetupLocalPos(this, result: &v77, gridY: v20, prevHM: v31, a5: v36);
    v38 = v31;
    v39 = this;
    if ( v22 <= v33 )
    {
      v40 = __PAIR64__(v18, v20);
      goto LABEL_21;
    }
    LODWORD(v40) = v26;
  }
  else
  {
    HIDWORD(v35) = HIDWORD(v20);
    idWaterSurfaceSim::SetupLocalPos(this, result: &v76, gridY: v35, prevHM: v34, a5: v30);
    idWaterSurfaceSim::SetupLocalPos(this, result: &v77, gridY: __SPAIR64__(v18, v20), prevHM: v31, a5: v41);
    v38 = v31;
    v39 = this;
    if ( (float)((float)1.0 - (float)v22) > v33 )
    {
      v40 = __PAIR64__(v18, v26);
      goto LABEL_21;
    }
    LODWORD(v40) = v20;
  }
  HIDWORD(v40) = HIDWORD(v20);
LABEL_21:
  idWaterSurfaceSim::SetupLocalPos(this: v39, result: v78, gridY: v40, prevHM: v38, a5: v37);
  z = v78[0].z;
  x = v78[0].x;
  v44 = (float)(v77.z - v78[0].z);
  v45 = (float)(v76.x - v78[0].x);
  y = v78[0].y;
  v47 = (float)(v76.y - v78[0].y);
  v48 = (float)(v76.z - v78[0].z);
  v49 = (float)(v77.y - v78[0].y);
  v50 = (float)((float)(v76.y - v78[0].y) * (float)(v77.x - v78[0].x));
  v51 = (float)((float)((float)(v76.z - v78[0].z) * (float)(v77.x - v78[0].x))
              - (float)((float)(v77.z - v78[0].z) * (float)(v76.x - v78[0].x)));
  normal->y = (float)((float)(v76.z - v78[0].z) * (float)(v77.x - v78[0].x))
            - (float)((float)(v77.z - v78[0].z) * (float)(v76.x - v78[0].x));
  v52 = (float)((float)v48 * (float)v49);
  v53 = (float)((float)((float)v49 * (float)v45) - (float)v50);
  normal->z = v53;
  v54 = (float)((float)((float)v47 * (float)v44) - (float)v52);
  normal->x = v54;
  _FP4 = (float)((float)((float)((float)v54 * (float)v54)
                       + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f4, f5, f13 }
  v57 = __frsqrte(_FP13);
  v58 = (float)((float)-(float)((float)((float)((float)v57
                                              * (float)((float)((float)((float)v54 * (float)v54)
                                                              + (float)((float)((float)v53 * (float)v53)
                                                                      + (float)((float)v51 * (float)v51)))
                                                      * (float)0.5))
                                      * (float)v57)
                              - (float)1.5)
              * (float)v57);
  v59 = (float)((float)v51
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                              * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v58)
                                                                              - (float)1.5)
                                                              * (float)v58)
                                                      * (float)((float)((float)((float)v54 * (float)v54)
                                                                      + (float)((float)((float)v53 * (float)v53)
                                                                              + (float)((float)v51 * (float)v51)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v58
                                                                                      * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)v58)
                                                                      - (float)1.5)
                                                      * (float)v58))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v58
                                                              * (float)((float)((float)((float)v54 * (float)v54)
                                                                              + (float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)v51 * (float)v51)))
                                                                      * (float)0.5))
                                                      * (float)v58)
                                              - (float)1.5)
                              * (float)v58)));
  normal->y = (float)v51
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                            * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                    * (float)v58)
                                                                            - (float)1.5)
                                                            * (float)v58)
                                                    * (float)((float)((float)((float)v54 * (float)v54)
                                                                    + (float)((float)((float)v53 * (float)v53)
                                                                            + (float)((float)v51 * (float)v51)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v58
                                                                                    * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                            * (float)0.5))
                                                                            * (float)v58)
                                                                    - (float)1.5)
                                                    * (float)v58))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v58
                                                            * (float)((float)((float)((float)v54 * (float)v54)
                                                                            + (float)((float)((float)v53 * (float)v53)
                                                                                    + (float)((float)v51 * (float)v51)))
                                                                    * (float)0.5))
                                                    * (float)v58)
                                            - (float)1.5)
                            * (float)v58));
  v60 = (float)((float)v54
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                              * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v58)
                                                                              - (float)1.5)
                                                              * (float)v58)
                                                      * (float)((float)((float)((float)v54 * (float)v54)
                                                                      + (float)((float)((float)v53 * (float)v53)
                                                                              + (float)((float)v51 * (float)v51)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v58
                                                                                      * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)v58)
                                                                      - (float)1.5)
                                                      * (float)v58))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v58
                                                              * (float)((float)((float)((float)v54 * (float)v54)
                                                                              + (float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)v51 * (float)v51)))
                                                                      * (float)0.5))
                                                      * (float)v58)
                                              - (float)1.5)
                              * (float)v58)));
  normal->x = (float)v54
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                            * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                    * (float)v58)
                                                                            - (float)1.5)
                                                            * (float)v58)
                                                    * (float)((float)((float)((float)v54 * (float)v54)
                                                                    + (float)((float)((float)v53 * (float)v53)
                                                                            + (float)((float)v51 * (float)v51)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v58
                                                                                    * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                            * (float)0.5))
                                                                            * (float)v58)
                                                                    - (float)1.5)
                                                    * (float)v58))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v58
                                                            * (float)((float)((float)((float)v54 * (float)v54)
                                                                            + (float)((float)((float)v53 * (float)v53)
                                                                                    + (float)((float)v51 * (float)v51)))
                                                                    * (float)0.5))
                                                    * (float)v58)
                                            - (float)1.5)
                            * (float)v58));
  v61 = (float)((float)v53
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                              * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v58)
                                                                              - (float)1.5)
                                                              * (float)v58)
                                                      * (float)((float)((float)((float)v54 * (float)v54)
                                                                      + (float)((float)((float)v53 * (float)v53)
                                                                              + (float)((float)v51 * (float)v51)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v58
                                                                                      * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                              * (float)0.5))
                                                                              * (float)v58)
                                                                      - (float)1.5)
                                                      * (float)v58))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v58
                                                              * (float)((float)((float)((float)v54 * (float)v54)
                                                                              + (float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)v51 * (float)v51)))
                                                                      * (float)0.5))
                                                      * (float)v58)
                                              - (float)1.5)
                              * (float)v58)));
  normal->z = (float)v53
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                            * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                    * (float)v58)
                                                                            - (float)1.5)
                                                            * (float)v58)
                                                    * (float)((float)((float)((float)v54 * (float)v54)
                                                                    + (float)((float)((float)v53 * (float)v53)
                                                                            + (float)((float)v51 * (float)v51)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v58
                                                                                    * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51)))
                                                                                            * (float)0.5))
                                                                            * (float)v58)
                                                                    - (float)1.5)
                                                    * (float)v58))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v58
                                                            * (float)((float)((float)((float)v54 * (float)v54)
                                                                            + (float)((float)((float)v53 * (float)v53)
                                                                                    + (float)((float)v51 * (float)v51)))
                                                                    * (float)0.5))
                                                    * (float)v58)
                                            - (float)1.5)
                            * (float)v58));
  v63 = (float)((float)((float)v53
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58 * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                              * (float)v58)
                                                                                      - (float)1.5)
                                                                      * (float)v58)
                                                              * (float)((float)((float)((float)v54 * (float)v54)
                                                                              + (float)((float)((float)v53 * (float)v53)
                                                                                      + (float)((float)v51 * (float)v51)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v58
                                                                                              * (float)((float)((float)((float)v54 * (float)v54) + (float)((float)((float)v53 * (float)v53) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                      * (float)v58)
                                                                              - (float)1.5)
                                                              * (float)v58))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v58
                                                                      * (float)((float)((float)((float)v54 * (float)v54)
                                                                                      + (float)((float)((float)v53 * (float)v53)
                                                                                              + (float)((float)v51 * (float)v51)))
                                                                              * (float)0.5))
                                                              * (float)v58)
                                                      - (float)1.5)
                                      * (float)v58)))
              * vec3_up.z);
  v62 = vec3_up.z;
  v64 = (float)-(float)((float)((float)y * (float)v59)
                      + (float)((float)((float)x * (float)v60) + (float)((float)z * (float)v61)));
  if ( (float)((float)((float)v60 * vec3_up.x) + (float)((float)((float)v59 * vec3_up.y) + (float)v63)) == 0.0 )
    v65 = *(float *)&v74;
  else
    v65 = -(float)((float)((float)((float)((float)v60 * (float)v11)
                                 + (float)((float)((float)v59 * (float)v12)
                                         + (float)((float)v61 * (float)((float)v13 - (float)256.0))))
                         + (float)v64)
                 / (float)((float)((float)v60 * vec3_up.x) + (float)((float)((float)v59 * vec3_up.y) + (float)v63)));
  v75[0].x = (float)(vec3_up.x * (float)v65) + (float)v11;
  v75[0].y = (float)(vec3_up.y * (float)v65) + (float)v12;
  *retWaveHeight = (float)(vec3_up.z * (float)v65) + (float)((float)v13 - (float)256.0);
  v75[0].z = (float)((float)v62 * (float)v65) + (float)((float)v13 - (float)256.0);
  idRenderModel::LocalPointToGlobal(this: waterSurfaceModel, in: v75, out: pos);
  v66 = 0;
  v67 = pos->y;
  pos->x = pos->x + p_origin->x;
  v68 = pos->z;
  pos->y = p_origin->y + (float)v67;
  pos->z = p_origin->z + (float)v68;
  do
  {
    idRenderModel::LocalPointToGlobal(
      this: waterSurfaceModel,
      in: (idVec3 *)((char *)&v76 + v66 * 12),
      out: &v78[v66 + 2]);
    p_z = &v78[v66 + 2].z;
    v70 = p_origin->y;
    v71 = p_origin->z;
    v78[v66 + 2].x = v78[v66 + 2].x + p_origin->x;
    v72 = (float)(v78[v66 + 2].z + (float)v71);
    ++v66;
    *(p_z - 1) = *(p_z - 1) + (float)v70;
    *p_z = v72;
  }
  while ( v66 < 3 );
  return 1;
}


// ========================================================================
// ??1idWaterSurfaceSim@@QAA@XZ
// EA  : 0x82890D30
// RVA : 0x00890D30
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void __fastcall idWaterSurfaceSim::~idWaterSurfaceSim(idWaterSurfaceSim *this)
{
  int *p_num; // r30
  int i; // r27
  void *v4; // r4
  void *v5; // r4
  float *list; // r4
  unsigned int *v7; // r4
  unsigned __int8 *v8; // r4
  float *v9; // r4
  unsigned __int8 *v10; // r4
  unsigned int *v11; // r4

  p_num = &this->dummyBlock.num;
  for ( i = 2; i != 0; --i )
  {
    if ( *((_BYTE *)p_num - 21) == 0 || *((_BYTE *)p_num - 21) == 2 )
    {
      v4 = (void *)*(p_num - 9);
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      *(p_num - 9) = 0;
      *(p_num - 7) = 0;
    }
    *(p_num - 8) = 0;
    if ( *((_BYTE *)p_num + 27) == 0 || *((_BYTE *)p_num + 27) == 2 )
    {
      v5 = (void *)p_num[3];
      if ( v5 != nullptr )
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      p_num[3] = 0;
      p_num[5] = 0;
    }
    p_num += 4;
    *p_num = 0;
  }
  if ( this->dummyBlock.listStatic == 0 || this->dummyBlock.listStatic == 2 )
  {
    list = this->dummyBlock.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->dummyBlock.list = nullptr;
    this->dummyBlock.size = 0;
  }
  this->dummyBlock.num = 0;
  if ( this->simulateParms.listStatic == 0 || this->simulateParms.listStatic == 2 )
  {
    v7 = this->simulateParms.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->simulateParms.list = nullptr;
    this->simulateParms.size = 0;
  }
  this->simulateParms.num = 0;
  if ( this->vertGradient.listStatic == 0 || this->vertGradient.listStatic == 2 )
  {
    v8 = this->vertGradient.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->vertGradient.list = nullptr;
    this->vertGradient.size = 0;
  }
  this->vertGradient.num = 0;
  `eh vector destructor iterator'(
    ptr: this->waterDisturbances,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( this->dummyBlock.listStatic == 0 || this->dummyBlock.listStatic == 2 )
  {
    v9 = this->dummyBlock.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->dummyBlock.list = nullptr;
    this->dummyBlock.size = 0;
  }
  this->dummyBlock.num = 0;
  `eh vector destructor iterator'(
    ptr: this->waveHeight,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  if ( this->vertGradient.listStatic == 0 || this->vertGradient.listStatic == 2 )
  {
    v10 = this->vertGradient.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->vertGradient.list = nullptr;
    this->vertGradient.size = 0;
  }
  this->vertGradient.num = 0;
  if ( this->simulateParms.listStatic == 0 || this->simulateParms.listStatic == 2 )
  {
    v11 = this->simulateParms.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->simulateParms.list = nullptr;
    this->simulateParms.size = 0;
  }
  this->simulateParms.num = 0;
}


// ========================================================================
// __unwind$221819
// EA  : 0x82890F7C
// RVA : 0x00890F7C
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_221819()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 68));
}


// ========================================================================
// __unwind$221820
// EA  : 0x82890FA8
// RVA : 0x00890FA8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_221820()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 84));
}


// ========================================================================
// __unwind$221821_0
// EA  : 0x82890FD4
// RVA : 0x00890FD4
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_221821_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 100),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$221822_0
// EA  : 0x82891010
// RVA : 0x00891010
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_221822_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 132));
}


// ========================================================================
// __unwind$221823_1
// EA  : 0x8289103C
// RVA : 0x0089103C
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_221823_1()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 148),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ??0idWaterSurfaceSim@@QAA@ABVidBounds@@MMMM@Z
// EA  : 0x82891108
// RVA : 0x00891108
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

idWaterSurfaceSim *__fastcall idWaterSurfaceSim::idWaterSurfaceSim(
        idWaterSurfaceSim *this,
        const idBounds *bounds,
        double s,
        double damping,
        double speed,
        double timeStep)
{
  idList<int,5> *p_simulateParms; // r25
  idVec3 *p_origin; // r27
  long double v10; // fp2
  double x; // fp10
  double v12; // fp9
  double y; // fp12
  double v14; // fp11
  double z; // fp0
  double v16; // fp13
  double v17; // fp0
  double v18; // fp13
  long double v19; // fp2
  double v20; // fp31
  double v22; // fp30
  long double v24; // fp2
  double v25; // fp0
  long double v26; // fp2
  int *p_size; // r28
  int v28; // r26
  signed int v29; // r8
  signed int v30; // r4
  int v31; // r27
  bfx::BinaryReplayLogOut *v32; // r3
  char *v33; // r3
  char v34; // r11
  int v35; // r11
  int v36; // r11
  char v38; // [sp+50h] [-80h] BYREF
  float v39[2]; // [sp+54h] [-7Ch] BYREF
  unsigned int v40; // [sp+5Ch] [-74h]

  this->damping = damping;
  this->speed = speed;
  this->timeStep = timeStep;
  this->spacing = s;
  this->width = 0;
  this->visible = false;
  this->height = 0;
  p_simulateParms = (idList<int,5> *)&this->simulateParms;
  this->origin = vec3_origin;
  p_origin = &this->origin;
  this->rnd.seed = 0;
  this->currentDeferred = 0;
  this->numDisturbances = 0;
  this->allocWidth = 0;
  this->allocHeight = 0;
  this->numBlocksX = 0;
  this->numBlocksY = 0;
  this->simulateParms.list = nullptr;
  this->simulateParms.granularity = 0;
  this->simulateParms.memTag = 54;
  this->simulateParms.listStatic = 0;
  this->simulateParms.size = 0;
  this->simulateParms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->simulateParms);
  this->vertGradient.list = nullptr;
  this->vertGradient.granularity = 0;
  this->vertGradient.memTag = 54;
  this->vertGradient.listStatic = 0;
  this->vertGradient.size = 0;
  this->vertGradient.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertGradient);
  `eh vector constructor iterator'(
    ptr: this->waveHeight,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<float,54>::idList<float,54>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->dummyBlock.list = nullptr;
  this->dummyBlock.granularity = 0;
  this->dummyBlock.memTag = 54;
  this->dummyBlock.listStatic = 0;
  this->dummyBlock.size = 0;
  this->dummyBlock.num = 0;
  LODWORD(v39[0]) = &this->dummyBlock;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dummyBlock);
  `eh vector constructor iterator'(
    ptr: this->waterDisturbances,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idList<float,54>::idList<float,54>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  x = bounds->b[0].x;
  v12 = bounds->b[1].x;
  v39[0] = bounds->b[1].x;
  if ( x >= v12
    || (y = bounds->b[0].y, v14 = bounds->b[1].y, v39[0] = bounds->b[1].y, y >= v14)
    || (z = bounds->b[0].z, v16 = bounds->b[1].z, v39[0] = bounds->b[1].z, z >= v16)
    || (v39[0] = z,
        (float)((float)((float)((float)v16 - (float)z) * (float)((float)v14 - (float)y)) * (float)((float)v12 - (float)x)) < 0.0099999998) )
  {
    idLib::Warning(fmt: "Dynamic water has an invalid bounds");
  }
  v17 = bounds->b[0].x;
  LODWORD(v39[0]) = p_origin;
  v18 = bounds->b[1].z;
  p_origin->y = bounds->b[0].y;
  p_origin->z = v18;
  p_origin->x = v17;
  *(double *)&v10 = (float)(bounds->b[1].x - bounds->b[0].x);
  v19 = ceil(x: v10);
  v20 = (float)*(double *)&v19;
  *(double *)&v19 = (float)(bounds->b[1].y - bounds->b[0].y);
  _FP2 = ceil(x: v19);
  v22 = (float)*(double *)&_FP2;
  _FP3 = (float)(this->spacing
               - (float)__fsqrts((float)((float)((float)*(double *)&_FP2 * (float)v20) * (float)0.000015259022)));
  __asm { fsel      f2, f3, f7, f4# x }
  this->spacing = *((double *)&_FP2 + 1);
  *(double *)&_FP2 = (float)((float)v20 / (float)*((double *)&_FP2 + 1));
  v24 = floor(x: _FP2);
  v25 = (float)*(double *)&v24;
  *(double *)&v24 = (float)((float)v22 / this->spacing);
  this->width = (int)v25;
  v26 = floor(x: v24);
  p_size = &this->waterDisturbances[0].size;
  v28 = 2;
  v29 = (this->width + 15) & 0xFFFFFFF0;
  v39[0] = 0.0;
  this->allocWidth = v29;
  v40 = (int)(float)*(double *)&v26;
  v30 = (v40 + 15) & 0xFFFFFFF0;
  this->height = v40;
  this->numBlocksX = v29 >> 4;
  this->allocHeight = v30;
  v31 = v29 * v30;
  this->numBlocksY = v30 >> 4;
  do
  {
    v32 = (bfx::BinaryReplayLogOut *)idList<float,17>::SetNum(
                                       this: (idList<float,32> *)(p_size - 14),
                                       newNum: v31,
                                       initValue: v39);
    if ( *p_size < 100 )
    {
      if ( *((_BYTE *)p_size + 7) == 0 )
      {
        if ( *p_size > 0 || *((_WORD *)p_size + 2) == 100 )
          idPhysics_StaticMulti::UpdateTime(this: v32);
        v33 = idListArrayResize<waterDisturbanceParms_t>(
                voldptr: (_BYTE *)*(p_size - 2),
                oldNum: *p_size,
                newNum: 100,
                tag: (memTag_t)*((unsigned __int8 *)p_size + 6),
                zeroBuffer: false);
        *(p_size - 2) = (int)v33;
        if ( v33 == nullptr )
        {
          v34 = 0;
          goto LABEL_17;
        }
        v35 = *(p_size - 1);
        *p_size = 100;
        if ( v35 > 100 )
          *(p_size - 1) = 100;
      }
      v34 = 1;
LABEL_17:
      if ( v34 == 0 )
        goto LABEL_21;
    }
    v36 = *p_size;
    if ( *p_size > 100 )
      v36 = 100;
    *(p_size - 1) = v36;
LABEL_21:
    --v28;
    p_size += 4;
  }
  while ( v28 != 0 );
  v39[0] = 0.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&this->dummyBlock, newNum: 256, initValue: v39);
  v39[0] = 0.0;
  idList<idRenderModelCommitted *,5>::SetNum(this: p_simulateParms, newNum: v31, initValue: (const int *)v39);
  v38 = -1;
  idList<bool,5>::SetNum(this: (idList<bool,5> *)&this->vertGradient, newNum: v31, initValue: (bool *)&v38);
  return this;
}


// ========================================================================
// __unwind$222157
// EA  : 0x828914D8
// RVA : 0x008914D8
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_222157()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 68));
}


// ========================================================================
// __unwind$222158
// EA  : 0x82891504
// RVA : 0x00891504
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_222158()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 84));
}


// ========================================================================
// __unwind$222159
// EA  : 0x82891530
// RVA : 0x00891530
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_222159()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 208 + 228) + 100),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$222160
// EA  : 0x8289156C
// RVA : 0x0089156C
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_222160()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 132));
}


// ========================================================================
// __unwind$222161
// EA  : 0x82891598
// RVA : 0x00891598
// PDB : w:\tech5\engine\models\water\watersurfacesim.cpp
// ========================================================================

void _unwind_222161()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 208 + 228) + 148),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}

