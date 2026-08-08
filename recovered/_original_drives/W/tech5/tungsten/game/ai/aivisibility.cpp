
// ========================================================================
// ?ByteToFOVDot@idAIVisibility@@SAME@Z
// EA  : 0x82A60ED8
// RVA : 0x00A60ED8
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

float __fastcall idAIVisibility::ByteToFOVDot(const unsigned __int8 fov)
{
  __int64 v1; // r10
  double v2; // fp1

  LODWORD(v1) = fov;
  HIDWORD(v1) = &unk_821C0000;
  v2 = (float)((float)((float)v1 * (float)0.0078431377) - (float)1.0);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?FOVDotToByte@idAIVisibility@@SAEM@Z
// EA  : 0x82A60F08
// RVA : 0x00A60F08
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

unsigned int __fastcall idAIVisibility::FOVDotToByte(double fov)
{
  return (unsigned int)(int)(float)((float)((float)fov + (float)1.0) * (float)127.5) >> 24;
}


// ========================================================================
// ?TraceVisible_Resolve@idAIVisibility@@SA_NPBVidAIGameState@@VidSpawnId@@AAVidClipQuery@@AAUtrace_t@@@Z
// EA  : 0x82A60F38
// RVA : 0x00A60F38
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

int __fastcall idAIVisibility::TraceVisible_Resolve(
        idAIGameState *gameState,
        const idSpawnId *destId,
        idClipQuery *clipQuery,
        trace_t *tr,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idSpawnId a14)
{
  idClientGame *v17; // r29
  __int128 v18; // r11
  const aiLatchedState_t *State; // r31
  int EntityNumber; // r29
  int v21; // r3
  int entityNum; // r11

  a14.value = (int)destId;
  v17 = clientGame;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery) != 0 )
  {
    *((idClipQuery *)&v18 + 1) = (idClipQuery)clipQuery->index;
    DWORD1(v18) = &consoleFont[21088];
    clipQuery->index = *(unsigned __int64 *)((char *)&v18 + 4);
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: tr,
      query: &v17->clip.collisionQueries[v18 & 0xFFF].query,
      peek: false);
    if ( tr->fraction >= 1.0 )
      return 1;
    if ( a14.value != 0x1FFF )
    {
      State = idAIGameState::GetState(this: gameState, spawnId: &a14);
      if ( State != nullptr )
      {
        EntityNumber = idSpawnId::GetEntityNumber(this: &a14);
        v21 = idSpawnId::GetEntityNumber(this: &State->masterId);
        entityNum = tr->c.entityNum;
        if ( entityNum == EntityNumber || entityNum == v21 )
          return 1;
      }
    }
  }
  else
  {
    tr->fraction = 0.0;
  }
  return 0;
}


// ========================================================================
// ?CheckFOV@idAIVisibility@@SAMABVidVec3@@0M@Z
// EA  : 0x82A61038
// RVA : 0x00A61038
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

float __fastcall idAIVisibility::CheckFOV(const idVec3 *dir, const idVec3 *eyeFwd, double cosFOV)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  double v8; // fp1
  double v9; // fp31
  idPLogScope v11[2]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idAIVisibility::CheckFOV1");
  LODWORD(v6) = "idAIVisibility::CheckFOV1";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v11, pl: &pLog, gMask: v6, label: v7);
  if ( (float)((float)(dir->x * eyeFwd->x) + (float)((float)(dir->z * eyeFwd->z) + (float)(dir->y * eyeFwd->y))) > cosFOV )
  {
    v9 = (float)((float)((float)((float)(dir->x * eyeFwd->x)
                               + (float)((float)(dir->z * eyeFwd->z) + (float)(dir->y * eyeFwd->y)))
                       - (float)cosFOV)
               / (float)((float)1.0 - (float)cosFOV));
    idPLogScope::~idPLogScope(this: v11);
    RD_EventEnd();
    v8 = v9;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v11);
    RD_EventEnd();
    v8 = 0.0;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// __unwind$487591
// EA  : 0x82A610F4
// RVA : 0x00A610F4
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487591()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$487592
// EA  : 0x82A6111C
// RVA : 0x00A6111C
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487592()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?CheckFOV@idAIVisibility@@SAMABVidVec3@@0MM@Z
// EA  : 0x82A61150
// RVA : 0x00A61150
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

