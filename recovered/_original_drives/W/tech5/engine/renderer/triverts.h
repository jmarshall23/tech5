
// ========================================================================
// ?VertexSizeFromMask@@YAHI@Z
// EA  : 0x827FBE18
// RVA : 0x007FBE18
// PDB : w:\tech5\engine\renderer\triverts.h
// ========================================================================

unsigned int __fastcall VertexSizeFromMask(unsigned int vertexMask)
{
  return ((vertexMask & 0x1000) == 0 ? 0 : 0xC)
       + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
       + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
       + ((vertexMask & 1) == 0 ? 0 : 0xC)
       + ((vertexMask >> 9) & 4)
       + ((vertexMask >> 2) & 4)
       + ((vertexMask >> 1) & 4)
       + ((4 * vertexMask) & 8)
       + (vertexMask & 4);
}

