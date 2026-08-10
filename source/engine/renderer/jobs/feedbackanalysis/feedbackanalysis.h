#pragma once

#include <cstddef>
#include <cstdint>

#ifndef TECH5_PHYSICAL_PAGES_POOL_T_DEFINED
#define TECH5_PHYSICAL_PAGES_POOL_T_DEFINED
enum physicalPagesPool_t : std::int32_t {
	PHYSICAL_PAGES_POOL_VMTR = 0,
	PHYSICAL_PAGES_POOL_UNIQUE = 1,
	PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY = 2,
	PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2 = 3,
	PHYSICAL_PAGES_POOL_MAX = 4
};
#endif

struct pageStats_t {
	std::uint16_t numPages;
	std::uint16_t numVisPages;
	std::uint16_t numTopPages;
	std::uint16_t pad;
};

struct pageIndices_t {
	std::uint64_t totalNumPages;
	pageStats_t pageStats[PHYSICAL_PAGES_POOL_MAX];
	std::uint64_t indices[1];
};

struct virtualTextureInfo_t {
	unsigned int numLevels;
	unsigned int baseLevel;
	unsigned int pagesWide;
	std::uint16_t physicalPagesPool;
	std::uint16_t priorityBias;
};

struct analyzeParms_t {
	int analyzeFrame;
	pageIndices_t * pageIndices;
	const virtualTextureInfo_t * vtInfo;
	const void * data;
	unsigned int width;
	unsigned int height;
	unsigned int bytePitch;
	const void * data2;
	unsigned int data2Width;
	bool forceHighestDetail;
};

static const std::size_t PAGE_INDICES_ALLOCATION_BYTES = 0x4008;
static const unsigned int MAX_FEEDBACK_PAGE_INDICES =
	static_cast< unsigned int >( ( PAGE_INDICES_ALLOCATION_BYTES - offsetof( pageIndices_t, indices ) ) /
		sizeof( std::uint64_t ) );

inline std::uint32_t PackVirtualPageID( unsigned int virtualTexture, unsigned int level,
		unsigned int x, unsigned int y ) {
	return ( x & 0x7FFu ) | ( ( y & 0x7FFu ) << 11 ) |
		( ( level & 0xFu ) << 22 ) | ( ( virtualTexture & 0xFu ) << 26 );
}

inline unsigned int VirtualPageX( std::uint64_t index ) { return static_cast< unsigned int >( index ) & 0x7FFu; }
inline unsigned int VirtualPageY( std::uint64_t index ) { return ( static_cast< unsigned int >( index ) >> 11 ) & 0x7FFu; }
inline unsigned int VirtualPageLevel( std::uint64_t index ) { return ( static_cast< unsigned int >( index ) >> 22 ) & 0xFu; }
inline unsigned int VirtualPageTexture( std::uint64_t index ) { return ( static_cast< unsigned int >( index ) >> 26 ) & 0xFu; }
inline unsigned int VirtualPagePriority( std::uint64_t index ) { return static_cast< unsigned int >( index >> 56 ) & 0x1Fu; }
inline unsigned int VirtualPageSamples( std::uint64_t index ) { return static_cast< unsigned int >( index >> 40 ) & 0xFFFFu; }
inline bool VirtualPageVisible( std::uint64_t index ) { return ( index & ( 1ull << 32 ) ) != 0; }
inline bool VirtualPageAncestor( std::uint64_t index ) { return ( index & ( 1ull << 33 ) ) != 0; }

void GetUniqueVirtualPages( pageIndices_t * pageIndices, std::uint16_t * temp,
	const virtualTextureInfo_t * vtInfo, const void * data, unsigned int width,
	unsigned int height, unsigned int bytePitch, const void * data2,
	unsigned int data2Width, bool forceHighestDetail );
void FeedbackAnalysisJob( const analyzeParms_t * parms );

#if defined( _M_IX86 )
static_assert( offsetof( analyzeParms_t, data2 ) == 28, "Recovered feedback ABI changed" );
#endif
