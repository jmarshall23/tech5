
// ========================================================================
// ?SetValid@idActorModifier@@QAAX_N@Z
// EA  : 0x82BEAA80
// RVA : 0x00BEAA80
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::SetValid(idActorModifier *this, bool valid_)
{
  this->valid = valid_;
}


// ========================================================================
// ?OnDamageTaken@idActorModifier@@QAAXPAVidEntity@@00PBVidDeclDamage@@M_N@Z
// EA  : 0x82BEAA88
// RVA : 0x00BEAA88
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::OnDamageTaken(
        idActorModifier *this,
        idEntity *attacker,
        idActor *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDecl,
        double damage,
        const bool isDead)
{
  const idDeclActorModifier *decl; // r11
  int v11; // r23
  int v12; // r24
  int v13; // r29
  int v14; // r30
  idActor *v15; // r3
  idEntity *v16; // r31
  idPresentable *presentable; // r3
  int v18; // r3
  int v19; // r31
  idDeclActorModifier::ActorModifierOutput_t *list; // r11
  double v21; // fp31

  if ( this->valid )
  {
    decl = this->decl;
    if ( decl != nullptr )
    {
      v11 = 0;
      if ( decl->triggers.num > 0 )
      {
        v12 = 0;
        do
        {
          if ( decl->triggers.list[v12].type == TRIGGER_TYPE_DAMAGE_TAKEN )
          {
            v13 = 0;
            if ( decl->outputs.num > 0 )
            {
              v14 = 0;
              do
              {
                if ( decl->outputs.list[v14].action == ACTION_GIVE_OVERDRIVE_POINTS )
                {
                  v15 = idActor::CastTo(c: victim);
                  v16 = v15;
                  if ( v15 == nullptr )
                    return;
                  presentable = v15->presentable;
                  if ( presentable == nullptr )
                  {
                    idEntity::InitPresentableInternal(this: v16);
                    presentable = v16->presentable;
                  }
                  v18 = (int)presentable->GetActorInterface_2(this: presentable);
                  v19 = v18;
                  if ( v18 == 0 || (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v18 + 376))(a1: v18) != 0 )
                    return;
                  list = this->decl->outputs.list;
                  v21 = (float)(list[v14].value * (float)damage);
                  if ( g_debug_overdrive.valueInteger != 0 )
                    idLib::Printf(
                      fmt: (const char *)HIDWORD(v21),
                      LODWORD(v21),
                      (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(v19 + 15584)),
                      (unsigned int)COERCE_UNSIGNED_INT64(g_overdrive_PointsRequired.valueFloat),
                      (float)(list[v14].value * (float)damage));
                  if ( (float)(*(float *)(v19 + 15584) + (float)v21) > (double)g_overdrive_PointsRequired.valueFloat )
                  {
                    *(float *)(v19 + 15584) = *(float *)(v19 + 15584) + g_overdrive_PointsRequired.valueFloat;
                    return;
                  }
                  *(float *)(v19 + 15584) = *(float *)(v19 + 15584) + (float)v21;
                }
                decl = this->decl;
                ++v13;
                ++v14;
              }
              while ( v13 < decl->outputs.num );
            }
          }
          ++v11;
          ++v12;
        }
        while ( v11 < decl->triggers.num );
      }
    }
  }
}


// ========================================================================
// ?SetParent@idActorModifier@@QAAXPAVidPresentableActor@@@Z
// EA  : 0x82BEAC40
// RVA : 0x00BEAC40
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::SetParent(idActorModifier *this, idPresentableActor *parent_)
{
  unsigned int spawnId; // r11

  spawnId = 0;
  if ( parent_ != nullptr )
    spawnId = parent_->spawnId;
  this->parent.spawnId = spawnId;
}


