#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/langdict.h"

class idDeclMapInfo : public idDeclTypeInfo {
public:
    class loadingVideos_t {
    public:
        idAtomicString layerMask;
        idAtomicString videoFile;
    };

    idDeclMapInfo();
    idDeclInfo* GetDeclInfo() const override;

    idStrId prettyMapName;
    int discNumber;
    int dlcId;
    idList<loadingVideos_t, 5> loadingVideos;

    static idDeclInfoTemplate<idDeclMapInfo> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclMapInfo::loadingVideos_t) == 8,
    "Recovered map loading-video ABI changed");
static_assert(sizeof(idDeclMapInfo) == 92,
    "Recovered map-info declaration ABI changed");
#endif
