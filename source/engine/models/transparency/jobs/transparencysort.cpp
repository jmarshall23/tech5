#include "models/transparency/jobs/transparencysort.h"

#include <algorithm>
#include <cstring>
#include <vector>

namespace {

int QuadIndex(const float encoded) {
    std::uint32_t bits;
    std::memcpy(&bits, &encoded, sizeof(bits));
    return static_cast<int>(bits & 0x7FFFu);
}

void EncodeQuadIndex(float& destination, const int index) {
    const std::uint32_t bits = static_cast<std::uint32_t>(index) & 0x7FFFu;
    std::memcpy(&destination, &bits, sizeof(bits));
}

void WriteQuadIndices(std::uint16_t* indices, const int quad) {
    const std::uint16_t base = static_cast<std::uint16_t>(quad * 4);
    indices[0] = base;
    indices[1] = static_cast<std::uint16_t>(base + 2);
    indices[2] = static_cast<std::uint16_t>(base + 3);
    indices[3] = base;
    indices[4] = static_cast<std::uint16_t>(base + 3);
    indices[5] = static_cast<std::uint16_t>(base + 1);
}

} // namespace

int TransparencyTriIndGen(const transSortParms_t* parms,
    const int quadOffset) {
    if (parms == nullptr || parms->sortResult == nullptr
        || parms->quadDepths == nullptr || parms->indices == nullptr
        || quadOffset < 0) {
        return 0;
    }
    const int count = (std::min)(
        parms->sortResult->numSortedQuads - quadOffset,
        parms->maxIndices / 6);
    for (int index = 0; index < (std::max)(0, count); ++index) {
        WriteQuadIndices(parms->indices + index * 6,
            QuadIndex(parms->quadDepths[quadOffset + index]));
    }
    return (std::max)(0, count);
}

int TransparencyEmissiveTriIndGen(const transSortParms_t* parms,
    const int quadOffset) {
    if (parms == nullptr || parms->sortResult == nullptr
        || parms->quadDepths == nullptr || parms->emissiveQuads == nullptr
        || parms->indices2 == nullptr || quadOffset < 0) {
        return 0;
    }
    const int count = (std::min)(
        parms->sortResult->numSortedQuads - quadOffset,
        parms->maxIndices / 6);
    int emitted = 0;
    for (int index = 0; index < (std::max)(0, count)
            && (emitted + 1) * 6 <= parms->maxIndices2; ++index) {
        const int quad = QuadIndex(parms->quadDepths[quadOffset + index]);
        if (parms->emissiveQuads[quad] == 0) continue;
        WriteQuadIndices(parms->indices2 + emitted * 6, quad);
        ++emitted;
    }
    parms->sortResult->numEmissiveQuads = emitted;
    return emitted;
}

int TransparencySortQuads(const transSortParms_t* parms) {
    if (parms == nullptr || parms->sortResult == nullptr
        || parms->quadDepths == nullptr || parms->segmentInfo == nullptr) {
        return 0;
    }

    struct quad_t {
        float depth;
        int sourceIndex;
        bool emissive;
    };
    std::vector<quad_t> quads;
    int allocatedVertices = 0;
    int emissiveCount = 0;
    for (int segment = 0; segment < parms->numSegmentAllocations; ++segment) {
        const transSortSegmentInfo_t& info = parms->segmentInfo[segment];
        const int used = (std::max)(0,
            (std::min)(info.quadsUsed, info.quadsAllocated));
        allocatedVertices += info.quadsAllocated * 4;
        for (int index = 0; index < used; ++index) {
            const int source = info.segmentOffset + index;
            quads.push_back({ parms->quadDepths[source], source,
                info.emissivePass });
            if (info.emissivePass) ++emissiveCount;
        }
    }

    if (parms->collapse) {
        for (int index = 0; index < static_cast<int>(quads.size()); ++index) {
            const quad_t& quad = quads[index];
            if (index != quad.sourceIndex && parms->verts != nullptr) {
                std::memmove(parms->verts + index * 4,
                    parms->verts + quad.sourceIndex * 4,
                    sizeof(idTransparencyVert) * 4);
            }
            parms->quadDepths[index] = quad.depth;
            if (parms->emissiveQuads != nullptr) {
                parms->emissiveQuads[index] = quad.emissive ? 1 : 0;
            }
            quads[index].sourceIndex = index;
        }
        allocatedVertices = static_cast<int>(quads.size()) * 4;
    } else if (parms->emissiveQuads != nullptr) {
        for (const quad_t& quad : quads) {
            parms->emissiveQuads[quad.sourceIndex] = quad.emissive ? 1 : 0;
        }
    }

    if (parms->sort) {
        quads.erase(std::remove_if(quads.begin(), quads.end(),
            [](const quad_t& quad) { return quad.depth <= 0.0f; }), quads.end());
        std::stable_sort(quads.begin(), quads.end(),
            [](const quad_t& left, const quad_t& right) {
                return left.depth > right.depth;
            });
    }
    for (int index = 0; index < static_cast<int>(quads.size()); ++index) {
        EncodeQuadIndex(parms->quadDepths[index], quads[index].sourceIndex);
    }

    parms->sortResult->numSortedQuads = static_cast<int>(quads.size());
    parms->sortResult->numCollapsedVerts = allocatedVertices;
    parms->sortResult->numEmissiveQuads = emissiveCount;
    return parms->sortResult->numSortedQuads;
}
