
// ========================================================================
// ?GetSubtitleForLanguage@idPlayerProfileGame@@QAA_NH@Z
// EA  : 0x82E4E9B8
// RVA : 0x00E4E9B8
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

BOOL __fastcall idPlayerProfileGame::GetSubtitleForLanguage(idPlayerProfileGame *this, char language)
{
  return (this->subtitleMask & (1 << language)) != 0;
}


// ========================================================================
// ?SetSubtitleForLanguage@idPlayerProfileGame@@QAAXH_N@Z
// EA  : 0x82E4E9D8
// RVA : 0x00E4E9D8
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetSubtitleForLanguage(idPlayerProfileGame *this, char language, bool active)
{
  unsigned int v3; // r10

  v3 = this->subtitleMask & ~(1 << language);
  this->subtitleMask = v3;
  if ( active )
    this->subtitleMask = v3 | (1 << language);
}


// ========================================================================
// ?SetAllProgress@idPlayerProfileGame@@QAAXXZ
// EA  : 0x82E4EA08
// RVA : 0x00E4EA08
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetAllProgress(idPlayerProfileGame *this)
{
  __int64 v1; // r11

  LODWORD(v1) = -1;
  *(_QWORD *)this->progressBits = v1;
  *(_QWORD *)&this->progressBits[2] = v1;
  *(_QWORD *)&this->progressBits[4] = v1;
  *(_QWORD *)&this->progressBits[6] = v1;
  ++this->secretAndProgressStamp;
}


// ========================================================================
// ?SetProgress@idPlayerProfileGame@@QAAXH@Z
// EA  : 0x82E4EA30
// RVA : 0x00E4EA30
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetProgress(idPlayerProfileGame *this, unsigned int variationId)
{
  if ( variationId < 0x100 )
  {
    this->progressBits[(int)variationId / 32] |= 1 << (variationId & 0x1F);
    ++this->secretAndProgressStamp;
  }
}


// ========================================================================
// ?GetProgress@idPlayerProfileGame@@QAA_NH@Z
// EA  : 0x82E4EA78
// RVA : 0x00E4EA78
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

BOOL __fastcall idPlayerProfileGame::GetProgress(idPlayerProfileGame *this, unsigned int variationId)
{
  return variationId < 0x100 && ((1 << (variationId & 0x1F)) & this->progressBits[(int)variationId / 32]) != 0;
}


// ========================================================================
// ?ClearSecrets@idPlayerProfileGame@@QAAXXZ
// EA  : 0x82E4EAC0
// RVA : 0x00E4EAC0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::ClearSecrets(idPlayerProfileGame *this)
{
  memset(Dst: this->secretBits, Val: 0, Size: sizeof(this->secretBits));
  ++this->secretAndProgressStamp;
}


// ========================================================================
// ?SetAllSecrets@idPlayerProfileGame@@QAAXXZ
// EA  : 0x82E4EB08
// RVA : 0x00E4EB08
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetAllSecrets(idPlayerProfileGame *this)
{
  memset(Dst: this->secretBits, Val: 255, Size: sizeof(this->secretBits));
  ++this->secretAndProgressStamp;
}


// ========================================================================
// ?SetSecret@idPlayerProfileGame@@QAAXH@Z
// EA  : 0x82E4EB50
// RVA : 0x00E4EB50
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetSecret(idPlayerProfileGame *this, unsigned int secretId)
{
  if ( secretId < 0x800 )
  {
    this->secretBits[(int)secretId / 32] |= 1 << (secretId & 0x1F);
    ++this->secretAndProgressStamp;
  }
}


// ========================================================================
// ?GetSecret@idPlayerProfileGame@@QAA_NH@Z
// EA  : 0x82E4EB98
// RVA : 0x00E4EB98
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

BOOL __fastcall idPlayerProfileGame::GetSecret(idPlayerProfileGame *this, unsigned int secretId)
{
  return secretId < 0x800 && ((1 << (secretId & 0x1F)) & this->secretBits[(int)secretId / 32]) != 0;
}


// ========================================================================
// ?SetCompleted@idPlayerProfileGame@@QAAXH@Z
// EA  : 0x82E4EBE0
// RVA : 0x00E4EBE0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetCompleted(idPlayerProfileGame *this, unsigned int completedID)
{
  if ( completedID < 0x100 )
    this->completedBits[(int)completedID / 32] |= 1 << (completedID & 0x1F);
}


// ========================================================================
// ?GetCompleted@idPlayerProfileGame@@QAA_NH@Z
// EA  : 0x82E4EC20
// RVA : 0x00E4EC20
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

BOOL __fastcall idPlayerProfileGame::GetCompleted(idPlayerProfileGame *this, unsigned int completedID)
{
  return completedID < 0x100 && ((1 << (completedID & 0x1F)) & this->completedBits[(int)completedID / 32]) != 0;
}


// ========================================================================
// ?GetConfig@idPlayerProfileGame@@QBAH_N@Z
// EA  : 0x82E4EC68
// RVA : 0x00E4EC68
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

int __fastcall idPlayerProfileGame::GetConfig(XGRAPHICS::CFG *this)
{
  return this->parameter_generation_position;
}


