#include "virtualtexture.h"

#include "image.h"
#include "imagemanager.h"
#include "jobs/pageupdate/pageupdate.h"

#include "../../shared/idlib/filesystem/filesystem.h"
#include "../../shared/idlib/filesystem/file.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

idPhysicalPages * VT_GetPhysicalPagesPool( physicalPagesPool_t pool );
void VT_RegisterSource( pageSource_t source, idVirtualTexture * texture );

namespace {
	static const int PAGE_FILE_MAGIC = 1999870212;

	std::uint16_t ByteSwap16( const std::uint16_t value ) {
		return static_cast< std::uint16_t >( value << 8 | value >> 8 );
	}
	std::uint32_t ByteSwap32( const std::uint32_t value ) {
		return ( value >> 24 ) | ( ( value >> 8 ) & 0x0000FF00u ) |
			( ( value << 8 ) & 0x00FF0000u ) | ( value << 24 );
	}
	std::uint64_t ByteSwap64( const std::uint64_t value ) {
		return static_cast< std::uint64_t >( ByteSwap32( static_cast< std::uint32_t >( value ) ) ) << 32 |
			ByteSwap32( static_cast< std::uint32_t >( value >> 32 ) );
	}

	void InitializeRoot( idVirtualTexture & texture ) {
		texture.rootTexturePage = new texturePage_t();
		std::memset( texture.rootTexturePage, 0, sizeof( texturePage_t ) );
		texture.rootTexturePage->mapped = false;
		texture.rootTexturePage->locked = true;
		texture.rootTexturePage->maxLevel = static_cast< std::uint8_t >( (std::max)( 0,
			static_cast< int >( texture.header.numLevels ) - 1 ) );
		texture.rootTexturePage->pageLevel = texture.rootTexturePage->maxLevel;
		texture.rootTexturePage->pageSource = texture.pageSource;
		texture.rootTexturePage->pageCompression = texture.header.subRoot.pageCompression;
		std::memcpy( texture.rootTexturePage->finerDiskOffset,
			texture.header.subRoot.finerDiskOffset, sizeof( texture.rootTexturePage->finerDiskOffset ) );
		std::memcpy( texture.rootTexturePage->finerDiskLength,
			texture.header.subRoot.finerDiskLength, sizeof( texture.rootTexturePage->finerDiskLength ) );
	}
}

void SwapPageHeader( pageHeader_t & header ) {
	header.magic = static_cast< int >( ByteSwap32( static_cast< std::uint32_t >( header.magic ) ) );
	header.pageCompression = static_cast< pageCompression_t >(
		ByteSwap32( static_cast< std::uint32_t >( header.pageCompression ) ) );
	for ( int i = 0; i < 4; ++i ) {
		header.finerDiskOffset[i] = ByteSwap32( header.finerDiskOffset[i] );
		header.finerDiskLength[i] = ByteSwap16( header.finerDiskLength[i] );
	}
	header.x = ByteSwap16( header.x );
	header.y = ByteSwap16( header.y );
	header.level = ByteSwap16( header.level );
	header.reserved = ByteSwap16( header.reserved );
}

void SwapPageFileHeader( pageFileHeader_t & header ) {
	header.magic = static_cast< int >( ByteSwap32( static_cast< std::uint32_t >( header.magic ) ) );
	header.pagesWide = static_cast< int >( ByteSwap32( static_cast< std::uint32_t >( header.pagesWide ) ) );
	header.installedMipAndOffset = static_cast< int >(
		ByteSwap32( static_cast< std::uint32_t >( header.installedMipAndOffset ) ) );
	header.numLevels = static_cast< std::int16_t >( ByteSwap16( static_cast< std::uint16_t >( header.numLevels ) ) );
	header.layoutVersion = static_cast< std::int16_t >( ByteSwap16( static_cast< std::uint16_t >( header.layoutVersion ) ) );
	header.totalPages = static_cast< int >( ByteSwap32( static_cast< std::uint32_t >( header.totalPages ) ) );
	header.diskOffsetScale = static_cast< int >( ByteSwap32( static_cast< std::uint32_t >( header.diskOffsetScale ) ) );
	header.totalFileSize = static_cast< std::int64_t >(
		ByteSwap64( static_cast< std::uint64_t >( header.totalFileSize ) ) );
	SwapPageHeader( header.subRoot );
}

pageCompression_t PageCompressionForString( const char * string ) {
	if ( string == nullptr ) return COMP_DXT;
	if ( _stricmp( string, "none" ) == 0 || _stricmp( string, "raw" ) == 0 ) return COMP_NONE;
	if ( _stricmp( string, "dxt" ) == 0 || _stricmp( string, "bc" ) == 0 ) return COMP_DXT;
	if ( _stricmp( string, "lzw" ) == 0 ) return COMP_LZW;
	if ( _stricmp( string, "dct" ) == 0 || _stricmp( string, "jpeg" ) == 0 ) return COMP_DCT;
	if ( _stricmp( string, "hdp" ) == 0 || _stricmp( string, "hdphoto" ) == 0 ) return COMP_HDP;
	if ( _stricmp( string, "jxr" ) == 0 || _stricmp( string, "jpegxr" ) == 0 ) return COMP_JXR;
	return COMP_DXT;
}

