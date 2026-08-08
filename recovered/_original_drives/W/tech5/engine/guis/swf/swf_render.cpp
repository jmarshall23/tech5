
// ========================================================================
// ?GLStateForRenderState@idSWF@@AAA_KABUswfRenderState_t@@@Z
// EA  : 0x8277E5A0
// RVA : 0x0077E5A0
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

int __fastcall idSWF::GLStateForRenderState(idSWF *this, const swfRenderState_t *renderState)
{
  int activeMasks; // r10
  int v3; // r11
  int result; // r3

  activeMasks = renderState->activeMasks;
  v3 = 0;
  if ( activeMasks > 0 )
    v3 = ((unsigned __int8)(activeMasks + 0x80) | 0x5FF00) << 20;
  switch ( renderState->blendMode )
  {
    case 3u:
    case 0xDu:
    case 0xEu:
      result = v3 | 0x2A;
      break;
    case 4u:
      result = v3 | 0x4000A;
      break;
    case 5u:
      result = v3 | 0xC0008;
      break;
    case 6u:
      result = v3 | 0x80008;
      break;
    case 7u:
    case 9u:
      result = v3 | 0x40008;
      break;
    case 8u:
      result = v3 | 8;
      break;
    default:
      result = v3 | 0x28;
      break;
  }
  return result;
}


// ========================================================================
// ?LoadAtlasImage@idSWF@@QAA_N_N@Z
// EA  : 0x8277E878
// RVA : 0x0077E878
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

int __fastcall idSWF::LoadAtlasImage(idSWF *this, bool force)
{
  imageState_t v4; // r3
  idFile *v5; // r3
  idFile *atlasFile; // r4
  unsigned int v8; // r5
  const char *str; // r4
  __int64 v10; // r11
  int v11; // [sp+50h] [-40h] BYREF
  _BYTE v12[4]; // [sp+54h] [-3Ch] BYREF
  _BYTE v13[4]; // [sp+58h] [-38h] BYREF
  _BYTE v14[4]; // [sp+5Ch] [-34h] BYREF
  _QWORD v15[6]; // [sp+60h] [-30h] BYREF

  v4 = idImage::ImageState(this: this->atlasImage);
  if ( v4 != IS_READY )
  {
    if ( v4 == IS_BACKGROUND_READING )
    {
      if ( force )
      {
        while ( idImage::ImageState(this: this->atlasImage) == IS_BACKGROUND_READING )
          mgthread_sleep(ms: 10);
        return (_cntlzw(idImage::ImageState(this: this->atlasImage) - 2) & 0x20) != 0;
      }
    }
    else
    {
      if ( idLib::production == PROD_PRODUCTION || idLib::production == PROD_LOADED )
      {
        str = this->atlasTextureName.str;
        this->atlasFile = nullptr;
        if ( resourceManager->GetPatchFileInfo(
               this: resourceManager,
               a2: str,
               a3: v15,
               a4: (unsigned int *)v14,
               a5: (unsigned int *)v13,
               a6: (unsigned int *)v12,
               a7: &v11) )
        {
          this->atlasFile = resourceManager->GetPatchFile(this: resourceManager, a2: v11);
        }
        atlasFile = this->atlasFile;
        if ( atlasFile == nullptr )
        {
          if ( resourceManager->GetCacheFileInfo(
                 this: resourceManager,
                 a2: this->atlasTextureName.str,
                 a3: v15,
                 a4: (unsigned int *)v14,
                 a5: (unsigned int *)v13,
                 a6: (unsigned int *)v12,
                 a7: false) )
          {
            this->atlasFile = resourceManager->GetCacheFile(this: resourceManager);
          }
          atlasFile = this->atlasFile;
          if ( atlasFile == nullptr )
            return 0;
        }
        HIDWORD(v10) = HIDWORD(v15[0]);
        LODWORD(v10) = LODWORD(v15[0]) + 62;
        v8 = LODWORD(v15[0]) + 62;
        v15[0] = v10;
      }
      else
      {
        atlasFile = fileSystem->OpenFileRead(this: fileSystem, a2: this->atlasTextureName.str, a3: 1, a4: 0);
        this->atlasFile = atlasFile;
        if ( atlasFile == nullptr )
          idLib::Error(fmt: "Required SWF atlas file '%s' could not be opened.", this->atlasTextureName.str);
        v8 = 62;
      }
      idImage::BackgroundRead(this: this->atlasImage, file: atlasFile, offset: v8);
      if ( force )
      {
        while ( idImage::ImageState(this: this->atlasImage) == IS_BACKGROUND_READING )
          mgthread_sleep(ms: 10);
        return (_cntlzw(idImage::ImageState(this: this->atlasImage) - 2) & 0x20) != 0;
      }
    }
    return 0;
  }
  if ( this->atlasPurgable )
    idSWF::MarkImageForPurging(image: this->atlasImage);
  if ( this->atlasFile != nullptr
    && ((unsigned __int8 (__fastcall *)(idResourceManager *))resourceManager->IsResourceFile)(a1: resourceManager) == 0 )
  {
    if ( resourceManager->GetCacheFile(this: resourceManager) != nullptr || idLib::production == PROD_DEVELOPMENT )
    {
      v5 = this->atlasFile;
      if ( v5 != nullptr )
        ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
    }
    this->atlasFile = nullptr;
  }
  return 1;
}


// ========================================================================
// ?RenderShape@idSWF@@AAAXPAVidRenderModelGui@@PBVidSWFShape@@ABUswfRenderState_t@@@Z
// EA  : 0x8277EB20
// RVA : 0x0077EB20
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::RenderShape(
        idSWF *this,
        idRenderModelGui *gui,
        const idSWFShape *shape,
        const swfRenderState_t *renderState)
{
  idSWF *v4; // r3
  idSWF *v5; // r23
  idRenderModelGui *v6; // r22
  const idSWFShape *v7; // r26
  const char **v9; // r3
  __int64 v10; // r10 OVERLAPPED
  __int64 v11; // r8 OVERLAPPED
  char *type; // r6 OVERLAPPED
  idCVar *v13; // r21
  double i; // fp0
  idSWFShapeDrawFill *list; // r10
  const idMaterial *material; // r11
  char v18; // r14
  idSWFShapeDrawFill *v19; // r28
  double xx; // fp27
  double yy; // fp26
  double xy; // fp25
  double yx; // fp24
  double tx; // fp23
  double ty; // fp22
  double v26; // fp19
  double v27; // fp18
  double v28; // fp21
  double v29; // fp20
  double v30; // fp29
  double v31; // fp30
  const idMaterial *atlasMaterial; // r27
  __int64 v33; // r8
  __int128 v34; // r5
  swfColorXform_t *v35; // r3
  double w; // fp13
  double valueFloat; // fp0
  double v38; // fp12
  unsigned int v39; // r30
  unsigned int v40; // r3
  __int64 v41; // r11
  unsigned int v42; // r29
  double v43; // fp29
  double v44; // fp30
  unsigned __int64 v45; // r6
  int *p_num; // r15
  idDrawVert *v47; // r3
  int v49; // r8
  int v50; // r5
  float *p_x; // r10
  float *v53; // r9
  double v54; // fp0
  double v55; // fp8
  double v56; // fp11
  double v57; // fp10
  double v58; // fp9
  double v59; // fp5
  double v60; // fp13
  double v61; // fp6
  double v62; // fp1
  double v63; // fp0
  double v64; // fp13
  int bitmapID; // r10
  int v66; // r30
  __int128 v67; // r10
  __int128 v68; // r6
  swfMatrix_t *v69; // r3
  int v70; // r3
  int v72; // ctr
  int v75; // r7
  int v77; // r3
  int v79; // ctr
  int *v83; // r24
  int v84; // r25
  idList<idSWFShapeDrawLine,72> *p_lineDraws; // r26
  int v86; // r27
  idSWFShapeDrawLine *v87; // r11
  __int64 v88; // r6
  int v89; // r28
  int v90; // r11
  swfColorXform_t *v91; // r3
  double v92; // fp13
  double v93; // fp0
  double v94; // fp12
  unsigned int v95; // r30
  unsigned int v96; // r29
  unsigned __int64 v97; // r6
  _DWORD *v98; // r18
  double v104; // fp5
  double v106; // fp13
  double v107; // fp2
  idList<idSWFShapeDrawLine,72> *v108; // [sp+50h] [-330h]
  int v109; // [sp+54h] [-32Ch]
  int v110; // [sp+54h] [-32Ch]
  int v111; // [sp+58h] [-328h]
  int v112; // [sp+58h] [-328h]
  swfColorXform_t v113; // [sp+60h] [-320h] BYREF
  swfColorXform_t v114; // [sp+80h] [-300h] BYREF
  idCVar *v115; // [sp+A0h] [-2E0h]
  float v116; // [sp+A4h] [-2DCh]
  swfColorXform_t v117; // [sp+B0h] [-2D0h] BYREF
  unsigned __int64 v118; // [sp+D0h] [-2B0h]
  __int64 v119; // [sp+D8h] [-2A8h]
  __int64 v120; // [sp+E0h] [-2A0h]
  unsigned __int64 v121; // [sp+E8h] [-298h]
  __int64 v122; // [sp+F0h] [-290h]
  idVec4 v123; // [sp+100h] [-280h] BYREF
  idVec4 v124; // [sp+110h] [-270h] BYREF
  __int64 v125; // [sp+120h] [-260h]
  __int64 v126; // [sp+128h] [-258h]
  __int64 v127; // [sp+130h] [-250h]
  __int64 v128; // [sp+138h] [-248h]
  __int64 v129; // [sp+140h] [-240h]
  __int64 v130; // [sp+148h] [-238h]
  __int64 v131; // [sp+150h] [-230h]
  _BYTE v132[16]; // [sp+160h] [-220h] BYREF
  _DWORD v133[48]; // [sp+170h] [-210h] BYREF
  swfColorXform_t v134[5]; // [sp+230h] [-150h] BYREF
  idSWF *v135; // [sp+394h] [+14h]

  v5 = v4;
  v135 = v4;
  v6 = gui;
  v7 = shape;
  if ( shape == nullptr )
  {
    idLib::Warning(fmt: "%s: RenderShape: shape == NULL", *v9);
    return;
  }
  HIDWORD(v10) = shape->fillDraws.num;
  HIDWORD(v11) = &off_82040000;
  type = byte_821B0000;
  v13 = &swf_forceAlpha;
  _R19 = 16;
  v111 = 0;
  v116 = 0.5;
  v115 = &swf_forceAlpha;
  if ( SHIDWORD(v10) > 0 )
  {
    v109 = 0;
    for ( i = 0.050000001; ; i = (float)0.050000001 )
    {
      list = v7->fillDraws.list;
      material = renderState->material;
      v113.mul.x = 1.0;
      v113.mul.y = 1.0;
      v18 = 0;
      v113.mul.z = 1.0;
      v19 = &list[v109];
      v113.mul.w = 1.0;
      v113.add.x = 0.0;
      xx = 1.0;
      v113.add.y = 0.0;
      yy = 1.0;
      v113.add.z = 0.0;
      xy = 0.0;
      v113.add.w = 0.0;
      yx = 0.0;
      tx = 0.0;
      ty = 0.0;
      v26 = 0.0;
      v27 = 0.0;
      v28 = 0.0;
      v29 = 0.0;
      v30 = 1.0;
      v31 = 1.0;
      if ( material != nullptr )
      {
        atlasMaterial = material;
        yy = i;
        xx = i;
        goto LABEL_11;
      }
      if ( v19->style.type == 0 )
        break;
      if ( v19->style.type != 4 )
        goto LABEL_10;
      bitmapID = v19->style.bitmapID;
      if ( bitmapID == 0xFFFF )
        goto LABEL_10;
      atlasMaterial = v5->atlasMaterial;
      v66 = (int)&v5->dictionary.list[bitmapID];
      memcpy(Dst: &v133[28], Src: &v5->atlasImage->opts, Size: 0x50u);
      DWORD2(v67) = *(_DWORD *)(v66 + 28);
      *(_QWORD *)&v67 = *(_QWORD *)(v66 + 32);
      LODWORD(v68) = *(_DWORD *)(v66 + 40);
      *(_QWORD *)((char *)&v68 + 4) = __PAIR64__(HIDWORD(v67), DWORD2(v67));
      v113.mul.x = *(float *)(v66 + 44);
      v128 = *(_QWORD *)&v67;
      v121 = __PAIR64__(v133[29], HIDWORD(v67));
      LODWORD(v67) = v133[29];
      v127 = v68;
      v118 = __PAIR64__(HIDWORD(v67), DWORD2(v67));
      v131 = v67;
      v18 = 1;
      DWORD2(v67) = v133[30];
      v125 = *(_QWORD *)((char *)&v67 + 4);
      v113.mul.y = *(float *)(v66 + 48);
      v113.mul.z = *(float *)(v66 + 52);
      v113.mul.w = *(float *)(v66 + 56);
      v30 = (float)*(__int64 *)((char *)&v68 + 4);
      v31 = (float)__SPAIR64__(v133[29], HIDWORD(v67));
      v28 = (float)((float)*(__int64 *)&v67 / (float)v131);
      v26 = (float)((float)*(__int64 *)((char *)&v68 + 4) / (float)v131);
      v27 = (float)((float)__SPAIR64__(v133[29], HIDWORD(v67)) / (float)*(__int64 *)((char *)&v67 + 4));
      v29 = (float)((float)(__int64)v68 / (float)*(__int64 *)((char *)&v67 + 4));
      v69 = swfMatrix_t::Inverse(this: (swfMatrix_t *)&v117, result: &v19->style.startMatrix);
      xx = v69->xx;
      yy = v69->yy;
      xy = v69->xy;
      yx = v69->yx;
      tx = v69->tx;
      ty = v69->ty;
LABEL_11:
      v35 = swfColorXform_t::Multiply(this: &v117, result: &v113, a: &renderState->cxf);
      v113.mul.x = v35->mul.x;
      v113.mul.y = v35->mul.y;
      v113.mul.z = v35->mul.z;
      w = v35->mul.w;
      v113.mul.w = v35->mul.w;
      v113.add.x = v35->add.x;
      v113.add.y = v35->add.y;
      v113.add.z = v35->add.z;
      valueFloat = v13->valueFloat;
      v38 = v35->add.w;
      v113.add.w = v35->add.w;
      if ( valueFloat > 0.0 )
      {
        v113.mul.w = valueFloat;
        w = valueFloat;
        v113.add.w = 0.0;
        v38 = 0.0;
      }
      if ( (float)((float)v38 + (float)w) > 0.001 )
      {
        v39 = idColor::PackColor(color: &v113.mul);
        v123.x = (float)(v113.add.x * v116) + v116;
        v123.y = (float)(v113.add.y * v116) + v116;
        v123.z = (float)(v113.add.z * v116) + v116;
        v123.w = (float)(v113.add.w * v116) + v116;
        v40 = idColor::PackColor(color: &v123);
        LODWORD(v41) = renderState->materialWidth;
        v42 = v40;
        if ( (int)v41 > 0 )
        {
          v120 = v41;
          v30 = (float)v41;
        }
        LODWORD(v41) = renderState->materialHeight;
        if ( (int)v41 > 0 )
        {
          v119 = v41;
          v31 = (float)v41;
        }
        v43 = (float)((float)1.0 / (float)v30);
        v44 = (float)((float)1.0 / (float)v31);
        idSWF::GLStateForRenderState(this: v5, renderState);
        idRenderModelGui::SetGLState(this: v6, bits: v45);
        p_num = &v19->startVerts.num;
        v47 = idRenderModelGui::AllocTris(
                this: v6,
                numVerts: v19->startVerts.num,
                indexes: v19->indices.list,
                numIndexes: v19->indices.num,
                material: atlasMaterial);
        if ( v47 != nullptr )
        {
          v49 = 0;
          if ( *p_num > 0 )
          {
            __asm { vspltisw128 v63, 0 }
            __asm { vcmpequw128 v62, v95, v63 }
            __asm { vsldoi128 v62, v95, v62, 4 }
            v50 = 0;
            do
            {
              _R11 = (float *)&v132[(32 * v49) & 0x60];
              p_x = &v19->startVerts.list[v50].x;
              v53 = p_x + 1;
              __asm
              {
                stvx128   v63, r0, r11
                stvx128   v62, r11, r19
              }
              type = (char *)v19->style.type;
              v54 = *p_x;
              v55 = renderState->matrix.xy;
              *((_BYTE *)_R11 + 31) = HIBYTE(v39);
              v56 = renderState->matrix.xx;
              *((_BYTE *)_R11 + 30) = BYTE1(v39);
              v57 = renderState->matrix.yy;
              *((_BYTE *)_R11 + 29) = BYTE2(v39);
              v58 = renderState->matrix.ty;
              *((_BYTE *)_R11 + 28) = v39;
              v59 = renderState->matrix.tx;
              *((_BYTE *)_R11 + 27) = HIBYTE(v42);
              v60 = p_x[1];
              *((_BYTE *)_R11 + 26) = BYTE1(v42);
              v61 = (float)(renderState->matrix.yx * (float)v54);
              _R11[2] = 0.0;
              *((_BYTE *)_R11 + 25) = BYTE2(v42);
              *((_BYTE *)_R11 + 24) = v42;
              _R11[1] = (float)((float)((float)v60 * (float)v57) + (float)v61) + (float)v58;
              *_R11 = (float)((float)((float)v54 * (float)v56) + (float)((float)v60 * (float)v55)) + (float)v59;
              if ( type != nullptr )
              {
                v62 = (float)((float)((float)yx
                                    * (float)((float)((float)((float)v54 - shape->startBounds.tl.x) * (float)v43)
                                            * (float)20.0))
                            + (float)((float)((float)((float)(*v53 - shape->startBounds.tl.y) * (float)v44) * (float)20.0)
                                    * (float)yy));
                v64 = (float)((float)((float)((float)yx
                                            * (float)((float)((float)((float)v54 - shape->startBounds.tl.x) * (float)v43)
                                                    * (float)20.0))
                                    + (float)((float)((float)((float)(*v53 - shape->startBounds.tl.y) * (float)v44)
                                                    * (float)20.0)
                                            * (float)yy))
                            + (float)ty);
                v63 = (float)((float)((float)((float)xy
                                            * (float)((float)((float)(*v53 - shape->startBounds.tl.y) * (float)v44)
                                                    * (float)20.0))
                                    + (float)((float)((float)((float)((float)v54 - shape->startBounds.tl.x) * (float)v43)
                                                    * (float)20.0)
                                            * (float)xx))
                            + (float)tx);
                if ( v18 != 0 )
                {
                  v63 = (float)((float)((float)v63 * (float)v26) + (float)v28);
                  v64 = (float)((float)((float)((float)v62 + (float)ty) * (float)v27) + (float)v29);
                }
                if ( v63 >= 0.001 )
                {
                  if ( v63 > 0.99900001 )
                    v63 = 0.99900001;
                }
                else
                {
                  v63 = 0.001;
                }
                if ( v64 >= 0.001 )
                {
                  if ( v64 > 0.99900001 )
                    v64 = 0.99900001;
                }
                else
                {
                  v64 = 0.001;
                }
                _R11[3] = v63;
                _R11[4] = v64;
              }
              if ( (v49 & 3) == 3 )
              {
                _R11 = ((32 * v49) & 0xFFFFFF80) + v70;
                type = (char *)v133;
                v72 = 4;
                _R9 = &v132[-_R11];
                _R10 = (char *)v133 - _R11;
                v75 = 16;
                do
                {
                  __asm
                  {
                    lvx128    v61, r9, r11
                    stvx128   v61, r0, r11
                    lvx128    v60, r10, r11
                    stvx128   v60, r11, r7
                  }
                  _R11 += 32;
                  --v72;
                }
                while ( v72 != 0 );
              }
              ++v49;
              ++v50;
            }
            while ( v49 < *p_num );
            v5 = v135;
            v13 = v115;
            v6 = gui;
            v7 = shape;
          }
          _R11 = ((32 * *p_num) & 0xFFFFFF80) + v77;
          if ( (*p_num & 3) != 0 )
          {
            v79 = *p_num & 3;
            _R9 = &v132[-_R11];
            _R10 = (char *)v133 - _R11;
            _R8 = 16;
            do
            {
              __asm
              {
                lvx128    v59, r9, r11
                stvx128   v59, r0, r11
                lvx128    v58, r10, r11
                stvx128   v58, r11, r8
              }
              _R11 += 32;
              --v79;
            }
            while ( v79 != 0 );
          }
        }
      }
      HIDWORD(v10) = v109 * 280;
      HIDWORD(v11) = v109 * 280 + 280;
      ++v109;
      if ( ++v111 >= v7->fillDraws.num )
        goto LABEL_45;
    }
    HIDWORD(v33) = v19->style.startColor.r;
    LODWORD(v34) = v19->style.startColor.g;
    DWORD2(v34) = v19->style.startColor.b;
    LODWORD(v33) = v19->style.startColor.a;
    v129 = *(_QWORD *)(&type - 1);
    v130 = v34;
    v126 = *(_QWORD *)((char *)&v34 + 4);
    v122 = v33;
    v113.mul.w = (float)v33 * (float)0.0039215689;
    v113.mul.x = (float)*(__int64 *)(&type - 1) * (float)0.0039215689;
    v113.mul.z = (float)*(__int64 *)((char *)&v34 + 4) * (float)0.0039215689;
    v113.mul.y = (float)(__int64)v34 * (float)0.0039215689;
LABEL_10:
    atlasMaterial = v5->guiSolid;
    goto LABEL_11;
  }
LABEL_45:
  v83 = &v7->lineDraws.num;
  v84 = 0;
  HIDWORD(v122) = &v7->lineDraws.num;
  v112 = 0;
  if ( v7->lineDraws.num > 0 )
  {
    p_lineDraws = &v7->lineDraws;
    v86 = 0;
    v108 = p_lineDraws;
    v110 = 0;
    do
    {
      v114.mul.w = 1.0;
      v87 = p_lineDraws->list;
      v114.mul.y = 1.0;
      HIDWORD(v88) = &renderState->cxf;
      v114.mul.z = 1.0;
      v89 = (int)v87 + v86;
      v114.add.z = 0.0;
      v114.add.w = 0.0;
      v114.mul.x = 1.0;
      v114.add.x = 0.0;
      v114.add.y = 0.0;
      LODWORD(v88) = *(&v87->style.startColor.b + v86);
      LODWORD(v11) = *(&v87->style.startColor.g + v86);
      LODWORD(v10) = *(&v87->style.startColor.r + v86);
      v90 = *(&v87->style.startColor.a + v86);
      v119 = v10;
      v120 = v88;
      v121 = *(__int64 *)((char *)&v10 - 4);
      v118 = v11;
      v114.mul.x = (float)v10 * (float)0.0039215689;
      v114.mul.y = (float)v11 * (float)0.0039215689;
      v114.mul.z = (float)v88 * (float)0.0039215689;
      v114.mul.w = (float)*(__int64 *)((char *)&v10 - 4) * (float)0.0039215689;
      v91 = swfColorXform_t::Multiply(this: v134, result: &v114, a: &renderState->cxf);
      v114.mul.x = v91->mul.x;
      v114.mul.y = v91->mul.y;
      v114.mul.z = v91->mul.z;
      v92 = v91->mul.w;
      v114.mul.w = v91->mul.w;
      v114.add.x = v91->add.x;
      v114.add.y = v91->add.y;
      v114.add.z = v91->add.z;
      v93 = v13->valueFloat;
      v94 = v91->add.w;
      v114.add.w = v91->add.w;
      if ( v93 > 0.0 )
      {
        v114.mul.w = v93;
        v92 = v93;
        v114.add.w = 0.0;
        v94 = 0.0;
      }
      if ( (float)((float)v94 + (float)v92) > 0.001 )
      {
        v95 = idColor::PackColor(color: &v114.mul);
        v124.x = (float)(v114.add.x * v116) + v116;
        v124.y = (float)(v114.add.y * v116) + v116;
        v124.z = (float)(v114.add.z * v116) + v116;
        v124.w = (float)(v114.add.w * v116) + v116;
        v96 = idColor::PackColor(color: &v124);
        idSWF::GLStateForRenderState(this: v5, renderState);
        idRenderModelGui::SetGLState(this: v6, bits: v97);
        v98 = (_DWORD *)(v89 + 16);
        _R11 = idRenderModelGui::AllocTris(
                 this: v6,
                 numVerts: *(_DWORD *)(v89 + 16),
                 indexes: *(const unsigned __int16 **)(v89 + 44),
                 numIndexes: *(_DWORD *)(v89 + 48),
                 material: v5->white);
        if ( _R11 != nullptr )
        {
          LODWORD(v11) = 0;
          if ( (int)*v98 > 0 )
          {
            __asm { vspltisw128 v63, 0 }
            HIDWORD(v11) = v89 + 12;
            __asm { vcmpequw128 v57, v95, v63 }
            __asm { vsldoi128 v62, v95, v57, 4 }
            LODWORD(v10) = 0;
            _R3 = &v117;
            _R20 = &v117;
            do
            {
              __asm
              {
                stvx128   v63, r0, r3
                stvx128   v62, r20, r19
              }
              _R16 = &v117.add;
              HIDWORD(v10) = *(_DWORD *)HIDWORD(v11) + v10;
              v104 = renderState->matrix.tx;
              _R17 = &v117;
              v117.mul.z = 0.0;
              v117.mul.w = 0.0;
              LOBYTE(v117.add.w) = HIBYTE(v95);
              v117.add.x = 0.0;
              BYTE2(v117.add.z) = BYTE1(v96);
              HIBYTE(v117.add.z) = v96;
              LODWORD(v11) = v11 + 1;
              v106 = *(float *)HIDWORD(v10);
              BYTE2(v117.add.w) = BYTE1(v95);
              BYTE1(v117.add.w) = BYTE2(v95);
              LODWORD(v10) = v10 + 8;
              HIBYTE(v117.add.w) = v95;
              LOBYTE(v117.add.z) = HIBYTE(v96);
              BYTE1(v117.add.z) = BYTE2(v96);
              v107 = (float)((float)((float)((float)v106 * renderState->matrix.yx)
                                   + (float)(*(float *)(HIDWORD(v10) + 4) * renderState->matrix.yy))
                           + renderState->matrix.ty);
              v117.mul.x = (float)((float)((float)v106 * renderState->matrix.xx)
                                 + (float)(*(float *)(HIDWORD(v10) + 4) * renderState->matrix.xy))
                         + (float)v104;
              v117.mul.y = v107;
              __asm
              {
                lvx128    v56, r0, r17
                stvx128   v56, r0, r11
                lvx128    v55, r0, r16
                stvx128   v55, r11, r19
              }
              ++_R11;
              HIDWORD(v10) = *v98;
            }
            while ( (int)v11 < *v98 );
            v84 = v112;
            v86 = v110;
            p_lineDraws = v108;
            v83 = (int *)HIDWORD(v122);
            v5 = v135;
            v13 = v115;
            v6 = gui;
          }
        }
      }
      ++v84;
      v86 += 60;
      v112 = v84;
      v110 = v86;
    }
    while ( v84 < *v83 );
  }
}