// ========================================================================
// ?GetGammaValue@idPlayerProfileGame@@QBAMXZ
// EA  : 0x82E4EC70
// RVA : 0x00E4EC70
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetGammaValue(idPlayerProfileGame *this)
{
  double gammaValue; // fp1

  gammaValue = this->gammaValue;
  return *((float *)&gammaValue + 1);
}


// ========================================================================
// ?SetInvertLook@idPlayerProfileGame@@UAAX_N@Z
// EA  : 0x82E4EC78
// RVA : 0x00E4EC78
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetInvertLook(idPlayerProfileGame *this, bool val)
{
  idCVar::SetBool(this: &in_invertLook, newValue: val, force: true);
}


// ========================================================================
// ?SetMouseSensitivity@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4EC88
// RVA : 0x00E4EC88
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetMouseSensitivity(idPlayerProfileGame *this, double val, bool a3)
{
  idCVar::SetFloat(this: &m_sensitivity, newValue: val, force: a3);
}


// ========================================================================
// ?GetLevel@idPlayerProfileGame@@UBAHXZ
// EA  : 0x82E4EC98
// RVA : 0x00E4EC98
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

int __fastcall idPlayerProfileGame::GetLevel(idPlayerProfileGame *this)
{
  bool v2; // r3
  profileStatValue_t *list; // r11

  v2 = common->IsMultiplayer(this: common);
  list = this->stats.list;
  if ( v2 )
    return list[32].i;
  else
    return list[31].i;
}


// ========================================================================
// ?SetGammaValue@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4ED08
// RVA : 0x00E4ED08
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetGammaValue(idPlayerProfileGame *this, double percent)
{
  double v2; // fp1

  this->gammaValue = percent;
  v2 = (float)((float)((float)percent * (float)0.2) - (float)0.1);
  if ( v2 >= -0.1 )
  {
    if ( v2 > 0.1 )
      v2 = 0.1;
  }
  else
  {
    v2 = -0.1;
  }
  if ( renderSystem != nullptr )
    renderSystem->SetBlackLevel(this: renderSystem, a2: v2);
}


// ========================================================================
// ?ExecConfig@idPlayerProfileGame@@QAAXH_N0@Z
// EA  : 0x82E4ED68
// RVA : 0x00E4ED68
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::ExecConfig(
        idPlayerProfileGame *this,
        int config,
        __int64 save,
        __int64 a4,
        __int64 a5)
{
  const char *v5; // r31
  int v6; // r29
  int v7; // r28
  va *v8; // r3
  int v9; // [sp+8h] [-1078h]
  int v10; // [sp+Ch] [-1074h]
  int v11; // [sp+10h] [-1070h]
  int v12; // [sp+14h] [-106Ch]
  int v13; // [sp+18h] [-1068h]
  int v14; // [sp+1Ch] [-1064h]
  va v15; // [sp+50h] [-1030h] BYREF

  if ( BYTE3(save) != 0 )
  {
    if ( (unsigned int)(config - 1) > 4 )
    {
      v5 = "default_joystick360.cfg";
    }
    else
    {
      switch ( config )
      {
        case 2:
          v5 = "360_3.cfg";
          break;
        case 3:
          v5 = "360_4.cfg";
          break;
        case 4:
          v5 = "Southpaw_360_1.cfg";
          break;
        case 1:
          v5 = "360_2.cfg";
          break;
        default:
          v5 = "Southpaw_360_2.cfg";
          break;
      }
    }
  }
  else
  {
    switch ( config )
    {
      case 1:
        v5 = "vehicle_2.cfg";
        break;
      case 2:
        v5 = "vehicle_3.cfg";
        break;
      case 3:
        v5 = "vehicle_4.cfg";
        break;
      default:
        v5 = "vehicle_1.cfg";
        break;
    }
  }
  v6 = (unsigned __int8)save;
  v7 = 0;
  if ( (_BYTE)save == 0 )
    v7 = cvarSystem->GetModifiedFlags(this: cvarSystem);
  HIDWORD(save) = v5;
  v8 = va::va(this: &v15, fmt: "exec %s\n", a3: save, a4, a5, a6: v9, a7: v10, a8: v11, a9: v12, a10: v13, a11: v14);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v8->buffer);
  cmdSystem->ExecuteCommandBuffer(this: cmdSystem);
  if ( v6 == 0 )
  {
    cvarSystem->ClearModifiedFlags(this: cvarSystem, a2: 0x10000);
    cvarSystem->SetModifiedFlags(this: cvarSystem, a2: v7);
  }
}


// ========================================================================
// ?GetInvertLook@idPlayerProfileGame@@QBA_NXZ
// EA  : 0x82E4EEE8
// RVA : 0x00E4EEE8
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

BOOL __fastcall idPlayerProfileGame::GetInvertLook(idPlayerProfileGame *this)
{
  return in_invertLook.valueInteger != 0;
}


// ========================================================================
// ?GetMouseSensitivity@idPlayerProfileGame@@UBAMXZ
// EA  : 0x82E4EF00
// RVA : 0x00E4EF00
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetMouseSensitivity(idPlayerProfileGame *this)
{
  double valueFloat; // fp1

  valueFloat = m_sensitivity.valueFloat;
  return *((float *)&valueFloat + 1);
}


