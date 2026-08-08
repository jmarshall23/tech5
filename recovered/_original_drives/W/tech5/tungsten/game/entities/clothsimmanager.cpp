
// ========================================================================
// ?Update@idClothSimManager@@QAAXXZ
// EA  : 0x82C16AD0
// RVA : 0x00C16AD0
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::Update(idClothSimManager *this)
{
  int v1; // r9
  int v2; // r11

  v1 = 0;
  if ( this->cloth.num > 0 )
  {
    v2 = 0;
    do
    {
      if ( this->cloth.list[v2].state == READY_TO_FREE )
        this->cloth.list[v2].state = READY_TO_USE;
      ++v1;
      ++v2;
    }
    while ( v1 < this->cloth.num );
  }
}


// ========================================================================
// ?FreeCloth@idClothSimManager@@QAAXPAVidClothSim@@@Z
// EA  : 0x82C16B18
// RVA : 0x00C16B18
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::FreeCloth(idClothSimManager *this, idClothSim *clothSim)
{
  int num; // r7
  int v3; // r10
  idClothSimManager::clothSims_t *list; // r8
  int v5; // r11
  idClothSimManager::clothSims_t *v6; // r9

  if ( clothSim != nullptr )
  {
    num = this->cloth.num;
    v3 = 0;
    if ( num > 0 )
    {
      list = this->cloth.list;
      v5 = 0;
      v6 = this->cloth.list;
      while ( v6->clothSim != clothSim )
      {
        ++v3;
        v6 = &list[++v5];
        if ( v3 >= num )
          return;
      }
      list[v3].state = READY_TO_FREE;
    }
  }
}


// ========================================================================
// ?ReserveCloth@idClothSimManager@@QAAPAVidClothSim@@PBVidDeclCloth@@@Z
// EA  : 0x82C16B70
// RVA : 0x00C16B70
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

idClothSim *__fastcall idClothSimManager::ReserveCloth(idClothSimManager *this, const idDeclCloth *decl)
{
  int num; // r6
  int v4; // r8
  idClothSimManager::clothSims_t *list; // r7
  int i; // r10
  const idDeclCloth **p_clothDecl; // r11
  int v9; // r31

  if ( decl == nullptr )
    idLib::Error(fmt: "idClothSimManager::ReserveCloth() - NULL idDeclEntityDef passed in.");
  num = this->cloth.num;
  v4 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->cloth.list;
  for ( i = 0; ; ++i )
  {
    p_clothDecl = &list[i].clothSim->clothDecl;
    if ( p_clothDecl != nullptr && *p_clothDecl == decl && list[i].state == READY_TO_USE )
      break;
    if ( ++v4 >= num )
      return nullptr;
  }
  v9 = v4;
  list[v4].state = 2;
  idClothSim::Reset(this: this->cloth.list[v4].clothSim);
  return this->cloth.list[v9].clothSim;
}


// ========================================================================
// ??1idClothSimManager@@QAA@XZ
// EA  : 0x82C16C40
// RVA : 0x00C16C40
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::~idClothSimManager(idClothSimManager *this)
{
  int v2; // r27
  int v3; // r28
  idClothSimManager::clothSims_t *v4; // r11
  idClothSim *clothSim; // r29

  v2 = 0;
  if ( this->cloth.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->cloth.list[v3];
      clothSim = v4->clothSim;
      if ( clothSim != nullptr )
      {
        idClothSim::~idClothSim(this: v4->clothSim);
        idMem::Free(this: &mem, ptr: clothSim, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->cloth.num );
  }
  if ( this->cloth.listStatic == 0 || this->cloth.listStatic == 2 )
  {
    if ( this->cloth.list != nullptr )
      idMem::Free(this: &mem, ptr: this->cloth.list, align: ALIGN_16);
    this->cloth.list = nullptr;
    this->cloth.size = 0;
  }
  this->cloth.num = 0;
}


// ========================================================================
// __unwind$489014
// EA  : 0x82C16CFC
// RVA : 0x00C16CFC
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_489014()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 180));
}


