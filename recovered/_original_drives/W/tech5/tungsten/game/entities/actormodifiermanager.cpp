
// ========================================================================
// ?PostSerializeRead@idActorModifierManager@@UAAX_N@Z
// EA  : 0x82BEC198
// RVA : 0x00BEC198
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::PostSerializeRead(idActorModifierManager *this, bool firstClientFrame)
{
  netBoolEvent_t *p_added; // r31
  int i; // r29
  char v6; // r11

  p_added = &this->modifiers.ptr[0].added;
  for ( i = 16; i != 0; --i )
  {
    idActorModifier::PostSerializeRead(this: (idActorModifier *)&p_added[-106].lastCount, firstClientFrame);
    if ( p_added->count == p_added->lastCount )
    {
      v6 = 0;
    }
    else
    {
      p_added->lastCount = p_added->count;
      v6 = 1;
    }
    if ( v6 != 0 )
    {
      idEventReceiver::AddEventListener(
        this: (idEventReceiver *)&p_added[-106].lastCount,
        listener: &this->idEventReceiver);
      idActorModifier::SetDefaults(this: (idActorModifier *)&p_added[-106].lastCount);
    }
    p_added += 111;
  }
}


// ========================================================================
// ?InventoryItemRemoved@idActorModifierManager@@QAAXPAVidInventoryItem@@PAVidEntity@@@Z
// EA  : 0x82BEC218
// RVA : 0x00BEC218
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::InventoryItemRemoved(
        idActorModifierManager *this,
        idInventoryItem *item,
        idEntity *owner)
{
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r11
  const idInventoryItem **i; // r10
  idActorModifier *v10; // r31

  v5 = *(_DWORD *)(item->GetType(this: item) + 36);
  if ( v5 < idActorModifierItem::Type.typeNum || (v7 = v5 <= idActorModifierItem::Type.lastChild, v6 = 1, !v7) )
    v6 = 0;
  if ( v6 != 0 )
  {
    v8 = 0;
    for ( i = &this->modifiers.ptr[0].item; *i != item; i += 222 )
    {
      if ( ++v8 >= 16 )
        return;
    }
    v10 = &this->modifiers.ptr[v8];
    idActorModifier::SetValid(this: v10, valid_: false);
    idEventReceiver::RemoveEventListener(this: v10, listener: &this->idEventReceiver);
  }
}


// ========================================================================
// ?AssignAvailableModifier@idActorModifierManager@@AAAPAVidActorModifier@@XZ
// EA  : 0x82BEC2E8
// RVA : 0x00BEC2E8
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idActorModifier *__fastcall idActorModifierManager::AssignAvailableModifier(idActorModifierManager *this)
{
  int v1; // r11
  bool *i; // r10
  char *v4; // r10
  unsigned int modifierUIDCounter; // r11

  v1 = 0;
  for ( i = &this->modifiers.ptr[0].valid; *i; i += 888 )
  {
    if ( ++v1 >= 16 )
      return nullptr;
  }
  v4 = (char *)this + 888 * v1;
  v4[920] = v1;
  modifierUIDCounter = this->modifierUIDCounter;
  this->modifierUIDCounter = modifierUIDCounter + 1;
  *((_DWORD *)v4 + 227) = modifierUIDCounter;
  return (idActorModifier *)(v4 + 40);
}


// ========================================================================
// ?GetSpeedModifier@idActorModifierManager@@QAAMXZ
// EA  : 0x82BEC340
// RVA : 0x00BEC340
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

float __fastcall idActorModifierManager::GetSpeedModifier(idActorModifierManager *this)
{
  double value; // fp1

  value = this->modValues.ptr[1].value;
  return *((float *)&value + 1);
}


// ========================================================================
// ?GetDamageModifier@idActorModifierManager@@QAAMXZ
// EA  : 0x82BEC348
// RVA : 0x00BEC348
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

float __fastcall idActorModifierManager::GetDamageModifier(idActorModifierManager *this)
{
  double value; // fp1

  value = this->modValues.ptr[2].value;
  return *((float *)&value + 1);
}


