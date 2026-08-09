#include "gamelib/physics/physics.h"

#include "idlib/lib_print.h"

#include <cstring>

idPhysics* idPhysics::hash[1024] = {};
int idPhysics::currentPhysicsId = 0;

idPhysics::idPhysics()
    : type(PHYSICS_INVALID),
      physicsId(++currentPhysicsId),
      entityNumber(0x1FFF),
      nextInHash(nullptr),
      clip(nullptr),
      callbacks(nullptr),
      residencyQuery{0},
      collisionResidency(RESIDENCY_NOT_TESTED) {
    Link();
}

idPhysics::~idPhysics() {
    Unlink();
    nextInHash = nullptr;
    clip = nullptr;
    callbacks = nullptr;
}

void idPhysics::InitPhysics(idClip* clip_, idPhysicsCallbacks* callbacks_,
        const int entityNumber_) {
    clip = clip_;
    callbacks = callbacks_;
    entityNumber = entityNumber_;
}

void idPhysics::ClearHash() {
    std::memset(hash, 0, sizeof(hash));
    currentPhysicsId = 0;
}

idPhysics* idPhysics::GetPhysicsForId(const int physicsId_) {
    if (physicsId_ == -1) {
        return nullptr;
    }

    for (idPhysics* item = hash[physicsId_ & 1023]; item != nullptr;
            item = item->nextInHash) {
        if (item->physicsId == physicsId_) {
            return item;
        }
    }
    return nullptr;
}

void idPhysics::UpdateCollisionResidency(const contactInfo_t& contact) {
    if ((contact.flags & CONTACT_FLAG_SUBMODEL_NOT_RESIDENT) != 0) {
        collisionResidency = RESIDENCY_NO;
    }
}

void idPhysics::Unlink() {
    idPhysics** link = &hash[physicsId & 1023];
    while (*link != nullptr) {
        if (*link == this && (*link)->physicsId == physicsId) {
            *link = nextInHash;
            return;
        }
        link = &(*link)->nextInHash;
    }
}

void idPhysics::Link() {
    if (physicsId != -1 && GetPhysicsForId(physicsId) != nullptr) {
        idLibPrint::Printf(" duplicate physicsId = %d\n", physicsId);
        do {
            physicsId = currentPhysicsId++;
        } while (physicsId != -1 && GetPhysicsForId(physicsId) != nullptr);
    }

    const int bucket = physicsId & 1023;
    nextInHash = hash[bucket];
    hash[bucket] = this;
}

void OutputPhysicsHash_f(const idCmdArgs&) {
    for (int bucket = 0; bucket < 1024; ++bucket) {
        if (idPhysics::hash[bucket] == nullptr) {
            continue;
        }
        idLibPrint::Printf("%d:", bucket);
        for (idPhysics* item = idPhysics::hash[bucket]; item != nullptr;
                item = item->nextInHash) {
            idLibPrint::Printf(" (%d) 0x%p", item->physicsId, item);
        }
        idLibPrint::Printf("\n");
    }
}

bool idPhysics::IsInNonResidentCollisionArea(const bool assumeNonResident) {
    // The recovered routine first consumes/submits an asynchronous idClip
    // residency query. That queue is owned by clip.cpp and will be connected
    // when that authoritative unit is reconstructed. Its final state test is
    // independent and is retained here.
    return collisionResidency == RESIDENCY_NO
        || (collisionResidency == RESIDENCY_NOT_TESTED && assumeNonResident);
}
