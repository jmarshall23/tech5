
// ========================================================================
// ?BeginScene@bfx@@YAXXZ
// EA  : 0x832487A0
// RVA : 0x012487A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::BeginScene(bfx *this)
{
  bfx::g_pCurInstance->m_pRendererManager->m_renderingScene = true;
}


// ========================================================================
// ?EndScene@bfx@@YAXXZ
// EA  : 0x832487B8
// RVA : 0x012487B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::EndScene(bfx *this)
{
  bfx::g_pCurInstance->m_pRendererManager->m_renderingScene = false;
}


// ========================================================================
// ?CalcCosSin@bfx@@YAXPAM0H@Z
// EA  : 0x832487D0
// RVA : 0x012487D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::CalcCosSin(float *pCosVals, float *pSinVals, int numVals, long double a4)
{
  __int64 v4; // r11
  int v6; // r30
  float *v7; // r31
  int v8; // r28
  double v9; // fp31
  double v10; // fp30
  long double v11; // fp2

  v6 = 0;
  if ( numVals > 0 )
  {
    LODWORD(v4) = numVals;
    v7 = pSinVals;
    v8 = (char *)pCosVals - (char *)pSinVals;
    v9 = (float)v4;
    do
    {
      LODWORD(v4) = v6;
      v10 = (float)((float)((float)v4 * 6.2831855) / (float)v9);
      *(double *)&a4 = v10;
      v11 = cos(x: a4);
      *(float *)((char *)v7 + v8) = *(double *)&v11;
      *(double *)&v11 = v10;
      a4 = sin(x: v11);
      ++v6;
      *v7++ = *(double *)&a4;
    }
    while ( v6 < numVals );
  }
}


// ========================================================================
// ??0QueuedString@bfx@@QAA@ABVVector3@1@ABVString@1@@Z
// EA  : 0x83248878
// RVA : 0x01248878
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

bfx::QueuedString *__fastcall bfx::QueuedString::QueuedString(
        bfx::QueuedString *this,
        const bfx::Vector3 *v0,
        const bfx::String *string)
{
  this->m_v0 = *v0;
  bfx::String::String(this: &this->m_string, rhs: string);
  return this;
}


// ========================================================================
// ?DrawString@bfx@@YAXPADZZ
// EA  : 0x832488F0
// RVA : 0x012488F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void bfx::DrawString(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  bfx::RendererManager *m_pRendererManager; // r31
  char v9[1024]; // [sp+60h] [-410h] BYREF
  __int64 v10; // [sp+488h] [+18h] BYREF
  va_list va; // [sp+488h] [+18h]
  __int64 v12; // [sp+490h] [+20h]
  __int64 v13; // [sp+498h] [+28h]
  __int64 v14; // [sp+4A0h] [+30h]
  __int64 v15; // [sp+4A8h] [+38h]
  __int64 v16; // [sp+4B0h] [+40h]
  __int64 v17; // [sp+4B8h] [+48h]
  va_list va1; // [sp+4C0h] [+50h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v10 = fmt;
  v12 = *(__int64 *)((char *)&a2 + 4);
  v13 = a2;
  v14 = *(__int64 *)((char *)&a3 + 4);
  v15 = a3;
  v16 = *(__int64 *)((char *)&a4 + 4);
  v17 = a4;
  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_pRendererManager->m_pRenderer != nullptr && m_pRendererManager->m_pQueuedData != nullptr )
  {
    vsprintf(string: v9, format: (const char *)HIDWORD(fmt), ap: va);
    m_pRendererManager->m_pRenderer->DrawString_2(this: m_pRendererManager->m_pRenderer, a2: &ColorWhite_0, a3: v9);
  }
}


// ========================================================================
// ?Build@DrawCullData@bfx@@QAAXPBVSpace@2@ABVDrawCullParams@2@@Z
// EA  : 0x83248998
// RVA : 0x01248998
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCullData::Build(
        bfx::DrawCullData *this,
        const bfx::Space *pSpace,
        const bfx::DrawCullParams *drawCullParams)
{
  bfx::Vec3 *p_m_matWorldToSpace; // r30
  double m_x; // fp13
  double m_y; // fp12
  double v8; // fp10
  double v9; // fp9
  double v10; // fp7
  double v11; // fp6
  double v17; // fp29
  double v18; // fp28
  double v19; // fp27
  double v21; // fp26
  double v22; // fp6
  long double v23; // fp2
  double v24; // fp4
  double v25; // fp3
  double v28; // fp31
  double v29; // fp30
  double v30; // fp25
  long double v31; // fp2
  double v32; // fp24
  long double v33; // fp2
  bfx::Vec3 v34; // [sp+50h] [-B0h] BYREF
  bfx::Matrix v35[2]; // [sp+60h] [-A0h] BYREF

  p_m_matWorldToSpace = (bfx::Vec3 *)&pSpace->m_matWorldToSpace;
  this->m_useCulling = true;
  m_x = drawCullParams->m_cameraPos.m_x;
  m_y = drawCullParams->m_cameraPos.m_y;
  v34.m_z = drawCullParams->m_cameraPos.m_z;
  v34.m_y = m_y;
  v34.m_x = m_x;
  bfx::Matrix::operator*(this: v35, result: (bfx::Vec3 *)&pSpace->m_matWorldToSpace, rhs: &v34);
  v8 = v35[0].m_data[1];
  v9 = v35[0].m_data[2];
  this->m_cameraPos.m_x = v35[0].m_data[0];
  this->m_cameraPos.m_y = v8;
  this->m_cameraPos.m_z = v9;
  v10 = drawCullParams->m_cameraDir.m_x;
  v11 = drawCullParams->m_cameraDir.m_y;
  v35[0].m_data[6] = drawCullParams->m_cameraDir.m_z;
  v35[0].m_data[5] = v11;
  v35[0].m_data[4] = v10;
  bfx::Matrix::Rot(
    this: (bfx::Matrix *)&v35[0].m_data[8],
    result: p_m_matWorldToSpace,
    rhs: (const bfx::Vec3 *)&v35[0].m_data[4]);
  this->m_farClipDist = drawCullParams->m_farClipDist;
  _FP6 = -drawCullParams->m_fov;
  _FP5 = (float)((float)180.0 - drawCullParams->m_fov);
  _FP4 = (float)((float)__fsqrts((float)((float)(v35[0].m_data[8] * v35[0].m_data[8])
                                       + (float)((float)(v35[0].m_data[9] * v35[0].m_data[9])
                                               + (float)(v35[0].m_data[10] * v35[0].m_data[10]))))
               - (float)1.0842022e-19);
  __asm
  {
    fsel      f2, f6, f10, f1
    fsel      f1, f4, f3, f30
  }
  v17 = (float)(v35[0].m_data[8] * (float)_FP1);
  v18 = (float)(v35[0].m_data[9] * (float)_FP1);
  v19 = (float)(v35[0].m_data[10] * (float)_FP1);
  __asm { fsel      f9, f5, f10, f13 }
  v21 = (float)((float)((float)_FP9 * (float)0.017453292) * (float)0.5);
  bfx::GetUpVec(result: (bfx::Vec3 *)&v35[0].m_data[12]);
  v22 = (float)((float)(v35[0].m_data[13] * (float)v19) - (float)(v35[0].m_data[14] * (float)v18));
  *(double *)&v23 = v21;
  v24 = (float)((float)((float)v18 * v35[0].m_data[12]) - (float)(v35[0].m_data[13] * (float)v17));
  v25 = (float)((float)(v35[0].m_data[14] * (float)v17) - (float)((float)v19 * v35[0].m_data[12]));
  *((double *)&v23 + 1) = (float)((float)v25 * (float)v25);
  _FP10 = (float)((float)__fsqrts((float)((float)((float)v22 * (float)v22)
                                        + (float)((float)((float)v24 * (float)v24) + (float)((float)v25 * (float)v25))))
                - 1.0842022e-19);
  __asm { fsel      f8, f10, f9, f30 }
  v28 = (float)((float)((float)(v35[0].m_data[13] * (float)v19) - (float)(v35[0].m_data[14] * (float)v18)) * (float)_FP8);
  v29 = (float)((float)((float)(v35[0].m_data[14] * (float)v17) - (float)((float)v19 * v35[0].m_data[12])) * (float)_FP8);
  v30 = (float)((float)((float)((float)v18 * v35[0].m_data[12]) - (float)(v35[0].m_data[13] * (float)v17)) * (float)_FP8);
  v31 = cos(x: v23);
  v32 = (float)*(double *)&v31;
  *(double *)&v31 = v21;
  v33 = sin(x: v31);
  this->m_clipPlanes[0].m_normal.m_x = (float)((float)v28 * (float)v32) + (float)((float)v17 * (float)*(double *)&v33);
  this->m_clipPlanes[0].m_normal.m_y = (float)((float)v29 * (float)v32) + (float)((float)v18 * (float)*(double *)&v33);
  this->m_clipPlanes[0].m_normal.m_z = (float)((float)v30 * (float)v32) + (float)((float)v19 * (float)*(double *)&v33);
  this->m_clipPlanes[1].m_normal.m_x = (float)((float)v17 * (float)*(double *)&v33) - (float)((float)v28 * (float)v32);
  this->m_clipPlanes[1].m_normal.m_y = (float)((float)v18 * (float)*(double *)&v33) - (float)((float)v29 * (float)v32);
  this->m_clipPlanes[1].m_normal.m_z = (float)((float)v19 * (float)*(double *)&v33) - (float)((float)v30 * (float)v32);
  this->m_clipPlanes[0].m_d = (float)(this->m_cameraPos.m_y * this->m_clipPlanes[0].m_normal.m_y)
                            + (float)((float)(this->m_clipPlanes[0].m_normal.m_x * this->m_cameraPos.m_x)
                                    + (float)(this->m_cameraPos.m_z * this->m_clipPlanes[0].m_normal.m_z));
  this->m_clipPlanes[1].m_d = (float)(this->m_cameraPos.m_y * this->m_clipPlanes[1].m_normal.m_y)
                            + (float)((float)(this->m_cameraPos.m_x * this->m_clipPlanes[1].m_normal.m_x)
                                    + (float)(this->m_cameraPos.m_z * this->m_clipPlanes[1].m_normal.m_z));
  this->m_clipPlanes[2].m_normal.m_y = -v18;
  this->m_clipPlanes[2].m_normal.m_z = -v19;
  this->m_clipPlanes[2].m_normal.m_x = -v17;
  this->m_clipPlanes[2].m_d = (float)((float)((float)-v18 * this->m_cameraPos.m_y)
                                    + (float)((float)((float)-v17 * this->m_cameraPos.m_x)
                                            + (float)((float)-v19 * this->m_cameraPos.m_z)))
                            - this->m_farClipDist;
}


// ========================================================================
// ?IsSphereCulled@DrawCullData@bfx@@QBA_NABVVec3@2@M@Z
// EA  : 0x83248C30
// RVA : 0x01248C30
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

int __fastcall bfx::DrawCullData::IsSphereCulled(bfx::DrawCullData *this, const bfx::Vec3 *centerPos, double radius)
{
  bool IsPosWithinConvexVolume; // r3
  unsigned __int8 v4; // r11

  if ( !this->m_useCulling )
    return 0;
  IsPosWithinConvexVolume = bfx::IsPosWithinConvexVolume(
                              pos: centerPos,
                              pPlanes: this->m_clipPlanes,
                              numPlanes: 3,
                              expandDist: radius);
  v4 = 1;
  if ( IsPosWithinConvexVolume )
    return 0;
  return v4;
}


// ========================================================================
// ?SetRenderer@bfx@@YAXPAVRenderer@1@@Z
// EA  : 0x83248C88
// RVA : 0x01248C88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::SetRenderer(bfx::Renderer *pRenderer)
{
  bfx::SystemInstance *v2; // r11
  bfx::APICriticalSection *m_pGlobalCS; // r31

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  v2->m_pRendererManager->m_pRenderer = pRenderer;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// ?DrawQDraw@bfx@@YAXXZ
// EA  : 0x83249278
// RVA : 0x01249278
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawQDraw(bfx *this)
{
  bfx::RendererManager *m_pRendererManager; // r11
  bfx::Array<bfx::QDrawData> *p_m_queuedData; // r30
  int v3; // r29
  int v4; // r31
  bfx::QDrawData *v5; // r10
  bool *m_pDraw; // r11

  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_pRendererManager->m_qdrawEnabled )
  {
    p_m_queuedData = &m_pRendererManager->m_queuedData;
    v3 = 0;
    if ( m_pRendererManager->m_queuedData.m_size > 0 )
    {
      v4 = 0;
      do
      {
        v5 = &p_m_queuedData->m_data[v4];
        m_pDraw = v5->m_pDraw;
        if ( m_pDraw == nullptr || *m_pDraw )
          v5->m_pRenderer->Draw(this: v5->m_pRenderer);
        ++v3;
        ++v4;
      }
      while ( v3 < p_m_queuedData->m_size );
    }
  }
}


