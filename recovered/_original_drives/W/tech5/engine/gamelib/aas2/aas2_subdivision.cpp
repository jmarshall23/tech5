
// ========================================================================
// ?GetAreaCells@idAAS2Local@@UBA_NHHAAH0@Z
// EA  : 0x826B88C8
// RVA : 0x006B88C8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_subdivision.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAreaCells(idAAS2Local *this, int areaNum, signed int subSize, int *subx, int *suby)
{
  float *v8; // r3
  double v10; // fp12
  double v11; // fp9
  char v12; // [sp+60h] [-40h] BYREF

  if ( this->file == nullptr || areaNum <= 0 )
    return 0;
  v8 = (float *)idAAS2File::AreaBounds(this: (idAAS2File *)&v12, result: (idBounds *)this->file, areaNum);
  __twllei(subSize, 0);
  __twllei(subSize, 0);
  v10 = (float)(v8[4] - v8[1]);
  v11 = (float)(v8[3] - *v8);
  *subx = (int)v11 / subSize + 1;
  __twlgei(subSize & ~(__ROL4__((int)v11, 1) - 1), 0xFFFFFFFF);
  __twlgei(subSize & ~(__ROL4__((int)v10, 1) - 1), 0xFFFFFFFF);
  *suby = (int)v10 / subSize + 1;
  return 1;
}


// ========================================================================
// ?WorldPosToCellPos@idAAS2Local@@UBA_NHHABVidVec3@@AAH1@Z
// EA  : 0x826B8990
// RVA : 0x006B8990
// PDB : w:\tech5\engine\gamelib\aas2\aas2_subdivision.cpp
// ========================================================================

int __fastcall idAAS2Local::WorldPosToCellPos(
        idAAS2Local *this,
        int areaNum,
        unsigned int subSize,
        const idVec3 *origin,
        int *subx,
        int *suby)
{
  float *v10; // r3
  double v12; // fp3
  char v13; // [sp+60h] [-40h] BYREF

  if ( this->file == nullptr || areaNum <= 0 )
    return 0;
  v10 = (float *)idAAS2File::AreaBounds(this: (idAAS2File *)&v13, result: (idBounds *)this->file, areaNum);
  *subx = (int)(float)((float)(origin->x - *v10) / (float)__SPAIR64__((unsigned int)v10, subSize));
  v12 = (float)((float)(origin->y - v10[1]) / (float)__SPAIR64__((unsigned int)v10, subSize));
  *suby = (int)v12;
  return 1;
}


// ========================================================================
// ?CellPosToWorldPos@idAAS2Local@@UBA_NHHHHAAVidVec3@@_N@Z
// EA  : 0x826B8A30
// RVA : 0x006B8A30
// PDB : w:\tech5\engine\gamelib\aas2\aas2_subdivision.cpp
// ========================================================================

int __fastcall idAAS2Local::CellPosToWorldPos(
        idAAS2Local *this,
        int areaNum,
        const int subSize,
        const int subx,
        const int suby,
        idVec3 *worldPos,
        const bool findZ)
{
  double v11; // fp13
  double v12; // fp12
  __int64 v13; // r10
  __int64 v14; // r8
  float v16[16]; // [sp+60h] [-40h] BYREF

  if ( this->file == nullptr || areaNum <= 0 )
    return 0;
  idAAS2File::AreaBounds(this: (idAAS2File *)v16, result: (idBounds *)this->file, areaNum);
  v11 = v16[0];
  v12 = v16[1];
  worldPos->z = v16[5];
  HIDWORD(v13) = subSize * subx;
  LODWORD(v13) = subSize * suby;
  LODWORD(v14) = subSize * subx;
  worldPos->y = (float)v13 + (float)v12;
  worldPos->x = (float)v14 + (float)v11;
  return 1;
}

