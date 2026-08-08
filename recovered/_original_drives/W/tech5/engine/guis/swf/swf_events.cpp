
// ========================================================================
// ?HitTest@idSWF@@QAAPAVidSWFScriptObject@@PAVidSWFSpriteInstance@@ABUswfRenderState_t@@HHPAV2@@Z
// EA  : 0x8276FB58
// RVA : 0x0076FB58
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

idSWFScriptObject *__fastcall idSWF::HitTest(
        idSWF *this,
        idSWFSpriteInstance *spriteInstance,
        const swfRenderState_t *renderState,
        unsigned int x,
        unsigned int y,
        idSWFScriptObject *parentObject)
{
  idSWFSpriteInstance *parent; // r3
  swfDisplayEntry_t *DisplayEntry; // r3
  idSWFScriptObject *scriptObject; // r3
  const char *v16; // r28
  const char *v17; // r27
  double xOffset; // fp21
  double yOffset; // fp20
  idSWFScriptObject *v20; // r21
  int v21; // r14
  int v22; // r17
  swfDisplayEntry_t *v23; // r30
  __int64 v24; // r10
  idSWFDictionaryEntry *DictionaryEntry; // r3
  idSWFDictionaryEntry *v26; // r29
  double xx; // fp11
  double yx; // fp10
  double tx; // fp8
  double ty; // fp7
  double v31; // fp3
  double xy; // fp2
  double v33; // fp6
  double v34; // fp0
  double v35; // fp13
  double v36; // fp5
  double v37; // fp4
  double v38; // fp9
  double v39; // fp12
  double v40; // fp11
  double yy; // fp10
  double v42; // fp13
  double v43; // fp0
  swfDictType_t type; // r11
  idSWFScriptVar *v45; // r3
  idSWFScriptObject *v46; // r30
  idSWFScriptVar *v47; // r3
  bool v48; // r3
  char v49; // r11
  char v50; // r29
  idSWFShape *shape; // r26
  int v52; // r25
  int v53; // r27
  int v54; // r28
  idSWFShapeDrawFill *v55; // r29
  int v56; // r30
  double v57; // fp30
  idVec2 *list; // r10
  unsigned __int16 *v59; // r8
  float *v60; // r11
  float *v61; // r9
  float *v62; // r10
  double v63; // fp4
  double v64; // fp2
  double v65; // fp6
  double v66; // fp3
  double v67; // fp1
  double v68; // fp8
  double v69; // fp7
  double v70; // fp11
  double v71; // fp10
  idSWFScriptObject *v72; // r28
  idSWFTextInstance *textInstance; // r11
  float *p_x; // r30
  idSWFEditText *editText; // r29
  double TextLength; // fp1
  double v77; // fp0
  double v78; // fp10
  swfEditTextAlign_t align; // r11
  double v80; // fp26
  double v81; // fp30
  double v82; // fp0
  double v83; // fp13
  double v84; // fp28
  double v85; // fp29
  double v86; // fp27
  double v87; // fp25
  double v88; // fp2
  double v89; // fp29
  double v90; // fp0
  double v91; // fp4
  __int64 v92; // r10
  double v93; // fp23
  bool v94; // r11
  bool v95; // r11
  int v96; // [sp+50h] [-200h]
  idMat3 v97; // [sp+60h] [-1F0h] BYREF
  swfRenderState_t v98; // [sp+90h] [-1C0h] BYREF
  idMat3 v99; // [sp+E0h] [-170h] BYREF
  const char *v100; // [sp+104h] [-14Ch]
  const char *v101; // [sp+108h] [-148h]
  const char *v102; // [sp+10Ch] [-144h]
  unsigned __int64 v103; // [sp+110h] [-140h]
  idSWFScriptObject v104; // [sp+118h] [-138h] BYREF

  v96 = 0;
  parent = spriteInstance->parent;
  if ( parent != nullptr )
  {
    DisplayEntry = idSWFSpriteInstance::FindDisplayEntry(this: parent, depth: spriteInstance->depth);
    if ( (float)(DisplayEntry->cxf.add.w + DisplayEntry->cxf.mul.w) < 0.001 )
      return nullptr;
  }
  if ( !spriteInstance->isVisible )
    return nullptr;
  scriptObject = spriteInstance->scriptObject;
  v16 = "onRelease";
  v101 = "onRelease";
  v17 = "onPress";
  v102 = "onPress";
  if ( idSWFScriptObject::HasValidProperty(this: scriptObject, name: "onRelease")
    || idSWFScriptObject::HasValidProperty(this: spriteInstance->scriptObject, name: "onPress")
    || idSWFScriptObject::HasValidProperty(this: spriteInstance->scriptObject, name: "onRollOver")
    || idSWFScriptObject::HasValidProperty(this: spriteInstance->scriptObject, name: "onRollOut")
    || idSWFScriptObject::HasValidProperty(this: spriteInstance->scriptObject, name: "onDrag") )
  {
    parentObject = spriteInstance->scriptObject;
  }
  xOffset = spriteInstance->xOffset;
  yOffset = spriteInstance->yOffset;
  v20 = nullptr;
  v21 = 0;
  if ( spriteInstance->displayList.num > 0 )
  {
    v22 = 0;
    v100 = "_visible";
    while ( 1 )
    {
      v23 = &spriteInstance->displayList.list[v22];
      DictionaryEntry = idSWF::FindDictionaryEntry(this, characterID: v23->characterID);
      v26 = DictionaryEntry;
      if ( DictionaryEntry == nullptr )
        goto LABEL_59;
      v98.matrix.xx = 1.0;
      memset(&v98.material, 0, 17);
      v98.matrix.yy = 1.0;
      v98.matrix.xy = 0.0;
      v98.matrix.yx = 0.0;
      v98.matrix.tx = 0.0;
      v98.matrix.ty = 0.0;
      v98.ratio = 0.0;
      v98.cxf.mul.x = 1.0;
      *(_DWORD *)&v104.variables.granularity = &v23->matrix;
      v98.cxf.mul.y = 1.0;
      v98.cxf.mul.z = 1.0;
      v98.cxf.mul.w = 1.0;
      v98.cxf.add.x = 0.0;
      v98.cxf.add.y = 0.0;
      v98.cxf.add.z = 0.0;
      v98.cxf.add.w = 0.0;
      xx = renderState->matrix.xx;
      yx = renderState->matrix.yx;
      tx = renderState->matrix.tx;
      ty = renderState->matrix.ty;
      v31 = v23->matrix.xx;
      xy = v23->matrix.xy;
      v33 = (float)(renderState->matrix.yy * v23->matrix.yx);
      v34 = (float)(v23->matrix.yy * renderState->matrix.xy);
      v35 = (float)(v23->matrix.yy * renderState->matrix.yy);
      v36 = (float)((float)(v23->matrix.tx * renderState->matrix.xx) + (float)(v23->matrix.ty * renderState->matrix.xy));
      v37 = (float)((float)(v23->matrix.tx * renderState->matrix.yx) + (float)(v23->matrix.ty * renderState->matrix.yy));
      v38 = (float)((float)(v23->matrix.xx * renderState->matrix.xx) + (float)(renderState->matrix.xy * v23->matrix.yx));
      v39 = (float)((float)(renderState->matrix.yx * v23->matrix.xx) + (float)(renderState->matrix.yy * v23->matrix.yx));
      v98.matrix.xx = (float)(v23->matrix.xx * renderState->matrix.xx)
                    + (float)(renderState->matrix.xy * v23->matrix.yx);
      v98.matrix.yx = (float)((float)yx * (float)v31) + (float)v33;
      v40 = (float)((float)((float)xy * (float)xx) + (float)v34);
      v98.matrix.xy = v40;
      yy = (float)((float)((float)xy * (float)yx) + (float)v35);
      v98.matrix.yy = yy;
      v42 = (float)((float)v36 + (float)tx);
      v98.matrix.tx = (float)v36 + (float)tx;
      v43 = (float)((float)v37 + (float)ty);
      v98.matrix.ty = (float)v37 + (float)ty;
      v98.ratio = v23->ratio;
      type = DictionaryEntry->type;
      if ( DictionaryEntry->type == SWF_DICT_SPRITE )
      {
        v45 = (idSWFScriptVar *)idSWF::HitTest(
                                  this,
                                  spriteInstance: v23->spriteInstance,
                                  renderState: &v98,
                                  x,
                                  y,
                                  parentObject);
        v46 = (idSWFScriptObject *)v45;
        if ( v45 == nullptr
          || (v47 = idSWFScriptObject::Get(this: &v104, result: v45, name: v100),
              v96 |= 1u,
              v48 = idSWFScriptVar::ToBool(this: v47),
              v49 = 1,
              !v48) )
        {
          v49 = 0;
        }
        v50 = v49;
        if ( (v96 & 1) != 0 )
        {
          v96 &= ~1u;
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v104);
        }
        if ( v50 != 0 )
          v20 = v46;
      }
      else if ( type == SWF_DICT_SHAPE && parentObject != nullptr )
      {
        shape = DictionaryEntry->shape;
        v52 = 0;
        if ( shape->fillDraws.num > 0 )
        {
          v53 = 0;
          do
          {
            v54 = 0;
            v55 = &shape->fillDraws.list[v53];
            if ( v55->indices.num > 0 )
            {
              LODWORD(v24) = x;
              *(_QWORD *)&v104.variablesHash[3] = v24;
              v103 = __PAIR64__(x, y);
              v56 = 0;
              v57 = (float)v24;
              do
              {
                list = v55->startVerts.list;
                v59 = &v55->indices.list[v56];
                v60 = (float *)((char *)&list->x + __ROL4__(*v59, 3));
                v61 = (float *)((char *)&list->x + __ROL4__(v59[1], 3));
                v62 = (float *)((char *)&list->x + __ROL4__(v59[2], 3));
                v63 = (float)(v60[1] * (float)yy);
                v64 = *v60;
                v65 = (float)(v60[1] * (float)v40);
                v66 = (float)(v61[1] * (float)v40);
                v67 = (float)(v61[1] * (float)yy);
                v68 = *v61;
                v69 = (float)(v62[1] * (float)v40);
                v70 = *v62;
                v71 = (float)(v62[1] * (float)yy);
                v99.mat[0].z = 1.0;
                v99.mat[1].z = 1.0;
                v99.mat[2].z = 1.0;
                v99.mat[0].y = (float)((float)((float)((float)v64 * (float)v39) + (float)v63) + (float)v43)
                             + (float)yOffset;
                v99.mat[0].x = (float)((float)((float)((float)v64 * (float)v38) + (float)v65) + (float)v42)
                             + (float)xOffset;
                v99.mat[1].x = (float)((float)((float)((float)v68 * (float)v38) + (float)v66) + (float)v42)
                             + (float)xOffset;
                v99.mat[1].y = (float)((float)((float)((float)v68 * (float)v39) + (float)v67) + (float)v43)
                             + (float)yOffset;
                v99.mat[2].x = (float)((float)((float)((float)v70 * (float)v38) + (float)v69) + (float)v42)
                             + (float)xOffset;
                v99.mat[2].y = (float)((float)((float)((float)v70 * (float)v39) + (float)v71) + (float)v43)
                             + (float)yOffset;
                idMat3::InverseSelf(this: &v99);
                HIDWORD(v24) = (float)((float)((float)(v99.mat[0].y * (float)v57)
                                             + (float)(v99.mat[1].y * (float)__SPAIR64__(x, y)))
                                     + v99.mat[2].y) > 0.0;
                if ( (float)((float)((float)(v99.mat[0].x * (float)v57)
                                   + (float)(v99.mat[1].x * (float)__SPAIR64__(x, y)))
                           + v99.mat[2].x) > 0.0 == HIDWORD(v24)
                  && (float)((float)((float)(v99.mat[0].x * (float)v57)
                                   + (float)(v99.mat[1].x * (float)__SPAIR64__(x, y)))
                           + v99.mat[2].x) > 0.0 == (float)((float)((float)(v99.mat[0].z * (float)v57)
                                                                  + (float)(v99.mat[1].z * (float)__SPAIR64__(x, y)))
                                                          + v99.mat[2].z) > 0.0 )
                {
                  v20 = parentObject;
                }
                v54 += 3;
                v43 = v98.matrix.ty;
                v56 += 3;
                v42 = v98.matrix.tx;
                v39 = v98.matrix.yx;
                v40 = v98.matrix.xy;
                yy = v98.matrix.yy;
                v38 = v98.matrix.xx;
              }
              while ( v54 < v55->indices.num );
            }
            ++v52;
            ++v53;
          }
          while ( v52 < shape->fillDraws.num );
        }
      }
      else
      {
        if ( type != SWF_DICT_EDITTEXT )
          goto LABEL_59;
        if ( idSWFScriptObject::HasProperty(this: v23->textInstance->scriptObject, name: v16)
          || idSWFScriptObject::HasProperty(this: v23->textInstance->scriptObject, name: v17) )
        {
          v72 = v23->textInstance->scriptObject;
        }
        else
        {
          if ( parentObject == nullptr )
            goto LABEL_59;
          v72 = parentObject;
        }
        if ( v72 != nullptr )
        {
          textInstance = v23->textInstance;
          if ( textInstance->text.len != 0 )
          {
            p_x = &v26->edittext->bounds.tl.x;
            editText = textInstance->editText;
            TextLength = idSWFTextInstance::GetTextLength(this: textInstance);
            v77 = 0.0;
            v78 = (float)((float)__fabs((float)(p_x[2] - *p_x)) - (float)TextLength);
            if ( sys_langJapanese.valueInteger != 0 )
              v77 = 3.0;
            align = editText->align;
            if ( align != SWF_ET_ALIGN_LEFT )
            {
              if ( align == SWF_ET_ALIGN_RIGHT )
              {
                v83 = (float)((float)((float)((float)(p_x[2] + spriteInstance->xOffset) * v98.matrix.xx)
                                    + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.xy))
                            + v98.matrix.tx);
                v86 = (float)((float)((float)((float)(p_x[2] + spriteInstance->xOffset) * v98.matrix.xx)
                                    + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.xy))
                            + v98.matrix.tx);
                v80 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.yy)
                                    + (float)(v98.matrix.yx
                                            * (float)((float)(spriteInstance->xOffset + (float)v78) + *p_x)))
                            + v98.matrix.ty);
                v84 = (float)((float)((float)((float)((float)(spriteInstance->xOffset + (float)v78) + *p_x)
                                            * v98.matrix.xx)
                                    + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.xy))
                            + v98.matrix.tx);
                v81 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.yy)
                                    + (float)(v98.matrix.yx
                                            * (float)((float)(spriteInstance->xOffset + (float)v78) + *p_x)))
                            + v98.matrix.ty);
                v85 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.yy)
                                    + (float)(v98.matrix.yx * (float)(p_x[2] + spriteInstance->xOffset)))
                            + v98.matrix.ty);
                v87 = (float)((float)((float)((float)((float)(spriteInstance->xOffset + (float)v78) + *p_x)
                                            * v98.matrix.xx)
                                    + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.xy))
                            + v98.matrix.tx);
                v82 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                            * v98.matrix.yy)
                                    + (float)(v98.matrix.yx * (float)(p_x[2] + spriteInstance->xOffset)))
                            + v98.matrix.ty);
              }
              else
              {
                if ( align == SWF_ET_ALIGN_CENTER )
                {
                  v88 = (float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset);
                  v89 = (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset) * v98.matrix.xy);
                  v91 = (float)((float)(v98.matrix.xx
                                      * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                              + (float)(spriteInstance->xOffset + p_x[2]))
                                                      * (float)0.5)
                                              + (float)((float)TextLength * (float)0.5)))
                              + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset) * v98.matrix.xy));
                  v90 = (float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset);
                  v84 = (float)((float)((float)(v98.matrix.xx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      - (float)((float)TextLength * (float)0.5)))
                                      + (float)((float)v90 * v98.matrix.xy))
                              + v98.matrix.tx);
                  v83 = (float)((float)((float)(v98.matrix.xx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      + (float)((float)TextLength * (float)0.5)))
                                      + (float)v89)
                              + v98.matrix.tx);
                  v87 = (float)((float)((float)(v98.matrix.xx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      - (float)((float)TextLength * (float)0.5)))
                                      + (float)((float)v88 * v98.matrix.xy))
                              + v98.matrix.tx);
                  v85 = (float)((float)((float)((float)v88 * v98.matrix.yy)
                                      + (float)(v98.matrix.yx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      + (float)((float)TextLength * (float)0.5))))
                              + v98.matrix.ty);
                  v81 = (float)((float)((float)((float)v90 * v98.matrix.yy)
                                      + (float)(v98.matrix.yx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      - (float)((float)TextLength * (float)0.5))))
                              + v98.matrix.ty);
                  v82 = (float)((float)((float)((float)v90 * v98.matrix.yy)
                                      + (float)(v98.matrix.yx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      + (float)((float)TextLength * (float)0.5))))
                              + v98.matrix.ty);
                  v80 = (float)((float)((float)((float)v88 * v98.matrix.yy)
                                      + (float)(v98.matrix.yx
                                              * (float)((float)((float)((float)(spriteInstance->xOffset + *p_x)
                                                                      + (float)(spriteInstance->xOffset + p_x[2]))
                                                              * (float)0.5)
                                                      - (float)((float)TextLength * (float)0.5))))
                              + v98.matrix.ty);
                }
                else
                {
                  v91 = (float)((float)((float)(p_x[2] + spriteInstance->xOffset) * v98.matrix.xx)
                              + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset) * v98.matrix.xy));
                  v81 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.yy)
                                      + (float)(v98.matrix.yx * (float)(spriteInstance->xOffset + *p_x)))
                              + v98.matrix.ty);
                  v85 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.yy)
                                      + (float)(v98.matrix.yx * (float)(p_x[2] + spriteInstance->xOffset)))
                              + v98.matrix.ty);
                  v80 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.yy)
                                      + (float)(v98.matrix.yx * (float)(spriteInstance->xOffset + *p_x)))
                              + v98.matrix.ty);
                  v83 = (float)((float)((float)((float)(p_x[2] + spriteInstance->xOffset) * v98.matrix.xx)
                                      + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.xy))
                              + v98.matrix.tx);
                  v84 = (float)((float)((float)((float)(spriteInstance->xOffset + *p_x) * v98.matrix.xx)
                                      + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.xy))
                              + v98.matrix.tx);
                  v87 = (float)((float)((float)((float)(spriteInstance->xOffset + *p_x) * v98.matrix.xx)
                                      + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.xy))
                              + v98.matrix.tx);
                  v82 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                              * v98.matrix.yy)
                                      + (float)(v98.matrix.yx * (float)(p_x[2] + spriteInstance->xOffset)))
                              + v98.matrix.ty);
                }
                v86 = (float)((float)v91 + v98.matrix.tx);
              }
            }
            else
            {
              v80 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.yy)
                                  + (float)(v98.matrix.yx * (float)(spriteInstance->xOffset + *p_x)))
                          + v98.matrix.ty);
              v81 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.yy)
                                  + (float)(v98.matrix.yx * (float)(spriteInstance->xOffset + *p_x)))
                          + v98.matrix.ty);
              v83 = (float)((float)((float)((float)((float)(p_x[2] - (float)v78) + spriteInstance->xOffset)
                                          * v98.matrix.xx)
                                  + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.xy))
                          + v98.matrix.tx);
              v84 = (float)((float)((float)((float)(spriteInstance->xOffset + *p_x) * v98.matrix.xx)
                                  + (float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.xy))
                          + v98.matrix.tx);
              v85 = (float)((float)((float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.yy)
                                  + (float)(v98.matrix.yx
                                          * (float)((float)(p_x[2] - (float)v78) + spriteInstance->xOffset)))
                          + v98.matrix.ty);
              v86 = (float)((float)((float)((float)((float)(p_x[2] - (float)v78) + spriteInstance->xOffset)
                                          * v98.matrix.xx)
                                  + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.xy))
                          + v98.matrix.tx);
              v87 = (float)((float)((float)((float)(spriteInstance->xOffset + *p_x) * v98.matrix.xx)
                                  + (float)((float)((float)(p_x[3] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.xy))
                          + v98.matrix.tx);
              v82 = (float)((float)((float)((float)((float)(p_x[1] + (float)v77) + spriteInstance->yOffset)
                                          * v98.matrix.yy)
                                  + (float)(v98.matrix.yx
                                          * (float)((float)(p_x[2] - (float)v78) + spriteInstance->xOffset)))
                          + v98.matrix.ty);
            }
            v97.mat[0].x = v84;
            v97.mat[0].y = v81;
            v97.mat[0].z = 1.0;
            v97.mat[1].x = v83;
            v97.mat[1].y = v82;
            v97.mat[1].z = 1.0;
            v97.mat[2].x = v86;
            v97.mat[2].y = v85;
            v97.mat[2].z = 1.0;
            idMat3::InverseSelf(this: &v97);
            LODWORD(v92) = x;
            *(_QWORD *)&v104.variables.num = __PAIR64__(x, y);
            *(_QWORD *)&v104.variablesHash[1] = v92;
            v93 = (float)v92;
            v94 = (float)((float)((float)(v97.mat[1].x * (float)__SPAIR64__(x, y)) + (float)(v97.mat[0].x * (float)v92))
                        + v97.mat[2].x) > 0.0;
            if ( v94 == (float)((float)((float)(v97.mat[1].y * (float)__SPAIR64__(x, y))
                                      + (float)(v97.mat[0].y * (float)v92))
                              + v97.mat[2].y) > 0.0
              && v94 == (float)((float)((float)(v97.mat[1].z * (float)__SPAIR64__(x, y))
                                      + (float)(v97.mat[0].z * (float)v92))
                              + v97.mat[2].z) > 0.0 )
            {
              v20 = v72;
            }
            v97.mat[0].x = v84;
            v97.mat[0].y = v81;
            v97.mat[0].z = 1.0;
            v97.mat[1].x = v86;
            v97.mat[1].y = v85;
            v97.mat[1].z = 1.0;
            v97.mat[2].x = v87;
            v97.mat[2].y = v80;
            v97.mat[2].z = 1.0;
            idMat3::InverseSelf(this: &v97);
            v95 = (float)((float)((float)(v97.mat[1].x * (float)__SPAIR64__(x, y)) + (float)(v97.mat[0].x * (float)v93))
                        + v97.mat[2].x) > 0.0;
            if ( v95 == (float)((float)((float)(v97.mat[1].y * (float)__SPAIR64__(x, y))
                                      + (float)(v97.mat[0].y * (float)v93))
                              + v97.mat[2].y) > 0.0
              && v95 == (float)((float)((float)(v97.mat[1].z * (float)__SPAIR64__(x, y))
                                      + (float)(v97.mat[0].z * (float)v93))
                              + v97.mat[2].z) > 0.0 )
            {
              v20 = v72;
            }
          }
        }
      }