// ========================================================================
// ?UpdateJointsWithClothSim@idClothSimManager@@QAAXPAVidTreeAnimator@@PAVidClothSim@@@Z
// EA  : 0x82C16D30
// RVA : 0x00C16D30
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::UpdateJointsWithClothSim(
        idClothSimManager *this,
        idTreeAnimator *ta,
        idClothSim *clothSim)
{
  BOOL useDeferredPosition; // r10
  idRenderModelParms *p_deferredOrigin; // r11
  const idDeclCloth *clothDecl; // r26
  float y; // r8
  float z; // r7
  idMat3 *p_deferredAxis; // r11
  int *v11; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idList<idDeclCloth::particleInfo_t,5> *p_particleData; // r23
  int v15; // r30
  int v16; // r29
  idDeclCloth::particleInfo_t *v17; // r11
  int j; // r28
  int width; // r8
  int k; // r29
  int v21; // r30
  idClothParticle *v22; // r11
  float v23; // r7
  int v24; // r6
  float v25; // r5
  int v26; // r11
  idClothParticle *v27; // r11
  double v28; // fp7
  double v29; // fp6
  double v30; // fp13
  double v31; // fp5
  double v32; // fp12
  double v33; // fp11
  int v34; // r11
  idClothParticle *v35; // r11
  int v36; // r11
  double v39; // fp1
  double v40; // fp4
  double v41; // fp1
  double v42; // fp4
  double v43; // fp10
  double v44; // fp9
  double v45; // fp8
  idClothParticle *v46; // r11
  double v47; // fp13
  double v48; // fp12
  double v49; // fp11
  idClothParticle *v50; // r11
  double v51; // fp7
  double v54; // fp7
  double v55; // fp5
  double v56; // fp2
  double v57; // fp1
  double v58; // fp13
  double v59; // fp12
  double v60; // fp5
  double v61; // fp4
  double v62; // fp3
  double v65; // fp6
  double v66; // fp6
  int v67; // r30
  int v68; // r11
  int v69; // r30
  int v70; // r29
  idDeclCloth::particleInfo_t *v71; // r11
  int v72; // r29
  int v73; // r30
  int v74; // r28
  idClothParticle *v75; // r11
  float v76; // r9
  float v77; // r7
  int v78; // r8
  int v79; // r11
  idClothParticle *v80; // r10
  int v81; // r11
  double v82; // fp12
  double v83; // fp10
  double v86; // fp9
  double v87; // fp1
  double v88; // fp9
  double v89; // fp1
  double v90; // fp13
  double v91; // fp12
  double v92; // fp11
  double v93; // fp10
  double v94; // fp9
  double v95; // fp8
  idClothParticle *v96; // r11
  double v97; // fp9
  double v98; // fp7
  double v101; // fp8
  double v102; // fp6
  double v103; // fp10
  double v104; // fp8
  double v105; // fp1
  double v106; // fp7
  double v107; // fp6
  double v110; // fp9
  double v111; // fp8
  double v112; // fp8
  double v113; // fp9
  double v114; // fp1
  double v115; // fp13
  double v116; // fp12
  double v119; // fp2
  double v120; // fp2
  idList<idDeclCloth::ropeInfo,5> *p_ropeData; // r25
  int v122; // r22
  int v123; // r26
  idDeclCloth::ropeInfo *list; // r11
  int v125; // r28
  int num; // r10
  int v127; // r27
  int v128; // r29
  idVec3 *v129; // r11
  double v130; // fp8
  double v131; // fp5
  double v132; // fp12
  double v133; // fp9
  double v134; // fp7
  double v135; // fp6
  idMat3 *v136; // r30
  int v137; // r30
  int v138; // r29
  int v139; // r28
  idDeclCloth::ropeInfo *v140; // r11
  idVec3 *v141; // r10
  double v142; // fp10
  double v143; // fp9
  idRenderWorld *v144; // r3
  idRenderWorld *v145; // r3
  idRenderWorld *v146; // r3
  unsigned int v147; // r28
  int GameMsPerFrame; // r27
  int PreviousGameMs; // r29
  int GameMs; // r3
  float *v151; // [sp+8h] [-908h]
  float *v152; // [sp+Ch] [-904h]
  float *v153; // [sp+10h] [-900h]
  int v154; // [sp+14h] [-8FCh]
  int v155; // [sp+18h] [-8F8h]
  int v156; // [sp+1Ch] [-8F4h]
  int v157; // [sp+20h] [-8F0h]
  int v158; // [sp+24h] [-8ECh]
  int v159; // [sp+28h] [-8E8h]
  int v160; // [sp+2Ch] [-8E4h]
  int v161; // [sp+30h] [-8E0h]
  int v162; // [sp+34h] [-8DCh]
  int v163; // [sp+38h] [-8D8h]
  int v164; // [sp+3Ch] [-8D4h]
  int v165; // [sp+40h] [-8D0h]
  int v166; // [sp+44h] [-8CCh]
  int v167; // [sp+48h] [-8C8h]
  int v168; // [sp+4Ch] [-8C4h]
  int v169; // [sp+50h] [-8C0h]
  int v170; // [sp+58h] [-8B8h]
  int v171; // [sp+60h] [-8B0h]
  clothType_t type; // [sp+70h] [-8A0h]
  idVec3 v173; // [sp+78h] [-898h] BYREF
  idMat3 v174; // [sp+90h] [-880h] BYREF
  float x; // [sp+B8h] [-858h]
  float v176; // [sp+BCh] [-854h]
  float v177; // [sp+C0h] [-850h]
  float v178; // [sp+C8h] [-848h] BYREF
  float v179; // [sp+CCh] [-844h]
  float v180; // [sp+D0h] [-840h]
  idMat3 v181; // [sp+E0h] [-830h] BYREF
  int v182; // [sp+10Ch] [-804h] BYREF
  idMat3 v183; // [sp+110h] [-800h] BYREF
  float v184[4]; // [sp+138h] [-7D8h] BYREF
  idVec3 v185; // [sp+148h] [-7C8h] BYREF
  float v186[4]; // [sp+158h] [-7B8h] BYREF
  float v187[4]; // [sp+168h] [-7A8h] BYREF
  idVec3 v188; // [sp+178h] [-798h] BYREF
  float v189[4]; // [sp+190h] [-780h] BYREF
  float v190[4]; // [sp+1A0h] [-770h] BYREF
  float v191[4]; // [sp+1B0h] [-760h] BYREF
  idMat3 v192; // [sp+1C0h] [-750h] BYREF
  idVec3 v193; // [sp+1E8h] [-728h] BYREF
  idVec3 v194[2]; // [sp+1F8h] [-718h] BYREF
  idList<idVec3,5> v195; // [sp+210h] [-700h] BYREF
  int v196; // [sp+220h] [-6F0h] BYREF
  idList<idMat3,5> v197; // [sp+3A0h] [-570h] BYREF
  int v198; // [sp+3B0h] [-560h] BYREF

  if ( ta != nullptr && clothSim != nullptr )
  {
    useDeferredPosition = ta->useDeferredPosition;
    p_deferredOrigin = (idRenderModelParms *)&ta->deferredOrigin;
    clothDecl = clothSim->clothDecl;
    if ( !ta->useDeferredPosition )
      p_deferredOrigin = &ta->g;
    y = p_deferredOrigin->origin.y;
    z = p_deferredOrigin->origin.z;
    v173.x = p_deferredOrigin->origin.x;
    p_deferredAxis = &ta->deferredAxis;
    v173.y = y;
    v173.z = z;
    if ( !useDeferredPosition )
      p_deferredAxis = &ta->g.axis;
    v11 = &v182;
    p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++v11 = *++p_z;
    p_particleData = &clothDecl->particleData;
    type = clothDecl->type;
    v181.mat[0].x = v183.mat[0].x;
    v181.mat[0].y = v183.mat[1].x;
    v181.mat[0].z = v183.mat[2].x;
    v181.mat[1].x = v183.mat[0].y;
    v181.mat[1].y = v183.mat[1].y;
    v181.mat[1].z = v183.mat[2].y;
    v181.mat[2].x = v183.mat[0].z;
    v181.mat[2].y = v183.mat[1].z;
    v181.mat[2].z = v183.mat[2].z;
    switch ( type )
    {
      case CLOTH_SQUARE:
        v15 = 0;
        if ( clothDecl->particleData.num > 0 )
        {
          v16 = 0;
          do
          {
            v17 = &p_particleData->list[v16];
            if ( v17->anchored )
            {
              idTreeAnimator::GetWorldSpaceJointTransform(
                this: ta,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v17->jointIndex.value,
                origin: &v193,
                axis: &v192);
              idClothSim::SetAnchorPosition(this: clothSim, index: v15, org: &v193);
            }
            ++v15;
            ++v16;
          }
          while ( v15 < clothDecl->particleData.num );
        }
        for ( j = 0; j < clothDecl->height; ++j )
        {
          width = clothDecl->width;
          for ( k = 0; k < width; ++k )
          {
            v21 = width * j + k;
            if ( v21 < 0 || v21 >= clothSim->numClothParticles )
              v22 = (idClothParticle *)&vec3_origin;
            else
              v22 = &clothSim->cloth[v21];
            v23 = v22->origin.y;
            v24 = clothDecl->height - 1;
            v25 = v22->origin.z;
            x = v22->origin.x;
            v176 = v23;
            v177 = v25;
            if ( j >= v24 )
            {
              v34 = v21 - width;
              if ( v21 - width < 0 || v34 >= clothSim->numClothParticles )
                v35 = (idClothParticle *)&vec3_origin;
              else
                v35 = &clothSim->cloth[v34];
              v28 = x;
              v29 = v176;
              v30 = (float)(x - v35->origin.x);
              v31 = v177;
              v32 = (float)(v176 - v35->origin.y);
              v33 = (float)(v177 - v35->origin.z);
            }
            else
            {
              v26 = width + v21;
              if ( width + v21 < 0 || v26 >= clothSim->numClothParticles )
                v27 = (idClothParticle *)&vec3_origin;
              else
                v27 = &clothSim->cloth[v26];
              v28 = x;
              v29 = v176;
              v30 = (float)(v27->origin.x - x);
              v31 = v177;
              v32 = (float)(v27->origin.y - v176);
              v33 = (float)(v27->origin.z - v177);
            }
            v36 = v21 + 1;
            _FP4 = (float)((float)((float)((float)v30 * (float)v30)
                                 + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f2, f4, f8, f0 }
            v39 = __frsqrte(_FP2);
            v40 = (float)((float)-(float)((float)((float)((float)v39
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39);
            v41 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39
                                                                                        * (float)((float)((float)((float)v30 * (float)v30) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v39)
                                                                        - (float)1.5)
                                                        * (float)v39)
                                                * (float)((float)((float)((float)v30 * (float)v30)
                                                                + (float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)v32 * (float)v32)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v39
                                                                                * (float)((float)((float)((float)v30 * (float)v30)
                                                                                                + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                        * (float)0.5))
                                                                        * (float)v39)
                                                                - (float)1.5)
                                                * (float)v39))
                                - (float)1.5);
            v42 = (float)((float)-(float)((float)((float)((float)((float)v41 * (float)v40)
                                                        * (float)((float)((float)((float)v30 * (float)v30)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)((float)v41 * (float)v40))
                                        - (float)1.5)
                        * (float)((float)v41 * (float)v40));
            v43 = (float)((float)v42 * (float)v30);
            v174.mat[0].x = (float)v42 * (float)v30;
            v44 = (float)((float)v42 * (float)v32);
            v174.mat[0].y = (float)v42 * (float)v32;
            v45 = (float)((float)v42 * (float)v33);
            v174.mat[0].z = (float)v42 * (float)v33;
            if ( k >= width - 1 )
            {
              if ( v21 + 1 < 0 || v36 >= clothSim->numClothParticles )
                v50 = (idClothParticle *)&vec3_origin;
              else
                v50 = &clothSim->cloth[v36];
              v47 = (float)((float)v28 - v50->origin.x);
              v48 = (float)((float)v29 - v50->origin.y);
              v49 = (float)((float)v31 - v50->origin.z);
            }
            else
            {
              if ( v21 + 1 < 0 || v36 >= clothSim->numClothParticles )
                v46 = (idClothParticle *)&vec3_origin;
              else
                v46 = &clothSim->cloth[v36];
              v47 = (float)(v46->origin.x - (float)v28);
              v48 = (float)(v46->origin.y - (float)v29);
              v49 = (float)(v46->origin.z - (float)v31);
            }
            v51 = (float)((float)v28 - v173.x);
            _FP1 = (float)((float)((float)((float)v47 * (float)v47)
                                 + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v185.z = (float)(v181.mat[0].z * (float)v51)
                   + (float)((float)((float)((float)v31 - v173.z) * v181.mat[2].z)
                           + (float)((float)((float)v29 - v173.y) * v181.mat[1].z));
            v185.x = (float)((float)v51 * v181.mat[0].x)
                   + (float)((float)((float)((float)v29 - v173.y) * v181.mat[1].x)
                           + (float)((float)((float)v31 - v173.z) * v181.mat[2].x));
            v185.y = (float)(v181.mat[0].y * (float)v51)
                   + (float)((float)((float)((float)v31 - v173.z) * v181.mat[2].y)
                           + (float)((float)((float)v29 - v173.y) * v181.mat[1].y));
            __asm { fsel      f1, f1, f4, f0 }
            v54 = __frsqrte(_FP1);
            v55 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54
                                                                                                * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5))
                                                                                        * (float)v54)
                                                                                - (float)1.5)
                                                                * (float)v54)
                                                        * (float)((float)((float)((float)v47 * (float)v47)
                                                                        + (float)((float)((float)v49 * (float)v49)
                                                                                + (float)((float)v48 * (float)v48)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v54
                                                                                        * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48)))
                                                                                                * (float)0.5))
                                                                                * (float)v54)
                                                                        - (float)1.5)
                                                        * (float)v54))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v54
                                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                                + (float)((float)((float)v49 * (float)v49)
                                                                                        + (float)((float)v48 * (float)v48)))
                                                                        * (float)0.5))
                                                        * (float)v54)
                                                - (float)1.5)
                                * (float)v54));
            v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5) * (float)v54)
                                                                                                * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5)
                                                                                                * (float)v54))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5))
                                                                                                * (float)v54)
                                                                                        - (float)1.5)
                                                                        * (float)v54))
                                                        * (float)((float)((float)((float)v47 * (float)v47)
                                                                        + (float)((float)((float)v49 * (float)v49)
                                                                                + (float)((float)v48 * (float)v48)))
                                                                * (float)0.5))
                                                * (float)v55)
                                        - (float)1.5)
                        * (float)v55);
            v57 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5) * (float)v54) * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5) * (float)v54))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54)
                                                                                                - (float)1.5)
                                                                                * (float)v54))
                                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                                + (float)((float)((float)v49 * (float)v49)
                                                                                        + (float)((float)v48 * (float)v48)))
                                                                        * (float)0.5))
                                                        * (float)v55)
                                                - (float)1.5)
                                * (float)v55)
                        * (float)v49);
            v58 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5) * (float)v54) * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54) - (float)1.5) * (float)v54))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v54 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) * (float)0.5)) * (float)v54)
                                                                                                - (float)1.5)
                                                                                * (float)v54))
                                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                                + (float)((float)((float)v49 * (float)v49)
                                                                                        + (float)((float)v48 * (float)v48)))
                                                                        * (float)0.5))
                                                        * (float)v55)
                                                - (float)1.5)
                                * (float)v55)
                        * (float)v47);
            v59 = (float)((float)v56 * (float)v48);
            v60 = (float)((float)((float)v58 * (float)v45) - (float)((float)v57 * (float)v43));
            v61 = (float)((float)((float)v59 * (float)v43) - (float)((float)v58 * (float)v44));
            v62 = (float)((float)((float)v57 * (float)v44) - (float)((float)v59 * (float)v45));
            _FP12 = (float)((float)((float)((float)v62 * (float)v62)
                                  + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                          - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f7, f12, f13, f0 }
            v65 = __frsqrte(_FP7);
            v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) * (float)0.5))
                                                                                        * (float)v65)
                                                                                - (float)1.5)
                                                                * (float)v65)
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)v61 * (float)v61)
                                                                                + (float)((float)v60 * (float)v60)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v65
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60)))
                                                                                                * (float)0.5))
                                                                                * (float)v65)
                                                                        - (float)1.5)
                                                        * (float)v65))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v65
                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                + (float)((float)((float)v61 * (float)v61)
                                                                                        + (float)((float)v60 * (float)v60)))
                                                                        * (float)0.5))
                                                        * (float)v65)
                                                - (float)1.5)
                                * (float)v65));
            v174.mat[2].x = (float)((float)-(float)((float)((float)((float)v66
                                                                  * (float)((float)((float)((float)v62 * (float)v62)
                                                                                  + (float)((float)((float)v61
                                                                                                  * (float)v61)
                                                                                          + (float)((float)v60
                                                                                                  * (float)v60)))
                                                                          * (float)0.5))
                                                          * (float)v66)
                                                  - (float)1.5)
                                  * (float)v66)
                          * (float)v62;
            v174.mat[2].y = (float)((float)-(float)((float)((float)((float)v66
                                                                  * (float)((float)((float)((float)v62 * (float)v62)
                                                                                  + (float)((float)((float)v61
                                                                                                  * (float)v61)
                                                                                          + (float)((float)v60
                                                                                                  * (float)v60)))
                                                                          * (float)0.5))
                                                          * (float)v66)
                                                  - (float)1.5)
                                  * (float)v66)
                          * (float)v60;
            v174.mat[2].z = (float)((float)-(float)((float)((float)((float)v66
                                                                  * (float)((float)((float)((float)v62 * (float)v62)
                                                                                  + (float)((float)((float)v61
                                                                                                  * (float)v61)
                                                                                          + (float)((float)v60
                                                                                                  * (float)v60)))
                                                                          * (float)0.5))
                                                          * (float)v66)
                                                  - (float)1.5)
                                  * (float)v66)
                          * (float)v61;
            v174.mat[1].y = (float)(v174.mat[2].z * (float)v43) - (float)(v174.mat[2].x * (float)v45);
            v174.mat[1].z = (float)(v174.mat[2].x * (float)v44) - (float)(v174.mat[2].y * (float)v43);
            v174.mat[1].x = (float)(v174.mat[2].y * (float)v45) - (float)(v174.mat[2].z * (float)v44);
            idMat3::operator*(this: &v192, result: &v174, a: &v181);
            v67 = v21;
            idTreeAnimator::SetJointAxis(
              this: ta,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_particleData->list[v67].jointIndex.value,
              type: JOINTMOD_MODEL_OVERRIDE,
              axis: &v192);
            v68 = (int)&p_particleData->list[v67];
            if ( *(_BYTE *)(v68 + 24) == 0 )
              idTreeAnimator::SetJointPos(
                this: ta,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*(unsigned __int16 *)(v68 + 12),
                type: JOINTMOD_MODEL_OVERRIDE,
                pos: &v185);
            width = clothDecl->width;
          }
        }
        break;
      case CLOTH_GENERIC:
        v69 = 0;
        if ( clothDecl->particleData.num > 0 )
        {
          v70 = 0;
          do
          {
            v71 = &p_particleData->list[v70];
            if ( v71->anchored )
            {
              idTreeAnimator::GetWorldSpaceJointTransform(
                this: ta,
                pose: DRIVER_MODEL,
                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v71->jointIndex.value,
                origin: v194,
                axis: &v192);
              idClothSim::SetAnchorPosition(this: clothSim, index: v69, org: v194);
            }
            ++v69;
            ++v70;
          }
          while ( v69 < clothDecl->particleData.num );
        }
        v72 = 1;
        if ( clothDecl->particleData.num > 1 )
        {
          v73 = 1;
          v74 = 1;
          do
          {
            if ( v72 < 0 || v72 >= clothSim->numClothParticles )
              v75 = (idClothParticle *)&vec3_origin;
            else
              v75 = &clothSim->cloth[v74];
            v76 = v75->origin.y;
            v77 = v75->origin.z;
            v78 = (int)&p_particleData->list[v73];
            x = v75->origin.x;
            v176 = v76;
            v177 = v77;
            v79 = *(_DWORD *)(v78 + 16);
            if ( v79 == -1 && *(_DWORD *)(v78 + 20) == -1 )
            {
              v174.mat[0].x = mat3_identity.mat[0].x;
              v174.mat[0].y = mat3_identity.mat[0].y;
              v174.mat[0].z = mat3_identity.mat[0].z;
              v174.mat[1].x = mat3_identity.mat[1].x;
              v174.mat[1].y = mat3_identity.mat[1].y;
              v174.mat[1].z = mat3_identity.mat[1].z;
              v174.mat[2].x = mat3_identity.mat[2].x;
              v174.mat[2].y = mat3_identity.mat[2].y;
              v174.mat[2].z = mat3_identity.mat[2].z;
            }
            else
            {
              if ( v79 < 0 || v79 >= clothSim->numClothParticles )
                v80 = (idClothParticle *)&vec3_origin;
              else
                v80 = &clothSim->cloth[v79];
              v81 = *(_DWORD *)(v78 + 20);
              v82 = (float)(v80->origin.y - v176);
              v83 = (float)(v80->origin.z - v177);
              _FP1 = (float)((float)((float)((float)(v80->origin.x - x) * (float)(v80->origin.x - x))
                                   + (float)((float)((float)(v80->origin.z - v177) * (float)(v80->origin.z - v177))
                                           + (float)((float)(v80->origin.y - v176) * (float)(v80->origin.y - v176))))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f11, f1, f2, f0 }
              v86 = __frsqrte(_FP11);
              v87 = (float)((float)-(float)((float)((float)((float)v86
                                                          * (float)((float)((float)((float)(v80->origin.x - x)
                                                                                  * (float)(v80->origin.x - x))
                                                                          + (float)((float)((float)(v80->origin.z - v177)
                                                                                          * (float)(v80->origin.z - v177))
                                                                                  + (float)((float)(v80->origin.y - v176)
                                                                                          * (float)(v80->origin.y - v176))))
                                                                  * (float)0.5))
                                                  * (float)v86)
                                          - (float)1.5)
                          * (float)v86);
              v88 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v86
                                                                                          * (float)((float)((float)((float)(v80->origin.x - x) * (float)(v80->origin.x - x)) + (float)((float)((float)v83 * (float)v83) + (float)((float)v82 * (float)v82)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v86)
                                                                          - (float)1.5)
                                                          * (float)v86)
                                                  * (float)((float)((float)((float)(v80->origin.x - x)
                                                                          * (float)(v80->origin.x - x))
                                                                  + (float)((float)((float)v83 * (float)v83)
                                                                          + (float)((float)v82 * (float)v82)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v86
                                                                                  * (float)((float)((float)((float)(v80->origin.x - x) * (float)(v80->origin.x - x))
                                                                                                  + (float)((float)((float)v83 * (float)v83) + (float)((float)v82 * (float)v82)))
                                                                                          * (float)0.5))
                                                                          * (float)v86)
                                                                  - (float)1.5)
                                                  * (float)v86))
                                  - (float)1.5);
              v89 = (float)((float)-(float)((float)((float)((float)((float)v88 * (float)v87)
                                                          * (float)((float)((float)((float)(v80->origin.x - x)
                                                                                  * (float)(v80->origin.x - x))
                                                                          + (float)((float)((float)(v80->origin.z - v177)
                                                                                          * (float)(v80->origin.z - v177))
                                                                                  + (float)((float)(v80->origin.y - v176)
                                                                                          * (float)(v80->origin.y - v176))))
                                                                  * (float)0.5))
                                                  * (float)((float)v88 * (float)v87))
                                          - (float)1.5)
                          * (float)((float)v88 * (float)v87));
              v90 = (float)((float)(v80->origin.x - x) * (float)v89);
              v91 = (float)((float)(v80->origin.y - v176) * (float)v89);
              v174.mat[1].x = (float)(v80->origin.x - x) * (float)v89;
              v174.mat[1].y = v91;
              v92 = (float)((float)v83 * (float)v89);
              v174.mat[1].z = (float)v83 * (float)v89;
              if ( v81 == -1 )
              {
                v93 = vec3_up.x;
                v94 = vec3_up.y;
                v95 = vec3_up.z;
              }
              else
              {
                if ( v81 < 0 || v81 >= clothSim->numClothParticles )
                  v96 = (idClothParticle *)&vec3_origin;
                else
                  v96 = &clothSim->cloth[v81];
                v97 = (float)(v76 - v96->origin.y);
                v98 = (float)(v77 - v96->origin.z);
                _FP6 = (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x))
                                     + (float)((float)((float)(v77 - v96->origin.z) * (float)(v77 - v96->origin.z))
                                             + (float)((float)(v76 - v96->origin.y) * (float)(v76 - v96->origin.y))))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                __asm { fsel      f10, f6, f8, f0 }
                v101 = __frsqrte(_FP10);
                v102 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                             * (float)v101)
                                                                                     - (float)1.5)
                                                                     * (float)v101)
                                                             * (float)((float)((float)((float)(x - v96->origin.x)
                                                                                     * (float)(x - v96->origin.x))
                                                                             + (float)((float)((float)v98 * (float)v98)
                                                                                     + (float)((float)v97 * (float)v97)))
                                                                     * (float)0.5))
                                                     * (float)((float)-(float)((float)((float)((float)v101
                                                                                             * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                     * (float)v101)
                                                                             - (float)1.5)
                                                             * (float)v101))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v101
                                                                     * (float)((float)((float)((float)(x - v96->origin.x)
                                                                                             * (float)(x - v96->origin.x))
                                                                                     + (float)((float)((float)v98 * (float)v98)
                                                                                             + (float)((float)v97 * (float)v97)))
                                                                             * (float)0.5))
                                                             * (float)v101)
                                                     - (float)1.5)
                                     * (float)v101));
                v103 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5)) * (float)v101) - (float)1.5) * (float)v101)
                                                                                             * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5)) * (float)v101) - (float)1.5)
                                                                                             * (float)v101))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                             * (float)v101)
                                                                                     - (float)1.5)
                                                                     * (float)v101))
                                                     * (float)((float)((float)((float)(x - v96->origin.x)
                                                                             * (float)(x - v96->origin.x))
                                                                     + (float)((float)((float)v98 * (float)v98)
                                                                             + (float)((float)v97 * (float)v97)))
                                                             * (float)0.5))
                                             * (float)v102)
                                     - (float)1.5);
                v104 = (float)((float)v103
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5)) * (float)v101)
                                                                                             - (float)1.5)
                                                                             * (float)v101)
                                                                     * (float)((float)((float)((float)(x - v96->origin.x)
                                                                                             * (float)(x - v96->origin.x))
                                                                                     + (float)((float)((float)v98 * (float)v98)
                                                                                             + (float)((float)v97 * (float)v97)))
                                                                             * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)v101 * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x)) + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97))) * (float)0.5))
                                                                                             * (float)v101)
                                                                                     - (float)1.5)
                                                                     * (float)v101))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v101
                                                                             * (float)((float)((float)((float)(x - v96->origin.x) * (float)(x - v96->origin.x))
                                                                                             + (float)((float)((float)v98 * (float)v98) + (float)((float)v97 * (float)v97)))
                                                                                     * (float)0.5))
                                                                     * (float)v101)
                                                             - (float)1.5)
                                             * (float)v101)));
                v93 = (float)((float)(x - v96->origin.x) * (float)v104);
                v94 = (float)((float)(v76 - v96->origin.y) * (float)v104);
                v95 = (float)((float)(v77 - v96->origin.z) * (float)v104);
              }
              v105 = (float)((float)((float)v93 * (float)v92) - (float)((float)v95 * (float)v90));
              v106 = (float)((float)((float)v94 * (float)v90) - (float)((float)v93 * (float)v91));
              v107 = (float)((float)((float)v95 * (float)v91) - (float)((float)v94 * (float)v92));
              _FP8 = (float)((float)((float)((float)v107 * (float)v107)
                                   + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f10, f8, f9, f0 }
              v110 = __frsqrte(_FP10);
              v111 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                           * (float)v110)
                                                                                   - (float)1.5)
                                                                   * (float)v110)
                                                           * (float)((float)((float)((float)v107 * (float)v107)
                                                                           + (float)((float)((float)v106 * (float)v106)
                                                                                   + (float)((float)v105 * (float)v105)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v110
                                                                                           * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                   * (float)v110)
                                                                           - (float)1.5)
                                                           * (float)v110))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v110
                                                                   * (float)((float)((float)((float)v107 * (float)v107)
                                                                                   + (float)((float)((float)v106 * (float)v106)
                                                                                           + (float)((float)v105 * (float)v105)))
                                                                           * (float)0.5))
                                                           * (float)v110)
                                                   - (float)1.5)
                                   * (float)v110));
              v112 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110) * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110) - (float)1.5) * (float)v110))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v110 * (float)((float)((float)((float)v107 * (float)v107) + (float)((float)((float)v106 * (float)v106) + (float)((float)v105 * (float)v105))) * (float)0.5)) * (float)v110)
                                                                                           - (float)1.5)
                                                                           * (float)v110))
                                                           * (float)((float)((float)((float)v107 * (float)v107)
                                                                           + (float)((float)((float)v106 * (float)v106)
                                                                                   + (float)((float)v105 * (float)v105)))
                                                                   * (float)0.5))
                                                   * (float)v111)
                                           - (float)1.5)
                           * (float)v111);
              v174.mat[0].x = (float)v112 * (float)v107;
              v113 = (float)((float)v105 * (float)v112);
              v174.mat[0].y = (float)v105 * (float)v112;
              v174.mat[0].z = (float)v106 * (float)v112;
              v114 = (float)((float)((float)v90 * v174.mat[0].z) - (float)((float)v92 * v174.mat[0].x));
              v115 = (float)((float)((float)v91 * v174.mat[0].x) - (float)((float)v90 * (float)v113));
              v116 = (float)((float)((float)v92 * (float)v113) - (float)((float)v91 * v174.mat[0].z));
              _FP8 = (float)((float)((float)((float)v116 * (float)v116)
                                   + (float)((float)((float)v115 * (float)v115) + (float)((float)v114 * (float)v114)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              __asm { fsel      f6, f8, f9, f0 }
              v119 = __frsqrte(_FP6);
              v120 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v115 * (float)v115) + (float)((float)v114 * (float)v114))) * (float)0.5))
                                                                                           * (float)v119)
                                                                                   - (float)1.5)
                                                                   * (float)v119)
                                                           * (float)((float)((float)((float)v116 * (float)v116)
                                                                           + (float)((float)((float)v115 * (float)v115)
                                                                                   + (float)((float)v114 * (float)v114)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v119
                                                                                           * (float)((float)((float)((float)v116 * (float)v116) + (float)((float)((float)v115 * (float)v115) + (float)((float)v114 * (float)v114))) * (float)0.5))
                                                                                   * (float)v119)
                                                                           - (float)1.5)
                                                           * (float)v119))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v119
                                                                   * (float)((float)((float)((float)v116 * (float)v116)
                                                                                   + (float)((float)((float)v115 * (float)v115)
                                                                                           + (float)((float)v114 * (float)v114)))
                                                                           * (float)0.5))
                                                           * (float)v119)
                                                   - (float)1.5)
                                   * (float)v119));
              v174.mat[2].x = (float)((float)-(float)((float)((float)((float)v120
                                                                    * (float)((float)((float)((float)v116 * (float)v116)
                                                                                    + (float)((float)((float)v115 * (float)v115)
                                                                                            + (float)((float)v114 * (float)v114)))
                                                                            * (float)0.5))
                                                            * (float)v120)
                                                    - (float)1.5)
                                    * (float)v120)
                            * (float)v116;
              v174.mat[2].y = (float)v114
                            * (float)((float)-(float)((float)((float)((float)v120
                                                                    * (float)((float)((float)((float)v116 * (float)v116)
                                                                                    + (float)((float)((float)v115 * (float)v115)
                                                                                            + (float)((float)v114 * (float)v114)))
                                                                            * (float)0.5))
                                                            * (float)v120)
                                                    - (float)1.5)
                                    * (float)v120);
              v174.mat[2].z = (float)v115
                            * (float)((float)-(float)((float)((float)((float)v120
                                                                    * (float)((float)((float)((float)v116 * (float)v116)
                                                                                    + (float)((float)((float)v115 * (float)v115)
                                                                                            + (float)((float)v114 * (float)v114)))
                                                                            * (float)0.5))
                                                            * (float)v120)
                                                    - (float)1.5)
                                    * (float)v120);
            }
            v188.y = (float)(v181.mat[0].y * (float)(x - v173.x))
                   + (float)((float)((float)(v77 - v173.z) * v181.mat[2].y)
                           + (float)((float)(v76 - v173.y) * v181.mat[1].y));
            v188.x = (float)((float)(x - v173.x) * v181.mat[0].x)
                   + (float)((float)((float)(v76 - v173.y) * v181.mat[1].x)
                           + (float)((float)(v77 - v173.z) * v181.mat[2].x));
            v188.z = (float)(v181.mat[0].z * (float)(x - v173.x))
                   + (float)((float)((float)(v77 - v173.z) * v181.mat[2].z)
                           + (float)((float)(v76 - v173.y) * v181.mat[1].z));
            idMat3::operator*(this: &v192, result: &v174, a: &v181);
            idTreeAnimator::SetJointAxis(
              this: ta,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_particleData->list[v73].jointIndex.value,
              type: JOINTMOD_MODEL_OVERRIDE,
              axis: &v192);
            idTreeAnimator::SetJointPos(
              this: ta,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_particleData->list[v73].jointIndex.value,
              type: JOINTMOD_MODEL_OVERRIDE,
              pos: &v188);
            ++v72;
            ++v74;
            ++v73;
          }
          while ( v72 < clothDecl->particleData.num );
        }
        break;
      case CLOTH_ROPE:
        p_ropeData = &clothDecl->ropeData;
        v122 = 0;
        if ( clothDecl->ropeData.num > 0 )
        {
          v123 = 0;
          do
          {
            if ( p_ropeData->list[v123].positions.num <= 32 )
            {
              v197.size = 32;
              v197.num = 0;
              v197.granularity = 1;
              v197.list = (idMat3 *)&v198;
              v197.memTag = 5;
              v197.listStatic = 1;
              v195.size = 32;
              v195.num = 0;
              v195.granularity = 1;
              v195.list = (idVec3 *)&v196;
              v195.memTag = 5;
              v195.listStatic = 1;
              idClothSim::GetRopeParticleOriginAxis(this: clothSim, index: v122, originList: &v195, axisList: &v197);
              list = p_ropeData->list;
              v125 = 0;
              num = p_ropeData->list[v123].positions.num;
              v174.mat[0].x = v183.mat[0].x;
              v174.mat[0].y = v183.mat[1].x;
              v174.mat[0].z = v183.mat[2].x;
              v174.mat[1].x = v183.mat[0].y;
              v174.mat[1].y = v183.mat[1].y;
              v174.mat[1].z = v183.mat[2].y;
              v174.mat[2].x = v183.mat[0].z;
              v174.mat[2].y = v183.mat[1].z;
              v174.mat[2].z = v183.mat[2].z;
              if ( num > 0 )
              {
                v127 = 0;
                v128 = 0;
                do
                {
                  v129 = &v195.list[v128];
                  v130 = (float)(v195.list[v128].x - v173.x);
                  v131 = (float)(v195.list[v128].y - v173.y);
                  v133 = v174.mat[0].x;
                  v134 = (float)((float)(v174.mat[2].y * (float)(v195.list[v128].z - v173.z))
                               + (float)(v174.mat[0].y * (float)(v195.list[v128].x - v173.x)));
                  v135 = (float)((float)(v174.mat[2].x * (float)(v129->z - v173.z))
                               + (float)(v174.mat[1].x * (float)(v129->y - v173.y)));
                  v132 = v174.mat[1].y;
                  v129->z = (float)(v174.mat[1].z * (float)(v195.list[v128].y - v173.y))
                          + (float)((float)(v174.mat[2].z * (float)(v195.list[v128].z - v173.z))
                                  + (float)(v174.mat[0].z * (float)(v195.list[v128].x - v173.x)));
                  v129->y = (float)((float)v132 * (float)v131) + (float)v134;
                  v129->x = (float)((float)v133 * (float)v130) + (float)v135;
                  v136 = &v197.list[v127];
                  *v136 = *idMat3::operator*(this: &v192, result: &v197.list[v127], a: &v174);
                  ++v125;
                  ++v128;
                  ++v127;
                  list = p_ropeData->list;
                  num = p_ropeData->list[v123].positions.num;
                }
                while ( v125 < num );
              }
              v137 = 0;
              if ( num > 0 )
              {
                v138 = 0;
                v139 = 0;
                do
                {
                  v140 = &list[v123];
                  if ( v137 < v140->positions.num - 1 )
                  {
                    idTreeAnimator::SetJointAxis(
                      this: ta,
                      pose: (animationPose_t)0,
                      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v140->indexOfJointToAttachTo.list[v140->indexOfJointToAttachTo.num - v137 - 1].value,
                      type: JOINTMOD_MODEL_OVERRIDE,
                      axis: &v197.list[v139]);
                    if ( g_debugClothAxis.valueInteger > 0 )
                    {
                      v141 = v195.list;
                      v142 = (float)((float)(v183.mat[1].y * v141[v138].y)
                                   + (float)((float)(v183.mat[0].y * v141[v138].x)
                                           + (float)(v183.mat[2].y * v141[v138].z)));
                      v143 = (float)((float)(v141[v138].x * v183.mat[0].x)
                                   + (float)((float)(v141[v138].y * v183.mat[1].x)
                                           + (float)(v183.mat[2].x * v141[v138].z)));
                      v180 = v173.z
                           + (float)((float)(v183.mat[1].z * v141[v138].y)
                                   + (float)((float)(v183.mat[0].z * v141[v138].x)
                                           + (float)(v183.mat[2].z * v141[v138].z)));
                      v179 = v173.y + (float)v142;
                      v178 = (float)v143 + v173.x;
                      idMat3::operator*(this: &v181, result: &v197.list[v139], a: &v183);
                      v144 = gameLocal->GetRenderWorld(this: gameLocal);
                      v191[3] = 1.0;
                      v191[0] = 1.0;
                      v191[1] = 0.0;
                      v191[2] = 0.0;
                      v187[2] = (float)(v181.mat[0].z * (float)7.0) + v180;
                      v187[1] = (float)(v181.mat[0].y * (float)7.0) + v179;
                      v187[0] = (float)(v181.mat[0].x * (float)7.0) + v178;
                      v144->DebugLine(
                        this: v144,
                        a2: (const idVec4 *)v191,
                        a3: (const idVec3 *)&v178,
                        a4: (const idVec3 *)v187,
                        a5: 0,
                        a6: false);
                      v145 = gameLocal->GetRenderWorld(this: gameLocal);
                      v189[0] = 0.0;
                      v189[1] = 1.0;
                      v189[2] = 0.0;
                      v189[3] = 1.0;
                      v184[2] = (float)(v181.mat[1].z * (float)7.0) + v180;
                      v184[1] = (float)(v181.mat[1].y * (float)7.0) + v179;
                      v184[0] = (float)(v181.mat[1].x * (float)7.0) + v178;
                      v145->DebugLine(
                        this: v145,
                        a2: (const idVec4 *)v189,
                        a3: (const idVec3 *)&v178,
                        a4: (const idVec3 *)v184,
                        a5: 0,
                        a6: false);
                      v146 = gameLocal->GetRenderWorld(this: gameLocal);
                      v190[0] = 0.0;
                      v190[1] = 0.0;
                      v190[2] = 1.0;
                      v190[3] = 1.0;
                      v186[2] = (float)(v181.mat[2].z * (float)7.0) + v180;
                      v186[1] = (float)(v181.mat[2].y * (float)7.0) + v179;
                      v186[0] = (float)(v181.mat[2].x * (float)7.0) + v178;
                      v146->DebugLine(
                        this: v146,
                        a2: (const idVec4 *)v190,
                        a3: (const idVec3 *)&v178,
                        a4: (const idVec3 *)v186,
                        a5: 0,
                        a6: false);
                    }
                  }
                  idTreeAnimator::SetJointPos(
                    this: ta,
                    pose: (animationPose_t)0,
                    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)p_ropeData->list[v123].indexOfJointToAttachTo.list[p_ropeData->list[v123].indexOfJointToAttachTo.num - v137 - 1].value,
                    type: JOINTMOD_MODEL_OVERRIDE,
                    pos: &v195.list[v138]);
                  list = p_ropeData->list;
                  ++v137;
                  ++v139;
                  ++v138;
                }
                while ( v137 < p_ropeData->list[v123].positions.num );
              }
              idClothSim::SetAnchorPosition(this: clothSim, index: v122, org: &v173);
              idClothSim::SetAnchorAxis(this: clothSim, index: v122, modelAxis: &v183);
              if ( v195.listStatic == 0 || v195.listStatic == 2 )
              {
                if ( v195.list != nullptr )
                  idMem::Free(this: &mem, ptr: v195.list, align: ALIGN_16);
                v195.list = nullptr;
                v195.size = 0;
              }
              v195.num = 0;
              if ( v197.listStatic == 0 || v197.listStatic == 2 )
              {
                if ( v197.list != nullptr )
                  idMem::Free(this: &mem, ptr: v197.list, align: ALIGN_16);
                v197.list = nullptr;
                v197.size = 0;
              }
              v197.num = 0;
            }
            else
            {
              idLib::Warning(fmt: "Too many rope particles");
            }
            ++v122;
            ++v123;
          }
          while ( v122 < p_ropeData->num );
        }
        break;
      default:
        break;
    }
    v147 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idTreeAnimator::BlendTreeInternal(
      this: ta,
      currentTime: GameMs,
      previousTime: PreviousGameMs,
      gameMsPerFrame: GameMsPerFrame,
      ticksPerSec: v147,
      tree: nullptr,
      parallelJobList: gameLocal->parallelJobList,
      localR: nullptr,
      localS: v151,
      localT: v152,
      localU: v153,
      a12: v154,
      a13: v155,
      a14: v156,
      a15: v157,
      a16: v158,
      a17: v159,
      a18: v160,
      a19: v161,
      a20: v162,
      a21: v163,
      a22: v164,
      a23: v165,
      a24: v166,
      a25: v167,
      a26: v168,
      a27: v169,
      a28: nullptr,
      a29: v170,
      a30: nullptr,
      a31: v171,
      a32: nullptr);
  }
  else
  {
    idLib::Warning(fmt: "%s called with null treeanimator or clothSim", "idClothSimManager::UpdateJointsWithClothSim");
  }
}


