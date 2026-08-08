
// ========================================================================
// ??0idRibbonManager@@QAA@XZ
// EA  : 0x82BB5208
// RVA : 0x00BB5208
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

idRibbonManager *__fastcall idRibbonManager::idRibbonManager(idRibbonManager *this)
{
  this->ribbon = nullptr;
  this->ribbonDecl = nullptr;
  this->beamModel = nullptr;
  this->modelManager = nullptr;
  this->isInitialized = false;
  return this;
}


// ========================================================================
// ??1idClothComponent@@QAA@XZ
// EA  : 0x82BB5228
// RVA : 0x00BB5228
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

void __fastcall idClothComponent::~idClothComponent(idClothComponent *this)
{
  idClothSimManager::FreeCloth(this: &gameLocal->clothSimManager, clothSim: this->clothSim);
  this->clothSim = nullptr;
}


// ========================================================================
// ?Init@idClothComponent@@QAAXPAVidAnimatedEntity@@@Z
// EA  : 0x82BB5270
// RVA : 0x00BB5270
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

void __fastcall idClothComponent::Init(idClothComponent *this, idAnimatedEntity *inAnimtedEntity)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  const idDeclCloth *clothDecl; // r4
  idClothSim *v6; // r3
  idPhysics *Physics; // r3
  const idMat3 *v8; // r30
  idPhysics *v9; // r3
  const idVec3 *v10; // r3
  idPhysics *v11; // r3
  const idVec3 *v12; // r3

  if ( this->clothDecl != nullptr && this->clothDecl->clothMD6 != nullptr )
  {
    if ( inAnimtedEntity == nullptr )
      idLib::Error(fmt: "idClothComponent initialized with a NULL presentable");
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: inAnimtedEntity) == nullptr
      || (TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: inAnimtedEntity),
          clothDecl = this->clothDecl,
          TreeAnimatorFromPresentable->decl != this->clothDecl->clothMD6) )
    {
      idLib::Error(
        fmt: "idClothComponent %s and the presentable does not have the same MD6 decl",
        this->clothDecl->clothMD6->name.str);
      JUMPOUT(0x82BB53DC);
    }
    this->animatedEntity = inAnimtedEntity;
    idClothSimManager::AddCloth(this: &gameLocal->clothSimManager, decl: clothDecl);
    v6 = idClothSimManager::ReserveCloth(this: &gameLocal->clothSimManager, decl: this->clothDecl);
    this->clothSim = v6;
    if ( v6 == nullptr )
      idLib::Error(fmt: "Failed to create cloth sim for %s", this->animatedEntity->name.data);
    Physics = idEntity::GetPhysics(this: this->animatedEntity);
    v8 = Physics->GetAxis(this: Physics, a2: 0);
    v9 = idEntity::GetPhysics(this: this->animatedEntity);
    v10 = v9->GetOrigin(this: v9, a2: 0);
    idClothSim::SetOriginAxis(this: this->clothSim, newOrigin: v10, newAxis: v8, updateParticles: true);
    if ( this->gibEntity != nullptr )
    {
      v11 = idEntity::GetPhysics(this: this->animatedEntity);
      v12 = v11->GetOrigin(this: v11, a2: 0);
      idBreakableManager::AddBreakable(this: &gameLocal->breakableManager, decl: this->gibEntity, origin: v12);
    }
  }
}


// ========================================================================
// ?Update@idClothComponent@@QAAXXZ
// EA  : 0x82BB53E0
// RVA : 0x00BB53E0
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

