#pragma once

#include "../../../shared/idlib/text/str.h"

class idDeclJobRef : public idStr {
public:
    using idStr::idStr;
};

static_assert(sizeof(idDeclJobRef) == sizeof(idStr),
    "Recovered job-declaration reference ABI changed");
