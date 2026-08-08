
// ========================================================================
// ?Clamp@idAngles@@QAAXABV1@0@Z
// EA  : 0x82B73DB8
// RVA : 0x00B73DB8
// PDB : w:\tech5\shared\idlib\math\angles.h
// ========================================================================

void __fastcall idAngles::Clamp(idAngles *this, const idAngles *min, const idAngles *max)
{
  double pitch; // fp0
  double v4; // fp13
  double yaw; // fp13
  double v6; // fp0
  double roll; // fp13
  double v8; // fp0

  pitch = this->pitch;
  v4 = min->pitch;
  if ( pitch < v4 || (v4 = max->pitch, pitch > v4) )
    this->pitch = v4;
  yaw = min->yaw;
  v6 = this->yaw;
  if ( v6 < yaw || (yaw = max->yaw, v6 > yaw) )
    this->yaw = yaw;
  roll = min->roll;
  v8 = this->roll;
  if ( v8 < roll || (roll = max->roll, v8 > roll) )
    this->roll = roll;
}


// ========================================================================
// ?Compare@idAngles@@QBA_NABV1@M@Z
// EA  : 0x82D58AD8
// RVA : 0x00D58AD8
// PDB : w:\tech5\shared\idlib\math\angles.h
// ========================================================================

int __fastcall idAngles::Compare(idAngles *this, const idAngles *a, double epsilon)
{
  double v3; // fp0
  int result; // r3
  double v5; // fp0
  double v6; // fp0

  v3 = (float)(this->pitch - a->pitch);
  if ( __fabs(v3) > epsilon && __fabs(v3) < (float)((float)360.0 - (float)epsilon) )
    return 0;
  v5 = (float)(this->yaw - a->yaw);
  if ( __fabs(v5) > epsilon && __fabs(v5) < (float)((float)360.0 - (float)epsilon) )
    return 0;
  v6 = (float)(this->roll - a->roll);
  if ( __fabs(v6) <= epsilon )
    return 1;
  result = 0;
  if ( __fabs(v6) >= (float)((float)360.0 - (float)epsilon) )
    return 1;
  return result;
}

