
// ========================================================================
// ?NumVertsPerParticle@idParticleStage@@QBAHXZ
// EA  : 0x827DE298
// RVA : 0x007DE298
// PDB : w:\tech5\engine\models\particles\jobs\particlestage.h
// ========================================================================

int __fastcall idParticleStage::NumVertsPerParticle(idParticleStage *this)
{
  if ( this->staticData != nullptr )
    return this->numStaticVerts;
  if ( this->orientation.type == POR_TRAIL )
    return 4 * (this->orientation.numTrails + 1);
  return 4;
}

