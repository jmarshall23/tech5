
// ========================================================================
// ?GetDistSegToArea@bfx@@YAMABVLineSeg@1@MMPAVArea@1@@Z
// EA  : 0x8325ACC8
// RVA : 0x0125ACC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

float __fastcall bfx::GetDistSegToArea(
        const bfx::LineSeg *origSeg,
        double s0,
        double s1,
        bfx::Area *pArea,
        int a5,
        const bfx::Area *a6)
{
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp1
  double v14; // fp11
  double v15; // fp10
  float result; // fp1
  bfx::Vec3 v19; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v20; // [sp+60h] [-40h] BYREF
  bfx::Vec3 v21; // [sp+70h] [-30h] BYREF
  bfx::Vec3 v22; // [sp+80h] [-20h] BYREF

  m_x = origSeg->m_v0.m_x;
  m_y = origSeg->m_v0.m_y;
  m_z = origSeg->m_v0.m_z;
  v10 = (float)((float)(origSeg->m_v1.m_x - origSeg->m_v0.m_x) * (float)s0);
  v11 = (float)((float)(origSeg->m_v1.m_y - origSeg->m_v0.m_y) * (float)s0);
  v12 = (float)((float)(origSeg->m_v1.m_z - origSeg->m_v0.m_z) * (float)s0);
  v14 = (float)((float)(origSeg->m_v1.m_y - origSeg->m_v0.m_y) * (float)s1);
  v15 = (float)((float)(origSeg->m_v1.m_z - origSeg->m_v0.m_z) * (float)s1);
  v13 = (float)((float)(origSeg->m_v1.m_x - origSeg->m_v0.m_x) * (float)s1);
  v20.m_x = origSeg->m_v0.m_x + (float)v10;
  v20.m_y = (float)m_y + (float)v11;
  v20.m_z = (float)m_z + (float)v12;
  v19.m_x = (float)m_x + (float)v13;
  v19.m_y = (float)m_y + (float)v14;
  v19.m_z = (float)m_z + (float)v15;
  bfx::GetClosestPosInArea(result: &v22, pArea: a6, pos: &v20, pEdgeIndexOut: nullptr);
  bfx::GetClosestPosInArea(result: &v21, pArea: a6, pos: &v19, pEdgeIndexOut: nullptr);
  _FP5 = (float)((float)__fsqrts((float)((float)((float)(v22.m_x - v20.m_x) * (float)(v22.m_x - v20.m_x))
                                       + (float)((float)((float)(v22.m_z - v20.m_z) * (float)(v22.m_z - v20.m_z))
                                               + (float)((float)(v22.m_y - v20.m_y) * (float)(v22.m_y - v20.m_y)))))
               - (float)__fsqrts((float)((float)((float)(v21.m_x - v19.m_x) * (float)(v21.m_x - v19.m_x))
                                       + (float)((float)((float)(v21.m_z - v19.m_z) * (float)(v21.m_z - v19.m_z))
                                               + (float)((float)(v21.m_y - v19.m_y) * (float)(v21.m_y - v19.m_y))))));
  __asm { fsel      f1, f5, f7, f6 }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?RemoveOverlapBetweenSegments@bfx@@YAXABVLineSeg@1@AAVAreaSeg@1@1@Z
// EA  : 0x8325ADF8
// RVA : 0x0125ADF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::RemoveOverlapBetweenSegments(const bfx::LineSeg *origSeg, bfx::Area *segA, bfx::AreaSeg *segB)
{
  bfx::AreaSeg *v4; // r31
  double DistSegToArea; // fp29
  int v11; // r5
  bfx::Area *v12; // r4
  double m_s0; // fp13
  double m_s1; // fp0

  v4 = (bfx::AreaSeg *)segA;
  _FP11 = (float)(*(float *)&segA->m_dynAreaData.m_data - segB->m_s0);
  _FP9 = (float)(*(float *)&segA->m_pFirstLink - segB->m_s1);
  __asm
  {
    fsel      f31, f11, f13, f0
    fsel      f30, f9, f12, f10
  }
  if ( _FP31 < _FP30 )
  {
    DistSegToArea = bfx::GetDistSegToArea(
                      origSeg,
                      s0: _FP31,
                      s1: _FP30,
                      pArea: segA,
                      a5: (int)segB,
                      a6: (const bfx::Area *)segA->m_pProxy);
    if ( DistSegToArea <= bfx::GetDistSegToArea(origSeg, s0: _FP31, s1: _FP30, pArea: v12, a5: v11, a6: segB->m_pArea) )
      v4 = segB;
    m_s0 = v4->m_s0;
    if ( _FP31 <= m_s0 )
    {
LABEL_10:
      v4->m_s0 = _FP30;
      return;
    }
    m_s1 = v4->m_s1;
    if ( _FP30 >= m_s1 )
    {
LABEL_9:
      v4->m_s1 = _FP31;
      return;
    }
    if ( _FP31 >= m_s0 && _FP30 <= m_s1 )
    {
      if ( (float)((float)_FP31 - v4->m_s0) > (double)(float)(v4->m_s1 - (float)_FP30) )
        goto LABEL_9;
      goto LABEL_10;
    }
  }
}


// ========================================================================
// ?SnapLinkStripEndPosOntoNavGraph@bfx@@YAXPAVNavLayer@1@MAAVVec3@1@@Z
// EA  : 0x8325AEF8
// RVA : 0x0125AEF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::SnapLinkStripEndPosOntoNavGraph(
        bfx::NavLayer *pNavLayer,
        double maxSnapDist,
        bfx::Vec3 *pos,
        bfx::Vec3 *a4)
{
  const bfx::Area *ClosestArea; // r3
  float *v7; // r30
  float v8; // r9
  float v9; // r8
  double v10; // fp30
  double v11; // fp29
  double v12; // fp28
  double v13; // fp31
  double Scale; // fp1
  double m_y; // fp12
  double m_z; // fp11
  bfx::Vec3 v19; // [sp+50h] [-60h] BYREF
  float v20; // [sp+60h] [-50h]
  float v21; // [sp+64h] [-4Ch]
  float v22; // [sp+68h] [-48h]

  ClosestArea = bfx::NavLayer::GetClosestArea(
                  this: pNavLayer,
                  pos: a4,
                  pathSpec: &bfx::g_defaultPathSpec,
                  radius: maxSnapDist);
  v7 = (float *)ClosestArea;
  if ( ClosestArea != nullptr )
  {
    bfx::GetClosestPosInArea(result: &v19, pArea: ClosestArea, pos: a4, pEdgeIndexOut: nullptr);
    if ( __fsqrts((float)((float)((float)(v19.m_x - a4->m_x) * (float)(v19.m_x - a4->m_x))
                        + (float)((float)((float)(v19.m_z - a4->m_z) * (float)(v19.m_z - a4->m_z))
                                + (float)((float)(v19.m_y - a4->m_y) * (float)(v19.m_y - a4->m_y))))) <= maxSnapDist )
    {
      v8 = v7[4];
      v9 = v7[5];
      v22 = v7[6];
      v20 = v8;
      v21 = v9;
      v10 = (float)(v9 - v19.m_y);
      v11 = (float)(v22 - v19.m_z);
      v12 = (float)(v8 - v19.m_x);
      v13 = __fsqrts((float)((float)((float)(v8 - v19.m_x) * (float)(v8 - v19.m_x))
                           + (float)((float)((float)(v22 - v19.m_z) * (float)(v22 - v19.m_z))
                                   + (float)((float)(v9 - v19.m_y) * (float)(v9 - v19.m_y)))));
      if ( v13 > 1.0842022e-19 )
      {
        Scale = bfx::GetScale();
        m_y = v19.m_y;
        m_z = v19.m_z;
        _FP9 = (float)((float)((float)Scale * (float)0.001) - (float)v13);
        __asm { fsel      f8, f9, f31, f10 }
        a4->m_x = (float)((float)v12 * (float)((float)_FP8 / (float)v13)) + v19.m_x;
        a4->m_y = (float)((float)v10 * (float)((float)_FP8 / (float)v13)) + (float)m_y;
        a4->m_z = (float)((float)v11 * (float)((float)_FP8 / (float)v13)) + (float)m_z;
      }
    }
  }
}


// ========================================================================
// ?UpdateCachedDataForHLinkEnableOrDisable@bfx@@YAXPAVHalfLink@1@_N@Z
// EA  : 0x8325B048
// RVA : 0x0125B048
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::UpdateCachedDataForHLinkEnableOrDisable(bfx::HalfLink *pLink, bool enable)
{
  bfx::NavLayer *m_pNavLayer; // r30
  bool v5; // cr58
  bfx::IslandGraph *m_pIslandGraph; // r3
  bfx::XGraph_vtbl *v7; // r11
  void (*UpdateForRemoveHLink)(void); // r10

  m_pNavLayer = pLink->m_pNavLayer;
  v5 = !enable;
  m_pIslandGraph = m_pNavLayer->m_pIslandGraph;
  if ( v5 )
  {
    bfx::IslandGraph::UpdateForLinkDisabledOrModified(this: m_pIslandGraph, pLink);
    if ( pLink->m_pXLinkChain == nullptr )
      return;
    UpdateForRemoveHLink = (void (*)(void))m_pNavLayer->m_pXGraph->UpdateForRemoveHLink;
  }
  else
  {
    bfx::IslandGraph::UpdateForLinkEnabled(this: m_pIslandGraph, pLink);
    v7 = m_pNavLayer->m_pXGraph->__vftable;
    if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) == 0 )
    {
      ((void (*)(void))v7->MarkDirty)();
      return;
    }
    UpdateForRemoveHLink = (void (*)(void))v7->UpdateForAddHLink;
  }
  UpdateForRemoveHLink();
}


