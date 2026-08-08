
// ========================================================================
// ?SwapEdgeInAEL@idCutterClip@@AAAXPAUEdge_t@1@0@Z
// EA  : 0x827B3B08
// RVA : 0x007B3B08
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::SwapEdgeInAEL(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2)
{
  idCutterClip::Edge_t *nextAEL; // r10
  idCutterClip::Edge_t *v4; // r11
  idCutterClip::Edge_t *prevAEL; // r10
  idCutterClip::Edge_t *v6; // r11
  idCutterClip::Edge_t *v7; // r9
  idCutterClip::Edge_t *v8; // r11

  nextAEL = edge1->nextAEL;
  if ( nextAEL != nullptr || edge1->prevAEL != nullptr )
  {
    v4 = edge2->nextAEL;
    if ( v4 != nullptr || edge2->prevAEL != nullptr )
    {
      if ( nextAEL == edge2 )
      {
        if ( v4 != nullptr )
          v4->prevAEL = edge1;
        prevAEL = edge1->prevAEL;
        if ( prevAEL != nullptr )
          prevAEL->nextAEL = edge2;
        edge2->nextAEL = edge1;
        edge2->prevAEL = prevAEL;
        edge1->prevAEL = edge2;
        edge1->nextAEL = v4;
      }
      else if ( v4 == edge1 )
      {
        if ( nextAEL != nullptr )
          nextAEL->prevAEL = edge2;
        v6 = edge2->prevAEL;
        if ( v6 != nullptr )
          v6->nextAEL = edge1;
        edge1->nextAEL = edge2;
        edge1->prevAEL = v6;
        edge2->prevAEL = edge1;
        edge2->nextAEL = nextAEL;
      }
      else
      {
        v7 = edge1->prevAEL;
        edge1->nextAEL = v4;
        if ( v4 != nullptr )
          v4->prevAEL = edge1;
        v8 = edge2->prevAEL;
        edge1->prevAEL = v8;
        if ( v8 != nullptr )
          v8->nextAEL = edge1;
        edge2->nextAEL = nextAEL;
        if ( nextAEL != nullptr )
          nextAEL->prevAEL = edge2;
        edge2->prevAEL = v7;
        if ( v7 != nullptr )
          v7->nextAEL = edge2;
      }
      if ( edge1->prevAEL != nullptr )
      {
        if ( edge2->prevAEL == nullptr )
          this->activeEdges = edge2;
      }
      else
      {
        this->activeEdges = edge1;
      }
    }
  }
}


// ========================================================================
// ?SwapEdgeInSEL@idCutterClip@@AAAXPAUEdge_t@1@0@Z
// EA  : 0x827B3C18
// RVA : 0x007B3C18
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::SwapEdgeInSEL(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2)
{
  idCutterClip::Edge_t *nextSEL; // r10
  idCutterClip::Edge_t *v4; // r11
  idCutterClip::Edge_t *prevSEL; // r10
  idCutterClip::Edge_t *v6; // r11
  idCutterClip::Edge_t *v7; // r9
  idCutterClip::Edge_t *v8; // r11

  nextSEL = edge1->nextSEL;
  if ( nextSEL != nullptr || edge1->prevSEL != nullptr )
  {
    v4 = edge2->nextSEL;
    if ( v4 != nullptr || edge2->prevSEL != nullptr )
    {
      if ( nextSEL == edge2 )
      {
        if ( v4 != nullptr )
          v4->prevSEL = edge1;
        prevSEL = edge1->prevSEL;
        if ( prevSEL != nullptr )
          prevSEL->nextSEL = edge2;
        edge2->nextSEL = edge1;
        edge2->prevSEL = prevSEL;
        edge1->prevSEL = edge2;
        edge1->nextSEL = v4;
      }
      else if ( v4 == edge1 )
      {
        if ( nextSEL != nullptr )
          nextSEL->prevSEL = edge2;
        v6 = edge2->prevSEL;
        if ( v6 != nullptr )
          v6->nextSEL = edge1;
        edge1->nextSEL = edge2;
        edge1->prevSEL = v6;
        edge2->prevSEL = edge1;
        edge2->nextSEL = nextSEL;
      }
      else
      {
        v7 = edge1->prevSEL;
        edge1->nextSEL = v4;
        if ( v4 != nullptr )
          v4->prevSEL = edge1;
        v8 = edge2->prevSEL;
        edge1->prevSEL = v8;
        if ( v8 != nullptr )
          v8->nextSEL = edge1;
        edge2->nextSEL = nextSEL;
        if ( nextSEL != nullptr )
          nextSEL->prevSEL = edge2;
        edge2->prevSEL = v7;
        if ( v7 != nullptr )
          v7->nextSEL = edge2;
      }
      if ( edge1->prevSEL != nullptr )
      {
        if ( edge2->prevSEL == nullptr )
          this->sortedEdges = edge2;
      }
      else
      {
        this->sortedEdges = edge1;
      }
    }
  }
}


// ========================================================================
// ?AddEdgeToAEL@idCutterClip@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827B3D28
// RVA : 0x007B3D28
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddEdgeToAEL(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  idCutterClip::Edge_t *activeEdges; // r11
  unsigned int x; // r10
  unsigned int v4; // r8
  char v5; // r10
  idCutterClip::Edge_t **p_nextAEL; // r9
  idCutterClip::Edge_t *v7; // r7
  idCutterClip::Edge_t *v8; // r11
  unsigned int v9; // r10
  char v10; // r10

  edge->prevAEL = nullptr;
  edge->nextAEL = nullptr;
  activeEdges = this->activeEdges;
  if ( activeEdges == nullptr )
    goto LABEL_7;
  x = activeEdges->current.x;
  v4 = edge->current.x;
  if ( x == v4 )
    v5 = ((((int)edge->deltaX ^ (int)activeEdges->deltaX) >= 0)
        + ((int)activeEdges->deltaX >= (unsigned int)(int)edge->deltaX))
       & 1;
  else
    v5 = ((((x ^ v4) & 0x80000000) == 0) + (v4 >= x)) & 1;
  if ( v5 != 0 )
  {
    edge->nextAEL = activeEdges;
    this->activeEdges->prevAEL = edge;
LABEL_7:
    this->activeEdges = edge;
    return;
  }
  p_nextAEL = &activeEdges->nextAEL;
  v7 = this->activeEdges;
  if ( activeEdges->nextAEL != nullptr )
  {
    do
    {
      v8 = *p_nextAEL;
      v9 = (*p_nextAEL)->current.x;
      if ( v9 == v4 )
        v10 = ((((int)edge->deltaX ^ (int)v8->deltaX) >= 0) + ((int)v8->deltaX >= (unsigned int)(int)edge->deltaX)) & 1;
      else
        v10 = ((((v9 ^ v4) & 0x80000000) == 0) + (v4 >= v9)) & 1;
      if ( v10 != 0 )
        break;
      p_nextAEL = &v8->nextAEL;
      v7 = v8;
    }
    while ( v8->nextAEL != nullptr );
  }
  edge->nextAEL = *p_nextAEL;
  if ( *p_nextAEL != nullptr )
    (*p_nextAEL)->prevAEL = edge;
  edge->prevAEL = v7;
  *p_nextAEL = edge;
}


// ========================================================================
// ?RemoveEdgeFromAEL@idCutterClip@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827B3E70
// RVA : 0x007B3E70
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::RemoveEdgeFromAEL(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  idCutterClip::Edge_t *prevAEL; // r11
  idCutterClip::Edge_t *nextAEL; // r10

  prevAEL = edge->prevAEL;
  nextAEL = edge->nextAEL;
  if ( prevAEL != nullptr || nextAEL != nullptr || edge == this->activeEdges )
  {
    edge->nextAEL = nullptr;
    edge->prevAEL = nullptr;
    if ( prevAEL != nullptr )
      prevAEL->nextAEL = nextAEL;
    if ( nextAEL != nullptr )
      nextAEL->prevAEL = prevAEL;
    if ( prevAEL == nullptr )
      this->activeEdges = nextAEL;
  }
}


// ========================================================================
// ?FindBottom@idCutterClip@@CAPAUPolygonPoint_t@1@PAU21@@Z
// EA  : 0x827B3EC8
// RVA : 0x007B3EC8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::PolygonPoint_t *__fastcall idCutterClip::FindBottom(idCutterClip::PolygonPoint_t *point)
{
  idCutterClip::PolygonPoint_t *next; // r11
  idCutterClip::PolygonPoint_t *i; // r8
  int y; // r10
  int v4; // r9

  next = point->next;
  for ( i = point; next != i; next = next->next )
  {
    y = next->pos.y;
    v4 = point->pos.y;
    if ( y > v4 || y == v4 && next->pos.x < point->pos.x )
      point = next;
  }
  return point;
}


// ========================================================================
// ?IsClockwise@idCutterClip@@CA_NPBUPolygonPoint_t@1@@Z
// EA  : 0x827B3F10
// RVA : 0x007B3F10
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

unsigned int __fastcall idCutterClip::IsClockwise(const idCutterClip::PolygonPoint_t *points)
{
  idCutterClip::PolygonPoint_t *next; // r11
  const idCutterClip::PolygonPoint_t *v2; // r10
  int v3; // r9
  int x; // r5
  int v5; // r4
  bool v6; // zf

  next = points->next;
  if ( points == points->next || next->next == points )
    return 0;
  v2 = points;
  v3 = 0;
  do
  {
    x = v2->pos.x;
    v5 = next->pos.x * v2->pos.y;
    v2 = next;
    v3 += next->pos.y * x - v5;
    v6 = next != points;
    next = next->next;
  }
  while ( v6 );
  return (-v3 & (unsigned int)~v3) >> 31;
}


