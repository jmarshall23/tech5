#include "pagesort.h"

#include <algorithm>
#include <cstdint>

namespace {
	bool PageLess( const std::int64_t a, const std::int64_t b ) {
		const std::int32_t priorityA = static_cast< std::int32_t >(
			static_cast< std::uint64_t >( a ) >> 32 );
		const std::int32_t priorityB = static_cast< std::int32_t >(
			static_cast< std::uint64_t >( b ) >> 32 );
		if ( priorityA != priorityB ) return priorityA < priorityB;
		return static_cast< std::uint32_t >( a ) < static_cast< std::uint32_t >( b );
	}
}

void PageListQuickSort( std::int64_t * pages, const int count ) {
	if ( pages == nullptr || count <= 1 ) return;
	std::sort( pages, pages + count, PageLess );
}

void PageSortJob( const pageSortParms_t * parms ) {
	if ( parms == nullptr || parms->firstPageIndex == nullptr ||
			parms->lastPageIndex == nullptr || parms->physicalPageNums == nullptr ||
			parms->sortedPhysicalPageNums == nullptr || parms->indexMask < 0 ) {
		if ( parms != nullptr && parms->done != nullptr ) *parms->done = 1;
		return;
	}
	const int first = *parms->firstPageIndex;
	const int last = *parms->lastPageIndex;
	const int capacity = parms->indexMask + 1;
	int count = last - first + 1;
	if ( count < 0 ) count += capacity;
	count = (std::max)( 0, (std::min)( count, capacity ) );
	for ( int output = 0; output < count; ++output ) {
		const int ringIndex = ( first + output ) & parms->indexMask;
		const std::uint32_t physicalPage = static_cast< std::uint32_t >(
			parms->physicalPageNums[ringIndex] );
		int priority = 0;
		if ( parms->pagePriority != nullptr ) priority += parms->pagePriority[physicalPage];
		if ( parms->pageFrameNum != nullptr ) priority +=
			parms->pageFrameNum[physicalPage] - parms->frameNum;
		parms->sortedPhysicalPageNums[output] = static_cast< std::int64_t >(
			static_cast< std::uint64_t >( static_cast< std::uint32_t >( priority ) ) << 32 |
			physicalPage );
	}
	*parms->firstPageIndex = 0;
	*parms->lastPageIndex = count - 1;
	PageListQuickSort( parms->sortedPhysicalPageNums, count );
	if ( parms->done != nullptr ) *parms->done = 1;
}