// ========================================================================
// ?IsOverdriveDisabled@idActorModifierManager@@QAA_NXZ
// EA  : 0x82BEC350
// RVA : 0x00BEC350
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

BOOL __fastcall idActorModifierManager::IsOverdriveDisabled(idActorModifierManager *this)
{
  return (_cntlzw(this->modValues.ptr[3].integer) & 0x20) != 0;
}


// ========================================================================
// ?HandleButtonPress@idActorModifierManager@@QAAXPAVidUCmdTracker@@@Z
// EA  : 0x82BEC360
// RVA : 0x00BEC360
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::HandleButtonPress(idActorModifierManager *this, idUCmdTracker *cmdTracker)
{
  idArray<idActorModifier,16> *p_modifiers; // r31
  int i; // r30

  p_modifiers = &this->modifiers;
  for ( i = 16; i != 0; --i )
  {
    if ( p_modifiers->ptr[0].valid )
      idActorModifier::HandleButtonPress(this: p_modifiers->ptr, cmdTracker);
    p_modifiers = (idArray<idActorModifier,16> *)((char *)p_modifiers + 888);
  }
}


// ========================================================================
// ?HandleActorModifierMessage@idActorModifierManager@@UAAXIE@Z
// EA  : 0x82BEC3A8
// RVA : 0x00BEC3A8
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::HandleActorModifierMessage(
        idActorModifierManager *this,
        unsigned int uid,
        unsigned __int8 index)
{
  char *v3; // r11

  if ( index < 0x10u )
  {
    v3 = (char *)this + 888 * index;
    if ( v3[921] != 0 && *((_DWORD *)v3 + 227) == uid && (unsigned __int8)v3[920] == index )
      idActorModifier::Activate(this: (idActorModifier *)(v3 + 40), activatedByServer: true);
  }
}


// ========================================================================
// ?RecalculateModValue@idActorModifierManager@@AAAXW4ActorModifierAttribute_t@idDeclActorModifier@@@Z
// EA  : 0x82BEC3F0
// RVA : 0x00BEC3F0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::RecalculateModValue(idActorModifierManager *this, int attrib)
{
  char *v2; // r11
  double v3; // fp0
  bool *p_active; // r6
  double v5; // fp13
  idActorModifierManager::ActorModifierVar_s *v6; // r3
  int v7; // r5
  int v8; // r11
  int v9; // r7
  int v10; // r10
  int v11; // r8
  int v12; // r11
  int v13; // r9

  if ( attrib > 0 && attrib < 4 )
  {
    v2 = (char *)this + 20 * attrib;
    v3 = 1.0;
    p_active = &this->modifiers.ptr[0].active;
    v5 = 0.0;
    v6 = (idActorModifierManager::ActorModifierVar_s *)(v2 + 14252);
    v7 = 16;
    *((float *)v2 + 3566) = 1.0;
    *((_DWORD *)v2 + 3567) = 1;
    do
    {
      if ( *(p_active - 1) && *p_active )
      {
        v8 = *(_DWORD *)(p_active - 46);
        if ( v8 != 0 && *(int *)(v8 + 508) > 0 )
        {
          v9 = *(_DWORD *)(v8 + 504);
          v10 = 0;
          v11 = *(_DWORD *)(v8 + 508);
          do
          {
            v12 = v10 + v9;
            if ( *(_DWORD *)(v10 + v9 + 4) == attrib )
            {
              v13 = *(_DWORD *)(v12 + 8);
              if ( v13 != 0 )
              {
                if ( v13 == 1 )
                  v5 = (float)(*(float *)(v12 + 16) + (float)v5);
              }
              else
              {
                v3 = (float)(*(float *)(v12 + 16) * (float)v3);
              }
            }
            --v11;
            v10 += 64;
          }
          while ( v11 != 0 );
        }
      }
      --v7;
      p_active += 888;
    }
    while ( v7 != 0 );
    idActorModifierManager::ActorModifierVar_s::Set(this: v6, value_: (float)((float)v5 + (float)v3));
  }
}


