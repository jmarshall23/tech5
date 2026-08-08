
// ========================================================================
// ??1idObstacleAvoidance@@QAA@XZ
// EA  : 0x826BABA0
// RVA : 0x006BABA0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::~idObstacleAvoidance(idObstacleAvoidance *this)
{
  obstacleAvoidanceManager->FreeObstacleBuffers(this: obstacleAvoidanceManager, a2: this);
}


// ========================================================================
// ?AllocBuffers@idObstacleAvoidance@@QAAXXZ
// EA  : 0x826BABC0
// RVA : 0x006BABC0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::AllocBuffers(idObstacleAvoidance *this)
{
  obstacleAvoidanceManager->AllocObstacleBuffers(this: obstacleAvoidanceManager, a2: this);
}


// ========================================================================
// ?GetVertexArray@idObstacleAvoidance@@QAAPAUobstacleVertex_t@@XZ
// EA  : 0x826BABE0
// RVA : 0x006BABE0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

obstacleVertex_t *__fastcall idObstacleAvoidance::GetVertexArray(idObstacleAvoidance *this)
{
  idObstacleBuffers *buffers; // r11
  obstacleVertex_t *result; // r3
  bool v3; // zf

  buffers = this->buffers;
  v3 = this->buffers != nullptr;
  result = nullptr;
  if ( v3 )
    return buffers->vertices;
  return result;
}


// ========================================================================
// ?GetMaxVertices@idObstacleAvoidance@@QAAHXZ
// EA  : 0x826BABF8
// RVA : 0x006BABF8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

int __fastcall idObstacleAvoidance::GetMaxVertices(idObstacleAvoidance *this)
{
  return this->buffers == nullptr ? 0 : 0x300;
}


// ========================================================================
// ?SetNumVertices@idObstacleAvoidance@@QAAXH@Z
// EA  : 0x826BAC10
// RVA : 0x006BAC10
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::SetNumVertices(idObstacleAvoidance *this, int num)
{
  if ( this->buffers != nullptr )
    this->buffers->numVertices = num;
}


// ========================================================================
// ?GetEdgeArray@idObstacleAvoidance@@QAAPAUobstacleEdge_t@@XZ
// EA  : 0x826BAC28
// RVA : 0x006BAC28
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

obstacleEdge_t *__fastcall idObstacleAvoidance::GetEdgeArray(idObstacleAvoidance *this)
{
  idObstacleBuffers *buffers; // r11
  obstacleEdge_t *result; // r3
  bool v3; // zf

  buffers = this->buffers;
  v3 = this->buffers != nullptr;
  result = nullptr;
  if ( v3 )
    return buffers->edges;
  return result;
}


// ========================================================================
// ?GetMaxEdges@idObstacleAvoidance@@QAAHXZ
// EA  : 0x826BAC40
// RVA : 0x006BAC40
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

int __fastcall idObstacleAvoidance::GetMaxEdges(idObstacleAvoidance *this)
{
  return this->buffers == nullptr ? 0 : 0x200;
}


// ========================================================================
// ?SetNumEdges@idObstacleAvoidance@@QAAXH@Z
// EA  : 0x826BAC58
// RVA : 0x006BAC58
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::SetNumEdges(idObstacleAvoidance *this, int num)
{
  if ( this->buffers != nullptr )
    this->buffers->numEdges = num;
}


// ========================================================================
// ObstacleAvoidanceJob
// EA  : 0x826BAC78
// RVA : 0x006BAC78
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall ObstacleAvoidanceJob(obstacleParms_t *parms)
{
  int v2; // r12
  int numTraces; // r7
  const obstacleTrace_t *traces; // r6
  int numCorners; // r26
  const obstacleCorner_t *corners; // r25
  double cornerCircleRadius; // fp3
  double frameMoveDist; // fp2
  int numEdges; // r29
  double obstacleRadius; // fp1
  const obstacleEdge_t *edges; // r24
  int numVertices; // r23
  const obstacleVertex_t *vertices; // r22
  int numObstacles; // r21
  const obstacleBox_t *obstacles; // r20
  const obstacleRoute_t *route; // r19
  int flags; // r18
  int maxDebugText; // r8
  avoidDebugText_t *debugText; // r7
  int maxDebugLines; // r6
  avoidDebugLine_t *debugLines; // r5
  obstaclePath_t *path; // r4
  _DWORD back_chain[60]; // [sp+0h] [-200h]
  idObstacleAvoidanceCore v24; // [sp+F0h] [-110h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v2) = back_chain[0];
  idObstacleAvoidanceCore::idObstacleAvoidanceCore(this: &v24);
  numTraces = parms->numTraces;
  traces = parms->traces;
  numCorners = parms->numCorners;
  corners = parms->corners;
  back_chain[59] = parms->traceFractions;
  back_chain[57] = numTraces;
  cornerCircleRadius = parms->cornerCircleRadius;
  back_chain[55] = traces;
  frameMoveDist = parms->frameMoveDist;
  numEdges = parms->numEdges;
  obstacleRadius = parms->obstacleRadius;
  edges = parms->edges;
  numVertices = parms->numVertices;
  vertices = parms->vertices;
  numObstacles = parms->numObstacles;
  obstacles = parms->obstacles;
  route = parms->route;
  flags = parms->flags;
  maxDebugText = parms->maxDebugText;
  debugText = parms->debugText;
  maxDebugLines = parms->maxDebugLines;
  debugLines = parms->debugLines;
  path = parms->path;
  back_chain[53] = numCorners;
  back_chain[51] = corners;
  back_chain[49] = numEdges;
  back_chain[47] = edges;
  back_chain[45] = numVertices;
  back_chain[43] = vertices;
  back_chain[41] = numObstacles;
  back_chain[39] = obstacles;
  back_chain[37] = route;
  back_chain[35] = flags;
  back_chain[27] = &parms->lastCorner;
  back_chain[25] = &parms->lastDir;
  back_chain[23] = &parms->gravity;
  back_chain[21] = parms;
  idObstacleAvoidanceCore::FindPathAroundObstacles(
    this: &v24,
    path,
    debugLines,
    maxDebugLines,
    debugText,
    maxDebugText,
    temp: &v24,
    tempSize: 0x10000,
    bbox: (const idBounds *)back_chain[2],
    gravity: (const idVec3 *)back_chain[3],
    lastDir: (const idVec3 *)back_chain[4],
    lastCorner: (const idVec4 *)back_chain[5],
    obstacleRadius,
    frameMoveDist,
    cornerCircleRadius,
    flags: back_chain[6],
    route: (const obstacleRoute_t *)back_chain[7],
    obstacles: (const obstacleBox_t *)back_chain[8],
    numObstacles: back_chain[9],
    vertices: (const obstacleVertex_t *)back_chain[10],
    numVertices: back_chain[11],
    edges: (const obstacleEdge_t *)back_chain[12],
    numEdges: back_chain[13],
    corners: (const obstacleCorner_t *)back_chain[14],
    numCorners: back_chain[15],
    traces: (const obstacleTrace_t *)back_chain[16],
    numTraces: back_chain[17],
    traceFractions: (float *)back_chain[18]);
  parms->path->done = true;
  idObstacleAvoidanceCore::~idObstacleAvoidanceCore(this: &v24);
}


// ========================================================================
// __unwind$246260
// EA  : 0x826BAD78
// RVA : 0x006BAD78
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void _unwind_246260()
{
  int v0; // r12

  idObstacleAvoidanceCore::~idObstacleAvoidanceCore(this: (idObstacleAvoidanceCore *)(v0 - 512 + 240));
}


// ========================================================================
// ??0idObstacleAvoidance@@QAA@XZ
// EA  : 0x826BADA0
// RVA : 0x006BADA0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

