
// ========================================================================
// ?Transpose@idSpatialMat@@QBAXAAV1@@Z
// EA  : 0x82F39DB8
// RVA : 0x00F39DB8
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::Transpose(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r10

  mat = dst->mat;
  dst->numRows = this->numColumns;
  dst->numColumns = this->numRows;
  if ( mat == nullptr )
  {
    dst->mat = (float *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\math\\SpatialMat.cpp(36) : TAG_MATH",
                          size: 0xC0u,
                          tag: TAG_MATH,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    dst->allocatedRows = 6;
  }
  _R11 = this->mat;
  _R28 = 32;
  _R29 = 64;
  _R27 = dst->mat;
  _R3 = 96;
  __asm { vspltisw128 v63, 0 }
  _R5 = 160;
  _R6 = 80;
  __asm { lvx128    v61, r11, r28 }
  _R7 = 16;
  __asm { lvx128    v60, r11, r29 }
  _R8 = 112;
  __asm { lvx128    v59, r11, r3 }
  _R9 = 48;
  __asm { lvx128    v62, r0, r11 }
  _R4 = 128;
  __asm { vmrghw128 v57, v93, v59 }
  _R11 = 144;
  __asm { vmrghw128 v58, v94, v60 }
  _R10 = 176;
  __asm
  {
    vmrglw128 v56, v94, v60
    vmrglw128 v55, v93, v59
    vmrghw128 v54, v90, v57
    vmrglw128 v53, v90, v57
    vmrghw128 v52, v88, v55
    vmrglw128 v51, v88, v55
    stvx128   v54, r0, r27
  }
  __asm { stvx128   v53, r27, r28 }
  _R28 = _R27;
  __asm { stvx128   v52, r28, r29 }
  _R29 = _R28;
  __asm { stvx128   v51, r29, r3 }
  _R3 = this->mat;
  __asm { lvx128    v45, r3, r5 }
  _R29 = _R28;
  __asm
  {
    lvx128    v48, r3, r7
    lvx128    v49, r3, r6
    lvx128    v47, r3, r8
    lvx128    v46, r3, r9
    lvx128    v50, r3, r4
    vmrghw128 v43, v82, v63
    vmrghw128 v44, v77, v63
    vmrglw128 v42, v82, v63
    vmrglw128 v41, v77, v63
    vmrghw128 v40, v80, v49
    vmrghw128 v39, v75, v44
    vmrglw128 v38, v75, v44
    vmrghw128 v37, v78, v47
    vmrghw128 v36, v74, v41
    vmrglw128 v35, v74, v41
    vmrghw128 v34, v72, v37
    stvx128   v39, r29, r7
  }
  _R7 = _R28;
  __asm
  {
    stvx128   v38, r7, r9
    vmrglw128 v33, v72, v37
  }
  _R3 = _R28;
  __asm { stvx128   v36, r3, r6 }
  _R9 = _R28;
  __asm { stvx128   v35, r9, r8 }
  _R8 = _R28;
  __asm { stvx128   v34, r8, r4 }
  _R7 = _R28;
  __asm { stvx128   v33, r7, r5 }
  _R6 = this->mat;
  _R5 = _R28;
  __asm
  {
    lvx128    v62, r6, r11
    lvx128    v32, r6, r10
    vmrghw128 v60, v64, v63
    vmrghw128 v61, v94, v63
    vmrghw128 v59, v93, v60
    vmrglw128 v58, v93, v60
    stvx128   v59, r5, r11
  }
  _R4 = _R28;
  __asm { stvx128   v58, r4, r10 }
}


// ========================================================================
// ?Subtract@idSpatialMat@@QAAXABV1@@Z
// EA  : 0x82F39F50
// RVA : 0x00F39F50
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::Subtract(idSpatialMat *this, const idSpatialMat *a)
{
  _R27 = a->mat;
  _R30 = 16;
  _R26 = this->mat;
  _R31 = 32;
  __asm { lvx128    v63, r0, r27 }
  _R4 = 64;
  __asm { lvx128    v62, r0, r26 }
  _R5 = 80;
  __asm
  {
    lvx128    v61, r27, r30
    vsubfp128 v60, v94, v63
    lvx128    v59, r26, r30
  }
  _R25 = _R26;
  _R3 = 48;
  __asm
  {
    vsubfp128 v58, v91, v61
    lvx128    v55, r27, r3
    lvx128    v53, r26, r3
  }
  _R10 = 96;
  __asm
  {
    lvx128    v52, r27, r4
    vsubfp128 v51, v85, v55
    lvx128    v57, r27, r31
  }
  _R11 = 112;
  __asm { lvx128    v50, r26, r4 }
  _R6 = 128;
  __asm
  {
    lvx128    v49, r27, r5
    vsubfp128 v48, v82, v52
    lvx128    v56, r26, r31
  }
  _R7 = 144;
  __asm
  {
    lvx128    v47, r26, r5
    vsubfp128 v54, v88, v57
    vsubfp128 v46, v79, v49
  }
  _R8 = 160;
  _R9 = 176;
  __asm { stvx128   v60, r0, r25 }
  _R27 = this->mat;
  __asm { stvx128   v58, r27, r30 }
  _R30 = _R27;
  __asm { stvx128   v54, r30, r31 }
  _R31 = _R27;
  __asm { stvx128   v51, r31, r3 }
  _R3 = _R27;
  __asm { stvx128   v48, r3, r4 }
  _R4 = _R27;
  __asm { stvx128   v46, r4, r5 }
  _R3 = a->mat;
  _R5 = _R27;
  __asm
  {
    lvx128    v40, r3, r10
    lvx128    v34, r5, r10
  }
  __asm
  {
    vsubfp128 v33, v66, v40
    lvx128    v45, r3, r11
    lvx128    v39, r5, r11
    vsubfp128 v32, v71, v45
    lvx128    v44, r3, r6
    lvx128    v38, r5, r6
    vsubfp128 v63, v70, v44
    lvx128    v43, r3, r7
    lvx128    v37, r5, r7
    vsubfp128 v62, v69, v43
    lvx128    v42, r3, r8
    lvx128    v36, r5, r8
    vsubfp128 v61, v68, v42
    lvx128    v41, r3, r9
    lvx128    v35, r5, r9
    vsubfp128 v60, v67, v41
    stvx128   v33, r5, r10
  }
  _R3 = _R27;
  __asm { stvx128   v32, r3, r11 }
  _R11 = _R27;
  __asm { stvx128   v63, r11, r6 }
  _R10 = _R27;
  __asm { stvx128   v62, r10, r7 }
  _R7 = _R27;
  __asm { stvx128   v61, r7, r8 }
  _R6 = _R27;
  __asm { stvx128   v60, r6, r9 }
}


// ========================================================================
// ?Multiply@idSpatialMat@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x82F3A090
// RVA : 0x00F3A090
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::Multiply(idSpatialMat *this, idSpatialVec *dst, const idSpatialVec *vec)
{
  _R10 = 64;
  _R9 = vec->p;
  _R8 = 96;
  _R5 = dst->p;
  _R6 = 128;
  _R7 = 48;
  __asm { vspltisw128 v63, 0 }
  _R31 = 80;
  dst->size = this->numRows;
  _R4 = 160;
  _R3 = this->mat;
  _R11 = 16;
  _R30 = 112;
  __asm { lvx128    v62, r0, r9 }
  _R29 = 144;
  _R28 = 176;
  __asm { lvx128    v0, r9, r11 }
  _R9 = 32;
  __asm
  {
    lvx128    v61, r0, r3
    lvx128    v60, r3, r10
    lvx128    v59, r3, r8
    lvx128    v58, r3, r6
    lvx128    v57, r3, r4
    lvx128    v13, r3, r7
    lvx128    v11, r3, r11
    lvx128    v9, r3, r31
    lvx128    v7, r3, r30
    lvx128    v5, r3, r29
    lvx128    v3, r3, r28
    lvx128    v56, r3, r9
    vmulfp128 v12, v88, v62
    vmulfp128 v10, v93, v62
    vmulfp128 v8, v92, v62
    vmulfp128 v6, v91, v62
    vmulfp128 v4, v90, v62
    vmulfp128 v2, v89, v62
    vmaddfp   v13, v13, v12, v0
    vmaddfp   v12, v11, v10, v0
    vmaddfp   v11, v9, v8, v0
    vmaddfp   v10, v7, v6, v0
    vmaddfp   v9, v5, v4, v0
    vmaddfp   v0, v3, v2, v0
    vmrglw128 v55, v12, v11
    vmrghw128 v54, v12, v11
    vmrglw128 v53, v13, v10
    vmrghw128 v52, v13, v10
    vmrglw128 v51, v9, v63
    vmrghw128 v50, v9, v63
    vaddfp128 v49, v86, v55
    vmrglw128 v48, v0, v63
    vmrghw128 v47, v0, v63
    vaddfp128 v46, v84, v53
    vaddfp128 v45, v82, v51
    vaddfp128 v44, v79, v48
    vmrghw128 v43, v81, v46
    vmrglw128 v42, v81, v46
    vmrghw128 v41, v77, v44
    vmrglw128 v40, v77, v44
    vaddfp128 v39, v74, v43
    vaddfp128 v38, v72, v41
    stvx128   v39, r0, r5
    stvx128   v38, r5, r11
  }
}


// ========================================================================
// ?MultiplyAdd@idSpatialMat@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x82F3A198
// RVA : 0x00F3A198
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::MultiplyAdd(idSpatialMat *this, idSpatialVec *dst, const idSpatialVec *vec)
{
  _R9 = this->mat;
  _R8 = 32;
  _R7 = vec->p;
  _R6 = 64;
  _R11 = dst->p;
  _R3 = 128;
  _R5 = 96;
  __asm { vspltisw128 v63, 0 }
  _R4 = 160;
  __asm { lvx128    v62, r0, r9 }
  _R10 = 16;
  __asm { lvx128    v61, r0, r7 }
  _R31 = 48;
  __asm
  {
    lvx128    v60, r9, r8
    vmulfp128 v12, v94, v61
    lvx128    v59, r9, r6
    vmulfp128 v10, v92, v61
    lvx128    v57, r9, r3
    vmulfp128 v8, v91, v61
    lvx128    v58, r9, r5
    vmulfp128 v4, v89, v61
    lvx128    v56, r9, r4
    vmulfp128 v6, v90, v61
    vmulfp128 v2, v88, v61
    lvx128    v0, r7, r10
  }
  _R3 = 80;
  __asm { lvx128    v13, r9, r10 }
  _R8 = 112;
  __asm { lvx128    v11, r9, r31 }
  _R7 = 144;
  __asm { lvx128    v55, r0, r11 }
  _R6 = 176;
  _R10 = _R11 + 4;
  __asm
  {
    lvx128    v9, r9, r3
    vmaddfp   v13, v13, v12, v0
    lvx128    v7, r9, r8
    lvx128    v5, r9, r7
    vmaddfp   v12, v11, v10, v0
    lvx128    v3, r9, r6
    vmaddfp   v11, v9, v8, v0
    vmaddfp   v9, v5, v4, v0
    lvx128    v54, r0, r10
    vmaddfp   v10, v7, v6, v0
    vmaddfp   v0, v3, v2, v0
    vmrglw128 v53, v13, v11
    vmrghw128 v52, v13, v11
    vmrglw128 v51, v12, v10
    vmrghw128 v50, v12, v10
    vmrglw128 v49, v9, v63
    vmrghw128 v48, v9, v63
    vaddfp128 v47, v84, v53
    vmrglw128 v46, v0, v63
    vmrghw128 v45, v0, v63
    vaddfp128 v44, v82, v51
    vaddfp128 v43, v80, v49
    vaddfp128 v42, v77, v46
    vmrghw128 v41, v79, v44
    vmrglw128 v40, v79, v44
    vmrghw128 v39, v75, v42
    vmrglw128 v38, v75, v42
    vaddfp128 v37, v72, v41
    vaddfp128 v36, v70, v39
    vaddfp128 v35, v69, v55
    vaddfp128 v34, v68, v54
    stvx128   v35, r0, r11
    stvx128   v34, r0, r10
  }
}


// ========================================================================
// ?MultiplySub@idSpatialMat@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x82F3A2B0
// RVA : 0x00F3A2B0
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::MultiplySub(idSpatialMat *this, idSpatialVec *dst, const idSpatialVec *vec)
{
  _R9 = this->mat;
  _R8 = 32;
  _R7 = vec->p;
  _R6 = 64;
  _R11 = dst->p;
  _R3 = 128;
  _R5 = 96;
  __asm { vspltisw128 v63, 0 }
  _R4 = 160;
  __asm { lvx128    v62, r0, r9 }
  _R10 = 16;
  __asm { lvx128    v61, r0, r7 }
  _R31 = 48;
  __asm
  {
    lvx128    v60, r9, r8
    vmulfp128 v12, v94, v61
    lvx128    v59, r9, r6
    vmulfp128 v10, v92, v61
    lvx128    v57, r9, r3
    vmulfp128 v8, v91, v61
    lvx128    v58, r9, r5
    vmulfp128 v4, v89, v61
    lvx128    v56, r9, r4
    vmulfp128 v6, v90, v61
    vmulfp128 v2, v88, v61
    lvx128    v0, r7, r10
  }
  _R3 = 80;
  __asm { lvx128    v13, r9, r10 }
  _R8 = 112;
  __asm { lvx128    v11, r9, r31 }
  _R7 = 144;
  __asm { lvx128    v55, r0, r11 }
  _R6 = 176;
  _R10 = _R11 + 4;
  __asm
  {
    lvx128    v9, r9, r3
    vmaddfp   v13, v13, v12, v0
    lvx128    v7, r9, r8
    lvx128    v5, r9, r7
    vmaddfp   v12, v11, v10, v0
    lvx128    v3, r9, r6
    vmaddfp   v11, v9, v8, v0
    vmaddfp   v9, v5, v4, v0
    lvx128    v54, r0, r10
    vmaddfp   v10, v7, v6, v0
    vmaddfp   v0, v3, v2, v0
    vmrglw128 v53, v13, v11
    vmrghw128 v52, v13, v11
    vmrglw128 v51, v12, v10
    vmrghw128 v50, v12, v10
    vmrglw128 v49, v9, v63
    vmrghw128 v48, v9, v63
    vaddfp128 v47, v84, v53
    vmrglw128 v46, v0, v63
    vmrghw128 v45, v0, v63
    vaddfp128 v44, v82, v51
    vaddfp128 v43, v80, v49
    vaddfp128 v42, v77, v46
    vmrghw128 v41, v79, v44
    vmrglw128 v40, v79, v44
    vmrghw128 v39, v75, v42
    vmrglw128 v38, v75, v42
    vaddfp128 v37, v72, v41
    vaddfp128 v36, v70, v39
    vsubfp128 v35, v87, v37
    vsubfp128 v34, v86, v36
    stvx128   v35, r0, r11
    stvx128   v34, r0, r10
  }
}


// ========================================================================
// ?TransposeMultiplyAdd@idSpatialMat@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x82F3A3C8
// RVA : 0x00F3A3C8
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::TransposeMultiplyAdd(idSpatialMat *this, idSpatialVec *dst, const idSpatialVec *vec)
{
  _R8 = vec->p;
  _R9 = 16;
  _R11 = dst->p;
  _R7 = 48;
  _R6 = this->mat;
  _R5 = 32;
  _R10 = _R11 + 4;
  _R4 = 80;
  __asm { lvx128    v63, r0, r8 }
  _R3 = 64;
  __asm { lvx128    v7, r0, r11 }
  _R31 = 112;
  __asm
  {
    vspltw128 v0, v63, 0
    lvx128    v11, r6, r9
    lvx128    v10, r0, r10
    vspltw128 v13, v63, 1
    lvx128    v8, r0, r6
    vspltw128 v12, v63, 2
    lvx128    v30, r6, r7
  }
  _R7 = 96;
  __asm
  {
    vmaddfp   v9, v11, v10, v0
    lvx128    v1, r6, r5
    vmaddfp   v31, v8, v7, v0
    lvx128    v2, r6, r4
    lvx128    v3, r6, r3
    vspltw128 v0, v63, 3
    lvx128    v4, r6, r31
  }
  _R5 = 144;
  __asm { lvx128    v5, r6, r7 }
  _R4 = 128;
  __asm { lvx128    v62, r8, r9 }
  _R3 = 176;
  _R9 = 160;
  __asm
  {
    vspltw128 v11, v62, 0
    lvx128    v6, r6, r5
    vspltw128 v10, v62, 1
    lvx128    v7, r6, r4
    lvx128    v8, r6, r3
    vmaddfp   v30, v30, v9, v13
    lvx128    v9, r6, r9
    vmaddfp   v1, v1, v31, v13
    vmaddfp   v13, v2, v30, v12
    vmaddfp   v12, v3, v1, v12
    vmaddfp   v13, v4, v13, v0
    vmaddfp   v0, v5, v12, v0
    vmaddfp   v13, v6, v13, v11
    vmaddfp   v0, v7, v0, v11
    vmaddfp   v13, v8, v13, v10
    vmaddfp   v0, v9, v0, v10
    stvx128   v13, r0, r10
    stvx128   v0, r0, r11
  }
}


// ========================================================================
// ?TransposeMultiplySub@idSpatialMat@@QBAXAAVidSpatialVec@@ABV2@@Z
// EA  : 0x82F3A4A0
// RVA : 0x00F3A4A0
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::TransposeMultiplySub(idSpatialMat *this, idSpatialVec *dst, const idSpatialVec *vec)
{
  _R8 = vec->p;
  _R9 = 16;
  _R11 = dst->p;
  _R7 = 48;
  _R6 = this->mat;
  _R5 = 32;
  _R10 = _R11 + 4;
  _R4 = 80;
  __asm { lvx128    v63, r0, r8 }
  _R3 = 64;
  __asm { lvx128    v7, r0, r11 }
  _R31 = 112;
  __asm
  {
    vspltw128 v11, v63, 0
    lvx128    v0, r6, r9
    lvx128    v9, r0, r10
    vspltw128 v28, v63, 1
    lvx128    v12, r0, r6
    vspltw128 v2, v63, 2
    lvx128    v10, r6, r7
  }
  _R7 = 96;
  __asm
  {
    vnmsubfp  v27, v0, v9, v11
    lvx128    v29, r6, r5
    vnmsubfp  v0, v12, v7, v11
    lvx128    v30, r6, r4
    lvx128    v1, r6, r3
    vspltw128 v6, v63, 3
    lvx128    v3, r6, r31
  }
  _R5 = 144;
  __asm { lvx128    v5, r6, r7 }
  _R4 = 128;
  __asm { lvx128    v62, r8, r9 }
  _R3 = 176;
  _R9 = 160;
  __asm
  {
    vspltw128 v61, v62, 0
    lvx128    v7, r6, r5
    vspltw128 v60, v62, 1
    lvx128    v9, r6, r4
    lvx128    v11, r6, r3
    vor128    v8, v93, v61
    lvx128    v13, r6, r9
    vnmsubfp  v27, v10, v27, v28
    vor128    v10, v93, v61
    vnmsubfp  v26, v29, v0, v28
    vor128    v12, v92, v60
    vor128    v0, v92, v60
    vnmsubfp  v29, v30, v27, v2
    vnmsubfp  v31, v1, v26, v2
    vnmsubfp  v2, v3, v29, v6
    vnmsubfp  v4, v5, v31, v6
    vnmsubfp  v6, v7, v2, v8
    vnmsubfp  v8, v9, v4, v10
    vnmsubfp  v10, v11, v6, v12
    vnmsubfp  v12, v13, v8, v0
    stvx128   v10, r0, r10
    stvx128   v12, r0, r11
  }
}


// ========================================================================
// ?Multiply@idSpatialMat@@QBAXAAV1@ABV1@@Z
// EA  : 0x82F3A588
// RVA : 0x00F3A588
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::Multiply(idSpatialMat *this, idSpatialMat *dst, const idSpatialMat *a)
{
  int v4; // r9
  int numRows; // r10
  int v23; // ctr

  v4 = 0;
  _R8 = 16;
  dst->numRows = this->numRows;
  dst->numColumns = a->numColumns;
  numRows = this->numRows;
  if ( this->numRows > 0 )
  {
    _R11 = 0;
    _R24 = 32;
    _R25 = 48;
    _R26 = 64;
    _R27 = 80;
    _R28 = 96;
    _R29 = 112;
    _R30 = 128;
    _R31 = 144;
    _R6 = 160;
    _R7 = 176;
    do
    {
      ++v4;
      _R23 = a->mat;
      _R10 = &this->mat[_R11];
      _R22 = dst->mat;
      __asm
      {
        lvx128    v63, r0, r23
        lvx128    v62, r0, r10
        lvx128    v61, r23, r8
        vspltw128 v60, v62, 0
        lvx128    v30, r23, r24
        vspltw128 v0, v62, 1
        lvx128    v9, r23, r25
        vspltw128 v13, v62, 2
        lvx128    v1, r23, r26
        lvx128    v8, r23, r27
        vspltw128 v12, v62, 3
        vmulfp128 v29, v95, v60
        lvx128    v2, r23, r28
        vmulfp128 v31, v93, v60
        lvx128    v59, r10, r8
        lvx128    v7, r23, r29
        vspltw128 v11, v59, 0
        lvx128    v3, r23, r30
        lvx128    v6, r23, r31
        vspltw128 v10, v59, 1
        lvx128    v4, r23, r6
        lvx128    v5, r23, r7
        vmaddfp   v30, v30, v29, v0
        vmaddfp   v0, v9, v31, v0
        vmaddfp   v9, v1, v30, v13
        vmaddfp   v0, v8, v0, v13
        vmaddfp   v13, v2, v9, v12
        vmaddfp   v0, v7, v0, v12
        vmaddfp   v13, v3, v13, v11
        vmaddfp   v0, v6, v0, v11
        vmaddfp   v13, v4, v13, v10
        vmaddfp   v0, v5, v0, v10
        stvx128   v13, r11, r22
      }
      _R10 = &_R22[_R11];
      __asm { stvx128   v0, r10, r8 }
      numRows = this->numRows;
      _R11 += 8;
    }
    while ( v4 < this->numRows );
  }
  if ( numRows < 6 )
  {
    __asm { vspltisw128 v63, 0 }
    _R11 = 8 * numRows;
    v23 = 6 - numRows;
    do
    {
      _R10 = dst->mat;
      __asm { stvx128   v63, r11, r10 }
      _R9 = &_R10[_R11];
      _R11 += 8;
      __asm { stvx128   v63, r9, r8 }
      --v23;
    }
    while ( v23 != 0 );
  }
}


// ========================================================================
// ?TransposeMultiply@idSpatialMat@@QBAXAAV1@ABV1@@Z
// EA  : 0x82F3A6D0
// RVA : 0x00F3A6D0
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

void __fastcall idSpatialMat::TransposeMultiply(idSpatialMat *this, idSpatialMat *dst, const idSpatialMat *a)
{
  int v5; // r9
  int numColumns; // r8
  int v29; // ctr

  _R31 = 16;
  v5 = 0;
  dst->numRows = this->numColumns;
  dst->numColumns = a->numColumns;
  numColumns = this->numColumns;
  if ( numColumns > 0 )
  {
    _R21 = 64;
    _R10 = 0;
    _R11 = 64;
    _R7 = 0;
    _R6 = 32;
    _R22 = 32;
    _R23 = 48;
    _R24 = 80;
    _R25 = 96;
    _R26 = 112;
    _R27 = 128;
    _R28 = 144;
    _R29 = 160;
    _R30 = 176;
    do
    {
      _R8 = this->mat;
      _R20 = _R11 + 32;
      _R19 = a->mat;
      _R18 = _R11 + 64;
      _R17 = _R11 + 96;
      _R16 = dst->mat;
      ++v5;
      __asm
      {
        lvlx128   v63, r7, r8
        lvx128    v62, r0, r19
        vspltw128 v61, v63, 0
        lvlx128   v60, r6, r8
        lvx128    v59, r19, r31
        vspltw128 v0, v60, 0
        lvx128    v5, r19, r22
        lvlx128   v58, r11, r8
      }
      _R11 += 4;
      __asm
      {
        vmulfp128 v30, v94, v61
        lvx128    v9, r19, r23
        vmulfp128 v31, v91, v61
        vspltw128 v13, v58, 0
        lvx128    v1, r19, r21
      }
      _R7 = _R11 - 64;
      __asm { lvlx128   v57, r20, r8 }
      _R6 = _R11 - 32;
      __asm
      {
        lvx128    v8, r19, r24
        vspltw128 v12, v57, 0
        lvx128    v2, r19, r25
        lvlx128   v56, r18, r8
        lvx128    v7, r19, r26
        vspltw128 v11, v56, 0
        lvx128    v3, r19, r27
        lvlx128   v55, r17, r8
        lvx128    v6, r19, r28
        vspltw128 v10, v55, 0
        lvx128    v4, r19, r29
        vmaddfp   v30, v5, v30, v0
        lvx128    v5, r19, r30
        vmaddfp   v0, v9, v31, v0
        vmaddfp   v9, v1, v30, v13
        vmaddfp   v0, v8, v0, v13
        vmaddfp   v13, v2, v9, v12
        vmaddfp   v0, v7, v0, v12
        vmaddfp   v13, v3, v13, v11
        vmaddfp   v0, v6, v0, v11
        vmaddfp   v13, v4, v13, v10
        vmaddfp   v0, v5, v0, v10
        stvx128   v13, r10, r16
      }
      _R8 = &_R16[_R10];
      __asm { stvx128   v0, r8, r31 }
      numColumns = this->numColumns;
      _R10 += 8;
    }
    while ( v5 < numColumns );
  }
  if ( numColumns < 6 )
  {
    __asm { vspltisw128 v63, 0 }
    _R11 = 8 * numColumns;
    v29 = 6 - numColumns;
    do
    {
      _R10 = dst->mat;
      __asm { stvx128   v63, r11, r10 }
      _R9 = &_R10[_R11];
      _R11 += 8;
      __asm { stvx128   v63, r9, r31 }
      --v29;
    }
    while ( v29 != 0 );
  }
}


// ========================================================================
// ?Inverse1x1@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3A848
// RVA : 0x00F3A848
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse1x1(idSpatialMat *this, idSpatialMat *dst)
{
  if ( __fabs(*this->mat) < 9.9999998e-15 )
    return 0;
  *dst->mat = (float)1.0 / *this->mat;
  return 1;
}


// ========================================================================
// ?Inverse2x2@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3A888
// RVA : 0x00F3A888
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse2x2(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r10
  float *v4; // r9
  double v5; // fp0
  double v6; // fp12

  if ( __fabs((float)((float)(this->mat[9] * *this->mat) - (float)(this->mat[8] * this->mat[1]))) < 9.9999998e-15 )
    return 0;
  mat = this->mat;
  v4 = dst->mat;
  v5 = (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])));
  v6 = *mat;
  *v4 = mat[9] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])));
  v4[1] = -(float)(mat[1] * (float)v5);
  v4[8] = -(float)(mat[8] * (float)v5);
  v4[9] = (float)v6 * (float)v5;
  return 1;
}


