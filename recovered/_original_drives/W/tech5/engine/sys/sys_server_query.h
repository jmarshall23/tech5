
// ========================================================================
// ?Clear@?$idList@UserverQueryInfo_t@idServerQuery@@$04@@QAAXXZ
// EA  : 0x829DFE20
// RVA : 0x009DFE20
// PDB : w:\tech5\engine\sys\sys_server_query.h
// ========================================================================

void __fastcall idList<idServerQuery::serverQueryInfo_t,5>::Clear(idList<idServerQuery::serverQueryInfo_t,5> *this)
{
  idServerQuery::serverQueryInfo_t *list; // r3

  if ( this->listStatic == 0 || this->listStatic == 2 )
  {
    list = this->list;
    if ( this->list != nullptr )
      idListArrayDelete<idServerQuery::serverQueryInfo_t>(ptr: (char *)list, num: this->size);
    this->list = nullptr;
    this->size = 0;
  }
  this->num = 0;
}

