
// ========================================================================
// ?FadeInLogScale@musicManager@@QAAXVssEntity@@M_N@Z
// EA  : 0x82EF0FE8
// RVA : 0x00EF0FE8
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManager::FadeInLogScale(
        musicManager *this,
        ssEntity *speaker,
        long double duration,
        bool constantVoltage,
        unsigned __int8 a5,
        long double a6)
{
  double v6; // fp29
  int v7; // r28
  char v9; // r30
  long double v10; // fp2
  double v11; // fp31
  __int64 v12; // r9
  long double v13; // fp2
  long double v14; // fp2
  double v15; // fp1

  v6 = *(double *)&duration;
  v7 = a5;
  v9 = 0;
  *(_QWORD *)&duration = 0x4024000000000000LL;
  if ( a5 != 0 )
    *((_QWORD *)&duration + 1) = 0xC0079999A0000000uLL;
  else
    *((_QWORD *)&duration + 1) = 0xC0179999A0000000uLL;
  v10 = pow(x: duration, y: a6);
  v11 = (float)*(double *)&v10;
  do
  {
    LODWORD(v12) = gameInterface->GetFrameTime(this: gameInterface);
    v11 = (float)((float)((float)((float)v12 * (float)((float)1.0 / (float)v6)) * (float)0.001) + (float)v11);
    if ( v11 > 1.0 )
    {
      v11 = 1.0;
      v9 = 1;
    }
    *(double *)&v13 = v11;
    v14 = log10(x: v13);
    if ( v7 != 0 )
      v15 = (float)((float)*(double *)&v14 * (float)20.0);
    else
      v15 = (float)((float)*(double *)&v14 * (float)10.0);
    ssEntity::FadeSound(this: speaker, channel: 54, to: v15, over: 0.0);
    gameInterface->WaitFrame(this: gameInterface);
  }
  while ( v9 == 0 );
}


// ========================================================================
// ?FadeOutLogScale@musicManager@@QAAXVssEntity@@M_N@Z
// EA  : 0x82EF1110
// RVA : 0x00EF1110
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManager::FadeOutLogScale(
        musicManager *this,
        ssEntity *speaker,
        long double duration,
        bool constantVoltage,
        unsigned __int8 a5,
        long double a6)
{
  double v6; // fp30
  int v7; // r28
  char v9; // r30
  double v10; // fp31
  long double v11; // fp2
  double v12; // fp29
  __int64 v13; // r9
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp1

  v6 = *(double *)&duration;
  v7 = a5;
  v9 = 0;
  v10 = 1.0;
  *(_QWORD *)&duration = 0x4024000000000000LL;
  if ( a5 != 0 )
    *((_QWORD *)&duration + 1) = 0xC0079999A0000000uLL;
  else
    *((_QWORD *)&duration + 1) = 0xC0179999A0000000uLL;
  v11 = pow(x: duration, y: a6);
  v12 = (float)*(double *)&v11;
  do
  {
    LODWORD(v13) = gameInterface->GetFrameTime(this: gameInterface);
    v10 = (float)-(float)((float)((float)((float)v13 * (float)((float)1.0 / (float)v6)) * (float)0.001) - (float)v10);
    if ( v10 < v12 )
    {
      v10 = v12;
      v9 = 1;
    }
    *(double *)&v14 = v10;
    v15 = log10(x: v14);
    if ( v7 != 0 )
      v16 = (float)((float)*(double *)&v15 * (float)20.0);
    else
      v16 = (float)((float)*(double *)&v15 * (float)10.0);
    ssEntity::FadeSound(this: speaker, channel: 54, to: v16, over: 0.0);
    gameInterface->WaitFrame(this: gameInterface);
  }
  while ( v9 == 0 );
}


// ========================================================================
// ?GetTransition@musicManager@@QAA?AUtensionTransition_t@@W4musicTensionStates_t@@0@Z
// EA  : 0x82EF1238
// RVA : 0x00EF1238
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

