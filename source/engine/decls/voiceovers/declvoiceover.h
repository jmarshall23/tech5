#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/containers/list.h"
#include "idlib/typesafenumber.h"

class idVoiceTrack;
enum millisecondUnique_t : int;

using millisecond_t = idTypesafeNumber<int, millisecondUnique_t>;

class alignas(4) idDeclVoiceOver : public idDeclTypeInfo {
public:
    idDeclVoiceOver();
    ~idDeclVoiceOver() override;

    idDeclInfo* GetDeclInfo() const override;
    unsigned int Size() const override;

    const idVoiceTrack* GetTrack(int index) const;
    millisecond_t GetMaxLength() const;
    bool AddTrack(idVoiceTrack* voiceTrack);

    char nextSampleToPlay;
    idList<const idVoiceTrack*, 65> tracks;

    static idDeclInfoTemplate<idDeclVoiceOver> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclVoiceOver) == 84,
    "Recovered voice-over declaration ABI changed");
#endif