// ========================================================================
// ?GetMasterVolume@idPlayerProfileGame@@QBAMXZ
// EA  : 0x82E4EF10
// RVA : 0x00E4EF10
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetMasterVolume(idPlayerProfileGame *this)
{
  double v1; // fp0
  double v2; // fp1

  v1 = (float)-(float)((float)(s_volume_dB.valueFloat * (float)-0.016666668) - (float)1.0);
  v2 = (float)((float)v1 * (float)v1);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetMusicVolume@idPlayerProfileGame@@QBAMXZ
// EA  : 0x82E4EF38
// RVA : 0x00E4EF38
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetMusicVolume(idPlayerProfileGame *this)
{
  double v1; // fp0
  double v2; // fp1

  v1 = (float)-(float)((float)(s_volume_music.valueFloat * (float)-0.016666668) - (float)1.0);
  v2 = (float)((float)v1 * (float)v1);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetVoiceVolume@idPlayerProfileGame@@QBAMXZ
// EA  : 0x82E4EF60
// RVA : 0x00E4EF60
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetVoiceVolume(idPlayerProfileGame *this)
{
  double v1; // fp0
  double v2; // fp1

  v1 = (float)-(float)((float)(s_volume_vo.valueFloat * (float)-0.016666668) - (float)1.0);
  v2 = (float)((float)v1 * (float)v1);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetAmbientVolume@idPlayerProfileGame@@QBAMXZ
// EA  : 0x82E4EF88
// RVA : 0x00E4EF88
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

float __fastcall idPlayerProfileGame::GetAmbientVolume(idPlayerProfileGame *this)
{
  double v1; // fp0
  double v2; // fp1

  v1 = (float)-(float)((float)(s_volume_ambient.valueFloat * (float)-0.016666668) - (float)1.0);
  v2 = (float)((float)v1 * (float)v1);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?SetMasterVolume@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4EFB0
// RVA : 0x00E4EFB0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetMasterVolume(idPlayerProfileGame *this, double val, bool a3)
{
  idCVar::SetFloat(
    this: &s_volume_dB,
    newValue: (float)-(float)((float)((float)__fsqrts(val) * (float)-60.0) - (float)-60.0),
    force: a3);
}


// ========================================================================
// ?SetMusicVolume@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4EFD0
// RVA : 0x00E4EFD0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetMusicVolume(idPlayerProfileGame *this, double val, bool a3)
{
  idCVar::SetFloat(
    this: &s_volume_music,
    newValue: (float)-(float)((float)((float)__fsqrts(val) * (float)-60.0) - (float)-60.0),
    force: a3);
}


// ========================================================================
// ?SetVoiceVolume@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4EFF0
// RVA : 0x00E4EFF0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetVoiceVolume(idPlayerProfileGame *this, double val, bool a3)
{
  idCVar::SetFloat(
    this: &s_volume_vo,
    newValue: (float)-(float)((float)((float)__fsqrts(val) * (float)-60.0) - (float)-60.0),
    force: a3);
}


// ========================================================================
// ?SetAmbientVolume@idPlayerProfileGame@@QAAXM@Z
// EA  : 0x82E4F010
// RVA : 0x00E4F010
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetAmbientVolume(idPlayerProfileGame *this, double val, bool a3)
{
  idCVar::SetFloat(
    this: &s_volume_ambient,
    newValue: (float)-(float)((float)((float)__fsqrts(val) * (float)-60.0) - (float)-60.0),
    force: a3);
}


// ========================================================================
// ?SetSideMissionData@idPlayerProfileGame@@QAAXABVidStr@@00HH@Z
// EA  : 0x82E4F0B0
// RVA : 0x00E4F0B0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetSideMissionData(
        idPlayerProfileGame *this,
        const idStr *mapName,
        const idStr *spawnPoint,
        const idStr *layers,
        int variationIndex,
        int partIndex)
{
  int len; // r30
  int v13; // r30
  int v14; // r30

  len = mapName->len;
  idStr::EnsureAlloced(this: &this->savedSpawnMap, amount: mapName->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->savedSpawnMap.data, Src: mapName->data, Size: len);
  this->savedSpawnMap.data[len] = 0;
  this->savedSpawnMap.len = len;
  v13 = spawnPoint->len;
  idStr::EnsureAlloced(this: &this->savedSpawnSpot, amount: spawnPoint->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->savedSpawnSpot.data, Src: spawnPoint->data, Size: v13);
  this->savedSpawnSpot.data[v13] = 0;
  this->savedSpawnSpot.len = v13;
  v14 = layers->len;
  idStr::EnsureAlloced(this: &this->savedLayers, amount: layers->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->savedLayers.data, Src: layers->data, Size: v14);
  this->savedLayers.data[v14] = 0;
  this->savedLayers.len = v14;
  this->savedVariationIndex = variationIndex;
  this->savedPartIndex = partIndex;
}


// ========================================================================
// ?GetSideMissionData@idPlayerProfileGame@@QAAXPAVidStr@@PAH10@Z
// EA  : 0x82E4F188
// RVA : 0x00E4F188
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::GetSideMissionData(
        idPlayerProfileGame *this,
        idStr *spawnSpot,
        int *variationIndex,
        int *partIndex,
        idStr *layers)
{
  int len; // r31
  int v11; // r31

  len = this->savedSpawnSpot.len;
  idStr::EnsureAlloced(this: spawnSpot, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: spawnSpot->data, Src: this->savedSpawnSpot.data, Size: len);
  spawnSpot->data[len] = 0;
  spawnSpot->len = len;
  *variationIndex = this->savedVariationIndex;
  *partIndex = this->savedPartIndex;
  v11 = this->savedLayers.len;
  idStr::EnsureAlloced(this: layers, amount: v11 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: layers->data, Src: this->savedLayers.data, Size: v11);
  layers->data[v11] = 0;
  layers->len = v11;
}


// ========================================================================
// ?SetConfig@idPlayerProfileGame@@QAAXH_N0@Z
// EA  : 0x82E4F230
// RVA : 0x00E4F230
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetConfig(
        idPlayerProfileGame *this,
        int config,
        __int64 save,
        __int64 a4,
        __int64 a5)
{
  this->fpsConfigSet = config;
  idPlayerProfileGame::ExecConfig(this, config, save, a4, a5);
}


// ========================================================================
// ?CountBonuses@idPlayerProfileGame@@QAAHH_N@Z
// EA  : 0x82E4F238
// RVA : 0x00E4F238
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

int __fastcall idPlayerProfileGame::CountBonuses(idPlayerProfileGame *this, idResourceList *bonusType, bool onlyTaken)
{
  int v6; // r20
  int v7; // r19
  int v8; // r21
  const char *str; // r4
  const idDecl *v10; // r3
  const idDecl *v11; // r28
  int v12; // r23
  int v13; // r27
  const char *v14; // r4
  const idDecl *v15; // r3
  idResource *v16; // r30
  int v17; // r29
  int v18; // r31
  const char *v19; // r4
  const char *v20; // r3
  int v21; // r3
  char v22; // r11
  int v23; // r11
  bool v24; // r11

  v6 = 0;
  v7 = 0;
  if ( idDeclSecretType::resourceList.declSources.num > 0 )
  {
    v8 = 0;
    do
    {
      str = idDeclSecretType::resourceList.declSources.list[v8]->name.str;
      if ( str != nullptr )
      {
        v10 = idDeclInfo::FindWithInheritance(this: &idDeclSecretType::resourceList, name: str, makeDefault: false);
        v11 = v10;
        if ( v10 != nullptr && v10[1].resourceListPtr == bonusType )
        {
          v12 = 0;
          if ( idDeclSecrets::resourceList.declSources.num > 0 )
          {
            v13 = 0;
            do
            {
              v14 = idDeclSecrets::resourceList.declSources.list[v13]->name.str;
              if ( v14 != nullptr )
              {
                v15 = idDeclInfo::FindWithInheritance(this: &idDeclSecrets::resourceList, name: v14, makeDefault: false);
                if ( v15 != nullptr )
                {
                  v16 = (idResource *)((char *)&v15[1].idResource + 32);
                  v17 = 0;
                  if ( (int)v15[1].textSource > 0 )
                  {
                    v18 = 0;
                    do
                    {
                      v19 = v11->name.str;
                      v20 = *(const char **)((char *)&v16->LoadResource + v18);
                      if ( v20 == v19 || (v21 = idStr::Cmp(s1: v20, s2: v19), v22 = 0, v21 == 0) )
                        v22 = 1;
                      if ( v22 != 0 )
                      {
                        if ( !onlyTaken
                          || ((unsigned int)(v23 = *(int *)((char *)&v16->dtr_idResource + v18)) >= 0x800
                            ? (v24 = false)
                            : (v24 = ((1 << (v23 & 0x1F)) & this->secretBits[v23 / 32]) != 0),
                              v24) )
                        {
                          ++v6;
                        }
                      }
                      ++v17;
                      v18 += 12;
                    }
                    while ( v17 < v16->trackedMemory );
                  }
                }
              }
              ++v12;
              ++v13;
            }
            while ( v12 < idDeclSecrets::resourceList.declSources.num );
          }
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < idDeclSecretType::resourceList.declSources.num );
  }
  return v6;
}


// ========================================================================
// ?Serialize@idPlayerProfileGame@@UAA_NAAVidSerializer@@@Z
// EA  : 0x82E4F4B0
// RVA : 0x00E4F4B0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

int __fastcall idPlayerProfileGame::Serialize(idPlayerProfileGame *this, idSerializer *ser)
{
  int v4; // r25
  int v6; // r28
  idGame *v7; // r3
  const char *v8; // r4
  unsigned __int8 v9; // r11
  int v10; // r29
  bool v11; // r3
  bool v12; // r4
  __int64 v13; // r10
  __int64 v14; // r8
  bool v15; // r4
  bool v16; // r4
  bool v17; // r4
  bool v18; // r4
  int *progressBits; // r29
  int i; // r28
  idBitMsg *msg; // r3
  int *secretBits; // r29
  int j; // r28
  idBitMsg *v24; // r3
  idBitMsg *v25; // r3
  idBitMsg *v26; // r3
  idBitMsg *v27; // r3
  idBitMsg *v28; // r3
  bool vdmPrivate; // r29
  idBitMsg *v30; // r3
  idBitMsg *v31; // r3
  bool coopPrivate; // r29
  idBitMsg *v33; // r3
  idBitMsg *v34; // r3
  idBitMsg *v35; // r3
  int v36[20]; // [sp+70h] [-50h] BYREF

  if ( rp == nullptr )
    return 0;
  v4 = cvarSystem->GetModifiedFlags(this: cvarSystem);
  v36[0] = 1412432129;
  idSerializer::SerializePacked(this: ser, original: v36);
  if ( SHIWORD(v36[0]) != 21552 )
  {
    idLib::Warning(fmt: "Invalid profile, will be reset by profile manager.");
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 132,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    this->SetDefaults(this);
    idPlayerProfile::SaveSettings(this);
    return 0;
  }
  if ( SBYTE2(v36[0]) <= 1 )
  {
    idSerializer::Serialize(this: ser, value: &this->achievementBits);
    idSerializer::Serialize(this: ser, value: &this->achievementBits2);
    idSerializer::SerializePacked(this: ser, original: &this->dlcReleaseVersion);
    v6 = 0;
    if ( common->Game(this: common) != nullptr
      && (v7 = common->Game(this: common), (v8 = v7->GetMapName(this: v7)) != nullptr)
      && idDeclInfo::FindWithInheritance(this: &idDeclMapInfo::resourceList, name: v8, makeDefault: false) != nullptr
      || (v9 = 0, profileSecurityCheck.valueInteger == 0) )
    {
      v9 = 1;
    }
    if ( idSerializer::SerializeBoolNonRef(this: ser, value: v9) )
    {
      v36[0] = this->stats.num;
      idSerializer::SerializePacked(this: ser, original: v36);
      v10 = v36[0];
      idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->stats, newNum: v36[0]);
      if ( v10 > 0 )
      {
        do
        {
          idSerializer::SerializePacked(this: ser, original: &this->stats.list[v6].i);
          --v10;
          ++v6;
        }
        while ( v10 != 0 );
      }
    }
    this->useSubtitles = idSerializer::SerializeBoolNonRef(this: ser, value: this->useSubtitles);
    this->useAimAssist = idSerializer::SerializeBoolNonRef(this: ser, value: this->useAimAssist);
    this->useGamepad = idSerializer::SerializeBoolNonRef(this: ser, value: this->useGamepad);
    this->useVibrate = idSerializer::SerializeBoolNonRef(this: ser, value: this->useVibrate);
    v11 = idSerializer::SerializeBoolNonRef(this: ser, value: in_invertLook.valueInteger != 0);
    idCVar::SetBool(this: &in_invertLook, newValue: v11, force: true);
    idSerializer::Serialize(this: ser, value: &this->joyXSensitivity);
    idSerializer::Serialize(this: ser, value: &this->joyYSensitivity);
    v36[0] = SLODWORD(m_sensitivity.valueFloat);
    idSerializer::Serialize(this: ser, value: (float *)v36);
    idCVar::SetFloat(this: &m_sensitivity, newValue: *(float *)v36, force: v12);
    idSerializer::Serialize(this: ser, value: &this->fpsConfigSet);
    if ( !ser->writing )
    {
      LODWORD(v14) = ser->writing;
      idPlayerProfileGame::ExecConfig(this, config: this->fpsConfigSet, save: 0x100000000LL, a4: v14, a5: v13);
    }
    v36[0] = SLODWORD(s_volume_dB.valueFloat);
    idSerializer::Serialize(this: ser, value: (float *)v36);
    idCVar::SetFloat(this: &s_volume_dB, newValue: *(float *)v36, force: v15);
    v36[0] = SLODWORD(s_volume_music.valueFloat);
    idSerializer::Serialize(this: ser, value: (float *)v36);
    idCVar::SetFloat(this: &s_volume_music, newValue: *(float *)v36, force: v16);
    v36[0] = SLODWORD(s_volume_vo.valueFloat);
    idSerializer::Serialize(this: ser, value: (float *)v36);
    idCVar::SetFloat(this: &s_volume_vo, newValue: *(float *)v36, force: v17);
    v36[0] = SLODWORD(s_volume_ambient.valueFloat);
    idSerializer::Serialize(this: ser, value: (float *)v36);
    idCVar::SetFloat(this: &s_volume_ambient, newValue: *(float *)v36, force: v18);
    idSerializer::Serialize(this: ser, value: &this->gammaValue);
    if ( !ser->writing )
      idPlayerProfileGame::SetGammaValue(this, percent: this->gammaValue);
    this->seenInstallMessage = idSerializer::SerializeBoolNonRef(this: ser, value: this->seenInstallMessage);
    progressBits = (int *)this->progressBits;
    for ( i = 8; i != 0; --i )
    {
      msg = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: msg, value: *progressBits, numBits: 32);
      else
        *progressBits = idBitMsg::ReadBits(this: msg, numBits: 32);
      ++progressBits;
    }
    secretBits = (int *)this->secretBits;
    for ( j = 64; j != 0; --j )
    {
      v24 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v24, value: *secretBits, numBits: 32);
      else
        *secretBits = idBitMsg::ReadBits(this: v24, numBits: 32);
      ++secretBits;
    }
    v25 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v25, value: this->vdmModeIndex, numBits: 32);
    else
      this->vdmModeIndex = idBitMsg::ReadBits(this: v25, numBits: 32);
    v26 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v26, value: this->vdmMapIndex, numBits: 32);
    else
      this->vdmMapIndex = idBitMsg::ReadBits(this: v26, numBits: 32);
    v27 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v27, value: this->vdmScoreLimit, numBits: 32);
    else
      this->vdmScoreLimit = idBitMsg::ReadBits(this: v27, numBits: 32);
    v28 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v28, value: this->vdmTimeLimit, numBits: 32);
    else
      this->vdmTimeLimit = idBitMsg::ReadBits(this: v28, numBits: 32);
    vdmPrivate = this->vdmPrivate;
    v30 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v30, value: this->vdmPrivate, numBits: 1);
    else
      vdmPrivate = (_cntlzw(idBitMsg::ReadBits(this: v30, numBits: 1) - 1) & 0x20) != 0;
    this->vdmPrivate = vdmPrivate;
    v31 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v31, value: this->coopMapIndex, numBits: 32);
    else
      this->coopMapIndex = idBitMsg::ReadBits(this: v31, numBits: 32);
    coopPrivate = this->coopPrivate;
    v33 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v33, value: this->coopPrivate, numBits: 1);
    else
      coopPrivate = (_cntlzw(idBitMsg::ReadBits(this: v33, numBits: 1) - 1) & 0x20) != 0;
    this->coopPrivate = coopPrivate;
    v34 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v34, value: this->coopDifficulty, numBits: 32);
    else
      this->coopDifficulty = idBitMsg::ReadBits(this: v34, numBits: 32);
    v35 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v35, value: this->subtitleMask, numBits: 32);
    else
      this->subtitleMask = idBitMsg::ReadBits(this: v35, numBits: 32);
    cvarSystem->ClearModifiedFlags(this: cvarSystem, a2: 0x10000);
    cvarSystem->SetModifiedFlags(this: cvarSystem, a2: v4);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "Profile version exceeded support threshold, will be reset by profile manager.");
    ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 133,
      a3: 1,
      a4: 0,
      a5: 0,
      a6: 1,
      a7: 0,
      a8: 0);
    this->SetDefaults(this);
    idPlayerProfile::SaveSettings(this);
    return 0;
  }
}