LABEL_59:
      ++v21;
      ++v22;
      if ( v21 >= spriteInstance->displayList.num )
        return v20;
      v16 = v101;
      v17 = v102;
    }
  }
  return v20;
}


// ========================================================================
// __unwind$219969
// EA  : 0x8277062C
// RVA : 0x0077062C
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_219969()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 592;
  if ( (*(_DWORD *)(v0 - 592 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v1 + 280));
  }
}


// ========================================================================
// ?HandleEvent@idSWF@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82770678
// RVA : 0x00770678
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

int __fastcall idSWF::HandleEvent(idSWF *this, const sysEvent_t *event)
{
  sysEventType_t evType; // r11
  idSWFScriptVar::swfScriptVarType v5; // r28
  idSWFSpriteInstance *mainspriteInstance; // r4
  idSWFScriptObject *v7; // r3
  idSWFScriptObject *v8; // r29
  const idSWFScriptVar *v9; // r3
  idSWFScriptVar *v11; // r3
  idSWFScriptObject *mouseObject; // r4
  const idSWFScriptVar *v13; // r3
  idSWFScriptObject *hoverObject; // r3
  const char *v15; // r26
  int v16; // r28
  char v17; // r11
  idStr *v18; // r3
  const idSWFScriptVar *v19; // r3
  idSWFScriptObject *list; // r28
  idSWFScriptVar *v21; // r3
  bool v22; // r26
  const idSWFScriptVar *v23; // r3
  const idSWFScriptVar *v24; // r3
  char *Binding; // r3
  int v26; // r28
  idSWFScriptObject *size; // r28
  idSWFScriptVar *v28; // r3
  bool v29; // r30
  idSWFScriptVar *v30; // r3
  idSWFScriptVar *v31; // r3
  const char *v32; // r3
  idSWFScriptVar *v33; // r3
  idSWFScriptVar::swfScriptVarValue_t v34; // r11
  idSWFScriptVar::swfScriptVarValue_t v35; // r9
  double renderBorder; // fp0
  unsigned int i; // r6
  idSWFScriptVar::swfScriptVarValue_t v38; // r11
  idSWFSpriteInstance *v39; // r4
  int v40; // r24
  idSWFScriptObject *v41; // r3
  idSWFScriptObject *v42; // r28
  idSWFScriptObject *v43; // r4
  idSWFScriptObject::swfNamedVar_t *v44; // r24
  int v45; // r29
  idSWFScriptObject *v46; // r4
  __int64 v47; // r9
  BOOL v48; // r30
  bool v49; // [sp+50h] [-AF0h] BYREF
  __int64 v50; // [sp+58h] [-AE8h] BYREF
  idSWFScriptObject v51; // [sp+60h] [-AE0h] BYREF
  float v52; // [sp+C0h] [-A80h]
  float v53; // [sp+C4h] [-A7Ch]
  float v54; // [sp+C8h] [-A78h]
  float v55; // [sp+CCh] [-A74h]
  float v56; // [sp+D0h] [-A70h]
  float v57; // [sp+D4h] [-A6Ch]
  float v58; // [sp+D8h] [-A68h]
  float v59; // [sp+DCh] [-A64h]
  float v60; // [sp+E0h] [-A60h]
  float v61; // [sp+E4h] [-A5Ch]
  int v62; // [sp+E8h] [-A58h]
  int v63; // [sp+ECh] [-A54h]
  int v64; // [sp+F0h] [-A50h]
  int v65; // [sp+F4h] [-A4Ch]
  char v66; // [sp+F8h] [-A48h]
  float v67; // [sp+FCh] [-A44h]
  idSWFScriptObject v68; // [sp+100h] [-A40h] BYREF
  idSWFScriptVar v69; // [sp+160h] [-9E0h] BYREF
  idSWFScriptObject v70; // [sp+168h] [-9D8h] BYREF
  idStaticList<idSWFScriptVar,16> v71; // [sp+1D0h] [-970h] BYREF
  idStr v72; // [sp+260h] [-8E0h] BYREF
  idStaticList<idSWFScriptVar,16> v73; // [sp+280h] [-8C0h] BYREF
  idStaticList<idSWFScriptVar,16> v74; // [sp+310h] [-830h] BYREF
  idStaticList<idSWFScriptVar,16> v75; // [sp+3A0h] [-7A0h] BYREF
  idStaticList<idSWFScriptVar,16> v76; // [sp+430h] [-710h] BYREF
  idStaticList<idSWFScriptVar,16> v77; // [sp+4C0h] [-680h] BYREF
  idStaticList<idSWFScriptVar,16> v78; // [sp+550h] [-5F0h] BYREF
  idStaticList<idSWFScriptVar,16> v79; // [sp+5E0h] [-560h] BYREF
  idStaticList<idSWFScriptVar,16> v80; // [sp+670h] [-4D0h] BYREF
  idStaticList<idSWFScriptVar,16> v81; // [sp+700h] [-440h] BYREF
  idStaticList<idSWFScriptVar,16> v82; // [sp+790h] [-3B0h] BYREF
  idStaticList<idSWFScriptVar,16> v83; // [sp+820h] [-320h] BYREF
  idStaticList<idSWFScriptVar,16> v84; // [sp+8B0h] [-290h] BYREF
  idStaticList<idSWFScriptVar,16> v85; // [sp+940h] [-200h] BYREF
  idStaticList<idSWFScriptVar,16> v86; // [sp+9D0h] [-170h] BYREF
  idStaticList<idSWFScriptVar,16> v87; // [sp+A60h] [-E0h] BYREF

  if ( this->frameRate == 0 || !this->isActive || !this->inhibitControl && this->useInhibtControl )
    return 0;
  evType = event->evType;
  if ( event->evType == SE_KEY )
  {
    HIDWORD(v50) = event->evValue;
    if ( HIDWORD(v50) == 286 )
    {
      v5 = SWF_VAR_UNDEF;
      this->mouseEnabled = true;
      HIDWORD(v50) = 4;
      if ( event->evValue2 != 0 )
      {
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v51.variablesHash[1],
          result: (idSWFScriptVar *)this->globals,
          name: "waitInput");
        if ( v51.variablesHash[1] == 7 )
        {
          this->useMouse = false;
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v79);
          idSWFParmList::Append(this: (idSWFParmList *)&v79, i: event->evValue);
          (*(void (__fastcall **)(__int16 *, int, _DWORD, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[2]
                                                                                            + 4))(
            a1: &v70.variables.granularity,
            a2: v51.variablesHash[2],
            a3: 0,
            a4: &v79);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variables.granularity);
          idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v79);
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v79);
        }
        else
        {
          this->useMouse = true;
        }
        v62 = 0;
        v63 = 0;
        v64 = 0;
        v65 = 0;
        v66 = 0;
        *(float *)&v51.variablesHash[15] = 1.0;
        *(float *)&v51.prototype = 1.0;
        *(float *)&v51.objectType = 0.0;
        mainspriteInstance = this->mainspriteInstance;
        *(float *)&v51.data.sprite = 0.0;
        v52 = 0.0;
        v53 = 0.0;
        v54 = 1.0;
        v55 = 1.0;
        v56 = 1.0;
        v57 = 1.0;
        v58 = 0.0;
        v59 = 0.0;
        v60 = 0.0;
        v61 = 0.0;
        v67 = 0.0;
        v7 = idSWF::HitTest(
               this,
               spriteInstance: mainspriteInstance,
               renderState: (const swfRenderState_t *)&v51.variablesHash[15],
               x: idSWF::mouseX,
               y: idSWF::mouseY,
               parentObject: nullptr);
        v8 = v7;
        if ( v7 != nullptr )
        {
          this->mouseObject = v7;
          ++v7->refCount;
          v9 = idSWFScriptObject::Get(
                 this: (idSWFScriptObject *)&v68.variablesHash[13],
                 result: (idSWFScriptVar *)v7,
                 name: "onPress");
          idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v50, other: v9);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[13]);
          if ( HIDWORD(v50) == 7 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v75);
            idSWFParmList::Append(this: (idSWFParmList *)&v75, i: event->inputDevice);
            idSWFParmList::Append(this: (idSWFParmList *)&v75, o: v8);
            (*(void (__fastcall **)(int *, int __struct_ptr, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v50 + 4))(
              a1: &v68.variablesHash[7],
              a2: v50,
              a3: v8,
              a4: &v75);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[7]);
            idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v75);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v75);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[1]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v50);
            return 1;
          }
          idSWFScriptObject::Get(
            this: (idSWFScriptObject *)&v51.variablesHash[9],
            result: (idSWFScriptVar *)v8,
            name: "onDrag");
          if ( v51.variablesHash[9] == 7 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v73);
            idSWFParmList::Append(this: (idSWFParmList *)&v73, i: event->inputDevice);
            idSWFParmList::Append(this: (idSWFParmList *)&v73, i: idSWF::mouseX);
            idSWFParmList::Append(this: (idSWFParmList *)&v73, i: idSWF::mouseY);
            idSWFParmList::Append(this: (idSWFParmList *)&v73, b: true);
            (*(void (__fastcall **)(int *, int, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[10] + 4))(
              a1: &v70.variablesHash[13],
              a2: v51.variablesHash[10],
              a3: v8,
              a4: &v73);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[13]);
            idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v73);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v73);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[9]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[1]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v50);
            return 1;
          }
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[9]);
        }
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v82);
        idSWFParmList::Append(this: (idSWFParmList *)&v82, o: v8);
        idSWF::Invoke(this, functionName: "setHitObject", parms: (const idSWFParmList *)&v82);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v82);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[1]);
      }
      else
      {
        mouseObject = this->mouseObject;
        if ( mouseObject != nullptr )
        {
          v13 = idSWFScriptObject::Get(
                  this: (idSWFScriptObject *)&v70.objectType,
                  result: (idSWFScriptVar *)mouseObject,
                  name: "onRelease");
          idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v50, other: v13);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.objectType);
          v5 = HIDWORD(v50);
          if ( HIDWORD(v50) == 7 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v83);
            idSWFParmList::Append(this: (idSWFParmList *)&v83, o: this->mouseObject);
            (*(void (__fastcall **)(int *, int __struct_ptr, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v50 + 4))(
              a1: &v68.variablesHash[11],
              a2: v50,
              a3: this->mouseObject,
              a4: &v83);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[11]);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v83);
          }
          idSWFScriptObject::Release(this: this->mouseObject);
          this->mouseObject = nullptr;
        }
        hoverObject = this->hoverObject;
        if ( hoverObject != nullptr )
        {
          idSWFScriptObject::Release(this: hoverObject);
          this->hoverObject = nullptr;
        }
        if ( v5 == SWF_VAR_FUNCTION )
        {
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v50);
          return 1;
        }
      }
      v11 = (idSWFScriptVar *)&v50;
      goto _M221575;
    }
    v15 = idKeyInput::KeyNumToString(keynum: SHIDWORD(v50));
    idSWFScriptObject::Get(this: &v51, result: (idSWFScriptVar *)this->shortcutKeys, name: v15);
    v16 = 0;
    while ( 1 )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v71);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v71);
      if ( v51.refCount == 1 || (v17 = 0, v51.refCount == 0) )
        v17 = 1;
      if ( v17 == 0 )
        break;
      v18 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v72, result: (idStr *)&v51);
      v19 = idSWFScriptObject::Get(
              this: (idSWFScriptObject *)&v70.variablesHash[3],
              result: (idSWFScriptVar *)this->shortcutKeys,
              name: v18->data);
      idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v51, other: v19);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[3]);
      idStr::FreeData(this: &v72);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
      if ( ++v16 >= 32 )
      {
        idLib::Warning(fmt: "Circular reference in %s shortcutKeys.%s", this->filename.str, v15);
LABEL_34:
        v11 = (idSWFScriptVar *)&v51;
        goto _M221575;
      }
    }
    if ( v51.refCount == 8 )
    {
      list = (idSWFScriptObject *)v51.variables.list;
      v21 = idSWFScriptObject::Get(
              this: (idSWFScriptObject *)&v68.objectType,
              result: (idSWFScriptVar *)v51.variables.list,
              name: "_pressed");
      v22 = idSWFScriptVar::ToBool(this: v21);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.objectType);
      idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v68.variablesHash[1], b: event->evValue2 != 0);
      idSWFScriptObject::Set(this: list, name: "_pressed", value: (const idSWFScriptVar *)&v68.variablesHash[1]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[1]);
      if ( event->evValue2 != 0 )
      {
        v23 = idSWFScriptObject::Get(
                this: (idSWFScriptObject *)&v70.variablesHash[11],
                result: (idSWFScriptVar *)list,
                name: "onPress");
        idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v51, other: v23);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[11]);
        idSWFParmList::Append(this: (idSWFParmList *)&v71, i: event->inputDevice);
        idSWFParmList::Append(this: (idSWFParmList *)&v71, o: list);
      }
      else if ( v22 )
      {
        v24 = idSWFScriptObject::Get(this: &v70, result: (idSWFScriptVar *)list, name: "onRelease");
        idSWFScriptVar::operator=(this: (idSWFScriptVar *)&v51, other: v24);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70);
      }
      if ( v51.refCount == 7 )
      {
        (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(v51.variables.list->index + 4))(
          a1: &v70.variablesHash[7],
          a2: v51.variables.list,
          a3: list,
          a4: &v71);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[7]);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51);
        return 1;
      }
    }
    else if ( v51.refCount == 7 )
    {
      if ( event->evValue2 == 0 )
      {
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
        goto LABEL_34;
      }
      (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, _DWORD, idStaticList<idSWFScriptVar,16> *))(v51.variables.list->index + 4))(
        a1: &v68.variablesHash[3],
        a2: v51.variables.list,
        a3: 0,
        a4: &v71);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[3]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51);
      return 1;
    }
    idSWFScriptObject::Get(
      this: (idSWFScriptObject *)&v51.variablesHash[13],
      result: (idSWFScriptVar *)this->globals,
      name: "useFunction");
    if ( v51.variablesHash[13] == 7 && event->evValue2 != 0 )
    {
      Binding = idKeyInput::GetBinding(numDevice: event->inputDevice, bindset: 0, keynum: (keyNum_t)event->evValue);
      if ( idStr::Cmp(s1: "_use", s2: Binding) == 0 )
      {
        v26 = v51.variablesHash[14];
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v85);
        (*(void (__fastcall **)(int *, int, _DWORD, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v26 + 4))(
          a1: &v70.variablesHash[15],
          a2: v26,
          a3: 0,
          a4: &v85);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[15]);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v85);
      }
    }
    idSWFScriptObject::Get(
      this: (idSWFScriptObject *)&v51.variablesHash[5],
      result: (idSWFScriptVar *)this->globals,
      name: "waitInput");
    if ( v51.variablesHash[5] == 7 )
    {
      this->useMouse = false;
      if ( event->evValue2 != 0 )
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v84);
        idSWFParmList::Append(this: (idSWFParmList *)&v84, i: event->evValue);
        (*(void (__fastcall **)(int *, int, _DWORD, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[6]
                                                                                      + 4))(
          a1: &v68.variablesHash[9],
          a2: v51.variablesHash[6],
          a3: 0,
          a4: &v84);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[9]);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v84);
      }
    }
    else
    {
      this->useMouse = true;
    }
    idSWFScriptObject::Get(
      this: (idSWFScriptObject *)&v51.variables.num,
      result: (idSWFScriptVar *)this->globals,
      name: "focusWindow");
    if ( v51.variables.num != 8 )
      goto _M221612_0;
    idSWFScriptObject::Get(
      this: (idSWFScriptObject *)&v51.variables.granularity,
      result: (idSWFScriptVar *)v51.variables.size,
      name: "onKey");
    if ( *(_DWORD *)&v51.variables.granularity != 7 )
    {
LABEL_63:
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variables.granularity);
_M221612_0:
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variables.num);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[5]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[13]);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
      goto LABEL_34;
    }
    size = (idSWFScriptObject *)v51.variables.size;
    v28 = idSWFScriptObject::Get(
            this: (idSWFScriptObject *)&v68.variablesHash[15],
            result: (idSWFScriptVar *)v51.variables.size,
            name: "_kpressed");
    v29 = idSWFScriptVar::ToBool(this: v28);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[15]);
    idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v68.variables.granularity, b: event->evValue2 != 0);
    idSWFScriptObject::Set(this: size, name: "_kpressed", value: (const idSWFScriptVar *)&v68.variables.granularity);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variables.granularity);
    if ( event->evValue2 == 0 && !v29 )
    {
      HIDWORD(v50) = event->evValue;
      if ( HIDWORD(v50) == 42 || HIDWORD(v50) == 54 )
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v80);
        idSWFParmList::Append(this: (idSWFParmList *)&v80, i: event->evValue);
        idSWFParmList::Append(this: (idSWFParmList *)&v80, b: event->evValue2 != 0);
        v30 = (idSWFScriptVar *)(*(int (__fastcall **)(idSWFScriptVar *, int, int, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[0] + 4))(
                                  a1: &v69,
                                  a2: v51.variablesHash[0],
                                  a3: v51.variables.size,
                                  a4: &v80);
        idSWFScriptVar::ToBool(this: v30);
        idSWFScriptVar::Free(this: &v69);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v80);
      }
      goto LABEL_63;
    }
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v78);
    idSWFParmList::Append(this: (idSWFParmList *)&v78, i: event->evValue);
    idSWFParmList::Append(this: (idSWFParmList *)&v78, b: event->evValue2 != 0);
    v31 = (idSWFScriptVar *)(*(int (__fastcall **)(int *, int, int, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[0] + 4))(
                              a1: &v70.variables.num,
                              a2: v51.variablesHash[0],
                              a3: v51.variables.size,
                              a4: &v78);
    idSWFScriptVar::ToBool(this: v31);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variables.num);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v78);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variables.granularity);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variables.num);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[5]);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[13]);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v71);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51);
    return 1;
  }
  else
  {
    switch ( evType )
    {
      case SE_CHAR:
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v51.variablesHash[3],
          result: (idSWFScriptVar *)this->globals,
          name: "focusWindow");
        if ( v51.variablesHash[3] == 8 )
        {
          idSWFScriptObject::Get(
            this: (idSWFScriptObject *)&v51.variablesHash[7],
            result: (idSWFScriptVar *)v51.variablesHash[4],
            name: "onChar");
          if ( v51.variablesHash[7] == 7 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v77);
            idSWFParmList::Append(this: (idSWFParmList *)&v77, i: event->evValue);
            v32 = idKeyInput::KeyNumToString(keynum: (keyNum_t)event->evValue);
            idSWFParmList::Append(this: (idSWFParmList *)&v77, s: v32);
            v33 = (idSWFScriptVar *)(*(int (__fastcall **)(int *, int, int, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[8] + 4))(
                                      a1: &v70.variablesHash[1],
                                      a2: v51.variablesHash[8],
                                      a3: v51.variablesHash[4],
                                      a4: &v77);
            idSWFScriptVar::ToBool(this: v33);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[1]);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v77);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[7]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[3]);
            return 1;
          }
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[7]);
        }
        v11 = (idSWFScriptVar *)&v51.variablesHash[3];
