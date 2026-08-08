
// ========================================================================
// ?TracePoint@idClip@@QAA_NAAUtrace_t@@ABVidVec3@@1HH@Z
// EA  : 0x826AAE18
// RVA : 0x006AAE18
// PDB : w:\tech5\engine\gamelib\physics\clip.h
// ========================================================================

BOOL __fastcall idClip::TracePoint(
        idClip *this,
        trace_t *result,
        const idVec3 *start,
        const idVec3 *end,
        int clipMask,
        const int passEntityNumber)
{
  int v8; // [sp+8h] [-88h]
  bool v9; // [sp+Fh] [-81h]
  const char *v10; // [sp+10h] [-80h]
  char v11; // [sp+70h] [-20h] BYREF

  idClip::Translation(
    this: (idClip *)&v11,
    result: (idClipQuery *)this,
    result,
    start,
    end,
    clipModel: nullptr,
    startAxis: &mat3_identity,
    clipMask,
    passEntityNumber: v8,
    moveClipModel: v9,
    userName: v10);
  return result->fraction < 1.0;
}


// ========================================================================
// ?QueryIsValid@idClip@@QBA_NABVidClipQuery@@@Z
// EA  : 0x826E3168
// RVA : 0x006E3168
// PDB : w:\tech5\engine\gamelib\physics\clip.h
// ========================================================================

int __fastcall idClip::QueryIsValid(idClip *this, const idClipQuery *clipQuery)
{
  unsigned __int64 index; // r11
  unsigned int v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  index = clipQuery->index;
  if ( (idClipModel *)LODWORD(clipQuery->index) < *(idClipModel **)((char *)&this->temporaryClipModel
                                                                  + (HIDWORD(clipQuery->index) | 0xC178))
    || (unsigned int)index > LODWORD(this->collisionQueryLastSubmittedIndex) )
  {
    return 0;
  }
  v3 = *((_DWORD *)&this->collisionQueries[0].query.offset + 2 * (index & 0xFFF) + 2 * ((2 * index) & 0x1FFE) + 1);
  if ( v3 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset )
    return 0;
  v5 = v3 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}


// ========================================================================
// ?CancelQuery@idClip@@QAAXAAVidClipQuery@@@Z
// EA  : 0x8271B9D0
// RVA : 0x0071B9D0
// PDB : w:\tech5\engine\gamelib\physics\clip.h
// ========================================================================

void __fastcall idClip::CancelQuery(idClip *this, idClipQuery *clipQuery)
{
  unsigned __int64 index; // r11
  int v3; // r11
  unsigned __int64 v4; // r8

  index = clipQuery->index;
  if ( (idClipModel *)LODWORD(clipQuery->index) < *(idClipModel **)((char *)&this->temporaryClipModel
                                                                  + (HIDWORD(clipQuery->index) | 0xC178))
    || (HIDWORD(index) = 327680, (unsigned int)index > LODWORD(this->collisionQueryLastAllocedIndex)) )
  {
    LODWORD(index) = 0;
    clipQuery->index = index;
  }
  else
  {
    v3 = (index & 0xFFF) + 11621;
    LODWORD(v4) = 0;
    HIDWORD(v4) = 3 * v3;
    *((_DWORD *)&this->world + 6 * v3) = 1;
    clipQuery->index = v4;
  }
}


// ========================================================================
// ?TraceBounds@idClip@@QAA_NAAUtrace_t@@ABVidVec3@@1PBVidClipModel@@HH@Z
// EA  : 0x829F0658
// RVA : 0x009F0658
// PDB : w:\tech5\engine\gamelib\physics\clip.h
// ========================================================================

BOOL __fastcall idClip::TraceBounds(
        idClip *this,
        trace_t *result,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *trm,
        int clipMask,
        int passEntityNumber)
{
  int v9; // [sp+8h] [-88h]
  bool v10; // [sp+Fh] [-81h]
  const char *v11; // [sp+10h] [-80h]
  int v12; // [sp+14h] [-7Ch]
  int v13; // [sp+18h] [-78h]
  int v14; // [sp+1Ch] [-74h]
  int v15; // [sp+20h] [-70h]
  int v16; // [sp+24h] [-6Ch]
  int v17; // [sp+28h] [-68h]
  int v18; // [sp+2Ch] [-64h]
  int v19; // [sp+30h] [-60h]
  int v20; // [sp+34h] [-5Ch]
  int v21; // [sp+38h] [-58h]
  int v22; // [sp+3Ch] [-54h]
  int v23; // [sp+40h] [-50h]
  int v24; // [sp+44h] [-4Ch]
  int v25; // [sp+48h] [-48h]
  int v26; // [sp+4Ch] [-44h]
  int v27; // [sp+50h] [-40h]
  int v28; // [sp+58h] [-38h]
  int v29; // [sp+60h] [-30h]
  char v30; // [sp+70h] [-20h] BYREF

  idClip::Translation(
    this: (idClip *)&v30,
    result: this,
    a3: result,
    start,
    end,
    clipModel: trm,
    startAxis: &mat3_identity,
    clipMask,
    passEntityNumber: v9,
    moveClipModel: v10,
    userName: v11,
    a12: v12,
    a13: v13,
    a14: v14,
    a15: v15,
    a16: v16,
    a17: v17,
    a18: v18,
    a19: v19,
    a20: v20,
    a21: v21,
    a22: v22,
    a23: v23,
    a24: v24,
    a25: v25,
    a26: v26,
    a27: v27,
    a28: passEntityNumber,
    a29: v28,
    a30: false,
    a31: v29,
    a32: 0);
  return result->fraction < 1.0;
}