// ========================================================================
// ?EnableLinkPair@bfx@@YAXPAVHalfLink@1@_N@Z
// EA  : 0x8325B0F8
// RVA : 0x0125B0F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::EnableLinkPair(bfx::HalfLink *pForwardLink, bool enable)
{
  bfx::HalfLink *m_pTwin; // r30
  char v4; // r11
  char v5; // r9
  char v6; // r11
  char v7; // r29
  char v8; // r10
  char v9; // r11
  char v10; // r10
  bool v11; // zf
  char v12; // r11
  char v13; // r31

  m_pTwin = pForwardLink->m_pTwin;
  if ( (*((_BYTE *)pForwardLink + 44) & 0x80) == 0
    || (*((_BYTE *)pForwardLink + 44) & 0x40) != 0
    || (v4 = 1, (*((_BYTE *)pForwardLink + 44) & 0x20) != 0) )
  {
    v4 = 0;
  }
  v5 = v4;
  if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
    || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
    || (v6 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
  {
    v6 = 0;
  }
  v7 = v6;
  *((_BYTE *)pForwardLink + 44) = *((_BYTE *)pForwardLink + 44) & 0x7F | (enable << 7);
  v8 = *((_BYTE *)m_pTwin + 44) & 0x7F | (enable << 7);
  *((_BYTE *)m_pTwin + 44) = v8;
  if ( (*((_BYTE *)pForwardLink + 44) & 0x80) == 0
    || (*((_BYTE *)pForwardLink + 44) & 0x40) != 0
    || (v9 = 1, (*((_BYTE *)pForwardLink + 44) & 0x20) != 0) )
  {
    v9 = 0;
  }
  v11 = (v8 & 0x80) == 0;
  v10 = v9;
  if ( v11 || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0 || (v12 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
    v12 = 0;
  v13 = v12;
  if ( v5 != v10 )
    bfx::UpdateCachedDataForHLinkEnableOrDisable(pLink: pForwardLink, enable);
  if ( v7 != v13 )
    bfx::UpdateCachedDataForHLinkEnableOrDisable(pLink: m_pTwin, enable);
}


// ========================================================================
// ?RemoveLinkPair@bfx@@YAXPAVNavLayer@1@PAVHalfLink@1@@Z
// EA  : 0x8325B240
// RVA : 0x0125B240
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::RemoveLinkPair(bfx::NavLayer *pNavLayer, bfx::HalfLink *pLink)
{
  bfx::HalfLink *m_pTwin; // r30
  bfx::XGraph *m_pXGraph; // r29

  m_pTwin = pLink->m_pTwin;
  m_pXGraph = pNavLayer->m_pXGraph;
  if ( pLink->m_pXLinkChain != nullptr )
    ((void (__fastcall *)(bfx::XGraph *))m_pXGraph->UpdateForRemoveHLink)(a1: pNavLayer->m_pXGraph);
  if ( m_pTwin->m_pXLinkChain != nullptr )
    m_pXGraph->UpdateForRemoveHLink(this: m_pXGraph, a2: m_pTwin);
  bfx::Area::RemoveLink(this: pLink->m_pArea, pLinkToRemove: pLink);
  bfx::Area::RemoveLink(this: m_pTwin->m_pArea, pLinkToRemove: m_pTwin);
  ((void (__fastcall *)(bfx::HalfLink *, int))pLink->dtr_HandleTargetBase)(a1: pLink, a2: 1);
  ((void (__fastcall *)(bfx::HalfLink *, int))m_pTwin->dtr_HandleTargetBase)(a1: m_pTwin, a2: 1);
}


// ========================================================================
// ?IsDrawCulled@LinkImpl@bfx@@UBA_NABVDrawCullData@2@@Z
// EA  : 0x8325B2F0
// RVA : 0x0125B2F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

int __fastcall bfx::LinkImpl::IsDrawCulled(bfx::LinkImpl *this, const bfx::DrawCullData *drawCull)
{
  double v2; // fp12
  double v3; // fp8
  double v4; // fp4
  double v5; // fp3
  double m_maxSnapDist; // fp2
  double v7; // fp1
  double v8; // fp12
  int result; // r3
  bool v10; // zf
  bfx::Vec3 v11; // [sp+50h] [-20h] BYREF

  if ( !drawCull->m_useCulling )
    return 0;
  v2 = (float)(this->m_endPos.m_y - this->m_startPos.m_y);
  v3 = (float)(this->m_endPos.m_z - this->m_startPos.m_z);
  v4 = (float)(this->m_endPos.m_x - this->m_startPos.m_x);
  v5 = (float)(this->m_endPos.m_x + this->m_startPos.m_x);
  m_maxSnapDist = this->m_linkDat.m_maxSnapDist;
  v7 = (float)((float)v2 * (float)v2);
  v8 = (float)((float)(this->m_startPos.m_z + this->m_endPos.m_z) * (float)0.5);
  v11.m_y = (float)(this->m_startPos.m_y + this->m_endPos.m_y) * (float)0.5;
  v11.m_z = v8;
  v11.m_x = (float)v5 * (float)0.5;
  v10 = (unsigned __int8)bfx::DrawCullData::IsSphereCulled(
                           this: drawCull,
                           centerPos: &v11,
                           radius: (float)((float)__fsqrts((float)((float)((float)v4 * (float)v4)
                                                         + (float)((float)((float)v3 * (float)v3) + (float)v7)))
                                 + (float)m_maxSnapDist)) != 0;
  result = 1;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?GetOutputPos@LinkImpl@bfx@@UBA?AVVec3@2@ABV32@@Z
// EA  : 0x8325B3A8
// RVA : 0x0125B3A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkImpl *__fastcall bfx::LinkImpl::GetOutputPos(
        bfx::LinkImpl *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *inputPos)
{
  double v3; // fp10
  double v4; // fp9
  double v5; // fp1
  double v6; // fp5
  double v7; // fp4
  double v8; // fp0
  float m_z; // r11
  float m_x; // r10
  float m_y; // r9

  v3 = (float)(result[8].m_z - inputPos->m_x);
  v4 = (float)(result[10].m_x - inputPos->m_y);
  v5 = (float)(result[9].m_x - inputPos->m_y);
  v6 = (float)(result[9].m_y - inputPos->m_z);
  v7 = (float)(result[10].m_y - inputPos->m_z);
  v8 = (float)(result[9].m_z - inputPos->m_x);
  if ( __fsqrts((float)((float)((float)v5 * (float)v5)
                      + (float)((float)((float)v6 * (float)v6) + (float)((float)v3 * (float)v3)))) >= __fsqrts((float)((float)((float)v8 * (float)v8) + (float)((float)((float)v7 * (float)v7) + (float)((float)v4 * (float)v4)))) )
  {
    m_z = result[8].m_z;
    m_x = result[9].m_x;
    m_y = result[9].m_y;
  }
  else
  {
    m_z = result[9].m_z;
    m_x = result[10].m_x;
    m_y = result[10].m_y;
  }
  *(float *)&this->__vftable = m_z;
  *(float *)&this->m_pProxy = m_x;
  *(float *)&this->m_pPlanner = m_y;
  return this;
}


// ========================================================================
// ?IsDrawCulled@LinkStripImpl@bfx@@UBA_NABVDrawCullData@2@@Z
// EA  : 0x8325B448
// RVA : 0x0125B448
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

int __fastcall bfx::LinkStripImpl::IsDrawCulled(bfx::LinkStripImpl *this, const bfx::DrawCullData *drawCull)
{
  double m_y; // fp11
  double v3; // fp10
  double m_z; // fp5
  double v5; // fp4
  double m_x; // fp9
  double v7; // fp8
  double v8; // fp3
  double v9; // fp31
  double v10; // fp30
  double v11; // fp29
  double v12; // fp28
  double v13; // fp27
  double m_maxSnapDist; // fp26
  double v15; // fp1
  double v16; // fp12
  int result; // r3
  bool v24; // zf
  bfx::Vec3 v25; // [sp+50h] [-50h] BYREF

  if ( !drawCull->m_useCulling )
    return 0;
  m_y = this->m_end.m_v0.m_y;
  v3 = this->m_start.m_v0.m_y;
  m_z = this->m_end.m_v0.m_z;
  v5 = this->m_start.m_v0.m_z;
  m_x = this->m_end.m_v0.m_x;
  v7 = this->m_start.m_v0.m_x;
  v8 = this->m_end.m_v1.m_y;
  v9 = this->m_start.m_v1.m_y;
  v10 = this->m_end.m_v1.m_z;
  v11 = this->m_start.m_v1.m_z;
  v12 = this->m_end.m_v1.m_x;
  v13 = this->m_start.m_v1.m_x;
  m_maxSnapDist = this->m_linkDat.m_maxSnapDist;
  v15 = (float)((float)((float)(this->m_start.m_v0.m_x + this->m_start.m_v1.m_x) * (float)0.5)
              + (float)((float)(this->m_end.m_v0.m_x + this->m_end.m_v1.m_x) * (float)0.5));
  v16 = (float)((float)((float)((float)(this->m_start.m_v1.m_z + this->m_start.m_v0.m_z) * (float)0.5)
                      + (float)((float)(this->m_end.m_v1.m_z + this->m_end.m_v0.m_z) * (float)0.5))
              * (float)0.5);
  v25.m_y = (float)((float)((float)(this->m_start.m_v1.m_y + this->m_start.m_v0.m_y) * (float)0.5)
                  + (float)((float)(this->m_end.m_v1.m_y + this->m_end.m_v0.m_y) * (float)0.5))
          * (float)0.5;
  v25.m_z = v16;
  v25.m_x = (float)v15 * (float)0.5;
  _FP0 = (float)((float)((float)((float)(v25.m_x - (float)m_x) * (float)(v25.m_x - (float)m_x))
                       + (float)((float)((float)((float)v16 - (float)m_z) * (float)((float)v16 - (float)m_z))
                               + (float)((float)(v25.m_y - (float)m_y) * (float)(v25.m_y - (float)m_y))))
               - (float)((float)((float)(v25.m_x - (float)v12) * (float)(v25.m_x - (float)v12))
                       + (float)((float)((float)((float)v16 - (float)v10) * (float)((float)v16 - (float)v10))
                               + (float)((float)(v25.m_y - (float)v8) * (float)(v25.m_y - (float)v8)))));
  _FP13 = (float)((float)((float)((float)(v25.m_x - (float)v7) * (float)(v25.m_x - (float)v7))
                        + (float)((float)((float)((float)v16 - (float)v5) * (float)((float)v16 - (float)v5))
                                + (float)((float)(v25.m_y - (float)v3) * (float)(v25.m_y - (float)v3))))
                - (float)((float)((float)(v25.m_x - (float)v13) * (float)(v25.m_x - (float)v13))
                        + (float)((float)((float)((float)v16 - (float)v11) * (float)((float)v16 - (float)v11))
                                + (float)((float)(v25.m_y - (float)v9) * (float)(v25.m_y - (float)v9)))));
  __asm
  {
    fsel      f12, f0, f3, f4
    fsel      f11, f13, f1, f2
  }
  _FP10 = (float)((float)_FP11 - (float)_FP12);
  __asm { fsel      f9, f10, f11, f12 }
  v24 = (unsigned __int8)bfx::DrawCullData::IsSphereCulled(
                           this: drawCull,
                           centerPos: &v25,
                           radius: (float)((float)__fsqrts(_FP9) + (float)m_maxSnapDist)) != 0;
  result = 1;
  if ( !v24 )
    return 0;
  return result;
}


// ========================================================================
// ?GetOutputPos@LinkStripImpl@bfx@@UBA?AVVec3@2@ABV32@@Z
// EA  : 0x8325B5D8
// RVA : 0x0125B5D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkStripImpl *__fastcall bfx::LinkStripImpl::GetOutputPos(
        bfx::LinkStripImpl *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *inputPos)
{
  const bfx::LineSeg *p_m_z; // r30
  const bfx::LineSeg *v6; // r31
  double DistPtToLineSeg; // fp31
  BOOL v8; // r8
  const bfx::LineSeg *v9; // r11
  char *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  const bfx::LineSeg *v13; // r11
  char *v14; // r10
  _DWORD *v15; // r11
  int j; // ctr
  double v17; // fp11
  double v18; // fp0
  double v20; // fp12
  double v21; // fp11
  double v22; // fp3
  double v23; // fp2
  char v24; // [sp+4Ch] [-74h] BYREF
  float v25; // [sp+50h] [-70h]
  float v26; // [sp+54h] [-6Ch]
  float v27; // [sp+58h] [-68h]
  float v28; // [sp+5Ch] [-64h]
  float v29; // [sp+60h] [-60h]
  float v30; // [sp+64h] [-5Ch]
  char v31; // [sp+6Ch] [-54h] BYREF
  float v32; // [sp+70h] [-50h]
  float v33; // [sp+74h] [-4Ch]
  float v34; // [sp+78h] [-48h]
  float v35; // [sp+7Ch] [-44h]
  float v36; // [sp+80h] [-40h]
  float v37; // [sp+84h] [-3Ch]

  p_m_z = (const bfx::LineSeg *)&result[8].m_z;
  v6 = (const bfx::LineSeg *)&result[10].m_z;
  DistPtToLineSeg = bfx::GetDistPtToLineSeg(pos: inputPos, seg: (const bfx::LineSeg *)&result[8].m_z);
  v8 = DistPtToLineSeg < bfx::GetDistPtToLineSeg(pos: inputPos, seg: v6);
  v9 = p_m_z;
  if ( !v8 )
    v9 = v6;
  v10 = &v24;
  v11 = (_DWORD *)&v9[-1].m_v1.m_z;
  for ( i = 6; i != 0; --i )
  {
    ++v11;
    v10 += 4;
    *(_DWORD *)v10 = *v11;
  }
  v13 = v6;
  if ( !v8 )
    v13 = p_m_z;
  v14 = &v31;
  v15 = (_DWORD *)&v13[-1].m_v1.m_z;
  for ( j = 6; j != 0; --j )
  {
    ++v15;
    v14 += 4;
    *(_DWORD *)v14 = *v15;
  }
  v17 = __fsqrts((float)((float)((float)(v29 - v26) * (float)(v29 - v26))
                       + (float)((float)((float)(v30 - v27) * (float)(v30 - v27))
                               + (float)((float)(v28 - v25) * (float)(v28 - v25)))));
  if ( v17 <= 1.0842022e-19 )
    v18 = 0.0;
  else
    v18 = (float)((float)((float)((float)(inputPos->m_x - v25) * (float)(v28 - v25))
                        + (float)((float)((float)(inputPos->m_z - v27) * (float)(v30 - v27))
                                + (float)((float)(inputPos->m_y - v26) * (float)(v29 - v26))))
                / (float)((float)v17 * (float)v17));
  v20 = v33;
  v21 = v34;
  v22 = (float)((float)(v36 - v33) * (float)v18);
  v23 = (float)((float)(v37 - v34) * (float)v18);
  *(float *)&this->__vftable = (float)((float)(v35 - v32) * (float)v18) + v32;
  *(float *)&this->m_pProxy = (float)v22 + (float)v20;
  *(float *)&this->m_pPlanner = (float)v23 + (float)v21;
  return this;
}


// ========================================================================
// ?GetLinkOutputPos@bfx@@YA?AVVec3@1@PAVHalfLink@1@ABV21@@Z
// EA  : 0x8325B760
// RVA : 0x0125B760
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetLinkOutputPos(bfx::Vec3 *result, bfx::HalfLink *pLink, const bfx::Vec3 *posOnLinkStart)
{
  bfx::HalfLink *m_pTwin; // r11
  const bfx::Area *m_pArea; // r4
  bfx::Vec3 v8[2]; // [sp+50h] [-30h] BYREF

  ((void (__fastcall *)(bfx::Vec3 *))pLink->m_pLinkBase->GetOutputPos)(a1: result);
  m_pTwin = pLink->m_pTwin;
  if ( m_pTwin != nullptr )
    m_pArea = m_pTwin->m_pArea;
  else
    m_pArea = nullptr;
  *result = *bfx::GetClosestPosInArea(result: v8, pArea: m_pArea, pos: result, pEdgeIndexOut: nullptr);
  return result;
}


// ========================================================================
// ?ClipLineSegAgainstArea@bfx@@YA_NPAVArea@1@MABVLineSeg@1@AAVAreaSeg@1@@Z
// EA  : 0x8325B7F0
// RVA : 0x0125B7F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

int __fastcall bfx::ClipLineSegAgainstArea(
        bfx::Vec3 *pArea,
        double tol,
        const bfx::LineSeg *seg,
        const bfx::LineSeg *areaSegOut,
        int a5)
{
  double v5; // fp11
  double v7; // fp8
  double v8; // fp6
  signed int v12; // r31
  signed int v13; // r11
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  bfx::Vec3 *v17; // r30
  bfx::Vec3 *v18; // r11
  float m_y; // r9
  float m_z; // r8
  double v21; // fp2
  double v22; // fp10
  double v23; // fp8
  float v26; // r10
  float v27; // r9
  double v28; // fp28
  int v30; // r7
  float v31; // r5
  float v32; // [sp+50h] [-F0h] BYREF
  float v33; // [sp+54h] [-ECh] BYREF
  bfx::Area v34; // [sp+58h] [-E8h] BYREF
  bfx::Vec3 v35; // [sp+90h] [-B0h] BYREF
  int v36; // [sp+9Ch] [-A4h]
  bfx::Plane v37; // [sp+A0h] [-A0h] BYREF
  bfx::Plane v38; // [sp+B0h] [-90h] BYREF
  bfx::Plane v39; // [sp+C0h] [-80h] BYREF

  v5 = (float)(areaSegOut->m_v1.m_x - areaSegOut->m_v0.m_x);
  v7 = (float)(areaSegOut->m_v1.m_y - areaSegOut->m_v0.m_y);
  v8 = (float)(areaSegOut->m_v1.m_z - areaSegOut->m_v0.m_z);
  v32 = 1.0;
  v33 = 0.0;
  v35.m_x = v5;
  v35.m_y = v7;
  v35.m_z = v8;
  bfx::Area::CalcNormal(this: &v34, result: pArea);
  v12 = 0;
  v13 = LODWORD(pArea[3].m_y) & 0x7F;
  v14 = *(float *)&v34.m_pFirstLink;
  v15 = *(float *)&v34.m_dynAreaData.m_data;
  v16 = *(float *)&v34.m_pProxy;
  if ( v13 != 0 )
  {
    v17 = pArea + 5;
    while ( 1 )
    {
      ++v12;
      v34.m_pos = *v17;
      __twllei(v13, 0);
      __twlgei(v13 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
      v18 = &pArea[2 * (v12 % v13)];
      m_y = v18[5].m_y;
      m_z = v18[5].m_z;
      v34.m_searchCost = LODWORD(v18[5].m_x);
      *(float *)&v34.m_usageFlags = m_y;
      *(float *)&v34.m_flags.m_flags1 = m_z;
      v21 = (float)((float)((float)v14 * (float)(*(float *)&v34.m_searchCost - v34.m_pos.m_x))
                  - (float)((float)(m_z - v34.m_pos.m_z) * (float)v16));
      v22 = (float)((float)((float)(m_y - v34.m_pos.m_y) * (float)v16)
                  - (float)((float)v15 * (float)(*(float *)&v34.m_searchCost - v34.m_pos.m_x)));
      v23 = (float)((float)((float)v15 * (float)(m_z - v34.m_pos.m_z))
                  - (float)((float)v14 * (float)(m_y - v34.m_pos.m_y)));
      _FP4 = (float)((float)__fsqrts((float)((float)((float)v23 * (float)v23)
                                           + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))))
                   - (float)1.0842022e-19);
      __asm { fsel      f1, f4, f3, f27 }
      v37.m_normal.m_z = (float)((float)((float)(m_y - v34.m_pos.m_y) * (float)v16)
                               - (float)((float)v15 * (float)(*(float *)&v34.m_searchCost - v34.m_pos.m_x)))
                       * (float)_FP1;
      v37.m_normal.m_x = (float)((float)((float)v15 * (float)(m_z - v34.m_pos.m_z))
                               - (float)((float)v14 * (float)(m_y - v34.m_pos.m_y)))
                       * (float)_FP1;
      v37.m_normal.m_y = (float)((float)((float)v14 * (float)(*(float *)&v34.m_searchCost - v34.m_pos.m_x))
                               - (float)((float)(m_z - v34.m_pos.m_z) * (float)v16))
                       * (float)_FP1;
      v37.m_d = (float)(v37.m_normal.m_x * v34.m_pos.m_x)
              + (float)((float)(v37.m_normal.m_y * v34.m_pos.m_y) + (float)(v37.m_normal.m_z * v34.m_pos.m_z));
      if ( !bfx::ClipLineSegAgainstPlane(plane: &v37, seg: areaSegOut, segVec: &v35, minS: &v33, maxS: &v32) )
        break;
      v17 += 2;
      v13 = LODWORD(pArea[3].m_y) & 0x7F;
      if ( v12 >= v13 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v26 = pArea[1].m_y;
    v27 = pArea[1].m_z;
    v34.m_flags.m_flags1 = LODWORD(pArea[2].m_x);
    *(float *)&v34.m_searchCost = v26;
    *(float *)&v34.m_usageFlags = v27;
    LODWORD(v38.m_normal.m_x) = v34.m_pProxy;
    LODWORD(v38.m_normal.m_y) = v34.m_dynAreaData.m_data;
    LODWORD(v38.m_normal.m_z) = v34.m_pFirstLink;
    v28 = (float)((float)(v26 * (float)v16)
                + (float)((float)(*(float *)&v34.m_flags.m_flags1 * (float)v14) + (float)(v27 * (float)v15)));
    v38.m_d = (float)((float)(v26 * (float)v16)
                    + (float)((float)(*(float *)&v34.m_flags.m_flags1 * (float)v14) + (float)(v27 * (float)v15)))
            - (float)tol;
    if ( bfx::ClipLineSegAgainstPlane(plane: &v38, seg: areaSegOut, segVec: &v35, minS: &v33, maxS: &v32) )
    {
      *(float *)&v34.m_searchCost = -v16;
      *(float *)&v34.m_usageFlags = -v15;
      *(float *)&v34.m_flags.m_flags1 = -v14;
      v39.m_normal = *(bfx::Vec3 *)&v34.m_searchCost;
      v39.m_d = (float)-v28 - (float)tol;
      if ( bfx::ClipLineSegAgainstPlane(plane: &v39, seg: areaSegOut, segVec: &v35, minS: &v33, maxS: &v32) )
      {
        LODWORD(v35.m_x) = pArea;
        v35.m_z = v32;
        v35.m_y = v33;
        v36 &= ~0x80000000;
        v30 = v36;
        v31 = v32;
        *(float *)(a5 + 4) = v33;
        *(float *)(a5 + 8) = v31;
        *(_DWORD *)a5 = pArea;
        *(_DWORD *)(a5 + 12) = v30;
        return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?SnapSegmentIntoArea@bfx@@YA_NPAVArea@1@MABVLineSeg@1@1AAVAreaSeg@1@@Z
// EA  : 0x8325BAF8
// RVA : 0x0125BAF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

int __fastcall bfx::SnapSegmentIntoArea(
        bfx::Area *pArea,
        double tol,
        const bfx::LineSeg *closeSeg,
        const bfx::LineSeg *farSeg,
        const bfx::LineSeg *areaSegOut,
        int a6)
{
  bfx::Vec3 *p_m_v1; // r29
  double DistPtToLineSeg; // fp31
  double v13; // fp1
  double v14; // fp31
  double v15; // fp1
  double v16; // fp10
  double v17; // fp8
  double v18; // fp10
  double v19; // fp10
  double v20; // fp0
  double v21; // fp13
  int v31; // r7
  float m_y; // r5
  bfx::Vec3 v33; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v34; // [sp+60h] [-50h] BYREF
  int v35; // [sp+6Ch] [-44h]

  p_m_v1 = &farSeg->m_v1;
  bfx::GetClosestPosInArea(result: &v33, pArea, pos: &farSeg->m_v0, pEdgeIndexOut: nullptr);
  bfx::GetClosestPosInArea(result: &v34, pArea, pos: &farSeg->m_v1, pEdgeIndexOut: nullptr);
  DistPtToLineSeg = bfx::GetDistPtToLineSeg(pos: &v33, seg: farSeg);
  v13 = bfx::GetDistPtToLineSeg(pos: &v33, seg: areaSegOut);
  if ( DistPtToLineSeg > tol )
    return 0;
  if ( DistPtToLineSeg > v13 )
    return 0;
  v14 = bfx::GetDistPtToLineSeg(pos: &v34, seg: farSeg);
  v15 = bfx::GetDistPtToLineSeg(pos: &v34, seg: areaSegOut);
  if ( v14 > tol )
    return 0;
  if ( v14 > v15 )
    return 0;
  v16 = (float)(farSeg->m_v1.m_y - farSeg->m_v0.m_y);
  v17 = (float)(farSeg->m_v1.m_z - farSeg->m_v0.m_z);
  v18 = __fsqrts((float)((float)((float)v17 * (float)v17)
                       + (float)((float)((float)v16 * (float)v16)
                               + (float)((float)(p_m_v1->m_x - farSeg->m_v0.m_x)
                                       * (float)(p_m_v1->m_x - farSeg->m_v0.m_x)))));
  if ( v18 < 1.0842022e-19 )
    return 0;
  v19 = (float)((float)1.0 / (float)v18);
  v20 = (float)((float)((float)((float)(v33.m_x - farSeg->m_v0.m_x)
                              * (float)((float)v19 * (float)(farSeg->m_v1.m_x - farSeg->m_v0.m_x)))
                      + (float)((float)((float)(v33.m_z - farSeg->m_v0.m_z)
                                      * (float)((float)v19 * (float)(farSeg->m_v1.m_z - farSeg->m_v0.m_z)))
                              + (float)((float)(v33.m_y - farSeg->m_v0.m_y)
                                      * (float)((float)v19 * (float)(farSeg->m_v1.m_y - farSeg->m_v0.m_y)))))
              * (float)v19);
  v21 = (float)((float)((float)((float)(v34.m_x - farSeg->m_v0.m_x)
                              * (float)((float)v19 * (float)(farSeg->m_v1.m_x - farSeg->m_v0.m_x)))
                      + (float)((float)((float)(v34.m_z - farSeg->m_v0.m_z)
                                      * (float)((float)v19 * (float)(farSeg->m_v1.m_z - farSeg->m_v0.m_z)))
                              + (float)((float)(v34.m_y - farSeg->m_v0.m_y)
                                      * (float)((float)v19 * (float)(farSeg->m_v1.m_y - farSeg->m_v0.m_y)))))
              * (float)v19);
  if ( v20 > v21 )
  {
    v20 = (float)((float)((float)((float)(v34.m_x - farSeg->m_v0.m_x)
                                * (float)((float)v19 * (float)(farSeg->m_v1.m_x - farSeg->m_v0.m_x)))
                        + (float)((float)((float)(v34.m_z - farSeg->m_v0.m_z)
                                        * (float)((float)v19 * (float)(farSeg->m_v1.m_z - farSeg->m_v0.m_z)))
                                + (float)((float)(v34.m_y - farSeg->m_v0.m_y)
                                        * (float)((float)v19 * (float)(farSeg->m_v1.m_y - farSeg->m_v0.m_y)))))
                * (float)v19);
    v21 = (float)((float)((float)((float)(v33.m_x - farSeg->m_v0.m_x)
                                * (float)((float)v19 * (float)(farSeg->m_v1.m_x - farSeg->m_v0.m_x)))
                        + (float)((float)((float)(v33.m_z - farSeg->m_v0.m_z)
                                        * (float)((float)v19 * (float)(farSeg->m_v1.m_z - farSeg->m_v0.m_z)))
                                + (float)((float)(v33.m_y - farSeg->m_v0.m_y)
                                        * (float)((float)v19 * (float)(farSeg->m_v1.m_y - farSeg->m_v0.m_y)))))
                * (float)v19);
  }
  _FP9 = -v20;
  _FP8 = -v21;
  _FP7 = (float)((float)1.0 - (float)v20);
  _FP6 = (float)((float)1.0 - (float)v21);
  __asm
  {
    fsel      f5, f9, f11, f0
    fsel      f4, f8, f11, f13
  }
  __asm
  {
    fsel      f0, f7, f3, f12
    fsel      f13, f6, f2, f12
  }
  if ( (float)((float)_FP13 - (float)_FP0) < 0.001 )
    return 0;
  v34.m_y = _FP0;
  LODWORD(v34.m_x) = pArea;
  v34.m_z = _FP13;
  v35 &= ~0x80000000;
  v31 = v35;
  m_y = v34.m_y;
  *(float *)(a6 + 8) = v34.m_z;
  *(float *)(a6 + 4) = m_y;
  *(_DWORD *)a6 = pArea;
  *(_DWORD *)(a6 + 12) = v31;
  return 1;
}


// ========================================================================
// ?DrawPanelBetweenLineSegs@bfx@@YAXPBVSpace@1@ABVLineSeg@1@1ABVColor@1@@Z
// EA  : 0x8325BD20
// RVA : 0x0125BD20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::DrawPanelBetweenLineSegs(
        bfx::Space *pSpace,
        const bfx::LineSeg *start,
        const bfx::LineSeg *end,
        const bfx::Color *color)
{
  float m_r; // r11
  float m_g; // r9
  float m_b; // r7
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  bfx::Vec3 *p_m_v1; // r28
  double v18; // fp6
  double v19; // fp5
  double v20; // fp4
  double v21; // fp3
  double v22; // fp2
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  double v26; // fp11
  double v27; // fp10
  double v28; // fp8
  double v29; // fp7
  double v30; // fp6
  double v31; // fp5
  bfx::Color v32; // [sp+50h] [-C0h] BYREF
  bfx::Vec3 v33; // [sp+60h] [-B0h] BYREF
  float v34; // [sp+6Ch] [-A4h]
  float v35; // [sp+70h] [-A0h]
  float v36; // [sp+74h] [-9Ch]
  bfx::Vec3 v37; // [sp+80h] [-90h] BYREF
  float v38; // [sp+8Ch] [-84h]
  float v39; // [sp+90h] [-80h]
  float v40; // [sp+94h] [-7Ch]
  bfx::Vec3 v41; // [sp+A0h] [-70h] BYREF
  float v42; // [sp+ACh] [-64h]
  float v43; // [sp+B0h] [-60h]
  float v44; // [sp+B4h] [-5Ch]
  bfx::Vec3 v45; // [sp+C0h] [-50h] BYREF
  float v46; // [sp+CCh] [-44h]
  float v47; // [sp+D0h] [-40h]
  float v48; // [sp+D4h] [-3Ch]

  m_r = color->m_r;
  m_g = color->m_g;
  m_b = color->m_b;
  m_x = start->m_v0.m_x;
  m_y = start->m_v0.m_y;
  m_z = start->m_v0.m_z;
  v13 = start->m_v1.m_x;
  v32.m_a = color->m_a;
  v14 = start->m_v1.m_y;
  v32.m_r = m_r;
  v15 = start->m_v1.m_z;
  v32.m_g = m_g;
  v32.m_b = m_b;
  v33.m_x = m_x;
  v33.m_y = m_y;
  v33.m_z = m_z;
  v34 = v13;
  p_m_v1 = &start->m_v1;
  v35 = v14;
  v36 = v15;
  v32.m_a = 0.25;
  bfx::DrawLineList(pSpace, pVerts: &v33, numVerts: 2, color);
  v18 = end->m_v0.m_y;
  v19 = end->m_v0.m_z;
  v20 = end->m_v1.m_x;
  v21 = end->m_v1.m_y;
  v22 = end->m_v1.m_z;
  v37.m_x = end->m_v0.m_x;
  v37.m_y = v18;
  v37.m_z = v19;
  v38 = v20;
  v39 = v21;
  v40 = v22;
  bfx::DrawLineList(pSpace, pVerts: &v37, numVerts: 2, color);
  v23 = start->m_v0.m_y;
  v24 = start->m_v0.m_z;
  v25 = end->m_v0.m_x;
  v26 = end->m_v0.m_y;
  v27 = end->m_v0.m_z;
  v41.m_x = start->m_v0.m_x;
  v41.m_y = v23;
  v41.m_z = v24;
  v42 = v25;
  v43 = v26;
  v44 = v27;
  bfx::DrawLineList(pSpace, pVerts: &v41, numVerts: 2, color);
  v28 = start->m_v1.m_y;
  v29 = start->m_v1.m_z;
  v30 = end->m_v1.m_x;
  v31 = end->m_v1.m_y;
  v45.m_x = start->m_v1.m_x;
  v45.m_y = v28;
  v45.m_z = v29;
  v46 = v30;
  v47 = v31;
  v48 = end->m_v1.m_z;
  bfx::DrawLineList(pSpace, pVerts: &v45, numVerts: 2, color);
  bfx::DrawSolidTri((bfx::Vector3 *)pSpace, v0: &start->m_v0, v1: &end->m_v1, v2: p_m_v1, color: &v32);
  bfx::DrawSolidTri((bfx::Vector3 *)pSpace, v0: &start->m_v0, v1: &end->m_v0, v2: &end->m_v1, color: &v32);
  bfx::DrawSolidTri((bfx::Vector3 *)pSpace, v0: &start->m_v0, v1: p_m_v1, v2: &end->m_v1, color: &v32);
  bfx::DrawSolidTri((bfx::Vector3 *)pSpace, v0: &start->m_v0, v1: &end->m_v1, v2: &end->m_v0, color: &v32);
}


// ========================================================================
// ?ApplyLimits_LinkDat@bfx@@YAXAAVLinkDat@1@@Z
// EA  : 0x8325BEE8
// RVA : 0x0125BEE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_LinkDat(bfx::LinkDat *linkDat, int a2, int a3, int a4, __int64 a5)
{
  bfx::LinkDat *v5; // r31
  __int64 v6; // r10
  double v7; // fp1
  double Scale; // fp1
  unsigned int m_maxSimultaneous; // r10
  bfx::LinkDat v22; // [sp+50h] [-70h] BYREF

  v5 = linkDat;
  if ( linkDat->m_maxSnapDist < 0.0 )
  {
    linkDat = bfx::LinkDat::LinkDat(this: &v22);
    v5->m_maxSnapDist = linkDat->m_maxSnapDist;
  }
  if ( v5->m_mayUseDist < 0.0 )
  {
    linkDat = bfx::LinkDat::LinkDat(this: &v22);
    v5->m_mayUseDist = linkDat->m_mayUseDist;
  }
  LODWORD(v6) = &MAX_FLOAT_13;
  HIDWORD(v6) = &unk_82410000;
  v7 = bfx::LimitWarn(
         val: v5->m_penaltyMult,
         min: 0.1,
         max: 15.0,
         name: (const char *)linkDat,
         a5: a2,
         a6: a3,
         a7: (unsigned int)"LinkDat::m_penaltyMult",
         a8: a5,
         a9: v6);
  _FP12 = -v5->m_maxSnapDist;
  _FP11 = (float)(3.4028235e38 - v5->m_maxSnapDist);
  v5->m_penaltyMult = v7;
  __asm { fsel      f10, f12, f29, f13 }
  __asm { fsel      f8, f11, f9, f31 }
  v5->m_maxSnapDist = _FP8;
  Scale = bfx::GetScale();
  m_maxSimultaneous = v5->m_flowTune.m_maxSimultaneous;
  _FP3 = -v5->m_mustUseDist;
  _FP2 = (float)(3.4028235e38 - v5->m_mayUseDist);
  _FP0 = (float)((float)((float)Scale * (float)0.1) - v5->m_mayUseDist);
  _FP1 = (float)(3.4028235e38 - v5->m_mustUseDist);
  __asm
  {
    fsel      f13, f3, f29, f4
    fsel      f12, f0, f6, f5
  }
  __asm
  {
    fsel      f9, f1, f11, f31
    fsel      f8, f2, f10, f31
  }
  v5->m_mustUseDist = _FP9;
  v5->m_mayUseDist = _FP8;
  if ( m_maxSimultaneous <= 0x7FFFFFFF )
    v5->m_flowTune.m_maxSimultaneous = m_maxSimultaneous;
  else
    v5->m_flowTune.m_maxSimultaneous = 0x7FFFFFFF;
}


// ========================================================================
// ?DestroyLink@bfx@@YAXAAVLinkHandle@1@@Z
// EA  : 0x8325C048
// RVA : 0x0125C048
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::DestroyLink(bfx::LinkHandle *link)
{
  bfx::SystemInstance *v2; // r11
  bfx::LinkBase **m_pProxy; // r30
  int v4; // r10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  m_pProxy = (bfx::LinkBase **)link->m_pProxy;
  if ( link->m_pProxy != nullptr )
  {
    v4 = (int)((_DWORD)m_pProxy[1] << 24) >> 28;
    if ( v4 == 2 )
    {
      bfx::DestroyLinkInternal(pLinkBase: *m_pProxy);
    }
    else if ( v4 == 1 )
    {
      v2->m_pSystemMCore->DeleteTaskForProxy(this: v2->m_pSystemMCore, a2: (bfx::HandleProxy *)link->m_pProxy);
      if ( m_pProxy != nullptr )
        m_pProxy[1] = (bfx::LinkBase *)((unsigned int)m_pProxy[1] & 0xFFFFFF0F | 0x40);
    }
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$85274
// EA  : 0x8325C100
// RVA : 0x0125C100
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85274()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??1LinkBase@bfx@@UAA@XZ
// EA  : 0x8325C1C0
// RVA : 0x0125C1C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::~LinkBase(bfx::LinkBase *this)
{
  bfx::LinkFlowBase *m_pLinkFlow; // r3
  bfx::HalfLink **m_data; // r4

  this->__vftable = (bfx::LinkBase_vtbl *)&bfx::LinkBase::`vftable';
  m_pLinkFlow = this->m_pLinkFlow;
  if ( m_pLinkFlow != nullptr )
    ((void (__fastcall *)(bfx::LinkFlowBase *, int))m_pLinkFlow->dtr_LinkFlowBase)(a1: m_pLinkFlow, a2: 1);
  this->m_pLinkFlow = nullptr;
  m_data = this->m_links.m_data;
  this->m_links.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_links.m_data = nullptr;
  }
  this->m_links.m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$85756
// EA  : 0x8325C244
// RVA : 0x0125C244
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85756()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$85757
// EA  : 0x8325C26C
// RVA : 0x0125C26C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85757()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 12));
}


// ========================================================================
// ?CalcAreaSegs@bfx@@YAXABVLineSeg@1@0MPAVNavLayer@1@AAV?$Array@VAreaSeg@bfx@@@1@@Z
// EA  : 0x8325C2A0
// RVA : 0x0125C2A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::CalcAreaSegs(
        const bfx::LineSeg *origSeg,
        const bfx::LineSeg *farSeg,
        double tol,
        bfx::NavLayer *pNavLayer,
        bfx::NavLayer *segs,
        bfx::Array<bfx::ResourceManager::Registration> *a6)
{
  double m_x; // fp13
  double v7; // fp12
  double v10; // fp2
  double v11; // fp6
  double m_z; // fp7
  double v13; // fp5
  double v14; // fp3
  bfx::SpaceComponent **m_data; // r21
  int m_size; // r25
  int m_cap; // r29
  int v32; // r28
  int v33; // r27
  char v34; // r11
  bfx::Vec3 *v35; // r30
  const bfx::LineSeg *v36; // r4
  int v37; // r4
  int v38; // r10
  bool (__fastcall *v39)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *); // r11
  int *p_m_size; // r24
  bool (__fastcall *v41)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *); // r26
  char *v42; // r30
  bfx::Area *v43; // r27
  int v44; // r29
  int v45; // r29
  int v46; // r30
  bfx::ResourceManager::Registration *v47; // r4
  int v48; // r10
  int v49; // r8
  bfx::ResourceManager::Registration *v50; // r27
  int v51; // r7
  int v52; // r5
  bfx::SystemInstance *v53; // r6
  bfx::ComponentManager *m_pComponentManager; // r4
  int v55; // r10
  double v56; // fp0
  int v57; // r11
  bfx::Area **v58; // r30
  int v59; // r29
  int v60; // r8
  double v61; // fp12
  double v62; // fp11
  int v63; // r9
  bool v64; // cr57
  bfx::ResourceManager::Registration *v65; // r7
  int v66; // r10
  bfx::ResourceManager::Registration v71; // [sp+60h] [-540h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v72; // [sp+70h] [-530h] BYREF
  bfx::Array<bfx::SpaceComponent *> v73; // [sp+80h] [-520h] BYREF
  bfx::Array<bfx::NavGraph *> v74; // [sp+90h] [-510h] BYREF
  bfx::Sphere v75; // [sp+A0h] [-500h] BYREF
  bfx::Box v76; // [sp+B0h] [-4F0h] BYREF
  bfx::ActiveAreasInSphereCursor v77; // [sp+D0h] [-4D0h] BYREF

  m_x = origSeg->m_v1.m_x;
  v7 = origSeg->m_v0.m_x;
  _FP9 = (float)(origSeg->m_v0.m_x - origSeg->m_v1.m_x);
  v10 = (float)(origSeg->m_v1.m_x - origSeg->m_v0.m_x);
  v11 = (float)(origSeg->m_v1.m_y - origSeg->m_v0.m_y);
  m_z = origSeg->m_v1.m_z;
  v13 = origSeg->m_v0.m_z;
  v14 = (float)(origSeg->m_v0.m_z + origSeg->m_v1.m_z);
  _FP30 = (float)(origSeg->m_v0.m_y - origSeg->m_v1.m_y);
  _FP29 = _FP30;
  _FP28 = (float)(origSeg->m_v0.m_z - origSeg->m_v1.m_z);
  _FP11 = _FP9;
  __asm { fsel      f9, f9, f13, f12 }
  *(float *)&v71.m_initCB = (float)(origSeg->m_v0.m_y + origSeg->m_v1.m_y) * (float)0.5;
  *(float *)&v71.m_termCB = (float)v14 * (float)0.5;
  _FP4 = _FP28;
  __asm { fsel      f30, f30, f8, f10 }
  __asm { fsel      f29, f29, f10, f8 }
  __asm { fsel      f28, f28, f5, f7 }
  __asm { fsel      f11, f11, f12, f13 }
  memset(&v74, 0, 12);
  __asm { fsel      f8, f4, f7, f5 }
  *(float *)&v72.m_size = (float)_FP30 + (float)tol;
  *(float *)&v71.m_id = (float)((float)v7 + (float)m_x) * (float)0.5;
  *(float *)&v72.m_cap = (float)_FP28 + (float)tol;
  *(float *)&v72.m_data = (float)_FP11 + (float)tol;
  v74.m_tag = bfx::MEM_BFXPLANNER;
  v75.m_pos = *(bfx::Vec3 *)&v71.m_id;
  v75.m_radius = (float)((float)__fsqrts((float)((float)((float)((float)m_z - (float)v13)
                                                       * (float)((float)m_z - (float)v13))
                                               + (float)((float)((float)v10 * (float)v10)
                                                       + (float)((float)v11 * (float)v11))))
                       * (float)0.5)
               + (float)tol;
  v76.m_max.m_x = *(float *)&v72.m_data;
  v76.m_min.m_x = (float)_FP9 - (float)tol;
  v76.m_max.m_y = *(float *)&v72.m_size;
  v76.m_min.m_y = (float)_FP29 - (float)tol;
  v76.m_max.m_z = *(float *)&v72.m_cap;
  v76.m_min.m_z = (float)_FP8 - (float)tol;
  bfx::NavLayer::GetNavGraphsIntersectingBox(this: segs, box: &v76, navGraphsOut: &v74);
  m_data = nullptr;
  memset(&v73, 0, 12);
  m_size = 0;
  m_cap = 0;
  v73.m_tag = bfx::MEM_BFXPLANNER;
  v32 = 0;
  if ( v74.m_size > 0 )
  {
    v33 = 0;
    do
    {
      bfx::ActiveAreasInSphereCursor::ActiveAreasInSphereCursor(this: &v77, sphere: &v75, pNavGraph: v74.m_data[v33]);
      while ( 1 )
      {
        if ( !v77.m_staticAreaCursor.m_atEnd
          || (v34 = 1, v77.m_allocatedAreasCC.m_i < v77.m_allocatedAreasCC.m_pArray->m_size) )
        {
          v34 = 0;
        }
        if ( v34 != 0 )
          break;
        v35 = (bfx::Vec3 *)bfx::ActiveAreasInSphereCursor::operator*(this: &v77);
        if ( m_cap == m_size )
        {
          v37 = 2 * m_cap;
          if ( m_cap == 0 )
            v37 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: &v73, size: v37);
          m_size = v73.m_size;
          m_data = v73.m_data;
          m_cap = v73.m_cap;
        }
        if ( &m_data[m_size] != nullptr )
          m_data[m_size] = (bfx::SpaceComponent *)v35;
        v73.m_size = ++m_size;
        if ( (unsigned __int8)bfx::ClipLineSegAgainstArea(pArea: v35, tol, seg: v36, areaSegOut: origSeg, a5: (int)&v72) != 0 )
          bfx::Array<bfx::Plane>::push_back(this: a6, val: (const bfx::ResourceManager::Registration *)&v72);
        bfx::ActiveAreasInSphereCursor::operator++(this: &v77);
      }
      ++v32;
      ++v33;
    }
    while ( v32 < v74.m_size );
  }
  v38 = a6->m_size;
  v39 = nullptr;
  p_m_size = &a6->m_size;
  v71.m_id = (unsigned int)a6;
  v71.m_initCB = nullptr;
  if ( v38 > 0 )
  {
    do
    {
      v41 = (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))((char *)v39 + 1);
      v42 = (char *)v39 + 1;
      v43 = (bfx::Area *)&a6->m_data[(_DWORD)v39];
      if ( (int)v39 + 1 < *(_DWORD *)(v71.m_id + 4) )
      {
        v44 = 16 * (_DWORD)v41;
        do
        {
          bfx::RemoveOverlapBetweenSegments(origSeg, segA: v43, segB: (bfx::AreaSeg *)(v44 + *(_DWORD *)v71.m_id));
          ++v42;
          v44 += 16;
        }
        while ( (int)v42 < *(_DWORD *)(v71.m_id + 4) );
      }
      v39 = v41;
      v38 = *p_m_size;
      v71.m_initCB = v41;
    }
    while ( (int)v41 < v38 );
  }
  memset(&v72, 0, 12);
  v72.m_tag = MEM_TEMP;
  v45 = 0;
  if ( v38 > 0 )
  {
    v46 = 0;
    do
    {
      v47 = &a6->m_data[v46];
      if ( (float)(*(float *)&v47->m_termCB - *(float *)&v47->m_initCB) > 0.001 )
        bfx::Array<bfx::Plane>::push_back(this: &v72, val: v47);
      ++v45;
      ++v46;
    }
    while ( v45 < *p_m_size );
  }
  v48 = v72.m_size;
  v49 = v72.m_cap;
  v50 = a6->m_data;
  a6->m_data = v72.m_data;
  v51 = *p_m_size;
  *p_m_size = v48;
  v52 = a6->m_cap;
  a6->m_cap = v49;
  v53 = bfx::g_pCurInstance;
  v72.m_data = v50;
  v72.m_size = v51;
  v72.m_cap = v52;
  m_pComponentManager = bfx::g_pCurInstance->m_pComponentManager;
  if ( HIBYTE(m_pComponentManager->m_components[1][13].__vftable) != 0 )
  {
    v55 = 0;
    v56 = 1.0;
    if ( *p_m_size <= 0 )
      goto LABEL_33;
    v57 = 0;
    do
    {
      ++v55;
      v56 = (float)((float)v56 - (float)(*(float *)&a6->m_data[v57].m_termCB - *(float *)&a6->m_data[v57].m_initCB));
      ++v57;
    }
    while ( v55 < *p_m_size );
    if ( v56 > 0.1 )
    {
LABEL_33:
      if ( m_size > 0 )
      {
        v58 = (bfx::Area **)m_data;
        v59 = m_size;
        while ( 1 )
        {
          if ( (unsigned __int8)bfx::SnapSegmentIntoArea(
                                  pArea: *v58,
                                  tol,
                                  closeSeg: (const bfx::LineSeg *)m_pComponentManager,
                                  farSeg: origSeg,
                                  areaSegOut: farSeg,
                                  a6: (int)&v71) != 0 )
          {
            v60 = *p_m_size;
            v61 = *(float *)&v71.m_termCB;
            v62 = *(float *)&v71.m_initCB;
            v63 = 0;
            v64 = *p_m_size > 0;
            v71.m_isUpToDateCB = (bool (__fastcall *)(bool, const char *))((int)v71.m_isUpToDateCB | 0x80000000);
            if ( v64 )
            {
              v65 = a6->m_data;
              v66 = 0;
              while ( 1 )
              {
                _FP10 = (float)(*(float *)&v65[v66].m_initCB - (float)v62);
                _FP9 = (float)(*(float *)&v65[v66].m_termCB - (float)v61);
                __asm
                {
                  fsel      f0, f10, f0, f11
                  fsel      f13, f9, f12, f13
                }
                if ( _FP0 < _FP13 )
                {
                  if ( _FP0 <= v62 )
                    goto LABEL_46;
                  if ( _FP13 < v61 )
                  {
                    if ( _FP0 < v62 || _FP13 > v61 )
                      goto LABEL_47;
                    if ( (float)((float)_FP0 - (float)v62) <= (double)(float)((float)v61 - (float)_FP13) )
                    {
LABEL_46:
                      v62 = _FP13;
                      goto LABEL_47;
                    }
                    v61 = _FP0;
                  }
                  else
                  {
                    v61 = _FP0;
                  }
                }
LABEL_47:
                ++v63;
                ++v66;
                if ( v63 >= v60 )
                {
                  *(float *)&v71.m_termCB = v61;
                  *(float *)&v71.m_initCB = v62;
                  break;
                }
              }
            }
            if ( (float)((float)v61 - (float)v62) > 0.001 )
              bfx::Array<bfx::Plane>::push_back(this: a6, val: &v71);
          }
          --v59;
          ++v58;
          if ( v59 == 0 )
          {
            v53 = bfx::g_pCurInstance;
            break;
          }
        }
      }
    }
  }
  if ( v50 != nullptr )
  {
    bfx::MemoryManager::Free(this: v53->m_pMemoryManager, ptr: v50);
    v53 = bfx::g_pCurInstance;
  }
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: v53->m_pMemoryManager, ptr: m_data);
    v53 = bfx::g_pCurInstance;
  }
  v74.m_size = 0;
  if ( v74.m_data != nullptr )
    bfx::MemoryManager::Free(this: v53->m_pMemoryManager, ptr: v74.m_data);
}


// ========================================================================
// __unwind$85834
// EA  : 0x8325C86C
// RVA : 0x0125C86C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85834()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1440 + 144));
}


// ========================================================================
// __unwind$85835
// EA  : 0x8325C894
// RVA : 0x0125C894
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85835()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1440 + 128));
}


// ========================================================================
// __unwind$85836
// EA  : 0x8325C8BC
// RVA : 0x0125C8BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_85836()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1440 + 112));
}


// ========================================================================
// ?Enable@LinkBase@bfx@@QAAX_N@Z
// EA  : 0x8325C8E8
// RVA : 0x0125C8E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::Enable(bfx::LinkBase *this, bool enable)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r29
  int v4; // r31
  int v5; // r30

  this->m_enabled = enable;
  p_m_links = &this->m_links;
  v4 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v5 = 0;
    do
    {
      bfx::EnableLinkPair(pForwardLink: p_m_links->m_data[v5], enable);
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_links->m_size );
  }
}


// ========================================================================
// ?SetBidirectional@LinkBase@bfx@@AAAX_N@Z
// EA  : 0x8325C940
// RVA : 0x0125C940
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::SetBidirectional(bfx::LinkBase *this, bool bidirectional)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r30
  int v3; // r29
  int v4; // r31
  unsigned int v5; // r28
  bfx::HalfLink *m_pTwin; // r3
  char v7; // r10
  unsigned __int8 v8; // r11
  char v9; // r8
  char v10; // r11

  this->m_linkDat.m_bidirectional = bidirectional;
  p_m_links = &this->m_links;
  v3 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v4 = 0;
    v5 = (2 * _cntlzw(bidirectional)) & 0x40;
    do
    {
      m_pTwin = p_m_links->m_data[v4]->m_pTwin;
      if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
        || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
        || (v7 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
      {
        v7 = 0;
      }
      v8 = *((_BYTE *)m_pTwin + 44) & 0xBF;
      v9 = v8 | v5;
      *((_BYTE *)m_pTwin + 44) = v8 | v5;
      if ( (v8 & 0x80 | v5 & 0x80) == 0 || ((v8 | (unsigned __int8)v5) & 0x40) != 0 || (v10 = 1, (v9 & 0x20) != 0) )
        v10 = 0;
      if ( v10 != v7 )
        bfx::UpdateCachedDataForHLinkEnableOrDisable(pLink: m_pTwin, enable: v10);
      ++v3;
      ++v4;
    }
    while ( v3 < p_m_links->m_size );
  }
}


// ========================================================================
// ?SetLinkUsageFlags@LinkBase@bfx@@AAAXI@Z
// EA  : 0x8325CA30
// RVA : 0x0125CA30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::SetLinkUsageFlags(bfx::LinkBase *this, unsigned int linkUsageFlags)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r28
  int v4; // r31
  int v5; // r30
  bfx::HalfLink *v6; // r27
  bfx::NavLayer *m_pNavLayer; // r26
  bfx::XGraph *m_pXGraph; // r26

  this->m_linkDat.m_linkUsageFlags = linkUsageFlags;
  p_m_links = &this->m_links;
  v4 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = p_m_links->m_data[v5];
      m_pNavLayer = v6->m_pNavLayer;
      bfx::IslandGraph::UpdateForLinkDisabledOrModified(this: m_pNavLayer->m_pIslandGraph, pLink: v6);
      m_pXGraph = m_pNavLayer->m_pXGraph;
      m_pXGraph->UpdateForLinkUsageFlagsChanged(this: m_pXGraph, a2: v6, a3: linkUsageFlags);
      m_pXGraph->UpdateForLinkUsageFlagsChanged(this: m_pXGraph, a2: v6->m_pTwin, a3: linkUsageFlags);
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_links->m_size );
  }
}


// ========================================================================
// ?IsConnected@LinkBase@bfx@@QBA_NI@Z
// EA  : 0x8325CAD0
// RVA : 0x0125CAD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

int __fastcall bfx::LinkBase::IsConnected(bfx::LinkBase *this, unsigned int layerMask)
{
  int m_size; // r8
  int v3; // r10
  int i; // r11

  m_size = this->m_links.m_size;
  v3 = 0;
  if ( m_size <= 0 )
    return 0;
  for ( i = 0; ((1 << this->m_links.m_data[i]->m_pNavLayer->m_layerIndex) & layerMask) == 0; ++i )
  {
    if ( ++v3 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?ApplyLinkToLayers@LinkBase@bfx@@QAAXIPAVIslandsTouchedArray@2@@Z
// EA  : 0x8325CB28
// RVA : 0x0125CB28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::ApplyLinkToLayers(
        bfx::LinkBase *this,
        unsigned int layersToApplyTo,
        bfx::IslandsTouchedArray *pIslandsTouchedArray)
{
  int v6; // r11
  int m_size; // ctr
  bfx::HalfLink *v8; // r10
  unsigned int v9; // r29
  int v10; // r27
  unsigned int i; // r30
  bfx::NavLayer *v12; // r31
  bfx::ArrayMap<bfx::Area *> *ArrayMapForLayer; // r5

  if ( this->m_links.m_size > 0 )
  {
    v6 = 0;
    m_size = this->m_links.m_size;
    do
    {
      v8 = this->m_links.m_data[v6++];
      layersToApplyTo &= ~(1 << v8->m_pNavLayer->m_layerIndex);
      --m_size;
    }
    while ( m_size != 0 );
  }
  v9 = 0;
  v10 = 1;
  for ( i = 8; i < 0x88; i += 4 )
  {
    if ( (v10 & layersToApplyTo) != 0 && v9 < 0x20 )
    {
      v12 = *(bfx::NavLayer **)((char *)&this->m_pPlanner->__vftable + i);
      if ( v12 != nullptr )
      {
        if ( pIslandsTouchedArray != nullptr )
          ArrayMapForLayer = bfx::IslandsTouchedArray::GetArrayMapForLayer(this: pIslandsTouchedArray, layerNum: v9);
        else
          ArrayMapForLayer = nullptr;
        this->CreateLinksForLayer(this, a2: v12, a3: ArrayMapForLayer);
      }
    }
    ++v9;
    v10 = __ROL4__(v10, 1);
  }
}


// ========================================================================
// ?ApplyLinksToLayers@bfx@@YAXPAVPlanner@1@AAV?$Array@PAVLinkBase@bfx@@@1@I@Z
// EA  : 0x8325CC08
// RVA : 0x0125CC08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::ApplyLinksToLayers(
        bfx::Planner *pPlanner,
        bfx::Array<bfx::LinkBase *> *links,
        unsigned int layerApplicationMask)
{
  int v6; // r28
  int v7; // r30
  bfx::LinkBase *v8; // r3
  unsigned int m_layerMask; // r10
  bfx::IslandsTouchedArray v10; // [sp+60h] [-C0h] BYREF

  bfx::IslandsTouchedArray::IslandsTouchedArray(this: &v10);
  v6 = 0;
  if ( links->m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = links->m_data[v7];
      m_layerMask = v8->m_linkDat.m_layerMask;
      if ( (m_layerMask & layerApplicationMask) != 0 )
        bfx::LinkBase::ApplyLinkToLayers(
          this: v8,
          layersToApplyTo: m_layerMask & layerApplicationMask,
          pIslandsTouchedArray: &v10);
      ++v6;
      ++v7;
    }
    while ( v6 < links->m_size );
  }
  bfx::RefreshIslandsTouched(pPlanner, islandsTouchedArray: &v10);
  bfx::IslandsTouchedArray::~IslandsTouchedArray(this: &v10);
}


// ========================================================================
// __unwind$86669
// EA  : 0x8325CC94
// RVA : 0x0125CC94
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_86669()
{
  int v0; // r12

  bfx::IslandsTouchedArray::~IslandsTouchedArray(this: (bfx::IslandsTouchedArray *)(v0 - 288 + 96));
}


// ========================================================================
// ?Draw@LinkImpl@bfx@@UAAXPBVSpace@2@I@Z
// EA  : 0x8325CCC0
// RVA : 0x0125CCC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkImpl::Draw(bfx::LinkImpl *this, bfx::Space *pSpace, unsigned int layerMask)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r25
  unsigned __int8 v7; // r10
  bfx::SystemInstance *v8; // r11
  int v9; // r23
  __int64 v10; // r8
  int v11; // r18
  int v12; // r24
  bfx::HalfLink *v13; // r31
  const bfx::Color *v14; // r30
  bfx::HalfLink *m_pTwin; // r29
  char v16; // r11
  char v17; // r11
  float m_y; // r10
  float m_z; // r9
  float *v20; // r11
  float v21; // r8
  float v22; // r7
  float v23; // r11
  double v24; // fp30
  const bfx::Color *v25; // r5
  const bfx::Color *v26; // r5
  unsigned int v27; // r10
  char v28; // r11
  char v29; // r11
  const bfx::Vec3 *v30; // r5
  const bfx::Vec3 *v31; // r4
  char v32; // r11
  char v33; // r11
  __int64 v34; // r10
  double Scale; // fp1
  double m_x; // fp13
  double v37; // fp12
  double v38; // fp11
  double v39; // fp10
  double v40; // fp9
  double v41; // fp30
  double v42; // fp6
  double v43; // fp5
  const bfx::Color *v44; // r5
  double v45; // fp2
  double v46; // fp0
  const bfx::Color *v47; // r5
  double v48; // fp31
  const bfx::Color *v49; // r5
  const bfx::Color *v50; // r5
  __int64 v51; // r6
  double v52; // fp6
  double v53; // fp4
  int v54; // [sp+8h] [-148h]
  int v55; // [sp+Ch] [-144h]
  int v56; // [sp+10h] [-140h]
  int v57; // [sp+14h] [-13Ch]
  int v58; // [sp+18h] [-138h]
  int v59; // [sp+1Ch] [-134h]
  int v60; // [sp+20h] [-130h]
  int v61; // [sp+24h] [-12Ch]
  bfx::Vec3 v62; // [sp+50h] [-100h] BYREF
  bfx::Vec3 v63; // [sp+60h] [-F0h] BYREF
  bfx::Vec3 v64; // [sp+70h] [-E0h] BYREF
  bfx::Vec3 v65; // [sp+80h] [-D0h] BYREF
  bfx::Vec3 v66; // [sp+90h] [-C0h] BYREF
  float v67; // [sp+9Ch] [-B4h]
  float v68; // [sp+A0h] [-B0h]
  float v69; // [sp+A4h] [-ACh]
  bfx::Vec3 v70; // [sp+B0h] [-A0h] BYREF
  float v71; // [sp+BCh] [-94h]
  float v72; // [sp+C0h] [-90h]
  float v73; // [sp+C4h] [-8Ch]

  if ( (this->m_linkDat.m_layerMask & layerMask) != 0 )
  {
    p_m_links = &this->m_links;
    v7 = 0;
    v8 = bfx::g_pCurInstance;
    v9 = 0;
    HIDWORD(v10) = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
    v11 = *(_DWORD *)(HIDWORD(v10) + 36);
    if ( this->m_links.m_size > 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        v13 = p_m_links->m_data[v12];
        HIDWORD(v10) = 1 << v13->m_pNavLayer->m_layerIndex;
        if ( (HIDWORD(v10) & layerMask) != 0 )
          break;
LABEL_40:
        ++v9;
        ++v12;
        if ( v9 >= p_m_links->m_size )
        {
          v8 = bfx::g_pCurInstance;
          goto LABEL_42;
        }
      }
      v14 = &ColorPurple_4;
      m_pTwin = v13->m_pTwin;
      if ( (*((_BYTE *)v13 + 44) & 0x80) == 0
        || (*((_BYTE *)v13 + 44) & 0x40) != 0
        || (v16 = 1, (*((_BYTE *)v13 + 44) & 0x20) != 0) )
      {
        v16 = 0;
      }
      if ( v16 == 0 )
      {
        if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
          || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
          || (v17 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
        {
          v17 = 0;
        }
        if ( v17 == 0 )
          v14 = &ColorRed_4;
      }
      m_y = v13->m_startSeg.m_v0.m_y;
      m_z = v13->m_startSeg.m_v0.m_z;
      v62.m_x = v13->m_startSeg.m_v0.m_x;
      v62.m_y = m_y;
      v62.m_z = m_z;
      v20 = (float *)v13->m_pTwin;
      v21 = v20[2];
      v22 = v20[3];
      v23 = v20[4];
      v66.m_x = v62.m_x;
      v63.m_x = v21;
      v63.m_y = v22;
      v63.m_z = v23;
      v66.m_y = m_y;
      v66.m_z = m_z;
      v69 = v23;
      v68 = v22;
      v67 = v21;
      bfx::DrawLineList(pSpace, pVerts: &v66, numVerts: 2, color: v14);
      v24 = (float)(bfx::GetScale() * (float)0.079999998);
      bfx::DrawBox(pSpace, pos: &v62, r: v24, color: v25, a5: v14);
      bfx::DrawBox(pSpace, pos: &v63, r: v24, color: v26, a5: v14);
      v27 = *((unsigned __int8 *)v13 + 44);
      if ( v27 >> 7 == 0 || (v27 & 0x40) != 0 || (v28 = 1, (v27 & 0x20) != 0) )
        v28 = 0;
      if ( v28 == 0 )
        goto LABEL_51;
      if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
        || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
        || (v29 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
      {
        v29 = 0;
      }
      if ( v29 != 0 )
      {
LABEL_51:
        if ( v27 >> 7 == 0 || (v27 & 0x40) != 0 || (v32 = 1, (v27 & 0x20) != 0) )
          v32 = 0;
        if ( v32 != 0 )
          goto LABEL_39;
        if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
          || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
          || (v33 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
        {
          v33 = 0;
        }
        if ( v33 == 0 )
          goto LABEL_39;
        v30 = &v62;
        v31 = &v63;
      }
      else
      {
        v30 = &v63;
        v31 = &v62;
      }
      bfx::DrawArrowhead((bfx::Vector3 *)pSpace, startPos: v31, endPos: v30, color: v14);
LABEL_39:
      v7 = 1;
      goto LABEL_40;
    }
LABEL_42:
    HIDWORD(v34) = &unk_821F0000;
    LODWORD(v10) = v7;
    if ( v7 == 0 )
    {
      LODWORD(v34) = v8->m_pComponentManager->m_components[1];
      HIDWORD(v34) = *(unsigned __int8 *)(v34 + 55);
      if ( *(_BYTE *)(v34 + 55) == 0 )
      {
        Scale = bfx::GetScale();
        m_x = this->m_startPos.m_x;
        v37 = this->m_startPos.m_y;
        v38 = this->m_startPos.m_z;
        v39 = this->m_endPos.m_y;
        v40 = this->m_endPos.m_z;
        v41 = (float)((float)Scale * (float)0.15000001);
        v71 = this->m_endPos.m_x;
        v70.m_x = m_x;
        v70.m_y = v37;
        v70.m_z = v38;
        v72 = v39;
        v73 = v40;
        bfx::DrawLineList(pSpace, pVerts: &v70, numVerts: 2, color: &ColorRed_4);
        v42 = (float)(this->m_startPos.m_z + (float)v41);
        v43 = this->m_startPos.m_y;
        v64.m_x = this->m_startPos.m_x;
        v64.m_z = v42;
        v64.m_y = v43;
        bfx::DrawBox(pSpace, pos: &v64, r: v41, color: v44, a5: &ColorRed_4);
        v45 = (float)(this->m_endPos.m_z + (float)v41);
        v46 = this->m_endPos.m_y;
        v64.m_x = this->m_endPos.m_x;
        v64.m_z = v45;
        v64.m_y = v46;
        bfx::DrawBox(pSpace, pos: &v64, r: v41, color: v47, a5: &ColorRed_4);
      }
    }
    if ( *(_BYTE *)(v11 + 11) != 0 )
    {
      v48 = (float)(bfx::GetScale() * (float)0.15000001);
      bfx::DrawCross(pSpace, pos: &this->m_startPos, radius: v48, color: v49, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      bfx::DrawCross(pSpace, pos: &this->m_endPos, radius: v48, color: v50, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
    }
    if ( *(_BYTE *)(v11 + 10) != 0 )
    {
      LODWORD(v34) = &unk_82410000;
      HIDWORD(v51) = "%08x";
      v52 = (float)(this->m_startPos.m_z + this->m_endPos.m_z);
      LODWORD(v51) = this->m_linkDat.m_linkUsageFlags;
      v53 = (float)((float)(this->m_startPos.m_y + this->m_endPos.m_y) * (float)0.5);
      v65.m_x = (float)(this->m_startPos.m_x + this->m_endPos.m_x) * (float)0.5;
      v65.m_y = v53;
      v65.m_z = (float)v52 * (float)0.5;
      bfx::DrawString(
        (bfx::Vector3 *)pSpace,
        inputPos: &v65,
        fmt: v51,
        a4: v10,
        a5: v34,
        a6: v54,
        a7: v55,
        a8: v56,
        a9: v57,
        a10: v58,
        a11: v59,
        a12: v60,
        a13: v61);
    }
  }
}


// ========================================================================
// ?DrawUsageDistances@LinkImpl@bfx@@UAAXPBVSpace@2@I@Z
// EA  : 0x8325D140
// RVA : 0x0125D140
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkImpl::DrawUsageDistances(
        bfx::LinkImpl *this,
        const bfx::Space *pSpace,
        unsigned int layerMask)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r24
  int v7; // r23
  int v8; // r27
  bfx::HalfLink *v9; // r31
  double m_mayUseDist; // fp31
  float m_y; // r10
  float m_z; // r9
  bfx::HalfLink *m_pTwin; // r30
  float v14; // r7
  float v15; // r6
  bfx::Area *v16; // r3
  const bfx::Color *v17; // r6
  double v18; // fp31
  bfx::Area *v19; // r3
  const bfx::Color *v20; // r6
  double m_mustUseDist; // fp31
  bfx::Area *v22; // r3
  const bfx::Color *v23; // r6
  double v24; // fp31
  bfx::Area *v25; // r3
  const bfx::Color *v26; // r6
  bfx::Vec3 v27; // [sp+50h] [-D0h] BYREF
  bfx::Vec3 v28; // [sp+60h] [-C0h] BYREF
  bfx::Area v29; // [sp+70h] [-B0h] BYREF

  if ( (this->m_linkDat.m_layerMask & layerMask) != 0 )
  {
    p_m_links = &this->m_links;
    v7 = 0;
    if ( this->m_links.m_size > 0 )
    {
      v8 = 0;
      do
      {
        v9 = p_m_links->m_data[v8];
        if ( ((1 << v9->m_pNavLayer->m_layerIndex) & layerMask) != 0 )
        {
          m_mayUseDist = this->m_linkDat.m_mayUseDist;
          m_y = v9->m_startSeg.m_v0.m_y;
          m_z = v9->m_startSeg.m_v0.m_z;
          m_pTwin = v9->m_pTwin;
          v27.m_x = v9->m_startSeg.m_v0.m_x;
          v27.m_y = m_y;
          v27.m_z = m_z;
          v14 = m_pTwin->m_startSeg.m_v0.m_y;
          v15 = m_pTwin->m_startSeg.m_v0.m_z;
          v28.m_x = m_pTwin->m_startSeg.m_v0.m_x;
          v28.m_y = v14;
          v28.m_z = v15;
          if ( m_mayUseDist > 0.0 )
          {
            v16 = bfx::Area::CalcNormal(this: &v29, result: (bfx::Vec3 *)v9->m_pArea);
            bfx::DrawCircle(
              pSpace,
              pos: &v27,
              N: (const bfx::Vec3 *)v16,
              radius: m_mayUseDist,
              color: v17,
              a6: &MAY_USE_DIST_COLOR);
            v18 = this->m_linkDat.m_mayUseDist;
            v19 = bfx::Area::CalcNormal(this: (bfx::Area *)&v29.m_pos, result: (bfx::Vec3 *)m_pTwin->m_pArea);
            bfx::DrawCircle(
              pSpace,
              pos: &v28,
              N: (const bfx::Vec3 *)v19,
              radius: v18,
              color: v20,
              a6: &MAY_USE_DIST_COLOR);
          }
          m_mustUseDist = this->m_linkDat.m_mustUseDist;
          if ( m_mustUseDist > 0.0 )
          {
            v22 = bfx::Area::CalcNormal(this: (bfx::Area *)&v29.m_searchCost, result: (bfx::Vec3 *)v9->m_pArea);
            bfx::DrawCircle(
              pSpace,
              pos: &v27,
              N: (const bfx::Vec3 *)v22,
              radius: m_mustUseDist,
              color: v23,
              a6: &MUST_USE_DIST_COLOR);
            v24 = this->m_linkDat.m_mustUseDist;
            v25 = bfx::Area::CalcNormal(this: (bfx::Area *)&v29.m_flags.m_flags3, result: (bfx::Vec3 *)m_pTwin->m_pArea);
            bfx::DrawCircle(
              pSpace,
              pos: &v28,
              N: (const bfx::Vec3 *)v25,
              radius: v24,
              color: v26,
              a6: &MUST_USE_DIST_COLOR);
          }
        }
        ++v7;
        ++v8;
      }
      while ( v7 < p_m_links->m_size );
    }
  }
}


// ========================================================================
// ??0LinkStripImpl@bfx@@QAA@PAVPlanner@1@ABVLineSeg@1@1ABVLinkDat@1@I@Z
// EA  : 0x8325D2D8
// RVA : 0x0125D2D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkStripImpl *__fastcall bfx::LinkStripImpl::LinkStripImpl(
        bfx::LinkStripImpl *this,
        bfx::Planner *pPlanner,
        const bfx::LineSeg *start,
        const bfx::LineSeg *end,
        const bfx::LinkDat *linkDat,
        unsigned int linkID)
{
  bfx::bfxMemTag v8; // r11
  _DWORD *p_m_z; // r10
  bfx::LinkFlowBase **v12; // r9
  int i; // ctr
  bfx::LineSeg *p_m_end; // r29
  _DWORD *v15; // r11
  float *v16; // r10
  int j; // ctr
  bfx::Vec3 *p_m_v1; // r28
  double DistBetweenLineSegs; // fp31
  float m_y; // r11
  float m_x; // r10
  float m_z; // r9

  this->m_pPlanner = pPlanner;
  this->m_pProxy = nullptr;
  this->__vftable = (bfx::LinkStripImpl_vtbl *)&bfx::LinkBase::`vftable';
  v8 = bfx::MEM_BFXPLANNER;
  this->m_links.m_data = nullptr;
  this->m_links.m_size = 0;
  this->m_links.m_cap = 0;
  this->m_links.m_tag = v8;
  memcpy(Dst: &this->m_linkDat, Src: linkDat, Size: sizeof(this->m_linkDat));
  this->m_linkID = linkID;
  this->m_pLinkFlow = nullptr;
  this->m_enabled = true;
  this->__vftable = (bfx::LinkStripImpl_vtbl *)&bfx::LinkStripImpl::`vftable';
  p_m_z = (_DWORD *)&start[-1].m_v1.m_z;
  v12 = &this->m_pLinkFlow + 1;
  for ( i = 6; i != 0; --i )
    *++v12 = (bfx::LinkFlowBase *)*++p_m_z;
  p_m_end = &this->m_end;
  v15 = (_DWORD *)&end[-1].m_v1.m_z;
  v16 = &this->m_start.m_v1.m_z;
  for ( j = 6; j != 0; --j )
    *++v16 = *(float *)++v15;
  this->m_applyAngleLimits = true;
  p_m_v1 = &this->m_end.m_v1;
  DistBetweenLineSegs = bfx::GetDistBetweenLineSegs(
                          startA: &this->m_start.m_v0,
                          endA: &this->m_end.m_v0,
                          startB: &this->m_start.m_v1,
                          endB: &this->m_end.m_v1);
  if ( DistBetweenLineSegs < bfx::GetDistBetweenLineSegs(
                               startA: &this->m_start.m_v0,
                               endA: &this->m_end.m_v1,
                               startB: &this->m_start.m_v1,
                               endB: &this->m_end.m_v0) )
  {
    m_y = this->m_end.m_v0.m_y;
    m_x = p_m_end->m_v0.m_x;
    p_m_end->m_v0.m_x = p_m_v1->m_x;
    m_z = this->m_end.m_v0.m_z;
    this->m_end.m_v0.m_y = this->m_end.m_v1.m_y;
    this->m_end.m_v0.m_z = this->m_end.m_v1.m_z;
    p_m_v1->m_x = m_x;
    this->m_end.m_v1.m_y = m_y;
    this->m_end.m_v1.m_z = m_z;
  }
  return this;
}


// ========================================================================
// __unwind$87040
// EA  : 0x8325D448
// RVA : 0x0125D448
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_87040()
{
  int v0; // r12

  bfx::LinkBase::~LinkBase(this: *(bfx::LinkBase **)(v0 - 176 + 196));
}


// ========================================================================
// ?GetStartSeg@LinkStripImpl@bfx@@UBA?AVLineSeg@2@XZ
// EA  : 0x8325D470
// RVA : 0x0125D470
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkStripImpl *__fastcall bfx::LinkStripImpl::GetStartSeg(bfx::LinkStripImpl *this, bfx::LineSeg *result)
{
  bfx::LinkStripImpl_vtbl **p_m_y; // r11
  bfx::LinkStripImpl *v3; // r10
  int i; // ctr

  p_m_y = (bfx::LinkStripImpl_vtbl **)&result[4].m_v0.m_y;
  v3 = (bfx::LinkStripImpl *)((char *)this - 4);
  for ( i = 6; i != 0; --i )
  {
    ++p_m_y;
    v3 = (bfx::LinkStripImpl *)((char *)v3 + 4);
    v3->__vftable = *p_m_y;
  }
  return this;
}


// ========================================================================
// ?GetEndSeg@LinkStripImpl@bfx@@UBA?AVLineSeg@2@XZ
// EA  : 0x8325D490
// RVA : 0x0125D490
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkStripImpl *__fastcall bfx::LinkStripImpl::GetEndSeg(bfx::LinkStripImpl *this, bfx::LineSeg *result)
{
  bfx::LinkStripImpl_vtbl **p_m_y; // r11
  bfx::LinkStripImpl *v3; // r10
  int i; // ctr

  p_m_y = (bfx::LinkStripImpl_vtbl **)&result[5].m_v0.m_y;
  v3 = (bfx::LinkStripImpl *)((char *)this - 4);
  for ( i = 6; i != 0; --i )
  {
    ++p_m_y;
    v3 = (bfx::LinkStripImpl *)((char *)v3 + 4);
    v3->__vftable = *p_m_y;
  }
  return this;
}


// ========================================================================
// ?Draw@LinkStripImpl@bfx@@UAAXPBVSpace@2@I@Z
// EA  : 0x8325D4B0
// RVA : 0x0125D4B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkStripImpl::Draw(bfx::LinkStripImpl *this, bfx::Space *pSpace, unsigned int layerMask)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r24
  bfx::SystemInstance *v7; // r11
  char v8; // r10
  int v9; // r21
  __int64 v10; // r8
  int v11; // r17
  int v12; // r22
  bfx::HalfLink *v13; // r29
  const bfx::Color *v14; // r28
  bfx::HalfLink *m_pTwin; // r10
  char v16; // r11
  char v17; // r11
  const bfx::Vec3 *p_m_v0; // r30
  char v19; // r11
  char v20; // r10
  char v21; // r11
  char v22; // r11
  bool v23; // zf
  double Scale; // fp1
  double v25; // fp30
  double m_z; // fp0
  double m_y; // fp12
  const bfx::Color *v28; // r5
  double v29; // fp8
  double v30; // fp7
  const bfx::Color *v31; // r5
  double v32; // fp4
  double v33; // fp3
  const bfx::Color *v34; // r5
  double v35; // fp13
  double v36; // fp12
  const bfx::Color *v37; // r5
  double v38; // fp13
  double v39; // fp12
  double m_x; // fp11
  double v41; // fp10
  double v42; // fp9
  double v43; // fp7
  double v44; // fp6
  double v45; // fp5
  double v46; // fp4
  double v47; // fp3
  double v48; // fp1
  double v49; // fp13
  double v50; // fp12
  double v51; // fp11
  double v52; // fp10
  double v53; // fp9
  double v54; // fp31
  double v55; // fp7
  double v56; // fp6
  double v57; // fp5
  double v58; // fp4
  double v59; // fp3
  const bfx::Color *v60; // r5
  const bfx::Color *v61; // r5
  const bfx::Color *v62; // r5
  const bfx::Color *v63; // r5
  __int64 v64; // r10
  __int64 v65; // r6
  double v66; // fp2
  double v67; // fp13
  int v68; // [sp+8h] [-1A8h]
  int v69; // [sp+Ch] [-1A4h]
  int v70; // [sp+10h] [-1A0h]
  int v71; // [sp+14h] [-19Ch]
  int v72; // [sp+18h] [-198h]
  int v73; // [sp+1Ch] [-194h]
  int v74; // [sp+20h] [-190h]
  int v75; // [sp+24h] [-18Ch]
  bfx::Vec3 v76; // [sp+50h] [-160h] BYREF
  bfx::Vec3 v77; // [sp+60h] [-150h] BYREF
  bfx::Vec3 v78; // [sp+70h] [-140h] BYREF
  bfx::Vec3 v79; // [sp+80h] [-130h] BYREF
  bfx::Vec3 v80; // [sp+90h] [-120h] BYREF
  bfx::Vec3 v81; // [sp+A0h] [-110h] BYREF
  float v82; // [sp+ACh] [-104h]
  float v83; // [sp+B0h] [-100h]
  float v84; // [sp+B4h] [-FCh]
  bfx::Vec3 v85; // [sp+C0h] [-F0h] BYREF
  float v86; // [sp+CCh] [-E4h]
  float v87; // [sp+D0h] [-E0h]
  float v88; // [sp+D4h] [-DCh]
  bfx::Vec3 v89; // [sp+E0h] [-D0h] BYREF
  float v90; // [sp+ECh] [-C4h]
  float v91; // [sp+F0h] [-C0h]
  float v92; // [sp+F4h] [-BCh]
  bfx::Vec3 v93; // [sp+100h] [-B0h] BYREF
  float v94; // [sp+10Ch] [-A4h]
  float v95; // [sp+110h] [-A0h]
  float v96; // [sp+114h] [-9Ch]

  if ( (this->m_linkDat.m_layerMask & layerMask) != 0 )
  {
    LODWORD(v10) = &unk_821F0000;
    p_m_links = &this->m_links;
    v7 = bfx::g_pCurInstance;
    v8 = 0;
    v9 = 0;
    HIDWORD(v10) = bfx::g_pCurInstance->m_pComponentManager;
    v11 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v10) + 4) + 36);
    if ( this->m_links.m_size > 0 )
    {
      v12 = 0;
      do
      {
        v13 = p_m_links->m_data[v12];
        LODWORD(v10) = v13->m_pNavLayer->m_layerIndex;
        HIDWORD(v10) = 1 << v10;
        if ( ((1 << v10) & layerMask) != 0 )
        {
          v14 = &ColorPurple_4;
          m_pTwin = v13->m_pTwin;
          if ( (*((_BYTE *)v13 + 44) & 0x80) == 0
            || (*((_BYTE *)v13 + 44) & 0x40) != 0
            || (v16 = 1, (*((_BYTE *)v13 + 44) & 0x20) != 0) )
          {
            v16 = 0;
          }
          if ( v16 == 0 )
          {
            if ( (*((_BYTE *)m_pTwin + 44) & 0x80) == 0
              || (*((_BYTE *)m_pTwin + 44) & 0x40) != 0
              || (v17 = 1, (*((_BYTE *)m_pTwin + 44) & 0x20) != 0) )
            {
              v17 = 0;
            }
            if ( v17 == 0 )
              v14 = &ColorRed_4;
          }
          p_m_v0 = &m_pTwin->m_startSeg.m_v0;
          bfx::DrawPanelBetweenLineSegs(pSpace, start: &v13->m_startSeg, end: &m_pTwin->m_startSeg, color: v14);
          if ( (*((_BYTE *)v13 + 44) & 0x80) == 0
            || (*((_BYTE *)v13 + 44) & 0x40) != 0
            || (v19 = 1, (*((_BYTE *)v13 + 44) & 0x20) != 0) )
          {
            v19 = 0;
          }
          v20 = v19;
          v21 = *((_BYTE *)v13->m_pTwin + 44);
          LODWORD(v10) = v21 & 0x80;
          if ( (v21 & 0x80) == 0
            || (*((_BYTE *)v13->m_pTwin + 44) & 0x40) != 0
            || (v23 = (v21 & 0x20) == 0, v22 = 1, !v23) )
          {
            v22 = 0;
          }
          if ( v20 == 0 || v22 != 0 )
          {
            if ( v22 != 0 )
            {
              if ( v20 == 0 )
              {
                bfx::DrawArrowhead((bfx::Vector3 *)pSpace, startPos: p_m_v0, endPos: &v13->m_startSeg.m_v0, color: v14);
                bfx::DrawArrowhead(
                  (bfx::Vector3 *)pSpace,
                  startPos: p_m_v0 + 1,
                  endPos: &v13->m_startSeg.m_v1,
                  color: v14);
              }
            }
            else if ( v20 == 0 )
            {
              Scale = bfx::GetScale();
              v25 = (float)((float)Scale * (float)0.15000001);
              m_z = v13->m_startSeg.m_v0.m_z;
              m_y = v13->m_startSeg.m_v0.m_y;
              v77.m_x = v13->m_startSeg.m_v0.m_x;
              v77.m_y = m_y;
              v77.m_z = (float)m_z + (float)((float)Scale * (float)0.15000001);
              bfx::DrawBox(pSpace, pos: &v77, r: v25, color: v28, a5: &ColorRed_4);
              v29 = (float)(p_m_v0->m_z + (float)v25);
              v30 = p_m_v0->m_y;
              v80.m_x = p_m_v0->m_x;
              v80.m_z = v29;
              v80.m_y = v30;
              bfx::DrawBox(pSpace, pos: &v80, r: v25, color: v31, a5: &ColorRed_4);
              v32 = (float)(v13->m_startSeg.m_v1.m_z + (float)v25);
              v33 = v13->m_startSeg.m_v1.m_y;
              v79.m_x = v13->m_startSeg.m_v1.m_x;
              v79.m_z = v32;
              v79.m_y = v33;
              bfx::DrawBox(pSpace, pos: &v79, r: v25, color: v34, a5: &ColorRed_4);
              v35 = (float)(p_m_v0[1].m_z + (float)v25);
              v36 = p_m_v0[1].m_y;
              v78.m_x = p_m_v0[1].m_x;
              v78.m_z = v35;
              v78.m_y = v36;
              bfx::DrawBox(pSpace, pos: &v78, r: v25, color: v37, a5: &ColorRed_4);
            }
          }
          else
          {
            bfx::DrawArrowhead((bfx::Vector3 *)pSpace, startPos: &v13->m_startSeg.m_v0, endPos: p_m_v0, color: v14);
            bfx::DrawArrowhead((bfx::Vector3 *)pSpace, startPos: &v13->m_startSeg.m_v1, endPos: p_m_v0 + 1, color: v14);
          }
          v8 = 1;
        }
        ++v9;
        ++v12;
      }
      while ( v9 < p_m_links->m_size );
      v7 = bfx::g_pCurInstance;
    }
    if ( v8 == 0 && LOBYTE(v7->m_pComponentManager->m_components[1][13].__vftable) == 0 )
    {
      bfx::DrawPanelBetweenLineSegs(pSpace, start: &this->m_start, end: &this->m_end, color: &ColorRed_4);
      v38 = this->m_start.m_v0.m_y;
      v39 = this->m_start.m_v0.m_z;
      m_x = this->m_end.m_v1.m_x;
      v41 = this->m_end.m_v1.m_y;
      v42 = this->m_end.m_v1.m_z;
      v81.m_x = this->m_start.m_v0.m_x;
      v81.m_y = v38;
      v81.m_z = v39;
      v82 = m_x;
      v83 = v41;
      v84 = v42;
      bfx::DrawLineList(pSpace, pVerts: &v81, numVerts: 2, color: &ColorRed_4);
      v43 = this->m_start.m_v1.m_y;
      v44 = this->m_start.m_v1.m_z;
      v45 = this->m_end.m_v0.m_x;
      v46 = this->m_end.m_v0.m_y;
      v47 = this->m_end.m_v0.m_z;
      v89.m_x = this->m_start.m_v1.m_x;
      v89.m_y = v43;
      v89.m_z = v44;
      v90 = v45;
      v91 = v46;
      v92 = v47;
      bfx::DrawLineList(pSpace, pVerts: &v89, numVerts: 2, color: &ColorRed_4);
    }
    if ( *(_BYTE *)(v11 + 11) != 0 )
    {
      v48 = bfx::GetScale();
      v49 = this->m_start.m_v0.m_x;
      v50 = this->m_start.m_v0.m_y;
      v51 = this->m_start.m_v0.m_z;
      v52 = this->m_start.m_v1.m_y;
      v53 = this->m_start.m_v1.m_z;
      v86 = this->m_start.m_v1.m_x;
      v85.m_x = v49;
      v85.m_y = v50;
      v85.m_z = v51;
      v54 = (float)((float)v48 * (float)0.15000001);
      v87 = v52;
      v88 = v53;
      bfx::DrawLineList(pSpace, pVerts: &v85, numVerts: 2, color: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      v55 = this->m_end.m_v0.m_y;
      v56 = this->m_end.m_v0.m_z;
      v57 = this->m_end.m_v1.m_x;
      v58 = this->m_end.m_v1.m_y;
      v59 = this->m_end.m_v1.m_z;
      v93.m_x = this->m_end.m_v0.m_x;
      v93.m_y = v55;
      v93.m_z = v56;
      v94 = v57;
      v95 = v58;
      v96 = v59;
      bfx::DrawLineList(pSpace, pVerts: &v93, numVerts: 2, color: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      bfx::DrawCross(pSpace, pos: &this->m_start.m_v0, radius: v54, color: v60, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      bfx::DrawCross(pSpace, pos: &this->m_start.m_v1, radius: v54, color: v61, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      bfx::DrawCross(pSpace, pos: &this->m_end.m_v0, radius: v54, color: v62, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
      bfx::DrawCross(pSpace, pos: &this->m_end.m_v1, radius: v54, color: v63, a5: &bfx::ORIGINAL_LINK_LOCATION_COLOR);
    }
    if ( *(_BYTE *)(v11 + 10) != 0 )
    {
      LODWORD(v64) = 0x82000000;
      HIDWORD(v64) = &unk_82410000;
      HIDWORD(v65) = "%08x";
      LODWORD(v65) = this->m_linkDat.m_linkUsageFlags;
      v66 = (float)((float)((float)(this->m_start.m_v1.m_z + this->m_start.m_v0.m_z) * (float)0.5)
                  + (float)((float)(this->m_end.m_v1.m_z + this->m_end.m_v0.m_z) * (float)0.5));
      v67 = (float)((float)((float)((float)(this->m_start.m_v1.m_y + this->m_start.m_v0.m_y) * (float)0.5)
                          + (float)((float)(this->m_end.m_v1.m_y + this->m_end.m_v0.m_y) * (float)0.5))
                  * (float)0.5);
      v76.m_x = (float)((float)((float)(this->m_start.m_v0.m_x + this->m_start.m_v1.m_x) * (float)0.5)
                      + (float)((float)(this->m_end.m_v0.m_x + this->m_end.m_v1.m_x) * (float)0.5))
              * (float)0.5;
      v76.m_y = v67;
      v76.m_z = (float)v66 * (float)0.5;
      bfx::DrawString(
        (bfx::Vector3 *)pSpace,
        inputPos: &v76,
        fmt: v65,
        a4: v10,
        a5: v64,
        a6: v68,
        a7: v69,
        a8: v70,
        a9: v71,
        a10: v72,
        a11: v73,
        a12: v74,
        a13: v75);
    }
  }
}


// ========================================================================
// ?DrawUsageDistances@LinkStripImpl@bfx@@UAAXPBVSpace@2@I@Z
// EA  : 0x8325DA58
// RVA : 0x0125DA58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkStripImpl::DrawUsageDistances(
        bfx::LinkStripImpl *this,
        const bfx::Space *pSpace,
        unsigned int layerMask)
{
  const bfx::Vec3 *v5; // r5
  int m_size; // r10
  double v7; // fp31
  double v8; // fp30
  int v9; // r24
  double v10; // fp29
  double v11; // fp28
  double v12; // fp27
  double v13; // fp26
  int v14; // r29
  bfx::HalfLink *v15; // r30
  double DistPtToLineSeg; // fp24
  double v17; // fp12
  double v18; // fp9
  double v19; // fp6
  double v20; // fp24
  float *v21; // r3
  bfx::HalfLink *v22; // r11
  bfx::Area *p_m_flags3; // r3
  bfx::Vec3 *m_pArea; // r4
  double m_z; // fp0
  double v26; // fp13
  double v27; // fp7
  double v28; // fp5
  double v29; // fp4
  double v30; // fp3
  double v31; // fp2
  bfx::HalfLink *m_pTwin; // r11
  double v33; // fp12
  double v34; // fp9
  double v35; // fp6
  double v36; // fp24
  float *v37; // r3
  double v38; // fp24
  float *v39; // r3
  double m_mayUseDist; // fp1
  const bfx::Vec3 *v45; // r5
  double m_mustUseDist; // fp1
  const bfx::Vec3 *v47; // r5
  bfx::Color v48; // [sp+50h] [-F0h] BYREF
  bfx::Color v49; // [sp+60h] [-E0h] BYREF
  bfx::Area v50[2]; // [sp+70h] [-D0h] BYREF

  if ( (this->m_linkDat.m_layerMask & layerMask) != 0 )
  {
    bfx::GetUpVec(result: (bfx::Vec3 *)&v48);
    bfx::GetUpVec(result: (bfx::Vec3 *)&v49);
    m_size = this->m_links.m_size;
    if ( m_size != 0 )
    {
      v7 = 0.0;
      v8 = 0.0;
      v9 = 0;
      v10 = 0.0;
      v11 = 0.0;
      v12 = 0.0;
      v13 = 0.0;
      if ( m_size > 0 )
      {
        v14 = 0;
        do
        {
          v15 = this->m_links.m_data[v14];
          DistPtToLineSeg = bfx::GetDistPtToLineSeg(pos: &v15->m_startSeg.m_v0, seg: &this->m_start);
          if ( DistPtToLineSeg >= bfx::GetDistPtToLineSeg(pos: &v15->m_startSeg.m_v0, seg: &this->m_end) )
          {
            m_pTwin = v15->m_pTwin;
            v33 = (float)(m_pTwin->m_startSeg.m_v1.m_y - m_pTwin->m_startSeg.m_v0.m_y);
            v34 = (float)(m_pTwin->m_startSeg.m_v1.m_z - m_pTwin->m_startSeg.m_v0.m_z);
            v35 = (float)(m_pTwin->m_startSeg.m_v1.m_x - m_pTwin->m_startSeg.m_v0.m_x);
            v36 = __fsqrts((float)((float)((float)v35 * (float)v35)
                                 + (float)((float)((float)v34 * (float)v34) + (float)((float)v33 * (float)v33))));
            v37 = (float *)bfx::Area::CalcNormal(
                             this: (bfx::Area *)&v50[0].m_searchCost,
                             result: (bfx::Vec3 *)m_pTwin->m_pArea);
            m_pArea = (bfx::Vec3 *)v15->m_pArea;
            m_z = v15->m_startSeg.m_v1.m_z;
            v26 = v15->m_startSeg.m_v0.m_z;
            v27 = (float)(v15->m_startSeg.m_v1.m_y - v15->m_startSeg.m_v0.m_y);
            v28 = (float)(*v37 * (float)v36);
            v29 = (float)(v37[1] * (float)v36);
            v30 = (float)(v37[2] * (float)v36);
            p_m_flags3 = (bfx::Area *)&v50[0].m_flags.m_flags3;
            v31 = (float)(v15->m_startSeg.m_v1.m_x - v15->m_startSeg.m_v0.m_x);
          }
          else
          {
            v17 = (float)(v15->m_startSeg.m_v1.m_y - v15->m_startSeg.m_v0.m_y);
            v18 = (float)(v15->m_startSeg.m_v1.m_z - v15->m_startSeg.m_v0.m_z);
            v19 = (float)(v15->m_startSeg.m_v1.m_x - v15->m_startSeg.m_v0.m_x);
            v20 = __fsqrts((float)((float)((float)v19 * (float)v19)
                                 + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))));
            v21 = (float *)bfx::Area::CalcNormal(this: v50, result: (bfx::Vec3 *)v15->m_pArea);
            v22 = v15->m_pTwin;
            m_pArea = (bfx::Vec3 *)v22->m_pArea;
            m_z = v22->m_startSeg.m_v1.m_z;
            v26 = v22->m_startSeg.m_v0.m_z;
            v27 = (float)(v22->m_startSeg.m_v1.m_y - v22->m_startSeg.m_v0.m_y);
            v28 = (float)(*v21 * (float)v20);
            v29 = (float)(v21[1] * (float)v20);
            v30 = (float)(v21[2] * (float)v20);
            p_m_flags3 = (bfx::Area *)&v50[0].m_pos;
            v31 = (float)(v22->m_startSeg.m_v1.m_x - v22->m_startSeg.m_v0.m_x);
          }
          v7 = (float)((float)v28 + (float)v7);
          v8 = (float)((float)v29 + (float)v8);
          v10 = (float)((float)v30 + (float)v10);
          v38 = __fsqrts((float)((float)((float)v31 * (float)v31)
                               + (float)((float)((float)((float)m_z - (float)v26) * (float)((float)m_z - (float)v26))
                                       + (float)((float)v27 * (float)v27))));
          v39 = (float *)bfx::Area::CalcNormal(this: p_m_flags3, result: m_pArea);
          ++v9;
          ++v14;
          v13 = (float)((float)(v39[2] * (float)v38) + (float)v13);
          v12 = (float)((float)(v39[1] * (float)v38) + (float)v12);
          v11 = (float)((float)((float)v38 * *v39) + (float)v11);
        }
        while ( v9 < this->m_links.m_size );
      }
      _FP2 = (float)((float)__fsqrts((float)((float)((float)v11 * (float)v11)
                                           + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))))
                   - (float)1.0842022e-19);
      _FP4 = (float)((float)__fsqrts((float)((float)((float)v7 * (float)v7)
                                           + (float)((float)((float)v8 * (float)v8) + (float)((float)v10 * (float)v10))))
                   - (float)1.0842022e-19);
      __asm
      {
        fsel      f0, f4, f3, f25
        fsel      f13, f2, f1, f25
      }
      v48.m_r = (float)_FP0 * (float)v7;
      v48.m_g = (float)_FP0 * (float)v8;
      v48.m_b = (float)_FP0 * (float)v10;
      v49.m_r = (float)_FP13 * (float)v11;
      v49.m_g = (float)v12 * (float)_FP13;
      v49.m_b = (float)v13 * (float)_FP13;
    }
    m_mayUseDist = this->m_linkDat.m_mayUseDist;
    if ( m_mayUseDist > 0.0 )
    {
      bfx::DrawCapsule2d(pSpace, seg: &this->m_start, radius: m_mayUseDist, N: v5, color: &v48, a6: &MAY_USE_DIST_COLOR);
      bfx::DrawCapsule2d(
        pSpace,
        seg: &this->m_end,
        radius: this->m_linkDat.m_mayUseDist,
        N: v45,
        color: &v49,
        a6: &MAY_USE_DIST_COLOR);
    }
    m_mustUseDist = this->m_linkDat.m_mustUseDist;
    if ( m_mustUseDist > 0.0 )
    {
      bfx::DrawCapsule2d(
        pSpace,
        seg: &this->m_start,
        radius: m_mustUseDist,
        N: v5,
        color: &v48,
        a6: &MUST_USE_DIST_COLOR);
      bfx::DrawCapsule2d(
        pSpace,
        seg: &this->m_end,
        radius: this->m_linkDat.m_mustUseDist,
        N: v47,
        color: &v49,
        a6: &MUST_USE_DIST_COLOR);
    }
  }
}


// ========================================================================
// ?CreateLinkStrip@Planner@bfx@@QAAPAVLinkBase@2@ABVLineSeg@2@0ABVLinkDat@2@I@Z
// EA  : 0x8325DD98
// RVA : 0x0125DD98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::Space *__fastcall bfx::Planner::CreateLinkStrip(
        bfx::Planner *this,
        const bfx::LineSeg *start,
        const bfx::LineSeg *end,
        const bfx::LinkDat *inputLinkDat,
        __int64 linkID)
{
  unsigned int v8; // r27
  int v9; // ctr
  bfx::LinkFlowTune *p_m_flowTune; // r9
  __int64 v11; // r11
  bfx::Space *v12; // r3
  bfx::Space *v13; // r30
  bfx::Space *v15; // [sp+50h] [-80h] BYREF
  bfx::LinkDat v16[2]; // [sp+60h] [-70h] BYREF

  v8 = HIDWORD(linkID);
  v9 = 7;
  p_m_flowTune = &inputLinkDat[-1].m_flowTune;
  do
  {
    p_m_flowTune += 2;
    v11 = *(_QWORD *)&p_m_flowTune->m_maxSimultaneous;
    HIDWORD(v11) = p_m_flowTune->m_maxSimultaneous + 8;
    *(_QWORD *)HIDWORD(v11) = v11;
    --v9;
  }
  while ( v9 != 0 );
  bfx::ApplyLimits_LinkDat(linkDat: v16, a2: (int)start, a3: (int)end, a4: (int)inputLinkDat, a5: linkID);
  v12 = (bfx::Space *)bfx::MemoryManager::Malloc(
                        this: bfx::g_pCurInstance->m_pMemoryManager,
                        size: 0xA0u,
                        tag: bfx::MEM_BFXPLANNER);
  v15 = v12;
  if ( v12 != nullptr )
    v13 = (bfx::Space *)bfx::LinkStripImpl::LinkStripImpl(
                          this: (bfx::LinkStripImpl *)v12,
                          pPlanner: this,
                          start,
                          end,
                          linkDat: v16,
                          linkID: v8);
  else
    v13 = nullptr;
  v15 = v13;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_links, val: &v15);
  bfx::LinkBase::ApplyLinkToLayers(
    this: (bfx::LinkBase *)v13,
    layersToApplyTo: v16[0].m_layerMask,
    pIslandsTouchedArray: nullptr);
  return v13;
}


// ========================================================================
// __unwind$88029
// EA  : 0x8325DE54
// RVA : 0x0125DE54
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88029()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 208 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0LinkImpl@bfx@@QAA@PAVPlanner@1@ABVVec3@1@1ABVLinkDat@1@I@Z
// EA  : 0x8325DE80
// RVA : 0x0125DE80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkImpl *__fastcall bfx::LinkImpl::LinkImpl(
        bfx::LinkImpl *this,
        bfx::Planner *pPlanner,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::LinkDat *linkDat,
        unsigned int linkID)
{
  bfx::bfxMemTag v8; // r11

  this->m_pPlanner = pPlanner;
  this->m_pProxy = nullptr;
  this->__vftable = (bfx::LinkImpl_vtbl *)&bfx::LinkBase::`vftable';
  v8 = bfx::MEM_BFXPLANNER;
  this->m_links.m_data = nullptr;
  this->m_links.m_size = 0;
  this->m_links.m_cap = 0;
  this->m_links.m_tag = v8;
  memcpy(Dst: &this->m_linkDat, Src: linkDat, Size: sizeof(this->m_linkDat));
  this->m_linkID = linkID;
  this->m_pLinkFlow = nullptr;
  this->m_enabled = true;
  this->__vftable = (bfx::LinkImpl_vtbl *)&bfx::LinkImpl::`vftable';
  this->m_startPos = *startPos;
  this->m_endPos = *endPos;
  return this;
}


// ========================================================================
// ?GetStartSeg@LinkImpl@bfx@@UBA?AVLineSeg@2@XZ
// EA  : 0x8325DF38
// RVA : 0x0125DF38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkImpl *__fastcall bfx::LinkImpl::GetStartSeg(bfx::LinkImpl *this, bfx::LineSeg *result)
{
  float m_z; // r7
  int m_x_low; // r6
  int m_y_low; // r5

  m_z = result[4].m_v0.m_z;
  m_x_low = LODWORD(result[4].m_v1.m_x);
  m_y_low = LODWORD(result[4].m_v1.m_y);
  *(float *)&this->__vftable = m_z;
  this->m_pProxy = (bfx::HandleProxy *)m_x_low;
  this->m_pPlanner = (bfx::Planner *)m_y_low;
  *(float *)&this->m_links.m_data = m_z;
  this->m_links.m_size = m_x_low;
  this->m_links.m_cap = m_y_low;
  return this;
}


// ========================================================================
// ?GetEndSeg@LinkImpl@bfx@@UBA?AVLineSeg@2@XZ
// EA  : 0x8325DF70
// RVA : 0x0125DF70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::LinkImpl *__fastcall bfx::LinkImpl::GetEndSeg(bfx::LinkImpl *this, bfx::LineSeg *result)
{
  float m_z; // r7
  int m_x_low; // r6
  int m_y_low; // r5

  m_z = result[4].m_v1.m_z;
  m_x_low = LODWORD(result[5].m_v0.m_x);
  m_y_low = LODWORD(result[5].m_v0.m_y);
  *(float *)&this->__vftable = m_z;
  this->m_pProxy = (bfx::HandleProxy *)m_x_low;
  this->m_pPlanner = (bfx::Planner *)m_y_low;
  *(float *)&this->m_links.m_data = m_z;
  this->m_links.m_size = m_x_low;
  this->m_links.m_cap = m_y_low;
  return this;
}


// ========================================================================
// ?AddHLinkPairBetweenAreas@LinkBase@bfx@@QAAXPAVArea@2@0ABVLineSeg@2@1PAVNavLayer@2@AAV?$ArrayMap@PAVArea@bfx@@@2@@Z
// EA  : 0x8325DFF8
// RVA : 0x0125DFF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::AddHLinkPairBetweenAreas(
        bfx::LinkBase *this,
        bfx::VolumeGraph *pStartArea,
        bfx::VolumeGraph *pEndArea,
        const bfx::LineSeg *startSeg,
        const bfx::LineSeg *endSeg,
        bfx::NavLayer *pNavLayer,
        bfx::ArrayMap<bfx::VolumeGraph *> *islandsTouched)
{
  bfx::Space *v14; // r3
  bfx::HandleProxy **p_m_pProxy; // r10
  _DWORD *p_m_z; // r11
  int i; // ctr
  bfx::Space *v18; // r29
  float m_y; // r10
  char v20; // r11
  _DWORD *v21; // r3
  _DWORD *v22; // r10
  _DWORD *v23; // r11
  int j; // ctr
  _DWORD *v25; // r31
  int v26; // r10
  char v27; // r11
  unsigned int v28; // r4
  unsigned int v29; // r30
  bfx::XGraph *m_pXGraph; // r30
  bfx::XGraph_vtbl *v31; // r11
  bfx::Space *v32; // [sp+50h] [-80h] BYREF

  v14 = (bfx::Space *)bfx::MemoryManager::Malloc(
                        this: bfx::g_pCurInstance->m_pMemoryManager,
                        size: 0x40u,
                        tag: bfx::MEM_BFXPLANNER);
  if ( v14 != nullptr )
  {
    v14->__vftable = (bfx::Space_vtbl *)&bfx::HalfLink::`vftable';
    p_m_pProxy = &v14->m_pProxy;
    v14->m_pProxy = nullptr;
    p_m_z = (_DWORD *)&startSeg[-1].m_v1.m_z;
    for ( i = 6; i != 0; --i )
      *++p_m_pProxy = (bfx::HandleProxy *)*++p_m_z;
    v18 = v14;
    m_y = v14->m_rotWorldToSpace.m_y;
    v20 = HIBYTE(v14->m_rotWorldToSpace.m_x) & 0x1F | 0x80;
    LODWORD(v14->m_rotSpaceToWorld.m_y) = pStartArea;
    v14->m_rotSpaceToWorld.m_z = 0.0;
    v14->m_rotWorldToSpace.m_w = 0.0;
    HIBYTE(v14->m_rotWorldToSpace.m_x) = v20;
    LODWORD(v14->m_rotWorldToSpace.m_y) = LODWORD(m_y) & 0x3FFFFFFF;
    LODWORD(v14->m_rotWorldToSpace.m_z) = this;
    v14->m_userData = (unsigned int)pNavLayer;
    v14->m_matSpaceToWorld.m_data[0] = 0.0;
  }
  else
  {
    v18 = nullptr;
  }
  v32 = v18;
  v21 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x40u, tag: bfx::MEM_BFXPLANNER);
  if ( v21 != nullptr )
  {
    *v21 = &bfx::HalfLink::`vftable';
    v22 = v21 + 1;
    v21[1] = 0;
    v23 = (_DWORD *)&endSeg[-1].m_v1.m_z;
    for ( j = 6; j != 0; --j )
      *++v22 = *++v23;
    v25 = v21;
    v26 = v21[12];
    v27 = v21[11] & 0x1F | 0x80;
    v21[8] = pEndArea;
    v21[13] = this;
    v21[9] = 0;
    v21[10] = 0;
    *((_BYTE *)v21 + 44) = v27;
    v21[12] = v26 & 0x3FFFFFFF | 0x40000000;
    v21[14] = pNavLayer;
    v21[15] = 0;
  }
  else
  {
    v25 = nullptr;
  }
  if ( !this->m_linkDat.m_bidirectional )
    *((_BYTE *)v25 + 44) |= 0x40u;
  if ( pStartArea == pEndArea )
  {
    HIBYTE(v18->m_rotWorldToSpace.m_x) |= 0x20u;
    *((_BYTE *)v25 + 44) |= 0x20u;
  }
  LODWORD(v18->m_rotSpaceToWorld.m_z) = v25;
  v25[9] = v18;
  LODWORD(v18->m_rotWorldToSpace.m_w) = pStartArea->m_pResourceImage;
  pStartArea->m_pResourceImage = (char *const)v18;
  v25[10] = pEndArea->m_pResourceImage;
  pEndArea->m_pResourceImage = (char *const)v25;
  HIBYTE(v18->m_rotWorldToSpace.m_x) = (this->m_enabled << 7) | HIBYTE(v18->m_rotWorldToSpace.m_x) & 0x7F;
  *((_BYTE *)v25 + 44) = (this->m_enabled << 7) | v25[11] & 0x7F;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_links, val: &v32);
  v28 = ((unsigned int)pStartArea->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  v29 = ((unsigned int)pEndArea->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  if ( v28 != v29 )
  {
    bfx::ArrayMap<bfx::Repulsor3D *>::add(this: islandsTouched, key: v28, val: pStartArea);
    bfx::ArrayMap<bfx::Repulsor3D *>::add(this: islandsTouched, key: v29, val: pEndArea);
  }
  m_pXGraph = pNavLayer->m_pXGraph;
  v31 = m_pXGraph->__vftable;
  if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) != 0 )
  {
    v31->UpdateForAddHLink(this: m_pXGraph, a2: (bfx::HalfLink *)v18);
    m_pXGraph->UpdateForAddHLink(this: m_pXGraph, a2: (bfx::HalfLink *)v25);
  }
  else
  {
    v31->MarkDirty(this: m_pXGraph);
  }
}


// ========================================================================
// ?CreateLinksForLayer@LinkImpl@bfx@@UAAXPAVNavLayer@2@PAV?$ArrayMap@PAVArea@bfx@@@2@@Z
// EA  : 0x8325E260
// RVA : 0x0125E260
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkImpl::CreateLinksForLayer(
        bfx::LinkImpl *this,
        bfx::NavLayer *pNavLayer,
        bfx::ArrayMap<bfx::VolumeGraph *> *pIslandsTouchedOut)
{
  double m_maxSnapDist; // fp1
  bfx::Vec3 *p_m_startPos; // r28
  bfx::Vec3 *p_m_endPos; // r27
  bfx::Area *ClosestArea; // r24
  bfx::Area *v10; // r3
  bfx::Area *v11; // r23
  double v12; // fp0
  double v13; // fp13
  bfx::ArrayMap<bfx::VolumeGraph *> *v14; // r30
  bfx::Vec3 v15; // [sp+50h] [-E0h] BYREF
  bfx::Vec3 v16; // [sp+60h] [-D0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v17; // [sp+70h] [-C0h] BYREF
  bfx::LineSeg v18; // [sp+80h] [-B0h] BYREF
  bfx::LineSeg v19; // [sp+A0h] [-90h] BYREF
  bfx::PathSpec v20[3]; // [sp+C0h] [-70h] BYREF

  m_maxSnapDist = this->m_linkDat.m_maxSnapDist;
  v20[0].m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  p_m_startPos = &this->m_startPos;
  v20[0].m_areaUsageFlags = -1;
  v20[0].m_linkUsageFlags = -1;
  v20[0].m_pathSharingPenalty = 0.0;
  v20[0].m_usePathSharingPenalty = false;
  v20[0].m_maxPathSharingPenalty = 0.0;
  v20[0].m_obstacleBlockageFlags = 0;
  v20[0].m_maxSearchDist = 0.0;
  p_m_endPos = &this->m_endPos;
  ClosestArea = bfx::NavLayer::GetClosestArea(
                  this: pNavLayer,
                  pos: &this->m_startPos,
                  pathSpec: v20,
                  radius: m_maxSnapDist);
  v10 = bfx::NavLayer::GetClosestArea(
          this: pNavLayer,
          pos: &this->m_endPos,
          pathSpec: v20,
          radius: this->m_linkDat.m_maxSnapDist);
  v11 = v10;
  if ( ClosestArea != nullptr && v10 != nullptr )
  {
    bfx::GetClosestPosInArea(result: &v15, pArea: ClosestArea, pos: p_m_startPos, pEdgeIndexOut: nullptr);
    bfx::GetClosestPosInArea(result: &v16, pArea: v11, pos: &this->m_endPos, pEdgeIndexOut: nullptr);
    v12 = this->m_linkDat.m_maxSnapDist;
    v13 = __fsqrts((float)((float)((float)(v16.m_z - this->m_endPos.m_z) * (float)(v16.m_z - this->m_endPos.m_z))
                         + (float)((float)((float)(v16.m_x - p_m_endPos->m_x) * (float)(v16.m_x - p_m_endPos->m_x))
                                 + (float)((float)(v16.m_y - this->m_endPos.m_y) * (float)(v16.m_y - this->m_endPos.m_y)))));
    if ( __fsqrts((float)((float)((float)(v15.m_z - p_m_startPos->m_z) * (float)(v15.m_z - p_m_startPos->m_z))
                        + (float)((float)((float)(v15.m_x - p_m_startPos->m_x) * (float)(v15.m_x - p_m_startPos->m_x))
                                + (float)((float)(v15.m_y - p_m_startPos->m_y) * (float)(v15.m_y - p_m_startPos->m_y))))) < v12
      && v13 < v12 )
    {
      v19.m_v0 = v15;
      v19.m_v1 = v15;
      v18.m_v0 = v16;
      v18.m_v1 = v16;
      memset(&v17, 0, 12);
      v17.m_tag = MEM_TEMP;
      v14 = pIslandsTouchedOut;
      if ( pIslandsTouchedOut == nullptr )
        v14 = (bfx::ArrayMap<bfx::VolumeGraph *> *)&v17;
      bfx::LinkBase::AddHLinkPairBetweenAreas(
        this,
        pStartArea: (bfx::VolumeGraph *)ClosestArea,
        pEndArea: (bfx::VolumeGraph *)v11,
        startSeg: &v19,
        endSeg: &v18,
        pNavLayer,
        islandsTouched: v14);
      if ( pIslandsTouchedOut == nullptr )
        bfx::IslandGraph::RefreshLinkData(
          this: pNavLayer->m_pIslandGraph,
          islandsTouched: (bfx::ArrayMap<bfx::Area *> *)v14);
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v17);
    }
  }
  if ( pIslandsTouchedOut == nullptr )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)pNavLayer);
}


// ========================================================================
// __unwind$88365
// EA  : 0x8325E458
// RVA : 0x0125E458
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88365()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 112));
}


// ========================================================================
// ?CreateLinksForLayer@LinkStripImpl@bfx@@UAAXPAVNavLayer@2@PAV?$ArrayMap@PAVArea@bfx@@@2@@Z
// EA  : 0x8325E488
// RVA : 0x0125E488
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkStripImpl::CreateLinksForLayer(
        bfx::LinkStripImpl *this,
        bfx::NavLayer *pNavLayer,
        bfx::ArrayMap<bfx::Area *> *pIslandsTouchedOut)
{
  int *v3; // r10
  bfx::ArrayMap<bfx::Area *> *v6; // r21
  bfx::LinkFlowBase **v7; // r11
  int i; // ctr
  int *v9; // r10
  float *p_m_z; // r11
  int j; // ctr
  bfx::Vec3 *v12; // r4
  bfx::Vec3 *v13; // r4
  bfx::Vec3 *v14; // r4
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  double v18; // fp28
  double v19; // fp27
  double v20; // fp26
  bfx::NavLayer *v21; // r5
  bfx::NavLayer *v22; // r5
  bfx::ArrayMap<bfx::VolumeGraph *> *v23; // r24
  bfx::ResourceManager::Registration *m_data; // r29
  bfx::ResourceManager::Registration *v25; // r26
  int m_size; // r23
  void (__fastcall **p_m_termCB)(bfx::Space *, unsigned int, bfx::BinaryImageIn *); // r29
  int k; // r22
  bfx::ResourceManager::Registration *v29; // r30
  int m; // r26
  bfx::Vec3 v35; // [sp+50h] [-210h] BYREF
  bfx::Vec3 v36; // [sp+60h] [-200h] BYREF
  bfx::Vec3 v37; // [sp+70h] [-1F0h] BYREF
  bfx::Vec3 v38; // [sp+80h] [-1E0h] BYREF
  int v39; // [sp+8Ch] [-1D4h] BYREF
  bfx::LineSeg v40; // [sp+90h] [-1D0h] BYREF
  int v41; // [sp+ACh] [-1B4h] BYREF
  bfx::LineSeg v42; // [sp+B0h] [-1B0h] BYREF
  void *v43; // [sp+D0h] [-190h] BYREF
  int v44; // [sp+D4h] [-18Ch]
  int v45; // [sp+D8h] [-188h]
  int v46; // [sp+DCh] [-184h]
  bfx::Array<bfx::ResourceManager::Registration> v47; // [sp+E0h] [-180h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v48; // [sp+F0h] [-170h] BYREF
  bfx::LineSeg v49; // [sp+100h] [-160h] BYREF
  bfx::LineSeg v50; // [sp+120h] [-140h] BYREF
  bfx::Vec3 v51; // [sp+138h] [-128h] BYREF
  bfx::Vec3 v52; // [sp+148h] [-118h] BYREF
  bfx::Vec3 v53; // [sp+158h] [-108h] BYREF
  bfx::Vec3 v54[8]; // [sp+168h] [-F8h] BYREF

  v3 = &v41;
  v6 = pIslandsTouchedOut;
  v7 = &this->m_pLinkFlow + 1;
  for ( i = 6; i != 0; --i )
    *++v3 = (int)*++v7;
  v9 = &v39;
  p_m_z = &this->m_start.m_v1.m_z;
  for ( j = 6; j != 0; --j )
    *++v9 = *(_DWORD *)++p_m_z;
  bfx::SnapLinkStripEndPosOntoNavGraph(
    pNavLayer,
    maxSnapDist: this->m_linkDat.m_maxSnapDist,
    pos: (bfx::Vec3 *)pNavLayer,
    a4: &v42.m_v0);
  bfx::SnapLinkStripEndPosOntoNavGraph(pNavLayer, maxSnapDist: this->m_linkDat.m_maxSnapDist, pos: v12, a4: &v42.m_v1);
  bfx::SnapLinkStripEndPosOntoNavGraph(pNavLayer, maxSnapDist: this->m_linkDat.m_maxSnapDist, pos: v13, a4: &v40.m_v0);
  bfx::SnapLinkStripEndPosOntoNavGraph(pNavLayer, maxSnapDist: this->m_linkDat.m_maxSnapDist, pos: v14, a4: &v40.m_v1);
  memset(&v48, 0, 12);
  v48.m_tag = MEM_TEMP;
  v15 = (float)(v42.m_v1.m_z - v42.m_v0.m_z);
  v16 = (float)(v42.m_v1.m_y - v42.m_v0.m_y);
  v17 = (float)(v42.m_v1.m_x - v42.m_v0.m_x);
  v18 = (float)(v40.m_v1.m_z - v40.m_v0.m_z);
  v19 = (float)(v40.m_v1.m_y - v40.m_v0.m_y);
  v20 = (float)(v40.m_v1.m_x - v40.m_v0.m_x);
  bfx::CalcAreaSegs(
    origSeg: &v42,
    farSeg: &v40,
    tol: this->m_linkDat.m_maxSnapDist,
    pNavLayer: v21,
    segs: pNavLayer,
    a6: &v48);
  memset(&v47, 0, 12);
  v47.m_tag = MEM_TEMP;
  bfx::CalcAreaSegs(
    origSeg: &v40,
    farSeg: &v42,
    tol: this->m_linkDat.m_maxSnapDist,
    pNavLayer: v22,
    segs: pNavLayer,
    a6: &v47);
  v44 = 0;
  v43 = nullptr;
  v45 = 0;
  v46 = 2;
  v23 = (bfx::ArrayMap<bfx::VolumeGraph *> *)v6;
  if ( v6 == nullptr )
    v23 = (bfx::ArrayMap<bfx::VolumeGraph *> *)&v43;
  m_data = v48.m_data;
  v25 = v47.m_data;
  if ( v48.m_size > 0 )
  {
    m_size = v47.m_size;
    p_m_termCB = &v48.m_data->m_termCB;
    for ( k = v48.m_size; k != 0; --k )
    {
      if ( m_size > 0 )
      {
        v29 = v25;
        for ( m = m_size; m != 0; --m )
        {
          _FP10 = (float)(*((float *)p_m_termCB - 1) - *(float *)&v29->m_initCB);
          _FP9 = (float)(*(float *)p_m_termCB - *(float *)&v29->m_termCB);
          __asm
          {
            fsel      f0, f10, f0, f12
            fsel      f13, f9, f11, f13
          }
          if ( _FP0 < _FP13 )
          {
            v35.m_y = (float)((float)v16 * (float)_FP0) + v42.m_v0.m_y;
            v35.m_z = (float)((float)v15 * (float)_FP0) + v42.m_v0.m_z;
            v36.m_y = (float)((float)v16 * (float)_FP13) + v42.m_v0.m_y;
            v36.m_z = (float)((float)v15 * (float)_FP13) + v42.m_v0.m_z;
            v38.m_y = (float)((float)v19 * (float)_FP0) + v40.m_v0.m_y;
            v38.m_z = (float)((float)v18 * (float)_FP0) + v40.m_v0.m_z;
            v37.m_y = (float)((float)v19 * (float)_FP13) + v40.m_v0.m_y;
            v37.m_z = (float)((float)v18 * (float)_FP13) + v40.m_v0.m_z;
            v35.m_x = (float)((float)v17 * (float)_FP0) + v42.m_v0.m_x;
            v36.m_x = (float)((float)v17 * (float)_FP13) + v42.m_v0.m_x;
            v38.m_x = (float)((float)v20 * (float)_FP0) + v40.m_v0.m_x;
            v37.m_x = (float)((float)v20 * (float)_FP13) + v40.m_v0.m_x;
            v35 = *bfx::GetClosestPosInArea(
                     result: &v52,
                     pArea: (const bfx::Area *)*(p_m_termCB - 2),
                     pos: &v35,
                     pEdgeIndexOut: nullptr);
            v36 = *bfx::GetClosestPosInArea(
                     result: v54,
                     pArea: (const bfx::Area *)*(p_m_termCB - 2),
                     pos: &v36,
                     pEdgeIndexOut: nullptr);
            v38 = *bfx::GetClosestPosInArea(
                     result: &v53,
                     pArea: (const bfx::Area *)v29->m_id,
                     pos: &v38,
                     pEdgeIndexOut: nullptr);
            v37 = *bfx::GetClosestPosInArea(
                     result: &v51,
                     pArea: (const bfx::Area *)v29->m_id,
                     pos: &v37,
                     pEdgeIndexOut: nullptr);
            if ( (int)p_m_termCB[1] >= 0 && (int)v29->m_isUpToDateCB >= 0 )
              goto LABEL_15;
            if ( *(p_m_termCB - 2) != (void (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *))v29->m_id )
            {
LABEL_15:
              v50.m_v0 = v38;
              v50.m_v1 = v37;
              v49.m_v0 = v35;
              v49.m_v1 = v36;
              bfx::LinkBase::AddHLinkPairBetweenAreas(
                this,
                pStartArea: (bfx::VolumeGraph *)*(p_m_termCB - 2),
                pEndArea: (bfx::VolumeGraph *)v29->m_id,
                startSeg: &v49,
                endSeg: &v50,
                pNavLayer,
                islandsTouched: v23);
            }
          }
          ++v29;
        }
        v25 = v47.m_data;
        v6 = pIslandsTouchedOut;
      }
      p_m_termCB += 4;
    }
    m_data = v48.m_data;
  }
  if ( v6 == nullptr )
  {
    bfx::IslandGraph::RefreshLinkData(
      this: pNavLayer->m_pIslandGraph,
      islandsTouched: (bfx::ArrayMap<bfx::Area *> *)v23);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)pNavLayer);
  }
  v44 = 0;
  if ( v43 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v43);
    v43 = nullptr;
  }
  v45 = 0;
  if ( v25 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v25);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$88468
// EA  : 0x8325E8FC
// RVA : 0x0125E8FC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88468()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 608 + 240));
}


// ========================================================================
// __unwind$88469
// EA  : 0x8325E924
// RVA : 0x0125E924
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88469()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 608 + 224));
}


// ========================================================================
// __unwind$88470
// EA  : 0x8325E94C
// RVA : 0x0125E94C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88470()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 608 + 208));
}


// ========================================================================
// ?DestroyLinkPair@bfx@@YAXPAVHalfLink@1@PAVIslandsTouchedArray@1@@Z
// EA  : 0x8325E980
// RVA : 0x0125E980
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::DestroyLinkPair(bfx::HalfLink *pLink, bfx::IslandsTouchedArray *pIslandsTouchedArray)
{
  bfx::HalfLink *m_pTwin; // r11
  bfx::NavLayer *m_pNavLayer; // r27
  bfx::VolumeGraph *m_pArea; // r26
  bfx::VolumeGraph *v6; // r28
  unsigned int v7; // r30
  unsigned int v8; // r29
  bfx::ArrayMap<bfx::VolumeGraph *> *ArrayMapForLayer; // r27
  bfx::Array<bfx::SpaceComponent *> v10[6]; // [sp+50h] [-60h] BYREF

  m_pTwin = pLink->m_pTwin;
  m_pNavLayer = pLink->m_pNavLayer;
  m_pArea = (bfx::VolumeGraph *)pLink->m_pArea;
  if ( m_pTwin != nullptr )
    v6 = (bfx::VolumeGraph *)m_pTwin->m_pArea;
  else
    v6 = nullptr;
  v7 = ((unsigned int)m_pArea->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  v8 = ((unsigned int)v6->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  bfx::RemoveLinkPair(pNavLayer: pLink->m_pNavLayer, pLink);
  if ( v7 != v8 )
  {
    if ( pIslandsTouchedArray != nullptr )
    {
      ArrayMapForLayer = (bfx::ArrayMap<bfx::VolumeGraph *> *)bfx::IslandsTouchedArray::GetArrayMapForLayer(
                                                                this: pIslandsTouchedArray,
                                                                layerNum: m_pNavLayer->m_layerIndex);
      bfx::ArrayMap<bfx::Repulsor3D *>::add(this: ArrayMapForLayer, key: v7, val: m_pArea);
      bfx::ArrayMap<bfx::Repulsor3D *>::add(this: ArrayMapForLayer, key: v8, val: v6);
    }
    else
    {
      memset(v10, 0, 12);
      v10[0].m_tag = MEM_TEMP;
      bfx::ArrayMap<bfx::Repulsor3D *>::add(this: (bfx::ArrayMap<bfx::VolumeGraph *> *)v10, key: v7, val: m_pArea);
      bfx::ArrayMap<bfx::Repulsor3D *>::add(this: (bfx::ArrayMap<bfx::VolumeGraph *> *)v10, key: v8, val: v6);
      bfx::IslandGraph::RefreshLinkData(
        this: m_pNavLayer->m_pIslandGraph,
        islandsTouched: (bfx::ArrayMap<bfx::Area *> *)v10);
      bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v10);
    }
  }
}


// ========================================================================
// __unwind$88862
// EA  : 0x8325EA64
// RVA : 0x0125EA64
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88862()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 80));
}


// ========================================================================
// ?RemoveLinkFromLayers@LinkBase@bfx@@QAAXIPAVIslandsTouchedArray@2@@Z
// EA  : 0x8325EA90
// RVA : 0x0125EA90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::RemoveLinkFromLayers(
        bfx::LinkBase *this,
        unsigned int layersToRemoveFrom,
        bfx::IslandsTouchedArray *pIslandsTouchedArray)
{
  bfx::Array<bfx::HalfLink *> *p_m_links; // r31
  int v6; // r28
  int v7; // r30
  bfx::HalfLink *v8; // r3
  bfx::HalfLink **v9; // r3
  unsigned int v10; // r11

  p_m_links = &this->m_links;
  v6 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = p_m_links->m_data[v7];
      if ( ((1 << v8->m_pNavLayer->m_layerIndex) & layersToRemoveFrom) != 0 )
      {
        bfx::DestroyLinkPair(pLink: v8, pIslandsTouchedArray);
        v9 = &p_m_links->m_data[v7];
        v10 = (unsigned int)&p_m_links->m_data[p_m_links->m_size - 1];
        if ( (unsigned int)v9 < v10 )
          blkmov(a1: v9, a2: v9 + 1, a3: 4 * (((v10 - (unsigned int)v9 - 1) >> 2) + 1));
        --p_m_links->m_size;
      }
      else
      {
        ++v6;
        ++v7;
      }
    }
    while ( v6 < p_m_links->m_size );
  }
}


// ========================================================================
// ?RemoveLinksFromLayers@bfx@@YAXPAVPlanner@1@AAV?$Array@PAVLinkBase@bfx@@@1@I@Z
// EA  : 0x8325EB60
// RVA : 0x0125EB60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::RemoveLinksFromLayers(
        bfx::Planner *pPlanner,
        bfx::Array<bfx::LinkBase *> *links,
        unsigned int layersToRemoveFrom)
{
  int v6; // r30
  int v7; // r29
  bfx::IslandsTouchedArray v8; // [sp+50h] [-C0h] BYREF

  bfx::IslandsTouchedArray::IslandsTouchedArray(this: &v8);
  v6 = 0;
  if ( links->m_size > 0 )
  {
    v7 = 0;
    do
    {
      bfx::LinkBase::RemoveLinkFromLayers(this: links->m_data[v7], layersToRemoveFrom, pIslandsTouchedArray: &v8);
      ++v6;
      ++v7;
    }
    while ( v6 < links->m_size );
  }
  bfx::RefreshIslandsTouched(pPlanner, islandsTouchedArray: &v8);
  bfx::IslandsTouchedArray::~IslandsTouchedArray(this: &v8);
}


// ========================================================================
// __unwind$88982
// EA  : 0x8325EBDC
// RVA : 0x0125EBDC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void _unwind_88982()
{
  int v0; // r12

  bfx::IslandsTouchedArray::~IslandsTouchedArray(this: (bfx::IslandsTouchedArray *)(v0 - 272 + 80));
}


// ========================================================================
// ?CreateLink@Planner@bfx@@QAAPAVLinkBase@2@ABVVec3@2@0ABVLinkDat@2@I@Z
// EA  : 0x8325EC08
// RVA : 0x0125EC08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

bfx::Space *__fastcall bfx::Planner::CreateLink(
        bfx::Planner *this,
        const bfx::Vec3 *start,
        const bfx::Vec3 *end,
        const bfx::LinkDat *inputLinkDat,
        __int64 linkID)
{
  unsigned int v8; // r28
  int v9; // ctr
  bfx::LinkFlowTune *p_m_flowTune; // r9
  __int64 v11; // r11
  bfx::LinkImpl *v12; // r3
  bfx::Space *v13; // r31
  bfx::Space *v15; // [sp+50h] [-70h] BYREF
  bfx::LinkDat v16; // [sp+60h] [-60h] BYREF

  v8 = HIDWORD(linkID);
  v9 = 7;
  p_m_flowTune = &inputLinkDat[-1].m_flowTune;
  do
  {
    p_m_flowTune += 2;
    v11 = *(_QWORD *)&p_m_flowTune->m_maxSimultaneous;
    HIDWORD(v11) = p_m_flowTune->m_maxSimultaneous + 8;
    *(_QWORD *)HIDWORD(v11) = v11;
    --v9;
  }
  while ( v9 != 0 );
  bfx::ApplyLimits_LinkDat(linkDat: &v16, a2: (int)start, a3: (int)end, a4: (int)inputLinkDat, a5: linkID);
  v12 = (bfx::LinkImpl *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x80u,
                           tag: bfx::MEM_BFXPLANNER);
  if ( v12 != nullptr )
    v13 = (bfx::Space *)bfx::LinkImpl::LinkImpl(
                          this: v12,
                          pPlanner: this,
                          startPos: start,
                          endPos: end,
                          linkDat: &v16,
                          linkID: v8);
  else
    v13 = nullptr;
  v15 = v13;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_links, val: &v15);
  bfx::LinkBase::ApplyLinkToLayers(
    this: (bfx::LinkBase *)v13,
    layersToApplyTo: v16.m_layerMask,
    pIslandsTouchedArray: nullptr);
  return v13;
}


// ========================================================================
// ?DestroyLink@Planner@bfx@@QAAXPAVLinkBase@2@@Z
// EA  : 0x8325ECC0
// RVA : 0x0125ECC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::Planner::DestroyLink(
        bfx::Planner *this,
        bfx::Space *pLink,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  a14 = pLink;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&this->m_links, val: &a14);
  bfx::LinkBase::RemoveLinkFromLayers(
    this: (bfx::LinkBase *)pLink,
    layersToRemoveFrom: LODWORD(pLink->m_rotSpaceToWorld.m_y),
    pIslandsTouchedArray: nullptr);
  ((void (__fastcall *)(bfx::Space *, int))pLink->dtr_HandleTargetBase)(a1: pLink, a2: 1);
}


// ========================================================================
// ?SetLayerMask@LinkBase@bfx@@QAAXI@Z
// EA  : 0x8325ED80
// RVA : 0x0125ED80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::SetLayerMask(bfx::LinkBase *this, unsigned int layerMask)
{
  unsigned int m_layerMask; // r11
  unsigned int v5; // r29

  m_layerMask = this->m_linkDat.m_layerMask;
  v5 = ~(m_layerMask & layerMask);
  bfx::LinkBase::RemoveLinkFromLayers(this, layersToRemoveFrom: v5 & m_layerMask, pIslandsTouchedArray: nullptr);
  bfx::LinkBase::ApplyLinkToLayers(this, layersToApplyTo: v5 & layerMask, pIslandsTouchedArray: nullptr);
  this->m_linkDat.m_layerMask = layerMask;
}


// ========================================================================
// ?SetLinkDat@LinkBase@bfx@@QAAXABVLinkDat@2@@Z
// EA  : 0x8325EDC8
// RVA : 0x0125EDC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

void __fastcall bfx::LinkBase::SetLinkDat(bfx::LinkBase *this, const bfx::LinkDat *newLinkDat)
{
  unsigned int m_layerMask; // r30
  unsigned int v4; // r11
  bfx::LinkDat *p_m_linkDat; // r28
  int v7; // r27
  BOOL m_bidirectional; // r4
  unsigned int m_linkUsageFlags; // r4
  bfx::LinkFlowTune *p_m_flowTune; // r11
  bfx::LinkFlowTune *v11; // r10
  int i; // ctr

  m_layerMask = newLinkDat->m_layerMask;
  v4 = this->m_linkDat.m_layerMask;
  p_m_linkDat = &this->m_linkDat;
  if ( newLinkDat->m_layerMask != v4 )
  {
    v7 = ~(v4 & m_layerMask);
    bfx::LinkBase::RemoveLinkFromLayers(this, layersToRemoveFrom: v7 & v4, pIslandsTouchedArray: nullptr);
    bfx::LinkBase::ApplyLinkToLayers(this, layersToApplyTo: v7 & m_layerMask, pIslandsTouchedArray: nullptr);
    p_m_linkDat->m_layerMask = m_layerMask;
  }
  m_bidirectional = newLinkDat->m_bidirectional;
  if ( m_bidirectional != this->m_linkDat.m_bidirectional )
    bfx::LinkBase::SetBidirectional(this, bidirectional: m_bidirectional);
  m_linkUsageFlags = newLinkDat->m_linkUsageFlags;
  if ( m_linkUsageFlags != this->m_linkDat.m_linkUsageFlags )
    bfx::LinkBase::SetLinkUsageFlags(this, linkUsageFlags: m_linkUsageFlags);
  p_m_flowTune = &newLinkDat[-1].m_flowTune;
  v11 = &p_m_linkDat[-1].m_flowTune;
  for ( i = 7; i != 0; --i )
  {
    p_m_flowTune += 2;
    v11 += 2;
    *(_QWORD *)&v11->m_maxSimultaneous = *(_QWORD *)&p_m_flowTune->m_maxSimultaneous;
  }
}


// ========================================================================
// bfx::`dynamic initializer for 'ORIGINAL_LINK_LOCATION_COLOR''
// EA  : 0x83398338
// RVA : 0x01398338
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxlink.cpp
// ========================================================================

__int64 bfx::_dynamic_initializer_for__ORIGINAL_LINK_LOCATION_COLOR__()
{
  __int64 result; // r4

  LODWORD(result) = LODWORD(ColorCyan_4.m_a);
  bfx::ORIGINAL_LINK_LOCATION_COLOR = ColorCyan_4;
  return result;
}