// ========================================================================
// ?OnDamageDealt@idActorModifierManager@@QAAXPAVidEntity@@00PBVidDeclDamage@@M_N@Z
// EA  : 0x82BEC4D0
// RVA : 0x00BEC4D0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::OnDamageDealt(
        idActorModifierManager *this,
        idActor *attacker,
        idActor *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDecl,
        double damage,
        bool isDead)
{
  idArray<idActorModifier,16> *p_modifiers; // r31
  int i; // r25

  p_modifiers = &this->modifiers;
  for ( i = 16; i != 0; --i )
  {
    if ( p_modifiers->ptr[0].valid )
      idActorModifier::OnDamageDealt(this: p_modifiers->ptr, attacker, victim, inflictor, damageDecl, damage, isDead);
    p_modifiers = (idArray<idActorModifier,16> *)((char *)p_modifiers + 888);
  }
}


// ========================================================================
// ?OnDamageTaken@idActorModifierManager@@QAAXPAVidEntity@@00PBVidDeclDamage@@M_N@Z
// EA  : 0x82BEC548
// RVA : 0x00BEC548
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::OnDamageTaken(
        idActorModifierManager *this,
        idEntity *attacker,
        idActor *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDecl,
        double damage,
        bool isDead)
{
  idArray<idActorModifier,16> *p_modifiers; // r31
  int i; // r25

  p_modifiers = &this->modifiers;
  for ( i = 16; i != 0; --i )
  {
    if ( p_modifiers->ptr[0].valid )
      idActorModifier::OnDamageTaken(this: p_modifiers->ptr, attacker, victim, inflictor, damageDecl, damage, isDead);
    p_modifiers = (idArray<idActorModifier,16> *)((char *)p_modifiers + 888);
  }
}


// ========================================================================
// ?Serialize@idActorModifierManager@@UAAXAAVidSerializer@@@Z
// EA  : 0x82BEC6E0
// RVA : 0x00BEC6E0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::Serialize(idActorModifierManager *this, idSerializer *ser)
{
  idArray<idActorModifierManager::ActorModifierVar_s,4> *p_modValues; // r30
  int i; // r31
  idArray<idActorModifier,16> *p_modifiers; // r30
  int j; // r31

  p_modValues = &this->modValues;
  for ( i = 4; i != 0; --i )
  {
    idActorModifierManager::ActorModifierVar_s::Serialize(this: p_modValues->ptr, ser);
    p_modValues = (idArray<idActorModifierManager::ActorModifierVar_s,4> *)((char *)p_modValues + 20);
  }
  p_modifiers = &this->modifiers;
  for ( j = 16; j != 0; --j )
  {
    idActorModifier::Serialize(this: p_modifiers->ptr, ser);
    p_modifiers = (idArray<idActorModifier,16> *)((char *)p_modifiers + 888);
  }
}


// ========================================================================
// ??0idActorModifierManager@@QAA@XZ
// EA  : 0x82BEC748
// RVA : 0x00BEC748
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idActorModifierManager *__fastcall idActorModifierManager::idActorModifierManager(idActorModifierManager *this)
{
  idEventReceiver::idEventReceiver(this: &this->idEventReceiver);
  this->parentPtr = nullptr;
  this->__vftable = (idActorModifierManager_vtbl *)&idActorModifierManager::`vftable';
  this->parent.spawnId = 0;
  this->inventory = nullptr;
  this->items.list = nullptr;
  this->items.granularity = 0;
  this->items.memTag = 5;
  this->items.listStatic = 0;
  this->items.size = 0;
  this->items.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->items);
  `eh vector constructor iterator'(
    ptr: &this->modifiers,
    size: 0x378u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idActorModifier::idActorModifier,
    pDtor: (void (__fastcall *)(void *))idActorModifier::~idActorModifier);
  this->modifierUIDCounter = 0;
  this->modValues.ptr[0].netFloat.event.count = 0;
  this->modValues.ptr[0].netFloat.event.lastCount = 0;
  this->modValues.ptr[0].integer = 1;
  this->modValues.ptr[1].netFloat.event.count = 0;
  this->modValues.ptr[1].netFloat.event.lastCount = 0;
  this->modValues.ptr[0].netFloat.value = 0.0;
  this->modValues.ptr[1].integer = 1;
  this->modValues.ptr[0].value = 1.0;
  this->modValues.ptr[2].netFloat.event.count = 0;
  this->modValues.ptr[1].netFloat.value = 0.0;
  this->modValues.ptr[2].netFloat.event.lastCount = 0;
  this->modValues.ptr[1].value = 1.0;
  this->modValues.ptr[2].integer = 1;
  this->modValues.ptr[2].netFloat.value = 0.0;
  this->modValues.ptr[3].netFloat.event.count = 0;
  this->modValues.ptr[2].value = 1.0;
  this->modValues.ptr[3].netFloat.event.lastCount = 0;
  this->modValues.ptr[3].netFloat.value = 0.0;
  this->modValues.ptr[3].integer = 1;
  this->modValues.ptr[3].value = 1.0;
  return this;
}


