#include "gamelib/physics/physics_dynamicbase.h"

#include "gamelib/physics/clip.h"
#include "gamelib/physics/clipmodel.h"

#include <algorithm>
#include <cstring>

void GameLib_ActivateContactPhysics(idPhysics* physics);
void GameLib_DrawPhysicsVelocity(const idVec3& origin,
    const idVec3& linearVelocity, const idVec3& angularVelocity,
    float angularScale);

idPhysics_DynamicBase::idPhysics_DynamicBase()
    : idPhysics()
    , clipMask(0)
    , gravityVector(0.0f, 0.0f, -1066.0f)
    , gravityNormal(0.0f, 0.0f, -1.0f)
    , contacts(4)
    , contactPhysicsIds(4)
    , waterLevel(0.0f)
    , waterViscosity(0.0f) {
}

idPhysics_DynamicBase::~idPhysics_DynamicBase() {
    contacts.Clear();
    contactPhysicsIds.Clear();
}

void idPhysics_DynamicBase::SetClipMask(const int mask, const int id) {
    (void)id;
    clipMask = mask;
}

const idBounds* idPhysics_DynamicBase::GetAbsBounds(const int id) {
    const idClipModel* const model = GetClipModel(id);
    if (model != nullptr) {
        return &model->GetAbsBounds();
    }
    static const idBounds empty{{idVec3(0.0f, 0.0f, 0.0f),
        idVec3(0.0f, 0.0f, 0.0f)}};
    return &empty;
}

