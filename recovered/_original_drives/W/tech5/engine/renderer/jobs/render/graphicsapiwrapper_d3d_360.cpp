
// ========================================================================
// ?GL_SetWrapperContext@@YAXABUwrapperContext_t@@@Z
// EA  : 0x828D5158
// RVA : 0x008D5158
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_SetWrapperContext(const wrapperContext_t *context)
{
  wrapperContext = *context;
  renderStateDX.currentOcclusionQueryBatch = 16;
  renderStateDX.currentOcclusionQuery = 0x1000000000LL;
  renderStateDX.lastCachedOcclusionBatch = 16;
  renderStateDX.drawElementsSinceLastEndQuery = false;
}


// ========================================================================
// ?GL_SetWrapperConfig@@YAXABUwrapperConfig_t@@@Z
// EA  : 0x828D51B0
// RVA : 0x008D51B0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_SetWrapperConfig(const wrapperConfig_t *config)
{
  _DWORD *p_textureLODBias; // r11
  _DWORD *v2; // r10
  int i; // ctr

  p_textureLODBias = (_DWORD *)&config[-1].textureLODBias;
  v2 = &unk_837303CC;
  for ( i = 10; i != 0; --i )
    *++v2 = *++p_textureLODBias;
}


// ========================================================================
// ?TimingCallback@@YAXK@Z
// EA  : 0x828D51D8
// RVA : 0x008D51D8
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall TimingCallback(int tag)
{
  unsigned __int64 v2; // r3

  LODWORD(v2) = Sys_Microseconds() >> 32;
  *(&renderStateDX.gpuTiming[0].microseconds
  + (renderStateDX.numGpuTiming & 7)
  + ((2 * renderStateDX.numGpuTiming) & 0xE)) = v2;
  *(&renderStateDX.gpuTiming[0].tag
  + 2 * (renderStateDX.numGpuTiming & 7)
  + 2 * ((2 * renderStateDX.numGpuTiming++) & 0xE)) = tag;
}


// ========================================================================
// ?GL_StartFrame@@YAXH@Z
// EA  : 0x828D5250
// RVA : 0x008D5250
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_StartFrame(int frame)
{
  unsigned __int64 v1; // r3
  D3DDevice *d3d; // r11

  renderStateDX.frameNumber = frame;
  LODWORD(v1) = Sys_Microseconds() >> 32;
  d3d = wrapperContext.d3d;
  *(&renderStateDX.gpuTiming[0].cpuMicroseconds
  + (renderStateDX.numGpuTiming & 7)
  + ((2 * renderStateDX.numGpuTiming) & 0xE)) = v1;
  D3DDevice_InsertCallback(
    pDevice: d3d,
    Type: 0x20000000u,
    pCallback: (void (__fastcall *)(unsigned int))TimingCallback,
    Context: 0);
}


// ========================================================================
// ?GL_EndFrame@@YAXXZ
// EA  : 0x828D52C0
// RVA : 0x008D52C0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_EndFrame()
{
  unsigned __int64 v0; // r3
  D3DDevice *d3d; // r10

  LODWORD(v0) = Sys_Microseconds() >> 32;
  d3d = wrapperContext.d3d;
  *(&renderStateDX.gpuTiming[0].cpuMicroseconds
  + (renderStateDX.numGpuTiming & 7)
  + ((2 * renderStateDX.numGpuTiming) & 0xE)) = v0;
  D3DDevice_InsertCallback(
    pDevice: d3d,
    Type: 0x20000000u,
    pCallback: (void (__fastcall *)(unsigned int))TimingCallback,
    Context: 1u);
  renderStateDX.endFencePoint = D3DDevice_InsertFence(pDevice: wrapperContext.d3d);
}


// ========================================================================
// ?GL_WaitForEndFrame@@YAXXZ
// EA  : 0x828D5340
// RVA : 0x008D5340
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_WaitForEndFrame()
{
  unsigned __int64 v0; // r3
  unsigned __int64 v1; // r3

  LODWORD(v0) = Sys_Microseconds() >> 32;
  renderStateDX.fenceWaitStartMicroSec = v0;
  D3DDevice_BlockOnFence(Fence: renderStateDX.endFencePoint);
  LODWORD(v1) = Sys_Microseconds() >> 32;
  renderStateDX.fenceWaitEndMicroSec = v1;
}


// ========================================================================
// ?GL_GetLastFrameTime@@YAXAA_K0@Z
// EA  : 0x828D5388
// RVA : 0x008D5388
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_GetLastFrameTime(unsigned __int64 *startGPUTimeMicroSec, unsigned __int64 *endGPUTimeMicroSec)
{
  unsigned __int64 v2; // r11
  int v3; // r9
  gpuTiming_t *v4; // r11
  gpuTiming_t *v5; // r10
  unsigned __int64 microseconds; // r9
  __int64 v7; // r11

  HIDWORD(v2) = renderStateDX.numGpuTiming;
  if ( renderStateDX.numGpuTiming >= 2 )
  {
    v3 = (LOBYTE(renderStateDX.numGpuTiming) - 1) & 7;
    if ( renderStateDX.gpuTiming[v3].tag == 1 )
    {
      v4 = &renderStateDX.gpuTiming[v3];
      v5 = &renderStateDX.gpuTiming[(LOBYTE(renderStateDX.numGpuTiming) - 2) & 7];
    }
    else
    {
      v5 = &renderStateDX.gpuTiming[(LOBYTE(renderStateDX.numGpuTiming) - 3) & 7];
      v4 = &renderStateDX.gpuTiming[(LOBYTE(renderStateDX.numGpuTiming) - 2) & 7];
    }
    microseconds = v5->microseconds;
    HIDWORD(microseconds) = &idInGameVideoFile::resourceList.hashTable[109];
    *startGPUTimeMicroSec = microseconds;
    *endGPUTimeMicroSec = v4->microseconds;
    LODWORD(microseconds) = LODWORD(v4->cpuMicroseconds) - LODWORD(v5->cpuMicroseconds);
    *(_QWORD *)(HIDWORD(microseconds) + 17936) = microseconds;
    if ( (int)microseconds > 20000 )
      ++longCpuFrame;
    v7 = v4->microseconds;
    LODWORD(v7) = v7 - *(_DWORD *)(HIDWORD(v7) + 12);
    gpuMicroseconds = v7;
    if ( (int)v7 > 20000 )
      ++longGpuFrame;
  }
  else
  {
    LODWORD(v2) = 0;
    *startGPUTimeMicroSec = v2;
    *endGPUTimeMicroSec = v2;
  }
}


// ========================================================================
// ?GL_Flush@@YAXXZ
// EA  : 0x828D54A0
// RVA : 0x008D54A0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_Flush()
{
  D3DDevice_InsertFence(pDevice: wrapperContext.d3d);
}


// ========================================================================
// ?GL_Finish@@YAXXZ
// EA  : 0x828D54B0
// RVA : 0x008D54B0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_Finish()
{
  D3DDevice_BlockUntilIdle(pDevice: wrapperContext.d3d);
}


