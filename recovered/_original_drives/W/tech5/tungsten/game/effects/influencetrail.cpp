
// ========================================================================
// ?AllocInfluenceTrail@idInfluenceTrailManager@@QAA?AV?$idHandle@HW4invalidInfluenceTrail_t@@$0?0@@MMMMHHAAVidPresentable@@QBVidSoundShader@@@Z
// EA  : 0x82BE0EA8
// RVA : 0x00BE0EA8
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

idInfluenceTrailManager *__fastcall idInfluenceTrailManager::AllocInfluenceTrail(
        idInfluenceTrailManager *this,
        idHandle<int,enum invalidInfluenceTrail_t,-1> *result,
        double innerRadius,
        double outerRadius,
        double angle,
        double trailDist,
        int trailFadeInTime,
        int trailFadeOutTime,
        idPresentable *presentable,
        const idSoundShader *const sndFoliage,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34)
{
  int v35; // r11
  idHandle<int,enum invalidInfluenceTrail_t,-1> *v36; // r8
  int value_high; // r6
  idHandle<int,enum invalidInfluenceTrail_t,-1> *v39; // r11

  v35 = 0;
  v36 = result + 1;
  while ( 1 )
  {
    value_high = HIBYTE(v36->value);
    if ( HIBYTE(v36->value) == 0 )
      break;
    ++v35;
    v36 += 19;
    if ( v35 >= 128 )
    {
      idLib::Warning(
        fmt: "out of influence trails",
        result,
        trailFadeInTime,
        value_high,
        presentable,
        v36,
        innerRadius,
        outerRadius,
        angle,
        trailDist);
      this->__vftable = (idInfluenceTrailManager_vtbl *)-1;
      return this;
    }
  }
  this->__vftable = (idInfluenceTrailManager_vtbl *)v35;
  v39 = &result[19 * v35];
  *(float *)&v39[3].value = innerRadius;
  v39[6].value = a11;
  v39[7].value = a12;
  *(float *)&v39[4].value = outerRadius;
  v39[18].value = a32;
  *(float *)&v39[5].value = angle;
  v39[19].value = a34;
  *(float *)&v39[2].value = trailDist;
  *(float *)&v39[10].value = 0.0;
  *(float *)&v39[9].value = 0.0;
  *(float *)&v39[8].value = 0.0;
  *(float *)&v39[13].value = 0.0;
  *(float *)&v39[12].value = 0.0;
  *(float *)&v39[11].value = 0.0;
  HIBYTE(v39[1].value) = 1;
  return this;
}


// ========================================================================
// ?FreeInfluenceTrail@idInfluenceTrailManager@@QAAXAAVidPresentable@@@Z
// EA  : 0x82BE0F70
// RVA : 0x00BE0F70
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrailManager::FreeInfluenceTrail(idInfluenceTrailManager *this, idPresentable *presentable)
{
  int value; // r11
  char *v3; // r11

  value = presentable->influenceHandle.value;
  if ( value != -1 )
  {
    v3 = (char *)this + 76 * value;
    v3[4] = 0;
    *((_DWORD *)v3 + 18) = 0;
    *((_DWORD *)v3 + 19) = 0;
    presentable->influenceHandle.value = -1;
  }
}


// ========================================================================
// ?ModifyAngle@idInfluenceTrailManager@@QAAXABV?$idHandle@HW4invalidInfluenceTrail_t@@$0?0@@M@Z
// EA  : 0x82BE0FA8
// RVA : 0x00BE0FA8
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrailManager::ModifyAngle(
        idInfluenceTrailManager *this,
        const idHandle<int,enum invalidInfluenceTrail_t,-1> *trail,
        double angle)
{
  if ( trail->value != -1 )
    this->influenceTrails[trail->value].angle = angle;
}


