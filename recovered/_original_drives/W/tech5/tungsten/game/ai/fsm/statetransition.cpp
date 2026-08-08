
// ========================================================================
// ??0idStateTransition@@QAA@H@Z
// EA  : 0x82AF80C8
// RVA : 0x00AF80C8
// PDB : w:\tech5\tungsten\game\ai\fsm\statetransition.cpp
// ========================================================================

idStateTransition *__fastcall idStateTransition::idStateTransition(idStateTransition *this, int flags)
{
  this->flags = flags;
  this->__vftable = (idStateTransition_vtbl *)&idStateTransition::`vftable';
  return this;
}


// ========================================================================
// ?Save@idStateTransition@@UBAXAAVidFile_String@@PBDABV?$idList@UtransDest_t@idStateTransition@@$04@@@Z
// EA  : 0x82AF80E0
// RVA : 0x00AF80E0
// PDB : w:\tech5\tungsten\game\ai\fsm\statetransition.cpp
// ========================================================================

void __fastcall idStateTransition::Save(
        idStateTransition *this,
        idFile_String *file,
        const char *indent,
        const idList<idStateTransition::transDest_t,5> *dests)
{
  const char *Classname; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  va *v11; // r3
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r10
  va *v15; // r3
  int v16; // [sp+8h] [-1078h]
  int v17; // [sp+8h] [-1078h]
  int v18; // [sp+Ch] [-1074h]
  int v19; // [sp+Ch] [-1074h]
  int v20; // [sp+10h] [-1070h]
  int v21; // [sp+10h] [-1070h]
  int v22; // [sp+14h] [-106Ch]
  int v23; // [sp+14h] [-106Ch]
  int v24; // [sp+18h] [-1068h]
  int v25; // [sp+18h] [-1068h]
  int v26; // [sp+1Ch] [-1064h]
  int v27; // [sp+1Ch] [-1064h]
  va v28; // [sp+50h] [-1030h] BYREF

  Classname = idClass::GetClassname(this: &this->idClass);
  v11 = va::va(
          this: &v28,
          fmt: "%stransition \"%s\" {\n",
          a3: __SPAIR64__((unsigned int)indent, (unsigned int)Classname),
          a4: v10,
          a5: v9,
          a6: v16,
          a7: v18,
          a8: v20,
          a9: v22,
          a10: v24,
          a11: v26);
  idFile_String::operator+=(this: file, str: v11->buffer);
  this->InternalSave(this, a2: file, a3: indent, a4: dests);
  LODWORD(v12) = byte_821B0000;
  HIDWORD(v13) = indent;
  v15 = va::va(
          this: &v28,
          fmt: "%s}\n",
          a3: v13,
          a4: v12,
          a5: v14,
          a6: v17,
          a7: v19,
          a8: v21,
          a9: v23,
          a10: v25,
          a11: v27);
  idFile_String::operator+=(this: file, str: v15->buffer);
}