// ========================================================================
// ?GL_State@@YAX_K_N@Z
// EA  : 0x828D54C0
// RVA : 0x008D54C0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_State(unsigned __int64 stateBits, bool forceGlState)
{
  unsigned __int64 v2; // r28
  int v3; // r26
  unsigned int v4; // r4
  unsigned int v5; // r11
  unsigned int v6; // r4
  unsigned int v7; // r11
  unsigned int v8; // r11
  int v9; // r10
  unsigned int v10; // r11
  unsigned int v11; // r11
  unsigned int v12; // r10
  unsigned int v13; // r4
  unsigned int v14; // r31
  unsigned int v15; // r4
  double v16; // fp31
  unsigned int v17; // r4
  unsigned int v18; // [sp+50h] [-70h]
  unsigned int v19; // [sp+50h] [-70h]
  unsigned int v20; // [sp+50h] [-70h]

  LODWORD(v2) = HIDWORD(stateBits);
  if ( wrapperConfig.forceTwoSided )
    LODWORD(v2) = HIDWORD(stateBits) | 0x8000;
  if ( wrapperConfig.disableStateCaching || (_BYTE)stateBits != 0 )
  {
    v3 = -1;
  }
  else
  {
    v3 = LODWORD(renderStateDX.currentState) ^ v2;
    if ( LODWORD(renderStateDX.currentState) == (unsigned int)v2 )
      return;
  }
  if ( (v2 & 0x8000) != 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = 2;
    if ( (v2 & 0x10000) == 0 )
      v4 = 6;
  }
  D3DDevice_SetRenderState_CullMode(pDevice: wrapperContext.d3d, Value: v4);
  if ( (v3 & 0x6000) != 0 )
  {
    v5 = v2 & 0x6000;
    v6 = 0;
    if ( v5 <= 0x6000 )
    {
      if ( v5 > 0x4000 )
      {
        if ( v5 == 24576 )
          v6 = 2;
      }
      else if ( v5 == 0x4000 )
      {
        v6 = 7;
      }
      else if ( (v2 & 0x6000) != 0 )
      {
        if ( v5 == 0x2000 )
          v6 = 3;
      }
      else
      {
        v6 = 6;
      }
    }
    D3DDevice_SetRenderState_ZFunc(pDevice: wrapperContext.d3d, Value: v6);
  }
  HIDWORD(v2) = 1;
  if ( (v3 & 0xC003F) != 0 )
  {
    v7 = v2 & 0xC0000;
    if ( (v2 & 0xC0000) <= 0xC0000 )
    {
      if ( v7 > 0x80000 )
      {
        if ( v7 == 786432 )
        {
          v8 = v18 & 0xFFFFFF1F | 0x60;
          goto LABEL_36;
        }
      }
      else
      {
        switch ( v7 )
        {
          case 0x80000u:
            v8 = v18 & 0xFFFFFF1F | 0x40;
            goto LABEL_36;
          case 0u:
            v8 = v18 & 0xFFFFFF1F;
            goto LABEL_36;
          case 0x40000u:
            v8 = v18 & 0xFFFFFF1F | 0x80;
LABEL_36:
            v9 = v2 & 7;
            v10 = v8 & 0xFFFF00E0 | 0x101;
            if ( (v2 & 7) != 0 )
            {
              switch ( v9 )
              {
                case 1:
                  v11 = v10 & 0xFFFFFFE0;
                  break;
                case 2:
                  v11 = v10 & 0xFFFFFFE0 | 8;
                  break;
                case 3:
                  v11 = v10 & 0xFFFFFFE0 | 9;
                  break;
                case 4:
                  v11 = v10 & 0xFFFFFFE0 | 6;
                  break;
                case 5:
                  v11 = v10 & 0xFFFFFFE0 | 7;
                  break;
                case 6:
                  v11 = v10 & 0xFFFFFFE0 | 0xA;
                  break;
                default:
                  v11 = v10 & 0xFFFFFFE0 | 0xB;
                  break;
              }
            }
            else
            {
              v11 = v10 & 0xFFFFFFE0 | 1;
            }
            v12 = v2 & 0x38;
            if ( v12 <= 0x38 )
            {
              if ( v12 > 0x20 )
              {
                switch ( v12 )
                {
                  case '(':
                    v11 = v11 & 0xFFFF00FF | 0x700;
                    break;
                  case '0':
                    v11 = v11 & 0xFFFF00FF | 0xA00;
                    break;
                  case '8':
                    v11 = v11 & 0xFFFF00FF | 0xB00;
                    break;
                  default:
                    break;
                }
              }
              else if ( v12 == 32 )
              {
                v11 = v11 & 0xFFFF00FF | 0x600;
              }
              else if ( v12 > 0x10 )
              {
                if ( v12 == 24 )
                  v11 = v11 & 0xFFFF00FF | 0x500;
              }
              else if ( v12 == 16 )
              {
                v11 = v11 & 0xFFFF00FF | 0x400;
              }
              else if ( (v2 & 0x38) != 0 )
              {
                if ( v12 == 8 )
                  v11 = v11 & 0xFFFF00FF | 0x100;
              }
              else
              {
                v11 &= 0xFFFF00FF;
              }
            }
            D3DDevice_SetBlendState(
              pDevice: wrapperContext.d3d,
              RenderTargetIndex: 0,
              BlendState: (_D3DBLENDSTATE *)((((((v11 << 16) & 0xE00000 | v11 & 0xFF1FFFFF) << 16) & 0xFF000000
                                 | (v11 << 16) & 0xE00000
                                 | v11 & 0x1FFFFF) << 16)
                               & 0x1F0000
                               | (((v11 << 16) & 0xE00000 | v11 & 0xFF1FFFFF) << 16) & 0xFF000000
                               | (v11 << 16) & 0xE00000
                               | (unsigned __int16)v11));
            goto LABEL_71;
          default:
            break;
        }
      }
    }
    v8 = v18;
    goto LABEL_36;
  }
LABEL_71:
  if ( (v3 & 0x40) != 0 )
  {
    if ( (v2 & 0x40) != 0 )
    {
      D3DDevice_SetRenderState_ZWriteEnable(pDevice: wrapperContext.d3d, Value: 0);
      v13 = 0;
    }
    else
    {
      D3DDevice_SetRenderState_ZWriteEnable(pDevice: wrapperContext.d3d, Value: 1u);
      v13 = 2;
    }
    D3DDevice_SetRenderState_HiZWriteEnable(pDevice: wrapperContext.d3d, Value: v13);
  }
  if ( (v3 & 0x780) != 0 )
  {
    v14 = (v2 & 0x80) == 0;
    if ( (v2 & 0x100) == 0 )
      v14 |= 2u;
    if ( (v2 & 0x200) == 0 )
      v14 |= 4u;
    if ( (v2 & 0x400) == 0 )
      v14 |= 8u;
    D3DDevice_SetRenderState_ColorWriteEnable(pDevice: wrapperContext.d3d, Value: v14);
    D3DDevice_SetRenderState_ColorWriteEnable1(pDevice: wrapperContext.d3d, Value: v14);
    D3DDevice_SetRenderState_ColorWriteEnable2(pDevice: wrapperContext.d3d, Value: v14);
    D3DDevice_SetRenderState_ColorWriteEnable3(pDevice: wrapperContext.d3d, Value: v14);
  }
  if ( (v3 & 0x800) != 0 )
  {
    v15 = 37;
    if ( (v2 & 0x800) == 0 )
      v15 = 0;
    D3DDevice_SetRenderState_FillMode(pDevice: wrapperContext.d3d, Value: v15);
  }
  if ( (v3 & 0x20000) != 0 )
    D3DDevice_SetRenderState_AlphaToMaskEnable(pDevice: wrapperContext.d3d, Value: (v2 & 0x20000) != 0);
  if ( (v3 & 0x1000) != 0 )
  {
    if ( (v2 & 0x1000) != 0 )
    {
      *(float *)&v19 = -wrapperConfig.defaultPolyOfsFactor;
      v16 = -wrapperConfig.defaultPolyOfsUnits;
      D3DDevice_SetRenderState_SlopeScaleDepthBias(pDevice: wrapperContext.d3d, FloatAsDword: v19);
      *(float *)&v20 = v16;
      v17 = v20;
    }
    else
    {
      D3DDevice_SetRenderState_SlopeScaleDepthBias(pDevice: wrapperContext.d3d, FloatAsDword: 0);
      v17 = 0;
    }
    D3DDevice_SetRenderState_DepthBias(pDevice: wrapperContext.d3d, FloatAsDword: v17);
  }
  if ( (v3 & 0xFF00000) != 0 )
    D3DDevice_SetRenderState_StencilRef(pDevice: wrapperContext.d3d, Value: (unsigned __int8)(v2 >> 20));
  if ( (v3 & 0xF0000000) != 0 )
    D3DDevice_SetRenderState_StencilMask(pDevice: wrapperContext.d3d, Value: (unsigned __int8)(v2 >> 28));
  renderStateDX.currentState = v2;
}


// ========================================================================
// ?GL_Scissor@@YAXHHHH@Z
// EA  : 0x828D5D40
// RVA : 0x008D5D40
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_Scissor(int x, int y, int w, int h)
{
  tagRECT v4; // [sp+50h] [-20h] BYREF

  v4.left = x;
  v4.right = x + w;
  v4.bottom = renderStateDX.targetHeight - y;
  v4.top = renderStateDX.targetHeight - y - h;
  D3DDevice_SetScissorRect(pDevice: wrapperContext.d3d, pRect: &v4);
}


