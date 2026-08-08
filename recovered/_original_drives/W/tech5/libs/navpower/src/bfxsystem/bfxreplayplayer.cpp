
// ========================================================================
// ?ParseNextEvent@ReplayParser@bfx@@QAAXXZ
// EA  : 0x832971E8
// RVA : 0x012971E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

void __fastcall bfx::ReplayParser::ParseNextEvent(bfx::ReplayParser *this)
{
  this->m_pLog->CloseLogEvent(this: this->m_pLog);
  if ( this->m_pLog->OpenLogEvent(
         this: this->m_pLog,
         a2: (bfx::ComponentID *)&this->m_currentInfo,
         a3: &this->m_currentInfo.m_eventID,
         a4: &this->m_currentInfo.m_version,
         a5: &this->m_currentInfo.m_time) )
  {
    this->m_pCurrentInfo = &this->m_currentInfo;
  }
  else
  {
    this->m_pCurrentInfo = nullptr;
  }
}


// ========================================================================
// ?CompareRegistration@ReplayPlayer@bfx@@SAHPBX0@Z
// EA  : 0x83297270
// RVA : 0x01297270
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

int __fastcall bfx::ReplayPlayer::CompareRegistration(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13

  v2 = a[4];
  v3 = b[4];
  if ( v2 >= v3 )
    return v2 > v3;
  else
    return -1;
}


// ========================================================================
// ?IsReplayPlaybackEnabled@bfx@@YA_NXZ
// EA  : 0x832972A0
// RVA : 0x012972A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

BOOL __fastcall bfx::IsReplayPlaybackEnabled()
{
  return bfx::g_pCurInstance->m_pReplayPlayer->m_pParser != nullptr;
}


// ========================================================================
// ?FindComponent@ReplayPlayer@bfx@@ABAPBVRegistration@12@W4ComponentID@2@@Z
// EA  : 0x83297468
// RVA : 0x01297468
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

const bfx::ReplayPlayer::Registration *__fastcall bfx::ReplayPlayer::FindComponent(
        bfx::ReplayPlayer *this,
        bfx::ComponentID componentID)
{
  int m_size; // r8
  int v3; // r10
  bfx::ReplayPlayer::Registration *m_data; // r9
  int i; // r11

  m_size = this->m_registry.m_size;
  v3 = 0;
  if ( m_size <= 0 )
    return nullptr;
  m_data = this->m_registry.m_data;
  for ( i = 0; m_data[i].m_id != componentID; ++i )
  {
    if ( ++v3 >= m_size )
      return nullptr;
  }
  return &m_data[v3];
}


// ========================================================================
// ?RegisterReplayComponent@ReplayPlayer@bfx@@QAA_NW4ComponentID@2@P6A_NGIPAVReplayLogIn@2@PAX@ZP6AXXZP6APBDG@ZM@Z
// EA  : 0x832974B8
// RVA : 0x012974B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

int __fastcall bfx::ReplayPlayer::RegisterReplayComponent(
        bfx::ReplayPlayer *this,
        bfx::ComponentID id,
        bool (__fastcall *replayCB)(unsigned __int16, unsigned int, bfx::ReplayLogIn *, void *),
        void (__fastcall *clearCB)(),
        const char *(__fastcall *getNameCB)(unsigned __int16),
        double priority)
{
  int m_size; // r9
  int v7; // r11
  bfx::ReplayPlayer::Registration *m_data; // r8
  int v9; // r10
  bfx::ReplayPlayer::Registration v11; // [sp+50h] [-30h] BYREF

  m_size = this->m_registry.m_size;
  v7 = 0;
  if ( m_size > 0 )
  {
    m_data = this->m_registry.m_data;
    v9 = 0;
    while ( m_data[v9].m_id != id )
    {
      ++v7;
      ++v9;
      if ( v7 >= m_size )
        goto LABEL_5;
    }
    if ( &m_data[v7] != nullptr )
      return 0;
  }
LABEL_5:
  v11.m_id = id;
  v11.m_priority = priority;
  v11.m_replayCB = replayCB;
  v11.m_clearCB = clearCB;
  v11.m_getNameCB = getNameCB;
  bfx::Array<bfx::ReplayPlayer::Registration>::push_back(this: &this->m_registry, val: &v11);
  return 1;
}


// ========================================================================
// ?Stop@ReplayPlayer@bfx@@QAAXXZ
// EA  : 0x83297560
// RVA : 0x01297560
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

void __fastcall bfx::ReplayPlayer::Stop(bfx::ReplayPlayer *this)
{
  char *m_pParser; // r30
  signed int m_size; // r4
  int v4; // r29
  int v5; // r30

  m_pParser = (char *)this->m_pParser;
  if ( m_pParser != nullptr )
  {
    if ( *(_DWORD *)m_pParser != 0 )
      (***(void (__fastcall ****)(_DWORD, int))m_pParser)(a1: *(_DWORD *)m_pParser, a2: 1);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pParser);
    m_size = this->m_registry.m_size;
    v4 = 0;
    this->m_pParser = nullptr;
    if ( m_size > 1 )
      qsort(
        base: this->m_registry.m_data,
        num: m_size,
        width: 0x14u,
        comp: (int (__fastcall *)(const void *, const void *))bfx::ReplayPlayer::CompareRegistration);
    if ( this->m_registry.m_size > 0 )
    {
      v5 = 0;
      do
      {
        this->m_registry.m_data[v5].m_clearCB();
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_registry.m_size );
    }
  }
}


// ========================================================================
// ?StopReplayPlayback@bfx@@YAXXZ
// EA  : 0x83297618
// RVA : 0x01297618
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

