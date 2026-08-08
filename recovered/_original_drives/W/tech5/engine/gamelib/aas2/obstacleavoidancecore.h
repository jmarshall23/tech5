
// ========================================================================
// ?Clear@obstacleRoute_t@@QAAXXZ
// EA  : 0x826AB228
// RVA : 0x006AB228
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.h
// ========================================================================

void __fastcall obstacleRoute_t::Clear(obstacleRoute_t *this)
{
  float *p_y; // r11
  int v2; // ctr

  p_y = &this->endAlignDir.y;
  this->numAreas = 0;
  this->endAlignDir.z = 0.0;
  v2 = 11;
  this->endAlignDir.y = 0.0;
  this->endAlignDir.x = 0.0;
  this->endTurnRadius = 0.0;
  do
  {
    p_y[3] = 0.0;
    p_y[6] = 0.0;
    p_y[5] = 0.0;
    p_y[4] = 0.0;
    p_y[9] = 0.0;
    p_y[8] = 0.0;
    p_y += 7;
    *p_y = 0.0;
    --v2;
  }
  while ( v2 != 0 );
}


// ========================================================================
// ??0obstacleRoute_t@@QAA@XZ
// EA  : 0x826AC248
// RVA : 0x006AC248
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.h
// ========================================================================

obstacleRoute_t *__fastcall obstacleRoute_t::obstacleRoute_t(obstacleRoute_t *this)
{
  this->numAreas = 0;
  this->pad[0] = 0;
  this->pad[1] = 0;
  this->endAlignDir.x = 0.0;
  this->endAlignDir.y = 0.0;
  this->endAlignDir.z = 0.0;
  this->endTurnRadius = 0.0;
  obstacleRoute_t::Clear(this);
  return this;
}


// ========================================================================
// ??0obstaclePath_t@@QAA@XZ
// EA  : 0x826AC2A0
// RVA : 0x006AC2A0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.h
// ========================================================================

obstaclePath_t *__fastcall obstaclePath_t::obstaclePath_t(obstaclePath_t *this)
{
  this->numSeekPos = 0;
  this->firstObstaclePosition.x = 0.0;
  this->firstObstaclePosition.y = 0.0;
  this->firstObstaclePosition.z = 0.0;
  this->firstObstacle = -1;
  this->startPosOutsideObstacles.x = 0.0;
  this->startPosOutsideObstacles.y = 0.0;
  this->startPosOutsideObstacles.z = 0.0;
  this->startPosObstacle = -1;
  this->seekPosOutsideObstacles.x = 0.0;
  this->seekPosOutsideObstacles.y = 0.0;
  this->seekPosOutsideObstacles.z = 0.0;
  this->seekPosObstacle = -1;
  this->targetDist = 0.0;
  this->pathLength = 0.0;
  this->nextCorner.x = 0.0;
  this->nextCorner.y = 0.0;
  this->nextCorner.z = 0.0;
  this->nextCorner.w = 0.0;
  this->nextCornerAngle = 0.0;
  this->radar[0].obstacle = 0;
  this->radar[0].direction.z = 0.0;
  this->radar[1].obstacle = 0;
  this->radar[0].direction.y = 0.0;
  this->radar[2].obstacle = 0;
  this->radar[0].direction.x = 0.0;
  this->radar[3].obstacle = 0;
  this->radar[1].direction.z = 0.0;
  this->radar[4].obstacle = 0;
  this->radar[1].direction.y = 0.0;
  this->radar[5].obstacle = 0;
  this->radar[1].direction.x = 0.0;
  this->radar[6].obstacle = 0;
  this->radar[2].direction.z = 0.0;
  this->radar[2].direction.y = 0.0;
  this->radar[2].direction.x = 0.0;
  this->radar[3].direction.z = 0.0;
  this->radar[3].direction.y = 0.0;
  this->radar[3].direction.x = 0.0;
  this->radar[4].direction.z = 0.0;
  this->radar[4].direction.y = 0.0;
  this->radar[4].direction.x = 0.0;
  this->radar[5].direction.z = 0.0;
  this->radar[5].direction.y = 0.0;
  this->radar[5].direction.x = 0.0;
  this->radar[6].direction.z = 0.0;
  this->radar[6].direction.y = 0.0;
  this->radar[6].direction.x = 0.0;
  this->useRadarForward = false;
  this->radarForward.x = 0.0;
  this->radarForward.y = 0.0;
  this->radarForward.z = 0.0;
  this->hasValidPath = false;
  this->startPosValid = false;
  this->seekPosValid = false;
  this->done = false;
  memset(Dst: this, Val: 0, Size: 0x174u);
  this->seekPosPlane.d = 0.0;
  this->seekPosPlane.c = 0.0;
  this->seekPosPlane.b = 0.0;
  this->seekPosPlane.a = 0.0;
  this->wallCorners[0].z = 0.0;
  this->wallCorners[0].y = 0.0;
  this->wallCorners[0].x = 0.0;
  this->wallCorners[1].z = 0.0;
  this->wallCorners[1].y = 0.0;
  this->wallCorners[1].x = 0.0;
  return this;
}

