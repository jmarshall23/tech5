
// ========================================================================
// ??0?$idStaticParmBlock@$0CA@@@QAA@W4threadId_t@@@Z
// EA  : 0x8256FC40
// RVA : 0x0056FC40
// PDB : w:\tech5\engine\renderer\parmblock.h
// ========================================================================

idStaticParmBlock<32> *__fastcall idStaticParmBlock<32>::idStaticParmBlock<32>(
        idStaticParmBlock<32> *this,
        threadId_t threadId)
{
  idParmBlock::idParmBlock(this, threadId);
  this->ops.granularity = 1;
  this->ops.size = 32;
  this->ops.num = 0;
  this->ops.memTag = 56;
  this->ops.list = this->staticOps;
  this->ops.listStatic = 1;
  this->constants.list = this->staticConstants;
  this->constants.size = 32;
  this->constants.num = 0;
  this->constants.granularity = 1;
  this->constants.memTag = 56;
  this->constants.listStatic = 1;
  return this;
}


// ========================================================================
// ?Clear@?$idStaticParmBlock@$0CA@@@QAAXXZ
// EA  : 0x82E87D40
// RVA : 0x00E87D40
// PDB : w:\tech5\engine\renderer\parmblock.h
// ========================================================================

void __fastcall idStaticParmBlock<32>::Clear(idStaticParmBlock<32> *this)
{
  float *p_parmIndexA; // r10
  bool *v3; // r11
  int i; // ctr

  idParmBlock::Clear(this);
  p_parmIndexA = (float *)&this->staticOps[32].parmIndexA;
  v3 = &this->usingTempOps + 2;
  for ( i = 32; i != 0; --i )
  {
    *((_WORD *)v3 + 1) = 0;
    *((_WORD *)v3 + 2) = 0;
    *((_WORD *)v3 + 3) = 0;
    v3 += 8;
    *(_WORD *)v3 = 0;
    p_parmIndexA[1] = 0.0;
    p_parmIndexA[2] = 0.0;
    p_parmIndexA[3] = 0.0;
    p_parmIndexA += 4;
    *p_parmIndexA = 0.0;
  }
}