// ========================================================================
// ?GL_Viewport@@YAXHHHH@Z
// EA  : 0x828D5D98
// RVA : 0x008D5D98
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_Viewport(unsigned int x, int y, unsigned int w, unsigned int h)
{
  _D3DVIEWPORT9 v4; // [sp+50h] [-30h] BYREF

  v4.Height = h;
  v4.X = x;
  v4.Width = w;
  v4.MinZ = 1.0;
  v4.MaxZ = 0.0;
  v4.Y = renderStateDX.targetHeight - y - h;
  D3DDevice_SetViewport(pDevice: wrapperContext.d3d, pViewport: &v4);
  renderStateDX.defaultViewPort = false;
}


// ========================================================================
// ?GL_Clear@@YAX_N00EMMMM@Z
// EA  : 0x828D5E10
// RVA : 0x008D5E10
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_Clear(
        bool color,
        bool depth,
        bool stencil,
        unsigned __int8 stencilValue,
        double r,
        double g,
        double b,
        double a)
{
  char v8; // r10
  int v9; // r5
  __vector4 v10; // [sp+50h] [-20h] BYREF

  v10.vector4_f32[0] = r;
  v10.vector4_f32[1] = g;
  v10.vector4_f32[2] = b;
  v10.vector4_f32[3] = a;
  v8 = !stencil - 1;
  v9 = !color ? 0 : 0xF;
  D3DDevice_ClearF(
    pDevice: wrapperContext.d3d,
    Flags: v9 | v8 & 0x20 | (!depth ? 0 : 0x10),
    pRect: nullptr,
    pColor: &v10,
    Z: 0.0,
    Stencil: v9 | v8 & 0x20);
}


// ========================================================================
// ?GL_PolygonOffset@@YAXMM_N@Z
// EA  : 0x828D5EA0
// RVA : 0x008D5EA0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_PolygonOffset(double scale, double bias, bool fill)
{
  unsigned int v4; // [sp+50h] [-20h]
  unsigned int v5; // [sp+50h] [-20h]

  *(float *)&v4 = -scale;
  D3DDevice_SetRenderState_SlopeScaleDepthBias(pDevice: wrapperContext.d3d, FloatAsDword: v4);
  *(float *)&v5 = -bias;
  D3DDevice_SetRenderState_DepthBias(pDevice: wrapperContext.d3d, FloatAsDword: v5);
}


// ========================================================================
// ?GL_GetCurrentQueryNumber@@YA_JXZ
// EA  : 0x828D5F00
// RVA : 0x008D5F00
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

int __fastcall GL_GetCurrentQueryNumber()
{
  return (LODWORD(renderStateDX.currentOcclusionQueryBatch) << 9)
       | *(_DWORD *)(HIDWORD(renderStateDX.currentOcclusionQueryBatch) + 0x1C);
}


// ========================================================================
// ?GL_CacheOcclusionQueryBatches@@YAX_J@Z
// EA  : 0x828D5F20
// RVA : 0x008D5F20
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_CacheOcclusionQueryBatches(__int64 upToIncludingBatchNum)
{
  int v1; // r25
  int i; // r11
  __int64 v3; // r11
  int v4; // r30
  D3DOcclusionQueryBatch *v5; // r31
  int v6; // r24
  int v8; // r3
  int v9; // r8
  int m_SlotsUsed; // r5
  unsigned int m_SlotSize; // r3
  bool *v13; // r4
  int v14; // r10
  unsigned __int8 *v15; // r9
  unsigned int m_NumTiles; // ctr
  int v17; // r7

  v1 = HIDWORD(upToIncludingBatchNum);
  for ( i = renderStateDX.lastCachedOcclusionBatch;
        SLODWORD(renderStateDX.lastCachedOcclusionBatch) < v1;
        i = renderStateDX.lastCachedOcclusionBatch )
  {
    LODWORD(v3) = i + 1;
    HIDWORD(v3) = wrapperContext.occlusionQueryBatch;
    renderStateDX.lastCachedOcclusionBatch = v3;
    v4 = v3 & 0xF;
    v5 = *(D3DOcclusionQueryBatch **)((char *)wrapperContext.occlusionQueryBatch + ((4 * v3) & 0x3C));
    v6 = Sys_Microseconds() >> 32;
    _R29 = D3DOcclusionQueryBatch_Lock(pThis: v5);
    v8 = Sys_Microseconds() >> 32;
    v9 = 0;
    _R6 = 128;
    wrapperStats.c_queriesWaitTime = v8 + wrapperStats.c_queriesWaitTime - v6;
    m_SlotsUsed = v5->m_SlotsUsed;
    m_SlotSize = v5->m_SlotSize;
    if ( m_SlotsUsed > 0 )
    {
      v13 = &renderStateDX.drawElementsSinceLastEndQuery + 1024 * v4;
      do
      {
        __asm { dcbt      r6, r29 }
        v14 = 0;
        if ( v5->m_NumTiles != 0 )
        {
          v15 = &v5->m_pCachedReadOnlyBase[v9 * v5->m_SlotSize - 12];
          m_NumTiles = v5->m_NumTiles;
          do
          {
            v17 = *((_DWORD *)v15 + 7);
            v15 += 32;
            v14 += ((v17 << 24) | (v17 << 8) & 0xFF0000 | (unsigned __int16)(((_WORD)v17 << 8) | HIBYTE(v17)))
                 + ((*(_DWORD *)v15 << 24)
                  | (*(_DWORD *)v15 << 8) & 0xFF0000
                  | (unsigned __int16)((*(_WORD *)v15 << 8) | (unsigned __int8)HIBYTE(*(_DWORD *)v15)));
            --m_NumTiles;
          }
          while ( m_NumTiles != 0 );
        }
        ++v9;
        v13 += 4;
        *(_DWORD *)v13 = v14;
        _R6 += m_SlotSize;
      }
      while ( v9 < m_SlotsUsed );
    }
    D3DOcclusionQueryBatch_Unlock(pThis: v5);
  }
}


// ========================================================================
// ?GL_BeginQueryBatch@@YAXXZ
// EA  : 0x828D6058
// RVA : 0x008D6058
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_BeginQueryBatch(__int64 a1)
{
  int currentOcclusionQueryBatch; // r11
  __int64 v2; // r11

  currentOcclusionQueryBatch = renderStateDX.currentOcclusionQueryBatch;
  if ( LODWORD(renderStateDX.currentOcclusionQueryBatch) - HIDWORD(renderStateDX.currentOcclusionQueryBatch) + 1 > 16 )
  {
    HIDWORD(a1) = LODWORD(renderStateDX.currentOcclusionQueryBatch) - 15;
    GL_CacheOcclusionQueryBatches(upToIncludingBatchNum: a1);
    currentOcclusionQueryBatch = renderStateDX.currentOcclusionQueryBatch;
    ++*(_DWORD *)(HIDWORD(renderStateDX.currentOcclusionQueryBatch) + 0x404);
  }
  LODWORD(v2) = currentOcclusionQueryBatch + 1;
  HIDWORD(v2) = &idInGameVideoFile::resourceList.hashTable[109];
  renderStateDX.currentOcclusionQueryBatch = v2;
  D3DOcclusionQueryBatch_Reset(pThis: *(D3DOcclusionQueryBatch **)((char *)wrapperContext.occlusionQueryBatch
                                                                 + ((4 * v2) & 0x3C)));
  renderStateDX.currentOcclusionQuery = 0;
  renderStateDX.drawElementsSinceLastEndQuery = false;
}


// ========================================================================
// ?GL_BeginQuery@@YAXPA_J@Z
// EA  : 0x828D60F0
// RVA : 0x008D60F0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_BeginQuery(__int64 queryNumber, int a2, __int64 a3)
{
  _QWORD *v3; // r30
  __int64 v4; // r11

  v3 = (_QWORD *)HIDWORD(queryNumber);
  LODWORD(v4) = renderStateDX.currentOcclusionQuery;
  if ( LODWORD(renderStateDX.currentOcclusionQuery) + 2 > 256 )
  {
    GL_BeginQueryBatch(a1: queryNumber);
    LODWORD(v4) = renderStateDX.currentOcclusionQuery;
  }
  if ( renderStateDX.drawElementsSinceLastEndQuery || (_DWORD)v4 == 0 )
  {
    D3DOcclusionQueryBatch_Issue(pThis: *(D3DOcclusionQueryBatch **)(((4
                                                                     * LODWORD(renderStateDX.currentOcclusionQueryBatch))
                                                                    & 0x3C)
                                                                   + HIDWORD(renderStateDX.currentOcclusionQueryBatch)
                                                                   + 1060));
    HIDWORD(v4) = HIDWORD(renderStateDX.currentOcclusionQuery);
    LODWORD(v4) = LODWORD(renderStateDX.currentOcclusionQuery) + 1;
    renderStateDX.currentOcclusionQuery = v4;
  }
  LODWORD(a3) = (LODWORD(renderStateDX.currentOcclusionQueryBatch) << 9) | v4;
  *v3 = a3;
  ++wrapperStats.c_queriesIssued;
}


