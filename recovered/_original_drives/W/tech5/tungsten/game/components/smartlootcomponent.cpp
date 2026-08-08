
// ========================================================================
// ??0idSmartLootComponent@@QAA@XZ
// EA  : 0x82BB6BE8
// RVA : 0x00BB6BE8
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

idSmartLootComponent *__fastcall idSmartLootComponent::idSmartLootComponent(idSmartLootComponent *this)
{
  this->decl = nullptr;
  this->__vftable = (idSmartLootComponent_vtbl *)&idSmartLootComponent::`vftable';
  this->weaponDecl = nullptr;
  this->customItem = nullptr;
  this->weaponItem = nullptr;
  this->ammoItem = nullptr;
  this->randomItem = nullptr;
  return this;
}


// ========================================================================
// ??1idSmartLootComponent@@UAA@XZ
// EA  : 0x82BB6C18
// RVA : 0x00BB6C18
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void __fastcall idSmartLootComponent::~idSmartLootComponent(idSmartLootComponent *this)
{
  idInventoryItem *customItem; // r3
  idInventoryItem *weaponItem; // r3
  idInventoryItem *ammoItem; // r3
  idInventoryItem *randomItem; // r3

  customItem = this->customItem;
  this->__vftable = (idSmartLootComponent_vtbl *)&idSmartLootComponent::`vftable';
  if ( customItem != nullptr )
    ((void (__fastcall *)(idInventoryItem *, int))customItem->dtr_idClass)(a1: customItem, a2: 1);
  weaponItem = this->weaponItem;
  this->customItem = nullptr;
  if ( weaponItem != nullptr )
    ((void (__fastcall *)(idInventoryItem *, int))weaponItem->dtr_idClass)(a1: weaponItem, a2: 1);
  ammoItem = this->ammoItem;
  this->weaponItem = nullptr;
  if ( ammoItem != nullptr )
    ((void (__fastcall *)(idInventoryItem *, int))ammoItem->dtr_idClass)(a1: ammoItem, a2: 1);
  randomItem = this->randomItem;
  this->ammoItem = nullptr;
  if ( randomItem != nullptr )
    ((void (__fastcall *)(idInventoryItem *, int))randomItem->dtr_idClass)(a1: randomItem, a2: 1);
  this->randomItem = nullptr;
}