void idPhysics_DynamicBase::ClipTranslation(trace_t* const results,
    const idVec3* const translation, const idClipModel* const model) {
    if (results == nullptr) {
        return;
    }
    const idClipModel* const clipModel = model != nullptr
        ? model : GetClipModel(0);
    if (clip == nullptr || clipModel == nullptr || translation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    const idVec3& start = clipModel->GetOrigin();
    clip->Translation(results, start, start + *translation, clipModel,
        clipModel->GetAxis(), clipMask, GetEntityNumber(), false,
        "idPhysics_DynamicBase::ClipTranslation");
}

void idPhysics_DynamicBase::SetGravity(const idVec3* const gravity) {
    if (gravity == nullptr) {
        return;
    }
    gravityVector = *gravity;
    gravityNormal = gravityVector;
    if (gravityNormal.NormalizeFast() == 0.0f) {
        gravityNormal.Zero();
    }
}

void idPhysics_DynamicBase::SetWaterLevel(const float level, const int id) {
    (void)id;
    waterLevel = (std::max)(0.0f, (std::min)(1.0f, level));
}

float idPhysics_DynamicBase::GetWaterLevel(const int id) {
    (void)id;
    return waterLevel;
}

void idPhysics_DynamicBase::SetWaterViscosity(const float viscosity,
    const int id) {
    (void)id;
    waterViscosity = (std::max)(0.0f, viscosity);
}

float idPhysics_DynamicBase::GetWaterViscosity(const int id) {
    (void)id;
    return waterViscosity;
}

const contactInfo_t* idPhysics_DynamicBase::GetContact(const int index) {
    return index >= 0 && index < contacts.Num() ? &contacts[index] : nullptr;
}

void idPhysics_DynamicBase::ClearContacts() {
    for (int index = 0; index < contacts.Num(); ++index) {
        idPhysics* const other = idPhysics::GetPhysicsForId(
            contacts[index].physicsId);
        if (other != nullptr && other != this) {
            other->RemoveContactPhysics(this);
        }
    }
    contacts.Clear();
}

void idPhysics_DynamicBase::AddContactPhysics(idPhysics* const physics) {
    if (physics == nullptr || physics == this) {
        return;
    }
    const int id = physics->GetPhysicsId();
    for (int index = 0; index < contactPhysicsIds.Num(); ++index) {
        if (contactPhysicsIds[index] == id) {
            return;
        }
    }
    contactPhysicsIds.Append(id);
}

void idPhysics_DynamicBase::RemoveContactPhysics(idPhysics* const physics) {
    if (physics == nullptr) {
        return;
    }
    const int id = physics->GetPhysicsId();
    for (int index = contactPhysicsIds.Num() - 1; index >= 0; --index) {
        if (contactPhysicsIds[index] == id) {
            contactPhysicsIds.RemoveIndexFast(index);
        }
    }
}

idPhysics* idPhysics_DynamicBase::GetContactPhysics(const int index) {
    if (index < 0 || index >= contactPhysicsIds.Num()) {
        return nullptr;
    }
    return idPhysics::GetPhysicsForId(contactPhysicsIds[index]);
}

void idPhysics_DynamicBase::ActivateContactPhysics() {
    for (int index = contactPhysicsIds.Num() - 1; index >= 0; --index) {
        idPhysics* const physics = idPhysics::GetPhysicsForId(
            contactPhysicsIds[index]);
        if (physics == nullptr) {
            contactPhysicsIds.RemoveIndexFast(index);
            continue;
        }
        GameLib_ActivateContactPhysics(physics);
    }
}

bool idPhysics_DynamicBase::HasGroundContacts() {
    for (int index = 0; index < contacts.Num(); ++index) {
        if (contacts[index].normal.Dot(-gravityNormal) > 0.0f) {
            return true;
        }
    }
    return false;
}

bool idPhysics_DynamicBase::IsGroundEntity(const int entityNumber_) {
    for (int index = 0; index < contacts.Num(); ++index) {
        if (contacts[index].entityNum == entityNumber_ &&
            contacts[index].normal.Dot(gravityNormal) < -0.1f) {
            return true;
        }
    }
    return false;
}

bool idPhysics_DynamicBase::IsGroundClipModel(const int entityNumber_,
    const int bodyId) {
    for (int index = 0; index < contacts.Num(); ++index) {
        if (contacts[index].entityNum == entityNumber_ &&
            contacts[index].bodyId == bodyId &&
            contacts[index].normal.Dot(gravityNormal) < -0.98480773f) {
            return true;
        }
    }
    return false;
}

void idPhysics_DynamicBase::AddContactPhysicsForContacts() {
    for (int index = 0; index < contacts.Num(); ++index) {
        idPhysics* const physics = idPhysics::GetPhysicsForId(
            contacts[index].physicsId);
        if (physics != nullptr && physics != this) {
            physics->AddContactPhysics(this);
        }
    }
}

void idPhysics_DynamicBase::AddGroundContacts(const idClipModel* const model,
    const int maxContacts) {
    if (clip == nullptr || model == nullptr || maxContacts <= 0) {
        return;
    }
    contactsResult_t results{};
    clip->Contacts(&results, model->GetOrigin(), gravityNormal, 0.25f,
        model, model->GetAxis(), clipMask, GetEntityNumber(),
        "idPhysics_DynamicBase::AddGroundContacts");
    const int count = (std::min)(results.numContacts, maxContacts);
    for (int index = 0; index < count; ++index) {
        contacts.Append(results.contacts[index]);
        UpdateCollisionResidency(results.contacts[index]);
    }
    AddContactPhysicsForContacts();
}

bool idPhysics_DynamicBase::IsOutsideWorld() {
    if (clip == nullptr) {
        return false;
    }
    const idBounds& world = clip->GetWorldBounds();
    const idBounds* const object = GetAbsBounds(-1);
    return (*object)[1].x < world[0].x - 1024.0f ||
        (*object)[1].y < world[0].y - 1024.0f ||
        (*object)[1].z < world[0].z - 1024.0f ||
        (*object)[0].x > world[1].x + 1024.0f ||
        (*object)[0].y > world[1].y + 1024.0f ||
        (*object)[0].z > world[1].z + 1024.0f;
}

void idPhysics_DynamicBase::DrawVelocity(const int id,
    const float linearScale, const float angularScale) const {
    idVec3 linear;
    idVec3 angular;
    const_cast<idPhysics_DynamicBase*>(this)->GetLinearVelocity(&linear, id);
    const_cast<idPhysics_DynamicBase*>(this)->GetAngularVelocity(&angular, id);
    linear = linear * linearScale;
    const idVec3* const origin =
        const_cast<idPhysics_DynamicBase*>(this)->GetOrigin(id);
    if (origin != nullptr) {
        GameLib_DrawPhysicsVelocity(*origin, linear, angular, angularScale);
    }
}
