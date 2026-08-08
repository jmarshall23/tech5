
// ========================================================================
// win32munmap
// EA  : 0x83294B88
// RVA : 0x01294B88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

int __fastcall win32munmap(char *ptr, unsigned int size)
{
  unsigned int v3; // r30
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v10; // [sp+8h] [-88h]
  int v11; // [sp+Ch] [-84h]
  int v12; // [sp+10h] [-80h]
  void *v13; // [sp+14h] [-7Ch]
  int v14; // [sp+18h] [-78h]
  unsigned int v15; // [sp+1Ch] [-74h]
  _MEMORY_BASIC_INFORMATION v16; // [sp+50h] [-40h] BYREF

  v3 = size;
  if ( size == 0 )
    return 0;
  while ( VirtualQuery(lpAddress: ptr, lpBuffer: &v16, dwLength: 0x1Cu) != 0
       && v16.BaseAddress == ptr
       && v16.AllocationBase == ptr
       && v16.State == 4096
       && v16.RegionSize <= v3
       && VirtualFree(
            lpAddress: ptr,
            dwSize: 0,
            dwFreeType: 0x8000,
            a4: v8,
            a5: v7,
            a6: v6,
            a7: v5,
            a8: v4,
            a9: v10,
            a10: v11,
            a11: v12,
            a12: v13,
            a13: v14,
            a14: v15) != 0 )
  {
    v3 -= v16.RegionSize;
    ptr += v16.RegionSize;
    if ( v3 == 0 )
      return 0;
  }
  return -1;
}


// ========================================================================
// internal_mallinfo
// EA  : 0x83294C48
// RVA : 0x01294C48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

bfx::mallinfo *__fastcall internal_mallinfo(bfx::mallinfo *result, malloc_state *m)
{
  malloc_chunk *top; // r27
  unsigned int topsize; // r28
  malloc_segment *p_seg; // r31
  unsigned int v5; // r30
  unsigned int v6; // r7
  unsigned int v7; // r6
  char *base; // r8
  int v9; // r11
  int v10; // r11
  unsigned int i; // r11
  int v12; // r9
  unsigned int footprint; // r11
  unsigned int max_footprint; // r10

  top = m->top;
  result->arena = 0;
  result->ordblks = 0;
  result->smblks = 0;
  result->hblks = 0;
  result->hblkhd = 0;
  result->usmblks = 0;
  result->fsmblks = 0;
  result->uordblks = 0;
  result->fordblks = 0;
  result->keepcost = 0;
  if ( top != nullptr )
  {
    topsize = m->topsize;
    p_seg = &m->seg;
    v5 = 1;
    v6 = topsize + 40;
    v7 = topsize + 40;
    if ( m != (malloc_state *)-440 )
    {
      do
      {
        base = p_seg->base;
        v9 = (int)p_seg->base & 7;
        if ( v9 != 0 )
          v10 = -v9 & 7;
        else
          v10 = 0;
        for ( i = (unsigned int)&base[v10]; i >= (unsigned int)base; i += v12 & 0xFFFFFFFC )
        {
          if ( i >= (unsigned int)&base[p_seg->size] )
            break;
          if ( (malloc_chunk *)i == top )
            break;
          v12 = *(_DWORD *)(i + 4);
          if ( v12 == 7 )
            break;
          v7 += v12 & 0xFFFFFFFC;
          if ( (v12 & 2) == 0 )
          {
            v6 += v12 & 0xFFFFFFFC;
            ++v5;
          }
        }
        p_seg = p_seg->next;
      }
      while ( p_seg != nullptr );
    }
    footprint = m->footprint;
    max_footprint = m->max_footprint;
    result->arena = v7;
    result->ordblks = v5;
    result->hblkhd = footprint - v7;
    result->uordblks = footprint - v6;
    result->usmblks = max_footprint;
    result->fordblks = v6;
    result->keepcost = topsize;
  }
  return result;
}


// ========================================================================
// mmap_alloc
// EA  : 0x83294D60
// RVA : 0x01294D60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

char *__fastcall mmap_alloc(malloc_state *m, unsigned int nb, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int granularity; // r11
  unsigned int v9; // r11
  int v10; // r10
  unsigned int v11; // r30
  char *v12; // r3
  int v13; // r11
  char *v14; // r10
  char *v15; // r8
  unsigned int max_footprint; // r9
  unsigned int v17; // r11
  int v19; // [sp+8h] [-68h]
  int v20; // [sp+Ch] [-64h]
  int v21; // [sp+10h] [-60h]
  void *v22; // [sp+14h] [-5Ch]
  int v23; // [sp+18h] [-58h]
  SIZE_T v24; // [sp+1Ch] [-54h]

  granularity = m->m_params.granularity;
  v10 = granularity + nb + 31;
  v9 = granularity - 1;
  v11 = v10 & ~v9;
  if ( v11 <= nb )
    return nullptr;
  v12 = (char *)VirtualAlloc(
                  lpAddress: nullptr,
                  dwSize: v10 & ~v9,
                  flAllocationType: 0x103000u,
                  flProtect: 4u,
                  a5,
                  a6,
                  a7,
                  a8: v10,
                  a9: v19,
                  a10: v20,
                  a11: v21,
                  a12: v22,
                  a13: v23,
                  a14: v24);
  if ( v12 == nullptr || v12 == (char *)-1 )
    return nullptr;
  v13 = (unsigned __int8)v12 & 7;
  if ( ((unsigned __int8)v12 & 7) != 0 )
    v13 = -v13 & 7;
  v14 = &v12[v13];
  v15 = &v12[v11 - 16];
  *(_DWORD *)&v12[v13] = v13 | 1;
  *(_DWORD *)&v12[v13 + 4] = (v11 - v13 - 16) | 2;
  *((_DWORD *)v15 + 1) = 7;
  *((_DWORD *)v15 + 2) = 0;
  if ( v12 < m->least_addr )
    m->least_addr = v12;
  max_footprint = m->max_footprint;
  v17 = v11 + m->footprint;
  m->footprint = v17;
  if ( v17 > max_footprint )
    m->max_footprint = v17;
  return v14 + 8;
}


// ========================================================================
// prepend_alloc
// EA  : 0x83294E50
// RVA : 0x01294E50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

