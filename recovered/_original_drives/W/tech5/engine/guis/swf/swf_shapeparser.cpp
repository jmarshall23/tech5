
// ========================================================================
// ?FindEarVert@idSWFShapeParser@@AAAHABUswfSPLineLoop_t@1@@Z
// EA  : 0x8278DC50
// RVA : 0x0078DC50
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

int __fastcall idSWFShapeParser::FindEarVert(idSWFShapeParser *this, const idSWFShapeParser::swfSPLineLoop_t *loop)
{
  int num; // r30
  unsigned __int64 v5; // r10
  float *v6; // r8
  float *v7; // r7
  float *v8; // r6
  int size; // r11
  signed int v10; // r17
  idVehicleState **list; // r18
  idVehicleState **v12; // r11
  unsigned __int16 *v13; // r3
  idVec2 *v14; // r5
  int v15; // r24
  float *v16; // r4
  int v17; // r22
  float *v18; // r3
  float *v19; // r5
  double v20; // fp9
  double v21; // fp8
  double v22; // fp6
  double v23; // fp5
  int v24; // r23
  idVec2 *v25; // r4
  unsigned __int16 *v26; // r5
  int v27; // r29
  int v28; // r5
  int v29; // r24
  double v30; // fp2
  double v31; // fp1
  float *v32; // r5
  double v33; // fp0
  double v34; // fp13
  float *v35; // r5
  double v36; // fp7
  double v37; // fp6
  unsigned __int16 *v38; // r7
  idVec2 *v39; // r5
  int v40; // r20
  int v41; // r3
  int v42; // r16
  float *v43; // r7
  float *v44; // r3
  float *v45; // r5
  double v46; // fp11
  double v47; // fp1
  double v48; // fp13
  double v49; // fp9
  idVec2 *v50; // r7
  unsigned __int16 *v51; // r3
  float *v52; // r5
  float *v53; // r4
  int v54; // r11
  int v55; // ctr
  unsigned __int16 *v56; // r3
  idVec2 *v57; // r8
  int v58; // r28
  int v59; // r26
  double v60; // fp0
  double v61; // fp13
  double v62; // fp12
  signed int v63; // r20
  idVehicleState **v64; // r24
  int v65; // r21
  int v66; // r23
  unsigned __int16 *v67; // r8
  int v68; // r6
  idVehicleState *v69; // r22
  idVec2 *v70; // r11
  unsigned __int16 *v71; // r5
  int v72; // r9
  float *v73; // r29
  int v74; // r6
  float *v75; // r28
  int v76; // r10
  int v77; // r8
  float *v78; // r26
  double v79; // fp13
  float *v80; // r10
  float *v81; // r9
  double v82; // fp12
  float *v83; // r11
  double v84; // fp9
  double v85; // fp8
  double v86; // fp5
  double v87; // fp4
  char v88; // r4
  int v89; // r6
  int v90; // r5
  __int64 v91; // r8
  double v92; // fp0
  double v93; // fp13
  char v94; // r11
  char v95; // r11
  char v96; // r11
  bool v97; // r11
  float *v98; // r11
  double v99; // fp13
  double v100; // fp0
  bool v101; // r11
  int v103; // [sp+50h] [-150h]
  idSort_Quick<earVert_t,idSort_Ears> v104; // [sp+58h] [-148h] BYREF
  idList<idVehicleState *,5> v105; // [sp+60h] [-140h] BYREF
  idMat3 v106; // [sp+70h] [-130h] BYREF
  idMat3 v107; // [sp+A0h] [-100h] BYREF

  num = loop->vindex1.num;
  memset(&v105, 0, 14);
  *(_WORD *)&v105.memTag = 18432;
  idList<idThread *,58>::Clear(this: &v105);
  size = v105.size;
  if ( num > v105.size )
  {
    if ( !idList<idPlayerCoverScore_t,5>::Resize(this: (idList<idPlane,37> *)&v105, newsize: num) )
    {
      v10 = v105.num;
      goto LABEL_8;
    }
    size = v105.size;
  }
  if ( num >= size )
  {
    v10 = size;
    v105.num = size;
  }
  else
  {
    v10 = num;
    v105.num = num;
  }
LABEL_8:
  list = v105.list;
  HIDWORD(v5) = 0;
  if ( num >= 4 )
  {
    LODWORD(v5) = 2;
    v6 = nullptr;
    v12 = v105.list - 2;
    do
    {
      v13 = loop->vindex1.list;
      v14 = this->verts.list;
      v15 = ((int)v5 - 1) % num;
      v8 = (float *)(v5 + 1);
      v16 = (float *)((char *)&v14->x + __ROL4__(*(unsigned __int16 *)((char *)v6 + (_DWORD)v13), 3));
      v17 = v13[v15];
      v18 = (float *)((char *)&v14->x + __ROL4__(v13[(int)v5 % num], 3));
      v19 = (float *)((char *)&v14->x + __ROL4__(v17, 3));
      v20 = (float)(*v19 - *v18);
      v21 = (float)(v16[1] - v19[1]);
      v22 = (float)(*v16 - *v19);
      v23 = (float)(v19[1] - v18[1]);
      __twlgei(num & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
      v24 = ((int)v5 + 1) % num;
      __twlgei(num & ~(__ROL4__(v5 - 1, 1) - 1), 0xFFFFFFFF);
      __twlgei(num & ~(__ROL4__(v5 + 1, 1) - 1), 0xFFFFFFFF);
      __twllei(num, 0);
      __twllei(num, 0);
      *((float *)v12 + 5) = (float)((float)v23 * (float)v22) - (float)((float)v20 * (float)v21);
      v12[3] = (idVehicleState *)v15;
      __twllei(num, 0);
      v12[2] = (idVehicleState *)HIDWORD(v5);
      v12[4] = (idVehicleState *)((int)v5 % num);
      v25 = this->verts.list;
      v26 = loop->vindex1.list;
      v27 = v26[v24];
      v29 = *(unsigned __int16 *)((char *)v6 + (_DWORD)v26 + 2);
      v28 = __ROL4__(v26[(int)v5 % num], 3);
      v30 = *(float *)((char *)&v25->y + v28);
      v31 = *(float *)((char *)&v25->x + v28);
      v32 = (float *)((char *)&v25->x + __ROL4__(v27, 3));
      v33 = v32[1];
      v34 = *v32;
      v35 = (float *)((char *)&v25->x + __ROL4__(v29, 3));
      v36 = (float)(*v35 - (float)v31);
      v37 = (float)((float)((float)v31 - (float)v34) * (float)(v35[1] - (float)v30));
      __twllei(num, 0);
      __twllei(num, 0);
      *((float *)v12 + 9) = (float)((float)((float)v30 - (float)v33) * (float)v36) - (float)v37;
      v12[6] = (idVehicleState *)(v5 - 1);
      v12[7] = (idVehicleState *)((int)v5 % num);
      v12[8] = (idVehicleState *)v24;
      v103 = ((int)v5 + 2) % num;
      v38 = loop->vindex1.list;
      v39 = this->verts.list;
      v40 = ((int)v5 + 3) % num;
      v41 = v38[v103];
      v42 = *(unsigned __int16 *)((char *)v38 + (_DWORD)v6 + 6 - 2);
      v43 = (float *)((char *)&v39->x + __ROL4__(v38[v24], 3));
      v44 = (float *)((char *)&v39->x + __ROL4__(v41, 3));
      v45 = (float *)((char *)&v39->x + __ROL4__(v42, 3));
      v46 = (float)(v45[1] - v43[1]);
      v47 = (float)(*v43 - *v44);
      v48 = (float)(v43[1] - v44[1]);
      v49 = (float)(*v45 - *v43);
      __twlgei(num & ~(__ROL4__(v5 + 3, 1) - 1), 0xFFFFFFFF);
      __twlgei(num & ~(__ROL4__(v5 + 2, 1) - 1), 0xFFFFFFFF);
      *((float *)v12 + 13) = (float)((float)v48 * (float)v49) - (float)((float)v47 * (float)v46);
      v12[11] = (idVehicleState *)v24;
      v12[12] = (idVehicleState *)v103;
      v12[10] = (idVehicleState *)v5;
      v50 = this->verts.list;
      v51 = loop->vindex1.list;
      v52 = (float *)((char *)&v50->x + __ROL4__(v51[v40], 3));
      v53 = (float *)((char *)&v50->x + __ROL4__(v51[v103], 3));
      v7 = (float *)((char *)&v50->x + __ROL4__(*(unsigned __int16 *)((char *)v51 + (_DWORD)v6 + 6), 3));
      HIDWORD(v5) += 4;
      v6 += 2;
      *((float *)v12 + 17) = (float)((float)(v53[1] - v52[1]) * (float)(*v7 - *v53))
                           - (float)((float)(v7[1] - v53[1]) * (float)(*v53 - *v52));
      v12[14] = (idVehicleState *)(v5 + 1);
      LODWORD(v5) = v5 + 4;
      v12[15] = (idVehicleState *)v103;
      v12 += 16;
      *v12 = (idVehicleState *)v40;
    }
    while ( SHIDWORD(v5) < num - 3 );
  }
  if ( SHIDWORD(v5) < num )
  {
    v7 = (float *)(2 * HIDWORD(v5));
    v54 = (int)&list[4 * HIDWORD(v5) - 2];
    v55 = num - HIDWORD(v5);
    do
    {
      v56 = loop->vindex1.list;
      v57 = this->verts.list;
      __twllei(num, 0);
      v58 = (HIDWORD(v5) + 1) % num;
      v59 = (HIDWORD(v5) + 2) % num;
      v8 = (float *)((char *)&v57->x + __ROL4__(*(unsigned __int16 *)((char *)v56 + (_DWORD)v7), 3));
      LODWORD(v5) = (char *)v57 + __ROL4__(v56[v58], 3);
      v6 = (float *)((char *)&v57->x + __ROL4__(v56[v59], 3));
      v60 = v8[1];
      __twllei(num, 0);
      v61 = *(float *)v5;
      __twlgei(num & ~(__ROL4__(HIDWORD(v5) + 1, 1) - 1), 0xFFFFFFFF);
      v62 = *(float *)(v5 + 4);
      __twlgei(num & ~(__ROL4__(HIDWORD(v5) + 2, 1) - 1), 0xFFFFFFFF);
      v7 = (float *)((char *)v7 + 2);
      *(float *)(v54 + 20) = (float)((float)((float)v62 - v6[1]) * (float)(*v8 - (float)v61))
                           - (float)((float)((float)v60 - (float)v62) * (float)((float)v61 - *v6));
      *(_DWORD *)(v54 + 8) = HIDWORD(v5)++;
      *(_DWORD *)(v54 + 12) = v58;
      v54 += 16;
      *(_DWORD *)v54 = v59;
      --v55;
    }
    while ( v55 != 0 );
  }
  v104.__vftable = (idSort_Quick<earVert_t,idSort_Ears>_vtbl *)&idSort_Ears::`vftable';
  if ( list != nullptr )
    idSort_Quick<earVert_t,idSort_Ears>::Sort(
      this: &v104,
      base: (earVert_t *)list,
      num: v10,
      a4: (int)v8,
      a5: (int)v7,
      a6: (int)v6,
      a7: v5);
  v63 = 0;
  v104.__vftable = (idSort_Quick<earVert_t,idSort_Ears>_vtbl *)&idSort<earVert_t>::`vftable';
  if ( v10 <= 0 )
  {
LABEL_45:
    if ( (v105.listStatic == 0 || v105.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return -1;
  }
  else
  {
    v64 = list + 1;
    while ( 1 )
    {
      if ( *((float *)v64 + 2) >= 0.0 )
      {
        v65 = (int)*(v64 - 1);
        v66 = (int)*v64;
        v67 = loop->vindex1.list;
        v68 = (int)*v64;
        v69 = v64[1];
        v70 = this->verts.list;
        v71 = loop->vindex2.list;
        v72 = __ROL4__(v67[v68], 3);
        v73 = (float *)((char *)&v70->x + __ROL4__(v67[v65], 3));
        v74 = v71[v68];
        v75 = (float *)((char *)&v70->x + v72);
        v76 = __ROL4__(v67[(_DWORD)v69], 3);
        v77 = __ROL4__(v71[(_DWORD)v69], 3);
        v78 = (float *)((char *)&v70->x + v76);
        v79 = v73[1];
        v80 = (float *)((char *)&v70->x + __ROL4__(v71[v65], 3));
        v106.mat[0].x = *v73;
        v106.mat[0].y = v79;
        v106.mat[0].z = 1.0;
        v82 = *(float *)((char *)&v70->y + v72);
        v81 = (float *)((char *)&v70->x + __ROL4__(v74, 3));
        v83 = (float *)((char *)&v70->x + v77);
        v106.mat[1].x = *v75;
        v106.mat[1].z = 1.0;
        v106.mat[1].y = v82;
        v84 = v78[1];
        v106.mat[2].x = *v78;
        v106.mat[2].y = v84;
        v106.mat[2].z = 1.0;
        v85 = v80[1];
        v107.mat[0].x = *v80;
        v107.mat[0].y = v85;
        v107.mat[0].z = 1.0;
        v86 = v81[1];
        v107.mat[1].x = *v81;
        v107.mat[1].y = v86;
        v107.mat[1].z = 1.0;
        v87 = v83[1];
        v107.mat[2].x = *v83;
        v107.mat[2].y = v87;
        v107.mat[2].z = 1.0;
        idMat3::InverseSelf(this: &v106);
        idMat3::InverseSelf(this: &v107);
        v88 = 1;
        v89 = 0;
        if ( num > 0 )
        {
          v90 = 0;
          while ( 1 )
          {
            if ( v89 != v65 && v89 != v66 && (idVehicleState *)v89 != v69 )
            {
              v91 = *(__int64 *)((char *)this->verts.list + __ROL4__(loop->vindex1.list[v90], 3));
              v92 = *(float *)&v91;
              v93 = *((float *)&v91 + 1);
              if ( *v73 != *(float *)&v91 || (v94 = 1, v73[1] != v93) )
                v94 = 0;
              if ( v94 == 0 )
              {
                if ( *v75 != v92 || (v95 = 1, v75[1] != v93) )
                  v95 = 0;
                if ( v95 == 0 )
                {
                  if ( *v78 != v92 || (v96 = 1, v78[1] != v93) )
                    v96 = 0;
                  if ( v96 == 0 )
                  {
                    v97 = (float)((float)((float)(v106.mat[1].x * *((float *)&v91 + 1))
                                        + (float)(v106.mat[0].x * *(float *)&v91))
                                + v106.mat[2].x) > 0.0;
                    if ( v97 == (float)((float)((float)(v106.mat[1].y * *((float *)&v91 + 1))
                                              + (float)(v106.mat[0].y * *(float *)&v91))
                                      + v106.mat[2].y) > 0.0
                      && v97 == (float)((float)((float)(v106.mat[1].z * *((float *)&v91 + 1))
                                              + (float)(v106.mat[0].z * *(float *)&v91))
                                      + v106.mat[2].z) > 0.0 )
                    {
                      break;
                    }
                    v98 = (float *)(__ROL4__(loop->vindex2.list[v90], 3) + HIDWORD(v91));
                    v99 = (float)((float)((float)(v107.mat[1].z * v98[1]) + (float)(v107.mat[0].z * *v98))
                                + v107.mat[2].z);
                    v100 = (float)((float)((float)(v107.mat[1].y * v98[1]) + (float)(v107.mat[0].y * *v98))
                                 + v107.mat[2].y);
                    v101 = (float)((float)((float)(v107.mat[1].x * v98[1]) + (float)(v107.mat[0].x * *v98))
                                 + v107.mat[2].x) > 0.0;
                    if ( v101 == v100 > 0.0 && v101 == v99 > 0.0 )
                      break;
                  }
                }
              }
            }
            ++v89;
            ++v90;
            if ( v89 >= num )
              goto LABEL_43;
          }
          v88 = 0;
        }
LABEL_43:
        if ( v88 != 0 )
          break;
      }
      ++v63;
      v64 += 4;
      if ( v63 >= v10 )
        goto LABEL_45;
    }
    if ( (v105.listStatic == 0 || v105.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return v65;
  }
}


// ========================================================================
// __unwind$223353
// EA  : 0x8278E4D8
// RVA : 0x0078E4D8
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void _unwind_223353()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$223354
// EA  : 0x8278E500
// RVA : 0x0078E500
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void _unwind_223354()
{
  int v0; // r12

  idSort_Ears::~idSort_Ears(this: (idSort_Ears *)(v0 - 416 + 88));
}


// ========================================================================
// ?ParseEdge@idSWFShapeParser@@AAAXAAVidSWFBitStream@@AAH1AAUswfSPEdge_t@1@@Z
// EA  : 0x8278E528
// RVA : 0x0078E528
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFShapeParser::ParseEdge(
        idSWFShapeParser *this,
        idSWFBitStream *bitstream,
        unsigned __int64 penY,
        unsigned __int64 edge)
{
  _DWORD *v6; // r30
  _DWORD *v7; // r29
  _WORD *v8; // r25
  bool v9; // r26
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // r6
  __int128 v12; // r6
  idList<idVec2,72> *p_verts; // r27
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // r6
  int Index; // r3
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // r6
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // r6
  __int64 v21; // r8 OVERLAPPED
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // r6
  unsigned __int64 v24; // r8
  unsigned __int64 v25; // r6
  __int64 v26; // r7
  __int64 v27; // r3
  unsigned __int64 v28; // r8
  unsigned __int64 v29; // r6
  int v30; // r3
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r6
  int v33; // r9
  int v34; // r3
  idVec2 v35; // [sp+50h] [-50h] BYREF

  v6 = (_DWORD *)HIDWORD(penY);
  v7 = (_DWORD *)penY;
  v8 = (_WORD *)HIDWORD(edge);
  v9 = idSWFBitStream::ReadU(this: bitstream, numBits: penY, a3: edge) != 0;
  idSWFBitStream::ReadU(this: bitstream, numBits: v11, a3: v10);
  LODWORD(v12) = *v7;
  DWORD2(v12) = *v6;
  p_verts = &this->verts;
  v35.y = (float)(__int64)v12 * (float)0.050000001;
  v35.x = (float)*(__int64 *)((char *)&v12 + 4) * (float)0.050000001;
  Index = idList<idVec2,72>::FindIndex(this: &this->verts, obj: &v35, startIndex: 0);
  if ( Index < 0 )
    LOWORD(Index) = idList<idVec2,72>::Append(this: p_verts, obj: &v35);
  *v8 = Index;
  if ( v9 )
  {
    v8[2] = -1;
    if ( idSWFBitStream::ReadU(this: bitstream, numBits: v15, a3: v14) != 0 )
    {
      *v6 += idSWFBitStream::ReadS(this: bitstream, numBits: v18, a3: v17);
      *v7 += idSWFBitStream::ReadS(this: bitstream, numBits: v20, a3: v19);
    }
    else if ( idSWFBitStream::ReadU(this: bitstream, numBits: v18, a3: v17) != 0 )
    {
      *v7 += idSWFBitStream::ReadS(this: bitstream, numBits: v23, a3: v22);
    }
    else
    {
      *v6 += idSWFBitStream::ReadS(this: bitstream, numBits: v23, a3: v22);
    }
  }
  else
  {
    *v6 += idSWFBitStream::ReadS(this: bitstream, numBits: v15, a3: v14);
    LODWORD(v26) = idSWFBitStream::ReadS(this: bitstream, numBits: v25, a3: v24) + *v7;
    *v7 = v26;
    HIDWORD(v26) = *v6;
    LODWORD(v27) = *v6;
    v35.x = (float)v27 * (float)0.050000001;
    v35.y = (float)v26 * (float)0.050000001;
    v30 = idList<idVec2,72>::FindIndex(this: p_verts, obj: &v35, startIndex: 0);
    if ( v30 < 0 )
      LOWORD(v30) = idList<idVec2,72>::Append(this: p_verts, obj: &v35);
    v8[2] = v30;
    *v6 += idSWFBitStream::ReadS(this: bitstream, numBits: v29, a3: v28);
    HIDWORD(v21) = idSWFBitStream::ReadS(this: bitstream, numBits: v32, a3: v31) + *v7;
    *v7 = HIDWORD(v21);
  }
  v33 = *v7;
  LODWORD(v21) = *v6;
  v35.y = (float)*(__int64 *)((char *)&v21 - 4) * (float)0.050000001;
  v35.x = (float)v21 * (float)0.050000001;
  v34 = idList<idVec2,72>::FindIndex(this: p_verts, obj: &v35, startIndex: 0);
  if ( v34 < 0 )
    LOWORD(v34) = idList<idVec2,72>::Append(this: p_verts, obj: &v35);
  v8[1] = v34;
}


// ========================================================================
// ?AddUniqueVert@idSWFShapeParser@@AAAXAAVidSWFShapeDrawFill@@ABVidVec2@@1@Z
// EA  : 0x8278E7C8
// RVA : 0x0078E7C8
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::AddUniqueVert(
        idSWFShapeParser *this,
        idSWFShapeDrawFill *drawFill,
        const idVec2 *start,
        const idVec2 *end)
{
  int num; // r7
  int v8; // r9
  idVec2 *list; // r8
  int v10; // r10
  char v11; // r11
  idVec2 *v12; // r11
  double y; // fp13
  char v14; // r11
  unsigned __int16 v15; // r29
  int Index; // r3
  unsigned __int16 v17[24]; // [sp+50h] [-30h] BYREF

  if ( this->morph )
  {
    num = drawFill->startVerts.num;
    v8 = 0;
    if ( num <= 0 )
    {
LABEL_13:
      v15 = idList<idVec2,72>::Append(this: &drawFill->startVerts, obj: start);
      idList<idVec2,72>::Append(this: &drawFill->endVerts, obj: end);
      v17[0] = v15;
      idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)&drawFill->indices, obj: v17);
    }
    else
    {
      list = drawFill->startVerts.list;
      v10 = 0;
      while ( 1 )
      {
        if ( list[v10].x != start->x || (v11 = 1, list[v10].y != start->y) )
          v11 = 0;
        if ( v11 != 0 )
        {
          v12 = &drawFill->endVerts.list[v10];
          if ( v12->x != end->x || (y = v12->y, v14 = 1, y != end->y) )
            v14 = 0;
          if ( v14 != 0 )
            break;
        }
        ++v8;
        ++v10;
        if ( v8 >= num )
          goto LABEL_13;
      }
      v17[0] = v8;
      idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)&drawFill->indices, obj: v17);
    }
  }
  else
  {
    Index = idList<idVec2,72>::FindIndex(this: &drawFill->startVerts, obj: start, startIndex: 0);
    if ( Index < 0 )
      LOWORD(Index) = idList<idVec2,72>::Append(this: &drawFill->startVerts, obj: start);
    v17[0] = Index;
    idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)&drawFill->indices, obj: v17);
  }
}


