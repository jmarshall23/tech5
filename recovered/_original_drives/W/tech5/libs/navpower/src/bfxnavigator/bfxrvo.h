
// ========================================================================
// ??1RepulsorsForRVO@bfx@@QAA@XZ
// EA  : 0x83261F00
// RVA : 0x01261F00
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.h
// ========================================================================

void __fastcall bfx::RepulsorsForRVO::~RepulsorsForRVO(bfx::RepulsorsForRVO *this)
{
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_pRecs);
}


// ========================================================================
// ?ApplyMatrixToAllPositions@RVODebugDrawInfo@bfx@@QAAXABVMatrix@2@@Z
// EA  : 0x832CB620
// RVA : 0x012CB620
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrvo.h
// ========================================================================

void __fastcall bfx::RVODebugDrawInfo::ApplyMatrixToAllPositions(bfx::RVODebugDrawInfo *this, bfx::Vec3 *mat)
{
  bfx::Matrix *v4; // r3
  bfx::Matrix *v5; // r3
  bfx::Matrix *v6; // r3
  bfx::Matrix *v7; // r3
  bfx::Vec3 *m_velCircPt; // r29
  int v9; // r28
  bfx::Matrix *v10; // r3
  bfx::Matrix v11; // [sp+50h] [-50h] BYREF

  v4 = bfx::Matrix::operator*(this: &v11, result: mat, rhs: &this->m_startPos1);
  this->m_startPos1.m_x = v4->m_data[0];
  this->m_startPos1.m_y = v4->m_data[1];
  this->m_startPos1.m_z = v4->m_data[2];
  v5 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v11.m_data[4], result: mat, rhs: &this->m_startPos2);
  this->m_startPos2.m_x = v5->m_data[0];
  this->m_startPos2.m_y = v5->m_data[1];
  this->m_startPos2.m_z = v5->m_data[2];
  v6 = bfx::Matrix::operator*(this: &v11, result: mat, rhs: &this->m_myPos);
  this->m_myPos.m_x = v6->m_data[0];
  this->m_myPos.m_y = v6->m_data[1];
  this->m_myPos.m_z = v6->m_data[2];
  v7 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v11.m_data[4], result: mat, rhs: &this->m_velocityCircleCenter);
  this->m_velocityCircleCenter.m_x = v7->m_data[0];
  m_velCircPt = this->m_velCircPt;
  v9 = 4;
  this->m_velocityCircleCenter.m_y = v7->m_data[1];
  this->m_velocityCircleCenter.m_z = v7->m_data[2];
  do
  {
    v10 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v11.m_data[4], result: mat, rhs: m_velCircPt);
    m_velCircPt->m_x = v10->m_data[0];
    --v9;
    m_velCircPt->m_y = v10->m_data[1];
    m_velCircPt->m_z = v10->m_data[2];
    ++m_velCircPt;
  }
  while ( v9 != 0 );
}

