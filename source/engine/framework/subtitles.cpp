#include "framework/subtitles.h"

#include "framework/framework_hooks.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

namespace {
const char* const LANGUAGE_ISO_NAMES[idSubtitles::NUM_LANGUAGES] = {
    "", "en", "de", "fr", "es", "it", "pl", "ru", "ja", "he"
};

int LanguageForToken(const std::string& token) {
    for (int language = 0; language < idSubtitles::NUM_LANGUAGES; ++language) {
        if (token == LANGUAGE_ISO_NAMES[language]) {
            return language;
        }
    }
    return -1;
}

bool IsNumber(const std::string& token) {
    if (token.empty()) return false;
    char* end = nullptr;
    std::strtof(token.c_str(), &end);
    return end != token.c_str() && *end == '\0';
}
}

const char* idSubtitles::GetLanguageIsoName(const int language) {
    return language >= 0 && language < NUM_LANGUAGES
        ? LANGUAGE_ISO_NAMES[language] : LANGUAGE_ISO_NAMES[LANGUAGE_UNDEF];
}

bool idSubtitles::ProcessText(const char* const text, const float endTime,
        idList<idPart, 5>* const parts) {
    if (text == nullptr || parts == nullptr) {
        return false;
    }
    parts->Clear();
    idPart part = {0, LANGUAGE_UNDEF, 0.0f, idStr()};
    bool timeMarker = false;

    const char* cursor = text;
    while (*cursor != '\0') {
        if (*cursor != '[') {
            part.phrase.Append(*cursor++);
            continue;
        }
        const char* close = std::strchr(cursor + 1, ']');
        if (close == nullptr) {
            return false;
        }
        std::string token(cursor + 1, close);
        const std::size_t whitespace = token.find_first_of(" \t");
        if (whitespace != std::string::npos) {
            token.resize(whitespace);
        }
        if (IsNumber(token)) {
            if (timeMarker || part.phrase.Length() != 0) {
                parts->Append(part);
                part.phrase.Clear();
            }
            part.startTime = std::strtof(token.c_str(), nullptr);
            timeMarker = true;
        } else {
            const int language = LanguageForToken(token);
            if (language >= 0 && language != part.language) {
                if (part.phrase.Length() != 0) {
                    parts->Append(part);
                    part.phrase.Clear();
                    timeMarker = false;
                }
                part.language = language;
            }
        }
        cursor = close + 1;
    }
    if (timeMarker || part.phrase.Length() != 0) {
        parts->Append(part);
    }
    if (part.phrase.Length() != 0) {
        idPart terminator = {0, LANGUAGE_UNDEF,
            endTime > 0.0f ? endTime : part.startTime + 2.0f, idStr()};
        parts->Append(terminator);
    }
    return true;
}

void idSubtitleSequencer::Start(const char* const text, const float endTime) {
    current = 0;
    idSubtitles::ProcessText(text, endTime, &parts);
}

const char* idSubtitleSequencer::Update(const float newTime,
        const unsigned int languageMask) {
    while (current + 1 < parts.Num()
            && newTime >= parts[current + 1].startTime) {
        ++current;
    }
    if (current < 0 || current >= parts.Num()) {
        return nullptr;
    }
    const idSubtitles::idPart& part = parts[current];
    return newTime > part.startTime
            && (languageMask & (1u << part.language)) != 0
        ? part.phrase.c_str() : nullptr;
}

idSubtitles_VideoOverlay::idSubtitles_VideoOverlay()
    : swf(nullptr), languageMask(0xFFFFFFFFu) {
}

idSubtitles_VideoOverlay::~idSubtitles_VideoOverlay() {
    End();
}

void idSubtitles_VideoOverlay::Start(const char* const videoName,
        const float length) {
    sequencer.Start(videoName, length);
}

void idSubtitles_VideoOverlay::Render(idRenderModelGui* const gui,
        const float time) {
    const char* phrase = sequencer.Update(time, languageMask);
    if (phrase != nullptr && frameworkHooks.drawString != nullptr) {
        frameworkHooks.drawString(gui, 60.0f, 650.0f, phrase,
            0xFFFFFFFFu, 1.0f);
    }
}

void idSubtitles_VideoOverlay::End() {
    swf = nullptr;
    sequencer.parts.Clear();
    sequencer.current = 0;
}