// ========================================================================
// ?AddInfluenceSpheresToModel@idInfluenceTrailManager@@QAAXPAVidRenderModelTransparency@@H@Z
// EA  : 0x82BE0FC8
// RVA : 0x00BE0FC8
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idInfluenceTrailManager::AddInfluenceSpheresToModel(
        idInfluenceTrailManager *this,
        idRenderModelTransparency *model,
        int time)
{
  const idSoundShader **p_sndFoliage; // r31
  int i; // r23
  const idSoundShader **v7; // r27
  int v8; // r30
  int v9; // r29
  __int64 v10; // r7 OVERLAPPED
  long double v11; // fp2
  int v12; // r29
  int v13; // r30
  int v14; // r8
  int v15; // r7
  __int64 v16; // r11 OVERLAPPED
  int v17; // r9
  int v18; // r8
  double v19; // fp31
  long double v20; // fp2
  double v21; // fp31

  p_sndFoliage = &this->influenceTrails[0].sndFoliage;
  for ( i = 128; i != 0; --i )
  {
    v7 = p_sndFoliage - 18;
    if ( *((_BYTE *)p_sndFoliage - 72) != 0 )
    {
      if ( *((float *)p_sndFoliage - 17) == -1.0 )
      {
        if ( *p_sndFoliage != nullptr
          && !idPresentable::IsPlayingSound(this: (idPresentable *)*(p_sndFoliage - 1), channel: SND_CHANNEL_BREATHE) )
        {
          idPresentable::StartSoundShader(
            this: (idPresentable *)*(p_sndFoliage - 1),
            channel: SND_CHANNEL_BREATHE,
            shader: *p_sndFoliage,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0);
        }
        idRenderModelTransparency::AddInfluenceSphere(
          this: model,
          center: (const idVec3 *)(p_sndFoliage - 11),
          innerRadius: *((float *)p_sndFoliage - 16),
          outerRadius: *((float *)p_sndFoliage - 15),
          angle: *((float *)p_sndFoliage - 14));
        v8 = 0;
        if ( (int)*(p_sndFoliage - 4) > 0 )
        {
          v9 = 0;
          do
          {
            idRenderModelTransparency::AddInfluenceSphere(
              this: model,
              center: (const idVec3 *)((char *)*(p_sndFoliage - 5) + v9),
              innerRadius: *((float *)p_sndFoliage - 16),
              outerRadius: *((float *)p_sndFoliage - 15),
              angle: *((float *)p_sndFoliage - 14));
            ++v8;
            v9 += 16;
          }
          while ( v8 < (int)*(p_sndFoliage - 4) );
        }
      }
      else
      {
        idRenderModelTransparency::AddInfluenceSphere(
          this: model,
          center: (const idVec3 *)(p_sndFoliage - 11),
          innerRadius: *((float *)p_sndFoliage - 16),
          outerRadius: *((float *)p_sndFoliage - 15),
          angle: *((float *)p_sndFoliage - 14));
        v12 = 0;
        if ( (int)*(p_sndFoliage - 4) > 0 )
        {
          v13 = 0;
          do
          {
            HIDWORD(v16) = *(p_sndFoliage - 13);
            v14 = (int)*(p_sndFoliage - 12) + HIDWORD(v16);
            v15 = *(int *)((char *)&(*(p_sndFoliage - 5))->nextOnHashChain + v13);
            LODWORD(v16) = time - v15;
            if ( time - v15 <= v14 )
            {
              LODWORD(v10) = time - v15;
              if ( (int)v16 <= SHIDWORD(v16) )
              {
                LODWORD(v16) = *(p_sndFoliage - 13);
                v19 = (float)((float)((float)v10 * 0.001) / (float)((float)v16 * (float)0.001));
              }
              else
              {
                HIDWORD(v16) = *(p_sndFoliage - 12);
                v18 = v14 - v16;
                v17 = v18;
                v19 = (float)((float)((float)*(__int64 *)((char *)&v10 - 4) * (float)0.001)
                            / (float)((float)*(__int64 *)((char *)&v16 + 4) * (float)0.001));
              }
              *(double *)&v11 = (float)((float)(idMath::TWO_PI / (float)((float)((float)v10 * 0.001) + (float)1.0))
                                      * (float)((float)v10 * 0.001));
              v20 = cos(x: v11);
              v21 = (float)((float)(*((float *)p_sndFoliage - 14) * (float)*(double *)&v20) * (float)v19);
              if ( *p_sndFoliage != nullptr
                && !idPresentable::IsPlayingSound(this: (idPresentable *)v7[17], channel: SND_CHANNEL_BREATHE) )
              {
                idPresentable::StartSoundShader(
                  this: (idPresentable *)v7[17],
                  channel: SND_CHANNEL_BREATHE,
                  shader: *p_sndFoliage,
                  soundShaderFlags: (soundShaderFlags_t)0,
                  peerMask: 0);
              }
              idRenderModelTransparency::AddInfluenceSphere(
                this: model,
                center: (const idVec3 *)((char *)*(p_sndFoliage - 5) + v13),
                innerRadius: *((float *)p_sndFoliage - 16),
                outerRadius: *((float *)p_sndFoliage - 15),
                angle: v21);
            }
            ++v12;
            v13 += 16;
          }
          while ( v12 < (int)*(p_sndFoliage - 4) );
        }
      }
    }
    p_sndFoliage += 19;
  }
}


