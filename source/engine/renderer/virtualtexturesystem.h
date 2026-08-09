#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\virtualtexturesystem.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18496; PDB kind: class.
class __declspec(align(8)) idVirtualTextureSystem
{
public:
  char vmtrPath[256];
  char vmtrName[256];
  idList<idVirtualMaterial *,5> vmtrs;
  idHashIndex vmtrHash;
  idVirtualTexture vts[16];
  idVirtualTexture *vmtrMega;
  idVirtualTexture *vtPtrs[16];
  idList<cachedPageFile_t,5> cachedPagesFiles;
  int numReferencedVirtualTextures;
  char referencedVTPath[100][256];
  char referencedVTName[100][32];
  idPhysicalPages physicalPagesPool[4];
  bool mapHasSpecularPages;
  bool mapHasDiffuseOnlyPages;
  bool mapHasDiffuseOnly2Pages;
  char containerPath[256];
  void *feedbackBuffer;
  int feedbackBufferPitch;
  idPixelPackBuffer *feedbackBufferObject;
  idRenderDestination *renderDestFeedback[3];
  idImage *feedbackVisualize;
  idImage *feedbackStreaming;
  float mipLevelMSE;
  int feedbackFrameNum;
  bool flushNextFeedback;
  int pageUploadCount;
  int pageTranscodeCount;
  int emptyCacheTime;
  vmtrBatch_t vmtrBatchBuild;
  idBitBlockAllocator *bitBlock;
  analyzeParms_t analyzeParms;
  virtualTextureInfo_t *vtInfo;
  unsigned int currentPageIndices;
  pageIndices_t *pageIndices[2];
  unsigned __int8 *explicitPages[2];
  int numExplicitPages[2];
  idParallelJobList *analyzeJobList;
  transcodeJobList_t transcodeJobList[2];
  int currentTranscodeJobList;
  volatile bool cancelToTerminate;
  idSysMutex metricMutex;
  idGaugeMetric vmtrTotalPagesMetric;
  idGaugeMetric vmtrBiasMetric;
  idGaugeMetric specTotalPagesMetric;
  idGaugeMetric specBiasMetric;
  idGaugeMetric diffuseTotalPagesMetric;
  idGaugeMetric diffuseBiasMetric;
};
