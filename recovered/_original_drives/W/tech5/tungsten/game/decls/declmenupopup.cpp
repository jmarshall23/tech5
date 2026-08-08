
// ========================================================================
// ??0idDeclMenuPopup@@QAA@XZ
// EA  : 0x82BC8628
// RVA : 0x00BC8628
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.cpp
// ========================================================================

idDeclMenuPopup *__fastcall idDeclMenuPopup::idDeclMenuPopup(idDeclMenuPopup *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclMenuPopup_vtbl *)&idDeclMenuPopup::`vftable';
  this->fileName.len = 0;
  this->fileName.allocedAndFlag = 20;
  this->fileName.data = this->fileName.baseBuffer;
  this->fileName.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?GetCreditType@idDeclCredits@@QBAHH@Z
// EA  : 0x82BC8780
// RVA : 0x00BC8780
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.cpp
// ========================================================================

idDeclCredits::creditEntry_t __fastcall idDeclCredits::GetCreditType(idDeclCredits *this, int index)
{
  if ( index >= this->creditList.num )
    return CREDIT_SPACER;
  else
    return this->creditList.list[index].entryType;
}


// ========================================================================
// ?GetScriptName@idDeclMenuPopup@@QBAPBDXZ
// EA  : 0x82BC87B0
// RVA : 0x00BC87B0
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.cpp
// ========================================================================

char *__fastcall idDeclMenuPopup::GetScriptName(idDeclMenuPopup *this)
{
  char *data; // r31
  idStr v3; // [sp+50h] [-30h] BYREF

  idStr::idStr(this: &v3, text: this->name.str);
  idStr::ToUpper(this: &v3);
  data = v3.data;
  idStr::FreeData(this: &v3);
  return data;
}


// ========================================================================
// ?GetCreditEntry@idDeclCredits@@QBA?AVidStr@@HH@Z
// EA  : 0x82BC8800
// RVA : 0x00BC8800
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.cpp
// ========================================================================

idDeclCredits *__fastcall idDeclCredits::GetCreditEntry(idDeclCredits *this, idStr *result, int index, int entry)
{
  int v5; // r11
  const char *LocalizedString; // r4

  if ( index >= (int)result[2].data )
  {
    LocalizedString = &byte_8200D768;
    goto LABEL_8;
  }
  v5 = 72 * index + result[2].len;
  if ( *(int *)(v5 + 4) >= 0 )
  {
    LocalizedString = idStrId::GetLocalizedString(this: (idStrId *)(v5 + 4));
LABEL_8:
    idStr::idStr((idStr *)this, text: LocalizedString);
    return this;
  }
  if ( entry != 0 )
    idStr::idStr((idStr *)this, text: (const idStr *)(v5 + 40));
  else
    idStr::idStr((idStr *)this, text: (const idStr *)(v5 + 8));
  return this;
}


// ========================================================================
// ?LoadAllDecls@idDeclMenuPopup@@SAXXZ
// EA  : 0x82BC88A0
// RVA : 0x00BC88A0
// PDB : w:\tech5\tungsten\game\decls\declmenupopup.cpp
// ========================================================================

static void __fastcall idDeclMenuPopup::LoadAllDecls()
{
  int v0; // r31
  int num; // r29
  const char *str; // r4

  if ( idDeclMenuPopup::resourceList.declSources.num > 0 )
  {
    v0 = 0;
    num = idDeclMenuPopup::resourceList.declSources.num;
    do
    {
      str = idDeclMenuPopup::resourceList.declSources.list[v0]->name.str;
      if ( str != nullptr )
        idDeclInfo::FindWithInheritance(this: &idDeclMenuPopup::resourceList, name: str, makeDefault: false);
      --num;
      ++v0;
    }
    while ( num != 0 );
  }
}

