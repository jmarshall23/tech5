
// ========================================================================
// ?StopExplosionFX@idEffectPhysicsBreakable@@QAAXH@Z
// EA  : 0x826FA980
// RVA : 0x006FA980
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::StopExplosionFX(idEffectPhysicsBreakable *this, int currTime)
{
  int v4; // r31
  int v5; // r30

  v4 = 0;
  if ( this->explosionFX.num > 0 )
  {
    v5 = 0;
    do
    {
      idFXManager::StopAllFX(this: &this->explosionFX.list[v5], time: currTime, immediateStop: true);
      ++v4;
      ++v5;
    }
    while ( v4 < this->explosionFX.num );
  }
}


// ========================================================================
// ?UpdateModel@idEffectPhysicsBreakable@@QAAXABVidVec3@@ABVidMat3@@H@Z
// EA  : 0x826FA9D8
// RVA : 0x006FA9D8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::UpdateModel(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        int gameMsPerFrame)
{
  int v8; // r28
  int v9; // r29
  idEffectPhysicsRigidBody *v10; // r10
  const idMat3 *p_orientation; // r6
  const idVec3 *p_position; // r5
  double z; // fp9
  double v14; // fp2
  double v15; // fp0
  idRenderModelDiscreteAnimation *model; // r3
  int num; // r11
  int v18; // r29
  int v19; // r30
  idEffectPhysicsBreakable::idBreakableParticle *list; // r10
  int v21; // r11
  int v22; // r7
  idEffectPhysicsBreakable::idBreakableParticle *v23; // r11
  __int64 v24; // r6
  int v25; // r27
  int v26; // r29
  int v27; // r30
  idEffectPhysicsRigidBody **v28; // r9
  float *v29; // r11
  idGameLibEffects *gameLibEffects; // r3
  idEffectPhysicsBreakable::idSpark *v31; // r10
  double v32; // fp9
  double v33; // fp8
  double v34; // fp7
  double v37; // fp10
  double v38; // fp10
  float *v39; // r9
  int v40; // r8
  double v41; // fp27
  double v42; // fp7
  double v43; // fp9
  double v44; // fp2
  double v47; // fp6
  float v48[4]; // [sp+80h] [-E0h] BYREF
  idVec3 v49; // [sp+90h] [-D0h] BYREF
  idVec3 v50; // [sp+A0h] [-C0h] BYREF
  idMat3 v51[2]; // [sp+B0h] [-B0h] BYREF

  if ( this->model != nullptr )
  {
    v8 = 0;
    if ( this->rigidBodies.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = this->rigidBodies.list[v9];
        if ( v10->active )
        {
          p_orientation = &v10->currentState.orientation;
          p_position = &v10->currentState.position;
        }
        else
        {
          z = origin->z;
          v14 = (float)((float)(axis->mat[2].z * v10->currentState.position.z)
                      + (float)((float)(axis->mat[0].z * v10->currentState.position.x)
                              + (float)(axis->mat[1].z * v10->currentState.position.y)));
          v15 = (float)(origin->y
                      + (float)((float)(axis->mat[2].y * v10->currentState.position.z)
                              + (float)((float)(axis->mat[0].y * v10->currentState.position.x)
                                      + (float)(axis->mat[1].y * v10->currentState.position.y))));
          v48[0] = origin->x
                 + (float)((float)(v10->currentState.position.x * axis->mat[0].x)
                         + (float)((float)(axis->mat[1].x * v10->currentState.position.y)
                                 + (float)(axis->mat[2].x * v10->currentState.position.z)));
          v48[1] = v15;
          v48[2] = (float)z + (float)v14;
          p_orientation = idMat3::operator*(this: v51, result: &v10->currentState.orientation, a: axis);
          p_position = (const idVec3 *)v48;
        }
        idRenderModelDiscreteAnimation::SetPiecePosition(
          this: this->model,
          index: v8++,
          position: p_position,
          orientation: p_orientation);
        ++v9;
      }
      while ( v8 < this->rigidBodies.num );
    }
    model = this->model;
    if ( model != nullptr )
    {
      idRenderModelDiscreteAnimation::SetBasePiecePosition(this: model, position: origin, orientation: axis);
      idRenderModelDiscreteAnimation::Update(this: this->model);
    }
    if ( this->gameLibEffects != nullptr )
    {
      num = this->particles.num;
      if ( num > 0 && g_skipBreakableParticles.valueInteger == 0 )
      {
        v18 = num - 1;
        v19 = num - 1;
        do
        {
          list = this->particles.list;
          v21 = 1103515245 * this->random.seed + 12345;
          this->random.seed = v21;
          v22 = v21 >> 16;
          LODWORD(v24) = (v21 >> 16) & 0x7FFF;
          v23 = &this->particles.list[v19];
          HIDWORD(v24) = v23->startTime;
          idRenderModelEffects::AddParticles(
            this: this->gameLibEffects->effectsModel,
            particle: v23->particle,
            systemStartTime: SHIDWORD(v24),
            gameMsPerFrame,
            diversity: (float)((float)v24 * (float)0.000030518509),
            origin: (const idVec3 *)v22,
            axis: (const idMat3 *)&list[v19].pos,
            velocity: mat3_identity.mat,
            color: (const unsigned int *)&vec3_origin);
          --v18;
          --v19;
        }
        while ( v18 >= 0 );
      }
      v25 = 0;
      if ( this->sparks.num > 0 )
      {
        v26 = 0;
        v27 = 0;
        do
        {
          v28 = this->rigidBodies.list;
          v29 = (float *)v28[v27];
          if ( v29 != nullptr )
          {
            gameLibEffects = this->gameLibEffects;
            v31 = &this->sparks.list[v26];
            v32 = (float)(v29[14] * *(float *)(*(_DWORD *)v29 + 60));
            v33 = (float)(*(float *)(*(_DWORD *)v29 + 60) * v29[13]);
            v34 = (float)(v29[15] * *(float *)(*(_DWORD *)v29 + 60));
            _FP13 = (float)((float)((float)((float)v34 * (float)v34)
                                  + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f11, f13, f2, f0 }
            v37 = __frsqrte(_FP11);
            v38 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                                * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                        * (float)v37)
                                                                                - (float)1.5)
                                                                * (float)v37)
                                                        * (float)((float)((float)((float)v34 * (float)v34)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v37
                                                                                        * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v37)
                                                                        - (float)1.5)
                                                        * (float)v37))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v37
                                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                                + (float)((float)((float)v33 * (float)v33)
                                                                                        + (float)((float)v32 * (float)v32)))
                                                                        * (float)0.5))
                                                        * (float)v37)
                                                - (float)1.5)
                                * (float)v37));
            v49.z = (float)v34
                  * (float)((float)-(float)((float)((float)((float)v38
                                                          * (float)((float)((float)((float)v34 * (float)v34)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)v32 * (float)v32)))
                                                                  * (float)0.5))
                                                  * (float)v38)
                                          - (float)1.5)
                          * (float)v38);
            v49.y = (float)v32
                  * (float)((float)-(float)((float)((float)((float)v38
                                                          * (float)((float)((float)((float)v34 * (float)v34)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)v32 * (float)v32)))
                                                                  * (float)0.5))
                                                  * (float)v38)
                                          - (float)1.5)
                          * (float)v38);
            v49.x = (float)v33
                  * (float)((float)-(float)((float)((float)((float)v38
                                                          * (float)((float)((float)((float)v34 * (float)v34)
                                                                          + (float)((float)((float)v33 * (float)v33)
                                                                                  + (float)((float)v32 * (float)v32)))
                                                                  * (float)0.5))
                                                  * (float)v38)
                                          - (float)1.5)
                          * (float)v38);
            v39 = (float *)v28[v27];
            v40 = *(_DWORD *)v39;
            v41 = v39[1];
            v42 = (float)(v39[14] * *(float *)(*(_DWORD *)v39 + 60));
            v43 = (float)(v39[15] * *(float *)(*(_DWORD *)v39 + 60));
            v44 = (float)(v39[13] * *(float *)(*(_DWORD *)v39 + 60));
            _FP11 = (float)(v31->size
                          - (float)((float)__fsqrts((float)((float)((float)v44 * (float)v44)
                                                          + (float)((float)((float)v43 * (float)v43)
                                                                  + (float)((float)v42 * (float)v42))))
                                  * v31->velocityScale));
            __asm { fsel      f2, f11, f10, f2# length }
            v47 = (float)(v39[3] - (float)(v49.z * (float)_FP2));
            v50.y = v39[2] - (float)(v49.y * (float)_FP2);
            v50.z = v47;
            v50.x = (float)v41 - (float)(v49.x * (float)_FP2);
            idRenderModelEffects::AddTracer(
              this: gameLibEffects->effectsModel,
              mat: v31->material,
              origin: &v50,
              dir: &v49,
              maxDist: &vec3_origin,
              speed: 0.0,
              length: _FP2,
              height: v31->size,
              ensureVisual: v40,
              fractionInsured: 0.050000001,
              lifeTime: 0.0);
          }
          ++v25;
          ++v27;
          ++v26;
        }
        while ( v25 < this->sparks.num );
      }
    }
  }
}


// ========================================================================
// ?AddRadiusImpact@idEffectPhysicsBreakable@@QAAXHPBVidPhysics@@ABVidVec3@@MM@Z
// EA  : 0x826FADA0
// RVA : 0x006FADA0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsBreakable::AddRadiusImpact(
        idEffectPhysicsBreakable *this,
        int time,
        const idPhysics *physics,
        const idVec3 *pos,
        double radius,
        double power)
{
  int v6; // r2 OVERLAPPED
  int v12; // r18
  int v13; // r21
  char *v14; // r10
  idEffectPhysicsRigidBody *v15; // r31
  int v16; // ctr
  _WORD *v17; // r11
  int v18; // r9 OVERLAPPED
  __int128 v19; // r6 OVERLAPPED
  __int64 v20; // r8 OVERLAPPED
  const idMat3 *v21; // r30
  const idVec3 *v22; // r3
  double y; // fp13
  double z; // fp12
  const idMat3 *v25; // r3
  float *p_radius; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double v29; // fp25
  double v30; // fp24
  double v31; // fp23
  const idVec3 *v32; // r3
  double v33; // fp4
  double v34; // fp3
  double v35; // fp12
  float x; // r10
  double v37; // fp11
  float v38; // r11
  double v39; // fp10
  __int64 v40; // r9
  double v41; // fp0
  double valueFloat; // fp13
  double v43; // fp5
  double v44; // fp6
  double v45; // fp3
  int v46; // r5
  int v47; // r11
  __int128 v48; // r5
  double v50; // fp8
  double v51; // fp7
  int v53; // r11
  double v54; // fp12
  double v55; // fp9
  double v56; // fp13
  double v57; // fp4
  double v58; // fp8
  double v59; // fp1
  char v60; // [sp+4Eh] [-1D2h] BYREF
  __int16 v61; // [sp+50h] [-1D0h]
  __int16 v62; // [sp+52h] [-1CEh]
  unsigned __int16 v63; // [sp+54h] [-1CCh]
  __int16 v64; // [sp+56h] [-1CAh]
  unsigned __int16 v65; // [sp+58h] [-1C8h]
  __int16 v66; // [sp+5Ah] [-1C6h]
  float v67; // [sp+60h] [-1C0h]
  float v68; // [sp+64h] [-1BCh]
  float v69; // [sp+68h] [-1B8h]
  idBounds v70; // [sp+70h] [-1B0h] BYREF
  idVec3 v71; // [sp+88h] [-198h] BYREF
  idVec3 v72; // [sp+98h] [-188h] BYREF
  idSphere v73; // [sp+B0h] [-170h] BYREF
  idMat3 v74; // [sp+C0h] [-160h] BYREF
  __int64 v75; // [sp+E8h] [-138h]
  __int64 v76; // [sp+F0h] [-130h]
  __int64 v77; // [sp+F8h] [-128h]
  __int64 v78; // [sp+100h] [-120h]
  __int64 v79; // [sp+108h] [-118h]
  __int64 v80; // [sp+110h] [-110h]
  __int64 v81; // [sp+118h] [-108h]
  __int64 v82; // [sp+120h] [-100h]
  __int64 v83; // [sp+128h] [-F8h]
  idMat3 v84[3]; // [sp+130h] [-F0h] BYREF

  v12 = 0;
  if ( this->rigidBodies.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &v60;
      v15 = this->rigidBodies.list[v13];
      v16 = 6;
      v17 = (_WORD *)&v15->SPObject.axis.mat[2].z + 1;
      do
      {
        ++v17;
        v14 += 2;
        *(_WORD *)v14 = *v17;
        --v16;
      }
      while ( v16 != 0 );
      v18 = v61;
      LODWORD(v19) = v64;
      DWORD1(v19) = v63;
      HIDWORD(v19) = v66;
      DWORD2(v19) = v65;
      LODWORD(v20) = v62;
      HIDWORD(v20) = (__int16)v63;
      v83 = v19;
      DWORD2(v19) = (__int16)v65;
      v81 = v20;
      v79 = *(_QWORD *)((char *)&v19 - 4);
      v76 = *(_QWORD *)((char *)&v19 + 4);
      v78 = *(_QWORD *)(&v6 - 1);
      v77 = *(_QWORD *)&v18;
      v70.b[0].x = (float)*(__int64 *)&v18;
      v70.b[1].x = (float)v83;
      v70.b[0].y = (float)v20;
      v70.b[0].z = (float)*(__int64 *)((char *)&v19 - 4);
      v70.b[1].z = (float)*(__int64 *)(&v6 - 1);
      v70.b[1].y = (float)*(__int64 *)((char *)&v19 + 4);
      if ( !v15->active )
      {
        v21 = physics->GetAxis(this: physics, a2: 0);
        v22 = physics->GetOrigin(this: physics, a2: 0);
        idBounds::FromTransformedBounds(this: &v70, bounds: &v70, origin: v22, axis: v21);
      }
      y = pos->y;
      z = pos->z;
      v73.origin.x = pos->x;
      v73.radius = radius;
      v73.origin.y = y;
      v73.origin.z = z;
      if ( idBounds::SphereIntersection(this: &v70, s: &v73) )
      {
        if ( !v15->active )
        {
          v25 = physics->GetAxis(this: physics, a2: 0);
          p_radius = &v73.radius;
          p_z = (_DWORD *)&v25[-1].mat[2].z;
          for ( i = 9; i != 0; --i )
            *++p_radius = *(float *)++p_z;
          v29 = (float)((float)(v15->currentState.position.x * v74.mat[0].x)
                      + (float)((float)(v15->currentState.position.z * v74.mat[2].x)
                              + (float)(v15->currentState.position.y * v74.mat[1].x)));
          v30 = (float)((float)(v15->currentState.position.y * v74.mat[1].y)
                      + (float)((float)(v15->currentState.position.x * v74.mat[0].y)
                              + (float)(v15->currentState.position.z * v74.mat[2].y)));
          v31 = (float)((float)(v15->currentState.position.y * v74.mat[1].z)
                      + (float)((float)(v15->currentState.position.x * v74.mat[0].z)
                              + (float)(v15->currentState.position.z * v74.mat[2].z)));
          v32 = physics->GetOrigin(this: physics, a2: 0);
          v33 = (float)(v32->y + (float)v30);
          v34 = (float)(v32->z + (float)v31);
          v15->currentState.position.x = v32->x + (float)v29;
          v15->currentState.position.y = v33;
          v15->currentState.position.z = v34;
          idEffectPhysicsBroadPhase::SetObjectPosition(
            this: v15->properties->broadPhase,
            object: &v15->SPObject,
            origin: &v15->currentState.position,
            axis: &v15->currentState.orientation,
            bounds: nullptr);
          v15->currentState.orientation = *idMat3::operator*(this: v84, result: &v15->currentState.orientation, a: &v74);
          idEffectPhysicsBroadPhase::SetObjectPosition(
            this: v15->properties->broadPhase,
            object: &v15->SPObject,
            origin: &v15->currentState.position,
            axis: &v15->currentState.orientation,
            bounds: nullptr);
          v15->active = true;
          v15->SPObject.motion.ignore = false;
        }
        v35 = pos->y;
        x = v15->currentState.position.x;
        v37 = pos->z;
        v38 = v15->currentState.position.z;
        v39 = pos->x;
        HIDWORD(v40) = this->random.seed;
        v41 = idMath::FLT_SMALLEST_NON_DENORMAL;
        valueFloat = g_breakableSpin.valueFloat;
        v68 = v15->currentState.position.y;
        v67 = x;
        v69 = v38;
        v43 = (float)(v38 - (float)v37);
        v44 = (float)(v68 - (float)v35);
        v45 = (float)(x - (float)v39);
        v46 = 1103515245 * HIDWORD(v40) + 12345;
        this->random.seed = v46;
        v47 = 1103515245 * v46 + 12345;
        DWORD2(v48) = (v46 >> 16) & 0x7FFF;
        DWORD1(v48) = v47 >> 16;
        v82 = *(_QWORD *)((char *)&v48 + 4);
        LODWORD(v40) = (v47 >> 16) & 0x7FFF;
        v80 = v40;
        v50 = (float)((float)((float)((float)(x - (float)v39) * (float)(x - (float)v39))
                            + (float)((float)((float)v43 * (float)v43) + (float)((float)v44 * (float)v44)))
                    * (float)0.5);
        _FP10 = (float)((float)((float)((float)(x - (float)v39) * (float)(x - (float)v39))
                              + (float)((float)((float)v43 * (float)v43) + (float)((float)v44 * (float)v44)))
                      - (float)v41);
        v51 = g_breakableSpin.valueFloat;
        this->random.seed = v47;
        __asm { fsel      f2, f10, f12, f0 }
        v53 = 1103515245 * v47 + 12345;
        LODWORD(v48) = (v53 >> 16) & 0x7FFF;
        v54 = __frsqrte(_FP2);
        v75 = v48;
        v55 = (float)((float)((float)((float)*(__int64 *)((char *)&v48 + 4) * (float)0.000061037019) - (float)1.0)
                    * (float)valueFloat);
        v56 = g_breakableSpin.valueFloat;
        this->random.seed = v53;
        v57 = pos->z;
        v58 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)v50) * (float)v54) - (float)1.5) * (float)v54)
                                                                                            * (float)v50)
                                                                                    * (float)((float)-(float)((float)((float)((float)v54 * (float)v50) * (float)v54) - (float)1.5)
                                                                                            * (float)v54))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v54 * (float)v50)
                                                                                            * (float)v54)
                                                                                    - (float)1.5)
                                                                    * (float)v54))
                                                    * (float)v50)
                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)v50) * (float)v54) - (float)1.5)
                                                                                            * (float)v54)
                                                                                    * (float)v50)
                                                                            * (float)((float)-(float)((float)((float)((float)v54 * (float)v50) * (float)v54) - (float)1.5)
                                                                                    * (float)v54))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v54 * (float)v50)
                                                                                    * (float)v54)
                                                                            - (float)1.5)
                                                            * (float)v54)))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)v50)
                                                                                            * (float)v54)
                                                                                    - (float)1.5)
                                                                    * (float)v54)
                                                            * (float)v50)
                                                    * (float)((float)-(float)((float)((float)((float)v54 * (float)v50)
                                                                                    * (float)v54)
                                                                            - (float)1.5)
                                                            * (float)v54))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v54 * (float)v50) * (float)v54) - (float)1.5)
                                    * (float)v54)));
        v59 = (float)((float)((float)((float)((float)v40 * (float)0.000061037019) - (float)1.0) * (float)v51) + pos->y);
        v72.x = pos->x
              + (float)((float)((float)((float)(__int64)v48 * (float)0.000061037019) - (float)1.0) * (float)v56);
        v71.x = (float)((float)v45 * (float)v58) * (float)power;
        v72.y = v59;
        v72.z = (float)v57 + (float)v55;
        v71.y = (float)((float)v44 * (float)v58) * (float)power;
        v71.z = (float)((float)v43 * (float)v58) * (float)power;
        idEffectPhysicsRigidBody::ApplyImpulse(this: v15, point: &v72, impulse: &v71);
      }
      ++v12;
      ++v13;
    }
    while ( v12 < this->rigidBodies.num );
  }
}


// ========================================================================
// ?ApplyImpulseToBody@idEffectPhysicsBreakable@@QAAXHPBVidPhysics@@ABVidVec3@@1@Z
// EA  : 0x826FB280
// RVA : 0x006FB280
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::ApplyImpulseToBody(
        idEffectPhysicsBreakable *this,
        int bodyNum,
        const idPhysics *physics,
        const idVec3 *pos,
        const idVec3 *impulse)
{
  idEffectPhysicsRigidBody *v8; // r31
  const idMat3 *v9; // r3
  char *v10; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  const idVec3 *v16; // r3
  double v17; // fp4
  double v18; // fp3
  const idMat3 *v19; // r3
  char v20; // [sp+4Ch] [-A4h] BYREF
  idMat3 v21; // [sp+50h] [-A0h] BYREF
  idMat3 v22; // [sp+80h] [-70h] BYREF

  if ( physics != nullptr && bodyNum >= 0 && bodyNum < this->rigidBodies.num )
  {
    v8 = this->rigidBodies.list[bodyNum];
    if ( !v8->active )
    {
      v9 = physics->GetAxis(this: physics, a2: 0);
      v10 = &v20;
      p_z = (_DWORD *)&v9[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v10 += 4;
        *(_DWORD *)v10 = *p_z;
      }
      v13 = (float)((float)(v8->currentState.position.z * v21.mat[2].z)
                  + (float)((float)(v8->currentState.position.x * v21.mat[0].z)
                          + (float)(v8->currentState.position.y * v21.mat[1].z)));
      v14 = (float)((float)(v8->currentState.position.x * v21.mat[0].x)
                  + (float)((float)(v8->currentState.position.y * v21.mat[1].x)
                          + (float)(v8->currentState.position.z * v21.mat[2].x)));
      v15 = (float)((float)(v8->currentState.position.y * v21.mat[1].y)
                  + (float)((float)(v8->currentState.position.x * v21.mat[0].y)
                          + (float)(v8->currentState.position.z * v21.mat[2].y)));
      v16 = physics->GetOrigin(this: physics, a2: 0);
      v17 = (float)(v16->y + (float)v15);
      v18 = (float)(v16->z + (float)v13);
      v8->currentState.position.x = v16->x + (float)v14;
      v8->currentState.position.y = v17;
      v8->currentState.position.z = v18;
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v8->properties->broadPhase,
        object: &v8->SPObject,
        origin: &v8->currentState.position,
        axis: &v8->currentState.orientation,
        bounds: nullptr);
      v19 = idMat3::operator*(this: &v22, result: &v8->currentState.orientation, a: &v21);
      idEffectPhysicsRigidBody::SetOrientation(this: v8, m: v19);
      v8->active = true;
      v8->SPObject.motion.ignore = false;
    }
    idEffectPhysicsRigidBody::ApplyImpulse(this: v8, point: pos, impulse);
  }
}


