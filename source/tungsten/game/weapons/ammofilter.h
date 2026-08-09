#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\ammofilter.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15266; PDB kind: class.
class idAmmoItem : public idInventoryItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15267.
  virtual idTypeInfo *GetType();
  virtual ~idAmmoItem();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(const idDeclInventory *);
  virtual void Merge(idPresentable *, idInventoryCollection *, const idDeclInventory *);
  virtual void Hide();
  virtual void Show();
  virtual void OnEquip(const idPresentable *, idFXManager *);
  virtual void OnUnequip(const idPresentable *, idFXManager *);
  virtual void OnClone(const idInventoryItem *);
  virtual int GetCount();
  virtual bool CanUse(idActor *);
  virtual bool Use(idActor *);
  virtual bool CanUseInVehicle(idActor *);
  virtual bool ClientUse(idPresentablePlayer *);
  virtual void Serialize(idSerializer *, idInventoryCollection *);
  virtual void SerializeNonPrediction(idSerializer *, idInventoryCollection *);
  virtual void ClientUpdate();
  virtual void GetPickupHudInfo(const idEntity *, idPickupHudInfo *);

  burstMode_t burstMode;
};

// IDA Local Type ordinal 17558; PDB kind: class.
class idAmmoFilter : public idThrowableFilter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17559.
  virtual idTypeInfo *GetType();
  virtual ~idAmmoFilter();
  virtual void InternalPreFilterItems();
  virtual bool InternalFilter(const idInventoryItem *);
  virtual void InternalPostFilterItems();

  const idWeapon *weapon;
};