_M221575:
        idSWFScriptVar::Free(this: v11);
        return 0;
      case SE_MOUSE:
        this->mouseEnabled = true;
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v76);
        idSWFParmList::Append(this: (idSWFParmList *)&v76, i: event->evValue);
        idSWFParmList::Append(this: (idSWFParmList *)&v76, i: event->evValue2);
        idSWF::Invoke(this, functionName: "onMouse", parms: (const idSWFParmList *)&v76);
        idSWF::mouseX += event->evValue;
        v34.i = idSWF::mouseX;
        v35.i = event->evValue2 + idSWF::mouseY;
        idSWF::mouseY = v35.i;
        renderBorder = this->renderBorder;
        LODWORD(v50) = (int)(float)(this->frameWidth + this->renderBorder);
        if ( idSWF::mouseX >= (int)v50 )
          v34.i = v50;
        LODWORD(v50) = (int)-renderBorder;
        i = v50;
        if ( v34.i > (int)v50 )
          i = v34.i;
        idSWF::mouseX = i;
        LODWORD(v50) = (int)this->frameHeight;
        v38.i = v50;
        if ( v35.i < (int)v50 )
          v38.f = v35.f;
        v62 = 0;
        idSWF::mouseY = ((v38.i == 0) + ((unsigned int)v38.i >> 31) - 1) & v38.i;
        *(float *)&v51.variablesHash[15] = 1.0;
        v63 = 0;
        *(float *)&v51.prototype = 1.0;
        v64 = 0;
        *(float *)&v51.objectType = 0.0;
        v65 = 0;
        *(float *)&v51.data.sprite = 0.0;
        v66 = 0;
        v52 = 0.0;
        v53 = 0.0;
        v54 = 1.0;
        v55 = 1.0;
        v39 = this->mainspriteInstance;
        v56 = 1.0;
        v40 = 0;
        v57 = 1.0;
        v58 = 0.0;
        v59 = 0.0;
        v60 = 0.0;
        v61 = 0.0;
        v67 = 0.0;
        v41 = idSWF::HitTest(
                this,
                spriteInstance: v39,
                renderState: (const swfRenderState_t *)&v51.variablesHash[15],
                x: i,
                y: idSWF::mouseY,
                parentObject: nullptr);
        v42 = v41;
        this->hasHitObject = v41 != nullptr;
        v43 = this->hoverObject;
        if ( v41 != v43 )
        {
          if ( v43 != nullptr )
          {
            idSWFScriptObject::Get(this: &v68, result: (idSWFScriptVar *)v43, name: "onRollOut");
            if ( v68.refCount == 7 )
            {
              v44 = v68.variables.list;
              idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v86);
              (*(void (__fastcall **)(int *, idSWFScriptObject::swfNamedVar_t *, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(v44->index + 4))(
                a1: &v70.variablesHash[5],
                a2: v44,
                a3: this->hoverObject,
                a4: &v86);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[5]);
              idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v86);
              v40 = 1;
            }
            idSWFScriptObject::Release(this: this->hoverObject);
            this->hoverObject = nullptr;
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68);
          }
          if ( v42 != nullptr )
          {
            this->hoverObject = v42;
            ++v42->refCount;
            idSWFScriptObject::Get(
              this: (idSWFScriptObject *)&v68.variables.num,
              result: (idSWFScriptVar *)v42,
              name: "onRollOver");
            if ( v68.variables.num == 7 )
            {
              v45 = v68.variables.size;
              idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v87);
              (*(void (__fastcall **)(int *, int, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v45 + 4))(
                a1: &v70.variablesHash[9],
                a2: v45,
                a3: v42,
                a4: &v87);
              idSWFScriptVar::Free(this: (idSWFScriptVar *)&v70.variablesHash[9]);
              idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v87);
              v40 = 1;
            }
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variables.num);
          }
        }
        v46 = this->mouseObject;
        if ( v46 != nullptr )
        {
          idSWFScriptObject::Get(
            this: (idSWFScriptObject *)&v51.variablesHash[11],
            result: (idSWFScriptVar *)v46,
            name: "onDrag");
          if ( v51.variablesHash[11] == 7 )
          {
            idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v74);
            idSWFParmList::Append(this: (idSWFParmList *)&v74, i: event->inputDevice);
            idSWFParmList::Append(this: (idSWFParmList *)&v74, i: idSWF::mouseX);
            idSWFParmList::Append(this: (idSWFParmList *)&v74, i: idSWF::mouseY);
            idSWFParmList::Append(this: (idSWFParmList *)&v74, b: false);
            (*(void (__fastcall **)(int *, int, idSWFScriptObject *, idStaticList<idSWFScriptVar,16> *))(*(_DWORD *)v51.variablesHash[12] + 4))(
              a1: &v68.variablesHash[5],
              a2: v51.variablesHash[12],
              a3: this->mouseObject,
              a4: &v74);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v68.variablesHash[5]);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v74);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[11]);
            idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v76);
            return 1;
          }
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v51.variablesHash[11]);
        }
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v76);
        return v40;
      case SE_JOYSTICK:
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v81);
        idSWFParmList::Append(this: (idSWFParmList *)&v81, i: event->evValue);
        LODWORD(v47) = event->evValue2;
        v50 = v47;
        idSWFParmList::Append(this: (idSWFParmList *)&v81, f: (float)((float)v47 * (float)0.03125));
        v49 = false;
        idSWF::Invoke(this, functionName: "onJoystick", parms: (const idSWFParmList *)&v81, functionExists: &v49);
        v48 = v49;
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v81);
        return v48;
      default:
        return 0;
    }
  }
}


