
// ========================================================================
// ?Zero@impactInfo_t@@QAAXXZ
// EA  : 0x8275B3F0
// RVA : 0x0075B3F0
// PDB : w:\tech5\engine\gamelib\physics\physics.h
// ========================================================================

void __fastcall impactInfo_t::Zero(impactInfo_t *this)
{
  int v1; // r9
  int v2; // r11
  int i; // ctr
  int v4; // r10

  v1 = 0;
  this->invMass = 0.0;
  do
  {
    v2 = 0;
    for ( i = 3; i != 0; --i )
    {
      v4 = v1 + v2++ + 1;
      *(&this->invMass + v4) = 0.0;
    }
    v1 += 3;
  }
  while ( v1 < 9 );
  this->position.z = 0.0;
  this->position.y = 0.0;
  this->position.x = 0.0;
  this->velocity.z = 0.0;
  this->velocity.y = 0.0;
  this->velocity.x = 0.0;
}