// ========================================================================
// ?IsTopHorizontal@idCutterClip@@ABA_NH@Z
// EA  : 0x827B3F78
// RVA : 0x007B3F78
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::IsTopHorizontal(idCutterClip *this, int x)
{
  idCutterClip::Edge_t *sortedEdges; // r8
  int v3; // r10
  int v4; // r11
  int v5; // r9

  sortedEdges = this->sortedEdges;
  if ( sortedEdges == nullptr )
    return 1;
  while ( 1 )
  {
    v3 = sortedEdges->current.x;
    v4 = sortedEdges->top.x;
    v5 = v3;
    if ( v3 >= v4 )
      v5 = sortedEdges->top.x;
    if ( x >= v5 )
    {
      if ( v3 > v4 )
        v4 = sortedEdges->current.x;
      if ( x <= v4 )
        break;
    }
    sortedEdges = sortedEdges->nextSEL;
    if ( sortedEdges == nullptr )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?FixupIntersections@idCutterClip@@AAA_NXZ
// EA  : 0x827B3FD8
// RVA : 0x007B3FD8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idCutterClip::FixupIntersections(idCutterClip *this)
{
  idCutterClip::Edge_t *activeEdges; // r10
  idCutterClip::Edge_t *v3; // r7
  idCutterClip::Edge_t *i; // r11
  idCutterClip::IntersectNode_t *intersectNodes; // r8
  idCutterClip::IntersectNode_t *j; // r11
  idCutterClip::Edge_t *edge1; // r4
  idCutterClip::Edge_t *edge2; // r5
  int v9; // r4
  idCutterClip::Edge_t *v10; // r10
  idCutterClip::Edge_t *v11; // r9
  idCutterClip::Edge_t *v12; // r9
  idCutterClip::Edge_t *v13; // r6
  idCutterClip::Edge_t *v14; // r4
  idCutterClip::Edge_t *v15; // r4
  idCutterClip::IntersectNode_t **v16; // r8
  idCutterClip::Edge_t *v17; // r11
  idCutterClip::Edge_t *v18; // r10
  unsigned __int8 v19; // r11
  bool v20; // zf

  if ( this->intersectNodes->next == nullptr )
    return 1;
  activeEdges = this->activeEdges;
  v3 = nullptr;
  this->sortedEdges = activeEdges;
  if ( activeEdges != nullptr )
  {
    for ( i = activeEdges->nextAEL; i != nullptr; i = i->nextAEL )
    {
      i->prevSEL = activeEdges;
      activeEdges->nextSEL = i;
      activeEdges = i;
    }
    this->sortedEdges->prevSEL = nullptr;
    activeEdges->nextSEL = nullptr;
  }
  intersectNodes = this->intersectNodes;
  for ( j = intersectNodes->next; intersectNodes->next != nullptr; j = intersectNodes->next )
  {
    edge1 = intersectNodes->edge1;
    edge2 = intersectNodes->edge2;
    if ( edge1->prevSEL != edge2 && *(idCutterClip::Edge_t **)(v9 + 28) != edge2 )
    {
      while ( 1 )
      {
        v10 = j->edge1;
        v11 = j->edge2;
        if ( v10->nextSEL == v11 || v10->prevSEL == v11 )
          break;
        j = j->next;
        if ( j == nullptr )
          return 0;
      }
      v12 = intersectNodes->edge1;
      intersectNodes->edge1 = j->edge1;
      j->edge1 = v12;
      v13 = intersectNodes->edge2;
      intersectNodes->edge2 = j->edge2;
      j->edge2 = v13;
      *(idVec2i *)(&this - 1) = intersectNodes->pos;
      intersectNodes->pos.x = j->pos.x;
      intersectNodes->pos.y = j->pos.y;
      j->pos = *(idVec2i *)(&this - 1);
      v14 = intersectNodes->edge1;
      edge2 = intersectNodes->edge2;
    }
    idCutterClip::SwapEdgeInSEL(this, edge1: v15, edge2);
    intersectNodes = *v16;
  }
  this->sortedEdges = v3;
  v17 = intersectNodes->edge1;
  v18 = intersectNodes->edge2;
  if ( v17->prevSEL == v18 )
    return 1;
  v20 = v17->nextSEL != v18;
  v19 = (unsigned __int8)v3;
  if ( !v20 )
    return 1;
  return v19;
}


// ========================================================================
// ?PointInPolygon@idCutterClip@@CA_NABVidVec2i@@PBUPolygonPoint_t@1@@Z
// EA  : 0x827B4150
// RVA : 0x007B4150
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idCutterClip::PointInPolygon(const idVec2i *pos, const idCutterClip::PolygonPoint_t *point)
{
  int y; // r11
  const idCutterClip::PolygonPoint_t *v4; // r7
  BOOL result; // r3
  idVec2i v6; // r9 OVERLAPPED
  const idCutterClip::PolygonPoint_t **v7; // r7 OVERLAPPED
  int v8; // r10
  signed int v9; // r8
  int v10; // r9
  int v11; // r5
  int x; // [sp+8h] [-18h]

  y = pos->y;
  v4 = point;
  result = false;
  do
  {
    v6 = v4->pos;
    *(idVec2i *)&v6.y = v4->prev->pos;
    x = v6.x;
    v8 = v6.y;
    if ( v6.y > y )
    {
      if ( v6.x > y )
        goto LABEL_9;
LABEL_6:
      if ( y >= v6.y )
        goto LABEL_9;
      goto LABEL_7;
    }
    if ( y >= v6.x )
      goto LABEL_6;
LABEL_7:
    v9 = v6.x - v6.y;
    v10 = pos->x - x;
    v11 = (y - v8) * ((_DWORD)v7 - x);
    __twllei(v9, 0);
    __twlgei(v9 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
    if ( v10 < v11 / v9 )
      result = (_cntlzw(result) & 0x20) != 0;
LABEL_9:
    v4 = *v7;
  }
  while ( v4 != point );
  return result;
}


// ========================================================================
// ?CalculateTopX@idCutterClip@@CAHPBUEdge_t@1@H@Z
// EA  : 0x827B4208
// RVA : 0x007B4208
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::CalculateTopX(const idCutterClip::Edge_t *edge, int y, long double a3, int a4, __int64 a5)
{
  long double v7; // fp2

  if ( edge->top.y == y )
    return edge->top.x * idCutterClip::precisionModifier;
  LODWORD(a5) = (y - edge->bottom.y) * idCutterClip::precisionModifier;
  *(double *)&a3 = (float)((float)((float)a5 * edge->deltaX) + (float)0.5);
  v7 = floor(x: a3);
  return edge->bottom.x * idCutterClip::precisionModifier + (int)(float)*(double *)&v7;
}


// ========================================================================
// ?FixHoleLinkage_r@idCutterClip@@AAAXPAUPolygon_t@1@@Z
// EA  : 0x827B4370
// RVA : 0x007B4370
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::FixHoleLinkage_r(idCutterClip *this, idCutterClip::Polygon_t *polygon)
{
  idCutterClip::PolygonPoint_t *bottomPoint; // r11
  idCutterClip::Polygon_t *firstLeft; // r31
  idCutterClip::Polygon_t *i; // r11

  bottomPoint = polygon->bottomPoint;
  if ( bottomPoint != nullptr )
    firstLeft = this->polygons.list[bottomPoint->index]->firstLeft;
  else
    firstLeft = polygon;
  if ( firstLeft != nullptr )
  {
    for ( i = firstLeft->appendLink; i != nullptr; i = i->appendLink )
      firstLeft = i;
    if ( firstLeft == polygon )
    {
      firstLeft = nullptr;
    }
    else if ( firstLeft->hole )
    {
      idCutterClip::FixHoleLinkage_r(this, polygon: firstLeft);
      firstLeft = firstLeft->firstLeft;
    }
  }
  polygon->firstLeft = firstLeft;
  polygon->appendLink = nullptr;
  if ( firstLeft == nullptr )
    polygon->hole = false;
}


// ========================================================================
// ?GetNumPolygons@idCutterClip@@QBAHXZ
// EA  : 0x827B4418
// RVA : 0x007B4418
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::GetNumPolygons(idCutterClip *this)
{
  return this->nestedPolygons.num;
}


// ========================================================================
// ?GetConnectedPolygons@idCutterClip@@QBAHXZ
// EA  : 0x827B4420
// RVA : 0x007B4420
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::GetConnectedPolygons(idCutterClip *this)
{
  return this->polygons.num;
}


// ========================================================================
// ?IsPolygonPoint@idCutterClip@@CA_NABVidVec2i@@PBUPolygonPoint_t@1@@Z
// EA  : 0x827B4428
// RVA : 0x007B4428
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::IsPolygonPoint(const idVec2i *pos, const idCutterClip::PolygonPoint_t *point)
{
  const idCutterClip::PolygonPoint_t *v2; // r11
  char v3; // r10

  v2 = point;
  while ( 1 )
  {
    if ( pos->x != v2->pos.x || (v3 = 1, pos->y != v2->pos.y) )
      v3 = 0;
    if ( v3 != 0 )
      break;
    v2 = v2->next;
    if ( v2 == point )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsContributing@idCutterClip@@CA_NW4clipMode_t@@PAUEdge_t@1@@Z
// EA  : 0x827B4480
// RVA : 0x007B4480
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::IsContributing(unsigned int clipMode, idCutterClip::Edge_t *edge)
{
  unsigned __int8 v2; // r11
  unsigned __int8 v4; // r11
  unsigned __int8 v5; // r11
  int v6; // r7
  unsigned __int8 v7; // r11
  unsigned __int8 v8; // r11

  if ( clipMode > 3 )
    return 0;
  if ( clipMode == 1 )
  {
    if ( abs16(edge->windingCount) != 1 )
      return 0;
    v5 = 1;
    if ( edge->windingCount2 != 0 )
      return 0;
    return v5;
  }
  else if ( clipMode == 2 )
  {
    v6 = abs16(edge->windingCount);
    if ( (*((_WORD *)edge + 36) & 0x4000) == 0x4000 )
    {
      if ( v6 != 1 )
        return 0;
      v7 = 1;
      if ( edge->windingCount2 != 0 )
        return 0;
      return v7;
    }
    else
    {
      if ( v6 != 1 )
        return 0;
      v8 = 1;
      if ( edge->windingCount2 == 0 )
        return 0;
      return v8;
    }
  }
  else if ( clipMode != 0 )
  {
    return (_cntlzw(abs16(edge->windingCount) - 1) & 0x20) != 0;
  }
  else if ( (*((_WORD *)edge + 36) & 0x4000) == 0x4000 )
  {
    if ( abs16(edge->windingCount) != 1 )
      return 0;
    v2 = 1;
    if ( edge->windingCount2 == 0 )
      return 0;
    return v2;
  }
  else
  {
    if ( abs16(edge->windingCount2) == 0 )
      return 0;
    v4 = 1;
    if ( abs16(edge->windingCount) != 1 )
      return 0;
    return v4;
  }
}


// ========================================================================
// ?SlopesEqual@idCutterClip@@CA_NPAUEdge_t@1@0@Z
// EA  : 0x827B45F8
// RVA : 0x007B45F8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

BOOL __fastcall idCutterClip::SlopesEqual(idCutterClip::Edge_t *edge1, idCutterClip::Edge_t *edge2)
{
  int x; // r11
  int v4; // r10

  if ( edge1->bottom.y == edge1->top.y )
    return (_cntlzw(edge2->top.y - edge2->bottom.y) & 0x20) != 0;
  x = edge1->bottom.x;
  v4 = edge1->top.x;
  if ( x == v4 )
    return (_cntlzw(edge2->top.x - edge2->bottom.x) & 0x20) != 0;
  else
    return (_cntlzw(
              (edge2->top.x - edge2->bottom.x) * (edge1->top.y - edge1->bottom.y)
            - (edge2->top.y - edge2->bottom.y) * (v4 - x))
          & 0x20) != 0;
}


// ========================================================================
// ?IsSegmentOverlapping@idCutterClip@@CA_NABVidVec2i@@000PAV2@1@Z
// EA  : 0x827B4688
// RVA : 0x007B4688
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::IsSegmentOverlapping(
        const idVec2i *p1a,
        const idVec2i *p1b,
        const idVec2i *p2a,
        const idVec2i *p2b,
        idVec2i *overlap1,
        idVec2i *overlap2)
{
  int y; // r11
  int v7; // r30
  int x; // r9
  int v9; // r31
  signed int v10; // r10
  int v11; // r11
  bool v12; // zf
  int v13; // r29
  int v14; // r30
  int v15; // r10
  int v16; // r31
  int v17; // r9
  int v18; // r11
  const idVec2i *v19; // r11
  idVec2i v20; // r28
  int v21; // r10
  int v22; // r11
  const idVec2i *v23; // r11
  idVec2i v24; // r11
  unsigned int v25; // r11
  unsigned int v26; // r10
  int v27; // r10
  int v28; // r29
  int v29; // r30
  int v30; // r11
  const idVec2i *v31; // r11
  idVec2i v32; // r28
  int v33; // r10
  int v34; // r11
  const idVec2i *v35; // r11
  idVec2i v36; // r11
  idVec2i back_chain; // [sp+0h] [-40h]
  idVec2i back_chaina; // [sp+0h] [-40h]
  int v40; // [sp+Ch] [-34h]

  y = p1a->y;
  v7 = p1b->y;
  x = p1a->x;
  v9 = p1b->x;
  v10 = y - v7;
  v12 = y == v7;
  v11 = p1a->x - p1b->x;
  if ( v12 || (__twllei(v10, 0), __twlgei(v10 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF), (int)abs32(v11 / v10) > 1) )
  {
    v27 = p1a->x;
    if ( x >= v9 )
      v27 = p1b->x;
    v28 = p2a->x;
    v29 = p2b->x;
    v30 = p2a->x;
    if ( p2a->x >= p2b->x )
      v30 = p2b->x;
    if ( v27 <= v30 )
    {
      v31 = p2a;
      if ( v28 >= v29 )
        v31 = p2b;
    }
    else if ( x >= v9 )
    {
      v31 = p1b;
    }
    else
    {
      v31 = p1a;
    }
    v32 = *v31;
    v33 = p1a->x;
    back_chaina = *v31;
    if ( x <= v9 )
      v33 = p1b->x;
    v34 = p2a->x;
    if ( v28 <= v29 )
      v34 = p2b->x;
    if ( v33 >= v34 )
    {
      v35 = p2b;
      if ( v28 >= v29 )
        v35 = p2a;
    }
    else if ( x >= v9 )
    {
      v35 = p1a;
    }
    else
    {
      v35 = p1b;
    }
    v36 = *v35;
    if ( overlap1 != nullptr )
      *overlap1 = v32;
    if ( overlap2 != nullptr )
      *overlap2 = v36;
    v25 = v36.x;
    v26 = back_chaina.x;
  }
  else
  {
    v13 = p1a->y;
    v14 = p1b->y;
    v15 = v13;
    if ( v13 <= v14 )
      v15 = p1b->y;
    v16 = p2a->y;
    v17 = p2b->y;
    v18 = v16;
    if ( v16 <= v17 )
      v18 = p2b->y;
    if ( v15 >= v18 )
    {
      v19 = p2b;
      if ( v16 >= v17 )
        v19 = p2a;
    }
    else if ( v13 >= v14 )
    {
      v19 = p1a;
    }
    else
    {
      v19 = p1b;
    }
    v20 = *v19;
    v21 = p1a->y;
    back_chain = *v19;
    if ( v13 >= v14 )
      v21 = p1b->y;
    v22 = p2a->y;
    if ( v16 >= v17 )
      v22 = p2b->y;
    if ( v21 <= v22 )
    {
      v23 = p2a;
      if ( v16 >= v17 )
        v23 = p2b;
    }
    else if ( v13 >= v14 )
    {
      v23 = p1b;
    }
    else
    {
      v23 = p1a;
    }
    v24 = *v23;
    v40 = v24.y;
    if ( overlap1 != nullptr )
      *overlap1 = v20;
    if ( overlap2 != nullptr )
      *overlap2 = v24;
    v25 = back_chain.y;
    v26 = v40;
  }
  return ((((v25 ^ v26) & 0x80000000) == 0) + (v26 >= v25)) & 1;
}


// ========================================================================
// ?SetHoleState@idCutterClip@@AAAXPBUEdge_t@1@PAUPolygon_t@1@@Z
// EA  : 0x827B48B0
// RVA : 0x007B48B0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::SetHoleState(
        idCutterClip *this,
        const idCutterClip::Edge_t *edge,
        idCutterClip::Polygon_t *polygon)
{
  idCutterClip::Edge_t *prevAEL; // r10
  bool i; // r9
  int outIndex; // r11

  prevAEL = edge->prevAEL;
  for ( i = false; prevAEL != nullptr; prevAEL = prevAEL->prevAEL )
  {
    outIndex = prevAEL->outIndex;
    if ( outIndex != -1 )
    {
      i = (_cntlzw(i) & 0x20) != 0;
      if ( polygon->firstLeft == nullptr )
        polygon->firstLeft = this->polygons.list[outIndex];
    }
  }
  polygon->hole = i;
}


// ========================================================================
// ?FindBottomPolygon@idCutterClip@@CAPBUPolygon_t@1@PBU21@0@Z
// EA  : 0x827B4910
// RVA : 0x007B4910
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

const idCutterClip::Polygon_t *__fastcall idCutterClip::FindBottomPolygon(
        const idCutterClip::Polygon_t *polygon1,
        const idCutterClip::Polygon_t *polygon2)
{
  idVec2i pos; // r8
  int y; // r11
  idCutterClip::Edge_t *bottomEdge2; // r10
  idCutterClip::Edge_t *v5; // r11

  pos = polygon2->bottomPoint->pos;
  y = polygon1->bottomPoint->pos.y;
  if ( y <= pos.y )
  {
    if ( y < pos.y )
      return polygon2;
    if ( pos.y >= pos.x )
    {
      if ( pos.y > pos.x )
        return polygon2;
      bottomEdge2 = polygon1->bottomEdge2;
      if ( bottomEdge2 == nullptr )
        return polygon2;
      v5 = polygon2->bottomEdge2;
      if ( v5 != nullptr )
      {
        _FP10 = (float)(polygon1->bottomEdge1->deltaX - bottomEdge2->deltaX);
        _FP9 = (float)(polygon2->bottomEdge1->deltaX - v5->deltaX);
        __asm
        {
          fsel      f8, f10, f12, f0
          fsel      f7, f9, f11, f13
        }
        if ( _FP7 > _FP8 )
          return polygon2;
      }
    }
  }
  return polygon1;
}


// ========================================================================
// ?AppendPolygon@idCutterClip@@AAAXPAUEdge_t@1@0@Z
// EA  : 0x827B49A0
// RVA : 0x007B49A0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AppendPolygon(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2)
{
  idCutterClip::Polygon_t *v5; // r7
  int v6; // r5
  const idCutterClip::Polygon_t *v7; // r4
  const idCutterClip::Polygon_t *BottomPolygon; // r3
  bool hole; // r11
  int v10; // r29
  idCutterClip::PolygonPoint_t *points; // r9
  idCutterClip::PolygonPoint_t *v12; // r11
  idCutterClip::PolygonPoint_t *prev; // r31
  idCutterClip::PolygonPoint_t *v14; // r6
  idCutterClip::PolygonPoint_t *v15; // r10
  idCutterClip::PolygonPoint_t *next; // r8
  idCutterClip::PolygonPoint_t *v17; // r27
  bool v18; // cr58
  idCutterClip::PolygonPoint_t *bottomPoint; // r11
  int index; // r10
  idCutterClip::Polygon_t *firstLeft; // r11
  int v22; // r9
  int v23; // r8
  __int16 outIndex; // r6
  idCutterClip::Edge_t *activeEdges; // r11
  __int16 v26; // r10
  int v27; // r7
  int v28; // r11
  idCutterClip::JoinRecord_t *v29; // r10
  idCutterClip::JoinRecord_t *v30; // r10
  int v31; // r10
  idCutterClip::HorizontalJoinRecord_t *v32; // r11

  BottomPolygon = idCutterClip::FindBottomPolygon(
                    polygon1: this->polygons.list[edge1->outIndex],
                    polygon2: this->polygons.list[edge2->outIndex]);
  if ( v5->hole != v7->hole )
  {
    hole = BottomPolygon->hole;
    if ( BottomPolygon == v7 )
      v5->hole = hole;
    else
      v7->hole = hole;
  }
  v10 = *((unsigned __int16 *)edge1 + 36) >> 15;
  points = v5->points;
  v12 = v7->points;
  prev = points->prev;
  v14 = v12->prev;
  if ( v10 == *(unsigned __int16 *)(v6 + 72) >> 15 )
  {
    v15 = v7->points;
    do
    {
      next = v15->next;
      v17 = v15->prev;
      v18 = v15->next == v12;
      v15->prev = v15->next;
      v15->next = v17;
      v15 = next;
    }
    while ( !v18 );
    v12->next = points;
    points->prev = v12;
    prev->next = v14;
    v14->prev = prev;
    if ( v10 == 0 )
      v5->points = v14;
  }
  else
  {
    v14->next = points;
    points->prev = v14;
    v12->prev = prev;
    prev->next = v12;
    if ( v10 == 0 )
      v5->points = v12;
  }
  if ( BottomPolygon == v7 )
  {
    bottomPoint = v7->bottomPoint;
    index = v5->index;
    v5->bottomPoint = bottomPoint;
    bottomPoint->index = index;
    v5->bottomEdge1 = v7->bottomEdge1;
    v5->bottomEdge2 = v7->bottomEdge2;
    firstLeft = v7->firstLeft;
    if ( firstLeft != v5 )
      v5->firstLeft = firstLeft;
  }
  v22 = 0;
  v7->appendLink = nullptr;
  v7->bottomPoint = nullptr;
  v7->points = nullptr;
  v23 = *(__int16 *)(v6 + 68);
  outIndex = edge1->outIndex;
  edge1->outIndex = -1;
  *(_WORD *)(v6 + 68) = -1;
  activeEdges = this->activeEdges;
  if ( activeEdges != nullptr )
  {
    while ( activeEdges->outIndex != v23 )
    {
      activeEdges = activeEdges->nextAEL;
      if ( activeEdges == nullptr )
        goto LABEL_20;
    }
    v26 = *((_WORD *)activeEdges + 36);
    activeEdges->outIndex = outIndex;
    *((_WORD *)activeEdges + 36) = ((_WORD)v10 << 15) | v26 & 0x7FFF;
  }
LABEL_20:
  v27 = 0;
  if ( this->joins.num > 0 )
  {
    v28 = 0;
    do
    {
      v29 = this->joins.list[v28];
      if ( v29->polyIndex1 == v23 )
        v29->polyIndex1 = outIndex;
      v30 = this->joins.list[v28];
      if ( v30->polyIndex2 == v23 )
        v30->polyIndex2 = outIndex;
      ++v27;
      ++v28;
    }
    while ( v27 < this->joins.num );
  }
  if ( this->horizontalJoins.num > 0 )
  {
    v31 = 0;
    do
    {
      v32 = this->horizontalJoins.list[v31];
      if ( v32->savedIndex == v23 )
        v32->savedIndex = outIndex;
      ++v22;
      ++v31;
    }
    while ( v22 < this->horizontalJoins.num );
  }
}


// ========================================================================
// ?SetWindingCount@idCutterClip@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827B4BD8
// RVA : 0x007B4BD8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::SetWindingCount(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  idCutterClip::Edge_t *prevAEL; // r7
  BOOL v3; // r11
  __int16 v4; // r11
  idCutterClip::Edge_t *nextAEL; // r11
  fillType_t fillTypeSubject; // r11
  __int16 windingCount; // r8
  int windingDelta; // r10
  int v9; // r9
  bool v10; // cr57
  int v11; // r9
  int v12; // r11
  fillType_t fillTypeClip; // r10

  prevAEL = edge->prevAEL;
  if ( prevAEL != nullptr )
  {
    v3 = (*((_WORD *)edge + 36) & 0x4000) != 0;
    while ( ((*((_WORD *)prevAEL + 36) & 0x4000) != 0) != v3 )
    {
      prevAEL = prevAEL->prevAEL;
      if ( prevAEL == nullptr )
        goto LABEL_5;
    }
    if ( v3 )
      fillTypeSubject = this->fillTypeSubject;
    else
      fillTypeSubject = this->fillTypeClip;
    if ( fillTypeSubject != FILLTYPE_EVEN_ODD )
    {
      if ( fillTypeSubject == FILLTYPE_NON_ZERO )
      {
        windingCount = prevAEL->windingCount;
        windingDelta = prevAEL->windingDelta;
        v9 = abs16(windingCount);
        v10 = v9 > 1;
        if ( windingCount * windingDelta >= 0 )
        {
          if ( v9 <= 1 || edge->windingDelta * windingDelta >= 0 )
          {
            v12 = edge->windingDelta + windingCount;
            if ( v12 != 0 )
              edge->windingCount = v12;
            else
              edge->windingCount = windingCount;
          }
          else
          {
            edge->windingCount = windingCount;
          }
        }
        else
        {
          v11 = edge->windingDelta;
          if ( v10 )
          {
            if ( v11 * windingDelta >= 0 )
              edge->windingCount = v11 * windingCount;
            else
              edge->windingCount = windingCount;
          }
          else
          {
            edge->windingCount = v11 + windingCount + windingDelta;
          }
        }
      }
    }
    else
    {
      edge->windingCount = 1;
    }
    edge->windingCount2 = prevAEL->windingCount2;
    nextAEL = prevAEL->nextAEL;
  }
  else
  {
LABEL_5:
    v4 = edge->windingDelta;
    edge->windingCount2 = 0;
    edge->windingCount = v4;
    nextAEL = this->activeEdges;
  }
  if ( (*((_WORD *)edge + 36) & 0x4000) == 0x4000 )
    fillTypeClip = this->fillTypeClip;
  else
    fillTypeClip = this->fillTypeSubject;
  if ( fillTypeClip != FILLTYPE_EVEN_ODD )
  {
    if ( fillTypeClip == FILLTYPE_NON_ZERO && nextAEL != edge )
    {
      do
      {
        edge->windingCount2 += nextAEL->windingDelta;
        nextAEL = nextAEL->nextAEL;
      }
      while ( nextAEL != edge );
    }
  }
  else
  {
    for ( ; nextAEL != edge; nextAEL = nextAEL->nextAEL )
      edge->windingCount2 = (_cntlzw((unsigned __int16)edge->windingCount2) & 0x20) != 0;
    if ( edge->windingCount2 != 0 )
      edge->windingCount2 = 1;
  }
}


// ========================================================================
// ?ClearHorizontalJoinRecords@idCutterClip@@AAAXXZ
// EA  : 0x827B5020
// RVA : 0x007B5020
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ClearHorizontalJoinRecords(idCutterClip *this)
{
  int v2; // r10
  int v3; // r11
  idCutterClip::HorizontalJoinRecord_t *v4; // r7
  idCutterClip::HorizontalJoinRecord_t **list; // r6
  int v6; // r5
  idCutterClip::HorizontalJoinRecord_t **v7; // r4

  v2 = 0;
  if ( this->horizontalJoins.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = this->horizontalJoins.list[v3];
      v4->next = this->horizontalJoinRecordsPool;
      list = this->horizontalJoins.list;
      v6 = this->numHorizontalJoinRecords - 1;
      this->horizontalJoinRecordsPool = v4;
      this->numHorizontalJoinRecords = v6;
      list[v3++] = nullptr;
    }
    while ( v2 < this->horizontalJoins.num );
  }
  if ( this->horizontalJoins.listStatic == 0 || this->horizontalJoins.listStatic == 2 )
  {
    v7 = this->horizontalJoins.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->horizontalJoins.list = nullptr;
    this->horizontalJoins.size = 0;
  }
  this->horizontalJoins.num = 0;
}


// ========================================================================
// ?ClearJoinRecords@idCutterClip@@AAAXXZ
// EA  : 0x827B50E0
// RVA : 0x007B50E0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ClearJoinRecords(idCutterClip *this)
{
  int v2; // r10
  int v3; // r11
  idCutterClip::JoinRecord_t *v4; // r7
  idCutterClip::JoinRecord_t **list; // r6
  int v6; // r5
  idCutterClip::JoinRecord_t **v7; // r4

  v2 = 0;
  if ( this->joins.num > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = this->joins.list[v3];
      v4->next = this->joinRecordsPool;
      list = this->joins.list;
      v6 = this->numJoinRecords - 1;
      this->joinRecordsPool = v4;
      this->numJoinRecords = v6;
      list[v3++] = nullptr;
    }
    while ( v2 < this->joins.num );
  }
  if ( this->joins.listStatic == 0 || this->joins.listStatic == 2 )
  {
    v7 = this->joins.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->joins.list = nullptr;
    this->joins.size = 0;
  }
  this->joins.num = 0;
}


// ========================================================================
// ?ClearNestedPolygons@idCutterClip@@AAAXXZ
// EA  : 0x827B51A0
// RVA : 0x007B51A0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ClearNestedPolygons(idCutterClip *this)
{
  int v2; // r9
  int v3; // r11
  idCutterClip::NestedPolygon_t *v4; // r8
  idCutterClip::NestedPolygon_t **list; // r6
  int v6; // r5
  idCutterClip::NestedPolygon_t **v7; // r4

  v2 = 0;
  if ( this->nestedPolygons.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->nestedPolygons.list[v3];
      if ( v4 != nullptr )
      {
        v4->next = this->nestedPolygonsPool;
        list = this->nestedPolygons.list;
        v6 = this->numNestedPolygons - 1;
        this->nestedPolygonsPool = v4;
        this->numNestedPolygons = v6;
        list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->nestedPolygons.num );
  }
  if ( this->nestedPolygons.listStatic == 0 || this->nestedPolygons.listStatic == 2 )
  {
    v7 = this->nestedPolygons.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->nestedPolygons.list = nullptr;
    this->nestedPolygons.size = 0;
  }
  this->nestedPolygons.num = 0;
}


// ========================================================================
// ?ClearPolygons@idCutterClip@@AAAXXZ
// EA  : 0x827B5270
// RVA : 0x007B5270
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ClearPolygons(idCutterClip *this)
{
  int v2; // r8
  int v3; // r10
  idCutterClip::Polygon_t *v4; // r9
  idCutterClip::PolygonPoint_t *points; // r11
  idCutterClip::PolygonPoint_t *v6; // r7
  int v7; // r5
  idCutterClip::Polygon_t *v8; // r3
  idCutterClip::Polygon_t **list; // r9
  int v10; // r7
  idCutterClip::Polygon_t **v11; // r4

  v2 = 0;
  if ( this->polygons.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->polygons.list[v3];
      if ( v4 != nullptr )
      {
        points = v4->points;
        if ( points != nullptr )
        {
          points->prev->next = nullptr;
          do
          {
            v6 = points;
            points = points->next;
            v6->next = nullptr;
            v6->prev = nullptr;
            v6->next = this->polygonPointsPool;
            v7 = this->numPolygonPoints - 1;
            this->polygonPointsPool = v6;
            this->numPolygonPoints = v7;
          }
          while ( points != nullptr );
        }
        this->polygons.list[v3]->points = nullptr;
        this->polygons.list[v3]->bottomPoint = nullptr;
        v8 = this->polygons.list[v3];
        v8->appendLink = this->polygonsPool;
        list = this->polygons.list;
        v10 = this->numPolygons - 1;
        this->polygonsPool = v8;
        this->numPolygons = v10;
        list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->polygons.num );
  }
  if ( this->polygons.listStatic == 0 || this->polygons.listStatic == 2 )
  {
    v11 = this->polygons.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->polygons.list = nullptr;
    this->polygons.size = 0;
  }
  this->polygons.num = 0;
}


// ========================================================================
// ?ClearPolygonPoints@idCutterClip@@AAAXXZ
// EA  : 0x827B53A0
// RVA : 0x007B53A0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ClearPolygonPoints(idCutterClip *this)
{
  int v2; // r8
  int v3; // r9
  idCutterClip::PolygonPoint_t *v4; // r10
  idCutterClip::PolygonPoint_t *v5; // r11
  idCutterClip::PolygonPoint_t *v6; // r7
  int v7; // r5
  idCutterClip::PolygonPoint_t **list; // r4

  v2 = 0;
  if ( this->polygonPoints.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->polygonPoints.list[v3];
      if ( v4 != nullptr )
      {
        v5 = this->polygonPoints.list[v3];
        v4->prev->next = nullptr;
        do
        {
          v6 = v5;
          v5 = v5->next;
          v6->next = nullptr;
          v6->prev = nullptr;
          v6->next = this->polygonPointsPool;
          v7 = this->numPolygonPoints - 1;
          this->polygonPointsPool = v6;
          this->numPolygonPoints = v7;
        }
        while ( v5 != nullptr );
        this->polygonPoints.list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->polygonPoints.num );
  }
  if ( this->polygonPoints.listStatic == 0 || this->polygonPoints.listStatic == 2 )
  {
    list = this->polygonPoints.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->polygonPoints.list = nullptr;
    this->polygonPoints.size = 0;
  }
  this->polygonPoints.num = 0;
}


// ========================================================================
// ?EdgeEdgeIntersection@idCutterClip@@CA_NPAUEdge_t@1@0PAVidVec2i@@@Z
// EA  : 0x827B5498
// RVA : 0x007B5498
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idCutterClip::EdgeEdgeIntersection(
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        idVec2i *pos)
{
  __int64 v6; // r7
  __int64 v7; // r5 OVERLAPPED
  int y; // r11
  __int64 v10; // r7
  long double v11; // fp2
  long double v12; // fp2
  __int64 v13; // r9
  int x; // r6
  long double v15; // fp2
  long double v16; // fp2
  __int64 v17; // r9
  double deltaX; // fp0
  __int64 v19; // r4
  double v20; // fp5
  long double v21; // fp2
  double v22; // fp30
  long double v23; // fp2
  double v24; // fp6
  long double v25; // fp2
  int v26; // r8
  char v27; // r10
  int v28; // r9
  char v29; // r7
  char v30; // r10
  char v31; // r11
  bool v32; // zf
  unsigned __int8 v33; // r11
  idVec2i v34; // [sp+50h] [-50h]

  if ( idCutterClip::SlopesEqual(edge1, edge2) )
    return 0;
  if ( __fabs(edge1->deltaX) >= 0.00000011920929 )
  {
    if ( __fabs(edge2->deltaX) >= 0.00000011920929 )
    {
      HIDWORD(v17) = edge1->bottom.x;
      LODWORD(v17) = edge2->bottom.x;
      deltaX = edge1->deltaX;
      LODWORD(v7) = HIDWORD(v17);
      LODWORD(v6) = edge2->bottom.y;
      v20 = (double)v7;
      LODWORD(v19) = edge1->bottom.y;
      HIDWORD(v19) = 0x82000000;
      *((double *)&v21 + 1) = (float)v6;
      v22 = (float)((float)((float)-(float)((float)((float)v6 * edge2->deltaX) - (float)v17)
                          - (float)-(float)((float)((float)v19 * edge1->deltaX) - (float)v20))
                  / (float)(edge1->deltaX - edge2->deltaX));
      *(double *)&v21 = (float)((float)((float)((float)deltaX
                                              * (float)((float)((float)-(float)((float)((float)v6 * edge2->deltaX)
                                                                              - (float)v17)
                                                              - (float)-(float)((float)((float)v19 * (float)deltaX)
                                                                              - (float)v20))
                                                      / (float)((float)deltaX - edge2->deltaX)))
                                      - (float)((float)((float)v19 * (float)deltaX) - (float)v20))
                              + (float)0.5);
      v23 = floor(x: v21);
      v24 = (float)*(double *)&v23;
      *(double *)&v23 = (float)((float)v22 + (float)0.5);
      v34.x = (int)v24;
      v25 = floor(x: v23);
      y = (int)(float)*(double *)&v25;
    }
    else
    {
      v34.x = edge2->bottom.x;
      if ( (*((_WORD *)edge1 + 36) & 0x2000) != 0 )
      {
        y = edge1->bottom.y;
      }
      else
      {
        HIDWORD(v13) = edge1->bottom.y;
        LODWORD(v13) = edge2->bottom.x;
        x = edge1->bottom.x;
        LODWORD(v7) = HIDWORD(v13);
        *((double *)&v15 + 1) = (float)-(float)((float)((float)*(__int64 *)((char *)&v7 - 4)
                                                      * (float)((float)1.0 / edge1->deltaX))
                                              - (float)v7);
        *(double *)&v15 = (float)((float)((float)((float)v13 * (float)((float)1.0 / edge1->deltaX))
                                        - (float)((float)((float)*(__int64 *)((char *)&v7 - 4)
                                                        * (float)((float)1.0 / edge1->deltaX))
                                                - (float)v7))
                                + (float)0.5);
        v16 = floor(x: v15);
        y = (int)(float)*(double *)&v16;
      }
    }
  }
  else
  {
    v34.x = edge1->bottom.x;
    if ( (*((_WORD *)edge2 + 36) & 0x2000) != 0 )
    {
      y = edge2->bottom.y;
    }
    else
    {
      LODWORD(v10) = edge1->bottom.x;
      *(__int64 *)((char *)&v7 - 4) = (__int64)edge2->bottom;
      *((double *)&v11 + 1) = (float)-(float)((float)((float)v7 * (float)((float)1.0 / edge2->deltaX))
                                            - (float)*(__int64 *)((char *)&v7 - 4));
      *(double *)&v11 = (float)((float)((float)((float)v10 * (float)((float)1.0 / edge2->deltaX))
                                      - (float)((float)((float)v7 * (float)((float)1.0 / edge2->deltaX))
                                              - (float)*(__int64 *)((char *)&v7 - 4)))
                              + (float)0.5);
      v12 = floor(x: v11);
      y = (int)(float)*(double *)&v12;
    }
  }
  v26 = edge1->top.y;
  v34.y = y;
  if ( y != v26 || y < edge2->top.y || (v27 = 1, edge1->tmpX <= edge2->tmpX) )
    v27 = 0;
  v28 = edge2->top.y;
  v29 = v27;
  if ( y != v28 || y < v26 || (v30 = 1, edge1->tmpX <= edge2->tmpX) )
    v30 = 0;
  if ( y <= v26 || (v32 = y > v28, v31 = 1, !v32) )
    v31 = 0;
  if ( pos != nullptr )
    *pos = v34;
  if ( v29 != 0 )
    return 1;
  if ( v30 != 0 )
    return 1;
  v32 = v31 == 0;
  v33 = 0;
  if ( !v32 )
    return 1;
  return v33;
}


// ========================================================================
// ?FixupPolygon@idCutterClip@@AAAXPAUPolygon_t@1@@Z
// EA  : 0x827B5838
// RVA : 0x007B5838
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::FixupPolygon(idCutterClip *this, idCutterClip::Polygon_t *polygon)
{
  idCutterClip::PolygonPoint_t *bottomPoint; // r10
  idCutterClip::PolygonPoint_t *v3; // r30
  idCutterClip::PolygonPoint_t *prev; // r11
  idCutterClip::PolygonPoint_t *next; // r7
  idCutterClip::PolygonPoint_t *i; // r31
  int x; // r5
  int v8; // r11
  char v9; // r8
  int y; // r6
  int v11; // r8
  bool v12; // r11
  int v13; // r8
  unsigned int v14; // r11
  idCutterClip::PolygonPoint_t *v15; // r9
  int v16; // r7

  bottomPoint = polygon->bottomPoint;
  v3 = nullptr;
  prev = bottomPoint->prev;
  next = bottomPoint->next;
  for ( i = prev; bottomPoint != prev; i = prev )
  {
    if ( i == next )
      break;
    x = next->pos.x;
    v8 = bottomPoint->pos.x;
    if ( v8 != x || (v9 = 1, bottomPoint->pos.y != next->pos.y) )
      v9 = 0;
    if ( v9 != 0
      || ((y = i->pos.y, v11 = bottomPoint->pos.y, y != v11)
        ? ((v13 = i->pos.x) != v8
         ? (v14 = (v8 - x) * (y - bottomPoint->pos.y) - (bottomPoint->pos.y - next->pos.y) * (v13 - v8))
         : (v14 = x - v8),
           v12 = (_cntlzw(v14) & 0x20) != 0)
        : (v12 = (_cntlzw(next->pos.y - v11) & 0x20) != 0),
          v12) )
    {
      v3 = nullptr;
      if ( bottomPoint == polygon->bottomPoint )
      {
        if ( i->pos.y <= next->pos.y )
          polygon->bottomPoint = next;
        else
          polygon->bottomPoint = i;
        polygon->bottomPoint->index = polygon->index;
      }
      i->next = bottomPoint->next;
      next->prev = bottomPoint->prev;
      bottomPoint = bottomPoint->prev;
    }
    else
    {
      if ( bottomPoint == v3 )
        goto LABEL_28;
      if ( v3 == nullptr )
        v3 = bottomPoint;
      bottomPoint = next;
    }
    prev = bottomPoint->prev;
    next = bottomPoint->next;
  }
  prev->next = nullptr;
  do
  {
    v15 = bottomPoint;
    bottomPoint = bottomPoint->next;
    v15->next = nullptr;
    v15->prev = nullptr;
    v15->next = this->polygonPointsPool;
    v16 = this->numPolygonPoints - 1;
    this->polygonPointsPool = v15;
    this->numPolygonPoints = v16;
  }
  while ( bottomPoint != nullptr );
  polygon->bottomPoint = nullptr;
LABEL_28:
  polygon->points = polygon->bottomPoint;
}


// ========================================================================
// ?FindSegment@idCutterClip@@CA_NAAPAUPolygonPoint_t@1@AAVidVec2i@@1@Z
// EA  : 0x827B59D0
// RVA : 0x007B59D0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::FindSegment(idCutterClip::PolygonPoint_t **point, idVec2i *p1, idVec2i *p2)
{
  idCutterClip::PolygonPoint_t *v3; // r29
  idVec2i *v6; // r4
  int y; // r9
  idVec2i *p_pos; // r5
  int v9; // r11
  idCutterClip::PolygonPoint_t *prev; // r10
  const idVec2i *v11; // r6
  bool v12; // r10
  bool v13; // r11
  int x; // r10
  idCutterClip::PolygonPoint_t *next; // r10
  __int128 v17; // r11
  idVec2i v18; // [sp+50h] [-40h] BYREF
  idVec2i v19; // [sp+58h] [-38h] BYREF

  v3 = *point;
  v6 = p2;
  if ( *point == nullptr )
    return 0;
  while ( 1 )
  {
    y = p1->y;
    p_pos = &(*point)->pos;
    v9 = v6->y;
    prev = (*point)->prev;
    v11 = &prev->pos;
    if ( y == v9 )
      v12 = (_cntlzw(prev->pos.y - (*point)->pos.y) & 0x20) != 0;
    else
      v12 = p1->x == v6->x
          ? (_cntlzw(v11->x - p_pos->x) & 0x20) != 0
          : (_cntlzw((p_pos->x - v11->x) * (y - v9) - ((*point)->pos.y - prev->pos.y) * (p1->x - v6->x)) & 0x20) != 0;
    if ( v12 )
    {
      if ( y == v9 )
      {
        v13 = (_cntlzw((*point)->pos.y - v9) & 0x20) != 0;
      }
      else
      {
        x = v6->x;
        v13 = p1->x == v6->x
            ? (_cntlzw(p_pos->x - x) & 0x20) != 0
            : (_cntlzw((x - p_pos->x) * (y - v9) - (v9 - (*point)->pos.y) * (p1->x - x)) & 0x20) != 0;
      }
      if ( v13
        && (unsigned __int8)idCutterClip::IsSegmentOverlapping(
                              p1a: p1,
                              p1b: v6,
                              p2a: p_pos,
                              p2b: v11,
                              overlap1: &v18,
                              overlap2: &v19) != 0 )
      {
        break;
      }
    }
    next = (*point)->next;
    *point = next;
    if ( next == v3 )
      return 0;
  }
  LODWORD(v17) = v18.y;
  *(idVec2i *)((char *)&v17 + 4) = v19;
  *p1 = (idVec2i)v17;
  *v6 = *(idVec2i *)((char *)&v17 + 4);
  return 1;
}


// ========================================================================
// ??0idCutterClip@@QAA@XZ
// EA  : 0x827B5C30
// RVA : 0x007B5C30
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip *__fastcall idCutterClip::idCutterClip(idCutterClip *this)
{
  idList<idVehicleState *,5> *p_edges; // r27
  char v3; // r11

  this->memoryPeek = 0;
  p_edges = (idList<idVehicleState *,5> *)&this->edges;
  this->memoryCurrent = 0;
  this->numEdges = 0;
  this->maxEdges = 0;
  this->numLocalMinima = 0;
  this->maxLocalMinima = 0;
  this->numScanbeams = 0;
  this->maxScanbeams = 0;
  this->numPolygons = 0;
  this->maxPolygons = 0;
  this->numPolygonPoints = 0;
  this->maxPolygonPoints = 0;
  this->numNestedPolygons = 0;
  this->maxNestedPolygons = 0;
  this->numJoinRecords = 0;
  this->maxJoinRecords = 0;
  this->numHorizontalJoinRecords = 0;
  this->maxHorizontalJoinRecords = 0;
  this->numIntersectNode = 0;
  this->maxIntersectNode = 0;
  this->edgesPool = nullptr;
  this->scanbeamsPool = nullptr;
  this->polygonsPool = nullptr;
  this->polygonPointsPool = nullptr;
  this->nestedPolygonsPool = nullptr;
  this->localMinimasPool = nullptr;
  this->intersectNodesPool = nullptr;
  this->joinRecordsPool = nullptr;
  this->horizontalJoinRecordsPool = nullptr;
  this->currentLocalMinima = nullptr;
  this->localMinimaList = nullptr;
  this->scanbeams = nullptr;
  this->activeEdges = nullptr;
  this->sortedEdges = nullptr;
  this->intersectNodes = nullptr;
  this->currentNestedPolygon = nullptr;
  this->currentInnerPolygon = nullptr;
  this->edges.list = nullptr;
  this->edges.granularity = 0;
  this->edges.memTag = 5;
  this->edges.listStatic = 0;
  this->edges.size = 0;
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  this->polygonPoints.list = nullptr;
  this->polygonPoints.granularity = 0;
  this->polygonPoints.memTag = 5;
  this->polygonPoints.listStatic = 0;
  this->polygonPoints.size = 0;
  this->polygonPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->polygonPoints);
  this->polygons.list = nullptr;
  this->polygons.granularity = 0;
  this->polygons.memTag = 5;
  this->polygons.listStatic = 0;
  this->polygons.size = 0;
  this->polygons.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->polygons);
  this->nestedPolygons.list = nullptr;
  this->nestedPolygons.granularity = 0;
  this->nestedPolygons.memTag = 5;
  this->nestedPolygons.listStatic = 0;
  this->nestedPolygons.size = 0;
  this->nestedPolygons.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nestedPolygons);
  this->joins.list = nullptr;
  this->joins.granularity = 0;
  this->joins.memTag = 5;
  this->joins.listStatic = 0;
  this->joins.size = 0;
  this->joins.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joins);
  this->horizontalJoins.list = nullptr;
  this->horizontalJoins.granularity = 0;
  this->horizontalJoins.memTag = 5;
  this->horizontalJoins.listStatic = 0;
  this->horizontalJoins.size = 0;
  this->horizontalJoins.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->horizontalJoins);
  this->poolAllocations.list = nullptr;
  this->poolAllocations.granularity = 0;
  this->poolAllocations.memTag = 5;
  this->poolAllocations.listStatic = 0;
  this->poolAllocations.size = 0;
  this->poolAllocations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->poolAllocations);
  v3 = *((_BYTE *)this + 272);
  this->clipMode = CLIPMODE_INTERSECT;
  *((_BYTE *)this + 272) = v3 & 0x7F;
  idList<idThread *,58>::Clear(this: p_edges);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->polygons);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->polygonPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nestedPolygons);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->joins);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->horizontalJoins);
  return this;
}


