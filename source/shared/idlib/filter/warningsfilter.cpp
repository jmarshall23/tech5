#include "warningsfilter.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <new>
#include <regex>
#include <string>

namespace {

std::mutex filterMutex;

struct filterConfig_t {
    const mgWarningsFilter* owner;
    bool enabled;
};

filterConfig_t filterConfigs[8] = {};

bool& EnabledFor(const mgWarningsFilter* owner) {
    for (filterConfig_t& config : filterConfigs) {
        if (config.owner == owner) return config.enabled;
    }
    for (filterConfig_t& config : filterConfigs) {
        if (config.owner == nullptr) {
            config.owner = owner;
            config.enabled = true;
            return config.enabled;
        }
    }
    return filterConfigs[0].enabled;
}

bool DecodeJSONString(const char* objectBegin, const char* objectEnd,
        const char* key, std::string& result) {
    const std::string needle = std::string("\"") + key + "\"";
    const char* keyPosition = std::search(objectBegin, objectEnd,
        needle.begin(), needle.end());
    if (keyPosition == objectEnd) return false;
    const char* cursor = keyPosition + needle.size();
    while (cursor < objectEnd && *cursor != ':') ++cursor;
    if (cursor == objectEnd) return false;
    while (++cursor < objectEnd && (*cursor == ' ' || *cursor == '\t'
            || *cursor == '\r' || *cursor == '\n')) {}
    if (cursor == objectEnd || *cursor != '"') return false;
    ++cursor;
    result.clear();
    while (cursor < objectEnd && *cursor != '"') {
        if (*cursor == '\\' && cursor + 1 < objectEnd) {
            ++cursor;
            switch (*cursor) {
                case 'n': result.push_back('\n'); break;
                case 'r': result.push_back('\r'); break;
                case 't': result.push_back('\t'); break;
                default: result.push_back(*cursor); break;
            }
        } else {
            result.push_back(*cursor);
        }
        ++cursor;
    }
    return cursor < objectEnd;
}

} // namespace

warningfilter_t::warningfilter_t() : reg{} {}

warningfilter_t::warningfilter_t(const warningfilter_t& other)
    : pattern(other.pattern), owner(other.owner), reg{} {
    if (other.reg.value != nullptr) {
        try {
            reg.value = new std::regex(pattern.c_str(),
                std::regex_constants::extended);
        } catch (const std::regex_error&) {
            reg.value = nullptr;
        }
    }
}

warningfilter_t::~warningfilter_t() {
    delete static_cast<std::regex*>(reg.value);
}

warningfilter_t& warningfilter_t::operator=(const warningfilter_t& other) {
    if (this == &other) return *this;
    delete static_cast<std::regex*>(reg.value);
    reg = {};
    pattern = other.pattern;
    owner = other.owner;
    if (other.reg.value != nullptr) {
        try {
            reg.value = new std::regex(pattern.c_str(),
                std::regex_constants::extended);
        } catch (const std::regex_error&) {
            reg.value = nullptr;
        }
    }
    return *this;
}

mgWarningsFilter::mgWarningsFilter() : filters{}, init(false) {
    filters.granularity = 16;
    EnabledFor(this) = true;
}

mgWarningsFilter::~mgWarningsFilter() {
    Clear();
    for (filterConfig_t& config : filterConfigs) {
        if (config.owner == this) config = {};
    }
}

bool mgWarningsFilter::EnsureCapacity(const int amount) {
    if (amount <= filters.size) return true;
    int newSize = filters.size == 0 ? filters.granularity : filters.size;
    while (newSize < amount) newSize += filters.granularity;
    warningfilter_t* const replacement = new (std::nothrow)
        warningfilter_t[newSize];
    if (replacement == nullptr) return false;
    for (int index = 0; index < filters.num; ++index) {
        replacement[index] = filters.list[index];
    }
    delete[] filters.list;
    filters.list = replacement;
    filters.size = newSize;
    return true;
}

