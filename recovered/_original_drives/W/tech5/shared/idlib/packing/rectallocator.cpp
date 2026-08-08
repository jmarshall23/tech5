
// ========================================================================
// ?RectPackingFraction@@YAMABV?$idList@VidVec2i@@$04@@VidVec2i@@@Z
// EA  : 0x82F798B8
// RVA : 0x00F798B8
// PDB : w:\tech5\shared\idlib\packing\rectallocator.cpp
// ========================================================================

float __fastcall RectPackingFraction(
        const idList<idVec2i,5> *inputSizes,
        const idVec2i *totalSize,
        int a3,
        int a4,
        __int64 a5)
{
  double v5; // fp1
  int num; // r31
  int v7; // r6
  int v8; // r5
  int v9; // r30
  int v10; // r9
  idVec2i *list; // r8
  int v12; // r10
  int x; // r7
  int y; // r28
  int v15; // r27
  int v16; // r11
  __int64 v17; // r10

  if ( (_DWORD)totalSize * (_DWORD)inputSizes != 0 )
  {
    num = inputSizes->num;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    if ( num >= 2 )
    {
      list = inputSizes->list;
      v12 = 0;
      do
      {
        x = list[v12].x;
        v10 += 2;
        y = list[v12].y;
        v15 = list[v12 + 1].y;
        v16 = list[v12 + 1].x;
        v12 += 2;
        HIDWORD(a5) = y * x;
        v7 += HIDWORD(a5);
        v8 += v15 * v16;
      }
      while ( v10 < num - 1 );
    }
    if ( v10 < num )
      v9 = inputSizes->list[v10].y * inputSizes->list[v10].x;
    LODWORD(v17) = (_DWORD)totalSize * (_DWORD)inputSizes;
    HIDWORD(v17) = v8 + v7 + v9;
    LODWORD(a5) = HIDWORD(v17);
    v5 = (float)((float)a5 / (float)v17);
  }
  else
  {
    v5 = 0.0;
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?RectAllocator@@YAXABV?$idList@VidVec2i@@$04@@AAV1@AAVidVec2i@@@Z
// EA  : 0x82F79E70
// RVA : 0x00F79E70
// PDB : w:\tech5\shared\idlib\packing\rectallocator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RectAllocator(
        const idList<idVec2i,5> *inputSizes,
        idList<idSkinMapping,46> *outputPositions,
        idVec2i *totalSize)
{
  int num; // r30
  const idList<idVec2i,5> *v4; // r29
  idVec2i *v6; // r28
  int size; // r11
  int v8; // r9
  int v9; // r8
  int v10; // r7
  __int64 v11; // r6
  __int64 v12; // r4
  idVehicleState *v13; // r11
  idVehicleState **list; // r15
  idVehicleState **v15; // r10
  int v16; // r19
  idVec2i *v17; // r11
  __int64 v18; // r8 OVERLAPPED
  __int64 v19; // r6
  int v20; // r22
  idVec2i *v21; // r27
  int v22; // r21
  __int64 v23; // r10 OVERLAPPED
  idVec2i *v24; // r17
  int v25; // ctr
  int x; // r20
  int y; // r16
  int v28; // r28
  int v29; // r11
  int v30; // r26
  int v31; // r25
  int v32; // r24
  int v33; // r23
  int v34; // r30
  int v35; // r11
  signed int v36; // r11
  int v37; // r11
  int v38; // r11
  int v39; // r11
  int v40; // r10
  int v41; // r9
  int v42; // r8
  int v43; // r7
  int v44; // r6
  int v45; // r5
  int v46; // r4
  int v47; // r3
  __int64 v48; // [sp+8h] [-138h]
  int v49; // [sp+10h] [-130h]
  int v50; // [sp+14h] [-12Ch]
  unsigned int *v51; // [sp+50h] [-F0h]
  unsigned int v52; // [sp+54h] [-ECh]
  __int64 v53; // [sp+58h] [-E8h]
  int v54; // [sp+64h] [-DCh]
  idSort_Quick<int,idSortrects> v55[2]; // [sp+68h] [-D8h] BYREF
  __int64 v56; // [sp+70h] [-D0h]
  signed int v57; // [sp+78h] [-C8h]
  int v58; // [sp+7Ch] [-C4h]
  __int64 v59; // [sp+80h] [-C0h]
  idList<idVehicleState *,5> v60[11]; // [sp+90h] [-B0h] BYREF

  num = inputSizes->num;
  v4 = inputSizes;
  v6 = totalSize;
  if ( num <= outputPositions->size
    || (unsigned __int8)idList<idDeclMD6::includeDecl_t,5>::Resize(this: outputPositions, newsize: num) != 0 )
  {
    size = outputPositions->size;
    if ( num < size )
      size = num;
    outputPositions->num = size;
  }
  if ( v4->num != 0 )
  {
    memset(v60, 0, 14);
    v60[0].listStatic = 0;
    v60[0].memTag = 5;
    idList<idThread *,58>::Clear(this: v60);
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)v60, newNum: v4->num);
    v13 = nullptr;
    list = v60[0].list;
    if ( v4->num > 0 )
    {
      v15 = v60[0].list - 1;
      do
      {
        *++v15 = v13;
        v13 = (idVehicleState *)((char *)v13 + 1);
        v8 = v4->num;
      }
      while ( (int)v13 < v8 );
    }
    v55[0].__vftable = (idSort_Quick<int,idSortrects>_vtbl *)&idSortrects::`vftable';
    v55[1].__vftable = (idSort_Quick<int,idSortrects>_vtbl *)v4;
    if ( list != nullptr )
    {
      HIDWORD(v11) = v60[0].num;
      idSort_Quick<int,idSortrects>::Sort(this: v55, num: v11, a3: v10, a4: v9, a5: v8, a6: v48);
    }
    v16 = 1;
    v17 = (idVec2i *)&outputPositions->list[(_DWORD)*list];
    v17->x = 0;
    v17->y = 0;
    LODWORD(v18) = &v4->list[(_DWORD)*list];
    HIDWORD(v18) = *(_DWORD *)v18;
    v6->x = *(_DWORD *)v18;
    LODWORD(v19) = *(_DWORD *)(v18 + 4);
    v6->y = v19;
    HIDWORD(v19) = v4->num;
    if ( SHIDWORD(v19) <= 1 )
    {
LABEL_41:
      v55[0].__vftable = (idSort_Quick<int,idSortrects>_vtbl *)&idSort<int>::`vftable';
      if ( v60[0].listStatic == 0 || v60[0].listStatic == 2 )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    else
    {
      v51 = (unsigned int *)(list + 1);
      while ( 1 )
      {
        v20 = 0x4000;
        v21 = v4->list;
        v22 = 0x4000;
        v53 = 0;
        LODWORD(v23) = *v51;
        v52 = *v51;
        v54 = 0x4000;
        *(__int64 *)((char *)&v18 - 4) = (__int64)v4->list[v52];
        v56 = *(__int64 *)((char *)&v18 - 4);
        if ( v16 <= 0 )
          break;
        v24 = (idVec2i *)outputPositions->list;
        v25 = v16;
        x = v6->x;
        y = v6->y;
        do
        {
          v28 = 1;
          v29 = (int)*list;
          v30 = v21[v29].x;
          v31 = v24[v29].x;
          v32 = v21[v29].y;
          v33 = v24[v29].y;
          do
          {
            HIDWORD(v23) = (v28 >> 1) & 1;
            HIDWORD(v12) = (v28 & 1) * v30 + v31;
            HIDWORD(v59) = HIDWORD(v12);
            v34 = HIDWORD(v23) * v32 + v33;
            LODWORD(v12) = HIDWORD(v56) + HIDWORD(v12);
            LODWORD(v59) = v34;
            v35 = x;
            if ( x <= HIDWORD(v56) + HIDWORD(v12) )
              v35 = HIDWORD(v56) + HIDWORD(v12);
            LODWORD(v23) = y;
            if ( y <= (int)v56 + v34 )
              LODWORD(v23) = v56 + v34;
            v58 = v23;
            v36 = (v35 + 31) & 0xFFFFFFE0;
            v57 = v36;
            if ( v36 <= 1024 && (int)v23 <= 1024 )
            {
              LODWORD(v18) = v22 * v22;
              HIDWORD(v23) = v20 * v20;
              v37 = v23 * v23 + v36 * v36;
              LODWORD(v23) = v22 * v22 + v20 * v20;
              if ( v37 <= (int)v23 )
              {
                if ( v37 != (_DWORD)v23
                  || (LODWORD(v23) = v34 + HIDWORD(v12),
                      HIDWORD(v23) = HIDWORD(v53),
                      LODWORD(v18) = v53 + HIDWORD(v53),
                      (int)v53 + HIDWORD(v53) >= v34 + HIDWORD(v12)) )
                {
                  v19 = (unsigned int)outputPositions->list;
                  LODWORD(v18) = v60[0].list;
                  while ( 1 )
                  {
                    v38 = 8 * *(_DWORD *)v18;
                    LODWORD(v23) = v38 + v19;
                    HIDWORD(v23) = &v21[v38 / 8u];
                    v39 = *(_DWORD *)(v38 + v19);
                    if ( (int)v12 > v39 )
                    {
                      HIDWORD(v18) = *(_DWORD *)(v23 + 4);
                      if ( (int)v56 + v34 > SHIDWORD(v18) )
                      {
                        LODWORD(v23) = *(_DWORD *)HIDWORD(v23);
                        if ( SHIDWORD(v12) < v39 + *(_DWORD *)HIDWORD(v23)
                          && v34 < *(_DWORD *)(HIDWORD(v23) + 4) + HIDWORD(v18) )
                        {
                          break;
                        }
                      }
                    }
                    ++HIDWORD(v19);
                    LODWORD(v18) = v18 + 4;
                    if ( SHIDWORD(v19) >= v16 )
                      goto LABEL_36;
                  }
                  if ( SHIDWORD(v19) < v16 )
                    goto LABEL_37;
LABEL_36:
                  v23 = v59;
                  v54 = v58;
                  v22 = v58;
                  v53 = v59;
                  v20 = v59;
                }
              }
            }
LABEL_37:
            ++v28;
          }
          while ( v28 < 4 );
          ++list;
          --v25;
        }
        while ( v25 != 0 );
        if ( v20 == 0x4000 )
          break;
        ++v16;
        HIDWORD(v18) = totalSize;
        v19 = __PAIR64__((unsigned int)v51, (unsigned int)inputSizes);
        outputPositions->list[v52] = (idSkinMapping)__PAIR64__(v52 * 8, v53);
        LODWORD(v12) = v51 + 1;
        list = v60[0].list;
        *totalSize = (idVec2i)__PAIR64__((unsigned int)totalSize, v54);
        ++v51;
        if ( v16 >= inputSizes->num )
          goto LABEL_41;
        v4 = inputSizes;
        v6 = totalSize;
      }
      HIDWORD(v12) = "RectAllocator: couldn't fit everything";
      idLib::FatalError(fmt: v12, a2: v19, a3: v18, a4: v23, a5: SHIDWORD(v48), a6: v48, a7: v49, a8: v50);
      _LN206_1(a1: v47, a2: v46, a3: v45, a4: v44, a5: v43, a6: v42, a7: v41, a8: v40);
    }
  }
  else
  {
    v6->x = 0;
    v6->y = 0;
  }
}


// ========================================================================
// $LN206_1
// EA  : 0x82F7A224
// RVA : 0x00F7A224
// PDB : w:\tech5\shared\idlib\packing\rectallocator.cpp
// ========================================================================

void _LN206_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$112163
// EA  : 0x82F7A24C
// RVA : 0x00F7A24C
// PDB : w:\tech5\shared\idlib\packing\rectallocator.cpp
// ========================================================================

void _unwind_112163()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 320 + 104));
}