char *__fastcall prepend_alloc(malloc_state *m, char *newbase, char *oldbase, unsigned int nb)
{
  int v5; // r10
  char *v6; // r30
  int v7; // r11
  malloc_chunk *v8; // r11
  malloc_chunk *v9; // r8
  unsigned int v10; // r5
  unsigned int topsize; // r11
  char *result; // r3
  unsigned int v13; // r11
  unsigned int dvsize; // r11
  unsigned int v15; // r11
  unsigned int head; // r10
  unsigned int v17; // r7
  unsigned int v18; // r4
  malloc_chunk *fd; // r10
  malloc_chunk *bk; // r9
  malloc_chunk *prev_foot; // r10
  malloc_chunk *v22; // r6
  malloc_chunk *v23; // r9
  malloc_chunk *v24; // r7
  malloc_chunk *v25; // r9
  int v26; // r9
  unsigned int v27; // r9
  unsigned int v28; // r9
  unsigned int v29; // r10
  int v30; // r10
  char *v31; // r11
  malloc_chunk *v32; // r11
  malloc_chunk *v33; // r7
  unsigned int v34; // r11
  unsigned int v35; // r11
  unsigned int v36; // r9
  unsigned int v37; // r10
  unsigned int v38; // r11
  unsigned int v39; // r11
  malloc_tree_chunk **v40; // r7
  unsigned int treemap; // r9
  malloc_chunk *v42; // r10
  char v43; // r11
  unsigned int v44; // r9
  unsigned int v45; // r11
  int v46; // r7
  int v47; // r11
  malloc_chunk *v48; // r11

  if ( ((unsigned __int8)newbase & 7) != 0 )
    v5 = -((unsigned __int8)newbase & 7) & 7;
  else
    v5 = 0;
  v6 = &newbase[v5];
  if ( ((unsigned __int8)oldbase & 7) != 0 )
    v7 = -((unsigned __int8)oldbase & 7) & 7;
  else
    v7 = 0;
  v8 = (malloc_chunk *)&oldbase[v7];
  *((_DWORD *)v6 + 1) = nb | 3;
  v9 = (malloc_chunk *)&v6[nb];
  v10 = (char *)v8 - v6 - nb;
  if ( v8 == m->top )
  {
    topsize = m->topsize;
    m->top = v9;
    v13 = v10 + topsize;
    m->topsize = v13;
    v9->head = v13 | 1;
    return v6 + 8;
  }
  if ( v8 == m->dv )
  {
    dvsize = m->dvsize;
    m->dv = v9;
    v15 = dvsize + v10;
    m->dvsize = v15;
    v9->head = v15 | 1;
    *(unsigned int *)((char *)&v9->prev_foot + v15) = v15;
    return v6 + 8;
  }
  head = v8->head;
  if ( (head & 2) == 0 )
  {
    v17 = head >> 3;
    v18 = head & 0xFFFFFFFC;
    if ( head >> 3 < 0x20 )
    {
      fd = v8->fd;
      bk = v8->bk;
      if ( fd == bk )
      {
        m->smallmap &= ~(1 << v17);
      }
      else
      {
        fd->bk = bk;
        bk->fd = fd;
      }
      goto LABEL_36;
    }
    prev_foot = v8->bk;
    v22 = v8[1].fd;
    if ( prev_foot == v8 )
    {
      prev_foot = (malloc_chunk *)v8[1].head;
      v24 = (malloc_chunk *)((char *)v8 + 20);
      if ( prev_foot != nullptr || (prev_foot = (malloc_chunk *)v8[1].prev_foot, v24 = v8 + 1, prev_foot != nullptr) )
      {
        while ( 1 )
        {
          v25 = (malloc_chunk *)((char *)prev_foot + 20);
          if ( prev_foot[1].head == 0 )
          {
            v25 = prev_foot + 1;
            if ( prev_foot[1].prev_foot == 0 )
              break;
          }
          prev_foot = (malloc_chunk *)v25->prev_foot;
          v24 = v25;
        }
        v24->prev_foot = 0;
      }
    }
    else
    {
      v23 = v8->fd;
      v23->bk = prev_foot;
      prev_foot->fd = v23;
    }
    if ( v22 == nullptr )
      goto LABEL_36;
    v26 = 4 * ((int)&v8[1].bk[4].fd + 3);
    if ( v8 == *(malloc_chunk **)((char *)&m->smallmap + v26) )
    {
      *(unsigned int *)((char *)&m->smallmap + v26) = (unsigned int)prev_foot;
      if ( prev_foot == nullptr )
      {
        m->treemap &= ~(1 << (int)v8[1].bk);
LABEL_36:
        v8 = (malloc_chunk *)((char *)v8 + v18);
        v10 += v18;
        goto LABEL_37;
      }
    }
    else
    {
      if ( (malloc_chunk *)v22[1].prev_foot == v8 )
        v22[1].prev_foot = (unsigned int)prev_foot;
      else
        v22[1].head = (unsigned int)prev_foot;
      if ( prev_foot == nullptr )
        goto LABEL_36;
    }
    prev_foot[1].fd = v22;
    v27 = v8[1].prev_foot;
    if ( v27 != 0 )
    {
      prev_foot[1].prev_foot = v27;
      *(_DWORD *)(v27 + 24) = prev_foot;
    }
    v28 = v8[1].head;
    if ( v28 != 0 )
    {
      prev_foot[1].head = v28;
      *(_DWORD *)(v28 + 24) = prev_foot;
    }
    goto LABEL_36;
  }
LABEL_37:
  v29 = v10 >> 3;
  v8->head &= ~1u;
  v9->head = v10 | 1;
  *(unsigned int *)((char *)&v9->prev_foot + v10) = v10;
  if ( v10 >> 3 >= 0x20 )
  {
    v34 = v10 >> 8;
    if ( v10 >> 8 != 0 )
    {
      if ( v34 <= 0xFFFF )
      {
        v36 = ((v34 - 256) >> 16) & 8;
        v37 = v34 << v36;
        v38 = (((v34 << v36) - 4096) >> 16) & 4;
        v39 = (v37 << v38 << ((((v37 << v38) - 0x4000) >> 16) & 2) >> 15)
            - ((((v37 << v38) - 0x4000) >> 16) & 2)
            - (v38
             + v36)
            + 14;
        v35 = ((v10 >> (v39 + 7)) & 1) + 2 * v39;
      }
      else
      {
        v35 = 31;
      }
    }
    else
    {
      v35 = 0;
    }
    v9[1].bk = (malloc_chunk *)v35;
    v9[1].head = 0;
    v9[1].prev_foot = 0;
    v40 = &m->treebins[v35];
    treemap = m->treemap;
    if ( ((1 << v35) & treemap) != 0 )
    {
      v42 = (malloc_chunk *)*v40;
      if ( v35 == 31 )
        v43 = 0;
      else
        v43 = 25 - (v35 >> 1);
      v44 = v10 << v43;
      if ( (v42->head & 0xFFFFFFFC) == v10 )
      {
LABEL_55:
        v48 = v42->fd;
        v48->bk = v9;
        v42->fd = v9;
        v9->fd = v48;
        v9->bk = v42;
        v9[1].fd = nullptr;
        return v6 + 8;
      }
      else
      {
        while ( 1 )
        {
          __SET_PAIR__(v45, v44, 2LL * v44);
          v46 = 4 * (v45 + 4);
          v47 = *(unsigned int *)((char *)&v42->prev_foot + v46);
          if ( v47 == 0 )
            break;
          v42 = *(malloc_chunk **)((char *)&v42->prev_foot + v46);
          if ( (*(_DWORD *)(v47 + 4) & 0xFFFFFFFC) == v10 )
            goto LABEL_55;
        }
        *(unsigned int *)((char *)&v42->prev_foot + v46) = (unsigned int)v9;
        v9[1].fd = v42;
        v9->bk = v9;
        v9->fd = v9;
        return v6 + 8;
      }
    }
    else
    {
      m->treemap = (1 << v35) | treemap;
      *v40 = (malloc_tree_chunk *)v9;
      v9[1].fd = (malloc_chunk *)v40;
      v9->bk = v9;
      v9->fd = v9;
      return v6 + 8;
    }
  }
  else
  {
    v31 = (char *)m + 8 * v29;
    v30 = 1 << v29;
    v32 = (malloc_chunk *)(v31 + 36);
    if ( (v30 & m->smallmap) != 0 )
    {
      v33 = v32->fd;
      result = v6 + 8;
      v32->fd = v9;
      v33->bk = v9;
      v9->fd = v33;
    }
    else
    {
      result = v6 + 8;
      m->smallmap |= v30;
      v32->fd = v9;
      v32->bk = v9;
      v9->fd = v32;
    }
    v9->bk = v32;
  }
  return result;
}


// ========================================================================
// add_segment
// EA  : 0x83295248
// RVA : 0x01295248
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

void __fastcall add_segment(malloc_state *m, char *tbase, unsigned int tsize, unsigned int mmapped)
{
  malloc_segment *p_seg; // r10
  malloc_chunk *top; // r31
  malloc_segment *v6; // r11
  unsigned int v7; // r29
  int v8; // r11
  int v9; // r11
  malloc_chunk *v10; // r11
  int v11; // r9
  malloc_chunk *v12; // r9
  unsigned int v13; // r8
  char *p_bk; // r7
  malloc_chunk *v15; // r9
  char *v16; // r10
  unsigned int v17; // r8
  unsigned int v18; // r11
  int v19; // r9
  malloc_chunk **v20; // r11
  unsigned int v21; // r6
  malloc_chunk *v22; // r8
  unsigned int v23; // r11
  unsigned int v24; // r11
  unsigned int v25; // r10
  unsigned int v26; // r11
  unsigned int v27; // r9
  unsigned int v28; // r11
  malloc_tree_chunk **v29; // r7
  unsigned int treemap; // r9
  malloc_chunk *v31; // r10
  char v32; // r11
  unsigned int v33; // r9
  unsigned int v34; // r11
  int v35; // r7
  int v36; // r11
  malloc_chunk *fd; // r11

  p_seg = &m->seg;
  top = m->top;
  v6 = &m->seg;
  while ( (char *)top < v6->base || (char *)top >= &v6->base[v6->size] )
  {
    v6 = v6->next;
    if ( v6 == nullptr )
    {
      v6 = nullptr;
      break;
    }
  }
  v7 = (unsigned int)&v6->base[v6->size];
  v8 = (v7 - 47) & 7;
  if ( v8 != 0 )
    v9 = -v8 & 7;
  else
    v9 = 0;
  v10 = (malloc_chunk *)(v9 + v7 - 47);
  if ( v10 < &top[1] )
    v10 = m->top;
  v11 = ((unsigned __int8)tbase & 7) == 0 ? 0 : -((unsigned __int8)tbase & 7) & 7;
  v13 = tsize - v11 - 40;
  v12 = (malloc_chunk *)&tbase[v11];
  m->top = v12;
  p_bk = (char *)&v10[1].bk;
  m->topsize = v13;
  v12->head = v13 | 1;
  *(unsigned int *)((char *)&v12->head + v13) = 40;
  v15 = v10 + 2;
  m->trim_check = m->m_params.trim_threshold;
  v10->head = 27;
  v10->fd = (malloc_chunk *)p_seg->base;
  v10->bk = (malloc_chunk *)m->seg.size;
  v10[1].prev_foot = (unsigned int)m->seg.next;
  v10[1].head = m->seg.sflags;
  p_seg->base = tbase;
  m->seg.size = tsize;
  m->seg.sflags = mmapped;
  m->seg.next = (malloc_segment *)&v10->fd;
  for ( v10[1].bk = (malloc_chunk *)7; (unsigned int)v15 < v7; *((_DWORD *)v16 + 1) = 7 )
  {
    v16 = p_bk;
    p_bk = (char *)v15;
    v15 = (malloc_chunk *)((char *)v15 + 4);
  }
  if ( v10 != top )
  {
    v17 = (char *)v10 - (char *)top;
    v10->head &= ~1u;
    top->head = ((char *)v10 - (char *)top) | 1;
    v10->prev_foot = (char *)v10 - (char *)top;
    v18 = (unsigned int)((char *)v10 - (char *)top) >> 3;
    if ( v18 >= 0x20 )
    {
      v23 = v17 >> 8;
      if ( v17 >> 8 != 0 )
      {
        if ( v23 <= 0xFFFF )
        {
          v25 = ((v23 - 256) >> 16) & 8;
          v26 = v23 << v25;
          v27 = ((v26 - 4096) >> 16) & 4;
          v28 = v26 << v27;
          v24 = ((v17 >> ((v28 << (((v28 - 0x4000) >> 16) & 2) >> 15) - (((v28 - 0x4000) >> 16) & 2) - (v27 + v25) + 21))
               & 1)
              + 2 * ((v28 << (((v28 - 0x4000) >> 16) & 2) >> 15) - (((v28 - 0x4000) >> 16) & 2) - (v27 + v25) + 14);
        }
        else
        {
          v24 = 31;
        }
      }
      else
      {
        v24 = 0;
      }
      top[1].bk = (malloc_chunk *)v24;
      top[1].head = 0;
      top[1].prev_foot = 0;
      v29 = &m->treebins[v24];
      treemap = m->treemap;
      if ( (treemap & (1 << v24)) != 0 )
      {
        v31 = (malloc_chunk *)*v29;
        if ( v24 == 31 )
          v32 = 0;
        else
          v32 = 25 - (v24 >> 1);
        v33 = v17 << v32;
        if ( (v31->head & 0xFFFFFFFC) == v17 )
        {
LABEL_32:
          fd = v31->fd;
          fd->bk = top;
          v31->fd = top;
          top->fd = fd;
          top->bk = v31;
          top[1].fd = nullptr;
        }
        else
        {
          while ( 1 )
          {
            __SET_PAIR__(v34, v33, 2LL * v33);
            v35 = 4 * (v34 + 4);
            v36 = *(unsigned int *)((char *)&v31->prev_foot + v35);
            if ( v36 == 0 )
              break;
            v31 = *(malloc_chunk **)((char *)&v31->prev_foot + v35);
            if ( (*(_DWORD *)(v36 + 4) & 0xFFFFFFFC) == v17 )
              goto LABEL_32;
          }
          *(unsigned int *)((char *)&v31->prev_foot + v35) = (unsigned int)top;
          top[1].fd = v31;
          top->bk = top;
          top->fd = top;
        }
      }
      else
      {
        m->treemap = treemap | (1 << v24);
        *v29 = (malloc_tree_chunk *)top;
        top[1].fd = (malloc_chunk *)v29;
        top->bk = top;
        top->fd = top;
      }
    }
    else
    {
      v19 = 1 << v18;
      v21 = m->smallmap & (1 << v18);
      v20 = &m->smallbins[2 * v18];
      if ( v21 != 0 )
      {
        v22 = v20[2];
        v20[2] = top;
        v22->bk = top;
        top->fd = v22;
      }
      else
      {
        m->smallmap |= v19;
        v20[2] = top;
        v20[3] = top;
        top->fd = (malloc_chunk *)v20;
      }
      top->bk = (malloc_chunk *)v20;
    }
  }
}


