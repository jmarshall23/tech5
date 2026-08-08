
// ========================================================================
// ??0botPathInfo_t@idBotMoveState@@QAA@XZ
// EA  : 0x82B42870
// RVA : 0x00B42870
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.h
// ========================================================================

idBotMoveState::botPathInfo_t *__fastcall idBotMoveState::botPathInfo_t::botPathInfo_t(
        idBotMoveState::botPathInfo_t *this)
{
  float z; // r6

  this->hasPath = false;
  this->hasClearPath = false;
  this->nextMovePointIsGoal = false;
  this->radarValid = false;
  this->nextMovePoint.x = vec3_origin.x;
  this->nextMovePoint.y = vec3_origin.y;
  z = vec3_origin.z;
  this->aas = nullptr;
  this->nextMovePoint.z = z;
  idAAS2Path::idAAS2Path(this: &this->path);
  obstaclePath_t::obstaclePath_t(this: &this->obstacleAvoidanceInfo);
  idObstacleAvoidance::idObstacleAvoidance(this: &this->obstacleAvoidance);
  return this;
}

