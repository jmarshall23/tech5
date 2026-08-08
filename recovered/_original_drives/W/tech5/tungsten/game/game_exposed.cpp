
// ========================================================================
// ?SetInterpolation@idGameLocal@@UAAXMHHH@Z
// EA  : 0x82D76D08
// RVA : 0x00D76D08
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::SetInterpolation(
        idGameLocal *this,
        double fraction,
        const int serverGameMS,
        int ssStartTime,
        int ssEndTime,
        int a6)
{
  int v6; // r31

  v6 = this->netInterpolationInfo.serverGameMs;
  this->netInterpolationInfo.serverGameMs = ssStartTime;
  this->netInterpolationInfo.pct = fraction;
  this->netInterpolationInfo.previousServerGameMs = v6;
  this->netInterpolationInfo.ssStartTime = ssEndTime;
  this->netInterpolationInfo.ssEndTime = a6;
}


// ========================================================================
// ??0idGameLock@@QAA@PBVidGame@@@Z
// EA  : 0x82D76D58
// RVA : 0x00D76D58
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

idGameLock *__fastcall idGameLock::idGameLock(idGameLock *this, idGameLocal *newGame)
{
  idGame_vtbl *navPowerInstance; // r3

  this->prevGame = gameLocal;
  clientGame = &newGame->clientGame;
  gameLocal = newGame;
  if ( newGame != nullptr )
  {
    navPowerInstance = (idGame_vtbl *)newGame->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: (idNavPowerInstance *)navPowerInstance, lockInstance: false);
  }
  return this;
}


// ========================================================================
// ??1idGameLock@@QAA@XZ
// EA  : 0x82D76DC8
// RVA : 0x00D76DC8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLock::~idGameLock(idGameLock *this)
{
  const idGame *prevGame; // r11
  idNavPowerInstance *v2; // r3

  prevGame = this->prevGame;
  gameLocal = (idGameLocal *)this->prevGame;
  if ( gameLocal != nullptr )
  {
    clientGame = (idClientGame *)&prevGame[173918];
    v2 = (idNavPowerInstance *)prevGame[437456].__vftable;
    if ( v2 != nullptr )
      idNavPowerInstance::MakeActive(this: v2, lockInstance: false);
  }
  else
  {
    clientGame = nullptr;
  }
}


// ========================================================================
// ?OnCloseSnapshot@idGameLocal@@UAAXXZ
// EA  : 0x82D76E20
// RVA : 0x00D76E20
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::OnCloseSnapshot(idGameLocal *this)
{
  idGameLocal *v1; // r29
  idNavPowerInstance *navPowerInstance; // r3
  idArray<idEntity *,8192> *p_entities; // r10
  int i; // ctr
  idPresentable *presentable; // r11
  idNavPowerInstance *v7; // r3

  v1 = gameLocal;
  gameLocal = this;
  clientGame = &this->clientGame;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  p_entities = &this->entities;
  for ( i = 0x2000; i != 0; --i )
  {
    if ( p_entities->ptr[0] != nullptr )
    {
      presentable = p_entities->ptr[0]->presentable;
      if ( presentable != nullptr )
        presentable->serializedIndex = -1;
    }
    p_entities = (idArray<idEntity *,8192> *)((char *)p_entities + 4);
  }
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v7 = v1->navPowerInstance;
    if ( v7 != nullptr )
      idNavPowerInstance::MakeActive(this: v7, lockInstance: false);
  }
}


// ========================================================================
// __unwind$487577
// EA  : 0x82D76EF8
// RVA : 0x00D76EF8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487577()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 84));
}


// ========================================================================
// ?SetServerGameTimeMs@idGameLocal@@UAAXH@Z
// EA  : 0x82D76F28
// RVA : 0x00D76F28
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::SetServerGameTimeMs(idGameLocal *this, int time)
{
  idGameLocal *v2; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  idNavPowerInstance *v6; // r3

  v2 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  idClientGame::SetServerGameTime(this: p_clientGame, time);
  gameLocal = v2;
  clientGame = v2 == nullptr ? nullptr : &v2->clientGame;
  if ( v2 != nullptr )
  {
    v6 = v2->navPowerInstance;
    if ( v6 != nullptr )
      idNavPowerInstance::MakeActive(this: v6, lockInstance: false);
  }
}