// ========================================================================
// __unwind$224736
// EA  : 0x827B5E40
// RVA : 0x007B5E40
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224736()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 148));
}


// ========================================================================
// __unwind$224737
// EA  : 0x827B5E6C
// RVA : 0x007B5E6C
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224737()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 164));
}


// ========================================================================
// __unwind$224738
// EA  : 0x827B5E98
// RVA : 0x007B5E98
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224738()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 180));
}


// ========================================================================
// __unwind$224739
// EA  : 0x827B5EC4
// RVA : 0x007B5EC4
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224739()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 196));
}


// ========================================================================
// __unwind$224740
// EA  : 0x827B5EF0
// RVA : 0x007B5EF0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224740()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 212));
}


// ========================================================================
// __unwind$224741
// EA  : 0x827B5F1C
// RVA : 0x007B5F1C
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224741()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 228));
}


// ========================================================================
// __unwind$224742
// EA  : 0x827B5F48
// RVA : 0x007B5F48
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_224742()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 244));
}


// ========================================================================
// ?Prepare@idCutterClip@@QAAXXZ
// EA  : 0x827B5F78
// RVA : 0x007B5F78
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::Prepare(idCutterClip *this)
{
  int v2; // r10
  int v3; // r11
  idCutterClip::Edge_t *v4; // r7
  int v5; // r6
  idCutterClip::LocalMinima_t *localMinimaList; // r11
  idCutterClip::LocalMinima_t *next; // r10
  bool v8; // cr58
  int v9; // r8
  idCutterClip::IntersectNode_t *intersectNodes; // r11
  idCutterClip::IntersectNode_t *v11; // r10
  bool v12; // cr58
  int v13; // r8
  idCutterClip::Scanbeam_t *scanbeams; // r11
  idCutterClip::Scanbeam_t *v15; // r10
  bool v16; // cr58

  idCutterClip::ClearNestedPolygons(this);
  idCutterClip::ClearPolygons(this);
  idCutterClip::ClearPolygonPoints(this);
  idCutterClip::ClearHorizontalJoinRecords(this);
  idCutterClip::ClearJoinRecords(this);
  if ( this->edges.num > 0 )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      ++v2;
      v4 = this->edges.list[v3++];
      v4->next = this->edgesPool;
      v5 = this->numEdges - 1;
      this->edgesPool = v4;
      this->numEdges = v5;
    }
    while ( v2 < this->edges.num );
    if ( this->edges.size < 0 )
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
    this->edges.num = __CFADD__(-this->edges.size, this->edges.size ^ 0x80000000) ? 0 : this->edges.size;
  }
  localMinimaList = this->localMinimaList;
  if ( localMinimaList != nullptr )
  {
    do
    {
      next = localMinimaList->next;
      v8 = localMinimaList->next == nullptr;
      localMinimaList->next = this->localMinimasPool;
      v9 = this->numLocalMinima - 1;
      this->localMinimasPool = localMinimaList;
      localMinimaList = next;
      this->numLocalMinima = v9;
    }
    while ( !v8 );
    this->localMinimaList = nullptr;
  }
  intersectNodes = this->intersectNodes;
  if ( intersectNodes != nullptr )
  {
    do
    {
      v11 = intersectNodes->next;
      v12 = intersectNodes->next == nullptr;
      intersectNodes->next = this->intersectNodesPool;
      v13 = this->numIntersectNode - 1;
      this->intersectNodesPool = intersectNodes;
      intersectNodes = v11;
      this->numIntersectNode = v13;
    }
    while ( !v12 );
    this->intersectNodes = nullptr;
  }
  scanbeams = this->scanbeams;
  if ( scanbeams != nullptr )
  {
    do
    {
      v15 = scanbeams->next;
      v16 = scanbeams->next == nullptr;
      scanbeams->next = this->scanbeamsPool;
      this->scanbeamsPool = scanbeams;
      scanbeams = v15;
      --this->numScanbeams;
    }
    while ( !v16 );
    this->scanbeams = nullptr;
  }
  this->activeEdges = nullptr;
  this->sortedEdges = nullptr;
  this->currentLocalMinima = nullptr;
}


