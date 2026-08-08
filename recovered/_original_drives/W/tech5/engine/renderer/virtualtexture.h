
// ========================================================================
// ?Swap@pageFileHeader_t@@QAAXXZ
// EA  : 0x82978C50
// RVA : 0x00978C50
// PDB : w:\tech5\engine\renderer\virtualtexture.h
// ========================================================================

void __fastcall pageFileHeader_t::Swap(pageFileHeader_t *this)
{
  char magic; // r9
  char v2; // r8
  char v3; // r7
  char v4; // r4
  char v5; // r9
  int v6; // ctr
  char *v7; // r11
  char pagesWide; // r5
  char installedMipAndOffset_high; // r6
  char installedMipAndOffset; // r5
  char v11; // r7
  char numLevels_high; // r4
  char layoutVersion_high; // r8
  char totalPages_high; // r4
  char totalPages; // r9
  char v16; // r5
  char diskOffsetScale_high; // r6
  char diskOffsetScale; // r5
  char v19; // r7
  char totalFileSize_high; // r8
  char totalFileSize; // r7
  char v22; // r6
  char v23; // r5
  char v24; // r31
  char v25; // r30
  char v26; // r4
  char magic_high; // r9
  char v28; // r4
  char v29; // r10
  char pageCompression; // r5
  char pageCompression_high; // r4
  char v32; // r7
  char v33; // r9
  char v34; // r8
  char v35; // r7
  char *v36; // r11
  int i; // ctr
  char v38; // r9
  char x; // r8
  char y; // r6
  char level_high; // r4
  char reserved; // r11

  magic = this->magic;
  v2 = BYTE1(this->magic);
  v3 = BYTE2(this->magic);
  LOBYTE(this->magic) = HIBYTE(this->magic);
  HIBYTE(this->magic) = magic;
  BYTE2(this->magic) = v2;
  BYTE1(this->magic) = v3;
  v4 = BYTE1(this->pagesWide);
  v5 = BYTE2(this->pagesWide);
  v6 = 4;
  v7 = (char *)&this->subRoot.pageCompression + 2;
  pagesWide = this->pagesWide;
  LOBYTE(this->pagesWide) = HIBYTE(this->pagesWide);
  BYTE2(this->pagesWide) = v4;
  HIBYTE(this->pagesWide) = pagesWide;
  BYTE1(this->pagesWide) = v5;
  installedMipAndOffset_high = HIBYTE(this->installedMipAndOffset);
  installedMipAndOffset = this->installedMipAndOffset;
  v11 = BYTE1(this->installedMipAndOffset);
  BYTE1(this->installedMipAndOffset) = BYTE2(this->installedMipAndOffset);
  HIBYTE(this->installedMipAndOffset) = installedMipAndOffset;
  LOBYTE(this->installedMipAndOffset) = installedMipAndOffset_high;
  BYTE2(this->installedMipAndOffset) = v11;
  numLevels_high = HIBYTE(this->numLevels);
  HIBYTE(this->numLevels) = this->numLevels;
  LOBYTE(this->numLevels) = numLevels_high;
  layoutVersion_high = HIBYTE(this->layoutVersion);
  HIBYTE(this->layoutVersion) = this->layoutVersion;
  LOBYTE(this->layoutVersion) = layoutVersion_high;
  totalPages_high = HIBYTE(this->totalPages);
  totalPages = this->totalPages;
  v16 = BYTE1(this->totalPages);
  BYTE1(this->totalPages) = BYTE2(this->totalPages);
  HIBYTE(this->totalPages) = totalPages;
  LOBYTE(this->totalPages) = totalPages_high;
  BYTE2(this->totalPages) = v16;
  diskOffsetScale_high = HIBYTE(this->diskOffsetScale);
  diskOffsetScale = this->diskOffsetScale;
  v19 = BYTE1(this->diskOffsetScale);
  BYTE1(this->diskOffsetScale) = BYTE2(this->diskOffsetScale);
  HIBYTE(this->diskOffsetScale) = diskOffsetScale;
  LOBYTE(this->diskOffsetScale) = diskOffsetScale_high;
  BYTE2(this->diskOffsetScale) = v19;
  totalFileSize_high = HIBYTE(this->totalFileSize);
  totalFileSize = this->totalFileSize;
  v22 = BYTE4(this->totalFileSize);
  v23 = BYTE1(this->totalFileSize);
  v24 = BYTE6(this->totalFileSize);
  v25 = BYTE3(this->totalFileSize);
  v26 = BYTE2(this->totalFileSize);
  BYTE2(this->totalFileSize) = BYTE5(this->totalFileSize);
  BYTE1(this->totalFileSize) = v24;
  HIBYTE(this->totalFileSize) = totalFileSize;
  LOBYTE(this->totalFileSize) = totalFileSize_high;
  BYTE6(this->totalFileSize) = v23;
  BYTE5(this->totalFileSize) = v26;
  BYTE3(this->totalFileSize) = v22;
  BYTE4(this->totalFileSize) = v25;
  magic_high = HIBYTE(this->subRoot.magic);
  v28 = BYTE2(this->subRoot.magic);
  v29 = BYTE1(this->subRoot.magic);
  HIBYTE(this->subRoot.magic) = this->subRoot.magic;
  LOBYTE(this->subRoot.magic) = magic_high;
  BYTE1(this->subRoot.magic) = v28;
  BYTE2(this->subRoot.magic) = v29;
  pageCompression = this->subRoot.pageCompression;
  pageCompression_high = HIBYTE(this->subRoot.pageCompression);
  v32 = BYTE2(this->subRoot.pageCompression);
  BYTE2(this->subRoot.pageCompression) = BYTE1(this->subRoot.pageCompression);
  HIBYTE(this->subRoot.pageCompression) = pageCompression;
  LOBYTE(this->subRoot.pageCompression) = pageCompression_high;
  BYTE1(this->subRoot.pageCompression) = v32;
  do
  {
    v33 = v7[5];
    v34 = v7[4];
    v35 = v7[3];
    v7[5] = v7[2];
    v7[2] = v33;
    v7[3] = v34;
    v7 += 4;
    *v7 = v35;
    --v6;
  }
  while ( v6 != 0 );
  v36 = (char *)&this->subRoot.finerDiskOffset[3] + 3;
  for ( i = 4; i != 0; --i )
  {
    v38 = v36[1];
    v36[1] = v36[2];
    v36 += 2;
    *v36 = v38;
  }
  x = this->subRoot.x;
  LOBYTE(this->subRoot.x) = HIBYTE(this->subRoot.x);
  HIBYTE(this->subRoot.x) = x;
  y = this->subRoot.y;
  LOBYTE(this->subRoot.y) = HIBYTE(this->subRoot.y);
  HIBYTE(this->subRoot.y) = y;
  level_high = HIBYTE(this->subRoot.level);
  HIBYTE(this->subRoot.level) = this->subRoot.level;
  LOBYTE(this->subRoot.level) = level_high;
  reserved = this->subRoot.reserved;
  LOBYTE(this->subRoot.reserved) = HIBYTE(this->subRoot.reserved);
  HIBYTE(this->subRoot.reserved) = reserved;
}