// ========================================================================
// ?ActivateNoisy@idEffectPhysicsBreakable@@AAA_NHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826FB410
// RVA : 0x006FB410
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEffectPhysicsBreakable::ActivateNoisy(
        idEffectPhysicsBreakable *this,
        int num,
        const idVec3 *origin,
        const idMat3 *axis)
{
  int v4; // r3
  idEffectPhysicsRigidBody *v6; // r31
  __int64 v7; // r4
  int v8; // r9
  __int64 v9; // r7
  int v10; // r11
  __int64 v11; // r9
  double v12; // fp9
  int v13; // r11
  double x; // fp8
  double z; // fp7
  double y; // fp1
  double v17; // fp5
  double v18; // fp9
  double v19; // fp31
  double v20; // fp3
  double v21; // fp30
  double v22; // fp10
  double v23; // fp28
  double v24; // fp6
  double v25; // fp29
  double v26; // fp27
  double v27; // fp4
  double v28; // fp2
  const idMat3 *v29; // r3
  idVec3 v31; // [sp+50h] [-90h] BYREF
  idMat3 v32[2]; // [sp+60h] [-80h] BYREF

  v6 = *(idEffectPhysicsRigidBody **)(4 * num + *(_DWORD *)(v4 + 16));
  if ( v6->active )
    return 0;
  v8 = 1103515245 * *(_DWORD *)(HIDWORD(v7) + 252) + 12345;
  HIDWORD(v9) = 1103515245;
  *(_DWORD *)(HIDWORD(v7) + 252) = v8;
  LODWORD(v9) = (v8 >> 16) & 0x7FFF;
  *(_QWORD *)&v31.x = v9;
  v10 = 1103515245 * v8 + 12345;
  *(_DWORD *)(HIDWORD(v7) + 252) = v10;
  HIDWORD(v11) = v10 >> 16;
  v12 = (double)*(__int64 *)&v31.x;
  LODWORD(v11) = (v10 >> 16) & 0x7FFF;
  v13 = 1103515245 * v10 + 12345;
  *(_DWORD *)(HIDWORD(v7) + 252) = v13;
  LODWORD(v7) = (v13 >> 16) & 0x7FFF;
  *(_QWORD *)&v31.x = v7;
  x = axis->mat[2].x;
  z = axis->mat[1].z;
  y = axis->mat[0].y;
  v17 = axis->mat[1].x;
  v19 = axis->mat[2].y;
  v20 = axis->mat[0].x;
  v21 = axis->mat[2].z;
  v22 = (float)((float)((float)v12 * (float)0.000061037019) - (float)1.0);
  v18 = axis->mat[0].z;
  v23 = origin->y;
  v24 = axis->mat[1].y;
  v25 = origin->x;
  v26 = origin->z;
  v31.x = (float)((float)((float)v7 * (float)0.000061037019) - (float)1.0) * (float)1500.0;
  v31.z = (float)v22 * (float)1000.0;
  v31.y = (float)((float)((float)v11 * (float)0.000061037019) - (float)1.0) * (float)1500.0;
  v27 = (float)((float)((float)v21 * v6->currentState.position.z)
              + (float)((float)((float)v18 * v6->currentState.position.x)
                      + (float)((float)z * v6->currentState.position.y)));
  v28 = (float)((float)v25
              + (float)((float)(v6->currentState.position.x * (float)v20)
                      + (float)((float)((float)v17 * v6->currentState.position.y)
                              + (float)((float)x * v6->currentState.position.z))));
  v6->currentState.position.y = (float)v23
                              + (float)((float)((float)v19 * v6->currentState.position.z)
                                      + (float)((float)((float)y * v6->currentState.position.x)
                                              + (float)((float)v24 * v6->currentState.position.y)));
  v6->currentState.position.x = v28;
  v6->currentState.position.z = (float)v26 + (float)v27;
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: v6->properties->broadPhase,
    object: &v6->SPObject,
    origin: &v6->currentState.position,
    axis: &v6->currentState.orientation,
    bounds: nullptr);
  v29 = idMat3::operator*(this: v32, result: &v6->currentState.orientation, a: axis);
  idEffectPhysicsRigidBody::SetOrientation(this: v6, m: v29);
  idEffectPhysicsRigidBody::ApplyImpulse(this: v6, point: &v6->currentState.position, impulse: &v31);
  v6->active = true;
  v6->SPObject.motion.ignore = false;
  return 1;
}


// ========================================================================
// ?ApplyForce@idEffectPhysicsBreakable@@QAAXABVidVec3@@ABVidMat3@@0@Z
// EA  : 0x826FB610
// RVA : 0x006FB610
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::ApplyForce(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *force)
{
  int v8; // r20
  int v9; // r21
  idEffectPhysicsRigidBody *v10; // r31
  double y; // fp9
  double z; // fp5
  double v13; // fp2
  double v14; // fp1
  idMat3 v15[4]; // [sp+50h] [-90h] BYREF

  v8 = 0;
  if ( this->rigidBodies.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->rigidBodies.list[v9];
      if ( !v10->active )
      {
        y = origin->y;
        z = origin->z;
        v13 = (float)((float)(axis->mat[2].y * v10->currentState.position.z)
                    + (float)((float)(axis->mat[0].y * v10->currentState.position.x)
                            + (float)(axis->mat[1].y * v10->currentState.position.y)));
        v14 = (float)((float)(axis->mat[2].z * v10->currentState.position.z)
                    + (float)((float)(axis->mat[0].z * v10->currentState.position.x)
                            + (float)(axis->mat[1].z * v10->currentState.position.y)));
        v10->currentState.position.x = origin->x
                                     + (float)((float)(v10->currentState.position.x * axis->mat[0].x)
                                             + (float)((float)(axis->mat[1].x * v10->currentState.position.y)
                                                     + (float)(axis->mat[2].x * v10->currentState.position.z)));
        v10->currentState.position.y = (float)y + (float)v13;
        v10->currentState.position.z = (float)z + (float)v14;
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v10->properties->broadPhase,
          object: &v10->SPObject,
          origin: &v10->currentState.position,
          axis: &v10->currentState.orientation,
          bounds: nullptr);
        v10->currentState.orientation = *idMat3::operator*(this: v15, result: &v10->currentState.orientation, a: axis);
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v10->properties->broadPhase,
          object: &v10->SPObject,
          origin: &v10->currentState.position,
          axis: &v10->currentState.orientation,
          bounds: nullptr);
        idEffectPhysicsRigidBody::ApplyImpulse(this: v10, point: &v10->currentState.position, impulse: force);
        v10->active = true;
        v10->SPObject.motion.ignore = false;
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->rigidBodies.num );
  }
}


// ========================================================================
// ?DrawCollisionModels@idEffectPhysicsBreakable@@QAAXHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826FB7A8
// RVA : 0x006FB7A8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::DrawCollisionModels(
        idEffectPhysicsBreakable *this,
        unsigned int single,
        const idVec3 *offset,
        const idMat3 *axis)
{
  signed int v7; // r11
  int num; // r19
  signed int v9; // r23
  int v10; // r29
  char *v11; // r10
  idEffectPhysicsRigidBody **list; // r9
  idEffectPhysicsRigidBody *v13; // r7
  int v14; // ctr
  float y; // r4
  float z; // r3
  int traceModelIndex; // r31
  idEffectPhysicsRigidBody *p_z; // r11
  double v19; // fp10
  double v20; // fp5
  double v21; // fp3
  idRenderWorld *v22; // r31
  __int64 v23; // r6
  __int64 v24; // r10
  __int64 v25; // r8
  va *v26; // r3
  int v27; // [sp+8h] [-1128h]
  int v28; // [sp+Ch] [-1124h]
  int v29; // [sp+10h] [-1120h]
  int v30; // [sp+14h] [-111Ch]
  int v31; // [sp+18h] [-1118h]
  int v32; // [sp+1Ch] [-1114h]
  int v33; // [sp+20h] [-1110h]
  int v34; // [sp+24h] [-110Ch]
  int v35; // [sp+28h] [-1108h]
  int v36; // [sp+2Ch] [-1104h]
  int v37; // [sp+30h] [-1100h]
  int v38; // [sp+34h] [-10FCh]
  int v39; // [sp+38h] [-10F8h]
  int v40; // [sp+3Ch] [-10F4h]
  int v41; // [sp+40h] [-10F0h]
  int v42; // [sp+44h] [-10ECh]
  int v43; // [sp+48h] [-10E8h]
  int v44; // [sp+4Ch] [-10E4h]
  int v45; // [sp+50h] [-10E0h]
  idVec3 v46; // [sp+60h] [-10D0h] BYREF
  char v47; // [sp+6Ch] [-10C4h] BYREF
  idMat3 v48; // [sp+70h] [-10C0h] BYREF
  va v49; // [sp+A0h] [-1090h] BYREF

  v7 = ((single >> 31) - 1) & single;
  num = single + 1;
  if ( (single & 0x80000000) != 0 )
    num = this->rigidBodies.num;
  v9 = ((single >> 31) - 1) & single;
  if ( v7 < num )
  {
    v10 = v7;
    do
    {
      v11 = &v47;
      list = this->rigidBodies.list;
      v13 = list[v10];
      v14 = 9;
      y = v13->currentState.position.y;
      z = v13->currentState.position.z;
      traceModelIndex = v13->properties->traceModelIndex;
      v46.x = v13->currentState.position.x;
      v46.y = y;
      v46.z = z;
      p_z = (idEffectPhysicsRigidBody *)&list[v10]->currentState.position.z;
      do
      {
        p_z = (idEffectPhysicsRigidBody *)((char *)p_z + 4);
        v11 += 4;
        *(_DWORD *)v11 = p_z->properties;
        --v14;
      }
      while ( v14 != 0 );
      if ( !list[v10]->active )
      {
        v19 = offset->y;
        v20 = (float)((float)(axis->mat[0].y * v46.x)
                    + (float)((float)(axis->mat[1].y * v46.y) + (float)(axis->mat[2].y * v46.z)));
        v21 = (float)(offset->x
                    + (float)((float)(axis->mat[0].x * v46.x)
                            + (float)((float)(axis->mat[1].x * v46.y) + (float)(axis->mat[2].x * v46.z))));
        v46.z = offset->z
              + (float)((float)(axis->mat[0].z * v46.x)
                      + (float)((float)(axis->mat[1].z * v46.y) + (float)(axis->mat[2].z * v46.z)));
        v46.x = v21;
        v46.y = (float)v19 + (float)v20;
        idMat3::operator*=(this: &v48, a: axis);
      }
      idCollisionModelManager::DrawCollisionModel(
        this: collisionModelManager,
        model: this->broadPhase.traceModelCache->cache.list[traceModelIndex]->collisionModel,
        modelJoints: nullptr,
        modelOrigin: &v46,
        modelAxis: &v48,
        viewOrigin: &vec3_origin,
        viewAxis: &mat3_identity,
        radius: 0.0,
        lifeTime: 4 * traceModelIndex,
        a10: v27,
        a11: v28,
        a12: v29,
        a13: v30,
        a14: v31,
        a15: v32,
        a16: v33,
        a17: v34,
        a18: v35,
        a19: v36,
        a20: v37,
        a21: v38,
        a22: v39,
        a23: v40,
        a24: v41,
        a25: v42,
        a26: v43,
        a27: v44,
        a28: v45,
        a29: 0);
      if ( common->RW(this: common) != nullptr )
      {
        v22 = common->RW(this: common);
        HIDWORD(v23) = v9 + 1;
        v26 = va::va(
                this: &v49,
                fmt: "%d",
                a3: v23,
                a4: v25,
                a5: v24,
                a6: v27,
                a7: v28,
                a8: v29,
                a9: v30,
                a10: v31,
                a11: v32);
        ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v22->DebugText)(
          a1: v22,
          a2: v26,
          a3: &v46,
          a4: v22->DebugText,
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.1);
      }
      ++v9;
      ++v10;
    }
    while ( v9 < num );
  }
}


// ========================================================================
// ?ActivateAllNow@idEffectPhysicsBreakable@@QAA_NABVidVec3@@ABVidMat3@@@Z
// EA  : 0x826FB9E8
// RVA : 0x006FB9E8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEffectPhysicsBreakable::ActivateAllNow(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        __int64 axis)
{
  int v3; // r2 OVERLAPPED
  int v6; // r30
  int v7; // r19
  int v8; // r20
  int v9; // r21
  idEffectPhysicsRigidBody *v10; // r31
  int v11; // r11
  int v12; // r5
  __int64 v13; // r8
  int v14; // r11
  int v15; // r3
  double v16; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp7
  double v20; // fp8
  double v21; // fp4
  double v22; // fp0
  double v23; // fp2
  double v24; // fp12
  double y; // fp5
  double x; // fp6
  double z; // fp27
  double v28; // fp8
  double v29; // fp9
  char v30; // r11
  __int64 v32; // [sp+50h] [-F0h]
  idVec3 v33; // [sp+68h] [-D8h] BYREF
  idMat3 v34[2]; // [sp+80h] [-C0h] BYREF

  v6 = HIDWORD(axis);
  v7 = 0;
  v8 = 0;
  if ( this->rigidBodies.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->rigidBodies.list[v9];
      if ( v10->active )
      {
        v30 = 0;
      }
      else
      {
        v11 = 1103515245 * this->random.seed + 12345;
        this->random.seed = v11;
        LODWORD(axis) = (v11 >> 16) & 0x7FFF;
        v32 = axis;
        v12 = 1103515245 * v11 + 12345;
        this->random.seed = v12;
        HIDWORD(v13) = v12 >> 16;
        v14 = 1103515245 * v12 + 12345;
        v15 = (v12 >> 16) & 0x7FFF;
        this->random.seed = v14;
        LODWORD(v13) = (v14 >> 16) & 0x7FFF;
        v16 = *(float *)(v6 + 16);
        v17 = *(float *)(v6 + 20);
        v18 = *(float *)(v6 + 24);
        v19 = *(float *)(v6 + 4);
        v20 = *(float *)(v6 + 12);
        v21 = *(float *)(v6 + 8);
        v22 = *(float *)(v6 + 28);
        v23 = *(float *)v6;
        y = origin->y;
        x = origin->x;
        z = origin->z;
        v24 = *(float *)(v6 + 32);
        v33.y = (float)((float)((float)*(__int64 *)(&v3 - 1) * (float)0.000061037019) - (float)1.0) * (float)1500.0;
        v33.x = (float)((float)((float)v13 * (float)0.000061037019) - (float)1.0) * (float)1500.0;
        v33.z = (float)((float)((float)v32 * (float)0.000061037019) - (float)1.0) * (float)1000.0;
        v29 = (float)((float)(v10->currentState.position.x * (float)v23)
                    + (float)((float)((float)v20 * v10->currentState.position.y)
                            + (float)((float)v18 * v10->currentState.position.z)));
        v28 = (float)((float)((float)v24 * v10->currentState.position.z)
                    + (float)((float)((float)v21 * v10->currentState.position.x)
                            + (float)((float)v17 * v10->currentState.position.y)));
        v10->currentState.position.y = (float)y
                                     + (float)((float)((float)v22 * v10->currentState.position.z)
                                             + (float)((float)((float)v19 * v10->currentState.position.x)
                                                     + (float)((float)v16 * v10->currentState.position.y)));
        v10->currentState.position.z = (float)z + (float)v28;
        v10->currentState.position.x = (float)x + (float)v29;
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v10->properties->broadPhase,
          object: &v10->SPObject,
          origin: &v10->currentState.position,
          axis: &v10->currentState.orientation,
          bounds: nullptr);
        v10->currentState.orientation = *idMat3::operator*(
                                           this: v34,
                                           result: &v10->currentState.orientation,
                                           a: (const idMat3 *)v6);
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v10->properties->broadPhase,
          object: &v10->SPObject,
          origin: &v10->currentState.position,
          axis: &v10->currentState.orientation,
          bounds: nullptr);
        idEffectPhysicsRigidBody::ApplyImpulse(this: v10, point: &v10->currentState.position, impulse: &v33);
        v10->active = true;
        v30 = 1;
        v10->SPObject.motion.ignore = false;
      }
      if ( v30 != 0 )
        v7 = 1;
      ++v8;
      ++v9;
    }
    while ( v8 < this->rigidBodies.num );
  }
  return v7;
}


