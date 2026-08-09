#pragma once

#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

#include <cstdint>
#include <cstring>

// Recovered from tungsten.exe type information. These are the common result
// records shared by CM and GameLib; keeping one definition prevents the two
// libraries from drifting at their ABI boundary.
enum contactType_t : int {
    CONTACT_NONE = 0,
    CONTACT_EDGE = 1,
    CONTACT_MODELVERTEX = 2,
    CONTACT_TRMVERTEX = 3,
    CONTACT_SPHERE = 4
};

enum contactFlag_t : int {
    CONTACT_FLAG_NONE = 0,
    CONTACT_FLAG_SUBMODEL_NOT_RESIDENT = 1,
    CONTACT_FLAG_STEPMOVE_ONSOLID = 2,
    CONTACT_FLAG_STEPMOVE_ONGROUND = 4,
    CONTACT_FLAG_CAR_TO_CAR_COLLISION = 8,
    CONTACT_FLAG_OUTSIDE_LARGEST_SUPPORT_TRIANGLE = 16,
    CONTACT_FLAG_SLIDEMOVE_FINISHED = 32
};

struct contactInfo_t {
    contactType_t type;
    idVec3 point;
    idVec3 normal;
    float dist;
    float separation;
    int contentFlags;
    int surfaceFlags;
    int surfaceType;
    int modelFeature;
    int trmFeature;
    int entityNum;
    int physicsId;
    int bodyId;
    int selfId;
    std::uint8_t flags;
    std::uint8_t surfaceColor[3];
};

struct trace_t {
    float fraction;
    idVec3 endpos;
    idMat3 endAxis;
    contactInfo_t c;
};

struct contactsResult_t {
    int numContacts;
    int pad[3];
    contactInfo_t contacts[12];

    // Recovered from engine/cm/jobs/collisionresults.h. The dump copies each
    // 76-byte contact; memcpy is the exact scalar PC spelling of that loop.
    void CopyFrom(const contactsResult_t& other) {
        numContacts = other.numContacts;
        const int copyCount = numContacts < 12 ? numContacts : 12;
        if (copyCount > 0) {
            std::memcpy(contacts, other.contacts,
                static_cast<std::size_t>(copyCount) * sizeof(contactInfo_t));
        }
    }
};

struct clipResult_t {
    int numVerts;
    int numIndices;
    int pad[2];
    idVec3 verts[32];
    std::int16_t indices[264];
};

static_assert(sizeof(contactInfo_t) == 76,
    "Recovered contactInfo_t ABI changed");
static_assert(sizeof(trace_t) == 128, "Recovered trace_t ABI changed");
static_assert(sizeof(contactsResult_t) == 928,
    "Recovered contactsResult_t ABI changed");
static_assert(sizeof(clipResult_t) == 928,
    "Recovered clipResult_t ABI changed");
