
// ========================================================================
// ?GetVolume@Surfer3D@bfx@@QBAPBVVolume@2@XZ
// EA  : 0x832C0B88
// RVA : 0x012C0B88
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxsurfer3d.cpp
// ========================================================================

const bfx::Volume *__fastcall bfx::Surfer3D::GetVolume(bfx::Surfer3D *this)
{
  bfx::HandleProxy *m_pProxy; // r11

  m_pProxy = this->m_volume.m_pProxy;
  if ( m_pProxy != nullptr )
    return (const bfx::Volume *)m_pProxy->m_pTarget;
  else
    return nullptr;
}


// ========================================================================
// ?SetPosAndVolume@Surfer3D@bfx@@QAAXABVVec3@2@PBVVolume@2@@Z
// EA  : 0x832C0BA8
// RVA : 0x012C0BA8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxsurfer3d.cpp
// ========================================================================

void __fastcall bfx::Surfer3D::SetPosAndVolume(bfx::Surfer3D *this, const bfx::Vec3 *pos, bfx::Vec3 *pVolume)
{
  bfx::Volume *ClosestPos; // r3
  char v6; // [sp+50h] [-30h] BYREF

  if ( pVolume != nullptr )
  {
    ClosestPos = bfx::Volume::GetClosestPos(this: (bfx::Volume *)&v6, result: pVolume, pos);
    *(bfx::HandleTargetBase *)&this->m_pos.m_x = ClosestPos->bfx::HandleTargetBase;
    this->m_pos.m_z = *(float *)&ClosestPos->m_pParentGraph;
    bfx::Handle<bfx::MoverImpl>::operator=(
      this: (bfx::Handle<bfx::LinkBase> *)&this->m_volume,
      pTarget: (bfx::LinkBase *)pVolume);
    this->m_iFace0 = -1;
    this->m_state = FREE;
    this->m_iFace1 = -1;
    this->m_iFace2 = -1;
  }
  else
  {
    this->m_pos = *pos;
  }
}


// ========================================================================
// ?MoveOnce@Surfer3D@bfx@@AAAMAAVVec3@2@M@Z
// EA  : 0x832C0C50
// RVA : 0x012C0C50
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxsurfer3d.cpp
// ========================================================================