// ========================================================================
// __unwind$489133
// EA  : 0x82C17DD4
// RVA : 0x00C17DD4
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_489133()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2320 + 928));
}


// ========================================================================
// __unwind$489134
// EA  : 0x82C17DFC
// RVA : 0x00C17DFC
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_489134()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2320 + 528));
}


// ========================================================================
// ?UpdateWeaponTraces@idClothSimManager@@QAAXPAVidClothSim@@@Z
// EA  : 0x82C17E30
// RVA : 0x00C17E30
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::UpdateWeaponTraces(idClothSimManager *this, idClothSim *clothSim)
{
  int v3; // r28
  double z; // fp13
  double y; // fp12
  double x; // fp11
  double v7; // fp10
  double v8; // fp9
  double v9; // fp7
  idWeaponTraceManager *WeaponTraceMgr; // r3
  bool v11; // r6
  int v12; // r29
  idBounds v13; // [sp+50h] [-200h] BYREF
  idBounds *p_clothBounds; // [sp+68h] [-1E8h]
  idList<idVehicleState *,5> v15; // [sp+70h] [-1E0h] BYREF
  _DWORD v16[104]; // [sp+80h] [-1D0h] BYREF

  if ( clothSim != nullptr )
  {
    v3 = 0;
    v16[12] = 0x1FFF;
    v15.granularity = 1;
    v15.num = 0;
    v15.size = 6;
    v15.list = (idVehicleState **)v16;
    v15.memTag = 5;
    v15.listStatic = 1;
    v16[13] = 0x1FFF;
    v16[29] = 0x1FFF;
    v16[30] = 0x1FFF;
    v16[46] = 0x1FFF;
    v16[47] = 0x1FFF;
    v16[63] = 0x1FFF;
    v16[64] = 0x1FFF;
    v16[80] = 0x1FFF;
    v16[81] = 0x1FFF;
    v16[97] = 0x1FFF;
    v16[98] = 0x1FFF;
    z = clothSim->clothBounds.b[1].z;
    y = clothSim->clothBounds.b[1].y;
    x = clothSim->clothBounds.b[1].x;
    v7 = clothSim->clothBounds.b[0].z;
    p_clothBounds = &clothSim->clothBounds;
    v8 = clothSim->clothBounds.b[0].y;
    v9 = clothSim->clothBounds.b[0].x;
    v13.b[1].z = (float)z + (float)5.0;
    v13.b[1].y = (float)y + (float)5.0;
    v13.b[1].x = (float)x + (float)5.0;
    v13.b[0].z = (float)v7 - (float)5.0;
    v13.b[0].y = (float)v8 - (float)5.0;
    v13.b[0].x = (float)v9 - (float)5.0;
    WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
    idWeaponTraceManager::GetCollisions(this: WeaponTraceMgr, inBounds: &v13, outTraces: &v15);
    if ( v15.num > 0 )
    {
      v12 = 0;
      do
      {
        if ( v15.list[v12 + 16] != (idVehicleState *)2 )
          idClothSim::AddWeaponTrace(
            this: clothSim,
            start: (const idVec3 *)&v15.list[v12],
            dir: (const idVec3 *)&v15.list[v12 + 9],
            strength: 0.0,
            causesHoles: v11,
            a6: false);
        ++v3;
        v12 += 17;
      }
      while ( v3 < v15.num );
    }
    if ( (v15.listStatic == 0 || v15.listStatic == 2) && v15.list != nullptr )
      idMem::Free(this: &mem, ptr: v15.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$490650
// EA  : 0x82C17FB0
// RVA : 0x00C17FB0
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_490650()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 592 + 112));
}