// ========================================================================
// __unwind$487646
// EA  : 0x82D76FD4
// RVA : 0x00D76FD4
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487646()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetServerGameTimeMs@idGameLocal@@UBAHXZ
// EA  : 0x82D77008
// RVA : 0x00D77008
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GetServerGameTimeMs(idGameLocal *this)
{
  idGameLocal *v1; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  int ServerGameTime; // r27
  idNavPowerInstance *v5; // r3

  v1 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  ServerGameTime = idClientGame::GetServerGameTime(this: p_clientGame);
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v5 = v1->navPowerInstance;
    if ( v5 != nullptr )
      idNavPowerInstance::MakeActive(this: v5, lockInstance: false);
  }
  return ServerGameTime;
}


// ========================================================================
// __unwind$487699
// EA  : 0x82D770B4
// RVA : 0x00D770B4
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487699()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?SetSSTimes@idGameLocal@@UAAXHH@Z
// EA  : 0x82D770E0
// RVA : 0x00D770E0
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::SetSSTimes(idGameLocal *this, int ssStart, int ssEnd)
{
  idClientGame *p_clientGame; // r29
  idGameLocal *v4; // r31
  idNavPowerInstance *navPowerInstance; // r3
  idNavPowerInstance *v8; // r3

  p_clientGame = &this->clientGame;
  v4 = gameLocal;
  gameLocal = this;
  clientGame = &this->clientGame;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  p_clientGame->ssStartTime = ssStart;
  p_clientGame->ssEndTime = ssEnd;
  gameLocal = v4;
  clientGame = v4 == nullptr ? nullptr : &v4->clientGame;
  if ( v4 != nullptr )
  {
    v8 = v4->navPowerInstance;
    if ( v8 != nullptr )
      idNavPowerInstance::MakeActive(this: v8, lockInstance: false);
  }
}


// ========================================================================
// ?GetSSEndTime@idGameLocal@@UAAHXZ
// EA  : 0x82D77190
// RVA : 0x00D77190
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GetSSEndTime(idGameLocal *this)
{
  idGameLocal *v1; // r30
  idNavPowerInstance *navPowerInstance; // r3
  int ssEndTime; // r31
  idNavPowerInstance *v5; // r3

  v1 = gameLocal;
  gameLocal = this;
  clientGame = &this->clientGame;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  ssEndTime = this->clientGame.ssEndTime;
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v5 = v1->navPowerInstance;
    if ( v5 != nullptr )
      idNavPowerInstance::MakeActive(this: v5, lockInstance: false);
  }
  return ssEndTime;
}


// ========================================================================
// ?GetSSStartTime@idGameLocal@@UAAHXZ
// EA  : 0x82D77230
// RVA : 0x00D77230
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GetSSStartTime(idGameLocal *this)
{
  idGameLocal *v1; // r30
  idNavPowerInstance *navPowerInstance; // r3
  int ssStartTime; // r31
  idNavPowerInstance *v5; // r3

  v1 = gameLocal;
  gameLocal = this;
  clientGame = &this->clientGame;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  ssStartTime = this->clientGame.ssStartTime;
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v5 = v1->navPowerInstance;
    if ( v5 != nullptr )
      idNavPowerInstance::MakeActive(this: v5, lockInstance: false);
  }
  return ssStartTime;
}


// ========================================================================
// ?RenderLocalViewForPlayer@idGameLocal@@UAAPAVidRenderModelGui@@HHPBUrenderView_t@@PAVidRenderWorld@@@Z
// EA  : 0x82D772D8
// RVA : 0x00D772D8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

idRenderModelGui *__fastcall idGameLocal::RenderLocalViewForPlayer(
        idGameLocal *this,
        int playerNum,
        unsigned int time,
        const renderView_t *view,
        idRenderWorld *rw)
{
  idGameLocal *v5; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  idRenderModelGui *v12; // r27
  idNavPowerInstance *v13; // r3

  v5 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  v12 = idClientGame::RenderLocalViewForPlayer(
          this: p_clientGame,
          playerNum,
          view: __PAIR64__(time, (unsigned int)view),
          rw);
  gameLocal = v5;
  clientGame = v5 == nullptr ? nullptr : &v5->clientGame;
  if ( v5 != nullptr )
  {
    v13 = v5->navPowerInstance;
    if ( v13 != nullptr )
      idNavPowerInstance::MakeActive(this: v13, lockInstance: false);
  }
  return v12;
}


// ========================================================================
// __unwind$487887
// EA  : 0x82D773A4
// RVA : 0x00D773A4
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487887()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 192 + 80));
}


