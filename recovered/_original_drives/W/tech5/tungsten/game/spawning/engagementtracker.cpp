
// ========================================================================
// ?Update@idEngagementTracker@@QAAXM@Z
// EA  : 0x82EA5F28
// RVA : 0x00EA5F28
// PDB : w:\tech5\tungsten\game\spawning\engagementtracker.cpp
// ========================================================================

void __fastcall idEngagementTracker::Update(idEngagementTracker *this, double elapsedTime)
{
  double nonPlayerEngagementTimer; // fp0

  nonPlayerEngagementTimer = this->nonPlayerEngagementTimer;
  this->isEngaged = false;
  if ( nonPlayerEngagementTimer > 0.0 )
  {
    this->nonPlayerEngagementTimer = (float)nonPlayerEngagementTimer - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[0] > 0.0 )
  {
    this->playerEngagementTimers[0] = this->playerEngagementTimers[0] - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[1] > 0.0 )
  {
    this->playerEngagementTimers[1] = this->playerEngagementTimers[1] - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[2] > 0.0 )
  {
    this->playerEngagementTimers[2] = this->playerEngagementTimers[2] - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[3] > 0.0 )
  {
    this->playerEngagementTimers[3] = this->playerEngagementTimers[3] - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[4] > 0.0 )
  {
    this->playerEngagementTimers[4] = this->playerEngagementTimers[4] - (float)elapsedTime;
    this->isEngaged = true;
  }
  if ( this->playerEngagementTimers[5] > 0.0 )
  {
    this->playerEngagementTimers[5] = this->playerEngagementTimers[5] - (float)elapsedTime;
    this->isEngaged = true;
  }
}


// ========================================================================
// ?OnEngaged@idEngagementTracker@@QAAXPBVidEntity@@M@Z
// EA  : 0x82EA5FE8
// RVA : 0x00EA5FE8
// PDB : w:\tech5\tungsten\game\spawning\engagementtracker.cpp
// ========================================================================

void __fastcall idEngagementTracker::OnEngaged(
        idEngagementTracker *this,
        idPlayer *attacker,
        double engagementTimeOverride)
{
  idPlayer *v5; // r3

  v5 = idPlayer::CastTo(c: attacker);
  if ( v5 != nullptr )
  {
    if ( engagementTimeOverride == 0.0 )
      engagementTimeOverride = 3.0;
    this->playerEngagementTimers[v5->entityNumber] = engagementTimeOverride;
    this->isEngaged = true;
  }
  else
  {
    this->lastNonPlayerEngagementTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( engagementTimeOverride == 0.0 )
      engagementTimeOverride = 3.0;
    this->nonPlayerEngagementTimer = engagementTimeOverride;
    this->isEngaged = true;
  }
}

