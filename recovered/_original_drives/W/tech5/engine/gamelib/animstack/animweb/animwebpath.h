
// ========================================================================
// ?Invert@idAnimWebRoute@@QAAXXZ
// EA  : 0x826D0CF8
// RVA : 0x006D0CF8
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebpath.h
// ========================================================================

void __fastcall idAnimWebRoute::Invert(idAnimWebRoute *this)
{
  int v1; // r11
  idAnimWebRoute *v2; // r10
  int v3; // ctr
  __int16 value; // r8
  int v5; // r9

  v1 = 0;
  if ( this->num / 2 > 0 )
  {
    v2 = (idAnimWebRoute *)((char *)this - 2);
    v3 = this->num / 2;
    do
    {
      value = v2->path[1].value;
      v2 = (idAnimWebRoute *)((char *)v2 + 2);
      v2->path[0].value = this->path[this->num - v1 - 1].value;
      v5 = this->num - v1++ - 1;
      this->path[v5].value = value;
      --v3;
    }
    while ( v3 != 0 );
  }
}


// ========================================================================
// ?AppendPath@idAnimWebRoute@@QAAXABV1@@Z
// EA  : 0x826D1348
// RVA : 0x006D1348
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebpath.h
// ========================================================================

void __fastcall idAnimWebRoute::AppendPath(idAnimWebRoute *this, const idAnimWebRoute *other)
{
  int num; // r10
  int v3; // r11
  const idAnimWebRoute *v4; // r10
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v5; // r10
  int v6; // r8

  num = this->num;
  v3 = 0;
  if ( num > 0 && this->path[num - 1].value == other->path[0].value )
  {
    v4 = other;
    do
    {
      v4 = (const idAnimWebRoute *)((char *)v4 + 2);
      ++v3;
    }
    while ( this->path[this->num - 1].value == v4->path[0].value );
  }
  if ( v3 < other->num )
  {
    v5 = &other->path[v3 - 1];
    do
    {
      v6 = this->num;
      if ( v6 >= 32 )
        break;
      ++v5;
      ++v3;
      this->path[v6] = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>)v5->value;
      ++this->num;
    }
    while ( v3 < other->num );
  }
  this->cost += other->cost;
}

