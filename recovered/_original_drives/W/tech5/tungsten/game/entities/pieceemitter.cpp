
// ========================================================================
// ??0idPieceEmitter@@QAA@XZ
// EA  : 0x82C95660
// RVA : 0x00C95660
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

idPieceEmitter *__fastcall idPieceEmitter::idPieceEmitter(idPieceEmitter *this)
{
  idEntity::idEntity(this);
  this->impactSoundTable = nullptr;
  this->__vftable = (idPieceEmitter_vtbl *)&idPieceEmitter::`vftable';
  this->pieceAngularVelocity = 50.0;
  this->pieceLifeSpan = 0;
  this->pieceFriction = 15.0;
  this->pieceMinBounceVelocity = 40.0;
  this->pieceCollisionAgeDecay = 0.0;
  this->pieceCollisionVolumeDecay = 0.0;
  idEffectPhysicsPieceEmitter::idEffectPhysicsPieceEmitter(this: &this->piecePhysics);
  this->emitModelDepthHack = 0.0;
  this->emitFovScale = 1.0;
  return this;
}


// ========================================================================
// __unwind$487573
// EA  : 0x82C9570C
// RVA : 0x00C9570C
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void _unwind_487573()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Hide@idPieceEmitter@@UAAXXZ
// EA  : 0x82C95738
// RVA : 0x00C95738
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __fastcall idPieceEmitter::Hide(idPieceEmitter *this)
{
  idEntity::Hide(this);
  idEffectPhysicsPieceEmitter::Hide(this: &this->piecePhysics);
}


// ========================================================================
// ?Show@idPieceEmitter@@UAAXXZ
// EA  : 0x82C95770
// RVA : 0x00C95770
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __fastcall idPieceEmitter::Show(idPieceEmitter *this)
{
  idEntity::Show(this);
  idEffectPhysicsPieceEmitter::Show(this: &this->piecePhysics);
}


// ========================================================================
// ??1idPieceEmitter@@UAA@XZ
// EA  : 0x82C957B0
// RVA : 0x00C957B0
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __fastcall idPieceEmitter::~idPieceEmitter(idPieceEmitter *this)
{
  this->__vftable = (idPieceEmitter_vtbl *)&idPieceEmitter::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->piecePhysics.broadPhase);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->piecePhysics);
  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: &this->piecePhysics);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$488074
// EA  : 0x82C95808
// RVA : 0x00C95808
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void _unwind_488074()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488075_1
// EA  : 0x82C95830
// RVA : 0x00C95830
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void _unwind_488075_1()
{
  int v0; // r12

  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: (idEffectPhysicsPieceEmitter *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                + 828));
}


// ========================================================================
// ?Spawn@idPieceEmitter@@QAAXXZ
// EA  : 0x82C95860
// RVA : 0x00C95860
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __fastcall idPieceEmitter::Spawn(idPieceEmitter *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v3; // r30
  const idDeclImpactSound *impactSoundTable; // r10
  double v5; // fp13
  int entityNumber; // r27
  idRenderModelEffects *MergeBranch; // r3
  int pieceLifeSpan; // r6
  double pieceCollisionAgeDecay; // fp11
  double pieceCollisionVolumeDecay; // fp10
  idVec3 v11; // [sp+50h] [-50h] BYREF
  idEffectPhysicsPieceEmitter::pieceEmitterSound_t v12; // [sp+60h] [-40h] BYREF

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                           inptr: RenderModelFromPresentable,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                           isReference: 0);
  if ( v3 == nullptr )
    idLib::Error(fmt: "%s does not use a breakable model", this->name.data);
  if ( v3->declBreakable == nullptr )
    idLib::Error(fmt: "%s does not use a breakable decl", this->name.data);
  impactSoundTable = this->impactSoundTable;
  v5 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
  entityNumber = this->entityNumber;
  v12.impactTable = nullptr;
  v12.soundWorld = nullptr;
  v12.minBounceVelSqr = 0.0;
  v12.nextSoundTime = 0;
  v12.soundWorld = clientGame->soundWorld;
  v12.minBounceVelSqr = v5;
  v12.impactTable = impactSoundTable;
  MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
  idEffectPhysicsPieceEmitter::Init(
    this: &this->piecePhysics,
    clip: &clientGame->clip,
    tmc: &clientGame->traceModelCache,
    model: v3,
    modelEffects: MergeBranch,
    soundInfo: &v12,
    entNum: entityNumber);
  pieceLifeSpan = this->pieceLifeSpan;
  pieceCollisionAgeDecay = this->pieceCollisionAgeDecay;
  pieceCollisionVolumeDecay = this->pieceCollisionVolumeDecay;
  this->piecePhysics.pieceFriction = this->pieceFriction;
  v11.x = 1.0;
  this->piecePhysics.pieceLifeTime = pieceLifeSpan;
  v11.y = 1.0;
  v11.z = 1.0;
  this->piecePhysics.pieceCollisionAgeDecay = pieceCollisionAgeDecay;
  this->piecePhysics.pieceCollisionVolumeDecay = pieceCollisionVolumeDecay;
  idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: &v11);
  if ( !v3->deferredPositionInitialized || !v3->useDeferredPosition )
    v3->g.origin = vec3_origin;
  v3->deferredOrigin = vec3_origin;
  idRenderModel::SetAxis(this: v3, a: &mat3_identity);
  v3->g.fovScale = this->emitFovScale;
  v3->g.modelDepthHack = this->emitModelDepthHack;
  idEntity::BecomeInactive(this, flags: 7);
}


// ========================================================================
// ?AllocPresentable@idPieceEmitter@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C95A00
// RVA : 0x00C95A00
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

idPresentablePieceEmitter *__fastcall idPieceEmitter::AllocPresentable(
        idPieceEmitter *this,
        idTreeAnimator *renderModel_)
{
  int v4; // r5
  idPresentablePieceEmitter *v5; // r3
  idPresentablePieceEmitter *v6; // r29

  v5 = (idPresentablePieceEmitter *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x850u,
                                      tag: TAG_PRESENTABLE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idPresentablePieceEmitter::idPresentablePieceEmitter(this: v5, ent: this, renderModel_);
  else
    v6 = nullptr;
  idPresentablePieceEmitter::SetInitProperties(
    this: v6,
    impactTable_: this->impactSoundTable,
    pieceMinBounceVelocity_: this->pieceMinBounceVelocity,
    pieceLifeSpan_: v4,
    pieceFriction_: this->pieceFriction,
    emitFovScale_: this->emitFovScale,
    emitModelDepthHack_: this->emitModelDepthHack,
    pieceCollisionAgeDecay_: this->pieceCollisionAgeDecay,
    pieceCollisionVolumeDecay_: this->pieceCollisionVolumeDecay,
    a10: this->pieceLifeSpan);
  return v6;
}


// ========================================================================
// __unwind$488195_0
// EA  : 0x82C95A98
// RVA : 0x00C95A98
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void _unwind_488195_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 96), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Think@idPieceEmitter@@UAAXXZ
// EA  : 0x82C95AC8
// RVA : 0x00C95AC8
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __fastcall idPieceEmitter::Think(
        idPieceEmitter *this,
        int a2,
        int a3,
        int a4,
        enum idAIStateTransition::aiTransCode_t (__fastcall **a5)(COMBAT_AtPlugAnim *__hidden this, struct idAI2 *, struct idAIFSM *, struct idAIState *, int),
        int a6,
        int a7)
{
  int numPiecesInUse; // r10
  idPhysics *Physics; // r28
  idPhysics *v10; // r26
  const char *GameMsPerFrame; // r25
  signed int v12; // r24
  const idMat3 *v13; // r28
  const idVec3 *v14; // r3
  idPlayer *Player; // r30
  idPhysics *v16; // r29
  idPhysics *v17; // r30
  float *v18; // r29
  float *v19; // r3
  double v20; // fp10
  double v21; // fp8
  int v22; // r30
  idPhysics *v23; // r29
  idPhysics *v24; // r28
  const idMat3 *v25; // r29
  const idVec3 *v26; // r3
  int v27; // [sp+8h] [-A8h]
  int v28; // [sp+Ch] [-A4h]
  int v29; // [sp+10h] [-A0h]
  int v30; // [sp+14h] [-9Ch]
  int v31; // [sp+18h] [-98h]
  idEffectPhysicsBroadPhase *v32; // [sp+1Ch] [-94h]
  idVec3 v33; // [sp+50h] [-60h] BYREF

  numPiecesInUse = (this->thinkFlags & 2) != 0;
  if ( (this->thinkFlags & 2) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v10 = idEntity::GetPhysics(this);
    GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
    v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v13 = Physics->GetAxis(this: Physics, a2: 0);
    v14 = v10->GetOrigin(this: v10, a2: 0);
    idEffectPhysicsPieceEmitter::UpdateSimulation(
      this: &this->piecePhysics,
      origin: v14,
      axis: v13,
      currentTime: v12,
      gameMsPerFrame: GameMsPerFrame);
    v33.x = 1.0;
    v33.y = 1.0;
    v33.z = 1.0;
    idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: &v33);
    numPiecesInUse = this->piecePhysics.numPiecesInUse;
    if ( numPiecesInUse == 0 )
    {
      idEffectPhysicsPieceEmitter::Reset(this: &this->piecePhysics);
      idEntity::BecomeInactive(this, flags: 2);
    }
  }
  if ( g_showPieceCollision.valueInteger != 0 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
    {
      v16 = idEntity::GetPhysics(this);
      v17 = idEntity::GetPhysics(this: Player);
      v18 = (float *)v16->GetOrigin(this: v16, a2: 0);
      v19 = (float *)v17->GetOrigin(this: v17, a2: 0);
      a5 = &off_82040000;
      v20 = (float)(v19[1] - v18[1]);
      v21 = (float)(v19[2] - v18[2]);
      if ( (float)((float)((float)(*v19 - *v18) * (float)(*v19 - *v18))
                 + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) < 1000000.0 )
      {
        v22 = -1 - g_showPieceCollision.valueInteger;
        if ( g_showPieceCollision.valueInteger >= 0 )
          v22 = -1;
        v23 = idEntity::GetPhysics(this);
        v24 = idEntity::GetPhysics(this);
        v25 = v23->GetAxis(this: v23, a2: 0);
        v26 = v24->GetOrigin(this: v24, a2: 0);
        idEffectPhysicsPieceEmitter::DrawCollisionModels(this: &this->piecePhysics, single: v22, offset: v26, axis: v25);
      }
    }
  }
  idClientGame::AddSimulatingEffectPhysics(
    this: clientGame,
    broadPhase: &this->piecePhysics.broadPhase,
    a3,
    a4,
    (int)a5,
    a6,
    a7,
    a8: numPiecesInUse,
    a9: v27,
    a10: v28,
    a11: v29,
    a12: v30,
    a13: v31,
    a14: v32);
}


// ========================================================================
// ?Emit@idPieceEmitter@@QAAXABVidVec3@@00ABVidMat3@@1MMM@Z
// EA  : 0x82C95D10
// RVA : 0x00C95D10
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPieceEmitter::Emit(
        int a1,
        const idVec3 *a2,
        float *a3,
        float *a4,
        const idMat3 *a5,
        float *a6,
        long double deltaSpeed,
        double deltaAngle)
{
  int v8; // r2 OVERLAPPED
  idClientGame *v14; // r8
  __int64 v16; // r10
  unsigned int v18; // r7
  unsigned int v19; // r3
  double v20; // fp30
  double v21; // fp29
  long double v22; // fp2
  double v23; // fp28
  long double v24; // fp2
  double v25; // fp13
  double v26; // fp11
  double v27; // fp9
  unsigned int v28; // r8
  double v29; // fp6
  double v30; // fp5
  double v31; // fp4
  double v32; // fp29
  __int64 v33; // r4
  double v34; // fp28
  double v35; // fp27
  double v36; // fp31
  long double v37; // fp2
  double v38; // fp11
  double v39; // fp31
  double v40; // fp29
  double v41; // fp28
  long double v42; // fp2
  float z; // r7
  double v44; // fp7
  double v45; // fp6
  float y; // r3
  double v47; // fp5
  double v48; // fp3
  double v49; // fp4
  __int64 v50; // r6
  double v51; // fp7
  double v52; // fp6
  double v53; // fp5
  double v56; // fp5
  unsigned int v57; // r8
  int v58; // r11
  idPresentablePieceEmitter *v59; // r29
  int v60; // r3
  double v61; // fp6
  int v62; // r3
  idVec3 *v63; // r11
  int v64; // r11
  idPhysics *Physics; // r3
  idPhysics *v66; // r3
  idVec3 v67; // [sp+58h] [-B8h] BYREF
  idVec3 v68; // [sp+68h] [-A8h] BYREF
  idVec3 v69; // [sp+78h] [-98h] BYREF

  v14 = clientGame;
  HIDWORD(v16) = &si_vector_decode_cat_0[184];
  clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  LODWORD(v16) = (v14->random.seed >> 10) & 0x7FFF;
  v18 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v18 + 1013904223;
  v19 = ((v18 + 1013904223) >> 10) & 0x7FFF;
  v20 = (float)((float)((float)((float)v16 * (float)*((double *)&deltaSpeed + 1)) * (float)0.000030518509)
              + (float)*(double *)&deltaSpeed);
  v21 = (float)((float)((float)((float)*(__int64 *)(&v8 - 1) * idMath::TWO_PI) * (float)deltaAngle)
              * (float)0.000030518509);
  *(double *)&deltaSpeed = v21;
  v22 = sin(x: deltaSpeed);
  v23 = (float)*(double *)&v22;
  *(double *)&v22 = v21;
  v24 = cos(x: v22);
  v25 = (float)(a6[6] * (float)v23);
  v26 = (float)(a6[7] * (float)v23);
  v27 = (float)(a6[8] * (float)v23);
  v28 = 1664525 * clientGame->random.seed;
  v29 = (float)(a6[3] * (float)*(double *)&v24);
  v30 = (float)(a6[4] * (float)*(double *)&v24);
  v31 = (float)(a6[5] * (float)*(double *)&v24);
  clientGame->random.seed = v28 + 1013904223;
  v32 = (float)((float)v29 + (float)v25);
  LODWORD(v33) = ((v28 + 1013904223) >> 10) & 0x7FFF;
  v34 = (float)((float)v30 + (float)v26);
  v35 = (float)((float)v31 + (float)v27);
  *((double *)&v24 + 1) = (double)v33;
  v36 = (float)((float)((float)((float)v33 * idMath::M_DEG2RAD) * (float)deltaAngle) * 0.000030518509);
  *(double *)&v24 = v36;
  v37 = sin(x: v24);
  v38 = (float)*(double *)&v37;
  *(double *)&v37 = v36;
  v39 = (float)((float)v32 * (float)v38);
  v40 = (float)((float)v34 * (float)v38);
  v41 = (float)((float)v35 * (float)v38);
  v42 = cos(x: v37);
  z = a5->mat[0].z;
  v44 = *a6;
  v45 = a6[2];
  y = a5->mat[0].y;
  v47 = a6[1];
  v48 = a4[2];
  v67.x = a5->mat[0].x;
  v67.z = z;
  v49 = *a4;
  v67.y = y;
  HIDWORD(v50) = byte_821B0000;
  v51 = (float)((float)((float)v44 * (float)*(double *)&v42) + (float)v39);
  v52 = (float)((float)((float)v45 * (float)*(double *)&v42) + (float)v41);
  v53 = (float)((float)((float)v47 * (float)*(double *)&v42) + (float)v40);
  *(double *)&v42 = a4[1];
  v68.x = (float)v49 + (float)((float)v51 * (float)v20);
  v68.z = (float)v48 + (float)((float)v52 * (float)v20);
  v68.y = (float)*(double *)&v42 + (float)((float)v53 * (float)v20);
  _FP5 = (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f2, f13 }
  *((double *)&v42 + 1) = __frsqrte(_FP3);
  v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1)
                                                                                      * (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y)))
                                                                                              * (float)0.5))
                                                                              * (float)*((double *)&v42 + 1))
                                                                      - (float)1.5)
                                                      * (float)*((double *)&v42 + 1))
                                              * (float)((float)((float)(v67.x * v67.x)
                                                              + (float)((float)(z * z) + (float)(y * y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1)
                                                                              * (float)((float)((float)(v67.x * v67.x)
                                                                                              + (float)((float)(z * z) + (float)(y * y)))
                                                                                      * (float)0.5))
                                                                      * (float)*((double *)&v42 + 1))
                                                              - (float)1.5)
                                              * (float)*((double *)&v42 + 1)))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1)
                                                      * (float)((float)((float)(v67.x * v67.x)
                                                                      + (float)((float)(z * z) + (float)(y * y)))
                                                              * (float)0.5))
                                              * (float)*((double *)&v42 + 1))
                                      - (float)1.5)
                      * (float)*((double *)&v42 + 1)));
  *((double *)&v42 + 1) = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1) * (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y))) * (float)0.5)) * (float)*((double *)&v42 + 1)) - (float)1.5) * (float)*((double *)&v42 + 1)) * (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1) * (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y))) * (float)0.5)) * (float)*((double *)&v42 + 1)) - (float)1.5) * (float)*((double *)&v42 + 1)))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)*((double *)&v42 + 1) * (float)((float)((float)(v67.x * v67.x) + (float)((float)(z * z) + (float)(y * y))) * (float)0.5)) * (float)*((double *)&v42 + 1))
                                                                                                - (float)1.5)
                                                                                * (float)*((double *)&v42 + 1)))
                                                                * (float)((float)((float)(v67.x * v67.x)
                                                                                + (float)((float)(z * z) + (float)(y * y)))
                                                                        * (float)0.5))
                                                        * (float)v56)
                                                - (float)1.5)
                                * (float)v56);
  v67.y = y * (float)*((double *)&v42 + 1);
  v67.x = v67.x * (float)*((double *)&v42 + 1);
  v67.z = z * (float)*((double *)&v42 + 1);
  v57 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v57;
  v58 = *(_DWORD *)(a1 + 488);
  LODWORD(v50) = (v57 >> 10) & 0x7FFF;
  v67.x = (float)((float)((float)v50 * (float)0.000061037019) - (float)1.0) * v67.x;
  v67.y = v67.y * (float)((float)((float)v50 * (float)0.000061037019) - (float)1.0);
  v67.z = v67.z * (float)((float)((float)v50 * (float)0.000061037019) - (float)1.0);
  if ( v58 == 0 )
  {
    idEntity::InitPresentableInternal(this: (idEntity *)a1);
    v58 = *(_DWORD *)(a1 + 488);
  }
  v59 = (idPresentablePieceEmitter *)(*(int (__fastcall **)(int))(*(_DWORD *)v58 + 84))(a1: v58);
  v60 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPresentablePieceEmitter::EmitPiece(this: v59, emitTime: v60, pos: a2, axes: a5, impulsePoint: &v67, impulse: &v68);
  v69.x = a2->x + *a3;
  v61 = (float)(a2->z + a3[2]);
  v69.y = a2->y + a3[1];
  v69.z = v61;
  v62 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idEffectPhysicsPieceEmitter::EmitPiece(
    this: (idEffectPhysicsPieceEmitter *)(a1 + 828),
    emitTime: v62,
    pos: &v69,
    axes: a5,
    impulsePoint: &v67,
    impulse: &v68);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)a1) == 0 )
    (*(void (__fastcall **)(int))(*(_DWORD *)a1 + 136))(a1);
  v63 = *(idVec3 **)(a1 + 488);
  if ( v63 == nullptr )
  {
    idEntity::InitPresentableInternal(this: (idEntity *)a1);
    v63 = *(idVec3 **)(a1 + 488);
  }
  v63[10] = vec3_origin;
  v64 = *(_DWORD *)(a1 + 488);
  if ( v64 == 0 )
  {
    idEntity::InitPresentableInternal(this: (idEntity *)a1);
    v64 = *(_DWORD *)(a1 + 488);
  }
  *(idMat3 *)(v64 + 132) = mat3_identity;
  Physics = idEntity::GetPhysics(this: (idEntity *)a1);
  Physics->SetOrigin(this: Physics, a2, a3: -1);
  v66 = idEntity::GetPhysics(this: (idEntity *)a1);
  v66->SetAxis(this: v66, a2: (const idMat3 *)a6, a3: -1);
  idEntity::BecomeActive(this: (idEntity *)a1, flags: 2);
}


// ========================================================================
// `dynamic initializer for 'g_showPieceCollision''
// EA  : 0x83377EF0
// RVA : 0x01377EF0
// PDB : w:\tech5\tungsten\game\entities\pieceemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showPieceCollision__()
{
  idCVar::idCVar(
    this: &g_showPieceCollision,
    name: "g_showPieceCollision",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showPieceCollision__);
}

