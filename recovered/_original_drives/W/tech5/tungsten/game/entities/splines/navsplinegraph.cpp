
// ========================================================================
// ?GetNodeList@idNavSplineGraph@@QAAAAV?$idList@UnavSplinePathNode_t@@$04@@XZ
// EA  : 0x82CBC090
// RVA : 0x00CBC090
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

idStaticList<navSplinePathNode_t,180> *__fastcall idNavSplineGraph::GetNodeList(idNavSplineGraph *this)
{
  if ( com_production.valueInteger != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
    || spl_useBuildGameList.valueInteger != 0 )
  {
    return (idStaticList<navSplinePathNode_t,180> *)&this->nodes_BuildGame;
  }
  else
  {
    return &this->nodes;
  }
}


// ========================================================================
// ?FindNodeLink@idNavSplineGraph@@QAAPAUnavSplineLink_t@@PAUnavSplinePathNode_t@@PAVidNavSpline@@@Z
// EA  : 0x82CBC140
// RVA : 0x00CBC140
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

navSplineLink_t *__fastcall idNavSplineGraph::FindNodeLink(
        idNavSplineGraph *this,
        navSplinePathNode_t *node,
        idNavSpline *navSpline)
{
  int num; // r7
  int v4; // r10
  navSplineLink_t *list; // r8
  int v6; // r11
  navSplineLink_t *v7; // r9

  num = node->links.num;
  v4 = 0;
  if ( num <= 0 )
    return nullptr;
  list = node->links.list;
  v6 = 0;
  v7 = list;
  while ( v7->navSpline != navSpline )
  {
    ++v4;
    v7 = &list[++v6];
    if ( v4 >= num )
      return nullptr;
  }
  return &list[v4];
}


// ========================================================================
// ?RemoveTempNodes@idNavSplineGraph@@QAAXVidNavSplinePosition@@0@Z
// EA  : 0x82CBC190
// RVA : 0x00CBC190
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __fastcall idNavSplineGraph::RemoveTempNodes(idNavSplineGraph *this, idNavSpline *start, idNavSplinePosition *end)
{
  idNavSpline *v4; // r6
  navSplineLink_t *NodeLink; // r3
  navSplineLink_t *v6; // r3
  float *v7; // r3
  navSplineLink_t *v8; // r3

  v4 = start;
  if ( (*(_BYTE *)&start->splinePath->splineFlags & 0x40) != 0 )
  {
    NodeLink = idNavSplineGraph::FindNodeLink(this, node: start->startNode, navSpline: start);
    NodeLink->node = v4->endNode;
    NodeLink->nodeDistance = v4->length;
  }
  if ( (*(_BYTE *)&v4->splinePath->splineFlags & 0x20) != 0 )
  {
    v6 = idNavSplineGraph::FindNodeLink(this, node: v4->endNode, navSpline: v4);
    v6->node = v4->startNode;
    v6->nodeDistance = v4->length;
  }
  if ( v4 != start )
  {
    if ( (*(_BYTE *)&start->splinePath->splineFlags & 0x40) != 0 )
    {
      v7 = (float *)idNavSplineGraph::FindNodeLink(this, node: start->startNode, navSpline: start);
      *v7 = *(float *)&start->endNode;
      v7[1] = start->length;
    }
    if ( (*(_BYTE *)&start->splinePath->splineFlags & 0x20) != 0 )
    {
      v8 = idNavSplineGraph::FindNodeLink(this, node: start->endNode, navSpline: start);
      v8->node = start->startNode;
      v8->nodeDistance = start->length;
    }
  }
}


