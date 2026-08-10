#pragma once

#include "../../shared/idlib/containers/array.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/text/str.h"

#include <cstdint>

struct leaderboardDefinition_t;

enum leaderboardDisplayError_t : int {
    LEADERBOARD_DISPLAY_ERROR_NONE = 0,
    LEADERBOARD_DISPLAY_ERROR_FAILED = 1,
    LEADERBOARD_DISPLAY_ERROR_NOT_ONLINE = 2,
    LEADERBOARD_DISPLAY_ERROR_NOT_RANKED = 3,
    LEADERBOARD_DISPLAY_ERROR_MAX = 4
};

enum leaderboardFilterMode_t : int {
    LEADERBOARD_FILTER_OVERALL = 0,
    LEADERBOARD_FILTER_MYSCORE = 1,
    LEADERBOARD_FILTER_FRIENDS = 2
};

class idLeaderboardCallback {
public:
    struct row_t {
        bool hasAttachment;
        std::int64_t attachmentID;
        idStr name;
        std::int64_t rank;
        idArray<std::int64_t, 16> columns;
        std::uint64_t user_id;
    };
};

class idLBRowBlock {
public:
    idLBRowBlock();

    int lastTime;
    int startIndex;
    idList<idLeaderboardCallback::row_t, 5> rows;
};

class idLBCache {
public:
    idLBCache();
    bool Scroll(int amount);
    idLBRowBlock* FindFreeRowBlock();
    void Reset();

    idLBRowBlock rowBlocks[5];
    const leaderboardDefinition_t* def;
    leaderboardFilterMode_t filter;
    const leaderboardDefinition_t* pendingDef;
    leaderboardFilterMode_t pendingFilter;
    bool requestingRows;
    bool loadingNewLeaderboard;
    int numRowsInLeaderboard;
    int entryIndex;
    int rowOffset;
    int localIndex;
    leaderboardDisplayError_t errorCode;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLeaderboardCallback::row_t) == 192,
    "Recovered leaderboard row ABI changed");
static_assert(sizeof(idLBRowBlock) == 24,
    "Recovered leaderboard row block ABI changed");
static_assert(sizeof(idLBCache) == 160,
    "Recovered leaderboard cache ABI changed");
#endif