idVirtualTexture::idVirtualTexture() :
	pageSource( PAGESOURCE_INVALID ), layoutVersion( 0 ), pageFile( nullptr ),
	pageFileInstalled( nullptr ), minMipLevelInstalled( 0 ), VIRTUAL_PAGES_WIDE_LOG2( 0 ),
	VIRTUAL_TEXELS_WIDE( 0 ), VIRTUAL_MAPPING_PAGES_WIDE( 0 ), physicalPages( nullptr ),
	rootTexturePage( nullptr ), pageTableImage( nullptr ), enlargedPageTableAllocationFailed( false ),
	isDirectMapped( false ), pageFileIsLocal( false ), skipFlush( false ),
	forcedPageCompression( static_cast< pageCompression_t >( 0 ) ) {
	std::memset( &header, 0, sizeof( header ) );
	std::memset( mipLevelPagesWide, 0, sizeof( mipLevelPagesWide ) );
	std::memset( levelResidency, 0, sizeof( levelResidency ) );
}

idVirtualTexture::~idVirtualTexture() {
	FreeData();
}

physicalPagesPool_t idVirtualTexture::GetPhysicalPagesPool() const {
	return physicalPages != nullptr ? physicalPages->physicalPagesPool : PHYSICAL_PAGES_POOL_VMTR;
}

void idVirtualTexture::GetToBeLockedPhysicalPages( const int numTexturePages,
		pageIndices_t * pageIndices ) const {
	if ( pageIndices == nullptr || pageSource <= PAGESOURCE_INVALID ||
		header.numLevels <= 0 || numTexturePages <= 0 ) return;
	unsigned int count = static_cast< unsigned int >( (std::min)( numTexturePages,
		static_cast< int >( MAX_FEEDBACK_PAGE_INDICES - pageIndices->totalNumPages ) ) );
	for ( int level = header.numLevels - 1; level >= 0 && count > 0; --level ) {
		const int pagesWide = (std::max)( 1, header.pagesWide >> level );
		for ( int y = 0; y < pagesWide && count > 0; ++y ) for ( int x = 0; x < pagesWide && count > 0; ++x ) {
			std::uint64_t index = PackVirtualPageID( pageSource, level, x, y );
			index |= 1ull << 32;
			index |= static_cast< std::uint64_t >( 31 ) << 56;
			pageIndices->indices[pageIndices->totalNumPages++] = index;
			--count;
		}
	}
}

void idVirtualTexture::EmptyCache() {
	if ( physicalPages != nullptr && rootTexturePage != nullptr )
		physicalPages->FreePageTree_r( this, rootTexturePage, nullptr );
	rootTexturePage = nullptr;
	std::memset( levelResidency, 0, sizeof( levelResidency ) );
	if ( header.numLevels > 0 ) InitializeRoot( *this );
	dirtyPages.Clear();
}

idVec4 idVirtualTexture::GetFeedbackVec4() const {
	return idVec4( VIRTUAL_TEXELS_WIDE > 0 ? 1.0f / VIRTUAL_TEXELS_WIDE : 0.0f,
		static_cast< float >( VIRTUAL_PAGES_WIDE_LOG2 ), static_cast< float >( pageSource ), 0.0f );
}

void idVirtualTexture::Print() const {
	if ( pageFile == nullptr ) {
		std::printf( "No virtual-texture source set.\n" );
		return;
	}
	std::printf( "Page file: %s\nmagic: 0x%x  pages: %d  levels: %d  layout: %d  alignment: %d\n",
		pageFilePath.c_str(), header.magic, header.pagesWide, header.numLevels,
		header.layoutVersion, header.diskOffsetScale );
	if ( physicalPages != nullptr ) std::printf( "Resident: %d  locked: %d\n",
		physicalPages->GetNumResidentPagesForSource( pageSource ),
		physicalPages->GetNumLockedPagesForSource( pageSource ) );
}

pageCompression_t idVirtualTexture::GetNewDiskPageCompression() const {
	if ( forcedPageCompression > 0 && forcedPageCompression < COMP_MAX_COMPRESSIONS )
		return forcedPageCompression;
	if ( std::strstr( pageFilePath.c_str(), "_U." ) != nullptr ) return COMP_NONE;
	return pageSource == PAGESOURCE_VMTR ? COMP_DXT : COMP_JXR;
}