float __fastcall bfx::Surfer3D::MoveOnce(bfx::Surfer3D *this, bfx::Vec3 *vel, double simTime)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::Handle<bfx::LinkBase> *p_m_volume; // r21
  bfx::Volume *m_pTarget; // r26
  bfx::Surfer3D::State m_state; // r11
  double v10; // fp30
  double v11; // fp29
  double v12; // fp31
  double v13; // fp27
  bfx::Vec3 *p_m_pos; // r29
  double v15; // fp10
  double v16; // fp9
  bfx::Portal *v17; // r3
  double m_y; // fp0
  double v19; // fp11
  double m_z; // fp13
  bool v21; // cr58
  double v22; // fp9
  double v23; // fp7
  double v24; // fp31
  const bfx::Volume *OtherVolume; // r3
  bfx::LinkBase *v26; // r29
  double v27; // fp1
  const bfx::Portal *v28; // r11
  double v29; // fp11
  double v30; // fp10
  double m_x; // fp9
  int v32; // r10
  float v33; // r5
  float v34; // r4
  float v35; // r3
  float v36; // r10
  double v37; // fp4
  double v38; // fp5
  double v39; // fp0
  double v40; // fp13
  double v41; // fp12
  double v42; // fp13
  double v43; // fp11
  unsigned int v44; // r11
  double v45; // fp10
  float v46; // r5
  float v47; // r4
  float v48; // r3
  double v49; // fp9
  double v50; // fp31
  double v51; // fp30
  double v52; // fp29
  int v53; // r23
  double v54; // fp27
  int v55; // r25
  bfx::PortalRecord *v56; // r11
  bfx::Portal *m_pPortal; // r29
  bfx::LinkBase *v58; // r27
  bfx::Surfer3D_vtbl *v59; // r28
  const bfx::Volume *v60; // r3
  double v61; // fp12
  double v62; // fp11
  double v63; // fp7
  double v64; // fp6
  double v65; // fp5
  double v66; // fp31
  double v67; // fp30
  double v68; // fp29
  double v69; // fp27
  double v70; // fp10
  double v71; // fp9
  bfx::Portal *v72; // r3
  double v73; // fp0
  double v74; // fp11
  bool v75; // cr58
  double v76; // fp9
  double v77; // fp12
  double v78; // fp7
  double v79; // fp31
  const bfx::Volume *v80; // r3
  bfx::LinkBase *v81; // r29
  const bfx::Portal *v82; // r11
  double v83; // fp11
  double v84; // fp10
  double v85; // fp9
  int v86; // r10
  float v87; // r5
  float v88; // r4
  float v89; // r3
  float v90; // r10
  double v91; // fp4
  double v92; // fp5
  bfx::VolumeResource *m_pRes; // r11
  double v94; // fp13
  double v95; // fp12
  double v96; // fp0
  float *v97; // r11
  float m_d; // r7
  double v99; // fp9
  float v100; // r4
  float v101; // r10
  float v102; // r9
  float v103; // r5
  double v104; // fp25
  double v105; // fp24
  float v106; // r4
  double v107; // fp11
  float v108; // r3
  double v109; // fp26
  double v110; // fp31
  double v111; // fp30
  bool v112; // r10
  double v113; // fp29
  bool v114; // r11
  bool v115; // r9
  unsigned int m_iFace0; // r7
  int v117; // r23
  double v118; // fp27
  int v119; // r25
  bfx::PortalRecord *v120; // r11
  unsigned int m_planeIndex; // r10
  bfx::Portal *v122; // r29
  bfx::LinkBase *v123; // r27
  bfx::Surfer3D_vtbl *v124; // r28
  const bfx::Volume *v125; // r3
  double v126; // fp6
  double v127; // fp5
  double v128; // fp4
  double v131; // fp11
  double v132; // fp10
  double v133; // fp8
  double v134; // fp31
  double v135; // fp30
  double v136; // fp29
  double v137; // fp26
  bfx::Vec3 *v138; // r29
  double v139; // fp10
  double v140; // fp9
  bfx::Portal *v141; // r3
  double v142; // fp0
  double v143; // fp11
  bool v144; // cr58
  double v145; // fp9
  double v146; // fp12
  double v147; // fp7
  double v148; // fp31
  const bfx::Volume *v149; // r3
  bfx::LinkBase *v150; // r29
  const bfx::Portal *v151; // r11
  double v152; // fp13
  double v153; // fp12
  bfx::VolumeResource *v154; // r11
  double v155; // fp13
  double v156; // fp12
  float *p_m_x; // r4
  double v158; // fp0
  float *v159; // r9
  float v160; // r29
  float *v161; // r11
  float v162; // r3
  float v163; // r5
  double v164; // fp9
  float v165; // r10
  float v166; // r8
  float v167; // r6
  float v168; // r29
  float v169; // r5
  double v170; // fp11
  float v171; // r3
  int v172; // r11
  int v173; // r9
  bool v174; // r9
  bool v175; // r8
  bool v176; // r11
  bool v177; // r10
  unsigned int v178; // r6
  bool v179; // r10
  unsigned int v180; // r6
  bool v181; // r10
  unsigned int m_iFace1; // r6
  bfx::Portal *v184; // [sp+50h] [-100h] BYREF
  bfx::Portal *v185; // [sp+54h] [-FCh] BYREF
  bfx::Vec3 v186; // [sp+58h] [-F8h] BYREF
  bfx::Vec3 v187; // [sp+70h] [-E0h] BYREF
  int v188; // [sp+7Ch] [-D4h]
  bfx::Vec3 v189; // [sp+80h] [-D0h] BYREF
  int v190; // [sp+8Ch] [-C4h]
  float v191; // [sp+90h] [-C0h]
  float v192; // [sp+94h] [-BCh]
  float v193; // [sp+98h] [-B8h]
  float v194; // [sp+9Ch] [-B4h]

  m_pProxy = this->m_volume.m_pProxy;
  p_m_volume = (bfx::Handle<bfx::LinkBase> *)&this->m_volume;
  if ( m_pProxy != nullptr )
    m_pTarget = (bfx::Volume *)m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  if ( m_pTarget == nullptr )
    goto LABEL_15;
  m_state = this->m_state;
  switch ( m_state )
  {
    case FREE:
      v10 = (float)(vel->m_y * (float)simTime);
      v11 = (float)(vel->m_z * (float)simTime);
      v12 = (float)(vel->m_x * (float)simTime);
      v13 = __fsqrts((float)((float)((float)(vel->m_x * (float)simTime) * (float)(vel->m_x * (float)simTime))
                           + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))));
      if ( v13 < (float)(bfx::GetScale() * (float)0.0009765625) )
      {
LABEL_15:
        v27 = 0.0;
        break;
      }
      p_m_pos = &this->m_pos;
      v15 = (float)(this->m_pos.m_y + (float)v10);
      v16 = (float)(this->m_pos.m_z + (float)v11);
      v186.m_x = this->m_pos.m_x + (float)v12;
      v186.m_y = v15;
      v186.m_z = v16;
      if ( (unsigned __int8)bfx::Volume::ProbeFrom(
                              this: m_pTarget,
                              startPos: &this->m_pos,
                              endPos: &v186,
                              hitPlaneIndex: (unsigned int *)&v185,
                              pHitPortal: (const bfx::Portal **)&v184,
                              ignorePlaneIndex0: -1,
                              ignorePlaneIndex1: -1) != 0 )
      {
        v17 = v184;
        m_y = v186.m_y;
        v19 = (float)(v186.m_y - this->m_pos.m_y);
        m_z = v186.m_z;
        v21 = v184 == nullptr;
        v22 = (float)(v186.m_z - this->m_pos.m_z);
        v23 = (float)(v186.m_x - p_m_pos->m_x);
        p_m_pos->m_x = v186.m_x;
        this->m_pos.m_y = m_y;
        this->m_pos.m_z = m_z;
        v24 = __fsqrts((float)((float)((float)v23 * (float)v23)
                             + (float)((float)((float)v22 * (float)v22) + (float)((float)v19 * (float)v19))));
        if ( !v21
          && (OtherVolume = bfx::Portal::GetOtherVolume(this: v17, vol: m_pTarget),
              v26 = (bfx::LinkBase *)OtherVolume,
              OtherVolume != nullptr)
          && this->OkToMoveIntoVolume(this, a2: OtherVolume) )
        {
          bfx::Handle<bfx::MoverImpl>::operator=(this: p_m_volume, pTarget: v26);
          v27 = (float)((float)((float)((float)v13 - (float)v24) / (float)v13) * (float)simTime);
        }
        else
        {
          v28 = v185;
          v29 = vel->m_y;
          v30 = vel->m_z;
          m_x = vel->m_x;
          v32 = (int)m_pTarget->m_pRes + 16 * (_DWORD)v185;
          v33 = *(float *)(v32 + 12);
          v34 = *(float *)(v32 + 16);
          v35 = *(float *)(v32 + 20);
          v36 = *(float *)(v32 + 24);
          v191 = v33;
          v192 = v34;
          v193 = v35;
          v194 = v36;
          v37 = (float)(v192
                      * (float)((float)((float)m_x * v33)
                              + (float)((float)(v35 * (float)v30) + (float)(v192 * (float)v29))));
          v38 = (float)((float)((float)((float)m_x * v191)
                              + (float)((float)(v35 * (float)v30) + (float)(v34 * (float)v29)))
                      * v191);
          vel->m_z = (float)v30
                   - (float)(v35
                           * (float)((float)((float)m_x * v33)
                                   + (float)((float)(v35 * (float)v30) + (float)(v34 * (float)v29))));
          vel->m_y = (float)v29 - (float)v37;
          vel->m_x = (float)m_x - (float)v38;
          this->m_state = ON_FACE;
          this->m_iFace0 = (unsigned int)v28;
          v27 = (float)((float)((float)((float)v13 - (float)v24) / (float)v13) * (float)simTime);
        }
        break;
      }
      v39 = v186.m_x;
      v40 = v186.m_y;
      v41 = v186.m_z;
