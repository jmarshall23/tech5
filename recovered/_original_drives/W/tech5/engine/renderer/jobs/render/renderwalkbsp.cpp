
// ========================================================================
// ?RenderWalkBSP@@YAXPBUrenderWalkBSPParms_t@@@Z
// EA  : 0x828E4230
// RVA : 0x008E4230
// PDB : w:\tech5\engine\renderer\jobs\render\renderwalkbsp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall RenderWalkBSP(const renderWalkBSPParms_t *parms)
{
  const renderSettings_t *settings; // r10
  int singleWorldArea; // r11
  int isComboMap; // r11
  int numWorldAreas; // r9
  int v6; // r10
  int v7; // r24
  int v8; // r30
  int v9; // r28
  unsigned int v10; // r27
  int *v11; // r25
  int *v12; // r26
  __int64 v13; // r4 OVERLAPPED
  const areaNode_t *v14; // r11
  unsigned int v15; // r10
  int v16; // r5
  int v17; // r10
  int v18; // r11
  nodeWorldArea_t *v19; // r4
  nodeWorldArea_t *v20; // r4
  char v21; // [sp+50h] [-860h] BYREF
  char v22; // [sp+450h] [-460h] BYREF

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_WALK_BSP);
  settings = parms->settings;
  singleWorldArea = parms->settings->singleWorldArea;
  if ( singleWorldArea < 0 )
  {
    isComboMap = settings->isComboMap;
    if ( settings->isComboMap )
    {
      v7 = 0;
      v8 = 0;
      v9 = -1;
      LOBYTE(v10) = 0;
      v11 = (int *)&v21;
      v12 = (int *)&v22;
      while ( 1 )
      {
        if ( (_BYTE)v10 != 0 )
        {
          if ( v7 == 0 )
            goto LABEL_5;
          v8 = *--v12;
          --v7;
          v9 = *--v11;
          LOBYTE(v10) = 0;
        }
        if ( parms->areaNodeBoundsCulled[v8] == 0 || parms->settings->skipNodeCPUCulling )
        {
          if ( parms->areaNodeOcclusionIndex[v8] >= 0x40u
            || parms->settings->skipNodeGPUCulling
            || (unsigned __int8)idBounds::IntersectsBounds(
                                  this: (idBounds *)&parms->areaNodeBounds[v8],
                                  a: &parms->settings->viewBounds) != 0
            || (v9 = *parms->numOcclusionTestNodes,
                parms->occlusionTestNodes[v9] = v8,
                ++*parms->numOcclusionTestNodes,
                LODWORD(v13) = parms->areaNodeOcclusionQuery,
                *(__int64 *)((char *)&v13 + 4) = *(_QWORD *)(8 * parms->areaNodeOcclusionIndex[v8] + v13),
                SHIDWORD(v13) < SLODWORD(parms->renderView->firstOcclusionQueryInPreviousFrame))
            || GL_GetDeferredQueryResult(queryNumber: v13) != 0 )
          {
            v14 = &parms->areaNodes[v8];
            v15 = (float)((float)((float)(parms->settings->viewOrigin.x * v14->plane.a)
                                + (float)((float)(parms->settings->viewOrigin.z * v14->plane.c)
                                        + (float)(parms->settings->viewOrigin.y * v14->plane.b)))
                        + v14->plane.d) < 0.0;
            v16 = 4 * (((_cntlzw(v15) & 0x20) != 0) + 4);
            v17 = v14->children[v15];
            v8 = *(_DWORD *)((char *)&v14->plane.a + v16);
            if ( v17 <= 0 || v8 <= 0 )
            {
              v18 = *parms->numNodeWorldAreas;
              if ( v17 < 0 && v18 < 0x2000 )
              {
                parms->nodeWorldAreas[v18].areaNum = -1 - v17;
                v19 = &parms->nodeWorldAreas[v18++];
                v19->nodeOcclusionTestIndex = v9;
              }
              if ( v8 < 0 && v18 < 0x2000 )
              {
                parms->nodeWorldAreas[v18].areaNum = -1 - v8;
                v20 = &parms->nodeWorldAreas[v18++];
                v20->nodeOcclusionTestIndex = v9;
              }
              *parms->numNodeWorldAreas = v18;
              if ( v17 > v8 )
                v8 = v17;
              v10 = (v8 | (unsigned int)(v8 - 1)) >> 31;
            }
            else
            {
              *v12 = v8;
              ++v7;
              *v11 = v9;
              ++v12;
              ++v11;
              v8 = v17;
            }
          }
          else
          {
            LOBYTE(v10) = 1;
          }
        }
        else
        {
          LOBYTE(v10) = 1;
        }
      }
    }
    numWorldAreas = parms->numWorldAreas;
    if ( numWorldAreas > 0 )
    {
      v6 = 0;
      do
      {
        parms->nodeWorldAreas[v6].areaNum = isComboMap++;
        parms->nodeWorldAreas[v6++].nodeOcclusionTestIndex = -1;
        numWorldAreas = parms->numWorldAreas;
      }
      while ( isComboMap < numWorldAreas );
    }
    *parms->numNodeWorldAreas = numWorldAreas;
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
  else
  {
    if ( singleWorldArea > parms->numWorldAreas - 1 )
      singleWorldArea = parms->numWorldAreas - 1;
    parms->nodeWorldAreas->areaNum = singleWorldArea;
    parms->nodeWorldAreas->nodeOcclusionTestIndex = -1;
    *parms->numNodeWorldAreas = 1;
LABEL_5:
    idRenderLog::CloseMainBlock(this: &renderLog);
  }
}


// ========================================================================
// `dynamic initializer for 'register_RenderWalkBSP''
// EA  : 0x8334C3B0
// RVA : 0x0134C3B0
// PDB : w:\tech5\engine\renderer\jobs\render\renderwalkbsp.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderWalkBSP__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderWalkBSP,
           function: (void (__fastcall *)(void *))RenderWalkBSP,
           name: "RenderWalkBSP");
}

