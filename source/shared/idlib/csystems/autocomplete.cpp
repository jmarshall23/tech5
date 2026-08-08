#include "autocomplete.h"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <new>

namespace {
int ComparePrefixInsensitive(const char* left, const char* right,
    const int count) {
    const unsigned char* safeLeft = reinterpret_cast<const unsigned char*>(
        left == nullptr ? "" : left
    );
    const unsigned char* safeRight = reinterpret_cast<const unsigned char*>(
        right == nullptr ? "" : right
    );
    for (int index = 0; index < count; ++index) {
        const int leftChar = std::tolower(safeLeft[index]);
        const int rightChar = std::tolower(safeRight[index]);
        if (leftChar != rightChar || safeLeft[index] == '\0'
            || safeRight[index] == '\0') {
            return leftChar - rightChar;
        }
    }
    return 0;
}
}

idAutoComplete::~idAutoComplete() {
    ClearSuggestions();
}

void idAutoComplete::ClearSuggestions() {
    if (suggestions.list != nullptr) {
        for (int index = 0; index < suggestions.size; ++index) {
            suggestions.list[index].~idStr();
        }
        std::free(suggestions.list);
    }
    suggestions.list = nullptr;
    suggestions.num = 0;
    suggestions.size = 0;
}

void idAutoComplete::AppendSuggestion(const idStr& suggestion) {
    if (suggestions.num == suggestions.size) {
        const int newSize = suggestions.size + suggestions.granularity;
        idStr* const replacement = static_cast<idStr*>(
            std::malloc(sizeof(idStr) * static_cast<std::size_t>(newSize))
        );
        if (replacement == nullptr) {
            return;
        }

        for (int index = 0; index < newSize; ++index) {
            new (&replacement[index]) idStr();
        }
        for (int index = 0; index < suggestions.num; ++index) {
            replacement[index] = suggestions.list[index];
        }
        if (suggestions.list != nullptr) {
            for (int index = 0; index < suggestions.size; ++index) {
                suggestions.list[index].~idStr();
            }
            std::free(suggestions.list);
        }
        suggestions.list = replacement;
        suggestions.size = newSize;
    }

    suggestions.list[suggestions.num++] = suggestion;
}

void idAutoComplete::Append(
    const idStr& suggestion,
    const int completingArg
) {
    const int argumentIndex = completingArg < 0
        ? args.Argc() - 1
        : completingArg;

    const char* const partial = args.Argv(argumentIndex);
    const int partialLength = static_cast<int>(std::strlen(partial));
    if (partialLength > 0
        && ComparePrefixInsensitive(suggestion.c_str(), partial, partialLength) != 0) {
        return;
    }

    if (args.Argc() == 1 && argumentIndex == 0) {
        AppendSuggestion(suggestion);
        return;
    }

    idStr completed;
    for (int index = 0; index < argumentIndex; ++index) {
        completed.Append(args.Argv(index));
        completed.Append(' ');
    }
    completed.Append(suggestion);
    AppendSuggestion(completed);
}
