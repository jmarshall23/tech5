
// ========================================================================
// ?InitAdaptiveHuffman@@YAXPAUhdpCodecParms_t@@PAUhdpAdaptiveHuffman_t@@H@Z
// EA  : 0x828F9190
// RVA : 0x008F9190
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdphuffman.cpp
// ========================================================================

void __fastcall InitAdaptiveHuffman(hdpCodecParms_t *codecParms, hdpAdaptiveHuffman_t *adaptHuff, int numSymbols)
{
  memset(Dst: adaptHuff, Val: 0, Size: sizeof(hdpAdaptiveHuffman_t));
  adaptHuff->numSymbols = numSymbols;
}


// ========================================================================
// ?ShutdownAdaptiveHuffman@@YAXPAUhdpCodecParms_t@@PAUhdpAdaptiveHuffman_t@@@Z
// EA  : 0x828F91D8
// RVA : 0x008F91D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdphuffman.cpp
// ========================================================================

void __fastcall ShutdownAdaptiveHuffman(hdpCodecParms_t *codecParms, hdpAdaptiveHuffman_t *adaptHuff)
{
  adaptHuff->encTable = nullptr;
  adaptHuff->decTable = nullptr;
}


// ========================================================================
// ?AdaptiveHuffmanDiscriminant@@YAXPAUhdpAdaptiveHuffman_t@@@Z
// EA  : 0x828F91E8
// RVA : 0x008F91E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdphuffman.cpp
// ========================================================================

void __fastcall AdaptiveHuffmanDiscriminant(hdpAdaptiveHuffman_t *adaptHuff)
{
  int numSymbols; // r9
  int discriminant; // r8
  int discriminant1; // r6
  int tableIndex; // r11
  int v5; // r29
  int v6; // r5
  char v7; // r7
  int v8; // r7
  int v9; // r6
  int v10; // r5
  const __int16 *v11; // r30
  int v12; // r7
  const int *v13; // r4
  const int *v14; // r6
  int v15; // r31
  const int *v16; // r10

  numSymbols = adaptHuff->numSymbols;
  discriminant = adaptHuff->discriminant;
  discriminant1 = adaptHuff->discriminant1;
  tableIndex = adaptHuff->tableIndex;
  if ( adaptHuff->isInitialized == 0 )
  {
    discriminant = 0;
    adaptHuff->isInitialized = 1;
    discriminant1 = 0;
    tableIndex = gSecondDisc[numSymbols];
  }
  v5 = numSymbols;
  v6 = discriminant;
  if ( gSecondDisc[numSymbols] != 0 )
    v6 = discriminant1;
  v7 = 0;
  if ( discriminant >= adaptHuff->lowerBound )
  {
    if ( v6 <= adaptHuff->upperBound )
      goto LABEL_10;
    ++tableIndex;
  }
  else
  {
    --tableIndex;
  }
  v7 = 1;
LABEL_10:
  if ( v7 != 0 )
  {
    discriminant = 0;
    discriminant1 = 0;
  }
  else
  {
    if ( discriminant >= -64 )
    {
      if ( discriminant > 64 )
        discriminant = 64;
    }
    else
    {
      discriminant = -64;
    }
    if ( discriminant1 >= -64 )
    {
      if ( discriminant1 > 64 )
        discriminant1 = 64;
    }
    else
    {
      discriminant1 = -64;
    }
  }
  adaptHuff->discriminant = discriminant;
  adaptHuff->discriminant1 = discriminant1;
  v8 = 0x80000000;
  adaptHuff->tableIndex = tableIndex;
  if ( tableIndex != 0 )
    v8 = -8;
  adaptHuff->lowerBound = v8;
  v9 = 0x40000000;
  if ( tableIndex != gMaxTables[v5] - 1 )
    v9 = 8;
  adaptHuff->upperBound = v9;
  if ( (unsigned int)(numSymbols - 4) <= 8 )
  {
    switch ( numSymbols )
    {
      case 5:
        adaptHuff->deltaTable1 = nullptr;
        adaptHuff->deltaTable = g5DeltaTable;
        adaptHuff->decTable = g5HuffLookupTable[tableIndex];
        adaptHuff->encTable = &g5CodeTable[11 * tableIndex];
        return;
      case 6:
        v10 = 13 * tableIndex;
        v11 = g6HuffLookupTable[0];
        v12 = 6 * (((_cntlzw(tableIndex) & 0x20) != 0) + tableIndex - 1);
        v13 = g6CodeTable;
        v14 = g6DeltaTable;
        v15 = 44 * tableIndex;
        v16 = g6DeltaTable;
LABEL_40:
        adaptHuff->encTable = &v13[v10];
        adaptHuff->deltaTable = &v14[v12];
        adaptHuff->decTable = &v11[v15];
        adaptHuff->deltaTable1 = &v16[(tableIndex - ((_cntlzw(gMaxTables[v5] - (tableIndex + 1)) & 0x20) != 0))
                                    * numSymbols];
        return;
      case 7:
        adaptHuff->deltaTable1 = nullptr;
        adaptHuff->deltaTable = g7DeltaTable;
        adaptHuff->decTable = g7HuffLookupTable[tableIndex];
        adaptHuff->encTable = &g7CodeTable[15 * tableIndex];
        return;
      case 8:
        adaptHuff->deltaTable1 = nullptr;
        adaptHuff->decTable = g8HuffLookupTable[0];
        adaptHuff->deltaTable = g8DeltaTable;
        adaptHuff->encTable = &g8CodeTable[17 * tableIndex];
        return;
      case 9:
        adaptHuff->deltaTable1 = nullptr;
        adaptHuff->deltaTable = g9DeltaTable;
        adaptHuff->decTable = g9HuffLookupTable[tableIndex];
        adaptHuff->encTable = &g9CodeTable[19 * tableIndex];
        return;
      default:
        break;
    }
    if ( numSymbols != 10 && numSymbols != 11 )
    {
      if ( numSymbols == 4 )
      {
        adaptHuff->decTable = g4HuffLookupTable;
        adaptHuff->deltaTable = nullptr;
        adaptHuff->encTable = g4CodeTable;
        adaptHuff->deltaTable1 = nullptr;
        return;
      }
      v10 = (2 * numSymbols + 1) * tableIndex;
      v11 = g12HuffLookupTable[0];
      v12 = (((_cntlzw(tableIndex) & 0x20) != 0) + tableIndex - 1) * numSymbols;
      v13 = g12CodeTable;
      v14 = g12DeltaTable;
      v15 = 56 * tableIndex;
      v16 = g12DeltaTable;
      goto LABEL_40;
    }
  }
}

