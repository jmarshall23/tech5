
// ========================================================================
// ?MergeContours@idCutterGraphManager@@QAAXPAVContour@@@Z
// EA  : 0x827BA848
// RVA : 0x007BA848
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::MergeContours(idCutterGraphManager *this, Contour *contour)
{
  ContourManager::Merge(this: this->contourManager, contours: contour);
}


// ========================================================================
// ?FreeContour@idCutterGraphManager@@QAAXPAVContour@@@Z
// EA  : 0x827BA850
// RVA : 0x007BA850
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::FreeContour(idCutterGraphManager *this, Contour *contour)
{
  ContourManager::Free(this: this->contourManager, contour);
}


// ========================================================================
// ?PreAcquire@idCutterGraphManager@@QAAXXZ
// EA  : 0x827BA858
// RVA : 0x007BA858
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::PreAcquire(idCutterGraphManager *this)
{
  idCutterGraphManager::Graph *graph; // r11

  graph = this->graph;
  if ( graph != nullptr )
    graph->lastNode = nullptr;
}


// ========================================================================
// ?CreateContour@idCutterGraphManager@@QAAPAVContour@@ABV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827BA870
// RVA : 0x007BA870
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

Contour *__fastcall idCutterGraphManager::CreateContour(idCutterGraphManager *this, const idList<idVec2i,5> *points)
{
  return ContourManager::Create(this: this->contourManager, points);
}


// ========================================================================
// ?Alloc@IDHeap@idCutterGraphManager@@QAAHXZ
// EA  : 0x827BA878
// RVA : 0x007BA878
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::IDHeap::Alloc(idCutterGraphManager::IDHeap *this)
{
  unsigned int v1; // r7
  unsigned __int8 *list; // r6
  int v3; // r11
  int i; // r9
  int v6; // r10
  int v7; // r9

  v1 = *((_DWORD *)this + 4);
  list = this->buffer.list;
  v3 = v1 >> 1;
  for ( i = v1 >> 1; list[v3] == 255; ++v3 )
    ;
  if ( v3 < (this->numBits >> 3) - 1 )
    goto LABEL_11;
  if ( i == 0 )
    return -1;
  v3 = 0;
  if ( v1 >> 1 != 0 )
  {
    do
    {
      if ( list[v3] != 255 )
        break;
      ++v3;
    }
    while ( v3 < i );
  }
  if ( list[v3] == 255 )
  {
    *((_DWORD *)this + 4) &= 1u;
    return -1;
  }
  else
  {
LABEL_11:
    v6 = 0;
    v7 = 1;
    do
    {
      if ( (this->buffer.list[v3] & (unsigned __int8)v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
    list[v3] |= 1 << v6;
    *((_DWORD *)this + 4) = (2 * v3) | *((_DWORD *)this + 4) & 1;
    return 8 * v3 + v6;
  }
}


// ========================================================================
// ?Write@IDHeap@idCutterGraphManager@@QBAXPAVidFile@@@Z
// EA  : 0x827BA968
// RVA : 0x007BA968
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::IDHeap::Write(idCutterGraphManager::IDHeap *this, idFile *file)
{
  idFile_vtbl *v2; // r9
  idFile_vtbl *v5; // r10
  idFile_vtbl *v6; // r6
  int v7; // [sp+50h] [-20h] BYREF
  int num; // [sp+54h] [-1Ch] BYREF

  v2 = file->__vftable;
  num = this->buffer.num;
  v7 = 0;
  v2->Write(this: file, a2: &num, a3: 4u);
  file->Write(this: file, a2: this->buffer.list, a3: this->buffer.num);
  v5 = file->__vftable;
  v7 = *((_DWORD *)this + 4) >> 1;
  v5->Write(this: file, a2: &v7, a3: 4u);
  v6 = file->__vftable;
  v7 = *((_DWORD *)this + 4) & 1;
  v6->Write(this: file, a2: &v7, a3: 4u);
  file->Write(this: file, a2: &this->numBits, a3: 4u);
}


// ========================================================================
// ?RemoveEdge@Graph@idCutterGraphManager@@QAAXPAUEdge_t@2@@Z
// EA  : 0x827BAA50
// RVA : 0x007BAA50
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Graph::RemoveEdge(
        idCutterGraphManager::Graph *this,
        idCutterGraphManager::Edge_t *edge)
{
  int num; // r9
  int v3; // r8
  int v4; // r10
  int v5; // r11
  int v6; // r11
  int v7; // r11

  num = this->edges.num;
  v3 = -1;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    while ( this->edges.list[v5].data != edge )
    {
      ++v4;
      ++v5;
      if ( v4 >= num )
        goto LABEL_7;
    }
    v3 = v4;
  }
LABEL_7:
  if ( v3 >= 0 )
  {
    v6 = this->edges.num;
    if ( v3 < v6 )
    {
      v7 = v6 - 1;
      this->edges.num = v7;
      if ( v3 != v7 )
        this->edges.list[v3].data = this->edges.list[v7].data;
    }
  }
}


// ========================================================================
// ?RemoveLink@Graph@idCutterGraphManager@@QAAXPAULink_t@2@@Z
// EA  : 0x827BAAD0
// RVA : 0x007BAAD0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Graph::RemoveLink(
        idCutterGraphManager::Graph *this,
        idCutterGraphManager::Link_t *link)
{
  int num; // r9
  int v3; // r8
  int v4; // r10
  int v5; // r11
  int v6; // r11
  int v7; // r11

  num = this->links.num;
  v3 = -1;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    while ( this->links.list[v5].data != link )
    {
      ++v4;
      ++v5;
      if ( v4 >= num )
        goto LABEL_7;
    }
    v3 = v4;
  }
LABEL_7:
  if ( v3 >= 0 )
  {
    v6 = this->links.num;
    if ( v3 < v6 )
    {
      v7 = v6 - 1;
      this->links.num = v7;
      if ( v3 != v7 )
        this->links.list[v3].data = this->links.list[v7].data;
    }
  }
}


// ========================================================================
// ?FindNodeIndex@Graph@idCutterGraphManager@@QAAHABVidVec2i@@H@Z
// EA  : 0x827BAB50
// RVA : 0x007BAB50
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::Graph::FindNodeIndex(
        idCutterGraphManager::Graph *this,
        const idVec2i *pos,
        int threshold)
{
  int num; // r31
  int v5; // r5
  int result; // r3
  idCutterGraphManager::nodeHandle_t *list; // r8
  int i; // r10

  num = this->nodes.num;
  v5 = threshold * threshold;
  result = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    list = this->nodes.list;
    if ( (list[i].data->pos.x - pos->x) * (list[i].data->pos.x - pos->x)
       + (list[i].data->pos.y - pos->y) * (list[i].data->pos.y - pos->y) <= v5 )
      break;
    if ( ++result >= num )
      return -1;
  }
  return result;
}


// ========================================================================
// ?Local3DToLocal2D@Graph@idCutterGraphManager@@QBA?AVidVec2i@@ABVidVec3@@@Z
// EA  : 0x827BABC0
// RVA : 0x007BABC0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Graph *__fastcall idCutterGraphManager::Graph::Local3DToLocal2D(
        idCutterGraphManager::Graph *this,
        idVec2i *result,
        const idVec3 *localPoint)
{
  long double v4; // fp2
  double v5; // fp30
  long double v6; // fp2
  double v7; // fp29
  long double v8; // fp2

  *((double *)&v4 + 1) = (float)((float)(*(float *)&result[29].x * localPoint->y)
                               + (float)(*(float *)&result[29].y * localPoint->z));
  v5 = (float)((float)(localPoint->x * *(float *)&result[28].y)
             + (float)((float)(*(float *)&result[29].x * localPoint->y)
                     + (float)(*(float *)&result[29].y * localPoint->z)));
  *(double *)&v4 = (float)((float)((float)(*(float *)&result[27].x * localPoint->x)
                                 + (float)((float)(*(float *)&result[27].y * localPoint->y)
                                         + (float)(*(float *)&result[28].x * localPoint->z)))
                         + (float)0.5);
  v6 = floor(x: v4);
  v7 = (float)*(double *)&v6;
  *(double *)&v6 = (float)((float)v5 + (float)0.5);
  v8 = floor(x: v6);
  this->lastNode = (idCutterGraphManager::Node_t *)(int)v7;
  this->prevNode = (idCutterGraphManager::Node_t *)(int)(float)*(double *)&v8;
  return this;
}


// ========================================================================
// ?GetLocal2D@Graph@idCutterGraphManager@@QBA?AVidVec2i@@ABVidVec3@@@Z
// EA  : 0x827BAC78
// RVA : 0x007BAC78
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Graph *__fastcall idCutterGraphManager::Graph::GetLocal2D(
        idCutterGraphManager::Graph *this,
        idVec2i *result,
        const idVec3 *point)
{
  double v4; // fp10
  double v5; // fp11
  double v6; // fp7
  double v7; // fp4
  double v8; // fp2
  idVec3 v10; // [sp+50h] [-20h] BYREF

  v4 = (float)(point->y - *(float *)&result[24].y);
  v5 = *(float *)&result[17].x;
  v6 = *(float *)&result[17].y;
  v7 = (float)((float)(*(float *)&result[15].y * (float)(point->x - *(float *)&result[24].x))
             + (float)(*(float *)&result[18].y * (float)(point->z - *(float *)&result[25].x)));
  v8 = (float)((float)(*(float *)&result[16].x * (float)(point->x - *(float *)&result[24].x))
             + (float)(*(float *)&result[19].x * (float)(point->z - *(float *)&result[25].x)));
  v10.x = (float)(*(float *)&result[15].x * (float)(point->x - *(float *)&result[24].x))
        + (float)((float)(*(float *)&result[18].x * (float)(point->z - *(float *)&result[25].x))
                + (float)(*(float *)&result[16].y * (float)(point->y - *(float *)&result[24].y)));
  v10.y = (float)((float)v5 * (float)v4) + (float)v7;
  v10.z = (float)((float)v6 * (float)v4) + (float)v8;
  idCutterGraphManager::Graph::Local3DToLocal2D(this, result, localPoint: &v10);
  return this;
}


// ========================================================================
// ?GetPosition3D@Graph@idCutterGraphManager@@QBA?AVidVec3@@ABVidVec2i@@@Z
// EA  : 0x827BAD28
// RVA : 0x007BAD28
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCutterGraphManager::Graph *__fastcall idCutterGraphManager::Graph::GetPosition3D(
        idCutterGraphManager::Graph *this,
        idVec3 *result,
        const idVec2i *point2d,
        int a4,
        __int64 a5)
{
  int x; // r9
  double y; // fp27
  double z; // fp26
  double v8; // fp10
  double v9; // fp9

  x = point2d->x;
  LODWORD(a5) = point2d->y;
  y = result[16].y;
  z = result[16].z;
  v8 = (float)((float)(result[13].y
                     * (float)((float)(result[18].x * (float)*(__int64 *)((char *)&a5 - 4))
                             + (float)(result[19].x * (float)a5)))
             + (float)((float)(result[15].y
                             * (float)((float)(result[18].z * (float)*(__int64 *)((char *)&a5 - 4))
                                     + (float)(result[19].z * (float)a5)))
                     + (float)(result[14].y
                             * (float)((float)(result[18].y * (float)*(__int64 *)((char *)&a5 - 4))
                                     + (float)(result[19].y * (float)a5)))));
  v9 = (float)((float)(result[13].z
                     * (float)((float)(result[18].x * (float)*(__int64 *)((char *)&a5 - 4))
                             + (float)(result[19].x * (float)a5)))
             + (float)((float)(result[15].z
                             * (float)((float)(result[18].z * (float)*(__int64 *)((char *)&a5 - 4))
                                     + (float)(result[19].z * (float)a5)))
                     + (float)(result[14].z
                             * (float)((float)(result[18].y * (float)*(__int64 *)((char *)&a5 - 4))
                                     + (float)(result[19].y * (float)a5)))));
  *(float *)&this->lastNode = result[16].x
                            + (float)((float)(result[13].x
                                            * (float)((float)(result[18].x * (float)*(__int64 *)((char *)&a5 - 4))
                                                    + (float)(result[19].x * (float)a5)))
                                    + (float)((float)(result[15].x
                                                    * (float)((float)(result[18].z * (float)*(__int64 *)((char *)&a5 - 4))
                                                            + (float)(result[19].z * (float)a5)))
                                            + (float)(result[14].x
                                                    * (float)((float)(result[18].y * (float)*(__int64 *)((char *)&a5 - 4))
                                                            + (float)(result[19].y * (float)a5)))));
  *(float *)&this->prevNode = (float)y + (float)v8;
  *(float *)&this->nodes.list = (float)z + (float)v9;
  return this;
}


// ========================================================================
// ?SetPosition@Graph@idCutterGraphManager@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827BAE28
// RVA : 0x007BAE28
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Graph::SetPosition(
        idCutterGraphManager::Graph *this,
        const idVec3 *position_,
        const idMat3 *orientation_)
{
  idMat3 v3; // [sp+50h] [-40h] BYREF

  this->position = *position_;
  this->orientation = *orientation_;
  this->inverse = *idMat3::Inverse(this: &v3, result: &this->orientation);
}


// ========================================================================
// ?DebugDraw@Graph@idCutterGraphManager@@QAAXPAVidRenderWorld@@H@Z
// EA  : 0x827BAF10
// RVA : 0x007BAF10
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCutterGraphManager::Graph::DebugDraw(
        idCutterGraphManager::Graph *this,
        idRenderWorld *renderWorld,
        __int64 lifeTime)
{
  int v5; // r22
  int v6; // r25
  float *p_orientation; // r31
  idVec3 *p_down; // r28
  idVec3 *p_left; // r27
  idVec3 *p_position; // r26
  int v11; // r29
  idCutterGraphManager::Edge_t *data; // r10
  double v13; // fp31
  __int64 pos; // r8
  double z; // fp28
  double v16; // fp0
  double v17; // fp6
  double v18; // fp1
  float v19[4]; // [sp+60h] [-B0h] BYREF
  _BYTE v20[72]; // [sp+70h] [-A0h] BYREF

  v5 = HIDWORD(lifeTime);
  v6 = 0;
  if ( this->edges.num > 0 )
  {
    p_orientation = (float *)&this->orientation;
    p_down = &this->down;
    p_left = &this->left;
    p_position = &this->position;
    v11 = 0;
    do
    {
      data = this->edges.list[v11].data;
      v13 = p_orientation[5];
      pos = (__int64)data->node1->pos;
      LODWORD(lifeTime) = data->node1->pos.y;
      z = p_position->z;
      v16 = (float)((float)(p_left->y * (float)*(__int64 *)((char *)&lifeTime - 4))
                  + (float)(p_down->y * (float)lifeTime));
      v17 = (float)((float)(p_orientation[2]
                          * (float)((float)(p_left->x * (float)*(__int64 *)((char *)&lifeTime - 4))
                                  + (float)(p_down->x * (float)lifeTime)))
                  + (float)(p_orientation[8]
                          * (float)((float)(p_left->z * (float)*(__int64 *)((char *)&lifeTime - 4))
                                  + (float)(p_down->z * (float)lifeTime))));
      v18 = (float)(p_position->y
                  + (float)((float)((float)((float)(p_left->x * (float)*(__int64 *)((char *)&lifeTime - 4))
                                          + (float)(p_down->x * (float)lifeTime))
                                  * p_orientation[1])
                          + (float)((float)(p_orientation[7]
                                          * (float)((float)(p_left->z * (float)*(__int64 *)((char *)&lifeTime - 4))
                                                  + (float)(p_down->z * (float)lifeTime)))
                                  + (float)(p_orientation[4]
                                          * (float)((float)(p_left->y * (float)*(__int64 *)((char *)&lifeTime - 4))
                                                  + (float)(p_down->y * (float)lifeTime))))));
      v19[0] = p_position->x
             + (float)((float)(*p_orientation
                             * (float)((float)(p_left->x * (float)*(__int64 *)((char *)&lifeTime - 4))
                                     + (float)(p_down->x * (float)lifeTime)))
                     + (float)((float)(p_orientation[6]
                                     * (float)((float)(p_left->z * (float)*(__int64 *)((char *)&lifeTime - 4))
                                             + (float)(p_down->z * (float)lifeTime)))
                             + (float)(p_orientation[3]
                                     * (float)((float)(p_left->y * (float)*(__int64 *)((char *)&lifeTime - 4))
                                             + (float)(p_down->y * (float)lifeTime)))));
      v19[1] = v18;
      v19[2] = (float)z + (float)((float)((float)v13 * (float)v16) + (float)v17);
      idCutterGraphManager::Graph::GetPosition3D(
        this: (idCutterGraphManager::Graph *)v20,
        result: (idVec3 *)this,
        point2d: &data->node2->pos,
        a4: pos,
        a5: pos);
      renderWorld->DebugLine(
        this: renderWorld,
        a2: (const idVec4 *)&idColor::colorOrange,
        a3: (const idVec3 *)v19,
        a4: (const idVec3 *)v20,
        a5: v5,
        a6: true);
      ++v6;
      ++v11;
    }
    while ( v6 < this->edges.num );
  }
}


// ========================================================================
// ?GetLocal2D@idCutterGraphManager@@QBA?AVidVec2i@@ABVidVec3@@@Z
// EA  : 0x827BB0A0
// RVA : 0x007BB0A0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager *__fastcall idCutterGraphManager::GetLocal2D(
        idCutterGraphManager *this,
        idVec2i *result,
        const idVec3 *point)
{
  idCutterGraphManager::Graph::GetLocal2D((idCutterGraphManager::Graph *)this, result: (idVec2i *)result[21].x, point);
  return this;
}


// ========================================================================
// ?GetLocal3D@idCutterGraphManager@@QBA?AVidVec3@@ABVidVec2@@@Z
// EA  : 0x827BB0D8
// RVA : 0x007BB0D8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager *__fastcall idCutterGraphManager::GetLocal3D(
        idCutterGraphManager *this,
        idVec3 *result,
        const idVec2 *point2d)
{
  float x; // r11
  double v4; // fp8
  double v5; // fp6
  double v6; // fp2
  double v7; // fp1

  x = result[14].x;
  v4 = (float)(*(float *)(LODWORD(x) + 232) * point2d->y);
  v5 = (float)(*(float *)(LODWORD(x) + 236) * point2d->y);
  v6 = (float)(*(float *)(LODWORD(x) + 220) * point2d->x);
  v7 = (float)(*(float *)(LODWORD(x) + 224) * point2d->x);
  *(float *)&this->__vftable = (float)(*(float *)(LODWORD(x) + 216) * point2d->x)
                             + (float)(*(float *)(LODWORD(x) + 228) * point2d->y);
  *(float *)&this->savedContours.list = (float)v6 + (float)v4;
  *(float *)&this->savedContours.num = (float)v7 + (float)v5;
  return this;
}


// ========================================================================
// ?IsGraphValid@idCutterGraphManager@@QBA_NH@Z
// EA  : 0x827BB130
// RVA : 0x007BB130
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

BOOL __fastcall idCutterGraphManager::IsGraphValid(idCutterGraphManager *this, int id)
{
  return this->graphs.list[id].graph != nullptr;
}


// ========================================================================
// ?SetPosition@idCutterGraphManager@@QAAXHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827BB148
// RVA : 0x007BB148
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::SetPosition(
        idCutterGraphManager *this,
        int id,
        const idVec3 *position,
        const idMat3 *orientation)
{
  idCutterGraphManager::Graph::SetPosition(
    this: this->graphs.list[id].graph,
    position_: position,
    orientation_: orientation);
}


// ========================================================================
// ?PointInPolygon@idCutterGraphManager@@ABA_NABVidVec2i@@PBUContourEdge_t@@@Z
// EA  : 0x827BB168
// RVA : 0x007BB168
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

BOOL __fastcall idCutterGraphManager::PointInPolygon(
        idCutterGraphManager *this,
        const idVec2i *pos,
        const ContourEdge_t *edge)
{
  BOOL result; // r3
  ContourNode_t *node; // r11
  ContourNode_t *next; // r7
  idVec2i v6; // r11
  int y; // r8
  signed int v8; // r8
  int v9; // r9
  int v10; // r6

  result = false;
  if ( edge != nullptr )
  {
    while ( 1 )
    {
      node = edge->node;
      next = node->next;
      if ( node->next != nullptr )
        break;
LABEL_11:
      edge = edge->next;
      if ( edge == nullptr )
        return result;
    }
    while ( 1 )
    {
      v6 = node->pos;
      y = next->pos.y;
      if ( v6.y > v6.x )
      {
        if ( y > v6.x )
          goto LABEL_10;
      }
      else if ( v6.x < y )
      {
        goto LABEL_8;
      }
      if ( v6.x < v6.y )
      {
LABEL_8:
        v8 = y - v6.y;
        v9 = pos->x - v6.x;
        v10 = (v6.x - v6.y) * (next->pos.x - v6.x);
        __twllei(v8, 0);
        __twlgei(v8 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
        if ( v9 < v10 / v8 )
          result = (_cntlzw(result) & 0x20) != 0;
      }
LABEL_10:
      node = next;
      next = next->next;
      if ( next == nullptr )
        goto LABEL_11;
    }
  }
  return result;
}


// ========================================================================
// ?GetNormalVectors@idCutterGraphManager@@QBAXHAAVidVec3@@00@Z
// EA  : 0x827BB238
// RVA : 0x007BB238
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::GetNormalVectors(
        idCutterGraphManager *this,
        int id,
        idVec3 *normal_,
        idVec3 *left_,
        idVec3 *up_)
{
  idCutterGraphManager::Graph *graph; // r9
  double y; // fp7
  double v7; // fp5

  graph = this->graphs.list[id].graph;
  normal_->x = graph->normal.x;
  normal_->y = graph->normal.y;
  normal_->z = graph->normal.z;
  left_->x = graph->left.x;
  left_->y = graph->left.y;
  left_->z = graph->left.z;
  y = graph->down.y;
  v7 = -graph->down.z;
  up_->x = -graph->down.x;
  up_->y = -y;
  up_->z = v7;
}


// ========================================================================
// ?GetOuterContour@idCutterGraphManager@@QBAPAVContour@@H@Z
// EA  : 0x827BB2A0
// RVA : 0x007BB2A0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

Contour *__fastcall idCutterGraphManager::GetOuterContour(idCutterGraphManager *this, int id)
{
  return this->graphs.list[id].graph->contoursOuter;
}


// ========================================================================
// ?GetInnerContour@idCutterGraphManager@@QBAPAVContour@@H@Z
// EA  : 0x827BB2B8
// RVA : 0x007BB2B8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

Contour *__fastcall idCutterGraphManager::GetInnerContour(idCutterGraphManager *this, int id)
{
  return this->graphs.list[id].graph->contoursInner;
}


// ========================================================================
// ?DebugDraw@idCutterGraphManager@@QAAXHPAVidRenderWorld@@H@Z
// EA  : 0x827BB2D0
// RVA : 0x007BB2D0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::DebugDraw(idCutterGraphManager *this, int id, __int64 lifeTime)
{
  idRenderWorld *v3; // r11
  idCutterGraphManager::Graph *graph; // r3

  v3 = (idRenderWorld *)HIDWORD(lifeTime);
  graph = this->graphs.list[id].graph;
  if ( graph != nullptr )
  {
    HIDWORD(lifeTime) = lifeTime;
    idCutterGraphManager::Graph::DebugDraw(this: graph, renderWorld: v3, lifeTime);
  }
}


// ========================================================================
// ?FindClosestNode@Graph@idCutterGraphManager@@QAAHPAUEdge_t@2@ABVidVec2i@@H@Z
// EA  : 0x827BB2F8
// RVA : 0x007BB2F8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::Graph::FindClosestNode(
        idCutterGraphManager::Graph *this,
        idCutterGraphManager::Edge_t *edge,
        const idVec2i *hitPos,
        int threshold)
{
  idCutterGraphManager::Node_t *node1; // r10
  int v5; // r11
  idCutterGraphManager::Node_t *node2; // r9
  int y; // r7
  const idVec2i *p_pos; // r31
  int v10; // r30
  int result; // r3
  int v12; // r28

  node1 = edge->node1;
  v5 = threshold * threshold;
  node2 = edge->node2;
  y = hitPos->y;
  p_pos = &node2->pos;
  v10 = (hitPos->x - node1->pos.x) * (hitPos->x - node1->pos.x) + (y - node1->pos.y) * (y - node1->pos.y);
  v12 = (hitPos->x - node2->pos.x) * (hitPos->x - node2->pos.x) + (y - node2->pos.y) * (y - node2->pos.y);
  result = -1;
  if ( v10 < threshold * threshold )
  {
    result = idCutterGraphManager::Graph::FindNodeIndex(this, pos: &node1->pos, threshold: 0);
    v5 = v10;
  }
  if ( v12 < v5 )
    return idCutterGraphManager::Graph::FindNodeIndex(this, pos: p_pos, threshold: 0);
  return result;
}


