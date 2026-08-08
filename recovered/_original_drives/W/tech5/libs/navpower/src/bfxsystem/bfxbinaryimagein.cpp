
// ========================================================================
// ?GetImageSize@BinaryImageIn@bfx@@SAHPBD@Z
// EA  : 0x8329C128
// RVA : 0x0129C128
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

unsigned int __fastcall bfx::BinaryImageIn::GetImageSize(const char *pBinaryImage)
{
  unsigned int v1; // r11
  bool v2; // zf
  unsigned int v4; // [sp+50h] [-10h] BYREF

  v1 = *((_DWORD *)pBinaryImage + 2);
  v2 = *(_DWORD *)pBinaryImage != 0;
  v4 = v1;
  if ( !v2 )
  {
    bfx::EndianSwapLong(val: &v4);
    v1 = v4;
  }
  return v1 + 24;
}


// ========================================================================
// ?GetResourceHeader@BinaryImageIn@bfx@@SAXPBDAAUResourceHeader@2@@Z
// EA  : 0x8329C168
// RVA : 0x0129C168
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

void __fastcall bfx::BinaryImageIn::GetResourceHeader(const char *pBinaryImage, bfx::ResourceHeader *header)
{
  const char *v2; // r11
  unsigned int *p_m_pad; // r10
  BOOL v4; // r8
  int i; // ctr

  v2 = pBinaryImage - 4;
  p_m_pad = &header[-1].m_pad;
  v4 = *(_DWORD *)pBinaryImage != 0;
  for ( i = 6; i != 0; --i )
  {
    v2 += 4;
    *++p_m_pad = *(_DWORD *)v2;
  }
  if ( !v4 )
    bfx::ResourceHeader::EndianSwap(this: header);
}


// ========================================================================
// ?FixLong@BinaryImageIn@bfx@@AAAXXZ
// EA  : 0x8329C1A8
// RVA : 0x0129C1A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

void __fastcall bfx::BinaryImageIn::FixLong(bfx::BinaryImageIn *this)
{
  char *m_pRead; // r11
  char v2; // r9
  char v3; // r8

  m_pRead = this->m_pRead;
  if ( this->m_endian != BFX_BIG_ENDIAN )
  {
    v2 = *m_pRead;
    *m_pRead = m_pRead[3];
    m_pRead[3] = v2;
    v3 = m_pRead[1];
    m_pRead[1] = m_pRead[2];
    m_pRead[2] = v3;
  }
  this->m_pRead += 4;
}


// ========================================================================
// ?PopSection@BinaryImageIn@bfx@@QAAXXZ
// EA  : 0x8329C1E8
// RVA : 0x0129C1E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

void __fastcall bfx::BinaryImageIn::PopSection(bfx::BinaryImageIn *this)
{
  int m_size; // r11
  const bfx::ResourceSectionHeader *v2; // r11

  m_size = this->m_sectionStack.m_size;
  if ( m_size != 0 )
  {
    v2 = this->m_sectionStack.m_data[m_size - 1];
    --this->m_sectionStack.m_size;
    this->m_pRead = (char *)&v2[1] + v2->m_size;
  }
}


// ========================================================================
// ??0BinaryImageIn@bfx@@QAA@PAD_N@Z
// EA  : 0x8329C230
// RVA : 0x0129C230
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