// ========================================================================
// ?Activate@idSmartLootComponent@@QAAXPAVidEntity@@@Z
// EA  : 0x82BB6D48
// RVA : 0x00BB6D48
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void __fastcall idSmartLootComponent::Activate(idSmartLootComponent *this, idEntity *owner)
{
  idInventoryCollection *v4; // r25
  int v5; // r24
  int v6; // r26
  idWeapon *v7; // r30
  idWeapon *v8; // r3
  const idDeclWeapon *decl; // r11
  idGameLocal_vtbl *v10; // r31
  idTypeInfoSettings *v11; // r3
  idProp_Moveable *v12; // r31
  idProp_Moveable *v13; // r3
  const idDeclWeapon *inventoryDecl; // r11
  const idDeclInventory *v15; // r31
  idInventoryItem *v16; // r3
  idPresentable *presentable; // r31
  idInventoryCollection *v18; // r3
  idTypeInfoSettings v19[9]; // [sp+50h] [-70h] BYREF

  if ( idGameLocal::GetPlayer(this: gameLocal, i: 0) != nullptr )
  {
    v4 = owner->GetInventory_2(this: owner);
    v5 = 0;
    if ( v4->inventory.num > 0 )
    {
      v6 = 0;
      do
      {
        v7 = (idWeapon *)v4->inventory.list[v6];
        v8 = idWeapon::CastTo(c: v7);
        if ( v8 != nullptr )
        {
          decl = (const idDeclWeapon *)v8->decl;
          this->weaponDecl = decl;
          if ( decl->entityDef != nullptr )
          {
            v10 = gameLocal->__vftable;
            v11 = idTypeInfoSettings::idTypeInfoSettings(this: v19);
            v12 = (idProp_Moveable *)v10->CreateEntityFromDef(this: gameLocal, a2: this->weaponDecl->entityDef, a3: v11);
            v13 = idProp_Moveable::CastTo(c: v12);
            if ( v13 != nullptr && (inventoryDecl = (const idDeclWeapon *)v13->inventoryDecl) != nullptr )
              this->weaponDecl = inventoryDecl;
            else
              this->weaponDecl = nullptr;
            if ( v12 != nullptr )
              ((void (__fastcall *)(idProp_Moveable *, int))v12->dtr_idClass)(a1: v12, a2: 1);
          }
        }
        else if ( v7 != nullptr && this->customItem == nullptr )
        {
          v15 = v7->decl;
          v16 = idInventoryItem::Create(decl: v15);
          this->customItem = v16;
          if ( v16 != nullptr )
          {
            v16->lootable = true;
            presentable = owner->presentable;
            if ( presentable != nullptr )
            {
              v18 = owner->GetInventory_2(this: owner);
              idInventoryCollection::RemoveItemFromInventory(this: v18, owner: presentable, item: v7);
            }
          }
          else
          {
            idLib::Warning(fmt: "idSmartLootComponent failed to spawn customItem from decl '%s'", v15->name.str);
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v4->inventory.num );
    }
  }
}


// ========================================================================
// ?IsCompatibleAmmo@@YA_NPBVidDeclInventory@@PBVidDeclWeapon@@@Z
// EA  : 0x82BB6EE0
// RVA : 0x00BB6EE0
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

int __fastcall IsCompatibleAmmo(const idDeclAmmo *ammo, const idDeclWeapon *weapon)
{
  int num; // r9
  int v3; // r10
  int v4; // r11
  int v5; // r8
  int v6; // r10
  int i; // r11

  num = weapon->validAmmoClips.num;
  v3 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    v5 = weapon->validAmmoClipsSecondary.num;
    v6 = 0;
    if ( v5 <= 0 )
      return 0;
    for ( i = 0; weapon->validAmmoClipsSecondary.list[i].validAmmoDecl != ammo; ++i )
    {
      if ( ++v6 >= v5 )
        return 0;
    }
  }
  else
  {
    v4 = 0;
    while ( weapon->validAmmoClips.list[v4].validAmmoDecl != ammo )
    {
      ++v3;
      ++v4;
      if ( v3 >= num )
        goto LABEL_5;
    }
  }
  return 1;
}


// ========================================================================
// ?GetTotalAmmoInInventory@@YAHPBVidInventoryCollection@@PBVidDeclInventory@@@Z
// EA  : 0x82BB6F58
// RVA : 0x00BB6F58
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

int __fastcall GetTotalAmmoInInventory(const idInventoryCollection *inventory, const idDeclInventory *ammo)
{
  int v4; // r27
  int v5; // r25
  int v6; // r29
  idWeapon *v7; // r3
  bool v8; // zf
  int v9; // r3
  idWeapon *v10; // r3
  idWeapon *v11; // r30
  _DWORD *v12; // r31
  _DWORD *v13; // r31

  v4 = 0;
  v5 = 0;
  if ( inventory->inventory.num > 0 )
  {
    v6 = 0;
    do
    {
      v8 = idStr::Cmp(s1: inventory->inventory.list[v6]->decl->internalName.data, s2: ammo->internalName.data) != 0;
      v7 = (idWeapon *)inventory->inventory.list[v6];
      if ( v8 )
      {
        v10 = idWeapon::CastTo(c: v7);
        v11 = v10;
        if ( v10 == nullptr )
          goto LABEL_13;
        v12 = &v10->ammoClip->__vftable;
        if ( v12 != nullptr && idStr::Cmp(s1: *(const char **)(v12[3] + 172), s2: ammo->internalName.data) == 0 )
          v4 += (*(int (__fastcall **)(_DWORD *))(*v12 + 52))(a1: v12);
        v13 = &v11->ammoClipSecondary->__vftable;
        if ( v13 == nullptr || idStr::Cmp(s1: *(const char **)(v13[3] + 172), s2: ammo->internalName.data) != 0 )
          goto LABEL_13;
        v9 = (*(int (__fastcall **)(_DWORD *))(*v13 + 52))(a1: v13);
      }
      else
      {
        v9 = v7->GetCount(this: v7);
      }
      v4 += v9;
LABEL_13:
      ++v5;
      ++v6;
    }
    while ( v5 < inventory->inventory.num );
  }
  return v4;
}


// ========================================================================
// ??$GetWeightedRandom@UtempItemGroup_t@?A0x4148b61e@@$0BA@@@YAHPBUtempItemGroup_t@?A0x4148b61e@@H@Z
// EA  : 0x82BB7068
// RVA : 0x00BB7068
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

int __fastcall GetWeightedRandom<`anonymous namespace'::tempItemGroup_t,16>(const tempItemGroup_t *list, int num)
{
  int v2; // r11
  double v3; // fp0
  double v4; // fp13
  double weight; // fp10
  float *p_weight; // r10
  double v7; // fp0
  int v8; // r11
  double v9; // fp10
  __int64 v10; // r6
  float *i; // r10

  if ( num == 0 )
    return -1;
  v2 = 0;
  v3 = 0.0;
  v4 = 0.0;
  weight = 0.0;
  if ( num >= 2 )
  {
    p_weight = &list[-1].weight;
    do
    {
      v2 += 2;
      v3 = (float)(p_weight[5] + (float)v3);
      p_weight += 10;
      v4 = (float)(*p_weight + (float)v4);
    }
    while ( v2 < num - 1 );
  }
  if ( v2 < num )
    weight = list[v2].weight;
  v8 = 0;
  v9 = (float)((float)((float)v4 + (float)v3) + (float)weight);
  v7 = 0.0;
  HIDWORD(v10) = 1664525 * clientGame->random.seed;
  clientGame->random.seed = HIDWORD(v10) + 1013904223;
  if ( num <= 0 )
    return -1;
  for ( i = &list->weight; ; i += 5 )
  {
    v7 = (float)(*i + (float)v7);
    LODWORD(v10) = ((unsigned int)(HIDWORD(v10) + 1013904223) >> 10) & 0x7FFF;
    if ( (float)((float)((float)v9 * (float)v10) * (float)0.000030518509) < v7 )
      break;
    if ( ++v8 >= num )
      return -1;
  }
  return v8;
}


// ========================================================================
// ??$GetWeightedRandom@UtempItem_t@?A0x4148b61e@@$0A@@@YAHPBUtempItem_t@?A0x4148b61e@@H@Z
// EA  : 0x82BB7168
// RVA : 0x00BB7168
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

int __fastcall GetWeightedRandom<`anonymous namespace'::tempItem_t,0>(const tempItem_t *list, int num)
{
  int v2; // r10
  double v3; // fp0
  double v4; // fp13
  double weight; // fp10
  const tempItem_t *v6; // r11
  double v7; // fp0
  int v8; // r11
  double v9; // fp10
  __int64 v10; // r6
  const tempItem_t *i; // r10

  if ( num == 0 )
    return -1;
  v2 = 0;
  v3 = 0.0;
  v4 = 0.0;
  weight = 0.0;
  if ( num >= 2 )
  {
    v6 = list - 1;
    do
    {
      v2 += 2;
      v3 = (float)(v6[1].weight + (float)v3);
      v6 += 2;
      v4 = (float)(v6->weight + (float)v4);
    }
    while ( v2 < num - 1 );
  }
  if ( v2 < num )
    weight = list[v2].weight;
  v8 = 0;
  v9 = (float)((float)((float)v4 + (float)v3) + (float)weight);
  v7 = 0.0;
  HIDWORD(v10) = 1664525 * clientGame->random.seed;
  clientGame->random.seed = HIDWORD(v10) + 1013904223;
  if ( num <= 0 )
    return -1;
  for ( i = list; ; ++i )
  {
    v7 = (float)(i->weight + (float)v7);
    LODWORD(v10) = ((unsigned int)(HIDWORD(v10) + 1013904223) >> 10) & 0x7FFF;
    if ( (float)((float)((float)v9 * (float)v10) * (float)0.000030518509) < v7 )
      break;
    if ( ++v8 >= num )
      return -1;
  }
  return v8;
}


// ========================================================================
// ?PeekLootItems@idSmartLootComponent@@QBA_NAAV?$idStaticList@PAVidInventoryItem@@$02@@_N@Z
// EA  : 0x82BB7368
// RVA : 0x00BB7368
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

unsigned int __fastcall idSmartLootComponent::PeekLootItems(
        idSmartLootComponent *this,
        idList<idVehicleState *,5> *output,
        const bool weaponStuffOnly)
{
  idInventoryItem **p_customItem; // r4
  idInventoryItem **p_weaponItem; // r4

  idList<idThread *,58>::Clear(this: output);
  if ( !weaponStuffOnly )
  {
    p_customItem = &this->customItem;
    if ( this->customItem != nullptr || (p_customItem = &this->randomItem, this->randomItem != nullptr) )
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)output,
        obj: (encounterGroupRole_t *)p_customItem);
  }
  p_weaponItem = &this->weaponItem;
  if ( this->weaponItem != nullptr || (p_weaponItem = &this->ammoItem, this->ammoItem != nullptr) )
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)output,
      obj: (encounterGroupRole_t *)p_weaponItem);
  return (-output->num & (unsigned int)~output->num) >> 31;
}


