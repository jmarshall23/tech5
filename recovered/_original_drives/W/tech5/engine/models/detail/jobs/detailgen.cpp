
// ========================================================================
// ?CalculateDetailBounds@@YAXPBUdm_detail_t@@PBVidDetailPaletteData@@AAVidBounds@@@Z
// EA  : 0x827CD5A0
// RVA : 0x007CD5A0
// PDB : w:\tech5\engine\models\detail\jobs\detailgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall CalculateDetailBounds(
        const dm_detail_t *detail,
        const idDetailPaletteData *data,
        idBounds *bounds,
        __int64 a4)
{
  double v6; // fp31
  __int64 v7; // r5 OVERLAPPED
  __int64 v8; // r8 OVERLAPPED
  double y; // fp12
  double z; // fp11
  double v11; // fp9
  double v12; // fp7
  idMat3 v13; // [sp+60h] [-50h] BYREF

  LODWORD(a4) = detail->uniformSizeScale;
  *bounds = data->bounds;
  v6 = (float)((float)a4 * (float)0.0099999998);
  idCQuat::ToMat3(this: (idCQuat *)&v13, result: (idMat3 *)&detail->rotation);
  v13.mat[0].x = v13.mat[0].x * (float)v6;
  v13.mat[0].y = v13.mat[0].y * (float)v6;
  v13.mat[0].z = v13.mat[0].z * (float)v6;
  v13.mat[1].x = v13.mat[1].x * (float)v6;
  v13.mat[1].y = v13.mat[1].y * (float)v6;
  v13.mat[1].z = v13.mat[1].z * (float)v6;
  v13.mat[2].x = v13.mat[2].x * (float)v6;
  v13.mat[2].y = v13.mat[2].y * (float)v6;
  v13.mat[2].z = v13.mat[2].z * (float)v6;
  idBounds::FromTransformedBounds(this: bounds, bounds, origin: &vec3_origin, axis: &v13);
  HIDWORD(v7) = (unsigned __int16)detail->xyz[1];
  LODWORD(v8) = SWORD1(v7);
  HIDWORD(v8) = detail->xyz[2];
  y = bounds->b[0].y;
  LODWORD(v7) = detail->xyz[0];
  z = bounds->b[0].z;
  bounds->b[0].x = bounds->b[0].x + (float)v7;
  bounds->b[0].y = (float)y + (float)v8;
  bounds->b[0].z = (float)z + (float)*(__int64 *)((char *)&v8 + 4);
  v11 = (float)(bounds->b[1].y + (float)v8);
  v12 = (float)(bounds->b[1].z + (float)*(__int64 *)((char *)&v8 + 4));
  bounds->b[1].x = bounds->b[1].x + (float)v7;
  bounds->b[1].y = v11;
  bounds->b[1].z = v12;
}


// ========================================================================
// ?GetDetailTotalCount@@YAXPBUdetailSubTreeStats_t@@PAUdetailGenTotals_t@@@Z
// EA  : 0x827CD758
// RVA : 0x007CD758
// PDB : w:\tech5\engine\models\detail\jobs\detailgen.cpp
// ========================================================================

void __fastcall GetDetailTotalCount(const detailSubTreeStats_t *detailCountsList, detailGenTotals_t *totalsCount)
{
  int v2; // r10
  const detailSubTreeStats_t *v3; // r11
  int totalIndices; // r8

  v2 = 0;
  totalsCount->totalVerts = 0;
  totalsCount->totalIndices = 0;
  if ( detailCountsList->subTreeDetailCount != -1 )
  {
    v3 = detailCountsList;
    do
    {
      ++v2;
      totalIndices = totalsCount->totalIndices;
      totalsCount->totalVerts += v3->vertCount;
      totalsCount->totalIndices = v3->indexCount + totalIndices;
      v3 = &detailCountsList[v2];
    }
    while ( v3->subTreeDetailCount != -1 );
  }
}


// ========================================================================
// ?GetDetailOffsetsForSubTree@@YAXPBUdetailSubTreeStats_t@@HAAH1@Z
// EA  : 0x827CD7B0
// RVA : 0x007CD7B0
// PDB : w:\tech5\engine\models\detail\jobs\detailgen.cpp
// ========================================================================

void __fastcall GetDetailOffsetsForSubTree(
        const detailSubTreeStats_t *detailCountsList,
        int subTreeIndex,
        int *vertCount,
        int *indexCount)
{
  int *p_indexCount; // r11
  int i; // ctr

  *vertCount = 0;
  *indexCount = 0;
  if ( subTreeIndex > 0 )
  {
    p_indexCount = &detailCountsList[-1].indexCount;
    for ( i = subTreeIndex; i != 0; --i )
    {
      *vertCount += p_indexCount[3];
      p_indexCount += 4;
      *indexCount += *p_indexCount;
    }
  }
}


