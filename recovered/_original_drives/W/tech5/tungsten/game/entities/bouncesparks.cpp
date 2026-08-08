
// ========================================================================
// ?Spawn@idBounceSparks@@QAAXXZ
// EA  : 0x82C0BFA8
// RVA : 0x00C0BFA8
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void __fastcall idBounceSparks::Spawn(idBounceSparks *this)
{
  double minTimeBetweenBursts; // fp12
  double maxTimeBetweenBursts; // fp0
  idPhysics *Physics; // r3
  idBreakableManager *p_breakableManager; // r29
  const idVec3 *v6; // r3
  __int64 v7; // r5
  unsigned int v8; // r9
  double v9; // fp31

  idEntity::BecomeActive(this, flags: 1);
  if ( this->declBreakable == nullptr
    || (minTimeBetweenBursts = this->minTimeBetweenBursts) < 0.0
    || (maxTimeBetweenBursts = this->maxTimeBetweenBursts) < 0.0
    || maxTimeBetweenBursts < minTimeBetweenBursts )
  {
    idLib::Error(fmt: "'%s' has bad data", this->name.data);
    JUMPOUT(0x82C0C0F0);
  }
  Physics = idEntity::GetPhysics(this);
  p_breakableManager = &gameLocal->breakableManager;
  v6 = Physics->GetOrigin(this: Physics, a2: 0);
  idBreakableManager::AddBreakable(this: p_breakableManager, decl: this->declBreakable, origin: v6);
  HIDWORD(v7) = 1;
  v8 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v8 + 1013904223;
  LODWORD(v7) = ((v8 + 1013904223) >> 10) & 0x7FFF;
  v9 = (float)((float)((float)((float)((float)v7 * (float)(this->maxTimeBetweenBursts - this->minTimeBetweenBursts))
                             * (float)0.000030518509)
                     + this->minTimeBetweenBursts)
             * (float)1000.0);
  this->nextSparkTime = (int)(float)((float)(gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                                           | 0x36400000000uLL)
                                   + (float)v9);
}


// ========================================================================
// ??0idBounceSparks@@QAA@XZ
// EA  : 0x82C0C0F8
// RVA : 0x00C0C0F8
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

