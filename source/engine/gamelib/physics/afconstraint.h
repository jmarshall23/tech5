#pragma once

#include "gamelib/physics/afbody.h"
#include "gamelib/physics/clip.h"
#include "idlib/text/atomicstring.h"

#include <cstdint>
#include <cstddef>

class idDeclTable;
class idPhysics_AF;
class idRotation;
class idSerializer;

enum constraintType_t : int {
    CONSTRAINT_INVALID = 0,
    CONSTRAINT_FIXED = 1,
    CONSTRAINT_BALLANDSOCKETJOINT = 2,
    CONSTRAINT_UNIVERSALJOINT = 3,
    CONSTRAINT_HINGE = 4,
    CONSTRAINT_HINGESTEERING = 5,
    CONSTRAINT_SLIDER = 6,
    CONSTRAINT_CYLINDRICALJOINT = 7,
    CONSTRAINT_PLANE = 9,
    CONSTRAINT_SPRING = 10,
    CONSTRAINT_CONTACT = 11,
    CONSTRAINT_FRICTION = 12,
    CONSTRAINT_CONELIMIT = 13,
    CONSTRAINT_PYRAMIDLIMIT = 14,
    CONSTRAINT_SUSPENSION = 15,
    CONSTRAINT_WEEBLE = 16
};

class alignas(16) idAFConstraint {
public:
    struct constraintFlags_s {
        std::uint8_t reserved : 3;
        std::uint8_t isZero : 1;
        std::uint8_t isPrimary : 1;
        std::uint8_t noCollision : 1;
        std::uint8_t frameConstraint : 1;
        std::uint8_t allowPrimary : 1;
    };