// ========================================================================
// __unwind$220783
// EA  : 0x82771450
// RVA : 0x00771450
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220783()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 88));
}


// ========================================================================
// __unwind$220784
// EA  : 0x82771478
// RVA : 0x00771478
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220784()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 120));
}


// ========================================================================
// __unwind$220785
// EA  : 0x827714A0
// RVA : 0x007714A0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220785()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1504));
}


// ========================================================================
// __unwind$220787
// EA  : 0x827714C8
// RVA : 0x007714C8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220787()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 328));
}


// ========================================================================
// __unwind$220788
// EA  : 0x827714F0
// RVA : 0x007714F0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220788()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 928));
}


// ========================================================================
// __unwind$220790
// EA  : 0x82771518
// RVA : 0x00771518
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220790()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 152));
}


// ========================================================================
// __unwind$220791
// EA  : 0x82771540
// RVA : 0x00771540
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220791()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 640));
}


// ========================================================================
// __unwind$220793
// EA  : 0x82771568
// RVA : 0x00771568
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220793()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1936));
}


// ========================================================================
// __unwind$220794
// EA  : 0x82771590
// RVA : 0x00771590
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220794()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 448));
}


// ========================================================================
// __unwind$220795
// EA  : 0x827715B8
// RVA : 0x007715B8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220795()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 2080));
}