// ========================================================================
// ?RenderLocalViewForGame@idGameLocal@@UAAPAVidRenderModelGui@@HPAVidRenderWorld@@@Z
// EA  : 0x82D773D8
// RVA : 0x00D773D8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

idRenderModelGui *__fastcall idGameLocal::RenderLocalViewForGame(
        idGameLocal *this,
        int time,
        unsigned __int64 rw,
        int a4)
{
  idGameLocal *v4; // r30
  idClientGame *p_clientGame; // r27
  int v7; // r24
  idNavPowerInstance *navPowerInstance; // r3
  idRenderModelGui *v9; // r27
  idNavPowerInstance *v10; // r3

  v4 = gameLocal;
  p_clientGame = &this->clientGame;
  v7 = HIDWORD(rw);
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  HIDWORD(rw) = v7;
  v9 = idClientGame::RenderLocalViewForGame(this: p_clientGame, time, rw, a4);
  gameLocal = v4;
  clientGame = v4 == nullptr ? nullptr : &v4->clientGame;
  if ( v4 != nullptr )
  {
    v10 = v4->navPowerInstance;
    if ( v10 != nullptr )
      idNavPowerInstance::MakeActive(this: v10, lockInstance: false);
  }
  return v9;
}


// ========================================================================
// __unwind$487942
// EA  : 0x82D77494
// RVA : 0x00D77494
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487942()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// ?IsPlayerControlInhibited@idGameLocal@@UBA_NH@Z
// EA  : 0x82D774C8
// RVA : 0x00D774C8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

BOOL __fastcall idGameLocal::IsPlayerControlInhibited(idGameLocal *this, int playerNum)
{
  idGameLocal *v2; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  BOOL IsPlayerControlInhibited; // r27
  idNavPowerInstance *v7; // r3

  v2 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  IsPlayerControlInhibited = idClientGame::IsPlayerControlInhibited(this: p_clientGame, playerNum);
  gameLocal = v2;
  clientGame = v2 == nullptr ? nullptr : &v2->clientGame;
  if ( v2 != nullptr )
  {
    v7 = v2->navPowerInstance;
    if ( v7 != nullptr )
      idNavPowerInstance::MakeActive(this: v7, lockInstance: false);
  }
  return IsPlayerControlInhibited;
}


// ========================================================================
// __unwind$487997
// EA  : 0x82D7757C
// RVA : 0x00D7757C
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_487997()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GenerateInputToPlayerIndexRouting@idGameLocal@@UAAHXZ
// EA  : 0x82D775B0
// RVA : 0x00D775B0
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GenerateInputToPlayerIndexRouting(idGameLocal *this)
{
  idGameLocal *v1; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  int InputToPlayerIndexRouting; // r27
  idNavPowerInstance *v5; // r3

  v1 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  InputToPlayerIndexRouting = idClientGame::GenerateInputToPlayerIndexRouting(this: p_clientGame);
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v5 = v1->navPowerInstance;
    if ( v5 != nullptr )
      idNavPowerInstance::MakeActive(this: v5, lockInstance: false);
  }
  return InputToPlayerIndexRouting;
}


// ========================================================================
// __unwind$488050
// EA  : 0x82D7765C
// RVA : 0x00D7765C
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_488050()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetPlayerIndexFromInputDevice@idGameLocal@@UBAHH@Z
// EA  : 0x82D77690
// RVA : 0x00D77690
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GetPlayerIndexFromInputDevice(idGameLocal *this, int inputDevice)
{
  idGameLocal *v2; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  int PlayerIndexFromInputDevice; // r27
  idNavPowerInstance *v7; // r3

  v2 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  PlayerIndexFromInputDevice = idClientGame::GetPlayerIndexFromInputDevice(this: p_clientGame, inputDevice);
  gameLocal = v2;
  clientGame = v2 == nullptr ? nullptr : &v2->clientGame;
  if ( v2 != nullptr )
  {
    v7 = v2->navPowerInstance;
    if ( v7 != nullptr )
      idNavPowerInstance::MakeActive(this: v7, lockInstance: false);
  }
  return PlayerIndexFromInputDevice;
}


