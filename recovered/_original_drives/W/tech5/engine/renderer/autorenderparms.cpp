
// ========================================================================
// ??0idAutoRenderParms@@QAA@XZ
// EA  : 0x828A4148
// RVA : 0x008A4148
// PDB : w:\tech5\engine\renderer\autorenderparms.cpp
// ========================================================================

idAutoRenderParms *__fastcall idAutoRenderParms::idAutoRenderParms(idAutoRenderParms *this)
{
  const idDeclRenderParm **v2; // r29
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  int i; // r28
  char v7; // r11
  int v8; // r18
  va *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  va *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r3
  __int64 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  va *v33; // r3
  __int64 v34; // r6
  __int64 v35; // r10
  __int64 v36; // r8
  va *v37; // r3
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  va *v41; // r3
  __int64 v42; // r10
  __int64 v43; // r8
  __int64 v44; // r6
  int v45; // r29
  const idDeclRenderParm **p_ambientLightColor; // r28
  va *v47; // r3
  int v49; // [sp+8h] [-10C8h]
  int v50; // [sp+8h] [-10C8h]
  int v51; // [sp+8h] [-10C8h]
  int v52; // [sp+8h] [-10C8h]
  int v53; // [sp+8h] [-10C8h]
  int v54; // [sp+8h] [-10C8h]
  int v55; // [sp+8h] [-10C8h]
  int v56; // [sp+8h] [-10C8h]
  int v57; // [sp+8h] [-10C8h]
  int v58; // [sp+Ch] [-10C4h]
  int v59; // [sp+Ch] [-10C4h]
  int v60; // [sp+Ch] [-10C4h]
  int v61; // [sp+Ch] [-10C4h]
  int v62; // [sp+Ch] [-10C4h]
  int v63; // [sp+Ch] [-10C4h]
  int v64; // [sp+Ch] [-10C4h]
  int v65; // [sp+Ch] [-10C4h]
  int v66; // [sp+Ch] [-10C4h]
  int v67; // [sp+10h] [-10C0h]
  int v68; // [sp+10h] [-10C0h]
  int v69; // [sp+10h] [-10C0h]
  int v70; // [sp+10h] [-10C0h]
  int v71; // [sp+10h] [-10C0h]
  int v72; // [sp+10h] [-10C0h]
  int v73; // [sp+10h] [-10C0h]
  int v74; // [sp+10h] [-10C0h]
  int v75; // [sp+10h] [-10C0h]
  int v76; // [sp+14h] [-10BCh]
  int v77; // [sp+14h] [-10BCh]
  int v78; // [sp+14h] [-10BCh]
  int v79; // [sp+14h] [-10BCh]
  int v80; // [sp+14h] [-10BCh]
  int v81; // [sp+14h] [-10BCh]
  int v82; // [sp+14h] [-10BCh]
  int v83; // [sp+14h] [-10BCh]
  int v84; // [sp+14h] [-10BCh]
  int v85; // [sp+18h] [-10B8h]
  int v86; // [sp+18h] [-10B8h]
  int v87; // [sp+18h] [-10B8h]
  int v88; // [sp+18h] [-10B8h]
  int v89; // [sp+18h] [-10B8h]
  int v90; // [sp+18h] [-10B8h]
  int v91; // [sp+18h] [-10B8h]
  int v92; // [sp+18h] [-10B8h]
  int v93; // [sp+18h] [-10B8h]
  int v94; // [sp+1Ch] [-10B4h]
  int v95; // [sp+1Ch] [-10B4h]
  int v96; // [sp+1Ch] [-10B4h]
  int v97; // [sp+1Ch] [-10B4h]
  int v98; // [sp+1Ch] [-10B4h]
  int v99; // [sp+1Ch] [-10B4h]
  int v100; // [sp+1Ch] [-10B4h]
  int v101; // [sp+1Ch] [-10B4h]
  int v102; // [sp+1Ch] [-10B4h]
  va v103; // [sp+50h] [-1080h] BYREF

  v2 = &this->mvpMatrix[3];
  LODWORD(v3) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v3) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  LODWORD(v4) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  HIDWORD(v4) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  LODWORD(v5) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  for ( i = 0; i < 4; ++i )
  {
    v7 = aXyzw[i];
    v8 = v7;
    HIDWORD(v5) = v7;
    v9 = va::va(
           this: &v103,
           fmt: "inverseModelMatrix%c",
           a3: v5,
           a4: v4,
           a5: v3,
           a6: v49,
           a7: v58,
           a8: v67,
           a9: v76,
           a10: v85,
           a11: v94);
    *(v2 - 15) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v9->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v10) = v8;
    v13 = va::va(
            this: &v103,
            fmt: "viewMatrix%c",
            a3: v10,
            a4: v12,
            a5: v11,
            a6: v50,
            a7: v59,
            a8: v68,
            a9: v77,
            a10: v86,
            a11: v95);
    *(v2 - 27) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v13->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v14) = v8;
    v17 = va::va(
            this: &v103,
            fmt: "inverseViewMatrix%c",
            a3: v14,
            a4: v16,
            a5: v15,
            a6: v51,
            a7: v60,
            a8: v69,
            a9: v78,
            a10: v87,
            a11: v96);
    *(v2 - 23) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v17->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v18) = v8;
    v21 = va::va(
            this: &v103,
            fmt: "modelMatrix%c",
            a3: v18,
            a4: v20,
            a5: v19,
            a6: v52,
            a7: v61,
            a8: v70,
            a9: v79,
            a10: v88,
            a11: v97);
    *(v2 - 19) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v21->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v22) = v8;
    v25 = va::va(
            this: &v103,
            fmt: "inverseModelMatrix%c",
            a3: v22,
            a4: v24,
            a5: v23,
            a6: v53,
            a7: v62,
            a8: v71,
            a9: v80,
            a10: v89,
            a11: v98);
    *(v2 - 15) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v25->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v26) = v8;
    v29 = va::va(
            this: &v103,
            fmt: "projectionMatrix%c",
            a3: v26,
            a4: v28,
            a5: v27,
            a6: v54,
            a7: v63,
            a8: v72,
            a9: v81,
            a10: v90,
            a11: v99);
    *(v2 - 11) = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: v29->buffer,
                                             makeDefault: true,
                                             skipStaleCheck: false);
    HIDWORD(v30) = v8;
    v33 = va::va(
            this: &v103,
            fmt: "inverseProjectionMatrix%c",
            a3: v30,
            a4: v32,
            a5: v31,
            a6: v55,
            a7: v64,
            a8: v73,
            a9: v82,
            a10: v91,
            a11: v100);
    *(v2 - 7) = (const idDeclRenderParm *)idResourceList::Load(
                                            this: &idDeclRenderParm::resourceList,
                                            name: v33->buffer,
                                            makeDefault: true,
                                            skipStaleCheck: false);
    HIDWORD(v34) = v8;
    v37 = va::va(
            this: &v103,
            fmt: "mvpMatrix%c",
            a3: v34,
            a4: v36,
            a5: v35,
            a6: v56,
            a7: v65,
            a8: v74,
            a9: v83,
            a10: v92,
            a11: v101);
    *(v2 - 3) = (const idDeclRenderParm *)idResourceList::Load(
                                            this: &idDeclRenderParm::resourceList,
                                            name: v37->buffer,
                                            makeDefault: true,
                                            skipStaleCheck: false);
    HIDWORD(v38) = v8;
    v41 = va::va(
            this: &v103,
            fmt: "inverseMVPMatrix%c",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v57,
            a7: v66,
            a8: v75,
            a9: v84,
            a10: v93,
            a11: v102);
    *++v2 = (const idDeclRenderParm *)idResourceList::Load(
                                        this: &idDeclRenderParm::resourceList,
                                        name: v41->buffer,
                                        makeDefault: true,
                                        skipStaleCheck: false);
  }
  this->If = (const idDeclRenderParm *)idResourceList::Load(
                                         this: &idDeclRenderParm::resourceList,
                                         name: "If",
                                         makeDefault: true,
                                         skipStaleCheck: false);
  this->Time = (const idDeclRenderParm *)idResourceList::Load(
                                           this: &idDeclRenderParm::resourceList,
                                           name: "Time",
                                           makeDefault: true,
                                           skipStaleCheck: false);
  this->Color = (const idDeclRenderParm *)idResourceList::Load(
                                            this: &idDeclRenderParm::resourceList,
                                            name: "Color",
                                            makeDefault: true,
                                            skipStaleCheck: false);
  this->coverage = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "coverage",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->modelFade = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "modelFade",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->useSkinBlending = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "useSkinBlending",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->exposure = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "exposure",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->TimeScale = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "TimeScale",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->TimeOffset = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "TimeOffset",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->TimeStop = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "TimeStop",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->Diversity = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "Diversity",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->Wind = (const idDeclRenderParm *)idResourceList::Load(
                                           this: &idDeclRenderParm::resourceList,
                                           name: "Wind",
                                           makeDefault: true,
                                           skipStaleCheck: false);
  this->NoShadows = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "NoShadows",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->polygonOffset = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "polygonOffset",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->lightColor = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "lightColor",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->lightScale = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "lightScale",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->lightProjectMap = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "lightProjectMap",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->lightFalloffMap = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "lightFalloffMap",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->globalViewOrigin = (const idDeclRenderParm *)idResourceList::Load(
                                                       this: &idDeclRenderParm::resourceList,
                                                       name: "globalViewOrigin",
                                                       makeDefault: true,
                                                       skipStaleCheck: false);
  this->globalViewFwd = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "globalViewFwd",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->globalViewLeft = (const idDeclRenderParm *)idResourceList::Load(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "globalViewLeft",
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
  this->globalViewUp = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "globalViewUp",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->stageProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "stageProgram",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->interactionProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "interactionProgram",
                                                         makeDefault: true,
                                                         skipStaleCheck: false);
  this->shadowProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "shadowProgram",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->depthFillProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                       this: &idDeclRenderParm::resourceList,
                                                       name: "depthFillProgram",
                                                       makeDefault: true,
                                                       skipStaleCheck: false);
  this->addProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "addProgram",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->blendProgram = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "blendProgram",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->stageSort = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "stageSort",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->sortCoverage = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "sortCoverage",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->sortSkybox = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "sortSkybox",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->sortBackground = (const idDeclRenderParm *)idResourceList::Load(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "sortBackground",
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
  this->sortEmit = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "sortEmit",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->sortEmitOnly = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "sortEmitOnly",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->sortLight = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "sortLight",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->sortDecal = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "sortDecal",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->sortTransSort = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "sortTransSort",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->sortTrans = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "sortTrans",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->sortWater = (const idDeclRenderParm *)idResourceList::Load(
                                                this: &idDeclRenderParm::resourceList,
                                                name: "sortWater",
                                                makeDefault: true,
                                                skipStaleCheck: false);
  this->sortPerturber = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "sortPerturber",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->surfaceFlags = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "surfaceFlags",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->contentFlags = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "contentFlags",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->toolsFlags = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "toolsFlags",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->surfaceType = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "surfaceType",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->editorImage = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "qer_editorImage",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->editorDraw = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "editorDraw",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->editorAlpha = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "editorAlpha",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->discrete = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "discrete",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->noFragment = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "noFragment",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->skipSurfaceInfo = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "skipSurfaceInfo",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->powerMip = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "powerMip",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->diffuseMap = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "diffuseMap",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->specularMap = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "specularMap",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->bumpMap = (const idDeclRenderParm *)idResourceList::Load(
                                              this: &idDeclRenderParm::resourceList,
                                              name: "bumpMap",
                                              makeDefault: true,
                                              skipStaleCheck: false);
  this->powerMap = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "powerMap",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->coverMap = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "coverMap",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->virtualTransMap = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "virtualTransMap",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->transMap = (const idDeclRenderParm *)idResourceList::Load(
                                               this: &idDeclRenderParm::resourceList,
                                               name: "transMap",
                                               makeDefault: true,
                                               skipStaleCheck: false);
  this->textureMap = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "textureMap",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->sMatrix = (const idDeclRenderParm *)idResourceList::Load(
                                              this: &idDeclRenderParm::resourceList,
                                              name: "sMatrix",
                                              makeDefault: true,
                                              skipStaleCheck: false);
  this->tMatrix = (const idDeclRenderParm *)idResourceList::Load(
                                              this: &idDeclRenderParm::resourceList,
                                              name: "tMatrix",
                                              makeDefault: true,
                                              skipStaleCheck: false);
  this->rMatrix = (const idDeclRenderParm *)idResourceList::Load(
                                              this: &idDeclRenderParm::resourceList,
                                              name: "rMatrix",
                                              makeDefault: true,
                                              skipStaleCheck: false);
  this->qMatrix = (const idDeclRenderParm *)idResourceList::Load(
                                              this: &idDeclRenderParm::resourceList,
                                              name: "qMatrix",
                                              makeDefault: true,
                                              skipStaleCheck: false);
  this->select = (const idDeclRenderParm *)idResourceList::Load(
                                             this: &idDeclRenderParm::resourceList,
                                             name: "select",
                                             makeDefault: true,
                                             skipStaleCheck: false);
  this->virtualMapping = (const idDeclRenderParm *)idResourceList::Load(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "virtualMapping",
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
  this->positionToViewTexture = (const idDeclRenderParm *)idResourceList::Load(
                                                            this: &idDeclRenderParm::resourceList,
                                                            name: "positionToViewTexture",
                                                            makeDefault: true,
                                                            skipStaleCheck: false);
  this->renderPositionToViewTexture = (const idDeclRenderParm *)idResourceList::Load(
                                                                  this: &idDeclRenderParm::resourceList,
                                                                  name: "renderPositionToViewTexture",
                                                                  makeDefault: true,
                                                                  skipStaleCheck: false);
  this->positionToFeedback = (const idDeclRenderParm *)idResourceList::Load(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "positionToFeedback",
                                                         makeDefault: true,
                                                         skipStaleCheck: false);
  this->ambientLightColor = (const idDeclRenderParm *)idResourceList::Load(
                                                        this: &idDeclRenderParm::resourceList,
                                                        name: "ambientLightColor",
                                                        makeDefault: true,
                                                        skipStaleCheck: false);
  v45 = 0;
  p_ambientLightColor = &this->ambientLightColor;
  do
  {
    HIDWORD(v44) = v45;
    v47 = va::va(
            this: &v103,
            fmt: "channelLight%i",
            a3: v44,
            a4: v43,
            a5: v42,
            a6: v49,
            a7: v58,
            a8: v67,
            a9: v76,
            a10: v85,
            a11: v94);
    ++v45;
    *++p_ambientLightColor = (const idDeclRenderParm *)idResourceList::Load(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: v47->buffer,
                                                         makeDefault: true,
                                                         skipStaleCheck: false);
  }
  while ( v45 < 6 );
  this->primeLightDir = (const idDeclRenderParm *)idResourceList::Load(
                                                    this: &idDeclRenderParm::resourceList,
                                                    name: "primeLightDir",
                                                    makeDefault: true,
                                                    skipStaleCheck: false);
  this->primeLightColor = (const idDeclRenderParm *)idResourceList::Load(
                                                      this: &idDeclRenderParm::resourceList,
                                                      name: "primeLightColor",
                                                      makeDefault: true,
                                                      skipStaleCheck: false);
  this->highlightColor = (const idDeclRenderParm *)idResourceList::Load(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "highlightColor",
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
  this->landPageFile = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "landPageFile",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->renderBump = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "renderbump",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->stampCovers = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "stampCovers",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->stampScales = (const idDeclRenderParm *)idResourceList::Load(
                                                  this: &idDeclRenderParm::resourceList,
                                                  name: "stampScales",
                                                  makeDefault: true,
                                                  skipStaleCheck: false);
  this->stampBlendMode = (const idDeclRenderParm *)idResourceList::Load(
                                                     this: &idDeclRenderParm::resourceList,
                                                     name: "landStampBlendMode",
                                                     makeDefault: true,
                                                     skipStaleCheck: false);
  this->stampBlendModeNone = (const idDeclRenderParm *)idResourceList::Load(
                                                         this: &idDeclRenderParm::resourceList,
                                                         name: "landStampBlendModeNone",
                                                         makeDefault: true,
                                                         skipStaleCheck: false);
  this->depthOfField = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "depthOfField",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  this->radialBlurCenter = (const idDeclRenderParm *)idResourceList::Load(
                                                       this: &idDeclRenderParm::resourceList,
                                                       name: "radialBlurCenter",
                                                       makeDefault: true,
                                                       skipStaleCheck: false);
  this->globalBlur = (const idDeclRenderParm *)idResourceList::Load(
                                                 this: &idDeclRenderParm::resourceList,
                                                 name: "globalBlur",
                                                 makeDefault: true,
                                                 skipStaleCheck: false);
  this->doubleVision = (const idDeclRenderParm *)idResourceList::Load(
                                                   this: &idDeclRenderParm::resourceList,
                                                   name: "doubleVision",
                                                   makeDefault: true,
                                                   skipStaleCheck: false);
  return this;
}