// ========================================================================
// sys_alloc
// EA  : 0x83295560
// RVA : 0x01295560
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

char *__fastcall sys_alloc(malloc_state *m, unsigned int nb, int a3, int a4, int a5, int a6)
{
  malloc_params *p_m_params; // r29
  int v9; // r9
  unsigned int *p_sflags; // r11
  int i; // ctr
  unsigned int magic; // r11
  char *result; // r3
  unsigned int granularity; // r11
  unsigned int v15; // r11
  int v16; // r10
  unsigned int v17; // r30
  char *v18; // r3
  unsigned int max_footprint; // r10
  unsigned int v20; // r11
  malloc_chunk *top; // r5
  unsigned int v22; // r9
  malloc_chunk **smallbins; // r11
  int j; // ctr
  char *v25; // r11
  int v26; // r10
  char *v27; // r8
  malloc_chunk *v28; // r10
  unsigned int v29; // r11
  malloc_segment *p_seg; // r11
  unsigned int size; // r10
  char *v32; // r8
  malloc_segment *v33; // r11
  char *base; // r5
  unsigned int topsize; // r10
  malloc_chunk *v36; // r11
  int v37; // r10
  malloc_chunk *v38; // r11
  unsigned int v39; // r10
  unsigned int v40; // r10
  int v41; // [sp+8h] [-78h]
  int v42; // [sp+Ch] [-74h]
  int v43; // [sp+10h] [-70h]
  void *v44; // [sp+14h] [-6Ch]
  int v45; // [sp+18h] [-68h]
  SIZE_T v46; // [sp+1Ch] [-64h]

  p_m_params = &m->m_params;
  v9 = 0;
  p_sflags = &m->seg.sflags;
  for ( i = 6; i != 0; --i )
    *++p_sflags = 0;
  if ( m->m_params.page_size == 0 )
  {
    magic = p_m_params->magic;
    v9 = 0x200000;
    a6 = 5;
    m->m_params.mmap_threshold = 0x40000;
    m->m_params.trim_threshold = 0x200000;
    m->m_params.default_mflags = 5;
    if ( magic == 0 )
      p_m_params->magic = 1482184792;
    m->m_params.page_size = 0x10000;
    m->m_params.granularity = 0x10000;
  }
  if ( (m->mflags & 1) == 0
    || nb < m->m_params.mmap_threshold
    || (result = mmap_alloc(m, nb, a3, a4, a5, a6, a7: v9)) == nullptr )
  {
    granularity = m->m_params.granularity;
    v16 = granularity + nb + 41;
    v15 = granularity - 1;
    v17 = v16 & ~v15;
    if ( v17 > nb )
    {
      v18 = (char *)VirtualAlloc(
                      lpAddress: nullptr,
                      dwSize: v16 & ~v15,
                      flAllocationType: 0x3000u,
                      flProtect: 4u,
                      a5,
                      a6,
                      a7: v9,
                      a8: v16,
                      a9: v41,
                      a10: v42,
                      a11: v43,
                      a12: v44,
                      a13: v45,
                      a14: v46);
      if ( v18 != nullptr && v18 != (char *)-1 )
      {
        max_footprint = m->max_footprint;
        v20 = m->footprint + v17;
        m->footprint = v20;
        if ( v20 > max_footprint )
          m->max_footprint = v20;
        top = m->top;
        if ( top != nullptr )
        {
          p_seg = &m->seg;
          if ( m == (malloc_state *)-440 )
            goto LABEL_22;
          while ( 1 )
          {
            size = p_seg->size;
            v32 = &p_seg->base[size];
            if ( v18 == v32 )
              break;
            p_seg = p_seg->next;
            if ( p_seg == nullptr )
              goto LABEL_22;
          }
          if ( (p_seg->sflags & 8) != 0
            || (p_seg->sflags & 1) != 1
            || (char *)top < p_seg->base
            || top >= (malloc_chunk *)v32 )
          {
LABEL_22:
            if ( v18 < m->least_addr )
              m->least_addr = v18;
            v33 = &m->seg;
            if ( m != (malloc_state *)-440 )
            {
              while ( 1 )
              {
                base = v33->base;
                if ( v33->base == &v18[v17] )
                  break;
                v33 = v33->next;
                if ( v33 == nullptr )
                  goto LABEL_27;
              }
              if ( (v33->sflags & 8) == 0 && (v33->sflags & 1) == 1 )
              {
                v40 = v33->size;
                v33->base = v18;
                v33->size = v40 + v17;
                return prepend_alloc(m, newbase: v18, oldbase: base, nb);
              }
            }
LABEL_27:
            add_segment(m, tbase: v18, tsize: v17, mmapped: 1u);
          }
          else
          {
            p_seg->size = size + v17;
            v37 = ((int)m->top & 7) == 0 ? 0 : -((int)m->top & 7) & 7;
            v38 = (malloc_chunk *)((char *)m->top + v37);
            v39 = v17 - v37 + m->topsize;
            m->top = v38;
            m->topsize = v39;
            v38->head = v39 | 1;
            *(unsigned int *)((char *)&v38->head + v39) = 40;
            m->trim_check = m->m_params.trim_threshold;
          }
        }
        else
        {
          v22 = p_m_params->magic;
          m->least_addr = v18;
          m->seg.base = v18;
          smallbins = m->smallbins;
          m->seg.size = v17;
          m->seg.sflags = 1;
          m->magic = v22;
          for ( j = 32; j != 0; --j )
          {
            smallbins[3] = (malloc_chunk *)smallbins;
            smallbins[2] = (malloc_chunk *)smallbins;
            smallbins += 2;
          }
          v25 = (char *)m + (m[-1].m_params.default_mflags & 0xFFFFFFFC) - 8;
          v26 = ((unsigned __int8)v25 & 7) == 0 ? 0 : -((unsigned __int8)v25 & 7) & 7;
          v27 = &v18[-v26];
          v28 = (malloc_chunk *)&v25[v26];
          m->top = v28;
          v29 = v27 - v25 + v17 - 40;
          m->topsize = v29;
          v28->head = v29 | 1;
          *(unsigned int *)((char *)&v28->head + v29) = 40;
          m->trim_check = m->m_params.trim_threshold;
        }
        topsize = m->topsize;
        if ( nb < topsize )
        {
          v36 = m->top;
          m->topsize = topsize - nb;
          m->top = (malloc_chunk *)((char *)v36 + nb);
          *(unsigned int *)((char *)&v36->head + nb) = (topsize - nb) | 1;
          v36->head = nb | 3;
          return (char *)&v36->fd;
        }
      }
    }
    return nullptr;
  }
  return result;
}


// ========================================================================
// release_unused_segments
// EA  : 0x83295898
// RVA : 0x01295898
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

