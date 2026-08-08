
// ========================================================================
// ?Get_idLeakyIntegrator_0_1__wasTriggered@@YAHPAX@Z
// EA  : 0x8255DE10
// RVA : 0x0055DE10
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_4.cpp
// ========================================================================

int __fastcall Get_idLeakyIntegrator_0_1__wasTriggered(unsigned __int8 *ptr)
{
  return ptr[12] >> 7;
}


// ========================================================================
// ?Set_idLeakyIntegrator_0_1__wasTriggered@@YAXPAXH@Z
// EA  : 0x8255DE20
// RVA : 0x0055DE20
// PDB : w:\tech5\tungsten\typeinfo\gametypeinfo_classes_4.cpp
// ========================================================================

void __fastcall Set_idLeakyIntegrator_0_1__wasTriggered(_BYTE *ptr, int value)
{
  ptr[12] = ((value != 0) << 7) | ptr[12] & 0x7F;
}

