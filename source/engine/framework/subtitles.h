#pragma once

#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idRenderModelGui;
class idSWF;

class idSubtitles {
public:
    enum language_t : int {
        LANGUAGE_UNDEF = 0,
        LANGUAGE_ENGLISH = 1,
        LANGUAGE_GERMAN = 2,
        LANGUAGE_FRENCH = 3,
        LANGUAGE_SPANISH = 4,
        LANGUAGE_ITALIAN = 5,
        LANGUAGE_POLISH = 6,
        LANGUAGE_RUSSIAN = 7,
        LANGUAGE_JAPANESE = 8,
        LANGUAGE_HEBREW = 9,
        NUM_LANGUAGES = 10
    };
    struct idPart {
        int flags;
        int language;
        float startTime;
        idStr phrase;
    };

    static const char* GetLanguageIsoName(int language);
    static bool ProcessText(const char* text, float endTime,
        idList<idPart, 5>* parts);
};

class idSubtitleSequencer {
public:
    idSubtitleSequencer() : current(0) {}
    void Start(const char* text, float endTime);
    const char* Update(float newTime, unsigned int languageMask);

    idList<idSubtitles::idPart, 5> parts;
    int current;
};

// The recovered base contributes only the vptr to this layout.  Renderer/SWF
// ownership is deliberately installed through framework hooks at runtime.
class idSubtitles_VideoOverlay {
public:
    idSubtitles_VideoOverlay();
    virtual ~idSubtitles_VideoOverlay();
    virtual void Start(const char* videoName, float length);
    virtual void Render(idRenderModelGui* gui, float time);
    virtual void End();

    idSWF* swf;
    unsigned int languageMask;
    idSubtitleSequencer sequencer;
};
