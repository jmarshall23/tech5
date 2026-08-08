
// ========================================================================
// ?GetNumCoverPoints@idAAS2Local@@UBAHXZ
// EA  : 0x826B82E8
// RVA : 0x006B82E8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumCoverPoints(idAAS2Local *this)
{
  return this->file->cover.num;
}


// ========================================================================
// ?GetCoverPoint@idAAS2Local@@UBAABUaas2Cover_t@@H@Z
// EA  : 0x826B82F8
// RVA : 0x006B82F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

const aas2Cover_t *__fastcall idAAS2Local::GetCoverPoint(idAAS2Local *this, const int coverIndex)
{
  return &this->file->cover.list[coverIndex];
}


// ========================================================================
// ?GetNumAreaCoverPoints@idAAS2Local@@UBAHH@Z
// EA  : 0x826B8310
// RVA : 0x006B8310
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumAreaCoverPoints(idAAS2Local *this, const int areaNum)
{
  if ( areaNum > 0 )
    return this->file->areas.list[areaNum].numCover;
  else
    return 0;
}


// ========================================================================
// ?GetAreaCoverPoints@idAAS2Local@@UBAHHPAHHAAH@Z
// EA  : 0x826B8340
// RVA : 0x006B8340
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::GetAreaCoverPoints(
        idAAS2Local *this,
        const int areaNum,
        int *coverPoints,
        int maxCover,
        int *numCover)
{
  int v5; // r30
  aas2Area_t *v11; // r29

  v5 = 0;
  *numCover = 0;
  if ( areaNum <= 0 )
    return 0;
  v11 = &this->file->areas.list[areaNum];
  if ( v11->numCover != 0 )
  {
    do
    {
      if ( *numCover >= maxCover )
        idLib::Warning(fmt: "idAAS2Local::GetAreaCoverPoints - search list overflowed.");
      else
        coverPoints[(*numCover)++] = this->file->areaCoverIndex.list[v11->firstCover + v5];
      ++v5;
    }
    while ( v5 < v11->numCover );
  }
  return *numCover;
}


// ========================================================================
// ?FindCoverPoints_Internal@idAAS2Local@@ABAXHABVidVec3@@ABVidBounds@@MHHHPAHHAAH@Z
// EA  : 0x826B8408
// RVA : 0x006B8408
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

