
// ========================================================================
// ?Filter@idTargetList@@QAAHPBVidEntity@@ABVidTargetFilter@@@Z
// EA  : 0x82B04410
// RVA : 0x00B04410
// PDB : w:\tech5\tungsten\game\ai\targetting\targetlist.cpp
// ========================================================================

int __fastcall idTargetList::Filter(idTargetList *this, idTurret *owner, idTargetFilter *filter)
{
  idList<enum encounterGroupRole_t,5> *p_viableTargets; // r27
  int size; // r11
  int v8; // r30
  const idTargetCache *targetCache; // r11
  int v11; // [sp+50h] [-40h] BYREF

  this->bestTargetIndex = -1;
  p_viableTargets = (idList<enum encounterGroupRole_t,5> *)&this->viableTargets;
  if ( this->viableTargets.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->viableTargets);
  size = p_viableTargets->size;
  v8 = 0;
  v11 = 0;
  p_viableTargets->num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
  if ( this->targetCache->targets.num > 0 )
  {
    do
    {
      if ( (unsigned __int8)idTargetFilter::Filter(this: filter, owner, ti: &this->targetCache->targets.list[v8]) != 0 )
      {
        if ( this->viableTargets.num >= this->viableTargets.size )
          return this->viableTargets.num;
        idList<idAnimWebBlendTree *,5>::Append(this: p_viableTargets, obj: (const encounterGroupRole_t *)&v11);
      }
      targetCache = this->targetCache;
      v11 = ++v8;
    }
    while ( v8 < targetCache->targets.num );
  }
  return this->viableTargets.num;
}


// ========================================================================
// ?FindBestTarget@idTargetList@@QAAHPBVidEntity@@ABVidTargetFilter@@ABVidTargetSelector@@@Z
// EA  : 0x82B044E8
// RVA : 0x00B044E8
// PDB : w:\tech5\tungsten\game\ai\targetting\targetlist.cpp
// ========================================================================