// ========================================================================
// ?GetLootItems@idSmartLootComponent@@QAA_NAAV?$idStaticList@PAVidInventoryItem@@$02@@_N@Z
// EA  : 0x82BB7400
// RVA : 0x00BB7400
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

unsigned int __fastcall idSmartLootComponent::GetLootItems(
        idSmartLootComponent *this,
        idList<idVehicleState *,5> *output,
        bool weaponStuffOnly)
{
  unsigned int result; // r3

  result = idSmartLootComponent::PeekLootItems(this, output, weaponStuffOnly);
  this->weaponDecl = nullptr;
  this->weaponItem = nullptr;
  this->ammoItem = nullptr;
  if ( !weaponStuffOnly )
  {
    this->customItem = nullptr;
    this->randomItem = nullptr;
    this->decl = nullptr;
  }
  return result;
}


// ========================================================================
// ?CreateRandomItem@@YAPAVidInventoryItem@@PAUtempItemGroup_t@?A0x4148b61e@@H@Z
// EA  : 0x82BB7468
// RVA : 0x00BB7468
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idInventoryItem *__fastcall CreateRandomItem(tempItemGroup_t *groups, int numGroups)
{
  int v3; // r10
  tempItemGroup_t *v4; // r11
  tempItemGroup_t *v5; // r11
  int v6; // ctr
  char v7; // r8
  int v8; // r10
  float *p_val; // r11
  double v10; // fp13
  double v11; // fp13
  double v12; // fp13
  double v13; // fp13
  int v14; // ctr
  float *v15; // r11
  double v16; // fp13
  int v17; // r10
  float *p_weight; // r11
  float *v19; // r7
  float *v20; // r7
  float *v21; // r7
  float *v22; // r7
  int v23; // ctr
  float *v24; // r11
  float *v25; // r10
  int v26; // r3
  int v27; // r27
  tempItemGroup_t *v29; // r29
  _BYTE v30[12]; // r11 OVERLAPPED
  const mgDeclSmartLoot::itemGroup_t *group; // r30
  int num; // r28
  int v33; // r8
  __int64 v34; // r4 OVERLAPPED
  double v35; // fp0
  int v36; // r5
  __int64 v37; // fp12
  double v38; // fp9
  __int64 v39; // r6
  int v40; // r10
  int v41; // r11
  int v42; // ctr
  double v43; // fp0
  int v44; // r5
  int v45; // r30
  idInventoryItem *v46; // r3
  idInventoryItem *v47; // r29
  int v48; // r4
  idList<idSpawnArea::GeneratedPosition *,5> v49; // [sp+70h] [-80h] BYREF
  int v50; // [sp+80h] [-70h] BYREF

  v3 = 0;
  if ( numGroups >= 4 )
  {
    v4 = groups + 1;
    do
    {
      if ( v4[-1].group->weight == 0.0 )
        v4[-1].disabled = true;
      if ( v4->group->weight == 0.0 )
        v4->disabled = true;
      if ( v4[1].group->weight == 0.0 )
        v4[1].disabled = true;
      if ( v4[2].group->weight == 0.0 )
        v4[2].disabled = true;
      v3 += 4;
      v4 += 4;
    }
    while ( v3 < numGroups - 3 );
  }
  if ( v3 < numGroups )
  {
    v5 = &groups[v3];
    v6 = numGroups - v3;
    do
    {
      if ( v5->group->weight == 0.0 )
        v5->disabled = true;
      ++v5;
      --v6;
    }
    while ( v6 != 0 );
  }
  v7 = 1;
  v8 = 0;
  if ( numGroups >= 4 )
  {
    p_val = &groups->val;
    do
    {
      if ( *((_BYTE *)p_val - 4) == 0 )
      {
        v10 = (float)((float)1.0 - (float)(*p_val / *(float *)(*((_DWORD *)p_val - 2) + 4)));
        if ( v10 >= 0.0 )
        {
          if ( v10 > 1.0 )
            v10 = 1.0;
        }
        else
        {
          v10 = 0.0;
        }
        p_val[1] = v10;
        if ( v10 > 0.0 )
          v7 = 0;
      }
      if ( *((_BYTE *)p_val + 16) == 0 )
      {
        v11 = (float)((float)1.0 - (float)(p_val[5] / *(float *)(*((_DWORD *)p_val + 3) + 4)));
        if ( v11 >= 0.0 )
        {
          if ( v11 > 1.0 )
            v11 = 1.0;
        }
        else
        {
          v11 = 0.0;
        }
        p_val[6] = v11;
        if ( v11 > 0.0 )
          v7 = 0;
      }
      if ( *((_BYTE *)p_val + 36) == 0 )
      {
        v12 = (float)((float)1.0 - (float)(p_val[10] / *(float *)(*((_DWORD *)p_val + 8) + 4)));
        if ( v12 >= 0.0 )
        {
          if ( v12 > 1.0 )
            v12 = 1.0;
        }
        else
        {
          v12 = 0.0;
        }
        p_val[11] = v12;
        if ( v12 > 0.0 )
          v7 = 0;
      }
      if ( *((_BYTE *)p_val + 56) == 0 )
      {
        v13 = (float)((float)1.0 - (float)(p_val[15] / *(float *)(*((_DWORD *)p_val + 13) + 4)));
        if ( v13 >= 0.0 )
        {
          if ( v13 > 1.0 )
            v13 = 1.0;
        }
        else
        {
          v13 = 0.0;
        }
        p_val[16] = v13;
        if ( v13 > 0.0 )
          v7 = 0;
      }
      v8 += 4;
      p_val += 20;
    }
    while ( v8 < numGroups - 3 );
  }
  if ( v8 < numGroups )
  {
    v14 = numGroups - v8;
    v15 = &groups[v8].val;
    do
    {
      if ( *((_BYTE *)v15 - 4) == 0 )
      {
        v16 = (float)((float)1.0 - (float)(*v15 / *(float *)(*((_DWORD *)v15 - 2) + 4)));
        if ( v16 >= 0.0 )
        {
          if ( v16 > 1.0 )
            v16 = 1.0;
        }
        else
        {
          v16 = 0.0;
        }
        v15[1] = v16;
        if ( v16 > 0.0 )
          v7 = 0;
      }
      v15 += 5;
      --v14;
    }
    while ( v14 != 0 );
  }
  v17 = 0;
  if ( numGroups >= 4 )
  {
    p_weight = &groups->weight;
    do
    {
      if ( *((_BYTE *)p_weight - 12) != 0 )
      {
        *p_weight = 0.0;
      }
      else
      {
        v19 = *((float **)p_weight - 4);
        if ( v7 != 0 )
          *p_weight = *v19;
        else
          *p_weight = *v19 * *(p_weight - 1);
      }
      if ( *((_BYTE *)p_weight + 8) != 0 )
      {
        p_weight[5] = 0.0;
      }
      else
      {
        v20 = *((float **)p_weight + 1);
        if ( v7 != 0 )
          p_weight[5] = *v20;
        else
          p_weight[5] = *v20 * p_weight[4];
      }
      if ( *((_BYTE *)p_weight + 28) != 0 )
      {
        p_weight[10] = 0.0;
      }
      else
      {
        v21 = *((float **)p_weight + 6);
        if ( v7 != 0 )
          p_weight[10] = *v21;
        else
          p_weight[10] = *v21 * p_weight[9];
      }
      if ( *((_BYTE *)p_weight + 48) != 0 )
      {
        p_weight[15] = 0.0;
      }
      else
      {
        v22 = *((float **)p_weight + 11);
        if ( v7 != 0 )
          p_weight[15] = *v22;
        else
          p_weight[15] = *v22 * p_weight[14];
      }
      v17 += 4;
      p_weight += 20;
    }
    while ( v17 < numGroups - 3 );
  }
  if ( v17 < numGroups )
  {
    v23 = numGroups - v17;
    v24 = &groups[v17].weight;
    do
    {
      if ( *((_BYTE *)v24 - 12) != 0 )
      {
        *v24 = 0.0;
      }
      else
      {
        v25 = *((float **)v24 - 4);
        if ( v7 != 0 )
          *v24 = *v25;
        else
          *v24 = *v25 * *(v24 - 1);
      }
      v24 += 5;
      --v23;
    }
    while ( v23 != 0 );
  }
  v26 = GetWeightedRandom<`anonymous namespace'::tempItemGroup_t,16>(list: groups, num: numGroups);
  v27 = v26;
  if ( v26 < 0 )
  {
    idLib::Printf(fmt: "NOTE: no smart loot item groups fit the player's need...\n");
    return nullptr;
  }
  *(_QWORD *)&v49.size = 0xA00010501LL;
  *(_DWORD *)v30 = 5 * v26;
  v49.num = 0;
  v29 = &groups[v26];
  *(_QWORD *)&v30[4] = 10;
  v49.list = (idSpawnArea::GeneratedPosition **)&v50;
  group = v29->group;
  num = v29->group->items.num;
  if ( num > 10 )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(this: &v49, newsize: v29->group->items.num) == 0 )
      goto LABEL_96;
    *(_DWORD *)&v30[8] = v49.size;
  }
  v49.num = num;
  if ( num >= *(int *)&v30[8] )
    v49.num = *(_DWORD *)&v30[8];
LABEL_96:
  v33 = 0;
  if ( num >= 4 )
  {
    *(_DWORD *)&v30[8] = num;
    HIDWORD(v34) = num - 3;
    v35 = (float)*(__int64 *)&v30[4];
    *(_DWORD *)&v30[8] = 2;
    *(_DWORD *)v30 = 0;
    *(_DWORD *)&v30[4] = 0;
    do
    {
      v36 = *(_DWORD *)&v30[8];
      LODWORD(v34) = *(_DWORD *)&v30[8] - 1;
      v37 = *(__int64 *)((char *)&v34 - 4);
      v38 = (double)v34;
      LODWORD(v39) = *(_DWORD *)&v30[8] + 1;
      HIDWORD(v39) = *(_DWORD *)&v30[8] + 2;
      LODWORD(v34) = *(_DWORD *)&v30[8] + 2;
      v33 += 4;
      *(_DWORD *)&v30[8] += 4;
      *(float *)((char *)v49.list + *(_DWORD *)v30) = (float)((float)((float)((float)((float)v38 / (float)v35)
                                                                            - (float)1.0)
                                                                    * v29->need)
                                                            + (float)1.0)
                                                    * *(float *)((char *)&group->items.list->weight + *(_DWORD *)&v30[4]);
      *(float *)((char *)v49.list + *(_DWORD *)v30 + 4) = (float)((float)((float)((float)((float)v37 / (float)v35)
                                                                                - (float)1.0)
                                                                        * v29->need)
                                                                + (float)1.0)
                                                        * *(float *)((char *)&group->items.list[1].weight
                                                                   + *(_DWORD *)&v30[4]);
      *(float *)((char *)v49.list + *(_DWORD *)v30 + 8) = (float)((float)((float)((float)((float)v39 / (float)v35)
                                                                                - (float)1.0)
                                                                        * v29->need)
                                                                + (float)1.0)
                                                        * *(float *)((char *)&group->items.list[2].weight
                                                                   + *(_DWORD *)&v30[4]);
      *(float *)((char *)v49.list + *(_DWORD *)v30 + 12) = (float)((float)((float)((float)((float)v34 / (float)v35)
                                                                                 - (float)1.0)
                                                                         * v29->need)
                                                                 + (float)1.0)
                                                         * *(float *)((char *)&group->items.list[3].weight
                                                                    + *(_DWORD *)&v30[4]);
      *(_DWORD *)&v30[4] += 48;
      *(_DWORD *)v30 += 16;
    }
    while ( v33 < SHIDWORD(v34) );
  }
  if ( v33 < num )
  {
    *(_DWORD *)&v30[4] = num;
    *(_DWORD *)&v30[8] = 12 * v33;
    v42 = num - v33;
    v43 = (float)*(__int64 *)v30;
    v40 = v33;
    do
    {
      *(float *)&v49.list[v40] = (float)((float)((float)((float)((float)__SPAIR64__((unsigned int)v49.list, ++v33)
                                                               / (float)v43)
                                                       - (float)1.0)
                                               * v29->need)
                                       + (float)1.0)
                               * *(float *)((char *)&group->items.list->weight + v41);
      v41 += 12;
      ++v40;
      --v42;
    }
    while ( v42 != 0 );
  }
  v44 = GetWeightedRandom<`anonymous namespace'::tempItem_t,0>(list: (const tempItem_t *)v49.list, num);
  if ( v44 < 0 )
  {
    idLib::Printf(fmt: "WARNING: could not pick an item from smart loot group!\n");
    if ( (v49.listStatic == 0 || v49.listStatic == 2) && v49.list != nullptr )
      idMem::Free(this: &mem, ptr: v49.list, align: ALIGN_16);
    return nullptr;
  }
  v45 = (int)&group->items.list[v44];
  idLib::Printf(
    fmt: "[smartloot] g:%d, i:%d, creating item: '%s', count: %d\n",
    v27,
    v44,
    *(const char **)(*(_DWORD *)(v45 + 4) + 8),
    *(_DWORD *)(v45 + 8));
  v46 = idInventoryItem::Create(decl: *(const idDeclInventory **)(v45 + 4));
  v47 = v46;
  if ( v46 != nullptr )
  {
    v48 = *(_DWORD *)(v45 + 8);
    if ( v48 >= 0 )
      idInventoryItem::SetCount(this: v46, amount: v48);
    v47->lootable = true;
    if ( (v49.listStatic == 0 || v49.listStatic == 2) && v49.list != nullptr )
      idMem::Free(this: &mem, ptr: v49.list, align: ALIGN_16);
    return v47;
  }
  else
  {
    idLib::Warning(fmt: "could not create item from smart loot group!");
    if ( v49.listStatic != 0 && v49.listStatic != 2 || v49.list == nullptr )
      return nullptr;
    idMem::Free(this: &mem, ptr: v49.list, align: ALIGN_16);
    return nullptr;
  }
}


