#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\virtualtexture.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13641; PDB kind: class.
class __declspec(align(8)) idVirtualTexture
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13642.
  virtual ~idVirtualTexture();
  virtual void FreeData();

  pageFileHeader_t header;
  idStrStatic<256> pageFilePath;
  idStrStatic<256> baseName;
  pageSource_t pageSource;
  int layoutVersion;
  idFile *pageFile;
  idFile *pageFileInstalled;
  int minMipLevelInstalled;
  int VIRTUAL_PAGES_WIDE_LOG2;
  int VIRTUAL_TEXELS_WIDE;
  int VIRTUAL_MAPPING_PAGES_WIDE;
  unsigned __int16 mipLevelPagesWide[16];
  idStrStatic<128> mapName;
  idSeenBits dirtyPages;
  idPhysicalPages *physicalPages;
  texturePage_t *rootTexturePage;
  idImage *pageTableImage;
  bool enlargedPageTableAllocationFailed;
  bool isDirectMapped;
  int levelResidency[12];
  idSysMutex headerMutex;
  bool pageFileIsLocal;
  bool skipFlush;
  pageCompression_t forcedPageCompression;
};

// IDA Local Type ordinal 18488; PDB kind: struct.
const struct virtualTextureInfo_t
{
  unsigned int numLevels;
  unsigned int baseLevel;
  unsigned int pagesWide;
  unsigned __int16 physicalPagesPool;
  unsigned __int16 priorityBias;
};