musicManager *__fastcall musicManager::GetTransition(
        musicManager *this,
        tensionTransition_t *result,
        unsigned int fromState,
        musicTensionStates_t toState)
{
  idSoundShader *v4; // r10
  idSoundShader *v5; // r10
  idSoundShader *v6; // r10
  idSoundShader *v7; // r10
  idSoundShader *v8; // r10
  idSoundShader *transitionMusic; // r10
  idSoundShader *v10; // r10
  idSoundShader *v11; // r10
  idSoundShader *v12; // r10
  idSoundShader *v13; // r10
  idSoundShader *v14; // r10
  float fadeTime; // r11

  if ( fromState > 3 )
    goto LABEL_28;
  switch ( fromState )
  {
    case 1u:
      goto LABEL_11;
    case 2u:
LABEL_16:
      switch ( toState )
      {
        case MUSIC_TENSION_STATE_OFF:
          transitionMusic = result[13].transitionMusic;
          this->__vftable = (musicManager_vtbl *)LODWORD(result[12].fadeTime);
          this->self.spawnId = (int)transitionMusic;
          return this;
        case MUSIC_TENSION_STATE_LOW:
          v10 = result[12].transitionMusic;
          this->__vftable = (musicManager_vtbl *)LODWORD(result[11].fadeTime);
          this->self.spawnId = (int)v10;
          return this;
        case MUSIC_TENSION_STATE_HIGH:
          v11 = result[8].transitionMusic;
          this->__vftable = (musicManager_vtbl *)LODWORD(result[7].fadeTime);
          this->self.spawnId = (int)v11;
          return this;
        default:
          break;
      }
      break;
    case 0u:
      if ( toState != MUSIC_TENSION_STATE_LOW )
      {
        if ( toState == MUSIC_TENSION_STATE_MEDIUM )
        {
          v5 = result[4].transitionMusic;
          this->__vftable = (musicManager_vtbl *)LODWORD(result[3].fadeTime);
          this->self.spawnId = (int)v5;
          return this;
        }
        if ( toState == MUSIC_TENSION_STATE_HIGH )
        {
          v6 = result[5].transitionMusic;
          this->__vftable = (musicManager_vtbl *)LODWORD(result[4].fadeTime);
          this->self.spawnId = (int)v6;
          return this;
        }
LABEL_11:
        switch ( toState )
        {
          case MUSIC_TENSION_STATE_OFF:
            goto LABEL_28;
          case MUSIC_TENSION_STATE_MEDIUM:
            v7 = result[6].transitionMusic;
            this->__vftable = (musicManager_vtbl *)LODWORD(result[5].fadeTime);
            this->self.spawnId = (int)v7;
            return this;
          case MUSIC_TENSION_STATE_HIGH:
            v8 = result[7].transitionMusic;
            this->__vftable = (musicManager_vtbl *)LODWORD(result[6].fadeTime);
            this->self.spawnId = (int)v8;
            return this;
          default:
            break;
        }
        goto LABEL_16;
      }
      v4 = result[3].transitionMusic;
      this->__vftable = (musicManager_vtbl *)LODWORD(result[2].fadeTime);
      this->self.spawnId = (int)v4;
      return this;
    default:
      break;
  }
  switch ( toState )
  {
    case MUSIC_TENSION_STATE_OFF:
      v12 = result[11].transitionMusic;
      this->__vftable = (musicManager_vtbl *)LODWORD(result[10].fadeTime);
      this->self.spawnId = (int)v12;
      return this;
    case MUSIC_TENSION_STATE_LOW:
      v13 = result[10].transitionMusic;
      this->__vftable = (musicManager_vtbl *)LODWORD(result[9].fadeTime);
      this->self.spawnId = (int)v13;
      return this;
    case MUSIC_TENSION_STATE_MEDIUM:
      v14 = result[9].transitionMusic;
      this->__vftable = (musicManager_vtbl *)LODWORD(result[8].fadeTime);
      this->self.spawnId = (int)v14;
      return this;
    default:
      break;
  }
LABEL_28:
  fadeTime = result[13].fadeTime;
  this->self.spawnId = (int)result[14].transitionMusic;
  *(float *)&this->__vftable = fadeTime;
  return this;
}


