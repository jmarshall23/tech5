#include "idlib/sys/sys_utils.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

const char* Sys_GetOSUserName() {
    static char userName[64] = {};
    DWORD length = static_cast<DWORD>(sizeof(userName));
    if (!GetUserNameA(userName, &length)) {
        userName[0] = '\0';
    }
    return userName;
}

const char* Sys_GetMachineName() {
    static char machineName[64] = {};
    DWORD length = static_cast<DWORD>(sizeof(machineName));
    if (!GetComputerNameA(machineName, &length)) {
        machineName[0] = '\0';
    }
    return machineName;
}