// ========================================================================
// ??1idPlayerProfileGame@@UAA@XZ
// EA  : 0x82E4FE40
// RVA : 0x00E4FE40
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::~idPlayerProfileGame(idPlayerProfileGame *this)
{
  this->__vftable = (idPlayerProfileGame_vtbl *)&idPlayerProfileGame::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->newEmblems);
  idStaticList<idPlayerProfileGame::profileLoadout_t,5>::~idStaticList<idPlayerProfileGame::profileLoadout_t,5>(this: &this->loadouts);
  idStr::FreeData(this: &this->savedLayers);
  idStr::FreeData(this: &this->savedSpawnSpot);
  idStr::FreeData(this: &this->savedSpawnMap);
  idPlayerProfile::~idPlayerProfile(this);
}


// ========================================================================
// __unwind$490671
// EA  : 0x82E4FEB4
// RVA : 0x00E4FEB4
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490671()
{
  int v0; // r12

  idPlayerProfile::~idPlayerProfile(this: *(idPlayerProfile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490672
// EA  : 0x82E4FEDC
// RVA : 0x00E4FEDC
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490672()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 2424));
}


// ========================================================================
// __unwind$490673_0
// EA  : 0x82E4FF08
// RVA : 0x00E4FF08
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490673_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 2456));
}


