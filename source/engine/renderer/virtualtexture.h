#pragma once

#include "jobs/feedbackanalysis/feedbackanalysis.h"
#include "jobs/pagesort/pagesort.h"
#include "jobs/transcode/pagecompression.h"
#include "seenbits.h"

#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/sys/sys_threading.h"
#include "../../shared/idlib/text/strstatic.h"

#include <cstdint>

class idFile;
class idImage;
class idDeclRenderParm;
template< class type_t > class idCodeResource;
struct pageImagesUpdate_t;
struct pageImagesUpdateParms_t;

#ifndef TECH5_PAGE_SOURCE_T_DEFINED
#define TECH5_PAGE_SOURCE_T_DEFINED
enum pageSource_t : std::int32_t {
	PAGESOURCE_INVALID = 0,
	PAGESOURCE_VMTR = 1,
	PAGESOURCE_UNIQUE = 2,
	PAGESOURCE_ALLOC2 = 3,
	PAGESOURCE_ALLOC3 = 4,
	PAGESOURCE_ALLOC4 = 5,
	PAGESOURCE_ALLOC5 = 6,
	PAGESOURCE_ALLOC6 = 7,
	PAGESOURCE_ALLOC7 = 8,
	PAGESOURCE_ALLOC8 = 9,
	PAGESOURCE_ALLOC9 = 10,
	PAGESOURCE_ALLOC10 = 11,
	PAGESOURCE_ALLOC11 = 12,
	PAGESOURCE_ALLOC12 = 13,
	PAGESOURCE_ALLOC13 = 14,
	PAGESOURCE_ALLOC14 = 15,
	PAGESOURCE_TOTAL = 16
};
#endif

enum pageQuadrant_t : std::int32_t {
	QUADRANT_LOWER_LEFT = 0,
	QUADRANT_LOWER_RIGHT = 1,
	QUADRANT_UPPER_LEFT = 2,
	QUADRANT_UPPER_RIGHT = 3
};

struct pageHeader_t {
	int magic;
	pageCompression_t pageCompression;
	std::uint32_t finerDiskOffset[4];
	std::uint16_t finerDiskLength[4];
	std::uint16_t x;
	std::uint16_t y;
	std::uint16_t level;
	std::uint16_t reserved;
};

struct pageFileHeader_t {
	int magic;
	int pagesWide;
	int installedMipAndOffset;
	std::int16_t numLevels;
	std::int16_t layoutVersion;
	int totalPages;
	int diskOffsetScale;
	std::int64_t totalFileSize;
	pageHeader_t subRoot;
};

struct texturePage_t {
	bool mapped;
	bool locked;
	std::uint8_t maxLevel;
	std::uint8_t pageLevel;
	std::uint16_t pageX;
	std::uint16_t pageY;
	std::uint16_t physicalPageNum;
	int transcodeFrameNum;
	pageSource_t pageSource;
	pageCompression_t pageCompression;
	pageQuadrant_t quadrant;
	texturePage_t * coarser;
	texturePage_t * finer[4];
	std::uint32_t finerDiskOffset[4];
	std::uint16_t finerDiskLength[4];
};

class idPhysicalPageHash {
public:
	struct pageHashEntry_t {
		std::uint32_t pageID;
		std::uint16_t mapped;
		std::uint16_t next;
	};

	idPhysicalPageHash();
	~idPhysicalPageHash();
	void Init( int hashSize, int indexSize );
	void Clear();
	int Find( std::uint32_t pageID ) const;
	void InsertPage( const texturePage_t * page, int index );
	void RemovePage( texturePage_t * page );
	void HashStats( int & total, int & empty, int & minChain, int & maxChain,
		int & averageChain, int & duplicates ) const;

	unsigned int hashMask;
	std::uint16_t * pageHashTable;
	pageHashEntry_t * pageHashIndex;
	int pageHashIndexSize;
};

class idPhysicalPageList {
public:
	idPhysicalPageList();
	~idPhysicalPageList();
	void Init( int size );
	bool Add( std::int64_t physicalPageNum );
	bool Remove( int physicalPageNum );
	bool PopFront( std::int64_t & physicalPageNum );
	int Num() const;
	void Sort( int frameNum, const int * pagePriority, const int * pageFrameNum,
		void * parallelJobList = nullptr, int wait = 1 );

	int firstPageIndex;
	int lastPageIndex;
	int indexMask;
	std::int64_t * physicalPageNums;
	volatile int sortDone;
	pageSortParms_t * sortParms;
};