// ========================================================================
// ?RenderRadial@idSWF@@AAAXPAVidRenderModelGui@@PAVidSWFSpriteInstance@@ABUswfRenderState_t@@H_N@Z
// EA  : 0x8277F510
// RVA : 0x0077F510
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::RenderRadial(
        idSWF *this,
        idRenderModelGui *gui,
        idSWFSpriteInstance *spriteInstance,
        const swfRenderState_t *renderState,
        int time,
        bool isSplitscreen)
{
  unsigned __int16 *p_currentFrame; // r17
  unsigned __int64 v12; // r6
  int *p_num; // r18
  int v14; // r20
  idList<swfDisplayEntry_t,72> *p_displayList; // r19
  int v16; // r21
  __int64 v18; // r11
  idSWFDictionaryEntry *DictionaryEntry; // r3
  int v20; // r2 OVERLAPPED
  idSWFShape *shape; // r30
  int v22; // r29
  int v27; // r31
  int v28; // r8
  int v29; // r3
  __int64 v30; // r6
  unsigned int v31; // r9
  int v32; // r3
  int v33; // r9
  int v62; // r9
  int v63; // ctr
  double v68; // fp12
  double v69; // fp11
  int v70; // r27
  double v71; // fp31
  double v72; // fp30
  double v73; // fp29
  double v74; // fp28
  int v75; // r8
  _WORD *v76; // r11
  int i; // ctr
  int v78; // r7
  idDrawVert *v79; // r3
  idDrawVert *v82; // r26
  unsigned int v84; // r3
  unsigned int v85; // r3
  long double v87; // fp2
  int v90; // r31
  double v92; // fp20
  long double v93; // fp2
  float v97; // [sp+60h] [-630h] BYREF
  float v98; // [sp+64h] [-62Ch]
  float v99; // [sp+68h] [-628h]
  _BYTE v100[16]; // [sp+70h] [-620h] BYREF
  idVec4 v101; // [sp+80h] [-610h] BYREF
  float v102; // [sp+90h] [-600h]
  float v103; // [sp+94h] [-5FCh]
  float v104; // [sp+98h] [-5F8h]
  float v105; // [sp+9Ch] [-5F4h]
  idVec4 v106; // [sp+A0h] [-5F0h] BYREF
  __int64 v107; // [sp+B0h] [-5E0h]
  __int64 v108; // [sp+B8h] [-5D8h]
  __int64 v109; // [sp+C0h] [-5D0h]
  __int64 v110; // [sp+C8h] [-5C8h] BYREF
  unsigned __int16 v111[672]; // [sp+D0h] [-5C0h] BYREF

  _R12 = -272;
  __asm { stvx128   v127, r1, r12 }
  p_currentFrame = &spriteInstance->currentFrame;
  if ( spriteInstance->currentFrame > 1u )
  {
    idSWF::GLStateForRenderState(this, renderState);
    idRenderModelGui::SetGLState(this: gui, bits: v12);
    p_num = &spriteInstance->displayList.num;
    v14 = 0;
    if ( spriteInstance->displayList.num > 0 )
    {
      p_displayList = &spriteInstance->displayList;
      v16 = 0;
      _R25 = 16;
      do
      {
        DictionaryEntry = idSWF::FindDictionaryEntry(this, characterID: p_displayList->list[v16].characterID);
        if ( DictionaryEntry != nullptr && DictionaryEntry->type == SWF_DICT_SHAPE )
        {
          shape = DictionaryEntry->shape;
          v101.x = 1.0;
          v101.y = 1.0;
          v22 = 0;
          v101.z = 1.0;
          _FP0 = 100000.0;
          v101.w = 1.0;
          _FP13 = 100000.0;
          v102 = 0.0;
          _FP12 = -100000.0;
          v103 = 0.0;
          _FP11 = -100000.0;
          v104 = 0.0;
          v105 = 0.0;
          if ( shape->fillDraws.num > 0 )
          {
            v27 = 0;
            do
            {
              v28 = 0;
              HIDWORD(v30) = &shape->fillDraws.list[v27];
              LODWORD(v18) = *(unsigned __int8 *)(HIDWORD(v30) + 4);
              v29 = *(unsigned __int8 *)(HIDWORD(v30) + 3);
              LODWORD(v30) = *(unsigned __int8 *)(HIDWORD(v30) + 2);
              v31 = *(unsigned __int8 *)(HIDWORD(v30) + 5);
              v109 = v18;
              v110 = *(_QWORD *)(&v20 - 1);
              v108 = v30;
              v101.w = (float)v31 * (float)0.0039215689;
              v101.z = (float)v18 * (float)0.0039215689;
              v101.y = (float)*(__int64 *)(&v20 - 1) * (float)0.0039215689;
              v101.x = (float)v30 * (float)0.0039215689;
              v32 = *(_DWORD *)(HIDWORD(v30) + 236);
              if ( v32 >= 4 )
              {
                v33 = *(_DWORD *)(HIDWORD(v30) + 232);
                LODWORD(v18) = 0;
                do
                {
                  v28 += 4;
                  HIDWORD(v18) = v33 + v18 + 24;
                  _FP20 = (float)((float)_FP0
                                - (float)((float)((float)(*(float *)(v33 + v18) * renderState->matrix.xx)
                                                + (float)(renderState->matrix.xy * *(float *)(v33 + v18 + 4)))
                                        + renderState->matrix.tx));
                  _FP19 = (float)((float)_FP13
                                - (float)((float)((float)(renderState->matrix.yx * *(float *)(v33 + v18))
                                                + (float)(renderState->matrix.yy * *(float *)(v33 + v18 + 4)))
                                        + renderState->matrix.ty));
                  _FP18 = (float)((float)_FP12
                                - (float)((float)((float)(*(float *)(v33 + v18) * renderState->matrix.xx)
                                                + (float)(renderState->matrix.xy * *(float *)(v33 + v18 + 4)))
                                        + renderState->matrix.tx));
                  _FP17 = (float)((float)_FP11
                                - (float)((float)((float)(renderState->matrix.yx * *(float *)(v33 + v18))
                                                + (float)(renderState->matrix.yy * *(float *)(v33 + v18 + 4)))
                                        + renderState->matrix.ty));
                  __asm
                  {
                    fsel      f0, f20, f2, f0
                    fsel      f13, f19, f4, f13
                    fsel      f12, f18, f12, f2
                    fsel      f11, f17, f11, f4
                  }
                  _FP4 = (float)((float)_FP0
                               - (float)((float)((float)(*(float *)(v33 + v18 + 8) * renderState->matrix.xx)
                                               + (float)(renderState->matrix.xy * *(float *)(v33 + v18 + 12)))
                                       + renderState->matrix.tx));
                  _FP2 = (float)((float)_FP13
                               - (float)((float)((float)(renderState->matrix.yx * *(float *)(v33 + v18 + 8))
                                               + (float)(renderState->matrix.yy * *(float *)(v33 + v18 + 12)))
                                       + renderState->matrix.ty));
                  _FP20 = (float)((float)_FP12
                                - (float)((float)((float)(*(float *)(v33 + v18 + 8) * renderState->matrix.xx)
                                                + (float)(renderState->matrix.xy * *(float *)(v33 + v18 + 12)))
                                        + renderState->matrix.tx));
                  _FP19 = (float)((float)_FP11
                                - (float)((float)((float)(renderState->matrix.yx * *(float *)(v33 + v18 + 8))
                                                + (float)(renderState->matrix.yy * *(float *)(v33 + v18 + 12)))
                                        + renderState->matrix.ty));
                  __asm
                  {
                    fsel      f0, f4, f3, f0
                    fsel      f13, f2, f1, f13
                    fsel      f12, f20, f12, f3
                    fsel      f11, f19, f11, f1
                  }
                  _FP4 = (float)((float)_FP0
                               - (float)((float)((float)(*(float *)(HIDWORD(v18) - 8) * renderState->matrix.xx)
                                               + (float)(renderState->matrix.xy * *(float *)(HIDWORD(v18) - 4)))
                                       + renderState->matrix.tx));
                  _FP3 = (float)((float)_FP13
                               - (float)((float)((float)(renderState->matrix.yx * *(float *)(HIDWORD(v18) - 8))
                                               + (float)(renderState->matrix.yy * *(float *)(HIDWORD(v18) - 4)))
                                       + renderState->matrix.ty));
                  _FP2 = (float)((float)_FP12
                               - (float)((float)((float)(*(float *)(HIDWORD(v18) - 8) * renderState->matrix.xx)
                                               + (float)(renderState->matrix.xy * *(float *)(HIDWORD(v18) - 4)))
                                       + renderState->matrix.tx));
                  _FP1 = (float)((float)_FP11
                               - (float)((float)((float)(renderState->matrix.yx * *(float *)(HIDWORD(v18) - 8))
                                               + (float)(renderState->matrix.yy * *(float *)(HIDWORD(v18) - 4)))
                                       + renderState->matrix.ty));
                  __asm
                  {
                    fsel      f0, f4, f31, f0
                    fsel      f13, f3, f30, f13
                    fsel      f12, f2, f12, f31
                    fsel      f11, f1, f11, f30
                  }
                  _FP4 = (float)((float)_FP0
                               - (float)((float)((float)(*(float *)HIDWORD(v18) * renderState->matrix.xx)
                                               + (float)(renderState->matrix.xy * *(float *)(HIDWORD(v18) + 4)))
                                       + renderState->matrix.tx));
                  _FP3 = (float)((float)_FP13
                               - (float)((float)((float)(renderState->matrix.yx * *(float *)HIDWORD(v18))
                                               + (float)(renderState->matrix.yy * *(float *)(HIDWORD(v18) + 4)))
                                       + renderState->matrix.ty));
                  _FP2 = (float)((float)_FP12
                               - (float)((float)((float)(*(float *)HIDWORD(v18) * renderState->matrix.xx)
                                               + (float)(renderState->matrix.xy * *(float *)(HIDWORD(v18) + 4)))
                                       + renderState->matrix.tx));
                  _FP1 = (float)((float)_FP11
                               - (float)((float)((float)(renderState->matrix.yx * *(float *)HIDWORD(v18))
                                               + (float)(renderState->matrix.yy * *(float *)(HIDWORD(v18) + 4)))
                                       + renderState->matrix.ty));
                  LODWORD(v18) = v18 + 32;
                  __asm
                  {
                    fsel      f0, f4, f29, f0
                    fsel      f13, f3, f28, f13
                    fsel      f12, f2, f12, f29
                    fsel      f11, f1, f11, f28
                  }
                }
                while ( v28 < v32 - 3 );
              }
              if ( v28 < v32 )
              {
                v62 = *(_DWORD *)(HIDWORD(v30) + 232);
                LODWORD(v18) = 8 * v28;
                v63 = v32 - v28;
                do
                {
                  HIDWORD(v18) = v62 + v18;
                  _FP4 = (float)((float)_FP0
                               - (float)((float)((float)(*(float *)(v62 + v18 + 4) * renderState->matrix.xy)
                                               + (float)(*(float *)(v62 + v18) * renderState->matrix.xx))
                                       + renderState->matrix.tx));
                  _FP3 = (float)((float)_FP13
                               - (float)((float)((float)(*(float *)(v62 + v18 + 4) * renderState->matrix.yy)
                                               + (float)(renderState->matrix.yx * *(float *)(v62 + v18)))
                                       + renderState->matrix.ty));
                  _FP31 = (float)((float)_FP12
                                - (float)((float)((float)(*(float *)(v62 + v18 + 4) * renderState->matrix.xy)
                                                + (float)(*(float *)(v62 + v18) * renderState->matrix.xx))
                                        + renderState->matrix.tx));
                  _FP30 = (float)((float)_FP11
                                - (float)((float)((float)(*(float *)(v62 + v18 + 4) * renderState->matrix.yy)
                                                + (float)(renderState->matrix.yx * *(float *)(v62 + v18)))
                                        + renderState->matrix.ty));
                  LODWORD(v18) = v18 + 8;
                  __asm
                  {
                    fsel      f0, f4, f2, f0
                    fsel      f13, f3, f1, f13
                    fsel      f12, f31, f12, f2
                    fsel      f11, f30, f11, f1
                  }
                  --v63;
                }
                while ( v63 != 0 );
              }
              ++v22;
              ++v27;
            }
            while ( v22 < shape->fillDraws.num );
          }
          v68 = (float)((float)_FP12 - (float)_FP0);
          v69 = (float)((float)_FP11 - (float)_FP13);
          v70 = *p_currentFrame - 1;
          v71 = (float)((float)v68 * (float)0.5);
          v72 = (float)((float)v69 * (float)0.5);
          v73 = (float)((float)((float)v68 * (float)0.5) + (float)_FP0);
          v74 = (float)((float)((float)v69 * (float)0.5) + (float)_FP13);
          if ( v70 >= 199 )
            v70 = 199;
          v75 = 0;
          if ( v70 > 0 )
          {
            v76 = (_WORD *)&v110 + 3;
            for ( i = v70; i != 0; --i )
            {
              v76[1] = v70;
              v76[2] = v75;
              v78 = ++v75 / 199;
              v76 += 3;
              *v76 = v75 - 199 * v78;
            }
          }
          v79 = idRenderModelGui::AllocTris(
                  this: gui,
                  numVerts: v70 + 1,
                  indexes: v111,
                  numIndexes: 3 * v70,
                  material: this->guiSolid);
          __asm { vspltisw128 v63, 0 }
          _R11 = &v97;
          _R10 = &v97;
          v82 = v79;
          __asm { vcmpequw128 v62, v95, v63 }
          __asm
          {
            stvx128   v63, r0, r11
            vsldoi128 v61, v95, v62, 4
            stvx128   v61, r10, r25
          }
          v84 = idColor::PackColor(color: &v101);
          v100[12] = v84;
          v100[15] = HIBYTE(v84);
          v100[14] = BYTE1(v84);
          v100[13] = BYTE2(v84);
          v106.x = (float)(v102 * (float)0.5) + (float)0.5;
          v106.y = (float)(v103 * (float)0.5) + (float)0.5;
          v106.z = (float)(v104 * (float)0.5) + (float)0.5;
          v106.w = (float)(v105 * (float)0.5) + (float)0.5;
          v85 = idColor::PackColor(color: &v106);
          _R4 = v100;
          v99 = 0.0;
          HIDWORD(_R11) = BYTE1(v85);
          v100[8] = v85;
          v100[11] = HIBYTE(v85);
          v100[10] = BYTE1(v85);
          v90 = 0;
          v100[9] = BYTE2(v85);
          __asm { lvx128    v127, r0, r4 }
          if ( v70 + 1 > 0 )
          {
            _R30 = v82;
            do
            {
              LODWORD(_R11) = v90;
              v107 = _R11;
              v92 = (float)((float)_R11 * (float)0.031573795);
              *(double *)&v87 = v92;
              v93 = sin(x: v87);
              v97 = (float)((float)*(double *)&v93 * (float)v71) + (float)v73;
              *(double *)&v93 = v92;
              v87 = cos(x: v93);
              HIDWORD(_R11) = &v97;
              ++v90;
              v98 = -(float)((float)((float)*(double *)&v87 * (float)v72) - (float)v74);
              __asm
              {
                lvx128    v60, r0, r10
                stvx128   v60, r0, r30
                stvx128   v127, r30, r25
              }
              ++_R30;
            }
            while ( v90 < v70 + 1 );
          }
          _R10 = &v97;
          v98 = v74;
          v97 = v73;
          _R11 = &v82[v70];
          __asm
          {
            lvx128    v59, r0, r10
            stvx128   v59, r0, r11
            stvx128   v127, r11, r25
          }
        }
        ++v14;
        ++v16;
      }
      while ( v14 < *p_num );
    }
  }
  _R0 = -272;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?DrawEditCursor@idSWF@@AAAXPAVidRenderModelGui@@MMMMABUswfMatrix_t@@@Z
// EA  : 0x8277FA98
// RVA : 0x0077FA98
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __fastcall idSWF::DrawEditCursor(
        idSWF *this,
        idRenderModelGui *gui,
        double x,
        double y,
        double w,
        double h,
        const swfMatrix_t *matrix,
        int a8,
        int a9,
        int a10,
        float *a11)
{
  double v11; // fp12
  double v12; // fp10
  double v13; // fp5
  double v14; // fp6
  double v15; // fp4
  double v16; // fp7
  double v17; // fp3
  double v18; // fp2
  double v19; // fp1
  double v20; // fp9
  double v21; // fp8
  double v22; // fp12
  const idMaterial *white; // r8
  idVec4 v24; // [sp+50h] [-50h] BYREF
  idVec4 v25; // [sp+60h] [-40h] BYREF
  idVec4 v26; // [sp+70h] [-30h] BYREF
  idVec4 v27; // [sp+80h] [-20h] BYREF

  v11 = (float)((float)x + (float)w);
  v12 = (float)((float)y + (float)h);
  v13 = (float)(*a11 * (float)x);
  v14 = a11[1];
  v15 = (float)(a11[3] * (float)x);
  v16 = (float)(a11[2] * (float)y);
  v17 = (float)(a11[1] * (float)y);
  v18 = a11[4];
  v19 = a11[5];
  v20 = (float)((float)v11 * *a11);
  v21 = (float)((float)v11 * a11[3]);
  v22 = (float)((float)v12 * a11[2]);
  v27.z = 0.0;
  v25.w = 0.0;
  v24.z = 0.0;
  v24.w = 0.0;
  v27.w = 1.0;
  v26.z = 1.0;
  v26.w = 1.0;
  v25.z = 1.0;
  white = this->white;
  v24.x = (float)((float)v13 + (float)v16) + (float)v18;
  v24.y = (float)((float)v17 + (float)v15) + (float)v19;
  v25.x = (float)((float)v20 + (float)v16) + (float)v18;
  v25.y = (float)((float)v21 + (float)v17) + (float)v19;
  v27.x = (float)((float)v22 + (float)v13) + (float)v18;
  v26.x = (float)((float)v22 + (float)v20) + (float)v18;
  v27.y = (float)((float)((float)v12 * (float)v14) + (float)v15) + (float)v19;
  v26.y = (float)((float)((float)v12 * (float)v14) + (float)v21) + (float)v19;
  idRenderModelGui::DrawStretchPic(
    this: gui,
    topLeft: &v24,
    topRight: &v25,
    bottomRight: &v26,
    bottomLeft: &v27,
    material: white);
}


// ========================================================================
// ?RenderMorphShape@idSWF@@AAAXPAVidRenderModelGui@@PBVidSWFShape@@ABUswfRenderState_t@@@Z
// EA  : 0x8277FC20
// RVA : 0x0077FC20
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::RenderMorphShape(
        idSWF *this,
        idRenderModelGui *gui,
        const idSWFShape *shape,
        const swfRenderState_t *renderState)
{
  float v4; // r2 OVERLAPPED
  idSWF *v5; // r24
  idRenderModelGui *v6; // r22
  const idSWFShape *v7; // r25
  int num; // r10
  int v10; // r21
  __int64 v11; // r9 OVERLAPPED
  int v12; // r23
  idCVar *v13; // r18
  idSWFShapeDrawFill *list; // r10
  const idMaterial *material; // r27
  unsigned __int8 *v17; // r31
  __int64 v18; // r11
  double ratio; // fp0
  __int64 v20; // r6 OVERLAPPED
  __int64 v21; // r4 OVERLAPPED
  int v22; // r7
  __int64 v23; // fp9
  int v24; // r10
  swfColorXform_t *v25; // r3
  double valueFloat; // fp0
  double w; // fp13
  double v28; // fp12
  unsigned int v29; // r29
  unsigned int v30; // r3
  __int128 v31; // r11
  unsigned int v32; // r28
  float *p_ratio; // r26
  double v34; // fp27
  double v35; // fp28
  __int64 v36; // r9
  double v37; // fp31
  __int64 v38; // r8
  __int64 v39; // r11
  double v40; // fp0
  double v41; // fp13
  double v42; // fp31
  double v43; // fp30
  double v44; // fp10
  double v45; // fp9
  double v46; // fp0
  double v47; // fp8
  double v48; // fp6
  double v49; // fp7
  double v50; // fp3
  double v51; // fp1
  double v52; // fp13
  double v53; // fp12
  unsigned __int64 v54; // r6
  int *v55; // r20
  idDrawVert *v56; // r3
  int v58; // r11
  double v61; // fp4
  double yy; // fp17
  double xy; // fp21
  double yx; // fp3
  double ty; // fp19
  float v67; // r3
  double v68; // fp0
  double v69; // fp4
  int v70; // r10
  int v71; // [sp+50h] [-250h]
  swfColorXform_t v72; // [sp+60h] [-240h] BYREF
  int v73; // [sp+80h] [-220h]
  __int64 v74; // [sp+88h] [-218h]
  float v75[4]; // [sp+90h] [-210h] BYREF
  float v76; // [sp+A0h] [-200h] BYREF
  char v77; // [sp+A8h] [-1F8h]
  char v78; // [sp+A9h] [-1F7h]
  char v79; // [sp+AAh] [-1F6h]
  char v80; // [sp+ABh] [-1F5h]
  char v81; // [sp+ACh] [-1F4h]
  char v82; // [sp+ADh] [-1F3h]
  char v83; // [sp+AEh] [-1F2h]
  char v84; // [sp+AFh] [-1F1h]
  idCVar *v85; // [sp+B0h] [-1F0h]
  idVec4 v86; // [sp+C0h] [-1E0h] BYREF
  swfMatrix_t v87; // [sp+D0h] [-1D0h] BYREF
  swfMatrix_t v88; // [sp+F0h] [-1B0h] BYREF
  __int64 v89; // [sp+108h] [-198h]
  __int64 v90; // [sp+110h] [-190h]
  __int64 v91; // [sp+118h] [-188h]
  __int64 v92; // [sp+120h] [-180h]
  __int64 v93; // [sp+128h] [-178h]
  __int64 v94; // [sp+130h] [-170h]
  __int64 v95; // [sp+138h] [-168h]
  __int64 v96; // [sp+140h] [-160h]
  __int64 v97; // [sp+148h] [-158h]
  __int64 v98; // [sp+150h] [-150h]
  __int64 v99; // [sp+158h] [-148h]
  __int64 v100; // [sp+160h] [-140h]
  swfColorXform_t v101[4]; // [sp+170h] [-130h] BYREF

  v5 = this;
  v6 = gui;
  v7 = shape;
  if ( shape != nullptr )
  {
    num = shape->fillDraws.num;
    v10 = 0;
    v73 = 0;
    if ( num > 0 )
    {
      HIDWORD(v11) = byte_821B0000;
      v12 = 0;
      v13 = &swf_forceAlpha;
      v71 = 0;
      _R19 = 16;
      v85 = &swf_forceAlpha;
      do
      {
        list = v7->fillDraws.list;
        material = renderState->material;
        v72.mul.x = 1.0;
        v72.mul.y = 1.0;
        v72.mul.z = 1.0;
        v17 = &list->style.type + v12;
        v72.mul.w = 1.0;
        v72.add.x = 0.0;
        v72.add.y = 0.0;
        v72.add.z = 0.0;
        v72.add.w = 0.0;
        if ( material == nullptr )
        {
          if ( *v17 != 0 )
          {
            if ( *v17 != 4 || (v24 = *((unsigned __int16 *)v17 + 114)) == 0xFFFF )
              material = v5->guiSolid;
            else
              material = v5->dictionary.list[v24].material;
          }
          else
          {
            HIDWORD(v18) = v17[3];
            ratio = renderState->ratio;
            LODWORD(v20) = v17[6];
            LODWORD(v21) = v17[7];
            HIDWORD(v20) = HIDWORD(v18);
            v22 = v17[2];
            HIDWORD(v21) = v17[4];
            LODWORD(v18) = v17[8];
            LODWORD(v11) = v17[9];
            v91 = v20;
            v93 = v21;
            v99 = *(__int64 *)((char *)&v20 - 4);
            v89 = *(__int64 *)((char *)&v11 - 4);
            v92 = *(_QWORD *)(&v4 - 1);
            v95 = v18;
            v97 = v11;
            v23 = v11;
            HIDWORD(v11) = v17[5];
            material = v5->guiSolid;
            v96 = *(__int64 *)((char *)&v11 + 4);
            v72.mul.y = (float)((float)((float)((float)v21 * (float)0.0039215689)
                                      - (float)((float)*(__int64 *)((char *)&v11 - 4) * (float)0.0039215689))
                              * (float)ratio)
                      + (float)((float)*(__int64 *)((char *)&v11 - 4) * (float)0.0039215689);
            v72.mul.x = (float)((float)((float)((float)v20 * (float)0.0039215689)
                                      - (float)((float)*(__int64 *)((char *)&v20 - 4) * (float)0.0039215689))
                              * (float)ratio)
                      + (float)((float)*(__int64 *)((char *)&v20 - 4) * (float)0.0039215689);
            v72.mul.z = (float)((float)((float)((float)v18 * (float)0.0039215689)
                                      - (float)((float)*(__int64 *)(&v4 - 1) * (float)0.0039215689))
                              * (float)ratio)
                      + (float)((float)*(__int64 *)(&v4 - 1) * (float)0.0039215689);
            v72.mul.w = (float)((float)((float)((float)v23 * (float)0.0039215689)
                                      - (float)((float)*(__int64 *)((char *)&v11 + 4) * (float)0.0039215689))
                              * (float)ratio)
                      + (float)((float)*(__int64 *)((char *)&v11 + 4) * (float)0.0039215689);
          }
        }
        v25 = swfColorXform_t::Multiply(this: v101, result: &v72, a: &renderState->cxf);
        v72.mul.x = v25->mul.x;
        valueFloat = v13->valueFloat;
        v72.mul.y = v25->mul.y;
        v72.mul.z = v25->mul.z;
        w = v25->mul.w;
        v72.mul.w = v25->mul.w;
        v72.add.x = v25->add.x;
        v72.add.y = v25->add.y;
        v72.add.z = v25->add.z;
        v28 = v25->add.w;
        v72.add.w = v25->add.w;
        if ( valueFloat > 0.0 )
        {
          v72.mul.w = valueFloat;
          w = valueFloat;
          v72.add.w = 0.0;
          v28 = 0.0;
        }
        if ( (float)((float)v28 + (float)w) > 0.001 )
        {
          v29 = idColor::PackColor(color: &v72.mul);
          v86.x = (float)(v72.add.x * (float)0.5) + (float)0.5;
          v86.y = (float)(v72.add.y * (float)0.5) + (float)0.5;
          v86.z = (float)(v72.add.z * (float)0.5) + (float)0.5;
          v86.w = (float)(v72.add.w * (float)0.5) + (float)0.5;
          v30 = idColor::PackColor(color: &v86);
          *((_QWORD *)&v31 + 1) = v7->startBounds.tl;
          *(idVec2 *)((char *)&v31 + 4) = v7->endBounds.tl;
          v32 = v30;
          p_ratio = &renderState->ratio;
          v34 = (float)((float)((float)(*((float *)&v31 + 2) - *((float *)&v31 + 3)) * renderState->ratio)
                      + *((float *)&v31 + 3));
          v35 = (float)((float)((float)(*((float *)&v31 + 1) - *((float *)&v31 + 2)) * renderState->ratio)
                      + *((float *)&v31 + 2));
          v74 = v31;
          LODWORD(v36) = idMaterial::GetHeight(this: material);
          v100 = v36;
          v37 = (float)v36;
          LODWORD(v38) = idMaterial::GetWidth(this: material);
          LODWORD(v39) = renderState->materialWidth;
          v40 = v37;
          v94 = v38;
          v41 = (float)v38;
          if ( (int)v39 > 0 )
          {
            v98 = v39;
            v41 = (float)v39;
          }
          LODWORD(v39) = renderState->materialHeight;
          if ( (int)v39 > 0 )
          {
            v90 = v39;
            v40 = (float)v39;
          }
          v42 = (float)((float)1.0 / (float)v41);
          v43 = (float)((float)1.0 / (float)v40);
          v44 = *((float *)v17 + 5);
          v45 = *((float *)v17 + 6);
          v46 = (float)(*((float *)v17 + 11) - *((float *)v17 + 5));
          v47 = *((float *)v17 + 7);
          v48 = (float)(*((float *)v17 + 12) - *((float *)v17 + 6));
          v49 = *((float *)v17 + 8);
          v50 = (float)(*((float *)v17 + 13) - *((float *)v17 + 7));
          v51 = (float)(*((float *)v17 + 14) - *((float *)v17 + 8));
          v52 = *p_ratio;
          v53 = (float)((float)((float)(*((float *)v17 + 9) - *((float *)v17 + 3)) * *p_ratio) + *((float *)v17 + 3));
          v88.yy = (float)((float)(*((float *)v17 + 10) - *((float *)v17 + 4)) * *p_ratio) + *((float *)v17 + 4);
          v88.xx = v53;
          v88.xy = (float)((float)v46 * (float)v52) + (float)v44;
          v88.yx = (float)((float)v48 * (float)v52) + (float)v45;
          v88.tx = (float)((float)v50 * (float)v52) + (float)v47;
          v88.ty = (float)((float)v51 * (float)v52) + (float)v49;
          swfMatrix_t::Inverse(this: &v87, result: &v88);
          idSWF::GLStateForRenderState(this: v5, renderState);
          idRenderModelGui::SetGLState(this: v6, bits: v54);
          v55 = (int *)(v17 + 236);
          v56 = idRenderModelGui::AllocTris(
                  this: v6,
                  numVerts: *((_DWORD *)v17 + 59),
                  indexes: *((const unsigned __int16 **)v17 + 66),
                  numIndexes: *((_DWORD *)v17 + 67),
                  material);
          if ( v56 != nullptr )
          {
            LODWORD(v11) = 0;
            if ( *v55 > 0 )
            {
              __asm { vspltisw128 v63, 0 }
              HIDWORD(v11) = v17 + 248;
              __asm { vcmpequw128 v62, v95, v63 }
              __asm { vsldoi128 v62, v95, v62, 4 }
              v58 = 0;
              _R10 = v56;
              do
              {
                _R14 = &v76;
                v61 = renderState->ratio;
                HIDWORD(_R18) = v75;
                LODWORD(v11) = v11 + 1;
                *(_QWORD *)(&v4 - 1) = *(_QWORD *)(v58 + *(_DWORD *)HIDWORD(v11));
                *((_QWORD *)&_R18 + 1) = *(_QWORD *)(v58 + *((_DWORD *)v17 + 58));
                __asm { stvx128   v63, r0, r17 }
                v58 += 8;
                __asm { stvx128   v62, r15, r19 }
                v84 = HIBYTE(v29);
                yy = renderState->matrix.yy;
                v83 = BYTE1(v29);
                xy = renderState->matrix.xy;
                yx = renderState->matrix.yx;
                v82 = BYTE2(v29);
                ty = renderState->matrix.ty;
                v81 = v29;
                v75[2] = 0.0;
                v80 = HIBYTE(v32);
                v79 = BYTE1(v32);
                v78 = BYTE2(v32);
                v77 = v32;
                *(_QWORD *)((char *)&_R18 + 4) = *(_QWORD *)(&v4 - 1);
                v68 = (float)((float)((float)(v4 - v67) * (float)v61) + v67);
                v69 = (float)((float)(v67 - *((float *)&_R18 + 3)) * (float)v61);
                v75[0] = (float)((float)(renderState->matrix.xx * (float)v68)
                               + (float)((float)((float)v69 + *((float *)&_R18 + 3)) * (float)xy))
                       + renderState->matrix.tx;
                v74 = _R18;
                v75[1] = (float)((float)((float)yx * (float)v68)
                               + (float)((float)yy * (float)((float)v69 + *((float *)&_R18 + 3))))
                       + (float)ty;
                v75[3] = (float)((float)((float)(v87.xy
                                               * (float)((float)((float)((float)((float)v69 + *((float *)&_R18 + 3))
                                                                       - (float)v34)
                                                               * (float)v43)
                                                       * (float)20.0))
                                       + (float)(v87.xx
                                               * (float)((float)((float)((float)v68 - (float)v35) * (float)v42)
                                                       * (float)20.0)))
                               + v87.tx)
                       + (float)((float)v42 * (float)0.5);
                v76 = (float)((float)((float)(v87.yy
                                            * (float)((float)((float)((float)((float)v69 + *((float *)&_R18 + 3))
                                                                    - (float)v34)
                                                            * (float)v43)
                                                    * (float)20.0))
                                    + (float)(v87.yx
                                            * (float)((float)((float)((float)v68 - (float)v35) * (float)v42)
                                                    * (float)20.0)))
                            + v87.ty)
                    + (float)((float)v43 * (float)0.5);
                __asm
                {
                  lvx128    v61, r0, r16
                  stvx128   v61, r0, r10
                  lvx128    v60, r0, r14
                  stvx128   v60, r10, r19
                }
                ++_R10;
                _R19 = 16;
              }
              while ( (int)v11 < *v55 );
              v12 = v71;
              v13 = v85;
              v10 = v73;
              v6 = gui;
              v7 = shape;
              v5 = this;
            }
          }
        }
        v70 = v7->fillDraws.num;
        ++v10;
        v12 += 280;
        v73 = v10;
        v71 = v12;
      }
      while ( v10 < v70 );
    }
  }
  else
  {
    idLib::Warning(fmt: "%s: RenderMorphShape: shape == NULL", this->filename.str);
  }
}


// ========================================================================
// ?CreateAltasImageAndMaterial@idSWF@@QAAXXZ
// EA  : 0x82780320
// RVA : 0x00780320
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __fastcall idSWF::CreateAltasImageAndMaterial(idSWF *this)
{
  int atlasWidth; // r6
  const char *str; // r4
  bool atlasPurgable; // r10
  idImageOpts v5; // [sp+50h] [-5A0h] BYREF
  idStr v6; // [sp+A0h] [-550h] BYREF
  int v7; // [sp+C0h] [-530h] BYREF
  char v8[1072]; // [sp+1C0h] [-430h] BYREF

  fileSystem->FixLongFilename(
    this: fileSystem,
    a2: "generated",
    a3: "bswf",
    a4: this->filename.str,
    a5: (char *)&v7,
    a6: 256);
  atlasWidth = this->atlasWidth;
  str = this->atlasTextureName.str;
  memset(&v5.colorFormat, 0, 12);
  v5.cubeFilter = false;
  v5.depth = 0;
  v5.textureType = TT_2D;
  v5.packedTail = true;
  v5.readback = false;
  v5.forceBias = false;
  v5.border.x = 0.0;
  v5.depthCompareMode = false;
  v5.border.y = 0.0;
  v5.numLevels = 1;
  v5.border.z = 0.0;
  v5.border.w = 0.0;
  v5.linear = true;
  v5.lodBias = 0.0;
  v5.startPurged = true;
  v5.lodMinClamp = 0.0;
  v5.lodMaxClamp = 13.0;
  v5.format = FMT_DXT5;
  v5.aniso = 0.0;
  v5.width = atlasWidth;
  atlasPurgable = this->atlasPurgable;
  v5.height = this->atlasHeight;
  v5.overlayMemory = atlasPurgable;
  this->atlasImage = idImageManager::ScratchImage(this: globalImages, _name: str, imgOpts: &v5);
  sprintf_0(
    string: v8,
    format: "{\ntransmap %s\nstageprogram guiBlend_CoACgY_premulalpha\n}",
    this->atlasTextureName.str);
  idStr::idStr(this: &v6, text: this->filename.str);
  idStr::StripFileExtension(this: &v6);
  idStr::Append(this: &v6, text: "_");
  if ( common->IsClient(this: common) )
    idStr::Append(this: &v6, text: "atlas_client_");
  this->atlasMaterial = (const idMaterial *)declManager->CreateNewDecl(
                                              this: declManager,
                                              a2: &idMaterial::resourceList,
                                              a3: v6.data,
                                              a4: &byte_8200D768,
                                              a5: v8);
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 15u);
  this->atlasImage = idImageManager::ImageFromFile(
                       this: globalImages,
                       _name: this->atlasTextureName.str,
                       opts_p: &v5,
                       makeDefault: true);
  resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// __unwind$226035
// EA  : 0x82780508
// RVA : 0x00780508
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1520 + 160));
}