void idVirtualTexture::FreeData() {
	if ( rootTexturePage != nullptr ) {
		if ( physicalPages != nullptr ) physicalPages->FreePageTree_r( this, rootTexturePage, nullptr );
		else delete rootTexturePage;
	}
	rootTexturePage = nullptr;
	if ( pageFile != nullptr ) delete pageFile;
	if ( pageFileInstalled != nullptr && pageFileInstalled != pageFile ) delete pageFileInstalled;
	pageFile = pageFileInstalled = nullptr;
	if ( pageTableImage != nullptr ) pageTableImage->PurgeImage();
	pageTableImage = nullptr;
	physicalPages = nullptr;
	VT_RegisterSource( pageSource, nullptr );
	std::memset( &header, 0, sizeof( header ) );
	std::memset( mipLevelPagesWide, 0, sizeof( mipLevelPagesWide ) );
	std::memset( levelResidency, 0, sizeof( levelResidency ) );
	VIRTUAL_PAGES_WIDE_LOG2 = VIRTUAL_TEXELS_WIDE = VIRTUAL_MAPPING_PAGES_WIDE = 0;
	enlargedPageTableAllocationFailed = isDirectMapped = false;
	pageFileIsLocal = skipFlush = false;
	pageFilePath = "";
	baseName = "";
}

void idVirtualTexture::ReleaseSource() {
	FreeData();
}

bool idVirtualTexture::ValidatePageTable() const {
	if ( header.numLevels <= 0 || header.numLevels > 16 || header.pagesWide <= 0 ) return false;
	for ( int level = 0; level < header.numLevels; ++level ) {
		const int expected = (std::max)( 1, header.pagesWide >> level );
		if ( mipLevelPagesWide[level] != expected ) return false;
	}
	return rootTexturePage != nullptr && rootTexturePage->pageSource == pageSource;
}

bool idVirtualTexture::SetSource( const char * newBaseName, const char * newPageFilePath,
		const physicalPagesPool_t pool ) {
	const pageSource_t source = pageSource != PAGESOURCE_INVALID ? pageSource :
		( pool == PHYSICAL_PAGES_POOL_VMTR ? PAGESOURCE_VMTR : PAGESOURCE_UNIQUE );
	FreeData();
	pageSource = source;
	baseName = newBaseName != nullptr ? newBaseName : "";
	pageFilePath = newPageFilePath != nullptr ? newPageFilePath : "";
	if ( fileSystem == nullptr || pageFilePath.IsEmpty() ) return false;
	pageFile = fileSystem->OpenFileRead( pageFilePath.c_str(), true, false );
	if ( pageFile == nullptr || pageFile->Read( &header, sizeof( header ) ) != sizeof( header ) ) {
		FreeData(); pageSource = source; return false;
	}
	if ( header.magic != PAGE_FILE_MAGIC ) {
		pageFileHeader_t swapped = header;
		SwapPageFileHeader( swapped );
		if ( swapped.magic != PAGE_FILE_MAGIC ) { FreeData(); pageSource = source; return false; }
		header = swapped;
	}
	if ( header.diskOffsetScale <= 0 ) header.diskOffsetScale = 64;
	if ( header.numLevels <= 0 || header.numLevels > 16 || header.pagesWide <= 0 ||
		( layoutVersion > 0 && header.layoutVersion > 0 && layoutVersion != header.layoutVersion ) ) {
		FreeData(); pageSource = source; return false;
	}
	layoutVersion = header.layoutVersion;
	VIRTUAL_MAPPING_PAGES_WIDE = header.pagesWide;
	VIRTUAL_PAGES_WIDE_LOG2 = 0;
	while ( ( 1 << VIRTUAL_PAGES_WIDE_LOG2 ) < header.pagesWide && VIRTUAL_PAGES_WIDE_LOG2 < 15 )
		++VIRTUAL_PAGES_WIDE_LOG2;
	VIRTUAL_TEXELS_WIDE = header.pagesWide * 120;
	for ( int level = 0; level < 16; ++level ) mipLevelPagesWide[level] =
		static_cast< std::uint16_t >( (std::max)( 1, header.pagesWide >> level ) );
	physicalPages = VT_GetPhysicalPagesPool( pool );
	if ( physicalPages == nullptr ) { FreeData(); pageSource = source; return false; }
	idImageOpts opts;
	opts.textureType = TT_2D;
	opts.width = header.pagesWide;
	opts.height = header.pagesWide;
	opts.numLevels = header.numLevels;
	opts.format = FMT_RGB565;
	opts.filter = TF_NEAREST_MIPMAP_NEAREST;
	opts.repeat = TR_CLAMP;
	// The 360 page table was CPU-linear memory.  On D3D9 a managed texture is
	// the durable equivalent: updates still use LockRect while device reset no
	// longer invalidates every virtual texture's page table.
	opts.linear = false;
	if ( globalImages != nullptr ) pageTableImage = globalImages->ScratchImage( pageFilePath.c_str(), &opts );
	if ( pageTableImage == nullptr || pageTableImage->allocationFailed ) {
		FreeData(); pageSource = source; return false;
	}
	InitializeRoot( *this );
	dirtyPages.Init( header.pagesWide, header.numLevels - 1, layoutVersion );
	VT_RegisterSource( pageSource, this );
	return ValidatePageTable();
}