// ========================================================================
// __unwind$490674_0
// EA  : 0x82E4FF34
// RVA : 0x00E4FF34
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490674_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 2488));
}


// ========================================================================
// __unwind$490675
// EA  : 0x82E4FF60
// RVA : 0x00E4FF60
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490675()
{
  int v0; // r12

  idStaticList<idPlayerProfileGame::profileLoadout_t,5>::~idStaticList<idPlayerProfileGame::profileLoadout_t,5>(this: (idStaticList<idPlayerProfileGame::profileLoadout_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 2528));
}


// ========================================================================
// ?ReloadDefaultLoadouts@idPlayerProfileGame@@QAAXXZ
// EA  : 0x82E4FFB0
// RVA : 0x00E4FFB0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::ReloadDefaultLoadouts(idPlayerProfileGame *this)
{
  idStaticList<idPlayerProfileGame::profileLoadout_t,5> *p_loadouts; // r27
  int v2; // r25
  int num; // r11
  int v4; // r26
  const idDeclVehicleLoadout *v5; // r30
  const char *Key; // r3
  const idDeclVehicleUnlock *vehicleClass; // r11
  int ordinal; // r11
  const idDeclVehicleUnlock *vehicle; // r11
  int v10; // r11
  const idDeclVehicleUnlock *weaponPrimary; // r11
  int v12; // r11
  const idDeclVehicleUnlock *weaponSecondary; // r11
  int v14; // r11
  const idDeclVehicleUnlock *quickUse1; // r11
  int v16; // r11
  const idDeclVehicleUnlock *quickUse2; // r11
  int v18; // r11
  idStrId v19; // [sp+50h] [-130h] BYREF
  idPlayerProfileGame::profileLoadout_t v20; // [sp+60h] [-120h] BYREF
  idStrStatic<64> v21; // [sp+E0h] [-A0h] BYREF

  p_loadouts = &this->loadouts;
  if ( this->loadouts.listStatic == 0 || this->loadouts.listStatic == 2 )
  {
    if ( p_loadouts->list != nullptr )
      idListArrayDelete<idPlayerProfileGame::profileLoadout_t>(
        ptr: &this->loadouts.list->name,
        num: this->loadouts.size);
    p_loadouts->list = nullptr;
    p_loadouts->size = 0;
  }
  p_loadouts->num = 0;
  v20.name.baseBuffer[0] = 0;
  v20.name.buffer[0] = 0;
  v20.name.data = v20.name.buffer;
  v20.name.len = 0;
  v20.name.allocedAndFlag = -2147483584;
  v2 = 0;
  num = idDeclVehicleLoadout::defaultLoadouts.num;
  if ( idDeclVehicleLoadout::defaultLoadouts.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = idDeclVehicleLoadout::defaultLoadouts.list[v4];
      if ( v5 != nullptr )
      {
        v19.index = v5->desc.index;
        Key = idStrId::GetKey(this: &v19);
        idStrStatic<64>::idStrStatic<64>(this: &v21, text: Key);
        v20.name.len = v21.len;
        memcpy(Dst: v20.name.data, Src: v21.data, Size: v21.len + 1);
        idStr::FreeData(this: &v21);
        vehicleClass = v5->vehicleClass;
        if ( vehicleClass != nullptr )
          ordinal = vehicleClass->ordinal;
        else
          ordinal = 0;
        v20.slot[0] = ordinal;
        vehicle = v5->vehicle;
        if ( vehicle != nullptr )
          v10 = vehicle->ordinal;
        else
          v10 = 0;
        v20.slot[1] = v10;
        weaponPrimary = v5->weaponPrimary;
        if ( weaponPrimary != nullptr )
          v12 = weaponPrimary->ordinal;
        else
          v12 = 0;
        v20.slot[2] = v12;
        weaponSecondary = v5->weaponSecondary;
        if ( weaponSecondary != nullptr )
          v14 = weaponSecondary->ordinal;
        else
          v14 = 0;
        v20.slot[3] = v14;
        quickUse1 = v5->quickUse1;
        if ( quickUse1 != nullptr )
          v16 = quickUse1->ordinal;
        else
          v16 = 0;
        v20.slot[4] = v16;
        quickUse2 = v5->quickUse2;
        if ( quickUse2 != nullptr )
          v18 = quickUse2->ordinal;
        else
          v18 = 0;
        v20.slot[5] = v18;
        idList<idPlayerProfileGame::profileLoadout_t,5>::Append(this: p_loadouts, obj: &v20);
        num = idDeclVehicleLoadout::defaultLoadouts.num;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < num );
  }
  idStr::FreeData(this: &v20.name);
}