// ========================================================================
// __unwind$488103
// EA  : 0x82D77744
// RVA : 0x00D77744
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_488103()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetPlayerPresentableCmds@idGameLocal@@UAAHHQAPAVusercmd_t@@H@Z
// EA  : 0x82D77778
// RVA : 0x00D77778
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::GetPlayerPresentableCmds(idGameLocal *this, int user, usercmd_t **buffer, int bufferSize)
{
  idGameLocal *v4; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  int PlayerPresentableCmds; // r27
  idNavPowerInstance *v11; // r3

  v4 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  PlayerPresentableCmds = idClientGame::GetPlayerPresentableCmds(this: p_clientGame, user, buffer, bufferSize);
  gameLocal = v4;
  clientGame = v4 == nullptr ? nullptr : &v4->clientGame;
  if ( v4 != nullptr )
  {
    v11 = v4->navPowerInstance;
    if ( v11 != nullptr )
      idNavPowerInstance::MakeActive(this: v11, lockInstance: false);
  }
  return PlayerPresentableCmds;
}


// ========================================================================
// __unwind$488156
// EA  : 0x82D7783C
// RVA : 0x00D7783C
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_488156()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetPlayerPredictionData@idGameLocal@@UAAXHQAPAVusercmd_t@@HAA_N@Z
// EA  : 0x82D77868
// RVA : 0x00D77868
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::GetPlayerPredictionData(
        idGameLocal *this,
        int user,
        usercmd_t **buffer,
        const int bufferSize,
        bool *positionSmoothing)
{
  double x; // fp30
  double y; // fp29
  int v10; // r28
  unsigned __int8 y_low; // r26
  unsigned __int8 v12; // r25
  double z; // fp28
  idPresentable *PresentableByIndex; // r3
  idPresentable *v15; // r30
  idPresentablePlayer *v16; // r3
  idPresentable *Control; // r29
  idPresentablePlayer *v18; // r23
  idAngles *v19; // r3
  float *v20; // r3
  double v21; // fp25
  double v22; // fp26
  double v23; // fp27
  idPresentablePlayer::moveBufferItem_t *MoveBufferItemForClientGameFrame; // r3
  usercmd_t *v25; // r9
  idVec3 v26; // [sp+50h] [-B0h] BYREF
  idMat3 v27; // [sp+60h] [-A0h] BYREF

  x = 0.0;
  y = 0.0;
  v10 = 0;
  y_low = 0;
  v12 = 0;
  z = 0.0;
  v26 = vec3_origin;
  PresentableByIndex = idClientGame::GetPresentableByIndex(this: &this->clientGame, index: user);
  v15 = PresentableByIndex;
  if ( PresentableByIndex != nullptr && PresentableByIndex->GetPlayerInterface_2(this: PresentableByIndex) != nullptr )
  {
    v16 = v15->GetPlayerInterface_2(this: v15);
    Control = idPresentablePlayer::GetControl(this: v16);
    v18 = v15->GetPlayerInterface_2(this: v15);
    if ( Control != nullptr && Control->GetVehicleInterface(this: Control) != nullptr )
    {
      v10 = (int)Control->GetVehicleInterface(this: Control);
      v19 = (idAngles *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v10 + 16512) + 68))(a1: v10 + 16512, a2: 0);
      idMat3::ToAngles(this: &v27, result: v19);
      v20 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v10 + 16512) + 64))(a1: v10 + 16512, a2: 0);
      v21 = *v20;
      v22 = v20[1];
      v23 = v20[2];
      (*(void (__fastcall **)(idVec3 *, int, _DWORD))(*(_DWORD *)(v10 + 16512) + 88))(a1: &v26, a2: v10 + 16512, a3: 0);
      LODWORD(v26.y) = (int)(float)(*(float *)(v10 + 11888) * (float)255.0);
      x = v27.mat[0].x;
      y = v27.mat[0].y;
      z = v27.mat[0].z;
      if ( v26.y >= 0.0 )
      {
        y_low = -1;
        if ( SLODWORD(v26.y) <= 255 )
          y_low = LOBYTE(v26.y);
      }
      v12 = (*(_BYTE *)(v10 + 17993) == 0 ? 0 : 0x40)
          | (*(_BYTE *)(v10 + 11879) == 0 ? 0 : 0x20)
          | (*(_BYTE *)(v10 + 11880) == 0 ? 0 : 0x10)
          | (*(_BYTE *)(v10 + 11883) == 0 ? 0 : 8)
          | (*(_BYTE *)(v10 + 11882) == 0 ? 0 : 4)
          | (*(_BYTE *)(v10 + 11878) == 0 ? 0 : 2)
          | (*(_BYTE *)(v10 + 11877) != 0);
    }
    else
    {
      v23 = v26.z;
      v22 = v26.y;
      v21 = v26.x;
    }
    if ( v18 != nullptr && bufferSize > 0 )
    {
      do
      {
        if ( *buffer != nullptr )
        {
          MoveBufferItemForClientGameFrame = idPresentablePlayer::GetMoveBufferItemForClientGameFrame(
                                               this: v18,
                                               frame: (*buffer)->clientGameFrame);
          if ( v10 != 0 )
          {
            *positionSmoothing = true;
            (*buffer)->pos[0] = v21;
            (*buffer)->pos[1] = v22;
            (*buffer)->pos[2] = v23;
            *(_QWORD *)&v26.x = (__int64)(float)(MoveBufferItemForClientGameFrame->speed * 0.056818184);
            (*buffer)->speed = LOBYTE(v26.y);
            (*buffer)->pitch = (int)(float)((float)x * (float)182.04445);
            LODWORD(v26.y) = (int)(float)((float)y * (float)182.04445);
            v25 = *buffer;
            LODWORD(v26.y) = (int)(float)((float)z * (float)182.04445);
            v25->yaw = (int)(float)((float)y * (float)182.04445);
            (*buffer)->roll = LOWORD(v26.y);
            (*buffer)->predictionStateBits = v12;
            (*buffer)->vehicleThrottle = y_low;
          }
          else
          {
            (*buffer)->pos[0] = MoveBufferItemForClientGameFrame->origin.x;
            (*buffer)->pos[1] = MoveBufferItemForClientGameFrame->origin.y;
            (*buffer)->pos[2] = MoveBufferItemForClientGameFrame->origin.z;
            (*buffer)->speed = 0;
            LODWORD(v26.y) = (int)(float)(MoveBufferItemForClientGameFrame->viewAngles.pitch * (float)182.04445);
            (*buffer)->pitch = LOWORD(v26.y);
            LODWORD(v26.y) = (int)(float)(MoveBufferItemForClientGameFrame->viewAngles.yaw * (float)182.04445);
            (*buffer)->yaw = LOWORD(v26.y);
            (*buffer)->roll = 0;
            (*buffer)->predictionStateBits = MoveBufferItemForClientGameFrame->predictionBits;
          }
          idPresentablePlayer::WriteFireDataToUserCmd(this: v18, usercmd: *buffer);
        }
        --bufferSize;
        ++buffer;
      }
      while ( bufferSize != 0 );
    }
  }
}