// ========================================================================
// ?RenderMask@idSWF@@AAAXPAVidRenderModelGui@@PBUswfDisplayEntry_t@@ABUswfRenderState_t@@PBVidMaterial@@@Z
// EA  : 0x82780530
// RVA : 0x00780530
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __fastcall idSWF::RenderMask(
        idSWF *this,
        idRenderModelGui *gui,
        const swfDisplayEntry_t *mask,
        const swfRenderState_t *renderState,
        const idMaterial *material)
{
  double xy; // fp0
  double yy; // fp13
  double xx; // fp10
  double yx; // fp8
  double v12; // fp11
  double v13; // fp9
  double tx; // fp4
  double v15; // fp5
  double v16; // fp2
  double v17; // fp1
  double v18; // fp0
  double v19; // fp12
  double v20; // fp3
  double v21; // fp13
  double ty; // fp7
  swfColorXform_t *v24; // r3
  idSWFDictionaryEntry *list; // r11
  double ratio; // fp0
  int characterID; // r10
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double w; // fp10
  double v32; // fp9
  double v33; // fp8
  double v34; // fp7
  double v35; // fp6
  idSWFDictionaryEntry *v36; // r11
  swfDictType_t type; // r10
  swfColorXform_t v38; // [sp+50h] [-A0h] BYREF
  swfRenderState_t v39; // [sp+70h] [-80h] BYREF

  xy = renderState->matrix.xy;
  yy = renderState->matrix.yy;
  xx = renderState->matrix.xx;
  yx = renderState->matrix.yx;
  memset(&v39.materialWidth, 0, 13);
  v12 = (float)(mask->matrix.ty * (float)xy);
  v13 = (float)(mask->matrix.ty * (float)yy);
  tx = mask->matrix.tx;
  v15 = (float)((float)xy * mask->matrix.yx);
  v16 = (float)(mask->matrix.yy * (float)xy);
  v17 = mask->matrix.xx;
  v18 = (float)(mask->matrix.yy * (float)yy);
  v19 = renderState->matrix.tx;
  v20 = (float)((float)yy * mask->matrix.yx);
  v21 = mask->matrix.xy;
  ty = renderState->matrix.ty;
  v39.matrix.xx = (float)((float)xx * mask->matrix.xx) + (float)v15;
  v39.matrix.xy = (float)((float)v21 * (float)xx) + (float)v16;
  v39.matrix.yx = (float)((float)yx * (float)v17) + (float)v20;
  v39.matrix.yy = (float)((float)v21 * (float)yx) + (float)v18;
  v39.matrix.tx = (float)((float)((float)tx * (float)xx) + (float)v12) + (float)v19;
  v39.matrix.ty = (float)((float)((float)tx * (float)yx) + (float)v13) + (float)ty;
  v24 = swfColorXform_t::Multiply(this: &v38, result: &mask->cxf, a: &renderState->cxf);
  list = this->dictionary.list;
  ratio = mask->ratio;
  characterID = mask->characterID;
  x = v24->mul.x;
  y = v24->mul.y;
  v39.material = material;
  z = v24->mul.z;
  w = v24->mul.w;
  v32 = v24->add.x;
  v33 = v24->add.y;
  v34 = v24->add.z;
  v35 = v24->add.w;
  v36 = &list[characterID];
  v39.ratio = ratio;
  v39.cxf.mul.x = x;
  v39.cxf.mul.y = y;
  v39.cxf.mul.z = z;
  v39.cxf.mul.w = w;
  type = v36->type;
  v39.cxf.add.x = v32;
  v39.cxf.add.y = v33;
  v39.cxf.add.z = v34;
  v39.cxf.add.w = v35;
  if ( type == SWF_DICT_SHAPE )
  {
    idSWF::RenderShape(this, gui, shape: v36->shape, renderState: &v39);
  }
  else if ( type == SWF_DICT_MORPH )
  {
    idSWF::RenderMorphShape(this, gui, shape: v36->shape, renderState: &v39);
  }
}


// ========================================================================
// ?FindTooltipIcons@idSWF@@AAAXPAVidStr@@HH@Z
// EA  : 0x82780AC8
// RVA : 0x00780AC8
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __fastcall idSWF::FindTooltipIcons(idSWF *this, idStr *text, bindSet_t bindset, int deviceNum)
{
  idList<idSWF::tooltipIcon_t,72> *p_tooltipIconList; // r24
  userCmdString_t *i; // r30
  const idStr *v10; // r3
  int v11; // r21
  int j; // r30
  int v13; // r29
  idSWF::keyButtonImages_t *list; // r10
  int v15; // r11
  const char *key; // r10
  int started; // r3
  idSWF::keyButtonImages_t *v18; // r11
  const char *psImage; // r4
  const idMaterial *v20; // r3
  const char *xbImage; // r4
  idSWF::keyButtonImages_t *v22; // r11
  int height; // r9
  int baseline; // r8
  int num; // r10
  char v26; // r8
  int v27; // r5
  int v28; // r11
  idSWF::tooltipIcon_t v29; // [sp+50h] [-C0h] BYREF
  idStr v30; // [sp+70h] [-A0h] BYREF
  idStr v31[4]; // [sp+90h] [-80h] BYREF

  p_tooltipIconList = &this->tooltipIconList;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tooltipIconList);
  for ( i = userCmdStrings; i->string != nullptr; ++i )
  {
    if ( idStr::Find(searchIn: text->data, searchFor: i->string, casesensitive: false, start: 0, end: -1) != -1 )
    {
      v30.allocedAndFlag = 20;
      v30.len = 0;
      v30.data = v30.baseBuffer;
      v30.baseBuffer[0] = 0;
      v10 = idKeyInput::KeysFromBinding(result: v31, numDevice: deviceNum, bindset, bind: i->string, firstOnly: true);
      idStr::Append(this: &v30, text: v10);
      idStr::FreeData(this: v31);
      if ( v30.len != 0 )
      {
        idStr::ToUpper(this: &v30);
        idStr::Replace(this: text, old: i->string, nw: v30.data);
      }
      idStr::FreeData(this: &v30);
    }
  }
  v11 = 0;
  if ( this->tooltipButtonImage.num > 0 )
  {
    for ( j = 0; ; ++j )
    {
      v13 = idStr::Find(
              searchIn: text->data,
              searchFor: this->tooltipButtonImage.list[j].key,
              casesensitive: false,
              start: 0,
              end: -1);
      if ( v13 != -1 )
        break;
LABEL_36:
      if ( ++v11 >= this->tooltipButtonImage.num )
        return;
    }
    while ( 1 )
    {
      list = this->tooltipButtonImage.list;
      v15 = 0;
      v29.startIndex = v13;
      key = list[j].key;
      if ( *key != 0 )
      {
        do
          ++v15;
        while ( key[v15] != 0 );
      }
      v29.endIndex = v15 + v13;
      started = idLobbyBackend360::StartArbitration(pexcept: nullptr);
      v18 = &this->tooltipButtonImage.list[j];
      if ( started == 1 )
      {
        psImage = v18->psImage;
        if ( psImage != nullptr )
          goto LABEL_22;
        v20 = nullptr;
      }
      else
      {
        xbImage = v18->xbImage;
        if ( xbImage != nullptr )
          v20 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                      this: &idMaterial::resourceList,
                                      name: xbImage,
                                      makeDefault: true);
        else
          v20 = nullptr;
        v29.material = v20;
        if ( idLib::production != PROD_BUILDING && com_production.valueInteger == 0 )
          goto LABEL_24;
        psImage = this->tooltipButtonImage.list[j].psImage;
        if ( psImage != nullptr )
        {
LABEL_22:
          v20 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                      this: &idMaterial::resourceList,
                                      name: psImage,
                                      makeDefault: true);
          goto LABEL_23;
        }
        v20 = nullptr;
      }
LABEL_23:
      v29.material = v20;
LABEL_24:
      if ( v20 != nullptr )
      {
        v22 = &this->tooltipButtonImage.list[j];
        height = v22->height;
        baseline = v22->baseline;
        v29.imageWidth = v22->width;
        v29.imageHeight = height;
        v29.baseline = baseline;
      }
      else
      {
        v29.imageWidth = 0;
        v29.imageHeight = 0;
        v29.baseline = 0;
      }
      num = this->tooltipIconList.num;
      v26 = 0;
      if ( num > 0 )
      {
        v27 = 0;
        v28 = 0;
        while ( p_tooltipIconList->list[v28].startIndex <= v13 )
        {
          ++v27;
          ++v28;
          if ( v27 >= num )
            goto LABEL_33;
        }
        idList<idSWF::tooltipIcon_t,72>::Insert(this: p_tooltipIconList, obj: &v29, index: v27);
        v26 = 1;
      }
LABEL_33:
      if ( v26 == 0 )
        idList<idSWF::tooltipIcon_t,72>::Append(this: p_tooltipIconList, obj: &v29);
      v13 = idStr::Find(
              searchIn: text->data,
              searchFor: this->tooltipButtonImage.list[j].key,
              casesensitive: false,
              start: v13 + 1,
              end: -1);
      if ( v13 == -1 )
        goto LABEL_36;
    }
  }
}


