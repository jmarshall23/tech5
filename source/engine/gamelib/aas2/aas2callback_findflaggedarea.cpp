#include "gamelib/aas2/aas2callback_findflaggedarea.h"

idAAS2Callback_FindFlaggedArea::idAAS2Callback_FindFlaggedArea(
        const int areaFlag_, const bool set)
    : idAAS2Callback_AvoidLocation()
    , areaFlag(areaFlag_)
    , test(set ? 1 : 0) {
}

idAAS2Callback_FindFlaggedArea::~idAAS2Callback_FindFlaggedArea() = default;

bool idAAS2Callback_FindFlaggedArea::AreaIsGoal(const idAAS2 *aas,
        const int areaNum, const idVec3 *) {
    if (aas == nullptr) {
        return false;
    }
    // The recovered callback ABI supplies a const pointer even though the
    // idAAS2 virtual interface did not mark GetAreaFlags const.
    const int flags = const_cast<idAAS2*>(aas)->GetAreaFlags(areaNum);
    return ((flags & areaFlag) != 0) == (test != 0);
}