int __fastcall idTargetList::FindBestTarget(
        idTargetList *this,
        idAI2 *owner,
        idTargetFilter *filter,
        const idTargetSelector *selector)
{
  idList<enum encounterGroupRole_t,5> *p_viableTargets; // r23
  double v9; // fp27
  idAI2 *v10; // r3
  idPresentable *presentable; // r11
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v15; // r3
  double v16; // fp1
  double v17; // fp0
  double v18; // fp12
  double v19; // fp10
  double v20; // fp9
  const idTargetCache *targetCache; // r11
  int v22; // r27
  const idTargetInfo *v23; // r31
  double v24; // fp31
  idPhysics *v25; // r3
  int v26; // r3
  float v27; // r8
  float v28; // r7
  aiSenseState_t *v29; // r11
  float v30; // r3
  float v31; // r7
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  va *v35; // r3
  const idTargetCache *v36; // r11
  int v38; // [sp+8h] [-1158h]
  int v39; // [sp+Ch] [-1154h]
  int v40; // [sp+10h] [-1150h]
  int v41; // [sp+14h] [-114Ch]
  int v42; // [sp+18h] [-1148h]
  int v43; // [sp+1Ch] [-1144h]
  encounterGroupRole_t v44[2]; // [sp+60h] [-1100h] BYREF
  float v45; // [sp+68h] [-10F8h] BYREF
  float v46; // [sp+6Ch] [-10F4h]
  float v47; // [sp+70h] [-10F0h]
  float v48; // [sp+78h] [-10E8h] BYREF
  float v49; // [sp+7Ch] [-10E4h]
  float v50; // [sp+80h] [-10E0h]
  float x; // [sp+88h] [-10D8h]
  float v52; // [sp+8Ch] [-10D4h]
  float v53; // [sp+90h] [-10D0h]
  float v54[6]; // [sp+98h] [-10C8h] BYREF
  idColor v55; // [sp+B0h] [-10B0h] BYREF
  va v56; // [sp+C0h] [-10A0h] BYREF

  this->bestTargetIndex = -1;
  p_viableTargets = (idList<enum encounterGroupRole_t,5> *)&this->viableTargets;
  if ( this->viableTargets.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->viableTargets);
  v9 = 0.0;
  p_viableTargets->num = __CFADD__(-p_viableTargets->size, p_viableTargets->size ^ 0x80000000)
                       ? 0
                       : p_viableTargets->size;
  v10 = idAI2::CastTo(c: owner);
  if ( v10 != nullptr )
  {
    selector->ownerDir = idAI2::GetBodyOrientation(this: v10)->axis.mat[0];
  }
  else
  {
    presentable = owner->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: owner);
      presentable = owner->presentable;
    }
    y = presentable->axis.mat[0].y;
    z = presentable->axis.mat[0].z;
    x = presentable->axis.mat[0].x;
    v52 = y;
    v53 = z;
    Physics = idEntity::GetPhysics(this: owner);
    v15 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    v16 = v15[1];
    v17 = v15[2];
    v18 = x;
    v19 = (float)((float)(v15[4] * v52) + (float)(v15[7] * v53));
    v20 = (float)((float)(v15[5] * v52) + (float)(v15[8] * v53));
    selector->ownerDir.x = (float)(*v15 * x) + (float)((float)(v15[3] * v52) + (float)(v15[6] * v53));
    selector->ownerDir.y = (float)((float)v16 * (float)v18) + (float)v19;
    selector->ownerDir.z = (float)((float)v17 * (float)v18) + (float)v20;
  }
  targetCache = this->targetCache;
  v22 = 0;
  v44[0] = ROLE_NONE;
  if ( targetCache->targets.num > 0 )
  {
    do
    {
      v23 = &this->targetCache->targets.list[v22];
      if ( (unsigned __int8)idTargetFilter::Filter(this: filter, (idTurret *)owner, ti: v23) != 0 )
      {
        if ( this->viableTargets.num >= this->viableTargets.size )
          return this->bestTargetIndex;
        idList<idAnimWebBlendTree *,5>::Append(this: p_viableTargets, obj: v44);
        v24 = ((double (__fastcall *)(const idTargetSelector *, idAI2 *, const idTargetInfo *))selector->GetWeight)(
                a1: selector,
                a2: owner,
                a3: v23);
        if ( ai_debugTargetList.valueInteger > 0 )
        {
          v25 = idEntity::GetPhysics(this: owner);
          v26 = (int)v25->GetOrigin(this: v25, a2: 0);
          v27 = *(float *)(v26 + 4);
          v28 = *(float *)(v26 + 8);
          v45 = *(float *)v26;
          v46 = v27;
          v47 = v28;
          v29 = v23->es->senses.ptr[1];
          if ( v29->lastUnconfirmedStimTime >= 0 )
          {
            v55 = idColor::colorMdGrey;
            if ( v29->lastConfirmedStimTime >= 0 )
              v55 = idColor::colorWhite;
            v30 = v29->unConfirmedPhysical.origin.z;
            v31 = v29->unConfirmedPhysical.origin.y;
            v48 = v29->unConfirmedPhysical.origin.x;
            v50 = v30;
            v49 = v31;
            ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
              a1: clientGame->renderWorld,
              a2: &v55,
              a3: &v45,
              a4: &v48,
              a5: 10.0);
            HIDWORD(v32) = LODWORD(v24);
            v54[0] = (float)(v48 + v45) * (float)0.5;
            v54[1] = (float)(v46 + v49) * (float)0.5;
            v54[2] = (float)(v47 + v50) * (float)0.5;
            v35 = va::va(
                    this: &v56,
                    fmt: "%4.2f",
                    a3: v32,
                    a4: v34,
                    a5: v33,
                    a6: v38,
                    a7: v39,
                    a8: v40,
                    a9: v41,
                    a10: v42,
                    a11: v43,
                    v24);
            ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
              a1: clientGame->renderWorld,
              a2: v35,
              a3: v54,
              a4: clientGame->renderWorld->__vftable,
              a5: &v55,
              a6: 30,
              a7: 0,
              a8: 0,
              a9: 0.25);
          }
        }
        if ( v24 > v9 )
        {
          v9 = v24;
          this->bestTargetIndex = this->viableTargets.num - 1;
        }
      }
      v36 = this->targetCache;
      v44[0] = ++v22;
    }
    while ( v22 < v36->targets.num );
  }
  return this->bestTargetIndex;
}


// ========================================================================
// ??0idTargetList@@QAA@ABVidTargetCache@@@Z
// EA  : 0x82B048C0
// RVA : 0x00B048C0
// PDB : w:\tech5\tungsten\game\ai\targetting\targetlist.cpp
// ========================================================================

idTargetList *__fastcall idTargetList::idTargetList(idTargetList *this, const idTargetCache *targetCache_)
{
  this->targetCache = targetCache_;
  this->viableTargets.granularity = 1;
  this->viableTargets.size = 8;
  this->viableTargets.num = 0;
  this->viableTargets.list = this->viableTargets.staticList;
  this->viableTargets.memTag = 5;
  this->viableTargets.listStatic = 1;
  this->bestTargetIndex = -1;
  return this;
}