void __fastcall idAAS2Local::FindCoverPoints_Internal(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *origin,
        const idBounds *bounds,
        double maxDistSqr,
        const int requiredFlags,
        const int excludeFlags,
        const int travelFlags,
        unsigned int coverPoints,
        const int maxCover,
        int *numCover,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        _DWORD *a33)
{
  int v41; // r10
  int v42; // r3
  int v43; // r11
  int v44; // r12
  int v45; // r4
  int v49; // r12
  int v50; // r11
  int v51; // r24
  int v52; // r3
  int *v54; // r23
  int v56; // r7
  aas2Area_t *v57; // r8
  idAAS2File *file; // r10
  int v59; // r9
  int v60; // r11
  double v61; // fp12
  double v62; // fp6
  int value; // r11
  _DWORD *v64; // r6
  int v65; // r7
  aas2Reachability_t *v66; // r10
  __int16 *v67; // r11
  __int16 v68; // r9
  _DWORD back_chain[20]; // [sp+0h] [-D0h]
  _DWORD v70[2]; // [sp+50h] [-80h] BYREF
  char v71; // [sp+CFh] [-1h] BYREF

  _R30 = bounds;
  this->GetNumAreas(this);
  v42 = ((int (*)(void))RtlCheckStack12)();
  v43 = 0;
  for ( *(_DWORD *)((char *)back_chain + v44) = back_chain[0]; v43 < v41; v43 += 128 )
    __asm { dcbz128   r11, r4 }
  ((void (__fastcall *)(int, unsigned int))RtlCheckStack12)(a1: v42, a2: (unsigned int)&v71 & 0xFFFFFF80);
  _R9 = 16;
  __asm { vspltisw128 v63, 0 }
  _R8 = 24;
  _R7 = 8;
  *(_DWORD *)((char *)back_chain + v49) = back_chain[0];
  v50 = startAreaNum;
  v51 = 0;
  v52 = 1;
  _R5 = &STACK[0x1450];
  v54 = v70;
  v70[0] = startAreaNum;
  *(_BYTE *)(v45 + startAreaNum) = 1;
  __asm
  {
    lvrx128   v62, r9, r30
    lvlx128   v59, r0, r30
  }
  __asm
  {
    lvrx128   v61, r8, r30
    lvlx128   v60, r7, r30
    vor128    v57, v92, v61
    vor128    v58, v91, v62
    vsldoi128 v56, v89, v63, 4
  }
  __asm
  {
    vrlimi128 v58, v63, 1, 0
    vrfip128  v54, v56
    vrfim128  v55, v58
    vcfpsxws128 v52, v54, 0
    vcfpsxws128 v53, v55, 0
    vpkswss128 v51, v85, v52
    stvx128   v51, r0, r5
  }
  do
  {
    if ( v52 >= 1280 )
      return;
    v56 = 0;
    v57 = &this->file->areas.list[v50];
    if ( v57->numCover != 0 )
    {
      do
      {
        file = this->file;
        v59 = file->areaCoverIndex.list[v57->firstCover + v56];
        v60 = (int)&file->cover.list[v59];
        if ( (excludeFlags == 0 || (*(__int16 *)(v60 + 26) & excludeFlags) != 0)
          && (*(__int16 *)(v60 + 26) & travelFlags) == 0 )
        {
          v61 = (float)(*(float *)(v60 + 4) - origin->y);
          v62 = (float)(*(float *)(v60 + 8) - origin->z);
          if ( (float)((float)((float)v62 * (float)v62)
                     + (float)((float)((float)(*(float *)v60 - origin->x) * (float)(*(float *)v60 - origin->x))
                             + (float)((float)v61 * (float)v61))) < maxDistSqr )
          {
            if ( *a33 >= a31 )
            {
              idLib::Warning(fmt: "idAAS2Local::FindCoverPoints_Internal - search list overflowed.");
              return;
            }
            *(_DWORD *)(4 * (*a33)++ + a29) = v59;
          }
        }
        ++v56;
      }
      while ( v56 < v57->numCover );
    }
    value = v57->reach.value;
    if ( value >= 0 )
    {
      v64 = &v70[v52 - 1];
      do
      {
        v65 = value;
        v66 = &this->file->reachabilities.list[value];
        if ( *(_BYTE *)(v66->toAreaNum + v45) != 1 && (v66->travelFlags & coverPoints) != 0 )
        {
          *(_BYTE *)(v66->toAreaNum + v45) = 1;
          v67 = &this->file->areaBounds.list->min[2 * v66->toAreaNum + 2 * __ROL4__(v66->toAreaNum, 1)];
          if ( SHIWORD(STACK[0x1450]) <= v67[3]
            && SHIWORD(STACK[0x1458]) >= *v67
            && SHIWORD(STACK[0x1452]) <= v67[4]
            && SHIWORD(STACK[0x145A]) >= v67[1]
            && SHIWORD(STACK[0x1454]) <= v67[5]
            && SHIWORD(STACK[0x145C]) >= v67[2] )
          {
            ++v52;
            *++v64 = v66->toAreaNum;
            if ( v52 >= 1280 )
              break;
          }
        }
        v68 = this->file->reachabilities.list[v65].next.value;
        value = v68;
      }
      while ( v68 >= 0 );
    }
    ++v51;
    v50 = *++v54;
  }
  while ( v51 < v52 );
}