// ========================================================================
// ?CollideWith@idEffectPhysicsBreakable@@QAAXABVidVec3@@PBVidPhysics@@1M@Z
// EA  : 0x826FBEE0
// RVA : 0x006FBEE0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsBreakable::CollideWith(
        idEffectPhysicsBreakable *this,
        const idVec3 *impactPoint,
        const idPhysics *physics,
        idVec3 *attacker,
        double extra)
{
  double v10; // fp31
  idVec3 *v11; // r3
  double v12; // fp12
  double v13; // fp13
  double v14; // fp9
  double v15; // fp6
  double v17; // fp4
  double v19; // fp2
  double v20; // fp13
  double v21; // fp31
  int num; // r4
  int v23; // r27
  int v24; // r22
  int v25; // r9
  _WORD *v26; // r10
  idEffectPhysicsRigidBody *v27; // r30
  int v28; // ctr
  _WORD *v29; // r11
  const idMat3 *v30; // r29
  const idVec3 *v31; // r3
  const idBounds *v32; // r3
  int *v33; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const idMat3 *v46; // r3
  __int16 *p_granularity; // r10
  _DWORD *v48; // r11
  int j; // ctr
  double v50; // fp28
  double v51; // fp27
  double v52; // fp26
  const idVec3 *v53; // r3
  double v54; // fp6
  double v55; // fp4
  const idMat3 *v56; // r3
  int v57; // r11
  int v58; // r22
  encounterGroupRole_t *list; // r21
  double v60; // fp27
  double v61; // fp26
  double v62; // fp25
  double v63; // fp30
  encounterGroupRole_t *v64; // r24
  double valueFloat; // fp12
  idEffectPhysicsRigidBody *v66; // r30
  int v67; // r11
  __int128 v68; // r6 OVERLAPPED
  double v69; // fp11
  double v70; // fp13
  int v71; // r9
  double x; // fp10
  double v73; // fp9
  double z; // fp8
  int v75; // r7
  idPhysics_vtbl *v76; // r11
  double v77; // fp4
  double v78; // fp3
  double v79; // fp1
  double v82; // fp0
  double v83; // fp5
  double v84; // fp22
  double v85; // fp23
  double v86; // fp21
  double v87; // fp12
  double v88; // fp10
  double v89; // fp20
  double v90; // fp19
  double v91; // fp18
  double v92; // fp1
  double y; // fp2
  double v94; // fp13
  idVec3 v95; // [sp+50h] [-1D0h] BYREF
  unsigned __int64 v96; // [sp+60h] [-1C0h] BYREF
  idBounds v97; // [sp+68h] [-1B8h] BYREF
  float v98; // [sp+80h] [-1A0h]
  int v99; // [sp+8Ch] [-194h] BYREF
  idBounds v100; // [sp+90h] [-190h] BYREF
  idVec3 v101; // [sp+A8h] [-178h] BYREF
  idList<enum encounterGroupRole_t,5> v102; // [sp+C0h] [-160h] BYREF
  idMat3 v103; // [sp+D0h] [-150h] BYREF
  __int64 v104; // [sp+F8h] [-128h]
  idBounds v105; // [sp+100h] [-120h] BYREF
  idMat3 v106[4]; // [sp+120h] [-100h] BYREF

  if ( physics != nullptr && this->rigidBodies.num != 0 )
  {
    v10 = ((double (__fastcall *)(idVec3 *, int))*(_DWORD *)(LODWORD(attacker->x) + 20))(a1: attacker, a2: -1);
    v11 = (idVec3 *)(*(int (__fastcall **)(idBounds *, idVec3 *, _DWORD))(LODWORD(attacker->x) + 88))(
                      a1: &v97,
                      a2: attacker,
                      a3: 0);
    v12 = (float)(v11->y * (float)v10);
    v13 = (float)(v11->x * (float)v10);
    v14 = (float)(v11->z * (float)v10);
    v95.x = v11->x * (float)v10;
    v95.y = v12;
    v95.z = v14;
    v15 = (float)((float)((float)v14 * (float)v14)
                + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)));
    _FP5 = (float)((float)((float)((float)v14 * (float)v14)
                         + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v17 = (float)((float)((float)((float)v14 * (float)v14)
                        + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))
                * (float)0.5);
    __asm { fsel      f3, f5, f6, f0 }
    v19 = __frsqrte(_FP3);
    v20 = (float)-(float)((float)((float)((float)v19
                                        * (float)((float)((float)((float)v14 * (float)v14)
                                                        + (float)((float)((float)v13 * (float)v13)
                                                                + (float)((float)v12 * (float)v12)))
                                                * (float)0.5))
                                * (float)v19)
                        - (float)1.5);
    v21 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v20 * (float)v19)
                                                                                                * (float)v17)
                                                                                        * (float)((float)v20 * (float)v19))
                                                                                - (float)1.5)
                                                                * (float)((float)v20 * (float)v19))
                                                        * (float)v17)
                                                * (float)((float)-(float)((float)((float)((float)((float)v20 * (float)v19)
                                                                                        * (float)v17)
                                                                                * (float)((float)v20 * (float)v19))
                                                                        - (float)1.5)
                                                        * (float)((float)v20 * (float)v19)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)v20 * (float)v19) * (float)v17)
                                                        * (float)((float)v20 * (float)v19))
                                                - (float)1.5)
                                * (float)((float)v20 * (float)v19)))
                * (float)v15);
    idVec3::NormalizeFast(this: &v95);
    idList<breakableIsland_t,59>::idList<breakableIsland_t,59>(this: (idList<int,59> *)&v102);
    num = this->rigidBodies.num;
    v23 = 0;
    v24 = 0;
    HIDWORD(v96) = 0;
    if ( num > 0 )
    {
      v25 = 0;
      do
      {
        v26 = (_WORD *)&v96 + 3;
        v27 = this->rigidBodies.list[v25];
        v28 = 6;
        v29 = (_WORD *)&v27->SPObject.axis.mat[2].z + 1;
        do
        {
          *++v26 = *++v29;
          --v28;
        }
        while ( v28 != 0 );
        idBoundsShort::ToBounds(this: (idBoundsShort *)&v105, result: &v97);
        if ( !v27->active )
        {
          v30 = physics->GetAxis(this: physics, a2: 0);
          v31 = physics->GetOrigin(this: physics, a2: 0);
          idBounds::FromTransformedBounds(this: &v105, bounds: &v105, origin: v31, axis: v30);
        }
        v32 = (const idBounds *)(*(int (__fastcall **)(idVec3 *, int))(LODWORD(attacker->x) + 44))(a1: attacker, a2: -1);
        v33 = &v99;
        p_z = (_DWORD *)&v32[-1].b[1].z;
        for ( i = 6; i != 0; --i )
          *++v33 = *++p_z;
        _FP2 = (float)((float)__fabs(v100.b[0].y) - (float)__fabs(v100.b[1].y));
        _FP1 = (float)((float)__fabs(v100.b[0].x) - (float)__fabs(v100.b[1].x));
        _FP0 = (float)((float)__fabs(v100.b[0].z) - (float)__fabs(v100.b[1].z));
        __asm
        {
          fsel      f13, f2, f10, f12
          fsel      f12, f1, f7, f8
          fsel      f11, f0, f3, f4
        }
        _FP10 = (float)((float)_FP12 - (float)_FP13);
        __asm { fsel      f9, f10, f12, f13 }
        _FP8 = (float)((float)_FP9 - (float)_FP11);
        __asm { fsel      f7, f8, f9, f11 }
        if ( (unsigned __int8)idBounds::IntersectsBounds(
                                this: &v105,
                                a: &v100,
                                epsilon: (float)((float)((float)_FP7 * (float)extra) + (float)0.5)) != 0
          && !v27->active )
        {
          v46 = physics->GetAxis(this: physics, a2: 0);
          p_granularity = &v102.granularity;
          v48 = (_DWORD *)&v46[-1].mat[2].z;
          for ( j = 9; j != 0; --j )
          {
            ++v48;
            p_granularity += 2;
            *(_DWORD *)p_granularity = *v48;
          }
          v50 = (float)((float)(v27->currentState.position.x * v103.mat[0].x)
                      + (float)((float)(v103.mat[2].x * v27->currentState.position.z)
                              + (float)(v103.mat[1].x * v27->currentState.position.y)));
          v51 = (float)((float)(v103.mat[1].z * v27->currentState.position.y)
                      + (float)((float)(v103.mat[0].z * v27->currentState.position.x)
                              + (float)(v103.mat[2].z * v27->currentState.position.z)));
          v52 = (float)((float)(v103.mat[1].y * v27->currentState.position.y)
                      + (float)((float)(v103.mat[0].y * v27->currentState.position.x)
                              + (float)(v103.mat[2].y * v27->currentState.position.z)));
          v53 = physics->GetOrigin(this: physics, a2: 0);
          v54 = (float)(v53->z + (float)v51);
          v55 = (float)(v53->y + (float)v52);
          v27->currentState.position.x = (float)v50 + v53->x;
          v27->currentState.position.y = v55;
          v27->currentState.position.z = v54;
          idEffectPhysicsBroadPhase::SetObjectPosition(
            this: v27->properties->broadPhase,
            object: &v27->SPObject,
            origin: &v27->currentState.position,
            axis: &v27->currentState.orientation,
            bounds: nullptr);
          v56 = idMat3::operator*(this: v106, result: &v27->currentState.orientation, a: &v103);
          idEffectPhysicsRigidBody::SetOrientation(this: v27, m: v56);
          v27->active = true;
          v27->SPObject.motion.ignore = false;
          idList<idAnimWebBlendTree *,5>::Append(this: &v102, obj: (const encounterGroupRole_t *)&v96);
        }
        v57 = this->rigidBodies.num;
        HIDWORD(v96) = ++v24;
        v25 = v24;
      }
      while ( v24 < v57 );
    }
    v58 = v102.num;
    list = v102.list;
    if ( v102.num > 0 )
    {
      v96 = __PAIR64__(byte_821B0000, v102.num);
      v60 = (float)(v95.x * (float)9.0);
      v61 = (float)(v95.y * (float)9.0);
      v62 = (float)(v95.z * (float)9.0);
      v63 = (float)((float)((float)(scale * (float)v21) * (float)0.1) / (float)__SPAIR64__(byte_821B0000, v102.num));
      v64 = v102.list - 1;
      do
      {
        ++v64;
        valueFloat = g_breakableSpin.valueFloat;
        v66 = this->rigidBodies.list[*v64];
        v67 = 1103515245 * this->random.seed + 12345;
        this->random.seed = v67;
        DWORD2(v68) = v67 >> 16;
        HIDWORD(v96) = &v66->currentState;
        LODWORD(v68) = (v67 >> 16) & 0x7FFF;
        DWORD1(v68) = 1103515245 * v67 + 12345;
        *(_QWORD *)&v97.b[0].x = v68;
        v69 = g_breakableSpin.valueFloat;
        this->random.seed = DWORD1(v68);
        v70 = g_breakableSpin.valueFloat;
        v71 = 1103515245 * DWORD1(v68) + 12345;
        DWORD2(v68) = (SDWORD1(v68) >> 16) & 0x7FFF;
        this->random.seed = v71;
        x = v66->currentState.position.x;
        v73 = impactPoint->x;
        z = v66->currentState.position.z;
        *(_QWORD *)&v95.x = *(_QWORD *)((char *)&v68 + 4);
        v75 = (v71 >> 16) & 0x7FFF;
        v76 = physics->__vftable;
        v77 = (float)(v66->currentState.position.y - impactPoint->y);
        v78 = (float)((float)x - (float)v73);
        v79 = (float)((float)z - impactPoint->z);
        _FP5 = (float)((float)((float)((float)((float)z - impactPoint->z) * (float)((float)z - impactPoint->z))
                             + (float)((float)((float)((float)x - (float)v73) * (float)((float)x - (float)v73))
                                     + (float)((float)v77 * (float)v77)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f2, f5, f6, f0 }
        v82 = (float)((float)((float)((float)((float)z - impactPoint->z) * (float)((float)z - impactPoint->z))
                            + (float)((float)((float)((float)x - (float)v73) * (float)((float)x - (float)v73))
                                    + (float)((float)v77 * (float)v77)))
                    * (float)0.5);
        v83 = __frsqrte(_FP2);
        v84 = (float)((float)((float)((float)*(__int64 *)&v97.b[0].x * (float)0.000061037019) - (float)1.0)
                    * (float)valueFloat);
        v85 = (float)((float)((float)((float)*(__int64 *)((char *)&v68 + 4) * (float)0.000061037019) - (float)1.0)
                    * (float)v69);
        v86 = (float)((float)((float)((float)*(__int64 *)((char *)&v68 - 4) * (float)0.000061037019) - (float)1.0)
                    * (float)v70);
        v87 = (float)((float)-(float)((float)((float)((float)v83
                                                    * (float)((float)((float)((float)((float)z - impactPoint->z)
                                                                            * (float)((float)z - impactPoint->z))
                                                                    + (float)((float)((float)((float)x - (float)v73)
                                                                                    * (float)((float)x - (float)v73))
                                                                            + (float)((float)v77 * (float)v77)))
                                                            * (float)0.5))
                                            * (float)v83)
                                    - (float)1.5)
                    * (float)v83);
        v88 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v83
                                                                                    * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)((float)x - (float)v73) * (float)((float)x - (float)v73)) + (float)((float)v77 * (float)v77)))
                                                                                            * (float)0.5))
                                                                            * (float)v83)
                                                                    - (float)1.5)
                                                    * (float)v83)
                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                            + (float)((float)((float)((float)x - (float)v73)
                                                                            * (float)((float)x - (float)v73))
                                                                    + (float)((float)v77 * (float)v77)))
                                                    * (float)0.5))
                                    * (float)((float)-(float)((float)((float)((float)v83
                                                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                                                            + (float)((float)((float)((float)x - (float)v73) * (float)((float)x - (float)v73)) + (float)((float)v77 * (float)v77)))
                                                                                    * (float)0.5))
                                                                    * (float)v83)
                                                            - (float)1.5)
                                            * (float)v83))
                            - (float)1.5);
        v89 = (float)((float)v78
                    * (float)((float)-(float)((float)((float)((float)((float)v88 * (float)v87) * (float)v82)
                                                    * (float)((float)v88 * (float)v87))
                                            - (float)1.5)
                            * (float)((float)v88 * (float)v87)));
        v90 = (float)((float)(v66->currentState.position.y - impactPoint->y)
                    * (float)((float)-(float)((float)((float)((float)((float)v88 * (float)v87) * (float)v82)
                                                    * (float)((float)v88 * (float)v87))
                                            - (float)1.5)
                            * (float)((float)v88 * (float)v87)));
        v91 = (float)((float)((float)z - impactPoint->z)
                    * (float)((float)-(float)((float)((float)((float)((float)v88 * (float)v87) * (float)v82)
                                                    * (float)((float)v88 * (float)v87))
                                            - (float)1.5)
                            * (float)((float)v88 * (float)v87)));
        v104 = *(_QWORD *)((char *)&v68 - 4);
        v92 = ((double (__fastcall *)(const idPhysics *, int))v76->GetMass)(a1: physics, a2: v23);
        y = impactPoint->y;
        v94 = impactPoint->x;
        v101.z = (float)v84 + impactPoint->z;
        v101.y = (float)v85 + (float)y;
        v101.x = (float)v94 + (float)v86;
        v97.b[1].y = (float)((float)((float)v89 + (float)v60) * (float)v63) * (float)((float)1.0 / (float)v92);
        v98 = (float)((float)((float)v91 + (float)v62) * (float)v63) * (float)((float)1.0 / (float)v92);
        v97.b[1].z = (float)((float)((float)v90 + (float)v61) * (float)v63) * (float)((float)1.0 / (float)v92);
        idEffectPhysicsRigidBody::ApplyImpulse(this: v66, point: &v101, impulse: (const idVec3 *)&v97.b[1].y);
        ++v23;
      }
      while ( v23 < v58 );
    }
    if ( (v102.listStatic == 0 || v102.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$253803
// EA  : 0x826FC4FC
// RVA : 0x006FC4FC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_253803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 544 + 192));
}


// ========================================================================
// ?GetPropertiesForTraceModel@idEffectPhysicsBreakable@@AAAPAVidEffectPhysicsProperties@@ABVidTraceModel@@@Z
// EA  : 0x826FC770
// RVA : 0x006FC770
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

idEffectPhysicsProperties *__fastcall idEffectPhysicsBreakable::GetPropertiesForTraceModel(
        idEffectPhysicsBreakable *this,
        const idTraceModel *trm)
{
  int v3; // r3
  int v4; // r28
  encounterGroupRole_t v5; // r10
  idEffectPhysicsProperties **list; // r8
  int v7; // r11
  idEffectPhysicsProperties *v8; // r3
  idEffectPhysicsProperties *v9; // r30
  const idDeclBreakable *decl; // r10
  const idDeclBreakable *v12; // r11
  encounterGroupRole_t v13[12]; // [sp+50h] [-30h] BYREF

  v3 = idTraceModelCache::AllocTraceModel(
         this: this->broadPhase.traceModelCache,
         trm,
         material: this->model->surfaces.list->material);
  v4 = v3;
  v5 = ROLE_NONE;
  v13[0] = (encounterGroupRole_t)this->properties.num;
  if ( v13[0] <= ROLE_NONE )
  {
LABEL_5:
    v8 = (idEffectPhysicsProperties *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0xA0u,
                                        tag: TAG_FXPHYSICS,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    v13[0] = (encounterGroupRole_t)v8;
    if ( v8 != nullptr )
      v9 = idEffectPhysicsProperties::idEffectPhysicsProperties(this: v8);
    else
      v9 = nullptr;
    v13[0] = (encounterGroupRole_t)v9;
    idEffectPhysicsProperties::Setup(this: v9, broadPhase: &this->broadPhase, traceModelIndex: v4, mass: 10.0);
    decl = this->decl;
    if ( decl != nullptr )
    {
      v13[1] = (encounterGroupRole_t)&v9->gravityVector;
      v9->linearFriction = decl->settings.linearFriction;
      v9->angularFriction = this->decl->settings.angularFriction;
      v9->contactFriction = this->decl->settings.contactFriction;
      v9->linearFrictionWater = this->decl->settings.linearFrictionWater;
      v9->angularFrictionWater = this->decl->settings.angularFrictionWater;
      v9->bouncyness = this->decl->settings.bouncyness;
      v12 = this->decl;
      v9->gravityVector.x = v12->settings.gravityVector.x;
      v9->gravityVector.y = v12->settings.gravityVector.y;
      v9->gravityVector.z = v12->settings.gravityVector.z;
      v9->worldCollisionOnly = this->decl->settings.worldCollisionOnly;
      v9->clipMask = this->decl->settings.clipMask;
    }
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v13);
    return v9;
  }
  else
  {
    list = this->properties.list;
    v7 = 0;
    while ( list[v7]->traceModelIndex != v3 )
    {
      ++v5;
      ++v7;
      if ( v5 >= v13[0] )
        goto LABEL_5;
    }
    return list[v5];
  }
}


// ========================================================================
// __unwind$254833
// EA  : 0x826FC8EC
// RVA : 0x006FC8EC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_254833()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// ?ActivateFloatingPieces@idEffectPhysicsBreakable@@QAA_NABVidVec3@@ABVidMat3@@M@Z
// EA  : 0x826FCB28
// RVA : 0x006FCB28
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idEffectPhysicsBreakable::ActivateFloatingPieces(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        double floor)
{
  const idMat3 *v6; // r25
  int num; // r16
  unsigned int v10; // r5
  idMem *v11; // r26
  int *v12; // r15
  unsigned int v13; // r5
  char *v14; // r18
  int v15; // r2 OVERLAPPED
  int v16; // r30
  int v17; // r28
  breakableIsland_t *v18; // r3
  __int64 v19; // r6
  int v20; // r29
  int *v21; // r4
  _WORD *v22; // r10
  __int64 v23; // r8 OVERLAPPED
  int v24; // ctr
  _WORD *v25; // r11
  double z; // fp0
  double x; // fp12
  __int64 v28; // r11
  int v29; // r9
  double y; // fp13
  double lowestPoint; // fp11
  double v32; // fp8
  double v33; // fp9
  double v34; // fp7
  double v35; // fp4
  double v36; // fp6
  double v37; // fp5
  int v38; // r7
  __int64 v39; // r9 OVERLAPPED
  int v40; // r11
  __int64 v41; // r11
  int i; // ctr
  double v43; // fp12
  double v44; // fp2
  __int64 v45; // r11
  __int64 v46; // fp11
  __int64 v47; // fp28
  double v48; // fp1
  double v49; // fp29
  double v50; // fp12
  char v51; // r11
  int v52; // r28
  int j; // r19
  idEffectPhysicsRigidBody *v54; // r8
  unsigned int v55; // r11
  idColor *v56; // r11
  float a; // r5
  float b; // r6
  float g; // r7
  _WORD *v60; // r11
  _WORD *v61; // r10
  int k; // ctr
  __int64 v63; // r9
  __int64 v64; // r11
  int v65; // r3
  __int64 v66; // r7
  idRenderWorld *v67; // r3
  int *list; // r27
  int v69; // r28
  int v70; // r30
  int v71; // r29
  int v72; // r11
  _WORD v73[9]; // [sp+4Eh] [-192h] BYREF
  float v74[3]; // [sp+60h] [-180h] BYREF
  float v75; // [sp+6Ch] [-174h] BYREF
  __int16 v76; // [sp+70h] [-170h]
  __int16 v77; // [sp+72h] [-16Eh]
  __int16 v78; // [sp+74h] [-16Ch]
  unsigned __int16 v79; // [sp+76h] [-16Ah]
  __int16 v80; // [sp+78h] [-168h]
  __int16 v81; // [sp+7Ah] [-166h]
  __int64 v82; // [sp+80h] [-160h]
  __int64 v83; // [sp+88h] [-158h]
  __int64 v84; // [sp+90h] [-150h]
  idMem *v85; // [sp+98h] [-148h]
  __int64 v86; // [sp+A0h] [-140h]
  __int64 v87; // [sp+A8h] [-138h]
  __int64 v88; // [sp+B0h] [-130h]
  idBounds v89; // [sp+C0h] [-120h] BYREF
  idList<int,59> v90; // [sp+E0h] [-100h] BYREF
  __int64 v91; // [sp+F0h] [-F0h]
  __int64 v92; // [sp+F8h] [-E8h]
  __int64 v93; // [sp+100h] [-E0h]
  __int64 v94; // [sp+108h] [-D8h]
  __int64 v95; // [sp+110h] [-D0h]
  __int64 v96; // [sp+118h] [-C8h]

  v6 = axis;
  if ( this->basePiece != nullptr )
    return 0;
  num = this->rigidBodies.num;
  if ( num == 0 )
    return 0;
  idList<breakableIsland_t,59>::idList<breakableIsland_t,59>(this: &v90);
  v10 = 4 * num;
  if ( (unsigned int)num > 0x3FFFFFFF )
    v10 = -1;
  v11 = &mem;
  v85 = &mem;
  v12 = (int *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                 size: v10,
                 tag: TAG_FXPHYSICS,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v13 = 4 * num;
  if ( (unsigned int)num > 0x3FFFFFFF )
    v13 = -1;
  v14 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                  size: v13,
                  tag: TAG_FXPHYSICS,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  memset(Dst: v14, Val: -1, Size: 4 * num);
  v16 = 0;
  v17 = 0;
  do
  {
    if ( !this->rigidBodies.list[v17]->active && *(_DWORD *)&v14[v17 * 4] == -1 )
    {
      v18 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&v90);
      HIDWORD(v19) = 1;
      v20 = 0;
      v18->index = v90.num - 1;
      v18->lowestPoint = 1900671690;
      *v12 = v16;
      v21 = v12;
      *(_DWORD *)&v14[v17 * 4] = v18->index;
      do
      {
        v22 = (_WORD *)&v75 + 1;
        HIDWORD(v23) = 4 * *v21;
        v24 = 6;
        v25 = (_WORD *)&(*(idEffectPhysicsRigidBody **)((char *)this->rigidBodies.list + HIDWORD(v23)))->SPObject.axis.mat[2].z
            + 1;
        do
        {
          *++v22 = *++v25;
          --v24;
        }
        while ( v24 != 0 );
        z = origin->z;
        x = origin->x;
        LODWORD(v19) = v80;
        HIDWORD(v28) = v79;
        LODWORD(v23) = v76;
        v95 = v19;
        v29 = v81;
        LODWORD(v19) = (__int16)v79;
        v93 = v23;
        v96 = *(__int64 *)((char *)&v23 - 4);
        v94 = v19;
        y = origin->y;
        LODWORD(v28) = v77;
        lowestPoint = v18->lowestPoint;
        v92 = v28;
        LODWORD(v28) = v78;
        v91 = v28;
        v32 = (float)((float)z + (float)v28);
        v33 = (float)((float)x + (float)v23);
        v34 = (float)((float)z + (float)*(__int64 *)((char *)&v23 - 4));
        v35 = (float)((float)x + (float)v19);
        v36 = (float)((float)y + (float)v95);
        v37 = (float)((float)y + (float)v92);
        if ( v32 < lowestPoint )
          v18->lowestPoint = (float)z + (float)v91;
        v38 = 0;
        if ( num > 0 )
        {
          HIDWORD(v39) = 0;
          LODWORD(v19) = &v12[HIDWORD(v19) - 1];
          do
          {
            if ( v16 != v38 && *(_DWORD *)&v14[HIDWORD(v39)] == -1 )
            {
              v40 = *(int *)((char *)this->rigidBodies.list + HIDWORD(v39));
              if ( *(_BYTE *)(v40 + 264) == 0 )
              {
                HIDWORD(v41) = v73;
                LODWORD(v41) = v40 + 166;
                for ( i = 6; i != 0; --i )
                {
                  LODWORD(v41) = v41 + 2;
                  HIDWORD(v41) += 2;
                  *(_WORD *)HIDWORD(v41) = *(_WORD *)v41;
                }
                v43 = origin->x;
                LODWORD(v41) = v73[5];
                v44 = origin->z;
                v87 = v41;
                LODWORD(v45) = v73[6];
                LODWORD(v39) = v73[1];
                HIDWORD(v45) = v73[3];
                v86 = v45;
                v83 = v39;
                v46 = v45;
                LODWORD(v45) = v73[2];
                v88 = v45;
                v47 = v45;
                HIDWORD(v45) = v73[3];
                v48 = origin->y;
                v82 = *(__int64 *)((char *)&v39 - 4);
                HIDWORD(v45) = v73[4];
                v84 = *(__int64 *)((char *)&v39 - 4);
                v49 = (float)((float)v43 + (float)*(__int64 *)((char *)&v39 - 4));
                v50 = (float)((float)v43 + (float)v39);
                if ( v49 < (float)((float)v33 - (float)0.050000001)
                  || (float)((float)v48 + (float)v87) < (double)(float)((float)v37 - (float)0.050000001)
                  || (float)((float)v44 + (float)v46) < (double)(float)((float)v32 - (float)0.050000001)
                  || v50 > (float)((float)v35 + (float)0.050000001)
                  || (float)((float)v48 + (float)v47) > (double)(float)((float)v36 + (float)0.050000001)
                  || (v51 = 1, (float)((float)v44 + (float)v82) > (double)(float)((float)v34 + (float)0.050000001)) )
                {
                  v51 = 0;
                }
                if ( v51 != 0 )
                {
                  ++HIDWORD(v19);
                  *(_DWORD *)&v14[HIDWORD(v39)] = v18->index;
                  LODWORD(v19) = v19 + 4;
                  *(_DWORD *)v19 = v38;
                }
              }
            }
            ++v38;
            HIDWORD(v39) += 4;
          }
          while ( v38 < num );
        }
        ++v20;
        ++v21;
      }
      while ( v20 < SHIDWORD(v19) );
    }
    ++v16;
    ++v17;
  }
  while ( v16 < num );
  if ( g_breakableDebugIslands.valueInteger != 0 && v90.num > 0 && num > 0 )
  {
    v52 = 0;
    for ( j = num; j != 0; --j )
    {
      v54 = this->rigidBodies.list[v52];
      if ( *(_DWORD *)&v14[v52 * 4] != -1 )
      {
        v75 = -1.0;
        v74[2] = -1.0;
        v74[1] = -1.0;
        v74[0] = -1.0;
        v55 = *(_DWORD *)&v14[v52 * 4];
        if ( v55 > 6 )
        {
          v56 = &idColor::colorCyan;
        }
        else
        {
          switch ( v55 )
          {
            case 1u:
              v56 = &idColor::colorRed;
              break;
            case 2u:
              v56 = &idColor::colorGreen;
              break;
            case 3u:
              v56 = &idColor::colorWhite;
              break;
            case 4u:
              v56 = &idColor::colorBlue;
              break;
            case 5u:
              v56 = &idColor::colorOrange;
              break;
            default:
              if ( v55 != 0 )
                v56 = &idColor::colorPurple;
              else
                v56 = &idColor::colorBrown;
              break;
          }
        }
        a = v56->a;
        b = v56->b;
        g = v56->g;
        v74[0] = v56->r;
        v60 = (_WORD *)&v54->SPObject.axis.mat[2].z + 1;
        v75 = a;
        v74[2] = b;
        v74[1] = g;
        v61 = v73;
        for ( k = 6; k != 0; --k )
          *++v61 = *++v60;
        LODWORD(v63) = v73[1];
        HIDWORD(v64) = v73[6];
        LODWORD(v64) = v73[4];
        HIDWORD(v63) = v73[5];
        v88 = v63;
        LODWORD(v63) = v73[5];
        v84 = v64;
        v65 = v73[3];
        LODWORD(v64) = v73[6];
        v86 = v63;
        v87 = *(_QWORD *)(&v15 - 1);
        v82 = v64;
        HIDWORD(v66) = axis;
        LODWORD(v66) = v73[2];
        v83 = v66;
        v89.b[0].y = (float)v66;
        v89.b[1].y = (float)v63;
        v89.b[0].x = (float)v88;
        v89.b[1].x = (float)v84;
        v89.b[1].z = (float)v64;
        v89.b[0].z = (float)*(__int64 *)(&v15 - 1);
        idBounds::FromTransformedBounds(this: &v89, bounds: &v89, origin, axis);
        v67 = common->RW(this: common);
        v67->DebugBounds(this: v67, a2: (const idVec4 *)v74, a3: &v89, a4: &vec3_origin, a5: 0, a6: false);
      }
      ++v52;
    }
    v11 = v85;
    v6 = axis;
  }
  list = v90.list;
  v69 = 0;
  v70 = 0;
  if ( num > 0 )
  {
    v71 = 0;
    do
    {
      v72 = *(_DWORD *)&v14[v71 * 4];
      if ( v72 != -1
        && !this->rigidBodies.list[v71]->active
        && *(float *)&list[2 * v72 + 1] > (double)(float)((float)floor + (float)1.0) )
      {
        idEffectPhysicsBreakable::ActivateNoisy(this, num: v70, origin, axis: v6);
        v69 = 1;
      }
      ++v70;
      ++v71;
    }
    while ( v70 < num );
  }
  idMem::Free(this: v11, ptr: v14, align: ALIGN_16);
  idMem::Free(this: v11, ptr: v12, align: ALIGN_16);
  if ( (v90.listStatic == 0 || v90.listStatic == 2) && list != nullptr )
    idMem::Free(this: v11, ptr: list, align: ALIGN_16);
  return v69;
}


// ========================================================================
// __unwind$255942
// EA  : 0x826FD248
// RVA : 0x006FD248
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_255942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 480 + 224));
}


// ========================================================================
// ?EmitSmokeForEachPiece@idEffectPhysicsBreakable@@QAAXPBVidDeclParticle@@H@Z
// EA  : 0x826FD270
// RVA : 0x006FD270
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::EmitSmokeForEachPiece(
        idEffectPhysicsBreakable *this,
        const idDeclParticle *p,
        int time)
{
  int v6; // r29
  int v7; // r30
  idEffectPhysicsRigidBody *v8; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idEffectPhysicsBreakable::idBreakableParticle v12; // [sp+50h] [-50h] BYREF

  v6 = 0;
  if ( this->rigidBodies.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this->rigidBodies.list[v7];
      if ( v8->active && p != nullptr )
      {
        x = v8->currentState.position.x;
        v12.particle = p;
        y = v8->currentState.position.y;
        v12.startTime = time;
        z = v8->currentState.position.z;
        v12.pos.x = x;
        v12.pos.y = y;
        v12.pos.z = z;
        idList<idEffectPhysicsBreakable::idBreakableParticle,59>::Append(this: &this->particles, obj: &v12);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->rigidBodies.num );
  }
}