// ========================================================================
// ?FindSplitEdge@Graph@idCutterGraphManager@@QBAPAUEdge_t@2@PBUNode_t@2@ABVidVec2i@@AAV5@@Z
// EA  : 0x827BB398
// RVA : 0x007BB398
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idCutterGraphManager::Edge_t *__fastcall idCutterGraphManager::Graph::FindSplitEdge(
        idCutterGraphManager::Graph *this,
        const idCutterGraphManager::Node_t *srcNode,
        const idVec2i *dst,
        idVec2i *pos)
{
  int num; // r25
  double v6; // fp3
  _BYTE v7[20]; // r11 OVERLAPPED
  double v8; // fp4
  __int64 v9; // r29 OVERLAPPED
  int v10; // r27 OVERLAPPED
  idCutterGraphManager::Edge_t *result; // r3
  int v12; // r26
  idVec2i v13; // r23
  idCutterGraphManager::edgeHandle_t *list; // r30 OVERLAPPED
  int v15; // r29
  int v16; // r20
  double v17; // fp2
  __int64 v18; // r20
  __int64 v19; // fp13
  double v20; // fp10
  double v21; // fp1
  double v22; // fp0
  double v23; // fp13
  int v24; // r31
  int v25; // r20
  int v26; // r31 OVERLAPPED
  double v27; // fp1
  double v28; // fp9
  double v29; // fp10
  double v30; // fp1
  double v31; // fp0
  double v32; // fp13
  char v33; // r9
  int v34; // r20
  int v35; // r18 OVERLAPPED
  __int64 v36; // r20 OVERLAPPED
  __int64 v37; // fp11
  double v38; // fp12
  double v39; // fp12
  double v40; // fp0
  double v41; // fp13
  char v42; // r9
  int v43; // r31
  __int64 v44; // r20
  int v45; // r31 OVERLAPPED
  __int64 v46; // fp1
  double v47; // fp10
  double v48; // fp1
  double v49; // fp0
  double v50; // fp13
  idCutterGraphManager::edgeHandle_t *v51; // r30
  int v52; // r31
  int v53; // ctr
  __int64 v54; // r26
  double v55; // fp1
  double v56; // fp0
  double v57; // fp13
  idVec2i v58; // [sp+0h] [-160h]
  __int64 v59; // [sp+38h] [-128h]
  __int64 v60; // [sp+40h] [-120h]
  __int64 v61; // [sp+48h] [-118h]
  __int64 v62; // [sp+58h] [-108h]
  __int64 v63; // [sp+70h] [-F0h]
  __int64 v64; // [sp+78h] [-E8h]

  *(idVec2i *)&v7[8] = *dst;
  *(idVec2i *)&v7[4] = srcNode->pos;
  num = this->edges.num;
  v58 = 0;
  v6 = 1.0e30;
  *(_DWORD *)v7 = srcNode->pos.y;
  v8 = 0.0;
  *(__int64 *)((char *)&v9 + 4) = *(_QWORD *)&v7[8];
  result = nullptr;
  v12 = 0;
  v13 = 0;
  if ( num >= 4 )
  {
    list = this->edges.list;
    v13.x = num - 3;
    v15 = 0;
    do
    {
      *(idCutterGraphManager::edgeHandle_t *)&v7[4] = list[v15];
      *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[4] + 4);
      *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[4] + 8);
      if ( srcNode != *(const idCutterGraphManager::Node_t **)&v7[16]
        && srcNode != *(const idCutterGraphManager::Node_t **)&v7[12] )
      {
        v16 = v10 - 0x82000000;
        *(_DWORD *)&v7[8] = *(_DWORD *)(*(_DWORD *)&v7[16] + 8);
        *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[16] + 12);
        HIDWORD(v18) = *(_DWORD *)(*(_DWORD *)&v7[12] + 8) - *(_DWORD *)&v7[8];
        v17 = (double)v18;
        LODWORD(v18) = HIDWORD(v18);
        *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[12] + 12) - *(_DWORD *)&v7[16];
        v63 = *(_QWORD *)&v7[8];
        *(_DWORD *)&v7[12] = *(_DWORD *)v7 - *(_DWORD *)&v7[16];
        v19 = v18;
        LODWORD(v18) = HIDWORD(v9) - *(_DWORD *)v7;
        *(_DWORD *)&v7[16] = 0x82000000 - *(_DWORD *)&v7[8];
        if ( __fabs((float)((float)((float)v63 * (float)v17) - (float)((float)v18 * (float)v19))) < 0.00000011920929
          || (v20 = (float)((float)1.0 / (float)((float)((float)v63 * (float)v17) - (float)((float)v18 * (float)v19))),
              v21 = (float)((float)((float)*(__int64 *)&v7[8] * (float)v19)
                          - (float)((float)*(__int64 *)&v7[12] * (float)v63)),
              v22 = (float)((float)((float)((float)*(__int64 *)&v7[8] * (float)v19)
                                  - (float)((float)*(__int64 *)&v7[12] * (float)v63))
                          * (float)((float)1.0
                                  / (float)((float)((float)v63 * (float)v17) - (float)((float)v18 * (float)v19)))),
              v23 = (float)((float)((float)((float)*(__int64 *)&v7[8] * (float)v17)
                                  - (float)((float)*(__int64 *)&v7[12] * (float)v18))
                          * (float)((float)1.0
                                  / (float)((float)((float)v63 * (float)v17) - (float)((float)v18 * (float)v19)))),
              v22 < 0.0)
          || v22 > 1.0
          || v23 < 0.0
          || v23 > 1.0 )
        {
          v7[11] = 0;
        }
        else
        {
          v7[11] = 1;
          v8 = (float)((float)v21 * (float)v20);
          v58.x = (int)(float)((float)((float)v21 * (float)v20) * (float)v17) + 0x82000000;
          v58.y = (int)(float)((float)((float)v21 * (float)v20) * (float)v18) + *(_DWORD *)v7;
        }
        if ( v7[11] != 0 && v8 <= v6 )
        {
          v13 = v58;
          v6 = v8;
          result = list[v15].data;
        }
      }
      *(idCutterGraphManager::edgeHandle_t *)&v7[4] = list[v15 + 1];
      *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[4] + 4);
      *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[4] + 8);
      if ( srcNode != *(const idCutterGraphManager::Node_t **)&v7[16]
        && srcNode != *(const idCutterGraphManager::Node_t **)&v7[12] )
      {
        *(_DWORD *)&v7[8] = *(_DWORD *)(*(_DWORD *)&v7[16] + 8);
        v24 = HIDWORD(v9) - *(_DWORD *)v7;
        *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[16] + 12);
        v25 = *(_DWORD *)(*(_DWORD *)&v7[12] + 8) - *(_DWORD *)&v7[8];
        *(_DWORD *)&v7[8] = 0x82000000 - *(_DWORD *)&v7[8];
        *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[12] + 12) - *(_DWORD *)&v7[16];
        v64 = *(_QWORD *)&v7[8];
        *(_DWORD *)&v7[12] = *(_DWORD *)&v7[8];
        *(_DWORD *)&v7[8] = *(_DWORD *)v7 - *(_DWORD *)&v7[16];
        *(_DWORD *)&v7[16] = v10 - 0x82000000;
        v27 = (double)*(__int64 *)&(&list)[-1];
        v28 = (float)*(__int64 *)&(&list)[-1];
        v26 = v25;
        if ( __fabs((float)((float)((float)v64 * (float)*(__int64 *)&v7[12])
                          - (float)((float)v27 * (float)*(__int64 *)&(&list)[-1]))) < 0.00000011920929
          || (v29 = (float)((float)1.0
                          / (float)((float)((float)v64 * (float)*(__int64 *)&v7[12])
                                  - (float)((float)v27 * (float)*(__int64 *)&(&list)[-1]))),
              v31 = (float)((float)((float)((float)*(__int64 *)&v7[4] * (float)*(__int64 *)&(&list)[-1])
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v64))
                          * (float)((float)1.0
                                  / (float)((float)((float)v64 * (float)*(__int64 *)&v7[12])
                                          - (float)((float)v27 * (float)*(__int64 *)&(&list)[-1])))),
              v32 = (float)((float)((float)((float)*(__int64 *)&v7[4] * (float)*(__int64 *)&v7[12])
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v27))
                          * (float)((float)1.0
                                  / (float)((float)((float)v64 * (float)*(__int64 *)&v7[12])
                                          - (float)((float)v27 * (float)*(__int64 *)&(&list)[-1])))),
              v30 = (float)((float)((float)*(__int64 *)&v7[4] * (float)*(__int64 *)&(&list)[-1])
                          - (float)((float)*(__int64 *)&v7[8] * (float)v64)),
              v31 < 0.0)
          || v31 > 1.0
          || v32 < 0.0
          || v32 > 1.0 )
        {
          v33 = 0;
        }
        else
        {
          v33 = 1;
          v8 = (float)((float)v30 * (float)v29);
          v58.x = (int)(float)((float)((float)v30 * (float)v29) * (float)*(__int64 *)&v7[12]) + 0x82000000;
          v58.y = (int)(float)((float)((float)v30 * (float)v29) * (float)v28) + *(_DWORD *)v7;
        }
        if ( v33 != 0 && v8 <= v6 )
        {
          v13 = v58;
          v6 = v8;
          result = list[v15 + 1].data;
        }
      }
      *(idCutterGraphManager::edgeHandle_t *)&v7[4] = list[v15 + 2];
      *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[4] + 4);
      *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[4] + 8);
      if ( srcNode != *(const idCutterGraphManager::Node_t **)&v7[16]
        && srcNode != *(const idCutterGraphManager::Node_t **)&v7[12] )
      {
        v34 = HIDWORD(v9) - *(_DWORD *)v7;
        v35 = v10 - 0x82000000;
        *(_DWORD *)&v7[8] = *(_DWORD *)(*(_DWORD *)&v7[16] + 12);
        *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[16] + 8);
        HIDWORD(v36) = *(_DWORD *)(*(_DWORD *)&v7[12] + 12) - *(_DWORD *)&v7[8];
        v37 = v36;
        LODWORD(v36) = v10 - 0x82000000;
        *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[12] + 8) - *(_DWORD *)&v7[16];
        *(_DWORD *)&v7[8] = *(_DWORD *)v7 - *(_DWORD *)&v7[8];
        v38 = (double)*(__int64 *)&v7[8];
        *(_DWORD *)&v7[12] = *(_DWORD *)&v7[8];
        v62 = *(_QWORD *)&v7[8];
        v39 = (float)v38;
        *(_DWORD *)&v7[16] = 0x82000000 - *(_DWORD *)&v7[16];
        if ( __fabs((float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                          - (float)((float)v37 * (float)v39))) < 0.00000011920929
          || (v40 = (float)((float)((float)((float)*(__int64 *)&v7[8] * (float)v39)
                                  - (float)((float)*(__int64 *)&v7[12] * (float)*(__int64 *)((char *)&v36 + 4)))
                          * (float)((float)1.0
                                  / (float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                                          - (float)((float)v37 * (float)v39)))),
              v41 = (float)((float)((float)((float)*(__int64 *)&v7[8] * (float)v36)
                                  - (float)((float)*(__int64 *)&v7[12] * (float)v37))
                          * (float)((float)1.0
                                  / (float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                                          - (float)((float)v37 * (float)v39)))),
              v40 < 0.0)
          || v40 > 1.0
          || v41 < 0.0
          || v41 > 1.0 )
        {
          v42 = 0;
        }
        else
        {
          v42 = 1;
          v8 = (float)((float)((float)((float)v62 * (float)v39)
                             - (float)((float)*(__int64 *)&v7[12] * (float)*(__int64 *)((char *)&v36 + 4)))
                     * (float)((float)1.0
                             / (float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                                     - (float)((float)v37 * (float)v39))));
          v58.x = (int)(float)((float)((float)((float)((float)v62 * (float)v39)
                                             - (float)((float)*(__int64 *)&v7[12] * (float)*(__int64 *)((char *)&v36 + 4)))
                                     * (float)((float)1.0
                                             / (float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                                                     - (float)((float)v37 * (float)v39))))
                             * (float)v36)
                + 0x82000000;
          v58.y = (int)(float)((float)((float)((float)((float)v62 * (float)v39)
                                             - (float)((float)*(__int64 *)&v7[12] * (float)*(__int64 *)((char *)&v36 + 4)))
                                     * (float)((float)1.0
                                             / (float)((float)((float)*(__int64 *)((char *)&v36 + 4) * (float)v36)
                                                     - (float)((float)v37 * (float)v39))))
                             * (float)v37)
                + *(_DWORD *)v7;
        }
        if ( v42 != 0 && v8 <= v6 )
        {
          v13 = v58;
          v6 = v8;
          result = list[v15 + 2].data;
        }
      }
      *(idCutterGraphManager::edgeHandle_t *)&v7[8] = list[v15 + 3];
      *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[8] + 4);
      *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[8] + 8);
      if ( srcNode != *(const idCutterGraphManager::Node_t **)&v7[16]
        && srcNode != *(const idCutterGraphManager::Node_t **)&v7[12] )
      {
        v43 = HIDWORD(v9) - *(_DWORD *)v7;
        *(_DWORD *)&v7[4] = *(_DWORD *)(*(_DWORD *)&v7[16] + 8);
        HIDWORD(v44) = v10 - 0x82000000;
        *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[16] + 12);
        LODWORD(v44) = *(_DWORD *)(*(_DWORD *)&v7[12] + 8) - *(_DWORD *)&v7[4];
        v61 = *(_QWORD *)&(&list)[-1];
        v45 = v10 - 0x82000000;
        *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[12] + 12) - *(_DWORD *)&v7[16];
        v46 = *(_QWORD *)&v7[8];
        *(_DWORD *)&v7[12] = 0x82000000 - *(_DWORD *)&v7[4];
        *(_DWORD *)&v7[4] = *(_DWORD *)v7 - *(_DWORD *)&v7[16];
        if ( __fabs((float)((float)((float)v46 * (float)*(__int64 *)&(&list)[-1]) - (float)((float)v61 * (float)v44))) < 0.00000011920929
          || (v47 = (float)((float)1.0
                          / (float)((float)((float)v46 * (float)*(__int64 *)&(&list)[-1])
                                  - (float)((float)v61 * (float)v44))),
              v49 = (float)((float)((float)((float)*(__int64 *)v7 * (float)v44)
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v46))
                          * (float)((float)1.0
                                  / (float)((float)((float)v46 * (float)*(__int64 *)&(&list)[-1])
                                          - (float)((float)v61 * (float)v44)))),
              v50 = (float)((float)((float)((float)*(__int64 *)v7 * (float)*(__int64 *)&(&list)[-1])
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v61))
                          * (float)((float)1.0
                                  / (float)((float)((float)v46 * (float)*(__int64 *)&(&list)[-1])
                                          - (float)((float)v61 * (float)v44)))),
              v48 = (float)((float)((float)*(__int64 *)v7 * (float)v44) - (float)((float)*(__int64 *)&v7[8] * (float)v46)),
              v49 < 0.0)
          || v49 > 1.0
          || v50 < 0.0
          || v50 > 1.0 )
        {
          v7[15] = 0;
        }
        else
        {
          v7[15] = 1;
          v8 = (float)((float)v48 * (float)v47);
          v58.y = (int)(float)((float)((float)v48 * (float)v47) * (float)v61) + *(_DWORD *)v7;
          v58.x = (int)(float)((float)((float)v48 * (float)v47) * (float)*(__int64 *)&(&list)[-1]) + 0x82000000;
        }
        if ( v7[15] != 0 && v8 <= v6 )
        {
          v13 = v58;
          v6 = v8;
          result = list[v15 + 3].data;
        }
      }
      v12 += 4;
      v15 += 4;
    }
    while ( v12 < v13.x );
  }
  if ( v12 < num )
  {
    v52 = v12;
    v53 = num - v12;
    do
    {
      v51 = this->edges.list;
      *(idCutterGraphManager::edgeHandle_t *)&v7[4] = v51[v52];
      *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[4] + 4);
      *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[4] + 8);
      if ( srcNode != *(const idCutterGraphManager::Node_t **)&v7[16]
        && srcNode != *(const idCutterGraphManager::Node_t **)&v7[12] )
      {
        LODWORD(v9) = HIDWORD(v9) - *(_DWORD *)v7;
        *(_DWORD *)&v7[8] = *(_DWORD *)(*(_DWORD *)&v7[16] + 8);
        HIDWORD(v54) = v10 - 0x82000000;
        LODWORD(v54) = *(_DWORD *)(*(_DWORD *)&v7[12] + 8) - *(_DWORD *)&v7[8];
        *(_DWORD *)&v7[16] = *(_DWORD *)(*(_DWORD *)&v7[16] + 12);
        *(_DWORD *)&v7[8] = 0x82000000 - *(_DWORD *)&v7[8];
        v59 = v9;
        *(_DWORD *)&v7[12] = *(_DWORD *)(*(_DWORD *)&v7[12] + 12) - *(_DWORD *)&v7[16];
        LODWORD(v9) = v10 - 0x82000000;
        v60 = *(_QWORD *)&v7[8];
        *(_QWORD *)&v7[8] = __PAIR64__(*(_DWORD *)v7 - *(_DWORD *)&v7[16], *(unsigned int *)&v7[8]);
        if ( __fabs((float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54))) < 0.00000011920929
          || (v55 = (float)((float)((float)*(__int64 *)&v7[4] * (float)v54)
                          - (float)((float)*(__int64 *)&v7[8] * (float)v60)),
              v56 = (float)((float)((float)((float)*(__int64 *)&v7[4] * (float)v54)
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v60))
                          * (float)((float)1.0
                                  / (float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54)))),
              v57 = (float)((float)((float)((float)*(__int64 *)&v7[4] * (float)v9)
                                  - (float)((float)*(__int64 *)&v7[8] * (float)v59))
                          * (float)((float)1.0
                                  / (float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54)))),
              v56 < 0.0)
          || v56 > 1.0
          || v57 < 0.0
          || v57 > 1.0 )
        {
          v7[11] = 0;
        }
        else
        {
          v7[11] = 1;
          v8 = (float)((float)v55
                     * (float)((float)1.0 / (float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54))));
          v58.x = (int)(float)((float)((float)v55
                                     * (float)((float)1.0
                                             / (float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54))))
                             * (float)v9)
                + 0x82000000;
          v58.y = (int)(float)((float)((float)v55
                                     * (float)((float)1.0
                                             / (float)((float)((float)v60 * (float)v9) - (float)((float)v59 * (float)v54))))
                             * (float)v59)
                + *(_DWORD *)v7;
        }
        if ( v7[11] != 0 && v8 <= v6 )
        {
          v13 = v58;
          v6 = v8;
          result = v51[v52].data;
        }
      }
      ++v52;
      --v53;
    }
    while ( v53 != 0 );
  }
  *pos = v13;
  return result;
}


// ========================================================================
// ??0IDHeap@idCutterGraphManager@@QAA@XZ
// EA  : 0x827BBB88
// RVA : 0x007BBB88
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::IDHeap *__fastcall idCutterGraphManager::IDHeap::IDHeap(idCutterGraphManager::IDHeap *this)
{
  this->buffer.list = nullptr;
  this->buffer.granularity = 0;
  this->buffer.memTag = 5;
  this->buffer.listStatic = 0;
  this->buffer.size = 0;
  this->buffer.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  *((_DWORD *)this + 4) = 0;
  this->numBits = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  return this;
}


// ========================================================================
// __unwind$230083
// EA  : 0x827BBBE0
// RVA : 0x007BBBE0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_230083()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??1IDHeap@idCutterGraphManager@@QAA@XZ
// EA  : 0x827BBC10
// RVA : 0x007BBC10
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::IDHeap::~IDHeap(idCutterGraphManager::IDHeap *this)
{
  int v2; // r9

  v2 = *((_DWORD *)this + 4) & 1;
  this->numBits = 0;
  *((_DWORD *)this + 4) = v2;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$230102
// EA  : 0x827BBC68
// RVA : 0x007BBC68
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_230102()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Create@IDHeap@idCutterGraphManager@@QAAXH@Z
// EA  : 0x827BC0E0
// RVA : 0x007BC0E0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::IDHeap::Create(idCutterGraphManager::IDHeap *this, int numBits_)
{
  int size; // r10
  int v4; // r11
  int v5; // r30
  int v6; // r11
  int num; // r10
  int v8; // r11
  int i; // ctr

  size = this->buffer.size;
  v4 = (numBits_ + 7) >> 3;
  v5 = v4 + 1;
  this->numBits = 8 * (v4 + 1);
  if ( v4 + 1 <= size || idList<unsigned char,25>::Resize((idList<unsigned char,37> *)this, newsize: v4 + 1) )
  {
    v6 = this->buffer.size;
    if ( v5 < v6 )
      v6 = v5;
    this->buffer.num = v6;
  }
  num = this->buffer.num;
  v8 = 0;
  *((_DWORD *)this + 4) &= 1u;
  if ( num > 0 )
  {
    for ( i = num; i != 0; --i )
      this->buffer.list[v8++] = 0;
  }
}


// ========================================================================
// ?Read@IDHeap@idCutterGraphManager@@QAAXPAVidFile@@@Z
// EA  : 0x827BC190
// RVA : 0x007BC190
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::IDHeap::Read(idCutterGraphManager::IDHeap *this, idFile *file)
{
  idFile_vtbl *v2; // r10
  unsigned int v5; // r5
  int v6; // r29
  bool v7; // r3
  int size; // r11
  int v9; // [sp+50h] [-30h] BYREF
  _DWORD v10[11]; // [sp+54h] [-2Ch] BYREF

  v2 = file->__vftable;
  v10[0] = 0;
  v9 = 0;
  v2->Read(this: file, a2: &v9, a3: 4u);
  v5 = v9;
  v6 = v9;
  if ( v9 <= this->buffer.size
    || (v7 = idList<unsigned char,25>::Resize((idList<unsigned char,37> *)this, newsize: v9), v5 = v9, v7) )
  {
    size = this->buffer.size;
    if ( v6 < size )
      size = v6;
    this->buffer.num = size;
  }
  file->Read(this: file, a2: this->buffer.list, a3: v5);
  file->Read(this: file, a2: v10, a3: 4u);
  *((_DWORD *)this + 4) = (2 * v10[0]) | *((_DWORD *)this + 4) & 1;
  file->Read(this: file, a2: v10, a3: 4u);
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFFFE | v10[0] & 1;
  file->Read(this: file, a2: &this->numBits, a3: 4u);
}


// ========================================================================
// ?Acquire@Graph@idCutterGraphManager@@QAAXXZ
// EA  : 0x827BC2A8
// RVA : 0x007BC2A8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Graph::Acquire(idCutterGraphManager::Graph *this)
{
  idList<idCutterGraphManager::nodeHandle_t,5> *p_nodes; // r3
  int size; // r11

  size = this->nodes.size;
  p_nodes = &this->nodes;
  if ( size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)p_nodes, newsize: 1024);
  if ( this->edges.size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->edges, newsize: 1024);
  if ( this->links.size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->links, newsize: 1024);
}


// ========================================================================
// ?AddNode@Graph@idCutterGraphManager@@QAAXPAUNode_t@2@@Z
// EA  : 0x827BC318
// RVA : 0x007BC318
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Graph::AddNode(
        idCutterGraphManager::Graph *this,
        idCutterGraphManager::Node_t *node)
{
  int v4; // r3
  int v5; // r11
  idCutterGraphManager::Node_t *v6; // [sp+50h] [-20h] BYREF

  v4 = idCutterGraphManager::IDHeap::Alloc(this: &this->idheap);
  v5 = *((_DWORD *)node + 4);
  v6 = node;
  *((_DWORD *)node + 4) = (2 * v4) | v5 & 1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->nodes,
    obj: (const encounterGroupRole_t *)&v6);
}


