#include "framework/sourcecontrolwrapper.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

idSourceControlWrapper::idSourceControlWrapper()
    : sc(nullptr), dllHandle(0), loadFailed(true), autoInitAttempt(true) {
}

idSourceControlWrapper::~idSourceControlWrapper() {
    Shutdown();
}

void idSourceControlWrapper::InstallBackend(idSourceControl* const backend,
        const unsigned int moduleHandle) {
    Shutdown();
    sc = backend;
    dllHandle = moduleHandle;
    loadFailed = backend == nullptr;
    autoInitAttempt = false;
}

bool idSourceControlWrapper::Init() {
    autoInitAttempt = true;
    if (sc == nullptr) {
        loadFailed = true;
        return false;
    }
    const bool initialized = sc->IsInitialized() || sc->Init();
    loadFailed = !initialized;
    return initialized;
}

void idSourceControlWrapper::Shutdown() {
    if (sc != nullptr) sc->Shutdown();
    if (dllHandle != 0) ::FreeLibrary(reinterpret_cast<HMODULE>(dllHandle));
    sc = nullptr;
    dllHandle = 0;
    loadFailed = false;
}

void idSourceControlWrapper::SetSilentCheckOut(bool set) { if (Init()) sc->SetSilentCheckOut(set); }
bool idSourceControlWrapper::GetSilentCheckOut() const { return sc != nullptr && sc->GetSilentCheckOut(); }
void idSourceControlWrapper::SetSilentCheckIn(bool set) { if (Init()) sc->SetSilentCheckIn(set); }
bool idSourceControlWrapper::GetSilentCheckIn() const { return sc != nullptr && sc->GetSilentCheckIn(); }
bool idSourceControlWrapper::IsConnected() const { return sc != nullptr && sc->IsConnected(); }
bool idSourceControlWrapper::IsInitialized() const { return sc != nullptr && sc->IsInitialized(); }
int idSourceControlWrapper::CheckOut(const idSourceControlFileList& f) { return Init() ? sc->CheckOut(f) : 0; }
int idSourceControlWrapper::UndoCheckOut(const idSourceControlFileList& f) { return Init() ? sc->UndoCheckOut(f) : 0; }
int idSourceControlWrapper::Import(const idSourceControlFileList& f, bool keep, bool submit, scFileType_t type) { return Init() ? sc->Import(f, keep, submit, type) : 0; }
int idSourceControlWrapper::GetLatest(const idSourceControlFileList& f, bool force) { return Init() ? sc->GetLatest(f, force) : 0; }
int idSourceControlWrapper::CheckIn(const idSourceControlFileList& f, const idStr& c, bool keep) { return Init() ? sc->CheckIn(f, c, keep) : 0; }
int idSourceControlWrapper::Delete(const idSourceControlFileList& f) { return Init() ? sc->Delete(f) : 0; }
int idSourceControlWrapper::UpdateFolder(const char* p) { return Init() ? sc->UpdateFolder(p) : 0; }
scFileStatus_t idSourceControlWrapper::GetFileStatus(const idStr& f) { return Init() ? sc->GetFileStatus(f) : SCF_NOTMANAGED; }
bool idSourceControlWrapper::GetFileVersion(const idStr& f, int& l, int& s) { return Init() && sc->GetFileVersion(f, l, s); }
int idSourceControlWrapper::GetNumCheckOutUsers(const idStr& f) { return Init() ? sc->GetNumCheckOutUsers(f) : 0; }
void idSourceControlWrapper::GetCheckOutUser(const idStr& f, int i, char* u, int n) { if (Init()) sc->GetCheckOutUser(f, i, u, n); else if (u != nullptr && n > 0) u[0] = '\0'; }
void idSourceControlWrapper::GetUsernameForFileVersion(const idStr& f, int v, idStr& u) { if (Init()) sc->GetUsernameForFileVersion(f, v, u); else u.Clear(); }
void idSourceControlWrapper::GetCurrentWorkspace(idSourceControlWorkspace& w) { if (Init()) sc->GetCurrentWorkspace(w); else w = idSourceControlWorkspace(); }
void idSourceControlWrapper::GetAvailableWorkspaces(workspaceList_t& w) { if (Init()) sc->GetAvailableWorkspaces(w); else w.Clear(); }
void idSourceControlWrapper::SetWorkspace(const char* n) { if (Init()) sc->SetWorkspace(n); }
void idSourceControlWrapper::SetWorkspace(idSourceControlWorkspace& w) { if (Init()) sc->SetWorkspace(w); }
bool idSourceControlWrapper::IsWorkspaceValid() { return Init() && sc->IsWorkspaceValid(); }
idStr idSourceControlWrapper::GetUsername() { return Init() ? sc->GetUsername() : idStr(); }
