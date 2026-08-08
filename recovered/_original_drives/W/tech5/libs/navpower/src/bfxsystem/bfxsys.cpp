
// ========================================================================
// ?CalcRandFromSeed@bfx@@YAII@Z
// EA  : 0x8323D070
// RVA : 0x0123D070
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

unsigned int __fastcall bfx::CalcRandFromSeed(__int16 seedNum)
{
  return (unsigned __int16)(6532 - 12271 * seedNum);
}


// ========================================================================
// ?GetScale@bfx@@YAMXZ
// EA  : 0x8323D080
// RVA : 0x0123D080
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

float __fastcall bfx::GetScale()
{
  bfx::SystemParams *m_pSystemParams; // r10
  double m_scaleDist; // fp1

  if ( bfx::g_pCurInstance != nullptr && (m_pSystemParams = bfx::g_pCurInstance->m_pSystemParams) != nullptr )
    m_scaleDist = m_pSystemParams->m_scaleDist;
  else
    m_scaleDist = INVALID_SYSTEM_PARAMS.m_scaleDist;
  return *((float *)&m_scaleDist + 1);
}


// ========================================================================
// ?GetUpAxis@bfx@@YA?AW4UpAxis@1@XZ
// EA  : 0x8323D0B8
// RVA : 0x0123D0B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::UpAxis __fastcall bfx::GetUpAxis()
{
  bfx::SystemParams *m_pSystemParams; // r10

  if ( bfx::g_pCurInstance != nullptr && (m_pSystemParams = bfx::g_pCurInstance->m_pSystemParams) != nullptr )
    return m_pSystemParams->m_upAxis;
  else
    return INVALID_SYSTEM_PARAMS.m_upAxis;
}


// ========================================================================
// ?GetUpPosMatrix@bfx@@YA?AVMatrix@1@ABVVec3@1@@Z
// EA  : 0x8323D0F0
// RVA : 0x0123D0F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::GetUpPosMatrix(bfx::Matrix *result, const bfx::Vec3 *pos)
{
  bfx::SystemParams *m_pSystemParams; // r11

  if ( bfx::g_pCurInstance != nullptr && bfx::g_pCurInstance->m_pSystemParams != nullptr )
    m_pSystemParams = bfx::g_pCurInstance->m_pSystemParams;
  else
    m_pSystemParams = &INVALID_SYSTEM_PARAMS;
  bfx::GetUpMatrix(result, upAxis: m_pSystemParams->m_upAxis);
  bfx::Matrix::Trans(this: result, offset: pos);
  return result;
}


// ========================================================================
// ?GetUpVec@bfx@@YA?AVVec3@1@XZ
// EA  : 0x8323D170
// RVA : 0x0123D170
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetUpVec(bfx::Vec3 *result)
{
  const bfx::Vec3 *CachedSize; // r3
  float m_y; // r9
  float m_z; // r8

  CachedSize = idreports::MapWarning::GetCachedSize(this: bfx::g_pCurInstance);
  m_y = CachedSize->m_y;
  m_z = CachedSize->m_z;
  result->m_x = CachedSize->m_x;
  result->m_y = m_y;
  result->m_z = m_z;
  return result;
}


// ========================================================================
// ?GetHorizontalReferenceVec@bfx@@YA?AVVec3@1@XZ
// EA  : 0x8323D1C0
// RVA : 0x0123D1C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetHorizontalReferenceVec(bfx::Vec3 *result)
{
  const bfx::Vec3 *HorizontalReferenceVec; // r3
  float m_y; // r9
  float m_z; // r8

  HorizontalReferenceVec = bfx::SystemInstance::GetHorizontalReferenceVec(this: bfx::g_pCurInstance);
  m_y = HorizontalReferenceVec->m_y;
  m_z = HorizontalReferenceVec->m_z;
  result->m_x = HorizontalReferenceVec->m_x;
  result->m_y = m_y;
  result->m_z = m_z;
  return result;
}