// ========================================================================
// ?OnDamageDealt@idActorModifier@@QAAXPAVidEntity@@00PBVidDeclDamage@@M_N@Z
// EA  : 0x82BEAC58
// RVA : 0x00BEAC58
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::OnDamageDealt(
        idActorModifier *this,
        idActor *attacker,
        idActor *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDecl,
        double damage,
        const bool isDead)
{
  const idDeclActorModifier *decl; // r11
  int v12; // r22
  int v13; // r23
  int v14; // r27
  int v15; // r29
  idDeclActorModifier::ActorModifierOutput_t *v16; // r11
  idActor *v17; // r3
  idEntity *v18; // r31
  idPresentable *v19; // r3
  int v20; // r3
  int v21; // r31
  idDeclActorModifier::ActorModifierOutput_t *list; // r11
  double v23; // fp31
  idActor *v24; // r3
  idEntity *v25; // r31
  idPresentable *presentable; // r3
  int v27; // r31
  idDeclActorModifier::ActorModifierOutput_t *v28; // r30
  idPresentableActor *v29; // r19
  int v30; // r3
  const idDeclActorModifier *v31; // r31
  int (__fastcall *v32)(int); // ctr
  idActorModifierManager *v33; // r3

  if ( this->valid )
  {
    decl = this->decl;
    if ( decl != nullptr )
    {
      v12 = 0;
      if ( decl->triggers.num > 0 )
      {
        v13 = 0;
        do
        {
          if ( decl->triggers.list[v13].type == TRIGGER_TYPE_DAMAGE_DEALT )
          {
            v14 = 0;
            if ( decl->outputs.num > 0 )
            {
              v15 = 0;
              do
              {
                v16 = &decl->outputs.list[v15];
                if ( v16->action == ACTION_APPLY_MODIFIER )
                {
                  if ( v16->decl != nullptr && v16->target == TARGET_VICTIM )
                  {
                    v24 = idActor::CastTo(c: victim);
                    v25 = v24;
                    if ( v24 == nullptr )
                      return;
                    presentable = v24->presentable;
                    if ( presentable == nullptr )
                    {
                      idEntity::InitPresentableInternal(this: v25);
                      presentable = v25->presentable;
                    }
                    v27 = (int)presentable->GetActorInterface_2(this: presentable);
                    if ( v27 == 0 )
                      return;
                    v28 = &this->decl->outputs.list[v15];
                    v29 = (idPresentableActor *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
                    v30 = v27;
                    v32 = *(int (__fastcall **)(int))(*(_DWORD *)v27 + 360);
                    v31 = v28->decl;
                    v33 = (idActorModifierManager *)v32(a1: v30);
                    if ( idActorModifierManager::AddModifierUnique(this: v33, decl: v31, item: nullptr, instigator: v29) == nullptr )
                      return;
                  }
                }
                else if ( v16->action == ACTION_GIVE_OVERDRIVE_POINTS )
                {
                  v17 = idActor::CastTo(c: attacker);
                  v18 = v17;
                  if ( v17 == nullptr )
                    return;
                  v19 = v17->presentable;
                  if ( v19 == nullptr )
                  {
                    idEntity::InitPresentableInternal(this: v18);
                    v19 = v18->presentable;
                  }
                  v20 = (int)v19->GetActorInterface_2(this: v19);
                  v21 = v20;
                  if ( v20 == 0 || (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v20 + 376))(a1: v20) != 0 )
                    return;
                  list = this->decl->outputs.list;
                  v23 = (float)(list[v15].value * (float)damage);
                  if ( g_debug_overdrive.valueInteger != 0 )
                    idLib::Printf(
                      fmt: (const char *)HIDWORD(v23),
                      LODWORD(v23),
                      (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(v21 + 15584)),
                      (unsigned int)COERCE_UNSIGNED_INT64(g_overdrive_PointsRequired.valueFloat),
                      (float)(list[v15].value * (float)damage));
                  if ( (float)(*(float *)(v21 + 15584) + (float)v23) > (double)g_overdrive_PointsRequired.valueFloat )
                  {
                    *(float *)(v21 + 15584) = *(float *)(v21 + 15584) + g_overdrive_PointsRequired.valueFloat;
                    return;
                  }
                  *(float *)(v21 + 15584) = *(float *)(v21 + 15584) + (float)v23;
                }
                decl = this->decl;
                ++v14;
                ++v15;
              }
              while ( v14 < decl->outputs.num );
            }
          }
          ++v12;
          ++v13;
        }
        while ( v12 < decl->triggers.num );
      }
    }
  }
}