// ========================================================================
// ?DrawQueuedLines@bfx@@YAXABV?$Array@VQueuedLine@bfx@@@1@@Z
// EA  : 0x83249308
// RVA : 0x01249308
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawQueuedLines(const bfx::Array<bfx::QueuedLine> *inputLines)
{
  int m_size; // r11
  bfx::RendererManager *m_pRendererManager; // r27
  bfx::QueuedLine *m_data; // r10
  int v5; // r5
  int v6; // r28
  int v7; // r29
  bfx::QueuedLine *v8; // r31
  char v9; // r11
  float m_y; // r8
  float m_z; // r6
  float m_x; // r4
  float v13; // r3
  float v14; // r7
  _QWORD *v15; // r11
  _DWORD *v16; // r10
  float *p_m_a; // r11
  int i; // ctr
  int v19; // r11
  bfx::Color m_color; // [sp+50h] [-3070h] BYREF
  float v21; // [sp+60h] [-3060h]
  float v22; // [sp+64h] [-305Ch]
  float v23; // [sp+68h] [-3058h]
  float v24; // [sp+6Ch] [-3054h]
  float v25; // [sp+70h] [-3050h]
  float v26; // [sp+74h] [-304Ch]
  _QWORD v27[8]; // [sp+80h] [-3040h] BYREF
  int v28; // [sp+3080h] [-40h]

  m_size = inputLines->m_size;
  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_size != 0 )
  {
    m_data = inputLines->m_data;
    v5 = 0;
    v28 = 0;
    v6 = 0;
    m_color = m_data->m_color;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &inputLines->m_data[v7];
        if ( v5 >= 512 )
          goto LABEL_11;
        if ( m_color.m_r != v8->m_color.m_r
          || m_color.m_g != v8->m_color.m_g
          || m_color.m_b != v8->m_color.m_b
          || (v9 = 1, m_color.m_a != v8->m_color.m_a) )
        {
          v9 = 0;
        }
        if ( v9 == 0 )
        {
LABEL_11:
          ((void (__fastcall *)(bfx::Renderer *, _QWORD *))m_pRendererManager->m_pRenderer->DrawLineList)(
            a1: m_pRendererManager->m_pRenderer,
            a2: v27);
          v5 = 0;
          v28 = 0;
          m_color = v8->m_color;
        }
        m_y = v8->m_v0.m_y;
        m_z = v8->m_v0.m_z;
        m_x = v8->m_v1.m_x;
        v13 = v8->m_v1.m_y;
        v14 = v8->m_v1.m_z;
        v15 = &v27[3 * v5];
        v21 = v8->m_v0.m_x;
        v22 = m_y;
        v23 = m_z;
        v24 = m_x;
        v25 = v13;
        v26 = v14;
        if ( v15 != nullptr )
        {
          v16 = (_DWORD *)v15 - 1;
          p_m_a = &m_color.m_a;
          for ( i = 6; i != 0; --i )
            *++v16 = *(_DWORD *)++p_m_a;
          v5 = v28;
        }
        v19 = inputLines->m_size;
        ++v6;
        ++v5;
        ++v7;
        v28 = v5;
      }
      while ( v6 < v19 );
    }
    ((void (__fastcall *)(bfx::Renderer *, _QWORD *))m_pRendererManager->m_pRenderer->DrawLineList)(
      a1: m_pRendererManager->m_pRenderer,
      a2: v27);
  }
}


// ========================================================================
// ?DrawQueuedTris@bfx@@YAXABV?$Array@VQueuedTri@bfx@@@1@@Z
// EA  : 0x832494E0
// RVA : 0x012494E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawQueuedTris(const bfx::Array<bfx::QueuedTri> *inputTris)
{
  int m_size; // r11
  bfx::RendererManager *m_pRendererManager; // r27
  bfx::QueuedTri *m_data; // r10
  int v5; // r5
  int v6; // r28
  int v7; // r29
  bfx::QueuedTri *v8; // r31
  char v9; // r11
  float m_x; // r9
  float m_y; // r8
  float m_z; // r6
  float v13; // r4
  float v14; // r3
  float v15; // r7
  float v16; // r26
  float v17; // r10
  float v18; // r31
  _DWORD *v19; // r10
  float *p_m_a; // r11
  int i; // ctr
  int v22; // r11
  bfx::Color m_color; // [sp+50h] [-2480h] BYREF
  float v24; // [sp+60h] [-2470h]
  float v25; // [sp+64h] [-246Ch]
  float v26; // [sp+68h] [-2468h]
  float v27; // [sp+6Ch] [-2464h]
  float v28; // [sp+70h] [-2460h]
  float v29; // [sp+74h] [-245Ch]
  float v30; // [sp+78h] [-2458h]
  float v31; // [sp+7Ch] [-2454h]
  float v32; // [sp+80h] [-2450h]
  _DWORD v33[272]; // [sp+90h] [-2440h] BYREF
  int v34; // [sp+2490h] [-40h]

  m_size = inputTris->m_size;
  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_size != 0 )
  {
    m_data = inputTris->m_data;
    v5 = 0;
    v34 = 0;
    v6 = 0;
    m_color = m_data->m_color;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &inputTris->m_data[v7];
        if ( v5 >= 256 )
          goto LABEL_11;
        if ( m_color.m_r != v8->m_color.m_r
          || m_color.m_g != v8->m_color.m_g
          || m_color.m_b != v8->m_color.m_b
          || (v9 = 1, m_color.m_a != v8->m_color.m_a) )
        {
          v9 = 0;
        }
        if ( v9 == 0 )
        {
LABEL_11:
          ((void (__fastcall *)(bfx::Renderer *, _DWORD *))m_pRendererManager->m_pRenderer->DrawTriList)(
            a1: m_pRendererManager->m_pRenderer,
            a2: v33);
          v5 = 0;
          v34 = 0;
          m_color = v8->m_color;
        }
        m_x = v8->m_v0.m_x;
        m_y = v8->m_v0.m_y;
        m_z = v8->m_v0.m_z;
        v13 = v8->m_v1.m_x;
        v14 = v8->m_v1.m_y;
        v15 = v8->m_v1.m_z;
        v16 = v8->m_v2.m_x;
        v17 = v8->m_v2.m_y;
        v18 = v8->m_v2.m_z;
        v24 = m_x;
        v25 = m_y;
        v26 = m_z;
        v27 = v13;
        v28 = v14;
        v29 = v15;
        v30 = v16;
        v31 = v17;
        v32 = v18;
        if ( &v33[9 * v5] != nullptr )
        {
          v19 = &v33[9 * v5 - 1];
          p_m_a = &m_color.m_a;
          for ( i = 9; i != 0; --i )
            *++v19 = *(_DWORD *)++p_m_a;
          v5 = v34;
        }
        v22 = inputTris->m_size;
        ++v6;
        ++v5;
        ++v7;
        v34 = v5;
      }
      while ( v6 < v22 );
    }
    ((void (__fastcall *)(bfx::Renderer *, _DWORD *))m_pRendererManager->m_pRenderer->DrawTriList)(
      a1: m_pRendererManager->m_pRenderer,
      a2: v33);
  }
}


// ========================================================================
// ?DrawLineList@bfx@@YAXPBVSpace@1@PAVVec3@1@HABVColor@1@@Z
// EA  : 0x832496C8
// RVA : 0x012496C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawLineList(const bfx::Space *pSpace, bfx::Vec3 *pVerts, int numVerts, const bfx::Color *color)
{
  bfx::RendererManager *m_pRendererManager; // r28
  int v7; // r29
  bfx::Vec3 *v8; // r27
  bfx::Vec3 *v9; // r3
  bfx::Vec3 *v10; // r3
  float v11; // r24
  float v12; // r6
  float v13; // r5
  float v14; // r11
  float v15; // r26
  float v16; // r25
  const bfx::Array<bfx::QueuedLine> *p_m_cachedLines; // r3
  bfx::Vec3 *v18; // r27
  bfx::Vec3 *v19; // r3
  bfx::Vec3 *v20; // r3
  float v21; // r6
  float v22; // r5
  float v23; // r26
  float v24; // r25
  int v25; // r29
  bfx::Vec3 *p_m_matSpaceToWorld; // r27
  bfx::Vec3 *v27; // r3
  bfx::Vec3 *v28; // r3
  float m_r; // r6
  float m_g; // r5
  float m_b; // r11
  float m_a; // r25
  bfx::QueuedData *m_pQueuedData; // r30
  float v34; // [sp+50h] [-B0h]
  float v35; // [sp+50h] [-B0h]
  float v36; // [sp+50h] [-B0h]
  float v37; // [sp+54h] [-ACh]
  float v38; // [sp+54h] [-ACh]
  float v39; // [sp+54h] [-ACh]
  float v40; // [sp+58h] [-A8h]
  float v41; // [sp+58h] [-A8h]
  float v42; // [sp+58h] [-A8h]
  float v43; // [sp+60h] [-A0h]
  float m_x; // [sp+60h] [-A0h]
  float v45; // [sp+64h] [-9Ch]
  float v46; // [sp+64h] [-9Ch]
  float m_y; // [sp+64h] [-9Ch]
  float v48; // [sp+68h] [-98h]
  float m_z; // [sp+68h] [-98h]
  bfx::Matrix v50; // [sp+70h] [-90h] BYREF
  float v51; // [sp+B0h] [-50h]
  float v52; // [sp+B4h] [-4Ch]

  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_pRendererManager->m_pRenderer != nullptr && m_pRendererManager->m_pQueuedData != nullptr )
  {
    if ( m_pRendererManager->m_pActiveQueuedRenderer != nullptr )
    {
      v25 = numVerts / 2;
      if ( numVerts / 2 > 0 )
      {
        p_m_matSpaceToWorld = (bfx::Vec3 *)&pSpace->m_matSpaceToWorld;
        do
        {
          v27 = bfx::Matrix::operator*(
                  this: (bfx::Matrix *)&v50.m_data[4],
                  result: p_m_matSpaceToWorld,
                  rhs: pVerts + 1);
          m_x = v27->m_x;
          m_y = v27->m_y;
          m_z = v27->m_z;
          v28 = bfx::Matrix::operator*(this: &v50, result: p_m_matSpaceToWorld, rhs: pVerts);
          v42 = v28->m_z;
          v36 = v28->m_x;
          m_r = color->m_r;
          m_g = color->m_g;
          v50.m_data[12] = m_y;
          v39 = v28->m_y;
          v50.m_data[13] = m_z;
          m_b = color->m_b;
          m_a = color->m_a;
          v50.m_data[11] = m_x;
          v50.m_data[9] = v39;
          v50.m_data[10] = v42;
          v50.m_data[8] = v36;
          v50.m_data[14] = m_r;
          v50.m_data[15] = m_g;
          v51 = m_b;
          v52 = m_a;
          bfx::Array<bfx::QueuedLine>::push_back(
            this: &m_pRendererManager->m_pQueuedData->m_cachedLines,
            val: (const bfx::QueuedLine *)&v50.m_data[8]);
          --v25;
          pVerts += 2;
        }
        while ( v25 != 0 );
      }
      bfx::DrawQueuedLines(inputLines: &m_pRendererManager->m_pQueuedData->m_cachedLines);
      m_pQueuedData = m_pRendererManager->m_pQueuedData;
      m_pQueuedData->m_cachedLines.m_size = 0;
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pQueuedData->m_cachedLines.m_data);
      m_pQueuedData->m_cachedLines.m_data = nullptr;
      m_pQueuedData->m_cachedLines.m_cap = 0;
    }
    else
    {
      v7 = numVerts / 2;
      if ( m_pRendererManager->m_renderingScene )
      {
        if ( numVerts / 2 > 0 )
        {
          v8 = (bfx::Vec3 *)&pSpace->m_matSpaceToWorld;
          do
          {
            v9 = bfx::Matrix::operator*(this: &v50, result: v8, rhs: pVerts + 1);
            v34 = v9->m_x;
            v37 = v9->m_y;
            v40 = v9->m_z;
            v10 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v50.m_data[4], result: v8, rhs: pVerts);
            v11 = v10->m_x;
            v45 = v10->m_y;
            v12 = color->m_r;
            v50.m_data[11] = v34;
            v13 = color->m_g;
            v14 = color->m_b;
            v15 = color->m_a;
            v16 = v10->m_z;
            v50.m_data[12] = v37;
            v50.m_data[13] = v40;
            v50.m_data[10] = v16;
            v50.m_data[9] = v45;
            v50.m_data[8] = v11;
            v50.m_data[14] = v12;
            v50.m_data[15] = v13;
            v51 = v14;
            v52 = v15;
            bfx::Array<bfx::QueuedLine>::push_back(
              this: &m_pRendererManager->m_pQueuedData->m_cachedLines,
              val: (const bfx::QueuedLine *)&v50.m_data[8]);
            --v7;
            pVerts += 2;
          }
          while ( v7 != 0 );
        }
        p_m_cachedLines = &m_pRendererManager->m_pQueuedData->m_cachedLines;
        if ( p_m_cachedLines->m_size > 1000 )
        {
          bfx::DrawQueuedLines(inputLines: p_m_cachedLines);
          bfx::Array<bfx::QueuedLine>::resize(this: &m_pRendererManager->m_pQueuedData->m_cachedLines, size: 0);
        }
      }
      else if ( numVerts / 2 > 0 )
      {
        v18 = (bfx::Vec3 *)&pSpace->m_matSpaceToWorld;
        do
        {
          v19 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v50.m_data[4], result: v18, rhs: pVerts + 1);
          v43 = v19->m_x;
          v46 = v19->m_y;
          v48 = v19->m_z;
          v20 = bfx::Matrix::operator*(this: &v50, result: v18, rhs: pVerts);
          v41 = v20->m_z;
          v35 = v20->m_x;
          v21 = color->m_r;
          v22 = color->m_g;
          v50.m_data[11] = v43;
          v38 = v20->m_y;
          v50.m_data[12] = v46;
          v23 = color->m_b;
          v24 = color->m_a;
          v50.m_data[9] = v38;
          v50.m_data[13] = v48;
          v50.m_data[8] = v35;
          v50.m_data[10] = v41;
          v50.m_data[14] = v21;
          v50.m_data[15] = v22;
          v51 = v23;
          v52 = v24;
          bfx::Array<bfx::QueuedLine>::push_back(
            this: &m_pRendererManager->m_pQueuedData->m_deferredLines,
            val: (const bfx::QueuedLine *)&v50.m_data[8]);
          --v7;
          pVerts += 2;
        }
        while ( v7 != 0 );
      }
    }
  }
}


