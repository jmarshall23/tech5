
// ========================================================================
// ?OptimizeParmBlockForUsedParms@idParmBlockOptimizer@@QAAXAAVidParmBlock@@@Z
// EA  : 0x8293D7E0
// RVA : 0x0093D7E0
// PDB : w:\tech5\engine\renderer\parmblockoptimizer.cpp
// ========================================================================

void __fastcall idParmBlockOptimizer::OptimizeParmBlockForUsedParms(
        idParmBlockOptimizer *this,
        idList<detailPaletteEntry_t,5> *parmBlock)
{
  int num; // r25
  idList<idPlane,37> *v5; // r22
  int v6; // r26
  int v7; // r28
  parmValue_t *v8; // r27
  expOp_t *v9; // r29
  int numUsedParms; // r8
  int v11; // r10
  idParmBlockOptimizer *v12; // r11
  int v13; // r10
  int parmIndexA; // r9
  idParmBlockOptimizer *v15; // r11
  int v16; // r10
  idParmBlockOptimizer *v17; // r11
  int v18; // r10
  int v19; // r9
  idParmBlockOptimizer *v20; // r11
  int v21; // r11
  idParmBlockOptimizer *v22; // r10
  int v23; // r30
  int v24; // r31
  int size; // r11
  int v26; // r11

  num = parmBlock->num;
  v5 = (idList<idPlane,37> *)&parmBlock[1];
  v6 = 0;
  v7 = num - 1;
  if ( num - 1 >= 0 )
  {
    v8 = (parmValue_t *)&parmBlock[1].list[2 * v7];
    v9 = (expOp_t *)&parmBlock->list[v7];
    do
    {
      numUsedParms = this->numUsedParms;
      v11 = 0;
      if ( numUsedParms > 0 )
      {
        v12 = this;
        do
        {
          if ( v12->usedParms[0] == v9->parmIndexDest )
            break;
          ++v11;
          v12 = (idParmBlockOptimizer *)((char *)v12 + 4);
        }
        while ( v11 < this->numUsedParms );
      }
      if ( v11 >= numUsedParms )
      {
        v23 = num - v7 - 1;
        memmove(Dst: v9, Src: &v9[1], Size: 8 * v23);
        memmove(Dst: v8, Src: &v8[1], Size: 16 * v23);
        ++v6;
      }
      else
      {
        switch ( v9->type & 0x1F )
        {
          case 0:
          case 2:
            break;
          case 1:
          case 3:
          case 4:
            v13 = 0;
            parmIndexA = v9->parmIndexA;
            if ( numUsedParms <= 0 )
              goto LABEL_28;
            v15 = this;
            while ( parmIndexA != v15->usedParms[0] )
            {
              ++v13;
              v15 = (idParmBlockOptimizer *)((char *)v15 + 4);
              if ( v13 >= this->numUsedParms )
                goto LABEL_28;
            }
            break;
          case 0x14:
            v16 = 0;
            parmIndexA = v9->parmIndexB;
            if ( numUsedParms <= 0 )
              goto LABEL_28;
            v17 = this;
            while ( parmIndexA != v17->usedParms[0] )
            {
              ++v16;
              v17 = (idParmBlockOptimizer *)((char *)v17 + 4);
              if ( v16 >= this->numUsedParms )
                goto LABEL_28;
            }
            break;
          default:
            v18 = 0;
            v19 = v9->parmIndexA;
            if ( numUsedParms <= 0 )
            {
LABEL_23:
              this->usedParms[numUsedParms] = v19;
              ++this->numUsedParms;
            }
            else
            {
              v20 = this;
              while ( v19 != v20->usedParms[0] )
              {
                ++v18;
                v20 = (idParmBlockOptimizer *)((char *)v20 + 4);
                if ( v18 >= this->numUsedParms )
                  goto LABEL_23;
              }
            }
            v21 = 0;
            numUsedParms = this->numUsedParms;
            parmIndexA = v9->parmIndexB;
            if ( numUsedParms <= 0 )
            {
LABEL_28:
              this->usedParms[numUsedParms] = parmIndexA;
              ++this->numUsedParms;
            }
            else
            {
              v22 = this;
              while ( parmIndexA != v22->usedParms[0] )
              {
                ++v21;
                v22 = (idParmBlockOptimizer *)((char *)v22 + 4);
                if ( v21 >= this->numUsedParms )
                  goto LABEL_28;
              }
            }
            break;
        }
        ++idParmBlockOptimizer::c_retainedOps;
      }
      --v7;
      --v9;
      --v8;
    }
    while ( v7 >= 0 );
  }
  v24 = num - v6;
  idParmBlockOptimizer::c_removedOps += v6;
  if ( num - v6 <= parmBlock->size || idList<detailPaletteEntry_t,5>::Resize(this: parmBlock, newsize: num - v6) )
  {
    size = parmBlock->size;
    if ( v24 < size )
      size = num - v6;
    parmBlock->num = size;
  }
  if ( v24 <= v5->size || idList<idPlayerCoverScore_t,5>::Resize(this: v5, newsize: num - v6) )
  {
    v26 = v5->size;
    if ( v24 < v26 )
      v26 = num - v6;
    v5->num = v26;
  }
}

