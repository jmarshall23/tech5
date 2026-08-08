
// ========================================================================
// ?SlopesEqual@Contour@@SA_NABVidVec2i@@000@Z
// EA  : 0x827B1EE0
// RVA : 0x007B1EE0
// PDB : w:\tech5\engine\models\cuttable\contourinfo.cpp
// ========================================================================

BOOL __fastcall Contour::SlopesEqual(const idVec2i *v1, const idVec2i *v2, const idVec2i *v3, const idVec2i *v4)
{
  int y; // r9
  int v5; // r8

  y = v1->y;
  v5 = v2->y;
  if ( y == v5 )
    return (_cntlzw(v4->y - v3->y) & 0x20) != 0;
  if ( v1->x == v2->x )
    return (_cntlzw(v4->x - v3->x) & 0x20) != 0;
  return (_cntlzw((v3->x - v4->x) * (y - v5) - (v3->y - v4->y) * (v1->x - v2->x)) & 0x20) != 0;
}


// ========================================================================
// ?SlopesEqual@Contour@@SA_NABVidVec2i@@00@Z
// EA  : 0x827B1F68
// RVA : 0x007B1F68
// PDB : w:\tech5\engine\models\cuttable\contourinfo.cpp
// ========================================================================

BOOL __fastcall Contour::SlopesEqual(const idVec2i *v1, const idVec2i *v2, const idVec2i *v3)
{
  int y; // r9
  int v4; // r11
  int x; // r11

  y = v1->y;
  v4 = v2->y;
  if ( y == v4 )
    return (_cntlzw(v3->y - v4) & 0x20) != 0;
  x = v2->x;
  if ( v1->x == v2->x )
    return (_cntlzw(v3->x - x) & 0x20) != 0;
  else
    return (_cntlzw((x - v3->x) * (y - v2->y) - (v2->y - v3->y) * (v1->x - x)) & 0x20) != 0;
}


// ========================================================================
// ?FindEdge@Contour@@QAAPAUContourEdge_t@@ABVidVec2i@@0@Z
// EA  : 0x827B1FE8
// RVA : 0x007B1FE8
// PDB : w:\tech5\engine\models\cuttable\contourinfo.cpp
// ========================================================================

ContourEdge_t *__fastcall Contour::FindEdge(Contour *this, const idVec2i *v0, const idVec2i *v1, int a4, __int64 a5)
{
  Contour *v7; // r28
  ContourEdge_t *result; // r3
  ContourNode_t *node; // r9
  int x; // r10
  char v11; // r11
  char v12; // r11
  __int64 v13; // r11
  __int64 v14; // kr00_8
  char v15; // r11
  idVec2 v16; // [sp+58h] [-58h] BYREF
  idVec2 v17; // [sp+60h] [-50h] BYREF
  __int64 v18; // [sp+68h] [-48h]
  __int64 v19; // [sp+70h] [-40h]
  __int64 v20; // [sp+78h] [-38h]
  __int64 v21; // [sp+80h] [-30h]

  v7 = this;
  if ( this == nullptr )
    return nullptr;
  while ( 1 )
  {
    v18 = (__int64)*v0;
    LODWORD(a5) = HIDWORD(v18);
    v19 = a5;
    v16.y = (float)v18;
    v16.x = (float)a5;
    HIDWORD(a5) = idBounds2D::ContainsPoint(this: &v7->bound, point: &v16);
    if ( HIDWORD(a5) != 0
      || (v21 = (__int64)*v1,
          v20 = HIDWORD(v21),
          v17.y = (float)v21,
          v17.x = (float)HIDWORD(v21),
          HIDWORD(a5) = idBounds2D::ContainsPoint(this: &v7->bound, point: &v17),
          HIDWORD(a5) != 0) )
    {
      result = v7->edges;
      if ( result != nullptr )
        break;
    }
LABEL_25:
    v7 = v7->next;
    if ( v7 == nullptr )
      return nullptr;
  }
  while ( 1 )
  {
    node = result->node;
    if ( node != nullptr )
      break;
LABEL_24:
    result = result->next;
    if ( result == nullptr )
      goto LABEL_25;
  }
  while ( 1 )
  {
    x = node->pos.x;
    if ( v0->x != x || (HIDWORD(a5) = node->pos.y, v11 = 1, v0->y != HIDWORD(a5)) )
      v11 = 0;
    if ( v11 != 0 )
    {
      v13 = (__int64)*v1;
      goto LABEL_18;
    }
    if ( v1->x != x || (v12 = 1, v1->y != node->pos.y) )
      v12 = 0;
    if ( v12 != 0 )
      break;
    node = node->next;
    if ( node == nullptr )
      goto LABEL_24;
  }
  v13 = (__int64)*v0;
LABEL_18:
  v14 = v13;
  while ( 1 )
  {
    if ( HIDWORD(v14) != node->pos.x || (v15 = 1, (_DWORD)v14 != node->pos.y) )
      v15 = 0;
    if ( v15 != 0 )
      return result;
    node = node->next;
    if ( node == nullptr )
      goto LABEL_24;
  }
}