// ========================================================================
// ?DrawSolidTri@bfx@@YAXPBVSpace@1@ABVVec3@1@11ABVColor@1@@Z
// EA  : 0x832499E8
// RVA : 0x012499E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawSolidTri(
        bfx::Vector3 *pSpace,
        const bfx::Vec3 *v0,
        const bfx::Vec3 *v1,
        const bfx::Vec3 *v2,
        const bfx::Color *color)
{
  bfx::RendererManager *m_pRendererManager; // r29
  bfx::Space *v10; // r26
  bfx::Space *v11; // r27
  bfx::Space *v12; // r3
  float v13; // r11
  float v14; // r6
  float v15; // r5
  float v16; // r9
  float v17; // r8
  float v18; // r7
  float v19; // r30
  float v20; // r28
  float m_r; // r27
  float m_g; // r26
  float m_b; // r25
  float m_a; // r31
  const bfx::Array<bfx::QueuedTri> *m_pQueuedData; // r11
  bfx::Space *v26; // r26
  bfx::Space *v27; // r27
  bfx::Space *v28; // r3
  float v29; // r11
  float v30; // r6
  float v31; // r5
  float v32; // r9
  float v33; // r8
  float v34; // r7
  float v35; // r30
  float v36; // r28
  float v37; // r27
  float v38; // r26
  float v39; // r25
  float v40; // r31
  bfx::Space *v41; // r26
  bfx::Space *v42; // r27
  bfx::Space *v43; // r3
  float v44; // r10
  unsigned int m_spaceID; // r9
  float v46; // r8
  float v47; // r3
  float v48; // r10
  float v49; // r9
  bfx::Space v50; // [sp+50h] [-E0h] BYREF

  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_pRendererManager->m_pRenderer != nullptr && m_pRendererManager->m_pQueuedData != nullptr )
  {
    if ( m_pRendererManager->m_pActiveQueuedRenderer != nullptr )
    {
      v41 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_rotSpaceToWorld.m_y, result: pSpace, posIn: v2);
      v42 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_pos.m_y, result: pSpace, posIn: v1);
      v43 = bfx::Space::TransformSpaceToWorld(this: &v50, result: pSpace, posIn: v0);
      v44 = *(float *)&v43->m_pProxy;
      m_spaceID = v43->m_spaceID;
      LODWORD(v50.m_rotWorldToSpace.m_y) = v43->__vftable;
      v50.m_rotWorldToSpace.m_z = v44;
      v50.m_userData = m_spaceID;
      v46 = *(float *)&v42->__vftable;
      v47 = *(float *)&v42->m_spaceID;
      LODWORD(v50.m_matSpaceToWorld.m_data[1]) = v42->m_pProxy;
      v50.m_matSpaceToWorld.m_data[0] = v46;
      v50.m_matSpaceToWorld.m_data[2] = v47;
      v48 = *(float *)&v41->m_pProxy;
      v49 = *(float *)&v41->m_spaceID;
      LODWORD(v50.m_matSpaceToWorld.m_data[3]) = v41->__vftable;
      v50.m_matSpaceToWorld.m_data[4] = v48;
      v50.m_matSpaceToWorld.m_data[5] = v49;
      m_pRendererManager->m_pRenderer->DrawTriList(
        this: m_pRendererManager->m_pRenderer,
        a2: (const bfx::Triangle *)&v50.m_rotWorldToSpace.m_y,
        a3: 1u,
        a4: color);
    }
    else if ( m_pRendererManager->m_renderingScene )
    {
      v10 = bfx::Space::TransformSpaceToWorld(this: &v50, result: pSpace, posIn: v2);
      v11 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_pos.m_y, result: pSpace, posIn: v1);
      v12 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_rotSpaceToWorld.m_y, result: pSpace, posIn: v0);
      v13 = *(float *)&v11->__vftable;
      v14 = *(float *)&v12->__vftable;
      v15 = *(float *)&v12->m_pProxy;
      v16 = *(float *)&v11->m_pProxy;
      v17 = *(float *)&v11->m_spaceID;
      v18 = *(float *)&v10->__vftable;
      v19 = *(float *)&v10->m_pProxy;
      v20 = *(float *)&v10->m_spaceID;
      m_r = color->m_r;
      m_g = color->m_g;
      m_b = color->m_b;
      m_a = color->m_a;
      LODWORD(v50.m_matSpaceToWorld.m_data[11]) = v12->m_spaceID;
      v50.m_matSpaceToWorld.m_data[12] = v13;
      v50.m_matSpaceToWorld.m_data[9] = v14;
      v50.m_matSpaceToWorld.m_data[10] = v15;
      v50.m_matSpaceToWorld.m_data[13] = v16;
      v50.m_matSpaceToWorld.m_data[14] = v17;
      v50.m_matSpaceToWorld.m_data[15] = v18;
      v50.m_matWorldToSpace.m_data[0] = v19;
      v50.m_matWorldToSpace.m_data[1] = v20;
      v50.m_matWorldToSpace.m_data[2] = m_r;
      v50.m_matWorldToSpace.m_data[3] = m_g;
      v50.m_matWorldToSpace.m_data[4] = m_b;
      v50.m_matWorldToSpace.m_data[5] = m_a;
      bfx::Array<bfx::QueuedTri>::push_back(
        this: &m_pRendererManager->m_pQueuedData->m_cachedTris,
        val: (const bfx::QueuedTri *)&v50.m_matSpaceToWorld.m_data[9]);
      m_pQueuedData = (const bfx::Array<bfx::QueuedTri> *)m_pRendererManager->m_pQueuedData;
      if ( m_pQueuedData[1].m_size > 500 )
      {
        bfx::DrawQueuedTris(inputTris: m_pQueuedData + 1);
        bfx::Array<bfx::QueuedTri>::resize(this: &m_pRendererManager->m_pQueuedData->m_cachedTris, size: 0);
      }
    }
    else
    {
      v26 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_rotSpaceToWorld.m_y, result: pSpace, posIn: v2);
      v27 = bfx::Space::TransformSpaceToWorld(this: (bfx::Space *)&v50.m_pos.m_y, result: pSpace, posIn: v1);
      v28 = bfx::Space::TransformSpaceToWorld(this: &v50, result: pSpace, posIn: v0);
      v29 = *(float *)&v27->__vftable;
      v30 = *(float *)&v28->__vftable;
      v31 = *(float *)&v28->m_pProxy;
      v32 = *(float *)&v27->m_pProxy;
      v33 = *(float *)&v27->m_spaceID;
      v34 = *(float *)&v26->__vftable;
      v35 = *(float *)&v26->m_pProxy;
      v36 = *(float *)&v26->m_spaceID;
      v37 = color->m_r;
      v38 = color->m_g;
      v39 = color->m_b;
      v40 = color->m_a;
      LODWORD(v50.m_matSpaceToWorld.m_data[11]) = v28->m_spaceID;
      v50.m_matSpaceToWorld.m_data[12] = v29;
      v50.m_matSpaceToWorld.m_data[9] = v30;
      v50.m_matSpaceToWorld.m_data[10] = v31;
      v50.m_matSpaceToWorld.m_data[13] = v32;
      v50.m_matSpaceToWorld.m_data[14] = v33;
      v50.m_matSpaceToWorld.m_data[15] = v34;
      v50.m_matWorldToSpace.m_data[0] = v35;
      v50.m_matWorldToSpace.m_data[1] = v36;
      v50.m_matWorldToSpace.m_data[2] = v37;
      v50.m_matWorldToSpace.m_data[3] = v38;
      v50.m_matWorldToSpace.m_data[4] = v39;
      v50.m_matWorldToSpace.m_data[5] = v40;
      bfx::Array<bfx::QueuedTri>::push_back(
        this: &m_pRendererManager->m_pQueuedData->m_deferredTris,
        val: (const bfx::QueuedTri *)&v50.m_matSpaceToWorld.m_data[9]);
    }
  }
}


// ========================================================================
// ?DrawArc@bfx@@YAXPAVSpace@1@MMMABVMatrix@1@ABVColor@1@@Z
// EA  : 0x83249C78
// RVA : 0x01249C78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawArc(
        bfx::Vector3 *a1,
        long double endAngleInRadians,
        double radius,
        const bfx::Matrix *mat,
        const bfx::Color *drawCol,
        int a6,
        bfx::Vec3 *a7,
        const bfx::Color *a8)
{
  double v9; // fp30
  double v10; // fp31
  long double v14; // fp2
  double v15; // fp27
  long double v16; // fp2
  __int64 v17; // r11
  long double v18; // fp2
  char v19; // r29
  int v20; // r30
  double v21; // fp0
  double v22; // fp26
  long double v23; // fp2
  double v24; // fp25
  long double v25; // fp2
  double m_y; // fp10
  double m_z; // fp9
  bfx::Matrix v28; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v29; // [sp+98h] [-78h] BYREF

  v9 = *(double *)&endAngleInRadians;
  v10 = *((double *)&endAngleInRadians + 1);
  if ( *(double *)&endAngleInRadians > *((double *)&endAngleInRadians + 1) )
  {
    v9 = *((double *)&endAngleInRadians + 1);
    v10 = *(double *)&endAngleInRadians;
  }
  *(double *)&endAngleInRadians = v9;
  v14 = sin(x: endAngleInRadians);
  v15 = (float)*(double *)&v14;
  *(double *)&v14 = v9;
  v16 = cos(x: v14);
  v28.m_data[9] = (float)v15 * (float)radius;
  v28.m_data[10] = 0.0;
  v28.m_data[8] = (float)*(double *)&v16 * (float)radius;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v28.m_data[4], result: a7, rhs: (const bfx::Vec3 *)&v28.m_data[8]);
  v19 = 0;
  v20 = 1;
  do
  {
    if ( v19 != 0 )
      break;
    LODWORD(v17) = v20;
    v21 = (float)((float)((float)v17 * (float)0.39269909) + (float)v9);
    if ( v21 >= v10 )
    {
      v21 = v10;
      v19 = 1;
    }
    v22 = v21;
    *(double *)&v18 = v21;
    v23 = sin(x: v18);
    v24 = (float)*(double *)&v23;
    *(double *)&v23 = v22;
    v25 = cos(x: v23);
    v28.m_data[14] = 0.0;
    v28.m_data[13] = (float)v24 * (float)radius;
    v28.m_data[12] = (float)*(double *)&v25 * (float)radius;
    bfx::Matrix::operator*(this: &v28, result: a7, rhs: (const bfx::Vec3 *)&v28.m_data[12]);
    m_y = a7[4].m_y;
    m_z = a7[4].m_z;
    v29.m_x = a7[4].m_x;
    v29.m_y = m_y;
    v29.m_z = m_z;
    bfx::DrawSolidTri(
      pSpace: a1,
      v0: &v29,
      v1: (const bfx::Vec3 *)&v28.m_data[4],
      v2: (const bfx::Vec3 *)&v28,
      color: a8);
    ++v20;
    v28.m_data[4] = v28.m_data[0];
    v28.m_data[5] = v28.m_data[1];
    v28.m_data[6] = v28.m_data[2];
  }
  while ( v20 <= 16 );
}


// ========================================================================
// ?DrawSolidBox@bfx@@YAXPBVSpace@1@ABVMatrix@1@ABVBox@1@ABVColor@1@@Z
// EA  : 0x83249DE8
// RVA : 0x01249DE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawSolidBox(
        bfx::Vector3 *pSpace,
        bfx::Vec3 *mat,
        const bfx::Box *boxLCoord,
        const bfx::Color *color)
{
  int v8; // r31
  float *v9; // r29
  const bfx::Box *p_m_max; // r11
  double m_z; // fp13
  const bfx::Box *v12; // r11
  double m_y; // fp0
  const bfx::Box *v14; // r11
  bfx::Vec3 *v15; // r3
  bfx::Vec3 v16; // [sp+50h] [-C0h] BYREF
  bfx::Matrix v17; // [sp+60h] [-B0h] BYREF
  bfx::Vec3 v18; // [sp+A0h] [-70h] BYREF
  bfx::Vec3 v19; // [sp+ACh] [-64h] BYREF
  bfx::Vec3 v20; // [sp+B8h] [-58h] BYREF
  bfx::Vec3 v21[6]; // [sp+C4h] [-4Ch] BYREF

  v8 = 0;
  v9 = &v17.m_data[3];
  do
  {
    p_m_max = boxLCoord;
    if ( (v8 & 1) != 0 )
      p_m_max = (const bfx::Box *)&boxLCoord->m_max;
    m_z = p_m_max->m_min.m_z;
    v12 = boxLCoord;
    if ( (unsigned int)v8 >> 1 != 2 * ((unsigned int)v8 >> 2) )
      v12 = (const bfx::Box *)&boxLCoord->m_max;
    m_y = v12->m_min.m_y;
    v14 = boxLCoord;
    if ( (v8 & 0xFFFFFFFC) != 0 )
      v14 = (const bfx::Box *)&boxLCoord->m_max;
    v16.m_x = v14->m_min.m_x;
    v16.m_y = m_y;
    v16.m_z = m_z;
    v15 = bfx::Matrix::operator*(this: &v17, result: mat, rhs: &v16);
    v9[1] = v15->m_x;
    ++v8;
    v9[2] = v15->m_y;
    v9 += 3;
    *v9 = v15->m_z;
  }
  while ( v8 < 8 );
  bfx::DrawSolidTri(pSpace, v0: (const bfx::Vec3 *)&v17.m_data[7], v1: &v19, v2: v21, color);
  bfx::DrawSolidTri(
    pSpace,
    v0: (const bfx::Vec3 *)&v17.m_data[7],
    v1: v21,
    v2: (const bfx::Vec3 *)&v17.m_data[13],
    color);
  bfx::DrawSolidTri(pSpace, v0: (const bfx::Vec3 *)&v17.m_data[4], v1: &v18, v2: &v19, color);
  bfx::DrawSolidTri(
    pSpace,
    v0: (const bfx::Vec3 *)&v17.m_data[4],
    v1: &v19,
    v2: (const bfx::Vec3 *)&v17.m_data[7],
    color);
  bfx::DrawSolidTri(pSpace, v0: &v18, v1: &v20, v2: v21, color);
  bfx::DrawSolidTri(pSpace, v0: &v18, v1: v21, v2: &v19, color);
  bfx::DrawSolidTri(
    pSpace,
    v0: &v20,
    v1: (const bfx::Vec3 *)&v17.m_data[10],
    v2: (const bfx::Vec3 *)&v17.m_data[13],
    color);
  bfx::DrawSolidTri(pSpace, v0: &v20, v1: (const bfx::Vec3 *)&v17.m_data[13], v2: v21, color);
  bfx::DrawSolidTri(
    pSpace,
    v0: (const bfx::Vec3 *)&v17.m_data[10],
    v1: (const bfx::Vec3 *)&v17.m_data[4],
    v2: (const bfx::Vec3 *)&v17.m_data[7],
    color);
  bfx::DrawSolidTri(
    pSpace,
    v0: (const bfx::Vec3 *)&v17.m_data[10],
    v1: (const bfx::Vec3 *)&v17.m_data[7],
    v2: (const bfx::Vec3 *)&v17.m_data[13],
    color);
  bfx::DrawSolidTri(
    pSpace,
    v0: &v18,
    v1: (const bfx::Vec3 *)&v17.m_data[4],
    v2: (const bfx::Vec3 *)&v17.m_data[10],
    color);
  bfx::DrawSolidTri(pSpace, v0: &v18, v1: (const bfx::Vec3 *)&v17.m_data[10], v2: &v20, color);
}


