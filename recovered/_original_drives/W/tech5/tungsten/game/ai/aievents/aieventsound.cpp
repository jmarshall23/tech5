
// ========================================================================
// ?InternalIsTouching@idAIEventSound@@MBA_NPBVidEntity@@H@Z
// EA  : 0x82A45A78
// RVA : 0x00A45A78
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsound.cpp
// ========================================================================

BOOL __fastcall idAIEventSound::InternalIsTouching(idAIEventSound *this, const idEntity *ent, int curTime)
{
  return idAIEventProjectedSphere::InternalIsTouching((idAIEventProjectedSphere *)this, ent, curTime);
}


// ========================================================================
// ??0idAIEventSound@@QAA@XZ
// EA  : 0x82A45AA8
// RVA : 0x00A45AA8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsound.cpp
// ========================================================================

idAIEventSound *__fastcall idAIEventSound::idAIEventSound(idAIEventSound *this)
{
  idAIEventSphere::idAIEventSphere(this);
  this->__vftable = (idAIEventSound_vtbl *)&idAIEventSound::`vftable';
  return this;
}


// ========================================================================
// ?InternalGetIntensity@idAIEventSound@@MBAMPBVidEntity@@@Z
// EA  : 0x82A45AE8
// RVA : 0x00A45AE8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventsound.cpp
// ========================================================================

float __fastcall idAIEventSound::InternalGetIntensity(idAIEventSound *this, idEntity *ent)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp10
  idVec3 *p_origin; // r31
  double v8; // fp8
  double v9; // fp31
  double v10; // fp25
  double v11; // fp30
  double v12; // fp26
  idSoundWorld *v13; // r30
  idPhysics *v14; // r3
  idSoundWorld_vtbl *v15; // r28
  int v16; // r3
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp10
  double x; // fp13
  double y; // fp12
  double v22; // fp9
  double v23; // fp7
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp11
  double v27; // fp10
  double v28; // fp0
  double v29; // fp7
  const idDeclAiEvent *eventDecl; // r11
  double volume; // fp28
  double v32; // fp29
  double intensityScale; // fp30
  float result; // fp1
  float v37[4]; // [sp+50h] [-B0h] BYREF
  float v38[4]; // [sp+60h] [-A0h] BYREF
  float v39[4]; // [sp+70h] [-90h] BYREF
  float v40[20]; // [sp+80h] [-80h] BYREF

  Physics = idEntity::GetPhysics(this: ent);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v6 = (float)(*v5 - this->origin.x);
  p_origin = &this->origin;
  v8 = (float)(v5[1] - this->origin.y);
  v9 = (float)(v5[2] - this->origin.z);
  v10 = 0.0;
  v11 = (float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6));
  v12 = __fsqrts((float)((float)((float)v9 * (float)v9)
                       + (float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6))));
  v13 = gameLocal->GetSoundWorld(this: gameLocal);
  if ( v13 != nullptr )
  {
    v14 = idEntity::GetPhysics(this: ent);
    v15 = v13->__vftable;
    v16 = (int)v14->GetOrigin(this: v14, a2: 0);
    if ( v15->Trace(this: v13, a2: &this->origin, a3: (const idVec3 *)v16) )
    {
      if ( ai_debugEnemy.valueInteger >= 2 && ai_debugLevel.valueInteger > 0 )
      {
        v17 = idEntity::GetPhysics(this: ent);
        v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
        v19 = v18[1];
        x = p_origin->x;
        y = this->origin.y;
        v22 = (float)(v18[2] + (float)5.0);
        v23 = (float)(this->origin.z + (float)5.0);
        v38[0] = *v18;
        v38[1] = v19;
        v37[0] = x;
        v37[2] = v23;
        v37[1] = y;
        v38[2] = v22;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorMdGrey,
          a3: v37,
          a4: v38);
      }
      v10 = 0.5;
      if ( v9 > 0.0 )
        v12 = __fsqrts((float)((float)((float)((float)v9 * (float)3.0) * (float)((float)v9 * (float)3.0)) + (float)v11));
    }
    else if ( ai_debugEnemy.valueInteger >= 2 && ai_debugLevel.valueInteger > 0 )
    {
      v24 = idEntity::GetPhysics(this: ent);
      v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
      v26 = v25[2];
      v27 = v25[1];
      v28 = p_origin->x;
      v39[0] = *v25;
      v39[1] = v27;
      v40[0] = v28;
      v29 = (float)(this->origin.z + (float)5.0);
      v40[1] = this->origin.y;
      v39[2] = (float)v26 + (float)5.0;
      v40[2] = v29;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorWhite,
        a3: v40,
        a4: v39);
    }
  }
  eventDecl = this->eventDecl;
  if ( eventDecl != nullptr )
    volume = eventDecl->volume;
  else
    volume = 1.0;
  if ( eventDecl != nullptr )
    v32 = eventDecl->volume;
  else
    v32 = 1.0;
  if ( eventDecl != nullptr )
    intensityScale = eventDecl->intensityScale;
  else
    intensityScale = 1.0;
  _FP9 = -(float)((float)((float)-(float)((float)((float)((float)v12 / idAIEventSphere::GetRadius(this)) * (float)v32)
                                        - (float)volume)
                        * (float)((float)1.0 - (float)v10))
                * (float)intensityScale);
  __asm { fsel      f1, f9, f27, f10 }
  LODWORD(result) = _FP1;
  return result;
}