// ========================================================================
// __unwind$488840_0
// EA  : 0x82BEC848
// RVA : 0x00BEC848
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void _unwind_488840_0()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488841_0
// EA  : 0x82BEC870
// RVA : 0x00BEC870
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void _unwind_488841_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// ??1idActorModifierManager@@UAA@XZ
// EA  : 0x82BEC8A8
// RVA : 0x00BEC8A8
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::~idActorModifierManager(idActorModifierManager *this)
{
  this->__vftable = (idActorModifierManager_vtbl *)&idActorModifierManager::`vftable';
  `eh vector destructor iterator'(
    ptr: &this->modifiers,
    size: 0x378u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idActorModifier::~idActorModifier);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->items);
  idEventReceiver::~idEventReceiver(this: &this->idEventReceiver);
}


// ========================================================================
// __unwind$489022
// EA  : 0x82BEC914
// RVA : 0x00BEC914
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void _unwind_489022()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489023_0
// EA  : 0x82BEC93C
// RVA : 0x00BEC93C
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void _unwind_489023_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ?Update@idActorModifierManager@@AAAXXZ
// EA  : 0x82BEC968
// RVA : 0x00BEC968
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::Update(idActorModifierManager *this)
{
  int v2; // r26
  idPresentablePtr<idPresentableActor> *p_parent; // r29
  int i; // r27
  int v5; // r31
  unsigned int spawnId; // r11
  int v7; // r31
  idPresentableActor *PresentableByIndex; // r4

  p_parent = &this->modifiers.ptr[0].parent;
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  for ( i = 16; i != 0; --i )
  {
    v5 = p_parent->spawnId & 0x3FFF;
    if ( p_parent->spawnId == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_parent->spawnId & 0x3FFF)
      || idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId != p_parent->spawnId )
    {
      spawnId = this->parent.spawnId;
      v7 = spawnId & 0x3FFF;
      if ( spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
        || (PresentableByIndex = (idPresentableActor *)idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != this->parent.spawnId )
      {
        PresentableByIndex = nullptr;
      }
      idActorModifier::SetParent(this: (idActorModifier *)&p_parent[-207], parent_: PresentableByIndex);
    }
    idActorModifier::Update(this: (idActorModifier *)&p_parent[-207], gameTime: v2);
    p_parent += 222;
  }
}


// ========================================================================
// ?ServerThink@idActorModifierManager@@QAAXXZ
// EA  : 0x82BECA60
// RVA : 0x00BECA60
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

// attributes: thunk
void __fastcall idActorModifierManager::ServerThink(idActorModifierManager *this)
{
  idActorModifierManager::Update(this);
}