// ========================================================================
// ?BuildDetailModel@@YAXPBUdetailPalette_t@@PAVidDrawVert@@PAGHPBUdm_detail_t@@PBUdm_attribute_t@@AAUdetailGenTotals_t@@@Z
// EA  : 0x827CD7F8
// RVA : 0x007CD7F8
// PDB : w:\tech5\engine\models\detail\jobs\detailgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall BuildDetailModel(
        const detailPalette_t *palette,
        idDrawVert *verts,
        unsigned __int16 *indices,
        __int64 detail,
        const dm_attribute_t *attribute,
        detailGenTotals_t *totals)
{
  int v6; // r2 OVERLAPPED
  detailPaletteVert_t *v9; // r9
  unsigned __int16 *v10; // r8
  int vertOffset; // r11
  int numIndices; // r25
  int indexOffset; // r31
  unsigned __int16 numVerts; // r3
  int v15; // r10
  signed int v16; // r11
  char *v17; // r30
  char *v18; // r9
  char *v19; // r11
  unsigned int v20; // r8
  unsigned __int16 *v21; // r10
  unsigned int v22; // ctr
  int v23; // r8
  int v24; // r8
  double v25; // fp12
  double v26; // fp11
  double v27; // fp10
  int v28; // r27
  double v29; // fp31
  idVec3 *v30; // r31
  char *v31; // r30
  __int64 v32; // r4
  int v33; // r11
  int v34; // r5
  int v35; // r29
  __int64 v36; // r10 OVERLAPPED
  double v37; // fp29
  unsigned int v38; // r28
  double v39; // fp28
  double v40; // fp27
  __int64 v41; // r6
  int v42; // r3
  signed __int16 v43; // r11
  __int64 v45; // r5
  double v46; // fp1
  double v47; // fp13
  double v48; // fp12
  int v49; // ctr
  int v54; // r10
  idQuat v55; // [sp+58h] [-6F8h] BYREF
  idVec3 v56; // [sp+70h] [-6E0h] BYREF
  float v57; // [sp+7Ch] [-6D4h]
  unsigned __int64 v58; // [sp+80h] [-6D0h]
  __int64 v59; // [sp+88h] [-6C8h]
  __int64 v60; // [sp+90h] [-6C0h]
  __int64 v61; // [sp+98h] [-6B8h]
  _BYTE v62[16]; // [sp+A0h] [-6B0h] BYREF
  char v63; // [sp+B0h] [-6A0h] BYREF

  v9 = palette->verts;
  v10 = palette->indices;
  vertOffset = palette->entry->vertOffset;
  numIndices = palette->entry->numIndices;
  indexOffset = palette->entry->indexOffset;
  numVerts = palette->entry->numVerts;
  v15 = 2 * (vertOffset + __ROL4__(vertOffset, 2));
  v16 = (numIndices + 1) & 0xFFFFFFFE;
  v17 = (char *)v9 + v15;
  v18 = (char *)v10 + __ROL4__(indexOffset, 1);
  if ( v16 > 0 )
  {
    v20 = (unsigned int)(v16 - 1) >> 1;
    v19 = v18 - 2;
    v21 = indices - 2;
    v22 = v20 + 1;
    do
    {
      v23 = *((unsigned __int16 *)v19 + 1);
      v19 += 4;
      v21 += 2;
      *(_DWORD *)v21 = ((v23 + HIDWORD(detail)) << 16) | (*(unsigned __int16 *)v19 + HIDWORD(detail));
      --v22;
    }
    while ( v22 != 0 );
  }
  v24 = *(unsigned __int8 *)(detail + 7);
  v25 = (float)(*(float *)(detail + 28) * *(float *)(detail + 28));
  v26 = *(float *)(detail + 24);
  v27 = *(float *)(detail + 20);
  v28 = numVerts;
  v56.z = *(float *)(detail + 28);
  v56.y = v26;
  v56.x = v27;
  v29 = (float)((float)*(__int64 *)((char *)&detail - 4) * (float)0.0099999998);
  v57 = __fsqrts(__fabs((float)((float)1.0
                              - (float)((float)((float)v27 * (float)v27)
                                      + (float)((float)((float)v26 * (float)v26) + (float)v25)))));
  if ( numVerts != 0 )
  {
    v30 = (idVec3 *)v62;
    v31 = v17 - 2;
    LODWORD(v32) = *(__int16 *)detail;
    HIDWORD(v36) = *(unsigned __int16 *)(detail + 4);
    v33 = *(__int16 *)(detail + 2);
    v34 = *(unsigned __int8 *)(detail + 8);
    HIDWORD(v32) = *(unsigned __int8 *)(detail + 9);
    v35 = v28;
    LODWORD(v36) = *(unsigned __int8 *)(detail + 10);
    LODWORD(detail) = SWORD1(v36);
    v37 = (float)v32;
    v38 = ((((__ROL4__(v34, 8) | HIDWORD(v32)) << 8) | (unsigned int)v36) << 8) | 0xFF;
    v39 = (float)*(__int64 *)((char *)&v36 - 4);
    v40 = (float)detail;
    do
    {
      HIDWORD(v41) = v30;
      v42 = *((__int16 *)v31 + 2);
      v43 = *((_WORD *)v31 + 3);
      LODWORD(v36) = *((__int16 *)v31 + 1);
      v59 = *(_QWORD *)(&v6 - 1);
      LODWORD(v41) = v43;
      v60 = v36;
      v30->z = (float)v41;
      v30->x = (float)v36;
      v30->y = (float)*(__int64 *)(&v6 - 1);
      idQuat::operator*(this: &v55, result: &v56, a: v30);
      HIDWORD(v36) = *((unsigned __int16 *)v31 + 4);
      v31 += 10;
      LODWORD(v45) = *(unsigned __int16 *)v31;
      v46 = (float)(v55.x * (float)v29);
      v58 = __PAIR64__(v45, HIDWORD(v36));
      v61 = v45;
      v47 = (float)(v55.y * (float)v29);
      v48 = (float)(v55.z * (float)v29);
      v30->x = v55.x * (float)v29;
      v30->y = v47;
      --v35;
      v30->z = v48;
      v30->x = (float)v37 + (float)v46;
      v30->y = v30->y + (float)v39;
      v30->z = (float)v40 + v30->z;
      v30[1].x = (float)__SPAIR64__(v45, HIDWORD(v36)) * (float)0.000015259022;
      v30[1].y = (float)v45 * (float)0.000015259022;
      LODWORD(v30[2].y) = v38;
      v30 = (idVec3 *)((char *)v30 + 32);
    }
    while ( v35 != 0 );
    if ( v28 > 0 )
    {
      v49 = v28;
      _R11 = verts;
      _R10 = v62 - (_BYTE *)verts;
      _R9 = &v63 - (char *)verts;
      _R8 = 16;
      do
      {
        __asm
        {
          lvx128    v63, r10, r11
          stvx128   v63, r0, r11
          lvx128    v62, r9, r11
          stvx128   v62, r11, r8
        }
        ++_R11;
        --v49;
      }
      while ( v49 != 0 );
    }
  }
  v54 = numIndices + totals->totalIndices;
  totals->totalVerts += v28;
  totals->totalIndices = v54;
}