// ========================================================================
// __unwind$488962_0
// EA  : 0x82BB7C44
// RVA : 0x00BB7C44
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void _unwind_488962_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// ?CreateRandomItem@idSmartLootComponent@@IAA_NPBVidPlayer@@@Z
// EA  : 0x82BB7C70
// RVA : 0x00BB7C70
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

idInventoryItem *__fastcall idSmartLootComponent::CreateRandomItem(idSmartLootComponent *this, const idPlayer *player)
{
  __int64 v2; // r11
  idPlayer_vtbl *v3; // r8
  const idBaseHealth *(__fastcall *GetHealthComponent)(struct idActor *); // r4
  int v8; // r3
  double v9; // fp1
  idTungstenHealth_vtbl *v10; // r9
  idInventoryItem *result; // r3
  idInventoryItem *v12; // r31
  idInventoryItem *randomItem; // r3
  tempItemGroup_t v14; // [sp+50h] [-40h] BYREF
  int v15; // [sp+64h] [-2Ch]
  __int64 v16; // [sp+68h] [-28h]
  __int64 v17; // [sp+70h] [-20h]

  HIDWORD(v2) = this->decl;
  v3 = player->__vftable;
  LODWORD(v2) = 0;
  v14.group = (const mgDeclSmartLoot::itemGroup_t *)(HIDWORD(v2) + 64);
  memset(&v14.disabled, 0, 16);
  GetHealthComponent = v3->GetHealthComponent;
  v15 = HIDWORD(v2) + 104;
  v16 = v2;
  v17 = v2;
  v8 = (int)GetHealthComponent(this: &player->idActor);
  v9 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v8 + 68))(a1: v8);
  v10 = player->playerHealth.__vftable;
  v14.val = v9;
  *((float *)&v16 + 1) = v10->GetComponentCur_Impl(this: &player->playerHealth, a2: 1);
  result = CreateRandomItem(groups: &v14, numGroups: 2);
  v12 = result;
  if ( result != nullptr )
  {
    randomItem = this->randomItem;
    if ( randomItem != nullptr )
      ((void (__fastcall *)(idInventoryItem *, int))randomItem->dtr_idClass)(a1: randomItem, a2: 1);
    this->randomItem = v12;
    return (idInventoryItem *)1;
  }
  return result;
}


