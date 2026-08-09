#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\afconstraint.h
// Recovered logical types: 14
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2471; PDB kind: enum.
enum declAFConstraintType_t : __int32
{
  DECLAF_CONSTRAINT_INVALID = 0x0,
  DECLAF_CONSTRAINT_FIXED = 0x1,
  DECLAF_CONSTRAINT_BALLANDSOCKETJOINT = 0x2,
  DECLAF_CONSTRAINT_UNIVERSALJOINT = 0x3,
  DECLAF_CONSTRAINT_HINGE = 0x4,
  DECLAF_CONSTRAINT_SLIDER = 0x5,
  DECLAF_CONSTRAINT_SPRING = 0x6,
};

// IDA Local Type ordinal 2940; PDB kind: enum.
enum idDeclAF_Constraint::afConstraintLimit_t : __int32
{
  LIMIT_NONE = 0xFFFFFFFF,
  LIMIT_CONE = 0x0,
  LIMIT_PYRAMID = 0x1,
};

// IDA Local Type ordinal 14601; PDB kind: class.
class idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14624.
  virtual ~idAFConstraint();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  __declspec(align(16)) constraintType_t type;
  idAtomicString name;
  idAFBody *body1;
  idAFBody *body2;
  idPhysics_AF *physics;
  idStaticSpatialVec lm;
  idSpatialMat J1;
  idSpatialMat J2;
  idStaticSpatialVec c1;
  idStaticSpatialVec c2;
  idStaticSpatialVec lo;
  idStaticSpatialVec hi;
  idStaticSpatialVec e;
  idAFConstraint *boxConstraint;
  int boxIndex[6];
  float boxScale[6];
  idSpatialMat invI;
  idSpatialMat J;
  int firstIndex;
  idAFConstraint::constraintFlags_s fl;
};

// IDA Local Type ordinal 14615; PDB kind: class.
class __declspec(align(16)) idAFConstraint_Contact : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33731.
  virtual ~idAFConstraint_Contact();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  contactInfo_t contact;
  float separation;
  idAFConstraint_ContactFriction *fc;
};

// IDA Local Type ordinal 14625; PDB kind: struct.
struct idAFConstraint::constraintFlags_s
{
  unsigned __int8 : 3;
  __int8 isZero : 1;
  __int8 isPrimary : 1;
  __int8 noCollision : 1;
  __int8 frameConstraint : 1;
  __int8 allowPrimary : 1;
};

// IDA Local Type ordinal 14656; PDB kind: class.
class __declspec(align(4)) idDeclAF_Constraint
{
public:
  idAtomicString name;
  idAtomicString body1;
  idAtomicString body2;
  declAFConstraintType_t type;
  float friction;
  float stretch;
  float compress;
  float damping;
  float restLength;
  float minLength;
  float maxLength;
  idAFVector anchor;
  idAFVector anchor2;
  idAFVector shaft[2];
  idAFVector axis;
  idDeclAF_Constraint::afConstraintLimit_t limit;
  idAFVector limitAxis;
  float limitAngles[3];
  bool syncConstraint;
};

// IDA Local Type ordinal 21669; PDB kind: class.
class __declspec(align(16)) idAFConstraint_ConeLimit : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21670.
  virtual ~idAFConstraint_ConeLimit();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 coneAnchor;
  idVec3 coneAxis;
  idVec3 body1Axis;
  float cosAngle;
  float sinHalfAngle;
  float cosHalfAngle;
  float epsilon;
};

// IDA Local Type ordinal 21688; PDB kind: class.
class __declspec(align(16)) idAFConstraint_Fixed : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21689.
  virtual ~idAFConstraint_Fixed();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 offset;
  idMat3 relAxis;
  bool shouldClamp;
};

// IDA Local Type ordinal 21764; PDB kind: class.
class idAFConstraint_Line : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21765.
  virtual ~idAFConstraint_Line();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

};

// IDA Local Type ordinal 21844; PDB kind: class.
class __declspec(align(4)) idAFConstraint_Weeble : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21845.
  virtual ~idAFConstraint_Weeble();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 up;
  bool enabled;
};

// IDA Local Type ordinal 21871; PDB kind: class.
class __declspec(align(16)) idAFConstraint_Hinge : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21875.
  virtual ~idAFConstraint_Hinge();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 anchor1;
  idVec3 anchor2;
  idVec3 axis1;
  idVec3 axis2;
  idMat3 initialAxis;
  float friction;
  idAFConstraint_ConeLimit *coneLimit;
  idAFConstraint_HingeSteering *steering;
  idAFConstraint_HingeFriction *fc;
};

// IDA Local Type ordinal 21970; PDB kind: class.
class __declspec(align(16)) idAFConstraint_Plane : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21971.
  virtual ~idAFConstraint_Plane();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 anchor1;
  idVec3 anchor2;
  idVec3 planeNormal;
};

// IDA Local Type ordinal 22048; PDB kind: class.
class idAFConstraint_Spring : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22049.
  virtual ~idAFConstraint_Spring();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 anchor1;
  idVec3 anchor2;
  float kstretch;
  float kcompress;
  float damping;
  float restLength;
  float minLength;
  float maxLength;
};

// IDA Local Type ordinal 22279; PDB kind: class.
class __declspec(align(8)) idAFConstraint_Slider : public idAFConstraint
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22280.
  virtual ~idAFConstraint_Slider();
  virtual void SetBody1(idAFBody *);
  virtual void SetBody2(idAFBody *);
  virtual void DebugDraw();
  virtual void Translate(const idVec3 *);
  virtual void Rotate(const idRotation *);
  virtual void GetCenter(idVec3 *);
  virtual void IssueCollisionQueries();
  virtual void CancelCollisionQueries();
  virtual void Serialize(idSerializer *);
  virtual void Evaluate(const idPhysics_AF *, float);
  virtual void ApplyFriction(float);

  idVec3 axis;
  idVec3 offset;
  idMat3 relAxis;
};