// ========================================================================
// ??1idActorModifier@@UAA@XZ
// EA  : 0x82BEAFF8
// RVA : 0x00BEAFF8
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::~idActorModifier(idActorModifier *this)
{
  idFXManager *p_fxManager; // r29

  this->__vftable = (idActorModifier_vtbl *)&idActorModifier::`vftable';
  p_fxManager = &this->fxManager;
  idFXManager::Shutdown(this: &this->fxManager);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->timers);
  idFXManager::~idFXManager(this: p_fxManager);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$488660_1
// EA  : 0x82BEB048
// RVA : 0x00BEB048
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void _unwind_488660_1()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488661_0
// EA  : 0x82BEB070
// RVA : 0x00BEB070
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void _unwind_488661_0()
{
  int v0; // r12

  idFXManager::~idFXManager(this: (idFXManager *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$488662_0
// EA  : 0x82BEB09C
// RVA : 0x00BEB09C
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void _unwind_488662_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 780));
}


// ========================================================================
// ?Serialize@idActorModifier@@QAAXAAVidSerializer@@@Z
// EA  : 0x82BEB0C8
// RVA : 0x00BEB0C8
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::Serialize(idActorModifier *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idPresentablePtr<idPresentableActor> *p_parent; // r29
  idBitMsg *v7; // r3
  bool valid; // r29
  idBitMsg *v9; // r3

  idSerializer::Serialize<idDeclActorModifier>(this: ser, decl: &this->decl);
  netBoolEvent_t::Serialize(this: &this->added, ser);
  netBoolEvent_t::Serialize(this: &this->activated, ser);
  netBoolEvent_t::Serialize(this: &this->deactivated, ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->uid, numBits: 32);
  else
    this->uid = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->index, numBits: 8);
  else
    this->index = idBitMsg::ReadBits(this: v5, numBits: 8);
  p_parent = &this->parent;
  if ( !idPresentablePtr<idPresentable>::IsValid(this: &this->parent) )
    idLib::Warning(fmt: "serialize: parent presentable is null...");
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: p_parent->spawnId, numBits: 32);
  else
    p_parent->spawnId = idBitMsg::ReadBits(this: v7, numBits: 32);
  valid = this->valid;
  v9 = ser->msg;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v9, value: this->valid, numBits: 1);
    this->valid = valid;
  }
  else
  {
    this->valid = (_cntlzw(idBitMsg::ReadBits(this: v9, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ?Deactivate@idActorModifier@@AAAX_N@Z
// EA  : 0x82BEB200
// RVA : 0x00BEB200
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::Deactivate(idActorModifier *this, const bool activatedByServer)
{
  idPresentable *v4; // r3
  int GameMs; // r3
  int v6; // [sp+60h] [-60h]
  const idEventArg *v7; // [sp+68h] [-58h]
  const idEventArg *v8; // [sp+6Ch] [-54h]

  if ( this->active )
  {
    this->active = false;
    v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
    if ( v4->IsLocallyControlled(this: v4) )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::LocalStopFX(this: &this->fxManager, time: GameMs, stop: 196, immediateStop: false);
    }
    if ( common->IsServer(this: common) )
    {
      HIBYTE(v6) = 105;
      idEventReceiver::BroadcastEvent(
        this,
        ev: *(const idEventDef **)v6,
        arg1: *(const idEventArg **)(v6 + 8),
        arg2: *(const idEventArg **)(v6 + 12));
      this->deactivated.count = (this->deactivated.count + 1) % 7;
    }
    else if ( !activatedByServer )
    {
      HIBYTE(v6) = 105;
      idEventReceiver::BroadcastEvent(this, ev: (const idEventDef *)v6, arg1: v7, arg2: v8);
    }
  }
}


// ========================================================================
// ?TriggerFX@idActorModifier@@AAAXW4fxCondition_t@@@Z
// EA  : 0x82BEB388
// RVA : 0x00BEB388
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::TriggerFX(idActorModifier *this, int fxCondition)
{
  idPresentablePtr<idPresentable> *p_parent; // r30
  idFXManager *p_fxManager; // r31
  int v6; // r3
  idPresentable *v7; // r28
  idPresentable *v8; // r30
  int v9; // r3

  p_parent = (idPresentablePtr<idPresentable> *)&this->parent;
  if ( idPresentablePtr<idPresentable>::IsValid(this: &this->parent) )
  {
    p_fxManager = &this->fxManager;
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idFXManager::StopFX(this: p_fxManager, time: v6, stopCondition: fxCondition, immediateStop: false);
    v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
    v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idFXManager::StartFX(this: p_fxManager, org: &v8->origin, axis: &v7->axis, time: v9, startCondition: fxCondition);
  }
}


// ========================================================================
// ?TriggerLocalFX@idActorModifier@@AAAXW4fxCondition_t@@@Z
// EA  : 0x82BEB440
// RVA : 0x00BEB440
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::TriggerLocalFX(idActorModifier *this, int fxCondition)
{
  idPresentablePtr<idPresentable> *p_parent; // r30
  idPresentable *v5; // r3
  idFXManager *p_fxManager; // r31
  int v7; // r3
  idPresentable *v8; // r28
  idPresentable *v9; // r30
  unsigned int v10; // r3

  p_parent = (idPresentablePtr<idPresentable> *)&this->parent;
  if ( idPresentablePtr<idPresentable>::IsValid(this: &this->parent) )
  {
    v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
    if ( v5->IsLocallyControlled(this: v5) )
    {
      p_fxManager = &this->fxManager;
      v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idFXManager::LocalStopFX(this: p_fxManager, time: v7, stop: fxCondition, immediateStop: false);
      v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
      v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
      v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idFXManager::LocalStartFX(this: p_fxManager, org: &v9->origin, axis: &v8->axis, time: v10, start: fxCondition);
    }
  }
}


// ========================================================================
// ?CheckDeps@idActorModifier@@QAA_NXZ
// EA  : 0x82BEB518
// RVA : 0x00BEB518
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

int __fastcall idActorModifier::CheckDeps(idActorModifier *this)
{
  idPresentablePtr<idPresentable> *p_parent; // r27
  idPresentable *v3; // r3
  const idDeclActorModifier *decl; // r11
  int v5; // r31
  int i; // r30

  if ( !this->valid )
    return 1;
  if ( this->decl == nullptr )
    return 1;
  p_parent = (idPresentablePtr<idPresentable> *)&this->parent;
  v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
  if ( !v3->IsLocallyControlled(this: v3) )
    return 1;
  decl = this->decl;
  v5 = 0;
  if ( decl->deps.num <= 0 )
    return 1;
  for ( i = 0;
        decl->deps.list[i].type != OVERDRIVE_FULL_DEPTYPE
     || *(float *)&idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent)[12].entityTypeFlags >= (double)g_overdrive_PointsRequired.valueFloat;
        ++i )
  {
    decl = this->decl;
    if ( ++v5 >= decl->deps.num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ??0idActorModifier@@QAA@XZ
// EA  : 0x82BEB5E8
// RVA : 0x00BEB5E8
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

idActorModifier *__fastcall idActorModifier::idActorModifier(idActorModifier *this)
{
  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idActorModifier_vtbl *)&idActorModifier::`vftable';
  idFXManager::idFXManager(this: &this->fxManager);
  this->timers.num = 0;
  this->timers.granularity = 1;
  this->timers.listStatic = 1;
  this->timers.list = this->timers.staticList;
  this->timers.size = 4;
  this->timers.memTag = 5;
  this->timers.staticList[0].expire_time = 0;
  this->timers.staticList[0].index = 0;
  this->timers.staticList[1].expire_time = 0;
  this->timers.staticList[1].index = 0;
  this->timers.staticList[2].expire_time = 0;
  this->timers.staticList[2].index = 0;
  this->timers.staticList[3].expire_time = 0;
  this->timers.staticList[3].index = 0;
  this->parent.spawnId = 0;
  this->instigator.spawnId = 0;
  this->decl = nullptr;
  this->item = nullptr;
  this->added.count = 0;
  this->added.lastCount = 0;
  this->activated.count = 0;
  this->activated.lastCount = 0;
  this->deactivated.count = 0;
  this->deactivated.lastCount = 0;
  this->uid = 0;
  this->creationTime = 0;
  this->activationTime = 0;
  this->index = 0;
  this->valid = false;
  this->active = false;
  this->nextTimerTick = 0;
  return this;
}