// ========================================================================
// ?Search_Dijkstra@idNavSplineGraph@@QAAXPAUnavSplinePathNode_t@@0@Z
// EA  : 0x82CBC2B0
// RVA : 0x00CBC2B0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __fastcall idNavSplineGraph::Search_Dijkstra(
        idNavSplineGraph *this,
        navSplinePathNode_t *startNode,
        navSplinePathNode_t *endNode)
{
  int v5; // r31
  idStaticList<navSplinePathNode_t,180> *NodeList; // r3
  int v7; // r11
  int v8; // r10
  navSplinePathNode_t *v9; // r9
  _DWORD *v10; // r5
  navSplinePathNode_t *v11; // r11
  int v12; // r7
  int v13; // r10
  navSplinePathNode_t **v14; // r8
  int num; // r8
  _DWORD *v16; // r10
  int v17; // r7
  int v18; // r9
  _DWORD *v19; // r6
  float *v20; // r8
  int v21; // r10
  double v22; // fp13
  int v23; // r31
  int v24; // r30
  int v25; // r30
  int v26; // r31
  idNavSpline *navSpline; // r9
  _DWORD v28[360]; // [sp+50h] [-5E0h] BYREF

  v5 = 1;
  memset(v28, 0, sizeof(v28));
  NodeList = idNavSplineGraph::GetNodeList(this);
  v7 = 0;
  if ( NodeList->num > 0 )
  {
    v8 = 0;
    do
    {
      ++v7;
      v9 = &NodeList->list[v8++];
      v9->search.distance = 1900671690;
    }
    while ( v7 < NodeList->num );
  }
  v28[0] = startNode;
  v10 = &v28[179];
  startNode->search.parent = nullptr;
  startNode->search.distance = 0.0;
  while ( 1 )
  {
    v11 = (navSplinePathNode_t *)v28[0];
    v12 = 0;
    v13 = 1;
    if ( v5 > 1 )
      break;
LABEL_11:
    if ( v11 != endNode )
    {
      --v5;
      num = v11->links.num;
      *++v10 = v11;
      v16 = &v28[v5];
      v28[v12] = *v16;
      v17 = 0;
      if ( num > 0 )
      {
        v18 = 0;
        v19 = v16 - 1;
        do
        {
          v20 = (float *)&v11->links.list[v18];
          v21 = *(_DWORD *)v20;
          v22 = *(float *)(*(_DWORD *)v20 + 288);
          if ( v22 == 1.0e30 )
          {
            *++v19 = v21;
            ++v5;
          }
          if ( (float)(v20[1] + v11->search.distance) < v22 )
          {
            *(float *)(v21 + 288) = v20[1] + v11->search.distance;
            *(_DWORD *)(v21 + 292) = v11;
            *(_DWORD *)(v21 + 296) = v11->links.list[v18].navSpline;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < v11->links.num );
      }
      if ( v5 != 0 )
        continue;
    }
    return;
  }
  v14 = (navSplinePathNode_t **)&v28[1];
  while ( v13 < 180 )
  {
    if ( (*v14)->search.distance < (double)v11->search.distance )
    {
      v11 = *v14;
      v12 = v13;
    }
    ++v13;
    ++v14;
    if ( v13 >= v5 )
      goto LABEL_11;
  }
  idLib::Printf(fmt: "\n\nSearch_Dijkstra failed! Node limit (%d) exceeded!", 180);
  idLib::Printf(fmt: "startNode links:\n");
  v23 = 0;
  if ( startNode->links.num > 0 )
  {
    v24 = 0;
    do
    {
      idLib::Printf(fmt: "%s\n", startNode->links.list[v24].navSpline->splinePath->name.data);
      ++v23;
      ++v24;
    }
    while ( v23 < startNode->links.num );
  }
  idLib::Printf(fmt: "endNode links:\n");
  v25 = 0;
  if ( endNode->links.num > 0 )
  {
    v26 = 0;
    do
    {
      idLib::Printf(fmt: "%s\n", endNode->links.list[v26].navSpline->splinePath->name.data);
      ++v25;
      ++v26;
    }
    while ( v25 < endNode->links.num );
  }
  idLib::Printf(fmt: "\n\n");
  idLib::Printf(fmt: "\n\nSearch_Dijkstra failed! Node limit (%d) exceeded!", 180);
  endNode->search.parent = startNode;
  navSpline = startNode->links.list->navSpline;
  endNode->search.distance = 0.0;
  endNode->search.spline = navSpline;
}


// ========================================================================
// ?Draw@idNavSplineGraph@@QAAXXZ
// EA  : 0x82CBC550
// RVA : 0x00CBC550
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __fastcall idNavSplineGraph::Draw(idNavSplineGraph *this)
{
  int v2; // r22
  int v3; // r20
  double v4; // fp31
  navSplinePathNode_t *list; // r11
  navSplinePathNode_t *v6; // r31
  double y; // fp13
  double v8; // fp12
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r3
  int v17; // r30
  int v18; // r29
  int v19; // [sp+8h] [-1138h]
  int v20; // [sp+8h] [-1138h]
  int v21; // [sp+Ch] [-1134h]
  int v22; // [sp+Ch] [-1134h]
  int v23; // [sp+10h] [-1130h]
  int v24; // [sp+10h] [-1130h]
  int v25; // [sp+14h] [-112Ch]
  int v26; // [sp+14h] [-112Ch]
  int v27; // [sp+18h] [-1128h]
  int v28; // [sp+18h] [-1128h]
  int v29; // [sp+1Ch] [-1124h]
  int v30; // [sp+1Ch] [-1124h]
  float v31[4]; // [sp+60h] [-10E0h] BYREF
  float v32[4]; // [sp+70h] [-10D0h] BYREF
  idColor v33; // [sp+80h] [-10C0h] BYREF
  va v34; // [sp+90h] [-10B0h] BYREF

  v2 = 0;
  if ( idNavSplineGraph::GetNodeList(this)->num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = 3.0;
      list = idNavSplineGraph::GetNodeList(this)->list;
      v33 = idColor::colorWhite;
      v6 = &list[v3];
      if ( v2 == idNavSplineGraph::GetNodeList(this)->num - 1 )
      {
        v4 = 6.0;
        v33 = idColor::colorRed;
      }
      v32[0] = 0.0;
      v32[1] = 0.0;
      v32[2] = 1.0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, navSplinePathNode_t *, float *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorGreen,
        a3: v6,
        a4: v32,
        a5: 100.0);
      y = v6->position.y;
      v8 = (float)(v6->position.z - (float)60.0);
      v31[0] = v6->position.x;
      v31[1] = y;
      v31[2] = v8;
      HIDWORD(v9) = v6->links.num;
      v12 = va::va(
              this: &v34,
              fmt: "links: %d",
              a3: v9,
              a4: v11,
              a5: v10,
              a6: v19,
              a7: v21,
              a8: v23,
              a9: v25,
              a10: v27,
              a11: v29);
      ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v12,
        a3: v31,
        a4: clientGame->renderWorld->DebugText,
        a5: &v33,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: (float)((float)v4 * (float)0.30000001));
      HIDWORD(v13) = v6->index;
      v16 = va::va(
              this: &v34,
              fmt: "#%d",
              a3: v13,
              a4: v15,
              a5: v14,
              a6: v20,
              a7: v22,
              a8: v24,
              a9: v26,
              a10: v28,
              a11: v30);
      ((void (__fastcall *)(idRenderWorld *, va *, navSplinePathNode_t *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v16,
        a3: v6,
        a4: clientGame->renderWorld->__vftable,
        a5: &v33,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: v4);
      v17 = 0;
      if ( v6->links.num > 0 )
      {
        v18 = 0;
        do
        {
          clientGame->renderWorld->DebugLine(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: (const idVec3 *)v6,
            a4: (const idVec3 *)v6->links.list[v18].node,
            a5: 0,
            a6: false);
          ++v17;
          ++v18;
        }
        while ( v17 < v6->links.num );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < idNavSplineGraph::GetNodeList(this)->num );
  }
}


// ========================================================================
// ?InsertTempNodes@idNavSplineGraph@@QAA_NVidNavSplinePosition@@0@Z
// EA  : 0x82CBCA38
// RVA : 0x00CBCA38
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idNavSplineGraph::InsertTempNodes(
        idNavSplineGraph *this,
        __int64 end,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  double v13; // fp31
  idNavSpline *v15; // r30
  idNavSpline *v16; // r29
  double v17; // fp30
  __int64 *v18; // r29
  __int64 *v19; // r25
  idNavSpline *v20; // r30
  idNavSplinePath *splinePath; // r9
  navSplineLink_t *NodeLink; // r3
  navSplinePathNode_t *startNode; // r11
  navSplineLink_t *v24; // r3
  double v25; // fp0
  int v26; // r6
  idNavSpline *v27; // r11
  navSplinePathNode_t *endNode; // r10
  double v29; // fp0
  double v30; // fp0
  navSplineLink_t *v32; // r3
  navSplinePathNode_t *v33; // r11
  navSplineLink_t *v34; // r3
  navSplinePathNode_t *v35; // r11
  double v36; // fp31
  navSplineLink_t *v37; // r3
  navSplinePathNode_t *v38; // r11
  navSplineLink_t *v39; // r3
  navSplinePathNode_t *v40; // r11
  navSplineLink_t v41; // [sp+50h] [-70h] BYREF

  a10 = *(__int64 *)((char *)&end + 4);
  v13 = *(float *)&this;
  a11 = end;
  a12 = *(__int64 *)((char *)&a3 + 4);
  a13 = a3;
  v15 = (idNavSpline *)HIDWORD(end);
  v16 = (idNavSpline *)HIDWORD(a3);
  if ( HIDWORD(end) == HIDWORD(a3) )
  {
    v17 = *(float *)&a12;
    if ( v13 <= *(float *)&a12 )
    {
      v18 = &a10;
      v19 = &a12;
    }
    else
    {
      v18 = &a12;
      v19 = &a10;
    }
    v20 = *((idNavSpline **)v18 + 2);
    v41.node = nullptr;
    v41.navSpline = nullptr;
    splinePath = v20->splinePath;
    v41.nodeDistance = 0.0;
    v41.splineDistance = 0.0;
    if ( (*(_BYTE *)&splinePath->splineFlags & 0x40) != 0 )
    {
      NodeLink = idNavSplineGraph::FindNodeLink(this, node: v20->startNode, navSpline: v20);
      NodeLink->nodeDistance = *(float *)v18;
      NodeLink->node = this->tempNode;
    }
    if ( (*(_BYTE *)&v20->splinePath->splineFlags & 0x20) != 0 )
    {
      startNode = v20->startNode;
      v41.nodeDistance = *(float *)v18;
      v41.navSpline = v20;
      v41.splineDistance = v41.nodeDistance;
      v41.node = startNode;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[0].links, obj: &v41);
    }
    if ( (*(_BYTE *)&v20->splinePath->splineFlags & 0x20) != 0 )
    {
      v24 = idNavSplineGraph::FindNodeLink(
              this,
              node: *(navSplinePathNode_t **)(*((_DWORD *)v19 + 2) + 72),
              navSpline: *((idNavSpline **)v19 + 2));
      v25 = *(float *)v19;
      v24->node = &this->tempNode[1];
      v24->nodeDistance = *(float *)(v26 + 12) - (float)v25;
    }
    if ( (*(_BYTE *)&v20->splinePath->splineFlags & 0x40) != 0 )
    {
      v27 = *((idNavSpline **)v19 + 2);
      v41.splineDistance = *(float *)v19;
      endNode = v27->endNode;
      v41.nodeDistance = v27->length - v41.splineDistance;
      v41.navSpline = v27;
      v41.node = endNode;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[1].links, obj: &v41);
    }
    if ( (*(_BYTE *)&v20->splinePath->splineFlags & 0x40) != 0 )
    {
      v29 = *(float *)v18;
      v41.nodeDistance = *(float *)v19 - *(float *)v18;
      v41.navSpline = v20;
      v41.splineDistance = v29;
      v41.node = &this->tempNode[1];
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[0].links, obj: &v41);
    }
    if ( (*(_BYTE *)&v20->splinePath->splineFlags & 0x20) != 0 )
    {
      v30 = *(float *)v19;
      v41.nodeDistance = *(float *)v19 - *(float *)v18;
      v41.navSpline = v20;
      v41.splineDistance = v30;
      v41.node = this->tempNode;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[1].links, obj: &v41);
    }
    return v13 > v17;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)HIDWORD(end) + 908) & 0x40) != 0 )
    {
      v32 = idNavSplineGraph::FindNodeLink(
              this,
              node: *(navSplinePathNode_t **)(HIDWORD(end) + 68),
              navSpline: (idNavSpline *)HIDWORD(end));
      v32->nodeDistance = v13;
      v32->node = this->tempNode;
    }
    if ( (*(_BYTE *)&v15->splinePath->splineFlags & 0x20) != 0 )
    {
      v33 = v15->startNode;
      v41.nodeDistance = v13;
      v41.splineDistance = v13;
      v41.navSpline = v15;
      v41.node = v33;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[0].links, obj: &v41);
    }
    if ( (*(_BYTE *)&v15->splinePath->splineFlags & 0x20) != 0 )
    {
      v34 = idNavSplineGraph::FindNodeLink(this, node: v15->endNode, navSpline: v15);
      v34->node = this->tempNode;
      v34->nodeDistance = v15->length - (float)v13;
    }
    if ( (*(_BYTE *)&v15->splinePath->splineFlags & 0x40) != 0 )
    {
      v35 = v15->endNode;
      v41.nodeDistance = v15->length - (float)v13;
      v41.splineDistance = v13;
      v41.navSpline = v15;
      v41.node = v35;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[0].links, obj: &v41);
    }
    v36 = *(float *)&a12;
    if ( (*(_BYTE *)&v16->splinePath->splineFlags & 0x40) != 0 )
    {
      v37 = idNavSplineGraph::FindNodeLink(this, node: v16->startNode, navSpline: v16);
      v37->nodeDistance = v36;
      v37->node = &this->tempNode[1];
    }
    if ( (*(_BYTE *)&v16->splinePath->splineFlags & 0x20) != 0 )
    {
      v38 = v16->startNode;
      v41.nodeDistance = v36;
      v41.splineDistance = v36;
      v41.navSpline = v16;
      v41.node = v38;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[1].links, obj: &v41);
    }
    if ( (*(_BYTE *)&v16->splinePath->splineFlags & 0x20) != 0 )
    {
      v39 = idNavSplineGraph::FindNodeLink(this, node: v16->endNode, navSpline: v16);
      v39->node = &this->tempNode[1];
      v39->nodeDistance = v16->length - (float)v36;
    }
    if ( (*(_BYTE *)&v16->splinePath->splineFlags & 0x40) != 0 )
    {
      v40 = v16->endNode;
      v41.nodeDistance = v16->length - (float)v36;
      v41.splineDistance = v36;
      v41.navSpline = v16;
      v41.node = v40;
      idList<navSplineLink_t,5>::Append(this: &this->tempNode[1].links, obj: &v41);
    }
    return false;
  }
}