// ========================================================================
// ?FindNode@Contour@@SAPAUContourNode_t@@PAUContourEdge_t@@ABVidVec2i@@1@Z
// EA  : 0x827B21B0
// RVA : 0x007B21B0
// PDB : w:\tech5\engine\models\cuttable\contourinfo.cpp
// ========================================================================

ContourNode_t *__fastcall Contour::FindNode(ContourEdge_t *edge, const idVec2i *v0, const idVec2i *v1)
{
  ContourNode_t *node; // r11
  ContourNode_t *v4; // r8
  int x; // r9
  char v6; // r10
  char v7; // r10
  ContourNode_t *result; // r3
  ContourNode_t *v9; // r10
  ContourNode_t *next; // r9
  char v11; // r11

  node = edge->node;
  v4 = node;
  if ( node == nullptr )
    return nullptr;
  while ( 1 )
  {
    x = v4->pos.x;
    if ( v1->x != x || (v6 = 1, v1->y != v4->pos.y) )
      v6 = 0;
    if ( v6 != 0 )
      break;
    if ( v0->x != x || (v7 = 1, v0->y != v4->pos.y) )
      v7 = 0;
    if ( v7 != 0 )
      return v4;
    v4 = v4->next;
    if ( v4 == nullptr )
      return nullptr;
  }
  v9 = nullptr;
  do
  {
    next = node->next;
    node->next = v9;
    v9 = node;
    node = next;
  }
  while ( next != nullptr );
  edge->node = v9;
  result = v9;
  if ( v9 == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( v0->x != result->pos.x || (v11 = 1, v0->y != result->pos.y) )
      v11 = 0;
    if ( v11 != 0 )
      break;
    result = result->next;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?ContainsPoint@Contour@@QBA_NABVidVec2i@@@Z
// EA  : 0x827B22C0
// RVA : 0x007B22C0
// PDB : w:\tech5\engine\models\cuttable\contourinfo.cpp
// ========================================================================

BOOL __fastcall Contour::ContainsPoint(Contour *this, const idVec2i *pos)
{
  ContourEdge_t *edges; // r26
  BOOL result; // r3
  int x; // r31
  idVec2i v5; // r28
  idVec2i v6; // r11
  int v7; // r29
  int y; // r30
  int v9; // r11
  int v10; // r7
  int v11; // r11
  int v12; // r10
  char v13; // r7
  int v14; // r9
  int v15; // r11
  int v16; // r10
  int v17; // r8
  int v18; // r7
  idVec2i v19; // [sp+0h] [-40h]

  edges = this->edges;
  result = false;
  if ( edges != nullptr )
  {
    x = pos->x;
    v5 = v19;
    while ( 1 )
    {
      v6 = edges->node->pos;
      v7 = edges->node->pos.x;
      y = edges->node->pos.y;
      if ( v7 != x || (LOBYTE(v9) = 1, y != pos->y) )
        LOBYTE(v9) = 0;
      v9 = (unsigned __int8)v9;
      while ( (_BYTE)v9 == 0 )
      {
        if ( v6.x == 0 )
          break;
        v6 = *(idVec2i *)(v6.x + 4);
        v6.x = *(_DWORD *)v6.x;
        v5 = v6;
        if ( v6.x == x )
        {
          LOBYTE(v9) = 1;
          if ( v5.y == pos->y )
            continue;
        }
        LOBYTE(v9) = 0;
        v9 = (unsigned __int8)v9;
      }
      if ( v9 != 0 )
        break;
      v10 = pos->y;
      if ( y == v10 && v5.y == v10
        || v7 == x && v5.x == x
        || (v11 = (v10 - v5.y) * (v7 - x), v12 = (x - v5.x) * (y - v10), v13 = 0, v12 == v11) )
      {
        v13 = 1;
      }
      v14 = pos->y;
      v15 = v5.x - v7;
      v16 = v5.y - y;
      v17 = v14 - y;
      if ( v13 != 0 )
      {
        v18 = (x - v7) * v15 + v16 * v17;
        if ( v18 >= 0 && v18 <= v15 * v15 + v16 * v16 )
          break;
      }
      if ( y < v14 && v5.y >= v14 || v5.y < v14 && y >= v14 )
      {
        __twllei(v5.y - y, 0);
        __twlgei((v5.y - y) & ~(__ROL4__(v17, 1) - 1), 0xFFFFFFFF);
        if ( v17 / (v5.y - y) * v15 + v7 < x )
          result = (_cntlzw(result) & 0x20) != 0;
      }
      edges = edges->next;
      if ( edges == nullptr )
        return result;
    }
    return true;
  }
  return result;
}