// ========================================================================
// ?GenDetailForSubTree@@YAHPBUdeferredDetailGenParms_t@@PBGHHHHAAUdetailGenTotals_t@@@Z
// EA  : 0x827CDAF0
// RVA : 0x007CDAF0
// PDB : w:\tech5\engine\models\detail\jobs\detailgen.cpp
// ========================================================================

int __fastcall GenDetailForSubTree(
        const deferredDetailGenParms_t *parms,
        const unsigned __int16 *detailIndices,
        int numDetail,
        int vertexBufferOffset,
        int indexBufferOffset,
        int indexOffset,
        const dm_attribute_t *totals)
{
  const dm_subTreeData_t *subTreeData; // r11
  char *v13; // r22
  char *v14; // r21
  const unsigned __int16 *v15; // r28
  int i; // r29
  detailPaletteEntry_t *paletteEntries; // r10
  __int64 v18; // r8
  int v19; // r5
  unsigned __int16 *paletteIndices; // r19
  int v21; // r8
  unsigned __int16 *indices; // r26
  idDrawVert *verts; // r27
  int v24; // r11
  idDrawVert *v25; // r4
  detailPalette_t v27; // [sp+50h] [-80h] BYREF

  *(_DWORD *)&totals->declIdx = 0;
  totals->pad[0] = 0;
  totals->pad[2] = 0;
  totals->pad[1] = 0;
  subTreeData = parms->subTreeData;
  v13 = (char *)subTreeData + subTreeData->detailOffset;
  v14 = (char *)subTreeData + subTreeData->attributeOffset;
  if ( numDetail > 0 )
  {
    v15 = detailIndices - 1;
    for ( i = numDetail; i != 0; --i )
    {
      ++v15;
      paletteEntries = parms->paletteEntries;
      HIDWORD(v18) = &v13[__ROL4__(*v15, 5)];
      v19 = indexBufferOffset + totals->pad[0];
      paletteIndices = parms->paletteIndices;
      v21 = *(_DWORD *)&totals->declIdx + vertexBufferOffset;
      indices = parms->indices;
      v27.verts = parms->paletteVerts;
      verts = parms->verts;
      v24 = *(unsigned __int8 *)(HIDWORD(v18) + 6);
      v27.indices = paletteIndices;
      v25 = &verts[v21];
      LODWORD(v18) = &v14[__ROL4__(v24, 5)];
      v27.entry = (detailPaletteEntry_t *)((char *)paletteEntries + __ROL4__(*(unsigned __int16 *)(v18 + 2), 3));
      BuildDetailModel(
        palette: &v27,
        verts: v25,
        indices: &indices[v19],
        detail: v18,
        attribute: totals,
        totals: (detailGenTotals_t *)v27.entry);
    }
  }
  return numDetail;
}