int __fastcall release_unused_segments(malloc_state *m)
{
  malloc_segment *next; // r26
  malloc_segment *p_seg; // r28
  int v4; // r22
  unsigned int sflags; // r11
  char *base; // r3
  unsigned int size; // r30
  malloc_segment *v8; // r24
  int v9; // r11
  malloc_chunk *v10; // r31
  int v11; // r11
  unsigned int v12; // r29
  malloc_chunk *bk; // r11
  malloc_chunk *fd; // r8
  malloc_chunk *v15; // r10
  malloc_chunk *v16; // r9
  malloc_chunk *v17; // r10
  int v18; // r10
  unsigned int prev_foot; // r10
  unsigned int head; // r10
  unsigned int v21; // r11
  unsigned int v22; // r11
  unsigned int v23; // r10
  unsigned int v24; // r11
  unsigned int v25; // r9
  unsigned int v26; // r4
  malloc_tree_chunk **v27; // r8
  unsigned int treemap; // r9
  malloc_chunk *v29; // r10
  char v30; // r11
  unsigned int v31; // r9
  unsigned int v32; // r11
  int v33; // r8
  int v34; // r11
  malloc_chunk *v35; // r11

  next = m->seg.next;
  p_seg = &m->seg;
  v4 = 0;
  if ( next != nullptr )
  {
    while ( 1 )
    {
      sflags = next->sflags;
      base = next->base;
      size = next->size;
      v8 = next->next;
      if ( (sflags & 1) != 0 && (sflags & 8) == 0 )
      {
        v9 = ((unsigned __int8)base & 7) != 0 ? -((int)next->base & 7) & 7 : 0;
        v10 = (malloc_chunk *)&base[v9];
        v11 = *(_DWORD *)&base[v9 + 4];
        v12 = v11 & 0xFFFFFFFC;
        if ( (v11 & 2) == 0 && (char *)v10 + v12 >= &base[size - 40] )
          break;
      }
LABEL_47:
      p_seg = next;
      next = v8;
      if ( v8 == nullptr )
        return v4;
    }
    if ( v10 == m->dv )
    {
      m->dv = nullptr;
      m->dvsize = 0;
      goto LABEL_31;
    }
    bk = v10->bk;
    fd = v10[1].fd;
    if ( bk == v10 )
    {
      bk = (malloc_chunk *)v10[1].head;
      v16 = (malloc_chunk *)((char *)v10 + 20);
      if ( bk != nullptr || (bk = (malloc_chunk *)v10[1].prev_foot, v16 = v10 + 1, bk != nullptr) )
      {
        while ( 1 )
        {
          v17 = (malloc_chunk *)((char *)bk + 20);
          if ( bk[1].head == 0 )
          {
            v17 = bk + 1;
            if ( bk[1].prev_foot == 0 )
              break;
          }
          bk = (malloc_chunk *)v17->prev_foot;
          v16 = v17;
        }
        v16->prev_foot = 0;
      }
    }
    else
    {
      v15 = v10->fd;
      v15->bk = bk;
      bk->fd = v15;
    }
    if ( fd != nullptr )
    {
      v18 = 4 * ((int)&v10[1].bk[4].fd + 3);
      if ( v10 == *(malloc_chunk **)((char *)&m->smallmap + v18) )
      {
        *(unsigned int *)((char *)&m->smallmap + v18) = (unsigned int)bk;
        if ( bk == nullptr )
        {
          m->treemap &= ~(1 << (int)v10[1].bk);
          goto LABEL_31;
        }
      }
      else
      {
        if ( (malloc_chunk *)fd[1].prev_foot == v10 )
          fd[1].prev_foot = (unsigned int)bk;
        else
          fd[1].head = (unsigned int)bk;
        if ( bk == nullptr )
          goto LABEL_31;
      }
      bk[1].fd = fd;
      prev_foot = v10[1].prev_foot;
      if ( prev_foot != 0 )
      {
        bk[1].prev_foot = prev_foot;
        *(_DWORD *)(prev_foot + 24) = bk;
      }
      head = v10[1].head;
      if ( head != 0 )
      {
        bk[1].head = head;
        *(_DWORD *)(head + 24) = bk;
      }
    }
LABEL_31:
    if ( win32munmap(ptr: base, size) != 0 )
    {
      v21 = v12 >> 8;
      if ( v12 >> 8 != 0 )
      {
        if ( v21 <= 0xFFFF )
        {
          v23 = ((v21 - 256) >> 16) & 8;
          v24 = v21 << v23;
          v25 = ((v24 - 4096) >> 16) & 4;
          v26 = (v24 << v25 << ((((v24 << v25) - 0x4000) >> 16) & 2) >> 15) - ((((v24 << v25) - 0x4000) >> 16) & 2);
          v22 = ((v12 >> (v26 - (v25 + v23) + 21)) & 1) + 2 * (v26 - (v25 + v23) + 14);
        }
        else
        {
          v22 = 31;
        }
      }
      else
      {
        v22 = 0;
      }
      v10[1].bk = (malloc_chunk *)v22;
      v10[1].head = 0;
      v10[1].prev_foot = 0;
      v27 = &m->treebins[v22];
      treemap = m->treemap;
      if ( ((1 << v22) & treemap) != 0 )
      {
        v29 = (malloc_chunk *)*v27;
        if ( v22 == 31 )
          v30 = 0;
        else
          v30 = 25 - (v22 >> 1);
        v31 = v12 << v30;
        if ( (v29->head & 0xFFFFFFFC) == v12 )
        {
LABEL_46:
          v35 = v29->fd;
          v35->bk = v10;
          v29->fd = v10;
          v10->fd = v35;
          v10->bk = v29;
          v10[1].fd = nullptr;
        }
        else
        {
          while ( 1 )
          {
            __SET_PAIR__(v32, v31, 2LL * v31);
            v33 = 4 * (v32 + 4);
            v34 = *(unsigned int *)((char *)&v29->prev_foot + v33);
            if ( v34 == 0 )
              break;
            v29 = *(malloc_chunk **)((char *)&v29->prev_foot + v33);
            if ( (*(_DWORD *)(v34 + 4) & 0xFFFFFFFC) == v12 )
              goto LABEL_46;
          }
          *(unsigned int *)((char *)&v29->prev_foot + v33) = (unsigned int)v10;
          v10[1].fd = v29;
          v10->bk = v10;
          v10->fd = v10;
        }
      }
      else
      {
        m->treemap = (1 << v22) | treemap;
        *v27 = (malloc_tree_chunk *)v10;
        v10[1].fd = (malloc_chunk *)v27;
        v10->bk = v10;
        v10->fd = v10;
      }
    }
    else
    {
      v4 += size;
      next = p_seg;
      m->footprint -= size;
      p_seg->next = v8;
    }
    goto LABEL_47;
  }
  return v4;
}


// ========================================================================
// sys_trim
// EA  : 0x83295BD8
// RVA : 0x01295BD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

int __fastcall sys_trim(malloc_state *m, unsigned int pad)
{
  unsigned int v3; // r28
  malloc_chunk *top; // r8
  unsigned int topsize; // r9
  unsigned int granularity; // r11
  malloc_segment *p_seg; // r10
  unsigned int v8; // r29
  malloc_segment *v9; // r30
  unsigned int sflags; // r11
  unsigned int size; // r9
  unsigned int base; // r10
  malloc_segment *v13; // r11
  unsigned int v14; // r7
  malloc_chunk *v15; // r10
  int v16; // r11
  unsigned int v17; // r3
  malloc_chunk *v18; // r11

  v3 = 0;
  if ( pad >= 0xFFFFFFC0 )
    return 0;
  top = m->top;
  if ( top == nullptr )
    return 0;
  topsize = m->topsize;
  if ( topsize > pad + 40 )
  {
    granularity = m->m_params.granularity;
    __twllei(granularity, 0);
    p_seg = &m->seg;
    v8 = ((topsize - (pad + 40) + granularity - 1) / granularity - 1) * granularity;
    while ( (char *)top < p_seg->base || (char *)top >= &p_seg->base[p_seg->size] )
    {
      p_seg = p_seg->next;
      if ( p_seg == nullptr )
      {
        v9 = nullptr;
        goto LABEL_9;
      }
    }
    v9 = p_seg;
LABEL_9:
    sflags = v9->sflags;
    if ( (sflags & 8) == 0 && (sflags & 1) != 0 )
    {
      size = v9->size;
      if ( size >= v8 )
      {
        base = (unsigned int)v9->base;
        v13 = &m->seg;
        while ( (unsigned int)v13 < base || (unsigned int)v13 >= base + size )
        {
          v13 = v13->next;
          if ( v13 == nullptr )
          {
            if ( win32munmap(ptr: (char *)(base + size - v8), size: v8) == 0 )
            {
              v3 = v8;
              if ( v8 != 0 )
              {
                v9->size -= v8;
                v14 = m->topsize;
                v15 = m->top;
                v16 = ((unsigned __int8)v15 & 7) == 0 ? 0 : -((unsigned __int8)v15 & 7) & 7;
                m->footprint -= v8;
                v17 = v14 - v16;
                v18 = (malloc_chunk *)((char *)v15 + v16);
                m->top = v18;
                m->topsize = v17 - v8;
                v18->head = (v17 - v8) | 1;
                *(unsigned int *)((char *)&v18->head + v17 - v8) = 40;
                m->trim_check = m->m_params.trim_threshold;
              }
            }
            break;
          }
        }
      }
    }
  }
  if ( release_unused_segments(m) + v3 != 0 )
    return 1;
  m->trim_check = -1;
  return 0;
}


// ========================================================================
// tmalloc_large
// EA  : 0x83295D98
// RVA : 0x01295D98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