LABEL_14:
      p_m_pos->m_x = v39;
      p_m_pos->m_y = v40;
      p_m_pos->m_z = v41;
      goto LABEL_15;
    case ON_FACE:
      v42 = vel->m_y;
      v43 = vel->m_z;
      v44 = (unsigned int)m_pTarget->m_pRes + 16 * this->m_iFace0;
      v45 = vel->m_x;
      v46 = *(float *)(v44 + 12);
      v47 = *(float *)(v44 + 16);
      v48 = *(float *)(v44 + 20);
      v49 = (float)((float)(vel->m_z * vel->m_z) + (float)(vel->m_y * vel->m_y));
      v194 = *(float *)(v44 + 24);
      v191 = v46;
      v192 = v47;
      v193 = v48;
      v50 = v47;
      v51 = v48;
      v52 = v46;
      if ( (float)((float)((float)v45 * v46) + (float)((float)(v48 * (float)v43) + (float)(v47 * (float)v42))) < -(float)((float)__fsqrts((float)((float)((float)v45 * (float)v45) + (float)v49)) * (float)0.0009765625) )
        goto LABEL_18;
      v53 = 0;
      v54 = (float)(bfx::GetScale() * (float)0.0078125);
      if ( m_pTarget->m_portals.m_size <= 0 )
      {
LABEL_25:
        v61 = vel->m_z;
        v62 = vel->m_x;
        v63 = (float)((float)v51
                    * (float)((float)(vel->m_x * (float)v52)
                            + (float)((float)((float)v51 * vel->m_z) + (float)((float)v50 * vel->m_y))));
        v64 = (float)((float)((float)(vel->m_x * (float)v52)
                            + (float)((float)((float)v51 * vel->m_z) + (float)((float)v50 * vel->m_y)))
                    * (float)v52);
        v65 = (float)(vel->m_y
                    - (float)((float)v50
                            * (float)((float)(vel->m_x * (float)v52)
                                    + (float)((float)((float)v51 * vel->m_z) + (float)((float)v50 * vel->m_y)))));
        vel->m_y = vel->m_y
                 - (float)((float)v50
                         * (float)((float)(vel->m_x * (float)v52)
                                 + (float)((float)((float)v51 * vel->m_z) + (float)((float)v50 * vel->m_y))));
        vel->m_z = (float)v61 - (float)v63;
        vel->m_x = (float)v62 - (float)v64;
        v66 = (float)((float)v65 * (float)simTime);
        v67 = (float)((float)((float)v61 - (float)v63) * (float)simTime);
        v68 = (float)((float)((float)v62 - (float)v64) * (float)simTime);
        v69 = __fsqrts((float)((float)((float)v68 * (float)v68)
                             + (float)((float)((float)v67 * (float)v67)
                                     + (float)((float)((float)v65 * (float)simTime)
                                             * (float)((float)v65 * (float)simTime)))));
        if ( v69 < (float)(bfx::GetScale() * 0.0009765625) )
          goto LABEL_15;
        p_m_pos = &this->m_pos;
        v70 = (float)(this->m_pos.m_y + (float)v66);
        v71 = (float)(this->m_pos.m_z + (float)v67);
        v187.m_x = this->m_pos.m_x + (float)v68;
        v187.m_y = v70;
        v187.m_z = v71;
        if ( (unsigned __int8)bfx::Volume::ProbeFrom(
                                this: m_pTarget,
                                startPos: &this->m_pos,
                                endPos: &v187,
                                hitPlaneIndex: (unsigned int *)&v184,
                                pHitPortal: (const bfx::Portal **)&v185,
                                ignorePlaneIndex0: this->m_iFace0,
                                ignorePlaneIndex1: -1) == 0 )
        {
          v39 = v187.m_x;
          v40 = v187.m_y;
          v41 = v187.m_z;
          goto LABEL_14;
        }
        v72 = v185;
        v73 = v187.m_z;
        v74 = (float)(v187.m_z - this->m_pos.m_z);
        v75 = v185 == nullptr;
        v76 = (float)(v187.m_x - p_m_pos->m_x);
        v77 = v187.m_y;
        v78 = (float)(v187.m_y - this->m_pos.m_y);
        p_m_pos->m_x = v187.m_x;
        this->m_pos.m_y = v77;
        this->m_pos.m_z = v73;
        v79 = __fsqrts((float)((float)((float)v78 * (float)v78)
                             + (float)((float)((float)v76 * (float)v76) + (float)((float)v74 * (float)v74))));
        if ( !v75
          && (v80 = bfx::Portal::GetOtherVolume(this: v72, vol: m_pTarget), v81 = (bfx::LinkBase *)v80, v80 != nullptr)
          && this->OkToMoveIntoVolume(this, a2: v80) )
        {
          bfx::Handle<bfx::MoverImpl>::operator=(this: p_m_volume, pTarget: v81);
          this->m_state = FREE;
          v27 = (float)((float)((float)((float)v69 - (float)v79) / (float)v69) * (float)simTime);
        }
        else
        {
          v82 = v184;
          v83 = vel->m_y;
          v84 = vel->m_z;
          v85 = vel->m_x;
          v86 = (int)m_pTarget->m_pRes + 16 * (_DWORD)v184;
          v87 = *(float *)(v86 + 12);
          v88 = *(float *)(v86 + 20);
          v89 = *(float *)(v86 + 24);
          v90 = *(float *)(v86 + 16);
          v191 = v87;
          v193 = v88;
          v194 = v89;
          v192 = v90;
          v91 = (float)(v192
                      * (float)((float)((float)v85 * v87)
                              + (float)((float)(v88 * (float)v84) + (float)(v192 * (float)v83))));
          v92 = (float)((float)((float)((float)v85 * v191)
                              + (float)((float)(v88 * (float)v84) + (float)(v90 * (float)v83)))
                      * v191);
          vel->m_z = (float)v84
                   - (float)(v88
                           * (float)((float)((float)v85 * v87)
                                   + (float)((float)(v88 * (float)v84) + (float)(v90 * (float)v83))));
          vel->m_y = (float)v83 - (float)v91;
          vel->m_x = (float)v85 - (float)v92;
          this->m_state = ON_EDGE;
          this->m_iFace1 = (unsigned int)v82;
          v27 = (float)((float)((float)((float)v69 - (float)v79) / (float)v69) * (float)simTime);
        }
      }
      else
      {
        v55 = 0;
        while ( 1 )
        {
          v56 = &m_pTarget->m_portals.m_data[v55];
          m_pPortal = v56->m_pPortal;
          if ( v56->m_planeIndex == this->m_iFace0
            && (unsigned __int8)bfx::Portal::IsFacePointInPortal(this: v56->m_pPortal, P: &this->m_pos, tol: v54) != 0 )
          {
            v58 = (bfx::LinkBase *)bfx::Portal::GetOtherVolume(this: m_pPortal, vol: m_pTarget);
            v59 = this->__vftable;
            v60 = bfx::Portal::GetOtherVolume(this: m_pPortal, vol: m_pTarget);
            if ( v59->OkToMoveIntoVolume(this, a2: v60) )
              break;
          }
          ++v53;
          ++v55;
          if ( v53 >= m_pTarget->m_portals.m_size )
            goto LABEL_25;
        }
        bfx::Handle<bfx::MoverImpl>::operator=(this: p_m_volume, pTarget: v58);
        this->m_state = FREE;
        this->m_iFace0 = -1;
        v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
      }
      break;
    case ON_EDGE:
      m_pRes = m_pTarget->m_pRes;
      v94 = vel->m_y;
      v95 = vel->m_z;
      v96 = vel->m_x;
      m_d = m_pRes->m_planes[this->m_iFace0].m_d;
      v99 = (float)((float)(vel->m_z * vel->m_z) + (float)(vel->m_y * vel->m_y));
      v100 = m_pRes->m_planes[this->m_iFace0].m_normal.m_x;
      v101 = m_pRes->m_planes[this->m_iFace0].m_normal.m_y;
      v102 = m_pRes->m_planes[this->m_iFace0].m_normal.m_z;
      v97 = (float *)(&m_pRes->m_userData + 4 * this->m_iFace1);
      v103 = v97[3];
      v194 = m_d;
      v191 = v100;
      v192 = v101;
      v193 = v102;
      v104 = v102;
      v105 = v100;
      v106 = v97[4];
      v107 = (float)((float)((float)v96 * (float)v96) + (float)v99);
      v108 = v97[5];
      v109 = v101;
      v194 = v97[6];
      v191 = v103;
      v192 = v106;
      v193 = v108;
      v110 = v106;
      v111 = v108;
      v112 = (float)((float)((float)v96 * (float)v105) + (float)((float)(v102 * (float)v95) + (float)(v101 * (float)v94))) >= -(float)((float)__fsqrts(v107) * (float)0.0009765625);
      v113 = v103;
      v114 = (float)((float)((float)v96 * v103) + (float)((float)(v108 * (float)v95) + (float)(v106 * (float)v94))) >= -(float)((float)__fsqrts(v107) * (float)0.0009765625);
      if ( !v112 )
      {
        v115 = v112;
        m_iFace0 = this->m_iFace0;
        v112 = v114;
        v114 = v115;
        this->m_iFace0 = this->m_iFace1;
        this->m_iFace1 = m_iFace0;
      }
      if ( !v112 )
        goto LABEL_18;
      if ( v114 )
      {
        v117 = 0;
        v118 = (float)(bfx::GetScale() * (float)0.0078125);
        if ( m_pTarget->m_portals.m_size <= 0 )
        {
LABEL_47:
          v126 = (float)((float)((float)v110 * (float)v105) - (float)((float)v109 * (float)v113));
          v127 = (float)((float)((float)v111 * (float)v109) - (float)((float)v110 * (float)v104));
          v128 = (float)((float)((float)v104 * (float)v113) - (float)((float)v111 * (float)v105));
          _FP11 = (float)((float)__fsqrts((float)((float)((float)v128 * (float)v128)
                                                + (float)((float)((float)v127 * (float)v127)
                                                        + (float)((float)v126 * (float)v126))))
                        - 1.0842022e-19);
          __asm { fsel      f3, f11, f10, f27 }
          v131 = (float)((float)((float)((float)((float)((float)v111 * (float)v109) - (float)((float)v110 * (float)v104))
                                       * (float)_FP3)
                               * vel->m_x)
                       + (float)((float)((float)((float)((float)((float)v110 * (float)v105)
                                                       - (float)((float)v109 * (float)v113))
                                               * (float)_FP3)
                                       * vel->m_z)
                               + (float)((float)((float)((float)((float)v104 * (float)v113)
                                                       - (float)((float)v111 * (float)v105))
                                               * (float)_FP3)
                                       * vel->m_y)));
          v132 = (float)((float)((float)((float)((float)v110 * (float)v105) - (float)((float)v109 * (float)v113))
                               * (float)_FP3)
                       * (float)((float)((float)((float)((float)((float)v111 * (float)v109)
                                                       - (float)((float)v110 * (float)v104))
                                               * (float)_FP3)
                                       * vel->m_x)
                               + (float)((float)((float)((float)((float)((float)v110 * (float)v105)
                                                               - (float)((float)v109 * (float)v113))
                                                       * (float)_FP3)
                                               * vel->m_z)
                                       + (float)((float)((float)((float)((float)v104 * (float)v113)
                                                               - (float)((float)v111 * (float)v105))
                                                       * (float)_FP3)
                                               * vel->m_y))));
          vel->m_z = (float)((float)((float)((float)v110 * (float)v105) - (float)((float)v109 * (float)v113))
                           * (float)_FP3)
                   * (float)((float)((float)((float)((float)((float)v111 * (float)v109)
                                                   - (float)((float)v110 * (float)v104))
                                           * (float)_FP3)
                                   * vel->m_x)
                           + (float)((float)((float)((float)((float)((float)v110 * (float)v105)
                                                           - (float)((float)v109 * (float)v113))
                                                   * (float)_FP3)
                                           * vel->m_z)
                                   + (float)((float)((float)((float)((float)v104 * (float)v113)
                                                           - (float)((float)v111 * (float)v105))
                                                   * (float)_FP3)
                                           * vel->m_y)));
          vel->m_x = (float)((float)((float)((float)v111 * (float)v109) - (float)((float)v110 * (float)v104))
                           * (float)_FP3)
                   * (float)v131;
          v133 = (float)((float)((float)((float)((float)v104 * (float)v113) - (float)((float)v111 * (float)v105))
                               * (float)_FP3)
                       * (float)v131);
          vel->m_y = (float)((float)((float)((float)v104 * (float)v113) - (float)((float)v111 * (float)v105))
                           * (float)_FP3)
                   * (float)v131;
          v135 = (float)((float)((float)((float)((float)((float)v111 * (float)v109) - (float)((float)v110 * (float)v104))
                                       * (float)_FP3)
                               * (float)v131)
                       * (float)simTime);
          v134 = (float)((float)v132 * (float)simTime);
          v136 = (float)((float)v133 * (float)simTime);
          v137 = __fsqrts((float)((float)((float)((float)v133 * (float)simTime) * (float)((float)v133 * (float)simTime))
                                + (float)((float)((float)v135 * (float)v135)
                                        + (float)((float)((float)v132 * (float)simTime)
                                                * (float)((float)v132 * (float)simTime)))));
          if ( v137 >= (float)(bfx::GetScale() * 0.0009765625) )
          {
            v138 = &this->m_pos;
            v139 = (float)(this->m_pos.m_y + (float)v136);
            v140 = (float)(this->m_pos.m_z + (float)v134);
            v189.m_x = (float)v135 + this->m_pos.m_x;
            v189.m_y = v139;
            v189.m_z = v140;
            if ( (unsigned __int8)bfx::Volume::ProbeFrom(
                                    this: m_pTarget,
                                    startPos: &this->m_pos,
                                    endPos: &v189,
                                    hitPlaneIndex: (unsigned int *)&v184,
                                    pHitPortal: (const bfx::Portal **)&v185,
                                    ignorePlaneIndex0: this->m_iFace0,
                                    ignorePlaneIndex1: this->m_iFace1) != 0 )
            {
              v141 = v185;
              v142 = v189.m_z;
              v143 = (float)(v189.m_z - this->m_pos.m_z);
              v144 = v185 == nullptr;
              v145 = (float)(v189.m_x - v138->m_x);
              v146 = v189.m_y;
              v147 = (float)(v189.m_y - this->m_pos.m_y);
              v138->m_x = v189.m_x;
              this->m_pos.m_y = v146;
              this->m_pos.m_z = v142;
              v148 = __fsqrts((float)((float)((float)v147 * (float)v147)
                                    + (float)((float)((float)v145 * (float)v145) + (float)((float)v143 * (float)v143))));
              if ( !v144
                && (v149 = bfx::Portal::GetOtherVolume(this: v141, vol: m_pTarget),
                    v150 = (bfx::LinkBase *)v149,
                    v149 != nullptr)
                && this->OkToMoveIntoVolume(this, a2: v149) )
              {
                bfx::Handle<bfx::MoverImpl>::operator=(this: p_m_volume, pTarget: v150);
                this->m_state = FREE;
                v27 = (float)((float)((float)((float)v137 - (float)v148) / (float)v137) * (float)simTime);
              }
              else
              {
                v151 = v184;
                vel->m_x = 0.0;
                vel->m_y = 0.0;
                vel->m_z = 0.0;
                this->m_state = ON_VERTEX;
                this->m_iFace2 = (unsigned int)v151;
                v27 = (float)((float)((float)((float)v137 - (float)v148) / (float)v137) * (float)simTime);
              }
            }
            else
            {
              v27 = 0.0;
              v152 = v189.m_y;
              v153 = v189.m_z;
              v138->m_x = v189.m_x;
              this->m_pos.m_y = v152;
              this->m_pos.m_z = v153;
            }
          }
          else
          {
            v27 = 0.0;
          }
        }
        else
        {
          v119 = 0;
          while ( 1 )
          {
            v120 = &m_pTarget->m_portals.m_data[v119];
            m_planeIndex = v120->m_planeIndex;
            if ( m_planeIndex == this->m_iFace0 || m_planeIndex == this->m_iFace1 )
            {
              v122 = v120->m_pPortal;
              if ( (unsigned __int8)bfx::Portal::IsFacePointInPortal(this: v120->m_pPortal, P: &this->m_pos, tol: v118) != 0 )
              {
                v123 = (bfx::LinkBase *)bfx::Portal::GetOtherVolume(this: v122, vol: m_pTarget);
                v124 = this->__vftable;
                v125 = bfx::Portal::GetOtherVolume(this: v122, vol: m_pTarget);
                if ( v124->OkToMoveIntoVolume(this, a2: v125) )
                  break;
              }
            }
            ++v117;
            ++v119;
            if ( v117 >= m_pTarget->m_portals.m_size )
              goto LABEL_47;
          }
          bfx::Handle<bfx::MoverImpl>::operator=(this: p_m_volume, pTarget: v123);
          this->m_state = FREE;
          this->m_iFace0 = -1;
          this->m_iFace1 = -1;
          v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
        }
      }
      else
      {
        this->m_iFace1 = -1;
        this->m_state = ON_FACE;
        v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
      }
      break;
    case ON_VERTEX:
      v154 = m_pTarget->m_pRes;
      v155 = vel->m_y;
      v156 = vel->m_z;
      p_m_x = &v154->m_planes[this->m_iFace0].m_normal.m_x;
      v158 = vel->m_x;
      v159 = (float *)(&v154->m_userData + 4 * this->m_iFace1);
      v160 = v154->m_planes[this->m_iFace0].m_normal.m_y;
      v162 = v154->m_planes[this->m_iFace0].m_normal.m_z;
      v163 = v154->m_planes[this->m_iFace0].m_d;
      v161 = (float *)(&v154->m_userData + 4 * this->m_iFace2);
      v164 = (float)((float)(vel->m_z * vel->m_z) + (float)(vel->m_y * vel->m_y));
      v165 = v159[3];
      v191 = *p_m_x;
      v192 = v160;
      v193 = v162;
      v194 = v163;
      v166 = v161[3];
      v167 = v161[4];
      v168 = v161[5];
      v169 = v159[4];
      v170 = (float)((float)((float)v158 * (float)v158) + (float)v164);
      v171 = v159[5];
      v172 = *((_DWORD *)v161 + 6);
      v173 = *((_DWORD *)v159 + 6);
      v189.m_x = v165;
      v189.m_y = v169;
      v189.m_z = v171;
      v188 = v172;
      v190 = v173;
      v187.m_x = v166;
      v187.m_y = v167;
      v187.m_z = v168;
      v174 = (float)((float)((float)v158 * v191) + (float)((float)(v193 * (float)v156) + (float)(v192 * (float)v155))) >= -(float)((float)__fsqrts(v170) * (float)0.0009765625);
      v176 = (float)((float)((float)v158 * v166) + (float)((float)(v168 * (float)v156) + (float)(v167 * (float)v155))) >= -(float)((float)__fsqrts(v170) * (float)0.0009765625);
      v175 = (float)((float)((float)v158 * v165) + (float)((float)(v171 * (float)v156) + (float)(v169 * (float)v155))) >= -(float)((float)__fsqrts(v170) * (float)0.0009765625);
      if ( !v174 )
      {
        v177 = v174;
        v178 = this->m_iFace0;
        v174 = v175;
        v175 = v177;
        this->m_iFace0 = this->m_iFace1;
        this->m_iFace1 = v178;
      }
      if ( !v174 )
      {
        v179 = v174;
        v180 = this->m_iFace0;
        v174 = v176;
        v176 = v179;
        this->m_iFace0 = this->m_iFace2;
        this->m_iFace2 = v180;
      }
      if ( !v175 )
      {
        v181 = v175;
        m_iFace1 = this->m_iFace1;
        v175 = v176;
        v176 = v181;
        this->m_iFace1 = this->m_iFace2;
        this->m_iFace2 = m_iFace1;
      }
      if ( v174 )
      {
        if ( v175 )
        {
          if ( v176 )
          {
            v27 = 0.0;
            vel->m_x = 0.0;
            vel->m_y = 0.0;
            vel->m_z = 0.0;
          }
          else
          {
            this->m_state = ON_EDGE;
            this->m_iFace2 = -1;
            v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
          }
        }
        else
        {
          this->m_iFace1 = -1;
          this->m_state = ON_FACE;
          this->m_iFace2 = -1;
          v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
        }
        break;
      }
