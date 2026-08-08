#pragma once

#include <cstdint>

#include "../text/str.h"

std::uint64_t Sys_CurrentSystemTime();
char* Sys_TimeStampToLogFormat(int timeStamp);
char* Sys_TimeStampToStr(int timeStamp, bool padded);
char* Sys_DateStr(bool padded);
idStr Sys_SecToStr(int seconds);
