#pragma once

#include "models/rendermodel.h"

class idRenderModelAugmentOutline : public idRenderModel {
public:
    idRenderModelAugmentOutline();
    ~idRenderModelAugmentOutline() override = default;

    bool CommitSubclass() override;
};
