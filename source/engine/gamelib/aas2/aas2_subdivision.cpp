#include "gamelib/aas2/aas2_local.h"

bool idAAS2Local::GetAreaCells(const int areaNumber, const int subdivisionSize,
    int* const subdivisionX, int* const subdivisionY) const {
  if (file == nullptr || areaNumber <= 0 || subdivisionSize <= 0) {
    return false;
  }

  const idBounds bounds = file->AreaBounds(areaNumber);

  *subdivisionX = static_cast<int>(bounds[1].x - bounds[0].x) /
      subdivisionSize + 1;
  *subdivisionY = static_cast<int>(bounds[1].y - bounds[0].y) /
      subdivisionSize + 1;
  return true;
}

bool idAAS2Local::WorldPosToCellPos(const int areaNumber,
    const int subdivisionSize, const idVec3& origin,
    int* const subdivisionX, int* const subdivisionY) const {
  if (file == nullptr || areaNumber <= 0 || subdivisionSize <= 0) {
    return false;
  }

  const idBounds bounds = file->AreaBounds(areaNumber);

  *subdivisionX = static_cast<int>(
      (origin.x - bounds[0].x) / static_cast<float>(subdivisionSize));
  *subdivisionY = static_cast<int>(
      (origin.y - bounds[0].y) / static_cast<float>(subdivisionSize));
  return true;
}

bool idAAS2Local::CellPosToWorldPos(const int areaNumber,
    const int subdivisionSize, const int subdivisionX,
    const int subdivisionY, idVec3& worldPosition,
    const bool findZ) const {
  (void)findZ;
  if (file == nullptr || areaNumber <= 0) {
    return false;
  }

  const idBounds bounds = file->AreaBounds(areaNumber);

  worldPosition.x = bounds[0].x + subdivisionSize * subdivisionX;
  worldPosition.y = bounds[0].y + subdivisionSize * subdivisionY;
  worldPosition.z = bounds[1].z;
  return true;
}
