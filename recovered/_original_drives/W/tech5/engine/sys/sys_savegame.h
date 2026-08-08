
// ========================================================================
// ?SetSlotName@idSaveGameDetails@@QAAXPBD@Z
// EA  : 0x829BB180
// RVA : 0x009BB180
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

void __fastcall idSaveGameDetails::SetSlotName(idSaveGameDetails *this, const char *slotName_)
{
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  idStrStatic<64> v6; // [sp+50h] [-70h] BYREF

  idStrStatic<64>::idStrStatic<64>(this: &v6, text: slotName_);
  data = v6.data;
  v4 = v6.len + 1;
  v5 = this->slotName.data;
  this->slotName.len = v6.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// ??1idSaveGameProcessor@@UAA@XZ
// EA  : 0x829BBE70
// RVA : 0x009BBE70
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

void __fastcall idSaveGameProcessor::~idSaveGameProcessor(idSaveGameProcessor *this)
{
  this->__vftable = (idSaveGameProcessor_vtbl *)&idSaveGameProcessor::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->completedCallbacks);
  idSaveLoadParms::~idSaveLoadParms(this: &this->parms);
}


// ========================================================================
// __unwind$222180_0
// EA  : 0x829BBEC4
// RVA : 0x009BBEC4
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

void _unwind_222180_0()
{
  int v0; // r12

  idSaveLoadParms::~idSaveLoadParms(this: (idSaveLoadParms *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?Name@idSaveGameProcessor@@UBAPBDXZ
// EA  : 0x829BBEF0
// RVA : 0x009BBEF0
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

const char *__fastcall idSaveGameProcessor::Name(idSaveGameProcessor *this)
{
  return "idSaveGameProcessor";
}


// ========================================================================
// ?GetDescriptorInt@idSaveGameDetails@@QBAHPBDH@Z
// EA  : 0x829BCA20
// RVA : 0x009BCA20
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

int __fastcall idSaveGameDetails::GetDescriptorInt(idSaveGameDetails *this, const char *key, int defaultInt)
{
  const idKeyValue *v4; // r3
  const char *data; // r3

  v4 = idDict::FindKey(this: &this->descriptors, key);
  if ( v4 != nullptr && (data = v4->value.data) != nullptr )
    return atol(nptr: data);
  else
    return defaultInt;
}


// ========================================================================
// ?GetGameVersion@idSaveGameDetails@@QBAHXZ
// EA  : 0x829CBC58
// RVA : 0x009CBC58
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

int __fastcall idSaveGameDetails::GetGameVersion(idSaveGameDetails *this)
{
  const idKeyValue *Key; // r3
  const char *data; // r3

  Key = idDict::FindKey(this: &this->descriptors, key: "gameVersion");
  if ( Key != nullptr && (data = Key->value.data) != nullptr )
    return atol(nptr: data);
  else
    return 0;
}


// ========================================================================
// ?GetMapName@idSaveGameDetails@@QBA?AVidStr@@XZ
// EA  : 0x829CC0D0
// RVA : 0x009CC0D0
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

idSaveGameDetails *__fastcall idSaveGameDetails::GetMapName(idSaveGameDetails *this, idDict *result)
{
  const idKeyValue *Key; // r3
  const char *data; // r4

  Key = idDict::FindKey(this: result, key: "mapName");
  if ( Key != nullptr )
    data = Key->value.data;
  else
    data = &byte_8200D768;
  idStr::idStr((idStr *)this, text: data);
  return this;
}


// ========================================================================
// ?GetSlotName@idSaveGameDetails@@QBA?AV?$idStrStatic@$0EA@@@XZ
// EA  : 0x829CC850
// RVA : 0x009CC850
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

idSaveGameDetails *__fastcall idSaveGameDetails::GetSlotName(idSaveGameDetails *this, idStrStatic<64> *result)
{
  idStrStatic<64>::idStrStatic<64>((idStrStatic<64> *)this, text: (const idStr *)&result->buffer[32]);
  return this;
}


// ========================================================================
// ?GetDirectory@idSaveLoadParms@@QBA?BV?$idStrStatic@$0EA@@@XZ
// EA  : 0x829DB538
// RVA : 0x009DB538
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

idSaveLoadParms *__fastcall idSaveLoadParms::GetDirectory(idSaveLoadParms *this, const idStrStatic<64> *result)
{
  idStrStatic<64>::idStrStatic<64>(this: &this->directory, text: result);
  return this;
}


// ========================================================================
// ?GetPattern@idSaveLoadParms@@QAA?AV?$idStrStatic@$07@@XZ
// EA  : 0x829DB568
// RVA : 0x009DB568
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

idSaveLoadParms *__fastcall idSaveLoadParms::GetPattern(idSaveLoadParms *this, idStrStatic<8> *result)
{
  idStrStatic<8>::idStrStatic<8>((idStrStatic<8> *)this, text: (idStrStatic<8> *)((char *)result + 96));
  return this;
}


// ========================================================================
// ?GetPostPattern@idSaveLoadParms@@QAA?AV?$idStrStatic@$07@@XZ
// EA  : 0x829DB5A0
// RVA : 0x009DB5A0
// PDB : w:\tech5\engine\sys\sys_savegame.h
// ========================================================================

idSaveLoadParms *__fastcall idSaveLoadParms::GetPostPattern(idSaveLoadParms *this, idStrStatic<8> *result)
{
  idStrStatic<8>::idStrStatic<8>((idStrStatic<8> *)this, text: (idStrStatic<8> *)((char *)result + 136));
  return this;
}