// ========================================================================
// ?Inverse3x3@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3A918
// RVA : 0x00F3A918
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse3x3(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r11
  double v3; // fp0
  double v4; // fp13
  double v5; // fp12
  double v6; // fp11
  float *v8; // r11
  float *v9; // r9
  double v10; // fp11
  double v11; // fp10
  double v12; // fp4
  double v13; // fp6
  double v14; // fp3
  double v15; // fp2
  double v16; // fp1

  mat = this->mat;
  v3 = (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18]));
  v4 = (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9]));
  v5 = (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17]));
  v6 = (float)((float)(*mat * (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17])))
             + (float)((float)(mat[2] * (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9])))
                     + (float)(mat[1] * (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18])))));
  if ( __fabs(v6) < 9.9999998e-15 )
    return 0;
  v8 = this->mat;
  v9 = dst->mat;
  v10 = (float)((float)1.0 / (float)v6);
  v11 = (float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17]));
  v12 = (float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10]));
  v13 = (float)((float)(v8[2] * v8[17]) - (float)(v8[1] * v8[18]));
  v14 = (float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2]));
  v15 = (float)((float)(*v8 * v8[18]) - (float)(v8[16] * v8[2]));
  v16 = (float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1]));
  *v9 = (float)v10 * (float)v5;
  v9[8] = (float)v10 * (float)v3;
  v9[16] = (float)v10 * (float)v4;
  v9[10] = (float)v12 * (float)v10;
  v9[17] = (float)v11 * (float)v10;
  v9[1] = (float)v13 * (float)v10;
  v9[2] = (float)v14 * (float)v10;
  v9[9] = (float)v15 * (float)v10;
  v9[18] = (float)v16 * (float)v10;
  return 1;
}


