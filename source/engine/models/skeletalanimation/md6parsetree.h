#pragma once

#include "idlib/bv/bounds.h"
#include "models/skeletalanimation/jobs/md6blend.h"

class idMD6Model;
class idMD6Node;

// Converts the pointer-based animation tree into the compact postfix command
// stream consumed by idMD6Blend.  The returned count includes OP_END.
int ParseTree(const idMD6Model* model, int previousTime, int currentTime,
    unsigned int ticksPerSecond, idMD6Node* tree,
    md6AnimCommand_t* commands, int maxCommands, idBounds& frameBounds,
    idBounds& translatedBounds, idBounds& normalizedBounds,
    md6OriginDelta_t* originDelta, unsigned short animatorFlags);

