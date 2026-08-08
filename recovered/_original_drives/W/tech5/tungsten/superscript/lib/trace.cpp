
// ========================================================================
// ?Resolve@ssTrace@@AAAXXZ
// EA  : 0x82EE8958
// RVA : 0x00EE8958
// PDB : w:\tech5\tungsten\superscript\lib\trace.cpp
// ========================================================================

void __fastcall ssTrace::Resolve(ssTrace *this)
{
  const ssEntity *v2; // r3
  double v3; // fp12
  double y; // fp7
  double z; // fp6
  double v6; // fp5
  double v7; // fp4
  XGRAPHICS::Compiler *v8; // [sp+50h] [-20h] BYREF
  char v9; // [sp+54h] [-1Ch] BYREF

  if ( !this->resolved )
  {
    gameInterface->GetTraceResults(
      this: gameInterface,
      a2: this->clipQueryId,
      a3: &this->hitFraction,
      a4: (ssVec3_t *)&this->hitNormal,
      a5: (int *)&v8);
    v2 = (const ssEntity *)ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v9, context: v8);
    ssEntity::ssEntity(this: &this->hitEnt, e: v2);
    v3 = (float)(this->length * this->hitFraction);
    this->hitLength = this->length * this->hitFraction;
    y = this->startPos.y;
    z = this->startPos.z;
    v6 = (float)(this->rayDir.z * (float)v3);
    v7 = (float)(this->rayDir.y * (float)v3);
    this->hitPos.x = this->startPos.x + (float)(this->rayDir.x * (float)v3);
    this->hitPos.z = (float)z + (float)v6;
    this->hitPos.y = (float)y + (float)v7;
    this->resolved = true;
  }
}


// ========================================================================
// ??0ssTrace@@QAA@VssVector@@0HVssEntity@@@Z
// EA  : 0x82EE8A20
// RVA : 0x00EE8A20
// PDB : w:\tech5\tungsten\superscript\lib\trace.cpp
// ========================================================================

ssTrace *__fastcall ssTrace::ssTrace(
        ssTrace *this,
        ssVector *_startPos,
        ssVector *_endPos,
        int _contentMask,
        ssEntity *_ignoreEnt)
{
  ssVector *p_endPos; // r30
  double z; // fp4
  double v8; // fp3
  double v9; // fp1
  double v10; // fp13
  double y; // fp5
  idGameSuperInterface *v12; // r3
  double v13; // fp3
  int (__fastcall *TracePoints)(idGameSuperInterface *, const ssVec3_t *, const ssVec3_t *, int, int); // ctr
  double v15; // fp12

  this->startPos = *_startPos;
  p_endPos = &this->endPos;
  this->endPos = *_endPos;
  this->rayDir.x = 0.0;
  this->rayDir.y = 0.0;
  this->rayDir.z = 0.0;
  this->contentMask = _contentMask;
  ssEntity::ssEntity(this: &this->ignoreEnt, e: _ignoreEnt);
  this->resolved = false;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->hitEnt);
  this->hitPos.x = 0.0;
  this->hitPos.y = 0.0;
  this->hitPos.z = 0.0;
  this->hitNormal.x = 0.0;
  this->hitNormal.y = 0.0;
  this->hitNormal.z = 0.0;
  z = this->endPos.z;
  v8 = this->startPos.z;
  v9 = (float)(this->endPos.y - this->startPos.y);
  v10 = (float)(this->endPos.x - this->startPos.x);
  this->rayDir.y = this->endPos.y - this->startPos.y;
  this->rayDir.x = v10;
  this->rayDir.z = (float)z - (float)v8;
  this->length = __fsqrts((float)((float)((float)((float)z - (float)v8) * (float)((float)z - (float)v8))
                                + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
  y = this->rayDir.y;
  v12 = gameInterface;
  v13 = this->rayDir.z;
  TracePoints = gameInterface->TracePoints;
  v15 = __fsqrts((float)((float)(this->rayDir.z * this->rayDir.z)
                       + (float)((float)(this->rayDir.x * this->rayDir.x) + (float)(this->rayDir.y * this->rayDir.y))));
  this->rayDir.x = this->rayDir.x * (float)((float)1.0 / (float)v15);
  this->rayDir.y = (float)y * (float)((float)1.0 / (float)v15);
  this->rayDir.z = (float)v13 * (float)((float)1.0 / (float)v15);
  this->clipQueryId = TracePoints(
                        this: v12,
                        a2: (const ssVec3_t *)this,
                        a3: (const ssVec3_t *)p_endPos,
                        a4: this->contentMask,
                        a5: this->ignoreEnt.spawnId);
  return this;
}