// ========================================================================
// ?SmoothIncomingUserCmds@idGameLocal@@UAAXAAVusercmd_t@@PAV2@H@Z
// EA  : 0x82D77C40
// RVA : 0x00D77C40
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameLocal::SmoothIncomingUserCmds(
        idGameLocal *this,
        usercmd_t *base,
        usercmd_t *buffer,
        const int bufferSize)
{
  double v4; // fp22
  int pitch; // r7
  __int128 v6; // r9
  double v7; // fp21
  __int64 v8; // fp10
  __int64 v9; // fp5
  double v10; // fp20
  int v11; // r29
  long double v12; // fp2
  __int64 v13; // r11 OVERLAPPED
  double v14; // fp14
  double v15; // fp9
  double v16; // fp27
  double v17; // fp10
  __int128 v18; // r9
  double v19; // fp28
  __int16 *p_roll; // r31
  double v21; // fp18
  double v22; // fp16
  double v23; // fp17
  double v24; // fp15
  double v25; // fp26
  int v26; // r30
  double v27; // fp30
  double v28; // fp31
  double v29; // fp25
  double v30; // fp24
  double v31; // fp23
  double v32; // fp0
  double v33; // fp27
  double v34; // fp30
  double v35; // fp0
  double v36; // fp30
  double v37; // fp28
  double v38; // fp0
  float v39; // [sp+50h] [-100h]
  float v40; // [sp+58h] [-F8h]
  float v41; // [sp+60h] [-F0h]
  float v42; // [sp+68h] [-E8h]
  float v43; // [sp+70h] [-E0h]
  float v44; // [sp+88h] [-C8h]
  float v45; // [sp+8Ch] [-C4h]

  v4 = base->pos[0];
  pitch = buffer->pitch;
  DWORD2(v6) = (unsigned __int16)base->pitch;
  v7 = base->pos[1];
  v8 = *(_QWORD *)(&bufferSize - 1);
  LODWORD(v6) = base->roll;
  HIDWORD(v13) = SWORD5(v6);
  LODWORD(v13) = buffer->yaw;
  v9 = v6;
  DWORD1(v6) = buffer->roll;
  v10 = base->pos[2];
  v11 = bufferSize - 1;
  *((double *)&v12 + 1) = (double)*(__int64 *)((char *)&v13 + 4);
  v14 = (float)((float)(__int64)v6 * (float)0.0054931641);
  DWORD2(v6) = base->yaw;
  v45 = (float)*(__int64 *)((char *)&v6 + 4) * (float)0.0054931641;
  v15 = (float)((float)v13 * (float)0.0054931641);
  LODWORD(v13) = 0;
  v16 = (float)((float)*(__int64 *)((char *)&v13 + 4) * (float)0.0054931641);
  v44 = (float)*(__int64 *)((char *)&v13 + 4) * (float)0.0054931641;
  v17 = (float)((float)v8 * (float)0.0054931641);
  if ( bufferSize - 1 > 0 )
  {
    LODWORD(v18) = bufferSize;
    v19 = (float)((float)v15 - (float)((float)*(__int64 *)((char *)&v18 + 4) * (float)0.0054931641));
    p_roll = &buffer[-1].roll;
    HIDWORD(v13) = &unk_821D0000;
    v43 = (float)((float)*(__int64 *)(&bufferSize - 1) * (float)0.0054931641) - (float)((float)v9 * (float)0.0054931641);
    v21 = (float)(buffer->pos[0] - base->pos[0]);
    v22 = (float)(buffer->pos[1] - base->pos[1]);
    v42 = (float)v15 - (float)((float)*(__int64 *)((char *)&v18 + 4) * (float)0.0054931641);
    v23 = (float)(__int64)v18;
    v24 = (float)(buffer->pos[2] - base->pos[2]);
    v25 = (float)((float)v17 - (float)v16);
    v41 = 180.0;
    v40 = 0.0027777778;
    v39 = 0.0;
    while ( 1 )
    {
      v26 = v13 + 1;
      v27 = v25;
      LODWORD(v13) = v13 + 1;
      v28 = (float)((float)v13 / (float)v23);
      v29 = (float)((float)((float)v21 * (float)((float)v13 / (float)v23)) + (float)v4);
      v30 = (float)((float)((float)v22 * (float)((float)v13 / (float)v23)) + (float)v7);
      v31 = (float)((float)((float)v24 * (float)((float)v13 / (float)v23)) + (float)v10);
      if ( v25 >= 360.0 || v25 < v39 )
      {
        *(double *)&v12 = (float)((float)v25 * v40);
        v12 = floor(x: v12);
        v27 = (float)-(float)((float)((float)*(double *)&v12 * (float)360.0) - (float)v25);
      }
      v32 = v27;
      if ( v27 > v41 )
        v32 = (float)((float)v27 - (float)360.0);
      v33 = (float)((float)((float)v32 * (float)v28) + (float)v16);
      v34 = v19;
      if ( v19 >= 360.0 || v19 < v39 )
      {
        *(double *)&v12 = (float)((float)v19 * v40);
        v12 = floor(x: v12);
        v34 = (float)-(float)((float)((float)*(double *)&v12 * (float)360.0) - (float)v19);
      }
      v35 = v34;
      if ( v34 > v41 )
        v35 = (float)((float)v34 - (float)360.0);
      v36 = v43;
      v37 = (float)((float)((float)v35 * (float)v28) + v45);
      if ( v43 >= 360.0 || v36 < v39 )
      {
        *(double *)&v12 = (float)(v43 * v40);
        v12 = floor(x: v12);
        v36 = (float)-(float)((float)((float)*(double *)&v12 * (float)360.0) - v43);
      }
      v38 = v36;
      if ( v36 > v41 )
        v38 = (float)((float)v36 - (float)360.0);
      *((float *)p_roll + 11) = v29;
      *((float *)p_roll + 12) = v30;
      *((float *)p_roll + 13) = v31;
      LODWORD(v13) = v26;
      HIDWORD(v13) = (int)(float)((float)v37 * (float)182.04445);
      p_roll[29] = WORD1(v13);
      p_roll[28] = (int)(float)((float)v33 * (float)182.04445);
      p_roll += 30;
      *p_roll = (int)(float)((float)((float)((float)v38 * (float)v28) + (float)v14) * (float)182.04445);
      if ( v26 >= v11 )
        break;
      v19 = v42;
      v16 = v44;
    }
  }
}