// ========================================================================
// ?GetGeneralOriginAxis@idClothSimManager@@QAAXPAVidClothSim@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C17FE0
// RVA : 0x00C17FE0
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::GetGeneralOriginAxis(
        idClothSimManager *this,
        idClothSim *clothSim,
        idVec3 *origin,
        idMat3 *axis)
{
  idVec3 *v4; // r29
  idVec3 *v5; // r28
  idVec3 *list; // r10
  float *v9; // r11
  idList<idVec3,5> v10; // [sp+60h] [-650h] BYREF
  int v11; // [sp+70h] [-640h] BYREF
  idList<idMat3,5> v12; // [sp+1F0h] [-4C0h] BYREF
  int v13; // [sp+200h] [-4B0h] BYREF

  v4 = &axis->mat[1];
  v5 = &axis->mat[2];
  *origin = vec3_origin;
  *axis = mat3_identity;
  if ( clothSim != nullptr )
  {
    if ( clothSim->clothDecl->type == CLOTH_ROPE )
    {
      if ( clothSim->clothDecl->ropeData.list->positions.num <= 32 )
      {
        v12.granularity = 1;
        v12.size = 32;
        v12.num = 0;
        v12.memTag = 5;
        v12.list = (idMat3 *)&v13;
        v12.listStatic = 1;
        v10.size = 32;
        v10.num = 0;
        v10.granularity = 1;
        v10.list = (idVec3 *)&v11;
        v10.memTag = 5;
        v10.listStatic = 1;
        idClothSim::GetRopeParticleOriginAxis(this: clothSim, index: 0, originList: &v10, axisList: &v12);
        list = v10.list;
        v9 = (float *)v12.list;
        origin->x = v10.list->x;
        origin->y = list->y;
        origin->z = list->z;
        axis->mat[0].x = *v9;
        axis->mat[0].y = v9[1];
        axis->mat[0].z = v9[2];
        v4->x = v9[3];
        v4->y = v9[4];
        v4->z = v9[5];
        v5->x = v9[6];
        v5->y = v9[7];
        v5->z = v9[8];
        idMat3::OrthoNormalizeSelf(this: axis);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v10);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v12);
      }
      else
      {
        idLib::Warning(fmt: "Too many rope particles");
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idClothSimManager::GetGeneralOriginAxis() called with NULL clothsim");
  }
}