// ========================================================================
// ?AllocEdge@idCutterClip@@AAAPAUEdge_t@1@XZ
// EA  : 0x827B60E8
// RVA : 0x007B60E8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::Edge_t *__fastcall idCutterClip::AllocEdge(idCutterClip *this)
{
  idCutterClip::Edge_t *v2; // r3
  idCutterClip::Edge_t *v3; // r10
  idCutterClip::Edge_t *v4; // r11
  int i; // ctr
  int maxEdges; // r10
  int v7; // r11
  idCutterClip::Edge_t *result; // r3
  idCutterClip::Edge_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->edgesPool == nullptr )
  {
    v2 = (idCutterClip::Edge_t *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(191) : TAG_GAME",
                                   size: 0x14000u,
                                   tag: TAG_GAME,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    this->edgesPool = v2;
    v3 = v2;
    v4 = v2 + 1;
    for ( i = 1023; i != 0; --i )
    {
      v3->next = v4;
      v3 = v4++;
    }
    v9 = v2;
    v3->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxEdges = this->maxEdges;
  v7 = this->numEdges + 1;
  this->numEdges = v7;
  if ( maxEdges > v7 )
    v7 = maxEdges;
  result = this->edgesPool;
  this->maxEdges = v7;
  this->edgesPool = result->next;
  return result;
}


// ========================================================================
// ?AllocLocalMinima@idCutterClip@@AAAPAULocalMinima_t@1@XZ
// EA  : 0x827B61B8
// RVA : 0x007B61B8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::LocalMinima_t *__fastcall idCutterClip::AllocLocalMinima(idCutterClip *this)
{
  idCutterClip::LocalMinima_t *v2; // r3
  idCutterClip::LocalMinima_t *v3; // r10
  idCutterClip::LocalMinima_t *v4; // r11
  int i; // ctr
  int maxLocalMinima; // r10
  int v7; // r11
  idCutterClip::LocalMinima_t *result; // r3
  idCutterClip::LocalMinima_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->localMinimasPool == nullptr )
  {
    v2 = (idCutterClip::LocalMinima_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(222) : TAG_GAME",
                                          size: 0x1000u,
                                          tag: TAG_GAME,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
    this->localMinimasPool = v2;
    v3 = v2;
    v4 = v2 + 1;
    for ( i = 255; i != 0; --i )
    {
      v3->next = v4;
      v3 = v4++;
    }
    v9 = v2;
    v3->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxLocalMinima = this->maxLocalMinima;
  v7 = this->numLocalMinima + 1;
  this->numLocalMinima = v7;
  if ( maxLocalMinima > v7 )
    v7 = maxLocalMinima;
  result = this->localMinimasPool;
  this->maxLocalMinima = v7;
  this->localMinimasPool = result->next;
  return result;
}


// ========================================================================
// ?AllocScanbeam@idCutterClip@@AAAPAUScanbeam_t@1@XZ
// EA  : 0x827B6280
// RVA : 0x007B6280
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::Scanbeam_t *__fastcall idCutterClip::AllocScanbeam(idCutterClip *this)
{
  idCutterClip::Scanbeam_t *v2; // r3
  idCutterClip::Scanbeam_t *v3; // r11
  idCutterClip::Scanbeam_t *v4; // r8
  int *p_y; // r11
  int i; // ctr
  idCutterClip::Scanbeam_t *v7; // r9
  idCutterClip::Scanbeam_t *v8; // r8
  int *v9; // r9
  int *v10; // r8
  _DWORD *v11; // r7
  idCutterClip::Scanbeam_t **v12; // r8
  idCutterClip::Scanbeam_t *v13; // r9
  int maxScanbeams; // r10
  int v15; // r11
  idCutterClip::Scanbeam_t *result; // r3
  idCutterClip::Scanbeam_t *v17; // [sp+50h] [-20h] BYREF

  if ( this->scanbeamsPool == nullptr )
  {
    v2 = (idCutterClip::Scanbeam_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(255) : TAG_GAME",
                                       size: 0x800u,
                                       tag: TAG_GAME,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
    {
      v3 = v2;
      v2->next = nullptr;
      v2->y = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->scanbeamsPool = v3;
    v4 = v3;
    p_y = &v2[3].y;
    for ( i = 51; i != 0; --i )
    {
      if ( p_y == (int *)20 )
      {
        v7 = nullptr;
      }
      else
      {
        v7 = (idCutterClip::Scanbeam_t *)(p_y - 5);
        *(p_y - 5) = 0;
        *(p_y - 4) = 0;
      }
      v4->next = v7;
      v8 = v7;
      if ( p_y == (int *)12 )
      {
        v9 = nullptr;
      }
      else
      {
        *(p_y - 3) = 0;
        v9 = p_y - 3;
        *(p_y - 2) = 0;
      }
      v8->next = (idCutterClip::Scanbeam_t *)v9;
      if ( p_y == (int *)4 )
      {
        v10 = nullptr;
      }
      else
      {
        *(p_y - 1) = 0;
        v10 = p_y - 1;
        *p_y = 0;
      }
      *v9 = (int)v10;
      v11 = v10;
      if ( p_y == (int *)-4 )
      {
        v12 = nullptr;
      }
      else
      {
        p_y[1] = 0;
        v12 = (idCutterClip::Scanbeam_t **)(p_y + 1);
        p_y[2] = 0;
      }
      v13 = (idCutterClip::Scanbeam_t *)(p_y + 3);
      *v11 = v12;
      if ( p_y == (int *)-12 )
      {
        v13 = nullptr;
      }
      else
      {
        v13->next = nullptr;
        p_y[4] = 0;
      }
      *v12 = v13;
      v4 = v13;
      p_y += 10;
    }
    v17 = v2;
    v13->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v17);
  }
  maxScanbeams = this->maxScanbeams;
  v15 = this->numScanbeams + 1;
  this->numScanbeams = v15;
  if ( maxScanbeams > v15 )
    v15 = maxScanbeams;
  result = this->scanbeamsPool;
  this->maxScanbeams = v15;
  this->scanbeamsPool = result->next;
  return result;
}


// ========================================================================
// ?AllocPolygon@idCutterClip@@AAAPAUPolygon_t@1@XZ
// EA  : 0x827B6408
// RVA : 0x007B6408
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::Polygon_t *__fastcall idCutterClip::AllocPolygon(idCutterClip *this)
{
  idCutterClip::Polygon_t *v2; // r3
  idCutterClip::Polygon_t *v3; // r11
  idCutterClip::Polygon_t *polygonsPool; // r10
  int i; // ctr
  int maxPolygons; // r10
  int v7; // r11
  idCutterClip::Polygon_t *result; // r3
  idCutterClip::Polygon_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->polygonsPool == nullptr )
  {
    v2 = (idCutterClip::Polygon_t *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(285) : TAG_GAME",
                                      size: 0x480u,
                                      tag: TAG_GAME,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
    this->polygonsPool = v2;
    v2->firstLeft = nullptr;
    v3 = v2 + 1;
    this->polygonsPool->appendLink = nullptr;
    polygonsPool = this->polygonsPool;
    for ( i = 31; i != 0; --i )
    {
      polygonsPool->appendLink = v3;
      polygonsPool->firstLeft = nullptr;
      polygonsPool = v3++;
    }
    v9 = v2;
    polygonsPool->appendLink = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxPolygons = this->maxPolygons;
  v7 = this->numPolygons + 1;
  this->numPolygons = v7;
  if ( maxPolygons > v7 )
    v7 = maxPolygons;
  result = this->polygonsPool;
  this->maxPolygons = v7;
  this->polygonsPool = result->appendLink;
  result->firstLeft = nullptr;
  result->appendLink = nullptr;
  result->bottomPoint = nullptr;
  result->points = nullptr;
  result->hole = false;
  result->connected = false;
  result->index = -1;
  return result;
}


// ========================================================================
// ?AllocPolygonPoint@idCutterClip@@AAAPAUPolygonPoint_t@1@XZ
// EA  : 0x827B6508
// RVA : 0x007B6508
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::PolygonPoint_t *__fastcall idCutterClip::AllocPolygonPoint(idCutterClip *this)
{
  idCutterClip::PolygonPoint_t *v2; // r3
  idCutterClip::PolygonPoint_t *v3; // r11
  idCutterClip::PolygonPoint_t *polygonPointsPool; // r9
  int i; // ctr
  idCutterClip::PolygonPoint_t *v6; // r10
  idCutterClip::PolygonPoint_t *v7; // r9
  idCutterClip::PolygonPoint_t *v8; // r10
  idCutterClip::PolygonPoint_t *v9; // r10
  int maxPolygonPoints; // r10
  int v11; // r11
  idCutterClip::PolygonPoint_t *result; // r3
  idCutterClip::PolygonPoint_t *v13; // [sp+50h] [-20h] BYREF

  if ( this->polygonPointsPool == nullptr )
  {
    v2 = (idCutterClip::PolygonPoint_t *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(330) : TAG_GAME",
                                           size: 0x5000u,
                                           tag: TAG_GAME,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
    this->polygonPointsPool = v2;
    v2->prev = nullptr;
    v3 = v2 + 3;
    this->polygonPointsPool->next = nullptr;
    polygonPointsPool = this->polygonPointsPool;
    for ( i = 341; i != 0; --i )
    {
      polygonPointsPool->prev = nullptr;
      v6 = v3 - 2;
      if ( v3 == (idCutterClip::PolygonPoint_t *)40 )
        v6 = nullptr;
      polygonPointsPool->next = v6;
      v7 = v6;
      v6->prev = nullptr;
      v8 = v3 - 1;
      if ( v3 == (idCutterClip::PolygonPoint_t *)20 )
        v8 = nullptr;
      v7->next = v8;
      v8->prev = nullptr;
      polygonPointsPool = v3;
      v8->next = v3;
      v9 = v3;
      v3 += 3;
    }
    v13 = v2;
    v9->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v13);
  }
  maxPolygonPoints = this->maxPolygonPoints;
  v11 = this->numPolygonPoints + 1;
  this->numPolygonPoints = v11;
  if ( maxPolygonPoints > v11 )
    v11 = maxPolygonPoints;
  result = this->polygonPointsPool;
  this->maxPolygonPoints = v11;
  this->polygonPointsPool = result->next;
  result->next = nullptr;
  result->prev = nullptr;
  return result;
}


// ========================================================================
// ?AllocNestedPolygon@idCutterClip@@AAAPAUNestedPolygon_t@1@XZ
// EA  : 0x827B6628
// RVA : 0x007B6628
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::NestedPolygon_t *__fastcall idCutterClip::AllocNestedPolygon(idCutterClip *this)
{
  idCutterClip::NestedPolygon_t *v2; // r3
  idCutterClip::NestedPolygon_t *v3; // r11
  idCutterClip::NestedPolygon_t *nestedPolygonsPool; // r10
  int i; // ctr
  int maxNestedPolygons; // r10
  int v7; // r11
  idCutterClip::NestedPolygon_t *result; // r3
  idCutterClip::NestedPolygon_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->nestedPolygonsPool == nullptr )
  {
    v2 = (idCutterClip::NestedPolygon_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(367) : TAG_GAME",
                                            size: 0x180u,
                                            tag: TAG_GAME,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
    this->nestedPolygonsPool = v2;
    v3 = v2 + 1;
    v2->next = nullptr;
    nestedPolygonsPool = this->nestedPolygonsPool;
    for ( i = 31; i != 0; --i )
    {
      nestedPolygonsPool->next = v3;
      nestedPolygonsPool = v3++;
    }
    v9 = v2;
    nestedPolygonsPool->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxNestedPolygons = this->maxNestedPolygons;
  v7 = this->numNestedPolygons + 1;
  this->numNestedPolygons = v7;
  if ( maxNestedPolygons > v7 )
    v7 = maxNestedPolygons;
  result = this->nestedPolygonsPool;
  this->maxNestedPolygons = v7;
  this->nestedPolygonsPool = result->next;
  result->next = nullptr;
  result->outer = nullptr;
  result->inner = nullptr;
  return result;
}


// ========================================================================
// ?AllocJoinRecord@idCutterClip@@AAAPAUJoinRecord_t@1@XZ
// EA  : 0x827B6708
// RVA : 0x007B6708
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::JoinRecord_t *__fastcall idCutterClip::AllocJoinRecord(idCutterClip *this)
{
  idCutterClip::JoinRecord_t *v2; // r3
  idCutterClip::JoinRecord_t *v3; // r10
  idCutterClip::JoinRecord_t *v4; // r11
  int i; // ctr
  int maxJoinRecords; // r10
  int v7; // r11
  idCutterClip::JoinRecord_t *result; // r3
  idCutterClip::JoinRecord_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->joinRecordsPool == nullptr )
  {
    v2 = (idCutterClip::JoinRecord_t *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(404) : TAG_GAME",
                                         size: 0x1400u,
                                         tag: TAG_GAME,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
    this->joinRecordsPool = v2;
    v3 = v2;
    v4 = v2 + 1;
    for ( i = 127; i != 0; --i )
    {
      v3->next = v4;
      v3 = v4++;
    }
    v9 = v2;
    v3->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxJoinRecords = this->maxJoinRecords;
  v7 = this->numJoinRecords + 1;
  this->numJoinRecords = v7;
  if ( maxJoinRecords > v7 )
    v7 = maxJoinRecords;
  result = this->joinRecordsPool;
  this->maxJoinRecords = v7;
  this->joinRecordsPool = result->next;
  return result;
}


// ========================================================================
// ?AllocHorizontalJoinRecord@idCutterClip@@AAAPAUHorizontalJoinRecord_t@1@XZ
// EA  : 0x827B67D0
// RVA : 0x007B67D0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::HorizontalJoinRecord_t *__fastcall idCutterClip::AllocHorizontalJoinRecord(idCutterClip *this)
{
  idCutterClip::HorizontalJoinRecord_t *v2; // r3
  idCutterClip::HorizontalJoinRecord_t *v3; // r10
  idCutterClip::HorizontalJoinRecord_t *v4; // r11
  int i; // ctr
  int maxHorizontalJoinRecords; // r10
  int v7; // r11
  idCutterClip::HorizontalJoinRecord_t *result; // r3
  idCutterClip::HorizontalJoinRecord_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->horizontalJoinRecordsPool == nullptr )
  {
    v2 = (idCutterClip::HorizontalJoinRecord_t *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(434) : TAG_GAME",
                                                   size: 0x600u,
                                                   tag: TAG_GAME,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
    this->horizontalJoinRecordsPool = v2;
    v3 = v2;
    v4 = v2 + 1;
    for ( i = 127; i != 0; --i )
    {
      v3->next = v4;
      v3 = v4++;
    }
    v9 = v2;
    v3->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxHorizontalJoinRecords = this->maxHorizontalJoinRecords;
  v7 = this->numHorizontalJoinRecords + 1;
  this->numHorizontalJoinRecords = v7;
  if ( maxHorizontalJoinRecords > v7 )
    v7 = maxHorizontalJoinRecords;
  result = this->horizontalJoinRecordsPool;
  this->maxHorizontalJoinRecords = v7;
  this->horizontalJoinRecordsPool = result->next;
  return result;
}


// ========================================================================
// ?AllocIntersectNode@idCutterClip@@AAAPAUIntersectNode_t@1@XZ
// EA  : 0x827B6898
// RVA : 0x007B6898
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::IntersectNode_t *__fastcall idCutterClip::AllocIntersectNode(idCutterClip *this)
{
  idCutterClip::IntersectNode_t *v2; // r3
  idCutterClip::IntersectNode_t *v3; // r10
  idCutterClip::IntersectNode_t *v4; // r11
  int i; // ctr
  int maxIntersectNode; // r10
  int v7; // r11
  idCutterClip::IntersectNode_t *result; // r3
  idCutterClip::IntersectNode_t *v9; // [sp+50h] [-20h] BYREF

  if ( this->intersectNodesPool == nullptr )
  {
    v2 = (idCutterClip::IntersectNode_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\models\\cuttable\\CutterClip.cpp(467) : TAG_GAME",
                                            size: 0xA00u,
                                            tag: TAG_GAME,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
    this->intersectNodesPool = v2;
    v3 = v2;
    v4 = v2 + 1;
    for ( i = 127; i != 0; --i )
    {
      v3->next = v4;
      v3 = v4++;
    }
    v9 = v2;
    v3->next = nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->poolAllocations,
      obj: (const encounterGroupRole_t *)&v9);
  }
  maxIntersectNode = this->maxIntersectNode;
  v7 = this->numIntersectNode + 1;
  this->numIntersectNode = v7;
  if ( maxIntersectNode > v7 )
    v7 = maxIntersectNode;
  result = this->intersectNodesPool;
  this->maxIntersectNode = v7;
  this->intersectNodesPool = result->next;
  return result;
}


// ========================================================================
// ??1idCutterClip@@QAA@XZ
// EA  : 0x827B6968
// RVA : 0x007B6968
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::~idCutterClip(idCutterClip *this)
{
  int v2; // r28
  int v3; // r29
  void **list; // r4
  void **v5; // r4
  idCutterClip::HorizontalJoinRecord_t **v6; // r4
  idCutterClip::JoinRecord_t **v7; // r4
  idCutterClip::NestedPolygon_t **v8; // r4
  idCutterClip::Polygon_t **v9; // r4
  idCutterClip::PolygonPoint_t **v10; // r4
  idCutterClip::Edge_t **v11; // r4

  idCutterClip::ClearJoinRecords(this);
  idCutterClip::ClearHorizontalJoinRecords(this);
  idCutterClip::ClearNestedPolygons(this);
  idCutterClip::ClearPolygons(this);
  idCutterClip::ClearPolygonPoints(this);
  v2 = 0;
  if ( this->poolAllocations.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->poolAllocations.list[v3], align: ALIGN_16);
      ++v2;
      this->poolAllocations.list[v3++] = nullptr;
    }
    while ( v2 < this->poolAllocations.num );
  }
  if ( this->poolAllocations.listStatic == 0 || this->poolAllocations.listStatic == 2 )
  {
    list = this->poolAllocations.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->poolAllocations.list = nullptr;
    this->poolAllocations.size = 0;
  }
  this->poolAllocations.num = 0;
  if ( this->poolAllocations.listStatic == 0 || this->poolAllocations.listStatic == 2 )
  {
    v5 = this->poolAllocations.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->poolAllocations.list = nullptr;
    this->poolAllocations.size = 0;
  }
  this->poolAllocations.num = 0;
  if ( this->horizontalJoins.listStatic == 0 || this->horizontalJoins.listStatic == 2 )
  {
    v6 = this->horizontalJoins.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->horizontalJoins.list = nullptr;
    this->horizontalJoins.size = 0;
  }
  this->horizontalJoins.num = 0;
  if ( this->joins.listStatic == 0 || this->joins.listStatic == 2 )
  {
    v7 = this->joins.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->joins.list = nullptr;
    this->joins.size = 0;
  }
  this->joins.num = 0;
  if ( this->nestedPolygons.listStatic == 0 || this->nestedPolygons.listStatic == 2 )
  {
    v8 = this->nestedPolygons.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->nestedPolygons.list = nullptr;
    this->nestedPolygons.size = 0;
  }
  this->nestedPolygons.num = 0;
  if ( this->polygons.listStatic == 0 || this->polygons.listStatic == 2 )
  {
    v9 = this->polygons.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->polygons.list = nullptr;
    this->polygons.size = 0;
  }
  this->polygons.num = 0;
  if ( this->polygonPoints.listStatic == 0 || this->polygonPoints.listStatic == 2 )
  {
    v10 = this->polygonPoints.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->polygonPoints.list = nullptr;
    this->polygonPoints.size = 0;
  }
  this->polygonPoints.num = 0;
  if ( this->edges.listStatic == 0 || this->edges.listStatic == 2 )
  {
    v11 = this->edges.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->edges.list = nullptr;
    this->edges.size = 0;
  }
  this->edges.num = 0;
}


// ========================================================================
// __unwind$225516_0
// EA  : 0x827B6BDC
// RVA : 0x007B6BDC
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225516_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 148));
}


// ========================================================================
// __unwind$225517_0
// EA  : 0x827B6C08
// RVA : 0x007B6C08
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225517_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 164));
}


// ========================================================================
// __unwind$225518_0
// EA  : 0x827B6C34
// RVA : 0x007B6C34
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225518_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 180));
}


// ========================================================================
// __unwind$225519_0
// EA  : 0x827B6C60
// RVA : 0x007B6C60
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225519_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 196));
}


// ========================================================================
// __unwind$225520_0
// EA  : 0x827B6C8C
// RVA : 0x007B6C8C
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225520_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 212));
}


// ========================================================================
// __unwind$225521_0
// EA  : 0x827B6CB8
// RVA : 0x007B6CB8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225521_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 228));
}


// ========================================================================
// __unwind$225522
// EA  : 0x827B6CE4
// RVA : 0x007B6CE4
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_225522()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 244));
}


// ========================================================================
// ?BuildResult@idCutterClip@@AAAXXZ
// EA  : 0x827B6D10
// RVA : 0x007B6D10
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::BuildResult(idCutterClip *this)
{
  int num; // r27
  int v3; // r31
  int v4; // r11
  idCutterClip::Polygon_t *v5; // r30
  idCutterClip::PolygonPoint_t *points; // r10
  int v7; // r9
  idCutterClip::PolygonPoint_t *v8; // r11
  idCutterClip::NestedPolygon_t *v9; // r3
  idCutterClip::Polygon_t *v10; // r9
  int v11; // r10
  idCutterClip::Polygon_t *v12; // r11
  idCutterClip::NestedPolygon_t *v13; // [sp+50h] [-40h] BYREF

  num = this->polygons.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      v5 = this->polygons.list[v4];
      points = v5->points;
      if ( points == nullptr )
        break;
      v7 = 0;
      v8 = v5->points;
      do
      {
        v8 = v8->next;
        ++v7;
      }
      while ( v8 != points );
      if ( v7 >= 3 )
      {
        v9 = idCutterClip::AllocNestedPolygon(this);
        v9->outer = v5;
        v10 = nullptr;
        v13 = v9;
        v9->inner = nullptr;
        if ( v3 < num )
        {
          v11 = v3;
          do
          {
            ++v3;
            v12 = this->polygons.list[v11++];
            if ( v12->points == nullptr )
              break;
            if ( !v12->hole && v9->outer != v12 )
            {
              v12->connected = true;
              break;
            }
            if ( v10 != nullptr )
              v10->next = v12;
            v12->next = nullptr;
            v10 = v12;
            if ( v9->inner == nullptr )
              v9->inner = v12;
          }
          while ( v3 < num );
        }
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->nestedPolygons,
          obj: (const encounterGroupRole_t *)&v13);
      }
      v4 = v3;
    }
    while ( v3 < num );
  }
}


// ========================================================================
// ?AddBoundToLML@idCutterClip@@AAAPAUEdge_t@1@PAU21@@Z
// EA  : 0x827B6E20
// RVA : 0x007B6E20
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::Edge_t *__fastcall idCutterClip::AddBoundToLML(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  idCutterClip::Edge_t *next; // r31
  idCutterClip::Edge_t *v4; // r11
  idVec2i top; // r10
  int x; // r7
  idCutterClip::Edge_t *prev; // r11
  idCutterClip::LocalMinima_t *v8; // r3
  idVec2i v9; // r10
  idCutterClip::Edge_t *v10; // r11
  idCutterClip::LocalMinima_t *v11; // r10
  idCutterClip::LocalMinima_t *i; // r11
  idCutterClip::Edge_t *result; // r3
  idVec2i v14; // r10
  int y; // r7

  next = edge->next;
  edge->nextLML = nullptr;
  while ( 1 )
  {
    while ( (*((_WORD *)next + 36) & 0x2000) == 0 )
    {
      if ( next->current.y == next->prev->current.y )
        goto LABEL_9;
LABEL_8:
      next->nextLML = next->prev;
      next = next->next;
    }
    v4 = next->next;
    if ( v4->top.y < next->top.y && v4->bottom.x > next->prev->bottom.x )
      break;
    if ( next->top.x == next->prev->bottom.x )
      goto LABEL_8;
    top = next->top;
    next->top.x = next->bottom.x;
    top.x = next->bottom.y;
    next->top.y = top.x;
    next->bottom = top;
    x = next->bottom.x;
    prev = next->prev;
    next->current.y = next->bottom.y;
    next->current.x = x;
    next->nextLML = prev;
    next = next->next;
  }
LABEL_9:
  v8 = idCutterClip::AllocLocalMinima(this);
  v8->next = nullptr;
  v8->y = next->prev->bottom.y;
  if ( (*((_WORD *)next + 36) & 0x2000) != 0 && next->bottom.x != next->prev->bottom.x )
  {
    v9 = next->top;
    next->top.x = next->bottom.x;
    v9.x = next->bottom.y;
    next->top.y = v9.x;
    next->bottom = v9;
    next->current.x = next->bottom.x;
    next->current.y = next->bottom.y;
  }
  if ( (*((_WORD *)next + 36) & 0x2000) != 0 || next->deltaX < (double)next->prev->deltaX )
  {
    v10 = next->prev;
    v8->rightBound = next;
    v8->leftBound = v10;
  }
  else
  {
    v8->leftBound = next;
    v8->rightBound = next->prev;
  }
  v11 = nullptr;
  *((_WORD *)v8->leftBound + 36) &= ~0x8000u;
  *((_WORD *)v8->rightBound + 36) |= 0x8000u;
  for ( i = this->localMinimaList; i != nullptr; i = i->next )
  {
    if ( v8->y >= i->y )
      break;
    v11 = i;
  }
  v8->next = i;
  if ( v11 != nullptr )
    v11->next = v8;
  else
    this->localMinimaList = v8;
  while ( 1 )
  {
    result = next->next;
    if ( result->top.y == next->top.y && (*((_WORD *)result + 36) & 0x2000) == 0 )
      break;
    next->nextLML = result;
    next = result;
    if ( (*((_WORD *)result + 36) & 0x2000) != 0 && result->bottom.x != result->prev->top.x )
    {
      v14 = result->top;
      result->top.x = result->bottom.x;
      v14.x = result->bottom.y;
      result->top.y = v14.x;
      result->bottom = v14;
      y = result->bottom.y;
      result->current.x = result->bottom.x;
      result->current.y = y;
    }
  }
  return result;
}