idObstacleAvoidance *__fastcall idObstacleAvoidance::idObstacleAvoidance(idObstacleAvoidance *this)
{
  this->buffers = nullptr;
  this->lastDir.x = 0.0;
  this->lastDir.y = 0.0;
  this->lastDir.z = 0.0;
  this->lastCorner.x = 0.0;
  this->lastCorner.y = 0.0;
  this->lastCorner.z = 0.0;
  this->lastCorner.w = 0.0;
  this->lastUpdateTime = -1;
  return this;
}


// ========================================================================
// ?AddObstacle@idObstacleAvoidance@@QAAXABVidBox@@VidSpawnId@@_N@Z
// EA  : 0x826BADD8
// RVA : 0x006BADD8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::AddObstacle(
        idObstacleAvoidance *this,
        const idBox *box,
        const idSpawnId *id,
        bool soft)
{
  idObstacleBuffers *buffers; // r11
  int numObstacles; // r10
  obstacleBox_t *obstacles; // r9
  obstacleBox_t *v7; // r11

  buffers = this->buffers;
  if ( this->buffers != nullptr )
  {
    numObstacles = buffers->numObstacles;
    if ( numObstacles < 128 )
    {
      obstacles = buffers->obstacles;
      buffers->numObstacles = numObstacles + 1;
      v7 = &obstacles[numObstacles];
      v7->axis = box->axis;
      v7->center = box->center;
      v7->extents = box->extents;
      v7->id = (int)id;
      v7->soft = soft;
    }
  }
}


