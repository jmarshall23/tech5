
// ========================================================================
// ?QuickSortWeights@idConvexHull@@CAXPBMPAFH@Z
// EA  : 0x827B2470
// RVA : 0x007B2470
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void __fastcall idConvexHull::QuickSortWeights(const float *weights, __int16 *indices, int num)
{
  int v3; // r28
  int *v4; // r29
  int *v5; // r31
  int v6; // r7
  int v7; // r6
  int v8; // r30
  int v9; // r8
  int v10; // r11
  int v11; // r10
  __int16 v12; // r9
  int v13; // r5
  __int16 *v14; // r11
  __int16 *v15; // r11
  __int16 *v16; // r11
  __int16 *v17; // r11
  bool v18; // cr57
  __int16 v19; // r26
  __int16 v20; // r8
  _DWORD *v21; // r31
  __int16 v22; // r7
  int v23; // [sp+10h] [-840h] BYREF
  int v24; // [sp+410h] [-440h] BYREF

  v3 = 0;
  v23 = num - 1;
  v24 = 0;
  v4 = &v23;
  v5 = &v24;
  do
  {
    v6 = *v5;
    v7 = *v4;
    if ( *v5 < *v4 )
    {
      v8 = v6;
      v9 = v6 + 1;
      v10 = (v7 + v6) >> 1;
      v11 = *v4;
      v12 = indices[v6];
      indices[v6] = indices[v10];
      indices[v10] = v12;
      v13 = indices[v6];
      if ( v6 + 1 <= v7 )
      {
        do
        {
          if ( v9 <= v7 )
          {
            if ( v7 - v9 + 1 < 4 )
            {
LABEL_12:
              if ( v9 <= v7 )
              {
                v15 = &indices[v9];
                do
                {
                  if ( (float)(weights[*v15] - weights[v13]) > 0.0 )
                    break;
                  ++v9;
                  ++v15;
                }
                while ( v9 <= v7 );
              }
            }
            else
            {
              v14 = &indices[v9 + 2];
              while ( (float)(weights[*(v14 - 2)] - weights[v13]) <= 0.0 )
              {
                if ( (float)(weights[*(v14 - 1)] - weights[v13]) > 0.0 )
                {
                  ++v9;
                  break;
                }
                if ( (float)(weights[*v14] - weights[v13]) > 0.0 )
                {
                  v9 += 2;
                  break;
                }
                if ( (float)(weights[v14[1]] - weights[v13]) > 0.0 )
                {
                  v9 += 3;
                  break;
                }
                v9 += 4;
                v14 += 4;
                if ( v9 > v7 - 3 )
                  goto LABEL_12;
              }
            }
          }
          if ( v11 >= v6 )
          {
            if ( v11 - v6 + 1 < 4 )
            {
LABEL_28:
              if ( v11 >= v6 )
              {
                v17 = &indices[v11];
                do
                {
                  if ( (float)(weights[*v17] - weights[v13]) <= 0.0 )
                    break;
                  --v11;
                  --v17;
                }
                while ( v11 >= v6 );
              }
            }
            else
            {
              v16 = &indices[v11 - 2];
              while ( (float)(weights[v16[2]] - weights[v13]) > 0.0 )
              {
                if ( (float)(weights[v16[1]] - weights[v13]) <= 0.0 )
                {
                  --v11;
                  break;
                }
                if ( (float)(weights[*v16] - weights[v13]) <= 0.0 )
                {
                  v11 -= 2;
                  break;
                }
                if ( (float)(weights[*(v16 - 1)] - weights[v13]) <= 0.0 )
                {
                  v11 -= 3;
                  break;
                }
                v11 -= 4;
                v16 -= 4;
                if ( v11 < v6 + 3 )
                  goto LABEL_28;
              }
            }
          }
          v18 = v9 > v11;
          if ( v9 < v11 )
          {
            v18 = v9 > v11;
            v19 = indices[v9];
            indices[v9] = indices[v11];
            indices[v11] = v19;
          }
        }
        while ( !v18 );
      }
      v20 = indices[v8];
      *v5 = v11 + 1;
      v3 += 2;
      v21 = v5 + 1;
      *v21 = v6;
      v22 = indices[v11];
      v4[1] = v11 - 1;
      v5 = v21 + 1;
      v4 += 2;
      indices[v8] = v22;
      indices[v11] = v20;
    }
    --v3;
    --v5;
    --v4;
  }
  while ( v3 >= 0 );
}