// ========================================================================
// ?Init@musicManagerSwitch@@UAAXXZ
// EA  : 0x82EF13B0
// RVA : 0x00EF13B0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManagerSwitch::Init(musicManagerSwitch *this)
{
  int v2; // r9
  char v3; // r11
  const ssString *v4; // r3
  const ssString *v5; // r30
  ssString *v6; // r3
  const ssString *v7; // r3
  const ssString *v8; // r3
  const ssString *v9; // r3
  ssString *v10; // r3
  ssString *v11; // r3
  char v12; // r3
  char v13; // r11
  const ssString *v14; // r3
  const ssString *v15; // r30
  ssString *v16; // r3
  const ssString *v17; // r3
  const ssString *v18; // r3
  const ssString *v19; // r3
  ssString *v20; // r3
  ssString v21; // [sp+60h] [-120h] BYREF
  ssString v22; // [sp+70h] [-110h] BYREF
  cvarInt_ v23; // [sp+80h] [-100h] BYREF
  cvarInt_ v24; // [sp+90h] [-F0h] BYREF
  ssString v25; // [sp+A0h] [-E0h] BYREF
  ssString v26; // [sp+B0h] [-D0h] BYREF
  ssString v27; // [sp+C0h] [-C0h] BYREF
  ssString v28; // [sp+D0h] [-B0h] BYREF
  ssString v29; // [sp+E0h] [-A0h] BYREF
  ssString v30; // [sp+F0h] [-90h] BYREF
  ssString v31; // [sp+100h] [-80h] BYREF
  ssString v32; // [sp+110h] [-70h] BYREF
  ssString v33; // [sp+120h] [-60h] BYREF
  ssString v34; // [sp+130h] [-50h] BYREF
  ssString v35; // [sp+140h] [-40h] BYREF
  ssString v36[3]; // [sp+150h] [-30h] BYREF

  if ( this->old_manager.spawnId == 0
    || (v2 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v3 = 1,
        v2 == 0) )
  {
    v3 = 0;
  }
  if ( v3 == 0 )
  {
    cvarInt_::cvarInt_(this: &v23, name_: "ss_debugPrint", default_: 1);
    if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v23.name, a3: v23.defValue) <= 0 )
      return;
    ssString::ssString(this: &v31, i: 402);
    v5 = v4;
    ssString::Init(this: &v22);
    ssString::operator=(this: &v22, text: "musicManagerSwitch::Init");
    v6 = operator+(result: &v33, a: "^1", b: &v22);
    v7 = operator+(result: &v25, a: v6, b: "::");
    v8 = operator+(result: &v35, a: v7, b: v5);
    v9 = operator+(result: &v27, a: v8, b: "^0 : ");
    v10 = operator+(result: &v29, a: v9, b: "musicModifier: old_manager is not valid");
    gameInterface->Printf(this: gameInterface, a2: "%s\n", v10->data);
    ssString::Empty(this: &v29);
    ssString::Empty(this: &v27);
    ssString::Empty(this: &v35);
    ssString::Empty(this: &v25);
    ssString::Empty(this: &v33);
    ssString::Empty(this: &v22);
    v11 = &v31;
    goto _M20090;
  }
  if ( this->new_manager.spawnId == 0
    || (v12 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v13 = 1,
        v12 == 0) )
  {
    v13 = 0;
  }
  if ( v13 == 0 )
  {
    cvarInt_::cvarInt_(this: &v24, name_: "ss_debugPrint", default_: 1);
    if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v24.name, a3: v24.defValue) > 0 )
    {
      ssString::ssString(this: v36, i: 407);
      v15 = v14;
      ssString::Init(this: &v21);
      ssString::operator=(this: &v21, text: "musicManagerSwitch::Init");
      v16 = operator+(result: &v34, a: "^1", b: &v21);
      v17 = operator+(result: &v32, a: v16, b: "::");
      v18 = operator+(result: &v30, a: v17, b: v15);
      v19 = operator+(result: &v28, a: v18, b: "^0 : ");
      v20 = operator+(result: &v26, a: v19, b: "musicModifier: new_manager is not valid");
      gameInterface->Printf(this: gameInterface, a2: "%s\n", v20->data);
      ssString::Empty(this: &v26);
      ssString::Empty(this: &v28);
      ssString::Empty(this: &v30);
      ssString::Empty(this: &v32);
      ssString::Empty(this: &v34);
      ssString::Empty(this: &v21);
      v11 = v36;
_M20090:
      ssString::Empty(this: v11);
    }
  }
}


// ========================================================================
// __unwind$19937
// EA  : 0x82EF1698
// RVA : 0x00EF1698
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19937()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 256));
}


// ========================================================================
// __unwind$19938
// EA  : 0x82EF16C0
// RVA : 0x00EF16C0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19938()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 112));
}


// ========================================================================
// __unwind$19939
// EA  : 0x82EF16E8
// RVA : 0x00EF16E8
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19939()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 288));
}


// ========================================================================
// __unwind$19940
// EA  : 0x82EF1710
// RVA : 0x00EF1710
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19940()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$19941
// EA  : 0x82EF1738
// RVA : 0x00EF1738
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19941()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 320));
}


// ========================================================================
// __unwind$19942
// EA  : 0x82EF1760
// RVA : 0x00EF1760
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19942()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$19943
// EA  : 0x82EF1788
// RVA : 0x00EF1788
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19943()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 224));
}


// ========================================================================
// __unwind$19944
// EA  : 0x82EF17B0
// RVA : 0x00EF17B0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19944()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 336));
}


// ========================================================================
// __unwind$19945
// EA  : 0x82EF17D8
// RVA : 0x00EF17D8
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19945()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$19946
// EA  : 0x82EF1800
// RVA : 0x00EF1800
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19946()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 304));
}


// ========================================================================
// __unwind$19947
// EA  : 0x82EF1828
// RVA : 0x00EF1828
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19947()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 272));
}


// ========================================================================
// __unwind$19948
// EA  : 0x82EF1850
// RVA : 0x00EF1850
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19948()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 240));
}


// ========================================================================
// __unwind$19949
// EA  : 0x82EF1878
// RVA : 0x00EF1878
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19949()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 208));
}


// ========================================================================
// __unwind$19950
// EA  : 0x82EF18A0
// RVA : 0x00EF18A0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_19950()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 384 + 176));
}