// ========================================================================
// ?AddObstacle@idObstacleAvoidance@@QAAXABVidBounds@@ABVidVec3@@ABVidMat3@@VidSpawnId@@_N@Z
// EA  : 0x826BAE98
// RVA : 0x006BAE98
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::AddObstacle(
        idObstacleAvoidance *this,
        const idBounds *bounds,
        const idVec3 *origin,
        const idMat3 *axis,
        const idSpawnId *id,
        bool soft)
{
  idObstacleBuffers *buffers; // r10
  int numObstacles; // r11
  obstacleBox_t *obstacles; // r3
  obstacleBox_t *v9; // r11
  double v10; // fp10
  double v11; // fp11
  double v12; // fp6
  double y; // fp3
  double v14; // fp13
  double v15; // fp0
  double v16; // fp2
  double v17; // fp11
  double z; // fp12

  buffers = this->buffers;
  if ( this->buffers != nullptr )
  {
    numObstacles = buffers->numObstacles;
    if ( numObstacles < 128 )
    {
      obstacles = buffers->obstacles;
      buffers->numObstacles = numObstacles + 1;
      v9 = &obstacles[numObstacles];
      v9->axis = *axis;
      v10 = (float)(bounds->b[0].y + bounds->b[1].y);
      v11 = (float)(bounds->b[0].z + bounds->b[1].z);
      v12 = (float)((float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5);
      v9->center.x = (float)(bounds->b[0].x + bounds->b[1].x) * (float)0.5;
      v9->center.y = (float)v10 * (float)0.5;
      v9->center.z = (float)v11 * (float)0.5;
      y = bounds->b[1].y;
      v14 = (float)(bounds->b[1].z - (float)((float)v11 * (float)0.5));
      v9->extents.x = bounds->b[1].x - (float)v12;
      v9->extents.y = (float)y - (float)((float)v10 * (float)0.5);
      v9->extents.z = v14;
      v15 = origin->y;
      v16 = (float)((float)(v9->center.x * axis->mat[0].y)
                  + (float)((float)(axis->mat[1].y * v9->center.y) + (float)(axis->mat[2].y * v9->center.z)));
      v17 = (float)((float)(v9->center.x * axis->mat[0].z)
                  + (float)((float)(axis->mat[1].z * v9->center.y) + (float)(axis->mat[2].z * v9->center.z)));
      z = origin->z;
      v9->center.x = origin->x
                   + (float)((float)(v9->center.z * axis->mat[2].x)
                           + (float)((float)(v9->center.y * axis->mat[1].x) + (float)(v9->center.x * axis->mat[0].x)));
      v9->center.y = (float)v15 + (float)v16;
      v9->center.z = (float)z + (float)v17;
      v9->id = (int)id;
      v9->soft = soft;
    }
  }
}


// ========================================================================
// ?Restart@idObstacleAvoidance@@QAAXABVidVec3@@0@Z
// EA  : 0x826BB030
// RVA : 0x006BB030
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::Restart(idObstacleAvoidance *this, const idVec3 *start, const idVec3 *goal)
{
  obstaclePath_t *path; // r11
  double v7; // fp2
  double v8; // fp1
  double y; // fp12
  double z; // fp11
  obstaclePath_t *v11; // r10
  obstaclePath_t *v12; // r10
  obstaclePath_t *v13; // r10
  obstaclePath_t *v14; // r10
  obstaclePath_t *v15; // r10
  obstaclePath_t *v16; // r10
  obstaclePath_t *v17; // r10
  float *v18; // r10
  obstaclePath_t *v19; // r10
  obstaclePath_t *v20; // r10
  obstaclePath_t *v21; // r10
  obstaclePath_t *v22; // r10
  obstaclePath_t *v23; // r10
  obstaclePath_t *v24; // r10
  obstaclePath_t *v25; // r10
  obstaclePath_t *v26; // r10
  idVec3 v27; // [sp+50h] [-30h] BYREF

  if ( this->buffers != nullptr )
  {
    path = this->buffers->path;
    if ( path != nullptr )
    {
      path->seekPos[0] = *goal;
      this->buffers->path->seekPos[1] = *goal;
      v7 = (float)(goal->z - start->z);
      v8 = (float)(goal->y - start->y);
      v27.x = goal->x - start->x;
      v27.y = v8;
      v27.z = v7;
      idVec3::NormalizeFast(this: &v27);
      y = v27.y;
      z = v27.z;
      v11 = this->buffers->path;
      v11->seekPosPlane.a = v27.x;
      v11->seekPosPlane.b = y;
      v11->seekPosPlane.c = z;
      this->buffers->path->seekPosPlane.d = -(float)((float)(this->buffers->path->seekPosPlane.a * goal->x)
                                                   + (float)((float)(this->buffers->path->seekPosPlane.c * goal->z)
                                                           + (float)(this->buffers->path->seekPosPlane.b * goal->y)));
      this->buffers->path->numSeekPos = 0;
      v12 = this->buffers->path;
      v12->seekPosPlane.d = 0.0;
      v12->seekPosPlane.c = 0.0;
      v12->seekPosPlane.b = 0.0;
      v12->seekPosPlane.a = 0.0;
      v13 = this->buffers->path;
      v13->firstObstaclePosition.z = 0.0;
      v13->firstObstaclePosition.y = 0.0;
      v13->firstObstaclePosition.x = 0.0;
      this->buffers->path->firstObstacle = -1;
      v14 = this->buffers->path;
      v14->startPosOutsideObstacles.x = start->x;
      v14->startPosOutsideObstacles.y = start->y;
      v14->startPosOutsideObstacles.z = start->z;
      this->buffers->path->startPosObstacle = -1;
      v15 = this->buffers->path;
      v15->seekPosOutsideObstacles.x = start->x;
      v15->seekPosOutsideObstacles.y = start->y;
      v15->seekPosOutsideObstacles.z = start->z;
      this->buffers->path->seekPosObstacle = -1;
      this->buffers->path->targetDist = 0.0;
      this->buffers->path->pathLength = 0.0;
      v16 = this->buffers->path;
      v16->nextCorner.w = 0.0;
      v16->nextCorner.x = 0.0;
      v16->nextCorner.z = 0.0;
      v16->nextCorner.y = 0.0;
      this->buffers->path->nextCornerAngle = 0.0;
      v17 = this->buffers->path;
      v17->wallCorners[0].x = goal->x;
      v17->wallCorners[0].y = goal->y;
      v17->wallCorners[0].z = goal->z;
      v18 = (float *)this->buffers->path;
      v18[120] = goal->x;
      v18[121] = goal->y;
      v18[122] = goal->z;
      this->buffers->path->useRadarForward = false;
      v19 = this->buffers->path;
      v19->radarForward.z = 0.0;
      v19->radarForward.y = 0.0;
      v19->radarForward.x = 0.0;
      this->buffers->path->hasValidPath = true;
      this->buffers->path->startPosValid = true;
      this->buffers->path->seekPosValid = true;
      this->buffers->path->done = false;
      v20 = this->buffers->path;
      v20->radar[0].direction.x = 0.0;
      v20->radar[0].direction.y = 0.0;
      v20->radar[0].obstacle = 0;
      v20->radar[0].direction.z = 0.0;
      v21 = this->buffers->path;
      v21->radar[1].direction.x = 0.0;
      v21->radar[1].direction.y = 0.0;
      v21->radar[1].direction.z = 0.0;
      v21->radar[1].obstacle = 0;
      v22 = this->buffers->path;
      v22->radar[2].direction.x = 0.0;
      v22->radar[2].direction.y = 0.0;
      v22->radar[2].direction.z = 0.0;
      v22->radar[2].obstacle = 0;
      v23 = this->buffers->path;
      v23->radar[3].direction.x = 0.0;
      v23->radar[3].direction.y = 0.0;
      v23->radar[3].direction.z = 0.0;
      v23->radar[3].obstacle = 0;
      v24 = this->buffers->path;
      v24->radar[4].direction.x = 0.0;
      v24->radar[4].direction.y = 0.0;
      v24->radar[4].direction.z = 0.0;
      v24->radar[4].obstacle = 0;
      v25 = this->buffers->path;
      v25->radar[5].direction.x = 0.0;
      v25->radar[5].direction.y = 0.0;
      v25->radar[5].direction.z = 0.0;
      v25->radar[5].obstacle = 0;
      v26 = this->buffers->path;
      v26->radar[6].direction.x = 0.0;
      v26->radar[6].direction.y = 0.0;
      v26->radar[6].direction.z = 0.0;
      v26->radar[6].obstacle = 0;
    }
  }
}


// ========================================================================
// ?ProjectTopDown@idObstacleAvoidance@@ABAXAAVidVec3@@ABV2@M@Z
// EA  : 0x826BB350
// RVA : 0x006BB350
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::ProjectTopDown(
        idObstacleAvoidance *this,
        idVec3 *point,
        const idVec3 *startPos,
        double scale)
{
  idGame *v7; // r3
  int v8; // r29
  idGame *v9; // r3
  idGame *v10; // r3
  double v11; // fp10
  double v12; // fp9
  double v13; // fp6
  double v14; // fp5
  idMat3 v15; // [sp+50h] [-D0h] BYREF
  float v16; // [sp+74h] [-ACh]
  idAngles v17; // [sp+80h] [-A0h] BYREF
  float v18; // [sp+8Ch] [-94h]
  float v19; // [sp+90h] [-90h]
  float v20; // [sp+94h] [-8Ch]
  float v21; // [sp+98h] [-88h]
  float v22; // [sp+9Ch] [-84h]
  float v23; // [sp+A0h] [-80h]
  idAngles v24; // [sp+B0h] [-70h] BYREF
  float v25; // [sp+BCh] [-64h]
  float v26; // [sp+C0h] [-60h]
  float v27; // [sp+C8h] [-58h]
  float v28; // [sp+CCh] [-54h]

  v7 = common->Game(this: common);
  v8 = (int)v7->GetEntity(this: v7, a2: 0);
  if ( v8 != 0 )
  {
    v9 = common->Game(this: common);
    v9->EntityGetEyePosition(this: v9, a2: (idEntity *)v8, a3: (idVec3 *)&v15.mat[1].y);
    v10 = common->Game(this: common);
    v10->EntityGetViewAngles(this: v10, a2: (idEntity *)v8, a3: (idAngles *)&v15.mat[2].z);
    idAngles::ToMat3(this: &v17, result: (idMat3 *)&v15.mat[2].z);
    v15.mat[0].x = 0.0;
    v15.mat[0].z = 0.0;
    v15.mat[0].y = -v16;
    idAngles::ToMat3(this: &v24, result: &v15);
    v11 = (float)(v22
                * (float)((float)(v24.pitch * (float)(point->x - startPos->x))
                        + (float)((float)(v27 * (float)(point->z - startPos->z))
                                + (float)(v25 * (float)(point->y - startPos->y)))));
    v12 = (float)(v23
                * (float)((float)(v24.pitch * (float)(point->x - startPos->x))
                        + (float)((float)(v27 * (float)(point->z - startPos->z))
                                + (float)(v25 * (float)(point->y - startPos->y)))));
    v13 = (float)((float)(v15.mat[1].z + (float)(v17.yaw * (float)scale))
                + (float)(v19
                        * (float)((float)(v24.yaw * (float)(point->x - startPos->x))
                                + (float)((float)(v28 * (float)(point->z - startPos->z))
                                        + (float)(v26 * (float)(point->y - startPos->y))))));
    v14 = (float)((float)(v15.mat[2].x + (float)(v17.roll * (float)scale))
                + (float)(v20
                        * (float)((float)(v24.yaw * (float)(point->x - startPos->x))
                                + (float)((float)(v28 * (float)(point->z - startPos->z))
                                        + (float)(v26 * (float)(point->y - startPos->y))))));
    point->x = (float)((float)(v15.mat[1].y + (float)(v17.pitch * (float)scale))
                     + (float)(v18
                             * (float)((float)(v24.yaw * (float)(point->x - startPos->x))
                                     + (float)((float)(v28 * (float)(point->z - startPos->z))
                                             + (float)(v26 * (float)(point->y - startPos->y))))))
             + (float)(v21
                     * (float)((float)(v24.pitch * (float)(point->x - startPos->x))
                             + (float)((float)(v27 * (float)(point->z - startPos->z))
                                     + (float)(v25 * (float)(point->y - startPos->y)))));
    point->y = (float)v13 + (float)v11;
    point->z = (float)v14 + (float)v12;
  }
}


// ========================================================================
// ?DrawBox@idObstacleAvoidance@@ABAXABVidVec3@@M@Z
// EA  : 0x826BB528
// RVA : 0x006BB528
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __fastcall idObstacleAvoidance::DrawBox(idObstacleAvoidance *this, const idVec3 *startPos, double radius)
{
  float y; // r9
  idVec3 *p_x; // r29
  int v8; // r30
  int v9; // r31
  float *v10; // r30
  idRenderWorld *v11; // r3
  idRenderWorld *v12; // r3
  idRenderWorld *v13; // r3
  float x; // [sp+50h] [-A0h] BYREF
  float v15; // [sp+54h] [-9Ch]
  float z; // [sp+58h] [-98h]
  float v17; // [sp+5Ch] [-94h]
  float v18; // [sp+60h] [-90h]
  float v19; // [sp+64h] [-8Ch]
  float v20; // [sp+68h] [-88h]
  float v21; // [sp+6Ch] [-84h]
  float v22; // [sp+70h] [-80h]
  float v23; // [sp+74h] [-7Ch]
  float v24; // [sp+78h] [-78h]
  float v25; // [sp+7Ch] [-74h]
  float v26; // [sp+80h] [-70h] BYREF
  float v27; // [sp+84h] [-6Ch]
  float v28; // [sp+88h] [-68h]
  float v29; // [sp+8Ch] [-64h] BYREF
  float v30; // [sp+90h] [-60h]
  float v31; // [sp+94h] [-5Ch]
  float v32[4]; // [sp+98h] [-58h] BYREF

  y = startPos->y;
  x = startPos->x;
  v15 = y;
  v17 = x;
  v18 = y;
  v20 = x;
  v21 = y;
  v23 = x;
  v24 = y;
  v27 = y;
  p_x = (idVec3 *)&x;
  v29 = x;
  v8 = 7;
  v30 = y;
  z = startPos->z;
  v26 = x;
  v19 = z;
  v22 = z;
  v25 = z;
  v28 = z;
  v15 = y + (float)radius;
  v17 = x + (float)radius;
  v18 = y - (float)radius;
  v20 = x - (float)radius;
  v21 = v18;
  v23 = v20;
  v24 = v15;
  v27 = v24;
  v29 = (float)((float)radius * (float)0.1) + x;
  v30 = (float)((float)radius - (float)((float)radius * (float)0.1)) + y;
  v32[0] = x - (float)((float)radius * (float)0.1);
  x = v17;
  v32[1] = v30;
  v31 = z;
  v32[2] = z;
  do
  {
    idObstacleAvoidance::ProjectTopDown(
      this,
      point: p_x,
      startPos,
      scale: (float)((float)((float)radius / aas_showObstacleScale.valueFloat) * (float)2.5));
    --v8;
    ++p_x;
  }
  while ( v8 != 0 );
  v9 = 0;
  v10 = &x;
  do
  {
    v11 = common->RW(this: common);
    ++v9;
    v11->DebugLine(
      this: v11,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)v10,
      a4: (const idVec3 *)(&x + (v9 & 3) + ((2 * v9) & 6)),
      a5: 0,
      a6: false);
    v10 += 3;
  }
  while ( v9 < 4 );
  v12 = common->RW(this: common);
  v12->DebugLine(
    this: v12,
    a2: (const idVec4 *)&idColor::colorCyan,
    a3: (const idVec3 *)&v26,
    a4: (const idVec3 *)&v29,
    a5: 0,
    a6: false);
  v13 = common->RW(this: common);
  v13->DebugLine(
    this: v13,
    a2: (const idVec4 *)&idColor::colorCyan,
    a3: (const idVec3 *)&v26,
    a4: (const idVec3 *)v32,
    a5: 0,
    a6: false);
}


