#include "virtualtexturesystem.h"

#include "declmaterial.h"
#include "image.h"
#include "imagemanager.h"
#include "virtualmaterialatlas.h"

#include "../../shared/idlib/filesystem/filesystem.h"
#include "../../shared/idlib/filesystem/file.h"
#include "../../shared/idlib/packing/bitblockallocator.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>

idVirtualTextureSystem virtualTextureSystem;

namespace {
	static const int PAGE_DATA_MAGIC = -893391612;
	static const std::uint16_t HASH_EMPTY = 0xFFFFu;

	unsigned int HashPageID( const unsigned int pageID ) {
		unsigned int hash = 1664525u * pageID + 1013904223u;
		hash ^= hash >> 11;
		hash ^= hash >> 11;
		return hash;
	}

	bool PointerInPagePool( const idPhysicalPages & pool, const texturePage_t * page ) {
		return pool.pages != nullptr && page >= pool.pages && page < pool.pages + pool.NUM_PHYSICAL_PAGES;
	}

	std::uint16_t PhysicalPageTableSpot( const idVirtualTexture & texture,
			const idPhysicalPages & pool, const texturePage_t & page ) {
		const int physicalX = page.physicalPageNum % (std::max)( pool.PHYSICAL_PAGES_WIDE, 1 );
		const int physicalY = page.physicalPageNum / (std::max)( pool.PHYSICAL_PAGES_WIDE, 1 );
		const int x5 = (std::min)( 31, physicalX * 32 / (std::max)( pool.PHYSICAL_PAGES_WIDE, 1 ) );
		const int y5 = (std::min)( 31, physicalY * 32 / (std::max)( pool.PHYSICAL_PAGES_HIGH, 1 ) );
		int logPages = 0;
		while ( ( 1 << logPages ) < texture.header.pagesWide && logPages < 15 ) ++logPages;
		const int effectiveLevel = (std::max)( 0, (std::min)( 63, logPages - page.pageLevel ) );
		return static_cast< std::uint16_t >( ( x5 << 11 ) | ( effectiveLevel << 5 ) | y5 );
	}

	void UploadPageTableMapping( idVirtualTexture & texture, const idPhysicalPages & pool,
			const texturePage_t & page ) {
		if ( texture.pageTableImage == nullptr ) return;
		const std::uint16_t spot = PhysicalPageTableSpot( texture, pool, page );
		for ( int mip = 0; mip <= page.pageLevel && mip < texture.pageTableImage->opts.numLevels; ++mip ) {
			const int shift = page.pageLevel - mip;
			const int size = 1 << shift;
			std::vector< std::uint16_t > pixels( static_cast< std::size_t >( size ) * size, spot );
			texture.pageTableImage->SubImageUpload( mip, page.pageX << shift,
				page.pageY << shift, 0, size, size, pixels.data(), size * 2 );
		}
	}

	bool ReadAndUploadPage( idVirtualTexture & texture, idPhysicalPages & pool,
			texturePage_t & page, const texturePage_t * parent, const pageQuadrant_t quadrant ) {
		if ( texture.pageFile == nullptr || parent == nullptr ) return false;
		const int q = static_cast< int >( quadrant ) & 3;
		const int blockBytes = parent->finerDiskLength[q] * texture.header.diskOffsetScale;
		const std::int64_t blockOffset = static_cast< std::int64_t >( parent->finerDiskOffset[q] ) *
			texture.header.diskOffsetScale;
		if ( blockBytes < static_cast< int >( sizeof( pageHeader_t ) ) || blockOffset < 0 ) return false;
		std::vector< unsigned char > block( blockBytes );
		if ( texture.pageFile->ReadOfs( blockOffset, block.data(), blockBytes ) !=
			static_cast< unsigned int >( blockBytes ) ) return false;
		pageHeader_t diskHeader;
		std::memcpy( &diskHeader, block.data(), sizeof( diskHeader ) );
		if ( diskHeader.magic != PAGE_DATA_MAGIC ) {
			pageHeader_t swapped = diskHeader;
			SwapPageHeader( swapped );
			if ( swapped.magic == PAGE_DATA_MAGIC ) diskHeader = swapped;
		}
		if ( diskHeader.pageCompression <= 0 || diskHeader.pageCompression >= COMP_MAX_COMPRESSIONS ) return false;
		page.pageCompression = diskHeader.pageCompression;
		std::memcpy( page.finerDiskOffset, diskHeader.finerDiskOffset, sizeof( page.finerDiskOffset ) );
		std::memcpy( page.finerDiskLength, diskHeader.finerDiskLength, sizeof( page.finerDiskLength ) );
		const bool photo = diskHeader.pageCompression == COMP_DCT ||
			diskHeader.pageCompression == COMP_HDP || diskHeader.pageCompression == COMP_JXR;
		const int codecHeaderBytes = photo ? 16 : 0;
		const int totalHeaderBytes = static_cast< int >( sizeof( pageHeader_t ) ) + codecHeaderBytes;
		if ( totalHeaderBytes > blockBytes ) return false;
		std::vector< unsigned char > specular( 8192 ), diffuse( 16384 ), normal( 16384 );
		transcodeParms_t parms = {};
		parms.imageFlags = pool.physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY ||
			pool.physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2 ?
			TRANSCODE_IMAGE_DIFFUSE : TRANSCODE_IMAGE_SPECULAR | TRANSCODE_IMAGE_DIFFUSE | TRANSCODE_IMAGE_NORMAL;
		parms.layoutVersion = texture.layoutVersion;
		parms.numLevels = texture.header.numLevels;
		parms.pageSource = texture.pageSource;
		parms.pageLevel = page.pageLevel;
		parms.pageX = page.pageX;
		parms.pageY = page.pageY;
		parms.physicalPageNum = page.physicalPageNum;
		parms.inPageCompression = diskHeader.pageCompression;
		parms.outPageCompression = COMP_DXT;
		parms.inPageDataLength = blockBytes - totalHeaderBytes;
		parms.outPageDataLength = static_cast< int >( specular.size() + diffuse.size() + normal.size() );
		parms.pageHeaderSize = totalHeaderBytes;
		parms.diskOffsetScale = texture.header.diskOffsetScale;
		parms.tempSize = 0x30000;
		parms.targetBytePitch[0] = 256; parms.targetBytePitch[1] = 512; parms.targetBytePitch[2] = 512;
		parms.inPageHeader = photo ? block.data() + sizeof( pageHeader_t ) : nullptr;
		parms.inPageData = block.data() + totalHeaderBytes;
		parms.targetImage[0] = specular.data(); parms.targetImage[1] = diffuse.data(); parms.targetImage[2] = normal.data();
		parms.TranscodePageFunc = reinterpret_cast< void ( __fastcall * )( const transcodeParms_t * ) >( TranscodePage );
		TranscodePage( &parms );
		const int destX = page.physicalPageNum % pool.PHYSICAL_PAGES_WIDE * 128;
		const int destY = page.physicalPageNum / pool.PHYSICAL_PAGES_WIDE * 128;
		if ( pool.physicalPagesImage0 != nullptr && ( parms.imageFlags & TRANSCODE_IMAGE_SPECULAR ) != 0 )
			pool.physicalPagesImage0->SubImageUpload( 0, destX, destY, 0, 128, 128, specular.data(), 256 );
		if ( pool.physicalPagesImage1 != nullptr )
			pool.physicalPagesImage1->SubImageUpload( 0, destX, destY, 0, 128, 128, diffuse.data(), 512 );
		if ( pool.physicalPagesImage2 != nullptr && ( parms.imageFlags & TRANSCODE_IMAGE_NORMAL ) != 0 )
			pool.physicalPagesImage2->SubImageUpload( 0, destX, destY, 0, 128, 128, normal.data(), 512 );
		return true;
	}
}