// ========================================================================
// ?FindCoverPoints@idAAS2Local@@UBAHHABVidVec3@@MHHHPAHHAAH@Z
// EA  : 0x826B8780
// RVA : 0x006B8780
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::FindCoverPoints(
        idAAS2Local *this,
        int areaNum,
        const idVec3 *origin,
        double maxDist,
        const int requiredFlags,
        int excludeFlags,
        int travelFlags,
        int *coverPoints,
        int maxCover,
        int *numCover,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        _DWORD *a31)
{
  int v44; // [sp+8h] [-98h]
  int *v45; // [sp+Ch] [-94h]
  int v46; // [sp+10h] [-90h]
  int v47; // [sp+14h] [-8Ch]
  int v48; // [sp+18h] [-88h]
  int v49; // [sp+1Ch] [-84h]
  int v50; // [sp+20h] [-80h]
  int v51; // [sp+24h] [-7Ch]
  int v52; // [sp+28h] [-78h]
  int v53; // [sp+2Ch] [-74h]
  int v54; // [sp+30h] [-70h]
  int v55; // [sp+34h] [-6Ch]
  int v56; // [sp+38h] [-68h]
  int v57; // [sp+3Ch] [-64h]
  int v58; // [sp+40h] [-60h]
  int v59; // [sp+44h] [-5Ch]
  int v60; // [sp+48h] [-58h]
  int v61; // [sp+4Ch] [-54h]
  int v62; // [sp+50h] [-50h]
  int v63; // [sp+58h] [-48h]
  int v64; // [sp+60h] [-40h]
  idBounds v65; // [sp+70h] [-30h] BYREF

  *a31 = 0;
  if ( areaNum <= 0 )
    return 0;
  _FP5 = (float)((float)(origin->x + (float)maxDist) - (float)(origin->x - (float)maxDist));
  _FP2 = (float)((float)(origin->x - (float)maxDist) - (float)(origin->x + (float)maxDist));
  _FP4 = (float)((float)(origin->y + (float)maxDist) - (float)(origin->y - (float)maxDist));
  _FP0 = (float)((float)(origin->y - (float)maxDist) - (float)(origin->y + (float)maxDist));
  _FP3 = (float)((float)(origin->z + (float)maxDist) - (float)(origin->z - (float)maxDist));
  _FP13 = (float)((float)(origin->z - (float)maxDist) - (float)(origin->z + (float)maxDist));
  __asm { fsel      f11, f5, f8, f12 }
  v65.b[0].x = _FP11;
  __asm { fsel      f5, f4, f7, f10 }
  v65.b[0].y = _FP5;
  __asm { fsel      f4, f3, f6, f9 }
  v65.b[0].z = _FP4;
  __asm { fsel      f3, f2, f8, f12 }
  v65.b[1].x = _FP3;
  __asm { fsel      f2, f0, f7, f10 }
  v65.b[1].y = _FP2;
  __asm { fsel      f0, f13, f6, f9 }
  v65.b[1].z = _FP0;
  idAAS2Local::FindCoverPoints_Internal(
    this,
    startAreaNum: areaNum,
    origin,
    bounds: &v65,
    maxDistSqr: (float)((float)maxDist * (float)maxDist),
    requiredFlags: excludeFlags,
    excludeFlags,
    travelFlags,
    (unsigned int)coverPoints,
    maxCover: v44,
    numCover: v45,
    a12: v46,
    a13: v47,
    a14: v48,
    a15: v49,
    a16: v50,
    a17: v51,
    a18: v52,
    a19: v53,
    a20: v54,
    a21: v55,
    a22: v56,
    a23: v57,
    a24: v58,
    a25: v59,
    a26: v60,
    a27: v61,
    a28: v62,
    a29: maxCover,
    a30: v63,
    a31: a29,
    a32: v64,
    a33: a31);
  return *a31;
}


// ========================================================================
// ?GetNumChokePoints@idAAS2Local@@EBAHXZ
// EA  : 0x826B8870
// RVA : 0x006B8870
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumChokePoints(idAAS2Local *this)
{
  return this->file->chokePoints.num;
}


// ========================================================================
// ?GetChokePoint@idAAS2Local@@EBAABUaas2ChokePoint_t@@H@Z
// EA  : 0x826B8880
// RVA : 0x006B8880
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

const aas2ChokePoint_t *__fastcall idAAS2Local::GetChokePoint(idAAS2Local *this, const int chokeIndex)
{
  return &this->file->chokePoints.list[chokeIndex];
}


// ========================================================================
// ?GetNumHintNodes@idAAS2Local@@EBAHXZ
// EA  : 0x826B8898
// RVA : 0x006B8898
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

int __fastcall idAAS2Local::GetNumHintNodes(idAAS2Local *this)
{
  return this->file->hintNodes.num;
}


// ========================================================================
// ?GetHintNode@idAAS2Local@@EBAABUaas2HintNode_t@@H@Z
// EA  : 0x826B88A8
// RVA : 0x006B88A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_spacial.cpp
// ========================================================================

const aas2HintNode_t *__fastcall idAAS2Local::GetHintNode(idAAS2Local *this, const int hintIndex)
{
  return &this->file->hintNodes.list[hintIndex];
}