// ========================================================================
// ?MakeLoops@idSWFShapeParser@@AAAXXZ
// EA  : 0x8278ECA8
// RVA : 0x0078ECA8
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::MakeLoops(idSWFShapeParser *this)
{
  int num; // r11
  int v3; // r8
  const char *v4; // r20
  idSWFShapeParser::swfSPDrawFill_t *v5; // r17
  int v6; // r4
  int v7; // r30
  idList<idSWFShapeParser::swfSPMorphEdge_t,72> *p_edges; // r5
  int v9; // r7
  int v10; // r11
  int v11; // r11
  unsigned __int16 *p_cp; // r6
  int v13; // ctr
  unsigned __int16 *v14; // r11
  idSpawnArea::GeneratedPosition **list; // r14
  int size; // r21
  bool v17; // r3
  int v18; // r24
  int v19; // r11
  idSpawnArea::GeneratedPosition **v20; // r10
  int v21; // r11
  int v22; // r10
  idSWFShapeParser::swfSPLineLoop_t *v23; // r9
  int v24; // r23
  int v25; // r29
  bool v26; // cr56
  idSpawnArea::GeneratedPosition *v27; // r30
  bool v28; // r3
  _DWORD *v29; // r25
  int v30; // r29
  idSWFShapeParser::swfSPMorphEdge_t *v31; // r11
  idVec2 *v32; // r8
  idSWFShapeParser::swfSPMorphEdge_t *v33; // r11
  int v34; // r5
  __int64 v35; // r11
  __int64 v36; // r9
  float *v37; // r7
  double v38; // fp13
  double v39; // fp9
  int v42; // r27
  double v43; // fp31
  int v44; // r28
  idVec2 *v45; // r10
  int v46; // r6
  idSWFShapeParser::swfSPMorphEdge_t *v47; // r7
  float *v48; // r9
  int v49; // r18
  float *v50; // r8
  int v51; // r19
  int v52; // r7
  int v53; // r6
  float *v54; // r11
  float *v55; // r7
  float *p_x; // r10
  double v57; // fp5
  double v58; // fp3
  double v59; // fp7
  double v60; // fp8
  double v61; // fp8
  double v62; // fp10
  double v63; // fp9
  double v64; // fp2
  double v65; // fp1
  double v66; // fp6
  double v67; // fp4
  double v68; // fp7
  double v69; // fp3
  int Index; // r3
  int v71; // r3
  idSWFShapeParser::swfSPMorphEdge_t *v72; // r4
  double v73; // fp13
  int v74; // r3
  idSWFShapeParser::swfSPMorphEdge_t *v75; // r6
  int v76; // r30
  int v77; // r7
  _DWORD *v78; // r5
  int j; // ctr
  idSWFShapeParser::swfSPMorphEdge_t *v80; // r11
  int v81; // r9
  idVec2 *v82; // r11
  float *v83; // r10
  float *v84; // r9
  float *v85; // r11
  int v86; // r30
  int v87; // r11
  double v88; // fp13
  int v89; // r10
  int v90; // r7
  int v91; // r9
  idVec2 *v92; // r5
  int v93; // r8
  signed int v94; // r6
  int v95; // r5
  int v96; // r3
  int v97; // r6
  int v98; // r7
  int v99; // r9
  idVec2 *v100; // r10
  float *v101; // r9
  float *v102; // r8
  float *v103; // r10
  double v104; // fp0
  double v105; // fp13
  double v106; // fp12
  double v107; // fp9
  double v108; // fp6
  double v109; // fp5
  int v110; // r27
  int v111; // r19
  int v112; // r21
  double v113; // fp13
  int v114; // r5
  idSWFShapeParser::swfSPLineLoop_t *v115; // r23
  idList<idSWFShapeParser::swfSPLineLoop_t,72> *p_loops; // r18
  idSWFShapeParser::swfSPLineLoop_t *v117; // r9
  signed int v118; // r11
  int v119; // r10
  idVec2 *v120; // r7
  int v121; // r3
  idVec2 *v122; // r25
  int v123; // r30
  int v124; // r20
  idSWFShapeParser::swfSPLineLoop_t *v125; // r24
  float *v126; // r26
  idSWFShapeParser::swfSPLineLoop_t *v127; // r28
  unsigned int *p_num; // r5
  signed int v129; // r3
  bool v130; // r29
  signed int v131; // r11
  bool v132; // cr57
  int v133; // r7
  double v134; // fp13
  idVec2 *v135; // r6
  int v136; // r8
  unsigned int v137; // r4
  int v138; // r10
  int v139; // r14
  float *v140; // r10
  int v141; // r9
  float *v142; // r9
  double v143; // fp0
  int v144; // r11
  int v145; // r29
  int v146; // r30
  double v147; // fp13
  int v148; // r27
  signed int v149; // r8
  idSWFShapeParser::swfSPLineLoop_t *v150; // r28
  int v151; // r9
  float *v152; // r10
  double v153; // fp8
  double v154; // fp0
  int v155; // r4
  int v156; // r29
  int v157; // r30
  int v158; // r29
  int v159; // r30
  int v160; // r29
  int v161; // r30
  int v162; // r29
  int v163; // r30
  int v164; // r29
  int v165; // r30
  int v166; // r29
  int v167; // r30
  int v168; // r29
  int v169; // r30
  int v170; // r29
  int v171; // r30
  int v172; // r11
  int v173; // r29
  int v174; // r30
  int v175; // r10
  int v176; // [sp+50h] [-140h] BYREF
  idMem *v177; // [sp+54h] [-13Ch]
  int v178; // [sp+58h] [-138h]
  const char *i; // [sp+5Ch] [-134h]
  const char *v180; // [sp+60h] [-130h]
  signed int v181; // [sp+68h] [-128h]
  int v182; // [sp+6Ch] [-124h]
  idVec2 v183; // [sp+70h] [-120h] BYREF
  idVec2 v184[2]; // [sp+78h] [-118h] BYREF
  __int64 v185; // [sp+88h] [-108h]
  idList<idSpawnArea::GeneratedPosition *,5> v186; // [sp+90h] [-100h] BYREF
  idList<unsigned short,5> v187[5]; // [sp+A0h] [-F0h] BYREF

  num = this->fillDraws.num;
  v3 = 0;
  v178 = 0;
  if ( num > 0 )
  {
    v4 = "idSWFShapeParser: loop with < 3 verts";
    v177 = &mem;
    v180 = "idSWFShapeParser: Hole not in a shape";
    for ( i = "idSWFShapeParser: loop with < 3 verts"; ; v4 = i )
    {
      v5 = &this->fillDraws.list[v3];
      v6 = 0;
      v176 = v5->edges.num;
      v7 = v176;
      if ( v176 > 0 )
      {
        p_edges = &v5->edges;
        v9 = 0;
        do
        {
          if ( p_edges->list[v9].start.v0 == p_edges->list[v9].start.v1
            || p_edges->list[v9].end.v0 == p_edges->list[v9].end.v1 )
          {
            if ( v6 >= 0 )
            {
              v10 = v5->edges.num;
              if ( v6 < v10 )
              {
                v11 = v10 - 1;
                v5->edges.num = v11;
                if ( v6 != v11 )
                {
                  p_cp = &p_edges->list[v9 - 1].end.cp;
                  v13 = 6;
                  v14 = &p_edges->list[v11 - 1].end.cp;
                  do
                  {
                    *++p_cp = *++v14;
                    --v13;
                  }
                  while ( v13 != 0 );
                }
              }
            }
            --v6;
            --v9;
          }
          ++v6;
          ++v9;
          v176 = v5->edges.num;
          v7 = v176;
        }
        while ( v6 < v176 );
      }
      list = nullptr;
      *(_WORD *)&v186.memTag = 18432;
      size = 0;
      memset(&v186, 0, 14);
      if ( v7 <= 0
        || (v17 = idList<idNavSpline *,5>::Resize(this: &v186, newsize: v7), size = v186.size, list = v186.list, v17) )
      {
        if ( v7 >= size )
        {
          v18 = size;
          v186.num = size;
        }
        else
        {
          v18 = v7;
          v186.num = v7;
        }
      }
      else
      {
        v18 = v186.num;
      }
      v19 = 0;
      if ( v5->edges.num > 0 )
      {
        v20 = list - 1;
        do
          *++v20 = (idSpawnArea::GeneratedPosition *)v19++;
        while ( v19 < v5->edges.num );
      }
      if ( v18 > 0 )
        break;
LABEL_66:
      while ( 1 )
      {
        v111 = -1;
        v112 = -1;
        v113 = -1.0e10;
        v114 = 0;
        v181 = v5->loops.num;
        v110 = v181;
        if ( v181 <= 0 )
          break;
        v115 = v5->loops.list;
        p_loops = &v5->loops;
        v117 = v115;
        do
        {
          if ( v117->hole )
          {
            v118 = 0;
            v181 = v117->vindex1.num;
            if ( v181 > 0 )
            {
              v119 = 0;
              v120 = this->verts.list;
              do
              {
                v6 = v117->vindex1.list[v119];
                v121 = __ROL4__(v6, 3);
                if ( *(float *)((char *)&v120->x + v121) > v113 )
                {
                  v111 = v114;
                  v113 = *(float *)((char *)&v120->x + v121);
                  v112 = v118;
                }
                ++v118;
                ++v119;
              }
              while ( v118 < v181 );
            }
          }
          ++v114;
          ++v117;
        }
        while ( v114 < v110 );
        if ( v111 == -1 )
          break;
        v122 = this->verts.list;
        v181 = v110;
        v123 = 0;
        v124 = v111;
        v125 = &v115[v111];
        v126 = (float *)((char *)&v122->x + __ROL4__(v125->vindex1.list[v112], 3));
        if ( v110 <= 0 )
          goto LABEL_91;
        v127 = v115;
        p_num = (unsigned int *)&v115->vindex1.num;
        while ( 1 )
        {
          if ( !v127->hole )
          {
            v129 = *p_num;
            v130 = false;
            v131 = 0;
            v132 = (int)*p_num > 0;
            v181 = *p_num;
            if ( v132 )
            {
              v133 = *(p_num - 1);
              v134 = *v126;
              v135 = this->verts.list;
              v136 = 0;
              do
              {
                v137 = *p_num;
                ++v131;
                v138 = __ROL4__(*(unsigned __int16 *)(v133 + v136), 3);
                v139 = 2 * (v131 % (int)*p_num);
                __twllei(*p_num, 0);
                v140 = (float *)((char *)&v135->x + v138);
                v6 = v137 & ~(__ROL4__(v131, 1) - 1);
                v141 = *(unsigned __int16 *)(v139 + v133);
                __twlgei(v6, 0xFFFFFFFF);
                v142 = (float *)((char *)&v135->x + __ROL4__(v141, 3));
                if ( *v140 >= v134 || *v142 >= v134 )
                {
                  v143 = v126[1];
                  v6 = v140[1] < v143;
                  if ( v6 != v142[1] < v143 )
                    v130 = (_cntlzw(v130) & 0x20) != 0;
                }
                v136 += 2;
              }
              while ( v131 < v129 );
              list = v186.list;
            }
            if ( v130 )
              break;
          }
          ++v123;
          ++v127;
          p_num += 9;
          if ( v123 >= v110 )
            goto LABEL_91;
        }
        if ( v123 == -1 )
        {
LABEL_91:
          idLib::Warning(fmt: v180, v6);
          if ( v111 >= 0 )
          {
            v144 = v5->loops.num;
            if ( v111 < v144 )
            {
              v5->loops.num = v144 - 1;
              if ( v111 != v144 - 1 )
              {
                v145 = (int)&p_loops->list[v124];
                v146 = (int)&p_loops->list[v144 - 1];
                p_loops->list[v111].hole = *(_BYTE *)v146;
                idList<unsigned short,72>::operator=(
                  this: (idList<unsigned short,115> *)(v145 + 4),
                  other: (const idList<unsigned short,115> *)(v146 + 4));
                idList<unsigned short,72>::operator=(
                  this: (idList<unsigned short,115> *)(v145 + 20),
                  other: (const idList<unsigned short,115> *)(v146 + 20));
              }
            }
          }
        }
        else
        {
          v147 = 1.0e10;
          v148 = -1;
          v149 = 0;
          v150 = &v115[v123];
          v181 = v150->vindex1.num;
          if ( v181 > 0 )
          {
            v151 = 0;
            do
            {
              v152 = (float *)((char *)&v122->x + __ROL4__(v150->vindex1.list[v151], 3));
              if ( *v152 >= (double)*v126 )
              {
                v153 = (float)(v152[1] - v126[1]);
                v154 = __fsqrts((float)((float)((float)(*v152 - *v126) * (float)(*v152 - *v126))
                                      + (float)((float)v153 * (float)v153)));
                if ( v154 < v147 )
                {
                  v148 = v149;
                  v147 = v154;
                }
              }
              ++v149;
              ++v151;
            }
            while ( v149 < v181 );
          }
          v187[0].listStatic = 0;
          v187[0].memTag = 72;
          memset(v187, 0, 14);
          v155 = v125->vindex1.num + v181 + 1;
          if ( v155 > 0 )
            idList<unsigned short,30>::Resize(this: v187, newsize: v155);
          if ( v148 >= 0 )
          {
            v156 = 0;
            v157 = v148 + 1;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v150->vindex1.list[v156]);
              --v157;
              ++v156;
            }
            while ( v157 != 0 );
          }
          v158 = v112;
          if ( v112 < v125->vindex1.num )
          {
            v159 = v112;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v125->vindex1.list[v159]);
              ++v158;
              ++v159;
            }
            while ( v158 < v125->vindex1.num );
          }
          if ( v112 >= 0 )
          {
            v160 = 0;
            v161 = v112 + 1;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v125->vindex1.list[v160]);
              --v161;
              ++v160;
            }
            while ( v161 != 0 );
          }
          v162 = v148;
          if ( v148 < v150->vindex1.num )
          {
            v163 = v148;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v150->vindex1.list[v163]);
              ++v162;
              ++v163;
            }
            while ( v162 < v150->vindex1.num );
          }
          idList<unsigned short,72>::operator=(
            this: (idList<unsigned short,115> *)&v150->vindex1,
            other: (const idList<unsigned short,115> *)v187);
          if ( v187[0].listStatic == 0 || v187[0].listStatic == 2 )
          {
            if ( v187[0].list != nullptr )
              idMem::Free(this: v177, ptr: v187[0].list, align: ALIGN_16);
            v187[0].list = nullptr;
            v187[0].size = 0;
          }
          v187[0].num = 0;
          if ( v148 >= 0 )
          {
            v164 = 0;
            v165 = v148 + 1;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v150->vindex2.list[v164]);
              --v165;
              ++v164;
            }
            while ( v165 != 0 );
          }
          v166 = v112;
          if ( v112 < v125->vindex2.num )
          {
            v167 = v112;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v125->vindex2.list[v167]);
              ++v166;
              ++v167;
            }
            while ( v166 < v125->vindex2.num );
          }
          if ( v112 >= 0 )
          {
            v168 = 0;
            v169 = v112 + 1;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v125->vindex2.list[v168]);
              --v169;
              ++v168;
            }
            while ( v169 != 0 );
          }
          v170 = v148;
          if ( v148 < v150->vindex2.num )
          {
            v171 = v148;
            do
            {
              idList<unsigned short,72>::Append(this: v187, obj: &v150->vindex2.list[v171]);
              ++v170;
              ++v171;
            }
            while ( v170 < v150->vindex2.num );
          }
          idList<unsigned short,72>::operator=(
            this: (idList<unsigned short,115> *)&v150->vindex2,
            other: (const idList<unsigned short,115> *)v187);
          if ( v111 >= 0 )
          {
            v172 = v5->loops.num;
            if ( v111 < v172 )
            {
              v5->loops.num = v172 - 1;
              if ( v111 != v172 - 1 )
              {
                v173 = (int)&p_loops->list[v124];
                v174 = (int)&p_loops->list[v172 - 1];
                p_loops->list[v111].hole = *(_BYTE *)v174;
                idList<unsigned short,72>::operator=(
                  this: (idList<unsigned short,115> *)(v173 + 4),
                  other: (const idList<unsigned short,115> *)(v174 + 4));
                idList<unsigned short,72>::operator=(
                  this: (idList<unsigned short,115> *)(v173 + 20),
                  other: (const idList<unsigned short,115> *)(v174 + 20));
              }
            }
          }
          if ( v187[0].listStatic == 0 || v187[0].listStatic == 2 )
          {
            v6 = (int)v187[0].list;
            if ( v187[0].list != nullptr )
              idMem::Free(this: v177, ptr: v187[0].list, align: ALIGN_16);
            v187[0].list = nullptr;
            v187[0].size = 0;
          }
          v187[0].num = 0;
        }
      }
      if ( v186.listStatic == 0 || v186.listStatic == 2 )
      {
        if ( list != nullptr )
          idMem::Free(this: v177, ptr: list, align: ALIGN_16);
        v186.list = nullptr;
        v186.size = 0;
      }
      v175 = this->fillDraws.num;
      v3 = v178 + 1;
      v186.num = 0;
      v178 = v3;
      if ( v3 >= v175 )
        return;
    }
    while ( 1 )
    {
      idList<idSWFShapeParser::swfSPLineLoop_t,72>::PreAllocateWithGranularity(
        this: &v5->loops,
        newSize: v5->loops.num + 1);
      v21 = v5->loops.num;
      v22 = v5->loops.size;
      v23 = v5->loops.list;
      if ( v21 >= v22 )
      {
        v24 = (int)&v23[v22 - 1];
      }
      else
      {
        v5->loops.num = v21 + 1;
        v24 = (int)&v23[v21];
      }
      *(_BYTE *)v24 = 0;
      v25 = v18 - 1;
      v26 = v18 - 1 < size;
      v27 = list[v18 - 1];
      if ( v18 - 1 > size )
      {
        v28 = idList<idNavSpline *,5>::Resize(this: &v186, newsize: v18 - 1);
        size = v186.size;
        list = v186.list;
        if ( !v28 )
        {
          v18 = v186.num;
          goto LABEL_35;
        }
        v26 = v25 < v186.size;
      }
      if ( v26 )
      {
        --v18;
        v186.num = v25;
      }
      else
      {
        v18 = size;
        v186.num = size;
      }
LABEL_35:
      v29 = (_DWORD *)(v24 + 4);
      while ( 1 )
      {
        v30 = (int)v27;
        idList<unsigned short,72>::Append(
          this: (idList<unsigned short,5> *)(v24 + 4),
          obj: &v5->edges.list[(_DWORD)v27].start.v0);
        idList<unsigned short,72>::Append(
          this: (idList<unsigned short,5> *)(v24 + 20),
          obj: &v5->edges.list[(_DWORD)v27].end.v0);
        v31 = v5->edges.list;
        if ( v31[(_DWORD)v27].start.cp != 0xFFFF )
        {
          v32 = this->verts.list;
          v33 = &v31[v30];
          LODWORD(v36) = 0;
          v176 = (int)&v5->edges.list[v30];
          v34 = __ROL4__(v33->start.v0, 3);
          LODWORD(v35) = (char *)v32 + __ROL4__(v33->start.v1, 3);
          HIDWORD(v35) = (char *)v32 + v34;
          v37 = (float *)((char *)&v32->x + __ROL4__(*(unsigned __int16 *)(v176 + 6), 3));
          v38 = *(float *)((char *)&v32->y + v34);
          HIDWORD(v36) = (char *)v32 + __ROL4__(*(unsigned __int16 *)(v176 + 8), 3);
          v39 = (float)(v37[1] - *(float *)(HIDWORD(v36) + 4));
          _FP10 = (float)((float)__fsqrts((float)((float)((float)(*(float *)HIDWORD(v35) - *(float *)v35)
                                                        * (float)(*(float *)HIDWORD(v35) - *(float *)v35))
                                                + (float)((float)((float)v38 - *(float *)(v35 + 4))
                                                        * (float)((float)v38 - *(float *)(v35 + 4)))))
                        - (float)__fsqrts((float)((float)((float)(*v37 - *(float *)HIDWORD(v36))
                                                        * (float)(*v37 - *(float *)HIDWORD(v36)))
                                                + (float)((float)v39 * (float)v39))));
          __asm { fsel      f9, f10, f12, f11 }
          v182 = (int)(float)((float)_FP9 * (float)-0.1);
          v42 = 1 - v182;
          if ( 1 - v182 > 0 )
          {
            LODWORD(v35) = 1 - (int)(float)((float)_FP9 * (float)-0.1);
            v184[1] = (idVec2)v35;
            v43 = (float)((float)v35 + (float)1.0);
            do
            {
              v44 = v36 + 1;
              v45 = this->verts.list;
              LODWORD(v36) = v36 + 1;
              v176 = (int)&v5->edges.list[v30];
              v185 = v36;
              v46 = *(unsigned __int16 *)(v176 + 2);
              v47 = (idSWFShapeParser::swfSPMorphEdge_t *)*(unsigned __int16 *)(v176 + 8);
              v48 = (float *)((char *)&v45->x + __ROL4__(*(unsigned __int16 *)v176, 3));
              v49 = *(unsigned __int16 *)(v176 + 6);
              v50 = (float *)((char *)&v45->x + __ROL4__(*(unsigned __int16 *)(v176 + 4), 3));
              v51 = *(unsigned __int16 *)(v176 + 10);
              v181 = v176;
              v176 = (int)v47;
              v52 = __ROL4__(v46, 3);
              v53 = __ROL4__(v51, 3);
              v54 = (float *)((char *)&v45->x + __ROL4__(v49, 3));
              v55 = (float *)((char *)&v45->x + v52);
              v57 = *(float *)((char *)&v45->x + v53);
              v58 = *(float *)((char *)&v45->y + v53);
              p_x = &v45[v176].x;
              v59 = (float)((float)v185 / (float)v43);
              v60 = (float)((float)1.0 - (float)((float)v185 / (float)v43));
              v61 = (float)((float)v60 * (float)v60);
              v62 = (float)(*v55 * (float)((float)v59 * (float)v59));
              v63 = (float)(v55[1] * (float)((float)v59 * (float)v59));
              v64 = (float)(*p_x * (float)((float)v59 * (float)v59));
              v65 = (float)(p_x[1] * (float)((float)v59 * (float)v59));
              v66 = (float)(*v54 * (float)v61);
              v67 = (float)(v54[1] * (float)v61);
              v68 = (float)((float)v58
                          * (float)((float)((float)((float)1.0 - (float)((float)v185 / (float)v43))
                                          * (float)((float)v185 / (float)v43))
                                  * (float)2.0));
              v69 = (float)((float)(v50[1]
                                  * (float)((float)((float)((float)1.0 - (float)((float)v185 / (float)v43))
                                                  * (float)((float)v185 / (float)v43))
                                          * (float)2.0))
                          + (float)(v48[1] * (float)v61));
              v183.x = (float)v62
                     + (float)((float)((float)((float)((float)((float)1.0 - (float)((float)v185 / (float)v43))
                                                     * (float)((float)v185 / (float)v43))
                                             * (float)2.0)
                                     * *v50)
                             + (float)(*v48 * (float)v61));
              v183.y = (float)v69 + (float)v63;
              v184[0].x = (float)v64
                        + (float)((float)((float)v57
                                        * (float)((float)((float)((float)1.0 - (float)((float)v185 / (float)v43))
                                                        * (float)((float)v185 / (float)v43))
                                                * (float)2.0))
                                + (float)v66);
              v184[0].y = (float)((float)v68 + (float)v67) + (float)v65;
              Index = idList<idVec2,72>::FindIndex(this: &this->verts, obj: &v183, startIndex: 0);
              if ( Index < 0 )
                LOWORD(Index) = idList<idVec2,72>::Append(this: &this->verts, obj: &v183);
              HIWORD(v176) = Index;
              idList<unsigned short,72>::Append(
                this: (idList<unsigned short,5> *)(v24 + 4),
                obj: (unsigned __int16 *)&v176);
              v71 = idList<idVec2,72>::FindIndex(this: &this->verts, obj: v184, startIndex: 0);
              if ( v71 < 0 )
                LOWORD(v71) = idList<idVec2,72>::Append(this: &this->verts, obj: v184);
              HIWORD(v176) = v71;
              idList<unsigned short,72>::Append(
                this: (idList<unsigned short,5> *)(v24 + 20),
                obj: (unsigned __int16 *)&v176);
              LODWORD(v36) = v44;
            }
            while ( v44 < v42 );
          }
        }
        v72 = v5->edges.list;
        v73 = 3.4028235e38;
        v74 = -1;
        v75 = &v72[v30];
        v76 = 0;
        if ( v18 <= 0 )
          break;
        v77 = v75->start.v1;
        v78 = list;
        for ( j = v18; j != 0; --j )
        {
          v80 = &v72[*v78];
          if ( v77 == v80->start.v0 )
          {
            v81 = v80->start.v1;
            v82 = this->verts.list;
            v83 = &v82[v77].x;
            v84 = (float *)((char *)&v82->x + __ROL4__(v81, 3));
            v85 = (float *)((char *)&v82->x + __ROL4__(v75->start.v0, 3));
            if ( (float)((float)((float)(v84[1] - v83[1]) * (float)(*v85 - *v83))
                       - (float)((float)(v85[1] - v83[1]) * (float)(*v84 - *v83))) < v73 )
            {
              v73 = (float)((float)((float)(v84[1] - v83[1]) * (float)(*v85 - *v83))
                          - (float)((float)(v85[1] - v83[1]) * (float)(*v84 - *v83)));
              v74 = v76;
            }
          }
          ++v76;
          ++v78;
        }
        if ( v74 < 0 )
          break;
        v27 = list[v74];
        if ( v74 < v18 )
        {
          v186.num = --v18;
          if ( v74 != v18 )
            list[v74] = list[v18];
        }
      }
      v181 = *(_DWORD *)(v24 + 8);
      if ( v181 >= 3 )
      {
        v88 = 3.4028235e38;
        v89 = 0;
        v90 = 0;
        v91 = 0;
        v92 = this->verts.list;
        do
        {
          v93 = __ROL4__(*(unsigned __int16 *)(v91 + *v29), 3);
          if ( *(float *)((char *)&v92->x + v93) < v88 )
          {
            v89 = v90;
            v88 = *(float *)((char *)&v92->x + v93);
          }
          ++v90;
          v91 += 2;
        }
        while ( v90 < *(_DWORD *)(v24 + 8) );
        v94 = v181 + v89 - 1;
        v95 = 2 * (v94 % v181);
        v96 = __ROL4__(v94, 1) - 1;
        v97 = *(unsigned __int16 *)(2 * ((v89 + 1) % v181) + *v29);
        v98 = __ROL4__(v89 + 1, 1) - 1;
        v99 = __ROL4__(*(unsigned __int16 *)(2 * v89 + *v29), 3);
        v100 = this->verts.list;
        v101 = (float *)((char *)&v100->x + v99);
        v102 = (float *)((char *)&v100->x + __ROL4__(v97, 3));
        v103 = (float *)((char *)&v100->x + __ROL4__(*(unsigned __int16 *)(v95 + *v29), 3));
        v6 = v181 & ~v96;
        v104 = *v101;
        __twllei(v181, 0);
        v105 = v101[1];
        __twllei(v181, 0);
        v106 = *v102;
        __twlgei(v6, 0xFFFFFFFF);
        v107 = (float)(v103[1] - (float)v105);
        v108 = (float)(v102[1] - (float)v105);
        v109 = (float)(*v103 - (float)v104);
        __twlgei(v181 & ~v98, 0xFFFFFFFF);
        *(_BYTE *)v24 = (float)((float)((float)v108 * (float)v109)
                              - (float)((float)v107 * (float)((float)v106 - (float)v104))) > 0.0;
      }
      else
      {
        idLib::Warning(fmt: v4);
        v86 = v5->loops.num - 1;
        if ( v86 <= v5->loops.size
          || (unsigned __int8)idList<idSWFShapeParser::swfSPLineLoop_t,72>::Resize(
                                this: &v5->loops,
                                newsize: v5->loops.num - 1) != 0 )
        {
          v87 = v5->loops.size;
          if ( v86 < v87 )
            v87 = v86;
          v5->loops.num = v87;
        }
      }
      if ( v18 <= 0 )
        goto LABEL_66;
    }
  }
}