idPhysicalPageHash::idPhysicalPageHash() : hashMask( 0 ), pageHashTable( nullptr ),
	pageHashIndex( nullptr ), pageHashIndexSize( 0 ) {}

idPhysicalPageHash::~idPhysicalPageHash() { delete[] pageHashTable; delete[] pageHashIndex; }

void idPhysicalPageHash::Init( int hashSize, const int indexSize ) {
	delete[] pageHashTable; delete[] pageHashIndex;
	int size = 1; while ( size < (std::max)( hashSize, 1 ) ) size <<= 1;
	hashMask = size - 1;
	pageHashIndexSize = (std::max)( indexSize, 0 );
	pageHashTable = new std::uint16_t[size];
	pageHashIndex = pageHashIndexSize > 0 ? new pageHashEntry_t[pageHashIndexSize] : nullptr;
	Clear();
}

void idPhysicalPageHash::Clear() {
	if ( pageHashTable != nullptr ) std::fill( pageHashTable, pageHashTable + hashMask + 1, HASH_EMPTY );
	for ( int i = 0; i < pageHashIndexSize; ++i ) {
		pageHashIndex[i].pageID = 0; pageHashIndex[i].mapped = 0; pageHashIndex[i].next = HASH_EMPTY;
	}
}

int idPhysicalPageHash::Find( const std::uint32_t pageID ) const {
	if ( pageHashTable == nullptr || pageHashIndex == nullptr ) return -1;
	std::uint16_t index = pageHashTable[HashPageID( pageID ) & hashMask];
	while ( index != HASH_EMPTY && index < pageHashIndexSize ) {
		if ( pageHashIndex[index].mapped != 0 && pageHashIndex[index].pageID == pageID ) return index;
		index = pageHashIndex[index].next;
	}
	return -1;
}

void idPhysicalPageHash::InsertPage( const texturePage_t * page, const int index ) {
	if ( page == nullptr || index < 0 || index >= pageHashIndexSize || pageHashTable == nullptr ) return;
	const std::uint32_t id = PackVirtualPageID( page->pageSource, page->pageLevel, page->pageX, page->pageY );
	const unsigned int bucket = HashPageID( id ) & hashMask;
	pageHashIndex[index].pageID = id; pageHashIndex[index].mapped = 1;
	pageHashIndex[index].next = pageHashTable[bucket];
	pageHashTable[bucket] = static_cast< std::uint16_t >( index );
}

void idPhysicalPageHash::RemovePage( texturePage_t * page ) {
	if ( page == nullptr || pageHashTable == nullptr || pageHashIndex == nullptr ) return;
	const std::uint32_t id = PackVirtualPageID( page->pageSource, page->pageLevel, page->pageX, page->pageY );
	const unsigned int bucket = HashPageID( id ) & hashMask;
	std::uint16_t index = pageHashTable[bucket], previous = HASH_EMPTY;
	while ( index != HASH_EMPTY && index < pageHashIndexSize ) {
		if ( pageHashIndex[index].mapped != 0 && pageHashIndex[index].pageID == id ) {
			if ( previous == HASH_EMPTY ) pageHashTable[bucket] = pageHashIndex[index].next;
			else pageHashIndex[previous].next = pageHashIndex[index].next;
			pageHashIndex[index].mapped = 0; pageHashIndex[index].next = HASH_EMPTY; return;
		}
		previous = index; index = pageHashIndex[index].next;
	}
}