LABEL_18:
      this->m_state = FREE;
      v27 = bfx::Surfer3D::MoveOnce(this, vel, simTime);
      break;
    default:
      goto LABEL_15;
  }
  return *((float *)&v27 + 1);
}


// ========================================================================
// ?Move@Surfer3D@bfx@@QAAXAAVVec3@2@M@Z
// EA  : 0x832C19D8
// RVA : 0x012C19D8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxsurfer3d.cpp
// ========================================================================

void __fastcall bfx::Surfer3D::Move(bfx::Surfer3D *this, bfx::Vec3 *vel, double simTime)
{
  int i; // r31

  for ( i = 10; simTime > 0.0; --i )
  {
    if ( i == 0 )
      break;
    simTime = bfx::Surfer3D::MoveOnce(this, vel, simTime);
  }
}


// ========================================================================
// ??0Surfer3D@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x832C1A30
// RVA : 0x012C1A30
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxsurfer3d.cpp
// ========================================================================

bfx::Surfer3D *__fastcall bfx::Surfer3D::Surfer3D(bfx::Surfer3D *this, bfx::Space *pSpace)
{
  this->m_pSpace = pSpace;
  this->__vftable = (bfx::Surfer3D_vtbl *)&bfx::Surfer3D::`vftable';
  this->m_volume.m_pProxy = nullptr;
  this->m_pos = bfx::ZERO_VEC;
  this->m_state = FREE;
  return this;
}