// ========================================================================
// ?GetShortestPath@idNavSplineGraph@@QAA_NVidNavSplinePosition@@0AAUnavSplinePath_t@@@Z
// EA  : 0x82CBCE58
// RVA : 0x00CBCE58
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idNavSplineGraph::GetShortestPath(
        idNavSplineGraph *this,
        idNavSpline *start,
        __int64 splinePath,
        int a4,
        int a5)
{
  idNavSplineGraph *v5; // r3
  navSplineType_t *p_navSplineType; // r29
  idNavSplineGraph *v7; // r27
  navSplinePathNode_t *tempNode; // r30
  __int64 v12; // r8
  int v13; // r10
  int v14; // r9
  navSplinePathNode_t *v15; // r29
  navSplinePathNode_t **p_parent; // r26
  navSplinePathNode_t *parent; // r11
  double v18; // fp31
  navSplinePathNode_t *v19; // r11
  int v20; // r28
  navSplinePathNode_t *startNode; // r9
  const idDeclVehicleUpgrade **list; // r29
  int v23; // r30
  const navSplinePath_t::path_t *v24; // r29
  int v25; // [sp+8h] [-E8h]
  __int64 v26; // [sp+10h] [-E0h]
  __int64 v27; // [sp+18h] [-D8h]
  __int64 v28; // [sp+20h] [-D0h]
  __int64 v29; // [sp+28h] [-C8h]
  __int64 v30; // [sp+30h] [-C0h]
  __int64 v31; // [sp+38h] [-B8h]
  __int64 v32; // [sp+40h] [-B0h]
  navSplinePath_t::path_t v33[2]; // [sp+50h] [-A0h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v34; // [sp+60h] [-90h] BYREF
  __int64 v35; // [sp+110h] [+20h]
  idNavSplinePathMgr *v37; // [sp+128h] [+38h]

  v35 = *(_QWORD *)&start;
  p_navSplineType = &v5->navSplineType;
  v37 = (idNavSplinePathMgr *)splinePath;
  v7 = v5;
  if ( start == &idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: v5->navSplineType)->tempNavSpline
    || v37 == (idNavSplinePathMgr *)&idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *p_navSplineType)->tempNavSpline )
  {
    return false;
  }
  tempNode = v7->tempNode;
  navSplinePathNode_t::Init(this: v7->tempNode);
  navSplinePathNode_t::Init(this: &v7->tempNode[1]);
  HIDWORD(v12) = 0;
  if ( idNavSplineGraph::InsertTempNodes(
         this: v7,
         end: (unsigned int)v37,
         a3: v12,
         a4: v14,
         a5: v13,
         a6: v25,
         a7: v26,
         a8: v27,
         a9: v28,
         a10: v29,
         a11: v30,
         a12: v31,
         a13: v32) )
  {
    v15 = &v7->tempNode[1];
  }
  else
  {
    v15 = v7->tempNode;
    tempNode = &v7->tempNode[1];
  }
  v15->index = -1;
  tempNode->index = -2;
  idNavSplineGraph::Search_Dijkstra(this: v7, startNode: v15, endNode: tempNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)(a5 + 16));
  p_parent = &tempNode->search.parent;
  *(float *)a5 = *(float *)&v35;
  *(float *)(a5 + 4) = *(float *)&splinePath;
  *(float *)(a5 + 8) = tempNode->search.distance;
  parent = tempNode->search.parent;
  if ( parent == v15 )
  {
    v33[0].navSpline = tempNode->search.spline;
    if ( *(float *)&v35 <= (double)*(float *)&splinePath )
      v18 = 1.0;
    else
      v18 = -1.0;
    v33[0].dir = v18;
    idList<navSplinePath_t::path_t,5>::Append(this: (idList<navSplinePath_t::path_t,5> *)(a5 + 16), obj: v33);
    v33[0].dir = -v18;
    idList<navSplinePath_t::path_t,5>::Append(this: (idList<navSplinePath_t::path_t,5> *)(a5 + 16), obj: v33);
  }
  else if ( parent != nullptr )
  {
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v34);
    v19 = *p_parent;
    if ( *p_parent != v15 )
    {
      v20 = (int)&tempNode->search.parent;
      do
      {
        startNode = tempNode->search.spline->startNode;
        v33[0].navSpline = tempNode->search.spline;
        if ( startNode == v19 )
          v33[0].dir = 1.0;
        else
          v33[0].dir = -1.0;
        idList<navSplinePath_t::path_t,5>::Append(this: (idList<navSplinePath_t::path_t,5> *)&v34, obj: v33);
        tempNode = *(navSplinePathNode_t **)v20;
        v19 = *(navSplinePathNode_t **)(*(_DWORD *)v20 + 292);
        v20 = *(_DWORD *)v20 + 292;
      }
      while ( v19 != v15 );
    }
    list = v34.list;
    v33[0].navSpline = start;
    *((float *)v34.list + 1) = -*((float *)v34.list + 1);
    if ( start->startNode == tempNode )
      v33[0].dir = -1.0;
    else
      v33[0].dir = 1.0;
    idList<navSplinePath_t::path_t,5>::Append(this: (idList<navSplinePath_t::path_t,5> *)(a5 + 16), obj: v33);
    v23 = v34.num - 1;
    if ( v34.num - 1 >= 0 )
    {
      v24 = (const navSplinePath_t::path_t *)&list[2 * v23];
      do
      {
        idList<navSplinePath_t::path_t,5>::Append(this: (idList<navSplinePath_t::path_t,5> *)(a5 + 16), obj: v24);
        --v23;
        --v24;
      }
      while ( v23 >= 0 );
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v34);
  }
  else
  {
    *(float *)(a5 + 8) = 1.0e30;
  }
  *(float *)(a5 + 12) = *((float *)&splinePath + 1) - *((float *)&v35 + 1);
  idNavSplineGraph::RemoveTempNodes(this: v7, start, end: nullptr);
  return *p_parent != nullptr;
}


