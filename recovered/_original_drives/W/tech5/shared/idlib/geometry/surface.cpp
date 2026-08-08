
// ========================================================================
// ?GenerateEdgeIndexes@idSurface@@IAAXXZ
// EA  : 0x82F21748
// RVA : 0x00F21748
// PDB : w:\tech5\shared\idlib\geometry\surface.cpp
// ========================================================================

void __fastcall idSurface::GenerateEdgeIndexes(idSurface *this)
{
  int v2; // r12
  size_t v3; // r5
  int num; // r30
  int size; // r10
  int v6; // r12
  int v7; // r11
  idList<surfaceEdge_t,44> *p_edges; // r23
  int v9; // r4
  int v10; // r19
  int v11; // r11
  int v12; // r25
  float *p_d; // r30
  int v14; // r24
  _DWORD *v15; // r27
  int v16; // r10
  int v17; // r9
  unsigned int v18; // r6
  unsigned int v19; // r5
  int v20; // r4
  int v21; // r10
  unsigned int v22; // r9
  float v23; // r7
  int v24; // r6
  float v25; // r5
  int v26; // r4
  int v27; // r3
  int v28; // r11
  int v29; // r11
  int v30; // r29
  int v31; // r3
  BOOL v32; // r28
  surfaceEdge_t *list; // r9
  int v34; // r11
  _DWORD back_chain[20]; // [sp+0h] [-100h]
  idPlane v36; // [sp+50h] [-B0h] BYREF
  int v37; // [sp+60h] [-A0h]
  int v38; // [sp+64h] [-9Ch]
  int v39; // [sp+70h] [-90h]
  int v40; // [sp+74h] [-8Ch]

  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v2) = back_chain[0];
  memset(Dst: &v36, Val: -1, Size: v3);
  num = this->indexes.num;
  ((void (*)(void))RtlCheckStack12)();
  size = this->edgeIndexes.size;
  *(_DWORD *)((char *)back_chain + v6) = back_chain[0];
  if ( num <= size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->edgeIndexes,
                          newsize: num) != 0 )
  {
    v7 = this->edgeIndexes.size;
    if ( num < v7 )
      v7 = num;
    this->edgeIndexes.num = v7;
  }
  p_edges = &this->edges;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  v9 = this->indexes.num / 3;
  if ( v9 > this->edges.size )
    idList<idPlayerCoverScore_t,5>::Resize(this: (idList<idPlane,37> *)&this->edges, newsize: v9);
  memset(&v36, 0, sizeof(v36));
  idList<aas2Cluster_t,37>::Append(this: (idList<idPlane,37> *)&this->edges, obj: &v36);
  v10 = 0;
  if ( this->indexes.num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = v11;
      p_d = &v36.d;
      v14 = 3;
      v15 = (int *)((char *)this->indexes.list + v11);
      v16 = v15[1];
      v17 = v15[2];
      v18 = (unsigned int)(v16 - *v15) >> 31;
      v19 = ((unsigned int)(v17 - v16) >> 31) + 1;
      v20 = (v18 * 4) ^ 4;
      v21 = (v19 * 4) ^ 0xC;
      v22 = ((unsigned int)(v17 - *v15) >> 30) & 2;
      v23 = *(float *)&v15[v18];
      v24 = v15[v19];
      v25 = *(float *)((char *)v15 + v20);
      v26 = *(_DWORD *)((char *)v15 + v21);
      v27 = v15[v22];
      v28 = *(_DWORD *)((char *)v15 + ((v22 * 4) ^ 8));
      v36.a = v23;
      v37 = v24;
      v36.b = v25;
      v38 = v26;
      v39 = v27;
      v40 = v28;
      do
      {
        v29 = *((_DWORD *)p_d - 3);
        v30 = 4 * v29;
        v31 = *((_DWORD *)&v36.a + v29);
        v32 = v29 != *v15;
        if ( v31 == -1 )
        {
LABEL_18:
          *p_d = NAN;
          *(p_d - 1) = NAN;
          v31 = idList<aas2Cluster_t,37>::Append(
                  this: (idList<idPlane,37> *)&this->edges,
                  obj: (const idPlane *)(p_d - 3));
          v34 = v31;
          *((_DWORD *)&v36.a + v31) = *(_DWORD *)((char *)&v36.a + v30);
          *(_DWORD *)((char *)&v36.a + v30) = v31;
        }
        else
        {
          list = p_edges->list;
          while ( 1 )
          {
            if ( list[v31].verts[1] == *((_DWORD *)p_d - 2) )
            {
              v34 = v31;
              if ( list[v31].tris[v32] == -1 )
                break;
            }
            v31 = *((_DWORD *)&v36.a + v31);
            if ( v31 == -1 )
              goto LABEL_18;
          }
        }
        p_edges->list[v34].tris[v32] = v10;
        if ( v32 )
          v31 = -v31;
        --v14;
        ++v15;
        p_d += 4;
        *(int *)((char *)this->edgeIndexes.list + v12) = v31;
        v12 += 4;
      }
      while ( v14 != 0 );
      v10 += 3;
      v11 = v12;
    }
    while ( v10 < this->indexes.num );
  }
  idList<idPlayerCoverScore_t,5>::Resize(this: (idList<idPlane,37> *)&this->edges, newsize: this->edges.num);
}

