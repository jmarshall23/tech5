
// ========================================================================
// ??0animDeltaCorrection_t@@QAA@XZ
// EA  : 0x82A6C5E8
// RVA : 0x00A6C5E8
// PDB : w:\tech5\tungsten\game\ai\aidefs.h
// ========================================================================

animDeltaCorrection_t *__fastcall animDeltaCorrection_t::animDeltaCorrection_t(animDeltaCorrection_t *this)
{
  int v1; // ctr
  float *p_z; // r8
  float *p_y; // r10
  _DWORD *v4; // r8
  float *v5; // r10
  int i; // ctr
  aiAnimDCIdealDir_t *p_idealDirOverride; // r7
  int v8; // ctr
  float *v9; // r8
  float z; // r6
  float *v11; // r7
  float *v12; // r8
  int j; // ctr
  float *v14; // r7
  int v15; // ctr
  float *v16; // r8
  float v17; // r4
  float *v18; // r7
  float *v19; // r8
  int k; // ctr
  char v21; // r5
  float *p_previousRemainingRotationFramesToGoal; // r8
  float *v23; // r9
  int v24; // ctr
  char v25; // r8
  float v26; // r5

  v1 = 9;
  p_z = &this->animEndTranslation.z;
  p_y = &mat2_identity.mat[1].y;
  this->endPoint = vec3_origin;
  this->endDir = vec3_origin;
  this->animEndTranslation = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v1;
  }
  while ( v1 != 0 );
  v4 = (_DWORD *)((char *)this + 72);
  v5 = &mat2_identity.mat[1].y;
  *((_BYTE *)this + 72) &= 0x3Fu;
  for ( i = 9; i != 0; --i )
    *++v4 = *(_DWORD *)++v5;
  *((_BYTE *)this + 112) &= ~0x80u;
  this->startOrigin.x = vec3_origin.x;
  p_idealDirOverride = &this->idealDirOverride;
  v8 = 9;
  this->startOrigin.y = vec3_origin.y;
  v9 = &mat2_identity.mat[1].y;
  z = vec3_origin.z;
  this->idealPoint = IDEALPOINT_NONE;
  this->idealPointOverride = IDEALPOINT_NONE;
  this->startOrigin.z = z;
  this->animSpaceEndTranslation = vec3_origin;
  this->animSpaceGoalTranslation = vec3_origin;
  this->translationEndTime = 0;
  this->idealDir = IDEALDIR_NONE;
  this->idealDirOverride = IDEALDIR_NONE;
  do
  {
    *++p_idealDirOverride = *(aiAnimDCIdealDir_t *)++v9;
    --v8;
  }
  while ( v8 != 0 );
  v11 = &this->animSpaceEndRotation.mat[2].z;
  v12 = &mat2_identity.mat[1].y;
  for ( j = 9; j != 0; --j )
    *++v11 = *++v12;
  v14 = &this->currentAnimnodeOrigin.z;
  this->animSpaceEndRotation_Translation = vec3_origin;
  v15 = 9;
  v16 = &mat2_identity.mat[1].y;
  this->animSpaceGoalRotation_Translation.x = vec3_origin.x;
  this->animSpaceGoalRotation_Translation.y = vec3_origin.y;
  v17 = vec3_origin.z;
  this->rotationEndTime = 0;
  this->rotationGoalTime = 0;
  this->animSpaceGoalRotation_Translation.z = v17;
  this->currentAnimnodeOrigin = vec3_origin;
  do
  {
    *++v14 = *++v16;
    --v15;
  }
  while ( v15 != 0 );
  v18 = &this->currentRefOrigin.z;
  v19 = &mat2_identity.mat[1].y;
  this->currentRefOrigin = vec3_origin;
  for ( k = 9; k != 0; --k )
    *++v18 = *++v19;
  v21 = *((_BYTE *)this + 372);
  this->anim = nullptr;
  this->node = nullptr;
  p_previousRemainingRotationFramesToGoal = &this->previousRemainingRotationFramesToGoal;
  *((_BYTE *)this + 372) = v21 & 0xF;
  v23 = &mat2_identity.mat[1].y;
  this->previousRemainingTranslationFrames = 0.0;
  v24 = 9;
  this->previousRemainingRotationFrames = 0.0;
  this->previousRemainingRotationFramesToGoal = 0.0;
  do
  {
    *++p_previousRemainingRotationFramesToGoal = *++v23;
    --v24;
  }
  while ( v24 != 0 );
  this->skipFirstFrame = false;
  this->in.translationCorrectionMaxScale = 0.0;
  v25 = *((_BYTE *)&this->in + 41) & 3 | 0x40;
  this->in.translationCorrectionPerFrameMax = vec3_origin;
  this->in.translationPerFrameMax.x = vec3_origin.x;
  this->in.translationPerFrameMax.y = vec3_origin.y;
  v26 = vec3_origin.z;
  this->in.rotationMaxScale = 0.0;
  this->in.rotationMinScale = 0.0;
  *((_BYTE *)&this->in + 40) = 0;
  this->in.rotationRateMax = 0.0;
  *((_BYTE *)&this->in + 41) = v25;
  this->in.translationPerFrameMax.z = v26;
  return this;
}