// ========================================================================
// ?StartExplosions@idEffectPhysicsBreakable@@QAAXABVidVec3@@ABVidMat3@@H@Z
// EA  : 0x826FD300
// RVA : 0x006FD300
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::StartExplosions(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        int currentTime)
{
  int v8; // r26
  int v9; // r28
  idEffectPhysicsBreakable::idExplosion *v10; // r11
  BOOL localSpace; // r10
  double y; // fp9
  double z; // fp5
  double v14; // fp2
  double v15; // fp1
  int fxIndex; // r10
  int num; // r11
  idVec3 *p_worldPosition; // r11
  double x; // fp0
  double v20; // fp13
  double v21; // fp12
  idEffectPhysicsBreakable::idBreakableParticle v22; // [sp+50h] [-60h] BYREF

  if ( this->decl != nullptr )
  {
    v8 = 0;
    if ( this->explosions.num <= 0 )
      goto LABEL_13;
    v9 = 0;
    do
    {
      v10 = &this->explosions.list[v9];
      localSpace = v10->localSpace;
      v10->startTime = currentTime;
      if ( localSpace )
      {
        y = origin->y;
        z = origin->z;
        v14 = (float)((float)(axis->mat[2].y * v10->decl.position.z)
                    + (float)((float)(axis->mat[0].y * v10->decl.position.x)
                            + (float)(axis->mat[1].y * v10->decl.position.y)));
        v15 = (float)((float)(axis->mat[2].z * v10->decl.position.z)
                    + (float)((float)(axis->mat[0].z * v10->decl.position.x)
                            + (float)(axis->mat[1].z * v10->decl.position.y)));
        v10->worldPosition.x = origin->x
                             + (float)((float)(axis->mat[0].x * v10->decl.position.x)
                                     + (float)((float)(axis->mat[1].x * v10->decl.position.y)
                                             + (float)(axis->mat[2].x * v10->decl.position.z)));
        v10->worldPosition.y = (float)y + (float)v14;
        v10->worldPosition.z = (float)z + (float)v15;
      }
      fxIndex = v10->fxIndex;
      if ( fxIndex >= 0 && fxIndex < this->explosionFX.num )
        idFXManager::StartFX(
          this: &this->explosionFX.list[fxIndex],
          org: &v10->worldPosition,
          axis: &mat3_identity,
          time: currentTime,
          startCondition: FX_NONE);
      num = this->explosions.num;
      ++v8;
      ++v9;
    }
    while ( v8 < num );
    if ( num <= 0 )
LABEL_13:
      p_worldPosition = &vec3_origin;
    else
      p_worldPosition = &this->explosions.list->worldPosition;
    if ( this->decl->settings.deathParticle != nullptr )
    {
      x = p_worldPosition->x;
      v22.particle = this->decl->settings.deathParticle;
      v20 = p_worldPosition->y;
      v22.startTime = currentTime;
      v21 = p_worldPosition->z;
      v22.pos.x = x;
      v22.pos.y = v20;
      v22.pos.z = v21;
      idList<idEffectPhysicsBreakable::idBreakableParticle,59>::Append(this: &this->particles, obj: &v22);
    }
  }
  else
  {
    idLib::Warning(fmt: "idEffectPhysicsBreakable::StartExplosions() called with NULL decl");
  }
}


// ========================================================================
// ?UpdateSimulation@idEffectPhysicsBreakable@@QAAXABVidVec3@@ABVidMat3@@HHHMM@Z
// EA  : 0x826FD4A8
// RVA : 0x006FD4A8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsBreakable::UpdateSimulation(
        idEffectPhysicsBreakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        int currentTime,
        const char *gameMsPerFrame,
        int frameNum,
        double msPerFrame,
        double dampening)
{
  unsigned __int64 v13; // r6
  int v14; // r21
  int v16; // r2 OVERLAPPED
  int num; // r6
  __int64 v19; // r11
  float x; // r4
  float *v21; // r23
  const unsigned int *v22; // r28
  int v23; // r16
  int v24; // r17
  idFXManager *v25; // r30
  idEffectPhysicsBreakable::idExplosion *v26; // r27
  int fxIndex; // r11
  int v28; // r20
  double z; // fp9
  double y; // fp5
  double v31; // fp2
  double v32; // fp1
  int seed; // r11
  double v34; // fp0
  const idVec3 *v35; // r9
  int v36; // r11
  idGameLibEffects *gameLibEffects; // r3
  const idDeclParticle *particle; // r4
  __int64 v39; // r7
  int v40; // r22
  int v41; // r21
  idEffectPhysicsRigidBody *v42; // r28
  float *p_x; // r11
  float *v44; // r30
  float v45; // r9
  float v46; // r8
  double v47; // fp12
  float v48; // r5
  int activateAllDelay; // r11
  double v51; // fp13
  double v53; // fp11
  double v54; // fp0
  double v55; // fp13
  double v56; // fp30
  double v57; // fp28
  double v58; // fp29
  double v59; // fp26
  int v60; // r23
  double v61; // fp11
  double v62; // fp9
  double v63; // fp2
  double v64; // fp1
  const idMat3 *v65; // r3
  double v66; // fp12
  double v67; // fp11
  __int64 *v68; // r11
  double v69; // fp10
  double v70; // fp9
  double v71; // fp8
  float v72; // r9
  float v73; // r8
  float v74; // r7
  int v75; // r11
  __int64 v76; // r10
  __int64 v77; // r7
  int v78; // r7
  int v79; // r11
  double angular; // fp7
  double v81; // fp3
  double v82; // fp8
  __int16 *v83; // r10
  _WORD *v84; // r11
  int i; // ctr
  bool v86; // r3
  double radius; // fp0
  double v88; // fp10
  double v89; // fp4
  double v90; // fp2
  const idMat3 *v91; // r3
  double v92; // fp13
  double v93; // fp12
  double v94; // fp12
  double v95; // fp10
  double v96; // fp9
  double v97; // fp8
  int v98; // r9
  __int128 v99; // r9
  int v100; // r11
  int v101; // r3
  double v102; // fp4
  double v103; // fp3
  double v104; // fp10
  int v105; // r27
  int v106; // r28
  int v107; // r30
  double v108; // fp30
  int v109; // r10
  int v110; // r14
  idEffectPhysicsBreakable::idTrail *v111; // r30
  double v112; // fp29
  double v113; // fp28
  idList<int,59> *p_pieces; // r17
  int v115; // r20
  int v116; // r23
  idEffectPhysicsRigidBody *v117; // r28
  int *list; // r11
  int v119; // r10
  int v120; // r11
  const unsigned int *v121; // r10
  const idVec3 *v122; // r9
  double v123; // fp0
  int v124; // r11
  __int64 v125; // r4
  float *v126; // r11
  int *v127; // r8
  int delay; // r11
  int v129; // r10
  float *v130; // r11
  double v131; // fp10
  double v132; // fp9
  double v133; // fp8
  __int64 v134; // r11
  double v135; // fp11
  double v136; // fp3
  double v137; // fp8
  double v138; // fp9
  double v139; // fp7
  double v140; // fp5
  double v141; // fp4
  double v142; // fp12
  double v143; // fp6
  __int64 v144; // r5 OVERLAPPED
  int v145; // r3 OVERLAPPED
  __int128 v146; // r8
  int fadeOutDuration; // r9
  double v148; // fp0
  double v149; // fp13
  double v150; // fp10
  idEffectPhysicsCollision *v157; // r27
  int v158; // r4
  const unsigned int *v159; // r10
  double v160; // fp0
  int v161; // r11
  __int64 v162; // r3
  const idDeclImpactSound *impactTable; // r26
  const idSoundShader *ImpactSoundForMaterial; // r4
  double trailVelocityScale; // fp13
  double v166; // fp8
  double v167; // fp5
  double v168; // fp7
  float *v169; // r11
  double v170; // fp12
  double v171; // fp9
  double v172; // fp4
  double v175; // fp11
  double v176; // fp1
  double v177; // fp11
  double v178; // fp30
  __int64 v179; // r10
  const idVec3 *v180; // r7
  __int64 v181; // r6
  int v182; // r28
  int v183; // r27
  float *v184; // r26
  __int64 v185; // r11
  double trailSpacing; // fp13
  double v187; // fp5
  double v188; // fp12
  double v189; // fp11
  double v190; // fp10
  double v191; // fp0
  double v192; // fp9
  double v193; // fp8
  double v194; // fp13
  double v195; // fp7
  double v196; // fp0
  idVec3 *v197; // r11
  float *v198; // r11
  double v199; // fp9
  double v200; // fp8
  double v201; // fp2
  double v202; // fp1
  int v203; // r8
  int v204; // r14
  int v205; // r16
  int v206; // r19
  idEffectPhysicsBreakable::idDecalFX *v207; // r30
  double v208; // fp24
  int v209; // r27
  int v210; // r22
  idEffectPhysicsRigidBody *v211; // r11
  int *v212; // r10
  float *v213; // r10
  float *v214; // r28
  float *v215; // r11
  double v216; // fp13
  double v217; // fp12
  double v218; // fp10
  double v219; // fp5
  bool v220; // r8
  idEffectPhysicsCollision *v221; // r11
  int v222; // r10
  float v223; // r4
  float v224; // r3
  bool v225; // cr58
  int v226; // r9
  idEffectPhysicsCollision *v227; // r11
  float v228; // r26
  __int64 v229; // r24
  double v230; // fp29
  double v231; // fp30
  double v232; // fp28
  float *v233; // r11
  float *v234; // r11
  signed int v235; // r11
  int v236; // r11
  int v237; // r10
  int v238; // r10
  int v239; // r8
  unsigned int v240; // r4
  const idMaterial **v241; // r10
  int v242; // r9
  int v243; // r11
  float *v244; // r4
  double v245; // fp0
  int v246; // r3
  double v247; // fp2
  double v248; // fp1
  double v249; // fp13
  idGameLibEffects *v251; // r4
  double v253; // fp13
  double v254; // fp4
  double v255; // fp5
  double v256; // fp4
  float *v257; // r11
  idRenderWorld *v258; // r3
  float *v259; // r11
  float *v260; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v262; // r30
  int v263; // r3
  __int64 totalTicks; // r11
  __int64 v265; // r9
  int v266; // [sp+60h] [-350h]
  __int64 v267; // [sp+68h] [-348h] BYREF
  float v268; // [sp+70h] [-340h]
  float *v269; // [sp+74h] [-33Ch]
  __int64 v270; // [sp+78h] [-338h] BYREF
  idVec3 *v271; // [sp+80h] [-330h]
  int v272; // [sp+84h] [-32Ch]
  float v273; // [sp+88h] [-328h] BYREF
  float v274; // [sp+8Ch] [-324h]
  float v275; // [sp+90h] [-320h]
  float *v276; // [sp+94h] [-31Ch]
  const idMat3 *v277; // [sp+98h] [-318h]
  float v278; // [sp+A0h] [-310h] BYREF
  float v279; // [sp+A4h] [-30Ch]
  float v280; // [sp+A8h] [-308h]
  idMat3 v281; // [sp+B0h] [-300h] BYREF
  float v282; // [sp+D4h] [-2DCh]
  float v283; // [sp+D8h] [-2D8h]
  float v284; // [sp+E0h] [-2D0h]
  int v285; // [sp+E4h] [-2CCh]
  __int64 v286; // [sp+E8h] [-2C8h]
  beamNodeParms_t v287; // [sp+F0h] [-2C0h] BYREF
  idVec3 v288; // [sp+158h] [-258h] BYREF
  __int64 v289; // [sp+168h] [-248h]
  unsigned __int64 v290; // [sp+170h] [-240h]
  __int64 v291; // [sp+178h] [-238h]
  __int64 v292; // [sp+180h] [-230h]
  __int64 v293; // [sp+188h] [-228h]
  idPLogScope v294[2]; // [sp+190h] [-220h] BYREF
  float v295[10]; // [sp+1A0h] [-210h] BYREF
  idVec3 v296; // [sp+1C8h] [-1E8h] BYREF
  float v297[3]; // [sp+1D8h] [-1D8h] BYREF
  __int16 v298; // [sp+1E6h] [-1CAh] BYREF
  idBounds v299; // [sp+1E8h] [-1C8h] BYREF
  float v300; // [sp+200h] [-1B0h]
  idMat3 v301; // [sp+208h] [-1A8h] BYREF
  float v302; // [sp+22Ch] [-184h]
  float v303[4]; // [sp+238h] [-178h] BYREF
  idVec3 v304; // [sp+248h] [-168h] BYREF
  idSphere v305; // [sp+260h] [-150h] BYREF
  _QWORD v306[4]; // [sp+270h] [-140h] BYREF
  idMat3 v307[3]; // [sp+290h] [-120h] BYREF

  LODWORD(v13) = "idEffectPhysicsBreakable::UpdateSimulation";
  HIDWORD(v13) = 1;
  v14 = (int)gameMsPerFrame;
  idPLogScope::idPLogScope(this: v294, pl: &::pLog, gMask: v13, label: gameMsPerFrame);
  if ( this->gameLibEffects == nullptr )
  {
    idPLogScope::~idPLogScope(this: v294);
    return;
  }
  num = this->explosions.num;
  HIDWORD(v19) = "_AI_OBSTACLE";
  x = COERCE_FLOAT(&idMath::FLT_SMALLEST_NON_DENORMAL);
  v21 = (float *)&MAX_RAND_FINV_8;
  v276 = (float *)&idMath::FLT_SMALLEST_NON_DENORMAL;
  v22 = (const unsigned int *)&vec3_origin;
  v269 = (float *)&MAX_RAND_FINV_8;
  v277 = &mat3_identity;
  v271 = &vec3_origin;
  v23 = 0;
  if ( num > 0 )
  {
    v24 = 0;
    do
    {
      v25 = nullptr;
      v26 = &this->explosions.list[v24];
      fxIndex = v26->fxIndex;
      if ( fxIndex >= 0 && fxIndex < this->explosionFX.num )
        v25 = &this->explosionFX.list[fxIndex];
      HIDWORD(v19) = v26->startTime;
      if ( HIDWORD(v19) != 0 )
      {
        v28 = v26->decl.delay + HIDWORD(v19);
        if ( currentTime >= v28 )
        {
          if ( v26->decl.duration + v28 >= currentTime )
          {
            if ( !v26->effectsEnabled )
            {
              if ( v26->localSpace )
              {
                z = origin->z;
                y = origin->y;
                v31 = (float)((float)(axis->mat[2].z * v26->decl.position.z)
                            + (float)((float)(axis->mat[0].z * v26->decl.position.x)
                                    + (float)(axis->mat[1].z * v26->decl.position.y)));
                v32 = (float)((float)(axis->mat[2].y * v26->decl.position.z)
                            + (float)((float)(axis->mat[0].y * v26->decl.position.x)
                                    + (float)(axis->mat[1].y * v26->decl.position.y)));
                v26->worldPosition.x = (float)((float)(axis->mat[0].x * v26->decl.position.x)
                                             + (float)((float)(axis->mat[1].x * v26->decl.position.y)
                                                     + (float)(axis->mat[2].x * v26->decl.position.z)))
                                     + origin->x;
                v26->worldPosition.z = (float)z + (float)v31;
                v26->worldPosition.y = (float)y + (float)v32;
              }
              v26->effectsEnabled = true;
            }
            if ( v26->decl.particle != nullptr && g_skipBreakableParticles.valueInteger == 0 )
            {
              seed = this->random.seed;
              v272 = -1;
              v34 = *v21;
              v35 = (const idVec3 *)v277;
              v36 = 1103515245 * seed + 12345;
              this->random.seed = v36;
              gameLibEffects = this->gameLibEffects;
              particle = v26->decl.particle;
              LODWORD(v39) = (v36 >> 16) & 0x7FFF;
              HIDWORD(v39) = v14;
              v270 = v39;
              idRenderModelEffects::AddParticles(
                this: gameLibEffects->effectsModel,
                particle,
                systemStartTime: v28,
                gameMsPerFrame: v14,
                diversity: (float)((float)v39 * (float)v34),
                origin: (const idVec3 *)v39,
                axis: (const idMat3 *)&v26->worldPosition,
                velocity: v35,
                color: v22);
            }
            if ( v25 != nullptr )
              idFXManager::Update(
                this: v25,
                parentOrigin: origin,
                parentAxis: axis,
                parentVel: (const idVec3 *)v22,
                time: currentTime,
                gameMsPerFrame: v14,
                frameNum,
                fovScale: 1.0,
                depthHack: 0.0);
            v40 = 0;
            if ( v26->decl.pieces.num > 0 )
            {
              v41 = 0;
              do
              {
                v42 = this->rigidBodies.list[v26->decl.pieces.list[v41]];
                if ( v40 >= this->pieceActivationTimes.num
                  || (HIDWORD(v19) = this->pieceActivationTimes.list[v41] * v40,
                      currentTime >= HIDWORD(v19) + v26->startTime) )
                {
                  if ( !v26->forceApplied || (HIDWORD(v19) = v42->active) == 0 && v26->decl.activateAllDelay != -1 )
                  {
                    p_x = &v26->worldPosition.x;
                    if ( !v42->active )
                      p_x = &v26->decl.position.x;
                    v44 = &v42->currentState.position.x;
                    v45 = p_x[2];
                    v46 = p_x[1];
                    v281.mat[2].z = *p_x;
                    v283 = v45;
                    v282 = v46;
                    x = v42->currentState.position.x;
                    v47 = *v276;
                    v281.mat[1].y = x;
                    v48 = v42->currentState.position.y;
                    v281.mat[2].x = v42->currentState.position.z;
                    v281.mat[1].z = v48;
                    activateAllDelay = v26->decl.activateAllDelay;
                    v51 = (float)((float)((float)((float)(v281.mat[2].x - v45) * (float)(v281.mat[2].x - v45))
                                        + (float)((float)((float)(v281.mat[1].y - v281.mat[2].z)
                                                        * (float)(v281.mat[1].y - v281.mat[2].z))
                                                + (float)((float)(v48 - v46) * (float)(v48 - v46))))
                                * (float)0.5);
                    _FP0 = (float)((float)((float)((float)(v281.mat[2].x - v45) * (float)(v281.mat[2].x - v45))
                                         + (float)((float)((float)(v281.mat[1].y - v281.mat[2].z)
                                                         * (float)(v281.mat[1].y - v281.mat[2].z))
                                                 + (float)((float)(v48 - v46) * (float)(v48 - v46))))
                                 - (float)v47);
                    __asm { fsel      f12, f0, f1, f12 }
                    v53 = __frsqrte(_FP12);
                    v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v51)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53)
                                                                * (float)v51)
                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v51)
                                                                                        * (float)v53)
                                                                                - (float)1.5)
                                                                * (float)v53))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v51) * (float)v53)
                                                        - (float)1.5)
                                        * (float)v53));
                    v55 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v51) * (float)v53)
                                                                                                - (float)1.5)
                                                                                * (float)v53)
                                                                        * (float)v51)
                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v51)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v51) * (float)v53)
                                                                - (float)1.5)
                                                * (float)v53))
                                * (float)v51);
                    v56 = (float)((float)(x - v281.mat[2].z)
                                * (float)((float)-(float)((float)((float)v55 * (float)v54) - (float)1.5) * (float)v54));
                    v57 = (float)((float)(v48 - v46)
                                * (float)((float)-(float)((float)((float)v55 * (float)v54) - (float)1.5) * (float)v54));
                    v58 = (float)((float)(v281.mat[2].x - v45)
                                * (float)((float)-(float)((float)((float)v55 * (float)v54) - (float)1.5) * (float)v54));
                    v59 = (float)((float)((float)((float)-(float)((float)((float)v55 * (float)v54) - (float)1.5)
                                                * (float)v54)
                                        * (float)((float)((float)(v281.mat[2].x - v45) * (float)(v281.mat[2].x - v45))
                                                + (float)((float)((float)(v281.mat[1].y - v281.mat[2].z)
                                                                * (float)(v281.mat[1].y - v281.mat[2].z))
                                                        + (float)((float)(v48 - v46) * (float)(v48 - v46)))))
                                + (float)1.0);
                    if ( activateAllDelay == -1 )
                      goto LABEL_42;
                    v285 = (int)(float)(v26->decl.distTimeScaleDelay
                                      * (float)((float)((float)((float)-(float)((float)((float)v55 * (float)v54)
                                                                              - (float)1.5)
                                                              * (float)v54)
                                                      * (float)((float)((float)(v281.mat[2].x - v45)
                                                                      * (float)(v281.mat[2].x - v45))
                                                              + (float)((float)((float)(v281.mat[1].y - v281.mat[2].z)
                                                                              * (float)(v281.mat[1].y - v281.mat[2].z))
                                                                      + (float)((float)(v48 - v46) * (float)(v48 - v46)))))
                                              + (float)1.0));
                    HIDWORD(v19) = v285;
                    v60 = v285 + activateAllDelay;
                    if ( currentTime > v285 + activateAllDelay + v28 )
                    {
                      if ( !v42->active )
                      {
                        v61 = origin->z;
                        v62 = origin->y;
                        v63 = (float)((float)(v42->currentState.position.y * axis->mat[1].z)
                                    + (float)((float)(v42->currentState.position.z * axis->mat[2].z)
                                            + (float)(axis->mat[0].z * v42->currentState.position.x)));
                        v64 = (float)((float)(axis->mat[2].y * v42->currentState.position.z)
                                    + (float)((float)(axis->mat[0].y * v42->currentState.position.x)
                                            + (float)(axis->mat[1].y * v42->currentState.position.y)));
                        v42->currentState.position.x = (float)((float)(v42->currentState.position.z * axis->mat[2].x)
                                                             + (float)((float)(axis->mat[0].x
                                                                             * v42->currentState.position.x)
                                                                     + (float)(v42->currentState.position.y
                                                                             * axis->mat[1].x)))
                                                     + origin->x;
                        v42->currentState.position.z = (float)v61 + (float)v63;
                        v42->currentState.position.y = (float)v62 + (float)v64;
                        idEffectPhysicsBroadPhase::SetObjectPosition(
                          this: v42->properties->broadPhase,
                          object: &v42->SPObject,
                          origin: &v42->currentState.position,
                          axis: &v42->currentState.orientation,
                          bounds: nullptr);
                        v65 = idMat3::operator*(this: v307, result: &v42->currentState.orientation, a: axis);
                        idEffectPhysicsRigidBody::SetOrientation(this: v42, m: v65);
                        v66 = (float)((float)(axis->mat[0].y * (float)v56) + (float)(axis->mat[2].y * (float)v58));
                        v67 = (float)((float)((float)v58 * axis->mat[2].x) + (float)((float)v57 * axis->mat[1].x));
                        v58 = (float)((float)((float)v57 * axis->mat[1].z)
                                    + (float)((float)(axis->mat[0].z * (float)v56) + (float)(axis->mat[2].z * (float)v58)));
                        v57 = (float)((float)(axis->mat[1].y * (float)v57) + (float)v66);
                        v56 = (float)((float)(axis->mat[0].x * (float)v56) + (float)v67);
                      }
                      if ( v60 != 0 )
                      {
                        v68 = (__int64 *)v271;
                      }
                      else
                      {
                        v68 = &v267;
                        v69 = (float)(v26->decl.impulse * (float)v57);
                        v70 = (float)((float)v56 * v26->decl.impulse);
                        v71 = (float)((float)1.0 / (float)(v26->decl.falloff * (float)v59));
                        v268 = (float)((float)1.0 / (float)(v26->decl.falloff * (float)v59))
                             * (float)(v26->decl.impulse * (float)v58);
                        *((float *)&v267 + 1) = (float)v71 * (float)v69;
                        *(float *)&v267 = (float)v71 * (float)v70;
                      }
                      v72 = *(float *)v68;
                      v73 = *((float *)v68 + 1);
                      v74 = *((float *)v68 + 2);
                      v75 = 1103515245 * this->random.seed;
                      v288.x = v72;
                      v288.y = v73;
                      v288.z = v74;
                      HIDWORD(v76) = v75 + 12345;
                      this->random.seed = v75 + 12345;
                      HIDWORD(v77) = (v75 + 12345) >> 16;
                      LODWORD(v76) = WORD1(v77) & 0x7FFF;
                      v78 = 1103515245 * (v75 + 12345) + 12345;
                      this->random.seed = v78;
                      v291 = v76;
                      v79 = 1103515245 * v78 + 12345;
                      LODWORD(v76) = (v78 >> 16) & 0x7FFF;
                      HIDWORD(v76) = v79 >> 16;
                      this->random.seed = v79;
                      angular = v26->decl.angular;
                      v290 = v76;
                      LODWORD(v77) = (v79 >> 16) & 0x7FFF;
                      v81 = v42->currentState.position.z;
                      v293 = v77;
                      v82 = *v44;
                      v304.y = v42->currentState.position.y
                             + (float)((float)angular * (float)((float)((float)v76 * (float)0.000061037019) - (float)1.0));
                      v304.z = (float)v81
                             + (float)((float)angular
                                     * (float)((float)((float)v291 * (float)0.000061037019) - (float)1.0));
                      v304.x = (float)((float)((float)((float)v77 * (float)0.000061037019) - (float)1.0) * (float)angular)
                             + (float)v82;
                      idEffectPhysicsRigidBody::ApplyImpulse(this: v42, point: &v304, impulse: &v288);
                      v42->active = true;
                      v42->SPObject.motion.ignore = false;
                    }
                    if ( !v26->forceApplied )
                    {
LABEL_42:
                      v83 = &v298;
                      v84 = (_WORD *)&v42->SPObject.axis.mat[2].z + 1;
                      for ( i = 6; i != 0; --i )
                        *++v83 = *++v84;
                      idBoundsShort::ToBounds(this: (idBoundsShort *)&v301.mat[2], result: &v299);
                      if ( v26->decl.useLinear )
                      {
                        v86 = idBounds::LineIntersection(
                                this: (idBounds *)&v301.mat[2],
                                start: (const idVec3 *)&v281.mat[2].z,
                                end: &v26->decl.endLinear);
                      }
                      else
                      {
                        radius = v26->decl.radius;
                        v305.origin.x = v281.mat[2].z;
                        v305.origin.y = v282;
                        v305.origin.z = v283;
                        v305.radius = radius;
                        v86 = idBounds::SphereIntersection(this: (idBounds *)&v301.mat[2], s: &v305);
                      }
                      if ( v86 )
                      {
                        if ( !v42->active )
                        {
                          v88 = origin->y;
                          v89 = (float)((float)(v42->currentState.position.z * axis->mat[2].y)
                                      + (float)((float)(axis->mat[0].y * v42->currentState.position.x)
                                              + (float)(v42->currentState.position.y * axis->mat[1].y)));
                          v90 = (float)(origin->z
                                      + (float)((float)(v42->currentState.position.z * axis->mat[2].z)
                                              + (float)((float)(axis->mat[0].z * v42->currentState.position.x)
                                                      + (float)(v42->currentState.position.y * axis->mat[1].z))));
                          v42->currentState.position.x = (float)((float)(v42->currentState.position.z * axis->mat[2].x)
                                                               + (float)((float)(axis->mat[0].x
                                                                               * v42->currentState.position.x)
                                                                       + (float)(v42->currentState.position.y
                                                                               * axis->mat[1].x)))
                                                       + origin->x;
                          v42->currentState.position.y = (float)v88 + (float)v89;
                          v284 = (float)v88 + (float)v89;
                          v42->currentState.position.z = (float)v90 + (float)5.0;
                          idEffectPhysicsBroadPhase::SetObjectPosition(
                            this: v42->properties->broadPhase,
                            object: &v42->SPObject,
                            origin: &v42->currentState.position,
                            axis: &v42->currentState.orientation,
                            bounds: nullptr);
                          v91 = idMat3::operator*(this: v307, result: &v42->currentState.orientation, a: axis);
                          idEffectPhysicsRigidBody::SetOrientation(this: v42, m: v91);
                          v92 = (float)((float)(axis->mat[0].y * (float)v56) + (float)(axis->mat[2].y * (float)v58));
                          v93 = (float)((float)((float)v58 * axis->mat[2].x) + (float)((float)v57 * axis->mat[1].x));
                          v58 = (float)((float)((float)v57 * axis->mat[1].z)
                                      + (float)((float)(axis->mat[0].z * (float)v56)
                                              + (float)(axis->mat[2].z * (float)v58)));
                          v57 = (float)((float)(axis->mat[1].y * (float)v57) + (float)v92);
                          v56 = (float)((float)(axis->mat[0].x * (float)v56) + (float)v93);
                        }
                        v94 = (float)(v26->decl.impulse * (float)v57);
                        v95 = (float)(v26->decl.impulse * (float)v56);
                        v96 = (float)(v26->decl.impulse * (float)v58);
                        v97 = (float)((float)1.0 / (float)(v26->decl.falloff * (float)v59));
                        v98 = 1103515245 * this->random.seed + 12345;
                        this->random.seed = v98;
                        v299.b[1].z = (float)v97 * (float)v94;
                        v300 = (float)v97 * (float)v96;
                        v299.b[1].y = (float)v97 * (float)v95;
                        DWORD1(v99) = 1103515245 * v98 + 12345;
                        this->random.seed = DWORD1(v99);
                        v100 = 1103515245 * DWORD1(v99) + 12345;
                        v101 = (SDWORD1(v99) >> 16) & 0x7FFF;
                        this->random.seed = v100;
                        DWORD2(v99) = (v98 >> 16) & 0x7FFF;
                        v102 = v26->decl.angular;
                        LODWORD(v99) = (v100 >> 16) & 0x7FFF;
                        v286 = *(_QWORD *)(&v16 - 1);
                        v292 = *(_QWORD *)((char *)&v99 + 4);
                        v289 = v99;
                        v103 = v42->currentState.position.z;
                        v104 = v42->currentState.position.y;
                        v296.x = (float)((float)((float)((float)(__int64)v99 * (float)0.000061037019) - (float)1.0)
                                       * (float)v102)
                               + *v44;
                        v296.z = (float)v103
                               + (float)((float)v102
                                       * (float)((float)((float)*(__int64 *)((char *)&v99 + 4) * (float)0.000061037019)
                                               - (float)1.0));
                        v296.y = (float)v104
                               + (float)((float)v102
                                       * (float)((float)((float)*(__int64 *)(&v16 - 1) * (float)0.000061037019)
                                               - (float)1.0));
                        idEffectPhysicsRigidBody::ApplyImpulse(
                          this: v42,
                          point: &v296,
                          impulse: (const idVec3 *)&v299.b[1].y);
                        v42->active = true;
                        v42->SPObject.motion.ignore = false;
                      }
                    }
                  }
                }
                ++v40;
                ++v41;
              }
              while ( v40 < v26->decl.pieces.num );
              v22 = (const unsigned int *)v271;
              v14 = (int)gameMsPerFrame;
              v21 = v269;
            }
            v26->forceApplied = true;
            goto LABEL_54;
          }
          if ( v25 != nullptr )
