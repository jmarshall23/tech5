#pragma once

#include <cstdint>

struct pageSortParms_t {
	int frameNum;
	const int * pagePriority;
	const int * pageFrameNum;
	const std::int64_t * physicalPageNums;
	int * firstPageIndex;
	int * lastPageIndex;
	int indexMask;
	std::int64_t * sortedPhysicalPageNums;
	volatile int * done;
};

void PageListQuickSort( std::int64_t * pages, int count );
void PageSortJob( const pageSortParms_t * parms );