    idAFConstraint(const char* name = nullptr,
        constraintType_t type = CONSTRAINT_INVALID,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    virtual ~idAFConstraint();

    static void* operator new(std::size_t size);
    static void operator delete(void* pointer) noexcept;

    virtual void SetBody1(idAFBody*);
    virtual void SetBody2(idAFBody*);
    virtual void DebugDraw();
    virtual void Translate(const idVec3&);
    virtual void Rotate(const idRotation&);
    virtual void GetCenter(idVec3&) const;
    virtual void IssueCollisionQueries();
    virtual void CancelCollisionQueries();
    virtual void Serialize(idSerializer*);
    virtual void Evaluate(const idPhysics_AF*, float);
    virtual void ApplyFriction(float);

    void InitSize(int size);

    alignas(16) constraintType_t type;
    idAtomicString name;
    idAFBody* body1;
    idAFBody* body2;
    idPhysics_AF* physics;
    idStaticSpatialVec lm;
    idSpatialMat J1;
    idSpatialMat J2;
    idStaticSpatialVec c1;
    idStaticSpatialVec c2;
    idStaticSpatialVec lo;
    idStaticSpatialVec hi;
    idStaticSpatialVec e;
    idAFConstraint* boxConstraint;
    int boxIndex[6];
    float boxScale[6];
    idSpatialMat invI;
    idSpatialMat J;
    int firstIndex;
    constraintFlags_s fl;
};

class alignas(16) idAFConstraint_Fixed : public idAFConstraint {
public:
    idAFConstraint_Fixed(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    void SetBody1(idAFBody*) override;
    void SetBody2(idAFBody*) override;
    void Rotate(const idRotation&) override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void InitOffset();

    idVec3 offset;
    idMat3 relAxis;
    bool shouldClamp;
};

class idAFConstraint_ConeLimit;
class idAFConstraint_PyramidLimit;
class idAFConstraint_BallAndSocketJointFriction;

class alignas(16) idAFConstraint_BallAndSocketJoint
    : public idAFConstraint {
public:
    idAFConstraint_BallAndSocketJoint(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    ~idAFConstraint_BallAndSocketJoint() override;
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void ApplyFriction(float) override;
    void SetAnchor(const idVec3& worldPosition);
    void SetWorldPosition(const idVec3& worldPosition);
    float GetFriction() const;
    void SetNoLimit();
    void SetConeLimit(const idVec3& coneAxis, float coneAngle,
        const idVec3& body1Axis);
    void SetPyramidLimit(const idVec3& pyramidAxis,
        const idVec3& baseAxis, float angle1, float angle2,
        const idVec3& body1Axis);

    idVec3 anchor1;
    idVec3 anchor2;
    float friction;
    idAFConstraint_ConeLimit* coneLimit;
    idAFConstraint_PyramidLimit* pyramidLimit;
    idAFConstraint_BallAndSocketJointFriction* fc;
};

class alignas(16) idAFConstraint_BallAndSocketJointFriction
    : public idAFConstraint {
public:
    explicit idAFConstraint_BallAndSocketJointFriction(
        idAFConstraint_BallAndSocketJoint* joint = nullptr);
    bool Add(idPhysics_AF*, float invTimeStep);
    idAFConstraint_BallAndSocketJoint* joint;
};

class idAFConstraint_UniversalJointFriction;

class alignas(16) idAFConstraint_UniversalJoint : public idAFConstraint {
public:
    idAFConstraint_UniversalJoint(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    ~idAFConstraint_UniversalJoint() override;
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void ApplyFriction(float) override;
    void SetAnchor(const idVec3& worldPosition);
    void SetShafts(const idVec3& cardanShaft1,
        const idVec3& cardanShaft2);
    float GetFriction() const;
    void SetNoLimit();
    void SetConeLimit(const idVec3& coneAxis, float coneAngle,
        const idVec3& body1Axis);
    void SetPyramidLimit(const idVec3& pyramidAxis,
        const idVec3& baseAxis, float angle1, float angle2,
        const idVec3& body1Axis);

    idVec3 anchor1;
    idVec3 anchor2;
    idVec3 shaft1;
    idVec3 shaft2;
    idVec3 axis1;
    idVec3 axis2;
    float friction;
    idAFConstraint_ConeLimit* coneLimit;
    idAFConstraint_PyramidLimit* pyramidLimit;
    idAFConstraint_UniversalJointFriction* fc;
};

class alignas(16) idAFConstraint_UniversalJointFriction
    : public idAFConstraint {
public:
    explicit idAFConstraint_UniversalJointFriction(
        idAFConstraint_UniversalJoint* joint = nullptr);
    bool Add(idPhysics_AF*, float invTimeStep);
    void Evaluate(const idPhysics_AF*, float) override;
    idAFConstraint_UniversalJoint* joint;
};

class idAFConstraint_HingeFriction;
class idAFConstraint_HingeSteering;

class alignas(16) idAFConstraint_Hinge : public idAFConstraint {
public:
    idAFConstraint_Hinge(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    ~idAFConstraint_Hinge() override;
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void ApplyFriction(float) override;
    void SetAnchor(const idVec3& worldPosition);
    void SetAxis(const idVec3& axis);
    float GetFriction() const;
    float GetAngle() const;
    void SetNoLimit();
    void SetLimit(float angle1, float angle2, float epsilon);

    idVec3 anchor1;
    idVec3 anchor2;
    idVec3 axis1;
    idVec3 axis2;
    idMat3 initialAxis;
    float friction;
    idAFConstraint_ConeLimit* coneLimit;
    idAFConstraint_HingeSteering* steering;
    idAFConstraint_HingeFriction* fc;
};

class alignas(16) idAFConstraint_HingeFriction : public idAFConstraint {
public:
    explicit idAFConstraint_HingeFriction(
        idAFConstraint_Hinge* hinge = nullptr);
    bool Add(idPhysics_AF*, float invTimeStep);
    idAFConstraint_Hinge* hinge;
};

class idAFConstraint_HingeSteering : public idAFConstraint {
public:
    explicit idAFConstraint_HingeSteering(
        idAFConstraint_Hinge* hinge = nullptr);
    bool Add(idPhysics_AF*, float invTimeStep);
    idAFConstraint_Hinge* hinge;
    float steerAngle;
    float steerSpeed;
    float epsilon;
};

class alignas(16) idAFConstraint_Slider : public idAFConstraint {
public:
    idAFConstraint_Slider(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    void SetAxis(const idVec3&);
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    idVec3 axis;
    idVec3 offset;
    idMat3 relAxis;
};

class idAFConstraint_Spring : public idAFConstraint {
public:
    idAFConstraint_Spring(const char* name = nullptr,
        idAFBody* body1 = nullptr, idAFBody* body2 = nullptr);
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void SetAnchor(const idVec3& anchor1, const idVec3& anchor2);
    void SetSpring(float stretch, float compress, float damping,
        float restLength);
    void SetLimit(float minLength, float maxLength);
    idVec3 anchor1;
    idVec3 anchor2;
    float kstretch;
    float kcompress;
    float damping;
    float restLength;
    float minLength;
    float maxLength;
};

class idAFConstraint_ContactFriction;

class alignas(16) idAFConstraint_Contact : public idAFConstraint {
public:
    idAFConstraint_Contact();
    ~idAFConstraint_Contact() override;
    void GetCenter(idVec3&) const override;
    void DebugDraw() override;
    void ApplyFriction(float) override;
    void Setup(idAFBody* body1, idAFBody* body2,
        const contactInfo_t&, float separation, float invTimeStep);
    contactInfo_t contact;
    float separation;
    idAFConstraint_ContactFriction* fc;
};

class alignas(16) idAFConstraint_ContactFriction
    : public idAFConstraint {
public:
    explicit idAFConstraint_ContactFriction(
        idAFConstraint_Contact* contact = nullptr);
    bool Add(idPhysics_AF*, float invTimeStep);
    idAFConstraint_Contact* cc;
};

class alignas(16) idAFConstraint_ConeLimit : public idAFConstraint {
public:
    idAFConstraint_ConeLimit();
    void Setup(idAFBody*, idAFBody*, const idVec3& coneAnchor,
        const idVec3& coneAxis, float coneAngle,
        const idVec3& body1Axis);
    bool Add(idPhysics_AF*, float invTimeStep);
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void DebugDraw() override;
    idVec3 coneAnchor;
    idVec3 coneAxis;
    idVec3 body1Axis;
    float cosAngle;
    float sinHalfAngle;
    float cosHalfAngle;
    float epsilon;
};

class alignas(16) idAFConstraint_PyramidLimit : public idAFConstraint {
public:
    idAFConstraint_PyramidLimit();
    void Setup(idAFBody*, idAFBody*, const idVec3& pyramidAnchor,
        const idVec3& pyramidAxis, const idVec3& baseAxis,
        float angle1, float angle2, const idVec3& body1Axis);
    bool Add(idPhysics_AF*, float invTimeStep);
    void Translate(const idVec3&) override;
    void Rotate(const idRotation&) override;
    void DebugDraw() override;
    idVec3 pyramidAnchor;
    idMat3 pyramidBasis;
    idVec3 body1Axis;
    float cosAngle[2];
    float sinHalfAngle[2];
    float cosHalfAngle[2];
    float epsilon;
};

class alignas(16) idAFConstraint_Suspension : public idAFConstraint {
public:
    idAFConstraint_Suspension();
    void Setup(const char* name, idAFBody*, const idVec3& localOrigin,
        idClip*, idClipModel*, int clipMask, float radius);
    void SetSuspension(float up, float down, float compress,
        float damping);
    int GetContactEntity() const;
    void Translate(const idVec3&) override;
    void IssueCollisionQueries() override;
    void CancelCollisionQueries() override;
    void DebugDraw() override;
    void Evaluate(const idPhysics_AF*, float) override;
    void Serialize(idSerializer*) override;

    idVec3 localOrigin;
    float suspensionUp;
    float suspensionDown;
    float suspensionCompress;
    float suspensionDamping;
    const idDeclTable* friction_longitudinal;
    const idDeclTable* friction_lateral;
    float frictionLatMultiplier;
    float frictionLongMultiplier;
    idClip* clip;
    idClipModel* wheelModel;
    float wheelRadius;
    int clipMask;
    idVec3 cgLocation;
    float steerAngle;
    bool motorEnabled;
    float motorForce;
    float motorVelocity;
    idClipQuery traceQuery;
    float traceFraction;
    idVec3 traceEndPos;
    idVec3 traceNormal;
    idVec3 tracePoint;
    int traceSurfaceFlags;
    int traceEntityNum;
    float wheelVelocity;
    float wheelAngle;
    float lastWheelHeight;
    float lastMotorVelocity;
    float lastTorque;
    float lastGrip;
    bool lastOnGround;
    bool limitLateralGrip;
    float lateralSlip;
    float longitudinalSlip;
    float debugSpringForce;
    idVec3 debugv1;
    idVec3 debugv2;
    idVec3 debugv3;
    float debugf1;
    float debugf2;
    float debugf3;
    float debugf4;
};

class idAFConstraint_Line : public idAFConstraint {};
class idAFConstraint_CylindricalJoint : public idAFConstraint {};

class alignas(16) idAFConstraint_Plane : public idAFConstraint {
public:
    idVec3 anchor1;
    idVec3 anchor2;
    idVec3 planeNormal;
};

class alignas(16) idAFConstraint_Weeble : public idAFConstraint {
public:
    idVec3 up;
    bool enabled;
};

static_assert(sizeof(idAFConstraint::constraintFlags_s) == 1,
    "Recovered AF constraint flags ABI changed");
