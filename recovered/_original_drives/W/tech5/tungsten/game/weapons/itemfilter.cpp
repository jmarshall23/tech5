
// ========================================================================
// ?InternalPostFilterItems@idThrowableFilter@@MAAXXZ
// EA  : 0x82ECCE08
// RVA : 0x00ECCE08
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

void __fastcall idThrowableFilter::InternalPostFilterItems(bfx::Orienter *this)
{
  this->m_state = FACE_IN_TRAVEL_DIR;
}


// ========================================================================
// ?SelectItem@idItemSelector@@SAHAAV1@ABV?$idList@PAVidInventoryItem@@$04@@AAPAVidInventoryItem@@@Z
// EA  : 0x82ECCE18
// RVA : 0x00ECCE18
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

int __fastcall idItemSelector::SelectItem(
        idItemSelector *selector,
        const idList<idInventoryItem *,5> *items,
        idInventoryItem **selectedItem)
{
  int v6; // r26
  int v7; // r29
  double v8; // fp31
  int v9; // r30
  double v10; // fp1

  selector->InternalPreSelectItem(this: selector);
  v6 = -1;
  *selectedItem = nullptr;
  v7 = 0;
  v8 = 0.0;
  if ( items->num > 0 )
  {
    v9 = 0;
    do
    {
      if ( items->list[v9] != nullptr )
      {
        v10 = ((double (__fastcall *)(idItemSelector *))selector->InternalGetWeight)(a1: selector);
        if ( v10 != -1.0 && v10 >= v8 )
        {
          v6 = v7;
          v8 = v10;
          *selectedItem = items->list[v9];
        }
      }
      ++v7;
      ++v9;
    }
    while ( v7 < items->num );
  }
  selector->InternalPostSelectItem(this: selector);
  selector->owner = nullptr;
  return v6;
}


// ========================================================================
// ??0idThrowableFilter@@QAA@XZ
// EA  : 0x82ECCF00
// RVA : 0x00ECCF00
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

idThrowableFilter *__fastcall idThrowableFilter::idThrowableFilter(idThrowableFilter *this)
{
  this->owner = nullptr;
  this->__vftable = (idThrowableFilter_vtbl *)&idThrowableFilter::`vftable';
  this->target = nullptr;
  return this;
}


// ========================================================================
// ?InternalFilter@idThrowableFilter@@MBA_NPBVidInventoryItem@@@Z
// EA  : 0x82ECCF20
// RVA : 0x00ECCF20
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

const idDeclInventory *__fastcall idThrowableFilter::InternalFilter(
        idThrowableFilter *this,
        const idInventoryItem *item)
{
  const idDeclInventory *result; // r3

  result = item->decl;
  if ( result != nullptr )
    return (const idDeclInventory *)((_cntlzw(
                                        (char *)&idDeclThrowable::resourceList
                                      - (char *)result->GetDeclInfo(this: result))
                                    & 0x20) != 0);
  return result;
}


// ========================================================================
// ??0idThrowableSelector@@QAA@XZ
// EA  : 0x82ECCF80
// RVA : 0x00ECCF80
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

idThrowableSelector *__fastcall idThrowableSelector::idThrowableSelector(idThrowableSelector *this)
{
  this->owner = nullptr;
  this->__vftable = (idThrowableSelector_vtbl *)&idThrowableSelector::`vftable';
  this->target = nullptr;
  return this;
}


// ========================================================================
// ?InternalGetWeight@idThrowableSelector@@MBAMPBVidInventoryItem@@@Z
// EA  : 0x82ECCFF8
// RVA : 0x00ECCFF8
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

float __fastcall idThrowableSelector::InternalGetWeight(idThrowableSelector *this, const idInventoryItem *item)
{
  const idDeclInventory *decl; // r3
  double v3; // fp1

  decl = item->decl;
  if ( decl != nullptr && decl->GetDeclInfo(this: decl) == &idDeclThrowable::resourceList )
    v3 = 1.0;
  else
    v3 = -1.0;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?InternalGetWeight@idThrowableSelector_Grenade@@MBAMPBVidInventoryItem@@@Z
// EA  : 0x82ECD060
// RVA : 0x00ECD060
// PDB : w:\tech5\tungsten\game\weapons\itemfilter.cpp
// ========================================================================

float __fastcall idThrowableSelector_Grenade::InternalGetWeight(
        idThrowableSelector_Grenade *this,
        const idInventoryItem *item)
{
  const idDeclInventory *decl; // r3
  double v5; // fp1
  idDeclInventory_vtbl *v6; // r11
  idDeclDamage *LoadResource; // r3
  unsigned int (__fastcall *Size)(struct idDeclInventory *); // r10

  decl = item->decl;
  if ( decl == nullptr )
    goto LABEL_3;
  if ( decl->GetDeclInfo(this: decl) != &idDeclThrowable::resourceList )
    goto LABEL_3;
  v6 = item->decl[1].__vftable;
  if ( v6 == nullptr )
    goto LABEL_3;
  LoadResource = (idDeclDamage *)v6[7].LoadResource;
  if ( LoadResource == nullptr
    || (Size = v6[6].Size) != nullptr && LoadResource->radius <= (double)*((float *)Size + 50) )
  {
    LoadResource = (idDeclDamage *)v6[6].Size;
  }
  if ( LoadResource != nullptr
    && (LoadResource->radius <= 0.0
     || this->target->distSqr > (double)(float)(LoadResource->radius * LoadResource->radius)) )
  {
    v5 = idDeclDamage::DamageAmount(this: LoadResource);
  }
  else
  {
LABEL_3:
    v5 = -1.0;
  }
  return *((float *)&v5 + 1);
}