float __fastcall idAIVisibility::CheckFOV(
        const idVec3 *dir,
        const idVec3 *eyeFwd,
        double cosHorzFOV,
        double cosVertFOV)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  double v10; // fp6
  double v11; // fp4
  double v12; // fp5
  double v15; // fp3
  double v16; // fp1
  double v17; // fp1
  double v18; // fp2
  double v19; // fp6
  double v20; // fp1
  double v21; // fp1
  double v22; // fp13
  double v23; // fp10
  double v24; // fp9
  double v25; // fp8
  double v26; // fp5
  double v31; // fp2
  double v32; // fp12
  double v33; // fp11
  double v34; // fp4
  double v35; // fp3
  double v36; // fp2
  double v37; // fp12
  double v38; // fp3
  double v39; // fp2
  double v40; // fp12
  double v41; // fp11
  double v42; // fp4
  double v43; // fp3
  double v44; // fp11
  double v45; // fp4
  double v46; // fp3
  double v47; // fp31
  idPLogScope v49[7]; // [sp+50h] [-60h] BYREF

  RD_EventBegin(name: "idAIVisibility::CheckFOV2");
  LODWORD(v8) = "idAIVisibility::CheckFOV2";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: v49, pl: &pLog, gMask: v8, label: v9);
  v10 = (float)(dir->y
              - (float)((float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                              - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z))
                      * (float)((float)(dir->y
                                      * (float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                                              - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z)))
                              + (float)((float)(dir->x
                                              * (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                                                      - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y)))
                                      + (float)(dir->z
                                              * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                                                      - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x)))))));
  v11 = (float)(dir->z
              - (float)((float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                              - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x))
                      * (float)((float)(dir->y
                                      * (float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                                              - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z)))
                              + (float)((float)(dir->x
                                              * (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                                                      - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y)))
                                      + (float)(dir->z
                                              * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                                                      - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x)))))));
  v12 = (float)(dir->x
              - (float)((float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                              - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y))
                      * (float)((float)(dir->y
                                      * (float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                                              - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z)))
                              + (float)((float)(dir->x
                                              * (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                                                      - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y)))
                                      + (float)(dir->z
                                              * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                                                      - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x)))))));
  _FP3 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f1, f12 }
  v15 = __frsqrte(_FP1);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15)
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  v18 = (float)((float)(dir->y
                      - (float)((float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                                      - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z))
                              * (float)((float)(dir->y
                                              * (float)((float)(eyeFwd->z * idAIVisibility::VEC_Z.x)
                                                      - (float)(eyeFwd->x * idAIVisibility::VEC_Z.z)))
                                      + (float)((float)(dir->x
                                                      * (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                                                              - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y)))
                                              + (float)(dir->z
                                                      * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                                                              - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x)))))))
              * (float)v17);
  v19 = (float)((float)(eyeFwd->y * (float)v18)
              + (float)((float)(eyeFwd->x
                              * (float)((float)(dir->x
                                              - (float)((float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.z)
                                                              - (float)(eyeFwd->z * idAIVisibility::VEC_Z.y))
                                                      * (float)((float)(dir->y
                                                                      * (float)((float)(eyeFwd->z
                                                                                      * idAIVisibility::VEC_Z.x)
                                                                              - (float)(eyeFwd->x
                                                                                      * idAIVisibility::VEC_Z.z)))
                                                              + (float)((float)(dir->x
                                                                              * (float)((float)(eyeFwd->y
                                                                                              * idAIVisibility::VEC_Z.z)
                                                                                      - (float)(eyeFwd->z
                                                                                              * idAIVisibility::VEC_Z.y)))
                                                                      + (float)(dir->z
                                                                              * (float)((float)(eyeFwd->x
                                                                                              * idAIVisibility::VEC_Z.y)
                                                                                      - (float)(eyeFwd->y
                                                                                              * idAIVisibility::VEC_Z.x)))))))
                                      * (float)v17))
                      + (float)((float)((float)(dir->z
                                              - (float)((float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.y)
                                                              - (float)(eyeFwd->y * idAIVisibility::VEC_Z.x))
                                                      * (float)((float)(dir->y
                                                                      * (float)((float)(eyeFwd->z
                                                                                      * idAIVisibility::VEC_Z.x)
                                                                              - (float)(eyeFwd->x
                                                                                      * idAIVisibility::VEC_Z.z)))
                                                              + (float)((float)(dir->x
                                                                              * (float)((float)(eyeFwd->y
                                                                                              * idAIVisibility::VEC_Z.z)
                                                                                      - (float)(eyeFwd->z
                                                                                              * idAIVisibility::VEC_Z.y)))
                                                                      + (float)(dir->z
                                                                              * (float)((float)(eyeFwd->x
                                                                                              * idAIVisibility::VEC_Z.y)
                                                                                      - (float)(eyeFwd->y
                                                                                              * idAIVisibility::VEC_Z.x)))))))
                                      * (float)v17)
                              * eyeFwd->z)));
  if ( v19 >= cosVertFOV )
  {
    v21 = (float)(dir->y
                - (float)(idAIVisibility::VEC_Z.y
                        * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                        + (float)(dir->z * idAIVisibility::VEC_Z.z)))));
    v23 = (float)(dir->x
                - (float)(idAIVisibility::VEC_Z.x
                        * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                        + (float)(dir->z * idAIVisibility::VEC_Z.z)))));
    v24 = (float)(eyeFwd->x
                - (float)(idAIVisibility::VEC_Z.x
                        * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                        + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))));
    v25 = (float)(dir->z
                - (float)(idAIVisibility::VEC_Z.z
                        * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                        + (float)(dir->z * idAIVisibility::VEC_Z.z)))));
    v26 = (float)(eyeFwd->z
                - (float)(idAIVisibility::VEC_Z.z
                        * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                        + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))));
    v22 = (float)(eyeFwd->y
                - (float)(idAIVisibility::VEC_Z.y
                        * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                        + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))));
    _FP2 = (float)((float)((float)((float)v25 * (float)v25)
                         + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    _FP11 = (float)((float)((float)((float)v26 * (float)v26)
                          + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm
    {
      fsel      f4, f2, f4, f12
      fsel      f3, f11, f3, f12
    }
    v31 = __frsqrte(_FP4);
    v32 = __frsqrte(_FP3);
    v33 = (float)v31;
    v34 = (float)v32;
    v35 = (float)((float)v31
                * (float)((float)((float)((float)v25 * (float)v25)
                                + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))
                        * (float)0.5));
    v36 = (float)((float)v32
                * (float)((float)((float)((float)v26 * (float)v26)
                                + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22)))
                        * (float)0.5));
    v37 = (float)-(float)((float)((float)v35 * (float)v33) - (float)1.5);
    v38 = (float)-(float)((float)((float)v36 * (float)v34) - (float)1.5);
    v39 = (float)((float)v37 * (float)v33);
    v41 = (float)((float)((float)v37 * (float)v33)
                * (float)((float)((float)((float)v25 * (float)v25)
                                + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))
                        * (float)0.5));
    v40 = (float)((float)v38 * (float)v34);
    v42 = (float)((float)((float)v38 * (float)v34)
                * (float)((float)((float)((float)v26 * (float)v26)
                                + (float)((float)((float)v24 * (float)v24) + (float)((float)v22 * (float)v22)))
                        * (float)0.5));
    v43 = (float)-(float)((float)((float)v41 * (float)v39) - (float)1.5);
    v44 = (float)-(float)((float)((float)v42 * (float)v40) - (float)1.5);
    v45 = (float)((float)-(float)((float)((float)((float)((float)v43 * (float)v39)
                                                * (float)((float)((float)((float)v25 * (float)v25)
                                                                + (float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)((float)v43 * (float)v39))
                                - (float)1.5)
                * (float)((float)v43 * (float)v39));
    v46 = (float)((float)-(float)((float)((float)((float)((float)v44 * (float)v40)
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)((float)v24 * (float)v24)
                                                                        + (float)((float)v22 * (float)v22)))
                                                        * (float)0.5))
                                        * (float)((float)v44 * (float)v40))
                                - (float)1.5)
                * (float)((float)v44 * (float)v40));
    if ( (float)((float)((float)((float)(eyeFwd->x
                                       - (float)(idAIVisibility::VEC_Z.x
                                               * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                                       + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                                               + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))))
                               * (float)v46)
                       * (float)((float)(dir->x
                                       - (float)(idAIVisibility::VEC_Z.x
                                               * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                                       + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                                               + (float)(dir->z * idAIVisibility::VEC_Z.z)))))
                               * (float)v45))
               + (float)((float)((float)((float)(eyeFwd->z
                                               - (float)(idAIVisibility::VEC_Z.z
                                                       * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                                               + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                                                       + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))))
                                       * (float)v46)
                               * (float)((float)(dir->z
                                               - (float)(idAIVisibility::VEC_Z.z
                                                       * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                                               + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                                                       + (float)(dir->z * idAIVisibility::VEC_Z.z)))))
                                       * (float)v45))
                       + (float)((float)((float)(eyeFwd->y
                                               - (float)(idAIVisibility::VEC_Z.y
                                                       * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                                               + (float)((float)(eyeFwd->y * idAIVisibility::VEC_Z.y)
                                                                       + (float)(eyeFwd->z * idAIVisibility::VEC_Z.z)))))
                                       * (float)v46)
                               * (float)((float)(dir->y
                                               - (float)(idAIVisibility::VEC_Z.y
                                                       * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                                               + (float)((float)(dir->y * idAIVisibility::VEC_Z.y)
                                                                       + (float)(dir->z * idAIVisibility::VEC_Z.z)))))
                                       * (float)v45)))) >= cosHorzFOV )
      v47 = (float)((float)((float)((float)((float)((float)(eyeFwd->x
                                                          - (float)(idAIVisibility::VEC_Z.x
                                                                  * (float)((float)(eyeFwd->x * idAIVisibility::VEC_Z.x)
                                                                          + (float)((float)(eyeFwd->y
                                                                                          * idAIVisibility::VEC_Z.y)
                                                                                  + (float)(eyeFwd->z
                                                                                          * idAIVisibility::VEC_Z.z)))))
                                                  * (float)v46)
                                          * (float)((float)(dir->x
                                                          - (float)(idAIVisibility::VEC_Z.x
                                                                  * (float)((float)(dir->x * idAIVisibility::VEC_Z.x)
                                                                          + (float)((float)(dir->y
                                                                                          * idAIVisibility::VEC_Z.y)
                                                                                  + (float)(dir->z
                                                                                          * idAIVisibility::VEC_Z.z)))))
                                                  * (float)v45))
                                  + (float)((float)((float)((float)(eyeFwd->z
                                                                  - (float)(idAIVisibility::VEC_Z.z
                                                                          * (float)((float)(eyeFwd->x
                                                                                          * idAIVisibility::VEC_Z.x)
                                                                                  + (float)((float)(eyeFwd->y
                                                                                                  * idAIVisibility::VEC_Z.y)
                                                                                          + (float)(eyeFwd->z
                                                                                                  * idAIVisibility::VEC_Z.z)))))
                                                          * (float)v46)
                                                  * (float)((float)(dir->z
                                                                  - (float)(idAIVisibility::VEC_Z.z
                                                                          * (float)((float)(dir->x
                                                                                          * idAIVisibility::VEC_Z.x)
                                                                                  + (float)((float)(dir->y
                                                                                                  * idAIVisibility::VEC_Z.y)
                                                                                          + (float)(dir->z
                                                                                                  * idAIVisibility::VEC_Z.z)))))
                                                          * (float)v45))
                                          + (float)((float)((float)(eyeFwd->y
                                                                  - (float)(idAIVisibility::VEC_Z.y
                                                                          * (float)((float)(eyeFwd->x
                                                                                          * idAIVisibility::VEC_Z.x)
                                                                                  + (float)((float)(eyeFwd->y
                                                                                                  * idAIVisibility::VEC_Z.y)
                                                                                          + (float)(eyeFwd->z
                                                                                                  * idAIVisibility::VEC_Z.z)))))
                                                          * (float)v46)
                                                  * (float)((float)(dir->y
                                                                  - (float)(idAIVisibility::VEC_Z.y
                                                                          * (float)((float)(dir->x
                                                                                          * idAIVisibility::VEC_Z.x)
                                                                                  + (float)((float)(dir->y
                                                                                                  * idAIVisibility::VEC_Z.y)
                                                                                          + (float)(dir->z
                                                                                                  * idAIVisibility::VEC_Z.z)))))
                                                          * (float)v45))))
                          - (float)cosHorzFOV)
                  / (float)(1.0 - (float)cosHorzFOV));
    else
      v47 = (float)((float)((float)v19 - (float)cosVertFOV) / (float)(1.0 - (float)cosVertFOV));
    idPLogScope::~idPLogScope(this: v49);
    RD_EventEnd();
    v20 = v47;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v49);
    RD_EventEnd();
    v20 = 0.0;
  }
  return *((float *)&v20 + 1);
}


