
// ========================================================================
// ?ResetTarget@idPresentableEBoltEmitter@@IAAXXZ
// EA  : 0x82B6EF80
// RVA : 0x00B6EF80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void __fastcall idPresentableEBoltEmitter::ResetTarget(idPresentableEBoltEmitter *this)
{
  int num; // r4
  int v3; // r3
  idVec3 *list; // r9
  unsigned int v5; // r8
  __int64 v6; // r4
  const idVec3 *v7; // r29
  double v8; // fp31
  int GameMs; // r3
  int v10; // r30

  num = this->targetPoints.num;
  if ( num != 0 && this->ebolt != nullptr )
  {
    v3 = idRandom2::RandomInt(this: &clientGame->random, max: num);
    list = this->targetPoints.list;
    v5 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v5;
    LODWORD(v6) = (v5 >> 10) & 0x7FFF;
    v7 = &list[v3];
    HIDWORD(v6) = &clientGame->gameTimeManager;
    v8 = (float)((float)v6 * (float)0.000030518509);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idElectricBolt::StartElectricBolt(
      this: this->ebolt,
      _startTime: GameMs,
      _startPos: &this->origin,
      _endPos: v7,
      _diversity: v8);
    v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->nextResetTime = idRandom2::RandomInt(
                            this: &clientGame->random,
                            min: this->minResetTime,
                            max: this->maxResetTime)
                        + v10;
    if ( g_debugEBoltPresentable.valueInteger != 0 )
    {
      idLib::Printf(fmt: "Ebolt presentable - Reset Target\n");
      idLib::Printf(fmt: "\tEndPos = %f %f %f\n", v7->x, v7->y, v7->z);
      idLib::Printf(fmt: "\tnextResetTime = %d\n", this->nextResetTime);
    }
  }
}


// ========================================================================
// ?ClientThink@idPresentableEBoltEmitter@@UAAXHM_N@Z
// EA  : 0x82B6F150
// RVA : 0x00B6F150
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void __fastcall idPresentableEBoltEmitter::ClientThink(
        idPresentableEBoltEmitter *this,
        int curTime,
        double fraction,
        bool predict,
        char a5)
{
  __int64 v6; // r9
  int GameMs; // r3

  idPresentable::ClientThink(this, curTime, fraction, predict, a5);
  if ( this->ebolt != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idElectricBolt::Update(this: this->ebolt, currTime: GameMs);
  }
  LODWORD(v6) = this->nextResetTime;
  if ( (float)v6 > 0.0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextResetTime )
  {
    idPresentableEBoltEmitter::ResetTarget(this);
  }
}


// ========================================================================
// ??0idPresentableEBoltEmitter@@QAA@PAVidEntity@@PAVidRenderModel@@HH_NPBVidDeclElectricBolt@@PBVidSoundShader@@4MABVidVec2@@ABV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@@Z
// EA  : 0x82B6F320
// RVA : 0x00B6F320
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

idPresentableEBoltEmitter *__fastcall idPresentableEBoltEmitter::idPresentableEBoltEmitter(
        idPresentableEBoltEmitter *this,
        idEntity *e,
        idTreeAnimator *renderModel_,
        int minResetTime_,
        int maxResetTime_,
        bool startOff_,
        const idDeclElectricBolt *electricBoltSystem_,
        const idSoundShader *sndPowerDown_,
        double maxConeAngle_,
        const idSoundShader *sndPowerUp_,
        const idVec2 *length_,
        const idList<idEntityPtr<idEntity>,5> *targets_,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        const idSoundShader *a29,
        int a30,
        int a31,
        int a32,
        idVec2 *a33,
        int a34,
        const idList<idEntityPtr<idAISearchHintGroup>,5> *a35)
{
  idPresentable v45; // [sp+60h] [-520h] BYREF

  idPresentable::idPresentable(this);
  this->__vftable = (idPresentableEBoltEmitter_vtbl *)&idPresentableEBoltEmitter::`vftable';
  this->targetPoints.list = nullptr;
  this->targetPoints.granularity = 0;
  this->targetPoints.memTag = 5;
  this->targetPoints.listStatic = 0;
  this->targetPoints.size = 0;
  this->targetPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetPoints);
  this->targets.memTag = 5;
  this->targets.list = nullptr;
  this->targets.granularity = 0;
  this->targets.listStatic = 0;
  this->targets.size = 0;
  this->targets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targets);
  idPresentable::idPresentable(this: &v45, e, renderModel_, entityNumber_: 0x1FFF, fxDecl_: nullptr);
  idPresentable::~idPresentable(this: &v45);
  this->maxConeAngle = maxConeAngle_;
  this->minResetTime = minResetTime_;
  this->maxResetTime = maxResetTime_;
  this->startOff = startOff_;
  this->electricBoltSystem = electricBoltSystem_;
  this->sndPowerDown = sndPowerDown_;
  this->sndPowerUp = a29;
  this->length = *a33;
  idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
    this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->targets,
    other: a35);
  this->ebolt = nullptr;
  this->firstSerialize = true;
  return this;
}


// ========================================================================
// __unwind$488911
// EA  : 0x82B6F440
// RVA : 0x00B6F440
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488911()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 1408 + 1428));
}


// ========================================================================
// __unwind$488912
// EA  : 0x82B6F468
// RVA : 0x00B6F468
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488912()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1408 + 1428) + 1236));
}


// ========================================================================
// __unwind$488913
// EA  : 0x82B6F494
// RVA : 0x00B6F494
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488913()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 1408 + 1428) + 1252));
}


// ========================================================================
// ??1idPresentableEBoltEmitter@@UAA@XZ
// EA  : 0x82B6F4C8
// RVA : 0x00B6F4C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void __fastcall idPresentableEBoltEmitter::~idPresentableEBoltEmitter(idPresentableEBoltEmitter *this)
{
  idElectricBolt *ebolt; // r29

  this->__vftable = (idPresentableEBoltEmitter_vtbl *)&idPresentableEBoltEmitter::`vftable';
  ebolt = this->ebolt;
  if ( ebolt != nullptr )
  {
    idElectricBolt::~idElectricBolt(this: this->ebolt);
    idMem::Free(this: &mem, ptr: ebolt, align: ALIGN_16);
    this->ebolt = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetPoints);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$488962
// EA  : 0x82B6F540
// RVA : 0x00B6F540
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488962()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488963
// EA  : 0x82B6F568
// RVA : 0x00B6F568
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488963()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1236));
}


