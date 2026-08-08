
// ========================================================================
// ?Emit@idSmokeEmitter@@QAA_NABVidVec3@@@Z
// EA  : 0x82BE0C00
// RVA : 0x00BE0C00
// PDB : w:\tech5\tungsten\game\effects\gameeffects.cpp
// ========================================================================

int __fastcall idSmokeEmitter::Emit(idSmokeEmitter *this, const idVec3 *velocity)
{
  idTreeAnimator *ta; // r3
  __int64 v5; // r9
  unsigned int v6; // r5
  double v7; // fp31
  int GameMsPerFrame; // r27
  int GameMs; // r31
  const idDeclParticle *particle; // r30
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v12; // r7
  int v14; // [sp+8h] [-D8h]
  int v15; // [sp+Ch] [-D4h]
  int v16; // [sp+10h] [-D0h]
  int v17; // [sp+14h] [-CCh]
  int v18; // [sp+18h] [-C8h]
  int v19; // [sp+1Ch] [-C4h]
  int v20; // [sp+20h] [-C0h]
  int v21; // [sp+24h] [-BCh]
  int v22; // [sp+28h] [-B8h]
  int v23; // [sp+2Ch] [-B4h]
  int v24; // [sp+30h] [-B0h]
  int v25; // [sp+34h] [-ACh]
  int v26; // [sp+38h] [-A8h]
  int v27; // [sp+3Ch] [-A4h]
  int v28; // [sp+40h] [-A0h]
  int v29; // [sp+44h] [-9Ch]
  int v30; // [sp+48h] [-98h]
  int v31; // [sp+4Ch] [-94h]
  int v32; // [sp+50h] [-90h]
  unsigned int v33; // [sp+60h] [-80h] BYREF
  __int64 v34; // [sp+68h] [-78h]
  idMat3 v35; // [sp+70h] [-70h] BYREF

  ta = this->ta;
  if ( ta == nullptr
    || this->tag.parentJoint.value == 0xFFFF
    || (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                          this: ta,
                          tagData: &this->tag,
                          origin: v35.mat,
                          axis: (idMat3 *)&v35.mat[1].y) == 0 )
  {
    return 0;
  }
  v33 = -1;
  HIDWORD(v5) = 458752;
  v6 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v6 + 1013904223;
  LODWORD(v5) = ((v6 + 1013904223) >> 10) & 0x7FFF;
  v34 = v5;
  v7 = (float)((float)v5 * (float)0.000030518509);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  particle = this->particle;
  MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
  return idRenderModelEffects::AddParticles(
           this: MergeBranch,
           particle,
           systemStartTime: GameMs,
           gameMsPerFrame: GameMsPerFrame,
           diversity: v7,
           origin: v12,
           axis: &v35,
           velocity: (const idVec3 *)&v35.mat[1].y,
           color: &velocity->x,
           a10: v14,
           a11: v15,
           a12: v16,
           a13: v17,
           a14: v18,
           a15: v19,
           a16: v20,
           a17: v21,
           a18: v22,
           a19: v23,
           a20: v24,
           a21: v25,
           a22: v26,
           a23: v27,
           a24: v28,
           a25: v29,
           a26: v30,
           a27: v31,
           a28: v32,
           a29: &v33);
}


// ========================================================================
// ?Fade@idFadeHelper@@QAAXABM0ABH_N@Z
// EA  : 0x82BE0D20
// RVA : 0x00BE0D20
// PDB : w:\tech5\tungsten\game\effects\gameeffects.cpp
// ========================================================================

void __fastcall idFadeHelper::Fade(idFadeHelper *this, float *from, float *to, const int *time, bool _noStippleFade)
{
  int GameMs; // r3
  int v9; // r10

  this->fadeFrom = *from;
  this->fadeTo = *to;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->fadeStartTime = GameMs;
  v9 = *time + GameMs;
  this->noStippleFade = _noStippleFade;
  this->fadeEndTime = v9;
}


// ========================================================================
// ?Update@idFadeHelper@@QAA_NPAVidPresentable@@@Z
// EA  : 0x82BE0D80
// RVA : 0x00BE0D80
// PDB : w:\tech5\tungsten\game\effects\gameeffects.cpp
// ========================================================================

int __fastcall idFadeHelper::Update(idFadeHelper *this, idPresentable *presentable)
{
  int v4; // r27
  __int128 v5; // r9
  double fadeTo; // fp31

  v4 = 0;
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->fadeEndTime )
  {
    fadeTo = this->fadeTo;
    this->fadeEndTime = -1;
  }
  else
  {
    LODWORD(v5) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    DWORD2(v5) = this->fadeStartTime;
    DWORD1(v5) = this->fadeEndTime;
    v4 = 1;
    fadeTo = (float)((float)((float)((float)((float)(__int64)v5 - (float)*(__int64 *)((char *)&v5 + 4))
                                   / (float)((float)*(__int64 *)&v5 - (float)*(__int64 *)((char *)&v5 + 4)))
                           * (float)(this->fadeTo - this->fadeFrom))
                   + this->fadeFrom);
  }
  if ( presentable != nullptr )
  {
    idPresentable::SetParm(this: presentable, parm: rp->coverage, scalar: fadeTo);
    if ( !this->noStippleFade )
      idRenderModel::SetModelFade(this: presentable->model, v: fadeTo);
    presentable->Present(this: presentable);
  }
  return v4;
}