// ========================================================================
// ?DrawCylinderDiagonals@bfx@@YAXPBVSpace@1@ABVMatrix@1@MMABVColor@1@H@Z
// EA  : 0x83249FD0
// RVA : 0x01249FD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCylinderDiagonals(
        const bfx::Space *pSpace,
        bfx::Vec3 *mat,
        double height,
        double radius,
        const bfx::Color *color,
        int segments,
        const bfx::Color *a7,
        signed int a8)
{
  double m_z; // fp0
  double m_x; // fp13
  double m_y; // fp12
  double v16; // fp29
  double v17; // fp28
  double v18; // fp27
  int v19; // r30
  float *v20; // r31
  int v21; // r11
  int v22; // r6
  double v23; // fp11
  double v24; // fp6
  double v25; // fp0
  double v26; // fp5
  double v27; // fp13
  double v28; // fp12
  bfx::Matrix v29; // [sp+50h] [-240h] BYREF
  bfx::Vec3 v30; // [sp+90h] [-200h] BYREF

  v29.m_data[12] = radius;
  m_z = mat[2].m_z;
  m_x = mat[3].m_x;
  m_y = mat[3].m_y;
  v29.m_data[13] = 0.0;
  v29.m_data[14] = 0.0;
  v16 = (float)((float)m_z * (float)height);
  v17 = (float)((float)m_x * (float)height);
  v18 = (float)((float)m_y * (float)height);
  bfx::Matrix::operator*(this: &v29, result: mat, rhs: (const bfx::Vec3 *)&v29.m_data[12]);
  v19 = 1;
  if ( a8 >= 1 )
  {
    v20 = &v29.m_data[15];
    do
    {
      v21 = v19;
      if ( a8 < 16 )
      {
        __twllei(a8, 0);
        v21 = 16 / a8 * v19;
      }
      v29.m_data[6] = 0.0;
      v22 = v21 % 16;
      v23 = (float)(bfx::sinVals[v22] * (float)radius);
      v29.m_data[4] = bfx::cosVals[v22] * (float)radius;
      v29.m_data[5] = v23;
      bfx::Matrix::operator*(this: (bfx::Matrix *)&v29.m_data[8], result: mat, rhs: (const bfx::Vec3 *)&v29.m_data[4]);
      ++v19;
      v24 = (float)(v29.m_data[1] + (float)v17);
      v25 = v29.m_data[8];
      v26 = (float)(v29.m_data[2] + (float)v18);
      v27 = v29.m_data[9];
      v20[1] = v29.m_data[0] + (float)v16;
      v20[2] = v24;
      v20[3] = v26;
      v28 = v29.m_data[10];
      v20[4] = v25;
      v20[5] = v27;
      v29.m_data[0] = v25;
      v29.m_data[1] = v27;
      v29.m_data[2] = v28;
      v20 += 6;
      *v20 = v28;
    }
    while ( v19 <= a8 );
  }
  bfx::DrawLineList(pSpace, pVerts: &v30, numVerts: 2 * a8, color: a7);
}


// ========================================================================
// ?DrawCylinder@bfx@@YAXPBVSpace@1@ABVMatrix@1@MMABVColor@1@H@Z
// EA  : 0x8324A130
// RVA : 0x0124A130
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCylinder(
        const bfx::Space *pSpace,
        bfx::Vec3 *mat,
        double height,
        double radius,
        const bfx::Color *color,
        int segments,
        const bfx::Color *a7,
        signed int a8)
{
  double m_z; // fp0
  double m_x; // fp13
  double m_y; // fp12
  double v16; // fp30
  double v17; // fp29
  double v18; // fp28
  int v19; // r30
  float *v20; // r31
  int v21; // r11
  int v22; // r6
  double v23; // fp11
  double v24; // fp10
  double v25; // fp8
  double v26; // fp9
  double v27; // fp7
  double v28; // fp0
  double v29; // fp13
  double v30; // fp5
  double v31; // fp12
  double v32; // fp4
  bfx::Matrix v33; // [sp+50h] [-540h] BYREF
  bfx::Vec3 v34; // [sp+90h] [-500h] BYREF

  v33.m_data[12] = radius;
  m_z = mat[2].m_z;
  m_x = mat[3].m_x;
  m_y = mat[3].m_y;
  v33.m_data[13] = 0.0;
  v33.m_data[14] = 0.0;
  v16 = (float)((float)m_z * (float)height);
  v17 = (float)((float)m_x * (float)height);
  v18 = (float)((float)m_y * (float)height);
  v19 = 1;
  bfx::Matrix::operator*(this: &v33, result: mat, rhs: (const bfx::Vec3 *)&v33.m_data[12]);
  if ( a8 >= 1 )
  {
    v20 = &v33.m_data[15];
    do
    {
      v21 = v19;
      if ( a8 < 16 )
      {
        __twllei(a8, 0);
        v21 = 16 / a8 * v19;
      }
      v33.m_data[6] = 0.0;
      v22 = v21 % 16;
      v23 = (float)(bfx::sinVals[v22] * (float)radius);
      v33.m_data[4] = bfx::cosVals[v22] * (float)radius;
      v33.m_data[5] = v23;
      bfx::Matrix::operator*(this: (bfx::Matrix *)&v33.m_data[8], result: mat, rhs: (const bfx::Vec3 *)&v33.m_data[4]);
      v24 = v33.m_data[1];
      v25 = (float)(v33.m_data[0] + (float)v16);
      v26 = v33.m_data[2];
      v27 = (float)(v33.m_data[1] + (float)v17);
      v20[1] = v33.m_data[0];
      v20[2] = v24;
      ++v19;
      v20[3] = v26;
      v28 = v33.m_data[8];
      v29 = v33.m_data[9];
      v30 = (float)(v33.m_data[8] + (float)v16);
      v31 = v33.m_data[10];
      v32 = (float)(v33.m_data[9] + (float)v17);
      v20[4] = v33.m_data[8];
      v20[5] = v29;
      v20[6] = v31;
      v20[7] = v25;
      v20[8] = v27;
      v20[9] = (float)v26 + (float)v18;
      v20[10] = v30;
      v20[11] = v32;
      v20[12] = (float)v31 + (float)v18;
      v20[13] = v28;
      v20[14] = v29;
      v20[15] = v31;
      v20[16] = v30;
      v20[17] = v32;
      v33.m_data[0] = v28;
      v33.m_data[1] = v29;
      v33.m_data[2] = v31;
      v20 += 18;
      *v20 = (float)v31 + (float)v18;
    }
    while ( v19 <= a8 );
  }
  bfx::DrawLineList(pSpace, pVerts: &v34, numVerts: 6 * a8, color: a7);
}


// ========================================================================
// ?DrawSolidCylinderParts@bfx@@YAXPBVSpace@1@ABVMatrix@1@MMABVColor@1@MMHI@Z
// EA  : 0x8324A2D0
// RVA : 0x0124A2D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawSolidCylinderParts(
        bfx::Vector3 *a1,
        bfx::Vec3 *a2,
        long double radius,
        const bfx::Color *color,
        double startAngle,
        double stopAngle,
        int numSegments,
        const bfx::Color *partsToDraw,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        char a31)
{
  __int64 v31; // r11
  double v33; // fp30
  double v34; // fp29
  double v35; // fp28
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  double v40; // fp31
  int v43; // r27
  int v44; // r28
  double v45; // fp26
  double v46; // fp25
  double v47; // fp23
  long double v48; // fp2
  double v49; // fp22
  long double v50; // fp2
  bfx::Matrix v51; // [sp+58h] [-F8h] BYREF
  bfx::Vec3 v52; // [sp+98h] [-B8h] BYREF
  bfx::Vec3 v53; // [sp+A8h] [-A8h] BYREF
  bfx::Vec3 v54; // [sp+B8h] [-98h] BYREF

  v33 = (float)(a2[2].m_z * (float)*(double *)&radius);
  v34 = (float)(a2[3].m_x * (float)*(double *)&radius);
  v35 = (float)(a2[3].m_y * (float)*(double *)&radius);
  m_x = a2[4].m_x;
  m_y = a2[4].m_y;
  m_z = a2[4].m_z;
  v40 = *((double *)&radius + 1);
  v53.m_y = a2[4].m_y;
  v53.m_x = m_x;
  v53.m_z = m_z;
  v43 = HIDWORD(v31) + 1;
  v44 = 0;
  v52.m_x = (float)m_x + (float)v33;
  v52.m_y = (float)m_y + (float)v34;
  v52.m_z = (float)m_z + (float)v35;
  if ( HIDWORD(v31) + 1 > 0 )
  {
    LODWORD(v31) = HIDWORD(v31);
    v45 = (float)((float)stopAngle - (float)startAngle);
    v46 = (float)v31;
    do
    {
      LODWORD(v31) = v44;
      v47 = (float)((float)((float)((float)v31 * (float)v45) / (float)v46) + (float)startAngle);
      *(double *)&radius = v47;
      v48 = sin(x: radius);
      v49 = (float)*(double *)&v48;
      *(double *)&v48 = v47;
      v50 = cos(x: v48);
      v54.m_z = 0.0;
      v54.m_y = (float)v49 * (float)v40;
      v54.m_x = (float)*(double *)&v50 * (float)v40;
      bfx::Matrix::operator*(this: &v51, result: a2, rhs: &v54);
      *((double *)&radius + 1) = (float)(v51.m_data[1] + (float)v34);
      v51.m_data[4] = (float)v33 + v51.m_data[0];
      v51.m_data[5] = v51.m_data[1] + (float)v34;
      v51.m_data[6] = v51.m_data[2] + (float)v35;
      if ( v44 > 0 )
      {
        if ( (a31 & 1) != 0 )
        {
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: &v52,
            v1: (const bfx::Vec3 *)&v51.m_data[8],
            v2: (const bfx::Vec3 *)&v51.m_data[4],
            color: partsToDraw);
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: &v52,
            v1: (const bfx::Vec3 *)&v51.m_data[4],
            v2: (const bfx::Vec3 *)&v51.m_data[8],
            color: partsToDraw);
        }
        if ( (a31 & 2) != 0 )
        {
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: (const bfx::Vec3 *)&v51.m_data[12],
            v1: (const bfx::Vec3 *)&v51,
            v2: (const bfx::Vec3 *)&v51.m_data[8],
            color: partsToDraw);
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: (const bfx::Vec3 *)&v51,
            v1: (const bfx::Vec3 *)&v51.m_data[4],
            v2: (const bfx::Vec3 *)&v51.m_data[8],
            color: partsToDraw);
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: (const bfx::Vec3 *)&v51.m_data[12],
            v1: (const bfx::Vec3 *)&v51.m_data[8],
            v2: (const bfx::Vec3 *)&v51,
            color: partsToDraw);
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: (const bfx::Vec3 *)&v51,
            v1: (const bfx::Vec3 *)&v51.m_data[8],
            v2: (const bfx::Vec3 *)&v51.m_data[4],
            color: partsToDraw);
        }
        if ( (a31 & 4) != 0 )
        {
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: &v53,
            v1: (const bfx::Vec3 *)&v51.m_data[12],
            v2: (const bfx::Vec3 *)&v51,
            color: partsToDraw);
          bfx::DrawSolidTri(
            pSpace: a1,
            v0: &v53,
            v1: (const bfx::Vec3 *)&v51,
            v2: (const bfx::Vec3 *)&v51.m_data[12],
            color: partsToDraw);
        }
      }
      ++v44;
      v51.m_data[12] = v51.m_data[0];
      v51.m_data[13] = v51.m_data[1];
      v51.m_data[14] = v51.m_data[2];
      v51.m_data[8] = v51.m_data[4];
      v51.m_data[9] = v51.m_data[5];
      v51.m_data[10] = v51.m_data[6];
    }
    while ( v44 < v43 );
  }
}