// ========================================================================
// ?SaveQuery@idObstacleAvoidance@@QAA_NPBD@Z
// EA  : 0x826BBF40
// RVA : 0x006BBF40
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

int __fastcall idObstacleAvoidance::SaveQuery(idObstacleAvoidance *this, const char *fileName)
{
  int result; // r3
  idFile *v4; // r31
  char v5; // r10
  char v6; // r8
  char v7; // r10
  char v8; // r8
  char v9; // r6
  char v10; // r8
  char v11; // r10
  char v12; // r11
  char v13; // r8
  char v14; // r10
  char v15; // r8
  char v16; // r6
  float obstacleRadius; // [sp+50h] [-50h] BYREF
  float frameMoveDist; // [sp+54h] [-4Ch] BYREF
  int numObstacles; // [sp+58h] [-48h] BYREF
  int numVertices; // [sp+5Ch] [-44h] BYREF
  int numEdges; // [sp+60h] [-40h] BYREF
  int numCorners; // [sp+64h] [-3Ch] BYREF
  _BYTE v23[4]; // [sp+68h] [-38h] BYREF
  _BYTE v24[4]; // [sp+6Ch] [-34h] BYREF
  _BYTE v25[48]; // [sp+70h] [-30h] BYREF

  result = ((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  v4 = (idFile *)result;
  if ( result != 0 )
  {
    idFile::WriteString(this: (idFile *)result, string: "ObstacleAvoidanceQuery");
    v23[1] = BYTE2(testQuery.time);
    v23[3] = HIBYTE(testQuery.time);
    v23[2] = BYTE1(testQuery.time);
    v23[0] = testQuery.time;
    v4->Write(this: v4, a2: v23, a3: 4u);
    v24[1] = BYTE2(testQuery.gameMsPerFrame);
    v24[0] = testQuery.gameMsPerFrame;
    v24[3] = HIBYTE(testQuery.gameMsPerFrame);
    v24[2] = BYTE1(testQuery.gameMsPerFrame);
    v4->Write(this: v4, a2: v24, a3: 4u);
    idFile::WriteLittle<idBounds>(this: v4, c: &testQuery.bbox);
    idFile::WriteLittle<idVec3>(this: v4, c: &testQuery.gravity);
    obstacleRadius = testQuery.obstacleRadius;
    v5 = BYTE1(obstacleRadius);
    v6 = HIBYTE(obstacleRadius);
    BYTE1(obstacleRadius) = BYTE2(obstacleRadius);
    HIBYTE(obstacleRadius) = LOBYTE(obstacleRadius);
    LOBYTE(obstacleRadius) = v6;
    BYTE2(obstacleRadius) = v5;
    v4->Write(this: v4, a2: &obstacleRadius, a3: 4u);
    frameMoveDist = testQuery.frameMoveDist;
    v7 = BYTE1(frameMoveDist);
    v8 = HIBYTE(frameMoveDist);
    BYTE1(frameMoveDist) = BYTE2(frameMoveDist);
    HIBYTE(frameMoveDist) = LOBYTE(frameMoveDist);
    LOBYTE(frameMoveDist) = v8;
    BYTE2(frameMoveDist) = v7;
    v4->Write(this: v4, a2: &frameMoveDist, a3: 4u);
    v25[3] = HIBYTE(testQuery.flags);
    v25[2] = BYTE1(testQuery.flags);
    v25[1] = BYTE2(testQuery.flags);
    v25[0] = testQuery.flags;
    v4->Write(this: v4, a2: v25, a3: 4u);
    numObstacles = this->buffers->numObstacles;
    v9 = BYTE2(numObstacles);
    v10 = HIBYTE(numObstacles);
    HIBYTE(numObstacles) = numObstacles;
    BYTE2(numObstacles) = BYTE1(numObstacles);
    BYTE1(numObstacles) = v9;
    LOBYTE(numObstacles) = v10;
    v4->Write(this: v4, a2: &numObstacles, a3: 4u);
    numVertices = this->buffers->numVertices;
    v11 = HIBYTE(numVertices);
    v12 = BYTE2(numVertices);
    BYTE2(numVertices) = BYTE1(numVertices);
    HIBYTE(numVertices) = numVertices;
    BYTE1(numVertices) = v12;
    LOBYTE(numVertices) = v11;
    v4->Write(this: v4, a2: &numVertices, a3: 4u);
    numEdges = this->buffers->numEdges;
    v13 = BYTE1(numEdges);
    v14 = HIBYTE(numEdges);
    BYTE1(numEdges) = BYTE2(numEdges);
    HIBYTE(numEdges) = numEdges;
    LOBYTE(numEdges) = v14;
    BYTE2(numEdges) = v13;
    v4->Write(this: v4, a2: &numEdges, a3: 4u);
    numCorners = this->buffers->numCorners;
    v15 = HIBYTE(numCorners);
    v16 = BYTE1(numCorners);
    BYTE1(numCorners) = BYTE2(numCorners);
    HIBYTE(numCorners) = numCorners;
    LOBYTE(numCorners) = v15;
    BYTE2(numCorners) = v16;
    v4->Write(this: v4, a2: &numCorners, a3: 4u);
    v4->Write(this: v4, a2: this->buffers->route, a3: 336u);
    v4->Write(this: v4, a2: this->buffers->obstacles, a3: 80 * this->buffers->numObstacles);
    v4->Write(this: v4, a2: this->buffers->vertices, a3: 12 * this->buffers->numVertices);
    v4->Write(this: v4, a2: this->buffers->edges, a3: 16 * this->buffers->numEdges);
    v4->Write(this: v4, a2: this->buffers->corners, a3: 16 * this->buffers->numCorners);
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    return 1;
  }
  return result;
}


// ========================================================================
// ?FindPathAroundObstacles@idObstacleAvoidance@@QAA_NAAUobstaclePath_t@@HHABVidBounds@@ABVidVec3@@MMMHABUobstacleRoute_t@@PAUobstacleTraceSet_t@@@Z
// EA  : 0x826BC310
// RVA : 0x006BC310
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
BOOL __fastcall idObstacleAvoidance::FindPathAroundObstacles(
        idObstacleAvoidance *this,
        obstaclePath_t *path,
        const int time,
        const int gameMsPerFrame,
        const idBounds *bbox,
        const idVec3 *gravity,
        double obstacleRadius,
        double frameMoveDist,
        double cornerCircleRadius,
        const int flags,
        const obstacleRoute_t *route,
        obstacleTraceSet_t *traceSet,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        const obstacleRoute_t *a35,
        int a36,
        _DWORD *a37)
{
  float *v37; // r8
  idBounds *v38; // r7
  int v39; // r6
  int v40; // r5
  idObstacleAvoidance *v41; // r3
  double v42; // fp2
  double v43; // fp1
  int v44; // r4
  obstaclePath_t *v45; // r30
  double v46; // fp3
  double v47; // fp28
  double v48; // fp30
  double v49; // fp29
  float *v50; // r22
  float *v51; // r23
  int v52; // r25
  int v53; // r17
  idObstacleAvoidance *v54; // r29
  float *v55; // r21
  float *v56; // r24
  signed int v58; // r18
  char v59; // r9
  float y; // r10
  float z; // r9
  char v62; // r16
  bool useRadarForward; // r15
  float *p_x; // r25
  float *v65; // r27
  double v66; // fp11
  double v67; // fp6
  bool v68; // r3
  double x; // fp0
  double v70; // fp13
  double v71; // fp12
  float *v72; // r11
  float *parms; // r11
  float *v74; // r11
  float *v75; // r11
  float *v76; // r11
  obstacleParms_t *v77; // r28
  idParallelJobList *v78; // r3
  int v79; // r26
  int v80; // r11
  int *v81; // r28
  float *v82; // r7
  float v83; // r4
  float v84; // r3
  float v85; // r11
  float v86; // r10
  float v87; // r9
  int v88; // r11
  idColor *v89; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idRenderWorld *v93; // r3
  int v94; // r27
  _QWORD *v95; // r28
  int v96; // r26
  float v97; // r7
  float v98; // r6
  int v99; // r11
  idColor *v100; // r11
  float v101; // r8
  float v102; // r7
  float v103; // r6
  idRenderWorld *v104; // r3
  BOOL v105; // [sp+64h] [-1110Ch]
  const idVec3 *p_start; // [sp+68h] [-11108h]
  idVec3 v107; // [sp+70h] [-11100h] BYREF
  idVec3 v108; // [sp+80h] [-110F0h] BYREF
  idColor v109; // [sp+90h] [-110E0h] BYREF
  idColor v110; // [sp+A0h] [-110D0h] BYREF
  _BYTE v111[44]; // [sp+B0h] [-110C0h] BYREF
  _QWORD v112[1530]; // [sp+DCh] [-11094h] BYREF
  _DWORD v113[14346]; // [sp+30B0h] [-E0C0h] BYREF

  v43 = ((double (*)(void))RtlCheckStack12)();
  v45 = (obstaclePath_t *)v44;
  v47 = v46;
  v48 = v43;
  v49 = v42;
  v50 = v37;
  *(float *)v44 = a35->areas[0].end.x;
  v51 = (float *)v38;
  *(float *)(v44 + 4) = a35->areas[0].end.y;
  v52 = v39;
  *(float *)(v44 + 8) = a35->areas[0].end.z;
  v53 = v40;
  *(float *)(v44 + 12) = a35->areas[0].end.x;
  p_start = &a35->areas[0].start;
  *(float *)(v44 + 16) = a35->areas[0].end.y;
  *(float *)(v44 + 20) = a35->areas[0].end.z;
  *(_DWORD *)(v44 + 372) = 1;
  v54 = v41;
  *(float *)(v44 + 388) = 0.0;
  *(float *)(v44 + 384) = 0.0;
  *(float *)(v44 + 380) = 0.0;
  *(float *)(v44 + 376) = 0.0;
  *(float *)(v44 + 400) = 0.0;
  *(float *)(v44 + 396) = 0.0;
  *(float *)(v44 + 392) = 0.0;
  *(_DWORD *)(v44 + 404) = -1;
  *(float *)(v44 + 408) = a35->areas[0].start.x;
  *(float *)(v44 + 412) = a35->areas[0].start.y;
  *(float *)(v44 + 416) = a35->areas[0].start.z;
  *(_DWORD *)(v44 + 420) = -1;
  *(float *)(v44 + 424) = a35->areas[0].end.x;
  *(float *)(v44 + 428) = a35->areas[0].end.y;
  *(float *)(v44 + 432) = a35->areas[0].end.z;
  *(_DWORD *)(v44 + 436) = -1;
  v55 = (float *)(v44 + 408);
  *(float *)(v44 + 440) = 1.0e30;
  v56 = (float *)(v44 + 448);
  *(float *)(v44 + 444) = 1.0e30;
  *(float *)(v44 + 460) = 0.0;
  *(float *)(v44 + 456) = 0.0;
  *(float *)(v44 + 452) = 0.0;
  *(float *)(v44 + 448) = 0.0;
  *(float *)(v44 + 464) = 0.0;
  *(float *)(v44 + 468) = a35->areas[0].end.x;
  *(float *)(v44 + 472) = a35->areas[0].end.y;
  *(float *)(v44 + 476) = a35->areas[0].end.z;
  *(float *)(v44 + 480) = a35->areas[0].end.x;
  *(float *)(v44 + 484) = a35->areas[0].end.y;
  *(float *)(v44 + 488) = a35->areas[0].end.z;
  *(_BYTE *)(v44 + 620) = 1;
  *(_BYTE *)(v44 + 621) = 1;
  *(_BYTE *)(v44 + 622) = 1;
  *(_BYTE *)(v44 + 623) = 1;
  *(float *)(v44 + 492) = 0.0;
  *(float *)(v44 + 500) = 0.0;
  *(float *)(v44 + 496) = 0.0;
  *(_DWORD *)(v44 + 504) = -1;
  *(float *)(v44 + 516) = 0.0;
  *(float *)(v44 + 512) = 0.0;
  *(float *)(v44 + 508) = 0.0;
  *(_DWORD *)(v44 + 520) = -1;
  *(float *)(v44 + 532) = 0.0;
  *(float *)(v44 + 528) = 0.0;
  *(float *)(v44 + 524) = 0.0;
  *(_DWORD *)(v44 + 536) = -1;
  *(float *)(v44 + 548) = 0.0;
  *(float *)(v44 + 544) = 0.0;
  *(float *)(v44 + 540) = 0.0;
  *(_DWORD *)(v44 + 552) = -1;
  *(float *)(v44 + 564) = 0.0;
  *(float *)(v44 + 560) = 0.0;
  *(float *)(v44 + 556) = 0.0;
  *(_DWORD *)(v44 + 568) = -1;
  *(float *)(v44 + 580) = 0.0;
  *(float *)(v44 + 576) = 0.0;
  *(float *)(v44 + 572) = 0.0;
  *(_DWORD *)(v44 + 584) = -1;
  *(float *)(v44 + 596) = 0.0;
  *(float *)(v44 + 592) = 0.0;
  *(float *)(v44 + 588) = 0.0;
  *(_DWORD *)(v44 + 600) = -1;
  if ( v41->buffers == nullptr )
    return true;
  if ( aas_skipObstacleAvoidance.valueInteger != 0
    || (v58 = v40 - v41->lastUpdateTime, v59 = _cntlzw(v58), v105 = (v59 & 0x20) != 0, (v59 & 0x20) == 0)
    && (a33 & 1) != 0
    && v41->buffers->numObstacles == 0 )
  {
    obstacleAvoidanceManager->FreeObstacleBuffers(this: obstacleAvoidanceManager, a2: v41);
    return true;
  }
  testQuery.time = v40;
  testQuery.gameMsPerFrame = v39;
  testQuery.bbox = *v38;
  testQuery.gravity.x = *v37;
  testQuery.gravity.y = v37[1];
  testQuery.gravity.z = v37[2];
  testQuery.flags = a33;
  testQuery.obstacleRadius = v43;
  testQuery.frameMoveDist = v42;
  if ( *aas_debugSaveQuery.valueString.data != 0 )
  {
    idObstacleAvoidance::SaveQuery(this: v41, fileName: aas_debugSaveQuery.valueString.data);
    idCVar::SetString(this: &aas_debugSaveQuery, newValue: byte_821DFB74, force: true);
  }
  y = v45->radarForward.y;
  z = v45->radarForward.z;
  v62 = 0;
  useRadarForward = v45->useRadarForward;
  v107.x = v45->radarForward.x;
  v107.y = y;
  v107.z = z;
  if ( v58 <= 0 || v58 >= 3 * v52 )
  {
    v54->lastDir.x = 0.0;
    p_x = &v54->lastDir.x;
    v54->lastDir.z = 0.0;
    v65 = &v54->lastCorner.x;
    v54->lastDir.y = 0.0;
    v54->lastCorner.w = 0.0;
    v54->lastCorner.z = 0.0;
    v54->lastCorner.y = 0.0;
    v54->lastCorner.x = 0.0;
  }
  else
  {
    obstaclePath_t::operator=(this: v45, __that: v54->buffers->path);
    p_x = &v54->lastDir.x;
    v65 = &v54->lastCorner.x;
    v66 = (float)(v45->seekPos[0].x - *v55);
    v67 = (float)(v45->seekPos[0].z - v55[2]);
    v54->lastDir.y = v45->seekPos[0].y - v55[1];
    v54->lastDir.x = v66;
    v54->lastDir.z = v67;
    v54->lastCorner.x = *v56;
    v54->lastCorner.y = v56[1];
    v54->lastCorner.z = v56[2];
    v54->lastCorner.w = v56[3];
    if ( a37 != nullptr )
    {
      memcpy(Dst: a37 + 1024, Src: v54->buffers->traceFractions, Size: 4 * a37[1793]);
      memcpy(Dst: (void *)v54->buffers->traces, Src: a37, Size: 16 * a37[1536]);
      v62 = 1;
      v54->buffers->numTraces = a37[1536];
    }
  }
  v54->lastUpdateTime = v53;
  obstacleRoute_t::operator=(this: v54->buffers->route, __that: a35);
  if ( v62 == 0 && a37 != nullptr )
  {
    memcpy(Dst: (void *)v54->buffers->traces, Src: a37, Size: 16 * a37[1536]);
    v54->buffers->numTraces = a37[1536];
  }
  if ( (_S13_7 & 1) != 0 )
  {
    v68 = singlePush;
  }
  else
  {
    _S13_7 |= 1u;
    v68 = session->GetTitleStorageBool_2(this: session, a2: "oa_singlePush", a3: false);
    singlePush = v68;
  }
  x = v107.x;
  v70 = v107.y;
  v71 = v107.z;
  v54->buffers->parms->path = v54->buffers->path;
  v54->buffers->parms->path->done = false;
  v54->buffers->parms->path->useRadarForward = useRadarForward;
  v72 = (float *)v54->buffers->parms->path;
  v72[152] = x;
  v72[153] = v70;
  v72[154] = v71;
  parms = (float *)v54->buffers->parms;
  *parms = *v51;
  parms[1] = v51[1];
  parms[2] = v51[2];
  parms[3] = v51[3];
  parms[4] = v51[4];
  parms[5] = v51[5];
  v74 = (float *)v54->buffers->parms;
  v74[6] = *v50;
  v74[7] = v50[1];
  v74[8] = v50[2];
  v75 = (float *)v54->buffers->parms;
  v75[9] = *p_x;
  v75[10] = p_x[1];
  v75[11] = p_x[2];
  v76 = (float *)v54->buffers->parms;
  v76[12] = *v65;
  v76[13] = v65[1];
  v76[14] = v65[2];
  v76[15] = v65[3];
  v54->buffers->parms->obstacleRadius = v48;
  v54->buffers->parms->frameMoveDist = v49;
  v54->buffers->parms->cornerCircleRadius = v47;
  v54->buffers->parms->flags = a33;
  v54->buffers->parms->flags |= aas_debugObstacleAvoidance.valueInteger == 0 ? 0 : 0x40;
  v54->buffers->parms->flags |= aas_debugBreakObstacleAvoidance.valueInteger == 0 ? 0 : 0x80;
  v54->buffers->parms->flags |= !v68 ? 0 : 0x200;
  v54->buffers->parms->numObstacles = v54->buffers->numObstacles;
  v54->buffers->parms->numVertices = v54->buffers->numVertices;
  v54->buffers->parms->numEdges = v54->buffers->numEdges;
  v54->buffers->parms->numCorners = v54->buffers->numCorners;
  v54->buffers->parms->numTraces = v54->buffers->numTraces;
  v54->buffers->parms->maxDebugLines = 0;
  v54->buffers->parms->maxDebugText = 0;
  v54->buffers->parms->route = v54->buffers->route;
  v54->buffers->parms->obstacles = v54->buffers->obstacles;
  v54->buffers->parms->vertices = v54->buffers->vertices;
  v54->buffers->parms->edges = v54->buffers->edges;
  v54->buffers->parms->corners = v54->buffers->corners;
  v54->buffers->parms->traces = v54->buffers->traces;
  v54->buffers->parms->traceFractions = v54->buffers->traceFractions;
  v54->buffers->parms->debugLines = nullptr;
  v54->buffers->parms->debugText = nullptr;
  if ( aas_showObstacleAvoidance.valueInteger > 2 || aas_showPathTree.valueInteger != 0 )
    v54->buffers->parms->flags |= 0x20u;
  if ( aas_useObstacleAvoidanceJobs.valueInteger == 1 )
  {
    if ( !v105 )
    {
      v77 = v54->buffers->parms;
      v78 = obstacleAvoidanceManager->GetJobList(this: obstacleAvoidanceManager);
      idParallelJobList::AddJob(this: v78, function: (void (__fastcall *)(void *))ObstacleAvoidanceJob, data: v77);
    }
  }
  else
  {
    v54->buffers->parms->debugLines = (avoidDebugLine_t *)v113;
    v54->buffers->parms->maxDebugLines = 2048;
    v54->buffers->parms->debugText = (avoidDebugText_t *)v111;
    v54->buffers->parms->maxDebugText = 256;
    ObstacleAvoidanceJob(parms: v54->buffers->parms);
    v54->buffers->parms->debugLines = nullptr;
    v54->buffers->parms->debugText = nullptr;
  }
  if ( aas_showObstacleAvoidance.valueInteger > 0 )
  {
    v79 = 0;
    if ( v113[0] != 0 )
    {
      v80 = 0;
      v81 = v113;
      do
      {
        v82 = (float *)&v113[v80 + 1];
        v83 = *(float *)&v113[v80 + 4];
        v84 = *(float *)&v113[v80 + 2];
        v86 = *(float *)&v113[v80 + 5];
        v87 = *(float *)&v113[v80 + 6];
        v85 = *(float *)&v113[v80 + 3];
        v108.x = *v82;
        v108.y = v84;
        v108.z = v85;
        v107.x = v83;
        v107.y = v86;
        v107.z = v87;
        if ( aas_showObstacleAvoidance.valueInteger > 1 )
        {
          idObstacleAvoidance::ProjectTopDown(
            this: v54,
            point: &v108,
            startPos: p_start,
            scale: (float)((float)((float)v48 / aas_showObstacleScale.valueFloat) * (float)2.5));
          idObstacleAvoidance::ProjectTopDown(
            this: v54,
            point: &v107,
            startPos: p_start,
            scale: (float)((float)((float)v48 / aas_showObstacleScale.valueFloat) * (float)2.5));
        }
        v88 = *v81;
        v110 = idColor::colorRed;
        switch ( v88 )
        {
          case 1:
            v89 = &idColor::colorWhite;
            goto LABEL_44;
          case 2:
            v89 = &idColor::colorLtGrey;
            goto LABEL_44;
          case 3:
            v89 = &idColor::colorRed;
            goto LABEL_44;
          case 4:
            v89 = &idColor::colorBlue;
            goto LABEL_44;
          case 5:
            v89 = &idColor::colorGreen;
            goto LABEL_44;
          case 6:
            v89 = &idColor::colorYellow;
            goto LABEL_44;
          case 7:
            v89 = &idColor::colorOrange;
            goto LABEL_44;
          case 8:
            v89 = &idColor::colorPurple;
            goto LABEL_44;
          case 9:
            v89 = &idColor::colorCyan;
            goto LABEL_44;
          case 10:
            v89 = &idColor::colorMagenta;
LABEL_44:
            g = v89->g;
            b = v89->b;
            a = v89->a;
            v110.r = v89->r;
            v110.g = g;
            v110.b = b;
            v110.a = a;
            break;
          default:
            break;
        }
        v93 = common->RW(this: common);
        v93->DebugLine(this: v93, a2: (const idVec4 *)&v110, a3: &v108, a4: &v107, a5: 0, a6: false);
        ++v79;
        v80 = 7 * v79;
        v81 = &v113[7 * v79];
      }
      while ( *v81 != 0 );
    }
    v94 = 0;
    if ( HIDWORD(v112[0]) != 0 )
    {
      v95 = v112;
      v96 = 0;
      do
      {
        v97 = *(float *)&v111[v96 + 36];
        v98 = *(float *)&v111[v96 + 40];
        v108.x = *(float *)&v111[v96 + 32];
        v108.y = v97;
        v108.z = v98;
        if ( aas_showObstacleAvoidance.valueInteger > 1 )
          idObstacleAvoidance::ProjectTopDown(
            this: v54,
            point: &v108,
            startPos: p_start,
            scale: (float)((float)((float)v48 / aas_showObstacleScale.valueFloat) * (float)2.5));
        v99 = *(_DWORD *)v95;
        v109 = idColor::colorRed;
        switch ( v99 )
        {
          case 1:
            v100 = &idColor::colorWhite;
            goto LABEL_61;
          case 2:
            v100 = &idColor::colorLtGrey;
            goto LABEL_61;
          case 3:
            v100 = &idColor::colorRed;
            goto LABEL_61;
          case 4:
            v100 = &idColor::colorBlue;
            goto LABEL_61;
          case 5:
            v100 = &idColor::colorGreen;
            goto LABEL_61;
          case 6:
            v100 = &idColor::colorYellow;
            goto LABEL_61;
          case 7:
            v100 = &idColor::colorOrange;
            goto LABEL_61;
          case 8:
            v100 = &idColor::colorPurple;
            goto LABEL_61;
          case 9:
            v100 = &idColor::colorCyan;
            goto LABEL_61;
          case 10:
            v100 = &idColor::colorMagenta;
LABEL_61:
            v101 = v100->g;
            v102 = v100->b;
            v103 = v100->a;
            v109.r = v100->r;
            v109.g = v101;
            v109.b = v102;
            v109.a = v103;
            break;
          default:
            break;
        }
        v104 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, _BYTE *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v104->DebugText)(
          a1: v104,
          a2: &v111[v96],
          a3: &v108,
          a4: v104->__vftable,
          a5: &v109,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.1);
        ++v94;
        v96 = 48 * v94;
        v95 = &v112[6 * v94];
      }
      while ( *(_DWORD *)v95 != 0 );
    }
  }
  if ( aas_showObstacleAvoidance.valueInteger > 1 )
    idObstacleAvoidance::DrawBox(this: v54, startPos: p_start, radius: v48);
  if ( !v45->startPosValid )
    idLib::Warning(
      fmt: "GetPointOutsideObstacles: no valid start point found outside obstacles startPos (%f %f %f)",
      a35->areas[0].start.x,
      a35->areas[0].start.y,
      a35->areas[0].start.z);
  if ( !v45->seekPosValid )
    idLib::Warning(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v45->seekPos[0].x)),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v45->seekPos[0].y)),
      (unsigned int)COERCE_UNSIGNED_INT64(v45->seekPos[0].y),
      (unsigned int)COERCE_UNSIGNED_INT64(v45->seekPos[0].z),
      v45->seekPos[1].y,
      (unsigned int)COERCE_UNSIGNED_INT64(v45->seekPos[1].z));
  return v45->hasValidPath;
}


