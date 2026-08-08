
// ========================================================================
// ?Name@ssEntity@@QBA?AVssString@@XZ
// EA  : 0x82EDE878
// RVA : 0x00EDE878
// PDB : w:\tech5\tungsten\superscript\lib\entity.h
// ========================================================================

ssEntity *__fastcall ssEntity::Name(ssEntity *this, ssString *result)
{
  const char *v3; // r30

  v3 = gameInterface->EntityName(this: gameInterface, a2: result->len);
  ssString::Init((ssString *)this);
  ssString::operator=((ssString *)this, text: v3);
  return this;
}


// ========================================================================
// ?IsValid@ssEntity@@QBA_NXZ
// EA  : 0x82EE8BA0
// RVA : 0x00EE8BA0
// PDB : w:\tech5\tungsten\superscript\lib\entity.h
// ========================================================================

int __fastcall ssEntity::IsValid(ssEntity *this)
{
  char v1; // r3
  unsigned __int8 v2; // r11

  if ( this->spawnId == 0 )
    return 0;
  v1 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface);
  v2 = 1;
  if ( v1 == 0 )
    return 0;
  return v2;
}

