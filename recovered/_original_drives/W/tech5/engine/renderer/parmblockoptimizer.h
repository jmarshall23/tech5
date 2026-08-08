
// ========================================================================
// ?AddRenderProg@idParmBlockOptimizer@@QAAXPBVidDeclRenderProg@@@Z
// EA  : 0x828A9C10
// RVA : 0x008A9C10
// PDB : w:\tech5\engine\renderer\parmblockoptimizer.h
// ========================================================================

void __fastcall idParmBlockOptimizer::AddRenderProg(idParmBlockOptimizer *this, const idDeclRenderProg *prog)
{
  int v2; // r6
  __int16 *vertexParms; // r7
  int v4; // r11
  int numUsedParms; // r8
  int v6; // r9
  idParmBlockOptimizer *v7; // r10
  int v8; // r6
  __int16 *fragmentParms; // r7
  int v10; // r11
  int v11; // r8
  int v12; // r9
  idParmBlockOptimizer *v13; // r10
  __int16 *textureParms; // r7
  int i; // ctr
  int v16; // r11
  int v17; // r8
  int v18; // r9
  idParmBlockOptimizer *v19; // r10

  if ( prog != nullptr )
  {
    v2 = 0;
    if ( prog->numVertexParms > 0 )
    {
      vertexParms = prog->vertexParms;
      do
      {
        v4 = 0;
        numUsedParms = this->numUsedParms;
        v6 = *vertexParms;
        if ( numUsedParms <= 0 )
        {
LABEL_8:
          this->usedParms[numUsedParms] = v6;
          ++this->numUsedParms;
        }
        else
        {
          v7 = this;
          while ( v6 != v7->usedParms[0] )
          {
            ++v4;
            v7 = (idParmBlockOptimizer *)((char *)v7 + 4);
            if ( v4 >= this->numUsedParms )
              goto LABEL_8;
          }
        }
        ++v2;
        ++vertexParms;
      }
      while ( v2 < prog->numVertexParms );
    }
    v8 = 0;
    if ( prog->numFragmentParms > 0 )
    {
      fragmentParms = prog->fragmentParms;
      do
      {
        v10 = 0;
        v11 = this->numUsedParms;
        v12 = *fragmentParms;
        if ( v11 <= 0 )
        {
LABEL_16:
          this->usedParms[v11] = v12;
          ++this->numUsedParms;
        }
        else
        {
          v13 = this;
          while ( v12 != v13->usedParms[0] )
          {
            ++v10;
            v13 = (idParmBlockOptimizer *)((char *)v13 + 4);
            if ( v10 >= this->numUsedParms )
              goto LABEL_16;
          }
        }
        ++v8;
        ++fragmentParms;
      }
      while ( v8 < prog->numFragmentParms );
    }
    textureParms = prog->textureParms;
    for ( i = 16; i != 0; --i )
    {
      v16 = 0;
      v17 = this->numUsedParms;
      v18 = *textureParms;
      if ( v17 <= 0 )
      {
LABEL_23:
        this->usedParms[v17] = v18;
        ++this->numUsedParms;
      }
      else
      {
        v19 = this;
        while ( v18 != v19->usedParms[0] )
        {
          ++v16;
          v19 = (idParmBlockOptimizer *)((char *)v19 + 4);
          if ( v16 >= this->numUsedParms )
            goto LABEL_23;
        }
      }
      ++textureParms;
    }
  }
}