// ========================================================================
// ?CreateRandomAmmo@idSmartLootComponent@@IAA_NPBVidPlayer@@@Z
// EA  : 0x82BB7D60
// RVA : 0x00BB7D60
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

idInventoryItem *__fastcall idSmartLootComponent::CreateRandomAmmo(idSmartLootComponent *this, const idPlayer *player)
{
  const mgDeclSmartLoot *decl; // r11
  __int64 v3; // r31
  idPlayer_vtbl *v4; // r9
  const idInventoryCollection *(__fastcall *GetInventory)(struct idActor *); // r10
  const idInventoryCollection *v7; // r27
  tempItemGroup_t *v8; // r30
  int i; // r28
  const mgDeclSmartLoot::itemGroup_t *group; // r11
  const idDeclInventory *v11; // r6
  __int64 v12; // r11
  idInventoryItem *result; // r3
  idInventoryItem *v14; // r31
  idInventoryItem *ammoItem; // r3
  tempItemGroup_t v16; // [sp+60h] [-90h] BYREF
  mgDeclSmartLoot::itemGroup_t *p_ammo_heavy; // [sp+74h] [-7Ch]
  __int64 v18; // [sp+78h] [-78h]
  __int64 v19; // [sp+80h] [-70h]
  mgDeclSmartLoot::itemGroup_t *p_ammo_grenade; // [sp+88h] [-68h]
  int v21; // [sp+8Ch] [-64h]
  int v22; // [sp+90h] [-60h]
  int v23; // [sp+94h] [-5Ch]
  int v24; // [sp+98h] [-58h]
  mgDeclSmartLoot::itemGroup_t *p_ammo_shells; // [sp+9Ch] [-54h]
  char v26; // [sp+A0h] [-50h] BYREF

  decl = this->decl;
  LODWORD(v3) = 0;
  v4 = player->__vftable;
  v16.group = &decl->ammo.ammo_light;
  memset(&v16.disabled, 0, 16);
  HIDWORD(v3) = &v26;
  p_ammo_heavy = &decl->ammo.ammo_heavy;
  v18 = v3;
  v19 = v3;
  p_ammo_grenade = &decl->ammo.ammo_grenade;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  GetInventory = v4->GetInventory;
  v24 = 0;
  p_ammo_shells = &decl->ammo.ammo_shells;
  *(_QWORD *)HIDWORD(v3) = v3;
  *(_QWORD *)(HIDWORD(v3) + 8) = v3;
  v7 = GetInventory(this: &player->idActor);
  v8 = &v16;
  for ( i = 4; i != 0; --i )
  {
    group = v8->group;
    v8->disabled = true;
    if ( group->items.num > 0
      && (unsigned __int8)IsCompatibleAmmo(ammo: (const idDeclAmmo *)group->items.list->item, weapon: this->weaponDecl) != 0 )
    {
      LODWORD(v12) = GetTotalAmmoInInventory(inventory: v7, ammo: v11);
      v8->disabled = false;
      v8->val = (float)v12;
    }
    ++v8;
  }
  result = CreateRandomItem(groups: &v16, numGroups: 4);
  v14 = result;
  if ( result != nullptr )
  {
    ammoItem = this->ammoItem;
    if ( ammoItem != nullptr )
      ((void (__fastcall *)(idInventoryItem *, int))ammoItem->dtr_idClass)(a1: ammoItem, a2: 1);
    this->ammoItem = v14;
    return (idInventoryItem *)1;
  }
  return result;
}


