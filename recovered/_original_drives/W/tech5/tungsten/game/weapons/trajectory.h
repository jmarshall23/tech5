
// ========================================================================
// ?GetTrajectoryParms@idTrajectory_Parabolic@@UAAPAUparms_t@idTrajectory@@H@Z
// EA  : 0x82EDDB80
// RVA : 0x00EDDB80
// PDB : w:\tech5\tungsten\game\weapons\trajectory.h
// ========================================================================

idTrajectory_Parabolic::parabolicParms_t *__fastcall idTrajectory_Parabolic::GetTrajectoryParms(
        idTrajectory_Parabolic *this,
        const int index)
{
  return &this->parms[index];
}


// ========================================================================
// ?GetSimulationResults@idTrajectory_Parabolic@@UBAPBUresults_t@idTrajectory@@H@Z
// EA  : 0x82EDDB90
// RVA : 0x00EDDB90
// PDB : w:\tech5\tungsten\game\weapons\trajectory.h
// ========================================================================

idTrajectory_Parabolic::parabolicResults_t *__fastcall idTrajectory_Parabolic::GetSimulationResults(
        idTrajectory_Parabolic *this,
        const int index)
{
  return &this->results[index];
}

