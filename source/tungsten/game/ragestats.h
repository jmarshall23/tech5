#pragma once

#include <cstdint>

// Retail declarations from w:\tech5\tungsten\game\ragestats.h and the two
// exported symbols in ragestats.cpp.  rageStat_t is defined by
// game/metrics/ragestat.h; keeping it opaque here avoids pulling the complete
// metrics declaration surface into callers of these helpers.

enum rageStat_t : int;
class idLocalUser;

struct pageStats_t {
    std::uint16_t numPages;
    std::uint16_t numVisPages;
    std::uint16_t numTopPages;
    std::uint16_t pad;
};

struct imageStats_t {
    float ME;
    float MSE;
    float PSNR;
    int Max;
};

bool RageStatTypeIsInt(rageStat_t stat);
int GetStatAsInt(idLocalUser& user, rageStat_t stat);

static_assert(sizeof(pageStats_t) == 8, "Recovered pageStats_t layout changed");
static_assert(sizeof(imageStats_t) == 16, "Recovered imageStats_t layout changed");