bfx::BinaryImageIn *__fastcall bfx::BinaryImageIn::BinaryImageIn(
        bfx::BinaryImageIn *this,
        char *pBinaryImage,
        bool bEndianFixed)
{
  bfx::bfxMemTag v3; // r10
  char *m_pRead; // r10
  bfx::Endian v5; // r11
  bfx::Endian m_endian; // r9
  char *v7; // r11
  char v8; // r8
  char v9; // r6
  bfx::Endian v10; // r9
  char *v11; // r11
  char v12; // r8
  char v13; // r6
  bfx::Endian v14; // r9
  char *v15; // r11
  char v16; // r8
  char v17; // r6

  this->m_pRead = pBinaryImage;
  this->m_pImage = pBinaryImage;
  v3 = bfx::MEM_BFXSYSTEM;
  this->m_sectionStack.m_data = nullptr;
  this->m_sectionStack.m_size = 0;
  this->m_sectionStack.m_cap = 0;
  this->m_sectionStack.m_tag = v3;
  m_pRead = this->m_pRead;
  v5 = bEndianFixed || *(_DWORD *)m_pRead != 0;
  this->m_endian = v5;
  if ( v5 != BFX_BIG_ENDIAN )
    *(_DWORD *)m_pRead = (*(_DWORD *)m_pRead != 0) - 1;
  m_endian = this->m_endian;
  v7 = this->m_pRead + 4;
  this->m_pRead = v7;
  if ( m_endian != BFX_BIG_ENDIAN )
  {
    v8 = *v7;
    *v7 = v7[3];
    v7[3] = v8;
    v9 = v7[1];
    v7[1] = v7[2];
    v7[2] = v9;
  }
  v10 = this->m_endian;
  v11 = this->m_pRead + 4;
  this->m_pRead = v11;
  if ( v10 != BFX_BIG_ENDIAN )
  {
    v12 = *v11;
    *v11 = v11[3];
    v11[3] = v12;
    v13 = v11[1];
    v11[1] = v11[2];
    v11[2] = v13;
  }
  v14 = this->m_endian;
  v15 = this->m_pRead + 4;
  this->m_pRead = v15;
  if ( v14 != BFX_BIG_ENDIAN )
  {
    v16 = *v15;
    *v15 = v15[3];
    v15[3] = v16;
    v17 = v15[1];
    v15[1] = v15[2];
    v15[2] = v17;
  }
  this->m_pRead += 12;
  this->m_imageSize = *((_DWORD *)m_pRead + 2) + 24;
  return this;
}


// ========================================================================
// ?PushSection@BinaryImageIn@bfx@@QAAPBUResourceSectionHeader@2@XZ
// EA  : 0x8329C360
// RVA : 0x0129C360
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.cpp
// ========================================================================

const bfx::ResourceSectionHeader *__fastcall bfx::BinaryImageIn::PushSection(bfx::BinaryImageIn *this)
{
  char *m_pRead; // r10
  bfx::Endian m_endian; // r9
  char *v3; // r31
  char v4; // r8
  char v5; // r7
  bfx::Endian v6; // r9
  char *v7; // r10
  char v8; // r8
  char v9; // r6
  bfx::Endian v10; // r9
  char *v11; // r10
  char v12; // r8
  char v13; // r6
  bfx::Space *v15; // [sp+50h] [-20h] BYREF

  m_pRead = this->m_pRead;
  m_endian = this->m_endian;
  v3 = m_pRead;
  v15 = (bfx::Space *)m_pRead;
  if ( m_endian != BFX_BIG_ENDIAN )
  {
    v4 = *m_pRead;
    *m_pRead = m_pRead[3];
    m_pRead[3] = v4;
    v5 = m_pRead[1];
    m_pRead[1] = m_pRead[2];
    m_pRead[2] = v5;
  }
  v6 = this->m_endian;
  v7 = this->m_pRead + 4;
  this->m_pRead = v7;
  if ( v6 != BFX_BIG_ENDIAN )
  {
    v8 = *v7;
    *v7 = v7[3];
    v7[3] = v8;
    v9 = v7[1];
    v7[1] = v7[2];
    v7[2] = v9;
  }
  v10 = this->m_endian;
  v11 = this->m_pRead + 4;
  this->m_pRead = v11;
  if ( v10 != BFX_BIG_ENDIAN )
  {
    v12 = *v11;
    *v11 = v11[3];
    v11[3] = v12;
    v13 = v11[1];
    v11[1] = v11[2];
    v11[2] = v13;
  }
  this->m_pRead += 4;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_sectionStack, val: &v15);
  return (const bfx::ResourceSectionHeader *)v3;
}

