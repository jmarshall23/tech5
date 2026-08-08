
// ========================================================================
// ??1idDevGuiListBox@@UAA@XZ
// EA  : 0x82EAF2F8
// RVA : 0x00EAF2F8
// PDB : w:\tech5\tungsten\game\tools\devgui.h
// ========================================================================

void __fastcall idDevGuiListBox::~idDevGuiListBox(idDevGuiListBox *this)
{
  this->__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this);
}


// ========================================================================
// ?IsChildActive@idDevGuiMainPage@@UBA_NXZ
// EA  : 0x82EB2BD0
// RVA : 0x00EB2BD0
// PDB : w:\tech5\tungsten\game\tools\devgui.h
// ========================================================================

BOOL __fastcall idDevGuiMainPage::IsChildActive(idDevGuiMainPage *this)
{
  return this->childActive;
}

