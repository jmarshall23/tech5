#pragma once

#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idStaticModel;
struct idImportModel;

// The original generator exposes these two helpers as file-local overloads.
// Keeping portable declarations makes the recovered weld behavior testable.
void BuildRemapTable(idList<int, 5>& remap,
    const idList<idVec3, 5>& vectors, float epsilon);
void BuildRemapTable(idList<int, 5>& remap,
    const idList<idVec2, 5>& vectors, float epsilon);

bool ConvertImportModelToStaticModel(idStaticModel& destination,
    const idImportModel& source, float vertexSlop = 0.01f,
    float texCoordSlop = 0.0001f, bool append = false);