// ========================================================================
// __unwind$488964
// EA  : 0x82B6F594
// RVA : 0x00B6F594
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_488964()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1252));
}


// ========================================================================
// ?Serialize@idPresentableEBoltEmitter@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6F628
// RVA : 0x00B6F628
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void __fastcall idPresentableEBoltEmitter::Serialize(idPresentableEBoltEmitter *this, idSerializer *ser)
{
  BOOL hidden; // r30
  char v5; // r10
  char v6; // r18
  char v7; // r11
  char v8; // r17
  idBitMsg *msg; // r3
  idBitMsg *v10; // r3
  bool startOff; // r30
  idBitMsg *v12; // r3
  const idDeclElectricBolt **p_electricBoltSystem; // r22
  const idSoundShader **p_sndPowerDown; // r20
  const idSoundShader **p_sndPowerUp; // r19
  idBitMsg *v16; // r3
  int v17; // r26
  int v18; // r29
  int value; // r9
  idEntity *v20; // r3
  int v21; // r9
  idEntity *v22; // r3
  idEntity *v23; // r3
  idPhysics *Physics; // r3
  const idVec3 *v25; // r3
  int num; // r30
  idBitMsg *v27; // r3
  int size; // r11
  int v29; // r24
  int v30; // r26
  int v31; // r30
  idBitMsg *v32; // r28
  float *p_z; // r29
  idElectricBolt *v34; // r3
  idElectricBolt *v35; // r3
  const idDeclElectricBolt *v36; // r30
  idRenderModelBeam *NumContacts; // r3
  const char *str; // r4
  const char *v39; // r4
  const char *v40; // r4
  const idSoundShader *v41; // r5
  soundChannel_t v42; // r4

  hidden = this->hidden;
  idPresentable::Serialize(this, ser);
  if ( !hidden || (v5 = 1, this->hidden) )
    v5 = 0;
  v6 = v5;
  if ( hidden || (v7 = 1, !this->hidden) )
    v7 = 0;
  v8 = v7;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->minResetTime, numBits: 32);
  else
    this->minResetTime = idBitMsg::ReadBits(this: msg, numBits: 32);
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: this->maxResetTime, numBits: 32);
  else
    this->maxResetTime = idBitMsg::ReadBits(this: v10, numBits: 32);
  startOff = this->startOff;
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: this->startOff, numBits: 1);
  else
    startOff = (_cntlzw(idBitMsg::ReadBits(this: v12, numBits: 1) - 1) & 0x20) != 0;
  this->startOff = startOff;
  p_electricBoltSystem = &this->electricBoltSystem;
  idSerializer::Serialize<idDeclElectricBolt>(this: ser, decl: &this->electricBoltSystem);
  p_sndPowerDown = &this->sndPowerDown;
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndPowerDown);
  p_sndPowerUp = &this->sndPowerUp;
  idSerializer::Serialize<idSoundShader>(this: ser, decl: &this->sndPowerUp);
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v16, value: COERCE_INT(this->maxConeAngle), numBits: 32);
  else
    LODWORD(this->maxConeAngle) = idBitMsg::ReadBits(this: v16, numBits: 32);
  idSerializer::Serialize(this: ser, value: &this->length);
  if ( this->firstSerialize && common->IsServer(this: common) )
  {
    v17 = 0;
    if ( this->targets.num > 0 )
    {
      v18 = 0;
      do
      {
        value = this->targets.list[v18].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v20 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v20 != nullptr && idEntity::CastTo(c: v20) != nullptr )
          {
            v21 = this->targets.list[v18].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
              && (v22 = gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr )
            {
              v23 = idEntity::CastTo(c: v22);
            }
            else
            {
              v23 = nullptr;
            }
            Physics = idEntity::GetPhysics(this: v23);
            v25 = Physics->GetOrigin(this: Physics, a2: 0);
            idList<idAngles,5>::Append(this: &this->targetPoints, obj: v25);
          }
        }
        ++v17;
        ++v18;
      }
      while ( v17 < this->targets.num );
    }
  }
  num = this->targetPoints.num;
  v27 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v27, value: this->targetPoints.num, numBits: 32);
  else
    num = idBitMsg::ReadBits(this: v27, numBits: 32);
  if ( common->IsClient(this: common)
    && (num <= this->targetPoints.size
     || (unsigned __int8)idList<idVec3,59>::Resize(this: &this->targetPoints, newsize: num) != 0) )
  {
    size = this->targetPoints.size;
    if ( num < size )
      size = num;
    this->targetPoints.num = size;
  }
  v29 = 0;
  if ( this->targetPoints.num > 0 )
  {
    v30 = 0;
    do
    {
      v31 = 3;
      v32 = ser->msg;
      p_z = &this->targetPoints.list[v30 - 1].z;
      if ( ser->writing )
      {
        do
        {
          idBitMsg::WriteBits(this: v32, value: COERCE_INT(*++p_z), numBits: 32);
          --v31;
        }
        while ( v31 != 0 );
      }
      else
      {
        do
        {
          --v31;
          *(_DWORD *)++p_z = idBitMsg::ReadBits(this: v32, numBits: 32);
        }
        while ( v31 != 0 );
      }
      ++v29;
      ++v30;
    }
    while ( v29 < this->targetPoints.num );
  }
  if ( common->IsClient(this: common) && this->firstSerialize && *p_electricBoltSystem != nullptr )
  {
    v34 = (idElectricBolt *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x320u,
                              tag: TAG_PARTICLE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    v35 = v34 != nullptr ? idElectricBolt::idElectricBolt(this: v34) : nullptr;
    this->ebolt = v35;
    v36 = *p_electricBoltSystem;
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idElectricBolt::Init(this: this->ebolt, _beamModel: NumContacts, _eboltDecl: v36);
    if ( !this->startOff )
      v6 = 1;
  }
  if ( g_debugEBoltPresentable.valueInteger != 0 && this->firstSerialize )
  {
    idLib::Printf(fmt: "EboltPresentable - First serialize for %d ====\n", this->index);
    idLib::Printf(fmt: "\tminResetTime = %d\n", this->minResetTime);
    idLib::Printf(fmt: "\tmaxResetTime = %d\n", this->maxResetTime);
    idLib::Printf(fmt: "\tstartOff = %d\n", this->startOff);
    if ( *p_electricBoltSystem != nullptr )
      str = (*p_electricBoltSystem)->name.str;
    else
      str = "NULL";
    idLib::Printf(fmt: "\telectricBoltSystem = %s\n", str);
    if ( *p_sndPowerDown != nullptr )
      v39 = (*p_sndPowerDown)->name.str;
    else
      v39 = "NULL";
    idLib::Printf(fmt: "\tsndPowerDown = %s\n", v39);
    if ( *p_sndPowerUp != nullptr )
      v40 = (*p_sndPowerUp)->name.str;
    else
      v40 = "NULL";
    idLib::Printf(fmt: "\tsndPowerUp = %s\n", v40);
    idLib::Printf(fmt: "\tmaxConeAngle = %f\n", this->maxConeAngle);
    idLib::Printf(fmt: "\tlength = %f - %f\n", this->length.x, this->length.y);
  }
  this->firstSerialize = false;
  if ( v6 != 0 )
  {
    if ( g_debugEBoltPresentable.valueInteger != 0 )
      idLib::Printf(fmt: "EboltPresentable - Powering Up\n");
    idPresentableEBoltEmitter::ResetTarget(this);
    v41 = *p_sndPowerUp;
    if ( *p_sndPowerUp != nullptr )
    {
      v42 = SND_CHANNEL_AMBIENT;
LABEL_76:
      idPresentable::StartSoundShader(
        this,
        channel: v42,
        shader: v41,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    }
  }
  else if ( v8 != 0 )
  {
    v41 = *p_sndPowerDown;
    if ( *p_sndPowerDown != nullptr )
    {
      v42 = SND_CHANNEL_ANY;
      goto LABEL_76;
    }
  }
}


// ========================================================================
// __unwind$489099
// EA  : 0x82B6FBF4
// RVA : 0x00B6FBF4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void _unwind_489099()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// `dynamic initializer for 'g_debugEBoltPresentable''
// EA  : 0x8336DBB0
// RVA : 0x0136DBB0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableeboltemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugEBoltPresentable__()
{
  idCVar::idCVar(
    this: &g_debugEBoltPresentable,
    name: "g_debugEBoltPresentable",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugEBoltPresentable__);
}