// ========================================================================
// ?Inverse4x4@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3AA68
// RVA : 0x00F3AA68
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse4x4(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r10
  double v4; // fp0
  double v5; // fp10
  double v6; // fp9
  double v7; // fp8
  double v8; // fp7
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11
  double v13; // fp4
  float *v14; // r10
  double v15; // fp2
  double v16; // fp3
  double v17; // fp31
  double v18; // fp30
  double v19; // fp5
  double v20; // fp4
  double v21; // fp27
  double v22; // fp2
  double v23; // fp6
  double v24; // fp1
  double v25; // fp29
  double v26; // fp28
  double v27; // fp25

  if ( __fabs((float)((float)(this->mat[9] * *this->mat) - (float)(this->mat[8] * this->mat[1]))) < 9.9999998e-15 )
    return 0;
  mat = this->mat;
  v4 = (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])));
  v5 = (float)(*mat * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))));
  v6 = (float)(mat[9] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))));
  v7 = -(float)(mat[1] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))));
  v8 = -(float)(mat[8] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))));
  v10 = (float)((float)(mat[3] * (float)v8)
              + (float)(mat[11]
                      * (float)(*mat * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))))));
  v11 = (float)((float)(mat[2]
                      * (float)(mat[9] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])))))
              + (float)(mat[10] * (float)v7));
  v12 = (float)((float)(mat[3]
                      * (float)(mat[9] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])))))
              + (float)(mat[11] * (float)v7));
  v13 = (float)((float)((float)(mat[16]
                              * (float)((float)(mat[3] * (float)(mat[9] * (float)v4)) + (float)(mat[11] * (float)v7)))
                      + (float)(mat[17]
                              * (float)((float)(mat[3] * (float)v8) + (float)(mat[11] * (float)(*mat * (float)v4)))))
              - mat[19]);
  v9 = (float)((float)(mat[2] * (float)v8)
             + (float)(mat[10]
                     * (float)(*mat * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))))));
  if ( __fabs((float)((float)((float)((float)((float)(mat[24]
                                                    * (float)((float)(mat[3] * (float)v6) + (float)(mat[11] * (float)v7)))
                                            + (float)(mat[25] * (float)v10))
                                    - mat[27])
                            * (float)((float)((float)(mat[16]
                                                    * (float)((float)(mat[2] * (float)v6) + (float)(mat[10] * (float)v7)))
                                            + (float)(mat[17] * (float)v9))
                                    - mat[18]))
                    - (float)((float)((float)((float)(mat[24]
                                                    * (float)((float)(mat[2] * (float)v6) + (float)(mat[10] * (float)v7)))
                                            + (float)(mat[25] * (float)v9))
                                    - mat[26])
                            * (float)((float)((float)(mat[16]
                                                    * (float)((float)(mat[3] * (float)v6) + (float)(mat[11] * (float)v7)))
                                            + (float)(mat[17] * (float)v10))
                                    - mat[19])))) < 9.9999998e-15 )
    return 0;
  v15 = (float)((float)((float)((float)(mat[24] * (float)((float)(mat[3] * (float)v6) + (float)(mat[11] * (float)v7)))
                              + (float)(mat[25] * (float)v10))
                      - mat[27])
              * (float)((float)1.0
                      / (float)((float)((float)((float)((float)(mat[24]
                                                              * (float)((float)(mat[3] * (float)v6)
                                                                      + (float)(mat[11] * (float)v7)))
                                                      + (float)(mat[25] * (float)v10))
                                              - mat[27])
                                      * (float)((float)((float)(mat[16]
                                                              * (float)((float)(mat[2] * (float)v6)
                                                                      + (float)(mat[10] * (float)v7)))
                                                      + (float)(mat[17] * (float)v9))
                                              - mat[18]))
                              - (float)((float)((float)((float)(mat[24]
                                                              * (float)((float)(mat[2] * (float)v6)
                                                                      + (float)(mat[10] * (float)v7)))
                                                      + (float)(mat[25] * (float)v9))
                                              - mat[26])
                                      * (float)((float)((float)(mat[16]
                                                              * (float)((float)(mat[3] * (float)v6)
                                                                      + (float)(mat[11] * (float)v7)))
                                                      + (float)(mat[17] * (float)v10))
                                              - mat[19])))));
  v16 = (float)((float)((float)((float)(mat[16] * (float)((float)(mat[2] * (float)v6) + (float)(mat[10] * (float)v7)))
                              + (float)(mat[17] * (float)v9))
                      - mat[18])
              * (float)((float)1.0
                      / (float)((float)((float)((float)((float)(mat[24]
                                                              * (float)((float)(mat[3] * (float)v6)
                                                                      + (float)(mat[11] * (float)v7)))
                                                      + (float)(mat[25] * (float)v10))
                                              - mat[27])
                                      * (float)((float)((float)(mat[16]
                                                              * (float)((float)(mat[2] * (float)v6)
                                                                      + (float)(mat[10] * (float)v7)))
                                                      + (float)(mat[17] * (float)v9))
                                              - mat[18]))
                              - (float)((float)((float)((float)(mat[24]
                                                              * (float)((float)(mat[2] * (float)v6)
                                                                      + (float)(mat[10] * (float)v7)))
                                                      + (float)(mat[25] * (float)v9))
                                              - mat[26])
                                      * (float)((float)((float)(mat[16]
                                                              * (float)((float)(mat[3] * (float)v6)
                                                                      + (float)(mat[11] * (float)v7)))
                                                      + (float)(mat[17] * (float)v10))
                                              - mat[19])))));
  v17 = (float)((float)(mat[24]
                      * (float)(mat[9] * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])))))
              + (float)(mat[25] * (float)v8));
  v18 = (float)((float)(mat[24] * (float)v7)
              + (float)(mat[25]
                      * (float)(*mat * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1]))))));
  v19 = -(float)((float)((float)((float)(mat[24] * (float)((float)(mat[2] * (float)v6) + (float)(mat[10] * (float)v7)))
                               + (float)(mat[25] * (float)v9))
                       - mat[26])
               * (float)((float)1.0
                       / (float)((float)((float)((float)((float)(mat[24]
                                                               * (float)((float)(mat[3] * (float)v6)
                                                                       + (float)(mat[11] * (float)v7)))
                                                       + (float)(mat[25] * (float)v10))
                                               - mat[27])
                                       * (float)((float)((float)(mat[16]
                                                               * (float)((float)(mat[2] * (float)v6)
                                                                       + (float)(mat[10] * (float)v7)))
                                                       + (float)(mat[17] * (float)v9))
                                               - mat[18]))
                               - (float)((float)((float)((float)(mat[24]
                                                               * (float)((float)(mat[2] * (float)v6)
                                                                       + (float)(mat[10] * (float)v7)))
                                                       + (float)(mat[25] * (float)v9))
                                               - mat[26])
                                       * (float)((float)((float)(mat[16]
                                                               * (float)((float)(mat[3] * (float)v6)
                                                                       + (float)(mat[11] * (float)v7)))
                                                       + (float)(mat[17] * (float)v10))
                                               - mat[19])))));
  v20 = -(float)((float)v13
               * (float)((float)1.0
                       / (float)((float)((float)((float)((float)(mat[24]
                                                               * (float)((float)(mat[3] * (float)v6)
                                                                       + (float)(mat[11] * (float)v7)))
                                                       + (float)(mat[25] * (float)v10))
                                               - mat[27])
                                       * (float)((float)((float)(mat[16]
                                                               * (float)((float)(mat[2] * (float)v6)
                                                                       + (float)(mat[10] * (float)v7)))
                                                       + (float)(mat[17] * (float)v9))
                                               - mat[18]))
                               - (float)((float)((float)((float)(mat[24]
                                                               * (float)((float)(mat[2] * (float)v6)
                                                                       + (float)(mat[10] * (float)v7)))
                                                       + (float)(mat[25] * (float)v9))
                                               - mat[26])
                                       * (float)((float)((float)(mat[16]
                                                               * (float)((float)(mat[3] * (float)v6)
                                                                       + (float)(mat[11] * (float)v7)))
                                                       + (float)(mat[17] * (float)v10))
                                               - mat[19])))));
  v21 = -v15;
  v23 = (float)((float)v19
              * (float)((float)(mat[16]
                              * (float)(mat[9]
                                      * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])))))
                      + (float)(mat[17] * (float)v8)));
  v24 = (float)((float)v19
              * (float)((float)(mat[16] * (float)v7)
                      + (float)(mat[17]
                              * (float)(*mat
                                      * (float)((float)1.0 / (float)((float)(mat[9] * *mat) - (float)(mat[8] * mat[1])))))));
  v25 = (float)((float)((float)v19 * (float)v12)
              + (float)((float)((float)((float)((float)(mat[24]
                                                      * (float)((float)(mat[3] * (float)v6)
                                                              + (float)(mat[11] * (float)v7)))
                                              + (float)(mat[25] * (float)v10))
                                      - mat[27])
                              * (float)((float)1.0
                                      / (float)((float)((float)((float)((float)(mat[24]
                                                                              * (float)((float)(mat[3] * (float)v6)
                                                                                      + (float)(mat[11] * (float)v7)))
                                                                      + (float)(mat[25] * (float)v10))
                                                              - mat[27])
                                                      * (float)((float)((float)(mat[16]
                                                                              * (float)((float)(mat[2] * (float)v6)
                                                                                      + (float)(mat[10] * (float)v7)))
                                                                      + (float)(mat[17] * (float)v9))
                                                              - mat[18]))
                                              - (float)((float)((float)((float)(mat[24]
                                                                              * (float)((float)(mat[2] * (float)v6)
                                                                                      + (float)(mat[10] * (float)v7)))
                                                                      + (float)(mat[25] * (float)v9))
                                                              - mat[26])
                                                      * (float)((float)((float)(mat[16]
                                                                              * (float)((float)(mat[3] * (float)v6)
                                                                                      + (float)(mat[11] * (float)v7)))
                                                                      + (float)(mat[17] * (float)v10))
                                                              - mat[19])))))
                      * (float)v11));
  v26 = (float)((float)((float)v19 * (float)v10)
              + (float)((float)((float)((float)((float)(mat[24]
                                                      * (float)((float)(mat[3] * (float)v6)
                                                              + (float)(mat[11] * (float)v7)))
                                              + (float)(mat[25] * (float)v10))
                                      - mat[27])
                              * (float)((float)1.0
                                      / (float)((float)((float)((float)((float)(mat[24]
                                                                              * (float)((float)(mat[3] * (float)v6)
                                                                                      + (float)(mat[11] * (float)v7)))
                                                                      + (float)(mat[25] * (float)v10))
                                                              - mat[27])
                                                      * (float)((float)((float)(mat[16]
                                                                              * (float)((float)(mat[2] * (float)v6)
                                                                                      + (float)(mat[10] * (float)v7)))
                                                                      + (float)(mat[17] * (float)v9))
                                                              - mat[18]))
                                              - (float)((float)((float)((float)(mat[24]
                                                                              * (float)((float)(mat[2] * (float)v6)
                                                                                      + (float)(mat[10] * (float)v7)))
                                                                      + (float)(mat[25] * (float)v9))
                                                              - mat[26])
                                                      * (float)((float)((float)(mat[16]
                                                                              * (float)((float)(mat[3] * (float)v6)
                                                                                      + (float)(mat[11] * (float)v7)))
                                                                      + (float)(mat[17] * (float)v10))
                                                              - mat[19])))))
                      * (float)v9));
  v27 = (float)((float)((float)v20 * (float)((float)(mat[24] * (float)v6) + (float)(mat[25] * (float)v8)))
              + (float)((float)v15 * (float)((float)(mat[16] * (float)v6) + (float)(mat[17] * (float)v8))));
  v22 = (float)((float)((float)((float)((float)(mat[24]
                                              * (float)((float)(mat[3] * (float)v6) + (float)(mat[11] * (float)v7)))
                                      + (float)(mat[25] * (float)v10))
                              - mat[27])
                      * (float)((float)1.0
                              / (float)((float)((float)((float)((float)(mat[24]
                                                                      * (float)((float)(mat[3] * (float)v6)
                                                                              + (float)(mat[11] * (float)v7)))
                                                              + (float)(mat[25] * (float)v10))
                                                      - mat[27])
                                              * (float)((float)((float)(mat[16]
                                                                      * (float)((float)(mat[2] * (float)v6)
                                                                              + (float)(mat[10] * (float)v7)))
                                                              + (float)(mat[17] * (float)v9))
                                                      - mat[18]))
                                      - (float)((float)((float)((float)(mat[24]
                                                                      * (float)((float)(mat[2] * (float)v6)
                                                                              + (float)(mat[10] * (float)v7)))
                                                              + (float)(mat[25] * (float)v9))
                                                      - mat[26])
                                              * (float)((float)((float)(mat[16]
                                                                      * (float)((float)(mat[3] * (float)v6)
                                                                              + (float)(mat[11] * (float)v7)))
                                                              + (float)(mat[17] * (float)v10))
                                                      - mat[19])))))
              * (float)((float)(mat[16] * (float)v7) + (float)(mat[17] * (float)v5)));
  v14 = dst->mat;
  v14[16] = v27;
  v14[17] = (float)((float)v20 * (float)v18) + (float)v22;
  v14[24] = (float)((float)v16 * (float)v17) + (float)v23;
  v14[25] = (float)((float)v16 * (float)v18) + (float)v24;
  *v14 = -(float)((float)((float)v12 * v14[24]) - (float)-(float)((float)(v14[16] * (float)v11) - (float)v6));
  v14[1] = -(float)((float)(v14[25] * (float)v12) - (float)-(float)((float)(v14[17] * (float)v11) - (float)v7));
  v14[8] = -(float)((float)((float)v10 * v14[24]) - (float)-(float)((float)(v14[16] * (float)v9) - (float)v8));
  v14[9] = -(float)((float)(v14[25] * (float)v10) - (float)-(float)((float)(v14[17] * (float)v9) - (float)v5));
  v14[2] = v25;
  v14[3] = (float)((float)v16 * (float)v12) + (float)((float)v20 * (float)v11);
  v14[10] = v26;
  v14[11] = (float)((float)v16 * (float)v10) + (float)((float)v20 * (float)v9);
  v14[18] = v21;
  v14[19] = -v20;
  v14[26] = -v19;
  v14[27] = -v16;
  return 1;
}


