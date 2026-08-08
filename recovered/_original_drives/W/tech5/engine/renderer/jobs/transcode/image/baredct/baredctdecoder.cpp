
// ========================================================================
// ?SetHuffmanTables@idBareDctDecoder@@QAAXPBVidBareDCTHuffmanTable@@00000@Z
// EA  : 0x828E51C0
// RVA : 0x008E51C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder.cpp
// ========================================================================

void __fastcall idBareDctDecoder::SetHuffmanTables(
        idBareDctDecoder *this,
        const idBareDCTHuffmanTable *tableYDC,
        const idBareDCTHuffmanTable *tableYAC,
        const idBareDCTHuffmanTable *tableCoCgDC,
        const idBareDCTHuffmanTable *tableCoCgAC,
        const idBareDCTHuffmanTable *tableADC,
        const idBareDCTHuffmanTable *tableAAC)
{
  this->pHuffTableYDC = tableYDC;
  this->pHuffTableYAC = tableYAC;
  this->pHuffTableCoCgDC = tableCoCgDC;
  this->pHuffTableCoCgAC = tableCoCgAC;
  this->pHuffTableADC = tableADC;
  this->pHuffTableAAC = tableAAC;
}


// ========================================================================
// ??0idBareDctDecoder@@QAA@XZ
// EA  : 0x828E51E8
// RVA : 0x008E51E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder.cpp
// ========================================================================

idBareDctDecoder *__fastcall idBareDctDecoder::idBareDctDecoder(idBareDctDecoder *this)
{
  unsigned __int64 v2; // r11

  idBareDctBase::idBareDctBase(this);
  LODWORD(v2) = 0;
  this->imageWidth = 0;
  this->imageHeight = 0;
  this->bitCnt = v2;
  this->bitBuff = v2;
  this->dcA = 0;
  this->dcCg = 0;
  this->dcCo = 0;
  this->dcY = 0;
  this->dataBytes = 0;
  this->data = nullptr;
  this->pHuffTableYDC = nullptr;
  this->pHuffTableCoCgDC = nullptr;
  this->pHuffTableADC = nullptr;
  this->pHuffTableYAC = nullptr;
  this->pHuffTableCoCgAC = nullptr;
  this->pHuffTableAAC = nullptr;
  idBareDctBase::InitQuantTable(this);
  return this;
}


// ========================================================================
// __unwind$71223
// EA  : 0x828E5274
// RVA : 0x008E5274
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredctdecoder.cpp
// ========================================================================

void _unwind_71223()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 132));
}