// ========================================================================
// __unwind$226376
// EA  : 0x82780DA0
// RVA : 0x00780DA0
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226376()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$226377
// EA  : 0x82780DC8
// RVA : 0x00780DC8
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226377()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// ?RenderEditText@idSWF@@AAAXPAVidRenderModelGui@@PAVidSWFTextInstance@@ABUswfRenderState_t@@H_N@Z
// EA  : 0x82780DF8
// RVA : 0x00780DF8
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::RenderEditText(
        idSWF *this,
        idRenderModelGui *gui,
        idSWFTextInstance *textInstance,
        const swfRenderState_t *renderState,
        int time,
        bool isSplitscreen)
{
  idSWFEditText *editText; // r16
  swfTextRenderMode_t renderMode; // r11
  int v14; // r3
  int v15; // r3
  const idStr *ParagraphText; // r3
  const char *v17; // r3
  int v18; // r3
  int v19; // r3
  const idStr *RandomText; // r3
  const char *String; // r3
  idStr *v22; // r3
  const char *v23; // r3
  idSWFTextInstance *SoundClip; // r3
  int selectionEnd; // r24
  int selectionStart; // r23
  int v27; // r29
  int lastInputTime; // r28
  int v29; // r18
  idGame *v30; // r3
  bool v31; // r30
  BOOL v32; // r17
  char v33; // r26
  int v34; // r11
  double xy; // fp12
  double xx; // fp11
  double v37; // fp14
  double v38; // fp10
  double v39; // fp23
  double v40; // fp9
  double v41; // fp8
  double v42; // fp7
  double v43; // fp27
  double v44; // fp28
  int *v45; // r10
  _DWORD *p_ratio; // r11
  double v47; // fp16
  int i; // ctr
  double v49; // fp21
  double v50; // fp20
  double v51; // fp19
  int fontID; // r4
  double v53; // fp18
  __int64 v54; // r7
  idSWFDictionaryEntry *DictionaryEntry; // r3
  idFont *v56; // r29
  double v57; // fp31
  double v58; // fp0
  double v59; // fp29
  double v60; // fp24
  __int64 v61; // r11
  __int64 v62; // r10
  __int64 v63; // r6
  double v64; // fp6
  double x; // fp3
  double v66; // fp4
  double z; // fp1
  double y; // fp12
  double v69; // fp11
  double valueFloat; // fp0
  unsigned __int64 v71; // r6
  double v72; // fp13
  __int128 v73; // r11
  double frameWidth; // fp25
  double v75; // fp26
  int v76; // r6
  int v77; // r5
  int Ascender; // r3
  int leading; // r7
  __int64 v80; // r11
  double v81; // fp22
  double v82; // fp30
  double frameHeight; // fp31
  unsigned int flags; // r11
  __int64 v85; // r8
  int v86; // r6
  const swfMatrix_t *v87; // r5
  double v88; // fp31
  double v89; // fp13
  int v90; // r16
  __int64 v91; // r5
  idStr *v92; // r3
  BOOL isSubtitle; // r9
  int subCharStartIndex; // r11
  double v95; // fp27
  idStr *v96; // r30
  int v97; // r24
  int v98; // r27
  char v99; // r21
  int v100; // r23
  idStr *list; // r18
  idCVar *v102; // r29
  int v103; // r25
  idStr *v104; // r3
  int v105; // r28
  unsigned int v106; // r26
  int v107; // r10
  int v108; // r9
  int v109; // r8
  int v110; // r7
  int v111; // r6
  int v112; // r5
  int v113; // r7 OVERLAPPED
  __int64 v114; // r9 OVERLAPPED
  double v115; // fp30
  int num; // r10
  float *p_w; // r9
  int *p_baseline; // r10
  int j; // ctr
  double v120; // fp28
  int v121; // r8
  int v122; // r30
  idStr *v123; // r3
  idStr *v124; // r29
  idStr *v125; // r3
  char v126; // r29
  int v127; // r11
  char *data; // r7
  int len; // r10
  int v130; // r11
  int v131; // r27
  int ApporoximateSubtitleBreak; // r3
  float v133; // r11
  int v134; // r8
  int v135; // r4
  char v136; // r5
  int v137; // r10
  bool v138; // cr57
  int v139; // r30
  char *v140; // r6
  int v141; // r9
  idSWFTextInstance *Speaker; // r3
  double v143; // fp17
  int v144; // r28
  idCVar *v145; // r18
  idFont *v146; // r22
  idSWFEditText *v147; // r17
  int v148; // r29
  unsigned int v149; // r30
  int v150; // r10
  int v151; // r9
  int v152; // r8
  int v153; // r7
  int v154; // r6
  int v155; // r5
  int v156; // r7 OVERLAPPED
  __int64 v157; // r9 OVERLAPPED
  double v158; // fp0
  int v159; // r11
  float *v160; // r9
  int *v161; // r10
  int k; // ctr
  int v163; // r10
  double v164; // fp13
  int v165; // r8
  int scroll; // r17
  int v167; // r24
  int v168; // r11
  int v169; // r10
  idSWFSpriteInstance *v170; // r16
  int v171; // r18
  int v172; // r21
  int v173; // r25
  int v174; // r22
  idStr *v175; // r9
  double v176; // fp28
  unsigned int inputTextStartChar; // r8
  int v178; // r29
  char v179; // r28
  idStr *v180; // r27
  unsigned int v181; // r30
  int v182; // r10
  int v183; // r9
  int v184; // r8
  int v185; // r7
  int v186; // r6
  int v187; // r5
  __int64 v188; // r9
  double v189; // fp30
  int v190; // r11
  double v191; // fp31
  idFont *v192; // r27
  unsigned int v193; // r3
  int v194; // r10
  int v195; // r9
  int v196; // r8
  int v197; // r7
  int v198; // r6
  int v199; // r5
  __int64 v200; // r11
  int v201; // r20
  double v202; // fp31
  double v203; // fp30
  idStr *v204; // r6
  int v205; // r8
  int v206; // r7
  int v207; // r11
  int v208; // r11
  idStr *v209; // r26
  int v210; // r29
  int subCharEndIndex; // r23
  int v212; // r11
  char v213; // r27
  double v214; // fp28
  int v215; // r10
  idCVar *v216; // r27
  int v217; // r30
  idSWF::tooltipIcon_t *v218; // r11
  idSWF::tooltipIcon_t *v219; // r11
  int v220; // r11
  unsigned int v221; // r28
  int v222; // r10
  int v223; // r9
  int v224; // r8
  int v225; // r7
  int v226; // r6
  int v227; // r5
  const glyphInfo_t *Glyph; // r3
  char v229; // r11
  __int64 v230; // r8
  unsigned int align; // r11
  double v232; // fp27
  __int64 v233; // r11
  int v234; // r9
  int v235; // r11
  int v236; // r10
  __int64 v237; // r11
  int v238; // r8
  int v239; // r29
  int v240; // r28
  int v241; // r10
  float *v242; // r9
  int v243; // r7
  int v244; // r6
  unsigned int v245; // r3
  unsigned int v246; // r30
  char v247; // r11
  double w; // fp28
  idVec4 *v249; // r3
  int m; // ctr
  __int64 v251; // r9
  const glyphInfo_t *v252; // r3
  __int64 v253; // r7 OVERLAPPED
  double v254; // fp13
  double v255; // fp0
  double v256; // fp0
  double v257; // fp28
  double v258; // fp26
  double v259; // fp27
  double v260; // fp25
  double v261; // fp24
  double v262; // fp22
  double v263; // fp23
  double v264; // fp15
  unsigned int v265; // r3
  double v266; // fp25
  const glyphInfo_t *v267; // r3
  __int64 v268; // r8
  BOOL useStroke; // r10
  __int128 v270; // r11
  __int128 v271; // r6 OVERLAPPED
  char left; // r7
  __int64 v273; // fp2
  int v274; // r7
  __int64 v275; // fp9
  double v276; // fp1
  double v277; // fp15
  double v278; // fp27
  double v279; // fp22
  double v280; // fp28
  double v281; // fp26
  double v282; // fp25
  double v283; // fp24
  double v284; // fp23
  double v285; // fp11
  double v286; // fp7
  double v287; // fp8
  double v288; // fp10
  double v289; // fp9
  double v290; // fp20
  double v291; // fp21
  double v292; // fp19
  double v293; // fp18
  double v294; // fp17
  double v295; // fp15
  unsigned int v296; // r3
  idRenderModelGui *v297; // r30
  double v298; // fp0
  const idMaterial *white; // r8
  unsigned int v300; // r3
  double v301; // fp12
  double v302; // fp11
  double v303; // fp10
  double v304; // fp9
  double v305; // fp8
  double v306; // fp7
  double v307; // fp6
  double v308; // fp28
  double v309; // fp27
  double v310; // fp22
  double v311; // fp18
  double v312; // fp17
  double v313; // fp16
  double v314; // fp15
  double v315; // fp14
  const idMaterial *Material; // r3
  unsigned int v317; // r3
  double v318; // fp12
  __int64 v319; // r8
  unsigned int v320; // r3
  __int64 v321; // r6
  int v322; // r30
  const idMaterial *v323; // r3
  const idMaterial *v324; // r3
  int v325; // r8
  int v326; // r7
  int v327; // r6
  int v328; // [sp+8h] [-738h]
  int v329; // [sp+Ch] [-734h]
  int v330; // [sp+10h] [-730h]
  int v331; // [sp+14h] [-72Ch]
  int v332; // [sp+18h] [-728h]
  unsigned int v333; // [sp+1Ch] [-724h]
  __int64 v334; // [sp+50h] [-6F0h]
  __int64 v335; // [sp+50h] [-6F0h]
  float v336; // [sp+50h] [-6F0h]
  int v337; // [sp+58h] [-6E8h] BYREF
  int v338; // [sp+5Ch] [-6E4h] BYREF
  float v339; // [sp+60h] [-6E0h]
  idFont *v340; // [sp+64h] [-6DCh]
  int v341; // [sp+68h] [-6D8h] BYREF
  bool v342; // [sp+6Ch] [-6D4h]
  int v343; // [sp+70h] [-6D0h]
  idList<idStr,5> v344; // [sp+80h] [-6C0h] BYREF
  int v345; // [sp+90h] [-6B0h] BYREF
  float v346; // [sp+94h] [-6ACh]
  float v347; // [sp+98h] [-6A8h]
  idCVar *v348; // [sp+9Ch] [-6A4h]
  idVec4 v349; // [sp+A0h] [-6A0h] BYREF
  int v350; // [sp+B0h] [-690h]
  int v351; // [sp+B4h] [-68Ch]
  const idMaterial *v352; // [sp+B8h] [-688h]
  __int16 v353; // [sp+BCh] [-684h]
  __int16 v354; // [sp+BEh] [-682h]
  int v355; // [sp+C0h] [-680h]
  int v356; // [sp+C4h] [-67Ch] BYREF
  int v357; // [sp+C8h] [-678h]
  int v358; // [sp+CCh] [-674h]
  float v359; // [sp+D0h] [-670h]
  float v360; // [sp+D4h] [-66Ch]
  idSWFEditText *v361; // [sp+D8h] [-668h]
  float v362; // [sp+DCh] [-664h]
  float v363; // [sp+E0h] [-660h]
  idSWFScriptObject v364; // [sp+E8h] [-658h] BYREF
  BOOL v365; // [sp+148h] [-5F8h]
  int v366; // [sp+14Ch] [-5F4h] BYREF
  float v367; // [sp+150h] [-5F0h] BYREF
  float v368; // [sp+154h] [-5ECh]
  float v369; // [sp+158h] [-5E8h]
  float v370; // [sp+15Ch] [-5E4h]
  float v371; // [sp+160h] [-5E0h]
  float v372; // [sp+164h] [-5DCh]
  float v373; // [sp+168h] [-5D8h]
  float v374; // [sp+16Ch] [-5D4h]
  int v375; // [sp+170h] [-5D0h]
  float v376; // [sp+174h] [-5CCh]
  float v377; // [sp+178h] [-5C8h]
  float v378; // [sp+17Ch] [-5C4h]
  float v379; // [sp+180h] [-5C0h]
  idSWFScriptObject v380; // [sp+188h] [-5B8h] BYREF
  float v381; // [sp+1E8h] [-558h]
  float v382; // [sp+1ECh] [-554h]
  idVec4 v383; // [sp+1F0h] [-550h] BYREF
  idVec4 v384; // [sp+200h] [-540h] BYREF
  idVec4 v385; // [sp+210h] [-530h] BYREF
  idVec4 v386; // [sp+220h] [-520h] BYREF
  idVec4 v387; // [sp+230h] [-510h] BYREF
  idVec4 v388; // [sp+240h] [-500h] BYREF
  idVec4 v389; // [sp+250h] [-4F0h] BYREF
  idVec4 v390; // [sp+260h] [-4E0h] BYREF
  idVec4 v391; // [sp+270h] [-4D0h] BYREF
  idVec4 v392; // [sp+280h] [-4C0h] BYREF
  idVec4 v393; // [sp+290h] [-4B0h] BYREF
  idVec4 v394; // [sp+2A0h] [-4A0h] BYREF
  idVec4 v395; // [sp+2B0h] [-490h] BYREF
  idVec4 v396; // [sp+2C0h] [-480h] BYREF
  idVec4 v397; // [sp+2D0h] [-470h] BYREF
  idVec4 v398; // [sp+2E0h] [-460h] BYREF
  __int64 v399; // [sp+2F0h] [-450h]
  float v400; // [sp+2F8h] [-448h]
  __int64 v401; // [sp+300h] [-440h]
  float v402; // [sp+308h] [-438h]
  __int64 v403; // [sp+310h] [-430h]
  __int64 v404; // [sp+318h] [-428h]
  __int64 v405; // [sp+320h] [-420h]
  float v406; // [sp+328h] [-418h]
  __int64 v407; // [sp+330h] [-410h]
  idStr v408; // [sp+340h] [-400h] BYREF
  float v409; // [sp+360h] [-3E0h]
  __int64 v410; // [sp+368h] [-3D8h]
  __int64 v411; // [sp+370h] [-3D0h]
  __int64 v412; // [sp+378h] [-3C8h]
  __int64 v413; // [sp+380h] [-3C0h]
  __int64 v414; // [sp+388h] [-3B8h]
  __int64 v415; // [sp+390h] [-3B0h]
  __int64 v416; // [sp+398h] [-3A8h]
  __int64 v417; // [sp+3A0h] [-3A0h]
  __int64 v418; // [sp+3A8h] [-398h]
  unsigned __int64 v419; // [sp+3B0h] [-390h]
  __int64 v420; // [sp+3B8h] [-388h]
  __int64 v421; // [sp+3C0h] [-380h]
  __int64 v422; // [sp+3C8h] [-378h]
  __int64 v423; // [sp+3D0h] [-370h]
  __int64 v424; // [sp+3D8h] [-368h]
  idStr v425; // [sp+3E0h] [-360h] BYREF
  idStr v426; // [sp+400h] [-340h] BYREF
  idVec4 v427; // [sp+420h] [-320h] BYREF
  idVec4 v428; // [sp+430h] [-310h] BYREF
  idVec4 v429; // [sp+440h] [-300h] BYREF
  idStr v430; // [sp+450h] [-2F0h] BYREF
  idSWFTextInstance v431; // [sp+470h] [-2D0h] BYREF

  if ( textInstance == nullptr )
  {
    idLib::Warning(fmt: "%s: RenderEditText: textInstance == NULL", this->filename.str);
    return;
  }
  if ( textInstance->visible )
  {
    editText = textInstance->editText;
    v364.variablesHash[5] = 0;
    v364.variablesHash[7] = 20;
    v364.variablesHash[6] = (int)&v364.variablesHash[8];
    v361 = editText;
    HIBYTE(v364.variablesHash[8]) = 0;
    if ( textInstance->variable.len != 0 )
    {
      idSWFScriptObject::Get(this: &v380, result: (idSWFScriptVar *)this->globals, name: textInstance->variable.data);
      if ( v380.refCount == 4 )
      {
        String = idLocalization::GetString(inString: textInstance->text.data);
        idStr::operator=(this: (idStr *)&v364.variablesHash[5], text: String);
      }
      else
      {
        v22 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v430, result: (idStr *)&v380);
        v23 = idLocalization::GetString(inString: v22->data);
        idStr::operator=(this: (idStr *)&v364.variablesHash[5], text: v23);
        idStr::FreeData(this: &v430);
      }
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v380);
    }
    else
    {
      renderMode = textInstance->renderMode;
      if ( renderMode == SWF_TEXT_RENDER_PARAGRAPH )
      {
        if ( textInstance->triggerGenerate )
        {
          v14 = Sys_Milliseconds();
          idSWFTextInstance::StartParagraphText(this: textInstance, time: v14);
        }
        v15 = Sys_Milliseconds();
        ParagraphText = idSWFTextInstance::GetParagraphText(
                          this: (idSWFTextInstance *)&v431.randomtext.allocedAndFlag,
                          result: (idStr *)textInstance,
                          time: v15);
        idStr::operator=(this: (idStr *)&v364.variablesHash[5], text: ParagraphText);
        idStr::FreeData(this: (idStr *)&v431.randomtext.allocedAndFlag);
      }
      else if ( renderMode == SWF_TEXT_RENDER_RANDOM_APPEAR || renderMode == SWF_TEXT_RENDER_RANDOM_APPEAR_CAPS )
      {
        if ( textInstance->triggerGenerate )
        {
          v18 = Sys_Milliseconds();
          idSWFTextInstance::StartRandomText(this: textInstance, time: v18);
        }
        v19 = Sys_Milliseconds();
        RandomText = idSWFTextInstance::GetRandomText(
                       this: (idSWFTextInstance *)&v431.variable.allocedAndFlag,
                       result: (idStr *)textInstance,
                       time: v19);
        idStr::operator=(this: (idStr *)&v364.variablesHash[5], text: RandomText);
        idStr::FreeData(this: (idStr *)&v431.variable.allocedAndFlag);
      }
      else
      {
        v17 = idLocalization::GetString(inString: textInstance->text.data);
        idStr::operator=(this: (idStr *)&v364.variablesHash[5], text: v17);
      }
    }
    if ( v364.variablesHash[5] == 0 )
    {
      textInstance->selectionEnd = -1;
      textInstance->selectionStart = -1;
    }
    if ( idSWFTextInstance::NeedsSoundPlayed(this: textInstance) )
    {
      SoundClip = idSWFTextInstance::GetSoundClip(this: &v431, result: (idStr *)textInstance);
      idSWF::PlaySound(this, sound: (const char *)SoundClip->swf, channel: SND_CHANNEL_ANY, blocking: false);
      idStr::FreeData(this: (idStr *)&v431);
      textInstance->needsSoundUpdate = false;
    }
    if ( textInstance->tooltip )
      idSWF::FindTooltipIcons(
        this,
        text: (idStr *)&v364.variablesHash[5],
        bindset: (bindSet_t)textInstance->bindset,
        deviceNum: this->userDeviceNumber);
    else
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tooltipIconList);
    selectionEnd = textInstance->selectionEnd;
    selectionStart = textInstance->selectionStart;
    v27 = 60;
    lastInputTime = textInstance->lastInputTime;
    v29 = selectionEnd;
    v357 = selectionStart;
    v358 = selectionEnd;
    v343 = selectionEnd;
    if ( common != nullptr && common->Game(this: common) != nullptr )
    {
      v30 = common->Game(this: common);
      v27 = v30->GetGameHz(this: v30, a2: GAMETIME_SCALED);
    }
    v31 = false;
    idSWFScriptObject::Get(this: &v364, result: (idSWFScriptVar *)this->globals, name: "focusWindow");
    if ( v364.refCount == 8 )
      v31 = v364.variables.list == (idSWFScriptObject::swfNamedVar_t *)textInstance->scriptObject;
    v32 = v31;
    v33 = 0;
    v365 = v31;
    if ( v31 )
    {
      v34 = idLib::frameNumber;
      __twllei(v27 / 2, 0);
      __twlgei((v27 / 2) & ~(__ROL4__(v34 - lastInputTime, 1) - 1), 0xFFFFFFFF);
      if ( (((v34 - lastInputTime) / (v27 / 2)) & 1) == 0 )
      {
        v29 = selectionEnd;
        v343 = selectionEnd;
        v33 = 1;
      }
    }
    if ( selectionStart > selectionEnd )
    {
      v357 = selectionEnd;
      v358 = selectionStart;
    }
    xy = renderState->matrix.xy;
    xx = renderState->matrix.xx;
    v37 = 0.0;
    v38 = (float)((float)(renderState->matrix.yy * (float)0.0) + renderState->matrix.yx);
    v39 = 0.5;
    v40 = (float)((float)(renderState->matrix.yx * (float)0.0) + renderState->matrix.yy);
    v41 = (float)((float)(renderState->matrix.xy * (float)0.0) + renderState->matrix.xx);
    v363 = 0.0;
    v362 = 0.5;
    v42 = (float)((float)((float)xx * (float)0.0) + (float)xy);
    v43 = __fsqrts((float)((float)((float)v41 * (float)v41) + (float)((float)v38 * (float)v38)));
    v44 = __fsqrts((float)((float)((float)v42 * (float)v42) + (float)((float)v40 * (float)v40)));
    if ( isSplitscreen )
      v44 = (float)((float)v44 * (float)0.5);
    v45 = &v366;
    p_ratio = (_DWORD *)&renderState[-1].ratio;
    v47 = 1.0;
    *(float *)&v364.objectType = 1.0;
    for ( i = 6; i != 0; --i )
      *++v45 = *++p_ratio;
    v49 = (float)(v367 * (float)((float)1.0 / (float)v43));
    v50 = (float)(v369 * (float)((float)1.0 / (float)v43));
    v51 = (float)(v368 * (float)((float)1.0 / (float)v44));
    fontID = editText->fontID;
    v53 = (float)(v370 * (float)((float)1.0 / (float)v44));
    v367 = v367 * (float)((float)1.0 / (float)v43);
    v369 = v369 * (float)((float)1.0 / (float)v43);
    v368 = v368 * (float)((float)1.0 / (float)v44);
    v370 = v370 * (float)((float)1.0 / (float)v44);
    DictionaryEntry = idSWF::FindDictionaryEntry(this, characterID: fontID, type: SWF_DICT_FONT);
    if ( DictionaryEntry == nullptr )
    {
      idLib::Warning(fmt: "idSWF::RenderEditText: NULL Font");
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v364);
LABEL_307:
      idStr::FreeData(this: (idStr *)&v364.variablesHash[5]);
      return;
    }
    LODWORD(v54) = editText->fontHeight;
    v56 = DictionaryEntry->font->fontID;
    v340 = v56;
    v57 = (float)((float)((float)v54 * (float)v44) * (float)0.050000001);
    if ( sys_langJapanese.valueInteger != 0 )
    {
      v334 = __PAIR64__(byte_821B0000, idFont::GetPointSize(this: v56));
      v58 = 0.033333335;
      v59 = (float)((float)v57 / (float)((float)v334 + (float)6.0));
    }
    else
    {
      v335 = __PAIR64__(&unk_821D0000, idFont::GetPointSize(this: v56));
      v58 = 0.041666668;
      v59 = (float)((float)v57 / (float)v335);
    }
    v60 = (float)((float)v57 * (float)v58);
    v360 = (float)v57 * (float)v58;
    LODWORD(v61) = idFont::GetMaterialWidth(this: v56);
    v378 = (float)1.0 / (float)v61;
    LODWORD(v62) = idFont::GetMaterialHeight(this: v56);
    v374 = (float)1.0 / (float)v62;
    swfColorRGBA_t::ToVec4(this: (swfColorRGBA_t *)&v349, result: (idVec4 *)&textInstance->color, a3: v63);
    v64 = (float)(renderState->cxf.mul.z * v349.z);
    x = renderState->cxf.mul.x;
    v66 = (float)(renderState->cxf.mul.y * v349.y);
    z = renderState->cxf.add.z;
    y = renderState->cxf.add.y;
    v69 = renderState->cxf.add.x;
    valueFloat = (float)(renderState->cxf.add.w + (float)(renderState->cxf.mul.w * v349.w));
    v349.w = renderState->cxf.add.w + (float)(renderState->cxf.mul.w * v349.w);
    v349.z = (float)z + (float)v64;
    v349.y = (float)y + (float)v66;
    v349.x = (float)v69 + (float)(v349.x * (float)x);
    if ( swf_forceAlpha.valueFloat > 0.0 )
    {
      v349.w = swf_forceAlpha.valueFloat;
      valueFloat = swf_forceAlpha.valueFloat;
    }
    if ( valueFloat > 0.001 )
    {
      v427.x = v349.x;
      v427.y = v349.y;
      v427.z = v349.z;
      v427.w = (float)valueFloat * (float)0.5;
      gui->currentVertexColor = idColor::PackColor(color: &v349);
      idSWF::GLStateForRenderState(this, renderState);
      idRenderModelGui::SetGLState(this: gui, bits: v71);
      v72 = editText->bounds.tl.x;
      LODWORD(v73) = editText->rightMargin;
      DWORD2(v73) = editText->leftMargin;
      frameWidth = (float)((float)-(float)((float)((float)(__int64)v73 * (float)0.050000001) - editText->bounds.br.x)
                         * (float)v43);
      v75 = (float)((float)((float)((float)*(__int64 *)((char *)&v73 + 4) * (float)0.050000001) + editText->bounds.tl.x)
                  * (float)v43);
      *(float *)&v364.variablesHash[15] = (float)-(float)((float)((float)(__int64)v73 * (float)0.050000001)
                                                        - editText->bounds.br.x)
                                        * (float)v43;
      *(float *)&v364.variablesHash[13] = (float)((float)((float)*(__int64 *)((char *)&v73 + 4) * (float)0.050000001)
                                                + (float)v72)
                                        * (float)v43;
      Ascender = idFont::GetAscender(this: v56);
      leading = (unsigned __int16)editText->leading;
      LODWORD(v80) = (__int16)leading;
      v81 = (float)((float)((float)__SPAIR64__(&unk_821F0000, Ascender) * (float)v59) * (float)1.15);
      v347 = (float)((float)__SPAIR64__(&unk_821F0000, Ascender) * (float)v59) * (float)1.15;
      if ( (_WORD)leading != 0 )
      {
        v81 = (float)((float)((float)((float)v80 * (float)v59) * (float)0.050000001)
                    + (float)((float)((float)__SPAIR64__(&unk_821F0000, Ascender) * (float)v59) * (float)1.15));
        v347 = (float)((float)((float)v80 * (float)v59) * (float)0.050000001)
             + (float)((float)((float)__SPAIR64__(&unk_821F0000, Ascender) * (float)v59) * (float)1.15);
      }
      if ( sys_langJapanese.valueInteger != 0 )
      {
        v82 = (float)((float)(editText->bounds.tl.y + (float)3.0) * (float)v44);
        frameHeight = (float)((float)(editText->bounds.br.y + (float)3.0) * (float)v44);
      }
      else
      {
        frameHeight = (float)(editText->bounds.br.y * (float)v44);
        v82 = (float)((float)((float)((float)v59 * (float)1.15) + editText->bounds.tl.y) * (float)v44);
      }
      flags = editText->flags;
      *(float *)&v364.variablesHash[14] = v82;
      if ( (flags & 0x10) != 0 )
      {
        frameWidth = this->frameWidth;
        frameHeight = this->frameHeight;
        *(float *)&v364.variablesHash[15] = this->frameWidth;
      }
      if ( v33 != 0 && v29 <= 0 )
      {
        LODWORD(v85) = idFont::GetGlyph(
                         this: v56,
                         idx: 0x20u,
                         a3: v77,
                         a4: v76,
                         a5: leading,
                         a6: (int)&unk_821F0000,
                         a7: Ascender,
                         a8: flags & 0x10,
                         a9: v328,
                         a10: v329,
                         a11: v330,
                         a12: v331,
                         a13: v332,
                         a14: v333)->height;
        idSWF::DrawEditCursor(
          this,
          gui,
          x: v75,
          y: (float)((float)((float)v85 * (float)v59) * (float)0.5),
          w: 1.0,
          h: v81,
          matrix: v87,
          a8: v86,
          a9: SHIDWORD(v85),
          a10: v85,
          a11: &v367);
      }
      if ( textInstance->isSubtitle )
      {
        if ( v364.variablesHash[5] == 0 && textInstance->subtitleText.len == 0 )
          goto LABEL_63;
_M228145:
        v89 = (float)((float)((float)frameHeight - (float)v82) / (float)v81);
        v88 = v75;
        v90 = (int)v89;
        v364.data.sprite = (idSWFSpriteInstance *)(int)v89;
        if ( (int)v89 == 0 )
        {
          v90 = 1;
          v364.data.sprite = (idSWFSpriteInstance *)1;
        }
        *(_WORD *)&v344.memTag = 18432;
        memset(&v344, 0, 14);
        v92 = idList<idStr,72>::Alloc(this: (idList<idStr,72> *)&v344);
        isSubtitle = textInstance->isSubtitle;
        subCharStartIndex = 0;
        v95 = 0.0;
        v338 = 0;
        v96 = v92;
        v97 = 0;
        v98 = 0;
        v99 = 0;
        v100 = 0;
        if ( isSubtitle )
        {
          subCharStartIndex = textInstance->subCharStartIndex;
          v338 = subCharStartIndex;
        }
        list = v344.list;
        v102 = &swf_textStrokeSizeGlyphSpacer;
        v348 = &swf_textStrokeSizeGlyphSpacer;
        if ( subCharStartIndex < v364.variablesHash[5] )
        {
          v103 = 0;
          while ( 1 )
          {
            if ( *(_BYTE *)(v364.variablesHash[6] + subCharStartIndex) == 10 )
            {
              if ( (v361->flags & 2) == 0 )
                break;
              idStr::Append(this: v96, a: 10);
              v88 = v75;
              if ( v98 < textInstance->scroll + v90 )
                ++v98;
              v104 = idList<idStr,72>::Alloc(this: (idList<idStr,72> *)&v344);
              list = v344.list;
              v96 = v104;
              subCharStartIndex = v338 + 1;
              v97 = 0;
              ++v338;
            }
            else
            {
              v105 = subCharStartIndex;
              v106 = idStr::UTF8Char(s: (const unsigned __int8 *)v364.variablesHash[6], idx: &v338);
              LODWORD(v114) = idFont::GetGlyph(
                                this: v340,
                                idx: v106,
                                a3: v112,
                                a4: v111,
                                a5: v110,
                                a6: v109,
                                a7: v108,
                                a8: v107,
                                a9: v328,
                                a10: v329,
                                a11: v330,
                                a12: v331,
                                a13: v332,
                                a14: v333)->xSkip;
              HIDWORD(v114) = textInstance->useStroke;
              v115 = (float)((float)v114 * (float)v59);
              if ( textInstance->useStroke )
                v115 = (float)((float)((float)((float)v59 * textInstance->strokeWeight) * v102->valueFloat)
                             + (float)((float)v114 * (float)v59));
              num = this->tooltipIconList.num;
              v353 = 0;
              v350 = -1;
              v351 = -1;
              if ( v100 < num )
              {
                p_w = &v349.w;
                p_baseline = &this->tooltipIconList.list[v103 - 1].baseline;
                for ( j = 5; j != 0; --j )
                  *(_DWORD *)++p_w = *++p_baseline;
              }
              subCharStartIndex = v338;
              v120 = 0.0;
              if ( v338 - 1 == v350 )
              {
                v99 = 1;
                v121 = v353;
                *(_QWORD *)&v364.variables.num = *(_QWORD *)(&v113 - 1);
                v120 = (float)((float)*(__int64 *)(&v113 - 1) * (float)v60);
              }
              else if ( v338 - 1 == v351 )
              {
                v99 = 0;
                v115 = 0.0;
                ++v100;
                ++v103;
              }
              if ( v99 != 0 )
                v115 = 0.0;
              if ( !v32
                && ((float)((float)v115 + (float)v88) > frameWidth || (float)((float)v120 + (float)v88) > frameWidth) )
              {
                if ( (v361->flags & 3) == 0 )
                  break;
                if ( v98 >= textInstance->scroll + v90 )
                {
                  len = v96->len;
                  if ( v97 > 0 && len > v97 )
                  {
                    v96->data[v97] = 0;
                    v96->len = v97;
                    subCharStartIndex = v338;
                  }
                  subCharStartIndex -= len;
                  v338 = subCharStartIndex;
                  break;
                }
                if ( v97 <= 0 )
                {
                  ++v98;
                  v125 = idList<idStr,72>::Alloc(this: (idList<idStr,72> *)&v344);
                  list = v344.list;
                  v96 = v125;
                  v88 = v75;
                }
                else
                {
                  v122 = v96 - list;
                  v123 = idList<idStr,72>::Alloc(this: (idList<idStr,72> *)&v344);
                  list = v344.list;
                  ++v98;
                  v124 = &v344.list[v122];
                  v96 = v123;
                  if ( v98 == v90 && v90 == 1 )
                  {
                    v130 = v124->len - 3;
                    if ( v124->len > v130 && v130 >= 0 )
                    {
                      v124->data[v130] = 0;
                      v124->len = v130;
                    }
                    idStr::Append(this: v124, text: "...");
                    subCharStartIndex = v338;
                    break;
                  }
                  idStr::operator=(this: v123, text: &v124->data[v97]);
                  if ( v124->len > v97 )
                  {
                    v124->data[v97] = 0;
                    v124->len = v97;
                  }
                  v88 = (float)((float)v88 - (float)v95);
                }
                subCharStartIndex = v338;
                v97 = 0;
              }
              if ( v105 < subCharStartIndex )
              {
                do
                {
                  if ( v105 >= v364.variablesHash[5] )
                    break;
                  v126 = *(_BYTE *)(v364.variablesHash[6] + v105);
                  idStr::EnsureAlloced(this: v96, amount: v96->len + 2, keepold: true, geometricGrowth: true);
                  ++v105;
                  v96->data[v96->len] = v126;
                  v127 = v96->len + 1;
                  data = v96->data;
                  v96->len = v127;
                  data[v127] = 0;
                  subCharStartIndex = v338;
                }
                while ( v105 < v338 );
              }
              v88 = (float)((float)((float)v120 + (float)v115) + (float)v88);
              if ( v106 == 32 || v106 == 45 )
              {
                v97 = v96->len;
                v95 = v88;
              }
            }
            if ( subCharStartIndex >= v364.variablesHash[5] )
              break;
            v102 = v348;
          }
        }
        v131 = v344.num;
        if ( !textInstance->isSubtitle || !textInstance->subUpdating )
          goto _M228155_0;
        if ( v344.num <= 0 || !textInstance->subNeedsSwitch )
          goto LABEL_133;
        ApporoximateSubtitleBreak = idSWFTextInstance::GetApporoximateSubtitleBreak(this: textInstance, time);
        v133 = *(float *)&list->len;
        v134 = textInstance->subCharStartIndex;
        v135 = 0;
        v136 = 0;
        v137 = 0;
        v138 = list->len > 0;
        v139 = list->len + v134;
        v359 = *(float *)&list->len;
        if ( !v138 )
          goto LABEL_128;
        v140 = list->data;
        while ( 1 )
        {
          v141 = v140[v137];
          if ( v141 == 32 || v141 == 45 )
            break;
          if ( v137 == LODWORD(v133) )
          {
            if ( v135 == ApporoximateSubtitleBreak )
              goto LABEL_126;
LABEL_145:
            ++v135;
          }
LABEL_146:
          ++v137;
          v359 = v133;
          if ( v137 >= SLODWORD(v133) )
            goto LABEL_127;
        }
        if ( v137 == 0 )
          goto LABEL_146;
        if ( v135 != ApporoximateSubtitleBreak )
        {
          if ( v137 <= 0 || v140[v137 - 1] == 32 )
            goto LABEL_146;
          goto LABEL_145;
        }
LABEL_126:
        v136 = 1;
        v139 = v137 + v134;
LABEL_127:
        if ( v135 <= 0 )
        {
LABEL_128:
          if ( SLODWORD(v133) > 0 )
            v135 = 1;
        }
        if ( v136 == 0 )
          idSWFTextInstance::LastWordChanged(this: textInstance, wordCount: v135, time);
        idSWFTextInstance::SetSubEndIndex(this: textInstance, endChar: v139, time);
        v425.allocedAndFlag = 20;
        v425.data = v425.baseBuffer;
        v425.len = 0;
        v425.baseBuffer[0] = 0;
        idStr::CopyRange(this: &v425, text: list->data, start: 0, end: v139 - textInstance->subCharStartIndex);
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v431.bindset);
        idSWFParmList::Append(this: (idSWFParmList *)&v431.bindset, s: &v425);
        Speaker = idSWFTextInstance::GetSpeaker(
                    this: (idSWFTextInstance *)&v431.text.allocedAndFlag,
                    result: (idStr *)textInstance);
        idSWFParmList::Append(this: (idSWFParmList *)&v431.bindset, s: (const char *)Speaker->swf);
        idStr::FreeData(this: (idStr *)&v431.text.allocedAndFlag);
        idSWFParmList::Append(
          this: (idSWFParmList *)&v431.bindset,
          i: (idSWFScriptVar::swfScriptVarValue_t *)textInstance->subAlign);
        idSWF::Invoke(this, functionName: "subtitleChanged", parms: (const idSWFParmList *)&v431.bindset);
        idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)&v431.bindset);
        idSWFTextInstance::SetSubNextStartIndex(this: textInstance, value: textInstance->subCharEndIndex);
        idSWFTextInstance::SwitchSubtitleText(this: textInstance, time);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v431.bindset);
        idStr::FreeData(this: &v425);