void idPhysicalPageHash::HashStats( int & total, int & empty, int & minChain,
		int & maxChain, int & averageChain, int & duplicates ) const {
	total = empty = maxChain = duplicates = 0; minChain = (std::numeric_limits< int >::max)();
	if ( pageHashTable == nullptr ) { minChain = averageChain = 0; return; }
	for ( unsigned int bucket = 0; bucket <= hashMask; ++bucket ) {
		int chain = 0;
		for ( std::uint16_t i = pageHashTable[bucket]; i != HASH_EMPTY && i < pageHashIndexSize; i = pageHashIndex[i].next ) ++chain;
		if ( chain == 0 ) ++empty; else minChain = (std::min)( minChain, chain );
		maxChain = (std::max)( maxChain, chain ); total += chain; if ( chain > 1 ) duplicates += chain - 1;
	}
	if ( minChain == (std::numeric_limits< int >::max)() ) minChain = 0;
	averageChain = static_cast< int >( hashMask + 1 ) > empty ? total / ( static_cast< int >( hashMask + 1 ) - empty ) : 0;
}

idPhysicalPageList::idPhysicalPageList() : firstPageIndex( 0 ), lastPageIndex( -1 ),
	indexMask( 0 ), physicalPageNums( nullptr ), sortDone( 1 ), sortParms( nullptr ) {}
idPhysicalPageList::~idPhysicalPageList() { delete[] physicalPageNums; delete sortParms; }

void idPhysicalPageList::Init( const int requestedSize ) {
	delete[] physicalPageNums;
	int size = 1; while ( size < (std::max)( requestedSize, 1 ) ) size <<= 1;
	indexMask = size - 1; physicalPageNums = new std::int64_t[size];
	std::fill( physicalPageNums, physicalPageNums + size, -1 );
	firstPageIndex = 0; lastPageIndex = -1; sortDone = 1;
}

int idPhysicalPageList::Num() const { return lastPageIndex < firstPageIndex ? 0 : lastPageIndex - firstPageIndex + 1; }

bool idPhysicalPageList::Add( const std::int64_t physicalPageNum ) {
	if ( physicalPageNums == nullptr || Num() >= indexMask + 1 ) return false;
	physicalPageNums[++lastPageIndex & indexMask] = physicalPageNum; return true;
}

bool idPhysicalPageList::PopFront( std::int64_t & physicalPageNum ) {
	if ( Num() <= 0 ) return false;
	physicalPageNum = physicalPageNums[firstPageIndex++ & indexMask];
	if ( firstPageIndex > lastPageIndex ) { firstPageIndex = 0; lastPageIndex = -1; }
	return true;
}

bool idPhysicalPageList::Remove( const int physicalPageNum ) {
	const int count = Num();
	for ( int i = 0; i < count; ++i ) {
		if ( static_cast< int >( physicalPageNums[( firstPageIndex + i ) & indexMask] ) != physicalPageNum ) continue;
		for ( int move = i; move + 1 < count; ++move )
			physicalPageNums[( firstPageIndex + move ) & indexMask] = physicalPageNums[( firstPageIndex + move + 1 ) & indexMask];
		--lastPageIndex; if ( lastPageIndex < firstPageIndex ) { firstPageIndex = 0; lastPageIndex = -1; }
		return true;
	}
	return false;
}

void idPhysicalPageList::Sort( const int frameNum, const int * priorities,
		const int * frameNumbers, void *, int ) {
	const int count = Num(); if ( count <= 1 ) return;
	std::vector< std::int64_t > sorted( count );
	pageSortParms_t parms = { frameNum, priorities, frameNumbers, physicalPageNums,
		&firstPageIndex, &lastPageIndex, indexMask, sorted.data(), &sortDone };
	sortDone = 0; PageSortJob( &parms );
	for ( int i = 0; i < count; ++i ) physicalPageNums[i] = static_cast< std::uint32_t >( sorted[i] );
}

idPhysicalPages::idPhysicalPages() : physicalPagesPool( PHYSICAL_PAGES_POOL_VMTR ),
	pages( nullptr ), pagePriority( nullptr ), pageFrameNum( nullptr ), numLockedPages( 0 ),
	pageImageCompressed( true ), isDirectMapped( false ), PHYSICAL_TEXELS_WIDE( 0 ),
	PHYSICAL_TEXELS_HIGH( 0 ), PHYSICAL_PAGES_WIDE( 0 ), PHYSICAL_PAGES_HIGH( 0 ),
	NUM_PHYSICAL_PAGES( 0 ), physicalPagesImage0( nullptr ), physicalPagesImage1( nullptr ),
	physicalPagesImage2( nullptr ), physicalMappingsImage0( nullptr ), feedbackNumPages( 0 ),
	feedbackDynamicLodBias( 0.0f ), oldFeedbackDynamicLodBias( 0.0f ), rpPhysicalFilterParms( nullptr ) {}

idPhysicalPages::~idPhysicalPages() { FreeData(); }

