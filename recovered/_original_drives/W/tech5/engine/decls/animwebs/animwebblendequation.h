
// ========================================================================
// ??0animList_t@idAnimWebBlendEquation@@QAA@XZ
// EA  : 0x825F91E8
// RVA : 0x005F91E8
// PDB : w:\tech5\engine\decls\animwebs\animwebblendequation.h
// ========================================================================

idAnimWebBlendEquation::animList_t *__fastcall idAnimWebBlendEquation::animList_t::animList_t(
        idAnimWebBlendEquation::animList_t *this)
{
  this->filterList.list = this->filterList.staticList;
  this->filterList.granularity = 1;
  this->filterList.num = 0;
  this->filterList.memTag = 5;
  this->filterList.size = 10;
  this->filterList.listStatic = 1;
  this->animList.size = 256;
  this->animList.num = 0;
  this->animList.granularity = 1;
  this->animList.list = this->animList.staticList;
  this->animList.memTag = 5;
  this->animList.listStatic = 1;
  this->tagList.size = 256;
  this->tagList.num = 0;
  this->tagList.granularity = 1;
  this->tagList.list = this->tagList.staticList;
  this->tagList.memTag = 5;
  this->tagList.listStatic = 1;
  this->animPropIndex = -1;
  return this;
}