LABEL_133:
        if ( !idSWFTextInstance::UpdateSubtitle(this: textInstance, time) )
        {
          idSWFTextInstance::SubtitleComplete(this: textInstance);
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v431.indexArray.size);
          idSWFParmList::Append(
            this: (idSWFParmList *)&v431.indexArray.size,
            i: (idSWFScriptVar::swfScriptVarValue_t *)textInstance->subAlign);
          idSWF::Invoke(this, functionName: "subtitleComplete", parms: (const idSWFParmList *)&v431.indexArray.size);
          idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)&v431.indexArray.size);
          idSWFTextInstance::SubtitleCleanup(this: textInstance);
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v431.indexArray.size);
        }
        subCharStartIndex = v338;
_M228155_0:
        v339 = v75;
        v143 = v75;
        v426.allocedAndFlag = 20;
        v426.data = v426.baseBuffer;
        v144 = 0;
        v426.len = 0;
        v426.baseBuffer[0] = 0;
        v345 = subCharStartIndex;
        if ( subCharStartIndex < v364.variablesHash[5] )
        {
          v145 = v348;
          v146 = v340;
          v147 = v361;
          v148 = v100;
          do
          {
            if ( *(_BYTE *)(subCharStartIndex + v364.variablesHash[6]) == 10 )
            {
              if ( (v147->flags & 2) == 0 )
                break;
              ++subCharStartIndex;
              v143 = v75;
              v97 = 0;
              v345 = subCharStartIndex;
              ++v144;
            }
            else
            {
              v149 = idStr::UTF8Char(s: (const unsigned __int8 *)v364.variablesHash[6], idx: &v345);
              LODWORD(v157) = idFont::GetGlyph(
                                this: v146,
                                idx: v149,
                                a3: v155,
                                a4: v154,
                                a5: v153,
                                a6: v152,
                                a7: v151,
                                a8: v150,
                                a9: v328,
                                a10: v329,
                                a11: v330,
                                a12: v331,
                                a13: v332,
                                a14: v333)->xSkip;
              HIDWORD(v157) = textInstance->useStroke;
              v158 = (float)((float)v157 * (float)v59);
              if ( textInstance->useStroke )
                v158 = (float)((float)((float)((float)v59 * textInstance->strokeWeight) * v145->valueFloat)
                             + (float)((float)v157 * (float)v59));
              v159 = this->tooltipIconList.num;
              v350 = -1;
              v351 = -1;
              v353 = 0;
              if ( v100 < v159 )
              {
                v160 = &v349.w;
                v161 = &this->tooltipIconList.list[v148 - 1].baseline;
                for ( k = 5; k != 0; --k )
                  *(_DWORD *)++v160 = *++v161;
              }
              v163 = v345;
              v164 = 0.0;
              if ( v345 - 1 == v350 )
              {
                v99 = 1;
                v165 = v353;
                *(_QWORD *)&v364.variables.num = *(_QWORD *)(&v156 - 1);
                v164 = (float)((float)*(__int64 *)(&v156 - 1) * (float)v60);
              }
              else if ( v345 - 1 == v351 )
              {
                v99 = 0;
                v158 = 0.0;
                ++v100;
                ++v148;
              }
              if ( v99 != 0 )
                v158 = 0.0;
              if ( (float)((float)v158 + (float)v143) > frameWidth || (float)((float)v164 + (float)v143) > frameWidth )
              {
                if ( (v147->flags & 3) == 0 )
                  break;
                ++v144;
                v143 = v75;
                if ( v97 > 0 )
                {
                  v163 = v97;
                  v345 = v97;
                  v97 = 0;
                }
              }
              else
              {
                v143 = (float)((float)((float)v164 + (float)v158) + (float)v143);
              }
              if ( v149 == 32 || v149 == 45 )
                v97 = v163;
              idStr::Append(this: &v426, a: v149);
              subCharStartIndex = v345;
            }
          }
          while ( subCharStartIndex < v364.variablesHash[5] );
          v339 = v143;
        }
        scroll = textInstance->scroll;
        v167 = 1;
        v168 = v144 - v90 + v131;
        textInstance->maxscroll = v168;
        if ( scroll + v90 <= v131 || v90 >= v131 )
        {
          if ( scroll < 0 || v131 <= v90 )
          {
            scroll = 0;
            textInstance->scroll = 0;
          }
          else if ( textInstance->renderMode == SWF_TEXT_RENDER_AUTOSCROLL )
          {
            scroll = v131 - v90;
            textInstance->scroll = v168;
          }
        }
        else
        {
          scroll = v131 - v90;
          textInstance->scroll = v131 - v90;
        }
        v380.variables.num = -1;
        *(_DWORD *)&v380.variables.granularity = -1;
        v169 = 0;
        v380.variablesHash[5] = -1;
        v170 = nullptr;
        v380.variablesHash[6] = -1;
        v171 = 0;
        v380.variables.size = 1;
        v172 = 0;
        v380.variablesHash[0] = 1;
        v173 = 0;
        v380.variablesHash[7] = 1;
        v174 = 0;
        v380.variablesHash[8] = 1;
        v408.allocedAndFlag = 20;
        v408.data = v408.baseBuffer;
        v341 = 0;
        v408.len = 0;
        v408.baseBuffer[0] = 0;
        if ( !v365 || v131 <= 0 )
          goto LABEL_205;
        v175 = v344.list;
        v176 = v75;
        inputTextStartChar = textInstance->inputTextStartChar;
        HIDWORD(v91) = inputTextStartChar - v344.list->len;
        v178 = ((__PAIR64__((unsigned int)v344.list->len >> 31, inputTextStartChar)
               - __PAIR64__(inputTextStartChar >> 31, v344.list->len)) >> 32)
             & inputTextStartChar;
        if ( v343 < v178 && v343 >= 0 )
          v178 = v343;
        v356 = v178;
        v179 = 0;
        if ( v178 >= v344.list->len )
          goto LABEL_202;
        v180 = v344.list;
        while ( 2 )
        {
          v181 = idStr::UTF8Char(s: (const unsigned __int8 *)v180->data, idx: &v356);
          LODWORD(v188) = idFont::GetGlyph(
                            this: v340,
                            idx: v181,
                            a3: v187,
                            a4: v186,
                            a5: v185,
                            a6: v184,
                            a7: v183,
                            a8: v182,
                            a9: v328,
                            a10: v329,
                            a11: v330,
                            a12: v331,
                            a13: v332,
                            a14: v333)->xSkip;
          HIDWORD(v188) = textInstance->useStroke;
          v189 = (float)((float)v188 * (float)v59);
          if ( textInstance->useStroke )
            v189 = (float)((float)((float)((float)v59 * textInstance->strokeWeight) * v348->valueFloat)
                         + (float)((float)v188 * (float)v59));
          if ( (float)((float)v189 + (float)v176) <= frameWidth )
          {
LABEL_198:
            idStr::AppendUTF8Char(this: &v408, c: v181);
            v176 = (float)((float)v189 + (float)v176);
            if ( v356 >= v180->len )
            {
              v169 = v341;
              goto LABEL_201;
            }
            continue;
          }
          break;
        }
        v190 = v356;
        v169 = v341;
        if ( v343 > v356 && v343 != v341 )
        {
          v191 = 0.0;
          if ( v189 > 0.0 )
          {
            v192 = v340;
            while ( v169 != v190 )
            {
              v193 = idStr::UTF8Char(s: (const unsigned __int8 *)v408.data, idx: &v341);
              LODWORD(v200) = idFont::GetGlyph(
                                this: v192,
                                idx: v193,
                                a3: v199,
                                a4: v198,
                                a5: v197,
                                a6: v196,
                                a7: v195,
                                a8: v194,
                                a9: v328,
                                a10: v329,
                                a11: v330,
                                a12: v331,
                                a13: v332,
                                a14: v333)->xSkip;
              HIDWORD(v200) = v200;
              *(_QWORD *)&v364.variables.num = v200;
              v191 = (float)((float)((float)v200 * (float)v59) + (float)v191);
              if ( v191 >= v189 )
                break;
              v169 = v341;
              v190 = v356;
            }
          }
          v60 = v360;
          v180 = v344.list;
          v75 = *(float *)&v364.variablesHash[13];
          v176 = (float)((float)v176 - (float)v191);
          frameWidth = *(float *)&v364.variablesHash[15];
          v39 = v362;
          goto LABEL_198;
        }
        v171 = v356;
        v179 = 1;
LABEL_201:
        v175 = v344.list;
        v131 = v344.num;
LABEL_202:
        if ( v179 == 0 )
          v171 = v175->len;
        v169 += v178;
        v81 = v347;
        v341 = v169;
        textInstance->inputTextStartChar = v169;