// ========================================================================
// ?Update@idSmartLootComponentActor@@UAAXPBVidEntity@@PBVidPlayer@@@Z
// EA  : 0x82BB7EB8
// RVA : 0x00BB7EB8
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void __fastcall idSmartLootComponentActor::Update(
        idSmartLootComponentActor *this,
        idActor *owner,
        const idPlayer *player)
{
  idActor *v5; // r29
  const idInventoryCollection *v6; // r3
  idJobManager *v7; // r30
  idWeapon *JobByDecl; // r3
  idEntity *DroppedItem1; // r3
  idProp_Moveable *v10; // r3
  idProp_Moveable *v11; // r3
  idInventoryCollection *v12; // r3
  idWeapon *InventoryItem; // r3
  idWeapon *v14; // r3
  idWeapon *v15; // r30
  idInventoryItem *v16; // r29
  int v17; // r3
  idInventoryItem *weaponItem; // r3
  idWeapon *v19; // r3
  idWeapon *v20; // r3
  idInventoryItem *v21; // r3
  idInventoryItem *ammoItem; // r3

  v5 = idActor::CastTo(c: owner);
  v6 = player->GetInventory(this: player);
  v7 = (idJobManager *)v6;
  if ( this->weaponDecl != nullptr )
  {
    if ( v5 != nullptr && v6 != nullptr && idActor::GetDroppedItem1(this: v5) != nullptr )
    {
      JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v7, jobDecl: (const idDeclJob *)this->weaponDecl);
      if ( idWeapon::CastTo(c: JobByDecl) != nullptr )
      {
        if ( this->ammoItem != nullptr )
          goto LABEL_24;
        idSmartLootComponent::CreateRandomAmmo(this, player);
        if ( this->ammoItem != nullptr )
        {
          DroppedItem1 = idActor::GetDroppedItem1(this: v5);
          if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: DroppedItem1) != 0 )
          {
            v10 = (idProp_Moveable *)idActor::GetDroppedItem1(this: v5);
            v11 = idProp_Moveable::CastTo(c: v10);
            v12 = v11->GetInventory_2(this: v11);
            InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v12, index: 0);
            v14 = idWeapon::CastTo(c: InventoryItem);
            v15 = v14;
            if ( v14 != nullptr )
            {
              v16 = &v14->ammoClip->idInventoryItem;
              if ( v16 != nullptr )
              {
                v17 = this->ammoItem->GetCount(this: this->ammoItem);
                idInventoryItem::SetCount(this: v16, amount: v17);
                *((_BYTE *)v15 + 453) &= ~0x80u;
              }
            }
          }
        }
      }
      else
      {
        if ( this->weaponItem != nullptr )
          goto LABEL_24;
        v19 = (idWeapon *)idInventoryItem::Create(decl: this->weaponDecl);
        this->weaponItem = v19;
        if ( v19 == nullptr )
          goto LABEL_24;
        v20 = idWeapon::CastTo(c: v19);
        if ( v20 != nullptr )
        {
          *((_BYTE *)v20 + 453) &= ~0x80u;
          goto LABEL_24;
        }
      }
      weaponItem = this->weaponItem;
      if ( weaponItem != nullptr )
        ((void (__fastcall *)(idInventoryItem *, int))weaponItem->dtr_idClass)(a1: weaponItem, a2: 1);
      this->weaponItem = nullptr;
    }
    else
    {
      v21 = this->weaponItem;
      if ( v21 != nullptr )
        ((void (__fastcall *)(idInventoryItem *, int))v21->dtr_idClass)(a1: v21, a2: 1);
      ammoItem = this->ammoItem;
      this->weaponItem = nullptr;
      if ( ammoItem != nullptr )
        ((void (__fastcall *)(idInventoryItem *, int))ammoItem->dtr_idClass)(a1: ammoItem, a2: 1);
      this->ammoItem = nullptr;
    }
  }