// ========================================================================
// ?DrawClientGameDebugHUD@idGameLocal@@UAAXXZ
// EA  : 0x82D77F20
// RVA : 0x00D77F20
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void __fastcall idGameLocal::DrawClientGameDebugHUD(idGameLocal *this)
{
  idGameLocal *v1; // r31
  idNavPowerInstance *navPowerInstance; // r3
  idNavPowerInstance *v3; // r3

  v1 = gameLocal;
  gameLocal = this;
  clientGame = &this->clientGame;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v3 = v1->navPowerInstance;
    if ( v3 != nullptr )
      idNavPowerInstance::MakeActive(this: v3, lockInstance: false);
  }
}


// ========================================================================
// ?GetViewCallbacks@idGameLocal@@UAAABV?$idList@PAVidViewCallbacks@@$04@@XZ
// EA  : 0x82D77FB8
// RVA : 0x00D77FB8
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

const idList<idViewCallbacks *,5> *__fastcall idGameLocal::GetViewCallbacks(idGameLocal *this)
{
  idGameLocal *v1; // r30
  idClientGame *p_clientGame; // r27
  idNavPowerInstance *navPowerInstance; // r3
  const idList<idViewCallbacks *,5> *LocalViewCallbacks; // r27
  idNavPowerInstance *v5; // r3

  v1 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    if ( navPowerInstance != nullptr )
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
  }
  LocalViewCallbacks = idClientGame::GetLocalViewCallbacks(this: p_clientGame);
  gameLocal = v1;
  clientGame = v1 == nullptr ? nullptr : &v1->clientGame;
  if ( v1 != nullptr )
  {
    v5 = v1->navPowerInstance;
    if ( v5 != nullptr )
      idNavPowerInstance::MakeActive(this: v5, lockInstance: false);
  }
  return LocalViewCallbacks;
}