// ========================================================================
// __unwind$248849
// EA  : 0x826BD0D0
// RVA : 0x006BD0D0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void _unwind_248849()
{
  _S13_7 &= ~1u;
}


// ========================================================================
// ?TestQuery@idObstacleAvoidance@@QAA_NPBD@Z
// EA  : 0x826BD0F8
// RVA : 0x006BD0F8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

BOOL __fastcall idObstacleAvoidance::TestQuery(idObstacleAvoidance *this, const char *fileName)
{
  idFile *v3; // r3
  idFile *v4; // r30
  BOOL PathAroundObstacles; // r30
  idRenderWorld *v7; // r3
  obstacleTraceSet_t *v8; // [sp+8h] [-338h]
  int v9; // [sp+Ch] [-334h]
  int v10; // [sp+10h] [-330h]
  int v11; // [sp+14h] [-32Ch]
  int v12; // [sp+18h] [-328h]
  int v13; // [sp+1Ch] [-324h]
  int v14; // [sp+20h] [-320h]
  int v15; // [sp+24h] [-31Ch]
  int v16; // [sp+28h] [-318h]
  int v17; // [sp+2Ch] [-314h]
  int v18; // [sp+30h] [-310h]
  int v19; // [sp+34h] [-30Ch]
  int v20; // [sp+38h] [-308h]
  int v21; // [sp+3Ch] [-304h]
  int v22; // [sp+40h] [-300h]
  int v23; // [sp+44h] [-2FCh]
  int v24; // [sp+48h] [-2F8h]
  int v25; // [sp+4Ch] [-2F4h]
  int v26; // [sp+50h] [-2F0h]
  int v27; // [sp+54h] [-2ECh]
  int v28; // [sp+58h] [-2E8h]
  int v29; // [sp+60h] [-2E0h]
  int v30; // [sp+68h] [-2D8h]
  idStr v31; // [sp+70h] [-2D0h] BYREF
  obstaclePath_t v32; // [sp+90h] [-2B0h] BYREF

  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: fileName, a3: 1, a4: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return false;
  v31.len = 0;
  v31.allocedAndFlag = 20;
  v31.data = v31.baseBuffer;
  v31.baseBuffer[0] = 0;
  idFile::ReadString(this: v3, string: &v31);
  if ( idStr::Cmp(s1: v31.data, s2: "ObstacleAvoidanceQuery") != 0 )
  {
    ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
    idStr::FreeData(this: &v31);
    return false;
  }
  idFile::ReadLittle<float>(this: v4, c: &testQuery.time);
  idFile::ReadLittle<float>(this: v4, c: &testQuery.gameMsPerFrame);
  idFile::ReadLittle<idBounds>(this: v4, c: &testQuery.bbox);
  idFile::ReadLittle<idVec3>(this: v4, c: &testQuery.gravity);
  idFile::ReadLittle<float>(this: v4, c: (int *)&testQuery.obstacleRadius);
  idFile::ReadLittle<float>(this: v4, c: (int *)&testQuery.frameMoveDist);
  idFile::ReadLittle<float>(this: v4, c: (int *)&testQuery.circleCornerRadius);
  idFile::ReadLittle<float>(this: v4, c: &testQuery.flags);
  idFile::ReadLittle<float>(this: v4, c: &this->buffers->numObstacles);
  idFile::ReadLittle<float>(this: v4, c: &this->buffers->numVertices);
  idFile::ReadLittle<float>(this: v4, c: &this->buffers->numEdges);
  idFile::ReadLittle<float>(this: v4, c: &this->buffers->numCorners);
  v4->Read(this: v4, a2: this->buffers->route, a3: 336u);
  v4->Read(this: v4, a2: (void *)this->buffers->obstacles, a3: 80 * this->buffers->numObstacles);
  v4->Read(this: v4, a2: this->buffers->vertices, a3: 12 * this->buffers->numVertices);
  v4->Read(this: v4, a2: this->buffers->edges, a3: 16 * this->buffers->numEdges);
  v4->Read(this: v4, a2: (void *)this->buffers->corners, a3: 16 * this->buffers->numCorners);
  ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
  obstaclePath_t::obstaclePath_t(this: &v32);
  PathAroundObstacles = idObstacleAvoidance::FindPathAroundObstacles(
                          this,
                          path: &v32,
                          time: testQuery.time,
                          gameMsPerFrame: testQuery.gameMsPerFrame,
                          bbox: &testQuery.bbox,
                          gravity: &testQuery.gravity,
                          obstacleRadius: testQuery.obstacleRadius,
                          frameMoveDist: testQuery.frameMoveDist,
                          cornerCircleRadius: testQuery.circleCornerRadius,
                          flags: (const int)this->buffers->route,
                          route: (const obstacleRoute_t *)this->buffers,
                          traceSet: v8,
                          a13: v9,
                          a14: v10,
                          a15: v11,
                          a16: v12,
                          a17: v13,
                          a18: v14,
                          a19: v15,
                          a20: v16,
                          a21: v17,
                          a22: v18,
                          a23: v19,
                          a24: v20,
                          a25: v21,
                          a26: v22,
                          a27: v23,
                          a28: v24,
                          a29: v25,
                          a30: v26,
                          a31: v27,
                          a32: v28,
                          a33: testQuery.flags,
                          a34: v29,
                          a35: this->buffers->route,
                          a36: v30,
                          a37: nullptr);
  v7 = common->RW(this: common);
  v7->DebugBounds(
    this: v7,
    a2: (const idVec4 *)&idColor::colorOrange,
    a3: &testQuery.bbox,
    a4: &this->buffers->route->areas[0].start,
    a5: 0,
    a6: false);
  idStr::FreeData(this: &v31);
  return PathAroundObstacles;
}