// ========================================================================
// __unwind$490998_0
// EA  : 0x82C181CC
// RVA : 0x00C181CC
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_490998_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1712 + 496));
}


// ========================================================================
// __unwind$490999_0
// EA  : 0x82C181F4
// RVA : 0x00C181F4
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void _unwind_490999_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1712 + 96));
}


// ========================================================================
// ?AddCloth@idClothSimManager@@QAAXPBVidDeclCloth@@@Z
// EA  : 0x82C18228
// RVA : 0x00C18228
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall idClothSimManager::AddCloth(idClothSimManager *this, const idDeclCloth *decl)
{
  int v3; // r6
  int v4; // r10
  int v5; // r11
  idClothSimManager::clothSims_t *list; // r9
  const idDeclCloth **p_clothDecl; // r9
  idSerializerLog::compressionEntry_t *v8; // r30
  idClothSim *v9; // r3
  idClothSim *v10; // r3
  int num; // [sp+50h] [-30h]

  if ( decl == nullptr )
    idLib::Error(fmt: "idClothSimManager::AddCloth() - NULL idDeclEntityDef passed in.");
  num = this->cloth.num;
  if ( num < this->cloth.size )
  {
    v3 = 0;
    v4 = 0;
    if ( num <= 0 )
      goto LABEL_11;
    v5 = 0;
    list = this->cloth.list;
    do
    {
      p_clothDecl = &list->clothSim->clothDecl;
      if ( p_clothDecl != nullptr && *p_clothDecl == decl )
        ++v3;
      ++v4;
      list = &this->cloth.list[++v5];
    }
    while ( v4 < num );
    if ( v3 < 4 )
    {
LABEL_11:
      v8 = idList<idSerializerLog::compressionEntry_t,44>::Alloc((idList<idSerializerLog::compressionEntry_t,44> *)this);
      v9 = (idClothSim *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                           size: 0x114u,
                           tag: TAG_NEW,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      if ( v9 != nullptr )
        v10 = idClothSim::idClothSim(this: v9, clothSystem: decl);
      else
        v10 = nullptr;
      v8->csize = (int)v10;
      v8->objID = 0;
    }
  }
}


// ========================================================================
// $LN30_1
// EA  : 0x82C18324
// RVA : 0x00C18324
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __fastcall _LN30_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'g_debugClothAxis''
// EA  : 0x833759A0
// RVA : 0x013759A0
// PDB : w:\tech5\tungsten\game\entities\clothsimmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugClothAxis__()
{
  idCVar::idCVar(
    this: &g_debugClothAxis,
    name: "g_debugClothAxis",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugClothAxis__);
}