LABEL_10:
            idFXManager::StopFX(this: v25, time: currentTime, stopCondition: FX_NONE, immediateStop: false);
        }
      }
      else if ( v25 != nullptr )
      {
        goto LABEL_10;
      }
LABEL_54:
      ++v23;
      ++v24;
    }
    while ( v23 < this->explosions.num );
  }
  v105 = 0;
  if ( this->rigidBodies.num > 0 )
  {
    LODWORD(v19) = v14;
    v106 = 0;
    v286 = v19;
    v107 = 0;
    v108 = (float)v19;
    do
    {
      idEffectPhysicsRigidBody::Update(
        this: this->rigidBodies.list[v106],
        deltaTime: (float)((float)v108 * 0.001),
        extraMomentumDecay: dampening,
        collision: (idEffectPhysicsCollision *)LODWORD(x));
      ++v105;
      v107 += 28;
      ++v106;
    }
    while ( v105 < this->rigidBodies.num );
  }
  if ( g_skipBreakableParticles.valueInteger == 0 )
  {
    v109 = this->trails.num;
    v272 = 0;
    if ( v109 > 0 )
    {
      v266 = 0;
      v284 = COERCE_FLOAT(&`VertexColorToByteWithScale'::`2'::SIMD_SP_255);
      do
      {
        v110 = 0;
        v111 = &this->trails.list[v266];
        v112 = (float)(v111->decl.minTrailVelocity * v111->decl.minTrailVelocity);
        v113 = (float)(v111->decl.minBounceVelocity * v111->decl.minBounceVelocity);
        if ( v111->decl.pieces.num > 0 )
        {
          p_pieces = &v111->decl.pieces;
          v115 = 0;
          v116 = 0;
          do
          {
            v117 = this->rigidBodies.list[p_pieces->list[v115]];
            if ( v117->active )
            {
              list = v111->pieceStartTime.list;
              v119 = list[v115];
              if ( v119 >= 0 )
              {
                if ( v119 == 0 )
                {
                  list[v115] = currentTime;
                  v126 = &v111->pieceLastParticleDropPos.list[v116].x;
                  *v126 = v117->currentState.position.x;
                  v126[1] = v117->currentState.position.y;
                  v126[2] = v117->currentState.position.z;
                }
                v127 = v111->pieceStartTime.list;
                delay = v111->decl.delay;
                v129 = v127[v115];
                if ( currentTime >= v129 + delay )
                {
                  if ( currentTime > v111->decl.duration + v129 + delay
                    || (v131 = (float)(v117->properties->inverseMass * v117->currentState.linearMomentum.y),
                        v132 = (float)(v117->properties->inverseMass * v117->currentState.linearMomentum.x),
                        (float)((float)((float)(v133 = (float)(v117->properties->inverseMass
                                                             * v117->currentState.linearMomentum.z))
                                      * (float)v133)
                              + (float)((float)((float)v132 * (float)v132) + (float)((float)v131 * (float)v131))) < v112) )
                  {
                    v127[v115] = -currentTime;
                  }
                  else
                  {
                    HIDWORD(v134) = &v111->decl.glowQuadMaterial;
                    if ( v111->decl.glowQuadMaterial != nullptr )
                    {
                      v287.startPos.z = 0.0;
                      v287.startPos.y = 0.0;
                      v287.color[2] = -1;
                      v287.startPos.x = 0.0;
                      *(_WORD *)&v287.tangent[0][1] = 0;
                      v287.endPos.z = 0.0;
                      *(_WORD *)&v287.tangent[1][1] = 0;
                      v287.endPos.x = 0.0;
                      *(_WORD *)&v287.tangent[2][0] = 0;
                      v287.endPos2.z = 0.0;
                      *(_WORD *)&v287.tangent[3][1] = 0;
                      v287.endPos2.x = 0.0;
                      v287.color[0] = -1;
                      v287.sMinMax.x = 0.0;
                      v287.color[3] = -1;
                      v287.orientVec.y = 0.0;
                      v287.tangent[0][0] = 0;
                      v287.orientVec.x = 0.0;
                      v287.startPos2.x = 0.0;
                      v287.sMinMax.y = 1.0;
                      v287.color[1] = -1;
                      v287.tMinMax.x = 0.0;
                      v287.tangent[2][2] = 0;
                      v287.halfWidth = 0.0;
                      v287.endPos.y = 0.0;
                      v287.tangent[3][0] = 0;
                      v287.startPos2.z = 0.0;
                      v287.tangent[1][0] = 0;
                      v287.startPos2.y = 0.0;
                      v287.endPos2.y = 0.0;
                      v287.tMinMax.y = 1.0;
                      LODWORD(v134) = currentTime;
                      v287.orientVec.z = 0.0;
                      v135 = 1.0;
                      v136 = v117->currentState.position.y;
                      v137 = v117->currentState.position.x;
                      v138 = (float)(v111->decl.glowQuadSize * (float)0.5);
                      v139 = (float)((float)(v111->decl.glowQuadSize * (float)0.5) * vec3_up.z);
                      v140 = (float)((float)(v111->decl.glowQuadSize * (float)0.5) * vec3_up.y);
                      v141 = (float)((float)(v111->decl.glowQuadSize * (float)0.5) * vec3_up.x);
                      v287.startPos.z = (float)((float)(v111->decl.glowQuadSize * (float)0.5) * vec3_up.z)
                                      + v117->currentState.position.z;
                      v287.startPos.y = (float)v140 + (float)v136;
                      v287.startPos.x = (float)v141 + (float)v137;
                      v142 = v117->currentState.position.z;
                      v143 = (float)(v117->currentState.position.y - (float)v140);
                      v287.endPos.x = v117->currentState.position.x - (float)v141;
                      v287.halfWidth = v138;
                      v287.endPos.z = (float)v142 - (float)v139;
                      v287.endPos.y = v143;
                      v145 = v111->pieceStartTime.list[v115];
                      LODWORD(v146) = v111->decl.fadeInDuration;
                      fadeOutDuration = v111->decl.fadeOutDuration;
                      *(_QWORD *)((char *)&v146 + 4) = __PAIR64__(fadeOutDuration, v145);
                      v289 = *(_QWORD *)&v111->decl.delay;
                      v144 = v289;
                      v292 = *(__int64 *)((char *)&v144 + 4);
                      v290 = __PAIR64__(fadeOutDuration, v145);
                      v293 = v146;
                      v306[2] = v134;
                      v291 = *(__int64 *)((char *)&v144 - 4);
                      v149 = (float)v134;
                      v150 = (float)((float)((float)v289 - (float)*(__int64 *)((char *)&v144 - 4))
                                   + (float)((float)__SPAIR64__(fadeOutDuration, v145)
                                           + (float)*(__int64 *)((char *)&v144 + 4)));
                      if ( v149 <= (float)((float)(__int64)v146
                                         + (float)((float)__SPAIR64__(fadeOutDuration, v145)
                                                 + (float)*(__int64 *)((char *)&v144 + 4))) )
                      {
                        v148 = (float)((float)__SPAIR64__(fadeOutDuration, v145) + (float)*(__int64 *)((char *)&v144 + 4));
                        v135 = (float)((float)((float)v134 - (float)v148)
                                     / (float)((float)((float)v293 + (float)v148) - (float)v148));
                      }
                      if ( v149 >= v150 )
                        v135 = (float)((float)((float)1.0
                                             - (float)((float)((float)v134 - (float)v150)
                                                     / (float)((float)((float)((float)__SPAIR64__(fadeOutDuration, v145)
                                                                             + (float)*(__int64 *)((char *)&v144 + 4))
                                                                     + (float)v289)
                                                             - (float)v150)))
                                     * (float)v135);
                      _R9 = &v301.mat[2];
                      v301.mat[2].y = 1.0;
                      v301.mat[2].z = 1.0;
                      _R8 = v284;
                      v301.mat[2].x = 1.0;
                      _R7 = v287.color;
                      v302 = v135;
                      _R5 = &v287.color[1];
                      _R3 = &v287.color[2];
                      _R27 = &v287.color[3];
                      __asm { lvx128    v63, r0, r8 }
                      __asm
                      {
                        lvx128    v62, r0, r9
                        vmulfp128 v61, v94, v63
                        vcfpsxws128 v60, v61, 0
                        vpkswss128 v59, v92, v60
                        vpkshus128 v0, v91, v59
                        stvebx    v0, 0, r7
                        stvebx    v0, 0, r5
                        stvebx    v0, 0, r3
                        stvebx    v0, 0, r27
                      }
                      idRenderModelBeam::DrawBeam(
                        this: this->gameLibEffects->beamModel,
                        node: &v287,
                        mtr: *(const idMaterial **)HIDWORD(v134),
                        type: BEAM_ORIENT_VIEWER);
                    }
                    v157 = &this->collisions.list[p_pieces->list[v115]];
                    if ( v111->decl.particleBounce != nullptr
                      && (float)((float)(v157->collisionNormalVelocity.z * v157->collisionNormalVelocity.z)
                               + (float)((float)(v157->collisionNormalVelocity.x * v157->collisionNormalVelocity.x)
                                       + (float)(v157->collisionNormalVelocity.y * v157->collisionNormalVelocity.y))) > v113 )
                    {
                      idVec3::ToZAxis(this: v307[0].mat, result: (idMat3 *)&v157->collisionNormalVelocity);
                      v158 = this->random.seed;
                      HIDWORD(v270) = -1;
                      v159 = (const unsigned int *)v271;
                      v160 = *v269;
                      v161 = 1103515245 * v158 + 12345;
                      this->random.seed = v161;
                      LODWORD(v162) = (v161 >> 16) & 0x7FFF;
                      *(_QWORD *)&v299.b[0].x = v162;
                      idRenderModelEffects::AddParticles(
                        this: this->gameLibEffects->effectsModel,
                        particle: v111->decl.particleBounce,
                        systemStartTime: currentTime,
                        (const int)gameMsPerFrame,
                        diversity: (float)((float)v162 * (float)v160),
                        origin: (const idVec3 *)this->gameLibEffects,
                        axis: (const idMat3 *)v157,
                        velocity: v307[0].mat,
                        color: v159);
                    }
                    impactTable = this->soundInfo.impactTable;
                    if ( this->soundInfo.soundWorld != nullptr
                      && impactTable != nullptr
                      && currentTime >= this->soundInfo.nextSoundTime
                      && (float)((float)(v157->collisionNormalVelocity.x * v157->collisionNormalVelocity.x)
                               + (float)((float)(v157->collisionNormalVelocity.y * v157->collisionNormalVelocity.y)
                                       + (float)(v157->collisionNormalVelocity.z * v157->collisionNormalVelocity.z))) > (double)this->soundInfo.minBounceVelSqr )
                    {
                      ImpactSoundForMaterial = idDeclImpactSound::GetImpactSoundForMaterial(
                                                 this: this->soundInfo.impactTable,
                                                 materialID: v157->collisionSurfaceType);
                      if ( ImpactSoundForMaterial != nullptr )
                      {
                        this->soundInfo.soundWorld->PlayPositionedShaderDirectly(
                          this: this->soundInfo.soundWorld,
                          a2: ImpactSoundForMaterial,
                          a3: (const idVec3 *)&v117->currentState,
                          a4: v277,
                          a5: 0.0);
                        this->soundInfo.nextSoundTime = impactTable->soundInterval + currentTime;
                      }
                    }
                    if ( v111->decl.particleTrail != nullptr )
                    {
                      trailVelocityScale = v111->decl.trailVelocityScale;
                      v166 = *v276;
                      v167 = (float)(v117->properties->inverseMass * v117->currentState.linearMomentum.z);
                      v168 = (float)(v117->properties->inverseMass * v117->currentState.linearMomentum.x);
                      v303[1] = (float)(v117->properties->inverseMass * v117->currentState.linearMomentum.y)
                              * v111->decl.trailVelocityScale;
                      v303[2] = (float)v167 * (float)trailVelocityScale;
                      v303[0] = (float)v168 * (float)trailVelocityScale;
                      v169 = &v111->pieceLastParticleDropPos.list[v116].x;
                      v170 = (float)(v117->currentState.position.y - v169[1]);
                      v171 = (float)(v117->currentState.position.x - *v169);
                      v172 = (float)(v117->currentState.position.z - v169[2]);
                      _FP1 = (float)((float)((float)((float)v172 * (float)v172)
                                           + (float)((float)((float)v171 * (float)v171)
                                                   + (float)((float)v170 * (float)v170)))
                                   - (float)v166);
                      __asm { fsel      f13, f1, f2, f8 }
                      v175 = __frsqrte(_FP13);
                      v176 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v175 * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5)) * (float)v175)
                                                                                           - (float)1.5)
                                                                           * (float)v175)
                                                                   * (float)((float)((float)((float)v172 * (float)v172)
                                                                                   + (float)((float)((float)v171 * (float)v171)
                                                                                           + (float)((float)v170 * (float)v170)))
                                                                           * (float)0.5))
                                                           * (float)((float)-(float)((float)((float)((float)v175 * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5))
                                                                                           * (float)v175)
                                                                                   - (float)1.5)
                                                                   * (float)v175))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)v175
                                                                           * (float)((float)((float)((float)v172 * (float)v172)
                                                                                           + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170)))
                                                                                   * (float)0.5))
                                                                   * (float)v175)
                                                           - (float)1.5)
                                           * (float)v175));
                      v177 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v175 * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5)) * (float)v175) - (float)1.5) * (float)v175) * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v175 * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5)) * (float)v175) - (float)1.5) * (float)v175))
                                                                                           - (float)1.5)
                                                                           * (float)((float)-(float)((float)((float)((float)v175 * (float)((float)((float)((float)v172 * (float)v172) + (float)((float)((float)v171 * (float)v171) + (float)((float)v170 * (float)v170))) * (float)0.5)) * (float)v175) - (float)1.5)
                                                                                   * (float)v175))
                                                                   * (float)((float)((float)((float)v172 * (float)v172)
                                                                                   + (float)((float)((float)v171 * (float)v171)
                                                                                           + (float)((float)v170 * (float)v170)))
                                                                           * (float)0.5))
                                                           * (float)v176)
                                                   - (float)1.5)
                                   * (float)v176);
                      v281.mat[0].x = (float)v177 * (float)(v117->currentState.position.x - *v169);
                      v281.mat[0].z = (float)v177 * (float)v172;
                      v281.mat[0].y = (float)v177 * (float)v170;
                      v178 = (float)((float)v177
                                   * (float)((float)((float)v172 * (float)v172)
                                           + (float)((float)((float)v171 * (float)v171)
                                                   + (float)((float)v170 * (float)v170))));
                      if ( v178 > v111->decl.trailSpacing )
                      {
                        idVec3::ToZAxis(this: v307[0].mat, result: &v281);
                        v182 = 1;
                        LODWORD(v270) = (int)(float)((float)v178 / v111->decl.trailSpacing);
                        v183 = v270;
                        if ( (int)v270 >= 1 )
                        {
                          v184 = v269;
                          do
                          {
                            LODWORD(v185) = v182;
                            HIDWORD(v185) = this->random.seed;
                            trailSpacing = v111->decl.trailSpacing;
                            *(_QWORD *)&v288.x = v185;
                            v187 = (double)v185;
                            HIDWORD(v185) = 1103515245 * HIDWORD(v185) + 12345;
                            v188 = v281.mat[0].z;
                            v189 = v281.mat[0].y;
                            v190 = v281.mat[0].x;
                            LODWORD(v185) = &v111->pieceLastParticleDropPos.list[v116];
                            LODWORD(v181) = (SHIDWORD(v185) >> 16) & 0x7FFF;
                            HIDWORD(v270) = -1;
                            v191 = *v184;
                            v267 = v181;
                            v192 = *(float *)(v185 + 8);
                            v193 = *(float *)(v185 + 4);
                            v194 = (float)((float)v187 * (float)trailSpacing);
                            v195 = *(float *)v185;
                            this->random.seed = HIDWORD(v185);
                            v301.mat[0].z = (float)v192 + (float)((float)v194 * (float)v188);
                            v301.mat[0].y = (float)v193 + (float)((float)v194 * (float)v189);
                            v301.mat[0].x = (float)((float)v194 * (float)v190) + (float)v195;
                            idRenderModelEffects::AddParticles(
                              this: this->gameLibEffects->effectsModel,
                              particle: v111->decl.particleTrail,
                              systemStartTime: currentTime,
                              (const int)gameMsPerFrame,
                              diversity: (float)((float)v267 * (float)v191),
                              origin: v180,
                              axis: &v301,
                              velocity: v307[0].mat,
                              color: (const unsigned int *)v303);
                            ++v182;
                          }
                          while ( v182 <= v183 );
                        }
                        LODWORD(v179) = v183;
                        v196 = v111->decl.trailSpacing;
                        v197 = v111->pieceLastParticleDropPos.list;
                        *(_QWORD *)&v281.mat[1].y = v179;
                        v198 = &v197[v116].x;
                        v199 = v198[1];
                        v200 = v198[2];
                        v201 = (float)((float)((float)v179 * (float)v196) * v281.mat[0].z);
                        v202 = (float)((float)((float)v179 * (float)v196) * v281.mat[0].y);
                        *v198 = (float)((float)((float)v179 * (float)v196) * v281.mat[0].x) + *v198;
                        v198[2] = (float)v201 + (float)v200;
                        v198[1] = (float)v202 + (float)v199;
                      }
                    }
                  }
                }
                else
                {
                  v130 = &v111->pieceLastParticleDropPos.list[v116].x;
                  *v130 = v117->currentState.position.x;
                  v130[1] = v117->currentState.position.y;
                  v130[2] = v117->currentState.position.z;
                }
              }
              else if ( v111->decl.particleDie != nullptr )
              {
                v120 = this->random.seed;
                HIDWORD(v270) = -1;
                v121 = (const unsigned int *)v271;
                v122 = (const idVec3 *)v277;
                v123 = *v269;
                v124 = 1103515245 * v120 + 12345;
                this->random.seed = v124;
                HIDWORD(v125) = this->gameLibEffects;
                LODWORD(v125) = (v124 >> 16) & 0x7FFF;
                v286 = v125;
                idRenderModelEffects::AddParticles(
                  this: *(idRenderModelEffects **)HIDWORD(v125),
                  particle: v111->decl.particleDie,
                  systemStartTime: -v111->pieceStartTime.list[v115],
                  (const int)gameMsPerFrame,
                  diversity: (float)((float)v125 * (float)v123),
                  origin: (const idVec3 *)v111->pieceStartTime.list[v115],
                  axis: (const idMat3 *)&v117->currentState,
                  velocity: v122,
                  color: v121);
              }
            }
            ++v110;
            ++v116;
            ++v115;
          }
          while ( v110 < v111->decl.pieces.num );
        }
        v203 = this->trails.num;
        ++v272;
        ++v266;
      }
      while ( v272 < v203 );
    }
  }
  if ( this->gameLibEffects != nullptr )
  {
    v204 = 0;
    if ( this->decals.num > 0 )
    {
      v205 = 0;
      do
      {
        v206 = 0;
        v207 = &this->decals.list[v205];
        v208 = (float)(v207->decl.minBounceVelocity * v207->decl.minBounceVelocity);
        if ( v207->decl.pieces.num > 0 )
        {
          v209 = 0;
          v210 = 0;
          do
          {
            v211 = this->rigidBodies.list[v207->decl.pieces.list[v210]];
            if ( v211->active )
            {
              v212 = v207->pieceStartTime.list;
              if ( v212[v210] == 0 )
              {
                v212[v210] = currentTime;
                v213 = &v207->pieceLastDecalDropPos.list[v209].x;
                *v213 = v211->currentState.position.x;
                v213[1] = v211->currentState.position.y;
                v213[2] = v211->currentState.position.z;
              }
              v214 = &v211->currentState.position.x;
              v216 = v211->currentState.position.y;
              v217 = v211->currentState.position.x;
              v215 = &v207->pieceLastDecalDropPos.list[v209].x;
              v218 = (float)(v215[1] - (float)v216);
              v219 = (float)(v215[2] - v214[2]);
              if ( (float)((float)((float)v219 * (float)v219)
                         + (float)((float)((float)(*v215 - (float)v217) * (float)(*v215 - (float)v217))
                                 + (float)((float)v218 * (float)v218))) >= (double)v207->decl.decalSpacing )
              {
                v220 = false;
                v221 = this->collisions.list;
                v222 = v207->decl.pieces.list[v210];
                v223 = v221[v222].collisionPoint.y;
                v224 = v221[v222].collisionPoint.z;
                v273 = v221[v222].collisionPoint.x;
                v274 = v223;
                v275 = v224;
                v225 = !v207->decl.splatterOnBounce;
                v226 = v207->decl.pieces.list[v210];
                v227 = &v221[v226];
                v228 = v227->collisionNormalVelocity.z;
                LODWORD(v229) = LODWORD(v227->collisionNormalVelocity.y);
                *(float *)&v267 = v227->collisionNormalVelocity.x;
                HIDWORD(v229) = HIDWORD(v267);
                LODWORD(v267) = v229;
                v230 = *((float *)&v229 + 1);
                v268 = v228;
                v231 = *(float *)&v267;
                v232 = v228;
                if ( !v225 )
                  v220 = (float)((float)(v268 * v268)
                               + (float)((float)(*(float *)&v267 * *(float *)&v267)
                                       + (float)(*((float *)&v267 + 1) * *((float *)&v267 + 1)))) > v208;
                if ( v207->decl.splatterOnRest && this->rigidBodies.list[v226]->settled )
                {
                  if ( ((HIDWORD(v267) | (unsigned int)v229 | LODWORD(v228)) & 0x7FFFFFFF) == 0 )
                  {
                    v233 = &v207->lastCollisionPos.list[v209].x;
                    v273 = *v233;
                    v274 = v233[1];
                    v275 = v233[2];
                    v234 = &v207->lastCollisionNormal.list[v209].x;
                    v231 = *v234;
                    v230 = v234[1];
                    v232 = v234[2];
                    *(float *)&v267 = *v234;
                    *((float *)&v267 + 1) = v230;
                    v268 = v232;
                    v229 = v267;
                    v228 = v268;
                  }
                  v220 = true;
                }
                if ( v220 )
                {
                  v295[2] = 32.0;
                  v295[0] = 0.0;
                  v295[3] = 32.0;
                  LODWORD(v295[6]) = 2000;
                  v295[4] = 0.0;
                  v295[7] = 0.0;
                  HIBYTE(v295[8]) = 0;
                  v295[1] = 8.0;
                  LODWORD(v295[5]) = 10000;
                  v235 = v207->decl.materials.num;
                  if ( v235 != 0 )
                  {
                    v237 = this->random.seed;
                    __twllei(v235, 0);
                    v238 = 1103515245 * v237 + 12345;
                    this->random.seed = v238;
                    v239 = (v238 >> 16) & 0x7FFF;
                    v240 = v235 & ~(__ROL4__(v239, 1) - 1);
                    v236 = v239 % v235;
                    __twlgei(v240, 0xFFFFFFFF);
                  }
                  else
                  {
                    v236 = 0;
                  }
                  v241 = v207->decl.materials.list;
                  v242 = v236;
                  v243 = 1103515245 * this->random.seed;
                  v244 = v276;
                  LODWORD(v284) = &v207->decl.maxSize;
                  v245 = *v269;
                  LODWORD(v295[0]) = v241[v242];
                  v243 += 12345;
                  v246 = (v243 >> 16) & 0x7FFF;
                  *(_QWORD *)&v281.mat[1].y = *(_QWORD *)(&v16 - 1);
                  v295[1] = v207->decl.depth;
                  v295[7] = *(float *)&v207->decl.fadeInEndTime;
                  v295[6] = *(float *)&v207->decl.fadeOutStartTime;
                  v295[5] = *(float *)&v207->decl.lifetime;
                  v247 = v207->decl.maxSize.x;
                  v248 = (float)(v207->decl.maxSize.y - v207->decl.minSize.y);
                  v249 = v207->decl.minSize.x;
                  this->random.seed = v243;
                  _FP12 = (float)((float)((float)((float)v232 * (float)v232)
                                        + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230)))
                                - *v244);
                  v251 = this->gameLibEffects;
                  __asm { fsel      f11, f12, f11, f0 }
                  v253 = (float)(v207->decl.minSize.x
                               + (float)((float)((float)v247 - (float)v249)
                                       * (float)((float)*(__int64 *)(&v16 - 1) * (float)v245)));
                  v295[3] = (float)((float)v248 * (float)((float)*(__int64 *)(&v16 - 1) * (float)v245))
                          + v207->decl.minSize.y;
                  v295[2] = v253;
                  v254 = __frsqrte(_FP11);
                  v255 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)((float)((float)((float)v232 * (float)v232) + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230))) * (float)0.5))
                                                                                               * (float)v254)
                                                                                       - (float)1.5)
                                                                       * (float)v254)
                                                               * (float)((float)((float)((float)v232 * (float)v232)
                                                                               + (float)((float)((float)v231
                                                                                               * (float)v231)
                                                                                       + (float)((float)v230
                                                                                               * (float)v230)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v254
                                                                                               * (float)((float)((float)((float)v232 * (float)v232) + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230))) * (float)0.5))
                                                                                       * (float)v254)
                                                                               - (float)1.5)
                                                               * (float)v254))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v254
                                                                       * (float)((float)((float)((float)v232
                                                                                               * (float)v232)
                                                                                       + (float)((float)((float)v231 * (float)v231)
                                                                                               + (float)((float)v230 * (float)v230)))
                                                                               * (float)0.5))
                                                               * (float)v254)
                                                       - (float)1.5)
                                       * (float)v254));
                  v256 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)((float)((float)((float)v232 * (float)v232) + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230))) * (float)0.5)) * (float)v254)
                                                                                               - (float)1.5)
                                                                               * (float)v254)
                                                                       * (float)((float)((float)((float)v232
                                                                                               * (float)v232)
                                                                                       + (float)((float)((float)v231 * (float)v231)
                                                                                               + (float)((float)v230 * (float)v230)))
                                                                               * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)((float)v254 * (float)((float)((float)((float)v232 * (float)v232) + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230))) * (float)0.5))
                                                                                               * (float)v254)
                                                                                       - (float)1.5)
                                                                       * (float)v254))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)v254
                                                                               * (float)((float)((float)((float)v232 * (float)v232)
                                                                                               + (float)((float)((float)v231 * (float)v231) + (float)((float)v230 * (float)v230)))
                                                                                       * (float)0.5))
                                                                       * (float)v254)
                                                               - (float)1.5)
                                               * (float)v254))
                               * (float)((float)((float)((float)v232 * (float)v232)
                                               + (float)((float)((float)v231 * (float)v231)
                                                       + (float)((float)v230 * (float)v230)))
                                       * (float)0.5));
                  v278 = (float)v231
                       * (float)((float)-(float)((float)((float)v256 * (float)v255) - (float)1.5) * (float)v255);
                  v279 = *((float *)&v229 + 1)
                       * (float)((float)-(float)((float)((float)v256 * (float)v255) - (float)1.5) * (float)v255);
                  v280 = v228 * (float)((float)-(float)((float)((float)v256 * (float)v255) - (float)1.5) * (float)v255);
                  v251->decalModel->AddDecalFromPoint(
                    this: (idRenderModel *)&v270,
                    result: (idHandle<int,enum invalidDecalHandle_t,-1> *)v251->decalModel,
                    a3: (const decalParams_t *)v295,
                    a4: currentTime,
                    a5: (const idVec3 *)&v273,
                    a6: (const idVec3 *)&v278,
                    a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
                  v257 = &v207->pieceLastDecalDropPos.list[v209].x;
                  *v257 = *v214;
                  v257[1] = v214[1];
                  v257[2] = v214[2];
                  if ( g_debugBreakableDecals.valueInteger != 0 )
                  {
                    v258 = common->RW(this: common);
                    *(float *)v306 = 1.0;
                    *((float *)v306 + 1) = 0.0;
                    *(float *)&v306[1] = 0.0;
                    *((float *)&v306[1] + 1) = 1.0;
                    v297[2] = v275 + (float)(v280 * (float)15.0);
                    v297[1] = v274 + (float)(v279 * (float)15.0);
                    v297[0] = v273 + (float)(v278 * (float)15.0);
                    v258->DebugLine(
                      this: v258,
                      a2: (const idVec4 *)v306,
                      a3: (const idVec3 *)v214,
                      a4: (const idVec3 *)v297,
                      a5: 10000,
                      a6: false);
                  }
                }
                if ( ((HIDWORD(v229) | (unsigned int)v229 | LODWORD(v228)) & 0x7FFFFFFF) != 0 )
                {
                  v259 = &v207->lastCollisionNormal.list[v209].x;
                  *v259 = v231;
                  v259[1] = v230;
                  v259[2] = v232;
                  v260 = &v207->lastCollisionPos.list[v209].x;
                  *v260 = v273;
                  v260[1] = v274;
                  v260[2] = v275;
                }
              }
            }
            ++v206;
            ++v210;
            ++v209;
          }
          while ( v206 < v207->decl.pieces.num );
        }
        ++v204;
        ++v205;
      }
      while ( v204 < this->decals.num );
    }
  }
  if ( v294[0].logIndex >= 0 )
  {
    pLog = v294[0].pLog;
    v262 = &v294[0].pLog->logEntries.list[v294[0].logIndex];
    v263 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v262->totalTicks;
    HIDWORD(totalTicks) = v262->parent;
    LODWORD(v265) = v263 - totalTicks;
    v262->totalTicks = v265;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
}


