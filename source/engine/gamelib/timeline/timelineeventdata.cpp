#include "gamelib/timeline/timelineeventdata.h"

tlEventData_t::tlEventData_t()
    : time(0)
    , duration(0)
    , type(TL_EVENT_NONE)
    , anim()
    , useAnimPos(false)
    , sound(nullptr)
    , worldPos(0.0f, 0.0f, 0.0f)
    , worldRot(0.0f, 0.0f, 0.0f)
    , keyName(TL_KEY_INVALID)
    , keyValue()
    , keyAnimData()
    , activateStart(true)
    , activateEnd(false)
    , env(nullptr) {
}