// ========================================================================
// ?Init@musicManager@@UAAXXZ
// EA  : 0x82EF1C10
// RVA : 0x00EF1C10
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManager::Init(musicManager *this)
{
  XGRAPHICS::Compiler *v2; // r3
  const ssEntity *v3; // r3
  XGRAPHICS::Compiler *v4; // r3
  const ssEntity *v5; // r3
  XGRAPHICS::Compiler *v6; // r3
  const ssEntity *v7; // r3
  XGRAPHICS::VRegTable v8; // [sp+50h] [-40h] BYREF

  v2 = (XGRAPHICS::Compiler *)gameInterface->SpawnFromDecl(this: gameInterface, a2: this->infoNull);
  v3 = (const ssEntity *)ssEntity::ssEntity(this: &v8, context: v2);
  ssEntity::ssEntity(this: &this->eLowSpeaker, e: v3);
  v4 = (XGRAPHICS::Compiler *)gameInterface->SpawnFromDecl(this: gameInterface, a2: this->infoNull);
  v5 = (const ssEntity *)ssEntity::ssEntity(this: &v8, context: v4);
  ssEntity::ssEntity(this: &this->eMediumSpeaker, e: v5);
  v6 = (XGRAPHICS::Compiler *)gameInterface->SpawnFromDecl(this: gameInterface, a2: this->infoNull);
  v7 = (const ssEntity *)ssEntity::ssEntity(this: &v8, context: v6);
  ssEntity::ssEntity(this: &this->eHighSpeaker, e: v7);
  if ( gameInterface->GetCVarInteger(
         this: gameInterface,
         a2: ss_musicTestManager.name,
         a3: ss_musicTestManager.defValue) != 0 )
  {
    ssString::Init(this: (ssString *)&v8.constants_3);
    ssString::operator=(this: (ssString *)&v8.constants_3, text: "DebugUpdate");
    idSuperScriptObject::CreateThreadNamed(this, threadName: (ssString *)&v8.constants_3, f: musicManager::DebugUpdate);
  }
}


// ========================================================================
// ?ChangeState@musicManager@@QAAXW4musicTensionStates_t@@UtensionTransition_t@@@Z
// EA  : 0x82EF1D38
// RVA : 0x00EF1D38
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManager::ChangeState(musicManager *this, __int64 overrideTransition)
{
  musicTensionStates_t v3; // r26
  const ssString *v4; // r3
  ssString *v5; // r3
  musicTensionStates_t currentTensionLevel; // r5
  int v7; // r5
  idSoundShader *lowTensionMusic; // r4
  idSoundShader *medTensionMusic; // r4
  idSoundShader *highTensionMusic; // r4
  musicTensionStates_t v11; // r11
  ssEntity *p_eLowSpeaker; // r4
  ssEntity *p_eMediumSpeaker; // r4
  idSoundShader *v14; // r27
  int v15; // r9
  char v16; // r11
  int v17; // r9
  char v18; // r11
  XGRAPHICS::Compiler *v19; // r3
  char v20; // [sp+50h] [-E0h] BYREF
  char v21; // [sp+51h] [-DFh] BYREF
  idStreamFileLog v22; // [sp+54h] [-DCh] BYREF
  char *v23; // [sp+7Ch] [-B4h]
  ssString v24; // [sp+80h] [-B0h] BYREF
  ssString v25; // [sp+90h] [-A0h] BYREF
  ssString v26; // [sp+A0h] [-90h] BYREF
  ssString v27; // [sp+B0h] [-80h] BYREF
  ssString v28; // [sp+C0h] [-70h] BYREF
  ssString v29; // [sp+D0h] [-60h] BYREF

  v3 = HIDWORD(overrideTransition);
  ssString::ssString(this: &v29, i: SHIDWORD(overrideTransition));
  v5 = operator+(result: &v28, a: "Music Manager: Changing to new state, ", b: v4);
  gameInterface->Printf(this: gameInterface, a2: "%s\n", v5->data);
  ssString::Empty(this: &v28);
  ssString::Empty(this: &v29);
  currentTensionLevel = this->currentTensionLevel;
  if ( v3 == currentTensionLevel )
  {
    ssString::Init(this: &v24);
    ssString::operator=(this: &v24, text: "Music Manager: Requested same level, bailing request.");
    gameInterface->Printf(this: gameInterface, a2: "%s\n", v24.data);
    ssString::Empty(this: &v24);
    return;
  }
  musicManager::GetTransition(
    this: (musicManager *)v22.currentEntry,
    result: (tensionTransition_t *)this,
    fromState: currentTensionLevel,
    toState: v3);
  if ( v7 == 0 )
  {
    lowTensionMusic = this->lowTensionMusic;
    if ( lowTensionMusic != nullptr )
    {
      ssEntity::StartSoundShader(this: &this->eLowSpeaker, shader: lowTensionMusic, channel: 54);
      ssEntity::FadeSound(this: &this->eLowSpeaker, channel: 54, to: -59.0, over: 0.0);
    }
    medTensionMusic = this->medTensionMusic;
    if ( medTensionMusic != nullptr )
    {
      ssEntity::StartSoundShader(this: &this->eMediumSpeaker, shader: medTensionMusic, channel: 54);
      ssEntity::FadeSound(this: &this->eMediumSpeaker, channel: 54, to: -59.0, over: 0.0);
    }
    highTensionMusic = this->highTensionMusic;
    if ( highTensionMusic != nullptr )
    {
      ssEntity::StartSoundShader(this: &this->eHighSpeaker, shader: highTensionMusic, channel: 54);
      ssEntity::FadeSound(this: &this->eHighSpeaker, channel: 54, to: -59.0, over: 0.0);
    }
  }
  v11 = this->currentTensionLevel;
  switch ( v11 )
  {
    case MUSIC_TENSION_STATE_LOW:
      p_eLowSpeaker = &this->eLowSpeaker;
      break;
    case MUSIC_TENSION_STATE_MEDIUM:
      p_eLowSpeaker = &this->eMediumSpeaker;
      break;
    case MUSIC_TENSION_STATE_HIGH:
      p_eLowSpeaker = &this->eHighSpeaker;
      break;
    default:
      idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&v22.maxEntries);
      goto LABEL_18;
  }
  ssEntity::ssEntity(this: (ssEntity *)&v22.maxEntries, e: p_eLowSpeaker);