// ========================================================================
// __unwind$488960
// EA  : 0x82BEB6FC
// RVA : 0x00BEB6FC
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void _unwind_488960()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ?Activate@idActorModifier@@QAAX_N@Z
// EA  : 0x82BEB790
// RVA : 0x00BEB790
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::Activate(idActorModifier *this, const bool activatedByServer)
{
  idCommon_vtbl *v4; // r10
  idPresentable *v5; // r3
  unsigned __int8 index; // r29
  unsigned int uid; // r28
  idPresentable *v8; // r3
  unsigned int spawnId; // r11
  idClientGameMsg v10; // [sp+70h] [-90h] BYREF
  unsigned int v11; // [sp+78h] [-88h]
  unsigned int v12; // [sp+7Ch] [-84h]
  unsigned __int8 v13; // [sp+80h] [-80h]
  const idEventDef *v14; // [sp+90h] [-70h]
  int v15; // [sp+94h] [-6Ch]
  const idEventArg *v16; // [sp+9Ch] [-64h]
  const idEventDef *v17; // [sp+B0h] [-50h]
  int v18; // [sp+B4h] [-4Ch]
  const idEventArg *v19; // [sp+B8h] [-48h]
  const idEventArg *v20; // [sp+BCh] [-44h]

  if ( !this->active && (unsigned __int8)idActorModifier::CheckDeps(this) != 0 )
  {
    this->active = true;
    this->activationTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v4 = common->__vftable;
    if ( activatedByServer )
    {
      if ( ((unsigned __int8 (*)(void))v4->IsServer)() != 0 )
        this->activated.count = (this->activated.count + 1) % 7;
      v18 = 1;
      HIBYTE(v17) = 105;
      HIBYTE(v14) = 105;
      v15 = 0;
      idEventReceiver::BroadcastEvent(this, ev: v17, arg1: v19, arg2: v20);
      v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
      if ( v5->IsLocallyControlled(this: v5) )
        idActorModifier::TriggerLocalFX(this, fxCondition: 195);
      else
        idActorModifier::TriggerFX(this, fxCondition: 193);
    }
    else if ( ((unsigned __int8 (*)(void))v4->IsClient)() != 0 )
    {
      index = this->index;
      uid = this->uid;
      v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
      spawnId = 0;
      v11 = 0;
      v10.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_ActorModifier::`vftable';
      v10.peerMask = -1;
      if ( v8 != nullptr )
        spawnId = v8->spawnId;
      v11 = spawnId;
      v12 = uid;
      v13 = index;
      idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v10);
      v18 = 1;
      v15 = 1;
      HIBYTE(v17) = 105;
      HIBYTE(v14) = 105;
      idEventReceiver::BroadcastEvent(this, ev: v14, arg1: (const idEventArg *)1, arg2: v16);
      idActorModifier::TriggerLocalFX(this, fxCondition: 195);
    }
  }
}


// ========================================================================
// __unwind$489050
// EA  : 0x82BEB9B4
// RVA : 0x00BEB9B4
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void _unwind_489050()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 256 + 112));
}


// ========================================================================
// ?PostSerializeRead@idActorModifier@@QAAX_N@Z
// EA  : 0x82BEBA50
// RVA : 0x00BEBA50
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::PostSerializeRead(idActorModifier *this, const bool firstClientFrame)
{
  int count; // r10
  char v3; // r9
  int v4; // r10
  char v5; // r11

  count = this->activated.count;
  if ( count == this->activated.lastCount )
  {
    v3 = 0;
  }
  else
  {
    this->activated.lastCount = count;
    v3 = 1;
  }
  v4 = this->deactivated.count;
  if ( v4 == this->deactivated.lastCount )
  {
    v5 = 0;
  }
  else
  {
    this->deactivated.lastCount = v4;
    v5 = 1;
  }
  if ( this->valid )
  {
    if ( this->active && v5 != 0 )
    {
      idActorModifier::Deactivate(this, activatedByServer: true);
    }
    else if ( v3 != 0 )
    {
      idActorModifier::Activate(this, activatedByServer: true);
    }
  }
}


// ========================================================================
// ?Update@idActorModifier@@QAAXH@Z
// EA  : 0x82BEBAE0
// RVA : 0x00BEBAE0
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::Update(idActorModifier *this, const int gameTime)
{
  idPresentablePtr<idPresentableActor> *p_parent; // r23
  int v4; // r27
  idPresentable *v5; // r29
  idPresentable *v6; // r28
  int v7; // r26
  unsigned int v8; // r3
  int v9; // r24
  int v10; // r27
  int v11; // r28
  int v12; // r25
  idActorModifierTimer *v13; // r29
  idDeclActorModifier::ActorModifierTrigger_t *v14; // r26
  int v15; // r3
  int timerDelay; // r8
  bool v17; // r3
  int v18; // r29
  int v19; // r29
  idPresentable *PresentableByIndex; // r3

  if ( this->valid )
  {
    p_parent = &this->parent;
    v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
    v7 = gameLocal->GetGameFrame(this: gameLocal);
    v8 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    idFXManager::Update(
      this: &this->fxManager,
      parentOrigin: &v6->origin,
      parentAxis: &v5->axis,
      parentVel: &vec3_origin,
      time: v4,
      gameMsPerFrame: v8,
      frameNum: v7,
      fovScale: 1.0,
      depthHack: 0.0);
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v10 = 0;
    if ( this->timers.num > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        if ( v9 >= this->timers.list[v11].expire_time )
        {
          idActorModifier::Activate(this, activatedByServer: true);
          v13 = &this->timers.list[v11];
          v14 = &this->decl->triggers.list[v12];
          v15 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          timerDelay = v14->timerDelay;
          v13->index = v10;
          v13->expire_time = v15 + timerDelay;
        }
        ++v10;
        ++v12;
        ++v11;
      }
      while ( v10 < this->timers.num );
    }
    if ( this->active
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->decl->lifetime + this->activationTime )
    {
      v17 = common->IsServer(this: common);
      idActorModifier::Deactivate(this, activatedByServer: v17);
    }
    if ( this->decl->removeAfter > 0
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->decl->removeAfter + this->creationTime )
    {
      this->valid = false;
    }
    v18 = p_parent->spawnId & 0x3FFF;
    if ( p_parent->spawnId != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: p_parent->spawnId & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v18)->spawnId == p_parent->spawnId )
    {
      v19 = p_parent->spawnId & 0x3FFF;
      if ( p_parent->spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_parent->spawnId & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v19))->spawnId != p_parent->spawnId )
      {
        PresentableByIndex = nullptr;
      }
      if ( ((unsigned __int8 (__fastcall *)(idPresentable *))PresentableByIndex->__vftable[1].PostSerializeRead)(a1: PresentableByIndex) != 0
        && this->decl->removeOnDeath )
      {
        this->valid = false;
      }
    }
  }
}


// ========================================================================
// ?HandleButtonPress@idActorModifier@@QAA_NPAVidUCmdTracker@@@Z
// EA  : 0x82BEBDC8
// RVA : 0x00BEBDC8
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

int __fastcall idActorModifier::HandleButtonPress(idActorModifier *this, idUCmdTracker *cmdTracker)
{
  const idDeclActorModifier *decl; // r11
  int v5; // r30
  int i; // r31
  idDeclActorModifier::ActorModifierTrigger_t *v7; // r11
  bool v9; // r3

  if ( !this->valid )
    return 0;
  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  v5 = 0;
  if ( decl->triggers.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v7 = &decl->triggers.list[i];
    if ( v7->type == TRIGGER_TYPE_BUTTON
      && (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: cmdTracker, mask: v7->button) != 0 )
    {
      break;
    }
    decl = this->decl;
    if ( ++v5 >= decl->triggers.num )
      return 0;
  }
  v9 = common->IsServer(this: common);
  idActorModifier::Activate(this, activatedByServer: v9);
  return 1;
}


// ========================================================================
// ?SetDefaults@idActorModifier@@QAAXXZ
// EA  : 0x82BEBF00
// RVA : 0x00BEBF00
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __fastcall idActorModifier::SetDefaults(idActorModifier *this)
{
  idFXManager *p_fxManager; // r27
  int v3; // r29
  idPresentable *v4; // r3
  __int64 v5; // r10
  unsigned int v6; // r6
  double v7; // fp31
  idPresentableAnimatedEntity *v8; // r3
  idTreeAnimator *TreeAnimator; // r3
  int i; // r28
  const idDeclActorModifier *decl; // r11
  idSerializerLog::compressionEntry_t *v12; // r24
  idDeclActorModifier::ActorModifierTrigger_t *v13; // r30
  int v14; // r3
  int timerDelay; // r7
  fxEmitterSound_t v16[2]; // [sp+50h] [-60h] BYREF

  if ( this->decl != nullptr )
  {
    p_fxManager = &this->fxManager;
    idFXManager::Shutdown(this: &this->fxManager);
    v3 = 0;
    if ( idPresentablePtr<idPresentable>::IsValid(this: &this->parent) && this->decl != nullptr )
    {
      v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
      v16[0].emitter = idPresentable::GetSoundEmitter(this: v4, alloc: false);
      HIDWORD(v5) = 1664525;
      v16[0].channel = SND_CHANNEL_ABILITY;
      v6 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v6 + 1013904223;
      LODWORD(v5) = ((v6 + 1013904223) >> 10) & 0x7FFF;
      v16[1] = (fxEmitterSound_t)v5;
      v7 = (float)((float)v5 * (float)0.000030518509);
      v8 = (idPresentableAnimatedEntity *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v8);
      idFXManager::Init(
        this: p_fxManager,
        declFX: this->decl->fxDecl,
        _rw: clientGame->renderWorld,
        _soundInfo: v16,
        _gameLibEffects: &clientGame->gameLibEffects,
        diversity: v7,
        _ta: (idTreeAnimator *)this->decl,
        a8: TreeAnimator);
    }
    this->creationTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( common->IsServer(this: common) )
    {
      idList<idActorModifierTimer,5>::SetNum(this: (idList<swfGlyphEntry_t,72> *)&this->timers, newNum: 0);
      for ( i = 0; i < this->decl->triggers.num; ++v3 )
      {
        decl = this->decl;
        if ( decl->triggers.list[v3].type == TRIGGER_TYPE_TIMER )
        {
          if ( this->timers.num == this->timers.size )
          {
            idLib::Warning(fmt: "idActorModifier %s is over the limit of 4 timers", decl->internalName.data);
          }
          else
          {
            v12 = idList<idSerializerLog::compressionEntry_t,44>::Alloc(this: (idList<idSerializerLog::compressionEntry_t,44> *)&this->timers);
            v13 = &this->decl->triggers.list[v3];
            v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            timerDelay = v13->timerDelay;
            v12->csize = i;
            v12->objID = v14 + timerDelay;
          }
        }
        ++i;
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_overdrive_PointsRequired''
// EA  : 0x833747B8
// RVA : 0x013747B8
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_overdrive_PointsRequired__()
{
  idCVar::idCVar(
    this: &g_overdrive_PointsRequired,
    name: "g_overdrive_PointsRequired",
    value: "200",
    flags: 2,
    description: "Number of overdrive points required activate overdrive ability",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_overdrive_PointsRequired__);
}


// ========================================================================
// `dynamic initializer for 'g_debug_overdrive''
// EA  : 0x83374810
// RVA : 0x01374810
// PDB : w:\tech5\tungsten\game\entities\actormodifier.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debug_overdrive__()
{
  idCVar::idCVar(
    this: &g_debug_overdrive,
    name: "g_debug_overdrive",
    value: "0",
    flags: 1,
    description: "Enables debug text for overdrive",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debug_overdrive__);
}

