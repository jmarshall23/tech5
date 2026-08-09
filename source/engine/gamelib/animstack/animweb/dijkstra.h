#pragma once

#include "idlib/index.h"

#include <cstdint>

// Recovered idDijkstra storage and interface. The materialized Xbox binary is
// the AnimWeb specialization, while keeping the original template boundary
// lets the algorithm be compiled and tested before idDeclAnimWeb is active.
template<typename nodeHolderType, typename nodeCacheType,
    typename nodeIndexType, typename edgeCacheType, typename pathType>
class idDijkstra {
public:
    struct djScratch_t {
        short prevIndex;
        std::uint16_t costAndVisited;

        int Cost() const {
            return costAndVisited & 0x7FFFu;
        }

        bool Visited() const {
            return (costAndVisited & 0x8000u) != 0;
        }

        void SetCost(const int cost) {
            costAndVisited = static_cast<std::uint16_t>(
                (costAndVisited & 0x8000u) | (cost & 0x7FFF));
        }

        void SetVisited(const bool visited) {
            if (visited) {
                costAndVisited |= 0x8000u;
            } else {
                costAndVisited &= 0x7FFFu;
            }
        }
    };

    idDijkstra()
        : lastStartNode(-1) {
    }

    bool TracePath(
        const nodeHolderType& nodeHolder,
        nodeIndexType startNode,
        nodeIndexType destNode,
        const djScratch_t* scratchBuff,
        pathType& path);

    bool FindShortestPaths(
        const nodeHolderType& nodeHolder,
        nodeIndexType startNode,
        const nodeIndexType* destNodes,
        int numDestNodes,
        const edgeCacheType* edges,
        djScratch_t* scratchBuff,
        int skipFlags,
        int requiredFlags);

    int lastStartNode;
};

static_assert(sizeof(typename idDijkstra<int, int,
        idIndex<short, idRecoveredInvalidIndex>, int, int>::djScratch_t) == 4,
    "Recovered idDijkstra scratch ABI changed");
static_assert(sizeof(idDijkstra<int, int,
        idIndex<short, idRecoveredInvalidIndex>, int, int>) == 4,
    "Recovered idDijkstra ABI changed");

#include "gamelib/animstack/animweb/dijkstra_impl.h"