void idPhysicalPages::FreeData() {
	delete[] pages; pages = nullptr;
	delete[] pagePriority; pagePriority = nullptr;
	delete[] pageFrameNum; pageFrameNum = nullptr;
	if ( physicalPagesImage0 != nullptr ) physicalPagesImage0->PurgeImage();
	if ( physicalPagesImage1 != nullptr ) physicalPagesImage1->PurgeImage();
	if ( physicalPagesImage2 != nullptr ) physicalPagesImage2->PurgeImage();
	if ( physicalMappingsImage0 != nullptr ) physicalMappingsImage0->PurgeImage();
	physicalPagesImage0 = physicalPagesImage1 = physicalPagesImage2 = physicalMappingsImage0 = nullptr;
	PHYSICAL_TEXELS_WIDE = PHYSICAL_TEXELS_HIGH = PHYSICAL_PAGES_WIDE = PHYSICAL_PAGES_HIGH = 0;
	NUM_PHYSICAL_PAGES = numLockedPages = 0;
	pageHash.Clear(); freePageList.Init( 1 ); unlockedPageList.Init( 1 );
}

bool idPhysicalPages::CreatePhysicalImages( const physicalPagesPool_t pool, const char * name,
		const int pageImageWidth, const int pageImageHeight,
		const idCodeResource< idDeclRenderParm > * filterParms ) {
	FreeData();
	if ( pageImageWidth < 128 || pageImageHeight < 128 || pageImageWidth % 128 != 0 ||
		pageImageHeight % 128 != 0 || globalImages == nullptr ) return false;
	physicalPagesPool = pool;
	PHYSICAL_TEXELS_WIDE = pageImageWidth; PHYSICAL_TEXELS_HIGH = pageImageHeight;
	PHYSICAL_PAGES_WIDE = pageImageWidth / 128; PHYSICAL_PAGES_HIGH = pageImageHeight / 128;
	NUM_PHYSICAL_PAGES = PHYSICAL_PAGES_WIDE * PHYSICAL_PAGES_HIGH;
	pages = new texturePage_t[NUM_PHYSICAL_PAGES]();
	pagePriority = new int[NUM_PHYSICAL_PAGES](); pageFrameNum = new int[NUM_PHYSICAL_PAGES]();
	pageHash.Init( 2048, NUM_PHYSICAL_PAGES );
	freePageList.Init( NUM_PHYSICAL_PAGES ); unlockedPageList.Init( NUM_PHYSICAL_PAGES );
	for ( int i = 0; i < NUM_PHYSICAL_PAGES; ++i ) {
		pages[i].physicalPageNum = static_cast< std::uint16_t >( i ); pageFrameNum[i] = 1; freePageList.Add( i );
	}
	pageImageCompressed = true;
	isDirectMapped = false; // D3D9 managed textures replace persistent Xbox CPU aliases.
	idImageOpts opts;
	opts.width = pageImageWidth; opts.height = pageImageHeight; opts.numLevels = 1;
	opts.textureType = TT_2D; opts.filter = TF_LINEAR; opts.repeat = TR_CLAMP; opts.linear = false;
	char imageName[256];
	const bool diffuseOnly = pool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY ||
		pool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2;
	if ( !diffuseOnly ) {
		opts.format = FMT_DXT1; opts.colorFormat = CFM_HQ_DXT1;
		std::snprintf( imageName, sizeof( imageName ), "_physical%sPages0", name != nullptr ? name : "" );
		physicalPagesImage0 = globalImages->ScratchImage( imageName, &opts );
	}
	opts.format = FMT_DXT5; opts.colorFormat = CFM_YCOCGA_DXT5;
	std::snprintf( imageName, sizeof( imageName ), "_physical%sPages1", name != nullptr ? name : "" );
	physicalPagesImage1 = globalImages->ScratchImage( imageName, &opts );
	if ( !diffuseOnly ) {
		opts.format = FMT_DXT5; opts.colorFormat = CFM_HQ_NORMAL_DXT5;
		std::snprintf( imageName, sizeof( imageName ), "_physical%sPages2", name != nullptr ? name : "" );
		physicalPagesImage2 = globalImages->ScratchImage( imageName, &opts );
	}
	idImageOpts mapOpts;
	mapOpts.width = PHYSICAL_PAGES_WIDE; mapOpts.height = PHYSICAL_PAGES_HIGH;
	mapOpts.numLevels = 1; mapOpts.format = FMT_RGBA8; mapOpts.filter = TF_NEAREST;
	mapOpts.repeat = TR_CLAMP; mapOpts.linear = false;
	std::snprintf( imageName, sizeof( imageName ), "_physical%sMappings", name != nullptr ? name : "" );
	physicalMappingsImage0 = globalImages->ScratchImage( imageName, &mapOpts );
	rpPhysicalFilterParms = filterParms;
	return physicalPagesImage1 != nullptr && !physicalPagesImage1->allocationFailed &&
		( diffuseOnly || ( physicalPagesImage0 != nullptr && physicalPagesImage2 != nullptr &&
			!physicalPagesImage0->allocationFailed && !physicalPagesImage2->allocationFailed ) );
}

void idPhysicalPages::LockPage( texturePage_t * page ) {
	if ( page == nullptr || page->locked ) return;
	page->locked = true; unlockedPageList.Remove( page->physicalPageNum ); ++numLockedPages;
}

int idPhysicalPages::GetNumResidentPagesForSource( const pageSource_t source ) const {
	int count = 0; for ( int i = 0; i < NUM_PHYSICAL_PAGES; ++i )
		if ( pages[i].mapped && pages[i].pageSource == source ) ++count;
	return count;
}

int idPhysicalPages::GetNumLockedPagesForSource( const pageSource_t source ) const {
	int count = 0; for ( int i = 0; i < NUM_PHYSICAL_PAGES; ++i )
		if ( pages[i].mapped && pages[i].locked && pages[i].pageSource == source ) ++count;
	return count;
}

