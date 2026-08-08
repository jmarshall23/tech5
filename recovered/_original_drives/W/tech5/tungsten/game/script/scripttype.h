
// ========================================================================
// ?Event_Append@idScriptList@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x824FDA98
// RVA : 0x004FDA98
// PDB : w:\tech5\tungsten\game\script\scripttype.h
// ========================================================================

idScriptList *__fastcall idScriptList::Event_Append(idScriptList *this, eventVoid *result, idEntity *toAdd)
{
  idEntityPtr<idEntity> v5; // [sp+50h] [-20h] BYREF

  if ( toAdd != nullptr )
    v5.spawnId.value = (gameLocal->spawnIds.ptr[toAdd->entityNumber] << 13) | toAdd->entityNumber;
  else
    v5.spawnId.value = 0x1FFF;
  idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&result[12], obj: &v5);
  return this;
}