malloc_tree_chunk **__fastcall tmalloc_large(malloc_state *m, unsigned int nb)
{
  unsigned int v2; // r11
  unsigned int v3; // r5
  malloc_tree_chunk *v4; // r31
  unsigned int v5; // r6
  unsigned int v6; // r10
  unsigned int v7; // r11
  unsigned int v8; // r9
  unsigned int v9; // r10
  unsigned int v10; // r9
  malloc_tree_chunk *v11; // r11
  int v12; // r10
  unsigned int v13; // r8
  malloc_tree_chunk *v14; // r7
  unsigned int v15; // r9
  malloc_tree_chunk *v16; // r10
  unsigned int treemap; // r9
  int v18; // r7
  unsigned int v19; // r11
  int v20; // r10
  unsigned int v21; // r9
  int v22; // r11
  unsigned int v23; // r8
  int v24; // r9
  int v25; // r10
  int v26; // r11
  unsigned int v27; // r9
  malloc_tree_chunk *bk; // r11
  malloc_tree_chunk *v29; // r7
  malloc_tree_chunk *parent; // r8
  malloc_tree_chunk *fd; // r10
  malloc_tree_chunk **v32; // r9
  malloc_tree_chunk **child; // r10
  int v34; // r10
  malloc_tree_chunk *v35; // r10
  malloc_tree_chunk *v36; // r10
  malloc_tree_chunk **result; // r3
  unsigned int v38; // r11
  int v39; // r9
  malloc_chunk **v40; // r11
  unsigned int v41; // r6
  malloc_chunk *v42; // r8
  unsigned int v43; // r11
  unsigned int v44; // r11
  unsigned int v45; // r10
  unsigned int v46; // r11
  unsigned int v47; // r9
  unsigned int v48; // r8
  malloc_tree_chunk **v49; // r8
  unsigned int v50; // r9
  malloc_tree_chunk *v51; // r10
  char v52; // r11
  unsigned int v53; // r9
  int v54; // r11
  int v55; // r8
  int v56; // r11
  malloc_tree_chunk *v57; // r11

  v2 = nb >> 8;
  v3 = -nb;
  v4 = nullptr;
  if ( nb >> 8 != 0 )
  {
    if ( v2 <= 0xFFFF )
    {
      v6 = ((v2 - 256) >> 16) & 8;
      v7 = v2 << v6;
      v8 = ((v7 - 4096) >> 16) & 4;
      v9 = v8 + v6;
      v10 = (v7 << v8 << ((((v7 << v8) - 0x4000) >> 16) & 2) >> 15) - ((((v7 << v8) - 0x4000) >> 16) & 2);
      v5 = ((nb >> (v10 - v9 + 21)) & 1) + 2 * (v10 - v9 + 14);
    }
    else
    {
      v5 = 31;
    }
  }
  else
  {
    v5 = 0;
  }
  v11 = m->treebins[v5];
  if ( v11 != nullptr )
  {
    if ( v5 == 31 )
      LOBYTE(v12) = 0;
    else
      v12 = 25 - (v5 >> 1);
    v13 = nb << v12;
    v14 = nullptr;
    while ( 1 )
    {
      v15 = v11->head & 0xFFFFFFFC;
      if ( v15 - nb < v3 )
      {
        v4 = v11;
        v3 = v15 - nb;
        if ( v15 == nb )
          break;
      }
      v16 = v11->child[1];
      v11 = v11->child[v13 >> 31];
      if ( v16 != nullptr && v16 != v11 )
        v14 = v16;
      if ( v11 == nullptr )
      {
        v11 = v14;
        break;
      }
      v13 *= 2;
    }
    if ( v11 != nullptr )
      goto LABEL_24;
    if ( v4 != nullptr )
      goto LABEL_31;
  }
  treemap = m->treemap;
  v18 = 2 * (-1 << v5);
  if ( (v18 & treemap) != 0 )
  {
    v19 = (-(v18 & treemap) & v18 & treemap) - 1;
    v20 = (v19 >> 12) & 0x10;
    v21 = v19 >> v20;
    v22 = (v19 >> v20 >> 5) & 8;
    v23 = v21 >> v22;
    v24 = (v21 >> v22 >> 2) & 4;
    v25 = v20 + v22;
    v26 = (v23 >> v24 >> 1) & 2;
    v11 = *(&m->treebins[v23 >> v24 >> v26 >> (((v23 >> v24 >> v26) & 2) != 0)]
          + v25
          + v24
          + v26
          + (((v23 >> v24 >> v26) & 2) != 0));
  }
  while ( v11 != nullptr )
  {
LABEL_24:
    v27 = v11->head & 0xFFFFFFFC;
    if ( v27 - nb < v3 )
    {
      v3 = v27 - nb;
      v4 = v11;
    }
    if ( v11->child[0] != nullptr )
      v11 = v11->child[0];
    else
      v11 = v11->child[1];
  }
  if ( v4 == nullptr )
    return nullptr;
LABEL_31:
  if ( v3 >= m->dvsize - nb )
    return nullptr;
  bk = v4->bk;
  v29 = (malloc_tree_chunk *)((char *)v4 + nb);
  parent = v4->parent;
  if ( bk == v4 )
  {
    bk = v4->child[1];
    v32 = &v4->child[1];
    if ( bk != nullptr || (bk = v4->child[0], v32 = v4->child, bk != nullptr) )
    {
      while ( 1 )
      {
        child = &bk->child[1];
        if ( bk->child[1] == nullptr )
        {
          child = bk->child;
          if ( bk->child[0] == nullptr )
            break;
        }
        bk = *child;
        v32 = child;
      }
      *v32 = nullptr;
    }
  }
  else
  {
    fd = v4->fd;
    fd->bk = bk;
    bk->fd = fd;
  }
  if ( parent != nullptr )
  {
    v34 = 4 * (v4->index + 75);
    if ( v4 == *(malloc_tree_chunk **)((char *)&m->smallmap + v34) )
    {
      *(unsigned int *)((char *)&m->smallmap + v34) = (unsigned int)bk;
      if ( bk == nullptr )
      {
        m->treemap &= ~(1 << v4->index);
        goto LABEL_52;
      }
    }
    else
    {
      if ( parent->child[0] == v4 )
        parent->child[0] = bk;
      else
        parent->child[1] = bk;
      if ( bk == nullptr )
        goto LABEL_52;
    }
    bk->parent = parent;
    v35 = v4->child[0];
    if ( v35 != nullptr )
    {
      bk->child[0] = v35;
      v35->parent = bk;
    }
    v36 = v4->child[1];
    if ( v36 != nullptr )
    {
      bk->child[1] = v36;
      v36->parent = bk;
    }
  }
LABEL_52:
  if ( v3 >= 0x10 )
  {
    v38 = v3 >> 3;
    v4->head = nb | 3;
    v29->head = v3 | 1;
    *(unsigned int *)((char *)&v29->prev_foot + v3) = v3;
    if ( v3 >> 3 >= 0x20 )
    {
      v43 = v3 >> 8;
      if ( v3 >> 8 != 0 )
      {
        if ( v43 <= 0xFFFF )
        {
          v45 = ((v43 - 256) >> 16) & 8;
          v46 = v43 << v45;
          v47 = ((v46 - 4096) >> 16) & 4;
          v48 = (v46 << v47 << ((((v46 << v47) - 0x4000) >> 16) & 2) >> 15) - ((((v46 << v47) - 0x4000) >> 16) & 2);
          v44 = ((v3 >> (v48 - (v47 + v45) + 21)) & 1) + 2 * (v48 - (v47 + v45) + 14);
        }
        else
        {
          v44 = 31;
        }
      }
      else
      {
        v44 = 0;
      }
      v29->index = v44;
      v29->child[1] = nullptr;
      v29->child[0] = nullptr;
      v49 = &m->treebins[v44];
      v50 = m->treemap;
      if ( ((1 << v44) & v50) != 0 )
      {
        v51 = *v49;
        if ( v44 == 31 )
          v52 = 0;
        else
          v52 = 25 - (v44 >> 1);
        v53 = v3 << v52;
        if ( (v51->head & 0xFFFFFFFC) == v3 )
        {
LABEL_72:
          v57 = v51->fd;
          v57->bk = v29;
          v51->fd = v29;
          v29->fd = v57;
          v29->bk = v51;
          v29->parent = nullptr;
          return &v4->fd;
        }
        else
        {
          while ( 1 )
          {
            v54 = (unsigned __int64)v53 >> 31;
            v53 *= 2;
            v55 = 4 * (v54 + 4);
            v56 = *(unsigned int *)((char *)&v51->prev_foot + v55);
            if ( v56 == 0 )
              break;
            v51 = *(malloc_tree_chunk **)((char *)&v51->prev_foot + v55);
            if ( (*(_DWORD *)(v56 + 4) & 0xFFFFFFFC) == v3 )
              goto LABEL_72;
          }
          *(unsigned int *)((char *)&v51->prev_foot + v55) = (unsigned int)v29;
          v29->parent = v51;
          v29->bk = v29;
          v29->fd = v29;
          return &v4->fd;
        }
      }
      else
      {
        m->treemap = (1 << v44) | v50;
        *v49 = v29;
        v29->parent = (malloc_tree_chunk *)v49;
        v29->bk = v29;
        v29->fd = v29;
        return &v4->fd;
      }
    }
    else
    {
      v39 = 1 << v38;
      v41 = m->smallmap & (1 << v38);
      v40 = &m->smallbins[2 * v38];
      if ( v41 != 0 )
      {
        v42 = v40[2];
        result = &v4->fd;
        v40[2] = (malloc_chunk *)v29;
        v42->bk = (malloc_chunk *)v29;
        v29->fd = (malloc_tree_chunk *)v42;
      }
      else
      {
        m->smallmap |= v39;
        result = &v4->fd;
        v40[2] = (malloc_chunk *)v29;
        v40[3] = (malloc_chunk *)v29;
        v29->fd = (malloc_tree_chunk *)v40;
      }
      v29->bk = (malloc_tree_chunk *)v40;
    }
  }
  else
  {
    v4->head = (v3 + nb) | 3;
    *(unsigned int *)((char *)&v4->head + v3 + nb) |= 1u;
    return &v4->fd;
  }
  return result;
}


// ========================================================================
// tmalloc_small
// EA  : 0x832962E0
// RVA : 0x012962E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