bool idPhysicalPages::ValidateCache() const {
	for ( int i = 0; i < NUM_PHYSICAL_PAGES; ++i ) if ( pages[i].mapped ) {
		const std::uint32_t id = PackVirtualPageID( pages[i].pageSource, pages[i].pageLevel,
			pages[i].pageX, pages[i].pageY );
		if ( pageHash.Find( id ) != i ) return false;
	}
	return true;
}

texturePage_t * idPhysicalPages::AllocPage( idVirtualTexture * vt, texturePage_t * coarser,
		const pageQuadrant_t quadrant, pageImagesUpdateParms_t * deferredUnmap ) {
	if ( vt == nullptr || pages == nullptr ) return nullptr;
	std::int64_t physical = -1;
	if ( !freePageList.PopFront( physical ) ) {
		unlockedPageList.Sort( virtualTextureSystem.feedbackFrameNum, pagePriority, pageFrameNum );
		if ( !unlockedPageList.PopFront( physical ) ) return nullptr;
		FreePage( vt, &pages[static_cast< int >( physical )], deferredUnmap );
		if ( !freePageList.PopFront( physical ) ) return nullptr;
	}
	const int physicalPage = static_cast< int >( physical );
	texturePage_t & page = pages[physicalPage];
	std::memset( &page, 0, sizeof( page ) );
	page.physicalPageNum = static_cast< std::uint16_t >( physicalPage );
	page.mapped = true; page.pageSource = vt->pageSource; page.coarser = coarser; page.quadrant = quadrant;
	if ( coarser != nullptr ) {
		page.pageLevel = coarser->pageLevel > 0 ? coarser->pageLevel - 1 : 0;
		page.maxLevel = coarser->maxLevel;
		page.pageX = static_cast< std::uint16_t >( coarser->pageX * 2 + ( quadrant & 1 ) );
		page.pageY = static_cast< std::uint16_t >( coarser->pageY * 2 + ( ( quadrant >> 1 ) & 1 ) );
		coarser->finer[quadrant & 3] = &page;
	} else {
		page.pageLevel = static_cast< std::uint8_t >( (std::max)( 0, vt->header.numLevels - 1 ) );
		page.maxLevel = page.pageLevel;
	}
	pageHash.InsertPage( &page, physicalPage ); unlockedPageList.Add( physicalPage );
	if ( page.pageLevel < 12 ) ++vt->levelResidency[page.pageLevel];
	return &page;
}

void idPhysicalPages::FreePage( idVirtualTexture * vt, texturePage_t * page, pageImagesUpdateParms_t * ) {
	if ( page == nullptr || !PointerInPagePool( *this, page ) || !page->mapped ) return;
	for ( texturePage_t * child : page->finer ) if ( child != nullptr ) return;
	pageHash.RemovePage( page );
	if ( page->locked ) { page->locked = false; --numLockedPages; }
	else unlockedPageList.Remove( page->physicalPageNum );
	if ( page->coarser != nullptr ) for ( texturePage_t *& child : page->coarser->finer ) if ( child == page ) child = nullptr;
	if ( vt != nullptr && page->pageLevel < 12 && vt->levelResidency[page->pageLevel] > 0 ) --vt->levelResidency[page->pageLevel];
	const int physical = page->physicalPageNum;
	std::memset( page, 0, sizeof( *page ) ); page->physicalPageNum = static_cast< std::uint16_t >( physical );
	freePageList.Add( physical );
}

void idPhysicalPages::FreePageTree_r( idVirtualTexture * vt, texturePage_t * page,
		pageImagesUpdateParms_t * deferredUnmap ) {
	if ( page == nullptr ) return;
	for ( int i = 0; i < 4; ++i ) { texturePage_t * child = page->finer[i]; page->finer[i] = nullptr;
		FreePageTree_r( vt, child, deferredUnmap ); }
	if ( PointerInPagePool( *this, page ) ) FreePage( vt, page, deferredUnmap ); else delete page;
}

void idPhysicalPages::CreatePageImagesUpdate( const idVirtualTexture * vt,
		const texturePage_t * physicalPage, texturePage_t * virtualPage,
		const void * pageDataPBO, const unsigned char * pageData, pageImagesUpdate_t & update ) const {
	std::memset( &update, 0, sizeof( update ) );
	if ( vt == nullptr || physicalPage == nullptr || virtualPage == nullptr ) { update.cancelled = true; return; }
	update.physicalPagesPool = physicalPagesPool; update.physicalPageNum = physicalPage->physicalPageNum;
	update.physX = physicalPage->physicalPageNum % (std::max)( PHYSICAL_PAGES_WIDE, 1 );
	update.physY = physicalPage->physicalPageNum / (std::max)( PHYSICAL_PAGES_WIDE, 1 );
	update.compressed = pageImageCompressed; update.pageDataPBO = pageDataPBO; update.pageData = pageData;
	update.physicalPagesImage0 = physicalPagesImage0; update.physicalPagesImage1 = physicalPagesImage1;
	update.physicalPagesImage2 = physicalPagesImage2;
	update.map[0] = 120.0f / (std::max)( PHYSICAL_TEXELS_WIDE, 1 );
	update.map[1] = 120.0f / (std::max)( PHYSICAL_TEXELS_HIGH, 1 );
	update.map[2] = ( update.physX * 128.0f + 4.0f ) / (std::max)( PHYSICAL_TEXELS_WIDE, 1 );
	update.map[3] = ( update.physY * 128.0f + 4.0f ) / (std::max)( PHYSICAL_TEXELS_HIGH, 1 );
	const std::uint16_t spot = PhysicalPageTableSpot( *vt, *this, *physicalPage );
	update.pageSpot[0] = static_cast< unsigned char >( spot ); update.pageSpot[1] = static_cast< unsigned char >( spot >> 8 );
	update.pageSpot[2] = update.pageSpot[0]; update.pageSpot[3] = update.pageSpot[1];
	update.spotX = virtualPage->pageX; update.spotY = virtualPage->pageY;
	update.effectivePageLevel = virtualPage->pageLevel; update.pageTableImage = vt->pageTableImage;
	virtualPage->mapped = physicalPage == virtualPage;
}