// ========================================================================
// ?BuildGraphTree@Graph@idCutterGraphManager@@QAAXAAUgraphTree_t@@@Z
// EA  : 0x827BC370
// RVA : 0x007BC370
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCutterGraphManager::Graph::BuildGraphTree(
        idCutterGraphManager::Graph *this,
        graphTree_t *graphTree,
        int a3,
        _BYTE a4[12])
{
  int v6; // r11
  int v7; // r10
  idCutterGraphManager::Edge_t *data; // r9
  int v9; // r23
  int v10; // r26
  idCutterGraphManager::Node_t *node1; // r29
  int num; // r28
  idCutterGraphManager::Link_t *link; // r11
  idCutterGraphManager::Node_t *node; // r30
  idCutterGraphManager::Edge_t *edge; // r11
  double x; // fp0
  double y; // fp13
  int v18; // r9
  double z; // fp12
  double v20; // fp11
  double v21; // fp11
  double v22; // fp10
  int v23; // r9
  double v24; // fp11
  double v25; // fp1
  double v26; // fp0
  double v27; // fp13
  double v28; // fp12
  double v29; // fp11
  double v30; // fp10
  int v31; // r11
  int v32; // r29
  int v33; // r30
  idCutterGraphManager::Node_t *v34; // r11
  idCutterGraphManager::Link_t *v35; // r10
  double v36; // fp11
  const idVec3 *v37; // r4
  idStaticList<idVec3,1024> *p_endpoints; // r3
  double v39; // fp1
  double v40; // fp0
  double v41; // fp13
  double v42; // fp12
  double v43; // fp11
  double v44; // fp10
  double v45; // fp0
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  double v49; // fp7
  double v50; // fp11
  double v51; // fp10
  graphBranch_t v52; // [sp+50h] [-A0h] BYREF
  __int64 v53; // [sp+58h] [-98h]
  __int64 v54; // [sp+60h] [-90h]
  __int64 v55; // [sp+68h] [-88h]
  __int64 v56; // [sp+70h] [-80h]
  idVec3 v57; // [sp+78h] [-78h] BYREF
  idVec3 v58[8]; // [sp+88h] [-68h] BYREF

  v6 = 0;
  if ( this->edges.num > 0 )
  {
    v7 = 0;
    do
    {
      ++v6;
      data = this->edges.list[v7++].data;
      *(_DWORD *)&a4[4] = *((_DWORD *)data + 5) & 0x7FFFFFFF;
      *((_DWORD *)data + 5) = *(_DWORD *)&a4[4];
      *(_DWORD *)a4 = this->edges.num;
    }
    while ( v6 < *(int *)a4 );
  }
  v9 = 0;
  if ( this->links.num > 0 )
  {
    v10 = 0;
    do
    {
      node1 = nullptr;
      num = graphTree->positions.num;
      link = this->links.list[v10].data;
      while ( link != nullptr )
      {
        if ( *((int *)link->edge + 5) >= 0 )
        {
          *((_DWORD *)link->edge + 5) |= 0x80000000;
          node = link->node;
          if ( node1 == nullptr )
          {
            edge = link->edge;
            node1 = edge->node1;
            if ( node == node1 )
              node1 = edge->node2;
            x = this->down.x;
            y = this->down.y;
            v18 = node1->pos.x;
            z = this->down.z;
            *(_DWORD *)&a4[8] = node1->pos.y;
            v20 = this->left.x;
            v54 = *(_QWORD *)&a4[-4];
            v53 = *(_QWORD *)&a4[4];
            v22 = (float)((float)((float)v20 * (float)*(__int64 *)&a4[-4])
                        + (float)((float)x * (float)*(__int64 *)&a4[4]));
            v21 = (float)(this->left.z * (float)*(__int64 *)&a4[-4]);
            v57.y = (float)(this->left.y * (float)*(__int64 *)&a4[-4]) + (float)((float)y * (float)*(__int64 *)&a4[4]);
            v57.x = v22;
            v57.z = (float)v21 + (float)((float)z * (float)*(__int64 *)&a4[4]);
            idList<idAngles,5>::Append(this: &graphTree->positions, obj: &v57);
          }
          v23 = node->pos.x;
          *(_DWORD *)&a4[8] = node->pos.y;
          v24 = this->left.x;
          v25 = (float)(this->down.x * (float)*(__int64 *)&a4[4]);
          v26 = (float)(this->down.y * (float)*(__int64 *)&a4[4]);
          v27 = (float)(this->down.z * (float)*(__int64 *)&a4[4]);
          v55 = *(_QWORD *)&a4[-4];
          v28 = (float)(this->left.y * (float)*(__int64 *)&a4[-4]);
          v56 = *(_QWORD *)&a4[4];
          v30 = (float)((float)((float)v24 * (float)*(__int64 *)&a4[-4]) + (float)v25);
          v29 = (float)(this->left.z * (float)*(__int64 *)&a4[-4]);
          v58[0].x = v30;
          v58[0].y = (float)v28 + (float)v26;
          v58[0].z = (float)v29 + (float)v27;
          idList<idAngles,5>::Append(this: &graphTree->positions, obj: v58);
          link = node->link;
        }
        else
        {
          link = link->next;
        }
      }
      v31 = graphTree->positions.num;
      if ( v31 > num )
      {
        v52.index = num;
        v52.num = v31 - num;
        idList<graphBranch_t,5>::Append(this: &graphTree->branches, obj: &v52);
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->links.num );
  }
  v32 = 0;
  if ( this->nodes.num > 0 )
  {
    v33 = 0;
    do
    {
      v34 = this->nodes.list[v33].data;
      v35 = v34->link;
      if ( v35 != nullptr )
      {
        if ( v35->next == nullptr )
        {
          *(_DWORD *)&a4[8] = v34->pos.x;
          *(_DWORD *)&a4[4] = v34->pos.y;
          v36 = this->left.x;
          v37 = v58;
          p_endpoints = &graphTree->endpoints;
          v39 = (float)(this->down.x * (float)*(__int64 *)a4);
          v40 = (float)(this->down.y * (float)*(__int64 *)a4);
          v41 = (float)(this->down.z * (float)*(__int64 *)a4);
          v55 = *(_QWORD *)a4;
          v42 = (float)(this->left.y * (float)*(__int64 *)&a4[4]);
          v56 = *(_QWORD *)&a4[4];
          v44 = (float)((float)((float)v36 * (float)*(__int64 *)&a4[4]) + (float)v39);
          v43 = (float)(this->left.z * (float)*(__int64 *)&a4[4]);
          v58[0].x = v44;
          v58[0].y = (float)v42 + (float)v40;
          v58[0].z = (float)v43 + (float)v41;
LABEL_25:
          idList<idAngles,5>::Append(this: p_endpoints, obj: v37);
          goto LABEL_26;
        }
        if ( v35->next->next != nullptr )
        {
          v45 = this->down.x;
          v46 = this->down.y;
          *(_DWORD *)&a4[4] = v34->pos.y;
          v47 = this->down.z;
          *(_DWORD *)&a4[8] = v34->pos.x;
          v48 = this->left.x;
          v53 = *(_QWORD *)a4;
          v49 = this->left.y;
          v54 = *(_QWORD *)&a4[4];
          v37 = &v57;
          p_endpoints = &graphTree->intersections;
          v51 = (float)((float)((float)v48 * (float)*(__int64 *)&a4[4]) + (float)((float)v45 * (float)*(__int64 *)a4));
          v50 = (float)(this->left.z * (float)*(__int64 *)&a4[4]);
          v57.x = v51;
          v57.y = (float)((float)v49 * (float)*(__int64 *)&a4[4]) + (float)((float)v46 * (float)*(__int64 *)a4);
          v57.z = (float)v50 + (float)((float)v47 * (float)*(__int64 *)a4);
          goto LABEL_25;
        }
      }
LABEL_26:
      ++v32;
      ++v33;
    }
    while ( v32 < this->nodes.num );
  }
}


// ========================================================================
// ?AddInvalidNode@idCutterGraphManager@@AAAXPAUNode_t@1@@Z
// EA  : 0x827BC718
// RVA : 0x007BC718
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::AddInvalidNode(
        idCutterGraphManager *this,
        idCutterGraphManager::Node_t *node,
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
        idCutterGraphManager::Node_t *a14)
{
  idList<enum encounterGroupRole_t,5> *p_invalidNodes; // r3
  int v15; // r10
  int num; // r9
  encounterGroupRole_t *list; // r8
  int v18; // r11

  p_invalidNodes = (idList<enum encounterGroupRole_t,5> *)&this->invalidNodes;
  a14 = node;
  v15 = 0;
  num = p_invalidNodes->num;
  if ( num <= 0 )
    goto LABEL_8;
  list = p_invalidNodes->list;
  v18 = 0;
  while ( (idCutterGraphManager::Node_t *)list[v18] != node )
  {
    ++v15;
    ++v18;
    if ( v15 >= num )
      goto LABEL_8;
  }
  if ( v15 < 0 || &list[v15] == nullptr )
LABEL_8:
    idList<idAnimWebBlendTree *,5>::Append(this: p_invalidNodes, obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?PreAllocatePools@idCutterGraphManager@@AAAXXZ
// EA  : 0x827BC798
// RVA : 0x007BC798
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::PreAllocatePools(idCutterGraphManager *this)
{
  int v2; // r30
  int *v3; // r31
  int v4; // r9
  int v5; // r30
  encounterGroupRole_t v6; // r31
  int v7; // r11
  int v8; // r30
  unsigned int *v9; // r31
  unsigned int v10; // r9
  int *v11; // [sp+50h] [-40h] BYREF
  encounterGroupRole_t v12[15]; // [sp+54h] [-3Ch] BYREF

  if ( this->linksPool.num == 0 )
  {
    v12[0] = (encounterGroupRole_t)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(1376) : TAG_GAME",
                                     size: 0x5000u,
                                     tag: TAG_GAME,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
    v2 = 1024;
    v3 = (int *)(v12[0] + 12);
    do
    {
      v4 = *v3 & 0x7FFFFFFF;
      v11 = v3 - 3;
      *v3 = v4;
      v3[1] = 0;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->linksPool,
        obj: (const encounterGroupRole_t *)&v11);
      --v2;
      v3 += 5;
    }
    while ( v2 != 0 );
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->linksPoolBlock, obj: v12);
  }
  if ( this->nodesPool.num == 0 )
  {
    v11 = (int *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(1392) : TAG_GAME",
                   size: 0x5000u,
                   tag: TAG_GAME,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v5 = 1024;
    v6 = (encounterGroupRole_t)v11;
    do
    {
      v7 = *(_DWORD *)(v6 + 16);
      v12[0] = v6;
      *(_DWORD *)(v6 + 16) = v7 & 0xFFFFFFFE;
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->nodesPool, obj: v12);
      --v5;
      v6 += 20;
    }
    while ( v5 != 0 );
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->nodesPoolBlock,
      obj: (const encounterGroupRole_t *)&v11);
  }
  if ( this->edgesPool.num == 0 )
  {
    v11 = (int *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(1407) : TAG_GAME",
                   size: 0x6000u,
                   tag: TAG_GAME,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v8 = 1024;
    v9 = (unsigned int *)(v11 + 5);
    do
    {
      v10 = *v9 & 0xBFFFFFFF;
      v12[0] = (encounterGroupRole_t)(v9 - 5);
      *v9 = v10;
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->edgesPool, obj: v12);
      --v8;
      v9 += 6;
    }
    while ( v8 != 0 );
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->edgesPoolBlock,
      obj: (const encounterGroupRole_t *)&v11);
  }
}


// ========================================================================
// ?AllocateLink@idCutterGraphManager@@AAAPAULink_t@1@XZ
// EA  : 0x827BC928
// RVA : 0x007BC928
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Link_t *__fastcall idCutterGraphManager::AllocateLink(idCutterGraphManager *this)
{
  int num; // r10
  idCutterGraphManager::Link_t *result; // r3
  int v4; // r10
  unsigned int v5; // r9

  if ( this->linksPool.num == 0 )
    idCutterGraphManager::PreAllocatePools(this);
  num = this->linksPool.num;
  result = *this->linksPool.list;
  if ( num > 0 )
  {
    v4 = num - 1;
    this->linksPool.num = v4;
    if ( v4 != 0 )
      *this->linksPool.list = this->linksPool.list[v4];
  }
  v5 = *((_DWORD *)result + 3) | 0x80000000;
  result->next = nullptr;
  result->edge = nullptr;
  result->node = nullptr;
  *((_DWORD *)result + 3) = v5;
  return result;
}


// ========================================================================
// ?AllocateNode@idCutterGraphManager@@AAAPAUNode_t@1@XZ
// EA  : 0x827BC9B0
// RVA : 0x007BC9B0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Node_t *__fastcall idCutterGraphManager::AllocateNode(idCutterGraphManager *this)
{
  int num; // r10
  idCutterGraphManager::Node_t *result; // r3
  int v4; // r10
  unsigned int v5; // r8

  if ( this->nodesPool.num == 0 )
    idCutterGraphManager::PreAllocatePools(this);
  num = this->nodesPool.num;
  result = *this->nodesPool.list;
  if ( num > 0 )
  {
    v4 = num - 1;
    this->nodesPool.num = v4;
    if ( v4 != 0 )
      *this->nodesPool.list = this->nodesPool.list[v4];
  }
  v5 = *((_DWORD *)result + 4) | 0xFFFFFFFE;
  result->next = nullptr;
  *((_DWORD *)result + 4) = v5;
  result->link = nullptr;
  result->pos.x = 0;
  result->pos.y = 0;
  *((_DWORD *)result + 4) |= 1u;
  return result;
}


// ========================================================================
// ?AllocateEdge@idCutterGraphManager@@AAAPAUEdge_t@1@XZ
// EA  : 0x827BCA50
// RVA : 0x007BCA50
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Edge_t *__fastcall idCutterGraphManager::AllocateEdge(idCutterGraphManager *this)
{
  int num; // r10
  idCutterGraphManager::Edge_t *result; // r3
  int v4; // r10
  int v5; // r10

  if ( this->edgesPool.num == 0 )
    idCutterGraphManager::PreAllocatePools(this);
  num = this->edgesPool.num;
  result = *this->edgesPool.list;
  if ( num > 0 )
  {
    v4 = num - 1;
    this->edgesPool.num = v4;
    if ( v4 != 0 )
      *this->edgesPool.list = this->edgesPool.list[v4];
  }
  v5 = *((_DWORD *)result + 5) & 0x3FFFFFFF | 0x40000000;
  result->next = nullptr;
  result->node1 = nullptr;
  result->node2 = nullptr;
  result->contour = nullptr;
  result->contourEdge = nullptr;
  *((_DWORD *)result + 5) = v5;
  return result;
}


// ========================================================================
// ?FreeLink@idCutterGraphManager@@AAAXPAULink_t@1@@Z
// EA  : 0x827BCAE8
// RVA : 0x007BCAE8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::FreeLink(idCutterGraphManager *this, idCutterGraphManager::Link_t *link)
{
  idCutterGraphManager::Link_t *v2; // r30
  idList<idSpawnArea::GeneratedPosition *,5> *p_linksPool; // r31
  int v4; // r11
  idCutterGraphManager::Link_t *next; // r29
  int granularity; // r4
  int size; // r11
  bool v8; // cr58
  signed int v9; // r10
  int v10; // r4
  int v11; // r11
  int num; // r11

  v2 = link;
  if ( link != nullptr )
  {
    p_linksPool = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->linksPool;
    do
    {
      v4 = *((_DWORD *)v2 + 3);
      v2->invalid = 0;
      next = v2->next;
      *((_DWORD *)v2 + 3) = v4 & 0x7FFFFFFF;
      if ( p_linksPool->list != nullptr )
        goto LABEL_7;
      granularity = p_linksPool->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_linksPool, newsize: granularity) != 0 )
      {
LABEL_7:
        size = p_linksPool->size;
        if ( p_linksPool->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v8 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_linksPool, newsize: size + 1) == 0;
        }
        else
        {
          v9 = p_linksPool->granularity;
          if ( p_linksPool->granularity != 0 )
          {
            v11 = size + v9;
            __twllei(v9, 0);
            __twlgei(v9 & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
            v8 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_linksPool, newsize: v11 - v11 % v9) == 0;
          }
          else
          {
            v10 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v10 == 0 )
                v10 = 1;
              v8 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_linksPool, newsize: v10) == 0;
            }
            else
            {
              v8 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_linksPool, newsize: 0x7FFFFFFF) == 0;
            }
          }
        }
        if ( !v8 )
        {
LABEL_18:
          num = p_linksPool->num;
          if ( num < p_linksPool->size )
          {
            p_linksPool->list[num] = (idSpawnArea::GeneratedPosition *)v2;
            ++p_linksPool->num;
          }
        }
      }
      v2 = next;
    }
    while ( next != nullptr );
  }
}


// ========================================================================
// ?FreeNode@idCutterGraphManager@@AAAXPAUNode_t@1@@Z
// EA  : 0x827BCC58
// RVA : 0x007BCC58
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::FreeNode(
        idCutterGraphManager *this,
        idCutterGraphManager::Node_t *node,
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
        idCutterGraphManager::Node_t *a14)
{
  idCutterGraphManager::Node_t *v15; // r31
  idList<enum encounterGroupRole_t,5> *p_nodesPool; // r28
  idCutterGraphManager::Node_t *next; // r30

  a14 = node;
  v15 = node;
  if ( node != nullptr )
  {
    p_nodesPool = (idList<enum encounterGroupRole_t,5> *)&this->nodesPool;
    do
    {
      next = v15->next;
      if ( v15->link != nullptr )
      {
        idCutterGraphManager::FreeLink(this, link: v15->link);
        v15->link = nullptr;
      }
      *((_DWORD *)v15 + 4) &= ~1u;
      idList<idAnimWebBlendTree *,5>::Append(this: p_nodesPool, obj: (const encounterGroupRole_t *)&a14);
      v15 = next;
      a14 = next;
    }
    while ( next != nullptr );
  }
}


// ========================================================================
// ?FreeEdge@idCutterGraphManager@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827BCCD0
// RVA : 0x007BCCD0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::FreeEdge(idCutterGraphManager *this, idCutterGraphManager::Edge_t *edge)
{
  idCutterGraphManager::Edge_t *v2; // r30
  idList<idSpawnArea::GeneratedPosition *,5> *p_edgesPool; // r31
  idCutterGraphManager::Edge_t *next; // r29
  int granularity; // r4
  int size; // r11
  bool v7; // cr58
  signed int v8; // r10
  int v9; // r4
  int v10; // r11
  int num; // r11

  v2 = edge;
  if ( edge != nullptr )
  {
    p_edgesPool = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->edgesPool;
    do
    {
      next = v2->next;
      *((_DWORD *)v2 + 5) &= ~0x40000000u;
      if ( p_edgesPool->list != nullptr )
        goto LABEL_7;
      granularity = p_edgesPool->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edgesPool, newsize: granularity) != 0 )
      {
LABEL_7:
        size = p_edgesPool->size;
        if ( p_edgesPool->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v7 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edgesPool, newsize: size + 1) == 0;
        }
        else
        {
          v8 = p_edgesPool->granularity;
          if ( p_edgesPool->granularity != 0 )
          {
            v10 = size + v8;
            __twllei(v8, 0);
            __twlgei(v8 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
            v7 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edgesPool, newsize: v10 - v10 % v8) == 0;
          }
          else
          {
            v9 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v9 == 0 )
                v9 = 1;
              v7 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edgesPool, newsize: v9) == 0;
            }
            else
            {
              v7 = (unsigned __int8)idList<idNavSpline *,5>::Resize(this: p_edgesPool, newsize: 0x7FFFFFFF) == 0;
            }
          }
        }
        if ( !v7 )
        {
LABEL_18:
          num = p_edgesPool->num;
          if ( num < p_edgesPool->size )
          {
            p_edgesPool->list[num] = (idSpawnArea::GeneratedPosition *)v2;
            ++p_edgesPool->num;
          }
        }
      }
      v2 = next;
    }
    while ( next != nullptr );
  }
}


// ========================================================================
// ?ProcessLinks@idCutterGraphManager@@AAAXPAVContour@@PAUNode_t@1@@Z
// EA  : 0x827BCE38
// RVA : 0x007BCE38
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCutterGraphManager::ProcessLinks(
        idCutterGraphManager *this,
        Contour *contour,
        idCutterGraphManager::Node_t *node,
        _BYTE a4[12])
{
  int v7; // r9
  idCutterGraphManager::Link_t *link; // r10
  idCutterGraphManager::Link_t *v9; // r30
  double v10; // fp26
  double v11; // fp27
  double v12; // fp31
  double v13; // fp30
  ContourEdge_t *edges; // r31
  __int64 v15; // r5 OVERLAPPED
  double v16; // fp10
  double v17; // fp9
  ContourEdge_t *v18; // r10
  int v19; // r9
  ContourNode_t *v20; // r11
  ContourNode_t *next; // r11
  double v22; // fp11
  double i; // fp12
  int v24; // r10
  int v25; // [sp+8h] [-108h]
  int v26; // [sp+Ch] [-104h]
  int v27; // [sp+10h] [-100h]
  int v28; // [sp+14h] [-FCh]
  int v29; // [sp+18h] [-F8h]
  idCutterGraphManager::Node_t *v30; // [sp+1Ch] [-F4h]
  idVec2 v31; // [sp+50h] [-C0h] BYREF
  idVec2i v32[3]; // [sp+58h] [-B8h] BYREF
  int y; // [sp+74h] [-9Ch]
  __int64 v35; // [sp+78h] [-98h]
  __int64 v36; // [sp+80h] [-90h]
  __int64 v37; // [sp+88h] [-88h]
  __int64 v38; // [sp+90h] [-80h]

  v7 = 0;
  link = node->link;
  if ( link != nullptr )
  {
    do
    {
      link = link->next;
      ++v7;
    }
    while ( link != nullptr );
    if ( v7 >= 3 )
    {
      v9 = node->link;
      *(idVec2i *)&a4[4] = node->pos;
      v10 = (float)*(__int64 *)&a4[4];
      v32[0] = *(idVec2i *)a4;
      v11 = (float)*(__int64 *)a4;
      v12 = *(float *)&a4[4];
      v13 = *(float *)a4;
      do
      {
        *(_DWORD *)&a4[8] = v9->node->pos.x;
        *(_DWORD *)&a4[4] = v9->node->pos.y;
        v32[1] = *(idVec2i *)a4;
        v32[2] = *(idVec2i *)&a4[4];
        v31.x = (float)((float)((float)*(__int64 *)&a4[4] - (float)v11) * (float)0.5) + (float)v11;
        v31.y = (float)((float)((float)*(__int64 *)a4 - (float)v10) * (float)0.5) + (float)v10;
        *(_DWORD *)a4 = idBounds2D::ContainsPoint(this: &contour->bound, point: &v31);
        if ( *(_DWORD *)a4 != 0 )
        {
          edges = contour->edges;
          y = (int)v31.y;
          v32[0].x = (int)v31.x;
          v32[0].y = y;
          if ( idCutterGraphManager::PointInPolygon(this, pos: v32, edge: edges) )
          {
            v18 = edges;
            v19 = 1;
            if ( edges != nullptr )
            {
              while ( 1 )
              {
                v20 = v18->node;
                *(_DWORD *)&a4[8] = v20->pos.x;
                *(_DWORD *)&a4[4] = v20->pos.y;
                __SET_PAIR__(*(unsigned int *)a4, v15, *(_QWORD *)&v20->pos);
                next = v20->next;
                v35 = *(_QWORD *)&a4[8];
                v36 = v15;
                v22 = (float)*(__int64 *)&a4[8];
                for ( i = (float)v15; next != nullptr; v12 = (float)v15 )
                {
                  *(_DWORD *)&a4[8] = next->pos.x;
                  *(_DWORD *)&a4[4] = next->pos.y;
                  __SET_PAIR__(*(unsigned int *)a4, v15, *(_QWORD *)&next->pos);
                  next = next->next;
                  v37 = *(_QWORD *)&a4[8];
                  v38 = v15;
                  v13 = (float)*(__int64 *)&a4[8];
                }
                if ( (i <= v16 && v12 >= v16 || v12 <= v16 && i >= v16)
                  && (v22 <= v17 && v13 >= v17 || v13 <= v17 && v22 >= v17)
                  && (float)((float)((float)((float)v13 - (float)v22) * (float)((float)v16 - (float)i))
                           - (float)((float)((float)v12 - (float)i) * (float)((float)v17 - (float)v22))) == 0.0 )
                {
                  break;
                }
                v18 = v18->next;
                if ( v18 == nullptr )
                  goto LABEL_22;
              }
              v19 = 0;
              v9->invalid = 2;
            }
LABEL_22:
            if ( (_BYTE)v19 != 0 )
            {
              v24 = v9->invalid | 1;
              v9->invalid = v24;
              idCutterGraphManager::AddInvalidNode(
                this,
                node,
                a3: v15,
                a4: *(int *)a4,
                a5: *(int *)&a4[4],
                a6: *(int *)&a4[8],
                a7: v19,
                a8: v24,
                a9: v25,
                a10: v26,
                a11: v27,
                a12: v28,
                a13: v29,
                a14: v30);
            }
          }
        }
        v9 = v9->next;
      }
      while ( v9 != nullptr );
    }
  }
}


// ========================================================================
// ?ReleaseGraph@idCutterGraphManager@@QAAXH@Z
// EA  : 0x827BD0E0
// RVA : 0x007BD0E0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::ReleaseGraph(idCutterGraphManager *this, int id)
{
  idCutterGraphManager::Graph *graph; // r31

  graph = this->graph;
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&graph->nodes,
    newsize: graph->nodes.num);
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&graph->edges,
    newsize: graph->edges.num);
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&graph->links,
    newsize: graph->links.num);
  graph->lastNode = nullptr;
  this->graph = nullptr;
}


// ========================================================================
// ?BuildGraphTree@idCutterGraphManager@@QAAXHAAUgraphTree_t@@@Z
// EA  : 0x827BD148
// RVA : 0x007BD148
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::BuildGraphTree(
        idCutterGraphManager *this,
        int id,
        graphTree_t *graphTree,
        _BYTE *a4)
{
  idCutterGraphManager::Graph *graph; // r3

  graph = this->graphs.list[id].graph;
  if ( graph != nullptr )
    idCutterGraphManager::Graph::BuildGraphTree(this: graph, graphTree, a3: (int)graphTree, a4);
}


// ========================================================================
// ?GenerateNode@idCutterGraphManager@@AAAPAUNode_t@1@ABVidVec3@@ABVidVec2i@@H@Z
// EA  : 0x827BD168
// RVA : 0x007BD168
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager::Node_t *__fastcall idCutterGraphManager::GenerateNode(
        idCutterGraphManager *this,
        const idVec3 *pos3d,
        const idVec2i *pos,
        int threshold)
{
  idCutterGraphManager::Graph *graph; // r31
  int NodeIndex; // r3
  idCutterGraphManager::Node_t *result; // r3
  idVec2i *Node; // r28
  idCutterGraphManager::Graph *v10; // r31
  int v11; // r3
  int x; // r9
  idVec2i *v13; // [sp+50h] [-30h] BYREF

  graph = this->graph;
  NodeIndex = idCutterGraphManager::Graph::FindNodeIndex(this: graph, pos, threshold);
  if ( NodeIndex >= 0 )
    result = graph->nodes.list[NodeIndex].data;
  else
    result = nullptr;
  if ( result == nullptr )
  {
    Node = (idVec2i *)idCutterGraphManager::AllocateNode(this);
    Node[1] = *pos;
    v10 = this->graph;
    v11 = idCutterGraphManager::IDHeap::Alloc(this: &v10->idheap);
    x = Node[2].x;
    v13 = Node;
    Node[2].x = (2 * v11) | x & 1;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&v10->nodes,
      obj: (const encounterGroupRole_t *)&v13);
    return (idCutterGraphManager::Node_t *)Node;
  }
  return result;
}


// ========================================================================
// ?AddLink@idCutterGraphManager@@AAAXPAUNode_t@1@0PAUEdge_t@1@@Z
// EA  : 0x827BD208
// RVA : 0x007BD208
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::AddLink(
        idCutterGraphManager *this,
        idCutterGraphManager::Node_t *srcNode,
        idCutterGraphManager::Node_t *dstNode,
        idCutterGraphManager::Edge_t *edge)
{
  idCutterGraphManager::Link_t *Link; // r27
  idCutterGraphManager::Link_t *v9; // r3
  encounterGroupRole_t v10; // r26
  encounterGroupRole_t v11[16]; // [sp+50h] [-40h] BYREF

  Link = idCutterGraphManager::AllocateLink(this);
  Link->edge = edge;
  Link->node = dstNode;
  Link->next = srcNode->link;
  srcNode->link = Link;
  v9 = idCutterGraphManager::AllocateLink(this);
  v9->edge = edge;
  v9->node = srcNode;
  v10 = (encounterGroupRole_t)v9;
  v9->next = dstNode->link;
  dstNode->link = v9;
  v11[0] = (encounterGroupRole_t)Link;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->graph->links, obj: v11);
  v11[0] = v10;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->graph->links, obj: v11);
}


// ========================================================================
// ?RemoveLink@idCutterGraphManager@@AAAXPAUNode_t@1@0@Z
// EA  : 0x827BD290
// RVA : 0x007BD290
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::RemoveLink(
        idCutterGraphManager *this,
        idCutterGraphManager::Node_t *srcNode,
        idCutterGraphManager::Node_t *dstNode)
{
  idCutterGraphManager::Link_t *link; // r4
  idCutterGraphManager::Link_t *v7; // r11
  idCutterGraphManager::Link_t *v8; // r4
  idCutterGraphManager::Link_t *v9; // r4
  idCutterGraphManager::Link_t *v10; // r11
  idCutterGraphManager::Link_t *v11; // r4

  link = srcNode->link;
  v7 = nullptr;
  if ( link != nullptr )
  {
    while ( link->node != dstNode )
    {
      v7 = link;
      link = link->next;
      if ( link == nullptr )
        goto LABEL_9;
    }
    if ( v7 != nullptr )
      v7->next = link->next;
    else
      srcNode->link = link->next;
    idCutterGraphManager::Graph::RemoveLink(this: this->graph, link);
    v8->next = nullptr;
    idCutterGraphManager::FreeLink(this, link: v8);
  }
LABEL_9:
  v9 = dstNode->link;
  v10 = nullptr;
  if ( v9 != nullptr )
  {
    while ( v9->node != srcNode )
    {
      v10 = v9;
      v9 = v9->next;
      if ( v9 == nullptr )
        return;
    }
    if ( v10 != nullptr )
      v10->next = v9->next;
    else
      dstNode->link = v9->next;
    idCutterGraphManager::Graph::RemoveLink(this: this->graph, link: v9);
    v11->next = nullptr;
    idCutterGraphManager::FreeLink(this, link: v11);
  }
}


