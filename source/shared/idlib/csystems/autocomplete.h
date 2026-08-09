#pragma once

#include "../text/cmdargs.h"
#include "../text/str.h"

#include <cstdint>

struct idAutoCompleteStringList {
    idStr* list;
    int num;
    int size;
    std::int16_t granularity;
    std::uint8_t memTag;
    std::uint8_t listStatic;
};

static_assert(
    sizeof(idAutoCompleteStringList) == 16,
    "Recovered idList<idStr, 5> layout changed"
);

// tungsten.exe.h type 12218. idCmdArgs and idList retain their recovered
// Win32 layouts through the active recovered core container layer.
class idAutoComplete {
public:
    idAutoComplete()
        : matchLength(0)
        , currentIndex(-1)
        , suggestions{nullptr, 0, 0, 16, 5, 0} {
    }

    ~idAutoComplete();

    void Append(const idStr& suggestion, int completingArg = -1);

    const char* GetArg(const int index) const {
        return args.Argv(index);
    }

    void Clear() {
        matchLength = 0;
        currentIndex = -1;
        args.Clear();
        ClearSuggestions();
    }

    void SetArgs(const idCmdArgs& newArgs) {
        args = newArgs;
    }

    int GetNumSuggestions() const {
        return suggestions.num;
    }

    const idStr& GetSuggestion(const int index) const {
        return suggestions.list[index];
    }

private:
    int matchLength;
    int currentIndex;
    idCmdArgs args;
    idAutoCompleteStringList suggestions;

    void AppendSuggestion(const idStr& suggestion);
    void ClearSuggestions();
};

static_assert(sizeof(idAutoComplete) == 2332, "idAutoComplete ABI changed");