LABEL_18:
  switch ( v3 )
  {
    case MUSIC_TENSION_STATE_LOW:
      p_eMediumSpeaker = &this->eLowSpeaker;
      goto LABEL_25;
    case MUSIC_TENSION_STATE_MEDIUM:
      p_eMediumSpeaker = &this->eMediumSpeaker;
      goto LABEL_25;
    case MUSIC_TENSION_STATE_HIGH:
      p_eMediumSpeaker = &this->eHighSpeaker;
LABEL_25:
      ssEntity::ssEntity(this: (ssEntity *)&v22, e: p_eMediumSpeaker);
      goto LABEL_26;
    default:
      break;
  }
  idMD6PhaseTrack::idMD6PhaseTrack(this: &v22);
LABEL_26:
  v14 = (idSoundShader *)v22.currentEntry[0];
  v22.entries = v22.currentEntry[1];
  if ( *((float *)&overrideTransition + 1) >= 0.0 )
    v22.entries = (sflEntry_t *)overrideTransition;
  if ( HIDWORD(overrideTransition) != 0 )
    v14 = (idSoundShader *)HIDWORD(overrideTransition);
  if ( v22.numEntries == 0
    || (v15 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v16 = 1,
        v15 == 0) )
  {
    v16 = 0;
  }
  if ( v16 != 0 )
  {
    v20 = 1;
    ssString::Init(this: &v25);
    ssString::operator=(this: &v25, text: "FadeInLogScale");
    v22.currentEntry[1] = (sflEntry_t *)&v22;
    v22.currentEntry[0] = (sflEntry_t *)musicManager::FadeInLogScale;
    v22.currentEntry[2] = (sflEntry_t *)&v22.entries;
    v23 = &v20;
    gameInterface->CreateThread(
      this: gameInterface,
      a2: v25.data,
      a3: this,
      a4: idSuperScriptObject::threadData3_t<ssEntity,float,bool>::proxyFunc,
      a5: v22.currentEntry);
    ssString::Empty(this: &v25);
  }
  if ( v22.maxEntries == 0
    || (v17 = ((unsigned __int8 (__fastcall *)(idGameSuperInterface *))gameInterface->EntityIsValid)(a1: gameInterface),
        v18 = 1,
        v17 == 0) )
  {
    v18 = 0;
  }
  if ( v18 != 0 )
  {
    v21 = 1;
    ssString::Init(this: &v26);
    ssString::operator=(this: &v26, text: "FadeOutLogScale");
    v22.currentEntry[2] = (sflEntry_t *)&v22.entries;
    v22.currentEntry[0] = (sflEntry_t *)musicManager::FadeOutLogScale;
    v23 = &v21;
    v22.currentEntry[1] = (sflEntry_t *)&v22.maxEntries;
    gameInterface->CreateThread(
      this: gameInterface,
      a2: v26.data,
      a3: this,
      a4: idSuperScriptObject::threadData3_t<ssEntity,float,bool>::proxyFunc,
      a5: v22.currentEntry);
    ssString::Empty(this: &v26);
  }
  if ( v14 != nullptr )
  {
    v19 = (XGRAPHICS::Compiler *)gameInterface->SpawnFromDecl(this: gameInterface, a2: this->infoNull);
    ssEntity::ssEntity(this: (XGRAPHICS::VRegTable *)&v22.mutex, context: v19);
    *(float *)v22.driveState = ssEntity::StartSoundShader(this: (ssEntity *)&v22.mutex, shader: v14, channel: 54);
    ssString::Init(this: &v27);
    ssString::operator=(this: &v27, text: "DelayRemoval");
    v22.currentEntry[1] = (sflEntry_t *)&v22.mutex;
    v22.currentEntry[0] = (sflEntry_t *)musicManager::DelayRemoval;
    v22.currentEntry[2] = (sflEntry_t *)v22.driveState;
    gameInterface->CreateThread(
      this: gameInterface,
      a2: v27.data,
      a3: this,
      a4: idSuperScriptObject::threadData2_t<ssEntity,float>::proxyFunc,
      a5: v22.currentEntry);
    ssString::Empty(this: &v27);
  }
  this->currentTensionLevel = v3;
  if ( v3 == MUSIC_TENSION_STATE_OFF )
  {
    gameInterface->Wait(this: gameInterface, a2: *(float *)&v22.entries);
    if ( this->currentTensionLevel == MUSIC_TENSION_STATE_OFF )
    {
      ssEntity::StopSound(this: &this->eLowSpeaker, channel: 54, netSync: 0);
      ssEntity::StopSound(this: &this->eMediumSpeaker, channel: 54, netSync: 0);
      ssEntity::StopSound(this: &this->eHighSpeaker, channel: 54, netSync: 0);
    }
  }
}