class idVirtualTexture;

class idPhysicalPages {
public:
	idPhysicalPages();
	~idPhysicalPages();
	bool CreatePhysicalImages( physicalPagesPool_t pool, const char * name,
		int pageImageWidth, int pageImageHeight,
		const idCodeResource< idDeclRenderParm > * filterParms = nullptr );
	void FreeData();
	void LockPage( texturePage_t * page );
	int GetNumResidentPagesForSource( pageSource_t source ) const;
	int GetNumLockedPagesForSource( pageSource_t source ) const;
	bool ValidateCache() const;
	texturePage_t * AllocPage( idVirtualTexture * vt, texturePage_t * coarser,
		pageQuadrant_t quadrant, pageImagesUpdateParms_t * deferredUnmap );
	void FreePage( idVirtualTexture * vt, texturePage_t * page,
		pageImagesUpdateParms_t * deferredUnmap );
	void FreePageTree_r( idVirtualTexture * vt, texturePage_t * page,
		pageImagesUpdateParms_t * deferredUnmap );
	void CreatePageImagesUpdate( const idVirtualTexture * vt, const texturePage_t * physicalPage,
		texturePage_t * virtualPage, const void * pageDataPBO, const unsigned char * pageData,
		pageImagesUpdate_t & update ) const;
	void GetDirectMappedPhysicalPagePointers( int physicalPageNum,
		unsigned char * targetImage[3], int targetPitch[3] ) const;
	void UpdateFilterParms( bool force );

	physicalPagesPool_t physicalPagesPool;
	texturePage_t * pages;
	int * pagePriority;
	int * pageFrameNum;
	idPhysicalPageHash pageHash;
	idPhysicalPageList freePageList;
	idPhysicalPageList unlockedPageList;
	int numLockedPages;
	bool pageImageCompressed;
	bool isDirectMapped;
	int PHYSICAL_TEXELS_WIDE;
	int PHYSICAL_TEXELS_HIGH;
	int PHYSICAL_PAGES_WIDE;
	int PHYSICAL_PAGES_HIGH;
	int NUM_PHYSICAL_PAGES;
	idImage * physicalPagesImage0;
	idImage * physicalPagesImage1;
	idImage * physicalPagesImage2;
	idImage * physicalMappingsImage0;
	int feedbackNumPages;
	float feedbackDynamicLodBias;
	float oldFeedbackDynamicLodBias;
	const idCodeResource< idDeclRenderParm > * rpPhysicalFilterParms;
};

class alignas( 8 ) idVirtualTexture {
public:
	idVirtualTexture();
	virtual ~idVirtualTexture();
	virtual void FreeData();

	physicalPagesPool_t GetPhysicalPagesPool() const;
	void GetToBeLockedPhysicalPages( int numTexturePages, pageIndices_t * pageIndices ) const;
	void EmptyCache();
	idVec4 GetFeedbackVec4() const;
	void Print() const;
	pageCompression_t GetNewDiskPageCompression() const;
	void ReleaseSource();
	bool ValidatePageTable() const;
	bool SetSource( const char * baseName, const char * pageFilePath, physicalPagesPool_t pool );

	pageFileHeader_t header;
	idStrStatic< 256 > pageFilePath;
	idStrStatic< 256 > baseName;
	pageSource_t pageSource;
	int layoutVersion;
	idFile * pageFile;
	idFile * pageFileInstalled;
	int minMipLevelInstalled;
	int VIRTUAL_PAGES_WIDE_LOG2;
	int VIRTUAL_TEXELS_WIDE;
	int VIRTUAL_MAPPING_PAGES_WIDE;
	std::uint16_t mipLevelPagesWide[16];
	idStrStatic< 128 > mapName;
	idSeenBits dirtyPages;
	idPhysicalPages * physicalPages;
	texturePage_t * rootTexturePage;
	idImage * pageTableImage;
	bool enlargedPageTableAllocationFailed;
	bool isDirectMapped;
	int levelResidency[12];
	idSysMutex headerMutex;
	bool pageFileIsLocal;
	bool skipFlush;
	pageCompression_t forcedPageCompression;
};

pageCompression_t PageCompressionForString( const char * string );
void SwapPageHeader( pageHeader_t & header );
void SwapPageFileHeader( pageFileHeader_t & header );

static_assert( sizeof( pageHeader_t ) == 40, "Recovered page header size changed" );
static_assert( sizeof( pageFileHeader_t ) == 72, "Recovered page file header size changed" );