// ========================================================================
// __unwind$489075
// EA  : 0x82CBD108
// RVA : 0x00CBD108
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void _unwind_489075()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ??0idNavSplineGraph@@QAA@XZ
// EA  : 0x82CBD4A8
// RVA : 0x00CBD4A8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

idNavSplineGraph *__fastcall idNavSplineGraph::idNavSplineGraph(idNavSplineGraph *this)
{
  this->__vftable = (idNavSplineGraph_vtbl *)&idNavSplineGraph::`vftable';
  idStaticList<navSplinePathNode_t,180>::idStaticList<navSplinePathNode_t,180>(this: &this->nodes);
  this->nodes_BuildGame.granularity = 0;
  this->nodes_BuildGame.memTag = 5;
  this->nodes_BuildGame.listStatic = 0;
  this->nodes_BuildGame.list = nullptr;
  this->nodes_BuildGame.size = 0;
  this->nodes_BuildGame.num = 0;
  `eh vector constructor iterator'(
    ptr: this->tempNode,
    size: 0x12Cu,
    count: 2,
    pCtor: (void (__fastcall *)(void *))navSplinePathNode_t::navSplinePathNode_t,
    pDtor: (void (__fastcall *)(void *))idMQCommand::~idMQCommand);
  this->navSplineType = NAV_SPLINE_TYPE_DEFAULT;
  return this;
}


