#pragma once

#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

template<typename nodeHolderType, typename nodeCacheType,
    typename nodeIndexType, typename edgeCacheType, typename pathType>
bool idDijkstra<nodeHolderType, nodeCacheType, nodeIndexType,
    edgeCacheType, pathType>::TracePath(
        const nodeHolderType& nodeHolder,
        const nodeIndexType startNode,
        const nodeIndexType destNode,
        const djScratch_t* scratchBuff,
        pathType& path) {
    (void)nodeHolder;

    const int start = static_cast<int>(startNode.Get());
    const int destination = static_cast<int>(destNode.Get());
    if (lastStartNode != start) {
        return false;
    }

    path.num = 0;
    path.cost = 0x7FFFFFFF;
    if (destination == start) {
        return false;
    }

    path.path[path.num++] = nodeIndexType(
        static_cast<short>(destination));
    const djScratch_t* scratch = &scratchBuff[destination];
    path.cost = scratch->Cost();

    while (path.num < 32) {
        const short previous = scratch->prevIndex;
        if (previous < 0) {
            path.cost = 0x7FFFFFFF;
            path.num = 0;
            return false;
        }

        path.path[path.num++] = nodeIndexType(previous);
        scratch = &scratchBuff[previous];
        if (previous == start) {
            path.Invert();
            return true;
        }
    }

    // The recovered implementation returns the first 32 nodes when a route
    // exceeds the fixed route buffer, then reverses that bounded prefix.
    path.Invert();
    return true;
}

template<typename nodeHolderType, typename nodeCacheType,
    typename nodeIndexType, typename edgeCacheType, typename pathType>
bool idDijkstra<nodeHolderType, nodeCacheType, nodeIndexType,
    edgeCacheType, pathType>::FindShortestPaths(
        const nodeHolderType& nodeHolder,
        const nodeIndexType startNode,
        const nodeIndexType* destNodes,
        const int numDestNodes,
        const edgeCacheType* edges,
        djScratch_t* scratchBuff,
        const int skipFlags,
        const int requiredFlags) {
    const int nodeCount = nodeHolder.decl->nodes.num;
    std::memset(scratchBuff, 0xFF,
        sizeof(djScratch_t) * static_cast<std::size_t>(nodeCount));

    for (int listIndex = 0;
            listIndex < nodeHolder.pathableSubWebNodeLists.num;
            ++listIndex) {
        const auto* const pathable =
            nodeHolder.pathableSubWebNodeLists.list[listIndex];
        for (int nodeIndex = 0; nodeIndex < pathable->num; ++nodeIndex) {
            const int value = static_cast<int>(pathable->list[nodeIndex].Get());
            scratchBuff[value].SetVisited(false);
        }
    }

    const int start = static_cast<int>(startNode.Get());
    scratchBuff[start].SetVisited(false);
    scratchBuff[start].SetCost(0);
    scratchBuff[start].prevIndex = -1;
    lastStartNode = -1;

    using heapEntry_t = std::pair<int, int>;
    std::priority_queue<heapEntry_t, std::vector<heapEntry_t>,
        std::greater<heapEntry_t>> heap;
    heap.push(heapEntry_t(0, start));

    int destinationsFound = 0;
    int processedNodes = 0;
    while (!heap.empty() && processedNodes < nodeCount) {
        const int node = heap.top().second;
        heap.pop();

        djScratch_t& nodeScratch = scratchBuff[node];
        if (nodeScratch.Visited()) {
            continue;
        }

        for (int destinationIndex = 0;
                destinationIndex < numDestNodes;
                ++destinationIndex) {
            if (destNodes[destinationIndex].Get() == node) {
                ++destinationsFound;
                if (destinationsFound == numDestNodes) {
                    lastStartNode = start;
                    return true;
                }
                break;
            }
        }

        const nodeCacheType& nodeCache = nodeHolder.decl->nodeCache.list[node];
        const int nodeCost = nodeScratch.Cost();
        nodeScratch.SetVisited(true);

        if ((nodeCache.flags & skipFlags) == 0
                && (nodeCache.flags & requiredFlags) == requiredFlags) {
            for (int localEdge = 0; localEdge < nodeCache.numEdges;
                    ++localEdge) {
                const int edgeIndex = nodeHolder.decl->edgeIndexCache[
                    nodeCache.edgeIndexOffset + localEdge];
                const edgeCacheType& edge = edges[edgeIndex];
                const int destination = static_cast<int>(
                    edge.destNodeIndex.Get());
                djScratch_t& destinationScratch = scratchBuff[destination];
                if (destinationScratch.Visited()) {
                    continue;
                }

                const float scaledCost = static_cast<float>(
                    nodeHolder.InternalGetEdgeCost(
                        nodeIndexType(static_cast<short>(node)),
                        { static_cast<short>(edgeIndex) }))
                    * (static_cast<float>(edge.weightScale) * 0.0625f);
                const int newCost = nodeCost + static_cast<int>(scaledCost);
                if (destinationScratch.Cost() > newCost) {
                    destinationScratch.prevIndex = static_cast<short>(node);
                    destinationScratch.SetCost(newCost);
                    heap.push(heapEntry_t(newCost, destination));
                }
            }
        }

        ++processedNodes;
    }

    lastStartNode = start;
    return true;
}
