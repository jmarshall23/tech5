
// ========================================================================
// ??0syncGroup_t@idAnimStack@@QAA@XZ
// EA  : 0x826F4E88
// RVA : 0x006F4E88
// PDB : w:\tech5\engine\gamelib\animstack\animstack.h
// ========================================================================

idAnimStack::syncGroup_t *__fastcall idAnimStack::syncGroup_t::syncGroup_t(idAnimStack::syncGroup_t *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->nodes.size = 16;
  this->nodes.list = this->nodes.staticList;
  this->nodes.granularity = 1;
  v1 = 16;
  this->nodes.num = 0;
  p_granularity = &this->nodes.granularity;
  this->nodes.memTag = 5;
  this->nodes.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(float *)p_granularity = 0.0;
    --v1;
  }
  while ( v1 != 0 );
  this->fraction = 0.0;
  this->groupNumber = 0;
  this->syncRate = 0.0;
  return this;
}