// ========================================================================
// __unwind$489566_0
// EA  : 0x82CBD538
// RVA : 0x00CBD538
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void _unwind_489566_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489567_0
// EA  : 0x82CBD560
// RVA : 0x00CBD560
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void _unwind_489567_0()
{
  int v0; // r12

  idStaticList<navSplinePathNode_t,180>::~idStaticList<navSplinePathNode_t,180>(this: (idStaticList<navSplinePathNode_t,180> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$489568_0
// EA  : 0x82CBD58C
// RVA : 0x00CBD58C
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void _unwind_489568_0()
{
  int v0; // r12

  idList<navSplinePathNode_t,5>::Clear(this: (idList<navSplinePathNode_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 54020));
}


// ========================================================================
// ?GetNode@idNavSplineGraph@@QAAPAUnavSplinePathNode_t@@VidVec3@@@Z
// EA  : 0x82CBD740
// RVA : 0x00CBD740
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

navSplinePathNode_t *__fastcall idNavSplineGraph::GetNode(idNavSplineGraph *this, idVec3 *position)
{
  int v3; // r30
  double v4; // fp31
  double v5; // fp30
  double v6; // fp29
  int v7; // r31
  idStaticList<navSplinePathNode_t,180> *v8; // r3
  navSplinePathNode_t *result; // r3
  double v10; // fp13
  double v11; // fp11
  double v12; // fp9
  int v13; // r31
  idStaticList<navSplinePathNode_t,180> *NodeList; // r31
  int num; // r11
  int size; // r10
  int v17; // r30
  void *v18; // r4

  v3 = 0;
  v4 = *(float *)&position;
  v5 = *(float *)&position;
  v6 = *(float *)&this;
  if ( idNavSplineGraph::GetNodeList(this)->num <= 0 )
  {
LABEL_5:
    if ( com_production.valueInteger != 0
      || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
      || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
      || (v13 = 180, spl_useBuildGameList.valueInteger != 0) )
    {
      v13 = 500;
    }
    if ( idNavSplineGraph::GetNodeList(this)->num == v13 )
    {
      return nullptr;
    }
    else
    {
      NodeList = idNavSplineGraph::GetNodeList(this);
      idList<navSplinePathNode_t,5>::PreAllocateWithGranularity(this: NodeList, newSize: NodeList->num + 1);
      num = NodeList->num;
      size = NodeList->size;
      if ( num >= size )
      {
        v17 = (int)&NodeList->list[size - 1];
      }
      else
      {
        v17 = (int)&NodeList->list[num];
        NodeList->num = num + 1;
      }
      *(float *)v17 = v6;
      *(float *)(v17 + 4) = v5;
      *(float *)(v17 + 8) = v4;
      if ( *(_BYTE *)(v17 + 27) == 0 || *(_BYTE *)(v17 + 27) == 2 )
      {
        v18 = *(void **)(v17 + 12);
        if ( v18 != nullptr )
          idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
        *(_DWORD *)(v17 + 12) = 0;
        *(_DWORD *)(v17 + 20) = 0;
      }
      *(_DWORD *)(v17 + 16) = 0;
      *(_DWORD *)(v17 + 284) = idNavSplineGraph::GetNodeList(this)->num - 1;
      return (navSplinePathNode_t *)v17;
    }
  }
  else
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = idNavSplineGraph::GetNodeList(this);
      v10 = (float)(v8->list[v7].position.x - (float)v6);
      result = &v8->list[v7];
      v11 = (float)(result->position.y - (float)v5);
      v12 = (float)(result->position.z - (float)v4);
      if ( (float)((float)((float)v10 * (float)v10)
                 + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) < 64.0 )
        break;
      ++v3;
      ++v7;
      if ( v3 >= idNavSplineGraph::GetNodeList(this)->num )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ?AddPath@idNavSplineGraph@@QAAXPAVidNavSpline@@@Z
// EA  : 0x82CBD948
// RVA : 0x00CBD948
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __fastcall idNavSplineGraph::AddPath(idNavSplineGraph *this, idNavSpline *navSpline)
{
  idCurve_Spline<idVec3> *curve; // r30
  navSplinePathNode_t *Node; // r3
  int num; // r11
  idVec3 *list; // r9
  navSplinePathNode_t *v7; // r30
  navSplinePathNode_t *v8; // r3
  navSplinePathNode_t *v9; // r29
  idNavSplinePath *splinePath; // r10
  idNavSplinePath::splineFlags_t splineFlags; // r8
  double length; // fp0
  navSplineLink_t v13; // [sp+50h] [-40h] BYREF

  curve = navSpline->curve;
  Node = idNavSplineGraph::GetNode(
           this: (idNavSplineGraph *)LODWORD(curve->values.list->x),
           position: (idVec3 *)LODWORD(curve->values.list->y));
  num = curve->values.num;
  list = curve->values.list;
  v7 = Node;
  v8 = idNavSplineGraph::GetNode(
         this: (idNavSplineGraph *)LODWORD(list[num - 1].x),
         position: (idVec3 *)LODWORD(list[num - 1].y));
  v9 = v8;
  if ( v7 != nullptr && v8 != nullptr )
  {
    splinePath = navSpline->splinePath;
    v13.node = nullptr;
    v13.navSpline = nullptr;
    splineFlags = splinePath->splineFlags;
    v13.nodeDistance = 0.0;
    v13.splineDistance = 0.0;
    if ( (*(_BYTE *)&splineFlags & 0x40) != 0 )
    {
      length = navSpline->length;
      v13.nodeDistance = navSpline->length;
      v13.node = v8;
      v13.navSpline = navSpline;
      v13.splineDistance = length;
      idList<navSplineLink_t,5>::Append(this: &v7->links, obj: &v13);
    }
    if ( (*(_BYTE *)&navSpline->splinePath->splineFlags & 0x20) != 0 )
    {
      v13.nodeDistance = navSpline->length;
      v13.node = v7;
      v13.navSpline = navSpline;
      v13.splineDistance = 0.0;
      idList<navSplineLink_t,5>::Append(this: &v9->links, obj: &v13);
    }
    navSpline->startNode = v7;
    navSpline->endNode = v9;
    if ( spl_gen_showNodes.valueInteger != 0 )
      idLib::Printf(fmt: "%s connects to nodes %d and %d\n", navSpline->splinePath->name.data, v7->index, v9->index);
  }
}


// ========================================================================
// ?BuildGraph@idNavSplineGraph@@QAAXW4navSplineType_t@@@Z
// EA  : 0x82CBDA90
// RVA : 0x00CBDA90
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __fastcall idNavSplineGraph::BuildGraph(idNavSplineGraph *this, navSplineType_t splineType)
{
  navSplineType_t *p_navSplineType; // r26
  idStaticList<navSplinePathNode_t,180> *v4; // r3
  idStaticList<navSplinePathNode_t,180> *NodeList; // r3
  idStaticList<navSplinePathNode_t,180> *v6; // r29
  char *list; // r3
  int v8; // r29
  idNavSplinePathMgr *NavSplinePathMgr; // r3
  int v10; // r28
  idNavSplinePathMgr *v11; // r3
  idList<idNavSpline,5> *NavSplineList; // r3
  idNavSplinePathMgr *v13; // r3
  int v14; // r28
  int v15; // r26
  int v16; // r27
  int v17; // r29
  idStaticList<navSplinePathNode_t,180> *v18; // r3
  idStaticList<navSplinePathNode_t,180> *v19; // r3
  idNavSpline *navSpline; // r11
  idNavSplinePath *splinePath; // r11
  navSplinePathNode_t *v22; // r29
  idStaticList<navSplinePathNode_t,180> *v23; // r3
  float x; // [sp+50h] [-90h]
  float y; // [sp+54h] [-8Ch]
  idStr v26; // [sp+70h] [-70h] BYREF

  p_navSplineType = &this->navSplineType;
  this->navSplineType = splineType;
  if ( com_production.valueInteger != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0
    || (gameLocal->GetGameFlags(this: gameLocal) & 2) != 0
    || spl_useBuildGameList.valueInteger != 0 )
  {
    NodeList = idNavSplineGraph::GetNodeList(this);
    v6 = NodeList;
    if ( NodeList->listStatic == 0 || NodeList->listStatic == 2 )
    {
      list = (char *)NodeList->list;
      if ( v6->list != nullptr )
        idListArrayDelete<navSplinePathNode_t>(ptr: list, num: v6->size);
      v6->list = nullptr;
      v6->size = 0;
    }
    v6->num = 0;
    if ( this->nodes_BuildGame.size < 500 )
      idList<navSplinePathNode_t,5>::Resize(this: &this->nodes_BuildGame, newsize: 500);
  }
  else
  {
    v4 = idNavSplineGraph::GetNodeList(this);
    idList<navSplinePathNode_t,5>::Clear(this: v4);
  }
  v8 = 0;
  NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *p_navSplineType);
  if ( idNavSplinePathMgr::GetNavSplineList(this: NavSplinePathMgr)->num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *p_navSplineType);
      NavSplineList = idNavSplinePathMgr::GetNavSplineList(this: v11);
      idNavSplineGraph::AddPath(this, navSpline: &NavSplineList->list[v10]);
      ++v8;
      ++v10;
      v13 = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: *p_navSplineType);
    }
    while ( v8 < idNavSplinePathMgr::GetNavSplineList(this: v13)->num );
  }
  if ( (gameLocal->gameSpawnInfo.gameFlags & 0x80) == 0 && idNavSplineGraph::GetNodeList(this)->num > 0 )
  {
    v14 = 0;
    v15 = 1;
    do
    {
      v16 = v15;
      if ( v15 < idNavSplineGraph::GetNodeList(this)->num )
      {
        v17 = v14 * 300 + 300;
        while ( 1 )
        {
          v18 = idNavSplineGraph::GetNodeList(this);
          x = v18->list[v14].position.x;
          y = v18->list[v14].position.y;
          v19 = idNavSplineGraph::GetNodeList(this);
          if ( (float)((float)((float)(x - *(float *)((char *)&v19->list->position.x + v17))
                             * (float)(x - *(float *)((char *)&v19->list->position.x + v17)))
                     + (float)((float)(y - *(float *)((char *)&v19->list->position.y + v17))
                             * (float)(y - *(float *)((char *)&v19->list->position.y + v17)))) < 4.0 )
            break;
          ++v16;
          v17 += 300;
          if ( v16 >= idNavSplineGraph::GetNodeList(this)->num )
            goto LABEL_29;
        }
        idStr::idStr(this: &v26, text: "unknown");
        if ( idNavSplineGraph::GetNodeList(this)->list[v14].links.num > 0 )
        {
          navSpline = idNavSplineGraph::GetNodeList(this)->list[v14].links.list->navSpline;
          if ( navSpline != nullptr )
          {
            splinePath = navSpline->splinePath;
            if ( splinePath != nullptr )
              idStr::operator=(this: &v26, text: splinePath->name.data);
          }
        }
        v22 = &idNavSplineGraph::GetNodeList(this)->list[v16];
        v23 = idNavSplineGraph::GetNodeList(this);
        idLib::Warning(
          fmt: "One of the endpoints of spline %s doesn't exactly overlap the endpoints of the spline it connects to. Check th"
          "e endpoints and make adjustments. It may not be aligned vertically. ( nodes: %d and %d )",
          v26.data,
          v23->list[v14].index,
          v22->index);
        idStr::FreeData(this: &v26);
      }
LABEL_29:
      ++v15;
      ++v14;
    }
    while ( v15 - 1 < idNavSplineGraph::GetNodeList(this)->num );
  }
}


// ========================================================================
// __unwind$489915_0
// EA  : 0x82CBDDCC
// RVA : 0x00CBDDCC
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void _unwind_489915_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// `dynamic initializer for 'spl_gen_showNodes''
// EA  : 0x83378AC8
// RVA : 0x01378AC8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinegraph.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_gen_showNodes__()
{
  idCVar::idCVar(
    this: &spl_gen_showNodes,
    name: "spl_gen_showNodes",
    value: "0",
    flags: 1,
    description: "Prints each node a spline is associated with.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_gen_showNodes__);
}

