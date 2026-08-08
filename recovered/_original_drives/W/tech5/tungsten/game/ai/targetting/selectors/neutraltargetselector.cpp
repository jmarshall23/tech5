
// ========================================================================
// ?GetWeight@idNeutralTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B032F0
// RVA : 0x00B032F0
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\neutraltargetselector.cpp
// ========================================================================

float __fastcall idNeutralTargetSelector::GetWeight(
        idNeutralTargetSelector *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  double v5; // fp1
  double v6; // fp31
  double v7; // fp10
  double v10; // fp13
  unsigned int curAwareness; // r11

  if ( ti->es == nullptr || idAIEntityState::IsDead(this: (idAIEntityState *)ti->es) )
  {
    v5 = 0.0;
  }
  else
  {
    v6 = (float)((float)(this->ownerDir.x * ti->dirTo.x)
               + (float)((float)(this->ownerDir.z * ti->dirTo.z) + (float)(this->ownerDir.y * ti->dirTo.y)));
    if ( (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)ti->es) != 0 )
      v7 = 1.0;
    else
      v7 = 0.5;
    _FP7 = (float)((float)(ti->distSqr * (float)0.00000023841858) - (float)1.0);
    __asm { fsel      f6, f7, f0, f8 }
    if ( v6 <= -0.96592599 )
      v10 = 0.0;
    else
      v10 = (float)((float)((float)v6 + (float)1.0) * (float)0.5);
    curAwareness = ti->es->curAwareness;
    v5 = (float)((float)((float)((float)v10 * (float)0.2)
                       + (float)((float)((float)1.0 - (float)_FP6) * (float)0.80000001))
               * (float)v7);
    if ( curAwareness < 2 )
    {
      v5 = 0.0;
    }
    else if ( curAwareness == 2 )
    {
      v5 = (float)((float)((float)((float)((float)v10 * (float)0.2)
                                 + (float)((float)((float)1.0 - (float)_FP6) * (float)0.80000001))
                         * (float)v7)
                 * (float)0.5);
    }
  }
  return *((float *)&v5 + 1);
}

