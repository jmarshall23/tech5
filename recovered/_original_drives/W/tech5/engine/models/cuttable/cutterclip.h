
// ========================================================================
// ?Compare@idSort_Polygons@idCutterClip@@QBAHPBUPolygon_t@2@0@Z
// EA  : 0x827B42B8
// RVA : 0x007B42B8
// PDB : w:\tech5\engine\models\cuttable\cutterclip.h
// ========================================================================

int __fastcall idCutterClip::idSort_Polygons::Compare(
        idCutterClip::idSort_Polygons *this,
        const idCutterClip::Polygon_t *a,
        const idCutterClip::Polygon_t *b)
{
  idCutterClip::PolygonPoint_t *points; // r11
  BOOL hole; // r8
  int index; // r10
  int v6; // r11
  int result; // r3

  if ( a == b )
    return 0;
  points = a->points;
  if ( points == nullptr || b->points == nullptr )
  {
    if ( ((_cntlzw((unsigned int)points) & 0x20) != 0) != ((_cntlzw((unsigned int)b->points) & 0x20) != 0) )
      return points == nullptr ? 1 : -1;
    return 0;
  }
  hole = a->hole;
  if ( a->hole )
    index = a->firstLeft->index;
  else
    index = a->index;
  if ( b->hole )
    v6 = b->firstLeft->index;
  else
    v6 = b->index;
  result = index - v6;
  if ( index == v6 && hole != b->hole )
    return !hole ? -1 : 1;
  return result;
}