void __fastcall idClothComponent::Update(idClothComponent *this)
{
  double v2; // fp30
  __int64 v3; // fp12
  __int64 v4; // r7
  unsigned int v5; // r3
  long double v6; // fp2
  double v7; // fp27
  long double v8; // fp2
  idClothSim *clothSim; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v11; // r29
  idClothSim *v12; // r4
  idClothParticle *cloth; // r11
  int v14; // r10
  char v15; // r11
  idDeclEntityDef *gibEntity; // r11
  idDeclEntityDef *v17; // r4
  int v18; // r27
  idRenderWorld *v19; // r3
  idVec3 v20[2]; // [sp+58h] [-D8h] BYREF
  idMat3 v21; // [sp+70h] [-C0h] BYREF
  idMat3 v22; // [sp+A0h] [-90h] BYREF

  if ( this->clothSim != nullptr )
  {
    if ( g_TestClothComponentWind.valueInteger > 0 )
    {
      v2 = (float)__SPAIR64__(0x82000000, g_TestClothComponentWind.valueInteger);
      v3 = (unsigned int)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         | 0x19660D00000000LL;
      HIDWORD(v4) = &joystick.joyAxis[0][2];
      v5 = 1664525 * clientGame->random.seed;
      *(double *)&v6 = (float)((float)v3 * gameTimeScale);
      clientGame->random.seed = v5 + 1013904223;
      LODWORD(v4) = ((v5 + 1013904223) >> 10) & 0x7FFF;
      v7 = (float)((float)v4 * (float)0.000030518509);
      v8 = sin(x: v6);
      clothSim = this->clothSim;
      clothSim->windDirection.y = (float)v2 * (float)-1.0;
      clothSim->windDirection.z = (float)v7 * (float)((float)v2 * (float)0.0);
      clothSim->windDirection.x = (float)*(double *)&v8 * (float)v2;
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->animatedEntity);
    v11 = TreeAnimatorFromPresentable;
    if ( this->isDetached )
    {
      v18 = 1;
      if ( idTreeAnimator::NumJoints(this: TreeAnimatorFromPresentable) > 1 )
      {
        do
          idTreeAnimator::SetJointScale(
            this: v11,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v18++,
            type: JOINTMOD_LOCAL_OVERRIDE,
            scale: &vec3_origin);
        while ( v18 < idTreeAnimator::NumJoints(this: v11) );
      }
    }
    else
    {
      idClothSimManager::UpdateJointsWithClothSim(
        this: &gameLocal->clothSimManager,
        ta: TreeAnimatorFromPresentable,
        clothSim: this->clothSim);
      v12 = this->clothSim;
      cloth = v12->cloth;
      if ( cloth == nullptr || (v14 = cloth->state & 1, v15 = 1, v14 == 0) )
        v15 = 0;
      if ( v15 != 0 )
      {
        gibEntity = this->gibEntity;
        this->isDetached = true;
        if ( gibEntity != nullptr )
        {
          idClothSimManager::GetGeneralOriginAxis(
            this: &gameLocal->clothSimManager,
            clothSim: v12,
            origin: v20,
            axis: &v21);
          v17 = this->gibEntity;
          v22.mat[0].x = v21.mat[2].x;
          v22.mat[0].y = v21.mat[2].y;
          v22.mat[0].z = v21.mat[2].z;
          v22.mat[1].x = v21.mat[0].x;
          v22.mat[1].y = v21.mat[0].y;
          v22.mat[1].z = v21.mat[0].z;
          v22.mat[2].x = v21.mat[1].x;
          v22.mat[2].y = v21.mat[1].y;
          v22.mat[2].z = v21.mat[1].z;
          idBreakableManager::UseBreakable(
            this: &gameLocal->breakableManager,
            decl: v17,
            origin: v20,
            axis: &v22,
            dir: &vec3_origin,
            pos: nullptr,
            impulse: 0.0,
            fadeTime: 0.0);
        }
      }
    }
    idClothSimManager::UpdateWeaponTraces(this: &gameLocal->clothSimManager, clothSim: this->clothSim);
    idClothSim::Run(this: this->clothSim, parallelJobList: gameLocal->parallelJobList);
    if ( g_debugClothComponent.valueInteger > 0 )
    {
      v19 = gameLocal->GetRenderWorld(this: gameLocal);
      idClothSim::DebugDraw(
        this: this->clothSim,
        offset: &vec3_origin,
        axis: &mat3_identity,
        renderWorld: v19,
        debugLevel: 4);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_debugClothComponent''
// EA  : 0x833722B8
// RVA : 0x013722B8
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugClothComponent__()
{
  idCVar::idCVar(
    this: &g_debugClothComponent,
    name: "g_debugClothComponent",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugClothComponent__);
}


// ========================================================================
// `dynamic initializer for 'g_TestClothComponentWind''
// EA  : 0x83372310
// RVA : 0x01372310
// PDB : w:\tech5\tungsten\game\components\clothcomponent.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_TestClothComponentWind__()
{
  idCVar::idCVar(
    this: &g_TestClothComponentWind,
    name: "g_TestClothComponentWind",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_TestClothComponentWind__);
}