_DWORD *__fastcall tmalloc_small(malloc_state *m, unsigned int nb)
{
  unsigned int v3; // r11
  int v4; // r10
  unsigned int v5; // r9
  int v6; // r11
  unsigned int v7; // r7
  int v8; // r9
  int v9; // r10
  int v10; // r11
  _DWORD *v11; // r11
  unsigned int v12; // r3
  _DWORD *v13; // r10
  unsigned int v14; // r7
  _DWORD *v15; // r11
  malloc_chunk *v16; // r31
  int v17; // r6
  int v18; // r9
  _DWORD *v19; // r7
  _DWORD *v20; // r9
  int v21; // r9
  int v22; // r9
  int v23; // r9
  unsigned int dvsize; // r11
  malloc_chunk *dv; // r6
  int v27; // r7
  malloc_chunk *v28; // r11
  malloc_chunk *fd; // r5

  v3 = (-m->treemap & m->treemap) - 1;
  v4 = (v3 >> 12) & 0x10;
  v5 = v3 >> v4;
  v6 = (v3 >> v4 >> 5) & 8;
  v7 = v5 >> v6;
  v8 = (v5 >> v6 >> 2) & 4;
  v9 = v4 + v6;
  v10 = (v7 >> v8 >> 1) & 2;
  v11 = *((_DWORD **)&m->treebins[v7 >> v8 >> v10 >> (((v7 >> v8 >> v10) & 2) != 0)]
        + v9
        + v8
        + v10
        + (((v7 >> v8 >> v10) & 2) != 0));
  v12 = (v11[1] & 0xFFFFFFFC) - nb;
LABEL_2:
  v13 = v11;
  while ( 1 )
  {
    v11 = (_DWORD *)(v11[4] != 0 ? v11[4] : v11[5]);
    if ( v11 == nullptr )
      break;
    v14 = v11[1] & 0xFFFFFFFC;
    if ( v14 - nb < v12 )
    {
      v12 = v14 - nb;
      goto LABEL_2;
    }
  }
  v15 = (_DWORD *)v13[3];
  v16 = (malloc_chunk *)((char *)v13 + nb);
  v17 = v13[6];
  if ( v15 == v13 )
  {
    v15 = (_DWORD *)v13[5];
    v19 = v13 + 5;
    if ( v15 != nullptr || (v15 = (_DWORD *)v13[4], v19 = v13 + 4, v15 != nullptr) )
    {
      while ( 1 )
      {
        v20 = v15 + 5;
        if ( v15[5] == 0 )
        {
          v20 = v15 + 4;
          if ( v15[4] == 0 )
            break;
        }
        v15 = (_DWORD *)*v20;
        v19 = v20;
      }
      *v19 = 0;
    }
  }
  else
  {
    v18 = v13[2];
    *(_DWORD *)(v18 + 12) = v15;
    v15[2] = v18;
  }
  if ( v17 != 0 )
  {
    v21 = 4 * (v13[7] + 75);
    if ( v13 == *(_DWORD **)((char *)&m->smallmap + v21) )
    {
      *(unsigned int *)((char *)&m->smallmap + v21) = (unsigned int)v15;
      if ( v15 == nullptr )
      {
        m->treemap &= ~(1 << v13[7]);
        goto LABEL_29;
      }
    }
    else
    {
      if ( *(_DWORD **)(v17 + 16) == v13 )
        *(_DWORD *)(v17 + 16) = v15;
      else
        *(_DWORD *)(v17 + 20) = v15;
      if ( v15 == nullptr )
        goto LABEL_29;
    }
    v15[6] = v17;
    v22 = v13[4];
    if ( v22 != 0 )
    {
      v15[4] = v22;
      *(_DWORD *)(v22 + 24) = v15;
    }
    v23 = v13[5];
    if ( v23 != 0 )
    {
      v15[5] = v23;
      *(_DWORD *)(v23 + 24) = v15;
    }
  }
LABEL_29:
  if ( v12 >= 0x10 )
  {
    v13[1] = nb | 3;
    v16->head = v12 | 1;
    *(unsigned int *)((char *)&v16->prev_foot + v12) = v12;
    dvsize = m->dvsize;
    if ( dvsize != 0 )
    {
      dv = m->dv;
      v27 = 1 << (dvsize >> 3);
      v28 = (malloc_chunk *)((char *)m->smallbins + (dvsize & 0xFFFFFFF8));
      fd = v28;
      if ( (m->smallmap & v27) != 0 )
        fd = v28->fd;
      else
        m->smallmap |= v27;
      v28->fd = dv;
      fd->bk = dv;
      dv->fd = fd;
      dv->bk = v28;
    }
    m->dvsize = v12;
    m->dv = v16;
    return v13 + 2;
  }
  else
  {
    v13[1] = (v12 + nb) | 3;
    *(_DWORD *)((char *)v13 + v12 + nb + 4) |= 1u;
    return v13 + 2;
  }
}


// ========================================================================
// ?mspace_malloc@bfx@@YAPAXPAXI@Z
// EA  : 0x83296550
// RVA : 0x01296550
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

char *__fastcall bfx::mspace_malloc(malloc_state *msp, unsigned int bytes, int a3, int smallmap, int a5, int a6)
{
  unsigned int v7; // r30
  unsigned int v8; // r11
  unsigned int v9; // r10
  unsigned int v10; // r10
  char *v11; // r11
  malloc_chunk *v12; // r9
  char *result; // r3
  malloc_chunk *fd; // r8
  unsigned int v15; // r11
  int v16; // r10
  unsigned int v17; // r9
  int v18; // r11
  unsigned int v19; // r8
  int v20; // r9
  int v21; // r9
  int v22; // r7
  char *v23; // r11
  malloc_chunk *v24; // r10
  malloc_chunk *v25; // r8
  unsigned int v26; // r6
  malloc_chunk *v27; // r5
  unsigned int v28; // r11
  malloc_chunk *v29; // r8
  int v30; // r9
  malloc_chunk *v31; // r11
  malloc_chunk *v32; // r7
  unsigned int dvsize; // r9
  unsigned int v34; // r11
  malloc_chunk *dv; // r10
  char *v36; // r9
  unsigned int topsize; // r10
  malloc_chunk *top; // r11

  if ( bytes > 0xF4 )
  {
    if ( bytes < 0xFFFFFFC0 )
    {
      v7 = (bytes + 11) & 0xFFFFFFF8;
      if ( msp->treemap != 0 )
      {
        result = (char *)tmalloc_large(m: msp, nb: (bytes + 11) & 0xFFFFFFF8);
LABEL_27:
        if ( result != nullptr )
          return result;
      }
    }
    else
    {
      v7 = -1;
    }
LABEL_28:
    dvsize = msp->dvsize;
    if ( v7 > dvsize )
    {
      topsize = msp->topsize;
      if ( v7 >= topsize )
      {
        if ( (msp->mflags & 0x10) != 0 )
          return nullptr;
        else
          return sys_alloc(m: msp, nb: v7, a3, a4: smallmap, a5, a6);
      }
      else
      {
        top = msp->top;
        msp->topsize = topsize - v7;
        msp->top = (malloc_chunk *)((char *)top + v7);
        *(unsigned int *)((char *)&top->head + v7) = (topsize - v7) | 1;
        top->head = v7 | 3;
        return (char *)&top->fd;
      }
    }
    else
    {
      v34 = dvsize - v7;
      dv = msp->dv;
      if ( dvsize - v7 < 0x10 )
      {
        msp->dv = nullptr;
        msp->dvsize = 0;
        dv->head = dvsize | 3;
        *(unsigned int *)((char *)&dv->head + dvsize) |= 1u;
      }
      else
      {
        v36 = (char *)dv + v7;
        msp->dvsize = v34;
        msp->dv = (malloc_chunk *)((char *)dv + v7);
        *((_DWORD *)v36 + 1) = v34 | 1;
        *(_DWORD *)&v36[v34] = v34;
        dv->head = v7 | 3;
      }
      return (char *)&dv->fd;
    }
  }
  if ( bytes >= 0xB )
    v7 = (bytes + 11) & 0xFFFFFFF8;
  else
    v7 = 16;
  smallmap = msp->smallmap;
  v8 = v7 >> 3;
  v9 = msp->smallmap >> (v7 >> 3);
  if ( (v9 & 3) != 0 )
  {
    v10 = ((v9 & 1) == 0) + v8;
    v11 = (char *)&msp->smallbins[2 * v10];
    v12 = msp->smallbins[2 * v10 + 2];
    result = (char *)&v12->fd;
    fd = v12->fd;
    if ( v11 == (char *)fd )
    {
      msp->smallmap = smallmap & ~(1 << v10);
    }
    else
    {
      msp->smallbins[2 * v10 + 2] = fd;
      fd->bk = (malloc_chunk *)v11;
    }
    v12->head = (8 * v10) | 3;
    *(&v12->head + 2 * v10) |= 1u;
    return result;
  }
  if ( v7 <= msp->dvsize )
    goto LABEL_28;
  if ( v9 == 0 )
  {
    if ( msp->treemap != 0 )
    {
      result = (char *)tmalloc_small(m: msp, nb: v7);
      goto LABEL_27;
    }
    goto LABEL_28;
  }
  v15 = (-((v9 << v8) & (2 * (-1 << v8))) & (v9 << v8) & (2 * (-1 << v8))) - 1;
  v16 = (v15 >> 12) & 0x10;
  v17 = v15 >> v16;
  v18 = (v15 >> v16 >> 5) & 8;
  v19 = v17 >> v18;
  v20 = (v17 >> v18 >> 2) & 4;
  v21 = (v19 >> v20 >> ((v19 >> v20 >> 1) & 2) >> (((v19 >> v20 >> ((v19 >> v20 >> 1) & 2)) & 2) != 0))
      + v16
      + v18
      + v20
      + ((v19 >> v20 >> 1) & 2)
      + (((v19 >> v20 >> ((v19 >> v20 >> 1) & 2)) & 2) != 0);
  v22 = 8 * v21;
  v23 = (char *)&msp->smallbins[2 * v21];
  v24 = msp->smallbins[2 * v21 + 2];
  result = (char *)&v24->fd;
  v25 = v24->fd;
  if ( v23 == (char *)v25 )
  {
    msp->smallmap = smallmap & ~(1 << v21);
  }
  else
  {
    msp->smallbins[2 * v21 + 2] = v25;
    v25->bk = (malloc_chunk *)v23;
  }
  v26 = v22 - v7;
  v27 = (malloc_chunk *)((char *)v24 + v7);
  v24->head = v7 | 3;
  v27->head = (v22 - v7) | 1;
  *(unsigned int *)((char *)&v27->prev_foot + v22 - v7) = v22 - v7;
  v28 = msp->dvsize;
  if ( v28 != 0 )
  {
    v29 = msp->dv;
    v30 = 1 << (v28 >> 3);
    v31 = (malloc_chunk *)((char *)msp->smallbins + (v28 & 0xFFFFFFF8));
    v32 = v31;
    if ( (msp->smallmap & v30) != 0 )
      v32 = v31->fd;
    else
      msp->smallmap |= v30;
    v31->fd = v29;
    v32->bk = v29;
    v29->fd = v32;
    v29->bk = v31;
  }
  msp->dvsize = v26;
  msp->dv = v27;
  return result;
}