// ========================================================================
// ?QuickSortPoints@idConvexHull@@CAXPBVidVec2i@@PAFH@Z
// EA  : 0x827B2768
// RVA : 0x007B2768
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void __fastcall idConvexHull::QuickSortPoints(const idVec2i *points, __int16 *indices, int num)
{
  int v3; // r26
  int *v4; // r27
  int *v5; // r28
  int v6; // r31
  int v7; // r30
  int v8; // r29
  int v9; // r10
  int v10; // r6
  int v11; // r7
  __int16 v12; // r9
  const idVec2i *v13; // r5
  int x; // r8
  __int16 *v15; // r9
  const idVec2i *v16; // r11
  int v17; // r10
  int v18; // r8
  __int16 *v19; // r9
  const idVec2i *v20; // r11
  int v21; // r10
  bool v22; // cr57
  __int16 v23; // r8
  int v24; // r11
  __int16 v25; // r8
  int v26; // r9
  _DWORD *v27; // r28
  __int16 v28; // r7
  int v29; // [sp+10h] [-840h] BYREF
  int v30; // [sp+410h] [-440h] BYREF

  v3 = 0;
  v30 = 0;
  v4 = &v29;
  v29 = num - 1;
  v5 = &v30;
  do
  {
    v6 = *v5;
    v7 = *v4;
    if ( *v5 < *v4 )
    {
      v8 = v6;
      v9 = (v7 + v6) >> 1;
      v10 = v6 + 1;
      v11 = *v4;
      v12 = indices[v6];
      indices[v6] = indices[v9];
      indices[v9] = v12;
      v13 = &points[indices[v6]];
      if ( v6 + 1 <= v7 )
      {
        do
        {
          if ( v10 <= v7 )
          {
            x = v13->x;
            v15 = &indices[v10];
            do
            {
              v16 = &points[*v15];
              v17 = v16->x - x;
              if ( v16->x == x )
                v17 = v16->y - v13->y;
              if ( v17 > 0 )
                break;
              ++v10;
              ++v15;
            }
            while ( v10 <= v7 );
          }
          if ( v11 >= v6 )
          {
            v18 = v13->x;
            v19 = &indices[v11];
            do
            {
              v20 = &points[*v19];
              v21 = v20->x - v18;
              if ( v20->x == v18 )
                v21 = v20->y - v13->y;
              if ( v21 <= 0 )
                break;
              --v11;
              --v19;
            }
            while ( v11 >= v6 );
          }
          v22 = v10 > v11;
          if ( v10 < v11 )
          {
            v22 = v10 > v11;
            v23 = indices[v10];
            indices[v10] = indices[v11];
            indices[v11] = v23;
          }
        }
        while ( !v22 );
      }
      v24 = v11;
      v25 = indices[v8];
      v26 = v11 - 1;
      *v5 = v11 + 1;
      v3 += 2;
      v27 = v5 + 1;
      *v27 = v6;
      v28 = indices[v11];
      v4[1] = v26;
      v5 = v27 + 1;
      v4 += 2;
      indices[v8] = v28;
      indices[v24] = v25;
    }
    --v3;
    --v5;
    --v4;
  }
  while ( v3 >= 0 );
}