// ========================================================================
// ?Enable@idInfluenceTrailManager@@QAAXAAVidPresentable@@ABVidEntityInfluenceTrail@@QBVidSoundShader@@@Z
// EA  : 0x82BE1240
// RVA : 0x00BE1240
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrailManager::Enable(
        idInfluenceTrailManager *this,
        idPresentable *presentable,
        const idEntityInfluenceTrail *trail,
        const idSoundShader *const sndFoliage,
        idPresentable *a5,
        const idSoundShader *a6)
{
  double angle; // fp3
  double trailFadeInTime; // fp12
  double trailDist; // fp4
  double outerRadius; // fp2
  double innerRadius; // fp1
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]
  int v18; // [sp+20h] [-60h]
  int v19; // [sp+24h] [-5Ch]
  int v20; // [sp+28h] [-58h]
  int v21; // [sp+2Ch] [-54h]
  int v22; // [sp+30h] [-50h]
  int v23; // [sp+34h] [-4Ch]
  int v24; // [sp+38h] [-48h]
  int v25; // [sp+3Ch] [-44h]
  int v26; // [sp+40h] [-40h]
  int v27; // [sp+44h] [-3Ch]
  int v28; // [sp+48h] [-38h]
  int v29; // [sp+4Ch] [-34h]
  int v30; // [sp+50h] [-30h]
  int v31; // [sp+58h] [-28h]
  int v32; // [sp+60h] [-20h] BYREF
  int v33; // [sp+64h] [-1Ch]
  int v35; // [sp+6Ch] [-14h]

  angle = trail->angle;
  if ( angle != 0.0 && presentable->influenceHandle.value == -1 )
  {
    trailFadeInTime = trail->trailFadeInTime;
    trailDist = trail->trailDist;
    outerRadius = trail->outerRadius;
    innerRadius = trail->innerRadius;
    v33 = (int)(float)(trail->trailFadeOutTime * (float)1000.0);
    v35 = (int)(float)((float)trailFadeInTime * (float)1000.0);
    idInfluenceTrailManager::AllocInfluenceTrail(
      this: (idInfluenceTrailManager *)&v32,
      result: (idHandle<int,enum invalidInfluenceTrail_t,-1> *)&clientGame->influenceTrailManager,
      innerRadius,
      outerRadius,
      angle,
      trailDist,
      trailFadeInTime: (int)trail,
      trailFadeOutTime: (int)sndFoliage,
      presentable: a5,
      sndFoliage: a6,
      a11: v35,
      a12: v33,
      a13: v12,
      a14: v13,
      a15: v14,
      a16: v15,
      a17: v16,
      a18: v17,
      a19: v18,
      a20: v19,
      a21: v20,
      a22: v21,
      a23: v22,
      a24: v23,
      a25: v24,
      a26: v25,
      a27: v26,
      a28: v27,
      a29: v28,
      a30: v29,
      a31: v30,
      a32: (int)presentable,
      a33: v31,
      a34: (int)sndFoliage);
    presentable->influenceHandle.value = v32;
  }
}


// ========================================================================
// ??0idInfluenceTrail@@QAA@XZ
// EA  : 0x82BE1368
// RVA : 0x00BE1368
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

idInfluenceTrail *__fastcall idInfluenceTrail::idInfluenceTrail(idInfluenceTrail *this)
{
  this->active = false;
  this->trailDist = 0.0;
  this->trailFadeInTime = 0;
  this->innerRadius = 0.0;
  this->trailFadeOutTime = 0;
  this->outerRadius = 0.0;
  this->angle = 0.0;
  this->position.x = 0.0;
  this->position.y = 0.0;
  this->position.z = 0.0;
  this->lastPosition.x = 0.0;
  this->lastPosition.y = 0.0;
  this->lastPosition.z = 0.0;
  this->trail.list = nullptr;
  this->trail.granularity = 0;
  this->trail.memTag = 5;
  this->trail.listStatic = 0;
  this->trail.size = 0;
  this->trail.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trail);
  this->presentable = nullptr;
  this->sndFoliage = nullptr;
  return this;
}