LABEL_205:
        v201 = 0;
        if ( v131 <= 0 )
        {
LABEL_306:
          idStr::FreeData(this: &v408);
          idStr::FreeData(this: &v426);
          idList<idStr,99>::~idList<idStr,99>(this: &v344);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v364);
          goto LABEL_307;
        }
        v202 = v372;
        v203 = v371;
        v204 = v344.list;
        v376 = 2.0;
        while ( 2 )
        {
          v342 = textInstance->isSubtitle;
          if ( v342 && v201 > 0 )
            goto LABEL_306;
          if ( v201 < scroll )
          {
            v205 = this->tooltipIconList.num;
            v206 = v174;
            v207 = v204[v201].len;
            v169 += v207;
            v167 += v207;
            v341 = v169;
            v173 += v204[v201].len;
            if ( v174 < v205 )
            {
              v208 = v174;
              do
              {
                if ( v169 <= this->tooltipIconList.list[v208].startIndex )
                  break;
                ++v206;
                ++v174;
                ++v208;
              }
              while ( v206 < v205 );
            }
LABEL_305:
            if ( ++v201 >= v344.num )
              goto LABEL_306;
            continue;
          }
          break;
        }
        if ( v170 == v364.data.sprite )
          goto LABEL_306;
        v209 = &v204[scroll];
        v210 = v169;
        subCharEndIndex = v209->len;
        if ( v342 )
          subCharEndIndex = textInstance->subCharEndIndex;
        ++scroll;
        if ( v365 )
        {
          if ( v171 == 0 )
            v171 = 1;
          v341 = v171;
          v357 -= v169;
          v358 -= v169;
          subCharEndIndex = v171;
          v343 -= v169;
          idStr::CopyRange(this: v209, text: v209->data, start: v169, end: v171);
        }
        else
        {
          v212 = v169 + 1;
          if ( subCharEndIndex != 0 )
            v212 = subCharEndIndex + v169;
          v341 = v212;
        }
        v213 = 0;
        v214 = v37;
        v215 = 0;
        v337 = 0;
        if ( subCharEndIndex > 0 )
        {
          v216 = v348;
          v217 = v174;
          while ( 1 )
          {
            if ( v174 < this->tooltipIconList.num
              && (v218 = this->tooltipIconList.list, v218[v217].startIndex == v215 + v210) )
            {
              ++v174;
              v219 = &v218[v217++];
              LODWORD(v91) = v219->imageWidth;
              v220 = v219->endIndex - v219->startIndex;
              v410 = v91;
              v215 += v220;
              v214 = (float)((float)((float)v91 * (float)v60) + (float)v214);
            }
            else
            {
              if ( v215 < v209->len )
              {
                v221 = idStr::UTF8Char(s: (const unsigned __int8 *)v209->data, idx: &v337);
                Glyph = idFont::GetGlyph(
                          this: v340,
                          idx: v221,
                          a3: v227,
                          a4: v226,
                          a5: v225,
                          a6: v224,
                          a7: v223,
                          a8: v222,
                          a9: v328,
                          a10: v329,
                          a11: v330,
                          a12: v331,
                          a13: v332,
                          a14: v333);
                v215 = v337;
                if ( v221 != 94 )
                  goto LABEL_238;
                if ( &v209->data[v337] == (char *)1
                  || v209->data[v337 - 1] != 94
                  || v209->data[v337] == 0
                  || (v229 = 1, v209->data[v337] == 32) )
                {
                  v229 = 0;
                }
                if ( v229 == 0 )
                {
LABEL_238:
                  LODWORD(v230) = Glyph->xSkip;
                  HIDWORD(v230) = textInstance->useStroke;
                  v404 = v230;
                  v214 = (float)((float)((float)v230 * (float)v59) + (float)v214);
                  if ( HIDWORD(v230) != 0 )
                    v214 = (float)((float)((float)((float)v59 * textInstance->strokeWeight) * v216->valueFloat)
                                 + (float)v214);
                  goto LABEL_242;
                }
              }
              ++v215;
            }
            v337 = v215;
LABEL_242:
            if ( v215 >= subCharEndIndex )
            {
              v213 = 0;
              break;
            }
          }
        }
        *(float *)&v364.variables.granularity = v37;
        v419 = __PAIR64__((unsigned int)v361, (unsigned int)v170);
        align = v361->align;
        v232 = (float)((float)v37
                     + (float)((float)((float)__SPAIR64__((unsigned int)v361, (unsigned int)v170) * (float)v81)
                             + *(float *)&v364.variablesHash[14]));
        *(float *)v364.variablesHash = (float)v37
                                     + (float)((float)((float)__SPAIR64__((unsigned int)v361, (unsigned int)v170)
                                                     * (float)v81)
                                             + *(float *)&v364.variablesHash[14]);
        if ( align <= 3 )
        {
          if ( align == 1 )
          {
            v143 = (float)((float)frameWidth - (float)v214);
            v339 = (float)frameWidth - (float)v214;
          }
          else if ( align == 2 )
          {
            v143 = (float)((float)((float)((float)frameWidth + (float)v75) - (float)v214) * (float)v39);
            v339 = (float)((float)((float)frameWidth + (float)v75) - (float)v214) * (float)v39;
          }
          else if ( align != 0 )
          {
            v339 = v75;
            v143 = v75;
            if ( v214 > (float)((float)((float)frameWidth - (float)v75) * (float)v39) )
            {
              HIDWORD(v233) = v344.num - 1;
              if ( (int)v170 < v344.num - 1 )
              {
                LODWORD(v233) = subCharEndIndex;
                v421 = v233;
                *(float *)&v364.variables.granularity = (float)((float)((float)frameWidth - (float)v75) - (float)v214)
                                                      / (float)((float)v233 - (float)v47);
              }
            }
          }
          else
          {
            v339 = v75;
            v143 = v75;
          }
        }
        v352 = nullptr;
        v353 = 0;
        v234 = v172;
        v350 = -1;
        v351 = -1;
        v235 = this->tooltipIconList.num;
        v354 = 0;
        v355 = 0;
        if ( v172 < v235 )
        {
          v236 = v172;
          do
          {
            if ( v173 <= this->tooltipIconList.list[v236].startIndex )
              break;
            ++v234;
            ++v172;
            ++v236;
          }
          while ( v234 < v235 );
        }
        LODWORD(v237) = idFont::GetAscender(this: v340);
        v337 = 0;
        v238 = 0;
        v423 = v237;
        v239 = 0;
        v359 = (float)((float)v237 * (float)v59) + (float)v232;
        if ( subCharEndIndex <= 0 )
        {
LABEL_304:
          v169 = v341;
          v81 = v347;
          v204 = v344.list;
          v170 = (idSWFSpriteInstance *)((char *)v170 + 1);
          goto LABEL_305;
        }
        v240 = v172;
        while ( 1 )
        {
          if ( v238 >= v209->len )
            goto LABEL_304;
          v245 = idStr::UTF8Char(s: (const unsigned __int8 *)v209->data, idx: &v337);
          v238 = v337;
          v246 = v245;
          if ( v245 == 10 )
            goto LABEL_301;
          if ( v245 != 32 )
            break;
          if ( v337 != 1 )
            goto LABEL_274;
          v173 = v173 - v239 + 1;
          v239 = 1;
LABEL_302:
          ++v167;
LABEL_303:
          if ( v238 >= subCharEndIndex )
            goto LABEL_304;
          v232 = *(float *)v364.variablesHash;
        }
        if ( v245 == 94 )
        {
          if ( &v209->data[v337] == (char *)1
            || (v241 = (unsigned __int8)v209->data[v337 - 1]) != 94
            || v209->data[v337] == 0
            || (v247 = 1, v209->data[v337] == 32) )
          {
            v247 = 0;
          }
          if ( v247 != 0 )
          {
            w = v349.w;
            ++v337;
            v249 = idStr::ColorForIndex(i: v209->data[v238]);
            v349.x = v249->x;
            v238 = v337;
            v349.y = v249->y;
            v349.z = v249->z;
            v349.w = w;
            goto LABEL_303;
          }
        }
LABEL_274:
        if ( v172 < this->tooltipIconList.num )
        {
          v242 = &v349.w;
          v241 = (int)&this->tooltipIconList.list[v240 - 1].baseline;
          for ( m = 5; m != 0; --m )
          {
            v241 += 4;
            *++v242 = *(float *)v241;
          }
        }
        if ( v173 == v350 )
        {
          v213 = 1;
          v252 = idFont::GetGlyph(
                   this: v340,
                   idx: v245,
                   a3: v91,
                   a4: v244,
                   a5: v243,
                   a6: v238,
                   a7: (int)v242,
                   a8: v241,
                   a9: v328,
                   a10: v329,
                   a11: v330,
                   a12: v331,
                   a13: v332,
                   a14: v333);
          HIDWORD(v253) = v252->height;
          LODWORD(v253) = v354;
          v411 = *(__int64 *)((char *)&v253 + 4);
          v401 = v253;
          v254 = (float)((float)v253 * (float)v60);
          if ( v355 != 0 )
          {
            v255 = (float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v59);
            v256 = (float)((float)((float)v255 + (float)v232) - (float)((float)((float)v401 * (float)v60) - (float)v255));
          }
          else
          {
            LODWORD(v251) = v252->top;
            v403 = v251;
            v256 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v59)
                                         - (float)((float)v253 * (float)v60))
                                 * (float)v39)
                         - (float)((float)((float)v251 * (float)v59) - v359));
          }
          HIDWORD(v253) = v353;
          LODWORD(v253) = v252->left;
          v413 = *(__int64 *)((char *)&v253 + 4);
          v405 = v253;
          v257 = (float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v60);
          v258 = (float)((float)((float)((float)((float)((float)v253 * (float)v59) + (float)v143) * (float)v49)
                               + (float)((float)v256 * (float)v50))
                       + (float)v203);
          v259 = (float)((float)((float)((float)((float)((float)v253 * (float)v59) + (float)v143) * (float)v53)
                               + (float)((float)v256 * (float)v51))
                       + (float)v202);
          v260 = (float)((float)((float)((float)((float)v254 + (float)v256) * (float)v51)
                               + (float)((float)((float)((float)v253 * (float)v59) + (float)v143) * (float)v53))
                       + (float)v202);
          v262 = (float)((float)((float)((float)((float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v60)
                                               + (float)((float)((float)v253 * (float)v59) + (float)v143))
                                       * (float)v49)
                               + (float)((float)v256 * (float)v50))
                       + (float)v203);
          v346 = (float)((float)((float)((float)v254 + (float)v256) * (float)v50)
                       + (float)((float)((float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v60)
                                       + (float)((float)((float)v253 * (float)v59) + (float)v143))
                               * (float)v49))
               + (float)v203;
          v263 = (float)((float)((float)((float)((float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v60)
                                               + (float)((float)((float)v253 * (float)v59) + (float)v143))
                                       * (float)v53)
                               + (float)((float)v256 * (float)v51))
                       + (float)v202);
          v264 = (float)((float)((float)((float)((float)v254 + (float)v256) * (float)v51)
                               + (float)((float)((float)((float)*(__int64 *)((char *)&v253 + 4) * (float)v60)
                                               + (float)((float)((float)v253 * (float)v59) + (float)v143))
                                       * (float)v53))
                       + (float)v202);
          v261 = (float)((float)((float)((float)((float)v254 + (float)v256) * (float)v50)
                               + (float)((float)((float)((float)v253 * (float)v59) + (float)v143) * (float)v49))
                       + (float)v203);
          v265 = idColor::PackColor(color: &v349);
          v385.y = v260;
          v37 = v363;
          v266 = v346;
          v385.x = v261;
          v385.z = v363;
          gui->currentVertexColor = v265;
          v385.w = v47;
          v396.x = v266;
          v396.y = v264;
          v396.z = v47;
          v396.w = v47;
          v398.x = v262;
          v398.y = v263;
          v398.z = v47;
          v398.w = v37;
          v389.x = v258;
          v389.y = v259;
          v389.z = v37;
          v389.w = v37;
          idRenderModelGui::DrawStretchPic(
            this: gui,
            topLeft: &v389,
            topRight: &v398,
            bottomRight: &v396,
            bottomLeft: &v385,
            material: v352);
          v238 = v337;
          v39 = v362;
          frameWidth = *(float *)&v364.variablesHash[15];
          v75 = *(float *)&v364.variablesHash[13];
          v60 = v360;
          v143 = (float)((float)((float)v143 + (float)v257) + *(float *)&v364.variables.granularity);
          v339 = v143;
        }
        else if ( v173 == v351 )
        {
          v213 = 0;
          ++v172;
          ++v240;
        }
        if ( v213 != 0 )
        {
          v173 += v238 - v239;
          v239 = v238;
          goto LABEL_303;
        }
        v267 = idFont::GetGlyph(
                 this: v340,
                 idx: v246,
                 a3: v91,
                 a4: v244,
                 a5: v243,
                 a6: v238,
                 a7: (int)v242,
                 a8: v241,
                 a9: v328,
                 a10: v329,
                 a11: v330,
                 a12: v331,
                 a13: v332,
                 a14: v333);
        LODWORD(v268) = v267->xSkip;
        useStroke = textInstance->useStroke;
        v415 = v268;
        v346 = (float)v268 * (float)v59;
        if ( useStroke )
          v346 = (float)((float)(textInstance->strokeWeight * (float)v59) * v348->valueFloat)
               + (float)((float)v268 * (float)v59);
        LODWORD(v270) = v267->width;
        LODWORD(v271) = v267->top;
        DWORD1(v270) = v267->height;
        DWORD2(v270) = v267->s;
        DWORD1(v271) = v270;
        left = v267->left;
        HIDWORD(v270) = v267->t;
        v422 = v270;
        v273 = v270;
        v418 = *(_QWORD *)&v270;
        DWORD2(v271) = left;
        v417 = v271;
        v274 = DWORD2(v270) + v270;
        LODWORD(v270) = DWORD2(v270);
        v412 = *(_QWORD *)((char *)&v271 + 4);
        v407 = v270;
        v275 = v270;
        v399 = *(_QWORD *)((char *)&v271 - 4);
        DWORD2(v270) = HIDWORD(v270);
        v276 = (double)*(__int64 *)((char *)&v271 + 4);
        v424 = *(_QWORD *)((char *)&v270 + 4);
        HIDWORD(v271) = v357;
        v277 = (float)((float)((float)*(__int64 *)&v270 * (float)v59) + (float)v47);
        *(float *)&v364.variablesHash[1] = (float)((float)*(__int64 *)&v270 * (float)v59) + (float)v47;
        v278 = (float)-(float)((float)((float)(__int64)v271 * (float)v59) - v359);
        v279 = (float)((float)((float)v273 * (float)v59) + (float)v47);
        v280 = (float)((float)((float)*(__int64 *)((char *)&v271 + 4) * (float)v59) + (float)v143);
        v281 = (float)((float)((float)v275 - v362) * v378);
        v282 = (float)((float)((float)*(__int64 *)((char *)&v270 + 4) - v362) * v374);
        v283 = (float)((float)((float)*(__int64 *)((char *)&v271 - 4) + v362) * v378);
        v336 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v271 + 4) * (float)v59) + (float)v143)
                             * (float)v53)
                     + (float)((float)-(float)((float)((float)(__int64)v271 * (float)v59) - v359) * (float)v51))
             + (float)v202;
        DWORD1(v271) = HIDWORD(v270) + DWORD1(v270);
        v414 = *(_QWORD *)&v271;
        v402 = (float)((float)((float)((float)((float)v276 * (float)v59) + (float)v143) * (float)v49)
                     + (float)((float)-(float)((float)((float)(__int64)v271 * (float)v59) - v359) * (float)v50))
             + (float)v203;
        v377 = (float)((float)((float)(*(float *)&v364.variablesHash[1]
                                     - (float)((float)((float)(__int64)v271 * (float)v59) - v359))
                             * (float)v51)
                     + (float)((float)((float)((float)v276 * (float)v59) + (float)v143) * (float)v53))
             + (float)v202;
        v373 = (float)((float)((float)(*(float *)&v364.variablesHash[1]
                                     - (float)((float)((float)(__int64)v271 * (float)v59) - v359))
                             * (float)v51)
                     + (float)((float)((float)((float)((float)v276 * (float)v59) + (float)v143)
                                     + (float)((float)((float)v273 * (float)v59) + (float)v47))
                             * (float)v53))
             + (float)v202;
        v400 = (float)((float)((float)((float)((float)((float)v276 * (float)v59) + (float)v143)
                                     + (float)((float)((float)v273 * (float)v59) + (float)v47))
                             * (float)v49)
                     + (float)((float)-(float)((float)((float)(__int64)v271 * (float)v59) - v359) * (float)v50))
             + (float)v203;
        v409 = (float)((float)((float)(*(float *)&v364.variablesHash[1]
                                     - (float)((float)((float)(__int64)v271 * (float)v59) - v359))
                             * (float)v50)
                     + (float)((float)((float)((float)((float)v276 * (float)v59) + (float)v143)
                                     + (float)((float)((float)v273 * (float)v59) + (float)v47))
                             * (float)v49))
             + (float)v203;
        *(float *)&v364.variables.num = (float)((float)((float)((float)((float)((float)v276 * (float)v59) + (float)v143)
                                                              + (float)((float)((float)v273 * (float)v59) + (float)v47))
                                                      * (float)v53)
                                              + (float)((float)-(float)((float)((float)(__int64)v271 * (float)v59) - v359)
                                                      * (float)v51))
                                      + (float)v202;
        v406 = (float)((float)((float)(*(float *)&v364.variablesHash[1]
                                     - (float)((float)((float)(__int64)v271 * (float)v59) - v359))
                             * (float)v50)
                     + (float)((float)((float)((float)v276 * (float)v59) + (float)v143) * (float)v49))
             + (float)v203;
        v284 = (float)((float)((float)*(__int64 *)&v271 + v362) * v374);
        if ( v167 <= v357 || v167 > v358 )
        {
          v297 = gui;
        }
        else
        {
          v285 = (float)((float)((float)(v346 + (float)v143) * (float)v49)
                       + (float)(*(float *)v364.variablesHash * (float)v50));
          v286 = (float)((float)((float)(*(float *)v364.variablesHash + v347) * (float)v50)
                       + (float)((float)v143 * (float)v49));
          v287 = (float)((float)((float)(*(float *)v364.variablesHash + v347) * (float)v51)
                       + (float)((float)v143 * (float)v53));
          v288 = (float)((float)((float)(*(float *)v364.variablesHash + v347) * (float)v51)
                       + (float)((float)(v346 + (float)v143) * (float)v53));
          v289 = (float)((float)((float)(*(float *)v364.variablesHash + v347) * (float)v50)
                       + (float)((float)(v346 + (float)v143) * (float)v49));
          v290 = (float)((float)((float)((float)v143 * (float)v49) + (float)(*(float *)v364.variablesHash * (float)v50))
                       + (float)v203);
          v291 = (float)((float)((float)((float)v143 * (float)v53) + (float)(*(float *)v364.variablesHash * (float)v51))
                       + (float)v202);
          v292 = (float)((float)((float)((float)(v346 + (float)v143) * (float)v53)
                               + (float)(*(float *)v364.variablesHash * (float)v51))
                       + (float)v202);
          v293 = (float)((float)v285 + (float)v203);
          *(float *)&v375 = (float)v286 + (float)v203;
          v379 = (float)v287 + (float)v202;
          v294 = (float)((float)v288 + (float)v202);
          v295 = (float)((float)v289 + (float)v203);
          v296 = idColor::PackColor(color: &v427);
          v297 = gui;
          v380.variablesHash[13] = v375;
          v37 = v363;
          v47 = *(float *)&v364.objectType;
          v298 = v379;
          gui->currentVertexColor = v296;
          *(float *)&v380.variablesHash[14] = v298;
          *(float *)&v380.variablesHash[15] = v37;
          *(float *)&v380.prototype = v47;
          white = this->white;
          v397.x = v295;
          v397.y = v294;
          v397.z = v47;
          v397.w = v47;
          v383.x = v293;
          v383.y = v292;
          v383.z = v47;
          v383.w = v37;
          v391.x = v290;
          v391.y = v291;
          v391.z = v37;
          v391.w = v37;
          idRenderModelGui::DrawStretchPic(
            this: gui,
            topLeft: &v391,
            topRight: &v383,
            bottomRight: &v397,
            bottomLeft: (const idVec4 *)&v380.variablesHash[13],
            material: white);
          v300 = idColor::PackColor(color: &v349);
          v49 = v367;
          v277 = *(float *)&v364.variablesHash[1];
          gui->currentVertexColor = v300;
          v143 = v339;
          v53 = v370;
          v51 = v368;
          v50 = v369;
        }
        if ( textInstance->useDropShadow )
        {
          v428.x = idColor::colorBlack.r;
          v428.y = idColor::colorBlack.g;
          v428.z = idColor::colorBlack.b;
          v428.w = v349.w;
          v301 = (float)((float)((float)((float)v280 + (float)((float)v59 * v376)) * (float)v49)
                       + (float)((float)((float)v278 + (float)((float)v59 * v376)) * (float)v50));
          v302 = (float)((float)((float)((float)((float)v278 + (float)((float)v59 * v376)) + (float)v277) * (float)v51)
                       + (float)((float)((float)v280 + (float)((float)v59 * v376)) * (float)v53));
          v303 = (float)((float)((float)((float)((float)v280 + (float)((float)v59 * v376)) + (float)v279) * (float)v53)
                       + (float)((float)((float)v278 + (float)((float)v59 * v376)) * (float)v51));
          v304 = (float)((float)((float)((float)((float)v280 + (float)((float)v59 * v376)) + (float)v279) * (float)v49)
                       + (float)((float)((float)v278 + (float)((float)v59 * v376)) * (float)v50));
          v305 = (float)((float)((float)((float)((float)v278 + (float)((float)v59 * v376)) + (float)v277) * (float)v51)
                       + (float)((float)((float)((float)v280 + (float)((float)v59 * v376)) + (float)v279) * (float)v53));
          v306 = (float)((float)((float)((float)((float)v278 + (float)((float)v59 * v376)) + (float)v277) * (float)v50)
                       + (float)((float)((float)((float)v280 + (float)((float)v59 * v376)) + (float)v279) * (float)v49));
          v307 = (float)((float)((float)((float)((float)v278 + (float)((float)v59 * v376)) + (float)v277) * (float)v50)
                       + (float)((float)((float)v280 + (float)((float)v59 * v376)) * (float)v49));
          v308 = (float)((float)((float)((float)((float)v280 + (float)((float)v59 * v376)) * (float)v53)
                               + (float)((float)((float)v278 + (float)((float)v59 * v376)) * (float)v51))
                       + (float)v202);
          v309 = (float)((float)v301 + (float)v203);
          v310 = (float)((float)v302 + (float)v202);
          v311 = (float)((float)v303 + (float)v202);
          v312 = (float)((float)v304 + (float)v203);
          v313 = (float)((float)v305 + (float)v202);
          v314 = (float)((float)v306 + (float)v203);
          v315 = (float)((float)v307 + (float)v203);
          v297->currentVertexColor = idColor::PackColor(color: &v428);
          *(float *)&v380.variablesHash[1] = v315;
          *(float *)&v380.variablesHash[2] = v310;
          *(float *)&v380.variablesHash[3] = v281;
          *(float *)&v380.variablesHash[4] = v284;
          v395.x = v314;
          v395.y = v313;
          v395.z = v283;
          v395.w = v284;
          v387.x = v312;
          v387.y = v311;
          v387.z = v283;
          v387.w = v282;
          v393.x = v309;
          v393.y = v308;
          v393.z = v281;
          v393.w = v282;
          Material = idFont::GetMaterial(this: v340);
          idRenderModelGui::DrawStretchPic(
            this: v297,
            topLeft: &v393,
            topRight: &v387,
            bottomRight: &v395,
            bottomLeft: (const idVec4 *)&v380.variablesHash[1],
            material: Material);
          v317 = idColor::PackColor(color: &v349);
          v53 = v370;
          v143 = v339;
          v297->currentVertexColor = v317;
          v37 = v363;
          v47 = *(float *)&v364.objectType;
        }
        else if ( textInstance->useStroke )
        {
          v318 = (float)(textInstance->strokeStrength * v349.w);
          v429.x = idColor::colorBlack.r;
          v429.y = idColor::colorBlack.g;
          v429.z = idColor::colorBlack.b;
          v429.w = v318;
          v320 = idColor::PackColor(color: &v429);
          HIDWORD(v321) = gui;
          v322 = 0;
          gui->currentVertexColor = v320;
          do
          {
            LODWORD(v319) = v380.variablesHash[v322 - 3];
            *(float *)&v364.variablesHash[1] = textInstance->strokeWeight;
            v420 = v319;
            LODWORD(v321) = v380.variablesHash[v322 + 5];
            *(float *)&v380.variablesHash[11] = v281;
            v416 = v321;
            *(float *)&v380.variablesHash[12] = v284;
            v381 = v283;
            v382 = v284;
            v384.z = v283;
            v384.w = v282;
            v386.z = v281;
            v386.w = v282;
            v386.x = (float)((float)((float)((float)((float)((float)v319 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v280)
                                   * (float)v49)
                           + (float)((float)((float)((float)((float)v321 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v278)
                                   * (float)v50))
                   + (float)v203;
            v386.y = (float)((float)((float)((float)((float)((float)v319 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v280)
                                   * (float)v53)
                           + (float)((float)((float)((float)((float)v321 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v278)
                                   * (float)v51))
                   + (float)v202;
            v384.x = (float)((float)((float)((float)((float)((float)((float)v319 * *(float *)&v364.variablesHash[1])
                                                           * (float)v59)
                                                   + (float)v280)
                                           + (float)v279)
                                   * (float)v49)
                           + (float)((float)((float)((float)((float)v321 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v278)
                                   * (float)v50))
                   + (float)v203;
            v384.y = (float)((float)((float)((float)((float)((float)((float)v319 * *(float *)&v364.variablesHash[1])
                                                           * (float)v59)
                                                   + (float)v280)
                                           + (float)v279)
                                   * (float)v53)
                           + (float)((float)((float)((float)((float)v321 * *(float *)&v364.variablesHash[1]) * (float)v59)
                                           + (float)v278)
                                   * (float)v51))
                   + (float)v202;
            *(float *)&v380.variablesHash[9] = (float)((float)((float)((float)((float)((float)((float)v321
                                                                                             * *(float *)&v364.variablesHash[1])
                                                                                     * (float)v59)
                                                                             + (float)v278)
                                                                     + (float)v277)
                                                             * (float)v50)
                                                     + (float)((float)((float)((float)((float)v319
                                                                                     * *(float *)&v364.variablesHash[1])
                                                                             * (float)v59)
                                                                     + (float)v280)
                                                             * (float)v49))
                                             + (float)v203;
            *(float *)&v380.variablesHash[10] = (float)((float)((float)((float)((float)((float)((float)v321
                                                                                              * *(float *)&v364.variablesHash[1])
                                                                                      * (float)v59)
                                                                              + (float)v278)
                                                                      + (float)v277)
                                                              * (float)v51)
                                                      + (float)((float)((float)((float)((float)v319
                                                                                      * *(float *)&v364.variablesHash[1])
                                                                              * (float)v59)
                                                                      + (float)v280)
                                                              * (float)v53))
                                              + (float)v202;
            *(float *)&v380.objectType = (float)((float)((float)((float)((float)((float)((float)v321
                                                                                       * *(float *)&v364.variablesHash[1])
                                                                               * (float)v59)
                                                                       + (float)v278)
                                                               + (float)v277)
                                                       * (float)v50)
                                               + (float)((float)((float)((float)((float)((float)v319
                                                                                       * *(float *)&v364.variablesHash[1])
                                                                               * (float)v59)
                                                                       + (float)v280)
                                                               + (float)v279)
                                                       * (float)v49))
                                       + (float)v203;
            *(float *)&v380.data.sprite = (float)((float)((float)((float)((float)((float)((float)v321
                                                                                        * *(float *)&v364.variablesHash[1])
                                                                                * (float)v59)
                                                                        + (float)v278)
                                                                + (float)v277)
                                                        * (float)v51)
                                                + (float)((float)((float)((float)((float)((float)v319
                                                                                        * *(float *)&v364.variablesHash[1])
                                                                                * (float)v59)
                                                                        + (float)v280)
                                                                + (float)v279)
                                                        * (float)v53))
                                        + (float)v202;
            v323 = idFont::GetMaterial(this: v340);
            idRenderModelGui::DrawStretchPic(
              this: gui,
              topLeft: &v386,
              topRight: &v384,
              bottomRight: (const idVec4 *)&v380.objectType,
              bottomLeft: (const idVec4 *)&v380.variablesHash[9],
              material: v323);
            ++v322;
          }
          while ( v322 < 4 );
          v297 = gui;
          gui->currentVertexColor = idColor::PackColor(color: &v349);
        }
        v388.x = v406;
        v388.y = v377;
        v388.z = v281;
        v388.w = v284;
        v390.x = v409;
        v390.y = v373;
        v390.z = v283;
        v390.w = v284;
        v392.x = v400;
        v392.y = *(float *)&v364.variables.num;
        v392.z = v283;
        v392.w = v282;
        v394.x = v402;
        v394.y = v336;
        v394.z = v281;
        v394.w = v282;
        v324 = idFont::GetMaterial(this: v340);
        idRenderModelGui::DrawStretchPic(
          this: v297,
          topLeft: &v394,
          topRight: &v392,
          bottomRight: &v390,
          bottomLeft: &v388,
          material: v324);
        v143 = (float)(*(float *)&v364.variables.granularity + (float)(v346 + (float)v143));
        v339 = v143;
        if ( v343 == v167 )
          idSWF::DrawEditCursor(
            this,
            gui: v297,
            x: (float)((float)v143 - (float)v47),
            y: *(float *)v364.variablesHash,
            w: v47,
            h: v347,
            matrix: (const swfMatrix_t *)v91,
            a8: v327,
            a9: v326,
            a10: v325,
            a11: &v367);
        v238 = v337;
        v60 = v360;
        v75 = *(float *)&v364.variablesHash[13];
        frameWidth = *(float *)&v364.variablesHash[15];
        v39 = v362;
LABEL_301:
        v173 += v238 - v239;
        v239 = v238;
        goto LABEL_302;
      }
      if ( v364.variablesHash[5] != 0 )
        goto _M228145;
    }
LABEL_63:
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v364);
    goto LABEL_307;
  }
}


// ========================================================================
// __unwind$226699
// EA  : 0x82782EF4
// RVA : 0x00782EF4
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226699()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 272));
}


// ========================================================================
// __unwind$226700
// EA  : 0x82782F1C
// RVA : 0x00782F1C
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226700()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1200));
}