// ========================================================================
// ?Connect@idCutterGraphManager@@AAAXPAUNode_t@1@0PAVContour@@@Z
// EA  : 0x827BD378
// RVA : 0x007BD378
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Connect(
        idCutterGraphManager *this,
        idCutterGraphManager::Node_t *srcNode,
        idCutterGraphManager::Node_t *dstNode,
        Contour *c)
{
  idCutterGraphManager::Edge_t *Edge; // r3
  idCutterGraphManager::Edge_t *v9; // r26
  idCutterGraphManager::Edge_t *v10; // [sp+50h] [-40h] BYREF

  Edge = idCutterGraphManager::AllocateEdge(this);
  Edge->node1 = srcNode;
  Edge->node2 = dstNode;
  v9 = Edge;
  Edge->contour = nullptr;
  Edge->contourEdge = nullptr;
  v10 = Edge;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->graph->edges,
    obj: (const encounterGroupRole_t *)&v10);
  v9->contour = c;
  v9->contourEdge = nullptr;
  idCutterGraphManager::AddLink(this, srcNode, dstNode, edge: v9);
}


// ========================================================================
// ?Disconnect@idCutterGraphManager@@AAAXPAUEdge_t@1@@Z
// EA  : 0x827BD3E8
// RVA : 0x007BD3E8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Disconnect(idCutterGraphManager *this, idCutterGraphManager::Edge_t *edge)
{
  idCutterGraphManager::Node_t *node1; // r9
  idCutterGraphManager::Link_t *link; // r11
  idCutterGraphManager::Node_t *node2; // r10
  idCutterGraphManager::Link_t *v7; // r11
  idCutterGraphManager::Edge_t *v8; // r4

  node1 = edge->node1;
  link = node1->link;
  if ( link != nullptr )
  {
    node2 = edge->node2;
    while ( link->node != node2 )
    {
      link = link->next;
      if ( link == nullptr )
        return;
    }
    v7 = node2->link;
    if ( v7 != nullptr )
    {
      while ( v7->node != node1 )
      {
        v7 = v7->next;
        if ( v7 == nullptr )
          return;
      }
      idCutterGraphManager::Graph::RemoveEdge(this: this->graph, edge);
      edge->next = nullptr;
      idCutterGraphManager::FreeEdge(this, edge: v8);
      idCutterGraphManager::RemoveLink(this, srcNode: edge->node1, dstNode: edge->node2);
    }
  }
}


// ========================================================================
// ?BuildEdge@idCutterGraphManager@@QAA_NABVidVec2i@@@Z
// EA  : 0x827BD4A0
// RVA : 0x007BD4A0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

BOOL __fastcall idCutterGraphManager::BuildEdge(idCutterGraphManager *this, idVec2i *dst)
{
  idCutterGraphManager::Graph *graph; // r11
  idCutterGraphManager::Node_t *lastNode; // r10
  int v6; // r5
  int v7; // r4
  idCutterGraphManager::Graph *v8; // r30
  __int64 v9; // r8
  int v10; // r6
  Contour *contoursInner; // r31
  idCutterGraphManager::Graph *Position3D; // r3
  const idVec2i *v13; // r5
  int NodeIndex; // r3
  idCutterGraphManager::Node_t *v16; // r27
  int v17; // r28
  idCutterGraphManager::Node_t *data; // r31
  idCutterGraphManager::Link_t *link; // r11
  char v20; // r11
  const idVec2i *p_pos; // r5
  idCutterGraphManager::Edge_t *SplitEdge; // r3
  idCutterGraphManager::Edge_t *v23; // r26
  int ClosestNode; // r3
  idCutterGraphManager::Node_t *v25; // r10
  idCutterGraphManager::Link_t *v26; // r11
  char v27; // r11
  bool v28; // r3
  idVec2i *v29; // r7
  int y; // r10
  int v31; // r4
  Contour *v32; // r30
  idCutterGraphManager::Link_t *v33; // r11
  int v34; // r6
  int x; // r11
  bool v36; // r24
  int v37; // r10
  idCutterGraphManager::Node_t *v38; // r9
  int v39; // r3
  Contour *v40; // r31
  bool v41; // r3
  idCutterGraphManager::Node_t *Node; // r31
  idCutterGraphManager::Node_t *node1; // r30
  idCutterGraphManager::Node_t *node2; // r29
  idCutterGraphManager::Link_t *v45; // r10
  idCutterGraphManager::Node_t *v46; // r11
  char v47; // r11
  idCutterGraphManager::Link_t *v48; // r11
  idCutterGraphManager::Link_t *v49; // r11
  ContourEdge_t *contourEdge; // r4
  idCutterGraphManager::Node_t *v51; // r11
  char v52; // r11
  idCutterGraphManager::Link_t *v53; // r10
  idCutterGraphManager::Node_t *v54; // r11
  char v55; // r11
  idCutterGraphManager::Link_t *v56; // r11
  idCutterGraphManager::Link_t *v57; // r11
  idCutterGraphManager::Link_t *v58; // r11
  ContourEdge_t *v59; // r4
  idCutterGraphManager::Link_t *v60; // r11
  idVec2i v61; // [sp+50h] [-70h] BYREF
  idVec2i v62[2]; // [sp+58h] [-68h] BYREF
  idVec2i v63; // [sp+68h] [-58h] BYREF

  graph = this->graph;
  lastNode = graph->lastNode;
  if ( graph->lastNode != nullptr )
  {
    v6 = lastNode->pos.x - dst->x;
    v7 = lastNode->pos.y - dst->y;
    if ( v7 * v7 + v6 * v6 > 225 )
      graph->lastNode = nullptr;
  }
  v8 = this->graph;
  if ( v8->lastNode == nullptr )
  {
    if ( idCutterGraphManager::Graph::FindNodeIndex(this: v8, pos: dst, threshold: 6) < 0
      && (contoursInner = v8->contoursInner) != nullptr )
    {
      while ( !Contour::ContainsPoint(this: contoursInner, pos: dst) )
      {
        contoursInner = contoursInner->next;
        if ( contoursInner == nullptr )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      this->graph->prevNode = this->graph->lastNode;
      Position3D = idCutterGraphManager::Graph::GetPosition3D(
                     this: (idCutterGraphManager::Graph *)v62,
                     result: (idVec3 *)this->graph,
                     point2d: dst,
                     a4: v10,
                     a5: v9);
      this->graph->lastNode = idCutterGraphManager::GenerateNode(
                                this,
                                pos3d: (const idVec3 *)Position3D,
                                pos: v13,
                                threshold: 6);
    }
    return false;
  }
  NodeIndex = idCutterGraphManager::Graph::FindNodeIndex(this: v8, pos: dst, threshold: 6);
  v16 = v8->lastNode;
  v17 = NodeIndex;
  if ( NodeIndex >= 0 )
    data = v8->nodes.list[NodeIndex].data;
  else
    data = nullptr;
  if ( v16 == data )
    return false;
  if ( data != nullptr )
  {
    link = v16->link;
    if ( link != nullptr )
    {
      while ( link->node != data )
      {
        link = link->next;
        if ( link == nullptr )
          goto LABEL_19;
      }
      v20 = 1;
    }
    else
    {
LABEL_19:
      v20 = 0;
    }
    if ( v20 != 0 )
    {
      this->graph->prevNode = v16;
      this->graph->lastNode = data;
      return false;
    }
    p_pos = &data->pos;
  }
  else
  {
    p_pos = dst;
  }
  SplitEdge = idCutterGraphManager::Graph::FindSplitEdge(this: v8, srcNode: v8->lastNode, dst: p_pos, pos: &v61);
  v23 = SplitEdge;
  if ( SplitEdge == nullptr )
  {
    v28 = false;
    if ( data != nullptr )
    {
      v29 = &v61;
      y = v16->pos.y;
      v31 = data->pos.y - y;
      v61.x = v16->pos.x + (data->pos.x - v16->pos.x) / 2;
      v61.y = v31 / 2 + y;
    }
    else
    {
      v29 = dst;
    }
    v62[0] = *v29;
    v32 = v8->contoursInner;
    do
    {
      if ( v32 == nullptr )
        break;
      v28 = Contour::ContainsPoint(this: v32, pos: v62);
      v32 = v32->next;
    }
    while ( !v28 );
    if ( !v28 )
    {
      if ( data != nullptr )
      {
        v33 = v16->link;
        if ( v33 != nullptr )
        {
          while ( v33->node != data )
          {
            v33 = v33->next;
            if ( v33 == nullptr )
              goto LABEL_47;
          }
        }
        else
        {
LABEL_47:
          idCutterGraphManager::Connect(this, srcNode: v16, dstNode: data, c: nullptr);
        }
      }
      else
      {
        v34 = v16->pos.y - dst->y;
        if ( v34 * v34 + (v16->pos.x - dst->x) * (v16->pos.x - dst->x) > 36 )
        {
          data = idCutterGraphManager::AllocateNode(this);
          data->pos = *dst;
          idCutterGraphManager::Connect(this, srcNode: v16, dstNode: data, c: nullptr);
          idCutterGraphManager::Graph::AddNode(this: this->graph, node: data);
        }
      }
      this->graph->prevNode = this->graph->lastNode;
      this->graph->lastNode = data;
    }
    return false;
  }
  if ( data == nullptr )
  {
    ClosestNode = idCutterGraphManager::Graph::FindClosestNode(this: v8, edge: SplitEdge, hitPos: &v61, threshold: 6);
    v17 = ClosestNode;
    if ( ClosestNode < 0 )
    {
LABEL_53:
      v17 = idCutterGraphManager::Graph::FindNodeIndex(this: v8, pos: &v61, threshold: 6);
      goto LABEL_54;
    }
    v25 = v8->nodes.list[ClosestNode].data;
    if ( v25 != nullptr )
    {
      v26 = v16->link;
      if ( v26 != nullptr )
      {
        while ( v26->node != v25 )
        {
          v26 = v26->next;
          if ( v26 == nullptr )
            goto LABEL_32;
        }
        v27 = 1;
      }
      else
      {
LABEL_32:
        v27 = 0;
      }
      if ( v27 != 0 )
      {
        this->graph->prevNode = v16;
        this->graph->lastNode = v25;
        return false;
      }
    }
  }
  if ( v17 < 0 )
    goto LABEL_53;
LABEL_54:
  x = v16->pos.x;
  v36 = false;
  v37 = v16->pos.y;
  if ( v17 >= 0 )
  {
    v38 = v8->nodes.list[v17].data;
    v39 = v38->pos.y - v37;
    v62[0].x = v38->pos.x - x;
    v62[0].y = v39;
  }
  else
  {
    v62[0].x = v61.x - x;
    v62[0].y = v61.y - v37;
  }
  v63.x = v62[0].x / 2 + x;
  v63.y = v62[0].y / 2 + v37;
  v40 = v8->contoursInner;
  do
  {
    if ( v40 == nullptr )
      break;
    v41 = Contour::ContainsPoint(this: v40, pos: &v63);
    v40 = v40->next;
    v36 = v41;
  }
  while ( !v41 );
  if ( v17 >= 0 )
  {
    Node = this->graph->nodes.list[v17].data;
  }
  else
  {
    Node = idCutterGraphManager::AllocateNode(this);
    Node->pos = v61;
  }
  node1 = v23->node1;
  node2 = v23->node2;
  if ( Node == node1 || Node == node2 )
  {
    if ( !v36 )
    {
      v60 = v16->link;
      if ( v60 != nullptr )
      {
        while ( v60->node != Node )
        {
          v60 = v60->next;
          if ( v60 == nullptr )
            goto LABEL_117;
        }
        return false;
      }
LABEL_117:
      idCutterGraphManager::Connect(this, srcNode: v16, dstNode: Node, c: v23->contour);
    }
  }
  else
  {
    v45 = v16->link;
    if ( Node == v16 )
    {
      if ( v45 != nullptr )
      {
        while ( 1 )
        {
          v46 = v45->node;
          if ( v46 == node1 || v46 == node2 )
            break;
          v45 = v45->next;
          if ( v45 == nullptr )
            goto LABEL_70;
        }
        v47 = 0;
      }
      else
      {
LABEL_70:
        v47 = 1;
      }
      if ( v47 == 0 )
        return false;
      idCutterGraphManager::Disconnect(this, edge: v23);
      v48 = Node->link;
      if ( v48 != nullptr )
      {
        while ( v48->node != node1 )
        {
          v48 = v48->next;
          if ( v48 == nullptr )
            goto LABEL_75;
        }
      }
      else
      {
LABEL_75:
        idCutterGraphManager::Connect(this, srcNode: node1, dstNode: Node, c: v23->contour);
      }
      v49 = Node->link;
      if ( v49 != nullptr )
      {
        while ( v49->node != node2 )
        {
          v49 = v49->next;
          if ( v49 == nullptr )
            goto LABEL_79;
        }
      }
      else
      {
LABEL_79:
        idCutterGraphManager::Connect(this, srcNode: node2, dstNode: Node, c: v23->contour);
      }
      contourEdge = v23->contourEdge;
      if ( contourEdge != nullptr )
        ContourManager::SplitEdge(
          this: this->contourManager,
          edge: contourEdge,
          v0: &v23->node1->pos,
          v1: &v23->node2->pos,
          pos: &Node->pos);
    }
    else
    {
      if ( v45 != nullptr )
      {
        while ( 1 )
        {
          v51 = v45->node;
          if ( v51 == node1 || v51 == node2 )
            break;
          v45 = v45->next;
          if ( v45 == nullptr )
            goto LABEL_87;
        }
        v52 = 0;
      }
      else
      {
LABEL_87:
        v52 = 1;
      }
      if ( v52 == 0 )
        return false;
      v53 = Node->link;
      if ( v53 != nullptr )
      {
        while ( 1 )
        {
          v54 = v53->node;
          if ( v54 == node1 || v54 == node2 )
            break;
          v53 = v53->next;
          if ( v53 == nullptr )
            goto LABEL_93;
        }
        v55 = 0;
      }
      else
      {
LABEL_93:
        v55 = 1;
      }
      if ( v55 == 0 )
        return false;
      idCutterGraphManager::Disconnect(this, edge: v23);
      if ( !v36 )
      {
        v56 = v16->link;
        if ( v56 != nullptr )
        {
          while ( v56->node != Node )
          {
            v56 = v56->next;
            if ( v56 == nullptr )
              goto LABEL_99;
          }
        }
        else
        {
LABEL_99:
          idCutterGraphManager::Connect(this, srcNode: v16, dstNode: Node, c: v23->contour);
        }
      }
      v57 = node1->link;
      if ( v57 != nullptr )
      {
        while ( v57->node != Node )
        {
          v57 = v57->next;
          if ( v57 == nullptr )
            goto LABEL_103;
        }
      }
      else
      {
LABEL_103:
        idCutterGraphManager::Connect(this, srcNode: node1, dstNode: Node, c: v23->contour);
      }
      v58 = node2->link;
      if ( v58 != nullptr )
      {
        while ( v58->node != Node )
        {
          v58 = v58->next;
          if ( v58 == nullptr )
            goto LABEL_107;
        }
      }
      else
      {
LABEL_107:
        idCutterGraphManager::Connect(this, srcNode: node2, dstNode: Node, c: v23->contour);
      }
      v59 = v23->contourEdge;
      if ( v59 != nullptr )
        ContourManager::SplitEdge(
          this: this->contourManager,
          edge: v59,
          v0: &v23->node1->pos,
          v1: &v23->node2->pos,
          pos: &Node->pos);
      idCutterGraphManager::Graph::AddNode(this: this->graph, node: Node);
    }
  }
  this->graph->prevNode = this->graph->lastNode;
  this->graph->lastNode = Node;
  return (_cntlzw(v36) & 0x20) != 0;
}


// ========================================================================
// ?PathFind@Graph@idCutterGraphManager@@QAA_NAAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827BDC38
// RVA : 0x007BDC38
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::Graph::PathFind(
        idCutterGraphManager::Graph *this,
        idList<idSkinMapping,46> *points)
{
  int num; // ctr
  int v5; // r11
  idCutterGraphManager::Edge_t *data; // r10
  unsigned int bits; // r23
  unsigned __int8 *buffer; // r22
  unsigned int v9; // r11
  char v10; // r10
  unsigned __int8 *v11; // r11
  char v12; // r9
  idCutterGraphManager::Node_t *prevNode; // r29
  int size; // r28
  idCutterGraphManager::Node_t *lastNode; // r26
  idCutterGraphManager::Link_t *link; // r27
  encounterGroupRole_t *list; // r25
  unsigned int v18; // r8
  char v19; // r10
  unsigned __int8 *v20; // r11
  char v21; // r9
  int v23; // r17
  unsigned int v24; // r11
  char v25; // r10
  unsigned __int8 *v26; // r11
  char v27; // r9
  int v28; // r30
  char v29; // r3
  idCutterGraphManager::Edge_t *edge; // r11
  unsigned int v31; // r11
  char v32; // r10
  unsigned __int8 *v33; // r11
  char v34; // r9
  const idSkinMapping **v36; // r29
  int i; // r30
  idCutterGraphManager::Link_t *v38; // [sp+50h] [-C0h] BYREF
  idCutterGraphManager::Node_t *v39; // [sp+54h] [-BCh] BYREF
  idBitArray v40; // [sp+58h] [-B8h] BYREF
  idList<enum encounterGroupRole_t,5> v41; // [sp+70h] [-A0h] BYREF
  idList<enum encounterGroupRole_t,5> v42[9]; // [sp+80h] [-90h] BYREF

  memset(&v41, 0, 14);
  *(_WORD *)&v41.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
  if ( v41.size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v41, newsize: 1024);
  v40.buffer = nullptr;
  v40.bits = 0;
  v40.memTag = 9;
  v40.free = false;
  idBitArray::Alloc(this: &v40, numBits: 0x400u);
  memset(v42, 0, 14);
  v42[0].memTag = 5;
  v42[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v42);
  if ( v42[0].size < 1024 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v42, newsize: 1024);
  if ( this->edges.num > 0 )
  {
    num = this->edges.num;
    v5 = 0;
    do
    {
      data = this->edges.list[v5++].data;
      *((_DWORD *)data + 5) &= ~0x80000000;
      --num;
    }
    while ( num != 0 );
  }
  idList<idAnimWebBlendTree *,5>::Append(this: &v41, obj: (const encounterGroupRole_t *)this);
  idList<idAnimWebBlendTree *,5>::Append(this: v42, obj: (const encounterGroupRole_t *)&this->lastNode->link);
  bits = v40.bits;
  buffer = v40.buffer;
  v9 = *((int *)this->lastNode + 4) >> 1;
  if ( v9 >= v40.bits )
  {
    v11 = nullptr;
    v10 = 0;
    v12 = 0;
  }
  else
  {
    v10 = 1 << (v9 & 7);
    v11 = &v40.buffer[v9 >> 3];
    v12 = 1;
  }
  if ( v12 != 0 )
    *v11 |= v10;
  prevNode = this->prevNode;
  size = v41.num;
  lastNode = this->lastNode;
  link = prevNode->link;
  v38 = link;
  v39 = prevNode;
  if ( v41.num > 0 )
  {
    list = v41.list;
    while ( 1 )
    {
      if ( link != nullptr )
      {
        v18 = *((int *)prevNode + 4) >> 1;
        if ( v18 >= bits )
        {
          v20 = nullptr;
          v19 = 0;
          v21 = 0;
        }
        else
        {
          v19 = 1 << (v18 & 7);
          v20 = &buffer[v18 >> 3];
          v21 = 1;
        }
        if ( v21 == 0 || (unsigned __int8)(*v20 & v19) == 0 )
          goto LABEL_40;
        if ( v18 == *((int *)this->lastNode + 4) >> 1 )
          goto LABEL_67;
      }
      if ( size < 2 )
      {
        if ( (v42[0].listStatic == 0 || v42[0].listStatic == 2) && v42[0].list != nullptr )
          idMem::Free(this: &mem, ptr: v42[0].list, align: ALIGN_16);
        if ( buffer != nullptr && v40.free )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        if ( (v41.listStatic == 0 || v41.listStatic == 2) && list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        return 0;
      }
      v23 = v42[0].num;
      prevNode = (idCutterGraphManager::Node_t *)list[size - 1];
      lastNode = (idCutterGraphManager::Node_t *)list[size - 2];
      link = *(idCutterGraphManager::Link_t **)v42[0].list[v42[0].num - 1];
      v24 = *((int *)prevNode + 4) >> 1;
      v38 = link;
      v39 = prevNode;
      if ( v24 >= bits )
      {
        v26 = nullptr;
        v25 = 0;
        v27 = 0;
      }
      else
      {
        v25 = 1 << (v24 & 7);
        v26 = &buffer[v24 >> 3];
        v27 = 1;
      }
      if ( v27 != 0 )
        *v26 &= ~v25;
      v28 = size - 1;
      if ( size - 1 <= v41.size
        || (v29 = idList<idNavSpline *,5>::Resize(
                    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v41,
                    newsize: size - 1),
            list = v41.list,
            v29 != 0) )
      {
        size = v41.size;
        if ( v28 < v41.size )
          size = v28;
        v41.num = size;
      }
      else
      {
        size = v41.num;
      }
      if ( v23 - 1 <= v42[0].size
        || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                              this: (idList<idSpawnArea::GeneratedPosition *,5> *)v42,
                              newsize: v23 - 1) != 0 )
      {
        v42[0].num = v23 - 1;
        if ( v23 - 1 >= v42[0].size )
          v42[0].num = v42[0].size;
      }
LABEL_40:
      if ( link != nullptr )
      {
        while ( *((int *)link->edge + 5) < 0 || link->node == lastNode )
        {
          link = link->next;
          if ( link == nullptr )
            goto LABEL_51;
        }
        edge = link->edge;
        v38 = link;
        *((_DWORD *)edge + 5) |= 0x80000000;
        v31 = *((int *)prevNode + 4) >> 1;
        if ( v31 >= bits )
        {
          v33 = nullptr;
          v32 = 0;
          v34 = 0;
        }
        else
        {
          v32 = 1 << (v31 & 7);
          v33 = &buffer[v31 >> 3];
          v34 = 1;
        }
        if ( v34 != 0 )
          *v33 |= v32;
        idList<idAnimWebBlendTree *,5>::Append(this: &v41, obj: (const encounterGroupRole_t *)&v39);
        idList<idAnimWebBlendTree *,5>::Append(this: v42, obj: (const encounterGroupRole_t *)&v38);
        lastNode = prevNode;
        size = v41.num;
        list = v41.list;
        prevNode = link->node;
        link = prevNode->link;
        v39 = prevNode;
LABEL_51:
        v38 = link;
      }
      if ( size <= 0 )
        goto LABEL_67;
    }
  }
  list = v41.list;
LABEL_67:
  if ( size > 0 )
  {
    v36 = (const idSkinMapping **)(list - 1);
    for ( i = size; i != 0; --i )
      idList<cachedPageFile_t,5>::Append(this: points, obj: *++v36 + 1);
  }
  if ( (v42[0].listStatic == 0 || v42[0].listStatic == 2) && v42[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v42[0].list, align: ALIGN_16);
  if ( buffer != nullptr && v40.free )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  if ( (v41.listStatic == 0 || v41.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  return ((size >= 0) + ((unsigned int)size <= 2)) & 1;
}


// ========================================================================
// __unwind$232145
// EA  : 0x827BE1A0
// RVA : 0x007BE1A0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_232145()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$232146
// EA  : 0x827BE1C8
// RVA : 0x007BE1C8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_232146()
{
  int v0; // r12

  idBitArray::~idBitArray(this: (idBitArray *)(v0 - 272 + 88));
}


// ========================================================================
// __unwind$232147
// EA  : 0x827BE1F0
// RVA : 0x007BE1F0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_232147()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 128));
}


// ========================================================================
// ?IntersectContours@idCutterGraphManager@@QAAPAVContour@@PAV2@@Z
// EA  : 0x827BE220
// RVA : 0x007BE220
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

Contour *__fastcall idCutterGraphManager::IntersectContours(idCutterGraphManager *this, Contour *contour)
{
  Contour *v2; // r16
  idSkinMapping *list; // r24
  idCutterGraphManager *v4; // r29
  Contour *v5; // r28
  ContourEdge_t *edges; // r30
  int num; // r21
  Contour *contoursInner; // r15
  Contour *v9; // r18
  idBounds2D *p_bound; // r14
  Contour *next; // r17
  int v12; // r29
  bool v13; // r3
  int size; // r19
  ContourEdge_t *v15; // r30
  int v16; // r20
  int v17; // r22
  int v18; // r25
  int v19; // r11
  int v20; // r23
  idSkinMapping *v21; // r26
  bool v22; // r28
  int v23; // r3
  const idMaterial *from; // r4
  int v25; // r10
  int *p_to; // r7
  const idMaterial *v27; // r8
  char *v28; // r9
  char v29; // r11
  const idMaterial *v30; // r6
  char v31; // r11
  int v32; // r10
  int v33; // r11
  int v34; // r10
  int v35; // r9
  Contour *v37; // [sp+50h] [-10D0h]
  idList<idSkinMapping,46> v38; // [sp+60h] [-10C0h] BYREF
  idSkinMapping v39; // [sp+70h] [-10B0h]
  _BYTE v40[160]; // [sp+80h] [-10A0h] BYREF

  v2 = nullptr;
  list = (idSkinMapping *)v40;
  *(_QWORD *)&v38.num = 512;
  v4 = this;
  v5 = contour;
  v38.list = (idSkinMapping *)v40;
  *(_DWORD *)&v38.granularity = 66817;
  edges = contour->edges;
  if ( edges != nullptr )
  {
    do
    {
      idList<cachedPageFile_t,5>::Append(this: &v38, obj: (const idSkinMapping *)&edges->node->pos);
      edges = edges->next;
    }
    while ( edges != nullptr );
    list = v38.list;
  }
  num = v38.num;
  v37 = nullptr;
  contoursInner = v4->graph->contoursInner;
  v9 = contoursInner;
  if ( contoursInner != nullptr )
  {
    p_bound = &v5->bound;
    while ( 1 )
    {
      next = v9->next;
      LOBYTE(v12) = 0;
      if ( idBounds2D::IntersectBounds(this: p_bound, other: &v9->bound) )
        break;
LABEL_48:
      if ( (_BYTE)v12 != 0 )
      {
        v9->next = v37;
        v37 = v9;
        if ( v2 != nullptr )
          v2->next = next;
        else
          contoursInner = next;
      }
      else
      {
        v2 = v9;
      }
      v9 = next;
      if ( next == nullptr )
      {
        v4 = this;
        goto LABEL_55;
      }
      v5 = contour;
    }
    if ( num <= v38.size
      || (v13 = idList<idDeclMD6::includeDecl_t,5>::Resize(this: &v38, newsize: num), list = v38.list, v13) )
    {
      size = v38.size;
      if ( num < v38.size )
        size = num;
      v38.num = size;
    }
    else
    {
      size = v38.num;
    }
    v15 = v5->edges;
    if ( v15 != nullptr )
    {
      do
      {
        idList<cachedPageFile_t,5>::Append(this: &v38, obj: (const idSkinMapping *)&v15->node->pos);
        v15 = v15->next;
      }
      while ( v15 != nullptr );
      list = v38.list;
      size = v38.num;
    }
    v16 = 0;
    while ( 1 )
    {
      if ( v16 >= 2 )
        goto LABEL_48;
      v17 = num;
      if ( v16 != 0 )
        v17 = size;
      v18 = num;
      if ( v16 != 1 )
        v18 = size;
      v19 = (unsigned __int8)v12;
      v20 = v17 - num;
      if ( (_BYTE)v12 == 0 )
        break;
LABEL_47:
      ++v16;
      if ( v19 != 0 )
        goto LABEL_48;
    }
    v21 = &list[v17 - num];
    while ( 1 )
    {
      if ( v20 >= v17 )
        goto LABEL_47;
      v22 = false;
      v23 = v18 - num;
      v39 = *v21;
      if ( v19 == 0 )
        break;
LABEL_46:
      ++v20;
      ++v21;
      v12 = (unsigned __int8)(v22 | v19);
      v19 = v12;
      if ( v12 != 0 )
        goto LABEL_47;
    }
    from = v39.from;
    v25 = 8 * (v18 - 1);
    p_to = (int *)&list[v18 - num].to;
    while ( 1 )
    {
      if ( v23 >= v18 )
        goto LABEL_46;
      v27 = *(const idMaterial **)((char *)&list->from + v25);
      v28 = (char *)list + v25;
      if ( v27 != from || (v29 = 1, *((const idMaterial **)v28 + 1) != v39.to) )
        v29 = 0;
      if ( v29 != 0 )
        goto LABEL_44;
      v30 = (const idMaterial *)*(p_to - 1);
      if ( v30 != from || (v31 = 1, (const idMaterial *)*p_to != v39.to) )
        v31 = 0;
      if ( v31 != 0 )
      {
LABEL_44:
        LOBYTE(v12) = 1;
        goto LABEL_45;
      }
      v32 = *((_DWORD *)v28 + 1);
      v33 = *p_to;
      if ( v32 >= (int)v39.to )
      {
        if ( v33 >= (int)v39.to )
          goto LABEL_45;
      }
      else if ( v33 >= (int)v39.to )
      {
        goto LABEL_42;
      }
      if ( v32 >= (int)v39.to )
      {
LABEL_42:
        v34 = *((_DWORD *)v28 + 1);
        __twllei(v33 - v34, 0);
        v39.from = (const idMaterial *)(((int)v39.to - v34) / (v33 - v34));
        v35 = (int)v27 + (int)v39.from * ((char *)v30 - (char *)v27);
        __twlgei((v33 - v34) & ~(__ROL4__((char *)v39.to - v34, 1) - 1), 0xFFFFFFFF);
        if ( v35 < (int)from )
          v22 = (_cntlzw(v22) & 0x20) != 0;
      }
LABEL_45:
      LOBYTE(v19) = v12;
      v25 = (int)p_to - 4 - (_DWORD)list;
      ++v23;
      p_to += 2;
      if ( (_BYTE)v12 != 0 )
        goto LABEL_46;
    }
  }
LABEL_55:
  v4->graph->contoursInner = contoursInner;
  if ( (v38.listStatic == 0 || v38.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  return v37;
}


// ========================================================================
// __unwind$232570
// EA  : 0x827BE594
// RVA : 0x007BE594
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_232570()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4384 + 96));
}


// ========================================================================
// ?AllocateGraph@idCutterGraphManager@@QAAHABVidStr@@ABVidVec3@@ABVidMat3@@1ABV?$idList@VidVec3@@$04@@@Z
// EA  : 0x827BE5C8
// RVA : 0x007BE5C8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::AllocateGraph(
        idCutterGraphManager *this,
        const idStr *name,
        const idVec3 *position,
        const idMat3 *orientation,
        const idVec3 *normal,
        const idList<idVec3,5> *points)
{
  idCutterGraphManager::Node_t *v12; // r3
  idCutterGraphManager::Graph *v13; // r30
  double z; // fp12
  int v15; // r29
  int v16; // r26
  Contour *v17; // r3
  unsigned int allocedAndFlag; // r11
  size_t len; // r28
  Contour *v20; // r26
  int v21; // r4
  int v22; // r11
  bool v23; // zf
  int v24; // r30
  idCutterGraphManager::Graph v26[17]; // [sp+50h] [-2080h] BYREF

  v12 = (idCutterGraphManager::Node_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                          size: 0xF0u,
                                          tag: TAG_NEW,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  v26[0].lastNode = v12;
  if ( v12 != nullptr )
    v13 = idCutterGraphManager::Graph::Graph(this: (idCutterGraphManager::Graph *)v12);
  else
    v13 = nullptr;
  idCutterGraphManager::Graph::SetPosition(this: v13, position_: position, orientation_: orientation);
  v13->normal.x = normal->x;
  v13->normal.y = normal->y;
  z = normal->z;
  v26[0].lastNode = (idCutterGraphManager::Node_t *)&v13->normal;
  v13->normal.z = z;
  idVec3::NormalVectors(this: &v13->normal, left: &v13->left, down: &v13->down);
  *(_DWORD *)&v26[0].nodes.granularity = 0;
  v26[0].edges.list = (idCutterGraphManager::edgeHandle_t *)1024;
  v26[0].nodes.size = (int)&v26[0].edges.size;
  v26[0].edges.num = 66817;
  v15 = 0;
  if ( points->num > 0 )
  {
    v16 = 0;
    do
    {
      idCutterGraphManager::Graph::Local3DToLocal2D(this: v26, result: (idVec2i *)v13, localPoint: &points->list[v16]);
      idList<cachedPageFile_t,5>::Append(
        this: (idList<idSkinMapping,46> *)&v26[0].nodes.size,
        obj: (const idSkinMapping *)v26);
      ++v15;
      ++v16;
    }
    while ( v15 < points->num );
  }
  idCutterGraphManager::PreAllocatePools(this);
  v17 = ContourManager::Create(this: this->contourManager, points: (const idList<idVec2i,5> *)&v26[0].nodes.size);
  allocedAndFlag = v13->name.allocedAndFlag;
  len = name->len;
  v20 = v17;
  v21 = name->len + 1;
  v23 = allocedAndFlag >> 31 == 0;
  v22 = allocedAndFlag & 0x7FFFFFFF;
  if ( v23 )
  {
    if ( v21 > v22 )
      idStr::ReAllocate(this: &v13->name, amount: v21, keepold: false);
  }
  else if ( v21 > v22
         && AssertFailed(
              file: "w:\\tech5\\shared\\idlib\\text/Str.h",
              line: 463,
              expression: "amount <= GetAlloced()",
              inlineBreak: true) )
  {
    __trap();
  }
  memcpy(Dst: v13->name.data, Src: name->data, Size: len);
  v13->name.data[len] = 0;
  v13->name.len = len;
  idCutterGraphManager::IDHeap::Create(this: &v13->idheap, numBits_: 1024);
  v13->contoursOuter = v20;
  v13->contoursInner = nullptr;
  v20->next = nullptr;
  v13->lastNode = nullptr;
  v26[0].lastNode = (idCutterGraphManager::Node_t *)v13;
  v13->prevNode = nullptr;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->graphs,
    obj: (const encounterGroupRole_t *)v26);
  v24 = this->graphs.num - 1;
  if ( (LOBYTE(v26[0].edges.num) == 0 || LOBYTE(v26[0].edges.num) == 2) && v26[0].nodes.size != 0 )
    idMem::Free(this: &mem, ptr: (void *)v26[0].nodes.size, align: ALIGN_16);
  return v24;
}


// ========================================================================
// __unwind$232730
// EA  : 0x827BE800
// RVA : 0x007BE800
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall _unwind_232730(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 8400 + 80), tag: a2);
}


