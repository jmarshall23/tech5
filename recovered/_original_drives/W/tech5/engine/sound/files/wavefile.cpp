
// ========================================================================
// ?SeekToChunk@idWaveFile@@QAAII@Z
// EA  : 0x82987E90
// RVA : 0x00987E90
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

unsigned int __fastcall idWaveFile::SeekToChunk(idWaveFile *this, unsigned int id)
{
  int num; // r8
  int v4; // r11
  int i; // r10
  int v7; // r31

  num = this->chunks.num;
  v4 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->chunks.list[i].id != id; ++i )
  {
    if ( ++v4 >= num )
      return 0;
  }
  v7 = v4;
  ((void (*)(void))this->file->Seek)();
  return this->chunks.list[v7].size;
}


// ========================================================================
// ?GetChunkOffset@idWaveFile@@QAAII@Z
// EA  : 0x82987F38
// RVA : 0x00987F38
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

unsigned int __fastcall idWaveFile::GetChunkOffset(idWaveFile *this, unsigned int id)
{
  int num; // r8
  int v3; // r10
  idWaveFile::chunk_t *list; // r9
  int i; // r11

  num = this->chunks.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  list = this->chunks.list;
  for ( i = 0; list[i].id != id; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  return list[v3].offset;
}


// ========================================================================
// ?ReadLoopData@idWaveFile@@QAA_NAAH0@Z
// EA  : 0x82987F90
// RVA : 0x00987F90
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

int __fastcall idWaveFile::ReadLoopData(idWaveFile *this, int *start, int *end)
{
  char v6; // r7
  char v7; // r6
  char v8; // r9
  char v9; // r8
  char v10; // r7
  char v11; // r6
  const char *v12; // r3
  int v14; // r10
  _BYTE v15[4]; // [sp+50h] [-70h] BYREF
  int v16; // [sp+54h] [-6Ch]
  int v17; // [sp+58h] [-68h]
  int v18; // [sp+5Ch] [-64h]
  _BYTE v19[28]; // [sp+70h] [-50h] BYREF
  int v20; // [sp+8Ch] [-34h]

  if ( idWaveFile::SeekToChunk(this, id: 0x736D706Cu) < 0x24 )
    return 0;
  this->file->Read(this: this->file, a2: v19, a3: 36u);
  v6 = v20;
  v7 = BYTE2(v20);
  LOBYTE(v20) = HIBYTE(v20);
  BYTE2(v20) = BYTE1(v20);
  HIBYTE(v20) = v6;
  BYTE1(v20) = v7;
  if ( v20 == 0 )
    return 0;
  this->file->Read(this: this->file, a2: v15, a3: 24u);
  v8 = HIBYTE(v17);
  v9 = BYTE1(v17);
  v10 = HIBYTE(v18);
  v11 = BYTE1(v18);
  BYTE1(v17) = BYTE2(v17);
  HIBYTE(v17) = v17;
  BYTE1(v18) = BYTE2(v18);
  HIBYTE(v18) = v18;
  LOBYTE(v17) = v8;
  BYTE2(v17) = v9;
  LOBYTE(v18) = v10;
  BYTE2(v18) = v11;
  if ( v16 != 0 )
  {
    v12 = this->file->GetName(this: this->file);
    idLib::Warning(fmt: "Invalid loop type in %s", v12);
    return 0;
  }
  v14 = v18;
  *start = v17;
  *end = v14;
  return 1;
}


// ========================================================================
// ?ReadWaveFormat@idWaveFile@@QAAPBDAAUwaveFmt_t@1@@Z
// EA  : 0x829880B8
// RVA : 0x009880B8
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

const char *__fastcall idWaveFile::ReadWaveFormat(idWaveFile *this, idWaveFile::waveFmt_t *format)
{
  unsigned int v4; // r3
  char formatTag; // r8
  char numChannels_high; // r7
  char samplesPerSec_high; // r3
  char samplesPerSec; // r11
  char v10; // r4
  char avgBytesPerSec_high; // r8
  char avgBytesPerSec; // r7
  char v13; // r9
  char blockSize_high; // r6
  char bitsPerSample_high; // r4
  int v16; // r11
  char extraSize; // r8
  char validBitsPerSample_high; // r7
  int v19; // r9
  char numCoef_high; // r5
  char *v21; // r11
  char v22; // r7
  char v23; // r5
  char v24; // r8
  char validBitsPerSample; // r8
  char v26; // r5
  char v27; // r4
  char channelMask; // r7
  char v29; // r10
  char samplesEncoded; // r9
  char v31; // r11
  char bytesPerBlock; // r6
  char v33; // r5
  char v34; // r7
  unsigned __int8 v35; // r10
  unsigned __int8 v36; // r3
  unsigned __int8 v37; // r11
  unsigned __int8 v38; // r7
  unsigned __int8 v39; // r6
  unsigned __int8 v40; // r8
  char v41; // r3
  char v42; // r11
  char loopBegin; // r4
  char v44; // r9
  char v45; // r8
  char loopLength_high; // r7
  char blockCount_high; // r5
  char extraSize_high; // r9
  idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t *p_subFormat; // r11
  int *v50; // r7
  char v51; // r5
  char v52; // r4
  char v53; // r9
  char v54; // r10
  char v55; // r4
  char v56; // r3
  char samplesEncoded_high; // r5
  char bytesPerBlock_high; // r10
  char v59; // r5
  char playBegin_high; // r4
  int data1_high; // r9
  int v62; // r10
  int v63; // [sp+50h] [-30h] BYREF
  __int16 v64; // [sp+54h] [-2Ch]
  __int16 v65; // [sp+56h] [-2Ah]
  __int16 v66; // [sp+58h] [-28h]
  char v67; // [sp+5Ah] [-26h]
  char v68; // [sp+5Bh] [-25h]
  char v69; // [sp+5Ch] [-24h]
  char v70; // [sp+5Dh] [-23h]
  char v71; // [sp+5Eh] [-22h]
  char v72; // [sp+5Fh] [-21h]
  int v73; // [sp+60h] [-20h] BYREF

  memset(Dst: format, Val: 0, Size: sizeof(idWaveFile::waveFmt_t));
  v4 = idWaveFile::SeekToChunk(this, id: 0x666D7420u);
  if ( v4 == 0 )
    return "No format chunk";
  if ( v4 < 0x10 )
    return "Format chunk too small";
  this->file->Read(this: this->file, a2: format, a3: 16u);
  formatTag = format->basic.formatTag;
  LOBYTE(format->basic.formatTag) = HIBYTE(format->basic.formatTag);
  HIBYTE(format->basic.formatTag) = formatTag;
  numChannels_high = HIBYTE(format->basic.numChannels);
  HIBYTE(format->basic.numChannels) = format->basic.numChannels;
  LOBYTE(format->basic.numChannels) = numChannels_high;
  samplesPerSec_high = HIBYTE(format->basic.samplesPerSec);
  samplesPerSec = format->basic.samplesPerSec;
  v10 = BYTE1(format->basic.samplesPerSec);
  BYTE1(format->basic.samplesPerSec) = BYTE2(format->basic.samplesPerSec);
  HIBYTE(format->basic.samplesPerSec) = samplesPerSec;
  LOBYTE(format->basic.samplesPerSec) = samplesPerSec_high;
  BYTE2(format->basic.samplesPerSec) = v10;
  avgBytesPerSec_high = HIBYTE(format->basic.avgBytesPerSec);
  avgBytesPerSec = format->basic.avgBytesPerSec;
  v13 = BYTE1(format->basic.avgBytesPerSec);
  BYTE1(format->basic.avgBytesPerSec) = BYTE2(format->basic.avgBytesPerSec);
  HIBYTE(format->basic.avgBytesPerSec) = avgBytesPerSec;
  LOBYTE(format->basic.avgBytesPerSec) = avgBytesPerSec_high;
  BYTE2(format->basic.avgBytesPerSec) = v13;
  blockSize_high = HIBYTE(format->basic.blockSize);
  HIBYTE(format->basic.blockSize) = format->basic.blockSize;
  LOBYTE(format->basic.blockSize) = blockSize_high;
  bitsPerSample_high = HIBYTE(format->basic.bitsPerSample);
  HIBYTE(format->basic.bitsPerSample) = format->basic.bitsPerSample;
  LOBYTE(format->basic.bitsPerSample) = bitsPerSample_high;
  v16 = format->basic.formatTag;
  if ( v16 == 1 )
    return nullptr;
  if ( v16 == 2 )
  {
    this->file->Read(this: this->file, a2: &format->extraSize, a3: 2u);
    extraSize = format->extraSize;
    LOBYTE(format->extraSize) = HIBYTE(format->extraSize);
    HIBYTE(format->extraSize) = extraSize;
    if ( format->extraSize != 32 )
      return "Incorrect number of coefficients in ADPCM file";
    this->file->Read(this: this->file, a2: &format->extra, a3: 32u);
    validBitsPerSample_high = HIBYTE(format->extra.extensible.validBitsPerSample);
    v19 = 0;
    HIBYTE(format->extra.extensible.validBitsPerSample) = format->extra.extensible.validBitsPerSample;
    LOBYTE(format->extra.extensible.validBitsPerSample) = validBitsPerSample_high;
    numCoef_high = HIBYTE(format->extra.adpcm.numCoef);
    HIBYTE(format->extra.adpcm.numCoef) = BYTE1(format->extra.xma2.channelMask);
    BYTE1(format->extra.xma2.channelMask) = numCoef_high;
    if ( format->extra.adpcm.numCoef != 0 )
    {
      v21 = (char *)&format->extra.xma2.channelMask + 1;
      do
      {
        ++v19;
        v22 = v21[1];
        v21[1] = v21[2];
        v21[2] = v22;
        v23 = v21[3];
        v21[3] = v21[4];
        v21 += 4;
        *v21 = v23;
      }
      while ( v19 < format->extra.adpcm.numCoef );
    }
    return nullptr;
  }
  if ( v16 != 358 )
  {
    if ( v16 != 0xFFFF )
      return "Unknown wave format tag";
    this->file->Read(this: this->file, a2: &format->extraSize, a3: 2u);
    extraSize_high = HIBYTE(format->extraSize);
    HIBYTE(format->extraSize) = format->extraSize;
    LOBYTE(format->extraSize) = extraSize_high;
    if ( format->extraSize != 22 )
      return "Incorrect chunk size in extensible wave file";
    this->file->Read(this: this->file, a2: &format->extra, a3: 22u);
    v65 = 16;
    v68 = -86;
    v63 = 1;
    v70 = 56;
    v72 = 113;
    p_subFormat = &format->extra.extensible.subFormat;
    v71 = -101;
    v50 = &v63;
    v64 = 0;
    v67 = 0;
    v69 = 0;
    v66 = 0x8000;
    v51 = HIBYTE(format->extra.extensible.validBitsPerSample);
    HIBYTE(format->extra.extensible.validBitsPerSample) = format->extra.extensible.validBitsPerSample;
    LOBYTE(format->extra.extensible.validBitsPerSample) = v51;
    v52 = BYTE1(format->extra.xma2.channelMask);
    v53 = BYTE2(format->extra.xma2.channelMask);
    v54 = HIBYTE(format->extra.adpcm.numCoef);
    HIBYTE(format->extra.adpcm.numCoef) = format->extra.xma2.channelMask;
    BYTE1(format->extra.xma2.channelMask) = v53;
    LOBYTE(format->extra.xma2.channelMask) = v54;
    BYTE2(format->extra.xma2.channelMask) = v52;
    v55 = BYTE1(format->extra.xma2.samplesEncoded);
    v56 = BYTE2(format->extra.xma2.samplesEncoded);
    samplesEncoded_high = HIBYTE(format->extra.xma2.samplesEncoded);
    HIBYTE(format->extra.xma2.samplesEncoded) = format->extra.xma2.samplesEncoded;
    BYTE1(format->extra.xma2.samplesEncoded) = v56;
    BYTE2(format->extra.xma2.samplesEncoded) = v55;
    LOBYTE(format->extra.xma2.samplesEncoded) = samplesEncoded_high;
    bytesPerBlock_high = HIBYTE(format->extra.xma2.bytesPerBlock);
    HIBYTE(format->extra.xma2.bytesPerBlock) = BYTE1(format->extra.xma2.bytesPerBlock);
    BYTE1(format->extra.xma2.bytesPerBlock) = bytesPerBlock_high;
    v59 = BYTE2(format->extra.xma2.bytesPerBlock);
    BYTE2(format->extra.xma2.bytesPerBlock) = format->extra.xma2.bytesPerBlock;
    LOBYTE(format->extra.xma2.bytesPerBlock) = v59;
    playBegin_high = HIBYTE(format->extra.xma2.playBegin);
    HIBYTE(format->extra.xma2.playBegin) = BYTE1(format->extra.xma2.playBegin);
    BYTE1(format->extra.xma2.playBegin) = playBegin_high;
    do
    {
      data1_high = HIBYTE(p_subFormat->data1);
      v62 = *(unsigned __int8 *)v50 - data1_high;
      if ( *(unsigned __int8 *)v50 != data1_high )
        break;
      v50 = (int *)((char *)v50 + 1);
      p_subFormat = (idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t *)((char *)p_subFormat + 1);
    }
    while ( v50 != &v73 );
    if ( v62 != 0 )
      return "Unsupported Extensible format";
    return nullptr;
  }
  this->file->Read(this: this->file, a2: &format->extraSize, a3: 2u);
  v24 = format->extraSize;
  LOBYTE(format->extraSize) = HIBYTE(format->extraSize);
  HIBYTE(format->extraSize) = v24;
  if ( format->extraSize != 34 )
    return "Incorrect chunk size in XMA2 file";
  this->file->Read(this: this->file, a2: &format->extra, a3: 34u);
  validBitsPerSample = format->extra.extensible.validBitsPerSample;
  LOBYTE(format->extra.extensible.validBitsPerSample) = HIBYTE(format->extra.extensible.validBitsPerSample);
  HIBYTE(format->extra.extensible.validBitsPerSample) = validBitsPerSample;
  v26 = BYTE1(format->extra.xma2.channelMask);
  v27 = BYTE2(format->extra.xma2.channelMask);
  channelMask = format->extra.xma2.channelMask;
  LOBYTE(format->extra.xma2.channelMask) = HIBYTE(format->extra.adpcm.numCoef);
  BYTE1(format->extra.xma2.channelMask) = v27;
  HIBYTE(format->extra.adpcm.numCoef) = channelMask;
  BYTE2(format->extra.xma2.channelMask) = v26;
  v29 = HIBYTE(format->extra.xma2.samplesEncoded);
  samplesEncoded = format->extra.xma2.samplesEncoded;
  v31 = BYTE1(format->extra.xma2.samplesEncoded);
  BYTE1(format->extra.xma2.samplesEncoded) = BYTE2(format->extra.xma2.samplesEncoded);
  HIBYTE(format->extra.xma2.samplesEncoded) = samplesEncoded;
  LOBYTE(format->extra.xma2.samplesEncoded) = v29;
  BYTE2(format->extra.xma2.samplesEncoded) = v31;
  bytesPerBlock = format->extra.xma2.bytesPerBlock;
  v33 = HIBYTE(format->extra.xma2.bytesPerBlock);
  v34 = BYTE1(format->extra.xma2.bytesPerBlock);
  BYTE1(format->extra.xma2.bytesPerBlock) = BYTE2(format->extra.xma2.bytesPerBlock);
  HIBYTE(format->extra.xma2.bytesPerBlock) = bytesPerBlock;
  BYTE2(format->extra.xma2.bytesPerBlock) = v34;
  LOBYTE(format->extra.xma2.bytesPerBlock) = v33;
  v35 = format->extra.extensible.subFormat.data5[0];
  v36 = BYTE1(format->extra.xma2.playBegin);
  v37 = HIBYTE(format->extra.xma2.playBegin);
  HIBYTE(format->extra.xma2.playBegin) = format->extra.extensible.subFormat.data5[1];
  format->extra.extensible.subFormat.data5[0] = v36;
  format->extra.extensible.subFormat.data5[1] = v37;
  BYTE1(format->extra.xma2.playBegin) = v35;
  v38 = format->extra.extensible.subFormat.data5[2];
  v39 = format->extra.extensible.subFormat.data5[5];
  v40 = format->extra.extensible.subFormat.data5[3];
  format->extra.extensible.subFormat.data5[3] = format->extra.extensible.subFormat.data5[4];
  format->extra.extensible.subFormat.data5[2] = v39;
  format->extra.extensible.subFormat.data5[5] = v38;
  format->extra.extensible.subFormat.data5[4] = v40;
  v41 = BYTE2(format->extra.xma2.loopBegin);
  v42 = BYTE1(format->extra.xma2.loopBegin);
  loopBegin = format->extra.xma2.loopBegin;
  LOBYTE(format->extra.xma2.loopBegin) = HIBYTE(format->extra.xma2.loopBegin);
  BYTE1(format->extra.xma2.loopBegin) = v41;
  HIBYTE(format->extra.xma2.loopBegin) = loopBegin;
  BYTE2(format->extra.xma2.loopBegin) = v42;
  v44 = BYTE1(format->extra.xma2.loopLength);
  v45 = BYTE2(format->extra.xma2.loopLength);
  loopLength_high = HIBYTE(format->extra.xma2.loopLength);
  HIBYTE(format->extra.xma2.loopLength) = format->extra.xma2.loopLength;
  BYTE2(format->extra.xma2.loopLength) = v44;
  LOBYTE(format->extra.xma2.loopLength) = loopLength_high;
  BYTE1(format->extra.xma2.loopLength) = v45;
  blockCount_high = HIBYTE(format->extra.xma2.blockCount);
  HIBYTE(format->extra.xma2.blockCount) = format->extra.xma2.blockCount;
  LOBYTE(format->extra.xma2.blockCount) = blockCount_high;
  return nullptr;
}


// ========================================================================
// ?ReadWaveFormatDirect@idWaveFile@@SA_NAAUwaveFmt_t@1@PAVidFile@@@Z
// EA  : 0x829885E8
// RVA : 0x009885E8
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

int __fastcall idWaveFile::ReadWaveFormatDirect(idWaveFile::waveFmt_t *format, idFile *file)
{
  char formatTag; // r8
  char numChannels_high; // r7
  char samplesPerSec_high; // r3
  char samplesPerSec; // r11
  char v8; // r4
  char avgBytesPerSec_high; // r8
  char avgBytesPerSec; // r7
  char v11; // r9
  char blockSize_high; // r6
  char bitsPerSample_high; // r4
  int v14; // r11
  char extraSize; // r8
  char v16; // r8
  int v17; // r9
  char v18; // r6
  char *v19; // r11
  char v20; // r7
  char v21; // r5
  char extraSize_high; // r8
  char validBitsPerSample; // r8
  char numCoef_high; // r5
  char v26; // r6
  char channelMask; // r4
  char samplesEncoded_high; // r10
  char samplesEncoded; // r9
  char v30; // r11
  char v31; // r6
  char v32; // r5
  char bytesPerBlock_high; // r8
  unsigned __int8 v34; // r10
  unsigned __int8 playBegin_high; // r4
  unsigned __int8 v36; // r3
  unsigned __int8 v37; // r7
  unsigned __int8 v38; // r6
  unsigned __int8 v39; // r8
  char v40; // r3
  char v41; // r11
  char loopBegin; // r4
  char v43; // r8
  char v44; // r7
  char loopLength_high; // r9
  char blockCount_high; // r6
  char v47; // r9
  idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t *p_subFormat; // r11
  int *v49; // r7
  char validBitsPerSample_high; // r5
  char v51; // r9
  char v52; // r3
  char v53; // r10
  char v54; // r8
  char v55; // r5
  char v56; // r4
  char v57; // r9
  char v58; // r5
  char v59; // r3
  int data1_high; // r9
  int v61; // r10
  int v62; // [sp+50h] [-30h] BYREF
  __int16 v63; // [sp+54h] [-2Ch]
  __int16 v64; // [sp+56h] [-2Ah]
  __int16 v65; // [sp+58h] [-28h]
  char v66; // [sp+5Ah] [-26h]
  char v67; // [sp+5Bh] [-25h]
  char v68; // [sp+5Ch] [-24h]
  char v69; // [sp+5Dh] [-23h]
  char v70; // [sp+5Eh] [-22h]
  char v71; // [sp+5Fh] [-21h]
  int v72; // [sp+60h] [-20h] BYREF

  file->Read(this: file, a2: format, a3: 16u);
  formatTag = format->basic.formatTag;
  LOBYTE(format->basic.formatTag) = HIBYTE(format->basic.formatTag);
  HIBYTE(format->basic.formatTag) = formatTag;
  numChannels_high = HIBYTE(format->basic.numChannels);
  HIBYTE(format->basic.numChannels) = format->basic.numChannels;
  LOBYTE(format->basic.numChannels) = numChannels_high;
  samplesPerSec_high = HIBYTE(format->basic.samplesPerSec);
  samplesPerSec = format->basic.samplesPerSec;
  v8 = BYTE1(format->basic.samplesPerSec);
  BYTE1(format->basic.samplesPerSec) = BYTE2(format->basic.samplesPerSec);
  HIBYTE(format->basic.samplesPerSec) = samplesPerSec;
  LOBYTE(format->basic.samplesPerSec) = samplesPerSec_high;
  BYTE2(format->basic.samplesPerSec) = v8;
  avgBytesPerSec_high = HIBYTE(format->basic.avgBytesPerSec);
  avgBytesPerSec = format->basic.avgBytesPerSec;
  v11 = BYTE1(format->basic.avgBytesPerSec);
  BYTE1(format->basic.avgBytesPerSec) = BYTE2(format->basic.avgBytesPerSec);
  HIBYTE(format->basic.avgBytesPerSec) = avgBytesPerSec;
  LOBYTE(format->basic.avgBytesPerSec) = avgBytesPerSec_high;
  BYTE2(format->basic.avgBytesPerSec) = v11;
  blockSize_high = HIBYTE(format->basic.blockSize);
  HIBYTE(format->basic.blockSize) = format->basic.blockSize;
  LOBYTE(format->basic.blockSize) = blockSize_high;
  bitsPerSample_high = HIBYTE(format->basic.bitsPerSample);
  HIBYTE(format->basic.bitsPerSample) = format->basic.bitsPerSample;
  LOBYTE(format->basic.bitsPerSample) = bitsPerSample_high;
  v14 = format->basic.formatTag;
  if ( v14 == 1 )
    return 1;
  if ( v14 != 2 )
  {
    if ( v14 == 358 )
    {
      file->Read(this: file, a2: &format->extraSize, a3: 2u);
      extraSize_high = HIBYTE(format->extraSize);
      HIBYTE(format->extraSize) = format->extraSize;
      LOBYTE(format->extraSize) = extraSize_high;
      if ( format->extraSize == 34 )
      {
        file->Read(this: file, a2: &format->extra, a3: 34u);
        validBitsPerSample = format->extra.extensible.validBitsPerSample;
        LOBYTE(format->extra.extensible.validBitsPerSample) = HIBYTE(format->extra.extensible.validBitsPerSample);
        HIBYTE(format->extra.extensible.validBitsPerSample) = validBitsPerSample;
        numCoef_high = HIBYTE(format->extra.adpcm.numCoef);
        v26 = BYTE1(format->extra.xma2.channelMask);
        BYTE1(format->extra.xma2.channelMask) = BYTE2(format->extra.xma2.channelMask);
        channelMask = format->extra.xma2.channelMask;
        LOBYTE(format->extra.xma2.channelMask) = numCoef_high;
        BYTE2(format->extra.xma2.channelMask) = v26;
        HIBYTE(format->extra.adpcm.numCoef) = channelMask;
        samplesEncoded_high = HIBYTE(format->extra.xma2.samplesEncoded);
        samplesEncoded = format->extra.xma2.samplesEncoded;
        v30 = BYTE2(format->extra.xma2.samplesEncoded);
        BYTE2(format->extra.xma2.samplesEncoded) = BYTE1(format->extra.xma2.samplesEncoded);
        HIBYTE(format->extra.xma2.samplesEncoded) = samplesEncoded;
        LOBYTE(format->extra.xma2.samplesEncoded) = samplesEncoded_high;
        BYTE1(format->extra.xma2.samplesEncoded) = v30;
        v31 = BYTE2(format->extra.xma2.bytesPerBlock);
        v32 = BYTE1(format->extra.xma2.bytesPerBlock);
        bytesPerBlock_high = HIBYTE(format->extra.xma2.bytesPerBlock);
        HIBYTE(format->extra.xma2.bytesPerBlock) = format->extra.xma2.bytesPerBlock;
        BYTE2(format->extra.xma2.bytesPerBlock) = v32;
        LOBYTE(format->extra.xma2.bytesPerBlock) = bytesPerBlock_high;
        BYTE1(format->extra.xma2.bytesPerBlock) = v31;
        v34 = BYTE1(format->extra.xma2.playBegin);
        playBegin_high = HIBYTE(format->extra.xma2.playBegin);
        v36 = format->extra.extensible.subFormat.data5[0];
        HIBYTE(format->extra.xma2.playBegin) = format->extra.extensible.subFormat.data5[1];
        BYTE1(format->extra.xma2.playBegin) = v36;
        format->extra.extensible.subFormat.data5[0] = v34;
        format->extra.extensible.subFormat.data5[1] = playBegin_high;
        v37 = format->extra.extensible.subFormat.data5[2];
        v38 = format->extra.extensible.subFormat.data5[5];
        v39 = format->extra.extensible.subFormat.data5[3];
        format->extra.extensible.subFormat.data5[3] = format->extra.extensible.subFormat.data5[4];
        format->extra.extensible.subFormat.data5[2] = v38;
        format->extra.extensible.subFormat.data5[5] = v37;
        format->extra.extensible.subFormat.data5[4] = v39;
        v40 = BYTE1(format->extra.xma2.loopBegin);
        v41 = BYTE2(format->extra.xma2.loopBegin);
        loopBegin = format->extra.xma2.loopBegin;
        LOBYTE(format->extra.xma2.loopBegin) = HIBYTE(format->extra.xma2.loopBegin);
        BYTE2(format->extra.xma2.loopBegin) = v40;
        HIBYTE(format->extra.xma2.loopBegin) = loopBegin;
        BYTE1(format->extra.xma2.loopBegin) = v41;
        v43 = BYTE1(format->extra.xma2.loopLength);
        v44 = BYTE2(format->extra.xma2.loopLength);
        loopLength_high = HIBYTE(format->extra.xma2.loopLength);
        HIBYTE(format->extra.xma2.loopLength) = format->extra.xma2.loopLength;
        LOBYTE(format->extra.xma2.loopLength) = loopLength_high;
        BYTE1(format->extra.xma2.loopLength) = v44;
        BYTE2(format->extra.xma2.loopLength) = v43;
        blockCount_high = HIBYTE(format->extra.xma2.blockCount);
        HIBYTE(format->extra.xma2.blockCount) = format->extra.xma2.blockCount;
        LOBYTE(format->extra.xma2.blockCount) = blockCount_high;
        return 1;
      }
    }
    else if ( v14 == 0xFFFF )
    {
      file->Read(this: file, a2: &format->extraSize, a3: 2u);
      v47 = HIBYTE(format->extraSize);
      HIBYTE(format->extraSize) = format->extraSize;
      LOBYTE(format->extraSize) = v47;
      if ( format->extraSize == 22 )
      {
        file->Read(this: file, a2: &format->extra, a3: 22u);
        v64 = 16;
        v67 = -86;
        v62 = 1;
        v70 = -101;
        v71 = 113;
        p_subFormat = &format->extra.extensible.subFormat;
        v69 = 56;
        v49 = &v62;
        v63 = 0;
        v66 = 0;
        v68 = 0;
        v65 = 0x8000;
        validBitsPerSample_high = HIBYTE(format->extra.extensible.validBitsPerSample);
        HIBYTE(format->extra.extensible.validBitsPerSample) = format->extra.extensible.validBitsPerSample;
        LOBYTE(format->extra.extensible.validBitsPerSample) = validBitsPerSample_high;
        v51 = HIBYTE(format->extra.adpcm.numCoef);
        v52 = format->extra.xma2.channelMask;
        v53 = BYTE2(format->extra.xma2.channelMask);
        BYTE2(format->extra.xma2.channelMask) = BYTE1(format->extra.xma2.channelMask);
        HIBYTE(format->extra.adpcm.numCoef) = v52;
        BYTE1(format->extra.xma2.channelMask) = v53;
        LOBYTE(format->extra.xma2.channelMask) = v51;
        v54 = format->extra.xma2.samplesEncoded;
        v55 = BYTE1(format->extra.xma2.samplesEncoded);
        v56 = BYTE2(format->extra.xma2.samplesEncoded);
        LOBYTE(format->extra.xma2.samplesEncoded) = HIBYTE(format->extra.xma2.samplesEncoded);
        BYTE1(format->extra.xma2.samplesEncoded) = v56;
        HIBYTE(format->extra.xma2.samplesEncoded) = v54;
        BYTE2(format->extra.xma2.samplesEncoded) = v55;
        v57 = BYTE1(format->extra.xma2.bytesPerBlock);
        BYTE1(format->extra.xma2.bytesPerBlock) = HIBYTE(format->extra.xma2.bytesPerBlock);
        HIBYTE(format->extra.xma2.bytesPerBlock) = v57;
        v58 = BYTE2(format->extra.xma2.bytesPerBlock);
        BYTE2(format->extra.xma2.bytesPerBlock) = format->extra.xma2.bytesPerBlock;
        LOBYTE(format->extra.xma2.bytesPerBlock) = v58;
        v59 = HIBYTE(format->extra.xma2.playBegin);
        HIBYTE(format->extra.xma2.playBegin) = BYTE1(format->extra.xma2.playBegin);
        BYTE1(format->extra.xma2.playBegin) = v59;
        do
        {
          data1_high = HIBYTE(p_subFormat->data1);
          v61 = *(unsigned __int8 *)v49 - data1_high;
          if ( *(unsigned __int8 *)v49 != data1_high )
            break;
          v49 = (int *)((char *)v49 + 1);
          p_subFormat = (idWaveFile::waveFmt_t::extra_t::extensible_t::guid_t *)((char *)p_subFormat + 1);
        }
        while ( v49 != &v72 );
        if ( v61 == 0 )
          return 1;
      }
    }
    return 0;
  }
  file->Read(this: file, a2: &format->extraSize, a3: 2u);
  extraSize = format->extraSize;
  LOBYTE(format->extraSize) = HIBYTE(format->extraSize);
  HIBYTE(format->extraSize) = extraSize;
  if ( format->extraSize != 32 )
    return 0;
  file->Read(this: file, a2: &format->extra, a3: 32u);
  v16 = HIBYTE(format->extra.extensible.validBitsPerSample);
  v17 = 0;
  HIBYTE(format->extra.extensible.validBitsPerSample) = format->extra.extensible.validBitsPerSample;
  LOBYTE(format->extra.extensible.validBitsPerSample) = v16;
  v18 = HIBYTE(format->extra.adpcm.numCoef);
  HIBYTE(format->extra.adpcm.numCoef) = BYTE1(format->extra.xma2.channelMask);
  BYTE1(format->extra.xma2.channelMask) = v18;
  if ( format->extra.adpcm.numCoef == 0 )
    return 1;
  v19 = (char *)&format->extra.xma2.channelMask + 1;
  do
  {
    ++v17;
    v20 = v19[2];
    v19[2] = v19[1];
    v19[1] = v20;
    v21 = v19[3];
    v19[3] = v19[4];
    v19 += 4;
    *v19 = v21;
  }
  while ( v17 < format->extra.adpcm.numCoef );
  return 1;
}


// ========================================================================
// ?Close@idWaveFile@@QAAXXZ
// EA  : 0x82988A90
// RVA : 0x00988A90
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

void __fastcall idWaveFile::Close(idWaveFile *this)
{
  idFile *file; // r3
  idList<idVehicleState *,5> *p_chunks; // r31

  file = this->file;
  if ( file != nullptr )
  {
    ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
    this->file = nullptr;
  }
  p_chunks = (idList<idVehicleState *,5> *)&this->chunks;
  if ( p_chunks->size < 0 )
    idList<idThread *,58>::Clear(this: p_chunks);
  p_chunks->num = __CFADD__(-p_chunks->size, p_chunks->size ^ 0x80000000) ? 0 : p_chunks->size;
}


// ========================================================================
// ?Open@idWaveFile@@QAA_NPBD@Z
// EA  : 0x82988B28
// RVA : 0x00988B28
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

int __fastcall idWaveFile::Open(idWaveFile *this, const char *filename)
{
  char *LocalizedName; // r3
  const char *v5; // r26
  idFile *v6; // r3
  idFile *v7; // r3
  char v8; // r5
  char v9; // r4
  unsigned int v10; // r28
  unsigned int v11; // r29
  unsigned int v12; // r29
  char v13; // r10
  char v14; // r9
  int num; // r7
  int size; // r6
  presentableObject_t *v17; // r3
  int v18; // r11
  const char *v20; // [sp+50h] [-3A0h] BYREF
  int v21; // [sp+54h] [-39Ch]
  int v22; // [sp+58h] [-398h] BYREF
  unsigned int v23; // [sp+5Ch] [-394h]
  int v24; // [sp+60h] [-390h]
  idStr v25; // [sp+70h] [-380h] BYREF
  char v26; // [sp+90h] [-360h] BYREF
  idStrStatic<256> v27; // [sp+190h] [-260h] BYREF
  char v28; // [sp+2B0h] [-140h] BYREF

  idWaveFile::Close(this);
  if ( filename == nullptr || *filename == 0 )
    return 0;
  LocalizedName = idResource::GetLocalizedName(inName: filename, outName: &v28, sizeOfOutName: 256);
  v5 = LocalizedName;
  if ( sys_localization.valueInteger != 0 && strstr(str1: LocalizedName, str2: "/vo/") != nullptr )
  {
    v25.baseBuffer[0] = 0;
    v26 = 0;
    v25.data = &v26;
    v25.len = 0;
    v25.allocedAndFlag = -2147483392;
    idStrStatic<256>::idStrStatic<256>(this: &v27, text: v5);
    v25.len = v27.len;
    memcpy(Dst: v25.data, Src: v27.data, Size: v27.len + 1);
    idStr::FreeData(this: &v27);
    idStr::ToLower(this: &v25);
    idStr::BackSlashesToSlashes(this: &v25);
    if ( idStr::Find(searchIn: v25.data, searchFor: ".msadpcm", casesensitive: true, start: 0, end: v25.len) >= 0 )
      idStr::Replace(this: &v25, old: ".msadpcm", nw: ".wav");
    v6 = fileSystem->OpenFileRead(this: fileSystem, a2: v25.data, a3: 0, a4: 0);
    this->file = v6;
    if ( v6 == nullptr )
    {
      idStr::Replace(this: &v25, old: ".wav", nw: ".msadpcm");
      this->file = fileSystem->OpenFileRead(this: fileSystem, a2: v25.data, a3: 0, a4: 0);
    }
    idStr::FreeData(this: &v25);
  }
  if ( this->file == nullptr )
  {
    v7 = fileSystem->OpenFileRead(this: fileSystem, a2: v5, a3: 1, a4: 0);
    this->file = v7;
    if ( v7 == nullptr )
      return 0;
  }
  if ( (int)this->file->Length(this: this->file) == 0 )
  {
    idWaveFile::Close(this);
    return 0;
  }
  this->file->Read(this: this->file, a2: &v22, a3: 12u);
  v8 = v23;
  v9 = BYTE2(v23);
  LOBYTE(v23) = HIBYTE(v23);
  BYTE2(v23) = BYTE1(v23);
  HIBYTE(v23) = v8;
  BYTE1(v23) = v9;
  if ( v22 != 1380533830 || v24 != 1463899717 || v23 < 4 )
  {
    idWaveFile::Close(this);
    idLib::Warning(fmt: "Header is not RIFF WAVE in %s", v5);
    return 0;
  }
  v10 = v23 + 8;
  v11 = 12;
  if ( v23 + 8 > 0xC )
  {
    while ( this->file->Read(this: this->file, a2: &v20, a3: 8u) == 8 )
    {
      v12 = v11 + 8;
      v13 = BYTE1(v21);
      v14 = v21;
      num = this->chunks.num;
      size = this->chunks.size;
      LOBYTE(v21) = HIBYTE(v21);
      HIBYTE(v21) = v14;
      BYTE1(v21) = BYTE2(v21);
      BYTE2(v21) = v13;
      if ( num >= size )
      {
        idWaveFile::Close(this);
        idLib::Warning(fmt: "More than %d chunks in %s", this->chunks.size, v5);
        return 0;
      }
      v17 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: (idList<presentableObject_t,5> *)&this->chunks);
      v17->name = v20;
      v18 = v21;
      *(_DWORD *)&v17->skipReplication = v12;
      v11 = v18 + v12;
      v17->presentableIndex = v18;
      this->file->Seek(this: this->file, a2: v11, a3: FS_SEEK_SET);
      if ( v11 >= v10 )
        return 1;
    }
  }
  return 1;
}


// ========================================================================
// __unwind$224276
// EA  : 0x82988E6C
// RVA : 0x00988E6C
// PDB : w:\tech5\engine\sound\files\wavefile.cpp
// ========================================================================

void _unwind_224276()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1008 + 112));
}