// ========================================================================
// ?Swap@pageHeader_t@@QAAXXZ
// EA  : 0x8297AC30
// RVA : 0x0097AC30
// PDB : w:\tech5\engine\renderer\virtualtexture.h
// ========================================================================

void __fastcall pageHeader_t::Swap(pageHeader_t *this)
{
  char magic; // r8
  char v2; // r7
  char *v3; // r11
  char v4; // r6
  int v5; // ctr
  char pageCompression_high; // r10
  char pageCompression; // r9
  char v8; // r4
  char v9; // r9
  char v10; // r8
  char v11; // r7
  char *v12; // r11
  int i; // ctr
  char v14; // r9
  char x_high; // r9
  char y; // r6
  char level; // r5
  char reserved_high; // r11

  magic = this->magic;
  v2 = BYTE1(this->magic);
  v3 = (char *)&this->pageCompression + 2;
  v4 = BYTE2(this->magic);
  LOBYTE(this->magic) = HIBYTE(this->magic);
  v5 = 4;
  HIBYTE(this->magic) = magic;
  BYTE2(this->magic) = v2;
  BYTE1(this->magic) = v4;
  pageCompression_high = HIBYTE(this->pageCompression);
  pageCompression = this->pageCompression;
  v8 = BYTE1(this->pageCompression);
  BYTE1(this->pageCompression) = BYTE2(this->pageCompression);
  HIBYTE(this->pageCompression) = pageCompression;
  LOBYTE(this->pageCompression) = pageCompression_high;
  BYTE2(this->pageCompression) = v8;
  do
  {
    v9 = v3[5];
    v10 = v3[4];
    v11 = v3[3];
    v3[5] = v3[2];
    v3[2] = v9;
    v3[3] = v10;
    v3 += 4;
    *v3 = v11;
    --v5;
  }
  while ( v5 != 0 );
  v12 = (char *)&this->finerDiskOffset[3] + 3;
  for ( i = 4; i != 0; --i )
  {
    v14 = v12[1];
    v12[1] = v12[2];
    v12 += 2;
    *v12 = v14;
  }
  x_high = HIBYTE(this->x);
  HIBYTE(this->x) = this->x;
  LOBYTE(this->x) = x_high;
  y = this->y;
  LOBYTE(this->y) = HIBYTE(this->y);
  HIBYTE(this->y) = y;
  level = this->level;
  LOBYTE(this->level) = HIBYTE(this->level);
  HIBYTE(this->level) = level;
  reserved_high = HIBYTE(this->reserved);
  HIBYTE(this->reserved) = this->reserved;
  LOBYTE(this->reserved) = reserved_high;
}