// ========================================================================
// __unwind$490744_1
// EA  : 0x82E5015C
// RVA : 0x00E5015C
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_490744_1()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// ?SetDefaultsImpl@idPlayerProfileGame@@AAAXXZ
// EA  : 0x82E50298
// RVA : 0x00E50298
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetDefaultsImpl(idPlayerProfileGame *this)
{
  this->stats.list[32].i = 1;
  this->stats.list[31].i = 1;
  this->joyXSensitivity = 240.0;
  this->joyYSensitivity = 120.0;
  this->useSubtitles = true;
  this->gammaValue = 0.5;
  *(_WORD *)&this->useAimAssist = 1;
  this->useVibrate = true;
  this->fpsConfigSet = 0;
  this->GPUtranscodeEnabled = false;
  this->antristropicFilter = 0;
  this->seenInstallMessage = false;
  this->chosenEmblem = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->newEmblems);
  this->vdmModeIndex = 0;
  this->vdmMapIndex = -1;
  this->vdmScoreLimit = 200;
  this->vdmTimeLimit = 600;
  this->vdmPrivate = false;
  this->coopMapIndex = -1;
  this->coopPrivate = false;
  this->coopDifficulty = 1;
  idPlayerProfileGame::ReloadDefaultLoadouts(this);
  this->subtitleMask = -3;
  *(_QWORD *)this->progressBits = 0x100000000LL;
  *(_QWORD *)&this->progressBits[2] = 0x100000000LL;
  *(_QWORD *)&this->progressBits[4] = 0x100000000LL;
  *(_QWORD *)&this->progressBits[6] = 0x100000000LL;
  ++this->secretAndProgressStamp;
}