idBounceSparks *__fastcall idBounceSparks::idBounceSparks(idBounceSparks *this)
{
  idVolume::idVolume(this);
  this->minTimeBetweenBursts = 10.0;
  this->maxTimeBetweenBursts = 10.0;
  this->declBreakable = nullptr;
  this->__vftable = (idBounceSparks_vtbl *)&idBounceSparks::`vftable';
  this->burstDirection.x = 0.0;
  this->burstDirection.y = 0.0;
  this->burstDirection.z = -1.0;
  this->impulse = 100.0;
  this->sparkTimings.list = nullptr;
  this->sparkTimings.granularity = 0;
  this->sparkTimings.memTag = 5;
  this->sparkTimings.listStatic = 0;
  this->sparkTimings.size = 0;
  this->sparkTimings.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparkTimings);
  this->nextSparkTime = 0;
  return this;
}


// ========================================================================
// __unwind$487917
// EA  : 0x82C0C19C
// RVA : 0x00C0C19C
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void _unwind_487917()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idBounceSparks@@UAA@XZ
// EA  : 0x82C0C1D0
// RVA : 0x00C0C1D0
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void __fastcall idBounceSparks::~idBounceSparks(idBounceSparks *this)
{
  this->__vftable = (idBounceSparks_vtbl *)&idBounceSparks::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparkTimings);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$488153_0
// EA  : 0x82C0C224
// RVA : 0x00C0C224
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void _unwind_488153_0()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idBounceSparks@@UAAXXZ
// EA  : 0x82C0C258
// RVA : 0x00C0C258
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void __fastcall idBounceSparks::Think(idBounceSparks *this)
{
  unsigned int v2; // r7
  __int64 v3; // r10
  double v4; // fp30
  __int64 v5; // r7
  double x; // fp13
  double y; // fp12
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp6
  double v11; // fp4
  idPhysics *v12; // r3
  const idVec3 *v13; // r3
  idBreakable *v14; // r3
  int v15; // r29
  idBreakable *v16; // r24
  int v17; // r9
  idVehicleState **list; // r23
  idVehicleState **v19; // r8
  __int64 v20; // r11
  idBounceSparks::sparkTimings_t *v21; // r11
  unsigned int v22; // r6
  double minDelay; // fp11
  double v24; // fp10
  idVec3 v25; // [sp+60h] [-B0h] BYREF
  idList<idVehicleState *,5> v26; // [sp+70h] [-A0h] BYREF
  idMat3 v27; // [sp+80h] [-90h] BYREF

  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > this->nextSparkTime )
  {
    v2 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v2 + 1013904223;
    LODWORD(v3) = ((v2 + 1013904223) >> 10) & 0x7FFF;
    HIDWORD(v3) = gameLocal->__vftable;
    v4 = (float)((float)((float)((float)((float)(this->maxTimeBetweenBursts - this->minTimeBetweenBursts) * (float)v3)
                               * (float)0.000030518509)
                       + this->minTimeBetweenBursts)
               * (float)1000.0);
    LODWORD(v5) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v5) = &this->burstDirection;
    this->nextSparkTime = (int)(float)((float)v5 + (float)v4);
    x = this->burstDirection.x;
    y = this->burstDirection.y;
    v27.mat[0].z = this->burstDirection.z;
    v27.mat[0].y = y;
    v27.mat[0].x = x;
    idVec3::NormalVectors(this: v27.mat, left: &v27.mat[1], down: &v27.mat[2]);
    Physics = idEntity::GetPhysics(this);
    v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v10 = (float)(v9[2] - v27.mat[0].z);
    v11 = (float)(v9[1] - v27.mat[0].y);
    v25.x = *v9 - v27.mat[0].x;
    v25.z = v10;
    v25.y = v11;
    v12 = idEntity::GetPhysics(this);
    v13 = v12->GetOrigin(this: v12, a2: 0);
    v14 = idBreakableManager::UseBreakable(
            this: &gameLocal->breakableManager,
            decl: this->declBreakable,
            origin: v13,
            axis: &v27,
            dir: v27.mat,
            pos: &v25,
            impulse: this->impulse,
            fadeTime: 0.0);
    v15 = 0;
    memset(&v26, 0, 14);
    v16 = v14;
    *(_WORD *)&v26.memTag = 1280;
    idList<idThread *,58>::Clear(this: &v26);
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v26, newNum: this->sparkTimings.num);
    v17 = 0;
    list = v26.list;
    if ( this->sparkTimings.num > 0 )
    {
      v19 = v26.list - 1;
      do
      {
        HIDWORD(v20) = clientGame;
        ++v17;
        v22 = 1664525 * clientGame->random.seed;
        v21 = &this->sparkTimings.list[v15++];
        clientGame->random.seed = v22 + 1013904223;
        minDelay = v21->minDelay;
        v24 = (float)(v21->maxDelay - v21->minDelay);
        LODWORD(v20) = ((v22 + 1013904223) >> 10) & 0x7FFF;
        *++v19 = (idVehicleState *)(int)(float)((float)((float)((float)((float)v20 * (float)v24) * (float)0.000030518509)
                                                      + (float)minDelay)
                                              * (float)1000.0);
      }
      while ( v17 < this->sparkTimings.num );
    }
    idList<idMaterial const *,59>::operator=(
      this: (idList<idMD6Node *,5> *)&v16->breakablePhysics.pieceActivationTimes,
      other: (const idList<idMD6Node *,5> *)&v26);
    if ( (v26.listStatic == 0 || v26.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$488174
// EA  : 0x82C0C530
// RVA : 0x00C0C530
// PDB : w:\tech5\tungsten\game\entities\bouncesparks.cpp
// ========================================================================

void _unwind_488174()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 112));
}

