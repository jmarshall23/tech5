
// ========================================================================
// ?GetHealthPercent@idDrone@@QBAMXZ
// EA  : 0x82C27AE8
// RVA : 0x00C27AE8
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

float __fastcall idDrone::GetHealthPercent(idDrone *this)
{
  double v1; // fp1

  v1 = 0.0;
  if ( this->health > 0.0 )
  {
    if ( this->startingHealth <= 0.0 )
      v1 = 0.5;
    else
      v1 = (float)(this->health / this->startingHealth);
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?DebugArrow@idDrone@@SAXVidVec4@@VidVec3@@1MH_N@Z
// EA  : 0x82C27B30
// RVA : 0x00C27B30
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDrone::DebugArrow(
        __int64 start,
        __int64 lifetime,
        double size,
        __int64 depthTest,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 *v14; // r4
  __int64 *v15; // r6

  a8 = *(__int64 *)((char *)&start + 4);
  a9 = start;
  v14 = &a8;
  a10 = *(__int64 *)((char *)&lifetime + 4);
  HIDWORD(lifetime) = &a10;
  a11 = lifetime;
  v15 = &a12;
  a12 = *(__int64 *)((char *)&depthTest + 4);
  a13 = depthTest;
  ((void (__fastcall *)(idRenderWorld *, __int64 *, __int64 *, __int64 *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &a8,
    a3: &a10,
    a4: &a12,
    a5: size);
}


// ========================================================================
// ?DebugSphere@idDrone@@SAXVidVec4@@VidVec3@@MHH_N@Z
// EA  : 0x82C27B98
// RVA : 0x00C27B98
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDrone::DebugSphere(
        __int64 pos,
        double radius,
        __int64 lifetime,
        bool depthTest,
        int a5,
        int a6,
        BOOL a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  float v13[6]; // [sp+50h] [-20h] BYREF

  a9 = *(__int64 *)((char *)&pos + 4);
  a10 = pos;
  v13[3] = radius;
  a11 = *(__int64 *)((char *)&lifetime + 4);
  a12 = lifetime;
  v13[0] = *((float *)&pos + 1);
  v13[1] = *(float *)&lifetime;
  v13[2] = *(float *)&lifetime;
  clientGame->renderWorld->DebugSphere(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&a9,
    a3: (const idSphere *)v13,
    a4: a5,
    a5: a6,
    a6: a7);
}


// ========================================================================
// ?GetHealth@idDrone@@UBAMXZ
// EA  : 0x82C2C318
// RVA : 0x00C2C318
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

float __fastcall idDrone::GetHealth(idDrone *this)
{
  double health; // fp1

  health = this->health;
  return *((float *)&health + 1);
}


// ========================================================================
// ?GetFaction@idDrone@@UBAPBVidFaction@@XZ
// EA  : 0x82C2C320
// RVA : 0x00C2C320
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

idFaction *__fastcall idDrone::GetFaction(idDrone *this)
{
  return &this->faction;
}


// ========================================================================
// ?GetTriggerTouchList@idDrone@@UAAPAV?$idList@V?$idEntityPtr@VidEntity@@@@$04@@XZ
// EA  : 0x82C2C328
// RVA : 0x00C2C328
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

const idList<idEntityPtr<idEntity>,5> *__fastcall idDrone::GetTriggerTouchList(idDrone *this)
{
  return &this->touching;
}


// ========================================================================
// ?GetAttachments@idDrone@@EBAPBVidAttachmentCollection@@XZ
// EA  : 0x82C2C330
// RVA : 0x00C2C330
// PDB : w:\tech5\tungsten\game\entities\drone.h
// ========================================================================

const idAttachmentCollection *__fastcall idDrone::GetAttachments(idDrone *this)
{
  return &this->attachments;
}

