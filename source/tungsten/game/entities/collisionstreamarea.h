#pragma once

class idEntity;
class idCollisionStreamArea;

class idCollisionStreamAreaServices {
public:
    virtual ~idCollisionStreamAreaServices() = default;
    virtual void UnlinkClip(idCollisionStreamArea&) {}
    virtual int FindStreamArea(idCollisionStreamArea&) const { return -1; }
    virtual int GetSpawnId(const idCollisionStreamArea&) const {
        return 0x1FFF;
    }
    virtual void RegisterStreamAreaEntity(int) {}
    virtual void UnregisterStreamAreaEntity(int) {}
    virtual void AddStreamArea(idCollisionStreamArea&, int) {}
};

class idCollisionStreamArea {
public:
    idCollisionStreamArea();
    virtual ~idCollisionStreamArea();

    static void SetServices(idCollisionStreamAreaServices* services);
    static idCollisionStreamAreaServices& Services();

    void OnActivate(idEntity* activator);
    void Spawn();

    int streamArea;
    int registeredSpawnId;
};
