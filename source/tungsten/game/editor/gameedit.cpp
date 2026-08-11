#include "game/editor/gameedit.h"

#include <algorithm>
#include <cmath>

namespace {
idGameEditServices defaultGameEditServices;
idGameEditServices* activeGameEditServices = &defaultGameEditServices;

bool SameVector(const idVec3& left, const idVec3& right) {
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

float Dot(const idVec3& left, const idVec3& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

float Length(const idVec3& value) {
    return std::sqrt(Dot(value, value));
}

float SnapCoordinate(const float value, const int gridSize) {
    if (gridSize <= 0) return std::floor(value);
    return std::floor(value / gridSize + 0.5f) * gridSize;
}
}

void idDragEntity::SetServices(idGameEditServices* services) {
    activeGameEditServices = services == nullptr
        ? &defaultGameEditServices : services;
}

idGameEditServices& idDragEntity::Services() {
    return *activeGameEditServices;
}

// EA 0x82BDC690
bool idEditEntities::ZoomEntity(const idVec3& cameraPosition,
        const bool push) {
    if (selectedEntities.IsEmpty() || !dragging ||
            selectedEntities[0] == nullptr) {
        return false;
    }
    idVec3 currentOrigin;
    if (!Services().GetEntityOrigin(selectedEntities[0], currentOrigin)) {
        return false;
    }
    idVec3 direction = push
        ? cameraPosition - currentOrigin : currentOrigin - cameraPosition;
    if (direction.NormalizeFast() == 0.0f) return false;
    const idVec3 newOrigin = currentOrigin + direction * 10.0f;
    Services().SetEntityOrigin(selectedEntities[0], newOrigin);
    Services().UpdateEntityMap(selectedEntities[0]);
    lastDragPos = newOrigin - cameraPosition;
    return true;
}

// EA 0x82BDC888
void idEditEntities::ResetDragging() {
    if (dragging && !selectedEntities.IsEmpty() &&
            selectedEntities[0] != nullptr) {
        Services().UpdateEditingDialog(selectedEntities[0]);
        if (Services().GetEditorMode() == 4) {
            Services().UpdateParticleTool();
        }
    }
    dragging = false;
}

// EA 0x82BDC948
void idEditEntities::EditSelected() {
    dragging = false;
    if (!selectedEntities.IsEmpty() && selectedEntities[0] != nullptr) {
        Services().ShowEditingDialog(selectedEntities[0]);
    }
}

// EA 0x82BDC978
void idEditEntities::RemoveSelectedEntity(idEntity* entity) {
    selectedEntities.Remove(entity);
}

// EA 0x82BDCA00
void idEditEntities::ClearSelectedEntities() {
    for (int index = 0; index < selectedEntities.Num(); ++index) {
        if (selectedEntities[index] != nullptr) {
            Services().SetEntitySelected(selectedEntities[index], false);
        }
    }
    selectedEntities.ClearFree();
}

// EA 0x82BDCAA0
bool idEditEntities::EntityIsSelectable(idEntity* entity, idVec4* color,
        idStr* text, idStr* type) {
    if (entity == nullptr) return false;
    int matchedClass = -1;
    for (int index = 0; index < selectableEntityClasses.Num(); ++index) {
        const idSelectedTypeInfo& candidate = selectableEntityClasses[index];
        if (candidate.entityMustExistInMapFile &&
                !Services().IsEntityInMap(entity)) {
            continue;
        }
        if (Services().IsEntityType(entity, candidate.typeInfo)) {
            matchedClass = index;
            if (text != nullptr && type != nullptr) {
                *text = candidate.textKey;
                *type = candidate.typeKey;
            }
            break;
        }
    }
    if (matchedClass < 0) return false;

    if (color != nullptr) {
        const bool selected = selectedEntities.FindIndex(entity) >= 0;
        const idColor* source = &idColor::colorGreen;
        if (selected) source = &idColor::colorRed;
        else if (matchedClass == 1) source = &idColor::colorYellow;
        else if (matchedClass == 2) source = &idColor::colorBlue;
        color->Set(source->r, source->g, source->b, source->a);
    }
    return true;
}

// EA 0x82BDCC88
void idDragEntity::Update(idPlayer* player) {
    Services().UpdateDragEntity(this, player);
}

// EA 0x82BDD798
void idDragEntity::DeleteSelected() {
    if (selected.IsValid()) Services().DeleteSpawnEntity(selected.GetSpawnId());
    selected.Invalidate();
    physicsId = -1;
}

// EA 0x82BDD830
idEntity* idEditEntities::FindEntity(const idVec3& origin,
        const idVec3& direction, const idEntity* skip) {
    idList<idEntity*, 5> entities(0);
    Services().GetSpawnedEntities(entities);
    idEntity* result = nullptr;
    float nearestScale = 1.0f;
    const idVec3 ray = direction * 4096.0f;
    for (int index = 0; index < entities.Num(); ++index) {
        idEntity* entity = entities[index];
        if (entity == nullptr || entity == skip ||
                !EntityIsSelectable(entity)) {
            continue;
        }
        idBounds bounds;
        if (!Services().GetEntityBounds(entity, bounds)) continue;
        bounds[0] = bounds[0] - idVec3(16.0f, 16.0f, 16.0f);
        bounds[1] = bounds[1] + idVec3(16.0f, 16.0f, 16.0f);
        float scale = 0.0f;
        if (bounds.RayIntersection(origin, ray, scale) &&
                scale >= 0.0f && scale < nearestScale) {
            result = entity;
            nearestScale = scale;
        }
    }
    return result;
}

// EA 0x82BDD9E0
bool idEditEntities::UpdateSelected(const idVec3& origin,
        const idVec3& direction, const idEntity* skip) {
    if (selectedEntities.IsEmpty() || selectedEntities[0] == nullptr) {
        return false;
    }
    if (Services().GetGameMilliseconds() - dragTime < 50) return true;

    idEntity* selected = selectedEntities[0];
    idVec3 newOrigin;
    if (Services().MouseDragEnabled()) {
        idVec3 entityOrigin;
        if (!Services().GetEntityOrigin(selected, entityOrigin)) return false;
        const idVec3 normal = direction * -1.0f;
        const float denominator = Dot(normal, direction);
        if (std::fabs(denominator) < 1.0e-6f) return false;
        const float scale = Dot(normal, entityOrigin - origin) / denominator;
        const idVec3 intersection = origin + direction * scale;
        idVec3 delta = intersection - lastDragPos;
        if (SameVector(delta, idVec3(0.0f, 0.0f, 0.0f))) return false;
        if (dragAxis == -1) {
            const float absolute[3] = {
                std::fabs(delta.x), std::fabs(delta.y), std::fabs(delta.z)};
            dragAxis = absolute[1] > absolute[0] ? 1 : 0;
            if (absolute[2] > absolute[dragAxis]) dragAxis = 2;
        }
        if (dragAxis != 0) delta.x = 0.0f;
        if (dragAxis != 1) delta.y = 0.0f;
        if (dragAxis != 2) delta.z = 0.0f;
        newOrigin = entityOrigin + delta;
        lastViewDir = direction;
        lastDragPos = intersection;
    } else {
        if (!dragging) {
            if (FindEntity(origin, direction, skip) != selected) return false;
            idVec3 entityOrigin;
            if (!Services().GetEntityOrigin(selected, entityOrigin)) return false;
            lastDragPos = entityOrigin - origin;
        }
        dragging = true;
        dragAxis = 0;
        newOrigin = origin + direction * Length(lastDragPos);
    }

    const int gridSize = Services().GetGridSize();
    newOrigin.x = SnapCoordinate(newOrigin.x, gridSize);
    newOrigin.y = SnapCoordinate(newOrigin.y, gridSize);
    newOrigin.z = SnapCoordinate(newOrigin.z, gridSize);
    Services().SetEntityOrigin(selected, newOrigin);
    Services().UpdateEntityMap(selected);
    return true;
}

// EA 0x82BDDFE8
idDragEntity::idDragEntity()
    : selected()
    , physicsId(-1)
    , bodyId(0)
    , localPhysicsPoint(0.0f, 0.0f, 0.0f)
    , localPlayerPoint(0.0f, 0.0f, 0.0f) {
}

// EA 0x82BDE1B0
idEditEntities::idEditEntities()
    : nextSelectTime(0)
    , lastSelectResult(false)
    , selectableEntityClasses(0)
    , selectedEntities(0)
    , dragging(false)
    , dragTime(0)
    , dragAxis(-1)
    , lastViewDir(0.0f, 0.0f, 0.0f)
    , lastDragPos(0.0f, 0.0f, 0.0f) {
}

// EA 0x82BDE308
void idEditEntities::AddSelectedEntity(idEntity* entity) {
    if (entity == nullptr) return;
    Services().SetEntitySelected(entity, true);
    selectedEntities.AddUnique(entity);
}

// EA 0x82BDE388
void idEditEntities::DisplayEntities() {
    selectableEntityClasses.ClearFree();
    Services().PopulateSelectableEntityClasses(selectableEntityClasses);
    Services().DisplayEntities(this);
}

// EA 0x82BE05B0
bool idEditEntities::SelectEntity(const idVec3& origin,
        const idVec3& direction, const idEntity* skip) {
    dragging = false;
    if (Services().GetEditorMode() == 0 ||
            selectableEntityClasses.IsEmpty()) {
        return false;
    }
    const int gameTime = Services().GetGameMilliseconds();
    if (gameTime < nextSelectTime) return lastSelectResult;

    lastSelectResult = false;
    nextSelectTime = gameTime + 300;
    idEntity* entity = FindEntity(origin, direction, skip);
    ClearSelectedEntities();
    if (entity == nullptr) {
        Services().UpdateParticleTool();
        return false;
    }
    if (!EntityIsSelectable(entity)) {
        Services().UpdateEditingDialog(entity);
        return false;
    }

    AddSelectedEntity(entity);
    Services().PrintSelectedEntity(entity);
    dragging = Services().MouseDragEnabled();
    dragTime = gameTime;
    idVec3 entityOrigin;
    if (!Services().GetEntityOrigin(entity, entityOrigin)) return false;
    if (!Services().MouseDragEnabled()) {
        lastDragPos = entityOrigin - origin;
    } else {
        const idVec3 normal = direction * -1.0f;
        const float denominator = Dot(normal, direction);
        if (std::fabs(denominator) < 1.0e-6f) return false;
        const float scale = Dot(normal, entityOrigin - origin) / denominator;
        lastDragPos = origin + direction * scale;
    }
    lastSelectResult = true;
    dragAxis = -1;
    Services().UpdateEditingDialog(entity);
    return true;
}

// EA 0x82BE08C0
void idEditEntities::DuplicateSelected(const idVec3& origin,
        const idVec3& direction) {
    dragging = false;
    if (selectedEntities.IsEmpty() || selectedEntities[0] == nullptr ||
            Services().GetEditorMode() == 4) {
        return;
    }
    idEntity* duplicate = Services().DuplicateEntity(selectedEntities[0],
        origin, direction, Services().GetCloneDistance());
    if (duplicate == nullptr) return;
    ClearSelectedEntities();
    AddSelectedEntity(duplicate);
    Services().ShowEditingDialog(duplicate);
}
