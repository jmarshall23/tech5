
// ========================================================================
// ?PostSerializeRead@idPresentableParticleEmitter@@UAAX_N@Z
// EA  : 0x82B71F78
// RVA : 0x00B71F78
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::PostSerializeRead(
        idPresentableParticleEmitter *this,
        bool firstClientFrame)
{
  int count; // r10
  char v4; // r11
  int v5; // r10
  char v6; // r11

  idPresentable::PostSerializeRead(this, firstClientFrame);
  count = this->activated.count;
  if ( count == this->activated.lastCount )
  {
    v4 = 0;
  }
  else
  {
    this->activated.lastCount = count;
    v4 = 1;
  }
  if ( v4 != 0 )
    this->TriggerShow(this);
  v5 = this->deactivated.count;
  if ( v5 == this->deactivated.lastCount )
  {
    v6 = 0;
  }
  else
  {
    this->deactivated.lastCount = v5;
    v6 = 1;
  }
  if ( v6 != 0 )
    this->TriggerHide(this);
}


// ========================================================================
// ?ClientThink@idPresentableParticleEmitter@@UAAXHM_N@Z
// EA  : 0x82B72030
// RVA : 0x00B72030
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::ClientThink(
        idPresentableParticleEmitter *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  int v6; // r3
  signed int smokeSystemRate; // r8
  char v8; // r11
  __int64 v9; // r9
  unsigned int v10; // r5
  double v11; // fp31
  int GameMsPerFrame; // r28
  int GameMs; // r30
  const idDeclParticle *particleSystem; // r29
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v16; // r7
  int v17; // [sp+8h] [-A8h]
  int v18; // [sp+Ch] [-A4h]
  int v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]
  int v27; // [sp+30h] [-80h]
  int v28; // [sp+34h] [-7Ch]
  int v29; // [sp+38h] [-78h]
  int v30; // [sp+3Ch] [-74h]
  int v31; // [sp+40h] [-70h]
  int v32; // [sp+44h] [-6Ch]
  int v33; // [sp+48h] [-68h]
  int v34; // [sp+4Ch] [-64h]
  int v35; // [sp+50h] [-60h]
  unsigned int v36; // [sp+60h] [-50h] BYREF
  __int64 v37; // [sp+68h] [-48h]

  idPresentable::ClientThink(this, curTime, fraction, predict, a5);
  if ( this->fade.fadeEndTime > 0 )
    idFadeHelper::Update(this: &this->fade, presentable: this);
  if ( this->useSmokeSystem )
  {
    if ( this->smokeSystemRate == 0
      || (v6 = gameLocal->GetGameFrame(this: gameLocal),
          smokeSystemRate = this->smokeSystemRate,
          __twllei(smokeSystemRate, 0),
          __twlgei(smokeSystemRate & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF),
          v8 = 0,
          v6 % smokeSystemRate == 0) )
    {
      v8 = 1;
    }
    if ( v8 != 0 )
    {
      v36 = -1;
      HIDWORD(v9) = 458752;
      v10 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v10 + 1013904223;
      LODWORD(v9) = ((v10 + 1013904223) >> 10) & 0x7FFF;
      v37 = v9;
      v11 = (float)((float)v9 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      particleSystem = this->particleSystem;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: particleSystem,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v11,
        origin: v16,
        axis: (const idMat3 *)&this->origin,
        velocity: this->axis.mat,
        color: &this->velocity.x,
        a10: v17,
        a11: v18,
        a12: v19,
        a13: v20,
        a14: v21,
        a15: v22,
        a16: v23,
        a17: v24,
        a18: v25,
        a19: v26,
        a20: v27,
        a21: v28,
        a22: v29,
        a23: v30,
        a24: v31,
        a25: v32,
        a26: v33,
        a27: v34,
        a28: v35,
        a29: &v36);
    }
  }
}