// ========================================================================
// ?GL_EndQuery@@YAXXZ
// EA  : 0x828D61A0
// RVA : 0x008D61A0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_EndQuery()
{
  __int64 v0; // r11

  if ( SLODWORD(renderStateDX.currentOcclusionQuery) < 256 )
  {
    D3DOcclusionQueryBatch_Issue(pThis: *(D3DOcclusionQueryBatch **)(((4
                                                                     * LODWORD(renderStateDX.currentOcclusionQueryBatch))
                                                                    & 0x3C)
                                                                   + HIDWORD(renderStateDX.currentOcclusionQueryBatch)
                                                                   + 1060));
    renderStateDX.drawElementsSinceLastEndQuery = false;
    HIDWORD(v0) = HIDWORD(renderStateDX.currentOcclusionQuery);
    LODWORD(v0) = LODWORD(renderStateDX.currentOcclusionQuery) + 1;
    renderStateDX.currentOcclusionQuery = v0;
  }
}


// ========================================================================
// ?GL_GetDeferredQueryResult@@YAH_J@Z
// EA  : 0x828D6208
// RVA : 0x008D6208
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall GL_GetDeferredQueryResult(__int64 queryNumber)
{
  int v2; // r31
  __int16 v3; // r29
  unsigned int result; // r3
  int v5; // r6

  v2 = *(__int64 *)((char *)&queryNumber + 4) >> 9;
  v3 = WORD1(queryNumber);
  if ( LODWORD(renderStateDX.currentOcclusionQueryBatch) - v2 <= 16 )
  {
    HIDWORD(queryNumber) = *(__int64 *)((char *)&queryNumber + 4) >> 9;
    GL_CacheOcclusionQueryBatches(upToIncludingBatchNum: queryNumber);
    v5 = ((v2 << 8) & 0xF00) + (v3 & 0x1FF);
    result = renderStateDX.cachedOcclusionResult[0][v5]
           - *(_DWORD *)(&renderStateDX.drawElementsSinceLastEndQuery + v5 * 4);
    wrapperStats.c_queriesPassed += renderStateDX.cachedOcclusionResult[0][v5] != *(_DWORD *)(&renderStateDX.drawElementsSinceLastEndQuery
                                                                                            + v5 * 4);
  }
  else
  {
    ++wrapperStats.c_queriesTooOld;
    return -1;
  }
  return result;
}


// ========================================================================
// ?GL_ResetProgramState@@YAXXZ
// EA  : 0x828D62A8
// RVA : 0x008D62A8
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ResetProgramState(int a1, int a2, unsigned __int64 a3)
{
  int v3; // ctr
  unsigned __int64 v4; // r10

  v3 = 16;
  LODWORD(a3) = 0;
  LODWORD(v4) = 0;
  renderStateDX.boundProgram = nullptr;
  HIDWORD(v4) = (char *)&renderStateDX.boundTextureParmVersion + 4;
  renderStateDX.boundVertexMask = 0;
  renderStateDX.boundVertexParmVersion = 0;
  renderStateDX.boundFragmentParmVersion = a3;
  renderStateDX.boundTextureParmVersion = v4;
  do
  {
    HIDWORD(v4) += 4;
    *(_DWORD *)HIDWORD(v4) = 0;
    --v3;
  }
  while ( v3 != 0 );
  renderStateDX.boundTexturesChanged = true;
  D3DDevice_SetVertexShader(pDevice: wrapperContext.d3d, pShader: nullptr);
  D3DDevice_SetPixelShader(pDevice: wrapperContext.d3d, pShader: nullptr);
}


// ========================================================================
// ?GL_ResetTextureState@@YAXXZ
// EA  : 0x828D6338
// RVA : 0x008D6338
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ResetTextureState()
{
  renderStateDX.boundTexturesChanged = true;
}


// ========================================================================
// ?GL_SetupSurfaceParms@@YAPAXPBVidDeclRenderProg@@PBVidRenderModelSurface@@@Z
// EA  : 0x828D6350
// RVA : 0x008D6350
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void *__fastcall GL_SetupSurfaceParms(const idDeclRenderProg *prog, unsigned __int64 surf)
{
  unsigned int numVertexParms; // r11
  int v3; // r31
  unsigned int v4; // r7
  D3DDevice *d3d; // r11
  int v6; // r6
  float *v7; // r10
  bool (__fastcall **v8)(idAIEvent *__hidden, const struct idEntity *, int); // r9
  unsigned __int64 v9; // r10
  int v10; // r11
  int v11; // r11

  numVertexParms = prog->numVertexParms;
  v3 = HIDWORD(surf);
  v4 = numVertexParms >> 2;
  v6 = 2 * (numVertexParms + 120);
  v7 = (float *)((char *)wrapperContext.d3d + 16 * numVertexParms);
  d3d = wrapperContext.d3d;
  LODWORD(surf) = 0x80000000;
  v8 = &off_82230000;
  *(float *)&wrapperContext.d3d->m_Pending.m_Mask[v6] = *(float *)(HIDWORD(surf) + 40);
  v7[481] = *(float *)(HIDWORD(surf) + 44);
  v7[482] = *(float *)(HIDWORD(surf) + 48);
  v7[483] = *(float *)(HIDWORD(surf) + 52);
  LODWORD(v9) = (surf >> v4) | LODWORD(d3d->m_Pending.m_Mask[0]);
  d3d->m_Pending.m_Mask[0] = v9;
  HIDWORD(v9) = *(_DWORD *)(HIDWORD(surf) + 28);
  if ( HIDWORD(v9) != 0 )
  {
    LODWORD(v9) = *(_DWORD *)(HIDWORD(v9) + 4);
    D3DDevice_SetStreamSource(
      pDevice: wrapperContext.d3d,
      StreamNumber: 1u,
      pVertexBuffer: *(D3DVertexBuffer **)(HIDWORD(v9) + 8),
      OffsetInBytes: v9 & 0x7FFFFFFF,
      StrideInBytes: 0,
      PendingMask3: v9);
    D3DDevice_SetVertexShaderConstantB(
      pDevice: wrapperContext.d3d,
      StartRegister: 1u,
      pConstantData: &true,
      BoolCount: 1u);
  }
  v10 = *(_DWORD *)(v3 + 32);
  if ( v10 != 0 )
  {
    LODWORD(v9) = *(_DWORD *)(v10 + 4);
    D3DDevice_SetStreamSource(
      pDevice: wrapperContext.d3d,
      StreamNumber: 2u,
      pVertexBuffer: *(D3DVertexBuffer **)(v10 + 8),
      OffsetInBytes: v9 & 0x7FFFFFFF,
      StrideInBytes: 0,
      PendingMask3: v9);
    D3DDevice_SetVertexShaderConstantB(
      pDevice: wrapperContext.d3d,
      StartRegister: 2u,
      pConstantData: &true,
      BoolCount: 1u);
  }
  v11 = *(_DWORD *)(v3 + 36);
  if ( v11 != 0 )
  {
    LODWORD(v9) = *(_DWORD *)(v11 + 4);
    D3DDevice_SetStreamSource(
      pDevice: wrapperContext.d3d,
      StreamNumber: 3u,
      pVertexBuffer: *(D3DVertexBuffer **)(v11 + 8),
      OffsetInBytes: v9 & 0x7FFFFFFF,
      StrideInBytes: 0,
      PendingMask3: v9);
  }
  return nullptr;
}