// ========================================================================
// __unwind$232731
// EA  : 0x827BE828
// RVA : 0x007BE828
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_232731()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8400 + 96));
}


// ========================================================================
// ?PathFind@idCutterGraphManager@@QAA_NAAV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827BE850
// RVA : 0x007BE850
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::PathFind(idCutterGraphManager *this, idList<idSkinMapping,46> *points)
{
  return idCutterGraphManager::Graph::PathFind(this: this->graph, points);
}


// ========================================================================
// ?Acquire@idCutterGraphManager@@QAAXH@Z
// EA  : 0x827BE858
// RVA : 0x007BE858
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Acquire(idCutterGraphManager *this, int id)
{
  int v2; // r30
  idCutterGraphManager::Graph *graph; // r11
  idCutterGraphManager::Graph *v5; // r3

  v2 = id;
  graph = this->graphs.list[id].graph;
  if ( graph != this->graph )
  {
    graph->lastNode = nullptr;
    if ( this->graph != nullptr )
      idCutterGraphManager::ReleaseGraph(this, id: -1);
    v5 = this->graphs.list[v2].graph;
    this->graph = v5;
    idCutterGraphManager::Graph::Acquire(this: v5);
  }
}


// ========================================================================
// ?FreeGraph@idCutterGraphManager@@QAAXH@Z
// EA  : 0x827BE8D0
// RVA : 0x007BE8D0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::FreeGraph(
        idCutterGraphManager *this,
        int id,
        int a3,
        int a4,
        int a5,
        int a6,
        int num,
        int a8)
{
  idCutterGraphManager::graph_t *list; // r25
  int v9; // r26
  idCutterGraphManager::Graph *graph; // r31
  Contour *contoursInner; // r4
  Contour *next; // r30
  Contour *contoursOuter; // r4
  Contour *v15; // r30
  int v16; // r27
  int v17; // r29
  idCutterGraphManager::Edge_t *data; // r4
  int v19; // r27
  int v20; // r29
  idCutterGraphManager::Link_t *v21; // r4
  int v22; // r27
  int v23; // r29
  idCutterGraphManager::Node_t *v24; // r4
  idCutterGraphManager::edgeHandle_t *v25; // r4
  idCutterGraphManager::nodeHandle_t *v26; // r4
  idCutterGraphManager::linkHandle_t *v27; // r4
  idCutterGraphManager::Graph *v28; // r31
  int v29; // [sp+8h] [-88h]
  int v30; // [sp+Ch] [-84h]
  int v31; // [sp+10h] [-80h]
  int v32; // [sp+14h] [-7Ch]
  int v33; // [sp+18h] [-78h]
  idCutterGraphManager::Node_t *v34; // [sp+1Ch] [-74h]

  list = this->graphs.list;
  v9 = id;
  graph = list[id].graph;
  if ( graph != nullptr )
  {
    if ( graph == this->graph )
      idCutterGraphManager::ReleaseGraph(this, id);
    contoursInner = graph->contoursInner;
    if ( contoursInner != nullptr )
    {
      do
      {
        next = contoursInner->next;
        ContourManager::Free(this: this->contourManager, contour: contoursInner);
        contoursInner = next;
      }
      while ( next != nullptr );
    }
    contoursOuter = graph->contoursOuter;
    if ( contoursOuter != nullptr )
    {
      do
      {
        v15 = contoursOuter->next;
        ContourManager::Free(this: this->contourManager, contour: contoursOuter);
        contoursOuter = v15;
      }
      while ( v15 != nullptr );
    }
    v16 = 0;
    if ( graph->edges.num > 0 )
    {
      v17 = 0;
      do
      {
        data = graph->edges.list[v17].data;
        data->next = nullptr;
        idCutterGraphManager::FreeEdge(this, edge: data);
        a8 = (int)graph->edges.list;
        ++v16;
        *(_DWORD *)(v17 * 4 + a8) = 0;
        ++v17;
        num = graph->edges.num;
      }
      while ( v16 < num );
    }
    v19 = 0;
    if ( graph->links.num > 0 )
    {
      v20 = 0;
      do
      {
        v21 = graph->links.list[v20].data;
        v21->next = nullptr;
        idCutterGraphManager::FreeLink(this, link: v21);
        a8 = (int)graph->links.list;
        ++v19;
        *(_DWORD *)(v20 * 4 + a8) = 0;
        ++v20;
        num = graph->links.num;
      }
      while ( v19 < num );
    }
    v22 = 0;
    if ( graph->nodes.num > 0 )
    {
      v23 = 0;
      do
      {
        v24 = graph->nodes.list[v23].data;
        v24->next = nullptr;
        v24->link = nullptr;
        idCutterGraphManager::FreeNode(
          this,
          node: v24,
          a3,
          a4,
          a5,
          a6,
          a7: num,
          a8,
          a9: v29,
          a10: v30,
          a11: v31,
          a12: v32,
          a13: v33,
          a14: v34);
        a8 = (int)graph->nodes.list;
        ++v22;
        *(_DWORD *)(v23 * 4 + a8) = 0;
        ++v23;
        num = graph->nodes.num;
      }
      while ( v22 < num );
    }
    if ( graph->edges.listStatic == 0 || graph->edges.listStatic == 2 )
    {
      v25 = graph->edges.list;
      if ( v25 != nullptr )
        idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
      graph->edges.list = nullptr;
      graph->edges.size = 0;
    }
    graph->edges.num = 0;
    if ( graph->nodes.listStatic == 0 || graph->nodes.listStatic == 2 )
    {
      v26 = graph->nodes.list;
      if ( v26 != nullptr )
        idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
      graph->nodes.list = nullptr;
      graph->nodes.size = 0;
    }
    graph->nodes.num = 0;
    if ( graph->links.listStatic == 0 || graph->links.listStatic == 2 )
    {
      v27 = graph->links.list;
      if ( v27 != nullptr )
        idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
      graph->links.list = nullptr;
      graph->links.size = 0;
    }
    graph->links.num = 0;
    v28 = list[v9].graph;
    if ( v28 != nullptr )
    {
      idCutterGraphManager::Graph::~Graph(this: list[v9].graph);
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
    }
    list[v9].graph = nullptr;
  }
}


// ========================================================================
// ?AddContour@idCutterGraphManager@@QAA_NPAVContour@@0@Z
// EA  : 0x827BEB00
// RVA : 0x007BEB00
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

int __fastcall idCutterGraphManager::AddContour(
        idCutterGraphManager *this,
        Contour *contours,
        Contour *mergedContours,
        int y)
{
  Contour *v6; // r25
  int v7; // r29
  ContourEdge_t *edges; // r23
  Contour *i; // r19
  ContourNode_t *node; // r11
  idCutterGraphManager::Graph *graph; // r5
  const idVec2i *p_pos; // r28
  ContourNode_t *next; // r24
  int v14; // r4
  const idVec2i *v15; // r26
  int num; // r3
  idCutterGraphManager::nodeHandle_t *list; // r8
  int v18; // r10
  int v19; // r31
  int v20; // r30
  int v21; // r3
  idCutterGraphManager::nodeHandle_t *v22; // r8
  int v23; // r10
  int v24; // r31
  idCutterGraphManager::Graph *v25; // r11
  int v26; // r5
  int v27; // r4
  idCutterGraphManager::nodeHandle_t *v28; // r8
  int v29; // r10
  idCutterGraphManager::Graph *v31; // r11
  int v32; // r5
  int v33; // r4
  idCutterGraphManager::nodeHandle_t *v34; // r8
  int v35; // r10
  int v36; // r27
  __int64 v37; // r8
  _DWORD *v38; // r11
  ContourEdge_t *Edge; // r3
  ContourNode_t *v40; // r3
  idCutterGraphManager::Graph *v41; // r11
  ContourNode_t *v42; // r31
  int v43; // r5
  int v44; // r4
  idCutterGraphManager::nodeHandle_t *v45; // r8
  int v46; // r10
  int v47; // r30
  int v48; // r11
  unsigned int v49; // r4
  idCutterGraphManager::Graph *v50; // r11
  int v51; // r5
  ContourNode_t *v52; // r9
  int v53; // r4
  idCutterGraphManager::nodeHandle_t *v54; // r8
  int v55; // r10
  int v56; // r9
  idCutterGraphManager::nodeHandle_t *v57; // r6
  const idVec2i *data; // r8
  const idVec2i *v59; // r10
  _DWORD *v60; // r11
  char v61; // r11
  _BYTE v62[12]; // r9
  int v63; // r21
  __int64 v64; // r25
  int v65; // r20
  idCutterGraphManager::Node_t *v66; // r26
  idCutterGraphManager::Link_t *j; // r11
  Contour *contoursInner; // r22
  bool v69; // r23
  unsigned int v70; // r5
  ContourEdge_t *v71; // r27
  int v72; // r6
  __int64 v73; // r11
  int v74; // r11
  int v75; // r11
  int v76; // r3
  int v77; // r11
  int v78; // r10
  int v79; // r28
  int x; // r31
  ContourNode_t *v81; // r11
  ContourNode_t *v82; // r11
  idVec2i v83; // r10
  int v84; // r10
  unsigned __int8 v85; // r10
  int v86; // r10
  int v87; // r11
  int v88; // r11
  idCutterGraphManager::Link_t *link; // r11
  idCutterGraphManager::Link_t *v90; // r31
  idList<idCutterGraphManager::nodeHandle_t,5> *p_nodes; // r11
  int v92; // r10
  idCutterGraphManager::nodeHandle_t *v93; // r11
  int v94; // r30
  idCutterGraphManager::Link_t *v95; // r11
  idCutterGraphManager::Link_t *v96; // r31
  int v97; // [sp+8h] [-E8h]
  int v98; // [sp+Ch] [-E4h]
  int v99; // [sp+10h] [-E0h]
  int v100; // [sp+14h] [-DCh]
  int v101; // [sp+18h] [-D8h]
  idCutterGraphManager::Node_t *v102; // [sp+1Ch] [-D4h]
  __int64 v103; // [sp+50h] [-A0h]
  __int64 v104; // [sp+50h] [-A0h]
  idVec2i v105; // [sp+50h] [-A0h]
  idVec2 v106; // [sp+58h] [-98h] BYREF
  idVec2i v107; // [sp+60h] [-90h]
  __int64 pos; // [sp+68h] [-88h]
  __int64 v109; // [sp+70h] [-80h]

  v6 = contours;
  v7 = 0;
  if ( contours != nullptr )
  {
    do
    {
      edges = v6->edges;
      for ( i = v6->next; edges != nullptr; edges = edges->next )
      {
        node = edges->node;
        if ( node->next != nullptr )
        {
          do
          {
            graph = this->graph;
            p_pos = &node->pos;
            next = node->next;
            v14 = 0;
            v15 = &node->next->pos;
            num = graph->nodes.num;
            if ( num <= 0 )
            {
LABEL_8:
              v14 = -1;
            }
            else
            {
              v18 = 0;
              y = node->pos.y;
              while ( 1 )
              {
                list = graph->nodes.list;
                if ( (list[v18].data->pos.x - p_pos->x) * (list[v18].data->pos.x - p_pos->x)
                   + (list[v18].data->pos.y - y) * (list[v18].data->pos.y - y) <= 4 )
                  break;
                ++v14;
                ++v18;
                if ( v14 >= num )
                  goto LABEL_8;
              }
            }
            v19 = graph->nodes.num;
            v20 = v14;
            v21 = 0;
            if ( v19 <= 0 )
            {
LABEL_13:
              v24 = -1;
            }
            else
            {
              v23 = 0;
              y = node->next->pos.y;
              while ( 1 )
              {
                v22 = graph->nodes.list;
                if ( (v22[v23].data->pos.x - v15->x) * (v22[v23].data->pos.x - v15->x)
                   + (v22[v23].data->pos.y - y) * (v22[v23].data->pos.y - y) <= 4 )
                  break;
                ++v21;
                ++v23;
                if ( v21 >= v19 )
                  goto LABEL_13;
              }
              v24 = v21;
            }
            if ( v14 < 0 )
            {
              idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find node 0, attempting search nearby!\n");
              v25 = this->graph;
              v26 = 0;
              v27 = v25->nodes.num;
              if ( v27 <= 0 )
                goto LABEL_19;
              v29 = 0;
              y = p_pos->y;
              while ( 1 )
              {
                v28 = v25->nodes.list;
                if ( (v28[v29].data->pos.x - p_pos->x) * (v28[v29].data->pos.x - p_pos->x)
                   + (v28[v29].data->pos.y - y) * (v28[v29].data->pos.y - y) <= 4 )
                  break;
                ++v26;
                ++v29;
                if ( v26 >= v27 )
                  goto LABEL_19;
              }
              v20 = v26;
              if ( v26 < 0 )
              {
LABEL_19:
                idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find close node 0!\n");
                return 0;
              }
            }
            if ( v24 < 0 )
            {
              idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find node 1, attempting search nearby!\n");
              v31 = this->graph;
              v32 = 0;
              v33 = v31->nodes.num;
              if ( v33 <= 0 )
                goto LABEL_27;
              v35 = 0;
              y = v15->y;
              while ( 1 )
              {
                v34 = v31->nodes.list;
                if ( (v34[v35].data->pos.x - v15->x) * (v34[v35].data->pos.x - v15->x)
                   + (v34[v35].data->pos.y - y) * (v34[v35].data->pos.y - y) <= 4 )
                  break;
                ++v32;
                ++v35;
                if ( v32 >= v33 )
                  goto LABEL_27;
              }
              v24 = v32;
              if ( v32 < 0 )
              {
LABEL_27:
                idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find close node 1!\n");
                return 0;
              }
            }
            v36 = 0;
            LODWORD(v37) = this->graph->nodes.list;
            HIDWORD(v37) = *(_DWORD *)(4 * v20 + v37);
            v38 = *(_DWORD **)(HIDWORD(v37) + 4);
            if ( v38 == nullptr )
              goto LABEL_34;
            while ( v38[2] != *(_DWORD *)(4 * v24 + v37) )
            {
              v38 = (_DWORD *)*v38;
              if ( v38 == nullptr )
                goto LABEL_34;
            }
            v36 = v38[1];
            if ( v36 != 0 )
            {
              *(_DWORD *)(v36 + 12) = v6;
            }
            else
            {
LABEL_34:
              Edge = Contour::FindEdge(this: mergedContours, v0: p_pos, v1: v15, a4: y, a5: v37);
              if ( Edge == nullptr )
              {
                idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find contour edge!\n");
                return 0;
              }
              v40 = Contour::FindNode(edge: Edge, v0: p_pos, v1: v15);
              v41 = this->graph;
              v42 = v40;
              v43 = 0;
              v44 = v41->nodes.num;
              if ( v44 <= 0 )
              {
LABEL_39:
                v43 = -1;
              }
              else
              {
                v46 = 0;
                while ( 1 )
                {
                  v45 = v41->nodes.list;
                  if ( (v45[v46].data->pos.x - v40->pos.x) * (v45[v46].data->pos.x - v40->pos.x)
                     + (v45[v46].data->pos.y - v40->pos.y) * (v45[v46].data->pos.y - v40->pos.y) <= 4 )
                    break;
                  ++v43;
                  ++v46;
                  if ( v43 >= v44 )
                    goto LABEL_39;
                }
              }
              v47 = v43;
              while ( 1 )
              {
                y = abs32(v42->pos.x - v15->x);
                if ( y <= 2 )
                {
                  y = 0;
                  v49 = abs32(v42->pos.y - v15->y);
                  v48 = (v49 <= 2) + (v49 >> 31);
                }
                else
                {
                  LOBYTE(v48) = 0;
                }
                if ( (_BYTE)v48 != 0 )
                  break;
                v50 = this->graph;
                v51 = 0;
                v53 = v50->nodes.num;
                if ( v53 <= 0 )
                {
LABEL_49:
                  v56 = -1;
                }
                else
                {
                  v55 = 0;
                  while ( 1 )
                  {
                    v54 = v50->nodes.list;
                    v52 = v42->next;
                    if ( (v54[v55].data->pos.x - v52->pos.x) * (v54[v55].data->pos.x - v52->pos.x)
                       + (v54[v55].data->pos.y - v52->pos.y) * (v54[v55].data->pos.y - v52->pos.y) <= 4 )
                      break;
                    ++v51;
                    ++v55;
                    if ( v51 >= v53 )
                      goto LABEL_49;
                  }
                  v56 = v51;
                }
                v57 = this->graph->nodes.list;
                data = (const idVec2i *)v57[v47].data;
                v59 = (const idVec2i *)v57[v56].data;
                v60 = (_DWORD *)data->y;
                if ( v60 != nullptr )
                {
                  while ( (const idVec2i *)v60[2] != v59 )
                  {
                    v60 = (_DWORD *)*v60;
                    if ( v60 == nullptr )
                      goto LABEL_56;
                  }
                  v36 = v60[1];
                }
LABEL_56:
                if ( v36 == 0 )
                {
                  idLib::Printf(fmt: "idCutterGraphManager::AddContour: Couldn't find graph edge!\n");
                  return 0;
                }
                *(_DWORD *)(v36 + 12) = v6;
                v47 = v56;
                v42 = v42->next;
                if ( v59[1].x != v15->x || (v61 = 1, v59[1].y != v15->y) )
                  v61 = 0;
                if ( v61 == 0 )
                  ContourManager::SplitEdge(
                    this: this->contourManager,
                    edge: edges,
                    v0: data + 1,
                    v1: v15,
                    pos: v59 + 1);
              }
            }
            node = next;
          }
          while ( next->next != nullptr );
        }
      }
      v6->next = this->graph->contoursInner;
      this->graph->contoursInner = v6;
      v6 = i;
    }
    while ( i != nullptr );
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->invalidNodes);
  if ( this->invalidNodes.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->invalidNodes);
  this->invalidNodes.num = __CFADD__(-this->invalidNodes.size, this->invalidNodes.size ^ 0x80000000)
                         ? 0
                         : this->invalidNodes.size;
  v63 = this->graph->nodes.num - 1;
  if ( v63 >= 0 )
  {
    v64 = v103;
    v65 = v63;
    do
    {
      v66 = this->graph->nodes.list[v65].data;
      for ( j = v66->link; j != nullptr; j = j->next )
        j->invalid = 0;
      contoursInner = this->graph->contoursInner;
      if ( contoursInner != nullptr )
      {
        while ( 1 )
        {
          v69 = false;
          pos = (__int64)v66->pos;
          *(_DWORD *)&v62[4] = HIDWORD(pos);
          v109 = *(_QWORD *)v62;
          v106.y = (float)pos;
          v106.x = (float)*(__int64 *)v62;
          *(_DWORD *)v62 = idBounds2D::ContainsPoint(this: &contoursInner->bound, point: &v106);
          if ( *(_DWORD *)v62 != 0 )
          {
            v71 = contoursInner->edges;
            v72 = (int)v71;
            if ( v71 != nullptr )
            {
              *(_DWORD *)v62 = v66->pos.x;
              while ( 1 )
              {
                v73 = *(_QWORD *)(*(_DWORD *)(v72 + 4) + 4);
                v104 = v73;
                *(_QWORD *)&v62[4] = v73;
                if ( HIDWORD(v73) != *(_DWORD *)v62 || (LOBYTE(v74) = 1, (_DWORD)v104 != v66->pos.y) )
                  LOBYTE(v74) = 0;
                v74 = (unsigned __int8)v74;
                while ( (_BYTE)v74 == 0 )
                {
                  if ( HIDWORD(v73) == 0 )
                    break;
                  v73 = *(_QWORD *)(HIDWORD(v73) + 4);
                  HIDWORD(v73) = *(_DWORD *)HIDWORD(v73);
                  v64 = v73;
                  if ( HIDWORD(v73) == *(_DWORD *)v62 )
                  {
                    LOBYTE(v74) = 1;
                    if ( (_DWORD)v64 == v66->pos.y )
                      continue;
                  }
                  LOBYTE(v74) = 0;
                  v74 = (unsigned __int8)v74;
                }
                if ( v74 != 0 )
                  break;
                v75 = v66->pos.y;
                if ( (int)v104 < v75 && (int)v64 >= v75 || (int)v64 < v75 && (int)v104 >= v75 )
                {
                  v76 = (v75 - v104) * (HIDWORD(v64) - HIDWORD(v104));
                  v77 = __ROL4__(v76, 1);
                  v78 = v66->pos.x - HIDWORD(v104);
                  *(_DWORD *)&v62[4] = v76 / ((int)v64 - (int)v104);
                  v70 = (v64 - v104) & ~(v77 - 1);
                  __twllei(v64 - v104, 0);
                  *(_DWORD *)&v62[8] = v77 - 1;
                  __twlgei(v70, 0xFFFFFFFF);
                  if ( v78 < *(int *)&v62[4] )
                    v69 = (_cntlzw(v69) & 0x20) != 0;
                }
                v72 = *(_DWORD *)v72;
                if ( v72 == 0 )
                  goto LABEL_97;
              }
              v69 = false;
            }
LABEL_97:
            if ( v69 && v71 != nullptr )
            {
              v79 = v66->pos.y;
              x = v66->pos.x;
              while ( 1 )
              {
                v81 = v71->node;
                v105 = v81->pos;
                v82 = v81->next;
                do
                {
                  v83 = v82->pos;
                  v82 = v82->next;
                  v107 = v83;
                }
                while ( v82 != nullptr );
                v70 = v105.y - v79;
                *(_DWORD *)v62 = v107.y;
                if ( v105.y == v79 && v107.y == v79
                  || (v84 = v66->pos.x, v105.x == v84) && v107.x == v84
                  || (v70 = (x - v107.x) * v70 - (v79 - v107.y) * (v105.x - x), v85 = 0, v70 == 0) )
                {
                  v85 = 1;
                }
                v72 = v85;
                *(_DWORD *)&v62[8] = v107.y - v105.y;
                *(_DWORD *)&v62[4] = x - v105.x;
                v87 = v79 - v105.y;
                v86 = v107.x - v105.x;
                if ( v72 != 0 )
                {
                  *(_DWORD *)v62 = v87 * *(_DWORD *)&v62[8];
                  v88 = v87 * *(_DWORD *)&v62[8] + *(_DWORD *)&v62[4] * v86;
                  if ( v88 >= 0 )
                  {
                    *(_DWORD *)&v62[8] *= *(_DWORD *)&v62[8];
                    if ( v88 <= *(_DWORD *)&v62[8] + v86 * v86 )
                      break;
                  }
                }
                v71 = v71->next;
                if ( v71 == nullptr )
                  goto LABEL_114;
              }
              v69 = false;
            }
LABEL_114:
            link = v66->link;
            if ( link != nullptr && !v69 )
            {
              idCutterGraphManager::ProcessLinks(this, contour: contoursInner, node: v66, a4: (_BYTE *)v72);
              goto LABEL_126;
            }
            if ( v69 )
              break;
          }
          contoursInner = contoursInner->next;
          if ( contoursInner == nullptr )
            goto LABEL_126;
        }
        if ( link != nullptr )
        {
          do
          {
            v90 = link->next;
            idCutterGraphManager::Disconnect(this, edge: link->edge);
            link = v90;
          }
          while ( v90 != nullptr );
        }
        v66->next = nullptr;
        v66->link = nullptr;
        p_nodes = &this->graph->nodes;
        v92 = this->graph->nodes.num;
        if ( v63 < v92 )
        {
          this->graph->nodes.num = --v92;
          if ( v63 != v92 )
          {
            v93 = p_nodes->list;
            v92 *= 4;
            *(idCutterGraphManager::nodeHandle_t *)&v62[8] = *(idCutterGraphManager::nodeHandle_t *)((char *)v93 + v92);
            v93[v65] = *(idCutterGraphManager::nodeHandle_t *)&v62[8];
          }
        }
        idCutterGraphManager::FreeNode(
          this,
          node: v66,
          a3: v70,
          a4: v72,
          a5: *(int *)v62,
          a6: *(int *)&v62[4],
          a7: *(int *)&v62[8],
          a8: v92,
          a9: v97,
          a10: v98,
          a11: v99,
          a12: v100,
          a13: v101,
          a14: v102);
      }
LABEL_126:
      --v63;
      --v65;
    }
    while ( v63 >= 0 );
  }
  if ( this->invalidNodes.num > 0 )
  {
    v94 = 0;
    do
    {
      v95 = this->invalidNodes.list[v94]->link;
      if ( v95 != nullptr )
      {
        do
        {
          v96 = v95->next;
          if ( (v95->invalid & 3) == 1 )
            idCutterGraphManager::Disconnect(this, edge: v95->edge);
          v95 = v96;
        }
        while ( v96 != nullptr );
      }
      ++v7;
      ++v94;
    }
    while ( v7 < this->invalidNodes.num );
  }
  return 1;
}