// ========================================================================
// ?DrawCone@bfx@@YAXPBVSpace@1@ABVMatrix@1@MMHABVColor@1@@Z
// EA  : 0x8324A528
// RVA : 0x0124A528
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCone(
        const bfx::Space *a1,
        bfx::Vec3 *a2,
        long double radius,
        int numSegs,
        const bfx::Color *color,
        int a6,
        const bfx::Color *a7)
{
  double v8; // fp31
  int v10; // r29
  int v12; // r27
  double v13; // fp29
  double v14; // fp28
  double v15; // fp30
  __int64 v16; // r10
  __int64 v17; // r11
  double v18; // fp26
  int v19; // r28
  float *v20; // r31
  float *v21; // r30
  int v22; // r26
  double v23; // fp25
  long double v24; // fp2
  double v25; // fp24
  long double v26; // fp2
  double v27; // fp0
  double v28; // fp13
  double v29; // fp12
  bfx::Vec3 v30; // [sp+58h] [-6C8h] BYREF
  bfx::Matrix v31[25]; // [sp+68h] [-6B8h] BYREF

  v8 = *((double *)&radius + 1);
  v10 = a6;
  if ( a6 >= 3 )
  {
    if ( a6 >= 32 )
      v10 = 32;
  }
  else
  {
    v10 = 3;
  }
  v12 = 0;
  v13 = (float)(a2[4].m_x + (float)(a2[2].m_z * (float)*(double *)&radius));
  v14 = (float)(a2[4].m_y + (float)(a2[3].m_x * (float)*(double *)&radius));
  v15 = (float)(a2[4].m_z + (float)(a2[3].m_y * (float)*(double *)&radius));
  if ( v10 > 0 )
  {
    LODWORD(v16) = v10;
    HIDWORD(v16) = 3 * v10;
    v18 = (float)v16;
    HIDWORD(v17) = 24 * v10;
    v19 = -1;
    v20 = &v31[0].m_data[6 * v10 + 5];
    v21 = &v31[0].m_data[2];
    do
    {
      LODWORD(v17) = v12;
      v22 = v19;
      if ( v19 < 0 )
        v22 = 2 * v10 - 1;
      v23 = (float)((float)((float)v17 * 6.2831855) / (float)v18);
      *(double *)&radius = v23;
      v24 = sin(x: radius);
      v25 = (float)*(double *)&v24;
      *(double *)&v24 = v23;
      v26 = cos(x: v24);
      v30.m_z = 0.0;
      v30.m_y = (float)v25 * (float)v8;
      v30.m_x = (float)*(double *)&v26 * (float)v8;
      bfx::Matrix::operator*(this: v31, result: a2, rhs: &v30);
      HIDWORD(v17) = &v31[0].m_data[6];
      v27 = v31[0].m_data[0];
      v28 = v31[0].m_data[1];
      v21[4] = v31[0].m_data[0];
      ++v12;
      v21[5] = v28;
      v29 = v31[0].m_data[2];
      v19 += 2;
      LODWORD(v17) = &v31[0].m_data[3 * v22 + 6];
      v21 += 6;
      *v21 = v31[0].m_data[2];
      *(float *)v17 = v27;
      *(float *)(v17 + 4) = v28;
      *(float *)(v17 + 8) = v29;
      v20[1] = v27;
      v20[2] = v28;
      v20[3] = v29;
      v20[4] = v13;
      v20[5] = v14;
      v20 += 6;
      *v20 = v15;
    }
    while ( v12 < v10 );
  }
  bfx::DrawLineList(pSpace: a1, pVerts: (bfx::Vec3 *)&v31[0].m_data[6], numVerts: 4 * v10, color: a7);
}


// ========================================================================
// ?DrawSolidCone@bfx@@YAXPBVSpace@1@ABVMatrix@1@MMABVColor@1@@Z
// EA  : 0x8324A6E8
// RVA : 0x0124A6E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawSolidCone(
        bfx::Vector3 *pSpace,
        bfx::Vec3 *mat,
        double height,
        double radius,
        const bfx::Color *color,
        int a6,
        const bfx::Color *a7)
{
  double v7; // fp12
  double v8; // fp10
  double v9; // fp9
  double m_x; // fp8
  double m_y; // fp7
  double m_z; // fp6
  __int64 v17; // r11
  long double v18; // fp2
  int v19; // r30
  double v20; // fp28
  long double v21; // fp2
  double v22; // fp27
  long double v23; // fp2
  bfx::Matrix v24; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v25; // [sp+98h] [-68h] BYREF

  v7 = (float)(mat[2].m_z * (float)height);
  v8 = (float)(mat[3].m_x * (float)height);
  v9 = (float)(mat[3].m_y * (float)height);
  m_x = mat[4].m_x;
  m_y = mat[4].m_y;
  m_z = mat[4].m_z;
  v24.m_data[12] = radius;
  v24.m_data[13] = 0.0;
  v24.m_data[14] = 0.0;
  v24.m_data[8] = (float)m_x + (float)v7;
  v24.m_data[9] = (float)m_y + (float)v8;
  v24.m_data[10] = (float)m_z + (float)v9;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v24.m_data[4], result: mat, rhs: (const bfx::Vec3 *)&v24.m_data[12]);
  v19 = 1;
  do
  {
    LODWORD(v17) = v19;
    v20 = (float)((float)v17 * (float)0.78539819);
    *(double *)&v18 = v20;
    v21 = sin(x: v18);
    v22 = (float)*(double *)&v21;
    *(double *)&v21 = v20;
    v23 = cos(x: v21);
    v25.m_z = 0.0;
    v25.m_y = (float)v22 * (float)radius;
    v25.m_x = (float)*(double *)&v23 * (float)radius;
    bfx::Matrix::operator*(this: &v24, result: mat, rhs: &v25);
    bfx::DrawSolidTri(
      pSpace,
      v0: (const bfx::Vec3 *)&v24.m_data[4],
      v1: (const bfx::Vec3 *)&v24,
      v2: (const bfx::Vec3 *)&v24.m_data[8],
      color: a7);
    bfx::DrawSolidTri(
      pSpace,
      v0: (const bfx::Vec3 *)&v24,
      v1: (const bfx::Vec3 *)&v24.m_data[4],
      v2: (const bfx::Vec3 *)&v24.m_data[8],
      color: a7);
    ++v19;
    v24.m_data[4] = v24.m_data[0];
    v24.m_data[5] = v24.m_data[1];
    v24.m_data[6] = v24.m_data[2];
  }
  while ( v19 <= 8 );
}


// ========================================================================
// ?DrawArrowhead@bfx@@YAXPBVSpace@1@ABVVec3@1@1ABVColor@1@@Z
// EA  : 0x8324A830
// RVA : 0x0124A830
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawArrowhead(
        bfx::Vector3 *pSpace,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::Color *color)
{
  double v6; // fp12
  double v8; // fp11
  double v9; // fp0
  double m_z; // fp13
  double v13; // fp7
  int v14; // r6
  const bfx::Color *v15; // r5
  bfx::Vec3 v16; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v17; // [sp+60h] [-80h] BYREF
  bfx::Matrix v18; // [sp+70h] [-70h] BYREF

  v6 = (float)(endPos->m_z - startPos->m_z);
  v8 = (float)(endPos->m_y - startPos->m_y);
  v9 = __fsqrts((float)((float)((float)v8 * (float)v8)
                      + (float)((float)((float)v6 * (float)v6)
                              + (float)((float)(endPos->m_x - startPos->m_x) * (float)(endPos->m_x - startPos->m_x)))));
  if ( v9 > 1.0842022e-19 )
  {
    v16.m_x = (float)((float)1.0 / (float)v9) * (float)(endPos->m_x - startPos->m_x);
    v16.m_y = (float)((float)1.0 / (float)v9) * (float)v8;
    v16.m_z = (float)((float)1.0 / (float)v9) * (float)v6;
    _FP12 = (float)(bfx::GetScale() - (float)((float)v9 * (float)0.25));
    m_z = endPos->m_z;
    __asm { fsel      f31, f12, f31, f1 }
    v13 = (float)(endPos->m_y - (float)(v16.m_y * (float)_FP31));
    v17.m_x = endPos->m_x - (float)(v16.m_x * (float)_FP31);
    v17.m_y = v13;
    v17.m_z = (float)m_z - (float)(v16.m_z * (float)_FP31);
    bfx::BuildMatAroundAxis(result: &v18, zaxis: &v16, pos: &v17);
    bfx::DrawSolidCone(
      pSpace,
      mat: (bfx::Vec3 *)&v18,
      height: _FP31,
      radius: (float)((float)_FP31 * (float)0.15000001),
      color: v15,
      a6: v14,
      a7: color);
  }
}


// ========================================================================
// ?DrawCachedPrims@bfx@@YAXXZ
// EA  : 0x8324AB00
// RVA : 0x0124AB00
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCachedPrims(bfx *this)
{
  bfx::Array<bfx::QueuedTri> **m_pRendererManager; // r31
  const bfx::Array<bfx::QueuedLine> *v2; // r3
  bfx::Array<bfx::QueuedTri> *v3; // r11
  bfx::Array<bfx::QueuedTri> *v4; // r29
  int v5; // r30
  int v6; // r28
  bfx::Array<bfx::QueuedString> *v7; // r31
  bfx *v8; // r3

  m_pRendererManager = (bfx::Array<bfx::QueuedTri> **)bfx::g_pCurInstance->m_pRendererManager;
  if ( *m_pRendererManager != nullptr )
  {
    v2 = (const bfx::Array<bfx::QueuedLine> *)m_pRendererManager[28];
    if ( v2 != nullptr )
    {
      bfx::DrawQueuedLines(inputLines: v2);
      bfx::Array<bfx::HoleRecord>::clear(this: m_pRendererManager[28]);
      bfx::DrawQueuedTris(inputTris: m_pRendererManager[28] + 1);
      bfx::Array<bfx::HoleRecord>::clear(this: m_pRendererManager[28] + 1);
      bfx::DrawQueuedLines(inputLines: (const bfx::Array<bfx::QueuedLine> *)&m_pRendererManager[28][2]);
      bfx::Array<bfx::HoleRecord>::clear(this: m_pRendererManager[28] + 2);
      bfx::DrawQueuedTris(inputTris: m_pRendererManager[28] + 3);
      bfx::Array<bfx::HoleRecord>::clear(this: m_pRendererManager[28] + 3);
      v3 = m_pRendererManager[28];
      v4 = v3 + 4;
      v5 = 0;
      if ( v3[4].m_size > 0 )
      {
        v6 = 0;
        do
        {
          ((void (__fastcall *)(bfx::Array<bfx::QueuedTri> *, bfx::Color *, int, _DWORD))LODWORD((*m_pRendererManager)->m_data->m_v0.m_z))(
            a1: *m_pRendererManager,
            a2: &ColorWhite_0,
            a3: (int)v4->m_data + v6,
            a4: *(_DWORD *)((char *)&v4->m_data->m_v1.m_x + v6));
          ++v5;
          v6 += 16;
        }
        while ( v5 < v4->m_size );
      }
      v7 = (bfx::Array<bfx::QueuedString> *)&m_pRendererManager[28][4];
      bfx::Array<bfx::QueuedString>::shrink(this: v7, size: 0);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7->m_data);
      v7->m_data = nullptr;
      v7->m_cap = 0;
      bfx::DrawQDraw(this: v8);
    }
  }
}


// ========================================================================
// ?DrawString@bfx@@YAXPBVSpace@1@ABVVec3@1@PADZZ
// EA  : 0x8324AC28
// RVA : 0x0124AC28
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void bfx::DrawString(
        bfx::Vector3 *pSpace,
        const bfx::Vec3 *inputPos,
        __int64 fmt,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        ...)
{
  bfx::RendererManager *m_pRendererManager; // r30
  float m_y; // r8
  float m_z; // r7
  const bfx::String *v18; // r29
  bfx::Space *v19; // r3
  const bfx::QueuedString *v20; // r3
  bfx::Renderer_vtbl *v21; // r29
  bfx::Space *v22; // r3
  bfx::String v23; // [sp+50h] [-470h] BYREF
  bfx::Vec3 v24; // [sp+58h] [-468h] BYREF
  bfx::Space v25[5]; // [sp+68h] [-458h] BYREF
  __int64 v26; // [sp+4E8h] [+28h] BYREF
  va_list va; // [sp+4E8h] [+28h]
  __int64 v28; // [sp+4F0h] [+30h]
  __int64 v29; // [sp+4F8h] [+38h]
  __int64 v30; // [sp+500h] [+40h]
  __int64 v31; // [sp+508h] [+48h]
  va_list va1; // [sp+510h] [+50h] BYREF

  va_start(va1, a13);
  va_start(va, a13);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v26 = fmt;
  v28 = *(__int64 *)((char *)&a4 + 4);
  v29 = a4;
  v30 = *(__int64 *)((char *)&a5 + 4);
  v31 = a5;
  m_pRendererManager = bfx::g_pCurInstance->m_pRendererManager;
  if ( m_pRendererManager->m_pRenderer != nullptr && m_pRendererManager->m_pQueuedData != nullptr )
  {
    va_copy(v23.m_data, va);
    vsprintf(string: (char *)&v25[0].m_rotWorldToSpace, format: (const char *)HIDWORD(fmt), ap: va);
    m_y = inputPos->m_y;
    m_z = inputPos->m_z;
    v24.m_x = inputPos->m_x;
    v24.m_y = m_y;
    v24.m_z = m_z;
    if ( bfx::g_pCurInstance->m_pRendererManager->m_pActiveQueuedRenderer != nullptr
      || m_pRendererManager->m_renderingScene )
    {
      v21 = m_pRendererManager->m_pRenderer->__vftable;
      v22 = bfx::Space::TransformSpaceToWorld(this: v25, result: pSpace, posIn: &v24);
      v21->DrawString(
        this: m_pRendererManager->m_pRenderer,
        a2: &ColorWhite_0,
        a3: (const bfx::Vector3 *)v22,
        a4: (const char *)&v25[0].m_rotWorldToSpace);
    }
    else
    {
      v18 = bfx::String::String(this: &v23, data: (const char *)&v25[0].m_rotWorldToSpace);
      v19 = bfx::Space::TransformSpaceToWorld(this: v25, result: pSpace, posIn: &v24);
      v20 = bfx::QueuedString::QueuedString(
              this: (bfx::QueuedString *)&v25[0].m_rotSpaceToWorld,
              v0: (const bfx::Vector3 *)v19,
              string: v18);
      bfx::Array<bfx::QueuedString>::push_back(this: &m_pRendererManager->m_pQueuedData->m_deferredStrings, val: v20);
      if ( LODWORD(v25[0].m_rotSpaceToWorld.m_z) != 0 )
        bfx::MemoryManager::Free(
          this: bfx::g_pCurInstance->m_pMemoryManager,
          ptr: (void *)LODWORD(v25[0].m_rotSpaceToWorld.m_z));
      if ( v23.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v23.m_data);
    }
  }
}