// ========================================================================
// __unwind$226701
// EA  : 0x82782F44
// RVA : 0x00782F44
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226701()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1232));
}


// ========================================================================
// __unwind$226702
// EA  : 0x82782F6C
// RVA : 0x00782F6C
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226702()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1856 + 392));
}


// ========================================================================
// __unwind$226703_0
// EA  : 0x82782F94
// RVA : 0x00782F94
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226703_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1104));
}


// ========================================================================
// __unwind$226704_0
// EA  : 0x82782FBC
// RVA : 0x00782FBC
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226704_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1136));
}


// ========================================================================
// __unwind$226705
// EA  : 0x82782FE4
// RVA : 0x00782FE4
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226705()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1856 + 232));
}


// ========================================================================
// __unwind$226706
// EA  : 0x8278300C
// RVA : 0x0078300C
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226706()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1856 + 128));
}


// ========================================================================
// __unwind$226707
// EA  : 0x82783034
// RVA : 0x00783034
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226707()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 992));
}


// ========================================================================
// __unwind$226708
// EA  : 0x8278305C
// RVA : 0x0078305C
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226708()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 1856 + 1264));
}


// ========================================================================
// __unwind$226709
// EA  : 0x82783084
// RVA : 0x00783084
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1168));
}


// ========================================================================
// __unwind$226710
// EA  : 0x827830AC
// RVA : 0x007830AC
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226710()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 1856 + 1408));
}


// ========================================================================
// __unwind$226711
// EA  : 0x827830D4
// RVA : 0x007830D4
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226711()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 1024));
}


// ========================================================================
// __unwind$226712
// EA  : 0x827830FC
// RVA : 0x007830FC
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_226712()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1856 + 832));
}


// ========================================================================
// ?RenderSprite@idSWF@@AAAXPAVidRenderModelGui@@PAVidSWFSpriteInstance@@ABUswfRenderState_t@@H_N@Z
// EA  : 0x82783130
// RVA : 0x00783130
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __fastcall idSWF::RenderSprite(
        idSWF *this,
        idRenderModelGui *gui,
        idSWFSpriteInstance *spriteInstance,
        const swfRenderState_t *renderState,
        int time,
        bool isSplitscreen)
{
  int num; // r6
  int v12; // r21
  int v13; // r29
  swfDisplayEntry_t *v14; // r30
  int v15; // r28
  const swfDisplayEntry_t *v16; // r5
  int v17; // r11
  idSWFDictionaryEntry *DictionaryEntry; // r29
  double xx; // fp12
  double yx; // fp11
  double tx; // fp10
  double ty; // fp9
  double xy; // fp4
  double v24; // fp5
  double v25; // fp8
  double v26; // fp0
  double v27; // fp13
  double v28; // fp7
  double v29; // fp6
  swfColorXform_t *v30; // r3
  unsigned __int16 blendMode; // r11
  int activeMasks; // r10
  const idMaterial *materialOverride; // r11
  int materialWidth; // r10
  int materialHeight; // r9
  swfDictType_t type; // r11
  idSWFSpriteInstance *v37; // r11
  double yOffset; // fp0
  idSWFSpriteInstance *v39; // r10
  unsigned int followBorder; // r29
  double VirtualWidth; // fp31
  __int64 v42; // r10
  double VirtualHeight; // fp1
  double valueFloat; // fp0
  const char **p_str; // r11
  const char *v46; // r3
  double v47; // fp31
  double v48; // fp30
  double v49; // fp25
  double v50; // fp5
  double v51; // fp11
  idSWFSpriteInstance *v52; // r11
  double v53; // fp11
  double v54; // fp10
  idSWFSpriteInstance *v55; // r11
  double v56; // fp11
  double v57; // fp10
  double v58; // fp9
  idSWFSpriteInstance *v59; // r11
  double v60; // fp12
  double v61; // fp11
  double v62; // fp10
  double v63; // fp9
  double v64; // fp0
  idSWFSpriteInstance *v65; // r11
  double v66; // fp13
  double v67; // fp0
  double v68; // fp11
  double v69; // fp10
  idSWFSpriteInstance *v70; // r11
  double v71; // fp31
  double v72; // fp25
  double v73; // fp0
  double v74; // fp24
  double v75; // fp1
  double v76; // fp6
  double v77; // fp4
  double v78; // fp0
  idSWFSpriteInstance *v79; // r11
  double v80; // fp1
  double v81; // fp10
  double xOffset; // fp9
  idSWFSpriteInstance *v83; // r11
  double v84; // fp1
  double v85; // fp10
  double v86; // fp9
  idSWFSpriteInstance *v87; // r11
  double v88; // fp1
  double yy; // fp10
  double v90; // fp9
  double v91; // fp8
  idSWFSpriteInstance *v92; // r11
  double v93; // fp30
  double v94; // fp25
  double v95; // fp1
  double v96; // fp11
  double v97; // fp10
  double v98; // fp0
  idSWFSpriteInstance *v99; // r11
  double v100; // fp31
  double v101; // fp30
  double v102; // fp1
  double v103; // fp11
  double v104; // fp10
  double v105; // fp0
  idSWFSpriteInstance *v106; // r11
  double v107; // fp1
  double v108; // fp4
  double v109; // fp3
  idSWFSpriteInstance *v110; // r11
  double v111; // fp8
  double v112; // fp7
  idSWFSpriteInstance *v113; // r11
  double v114; // fp1
  double v115; // fp10
  double v116; // fp9
  double v117; // fp8
  idSWFSpriteInstance *v118; // r11
  double v119; // fp1
  double v120; // fp7
  double v121; // fp6
  idSWFSpriteInstance *v122; // r11
  double v123; // fp1
  double v124; // fp5
  const char *str; // r3
  int v126; // r10
  int v127; // r11
  int v128; // r10
  int v129; // r29
  int v130; // r30
  int p_matrix; // [sp+50h] [-5E0h] BYREF
  int v132; // [sp+54h] [-5DCh]
  swfRenderState_t v133; // [sp+60h] [-5D0h] BYREF
  int v134; // [sp+B0h] [-580h]
  const char *v135; // [sp+B4h] [-57Ch]
  const char *v136; // [sp+B8h] [-578h]
  const char *v137; // [sp+BCh] [-574h]
  const char *v138; // [sp+C0h] [-570h]
  const char *v139; // [sp+C4h] [-56Ch]
  const char *v140; // [sp+C8h] [-568h]
  const char *v141; // [sp+CCh] [-564h]
  const char *v142; // [sp+D0h] [-560h]
  const char *v143; // [sp+D4h] [-55Ch]
  const char *v144; // [sp+D8h] [-558h]
  const char *v145; // [sp+DCh] [-554h]
  const char *v146; // [sp+E0h] [-550h]
  const char *v147; // [sp+E4h] [-54Ch]
  __int64 v148; // [sp+E8h] [-548h]
  __int64 v149; // [sp+F0h] [-540h]
  __int64 v150; // [sp+F8h] [-538h]
  __int64 v151; // [sp+100h] [-530h]
  __int64 v152; // [sp+108h] [-528h]
  __int64 v153; // [sp+110h] [-520h]
  swfColorXform_t v154; // [sp+120h] [-510h] BYREF
  idList<enum encounterGroupRole_t,5> v155; // [sp+140h] [-4F0h] BYREF
  int v156; // [sp+150h] [-4E0h] BYREF

  if ( spriteInstance == nullptr )
  {
    idLib::Warning(fmt: "%s: RenderSprite: spriteInstance == NULL", this->filename.str);
    return;
  }
  if ( (spriteInstance->isVisible || swf_ignoreVisible.valueInteger != 0)
    && ((float)(renderState->cxf.add.w + renderState->cxf.mul.w) > 0.001 || swf_forceAlpha.valueFloat > 0.0) )
  {
    v155.granularity = 1;
    v155.size = 256;
    v155.num = 0;
    v155.memTag = 5;
    v155.list = (encounterGroupRole_t *)&v156;
    v155.listStatic = 1;
    num = spriteInstance->displayList.num;
    v134 = 0;
    if ( num > 0 )
    {
      p_matrix = 0;
      v138 = "_absLeft";
      v143 = "_topLeft";
      v137 = "__radial";
      v136 = "_absTopLeft";
      v141 = "_bottomRight";
      v140 = "_top";
      v139 = "_absTop";
      v135 = "_absRight";
      v146 = "_right";
      v142 = "_topRight";
      v144 = "_bottom";
      v12 = 0;
      v147 = "_absBottom";
      v145 = "_bottomLeft";
      do
      {
        v13 = 0;
        v14 = &spriteInstance->displayList.list[v12];
        if ( v155.num > 0 )
        {
          v15 = 0;
          do
          {
            v16 = (const swfDisplayEntry_t *)v155.list[v15];
            if ( v14->depth > (unsigned int)v16->clipDepth )
            {
              idSWF::RenderMask(this, gui, mask: v16, renderState, material: this->guiStencilDecr);
              if ( v13 >= 0 && v13 < v155.num )
              {
                v17 = v155.num - 1;
                v155.num = v17;
                if ( v13 != v17 )
                  v155.list[v15] = v155.list[v17];
              }
            }
            ++v13;
            ++v15;
          }
          while ( v13 < v155.num );
        }
        if ( v14->clipDepth != 0 )
        {
          p_matrix = (int)v14;
          idList<idAnimWebBlendTree *,5>::Append(this: &v155, obj: (const encounterGroupRole_t *)&p_matrix);
          idSWF::RenderMask(this, gui, mask: v14, renderState, material: this->guiStencilIncr);
        }
        else
        {
          DictionaryEntry = idSWF::FindDictionaryEntry(this, characterID: v14->characterID);
          if ( DictionaryEntry != nullptr )
          {
            v133.matrix.xx = 1.0;
            memset(&v133.material, 0, 17);
            v133.matrix.yy = 1.0;
            v133.matrix.xy = 0.0;
            v133.matrix.yx = 0.0;
            v133.matrix.tx = 0.0;
            v133.matrix.ty = 0.0;
            v133.cxf.mul.x = 1.0;
            v133.cxf.mul.y = 1.0;
            v133.cxf.mul.z = 1.0;
            v133.cxf.mul.w = 1.0;
            p_matrix = (int)&v14->matrix;
            v133.cxf.add.x = 0.0;
            v133.cxf.add.y = 0.0;
            v133.cxf.add.z = 0.0;
            v133.cxf.add.w = 0.0;
            v133.ratio = 0.0;
            xx = renderState->matrix.xx;
            yx = renderState->matrix.yx;
            tx = renderState->matrix.tx;
            ty = renderState->matrix.ty;
            xy = v14->matrix.xy;
            v24 = v14->matrix.xx;
            v25 = (float)(renderState->matrix.yy * v14->matrix.yx);
            v26 = (float)(v14->matrix.yy * renderState->matrix.xy);
            v27 = (float)(v14->matrix.yy * renderState->matrix.yy);
            v28 = (float)((float)(v14->matrix.tx * renderState->matrix.xx)
                        + (float)(v14->matrix.ty * renderState->matrix.xy));
            v29 = (float)((float)(v14->matrix.tx * renderState->matrix.yx)
                        + (float)(v14->matrix.ty * renderState->matrix.yy));
            v133.matrix.xx = (float)(renderState->matrix.xx * v14->matrix.xx)
                           + (float)(renderState->matrix.xy * v14->matrix.yx);
            v133.matrix.yx = (float)((float)yx * (float)v24) + (float)v25;
            v133.matrix.xy = (float)((float)xy * (float)xx) + (float)v26;
            v133.matrix.yy = (float)((float)xy * (float)yx) + (float)v27;
            v133.matrix.tx = (float)v28 + (float)tx;
            v133.matrix.ty = (float)v29 + (float)ty;
            v30 = swfColorXform_t::Multiply(this: &v154, result: &v14->cxf, a: &renderState->cxf);
            v133.cxf.mul.x = v30->mul.x;
            v133.cxf.mul.y = v30->mul.y;
            p_matrix = (int)&v30->add;
            v133.cxf.mul.z = v30->mul.z;
            v133.cxf.mul.w = v30->mul.w;
            v133.cxf.add = v30->add;
            v133.ratio = v14->ratio;
            blendMode = v14->blendMode;
            if ( blendMode == 0 )
              LOBYTE(blendMode) = renderState->blendMode;
            activeMasks = renderState->activeMasks;
            v133.blendMode = blendMode;
            materialOverride = spriteInstance->materialOverride;
            v133.activeMasks = activeMasks + v155.num;
            if ( materialOverride != nullptr )
            {
              materialWidth = spriteInstance->materialWidth;
              materialHeight = spriteInstance->materialHeight;
            }
            else
            {
              materialOverride = renderState->material;
              materialWidth = renderState->materialWidth;
              materialHeight = renderState->materialHeight;
            }
            v133.materialHeight = materialHeight;
            v133.materialWidth = materialWidth;
            v133.material = materialOverride;
            type = DictionaryEntry->type;
            if ( DictionaryEntry->type != SWF_DICT_SPRITE )
            {
              switch ( type )
              {
                case SWF_DICT_SHAPE:
                  idSWF::RenderShape(this, gui, shape: DictionaryEntry->shape, renderState: &v133);
                  break;
                case SWF_DICT_MORPH:
                  idSWF::RenderMorphShape(this, gui, shape: DictionaryEntry->shape, renderState: &v133);
                  break;
                case SWF_DICT_EDITTEXT:
                  idSWF::RenderEditText(
                    this,
                    gui,
                    textInstance: v14->textInstance,
                    renderState: &v133,
                    time,
                    isSplitscreen);
                  break;
                default:
                  break;
              }
              goto LABEL_96;
            }
            v37 = v14->spriteInstance;
            yOffset = spriteInstance->yOffset;
            v37->xOffset = spriteInstance->xOffset;
            v37->yOffset = yOffset;
            v39 = v14->spriteInstance;
            if ( v39->followBorder == -1 )
            {
              valueFloat = swf_safeFrame.valueFloat;
            }
            else
            {
              followBorder = v39->followBorder;
              VirtualWidth = idRenderModelGui::GetVirtualWidth(this: gui);
              VirtualHeight = idRenderModelGui::GetVirtualHeight(this: gui);
              valueFloat = swf_safeFrame.valueFloat;
              if ( followBorder > 8 )
                goto LABEL_49;
              switch ( followBorder )
              {
                case 1u:
                case 2u:
LABEL_34:
                  v132 = (int)(float)((float)(swf_safeFrame.valueFloat * (float)VirtualHeight)
                                    - (float)((float)(this->frameHeight * (float)0.075000003) - v133.matrix.ty));
                  LODWORD(v42) = v132;
                  v148 = v42;
                  v133.matrix.ty = (float)v42;
                  break;
                case 3u:
                case 4u:
                case 5u:
                  v132 = (int)(float)((float)((float)VirtualHeight * (float)0.5)
                                    - (float)((float)(this->frameHeight * (float)0.5) - v133.matrix.ty));
                  LODWORD(v42) = v132;
                  v152 = v42;
                  v133.matrix.ty = (float)v42;
                  break;
                case 0u:
                  goto LABEL_34;
                default:
                  v132 = (int)(float)((float)(v133.matrix.ty
                                            - (float)-(float)((float)(this->frameHeight * (float)0.075000003)
                                                            - this->frameHeight))
                                    - (float)((float)(swf_safeFrame.valueFloat * (float)VirtualHeight)
                                            - (float)VirtualHeight));
                  LODWORD(v42) = v132;
                  v150 = v42;
                  v133.matrix.ty = (float)v42;
                  break;
              }
              switch ( followBorder )
              {
                case 1u:
                  goto LABEL_46;
                case 2u:
                  goto LABEL_47;
                case 3u:
                  goto LABEL_45;
                case 4u:
                  goto LABEL_46;
                case 5u:
                  goto LABEL_47;
                case 6u:
                  goto LABEL_45;
                case 7u:
LABEL_46:
                  v132 = (int)(float)((float)((float)VirtualWidth * (float)0.5)
                                    - (float)((float)(this->frameWidth * (float)0.5) - v133.matrix.tx));
                  LODWORD(v42) = v132;
                  v153 = v42;
                  v133.matrix.tx = (float)v42;
                  break;
                case 0u:
LABEL_45:
                  v132 = (int)(float)((float)(swf_safeFrame.valueFloat * (float)VirtualWidth)
                                    - (float)((float)(this->frameWidth * (float)0.075000003) - v133.matrix.tx));
                  LODWORD(v42) = v132;
                  v151 = v42;
                  v133.matrix.tx = (float)v42;
                  break;
                default:
LABEL_47:
                  v132 = (int)(float)((float)(v133.matrix.tx
                                            - (float)-(float)((float)(this->frameWidth * (float)0.075000003)
                                                            - this->frameWidth))
                                    - (float)((float)(swf_safeFrame.valueFloat * (float)VirtualWidth)
                                            - (float)VirtualWidth));
                  LODWORD(v42) = v132;
                  v149 = v42;
                  v133.matrix.tx = (float)v42;
                  break;
              }
            }
LABEL_49:
            p_str = &v14->spriteInstance->name.str;
            if ( **p_str == 95 )
            {
              v46 = *p_str;
              v47 = (float)(this->frameWidth * (float)valueFloat);
              v48 = (float)((float)valueFloat * this->frameHeight);
              p_matrix = (int)&v14->spriteInstance->name;
              if ( idStr::Icmp(s1: v46, s2: "_fullScreen") == 0 )
              {
                v133.matrix.tx = v14->matrix.tx * renderState->matrix.xx;
                v133.matrix.ty = v14->matrix.ty * renderState->matrix.yy;
                v49 = idRenderModelGui::GetVirtualWidth(this: gui);
                v50 = (float)(idRenderModelGui::GetVirtualHeight(this: gui) / this->frameHeight);
                v133.matrix.xx = (float)v49 / this->frameWidth;
                v133.matrix.yy = v50;
              }
              if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v139) != 0 )
              {
                if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v140) != 0 )
                {
                  if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v143) != 0 )
                  {
                    if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: "_left") != 0 )
                    {
                      if ( idStr::Find(
                             searchIn: v14->spriteInstance->name.str,
                             searchFor: v138,
                             casesensitive: false,
                             start: 0,
                             end: -1) < 0 )
                      {
                        if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v145) != 0 )
                        {
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v147) == 0 )
                          {
                            v80 = idRenderModelGui::GetVirtualHeight(this: gui);
                            v81 = spriteInstance->yOffset;
                            xOffset = spriteInstance->xOffset;
                            v133.matrix.ty = -(float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                            * renderState->matrix.yy)
                                                    - (float)v80);
                            v83 = v14->spriteInstance;
                            v83->xOffset = xOffset;
                            v83->yOffset = v81;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v144) == 0 )
                          {
                            v84 = idRenderModelGui::GetVirtualHeight(this: gui);
                            v85 = spriteInstance->yOffset;
                            v86 = spriteInstance->xOffset;
                            v133.matrix.ty = -(float)((float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                                    + (float)v48)
                                                            * renderState->matrix.yy)
                                                    - (float)v84);
                            v87 = v14->spriteInstance;
                            v87->xOffset = v86;
                            v87->yOffset = v85;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v142) == 0 )
                          {
                            v88 = idRenderModelGui::GetVirtualWidth(this: gui);
                            yy = renderState->matrix.yy;
                            v90 = spriteInstance->yOffset;
                            v91 = spriteInstance->xOffset;
                            v133.matrix.tx = -(float)((float)((float)((float)(this->frameWidth - v14->matrix.tx)
                                                                    + (float)v47)
                                                            * renderState->matrix.xx)
                                                    - (float)v88);
                            v133.matrix.ty = (float)(v14->matrix.ty + (float)v48) * (float)yy;
                            v92 = v14->spriteInstance;
                            v92->xOffset = v91;
                            v92->yOffset = v90;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v146) == 0 )
                          {
                            v93 = renderState->matrix.xx;
                            v94 = v133.matrix.tx;
                            v95 = idRenderModelGui::GetVirtualWidth(this: gui);
                            v96 = spriteInstance->xOffset;
                            v97 = spriteInstance->yOffset;
                            v98 = (float)-(float)((float)((float)((float)(this->frameWidth - v14->matrix.tx) + (float)v47)
                                                        * (float)v93)
                                                - (float)v95);
                            v133.matrix.tx = -(float)((float)((float)((float)(this->frameWidth - v14->matrix.tx)
                                                                    + (float)v47)
                                                            * (float)v93)
                                                    - (float)v95);
                            v99 = v14->spriteInstance;
                            v99->yOffset = v97;
                            v99->xOffset = (float)((float)((float)v98 - (float)v94) / (float)v93) + (float)v96;
                            goto LABEL_85;
                          }
                          if ( idStr::Find(
                                 searchIn: v14->spriteInstance->name.str,
                                 searchFor: v135,
                                 casesensitive: true,
                                 start: 0,
                                 end: -1) >= 0 )
                          {
                            v100 = renderState->matrix.xx;
                            v101 = v133.matrix.tx;
                            v102 = idRenderModelGui::GetVirtualWidth(this: gui);
                            v103 = spriteInstance->xOffset;
                            v104 = spriteInstance->yOffset;
                            v105 = (float)-(float)((float)((float)(this->frameWidth - v14->matrix.tx) * (float)v100)
                                                 - (float)v102);
                            v133.matrix.tx = -(float)((float)((float)(this->frameWidth - v14->matrix.tx) * (float)v100)
                                                    - (float)v102);
                            v106 = v14->spriteInstance;
                            v106->yOffset = v104;
                            v106->xOffset = (float)((float)((float)v105 - (float)v101) / (float)v100) + (float)v103;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v141) == 0 )
                          {
                            v133.matrix.tx = -(float)((float)((float)((float)(this->frameWidth - v14->matrix.tx)
                                                                    + (float)v47)
                                                            * renderState->matrix.xx)
                                                    - idRenderModelGui::GetVirtualWidth(this: gui));
                            v107 = idRenderModelGui::GetVirtualHeight(this: gui);
                            v108 = spriteInstance->yOffset;
                            v109 = spriteInstance->xOffset;
                            v133.matrix.ty = -(float)((float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                                    + (float)v48)
                                                            * renderState->matrix.yy)
                                                    - (float)v107);
                            v110 = v14->spriteInstance;
                            v110->xOffset = v109;
                            v110->yOffset = v108;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: v136) == 0 )
                          {
                            v133.matrix.tx = v14->matrix.tx * renderState->matrix.xx;
                            v111 = spriteInstance->yOffset;
                            v112 = spriteInstance->xOffset;
                            v133.matrix.ty = v14->matrix.ty * renderState->matrix.yy;
                            v113 = v14->spriteInstance;
                            v113->xOffset = v112;
                            v113->yOffset = v111;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: "_absTopRight") == 0 )
                          {
                            v114 = idRenderModelGui::GetVirtualWidth(this: gui);
                            v115 = renderState->matrix.yy;
                            v116 = spriteInstance->yOffset;
                            v117 = spriteInstance->xOffset;
                            v133.matrix.tx = -(float)((float)((float)(this->frameWidth - v14->matrix.tx)
                                                            * renderState->matrix.xx)
                                                    - (float)v114);
                            v133.matrix.ty = v14->matrix.ty * (float)v115;
                            v118 = v14->spriteInstance;
                            v118->xOffset = v117;
                            v118->yOffset = v116;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: "_absBottomLeft") == 0 )
                          {
                            v133.matrix.tx = v14->matrix.tx * renderState->matrix.xx;
                            v119 = idRenderModelGui::GetVirtualHeight(this: gui);
                            v120 = spriteInstance->yOffset;
                            v121 = spriteInstance->xOffset;
                            v133.matrix.ty = -(float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                            * renderState->matrix.yy)
                                                    - (float)v119);
                            v122 = v14->spriteInstance;
                            v122->xOffset = v121;
                            v122->yOffset = v120;
                            goto LABEL_85;
                          }
                          if ( idStr::Icmp(s1: v14->spriteInstance->name.str, s2: "_absBottomRight") != 0 )
                            goto LABEL_85;
                          v133.matrix.tx = -(float)((float)((float)(this->frameWidth - v14->matrix.tx)
                                                          * renderState->matrix.xx)
                                                  - idRenderModelGui::GetVirtualWidth(this: gui));
                          v123 = idRenderModelGui::GetVirtualHeight(this: gui);
                          v124 = spriteInstance->yOffset;
                          v77 = spriteInstance->xOffset;
                          v133.matrix.ty = -(float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                          * renderState->matrix.yy)
                                                  - (float)v123);
                          v79 = v14->spriteInstance;
                          v79->yOffset = v124;
                        }
                        else
                        {
                          v72 = v133.matrix.ty;
                          v73 = (float)((float)(v14->matrix.tx + (float)v47) * renderState->matrix.xx);
                          v74 = (float)((float)((float)((float)(v14->matrix.tx + (float)v47) * renderState->matrix.xx)
                                              - v133.matrix.tx)
                                      / renderState->matrix.xx);
                          v71 = renderState->matrix.yy;
                          v133.matrix.tx = v73;
                          v75 = idRenderModelGui::GetVirtualHeight(this: gui);
                          v76 = spriteInstance->yOffset;
                          v77 = (float)((float)v74 + spriteInstance->xOffset);
                          v78 = (float)-(float)((float)((float)((float)(this->frameHeight - v14->matrix.ty) + (float)v48)
                                                      * (float)v71)
                                              - (float)v75);
                          v133.matrix.ty = -(float)((float)((float)((float)(this->frameHeight - v14->matrix.ty)
                                                                  + (float)v48)
                                                          * (float)v71)
                                                  - (float)v75);
                          v79 = v14->spriteInstance;
                          v79->yOffset = (float)v76 + (float)((float)((float)v78 - (float)v72) / (float)v71);
                        }
                        v79->xOffset = v77;
                        goto LABEL_85;
                      }
                      v66 = renderState->matrix.xx;
                      v67 = (float)(v14->matrix.tx * renderState->matrix.xx);
                      v68 = v133.matrix.tx;
                      v133.matrix.tx = v14->matrix.tx * renderState->matrix.xx;
                      v69 = spriteInstance->xOffset;
                      v70 = v14->spriteInstance;
                      v70->yOffset = spriteInstance->yOffset;
                      v70->xOffset = (float)((float)((float)v67 - (float)v68) / (float)v66) + (float)v69;
                    }
                    else
                    {
                      v60 = renderState->matrix.xx;
                      v61 = v133.matrix.tx;
                      v62 = spriteInstance->xOffset;
                      v63 = spriteInstance->yOffset;
                      v64 = (float)((float)(v14->matrix.tx + (float)v47) * renderState->matrix.xx);
                      v133.matrix.tx = (float)(v14->matrix.tx + (float)v47) * renderState->matrix.xx;
                      v65 = v14->spriteInstance;
                      v65->yOffset = v63;
                      v65->xOffset = (float)((float)((float)v64 - (float)v61) / (float)v60) + (float)v62;
                    }
                  }
                  else
                  {
                    v56 = renderState->matrix.yy;
                    v57 = spriteInstance->yOffset;
                    v58 = spriteInstance->xOffset;
                    v133.matrix.tx = (float)(v14->matrix.tx + (float)v47) * renderState->matrix.xx;
                    v133.matrix.ty = (float)(v14->matrix.ty + (float)v48) * (float)v56;
                    v59 = v14->spriteInstance;
                    v59->xOffset = v58;
                    v59->yOffset = v57;
                  }
                }
                else
                {
                  v53 = spriteInstance->yOffset;
                  v54 = spriteInstance->xOffset;
                  v133.matrix.ty = (float)(v14->matrix.ty + (float)v48) * renderState->matrix.yy;
                  v55 = v14->spriteInstance;
                  v55->xOffset = v54;
                  v55->yOffset = v53;
                }
              }
              else
              {
                v133.matrix.ty = v14->matrix.ty * renderState->matrix.yy;
                v51 = spriteInstance->yOffset;
                v52 = v14->spriteInstance;
                v52->xOffset = spriteInstance->xOffset;
                v52->yOffset = v51;
              }
            }