void idPhysicalPages::GetDirectMappedPhysicalPagePointers( int,
		unsigned char * targetImage[3], int targetPitch[3] ) const {
	for ( int i = 0; i < 3; ++i ) { targetImage[i] = nullptr; targetPitch[i] = 0; }
}

void idPhysicalPages::UpdateFilterParms( bool ) {}

idVirtualTextureSystem::idVirtualTextureSystem() : vmtrMega( nullptr ),
	numReferencedVirtualTextures( 0 ), mapHasSpecularPages( true ),
	mapHasDiffuseOnlyPages( true ), mapHasDiffuseOnly2Pages( true ), feedbackBuffer( nullptr ),
	feedbackBufferPitch( 0 ), feedbackBufferObject( nullptr ), feedbackVisualize( nullptr ),
	feedbackStreaming( nullptr ), mipLevelMSE( 0.0f ), feedbackFrameNum( 0 ),
	flushNextFeedback( false ), pageUploadCount( 0 ), pageTranscodeCount( 0 ),
	emptyCacheTime( 0 ), vmtrBatchBuild( BATCH_NONE ), bitBlock( nullptr ), vtInfo( nullptr ),
	currentPageIndices( 0 ), analyzeJobList( nullptr ), currentTranscodeJobList( 0 ),
	cancelToTerminate( false ), vmtrTotalPagesMetric( idStr( "vt_vmtrPages" ) ),
	vmtrBiasMetric( idStr( "vt_vmtrBias" ) ), specTotalPagesMetric( idStr( "vt_specPages" ) ),
	specBiasMetric( idStr( "vt_specBias" ) ), diffuseTotalPagesMetric( idStr( "vt_diffusePages" ) ),
	diffuseBiasMetric( idStr( "vt_diffuseBias" ) ) {
	std::memset( vmtrPath, 0, sizeof( vmtrPath ) ); std::memset( vmtrName, 0, sizeof( vmtrName ) );
	std::memset( vtPtrs, 0, sizeof( vtPtrs ) ); std::memset( referencedVTPath, 0, sizeof( referencedVTPath ) );
	std::memset( referencedVTName, 0, sizeof( referencedVTName ) ); std::memset( containerPath, 0, sizeof( containerPath ) );
	std::memset( renderDestFeedback, 0, sizeof( renderDestFeedback ) );
	std::memset( &analyzeParms, 0, sizeof( analyzeParms ) ); std::memset( pageIndices, 0, sizeof( pageIndices ) );
	std::memset( explicitPages, 0, sizeof( explicitPages ) ); std::memset( numExplicitPages, 0, sizeof( numExplicitPages ) );
	std::memset( transcodeJobList, 0, sizeof( transcodeJobList ) );
	for ( int i = 0; i < 16; ++i ) vts[i].pageSource = static_cast< pageSource_t >( i );
}

idVirtualTextureSystem::~idVirtualTextureSystem() { Shutdown(); }

void idVirtualTextureSystem::Init() {
	if ( vtInfo != nullptr ) return;
	cancelToTerminate = false;
	vtInfo = new virtualTextureInfo_t[16]();
	for ( int i = 0; i < 2; ++i ) {
		pageIndices[i] = reinterpret_cast< pageIndices_t * >( new unsigned char[PAGE_INDICES_ALLOCATION_BYTES] );
		std::memset( pageIndices[i], 0, PAGE_INDICES_ALLOCATION_BYTES );
		explicitPages[i] = new unsigned char[0x2000]();
	}
	bitBlock = new idBitBlockAllocator( 256, 256 );
	CreatePhysicalImages();
}

void idVirtualTextureSystem::Shutdown() {
	cancelToTerminate = true;
	delete[] static_cast< unsigned char * >( feedbackBuffer ); feedbackBuffer = nullptr;
	for ( int i = 0; i < 16; ++i ) vts[i].FreeData();
	for ( idPhysicalPages & pool : physicalPagesPool ) pool.FreeData();
	for ( int i = 0; i < 2; ++i ) {
		delete[] reinterpret_cast< unsigned char * >( pageIndices[i] ); pageIndices[i] = nullptr;
		delete[] explicitPages[i]; explicitPages[i] = nullptr;
		delete[] transcodeJobList[i].transcodeParms; delete[] transcodeJobList[i].transcodeSourceBuffer;
		delete[] transcodeJobList[i].pageUnmapParms.updates; delete[] transcodeJobList[i].pageImagesUpdateParms.updates;
		std::memset( &transcodeJobList[i], 0, sizeof( transcodeJobList[i] ) );
	}
	delete[] vtInfo; vtInfo = nullptr; delete bitBlock; bitBlock = nullptr;
	for ( int i = 0; i < vmtrs.Num(); ++i ) delete vmtrs[i];
	vmtrs.Clear(); std::memset( vtPtrs, 0, sizeof( vtPtrs ) );
}

