
// ========================================================================
// ?InternalPreScore@idCoverQueryAvoid@@EAAXXZ
// EA  : 0x82A8CD68
// RVA : 0x00A8CD68
// PDB : w:\tech5\tungsten\game\ai\cover\coverqueryavoid.cpp
// ========================================================================

void __fastcall idCoverQueryAvoid::InternalPreScore(idCoverQueryAvoid *this)
{
  idPhysics *Physics; // r3

  idAASPosition::Update(
    this: &this->avoidvcPos,
    aas: (idAAS2 *)gameLocal->aasVisCache.aas,
    ent: (idEntity *)this->avoidEnt);
  Physics = idEntity::GetPhysics(this: (idEntity *)this->avoidEnt);
  this->avoidOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
}


// ========================================================================
// ?InternalScoreCover@idCoverQueryAvoid@@EAAMABUcoverCache_t@idCoverQuery@@@Z
// EA  : 0x82A8CDE8
// RVA : 0x00A8CDE8
// PDB : w:\tech5\tungsten\game\ai\cover\coverqueryavoid.cpp
// ========================================================================

float __fastcall idCoverQueryAvoid::InternalScoreCover(
        idCoverQueryAvoid *this,
        const idCoverQuery::coverCache_t *cached)
{
  idAICover *v4; // r29
  double v5; // fp1
  const aas2Cover_t *Origin; // r3
  const aas2Cover_t *v7; // r3
  bool v8; // r30
  idProjectile *v10; // r3
  BOOL v12; // r27
  double v13; // fp30
  idVec3 *p_origin; // r30
  double v15; // fp1
  double v16; // fp21
  double v17; // fp31
  double v18; // fp25
  double v19; // fp22
  const aas2Cover_t *v22; // r3
  double v23; // fp9
  double v24; // fp26
  double v25; // fp7
  double v28; // fp24
  idPhysics *Physics; // r3
  float *v30; // r28
  const aas2Cover_t *v31; // r3
  double v32; // fp29
  double v33; // fp28
  double v34; // fp27
  double v35; // fp30
  double v36; // fp30
  idPhysics *v37; // r3
  float *v38; // r3
  double v39; // fp0
  double v40; // fp13
  double z; // fp0
  double y; // fp13
  double x; // fp12
  const aas2Cover_t *v48; // r3
  int v49; // r10
  int v50; // r9
  int v51; // r8
  int v52; // r7
  int v53; // r6
  const idVec3 *v54; // r5
  const idVec3 *v55; // r4
  int v57; // [sp+8h] [-118h]
  int v58; // [sp+Ch] [-114h]
  int v59; // [sp+10h] [-110h]
  int v60; // [sp+14h] [-10Ch]
  int v61; // [sp+18h] [-108h]
  int v62; // [sp+1Ch] [-104h]
  int v63; // [sp+20h] [-100h]
  int v64; // [sp+24h] [-FCh]
  int v65; // [sp+28h] [-F8h]
  int v66; // [sp+2Ch] [-F4h]
  int v67; // [sp+30h] [-F0h]
  int v68; // [sp+34h] [-ECh]
  int v69; // [sp+38h] [-E8h]
  int v70; // [sp+3Ch] [-E4h]
  int v71; // [sp+40h] [-E0h]
  int v72; // [sp+44h] [-DCh]
  int v73; // [sp+48h] [-D8h]
  int v74; // [sp+4Ch] [-D4h]
  int v75; // [sp+50h] [-D0h]
  int v76; // [sp+58h] [-C8h]
  int v77; // [sp+60h] [-C0h]
  idVec3 v78; // [sp+70h] [-B0h] BYREF
  idVec3 v79; // [sp+80h] [-A0h] BYREF

  v4 = &this->ai->aiVolatile.coverManager.knownCover.list[cached->index];
  if ( (unsigned __int8)idAICover::IsValid(this: v4) != 0 )
  {
    if ( idAICover::IsFullyExposed(this: v4) )
    {
      Origin = idAICover::GetOrigin(this: v4);
      v5 = idCoverQuery::DebugFailed(this, message: "FULLY EXPOSED", origin: &Origin->origin, minLevel: 1);
    }
    else if ( cached->travelTime < (double)this->maxAvoidTime )
    {
      v8 = (_cntlzw(this->avoidEnt->entityNumber - idSpawnId::GetEntityNumber(this: &this->target.spawnId)) & 0x20) != 0;
      _FP28 = 128.0;
      v10 = idProjectile::CastTo(c: (idProjectile *)this->avoidEnt);
      if ( v10 != nullptr )
      {
        _FP0 = (float)((float)128.0 - idProjectile::GetMaxDamageRadius(this: v10));
        __asm { fsel      f28, f0, f1, f31 }
      }
      v12 = v8;
      v13 = 0.5;
      if ( v8 )
        v13 = 0.0;
      p_origin = &this->target.origin;
      v15 = idAICover::AngleToPoint(this: v4, point: &this->target.origin, considerFireOver: false);
      v16 = v15;
      v17 = 1.0;
      if ( v15 < -90.0 || v15 > 60.0 )
      {
        v18 = v13;
      }
      else if ( v15 <= 0.0 )
      {
        v18 = 1.0;
      }
      else
      {
        v18 = (float)((float)((float)((float)((float)60.0 - (float)v15) * (float)((float)1.0 - (float)v13))
                            * (float)0.016666668)
                    + (float)v13);
      }
      v19 = 1.0;
      if ( v12 )
      {
        _FP12 = (float)(this->maxAvoidTime - cached->travelTime);
        __asm { fsel      f11, f12, f13, f0 }
        v19 = (float)((float)1.0 - (float)((float)_FP11 / this->maxAvoidTime));
      }
      v22 = idAICover::GetOrigin(this: v4);
      v23 = (float)(this->target.origin.z - v22->origin.z);
      v24 = 1.0;
      v25 = (float)(this->target.origin.y - v22->origin.y);
      _FP0 = (float)((float)_FP28
                   - (float)__fsqrts((float)((float)((float)(p_origin->x - v22->origin.x)
                                                   * (float)(p_origin->x - v22->origin.x))
                                           + (float)((float)((float)v25 * (float)v25) + (float)((float)v23 * (float)v23)))));
      __asm { fsel      f12, f0, f1, f28 }
      v28 = (float)-(float)((float)((float)((float)1.0 - (float)((float)_FP12 / (float)_FP28))
                                  * (float)((float)1.0 - (float)v18))
                          - (float)1.0);
      if ( v12 )
      {
        Physics = idEntity::GetPhysics(this: this->ai);
        v30 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v31 = idAICover::GetOrigin(this: v4);
        v32 = (float)(v31->origin.y - v30[1]);
        v33 = (float)(v31->origin.z - v30[2]);
        v79.z = v31->origin.z - v30[2];
        v79.y = v32;
        v34 = (float)(v31->origin.x - *v30);
        v35 = (float)((float)((float)(v31->origin.x - *v30) * (float)(v31->origin.x - *v30))
                    + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)));
        v79.x = v31->origin.x - *v30;
        if ( v35 > 1.0 )
          idVec3::NormalizeFast(this: &v79);
        v36 = __fsqrts(v35);
        if ( v36 > 32.0 )
        {
          v37 = idEntity::GetPhysics(this: this->ai);
          v38 = (float *)v37->GetOrigin(this: v37, a2: 0);
          v39 = (float)(this->target.origin.y - v38[1]);
          v40 = (float)(this->target.origin.z - v38[2]);
          if ( (float)((float)((float)(p_origin->x - *v38) * (float)(p_origin->x - *v38))
                     + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) > 1.0 )
          {
            _FP6 = (float)((float)-1.0
                         - (float)((float)((float)((float)(this->target.origin.x - *v38) * (float)v34)
                                         + (float)((float)((float)(this->target.origin.z - v38[2]) * (float)v33)
                                                 + (float)((float)(this->target.origin.y - v38[1]) * (float)v32)))
                                 / (float)((float)v36 * (float)v36)));
            __asm { fsel      f5, f6, f0, f7 }
            _FP4 = (float)((float)1.0 - (float)_FP5);
            __asm { fsel      f3, f4, f5, f31 }
            v24 = (float)((float)((float)1.0 - (float)_FP3) * (float)0.5);
          }
          idEntity::GetLinearVelocity(this: (idEntity *)&v78, result: this->ai);
          z = v78.z;
          y = v78.y;
          x = v78.x;
          if ( (float)((float)(v78.x * v78.x) + (float)((float)(v78.y * v78.y) + (float)(v78.z * v78.z))) > 1.0 )
          {
            idVec3::NormalizeFast(this: &v78);
            z = v78.z;
            y = v78.y;
            x = v78.x;
          }
          v17 = (float)((float)((float)((float)((float)((float)x * v79.x)
                                              + (float)((float)((float)y * v79.y) + (float)((float)z * v79.z)))
                                      + (float)1.0)
                              * (float)0.25)
                      + (float)0.5);
        }
      }
      v48 = idAICover::GetOrigin(this: v4);
      v5 = idCoverQuery::DebugSucceededAvoid(
             this,
             score: (float)((float)((float)((float)((float)v17 * (float)v24) * (float)v28) * (float)v19) * (float)v18),
             angleScore: v18,
             angle: v16,
             travelScore: v19,
             proximityScore: v28,
             awayScore: v24,
             velocityScore: v17,
             coverOrigin: v55,
             targetOrigin: v54,
             minLevel: v53,
             a12: v52,
             a13: v51,
             a14: v50,
             a15: v49,
             a16: v57,
             a17: v58,
             a18: v59,
             a19: v60,
             a20: v61,
             a21: v62,
             a22: v63,
             a23: v64,
             a24: v65,
             a25: v66,
             a26: v67,
             a27: v68,
             a28: v69,
             a29: v70,
             a30: v71,
             a31: v72,
             a32: v73,
             a33: v74,
             a34: v75,
             a35: &v48->origin.x,
             a36: v76,
             a37: &this->target.origin.x,
             a38: v77,
             a39: 1);
    }
    else
    {
      v7 = idAICover::GetOrigin(this: v4);
      v5 = idCoverQuery::DebugFailed(this, message: "TOO_FAR", origin: &v7->origin, minLevel: 1);
    }
  }
  else
  {
    v5 = 0.0;
  }
  return *((float *)&v5 + 1);
}

