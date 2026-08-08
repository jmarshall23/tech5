
// ========================================================================
// ?RenderLights@@YAXPBUrenderLightsParms_t@@@Z
// EA  : 0x828DFEF0
// RVA : 0x008DFEF0
// PDB : w:\tech5\engine\renderer\jobs\render\renderlights.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RenderLights(const renderLightsParms_t *parms)
{
  idRenderLog *v2; // r14
  const idRenderView *renderView; // r11
  const idRenderView *v4; // r11
  int numViewLights; // r6
  __int64 v6; // r16
  int v7; // r23
  int v8; // r22
  const idRenderMatrix *v9; // r24
  int v10; // r9
  const idRenderLightCommitted *v11; // r25
  lightClass_t lightClass; // r11
  int slowMultiPass; // r29
  __int128 v14; // r7 OVERLAPPED
  int v15; // r10
  __int64 v16; // r9
  __int64 v17; // r28
  double v18; // fp24
  float *v19; // r3
  double v20; // fp22
  double v21; // fp21
  double v22; // fp29
  double v23; // fp28
  double v24; // fp23
  double v25; // fp0
  char v26; // r11
  double v27; // fp26
  double v28; // fp27
  double v29; // fp1
  double v30; // fp1
  double v31; // fp13
  double v32; // fp12
  double v33; // fp0
  double v34; // fp11
  const renderSettings_t *settings; // r11
  double v36; // fp1
  double maxVisibleRange; // fp0
  double v38; // fp10
  double x; // fp9
  double v40; // fp8
  double v41; // fp2
  double v42; // fp4
  double v43; // fp10
  double v44; // fp0
  lightClass_t v45; // r11
  bfx::BinaryReplayLogOut *v46; // r3
  bool v47; // r7
  const idTriangles *zeroOneCubeTris; // r10
  __int128 v49; // r6
  const idTriangles *v50; // r10
  __int128 v51; // r6
  bool v52; // r7
  const idDeclRenderProg *v53; // r28
  bool v54; // r7
  bfx::BinaryReplayLogOut *v55; // r3
  int showBlendedLights; // r11
  unsigned __int64 v57; // r6
  const idTriangles *v58; // r10
  const idRenderView *v59; // r11
  int y1; // r6
  int x2; // r5
  int y2; // r4
  BOOL useLightScissors; // r3
  const idRenderView *v64; // r11
  __int64 v65; // r4 OVERLAPPED
  __int64 v66; // r11
  __int64 v67; // r6 OVERLAPPED
  int v68; // r7
  int x1; // r29
  int v70; // r27
  int v71; // r26
  int v72; // r28
  char v73; // r11
  bool v74; // r5
  const idDeclRenderProg *progDepthOnly; // r10
  __int128 v76; // r6
  bool v77; // r7
  const idDeclRenderProg *v78; // r8
  bool v79; // r7
  int v80; // r20
  int v81; // r19
  const idRenderModelCommitted *v82; // r27
  char v83; // r11
  lightClass_t v84; // r10
  int v85; // r11
  unsigned __int64 v86; // r8
  int numViewWorldSurfaces; // r22
  int v88; // r26
  int v89; // r24
  int i; // r23
  const idRenderModelSurface *v91; // r29
  int binaryModelId; // r10
  const bool *binaryModelState; // r9
  const idDeclRenderProg *v94; // r28
  const idBounds *p_bounds; // r14
  bool v96; // r3
  unsigned __int64 v97; // r6
  const idRenderView *v98; // r11
  bfx::BinaryReplayLogOut *v99; // r3
  int indentLevel; // r11
  int v101; // r11
  int v102; // r11
  unsigned __int8 v103[4]; // [sp+50h] [-740h] BYREF
  int v104; // [sp+54h] [-73Ch]
  unsigned __int8 v105; // [sp+58h] [-738h] BYREF
  unsigned __int8 v106[7]; // [sp+59h] [-737h] BYREF
  __int64 v107; // [sp+60h] [-730h]
  __int64 v108; // [sp+68h] [-728h]
  idRenderLog *v109; // [sp+70h] [-720h]
  idRenderDrawSurf v110; // [sp+74h] [-71Ch] BYREF
  int v111; // [sp+78h] [-718h]
  idScreenRect v112; // [sp+80h] [-710h] BYREF
  __int64 v113; // [sp+90h] [-700h]
  __int64 v114; // [sp+98h] [-6F8h]
  idODSObject<idDeclRenderProg> v115; // [sp+A0h] [-6F0h] BYREF
  idRenderMatrix *v116; // [sp+A4h] [-6ECh]
  const idTriangles *v117; // [sp+A8h] [-6E8h] BYREF
  const char *v118; // [sp+ACh] [-6E4h]
  const idTriangles *v119; // [sp+B0h] [-6E0h] BYREF
  idODSObject<idDeclRenderProg> v120; // [sp+B4h] [-6DCh] BYREF
  idODSObject<idDeclRenderProg> v121; // [sp+B8h] [-6D8h] BYREF
  idODSObject<idDeclRenderProg> v122; // [sp+BCh] [-6D4h] BYREF
  idODSObject<idTriangles> v123; // [sp+C0h] [-6D0h] BYREF
  const idTriangles *v124; // [sp+C4h] [-6CCh] BYREF
  idODSObject<idDeclRenderProg> v125; // [sp+C8h] [-6C8h] BYREF
  idODSObject<idTriangles> v126; // [sp+CCh] [-6C4h] BYREF
  float v127; // [sp+D0h] [-6C0h] BYREF
  idODSObject<idTriangles> v128; // [sp+D4h] [-6BCh] BYREF
  float v129; // [sp+D8h] [-6B8h] BYREF
  idODSObject<idDeclRenderProg> v130; // [sp+DCh] [-6B4h] BYREF
  float v131; // [sp+E0h] [-6B0h] BYREF
  float v132; // [sp+E4h] [-6ACh] BYREF
  idRenderMatrix v133; // [sp+F0h] [-6A0h] BYREF
  __int64 v134; // [sp+130h] [-660h]
  lightShadow_t v135; // [sp+140h] [-650h] BYREF
  idBounds v136; // [sp+1C0h] [-5D0h] BYREF
  idBounds v137; // [sp+1E0h] [-5B0h] BYREF
  idBounds v138; // [sp+200h] [-590h] BYREF
  __int64 v139; // [sp+218h] [-578h]
  _QWORD v140[6]; // [sp+220h] [-570h] BYREF
  idRenderMatrix v141; // [sp+250h] [-540h] BYREF
  idRenderMatrix v142; // [sp+290h] [-500h] BYREF
  idRenderMatrix baseLightProject; // [sp+2D0h] [-4C0h] BYREF
  idRenderMatrix v144; // [sp+310h] [-480h] BYREF
  idRenderMatrix v145; // [sp+350h] [-440h] BYREF
  idRenderMatrix v146; // [sp+390h] [-400h] BYREF
  idRenderMatrix v147; // [sp+3D0h] [-3C0h] BYREF
  lightShadow_t v148; // [sp+410h] [-380h] BYREF
  idRenderMatrix v149; // [sp+490h] [-300h] BYREF
  idRenderMatrix v150; // [sp+4D0h] [-2C0h] BYREF
  idRenderMatrix v151; // [sp+510h] [-280h] BYREF
  idRenderMatrix v152; // [sp+550h] [-240h] BYREF
  idRenderMatrix v153; // [sp+590h] [-200h] BYREF
  idRenderMatrix v154; // [sp+5D0h] [-1C0h] BYREF
  idRenderMatrix v155; // [sp+610h] [-180h] BYREF
  idRenderMatrix v156[2]; // [sp+650h] [-140h] BYREF

  v2 = &renderLog;
  v109 = &renderLog;
  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_RENDER_LIGHTS);
  renderView = parms->renderView;
  GL_Viewport(
    x: renderView->viewport.x1,
    y: renderView->viewport.y1,
    w: renderView->viewport.x2 - renderView->viewport.x1 + 1,
    h: renderView->viewport.y2 - renderView->viewport.y1 + 1);
  v4 = parms->renderView;
  GL_Scissor(
    x: v4->scissorRect.x1,
    y: v4->scissorRect.y1,
    w: v4->scissorRect.x2 - v4->scissorRect.x1 + 1,
    h: v4->scissorRect.y2 - v4->scissorRect.y1 + 1);
  numViewLights = parms->numViewLights;
  LODWORD(v6) = 0;
  v7 = 0;
  v104 = 0;
  v8 = 0;
  v111 = 0;
  if ( numViewLights > 0 )
  {
    v9 = &renderMatrix_windowSpaceToClipSpace;
    v10 = 0;
    v116 = &renderMatrix_windowSpaceToClipSpace;
    v118 = "----- Light %i : lightMtr %s-----\n";
    do
    {
      v11 = parms->viewLights[v10];
      lightClass = v11->r.lightClass;
      if ( lightClass == LIGHT_BLENDED_ONLY )
      {
        if ( !parms->settings->skipBlendLights && v11->lightMtr->progs[6] != nullptr )
          goto LABEL_11;
      }
      else if ( (lightClass == LIGHT_SLOWLIGHT_DYNAMIC_ONLY
              || lightClass == LIGHT_SLOWLIGHT_PRIVATE_ONLY
              || !parms->settings->isComboMap)
             && !parms->settings->skipSlowLights )
      {
LABEL_11:
        idRenderLog::Printf(this: v2, fmt: v118, v11->index.index >> 8, v11->lightMtr->name.str);
        idRenderLog::Indent(this: v2, label: RENDER_LOG_INDENT_DEFAULT);
        HIDWORD(v6) = &v11->renderParmBlock;
        idParmState::VirtualEvaluateParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v11->renderParmBlock,
          parmBlock: &v11->renderParmBlock);
        idParmState::VirtualEvaluateParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v11->lightMtr->renderParmBlock,
          parmBlock: &v11->lightMtr->renderParmBlock);
        slowMultiPass = v11->r.slowMultiPass;
        *((_QWORD *)&v14 + 1) = *(unsigned __int64 *)((char *)&renderThreadParmState->renderParmVersion
                                                    + renderThreadParmState->values[parms->rpLightTranslation->parmIndex].swizzle[0]);
        *(_QWORD *)((char *)&v14 + 4) = *(unsigned __int64 *)((char *)&renderThreadParmState->renderParmVersion
                                                            + DWORD2(v14));
        v15 = 16 * (parms->rpLightRotation->parmIndex + 3);
        v16 = *(_QWORD *)renderThreadParmState->values[parms->rpLightOscillationAmp->parmIndex].value;
        v17 = *(_QWORD *)renderThreadParmState->values[parms->rpLightOscillationPhase->parmIndex].value;
        v107 = *(_QWORD *)((char *)&v14 - 4);
        v134 = v14;
        v114 = *(_QWORD *)((char *)&v14 + 4);
        v18 = *(float *)((char *)&renderThreadParmState->renderParmVersion + v15);
        v108 = v16;
        v113 = v17;
        v19 = (float *)memcpy(Dst: &v141, Src: &v11->baseLightProject, Size: DWORD1(v14));
        v20 = *((float *)&v107 + 1);
        v21 = *(float *)&v107;
        v22 = *((float *)&v134 + 1);
        v23 = *(float *)&v134;
        v24 = *((float *)&v114 + 1);
        v25 = *(float *)&v114;
        if ( v18 != 0.0 || v21 != 0.0 || v20 != 0.0 || v23 != 1.0 || v22 != 1.0 || v25 != 0.0 || (v26 = 0, v24 != 0.0) )
          v26 = 1;
        if ( v26 != 0 )
        {
          v133.m[0] = 1.0;
          v27 = 0.0;
          v133.m[1] = 0.0;
          v28 = 0.0;
          v133.m[3] = 0.0;
          v133.m[2] = 0.0;
          v133.m[5] = 1.0;
          v133.m[4] = 0.0;
          v133.m[7] = 0.0;
          v133.m[6] = 0.0;
          v133.m[8] = 0.0;
          v133.m[9] = 0.0;
          v133.m[10] = 1.0;
          v133.m[11] = 0.0;
          v133.m[12] = 0.0;
          v133.m[13] = 0.0;
          v133.m[14] = 0.0;
          v133.m[15] = 1.0;
          if ( v25 != 0.0 )
          {
            v29 = idMath::Sin16(a: (float)(*(float *)&v113 + *(float *)&v114));
            v27 = (float)((float)v29 * *(float *)&v108);
          }
          if ( v24 != 0.0 )
          {
            v30 = idMath::Sin16(a: (float)(*((float *)&v113 + 1) + (float)v24));
            v28 = (float)((float)v30 * *((float *)&v108 + 1));
          }
          if ( v18 == 0.0 )
          {
            v34 = v133.m[7];
            v31 = v133.m[5];
            v33 = v133.m[3];
            v32 = v133.m[0];
          }
          else
          {
            idMath::SinCos16(a: (float)(idMath::M_DEG2RAD * (float)v18), s: v19, c: &v129, a4: &v127);
            v31 = v127;
            v133.m[4] = v129 * (float)v23;
            v32 = v127;
            v133.m[1] = -(float)(v129 * (float)v22);
            v33 = (float)((float)((float)((float)(v129 * (float)0.5) + (float)(v127 * (float)-0.5)) + (float)0.5)
                        * (float)v23);
            v34 = (float)((float)((float)((float)(v129 * (float)-0.5) + (float)(v127 * (float)-0.5)) + (float)0.5)
                        * (float)v22);
          }
          v133.m[0] = (float)((float)v27 + (float)v23) * (float)v32;
          v133.m[5] = (float)((float)v28 + (float)v22) * (float)v31;
          v133.m[3] = (float)((float)v33 - (float)((float)((float)v23 * (float)0.5) - (float)0.5)) + (float)v21;
          v133.m[7] = (float)((float)v34 - (float)((float)((float)v22 * (float)0.5) - (float)0.5)) + (float)v20;
          baseLightProject = v11->baseLightProject;
          baseLightProject.m[8] = 0.0;
          baseLightProject.m[9] = 0.0;
          baseLightProject.m[10] = 0.0;
          baseLightProject.m[11] = 0.0;
          idRenderMatrix::Multiply(a: &v133, b: &baseLightProject, out: &v142);
          v141.m[0] = v142.m[0];
          v141.m[1] = v142.m[1];
          v141.m[2] = v142.m[2];
          v141.m[3] = v142.m[3];
          v141.m[4] = v142.m[4];
          v141.m[5] = v142.m[5];
          v141.m[6] = v142.m[6];
          v141.m[7] = v142.m[7];
        }
        settings = parms->settings;
        v36 = 1.0;
        if ( !parms->settings->skipLightRangeCulling )
        {
          maxVisibleRange = v11->r.maxVisibleRange;
          *(float *)&v107 = v11->r.maxVisibleRange;
          if ( maxVisibleRange > 0.0 )
          {
            v38 = (float)(settings->viewOrigin.y - v11->maxVisibleRange.y);
            x = settings->viewOrigin.x;
            v40 = v11->maxVisibleRange.x;
            HIDWORD(v107) = &v11->maxVisibleRange;
            v41 = (float)(v11->r.fadeVisibilityOver * v11->r.fadeVisibilityOver);
            v42 = (float)(settings->viewOrigin.z - v11->maxVisibleRange.z);
            HIDWORD(v107) = &settings->viewOrigin;
            v43 = (float)((float)((float)((float)((float)v42 * (float)v42)
                                        + (float)((float)((float)((float)x - (float)v40) * (float)((float)x - (float)v40))
                                                + (float)((float)v38 * (float)v38)))
                                - (float)v41)
                        / (float)((float)((float)maxVisibleRange * (float)maxVisibleRange) - (float)v41));
            v44 = (float)((float)1.0 - (float)v43);
            if ( v44 >= 0.0 )
            {
              if ( v44 <= 1.0 )
                v36 = (float)((float)1.0 - (float)v43);
              else
                v36 = 1.0;
            }
            else
            {
              v36 = 0.0;
            }
          }
        }
        idDeclRenderParm::Set(this: parms->rpLightFade, v: v36);
        v45 = v11->r.lightClass;
        if ( (_cntlzw(v45 - 7) & 0x20) != 0 )
        {
          if ( v11->castsShadows && (v45 != LIGHT_BLENDED_ONLY || !parms->settings->skipBlendLightShadows) )
          {
            RenderShadowBuffer(parms: &parms->shadowBufferParms, light: v11, lightShadow: &v148);
            idRenderMatrix::Multiply(a: &v148.worldPosToShadowMap, b: &parms->renderView->inverseViewMatrix, out: &v151);
            idRenderMatrix::Multiply(a: &v151, b: &parms->renderView->inverseProjectionMatrix, out: &v154);
            idRenderMatrix::Multiply(a: &v154, b: v9, out: &v145);
            idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedShadowS, plane: (const idPlane *)&v145);
            idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedShadowT, plane: (const idPlane *)&v145.m[4]);
            idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedShadowR, plane: (const idPlane *)&v145.m[8]);
            idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedShadowQ, plane: (const idPlane *)&v145.m[12]);
            idDeclRenderParm::Set(this: parms->rpShadowProjectionS, plane: (const idPlane *)&v148);
            idDeclRenderParm::Set(this: parms->rpShadowProjectionT, plane: (const idPlane *)&v148.shadowProjection.m[4]);
            idDeclRenderParm::Set(this: parms->rpShadowProjectionR, plane: (const idPlane *)&v148.shadowProjection.m[8]);
            idDeclRenderParm::Set(
              this: parms->rpShadowProjectionQ,
              plane: (const idPlane *)&v148.shadowProjection.m[12]);
            v104 = ++v7;
          }
          if ( parms->settings->useLightDepthBoundsTest )
          {
            idRenderMatrix::Multiply(
              a: &parms->renderView->worldSpaceMVPMatrix,
              b: &v11->inverseBaseLightProject,
              out: v156);
            v138.b[0].x = 0.0;
            v138.b[0].y = 0.0;
            v138.b[0].z = 0.0;
            v138.b[1].x = 1.0;
            v138.b[1].y = 1.0;
            v138.b[1].z = 1.0;
            idRenderMatrix::DepthBoundsForBounds(min: &v132, max: &v131, mvp: v156, b: &v138, zeroToOne: true);
            idPhysics_StaticMulti::UpdateTime(this: v46);
          }
          idParmState::SetMVPMatrixForInverseProject(
            this: renderThreadParmState,
            mvp: &parms->renderView->worldSpaceMVPMatrix,
            inverseProject: &v11->inverseBaseLightProject);
          D3DDevice_SetRenderState_HiStencilWriteEnable(pDevice: wrapperContext.d3d, Value: 1u);
          D3DDevice_SetRenderState_HiStencilRef(pDevice: wrapperContext.d3d, Value: 1u);
          D3DDevice_SetRenderState_HiStencilFunc(pDevice: wrapperContext.d3d, Value: 1u);
          if ( !idRenderMatrix::CullBoundsToMVPbits(
                  mvp: &v11->baseLightProject,
                  b: &parms->settings->viewBounds,
                  outBits: v106,
                  zeroToOne: true) )
          {
            zeroOneCubeTris = parms->zeroOneCubeTris;
            *((_QWORD *)&v49 + 1) = 0x8000280F00000000uLL;
            DWORD1(v49) = &v117;
            *(_QWORD *)((char *)&v49 + 4) <<= 32;
            v125.objectPtr = parms->progDepthOnly;
            v117 = zeroOneCubeTris;
            DWORD2(v49) |= 0xF01107C0;
            GL_DrawElements(
              prog: &v125,
              tri: (const idODSObject<idTriangles> *)DWORD1(v49),
              extraState: v49,
              skipDetailTriangles: v47);
          }
          v50 = parms->zeroOneCubeTris;
          *((_QWORD *)&v51 + 1) = 0x8000440F00000000uLL;
          DWORD1(v51) = &v119;
          *(_QWORD *)((char *)&v51 + 4) <<= 32;
          v120.objectPtr = parms->progDepthOnly;
          v119 = v50;
          DWORD2(v51) |= 0xF01007C0;
          GL_DrawElements(
            prog: &v120,
            tri: (const idODSObject<idTriangles> *)DWORD1(v51),
            extraState: v51,
            skipDetailTriangles: v47);
          D3DDevice_SetRenderState_HiStencilWriteEnable(pDevice: wrapperContext.d3d, Value: 0);
          idRenderMatrix::Multiply(a: &v141, b: &parms->renderView->inverseViewMatrix, out: &v149);
          idRenderMatrix::Multiply(a: &v149, b: &parms->renderView->inverseProjectionMatrix, out: &v155);
          idRenderMatrix::Multiply(a: &v155, b: v9, out: &v147);
          idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedTexS, plane: (const idPlane *)&v147);
          idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedTexT, plane: (const idPlane *)&v147.m[4]);
          idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedTexR, plane: (const idPlane *)&v147.m[8]);
          idDeclRenderParm::Set(this: parms->rpWindowPosToProjectedTexQ, plane: (const idPlane *)&v147.m[12]);
          D3DDevice_SetRenderState_HiStencilEnable(pDevice: wrapperContext.d3d, Value: 1u);
          D3DDevice_FlushHiZStencil(pDevice: wrapperContext.d3d, FlushType: D3DFHZS_SYNCHRONOUS);
          v53 = v11->lightMtr->progs[6];
          if ( slowMultiPass > 0 )
          {
            do
            {
              v123.objectPtr = parms->zeroOneCubeTris;
              v121.objectPtr = v53;
              GL_DrawElements(prog: &v121, tri: &v123, extraState: 0x1000000000000uLL, skipDetailTriangles: v52);
              --slowMultiPass;
            }
            while ( slowMultiPass != 0 );
          }
          D3DDevice_SetRenderState_HiStencilEnable(pDevice: wrapperContext.d3d, Value: 0);
          if ( parms->settings->useLightDepthBoundsTest )
            idPhysics_StaticMulti::UpdateTime(this: v55);
          showBlendedLights = parms->settings->showBlendedLights;
          if ( showBlendedLights != 0 )
          {
            HIDWORD(v57) = 0;
            if ( showBlendedLights == 1 )
            {
              HIDWORD(v57) = 2048;
            }
            else if ( showBlendedLights == 2 )
            {
              HIDWORD(v57) = -267386880;
            }
            LODWORD(v57) = 0;
            v58 = parms->zeroOneCubeTris;
            v122.objectPtr = parms->progBlendedLightDebugDraw;
            v128.objectPtr = v58;
            GL_DrawElements(prog: &v122, tri: &v128, extraState: v57, skipDetailTriangles: v54);
          }
        }
        else
        {
          v59 = parms->renderView;
          y1 = v59->scissorRect.y1;
          x2 = v59->scissorRect.x2;
          y2 = v59->scissorRect.y2;
          useLightScissors = parms->settings->useLightScissors;
          v112.x1 = v59->scissorRect.x1;
          v112.y1 = y1;
          v112.x2 = x2;
          v112.y2 = y2;
          if ( useLightScissors )
          {
            idRenderMatrix::Multiply(a: &v59->worldSpaceMVPMatrix, b: &v11->inverseBaseLightProject, out: &v153);
            v136.b[0].x = 0.0;
            v136.b[0].y = 0.0;
            v136.b[0].z = 0.0;
            v136.b[1].x = 1.0;
            v136.b[1].y = 1.0;
            v136.b[1].z = 1.0;
            idRenderMatrix::ProjectedBounds(projected: &v137, mvp: &v153, b: &v136, zeroToOne: true);
            v64 = parms->renderView;
            HIDWORD(v65) = &v112;
            HIDWORD(v66) = v64->viewport.y1;
            LODWORD(v67) = v64->viewport.x2;
            LODWORD(v65) = v64->viewport.x1;
            LODWORD(v66) = v64->viewport.y2;
            HIDWORD(v67) = v66;
            v139 = v66;
            v140[4] = v67;
            v140[3] = v65;
            v68 = HIDWORD(v66);
            v140[5] = *(__int64 *)((char *)&v67 - 4);
            LODWORD(v114) = (int)(float)(v137.b[0].x * (float)((float)v67 - (float)v65));
            LODWORD(v113) = (int)(float)(v137.b[1].y * (float)((float)v66 - (float)*(__int64 *)((char *)&v67 - 4)));
            LODWORD(v108) = (int)(float)(v137.b[1].x * (float)((float)v67 - (float)v65));
            v112.y1 = (int)(float)(v137.b[0].y * (float)((float)v66 - (float)*(__int64 *)((char *)&v67 - 4)));
            v112.y2 = v113;
            v112.x1 = v114;
            v112.x2 = v108;
            idScreenRect::Expand(this: &v112);
            idScreenRect::Intersect(this: &v112, rect: &parms->renderView->scissorRect);
          }
          x1 = v112.x1;
          v70 = v112.x2;
          v71 = v112.y2;
          v72 = v112.y1;
          if ( v112.x1 > v112.x2 || (v73 = 0, v112.y1 > v112.y2) )
            v73 = 1;
          if ( v73 == 0 )
          {
            if ( v11->castsShadows )
            {
              RenderShadowBuffer(parms: &parms->shadowBufferParms, light: v11, lightShadow: &v135);
              idDeclRenderParm::Set(this: parms->rpShadowProjectionS, plane: (const idPlane *)&v135);
              idDeclRenderParm::Set(
                this: parms->rpShadowProjectionT,
                plane: (const idPlane *)&v135.shadowProjection.m[4]);
              idDeclRenderParm::Set(
                this: parms->rpShadowProjectionR,
                plane: (const idPlane *)&v135.shadowProjection.m[8]);
              idDeclRenderParm::Set(
                this: parms->rpShadowProjectionQ,
                plane: (const idPlane *)&v135.shadowProjection.m[12]);
              v104 = v7 + 1;
            }
            else
            {
              v135.shadowProjection.m[0] = 1.0;
              v135.shadowProjection.m[1] = 0.0;
              v135.shadowProjection.m[2] = 0.0;
              v135.shadowProjection.m[3] = 0.0;
              v135.shadowProjection.m[4] = 0.0;
              v135.shadowProjection.m[5] = 1.0;
              v135.shadowProjection.m[6] = 0.0;
              v135.shadowProjection.m[7] = 0.0;
              v135.shadowProjection.m[8] = 0.0;
              v135.shadowProjection.m[9] = 0.0;
              v135.shadowProjection.m[10] = 1.0;
              v135.shadowProjection.m[11] = 0.0;
              v135.shadowProjection.m[12] = 0.0;
              v135.shadowProjection.m[13] = 0.0;
              v135.shadowProjection.m[14] = 0.0;
              v135.shadowProjection.m[15] = 1.0;
              v135.worldPosToShadowMap.m[0] = 1.0;
              v135.worldPosToShadowMap.m[1] = 0.0;
              v135.worldPosToShadowMap.m[2] = 0.0;
              v135.worldPosToShadowMap.m[3] = 0.0;
              v135.worldPosToShadowMap.m[4] = 0.0;
              v135.worldPosToShadowMap.m[5] = 1.0;
              v135.worldPosToShadowMap.m[6] = 0.0;
              v135.worldPosToShadowMap.m[7] = 0.0;
              v135.worldPosToShadowMap.m[8] = 0.0;
              v135.worldPosToShadowMap.m[9] = 0.0;
              v135.worldPosToShadowMap.m[10] = 1.0;
              v135.worldPosToShadowMap.m[11] = 0.0;
              v135.worldPosToShadowMap.m[12] = 0.0;
              v135.worldPosToShadowMap.m[13] = 0.0;
              v135.worldPosToShadowMap.m[14] = 0.0;
              v135.worldPosToShadowMap.m[15] = 1.0;
            }
            if ( parms->settings->useLightDepthBoundsTest )
              idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)useLightScissors);
            GL_Scissor(x: x1, y: v72, w: v70 - x1 + 1, h: v71 - v72 + 1);
            if ( parms->settings->showLightScissors )
              GL_Clear(color: true, depth: false, stencil: false, stencilValue: 0, r: 1.0, g: 0.0, b: 0.0, a: 0.0);
            GL_State(stateBits: 0xF000000000000000uLL, forceGlState: v74);
            GL_Clear(color: false, depth: false, stencil: true, stencilValue: 0, r: 0.0, g: 0.0, b: 0.0, a: 0.0);
            idParmState::SetMVPMatrixForInverseProject(
              this: renderThreadParmState,
              mvp: &parms->renderView->worldSpaceMVPMatrix,
              inverseProject: &v11->inverseBaseLightProject);
            progDepthOnly = parms->progDepthOnly;
            *((_QWORD *)&v76 + 1) = 0x80000C0000000000uLL;
            DWORD1(v76) = &v124;
            v124 = parms->zeroOneCubeTris;
            *(_QWORD *)((char *)&v76 + 4) <<= 32;
            v130.objectPtr = progDepthOnly;
            DWORD2(v76) |= 0x107C0u;
            GL_DrawElements(
              prog: &v130,
              tri: (const idODSObject<idTriangles> *)DWORD1(v76),
              extraState: v76,
              skipDetailTriangles: v77);
            v78 = parms->progDepthOnly;
            v126.objectPtr = parms->zeroOneCubeTris;
            v115.objectPtr = v78;
            GL_DrawElements(prog: &v115, tri: &v126, extraState: 0x800017C000000000uLL, skipDetailTriangles: v79);
            idDeclRenderParm::Set(this: parms->rpGlobalLightOrigin, vec: &v11->globalLightOrigin);
            idDeclRenderParm::Set(this: parms->rpStaticSpecularScale, v: v11->r.staticSpecularScale);
            idDeclRenderParm::Set(this: parms->rpStaticSpecularVector, vec: &v11->r.staticSpecularVector);
            v110.currentModel = nullptr;
            v80 = 0;
            if ( parms->numViewModels > 0 )
            {
              v81 = 0;
              do
              {
                v82 = parms->viewModels[v81];
                if ( (*((_BYTE *)v82 + 1416) & 4) == 0 || (v83 = 1, (*((_BYTE *)&v82->r + 105) & 0x40) != 0) )
                  v83 = 0;
                if ( v83 != 0 )
                {
                  v84 = v11->r.lightClass;
                  if ( v84 == LIGHT_PRIVATE_DYNAMIC_ONLY
                    || v84 == LIGHT_PRIVATE_PRIME
                    || (v85 = 0, v84 == LIGHT_SLOWLIGHT_PRIVATE_ONLY) )
                  {
                    v85 = 1;
                  }
                  if ( (*((_BYTE *)&v82->r + 106) & 1) == v85
                    && (v84 != LIGHT_PRELIGHT_ONLY || (*((_BYTE *)&v82->r + 104) & 0x20) != 0)
                    && (v84 != LIGHT_DYNAMIC_ONLY || (*((_BYTE *)&v82->r + 104) & 0x20) == 0)
                    && (v84 != LIGHT_SLOWLIGHT_DYNAMIC_ONLY && v84 != LIGHT_SLOWLIGHT_PRIVATE_ONLY
                     || (*((_BYTE *)&v82->r + 104) & 0x20) == 0 && (*((_BYTE *)&v82->r + 104) & 0x10) == 0) )
                  {
                    if ( (*((_BYTE *)&v82->r + 104) & 0x10) != 0
                      || (idRenderMatrix::Multiply(a: &v11->baseLightProject, b: &v82->modelMatrix, out: &v150),
                          !idRenderMatrix::CullBoundsToMVPbits(
                             mvp: &v150,
                             b: &v82->referenceBounds,
                             outBits: &v105,
                             zeroToOne: true)) )
                    {
                      if ( (*((_BYTE *)&v82->r + 107) & 8) == 0 )
                      {
                        idRenderMatrix::Multiply(a: &v141, b: &v82->modelMatrix, out: &v146);
                        idDeclRenderParm::Set(this: parms->rpLightProjectionS, plane: (const idPlane *)&v146);
                        idDeclRenderParm::Set(this: parms->rpLightProjectionT, plane: (const idPlane *)&v146.m[4]);
                        idDeclRenderParm::Set(this: parms->rpLightProjectionR, plane: (const idPlane *)&v146.m[8]);
                        idDeclRenderParm::Set(this: parms->rpLightProjectionQ, plane: (const idPlane *)&v146.m[12]);
                        if ( v11->castsShadows )
                        {
                          idRenderMatrix::Multiply(a: &v135.worldPosToShadowMap, b: &v82->modelMatrix, out: &v144);
                          idDeclRenderParm::Set(this: parms->rpLocalToLightS, plane: (const idPlane *)&v144);
                          idDeclRenderParm::Set(this: parms->rpLocalToLightT, plane: (const idPlane *)&v144.m[4]);
                          idDeclRenderParm::Set(this: parms->rpLocalToLightR, plane: (const idPlane *)&v144.m[8]);
                          idDeclRenderParm::Set(this: parms->rpLocalToLightQ, plane: (const idPlane *)&v144.m[12]);
                        }
                        if ( (*((_BYTE *)&v82->r + 104) & 0x10) != 0 )
                          numViewWorldSurfaces = parms->numViewWorldSurfaces;
                        else
                          numViewWorldSurfaces = v82->surfaces.num;
                        if ( numViewWorldSurfaces > 0 )
                        {
                          v88 = 0;
                          v89 = 0;
                          for ( i = numViewWorldSurfaces; i != 0; --i )
                          {
                            if ( (*((_BYTE *)&v82->r + 104) & 0x10) != 0 )
                              v91 = parms->viewWorldSurfaces[v89];
                            else
                              v91 = &v82->surfaces.list[v88];
                            if ( v91->material != nullptr )
                            {
                              binaryModelId = v91->binaryModelId;
                              binaryModelState = parms->binaryModelState;
                              LODWORD(v86) = binaryModelState[binaryModelId];
                              if ( binaryModelState[binaryModelId] )
                              {
                                v94 = v91->material->progs[1];
                                if ( v94 != nullptr )
                                {
                                  if ( numViewWorldSurfaces == 1
                                    || v91->joints != nullptr
                                    || (p_bounds = &v91->geometry->bounds,
                                        idRenderMatrix::Multiply(
                                          a: &v11->baseLightProject,
                                          b: &v82->modelMatrix,
                                          out: &v152),
                                        v96 = idRenderMatrix::CullBoundsToMVPbits(
                                                mvp: &v152,
                                                b: p_bounds,
                                                outBits: v103,
                                                zeroToOne: true),
                                        v2 = v109,
                                        !v96) )
                                  {
                                    if ( v11->castsShadows && v94->stageSort == parms->settings->sortLight )
                                      v94 = v94->versions[v11->r.lightType];
                                    HIDWORD(v97) = v140;
                                    LODWORD(v97) = 392961;
                                    v140[0] = v6;
                                    v140[2] = v6;
                                    HIDWORD(v140[1]) = v82;
                                    LODWORD(v140[1]) = v91;
                                    HIDWORD(v140[2]) = v91->material;
                                    LODWORD(v140[2]) = v94;
                                    idRenderDrawSurf::RenderDrawSurf(
                                      this: &v110,
                                      parms: &parms->drawSurfParms,
                                      surf: (const drawSurf_t *)(v97 >> 12),
                                      a4: -267386880,
                                      extraState: v86);
                                  }
                                }
                              }
                            }
                            ++v89;
                            ++v88;
                          }
                        }
                      }
                    }
                  }
                }
                ++v80;
                ++v81;
              }
              while ( v80 < parms->numViewModels );
            }
            v98 = parms->renderView;
            GL_Scissor(
              x: v98->scissorRect.x1,
              y: v98->scissorRect.y1,
              w: v98->scissorRect.x2 - v98->scissorRect.x1 + 1,
              h: v98->scissorRect.y2 - v98->scissorRect.y1 + 1);
            if ( parms->settings->useLightDepthBoundsTest )
              idPhysics_StaticMulti::UpdateTime(this: v99);
            idRenderDrawSurf::PopModel(this: &v110);
            v7 = v104;
            v8 = v111;
            v9 = v116;
          }
        }
        idParmState::VirtualRollbackParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v11->lightMtr->renderParmBlock,
          parmBlock: &v11->lightMtr->renderParmBlock);
        idParmState::VirtualRollbackParmBlock(
          this: renderThreadParmState,
          localParmBlock: &v11->renderParmBlock,
          parmBlock: &v11->renderParmBlock);
        if ( v2->logFile != nullptr )
        {
          indentLevel = v2->indentLevel;
          if ( indentLevel > 0 )
          {
            v101 = indentLevel - 1;
            v2->indentLevel = v101;
            v2->indentString[4 * v101] = 0;
          }
        }
      }
      v102 = parms->numViewLights;
      v111 = ++v8;
      v10 = v8;
    }
    while ( v8 < v102 );
  }
  *parms->numShadows = v7;
  idRenderLog::CloseMainBlock(this: v2);
}


// ========================================================================
// __unwind$87619
// EA  : 0x828E0EF8
// RVA : 0x008E0EF8
// PDB : w:\tech5\engine\renderer\jobs\render\renderlights.cpp
// ========================================================================

void _unwind_87619()
{
  int v0; // r12

  idRenderDrawSurf::~idRenderDrawSurf(this: (idRenderDrawSurf *)(v0 - 1936 + 116));
}