// ========================================================================
// ?mspace_free@bfx@@YAXPAX0@Z
// EA  : 0x83296878
// RVA : 0x01296878
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

void __fastcall bfx::mspace_free(malloc_state *msp, _DWORD *mem)
{
  malloc_chunk *v3; // r11
  int v4; // r10
  unsigned int v5; // r5
  malloc_chunk *v6; // r6
  unsigned int prev_foot; // r10
  unsigned int v8; // r10
  unsigned int v9; // r31
  unsigned int v10; // r8
  malloc_chunk *fd; // r10
  malloc_chunk *bk; // r9
  unsigned int v13; // r10
  unsigned int topsize; // r10
  unsigned int v15; // r10
  malloc_chunk *head; // r10
  malloc_chunk *v17; // r7
  malloc_chunk *v18; // r9
  malloc_chunk *v19; // r8
  malloc_chunk *v20; // r9
  int v21; // r9
  unsigned int v22; // r9
  unsigned int v23; // r9
  unsigned int dvsize; // r10
  unsigned int v25; // r10
  unsigned int v26; // r8
  malloc_chunk *v27; // r10
  malloc_chunk *v28; // r9
  malloc_chunk *v29; // r10
  malloc_chunk *v30; // r7
  malloc_chunk *v31; // r9
  malloc_chunk *v32; // r8
  malloc_chunk *v33; // r9
  int v34; // r9
  unsigned int v35; // r9
  unsigned int v36; // r9
  unsigned int v37; // r10
  int v38; // r8
  malloc_chunk **v39; // r10
  int v40; // r6
  malloc_chunk *v41; // r7
  unsigned int v42; // r10
  unsigned int v43; // r10
  unsigned int v44; // r8
  unsigned int v45; // r9
  unsigned int v46; // r10
  unsigned int v47; // r10
  malloc_tree_chunk **v48; // r7
  unsigned int treemap; // r8
  malloc_chunk *v50; // r9
  char v51; // r10
  unsigned int v52; // r8
  unsigned int v53; // r10
  int v54; // r7
  int v55; // r10
  malloc_chunk *v56; // r10

  if ( mem == nullptr )
    return;
  v3 = (malloc_chunk *)(mem - 2);
  v4 = *(mem - 1);
  v5 = v4 & 0xFFFFFFFC;
  v6 = (malloc_chunk *)((char *)mem + (v4 & 0xFFFFFFFC) - 8);
  if ( (v4 & 1) == 0 )
  {
    prev_foot = v3->prev_foot;
    if ( (v3->prev_foot & 1) != 0 )
    {
      v8 = prev_foot & 0xFFFFFFFE;
      v9 = v8 + v5 + 16;
      if ( win32munmap(ptr: (char *)v3 - v8, size: v9) == 0 )
        msp->footprint -= v9;
      return;
    }
    v3 = (malloc_chunk *)((char *)v3 - prev_foot);
    v5 += prev_foot;
    if ( v3 == msp->dv )
    {
      if ( (v6->head & 3) == 3 )
      {
        msp->dvsize = v5;
        v6->head &= ~1u;
        v3->head = v5 | 1;
        *(unsigned int *)((char *)&v3->prev_foot + v5) = v5;
        return;
      }
    }
    else
    {
      v10 = prev_foot >> 3;
      if ( prev_foot >> 3 < 0x20 )
      {
        fd = v3->fd;
        bk = v3->bk;
        if ( fd == bk )
        {
          msp->smallmap &= ~(1 << v10);
        }
        else
        {
          fd->bk = bk;
          bk->fd = fd;
        }
        goto LABEL_10;
      }
      head = v3->bk;
      v17 = v3[1].fd;
      if ( head == v3 )
      {
        head = (malloc_chunk *)v3[1].head;
        v19 = (malloc_chunk *)((char *)v3 + 20);
        if ( head != nullptr || (head = (malloc_chunk *)v3[1].prev_foot, v19 = v3 + 1, head != nullptr) )
        {
          while ( 1 )
          {
            v20 = (malloc_chunk *)((char *)head + 20);
            if ( head[1].head == 0 )
            {
              v20 = head + 1;
              if ( head[1].prev_foot == 0 )
                break;
            }
            head = (malloc_chunk *)v20->prev_foot;
            v19 = v20;
          }
          v19->prev_foot = 0;
        }
      }
      else
      {
        v18 = v3->fd;
        v18->bk = head;
        head->fd = v18;
      }
      if ( v17 != nullptr )
      {
        v21 = 4 * ((int)&v3[1].bk[4].fd + 3);
        if ( v3 == *(malloc_chunk **)((char *)&msp->smallmap + v21) )
        {
          *(unsigned int *)((char *)&msp->smallmap + v21) = (unsigned int)head;
          if ( head == nullptr )
          {
            msp->treemap &= ~(1 << (int)v3[1].bk);
            goto LABEL_10;
          }
        }
        else
        {
          if ( (malloc_chunk *)v17[1].prev_foot == v3 )
            v17[1].prev_foot = (unsigned int)head;
          else
            v17[1].head = (unsigned int)head;
          if ( head == nullptr )
            goto LABEL_10;
        }
        head[1].fd = v17;
        v22 = v3[1].prev_foot;
        if ( v22 != 0 )
        {
          head[1].prev_foot = v22;
          *(_DWORD *)(v22 + 24) = head;
        }
        v23 = v3[1].head;
        if ( v23 != 0 )
        {
          head[1].head = v23;
          *(_DWORD *)(v23 + 24) = head;
        }
      }
    }
  }
LABEL_10:
  v13 = v6->head;
  if ( (v13 & 2) == 0 )
  {
    if ( v6 == msp->top )
    {
      topsize = msp->topsize;
      msp->top = v3;
      v15 = v5 + topsize;
      msp->topsize = v15;
      v3->head = v15 | 1;
      if ( v3 == msp->dv )
      {
        msp->dv = nullptr;
        msp->dvsize = 0;
      }
      if ( v15 > msp->trim_check )
        sys_trim(m: msp, pad: 0);
      return;
    }
    if ( v6 == msp->dv )
    {
      dvsize = msp->dvsize;
      msp->dv = v3;
      v25 = v5 + dvsize;
      msp->dvsize = v25;
      v3->head = v25 | 1;
      *(unsigned int *)((char *)&v3->prev_foot + v25) = v25;
      return;
    }
    v26 = v13 >> 3;
    v5 += v13 & 0xFFFFFFFC;
    if ( v13 >> 3 < 0x20 )
    {
      v27 = v6->fd;
      v28 = v6->bk;
      if ( v27 == v28 )
      {
        msp->smallmap &= ~(1 << v26);
      }
      else
      {
        v27->bk = v28;
        v28->fd = v27;
      }
      goto LABEL_65;
    }
    v29 = v6->bk;
    v30 = v6[1].fd;
    if ( v29 == v6 )
    {
      v29 = (malloc_chunk *)v6[1].head;
      v32 = (malloc_chunk *)((char *)v6 + 20);
      if ( v29 != nullptr || (v29 = (malloc_chunk *)v6[1].prev_foot, v32 = v6 + 1, v29 != nullptr) )
      {
        while ( 1 )
        {
          v33 = (malloc_chunk *)((char *)v29 + 20);
          if ( v29[1].head == 0 )
          {
            v33 = v29 + 1;
            if ( v29[1].prev_foot == 0 )
              break;
          }
          v29 = (malloc_chunk *)v33->prev_foot;
          v32 = v33;
        }
        v32->prev_foot = 0;
      }
    }
    else
    {
      v31 = v6->fd;
      v31->bk = v29;
      v29->fd = v31;
    }
    if ( v30 != nullptr )
    {
      v34 = 4 * ((int)&v6[1].bk[4].fd + 3);
      if ( v6 == *(malloc_chunk **)((char *)&msp->smallmap + v34) )
      {
        *(unsigned int *)((char *)&msp->smallmap + v34) = (unsigned int)v29;
        if ( v29 == nullptr )
        {
          msp->treemap &= ~(1 << (int)v6[1].bk);
          goto LABEL_65;
        }
      }
      else
      {
        if ( (malloc_chunk *)v30[1].prev_foot == v6 )
          v30[1].prev_foot = (unsigned int)v29;
        else
          v30[1].head = (unsigned int)v29;
        if ( v29 == nullptr )
          goto LABEL_65;
      }
      v29[1].fd = v30;
      v35 = v6[1].prev_foot;
      if ( v35 != 0 )
      {
        v29[1].prev_foot = v35;
        *(_DWORD *)(v35 + 24) = v29;
      }
      v36 = v6[1].head;
      if ( v36 != 0 )
      {
        v29[1].head = v36;
        *(_DWORD *)(v36 + 24) = v29;
      }
    }
LABEL_65:
    v3->head = v5 | 1;
    *(unsigned int *)((char *)&v3->prev_foot + v5) = v5;
    if ( v3 == msp->dv )
    {
      msp->dvsize = v5;
      return;
    }
    goto LABEL_68;
  }
  v6->head = v13 & 0xFFFFFFFE;
  v3->head = v5 | 1;
  *(unsigned int *)((char *)&v3->prev_foot + v5) = v5;
LABEL_68:
  v37 = v5 >> 3;
  if ( v5 >> 3 >= 0x20 )
  {
    v42 = v5 >> 8;
    if ( v5 >> 8 != 0 )
    {
      if ( v42 <= 0xFFFF )
      {
        v44 = ((v42 - 256) >> 16) & 8;
        v45 = v42 << v44;
        v46 = (((v42 << v44) - 4096) >> 16) & 4;
        v47 = (v45 << v46 << ((((v45 << v46) - 0x4000) >> 16) & 2) >> 15)
            - ((((v45 << v46) - 0x4000) >> 16) & 2)
            - (v46
             + v44)
            + 14;
        v43 = ((v5 >> (v47 + 7)) & 1) + 2 * v47;
      }
      else
      {
        v43 = 31;
      }
    }
    else
    {
      v43 = 0;
    }
    v3[1].bk = (malloc_chunk *)v43;
    v3[1].head = 0;
    v3[1].prev_foot = 0;
    v48 = &msp->treebins[v43];
    treemap = msp->treemap;
    if ( ((1 << v43) & treemap) != 0 )
    {
      v50 = (malloc_chunk *)*v48;
      if ( v43 == 31 )
        v51 = 0;
      else
        v51 = 25 - (v43 >> 1);
      v52 = v5 << v51;
      if ( (v50->head & 0xFFFFFFFC) == v5 )
      {
LABEL_86:
        v56 = v50->fd;
        v56->bk = v3;
        v50->fd = v3;
        v3->fd = v56;
        v3->bk = v50;
        v3[1].fd = nullptr;
      }
      else
      {
        while ( 1 )
        {
          __SET_PAIR__(v53, v52, 2LL * v52);
          v54 = 4 * (v53 + 4);
          v55 = *(unsigned int *)((char *)&v50->prev_foot + v54);
          if ( v55 == 0 )
            break;
          v50 = *(malloc_chunk **)((char *)&v50->prev_foot + v54);
          if ( (*(_DWORD *)(v55 + 4) & 0xFFFFFFFC) == v5 )
            goto LABEL_86;
        }
        *(unsigned int *)((char *)&v50->prev_foot + v54) = (unsigned int)v3;
        v3[1].fd = v50;
        v3->bk = v3;
        v3->fd = v3;
      }
    }
    else
    {
      msp->treemap = (1 << v43) | treemap;
      *v48 = (malloc_tree_chunk *)v3;
      v3[1].fd = (malloc_chunk *)v48;
      v3->bk = v3;
      v3->fd = v3;
    }
  }
  else
  {
    v38 = 1 << v37;
    v40 = (1 << v37) & msp->smallmap;
    v39 = &msp->smallbins[2 * v37];
    if ( v40 != 0 )
    {
      v41 = v39[2];
      v39[2] = v3;
      v41->bk = v3;
      v3->fd = v41;
    }
    else
    {
      msp->smallmap |= v38;
      v39[2] = v3;
      v39[3] = v3;
      v3->fd = (malloc_chunk *)v39;
    }
    v3->bk = (malloc_chunk *)v39;
  }
}