// ========================================================================
// ?AddScanbeam@idCutterClip@@AAAXH@Z
// EA  : 0x827B7078
// RVA : 0x007B7078
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddScanbeam(idCutterClip *this, int y)
{
  idCutterClip::Scanbeam_t *scanbeams; // r31
  idCutterClip::Scanbeam_t *v5; // r30
  idCutterClip::Scanbeam_t *v6; // r3

  scanbeams = this->scanbeams;
  v5 = nullptr;
  if ( scanbeams == nullptr )
    goto LABEL_6;
  do
  {
    if ( y > scanbeams->y )
      break;
    v5 = scanbeams;
    scanbeams = scanbeams->next;
  }
  while ( scanbeams != nullptr );
  if ( v5 == nullptr || y != v5->y )
  {
LABEL_6:
    v6 = idCutterClip::AllocScanbeam(this);
    v6->y = y;
    v6->next = scanbeams;
    if ( v5 != nullptr )
      v5->next = v6;
    else
      this->scanbeams = v6;
  }
}


// ========================================================================
// ?AddJoinRecord@idCutterClip@@AAAXPAUEdge_t@1@0FF@Z
// EA  : 0x827B7100
// RVA : 0x007B7100
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddJoinRecord(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        __int16 outIndexEdge1,
        __int16 outIndexEdge2)
{
  idCutterClip::JoinRecord_t *v10; // r3
  int x; // r11
  idCutterClip::JoinRecord_t *v12; // [sp+50h] [-40h] BYREF

  v10 = idCutterClip::AllocJoinRecord(this);
  x = edge1->current.x;
  v12 = v10;
  v10->point1a.x = x;
  v10->point1a.y = edge1->current.y;
  v10->point1b = edge1->top;
  v10->point2a = edge2->current;
  v10->point2b = edge2->top;
  if ( outIndexEdge1 == -1 )
    v10->polyIndex1 = edge1->outIndex;
  else
    v10->polyIndex1 = outIndexEdge1;
  if ( outIndexEdge2 == -1 )
    v10->polyIndex2 = edge2->outIndex;
  else
    v10->polyIndex2 = outIndexEdge2;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->joins,
    obj: (const encounterGroupRole_t *)&v12);
}


// ========================================================================
// ?AddIntersectNode@idCutterClip@@AAAXPAUEdge_t@1@0ABVidVec2i@@@Z
// EA  : 0x827B71C8
// RVA : 0x007B71C8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddIntersectNode(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        const idVec2i *pos)
{
  idCutterClip::IntersectNode_t *v8; // r3
  idCutterClip::IntersectNode_t *v9; // r7
  int y; // r10
  idCutterClip::IntersectNode_t *intersectNodes; // r11
  unsigned int v12; // r8
  unsigned int v13; // r10
  char v14; // r9
  idCutterClip::Edge_t *v15; // r10

  v8 = idCutterClip::AllocIntersectNode(this);
  v8->edge1 = edge1;
  v9 = nullptr;
  v8->edge2 = edge2;
  v8->pos.x = pos->x;
  y = pos->y;
  v8->pos.y = y;
  v8->next = nullptr;
  intersectNodes = this->intersectNodes;
  if ( intersectNodes != nullptr )
  {
    v12 = y;
    do
    {
      v13 = intersectNodes->pos.y;
      v14 = ((((v12 ^ v13) & 0x80000000) == 0) + (v13 >= v12)) & 1;
      if ( v12 == v13 )
      {
        v15 = intersectNodes->edge1;
        v14 = (((intersectNodes->pos.x ^ v8->pos.x) >= 0) + (v8->pos.x >= (unsigned int)intersectNodes->pos.x)) & 1;
        if ( edge1 == v15 || edge2 == v15 || (v15 = intersectNodes->edge2, edge1 == v15) || edge2 == v15 )
        {
          if ( v15->deltaX > 0.0 )
            v14 = (_cntlzw(
                     (((intersectNodes->pos.x ^ v8->pos.x) >= 0) + (v8->pos.x >= (unsigned int)intersectNodes->pos.x))
                   & 1)
                 & 0x20) != 0;
        }
      }
      if ( v14 != 0 )
        break;
      v9 = intersectNodes;
      intersectNodes = intersectNodes->next;
    }
    while ( intersectNodes != nullptr );
  }
  v8->next = intersectNodes;
  if ( v9 != nullptr )
    v9->next = v8;
  if ( intersectNodes == this->intersectNodes )
    this->intersectNodes = v8;
}


// ========================================================================
// ?AddPolygonPoint@idCutterClip@@AAAPAUPolygonPoint_t@1@PAUEdge_t@1@0ABVidVec2i@@@Z
// EA  : 0x827B72E0
// RVA : 0x007B72E0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::PolygonPoint_t *__fastcall idCutterClip::AddPolygonPoint(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        const idVec2i *pos)
{
  int outIndex; // r11
  int num; // r29
  idCutterClip::PolygonPoint_t *v10; // r27
  idCutterClip::Polygon_t *v11; // r3
  idCutterClip::Polygon_t *v13; // r29
  idCutterClip::PolygonPoint_t *points; // r27
  idCutterClip::PolygonPoint_t *bottomPoint; // r26
  idCutterClip::PolygonPoint_t *prev; // r11
  int y; // r9
  char v18; // r11
  idCutterClip::PolygonPoint_t *v19; // r3
  idCutterClip::Polygon_t *v20; // [sp+50h] [-50h] BYREF

  outIndex = edge1->outIndex;
  if ( outIndex == -1 )
  {
    num = this->polygons.num;
    v10 = idCutterClip::AllocPolygonPoint(this);
    v10->index = num;
    v10->pos = *pos;
    v10->next = v10;
    v10->prev = v10;
    v11 = idCutterClip::AllocPolygon(this);
    v20 = v11;
    v11->index = num;
    v11->points = v10;
    v11->bottomPoint = v10;
    v11->bottomEdge1 = edge1;
    v11->bottomEdge2 = edge2;
    idCutterClip::SetHoleState(this, edge: edge1, polygon: v11);
    edge1->outIndex = num;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->polygons,
      obj: (const encounterGroupRole_t *)&v20);
    return nullptr;
  }
  else
  {
    v13 = this->polygons.list[outIndex];
    points = v13->points;
    bottomPoint = v13->bottomPoint;
    prev = points;
    if ( (*((_WORD *)edge1 + 36) & 0x8000) != 0 )
      prev = points->prev;
    if ( pos->x != prev->pos.x || (y = prev->pos.y, v18 = 1, pos->y != y) )
      v18 = 0;
    if ( v18 == 0 )
    {
      v19 = idCutterClip::AllocPolygonPoint(this);
      v19->index = v13->index;
      v19->pos = *pos;
      if ( pos->y == bottomPoint->pos.y && pos->x < bottomPoint->pos.x )
      {
        v13->bottomPoint = v19;
        v13->bottomEdge1 = edge1;
        v13->bottomEdge2 = edge2;
      }
      v19->next = points;
      v19->prev = points->prev;
      points->prev->next = v19;
      points->prev = v19;
      if ( (*((_WORD *)edge1 + 36) & 0x8000) == 0 )
        v13->points = v19;
    }
    return nullptr;
  }
}


// ========================================================================
// ?AddPolygonPoint@idCutterClip@@AAAPAUPolygonPoint_t@1@PAU21@00ABVidVec2i@@@Z
// EA  : 0x827B7468
// RVA : 0x007B7468
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::PolygonPoint_t *__fastcall idCutterClip::AddPolygonPoint(
        idCutterClip *this,
        idCutterClip::PolygonPoint_t *p1,
        idCutterClip::PolygonPoint_t *p2,
        idCutterClip::PolygonPoint_t *p3,
        const idVec2i *pos)
{
  int x; // r11
  idCutterClip::PolygonPoint_t *v6; // r31
  int v7; // r10
  idCutterClip::PolygonPoint_t *v8; // r30
  char v10; // r9
  idCutterClip::PolygonPoint_t *result; // r3
  int v12; // r8
  char v13; // r9
  char v14; // r9
  idCutterClip::PolygonPoint_t *v15; // r11
  idCutterClip::PolygonPoint_t *v16; // r10

  x = pos->x;
  v6 = p1;
  v7 = p1->pos.x;
  v8 = p2;
  if ( pos->x != v7 || (v10 = 1, pos->y != p1->pos.y) )
    v10 = 0;
  if ( v10 != 0 )
    return p1;
  v12 = p2->pos.x;
  if ( x != v12 || (v13 = 1, pos->y != p2->pos.y) )
    v13 = 0;
  if ( v13 != 0 )
    return p2;
  if ( p3 != nullptr )
  {
    if ( x != p3->pos.x || (v14 = 1, pos->y != p3->pos.y) )
      v14 = 0;
    if ( v14 != 0 )
      return p3;
    if ( (x - v7) * (x - v7) + (pos->y - p1->pos.y) * (pos->y - p1->pos.y) > (v12 - v7) * (v12 - v7)
                                                                           + (p2->pos.y - p1->pos.y)
                                                                           * (p2->pos.y - p1->pos.y) )
    {
      v6 = p2;
      v8 = p3;
    }
  }
  result = idCutterClip::AllocPolygonPoint(this);
  v15 = v6;
  v16 = v8;
  result->pos = *pos;
  if ( v6->next != v8 )
  {
    v15 = v8;
    v16 = v6;
  }
  v15->next = result;
  v16->prev = result;
  result->prev = v15;
  result->next = v16;
  return result;
}


// ========================================================================
// ?AddLocalMinPolygon@idCutterClip@@AAAXPAUEdge_t@1@0ABVidVec2i@@@Z
// EA  : 0x827B75D0
// RVA : 0x007B75D0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddLocalMinPolygon(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        const idVec2i *pos)
{
  idCutterClip::Edge_t *v4; // r31
  idCutterClip::Edge_t *v5; // r30

  v4 = edge2;
  v5 = edge1;
  if ( (*((_WORD *)edge2 + 36) & 0x2000) != 0 || edge1->deltaX > (double)edge2->deltaX )
  {
    v4 = edge1;
    v5 = edge2;
  }
  idCutterClip::AddPolygonPoint(this, edge1: v4, edge2: v5, pos);
  v5->outIndex = v4->outIndex;
  *((_WORD *)v4 + 36) &= ~0x8000u;
  *((_WORD *)v5 + 36) |= 0x8000u;
}


// ========================================================================
// ?AddLocalMaxPolygon@idCutterClip@@AAAXPAUEdge_t@1@0ABVidVec2i@@@Z
// EA  : 0x827B7658
// RVA : 0x007B7658
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddLocalMaxPolygon(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        const idVec2i *pos)
{
  idCutterClip::AddPolygonPoint(this, edge1, edge2: nullptr, pos);
  if ( edge1->outIndex == edge2->outIndex )
  {
    edge1->outIndex = -1;
    edge2->outIndex = -1;
  }
  else
  {
    idCutterClip::AppendPolygon(this, edge1, edge2);
  }
}


// ========================================================================
// ?IntersectEdges@idCutterClip@@AAAXPAUEdge_t@1@0ABVidVec2i@@W4intersectProtects_t@1@@Z
// EA  : 0x827B76B8
// RVA : 0x007B76B8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::IntersectEdges(
        idCutterClip *this,
        idCutterClip::Edge_t *edge1,
        idCutterClip::Edge_t *edge2,
        const idVec2i *pos,
        idCutterClip::intersectProtects_t protects)
{
  char v9; // r11
  char v10; // r11
  bool v11; // zf
  char v12; // r21
  char v13; // r11
  char v14; // r11
  char v15; // r23
  int v16; // r9
  __int16 v17; // r7
  int v18; // r11
  __int16 v19; // r22
  fillType_t fillTypeSubject; // r11
  __int16 windingCount; // r9
  int windingDelta; // r9
  int v23; // r11
  __int16 v24; // r10
  fillType_t fillTypeClip; // r11
  fillType_t v26; // r11
  int v27; // r26
  unsigned int v28; // r8
  int v29; // r9
  unsigned int v30; // r11
  unsigned int v31; // r10
  int v32; // r7
  int v33; // r3
  int v34; // r6
  int v35; // r27
  bool v36; // r5
  bool v37; // r4
  bool v38; // r29
  bool v39; // r28
  unsigned int v40; // r11
  __int16 outIndex; // r5
  unsigned int v42; // r11
  __int16 v43; // r5
  unsigned int v44; // r11
  __int16 v45; // r5
  clipMode_t clipMode; // r11
  unsigned int v47; // r10
  __int16 v48; // r3
  idCutterClip::Edge_t *prevAEL; // r11
  idCutterClip::Edge_t *nextAEL; // r10
  idCutterClip::Edge_t *v51; // r11
  idCutterClip::Edge_t *v52; // r10

  if ( (protects & 1) != 0 || edge1->nextLML != nullptr )
    goto LABEL_7;
  if ( pos->x != edge1->top.x || (v9 = 1, pos->y != edge1->top.y) )
    v9 = 0;
  v11 = v9 != 0;
  v10 = 1;
  if ( !v11 )
LABEL_7:
    v10 = 0;
  v12 = v10;
  if ( (protects & 2) != 0 || edge2->nextLML != nullptr )
    goto LABEL_14;
  if ( pos->x != edge2->top.x || (v13 = 1, pos->y != edge2->top.y) )
    v13 = 0;
  v11 = v13 != 0;
  v14 = 1;
  if ( !v11 )
LABEL_14:
    v14 = 0;
  v15 = v14;
  v16 = (*((_WORD *)edge1 + 36) & 0x4000) != 0;
  v17 = edge1->outIndex + 1 - (edge1->outIndex + (edge1->outIndex == -1));
  v18 = (*((_WORD *)edge2 + 36) & 0x4000) != 0;
  v19 = edge2->outIndex + 1 - (edge2->outIndex + (edge2->outIndex == -1));
  if ( v16 == v18 )
  {
    if ( v16 == 1 )
      fillTypeSubject = this->fillTypeSubject;
    else
      fillTypeSubject = this->fillTypeClip;
    if ( fillTypeSubject != FILLTYPE_EVEN_ODD )
    {
      if ( fillTypeSubject == FILLTYPE_NON_ZERO )
      {
        windingCount = edge1->windingCount;
        if ( edge2->windingDelta + windingCount != 0 )
          edge1->windingCount = edge2->windingDelta + windingCount;
        else
          edge1->windingCount = -windingCount;
        windingDelta = edge1->windingDelta;
        v23 = edge2->windingCount;
        if ( v23 == windingDelta )
          edge2->windingCount = -(__int16)v23;
        else
          edge2->windingCount = v23 - windingDelta;
      }
    }
    else
    {
      v24 = edge1->windingCount;
      edge1->windingCount = edge2->windingCount;
      edge2->windingCount = v24;
    }
  }
  else
  {
    if ( v18 == 1 )
      fillTypeClip = this->fillTypeSubject;
    else
      fillTypeClip = this->fillTypeClip;
    if ( fillTypeClip != FILLTYPE_EVEN_ODD )
    {
      if ( fillTypeClip == FILLTYPE_NON_ZERO )
        edge1->windingCount2 += edge2->windingDelta;
    }
    else
    {
      edge1->windingCount2 = (_cntlzw((unsigned __int16)edge1->windingCount2) & 0x20) != 0;
    }
    if ( v16 == 1 )
      v26 = this->fillTypeSubject;
    else
      v26 = this->fillTypeClip;
    if ( v26 != FILLTYPE_EVEN_ODD )
    {
      if ( v26 == FILLTYPE_NON_ZERO )
        edge2->windingCount2 -= edge1->windingDelta;
    }
    else
    {
      edge2->windingCount2 = (_cntlzw((unsigned __int16)edge2->windingCount2) & 0x20) != 0;
    }
  }
  v27 = (unsigned __int8)v17;
  v28 = *((unsigned __int16 *)edge1 + 36);
  v29 = *((unsigned __int16 *)edge2 + 36);
  v30 = (v28 & 0x4000) != 0;
  v31 = (v29 & 0x4000) != 0;
  v33 = abs16(edge1->windingCount2);
  v35 = abs16(edge2->windingCount2);
  v34 = abs16(edge2->windingCount);
  v36 = (_cntlzw(v30) & 0x20) != 0;
  v37 = (_cntlzw(v31) & 0x20) != 0;
  v38 = (_cntlzw(v30 - 1) & 0x20) != 0;
  v39 = (_cntlzw(v31 - 1) & 0x20) != 0;
  v11 = (unsigned __int8)v17 == 0;
  v32 = abs16(edge1->windingCount);
  if ( !v11 )
  {
    if ( (_BYTE)v19 != 0 )
    {
      if ( v12 != 0 || v15 != 0 || ((v29 ^ v28) & 0x4000) != 0 && this->clipMode != CLIPMODE_XOR || v32 > 1 || v34 > 1 )
      {
        idCutterClip::AddLocalMaxPolygon(this, edge1, edge2, pos);
      }
      else
      {
        idCutterClip::AddPolygonPoint(this, edge1, edge2, pos);
        idCutterClip::AddPolygonPoint(this, edge1: edge2, edge2: edge1, pos);
        v40 = *((unsigned __int16 *)edge1 + 36);
        *((_WORD *)edge1 + 36) = v40 & 0x7FFF | *((_WORD *)edge2 + 36) & 0x8000;
        *((_WORD *)edge2 + 36) = ((unsigned __int16)(v40 >> 15) << 15) | *((_WORD *)edge2 + 36) & 0x7FFF;
        outIndex = edge1->outIndex;
        edge1->outIndex = edge2->outIndex;
        edge2->outIndex = outIndex;
      }
      goto LABEL_89;
    }
    if ( v27 != 0 )
    {
      if ( v34 < 2 && (this->clipMode != CLIPMODE_INTERSECT || v39 || v35 != 0) )
      {
        idCutterClip::AddPolygonPoint(this, edge1, edge2, pos);
        v42 = *((unsigned __int16 *)edge1 + 36);
        *((_WORD *)edge1 + 36) = v42 & 0x7FFF | *((_WORD *)edge2 + 36) & 0x8000;
        *((_WORD *)edge2 + 36) = ((unsigned __int16)(v42 >> 15) << 15) | *((_WORD *)edge2 + 36) & 0x7FFF;
        v43 = edge1->outIndex;
        edge1->outIndex = edge2->outIndex;
        edge2->outIndex = v43;
      }
      goto LABEL_89;
    }
  }
  if ( (_BYTE)v19 != 0 )
  {
    if ( v32 < 2 && (this->clipMode != CLIPMODE_INTERSECT || v38 || v33 != 0) )
    {
      idCutterClip::AddPolygonPoint(this, edge1: edge2, edge2: edge1, pos);
      v44 = *((unsigned __int16 *)edge1 + 36);
      *((_WORD *)edge1 + 36) = v44 & 0x7FFF | *((_WORD *)edge2 + 36) & 0x8000;
      *((_WORD *)edge2 + 36) = ((unsigned __int16)(v44 >> 15) << 15) | *((_WORD *)edge2 + 36) & 0x7FFF;
      v45 = edge1->outIndex;
      edge1->outIndex = edge2->outIndex;
      edge2->outIndex = v45;
    }
    goto LABEL_89;
  }
  if ( v32 >= 2 || v34 >= 2 || v12 != 0 || v15 != 0 )
    goto LABEL_89;
  if ( v30 != v31 )
    goto LABEL_78;
  if ( v32 != 1 || v34 != 1 )
  {
    *((_WORD *)edge1 + 36) = v28 & 0x7FFF | v29 & 0x8000;
    *((_WORD *)edge2 + 36) = ((unsigned __int16)(v28 >> 15) << 15) | *((_WORD *)edge2 + 36) & 0x7FFF;
    goto LABEL_89;
  }
  clipMode = this->clipMode;
  if ( (unsigned int)clipMode <= CLIPMODE_XOR )
  {
    if ( clipMode != CLIPMODE_UNION )
    {
      if ( clipMode != CLIPMODE_DIFFERENCE )
      {
        if ( clipMode == CLIPMODE_INTERSECT && (v33 <= 0 || v35 <= 0) )
          goto LABEL_89;
        goto LABEL_78;
      }
      if ( v36 && v37 && v33 != 0 && v35 != 0 )
      {
LABEL_78:
        idCutterClip::AddLocalMinPolygon(this, edge1, edge2, pos);
        goto LABEL_89;
      }
      if ( !v38 || !v39 )
        goto LABEL_89;
    }
    if ( v33 != 0 || v35 != 0 )
      goto LABEL_89;
    goto LABEL_78;
  }
LABEL_89:
  if ( v12 != v15 && (v12 != 0 && v27 != 0 || v15 != 0 && (_BYTE)v19 != 0) )
  {
    v47 = *((unsigned __int16 *)edge1 + 36);
    *((_WORD *)edge1 + 36) = v47 & 0x7FFF | *((_WORD *)edge2 + 36) & 0x8000;
    *((_WORD *)edge2 + 36) = ((unsigned __int16)(v47 >> 15) << 15) | *((_WORD *)edge2 + 36) & 0x7FFF;
    v48 = edge1->outIndex;
    edge1->outIndex = edge2->outIndex;
    edge2->outIndex = v48;
  }
  if ( v12 != 0 )
  {
    prevAEL = edge1->prevAEL;
    nextAEL = edge1->nextAEL;
    if ( prevAEL != nullptr || nextAEL != nullptr || edge1 == this->activeEdges )
    {
      edge1->nextAEL = nullptr;
      edge1->prevAEL = nullptr;
      if ( prevAEL != nullptr )
        prevAEL->nextAEL = nextAEL;
      if ( nextAEL != nullptr )
        nextAEL->prevAEL = prevAEL;
      if ( prevAEL == nullptr )
        this->activeEdges = nextAEL;
    }
  }
  if ( v15 != 0 )
  {
    v51 = edge2->prevAEL;
    v52 = edge2->nextAEL;
    if ( v51 != nullptr || v52 != nullptr || edge2 == this->activeEdges )
    {
      edge2->nextAEL = nullptr;
      edge2->prevAEL = nullptr;
      if ( v51 != nullptr )
        v51->nextAEL = v52;
      if ( v52 != nullptr )
        v52->prevAEL = v51;
      if ( v51 == nullptr )
        this->activeEdges = v52;
    }
  }
}