bool idVirtualTextureSystem::CreatePhysicalImages( const bool vmtr, const bool unique,
		const bool diffuseOnly, const bool diffuseOnly2 ) {
	bool success = true;
	if ( vmtr ) success &= physicalPagesPool[0].CreatePhysicalImages( PHYSICAL_PAGES_POOL_VMTR, "Vmtr", 2048, 2048 );
	if ( unique ) success &= physicalPagesPool[1].CreatePhysicalImages( PHYSICAL_PAGES_POOL_UNIQUE, "Unique", 2048, 2048 );
	if ( diffuseOnly ) success &= physicalPagesPool[2].CreatePhysicalImages( PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY, "Diffuse", 2048, 2048 );
	if ( diffuseOnly2 ) success &= physicalPagesPool[3].CreatePhysicalImages( PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2, "Diffuse2", 2048, 2048 );
	return success;
}

void idVirtualTextureSystem::EmptyCache( bool ) {
	for ( int i = 1; i < 16; ++i ) if ( vtPtrs[i] != nullptr ) vtPtrs[i]->EmptyCache();
	++emptyCacheTime;
}

void idVirtualTextureSystem::FreeLockedPages() {
	for ( idPhysicalPages & pool : physicalPagesPool ) for ( int i = 0; i < pool.NUM_PHYSICAL_PAGES; ++i ) {
		texturePage_t & page = pool.pages[i];
		if ( page.mapped && page.locked ) {
			page.locked = false; pool.unlockedPageList.Add( page.physicalPageNum ); --pool.numLockedPages;
		}
	}
}

void idVirtualTextureSystem::FreeDynamicMedia() { EmptyCache( true ); }

void idVirtualTextureSystem::SetContainerPath( const char * path ) {
	strncpy_s( containerPath, path != nullptr ? path : "", _TRUNCATE );
}

void idVirtualTextureSystem::AddToReferencedVirtualTextures( const char * path, const char * name ) {
	if ( numReferencedVirtualTextures >= 100 ) return;
	strncpy_s( referencedVTPath[numReferencedVirtualTextures], path != nullptr ? path : "", _TRUNCATE );
	strncpy_s( referencedVTName[numReferencedVirtualTextures], name != nullptr ? name : "", _TRUNCATE );
	++numReferencedVirtualTextures;
}

void idVirtualTextureSystem::ClearFeedback() {
	delete[] static_cast< unsigned char * >( feedbackBuffer ); feedbackBuffer = nullptr; feedbackBufferPitch = 0;
	if ( pageIndices[currentPageIndices] != nullptr ) {
		pageIndices[currentPageIndices]->totalNumPages = 0;
		std::memset( pageIndices[currentPageIndices]->pageStats, 0, sizeof( pageIndices[currentPageIndices]->pageStats ) );
	}
}

void idVirtualTextureSystem::AnalyzeFeedback( const void * data, const int width,
		const int height, const bool forceHighestDetail ) {
	if ( vtInfo == nullptr || width <= 0 || height <= 0 ) return;
	for ( int i = 0; i < 16; ++i ) {
		idVirtualTexture * texture = vtPtrs[i];
		vtInfo[i].numLevels = texture != nullptr ? texture->header.numLevels : 0;
		vtInfo[i].baseLevel = 0; vtInfo[i].pagesWide = texture != nullptr ? texture->header.pagesWide : 0;
		vtInfo[i].physicalPagesPool = texture != nullptr ? texture->GetPhysicalPagesPool() : 0;
		vtInfo[i].priorityBias = i == PAGESOURCE_VMTR ? 4 : 8;
	}
	const unsigned int outputIndex = currentPageIndices ^ 1u;
	analyzeParms.analyzeFrame = feedbackFrameNum; analyzeParms.pageIndices = pageIndices[outputIndex];
	analyzeParms.vtInfo = vtInfo; analyzeParms.data = data;
	analyzeParms.width = static_cast< unsigned int >( width ); analyzeParms.height = static_cast< unsigned int >( height );
	analyzeParms.bytePitch = static_cast< unsigned int >( width * 4 );
	analyzeParms.data2 = explicitPages[outputIndex]; analyzeParms.data2Width = numExplicitPages[outputIndex];
	analyzeParms.forceHighestDetail = forceHighestDetail;
	FeedbackAnalysisJob( &analyzeParms ); currentPageIndices = outputIndex;
	for ( int pool = 0; pool < 4; ++pool )
		physicalPagesPool[pool].feedbackNumPages = pageIndices[currentPageIndices]->pageStats[pool].numPages;
}

void idVirtualTextureSystem::PushFeedback( const void * data, const int width,
		const int height, const bool forceHighestDetail ) {
	if ( data == nullptr || width <= 0 || height <= 0 ) return;
	const std::size_t bytes = static_cast< std::size_t >( width ) * height * 4;
	delete[] static_cast< unsigned char * >( feedbackBuffer ); feedbackBuffer = new unsigned char[bytes];
	std::memcpy( feedbackBuffer, data, bytes ); feedbackBufferPitch = width * 4;
	AnalyzeFeedback( feedbackBuffer, width, height, forceHighestDetail ); ++feedbackFrameNum;
}

