
// ========================================================================
// ?GetBaseModel@idDeclAnimWeb@@QBAPBVidDeclMD6@@XZ
// EA  : 0x825FEE70
// RVA : 0x005FEE70
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.h
// ========================================================================

const idDeclMD6 *__fastcall idDeclAnimWeb::GetBaseModel(idDeclAnimWeb *this)
{
  if ( this->models.num <= 0 )
    return nullptr;
  else
    return *this->models.list;
}


// ========================================================================
// ?GetDeclInfo@idDeclAnimWeb@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82603090
// RVA : 0x00603090
// PDB : w:\tech5\engine\decls\animwebs\declanimweb.h
// ========================================================================

idDeclInfoTemplate<idDeclAnimWeb> *__fastcall idDeclAnimWeb::GetDeclInfo(idDeclAnimWeb *this)
{
  return &idDeclAnimWeb::resourceList;
}