// ========================================================================
// ?Create@idConvexHull@@QAAXABV?$idList@VidVec2i@@$04@@M@Z
// EA  : 0x827B2C70
// RVA : 0x007B2C70
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __fastcall idConvexHull::Create(idConvexHull *this, const idList<idVec2i,5> *points, double shrink)
{
  double v3; // fp1
  int v4; // r4
  int v5; // r30
  int v6; // r28
  double v7; // fp29
  unsigned __int16 *list; // r9
  idList<idVec2,72> *v9; // r3
  idList<idVec2,72> *v10; // r21
  const idVec2i **v11; // r23
  int v12; // r24
  int v13; // r29
  const idVec2i *v14; // r29
  const idVec2i *v15; // r30
  int v16; // r27
  int v17; // r26
  int v18; // r25
  int v19; // r29
  const idVec2i *v20; // r11
  int v21; // r11
  idList<unsigned short,5> *v22; // r3
  int v23; // r29
  int v24; // r30
  int num; // r11
  unsigned __int16 *v26; // r10
  int v27; // r4
  unsigned __int16 *v28; // r9
  signed __int16 v29; // r5
  const idVec2i *v30; // r7
  const idVec2i *v31; // r6
  const idVec2i *v32; // r8
  int v33; // r29
  int v34; // r30
  int v35; // r4
  signed __int16 v36; // r5
  const idVec2i *v37; // r7
  const idVec2i *v38; // r6
  const idVec2i *v39; // r8
  int v40; // r8
  int v41; // r7
  int v42; // r8
  int v43; // r29
  int v44; // r30
  __int128 v45; // r6
  int v46; // r30
  __int16 *v47; // r9
  int size; // r8
  signed int v49; // r27
  bool v50; // cr57
  int v51; // r11
  bool v52; // cr57
  int v53; // r11
  bool v54; // cr57
  int v55; // r11
  bool v56; // cr57
  signed int v57; // r29
  int v58; // r30
  int v59; // r10
  __int128 v60; // r6 OVERLAPPED
  idSkinMapping *v61; // r10
  __int64 v62; // r9
  const idMaterial *to; // r11
  const idMaterial *from; // r10
  double v65; // fp12
  double v66; // fp7
  __int64 v67; // fp10
  double v68; // fp1
  const idMaterial *v69; // r7
  double v71; // fp3
  double v73; // fp13
  double v74; // fp9
  double v75; // fp4
  double v76; // fp3
  int v77; // r8
  int v78; // r11
  __int16 v79; // r9
  int v80; // r5
  int v81; // r7
  int v82; // r6
  int v83; // r30
  int v84; // r29
  int i; // r30
  __int64 v86; // r5
  __int64 v87; // r11
  int v88; // r11
  int v89; // ctr
  int v90; // r9
  int v91; // r10
  double v92; // fp0
  float *v93; // r10
  float *p_x; // r11
  double v95; // fp12
  double v96; // fp10
  double v99; // fp1
  double v100; // fp4
  double v101; // fp1
  double v102; // fp4
  double v103; // fp3
  double v104; // fp11
  double v105; // fp10
  float v106[2]; // [sp+50h] [-5120h] BYREF
  idVec2 v107; // [sp+58h] [-5118h] BYREF
  __int64 v108; // [sp+60h] [-5110h]
  __int64 v109; // [sp+68h] [-5108h]
  __int64 v110; // [sp+70h] [-5100h]
  __int64 v111; // [sp+78h] [-50F8h]
  __int64 v112; // [sp+80h] [-50F0h]
  idList<unsigned short,5> v113; // [sp+90h] [-50E0h] BYREF
  int v114; // [sp+A0h] [-50D0h] BYREF
  idList<unsigned short,5> v115; // [sp+8A0h] [-48D0h] BYREF
  _BYTE v116[2048]; // [sp+8B0h] [-48C0h] BYREF
  idList<unsigned short,5> v117; // [sp+10B0h] [-40C0h] BYREF
  int v118; // [sp+10C0h] [-40B0h] BYREF
  idList<unsigned short,5> v119; // [sp+18C0h] [-38B0h] BYREF
  int v120; // [sp+18D0h] [-38A0h] BYREF
  idList<float,13> v121; // [sp+20D0h] [-30A0h] BYREF
  int v122; // [sp+20E0h] [-3090h] BYREF
  idList<idSkinMapping,46> v123; // [sp+30E0h] [-2090h] BYREF
  int v124; // [sp+30F0h] [-2080h] BYREF

  v3 = ((double (*)(void))RtlCheckStack12)();
  v5 = *(_DWORD *)(v4 + 4);
  v6 = 1;
  v7 = v3;
  v115.granularity = 1;
  v115.size = 1024;
  list = (unsigned __int16 *)v116;
  v115.num = 0;
  v10 = v9;
  LODWORD(v106[0]) = v5;
  v11 = (const idVec2i **)v4;
  v115.list = (unsigned __int16 *)v116;
  v12 = v5 - 1;
  v115.memTag = 5;
  v115.listStatic = 1;
  v117.num = 0;
  v117.size = 1024;
  v117.granularity = 1;
  v117.list = (unsigned __int16 *)&v118;
  v117.memTag = 5;
  v117.listStatic = 1;
  v119.num = 0;
  v119.size = 1024;
  v119.granularity = 1;
  v119.list = (unsigned __int16 *)&v120;
  v119.memTag = 5;
  v119.listStatic = 1;
  v113.num = 0;
  v113.size = 1024;
  v113.granularity = 1;
  v113.list = (unsigned __int16 *)&v114;
  v113.memTag = 5;
  v113.listStatic = 1;
  v121.num = 0;
  v121.size = 1024;
  v121.granularity = 1;
  v121.list = (float *)&v122;
  v121.memTag = 5;
  v121.listStatic = 1;
  v123.num = 0;
  v123.size = 1024;
  v123.granularity = 1;
  v123.list = (idSkinMapping *)&v124;
  v123.memTag = 5;
  v123.listStatic = 1;
  v13 = 0;
  if ( v5 > 0 )
  {
    do
    {
      HIWORD(v106[0]) = v13;
      idList<unsigned short,72>::Append(this: &v115, obj: (unsigned __int16 *)v106);
      ++v13;
    }
    while ( v13 < v5 );
    if ( v115.num > 0 )
      idConvexHull::QuickSortPoints(points: *v11, indices: (__int16 *)v115.list, num: v115.num);
    list = v115.list;
  }
  HIWORD(v106[0]) = 0;
  v14 = &(*v11)[(__int16)*list];
  v15 = &(*v11)[(__int16)list[v12]];
  idList<unsigned short,72>::Append(this: &v117, obj: (unsigned __int16 *)v106);
  HIWORD(v106[0]) = 0;
  idList<unsigned short,72>::Append(this: &v119, obj: (unsigned __int16 *)v106);
  v16 = 1;
  v17 = v14->y - v15->y;
  v18 = v14->x - v15->x;
  if ( v12 > 1 )
  {
    v19 = 1;
    while ( 1 )
    {
      v20 = &(*v11)[(__int16)v115.list[v19]];
      v21 = (v20->y - v15->y) * v18 - v17 * (v20->x - v15->x);
      if ( v21 < 0 )
        break;
      if ( v21 > 0 )
      {
        v22 = &v119;
        goto LABEL_12;
      }
LABEL_13:
      ++v16;
      ++v19;
      if ( v16 >= v12 )
        goto LABEL_14;
    }
    v22 = &v117;
LABEL_12:
    HIWORD(v106[0]) = v16;
    idList<unsigned short,72>::Append(this: v22, obj: (unsigned __int16 *)v106);
    goto LABEL_13;
  }
LABEL_14:
  HIWORD(v106[0]) = v12;
  idList<unsigned short,72>::Append(this: &v117, obj: (unsigned __int16 *)v106);
  v23 = 0;
  if ( v117.num <= 0 )
  {
    v28 = v115.list;
    num = v113.num;
    v26 = v113.list;
  }
  else
  {
    v24 = 0;
    do
    {
      idList<unsigned short,72>::Append(this: &v113, obj: &v117.list[v24]);
      num = v113.num;
      if ( v113.num < 3 )
      {
LABEL_22:
        v28 = v115.list;
        v26 = v113.list;
      }
      else
      {
        while ( 1 )
        {
          v26 = v113.list;
          v27 = num - 2;
          v28 = v115.list;
          v29 = v113.list[num - 1];
          v30 = &(*v11)[(__int16)v115.list[(__int16)v113.list[num - 3]]];
          v31 = &(*v11)[(__int16)v115.list[(__int16)v113.list[v27]]];
          v32 = &(*v11)[(__int16)v115.list[v29]];
          if ( (v31->y - v32->y) * (v30->x - v32->x) - (v30->y - v32->y) * (v31->x - v32->x) < 0 )
            break;
          v113.list[v27] = v29;
          num = v113.num;
          if ( v113.num - 1 >= 0 && v113.num - 1 < v113.num )
            num = --v113.num;
          if ( num < 3 )
            goto LABEL_22;
        }
      }
      ++v23;
      ++v24;
    }
    while ( v23 < v117.num );
  }
  v33 = v119.num - 1;
  if ( v119.num - 1 >= 0 )
  {
    v34 = v33;
    do
    {
      idList<unsigned short,72>::Append(this: &v113, obj: &v119.list[v34]);
      num = v113.num;
      if ( v113.num < 3 )
      {
LABEL_34:
        v28 = v115.list;
        v26 = v113.list;
      }
      else
      {
        while ( 1 )
        {
          v26 = v113.list;
          v35 = num - 2;
          v28 = v115.list;
          v36 = v113.list[num - 1];
          v37 = &(*v11)[(__int16)v115.list[(__int16)v113.list[num - 3]]];
          v38 = &(*v11)[(__int16)v115.list[(__int16)v113.list[v35]]];
          v39 = &(*v11)[(__int16)v115.list[v36]];
          if ( (v38->y - v39->y) * (v37->x - v39->x) - (v37->y - v39->y) * (v38->x - v39->x) < 0 )
            break;
          v113.list[v35] = v36;
          num = v113.num;
          if ( v113.num - 1 >= 0 && v113.num - 1 < v113.num )
            num = --v113.num;
          if ( num < 3 )
            goto LABEL_34;
        }
      }
      --v33;
      --v34;
    }
    while ( v33 >= 0 );
  }
  if ( num > 0 && *v26 == v26[num - 1] )
  {
    v40 = num - 1;
    if ( num - 1 < num )
    {
      --num;
      v113.num = v40;
    }
  }
  v41 = 0;
  if ( num > 0 )
  {
    v42 = 0;
    do
    {
      ++v41;
      v26[v42] = v28[(__int16)v26[v42]];
      ++v42;
      v28 = v115.list;
      v26 = v113.list;
      num = v113.num;
    }
    while ( v41 < v113.num );
  }
  v43 = 0;
  if ( num >= 10 )
  {
    v46 = 0;
    do
    {
      idList<cachedPageFile_t,5>::Append(this: &v123, obj: (const idSkinMapping *)&(*v11)[(__int16)v26[v46]]);
      ++v43;
      v26 = v113.list;
      ++v46;
    }
    while ( v43 < v113.num );
    v47 = (__int16 *)v115.list;
    size = v115.size;
    v49 = v113.num;
    v50 = v115.size > 0;
    if ( v115.size < 0 )
    {
      if ( v115.listStatic == 0 || v115.listStatic == 2 )
      {
        if ( v115.list != nullptr )
        {
          idMem::Free(this: &mem, ptr: v115.list, align: ALIGN_16);
          v26 = v113.list;
        }
        v47 = nullptr;
        v115.list = nullptr;
        size = 0;
        v115.size = 0;
LABEL_58:
        v115.num = size;
LABEL_59:
        v51 = v121.size;
        v52 = v121.size > 0;
        if ( v121.size < 0 )
        {
          if ( v121.listStatic == 0 || v121.listStatic == 2 )
          {
            if ( v121.list != nullptr )
            {
              idMem::Free(this: &mem, ptr: v121.list, align: ALIGN_16);
              v47 = (__int16 *)v115.list;
              v26 = v113.list;
            }
            v51 = 0;
            v121.list = nullptr;
            v121.size = 0;
LABEL_67:
            v121.num = v51;
LABEL_68:
            v53 = v119.size;
            v54 = v119.size > 0;
            if ( v119.size < 0 )
            {
              if ( v119.listStatic == 0 || v119.listStatic == 2 )
              {
                if ( v119.list != nullptr )
                {
                  idMem::Free(this: &mem, ptr: v119.list, align: ALIGN_16);
                  v47 = (__int16 *)v115.list;
                  v26 = v113.list;
                }
                v53 = 0;
                v119.list = nullptr;
                v119.size = 0;
LABEL_76:
                v119.num = v53;
LABEL_77:
                v55 = v117.size;
                v56 = v117.size > 0;
                if ( v117.size < 0 )
                {
                  if ( v117.listStatic == 0 || v117.listStatic == 2 )
                  {
                    if ( v117.list != nullptr )
                    {
                      idMem::Free(this: &mem, ptr: v117.list, align: ALIGN_16);
                      v47 = (__int16 *)v115.list;
                      v26 = v113.list;
                    }
                    v55 = 0;
                    v117.list = nullptr;
                    v117.size = 0;
                    goto LABEL_85;
                  }
                  v56 = v117.size > 0;
                }
                v117.num = 0;
                if ( v56 )
                {
LABEL_86:
                  v57 = 0;
                  if ( v49 > 0 )
                  {
                    v58 = 0;
                    v59 = 8 * (v49 - 1);
                    do
                    {
                      DWORD1(v60) = v106;
                      v62 = *(__int64 *)((char *)v123.list + v59);
                      v61 = &v123.list[v6];
                      DWORD2(v60) = v123.list[v58].from;
                      to = v61->to;
                      from = v61->from;
                      v109 = *(_QWORD *)((char *)&v60 + 4);
                      LODWORD(v60) = (char *)to - v62;
                      v65 = (double)*(__int64 *)((char *)&v60 + 4);
                      DWORD2(v60) = (char *)from - HIDWORD(v62);
                      v110 = v60;
                      v66 = (double)(__int64)v60;
                      v107 = *(idVec2 *)((char *)&v60 + 4);
                      v67 = *(_QWORD *)((char *)&v60 + 4);
                      v68 = (float)(__int64)v60;
                      LODWORD(v60) = (char *)from + HIDWORD(v62);
                      v69 = v123.list[v58].to;
                      DWORD2(v60) = (char *)from + HIDWORD(v62);
                      v108 = *(_QWORD *)((char *)&v60 + 4);
                      v111 = *(_QWORD *)((char *)&v60 - 4);
                      LODWORD(v62) = (char *)to + v62;
                      v112 = v62;
                      _FP4 = (float)((float)((float)((float)v66 * (float)v66) + (float)((float)v67 * (float)v67))
                                   - idMath::FLT_SMALLEST_NON_DENORMAL);
                      v71 = (float)((float)((float)((float)v66 * (float)v66) + (float)((float)v67 * (float)v67))
                                  * (float)0.5);
                      __asm { fsel      f0, f4, f9, f0 }
                      v73 = __frsqrte(_FP0);
                      v74 = (float)((float)-(float)((float)((float)((float)v73
                                                                  * (float)((float)((float)((float)v66 * (float)v66)
                                                                                  + (float)((float)v67 * (float)v67))
                                                                          * (float)0.5))
                                                          * (float)v73)
                                                  - (float)1.5)
                                  * (float)v73);
                      v75 = (float)((float)-(float)((float)((float)((float)v74
                                                                  * (float)((float)((float)((float)v66 * (float)v66)
                                                                                  + (float)((float)v67 * (float)v67))
                                                                          * (float)0.5))
                                                          * (float)v74)
                                                  - (float)1.5)
                                  * (float)v74);
                      v76 = (float)((float)((float)-(float)((float)((float)((float)v74 * (float)v71) * (float)v74)
                                                          - (float)1.5)
                                          * (float)v74)
                                  * (float)v71);
                      v106[0] = __fabs((float)((float)((float)-(float)((float)((float)v62 * (float)0.5)
                                                                     - (float)*(__int64 *)((char *)&v60 - 4))
                                                     * (float)((float)((float)-(float)((float)((float)v76 * (float)v75)
                                                                                     - (float)1.5)
                                                                     * (float)v75)
                                                             * (float)v67))
                                             + (float)((float)-(float)((float)((float)-(float)((float)((float)v76 * (float)v75)
                                                                                             - (float)1.5)
                                                                             * (float)v75)
                                                                     * (float)v68)
                                                     * (float)-(float)((float)((float)*(__int64 *)((char *)&v60 + 4)
                                                                             * (float)0.5)
                                                                     - (float)v65))));
                      idList<float,13>::Append(this: &v121, obj: v106);
                      idList<unsigned short,72>::Append(this: &v115, obj: (unsigned __int16 *)v106);
                      idList<unsigned short,72>::Append(this: &v119, obj: (unsigned __int16 *)v106);
                      HIWORD(v106[0]) = v6;
                      idList<unsigned short,72>::Append(this: &v117, obj: (unsigned __int16 *)v106);
                      ++v57;
                      v59 = v58 * 8;
                      __twllei(v49, 0);
                      ++v58;
                      __twlgei(v49 & ~(__ROL4__(v6 + 1, 1) - 1), 0xFFFFFFFF);
                      v6 = (v6 + 1) % v49;
                    }
                    while ( v57 < v49 );
                    v47 = (__int16 *)v115.list;
                    v26 = v113.list;
                  }
                  if ( v115.num > 0 )
                  {
                    idConvexHull::QuickSortWeights(weights: v121.list, indices: v47, num: v115.num);
                    v47 = (__int16 *)v115.list;
                    v26 = v113.list;
                  }
                  v77 = 0;
                  if ( v115.num - 10 > 0 )
                  {
                    v78 = 0;
                    do
                    {
                      v79 = v47[v78];
                      ++v77;
                      ++v78;
                      v80 = v79;
                      v81 = (__int16)v117.list[v80];
                      v82 = (__int16)v119.list[v80];
                      v119.list[v81] = v82;
                      v117.list[v82] = v81;
                      v119.list[v80] = -1;
                      v117.list[v80] = -1;
                      v47 = (__int16 *)v115.list;
                    }
                    while ( v77 < v115.num - 10 );
                    v26 = v113.list;
                  }
                  if ( v113.listStatic == 0 || v113.listStatic == 2 )
                  {
                    if ( v26 != nullptr )
                    {
                      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
                      v47 = (__int16 *)v115.list;
                    }
                    v113.list = nullptr;
                    v113.size = 0;
                  }
                  v83 = 10;
                  v113.num = 0;
                  v84 = (__int16)v117.list[v47[v115.num - 1]];
                  do
                  {
                    HIWORD(v106[0]) = v84;
                    idList<unsigned short,72>::Append(this: &v113, obj: (unsigned __int16 *)v106);
                    --v83;
                    v84 = (__int16)v117.list[v84];
                  }
                  while ( v83 != 0 );
                  for ( i = 0; i < 10; ++i )
                  {
                    HIDWORD(v86) = &v107;
                    HIDWORD(v87) = 8 * (__int16)v113.list[i];
                    LODWORD(v106[0]) = (char *)v123.list + HIDWORD(v87);
                    LODWORD(v86) = *(const idMaterial **)((char *)&v123.list->from + HIDWORD(v87));
                    LODWORD(v87) = *(const idMaterial **)((char *)&v123.list->to + HIDWORD(v87));
                    v111 = v86;
                    v108 = v87;
                    v107.y = (float)v87;
                    v107.x = (float)v86;
                    idList<idVec2,72>::Append(this: v10, obj: &v107);
                  }
                  v26 = v113.list;
                  goto LABEL_106;
                }
LABEL_85:
                v117.num = v55;
                goto LABEL_86;
              }
              v54 = v119.size > 0;
            }
            v119.num = 0;
            if ( v54 )
              goto LABEL_77;
            goto LABEL_76;
          }
          v52 = v121.size > 0;
        }
        v121.num = 0;
        if ( v52 )
          goto LABEL_68;
        goto LABEL_67;
      }
      v50 = v115.size > 0;
    }
    v115.num = 0;
    if ( v50 )
      goto LABEL_59;
    goto LABEL_58;
  }
  if ( num > 0 )
  {
    v44 = 0;
    do
    {
      DWORD1(v45) = &v107;
      LODWORD(v106[0]) = &(*v11)[(__int16)v26[v44]];
      LODWORD(v45) = *(_DWORD *)LODWORD(v106[0]);
      DWORD2(v45) = *(_DWORD *)(LODWORD(v106[0]) + 4);
      v110 = v45;
      v109 = *(_QWORD *)((char *)&v45 + 4);
      v107.y = (float)*(__int64 *)((char *)&v45 + 4);
      v107.x = (float)(__int64)v45;
      idList<idVec2,72>::Append(this: v10, obj: &v107);
      ++v43;
      v26 = v113.list;
      ++v44;
    }
    while ( v43 < v113.num );
LABEL_106:
    v28 = v115.list;
  }
  if ( __fabs(v7) > 0.00000011920929 )
  {
    v88 = v10->num;
    if ( v88 > 0 )
    {
      v89 = v10->num;
      v90 = 0;
      v91 = 8 * (v88 - 1);
      v92 = idMath::FLT_SMALLEST_NON_DENORMAL;
      do
      {
        v93 = (float *)((char *)&v10->list->x + v91);
        p_x = &v10->list[v90].x;
        v95 = v93[1];
        v96 = (float)(v93[1] - p_x[1]);
        _FP4 = (float)((float)((float)((float)(*v93 - *p_x) * (float)(*v93 - *p_x)) + (float)((float)v96 * (float)v96))
                     - (float)v92);
        __asm { fsel      f2, f4, f5, f0 }
        v99 = __frsqrte(_FP2);
        v100 = (float)((float)-(float)((float)((float)((float)v99
                                                     * (float)((float)((float)((float)(*v93 - *p_x)
                                                                             * (float)(*v93 - *p_x))
                                                                     + (float)((float)v96 * (float)v96))
                                                             * (float)0.5))
                                             * (float)v99)
                                     - (float)1.5)
                     * (float)v99);
        v101 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v99
                                                                                     * (float)((float)((float)((float)(*v93 - *p_x) * (float)(*v93 - *p_x)) + (float)((float)v96 * (float)v96))
                                                                                             * (float)0.5))
                                                                             * (float)v99)
                                                                     - (float)1.5)
                                                     * (float)v99)
                                             * (float)((float)((float)((float)(*v93 - *p_x) * (float)(*v93 - *p_x))
                                                             + (float)((float)v96 * (float)v96))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v99
                                                                             * (float)((float)((float)((float)(*v93 - *p_x) * (float)(*v93 - *p_x))
                                                                                             + (float)((float)v96 * (float)v96))
                                                                                     * (float)0.5))
                                                                     * (float)v99)
                                                             - (float)1.5)
                                             * (float)v99))
                             - (float)1.5);
        v102 = (float)((float)-(float)((float)((float)((float)((float)v101 * (float)v100)
                                                     * (float)((float)((float)((float)(*v93 - *p_x)
                                                                             * (float)(*v93 - *p_x))
                                                                     + (float)((float)v96 * (float)v96))
                                                             * (float)0.5))
                                             * (float)((float)v101 * (float)v100))
                                     - (float)1.5)
                     * (float)((float)v101 * (float)v100));
        v103 = (float)((float)v102
                     * (float)((float)((float)(*v93 - *p_x) * (float)(*v93 - *p_x)) + (float)((float)v96 * (float)v96)));
        v104 = (float)((float)(*v93 - *p_x) * (float)v102);
        v105 = (float)((float)(v93[1] - p_x[1]) * (float)v102);
        if ( v103 >= (float)((float)v7 * (float)2.0) )
        {
          *v93 = *v93 - (float)((float)((float)(*v93 - *p_x) * (float)v102) * (float)v7);
          v93[1] = (float)v95 - (float)((float)v105 * (float)v7);
          *p_x = (float)((float)v104 * (float)v7) + *p_x;
          p_x[1] = (float)((float)v105 * (float)v7) + p_x[1];
          v92 = idMath::FLT_SMALLEST_NON_DENORMAL;
        }
        v91 = v90 * 8;
        ++v90;
        --v89;
      }
      while ( v89 != 0 );
      v28 = v115.list;
      v26 = v113.list;
    }
  }
  if ( v123.listStatic == 0 || v123.listStatic == 2 )
  {
    if ( v123.list != nullptr )
    {
      idMem::Free(this: &mem, ptr: v123.list, align: ALIGN_16);
      v28 = v115.list;
      v26 = v113.list;
    }
    v123.list = nullptr;
    v123.size = 0;
  }
  v123.num = 0;
  if ( v121.listStatic == 0 || v121.listStatic == 2 )
  {
    if ( v121.list != nullptr )
    {
      idMem::Free(this: &mem, ptr: v121.list, align: ALIGN_16);
      v28 = v115.list;
      v26 = v113.list;
    }
    v121.list = nullptr;
    v121.size = 0;
  }
  v121.num = 0;
  if ( v113.listStatic == 0 || v113.listStatic == 2 )
  {
    if ( v26 != nullptr )
    {
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
      v28 = v115.list;
    }
    v113.list = nullptr;
    v113.size = 0;
  }
  v113.num = 0;
  if ( v119.listStatic == 0 || v119.listStatic == 2 )
  {
    if ( v119.list != nullptr )
    {
      idMem::Free(this: &mem, ptr: v119.list, align: ALIGN_16);
      v28 = v115.list;
    }
    v119.list = nullptr;
    v119.size = 0;
  }
  v119.num = 0;
  if ( v117.listStatic == 0 || v117.listStatic == 2 )
  {
    if ( v117.list != nullptr )
    {
      idMem::Free(this: &mem, ptr: v117.list, align: ALIGN_16);
      v28 = v115.list;
    }
    v117.list = nullptr;
    v117.size = 0;
  }
  v117.num = 0;
  if ( (v115.listStatic == 0 || v115.listStatic == 2) && v28 != nullptr )
    idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
}


// ========================================================================
// __unwind$220828
// EA  : 0x827B3A14
// RVA : 0x007B3A14
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220828()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 2208));
}


// ========================================================================
// __unwind$220829_0
// EA  : 0x827B3A3C
// RVA : 0x007B3A3C
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220829_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 4272));
}


// ========================================================================
// __unwind$220830_0
// EA  : 0x827B3A64
// RVA : 0x007B3A64
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220830_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 6336));
}


// ========================================================================
// __unwind$220831
// EA  : 0x827B3A8C
// RVA : 0x007B3A8C
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220831()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 144));
}


// ========================================================================
// __unwind$220832_0
// EA  : 0x827B3AB4
// RVA : 0x007B3AB4
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220832_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 8400));
}


// ========================================================================
// __unwind$220833_0
// EA  : 0x827B3ADC
// RVA : 0x007B3ADC
// PDB : w:\tech5\engine\models\cuttable\convexhull.cpp
// ========================================================================

void _unwind_220833_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 20848 + 12512));
}

