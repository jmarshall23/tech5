
// ========================================================================
// ?EmitDebris@idEffectPhysicsDebrisEmitter@@QAAXVidVec3@@00HH@Z
// EA  : 0x82704858
// RVA : 0x00704858
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsDebrisEmitter::EmitDebris(
        idEffectPhysicsDebrisEmitter *this,
        __int64 velocity,
        __int64 count,
        __int64 currentTime,
        int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        int a15,
        int a16,
        int a17,
        int a18)
{
  BOOL active; // r11
  double v20; // fp13
  double v21; // fp12
  double v22; // fp11
  idEffectPhysicsDebrisEmitter::emitBufferItem_t *v23; // r11
  float *v24; // r11
  int v25; // r25
  int v26; // r28
  double v27; // fp22
  double v28; // fp21
  double v29; // fp20
  double v30; // fp19
  __int64 v31; // r7
  double v32; // fp18
  double v33; // fp17
  unsigned int seed; // r11
  unsigned int v35; // r9
  double yaw; // fp13
  double roll; // fp12
  double pitch; // fp11
  double v39; // fp10
  double v40; // fp9
  double v41; // fp8
  __int64 v42; // r4
  unsigned int v43; // r5
  __int128 v44; // r11
  double v45; // fp6
  unsigned int v46; // r5
  double v47; // fp4
  double v48; // fp5
  double v49; // fp7
  double v50; // fp4
  double v51; // fp2
  double v52; // fp1
  idAngles v53; // [sp+78h] [-F8h] BYREF
  idVec3 v54; // [sp+88h] [-E8h] BYREF
  idVec3 v55; // [sp+98h] [-D8h] BYREF
  idVec3 v56; // [sp+A8h] [-C8h] BYREF

  a9 = *(__int64 *)((char *)&velocity + 4);
  a10 = velocity;
  active = this->active;
  a11 = *(__int64 *)((char *)&count + 4);
  a12 = count;
  a13 = *(__int64 *)((char *)&currentTime + 4);
  a14 = currentTime;
  if ( active )
  {
    if ( a5 >= 16 )
      a5 = 15;
    v20 = *(float *)&a13;
    v21 = *((float *)&a13 + 1);
    v22 = *(float *)&a14;
    v23 = &this->emitBuffer[this->emitBufferPos];
    *(_QWORD *)&v23->pos.x = a9;
    v23->pos.z = *(float *)&a10;
    v24 = (float *)((char *)this + 28 * this->emitBufferPos);
    v24[45] = v20;
    v24[46] = v21;
    v24[47] = v22;
    this->emitBuffer[this->emitBufferPos].count = a5;
    this->emitBufferPos = (this->emitBufferPos + 1) % 10;
    if ( a5 > 0 )
    {
      v25 = a18;
      v26 = a5;
      v27 = *(float *)&a12;
      v28 = *((float *)&a11 + 1);
      v29 = *(float *)&a11;
      v30 = (float)((float)v20 * (float)1000.0);
      HIDWORD(v31) = "_AI_OBSTACLE";
      v32 = (float)((float)v21 * (float)1000.0);
      v33 = (float)((float)v22 * (float)1000.0);
      do
      {
        seed = this->random.seed;
        v54.y = 0.0;
        v54.z = 0.0;
        v35 = 1664525 * seed + 1013904223;
        LODWORD(v31) = (v35 >> 10) & 0x7FFF;
        this->random.seed = v35;
        v54.x = (float)((float)v31 * (float)0.0013733329) + (float)45.0;
        idAngles::ToForward(this: &v53, result: &v54);
        yaw = v53.yaw;
        roll = v53.roll;
        pitch = v53.pitch;
        v39 = *(float *)&a9;
        v40 = *((float *)&a9 + 1);
        v41 = *(float *)&a10;
        HIDWORD(v42) = 1664525 * this->random.seed + 1013904223;
        this->random.seed = HIDWORD(v42);
        LODWORD(v42) = (HIDWORD(v42) >> 10) & 0x7FFF;
        v43 = 1664525 * HIDWORD(v42) + 1013904223;
        LODWORD(v44) = (v43 >> 10) & 0x7FFF;
        this->random.seed = v43;
        DWORD2(v44) = v43;
        DWORD1(v44) = 1664525 * v43;
        v45 = (float)(__int64)v44;
        v46 = 1664525 * v43 + 1013904223;
        v47 = (float)((float)v42 * (float)0.000030518509);
        this->random.seed = v46;
        HIDWORD(v42) = v46;
        DWORD2(v44) = (v46 >> 10) & 0x7FFF;
        v48 = (double)*(__int64 *)((char *)&v44 + 4);
        DWORD1(v44) = 1664525 * v46 + 1013904223;
        LODWORD(v42) = (DWORD1(v44) >> 10) & 0x7FFF;
        this->random.seed = DWORD1(v44);
        v49 = (float)((float)((float)v47 * (float)8.0) - (float)4.0);
        v52 = (float)((float)roll
                    * (float)((float)((float)pitch * (float)((float)((float)v48 * (float)0.00024414808) - (float)4.0))
                            + (float)((float)((float)roll * (float)((float)((float)v47 * (float)8.0) - (float)4.0))
                                    + (float)((float)yaw
                                            * (float)((float)((float)((float)v45 * (float)0.000030518509) * (float)8.0)
                                                    - (float)4.0)))));
        v51 = (float)((float)yaw
                    * (float)((float)((float)pitch * (float)((float)((float)v48 * (float)0.00024414808) - (float)4.0))
                            + (float)((float)((float)roll * (float)((float)((float)v47 * (float)8.0) - (float)4.0))
                                    + (float)((float)yaw
                                            * (float)((float)((float)((float)v45 * (float)0.000030518509) * (float)8.0)
                                                    - (float)4.0)))));
        v50 = (float)((float)((float)v48 * (float)0.00024414808) - (float)4.0);
        v53.pitch = (float)pitch * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0);
        v53.yaw = (float)yaw * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0);
        v53.roll = (float)((float)roll * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0))
                 + (float)200.0;
        v55.x = (float)((float)v50
                      - (float)((float)pitch
                              * (float)((float)((float)pitch * (float)v50)
                                      + (float)((float)((float)roll * (float)v49)
                                              + (float)((float)yaw
                                                      * (float)((float)((float)((float)v45 * (float)0.000030518509)
                                                                      * (float)8.0)
                                                              - (float)4.0))))))
              + (float)v39;
        v55.y = (float)((float)((float)((float)((float)v45 * (float)0.000030518509) * (float)8.0) - (float)4.0)
                      - (float)v51)
              + (float)v40;
        v55.z = (float)((float)v49 - (float)v52) + (float)v41;
        v56.x = (float)((float)(v53.pitch * (float)10.0) + (float)v29) + (float)v30;
        v56.y = (float)((float)v28 + (float)(v53.yaw * (float)10.0)) + (float)v32;
        v56.z = (float)((float)v27 + (float)(v53.roll * (float)10.0)) + (float)v33;
        idEffectPhysicsPieceEmitter::EmitPiece(
          this: &this->piecePhysics,
          emitTime: v25,
          pos: &v55,
          axes: &mat3_identity,
          impulsePoint: (const idVec3 *)&a9,
          impulse: &v56);
        --v26;
      }
      while ( v26 != 0 );
    }
  }
}


