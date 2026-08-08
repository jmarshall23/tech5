
// ========================================================================
// ?SetBounds@idBoundsShort@@QAAXABVidBounds@@@Z
// EA  : 0x825BD780
// RVA : 0x005BD780
// PDB : w:\tech5\shared\idlib\bv\boundsshort.h
// ========================================================================

void __fastcall idBoundsShort::SetBounds(idBoundsShort *this, const idBounds *bounds)
{
  _R11 = 8;
  __asm { vspltisw128 v61, 0 }
  _R10 = 24;
  __asm { lvlx128   v60, r0, r4 }
  _R9 = 16;
  __asm { lvlx128   v59, r11, r4 }
  _R6 = &idBoundsShort::vector_float_max_ushort;
  __asm { lvrx128   v58, r10, r4 }
  _R5 = idBoundsShort::vector_int_max_ushort;
  __asm
  {
    vor128    v57, v91, v58
    lvrx128   v56, r9, r4
    vor128    v55, v92, v56
  }
  _R10 = 4;
  __asm { lvx128    v63, r0, r6 }
  _R9 = idBoundsShort::vector_int_zero;
  __asm
  {
    vsldoi128 v54, v89, v61, 4
    lvx128    v0, r0, r5
    vrlimi128 v55, v61, 1, 0
    vsubfp128 v53, v86, v63
    lvx128    v62, r0, r9
    vaddfp128 v52, v87, v63
    vcfpsxws128 v13, v53, 0
    vcfpsxws128 v12, v52, 0
    vaddsws   v11, v13, v0
    vsubsws   v10, v12, v0
    vpkswss128 v51, v11, v62
    vpkswss128 v50, v10, v62
    vsldoi128 v49, v93, v51, 0xA
    vor128    v48, v82, v49
    vspltw128 v47, v48, 0
    vspltw128 v46, v48, 1
    vspltw128 v45, v48, 2
    stvewx128 v47, r0, r3
    stvewx128 v46, r3, r10
    stvewx128 v45, r3, r11
  }
}


// ========================================================================
// ?ToBounds@idBoundsShort@@QBA?AVidBounds@@XZ
// EA  : 0x825BD820
// RVA : 0x005BD820
// PDB : w:\tech5\shared\idlib\bv\boundsshort.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idBounds *__fastcall idBoundsShort::ToBounds(idBoundsShort *this, idBounds *result)
{
  __int128 v2; // r11 OVERLAPPED
  __int128 v3; // r5 OVERLAPPED
  int z_low; // r7
  int v5; // r6
  idBounds *v6; // r3

  DWORD2(v2) = HIWORD(result->b[0].z);
  LODWORD(v3) = SHIWORD(result->b[0].x);
  z_low = LOWORD(result->b[0].z);
  LODWORD(v2) = SLOWORD(result->b[0].y);
  DWORD1(v2) = HIWORD(result->b[0].y);
  DWORD2(v3) = SLOWORD(result->b[0].x);
  HIDWORD(v2) = (__int16)z_low;
  v5 = SWORD3(v2);
  *(float *)(DWORD1(v3) + 4) = (float)*(__int64 *)((char *)&v3 + 4);
  *(float *)DWORD1(v3) = (float)(__int64)v3;
  *(float *)(DWORD1(v3) + 8) = (float)*(__int64 *)((char *)&v3 - 4);
  *(float *)(DWORD1(v3) + 12) = (float)(__int64)v2;
  DWORD2(v2) = SWORD5(v2);
  *(float *)(DWORD1(v3) + 16) = (float)*(__int64 *)((char *)&v2 + 4);
  *(float *)(DWORD1(v3) + 20) = (float)*(__int64 *)((char *)&v2 + 12);
  return v6;
}


// ========================================================================
// ?IntersectsBounds@idBoundsShort@@QBA_NABV1@@Z
// EA  : 0x827012D8
// RVA : 0x007012D8
// PDB : w:\tech5\shared\idlib\bv\boundsshort.h
// ========================================================================

int __fastcall idBoundsShort::IntersectsBounds(idBoundsShort *this, const idBoundsShort *a)
{
  unsigned __int8 v2; // r11

  if ( this->b[0][0] > a->b[1][0] )
    return 0;
  if ( this->b[0][1] > a->b[1][1] )
    return 0;
  if ( this->b[0][2] > a->b[1][2] )
    return 0;
  if ( a->b[0][0] > this->b[1][0] )
    return 0;
  if ( a->b[0][1] > this->b[1][1] )
    return 0;
  v2 = 1;
  if ( a->b[0][2] > this->b[1][2] )
    return 0;
  return v2;
}

