
// ========================================================================
// ?GetWeight@idFriendlyTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B031C0
// RVA : 0x00B031C0
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\friendlytargetselector.cpp
// ========================================================================

float __fastcall idFriendlyTargetSelector::GetWeight(
        idFriendlyTargetSelector *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  double v5; // fp31
  double v6; // fp30
  double v7; // fp10
  unsigned int curAwareness; // r11
  double v11; // fp1

  if ( ti->es == nullptr || idAIEntityState::IsDead(this: (idAIEntityState *)ti->es) )
    goto LABEL_9;
  v5 = (float)((float)(this->ownerDir.x * ti->dirTo.x)
             + (float)((float)(this->ownerDir.z * ti->dirTo.z) + (float)(this->ownerDir.y * ti->dirTo.y)));
  v6 = idRelationship::FloatForAttitude(attitude: (idRelationship::attitude_t)ti->attitude);
  v7 = (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)ti->es) != 0 ? 1.0 : 0.5;
  curAwareness = ti->es->curAwareness;
  _FP5 = (float)((float)(ti->distSqr * (float)0.00000023841858) - (float)1.0);
  __asm { fsel      f3, f5, f0, f8 }
  v11 = (float)((float)((float)((float)((float)v6 * (float)0.16666667) * (float)0.5)
                      + (float)((float)((float)((float)1.0 - (float)_FP3) * (float)0.25)
                              + (float)((float)((float)((float)v5 + (float)1.0) * (float)0.5) * (float)0.25)))
              * (float)v7);
  if ( curAwareness < 2 )
  {
LABEL_9:
    v11 = 0.0;
  }
  else if ( curAwareness == 2 )
  {
    v11 = (float)((float)((float)((float)((float)((float)v6 * (float)0.16666667) * (float)0.5)
                                + (float)((float)((float)((float)1.0 - (float)_FP3) * (float)0.25)
                                        + (float)((float)((float)((float)v5 + (float)1.0) * (float)0.5) * (float)0.25)))
                        * (float)v7)
                * (float)0.5);
  }
  return *((float *)&v11 + 1);
}