// ========================================================================
// __unwind$220797
// EA  : 0x827715E0
// RVA : 0x007715E0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220797()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 96));
}


// ========================================================================
// __unwind$220798
// EA  : 0x82771608
// RVA : 0x00771608
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220798()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 464));
}


// ========================================================================
// __unwind$220799
// EA  : 0x82771630
// RVA : 0x00771630
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220799()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2880 + 608));
}


// ========================================================================
// __unwind$220800
// EA  : 0x82771658
// RVA : 0x00771658
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220800()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 392));
}


// ========================================================================
// __unwind$220801
// EA  : 0x82771680
// RVA : 0x00771680
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220801()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 344));
}


// ========================================================================
// __unwind$220802
// EA  : 0x827716A8
// RVA : 0x007716A8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220802()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 280));
}


// ========================================================================
// __unwind$220803
// EA  : 0x827716D0
// RVA : 0x007716D0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220803()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 424));
}


// ========================================================================
// __unwind$220804
// EA  : 0x827716F8
// RVA : 0x007716F8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220804()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 360));
}


// ========================================================================
// __unwind$220807
// EA  : 0x82771720
// RVA : 0x00771720
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220807()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 168));
}


// ========================================================================
// __unwind$220808
// EA  : 0x82771748
// RVA : 0x00771748
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220808()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 2368));
}


