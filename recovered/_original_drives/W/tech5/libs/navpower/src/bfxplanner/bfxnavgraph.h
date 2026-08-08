
// ========================================================================
// ?AtEnd@ActiveAreasInSphereCursor@bfx@@QAA_NXZ
// EA  : 0x8325C188
// RVA : 0x0125C188
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.h
// ========================================================================

int __fastcall bfx::ActiveAreasInSphereCursor::AtEnd(bfx::ActiveAreasInSphereCursor *this)
{
  unsigned __int8 v1; // r11

  if ( !this->m_staticAreaCursor.m_atEnd )
    return 0;
  v1 = 1;
  if ( this->m_allocatedAreasCC.m_i < this->m_allocatedAreasCC.m_pArray->m_size )
    return 0;
  return v1;
}


// ========================================================================
// ?AddAdjacentNavGraphRecord@NavGraph@bfx@@QAAXPAV12@@Z
// EA  : 0x83277E38
// RVA : 0x01277E38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.h
// ========================================================================

void __fastcall bfx::NavGraph::AddAdjacentNavGraphRecord(
        bfx::NavGraph *this,
        bfx::NavGraph *pNavGraph,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  bfx::Array<bfx::Space *> *p_m_adjacentNavGraphs; // r3
  bfx::NavGraph **m_data; // r11
  int v16; // r10

  a14 = (bfx::Space *)pNavGraph;
  if ( pNavGraph != this )
  {
    p_m_adjacentNavGraphs = (bfx::Array<bfx::Space *> *)&this->m_adjacentNavGraphs;
    m_data = (bfx::NavGraph **)p_m_adjacentNavGraphs->m_data;
    v16 = (int)&p_m_adjacentNavGraphs->m_data[p_m_adjacentNavGraphs->m_size];
    if ( p_m_adjacentNavGraphs->m_data == (bfx::Space **)v16 )
    {
LABEL_5:
      bfx::Array<bfx::Portal *>::push_back(this: p_m_adjacentNavGraphs, val: &a14);
    }
    else
    {
      while ( *m_data != pNavGraph )
      {
        if ( ++m_data == (bfx::NavGraph **)v16 )
          goto LABEL_5;
      }
    }
  }
}