// ========================================================================
// __unwind$78586
// EA  : 0x8324AD84
// RVA : 0x0124AD84
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void _unwind_78586()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 1216 + 80));
}


// ========================================================================
// __unwind$78587
// EA  : 0x8324ADAC
// RVA : 0x0124ADAC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void _unwind_78587()
{
  int v0; // r12

  bfx::QueuedString::~QueuedString(this: (bfx::QueuedString *)(v0 - 1216 + 128));
}


// ========================================================================
// ?DrawAxes@bfx@@YAXPBVSpace@1@ABVVec3@1@@Z
// EA  : 0x8324ADD8
// RVA : 0x0124ADD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawAxes(const bfx::Space *pSpace, const bfx::Vec3 *pos)
{
  double Scale; // fp1
  double m_y; // fp13
  double v6; // fp12
  double m_z; // fp11
  double v8; // fp1
  double m_x; // fp9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp1
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  bfx::Vec3 v17; // [sp+50h] [-70h] BYREF
  float v18; // [sp+5Ch] [-64h]
  float v19; // [sp+60h] [-60h]
  float v20; // [sp+64h] [-5Ch]
  bfx::Vec3 v21; // [sp+70h] [-50h] BYREF
  float v22; // [sp+7Ch] [-44h]
  float v23; // [sp+80h] [-40h]
  float v24; // [sp+84h] [-3Ch]
  bfx::Vec3 v25; // [sp+90h] [-30h] BYREF
  float v26; // [sp+9Ch] [-24h]
  float v27; // [sp+A0h] [-20h]
  float v28; // [sp+A4h] [-1Ch]

  Scale = bfx::GetScale();
  m_y = pos->m_y;
  v6 = (float)(pos->m_x + (float)Scale);
  m_z = pos->m_z;
  v17.m_x = pos->m_x;
  v17.m_y = m_y;
  v17.m_z = m_z;
  v19 = m_y;
  v20 = m_z;
  v18 = v6;
  bfx::DrawLineList(pSpace, pVerts: &v17, numVerts: 2, color: &ColorRed_0);
  v8 = bfx::GetScale();
  m_x = pos->m_x;
  v10 = (float)(pos->m_y + (float)v8);
  v11 = pos->m_z;
  v21.m_y = pos->m_y;
  v21.m_x = m_x;
  v21.m_z = v11;
  v22 = m_x;
  v24 = v11;
  v23 = v10;
  bfx::DrawLineList(pSpace, pVerts: &v21, numVerts: 2, color: &ColorGreen_0);
  v12 = bfx::GetScale();
  v13 = pos->m_z;
  v14 = pos->m_x;
  v15 = (float)(pos->m_z + (float)v12);
  v16 = pos->m_y;
  v25.m_y = pos->m_y;
  v25.m_x = v14;
  v25.m_z = v13;
  v26 = v14;
  v27 = v16;
  v28 = v15;
  bfx::DrawLineList(pSpace, pVerts: &v25, numVerts: 2, color: &ColorBlue_0);
}


// ========================================================================
// ?DrawCross@bfx@@YAXPBVSpace@1@ABVVec3@1@MABVColor@1@@Z
// EA  : 0x8324AED8
// RVA : 0x0124AED8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCross(
        const bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        double radius,
        const bfx::Color *color,
        const bfx::Color *a5)
{
  double m_y; // fp13
  double m_z; // fp11
  double v8; // fp10
  double m_x; // fp8
  double v13; // fp6
  double v14; // fp5
  double v15; // fp3
  double v16; // fp2
  double v17; // fp1
  double v18; // fp0
  bfx::Vec3 v19; // [sp+50h] [-80h] BYREF
  float v20; // [sp+5Ch] [-74h]
  float v21; // [sp+60h] [-70h]
  float v22; // [sp+64h] [-6Ch]
  bfx::Vec3 v23; // [sp+70h] [-60h] BYREF
  float v24; // [sp+7Ch] [-54h]
  float v25; // [sp+80h] [-50h]
  float v26; // [sp+84h] [-4Ch]
  bfx::Vec3 v27; // [sp+90h] [-40h] BYREF
  float v28; // [sp+9Ch] [-34h]
  float v29; // [sp+A0h] [-30h]
  float v30; // [sp+A4h] [-2Ch]

  m_y = pos->m_y;
  m_z = pos->m_z;
  v8 = (float)(pos->m_x - (float)radius);
  v20 = pos->m_x + (float)radius;
  v21 = m_y;
  v22 = m_z;
  v19.m_x = v8;
  v19.m_y = m_y;
  v19.m_z = m_z;
  bfx::DrawLineList(pSpace, pVerts: &v19, numVerts: 2, color: a5);
  m_x = pos->m_x;
  v13 = pos->m_z;
  v14 = (float)(pos->m_y - (float)radius);
  v25 = pos->m_y + (float)radius;
  v24 = m_x;
  v26 = v13;
  v23.m_x = m_x;
  v23.m_y = v14;
  v23.m_z = v13;
  bfx::DrawLineList(pSpace, pVerts: &v23, numVerts: 2, color: a5);
  v15 = pos->m_x;
  v16 = (float)(pos->m_z + (float)radius);
  v17 = pos->m_y;
  v18 = (float)(pos->m_z - (float)radius);
  v29 = pos->m_y;
  v28 = v15;
  v30 = v16;
  v27.m_x = v15;
  v27.m_y = v17;
  v27.m_z = v18;
  bfx::DrawLineList(pSpace, pVerts: &v27, numVerts: 2, color: a5);
}


// ========================================================================
// ?DrawConvexVolume@bfx@@YAXPBVSpace@1@PBVPlane@1@HW4NormalsSpec@1@ABVColor@1@@Z
// EA  : 0x8324AFC0
// RVA : 0x0124AFC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawConvexVolume(
        const bfx::Space *pSpace,
        const bfx::Plane *pPlanes,
        int numPlanes,
        bfx::NormalsSpec normalsSpec,
        const bfx::Color *color)
{
  int v10; // r24
  const bfx::Plane *v11; // r21
  int v12; // r22
  int v13; // r27
  const bfx::Plane *v14; // r25
  char v15; // r29
  int v16; // r30
  float *p_m_z; // r31
  float v18; // r10
  float v19; // r9
  float v20; // r11
  bfx::Plane v21; // [sp+60h] [-F0h] BYREF
  bfx::Line v22; // [sp+70h] [-E0h] BYREF
  bfx::Vec3 v23; // [sp+90h] [-C0h] BYREF
  float v24; // [sp+9Ch] [-B4h]
  float v25; // [sp+A0h] [-B0h]
  float v26; // [sp+A4h] [-ACh]
  bfx::LineSegParameterized v27; // [sp+B0h] [-A0h] BYREF

  v10 = 0;
  if ( numPlanes > 0 )
  {
    v11 = pPlanes;
    do
    {
      v12 = v10 + 1;
      v13 = v10 + 1;
      if ( v10 + 1 < numPlanes )
      {
        v14 = v11 + 1;
        do
        {
          if ( bfx::IntersectTwoPlanes(plane1: v11, plane2: v14, lineOut: &v22) )
          {
            v27.m_minS = -3.4028235e38;
            v27.m_maxS = 3.4028235e38;
            v15 = 1;
            v16 = 0;
            v27.m_pos.m_x = v22.m_pos.m_x;
            p_m_z = &pPlanes->m_normal.m_z;
            v27.m_pos.m_y = v22.m_pos.m_y;
            v27.m_pos.m_z = v22.m_pos.m_z;
            v27.m_dir = v22.m_dir;
            do
            {
              if ( v16 != v10 && v16 != v13 )
              {
                if ( normalsSpec == OUTWARD_PLANE_NORMALS )
                {
                  v18 = *(p_m_z - 2) * (float)-1.0;
                  v19 = *(p_m_z - 1) * (float)-1.0;
                  v20 = *p_m_z * (float)-1.0;
                  v21.m_d = p_m_z[1] * (float)-1.0;
                  v21.m_normal.m_z = v20;
                  v21.m_normal.m_y = v19;
                  v21.m_normal.m_x = v18;
                  v15 &= bfx::ClipLineSegParameterizedAgainstPlane(plane: &v21, seg: &v27);
                }
                else
                {
                  v15 &= bfx::ClipLineSegParameterizedAgainstPlane(plane: (const bfx::Plane *)(p_m_z - 2), seg: &v27);
                }
              }
              ++v16;
              p_m_z += 4;
            }
            while ( v16 < numPlanes );
            if ( v15 != 0 )
            {
              v23.m_x = (float)(v27.m_dir.m_x * v27.m_minS) + v27.m_pos.m_x;
              v24 = v27.m_pos.m_x + (float)(v27.m_dir.m_x * v27.m_maxS);
              v25 = v27.m_pos.m_y + (float)(v27.m_dir.m_y * v27.m_maxS);
              v26 = v27.m_pos.m_z + (float)(v27.m_dir.m_z * v27.m_maxS);
              v23.m_y = (float)(v27.m_dir.m_y * v27.m_minS) + v27.m_pos.m_y;
              v23.m_z = (float)(v27.m_dir.m_z * v27.m_minS) + v27.m_pos.m_z;
              bfx::DrawLineList(pSpace, pVerts: &v23, numVerts: 2, color);
            }
          }
          ++v13;
          ++v14;
        }
        while ( v13 < numPlanes );
      }
      ++v10;
      ++v11;
    }
    while ( v12 < numPlanes );
  }
}


