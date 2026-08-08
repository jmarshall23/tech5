
// ========================================================================
// ?GetMaxParmVal@idParticleParm@@QBAMPBVidLookupTable@@@Z
// EA  : 0x827DE080
// RVA : 0x007DE080
// PDB : w:\tech5\engine\models\particles\jobs\particleparm.h
// ========================================================================

float __fastcall idParticleParm::GetMaxParmVal(idParticleParm *this, const idLookupTable *tables)
{
  double v4; // fp1
  int v5; // r11
  double v6; // fp0
  double v7; // fp13
  int table2Idx; // r11
  int v9; // r11
  double v10; // fp0
  double v11; // fp13
  int v12; // r11
  int tableIdx; // r11
  double v14; // fp0
  double max; // fp13

  if ( (unsigned int)(this->calcType - 1) > 6 )
  {
    v4 = 0.0;
  }
  else
  {
    switch ( this->calcType )
    {
      case PARTICLE_CALC_CURVE_GENERIC:
        tableIdx = this->tableIdx;
        v14 = 0.0;
        if ( tableIdx >= 0 && tables != nullptr )
          max = tables[tableIdx]._max;
        else
          max = 0.0;
        if ( tableIdx >= 0 && tables != nullptr )
          v14 = tables[tableIdx]._max;
        v4 = (float)((float)((float)((float)(this->variance * (float)v14) + (float)max) * this->val0) + this->val1);
        break;
      case PARTICLE_CALC_GENERIC:
        _FP12 = (float)(this->val1 - this->val0);
        _FP10 = _FP12;
        __asm
        {
          fsel      f9, f12, f13, f0
          fsel      f8, f10, f13, f0
        }
        v4 = (float)((float)(this->variance * (float)_FP9) + (float)_FP8);
        break;
      case PARTICLE_CALC_CURVE_MOD_CURVE:
        v5 = this->tableIdx;
        v6 = 0.0;
        if ( v5 >= 0 && tables != nullptr )
          v7 = tables[v5]._max;
        else
          v7 = 0.0;
        table2Idx = this->table2Idx;
        if ( table2Idx >= 0 && tables != nullptr )
          v6 = tables[table2Idx]._max;
        v4 = (float)((float)v6 * (float)v7);
        break;
      case PARTICLE_CALC_CURVE_ADD_CURVE:
        v9 = this->tableIdx;
        v10 = 0.0;
        if ( v9 >= 0 && tables != nullptr )
          v11 = tables[v9]._max;
        else
          v11 = 0.0;
        v12 = this->table2Idx;
        if ( v12 >= 0 && tables != nullptr )
          v10 = tables[v12]._max;
        v4 = (float)((float)v10 + (float)v11);
        break;
      case PARTICLE_CALC_PARAMETRIC_EVAL:
        v4 = (float)((float)(this->variance + (float)1.0) * this->val1);
        break;
      case PARTICLE_CALC_PARAMETRIC_INTEGRATE:
        v4 = (float)((float)((float)((float)((float)(this->val0 + this->val1) * this->variance) + this->val0)
                           + this->val1)
                   * (float)0.5);
        break;
      default:
        _FP10 = (float)(this->val1 - this->val0);
        __asm { fsel      f7, f10, f11, f12 }
        v4 = (float)((float)((float)((float)_FP7 * (float)(this->variance + (float)1.0)) * (float)2.0) * (float)0.5);
        break;
    }
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?EvalGeneric@idParticleParm@@ABAMMMAAVidRandom2@@@Z
// EA  : 0x827E4B68
// RVA : 0x007E4B68
// PDB : w:\tech5\engine\models\particles\jobs\particleparm.h
// ========================================================================

float __fastcall idParticleParm::EvalGeneric(
        idParticleParm *this,
        double min,
        double max,
        idRandom2 *rnd,
        int a5,
        unsigned int *a6)
{
  __int64 v6; // r8
  __int64 v7; // r5
  unsigned int v8; // r9
  double v9; // fp2
  double v10; // fp1

  HIDWORD(v6) = 1664525 * *a6;
  HIDWORD(v7) = &unk_82200000;
  *a6 = HIDWORD(v6) + 1013904223;
  v8 = 1664525 * (HIDWORD(v6) + 1013904223) + 1013904223;
  LODWORD(v6) = ((unsigned int)(HIDWORD(v6) + 1013904223) >> 10) & 0x7FFF;
  LODWORD(v7) = (v8 >> 10) & 0x7FFF;
  *a6 = v8;
  v9 = (float)((float)((float)((float)v6 * (float)((float)max - (float)min)) * (float)0.000030518509) + (float)min);
  v10 = (float)((float)((float)((float)((float)v7 * (float)0.000061037019) - (float)1.0)
                      * (float)(this->variance * (float)v9))
              + (float)v9);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?IntegrateMinMax@idParticleParm@@ABAMMMAAVidRandom2@@M@Z
// EA  : 0x827E4BF8
// RVA : 0x007E4BF8
// PDB : w:\tech5\engine\models\particles\jobs\particleparm.h
// ========================================================================

float __fastcall idParticleParm::IntegrateMinMax(
        idParticleParm *this,
        double min,
        double max,
        idRandom2 *rnd,
        double frac,
        int a6,
        __int64 a7)
{
  unsigned int v7; // r5
  unsigned int v8; // r5
  __int64 v9; // r11
  double v10; // fp1
  double v11; // fp1

  v7 = 1664525 * *(_DWORD *)HIDWORD(a7) + 1013904223;
  LODWORD(a7) = (v7 >> 10) & 0x7FFF;
  *(_DWORD *)HIDWORD(a7) = v7;
  v8 = 1664525 * v7 + 1013904223;
  HIDWORD(v9) = byte_821B0000;
  *(_DWORD *)HIDWORD(a7) = v8;
  LODWORD(v9) = (v8 >> 10) & 0x7FFF;
  v10 = (float)((float)((float)frac * (float)0.0)
              + (float)((float)((float)((float)a7 * (float)((float)max - (float)min)) * (float)0.000030518509)
                      + (float)min));
  v11 = (float)((float)((float)((float)((float)v9 * (float)0.000061037019) - (float)1.0)
                      * (float)(this->variance * (float)((float)v10 * (float)frac)))
              + (float)((float)v10 * (float)frac));
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?EvalTableWithVariance@idParticleParm@@ABAMPBVidLookupTable@@HMAAVidRandom2@@@Z
// EA  : 0x827E4C98
// RVA : 0x007E4C98
// PDB : w:\tech5\engine\models\particles\jobs\particleparm.h
// ========================================================================

float __fastcall idParticleParm::EvalTableWithVariance(
        idParticleParm *this,
        const idLookupTable *tables,
        const int idx,
        double frac,
        idRandom2 *rnd,
        unsigned int *a6)
{
  double v8; // fp1
  unsigned int v9; // r6
  __int64 v10; // r3
  double v11; // fp1

  if ( idx >= 0 && tables != nullptr )
  {
    v8 = idLookupTable::TableLookup(this: (idLookupTable *)&tables[idx], time: frac, fastSearch: (bool)tables);
    v9 = 1664525 * *a6 + 1013904223;
    LODWORD(v10) = (v9 >> 10) & 0x7FFF;
    *a6 = v9;
    v11 = (float)((float)((float)((float)((float)v10 * (float)0.000061037019) - (float)1.0)
                        * (float)(this->variance * (float)v8))
                + (float)v8);
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?Compute@idParticleParm@@QBAMPBVidLookupTable@@MAAVidRandom2@@@Z
// EA  : 0x827E4E50
// RVA : 0x007E4E50
// PDB : w:\tech5\engine\models\particles\jobs\particleparm.h
// ========================================================================

float __fastcall idParticleParm::Compute(
        idParticleParm *this,
        idRandom2 *tables,
        double frac,
        idRandom2 *rand,
        idRandom2 *a5,
        __int64 a6)
{
  double val1; // fp30
  double v10; // fp29
  double v11; // fp1
  int tableIdx; // r11
  double v13; // fp29
  int table2Idx; // r11
  int v15; // r11
  double v16; // fp29
  int v17; // r11
  __int64 v18; // r11
  double v19; // fp9
  unsigned int v20; // r4
  double val0; // fp11
  __int64 v22; // r10
  double v23; // fp8
  unsigned int v24; // r4

  if ( (unsigned int)(this->calcType - 1) > 6 )
  {
    v11 = 0.0;
  }
  else
  {
    switch ( this->calcType )
    {
      case PARTICLE_CALC_GENERIC:
        v11 = idParticleParm::EvalGeneric(
                this,
                min: this->val0,
                max: this->val1,
                rnd: tables,
                a5: (int)rand,
                a6: &a5->seed);
        break;
      case PARTICLE_CALC_CURVE_MOD_CURVE:
        tableIdx = this->tableIdx;
        if ( tableIdx >= 0 && tables != nullptr )
          v13 = idLookupTable::TableLookup(
                  this: (idLookupTable *)&tables[136 * tableIdx],
                  time: frac,
                  fastSearch: (bool)tables);
        else
          v13 = 0.0;
        table2Idx = this->table2Idx;
        if ( table2Idx >= 0 && tables != nullptr )
          v11 = (float)((float)v13
                      * idLookupTable::TableLookup(
                          this: (idLookupTable *)&tables[136 * table2Idx],
                          time: frac,
                          fastSearch: (bool)tables));
        else
          v11 = (float)((float)v13 * (float)0.0);
        break;
      case PARTICLE_CALC_CURVE_ADD_CURVE:
        v15 = this->tableIdx;
        if ( v15 >= 0 && tables != nullptr )
          v16 = idLookupTable::TableLookup(
                  this: (idLookupTable *)&tables[136 * v15],
                  time: frac,
                  fastSearch: (bool)tables);
        else
          v16 = 0.0;
        v17 = this->table2Idx;
        if ( v17 >= 0 && tables != nullptr )
          v11 = (float)(idLookupTable::TableLookup(
                          this: (idLookupTable *)&tables[136 * v17],
                          time: frac,
                          fastSearch: (bool)tables)
                      + (float)v16);
        else
          v11 = (float)((float)0.0 + (float)v16);
        break;
      case PARTICLE_CALC_PARAMETRIC_EVAL:
        HIDWORD(v18) = (idRandom2)a5->seed;
        v19 = (float)((float)((float)(this->val1 - this->val0) * (float)frac) + this->val0);
        v20 = 1664525 * a5->seed + 1013904223;
        LODWORD(v18) = (v20 >> 10) & 0x7FFF;
        a5->seed = v20;
        v11 = (float)((float)((float)((float)((float)v18 * (float)0.000061037019) - (float)1.0)
                            * (float)(this->variance * (float)v19))
                    + (float)v19);
        break;
      case PARTICLE_CALC_PARAMETRIC_INTEGRATE:
        val0 = this->val0;
        HIDWORD(v22) = 0x82000000;
        v23 = (float)((float)(this->val1 - this->val0) * (float)frac);
        v24 = 1664525 * a5->seed + 1013904223;
        LODWORD(v22) = (v24 >> 10) & 0x7FFF;
        a5->seed = v24;
        v11 = (float)((float)((float)((float)((float)v22 * (float)0.000061037019) - (float)1.0)
                            * (float)(this->variance
                                    * (float)((float)((float)((float)v23 * (float)0.5) + (float)val0) * (float)frac)))
                    + (float)((float)((float)((float)v23 * (float)0.5) + (float)val0) * (float)frac));
        break;
      case PARTICLE_CALC_CURVE_GENERIC:
        val1 = this->val1;
        v10 = this->val0;
        v11 = (float)((float)(idParticleParm::EvalTableWithVariance(
                                this,
                                (const idLookupTable *)tables,
                                idx: this->tableIdx,
                                frac,
                                rnd: a5,
                                a6: &a5->seed)
                            * (float)v10)
                    + (float)val1);
        break;
      default:
        v11 = idParticleParm::IntegrateMinMax(
                this,
                min: this->val0,
                max: this->val1,
                rnd: tables,
                frac,
                a6: (int)rand,
                a7: a6);
        break;
    }
  }
  return *((float *)&v11 + 1);
}

