#include "feedbackanalysis.h"

#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

namespace {
	struct accumulatedPage_t {
		std::uint32_t id;
		unsigned int priority;
		unsigned int samples;
		bool visible;
		bool ancestor;
	};

	void AccumulateFeedbackPixel( const unsigned char * pixel, const bool explicitPage,
			const bool forceHighestDetail, const virtualTextureInfo_t * info,
			std::unordered_map< std::uint32_t, std::size_t > & lookup,
			std::vector< accumulatedPage_t > & pages ) {
		if ( pixel == nullptr || info == nullptr ) return;
		const unsigned int texture = pixel[3] >> 4;
		if ( texture == 0 || texture >= 16 ) return;
		const virtualTextureInfo_t & textureInfo = info[texture];
		if ( textureInfo.numLevels == 0 || textureInfo.pagesWide == 0 ) return;
		const unsigned int fullX = pixel[0] | ( ( pixel[2] & 0x0Fu ) << 8 );
		const unsigned int fullY = pixel[1] | ( ( pixel[2] & 0xF0u ) << 4 );
		if ( fullX >= textureInfo.pagesWide || fullY >= textureInfo.pagesWide ) return;
		unsigned int requestedLevel = forceHighestDetail ? textureInfo.baseLevel : pixel[3] & 0x0Fu;
		requestedLevel = (std::max)( textureInfo.baseLevel,
			(std::min)( textureInfo.numLevels - 1, requestedLevel ) );
		unsigned int x = fullX >> requestedLevel;
		unsigned int y = fullY >> requestedLevel;
		for ( unsigned int level = requestedLevel; level < textureInfo.numLevels; ++level ) {
			const std::uint32_t id = PackVirtualPageID( texture, level, x, y );
			const unsigned int priority = (std::min)( 31u,
				static_cast< unsigned int >( textureInfo.priorityBias ) + level - requestedLevel + 1u +
				( explicitPage ? 16u : 0u ) );
			const auto found = lookup.find( id );
			if ( found == lookup.end() ) {
				if ( pages.size() >= MAX_FEEDBACK_PAGE_INDICES - 1 ) break;
				lookup[id] = pages.size();
				accumulatedPage_t page = { id, priority, 1u, level == requestedLevel && !explicitPage,
					level != requestedLevel };
				pages.push_back( page );
			} else {
				accumulatedPage_t & page = pages[found->second];
				page.priority = (std::max)( page.priority, priority );
				page.samples = (std::min)( page.samples + 1u, 0xFFFFu );
				page.visible |= level == requestedLevel && !explicitPage;
				page.ancestor &= level != requestedLevel;
			}
			x >>= 1;
			y >>= 1;
		}
	}

	std::uint64_t PackAccumulatedPage( const accumulatedPage_t & page ) {
		std::uint64_t result = page.id;
		if ( page.visible ) result |= 1ull << 32;
		if ( page.ancestor ) result |= 1ull << 33;
		result |= static_cast< std::uint64_t >( page.samples & 0xFFFFu ) << 40;
		result |= static_cast< std::uint64_t >( page.priority & 0x1Fu ) << 56;
		return result;
	}
}

void GetUniqueVirtualPages( pageIndices_t * output, std::uint16_t * temp,
		const virtualTextureInfo_t * vtInfo, const void * data, const unsigned int width,
		const unsigned int height, const unsigned int bytePitch, const void * data2,
		const unsigned int data2Width, const bool forceHighestDetail ) {
	if ( output == nullptr ) return;
	output->totalNumPages = 0;
	std::memset( output->pageStats, 0, sizeof( output->pageStats ) );
	if ( temp != nullptr ) std::memset( temp, 0, 2048 );
	if ( vtInfo == nullptr ) return;
	std::unordered_map< std::uint32_t, std::size_t > lookup;
	lookup.reserve( MAX_FEEDBACK_PAGE_INDICES * 2 );
	std::vector< accumulatedPage_t > pages;
	pages.reserve( MAX_FEEDBACK_PAGE_INDICES );
	const unsigned char * explicitPixels = static_cast< const unsigned char * >( data2 );
	for ( unsigned int x = 0; explicitPixels != nullptr && x < data2Width; ++x )
		AccumulateFeedbackPixel( explicitPixels + x * 4, true, forceHighestDetail, vtInfo, lookup, pages );
	const unsigned char * feedback = static_cast< const unsigned char * >( data );
	const unsigned int pitch = bytePitch != 0 ? bytePitch : width * 4;
	for ( unsigned int y = 0; feedback != nullptr && y < height; ++y )
		for ( unsigned int x = 0; x < width; ++x )
			AccumulateFeedbackPixel( feedback + y * pitch + x * 4, false,
				forceHighestDetail, vtInfo, lookup, pages );
	std::vector< std::uint64_t > packed;
	packed.reserve( pages.size() );
	for ( const accumulatedPage_t & page : pages ) {
		const std::uint64_t index = PackAccumulatedPage( page );
		packed.push_back( index );
		const unsigned int texture = VirtualPageTexture( index );
		const unsigned int pool = texture < 16 ? vtInfo[texture].physicalPagesPool : PHYSICAL_PAGES_POOL_VMTR;
		if ( pool < PHYSICAL_PAGES_POOL_MAX ) {
			pageStats_t & stats = output->pageStats[pool];
			if ( stats.numPages != 0xFFFFu ) ++stats.numPages;
			if ( page.visible && stats.numVisPages != 0xFFFFu ) ++stats.numVisPages;
			if ( !page.ancestor && stats.numTopPages != 0xFFFFu ) ++stats.numTopPages;
		}
	}
	std::sort( packed.begin(), packed.end(), []( const std::uint64_t a, const std::uint64_t b ) {
		if ( VirtualPagePriority( a ) != VirtualPagePriority( b ) )
			return VirtualPagePriority( a ) > VirtualPagePriority( b );
		if ( VirtualPageSamples( a ) != VirtualPageSamples( b ) )
			return VirtualPageSamples( a ) > VirtualPageSamples( b );
		return static_cast< std::uint32_t >( a ) < static_cast< std::uint32_t >( b );
	} );
	output->totalNumPages = packed.size();
	if ( !packed.empty() ) std::memcpy( output->indices, packed.data(), packed.size() * sizeof( packed[0] ) );
}

void FeedbackAnalysisJob( const analyzeParms_t * parms ) {
	if ( parms == nullptr ) return;
	std::uint16_t temp[4096] = {};
	GetUniqueVirtualPages( parms->pageIndices, temp, parms->vtInfo, parms->data,
		parms->width, parms->height, parms->bytePitch, parms->data2,
		parms->data2Width, parms->forceHighestDetail );
}