// ========================================================================
// __unwind$225477
// EA  : 0x8278FAA4
// RVA : 0x0078FAA4
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void _unwind_225477()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$225478
// EA  : 0x8278FACC
// RVA : 0x0078FACC
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void _unwind_225478()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 400 + 160));
}


// ========================================================================
// ?TriangulateSoup@idSWFShapeParser@@AAAXAAVidSWFShape@@@Z
// EA  : 0x8278FAF8
// RVA : 0x0078FAF8
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::TriangulateSoup(idSWFShapeParser *this, idSWFShape *shape)
{
  idList<idSWFShapeDrawFill,72> *p_fillDraws; // r17
  int size; // r11
  int num; // r31
  int v7; // r11
  int v8; // r16
  int v9; // r18
  int v10; // r19
  idSWFShapeParser::swfSPDrawFill_t *v11; // r23
  idSWFShapeDrawFill *v12; // r25
  int v13; // r20
  int v14; // r21
  int v15; // r24
  const idSWFShapeParser::swfSPLineLoop_t *v16; // r26
  int v17; // r22
  int EarVert; // r3
  signed int v19; // r5
  idVec2 *list; // r11
  int v21; // r10
  int v22; // r9
  int v23; // r29
  int v24; // r14
  int v25; // r27
  int v26; // r11
  int v27; // r11
  bool v28; // zf
  int v29; // r10
  unsigned __int16 *v30; // r9
  int v31; // r11
  int v32; // r11
  unsigned __int16 *v33; // r10

  p_fillDraws = &shape->fillDraws;
  idSWFShapeParser::MakeLoops(this);
  size = shape->fillDraws.size;
  num = this->fillDraws.num;
  if ( num <= size
    || (unsigned __int8)idList<idSWFShapeDrawFill,72>::Resize(this: p_fillDraws, newsize: this->fillDraws.num) != 0 )
  {
    v7 = p_fillDraws->size;
    if ( num < v7 )
      v7 = num;
    p_fillDraws->num = v7;
  }
  v8 = 0;
  if ( this->fillDraws.num > 0 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = &this->fillDraws.list[v10];
      v12 = &p_fillDraws->list[v9];
      swfFillStyle_t::operator=(this: &v12->style, __that: &v11->style);
      v13 = 0;
      if ( v11->loops.num > 0 )
      {
        v14 = 0;
        do
        {
          v15 = 0;
          v16 = &v11->loops.list[v14];
          v17 = v16->vindex1.num - 2;
          if ( v17 > 0 )
          {
            while ( 1 )
            {
              EarVert = idSWFShapeParser::FindEarVert(this, loop: v16);
              if ( EarVert == -1 )
                break;
              v19 = v16->vindex1.num;
              list = this->verts.list;
              v21 = v16->vindex1.list[EarVert];
              v23 = (EarVert + 1) % v19;
              v22 = __ROL4__(v16->vindex2.list[EarVert], 3);
              __twllei(v19, 0);
              __twllei(v19, 0);
              __twlgei(v19 & ~(__ROL4__(EarVert + 1, 1) - 1), 0xFFFFFFFF);
              __twlgei(v19 & ~(__ROL4__(EarVert + 2, 1) - 1), 0xFFFFFFFF);
              v24 = (EarVert + 2) % v19;
              idSWFShapeParser::AddUniqueVert(
                this,
                drawFill: v12,
                start: (idVec2 *)((char *)list + __ROL4__(v21, 3)),
                end: (idVec2 *)((char *)list + v22));
              v25 = v23;
              idSWFShapeParser::AddUniqueVert(
                this,
                drawFill: v12,
                start: (const idVec2 *)((char *)this->verts.list + __ROL4__(v16->vindex1.list[v23], 3)),
                end: (const idVec2 *)((char *)this->verts.list + __ROL4__(v16->vindex2.list[v23], 3)));
              idSWFShapeParser::AddUniqueVert(
                this,
                drawFill: v12,
                start: (const idVec2 *)((char *)this->verts.list + __ROL4__(v16->vindex1.list[v24], 3)),
                end: (const idVec2 *)((char *)this->verts.list + __ROL4__(v16->vindex2.list[v24], 3)));
              if ( v23 >= 0 )
              {
                v26 = v16->vindex1.num;
                if ( v23 < v26 )
                {
                  v16->vindex1.num = v26 - 1;
                  v28 = v23 >= v26 - 1;
                  v27 = v23;
                  if ( !v28 )
                  {
                    v29 = v23;
                    do
                    {
                      ++v27;
                      v30 = &v16->vindex1.list[v29++];
                      *v30 = v30[1];
                    }
                    while ( v27 < v16->vindex1.num );
                  }
                }
                v31 = v16->vindex2.num;
                if ( v23 < v31 )
                {
                  v16->vindex2.num = v31 - 1;
                  v28 = v23 >= v31 - 1;
                  v32 = v23;
                  if ( !v28 )
                  {
                    do
                    {
                      ++v32;
                      v33 = &v16->vindex2.list[v25++];
                      *v33 = v33[1];
                    }
                    while ( v32 < v16->vindex2.num );
                  }
                }
              }
              if ( ++v15 >= v17 )
                goto LABEL_23;
            }
            idLib::Warning(fmt: "idSWFShapeParser: could not find an ear vert");
          }
LABEL_23:
          ++v13;
          ++v14;
        }
        while ( v13 < v11->loops.num );
      }
      ++v8;
      ++v10;
      ++v9;
    }
    while ( v8 < this->fillDraws.num );
  }
}


