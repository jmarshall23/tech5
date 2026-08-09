#pragma once

#include "gamelib/physics/physics.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"

class alignas(8) idPhysics_DynamicBase : public idPhysics {
public:
    idPhysics_DynamicBase();
    ~idPhysics_DynamicBase() override;

    void SetClipMask(int mask, int id) override;
    int GetClipMask(int id) override { (void)id; return clipMask; }
    const idBounds* GetAbsBounds(int id) override;
    void ClipTranslation(trace_t* results, const idVec3* translation,
        const idClipModel* model) override;
    void SetGravity(const idVec3* gravity) override;
    const idVec3* GetGravity() override { return &gravityVector; }
    const idVec3* GetGravityNormal() override { return &gravityNormal; }
    void SetWaterLevel(float level, int id) override;
    float GetWaterLevel(int id) override;
    void SetWaterViscosity(float viscosity, int id) override;
    float GetWaterViscosity(int id) override;
    int GetNumContacts() override { return contacts.Num(); }
    const contactInfo_t* GetContact(int index) override;
    void ClearContacts() override;
    void AddContactPhysics(idPhysics* physics) override;
    void RemoveContactPhysics(idPhysics* physics) override;
    int GetNumContactPhysics() override { return contactPhysicsIds.Num(); }
    idPhysics* GetContactPhysics(int index) override;
    void ActivateContactPhysics() override;
    bool HasGroundContacts() override;
    bool IsGroundEntity(int entityNumber) override;
    bool IsGroundClipModel(int entityNumber, int bodyId) override;
    virtual bool IsOutsideWorld();

protected:
    void AddContactPhysicsForContacts();
    void AddGroundContacts(const idClipModel* model, int maxContacts);
    void DrawVelocity(int id, float linearScale, float angularScale) const;

    int clipMask;
    idVec3 gravityVector;
    idVec3 gravityNormal;
    idList<contactInfo_t, 77> contacts;
    idList<int, 77> contactPhysicsIds;
    float waterLevel;
    float waterViscosity;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_DynamicBase) == 120,
    "Recovered idPhysics_DynamicBase ABI changed");
#endif