// ========================================================================
// __unwind$487635
// EA  : 0x82A61400
// RVA : 0x00A61400
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487635()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$487636
// EA  : 0x82A61428
// RVA : 0x00A61428
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487636()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// ?TraceVisible@idAIVisibility@@SA_NPBVidAIGameState@@ABVidVec3@@1VidSpawnId@@2AAUtrace_t@@_N@Z
// EA  : 0x82A61458
// RVA : 0x00A61458
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

int __fastcall idAIVisibility::TraceVisible(
        idAIGameState *gameState,
        const idVec3 *fromPoint,
        const idVec3 *toPoint,
        const idSpawnId *ignoreId,
        const idSpawnId *destId,
        trace_t *tr,
        bool seeThroughBreakables,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        idSpawnId a18,
        int a19,
        idSpawnId a20)
{
  unsigned __int64 v25; // r6
  const char *v26; // r7
  int v27; // r23
  int v28; // r29
  bool v29; // zf
  unsigned __int64 v30; // r6
  const char *v31; // r7
  int EntityNumber; // r3
  const aiLatchedState_t *State; // r30
  int v34; // r29
  int v35; // r3
  int entityNum; // r11
  idPlayer *v37; // r3
  idColor *v38; // r4
  idPLogScope v40; // [sp+50h] [-70h] BYREF
  idPLogScope v41[13]; // [sp+58h] [-68h] BYREF

  a18.value = (int)ignoreId;
  a20.value = (int)destId;
  RD_EventBegin(name: "idAIVisibility::TraceVisible");
  LODWORD(v25) = "idAIVisibility::TraceVisible";
  HIDWORD(v25) = 6;
  idPLogScope::idPLogScope(this: v41, pl: &pLog, gMask: v25, label: v26);
  v27 = 0;
  v29 = seeThroughBreakables;
  v28 = 3;
  if ( !v29 )
    v28 = 8195;
  RD_EventBegin(name: "idAIVisibility::TraceVisible - trace point");
  LODWORD(v30) = "idAIVisibility::TraceVisible - trace point";
  HIDWORD(v30) = 6;
  idPLogScope::idPLogScope(this: &v40, pl: &pLog, gMask: v30, label: v31);
  EntityNumber = idSpawnId::GetEntityNumber(this: &a18);
  idClip::TracePoint(
    this: &clientGame->clip,
    result: tr,
    start: fromPoint,
    end: toPoint,
    clipMask: v28,
    passEntityNumber: EntityNumber);
  idPLogScope::~idPLogScope(this: &v40);
  RD_EventEnd();
  if ( tr->fraction >= 1.0
    || a20.value != 0x1FFF
    && (State = idAIGameState::GetState(this: gameState, spawnId: &a20)) != nullptr
    && ((v34 = idSpawnId::GetEntityNumber(this: &a20),
         v35 = idSpawnId::GetEntityNumber(this: &State->masterId),
         (entityNum = tr->c.entityNum) == v34)
     || entityNum == v35) )
  {
    v27 = 1;
  }
  if ( ai_showVisTrace.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
  {
    v37 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: a20.value);
    if ( idPlayer::CastTo(c: v37) != nullptr || ai_showVisTrace.valueInteger == 1 )
    {
      if ( (_BYTE)v27 != 0 )
        v38 = &idColor::colorRed;
      else
        v38 = &idColor::colorYellow;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v38,
        a3: fromPoint,
        a4: &tr->endpos,
        a5: 1000,
        a6: true);
    }
  }
  idPLogScope::~idPLogScope(this: v41);
  RD_EventEnd();
  return v27;
}