// ========================================================================
// __unwind$249134
// EA  : 0x826BD3C4
// RVA : 0x006BD3C4
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void _unwind_249134()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 832 + 112));
}


// ========================================================================
// `dynamic initializer for 'aas_showPathTree''
// EA  : 0x8333E6D0
// RVA : 0x0133E6D0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showPathTree__()
{
  idCVar::idCVar(
    this: &aas_showPathTree,
    name: "aas_showPathTree",
    value: "0",
    flags: 1,
    description: "1 = show the path tree when drawing obstacle avoidance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showPathTree__);
}


// ========================================================================
// `dynamic initializer for 'aas_showObstacleAvoidance''
// EA  : 0x8333E728
// RVA : 0x0133E728
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &aas_showObstacleAvoidance,
    name: "aas_showObstacleAvoidance",
    value: "0",
    flags: 2,
    description: "shows obstacles along paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'aas_showObstacleScale''
// EA  : 0x8333E780
// RVA : 0x0133E780
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showObstacleScale__()
{
  idCVar::idCVar(
    this: &aas_showObstacleScale,
    name: "aas_showObstacleScale",
    value: "1",
    flags: 4,
    description: "scale used when rendering the obstacles top down",
    valueMin: 1.0,
    valueMax: 100.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)"_AI_OBSTACLE",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showObstacleScale__);
}


