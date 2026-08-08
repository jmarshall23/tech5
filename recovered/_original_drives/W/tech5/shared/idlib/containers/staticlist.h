
// ========================================================================
// ??0?$idStaticList@UnavSplineLink_t@@$0BA@@@QAA@XZ
// EA  : 0x82592BA8
// RVA : 0x00592BA8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<navSplineLink_t,16> *__fastcall idStaticList<navSplineLink_t,16>::idStaticList<navSplineLink_t,16>(
        idStaticList<navSplineLink_t,16> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 16;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 16;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((float *)p_granularity + 2) = 0.0;
    *((_DWORD *)p_granularity + 1) = 0;
    *((_DWORD *)p_granularity + 3) = 0;
    p_granularity += 8;
    *(float *)p_granularity = 0.0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@VidSWFScriptVar@@$0BA@@@QAA@XZ
// EA  : 0x825AB3A8
// RVA : 0x005AB3A8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSWFScriptVar,16> *__fastcall idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
        idStaticList<idSWFScriptVar,16> *this)
{
  idSWFScriptVar *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 8u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idMainMenu::idSWFScriptFunction_changeTeam::Call,
    pDtor: (void (__fastcall *)(void *))idSWFScriptVar::~idSWFScriptVar);
  return this;
}


// ========================================================================
// __unwind$725645
// EA  : 0x825AB42C
// RVA : 0x005AB42C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_725645()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: *(idList<idSWFScriptVar,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UmpMapMode_t@@$0BA@@@QAA@XZ
// EA  : 0x825AB460
// RVA : 0x005AB460
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<mpMapMode_t,16> *__fastcall idStaticList<mpMapMode_t,16>::idStaticList<mpMapMode_t,16>(
        idStaticList<mpMapMode_t,16> *this)
{
  mpMapMode_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xA0u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))mpMapMode_t::mpMapMode_t,
    pDtor: (void (__fastcall *)(void *))mpMapMode_t::~mpMapMode_t);
  return this;
}


