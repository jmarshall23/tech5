#pragma once

#include "idlib/text/str.h"

#include <cstdint>

struct warningfilter_regex_t {
    unsigned int re_nsub;
    void* value;
};

struct warningfilter_t {
    warningfilter_t();
    warningfilter_t(const warningfilter_t& other);
    ~warningfilter_t();
    warningfilter_t& operator=(const warningfilter_t& other);

    idStr pattern;
    idStr owner;
    warningfilter_regex_t reg;
};

class mgWarningsFilter {
public:
    mgWarningsFilter();
    ~mgWarningsFilter();

    bool AddFilter(const char* pattern, const char* owner = "");
    int RemoveOwner(const char* owner);
    void Clear();
    bool IsFiltered(const char* warning, idStr* owner = nullptr) const;
    bool Filter(const char* warning) const { return IsFiltered(warning); }

    bool LoadJSONFile(const char* filename);
    int LoadJSONText(const char* json);
    int NumFilters() const { return filters.num; }
    const warningfilter_t* GetFilter(int index) const;

    void SetEnabled(bool value);
    bool IsEnabled() const;

private:
    struct recoveredFilterList_t {
        warningfilter_t* list;
        int num;
        int size;
        short granularity;
        unsigned char memTag;
        unsigned char listStatic;
    } filters;
    bool init;

    // Enabled is kept out of the recovered object layout in the .cpp sidecar.
    bool EnsureCapacity(int amount);
};

extern mgWarningsFilter warningsFilter;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(warningfilter_regex_t) == 8,
    "Recovered regex_t facade ABI changed");
static_assert(sizeof(warningfilter_t) == 72,
    "Recovered warningfilter_t ABI changed");
static_assert(sizeof(mgWarningsFilter) == 20,
    "Recovered mgWarningsFilter ABI changed");
#endif
