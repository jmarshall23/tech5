#pragma once

#include "idlib/sourcecontrol.h"

class alignas(4) idSourceControlWrapper : public idSourceControl {
public:
    idSourceControlWrapper();
    ~idSourceControlWrapper() override;

    bool Init() override;
    void Shutdown() override;
    void SetSilentCheckOut(bool set) override;
    bool GetSilentCheckOut() const override;
    void SetSilentCheckIn(bool set) override;
    bool GetSilentCheckIn() const override;
    bool IsConnected() const override;
    bool IsInitialized() const override;
    int CheckOut(const idSourceControlFileList& files) override;
    int UndoCheckOut(const idSourceControlFileList& files) override;
    int Import(const idSourceControlFileList& files, bool keepCheckedOut,
        bool submit, scFileType_t fileType) override;
    int GetLatest(const idSourceControlFileList& files, bool force) override;
    int CheckIn(const idSourceControlFileList& files, const idStr& comment,
        bool keepCheckedOut) override;
    int Delete(const idSourceControlFileList& files) override;
    int UpdateFolder(const char* path) override;
    scFileStatus_t GetFileStatus(const idStr& filename) override;
    bool GetFileVersion(const idStr& filename, int& localVersion,
        int& serverVersion) override;
    int GetNumCheckOutUsers(const idStr& filename) override;
    void GetCheckOutUser(const idStr& filename, int userIndex,
        char* userName, int maxLength) override;
    void GetUsernameForFileVersion(const idStr& filename, int fileVersion,
        idStr& username) override;
    void GetCurrentWorkspace(idSourceControlWorkspace& workspace) override;
    void GetAvailableWorkspaces(workspaceList_t& workspaces) override;
    void SetWorkspace(const char* name) override;
    void SetWorkspace(idSourceControlWorkspace& workspace) override;
    bool IsWorkspaceValid() override;
    idStr GetUsername() override;

    void InstallBackend(idSourceControl* backend, unsigned int moduleHandle = 0);

    idSourceControl* sc;
    unsigned int dllHandle;
    bool loadFailed;
    bool autoInitAttempt;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSourceControlWrapper) == 16,
    "Recovered idSourceControlWrapper ABI changed");
#endif