LABEL_24:
  if ( this->customItem == nullptr
    && this->randomItem == nullptr
    && this->decl != nullptr
    && (unsigned __int8)idSmartLootComponent::CreateRandomItem(this, player) == 0 )
  {
    this->decl = nullptr;
  }
}


// ========================================================================
// ?Update@idSmartLootComponent@@UAAXPBVidEntity@@PBVidPlayer@@@Z
// EA  : 0x82BB81A8
// RVA : 0x00BB81A8
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void __fastcall idSmartLootComponent::Update(idSmartLootComponent *this, const idEntity *owner, const idPlayer *player)
{
  idJobManager *v5; // r3
  const idDeclWeapon *weaponDecl; // r4
  idWeapon *JobByDecl; // r3
  idInventoryItem *weaponItem; // r3
  idWeapon *v9; // r3
  idWeapon *v10; // r3

  v5 = (idJobManager *)player->GetInventory(this: player);
  weaponDecl = this->weaponDecl;
  if ( weaponDecl != nullptr )
  {
    JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v5, jobDecl: (const idDeclJob *)weaponDecl);
    if ( idWeapon::CastTo(c: JobByDecl) != nullptr )
    {
      if ( this->ammoItem != nullptr )
        goto LABEL_8;
      idSmartLootComponent::CreateRandomAmmo(this, player);
    }
    else
    {
      if ( this->weaponItem != nullptr )
        goto LABEL_8;
      v9 = (idWeapon *)idInventoryItem::Create(decl: this->weaponDecl);
      this->weaponItem = v9;
      if ( v9 == nullptr )
        goto LABEL_8;
      v10 = idWeapon::CastTo(c: v9);
      if ( v10 != nullptr )
      {
        *((_BYTE *)v10 + 453) &= ~0x80u;
        goto LABEL_8;
      }
    }
    weaponItem = this->weaponItem;
    if ( weaponItem != nullptr )
      ((void (__fastcall *)(idInventoryItem *, int))weaponItem->dtr_idClass)(a1: weaponItem, a2: 1);
    this->weaponItem = nullptr;
  }