// ========================================================================
// ?ReadFillStyle@idSWFShapeParser@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x8278FFA8
// RVA : 0x0078FFA8
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::ReadFillStyle(idSWFShapeParser *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r27
  const unsigned __int8 *readp; // r11
  const unsigned __int8 *v5; // r10
  unsigned __int16 v7; // r11
  int v8; // r30
  idList<idSWFShapeParser::swfSPDrawFill_t,72> *p_fillDraws; // r28
  int v10; // r4
  const unsigned __int8 *v11; // r11
  unsigned __int8 v12; // r29
  int num; // r11
  int size; // r10
  int v15; // r30
  int v16; // r11
  swfColorRGBA_t *v17; // r4
  char v18; // r9
  char v19; // r8
  char v20; // r7
  unsigned __int64 v21; // r10
  int v22; // r8
  int v23; // r7
  int v24; // r6
  unsigned __int64 v25; // r10
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  __int64 v30; // r6
  const unsigned __int8 *v31; // r11
  const unsigned __int8 *v32; // r11
  const unsigned __int8 *v33; // r11
  const unsigned __int8 *v34; // r10
  unsigned __int16 v35; // r11
  int v36; // r30
  int v37; // r4
  unsigned __int64 v38; // r6
  int v39; // r11
  int v40; // r10
  idSWFShapeParser::swfSPDrawLine_t *list; // r9
  int v42; // r30
  const unsigned __int8 *v43; // r11
  int v44; // r9
  unsigned __int64 v45; // r8
  __int16 v46; // r11
  unsigned __int64 v47; // r8
  unsigned __int64 v48; // r6
  int v49; // r23
  unsigned __int64 v50; // r8
  unsigned __int64 v51; // r6
  bool v52; // r29
  unsigned __int64 v53; // r8
  unsigned __int64 v54; // r6
  unsigned __int64 v55; // r8
  unsigned __int64 v56; // r6
  unsigned __int64 v57; // r8
  unsigned __int64 v58; // r6
  unsigned __int64 v59; // r8
  unsigned __int64 v60; // r6
  unsigned __int64 v61; // r8
  unsigned __int64 v62; // r6
  unsigned __int64 v63; // r8
  unsigned __int64 v64; // r6
  const unsigned __int8 *v65; // r11
  char v66; // r9
  char v67; // r8
  char v68; // r11
  const unsigned __int8 *v69; // r11
  swfColorRGBA_t *v70; // r4
  char v71; // r8
  char v72; // r7

  readp = bitstream->readp;
  LODWORD(v2) = 0;
  v5 = readp + 1;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v7 = *readp;
  bitstream->readp = v5;
  if ( this->extendedCount && v7 == 255 )
  {
    bitstream->currentBit = v2;
    bitstream->currentByte = v2;
    bitstream->readp = v5 + 2;
    v7 = __ROL4__(v5[1], 8) | *v5;
  }
  v8 = v7;
  p_fillDraws = &this->fillDraws;
  v10 = this->fillDraws.num + v7;
  if ( v10 > this->fillDraws.size )
    idList<idSWFShapeParser::swfSPDrawFill_t,72>::Resize(this: &this->fillDraws, newsize: v10);
  if ( v8 > 0 )
  {
    HIDWORD(v2) = v8;
    do
    {
      bitstream->currentByte = v2;
      v11 = bitstream->readp;
      bitstream->currentBit = v2;
      v12 = *v11;
      bitstream->readp = v11 + 1;
      idList<idSWFShapeParser::swfSPDrawFill_t,72>::PreAllocateWithGranularity(
        this: &this->fillDraws,
        newSize: this->fillDraws.num + 1);
      num = this->fillDraws.num;
      size = this->fillDraws.size;
      if ( num >= size )
      {
        v15 = (int)&p_fillDraws->list[size - 1];
      }
      else
      {
        v15 = (int)&p_fillDraws->list[num];
        this->fillDraws.num = num + 1;
      }
      v16 = v12 >> 4;
      *(_BYTE *)v15 = v16;
      *(_BYTE *)(v15 + 1) = v12 & 0xF;
      if ( v12 >> 4 != 0 )
      {
        if ( v16 == 1 )
        {
          idSWFBitStream::ReadMatrix(this: bitstream, matrix: (swfMatrix_t *)(v15 + 12));
          if ( this->morph )
          {
            idSWFBitStream::ReadMatrix(this: bitstream, matrix: (swfMatrix_t *)(v15 + 36));
            idSWFBitStream::ReadMorphGradient(
              this: bitstream,
              grad: (swfGradient_t *)(v15 + 60),
              a3: v29,
              a4: v28,
              a5: v27,
              a6: v26,
              a7: v25);
          }
          else
          {
            *(float *)(v15 + 36) = *(float *)(v15 + 12);
            *(float *)(v15 + 40) = *(float *)(v15 + 16);
            *(float *)(v15 + 44) = *(float *)(v15 + 20);
            *(float *)(v15 + 48) = *(float *)(v15 + 24);
            *(float *)(v15 + 52) = *(float *)(v15 + 28);
            *(float *)(v15 + 56) = *(float *)(v15 + 32);
            idSWFBitStream::ReadGradient(
              this: bitstream,
              grad: (swfGradient_t *)(v15 + 60),
              rgba: this->rgba,
              a4: v24,
              a5: v23,
              a6: v22,
              a7: v21);
          }
          if ( *(_BYTE *)(v15 + 1) == 3 )
          {
            v31 = bitstream->readp;
            bitstream->currentBit = v2;
            v31 += 2;
            bitstream->currentByte = v2;
            bitstream->readp = v31;
            LODWORD(v30) = __ROL4__(*(v31 - 1), 8) | *(v31 - 2);
            *(float *)(v15 + 224) = (float)v30 * (float)0.00390625;
          }
        }
        else if ( v16 == 4 )
        {
          bitstream->currentByte = v2;
          bitstream->currentBit = v2;
          v32 = bitstream->readp + 2;
          bitstream->readp = v32;
          *(_WORD *)(v15 + 228) = __ROL4__(*(v32 - 1), 8) | *(v32 - 2);
          idSWFBitStream::ReadMatrix(this: bitstream, matrix: (swfMatrix_t *)(v15 + 12));
          if ( this->morph )
          {
            idSWFBitStream::ReadMatrix(this: bitstream, matrix: (swfMatrix_t *)(v15 + 36));
          }
          else
          {
            *(float *)(v15 + 36) = *(float *)(v15 + 12);
            *(float *)(v15 + 40) = *(float *)(v15 + 16);
            *(float *)(v15 + 44) = *(float *)(v15 + 20);
            *(float *)(v15 + 48) = *(float *)(v15 + 24);
            *(float *)(v15 + 52) = *(float *)(v15 + 28);
            *(float *)(v15 + 56) = *(float *)(v15 + 32);
          }
        }
      }
      else if ( this->morph )
      {
        idSWFBitStream::ReadColorRGBA(this: bitstream, color: (swfColorRGBA_t *)(v15 + 2));
        idSWFBitStream::ReadColorRGBA(this: bitstream, color: (swfColorRGBA_t *)(v15 + 6));
      }
      else
      {
        v17 = (swfColorRGBA_t *)(v15 + 2);
        if ( this->rgba )
          idSWFBitStream::ReadColorRGBA(this: bitstream, color: v17);
        else
          idSWFBitStream::ReadColorRGB(this: bitstream, color: v17);
        v18 = *(_BYTE *)(v15 + 3);
        v19 = *(_BYTE *)(v15 + 4);
        v20 = *(_BYTE *)(v15 + 5);
        *(_BYTE *)(v15 + 6) = *(_BYTE *)(v15 + 2);
        *(_BYTE *)(v15 + 7) = v18;
        *(_BYTE *)(v15 + 8) = v19;
        *(_BYTE *)(v15 + 9) = v20;
      }
      --HIDWORD(v2);
    }
    while ( HIDWORD(v2) != 0 );
  }
  bitstream->currentByte = v2;
  v33 = bitstream->readp;
  bitstream->currentBit = v2;
  v34 = v33 + 1;
  v35 = *v33;
  bitstream->readp = v34;
  if ( this->extendedCount && v35 == 255 )
  {
    bitstream->currentBit = v2;
    bitstream->currentByte = v2;
    bitstream->readp = v34 + 2;
    v35 = __ROL4__(v34[1], 8) | *v34;
  }
  v36 = v35;
  v37 = this->lineDraws.num + v35;
  if ( v37 > this->lineDraws.size )
    idList<idSWFShapeParser::swfSPDrawLine_t,72>::Resize(this: &this->lineDraws, newsize: v37);
  if ( v36 > 0 )
  {
    HIDWORD(v2) = v36;
    do
    {
      idList<idSWFShapeParser::swfSPDrawLine_t,72>::PreAllocateWithGranularity(
        this: &this->lineDraws,
        newSize: this->lineDraws.num + 1);
      v39 = this->lineDraws.num;
      v40 = this->lineDraws.size;
      list = this->lineDraws.list;
      if ( v39 >= v40 )
      {
        v42 = (int)&list[v40 - 1];
      }
      else
      {
        v42 = (int)&list[v39];
        this->lineDraws.num = v39 + 1;
      }
      v43 = bitstream->readp;
      bitstream->currentBit = v2;
      v43 += 2;
      bitstream->currentByte = v2;
      bitstream->readp = v43;
      v44 = *(v43 - 2);
      LODWORD(v45) = __ROL4__(*(v43 - 1), 8);
      v46 = v45 | v44;
      *(_WORD *)v42 = v45 | v44;
      LODWORD(v38) = this->lineStyle2;
      if ( this->lineStyle2 )
      {
        *(_WORD *)(v42 + 2) = v46;
        HIDWORD(v45) = v45 | v44;
        idSWFBitStream::ReadU(this: bitstream, numBits: v38, a3: v45);
        v49 = (unsigned __int8)idSWFBitStream::ReadU(this: bitstream, numBits: v48, a3: v47);
        v52 = idSWFBitStream::ReadU(this: bitstream, numBits: v51, a3: v50) != 0;
        idSWFBitStream::ReadU(this: bitstream, numBits: v54, a3: v53);
        idSWFBitStream::ReadU(this: bitstream, numBits: v56, a3: v55);
        idSWFBitStream::ReadU(this: bitstream, numBits: v58, a3: v57);
        idSWFBitStream::ReadU(this: bitstream, numBits: v60, a3: v59);
        idSWFBitStream::ReadU(this: bitstream, numBits: v62, a3: v61);
        idSWFBitStream::ReadU(this: bitstream, numBits: v64, a3: v63);
        if ( v49 == 2 )
        {
          v65 = bitstream->readp;
          bitstream->currentBit = v2;
          bitstream->currentByte = v2;
          bitstream->readp = v65 + 2;
        }
        if ( !v52 )
        {
          idSWFBitStream::ReadColorRGBA(this: bitstream, color: (swfColorRGBA_t *)(v42 + 4));
          v66 = *(_BYTE *)(v42 + 6);
          v67 = *(_BYTE *)(v42 + 7);
          v68 = *(_BYTE *)(v42 + 4);
          *(_BYTE *)(v42 + 9) = *(_BYTE *)(v42 + 5);
          *(_BYTE *)(v42 + 10) = v66;
          *(_BYTE *)(v42 + 11) = v67;
LABEL_54:
          *(_BYTE *)(v42 + 8) = v68;
          goto LABEL_55;
        }
        idLib::Warning(fmt: "idSWFShapeParser: Ignoring hasFillFlag");
      }
      else
      {
        if ( this->morph )
        {
          v69 = bitstream->readp;
          bitstream->currentBit = v2;
          v69 += 2;
          bitstream->currentByte = v2;
          bitstream->readp = v69;
          *(_WORD *)(v42 + 2) = __ROL4__(*(v69 - 1), 8) | *(v69 - 2);
        }
        else
        {
          *(_WORD *)(v42 + 2) = v46;
        }
        v70 = (swfColorRGBA_t *)(v42 + 4);
        if ( this->rgba )
          idSWFBitStream::ReadColorRGBA(this: bitstream, color: v70);
        else
          idSWFBitStream::ReadColorRGB(this: bitstream, color: v70);
        if ( !this->morph )
        {
          v71 = *(_BYTE *)(v42 + 6);
          v72 = *(_BYTE *)(v42 + 7);
          v68 = *(_BYTE *)(v42 + 4);
          *(_BYTE *)(v42 + 9) = *(_BYTE *)(v42 + 5);
          *(_BYTE *)(v42 + 10) = v71;
          *(_BYTE *)(v42 + 11) = v72;
          goto LABEL_54;
        }
        idSWFBitStream::ReadColorRGBA(this: bitstream, color: (swfColorRGBA_t *)(v42 + 8));
      }
LABEL_55:
      --HIDWORD(v2);
    }
    while ( HIDWORD(v2) != 0 );
  }
}


