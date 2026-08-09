#include "models/skeletalanimation/jobs/md6blend.h"

md6OriginDelta_t::md6OriginDelta_t()
    : time(-1), done(false), fudged(false), pad{} {
    deltaRotation[0] = deltaRotation[1] = deltaRotation[2] = 0.0f;
    deltaRotation[3] = 1.0f;
    deltaScale[0] = deltaScale[1] = deltaScale[2] = deltaScale[3] = 1.0f;
    deltaTranslation[0] = deltaTranslation[1] = 0.0f;
    deltaTranslation[2] = deltaTranslation[3] = 0.0f;
    animRotation[0] = animRotation[1] = animRotation[2] = 0.0f;
    animRotation[3] = 1.0f;
    animScale[0] = animScale[1] = animScale[2] = animScale[3] = 1.0f;
    animTranslation[0] = animTranslation[1] = 0.0f;
    animTranslation[2] = animTranslation[3] = 0.0f;
    jointBounds[0] = jointBounds[1] = jointBounds[2] = 1.0e30f;
    jointBounds[3] = jointBounds[4] = jointBounds[5] = -1.0e30f;
}