// ========================================================================
// ?UpdatePosition@idInfluenceTrail@@QAAXABVidVec3@@H@Z
// EA  : 0x82BE1660
// RVA : 0x00BE1660
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrail::UpdatePosition(idInfluenceTrail *this, const idVec3 *position, int time)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  double v8; // fp10
  double v9; // fp7
  double v10; // fp4
  float y; // r10
  float z; // r9
  int v13; // r27
  int v14; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v16; // r30
  int v17; // r3
  __int64 totalTicks; // r11
  __int64 v19; // r9
  idPLogScope v20; // [sp+58h] [-58h] BYREF
  idInfluenceTrail::idInfluenceSphere v21; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "idInfluenceTrail::UpdatePosition");
  LODWORD(v6) = "idInfluenceTrail::UpdatePosition";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v20, pl: &::pLog, gMask: v6, label: v7);
  this->position = *position;
  if ( this->trailDist == -1.0 )
  {
    idPLogScope::~idPLogScope(this: &v20);
  }
  else
  {
    v8 = (float)(position->y - this->lastPosition.y);
    v9 = (float)(position->x - this->lastPosition.x);
    v10 = (float)(position->z - this->lastPosition.z);
    if ( (float)((float)((float)v10 * (float)v10)
               + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) > (double)(float)(this->trailDist * this->trailDist) )
    {
      y = position->y;
      z = position->z;
      v21.center.x = position->x;
      v21.time = time;
      v21.center.y = y;
      v21.center.z = z;
      idList<idInfluenceTrail::idInfluenceSphere,5>::Append(this: &this->trail, obj: &v21);
      this->lastPosition.x = position->x;
      this->lastPosition.y = position->y;
      this->lastPosition.z = position->z;
    }
    v13 = 0;
    if ( this->trail.num > 0 )
    {
      v14 = 0;
      do
      {
        if ( time - this->trail.list[v14].time > this->trailFadeInTime + this->trailFadeOutTime )
        {
          idList<idInfluenceTrail::idInfluenceSphere,5>::RemoveIndex(this: &this->trail, index: v13--);
          --v14;
        }
        ++v13;
        ++v14;
      }
      while ( v13 < this->trail.num );
    }
    if ( v20.logIndex >= 0 )
    {
      pLog = v20.pLog;
      v16 = &v20.pLog->logEntries.list[v20.logIndex];
      v17 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v16->totalTicks;
      HIDWORD(totalTicks) = v16->parent;
      LODWORD(v19) = v17 - totalTicks;
      v16->totalTicks = v19;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$488272
// EA  : 0x82BE180C
// RVA : 0x00BE180C
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void _unwind_488272()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$488273
// EA  : 0x82BE1834
// RVA : 0x00BE1834
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void _unwind_488273()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?UpdateInfluenceTrails@idInfluenceTrailManager@@QAAXHPAVidRenderModelTransparency@@@Z
// EA  : 0x82BE1860
// RVA : 0x00BE1860
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrailManager::UpdateInfluenceTrails(
        idInfluenceTrailManager *this,
        int time,
        idRenderModelTransparency *transModel)
{
  idInfluenceTrail *influenceTrails; // r31
  int i; // r30

  influenceTrails = this->influenceTrails;
  for ( i = 128; i != 0; --i )
  {
    if ( influenceTrails->active )
      idInfluenceTrail::UpdatePosition(this: influenceTrails, position: &influenceTrails->position, time);
    ++influenceTrails;
  }
  if ( transModel != nullptr )
  {
    idRenderModelTransparency::ClearInfluenceSpheres(this: transModel);
    idInfluenceTrailManager::AddInfluenceSpheresToModel(this, model: transModel, time);
  }
}


// ========================================================================
// ?UpdatePosition@idInfluenceTrailManager@@QAAXABV?$idHandle@HW4invalidInfluenceTrail_t@@$0?0@@ABVidVec3@@H@Z
// EA  : 0x82BE18D0
// RVA : 0x00BE18D0
// PDB : w:\tech5\tungsten\game\effects\influencetrail.cpp
// ========================================================================

void __fastcall idInfluenceTrailManager::UpdatePosition(
        idInfluenceTrailManager *this,
        const idHandle<int,enum invalidInfluenceTrail_t,-1> *trail,
        const idVec3 *position,
        int time)
{
  if ( trail->value != -1 )
    idInfluenceTrail::UpdatePosition(this: &this->influenceTrails[trail->value], position, time);
}