// ========================================================================
// ?CopySwap@pageHeader_t@@QAAXPAU1@@Z
// EA  : 0x8297C3D0
// RVA : 0x0097C3D0
// PDB : w:\tech5\engine\renderer\virtualtexture.h
// ========================================================================

void __fastcall pageHeader_t::CopySwap(pageHeader_t *this, pageHeader_t *src)
{
  HIBYTE(this->magic) = src->magic;
  BYTE1(this->magic) = BYTE2(src->magic);
  BYTE2(this->magic) = BYTE1(src->magic);
  LOBYTE(this->magic) = HIBYTE(src->magic);
  HIBYTE(this->pageCompression) = src->pageCompression;
  BYTE1(this->pageCompression) = BYTE2(src->pageCompression);
  BYTE2(this->pageCompression) = BYTE1(src->pageCompression);
  LOBYTE(this->pageCompression) = HIBYTE(src->pageCompression);
  HIBYTE(this->finerDiskOffset[0]) = src->finerDiskOffset[0];
  BYTE1(this->finerDiskOffset[0]) = BYTE2(src->finerDiskOffset[0]);
  BYTE2(this->finerDiskOffset[0]) = BYTE1(src->finerDiskOffset[0]);
  LOBYTE(this->finerDiskOffset[0]) = HIBYTE(src->finerDiskOffset[0]);
  HIBYTE(this->finerDiskLength[0]) = src->finerDiskLength[0];
  LOBYTE(this->finerDiskLength[0]) = HIBYTE(src->finerDiskLength[0]);
  HIBYTE(this->finerDiskOffset[1]) = src->finerDiskOffset[1];
  BYTE1(this->finerDiskOffset[1]) = BYTE2(src->finerDiskOffset[1]);
  BYTE2(this->finerDiskOffset[1]) = BYTE1(src->finerDiskOffset[1]);
  LOBYTE(this->finerDiskOffset[1]) = HIBYTE(src->finerDiskOffset[1]);
  HIBYTE(this->finerDiskLength[1]) = src->finerDiskLength[1];
  LOBYTE(this->finerDiskLength[1]) = HIBYTE(src->finerDiskLength[1]);
  HIBYTE(this->finerDiskOffset[2]) = src->finerDiskOffset[2];
  BYTE1(this->finerDiskOffset[2]) = BYTE2(src->finerDiskOffset[2]);
  BYTE2(this->finerDiskOffset[2]) = BYTE1(src->finerDiskOffset[2]);
  LOBYTE(this->finerDiskOffset[2]) = HIBYTE(src->finerDiskOffset[2]);
  HIBYTE(this->finerDiskLength[2]) = src->finerDiskLength[2];
  LOBYTE(this->finerDiskLength[2]) = HIBYTE(src->finerDiskLength[2]);
  HIBYTE(this->finerDiskOffset[3]) = src->finerDiskOffset[3];
  BYTE1(this->finerDiskOffset[3]) = BYTE2(src->finerDiskOffset[3]);
  BYTE2(this->finerDiskOffset[3]) = BYTE1(src->finerDiskOffset[3]);
  LOBYTE(this->finerDiskOffset[3]) = HIBYTE(src->finerDiskOffset[3]);
  HIBYTE(this->finerDiskLength[3]) = src->finerDiskLength[3];
  LOBYTE(this->finerDiskLength[3]) = HIBYTE(src->finerDiskLength[3]);
  HIBYTE(this->x) = src->x;
  LOBYTE(this->x) = HIBYTE(src->x);
  HIBYTE(this->y) = src->y;
  LOBYTE(this->y) = HIBYTE(src->y);
  HIBYTE(this->level) = src->level;
  LOBYTE(this->level) = HIBYTE(src->level);
  HIBYTE(this->reserved) = src->reserved;
  LOBYTE(this->reserved) = HIBYTE(src->reserved);
}