// ========================================================================
// ?AddModifier@idActorModifierManager@@QAAPAVidActorModifier@@PBVidDeclActorModifier@@PBVidActorModifierItem@@@Z
// EA  : 0x82BECA68
// RVA : 0x00BECA68
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idActorModifier *__fastcall idActorModifierManager::AddModifier(
        idActorModifierManager *this,
        const idDeclActorModifier *decl,
        const idActorModifierItem *item)
{
  idActorModifier *result; // r3
  idActorModifier *v7; // r31
  idPresentableActor *v8; // r3

  result = idActorModifierManager::AssignAvailableModifier(this);
  v7 = result;
  if ( result != nullptr )
  {
    idPresentablePtr<idPresentable>::IsValid(this: &this->parent);
    v8 = (idPresentableActor *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->parent);
    idActorModifier::SetParent(this: v7, parent_: v8);
    v7->item = item;
    v7->decl = decl;
    idEventReceiver::AddEventListener(this: v7, listener: &this->idEventReceiver);
    idActorModifier::SetValid(this: v7, valid_: true);
    idActorModifier::SetDefaults(this: v7);
    v7->added.count = (v7->added.count + 1) % 7;
    return v7;
  }
  return result;
}


// ========================================================================
// ?FindModifierByInstigator@idActorModifierManager@@AAAPAVidActorModifier@@PBVidDeclActorModifier@@PAVidPresentableActor@@@Z
// EA  : 0x82BECB20
// RVA : 0x00BECB20
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idArray<idActorModifier,16> *__fastcall idActorModifierManager::FindModifierByInstigator(
        idActorModifierManager *this,
        const idDeclActorModifier *decl,
        idPresentableActor *instigator)
{
  int v6; // r28
  idPresentablePtr<idPresentableActor> *i; // r30
  int v8; // r31
  idPresentableActor *PresentableByIndex; // r3

  v6 = 0;
  for ( i = &this->modifiers.ptr[0].instigator; ; i += 222 )
  {
    if ( BYTE1(i[12].spawnId) != 0 )
    {
      v8 = i->spawnId & 0x3FFF;
      if ( i->spawnId == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: i->spawnId & 0x3FFF)
        || (PresentableByIndex = (idPresentableActor *)idClientGame::GetPresentableByIndex(this: clientGame, index: v8))->spawnId != i->spawnId )
      {
        PresentableByIndex = nullptr;
      }
      if ( PresentableByIndex == instigator && (const idDeclActorModifier *)i[1].spawnId == decl )
        break;
    }
    if ( ++v6 >= 16 )
      return nullptr;
  }
  return (idArray<idActorModifier,16> *)((char *)&this->modifiers + 888 * v6);
}


// ========================================================================
// ?Notice_ModifierEvent@idActorModifierManager@@QAA?AVeventVoid@@PAVidActorModifier@@_N1@Z
// EA  : 0x82BECBE0
// RVA : 0x00BECBE0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idActorModifierManager *__fastcall idActorModifierManager::Notice_ModifierEvent(
        idActorModifierManager *this,
        idActorModifierManager *result,
        idActorModifier *modifier,
        bool activating,
        bool predicted)
{
  const idDeclActorModifier *decl; // r31
  int v10; // r27
  int v11; // r28
  int v12; // r30
  int v13; // r31
  int v14; // r30

  decl = modifier->decl;
  if ( decl != nullptr )
  {
    v10 = 0;
    v11 = 0;
    if ( decl->outputs.num > 0 )
    {
      v12 = 0;
      do
      {
        if ( !common->IsServer(this: common) || !activating || decl->outputs.list[v12].action != ACTION_DROP_POI )
        {
          if ( common->IsServer(this: common)
            && activating
            && decl->outputs.list[v12].action == ACTION_CLEAR_OVERDRIVE_POINTS )
          {
            if ( idPresentablePtr<idPresentable>::IsValid(this: &result->parent) )
              *(float *)&idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&result->parent)[12].entityTypeFlags = 0.0;
          }
          else if ( (!predicted || decl->outputs.list[v12].predicted)
                 && (!common->IsClient(this: common) || predicted || !decl->outputs.list[v12].predicted) )
          {
            v10 |= 1 << decl->outputs.list[v12].attrib;
          }
        }
        ++v11;
        ++v12;
      }
      while ( v11 < decl->outputs.num );
    }
    v13 = 1;
    v14 = 2;
    do
    {
      if ( (v14 & v10) != 0 )
        idActorModifierManager::RecalculateModValue(this: result, attrib: v13);
      ++v13;
      v14 = __ROL4__(v14, 1);
    }
    while ( v13 < 4 );
  }
  return this;
}