// ========================================================================
// __unwind$725665
// EA  : 0x825AB4E4
// RVA : 0x005AB4E4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_725665()
{
  int v0; // r12

  idList<mpMapMode_t,5>::~idList<mpMapMode_t,5>(this: *(idList<mpMapMode_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidStr@@$03@@QAA@XZ
// EA  : 0x82600278
// RVA : 0x00600278
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStr,4> *__fastcall idStaticList<idStr,4>::idStaticList<idStr,4>(idStaticList<idStr,4> *this)
{
  idStr *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 4;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x20u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$232118
// EA  : 0x826002FC
// RVA : 0x006002FC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_232118()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: *(idList<idStr,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidStr@@$00@@QAA@XZ
// EA  : 0x8260B5A8
// RVA : 0x0060B5A8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStr,1> *__fastcall idStaticList<idStr,1>::idStaticList<idStr,1>(idStaticList<idStr,1> *this)
{
  idStr *staticList; // r3

  this->size = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->granularity = 1;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x20u,
    count: 1,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$221891
// EA  : 0x8260B628
// RVA : 0x0060B628
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_221891()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: *(idList<idStr,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidFXRenderParm@@$0BA@@@QAA@XZ
// EA  : 0x8261D110
// RVA : 0x0061D110
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idFXRenderParm,16> *__fastcall idStaticList<idFXRenderParm,16>::idStaticList<idFXRenderParm,16>(
        idStaticList<idFXRenderParm,16> *this)
{
  int v1; // ctr
  float *v2; // r11
  idStaticList<idFXRenderParm,16> *v3; // r10

  this->size = 16;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 16;
  v2 = (float *)this;
  this->num = 0;
  this->memTag = 5;
  v3 = (idStaticList<idFXRenderParm,16> *)((char *)this - 4);
  this->listStatic = 1;
  do
  {
    v2[8] = 0.0;
    v3 = (idStaticList<idFXRenderParm,16> *)((char *)v3 + 20);
    v3->list = nullptr;
    v2[7] = 0.0;
    v2[6] = 0.0;
    v2 += 5;
    *v2 = 0.0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@VidFXRenderParm@@$0BA@@@QAA@ABV0@@Z
// EA  : 0x8261D3E8
// RVA : 0x0061D3E8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idFXRenderParm,16> *__fastcall idStaticList<idFXRenderParm,16>::idStaticList<idFXRenderParm,16>(
        idStaticList<idFXRenderParm,16> *this,
        const idStaticList<idFXRenderParm,16> *other)
{
  int v3; // ctr
  float *v4; // r10
  idStaticList<idFXRenderParm,16> *v5; // r11

  this->granularity = 1;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  v3 = 16;
  v4 = (float *)this;
  v5 = (idStaticList<idFXRenderParm,16> *)((char *)this - 4);
  do
  {
    v4[8] = 0.0;
    v5 = (idStaticList<idFXRenderParm,16> *)((char *)v5 + 20);
    v5->list = nullptr;
    v4[7] = 0.0;
    v4[6] = 0.0;
    v4 += 5;
    *v4 = 0.0;
    --v3;
  }
  while ( v3 != 0 );
  idStaticList<idFXRenderParm,16>::operator=(this, __that: other);
  return this;
}


// ========================================================================
// __unwind$223511
// EA  : 0x8261D488
// RVA : 0x0061D488
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_223511()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidDialogInfo@@$03@@QAA@XZ
// EA  : 0x82645AF0
// RVA : 0x00645AF0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idDialogInfo,4> *__fastcall idStaticList<idDialogInfo,4>::idStaticList<idDialogInfo,4>(
        idStaticList<idDialogInfo,4> *this)
{
  idDialogInfo *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 4;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x158u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idDialogInfo::idDialogInfo,
    pDtor: (void (__fastcall *)(void *))idDialogInfo::~idDialogInfo);
  return this;
}


// ========================================================================
// __unwind$238102
// EA  : 0x82645B74
// RVA : 0x00645B74
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_238102()
{
  int v0; // r12

  idList<idDialogInfo,5>::~idList<idDialogInfo,5>(this: *(idList<idDialogInfo,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidLoadScreenInfo@@$0BA@@@QAA@XZ
// EA  : 0x82645BA8
// RVA : 0x00645BA8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idLoadScreenInfo,16> *__fastcall idStaticList<idLoadScreenInfo,16>::idStaticList<idLoadScreenInfo,16>(
        idStaticList<idLoadScreenInfo,16> *this)
{
  idLoadScreenInfo *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x40u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idLoadScreenInfo::idLoadScreenInfo,
    pDtor: (void (__fastcall *)(void *))idKeyValue::~idKeyValue);
  return this;
}


// ========================================================================
// __unwind$238122
// EA  : 0x82645C2C
// RVA : 0x00645C2C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_238122()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: *(idList<idLoadScreenInfo,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@QAA@XZ
// EA  : 0x82652C88
// RVA : 0x00652C88
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStrStatic<128>,256> *__fastcall idStaticList<idStrStatic<128>,256>::idStaticList<idStrStatic<128>,256>(
        idStaticList<idStrStatic<128>,256> *this)
{
  idStrStatic<128> *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 256;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xA0u,
    count: 256,
    pCtor: (void (__fastcall *)(void *))idStrStatic<128>::idStrStatic<128>,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$227047
// EA  : 0x82652D0C
// RVA : 0x00652D0C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_227047()
{
  int v0; // r12

  idList<idStrStatic<128>,5>::Clear(this: *(idList<idStrStatic<128>,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Vusercmd_t@@$02@@QAA@XZ
// EA  : 0x8265B050
// RVA : 0x0065B050
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<usercmd_t,3> *__fastcall idStaticList<usercmd_t,3>::idStaticList<usercmd_t,3>(
        idStaticList<usercmd_t,3> *this)
{
  char v1; // r5
  char v2; // r4
  char v3; // r10

  this->num = 0;
  this->granularity = 1;
  this->listStatic = 1;
  this->size = 3;
  this->memTag = 5;
  this->list = this->staticList;
  this->staticList[0].buttons = 0;
  this->staticList[0].buttons2 = 0;
  this->staticList[0].forwardmove = 0;
  this->staticList[0].pos[2] = 0.0;
  this->staticList[0].rightmove = 0;
  this->staticList[0].pos[1] = 0.0;
  this->staticList[0].upmove = 0;
  this->staticList[0].pos[0] = 0.0;
  this->staticList[0].angles[2] = 0;
  this->staticList[1].pos[2] = 0.0;
  this->staticList[0].angles[1] = 0;
  this->staticList[1].pos[1] = 0.0;
  this->staticList[0].angles[0] = 0;
  this->staticList[1].pos[0] = 0.0;
  this->staticList[0].clientGameFrame = 0;
  this->staticList[2].pos[2] = 0.0;
  this->staticList[0].yaw = 0;
  this->staticList[2].pos[1] = 0.0;
  this->staticList[0].pitch = 0;
  this->staticList[2].pos[0] = 0.0;
  this->staticList[0].roll = 0;
  this->staticList[0].predictionStateBits = 0;
  this->staticList[0].vehicleThrottle = 0;
  this->staticList[0].serverGameTime = 0;
  this->staticList[0].fireCount = 0;
  this->staticList[0].fireAngles[1] = 0;
  this->staticList[0].fireAngles[0] = 0;
  this->staticList[0].firePos[2] = 0;
  v1 = *((_BYTE *)this->staticList + 9);
  v2 = *((_BYTE *)&this->staticList[1] + 9);
  v3 = *((_BYTE *)&this->staticList[2] + 9);
  this->staticList[0].firePos[1] = 0;
  *((_BYTE *)this->staticList + 9) = v1 & 0x3F;
  this->staticList[0].firePos[0] = 0;
  this->staticList[0].speed = 0;
  this->staticList[1].buttons = 0;
  this->staticList[1].buttons2 = 0;
  this->staticList[1].forwardmove = 0;
  this->staticList[1].rightmove = 0;
  this->staticList[1].upmove = 0;
  this->staticList[1].angles[2] = 0;
  this->staticList[1].angles[1] = 0;
  this->staticList[1].angles[0] = 0;
  this->staticList[1].clientGameFrame = 0;
  *((_BYTE *)&this->staticList[1] + 9) = v2 & 0x3F;
  this->staticList[1].yaw = 0;
  this->staticList[1].pitch = 0;
  this->staticList[1].roll = 0;
  this->staticList[1].predictionStateBits = 0;
  this->staticList[1].vehicleThrottle = 0;
  this->staticList[1].serverGameTime = 0;
  this->staticList[1].fireCount = 0;
  this->staticList[1].fireAngles[1] = 0;
  this->staticList[1].fireAngles[0] = 0;
  this->staticList[1].firePos[2] = 0;
  this->staticList[1].firePos[1] = 0;
  this->staticList[1].firePos[0] = 0;
  this->staticList[1].speed = 0;
  this->staticList[2].buttons = 0;
  this->staticList[2].buttons2 = 0;
  this->staticList[2].forwardmove = 0;
  this->staticList[2].rightmove = 0;
  this->staticList[2].upmove = 0;
  this->staticList[2].angles[2] = 0;
  this->staticList[2].angles[1] = 0;
  this->staticList[2].angles[0] = 0;
  this->staticList[2].clientGameFrame = 0;
  *((_BYTE *)&this->staticList[2] + 9) = v3 & 0x3F;
  this->staticList[2].yaw = 0;
  this->staticList[2].pitch = 0;
  this->staticList[2].roll = 0;
  this->staticList[2].predictionStateBits = 0;
  this->staticList[2].vehicleThrottle = 0;
  this->staticList[2].serverGameTime = 0;
  this->staticList[2].fireCount = 0;
  this->staticList[2].fireAngles[1] = 0;
  this->staticList[2].fireAngles[0] = 0;
  this->staticList[2].firePos[2] = 0;
  this->staticList[2].firePos[1] = 0;
  this->staticList[2].firePos[0] = 0;
  this->staticList[2].speed = 0;
  return this;
}


// ========================================================================
// ??0?$idStaticList@H$03@@QAA@ABV0@@Z
// EA  : 0x8265F3C8
// RVA : 0x0065F3C8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<int,4> *__fastcall idStaticList<int,4>::idStaticList<int,4>(
        idStaticList<int,4> *this,
        const idList<idMD6Node *,5> *other)
{
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 4;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  idList<idMaterial const *,59>::operator=((idList<idMD6Node *,5> *)this, other);
  *(idList<idMD6Node *,5> *)this->staticList = other[1];
  return this;
}


// ========================================================================
// __unwind$234996
// EA  : 0x8265F440
// RVA : 0x0065F440
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_234996()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@QAA@ABV0@@Z
// EA  : 0x82660800
// RVA : 0x00660800
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStrStatic<128>,256> *__fastcall idStaticList<idStrStatic<128>,256>::idStaticList<idStrStatic<128>,256>(
        idStaticList<idStrStatic<128>,256> *this,
        const idStaticList<idStrStatic<128>,256> *other)
{
  idStrStatic<128> *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 256;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xA0u,
    count: 256,
    pCtor: (void (__fastcall *)(void *))idStrStatic<128>::idStrStatic<128>,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  idStaticList<idStrStatic<128>,256>::operator=(this, __that: other);
  return this;
}


// ========================================================================
// __unwind$236181
// EA  : 0x8266087C
// RVA : 0x0066087C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_236181()
{
  int v0; // r12

  idList<idStrStatic<128>,5>::Clear(this: *(idList<idStrStatic<128>,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$236182
// EA  : 0x826608A4
// RVA : 0x006608A4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_236182()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 16),
    size: 0xA0u,
    count: 256,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// ??0?$idStaticList@VidScreenView@@$02@@QAA@XZ
// EA  : 0x82692FC8
// RVA : 0x00692FC8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idScreenView,3> *__fastcall idStaticList<idScreenView,3>::idStaticList<idScreenView,3>(
        idStaticList<idScreenView,3> *this)
{
  idScreenView *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 3;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x7D0u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idScreenView::idScreenView,
    pDtor: (void (__fastcall *)(void *))idScreenView::~idScreenView);
  return this;
}


// ========================================================================
// __unwind$222547
// EA  : 0x8269304C
// RVA : 0x0069304C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_222547()
{
  int v0; // r12

  idList<idScreenView,5>::Clear(this: *(idList<idScreenView,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidPlatformStreamData@@$0BA@@@QAA@XZ
// EA  : 0x82699E40
// RVA : 0x00699E40
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idPlatformStreamData,16> *__fastcall idStaticList<idPlatformStreamData,16>::idStaticList<idPlatformStreamData,16>(
        idStaticList<idPlatformStreamData,16> *this)
{
  idPlatformStreamData *staticList; // r30
  int v3; // r29

  staticList = this->staticList;
  this->granularity = 1;
  this->list = this->staticList;
  this->num = 0;
  this->size = 16;
  this->memTag = 5;
  v3 = 15;
  this->listStatic = 1;
  do
  {
    memset(Dst: staticList, Val: 0, Size: 0x10u);
    staticList->streamAlignment = 0;
    staticList->streamLength = 0;
    --v3;
    staticList->streamData = nullptr;
    ++staticList;
  }
  while ( v3 >= 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UsyncGroup_t@idAnimStack@@$03@@QAA@XZ
// EA  : 0x826F53E8
// RVA : 0x006F53E8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAnimStack::syncGroup_t,4> *__fastcall idStaticList<idAnimStack::syncGroup_t,4>::idStaticList<idAnimStack::syncGroup_t,4>(
        idStaticList<idAnimStack::syncGroup_t,4> *this)
{
  idAnimStack::syncGroup_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 4;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x9Cu,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idAnimStack::syncGroup_t::syncGroup_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$251504
// EA  : 0x826F546C
// RVA : 0x006F546C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_251504()
{
  int v0; // r12

  idList<idAnimStack::syncGroup_t,5>::Clear(this: *(idList<idAnimStack::syncGroup_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Upiece_t@idEffectPhysicsCuttable@@$07@@QAA@XZ
// EA  : 0x82703670
// RVA : 0x00703670
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idEffectPhysicsCuttable::piece_t,8> *__fastcall idStaticList<idEffectPhysicsCuttable::piece_t,8>::idStaticList<idEffectPhysicsCuttable::piece_t,8>(
        idStaticList<idEffectPhysicsCuttable::piece_t,8> *this)
{
  this->num = 0;
  this->granularity = 1;
  this->listStatic = 1;
  this->size = 8;
  this->memTag = 5;
  this->list = this->staticList;
  this->staticList[0].collision.collisionPoint = vec3_origin;
  this->staticList[0].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[0].collision.collisionSurfaceType = 0;
  this->staticList[1].collision.collisionPoint = vec3_origin;
  this->staticList[1].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[1].collision.collisionSurfaceType = 0;
  this->staticList[2].collision.collisionPoint = vec3_origin;
  this->staticList[2].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[2].collision.collisionSurfaceType = 0;
  this->staticList[3].collision.collisionPoint = vec3_origin;
  this->staticList[3].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[3].collision.collisionSurfaceType = 0;
  this->staticList[4].collision.collisionPoint = vec3_origin;
  this->staticList[4].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[4].collision.collisionSurfaceType = 0;
  this->staticList[5].collision.collisionPoint = vec3_origin;
  this->staticList[5].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[5].collision.collisionSurfaceType = 0;
  this->staticList[6].collision.collisionPoint = vec3_origin;
  this->staticList[6].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[6].collision.collisionSurfaceType = 0;
  this->staticList[7].collision.collisionPoint = vec3_origin;
  this->staticList[7].collision.collisionNormalVelocity = vec3_origin;
  this->staticList[7].collision.collisionSurfaceType = 0;
  return this;
}


// ========================================================================
// ??0?$idStaticList@UribbonEffects_t@idRibbonModelManager@@$03@@QAA@XZ
// EA  : 0x82717CD8
// RVA : 0x00717CD8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idRibbonModelManager::ribbonEffects_t,4> *__fastcall idStaticList<idRibbonModelManager::ribbonEffects_t,4>::idStaticList<idRibbonModelManager::ribbonEffects_t,4>(
        idStaticList<idRibbonModelManager::ribbonEffects_t,4> *this)
{
  idRibbonModelManager::ribbonEffects_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 4;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x54u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idRibbonModelManager::ribbonEffects_t::ribbonEffects_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$246817_0
// EA  : 0x82717D5C
// RVA : 0x00717D5C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_246817_0()
{
  int v0; // r12

  idList<idBreakableManager::breakables_t,5>::Clear(this: *(idList<idRibbonModelManager::ribbonEffects_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UweaponTrace_t@@$05@@QAA@XZ
// EA  : 0x82719058
// RVA : 0x00719058
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<weaponTrace_t,6> *__fastcall idStaticList<weaponTrace_t,6>::idStaticList<weaponTrace_t,6>(
        idStaticList<weaponTrace_t,6> *this)
{
  this->size = 6;
  this->granularity = 1;
  this->list = this->staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  this->staticList[0].attacker.value = 0x1FFF;
  this->staticList[0].projectile.value = 0x1FFF;
  this->staticList[1].attacker.value = 0x1FFF;
  this->staticList[1].projectile.value = 0x1FFF;
  this->staticList[2].attacker.value = 0x1FFF;
  this->staticList[2].projectile.value = 0x1FFF;
  this->staticList[3].attacker.value = 0x1FFF;
  this->staticList[3].projectile.value = 0x1FFF;
  this->staticList[4].attacker.value = 0x1FFF;
  this->staticList[4].projectile.value = 0x1FFF;
  this->staticList[5].attacker.value = 0x1FFF;
  this->staticList[5].projectile.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0?$idStaticList@Ubeam_t@@$0EA@@@QAA@XZ
// EA  : 0x827F7B10
// RVA : 0x007F7B10
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<beam_t,64> *__fastcall idStaticList<beam_t,64>::idStaticList<beam_t,64>(idStaticList<beam_t,64> *this)
{
  beam_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 64;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x3218u,
    count: 64,
    pCtor: (void (__fastcall *)(void *))beam_t::beam_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$232181
// EA  : 0x827F7B94
// RVA : 0x007F7B94
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_232181()
{
  int v0; // r12

  idList<beam_t,5>::Clear(this: *(idList<beam_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UtrackedEvent_t@idAnimEventHandler@@$0CA@@@QAA@XZ
// EA  : 0x8283BA98
// RVA : 0x0083BA98
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAnimEventHandler::trackedEvent_t,32> *__fastcall idStaticList<idAnimEventHandler::trackedEvent_t,32>::idStaticList<idAnimEventHandler::trackedEvent_t,32>(
        idStaticList<idAnimEventHandler::trackedEvent_t,32> *this)
{
  int v1; // ctr
  unsigned __int8 *p_memTag; // r11

  this->size = 32;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 32;
  this->num = 0;
  p_memTag = &this->memTag;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *(_DWORD *)(p_memTag + 2) = -1;
    *((_WORD *)p_memTag + 3) = -1;
    p_memTag[8] = 0;
    *(_DWORD *)(p_memTag + 10) = 0;
    *(_DWORD *)(p_memTag + 14) = 0;
    *((_WORD *)p_memTag + 9) = -1;
    p_memTag += 20;
    *(_WORD *)p_memTag = -1;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UtriggeredEvent_t@idAnimEventHandler@@$0CA@@@QAA@XZ
// EA  : 0x8283BAF8
// RVA : 0x0083BAF8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAnimEventHandler::triggeredEvent_t,32> *__fastcall idStaticList<idAnimEventHandler::triggeredEvent_t,32>::idStaticList<idAnimEventHandler::triggeredEvent_t,32>(
        idStaticList<idAnimEventHandler::triggeredEvent_t,32> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 32;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 32;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = -1;
    p_granularity[4] = -1;
    *((_BYTE *)p_granularity + 10) = 0;
    *((_DWORD *)p_granularity + 3) = 0;
    *((_DWORD *)p_granularity + 4) = 0;
    p_granularity[10] = -1;
    p_granularity[11] = -1;
    p_granularity += 12;
    *(_DWORD *)p_granularity = 0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UeventInfo_t@idAnimEventHandler@@$0EA@@@QAA@XZ
// EA  : 0x8283BB58
// RVA : 0x0083BB58
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAnimEventHandler::eventInfo_t,64> *__fastcall idStaticList<idAnimEventHandler::eventInfo_t,64>::idStaticList<idAnimEventHandler::eventInfo_t,64>(
        idStaticList<idAnimEventHandler::eventInfo_t,64> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 64;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 64;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    *((_DWORD *)p_granularity + 2) = 0;
    *((_DWORD *)p_granularity + 3) = -1;
    *((_BYTE *)p_granularity + 16) = 0;
    p_granularity[9] = 0;
    *((_DWORD *)p_granularity + 5) = 0xFFFF;
    p_granularity += 12;
    *(_BYTE *)p_granularity = 0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@VExpNode@?$idRuntimeExpression@VVarId@idUserChannelExpression@@VVarContext@2@@@$0PN@@@QAA@XZ
// EA  : 0x828650B8
// RVA : 0x008650B8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253> *__fastcall idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253>::idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253>(
        idStaticList<idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext>::ExpNode,253> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->memTag = 5;
  this->size = 253;
  this->granularity = 1;
  this->list = this->staticList;
  v1 = 253;
  this->listStatic = 1;
  this->num = 0;
  p_granularity = &this->granularity;
  do
  {
    *((float *)p_granularity + 1) = 1.0;
    *((_DWORD *)p_granularity + 2) = 0;
    *((_BYTE *)p_granularity + 12) = -1;
    *((_BYTE *)p_granularity + 13) = -1;
    *((_BYTE *)p_granularity + 14) = -1;
    *((_BYTE *)p_granularity + 15) = -1;
    p_granularity += 8;
    *(_DWORD *)p_granularity = -1;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@VidStr@@$0BA@@@QAA@XZ
// EA  : 0x828A14A0
// RVA : 0x008A14A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStr,16> *__fastcall idStaticList<idStr,16>::idStaticList<idStr,16>(idStaticList<idStr,16> *this)
{
  idStr *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x20u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$222115
// EA  : 0x828A1524
// RVA : 0x008A1524
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_222115()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: *(idList<idStr,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidStr@@$0EAA@@@QAA@XZ
// EA  : 0x8295BBE0
// RVA : 0x0095BBE0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idStr,1024> *__fastcall idStaticList<idStr,1024>::idStaticList<idStr,1024>(idStaticList<idStr,1024> *this)
{
  idStr *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 1024;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x20u,
    count: 1024,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$242503
// EA  : 0x8295BC64
// RVA : 0x0095BC64
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_242503()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: *(idList<idStr,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidSoundVoice_XAudio2@@$0GA@@@QAA@XZ
// EA  : 0x8299EA50
// RVA : 0x0099EA50
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSoundVoice_XAudio2,96> *__fastcall idStaticList<idSoundVoice_XAudio2,96>::idStaticList<idSoundVoice_XAudio2,96>(
        idStaticList<idSoundVoice_XAudio2,96> *this)
{
  idSoundVoice_XAudio2 *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 96;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x160u,
    count: 96,
    pCtor: (void (__fastcall *)(void *))idSoundVoice_XAudio2::idSoundVoice_XAudio2,
    pDtor: (void (__fastcall *)(void *))idSoundVoice_XAudio2::~idSoundVoice_XAudio2);
  return this;
}


// ========================================================================
// __unwind$226395
// EA  : 0x8299EAD4
// RVA : 0x0099EAD4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_226395()
{
  int v0; // r12

  idList<idSoundVoice_XAudio2,5>::Clear(this: *(idList<idSoundVoice_XAudio2,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UmigrationInvite_t@idLobby@@$05@@QAA@XZ
// EA  : 0x829AA098
// RVA : 0x009AA098
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idLobby::migrationInvite_t,6> *__fastcall idStaticList<idLobby::migrationInvite_t,6>::idStaticList<idLobby::migrationInvite_t,6>(
        idStaticList<idLobby::migrationInvite_t,6> *this)
{
  int v1; // r28
  idLobby::migrationInvite_t *staticList; // r30

  v1 = 5;
  this->granularity = 1;
  this->num = 0;
  staticList = this->staticList;
  this->memTag = 5;
  this->size = 6;
  this->list = this->staticList;
  this->listStatic = 1;
  do
  {
    lobbyAddress_t::lobbyAddress_t(this: &staticList->address);
    staticList->userId.localUserHandle.handle = 0;
    staticList->userId.lobbyType = -1;
    --v1;
    staticList->lastInviteTime = -1;
    staticList->pingMs = 0;
    staticList->migrationGameData = -1;
    ++staticList;
  }
  while ( v1 >= 0 );
  return this;
}


// ========================================================================
// __unwind$231274
// EA  : 0x829AA118
// RVA : 0x009AA118
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_231274()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// ??0?$idStaticList@UlobbyConnectInfo_t@@$0BJ@@@QAA@XZ
// EA  : 0x829AA140
// RVA : 0x009AA140
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<lobbyConnectInfo_t,25> *__fastcall idStaticList<lobbyConnectInfo_t,25>::idStaticList<lobbyConnectInfo_t,25>(
        idStaticList<lobbyConnectInfo_t,25> *this)
{
  lobbyConnectInfo_t *staticList; // r30
  int v3; // r29

  staticList = this->staticList;
  this->granularity = 1;
  this->list = this->staticList;
  this->num = 0;
  this->size = 25;
  this->memTag = 5;
  v3 = 24;
  this->listStatic = 1;
  do
  {
    memset(Dst: staticList, Val: 0, Size: 0x3Cu);
    staticList->netAddr.type = NA_BAD;
    *(_DWORD *)staticList->netAddr.ip = 0;
    --v3;
    *(_DWORD *)&staticList->netAddr.port = 0;
    ++staticList;
  }
  while ( v3 >= 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UlobbyUser_t@@$05@@QAA@XZ
// EA  : 0x829AA1C0
// RVA : 0x009AA1C0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<lobbyUser_t,6> *__fastcall idStaticList<lobbyUser_t,6>::idStaticList<lobbyUser_t,6>(
        idStaticList<lobbyUser_t,6> *this)
{
  __int64 v1; // r29
  lobbyUser_t *staticList; // r30

  v1 = 0x500000000LL;
  this->granularity = 1;
  this->num = 0;
  staticList = this->staticList;
  this->memTag = 5;
  this->size = 6;
  this->list = this->staticList;
  this->listStatic = 1;
  do
  {
    staticList->lobbyUserID.localUserHandle.handle = 0;
    staticList->lobbyUserID.lobbyType = -1;
    lobbyAddress_t::lobbyAddress_t(this: &staticList->address);
    staticList->isBot = false;
    staticList->botData = nullptr;
    --HIDWORD(v1);
    staticList->peerIndex = -1;
    staticList->disconnecting = false;
    staticList->emblemOrdinal = 0;
    staticList->level = 1;
    staticList->pingMs = 9999;
    staticList->teamNumber = 0;
    staticList->arbitrationAcked = false;
    staticList->partyToken = 0;
    staticList->migrationGameData = -1;
    staticList->userIndex = 0;
    staticList->xuid = v1;
    staticList = (lobbyUser_t *)((char *)staticList + 176);
  }
  while ( v1 >= 0 );
  return this;
}


// ========================================================================
// __unwind$231356
// EA  : 0x829AA26C
// RVA : 0x009AA26C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_231356()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 180));
}


// ========================================================================
// ??0?$idStaticList@Upeer_t@idLobby@@$05@@QAA@XZ
// EA  : 0x829ACD98
// RVA : 0x009ACD98
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idLobby::peer_t,6> *__fastcall idStaticList<idLobby::peer_t,6>::idStaticList<idLobby::peer_t,6>(
        idStaticList<idLobby::peer_t,6> *this)
{
  idLobby::peer_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 6;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x1D8u,
    count: 6,
    pCtor: (void (__fastcall *)(void *))idLobby::peer_t::peer_t,
    pDtor: (void (__fastcall *)(void *))idLobby::peer_t::~peer_t);
  return this;
}


// ========================================================================
// __unwind$233491
// EA  : 0x829ACE1C
// RVA : 0x009ACE1C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_233491()
{
  int v0; // r12

  idList<idLobby::peer_t,5>::~idList<idLobby::peer_t,5>(this: *(idList<idLobby::peer_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidSaveGameDetails@@$0BA@@@QAA@XZ
// EA  : 0x829BE4A0
// RVA : 0x009BE4A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSaveGameDetails,16> *__fastcall idStaticList<idSaveGameDetails,16>::idStaticList<idSaveGameDetails,16>(
        idStaticList<idSaveGameDetails,16> *this)
{
  idSaveGameDetails *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xA0u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idSaveGameDetails::idSaveGameDetails,
    pDtor: (void (__fastcall *)(void *))idSaveGameDetails::~idSaveGameDetails);
  return this;
}


// ========================================================================
// __unwind$231584
// EA  : 0x829BE524
// RVA : 0x009BE524
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_231584()
{
  int v0; // r12

  idList<idSaveGameDetails,5>::Clear(this: *(idList<idSaveGameDetails,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UcontentData_t@idSessionLocal@@$0BA@@@QAA@XZ
// EA  : 0x829C8F18
// RVA : 0x009C8F18
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSessionLocal::contentData_t,16> *__fastcall idStaticList<idSessionLocal::contentData_t,16>::idStaticList<idSessionLocal::contentData_t,16>(
        idStaticList<idSessionLocal::contentData_t,16> *this)
{
  idSessionLocal::contentData_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x41Cu,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idSessionLocal::contentData_t::contentData_t,
    pDtor: (void (__fastcall *)(void *))idSessionLocal::contentData_t::~contentData_t);
  return this;
}


// ========================================================================
// __unwind$242568
// EA  : 0x829C8F9C
// RVA : 0x009C8F9C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_242568()
{
  int v0; // r12

  idList<idSessionLocal::contentData_t,5>::~idList<idSessionLocal::contentData_t,5>(this: *(idList<idSessionLocal::contentData_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@PAVidFile_SaveGame@@$09@@QAA@ABV0@@Z
// EA  : 0x829CCF58
// RVA : 0x009CCF58
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idFile_SaveGame *,10> *__fastcall idStaticList<idFile_SaveGame *,10>::idStaticList<idFile_SaveGame *,10>(
        idStaticList<idFile_SaveGame *,10> *this,
        const idList<idMD6Node *,5> *other)
{
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 10;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  idStaticList<idFile_SaveGame *,10>::operator=(this, __that: other);
  return this;
}


// ========================================================================
// __unwind$240682
// EA  : 0x829CCFC4
// RVA : 0x009CCFC4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_240682()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidSaveGameDetails@@$0BA@@@QAA@ABV0@@Z
// EA  : 0x829CE428
// RVA : 0x009CE428
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSaveGameDetails,16> *__fastcall idStaticList<idSaveGameDetails,16>::idStaticList<idSaveGameDetails,16>(
        idStaticList<idSaveGameDetails,16> *this,
        const idStaticList<idSaveGameDetails,16> *other)
{
  idSaveGameDetails *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xA0u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idSaveGameDetails::idSaveGameDetails,
    pDtor: (void (__fastcall *)(void *))idSaveGameDetails::~idSaveGameDetails);
  idStaticList<idSaveGameDetails,16>::operator=(this, __that: other);
  return this;
}


// ========================================================================
// __unwind$242328
// EA  : 0x829CE4A4
// RVA : 0x009CE4A4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_242328()
{
  int v0; // r12

  idList<idSaveGameDetails,5>::Clear(this: *(idList<idSaveGameDetails,5> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$242329
// EA  : 0x829CE4CC
// RVA : 0x009CE4CC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_242329()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 16),
    size: 0xA0u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idSaveGameDetails::~idSaveGameDetails);
}


// ========================================================================
// ??0?$idStaticList@UqueuedLeaderboardUpload_t@@$0BI@@@QAA@XZ
// EA  : 0x829D6578
// RVA : 0x009D6578
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<queuedLeaderboardUpload_t,24> *__fastcall idStaticList<queuedLeaderboardUpload_t,24>::idStaticList<queuedLeaderboardUpload_t,24>(
        idStaticList<queuedLeaderboardUpload_t,24> *this)
{
  queuedLeaderboardUpload_t *staticList; // r30
  int i; // r28

  this->granularity = 1;
  this->num = 0;
  staticList = this->staticList;
  this->size = 24;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  for ( i = 23; i >= 0; --i )
  {
    staticList->lobbyUserID.localUserHandle.handle = 0;
    staticList->lobbyUserID.lobbyType = -1;
    `vector constructor iterator'(
      __t: (char *)staticList->stats,
      __s: 8u,
      __n: 16,
      __f: (void *(__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
    ++staticList;
  }
  return this;
}


// ========================================================================
// __unwind$229813
// EA  : 0x829D65FC
// RVA : 0x009D65FC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_229813()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// ??0?$idStaticList@UcompareLeaderboardUpload_t@@$05@@QAA@XZ
// EA  : 0x829D8E60
// RVA : 0x009D8E60
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<compareLeaderboardUpload_t,6> *__fastcall idStaticList<compareLeaderboardUpload_t,6>::idStaticList<compareLeaderboardUpload_t,6>(
        idStaticList<compareLeaderboardUpload_t,6> *this)
{
  compareLeaderboardUpload_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 6;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x2E8u,
    count: 6,
    pCtor: (void (__fastcall *)(void *))compareLeaderboardUpload_t::compareLeaderboardUpload_t,
    pDtor: (void (__fastcall *)(void *))compareLeaderboardUpload_t::~compareLeaderboardUpload_t);
  return this;
}


// ========================================================================
// __unwind$231834_0
// EA  : 0x829D8EE4
// RVA : 0x009D8EE4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_231834_0()
{
  int v0; // r12

  idList<compareLeaderboardUpload_t,5>::Clear(this: *(idList<compareLeaderboardUpload_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UfriendGameQuery_t@id360FriendsServerFinder@@$0BA@@@QAA@XZ
// EA  : 0x829E04B8
// RVA : 0x009E04B8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<id360FriendsServerFinder::friendGameQuery_t,16> *__fastcall idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>::idStaticList<id360FriendsServerFinder::friendGameQuery_t,16>(
        idStaticList<id360FriendsServerFinder::friendGameQuery_t,16> *this)
{
  id360FriendsServerFinder::friendGameQuery_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x98u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))id360FriendsServerFinder::friendGameQuery_t::friendGameQuery_t,
    pDtor: (void (__fastcall *)(void *))idPlaytestStorage::useFocusInfo_t::~useFocusInfo_t);
  return this;
}


// ========================================================================
// __unwind$226520
// EA  : 0x829E053C
// RVA : 0x009E053C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_226520()
{
  int v0; // r12

  idList<id360FriendsServerFinder::friendGameQuery_t,5>::Clear(this: *(idList<id360FriendsServerFinder::friendGameQuery_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UserverQueryInfo_t@idServerQuery@@$0CA@@@QAA@XZ
// EA  : 0x829E0660
// RVA : 0x009E0660
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idServerQuery::serverQueryInfo_t,32> *__fastcall idStaticList<idServerQuery::serverQueryInfo_t,32>::idStaticList<idServerQuery::serverQueryInfo_t,32>(
        idStaticList<idServerQuery::serverQueryInfo_t,32> *this)
{
  idServerQuery::serverQueryInfo_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 32;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xCCu,
    count: 32,
    pCtor: (void (__fastcall *)(void *))idServerQuery::serverQueryInfo_t::serverQueryInfo_t,
    pDtor: (void (__fastcall *)(void *))idServerQuery::serverQueryInfo_t::~serverQueryInfo_t);
  return this;
}


// ========================================================================
// __unwind$226590
// EA  : 0x829E06E4
// RVA : 0x009E06E4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_226590()
{
  int v0; // r12

  idList<idServerQuery::serverQueryInfo_t,5>::Clear(this: *(idList<idServerQuery::serverQueryInfo_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Utalker_t@idVoiceChatMgr@@$0M@@@QAA@XZ
// EA  : 0x829E46A0
// RVA : 0x009E46A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idVoiceChatMgr::talker_t,12> *__fastcall idStaticList<idVoiceChatMgr::talker_t,12>::idStaticList<idVoiceChatMgr::talker_t,12>(
        idStaticList<idVoiceChatMgr::talker_t,12> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 12;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 12;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    *((_BYTE *)p_granularity + 8) = 0;
    *((_DWORD *)p_granularity + 3) = -1;
    *((_DWORD *)p_granularity + 4) = -1;
    *((_BYTE *)p_granularity + 20) = 0;
    *((_BYTE *)p_granularity + 21) = 0;
    *((_DWORD *)p_granularity + 6) = -1;
    p_granularity[14] = 1;
    *((_BYTE *)p_granularity + 30) = 0;
    *((_BYTE *)p_granularity + 31) = 0;
    *((_BYTE *)p_granularity + 32) = 0;
    p_granularity += 18;
    *(_DWORD *)p_granularity = 0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UremoteMachine_t@idVoiceChatMgr@@$0M@@@QAA@XZ
// EA  : 0x829E4720
// RVA : 0x009E4720
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idVoiceChatMgr::remoteMachine_t,12> *__fastcall idStaticList<idVoiceChatMgr::remoteMachine_t,12>::idStaticList<idVoiceChatMgr::remoteMachine_t,12>(
        idStaticList<idVoiceChatMgr::remoteMachine_t,12> *this)
{
  int v2; // r29
  lobbyAddress_t *p_address; // r28

  this->size = 12;
  this->granularity = 1;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  v2 = 11;
  p_address = &this->staticList[0].address;
  do
  {
    lobbyAddress_t::lobbyAddress_t(this: p_address);
    --v2;
    p_address = (lobbyAddress_t *)((char *)p_address + 72);
  }
  while ( v2 >= 0 );
  return this;
}


// ========================================================================
// __unwind$240184
// EA  : 0x829E4790
// RVA : 0x009E4790
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_240184()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStaticList@VidAIVar_String@@$07@@QAA@XZ
// EA  : 0x82A3FF38
// RVA : 0x00A3FF38
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAIVar_String,8> *__fastcall idStaticList<idAIVar_String,8>::idStaticList<idAIVar_String,8>(
        idStaticList<idAIVar_String,8> *this)
{
  idAIVar_String *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 8;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x44u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idAIVar_String::idAIVar_String,
    pDtor: (void (__fastcall *)(void *))idAIVar_String::~idAIVar_String);
  return this;
}


// ========================================================================
// __unwind$489878
// EA  : 0x82A3FFBC
// RVA : 0x00A3FFBC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489878()
{
  int v0; // r12

  idList<idAIVar_String,5>::~idList<idAIVar_String,5>(this: *(idList<idAIVar_String,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidAIVar_Float@@$07@@QAA@XZ
// EA  : 0x82A3FFF0
// RVA : 0x00A3FFF0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAIVar_Float,8> *__fastcall idStaticList<idAIVar_Float,8>::idStaticList<idAIVar_Float,8>(
        idStaticList<idAIVar_Float,8> *this)
{
  idAIVar_Float *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 8;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x28u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idAIVar_Float::idAIVar_Float,
    pDtor: (void (__fastcall *)(void *))idAIVar_Float::~idAIVar_Float);
  return this;
}


// ========================================================================
// __unwind$489898
// EA  : 0x82A40074
// RVA : 0x00A40074
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489898()
{
  int v0; // r12

  idList<idLayer,5>::Clear(this: *(idList<idAIVar_Int,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidAIVar_Int@@$07@@QAA@XZ
// EA  : 0x82A400A8
// RVA : 0x00A400A8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAIVar_Int,8> *__fastcall idStaticList<idAIVar_Int,8>::idStaticList<idAIVar_Int,8>(
        idStaticList<idAIVar_Int,8> *this)
{
  idAIVar_Int *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 8;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x28u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idAIVar_Int::idAIVar_Int,
    pDtor: (void (__fastcall *)(void *))idAIVar_Int::~idAIVar_Int);
  return this;
}


// ========================================================================
// __unwind$489918
// EA  : 0x82A4012C
// RVA : 0x00A4012C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489918()
{
  int v0; // r12

  idList<idLayer,5>::Clear(this: *(idList<idAIVar_Int,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidDamageImpulse@@$07@@QAA@XZ
// EA  : 0x82A41938
// RVA : 0x00A41938
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idDamageImpulse,8> *__fastcall idStaticList<idDamageImpulse,8>::idStaticList<idDamageImpulse,8>(
        idStaticList<idDamageImpulse,8> *this)
{
  this->num = 0;
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 8;
  this->memTag = 5;
  this->listStatic = 1;
  this->staticList[0].damageDecl = nullptr;
  this->staticList[0].impactDir.x = 0.0;
  this->staticList[0].impactDir.y = 0.0;
  this->staticList[0].impactDir.z = 0.0;
  this->staticList[0].impactPoint.x = 0.0;
  this->staticList[0].impactPoint.y = 0.0;
  this->staticList[0].impactPoint.z = 0.0;
  this->staticList[0].jointIndex.value = -1;
  this->staticList[0].damage = 0.0;
  this->staticList[0].armorPoppedOff = false;
  this->staticList[0].forceInjured = false;
  this->staticList[1].damageDecl = nullptr;
  this->staticList[1].impactDir.x = 0.0;
  this->staticList[1].impactDir.y = 0.0;
  this->staticList[1].impactDir.z = 0.0;
  this->staticList[1].impactPoint.x = 0.0;
  this->staticList[1].impactPoint.y = 0.0;
  this->staticList[1].impactPoint.z = 0.0;
  this->staticList[1].jointIndex.value = -1;
  this->staticList[1].damage = 0.0;
  this->staticList[1].armorPoppedOff = false;
  this->staticList[1].forceInjured = false;
  this->staticList[2].damageDecl = nullptr;
  this->staticList[2].impactDir.x = 0.0;
  this->staticList[2].impactDir.y = 0.0;
  this->staticList[2].impactDir.z = 0.0;
  this->staticList[2].impactPoint.x = 0.0;
  this->staticList[2].impactPoint.y = 0.0;
  this->staticList[2].impactPoint.z = 0.0;
  this->staticList[2].jointIndex.value = -1;
  this->staticList[2].damage = 0.0;
  this->staticList[2].armorPoppedOff = false;
  this->staticList[2].forceInjured = false;
  this->staticList[3].damageDecl = nullptr;
  this->staticList[3].impactDir.x = 0.0;
  this->staticList[3].impactDir.y = 0.0;
  this->staticList[3].impactDir.z = 0.0;
  this->staticList[3].impactPoint.x = 0.0;
  this->staticList[3].impactPoint.y = 0.0;
  this->staticList[3].impactPoint.z = 0.0;
  this->staticList[3].jointIndex.value = -1;
  this->staticList[3].damage = 0.0;
  this->staticList[3].armorPoppedOff = false;
  this->staticList[3].forceInjured = false;
  this->staticList[4].damageDecl = nullptr;
  this->staticList[4].impactDir.x = 0.0;
  this->staticList[4].impactDir.y = 0.0;
  this->staticList[4].impactDir.z = 0.0;
  this->staticList[4].impactPoint.x = 0.0;
  this->staticList[4].impactPoint.y = 0.0;
  this->staticList[4].impactPoint.z = 0.0;
  this->staticList[4].jointIndex.value = -1;
  this->staticList[4].damage = 0.0;
  this->staticList[4].armorPoppedOff = false;
  this->staticList[4].forceInjured = false;
  this->staticList[5].damageDecl = nullptr;
  this->staticList[5].impactDir.x = 0.0;
  this->staticList[5].impactDir.y = 0.0;
  this->staticList[5].impactDir.z = 0.0;
  this->staticList[5].impactPoint.x = 0.0;
  this->staticList[5].impactPoint.y = 0.0;
  this->staticList[5].impactPoint.z = 0.0;
  this->staticList[5].jointIndex.value = -1;
  this->staticList[5].damage = 0.0;
  this->staticList[5].armorPoppedOff = false;
  this->staticList[5].forceInjured = false;
  this->staticList[6].damageDecl = nullptr;
  this->staticList[6].impactDir.x = 0.0;
  this->staticList[6].impactDir.y = 0.0;
  this->staticList[6].impactDir.z = 0.0;
  this->staticList[6].impactPoint.x = 0.0;
  this->staticList[6].impactPoint.y = 0.0;
  this->staticList[6].impactPoint.z = 0.0;
  this->staticList[6].jointIndex.value = -1;
  this->staticList[6].damage = 0.0;
  this->staticList[6].armorPoppedOff = false;
  this->staticList[6].forceInjured = false;
  this->staticList[7].damageDecl = nullptr;
  this->staticList[7].impactDir.x = 0.0;
  this->staticList[7].impactDir.y = 0.0;
  this->staticList[7].impactDir.z = 0.0;
  this->staticList[7].impactPoint.x = 0.0;
  this->staticList[7].impactPoint.y = 0.0;
  this->staticList[7].impactPoint.z = 0.0;
  this->staticList[7].jointIndex.value = -1;
  this->staticList[7].damage = 0.0;
  this->staticList[7].armorPoppedOff = false;
  this->staticList[7].forceInjured = false;
  return this;
}


// ========================================================================
// ??0?$idStaticList@UidNpCornerInfo@@$0BP@@@QAA@XZ
// EA  : 0x82A71C88
// RVA : 0x00A71C88
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idNpCornerInfo,31> *__fastcall idStaticList<idNpCornerInfo,31>::idStaticList<idNpCornerInfo,31>(
        idStaticList<idNpCornerInfo,31> *this)
{
  idNpCornerInfo *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 31;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x3Cu,
    count: 31,
    pCtor: (void (__fastcall *)(void *))idNpCornerInfo::idNpCornerInfo,
    pDtor: (void (__fastcall *)(void *))idNpCornerInfo::~idNpCornerInfo);
  return this;
}


// ========================================================================
// __unwind$504526
// EA  : 0x82A71D0C
// RVA : 0x00A71D0C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_504526()
{
  int v0; // r12

  idList<idNpCornerInfo,5>::~idList<idNpCornerInfo,5>(this: *(idList<idNpCornerInfo,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidAICover@@$0IA@@@QAA@XZ
// EA  : 0x82A8F8E8
// RVA : 0x00A8F8E8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idAICover,128> *__fastcall idStaticList<idAICover,128>::idStaticList<idAICover,128>(
        idStaticList<idAICover,128> *this)
{
  idAICover *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 128;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xCu,
    count: 128,
    pCtor: (void (__fastcall *)(void *))idAICover::idAICover,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  return this;
}


// ========================================================================
// __unwind$488176
// EA  : 0x82A8F96C
// RVA : 0x00A8F96C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_488176()
{
  int v0; // r12

  idList<idAICover,5>::Clear(this: *(idAICoverManager **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidTargetInfo@@$07@@QAA@XZ
// EA  : 0x82B039A0
// RVA : 0x00B039A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idTargetInfo,8> *__fastcall idStaticList<idTargetInfo,8>::idStaticList<idTargetInfo,8>(
        idStaticList<idTargetInfo,8> *this)
{
  idTargetInfo *staticList; // r28
  int i; // r29

  this->granularity = 1;
  this->size = 8;
  staticList = this->staticList;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  for ( i = 7; i >= 0; --i )
    idTargetInfo::idTargetInfo(this: staticList++);
  return this;
}


// ========================================================================
// __unwind$487770_0
// EA  : 0x82B03A08
// RVA : 0x00B03A08
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_487770_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStaticList@UvehiclePickupInfo_t@@$09@@QAA@XZ
// EA  : 0x82B0EFE0
// RVA : 0x00B0EFE0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<vehiclePickupInfo_t,10> *__fastcall idStaticList<vehiclePickupInfo_t,10>::idStaticList<vehiclePickupInfo_t,10>(
        idStaticList<vehiclePickupInfo_t,10> *this)
{
  this->num = 0;
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 10;
  this->memTag = 5;
  this->listStatic = 1;
  this->staticList[0].prop.spawnId.value = 0x1FFF;
  this->staticList[0].pathPos.distance = 0.0;
  this->staticList[0].pathPos.rightDistance = 0.0;
  this->staticList[0].pathPos.navSpline = nullptr;
  this->staticList[0].distance = 0.0;
  this->staticList[0].frame = 0;
  this->staticList[1].prop.spawnId.value = 0x1FFF;
  this->staticList[1].pathPos.distance = 0.0;
  this->staticList[1].pathPos.rightDistance = 0.0;
  this->staticList[1].pathPos.navSpline = nullptr;
  this->staticList[1].distance = 0.0;
  this->staticList[1].frame = 0;
  this->staticList[2].prop.spawnId.value = 0x1FFF;
  this->staticList[2].pathPos.distance = 0.0;
  this->staticList[2].pathPos.rightDistance = 0.0;
  this->staticList[2].pathPos.navSpline = nullptr;
  this->staticList[2].distance = 0.0;
  this->staticList[2].frame = 0;
  this->staticList[3].prop.spawnId.value = 0x1FFF;
  this->staticList[3].pathPos.distance = 0.0;
  this->staticList[3].pathPos.rightDistance = 0.0;
  this->staticList[3].pathPos.navSpline = nullptr;
  this->staticList[3].distance = 0.0;
  this->staticList[3].frame = 0;
  this->staticList[4].prop.spawnId.value = 0x1FFF;
  this->staticList[4].pathPos.distance = 0.0;
  this->staticList[4].pathPos.rightDistance = 0.0;
  this->staticList[4].pathPos.navSpline = nullptr;
  this->staticList[4].distance = 0.0;
  this->staticList[4].frame = 0;
  this->staticList[5].prop.spawnId.value = 0x1FFF;
  this->staticList[5].pathPos.distance = 0.0;
  this->staticList[5].pathPos.rightDistance = 0.0;
  this->staticList[5].pathPos.navSpline = nullptr;
  this->staticList[5].distance = 0.0;
  this->staticList[5].frame = 0;
  this->staticList[6].prop.spawnId.value = 0x1FFF;
  this->staticList[6].pathPos.distance = 0.0;
  this->staticList[6].pathPos.rightDistance = 0.0;
  this->staticList[6].pathPos.navSpline = nullptr;
  this->staticList[6].distance = 0.0;
  this->staticList[6].frame = 0;
  this->staticList[7].prop.spawnId.value = 0x1FFF;
  this->staticList[7].pathPos.distance = 0.0;
  this->staticList[7].pathPos.rightDistance = 0.0;
  this->staticList[7].pathPos.navSpline = nullptr;
  this->staticList[7].distance = 0.0;
  this->staticList[7].frame = 0;
  this->staticList[8].prop.spawnId.value = 0x1FFF;
  this->staticList[8].pathPos.distance = 0.0;
  this->staticList[8].pathPos.rightDistance = 0.0;
  this->staticList[8].pathPos.navSpline = nullptr;
  this->staticList[8].distance = 0.0;
  this->staticList[8].frame = 0;
  this->staticList[9].prop.spawnId.value = 0x1FFF;
  this->staticList[9].pathPos.distance = 0.0;
  this->staticList[9].pathPos.rightDistance = 0.0;
  this->staticList[9].pathPos.navSpline = nullptr;
  this->staticList[9].distance = 0.0;
  this->staticList[9].frame = 0;
  return this;
}


// ========================================================================
// ??0?$idStaticList@UammoF_t@idVehicleAI@@$07@@QAA@XZ
// EA  : 0x82B132A8
// RVA : 0x00B132A8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idVehicleAI::ammoF_t,8> *__fastcall idStaticList<idVehicleAI::ammoF_t,8>::idStaticList<idVehicleAI::ammoF_t,8>(
        idStaticList<idVehicleAI::ammoF_t,8> *this)
{
  this->num = 0;
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 8;
  this->memTag = 5;
  this->listStatic = 1;
  this->staticList[0].frac = 0.0;
  this->staticList[0].decl = nullptr;
  this->staticList[0].slot = 0;
  this->staticList[0].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[1].frac = 0.0;
  this->staticList[1].decl = nullptr;
  this->staticList[1].slot = 0;
  this->staticList[1].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[2].frac = 0.0;
  this->staticList[2].decl = nullptr;
  this->staticList[2].slot = 0;
  this->staticList[2].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[3].frac = 0.0;
  this->staticList[3].decl = nullptr;
  this->staticList[3].slot = 0;
  this->staticList[3].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[4].frac = 0.0;
  this->staticList[4].decl = nullptr;
  this->staticList[4].slot = 0;
  this->staticList[4].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[5].frac = 0.0;
  this->staticList[5].decl = nullptr;
  this->staticList[5].slot = 0;
  this->staticList[5].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[6].frac = 0.0;
  this->staticList[6].decl = nullptr;
  this->staticList[6].slot = 0;
  this->staticList[6].bestPickupItem.spawnId.value = 0x1FFF;
  this->staticList[7].frac = 0.0;
  this->staticList[7].decl = nullptr;
  this->staticList[7].slot = 0;
  this->staticList[7].bestPickupItem.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0?$idStaticList@UentInfo_t@@$0EA@@@QAA@XZ
// EA  : 0x82B490D8
// RVA : 0x00B490D8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<entInfo_t,64> *__fastcall idStaticList<entInfo_t,64>::idStaticList<entInfo_t,64>(
        idStaticList<entInfo_t,64> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 64;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 64;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((_BYTE *)p_granularity + 4) = 0;
    *((_DWORD *)p_granularity + 2) = 0;
    *((_DWORD *)p_granularity + 3) = 0;
    p_granularity += 8;
    *(_DWORD *)p_granularity = 0x1FFF;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@VidCrosshairCombinerInfo@@$02@@QAA@XZ
// EA  : 0x82B79838
// RVA : 0x00B79838
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idCrosshairCombinerInfo,3> *__fastcall idStaticList<idCrosshairCombinerInfo,3>::idStaticList<idCrosshairCombinerInfo,3>(
        idStaticList<idCrosshairCombinerInfo,3> *this)
{
  idCrosshairCombinerInfo *staticList; // r10
  int v2; // r7
  int *v3; // r9
  int v4; // ctr

  staticList = this->staticList;
  this->size = 3;
  this->granularity = 1;
  this->list = this->staticList;
  this->num = 0;
  v2 = 2;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    staticList->hovered = false;
    v3 = &staticList->itemState[4];
    staticList->itemCount = 0;
    v4 = 5;
    staticList->itemIndex = 0;
    do
    {
      *(v3 - 4) = 0;
      *++v3 = 0;
      --v4;
    }
    while ( v4 != 0 );
    --v2;
    ++staticList;
  }
  while ( v2 >= 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UclientDetachable_t@idPresentableVehicle@@$0EG@@@QAA@XZ
// EA  : 0x82BA60A0
// RVA : 0x00BA60A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idPresentableVehicle::clientDetachable_t,70> *__fastcall idStaticList<idPresentableVehicle::clientDetachable_t,70>::idStaticList<idPresentableVehicle::clientDetachable_t,70>(
        idStaticList<idPresentableVehicle::clientDetachable_t,70> *this)
{
  idPresentableVehicle::clientDetachable_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 70;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x94u,
    count: 70,
    pCtor: (void (__fastcall *)(void *))idPresentableVehicle::clientDetachable_t::clientDetachable_t,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  return this;
}


// ========================================================================
// __unwind$527803
// EA  : 0x82BA6124
// RVA : 0x00BA6124
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_527803()
{
  int v0; // r12

  idList<idPresentableVehicle::clientDetachable_t,5>::Clear(this: *(idList<idPresentableVehicle::clientDetachable_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UplayerData_t@idGameChallenge@@$05@@QAA@XZ
// EA  : 0x82C56740
// RVA : 0x00C56740
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idGameChallenge::playerData_t,6> *__fastcall idStaticList<idGameChallenge::playerData_t,6>::idStaticList<idGameChallenge::playerData_t,6>(
        idStaticList<idGameChallenge::playerData_t,6> *this)
{
  int v1; // r5
  idGameChallenge::playerData_t *staticList; // r11
  int *p_timeTillNewPlayerCanTake; // r9
  int v4; // ctr

  v1 = 5;
  staticList = this->staticList;
  this->granularity = 1;
  this->memTag = 5;
  this->list = this->staticList;
  this->size = 6;
  this->num = 0;
  this->listStatic = 1;
  do
  {
    staticList->respawnDelay = 0;
    p_timeTillNewPlayerCanTake = &staticList->timeTillNewPlayerCanTake;
    staticList->spawnHandle = 0;
    v4 = 6;
    staticList->lastScore = 0;
    staticList->score = 0;
    staticList->lives = 0;
    staticList->team = TEAM_NONE;
    staticList->spectator = false;
    staticList->state = PLAYER_STATE_NONE;
    staticList->stateTime = 0;
    staticList->startTime = 0;
    staticList->needToSendFullSnap = false;
    staticList->player.spawnId.value = 0x1FFF;
    staticList->lastKiller = -1;
    staticList->timeTillNewPlayerCanTake = -1;
    do
    {
      *++p_timeTillNewPlayerCanTake = 0;
      --v4;
    }
    while ( v4 != 0 );
    --v1;
    ++staticList;
  }
  while ( v1 >= 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UteamData_t@idGameChallenge@@$04@@QAA@XZ
// EA  : 0x82C5ACE0
// RVA : 0x00C5ACE0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idGameChallenge::teamData_t,5> *__fastcall idStaticList<idGameChallenge::teamData_t,5>::idStaticList<idGameChallenge::teamData_t,5>(
        idStaticList<idGameChallenge::teamData_t,5> *this)
{
  idGameChallenge::teamData_t *staticList; // r3

  this->size = 5;
  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x24u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idGameChallenge::teamData_t::teamData_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$508778
// EA  : 0x82C5AD60
// RVA : 0x00C5AD60
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_508778()
{
  int v0; // r12

  idList<idGameChallenge::teamData_t,5>::~idList<idGameChallenge::teamData_t,5>(this: *(idList<idGameChallenge::teamData_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UspectatorAttachment_t@idRaceSpectator@@$01@@QAA@XZ
// EA  : 0x82CAD620
// RVA : 0x00CAD620
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idRaceSpectator::spectatorAttachment_t,2> *__fastcall idStaticList<idRaceSpectator::spectatorAttachment_t,2>::idStaticList<idRaceSpectator::spectatorAttachment_t,2>(
        idStaticList<idRaceSpectator::spectatorAttachment_t,2> *this)
{
  idRaceSpectator::spectatorAttachment_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 2;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x24u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idRaceSpectator::spectatorAttachment_t::spectatorAttachment_t,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  return this;
}


// ========================================================================
// __unwind$489119
// EA  : 0x82CAD6A4
// RVA : 0x00CAD6A4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489119()
{
  int v0; // r12

  idList<idSpawnRenderParm,5>::Clear(this: *(idList<idRenderParm,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UnavSplinePathNode_t@@$0LE@@@QAA@XZ
// EA  : 0x82CBD320
// RVA : 0x00CBD320
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<navSplinePathNode_t,180> *__fastcall idStaticList<navSplinePathNode_t,180>::idStaticList<navSplinePathNode_t,180>(
        idStaticList<navSplinePathNode_t,180> *this)
{
  navSplinePathNode_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 180;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x12Cu,
    count: 180,
    pCtor: (void (__fastcall *)(void *))navSplinePathNode_t::navSplinePathNode_t,
    pDtor: (void (__fastcall *)(void *))idMQCommand::~idMQCommand);
  return this;
}


// ========================================================================
// __unwind$489531_0
// EA  : 0x82CBD3A4
// RVA : 0x00CBD3A4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489531_0()
{
  int v0; // r12

  idList<navSplinePathNode_t,5>::Clear(this: *(idList<navSplinePathNode_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidNavSpline@@$0MI@@@QAA@XZ
// EA  : 0x82CC1268
// RVA : 0x00CC1268
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idNavSpline,200> *__fastcall idStaticList<idNavSpline,200>::idStaticList<idNavSpline,200>(
        idStaticList<idNavSpline,200> *this)
{
  idNavSpline *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 200;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x70u,
    count: 200,
    pCtor: (void (__fastcall *)(void *))idNavSpline::idNavSpline,
    pDtor: (void (__fastcall *)(void *))idNavSpline::~idNavSpline);
  return this;
}


// ========================================================================
// __unwind$498430
// EA  : 0x82CC12EC
// RVA : 0x00CC12EC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_498430()
{
  int v0; // r12

  idList<idNavSpline,5>::~idList<idNavSpline,5>(this: *(idList<idNavSpline,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Udetachable_t@@$0EG@@@QAA@XZ
// EA  : 0x82D2C9C0
// RVA : 0x00D2C9C0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<detachable_t,70> *__fastcall idStaticList<detachable_t,70>::idStaticList<detachable_t,70>(
        idStaticList<detachable_t,70> *this)
{
  detachable_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 70;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x7Cu,
    count: 70,
    pCtor: (void (__fastcall *)(void *))detachable_t::detachable_t,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  return this;
}


// ========================================================================
// __unwind$531435
// EA  : 0x82D2CA44
// RVA : 0x00D2CA44
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_531435()
{
  int v0; // r12

  idList<detachable_t,5>::Clear(this: *(idList<detachable_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Ubreakables_t@idBreakableManager@@$0BA@@@QAA@XZ
// EA  : 0x82D95AD8
// RVA : 0x00D95AD8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idBreakableManager::breakables_t,16> *__fastcall idStaticList<idBreakableManager::breakables_t,16>::idStaticList<idBreakableManager::breakables_t,16>(
        idStaticList<idBreakableManager::breakables_t,16> *this)
{
  idBreakableManager::breakables_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 16;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x54u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idRibbonModelManager::ribbonEffects_t::ribbonEffects_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$545551
// EA  : 0x82D95B5C
// RVA : 0x00D95B5C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_545551()
{
  int v0; // r12

  idList<idBreakableManager::breakables_t,5>::Clear(this: *(idList<idRibbonModelManager::ribbonEffects_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Uspawnables_t@idSpawnablePropManager@@$07@@QAA@XZ
// EA  : 0x82D95B90
// RVA : 0x00D95B90
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSpawnablePropManager::spawnables_t,8> *__fastcall idStaticList<idSpawnablePropManager::spawnables_t,8>::idStaticList<idSpawnablePropManager::spawnables_t,8>(
        idStaticList<idSpawnablePropManager::spawnables_t,8> *this)
{
  idSpawnablePropManager::spawnables_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 8;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x24u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idSpawnablePropManager::spawnables_t::spawnables_t,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$545571
// EA  : 0x82D95C14
// RVA : 0x00D95C14
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_545571()
{
  int v0; // r12

  idList<idGameChallenge::teamData_t,5>::~idList<idGameChallenge::teamData_t,5>(this: *(idList<idGameChallenge::teamData_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@H$02@@QAA@XZ
// EA  : 0x82D9EFE0
// RVA : 0x00D9EFE0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<int,3> *__fastcall idStaticList<int,3>::idStaticList<int,3>(idStaticList<int,3> *this)
{
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 3;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  return this;
}


// ========================================================================
// ??0?$idStaticList@H$05@@QAA@ABV0@@Z
// EA  : 0x82D9F098
// RVA : 0x00D9F098
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<int,6> *__fastcall idStaticList<int,6>::idStaticList<int,6>(
        idStaticList<int,6> *this,
        const idList<idMD6Node *,5> *other)
{
  this->granularity = 1;
  this->list = this->staticList;
  this->size = 6;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  idList<idMaterial const *,59>::operator=((idList<idMD6Node *,5> *)this, other);
  qmemcpy(this->staticList, &other[1], sizeof(this->staticList));
  return this;
}


// ========================================================================
// __unwind$489833_0
// EA  : 0x82D9F120
// RVA : 0x00D9F120
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489833_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Uparty_t@@$05@@QAA@XZ
// EA  : 0x82DA0F60
// RVA : 0x00DA0F60
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<party_t,6> *__fastcall idStaticList<party_t,6>::idStaticList<party_t,6>(idStaticList<party_t,6> *this)
{
  party_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 6;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x2Cu,
    count: 6,
    pCtor: (void (__fastcall *)(void *))party_t::party_t,
    pDtor: (void (__fastcall *)(void *))idLobby::migrationInfo_t::~migrationInfo_t);
  return this;
}


// ========================================================================
// __unwind$491504_0
// EA  : 0x82DA0FE4
// RVA : 0x00DA0FE4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_491504_0()
{
  int v0; // r12

  idList<party_t,5>::Clear(this: *(idList<party_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidSWFScriptVar@@$0BA@@@QAA@ABV0@@Z
// EA  : 0x82DB15A0
// RVA : 0x00DB15A0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSWFScriptVar,16> *__fastcall idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
        idStaticList<idSWFScriptVar,16> *this,
        const idStaticList<idSWFScriptVar,16> *other)
{
  int v2; // r28
  idSWFScriptVar *staticList; // r29
  int v6; // r27

  v2 = 16;
  this->granularity = 1;
  this->size = 16;
  staticList = this->staticList;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: this->staticList,
    size: 8u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idMainMenu::idSWFScriptFunction_changeTeam::Call,
    pDtor: (void (__fastcall *)(void *))idSWFScriptVar::~idSWFScriptVar);
  idList<idSWFScriptVar,5>::operator=(this, other);
  v6 = (char *)other - (char *)this;
  do
  {
    idSWFScriptVar::operator=(this: staticList, other: (idSWFScriptVar *)((char *)staticList + v6));
    --v2;
    ++staticList;
  }
  while ( v2 != 0 );
  return this;
}


// ========================================================================
// __unwind$536585
// EA  : 0x82DB163C
// RVA : 0x00DB163C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_536585()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: *(idList<idSWFScriptVar,5> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$536586
// EA  : 0x82DB1664
// RVA : 0x00DB1664
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_536586()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 16),
    size: 8u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idSWFScriptVar::~idSWFScriptVar);
}


// ========================================================================
// ??0?$idStaticList@UlobbyPlayerInfo_t@@$05@@QAA@XZ
// EA  : 0x82DCC678
// RVA : 0x00DCC678
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<lobbyPlayerInfo_t,6> *__fastcall idStaticList<lobbyPlayerInfo_t,6>::idStaticList<lobbyPlayerInfo_t,6>(
        idStaticList<lobbyPlayerInfo_t,6> *this)
{
  lobbyPlayerInfo_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 6;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x38u,
    count: 6,
    pCtor: (void (__fastcall *)(void *))lobbyPlayerInfo_t::lobbyPlayerInfo_t,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$516004
// EA  : 0x82DCC6FC
// RVA : 0x00DCC6FC
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_516004()
{
  int v0; // r12

  idList<lobbyPlayerInfo_t,5>::~idList<lobbyPlayerInfo_t,5>(this: *(idList<idEntityRetainedState,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UmpMapMode_t@@$0BA@@@QAA@ABV0@@Z
// EA  : 0x82DCE9F0
// RVA : 0x00DCE9F0
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<mpMapMode_t,16> *__fastcall idStaticList<mpMapMode_t,16>::idStaticList<mpMapMode_t,16>(
        idStaticList<mpMapMode_t,16> *this,
        const idStaticList<mpMapMode_t,16> *other)
{
  int v2; // r28
  mpMapMode_t *staticList; // r29
  int v6; // r27

  v2 = 16;
  this->granularity = 1;
  this->size = 16;
  staticList = this->staticList;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: this->staticList,
    size: 0xA0u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))mpMapMode_t::mpMapMode_t,
    pDtor: (void (__fastcall *)(void *))mpMapMode_t::~mpMapMode_t);
  idList<mpMapMode_t,5>::operator=(this, other);
  v6 = (char *)other - (char *)this;
  do
  {
    mpMapMode_t::operator=(this: staticList, __that: (mpMapMode_t *)((char *)staticList + v6));
    --v2;
    ++staticList;
  }
  while ( v2 != 0 );
  return this;
}


// ========================================================================
// __unwind$517937
// EA  : 0x82DCEA8C
// RVA : 0x00DCEA8C
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_517937()
{
  int v0; // r12

  idList<mpMapMode_t,5>::~idList<mpMapMode_t,5>(this: *(idList<mpMapMode_t,5> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$517938
// EA  : 0x82DCEAB4
// RVA : 0x00DCEAB4
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_517938()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 16),
    size: 0xA0u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))mpMapMode_t::~mpMapMode_t);
}


// ========================================================================
// ??0?$idStaticList@VidSWFScriptVar@@$04@@QAA@XZ
// EA  : 0x82DD70B8
// RVA : 0x00DD70B8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idSWFScriptVar,5> *__fastcall idStaticList<idSWFScriptVar,5>::idStaticList<idSWFScriptVar,5>(
        idStaticList<idSWFScriptVar,5> *this)
{
  idSWFScriptVar *staticList; // r3

  this->size = 5;
  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 8u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idMainMenu::idSWFScriptFunction_changeTeam::Call,
    pDtor: (void (__fastcall *)(void *))idSWFScriptVar::~idSWFScriptVar);
  return this;
}


// ========================================================================
// __unwind$488642_0
// EA  : 0x82DD7138
// RVA : 0x00DD7138
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_488642_0()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: *(idList<idSWFScriptVar,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@UbuttonInfo_t@idMenuWidget_CommandBar@@$04@@QAA@XZ
// EA  : 0x82DD7508
// RVA : 0x00DD7508
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5> *__fastcall idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>::idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>(
        idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5> *this)
{
  idMenuWidget_CommandBar::buttonInfo_t *staticList; // r3

  this->size = 5;
  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0xB8u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idMenuWidget_CommandBar::buttonInfo_t::buttonInfo_t,
    pDtor: (void (__fastcall *)(void *))idMenuWidget_CommandBar::buttonInfo_t::~buttonInfo_t);
  return this;
}


// ========================================================================
// __unwind$489267
// EA  : 0x82DD7588
// RVA : 0x00DD7588
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_489267()
{
  int v0; // r12

  idList<idMenuWidget_CommandBar::buttonInfo_t,5>::~idList<idMenuWidget_CommandBar::buttonInfo_t,5>(this: *(idList<idMenuWidget_CommandBar::buttonInfo_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VidRageStat@@$0BAA@@@QAA@XZ
// EA  : 0x82DE50E8
// RVA : 0x00DE50E8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idRageStat,256> *__fastcall idStaticList<idRageStat,256>::idStaticList<idRageStat,256>(
        idStaticList<idRageStat,256> *this)
{
  idRageStat *staticList; // r28
  int i; // r29

  this->granularity = 1;
  this->size = 256;
  staticList = this->staticList;
  this->num = 0;
  this->memTag = 5;
  this->list = this->staticList;
  this->listStatic = 1;
  for ( i = 255; i >= 0; --i )
    ContourManager::ContourManager(this: (ContourManager *)staticList++);
  return this;
}


// ========================================================================
// __unwind$494637
// EA  : 0x82DE5150
// RVA : 0x00DE5150
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_494637()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??0?$idStaticList@UweaponStats_t@@$0BE@@@QAA@XZ
// EA  : 0x82DE52F8
// RVA : 0x00DE52F8
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<weaponStats_t,20> *__fastcall idStaticList<weaponStats_t,20>::idStaticList<weaponStats_t,20>(
        idStaticList<weaponStats_t,20> *this)
{
  int v1; // ctr
  __int16 *p_granularity; // r11

  this->size = 20;
  this->list = this->staticList;
  this->granularity = 1;
  v1 = 20;
  this->num = 0;
  p_granularity = &this->granularity;
  this->memTag = 5;
  this->listStatic = 1;
  do
  {
    *((float *)p_granularity + 6) = 0.0;
    *((_DWORD *)p_granularity + 1) = 0;
    *((float *)p_granularity + 11) = 0.0;
    *((_DWORD *)p_granularity + 2) = 0;
    *((_DWORD *)p_granularity + 3) = 0;
    *((_DWORD *)p_granularity + 4) = 0;
    *((_DWORD *)p_granularity + 5) = 0;
    *((_DWORD *)p_granularity + 7) = 0;
    *((_DWORD *)p_granularity + 8) = 0;
    *((_DWORD *)p_granularity + 9) = 0;
    *((_DWORD *)p_granularity + 10) = 0;
    *((_DWORD *)p_granularity + 12) = 0;
    *((_DWORD *)p_granularity + 13) = 0;
    *((_DWORD *)p_granularity + 14) = 0;
    *((_DWORD *)p_granularity + 15) = 0;
    *((_DWORD *)p_granularity + 16) = 0;
    *((_DWORD *)p_granularity + 17) = 0;
    *((_DWORD *)p_granularity + 18) = 0;
    *((_DWORD *)p_granularity + 19) = 0;
    *((_DWORD *)p_granularity + 20) = 0;
    p_granularity += 42;
    *(_DWORD *)p_granularity = 0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ??0?$idStaticList@UprofileLoadout_t@idPlayerProfileGame@@$04@@QAA@XZ
// EA  : 0x82E50190
// RVA : 0x00E50190
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idPlayerProfileGame::profileLoadout_t,5> *__fastcall idStaticList<idPlayerProfileGame::profileLoadout_t,5>::idStaticList<idPlayerProfileGame::profileLoadout_t,5>(
        idStaticList<idPlayerProfileGame::profileLoadout_t,5> *this)
{
  idPlayerProfileGame::profileLoadout_t *staticList; // r3

  this->size = 5;
  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x78u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idStrStatic<64>::idStrStatic<64>,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$490980
// EA  : 0x82E50210
// RVA : 0x00E50210
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_490980()
{
  int v0; // r12

  idList<idPlayerProfileGame::profileLoadout_t,5>::Clear(this: *(idList<idPlayerProfileGame::profileLoadout_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VjobMessage_t@idPlayer@@$04@@QAA@XZ
// EA  : 0x82E74490
// RVA : 0x00E74490
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idPlayer::jobMessage_t,5> *__fastcall idStaticList<idPlayer::jobMessage_t,5>::idStaticList<idPlayer::jobMessage_t,5>(
        idStaticList<idPlayer::jobMessage_t,5> *this)
{
  idPlayer::jobMessage_t *staticList; // r3

  this->size = 5;
  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x24u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idPlayer::jobMessage_t::jobMessage_t,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  return this;
}


// ========================================================================
// __unwind$543504
// EA  : 0x82E74510
// RVA : 0x00E74510
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_543504()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: *(idList<idVoiceTrack::idSubtitleText,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@Vfunction_t@@$0MAA@@@QAA@XZ
// EA  : 0x82EA0500
// RVA : 0x00EA0500
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<function_t,3072> *__fastcall idStaticList<function_t,3072>::idStaticList<function_t,3072>(
        idStaticList<function_t,3072> *this)
{
  function_t *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 3072;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x50u,
    count: 3072,
    pCtor: (void (__fastcall *)(void *))function_t::function_t,
    pDtor: (void (__fastcall *)(void *))function_t::~function_t);
  return this;
}


// ========================================================================
// __unwind$501912
// EA  : 0x82EA0584
// RVA : 0x00EA0584
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_501912()
{
  int v0; // r12

  idList<function_t,5>::Clear(this: *(idList<function_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VNfs3Mount@idNfs3Client@@$0CA@@@QAA@XZ
// EA  : 0x82F18B90
// RVA : 0x00F18B90
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idNfs3Client::Nfs3Mount,32> *__fastcall idStaticList<idNfs3Client::Nfs3Mount,32>::idStaticList<idNfs3Client::Nfs3Mount,32>(
        idStaticList<idNfs3Client::Nfs3Mount,32> *this)
{
  idNfs3Client::Nfs3Mount *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 32;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x68u,
    count: 32,
    pCtor: (void (__fastcall *)(void *))idNfs3Client::Nfs3Mount::Nfs3Mount,
    pDtor: (void (__fastcall *)(void *))idNfs3Client::Nfs3Mount::~Nfs3Mount);
  return this;
}


// ========================================================================
// __unwind$125051
// EA  : 0x82F18C14
// RVA : 0x00F18C14
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_125051()
{
  int v0; // r12

  idList<idNfs3Client::Nfs3Mount,5>::~idList<idNfs3Client::Nfs3Mount,5>(this: *(idList<idNfs3Client::Nfs3Mount,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idStaticList@VExpNode@?$idRuntimeExpression@VVarId@TestExpression@@VVarContext@2@@@$0PN@@@QAA@XZ
// EA  : 0x82F7ED80
// RVA : 0x00F7ED80
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253> *__fastcall idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>::idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253>(
        idStaticList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,253> *this)
{
  idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode *staticList; // r3

  this->granularity = 1;
  staticList = this->staticList;
  this->list = staticList;
  this->size = 253;
  this->num = 0;
  this->memTag = 5;
  this->listStatic = 1;
  `eh vector constructor iterator'(
    ptr: staticList,
    size: 0x30u,
    count: 253,
    pCtor: (void (__fastcall *)(void *))idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode::ExpNode,
    pDtor: (void (__fastcall *)(void *))idSubtitles::idPart::~idPart);
  return this;
}


// ========================================================================
// __unwind$114033
// EA  : 0x82F7EE04
// RVA : 0x00F7EE04
// PDB : w:\tech5\shared\idlib\containers\staticlist.h
// ========================================================================

void _unwind_114033()
{
  int v0; // r12

  idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5>::Clear(this: *(idList<idRuntimeExpression<TestExpression::VarId,TestExpression::VarContext>::ExpNode,5> **)(v0 - 112 + 132));
}

