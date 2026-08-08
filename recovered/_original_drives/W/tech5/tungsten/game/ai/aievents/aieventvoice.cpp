
// ========================================================================
// ?GetVoiceMessageType@idAIEventVoice@@QBA?AW4voiceMessageType_t@@XZ
// EA  : 0x82A46C68
// RVA : 0x00A46C68
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventvoice.cpp
// ========================================================================

voiceMessageType_t __fastcall idAIEventVoice::GetVoiceMessageType(idAIEventVoice *this)
{
  const idDeclAiEvent *eventDecl; // r11
  voiceMessageType_t result; // r3

  eventDecl = this->eventDecl;
  result = VOICEMSG_MAX;
  if ( eventDecl != nullptr )
    return eventDecl->voiceMessage;
  return result;
}


// ========================================================================
// ?GetMessage@idAIEvent_DelayedVO@@QBA?AW4voiceMsg_t@@XZ
// EA  : 0x82A46C80
// RVA : 0x00A46C80
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventvoice.cpp
// ========================================================================

voiceMsg_t __fastcall idAIEvent_DelayedVO::GetMessage(idAIEvent_DelayedVO *this)
{
  const idDeclAiEvent *eventDecl; // r11
  voiceMsg_t result; // r3

  eventDecl = this->eventDecl;
  result = AIVOICE_MAX;
  if ( eventDecl != nullptr )
    return eventDecl->delayedMessage;
  return result;
}


// ========================================================================
// ??0idAIEventVoice@@QAA@XZ
// EA  : 0x82A46C98
// RVA : 0x00A46C98
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventvoice.cpp
// ========================================================================

idAIEventVoice *__fastcall idAIEventVoice::idAIEventVoice(idAIEventVoice *this)
{
  idAIEventSound::idAIEventSound(this);
  this->__vftable = (idAIEventVoice_vtbl *)&idAIEventVoice::`vftable';
  return this;
}


// ========================================================================
// ?InternalIsTouching@idAIEventVoice@@MBA_NPBVidEntity@@H@Z
// EA  : 0x82A46CD8
// RVA : 0x00A46CD8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventvoice.cpp
// ========================================================================

int __fastcall idAIEventVoice::InternalIsTouching(idAIEventVoice *this, idAI2 *ent, int curTime)
{
  idAI2 *v6; // r29
  int value; // r9
  idEntity *v8; // r3
  idAI2 *v9; // r3
  idAI2 *v10; // r31
  idEncounterGroup *EncounterGroup; // r31
  idPhysics *Physics; // r3
  float *v14; // r3
  idVec3 *p_origin; // r31
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  idSoundWorld *v19; // r30
  idPhysics *v20; // r3
  idSoundWorld_vtbl *v21; // r29
  int v22; // r3
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp10
  double x; // fp13
  double y; // fp12
  double v28; // fp9
  double v29; // fp7
  BOOL IsTouching; // r3
  BOOL v31; // r30
  idColor *v32; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  idPhysics *v36; // r3
  float *v37; // r3
  double v38; // fp10
  double v39; // fp13
  double v40; // fp12
  double v41; // fp9
  double v42; // fp7
  float v43[4]; // [sp+50h] [-A0h] BYREF
  float v44[4]; // [sp+60h] [-90h] BYREF
  float v45[4]; // [sp+70h] [-80h] BYREF
  float v46[4]; // [sp+80h] [-70h] BYREF
  float v47[4]; // [sp+90h] [-60h] BYREF

  v6 = idAI2::CastTo(c: ent);
  if ( v6 != nullptr )
  {
    value = this->originator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = (idAI2 *)idEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = idAI2::CastTo(c: v9);
    if ( v10 != nullptr
      && idAI2::GetEncounterGroup(this: v6) != nullptr
      && idAI2::GetEncounterGroup(this: v10) != nullptr )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: v10);
      if ( idAI2::GetEncounterGroup(this: v6) == EncounterGroup )
        return 1;
    }
  }
  Physics = idEntity::GetPhysics(this: ent);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  p_origin = &this->origin;
  v16 = (float)(*v14 - this->origin.x);
  v17 = (float)(v14[1] - this->origin.y);
  v18 = (float)(v14[2] - this->origin.z);
  v19 = gameLocal->GetSoundWorld(this: gameLocal);
  if ( v19 != nullptr
    && (v20 = idEntity::GetPhysics(this: ent),
        v21 = v19->__vftable,
        v22 = (int)v20->GetOrigin(this: v20, a2: 0),
        v21->Trace(this: v19, a2: &this->origin, a3: (const idVec3 *)v22))
    && (float)(idAIEventSphere::GetRadius(this) * (float)0.5) < __fsqrts((float)((float)((float)v16 * (float)v16)
                                                                               + (float)((float)((float)v18 * (float)v18)
                                                                                       + (float)((float)v17 * (float)v17)))) )
  {
    if ( ai_debugVoice.valueInteger >= 2 && ai_debugLevel.valueInteger > 0 )
    {
      v23 = idEntity::GetPhysics(this: ent);
      v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
      v25 = v24[1];
      x = p_origin->x;
      y = this->origin.y;
      v28 = (float)(v24[2] + (float)5.0);
      v29 = (float)(this->origin.z + (float)5.0);
      v44[0] = *v24;
      v44[1] = v25;
      v43[0] = x;
      v43[2] = v29;
      v43[1] = y;
      v44[2] = v28;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorMdGrey,
        a3: v43,
        a4: v44);
    }
    return 0;
  }
  else
  {
    IsTouching = idAIEventSound::InternalIsTouching(this, ent, curTime);
    v31 = IsTouching;
    if ( ai_debugVoice.valueInteger >= 2 && ai_debugLevel.valueInteger > 0 )
    {
      if ( IsTouching )
        v32 = &idColor::colorWhite;
      else
        v32 = &idColor::colorBlack;
      g = v32->g;
      b = v32->b;
      a = v32->a;
      v47[0] = v32->r;
      v47[1] = g;
      v47[2] = b;
      v47[3] = a;
      v36 = idEntity::GetPhysics(this: ent);
      v37 = (float *)v36->GetOrigin(this: v36, a2: 0);
      v38 = v37[1];
      v39 = p_origin->x;
      v40 = this->origin.y;
      v41 = (float)(v37[2] + (float)5.0);
      v42 = (float)(this->origin.z + (float)5.0);
      v46[0] = *v37;
      v46[1] = v38;
      v45[0] = v39;
      v45[2] = v42;
      v45[1] = v40;
      v46[2] = v41;
      ((void (__fastcall *)(idRenderWorld *, float *, float *, float *))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: v47,
        a3: v45,
        a4: v46);
    }
    return v31;
  }
}