// ========================================================================
// ?PreAllocate@idCutterClip@@QAAXXZ
// EA  : 0x827B7D60
// RVA : 0x007B7D60
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::PreAllocate(idCutterClip *this)
{
  idCutterClip::Edge_t *v2; // r3
  int numEdges; // r11
  idCutterClip::LocalMinima_t *v4; // r3
  int numLocalMinima; // r11
  idCutterClip::Scanbeam_t *v6; // r3
  int v7; // r11
  idCutterClip::NestedPolygon_t *v8; // r3
  int numNestedPolygons; // r11
  idCutterClip::Polygon_t *v10; // r3
  int numPolygons; // r11
  idCutterClip::PolygonPoint_t *v12; // r3
  int numPolygonPoints; // r11
  idCutterClip::JoinRecord_t *v14; // r3
  int numJoinRecords; // r11
  idCutterClip::HorizontalJoinRecord_t *v16; // r3
  int v17; // r11
  idCutterClip::IntersectNode_t *v18; // r3
  int v19; // r9

  v2 = idCutterClip::AllocEdge(this);
  v2->next = this->edgesPool;
  numEdges = this->numEdges;
  this->edgesPool = v2;
  this->numEdges = numEdges - 1;
  v4 = idCutterClip::AllocLocalMinima(this);
  v4->next = this->localMinimasPool;
  numLocalMinima = this->numLocalMinima;
  this->localMinimasPool = v4;
  this->numLocalMinima = numLocalMinima - 1;
  v6 = idCutterClip::AllocScanbeam(this);
  v6->next = this->scanbeamsPool;
  v7 = this->numScanbeams - 1;
  this->scanbeamsPool = v6;
  this->numScanbeams = v7;
  v8 = idCutterClip::AllocNestedPolygon(this);
  v8->next = this->nestedPolygonsPool;
  numNestedPolygons = this->numNestedPolygons;
  this->nestedPolygonsPool = v8;
  this->numNestedPolygons = numNestedPolygons - 1;
  v10 = idCutterClip::AllocPolygon(this);
  v10->appendLink = this->polygonsPool;
  numPolygons = this->numPolygons;
  this->polygonsPool = v10;
  this->numPolygons = numPolygons - 1;
  v12 = idCutterClip::AllocPolygonPoint(this);
  v12->prev = nullptr;
  v12->next = this->polygonPointsPool;
  numPolygonPoints = this->numPolygonPoints;
  this->polygonPointsPool = v12;
  this->numPolygonPoints = numPolygonPoints - 1;
  v14 = idCutterClip::AllocJoinRecord(this);
  v14->next = this->joinRecordsPool;
  numJoinRecords = this->numJoinRecords;
  this->joinRecordsPool = v14;
  this->numJoinRecords = numJoinRecords - 1;
  v16 = idCutterClip::AllocHorizontalJoinRecord(this);
  v16->next = this->horizontalJoinRecordsPool;
  v17 = this->numHorizontalJoinRecords - 1;
  this->horizontalJoinRecordsPool = v16;
  this->numHorizontalJoinRecords = v17;
  v18 = idCutterClip::AllocIntersectNode(this);
  v18->next = this->intersectNodesPool;
  v19 = this->numIntersectNode - 1;
  this->intersectNodesPool = v18;
  this->numIntersectNode = v19;
}


// ========================================================================
// ?Reset@idCutterClip@@AAAXXZ
// EA  : 0x827B7ED0
// RVA : 0x007B7ED0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::Reset(idCutterClip *this)
{
  idCutterClip::LocalMinima_t *localMinimaList; // r31
  idCutterClip::Edge_t *i; // r11
  __int16 v4; // r10
  idVec2i *p_current; // r9
  int x; // r8
  int y; // r6
  idCutterClip::Edge_t *j; // r11
  __int16 v9; // r10
  idVec2i *v10; // r9
  int v11; // r8
  int v12; // r6
  idCutterClip::LocalMinima_t *v13; // r10

  idCutterClip::ClearJoinRecords(this);
  idCutterClip::ClearHorizontalJoinRecords(this);
  idCutterClip::ClearNestedPolygons(this);
  idCutterClip::ClearPolygons(this);
  idCutterClip::ClearPolygonPoints(this);
  localMinimaList = this->localMinimaList;
  if ( localMinimaList != nullptr )
  {
    do
    {
      for ( i = localMinimaList->leftBound; i != nullptr; p_current->y = y )
      {
        v4 = *((_WORD *)i + 36);
        p_current = &i->current;
        x = i->bottom.x;
        y = i->bottom.y;
        i->outIndex = -1;
        *((_WORD *)i + 36) = v4 & 0x7FFF;
        i = i->nextLML;
        p_current->x = x;
      }
      for ( j = localMinimaList->rightBound; j != nullptr; v10->y = v12 )
      {
        v9 = *((_WORD *)j + 36);
        v10 = &j->current;
        v11 = j->bottom.x;
        v12 = j->bottom.y;
        j->outIndex = -1;
        *((_WORD *)j + 36) = v9 | 0x8000;
        j = j->nextLML;
        v10->x = v11;
      }
      idCutterClip::AddScanbeam(this, y: localMinimaList->y);
      idCutterClip::AddScanbeam(this, y: localMinimaList->leftBound->top.y);
      localMinimaList = localMinimaList->next;
    }
    while ( localMinimaList != nullptr );
    v13 = this->localMinimaList;
    this->currentNestedPolygon = nullptr;
    this->currentInnerPolygon = nullptr;
    this->currentLocalMinima = v13;
  }
}


// ========================================================================
// ?UpdateEdgeInAEL@idCutterClip@@AAAPAUEdge_t@1@PAU21@@Z
// EA  : 0x827B7FD0
// RVA : 0x007B7FD0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

idCutterClip::Edge_t *__fastcall idCutterClip::UpdateEdgeInAEL(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  idCutterClip::Edge_t *nextLML; // r31
  idCutterClip::Edge_t *prevAEL; // r11
  idCutterClip::Edge_t *nextAEL; // r10
  __int16 v6; // r9

  nextLML = edge->nextLML;
  prevAEL = edge->prevAEL;
  nextAEL = edge->nextAEL;
  if ( nextLML == nullptr )
    return nullptr;
  nextLML->outIndex = edge->outIndex;
  if ( prevAEL != nullptr )
    prevAEL->nextAEL = nextLML;
  if ( nextAEL != nullptr )
    nextAEL->prevAEL = nextLML;
  *((_WORD *)nextLML + 36) = *((_WORD *)nextLML + 36) & 0x7FFF | *((_WORD *)edge + 36) & 0x8000;
  nextLML->windingDelta = edge->windingDelta;
  nextLML->windingCount = edge->windingCount;
  nextLML->windingCount2 = edge->windingCount2;
  if ( prevAEL == nullptr )
    this->activeEdges = nextLML;
  v6 = *((_WORD *)nextLML + 36);
  nextLML->prevAEL = prevAEL;
  nextLML->nextAEL = nextAEL;
  if ( (v6 & 0x2000) == 0 )
    idCutterClip::AddScanbeam(this, y: nextLML->top.y);
  return nextLML;
}


// ========================================================================
// ?ProcessIntersectList@idCutterClip@@AAAXXZ
// EA  : 0x827B8098
// RVA : 0x007B8098
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ProcessIntersectList(idCutterClip *this)
{
  idCutterClip::IntersectNode_t *intersectNodes; // r31
  idCutterClip::IntersectNode_t *next; // r11
  bool v4; // cr58

  intersectNodes = this->intersectNodes;
  if ( intersectNodes != nullptr )
  {
    do
    {
      idCutterClip::IntersectEdges(
        this,
        edge1: intersectNodes->edge1,
        edge2: intersectNodes->edge2,
        pos: &intersectNodes->pos,
        protects: INTERSECTPROTECTS_BOTH);
      idCutterClip::SwapEdgeInAEL(this, edge1: intersectNodes->edge1, edge2: intersectNodes->edge2);
      next = intersectNodes->next;
      v4 = intersectNodes->next == nullptr;
      intersectNodes->next = this->intersectNodesPool;
      this->intersectNodesPool = intersectNodes;
      intersectNodes = next;
      --this->numIntersectNode;
    }
    while ( !v4 );
  }
  this->intersectNodes = nullptr;
}


// ========================================================================
// ?BuildIntersectList@idCutterClip@@AAAXHH@Z
// EA  : 0x827B8130
// RVA : 0x007B8130
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::BuildIntersectList(
        idCutterClip *this,
        int yBottom,
        int yTop,
        long double a4,
        int a5,
        __int64 a6)
{
  idCutterClip::Edge_t *activeEdges; // r31
  __int64 v10; // r8
  int v11; // r5
  long double v12; // fp2
  const idCutterClip::Edge_t *i; // r31
  idCutterClip::Edge_t *prevAEL; // r11
  idCutterClip::Edge_t *sortedEdges; // r31
  idCutterClip::Edge_t *nextSEL; // r30
  char j; // r29
  __int64 v18; // r8
  int v19; // r5
  long double v20; // fp2
  idCutterClip::Edge_t *prevSEL; // r11
  idVec2i v22[8]; // [sp+50h] [-40h] BYREF

  activeEdges = this->activeEdges;
  if ( activeEdges != nullptr )
  {
    activeEdges->tmpX = idCutterClip::CalculateTopX(edge: this->activeEdges, y: yTop, a3: a4, a4: yTop, a5: a6);
    this->sortedEdges = activeEdges;
    activeEdges->prevSEL = nullptr;
    for ( i = activeEdges->nextAEL; i != nullptr; i = i->nextAEL )
    {
      prevAEL = i->prevAEL;
      i->nextSEL = nullptr;
      i->prevSEL = prevAEL;
      prevAEL->nextSEL = (idCutterClip::Edge_t *)i;
      i->tmpX = idCutterClip::CalculateTopX(edge: i, y: yTop, a3: v12, a4: v11, a5: v10);
    }
    do
    {
      sortedEdges = this->sortedEdges;
      if ( sortedEdges == nullptr )
        break;
      nextSEL = sortedEdges->nextSEL;
      for ( j = 0; nextSEL != nullptr; nextSEL = sortedEdges->nextSEL )
      {
        if ( sortedEdges->tmpX > nextSEL->tmpX
          && (unsigned __int8)idCutterClip::EdgeEdgeIntersection(edge1: sortedEdges, edge2: nextSEL, pos: v22) != 0 )
        {
          if ( v22[0].y > yBottom )
          {
            v22[0].x = idCutterClip::CalculateTopX(edge: sortedEdges, y: yBottom, a3: v20, a4: v19, a5: v18);
            v22[0].y = yBottom;
          }
          idCutterClip::AddIntersectNode(this, edge1: sortedEdges, edge2: nextSEL, pos: v22);
          idCutterClip::SwapEdgeInSEL(this, edge1: sortedEdges, edge2: nextSEL);
          j = 1;
        }
        else
        {
          sortedEdges = nextSEL;
        }
      }
      prevSEL = sortedEdges->prevSEL;
      if ( prevSEL == nullptr )
        break;
      prevSEL->nextSEL = nullptr;
    }
    while ( j != 0 );
    this->sortedEdges = nullptr;
  }
}


// ========================================================================
// ?AddContour@idCutterClip@@QAAXPBVContour@@W4polygonType_t@@@Z
// EA  : 0x827B8278
// RVA : 0x007B8278
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCutterClip::AddContour(idCutterClip *this, const Contour *contours, polygonType_t polyType)
{
  __int16 v4; // r19
  const Contour *v5; // r20
  idList<idSpawnArea::GeneratedPosition *,5> *p_edges; // r25
  signed int numEdges; // r27
  int num; // r26
  ContourEdge_t *edges; // r22
  ContourEdge_t *next; // r24
  int size; // r11
  int v12; // r29
  signed int i; // r30
  idSpawnArea::GeneratedPosition **list; // r28
  int v15; // r28
  int v16; // r9
  int v17; // r4
  int v18; // r5
  int v19; // r11
  signed int v20; // r30
  ContourNode_t *node; // r10
  idVec2i pos; // r8 OVERLAPPED
  int v23; // r6 OVERLAPPED
  int v24; // r11
  int v25; // r10
  int v26; // r17
  __int16 v27; // r16
  int v28; // r8
  __int16 v29; // r9
  int v30; // r17
  double v31; // fp0
  __int64 v32; // r10
  int v33; // r7
  idCutterClip::Edge_t *v34; // r4

  v4 = polyType;
  v5 = contours;
  if ( contours != nullptr )
  {
    p_edges = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->edges;
    do
    {
      numEdges = v5->numEdges;
      num = this->edges.num;
      edges = v5->edges;
      next = edges->next;
      if ( num + numEdges <= p_edges->size
        || (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edges, newsize: num + numEdges) != 0 )
      {
        size = p_edges->size;
        if ( num + numEdges < size )
          size = num + numEdges;
        p_edges->num = size;
      }
      if ( numEdges > 0 )
      {
        v12 = num;
        for ( i = numEdges; i != 0; --i )
        {
          list = p_edges->list;
          list[v12++] = (idSpawnArea::GeneratedPosition *)idCutterClip::AllocEdge(this);
        }
      }
      v15 = 0;
      v16 = numEdges - 1;
      v17 = 0;
      v18 = 1;
      if ( numEdges > 0 )
      {
        v19 = 4 * v16;
        v20 = numEdges;
        do
        {
          node = edges->node;
          edges = next;
          next = next->next;
          pos = node->pos;
          *(idVec2i *)&pos.y = *(idVec2i *)(pos.x + 4);
          if ( next == nullptr )
            next = v5->edges;
          v25 = *(int *)((char *)&p_edges->list[num] + v19);
          v24 = *(int *)((char *)p_edges->list + v23);
          v26 = *((_DWORD *)&p_edges->list[v18] + num);
          v27 = *(_WORD *)(v24 + 72);
          *(_DWORD *)v24 = v25;
          *(_DWORD *)(v24 + 8) = 0;
          *(_DWORD *)(v24 + 4) = v26;
          *(_DWORD *)(v24 + 12) = 0;
          *(_DWORD *)(v24 + 16) = 0;
          *(_DWORD *)(v24 + 20) = 0;
          *(_DWORD *)(v24 + 24) = 0;
          *(_DWORD *)(v24 + 28) = 0;
          *(_WORD *)(v24 + 68) = -1;
          *(_WORD *)(v24 + 72) = v27 & 0xBFFF | (v4 << 14) & 0x4000;
          *(_WORD *)(v24 + 70) = -1;
          *(_WORD *)(v24 + 64) = 0;
          *(_WORD *)(v24 + 66) = 0;
          *(_DWORD *)(v24 + 76) = v16 + num;
          *(idVec2i *)(v24 + 32) = pos;
          *(idVec2i *)(v24 + 40) = *(idVec2i *)&pos.y;
          if ( pos.y >= pos.x )
          {
            *(_DWORD *)(v24 + 40) = *(_DWORD *)(v24 + 32);
            *(_DWORD *)(v24 + 44) = *(_DWORD *)(v24 + 36);
            *(idVec2i *)(v24 + 32) = *(idVec2i *)&pos.y;
            *(_WORD *)(v24 + 70) = 1;
          }
          v28 = *(_DWORD *)(v24 + 36);
          v29 = *(_WORD *)(v24 + 72);
          v30 = *(_DWORD *)(v24 + 44);
          *(_DWORD *)(v24 + 48) = *(_DWORD *)(v24 + 40);
          *(_DWORD *)(v24 + 52) = v30;
          *(_WORD *)(v24 + 72) = (((_cntlzw(v28 - v30) & 0x20) != 0) << 13) & 0x2000 | v29 & 0xDFFF;
          if ( v30 == v28 )
          {
            v31 = -1.0e30;
          }
          else
          {
            LODWORD(v32) = v28 - v30;
            HIDWORD(v32) = *(_DWORD *)(v24 + 32) - *(_DWORD *)(v24 + 40);
            v33 = HIDWORD(v32);
            v31 = (float)((float)*(__int64 *)(&v23 - 1) / (float)v32);
          }
          *(float *)(v24 + 56) = v31;
          if ( v15 == 0 || v28 < *(_DWORD *)(v15 + 36) )
            v15 = v24;
          --v20;
          v16 = v17;
          v19 = 4 * v17;
          __twlgei(numEdges & ~(__ROL4__(v18 + 1, 1) - 1), 0xFFFFFFFF);
          __twllei(numEdges, 0);
          ++v17;
          v18 = (v18 + 1) % numEdges;
        }
        while ( v20 != 0 );
      }
      if ( *(__int16 *)(v15 + 70) > 0 )
        v15 = *(_DWORD *)(v15 + 4);
      if ( (*(_WORD *)(v15 + 72) & 0x2000) != 0 )
        v15 = *(_DWORD *)(v15 + 4);
      v34 = (idCutterClip::Edge_t *)v15;
      do
        v34 = idCutterClip::AddBoundToLML(this, edge: v34);
      while ( v34 != (idCutterClip::Edge_t *)v15 );
      v5 = v5->next;
    }
    while ( v5 != nullptr );
  }
}


// ========================================================================
// ?GetPolygon@idCutterClip@@CAXPBUPolygon_t@1@AAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827B8550
// RVA : 0x007B8550
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::GetPolygon(const idCutterClip::Polygon_t *polygon, idList<idSkinMapping,46> *list)
{
  idCutterClip::PolygonPoint_t *points; // r29
  idCutterClip::PolygonPoint_t *v4; // r30
  int granularity; // r4
  int size; // r11
  bool v7; // cr58
  signed int v8; // r10
  int v9; // r4
  int v10; // r11
  int num; // r11
  idVec2i *v12; // r8

  if ( polygon != nullptr )
  {
    points = polygon->points;
    if ( points != nullptr )
    {
      v4 = polygon->points;
      do
      {
        if ( list->list != nullptr )
          goto LABEL_8;
        granularity = list->granularity;
        if ( granularity <= 0 )
          granularity = 1;
        if ( idList<idDeclMD6::includeDecl_t,5>::Resize(this: list, newsize: granularity) )
        {
LABEL_8:
          size = list->size;
          if ( list->num != size )
            goto LABEL_19;
          if ( forceIdListsToReallocateEveryAppend )
          {
            v7 = !idList<idDeclMD6::includeDecl_t,5>::Resize(this: list, newsize: size + 1);
          }
          else
          {
            v8 = list->granularity;
            if ( list->granularity != 0 )
            {
              v10 = size + v8;
              __twllei(v8, 0);
              __twlgei(v8 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
              v7 = !idList<idDeclMD6::includeDecl_t,5>::Resize(this: list, newsize: v10 - v10 % v8);
            }
            else
            {
              v9 = 2 * size;
              if ( 2 * size >= size )
              {
                if ( v9 == 0 )
                  v9 = 1;
                v7 = !idList<idDeclMD6::includeDecl_t,5>::Resize(this: list, newsize: v9);
              }
              else
              {
                v7 = !idList<idDeclMD6::includeDecl_t,5>::Resize(this: list, newsize: 0x7FFFFFFF);
              }
            }
          }
          if ( !v7 )
          {
LABEL_19:
            num = list->num;
            if ( num < list->size )
            {
              v12 = (idVec2i *)&list->list[num];
              v12->x = v4->pos.x;
              v12->y = v4->pos.y;
              ++list->num;
            }
          }
        }
        v4 = v4->next;
      }
      while ( v4 != points );
    }
  }
}


// ========================================================================
// ?DoMaxima@idCutterClip@@AAAXPAUEdge_t@1@0H@Z
// EA  : 0x827B86C8
// RVA : 0x007B86C8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::DoMaxima(
        idCutterClip *this,
        idCutterClip::Edge_t *edge,
        idCutterClip::Edge_t *edgeMaxPair,
        int y)
{
  idCutterClip::Edge_t *nextAEL; // r31
  int x; // r26
  idCutterClip *v10; // r3
  idVec2i v11[8]; // [sp+50h] [-40h] BYREF

  nextAEL = edge->nextAEL;
  x = edge->top.x;
  if ( nextAEL != edgeMaxPair )
  {
    v11[0].x = edge->top.x;
    v11[0].y = y;
    do
    {
      idCutterClip::IntersectEdges(this, edge1: edge, edge2: nextAEL, pos: v11, protects: INTERSECTPROTECTS_BOTH);
      nextAEL = nextAEL->nextAEL;
    }
    while ( nextAEL != edgeMaxPair );
  }
  if ( edge->outIndex == -1 )
  {
    if ( (unsigned __int16)edgeMaxPair->outIndex == 0xFFFF )
    {
      idCutterClip::RemoveEdgeFromAEL(this, edge);
      idCutterClip::RemoveEdgeFromAEL(this: v10, edge: edgeMaxPair);
    }
  }
  else if ( (unsigned __int16)edgeMaxPair->outIndex != 0xFFFF )
  {
    v11[0].x = x;
    v11[0].y = y;
    idCutterClip::IntersectEdges(this, edge1: edge, edge2: edgeMaxPair, pos: v11, protects: INTERSECTPROTECTS_NONE);
  }
}