// ========================================================================
// ?DrawBox@bfx@@YAXPBVSpace@1@ABVMatrix@1@ABVBox@1@ABVColor@1@@Z
// EA  : 0x8324B1D8
// RVA : 0x0124B1D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawBox(
        const bfx::Space *pSpace,
        bfx::Vec3 *mat,
        const bfx::Box *boxLCoord,
        const bfx::Color *color)
{
  int v8; // r31
  float *v9; // r29
  const bfx::Box *p_m_max; // r11
  double m_z; // fp13
  const bfx::Box *v12; // r11
  double m_y; // fp0
  const bfx::Box *v14; // r11
  bfx::Vec3 *v15; // r3
  double v16; // fp10
  double v17; // fp9
  double v18; // fp31
  double v19; // fp30
  double v20; // fp29
  double v21; // fp28
  double v22; // fp27
  double v23; // fp26
  double v24; // fp25
  double v25; // fp24
  double v26; // fp23
  double v27; // fp22
  double v28; // fp21
  double v29; // fp20
  double v30; // fp19
  double v31; // fp18
  double v32; // fp17
  double v33; // fp31
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  double v37; // fp27
  double v38; // fp26
  double v39; // fp25
  double v40; // fp24
  double v41; // fp23
  bfx::Vec3 v42; // [sp+50h] [-2B0h] BYREF
  bfx::Vec3 v43; // [sp+60h] [-2A0h] BYREF
  float v44; // [sp+6Ch] [-294h]
  float v45; // [sp+70h] [-290h]
  float v46; // [sp+74h] [-28Ch]
  bfx::Vec3 v47; // [sp+80h] [-280h] BYREF
  float v48; // [sp+8Ch] [-274h]
  float v49; // [sp+90h] [-270h]
  float v50; // [sp+94h] [-26Ch]
  bfx::Vec3 v51; // [sp+A0h] [-260h] BYREF
  float v52; // [sp+ACh] [-254h]
  float v53; // [sp+B0h] [-250h]
  float v54; // [sp+B4h] [-24Ch]
  bfx::Vec3 v55; // [sp+C0h] [-240h] BYREF
  float v56; // [sp+CCh] [-234h]
  float v57; // [sp+D0h] [-230h]
  float v58; // [sp+D4h] [-22Ch]
  bfx::Vec3 v59; // [sp+E0h] [-220h] BYREF
  float v60; // [sp+ECh] [-214h]
  float v61; // [sp+F0h] [-210h]
  float v62; // [sp+F4h] [-20Ch]
  bfx::Vec3 v63; // [sp+100h] [-200h] BYREF
  float v64; // [sp+10Ch] [-1F4h]
  float v65; // [sp+110h] [-1F0h]
  float v66; // [sp+114h] [-1ECh]
  bfx::Vec3 v67; // [sp+120h] [-1E0h] BYREF
  float v68; // [sp+12Ch] [-1D4h]
  float v69; // [sp+130h] [-1D0h]
  float v70; // [sp+134h] [-1CCh]
  bfx::Vec3 v71; // [sp+140h] [-1C0h] BYREF
  float v72; // [sp+14Ch] [-1B4h]
  float v73; // [sp+150h] [-1B0h]
  float v74; // [sp+154h] [-1ACh]
  bfx::Vec3 v75; // [sp+160h] [-1A0h] BYREF
  float v76; // [sp+16Ch] [-194h]
  float v77; // [sp+170h] [-190h]
  float v78; // [sp+174h] [-18Ch]
  bfx::Vec3 v79; // [sp+180h] [-180h] BYREF
  float v80; // [sp+18Ch] [-174h]
  float v81; // [sp+190h] [-170h]
  float v82; // [sp+194h] [-16Ch]
  bfx::Vec3 v83; // [sp+1A0h] [-160h] BYREF
  float v84; // [sp+1ACh] [-154h]
  float v85; // [sp+1B0h] [-150h]
  float v86; // [sp+1B4h] [-14Ch]
  bfx::Vec3 v87; // [sp+1C0h] [-140h] BYREF
  float v88; // [sp+1CCh] [-134h]
  float v89; // [sp+1D0h] [-130h]
  float v90; // [sp+1D4h] [-12Ch]
  int v91; // [sp+1DCh] [-124h] BYREF
  float v92; // [sp+1E0h] [-120h]
  float v93; // [sp+1E4h] [-11Ch]
  float v94; // [sp+1E8h] [-118h]
  float v95; // [sp+1ECh] [-114h]
  float v96; // [sp+1F0h] [-110h]
  float v97; // [sp+1F4h] [-10Ch]
  float v98; // [sp+1F8h] [-108h]
  float v99; // [sp+1FCh] [-104h]
  float v100; // [sp+200h] [-100h]
  float v101; // [sp+204h] [-FCh]
  float v102; // [sp+208h] [-F8h]
  float v103; // [sp+20Ch] [-F4h]
  float v104; // [sp+210h] [-F0h]
  float v105; // [sp+214h] [-ECh]
  float v106; // [sp+218h] [-E8h]
  float v107; // [sp+21Ch] [-E4h]
  float v108; // [sp+220h] [-E0h]
  float v109; // [sp+224h] [-DCh]
  float v110; // [sp+228h] [-D8h]
  float v111; // [sp+22Ch] [-D4h]
  float v112; // [sp+230h] [-D0h]
  float v113; // [sp+234h] [-CCh]
  float v114; // [sp+238h] [-C8h]
  float v115; // [sp+23Ch] [-C4h]
  bfx::Matrix v116[2]; // [sp+240h] [-C0h] BYREF

  v8 = 0;
  v9 = (float *)&v91;
  do
  {
    p_m_max = boxLCoord;
    if ( (v8 & 1) != 0 )
      p_m_max = (const bfx::Box *)&boxLCoord->m_max;
    m_z = p_m_max->m_min.m_z;
    v12 = boxLCoord;
    if ( (unsigned int)v8 >> 1 != 2 * ((unsigned int)v8 >> 2) )
      v12 = (const bfx::Box *)&boxLCoord->m_max;
    m_y = v12->m_min.m_y;
    v14 = boxLCoord;
    if ( (v8 & 0xFFFFFFFC) != 0 )
      v14 = (const bfx::Box *)&boxLCoord->m_max;
    v42.m_x = v14->m_min.m_x;
    v42.m_y = m_y;
    v42.m_z = m_z;
    v15 = bfx::Matrix::operator*(this: v116, result: mat, rhs: &v42);
    ++v8;
    v16 = v15->m_y;
    v17 = v15->m_z;
    v9[1] = v15->m_x;
    v9[2] = v16;
    v9 += 3;
    *v9 = v17;
  }
  while ( v8 < 8 );
  v18 = v92;
  v19 = v93;
  v20 = v94;
  v21 = v104;
  v22 = v105;
  v23 = v106;
  v51.m_x = v92;
  v51.m_y = v93;
  v51.m_z = v94;
  v52 = v104;
  v53 = v105;
  v54 = v106;
  bfx::DrawLineList(pSpace, pVerts: &v51, numVerts: 2, color);
  v24 = v110;
  v25 = v111;
  v26 = v112;
  v75.m_x = v21;
  v75.m_y = v22;
  v75.m_z = v23;
  v76 = v110;
  v77 = v111;
  v78 = v112;
  bfx::DrawLineList(pSpace, pVerts: &v75, numVerts: 2, color);
  v27 = v98;
  v28 = v99;
  v29 = v100;
  v59.m_x = v24;
  v59.m_y = v25;
  v59.m_z = v26;
  v60 = v98;
  v61 = v99;
  v62 = v100;
  bfx::DrawLineList(pSpace, pVerts: &v59, numVerts: 2, color);
  v83.m_x = v27;
  v83.m_y = v28;
  v83.m_z = v29;
  v84 = v18;
  v85 = v19;
  v86 = v20;
  bfx::DrawLineList(pSpace, pVerts: &v83, numVerts: 2, color);
  v30 = v95;
  v31 = v96;
  v32 = v97;
  v67.m_x = v18;
  v67.m_y = v19;
  v67.m_z = v20;
  v68 = v95;
  v69 = v96;
  v70 = v97;
  bfx::DrawLineList(pSpace, pVerts: &v67, numVerts: 2, color);
  v33 = v107;
  v34 = v108;
  v35 = v109;
  v43.m_x = v21;
  v43.m_y = v22;
  v43.m_z = v23;
  v44 = v107;
  v45 = v108;
  v46 = v109;
  bfx::DrawLineList(pSpace, pVerts: &v43, numVerts: 2, color);
  v36 = v113;
  v37 = v114;
  v38 = v115;
  v47.m_x = v24;
  v47.m_y = v25;
  v47.m_z = v26;
  v48 = v113;
  v49 = v114;
  v50 = v115;
  bfx::DrawLineList(pSpace, pVerts: &v47, numVerts: 2, color);
  v39 = v101;
  v40 = v102;
  v41 = v103;
  v55.m_x = v27;
  v55.m_y = v28;
  v55.m_z = v29;
  v56 = v101;
  v57 = v102;
  v58 = v103;
  bfx::DrawLineList(pSpace, pVerts: &v55, numVerts: 2, color);
  v63.m_x = v30;
  v63.m_y = v31;
  v63.m_z = v32;
  v64 = v33;
  v65 = v34;
  v66 = v35;
  bfx::DrawLineList(pSpace, pVerts: &v63, numVerts: 2, color);
  v71.m_x = v33;
  v71.m_y = v34;
  v71.m_z = v35;
  v72 = v36;
  v73 = v37;
  v74 = v38;
  bfx::DrawLineList(pSpace, pVerts: &v71, numVerts: 2, color);
  v79.m_x = v36;
  v79.m_y = v37;
  v79.m_z = v38;
  v80 = v39;
  v81 = v40;
  v82 = v41;
  bfx::DrawLineList(pSpace, pVerts: &v79, numVerts: 2, color);
  v87.m_x = v39;
  v87.m_y = v40;
  v87.m_z = v41;
  v88 = v30;
  v89 = v31;
  v90 = v32;
  bfx::DrawLineList(pSpace, pVerts: &v87, numVerts: 2, color);
}


// ========================================================================
// ?DrawCircle@bfx@@YAXPBVSpace@1@ABVMatrix@1@MABVColor@1@@Z
// EA  : 0x8324B520
// RVA : 0x0124B520
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCircle(
        const bfx::Space *pSpace,
        bfx::Vec3 *mat,
        double radius,
        const bfx::Color *color,
        const bfx::Color *a5)
{
  __int64 v9; // r11
  long double v10; // fp2
  int v11; // r31
  double v12; // fp28
  long double v13; // fp2
  double v14; // fp27
  long double v15; // fp2
  bfx::Matrix v16; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v17; // [sp+A0h] [-70h] BYREF
  float v18; // [sp+ACh] [-64h]
  float v19; // [sp+B0h] [-60h]
  float v20; // [sp+B4h] [-5Ch]

  v16.m_data[8] = radius;
  v16.m_data[9] = 0.0;
  v16.m_data[10] = 0.0;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v16.m_data[4], result: mat, rhs: (const bfx::Vec3 *)&v16.m_data[8]);
  v11 = 1;
  do
  {
    LODWORD(v9) = v11;
    v12 = (float)((float)v9 * (float)0.39269909);
    *(double *)&v10 = v12;
    v13 = sin(x: v10);
    v14 = (float)*(double *)&v13;
    *(double *)&v13 = v12;
    v15 = cos(x: v13);
    v16.m_data[14] = 0.0;
    v16.m_data[13] = (float)v14 * (float)radius;
    v16.m_data[12] = (float)*(double *)&v15 * (float)radius;
    bfx::Matrix::operator*(this: &v16, result: mat, rhs: (const bfx::Vec3 *)&v16.m_data[12]);
    v17.m_x = v16.m_data[4];
    v17.m_y = v16.m_data[5];
    v17.m_z = v16.m_data[6];
    v18 = v16.m_data[0];
    v19 = v16.m_data[1];
    v20 = v16.m_data[2];
    bfx::DrawLineList(pSpace, pVerts: &v17, numVerts: 2, color: a5);
    ++v11;
    *((double *)&v10 + 1) = v16.m_data[0];
    v16.m_data[4] = v16.m_data[0];
    v16.m_data[5] = v16.m_data[1];
    v16.m_data[6] = v16.m_data[2];
  }
  while ( v11 <= 16 );
}


// ========================================================================
// ?DrawCircle@bfx@@YAXPBVSpace@1@ABVVec3@1@1MABVColor@1@@Z
// EA  : 0x8324B640
// RVA : 0x0124B640
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCircle(
        const bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *N,
        double radius,
        const bfx::Color *color,
        const bfx::Color *a6)
{
  bfx::Vec3 *v9; // r3
  const bfx::Color *v10; // r5
  bfx::Matrix v11; // [sp+50h] [-60h] BYREF

  v9 = (bfx::Vec3 *)bfx::BuildMatAroundAxis(result: &v11, zaxis: N, pos);
  bfx::DrawCircle(pSpace, mat: v9, radius, color: v10, a5: a6);
}