// ========================================================================
// ?GL_ClearSurfaceParms@@YAXPBVidDeclRenderProg@@PBVidRenderModelSurface@@@Z
// EA  : 0x828D6488
// RVA : 0x008D6488
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ClearSurfaceParms(const idDeclRenderProg *prog, const idRenderModelSurface *surf)
{
  unsigned int numVertexParms; // r10
  int v3; // r6
  D3DDevice *d3d; // r11
  unsigned int v5; // r5
  float *v6; // r10
  __int128 v7; // r10
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r10

  numVertexParms = prog->numVertexParms;
  v3 = 2 * (numVertexParms + 120);
  d3d = wrapperContext.d3d;
  v5 = numVertexParms >> 2;
  v6 = (float *)((char *)wrapperContext.d3d + 16 * numVertexParms);
  *(float *)&wrapperContext.d3d->m_Pending.m_Mask[v3] = vec4_origin.x;
  *(_QWORD *)((char *)&v7 + 4) = 0x180000000uLL >> v5;
  v6[481] = vec4_origin.y;
  v6[482] = vec4_origin.z;
  v6[483] = vec4_origin.w;
  LODWORD(v7) = (0x180000000uLL >> v5) | LODWORD(d3d->m_Pending.m_Mask[0]);
  d3d->m_Pending.m_Mask[0] = v7;
  D3DDevice_SetStreamSource(
    pDevice: wrapperContext.d3d,
    StreamNumber: 1u,
    pVertexBuffer: nullptr,
    OffsetInBytes: 0,
    StrideInBytes: 0,
    PendingMask3: v7);
  D3DDevice_SetVertexShaderConstantB(
    pDevice: wrapperContext.d3d,
    StartRegister: 1u,
    pConstantData: &false,
    BoolCount: 1u);
  D3DDevice_SetStreamSource(
    pDevice: wrapperContext.d3d,
    StreamNumber: 2u,
    pVertexBuffer: nullptr,
    OffsetInBytes: 0,
    StrideInBytes: 0,
    PendingMask3: v8);
  D3DDevice_SetVertexShaderConstantB(
    pDevice: wrapperContext.d3d,
    StartRegister: 2u,
    pConstantData: &false,
    BoolCount: 1u);
  D3DDevice_SetStreamSource(
    pDevice: wrapperContext.d3d,
    StreamNumber: 3u,
    pVertexBuffer: nullptr,
    OffsetInBytes: 0,
    StrideInBytes: 0,
    PendingMask3: v9);
}


// ========================================================================
// GL_DrawElementsInternal
// EA  : 0x828D6598
// RVA : 0x008D6598
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_DrawElementsInternal(
        const idTriangles *tri,
        char progVertexMask,
        bool skipDetailTriangles,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  int numIndexes; // r29
  D3DIndexBuffer *apiObject; // r27
  unsigned int v10; // r7
  _D3DPRIMITIVETYPE v11; // r4
  unsigned int v12; // r6

  if ( !wrapperConfig.skipDetailTris && progVertexMask == 0 || (numIndexes = tri->detailOffset) == 0 )
    numIndexes = tri->numIndexes;
  if ( numIndexes >= 3 )
  {
    if ( wrapperConfig.singleTriangle )
      numIndexes = 3;
    apiObject = (D3DIndexBuffer *)tri->indexBuffer.apiObject;
    D3DDevice_SetStreamSource(
      pDevice: wrapperContext.d3d,
      StreamNumber: 0,
      pVertexBuffer: (D3DVertexBuffer *)tri->vertexBuffer.apiObject,
      OffsetInBytes: tri->vertexBuffer.offsetInOtherBuffer & 0x7FFFFFFF,
      StrideInBytes: 0,
      PendingMask3: a7);
    D3DDevice_SetIndices(pDevice: wrapperContext.d3d, pIndexData: apiObject);
    if ( (tri->vertexMask & 0x200) != 0 )
    {
      v10 = numIndexes;
      v11 = D3DPT_TRIANGLESTRIP;
      v12 = ((unsigned int)tri->indexBuffer.offsetInOtherBuffer >> 1) & 0x3FFFFFFF;
    }
    else
    {
      v11 = D3DPT_TRIANGLELIST;
      v12 = ((unsigned int)tri->indexBuffer.offsetInOtherBuffer >> 1) & 0x3FFFFFFF;
      v10 = 3 * (numIndexes / 3);
    }
    D3DDevice_DrawIndexedVertices(
      pDevice: wrapperContext.d3d,
      PrimitiveType: v11,
      BaseVertexIndex: 0,
      StartIndex: v12,
      IndexCount: v10);
    if ( wrapperConfig.finishEveryDraw )
      D3DDevice_BlockUntilIdle(pDevice: wrapperContext.d3d);
    renderStateDX.drawElementsSinceLastEndQuery = true;
    wrapperStats.c_drawIndices += numIndexes;
    ++wrapperStats.c_drawElements;
    wrapperStats.c_drawVertices += tri->numVerts;
  }
}


// ========================================================================
// ?GL_GetCurrentStats@@YA?AUwrapperStats_t@@XZ
// EA  : 0x828D66D0
// RVA : 0x008D66D0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

wrapperStats_t *__fastcall GL_GetCurrentStats(wrapperStats_t *result)
{
  int *p_c_drawVertices; // r10
  float *p_textureLODBias; // r11
  int i; // ctr

  p_c_drawVertices = &result[-1].c_drawVertices;
  p_textureLODBias = &wrapperConfig.textureLODBias;
  for ( i = 9; i != 0; --i )
    *++p_c_drawVertices = *(_DWORD *)++p_textureLODBias;
  return result;
}


// ========================================================================
// ?GL_ClearStats@@YAXXZ
// EA  : 0x828D66F8
// RVA : 0x008D66F8
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ClearStats()
{
  float *p_textureLODBias; // r11
  int i; // ctr

  p_textureLODBias = &wrapperConfig.textureLODBias;
  for ( i = 9; i != 0; --i )
    *++p_textureLODBias = 0.0;
}


