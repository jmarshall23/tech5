#pragma once

class idEntityInterface;

class idEntityInterfaceObject {
public:
    idEntityInterfaceObject() : lock(nullptr), iface(nullptr) {}
    void* lock;
    idEntityInterface* iface;
};