// ========================================================================
// __unwind$220810
// EA  : 0x82771770
// RVA : 0x00771770
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220810()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 136));
}


// ========================================================================
// __unwind$220811
// EA  : 0x82771798
// RVA : 0x00771798
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220811()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 2224));
}


// ========================================================================
// __unwind$220813
// EA  : 0x827717C0
// RVA : 0x007717C0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220813()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 104));
}


// ========================================================================
// __unwind$220814
// EA  : 0x827717E8
// RVA : 0x007717E8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220814()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 112));
}


// ========================================================================
// __unwind$220815
// EA  : 0x82771810
// RVA : 0x00771810
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220815()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 336));
}


// ========================================================================
// __unwind$220816
// EA  : 0x82771838
// RVA : 0x00771838
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220816()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 272));
}


// ========================================================================
// __unwind$220819
// EA  : 0x82771860
// RVA : 0x00771860
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220819()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1648));
}


// ========================================================================
// __unwind$220820
// EA  : 0x82771888
// RVA : 0x00771888
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220820()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 352));
}


// ========================================================================
// __unwind$220817
// EA  : 0x827718B0
// RVA : 0x007718B0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220817()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1360));
}


// ========================================================================
// __unwind$220818
// EA  : 0x827718D8
// RVA : 0x007718D8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220818()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 368));
}