LABEL_8:
  if ( this->customItem == nullptr
    && this->randomItem == nullptr
    && this->decl != nullptr
    && (unsigned __int8)idSmartLootComponent::CreateRandomItem(this, player) == 0 )
  {
    this->decl = nullptr;
  }
}


// ========================================================================
// ?GetPickupHudInfo@idSmartLootComponent@@QBAXPBVidEntity@@PAVidPickupHudInfo@@_N@Z
// EA  : 0x82BB8348
// RVA : 0x00BB8348
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void __fastcall idSmartLootComponent::GetPickupHudInfo(
        idSmartLootComponent *this,
        idPlayer *user,
        idPickupHudInfo *info,
        bool weaponStuffOnly)
{
  idPlayer *v8; // r3
  int v9; // r30
  idPlayer *v10; // r27
  int i; // r24
  idStateData *stateData; // r29
  idJobManager *v13; // r3
  idWeapon *JobByDecl; // r3
  idWeapon *v15; // r3
  idWeapon *v16; // r29
  idPickupHudInfo::item_t *v17; // r3
  const idMaterial *sellPrice; // r10
  idList<idVehicleState *,5> v19; // [sp+60h] [-70h] BYREF
  int v20; // [sp+70h] [-60h] BYREF

  v8 = idPlayer::CastTo(c: user);
  v9 = 0;
  v19.granularity = 1;
  v19.num = 0;
  v19.size = 3;
  v19.list = (idVehicleState **)&v20;
  v10 = v8;
  v19.memTag = 5;
  v19.listStatic = 1;
  if ( (unsigned __int8)idSmartLootComponent::PeekLootItems(this, output: &v19, weaponStuffOnly) != 0 )
  {
    for ( i = 0; i < v19.num; ++v9 )
    {
      stateData = v19.list[v9]->stateData;
      v13 = (idJobManager *)v10->GetInventory(this: v10);
      JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v13, jobDecl: (const idDeclJob *)stateData);
      v15 = idWeapon::CastTo(c: JobByDecl);
      v16 = v15;
      if ( v15 != nullptr && (*((_BYTE *)v15 + 453) & 0x80) != 0 )
      {
        v17 = idList<idPickupHudInfo::item_t,5>::Alloc(this: &info->items);
        sellPrice = (const idMaterial *)v16->decl[3].sellPrice;
        v17->count = 1;
        v17->canPickup = true;
        v17->icon = sellPrice;
      }
      else
      {
        ((void (__fastcall *)(idVehicleState *, idPlayer *, idPickupHudInfo *))v19.list[v9]->__vftable[1].InternalRespondsTo)(
          a1: v19.list[v9],
          a2: user,
          a3: info);
      }
      ++i;
    }
  }
  if ( (v19.listStatic == 0 || v19.listStatic == 2) && v19.list != nullptr )
    idMem::Free(this: &mem, ptr: v19.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$489384
// EA  : 0x82BB84A8
// RVA : 0x00BB84A8
// PDB : w:\tech5\tungsten\game\components\smartlootcomponent.cpp
// ========================================================================

void _unwind_489384()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}