// ========================================================================
// ?Write@idCutterGraphManager@@SAXPAV1@PAVidFile@@H@Z
// EA  : 0x827BF438
// RVA : 0x007BF438
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Write(idCutterGraphManager *manager, idFile *file, int graphHandle)
{
  idCutterGraphManager::Graph *graph; // r16
  idFile_vtbl *v5; // r10
  int v6; // r29
  int num; // r14
  int v8; // r30
  int v9; // r11
  const encounterGroupRole_t *v10; // r4
  encounterGroupRole_t *list; // r10
  int v12; // r3
  int v13; // r15
  int v14; // r28
  int v15; // r30
  int v16; // r11
  const encounterGroupRole_t *v17; // r4
  encounterGroupRole_t *v18; // r10
  int v19; // r3
  encounterGroupRole_t *v20; // r29
  int v21; // r20
  int v22; // r28
  int v23; // r30
  int v24; // r11
  const encounterGroupRole_t *v25; // r4
  encounterGroupRole_t *v26; // r10
  int v27; // r3
  encounterGroupRole_t *v28; // r17
  int v29; // r25
  encounterGroupRole_t *v30; // r18
  int v31; // r23
  encounterGroupRole_t *v32; // r19
  int v33; // r21
  _DWORD *i; // r28
  int v35; // r10
  encounterGroupRole_t *v36; // r11
  _DWORD *j; // r28
  int v38; // r10
  encounterGroupRole_t *v39; // r11
  encounterGroupRole_t *v40; // r27
  int k; // r26
  _DWORD *m; // r28
  int v43; // r10
  encounterGroupRole_t *v44; // r11
  encounterGroupRole_t *v45; // r27
  int n; // r26
  _DWORD *ii; // r28
  int v48; // r10
  encounterGroupRole_t *v49; // r11
  encounterGroupRole_t *v50; // r27
  int jj; // r26
  _DWORD *v52; // r28
  int v53; // r11
  encounterGroupRole_t *v54; // r10
  encounterGroupRole_t *v55; // r28
  int kk; // r27
  _DWORD *v57; // r8
  int v58; // r11
  encounterGroupRole_t *v59; // r10
  int v60; // r10
  encounterGroupRole_t *v61; // r11
  encounterGroupRole_t *v62; // r27
  int mm; // r26
  _DWORD *v64; // r28
  int v65; // r11
  encounterGroupRole_t *v66; // r10
  int v67; // r10
  encounterGroupRole_t *v68; // r11
  encounterGroupRole_t *v69; // r30
  int v70; // r26
  encounterGroupRole_t *v71; // r27
  _DWORD *v72; // r28
  int v73; // r11
  encounterGroupRole_t *v74; // r10
  int v75; // r10
  encounterGroupRole_t *v76; // r11
  idFile_vtbl *v77; // r8
  idFile_vtbl *v78; // r10
  encounterGroupRole_t *v79; // r25
  int v80; // r26
  encounterGroupRole_t *v81; // r27
  _DWORD *v82; // r28
  int v83; // r11
  encounterGroupRole_t *v84; // r10
  int v85; // r10
  encounterGroupRole_t *v86; // r11
  int v87; // r10
  encounterGroupRole_t *v88; // r11
  int v89; // r10
  encounterGroupRole_t *v90; // r11
  int v91; // r10
  encounterGroupRole_t *v92; // r11
  idFile_vtbl *v93; // r6
  idFile_vtbl *v94; // r8
  encounterGroupRole_t *v95; // r27
  int nn; // r26
  _DWORD *v97; // r28
  int v98; // r11
  encounterGroupRole_t *v99; // r10
  int v100; // r10
  encounterGroupRole_t *v101; // r11
  int v102; // r10
  encounterGroupRole_t *v103; // r11
  idFile_vtbl *v104; // r10
  int v105; // r28
  idFile_vtbl *v106; // r11
  encounterGroupRole_t *v107; // r26
  encounterGroupRole_t *v108; // r27
  int v109; // r29
  idFile_vtbl *v110; // r11
  encounterGroupRole_t *v111; // r27
  encounterGroupRole_t *v112; // r28
  int v113; // r30
  idFile_vtbl *v114; // r11
  encounterGroupRole_t *v115; // r28
  encounterGroupRole_t *v116; // r29
  int v117; // r10
  encounterGroupRole_t *v118; // r11
  int v119; // r10
  encounterGroupRole_t *v120; // r11
  idFile_vtbl *v121; // r7
  char v122; // r10
  char v123; // r6
  _DWORD *p_next; // [sp+50h] [-1C0h] BYREF
  bool v125[4]; // [sp+54h] [-1BCh] BYREF
  int len; // [sp+58h] [-1B8h] BYREF
  int v127; // [sp+5Ch] [-1B4h] BYREF
  _DWORD v128[4]; // [sp+60h] [-1B0h] BYREF
  idList<enum encounterGroupRole_t,5> v129; // [sp+70h] [-1A0h] BYREF
  idList<enum encounterGroupRole_t,5> v130; // [sp+80h] [-190h] BYREF
  idList<enum encounterGroupRole_t,5> v131; // [sp+90h] [-180h] BYREF
  int v132[4]; // [sp+A0h] [-170h] BYREF
  idList<enum encounterGroupRole_t,5> v133; // [sp+B0h] [-160h] BYREF
  idList<enum encounterGroupRole_t,5> v134; // [sp+C0h] [-150h] BYREF
  idList<enum encounterGroupRole_t,5> v135; // [sp+D0h] [-140h] BYREF
  idList<enum encounterGroupRole_t,5> v136; // [sp+E0h] [-130h] BYREF
  idList<enum encounterGroupRole_t,5> v137; // [sp+F0h] [-120h] BYREF
  idList<enum encounterGroupRole_t,5> v138; // [sp+100h] [-110h] BYREF
  int v139; // [sp+110h] [-100h] BYREF
  int v140; // [sp+114h] [-FCh] BYREF
  int v141; // [sp+118h] [-F8h] BYREF
  int v142; // [sp+11Ch] [-F4h] BYREF
  int v143; // [sp+120h] [-F0h] BYREF
  int v144; // [sp+124h] [-ECh] BYREF
  int v145; // [sp+128h] [-E8h] BYREF
  int v146; // [sp+12Ch] [-E4h] BYREF
  int v147; // [sp+130h] [-E0h] BYREF
  int v148; // [sp+134h] [-DCh] BYREF
  int v149; // [sp+138h] [-D8h] BYREF
  int v150; // [sp+13Ch] [-D4h] BYREF
  int v151; // [sp+140h] [-D0h] BYREF
  int v152; // [sp+144h] [-CCh] BYREF
  int v153; // [sp+148h] [-C8h] BYREF
  int v154; // [sp+14Ch] [-C4h] BYREF
  int v155; // [sp+150h] [-C0h] BYREF
  int v156; // [sp+154h] [-BCh] BYREF
  int v157; // [sp+158h] [-B8h] BYREF
  int v158; // [sp+15Ch] [-B4h] BYREF
  int v159; // [sp+160h] [-B0h] BYREF
  int v160; // [sp+164h] [-ACh] BYREF
  int v161; // [sp+168h] [-A8h] BYREF
  int v162; // [sp+16Ch] [-A4h] BYREF
  int v163; // [sp+170h] [-A0h] BYREF
  int v164; // [sp+174h] [-9Ch] BYREF

  if ( graphHandle >= 0 )
    graph = manager->graphs.list[graphHandle].graph;
  else
    graph = nullptr;
  v5 = file->__vftable;
  v125[0] = graph != nullptr;
  v5->Write(this: file, a2: v125, a3: 1u);
  if ( v125[0] )
  {
    memset(&v135, 0, 14);
    *(_WORD *)&v135.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v135);
    memset(&v129, 0, 14);
    *(_WORD *)&v129.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v129);
    v6 = 0;
    if ( graph->nodes.num <= 0 )
    {
      num = v129.num;
    }
    else
    {
      num = v129.num;
      v8 = 0;
      do
      {
        v9 = 0;
        v10 = (const encounterGroupRole_t *)&graph->nodes.list[v8];
        if ( num <= 0 )
          goto LABEL_13;
        list = v129.list;
        while ( *list != *v10 )
        {
          ++v9;
          ++list;
          if ( v9 >= num )
            goto LABEL_13;
        }
        v12 = v9;
        if ( v9 < 0 )
        {
LABEL_13:
          v12 = idList<idAnimWebBlendTree *,5>::Append(this: &v129, obj: v10);
          num = v129.num;
        }
        p_next = (_DWORD *)v12;
        idList<idAnimWebBlendTree *,5>::Append(this: &v135, obj: (const encounterGroupRole_t *)&p_next);
        ++v6;
        ++v8;
      }
      while ( v6 < graph->nodes.num );
    }
    *(_WORD *)&v134.memTag = 1280;
    memset(&v134, 0, 14);
    v13 = 0;
    *(_WORD *)&v131.memTag = 1280;
    memset(&v131, 0, 14);
    v14 = 0;
    if ( graph->edges.num > 0 )
    {
      v15 = 0;
      do
      {
        v16 = 0;
        v17 = (const encounterGroupRole_t *)&graph->edges.list[v15];
        if ( v13 <= 0 )
          goto LABEL_25;
        v18 = v131.list;
        while ( *v18 != *v17 )
        {
          ++v16;
          ++v18;
          if ( v16 >= v13 )
            goto LABEL_25;
        }
        v19 = v16;
        if ( v16 < 0 )
        {
LABEL_25:
          v19 = idList<idAnimWebBlendTree *,5>::Append(this: &v131, obj: v17);
          v13 = v131.num;
        }
        p_next = (_DWORD *)v19;
        idList<idAnimWebBlendTree *,5>::Append(this: &v134, obj: (const encounterGroupRole_t *)&p_next);
        ++v14;
        ++v15;
      }
      while ( v14 < graph->edges.num );
    }
    *(_WORD *)&v136.memTag = 1280;
    memset(&v136, 0, 14);
    v20 = nullptr;
    v21 = 0;
    *(_WORD *)&v133.memTag = 1280;
    memset(&v133, 0, 14);
    v22 = 0;
    if ( graph->links.num > 0 )
    {
      v23 = 0;
      do
      {
        v24 = 0;
        v25 = (const encounterGroupRole_t *)&graph->links.list[v23];
        if ( v21 <= 0 )
          goto LABEL_35;
        v26 = v20;
        while ( *v26 != *v25 )
        {
          ++v24;
          ++v26;
          if ( v24 >= v21 )
            goto LABEL_35;
        }
        v27 = v24;
        if ( v24 < 0 )
        {
LABEL_35:
          v27 = idList<idAnimWebBlendTree *,5>::Append(this: &v133, obj: v25);
          v21 = v133.num;
          v20 = v133.list;
        }
        p_next = (_DWORD *)v27;
        idList<idAnimWebBlendTree *,5>::Append(this: &v136, obj: (const encounterGroupRole_t *)&p_next);
        ++v22;
        ++v23;
      }
      while ( v22 < graph->links.num );
    }
    v28 = nullptr;
    v29 = 0;
    *(_WORD *)&v137.memTag = 1280;
    memset(&v137, 0, 14);
    v30 = nullptr;
    v31 = 0;
    *(_WORD *)&v138.memTag = 1280;
    memset(&v138, 0, 14);
    v32 = nullptr;
    v33 = 0;
    *(_WORD *)&v130.memTag = 1280;
    memset(&v130, 0, 14);
    p_next = &graph->contoursOuter->next;
    for ( i = p_next; i != nullptr; p_next = i )
    {
      v35 = 0;
      if ( v33 <= 0 )
        goto LABEL_44;
      v36 = v32;
      while ( *(_DWORD **)v36 != i )
      {
        ++v35;
        ++v36;
        if ( v35 >= v33 )
          goto LABEL_44;
      }
      if ( v35 < 0 )
      {
LABEL_44:
        idList<idAnimWebBlendTree *,5>::Append(this: &v130, obj: (const encounterGroupRole_t *)&p_next);
        v33 = v130.num;
        v32 = v130.list;
      }
      i = (_DWORD *)*i;
    }
    p_next = &graph->contoursInner->next;
    for ( j = p_next; j != nullptr; p_next = j )
    {
      v38 = 0;
      if ( v33 <= 0 )
        goto LABEL_53;
      v39 = v32;
      while ( *(_DWORD **)v39 != j )
      {
        ++v38;
        ++v39;
        if ( v38 >= v33 )
          goto LABEL_53;
      }
      if ( v38 < 0 )
      {
LABEL_53:
        idList<idAnimWebBlendTree *,5>::Append(this: &v130, obj: (const encounterGroupRole_t *)&p_next);
        v33 = v130.num;
        v32 = v130.list;
      }
      j = (_DWORD *)*j;
    }
    if ( v33 > 0 )
    {
      v40 = v32;
      for ( k = v33; k != 0; --k )
      {
        p_next = *(_DWORD **)(*v40 + 4);
        for ( m = p_next; m != nullptr; p_next = m )
        {
          v43 = 0;
          if ( v31 <= 0 )
            goto LABEL_64;
          v44 = v30;
          while ( *(_DWORD **)v44 != m )
          {
            ++v43;
            ++v44;
            if ( v43 >= v31 )
              goto LABEL_64;
          }
          if ( v43 < 0 )
          {
LABEL_64:
            idList<idAnimWebBlendTree *,5>::Append(this: &v138, obj: (const encounterGroupRole_t *)&p_next);
            v31 = v138.num;
            v30 = v138.list;
          }
          m = (_DWORD *)*m;
        }
        ++v40;
      }
    }
    if ( v31 > 0 )
    {
      v45 = v30;
      for ( n = v31; n != 0; --n )
      {
        p_next = *(_DWORD **)(*v45 + 4);
        for ( ii = p_next; ii != nullptr; p_next = ii )
        {
          v48 = 0;
          if ( v29 <= 0 )
            goto LABEL_76;
          v49 = v28;
          while ( *(_DWORD **)v49 != ii )
          {
            ++v48;
            ++v49;
            if ( v48 >= v29 )
              goto LABEL_76;
          }
          if ( v48 < 0 )
          {
LABEL_76:
            idList<idAnimWebBlendTree *,5>::Append(this: &v137, obj: (const encounterGroupRole_t *)&p_next);
            v29 = v137.num;
            v28 = v137.list;
          }
          ii = (_DWORD *)*ii;
        }
        ++v45;
      }
    }
    v145 = v29;
    file->Write(this: file, a2: &v145, a3: 4u);
    if ( v29 > 0 )
    {
      v50 = v28;
      for ( jj = v29; jj != 0; --jj )
      {
        v52 = (_DWORD *)*v50;
        v53 = 0;
        v54 = v28;
        while ( *v54 != **(_DWORD **)v50 )
        {
          ++v53;
          ++v54;
          if ( v53 >= v29 )
          {
            v53 = -1;
            break;
          }
        }
        v148 = v53;
        file->Write(this: file, a2: &v148, a3: 4u);
        file->Write(this: file, a2: v52 + 1, a3: 4u);
        file->Write(this: file, a2: v52 + 2, a3: 4u);
        ++v50;
      }
    }
    v150 = v31;
    file->Write(this: file, a2: &v150, a3: 4u);
    if ( v31 > 0 )
    {
      v55 = v30;
      for ( kk = v31; kk != 0; --kk )
      {
        v57 = (_DWORD *)*v55;
        v58 = 0;
        v59 = v30;
        while ( *v59 != **(_DWORD **)v55 )
        {
          ++v58;
          ++v59;
          if ( v58 >= v31 )
          {
            v58 = -1;
            break;
          }
        }
        v152 = v58;
        v60 = 0;
        if ( v29 <= 0 )
        {
LABEL_96:
          v60 = -1;
        }
        else
        {
          v61 = v28;
          while ( *v61 != v57[1] )
          {
            ++v60;
            ++v61;
            if ( v60 >= v29 )
              goto LABEL_96;
          }
        }
        v154 = v60;
        file->Write(this: file, a2: &v152, a3: 4u);
        file->Write(this: file, a2: &v154, a3: 4u);
        ++v55;
      }
    }
    v156 = v33;
    file->Write(this: file, a2: &v156, a3: 4u);
    if ( v33 > 0 )
    {
      v62 = v32;
      for ( mm = v33; mm != 0; --mm )
      {
        v64 = (_DWORD *)*v62;
        v65 = 0;
        v66 = v32;
        while ( *v66 != **(_DWORD **)v62 )
        {
          ++v65;
          ++v66;
          if ( v65 >= v33 )
          {
            v65 = -1;
            break;
          }
        }
        v158 = v65;
        v67 = 0;
        if ( v31 <= 0 )
        {
LABEL_108:
          v67 = -1;
        }
        else
        {
          v68 = v30;
          while ( *v68 != v64[1] )
          {
            ++v67;
            ++v68;
            if ( v67 >= v31 )
              goto LABEL_108;
          }
        }
        v160 = v67;
        file->Write(this: file, a2: &v158, a3: 4u);
        file->Write(this: file, a2: &v160, a3: 4u);
        file->Write(this: file, a2: v64 + 6, a3: 4u);
        file->Write(this: file, a2: v64 + 2, a3: 8u);
        file->Write(this: file, a2: v64 + 4, a3: 8u);
        ++v62;
      }
    }
    v162 = num;
    file->Write(this: file, a2: &v162, a3: 4u);
    v69 = v129.list;
    if ( num > 0 )
    {
      v70 = num;
      v71 = v129.list;
      do
      {
        v72 = (_DWORD *)*v71;
        v73 = 0;
        v74 = v69;
        while ( *v74 != **(_DWORD **)v71 )
        {
          ++v73;
          ++v74;
          if ( v73 >= num )
          {
            v73 = -1;
            break;
          }
        }
        v164 = v73;
        v75 = 0;
        if ( v21 <= 0 )
        {
LABEL_120:
          v75 = -1;
        }
        else
        {
          v76 = v20;
          while ( *v76 != v72[1] )
          {
            ++v75;
            ++v76;
            if ( v75 >= v21 )
              goto LABEL_120;
          }
        }
        v141 = v75;
        v127 = 0;
        file->Write(this: file, a2: &v164, a3: 4u);
        file->Write(this: file, a2: &v141, a3: 4u);
        file->Write(this: file, a2: v72 + 2, a3: 4u);
        file->Write(this: file, a2: v72 + 3, a3: 4u);
        v77 = file->__vftable;
        v127 = (int)v72[4] >> 1;
        v77->Write(this: file, a2: &v127, a3: 4u);
        v78 = file->__vftable;
        v127 = (int)(v72[4] << 31) >> 31;
        v78->Write(this: file, a2: &v127, a3: 4u);
        --v70;
        ++v71;
      }
      while ( v70 != 0 );
    }
    v153 = v13;
    file->Write(this: file, a2: &v153, a3: 4u);
    v79 = v131.list;
    if ( v13 > 0 )
    {
      v80 = v13;
      v81 = v131.list;
      do
      {
        v82 = (_DWORD *)*v81;
        v83 = 0;
        v84 = v79;
        while ( *v84 != **(_DWORD **)v81 )
        {
          ++v83;
          ++v84;
          if ( v83 >= v13 )
          {
            v83 = -1;
            break;
          }
        }
        v143 = v83;
        v85 = 0;
        if ( num <= 0 )
        {
LABEL_132:
          v85 = -1;
        }
        else
        {
          v86 = v69;
          while ( *v86 != v82[1] )
          {
            ++v85;
            ++v86;
            if ( v85 >= num )
              goto LABEL_132;
          }
        }
        v159 = v85;
        v87 = 0;
        if ( num <= 0 )
        {
LABEL_137:
          v87 = -1;
        }
        else
        {
          v88 = v69;
          while ( *v88 != v82[2] )
          {
            ++v87;
            ++v88;
            if ( v87 >= num )
              goto LABEL_137;
          }
        }
        v139 = v87;
        v89 = 0;
        if ( v33 <= 0 )
        {
LABEL_142:
          v89 = -1;
        }
        else
        {
          v90 = v32;
          while ( *v90 != v82[3] )
          {
            ++v89;
            ++v90;
            if ( v89 >= v33 )
              goto LABEL_142;
          }
        }
        v155 = v89;
        v91 = 0;
        if ( v31 <= 0 )
        {
LABEL_147:
          v91 = -1;
        }
        else
        {
          v92 = v30;
          while ( *v92 != v82[4] )
          {
            ++v91;
            ++v92;
            if ( v91 >= v31 )
              goto LABEL_147;
          }
        }
        v147 = v91;
        v128[0] = 0;
        file->Write(this: file, a2: &v143, a3: 4u);
        file->Write(this: file, a2: &v159, a3: 4u);
        file->Write(this: file, a2: &v139, a3: 4u);
        file->Write(this: file, a2: &v155, a3: 4u);
        file->Write(this: file, a2: &v147, a3: 4u);
        v93 = file->__vftable;
        v128[0] = (int)v82[5] >> 31;
        v93->Write(this: file, a2: v128, a3: 4u);
        v94 = file->__vftable;
        v128[0] = (2 * v82[5]) >> 31;
        v94->Write(this: file, a2: v128, a3: 4u);
        --v80;
        ++v81;
      }
      while ( v80 != 0 );
    }
    v163 = v21;
    file->Write(this: file, a2: &v163, a3: 4u);
    if ( v21 > 0 )
    {
      v95 = v20;
      for ( nn = v21; nn != 0; --nn )
      {
        v97 = (_DWORD *)*v95;
        v98 = 0;
        v99 = v20;
        while ( *v99 != **(_DWORD **)v95 )
        {
          ++v98;
          ++v99;
          if ( v98 >= v21 )
          {
            v98 = -1;
            break;
          }
        }
        v149 = v98;
        v100 = 0;
        if ( v13 <= 0 )
        {
LABEL_159:
          v100 = -1;
        }
        else
        {
          v101 = v79;
          while ( *v101 != v97[1] )
          {
            ++v100;
            ++v101;
            if ( v100 >= v13 )
              goto LABEL_159;
          }
        }
        v157 = v100;
        v102 = 0;
        if ( num <= 0 )
        {
LABEL_164:
          v102 = -1;
        }
        else
        {
          v103 = v69;
          while ( *v103 != v97[2] )
          {
            ++v102;
            ++v103;
            if ( v102 >= num )
              goto LABEL_164;
          }
        }
        v151 = v102;
        v132[0] = 0;
        file->Write(this: file, a2: &v149, a3: 4u);
        file->Write(this: file, a2: &v157, a3: 4u);
        file->Write(this: file, a2: &v151, a3: 4u);
        v104 = file->__vftable;
        v132[0] = (int)v97[3] >> 31;
        v104->Write(this: file, a2: v132, a3: 4u);
        ++v95;
      }
    }
    v105 = v135.num;
    v106 = file->__vftable;
    v161 = v135.num;
    v106->Write(this: file, a2: &v161, a3: 4u);
    v107 = v135.list;
    if ( v105 > 0 )
    {
      v108 = v135.list;
      do
      {
        file->Write(this: file, a2: v108, a3: 4u);
        --v105;
        ++v108;
      }
      while ( v105 != 0 );
    }
    v109 = v134.num;
    v110 = file->__vftable;
    v140 = v134.num;
    v110->Write(this: file, a2: &v140, a3: 4u);
    v111 = v134.list;
    if ( v109 > 0 )
    {
      v112 = v134.list;
      do
      {
        file->Write(this: file, a2: v112, a3: 4u);
        --v109;
        ++v112;
      }
      while ( v109 != 0 );
    }
    v113 = v136.num;
    v114 = file->__vftable;
    v142 = v136.num;
    v114->Write(this: file, a2: &v142, a3: 4u);
    v115 = v136.list;
    if ( v113 > 0 )
    {
      v116 = v136.list;
      do
      {
        file->Write(this: file, a2: v116, a3: 4u);
        --v113;
        ++v116;
      }
      while ( v113 != 0 );
    }
    v117 = 0;
    if ( v33 <= 0 )
    {
LABEL_179:
      v117 = -1;
    }
    else
    {
      v118 = v32;
      while ( (Contour *)*v118 != graph->contoursOuter )
      {
        ++v117;
        ++v118;
        if ( v117 >= v33 )
          goto LABEL_179;
      }
    }
    v144 = v117;
    file->Write(this: file, a2: &v144, a3: 4u);
    v119 = 0;
    if ( v33 <= 0 )
    {
LABEL_184:
      v119 = -1;
    }
    else
    {
      v120 = v32;
      while ( (Contour *)*v120 != graph->contoursInner )
      {
        ++v119;
        ++v120;
        if ( v119 >= v33 )
          goto LABEL_184;
      }
    }
    v146 = v119;
    file->Write(this: file, a2: &v146, a3: 4u);
    idCutterGraphManager::IDHeap::Write(this: &graph->idheap, file);
    v121 = file->__vftable;
    len = graph->name.len;
    p_next = &graph->name.len;
    v122 = BYTE1(len);
    v123 = HIBYTE(len);
    BYTE1(len) = BYTE2(len);
    HIBYTE(len) = len;
    LOBYTE(len) = v123;
    BYTE2(len) = v122;
    v121->Write(this: file, a2: &len, a3: 4u);
    file->Write(this: file, a2: graph->name.data, a3: graph->name.len);
    file->Write(this: file, a2: &graph->inverse, a3: 36u);
    file->Write(this: file, a2: &graph->orientation, a3: 36u);
    file->Write(this: file, a2: &graph->position, a3: 12u);
    file->Write(this: file, a2: &graph->normal, a3: 12u);
    file->Write(this: file, a2: &graph->left, a3: 12u);
    file->Write(this: file, a2: &graph->down, a3: 12u);
    if ( (v130.listStatic == 0 || v130.listStatic == 2) && v32 != nullptr )
      idMem::Free(this: &mem, ptr: v32, align: ALIGN_16);
    if ( (v138.listStatic == 0 || v138.listStatic == 2) && v30 != nullptr )
      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
    if ( (v137.listStatic == 0 || v137.listStatic == 2) && v28 != nullptr )
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
    if ( (v133.listStatic == 0 || v133.listStatic == 2) && v133.list != nullptr )
      idMem::Free(this: &mem, ptr: v133.list, align: ALIGN_16);
    if ( (v136.listStatic == 0 || v136.listStatic == 2) && v115 != nullptr )
      idMem::Free(this: &mem, ptr: v115, align: ALIGN_16);
    if ( (v131.listStatic == 0 || v131.listStatic == 2) && v131.list != nullptr )
      idMem::Free(this: &mem, ptr: v131.list, align: ALIGN_16);
    if ( (v134.listStatic == 0 || v134.listStatic == 2) && v111 != nullptr )
      idMem::Free(this: &mem, ptr: v111, align: ALIGN_16);
    if ( (v129.listStatic == 0 || v129.listStatic == 2) && v129.list != nullptr )
      idMem::Free(this: &mem, ptr: v129.list, align: ALIGN_16);
    if ( (v135.listStatic == 0 || v135.listStatic == 2) && v107 != nullptr )
      idMem::Free(this: &mem, ptr: v107, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$233889
// EA  : 0x827C05AC
// RVA : 0x007C05AC
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233889()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 208));
}


