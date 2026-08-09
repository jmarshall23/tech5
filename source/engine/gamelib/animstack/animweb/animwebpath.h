#pragma once

#include "idlib/index.h"
#include "idlib/text/str.h"

#include <cstdint>
#include <utility>

// idAnimWebPath has no storage beyond its recovered idStr base.
class idAnimWebPath : public idStr {
public:
    using idStr::idStr;
    using idStr::operator=;
};

// The owning idDeclAnimWeb declaration is not compile-locked yet. This tag
// retains the recovered two-byte node-index representation without importing
// that malformed generated declaration into GameLib's active boundary.
enum class idAnimWebInvalidNodeIndex_t : int {
    invalid = -1
};

using idAnimWebNodeIndex = idIndex<short, idAnimWebInvalidNodeIndex_t>;

struct idAnimWebRoute {
    idAnimWebNodeIndex path[32];
    int num;
    int cost;

    // Materialized in the authoritative animwebpath.h dump.
    void Invert() {
        for (int index = 0; index < num / 2; ++index) {
            std::swap(path[index], path[num - index - 1]);
        }
    }

    // Materialized in the authoritative animwebpath.h dump. A shared prefix
    // node is consumed so concatenated routes do not duplicate their join.
    void AppendPath(const idAnimWebRoute& other) {
        int first = 0;
        if (num > 0) {
            while (first < other.num
                    && path[num - 1].Get() == other.path[first].Get()) {
                ++first;
            }
        }
        while (first < other.num && num < 32) {
            path[num++] = other.path[first++];
        }
        cost += other.cost;
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAnimWebPath) == 32,
    "Recovered idAnimWebPath ABI changed");
static_assert(sizeof(idAnimWebNodeIndex) == 2,
    "Recovered AnimWeb node index ABI changed");
static_assert(sizeof(idAnimWebRoute) == 72,
    "Recovered idAnimWebRoute ABI changed");
#endif
