
// ========================================================================
// ??0idTarget_Bink@@QAA@XZ
// EA  : 0x82C0BC60
// RVA : 0x00C0BC60
// PDB : w:\tech5\tungsten\game\entities\bink.cpp
// ========================================================================

idTarget_Bink *__fastcall idTarget_Bink::idTarget_Bink(idTarget_Bink *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_Bink_vtbl *)&idTarget_Bink::`vftable';
  this->videoFileName.len = 0;
  this->videoFileName.allocedAndFlag = 20;
  this->videoFileName.data = this->videoFileName.baseBuffer;
  this->videoFileName.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ?OnActivate@idTarget_Bink@@UAAXPAVidEntity@@@Z
// EA  : 0x82C0BCC0
// RVA : 0x00C0BCC0
// PDB : w:\tech5\tungsten\game\entities\bink.cpp
// ========================================================================

void __fastcall idTarget_Bink::OnActivate(idTarget_Bink *this, idEntity *activator)
{
  idSoundWorld *v3; // r3
  char *data; // r30
  idRenderSystem_vtbl *v5; // r31
  idRenderVideoOverlay *v6; // r28
  void *v7; // r3
  idSoundWorld *v8; // r3
  idSysLocal v9; // [sp+60h] [-F0h] BYREF
  int v10; // [sp+64h] [-ECh]
  int v11; // [sp+68h] [-E8h]
  float v12[6]; // [sp+80h] [-D0h] BYREF
  char v13; // [sp+98h] [-B8h]
  bool v14; // [sp+99h] [-B7h]
  _BYTE v15[64]; // [sp+A0h] [-B0h] BYREF

  v3 = gameLocal->GetSoundWorld(this: gameLocal);
  ((void (__fastcall *)(idSoundWorld *, _DWORD, double))v3->Fade)(a1: v3, a2: 0, a3: -60.0);
  data = this->videoFileName.data;
  v5 = renderSystem->__vftable;
  v6 = common->VideoOverlay(this: common);
  v7 = renderSystem->GetGameWindow(this: renderSystem);
  v5->BeginBinkVideo(this: renderSystem, a2: v7, a3: data, a4: VIDEO_EXIT, a5: v6);
  if ( renderSystem->BinkVideoIsLoaded(this: renderSystem) && renderSystem->BinkVideoIsPlaying(this: renderSystem) )
  {
    while ( 1 )
    {
      soundSystem->Render(this: soundSystem, a2: true);
      v12[0] = 0.0;
      v12[1] = 1.0;
      v13 = 0;
      v12[2] = 1.0;
      v12[3] = joy_pitchSpeed.valueFloat;
      v14 = in_invertLook.valueInteger != 0;
      v12[4] = joy_yawSpeed.valueFloat;
      v12[5] = m_sensitivity.valueFloat;
      usercmdGen->GetUsercmd(
        this: (idUsercmdGen *)v15,
        result: (usercmd_t *)usercmdGen,
        a3: 0,
        a4: (const inputSettings_t *)v12,
        a5: true,
        a6: 0);
      sys->GenerateEvents(this: sys);
      sys->GetEvent(this: &v9, result: (sysEvent_t *)sys);
      if ( v9.__vftable == (idSysLocal_vtbl *)1 && v11 == 0 && (v10 == 1 || v10 == 257) )
        break;
      sys->ClearEvents(this: sys);
      mgthread_sleep(ms: 50);
      if ( !renderSystem->BinkVideoIsPlaying(this: renderSystem) )
        goto LABEL_10;
    }
    sys->ClearEvents(this: sys);
  }
LABEL_10:
  renderSystem->FreeBinkVideo(this: renderSystem);
  soundSystem->WaitForSoundThread(this: soundSystem);
  v8 = gameLocal->GetSoundWorld(this: gameLocal);
  ((void (__fastcall *)(idSoundWorld *, _DWORD, double))v8->Fade)(a1: v8, a2: 0, a3: 0.0);
}

