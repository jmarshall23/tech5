
// ========================================================================
// ?Joystick@idSysLocal@@UAAAAVidJoystick@@XZ
// EA  : 0x829D1920
// RVA : 0x009D1920
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

idJoystickXenon *__fastcall idSysLocal::Joystick(idSysLocal *this)
{
  return &joystick;
}


// ========================================================================
// ?PostInputEvent@idJoystickXenon@@IAAXHHH@Z
// EA  : 0x829D1930
// RVA : 0x009D1930
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

void __fastcall idJoystickXenon::PostInputEvent(
        idJoystickXenon *this,
        int inputDeviceNum,
        int event,
        unsigned int value)
{
  int v8; // r5
  char *v9; // r11
  bool v10; // r10
  int v11; // r6
  int v12; // r6
  int v13; // r8
  char *v14; // r29
  int v15; // r11
  int v16; // r11
  char *v17; // r29
  int v18; // r11
  int v19; // r11
  char *v20; // r29
  int v21; // r11
  int v22; // r11
  char *v23; // r29
  int v24; // r11
  int v25; // r11
  char *v26; // r10
  int v27; // r11
  char *v28; // r10
  int v29; // r11

  if ( (unsigned int)event < 0x20 )
  {
    v8 = event + 256;
    v9 = (char *)this + 296 * inputDeviceNum + v8;
    v10 = value != 0;
    v11 = v10;
    if ( v9[408] == v10 )
    {
LABEL_4:
      if ( event < 32 || event > 37 )
        goto LABEL_8;
      goto LABEL_6;
    }
LABEL_3:
    v9[408] = v10;
    sys->QueueEvent(this: sys, a2: SE_KEY, a3: v8, a4: v11, a5: 0, a6: nullptr, a7: inputDeviceNum);
    goto LABEL_4;
  }
  switch ( event )
  {
    case ' ':
      v14 = (char *)this + 296 * inputDeviceNum;
      v15 = (((~value & 0x80000000) == 0) + (value >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v14[682] != v15 )
      {
        v14[682] = v15;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 274, a4: v15, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v16 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
      if ( (unsigned __int8)v14[683] != v16 )
      {
        v14[683] = v16;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 275, a4: v16, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      break;
    case '!':
      v17 = (char *)this + 296 * inputDeviceNum;
      v18 = (((~value & 0x80000000) == 0) + (value >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v17[680] != v18 )
      {
        v17[680] = v18;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 272, a4: v18, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v19 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
      if ( (unsigned __int8)v17[681] != v19 )
      {
        v17[681] = v19;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 273, a4: v19, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      break;
    case '"':
      v20 = (char *)this + 296 * inputDeviceNum;
      v21 = (((~value & 0x80000000) == 0) + (value >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v20[686] != v21 )
      {
        v20[686] = v21;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 278, a4: v21, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v22 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
      if ( (unsigned __int8)v20[687] != v22 )
      {
        v20[687] = v22;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 279, a4: v22, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      break;
    case '#':
      v23 = (char *)this + 296 * inputDeviceNum;
      v24 = (((~value & 0x80000000) == 0) + (value >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v23[684] != v24 )
      {
        v23[684] = v24;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 276, a4: v24, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v25 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
      if ( (unsigned __int8)v23[685] != v25 )
      {
        v23[685] = v25;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 277, a4: v25, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      break;
    default:
      if ( event >= 38 && event <= 41 )
      {
        v8 = event + 244;
        v9 = (char *)&this->events[37 * inputDeviceNum + 29].value + event;
        v10 = value != 0;
        v11 = v10;
        if ( v9[408] == v10 )
          goto LABEL_4;
        goto LABEL_3;
      }
      if ( event == 36 )
      {
        v26 = (char *)this + 296 * inputDeviceNum;
        v27 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
        if ( (unsigned __int8)v26[688] != v27 )
        {
          v26[688] = v27;
          sys->QueueEvent(this: sys, a2: SE_KEY, a3: 280, a4: v27, a5: 0, a6: nullptr, a7: inputDeviceNum);
        }
      }
      else
      {
        if ( event != 37 )
          goto LABEL_4;
        v28 = (char *)this + 296 * inputDeviceNum;
        v29 = (((value & 0x80000000) == 0) + (value <= 0x4000)) & 1;
        if ( (unsigned __int8)v28[689] != v29 )
        {
          v28[689] = v29;
          sys->QueueEvent(this: sys, a2: SE_KEY, a3: 281, a4: v29, a5: 0, a6: nullptr, a7: inputDeviceNum);
        }
      }
      break;
  }
LABEL_6:
  v12 = ((int)(16 * value) >> 14) + ((value & 0x8000000) != 0 && ((16 * value) & 0x3FFF) != 0);
  v13 = 6 * inputDeviceNum + event - 32 + 398;
  if ( *((_DWORD *)&this->__vftable + v13) != v12 )
  {
    *((_DWORD *)&this->__vftable + v13) = v12;
    sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: event - 32, a4: v12, a5: 0, a6: nullptr, a7: inputDeviceNum);
  }
LABEL_8:
  this->events[this->numEvents].event = event;
  this->events[this->numEvents++].value = value;
}


// ========================================================================
// ?ReturnInputEvent@idJoystickXenon@@UAAHHAAH0@Z
// EA  : 0x829D1E70
// RVA : 0x009D1E70
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

int __fastcall idJoystickXenon::ReturnInputEvent(idJoystickXenon *this, unsigned int n, int *action, int *value)
{
  char *v6; // r11

  if ( n > 0x29 )
    return 0;
  v6 = (char *)this + 8 * n;
  *action = *((_DWORD *)v6 + 2);
  *value = *((_DWORD *)v6 + 3);
  return 1;
}


// ========================================================================
// ?TestInputTimes_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829D1EB0
// RVA : 0x009D1EB0
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

void __fastcall TestInputTimes_f(const idCmdArgs *args)
{
  int v1; // r28
  int v2; // r30
  int v3; // r31
  _XINPUT_STATE v4; // [sp+50h] [-50h] BYREF
  _XINPUT_STATE v5; // [sp+60h] [-40h] BYREF

  idLib::Printf(fmt: "Polling for ten seconds...\n");
  common->UpdateConsoleDisplay(this: common, a2: true);
  v1 = Sys_Milliseconds();
  XInputGetState(dwUserIndex: 0, pXInputState: &v5);
  v2 = v1;
  do
  {
    v3 = Sys_Milliseconds();
    XInputGetState(dwUserIndex: 0, pXInputState: &v4);
    if ( v4.dwPacketNumber != v5.dwPacketNumber && v4.Gamepad.wButtons != v5.Gamepad.wButtons )
    {
      v5 = v4;
      idLib::Printf(fmt: "0x%x: %i\n", v4.Gamepad.wButtons, v3 - v2);
      v2 = v3;
    }
  }
  while ( v3 - v1 < 10000 );
}


// ========================================================================
// ?PollInputEvents@idJoystickXenon@@UAAHH@Z
// EA  : 0x829D1F88
// RVA : 0x009D1F88
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

int __fastcall idJoystickXenon::PollInputEvents(idJoystickXenon *this, unsigned int inputDeviceNum)
{
  __int64 v2; // r27
  unsigned int State; // r3
  bool v7; // r28
  idGame *v8; // r3
  idGame *v9; // r3
  idGame *v10; // r3
  char *v11; // r26
  int v12; // r29
  int *v13; // r28
  int v14; // r11
  unsigned int v15; // r29
  char *v16; // r10
  int v17; // r11
  idJoystickXenon_vtbl *v18; // r6
  int v19; // r11
  unsigned int v20; // r29
  char *v21; // r10
  int v22; // r11
  int v23; // r6
  char *v24; // r11
  unsigned int v25; // r28
  char *v26; // r29
  int v27; // r11
  int v28; // r11
  int v29; // r6
  char *v30; // r11
  int sThumbRX; // r28
  char *v32; // r29
  int v33; // r11
  int v34; // r11
  int v35; // r6
  char *v36; // r11
  unsigned int v37; // r28
  char *v38; // r29
  int v39; // r11
  int v40; // r11
  int v41; // r6
  char *v42; // r11
  int v43; // r9
  int v44; // r8
  int v45; // r7
  _XINPUT_STATE v46; // [sp+50h] [-50h] BYREF

  LODWORD(v2) = 0;
  this->numEvents = 0;
  State = XInputGetState(dwUserIndex: inputDeviceNum, pXInputState: &v46);
  if ( State != 0 )
  {
    if ( State != 1167 )
      return 0;
    *(_QWORD *)&v46.dwPacketNumber = v2;
    *(_QWORD *)&v46.Gamepad.sThumbLX = v2;
    if ( !common->IsMultiplayer(this: common) && common->GetMasterLocalUserInputDevice(this: common) == inputDeviceNum )
    {
      v7 = false;
      if ( common->Game(this: common) != nullptr )
      {
        v8 = common->Game(this: common);
        v7 = v8->Shell_IsActive(this: v8);
      }
      if ( common->Game(this: common) != nullptr )
      {
        v9 = common->Game(this: common);
        if ( v9->IsGameActive(this: v9) && !common->IsMainMenuActive(this: common) && !v7 )
        {
          v10 = common->Game(this: common);
          v10->Shell_Show(this: v10, a2: true);
        }
      }
    }
    this->previousState[inputDeviceNum] = 1167;
  }
  else
  {
    this->previousState[inputDeviceNum] = 0;
  }
  if ( session->IsSystemUIShowing(this: session) )
  {
    *(_QWORD *)&v46.dwPacketNumber = v2;
    *(_QWORD *)&v46.Gamepad.sThumbLX = v2;
  }
  v11 = (char *)this + 16 * inputDeviceNum;
  if ( v46.dwPacketNumber != *((_DWORD *)v11 + 86) )
  {
    v12 = 1;
    v13 = joyRemap;
    do
    {
      v14 = (unsigned __int16)(v46.Gamepad.wButtons & v12);
      if ( v14 != (unsigned __int16)(*((_WORD *)v11 + 174) & v12) )
        idJoystickXenon::PostInputEvent(this, inputDeviceNum, event: *v13, value: (-v14 & (unsigned int)~v14) >> 31);
      ++v13;
      v12 = __ROL4__(v12, 1);
    }
    while ( (int)v13 < (int)&idJoystickXenon `RTTI Type Descriptor' );
    if ( v46.Gamepad.bLeftTrigger != v11[350] )
    {
      v15 = v46.Gamepad.bLeftTrigger << 7;
      v16 = (char *)this + 296 * inputDeviceNum;
      v17 = ((v15 <= 0x4000) + 1) & 1;
      if ( (unsigned __int8)v16[688] != v17 )
      {
        v16[688] = v17;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 280, a4: v17, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v18 = (idJoystickXenon_vtbl *)(((int)(16 * v15) >> 14) + ((v15 & 0x8000000) != 0 && ((16 * v15) & 0x3FFF) != 0));
      v19 = 24 * (inputDeviceNum + 67);
      if ( *(idJoystickXenon_vtbl **)((char *)&this->__vftable + v19) != v18 )
      {
        *(idJoystickXenon_vtbl **)((char *)&this->__vftable + v19) = v18;
        sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: 4, a4: (int)v18, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      this->events[this->numEvents].event = 36;
      this->events[this->numEvents++].value = v15;
    }
    if ( v46.Gamepad.bRightTrigger != v11[351] )
    {
      v20 = v46.Gamepad.bRightTrigger << 7;
      v21 = (char *)this + 296 * inputDeviceNum;
      v22 = ((v20 <= 0x4000) + 1) & 1;
      if ( (unsigned __int8)v21[689] != v22 )
      {
        v21[689] = v22;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 281, a4: v22, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v23 = ((int)(16 * v20) >> 14) + ((v20 & 0x8000000) != 0 && ((16 * v20) & 0x3FFF) != 0);
      v24 = (char *)this + 24 * inputDeviceNum;
      if ( *((_DWORD *)v24 + 403) != v23 )
      {
        *((_DWORD *)v24 + 403) = v23;
        sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: 5, a4: v23, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      this->events[this->numEvents].event = 37;
      this->events[this->numEvents++].value = v20;
    }
    if ( v46.Gamepad.sThumbLX != this->oldXis[inputDeviceNum].Gamepad.sThumbLX )
      idJoystickXenon::PostInputEvent(this, inputDeviceNum, event: 32, value: v46.Gamepad.sThumbLX);
    if ( v46.Gamepad.sThumbLY != *((__int16 *)v11 + 177) )
    {
      v25 = -v46.Gamepad.sThumbLY;
      v26 = (char *)this + 296 * inputDeviceNum;
      v27 = ((v46.Gamepad.sThumbLY - 1 >= 0) + (v25 >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v26[680] != v27 )
      {
        v26[680] = v27;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 272, a4: v27, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v28 = (((v25 & 0x80000000) == 0) + (v25 <= 0x4000)) & 1;
      if ( (unsigned __int8)v26[681] != v28 )
      {
        v26[681] = v28;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 273, a4: v28, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v29 = ((int)(16 * v25) >> 14) + ((v25 & 0x8000000) != 0 && ((16 * v25) & 0x3FFF) != 0);
      v30 = (char *)this + 24 * inputDeviceNum;
      if ( *((_DWORD *)v30 + 399) != v29 )
      {
        *((_DWORD *)v30 + 399) = v29;
        sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: 1, a4: v29, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      this->events[this->numEvents].event = 33;
      this->events[this->numEvents++].value = v25;
    }
    sThumbRX = v46.Gamepad.sThumbRX;
    if ( v46.Gamepad.sThumbRX != *((__int16 *)v11 + 178) )
    {
      v32 = (char *)this + 296 * inputDeviceNum;
      v33 = ((~v46.Gamepad.sThumbRX >= 0) + ((unsigned int)v46.Gamepad.sThumbRX >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v32[686] != v33 )
      {
        v32[686] = v33;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 278, a4: v33, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v34 = ((sThumbRX >= 0) + ((unsigned int)sThumbRX <= 0x4000)) & 1;
      if ( (unsigned __int8)v32[687] != v34 )
      {
        v32[687] = v34;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 279, a4: v34, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v35 = ((16 * sThumbRX) >> 14) + ((sThumbRX & 0x8000000) != 0 && ((16 * sThumbRX) & 0x3FFF) != 0);
      v36 = (char *)this + 24 * inputDeviceNum;
      if ( *((_DWORD *)v36 + 400) != v35 )
      {
        *((_DWORD *)v36 + 400) = v35;
        sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: 2, a4: v35, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      this->events[this->numEvents].event = 34;
      this->events[this->numEvents++].value = sThumbRX;
    }
    if ( v46.Gamepad.sThumbRY != *((__int16 *)v11 + 179) )
    {
      v37 = -v46.Gamepad.sThumbRY;
      v38 = (char *)this + 296 * inputDeviceNum;
      v39 = ((v46.Gamepad.sThumbRY - 1 >= 0) + (v37 >= 0xFFFFC000)) & 1;
      if ( (unsigned __int8)v38[684] != v39 )
      {
        v38[684] = v39;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 276, a4: v39, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v40 = (((v37 & 0x80000000) == 0) + (v37 <= 0x4000)) & 1;
      if ( (unsigned __int8)v38[685] != v40 )
      {
        v38[685] = v40;
        sys->QueueEvent(this: sys, a2: SE_KEY, a3: 277, a4: v40, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      v41 = ((int)(16 * v37) >> 14) + ((v37 & 0x8000000) != 0 && ((16 * v37) & 0x3FFF) != 0);
      v42 = (char *)this + 24 * inputDeviceNum;
      if ( *((_DWORD *)v42 + 401) != v41 )
      {
        *((_DWORD *)v42 + 401) = v41;
        sys->QueueEvent(this: sys, a2: SE_JOYSTICK, a3: 3, a4: v41, a5: 0, a6: nullptr, a7: inputDeviceNum);
      }
      this->events[this->numEvents].event = 35;
      this->events[this->numEvents++].value = v37;
    }
    v43 = *(_DWORD *)&v46.Gamepad.sThumbRX;
    v44 = *(_DWORD *)&v46.Gamepad.sThumbLX;
    v45 = *(_DWORD *)&v46.Gamepad.wButtons;
    *((_DWORD *)v11 + 86) = v46.dwPacketNumber;
    *((_DWORD *)v11 + 89) = v43;
    *((_DWORD *)v11 + 88) = v44;
    *((_DWORD *)v11 + 87) = v45;
  }
  return this->numEvents;
}


// ========================================================================
// ?TestJoypadRates_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x829D2800
// RVA : 0x009D2800
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

void __fastcall TestJoypadRates_f(const idCmdArgs *args)
{
  int v1; // r27
  unsigned int dwPacketNumber; // r29
  int v3; // r30
  int v4; // r31
  _XINPUT_STATE v5; // [sp+50h] [-40h] BYREF

  v1 = Sys_Milliseconds();
  dwPacketNumber = 0;
  v3 = v1;
  v4 = Sys_Milliseconds();
  if ( v4 - v1 <= 1000 )
  {
    while ( XInputGetState(dwUserIndex: 0, pXInputState: &v5) == 0 )
    {
      if ( v5.dwPacketNumber != dwPacketNumber )
      {
        dwPacketNumber = v5.dwPacketNumber;
        idLib::Printf(fmt: "%i msec\n", v4 - v3);
        v3 = v4;
      }
      v4 = Sys_Milliseconds();
      if ( v4 - v1 > 1000 )
        return;
    }
    idLib::Printf(fmt: "XInputGetState error\n");
  }
}


// ========================================================================
// ?SetRumble@idJoystickXenon@@UAAXHHH@Z
// EA  : 0x829D28F8
// RVA : 0x009D28F8
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

void __fastcall idJoystickXenon::SetRumble(
        idJoystickXenon *this,
        unsigned int deviceNum,
        int rumbleLow,
        int rumbleHigh)
{
  unsigned __int16 v4; // r11
  _XINPUT_VIBRATION v5; // [sp+50h] [-10h] BYREF

  v4 = -1;
  if ( rumbleLow >= 0 )
  {
    if ( rumbleLow > 0xFFFF )
      LOWORD(rumbleLow) = -1;
  }
  else
  {
    LOWORD(rumbleLow) = 0;
  }
  v5.wLeftMotorSpeed = rumbleLow;
  if ( rumbleHigh >= 0 )
  {
    if ( rumbleHigh <= 0xFFFF )
      v4 = rumbleHigh;
  }
  else
  {
    v4 = 0;
  }
  v5.wRightMotorSpeed = v4;
  XInputSetState(dwUserIndex: deviceNum, pVibration: &v5);
}


// ========================================================================
// `dynamic initializer for 'joystick''
// EA  : 0x83363B80
// RVA : 0x01363B80
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joystick__()
{
  memset(Dst: joystick.events, Val: 0, Size: sizeof(joystick.events));
  memset(Dst: joystick.oldXis, Val: 0, Size: sizeof(joystick.oldXis));
  memset(Dst: joystick.buttonStates, Val: 0, Size: sizeof(joystick.buttonStates));
  memset(Dst: joystick.joyAxis, Val: 0, Size: sizeof(joystick.joyAxis));
  joystick.previousState[0] = 0;
  joystick.previousState[1] = 0;
  joystick.previousState[2] = 0;
  joystick.previousState[3] = 0;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joystick__);
}


// ========================================================================
// `dynamic initializer for 'TestInputTimes_v''
// EA  : 0x83363C10
// RVA : 0x01363C10
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestInputTimes_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestInputTimes_v,
           cmdName: "TestInputTimes",
           function: TestInputTimes_f,
           description: "Reports msec timings on input polling changed",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestJoypadRates_v''
// EA  : 0x83363C38
// RVA : 0x01363C38
// PDB : w:\tech5\engine\sys\xenon\xen_input_joystick.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestJoypadRates_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestJoypadRates_v,
           cmdName: "TestJoypadRates",
           function: TestJoypadRates_f,
           description: "time joypad update rates",
           argCompletion: nullptr);
}

