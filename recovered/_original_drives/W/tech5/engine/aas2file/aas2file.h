
// ========================================================================
// ?GetResourceList@idAAS2File@@UBAPAVidResourceList@@XZ
// EA  : 0x825B3640
// RVA : 0x005B3640
// PDB : w:\tech5\engine\aas2file\aas2file.h
// ========================================================================

idTypedResourceList<idAAS2File> *__fastcall idAAS2File::GetResourceList(idAAS2File *this)
{
  return &idAAS2File::resourceList;
}


// ========================================================================
// ?FloodAddVisitedArea@idAAS2File@@ABAXH@Z
// EA  : 0x825BCD80
// RVA : 0x005BCD80
// PDB : w:\tech5\engine\aas2file\aas2file.h
// ========================================================================

void __fastcall idAAS2File::FloodAddVisitedArea(
        idAAS2File *this,
        int areaNum,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  a14 = areaNum;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->visitedAreas,
    obj: (const encounterGroupRole_t *)&a14);
  this->areas.list[areaNum].flags |= 0x8000u;
}


// ========================================================================
// ?FloodClearVisitedAreas@idAAS2File@@ABAXH@Z
// EA  : 0x825BCDE8
// RVA : 0x005BCDE8
// PDB : w:\tech5\engine\aas2file\aas2file.h
// ========================================================================

void __fastcall idAAS2File::FloodClearVisitedAreas(idAAS2File *this, int offset)
{
  int v3; // r9
  int v4; // r10
  int v5; // r11
  unsigned __int16 *p_flags; // r8
  idList<int,37> *p_visitedAreas; // r31
  int size; // r11

  v3 = offset;
  if ( offset < this->visitedAreas.num )
  {
    v4 = offset;
    do
    {
      ++v3;
      v5 = this->visitedAreas.list[v4++];
      p_flags = &this->areas.list[v5].flags;
      *p_flags &= ~0x8000u;
    }
    while ( v3 < this->visitedAreas.num );
  }
  p_visitedAreas = &this->visitedAreas;
  if ( offset <= this->visitedAreas.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->visitedAreas,
         newsize: offset) )
  {
    size = p_visitedAreas->size;
    if ( offset < size )
      size = offset;
    p_visitedAreas->num = size;
  }
}