// ========================================================================
// __unwind$487815
// EA  : 0x82A61644
// RVA : 0x00A61644
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487815()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$487816
// EA  : 0x82A6166C
// RVA : 0x00A6166C
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487816()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$487817
// EA  : 0x82A61694
// RVA : 0x00A61694
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487817()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 97));
}


// ========================================================================
// __unwind$487818
// EA  : 0x82A616BC
// RVA : 0x00A616BC
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487818()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?TraceVisible_Submit@idAIVisibility@@SAXABVidVec3@@0VidSpawnId@@_NAAVidClipQuery@@@Z
// EA  : 0x82A616F0
// RVA : 0x00A616F0
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void __fastcall idAIVisibility::TraceVisible_Submit(
        const idVec3 *fromPoint,
        const idVec3 *toPoint,
        const idSpawnId *ignoreId,
        bool seeThroughBreakables,
        idClipQuery *clipQuery,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        idSpawnId a16)
{
  unsigned __int64 v20; // r6
  const char *v21; // r7
  int v22; // r30
  bool v23; // zf
  int EntityNumber; // r3
  int v25; // [sp+8h] [-B8h]
  bool v26; // [sp+Fh] [-B1h]
  const char *v27; // [sp+10h] [-B0h]
  int v28; // [sp+14h] [-ACh]
  int v29; // [sp+18h] [-A8h]
  int v30; // [sp+1Ch] [-A4h]
  int v31; // [sp+20h] [-A0h]
  int v32; // [sp+24h] [-9Ch]
  int v33; // [sp+28h] [-98h]
  int v34; // [sp+2Ch] [-94h]
  int v35; // [sp+30h] [-90h]
  int v36; // [sp+34h] [-8Ch]
  int v37; // [sp+38h] [-88h]
  int v38; // [sp+3Ch] [-84h]
  int v39; // [sp+40h] [-80h]
  int v40; // [sp+44h] [-7Ch]
  int v41; // [sp+48h] [-78h]
  int v42; // [sp+4Ch] [-74h]
  int v43; // [sp+50h] [-70h]
  int v44; // [sp+58h] [-68h]
  int v45; // [sp+60h] [-60h]
  idPLogScope v46; // [sp+70h] [-50h] BYREF
  int v47; // [sp+78h] [-48h] BYREF

  a16.value = (int)ignoreId;
  RD_EventBegin(name: "idAIVisibility::TraceVisible");
  LODWORD(v20) = "idAIVisibility::TraceVisible";
  HIDWORD(v20) = 6;
  idPLogScope::idPLogScope(this: &v46, pl: &pLog, gMask: v20, label: v21);
  v23 = seeThroughBreakables;
  v22 = 3;
  if ( !v23 )
    v22 = 8195;
  EntityNumber = idSpawnId::GetEntityNumber(this: &a16);
  clipQuery->index = *(unsigned __int64 *)&idClip::Translation(
                                             this: (idClip *)&v47,
                                             result: &clientGame->clip,
                                             a3: nullptr,
                                             start: fromPoint,
                                             end: toPoint,
                                             clipModel: nullptr,
                                             startAxis: &mat3_identity,
                                             clipMask: v22,
                                             passEntityNumber: v25,
                                             moveClipModel: v26,
                                             userName: v27,
                                             a12: v28,
                                             a13: v29,
                                             a14: v30,
                                             a15: v31,
                                             a16: v32,
                                             a17: v33,
                                             a18: v34,
                                             a19: v35,
                                             a20: v36,
                                             a21: v37,
                                             a22: v38,
                                             a23: v39,
                                             a24: v40,
                                             a25: v41,
                                             a26: v42,
                                             a27: v43,
                                             a28: EntityNumber,
                                             a29: v44,
                                             a30: false,
                                             a31: v45,
                                             a32: (int)"w:\\tech5\\tungsten\\game\\ai\\AIVisibility.cpp(174) : Translation")->world;
  idPLogScope::~idPLogScope(this: &v46);
  RD_EventEnd();
}


// ========================================================================
// __unwind$487888
// EA  : 0x82A617BC
// RVA : 0x00A617BC
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487888()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 128));
}


// ========================================================================
// __unwind$487889
// EA  : 0x82A617E4
// RVA : 0x00A617E4
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void _unwind_487889()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 112));
}


// ========================================================================
// `dynamic initializer for 'ai_showVisTrace''
// EA  : 0x83367C50
// RVA : 0x01367C50
// PDB : w:\tech5\tungsten\game\ai\aivisibility.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showVisTrace__()
{
  idCVar::idCVar(
    this: &ai_showVisTrace,
    name: "ai_showVisTrace",
    value: "0",
    flags: 2,
    description: "1 to show visibility traces, 2 only against player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showVisTrace__);
}