bool mgWarningsFilter::AddFilter(const char* patternText,
        const char* ownerText) {
    if (patternText == nullptr || *patternText == '\0') return false;
    std::regex* compiled = nullptr;
    try {
        compiled = new std::regex(patternText, std::regex_constants::extended);
    } catch (const std::regex_error&) {
        return false;
    }

    std::lock_guard<std::mutex> lock(filterMutex);
    if (!EnsureCapacity(filters.num + 1)) {
        delete compiled;
        return false;
    }
    warningfilter_t& filter = filters.list[filters.num++];
    filter.pattern = patternText;
    filter.owner = ownerText == nullptr ? "" : ownerText;
    filter.reg.re_nsub = 0;
    filter.reg.value = compiled;
    init = true;
    return true;
}

int mgWarningsFilter::RemoveOwner(const char* ownerText) {
    const char* const safeOwner = ownerText == nullptr ? "" : ownerText;
    std::lock_guard<std::mutex> lock(filterMutex);
    int removed = 0;
    for (int index = 0; index < filters.num;) {
        if (std::strcmp(filters.list[index].owner.c_str(), safeOwner) != 0) {
            ++index;
            continue;
        }
        for (int move = index + 1; move < filters.num; ++move) {
            filters.list[move - 1] = filters.list[move];
        }
        filters.list[filters.num - 1] = warningfilter_t();
        --filters.num;
        ++removed;
    }
    return removed;
}

void mgWarningsFilter::Clear() {
    std::lock_guard<std::mutex> lock(filterMutex);
    delete[] filters.list;
    filters.list = nullptr;
    filters.num = 0;
    filters.size = 0;
    init = false;
}

bool mgWarningsFilter::IsFiltered(const char* warning, idStr* matchedOwner) const {
    if (warning == nullptr || !EnabledFor(this)) return false;
    std::lock_guard<std::mutex> lock(filterMutex);
    for (int index = 0; index < filters.num; ++index) {
        const warningfilter_t& filter = filters.list[index];
        const std::regex* const expression =
            static_cast<const std::regex*>(filter.reg.value);
        if (expression != nullptr && std::regex_search(warning, *expression)) {
            if (matchedOwner != nullptr) *matchedOwner = filter.owner;
            return true;
        }
    }
    return false;
}

const warningfilter_t* mgWarningsFilter::GetFilter(const int index) const {
    return index >= 0 && index < filters.num ? filters.list + index : nullptr;
}

void mgWarningsFilter::SetEnabled(const bool value) {
    EnabledFor(this) = value;
}

bool mgWarningsFilter::IsEnabled() const {
    return EnabledFor(this);
}

int mgWarningsFilter::LoadJSONText(const char* json) {
    if (json == nullptr) return 0;
    int loaded = 0;
    const char* cursor = json;
    while ((cursor = std::strchr(cursor, '{')) != nullptr) {
        const char* const end = std::strchr(cursor + 1, '}');
        if (end == nullptr) break;
        std::string patternText;
        std::string ownerText;
        if (DecodeJSONString(cursor, end, "pattern", patternText)) {
            DecodeJSONString(cursor, end, "owner", ownerText);
            if (AddFilter(patternText.c_str(), ownerText.c_str())) ++loaded;
        }
        cursor = end + 1;
    }
    return loaded;
}

bool mgWarningsFilter::LoadJSONFile(const char* filename) {
    if (filename == nullptr) return false;
    FILE* file = nullptr;
    if (fopen_s(&file, filename, "rb") != 0 || file == nullptr) return false;
    std::fseek(file, 0, SEEK_END);
    const long length = std::ftell(file);
    std::fseek(file, 0, SEEK_SET);
    if (length < 0 || length > 16 * 1024 * 1024) {
        std::fclose(file);
        return false;
    }
    std::string contents(static_cast<std::size_t>(length), '\0');
    const std::size_t read = contents.empty() ? 0
        : std::fread(&contents[0], 1, contents.size(), file);
    std::fclose(file);
    return read == contents.size() && LoadJSONText(contents.c_str()) > 0;
}

mgWarningsFilter warningsFilter;