// ========================================================================
// ?Inverse5x5@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3ACC8
// RVA : 0x00F3ACC8
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse5x5(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r11
  double v3; // fp0
  double v4; // fp13
  double v5; // fp12
  double v6; // fp11
  float *v8; // r11
  double v9; // fp11
  double v10; // fp7
  double v11; // fp6
  double v12; // fp5
  double v13; // fp8
  double v14; // fp4
  double v15; // fp3
  double v16; // fp1
  double v17; // fp2
  double v18; // fp31
  double v19; // fp23
  double v20; // fp10
  double v21; // fp29
  double v22; // fp0
  double v23; // fp12
  double v24; // fp13
  double v25; // fp9
  double v26; // fp11
  double v27; // fp10
  double v28; // fp23
  double v29; // fp27
  double v30; // fp25
  float *v31; // r10
  double v32; // fp26
  double v33; // fp30
  double v34; // fp28
  double v35; // fp27
  double v36; // fp23
  double v37; // fp22
  double v38; // fp21
  double v39; // fp18
  double v40; // fp17
  double v41; // fp29
  double v42; // fp24
  double v43; // fp25
  float v44; // [sp+0h] [-A0h]

  mat = this->mat;
  v3 = (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18]));
  v4 = (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9]));
  v5 = (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17]));
  v6 = (float)((float)(*mat * (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17])))
             + (float)((float)(mat[2] * (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9])))
                     + (float)(mat[1] * (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18])))));
  if ( __fabs(v6) < 9.9999998e-15 )
    return 0;
  v8 = this->mat;
  v9 = (float)((float)1.0 / (float)v6);
  v10 = (float)((float)v9 * (float)v4);
  v11 = (float)((float)v9 * (float)v5);
  v12 = (float)((float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17])) * (float)v9);
  v13 = (float)((float)v9 * (float)v3);
  v14 = (float)((float)((float)(*v8 * v8[18]) - (float)(v8[16] * v8[2])) * (float)v9);
  v44 = v8[36];
  v15 = (float)((float)((float)(v8[2] * v8[17]) - (float)(v8[1] * v8[18])) * (float)v9);
  v16 = (float)((float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1])) * (float)v9);
  v17 = (float)((float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10])) * (float)v9);
  v18 = (float)((float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2])) * (float)v9);
  v19 = (float)((float)(v8[3] * (float)((float)v9 * (float)v3))
              + (float)(v8[11] * (float)((float)((float)(*v8 * v8[18]) - (float)(v8[16] * v8[2])) * (float)v9)));
  v20 = (float)((float)(v8[4] * (float)((float)v9 * (float)v3))
              + (float)(v8[12] * (float)((float)((float)(*v8 * v8[18]) - (float)(v8[16] * v8[2])) * (float)v9)));
  v21 = (float)((float)(v8[4] * (float)((float)v9 * (float)v5))
              + (float)(v8[12] * (float)((float)((float)(v8[2] * v8[17]) - (float)(v8[1] * v8[18])) * (float)v9)));
  v22 = (float)((float)(v8[19] * (float)((float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1])) * (float)v9))
              + (float)((float)(v8[3] * (float)((float)v9 * (float)v4))
                      + (float)(v8[11] * (float)((float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17])) * (float)v9))));
  v23 = (float)((float)(v8[20] * (float)((float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1])) * (float)v9))
              + (float)((float)(v8[4] * (float)((float)v9 * (float)v4))
                      + (float)(v8[12] * (float)((float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17])) * (float)v9))));
  v24 = (float)((float)(v8[19] * (float)((float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10])) * (float)v9))
              + (float)v19);
  v25 = (float)((float)(v8[20] * (float)((float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10])) * (float)v9))
              + (float)v20);
  v28 = (float)(v8[26]
              * (float)((float)(v8[20] * (float)((float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1])) * (float)v9))
                      + (float)((float)(v8[4] * (float)v10)
                              + (float)(v8[12]
                                      * (float)((float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17])) * (float)v9)))));
  v29 = (float)((float)((float)((float)((float)(v8[20]
                                              * (float)((float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10]))
                                                      * (float)v9))
                                      + (float)v20)
                              * v8[25])
                      + (float)((float)((float)((float)(v8[20]
                                                      * (float)((float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2]))
                                                              * (float)v9))
                                              + (float)v21)
                                      * v8[24])
                              + (float)(v8[26]
                                      * (float)((float)(v8[20]
                                                      * (float)((float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1]))
                                                              * (float)v9))
                                              + (float)((float)(v8[4] * (float)v10)
                                                      + (float)(v8[12]
                                                              * (float)((float)((float)(v8[16] * v8[1])
                                                                              - (float)(*v8 * v8[17]))
                                                                      * (float)v9)))))))
              - v8[28]);
  v27 = (float)((float)(v8[20] * (float)((float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2])) * (float)v9))
              + (float)v21);
  v26 = (float)((float)(v8[19] * (float)((float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2])) * (float)v9))
              + (float)((float)(v8[3] * (float)v11)
                      + (float)(v8[11] * (float)((float)((float)(v8[2] * v8[17]) - (float)(v8[1] * v8[18])) * (float)v9))));
  v30 = (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                      + (float)((float)(v8[32] * (float)v27) + (float)(v8[33] * (float)v25)))
                              - v44)
                      * (float)((float)((float)((float)v24 * v8[25])
                                      + (float)((float)((float)v26 * v8[24]) + (float)(v8[26] * (float)v22)))
                              - v8[27]))
              - (float)((float)((float)((float)(v8[34] * (float)v22)
                                      + (float)((float)(v8[32] * (float)v26) + (float)(v8[33] * (float)v24)))
                              - v8[35])
                      * (float)((float)((float)((float)v25 * v8[25]) + (float)((float)((float)v27 * v8[24]) + (float)v28))
                              - v8[28])));
  if ( __fabs(v30) < 9.9999998e-15 )
    return 0;
  v31 = dst->mat;
  v32 = (float)((float)((float)((float)(v8[34] * (float)v23)
                              + (float)((float)(v8[32] * (float)v27) + (float)(v8[33] * (float)v25)))
                      - v44)
              * (float)((float)1.0
                      / (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                                      + (float)((float)(v8[32] * (float)v27)
                                                              + (float)(v8[33] * (float)v25)))
                                              - v44)
                                      * (float)((float)((float)((float)v24 * v8[25])
                                                      + (float)((float)((float)v26 * v8[24])
                                                              + (float)(v8[26] * (float)v22)))
                                              - v8[27]))
                              - (float)((float)((float)((float)(v8[34] * (float)v22)
                                                      + (float)((float)(v8[32] * (float)v26)
                                                              + (float)(v8[33] * (float)v24)))
                                              - v8[35])
                                      * (float)((float)((float)((float)v25 * v8[25])
                                                      + (float)((float)((float)v27 * v8[24]) + (float)v28))
                                              - v8[28])))));
  v33 = (float)((float)((float)1.0
                      / (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                                      + (float)((float)(v8[32] * (float)v27)
                                                              + (float)(v8[33] * (float)v25)))
                                              - v44)
                                      * (float)((float)((float)((float)v24 * v8[25])
                                                      + (float)((float)((float)v26 * v8[24])
                                                              + (float)(v8[26] * (float)v22)))
                                              - v8[27]))
                              - (float)((float)((float)((float)(v8[34] * (float)v22)
                                                      + (float)((float)(v8[32] * (float)v26)
                                                              + (float)(v8[33] * (float)v24)))
                                              - v8[35])
                                      * (float)((float)((float)((float)v25 * v8[25])
                                                      + (float)((float)((float)v27 * v8[24]) + (float)v28))
                                              - v8[28]))))
              * (float)((float)((float)((float)v24 * v8[25])
                              + (float)((float)((float)v26 * v8[24]) + (float)(v8[26] * (float)v22)))
                      - v8[27]));
  v34 = -(float)((float)((float)((float)(v8[34] * (float)v22)
                               + (float)((float)(v8[32] * (float)v26) + (float)(v8[33] * (float)v24)))
                       - v8[35])
               * (float)((float)1.0
                       / (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                                       + (float)((float)(v8[32] * (float)v27)
                                                               + (float)(v8[33] * (float)v25)))
                                               - v44)
                                       * (float)((float)((float)((float)v24 * v8[25])
                                                       + (float)((float)((float)v26 * v8[24])
                                                               + (float)(v8[26] * (float)v22)))
                                               - v8[27]))
                               - (float)((float)((float)((float)(v8[34] * (float)v22)
                                                       + (float)((float)(v8[32] * (float)v26)
                                                               + (float)(v8[33] * (float)v24)))
                                               - v8[35])
                                       * (float)((float)((float)((float)v25 * v8[25])
                                                       + (float)((float)((float)v27 * v8[24]) + (float)v28))
                                               - v8[28])))));
  v35 = -(float)((float)v29
               * (float)((float)1.0
                       / (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                                       + (float)((float)(v8[32] * (float)v27)
                                                               + (float)(v8[33] * (float)v25)))
                                               - v44)
                                       * (float)((float)((float)((float)v24 * v8[25])
                                                       + (float)((float)((float)v26 * v8[24])
                                                               + (float)(v8[26] * (float)v22)))
                                               - v8[27]))
                               - (float)((float)((float)((float)(v8[34] * (float)v22)
                                                       + (float)((float)(v8[32] * (float)v26)
                                                               + (float)(v8[33] * (float)v24)))
                                               - v8[35])
                                       * (float)((float)((float)((float)v25 * v8[25])
                                                       + (float)((float)((float)v27 * v8[24]) + (float)v28))
                                               - v8[28])))));
  v36 = (float)((float)(v8[34] * (float)v10) + (float)((float)(v8[32] * (float)v11) + (float)(v8[33] * (float)v13)));
  v37 = (float)((float)(v8[34] * (float)v12) + (float)((float)(v8[32] * (float)v15) + (float)(v8[33] * (float)v14)));
  v38 = (float)((float)(v8[34] * (float)v16) + (float)((float)(v8[32] * (float)v18) + (float)(v8[33] * (float)v17)));
  v39 = (float)((float)((float)((float)((float)(v8[34] * (float)v23)
                                      + (float)((float)(v8[32] * (float)v27) + (float)(v8[33] * (float)v25)))
                              - v44)
                      * (float)((float)1.0 / (float)v30))
              * (float)((float)(v8[26] * (float)v12)
                      + (float)((float)(v8[24] * (float)v15) + (float)(v8[25] * (float)v14))));
  v40 = (float)((float)((float)(v8[26] * (float)v16)
                      + (float)((float)(v8[24] * (float)v18) + (float)(v8[25] * (float)v17)))
              * (float)((float)((float)((float)(v8[34] * (float)v23)
                                      + (float)((float)(v8[32] * (float)v27) + (float)(v8[33] * (float)v25)))
                              - v44)
                      * (float)((float)1.0 / (float)v30)));
  v41 = (float)((float)v34
              * (float)((float)(v8[26] * (float)v10)
                      + (float)((float)(v8[24] * (float)v11) + (float)(v8[25] * (float)v13))));
  v42 = (float)((float)v34
              * (float)((float)(v8[26] * (float)v12)
                      + (float)((float)(v8[24] * (float)v15) + (float)(v8[25] * (float)v14))));
  v43 = (float)((float)((float)(v8[26] * (float)v16)
                      + (float)((float)(v8[24] * (float)v18) + (float)(v8[25] * (float)v17)))
              * (float)v34);
  v31[24] = (float)((float)v35
                  * (float)((float)(v8[34] * (float)v10)
                          + (float)((float)(v8[32] * (float)v11) + (float)(v8[33] * (float)v13))))
          + (float)((float)v32
                  * (float)((float)(v8[26] * (float)v10)
                          + (float)((float)(v8[24] * (float)v11) + (float)(v8[25] * (float)v13))));
  v31[25] = (float)((float)v35 * (float)v37) + (float)v39;
  v31[26] = (float)((float)v38 * (float)v35) + (float)v40;
  v31[32] = (float)((float)v33 * (float)v36) + (float)v41;
  v31[33] = (float)((float)v33 * (float)v37) + (float)v42;
  v31[34] = (float)((float)v38 * (float)v33) + (float)v43;
  *v31 = -(float)((float)(v31[32] * (float)v27) - (float)-(float)((float)(v31[24] * (float)v26) - (float)v11));
  v31[1] = -(float)((float)(v31[33] * (float)v27) - (float)-(float)((float)((float)v26 * v31[25]) - (float)v15));
  v31[2] = -(float)((float)((float)v27 * v31[34]) - (float)-(float)((float)(v31[26] * (float)v26) - (float)v18));
  v31[8] = -(float)((float)(v31[32] * (float)v25) - (float)-(float)((float)(v31[24] * (float)v24) - (float)v13));
  v31[9] = -(float)((float)(v31[33] * (float)v25) - (float)-(float)((float)((float)v24 * v31[25]) - (float)v14));
  v31[10] = -(float)((float)((float)v25 * v31[34]) - (float)-(float)((float)(v31[26] * (float)v24) - (float)v17));
  v31[16] = -(float)((float)(v31[32] * (float)v23) - (float)-(float)((float)(v31[24] * (float)v22) - (float)v10));
  v31[17] = -(float)((float)(v31[33] * (float)v23) - (float)-(float)((float)((float)v22 * v31[25]) - (float)v12));
  v31[18] = -(float)((float)((float)v23 * v31[34]) - (float)-(float)((float)(v31[26] * (float)v22) - (float)v16));
  v31[3] = (float)((float)v34 * (float)v27) + (float)((float)v32 * (float)v26);
  v31[4] = (float)((float)v33 * (float)v27) + (float)((float)v35 * (float)v26);
  v31[11] = (float)((float)v34 * (float)v25) + (float)((float)v32 * (float)v24);
  v31[12] = (float)((float)v33 * (float)v25) + (float)((float)v35 * (float)v24);
  v31[19] = (float)((float)v34 * (float)v23) + (float)((float)v32 * (float)v22);
  v31[20] = (float)((float)v33 * (float)v23) + (float)((float)v35 * (float)v22);
  v31[27] = -v32;
  v31[28] = -v35;
  v31[35] = -v34;
  v31[36] = -v33;
  return 1;
}


