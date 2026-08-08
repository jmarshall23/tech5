
// ========================================================================
// ??0Orienter@bfx@@QAA@PAVSpace@1@PBUMoverTune@1@@Z
// EA  : 0x832ADF48
// RVA : 0x012ADF48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.h
// ========================================================================

bfx::Orienter *__fastcall bfx::Orienter::Orienter(bfx::Orienter *this, bfx::Space *pSpace, const bfx::MoverTune *pTune)
{
  this->m_pSpace = pSpace;
  this->m_pTune = pTune;
  this->m_state = FACE_IN_TRAVEL_DIR;
  this->m_heading = 0.0;
  this->m_accelMode = HIGH_ACCEL_MODE;
  this->m_headingVel = 0.0;
  this->m_clientSpecifiedRotSpeed = 0.0;
  memcpy(Dst: &this->m_headingFrameMatrix, Src: &bfx::IDENTITY, Size: sizeof(this->m_headingFrameMatrix));
  this->m_targetPos.m_x = 0.0;
  this->m_targetPos.m_y = 0.0;
  this->m_targetPos.m_z = 0.0;
  this->m_dir.m_x = 0.0;
  this->m_dir.m_y = 0.0;
  this->m_dir.m_z = 0.0;
  this->m_slerpStartRot = bfx::IDENTITY_QUAT;
  this->m_slerping = false;
  this->m_slerpTimer = 0.0;
  this->m_areaIsFull3D = false;
  this->m_slerpDuration = 0.25;
  return this;
}