// ========================================================================
// ?AddLocalMinimaToAEL@idCutterClip@@AAAXH@Z
// EA  : 0x827B8798
// RVA : 0x007B8798
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::AddLocalMinimaToAEL(idCutterClip *this, int yBottom)
{
  idCutterClip::LocalMinima_t *currentLocalMinima; // r11
  idCutterClip::Edge_t *leftBound; // r24
  idCutterClip::Edge_t *rightBound; // r29
  fillType_t v7; // r11
  int v8; // r9
  idCutterClip::Edge_t *sortedEdges; // r11
  idCutterClip::Edge_t *v10; // r11
  int y; // r4
  idCutterClip::Edge_t *v12; // r4
  int v13; // r9
  idCutterClip::Edge_t *prevAEL; // r30
  int v15; // r25
  int v16; // r28
  idCutterClip::HorizontalJoinRecord_t *v17; // r30
  idCutterClip::Edge_t *v18; // r30
  idCutterClip::Edge_t *nextAEL; // r30
  idCutterClip::LocalMinima_t *v20; // r11
  idVec2i v21; // [sp+50h] [-70h] BYREF
  idVec2i i; // [sp+58h] [-68h] BYREF

  while ( this->currentLocalMinima != nullptr )
  {
    currentLocalMinima = this->currentLocalMinima;
    if ( currentLocalMinima->y != yBottom )
      break;
    leftBound = currentLocalMinima->leftBound;
    rightBound = currentLocalMinima->rightBound;
    idCutterClip::AddEdgeToAEL(this, edge: leftBound);
    idCutterClip::AddScanbeam(this, y: leftBound->top.y);
    idCutterClip::AddEdgeToAEL(this, edge: rightBound);
    v7 = (*((_WORD *)leftBound + 36) & 0x4000) == 0x4000 ? this->fillTypeSubject : this->fillTypeClip;
    if ( v7 != FILLTYPE_EVEN_ODD )
    {
      if ( v7 == FILLTYPE_NON_ZERO )
        rightBound->windingDelta = -leftBound->windingDelta;
    }
    else
    {
      leftBound->windingDelta = 1;
      rightBound->windingDelta = 1;
    }
    idCutterClip::SetWindingCount(this, edge: leftBound);
    v8 = *((_WORD *)rightBound + 36) & 0x2000;
    rightBound->windingCount = leftBound->windingCount;
    rightBound->windingCount2 = leftBound->windingCount2;
    if ( v8 != 0 )
    {
      sortedEdges = this->sortedEdges;
      if ( sortedEdges != nullptr )
        sortedEdges->prevSEL = rightBound;
      v10 = this->sortedEdges;
      rightBound->prevSEL = nullptr;
      rightBound->nextSEL = v10;
      this->sortedEdges = rightBound;
      y = rightBound->nextLML->top.y;
    }
    else
    {
      y = rightBound->top.y;
    }
    idCutterClip::AddScanbeam(this, y);
    if ( (unsigned __int8)idCutterClip::IsContributing(clipMode: this->clipMode, edge: leftBound) != 0 )
    {
      v13 = this->currentLocalMinima->y;
      v21.x = leftBound->current.x;
      v21.y = v13;
      idCutterClip::AddLocalMinPolygon(this, edge1: v12, edge2: rightBound, pos: &v21);
    }
    if ( (unsigned __int16)leftBound->outIndex != 0xFFFF )
    {
      prevAEL = leftBound->prevAEL;
      if ( prevAEL != nullptr
        && (unsigned __int16)prevAEL->outIndex != 0xFFFF
        && prevAEL->current.x == leftBound->bottom.x
        && idCutterClip::SlopesEqual(edge1: leftBound, edge2: leftBound->prevAEL) )
      {
        idCutterClip::AddJoinRecord(this, edge1: leftBound, edge2: prevAEL, outIndexEdge1: -1, outIndexEdge2: -1);
      }
    }
    if ( (unsigned __int16)rightBound->outIndex != 0xFFFF && (*((_WORD *)rightBound + 36) & 0x2000) != 0 )
    {
      v15 = 0;
      if ( this->horizontalJoins.num > 0 )
      {
        v16 = 0;
        do
        {
          v17 = this->horizontalJoins.list[v16];
          if ( (unsigned __int8)idCutterClip::IsSegmentOverlapping(
                                  p1a: &v17->edge->bottom,
                                  p1b: &v17->edge->top,
                                  p2a: &rightBound->bottom,
                                  p2b: &rightBound->top,
                                  overlap1: nullptr,
                                  overlap2: nullptr) != 0 )
            idCutterClip::AddJoinRecord(
              this,
              edge1: v17->edge,
              edge2: rightBound,
              outIndexEdge1: v17->savedIndex,
              outIndexEdge2: -1);
          ++v15;
          ++v16;
        }
        while ( v15 < this->horizontalJoins.num );
      }
    }
    if ( leftBound->nextAEL != rightBound )
    {
      if ( (unsigned __int16)rightBound->outIndex != 0xFFFF )
      {
        v18 = rightBound->prevAEL;
        if ( (unsigned __int16)v18->outIndex != 0xFFFF
          && idCutterClip::SlopesEqual(edge1: rightBound->prevAEL, edge2: rightBound) )
        {
          idCutterClip::AddJoinRecord(this, edge1: rightBound, edge2: v18, outIndexEdge1: -1, outIndexEdge2: -1);
        }
      }
      nextAEL = leftBound->nextAEL;
      for ( i = leftBound->current; nextAEL != rightBound; nextAEL = nextAEL->nextAEL )
        idCutterClip::IntersectEdges(this, edge1: rightBound, edge2: nextAEL, pos: &i, protects: INTERSECTPROTECTS_NONE);
    }
    v20 = this->currentLocalMinima;
    if ( v20 != nullptr )
      this->currentLocalMinima = v20->next;
  }
}


// ========================================================================
// ?ProcessHorizontal@idCutterClip@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827B8A98
// RVA : 0x007B8A98
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ProcessHorizontal(idCutterClip *this, idCutterClip::Edge_t *edge)
{
  int x; // r11
  int v4; // r9
  idVec2i *p_top; // r21
  int v7; // r24
  int v8; // r22
  int v9; // r23
  idCutterClip::Edge_t *prev; // r26
  idCutterClip::Edge_t *next; // r11
  char v12; // r10
  idCutterClip::Edge_t *nextAEL; // r31
  idCutterClip::Edge_t *v14; // r25
  int v15; // r29
  idCutterClip::Edge_t *nextLML; // r30
  char v17; // r11
  int v18; // r4
  idCutterClip *v19; // r3
  char IsTopHorizontal; // r3
  idCutterClip::Edge_t *v21; // r5
  idCutterClip::Edge_t *v22; // r4
  idCutterClip::intersectProtects_t v23; // r7
  int v24; // r11
  unsigned __int8 v25; // r3
  int outIndex; // r6
  int y; // r10
  idCutterClip::Edge_t *prevAEL; // r11
  idCutterClip::Edge_t *v29; // r10
  idCutterClip::Edge_t *v30; // r11
  idCutterClip::Edge_t *v31; // r10
  idVec2i v32[14]; // [sp+50h] [-70h] BYREF

  x = edge->current.x;
  v4 = edge->top.x;
  p_top = &edge->top;
  v7 = 1;
  if ( x < v4 )
  {
    v8 = edge->current.x;
  }
  else
  {
    v7 = 2;
    v8 = edge->top.x;
  }
  v9 = edge->current.x;
  if ( x <= v4 )
    v9 = edge->top.x;
  if ( edge->nextLML != nullptr )
  {
    prev = nullptr;
  }
  else
  {
    next = edge->next;
    if ( next == nullptr || next->top.y != edge->top.y || (v12 = 1, next->nextLML != nullptr) )
      v12 = 0;
    if ( v12 == 0 || (prev = edge->next, v4 != next->top.x) )
      prev = edge->prev;
  }
  if ( v7 == 1 )
    nextAEL = edge->nextAEL;
  else
    nextAEL = edge->prevAEL;
  if ( nextAEL == nullptr )
    goto LABEL_42;
  while ( 1 )
  {
    v14 = v7 == 1 ? nextAEL->nextAEL : nextAEL->prevAEL;
    if ( prev != nullptr )
      break;
    if ( v7 == 1 )
    {
      if ( nextAEL->current.x <= v9 )
        break;
    }
    else if ( nextAEL->current.x >= v8 )
    {
      break;
    }
    if ( edge->nextSEL != nullptr || v7 != 1 )
    {
      if ( v7 == 2 && nextAEL->current.x < v8 )
        goto LABEL_42;
    }
    else if ( nextAEL->current.x > v9 )
    {
      goto LABEL_42;
    }
LABEL_52:
    nextAEL = v14;
    if ( v14 == nullptr )
      goto LABEL_42;
  }
  v15 = nextAEL->current.x;
  if ( v15 != p_top->x || prev != nullptr )
  {
LABEL_29:
    v32[0].y = edge->current.y;
    v32[0].x = v15;
    if ( nextAEL == prev )
    {
      if ( v7 == 1 )
        idCutterClip::IntersectEdges(this, edge1: edge, edge2: nextAEL, pos: v32, protects: INTERSECTPROTECTS_NONE);
      else
        idCutterClip::IntersectEdges(this, edge1: nextAEL, edge2: edge, pos: v32, protects: INTERSECTPROTECTS_NONE);
      return;
    }
    if ( (*((_WORD *)nextAEL + 36) & 0x2000) == 0 )
      goto LABEL_49;
    if ( nextAEL->prev->nextLML == nextAEL || (v17 = 1, nextAEL->next->nextLML == nextAEL) )
      v17 = 0;
    if ( v17 != 0 || (v18 = nextAEL->top.x, v15 > v18) )
    {
LABEL_49:
      v18 = nextAEL->top.x;
      v19 = this;
      if ( v7 == 1 )
        goto LABEL_37;
    }
    else
    {
      v19 = this;
      if ( v7 == 1 )
      {
LABEL_37:
        IsTopHorizontal = idCutterClip::IsTopHorizontal(this, x: v18);
        v21 = nextAEL;
        v22 = edge;
        v23 = IsTopHorizontal == 0 ? INTERSECTPROTECTS_BOTH : INTERSECTPROTECTS_LEFT;
LABEL_51:
        idCutterClip::IntersectEdges(this, edge1: v22, edge2: v21, pos: v32, protects: v23);
        idCutterClip::SwapEdgeInAEL(this, edge1: edge, edge2: nextAEL);
        goto LABEL_52;
      }
    }
    v25 = idCutterClip::IsTopHorizontal(this: v19, x: v18);
    v22 = nextAEL;
    v21 = edge;
    v23 = ((_cntlzw(v25) & 0x20) != 0) + 2;
    goto LABEL_51;
  }
  nextLML = edge->nextLML;
  if ( !idCutterClip::SlopesEqual(edge1: nextAEL, edge2: nextLML) )
  {
    if ( nextAEL->deltaX < (double)nextLML->deltaX )
      goto LABEL_42;
    goto LABEL_29;
  }
  outIndex = (unsigned __int16)edge->outIndex;
  if ( outIndex != 0xFFFF && (unsigned __int16)nextAEL->outIndex != 0xFFFF )
    idCutterClip::AddJoinRecord(this, edge1: nextLML, edge2: nextAEL, outIndexEdge1: outIndex, outIndexEdge2: -1);
LABEL_42:
  v24 = (unsigned __int16)edge->outIndex;
  if ( edge->nextLML != nullptr )
  {
    if ( v24 != 0xFFFF )
      idCutterClip::AddPolygonPoint(this, edge1: edge, edge2: nullptr, pos: p_top);
    idCutterClip::UpdateEdgeInAEL(this, edge);
  }
  else
  {
    if ( v24 != 0xFFFF )
    {
      y = edge->current.y;
      v32[0].x = p_top->x;
      v32[0].y = y;
      idCutterClip::IntersectEdges(this, edge1: edge, edge2: prev, pos: v32, protects: INTERSECTPROTECTS_BOTH);
    }
    prevAEL = prev->prevAEL;
    v29 = prev->nextAEL;
    if ( prevAEL != nullptr || v29 != nullptr || prev == this->activeEdges )
    {
      prev->nextAEL = nullptr;
      prev->prevAEL = nullptr;
      if ( prevAEL != nullptr )
        prevAEL->nextAEL = v29;
      if ( v29 != nullptr )
        v29->prevAEL = prevAEL;
      if ( prevAEL == nullptr )
        this->activeEdges = v29;
    }
    v30 = edge->prevAEL;
    v31 = edge->nextAEL;
    if ( v30 != nullptr || v31 != nullptr || edge == this->activeEdges )
    {
      edge->nextAEL = nullptr;
      edge->prevAEL = nullptr;
      if ( v30 != nullptr )
        v30->nextAEL = v31;
      if ( v31 != nullptr )
        v31->prevAEL = v30;
      if ( v30 == nullptr )
        this->activeEdges = v31;
    }
  }
}


// ========================================================================
// ?GetPolygon@idCutterClip@@QAAXHAAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827B8EC0
// RVA : 0x007B8EC0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::GetPolygon(idCutterClip *this, int id, idList<idVehicleState *,5> *list)
{
  idCutterClip::NestedPolygon_t *v6; // r11

  if ( list->size < 0 )
    idList<idThread *,58>::Clear(this: list);
  list->num = __CFADD__(-list->size, list->size ^ 0x80000000) ? 0 : list->size;
  v6 = this->nestedPolygons.list[id];
  this->currentNestedPolygon = v6;
  if ( v6 != nullptr )
  {
    idCutterClip::GetPolygon(polygon: v6->outer, (idList<idSkinMapping,46> *)list);
    this->currentInnerPolygon = this->currentNestedPolygon->inner;
  }
  else
  {
    this->currentInnerPolygon = nullptr;
  }
}


// ========================================================================
// ?GetInnerPolygon@idCutterClip@@QAAXAAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827B8F50
// RVA : 0x007B8F50
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::GetInnerPolygon(idCutterClip *this, idList<idVehicleState *,5> *list)
{
  idCutterClip::Polygon_t *currentInnerPolygon; // r3

  if ( list->size < 0 )
    idList<idThread *,58>::Clear(this: list);
  list->num = __CFADD__(-list->size, list->size ^ 0x80000000) ? 0 : list->size;
  currentInnerPolygon = this->currentInnerPolygon;
  if ( currentInnerPolygon != nullptr )
  {
    idCutterClip::GetPolygon(polygon: currentInnerPolygon, (idList<idSkinMapping,46> *)list);
    this->currentInnerPolygon = this->currentInnerPolygon->next;
  }
}


// ========================================================================
// ?GetConnectedPolygon@idCutterClip@@QAAXHAAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827B8FD8
// RVA : 0x007B8FD8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::GetConnectedPolygon(idCutterClip *this, int index, idList<idVehicleState *,5> *list)
{
  idCutterClip::Polygon_t *v6; // r3

  if ( list->size < 0 )
    idList<idThread *,58>::Clear(this: list);
  list->num = __CFADD__(-list->size, list->size ^ 0x80000000) ? 0 : list->size;
  v6 = this->polygons.list[index];
  if ( v6->connected )
    idCutterClip::GetPolygon(polygon: v6, (idList<idSkinMapping,46> *)list);
}