// ========================================================================
// ?Update@idEffectPhysicsDebrisEmitter@@QAAXABVidVec3@@ABVidMat3@@0HH@Z
// EA  : 0x82704B90
// RVA : 0x00704B90
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsDebrisEmitter::Update(
        idEffectPhysicsDebrisEmitter *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *drawScale3D,
        int currentTime,
        int gameMsPerFrame)
{
  BOOL active; // r7
  int v13; // r11
  char *v14; // r11
  bool v15; // cr58
  float v16; // r10
  float v17; // r9
  float v18; // r8
  float v19; // r7
  float v20; // r6
  int v21; // r28
  float *v22; // r11
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  int v26; // r11
  __int64 v27; // r7
  double z; // fp24
  double v29; // fp27
  double y; // fp23
  double v31; // fp26
  double x; // fp22
  double v33; // fp25
  unsigned int seed; // r11
  unsigned int v35; // r9
  double yaw; // fp13
  double roll; // fp12
  double pitch; // fp11
  double v39; // fp10
  double v40; // fp9
  double v41; // fp8
  __int64 v42; // r4
  __int64 v43; // r9
  unsigned int v44; // r5
  __int64 v45; // r11
  unsigned int v46; // r5
  double v47; // fp6
  double v48; // fp4
  int numPiecesInUse; // r10
  idVec3 v50; // [sp+78h] [-168h] BYREF
  idAngles v51; // [sp+88h] [-158h] BYREF
  float v52; // [sp+98h] [-148h]
  float v53; // [sp+9Ch] [-144h]
  float v54; // [sp+A0h] [-140h]
  idVec3 v55; // [sp+A8h] [-138h]
  idVec3 v56; // [sp+B8h] [-128h] BYREF
  idVec3 v57; // [sp+C8h] [-118h] BYREF
  idVec3 v58[12]; // [sp+D8h] [-108h] BYREF

  while ( this->serializeEmitCount > 0 )
  {
    active = this->active;
    v13 = 28 * (this->emitBufferPos + 6);
    --this->serializeEmitCount;
    v55 = vec3_origin;
    v14 = (char *)this + v13;
    v15 = !active;
    v16 = *((float *)v14 + 5);
    v17 = *(float *)v14;
    v18 = *((float *)v14 + 1);
    v19 = *((float *)v14 + 2);
    v20 = *((float *)v14 + 3);
    v21 = *((_DWORD *)v14 + 6);
    v53 = *((float *)v14 + 4);
    v52 = v20;
    v54 = v16;
    v50.x = v17;
    v50.y = v18;
    v50.z = v19;
    if ( !v15 )
    {
      if ( v21 >= 16 )
        v21 = 15;
      *(idVec3 *)v14 = v50;
      v22 = (float *)((char *)this + 28 * this->emitBufferPos);
      v23 = v52;
      v24 = v54;
      v25 = v53;
      v22[45] = v52;
      v22[47] = v24;
      v22[46] = v25;
      this->emitBuffer[this->emitBufferPos].count = v21;
      v26 = this->emitBufferPos + 1;
      HIDWORD(v27) = 10 * (v26 / 10);
      this->emitBufferPos = v26 % 10;
      if ( v21 > 0 )
      {
        z = v55.z;
        v29 = (float)((float)v23 * (float)1000.0);
        y = v55.y;
        v31 = (float)((float)v25 * (float)1000.0);
        x = v55.x;
        v33 = (float)((float)v24 * (float)1000.0);
        do
        {
          seed = this->random.seed;
          v56.y = 0.0;
          v56.z = 0.0;
          v35 = 1664525 * seed + 1013904223;
          LODWORD(v27) = (v35 >> 10) & 0x7FFF;
          this->random.seed = v35;
          v56.x = (float)((float)v27 * (float)0.0013733329) + (float)45.0;
          idAngles::ToForward(this: &v51, result: &v56);
          yaw = v51.yaw;
          roll = v51.roll;
          pitch = v51.pitch;
          v39 = v50.x;
          v40 = v50.y;
          v41 = v50.z;
          HIDWORD(v42) = 1664525 * this->random.seed + 1013904223;
          HIDWORD(v43) = v58;
          this->random.seed = HIDWORD(v42);
          LODWORD(v42) = (HIDWORD(v42) >> 10) & 0x7FFF;
          v44 = 1664525 * HIDWORD(v42) + 1013904223;
          LODWORD(v45) = (v44 >> 10) & 0x7FFF;
          this->random.seed = v44;
          HIDWORD(v45) = v44;
          v46 = 1664525 * v44 + 1013904223;
          v47 = (float)((float)v42 * (float)0.000030518509);
          LODWORD(v43) = (v46 >> 10) & 0x7FFF;
          this->random.seed = v46;
          HIDWORD(v42) = v46;
          v48 = (float)((float)v45 * (float)0.000030518509);
          HIDWORD(v45) = 1664525 * v46 + 1013904223;
          LODWORD(v42) = (HIDWORD(v45) >> 10) & 0x7FFF;
          this->random.seed = HIDWORD(v45);
          v51.pitch = (float)pitch * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0);
          v51.yaw = (float)yaw * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0);
          v51.roll = (float)((float)roll * (float)((float)((float)v42 * (float)0.000030518509) * (float)125.0))
                   + (float)200.0;
          v57.x = (float)((float)((float)((float)v43 * (float)0.00024414808) - (float)4.0)
                        - (float)((float)pitch
                                * (float)((float)((float)pitch
                                                * (float)((float)((float)v43 * (float)0.00024414808) - (float)4.0))
                                        + (float)((float)((float)roll
                                                        * (float)((float)((float)v47 * (float)8.0) - (float)4.0))
                                                + (float)((float)yaw
                                                        * (float)((float)((float)v48 * (float)8.0) - (float)4.0))))))
                + (float)v39;
          v57.y = (float)((float)((float)((float)v48 * (float)8.0) - (float)4.0)
                        - (float)((float)yaw
                                * (float)((float)((float)pitch
                                                * (float)((float)((float)v43 * (float)0.00024414808) - (float)4.0))
                                        + (float)((float)((float)roll
                                                        * (float)((float)((float)v47 * (float)8.0) - (float)4.0))
                                                + (float)((float)yaw
                                                        * (float)((float)((float)v48 * (float)8.0) - (float)4.0))))))
                + (float)v40;
          v57.z = (float)((float)((float)((float)v47 * (float)8.0) - (float)4.0)
                        - (float)((float)roll
                                * (float)((float)((float)pitch
                                                * (float)((float)((float)v43 * (float)0.00024414808) - (float)4.0))
                                        + (float)((float)((float)roll
                                                        * (float)((float)((float)v47 * (float)8.0) - (float)4.0))
                                                + (float)((float)yaw
                                                        * (float)((float)((float)v48 * (float)8.0) - (float)4.0))))))
                + (float)v41;
          v58[0].y = (float)((float)y + (float)(v51.yaw * (float)10.0)) + (float)v31;
          v58[0].x = (float)((float)(v51.pitch * (float)10.0) + (float)x) + (float)v29;
          v58[0].z = (float)((float)z + (float)(v51.roll * (float)10.0)) + (float)v33;
          idEffectPhysicsPieceEmitter::EmitPiece(
            this: &this->piecePhysics,
            emitTime: currentTime,
            pos: &v57,
            axes: &mat3_identity,
            impulsePoint: &v50,
            impulse: v58);
          --v21;
        }
        while ( v21 != 0 );
      }
    }
  }
  numPiecesInUse = this->piecePhysics.numPiecesInUse;
  --this->serializeEmitCount;
  if ( numPiecesInUse != 0 )
  {
    idEffectPhysicsPieceEmitter::UpdateSimulation(this: &this->piecePhysics, origin, axis, currentTime, gameMsPerFrame);
    idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: drawScale3D);
    idEffectPhysicsPieceEmitter::SubmitCollisionQueries(this: &this->piecePhysics, worldCollisionModelOnly: false);
  }
}