// ========================================================================
// ?TriggerShow@idPresentableParticleEmitter@@UAAXXZ
// EA  : 0x82B721A0
// RVA : 0x00B721A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::TriggerShow(idPresentableParticleEmitter *this)
{
  int z_low; // r10
  __int128 v3; // r6
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r10
  double fadeIn; // fp13
  __int64 v9; // [sp+8h] [-88h]
  __int64 v10; // [sp+8h] [-88h]
  __int64 v11; // [sp+10h] [-80h]
  __int64 v12; // [sp+10h] [-80h]
  __int64 v13; // [sp+18h] [-78h]
  __int64 v14; // [sp+18h] [-78h]
  __int64 v15; // [sp+20h] [-70h]
  __int64 v16; // [sp+20h] [-70h]
  __int64 v17; // [sp+28h] [-68h]
  __int64 v18; // [sp+28h] [-68h]
  float v19; // [sp+50h] [-40h] BYREF
  float v20; // [sp+54h] [-3Ch] BYREF
  int v21; // [sp+58h] [-38h] BYREF
  __int64 v22; // [sp+60h] [-30h]

  this->activated.count = (this->activated.count + 1) % 7;
  if ( !common->IsServer(this: common) )
  {
    if ( this->model != nullptr )
    {
      if ( !this->useSmokeSystem )
      {
        this->Show(this);
        idPresentable::SetParm(this, parm: rp->TimeStop, scalar: 0.0);
        v22 = __PAIR64__(
                &unk_82390000,
                idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
        idPresentable::SetParm(this, parm: rp->TimeOffset, scalar: (float)((float)v22 * (float)0.001));
        z_low = LODWORD(this->distributionScale.z);
        *(_QWORD *)((char *)&v3 + 4) = *(_QWORD *)&this->distributionScale.x;
        LODWORD(v3) = __ROL4__(z_low, 32);
        idPresentable::SetParm(
          this,
          parm: *(const idDeclRenderParm **)(LODWORD(this->distributionScale.x) + 0x2140),
          v3,
          a4: v6,
          a5: v5,
          a6: v4,
          a7: z_low,
          a8: v9,
          a9: v11,
          a10: v13,
          a11: v15,
          a12: v17);
        idPresentable::SetParm(
          this,
          parm: (const idDeclRenderParm *)rpParticleVel_1.r,
          v3: __SPAIR64__(LODWORD(vec3_origin.y), __ROL4__(LODWORD(vec3_origin.z), 32)),
          a4: (int)&vec3_origin,
          a5: (int)&joystick.joyAxis[0][2],
          a6: (int)allocationCurrent[242],
          a7: v7,
          a8: v10,
          a9: v12,
          a10: v14,
          a11: v16,
          a12: v18);
        idPresentable::SetParm(
          this,
          parm: (const idDeclRenderParm *)rpParticleAlphaScale_0.r,
          scalar: (float)((float)1.0 / this->alphaScale));
        if ( this->fadeIn != 0.0 )
        {
          idPresentable::SetParm(this, parm: rp->coverage, scalar: 0.0);
          fadeIn = this->fadeIn;
          v19 = 1.0;
          v20 = 0.0;
          LODWORD(v22) = (int)(float)((float)fadeIn * (float)1000.0);
          v21 = v22;
          idFadeHelper::Fade(this: &this->fade, from: &v20, to: &v19, time: &v21, _noStippleFade: false);
        }
        this->Present(this);
      }
    }
    else
    {
      idLib::Warning(fmt: "idPresentableParticleEmitter::TriggerShow called with no render model. ");
    }
  }
}


// ========================================================================
// ?TriggerHide@idPresentableParticleEmitter@@UAAXXZ
// EA  : 0x82B723C0
// RVA : 0x00B723C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::TriggerHide(idPresentableParticleEmitter *this)
{
  double fadeOut; // fp13
  float v3; // [sp+50h] [-20h] BYREF
  float v4; // [sp+54h] [-1Ch] BYREF
  int v5; // [sp+58h] [-18h] BYREF
  int v6; // [sp+5Ch] [-14h]

  this->deactivated.count = (this->deactivated.count + 1) % 7;
  if ( !common->IsServer(this: common) && !this->useSmokeSystem )
  {
    fadeOut = this->fadeOut;
    if ( fadeOut == 0.0 )
    {
      this->Hide(this, a2: true);
    }
    else
    {
      v3 = 0.0;
      v4 = 1.0;
      v6 = (int)(float)((float)fadeOut * (float)1000.0);
      v5 = v6;
      idFadeHelper::Fade(this: &this->fade, from: &v4, to: &v3, time: &v5, _noStippleFade: false);
    }
  }
}


// ========================================================================
// ?SetParticle@idPresentableParticleEmitter@@EAAXPBVidDeclParticle@@@Z
// EA  : 0x82B724D0
// RVA : 0x00B724D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::SetParticle(
        idPresentableParticleEmitter *this,
        const idDeclParticle *particleDecl)
{
  idRenderModel *model; // r10
  int v5; // r8
  idParmBlock *Vector; // r3
  int v7; // r10
  int v8; // r8
  int v9; // r7
  __int64 v10; // r7
  idClientGame *v11; // r11
  const idDeclRenderParm *Diversity; // r4
  double v13; // fp1
  int z_low; // r9
  __int128 v15; // r6
  int v16; // r8
  int v17; // r7
  int v18; // r10
  int v19; // r9
  __int64 v20; // [sp+8h] [-88h]
  __int64 v21; // [sp+8h] [-88h]
  __int64 v22; // [sp+8h] [-88h]
  __int64 v23; // [sp+8h] [-88h]
  __int64 v24; // [sp+10h] [-80h]
  __int64 v25; // [sp+10h] [-80h]
  __int64 v26; // [sp+10h] [-80h]
  __int64 v27; // [sp+10h] [-80h]
  __int64 v28; // [sp+18h] [-78h]
  __int64 v29; // [sp+18h] [-78h]
  __int64 v30; // [sp+18h] [-78h]
  __int64 v31; // [sp+18h] [-78h]
  __int64 v32; // [sp+20h] [-70h]
  __int64 v33; // [sp+20h] [-70h]
  __int64 v34; // [sp+20h] [-70h]
  __int64 v35; // [sp+20h] [-70h]
  __int64 v36; // [sp+28h] [-68h]
  __int64 v37; // [sp+28h] [-68h]
  __int64 v38; // [sp+28h] [-68h]
  __int64 v39; // [sp+28h] [-68h]
  idParmBlock v40; // [sp+50h] [-40h] BYREF

  if ( particleDecl != nullptr && this->model != nullptr )
  {
    if ( particleDecl->resourceError != nullptr )
      idLib::Warning(fmt: "Particle decl error: '%s' - using default.", particleDecl->name.str);
    model = this->model;
    this->particleSystem = particleDecl;
    v5 = *((unsigned __int8 *)&model->g + 105);
    *((_BYTE *)&model->g + 105) = v5 | 0x80;
    this->fade.fadeFrom = 0.0;
    this->fade.fadeStartTime = 0;
    this->fade.fadeTo = 0.0;
    this->fade.fadeEndTime = 0;
    this->fade.noStippleFade = false;
    if ( this->model != nullptr )
    {
      idPresentable::SetParm(
        this,
        parm: rp->Color,
        v4: *(_QWORD *)&this->colorv4.z,
        a4: v5 | 0x80,
        a5: v5,
        a6: 0x82000000,
        a7: (int)model,
        a8: v20,
        a9: v24,
        a10: v28,
        a11: v32,
        a12: v36);
      Vector = idParmBlock::GetVector(this: &v40, result: &gameLocal->renderParmBlock, parm: rp->Wind);
      idPresentable::SetParm(
        this,
        parm: (const idDeclRenderParm *)Vector->ops.list,
        v4: *(_QWORD *)&Vector->ops.size,
        a4: v9,
        a5: v8,
        a6: (int)Vector,
        a7: v7,
        a8: v21,
        a9: v25,
        a10: v29,
        a11: v33,
        a12: v37);
      HIDWORD(v10) = 1664525;
      v11 = clientGame;
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      LODWORD(v10) = (v11->random.seed >> 10) & 0x7FFF;
      Diversity = rp->Diversity;
      *(_QWORD *)&v40.ops.list = v10;
      idPresentable::SetParm(this, parm: Diversity, scalar: (float)((float)v10 * (float)0.000030518509));
      idPresentable::SetParm(this, parm: rp->TimeStop, scalar: 0.0);
      *(_QWORD *)&v40.ops.list = __PAIR64__(
                                   &unk_82390000,
                                   idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED));
      idPresentable::SetParm(
        this,
        parm: rp->TimeOffset,
        scalar: (float)((float)*(__int64 *)&v40.ops.list * (float)0.001));
      if ( this->useGlobalShadows )
        v13 = 0.0;
      else
        v13 = 1.0;
      idPresentable::SetParm(this, parm: rp->NoShadows, scalar: v13);
      z_low = LODWORD(this->distributionScale.z);
      *(_QWORD *)((char *)&v15 + 4) = *(_QWORD *)&this->distributionScale.x;
      LODWORD(v15) = __ROL4__(z_low, 32);
      idPresentable::SetParm(
        this,
        parm: (const idDeclRenderParm *)rpParticleScale_0.r,
        v3: v15,
        a4: v17,
        a5: v16,
        a6: z_low,
        a7: (int)&rpParticleScale_0,
        a8: v22,
        a9: v26,
        a10: v30,
        a11: v34,
        a12: v38);
      idPresentable::SetParm(
        this,
        parm: *(const idDeclRenderParm **)(LODWORD(vec3_origin.x) + 8),
        v3: __SPAIR64__(LODWORD(vec3_origin.y), __ROL4__(LODWORD(vec3_origin.z), 32)),
        a4: (int)&joystick.joyAxis[0][2],
        a5: (int)allocationCurrent[242],
        a6: v19,
        a7: v18,
        a8: v23,
        a9: v27,
        a10: v31,
        a11: v35,
        a12: v39);
      idPresentable::SetParm(
        this,
        parm: (const idDeclRenderParm *)rpParticleAlphaScale_0.r,
        scalar: (float)((float)1.0 / this->alphaScale));
      this->Present(this);
    }
  }
}