// ========================================================================
// ?ConnectToTask@HandleProxy@bfx@@QAAXXZ
// EA  : 0x8323D210
// RVA : 0x0123D210
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::HandleProxy::ConnectToTask(bfx::HandleProxy *this)
{
  int v1; // r11
  int v2; // r10

  v1 = *((_DWORD *)this + 1);
  if ( (char)v1 >> 4 != 0 )
  {
    if ( (char)v1 >> 4 != 2 )
      goto LABEL_6;
    v2 = 3;
  }
  else
  {
    v2 = 1;
  }
  *((_DWORD *)this + 1) = (16 * v2) & 0xF0 | v1 & 0xFFFFFF0F;
LABEL_6:
  if ( (*((_DWORD *)this + 1) & 0xC) == 0 )
    *((_DWORD *)this + 1) = (unsigned __int8)*((_DWORD *)this + 1)
                          | ((*((_DWORD *)this + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
}


// ========================================================================
// ?ConnectToTarget@HandleProxy@bfx@@QAAXPAVHandleTargetBase@2@@Z
// EA  : 0x8323D260
// RVA : 0x0123D260
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::HandleProxy::ConnectToTarget(bfx::HandleProxy *this, bfx::HandleTargetBase *pTarget)
{
  unsigned int v2; // r11

  if ( this->m_pTarget == nullptr )
  {
    if ( pTarget != nullptr )
    {
      this->m_pTarget = pTarget;
      pTarget->m_pProxy = this;
      v2 = *((_DWORD *)this + 1) & 0xFFFFFF0F | 0x20;
      *((_DWORD *)this + 1) = v2;
      if ( (v2 & 0xC) == 0 )
        *((_DWORD *)this + 1) = (unsigned __int8)v2 | ((v2 & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    }
    else
    {
      *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF0F | 0x20;
    }
  }
}


// ========================================================================
// ?WriteString@bfx@@YAXPAVLogDevice@1@PBD@Z
// EA  : 0x8323D2C0
// RVA : 0x0123D2C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::WriteString(bfx::LogDevice *pLog, const char *str)
{
  int v3; // r10

  do
    v3 = *(unsigned __int8 *)str++;
  while ( v3 != 0 );
  ((void (__fastcall *)(bfx::LogDevice *))pLog->WriteBuf)(a1: pLog);
}


// ========================================================================
// ?GetPlatformName@bfx@@YAPBDXZ
// EA  : 0x8323D2F0
// RVA : 0x0123D2F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

const char *__fastcall bfx::GetPlatformName()
{
  return "Xbox360";
}


// ========================================================================
// ??0Pool@bfx@@QAA@IIW4bfxMemTag@1@@Z
// EA  : 0x8323D300
// RVA : 0x0123D300
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Pool *__fastcall bfx::Pool::Pool(
        bfx::Pool *this,
        unsigned int nodeSize,
        unsigned int numNodes,
        bfx::bfxMemTag tag)
{
  this->m_data.m_nodeSize = nodeSize;
  this->m_data.m_numNodesPerBlock = numNodes;
  this->m_data.m_tag = tag;
  this->m_data.m_pHead = nullptr;
  this->m_data.m_pUnused = nullptr;
  this->m_data.m_numBlocksAllocated = 0;
  return this;
}


// ========================================================================
// ?AllocBlock@Pool@bfx@@CAPAUBlockHeader@12@IIW4bfxMemTag@2@@Z
// EA  : 0x8323D320
// RVA : 0x0123D320
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Pool::BlockHeader *__fastcall bfx::Pool::AllocBlock(
        unsigned int nodeSize,
        unsigned int numNodes,
        bfx::bfxMemTag tag)
{
  bfx::Pool::BlockHeader *result; // r3
  bfx::Pool::BlockHeader *v6; // r11
  int v7; // ctr

  result = (bfx::Pool::BlockHeader *)bfx::MemoryManager::Malloc(
                                       this: bfx::g_pCurInstance->m_pMemoryManager,
                                       size: nodeSize * numNodes + 4,
                                       tag);
  v6 = result + 1;
  result->m_pNext = nullptr;
  if ( numNodes != 1 )
  {
    v7 = numNodes - 1;
    do
    {
      v6->m_pNext = (bfx::Pool::BlockHeader *)((char *)v6 + nodeSize);
      v6 = (bfx::Pool::BlockHeader *)((char *)v6 + nodeSize);
      --v7;
    }
    while ( v7 != 0 );
  }
  v6->m_pNext = nullptr;
  return result;
}


// ========================================================================
// ??1Pool@bfx@@QAA@XZ
// EA  : 0x8323D398
// RVA : 0x0123D398
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::Pool::~Pool(bfx::Pool *this)
{
  bfx::Pool::BlockHeader *m_pHead; // r4
  bfx::Pool::BlockHeader *m_pNext; // r31

  m_pHead = this->m_data.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pHead);
      m_pHead = m_pNext;
      --this->m_data.m_numBlocksAllocated;
    }
    while ( m_pNext != nullptr );
  }
  this->m_data.m_pHead = nullptr;
}


// ========================================================================
// ?Print@bfx@@YAXPBDZZ
// EA  : 0x8323D3F0
// RVA : 0x0123D3F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void bfx::Print(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  char v8[1032]; // [sp+60h] [-410h] BYREF
  __int64 v9; // [sp+488h] [+18h] BYREF
  va_list va; // [sp+488h] [+18h]
  __int64 v11; // [sp+490h] [+20h]
  __int64 v12; // [sp+498h] [+28h]
  __int64 v13; // [sp+4A0h] [+30h]
  __int64 v14; // [sp+4A8h] [+38h]
  __int64 v15; // [sp+4B0h] [+40h]
  __int64 v16; // [sp+4B8h] [+48h]
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
  v9 = fmt;
  v11 = *(__int64 *)((char *)&a2 + 4);
  v12 = a2;
  v13 = *(__int64 *)((char *)&a3 + 4);
  v14 = a3;
  v15 = *(__int64 *)((char *)&a4 + 4);
  v16 = a4;
  vsprintf(string: v8, format: (const char *)HIDWORD(fmt), ap: va);
  printf(format: v8);
}


// ========================================================================
// ?DisconnectFromTask@HandleProxy@bfx@@QAAXXZ
// EA  : 0x8323D500
// RVA : 0x0123D500
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::HandleProxy::DisconnectFromTask(bfx::HandleProxy *this)
{
  if ( (*((_DWORD *)this + 1) & 0xC) == 0 )
    bfx::HandleProxy::RemRefToHandleProxy(this);
}


// ========================================================================
// ?InternalWarning@bfx@@YAXPADZZ
// EA  : 0x8323D518
// RVA : 0x0123D518
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void bfx::InternalWarning(__int64 fmt, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7, int a8, ...)
{
  __int64 v8; // r8
  __int64 v9; // r6
  char *v10; // r11
  int v11; // r9
  __int64 v12; // r4
  int v13; // [sp+8h] [-478h]
  int v14; // [sp+Ch] [-474h]
  int v15; // [sp+10h] [-470h]
  int v16; // [sp+14h] [-46Ch]
  char v17[1032]; // [sp+70h] [-410h] BYREF
  __int64 v18; // [sp+498h] [+18h] BYREF
  va_list va; // [sp+498h] [+18h]
  __int64 v20; // [sp+4A0h] [+20h]
  __int64 v21; // [sp+4A8h] [+28h]
  __int64 v22; // [sp+4B0h] [+30h]
  __int64 v23; // [sp+4B8h] [+38h]
  __int64 v24; // [sp+4C0h] [+40h]
  __int64 v25; // [sp+4C8h] [+48h]
  va_list va1; // [sp+4D0h] [+50h] BYREF

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
  v18 = fmt;
  v20 = *(__int64 *)((char *)&a2 + 4);
  v21 = a2;
  v22 = *(__int64 *)((char *)&a3 + 4);
  v23 = a3;
  v24 = *(__int64 *)((char *)&a4 + 4);
  v25 = a4;
  vsprintf(string: v17, format: (const char *)HIDWORD(fmt), ap: va);
  if ( bfx::g_pCurInstance != nullptr )
  {
    if ( bfx::g_pCurInstance->m_pWarningLog != nullptr )
    {
      v10 = v17;
      do
        v11 = (unsigned __int8)*v10++;
      while ( v11 != 0 );
      bfx::g_pCurInstance->m_pWarningLog->WriteBuf(this: bfx::g_pCurInstance->m_pWarningLog, a2: v17, a3: v10 - v17 - 1);
    }
  }
  else
  {
    LODWORD(v12) = v17;
    HIDWORD(v12) = "%s";
    bfx::Print(
      fmt: v12,
      a2: v9,
      a3: v8,
      a4: __SPAIR64__(&_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861, 0),
      a5: v13,
      a6: v14,
      a7: v15,
      a8: v16);
  }
}


// ========================================================================
// ?LimitWarn@bfx@@YAMMMMPBD@Z
// EA  : 0x8323D5E8
// RVA : 0x0123D5E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

float __fastcall bfx::LimitWarn(
        double val,
        double min,
        double max,
        const char *name,
        int a5,
        int a6,
        unsigned int a7,
        __int64 a8,
        __int64 a9)
{
  int v12; // [sp+8h] [-88h]
  int v13; // [sp+Ch] [-84h]
  int v14; // [sp+10h] [-80h]
  int v15; // [sp+14h] [-7Ch]

  HIDWORD(a8) = a7;
  if ( val >= min )
  {
    if ( val > max )
    {
      bfx::InternalWarning(
        fmt: __SPAIR64__("%s's value of %1.2f is above the maximum value of %1.2f.  Modifying %s.\n", a7),
        a2: __SPAIR64__(LODWORD(val), LODWORD(max)),
        a3: a8,
        a4: a9,
        a5: v12,
        a6: v13,
        a7: v14,
        a8: v15);
      val = max;
    }
  }
  else
  {
    bfx::InternalWarning(
      fmt: __SPAIR64__("%s's value of %1.2f is below the minimum value of %1.2f.  Modifying %s.\n", a7),
      a2: __SPAIR64__(LODWORD(val), LODWORD(min)),
      a3: a8,
      a4: a9,
      a5: v12,
      a6: v13,
      a7: v14,
      a8: v15);
    val = min;
  }
  return *((float *)&val + 1);
}


// ========================================================================
// ?LimitWarn@bfx@@YA?AVVec3@1@ABV21@MMPBD@Z
// EA  : 0x8323D680
// RVA : 0x0123D680
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::LimitWarn(
        bfx::Vec3 *result,
        const bfx::Vec3 *vec,
        double min,
        double max,
        const char *name,
        int a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v11; // r30
  bfx::Vec3 *v12; // r31
  int v13; // r25
  int i; // r29
  double v15; // fp1
  int v17; // [sp+8h] [-C8h]
  int v18; // [sp+Ch] [-C4h]
  int v19; // [sp+10h] [-C0h]
  int v20; // [sp+14h] [-BCh]

  LODWORD(a8) = &unk_82410000;
  v11 = HIDWORD(a7);
  v12 = result;
  v13 = (char *)vec - (char *)result;
  for ( i = 3; i != 0; --i )
  {
    v15 = *(float *)((char *)&v12->m_x + v13);
    if ( v15 >= min )
    {
      if ( v15 > max )
      {
        HIDWORD(a7) = v11;
        bfx::InternalWarning(
          fmt: __SPAIR64__("%s's value of %1.2f is above the maximum value of %1.2f.  Modifying %s.\n", v11),
          a2: __SPAIR64__(LODWORD(v15), LODWORD(max)),
          a3: a7,
          a4: a8,
          a5: v17,
          a6: v18,
          a7: v19,
          a8: v20);
        v15 = max;
      }
    }
    else
    {
      HIDWORD(a7) = v11;
      bfx::InternalWarning(
        fmt: __SPAIR64__("%s's value of %1.2f is below the minimum value of %1.2f.  Modifying %s.\n", v11),
        a2: __SPAIR64__(LODWORD(v15), LODWORD(min)),
        a3: a7,
        a4: a8,
        a5: v17,
        a6: v18,
        a7: v19,
        a8: v20);
      v15 = min;
    }
    v12->m_x = v15;
    v12 = (bfx::Vec3 *)((char *)v12 + 4);
  }
  return result;
}


// ========================================================================
// ?EndianSwapLong@bfx@@YAXAAI@Z
// EA  : 0x8323D750
// RVA : 0x0123D750
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::EndianSwapLong(unsigned int *val)
{
  int back_chain; // [sp+0h] [-10h]

  HIBYTE(back_chain) = *val;
  BYTE1(back_chain) = BYTE2(*val);
  LOBYTE(back_chain) = HIBYTE(*val);
  BYTE2(back_chain) = BYTE1(*val);
  *val = back_chain;
}


// ========================================================================
// ?EndianSwapFloat@bfx@@YAXAAM@Z
// EA  : 0x8323D788
// RVA : 0x0123D788
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::EndianSwapFloat(float *val)
{
  char v1; // r10
  char v2; // r9

  v1 = *(_BYTE *)val;
  *(_BYTE *)val = *((_BYTE *)val + 3);
  *((_BYTE *)val + 3) = v1;
  v2 = *((_BYTE *)val + 1);
  *((_BYTE *)val + 1) = *((_BYTE *)val + 2);
  *((_BYTE *)val + 2) = v2;
}


// ========================================================================
// ?EndianSwapVec3@bfx@@YAXAAVVec3@1@@Z
// EA  : 0x8323D7B0
// RVA : 0x0123D7B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::EndianSwapVec3(bfx::Vec3 *vec)
{
  char m_x_high; // r9
  char v2; // r8
  char m_y_high; // r6
  char v4; // r4
  char m_z_high; // r10
  char v6; // r8

  m_x_high = HIBYTE(vec->m_x);
  HIBYTE(vec->m_x) = LOBYTE(vec->m_x);
  LOBYTE(vec->m_x) = m_x_high;
  v2 = BYTE1(vec->m_x);
  BYTE1(vec->m_x) = BYTE2(vec->m_x);
  BYTE2(vec->m_x) = v2;
  m_y_high = HIBYTE(vec->m_y);
  HIBYTE(vec->m_y) = LOBYTE(vec->m_y);
  LOBYTE(vec->m_y) = m_y_high;
  v4 = BYTE1(vec->m_y);
  BYTE1(vec->m_y) = BYTE2(vec->m_y);
  BYTE2(vec->m_y) = v4;
  m_z_high = HIBYTE(vec->m_z);
  HIBYTE(vec->m_z) = LOBYTE(vec->m_z);
  LOBYTE(vec->m_z) = m_z_high;
  v6 = BYTE1(vec->m_z);
  BYTE1(vec->m_z) = BYTE2(vec->m_z);
  BYTE2(vec->m_z) = v6;
}


// ========================================================================
// ?EndianSwapBox@bfx@@YAXAAVBox@1@@Z
// EA  : 0x8323D820
// RVA : 0x0123D820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::EndianSwapBox(bfx::Box *box)
{
  char m_x_high; // r8
  char v2; // r7
  char m_y_high; // r5
  char v4; // r11
  char m_z_high; // r9
  char v6; // r7
  char v7; // r5
  char v8; // r11
  char v9; // r9
  char v10; // r7
  char v11; // r5
  char v12; // r11

  m_x_high = HIBYTE(box->m_min.m_x);
  HIBYTE(box->m_min.m_x) = LOBYTE(box->m_min.m_x);
  LOBYTE(box->m_min.m_x) = m_x_high;
  v2 = BYTE1(box->m_min.m_x);
  BYTE1(box->m_min.m_x) = BYTE2(box->m_min.m_x);
  BYTE2(box->m_min.m_x) = v2;
  m_y_high = HIBYTE(box->m_min.m_y);
  HIBYTE(box->m_min.m_y) = LOBYTE(box->m_min.m_y);
  LOBYTE(box->m_min.m_y) = m_y_high;
  v4 = BYTE1(box->m_min.m_y);
  BYTE1(box->m_min.m_y) = BYTE2(box->m_min.m_y);
  BYTE2(box->m_min.m_y) = v4;
  m_z_high = HIBYTE(box->m_min.m_z);
  HIBYTE(box->m_min.m_z) = LOBYTE(box->m_min.m_z);
  LOBYTE(box->m_min.m_z) = m_z_high;
  v6 = BYTE1(box->m_min.m_z);
  BYTE1(box->m_min.m_z) = BYTE2(box->m_min.m_z);
  BYTE2(box->m_min.m_z) = v6;
  v7 = HIBYTE(box->m_max.m_x);
  HIBYTE(box->m_max.m_x) = LOBYTE(box->m_max.m_x);
  LOBYTE(box->m_max.m_x) = v7;
  v8 = BYTE1(box->m_max.m_x);
  BYTE1(box->m_max.m_x) = BYTE2(box->m_max.m_x);
  BYTE2(box->m_max.m_x) = v8;
  v9 = HIBYTE(box->m_max.m_y);
  HIBYTE(box->m_max.m_y) = LOBYTE(box->m_max.m_y);
  LOBYTE(box->m_max.m_y) = v9;
  v10 = BYTE1(box->m_max.m_y);
  BYTE1(box->m_max.m_y) = BYTE2(box->m_max.m_y);
  BYTE2(box->m_max.m_y) = v10;
  v11 = HIBYTE(box->m_max.m_z);
  HIBYTE(box->m_max.m_z) = LOBYTE(box->m_max.m_z);
  LOBYTE(box->m_max.m_z) = v11;
  v12 = BYTE1(box->m_max.m_z);
  BYTE1(box->m_max.m_z) = BYTE2(box->m_max.m_z);
  BYTE2(box->m_max.m_z) = v12;
}


// ========================================================================
// ??1HandleTargetBase@bfx@@UAA@XZ
// EA  : 0x8323D8F8
// RVA : 0x0123D8F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

void __fastcall bfx::HandleTargetBase::~HandleTargetBase(bfx::HandleTargetBase *this)
{
  bfx::HandleProxy *m_pProxy; // r3
  unsigned int v3; // r11

  m_pProxy = this->m_pProxy;
  this->__vftable = (bfx::HandleTargetBase_vtbl *)&bfx::HandleTargetBase::`vftable';
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
  {
    v3 = *((_DWORD *)m_pProxy + 1) & 0xFFFFFF0F | 0x40;
    m_pProxy->m_pTarget = nullptr;
    *((_DWORD *)m_pProxy + 1) = v3;
    if ( (v3 & 0xC) == 0 )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_STRING''
// EA  : 0x83397E98
// RVA : 0x01397E98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_STRING__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "String");
  bfx::MEM_STRING = result;
  return result;
}

