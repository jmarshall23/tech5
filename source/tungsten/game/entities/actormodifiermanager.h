#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\actormodifiermanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15281; PDB kind: class.
class idActorModifierManager : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15304.
  virtual idTypeInfo *GetType();
  virtual ~idActorModifierManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Serialize(idSerializer *);
  virtual void PostSerializeRead(bool);
  virtual void HandleActorModifierMessage(unsigned int, unsigned __int8);

  idPresentableActor *parentPtr;
  idPresentablePtr<idPresentableActor> parent;
  idInventoryCollection *inventory;
  idList<idActorModifierItem *,5> items;
  idArray<idActorModifier,16> modifiers;
  unsigned int modifierUIDCounter;
  idArray<idActorModifierManager::ActorModifierVar_s,4> modValues;
};

// IDA Local Type ordinal 15302; PDB kind: struct.
struct idActorModifierManager::ActorModifierVar_s
{
  idNetFloat netFloat;
  float value;
  int integer;
};