// ========================================================================
// __unwind$20315
// EA  : 0x82EF21D4
// RVA : 0x00EF21D4
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20315()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 208));
}


// ========================================================================
// __unwind$20316
// EA  : 0x82EF21FC
// RVA : 0x00EF21FC
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20316()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 192));
}


// ========================================================================
// __unwind$20317
// EA  : 0x82EF2224
// RVA : 0x00EF2224
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20317()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$20318
// EA  : 0x82EF224C
// RVA : 0x00EF224C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20318()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$20319
// EA  : 0x82EF2274
// RVA : 0x00EF2274
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20319()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$20320
// EA  : 0x82EF229C
// RVA : 0x00EF229C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20320()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 304 + 176));
}


// ========================================================================
// ?Init@musicModifier@@UAAXXZ
// EA  : 0x82EF22D0
// RVA : 0x00EF22D0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicModifier::Init(musicModifier *this)
{
  ssString *v2; // r3
  const ssString *v3; // r3
  const ssString *v4; // r29
  ssString *v5; // r3
  const ssString *v6; // r3
  const ssString *v7; // r3
  const ssString *v8; // r3
  ssString *v9; // r3
  const ssString *v10; // r3
  const ssString *v11; // r29
  ssString *v12; // r3
  const ssString *v13; // r3
  const ssString *v14; // r3
  const ssString *v15; // r3
  ssString *v16; // r3
  ssList<ssEntity> v17; // [sp+50h] [-140h] BYREF
  ssString v18; // [sp+60h] [-130h] BYREF
  ssString v19; // [sp+70h] [-120h] BYREF
  ssEntity v20; // [sp+80h] [-110h] BYREF
  cvarInt_ v21; // [sp+90h] [-100h] BYREF
  cvarInt_ v22; // [sp+A0h] [-F0h] BYREF
  ssString v23; // [sp+B0h] [-E0h] BYREF
  ssString v24; // [sp+C0h] [-D0h] BYREF
  ssString v25; // [sp+D0h] [-C0h] BYREF
  ssString v26; // [sp+E0h] [-B0h] BYREF
  ssString v27; // [sp+F0h] [-A0h] BYREF
  ssString v28; // [sp+100h] [-90h] BYREF
  ssString v29; // [sp+110h] [-80h] BYREF
  ssString v30; // [sp+120h] [-70h] BYREF
  ssString v31; // [sp+130h] [-60h] BYREF
  ssString v32; // [sp+140h] [-50h] BYREF
  ssString v33; // [sp+150h] [-40h] BYREF
  ssString v34[3]; // [sp+160h] [-30h] BYREF

  memset(&v17, 0, 12);
  if ( gameInterface != nullptr )
    v17.threadId = gameInterface->GetAllocThread(this: gameInterface);
  else
    v17.threadId = 0;
  ssEntity::ssEntity(this: &v20, e: &this->self);
  ssUtil::FillListFromTargets(dst: &v17, src: v2);
  if ( v17.num <= 1 )
  {
    if ( v17.num >= 1 )
    {
      ssEntity::ssEntity(this: &this->manager, e: v17.data);
    }
    else
    {
      cvarInt_::cvarInt_(this: &v22, name_: "ss_debugPrint", default_: 1);
      if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v22.name, a3: v22.defValue) > 0 )
      {
        ssString::ssString(this: v34, i: 359);
        v11 = v10;
        ssString::Init(this: &v19);
        ssString::operator=(this: &v19, text: "musicModifier::Init");
        v12 = operator+(result: &v32, a: "^1", b: &v19);
        v13 = operator+(result: &v30, a: v12, b: "::");
        v14 = operator+(result: &v28, a: v13, b: v11);
        v15 = operator+(result: &v26, a: v14, b: "^0 : ");
        v16 = operator+(result: &v24, a: v15, b: "musicModifier: modifier has no target");
        gameInterface->Printf(this: gameInterface, a2: "%s\n", v16->data);
        ssString::Empty(this: &v24);
        ssString::Empty(this: &v26);
        ssString::Empty(this: &v28);
        ssString::Empty(this: &v30);
        ssString::Empty(this: &v32);
        ssString::Empty(this: &v19);
        ssString::Empty(this: v34);
      }
    }
  }
  else
  {
    cvarInt_::cvarInt_(this: &v21, name_: "ss_debugPrint", default_: 1);
    if ( gameInterface->GetCVarInteger(this: gameInterface, a2: v21.name, a3: v21.defValue) > 0 )
    {
      ssString::ssString(this: &v29, i: 354);
      v4 = v3;
      ssString::Init(this: &v18);
      ssString::operator=(this: &v18, text: "musicModifier::Init");
      v5 = operator+(result: &v31, a: "^1", b: &v18);
      v6 = operator+(result: &v27, a: v5, b: "::");
      v7 = operator+(result: &v23, a: v6, b: v4);
      v8 = operator+(result: &v25, a: v7, b: "^0 : ");
      v9 = operator+(result: &v33, a: v8, b: "musicModifier: modifier has more than one target");
      gameInterface->Printf(this: gameInterface, a2: "%s\n", v9->data);
      ssString::Empty(this: &v33);
      ssString::Empty(this: &v25);
      ssString::Empty(this: &v23);
      ssString::Empty(this: &v27);
      ssString::Empty(this: &v31);
      ssString::Empty(this: &v18);
      ssString::Empty(this: &v29);
    }
  }
  ssList<ssEntity>::Clear(this: (ssList<float> *)&v17);
}


