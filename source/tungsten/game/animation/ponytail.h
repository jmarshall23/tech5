#pragma once

class idDeclPonytail;
class idEntity;
class idPonytail;

struct idPonytailInitResult {
    bool usingParentAnimStack = false;
    int attachmentHandle = -1;
};

class idPonytailServices {
public:
    virtual ~idPonytailServices() = default;
    virtual bool InitializePonytail(idPonytail&, idEntity*,
        const idDeclPonytail*, idPonytailInitResult&) = 0;
    virtual void UpdatePonytail(idPonytail&) = 0;
    virtual void RemoveAttachment(idEntity*, int) = 0;
};

class idPonytail {
public:
    idPonytail();
    ~idPonytail();

    void SetDeclaration(const idDeclPonytail* declaration) {
        declPonytail = declaration;
    }
    void SetServices(idPonytailServices* newServices) {
        services = newServices;
    }
    bool Init(idEntity* parentEntity);
    void Update();
    void Shutdown();

    const idDeclPonytail* GetDeclaration() const { return declPonytail; }
    idEntity* GetParent() const { return parent; }
    int GetAttachmentHandle() const { return attachmentHandle; }
    bool IsUsingParentAnimStack() const { return usingParentAnimStack; }
    bool IsInitialized() const { return initialized; }

private:
    const idDeclPonytail* declPonytail;
    idEntity* parent;
    int attachmentHandle;
    bool usingParentAnimStack;
    bool initialized;
    idPonytailServices* services;
};