// ========================================================================
// __unwind$257090
// EA  : 0x826FEC1C
// RVA : 0x006FEC1C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_257090()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 944 + 400));
}


// ========================================================================
// ?DamagePiece@idEffectPhysicsBreakable@@AAA_NHHMABVidVec3@@@Z
// EA  : 0x826FEC48
// RVA : 0x006FEC48
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

int __fastcall idEffectPhysicsBreakable::DamagePiece(
        idEffectPhysicsBreakable *this,
        int time,
        int piece,
        double amount,
        const idVec3 *pos,
        float *a6)
{
  const idDeclBreakable *decl; // r11
  int v10; // r30
  int v11; // r26
  __int64 v12; // r10
  double v13; // fp31
  const idDeclParticle *harmlessParticle; // r11
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  int v19; // r29
  float *list; // r11
  double v21; // fp13
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  __int64 v25; // [sp+50h] [-70h] BYREF
  idEffectPhysicsBreakable::idBreakableParticle v26; // [sp+60h] [-60h] BYREF

  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  v10 = piece;
  v11 = 1;
  if ( !this->rigidBodies.list[piece]->active )
  {
    if ( decl->armoredPieces.num <= piece )
      LODWORD(v12) = 0;
    else
      LODWORD(v12) = decl->armoredPieces.list[piece];
    HIDWORD(v12) = 0x82000000;
    v25 = v12;
    v13 = (float)((float)amount - (float)v12);
    if ( v13 <= 0.0 )
      goto LABEL_7;
    if ( decl->healthPieces.num > piece )
    {
      v19 = decl->healthPieces.list[piece];
      if ( v19 == -1 )
      {
LABEL_7:
        harmlessParticle = decl->settings.harmlessParticle;
        if ( harmlessParticle != nullptr )
        {
          v15 = *a6;
          v26.particle = harmlessParticle;
          v16 = a6[1];
          v26.startTime = time;
          v17 = a6[2];
          v26.pos.x = v15;
          v26.pos.y = v16;
          v26.pos.z = v17;
          idList<idEffectPhysicsBreakable::idBreakableParticle,59>::Append(this: &this->particles, obj: &v26);
        }
        return 0;
      }
      if ( v19 > 0 )
      {
        if ( this->damage.num == 0 )
        {
          *(float *)&v25 = 0.0;
          idList<float,17>::SetNum(
            this: (idList<float,32> *)&this->damage,
            newNum: this->rigidBodies.num,
            initValue: (float *)&v25);
        }
        LODWORD(v12) = v19;
        list = this->damage.list;
        v25 = v12;
        v21 = (float)(list[v10] + (float)v13);
        list[v10] = list[v10] + (float)v13;
        if ( v21 < (float)v12 )
          v11 = 0;
      }
    }
  }
  if ( (_BYTE)v11 != 0 && this->decl->settings.impactParticle != nullptr )
  {
    v22 = *a6;
    v26.particle = this->decl->settings.impactParticle;
    v23 = a6[1];
    v26.startTime = time;
    v24 = a6[2];
    v26.pos.x = v22;
    v26.pos.y = v23;
    v26.pos.z = v24;
    idList<idEffectPhysicsBreakable::idBreakableParticle,59>::Append(this: &this->particles, obj: &v26);
  }
  return v11;
}


// ========================================================================
// ?RemoveExplosions@idEffectPhysicsBreakable@@QAAXXZ
// EA  : 0x826FF090
// RVA : 0x006FF090
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::RemoveExplosions(idEffectPhysicsBreakable *this)
{
  char *list; // r3
  idFXManager *v3; // r3

  if ( this->explosions.listStatic == 0 || this->explosions.listStatic == 2 )
  {
    list = (char *)this->explosions.list;
    if ( list != nullptr )
      idListArrayDelete<idEffectPhysicsBreakable::idExplosion>(ptr: list, num: this->explosions.size);
    this->explosions.list = nullptr;
    this->explosions.size = 0;
  }
  this->explosions.num = 0;
  if ( this->explosionFX.listStatic == 0 || this->explosionFX.listStatic == 2 )
  {
    v3 = this->explosionFX.list;
    if ( v3 != nullptr )
      idListArrayDelete<idFXManager>(ptr: v3, num: this->explosionFX.size);
    this->explosionFX.list = nullptr;
    this->explosionFX.size = 0;
  }
  this->explosionFX.num = 0;
}


// ========================================================================
// ?AddRayImpact@idEffectPhysicsBreakable@@QAAXHABVidVec3@@ABVidMat3@@00_N@Z
// EA  : 0x826FF130
// RVA : 0x006FF130
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsBreakable::AddRayImpact(
        idEffectPhysicsBreakable *this,
        int time,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *start,
        const idVec3 *end,
        bool ignoreActivePieces)
{
  int v7; // r2 OVERLAPPED
  double y; // fp12
  double v10; // fp8
  double z; // fp11
  double v12; // fp6
  double x; // fp10
  double v14; // fp4
  double v22; // fp2
  double v23; // fp3
  double v24; // fp2
  double v25; // fp3
  double v26; // fp28
  double v27; // fp31
  double v28; // fp30
  double v29; // fp29
  int v30; // r24
  BOOL v31; // r15
  float v32; // r18
  float v33; // r17
  const idDeclParticle *particle; // r16
  int i; // r23
  idEffectPhysicsRigidBody *v36; // r31
  char *v37; // r10
  _WORD *v38; // r11
  int j; // ctr
  int v40; // r9 OVERLAPPED
  __int128 v41; // r6 OVERLAPPED
  __int64 v42; // r8 OVERLAPPED
  const idVec3 *v43; // r6
  BOOL active; // r11
  double v45; // fp9
  double v46; // fp5
  double v47; // fp2
  double v48; // fp1
  double v49; // fp25
  double v50; // fp24
  double v51; // fp23
  const idMat3 *v52; // r3
  double v53; // fp11
  double v54; // fp10
  const idDeclBreakable *decl; // r11
  const idDeclParticle *harmlessParticle; // r11
  idEffectPhysicsBreakable::idBreakableParticle v57; // [sp+50h] [-1B0h] BYREF
  idVec3 v58; // [sp+68h] [-198h] BYREF
  char v59; // [sp+76h] [-18Ah] BYREF
  __int16 v60; // [sp+78h] [-188h]
  __int16 v61; // [sp+7Ah] [-186h]
  unsigned __int16 v62; // [sp+7Ch] [-184h]
  __int16 v63; // [sp+7Eh] [-182h]
  unsigned __int16 v64; // [sp+80h] [-180h]
  __int16 v65; // [sp+82h] [-17Eh]
  idBounds v66; // [sp+90h] [-170h] BYREF
  idVec3 v67; // [sp+A8h] [-158h] BYREF
  __int64 v68; // [sp+B8h] [-148h]
  __int64 v69; // [sp+C0h] [-140h]
  __int64 v70; // [sp+C8h] [-138h]
  __int64 v71; // [sp+D0h] [-130h]
  __int64 v72; // [sp+D8h] [-128h]
  __int64 v73; // [sp+E0h] [-120h]
  idMat3 v74[3]; // [sp+F0h] [-110h] BYREF

  y = start->y;
  v10 = (float)(end->y - start->y);
  z = start->z;
  v12 = (float)(end->z - start->z);
  x = start->x;
  v14 = (float)(end->x - start->x);
  _FP7 = (float)((float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f7, f1, f13 }
  v22 = __frsqrte(_FP3);
  v23 = (float)((float)-(float)((float)((float)((float)v22
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v22)
                              - (float)1.5)
              * (float)v22);
  v24 = (float)((float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)((float)v14 * (float)v14)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22)
              * (float)((float)((float)((float)v14 * (float)v14)
                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                      * (float)0.5));
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5)
                                                      * (float)v23)
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5)
                                              * (float)v23))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23));
  v26 = (float)((float)v25
              * (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                      + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))));
  v27 = (float)((float)(end->x - start->x) * (float)v25);
  v28 = (float)((float)(end->y - start->y) * (float)v25);
  *(float *)&v57.particle = (float)(end->x - start->x) * (float)v25;
  v57.pos.x = (float)v10 * (float)v25;
  v29 = (float)((float)v12 * (float)v25);
  v57.pos.y = (float)v12 * (float)v25;
  if ( v26 == 0.0 )
  {
    decl = this->decl;
    if ( decl != nullptr )
    {
      harmlessParticle = decl->settings.harmlessParticle;
      if ( harmlessParticle != nullptr )
      {
        v57.pos.x = x;
        v57.particle = harmlessParticle;
        v57.pos.y = y;
        v57.startTime = time;
        v57.pos.z = z;
        idList<idEffectPhysicsBreakable::idBreakableParticle,59>::Append(this: &this->particles, obj: &v57);
      }
    }
  }
  else
  {
    v30 = 0;
    if ( this->rigidBodies.num > 0 )
    {
      v31 = ignoreActivePieces;
      v32 = v57.pos.y;
      v33 = v57.pos.x;
      particle = v57.particle;
      for ( i = 0; ; ++i )
      {
        v36 = this->rigidBodies.list[i];
        if ( v31 && v36->active )
          goto LABEL_16;
        v37 = &v59;
        v38 = (_WORD *)&v36->SPObject.axis.mat[2].z + 1;
        for ( j = 6; j != 0; --j )
        {
          ++v38;
          v37 += 2;
          *(_WORD *)v37 = *v38;
        }
        v40 = v60;
        LODWORD(v41) = v63;
        DWORD1(v41) = v62;
        HIDWORD(v41) = v65;
        DWORD2(v41) = v64;
        LODWORD(v42) = v61;
        HIDWORD(v42) = (__int16)v62;
        v69 = v41;
        DWORD2(v41) = (__int16)v64;
        v73 = v42;
        v71 = *(_QWORD *)((char *)&v41 - 4);
        v70 = *(_QWORD *)((char *)&v41 + 4);
        v68 = *(_QWORD *)(&v7 - 1);
        v72 = *(_QWORD *)&v40;
        v66.b[0].x = (float)*(__int64 *)&v40;
        v66.b[1].x = (float)v69;
        v66.b[0].y = (float)v42;
        v66.b[0].z = (float)*(__int64 *)((char *)&v41 - 4);
        v66.b[1].z = (float)*(__int64 *)(&v7 - 1);
        v66.b[1].y = (float)*(__int64 *)((char *)&v41 + 4);
        if ( !v36->active )
          idBounds::FromTransformedBounds(this: &v66, bounds: &v66, origin, axis);
        if ( idBounds::LineIntersection(this: &v66, start, end) )
        {
          active = v36->active;
          LODWORD(v58.x) = particle;
          v58.y = v33;
          v58.z = v32;
          if ( active )
            goto LABEL_15;
          if ( (unsigned __int8)idEffectPhysicsBreakable::DamagePiece(
                                  this,
                                  time,
                                  piece: v30,
                                  amount: v26,
                                  pos: v43,
                                  a6: &start->x) != 0 )
            break;
        }
LABEL_16:
        if ( ++v30 >= this->rigidBodies.num )
          return;
      }
      v45 = origin->y;
      v46 = origin->z;
      v47 = (float)((float)(axis->mat[2].y * v36->currentState.position.z)
                  + (float)((float)(axis->mat[0].y * v36->currentState.position.x)
                          + (float)(axis->mat[1].y * v36->currentState.position.y)));
      v48 = (float)((float)(axis->mat[2].z * v36->currentState.position.z)
                  + (float)((float)(axis->mat[0].z * v36->currentState.position.x)
                          + (float)(axis->mat[1].z * v36->currentState.position.y)));
      v49 = (float)(origin->x
                  + (float)((float)(v36->currentState.position.x * axis->mat[0].x)
                          + (float)((float)(axis->mat[1].x * v36->currentState.position.y)
                                  + (float)(axis->mat[2].x * v36->currentState.position.z))));
      v36->currentState.position.x = origin->x
                                   + (float)((float)(v36->currentState.position.x * axis->mat[0].x)
                                           + (float)((float)(axis->mat[1].x * v36->currentState.position.y)
                                                   + (float)(axis->mat[2].x * v36->currentState.position.z)));
      v50 = (float)((float)v47 + (float)v45);
      v36->currentState.position.y = (float)v47 + (float)v45;
      v51 = (float)((float)v48 + (float)v46);
      v36->currentState.position.z = (float)v48 + (float)v46;
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v36->properties->broadPhase,
        object: &v36->SPObject,
        origin: &v36->currentState.position,
        axis: &v36->currentState.orientation,
        bounds: nullptr);
      v52 = idMat3::operator*(this: v74, result: &v36->currentState.orientation, a: axis);
      idEffectPhysicsRigidBody::SetOrientation(this: v36, m: v52);
      v36->active = true;
      v36->SPObject.motion.ignore = false;
      v53 = (float)((float)v51 - origin->z);
      v54 = (float)((float)v50 - origin->y);
      *(float *)&v57.particle = (float)v49 - origin->x;
      v57.pos.x = v54;
      v57.pos.y = v53;
      idVec3::NormalizeFast(this: (idVec3 *)&v57);
      if ( (float)((float)(*(float *)&v57.particle * (float)v27)
                 + (float)((float)(v57.pos.y * (float)v29) + (float)(v57.pos.x * (float)v28))) < 0.0 )
      {
        v58.x = (float)(v57.pos.y * (float)v28) - (float)(v57.pos.x * (float)v29);
        v58.y = (float)((float)v29 * *(float *)&v57.particle) - (float)(v57.pos.y * (float)v27);
        v58.z = (float)(v57.pos.x * (float)v27) - (float)(*(float *)&v57.particle * (float)v28);
        idVec3::NormalizeFast(this: &v58);
      }
LABEL_15:
      v67.x = (float)((float)(v58.x * (float)10.0) + (float)(g_breakableRayUpPercent.valueFloat * vec3_up.x))
            * (float)v26;
      v67.y = (float)((float)(v58.y * (float)10.0) + (float)(vec3_up.y * g_breakableRayUpPercent.valueFloat))
            * (float)v26;
      v67.z = (float)((float)(v58.z * (float)10.0) + (float)(vec3_up.z * g_breakableRayUpPercent.valueFloat))
            * (float)v26;
      idEffectPhysicsRigidBody::ApplyImpulse(this: v36, point: start, impulse: &v67);
      goto LABEL_16;
    }
  }
}


