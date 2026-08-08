
// ========================================================================
// ?WriteToBinary@idAAS2DebugAreaModelGenerator@@SA_NPBD0IABVidAAS2DebugAreaModelData@@@Z
// EA  : 0x825AF860
// RVA : 0x005AF860
// PDB : w:\tech5\engine\aas2file\aas2debugareamodelgenerator.cpp
// ========================================================================

int __fastcall idAAS2DebugAreaModelGenerator::WriteToBinary(
        const char *uniqueIdName,
        const char *fileName,
        unsigned int sourceTimestamp,
        const idAAS2DebugAreaModelData *data)
{
  unsigned __int64 v4; // r27
  int v9; // r23
  int v10; // r24
  unsigned int (__fastcall *Write)(struct idFile_Memory *, const void *, unsigned int); // ctr
  int v12; // r29
  int v13; // r28
  int v14; // r30
  char *filePtr; // r30
  unsigned int v16; // r3
  int v18; // [sp+50h] [-210h] BYREF
  int v19; // [sp+54h] [-20Ch] BYREF
  int num; // [sp+58h] [-208h] BYREF
  idResource::resourceHeader_t v21; // [sp+60h] [-200h] BYREF
  idFile_Memory v22; // [sp+A0h] [-1C0h] BYREF

  idFile_Memory::idFile_Memory(this: &v22);
  num = data->vertices.num;
  v22.Write(this: &v22, a2: &num, a3: 4u);
  v22.Write(this: &v22, a2: data->vertices.list, a3: 12 * num);
  v19 = data->areas.num;
  v22.Write(this: &v22, a2: &v19, a3: 4u);
  LODWORD(v4) = 0;
  v9 = 0;
  if ( v19 > 0 )
  {
    v10 = 0;
    do
    {
      HIDWORD(v4) = &data->areas.list[v10];
      Write = v22.Write;
      v18 = *(_DWORD *)(HIDWORD(v4) + 4);
      Write(this: &v22, a2: &v18, a3: 4u);
      v12 = 0;
      if ( v18 > 0 )
      {
        v13 = 0;
        do
        {
          v14 = v13 + *(_DWORD *)HIDWORD(v4);
          v22.Write(this: &v22, a2: (const void *)v14, a3: 4u);
          v22.Write(this: &v22, a2: (const void *)(v14 + 4), a3: 4u);
          v22.Write(this: &v22, a2: (const void *)(v14 + 8), a3: 4u);
          ++v12;
          v13 += 12;
        }
        while ( v12 < v18 );
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v19 );
  }
  v21.sourceTimestamp = sourceTimestamp;
  v21.sourceFileNameLen = 0;
  v21.uniqueIdNameLen = 0;
  filePtr = v22.filePtr;
  v21.headerVersionHi = 1;
  v21.headerVersionLo = 1;
  v21.resourceId = 1094800196;
  v21.versionHi = idAAS2DebugAreaModelData::BINARY_VERSION_HI;
  v21.versionLo = idAAS2DebugAreaModelData::BINARY_VERSION_LO;
  v21.platform = 4;
  v21.pad[0] = 0;
  v21.pad[1] = 0;
  v21.pad[2] = 0;
  v21.uniqueId = v4;
  v21.hash = v4;
  v21.dataOffset = 0x100000004LL;
  v21.totalSize = v4;
  v16 = (unsigned __int64)idFile_Memory::Length(this: &v22) >> 32;
  if ( idResource::WriteBinary(
         uniqueIdName,
         sourceFileName: fileName,
         fileExtension: idAAS2DebugAreaModelData::BINARY_FILE_EXTENSION,
         header: &v21,
         data: filePtr,
         dataLen: v16) )
  {
    idFile_Memory::~idFile_Memory(this: &v22);
    return 1;
  }
  else
  {
    idFile_Memory::~idFile_Memory(this: &v22);
    return 0;
  }
}


// ========================================================================
// __unwind$224652
// EA  : 0x825AFA94
// RVA : 0x005AFA94
// PDB : w:\tech5\engine\aas2file\aas2debugareamodelgenerator.cpp
// ========================================================================

void _unwind_224652()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 608 + 160));
}