// ========================================================================
// ?GL_SetDefaultState@@YAXXZ
// EA  : 0x828D6928
// RVA : 0x008D6928
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_SetDefaultState()
{
  unsigned __int64 v0; // r11
  bool v1; // r5
  unsigned __int64 v2; // r6
  int v3; // r4
  int v4; // r3

  D3DDevice_SetRenderState_AlphaBlendEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_ScissorTestEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_StencilEnable(pDevice: wrapperContext.d3d, Value: 0);
  D3DDevice_SetRenderState_FillMode(pDevice: wrapperContext.d3d, Value: 0);
  D3DDevice_SetRenderState_ZWriteEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_ZEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_ZFunc(pDevice: wrapperContext.d3d, Value: 7u);
  D3DDevice_SetRenderState_HalfPixelOffset(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_ViewportEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_PrimitiveResetEnable(pDevice: wrapperContext.d3d, Value: 1u);
  D3DDevice_SetRenderState_PrimitiveResetIndex(pDevice: wrapperContext.d3d, Value: 0xFFFFu);
  HIDWORD(v0) = &idInGameVideoFile::resourceList.hashTable[109];
  LODWORD(v0) = 0;
  renderStateDX.currentState = v0;
  GL_State(stateBits: 0x400000000001uLL, forceGlState: v1);
  GL_ResetProgramState(a1: v4, a2: v3, a3: v2);
}


// ========================================================================
// ?GL_SetRenderDestination@@YAXABV?$idODSObject@VidRenderDestination@@@@HH@Z
// EA  : 0x828D69F8
// RVA : 0x008D69F8
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_SetRenderDestination(const idODSObject<idRenderDestination> *destination, int level, int side)
{
  unsigned int v6; // r29
  int i; // r30
  int v8; // r10
  const idRenderDestination *objectPtr; // r10
  D3DSurface *depthSurface; // r7

  v6 = 0;
  for ( i = 36; i < 52; i += 4 )
    D3DDevice_SetRenderTarget_External(
      pDevice: wrapperContext.d3d,
      RenderTargetIndex: v6++,
      pRenderTarget: *(D3DSurface **)(&destination->objectPtr->isDefault + i));
  D3DDevice_SetDepthStencilSurface(pDevice: wrapperContext.d3d, pZStencilSurface: destination->objectPtr->depthSurface);
  v8 = 0;
  renderStateDX.currentNumTargets = 0;
  if ( destination->objectPtr->targetSurface[0] != nullptr )
  {
    v8 = 1;
    renderStateDX.currentNumTargets = 1;
  }
  if ( destination->objectPtr->targetSurface[1] != nullptr )
    renderStateDX.currentNumTargets = ++v8;
  if ( destination->objectPtr->targetSurface[2] != nullptr )
    renderStateDX.currentNumTargets = ++v8;
  if ( destination->objectPtr->targetSurface[3] != nullptr )
    renderStateDX.currentNumTargets = v8 + 1;
  objectPtr = destination->objectPtr;
  renderStateDX.currentTargetLevel = level;
  renderStateDX.currentTargetSide = side;
  renderStateDX.currentRenderTexture = objectPtr;
  renderStateDX.targetWidth = destination->objectPtr->targetWidth >> level;
  renderStateDX.targetHeight = destination->objectPtr->targetHeight >> level;
  renderStateDX.targetIsDefault = destination->objectPtr->isDefault;
  renderStateDX.targetHasColor = destination->objectPtr->targetSurface[0] != nullptr;
  depthSurface = destination->objectPtr->depthSurface;
  renderStateDX.defaultViewPort = true;
  renderStateDX.targetHasDepth = depthSurface != nullptr;
}


// ========================================================================
// ?GL_ResolveTarget@@YAXW4resolveTarget_t@@ABV?$idODSObject@VidRenderDestination@@@@@Z
// EA  : 0x828D6B38
// RVA : 0x008D6B38
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ResolveTarget(resolveTarget_t target, const idODSObject<idRenderDestination> *destination)
{
  unsigned int v2; // r4
  idImage *depthImage; // r10
  unsigned int v4; // [sp+8h] [-78h]
  const _D3DRESOLVE_PARAMETERS *v5; // [sp+Ch] [-74h]

  if ( target == RESOLVE_TARGET_DEPTH )
  {
    depthImage = destination->objectPtr->depthImage;
    v2 = 4;
  }
  else
  {
    depthImage = destination->objectPtr->targetImage[target];
    v2 = dx_renderTarget[target];
  }
  D3DDevice_Resolve(
    pDevice: wrapperContext.d3d,
    Flags: v2,
    pSourceRect: nullptr,
    pDestTexture: depthImage->d3dTexture,
    pDestPoint: nullptr,
    DestLevel: renderStateDX.currentTargetLevel,
    DestSliceOrFace: renderStateDX.currentTargetSide,
    pClearColor: nullptr,
    ClearZ: 0.0,
    ClearStencil: v4,
    pParameters: v5);
}


// ========================================================================
// ?GL_ResolveTarget@@YAXW4resolveTarget_t@@ABV?$idODSObject@VidRenderDestination@@@@HHHHHH@Z
// EA  : 0x828D6BD8
// RVA : 0x008D6BD8
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_ResolveTarget(
        resolveTarget_t target,
        const idODSObject<idRenderDestination> *destination,
        int srcMinX,
        int srcMinY,
        int srcMaxX,
        int srcMaxY,
        int dstX,
        int dstY)
{
  unsigned int v8; // r4
  idImage *depthImage; // r30
  unsigned int v10; // [sp+8h] [-A8h]
  const _D3DRESOLVE_PARAMETERS *v11; // [sp+Ch] [-A4h]
  _D3DPOINT v12; // [sp+70h] [-40h] BYREF
  _D3DRECT v13; // [sp+80h] [-30h] BYREF

  if ( target == RESOLVE_TARGET_DEPTH )
  {
    depthImage = destination->objectPtr->depthImage;
    v8 = 4;
  }
  else
  {
    depthImage = destination->objectPtr->targetImage[target];
    v8 = dx_renderTarget[target];
  }
  v12.y = dstY & 0xFFFFFFF8;
  v12.x = dstX & 0xFFFFFFF8;
  v13.x2 = (srcMaxX + 7) & 0xFFFFFFF8;
  v13.x1 = srcMinX & 0xFFFFFFF8;
  v13.y1 = (renderStateDX.targetHeight - srcMaxY) & 0xFFFFFFF8;
  v13.y2 = (renderStateDX.targetHeight - srcMinY + 7) & 0xFFFFFFF8;
  D3DDevice_Resolve(
    pDevice: wrapperContext.d3d,
    Flags: v8,
    pSourceRect: &v13,
    pDestTexture: depthImage->d3dTexture,
    pDestPoint: &v12,
    DestLevel: renderStateDX.currentTargetLevel,
    DestSliceOrFace: renderStateDX.currentTargetSide,
    pClearColor: nullptr,
    ClearZ: 0.0,
    ClearStencil: v10,
    pParameters: v11);
}


// ========================================================================
// ?GL_BindTexture@@YAXABV?$idODSObject@VidImage@@@@H@Z
// EA  : 0x828D6CC0
// RVA : 0x008D6CC0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GL_BindTexture(const idODSObject<idImage> *image, unsigned int texUnit)
{
  unsigned __int64 v4; // r7
  unsigned __int64 v5; // r27
  D3DDevice *d3d; // r7
  unsigned int v7; // r29
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // r7 OVERLAPPED
  D3DDevice *v10; // r3
  unsigned __int64 v11; // r9
  D3DDevice *v12; // r11
  unsigned __int64 v13; // r9
  D3DDevice *v14; // r11
  unsigned __int64 v15; // r9 OVERLAPPED
  int v16; // r10

  if ( image->objectPtr->d3dTexture != nullptr )
  {
    LODWORD(v4) = 0x80000000;
    HIDWORD(v4) = texUnit + 32;
    image->objectPtr->frameUsed = renderStateDX.frameNumber;
    v5 = v4 >> SBYTE3(v4);
    ++image->objectPtr->bindCount;
    D3DDevice_SetTexture(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      pTexture: image->objectPtr->d3dTexture,
      PendingMask3: 0x8000000000000001uLL);
    D3DDevice_SetSamplerState_MagFilter(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      Value: image->objectPtr->_D3DSAMP_MAGFILTER);
    D3DDevice_SetSamplerState_MinFilter(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      Value: image->objectPtr->_D3DSAMP_MINFILTER);
    d3d = wrapperContext.d3d;
    v7 = texUnit;
    wrapperContext.d3d->m_Constants.Fetch[texUnit].Texture.dword[3] = (image->objectPtr->_D3DSAMP_MIPFILTER << 23)
                                                                    & 0x1800000
                                                                    | wrapperContext.d3d->m_Constants.Fetch[texUnit].Texture.dword[3]
                                                                    & 0xFE7FFFFF;
    LODWORD(v8) = v5 | LODWORD(d3d->m_Pending.m_Mask[3]);
    d3d->m_Pending.m_Mask[3] = v8;
    D3DDevice_SetSamplerState_MaxAnisotropy(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      Value: image->objectPtr->_D3DSAMP_MAXANISOTROPY);
    D3DDevice_SetSamplerState_MipMapLodBias(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      FloatAsDword: image->objectPtr->_D3DSAMP_MIPMAPLODBIAS);
    D3DDevice_SetSamplerState_MaxMipLevel(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      Value: image->objectPtr->_D3DSAMP_MAXMIPLEVEL);
    D3DDevice_SetSamplerState_MinMipLevel(
      pDevice: wrapperContext.d3d,
      Sampler: texUnit,
      Value: image->objectPtr->_D3DSAMP_MINMIPLEVEL);
    HIDWORD(v9) = &idInGameVideoFile::resourceList.hashTable[109];
    v10 = wrapperContext.d3d;
    wrapperContext.d3d->m_Constants.Fetch[v7].Texture.dword[5] = wrapperContext.d3d->m_Constants.Fetch[v7].Texture.dword[5]
                                                               & 0xFFFFFFFC
                                                               | (image->objectPtr->_D3DSAMP_BORDERCOLOR != 0);
    v11 = v10->m_Pending.m_Mask[3];
    LODWORD(v9) = v11 | v5;
    v10->m_Pending.m_Mask[3] = v9;
    HIDWORD(v9) = (idODSObject<idImage>)image->objectPtr;
    v12 = wrapperContext.d3d;
    *(_DWORD *)((char *)wrapperContext.d3d->m_Pending.m_Mask + HIDWORD(v11)) = (image->objectPtr->_D3DSAMP_ADDRESSU << 10)
                                                                             & 0x1C00
                                                                             | *(_DWORD *)((_BYTE *)wrapperContext.d3d->m_Pending.m_Mask
                                                                                         + HIDWORD(v11))
                                                                             & 0xFFFFE3FF;
    v13 = v12->m_Pending.m_Mask[3];
    LODWORD(v9) = v5 | v13;
    v12->m_Pending.m_Mask[3] = v9;
    v14 = wrapperContext.d3d;
    *(_DWORD *)((char *)wrapperContext.d3d->m_Pending.m_Mask + HIDWORD(v13)) = (image->objectPtr->_D3DSAMP_ADDRESSV << 13)
                                                                             & 0xE000
                                                                             | *(_DWORD *)((_BYTE *)wrapperContext.d3d->m_Pending.m_Mask
                                                                                         + HIDWORD(v13))
                                                                             & 0xFFFF1FFF;
    v15 = v14->m_Pending.m_Mask[3];
    HIDWORD(v15) = v15 | v5;
    v14->m_Pending.m_Mask[3] = *(unsigned __int64 *)((char *)&v9 - 4);
    HIDWORD(v9) = wrapperContext.d3d;
    wrapperContext.d3d->m_Constants.Fetch[v7].Texture.dword[5] = (8 * image->objectPtr->_D3DSAMP_TRILINEARTHRESHOLD)
                                                               & 0x18
                                                               | wrapperContext.d3d->m_Constants.Fetch[v7].Texture.dword[5]
                                                               & 0xFFFFFFE7;
    v16 = *(_DWORD *)(HIDWORD(v9) + 28) | v5;
    *(_QWORD *)(HIDWORD(v9) + 24) = *(unsigned __int64 *)((char *)&v15 - 4);
    ++wrapperStats.c_texturesBound;
  }
}


// ========================================================================
// ?GL_BindProgram@@YAXABV?$idODSObject@VidDeclRenderProg@@@@_KI@Z
// EA  : 0x828D6ED0
// RVA : 0x008D6ED0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GL_BindProgram(
        const idODSObject<idDeclRenderProg> *prog,
        int a2,
        unsigned __int64 extraState,
        unsigned int triVertexMask)
{
  unsigned int v6; // r23
  __int64 v7; // r11
  unsigned __int64 v8; // r4
  bool v9; // r5
  idResource **v10; // r30 OVERLAPPED
  D3DVertexShader *VertexProgramForVertexFormat; // r3
  D3DPixelShader *fragmentShaderD3D; // r4
  _BYTE v13[12]; // r11 OVERLAPPED
  unsigned int v14; // r31 OVERLAPPED
  int v15; // r11
  unsigned int v16; // r4
  int v17; // r4
  __int64 v18; // r8
  int v19; // r6
  D3DDevice *d3d; // r5
  __int64 v21; // r3
  int v22; // r4
  __int64 v23; // r8
  int v24; // r6
  float *v25; // r5
  __int64 v26; // r3
  bool boundTexturesChanged; // r8
  int v28; // r26
  signed int v29; // r31
  int v30; // r28
  const idImage **boundTextures; // r29
  int v32; // r7
  const idImage *v33; // r30
  int i; // ctr
  idODSObject<idImage> v35; // [sp+50h] [-60h] BYREF

  v6 = HIDWORD(extraState);
  idParmState::RollbackVirtualStack(this: renderThreadParmState, renderParmChange: false);
  LODWORD(v7) = ~a2;
  HIDWORD(v7) = a2;
  LODWORD(v8) = 0;
  HIDWORD(v8) = (v7 >> 63) & *(_DWORD *)(((unsigned __int64)(v7 >> 63) >> 32) + 68) | a2;
  GL_State(stateBits: v8, forceGlState: v9);
  v10 = &idInGameVideoFile::resourceList.hashTable[109];
  if ( *(_QWORD *)&renderStateDX.boundProgram != __PAIR64__(prog->objectPtr, v6) || !wrapperConfig.lazyBindPrograms )
  {
    if ( idDeclRenderProg::GetVertexProgramForVertexFormat(this: prog->objectPtr, storedVertexMask: v6) == nullptr )
    {
      if ( (*((_BYTE *)&prog->objectPtr->idResource + 32) & 0x40) != 0 )
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idDeclRenderProg::CreateVertexShaderForVertexFormat(this: prog->objectPtr, storedVertexMask: v6);
      if ( (*((_BYTE *)&prog->objectPtr->idResource + 32) & 0x40) != 0 )
        idMem::PopHeap(this: &mem);
    }
    VertexProgramForVertexFormat = idDeclRenderProg::GetVertexProgramForVertexFormat(
                                     this: prog->objectPtr,
                                     storedVertexMask: v6);
    D3DDevice_SetVertexShader(pDevice: wrapperContext.d3d, pShader: VertexProgramForVertexFormat);
    fragmentShaderD3D = nullptr;
    if ( !prog->objectPtr->isFastZ )
      fragmentShaderD3D = prog->objectPtr->fragmentShaderD3D;
    D3DDevice_SetPixelShader(pDevice: wrapperContext.d3d, pShader: fragmentShaderD3D);
  }
  *(_DWORD *)v13 = renderThreadParmState;
  v14 = 0x80000000;
  if ( renderStateDX.boundProgram == prog->objectPtr )
  {
    *(_DWORD *)&v13[4] = HIDWORD(renderStateDX.boundVertexParmVersion);
    if ( LODWORD(renderStateDX.boundVertexParmVersion) == LODWORD(renderThreadParmState->vertexParmVersion)
      && wrapperConfig.lazyBindParms )
    {
      goto LABEL_25;
    }
  }
  if ( (renderStateDX.currentState & 0x8000) == 0 )
  {
    v15 = renderStateDX.currentState & 0x10000;
    if ( renderThreadParmState->currentMVPHasNegativeDeterminant )
    {
      if ( v15 != 0 )
      {
        v16 = 2;
LABEL_20:
        D3DDevice_SetRenderState_CullMode(pDevice: wrapperContext.d3d, Value: v16);
        *(_DWORD *)v13 = renderThreadParmState;
        goto LABEL_21;
      }
    }
    else
    {
      v16 = 2;
      if ( v15 == 0 )
        goto LABEL_20;
    }
    v16 = 6;
    goto LABEL_20;
  }
LABEL_21:
  *(idODSObject<idDeclRenderProg> *)&v13[4] = (idODSObject<idDeclRenderProg>)prog->objectPtr;
  v17 = *(_DWORD *)v13 + 48;
  HIDWORD(v18) = 0;
  if ( prog->objectPtr->numVertexParms > 0 )
  {
    *(_DWORD *)&v13[8] = wrapperContext.d3d;
    *(_DWORD *)v13 = 0;
    v19 = 140;
    d3d = wrapperContext.d3d;
    do
    {
      LODWORD(v18) = *(_DWORD *)v13 + *(_DWORD *)&v13[8];
      v21 = *(_QWORD *)(&v10 - 1) >> (HIDWORD(v18)++ >> 2);
      *(_DWORD *)&v13[4] = 16 * *(__int16 *)(v19 + *(_DWORD *)&v13[4]) + v17;
      v19 += 2;
      d3d->m_Constants.Alu[0].vector4_f32[0] = **(float **)&v13[4];
      *(float *)(v18 + 1924) = *(float *)(*(_DWORD *)&v13[4] + 4);
      *(float *)(v18 + 1928) = *(float *)(*(_DWORD *)&v13[4] + 8);
      *(float *)(v18 + 1932) = *(float *)(*(_DWORD *)&v13[4] + 12);
      *(_QWORD *)v13 = **(_QWORD **)&v13[8];
      LODWORD(v18) = v21 | *(_DWORD *)(*(_DWORD *)&v13[8] + 4);
      **(_QWORD **)&v13[8] = v18;
      *(idODSObject<idDeclRenderProg> *)&v13[4] = (idODSObject<idDeclRenderProg>)prog->objectPtr;
      *(_DWORD *)&v13[8] = wrapperContext.d3d;
      d3d = (D3DDevice *)((char *)wrapperContext.d3d + *(_DWORD *)v13);
    }
    while ( SHIDWORD(v18) < prog->objectPtr->numVertexParms );
    *(_DWORD *)v13 = renderThreadParmState;
    goto LABEL_26;
  }
LABEL_25:
  *(_DWORD *)&v13[8] = wrapperContext.d3d;
LABEL_26:
  if ( renderStateDX.boundProgram != *(const idDeclRenderProg **)&v13[4]
    || LODWORD(renderStateDX.boundFragmentParmVersion) != HIDWORD(renderStateDX.boundFragmentParmVersion)
    || !wrapperConfig.lazyBindParms )
  {
    v22 = *(_DWORD *)v13 + 48;
    HIDWORD(v23) = 0;
    if ( *(int *)(*(_DWORD *)&v13[4] + 272) > 0 )
    {
      *(_DWORD *)v13 = 0;
      v24 = 208;
      v25 = *(float **)&v13[8];
      do
      {
        LODWORD(v23) = *(_DWORD *)v13 + *(_DWORD *)&v13[8];
        v26 = *(_QWORD *)(&v10 - 1) >> (HIDWORD(v23)++ >> 2);
        *(_DWORD *)&v13[4] = 16 * *(__int16 *)(v24 + *(_DWORD *)&v13[4]) + v22;
        v24 += 2;
        v25[1504] = **(float **)&v13[4];
        *(float *)(v23 + 6020) = *(float *)(*(_DWORD *)&v13[4] + 4);
        *(float *)(v23 + 6024) = *(float *)(*(_DWORD *)&v13[4] + 8);
        *(float *)(v23 + 6028) = *(float *)(*(_DWORD *)&v13[4] + 12);
        *(_QWORD *)v13 = *(_QWORD *)(*(_DWORD *)&v13[8] + 8);
        LODWORD(v23) = v26 | *(_DWORD *)&v13[4];
        *(_QWORD *)(*(_DWORD *)&v13[8] + 8) = v23;
        *(idODSObject<idDeclRenderProg> *)&v13[4] = (idODSObject<idDeclRenderProg>)prog->objectPtr;
        *(_DWORD *)&v13[8] = wrapperContext.d3d;
        v25 = (float *)((char *)wrapperContext.d3d + *(_DWORD *)v13);
      }
      while ( SHIDWORD(v23) < prog->objectPtr->numFragmentParms );
      *(_DWORD *)v13 = renderThreadParmState;
    }
  }
  boundTexturesChanged = renderStateDX.boundTexturesChanged;
  if ( renderStateDX.boundProgram != *(const idDeclRenderProg **)&v13[4]
    || (*(_DWORD *)&v13[4] = HIDWORD(renderStateDX.boundTextureParmVersion),
        LODWORD(renderStateDX.boundTextureParmVersion) != *(_DWORD *)(*(_DWORD *)v13 + 0x1C))
    || renderStateDX.boundTexturesChanged
    || !wrapperConfig.lazyBindTextures )
  {
    *(_DWORD *)&v13[8] = *(_DWORD *)(*(_DWORD *)&v13[4] + 308);
    v28 = *(_DWORD *)v13 + 48;
    v29 = 0;
    if ( *(int *)&v13[8] > 0 )
    {
      v30 = 276;
      boundTextures = renderStateDX.boundTextures;
      do
      {
        v32 = 16 * *(__int16 *)(v30 + *(_DWORD *)&v13[4]);
        v33 = *(const idImage **)(v32 + v28);
        if ( boundTexturesChanged || *boundTextures != v33 )
        {
          v35.objectPtr = *(const idImage **)(v32 + v28);
          GL_BindTexture(image: &v35, texUnit: v29);
          *boundTextures = v33;
          boundTexturesChanged = renderStateDX.boundTexturesChanged;
        }
        *(idODSObject<idDeclRenderProg> *)&v13[4] = (idODSObject<idDeclRenderProg>)prog->objectPtr;
        ++v29;
        v30 += 2;
        ++boundTextures;
        *(_DWORD *)&v13[8] = prog->objectPtr->numTextureParms;
      }
      while ( v29 < *(int *)&v13[8] );
      *(_DWORD *)v13 = renderThreadParmState;
    }
    if ( *(int *)&v13[8] < 16 )
    {
      *(_DWORD *)&v13[4] = &renderStateDX.boundTextures[*(_DWORD *)&v13[8]];
      *(_DWORD *)&v13[8] = 16 - *(_DWORD *)&v13[8];
      *(_DWORD *)&v13[4] -= 4;
      if ( *(_DWORD *)&v13[8] != 0 )
      {
        for ( i = *(_DWORD *)&v13[8]; i != 0; --i )
        {
          *(_DWORD *)&v13[4] += 4;
          **(_DWORD **)&v13[4] = 0;
        }
      }
    }
  }
  renderStateDX.boundProgram = prog->objectPtr;
  renderStateDX.boundVertexMask = v6;
  renderStateDX.boundVertexParmVersion = *(_QWORD *)(*(_DWORD *)v13 + offsetof(idParmState, vertexParmVersion));
  renderStateDX.boundFragmentParmVersion = *(_QWORD *)(*(_DWORD *)v13 + offsetof(idParmState, fragmentParmVersion));
  *(_QWORD *)&v13[4] = *(_QWORD *)(*(_DWORD *)v13 + offsetof(idParmState, textureParmVersion));
  renderStateDX.boundTexturesChanged = *(_DWORD *)(*(_DWORD *)v13 + offsetof(idParmState, textureParmVersion));
  renderStateDX.boundTextureParmVersion = *(_QWORD *)&v13[4];
  ++wrapperStats.c_programsBound;
}