// ========================================================================
// ??0idPlayerProfileGame@@QAA@XZ
// EA  : 0x82E50378
// RVA : 0x00E50378
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

idPlayerProfileGame *__fastcall idPlayerProfileGame::idPlayerProfileGame(idPlayerProfileGame *this)
{
  idPlayerProfile::idPlayerProfile(this);
  this->__vftable = (idPlayerProfileGame_vtbl *)&idPlayerProfileGame::`vftable';
  this->savedSpawnMap.len = 0;
  this->savedSpawnMap.data = this->savedSpawnMap.baseBuffer;
  this->savedSpawnMap.allocedAndFlag = 20;
  this->savedSpawnMap.baseBuffer[0] = 0;
  this->savedSpawnSpot.allocedAndFlag = 20;
  this->savedSpawnSpot.len = 0;
  this->savedSpawnSpot.data = this->savedSpawnSpot.baseBuffer;
  this->savedSpawnSpot.baseBuffer[0] = 0;
  this->savedLayers.allocedAndFlag = 20;
  this->savedLayers.len = 0;
  this->savedLayers.data = this->savedLayers.baseBuffer;
  this->savedLayers.baseBuffer[0] = 0;
  idStaticList<idPlayerProfileGame::profileLoadout_t,5>::idStaticList<idPlayerProfileGame::profileLoadout_t,5>(this: &this->loadouts);
  this->newEmblems.num = 0;
  this->newEmblems.granularity = 1;
  this->newEmblems.size = 100;
  this->newEmblems.list = this->newEmblems.staticList;
  this->newEmblems.memTag = 5;
  this->newEmblems.listStatic = 1;
  this->secretAndProgressStamp = 0;
  idStr::operator=(this: &this->savedSpawnMap, text: &byte_8200D768);
  idStr::operator=(this: &this->savedSpawnSpot, text: &byte_8200D768);
  idStr::operator=(this: &this->savedLayers, text: &byte_8200D768);
  idPlayerProfileGame::SetDefaultsImpl(this);
  return this;
}


// ========================================================================
// __unwind$491031
// EA  : 0x82E50474
// RVA : 0x00E50474
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491031()
{
  int v0; // r12

  idPlayerProfile::~idPlayerProfile(this: *(idPlayerProfile **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$491032
// EA  : 0x82E5049C
// RVA : 0x00E5049C
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491032()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2424));
}


// ========================================================================
// __unwind$491033
// EA  : 0x82E504C8
// RVA : 0x00E504C8
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2456));
}


// ========================================================================
// __unwind$491034
// EA  : 0x82E504F4
// RVA : 0x00E504F4
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2488));
}


// ========================================================================
// __unwind$491035
// EA  : 0x82E50520
// RVA : 0x00E50520
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491035()
{
  int v0; // r12

  idStaticList<idPlayerProfileGame::profileLoadout_t,5>::~idStaticList<idPlayerProfileGame::profileLoadout_t,5>(this: (idStaticList<idPlayerProfileGame::profileLoadout_t,5> *)(*(_DWORD *)(v0 - 144 + 164) + 2528));
}


// ========================================================================
// __unwind$491036
// EA  : 0x82E5054C
// RVA : 0x00E5054C
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void _unwind_491036()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 3148));
}


// ========================================================================
// ?SetDefaults@idPlayerProfileGame@@UAAXXZ
// EA  : 0x82E50578
// RVA : 0x00E50578
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __fastcall idPlayerProfileGame::SetDefaults(idPlayerProfileGame *this)
{
  idPlayerProfile::SetDefaults(this);
  idPlayerProfileGame::SetDefaultsImpl(this);
}


// ========================================================================
// ?CreatePlayerProfile@idPlayerProfileGame@@SAPAV1@H@Z
// EA  : 0x82E505B0
// RVA : 0x00E505B0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

idPlayerProfileGame *__fastcall idPlayerProfileGame::CreatePlayerProfile(int deviceIndex)
{
  int v1; // r29
  idPlayerProfileGame *v3; // r31

  v1 = 3600 * deviceIndex;
  v3 = &playerProfiles[deviceIndex];
  idPlayerProfile::SetDefaults(this: v3);
  idPlayerProfileGame::SetDefaultsImpl(this: v3);
  *(int *)((char *)&playerProfiles[0].deviceNum + v1) = deviceIndex;
  return v3;
}


// ========================================================================
// `dynamic initializer for 'profileSecurityCheck''
// EA  : 0x8338EC48
// RVA : 0x0138EC48
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__profileSecurityCheck__()
{
  idCVar::idCVar(
    this: &profileSecurityCheck,
    name: "profileSecurityCheck",
    value: "0",
    flags: 1,
    description: "checks to make sure we are on a valid map before we save stats to profile or update achievements",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__profileSecurityCheck__);
}


// ========================================================================
// `dynamic initializer for 'playerProfiles''
// EA  : 0x8338ECA0
// RVA : 0x0138ECA0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__playerProfiles__()
{
  `eh vector constructor iterator'(
    ptr: (char *)playerProfiles,
    size: 0xE10u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idPlayerProfileGame::idPlayerProfileGame,
    pDtor: (void (__fastcall *)(void *))idPlayerProfileGame::~idPlayerProfileGame);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__playerProfiles__);
}