LABEL_85:
            str = v14->spriteInstance->name.str;
            v126 = *(unsigned __int8 *)str;
            p_matrix = (int)str;
            if ( v126 == 95
              && (v127 = *((unsigned __int8 *)str + 1), p_matrix = (int)str, v127 == 95)
              && (p_matrix = (int)str, idStr::Cmp(s1: str, s2: v137) == 0) )
            {
              idSWF::RenderRadial(
                this,
                gui,
                spriteInstance: v14->spriteInstance,
                renderState: &v133,
                time,
                isSplitscreen);
            }
            else
            {
              idSWF::RenderSprite(
                this,
                gui,
                spriteInstance: v14->spriteInstance,
                renderState: &v133,
                time,
                isSplitscreen);
            }
          }
        }
LABEL_96:
        ++v12;
        v128 = spriteInstance->displayList.num;
        ++v134;
      }
      while ( v134 < v128 );
    }
    v129 = 0;
    if ( v155.num > 0 )
    {
      v130 = 0;
      do
      {
        idSWF::RenderMask(
          this,
          gui,
          mask: (const swfDisplayEntry_t *)v155.list[v130],
          renderState,
          material: this->guiStencilDecr);
        ++v129;
        ++v130;
      }
      while ( v129 < v155.num );
    }
    if ( (v155.listStatic == 0 || v155.listStatic == 2) && v155.list != nullptr )
      idMem::Free(this: &mem, ptr: v155.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$228233
// EA  : 0x82783F68
// RVA : 0x00783F68
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_228233()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1584 + 320));
}


// ========================================================================
// ?Render@idSWF@@QAAXPAVidRenderModelGui@@H_N@Z
// EA  : 0x82783F98
// RVA : 0x00783F98
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::Render(idSWF *this, idRenderModelGui *gui, int time, bool isSplitscreen, const char *a5)
{
  unsigned __int64 v9; // r6
  bool v10; // r4
  idSWFScriptVar::swfScriptVarValue_t *v11; // r29
  __int64 v12; // r6 OVERLAPPED
  double valueFloat; // fp12
  int lastRenderTime; // r11
  int v15; // r11
  __int64 v16; // r10
  char *v17; // r7
  int i; // r29
  double VirtualWidth; // fp27
  double VirtualHeight; // fp1
  BOOL automaticRescale; // r8
  double v22; // fp26
  double frameWidth; // fp13
  double frameHeight; // fp11
  double v27; // fp13
  int v28; // r10
  int v29; // r9
  int v30; // r8
  int v31; // r7
  unsigned __int64 v32; // r6
  const idMaterial *v33; // r4
  double v34; // fp29
  double v35; // fp28
  int v36; // r9
  int v37; // r8
  int v38; // r7
  int v39; // r6
  int v40; // r5
  const idMaterial *v41; // r4
  int v42; // r9
  int v43; // r8
  int v44; // r7
  int v45; // r6
  int v46; // r5
  const idMaterial *v47; // r4
  int v48; // [sp+8h] [-138h]
  int v49; // [sp+8h] [-138h]
  int v50; // [sp+8h] [-138h]
  int v51; // [sp+Ch] [-134h]
  int v52; // [sp+Ch] [-134h]
  int v53; // [sp+Ch] [-134h]
  int v54; // [sp+10h] [-130h]
  int v55; // [sp+10h] [-130h]
  int v56; // [sp+10h] [-130h]
  int v57; // [sp+14h] [-12Ch]
  int v58; // [sp+14h] [-12Ch]
  int v59; // [sp+14h] [-12Ch]
  int v60; // [sp+18h] [-128h]
  int v61; // [sp+18h] [-128h]
  int v62; // [sp+18h] [-128h]
  int v63; // [sp+1Ch] [-124h]
  int v64; // [sp+1Ch] [-124h]
  int v65; // [sp+1Ch] [-124h]
  int v66; // [sp+20h] [-120h]
  int v67; // [sp+20h] [-120h]
  int v68; // [sp+20h] [-120h]
  int v69; // [sp+24h] [-11Ch]
  int v70; // [sp+24h] [-11Ch]
  int v71; // [sp+24h] [-11Ch]
  int v72; // [sp+28h] [-118h]
  int v73; // [sp+28h] [-118h]
  int v74; // [sp+28h] [-118h]
  int v75; // [sp+2Ch] [-114h]
  int v76; // [sp+2Ch] [-114h]
  int v77; // [sp+2Ch] [-114h]
  int v78; // [sp+30h] [-110h]
  int v79; // [sp+30h] [-110h]
  int v80; // [sp+30h] [-110h]
  int v81; // [sp+34h] [-10Ch]
  int v82; // [sp+34h] [-10Ch]
  int v83; // [sp+34h] [-10Ch]
  int v84; // [sp+38h] [-108h]
  int v85; // [sp+38h] [-108h]
  int v86; // [sp+38h] [-108h]
  int v87; // [sp+3Ch] [-104h]
  int v88; // [sp+3Ch] [-104h]
  int v89; // [sp+3Ch] [-104h]
  int v90; // [sp+40h] [-100h]
  int v91; // [sp+40h] [-100h]
  int v92; // [sp+40h] [-100h]
  int v93; // [sp+44h] [-FCh]
  int v94; // [sp+44h] [-FCh]
  int v95; // [sp+44h] [-FCh]
  int v96; // [sp+48h] [-F8h]
  int v97; // [sp+48h] [-F8h]
  int v98; // [sp+48h] [-F8h]
  int v99; // [sp+4Ch] [-F4h]
  int v100; // [sp+4Ch] [-F4h]
  int v101; // [sp+4Ch] [-F4h]
  int v102; // [sp+50h] [-F0h]
  int v103; // [sp+50h] [-F0h]
  int v104; // [sp+50h] [-F0h]
  int v105; // [sp+54h] [-ECh]
  int v106; // [sp+54h] [-ECh]
  int v107; // [sp+54h] [-ECh]
  int v108; // [sp+58h] [-E8h]
  int v109; // [sp+58h] [-E8h]
  int v110; // [sp+58h] [-E8h]
  idPLogScope v111; // [sp+60h] [-E0h] BYREF
  idSWFScriptVar v112[3]; // [sp+68h] [-D8h] BYREF
  swfRenderState_t v113; // [sp+80h] [-C0h] BYREF

  LODWORD(v9) = "idSWF::Render";
  HIDWORD(v9) = 1;
  idPLogScope::idPLogScope(this: &v111, pl: &pLog, gMask: v9, label: a5);
  if ( this->frameRate != 0 && this->isActive )
  {
    if ( swf_stopat.valueInteger > 0 && this->mainspriteInstance->currentFrame == swf_stopat.valueInteger )
      idCVar::SetFloat(this: &swf_timescale, newValue: 0.0, force: v10);
    if ( (unsigned __int8)idSWF::LoadAtlasImage(this, force: false) != 0 )
    {
      v11 = (idSWFScriptVar::swfScriptVarValue_t *)Sys_Milliseconds();
      idSWFScriptVar::idSWFScriptVar(this: v112, i: v11);
      idSWFScriptObject::Set(this: this->globals, name: "currentTime", value: v112);
      idSWFScriptVar::Free(this: v112);
      if ( this->paused )
        this->lastRenderTime = (int)v11;
      valueFloat = swf_timescale.valueFloat;
      if ( swf_timescale.valueFloat > 0.0 )
      {
        lastRenderTime = this->lastRenderTime;
        if ( lastRenderTime != 0 )
        {
          HIDWORD(v16) = this->frameRate;
          v17 = (char *)v11 - lastRenderTime;
          LODWORD(v12) = HIDWORD(v16);
          LODWORD(v16) = (int)(float)((float)((float)((float)((float)v12 * (float)0.00390625) * swf_timescale.valueFloat)
                                            * (float)*(__int64 *)((char *)&v12 - 4))
                                    * (float)0.001);
          v112[1] = (idSWFScriptVar)v16;
          this->lastRenderTime = (int)(float)((float)((float)((float)1000.0
                                                            / (float)((float)((float)v12 * (float)0.00390625)
                                                                    * swf_timescale.valueFloat))
                                                    * (float)v16)
                                            + (float)__SPAIR64__(&unk_82150000, lastRenderTime));
          v15 = (int)(float)((float)((float)((float)((float)v12 * (float)0.00390625) * (float)valueFloat)
                                   * (float)*(__int64 *)((char *)&v12 - 4))
                           * (float)0.001);
          if ( (int)v16 > 10 )
            v15 = 10;
        }
        else
        {
          this->lastRenderTime = (int)v11;
          v15 = 1;
        }
        if ( v15 > 0 )
        {
          for ( i = v15; i != 0; --i )
          {
            idSWFSpriteInstance::Run(this: this->mainspriteInstance);
            idSWFSpriteInstance::RunActions(this: this->mainspriteInstance);
          }
        }
      }
      VirtualWidth = idRenderModelGui::GetVirtualWidth(this: gui);
      VirtualHeight = idRenderModelGui::GetVirtualHeight(this: gui);
      automaticRescale = this->automaticRescale;
      v113.matrix.xy = 0.0;
      v113.matrix.yx = 0.0;
      v22 = VirtualHeight;
      v113.matrix.tx = 0.0;
      memset(&v113.material, 0, 17);
      v113.matrix.xx = 1.0;
      v113.matrix.yy = 1.0;
      v113.matrix.ty = 0.0;
      v113.cxf.mul.x = 1.0;
      v113.cxf.mul.y = 1.0;
      v113.cxf.mul.z = 1.0;
      v113.cxf.mul.w = 1.0;
      v113.cxf.add.x = 0.0;
      v113.cxf.add.y = 0.0;
      v113.cxf.add.z = 0.0;
      v113.cxf.add.w = 0.0;
      v113.ratio = 0.0;
      if ( automaticRescale )
      {
        frameWidth = this->frameWidth;
        frameHeight = this->frameHeight;
        _FP0 = (float)((float)((float)VirtualHeight / this->frameHeight) * this->swfScale);
        if ( this->crop )
        {
          _FP10 = (float)((float)((float)((float)VirtualWidth / this->frameWidth) * this->swfScale)
                        - (float)((float)((float)VirtualHeight / this->frameHeight) * this->swfScale));
          __asm { fsel      f0, f10, f12, f0 }
        }
        if ( isSplitscreen )
          v113.matrix.xx = (float)_FP0 * (float)0.5;
        else
          v113.matrix.xx = _FP0;
        v113.matrix.yy = _FP0;
        if ( isSplitscreen )
          v27 = (float)((float)-(float)((float)((float)((float)_FP0 * (float)0.5) * (float)frameWidth)
                                      - (float)VirtualWidth)
                      * (float)0.5);
        else
          v27 = (float)((float)-(float)((float)((float)frameWidth * (float)_FP0) - (float)VirtualWidth) * (float)0.5);
        v113.matrix.tx = v27;
        this->renderBorder = (float)v27 / (float)_FP0;
        v113.matrix.ty = (float)-(float)((float)((float)frameHeight * (float)_FP0) - (float)VirtualHeight) * (float)0.5;
      }
      idSWF::RenderSprite(this, gui, spriteInstance: this->mainspriteInstance, renderState: &v113, time, isSplitscreen);
      if ( this->blackbars )
      {
        v34 = (float)(v113.matrix.tx + (float)0.5);
        v35 = (float)(v113.matrix.ty + (float)0.5);
        if ( v34 > 0.0 )
        {
          gui->currentVertexColor = -16777216;
          idRenderModelGui::DrawStretchPic(
            this: gui,
            x: 0.0,
            y: 0.0,
            w: v34,
            h: v22,
            s1: 0.0,
            t1: 0.0,
            s2: 1.0,
            t2: 1.0,
            material: v33,
            a11: SHIDWORD(v32),
            a12: v32,
            a13: v31,
            a14: v30,
            a15: v29,
            a16: v28,
            a17: v48,
            a18: v51,
            a19: v54,
            a20: v57,
            a21: v60,
            a22: v63,
            a23: v66,
            a24: v69,
            a25: v72,
            a26: v75,
            a27: v78,
            a28: v81,
            a29: v84,
            a30: v87,
            a31: v90,
            a32: v93,
            a33: v96,
            a34: v99,
            a35: v102,
            a36: v105,
            a37: v108,
            a38: this->white);
          idRenderModelGui::DrawStretchPic(
            this: gui,
            x: (float)((float)VirtualWidth - (float)v34),
            y: 0.0,
            w: v34,
            h: v22,
            s1: 0.0,
            t1: 0.0,
            s2: 1.0,
            t2: 1.0,
            material: v41,
            a11: v40,
            a12: v39,
            a13: v38,
            a14: v37,
            a15: v36,
            a16: (int)this->white,
            a17: v49,
            a18: v52,
            a19: v55,
            a20: v58,
            a21: v61,
            a22: v64,
            a23: v67,
            a24: v70,
            a25: v73,
            a26: v76,
            a27: v79,
            a28: v82,
            a29: v85,
            a30: v88,
            a31: v91,
            a32: v94,
            a33: v97,
            a34: v100,
            a35: v103,
            a36: v106,
            a37: v109,
            a38: this->white);
        }
        if ( v35 > 0.0 )
        {
          gui->currentVertexColor = -16777216;
          idRenderModelGui::DrawStretchPic(
            this: gui,
            x: 0.0,
            y: 0.0,
            w: VirtualWidth,
            h: v35,
            s1: 0.0,
            t1: 0.0,
            s2: 1.0,
            t2: 1.0,
            material: v33,
            a11: SHIDWORD(v32),
            a12: v32,
            a13: v31,
            a14: v30,
            a15: v29,
            a16: v28,
            a17: v48,
            a18: v51,
            a19: v54,
            a20: v57,
            a21: v60,
            a22: v63,
            a23: v66,
            a24: v69,
            a25: v72,
            a26: v75,
            a27: v78,
            a28: v81,
            a29: v84,
            a30: v87,
            a31: v90,
            a32: v93,
            a33: v96,
            a34: v99,
            a35: v102,
            a36: v105,
            a37: v108,
            a38: this->white);
          idRenderModelGui::DrawStretchPic(
            this: gui,
            x: 0.0,
            y: (float)((float)v22 - (float)v35),
            w: VirtualWidth,
            h: v35,
            s1: 0.0,
            t1: 0.0,
            s2: 1.0,
            t2: 1.0,
            material: v47,
            a11: v46,
            a12: v45,
            a13: v44,
            a14: v43,
            a15: v42,
            a16: (int)this->white,
            a17: v50,
            a18: v53,
            a19: v56,
            a20: v59,
            a21: v62,
            a22: v65,
            a23: v68,
            a24: v71,
            a25: v74,
            a26: v77,
            a27: v80,
            a28: v83,
            a29: v86,
            a30: v89,
            a31: v92,
            a32: v95,
            a33: v98,
            a34: v101,
            a35: v104,
            a36: v107,
            a37: v110,
            a38: this->white);
        }
      }
      idRenderModelGui::SetGLState(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v32);
      if ( swf_debugOrphans.valueInteger != 0 )
        idLib::Printf(
          fmt: "SWF: Sprite Orphans %2d %2d %2d   Text Orphans %2d %2d %2d\n",
          this->c_SpriteInstanceAdoptions,
          this->orphanedSprites.num,
          this->c_SpriteInstanceOrphans,
          this->c_TextInstanceAdoptions,
          this->orphanedTexts.num,
          this->c_TextInstanceOrphans);
      idSWF::PurgeOrphanage(this);
    }
  }
  idPLogScope::~idPLogScope(this: &v111);
}


// ========================================================================
// __unwind$228632
// EA  : 0x82784424
// RVA : 0x00784424
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_228632()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$228633
// EA  : 0x8278444C
// RVA : 0x0078444C
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void _unwind_228633()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 320 + 104));
}


// ========================================================================
// `dynamic initializer for 'swf_timescale''
// EA  : 0x83341A40
// RVA : 0x01341A40
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_timescale__()
{
  idCVar::idCVar(
    this: &swf_timescale,
    name: "swf_timescale",
    value: "1",
    flags: 4,
    description: "timescale for swf files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_timescale__);
}


// ========================================================================
// `dynamic initializer for 'swf_stopat''
// EA  : 0x83341A98
// RVA : 0x01341A98
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_stopat__()
{
  idCVar::idCVar(
    this: &swf_stopat,
    name: "swf_stopat",
    value: "0",
    flags: 4,
    description: "stop at a specific frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_stopat__);
}


// ========================================================================
// `dynamic initializer for 'swf_safeFrame''
// EA  : 0x83341AF0
// RVA : 0x01341AF0
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_safeFrame__()
{
  idCVar::idCVar(
    this: &swf_safeFrame,
    name: "swf_safeFrame",
    value: "0.075",
    flags: 65540,
    description: "space between UI elements and screen edge",
    valueMin: 0.0,
    valueMax: 0.075000003,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_821F0000,
    a9: (int)&unk_821F0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_safeFrame__);
}


// ========================================================================
// `dynamic initializer for 'swf_forceAlpha''
// EA  : 0x83341B58
// RVA : 0x01341B58
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_forceAlpha__()
{
  idCVar::idCVar(
    this: &swf_forceAlpha,
    name: "swf_forceAlpha",
    value: "0",
    flags: 4,
    description: "force an alpha value on all elements, useful to show invisible animating elements",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821F0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_forceAlpha__);
}


// ========================================================================
// `dynamic initializer for 'swf_ignoreVisible''
// EA  : 0x83341BC0
// RVA : 0x01341BC0
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_ignoreVisible__()
{
  idCVar::idCVar(
    this: &swf_ignoreVisible,
    name: "swf_ignoreVisible",
    value: "0",
    flags: 0,
    description: "forces all elements to render, ignoring the visible flag",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_ignoreVisible__);
}


// ========================================================================
// `dynamic initializer for 'swf_debugOrphans''
// EA  : 0x83341C18
// RVA : 0x01341C18
// PDB : w:\tech5\engine\guis\swf\swf_render.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_debugOrphans__()
{
  idCVar::idCVar(
    this: &swf_debugOrphans,
    name: "swf_debugOrphans",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_debugOrphans__);
}

