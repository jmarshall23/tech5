#include "decls/declstaticimage.h"

idDeclInfoTemplate<idDeclStaticImage> idDeclStaticImage::resourceList(
    "staticImage", "idDeclStaticImage", "tdef");

idDeclStaticImage::idDeclStaticImage() : fileName("") {
}

idDeclInfo* idDeclStaticImage::GetDeclInfo() const { return &resourceList; }