// ========================================================================
// `dynamic initializer for 'aas_skipObstacleAvoidance''
// EA  : 0x8333E7E8
// RVA : 0x0133E7E8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_skipObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &aas_skipObstacleAvoidance,
    name: "aas_skipObstacleAvoidance",
    value: "0",
    flags: 1,
    description: "ignore all dynamic obstacles along paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_skipObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'aas_debugSaveQuery''
// EA  : 0x8333E840
// RVA : 0x0133E840
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_debugSaveQuery__()
{
  idCVar::idCVar(
    this: &aas_debugSaveQuery,
    name: "aas_debugSaveQuery",
    value: &byte_8200D768,
    flags: 0,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_debugSaveQuery__);
}


// ========================================================================
// `dynamic initializer for 'aas_useObstacleAvoidanceJobs''
// EA  : 0x8333E890
// RVA : 0x0133E890
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_useObstacleAvoidanceJobs__()
{
  idCVar::idCVar(
    this: &aas_useObstacleAvoidanceJobs,
    name: "aas_useObstacleAvoidanceJobs",
    value: "1",
    flags: 2,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_useObstacleAvoidanceJobs__);
}


// ========================================================================
// `dynamic initializer for 'aas_debugObstacleAvoidance''
// EA  : 0x8333E8F8
// RVA : 0x0133E8F8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_debugObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &aas_debugObstacleAvoidance,
    name: "aas_debugObstacleAvoidance",
    value: "0",
    flags: 1,
    description: "1 = output debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_debugObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'aas_debugBreakObstacleAvoidance''