// ========================================================================
// __unwind$233890
// EA  : 0x827C05D4
// RVA : 0x007C05D4
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233890()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 112));
}


// ========================================================================
// __unwind$233891
// EA  : 0x827C05FC
// RVA : 0x007C05FC
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233891()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 192));
}


// ========================================================================
// __unwind$233892
// EA  : 0x827C0624
// RVA : 0x007C0624
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233892()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 144));
}


// ========================================================================
// __unwind$233893
// EA  : 0x827C064C
// RVA : 0x007C064C
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233893()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 224));
}


// ========================================================================
// __unwind$233894
// EA  : 0x827C0674
// RVA : 0x007C0674
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233894()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 176));
}


// ========================================================================
// __unwind$233895
// EA  : 0x827C069C
// RVA : 0x007C069C
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233895()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 240));
}


// ========================================================================
// __unwind$233896
// EA  : 0x827C06C4
// RVA : 0x007C06C4
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233896()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 256));
}


// ========================================================================
// __unwind$233897
// EA  : 0x827C06EC
// RVA : 0x007C06EC
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_233897()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 128));
}


// ========================================================================
// ?ApplyGraph@idCutterGraphManager@@AAAXPAVGraph@1@@Z
// EA  : 0x827C0718
// RVA : 0x007C0718
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::ApplyGraph(idCutterGraphManager *this, idCutterGraphManager::Graph *g)
{
  int v4; // r28
  int i; // r31
  idCutterGraphManager::graph_t *list; // r29
  idCutterGraphManager::Graph *graph; // r11
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5

  if ( g != nullptr )
  {
    v4 = 0;
    if ( this->graphs.num > 0 )
    {
      for ( i = 0; ; ++i )
      {
        list = this->graphs.list;
        graph = list[i].graph;
        if ( graph != nullptr && idStr::Cmp(s1: graph->name.data, s2: g->name.data) == 0 )
          break;
        if ( ++v4 >= this->graphs.num )
          return;
      }
      idCutterGraphManager::FreeGraph(this, id: v4, a3: v13, a4: v12, a5: v11, a6: v10, num: v9, a8: v8);
      list[i].graph = g;
    }
  }
}


// ========================================================================
// ?Read@idCutterGraphManager@@SAXPAV1@PAVidFile@@@Z
// EA  : 0x827C07A8
// RVA : 0x007C07A8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::Read(idCutterGraphManager *manager, idFile *file)
{
  Contour *v2; // r29
  idFile_vtbl *v3; // r11
  idCutterGraphManager::Graph *v5; // r3
  idCutterGraphManager::Graph *v6; // r15
  idFile_vtbl *v7; // r11
  int v8; // r27
  idVehicleState **list; // r26
  idVehicleState *v10; // r3
  idFile_vtbl *v11; // r11
  _DWORD *v12; // r28
  int v13; // r4
  int size; // r11
  int v15; // r28
  char v16; // r3
  int num; // r22
  idVehicleState **v18; // r14
  int v19; // r28
  idVehicleState **v20; // r27
  idVehicleState *v21; // r3
  idFile_vtbl *v22; // r11
  _DWORD *v23; // r25
  int v24; // r4
  int v25; // r11
  int v26; // r28
  char v27; // r3
  int v28; // r23
  idVehicleState **v29; // r16
  int v30; // r27
  idVehicleState **v31; // r26
  idVehicleState *v32; // r3
  idFile_vtbl *v33; // r11
  _DWORD *v34; // r28
  int v35; // r4
  int v36; // r11
  int v37; // r28
  char v38; // r3
  int v39; // r24
  idVehicleState **v40; // r17
  int v41; // r27
  idVehicleState **v42; // r26
  idVehicleState *v43; // r3
  _DWORD *v44; // r28
  int v45; // r4
  int v46; // r11
  int v47; // r28
  char v48; // r3
  int v49; // r25
  idVehicleState **v50; // r18
  int v51; // r28
  idVehicleState **v52; // r27
  idVehicleState *v53; // r3
  _DWORD *v54; // r21
  int v55; // r4
  int v56; // r11
  int v57; // r28
  char v58; // r3
  int v59; // r21
  idVehicleState **v60; // r19
  int v61; // r28
  idVehicleState **v62; // r27
  idVehicleState *v63; // r3
  idFile_vtbl *v64; // r11
  _DWORD *v65; // r14
  int v66; // r4
  int v67; // r3
  int v68; // r28
  int v69; // r11
  int v70; // r27
  int v71; // r28
  idCutterGraphManager::Node_t *v72; // r11
  int v73; // r28
  int v74; // r11
  int v75; // r27
  int v76; // r28
  idCutterGraphManager::Edge_t *v77; // r11
  int v78; // r28
  int v79; // r11
  int v80; // r27
  int v81; // r28
  idCutterGraphManager::Link_t *v82; // r11
  idVehicleState **v83; // r8
  int v84; // ctr
  idVehicleState **v85; // r10
  int v86; // r11
  idVehicleState_vtbl *v87; // r11
  idVehicleState **v88; // r9
  int i; // ctr
  _DWORD *v90; // r10
  int v91; // r11
  idVehicleState *v92; // r11
  int v93; // r11
  idVehicleState *v94; // r11
  idVehicleState **v95; // r9
  int j; // ctr
  _DWORD *v97; // r10
  int v98; // r11
  idVehicleState *v99; // r11
  int v100; // r11
  idVehicleState *v101; // r11
  idVehicleState **v102; // r9
  int k; // ctr
  _DWORD *v104; // r10
  int v105; // r11
  idVehicleState *v106; // r11
  int v107; // r11
  idVehicleState *v108; // r11
  idVehicleState **v109; // r9
  int m; // ctr
  _DWORD *v111; // r10
  int v112; // r11
  idVehicleState *v113; // r11
  int v114; // r11
  idVehicleState *v115; // r11
  int v116; // r11
  idVehicleState *v117; // r11
  int v118; // r11
  idVehicleState *v119; // r11
  int v120; // r11
  idVehicleState *v121; // r11
  idVehicleState **v122; // r9
  int n; // ctr
  _DWORD *v124; // r10
  int v125; // r11
  idVehicleState *v126; // r11
  int v127; // r11
  idVehicleState *v128; // r11
  int v129; // r11
  idVehicleState *v130; // r11
  Contour *v131; // r11
  idCutterGraphManager::Graph *v132; // r30
  _BYTE v133[4]; // [sp+50h] [-190h] BYREF
  int v134; // [sp+54h] [-18Ch] BYREF
  int v135; // [sp+58h] [-188h] BYREF
  int v136; // [sp+5Ch] [-184h] BYREF
  int v137; // [sp+60h] [-180h] BYREF
  int v138; // [sp+64h] [-17Ch] BYREF
  int v139; // [sp+68h] [-178h] BYREF
  int v140; // [sp+6Ch] [-174h] BYREF
  int v141; // [sp+70h] [-170h] BYREF
  idCutterGraphManager::Graph *v142; // [sp+74h] [-16Ch]
  int v143; // [sp+78h] [-168h] BYREF
  idList<idVehicleState *,5> v144; // [sp+80h] [-160h] BYREF
  int v145; // [sp+90h] [-150h] BYREF
  int v146[3]; // [sp+94h] [-14Ch] BYREF
  idList<idVehicleState *,5> v147; // [sp+A0h] [-140h] BYREF
  idList<idVehicleState *,5> v148; // [sp+B0h] [-130h] BYREF
  idList<idVehicleState *,5> v149; // [sp+C0h] [-120h] BYREF
  idList<idVehicleState *,5> v150; // [sp+D0h] [-110h] BYREF
  idList<idVehicleState *,5> v151; // [sp+E0h] [-100h] BYREF
  int v152; // [sp+F0h] [-F0h] BYREF
  int v153; // [sp+F4h] [-ECh] BYREF
  int v154; // [sp+F8h] [-E8h] BYREF
  int v155; // [sp+FCh] [-E4h] BYREF
  int v156; // [sp+100h] [-E0h] BYREF
  int v157; // [sp+104h] [-DCh] BYREF
  int v158; // [sp+108h] [-D8h] BYREF
  int v159; // [sp+10Ch] [-D4h] BYREF
  int v160; // [sp+110h] [-D0h] BYREF
  int v161; // [sp+114h] [-CCh] BYREF
  int v162; // [sp+118h] [-C8h] BYREF
  int v163; // [sp+11Ch] [-C4h] BYREF
  int v164; // [sp+120h] [-C0h] BYREF
  int v165; // [sp+124h] [-BCh] BYREF
  int v166; // [sp+128h] [-B8h] BYREF
  int v167; // [sp+12Ch] [-B4h] BYREF
  int v168; // [sp+130h] [-B0h] BYREF
  int v169; // [sp+134h] [-ACh] BYREF
  int v170; // [sp+138h] [-A8h] BYREF
  int v171; // [sp+13Ch] [-A4h] BYREF
  int v172; // [sp+140h] [-A0h] BYREF

  v2 = nullptr;
  v3 = file->__vftable;
  v133[0] = 0;
  v3->Read(this: file, a2: v133, a3: 1u);
  v142 = nullptr;
  if ( v133[0] == 0 )
    goto LABEL_184;
  memset(&v151, 0, 14);
  *(_WORD *)&v151.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v151);
  memset(&v144, 0, 14);
  *(_WORD *)&v144.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v144);
  memset(&v150, 0, 14);
  *(_WORD *)&v150.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v150);
  memset(&v149, 0, 14);
  *(_WORD *)&v149.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v149);
  memset(&v148, 0, 14);
  *(_WORD *)&v148.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v148);
  memset(&v147, 0, 14);
  *(_WORD *)&v147.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v147);
  v5 = (idCutterGraphManager::Graph *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0xF0u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  v142 = v5;
  if ( v5 != nullptr )
    v6 = idCutterGraphManager::Graph::Graph(this: v5);
  else
    v6 = nullptr;
  v6->lastNode = nullptr;
  v6->prevNode = nullptr;
  v7 = file->__vftable;
  v139 = 0;
  v142 = v6;
  v7->Read(this: file, a2: &v139, a3: 4u);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v151, newNum: v139);
  v8 = 0;
  if ( v139 > 0 )
  {
    list = v151.list;
    do
    {
      v10 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3176) : TAG_GAME",
                                size: 0xCu,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *list = v10;
      v11 = file->__vftable;
      v12 = &v10->__vftable;
      v172 = 0;
      v11->Read(this: file, a2: &v172, a3: 4u);
      file->Read(this: file, a2: v12 + 1, a3: 4u);
      file->Read(this: file, a2: v12 + 2, a3: 4u);
      ++v8;
      ++list;
      *v12 = __CFADD__(v172 + 1, 0x80000000) ? 0 : v172 + 1;
    }
    while ( v8 < v139 );
  }
  v136 = 0;
  file->Read(this: file, a2: &v136, a3: 4u);
  v13 = v136;
  size = v144.size;
  v15 = v136;
  if ( v136 > v144.size )
  {
    v16 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v144, newsize: v136);
    v13 = v136;
    if ( v16 == 0 )
    {
      num = v144.num;
      goto LABEL_15;
    }
    size = v144.size;
  }
  if ( v15 >= size )
  {
    num = size;
    v144.num = size;
  }
  else
  {
    num = v15;
    v144.num = v15;
  }
LABEL_15:
  v18 = v144.list;
  v19 = 0;
  if ( v13 > 0 )
  {
    v20 = v144.list;
    do
    {
      v21 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3195) : TAG_GAME",
                                size: 8u,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *v20 = v21;
      v22 = file->__vftable;
      v23 = &v21->__vftable;
      v162 = 0;
      v164 = 0;
      v22->Read(this: file, a2: &v162, a3: 4u);
      file->Read(this: file, a2: &v164, a3: 4u);
      ++v19;
      ++v20;
      *v23 = __CFADD__(v162 + 1, 0x80000000) ? 0 : v162 + 1;
      v23[1] = __CFADD__(v164 + 1, 0x80000000) ? 0 : v164 + 1;
    }
    while ( v19 < v136 );
  }
  v138 = 0;
  file->Read(this: file, a2: &v138, a3: 4u);
  v24 = v138;
  v25 = v150.size;
  v26 = v138;
  if ( v138 > v150.size )
  {
    v27 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v150, newsize: v138);
    v24 = v138;
    if ( v27 == 0 )
    {
      v28 = v150.num;
      goto LABEL_25;
    }
    v25 = v150.size;
  }
  if ( v26 >= v25 )
  {
    v28 = v25;
    v150.num = v25;
  }
  else
  {
    v28 = v26;
    v150.num = v26;
  }
LABEL_25:
  v29 = v150.list;
  v30 = 0;
  if ( v24 > 0 )
  {
    v31 = v150.list;
    do
    {
      v32 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3215) : TAG_GAME",
                                size: 0x1Cu,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *v31 = v32;
      v33 = file->__vftable;
      v34 = &v32->__vftable;
      v166 = 0;
      v168 = 0;
      v33->Read(this: file, a2: &v166, a3: 4u);
      file->Read(this: file, a2: &v168, a3: 4u);
      file->Read(this: file, a2: v34 + 6, a3: 4u);
      file->Read(this: file, a2: v34 + 2, a3: 8u);
      file->Read(this: file, a2: v34 + 4, a3: 8u);
      ++v30;
      ++v31;
      *v34 = __CFADD__(v166 + 1, 0x80000000) ? 0 : v166 + 1;
      v34[1] = __CFADD__(v168 + 1, 0x80000000) ? 0 : v168 + 1;
    }
    while ( v30 < v138 );
  }
  v137 = 0;
  file->Read(this: file, a2: &v137, a3: 4u);
  v35 = v137;
  v36 = v149.size;
  v37 = v137;
  if ( v137 > v149.size )
  {
    v38 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v149, newsize: v137);
    v35 = v137;
    if ( v38 == 0 )
    {
      v39 = v149.num;
      goto LABEL_35;
    }
    v36 = v149.size;
  }
  if ( v37 >= v36 )
  {
    v39 = v36;
    v149.num = v36;
  }
  else
  {
    v39 = v37;
    v149.num = v37;
  }
LABEL_35:
  v40 = v149.list;
  v41 = 0;
  if ( v35 > 0 )
  {
    v42 = v149.list;
    do
    {
      v43 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3238) : TAG_GAME",
                                size: 0x14u,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *v42 = v43;
      v170 = 0;
      v44 = &v43->__vftable;
      v152 = 0;
      v141 = 0;
      file->Read(this: file, a2: &v170, a3: 4u);
      file->Read(this: file, a2: &v152, a3: 4u);
      file->Read(this: file, a2: v44 + 2, a3: 4u);
      file->Read(this: file, a2: v44 + 3, a3: 4u);
      file->Read(this: file, a2: &v141, a3: 4u);
      v44[4] = (2 * v141) | v44[4] & 1;
      file->Read(this: file, a2: &v141, a3: 4u);
      v44[4] = v141 & 1 | v44[4] & 0xFFFFFFFE;
      ++v41;
      ++v42;
      *v44 = __CFADD__(v170 + 1, 0x80000000) ? 0 : v170 + 1;
      v44[1] = __CFADD__(v152 + 1, 0x80000000) ? 0 : v152 + 1;
    }
    while ( v41 < v137 );
  }
  v134 = 0;
  file->Read(this: file, a2: &v134, a3: 4u);
  v45 = v134;
  v46 = v148.size;
  v47 = v134;
  if ( v134 > v148.size )
  {
    v48 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v148, newsize: v134);
    v45 = v134;
    if ( v48 == 0 )
    {
      v49 = v148.num;
      goto LABEL_45;
    }
    v46 = v148.size;
  }
  if ( v47 >= v46 )
  {
    v49 = v46;
    v148.num = v46;
  }
  else
  {
    v49 = v47;
    v148.num = v47;
  }
LABEL_45:
  v50 = v148.list;
  v51 = 0;
  if ( v45 > 0 )
  {
    v52 = v148.list;
    do
    {
      v53 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3264) : TAG_GAME",
                                size: 0x18u,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *v52 = v53;
      v163 = 0;
      v54 = &v53->__vftable;
      v155 = 0;
      v171 = 0;
      v157 = 0;
      v165 = 0;
      v140 = 0;
      file->Read(this: file, a2: &v163, a3: 4u);
      file->Read(this: file, a2: &v155, a3: 4u);
      file->Read(this: file, a2: &v171, a3: 4u);
      file->Read(this: file, a2: &v157, a3: 4u);
      file->Read(this: file, a2: &v165, a3: 4u);
      file->Read(this: file, a2: &v140, a3: 4u);
      v54[5] = (v140 << 31) | v54[5] & 0x7FFFFFFF;
      file->Read(this: file, a2: &v140, a3: 4u);
      v54[5] = (v140 << 30) & 0x40000000 | v54[5] & 0xBFFFFFFF;
      *v54 = __CFADD__(v163 + 1, 0x80000000) ? 0 : v163 + 1;
      ++v51;
      ++v52;
      v54[1] = __CFADD__(v155 + 1, 0x80000000) ? 0 : v155 + 1;
      v54[2] = __CFADD__(v171 + 1, 0x80000000) ? 0 : v171 + 1;
      v54[3] = __CFADD__(v157 + 1, 0x80000000) ? 0 : v157 + 1;
      v54[4] = __CFADD__(v165 + 1, 0x80000000) ? 0 : v165 + 1;
    }
    while ( v51 < v134 );
  }
  v135 = 0;
  file->Read(this: file, a2: &v135, a3: 4u);
  v55 = v135;
  v56 = v147.size;
  v57 = v135;
  if ( v135 <= v147.size )
    goto LABEL_51;
  v58 = idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v147, newsize: v135);
  v55 = v135;
  if ( v58 != 0 )
  {
    v56 = v147.size;
LABEL_51:
    if ( v57 >= v56 )
    {
      v59 = v56;
      v147.num = v56;
    }
    else
    {
      v59 = v57;
      v147.num = v57;
    }
    goto LABEL_55;
  }
  v59 = v147.num;
