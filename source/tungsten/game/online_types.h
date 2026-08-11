#pragma once

enum challengeGameMode_t : int {
    CHALLENGE_MODE_NORMAL = 0,
    CHALLENGE_MODE_COOP = 1,
    CHALLENGE_MODE_DM = 2,
    CHALLENGE_MODE_TDM = 3,
    CHALLENGE_MODE_CTF = 4,
    CHALLENGE_MODE_DOMINATION = 5,
    CHALLENGE_MODE_MAX = 6
};

enum gameType_t : int {
    GAME_TYPE_UNUSED_DEPRECATED = 0,
    GAME_TYPE_COOP = 1,
    GAME_TYPE_PVP = 2
};