// ========================================================================
// __unwind$220821
// EA  : 0x82771900
// RVA : 0x00771900
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220821()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 128));
}


// ========================================================================
// __unwind$220822_0
// EA  : 0x82771928
// RVA : 0x00771928
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220822_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 144));
}


// ========================================================================
// __unwind$220823
// EA  : 0x82771950
// RVA : 0x00771950
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220823()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1216));
}


// ========================================================================
// __unwind$220824
// EA  : 0x82771978
// RVA : 0x00771978
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220824()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 384));
}


// ========================================================================
// __unwind$220825
// EA  : 0x827719A0
// RVA : 0x007719A0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220825()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1072));
}


// ========================================================================
// __unwind$220826
// EA  : 0x827719C8
// RVA : 0x007719C8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220826()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 256));
}


// ========================================================================
// __unwind$220827
// EA  : 0x827719F0
// RVA : 0x007719F0
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220827()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 2512));
}


// ========================================================================
// __unwind$220829
// EA  : 0x82771A18
// RVA : 0x00771A18
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220829()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 264));
}


// ========================================================================
// __unwind$220830
// EA  : 0x82771A40
// RVA : 0x00771A40
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220830()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 2656));
}


// ========================================================================
// __unwind$220832
// EA  : 0x82771A68
// RVA : 0x00771A68
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220832()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2880 + 160));
}


// ========================================================================
// __unwind$220833
// EA  : 0x82771A90
// RVA : 0x00771A90
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220833()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 784));
}


// ========================================================================
// __unwind$220835
// EA  : 0x82771AB8
// RVA : 0x00771AB8
// PDB : w:\tech5\engine\guis\swf\swf_events.cpp
// ========================================================================

void _unwind_220835()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2880 + 1792));
}