// ========================================================================
// ?DrawCapsule2d@bfx@@YAXPBVSpace@1@ABVLineSeg@1@MABVVec3@1@ABVColor@1@@Z
// EA  : 0x8324B6A8
// RVA : 0x0124B6A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawCapsule2d(
        const bfx::Space *pSpace,
        const bfx::LineSeg *seg,
        double radius,
        const bfx::Vec3 *N,
        const bfx::Color *color,
        const bfx::Color *a6)
{
  double v7; // fp12
  double v8; // fp9
  double v9; // fp6
  bfx::Vec3 *p_m_v1; // r30
  double m_r; // fp5
  double m_g; // fp4
  double m_b; // fp3
  double v18; // fp0
  double v19; // fp7
  double v20; // fp6
  double v21; // fp5
  __int64 v24; // r11
  long double v25; // fp2
  int v26; // r31
  double v27; // fp29
  double v28; // fp28
  double v29; // fp27
  double v30; // fp25
  long double v31; // fp2
  double v32; // fp24
  long double v33; // fp2
  double m_y; // fp13
  int v35; // r31
  double m_z; // fp12
  double v37; // fp24
  long double v38; // fp2
  double v39; // fp23
  long double v40; // fp2
  bfx::Matrix v41; // [sp+60h] [-1B0h] BYREF
  bfx::Vec3 v42; // [sp+A0h] [-170h] BYREF
  bfx::Vec3 v43; // [sp+B0h] [-160h] BYREF
  bfx::Vec3 v44; // [sp+C0h] [-150h] BYREF
  bfx::Vec3 v45; // [sp+D0h] [-140h] BYREF
  bfx::Vec3 v46; // [sp+E0h] [-130h] BYREF
  bfx::Vec3 v47; // [sp+F0h] [-120h] BYREF
  float v48; // [sp+FCh] [-114h]
  float v49; // [sp+100h] [-110h]
  float v50; // [sp+104h] [-10Ch]
  bfx::Vec3 v51; // [sp+110h] [-100h] BYREF
  float v52; // [sp+11Ch] [-F4h]
  float v53; // [sp+120h] [-F0h]
  float v54; // [sp+124h] [-ECh]
  bfx::Vec3 v55; // [sp+130h] [-E0h] BYREF
  float v56; // [sp+13Ch] [-D4h]
  float v57; // [sp+140h] [-D0h]
  float v58; // [sp+144h] [-CCh]
  bfx::Matrix v59[2]; // [sp+150h] [-C0h] BYREF

  v7 = (float)(seg->m_v1.m_z - seg->m_v0.m_z);
  v8 = (float)(seg->m_v1.m_y - seg->m_v0.m_y);
  v9 = (float)(seg->m_v1.m_x - seg->m_v0.m_x);
  p_m_v1 = &seg->m_v1;
  m_r = color->m_r;
  m_g = color->m_g;
  m_b = color->m_b;
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v9 * (float)v9)
                                       + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f8, f7, f30 }
  v18 = (float)((float)(seg->m_v1.m_z - seg->m_v0.m_z) * (float)_FP2);
  v46.m_z = (float)(seg->m_v1.m_z - seg->m_v0.m_z) * (float)_FP2;
  v46.m_x = (float)_FP2 * (float)v9;
  v46.m_y = (float)v8 * (float)_FP2;
  v19 = (float)((float)((float)m_b * v46.m_x) - (float)((float)m_r * (float)v18));
  v20 = (float)((float)((float)m_r * v46.m_y) - (float)((float)m_g * v46.m_x));
  v21 = (float)((float)((float)m_g * (float)v18) - (float)((float)m_b * v46.m_y));
  _FP11 = (float)((float)__fsqrts((float)((float)((float)v21 * (float)v21)
                                        + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))))
                - (float)1.0842022e-19);
  __asm { fsel      f9, f11, f10, f30 }
  v43.m_x = (float)((float)((float)m_g * (float)v18) - (float)((float)m_b * v46.m_y)) * (float)_FP9;
  v43.m_y = (float)v19 * (float)_FP9;
  v43.m_z = (float)v20 * (float)_FP9;
  v41.m_data[14] = (float)(v43.m_y * v46.m_x) - (float)(v46.m_y * v43.m_x);
  v41.m_data[12] = (float)(v43.m_z * v46.m_y) - (float)(v43.m_y * (float)v18);
  v41.m_data[13] = (float)((float)v18 * v43.m_x) - (float)(v43.m_z * v46.m_x);
  bfx::Matrix::Build(this: v59, xAxis: &v46, yAxis: &v43, zAxis: (const bfx::Vec3 *)&v41.m_data[12], trans: &seg->m_v0);
  v45.m_x = 0.0;
  v45.m_y = radius;
  v45.m_z = 0.0;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v41.m_data[8], result: (bfx::Vec3 *)v59, rhs: &v45);
  v26 = 1;
  v27 = v41.m_data[8];
  v28 = v41.m_data[9];
  v29 = v41.m_data[10];
  do
  {
    LODWORD(v24) = v26;
    v30 = (float)((float)((float)v24 * (float)0.39269909) + 1.5707964);
    *(double *)&v25 = v30;
    v31 = sin(x: v25);
    v32 = (float)*(double *)&v31;
    *(double *)&v31 = v30;
    v33 = cos(x: v31);
    v44.m_z = 0.0;
    v44.m_y = (float)v32 * (float)radius;
    v44.m_x = (float)*(double *)&v33 * (float)radius;
    bfx::Matrix::operator*(this: &v41, result: (bfx::Vec3 *)v59, rhs: &v44);
    v47.m_x = v27;
    v47.m_y = v28;
    v47.m_z = v29;
    v48 = v41.m_data[0];
    v49 = v41.m_data[1];
    v50 = v41.m_data[2];
    bfx::DrawLineList(pSpace, pVerts: &v47, numVerts: 2, color: a6);
    ++v26;
    v27 = v41.m_data[0];
    v28 = v41.m_data[1];
    v29 = v41.m_data[2];
  }
  while ( v26 <= 8 );
  m_y = p_m_v1->m_y;
  v35 = 0;
  m_z = p_m_v1->m_z;
  v59[0].m_data[12] = p_m_v1->m_x;
  v59[0].m_data[13] = m_y;
  v59[0].m_data[14] = m_z;
  do
  {
    LODWORD(v24) = v35;
    v37 = (float)((float)((float)v24 * (float)0.39269909) + (float)4.712389);
    *(double *)&v25 = v37;
    v38 = sin(x: v25);
    v39 = (float)*(double *)&v38;
    *(double *)&v38 = v37;
    v40 = cos(x: v38);
    v42.m_z = 0.0;
    v42.m_y = (float)v39 * (float)radius;
    v42.m_x = (float)*(double *)&v40 * (float)radius;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v41.m_data[4], result: (bfx::Vec3 *)v59, rhs: &v42);
    v55.m_x = v27;
    v55.m_y = v28;
    v55.m_z = v29;
    v56 = v41.m_data[4];
    v57 = v41.m_data[5];
    v58 = v41.m_data[6];
    bfx::DrawLineList(pSpace, pVerts: &v55, numVerts: 2, color: a6);
    ++v35;
    v27 = v41.m_data[4];
    v28 = v41.m_data[5];
    v29 = v41.m_data[6];
  }
  while ( v35 <= 8 );
  v51.m_x = v41.m_data[4];
  v51.m_y = v41.m_data[5];
  v51.m_z = v41.m_data[6];
  v52 = v41.m_data[8];
  v53 = v41.m_data[9];
  v54 = v41.m_data[10];
  bfx::DrawLineList(pSpace, pVerts: &v51, numVerts: 2, color: a6);
}


// ========================================================================
// ?DrawSphere@bfx@@YAXPBVSpace@1@ABVMatrix@1@MABVColor@1@@Z
// EA  : 0x8324B9E0
// RVA : 0x0124B9E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::DrawSphere(
        const bfx::Space *pSpace,
        bfx::Vec3 *mat,
        double radius,
        const bfx::Color *color,
        const bfx::Color *a5)
{
  __int64 v6; // r11
  int i; // r27
  double v11; // fp29
  long double v12; // fp2
  long double v13; // fp2
  double v14; // fp30
  long double v15; // fp2
  double v16; // fp29
  int v17; // r31
  double v18; // fp26
  long double v19; // fp2
  long double v20; // fp2
  double v21; // fp25
  long double v22; // fp2
  double v23; // fp24
  long double v24; // fp2
  const bfx::Color *v25; // r5
  bfx::Matrix v26; // [sp+60h] [-D0h] BYREF
  bfx::Vec3 v27; // [sp+A0h] [-90h] BYREF
  float v28; // [sp+ACh] [-84h]
  float v29; // [sp+B0h] [-80h]
  float v30; // [sp+B4h] [-7Ch]

  HIDWORD(v6) = &unk_82410000;
  for ( i = 1; i <= 16; ++i )
  {
    LODWORD(v6) = i;
    v11 = (float)((float)v6 * (float)0.39269909);
    *(double *)&v12 = v11;
    v13 = cos(x: v12);
    v14 = (float)*(double *)&v13;
    *(double *)&v13 = v11;
    v15 = sin(x: v13);
    v16 = (float)*(double *)&v15;
    v26.m_data[10] = 0.0;
    v26.m_data[8] = (float)v14 * (float)radius;
    v26.m_data[9] = (float)*(double *)&v15 * (float)radius;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v26.m_data[4], result: mat, rhs: (const bfx::Vec3 *)&v26.m_data[8]);
    v17 = 1;
    do
    {
      LODWORD(v6) = v17;
      v18 = (float)((float)v6 * (float)0.39269909);
      *(double *)&v19 = v18;
      v20 = sin(x: v19);
      v21 = (float)*(double *)&v20;
      *(double *)&v20 = v18;
      v22 = cos(x: v20);
      v23 = (float)*(double *)&v22;
      *(double *)&v22 = v18;
      v24 = cos(x: v22);
      v26.m_data[14] = (float)v21 * (float)radius;
      v26.m_data[13] = (float)((float)v23 * (float)v16) * (float)radius;
      v26.m_data[12] = (float)((float)*(double *)&v24 * (float)v14) * (float)radius;
      bfx::Matrix::operator*(this: &v26, result: mat, rhs: (const bfx::Vec3 *)&v26.m_data[12]);
      v27.m_x = v26.m_data[4];
      v27.m_y = v26.m_data[5];
      v27.m_z = v26.m_data[6];
      v28 = v26.m_data[0];
      v29 = v26.m_data[1];
      v30 = v26.m_data[2];
      bfx::DrawLineList(pSpace, pVerts: &v27, numVerts: 2, color: a5);
      ++v17;
      v26.m_data[4] = v26.m_data[0];
      v26.m_data[5] = v26.m_data[1];
      v26.m_data[6] = v26.m_data[2];
    }
    while ( v17 <= 16 );
  }
  bfx::DrawCircle(pSpace, mat, radius, color: v25, a5);
}


// ========================================================================
// ?DrawSphere@bfx@@YAXPBVSpace@1@ABVSphere@1@ABVColor@1@@Z
// EA  : 0x8324BB78
// RVA : 0x0124BB78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawSphere(const bfx::Space *pSpace, const bfx::Sphere *sphere, const bfx::Color *color)
{
  double m_radius; // fp31
  bfx::Vec3 *UpPosMatrix; // r3
  const bfx::Color *v7; // r5
  bfx::Matrix v8; // [sp+50h] [-60h] BYREF

  m_radius = sphere->m_radius;
  UpPosMatrix = (bfx::Vec3 *)bfx::GetUpPosMatrix(result: &v8, pos: &sphere->m_pos);
  bfx::DrawSphere(pSpace, mat: UpPosMatrix, radius: m_radius, color: v7, a5: color);
}


// ========================================================================
// ?DrawArrow@bfx@@YAXPBVSpace@1@ABVVec3@1@1ABVColor@1@@Z
// EA  : 0x8324BBD8
// RVA : 0x0124BBD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawArrow(
        bfx::Vector3 *pSpace,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::Color *color)
{
  double m_y; // fp13
  double m_z; // fp12
  double m_x; // fp11
  double v11; // fp10
  double v12; // fp9
  bfx::Vec3 v13; // [sp+50h] [-40h] BYREF
  float v14; // [sp+5Ch] [-34h]
  float v15; // [sp+60h] [-30h]
  float v16; // [sp+64h] [-2Ch]

  bfx::DrawArrowhead(pSpace, startPos, endPos, color);
  m_y = startPos->m_y;
  m_z = startPos->m_z;
  m_x = endPos->m_x;
  v11 = endPos->m_y;
  v12 = endPos->m_z;
  v13.m_x = startPos->m_x;
  v13.m_y = m_y;
  v13.m_z = m_z;
  v14 = m_x;
  v15 = v11;
  v16 = v12;
  bfx::DrawLineList((const bfx::Space *)pSpace, pVerts: &v13, numVerts: 2, color);
}


// ========================================================================
// ?DrawAxesWithArrows@bfx@@YAXPBVSpace@1@ABVVec3@1@@Z
// EA  : 0x8324BC48
// RVA : 0x0124BC48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::DrawAxesWithArrows(bfx::Vector3 *pSpace, const bfx::Vec3 *pos)
{
  double Scale; // fp1
  double m_y; // fp31
  double v6; // fp29
  double m_z; // fp30
  double m_x; // fp13
  double v9; // fp12
  double v10; // fp11
  double v11; // fp1
  double v12; // fp31
  double v13; // fp29
  double v14; // fp30
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp1
  double v19; // fp31
  double v20; // fp29
  double v21; // fp30
  double v22; // fp4
  double v23; // fp3
  bfx::Vec3 v24; // [sp+50h] [-A0h] BYREF
  bfx::Vec3 v25; // [sp+60h] [-90h] BYREF
  float v26; // [sp+6Ch] [-84h]
  float v27; // [sp+70h] [-80h]
  float v28; // [sp+74h] [-7Ch]
  bfx::Vec3 v29; // [sp+80h] [-70h] BYREF
  float v30; // [sp+8Ch] [-64h]
  float v31; // [sp+90h] [-60h]
  float v32; // [sp+94h] [-5Ch]
  bfx::Vec3 v33; // [sp+A0h] [-50h] BYREF
  float v34; // [sp+ACh] [-44h]
  float v35; // [sp+B0h] [-40h]
  float v36; // [sp+B4h] [-3Ch]

  Scale = bfx::GetScale();
  m_y = pos->m_y;
  v6 = (float)(pos->m_x + (float)Scale);
  m_z = pos->m_z;
  v24.m_y = pos->m_y;
  v24.m_x = v6;
  v24.m_z = m_z;
  bfx::DrawArrowhead(pSpace, startPos: pos, endPos: &v24, color: &ColorRed_0);
  m_x = pos->m_x;
  v9 = pos->m_y;
  v10 = pos->m_z;
  v26 = v6;
  v27 = m_y;
  v28 = m_z;
  v25.m_x = m_x;
  v25.m_y = v9;
  v25.m_z = v10;
  bfx::DrawLineList((const bfx::Space *)pSpace, pVerts: &v25, numVerts: 2, color: &ColorRed_0);
  v11 = bfx::GetScale();
  v12 = pos->m_x;
  v13 = (float)(pos->m_y + (float)v11);
  v14 = pos->m_z;
  v24.m_x = pos->m_x;
  v24.m_y = v13;
  v24.m_z = v14;
  bfx::DrawArrowhead(pSpace, startPos: pos, endPos: &v24, color: &ColorGreen_0);
  v15 = pos->m_x;
  v16 = pos->m_y;
  v17 = pos->m_z;
  v30 = v12;
  v31 = v13;
  v32 = v14;
  v29.m_x = v15;
  v29.m_y = v16;
  v29.m_z = v17;
  bfx::DrawLineList((const bfx::Space *)pSpace, pVerts: &v29, numVerts: 2, color: &ColorGreen_0);
  v18 = bfx::GetScale();
  v19 = pos->m_x;
  v20 = (float)(pos->m_z + (float)v18);
  v21 = pos->m_y;
  v24.m_x = pos->m_x;
  v24.m_z = v20;
  v24.m_y = v21;
  bfx::DrawArrowhead(pSpace, startPos: pos, endPos: &v24, color: &ColorBlue_0);
  v34 = v19;
  v35 = v21;
  v36 = v20;
  v22 = pos->m_y;
  v23 = pos->m_z;
  v33.m_x = pos->m_x;
  v33.m_y = v22;
  v33.m_z = v23;
  bfx::DrawLineList((const bfx::Space *)pSpace, pVerts: &v33, numVerts: 2, color: &ColorBlue_0);
}


// ========================================================================
// bfx::`dynamic initializer for 'dummyBoolForInit''
// EA  : 0x83398058
// RVA : 0x01398058
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.cpp
// ========================================================================

void __fastcall bfx::_dynamic_initializer_for__dummyBoolForInit__(long double a1)
{
  bfx::CalcCosSin(pCosVals: bfx::cosVals, pSinVals: bfx::sinVals, numVals: 16, a4: a1);
  dummyBoolForInit = true;
}

