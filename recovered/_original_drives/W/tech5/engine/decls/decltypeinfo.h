
// ========================================================================
// ?GetDeclInfo@idDeclTypeInfo@@UBAPAVidDeclInfo@@XZ
// EA  : 0x8262AD48
// RVA : 0x0062AD48
// PDB : w:\tech5\engine\decls\decltypeinfo.h
// ========================================================================

idDeclInfoTemplate<idDeclTypeInfo> *__fastcall idDeclTypeInfo::GetDeclInfo(idDeclTypeInfo *this)
{
  return &idDeclTypeInfo::resourceList;
}


// ========================================================================
// ?GetInheritName@idDeclTypeInfo@@QBAPBDXZ
// EA  : 0x82D78D88
// RVA : 0x00D78D88
// PDB : w:\tech5\engine\decls\decltypeinfo.h
// ========================================================================

char *__fastcall idDeclTypeInfo::GetInheritName(idDeclTypeInfo *this)
{
  idDeclTypeInfo *parent; // r11

  parent = this->parent;
  if ( parent != nullptr )
    return (char *)parent->name.str;
  else
    return &byte_8200D768;
}