// ========================================================================
// ?GL_DrawElements@@YAXABV?$idODSObject@VidDeclRenderProg@@@@ABV?$idODSObject@VidRenderModelSurface@@@@_K_N@Z
// EA  : 0x828D7300
// RVA : 0x008D7300
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_DrawElements(
        const idODSObject<idDeclRenderProg> *prog,
        const idODSObject<idRenderModelSurface> *surf,
        unsigned __int64 extraState,
        bool skipDetailTriangles)
{
  int v6; // r28
  char v7; // r27
  idTriangles *geometry; // r31
  unsigned __int64 v9; // r6
  unsigned __int64 v10; // r10
  int v11; // r8
  int v12; // r7
  int v13; // r6
  bool v14; // r5

  v6 = HIDWORD(extraState);
  v7 = extraState;
  geometry = surf->objectPtr->geometry;
  if ( (geometry->vertexMask & 0x60) != 0 )
    idParmState::Set16BitVertexScaleBias(this: renderThreadParmState, vsb: &geometry->vsb);
  HIDWORD(extraState) = geometry->vertexMask;
  GL_BindProgram(prog, a2: v6, extraState, triVertexMask: skipDetailTriangles);
  GL_SetupSurfaceParms(prog: prog->objectPtr, surf: v9);
  GL_DrawElementsInternal(
    tri: geometry,
    progVertexMask: v7,
    skipDetailTriangles: v14,
    a4: v13,
    a5: v12,
    a6: v11,
    a7: v10);
  GL_ClearSurfaceParms(prog: prog->objectPtr, surf: surf->objectPtr);
  if ( (geometry->vertexMask & 0x60) != 0 )
    idParmState::Set16BitVertexScaleBias(this: renderThreadParmState, vsb: &defaultVSB);
}