void __fastcall bfx::StopReplayPlayback(bfx *this)
{
  if ( bfx::g_pCurInstance->m_pReplayPlayer != nullptr )
    bfx::ReplayPlayer::Stop(this: bfx::g_pCurInstance->m_pReplayPlayer);
}


// ========================================================================
// ?ProcessCallbackEvent@ReplayPlayer@bfx@@QAA_NW4ComponentID@2@GPAX@Z
// EA  : 0x832976A0
// RVA : 0x012976A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

int __fastcall bfx::ReplayPlayer::ProcessCallbackEvent(
        bfx::ReplayPlayer *this,
        bfx::ComponentID componentID,
        unsigned __int16 eventID,
        void *pDataOut)
{
  bfx::ReplayParser *m_pParser; // r11
  int v9; // r8
  unsigned int m_version; // r7
  float m_time; // r6
  bfx::ReplayLogIn *m_pLog; // r3
  bfx::ReplayParser *v13; // r30
  const bfx::ReplayEventInfo *m_pCurrentInfo; // r29
  bfx::ComponentID m_componentID; // r27
  int m_eventID; // r28
  bfx::PlaybackFilter *m_pPlaybackFilter; // r3
  const bfx::ReplayPlayer::Registration *Component; // r3
  bfx::ReplayLogIn *v19; // r5
  int v21; // r9
  unsigned int v22; // r8
  float v23; // r7
  bfx::ReplayLogIn *v24; // r3
  bfx::FilterEntry v25; // [sp+50h] [-50h] BYREF

  m_pParser = this->m_pParser;
  v9 = *(_DWORD *)&m_pParser->m_currentInfo.m_eventID;
  m_version = m_pParser->m_currentInfo.m_version;
  m_time = m_pParser->m_currentInfo.m_time;
  m_pLog = m_pParser->m_pLog;
  m_pParser->m_infoAtMark.m_componentID = m_pParser->m_currentInfo.m_componentID;
  *(_DWORD *)&m_pParser->m_infoAtMark.m_eventID = v9;
  m_pParser->m_infoAtMark.m_version = m_version;
  m_pParser->m_infoAtMark.m_time = m_time;
  m_pLog->Mark(this: m_pLog);
  bfx::ReplayParser::ParseNextEvent(this: this->m_pParser);
  v13 = this->m_pParser;
  m_pCurrentInfo = v13->m_pCurrentInfo;
  if ( m_pCurrentInfo == nullptr )
    return 0;
  m_componentID = m_pCurrentInfo->m_componentID;
  if ( m_pCurrentInfo->m_componentID != componentID || (m_eventID = m_pCurrentInfo->m_eventID, eventID != m_eventID) )
  {
    v21 = *(_DWORD *)&v13->m_infoAtMark.m_eventID;
    v22 = v13->m_infoAtMark.m_version;
    v23 = v13->m_infoAtMark.m_time;
    v24 = v13->m_pLog;
    v13->m_currentInfo.m_componentID = v13->m_infoAtMark.m_componentID;
    *(_DWORD *)&v13->m_currentInfo.m_eventID = v21;
    v13->m_currentInfo.m_version = v22;
    v13->m_currentInfo.m_time = v23;
    v24->Rewind(this: v24);
    return 0;
  }
  m_pPlaybackFilter = this->m_pPlaybackFilter;
  if ( m_pPlaybackFilter != nullptr )
  {
    v25.m_componentID = m_pCurrentInfo->m_componentID;
    v25.m_eventID = m_eventID;
    if ( (unsigned __int8)bfx::Array<bfx::FilterEntry>::find(this: &m_pPlaybackFilter->m_filters, val: &v25) == 0 )
      return 0;
  }
  Component = bfx::ReplayPlayer::FindComponent(this, componentID: m_componentID);
  if ( Component == nullptr )
    return 0;
  if ( v13->m_pCurrentInfo != nullptr )
    v19 = v13->m_pLog;
  else
    v19 = nullptr;
  return ((int (__fastcall *)(int, unsigned int, bfx::ReplayLogIn *, void *))Component->m_replayCB)(
           a1: m_eventID,
           a2: m_pCurrentInfo->m_version,
           a3: v19,
           a4: pDataOut);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_warnOnReplayDivergenceRestore''
// EA  : 0x83399028
// RVA : 0x01399028
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_warnOnReplayDivergenceRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_warnOnReplayDivergenceRestore);
  bfx::g_warnOnReplayDivergenceRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_warnOnReplayDivergenceRestore.m_targetBool = &bfx::g_warnOnReplayDivergence;
  bfx::g_warnOnReplayDivergenceRestore.m_name = "warn_on_replay_divergence";
  bfx::g_warnOnReplayDivergenceRestore.m_defaultBool = bfx::g_warnOnReplayDivergence;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_warnOnReplayDivergenceRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_disableReplayVersionWarningRestore''
// EA  : 0x833990A0
// RVA : 0x013990A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_disableReplayVersionWarningRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_disableReplayVersionWarningRestore);
  bfx::g_disableReplayVersionWarningRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_disableReplayVersionWarningRestore.m_targetBool = &bfx::g_disableReplayVersionWarning;
  bfx::g_disableReplayVersionWarningRestore.m_name = "disable_replay_version_warning";
  bfx::g_disableReplayVersionWarningRestore.m_defaultBool = bfx::g_disableReplayVersionWarning;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_disableReplayVersionWarningRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 's_replayX87Precision''
// EA  : 0x83399118
// RVA : 0x01399118
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxreplayplayer.cpp
// ========================================================================

int __fastcall bfx::_dynamic_initializer_for__s_replayX87Precision__(_exception *a1)
{
  int result; // r3

  result = idLobbyBackend360::StartArbitration(pexcept: a1);
  s_replayX87Precision = result;
  return result;
}