// ========================================================================
// ??0idEffectPhysicsBreakable@@QAA@XZ
// EA  : 0x826FF7C8
// RVA : 0x006FF7C8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

idEffectPhysicsBreakable *__fastcall idEffectPhysicsBreakable::idEffectPhysicsBreakable(idEffectPhysicsBreakable *this)
{
  this->properties.list = nullptr;
  this->properties.granularity = 0;
  this->properties.memTag = 59;
  this->properties.listStatic = 0;
  this->properties.size = 0;
  this->properties.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->rigidBodies.list = nullptr;
  this->rigidBodies.granularity = 0;
  this->rigidBodies.memTag = 59;
  this->rigidBodies.listStatic = 0;
  this->rigidBodies.size = 0;
  this->rigidBodies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rigidBodies);
  this->collisions.list = nullptr;
  this->collisions.granularity = 0;
  this->collisions.memTag = 59;
  this->collisions.listStatic = 0;
  this->collisions.size = 0;
  this->collisions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collisions);
  this->basePiece = nullptr;
  this->explosions.granularity = 0;
  this->explosions.memTag = 59;
  this->explosions.listStatic = 0;
  this->explosions.list = nullptr;
  this->explosions.size = 0;
  this->explosions.num = 0;
  this->explosionFX.granularity = 0;
  this->explosionFX.memTag = 59;
  this->explosionFX.listStatic = 0;
  this->explosionFX.list = nullptr;
  this->explosionFX.size = 0;
  this->explosionFX.num = 0;
  this->trails.granularity = 0;
  this->trails.memTag = 59;
  this->trails.listStatic = 0;
  this->trails.list = nullptr;
  this->trails.size = 0;
  this->trails.num = 0;
  this->damage.list = nullptr;
  this->damage.granularity = 0;
  this->damage.memTag = 59;
  this->damage.listStatic = 0;
  this->damage.size = 0;
  this->damage.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->damage);
  this->particles.list = nullptr;
  this->particles.granularity = 0;
  this->particles.memTag = 59;
  this->particles.listStatic = 0;
  this->particles.size = 0;
  this->particles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->particles);
  this->decals.granularity = 0;
  this->decals.memTag = 59;
  this->decals.listStatic = 0;
  this->decals.list = nullptr;
  this->decals.size = 0;
  this->decals.num = 0;
  this->sparks.list = nullptr;
  this->sparks.granularity = 0;
  this->sparks.memTag = 59;
  this->sparks.listStatic = 0;
  this->sparks.size = 0;
  this->sparks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sparks);
  this->pieceActivationTimes.list = nullptr;
  this->pieceActivationTimes.granularity = 0;
  this->pieceActivationTimes.memTag = 5;
  this->pieceActivationTimes.listStatic = 0;
  this->pieceActivationTimes.size = 0;
  this->pieceActivationTimes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pieceActivationTimes);
  idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase(this: &this->broadPhase);
  this->random.seed = 0;
  this->gameLibEffects = nullptr;
  this->model = nullptr;
  this->decl = nullptr;
  this->soundInfo.minBounceVelSqr = 0.0;
  this->soundInfo.soundWorld = nullptr;
  this->soundInfo.emitter = nullptr;
  this->soundInfo.channel = SND_CHANNEL_ANY;
  this->soundInfo.nextSoundTime = 0;
  return this;
}


// ========================================================================
// __unwind$258966
// EA  : 0x826FF99C
// RVA : 0x006FF99C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258966()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$258967
// EA  : 0x826FF9C4
// RVA : 0x006FF9C4
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258967()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$258968
// EA  : 0x826FF9F0
// RVA : 0x006FF9F0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258968()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$258969
// EA  : 0x826FFA1C
// RVA : 0x006FFA1C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258969()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idExplosion,59>::~idList<idEffectPhysicsBreakable::idExplosion,59>(this: (idList<idEffectPhysicsBreakable::idExplosion,59> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$258970
// EA  : 0x826FFA48
// RVA : 0x006FFA48
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258970()
{
  int v0; // r12

  idList<idFXManager,59>::Clear(this: (idList<idFXManager,59> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$258971_0
// EA  : 0x826FFA74
// RVA : 0x006FFA74
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258971_0()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idTrail,59>::~idList<idEffectPhysicsBreakable::idTrail,59>(this: (idList<idEffectPhysicsBreakable::idTrail,59> *)(*(_DWORD *)(v0 - 128 + 148) + 84));
}


// ========================================================================
// __unwind$258972_0
// EA  : 0x826FFAA0
// RVA : 0x006FFAA0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258972_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 100));
}


// ========================================================================
// __unwind$258973_0
// EA  : 0x826FFACC
// RVA : 0x006FFACC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258973_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 116));
}


// ========================================================================
// __unwind$258974_0
// EA  : 0x826FFAF8
// RVA : 0x006FFAF8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258974_0()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idDecalFX,59>::Clear(this: (idList<idEffectPhysicsBreakable::idDecalFX,59> *)(*(_DWORD *)(v0 - 128 + 148) + 132));
}


// ========================================================================
// __unwind$258975_0
// EA  : 0x826FFB24
// RVA : 0x006FFB24
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258975_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 148));
}


// ========================================================================
// __unwind$258976_0
// EA  : 0x826FFB50
// RVA : 0x006FFB50
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_258976_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ??1idEffectPhysicsBreakable@@QAA@XZ
// EA  : 0x826FFB88
// RVA : 0x006FFB88
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::~idEffectPhysicsBreakable(idEffectPhysicsBreakable *this)
{
  idRenderModelDiscreteAnimation *model; // r11
  int v3; // r28
  int v4; // r29
  idRenderModelDiscreteAnimation *v5; // r3
  idList<idEffectPhysicsRigidBody *,59> *p_rigidBodies; // r29
  int *list; // r4
  idEffectPhysicsBreakable::idSpark *v8; // r4
  idEffectPhysicsBreakable::idDecalFX *v9; // r3
  idEffectPhysicsBreakable::idBreakableParticle *v10; // r4
  float *v11; // r4
  idEffectPhysicsBreakable::idTrail *v12; // r3
  idFXManager *v13; // r3
  char *v14; // r3
  idEffectPhysicsCollision *v15; // r4

  model = this->model;
  if ( model != nullptr )
  {
    v3 = 0;
    if ( model->modelData->traceModels.num > 0 )
    {
      v4 = 0;
      do
      {
        idTraceModelCache::FreeTraceModel(
          this: this->broadPhase.traceModelCache,
          traceModelIndex: this->rigidBodies.list[v4]->properties->traceModelIndex);
        ++v3;
        ++v4;
      }
      while ( v3 < this->model->modelData->traceModels.num );
    }
    v5 = this->model;
    v5->unlinked = true;
    v5->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: v5);
  }
  p_rigidBodies = &this->rigidBodies;
  idList<idEffectPhysicsRigidBody *,59>::DeleteContents(this: &this->rigidBodies);
  idList<idEffectPhysicsProperties *,59>::DeleteContents(this: &this->properties);
  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: &this->broadPhase);
  if ( this->pieceActivationTimes.listStatic == 0 || this->pieceActivationTimes.listStatic == 2 )
  {
    list = this->pieceActivationTimes.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->pieceActivationTimes.list = nullptr;
    this->pieceActivationTimes.size = 0;
  }
  this->pieceActivationTimes.num = 0;
  if ( this->sparks.listStatic == 0 || this->sparks.listStatic == 2 )
  {
    v8 = this->sparks.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->sparks.list = nullptr;
    this->sparks.size = 0;
  }
  this->sparks.num = 0;
  if ( this->decals.listStatic == 0 || this->decals.listStatic == 2 )
  {
    v9 = this->decals.list;
    if ( v9 != nullptr )
      idListArrayDelete<idEffectPhysicsBreakable::idDecalFX>(ptr: v9, num: this->decals.size);
    this->decals.list = nullptr;
    this->decals.size = 0;
  }
  this->decals.num = 0;
  if ( this->particles.listStatic == 0 || this->particles.listStatic == 2 )
  {
    v10 = this->particles.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->particles.list = nullptr;
    this->particles.size = 0;
  }
  this->particles.num = 0;
  if ( this->damage.listStatic == 0 || this->damage.listStatic == 2 )
  {
    v11 = this->damage.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->damage.list = nullptr;
    this->damage.size = 0;
  }
  this->damage.num = 0;
  if ( this->trails.listStatic == 0 || this->trails.listStatic == 2 )
  {
    v12 = this->trails.list;
    if ( v12 != nullptr )
      idListArrayDelete<idEffectPhysicsBreakable::idTrail>(ptr: v12, num: this->trails.size);
    this->trails.list = nullptr;
    this->trails.size = 0;
  }
  this->trails.num = 0;
  if ( this->explosionFX.listStatic == 0 || this->explosionFX.listStatic == 2 )
  {
    v13 = this->explosionFX.list;
    if ( v13 != nullptr )
      idListArrayDelete<idFXManager>(ptr: v13, num: this->explosionFX.size);
    this->explosionFX.list = nullptr;
    this->explosionFX.size = 0;
  }
  this->explosionFX.num = 0;
  if ( this->explosions.listStatic == 0 || this->explosions.listStatic == 2 )
  {
    v14 = (char *)this->explosions.list;
    if ( v14 != nullptr )
      idListArrayDelete<idEffectPhysicsBreakable::idExplosion>(ptr: v14, num: this->explosions.size);
    this->explosions.list = nullptr;
    this->explosions.size = 0;
  }
  this->explosions.num = 0;
  if ( this->collisions.listStatic == 0 || this->collisions.listStatic == 2 )
  {
    v15 = this->collisions.list;
    if ( v15 != nullptr )
      idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
    this->collisions.list = nullptr;
    this->collisions.size = 0;
  }
  this->collisions.num = 0;
  if ( this->rigidBodies.listStatic == 0 || this->rigidBodies.listStatic == 2 )
  {
    if ( p_rigidBodies->list != nullptr )
      idMem::Free(this: &mem, ptr: p_rigidBodies->list, align: ALIGN_16);
    p_rigidBodies->list = nullptr;
    this->rigidBodies.size = 0;
  }
  this->rigidBodies.num = 0;
  if ( this->properties.listStatic == 0 || this->properties.listStatic == 2 )
  {
    if ( this->properties.list != nullptr )
      idMem::Free(this: &mem, ptr: this->properties.list, align: ALIGN_16);
    this->properties.list = nullptr;
    this->properties.size = 0;
  }
  this->properties.num = 0;
}


// ========================================================================
// __unwind$259135
// EA  : 0x826FFEB0
// RVA : 0x006FFEB0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259135()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$259136
// EA  : 0x826FFED8
// RVA : 0x006FFED8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259136()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// __unwind$259137
// EA  : 0x826FFF04
// RVA : 0x006FFF04
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259137()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 32));
}


// ========================================================================
// __unwind$259138
// EA  : 0x826FFF30
// RVA : 0x006FFF30
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259138()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idExplosion,59>::~idList<idEffectPhysicsBreakable::idExplosion,59>(this: (idList<idEffectPhysicsBreakable::idExplosion,59> *)(*(_DWORD *)(v0 - 144 + 164) + 52));
}


// ========================================================================
// __unwind$259139
// EA  : 0x826FFF5C
// RVA : 0x006FFF5C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259139()
{
  int v0; // r12

  idList<idFXManager,59>::Clear(this: (idList<idFXManager,59> *)(*(_DWORD *)(v0 - 144 + 164) + 68));
}


// ========================================================================
// __unwind$259140
// EA  : 0x826FFF88
// RVA : 0x006FFF88
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259140()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idTrail,59>::~idList<idEffectPhysicsBreakable::idTrail,59>(this: (idList<idEffectPhysicsBreakable::idTrail,59> *)(*(_DWORD *)(v0 - 144 + 164) + 84));
}


// ========================================================================
// __unwind$259141
// EA  : 0x826FFFB4
// RVA : 0x006FFFB4
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259141()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 100));
}


// ========================================================================
// __unwind$259142
// EA  : 0x826FFFE0
// RVA : 0x006FFFE0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259142()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 116));
}


// ========================================================================
// __unwind$259143
// EA  : 0x8270000C
// RVA : 0x0070000C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259143()
{
  int v0; // r12

  idList<idEffectPhysicsBreakable::idDecalFX,59>::Clear(this: (idList<idEffectPhysicsBreakable::idDecalFX,59> *)(*(_DWORD *)(v0 - 144 + 164) + 132));
}


// ========================================================================
// __unwind$259144
// EA  : 0x82700038
// RVA : 0x00700038
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259144()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 148));
}


// ========================================================================
// __unwind$259145
// EA  : 0x82700064
// RVA : 0x00700064
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259145()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 164));
}


// ========================================================================
// __unwind$259146
// EA  : 0x82700090
// RVA : 0x00700090
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_259146()
{
  int v0; // r12

  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: (idEffectPhysicsBroadPhase *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                          + 180));
}


// ========================================================================
// ?AddExplosion@idEffectPhysicsBreakable@@QAAXPBVidDeclParticle@@HABVidVec3@@MMMMHH_NHM212@Z
// EA  : 0x82700138
// RVA : 0x00700138
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::AddExplosion(
        idEffectPhysicsBreakable *this,
        const idDeclParticle *particle,
        int time,
        const idVec3 *position,
        double radius,
        double impulse,
        double falloff,
        double angular,
        const int delay,
        const int duration,
        const bool startNow,
        const int activateAllDelay,
        double distTimeScaleDelay,
        const bool useLinear,
        const idVec3 *endLinear,
        const bool localSpace,
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
        int a34,
        int a35,
        int a36,
        char a37,
        int a38,
        int a39,
        int a40,
        int delay_0,
        int a42,
        bool duration_0_3,
        int a44,
        float *a45,
        int a46,
        bool activateAllDelay_0_3)
{
  idEffectPhysicsBreakable::idExplosion *v56; // r3
  idEffectPhysicsBreakable::idExplosion *v57; // r31
  idList<int,59> *p_pieces; // r28
  int num; // r30
  int size; // r11
  int v61; // r11
  int v62; // r10

  v56 = idList<idEffectPhysicsBreakable::idExplosion,59>::Alloc(this: &this->explosions);
  v56->decl.particle = particle;
  v56->decl.fx = nullptr;
  v56->decl.position = *position;
  v57 = v56;
  p_pieces = &v56->decl.pieces;
  v56->decl.delay = a33;
  v56->decl.duration = a35;
  v56->decl.radius = radius;
  v56->decl.impulse = (float)impulse * (float)10.0;
  v56->decl.falloff = falloff;
  v56->decl.angular = angular;
  num = this->rigidBodies.num;
  if ( num <= v56->decl.pieces.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v56->decl.pieces,
         newsize: this->rigidBodies.num) )
  {
    size = p_pieces->size;
    if ( num < size )
      size = num;
    p_pieces->num = size;
  }
  v57->decl.distTimeScaleDelay = distTimeScaleDelay;
  v61 = 0;
  v57->decl.activateAllDelay = a39;
  v57->decl.useLinear = duration_0_3;
  v57->decl.endLinear.x = *a45;
  v57->decl.endLinear.y = a45[1];
  v57->decl.endLinear.z = a45[2];
  if ( this->rigidBodies.num > 0 )
  {
    v62 = 0;
    do
      p_pieces->list[v62++] = v61++;
    while ( v61 < this->rigidBodies.num );
  }
  v57->localSpace = activateAllDelay_0_3;
  v57->startTime = a37 == 0 ? 0 : time;
  v57->worldPosition.x = position->x;
  v57->worldPosition.y = position->y;
  v57->worldPosition.z = position->z;
  v57->effectsEnabled = false;
  v57->forceApplied = false;
  v57->fxIndex = -1;
}