// EA  : 0x8333E950
// RVA : 0x0133E950
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_debugBreakObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &aas_debugBreakObstacleAvoidance,
    name: "aas_debugBreakObstacleAvoidance",
    value: "0",
    flags: 1,
    description: "1 = break in SPU job",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_debugBreakObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'testQuery''
// EA  : 0x8333E9A8
// RVA : 0x0133E9A8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

void _dynamic_initializer_for__testQuery__()
{
  int *p_gameMsPerFrame; // r10
  idSysMutex *p_viewNoteMutex; // r11
  int i; // ctr

  p_gameMsPerFrame = &testQuery.gameMsPerFrame;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  for ( i = 6; i != 0; --i )
  {
    ++p_viewNoteMutex;
    *++p_gameMsPerFrame = (int)p_viewNoteMutex->handle;
  }
  testQuery.bbox.b[0].z = 1.0e30;
  testQuery.bbox.b[0].y = 1.0e30;
  testQuery.bbox.b[0].x = 1.0e30;
  testQuery.bbox.b[1].z = -1.0e30;
  testQuery.bbox.b[1].y = -1.0e30;
  testQuery.bbox.b[1].x = -1.0e30;
}


// ========================================================================
// `dynamic initializer for 'register_ObstacleAvoidanceJob''
// EA  : 0x8333EA00
// RVA : 0x0133EA00
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidance.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_ObstacleAvoidanceJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_ObstacleAvoidanceJob,
           function: (void (__fastcall *)(void *))ObstacleAvoidanceJob,
           name: "ObstacleAvoidanceJob");
}

