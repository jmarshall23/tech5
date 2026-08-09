#include "decls/declmapinfo.h"

idDeclInfoTemplate<idDeclMapInfo> idDeclMapInfo::resourceList(
    "mapInfo", "idDeclMapInfo", "tdef");

idDeclMapInfo::idDeclMapInfo()
    : prettyMapName(), discNumber(-1), dlcId(0), loadingVideos(16) {
}

idDeclInfo* idDeclMapInfo::GetDeclInfo() const { return &resourceList; }