// ========================================================================
// ?Init@idEffectPhysicsDebrisEmitter@@QAAXPBVidDeclBreakable@@HAAVidClip@@PAVidRenderModelEffects@@@Z
// EA  : 0x82705060
// RVA : 0x00705060
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsDebrisEmitter::Init(
        idEffectPhysicsDebrisEmitter *this,
        const idDeclBreakable *breakableDebris,
        int entityNumber,
        idClip *clip,
        idRenderModelEffects *renderModelEffects)
{
  idRenderWorld *v10; // r27
  const idStr *v11; // r3
  idStr *v12; // r3
  const char **v13; // r27
  idRenderModelDiscreteAnimation *v14; // r3
  idRenderModel *v15; // r30
  idVec3 v16; // [sp+58h] [-A8h] BYREF
  idStr v17; // [sp+70h] [-90h] BYREF
  idStr v18; // [sp+90h] [-70h] BYREF

  if ( breakableDebris != nullptr )
  {
    v10 = common->RW(this: common);
    v11 = idStr::idStr(this: &v18, text: breakableDebris->name.str);
    v12 = operator+(result: &v17, a: v11, b: ".break");
    v13 = (const char **)v10->AllocRenderModel(this: v10, a2: v12->data, a3: true, a4: -1);
    idStr::FreeData(this: &v17);
    idStr::FreeData(this: &v18);
    if ( v13 != nullptr )
    {
      v14 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                                inptr: v13,
                                                VfDelta: 0,
                                                SrcType: &idRenderModel `RTTI Type Descriptor',
                                                TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                                isReference: 0);
      v15 = v14;
      if ( v14 != nullptr )
      {
        idEffectPhysicsPieceEmitter::Init(
          this: &this->piecePhysics,
          clip,
          tmc: clip->traceModelCache,
          model: v14,
          modelEffects: renderModelEffects,
          soundInfo: nullptr,
          entNum: entityNumber);
        this->piecePhysics.pieceLifeTime = 2500;
        this->piecePhysics.pieceFriction = 15.0;
        v16.x = 1.0;
        v16.y = 1.0;
        v16.z = 1.0;
        idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: &v16);
        if ( !v15->deferredPositionInitialized || !v15->useDeferredPosition )
          v15->g.origin = vec3_origin;
        v15->deferredOrigin = vec3_origin;
        idRenderModel::SetAxis(this: v15, a: &mat3_identity);
        v15->g.fovScale = 1.0;
        v15->g.modelDepthHack = 0.0;
        this->emitBufferPos = 0;
        this->serializeEmitCount = 0;
        this->skipFirstFrame = true;
        this->active = true;
        this->random.seed = 0;
      }
      else
      {
        idLib::Warning(fmt: " idEffectPhysicsDebrisEmitter::Init(): %s is not a breakable model.", v13[4]);
      }
    }
    else
    {
      idLib::Warning(
        fmt: " idEffectPhysicsDebrisEmitter::Init(): Model not found for breakable %s.",
        breakableDebris->name.str);
    }
  }
}


// ========================================================================
// __unwind$246939
// EA  : 0x8270525C
// RVA : 0x0070525C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.cpp
// ========================================================================

void _unwind_246939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$246940
// EA  : 0x82705284
// RVA : 0x00705284
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsdebrisemitter.cpp
// ========================================================================

void _unwind_246940()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}