// ========================================================================
// ?JoinEdges@idCutterClip@@AAAXXZ
// EA  : 0x827B9050
// RVA : 0x007B9050
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::JoinEdges(idCutterClip *this)
{
  idList<enum encounterGroupRole_t,5> *p_polygons; // r18
  int v3; // r19
  int v4; // r20
  idCutterClip::JoinRecord_t *v5; // r24
  __int128 v6; // r7
  int v7; // r8
  int polyIndex2; // r9
  idVec2i point1b; // r31
  idCutterClip::Polygon_t *v10; // r23
  idCutterClip::Polygon_t *v11; // r27
  idCutterClip::PolygonPoint_t *points; // r11
  idCutterClip::PolygonPoint_t *v13; // r31
  bool v14; // zf
  int v15; // r25
  int v16; // r26
  idCutterClip::PolygonPoint_t *v17; // r9
  int v18; // r8
  idCutterClip::PolygonPoint_t *v19; // r10
  idCutterClip::PolygonPoint_t *next; // r11
  int x; // r4
  int v22; // r3
  idCutterClip::PolygonPoint_t *v23; // r9
  int v24; // r8
  idCutterClip::PolygonPoint_t *v25; // r10
  idCutterClip::PolygonPoint_t *v26; // r11
  int v27; // r4
  int v28; // r3
  idCutterClip::PolygonPoint_t *v29; // r28
  idCutterClip::PolygonPoint_t *prev; // r29
  idCutterClip::PolygonPoint_t *v31; // r17
  idCutterClip::PolygonPoint_t *v32; // r30
  idCutterClip::PolygonPoint_t *v33; // r31
  idCutterClip::PolygonPoint_t *v34; // r29
  idCutterClip::PolygonPoint_t *v35; // r3
  idCutterClip::PolygonPoint_t *v36; // r11
  idCutterClip::PolygonPoint_t *v37; // r10
  int v38; // r9
  int v39; // r4
  int v40; // r3
  idCutterClip::PolygonPoint_t *v41; // r11
  idCutterClip::PolygonPoint_t *v42; // r10
  int v43; // r9
  signed int v44; // r7
  int v45; // r4
  int v46; // r3
  const idCutterClip::PolygonPoint_t *v47; // r28
  idCutterClip::PolygonPoint_t *v48; // r11
  idCutterClip::PolygonPoint_t *Bottom; // r3
  int index; // r11
  idCutterClip::PolygonPoint_t *v51; // r3
  int num; // r9
  idCutterClip::Polygon_t *v53; // r29
  idCutterClip::PolygonPoint_t *v54; // r3
  idCutterClip::PolygonPoint_t *v55; // r11
  idCutterClip::PolygonPoint_t *v56; // r10
  idCutterClip::PolygonPoint_t *v57; // r9
  bool v58; // cr58
  bool v59; // r3
  unsigned int hole; // r11
  idCutterClip::Polygon_t *firstLeft; // r7
  const idCutterClip::PolygonPoint_t *v62; // r31
  idCutterClip::PolygonPoint_t *v63; // r11
  idCutterClip::PolygonPoint_t *v64; // r10
  idCutterClip::PolygonPoint_t *v65; // r9
  bool v66; // cr58
  int v67; // r5
  int v68; // r6
  int v69; // r7
  int v70; // r7
  idCutterClip::Polygon_t *v71; // r4
  int v72; // r8
  idCutterClip::Polygon_t *v73; // r6
  int v74; // r9
  int v75; // r7
  int v76; // r10
  int v77; // r11
  idCutterClip::PolygonPoint_t *v78; // [sp+50h] [-C0h] BYREF
  idCutterClip::PolygonPoint_t *v79; // [sp+54h] [-BCh] BYREF
  idVec2i v80; // [sp+58h] [-B8h] BYREF
  idVec2i v81; // [sp+60h] [-B0h] BYREF
  idVec2i point2b; // [sp+68h] [-A8h] BYREF
  idVec2i v83; // [sp+70h] [-A0h] BYREF
  idVec2i v84; // [sp+78h] [-98h] BYREF
  idVec2i v85[18]; // [sp+80h] [-90h] BYREF

  if ( this->joins.num > 0 )
  {
    p_polygons = (idList<enum encounterGroupRole_t,5> *)&this->polygons;
    v3 = 1;
    v4 = 1;
    do
    {
      v5 = this->joins.list[v4 - 1];
      *((_QWORD *)&v6 + 1) = v5->point2a;
      v7 = 4 * v5->polyIndex1;
      *(idVec2i *)((char *)&v6 + 4) = v5->point1a;
      polyIndex2 = v5->polyIndex2;
      point1b = v5->point1b;
      point2b = v5->point2b;
      v83 = (idVec2i)v6;
      v10 = *(idCutterClip::Polygon_t **)(v7 + point2b.x);
      v81 = *(idVec2i *)((char *)&v6 + 4);
      v80 = point1b;
      v11 = *(idCutterClip::Polygon_t **)(4 * polyIndex2 + point2b.x);
      points = v11->points;
      v79 = v10->points;
      v78 = points;
      if ( (unsigned __int8)idCutterClip::FindSegment(point: &v79, p1: &v83, p2: (idVec2i *)DWORD1(v6)) != 0 )
      {
        v13 = v79;
        if ( v5->polyIndex1 != v5->polyIndex2 || (v14 = v79 == v79->next, v78 = v79->next, !v14) )
        {
          if ( (unsigned __int8)idCutterClip::FindSegment(point: &v78, p1: &v81, p2: &v80) != 0
            && (unsigned __int8)idCutterClip::IsSegmentOverlapping(
                                  p1a: &v83,
                                  p1b: &point2b,
                                  p2a: &v81,
                                  p2b: &v80,
                                  overlap1: &v84,
                                  overlap2: v85) != 0 )
          {
            v15 = 0;
            v16 = 0;
            if ( v5->polyIndex1 != v5->polyIndex2 )
            {
              v17 = v10->points;
              v18 = 0;
              v19 = v17;
              next = v17->next;
              do
              {
                x = v19->pos.x;
                v22 = next->pos.x * v19->pos.y;
                v19 = next;
                v18 += next->pos.y * x - v22;
                v14 = next != v17;
                next = next->next;
              }
              while ( v14 );
              v23 = v11->points;
              v15 = v18;
              v24 = 0;
              v25 = v23;
              v26 = v23->next;
              do
              {
                v27 = v25->pos.x;
                v28 = v26->pos.x * v25->pos.y;
                v25 = v26;
                v24 += v26->pos.y * v27 - v28;
                v14 = v26 != v23;
                v26 = v26->next;
              }
              while ( v14 );
              v16 = v24;
            }
            v29 = v78;
            prev = v13->prev;
            v31 = v78->prev;
            v32 = idCutterClip::AddPolygonPoint(this, p1: v13, p2: prev, p3: nullptr, pos: &v84);
            v33 = idCutterClip::AddPolygonPoint(this, p1: v13, p2: v32, p3: prev, pos: v85);
            v34 = idCutterClip::AddPolygonPoint(this, p1: v29, p2: v31, p3: nullptr, pos: &v84);
            v35 = idCutterClip::AddPolygonPoint(this, p1: v29, p2: v34, p3: v31, pos: v85);
            if ( v32->next == v33 && v34->prev == v35 )
            {
              v32->next = v34;
              v34->prev = v32;
              v33->prev = v35;
              v35->next = v33;
LABEL_20:
              if ( v5->polyIndex1 == v5->polyIndex2 )
              {
                v36 = v32->next;
                v37 = v32;
                v38 = 0;
                do
                {
                  v39 = v36->pos.x * v37->pos.y;
                  v40 = v36->pos.y * v37->pos.x;
                  v37 = v36;
                  v38 += v40 - v39;
                  v14 = v36 != v32;
                  v36 = v36->next;
                }
                while ( v14 );
                v41 = v33->next;
                v42 = v33;
                v44 = abs32(v38);
                v43 = 0;
                do
                {
                  v45 = v42->pos.x;
                  v46 = v41->pos.x * v42->pos.y;
                  v42 = v41;
                  v43 += v41->pos.y * v45 - v46;
                  v14 = v41 != v33;
                  v41 = v41->next;
                }
                while ( v14 );
                v47 = v33;
                if ( v44 < (int)abs32(v43) )
                {
                  v48 = v32;
                  v32 = v33;
                  v33 = v48;
                }
                Bottom = idCutterClip::FindBottom(point: v32);
                index = v10->index;
                v10->points = Bottom;
                v10->bottomPoint = Bottom;
                Bottom->index = index;
                v51 = (idCutterClip::PolygonPoint_t *)idCutterClip::AllocPolygon(this);
                num = this->polygons.num;
                v53 = (idCutterClip::Polygon_t *)v51;
                v79 = v51;
                v51[1].pos.x = num;
                v54 = idCutterClip::FindBottom(point: v33);
                v53->points = v54;
                v53->bottomPoint = v54;
                v54->index = v53->index;
                v5->polyIndex2 = v53->index;
                idList<idAnimWebBlendTree *,5>::Append(this: p_polygons, obj: (const encounterGroupRole_t *)&v79);
                if ( idCutterClip::PointInPolygon(pos: &v33->pos, point: v32) )
                {
                  v53->hole = (_cntlzw(v10->hole) & 0x20) != 0;
                  v53->firstLeft = v10;
                  if ( v53->hole == (unsigned __int8)idCutterClip::IsClockwise(points: v33) )
                  {
                    v55 = v33;
                    do
                    {
                      v56 = v55->next;
                      v57 = v55->prev;
                      v58 = v55->next == v33;
                      v55->prev = v55->next;
                      v55->next = v57;
                      v55 = v56;
                    }
                    while ( !v58 );
                  }
                }
                else
                {
                  v59 = idCutterClip::PointInPolygon(pos: &v32->pos, point: v33);
                  hole = v10->hole;
                  v53->hole = hole;
                  if ( v59 )
                  {
                    firstLeft = v10->firstLeft;
                    v10->hole = (_cntlzw(hole) & 0x20) != 0;
                    v53->firstLeft = firstLeft;
                    v10->firstLeft = v53;
                    v62 = v10->points;
                    if ( v10->hole == (unsigned __int8)idCutterClip::IsClockwise(points: v62) )
                    {
                      v63 = (idCutterClip::PolygonPoint_t *)v62;
                      do
                      {
                        v64 = v63->next;
                        v65 = v63->prev;
                        v66 = v63->next == v62;
                        v63->prev = v63->next;
                        v63->next = v65;
                        v63 = v64;
                      }
                      while ( !v66 );
                    }
                  }
                  else
                  {
                    v53->firstLeft = v10->firstLeft;
                  }
                }
                v67 = v3;
                if ( v3 < this->joins.num )
                {
                  v68 = v4 * 4;
                  do
                  {
                    v69 = *(int *)((char *)this->joins.list + v68);
                    if ( *(unsigned __int16 *)(v69 + 36) == (unsigned __int16)v5->polyIndex1
                      && (unsigned __int8)idCutterClip::IsPolygonPoint(pos: (const idVec2i *)(v69 + 4), point: v47) != 0 )
                    {
                      *(_WORD *)(v69 + 36) = v5->polyIndex2;
                    }
                    if ( *(unsigned __int16 *)(v69 + 38) == (unsigned __int16)v5->polyIndex1
                      && (unsigned __int8)idCutterClip::IsPolygonPoint(pos: (const idVec2i *)(v69 + 20), point: v47) != 0 )
                    {
                      *(_WORD *)(v70 + 38) = v5->polyIndex2;
                    }
                    ++v67;
                    v68 += 4;
                  }
                  while ( v67 < this->joins.num );
                }
                idCutterClip::FixupPolygon(this, polygon: v10);
                v71 = v53;
              }
              else
              {
                v72 = v10->index;
                v73 = v10;
                v74 = v11->index;
                v71 = v11;
                if ( v15 < v16 )
                {
                  v72 = v11->index;
                  v73 = v11;
                  v71 = v10;
                  v74 = v10->index;
                  v11->points = v10->points;
                }
                v71->appendLink = v73;
                v71->points = nullptr;
                v71->bottomPoint = nullptr;
                if ( v73->hole && !v71->hole )
                  v73->hole = false;
                v75 = v3;
                if ( v3 < this->joins.num )
                {
                  v76 = v4 * 4;
                  do
                  {
                    v77 = *(int *)((char *)this->joins.list + v76);
                    if ( *(__int16 *)(v77 + 36) == v74 )
                      *(_WORD *)(v77 + 36) = v72;
                    if ( *(__int16 *)(v77 + 38) == v74 )
                      *(_WORD *)(v77 + 38) = v72;
                    ++v75;
                    v76 += 4;
                  }
                  while ( v75 < this->joins.num );
                }
                if ( v73->points != nullptr )
                  v71 = v73;
              }
              idCutterClip::FixupPolygon(this, polygon: v71);
              goto LABEL_63;
            }
            if ( v32->prev == v33 && v34->next == v35 )
            {
              v32->prev = v34;
              v34->next = v32;
              v33->next = v35;
              v35->prev = v33;
              goto LABEL_20;
            }
          }
        }
      }
LABEL_63:
      ++v3;
      ++v4;
    }
    while ( v3 - 1 < this->joins.num );
  }
}


// ========================================================================
// ?ProcessHorizontals@idCutterClip@@AAAXXZ
// EA  : 0x827B9668
// RVA : 0x007B9668
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ProcessHorizontals(idCutterClip *this)
{
  idCutterClip::Edge_t *i; // r4
  idCutterClip::Edge_t *prevSEL; // r11
  idCutterClip::Edge_t *nextSEL; // r10

  for ( i = this->sortedEdges; i != nullptr; i = this->sortedEdges )
  {
    prevSEL = i->prevSEL;
    nextSEL = i->nextSEL;
    i->nextSEL = nullptr;
    i->prevSEL = nullptr;
    if ( prevSEL != nullptr )
      prevSEL->nextSEL = nextSEL;
    if ( nextSEL != nullptr )
      nextSEL->prevSEL = prevSEL;
    if ( prevSEL == nullptr )
      this->sortedEdges = nextSEL;
    idCutterClip::ProcessHorizontal(this, edge: i);
  }
}


// ========================================================================
// ?ProcessEdgesAtTopOfScanbeam@idCutterClip@@AAAXH@Z
// EA  : 0x827B96F0
// RVA : 0x007B96F0
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void __fastcall idCutterClip::ProcessEdgesAtTopOfScanbeam(
        idCutterClip *this,
        int y,
        long double a3,
        int a4,
        int a5,
        __int64 a6)
{
  idCutterClip::Edge_t *activeEdges; // r31
  char v9; // r11
  int next; // r5
  char v11; // r11
  idCutterClip::Edge_t *prevAEL; // r30
  char v13; // r11
  int v14; // r26
  int v15; // r27
  idCutterClip::Edge_t *nextLML; // r30
  idCutterClip::HorizontalJoinRecord_t *v17; // r28
  idCutterClip::Edge_t *edge; // r29
  __int16 outIndex; // r30
  idCutterClip::Edge_t *v20; // r29
  idCutterClip::HorizontalJoinRecord_t *v21; // r3
  idCutterClip::Edge_t *updated; // r3
  idCutterClip::Edge_t *sortedEdges; // r11
  idCutterClip::Edge_t *v24; // r11
  int v25; // r3
  signed int v26; // r11
  idCutterClip::Edge_t *i; // r31
  char v28; // r11
  idCutterClip::Edge_t *v29; // r3
  idCutterClip::Edge_t *v30; // r30
  idCutterClip::Edge_t *nextAEL; // r28
  const idVec2i *p_bottom; // r29
  char v33; // r11
  idCutterClip::Edge_t *v34; // r5
  int v35; // r11
  char v36; // r11
  idCutterClip::HorizontalJoinRecord_t *v37; // [sp+50h] [-60h] BYREF

  activeEdges = this->activeEdges;
  while ( activeEdges != nullptr )
  {
    if ( activeEdges->top.y != y || (v9 = 1, activeEdges->nextLML != nullptr) )
      v9 = 0;
    if ( v9 != 0 )
    {
      next = (int)activeEdges->next;
      if ( next == 0 || *(_DWORD *)(next + 36) != activeEdges->top.y || (v11 = 1, *(_DWORD *)(next + 12) != 0) )
        v11 = 0;
      if ( v11 == 0 || activeEdges->top.x != *(_DWORD *)(next + 32) )
        next = (int)activeEdges->prev;
    }
    else
    {
      next = 0;
    }
    if ( next == 0 || (*(_WORD *)(next + 72) & 0x2000) != 0 )
    {
      if ( activeEdges->top.y != y || (v13 = 1, activeEdges->nextLML == nullptr) )
        v13 = 0;
      if ( v13 != 0 && (*((_WORD *)activeEdges->nextLML + 36) & 0x2000) != 0 )
      {
        if ( (unsigned __int16)activeEdges->outIndex != 0xFFFF )
        {
          idCutterClip::AddPolygonPoint(this, edge1: activeEdges, edge2: nullptr, pos: &activeEdges->top);
          v14 = 0;
          if ( this->horizontalJoins.num > 0 )
          {
            v15 = 0;
            do
            {
              nextLML = activeEdges->nextLML;
              v17 = this->horizontalJoins.list[v15];
              edge = v17->edge;
              if ( (unsigned __int8)idCutterClip::IsSegmentOverlapping(
                                      p1a: &edge->bottom,
                                      p1b: &edge->top,
                                      p2a: &nextLML->bottom,
                                      p2b: &nextLML->top,
                                      overlap1: nullptr,
                                      overlap2: nullptr) != 0 )
                idCutterClip::AddJoinRecord(
                  this,
                  edge1: edge,
                  edge2: nextLML,
                  outIndexEdge1: v17->savedIndex,
                  outIndexEdge2: activeEdges->outIndex);
              ++v14;
              ++v15;
            }
            while ( v14 < this->horizontalJoins.num );
          }
          outIndex = activeEdges->outIndex;
          v20 = activeEdges->nextLML;
          v21 = idCutterClip::AllocHorizontalJoinRecord(this);
          v37 = v21;
          v21->edge = v20;
          v21->savedIndex = outIndex;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->horizontalJoins,
            obj: (const encounterGroupRole_t *)&v37);
        }
        updated = idCutterClip::UpdateEdgeInAEL(this, edge: activeEdges);
        sortedEdges = this->sortedEdges;
        activeEdges = updated;
        if ( sortedEdges != nullptr )
          sortedEdges->prevSEL = updated;
        v24 = this->sortedEdges;
        updated->prevSEL = nullptr;
        updated->nextSEL = v24;
        this->sortedEdges = updated;
      }
      else
      {
        v25 = idCutterClip::CalculateTopX(edge: activeEdges, y, a3, a4: next, a5: a6);
        v26 = idCutterClip::precisionModifier;
        LODWORD(a6) = __ROL4__(v25, 1) - 1;
        activeEdges->current.y = y;
        HIDWORD(a6) = v26 & ~(_DWORD)a6;
        __twllei(v26, 0);
        activeEdges->current.x = v25 / v26;
        __twlgei(HIDWORD(a6), 0xFFFFFFFF);
      }
      activeEdges = activeEdges->nextAEL;
    }
    else
    {
      prevAEL = activeEdges->prevAEL;
      idCutterClip::DoMaxima(this, edge: activeEdges, edgeMaxPair: (idCutterClip::Edge_t *)next, y);
      if ( prevAEL != nullptr )
        activeEdges = prevAEL->nextAEL;
      else
        activeEdges = this->activeEdges;
    }
  }
  idCutterClip::ProcessHorizontals(this);
  for ( i = this->activeEdges; i != nullptr; i = i->nextAEL )
  {
    if ( i->top.y != y || (v28 = 1, i->nextLML == nullptr) )
      v28 = 0;
    if ( v28 == 0 )
      continue;
    if ( (unsigned __int16)i->outIndex != 0xFFFF )
      idCutterClip::AddPolygonPoint(this, edge1: i, edge2: nullptr, pos: &i->top);
    v29 = idCutterClip::UpdateEdgeInAEL(this, edge: i);
    v30 = v29->prevAEL;
    i = v29;
    nextAEL = v29->nextAEL;
    if ( v29->outIndex == -1 )
      continue;
    if ( v30 == nullptr || (unsigned __int16)v30->outIndex == 0xFFFF )
      goto LABEL_61;
    p_bottom = &v29->bottom;
    if ( v30->current.x != v29->bottom.x || (v33 = 1, v30->current.y != v29->bottom.y) )
      v33 = 0;
    if ( v33 != 0 && Contour::SlopesEqual(v1: &v29->bottom, v2: &v29->top, v3: &v29->bottom, v4: &v30->top) )
    {
      idCutterClip::AddPolygonPoint(this, edge1: v30, edge2: nullptr, pos: p_bottom);
      v34 = v30;
    }
    else
    {
LABEL_61:
      if ( nextAEL == nullptr )
        continue;
      if ( (unsigned __int16)nextAEL->outIndex == 0xFFFF )
        continue;
      v35 = nextAEL->current.y;
      if ( v35 <= nextAEL->top.y || v35 >= nextAEL->bottom.y )
        continue;
      if ( nextAEL->current.x != i->bottom.x || (v36 = 1, nextAEL->current.y != i->bottom.y) )
        v36 = 0;
      if ( v36 == 0 || !Contour::SlopesEqual(v1: &i->bottom, v2: &i->top, v3: &i->bottom, v4: &nextAEL->top) )
        continue;
      idCutterClip::AddPolygonPoint(this, edge1: nextAEL, edge2: nullptr, pos: &i->bottom);
      v34 = nextAEL;
    }
    idCutterClip::AddJoinRecord(this, edge1: i, edge2: v34, outIndexEdge1: -1, outIndexEdge2: -1);
  }
}


// ========================================================================
// ?Clip@idCutterClip@@QAA_NW4clipMode_t@@W4fillType_t@@@Z
// EA  : 0x827B9B40
// RVA : 0x007B9B40
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

int __fastcall idCutterClip::Clip(idCutterClip *this, clipMode_t clipMode_, fillType_t fillType)
{
  idCutterClip::Scanbeam_t *scanbeams; // r11
  idCutterClip::Scanbeam_t *next; // r10
  int y; // r29
  __int64 v7; // r8
  int v8; // r6
  int v9; // r5
  long double v10; // fp2
  idCutterClip::Scanbeam_t *v11; // r11
  idCutterClip::Edge_t *activeEdges; // r10
  idCutterClip::Scanbeam_t *v13; // r9
  int v14; // r27
  unsigned __int8 v15; // r11
  int v16; // r28
  int v17; // r26
  int v18; // r27
  idCutterClip::Polygon_t **list; // r11
  idCutterClip::Polygon_t *v20; // r29
  idCutterClip::Polygon_t *v21; // r4
  idCutterClip *v22; // r3
  const idCutterClip::PolygonPoint_t *points; // r28
  idCutterClip::PolygonPoint_t *v24; // r11
  idCutterClip::PolygonPoint_t *v25; // r10
  idCutterClip::PolygonPoint_t *prev; // r9
  bool v27; // cr58
  __int64 v28; // r10
  int v29; // r8
  int v30; // r7
  int v31; // r6
  idCutterClip::Polygon_t **v32; // r4
  unsigned int num; // r5
  idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons> v35; // [sp+50h] [-40h] BYREF
  idCutterClip::Polygon_t **v36; // [sp+54h] [-3Ch]

  this->clipMode = clipMode_;
  this->fillTypeClip = fillType;
  this->fillTypeSubject = fillType;
  idCutterClip::Reset(this);
  if ( this->currentLocalMinima != nullptr )
  {
    scanbeams = this->scanbeams;
    next = scanbeams->next;
    v36 = (idCutterClip::Polygon_t **)scanbeams;
    this->scanbeams = next;
    y = scanbeams->y;
    while ( 1 )
    {
      idCutterClip::AddLocalMinimaToAEL(this, yBottom: y);
      idCutterClip::ClearHorizontalJoinRecords(this);
      idCutterClip::ProcessHorizontals(this);
      v11 = this->scanbeams;
      activeEdges = this->activeEdges;
      v13 = v11->next;
      v36 = (idCutterClip::Polygon_t **)v11;
      this->scanbeams = v13;
      v14 = v11->y;
      if ( activeEdges != nullptr )
      {
        idCutterClip::BuildIntersectList(this, yBottom: y, yTop: v11->y, a4: v10, a5: v8, a6: v7);
        if ( this->intersectNodes != nullptr )
        {
          if ( (unsigned __int8)idCutterClip::FixupIntersections(this) != 0 )
          {
            idCutterClip::ProcessIntersectList(this);
            v15 = 1;
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          v15 = 1;
        }
      }
      else
      {
        v15 = 1;
      }
      v16 = v15;
      if ( v15 != 0 )
        idCutterClip::ProcessEdgesAtTopOfScanbeam(this, y: v14, a3: v10, a4: v9, a5: v8, a6: v7);
      y = v14;
      if ( v16 == 0 )
        break;
      if ( this->scanbeams == nullptr )
      {
        v17 = 0;
        if ( this->polygons.num > 0 )
        {
          v18 = 0;
          do
          {
            list = this->polygons.list;
            v20 = list[v18];
            if ( v20->points != nullptr )
            {
              idCutterClip::FixupPolygon(this, polygon: list[v18]);
              if ( v20->points != nullptr )
              {
                if ( v20->hole )
                  idCutterClip::FixHoleLinkage_r(this: v22, polygon: v21);
                points = v20->points;
                if ( v20->hole == (unsigned __int8)idCutterClip::IsClockwise(points) )
                {
                  v24 = (idCutterClip::PolygonPoint_t *)points;
                  do
                  {
                    v25 = v24->next;
                    prev = v24->prev;
                    v27 = v24->next == points;
                    v24->prev = v24->next;
                    v24->next = prev;
                    v24 = v25;
                  }
                  while ( !v27 );
                }
              }
            }
            ++v17;
            ++v18;
          }
          while ( v17 < this->polygons.num );
        }
        idCutterClip::JoinEdges(this);
        v35.__vftable = (idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons>_vtbl *)&idCutterClip::idSort_Polygons::`vftable';
        v32 = this->polygons.list;
        if ( v32 != nullptr )
        {
          num = this->polygons.num;
          v36 = this->polygons.list;
          idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons>::Sort(
            this: &v35,
            base: v32,
            num,
            a4: v31,
            a5: v30,
            a6: v29,
            a7: v28);
        }
        v35.__vftable = (idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons>_vtbl *)&idSort<idCutterClip::Polygon_t *>::`vftable';
        idCutterClip::BuildResult(this);
        return 1;
      }
    }
  }
  return 1;
}


// ========================================================================
// __unwind$227724
// EA  : 0x827B9D44
// RVA : 0x007B9D44
// PDB : w:\tech5\engine\models\cuttable\cutterclip.cpp
// ========================================================================

void _unwind_227724()
{
  int v0; // r12

  idCutterClip::idSort_Polygons::~idSort_Polygons(this: (idCutterClip::idSort_Polygons *)(v0 - 144 + 80));
}