void idVirtualTextureSystem::FinishFeedback( const bool lockPages, const int maxPages ) {
	pageIndices_t * feedback = pageIndices[currentPageIndices]; if ( feedback == nullptr ) return;
	const int count = (std::min)( maxPages > 0 ? maxPages : static_cast< int >( feedback->totalNumPages ),
		static_cast< int >( feedback->totalNumPages ) );
	int uploaded = 0;
	for ( int i = 0; i < count; ++i ) {
		const std::uint64_t index = feedback->indices[i];
		const unsigned int source = VirtualPageTexture( index );
		idVirtualTexture * texture = source < 16 ? vtPtrs[source] : nullptr;
		if ( texture == nullptr || texture->physicalPages == nullptr ) continue;
		idPhysicalPages & pool = *texture->physicalPages;
		const std::uint32_t pageID = static_cast< std::uint32_t >( index );
		const int resident = pool.pageHash.Find( pageID );
		texturePage_t * page = resident >= 0 ? &pool.pages[resident] : nullptr;
		if ( page == nullptr ) {
			texturePage_t * parent = texture->rootTexturePage; if ( parent == nullptr ) continue;
			const int targetLevel = VirtualPageLevel( index );
			const int targetX = VirtualPageX( index ), targetY = VirtualPageY( index );
			while ( parent->pageLevel > targetLevel ) {
				const int childLevel = parent->pageLevel - 1, bit = childLevel - targetLevel;
				const pageQuadrant_t quadrant = static_cast< pageQuadrant_t >(
					( ( targetX >> bit ) & 1 ) | ( ( ( targetY >> bit ) & 1 ) << 1 ) );
				texturePage_t * child = parent->finer[quadrant];
				if ( child == nullptr ) {
					child = pool.AllocPage( texture, parent, quadrant, nullptr ); if ( child == nullptr ) break;
					ReadAndUploadPage( *texture, pool, *child, parent, quadrant );
					UploadPageTableMapping( *texture, pool, *child ); ++uploaded;
				}
				parent = child;
			}
			page = parent != texture->rootTexturePage ? parent : nullptr;
		}
		if ( page != nullptr ) {
			pool.pagePriority[page->physicalPageNum] = VirtualPagePriority( index );
			pool.pageFrameNum[page->physicalPageNum] = feedbackFrameNum;
			if ( lockPages ) pool.LockPage( page );
		}
	}
	pageUploadCount += uploaded; pageTranscodeCount += uploaded;
}

void idVirtualTextureSystem::SyncFeedback() {}

bool idVirtualTextureSystem::ReloadVirtualTextures() {
	bool success = true;
	for ( int i = 1; i < 16; ++i ) if ( vtPtrs[i] != nullptr ) {
		idVirtualTexture & texture = *vtPtrs[i];
		const idStrStatic<256> base = texture.baseName, path = texture.pageFilePath;
		const physicalPagesPool_t pool = texture.GetPhysicalPagesPool();
		success &= texture.SetSource( base.c_str(), path.c_str(), pool );
	}
	return success;
}

void idVirtualTextureSystem::UpdateFilterParms( const bool force ) {
	for ( idPhysicalPages & pool : physicalPagesPool ) pool.UpdateFilterParms( force );
}

void idVirtualTextureSystem::LockPhysicalPages( idVirtualTexture ** textures,
		const int numTextures, const int numPages ) {
	if ( textures == nullptr || pageIndices[currentPageIndices] == nullptr ) return;
	for ( int i = 0; i < numTextures; ++i ) if ( textures[i] != nullptr )
		textures[i]->GetToBeLockedPhysicalPages( numPages, pageIndices[currentPageIndices] );
	FinishFeedback( true, numPages );
}

idVirtualTexture * idVirtualTextureSystem::VirtualTextureForMaterial( const idMaterial * material ) {
	if ( material == nullptr ) return nullptr;
	const int source = static_cast< int >( material->pageSource );
	return source >= 0 && source < 16 ? vtPtrs[source] : nullptr;
}

idVirtualMaterial * idVirtualTextureSystem::VirtualMaterialForMaterial( const idMaterial * material ) {
	if ( material == nullptr ) return nullptr;
	if ( material->devVmtr != nullptr ) return material->devVmtr;
	for ( int i = 0; i < vmtrs.Num(); ++i ) if ( vmtrs[i] != nullptr && vmtrs[i]->material == material ) return vmtrs[i];
	return nullptr;
}

idFile * idVirtualTextureSystem::OpenCachedPagesFile( const char * path ) {
	return fileSystem != nullptr && path != nullptr ? fileSystem->OpenFileRead( path, true, false ) : nullptr;
}

idFile * idVirtualTextureSystem::OpenInstalledCachedPagesFile( const char * path ) {
	return fileSystem != nullptr && path != nullptr ? fileSystem->OpenFileRead( path, true, false ) : nullptr;
}

void idVirtualTextureSystem::CloseCachedPagesFile( idFile * file ) { delete file; }

idPhysicalPages * idVirtualTextureSystem::GetPhysicalPagesPool( const physicalPagesPool_t pool ) {
	return pool >= PHYSICAL_PAGES_POOL_VMTR && pool < PHYSICAL_PAGES_POOL_MAX ? &physicalPagesPool[pool] : nullptr;
}

void idVirtualTextureSystem::RegisterSource( const pageSource_t source, idVirtualTexture * texture ) {
	if ( source > PAGESOURCE_INVALID && source < PAGESOURCE_TOTAL ) vtPtrs[source] = texture;
}

idPhysicalPages * VT_GetPhysicalPagesPool( const physicalPagesPool_t pool ) {
	return virtualTextureSystem.GetPhysicalPagesPool( pool );
}

void VT_RegisterSource( const pageSource_t source, idVirtualTexture * texture ) {
	virtualTextureSystem.RegisterSource( source, texture );
}