// ========================================================================
// ?InventoryItemAdded@idActorModifierManager@@QAAXPAVidInventoryItem@@PAVidEntity@@@Z
// EA  : 0x82BECDF8
// RVA : 0x00BECDF8
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __fastcall idActorModifierManager::InventoryItemAdded(
        idActorModifierManager *this,
        idActorModifierItem *item,
        idEntity *owner)
{
  int v5; // r11
  char v6; // r11
  bool v7; // zf
  idActorModifierItem *v8; // r3
  idDeclInventory *decl; // r11
  const idActorModifierItem *v10; // r31
  const idDeclActorModifier *v11; // r4

  v5 = *(_DWORD *)(item->GetType(this: item) + 36);
  if ( v5 < idActorModifierItem::Type.typeNum || (v7 = v5 <= idActorModifierItem::Type.lastChild, v6 = 1, !v7) )
    v6 = 0;
  if ( v6 != 0 )
  {
    v8 = idActorModifierItem::CastTo(c: item);
    decl = (idDeclInventory *)item->decl;
    v10 = v8;
    if ( decl != nullptr )
    {
      v11 = (const idDeclActorModifier *)_RTDynamicCast(
                                           inptr: decl,
                                           VfDelta: 0,
                                           SrcType: &idDeclInventory `RTTI Type Descriptor',
                                           TargetType: (void *)&idDeclActorModifier `RTTI Type Descriptor',
                                           isReference: 0);
      if ( v11 != nullptr )
        idActorModifierManager::AddModifier(this, decl: v11, item: v10);
    }
  }
}


// ========================================================================
// ?AddModifierUnique@idActorModifierManager@@QAAPAVidActorModifier@@PBVidDeclActorModifier@@PBVidActorModifierItem@@PAVidPresentableActor@@@Z
// EA  : 0x82BECEC8
// RVA : 0x00BECEC8
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

idArray<idActorModifier,16> *__fastcall idActorModifierManager::AddModifierUnique(
        idActorModifierManager *this,
        const idDeclActorModifier *decl,
        const idActorModifierItem *item,
        idPresentableActor *instigator)
{
  idArray<idActorModifier,16> *ModifierByInstigator; // r31
  idArray<idActorModifier,16> *result; // r3
  unsigned int spawnId; // r11

  ModifierByInstigator = idActorModifierManager::FindModifierByInstigator(this, decl, instigator);
  if ( ModifierByInstigator != nullptr )
  {
    ModifierByInstigator->ptr[0].activationTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    return ModifierByInstigator;
  }
  else
  {
    result = (idArray<idActorModifier,16> *)idActorModifierManager::AddModifier(this, decl, item: nullptr);
    if ( result != nullptr )
    {
      spawnId = 0;
      if ( instigator != nullptr )
        spawnId = instigator->spawnId;
      result->ptr[0].instigator.spawnId = spawnId;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}


// ========================================================================
// `dynamic initializer for 'g_debugActorModifiers''
// EA  : 0x83374868
// RVA : 0x01374868
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugActorModifiers__()
{
  idCVar::idCVar(
    this: &g_debugActorModifiers,
    name: "g_debugActorModifiers",
    value: "0",
    flags: 1,
    description: "Draw debug actor modifier info to the HUD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugActorModifiers__);
}


// ========================================================================
// `dynamic initializer for 'g_enableOverrideReferenceRenderPath''
// EA  : 0x833748C0
// RVA : 0x013748C0
// PDB : w:\tech5\tungsten\game\entities\actormodifiermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_enableOverrideReferenceRenderPath__()
{
  idCVar::idCVar(
    this: &g_enableOverrideReferenceRenderPath,
    name: "g_enableOverrideReferenceRenderPath",
    value: "1",
    flags: 1,
    description: "Draw reference (C++) path progress bar for overdrive",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_enableOverrideReferenceRenderPath__);
}