// ========================================================================
// __unwind$20532
// EA  : 0x82EF25BC
// RVA : 0x00EF25BC
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20532()
{
  int v0; // r12

  ssList<util_debugMetaData::lineInfo_t>::~ssList<util_debugMetaData::lineInfo_t>(this: (ssList<int> *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$20533
// EA  : 0x82EF25E4
// RVA : 0x00EF25E4
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20533()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 272));
}


// ========================================================================
// __unwind$20534
// EA  : 0x82EF260C
// RVA : 0x00EF260C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20534()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$20535
// EA  : 0x82EF2634
// RVA : 0x00EF2634
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20535()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 304));
}


// ========================================================================
// __unwind$20536
// EA  : 0x82EF265C
// RVA : 0x00EF265C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20536()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$20537
// EA  : 0x82EF2684
// RVA : 0x00EF2684
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20537()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$20538
// EA  : 0x82EF26AC
// RVA : 0x00EF26AC
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20538()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$20539
// EA  : 0x82EF26D4
// RVA : 0x00EF26D4
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20539()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 336));
}


// ========================================================================
// __unwind$20540_1
// EA  : 0x82EF26FC
// RVA : 0x00EF26FC
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20540_1()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 352));
}


// ========================================================================
// __unwind$20541_0
// EA  : 0x82EF2724
// RVA : 0x00EF2724
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20541_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$20542
// EA  : 0x82EF274C
// RVA : 0x00EF274C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20542()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 320));
}


// ========================================================================
// __unwind$20543
// EA  : 0x82EF2774
// RVA : 0x00EF2774
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20543()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 288));
}


// ========================================================================
// __unwind$20544
// EA  : 0x82EF279C
// RVA : 0x00EF279C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20544()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 256));
}


// ========================================================================
// __unwind$20545
// EA  : 0x82EF27C4
// RVA : 0x00EF27C4
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20545()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$20546
// EA  : 0x82EF27EC
// RVA : 0x00EF27EC
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20546()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 400 + 192));
}


// ========================================================================
// ?OnActivate@musicModifier@@UAAXVssEntity@@@Z
// EA  : 0x82EF29E0
// RVA : 0x00EF29E0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicModifier::OnActivate(musicModifier *this, ssEntity *activator)
{
  idSoundShader *transitionMusic; // r11
  int *v4; // r3
  int v5; // r3
  musicTensionStates_t newState; // [sp+50h] [-50h] BYREF
  ssEntity v7; // [sp+54h] [-4Ch] BYREF
  tensionTransition_t v8; // [sp+58h] [-48h] BYREF
  ssObjectBase v9; // [sp+60h] [-40h] BYREF
  ssString v10; // [sp+70h] [-30h] BYREF

  transitionMusic = this->transitionMusic;
  v8.fadeTime = this->fadeTime;
  v8.transitionMusic = transitionMusic;
  ssEntity::ssEntity(this: &v7, e: &this->manager);
  v9.spawnId = *v4;
  v5 = gameInterface->FindObject(this: gameInterface, a2: v9.spawnId, a3: "musicManager", a4: false);
  newState = this->newState;
  v9.objectId = v5;
  ssString::Init(this: &v10);
  ssString::operator=(this: &v10, text: "&musicManager::ChangeState");
  ssObjectBase::CreateThreadNamed<enum musicTensionStates_t,tensionTransition_t>(
    this: &v9,
    threadName: &v10,
    f: musicManager::ChangeState,
    p1: &newState,
    p2: &v8);
  ssString::Empty(this: &v10);
}