// ========================================================================
// ?GL_DrawElements@@YAXABV?$idODSObject@VidDeclRenderProg@@@@ABV?$idODSObject@VidTriangles@@@@_K_N@Z
// EA  : 0x828D73A0
// RVA : 0x008D73A0
// PDB : w:\tech5\engine\renderer\jobs\render\graphicsapiwrapper_d3d_360.cpp
// ========================================================================

void __fastcall GL_DrawElements(
        const idODSObject<idDeclRenderProg> *prog,
        const idODSObject<idTriangles> *tri,
        unsigned __int64 extraState,
        bool skipDetailTriangles)
{
  int v6; // r29
  char v7; // r28
  unsigned __int64 v8; // r10
  int v9; // r8
  int v10; // r7
  int v11; // r6
  bool v12; // r5

  v6 = HIDWORD(extraState);
  v7 = extraState;
  if ( (tri->objectPtr->vertexMask & 0x60) != 0 )
    idParmState::Set16BitVertexScaleBias(this: renderThreadParmState, vsb: &tri->objectPtr->vsb);
  HIDWORD(extraState) = tri->objectPtr->vertexMask;
  GL_BindProgram(prog, a2: v6, extraState, triVertexMask: skipDetailTriangles);
  GL_DrawElementsInternal(
    tri: tri->objectPtr,
    progVertexMask: v7,
    skipDetailTriangles: v12,
    a4: v11,
    a5: v10,
    a6: v9,
    a7: v8);
  if ( (tri->objectPtr->vertexMask & 0x60) != 0 )
    idParmState::Set16BitVertexScaleBias(this: renderThreadParmState, vsb: &defaultVSB);
}