// ========================================================================
// __unwind$488774_0
// EA  : 0x82D78064
// RVA : 0x00D78064
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_488774_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 160 + 80));
}


// ========================================================================
// ?HandleGuiEvent@idGameLocal@@UAA_NPBUsysEvent_t@@H@Z
// EA  : 0x82D78098
// RVA : 0x00D78098
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

int __fastcall idGameLocal::HandleGuiEvent(idGameLocal *this, const sysEvent_t *event, int playerNum)
{
  idGameLocal *v3; // r29
  idClientGame *p_clientGame; // r26
  idNavPowerInstance *navPowerInstance; // r3
  idPlayer *Player; // r3
  BOOL v11; // r30
  idNavPowerInstance *v12; // r3
  idGameLock v13; // [sp+50h] [-60h] BYREF
  idNavPowerInstance *v14; // [sp+54h] [-5Ch]

  v3 = gameLocal;
  p_clientGame = &this->clientGame;
  clientGame = &this->clientGame;
  v13.prevGame = gameLocal;
  gameLocal = this;
  if ( this != nullptr )
  {
    navPowerInstance = this->navPowerInstance;
    v14 = navPowerInstance;
    if ( navPowerInstance != nullptr )
    {
      v14 = navPowerInstance;
      idNavPowerInstance::MakeActive(this: navPowerInstance, lockInstance: false);
    }
  }
  Player = idGameLocal::GetPlayer(this, i: playerNum);
  if ( Player != nullptr && Player->HandleGuiEvent(this: Player, a2: event) )
  {
    idGameLock::~idGameLock(this: &v13);
    return 1;
  }
  else
  {
    v11 = idClientGame::HandleGuiEventForPlayer(this: p_clientGame, playerNum, ev: event);
    gameLocal = v3;
    clientGame = v3 == nullptr ? nullptr : &v3->clientGame;
    if ( v3 != nullptr )
    {
      v12 = v3->navPowerInstance;
      if ( v12 != nullptr )
        idNavPowerInstance::MakeActive(this: v12, lockInstance: false);
    }
    return v11;
  }
}


// ========================================================================
// __unwind$488828_0
// EA  : 0x82D7819C
// RVA : 0x00D7819C
// PDB : w:\tech5\tungsten\game\game_exposed.cpp
// ========================================================================

void _unwind_488828_0()
{
  int v0; // r12

  idGameLock::~idGameLock(this: (idGameLock *)(v0 - 176 + 80));
}

