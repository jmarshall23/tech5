
// ========================================================================
// ?GetImageDimensions@idMaterialMap@@QBA_NAAH0@Z
// EA  : 0x82938DB0
// RVA : 0x00938DB0
// PDB : w:\tech5\engine\renderer\materialmap.cpp
// ========================================================================

int __fastcall idMaterialMap::GetImageDimensions(idMaterialMap *this, int *width, int *height)
{
  *width = this->width;
  *height = this->height;
  return 1;
}


// ========================================================================
// `dynamic initializer for 'r_writePackedMaterials''
// EA  : 0x83358210
// RVA : 0x01358210
// PDB : w:\tech5\engine\renderer\materialmap.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_writePackedMaterials__()
{
  idCVar::idCVar(
    this: &r_writePackedMaterials,
    name: "r_writePackedMaterials",
    value: "0",
    flags: 1,
    description: "debug option to write all the packed materials out to viewable tga files as they are retrieved",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_writePackedMaterials__);
}