// ========================================================================
// ?Inverse6x6@idSpatialMat@@ABA_NAAV1@@Z
// EA  : 0x82F3B0C0
// RVA : 0x00F3B0C0
// PDB : w:\tech5\shared\idlib\math\spatialmat.cpp
// ========================================================================

int __fastcall idSpatialMat::Inverse6x6(idSpatialMat *this, idSpatialMat *dst)
{
  float *mat; // r11
  double v3; // fp13
  double v4; // fp12
  double v5; // fp11
  double v6; // fp10
  float *v8; // r11
  double v9; // fp6
  double v10; // fp5
  double v11; // fp25
  double v12; // fp13
  double v13; // fp0
  double v14; // fp12
  double v15; // fp10
  double v16; // fp11
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  double v20; // fp28
  double v21; // fp31
  double v22; // fp30
  double v23; // fp4
  double v24; // fp3
  double v25; // fp25
  double v26; // fp21
  double v27; // fp24
  double v28; // fp27
  double v29; // fp26
  float *v30; // r9
  double v31; // fp31
  double v32; // fp17
  double v33; // fp20
  double v34; // fp22
  double v35; // fp25
  double v36; // fp3
  double v37; // fp1
  double v38; // fp16
  double v39; // fp30
  double v40; // fp6
  double v41; // fp24
  double v42; // fp28
  double v43; // fp15
  double v44; // fp29
  double v45; // fp4
  double v46; // fp23
  double v47; // fp5
  double v48; // fp2
  double v49; // fp27
  float v50; // [sp+0h] [-180h]
  float v51; // [sp+0h] [-180h]
  float v52; // [sp+4h] [-17Ch]
  float v53; // [sp+4h] [-17Ch]
  float v54; // [sp+10h] [-170h]
  float v55; // [sp+14h] [-16Ch]
  float v56; // [sp+18h] [-168h]
  float v57; // [sp+1Ch] [-164h]
  float v58; // [sp+20h] [-160h]
  float v59; // [sp+24h] [-15Ch]
  float v60; // [sp+28h] [-158h]
  float v61; // [sp+2Ch] [-154h]
  float v62; // [sp+30h] [-150h]
  float v63; // [sp+38h] [-148h]
  float v64; // [sp+40h] [-140h]
  float v65; // [sp+48h] [-138h]
  float v66; // [sp+50h] [-130h]
  float v67; // [sp+5Ch] [-124h]
  float v68; // [sp+60h] [-120h]
  float v69; // [sp+64h] [-11Ch]
  float v70; // [sp+68h] [-118h]
  float v71; // [sp+90h] [-F0h]
  float v72; // [sp+9Ch] [-E4h]
  float v73; // [sp+A8h] [-D8h]
  float v74; // [sp+E0h] [-A0h]

  mat = this->mat;
  v3 = (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18]));
  v4 = (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9]));
  v5 = (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17]));
  v6 = (float)((float)(*mat * (float)((float)(mat[9] * mat[18]) - (float)(mat[10] * mat[17])))
             + (float)((float)(mat[2] * (float)((float)(mat[8] * mat[17]) - (float)(mat[16] * mat[9])))
                     + (float)(mat[1] * (float)((float)(mat[16] * mat[10]) - (float)(mat[8] * mat[18])))));
  if ( __fabs(v6) < 9.9999998e-15 )
    return 0;
  v8 = this->mat;
  v9 = (float)((float)((float)1.0 / (float)v6) * (float)v3);
  v10 = (float)((float)((float)1.0 / (float)v6) * (float)v5);
  v60 = (float)((float)1.0 / (float)v6) * (float)v4;
  v58 = (float)((float)(*v8 * v8[18]) - (float)(v8[16] * v8[2])) * (float)((float)1.0 / (float)v6);
  v55 = (float)((float)(v8[2] * v8[17]) - (float)(v8[1] * v8[18])) * (float)((float)1.0 / (float)v6);
  v61 = (float)((float)(v8[16] * v8[1]) - (float)(*v8 * v8[17])) * (float)((float)1.0 / (float)v6);
  v59 = (float)((float)(v8[8] * v8[2]) - (float)(*v8 * v8[10])) * (float)((float)1.0 / (float)v6);
  v56 = (float)((float)(v8[10] * v8[1]) - (float)(v8[9] * v8[2])) * (float)((float)1.0 / (float)v6);
  v57 = (float)((float)1.0 / (float)v6) * (float)v3;
  v54 = v10;
  v62 = (float)((float)(*v8 * v8[9]) - (float)(v8[8] * v8[1])) * (float)((float)1.0 / (float)v6);
  v11 = (float)((float)(v8[3] * (float)((float)((float)1.0 / (float)v6) * (float)v5)) + (float)(v8[11] * v55));
  v13 = (float)((float)(v8[19] * v59) + (float)((float)(v8[3] * v57) + (float)(v8[11] * v58)));
  v12 = (float)((float)(v8[20] * v59) + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58)));
  v15 = (float)((float)(v8[20] * v56)
              + (float)((float)(v8[4] * (float)((float)((float)1.0 / (float)v6) * (float)v5)) + (float)(v8[12] * v55)));
  v16 = (float)((float)(v8[19] * v56) + (float)v11);
  v17 = (float)((float)(v8[21] * v56) + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55)));
  v14 = (float)((float)(v8[21] * v59) + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58)));
  v18 = (float)((float)(v8[19] * v62) + (float)((float)(v8[3] * v60) + (float)(v8[11] * v61)));
  v19 = (float)((float)(v8[20] * v62) + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61)));
  v74 = (float)(v8[21] * v62) + (float)((float)(v8[5] * v60) + (float)(v8[13] * v61));
  v21 = (float)((float)((float)(v8[26]
                              * (float)((float)(v8[19] * v62) + (float)((float)(v8[3] * v60) + (float)(v8[11] * v61))))
                      + (float)((float)(v8[24] * (float)((float)(v8[19] * v56) + (float)v11))
                              + (float)(v8[25]
                                      * (float)((float)(v8[19] * v59)
                                              + (float)((float)(v8[3] * v57) + (float)(v8[11] * v58))))))
              - v8[27]);
  v67 = (float)((float)(v8[34] * (float)((float)(v8[19] * v62) + (float)((float)(v8[3] * v60) + (float)(v8[11] * v61))))
              + (float)((float)(v8[32] * (float)((float)(v8[19] * v56) + (float)v11))
                      + (float)(v8[33]
                              * (float)((float)(v8[19] * v59) + (float)((float)(v8[3] * v57) + (float)(v8[11] * v58))))))
      - v8[35];
  v66 = (float)((float)(v8[26] * (float)((float)(v8[19] * v62) + (float)((float)(v8[3] * v60) + (float)(v8[11] * v61))))
              + (float)((float)(v8[24] * (float)((float)(v8[19] * v56) + (float)v11))
                      + (float)(v8[25]
                              * (float)((float)(v8[19] * v59) + (float)((float)(v8[3] * v57) + (float)(v8[11] * v58))))))
      - v8[27];
  v69 = (float)((float)(v8[34] * v74)
              + (float)((float)(v8[32]
                              * (float)((float)(v8[21] * v56)
                                      + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                      + (float)(v8[33]
                              * (float)((float)(v8[21] * v59) + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
      - v8[37];
  v70 = (float)((float)(v8[42] * (float)((float)(v8[19] * v62) + (float)((float)(v8[3] * v60) + (float)(v8[11] * v61))))
              + (float)((float)(v8[40] * (float)((float)(v8[19] * v56) + (float)v11))
                      + (float)(v8[41]
                              * (float)((float)(v8[19] * v59) + (float)((float)(v8[3] * v57) + (float)(v8[11] * v58))))))
      - v8[43];
  v68 = (float)((float)(v8[34] * (float)((float)(v8[20] * v62) + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
              + (float)((float)(v8[32] * (float)v15)
                      + (float)(v8[33]
                              * (float)((float)(v8[20] * v59) + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
      - v8[36];
  v72 = (float)(v70 * v69)
      - (float)((float)((float)((float)(v8[42] * v74)
                              + (float)((float)(v8[40]
                                              * (float)((float)(v8[21] * v56)
                                                      + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                                      + (float)(v8[41]
                                              * (float)((float)(v8[21] * v59)
                                                      + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
                      - v8[45])
              * v67);
  v73 = (float)((float)((float)((float)(v8[42]
                                      * (float)((float)(v8[20] * v62)
                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                              + (float)((float)(v8[40] * (float)v15)
                                      + (float)(v8[41]
                                              * (float)((float)(v8[20] * v59)
                                                      + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
                      - v8[44])
              * v67)
      - (float)(v70 * v68);
  v25 = (float)((float)((float)((float)((float)(v8[42] * v74)
                                      + (float)((float)(v8[40]
                                                      * (float)((float)(v8[21] * v56)
                                                              + (float)((float)(v8[5] * (float)v10)
                                                                      + (float)(v8[13] * v55))))
                                              + (float)(v8[41]
                                                      * (float)((float)(v8[21] * v59)
                                                              + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
                              - v8[45])
                      * v68)
              - (float)((float)((float)((float)(v8[42]
                                              * (float)((float)(v8[20] * v62)
                                                      + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                                      + (float)((float)(v8[40] * (float)v15)
                                              + (float)(v8[41]
                                                      * (float)((float)(v8[20] * v59)
                                                              + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
                              - v8[44])
                      * v69));
  v71 = (float)((float)((float)((float)(v8[42] * v74)
                              + (float)((float)(v8[40]
                                              * (float)((float)(v8[21] * v56)
                                                      + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                                      + (float)(v8[41]
                                              * (float)((float)(v8[21] * v59)
                                                      + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
                      - v8[45])
              * v68)
      - (float)((float)((float)((float)(v8[42]
                                      * (float)((float)(v8[20] * v62)
                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                              + (float)((float)(v8[40] * (float)v15)
                                      + (float)(v8[41]
                                              * (float)((float)(v8[20] * v59)
                                                      + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
                      - v8[44])
              * v69);
  v24 = (float)((float)((float)(v8[26] * v74)
                      + (float)((float)(v8[24]
                                      * (float)((float)(v8[21] * v56)
                                              + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                              + (float)(v8[25]
                                      * (float)((float)(v8[21] * v59)
                                              + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
              - v8[29]);
  v23 = (float)((float)((float)(v8[26]
                              * (float)((float)(v8[20] * v62) + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                      + (float)((float)(v8[24] * (float)v15)
                              + (float)(v8[25]
                                      * (float)((float)(v8[20] * v59)
                                              + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
              - v8[28]);
  if ( __fabs((float)((float)((float)v21 * (float)v25)
                    + (float)((float)((float)((float)((float)(v8[26] * v74)
                                                    + (float)((float)(v8[24]
                                                                    * (float)((float)(v8[21] * v56)
                                                                            + (float)((float)(v8[5] * (float)v10)
                                                                                    + (float)(v8[13] * v55))))
                                                            + (float)(v8[25]
                                                                    * (float)((float)(v8[21] * v59)
                                                                            + (float)((float)(v8[5] * v57)
                                                                                    + (float)(v8[13] * v58))))))
                                            - v8[29])
                                    * v73)
                            + (float)((float)((float)((float)(v8[26]
                                                            * (float)((float)(v8[20] * v62)
                                                                    + (float)((float)(v8[4] * v60)
                                                                            + (float)(v8[12] * v61))))
                                                    + (float)((float)(v8[24] * (float)v15)
                                                            + (float)(v8[25]
                                                                    * (float)((float)(v8[20] * v59)
                                                                            + (float)((float)(v8[4] * v57)
                                                                                    + (float)(v8[12] * v58))))))
                                            - v8[28])
                                    * v72)))) < (float)9.9999998e-15 )
    return 0;
  v26 = (float)((float)((float)((float)(v8[42]
                                      * (float)((float)(v8[20] * v62)
                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                              + (float)((float)(v8[40] * (float)v15)
                                      + (float)(v8[41]
                                              * (float)((float)(v8[20] * v59)
                                                      + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
                      - v8[44])
              * (float)v21);
  v27 = (float)((float)((float)((float)(v8[34] * v74)
                              + (float)((float)(v8[32]
                                              * (float)((float)(v8[21] * v56)
                                                      + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                                      + (float)(v8[33]
                                              * (float)((float)(v8[21] * v59)
                                                      + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))))
                      - v8[37])
              * (float)v21);
  v28 = (float)((float)1.0
              / (float)((float)((float)v21 * (float)v25)
                      + (float)((float)((float)((float)((float)(v8[26]
                                                              * (float)((float)(v8[21] * v62)
                                                                      + (float)((float)(v8[5] * v60)
                                                                              + (float)(v8[13] * v61))))
                                                      + (float)((float)(v8[24]
                                                                      * (float)((float)(v8[21] * v56)
                                                                              + (float)((float)(v8[5] * (float)v10)
                                                                                      + (float)(v8[13] * v55))))
                                                              + (float)(v8[25]
                                                                      * (float)((float)(v8[21] * v59)
                                                                              + (float)((float)(v8[5] * v57)
                                                                                      + (float)(v8[13] * v58))))))
                                              - v8[29])
                                      * v73)
                              + (float)((float)((float)((float)(v8[26]
                                                              * (float)((float)(v8[20] * v62)
                                                                      + (float)((float)(v8[4] * v60)
                                                                              + (float)(v8[12] * v61))))
                                                      + (float)((float)(v8[24] * (float)v15)
                                                              + (float)(v8[25]
                                                                      * (float)((float)(v8[20] * v59)
                                                                              + (float)((float)(v8[4] * v57)
                                                                                      + (float)(v8[12] * v58))))))
                                              - v8[28])
                                      * v72))));
  v52 = v8[40];
  v50 = v8[25] * (float)v9;
  v29 = (float)((float)((float)((float)((float)((float)(v8[42]
                                                      * (float)((float)(v8[20] * v62)
                                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                                              + (float)((float)(v52 * (float)v15)
                                                      + (float)(v8[41]
                                                              * (float)((float)(v8[20] * v59)
                                                                      + (float)((float)(v8[4] * v57)
                                                                              + (float)(v8[12] * v58))))))
                                      - v8[44])
                              * (float)v24)
                      - (float)((float)((float)((float)(v8[42] * v74)
                                              + (float)((float)(v52
                                                              * (float)((float)(v8[21] * v56)
                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                              + (float)(v8[13] * v55))))
                                                      + (float)(v8[41]
                                                              * (float)((float)(v8[21] * v59)
                                                                      + (float)((float)(v8[5] * v57)
                                                                              + (float)(v8[13] * v58))))))
                                      - v8[45])
                              * (float)((float)((float)(v8[26]
                                                      * (float)((float)(v8[20] * v62)
                                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                                              + (float)((float)(v8[24] * (float)v15)
                                                      + (float)(v8[25]
                                                              * (float)((float)(v8[20] * v59)
                                                                      + (float)((float)(v8[4] * v57)
                                                                              + (float)(v8[12] * v58))))))
                                      - v8[28])))
              * (float)v28);
  v30 = dst->mat;
  v20 = (float)((float)(v8[42] * v74)
              + (float)((float)(v52
                              * (float)((float)(v8[21] * v56)
                                      + (float)((float)(v8[5] * (float)v10) + (float)(v8[13] * v55))))
                      + (float)(v8[41]
                              * (float)((float)(v8[21] * v59) + (float)((float)(v8[5] * v57) + (float)(v8[13] * v58))))));
  v31 = (float)((float)((float)((float)((float)v20 - v8[45]) * (float)v21) - (float)(v70 * (float)v24))
              * (float)((float)1.0
                      / (float)((float)((float)v21 * (float)v25)
                              + (float)((float)((float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[21] * v62)
                                                                              + (float)((float)(v8[5] * v60)
                                                                                      + (float)(v8[13] * v61))))
                                                              + (float)((float)(v8[24]
                                                                              * (float)((float)(v8[21] * v56)
                                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                                              + (float)(v8[13] * v55))))
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[21] * v59)
                                                                                      + (float)((float)(v8[5] * v57)
                                                                                              + (float)(v8[13] * v58))))))
                                                      - v8[29])
                                              * v73)
                                      + (float)((float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[20] * v62)
                                                                              + (float)((float)(v8[4] * v60)
                                                                                      + (float)(v8[12] * v61))))
                                                              + (float)((float)(v8[24] * (float)v15)
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[20] * v59)
                                                                                      + (float)((float)(v8[4] * v57)
                                                                                              + (float)(v8[12] * v58))))))
                                                      - v8[28])
                                              * v72)))));
  v32 = (float)((float)(v8[34] * v61) + (float)((float)(v8[32] * v55) + (float)(v8[33] * v58)));
  v33 = (float)((float)(v8[34] * v60) + (float)((float)(v8[32] * (float)v10) + (float)(v8[33] * (float)v9)));
  v34 = (float)((float)(v8[34] * v62) + (float)((float)(v8[32] * v56) + (float)(v8[33] * v59)));
  v22 = (float)((float)((float)(v8[34]
                              * (float)((float)(v8[20] * v62) + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                      + (float)((float)(v8[32] * (float)v15)
                              + (float)(v8[33]
                                      * (float)((float)(v8[20] * v59)
                                              + (float)((float)(v8[4] * v57) + (float)(v8[12] * v58))))))
              - v8[36]);
  v35 = (float)((float)((float)(v69
                              * (float)((float)((float)(v8[26]
                                                      * (float)((float)(v8[20] * v62)
                                                              + (float)((float)(v8[4] * v60) + (float)(v8[12] * v61))))
                                              + (float)((float)(v8[24] * (float)v15)
                                                      + (float)(v8[25]
                                                              * (float)((float)(v8[20] * v59)
                                                                      + (float)((float)(v8[4] * v57)
                                                                              + (float)(v8[12] * v58))))))
                                      - v8[28]))
                      - (float)((float)v22
                              * (float)((float)((float)(v8[26]
                                                      * (float)((float)(v8[21] * v62)
                                                              + (float)((float)(v8[5] * v60) + (float)(v8[13] * v61))))
                                              + (float)((float)(v8[24]
                                                              * (float)((float)(v8[21] * v56)
                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                              + (float)(v8[13] * v55))))
                                                      + (float)(v8[25]
                                                              * (float)((float)(v8[21] * v59)
                                                                      + (float)((float)(v8[5] * v57)
                                                                              + (float)(v8[13] * v58))))))
                                      - v8[29])))
              * (float)v28);
  v36 = (float)((float)((float)(v67
                              * (float)((float)((float)(v8[26]
                                                      * (float)((float)(v8[21] * v62)
                                                              + (float)((float)(v8[5] * v60) + (float)(v8[13] * v61))))
                                              + (float)((float)(v8[24]
                                                              * (float)((float)(v8[21] * v56)
                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                              + (float)(v8[13] * v55))))
                                                      + (float)(v8[25]
                                                              * (float)((float)(v8[21] * v59)
                                                                      + (float)((float)(v8[5] * v57)
                                                                              + (float)(v8[13] * v58))))))
                                      - v8[29]))
                      - (float)v27)
              * (float)v28);
  v37 = (float)((float)(v8[42] * v62) + (float)((float)(v52 * v56) + (float)(v8[41] * v59)));
  v38 = (float)((float)(v8[42] * v60) + (float)((float)(v52 * (float)v10) + (float)(v8[41] * (float)v9)));
  v40 = (float)((float)(v8[26] * v60) + (float)((float)(v8[24] * (float)v10) + v50));
  v41 = (float)(v71 * (float)v28);
  v42 = (float)((float)(v8[26] * v61) + (float)((float)(v8[24] * v55) + (float)(v8[25] * v58)));
  v43 = (float)((float)((float)((float)((float)(v69
                                              * (float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[20] * v62)
                                                                              + (float)((float)(v8[4] * v60)
                                                                                      + (float)(v8[12] * v61))))
                                                              + (float)((float)(v8[24] * (float)v15)
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[20] * v59)
                                                                                      + (float)((float)(v8[4] * v57)
                                                                                              + (float)(v8[12] * v58))))))
                                                      - v8[28]))
                                      - (float)((float)v22
                                              * (float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[21] * v62)
                                                                              + (float)((float)(v8[5] * v60)
                                                                                      + (float)(v8[13] * v61))))
                                                              + (float)((float)(v8[24]
                                                                              * (float)((float)(v8[21] * v56)
                                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                                              + (float)(v8[13] * v55))))
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[21] * v59)
                                                                                      + (float)((float)(v8[5] * v57)
                                                                                              + (float)(v8[13] * v58))))))
                                                      - v8[29])))
                              * (float)v28)
                      * (float)((float)(v8[42] * v61) + (float)((float)(v52 * v55) + (float)(v8[41] * v58))))
              + (float)((float)v29
                      * (float)((float)(v8[34] * v61) + (float)((float)(v8[32] * v55) + (float)(v8[33] * v58)))));
  v44 = (float)((float)((float)((float)((float)(v69
                                              * (float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[20] * v62)
                                                                              + (float)((float)(v8[4] * v60)
                                                                                      + (float)(v8[12] * v61))))
                                                              + (float)((float)(v8[24] * (float)v15)
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[20] * v59)
                                                                                      + (float)((float)(v8[4] * v57)
                                                                                              + (float)(v8[12] * v58))))))
                                                      - v8[28]))
                                      - (float)((float)v22
                                              * (float)((float)((float)(v8[26]
                                                                      * (float)((float)(v8[21] * v62)
                                                                              + (float)((float)(v8[5] * v60)
                                                                                      + (float)(v8[13] * v61))))
                                                              + (float)((float)(v8[24]
                                                                              * (float)((float)(v8[21] * v56)
                                                                                      + (float)((float)(v8[5] * (float)v10)
                                                                                              + (float)(v8[13] * v55))))
                                                                      + (float)(v8[25]
                                                                              * (float)((float)(v8[21] * v59)
                                                                                      + (float)((float)(v8[5] * v57)
                                                                                              + (float)(v8[13] * v58))))))
                                                      - v8[29])))
                              * (float)v28)
                      * (float)((float)(v8[42] * v62) + (float)((float)(v52 * v56) + (float)(v8[41] * v59))))
              + (float)((float)v29
                      * (float)((float)(v8[34] * v62) + (float)((float)(v8[32] * v56) + (float)(v8[33] * v59)))));
  v39 = (float)((float)(v8[42] * v61) + (float)((float)(v52 * v55) + (float)(v8[41] * v58)));
  v46 = (float)((float)(v8[26] * v62) + (float)((float)(v8[24] * v56) + (float)(v8[25] * v59)));
  v30[24] = (float)((float)(v71 * (float)v28)
                  * (float)((float)(v8[26] * v60) + (float)((float)(v8[24] * (float)v10) + v50)))
          + (float)((float)((float)v35 * (float)v38) + (float)((float)v29 * (float)v33));
  v47 = (float)(v72 * (float)v28);
  v30[25] = (float)((float)(v71 * (float)v28) * (float)v42) + (float)v43;
  v48 = (float)((float)((float)(v68 * v66) - (float)(v67 * (float)v23)) * (float)v28);
  v45 = (float)((float)((float)(v70 * (float)v23) - (float)v26) * (float)v28);
  v30[26] = (float)((float)(v71 * (float)v28) * (float)v46) + (float)v44;
  v30[32] = (float)((float)(v72 * (float)v28) * (float)v40)
          + (float)((float)((float)v36 * (float)v38) + (float)((float)v31 * (float)v33));
  v30[33] = (float)((float)(v72 * (float)v28) * (float)v42)
          + (float)((float)((float)v36 * (float)v39) + (float)((float)v31 * (float)v32));
  v30[34] = (float)((float)(v72 * (float)v28) * (float)v46)
          + (float)((float)((float)v36 * (float)v37) + (float)((float)v31 * (float)v34));
  v49 = (float)(v73 * (float)v28);
  v30[40] = (float)((float)v49 * (float)v40)
          + (float)((float)((float)v48 * (float)v38) + (float)((float)v45 * (float)v33));
  v30[41] = (float)((float)v49 * (float)v42)
          + (float)((float)((float)v48 * (float)v39) + (float)((float)v45 * (float)v32));
  v30[42] = (float)((float)v49 * (float)v46)
          + (float)((float)((float)v48 * (float)v37) + (float)((float)v45 * (float)v34));
  *v30 = -(float)((float)(v30[40] * (float)v17)
                - (float)-(float)((float)(v30[32] * (float)v15) - (float)-(float)((float)(v30[24] * (float)v16) - v54)));
  v30[1] = -(float)((float)(v30[41] * (float)v17)
                  - (float)-(float)((float)(v30[33] * (float)v15) - (float)-(float)((float)((float)v16 * v30[25]) - v55)));
  v53 = -v41;
  v64 = -v35;
  v30[2] = -(float)((float)(v30[42] * (float)v17)
                  - (float)-(float)((float)((float)v15 * v30[34]) - (float)-(float)((float)(v30[26] * (float)v16) - v56)));
  v30[8] = -(float)((float)(v30[40] * (float)v14)
                  - (float)-(float)((float)(v30[32] * (float)v12) - (float)-(float)((float)(v30[24] * (float)v13) - v57)));
  v51 = -v29;
  v63 = -v45;
  v65 = -v48;
  v30[9] = -(float)((float)(v30[41] * (float)v14)
                  - (float)-(float)((float)(v30[33] * (float)v12) - (float)-(float)((float)(v30[25] * (float)v13) - v58)));
  v30[10] = -(float)((float)((float)v14 * v30[42])
                   - (float)-(float)((float)(v30[34] * (float)v12) - (float)-(float)((float)(v30[26] * (float)v13) - v59)));
  v30[16] = -(float)((float)(v30[40] * v74)
                   - (float)-(float)((float)(v30[32] * (float)v19) - (float)-(float)((float)(v30[24] * (float)v18) - v60)));
  v30[17] = -(float)((float)(v30[41] * v74)
                   - (float)-(float)((float)(v30[33] * (float)v19) - (float)-(float)((float)(v30[25] * (float)v18) - v61)));
  v30[18] = -(float)((float)(v74 * v30[42])
                   - (float)-(float)((float)(v30[34] * (float)v19) - (float)-(float)((float)(v30[26] * (float)v18) - v62)));
  v30[3] = (float)((float)v41 * (float)v16)
         + (float)((float)((float)v49 * (float)v17) + (float)((float)v47 * (float)v15));
  v30[4] = (float)((float)v29 * (float)v16)
         + (float)((float)((float)v45 * (float)v17) + (float)((float)v31 * (float)v15));
  v30[5] = (float)((float)v35 * (float)v16)
         + (float)((float)((float)v48 * (float)v17) + (float)((float)v36 * (float)v15));
  v30[11] = (float)((float)v41 * (float)v13)
          + (float)((float)((float)v49 * (float)v14) + (float)((float)v47 * (float)v12));
  v30[12] = (float)((float)v29 * (float)v13)
          + (float)((float)((float)v45 * (float)v14) + (float)((float)v31 * (float)v12));
  v30[13] = (float)((float)v35 * (float)v13)
          + (float)((float)((float)v48 * (float)v14) + (float)((float)v36 * (float)v12));
  v30[19] = (float)((float)v41 * (float)v18) + (float)((float)((float)v49 * v74) + (float)((float)v47 * (float)v19));
  v30[20] = (float)((float)v29 * (float)v18) + (float)((float)((float)v45 * v74) + (float)((float)v31 * (float)v19));
  v30[21] = (float)((float)v35 * (float)v18) + (float)((float)((float)v48 * v74) + (float)((float)v36 * (float)v19));
  v30[27] = v53;
  v30[28] = v51;
  v30[29] = v64;
  v30[35] = -v47;
  v30[36] = -v31;
  v30[37] = -v36;
  v30[43] = -v49;
  v30[44] = v63;
  v30[45] = v65;
  return 1;
}

