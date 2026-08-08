
// ========================================================================
// ?GetInstance@idAnimRecorder@@SAAAV1@XZ
// EA  : 0x826C9520
// RVA : 0x006C9520
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.h
// ========================================================================

idAnimRecorder *__fastcall idAnimRecorder::GetInstance()
{
  idAnimRecorder *result; // r3

  result = idAnimRecorder::instance;
  if ( idAnimRecorder::instance == nullptr )
  {
    result = idAnimRecorder::allocFunction();
    idAnimRecorder::instance = result;
  }
  return result;
}


// ========================================================================
// ??8NameStruct_t@idAnimRecorder@@QBA_NABU01@@Z
// EA  : 0x826F1058
// RVA : 0x006F1058
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.h
// ========================================================================

int __fastcall idAnimRecorder::NameStruct_t::operator==(
        idAnimRecorder::NameStruct_t *this,
        const idAnimRecorder::NameStruct_t *other)
{
  int v4; // r3
  unsigned __int8 v5; // r11

  if ( idStr::Icmp(s1: this->typeName, s2: other->typeName) != 0 )
    return 0;
  v4 = idStr::Icmp(s1: this->objectName, s2: other->objectName);
  v5 = 1;
  if ( v4 != 0 )
    return 0;
  return v5;
}


// ========================================================================
// ??1idAnimRecorder@@MAA@XZ
// EA  : 0x826F2050
// RVA : 0x006F2050
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.h
// ========================================================================

void __fastcall idAnimRecorder::~idAnimRecorder(idAnimRecorder *this)
{
  this->__vftable = (idAnimRecorder_vtbl *)&idAnimRecorder::`vftable';
  idAnimRecorder::CloseFile(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->networkIDDict);
}


// ========================================================================
// __unwind$247571
// EA  : 0x826F20A0
// RVA : 0x006F20A0
// PDB : w:\tech5\engine\gamelib\animstack\animrecorder.h
// ========================================================================

void _unwind_247571()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1288));
}