LABEL_55:
  v60 = v147.list;
  v61 = 0;
  if ( v55 > 0 )
  {
    v62 = v147.list;
    do
    {
      v63 = (idVehicleState *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(3298) : TAG_GAME",
                                size: 0x14u,
                                tag: TAG_GAME,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      *v62 = v63;
      v64 = file->__vftable;
      v65 = &v63->__vftable;
      v169 = 0;
      v161 = 0;
      v167 = 0;
      v159 = 0;
      v64->Read(this: file, a2: &v169, a3: 4u);
      file->Read(this: file, a2: &v161, a3: 4u);
      file->Read(this: file, a2: &v167, a3: 4u);
      file->Read(this: file, a2: &v159, a3: 4u);
      v66 = v159;
      v67 = v65[3];
      v65[4] = 0;
      v65[3] = (v66 << 31) | v67 & 0x7FFFFFFF;
      ++v61;
      ++v62;
      *v65 = __CFADD__(v169 + 1, 0x80000000) ? 0 : v169 + 1;
      v65[1] = __CFADD__(v161 + 1, 0x80000000) ? 0 : v161 + 1;
      v65[2] = __CFADD__(v167 + 1, 0x80000000) ? 0 : v167 + 1;
    }
    while ( v61 < v135 );
    v18 = v144.list;
  }
  file->Read(this: file, a2: &v143, a3: 4u);
  v68 = v143;
  if ( v143 <= v6->nodes.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v6->nodes,
                          newsize: v143) != 0 )
  {
    v69 = v6->nodes.size;
    if ( v68 < v69 )
      v69 = v68;
    v6->nodes.num = v69;
  }
  v70 = 0;
  if ( v143 > 0 )
  {
    v71 = 0;
    do
    {
      v153 = 0;
      file->Read(this: file, a2: &v153, a3: 4u);
      if ( v153 >= 0 )
        v72 = (idCutterGraphManager::Node_t *)v40[v153];
      else
        v72 = nullptr;
      ++v70;
      v6->nodes.list[v71++].data = v72;
    }
    while ( v70 < v143 );
  }
  file->Read(this: file, a2: v146, a3: 4u);
  v73 = v146[0];
  if ( v146[0] <= v6->edges.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v6->edges,
                          newsize: v146[0]) != 0 )
  {
    v74 = v6->edges.size;
    if ( v73 < v74 )
      v74 = v73;
    v6->edges.num = v74;
  }
  v75 = 0;
  if ( v146[0] > 0 )
  {
    v76 = 0;
    do
    {
      v154 = 0;
      file->Read(this: file, a2: &v154, a3: 4u);
      if ( v154 >= 0 )
        v77 = (idCutterGraphManager::Edge_t *)v50[v154];
      else
        v77 = nullptr;
      ++v75;
      v6->edges.list[v76++].data = v77;
    }
    while ( v75 < v146[0] );
  }
  file->Read(this: file, a2: &v145, a3: 4u);
  v78 = v145;
  if ( v145 <= v6->links.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v6->links,
                          newsize: v145) != 0 )
  {
    v79 = v6->links.size;
    if ( v78 < v79 )
      v79 = v78;
    v6->links.num = v79;
  }
  v80 = 0;
  if ( v145 > 0 )
  {
    v81 = 0;
    do
    {
      v156 = 0;
      file->Read(this: file, a2: &v156, a3: 4u);
      if ( v156 >= 0 )
        v82 = (idCutterGraphManager::Link_t *)v60[v156];
      else
        v82 = nullptr;
      ++v80;
      v6->links.list[v81++].data = v82;
    }
    while ( v80 < v145 );
  }
  v83 = v151.list;
  if ( v151.num > 0 )
  {
    v84 = v151.num;
    v85 = v151.list;
    do
    {
      v86 = (int)&(*v85)->__vftable[-1].ValidAttack + 3;
      if ( v86 >= 0 )
        v87 = (idVehicleState_vtbl *)v83[v86];
      else
        v87 = nullptr;
      (*v85++)->__vftable = v87;
      --v84;
    }
    while ( v84 != 0 );
  }
  if ( num > 0 )
  {
    v88 = v18;
    for ( i = num; i != 0; --i )
    {
      v90 = *v88;
      v91 = (int)&(*v88)->__vftable[-1].ValidAttack + 3;
      if ( v91 >= 0 )
        v92 = v18[v91];
      else
        v92 = nullptr;
      *v90 = v92;
      v93 = v90[1] - 1;
      if ( v93 >= 0 )
        v94 = v83[v93];
      else
        v94 = nullptr;
      v90[1] = v94;
      ++v88;
    }
  }
  if ( v28 > 0 )
  {
    v95 = v29;
    for ( j = v28; j != 0; --j )
    {
      v97 = *v95;
      v98 = (int)&(*v95)->__vftable[-1].ValidAttack + 3;
      if ( v98 >= 0 )
        v99 = v29[v98];
      else
        v99 = nullptr;
      *v97 = v99;
      v100 = v97[1] - 1;
      if ( v100 >= 0 )
        v101 = v18[v100];
      else
        v101 = nullptr;
      v97[1] = v101;
      ++v95;
    }
  }
  if ( v39 > 0 )
  {
    v102 = v40;
    for ( k = v39; k != 0; --k )
    {
      v104 = *v102;
      v105 = (int)&(*v102)->__vftable[-1].ValidAttack + 3;
      if ( v105 >= 0 )
        v106 = v40[v105];
      else
        v106 = nullptr;
      *v104 = v106;
      v107 = v104[1] - 1;
      if ( v107 >= 0 )
        v108 = v60[v107];
      else
        v108 = nullptr;
      v104[1] = v108;
      ++v102;
    }
  }
  if ( v49 > 0 )
  {
    v109 = v50;
    for ( m = v49; m != 0; --m )
    {
      v111 = *v109;
      v112 = (int)&(*v109)->__vftable[-1].ValidAttack + 3;
      if ( v112 >= 0 )
        v113 = v50[v112];
      else
        v113 = nullptr;
      *v111 = v113;
      v114 = v111[1] - 1;
      if ( v114 >= 0 )
        v115 = v40[v114];
      else
        v115 = nullptr;
      v111[1] = v115;
      v116 = v111[2] - 1;
      if ( v116 >= 0 )
        v117 = v40[v116];
      else
        v117 = nullptr;
      v111[2] = v117;
      v118 = v111[3] - 1;
      if ( v118 >= 0 )
        v119 = v29[v118];
      else
        v119 = nullptr;
      v111[3] = v119;
      v120 = v111[4] - 1;
      if ( v120 >= 0 )
        v121 = v18[v120];
      else
        v121 = nullptr;
      v111[4] = v121;
      ++v109;
    }
  }
  if ( v59 > 0 )
  {
    v122 = v60;
    for ( n = v59; n != 0; --n )
    {
      v124 = *v122;
      v125 = (int)&(*v122)->__vftable[-1].ValidAttack + 3;
      if ( v125 >= 0 )
        v126 = v60[v125];
      else
        v126 = nullptr;
      *v124 = v126;
      v127 = v124[1] - 1;
      if ( v127 >= 0 )
        v128 = v50[v127];
      else
        v128 = nullptr;
      v124[1] = v128;
      v129 = v124[2] - 1;
      if ( v129 >= 0 )
        v130 = v40[v129];
      else
        v130 = nullptr;
      v124[2] = v130;
      ++v122;
    }
  }
  v158 = 0;
  file->Read(this: file, a2: &v158, a3: 4u);
  if ( v158 >= 0 )
    v131 = (Contour *)v29[v158];
  else
    v131 = nullptr;
  v6->contoursOuter = v131;
  v160 = 0;
  file->Read(this: file, a2: &v160, a3: 4u);
  if ( v160 >= 0 )
    v2 = (Contour *)v29[v160];
  v6->contoursInner = v2;
  idCutterGraphManager::IDHeap::Read(this: &v6->idheap, file);
  idFile::ReadString(this: file, string: &v6->name);
  file->Read(this: file, a2: &v6->inverse, a3: 36u);
  file->Read(this: file, a2: &v6->orientation, a3: 36u);
  file->Read(this: file, a2: &v6->position, a3: 12u);
  file->Read(this: file, a2: &v6->normal, a3: 12u);
  file->Read(this: file, a2: &v6->left, a3: 12u);
  file->Read(this: file, a2: &v6->down, a3: 12u);
  if ( (v147.listStatic == 0 || v147.listStatic == 2) && v60 != nullptr )
    idMem::Free(this: &mem, ptr: v60, align: ALIGN_16);
  if ( (v148.listStatic == 0 || v148.listStatic == 2) && v50 != nullptr )
    idMem::Free(this: &mem, ptr: v50, align: ALIGN_16);
  if ( (v149.listStatic == 0 || v149.listStatic == 2) && v40 != nullptr )
    idMem::Free(this: &mem, ptr: v40, align: ALIGN_16);
  if ( (v150.listStatic == 0 || v150.listStatic == 2) && v29 != nullptr )
    idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
  if ( (v144.listStatic == 0 || v144.listStatic == 2) && v18 != nullptr )
    idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
  if ( (v151.listStatic == 0 || v151.listStatic == 2) && v151.list != nullptr )
    idMem::Free(this: &mem, ptr: v151.list, align: ALIGN_16);
LABEL_184:
  if ( manager != nullptr )
  {
    if ( v142 != nullptr )
      idCutterGraphManager::ApplyGraph(this: manager, g: v142);
  }
  else
  {
    v132 = v142;
    if ( v142 != nullptr )
    {
      idCutterGraphManager::Graph::~Graph(this: v142);
      idMem::Free(this: &mem, ptr: v132, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$235453
// EA  : 0x827C1AB0
// RVA : 0x007C1AB0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235453()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 224));
}


// ========================================================================
// __unwind$235454
// EA  : 0x827C1AD8
// RVA : 0x007C1AD8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$235455
// EA  : 0x827C1B00
// RVA : 0x007C1B00
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235455()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 208));
}


// ========================================================================
// __unwind$235456
// EA  : 0x827C1B28
// RVA : 0x007C1B28
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235456()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 192));
}


// ========================================================================
// __unwind$235457
// EA  : 0x827C1B50
// RVA : 0x007C1B50
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235457()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 176));
}


// ========================================================================
// __unwind$235458
// EA  : 0x827C1B78
// RVA : 0x007C1B78
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_235458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$235459
// EA  : 0x827C1BA0
// RVA : 0x007C1BA0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall _unwind_235459(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 480 + 116), tag: a2);
}


// ========================================================================
// ??0idCutterGraphManager@@QAA@XZ
// EA  : 0x827C1C38
// RVA : 0x007C1C38
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

idCutterGraphManager *__fastcall idCutterGraphManager::idCutterGraphManager(idCutterGraphManager *this)
{
  ContourManager *v2; // r3
  ContourManager *v3; // r3
  int v5[24]; // [sp+50h] [-60h] BYREF

  this->__vftable = (idCutterGraphManager_vtbl *)&idCutterGraphManager::`vftable';
  this->savedContours.granularity = 0;
  this->savedContours.memTag = 5;
  this->savedContours.listStatic = 0;
  v5[0] = (int)&this->savedContours;
  this->savedContours.list = nullptr;
  this->savedContours.size = 0;
  this->savedContours.num = 0;
  this->savedNodes.list = nullptr;
  this->savedNodes.granularity = 0;
  this->savedNodes.memTag = 5;
  this->savedNodes.listStatic = 0;
  this->savedNodes.size = 0;
  this->savedNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->savedNodes);
  this->invalidNodes.list = nullptr;
  this->invalidNodes.granularity = 0;
  this->invalidNodes.memTag = 5;
  this->invalidNodes.listStatic = 0;
  this->invalidNodes.size = 0;
  this->invalidNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->invalidNodes);
  this->graphs.list = nullptr;
  this->graphs.granularity = 0;
  this->graphs.memTag = 5;
  this->graphs.listStatic = 0;
  this->graphs.size = 0;
  this->graphs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->graphs);
  this->linksPoolBlock.list = nullptr;
  this->linksPoolBlock.granularity = 0;
  this->linksPoolBlock.memTag = 5;
  this->linksPoolBlock.listStatic = 0;
  this->linksPoolBlock.size = 0;
  this->linksPoolBlock.num = 0;
  v5[0] = (int)&this->linksPoolBlock;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->linksPoolBlock);
  this->nodesPoolBlock.list = nullptr;
  this->nodesPoolBlock.granularity = 0;
  this->nodesPoolBlock.memTag = 5;
  this->nodesPoolBlock.listStatic = 0;
  this->nodesPoolBlock.size = 0;
  this->nodesPoolBlock.num = 0;
  v5[0] = (int)&this->nodesPoolBlock;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodesPoolBlock);
  this->edgesPoolBlock.list = nullptr;
  this->edgesPoolBlock.granularity = 0;
  this->edgesPoolBlock.memTag = 5;
  this->edgesPoolBlock.listStatic = 0;
  this->edgesPoolBlock.size = 0;
  this->edgesPoolBlock.num = 0;
  v5[0] = (int)&this->edgesPoolBlock;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgesPoolBlock);
  this->linksPool.list = nullptr;
  this->linksPool.granularity = 0;
  this->linksPool.memTag = 5;
  this->linksPool.listStatic = 0;
  this->linksPool.size = 0;
  this->linksPool.num = 0;
  v5[0] = (int)&this->linksPool;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->linksPool);
  this->nodesPool.list = nullptr;
  this->nodesPool.granularity = 0;
  this->nodesPool.memTag = 5;
  this->nodesPool.listStatic = 0;
  this->nodesPool.size = 0;
  this->nodesPool.num = 0;
  v5[0] = (int)&this->nodesPool;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodesPool);
  this->edgesPool.memTag = 5;
  this->edgesPool.list = nullptr;
  this->edgesPool.granularity = 0;
  this->edgesPool.listStatic = 0;
  this->edgesPool.size = 0;
  this->edgesPool.num = 0;
  v5[0] = (int)&this->edgesPool;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edgesPool);
  this->graph = nullptr;
  v5[0] = 0;
  this->contourManager = nullptr;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->linksPool, newSize: 1024, initValue: v5);
  v5[0] = 0;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->nodesPool, newSize: 1024, initValue: v5);
  v5[0] = 0;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->edgesPool, newSize: 1024, initValue: v5);
  v5[0] = 0;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->linksPoolBlock, newSize: 4, initValue: v5);
  v5[0] = 0;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->nodesPoolBlock, newSize: 4, initValue: v5);
  v5[0] = 0;
  idList<int,5>::PreAllocate(this: (idList<int,5> *)&this->edgesPoolBlock, newSize: 4, initValue: v5);
  v2 = (ContourManager *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\models\\cuttable\\CutterGraph.cpp(945) : TAG_GAME",
                           size: 0xCu,
                           tag: TAG_GAME,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v5[0] = (int)v2;
  this->contourManager = v2;
  if ( v2 != nullptr )
    v3 = ContourManager::ContourManager(this: v2);
  else
    v3 = nullptr;
  this->contourManager = v3;
  return this;
}


// ========================================================================
// __unwind$237298
// EA  : 0x827C1EA8
// RVA : 0x007C1EA8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237298()
{
  int v0; // r12

  idList<idCutterGraphManager::savedContour_t,5>::~idList<idCutterGraphManager::savedContour_t,5>(this: (idList<idCutterGraphManager::savedContour_t,5> *)(*(_DWORD *)(v0 - 176 + 196) + 4));
}


// ========================================================================
// __unwind$237299
// EA  : 0x827C1ED4
// RVA : 0x007C1ED4
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237299()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 20));
}


// ========================================================================
// __unwind$237300
// EA  : 0x827C1F00
// RVA : 0x007C1F00
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237300()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 36));
}


// ========================================================================
// __unwind$237301
// EA  : 0x827C1F2C
// RVA : 0x007C1F2C
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237301()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 52));
}


// ========================================================================
// __unwind$237302
// EA  : 0x827C1F58
// RVA : 0x007C1F58
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237302()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 68));
}


// ========================================================================
// __unwind$237303
// EA  : 0x827C1F84
// RVA : 0x007C1F84
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237303()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 84));
}


// ========================================================================
// __unwind$237304
// EA  : 0x827C1FB0
// RVA : 0x007C1FB0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237304()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 100));
}


// ========================================================================
// __unwind$237305
// EA  : 0x827C1FDC
// RVA : 0x007C1FDC
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237305()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 116));
}


// ========================================================================
// __unwind$237306
// EA  : 0x827C2008
// RVA : 0x007C2008
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237306()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 132));
}


// ========================================================================
// __unwind$237307
// EA  : 0x827C2034
// RVA : 0x007C2034
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237307()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 148));
}


// ========================================================================
// __unwind$237308
// EA  : 0x827C2060
// RVA : 0x007C2060
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237308()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 80));
}


// ========================================================================
// ??1idCutterGraphManager@@UAA@XZ
// EA  : 0x827C2098
// RVA : 0x007C2098
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void __fastcall idCutterGraphManager::~idCutterGraphManager(
        idCutterGraphManager *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6)
{
  void **v7; // r10
  int num; // r9
  int v9; // r29
  idCutterGraphManager::Link_t **list; // r4
  idCutterGraphManager::Node_t **v11; // r4
  idCutterGraphManager::Edge_t **v12; // r4
  int v13; // r27
  int v14; // r29
  idCutterGraphManager::Link_t *v15; // r4
  int v16; // r27
  int v17; // r29
  idCutterGraphManager::Node_t *v18; // r4
  int v19; // r27
  int v20; // r29
  idCutterGraphManager::Edge_t *v21; // r4
  idCutterGraphManager::Link_t **v22; // r4
  idCutterGraphManager::Node_t **v23; // r4
  idCutterGraphManager::Edge_t **v24; // r4
  ContourManager *contourManager; // r3
  idCutterGraphManager::Edge_t **v26; // r4
  idCutterGraphManager::Node_t **v27; // r4
  idCutterGraphManager::Link_t **v28; // r4
  idCutterGraphManager::Edge_t **v29; // r4
  idCutterGraphManager::Node_t **v30; // r4
  idCutterGraphManager::Link_t **v31; // r4
  idCutterGraphManager::graph_t *v32; // r4
  idCutterGraphManager::Node_t **v33; // r4
  idCutterGraphManager::savedPathPos_t *v34; // r4
  char *v35; // r3

  v7 = &idCutterGraphManager::`vftable';
  this->__vftable = (idCutterGraphManager_vtbl *)&idCutterGraphManager::`vftable';
  num = this->graphs.num;
  v9 = 0;
  if ( num > 0 )
  {
    do
      idCutterGraphManager::FreeGraph(this, id: v9++, a3, a4, a5, a6, num, a8: (int)v7);
    while ( v9 < this->graphs.num );
  }
  if ( this->linksPool.listStatic == 0 || this->linksPool.listStatic == 2 )
  {
    list = this->linksPool.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->linksPool.list = nullptr;
    this->linksPool.size = 0;
  }
  this->linksPool.num = 0;
  if ( this->nodesPool.listStatic == 0 || this->nodesPool.listStatic == 2 )
  {
    v11 = this->nodesPool.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->nodesPool.list = nullptr;
    this->nodesPool.size = 0;
  }
  this->nodesPool.num = 0;
  if ( this->edgesPool.listStatic == 0 || this->edgesPool.listStatic == 2 )
  {
    v12 = this->edgesPool.list;
    if ( v12 != nullptr )
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    this->edgesPool.list = nullptr;
    this->edgesPool.size = 0;
  }
  this->edgesPool.num = 0;
  v13 = 0;
  if ( this->linksPoolBlock.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = this->linksPoolBlock.list[v14];
      if ( v15 != nullptr )
        idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
      ++v13;
      this->linksPoolBlock.list[v14++] = nullptr;
    }
    while ( v13 < this->linksPoolBlock.num );
  }
  v16 = 0;
  if ( this->nodesPoolBlock.num > 0 )
  {
    v17 = 0;
    do
    {
      v18 = this->nodesPoolBlock.list[v17];
      if ( v18 != nullptr )
        idMem::Free(this: &mem, ptr: v18, align: ALIGN_16);
      ++v16;
      this->nodesPoolBlock.list[v17++] = nullptr;
    }
    while ( v16 < this->nodesPoolBlock.num );
  }
  v19 = 0;
  if ( this->edgesPoolBlock.num > 0 )
  {
    v20 = 0;
    do
    {
      v21 = this->edgesPoolBlock.list[v20];
      if ( v21 != nullptr )
        idMem::Free(this: &mem, ptr: v21, align: ALIGN_16);
      ++v19;
      this->edgesPoolBlock.list[v20++] = nullptr;
    }
    while ( v19 < this->edgesPoolBlock.num );
  }
  if ( this->linksPoolBlock.listStatic == 0 || this->linksPoolBlock.listStatic == 2 )
  {
    v22 = this->linksPoolBlock.list;
    if ( v22 != nullptr )
      idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
    this->linksPoolBlock.list = nullptr;
    this->linksPoolBlock.size = 0;
  }
  this->linksPoolBlock.num = 0;
  if ( this->nodesPoolBlock.listStatic == 0 || this->nodesPoolBlock.listStatic == 2 )
  {
    v23 = this->nodesPoolBlock.list;
    if ( v23 != nullptr )
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    this->nodesPoolBlock.list = nullptr;
    this->nodesPoolBlock.size = 0;
  }
  this->nodesPoolBlock.num = 0;
  if ( this->edgesPoolBlock.listStatic == 0 || this->edgesPoolBlock.listStatic == 2 )
  {
    v24 = this->edgesPoolBlock.list;
    if ( v24 != nullptr )
      idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
    this->edgesPoolBlock.list = nullptr;
    this->edgesPoolBlock.size = 0;
  }
  this->edgesPoolBlock.num = 0;
  contourManager = this->contourManager;
  if ( contourManager != nullptr )
  {
    ContourManager::~ContourManager(this: contourManager);
    idMem::Free(this: &mem, ptr: this->contourManager, align: ALIGN_16);
    this->contourManager = nullptr;
  }
  if ( this->edgesPool.listStatic == 0 || this->edgesPool.listStatic == 2 )
  {
    v26 = this->edgesPool.list;
    if ( v26 != nullptr )
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    this->edgesPool.list = nullptr;
    this->edgesPool.size = 0;
  }
  this->edgesPool.num = 0;
  if ( this->nodesPool.listStatic == 0 || this->nodesPool.listStatic == 2 )
  {
    v27 = this->nodesPool.list;
    if ( v27 != nullptr )
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
    this->nodesPool.list = nullptr;
    this->nodesPool.size = 0;
  }
  this->nodesPool.num = 0;
  if ( this->linksPool.listStatic == 0 || this->linksPool.listStatic == 2 )
  {
    v28 = this->linksPool.list;
    if ( v28 != nullptr )
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
    this->linksPool.list = nullptr;
    this->linksPool.size = 0;
  }
  this->linksPool.num = 0;
  if ( this->edgesPoolBlock.listStatic == 0 || this->edgesPoolBlock.listStatic == 2 )
  {
    v29 = this->edgesPoolBlock.list;
    if ( v29 != nullptr )
      idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    this->edgesPoolBlock.list = nullptr;
    this->edgesPoolBlock.size = 0;
  }
  this->edgesPoolBlock.num = 0;
  if ( this->nodesPoolBlock.listStatic == 0 || this->nodesPoolBlock.listStatic == 2 )
  {
    v30 = this->nodesPoolBlock.list;
    if ( v30 != nullptr )
      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
    this->nodesPoolBlock.list = nullptr;
    this->nodesPoolBlock.size = 0;
  }
  this->nodesPoolBlock.num = 0;
  if ( this->linksPoolBlock.listStatic == 0 || this->linksPoolBlock.listStatic == 2 )
  {
    v31 = this->linksPoolBlock.list;
    if ( v31 != nullptr )
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    this->linksPoolBlock.list = nullptr;
    this->linksPoolBlock.size = 0;
  }
  this->linksPoolBlock.num = 0;
  if ( this->graphs.listStatic == 0 || this->graphs.listStatic == 2 )
  {
    v32 = this->graphs.list;
    if ( v32 != nullptr )
      idMem::Free(this: &mem, ptr: v32, align: ALIGN_16);
    this->graphs.list = nullptr;
    this->graphs.size = 0;
  }
  this->graphs.num = 0;
  if ( this->invalidNodes.listStatic == 0 || this->invalidNodes.listStatic == 2 )
  {
    v33 = this->invalidNodes.list;
    if ( v33 != nullptr )
      idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
    this->invalidNodes.list = nullptr;
    this->invalidNodes.size = 0;
  }
  this->invalidNodes.num = 0;
  if ( this->savedNodes.listStatic == 0 || this->savedNodes.listStatic == 2 )
  {
    v34 = this->savedNodes.list;
    if ( v34 != nullptr )
      idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
    this->savedNodes.list = nullptr;
    this->savedNodes.size = 0;
  }
  this->savedNodes.num = 0;
  if ( this->savedContours.listStatic == 0 || this->savedContours.listStatic == 2 )
  {
    v35 = (char *)this->savedContours.list;
    if ( v35 != nullptr )
      idListArrayDelete<idCutterGraphManager::savedContour_t>(ptr: v35, num: this->savedContours.size);
    this->savedContours.list = nullptr;
    this->savedContours.size = 0;
  }
  this->savedContours.num = 0;
}


// ========================================================================
// __unwind$237429
// EA  : 0x827C25BC
// RVA : 0x007C25BC
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237429()
{
  int v0; // r12

  idList<idCutterGraphManager::savedContour_t,5>::~idList<idCutterGraphManager::savedContour_t,5>(this: (idList<idCutterGraphManager::savedContour_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$237430_0
// EA  : 0x827C25E8
// RVA : 0x007C25E8
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237430_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 20));
}


// ========================================================================
// __unwind$237431
// EA  : 0x827C2614
// RVA : 0x007C2614
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237431()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 36));
}


// ========================================================================
// __unwind$237432_0
// EA  : 0x827C2640
// RVA : 0x007C2640
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237432_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 52));
}


// ========================================================================
// __unwind$237433
// EA  : 0x827C266C
// RVA : 0x007C266C
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237433()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 68));
}


// ========================================================================
// __unwind$237434
// EA  : 0x827C2698
// RVA : 0x007C2698
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237434()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 84));
}


// ========================================================================
// __unwind$237435
// EA  : 0x827C26C4
// RVA : 0x007C26C4
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237435()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 100));
}


// ========================================================================
// __unwind$237436
// EA  : 0x827C26F0
// RVA : 0x007C26F0
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 116));
}


// ========================================================================
// __unwind$237437
// EA  : 0x827C271C
// RVA : 0x007C271C
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237437()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 132));
}


// ========================================================================
// __unwind$237438
// EA  : 0x827C2748
// RVA : 0x007C2748
// PDB : w:\tech5\engine\models\cuttable\cuttergraph.cpp
// ========================================================================

void _unwind_237438()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 148));
}