// ========================================================================
// ?ParseShapes@idSWFShapeParser@@AAAXAAVidSWFBitStream@@PAV2@_N@Z
// EA  : 0x82790538
// RVA : 0x00790538
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::ParseShapes(
        idSWFShapeParser *this,
        idSWFBitStream *bitstream1,
        unsigned __int64 swap,
        unsigned __int64 a4)
{
  unsigned __int64 v4; // r23
  const unsigned __int8 *readp; // r11
  idSWFBitStream *v8; // r24
  unsigned __int8 v9; // r15
  unsigned __int8 v10; // r16
  unsigned __int8 v11; // r17
  unsigned __int64 v12; // r23
  unsigned __int16 num; // r21
  int v14; // r11
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // r6
  bool v17; // r31
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // r6
  unsigned int v20; // r3
  unsigned __int64 v21; // r8
  bool v22; // r27
  unsigned __int64 v23; // r6
  unsigned __int64 v24; // r8
  unsigned __int64 v25; // r6
  bool v26; // r28
  unsigned __int64 v27; // r6
  bool v28; // r29
  unsigned __int64 v29; // r8
  bool v30; // r11
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r6
  unsigned __int64 v33; // r8
  unsigned __int64 v34; // r6
  const unsigned __int8 *v35; // r11
  unsigned __int64 v36; // r8
  unsigned __int64 v37; // r6
  bool v38; // r27
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // r6
  unsigned int v41; // r3
  unsigned __int64 v42; // r8
  bool v43; // r28
  unsigned __int64 v44; // r6
  unsigned __int64 v45; // r8
  unsigned __int64 v46; // r6
  bool v47; // r29
  unsigned __int64 v48; // r6
  bool v49; // r31
  unsigned __int64 v50; // r8
  unsigned __int64 v51; // r8
  unsigned __int64 v52; // r6
  unsigned __int64 v53; // r8
  unsigned __int64 v54; // r6
  unsigned __int64 v55; // r6
  unsigned __int64 v56; // r8
  unsigned __int64 v57; // r8
  unsigned __int64 v58; // r6
  unsigned __int16 v59; // r29
  unsigned __int16 v60; // r28
  unsigned __int16 v61; // r25
  unsigned __int16 areaNum; // r27
  idVec2 *v63; // r10
  float *v64; // r11
  float *v65; // r10
  double v66; // fp7
  int v67; // r3
  idVec2 *list; // r10
  float *v69; // r11
  float *v70; // r10
  double v71; // fp7
  int Index; // r3
  unsigned __int16 v73; // r11
  __int16 *v74; // r10
  _WORD *v75; // r11
  int i; // ctr
  unsigned __int16 v77; // r8
  idSWFShapeParser::swfSPDrawFill_t *v78; // r11
  int v79; // [sp+50h] [-E0h] BYREF
  int v80; // [sp+54h] [-DCh] BYREF
  int v81; // [sp+58h] [-D8h] BYREF
  int v82; // [sp+5Ch] [-D4h] BYREF
  idVec2 v83; // [sp+60h] [-D0h] BYREF
  idVec2 v84; // [sp+68h] [-C8h] BYREF
  aas2Portal_t v85; // [sp+70h] [-C0h] BYREF
  __int16 v86; // [sp+7Eh] [-B2h] BYREF
  aas2Portal_t v87; // [sp+80h] [-B0h] BYREF
  char v88; // [sp+15Fh] [+2Fh]

  readp = bitstream1->readp;
  LODWORD(v4) = 0;
  v88 = swap;
  bitstream1->currentBit = v4;
  bitstream1->currentByte = v4;
  v8 = (idSWFBitStream *)HIDWORD(swap);
  v80 = 0;
  v9 = 0;
  v79 = 0;
  v10 = 0;
  v82 = 0;
  v11 = 0;
  v81 = 0;
  HIDWORD(v12) = 0;
  bitstream1->readp = readp + 1;
  num = 0;
  if ( HIDWORD(swap) != 0 )
  {
    v14 = *(_DWORD *)(HIDWORD(swap) + 12);
    *(_QWORD *)(HIDWORD(swap) + 16) = v12;
    *(_QWORD *)(HIDWORD(swap) + 24) = v12;
    *(_DWORD *)(HIDWORD(swap) + 12) = v14 + 1;
  }
  while ( 1 )
  {
    while ( idSWFBitStream::ReadU(this: bitstream1, numBits: swap, a3: a4) != 0 )
    {
      HIDWORD(v15) = &v85;
      LODWORD(v55) = &v79;
      HIDWORD(v55) = &v80;
      idSWFShapeParser::ParseEdge(this, bitstream: bitstream1, penY: v55, edge: v15);
      if ( v8 != nullptr )
      {
        if ( idSWFBitStream::ReadU(this: v8, numBits: swap, a3: v56) == 0 )
        {
          idLib::Warning(fmt: "idSWFShapeParser: morph stream 1 defines an edge, but stream 2 does not");
          return;
        }
        HIDWORD(v57) = v85.clusterAreaNum;
        LODWORD(v58) = &v81;
        HIDWORD(v58) = &v82;
        idSWFShapeParser::ParseEdge(this, bitstream: v8, penY: v58, edge: v57);
      }
      else
      {
        LODWORD(a4) = (unsigned __int16)v85.clusters[0];
        qmemcpy(v85.clusterAreaNum, &v85, 6);
      }
      v59 = v85.clusterAreaNum[1];
      v60 = v85.clusterAreaNum[0];
      v61 = v85.clusters[0];
      areaNum = v85.areaNum;
      if ( (unsigned __int16)v85.clusters[1] == 0xFFFF )
      {
        if ( v85.maxAreaTravelTime != 0xFFFF )
        {
          list = this->verts.list;
          v69 = (float *)((char *)&list->x + ((8 * v85.areaNum) & 0x7FFF8));
          v70 = (float *)((char *)&list->x + ((8 * (unsigned __int16)v85.clusters[0]) & 0x7FFF8));
          v71 = (float)((float)(v70[1] + v69[1]) * (float)0.5);
          v84.x = (float)(*v70 + *v69) * (float)0.5;
          v84.y = v71;
          Index = idList<idVec2,72>::FindIndex(this: &this->verts, obj: &v84, startIndex: 0);
          if ( Index < 0 )
            LOWORD(Index) = idList<idVec2,72>::Append(this: &this->verts, obj: &v84);
          v85.clusters[1] = Index;
        }
      }
      else if ( v85.maxAreaTravelTime == 0xFFFF )
      {
        v63 = this->verts.list;
        v64 = (float *)((char *)&v63->x + ((8 * v85.clusterAreaNum[0]) & 0x7FFF8));
        v65 = (float *)((char *)&v63->x + ((8 * v85.clusterAreaNum[1]) & 0x7FFF8));
        v66 = (float)((float)(v65[1] + v64[1]) * (float)0.5);
        v83.x = (float)(*v65 + *v64) * (float)0.5;
        v83.y = v66;
        v67 = idList<idVec2,72>::FindIndex(this: &this->verts, obj: &v83, startIndex: 0);
        if ( v67 < 0 )
          LOWORD(v67) = idList<idVec2,72>::Append(this: &this->verts, obj: &v83);
        v85.maxAreaTravelTime = v67;
      }
      if ( v11 != 0 )
        idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Append(
          this: (idList<aas2Portal_t,37> *)&this->lineDraws.list[num - 1 + v11].edges,
          obj: &v85);
      if ( v88 != 0 )
      {
        v73 = areaNum;
        v85.clusterAreaNum[0] = v59;
        v85.clusterAreaNum[1] = v60;
        v85.clusters[0] = areaNum;
        areaNum = v61;
        v85.areaNum = v61;
        v61 = v73;
      }
      if ( v10 != 0 )
        idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Append(
          this: (idList<aas2Portal_t,37> *)&this->fillDraws.list[WORD1(v12) - 1 + v10].edges,
          obj: &v85);
      HIDWORD(a4) = v9;
      if ( v9 != 0 )
      {
        v74 = &v86;
        v75 = (_WORD *)&v84.y + 1;
        for ( i = 6; i != 0; --i )
          *++v74 = *++v75;
        v77 = v87.clusterAreaNum[1];
        v87.areaNum = v61;
        v87.clusters[0] = areaNum;
        v78 = this->fillDraws.list;
        v87.clusterAreaNum[1] = v87.clusterAreaNum[0];
        v87.clusterAreaNum[0] = v77;
        idList<idSWFShapeParser::swfSPMorphEdge_t,72>::Append(
          this: (idList<aas2Portal_t,37> *)&v78[WORD1(v12) - 1 + v9].edges,
          obj: &v87);
      }
    }
    v17 = idSWFBitStream::ReadU(this: bitstream1, numBits: v16, a3: v15) != 0;
    v20 = idSWFBitStream::ReadU(this: bitstream1, numBits: v19, a3: v18);
    LODWORD(v21) = v20 - 1;
    v22 = v20 != 0;
    HIDWORD(v24) = idSWFBitStream::ReadU(this: bitstream1, numBits: v23, a3: v21);
    LODWORD(v25) = HIDWORD(v24) - 1;
    v26 = HIDWORD(v24) != 0;
    HIDWORD(v27) = idSWFBitStream::ReadU(this: bitstream1, numBits: v25, a3: v24);
    v28 = HIDWORD(v27) != 0;
    v30 = idSWFBitStream::ReadU(this: bitstream1, numBits: v27, a3: v29) != 0;
    if ( !v17 && !v22 && !v26 && !v28 && !v30 )
      break;
    if ( v30 )
    {
      idSWFBitStream::ReadU(this: bitstream1, numBits: swap, a3: a4);
      v80 = idSWFBitStream::ReadS(this: bitstream1, numBits: v32, a3: v31);
      v79 = idSWFBitStream::ReadS(this: bitstream1, numBits: v34, a3: v33);
    }
    if ( v28 )
      v9 = idSWFBitStream::ReadU(this: bitstream1, numBits: swap, a3: a4);
    if ( v26 )
      v10 = idSWFBitStream::ReadU(this: bitstream1, numBits: swap, a3: a4);
    if ( v22 )
      v11 = idSWFBitStream::ReadU(this: bitstream1, numBits: swap, a3: a4);
    if ( v17 )
    {
      HIDWORD(v12) = (unsigned __int16)this->fillDraws.num;
      num = this->lineDraws.num;
      idSWFShapeParser::ReadFillStyle(this, bitstream: bitstream1);
      v35 = bitstream1->readp;
      bitstream1->currentBit = v12;
      bitstream1->currentByte = v12;
      LODWORD(a4) = *v35;
      bitstream1->readp = v35 + 1;
    }
    if ( v8 != nullptr )
    {
      if ( idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4) != 0 )
      {
        idLib::Warning(fmt: "idSWFShapeParser: morph stream 1 defines style change, but stream 2 does not");
        return;
      }
      v38 = idSWFBitStream::ReadU(this: v8, numBits: v37, a3: v36) != 0;
      v41 = idSWFBitStream::ReadU(this: v8, numBits: v40, a3: v39);
      LODWORD(v42) = v41 - 1;
      v43 = v41 != 0;
      HIDWORD(v45) = idSWFBitStream::ReadU(this: v8, numBits: v44, a3: v42);
      LODWORD(v46) = HIDWORD(v45) - 1;
      v47 = HIDWORD(v45) != 0;
      HIDWORD(v48) = idSWFBitStream::ReadU(this: v8, numBits: v46, a3: v45);
      v49 = HIDWORD(v48) != 0;
      if ( idSWFBitStream::ReadU(this: v8, numBits: v48, a3: v50) != 0 )
      {
        idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4);
        v82 = idSWFBitStream::ReadS(this: v8, numBits: v52, a3: v51);
        v81 = idSWFBitStream::ReadS(this: v8, numBits: v54, a3: v53);
      }
      if ( v49 && idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4) != v9 )
      {
        idLib::Warning(fmt: "idSWFShapeParser: morph stream 2 defined a different fillStyle0 from stream 1");
        return;
      }
      if ( v47 && idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4) != v10 )
      {
        idLib::Warning(fmt: "idSWFShapeParser: morph stream 2 defined a different fillStyle1 from stream 1");
        return;
      }
      if ( v43 && idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4) != v11 )
      {
        idLib::Warning(fmt: "idSWFShapeParser: morph stream 2 defined a different lineStyle from stream 1");
        return;
      }
      if ( v38 )
      {
        idLib::Warning(fmt: "idSWFShapeParser: morph stream 2 defines new styles");
        return;
      }
    }
  }
  if ( v8 != nullptr && (unsigned __int8)idSWFBitStream::ReadU(this: v8, numBits: swap, a3: a4) != 0 )
    idLib::Warning(fmt: "idSWFShapeParser: morph stream 1 ends before 2");
}


