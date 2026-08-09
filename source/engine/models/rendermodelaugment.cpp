#include "models/rendermodelaugment.h"

idRenderModelAugmentOutline::idRenderModelAugmentOutline() {
    g.isAugment = 1;
    g.addAlways = 1;
}

bool idRenderModelAugmentOutline::CommitSubclass() {
    return idRenderModel::CommitSubclass();
}