// ========================================================================
// ?InitExplosionsAndTrails@idEffectPhysicsBreakable@@AAAXPAUbreakablePieceSound_t@1@PAVidGameLibEffects@@M@Z
// EA  : 0x82700380
// RVA : 0x00700380
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::InitExplosionsAndTrails(
        idEffectPhysicsBreakable *this,
        idEffectPhysicsBreakable::breakablePieceSound_t *soundInfo,
        idGameLibEffects *gameLibEffects,
        double diversity)
{
  idRenderModelDiscreteAnimation *model; // r3
  idList<idEffectPhysicsBreakable::idExplosion,59> *p_explosions; // r29
  idRenderWorld *World; // r24
  idEffectPhysicsBreakable::idExplosion *v11; // r8
  int v12; // r28
  int v13; // r30
  int v14; // r27
  float *v15; // r11
  const idDeclBreakable *decl; // r11
  int num; // r30
  int size; // r11
  int v19; // r30
  int v20; // r28
  int v21; // r27
  const idDeclFX *fx; // r4
  idEffectPhysicsBreakable::idExplosion *v23; // r11
  const idDeclBreakable *v24; // r11
  idList<idEffectPhysicsBreakable::idTrail,59> *p_trails; // r29
  int v26; // r30
  int v27; // r11
  int v28; // r25
  int v29; // r28
  int v30; // r30
  idEffectPhysicsBreakable::idTrail *v31; // r11
  idBreakableTrail *list; // r10
  idList<int,59> *p_pieceStartTime; // r26
  int v34; // r27
  int v35; // r11
  idEffectPhysicsBreakable::idTrail *v36; // r11
  idBreakableTrail *v37; // r10
  idList<idVec3,59> *p_pieceLastParticleDropPos; // r26
  int v39; // r27
  int v40; // r11
  int v41; // r8
  int v42; // r9
  int v43; // r10
  float *p_x; // r11
  const idDeclBreakable *v45; // r11
  idList<idEffectPhysicsBreakable::idDecalFX,59> *p_decals; // r29
  int v47; // r30
  int v48; // r11
  int v49; // r25
  int v50; // r28
  int v51; // r30
  idEffectPhysicsBreakable::idDecalFX *v52; // r11
  idBreakableDecal *v53; // r10
  idList<int,59> *v54; // r26
  int v55; // r27
  int v56; // r11
  idEffectPhysicsBreakable::idDecalFX *v57; // r11
  idBreakableDecal *v58; // r10
  idList<idVec3,59> *p_pieceLastDecalDropPos; // r26
  int v60; // r27
  int v61; // r11
  idEffectPhysicsBreakable::idDecalFX *v62; // r11
  idBreakableDecal *v63; // r10
  idList<idVec3,59> *p_lastCollisionPos; // r26
  int v65; // r27
  int v66; // r11
  idEffectPhysicsBreakable::idDecalFX *v67; // r11
  idBreakableDecal *v68; // r10
  idList<idVec3,59> *p_lastCollisionNormal; // r26
  int v70; // r27
  int v71; // r11
  int v72; // r8
  int v73; // r11
  int v74; // r9
  float *v75; // r10
  float *v76; // r10
  float *v77; // r10
  int v78; // r29
  idList<idEffectPhysicsBreakable::idSpark,59> *p_sparks; // r30
  int v80; // r11
  idGame *v81; // r3
  __int64 v82; // r4
  int v83; // r6
  int v84; // r7
  __int64 v85; // r10
  const idDeclBreakable *v86; // r8
  double sizeMin; // fp13
  int v88; // r5
  const idDeclBreakable *v89; // r8
  double v90; // fp9
  signed int v91; // r8
  int v92; // r6
  fxEmitterSound_t v93[3]; // [sp+50h] [-80h] BYREF

  if ( this->decl != nullptr )
  {
    model = this->model;
    if ( model != nullptr )
    {
      p_explosions = &this->explosions;
      World = idRenderModel::GetWorld(this: model);
      idList<idEffectPhysicsBreakable::idExplosion,59>::SetNum(
        this: &this->explosions,
        newNum: this->decl->explosions.num);
      v12 = 0;
      if ( this->decl->explosions.num > 0 )
      {
        v13 = 0;
        v14 = 0;
        do
        {
          idBreakableExplosion::operator=(
            this: &p_explosions->list[v13].decl,
            __that: &this->decl->explosions.list[v14]);
          ++v12;
          ++v14;
          p_explosions->list[v13].startTime = 0;
          v15 = (float *)&p_explosions->list[v13];
          v15[23] = v15[2];
          v15[24] = v15[3];
          v15[25] = v15[4];
          v11 = &p_explosions->list[v13];
          v11->effectsEnabled = false;
          p_explosions->list[v13].forceApplied = false;
          p_explosions->list[v13].localSpace = true;
          p_explosions->list[v13++].fxIndex = -1;
        }
        while ( v12 < this->decl->explosions.num );
      }
      decl = this->decl;
      num = decl->explosions.num;
      if ( num <= this->explosionFX.size
        || (unsigned __int8)idList<idFXManager,59>::Resize(this: &this->explosionFX, newsize: decl->explosions.num) != 0 )
      {
        size = this->explosionFX.size;
        if ( num < size )
          size = num;
        this->explosionFX.num = size;
      }
      v19 = 0;
      if ( this->explosionFX.num > 0 )
      {
        v20 = 0;
        v21 = 0;
        do
        {
          fx = p_explosions->list[v20].decl.fx;
          if ( soundInfo != nullptr )
          {
            v93[0] = *(fxEmitterSound_t *)&soundInfo->emitter;
          }
          else
          {
            v93[0].emitter = nullptr;
            v93[0].channel = SND_CHANNEL_FX;
          }
          idFXManager::Init(
            this: &this->explosionFX.list[v21++],
            declFX: fx,
            _rw: World,
            _soundInfo: v93,
            _gameLibEffects: gameLibEffects,
            diversity,
            _ta: (idTreeAnimator *)v11);
          v23 = &p_explosions->list[v20++];
          v23->fxIndex = v19++;
        }
        while ( v19 < this->explosionFX.num );
      }
      v24 = this->decl;
      p_trails = &this->trails;
      v26 = v24->trails.num;
      if ( v26 <= this->trails.size
        || (unsigned __int8)idList<idEffectPhysicsBreakable::idTrail,59>::Resize(
                              this: &this->trails,
                              newsize: v24->trails.num) != 0 )
      {
        v27 = this->trails.size;
        if ( v26 < v27 )
          v27 = v26;
        this->trails.num = v27;
      }
      v28 = 0;
      if ( this->decl->trails.num > 0 )
      {
        v29 = 0;
        v30 = 0;
        do
        {
          idBreakableTrail::operator=(this: &p_trails->list[v30].decl, __that: &this->decl->trails.list[v29]);
          v31 = &p_trails->list[v30];
          list = this->decl->trails.list;
          p_pieceStartTime = &v31->pieceStartTime;
          v34 = list[v29].pieces.num;
          if ( v34 <= v31->pieceStartTime.size
            || idList<idNavSpline *,5>::Resize(
                 this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v31->pieceStartTime,
                 newsize: list[v29].pieces.num) )
          {
            v35 = p_pieceStartTime->size;
            if ( v34 < v35 )
              v35 = v34;
            p_pieceStartTime->num = v35;
          }
          v36 = &p_trails->list[v30];
          v37 = this->decl->trails.list;
          p_pieceLastParticleDropPos = &v36->pieceLastParticleDropPos;
          v39 = v37[v29].pieces.num;
          if ( v39 <= v36->pieceLastParticleDropPos.size
            || idList<idVec3,59>::Resize(
                 this: (idList<idVec3,5> *)&v36->pieceLastParticleDropPos,
                 newsize: v37[v29].pieces.num) )
          {
            v40 = p_pieceLastParticleDropPos->size;
            if ( v39 < v40 )
              v40 = v39;
            p_pieceLastParticleDropPos->num = v40;
          }
          v41 = 0;
          if ( this->decl->trails.list[v29].pieces.num > 0 )
          {
            v42 = 0;
            v43 = 0;
            do
            {
              ++v41;
              p_trails->list[v30].pieceStartTime.list[v43++] = 0;
              p_x = &p_trails->list[v30].pieceLastParticleDropPos.list[v42].x;
              p_x[2] = 0.0;
              ++v42;
              p_x[1] = 0.0;
              *p_x = 0.0;
            }
            while ( v41 < this->decl->trails.list[v29].pieces.num );
          }
          ++v28;
          ++v30;
          ++v29;
        }
        while ( v28 < this->decl->trails.num );
      }
      v45 = this->decl;
      p_decals = &this->decals;
      v47 = v45->decals.num;
      if ( v47 <= this->decals.size
        || (unsigned __int8)idList<idEffectPhysicsBreakable::idDecalFX,59>::Resize(
                              this: &this->decals,
                              newsize: v45->decals.num) != 0 )
      {
        v48 = this->decals.size;
        if ( v47 < v48 )
          v48 = v47;
        this->decals.num = v48;
      }
      v49 = 0;
      if ( this->decl->decals.num > 0 )
      {
        v50 = 0;
        v51 = 0;
        do
        {
          idBreakableDecal::operator=(
            this: &p_decals->list[v51].decl,
            __that: (const idList<idMD6Node *,5> *)&this->decl->decals.list[v50]);
          v52 = &p_decals->list[v51];
          v53 = this->decl->decals.list;
          v54 = &v52->pieceStartTime;
          v55 = v53[v50].pieces.num;
          if ( v55 <= v52->pieceStartTime.size
            || idList<idNavSpline *,5>::Resize(
                 this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v52->pieceStartTime,
                 newsize: v53[v50].pieces.num) )
          {
            v56 = v54->size;
            if ( v55 < v56 )
              v56 = v55;
            v54->num = v56;
          }
          v57 = &p_decals->list[v51];
          v58 = this->decl->decals.list;
          p_pieceLastDecalDropPos = &v57->pieceLastDecalDropPos;
          v60 = v58[v50].pieces.num;
          if ( v60 <= v57->pieceLastDecalDropPos.size
            || idList<idVec3,59>::Resize(
                 this: (idList<idVec3,5> *)&v57->pieceLastDecalDropPos,
                 newsize: v58[v50].pieces.num) )
          {
            v61 = p_pieceLastDecalDropPos->size;
            if ( v60 < v61 )
              v61 = v60;
            p_pieceLastDecalDropPos->num = v61;
          }
          v62 = &p_decals->list[v51];
          v63 = this->decl->decals.list;
          p_lastCollisionPos = &v62->lastCollisionPos;
          v65 = v63[v50].pieces.num;
          if ( v65 <= v62->lastCollisionPos.size
            || idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&v62->lastCollisionPos, newsize: v63[v50].pieces.num) )
          {
            v66 = p_lastCollisionPos->size;
            if ( v65 < v66 )
              v66 = v65;
            p_lastCollisionPos->num = v66;
          }
          v67 = &p_decals->list[v51];
          v68 = this->decl->decals.list;
          p_lastCollisionNormal = &v67->lastCollisionNormal;
          v70 = v68[v50].pieces.num;
          if ( v70 <= v67->lastCollisionNormal.size
            || idList<idVec3,59>::Resize(
                 this: (idList<idVec3,5> *)&v67->lastCollisionNormal,
                 newsize: v68[v50].pieces.num) )
          {
            v71 = p_lastCollisionNormal->size;
            if ( v70 < v71 )
              v71 = v70;
            p_lastCollisionNormal->num = v71;
          }
          v72 = 0;
          if ( this->decl->decals.list[v50].pieces.num > 0 )
          {
            v73 = 0;
            v74 = 0;
            do
            {
              ++v72;
              p_decals->list[v51].pieceStartTime.list[v74++] = 0;
              v75 = &p_decals->list[v51].pieceLastDecalDropPos.list[v73].x;
              v75[1] = 0.0;
              *v75 = 0.0;
              v75[2] = 0.0;
              v76 = &p_decals->list[v51].lastCollisionPos.list[v73].x;
              v76[1] = 0.0;
              *v76 = 0.0;
              v76[2] = 0.0;
              v77 = &p_decals->list[v51].lastCollisionNormal.list[v73].x;
              v77[2] = 0.0;
              ++v73;
              v77[1] = 0.0;
              *v77 = 0.0;
            }
            while ( v72 < this->decl->decals.list[v50].pieces.num );
          }
          ++v49;
          ++v51;
          ++v50;
        }
        while ( v49 < this->decl->decals.num );
      }
      if ( this->decl->sparks.materials.num > 0 )
      {
        v78 = this->rigidBodies.num;
        p_sparks = &this->sparks;
        if ( v78 <= this->sparks.size
          || (unsigned __int8)idList<idEffectPhysicsBreakable::idSpark,59>::Resize(
                                this: &this->sparks,
                                newsize: this->rigidBodies.num) != 0 )
        {
          v80 = this->sparks.size;
          if ( v78 < v80 )
            v80 = v78;
          this->sparks.num = v80;
        }
        v81 = common->Game(this: common);
        HIDWORD(v82) = v81->GetGameFrame(this: v81);
        v83 = this->sparks.num;
        v84 = 0;
        this->random.seed = HIDWORD(v82);
        if ( v83 > 0 )
        {
          HIDWORD(v85) = 0;
          do
          {
            v86 = this->decl;
            LODWORD(v85) = 1103515245 * this->random.seed + 12345;
            this->random.seed = v85;
            LODWORD(v82) = this->decl;
            sizeMin = v86->sparks.sizeMin;
            v88 = (int)p_sparks->list + HIDWORD(v85);
            LODWORD(v85) = ((int)v85 >> 16) & 0x7FFF;
            v93[1] = (fxEmitterSound_t)v85;
            *(float *)(v88 + 8) = (float)((float)((float)(*(float *)(v82 + 264) - *(float *)(v82 + 260)) * (float)v85)
                                        * (float)0.000030518509)
                                + (float)sizeMin;
            v89 = this->decl;
            LODWORD(v85) = 1103515245 * this->random.seed + 12345;
            this->random.seed = v85;
            LODWORD(v82) = ((int)v85 >> 16) & 0x7FFF;
            v93[2] = (fxEmitterSound_t)v82;
            v90 = (float)((float)((float)((float)(this->decl->sparks.velocityScaleMax
                                                - this->decl->sparks.velocityScaleMin)
                                        * (float)v82)
                                * (float)0.000030518509)
                        + v89->sparks.velocityScaleMin);
            HIDWORD(v82) = (char *)p_sparks->list + HIDWORD(v85);
            *(float *)(HIDWORD(v82) + 4) = v90;
            LODWORD(v85) = this->decl;
            v91 = *(_DWORD *)(v85 + 248);
            if ( v91 <= 1 )
            {
              *(const idMaterial **)((char *)&p_sparks->list->material + HIDWORD(v85)) = **(const idMaterial ***)(v85 + 244);
            }
            else
            {
              v92 = *(_DWORD *)(v85 + 248);
              LODWORD(v85) = 1103515245 * this->random.seed + 12345;
              __twllei(v91, 0);
              this->random.seed = v85;
              LODWORD(v82) = ((int)v85 >> 16) & 0x7FFF;
              __twlgei(v92 & ~(__ROL4__(v82, 1) - 1), 0xFFFFFFFF);
              HIDWORD(v82) = this->decl->sparks.materials.list[(int)v82 % v92];
              *(const idMaterial **)((char *)&p_sparks->list->material + HIDWORD(v85)) = (const idMaterial *)HIDWORD(v82);
            }
            ++v84;
            HIDWORD(v85) += 12;
          }
          while ( v84 < this->sparks.num );
        }
      }
    }
  }
}


// ========================================================================
// ?Reset@idEffectPhysicsBreakable@@QAAX_N@Z
// EA  : 0x82700B98
// RVA : 0x00700B98
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::Reset(idEffectPhysicsBreakable *this, bool skipModelReset)
{
  idRenderModelDiscreteAnimation *model; // r3
  int num; // r11
  int v5; // r27
  int v6; // r28
  int v7; // r30
  idEffectPhysicsRigidBody *v8; // r11
  idEffectPhysicsBroadPhase **p_broadPhase; // r8
  idEffectPhysicsBroadPhase *v10; // r3
  idEffectPhysicsRigidBody *v11; // r11
  idEffectPhysicsBroadPhase **v12; // r3
  idEffectPhysicsBroadPhase *v13; // r3
  double y; // fp13
  double z; // fp12
  idEffectPhysicsRigidBody *v16; // r10
  double mass; // fp2
  idEffectPhysicsRigidBody *v18; // r7
  double v19; // fp6
  double x; // fp0
  double v21; // fp10
  double v22; // fp1
  double v23; // fp12
  int i; // r9
  const idDeclBreakable *decl; // r10
  idEffectPhysicsProperties *v26; // r11
  const idDeclBreakable *v27; // r10
  __int64 v28; // r11
  int v29; // r11
  idVec3 v30; // [sp+58h] [-78h] BYREF
  idMat3 v31; // [sp+70h] [-60h] BYREF

  model = this->model;
  if ( model != nullptr )
  {
    if ( !skipModelReset )
      idRenderModelDiscreteAnimation::Reset(this: model);
    num = this->rigidBodies.num;
    v5 = 0;
    v6 = 0;
    this->random.seed = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        idRenderModelDiscreteAnimation::GetPiecePosition(
          this: this->model,
          index: v6,
          position: &v30,
          orientation: &v31);
        this->rigidBodies.list[v7]->active = false;
        v8 = this->rigidBodies.list[v7];
        v8->currentState.position.x = v30.x;
        p_broadPhase = &v8->properties->broadPhase;
        v8->currentState.position.y = v30.y;
        v10 = *p_broadPhase;
        v8->currentState.position.z = v30.z;
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v10,
          object: &v8->SPObject,
          origin: &v8->currentState.position,
          axis: &v8->currentState.orientation,
          bounds: nullptr);
        v11 = this->rigidBodies.list[v7];
        v11->currentState.orientation.mat[0].x = v31.mat[0].x;
        v12 = &v11->properties->broadPhase;
        v11->currentState.orientation.mat[0].y = v31.mat[0].y;
        v13 = *v12;
        v11->currentState.orientation.mat[0].z = v31.mat[0].z;
        v11->currentState.orientation.mat[1] = v31.mat[1];
        v11->currentState.orientation.mat[2] = v31.mat[2];
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v13,
          object: &v11->SPObject,
          origin: &v11->currentState.position,
          axis: &v11->currentState.orientation,
          bounds: nullptr);
        ++v6;
        y = vec3_origin.y;
        z = vec3_origin.z;
        v16 = this->rigidBodies.list[v7];
        mass = v16->properties->mass;
        v16->currentState.linearMomentum.x = vec3_origin.x * v16->properties->mass;
        v16->currentState.linearMomentum.y = (float)y * (float)mass;
        v16->currentState.linearMomentum.z = (float)z * (float)mass;
        v18 = this->rigidBodies.list[v7++];
        v19 = v18->properties->inertiaTensor.mat[0].y;
        x = vec3_origin.x;
        v21 = (float)((float)(v18->properties->inertiaTensor.mat[1].z * vec3_origin.y)
                    + (float)(v18->properties->inertiaTensor.mat[2].z * vec3_origin.z));
        v22 = v18->properties->inertiaTensor.mat[0].z;
        v23 = (float)((float)(v18->properties->inertiaTensor.mat[1].y * vec3_origin.y)
                    + (float)(v18->properties->inertiaTensor.mat[2].y * vec3_origin.z));
        v18->currentState.angularMomentum.x = (float)(v18->properties->inertiaTensor.mat[0].x * vec3_origin.x)
                                            + (float)((float)(v18->properties->inertiaTensor.mat[1].x * vec3_origin.y)
                                                    + (float)(v18->properties->inertiaTensor.mat[2].x * vec3_origin.z));
        v18->currentState.angularMomentum.z = (float)((float)v22 * (float)x) + (float)v21;
        v18->currentState.angularMomentum.y = (float)((float)v19 * (float)x) + (float)v23;
      }
      while ( v6 < this->rigidBodies.num );
    }
    for ( i = 0; i < this->properties.num; ++v5 )
    {
      decl = this->decl;
      v26 = this->properties.list[v5];
      if ( decl != nullptr )
      {
        v26->linearFriction = decl->settings.linearFriction;
        v26->angularFriction = this->decl->settings.angularFriction;
        v26->contactFriction = this->decl->settings.contactFriction;
        v26->linearFrictionWater = this->decl->settings.linearFrictionWater;
        v26->angularFrictionWater = this->decl->settings.angularFrictionWater;
        v26->bouncyness = this->decl->settings.bouncyness;
        v27 = this->decl;
        v26->gravityVector.x = v27->settings.gravityVector.x;
        v26->gravityVector.y = v27->settings.gravityVector.y;
        v26->gravityVector.z = v27->settings.gravityVector.z;
        v26->worldCollisionOnly = this->decl->settings.worldCollisionOnly;
        v26->clipMask = this->decl->settings.clipMask;
      }
      ++i;
    }
    HIDWORD(v28) = this->random.seed;
    v29 = 1103515245 * HIDWORD(v28) + 12345;
    this->random.seed = v29;
    LODWORD(v28) = (v29 >> 16) & 0x7FFF;
    idEffectPhysicsBreakable::InitExplosionsAndTrails(
      this,
      soundInfo: &this->soundInfo,
      gameLibEffects: this->gameLibEffects,
      diversity: (float)((float)v28 * (float)0.000030518509));
  }
}


// ========================================================================
// ?Init@idEffectPhysicsBreakable@@QAAXPAVidClip@@PAVidTraceModelCache@@PAVidGameLibEffects@@PAVidRenderModelDiscreteAnimation@@HPAUbreakablePieceSound_t@1@@Z
// EA  : 0x82700E70
// RVA : 0x00700E70
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __fastcall idEffectPhysicsBreakable::Init(
        idEffectPhysicsBreakable *this,
        idClip *clip,
        idTraceModelCache *tmc,
        idGameLibEffects *_gameLibEffects,
        idRenderModelDiscreteAnimation *model_,
        int entNum,
        idEffectPhysicsBreakable::breakablePieceSound_t *_soundInfo)
{
  const idDeclBreakable **p_decl; // r10
  idEffectPhysicsBreakable::breakablePieceSound_t *v13; // r11
  int i; // ctr
  const idDiscreteAnimationModelData *modelData; // r8
  int num; // r30
  int size; // r11
  const idDiscreteAnimationModelData *v18; // r9
  int v19; // r30
  int v20; // r11
  int v21; // r23
  int v22; // r22
  float *p_z; // r10
  int v24; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  const idEffectPhysicsProperties *PropertiesForTraceModel; // r29
  idEffectPhysicsRigidBody *v27; // r3
  idEffectPhysicsRigidBody *v28; // r30
  double z; // fp12
  double y; // fp13
  double mass; // fp2
  double v32; // fp2
  double v33; // fp1
  double x; // fp13
  double v35; // fp12
  double v36; // fp10
  __int64 v37; // r8
  int v38; // r11
  idVec3 v39[2]; // [sp+58h] [-6D8h] BYREF
  idMat3 v40; // [sp+70h] [-6C0h] BYREF
  idTraceModel v41; // [sp+A0h] [-690h] BYREF

  idEffectPhysicsBroadPhase::Init(this: &this->broadPhase, clip, tmc);
  this->gameLibEffects = _gameLibEffects;
  if ( _soundInfo != nullptr )
  {
    p_decl = &this->decl;
    v13 = (idEffectPhysicsBreakable::breakablePieceSound_t *)((char *)_soundInfo - 4);
    for ( i = 6; i != 0; --i )
    {
      v13 = (idEffectPhysicsBreakable::breakablePieceSound_t *)((char *)v13 + 4);
      *++p_decl = (const idDeclBreakable *)v13->soundWorld;
    }
  }
  this->model = model_;
  this->decl = model_->declBreakable;
  idList<idEffectPhysicsProperties *,59>::DeleteContents(this: &this->properties);
  idList<idEffectPhysicsRigidBody *,59>::DeleteContents(this: &this->rigidBodies);
  modelData = this->model->modelData;
  num = modelData->traceModels.num;
  if ( num <= this->rigidBodies.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->rigidBodies,
         newsize: modelData->traceModels.num) )
  {
    size = this->rigidBodies.size;
    if ( num < size )
      size = num;
    this->rigidBodies.num = size;
  }
  v18 = this->model->modelData;
  v19 = v18->traceModels.num;
  if ( v19 <= this->collisions.size
    || (unsigned __int8)idList<idEffectPhysicsCollision,59>::Resize(
                          this: &this->collisions,
                          newsize: v18->traceModels.num) != 0 )
  {
    v20 = this->collisions.size;
    if ( v19 < v20 )
      v20 = v19;
    this->collisions.num = v20;
  }
  v21 = 0;
  if ( this->model->modelData->traceModels.num > 0 )
  {
    v22 = 0;
    do
    {
      v41.offset.x = 0.0;
      p_z = &v41.offset.z;
      v41.offset.y = 0.0;
      v41.offset.z = 0.0;
      memset(&v41.type, 0, 20);
      v24 = 6;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      do
      {
        ++p_viewNoteMutex;
        *++p_z = *(float *)&p_viewNoteMutex->handle;
        --v24;
      }
      while ( v24 != 0 );
      v41.radius = 0.0;
      v41.isConvex = false;
      v41.pad[2] = 0;
      v41.pad[1] = 0;
      v41.pad[0] = 0;
      idRenderModelDiscreteAnimation::GetPiecePosition(this: this->model, index: v21, position: v39, orientation: &v40);
      idRenderModelDiscreteAnimation::GetPieceTraceModel(this: this->model, index: v21, traceModel: &v41);
      idTraceModel::Shrink(this: &v41, m: 0.1875);
      PropertiesForTraceModel = idEffectPhysicsBreakable::GetPropertiesForTraceModel(this, trm: &v41);
      v27 = (idEffectPhysicsRigidBody *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x110u,
                                          tag: TAG_FXPHYSICS,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      if ( v27 != nullptr )
        v28 = idEffectPhysicsRigidBody::idEffectPhysicsRigidBody(this: v27);
      else
        v28 = nullptr;
      idEffectPhysicsRigidBody::Setup(this: v28, props: PropertiesForTraceModel);
      v28->currentState.position = v39[0];
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v28->properties->broadPhase,
        object: &v28->SPObject,
        origin: &v28->currentState.position,
        axis: &v28->currentState.orientation,
        bounds: nullptr);
      v28->currentState.orientation = v40;
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v28->properties->broadPhase,
        object: &v28->SPObject,
        origin: &v28->currentState.position,
        axis: &v28->currentState.orientation,
        bounds: nullptr);
      z = vec3_origin.z;
      y = vec3_origin.y;
      ++v21;
      mass = v28->properties->mass;
      v28->currentState.linearMomentum.x = v28->properties->mass * vec3_origin.x;
      v28->currentState.linearMomentum.z = (float)mass * (float)z;
      v28->currentState.linearMomentum.y = (float)mass * (float)y;
      v32 = v28->properties->inertiaTensor.mat[0].y;
      v33 = v28->properties->inertiaTensor.mat[0].z;
      x = vec3_origin.x;
      v35 = (float)((float)(v28->properties->inertiaTensor.mat[1].z * vec3_origin.y)
                  + (float)(v28->properties->inertiaTensor.mat[2].z * vec3_origin.z));
      v36 = (float)((float)(v28->properties->inertiaTensor.mat[1].y * vec3_origin.y)
                  + (float)(v28->properties->inertiaTensor.mat[2].y * vec3_origin.z));
      v28->currentState.angularMomentum.x = (float)(v28->properties->inertiaTensor.mat[0].x * vec3_origin.x)
                                          + (float)((float)(v28->properties->inertiaTensor.mat[1].x * vec3_origin.y)
                                                  + (float)(v28->properties->inertiaTensor.mat[2].x * vec3_origin.z));
      v28->currentState.angularMomentum.z = (float)((float)v33 * (float)x) + (float)v35;
      v28->currentState.angularMomentum.y = (float)((float)v32 * (float)x) + (float)v36;
      v28->SPObject.entityNum = entNum;
      this->rigidBodies.list[v22++] = v28;
    }
    while ( v21 < this->model->modelData->traceModels.num );
  }
  HIDWORD(v37) = &this->random;
  this->basePiece = this->model->modelData->baseModel;
  v38 = 1103515245 * this->random.seed + 12345;
  this->random.seed = v38;
  LODWORD(v37) = (v38 >> 16) & 0x7FFF;
  idEffectPhysicsBreakable::InitExplosionsAndTrails(
    this,
    soundInfo: &this->soundInfo,
    gameLibEffects: this->gameLibEffects,
    diversity: (float)((float)v37 * (float)0.000030518509));
}


// ========================================================================
// __unwind$260673
// EA  : 0x82701298
// RVA : 0x00701298
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void _unwind_260673()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1840 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// `dynamic initializer for 'g_skipBreakableParticles''
// EA  : 0x8333F588
// RVA : 0x0133F588
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_skipBreakableParticles__()
{
  idCVar::idCVar(
    this: &g_skipBreakableParticles,
    name: "g_skipBreakableParticles",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_skipBreakableParticles__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableSpin''
// EA  : 0x8333F5E0
// RVA : 0x0133F5E0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableSpin__()
{
  idCVar::idCVar(
    this: &g_breakableSpin,
    name: "g_breakableSpin",
    value: "250",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableSpin__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableRayUpPercent''
// EA  : 0x8333F638
// RVA : 0x0133F638
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableRayUpPercent__()
{
  idCVar::idCVar(
    this: &g_breakableRayUpPercent,
    name: "g_breakableRayUpPercent",
    value: "10",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableRayUpPercent__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableDebugIslands''
// EA  : 0x8333F690
// RVA : 0x0133F690
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableDebugIslands__()
{
  idCVar::idCVar(
    this: &g_breakableDebugIslands,
    name: "g_breakableDebugIslands",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableDebugIslands__);
}


// ========================================================================
// `dynamic initializer for 'g_debugBreakableDecals''
// EA  : 0x8333F6E8
// RVA : 0x0133F6E8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugBreakableDecals__()
{
  idCVar::idCVar(
    this: &g_debugBreakableDecals,
    name: "g_breakableDebugDecals",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugBreakableDecals__);
}