// ========================================================================
// __unwind$20831_0
// EA  : 0x82EF2AA4
// RVA : 0x00EF2AA4
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20831_0()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// ?OnActivate@musicManagerSwitch@@UAAXVssEntity@@@Z
// EA  : 0x82EF2AD8
// RVA : 0x00EF2AD8
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void __fastcall musicManagerSwitch::OnActivate(musicManagerSwitch *this, ssEntity *activator)
{
  idSoundShader *transitionMusic; // r11
  double fadeTime; // fp0
  int *v5; // r3
  idGameSuperInterface_vtbl *v6; // r11
  int *v7; // r3
  int v8; // r3
  musicTensionStates_t newState; // r9
  ssEntity v10; // [sp+50h] [-80h] BYREF
  musicTensionStates_t v11; // [sp+54h] [-7Ch] BYREF
  tensionTransition_t v12; // [sp+58h] [-78h] BYREF
  ssObjectBase v13; // [sp+60h] [-70h] BYREF
  tensionTransition_t v14; // [sp+68h] [-68h] BYREF
  ssObjectBase v15; // [sp+70h] [-60h] BYREF
  ssString v16; // [sp+80h] [-50h] BYREF
  ssString v17[4]; // [sp+90h] [-40h] BYREF

  transitionMusic = this->transitionMusic;
  fadeTime = this->fadeTime;
  v12.fadeTime = this->fadeTime;
  v14.fadeTime = fadeTime;
  v12.transitionMusic = transitionMusic;
  v14.transitionMusic = transitionMusic;
  ssEntity::ssEntity(this: &v10, e: &this->old_manager);
  v13.spawnId = *v5;
  v13.objectId = gameInterface->FindObject(this: gameInterface, a2: v13.spawnId, a3: "musicManager", a4: false);
  ssEntity::ssEntity(this: &v10, e: &this->new_manager);
  v6 = gameInterface->__vftable;
  v15.spawnId = *v7;
  v8 = ((int (*)(void))v6->FindObject)();
  newState = this->newState;
  v15.objectId = v8;
  v10.spawnId = 0;
  v11 = newState;
  ssString::Init(this: &v16);
  ssString::operator=(this: &v16, text: "&musicManager::ChangeState");
  ssObjectBase::CreateThreadNamed<enum musicTensionStates_t,tensionTransition_t>(
    this: &v13,
    threadName: &v16,
    f: musicManager::ChangeState,
    p1: (const musicTensionStates_t *)&v10,
    p2: &v12);
  ssString::Empty(this: &v16);
  ssString::Init(this: v17);
  ssString::operator=(this: v17, text: "&musicManager::ChangeState");
  ssObjectBase::CreateThreadNamed<enum musicTensionStates_t,tensionTransition_t>(
    this: &v15,
    threadName: v17,
    f: musicManager::ChangeState,
    p1: &v11,
    p2: &v14);
  ssString::Empty(this: v17);
}


// ========================================================================
// __unwind$20879
// EA  : 0x82EF2C0C
// RVA : 0x00EF2C0C
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20879()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 128));
}


// ========================================================================
// __unwind$20880
// EA  : 0x82EF2C34
// RVA : 0x00EF2C34
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _unwind_20880()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 208 + 144));
}


// ========================================================================
// `dynamic initializer for 'ss_musicState''
// EA  : 0x83393E30
// RVA : 0x01393E30
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _dynamic_initializer_for__ss_musicState__()
{
  if ( gameInterface != nullptr )
  {
    cvarInt_::RegisterCVar(this: &ss_musicState);
  }
  else
  {
    ss_musicState.nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = &ss_musicState;
  }
}


// ========================================================================
// `dynamic initializer for 'ss_musicTestManager''
// EA  : 0x83393E78
// RVA : 0x01393E78
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _dynamic_initializer_for__ss_musicTestManager__()
{
  if ( gameInterface != nullptr )
  {
    cvarInt_::RegisterCVar(this: &ss_musicTestManager);
  }
  else
  {
    ss_musicTestManager.nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = &ss_musicTestManager;
  }
}


// ========================================================================
// `dynamic initializer for 'ss_musicTestEnt''
// EA  : 0x83393EC0
// RVA : 0x01393EC0
// PDB : w:\tech5\tungsten\superscript\util\musicmanager.cpp
// ========================================================================

void _dynamic_initializer_for__ss_musicTestEnt__()
{
  if ( gameInterface != nullptr )
  {
    cvarString_::RegisterCVar(this: &ss_musicTestEnt);
  }
  else
  {
    ss_musicTestEnt.nextStaticCVar = cvar_::staticCVars;
    cvar_::staticCVars = &ss_musicTestEnt;
  }
}

