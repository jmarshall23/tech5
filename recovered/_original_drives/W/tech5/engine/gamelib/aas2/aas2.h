
// ========================================================================
// ??0idAAS2Path@@QAA@XZ
// EA  : 0x826AC3F8
// RVA : 0x006AC3F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2.h
// ========================================================================

idAAS2Path *__fastcall idAAS2Path::idAAS2Path(idAAS2Path *this)
{
  this->type = 10;
  this->moveGoal.x = 0.0;
  this->moveGoal.y = 0.0;
  this->moveGoal.z = 0.0;
  this->moveAreaNum = 0;
  this->firstEdge.toAreaNum = 0;
  this->firstEdge.edgeNum = 0;
  this->firstEdge.edgePoint.x = 0.0;
  this->firstEdge.edgePoint.y = 0.0;
  this->firstEdge.edgePoint.z = 0.0;
  this->reachIndex.value = -1;
  this->travelTime = -1;
  this->traversalIndex = -1;
  this->traversalStart.x = 0.0;
  this->traversalStart.y = 0.0;
  this->traversalStart.z = 0.0;
  this->traversalEnd.x = 0.0;
  this->traversalEnd.y = 0.0;
  this->traversalEnd.z = 0.0;
  this->dependencyIndex.value = -1;
  this->obstacleGoal.x = 0.0;
  this->obstacleGoal.y = 0.0;
  this->obstacleGoal.z = 0.0;
  this->obstacleAreaNum = 0;
  this->pathMaxHeight = 0.0;
  this->obstacleRoute.numAreas = 0;
  this->obstacleRoute.pad[0] = 0;
  this->obstacleRoute.pad[1] = 0;
  this->obstacleRoute.endAlignDir.x = 0.0;
  this->obstacleRoute.endAlignDir.y = 0.0;
  this->obstacleRoute.endAlignDir.z = 0.0;
  this->obstacleRoute.endTurnRadius = 0.0;
  obstacleRoute_t::Clear(this: &this->obstacleRoute);
  return this;
}

