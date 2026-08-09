#pragma once

#include "idlib/containers/list.h"

#include <cstdint>

void PutIndexesInSortedOrderForComparison(int numIndexes,
    std::uint16_t* indexes);
int RemoveDuplicatedTrianglesFromSortedList(int numIndexes,
    std::uint16_t* indexes);
void StripIndexesToTriangleIndexes(const std::uint16_t* stripIndexes,
    int numStripIndexes, idList<std::uint16_t, 5>& triangleIndexes);
void TriangleStripper(const std::uint16_t* indexes, int numIndexes,
    idList<std::uint16_t, 5>& stripIndexes);

