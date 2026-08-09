#pragma once

#include "decls/decltypeinfo.h"

class idDeclStaticImage : public idDeclTypeInfo {
public:
    idDeclStaticImage();
    idDeclInfo* GetDeclInfo() const override;
    idAtomicString fileName;

    static idDeclInfoTemplate<idDeclStaticImage> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclStaticImage) == 68,
    "Recovered static-image declaration ABI changed");
#endif
