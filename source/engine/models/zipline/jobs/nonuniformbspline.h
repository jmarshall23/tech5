#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3079; PDB kind: enum.
enum __bitmask idNonUniformBSpline<idVec3>::boundary_t : __int32
{
  CLAMPED = 0x1,
  CLOSED = 0x2,
};

// IDA Local Type ordinal 12901; PDB kind: class.
class idCurve_NonUniformBSpline<idVec4> : public idCurve_BSpline<idVec4>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12902.
  virtual ~idCurve_NonUniformBSpline();
  virtual int AddValue(const float, const idVec4 *);
  virtual void RemoveIndex(const int);
  virtual void Clear();
  virtual void SetNumValues(int);
  virtual idVec4 *GetCurrentValue(idVec4 *result, const float);
  virtual idVec4 *GetCurrentFirstDerivative(idVec4 *result, const float);
  virtual idVec4 *GetCurrentSecondDerivative(idVec4 *result, const float);
  virtual bool IsDone(const float);
  virtual float GetLengthForTime(const float);
  virtual float EstimateLengthForTime(const float);
  virtual idCurve<idVec4> *CreateNewCurve();
  virtual void SetBoundaryType(const boundary_t::eType);
  virtual boundary_t::eType GetBoundaryType();
  virtual void SetCloseTime(const float);
  virtual float GetCloseTime();
  virtual int GetOrder();
  virtual void SetOrder(const int);

};

// IDA Local Type ordinal 18169; PDB kind: class.
class idCurve_NonUniformBSpline<idVec3> : public idCurve_BSpline<idVec3>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18170.
  virtual ~idCurve_NonUniformBSpline();
  virtual int AddValue(const float, const idVec3 *);
  virtual void RemoveIndex(const int);
  virtual void Clear();
  virtual void SetNumValues(int);
  virtual idVec3 *GetCurrentValue(idVec3 *result, const float);
  virtual idVec3 *GetCurrentFirstDerivative(idVec3 *result, const float);
  virtual idVec3 *GetCurrentSecondDerivative(idVec3 *result, const float);
  virtual bool IsDone(const float);
  virtual float GetLengthForTime(const float);
  virtual float EstimateLengthForTime(const float);
  virtual idCurve<idVec3> *CreateNewCurve();
  virtual void SetBoundaryType(const boundary_t::eType);
  virtual boundary_t::eType GetBoundaryType();
  virtual void SetCloseTime(const float);
  virtual float GetCloseTime();
  virtual int GetOrder();
  virtual void SetOrder(const int);

};

// IDA Local Type ordinal 18806; PDB kind: class.
class idNonUniformBSpline<idVec3>
{
public:
  float times[512];
  idVec3 values[512];
  int numKnots;
  idNonUniformBSpline<idVec3>::boundary_t boundaryType;
  float closeTime;
  int order;
};

// IDA Local Type ordinal 19672; PDB kind: class.
class idCurve_NonUniformBSpline<idAngles> : public idCurve_BSpline<idAngles>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19673.
  virtual ~idCurve_NonUniformBSpline();
  virtual int AddValue(const float, const idAngles *);
  virtual void RemoveIndex(const int);
  virtual void Clear();
  virtual void SetNumValues(int);
  virtual idAngles *GetCurrentValue(idAngles *result, const float);
  virtual idAngles *GetCurrentFirstDerivative(idAngles *result, const float);
  virtual idAngles *GetCurrentSecondDerivative(idAngles *result, const float);
  virtual bool IsDone(const float);
  virtual float GetLengthForTime(const float);
  virtual float EstimateLengthForTime(const float);
  virtual idCurve<idAngles> *CreateNewCurve();
  virtual void SetBoundaryType(const boundary_t::eType);
  virtual boundary_t::eType GetBoundaryType();
  virtual void SetCloseTime(const float);
  virtual float GetCloseTime();
  virtual int GetOrder();
  virtual void SetOrder(const int);

};
