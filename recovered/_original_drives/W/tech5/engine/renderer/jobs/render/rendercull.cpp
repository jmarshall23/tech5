
// ========================================================================
// ?RenderCull@@YAXPBUrenderCullParms_t@@@Z
// EA  : 0x828DA7E8
// RVA : 0x008DA7E8
// PDB : w:\tech5\engine\renderer\jobs\render\rendercull.cpp
// ========================================================================

void __fastcall RenderCull(const renderCullParms_t *parms)
{
  idRenderMatrix *p_worldSpaceMVPMatrix; // r26
  int v4; // r30
  int v5; // r29
  int v7; // r29
  int v8; // r27
  bool v13; // r3
  unsigned __int8 v16; // cr56
  unsigned __int8 v17; // cr57
  char v19; // cr56
  char v20; // cr57
  unsigned __int8 *worldAreaGeometryBoundsCulled; // r11
  unsigned __int8 v22[128]; // [sp+50h] [-80h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_CULL_BOUNDS);
  p_worldSpaceMVPMatrix = &parms->renderView->worldSpaceMVPMatrix;
  _R28 = 24;
  v4 = 0;
  if ( parms->numAreaNodes > 0 )
  {
    v5 = 0;
    do
    {
      _R4 = &parms->areaNodeBounds[v5];
      __asm { dcbt      r4, r28 }
      ++v5;
      parms->areaNodeBoundsCulled[v4++] = idRenderMatrix::CullBoundsToMVPbits(
                                            mvp: p_worldSpaceMVPMatrix,
                                            b: _R4,
                                            outBits: v22,
                                            zeroToOne: false);
    }
    while ( v4 < parms->numAreaNodes );
  }
  v7 = 0;
  if ( parms->numWorldAreas > 0 )
  {
    v8 = 0;
    _R24 = 16;
    _R25 = 8;
    do
    {
      _R30 = &parms->worldAreaGeometryBounds[v8];
      _R4 = &parms->worldAreaSubspaceBounds[v8];
      __asm
      {
        dcbt      r4, r28
        dcbt      r30, r28
      }
      v13 = idRenderMatrix::CullBoundsToMVPbits(
              mvp: p_worldSpaceMVPMatrix,
              b: _R4,
              outBits: &parms->worldAreaSubspaceBoundsCulled[v7],
              zeroToOne: false);
      parms->worldAreaGeometryBoundsCulled[v7] = 3;
      if ( !v13 )
      {
        if ( idRenderMatrix::CullBoundsToMVPbits(mvp: p_worldSpaceMVPMatrix, b: _R30, outBits: v22, zeroToOne: false) )
        {
          parms->worldAreaGeometryBoundsCulled[v7] = 3;
        }
        else
        {
          __asm
          {
            lvrx128   v62, r24, r30
            lvlx128   v63, r0, r30
            vspltisw  v0, 0
          }
          _R11 = &parms->settings->detailBounds;
          __asm
          {
            lvrx128   v61, r28, r30
            lvlx128   v60, r25, r30
            vor128    v63, v95, v62
            vor128    v59, v92, v61
            lvrx128   v58, r24, r11
            vrlimi128 v63, v0, 1, 0
            lvlx128   v57, r0, r11
            vsldoi128 v62, v91, v0, 4
            lvrx128   v56, r28, r11
            vor128    v55, v89, v58
            lvlx128   v54, r25, r11
            vor128    v53, v86, v56
            vrlimi128 v55, v0, 1, 0
            vsldoi128 v52, v85, v0, 4
            vcmpgefp128 v51, v94, v55
            vcmpgefp128 v50, v84, v63
            vand128   v13, v82, v51
            vcmpgtuw. v12, v13, v0
          }
          if ( (((v16 << 7) | (v17 << 6)) & 0x80) != 0 )
          {
            _R11 = &parms->settings->viewBounds;
            __asm
            {
              lvlx128   v49, r0, r11
              lvrx128   v48, r24, r11
              lvrx128   v47, r28, r11
              vor128    v46, v81, v48
              lvlx128   v45, r25, r11
              vor128    v44, v77, v47
              vrlimi128 v46, v0, 1, 0
              vsldoi128 v43, v76, v0, 4
              vcmpgefp128 v42, v94, v46
              vcmpgefp128 v41, v75, v63
              vand128   v13, v73, v42
              vcmpgtuw. v12, v13, v0
            }
            worldAreaGeometryBoundsCulled = parms->worldAreaGeometryBoundsCulled;
            worldAreaGeometryBoundsCulled[v7] = ((unsigned __int8)(v19 << 7) | (v20 << 6) & 0x80) == 0;
          }
          else
          {
            parms->worldAreaGeometryBoundsCulled[v7] = 2;
          }
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < parms->numWorldAreas );
  }
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// `dynamic initializer for 'register_RenderCull''
// EA  : 0x8334C310
// RVA : 0x0134C310
// PDB : w:\tech5\engine\renderer\jobs\render\rendercull.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderCull__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderCull,
           function: (void (__fastcall *)(void *))RenderCull,
           name: "RenderCull");
}