// ========================================================================
// ?mspace_mallinfo@bfx@@YA?AUmallinfo@1@PAX@Z
// EA  : 0x83296E48
// RVA : 0x01296E48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

bfx::mallinfo *__fastcall bfx::mspace_mallinfo(bfx::mallinfo *result, malloc_state *msp)
{
  bfx::mallinfo *v3; // r3
  unsigned int *p_keepcost; // r10
  unsigned int *v5; // r11
  int i; // ctr
  bfx::mallinfo v8; // [sp+50h] [-40h] BYREF

  v3 = internal_mallinfo(result: &v8, m: msp);
  p_keepcost = &result[-1].keepcost;
  v5 = &v3[-1].keepcost;
  for ( i = 10; i != 0; --i )
    *++p_keepcost = *++v5;
  return result;
}


// ========================================================================
// ?mspace_malloc_usable_size@bfx@@YAIPAX0@Z
// EA  : 0x83296E98
// RVA : 0x01296E98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

unsigned int __fastcall bfx::mspace_malloc_usable_size(void *msp, _DWORD *mem)
{
  int v2; // r10
  int v3; // r11

  if ( mem == nullptr )
    return 0;
  v2 = *(mem - 1);
  if ( (v2 & 2) == 0 )
    return 0;
  if ( (v2 & 1) != 0 || (v3 = 8, (*(mem - 2) & 1) == 0) )
    v3 = 4;
  return (v2 & 0xFFFFFFFC) - v3;
}


// ========================================================================
// internal_memalign
// EA  : 0x83296EE8
// RVA : 0x01296EE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

char *__fastcall internal_memalign(malloc_state *m, unsigned int alignment, unsigned int bytes, int a4, int a5, int a6)
{
  unsigned int v7; // r30
  unsigned int i; // r11
  unsigned int v10; // r29
  char *v11; // r3
  _DWORD *v12; // r4
  char *v13; // r28
  char *v14; // r31
  char *v15; // r11
  int v16; // r10
  int v17; // r8
  unsigned int v18; // r7
  int v19; // r10
  unsigned int v20; // r10
  char *v21; // r11
  int v22; // r5

  v7 = alignment;
  if ( alignment <= 8 )
    return bfx::mspace_malloc(msp: m, bytes, a3: bytes, smallmap: a4, a5, a6);
  if ( alignment < 0x10 )
    v7 = 16;
  if ( ((v7 - 1) & v7) != 0 )
  {
    for ( i = 16; i < v7; i *= 2 )
      ;
    v7 = i;
  }
  if ( bytes >= -64 - v7 )
    return nullptr;
  v10 = bytes >= 0xB ? (bytes + 11) & 0xFFFFFFF8 : 16;
  v11 = bfx::mspace_malloc(msp: m, bytes: v10 + v7 + 12, a3: bytes, smallmap: a4, a5, a6);
  if ( v11 == nullptr )
    return nullptr;
  __twllei(v7, 0);
  v12 = nullptr;
  v13 = nullptr;
  v14 = v11 - 8;
  if ( (unsigned int)v11 % v7 != 0 )
  {
    v15 = (char *)(((unsigned int)&v11[v7 - 1] & -v7) - 8);
    if ( (unsigned int)(v15 - v14) < 0x10 )
      v15 += v7;
    v16 = *((_DWORD *)v14 + 1);
    v17 = v15 - v14;
    v18 = (v16 & 0xFFFFFFFC) - (v15 - v14);
    if ( (v16 & 1) != 0 || (*(_DWORD *)v14 & 1) == 0 )
    {
      v12 = v11;
      *((_DWORD *)v15 + 1) = *((_DWORD *)v15 + 1) & 1 | v18 | 2;
      *(_DWORD *)&v14[(v16 & 0xFFFFFFFC) + 4] |= 1u;
      *((_DWORD *)v14 + 1) = *((_DWORD *)v14 + 1) & 1 | v17 | 2;
      *((_DWORD *)v15 + 1) |= 1u;
    }
    else
    {
      *(_DWORD *)v15 = *(_DWORD *)v14 + v17;
      *((_DWORD *)v15 + 1) = v18 | 2;
    }
    v14 = v15;
  }
  v19 = *((_DWORD *)v14 + 1);
  if ( (v19 & 1) != 0 || (*(_DWORD *)v14 & 1) == 0 )
  {
    v20 = v19 & 0xFFFFFFFC;
    if ( v20 > v10 + 16 )
    {
      v21 = &v14[v10];
      *((_DWORD *)v14 + 1) = *((_DWORD *)v14 + 1) & 1 | v10 | 2;
      v22 = *(_DWORD *)&v14[v10 + 4] | 1;
      *((_DWORD *)v21 + 1) = v22;
      v13 = &v14[v10 + 8];
      *((_DWORD *)v21 + 1) = v22 & 1 | (v20 - v10) | 2;
      *(_DWORD *)&v14[v20 + 4] |= 1u;
    }
  }
  if ( v12 != nullptr )
    bfx::mspace_free(msp: m, mem: v12);
  if ( v13 != nullptr )
    bfx::mspace_free(msp: m, mem: v13);
  return v14 + 8;
}


// ========================================================================
// ?mspace_memalign@bfx@@YAPAXPAXII@Z
// EA  : 0x83297120
// RVA : 0x01297120
// PDB : w:\tech5\libs\navpower\src\bfxsystem\dlmalloc.cpp
// ========================================================================

// attributes: thunk
char *__fastcall bfx::mspace_memalign(
        malloc_state *msp,
        unsigned int alignment,
        unsigned int bytes,
        int a4,
        int a5,
        int a6)
{
  return internal_memalign(m: msp, alignment, bytes, a4, a5, a6);
}