// ========================================================================
// ??0idPresentableParticleEmitter@@QAA@PBVidDeclParticle@@PAVidEntity@@PAVidRenderModel@@HPBVidDeclFX@@@Z
// EA  : 0x82B72808
// RVA : 0x00B72808
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

idPresentableParticleEmitter *__fastcall idPresentableParticleEmitter::idPresentableParticleEmitter(
        idPresentableParticleEmitter *this,
        const idDeclParticle *ps,
        idEntity *e,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclFX *fxDecl_)
{
  idPresentable::idPresentable(this, e, renderModel_, entityNumber_, fxDecl_);
  this->__vftable = (idPresentableParticleEmitter_vtbl *)&idPresentableParticleEmitter::`vftable';
  this->activated.count = 0;
  this->activated.lastCount = 0;
  this->deactivated.count = 0;
  this->deactivated.lastCount = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->particleSystem = nullptr;
  this->fadeIn = 0.5;
  this->useGlobalShadows = false;
  this->fadeOut = 0.5;
  this->useSmokeSystem = false;
  this->alphaScale = 1.0;
  this->smokeSystemRate = 1;
  this->distributionScale.x = 1.0;
  this->distributionScale.y = 1.0;
  this->distributionScale.z = 1.0;
  this->velocity = vec3_origin;
  this->colorv4.x = 1.0;
  this->colorv4.y = 1.0;
  this->colorv4.z = 1.0;
  this->colorv4.w = 1.0;
  this->particleSystem = ps;
  return this;
}


// ========================================================================
// ?Serialize@idPresentableParticleEmitter@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B72978
// RVA : 0x00B72978
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void __fastcall idPresentableParticleEmitter::Serialize(idPresentableParticleEmitter *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  bool useGlobalShadows; // r29
  bool useSmokeSystem; // r29
  idBitMsg *v7; // r3
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  idVec3 *p_velocity; // r4
  idBitMsg *v13; // r3
  float fadeIn; // [sp+50h] [-30h] BYREF

  idPresentable::Serialize(this, ser);
  netBoolEvent_t::Serialize(this: &this->activated, ser);
  netBoolEvent_t::Serialize(this: &this->deactivated, ser);
  msg = ser->msg;
  useGlobalShadows = this->useGlobalShadows;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->useGlobalShadows, numBits: 1);
  else
    useGlobalShadows = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->useGlobalShadows = useGlobalShadows;
  useSmokeSystem = this->useSmokeSystem;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->useSmokeSystem, numBits: 1);
  else
    useSmokeSystem = (_cntlzw(idBitMsg::ReadBits(this: v7, numBits: 1) - 1) & 0x20) != 0;
  this->useSmokeSystem = useSmokeSystem;
  v8 = ser->msg;
  if ( ser->writing )
  {
    fadeIn = this->fadeIn;
    idBitMsg::WriteBits(this: v8, value: SLODWORD(fadeIn), numBits: 32);
  }
  else
  {
    LODWORD(this->fadeIn) = idBitMsg::ReadBits(this: v8, numBits: 32);
  }
  v9 = ser->msg;
  if ( ser->writing )
  {
    fadeIn = this->fadeOut;
    idBitMsg::WriteBits(this: v9, value: SLODWORD(fadeIn), numBits: 32);
  }
  else
  {
    LODWORD(this->fadeOut) = idBitMsg::ReadBits(this: v9, numBits: 32);
  }
  v10 = ser->msg;
  if ( ser->writing )
  {
    fadeIn = this->alphaScale;
    idBitMsg::WriteBits(this: v10, value: SLODWORD(fadeIn), numBits: 32);
  }
  else
  {
    LODWORD(this->alphaScale) = idBitMsg::ReadBits(this: v10, numBits: 32);
  }
  idSerializer::Serialize(this: ser, value: &this->distributionScale);
  v11 = ser->msg;
  p_velocity = &this->velocity;
  if ( ser->writing )
    idBitMsg::WriteQuantizedVector<idVec3,32768,16>(this: v11, v: p_velocity);
  else
    idBitMsg::ReadQuantizedVector<idVec3,32768,16>(this: v11, v: p_velocity);
  idSerializer::Serialize(this: ser, value: &this->colorv4);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: this->smokeSystemRate, numBits: 32);
  else
    this->smokeSystemRate = idBitMsg::ReadBits(this: v13, numBits: 32);
  fadeIn = *(float *)&this->particleSystem;
  idSerializer::Serialize<idDeclParticle>(this: ser, decl: (const idDecl **)&fadeIn);
  if ( this->particleSystem != (const idDeclParticle *)LODWORD(fadeIn) )
    ((void (__fastcall *)(idPresentableParticleEmitter *))this->SetParticle)(a1: this);
}


// ========================================================================
// `dynamic initializer for 'rpParticleAlphaScale''_0
// EA  : 0x8336DC08
// RVA : 0x0136DC08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleAlphaScale___0()
{
  rpParticleAlphaScale_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleAlphaScale_0;
}


// ========================================================================
// `dynamic initializer for 'rpParticleScale''_0
// EA  : 0x8336DC28
// RVA : 0x0136DC28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleScale___0()
{
  rpParticleScale_0.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleScale_0;
}


// ========================================================================
// `dynamic initializer for 'rpParticleVel''_1
// EA  : 0x8336DC48
// RVA : 0x0136DC48
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableparticleemitter.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleVel___1()
{
  rpParticleVel_1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleVel_1;
}

