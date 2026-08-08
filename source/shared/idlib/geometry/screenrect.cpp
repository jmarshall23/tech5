#include "screenrect.h"

void idScreenRect::Clear() {
    x1 = 32000;
    y1 = 32000;
    x2 = -32000;
    y2 = -32000;
}

void idScreenRect::Zero() {
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