// ========================================================================
// ?Parse@idSWFShapeParser@@QAAXAAVidSWFBitStream@@AAVidSWFShape@@H@Z
// EA  : 0x82790BD0
// RVA : 0x00790BD0
// PDB : w:\tech5\engine\guis\swf\swf_shapeparser.cpp
// ========================================================================

void __fastcall idSWFShapeParser::Parse(
        idSWFShapeParser *this,
        idSWFBitStream *bitstream,
        idSWFShape *shape,
        int recordType)
{
  unsigned __int64 v4; // r23
  const unsigned __int8 *readp; // r11
  unsigned __int64 v10; // r8
  idList<idSWFShapeDrawLine,72> *p_lineDraws; // r20
  int size; // r11
  int num; // r31
  int v14; // r11
  int v15; // r19
  int v16; // r21
  int v17; // r22
  idSWFShapeDrawLine *v18; // r30
  idSWFShapeParser::swfSPDrawLine_t *v19; // r31
  unsigned __int8 *p_memTag; // r9
  unsigned __int8 *v21; // r10
  int i; // ctr
  idList<unsigned short,5> *p_indices; // r25
  int v24; // r4
  int v25; // r24
  idList<idVec2,72> *p_startVerts; // r27
  int v27; // r30
  const idVec2 *v28; // r29
  int Index; // r3
  unsigned __int16 v30; // r29
  unsigned __int16 *v31; // r8
  int v32; // r4
  int v33; // r7
  __int64 v34; // r9
  float *v35; // r7
  __int64 list; // r11
  double v37; // fp5
  double v38; // fp3
  double v41; // fp8
  int v42; // r26
  double v43; // fp31
  int v44; // r29
  idVec2 *v45; // r10
  idSWFShapeParser::swfSPMorphEdge_t *v46; // r11
  double v47; // fp12
  int v48; // r6
  int v49; // r8
  float *v50; // r11
  float *v51; // r9
  float *v52; // r10
  double v53; // fp4
  double v54; // fp0
  double v55; // fp13
  double v56; // fp12
  double v57; // fp6
  int v58; // r3
  unsigned __int16 v59; // r18
  const idVec2 *v60; // r29
  int v61; // r3
  unsigned __int16 v62[4]; // [sp+50h] [-E0h] BYREF
  idVec2 v63; // [sp+58h] [-D8h] BYREF
  int v65; // [sp+64h] [-CCh]
  __int64 v66; // [sp+68h] [-C8h]
  __int64 v67; // [sp+70h] [-C0h]
  swfRect_t v68; // [sp+80h] [-B0h] BYREF

  this->rgba = recordType >= 3;
  LODWORD(v4) = 0;
  this->extendedCount = ((recordType >= 0) + ((unsigned int)recordType <= 1)) & 1;
  this->lineStyle2 = (_cntlzw(recordType - 4) & 0x20) != 0;
  this->morph = false;
  idSWFBitStream::ReadRect(this: bitstream, rect: &shape->startBounds);
  shape->endBounds = shape->startBounds;
  if ( recordType == 4 )
  {
    v68.tl.x = 0.0;
    v68.tl.y = 0.0;
    v68.br.x = 0.0;
    v68.br.y = 0.0;
    idSWFBitStream::ReadRect(this: bitstream, rect: &v68);
    readp = bitstream->readp;
    bitstream->currentBit = v4;
    bitstream->currentByte = v4;
    bitstream->readp = readp + 1;
  }
  idSWFShapeParser::ReadFillStyle(this, bitstream);
  idSWFShapeParser::ParseShapes(this, bitstream1: bitstream, swap: 0, a4: v10);
  idSWFShapeParser::TriangulateSoup(this, shape);
  p_lineDraws = &shape->lineDraws;
  size = shape->lineDraws.size;
  num = this->lineDraws.num;
  if ( num <= size
    || (unsigned __int8)idList<idSWFShapeDrawLine,72>::Resize(this: p_lineDraws, newsize: this->lineDraws.num) != 0 )
  {
    v14 = p_lineDraws->size;
    if ( num < v14 )
      v14 = num;
    p_lineDraws->num = v14;
  }
  v15 = 0;
  if ( this->lineDraws.num > 0 )
  {
    v16 = 0;
    v17 = 0;
    do
    {
      v18 = &p_lineDraws->list[v17];
      v19 = &this->lineDraws.list[v16];
      p_memTag = &v18[-1].indices.memTag;
      v21 = &v19[-1].edges.memTag;
      for ( i = 6; i != 0; --i )
      {
        v21 += 2;
        p_memTag += 2;
        *(_WORD *)p_memTag = *(_WORD *)v21;
      }
      p_indices = (idList<unsigned short,5> *)&v18->indices;
      v24 = 3 * v19->edges.num;
      if ( v24 > v18->indices.size )
        idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)&v18->indices, newsize: v24);
      v25 = 0;
      if ( v19->edges.num > 0 )
      {
        p_startVerts = &v18->startVerts;
        v27 = 0;
        do
        {
          v28 = (idVec2 *)((char *)this->verts.list + __ROL4__(v19->edges.list[v27].start.v0, 3));
          Index = idList<idVec2,72>::FindIndex(this: p_startVerts, obj: v28, startIndex: 0);
          if ( Index < 0 )
            LOWORD(Index) = idList<idVec2,72>::Append(this: p_startVerts, obj: v28);
          v30 = Index;
          v62[0] = Index;
          idList<unsigned short,72>::Append(this: p_indices, obj: v62);
          v62[0] = v30;
          idList<unsigned short,72>::Append(this: p_indices, obj: v62);
          if ( v19->edges.list[v27].start.cp != 0xFFFF )
          {
            list = (unsigned int)this->verts.list;
            v31 = &v19->edges.list[v27].start.v0;
            v32 = v31[3];
            v33 = __ROL4__(v31[4], 3);
            LODWORD(v34) = __ROL4__(v31[1], 3) + list;
            HIDWORD(v34) = __ROL4__(*v31, 3) + list;
            v35 = (float *)(v33 + list);
            LODWORD(list) = __ROL4__(v32, 3) + list;
            v37 = (float)(*(float *)(HIDWORD(v34) + 4) - *(float *)(v34 + 4));
            v38 = (float)(*(float *)(list + 4) - v35[1]);
            _FP10 = (float)((float)__fsqrts((float)((float)((float)v37 * (float)v37)
                                                  + (float)((float)(*(float *)HIDWORD(v34) - *(float *)v34)
                                                          * (float)(*(float *)HIDWORD(v34) - *(float *)v34))))
                          - (float)__fsqrts((float)((float)((float)v38 * (float)v38)
                                                  + (float)((float)(*(float *)list - *v35)
                                                          * (float)(*(float *)list - *v35)))));
            __asm { fsel      f9, f10, f12, f11 }
            v41 = (float)((float)_FP9 * (float)-0.1);
            v65 = (int)v41;
            v42 = 1 - (int)v41;
            if ( v42 > 0 )
            {
              LODWORD(list) = 1 - (int)v41;
              v66 = list;
              v43 = (float)((float)list + (float)1.0);
              do
              {
                v44 = HIDWORD(list) + 1;
                LODWORD(v34) = HIDWORD(list) + 1;
                v45 = this->verts.list;
                v46 = &v19->edges.list[v27];
                v67 = v34;
                v47 = (float)v34;
                v48 = v46->start.v1;
                v49 = __ROL4__(v46->start.cp, 3);
                v50 = (float *)((char *)&v45->x + __ROL4__(v46->start.v0, 3));
                v51 = (float *)((char *)&v45->x + v49);
                v52 = (float *)((char *)&v45->x + __ROL4__(v48, 3));
                v53 = (float)((float)1.0 - (float)((float)v47 / (float)v43));
                v54 = (float)(*v52 * (float)((float)((float)v47 / (float)v43) * (float)((float)v47 / (float)v43)));
                v55 = (float)(v52[1] * (float)((float)((float)v47 / (float)v43) * (float)((float)v47 / (float)v43)));
                v56 = (float)((float)((float)((float)1.0 - (float)((float)v47 / (float)v43))
                                    * (float)((float)v47 / (float)v43))
                            * (float)2.0);
                v57 = (float)((float)(v51[1] * (float)v56) + (float)(v50[1] * (float)((float)v53 * (float)v53)));
                v63.x = (float)v54
                      + (float)((float)(*v51 * (float)v56) + (float)(*v50 * (float)((float)v53 * (float)v53)));
                v63.y = (float)v55 + (float)v57;
                v58 = idList<idVec2,72>::FindIndex(this: p_startVerts, obj: &v63, startIndex: 0);
                if ( v58 < 0 )
                  LOWORD(v58) = idList<idVec2,72>::Append(this: p_startVerts, obj: &v63);
                v59 = v58;
                v62[0] = v58;
                idList<unsigned short,72>::Append(this: p_indices, obj: v62);
                v62[0] = v59;
                idList<unsigned short,72>::Append(this: p_indices, obj: v62);
                v62[0] = v59;
                idList<unsigned short,72>::Append(this: p_indices, obj: v62);
                HIDWORD(list) = v44;
              }
              while ( v44 < v42 );
            }
          }
          v60 = (idVec2 *)((char *)this->verts.list + __ROL4__(v19->edges.list[v27].start.v1, 3));
          v61 = idList<idVec2,72>::FindIndex(this: p_startVerts, obj: v60, startIndex: 0);
          if ( v61 < 0 )
            LOWORD(v61) = idList<idVec2,72>::Append(this: p_startVerts, obj: v60);
          v62[0] = v61;
          idList<unsigned short,72>::Append(this: p_indices, obj: v62);
          ++v25;
          ++v27;
        }
        while ( v25 < v19->edges.num );
      }
      ++v15;
      ++v17;
      ++v16;
    }
    while ( v15 < this->lineDraws.num );
  }
}

