#include "presentablecuttable.h"

idPresentableCuttable::idPresentableCuttable(idEntity* newEntity,
        idRenderModel* renderModel)
    : idPresentable(newEntity, renderModel, ENTITYNUM_NONE, nullptr) {
}

