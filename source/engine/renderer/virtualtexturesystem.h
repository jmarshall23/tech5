#pragma once

#include "virtualtexture.h"
#include "jobs/feedbackanalysis/feedbackanalysis.h"
#include "jobs/pageupdate/pageupdate.h"
#include "jobs/transcode/transcode.h"

#include "../../shared/idlib/containers/hashindex.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/metrics/metrics.h"

class idBitBlockAllocator;
class idFile;
class idImage;
class idMaterial;
class idParallelJobList;
class idRenderDestination;
class idVirtualMaterial;

enum vmtrBatch_t : int {
	BATCH_NONE = 0,
	BATCH_NOMIPS = 1,
	BATCH_NOIMAGES = 2
};

struct cachedPageFile_t {
	idFile * file;
	idFile * fileInstalled;
};

struct idPixelPackBuffer {
	int size;
	int offsetInOtherBuffer;
	void * apiObject;
};

struct idPixelUnpackBuffer {
	int size;
	int offsetInOtherBuffer;
	void * apiObject;
};

struct transcodeJobList_t {
	idParallelJobList * parallelJobList;
	int numTranscodeJobs;
	transcodeParms_t * transcodeParms;
	unsigned char * transcodeSourceBuffer;
	idPixelUnpackBuffer transcodePBO;
	pageImagesUpdateParms_t pageUnmapParms;
	pageImagesUpdateParms_t pageImagesUpdateParms;
	bool nextFramePageImageUpload;
};

class alignas( 8 ) idVirtualTextureSystem {
public:
	idVirtualTextureSystem();
	~idVirtualTextureSystem();
	void Init();
	void Shutdown();
	bool CreatePhysicalImages( bool vmtr = true, bool unique = true,
		bool diffuseOnly = true, bool diffuseOnly2 = true );
	void EmptyCache( bool force = false );
	void FreeLockedPages();
	void FreeDynamicMedia();
	void SetContainerPath( const char * path );
	void AddToReferencedVirtualTextures( const char * path, const char * name );
	void ClearFeedback();
	void AnalyzeFeedback( const void * data, int width, int height, bool forceHighestDetail );
	void PushFeedback( const void * data, int width, int height, bool forceHighestDetail );
	void FinishFeedback( bool lockPages, int maxPages );
	void SyncFeedback();
	bool ReloadVirtualTextures();
	void UpdateFilterParms( bool force );
	void LockPhysicalPages( idVirtualTexture ** textures, int numTextures, int numPages );
	idVirtualTexture * VirtualTextureForMaterial( const idMaterial * material );
	idVirtualMaterial * VirtualMaterialForMaterial( const idMaterial * material );
	void SetupVirtualMaterial( idVirtualMaterial * material );
	void SetupLoadedVirtualMaterials();
	void ReadVmtrFile();
	idFile * OpenCachedPagesFile( const char * path );
	idFile * OpenInstalledCachedPagesFile( const char * path );
	void CloseCachedPagesFile( idFile * file );
	idPhysicalPages * GetPhysicalPagesPool( physicalPagesPool_t pool );
	void RegisterSource( pageSource_t source, idVirtualTexture * texture );

	char vmtrPath[256];
	char vmtrName[256];
	idList< idVirtualMaterial *, 5 > vmtrs;
	idHashIndex vmtrHash;
	idVirtualTexture vts[16];
	idVirtualTexture * vmtrMega;
	idVirtualTexture * vtPtrs[16];
	idList< cachedPageFile_t, 5 > cachedPagesFiles;
	int numReferencedVirtualTextures;
	char referencedVTPath[100][256];
	char referencedVTName[100][32];
	idPhysicalPages physicalPagesPool[4];
	bool mapHasSpecularPages;
	bool mapHasDiffuseOnlyPages;
	bool mapHasDiffuseOnly2Pages;
	char containerPath[256];
	void * feedbackBuffer;
	int feedbackBufferPitch;
	idPixelPackBuffer * feedbackBufferObject;
	idRenderDestination * renderDestFeedback[3];
	idImage * feedbackVisualize;
	idImage * feedbackStreaming;
	float mipLevelMSE;
	int feedbackFrameNum;
	bool flushNextFeedback;
	int pageUploadCount;
	int pageTranscodeCount;
	int emptyCacheTime;
	vmtrBatch_t vmtrBatchBuild;
	idBitBlockAllocator * bitBlock;
	analyzeParms_t analyzeParms;
	virtualTextureInfo_t * vtInfo;
	unsigned int currentPageIndices;
	pageIndices_t * pageIndices[2];
	unsigned char * explicitPages[2];
	int numExplicitPages[2];
	idParallelJobList * analyzeJobList;
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

extern idVirtualTextureSystem virtualTextureSystem;
