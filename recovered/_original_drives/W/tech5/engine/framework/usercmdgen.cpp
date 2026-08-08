
// ========================================================================
// ?ClearMoveCmds@usercmd_t@@QAAXXZ
// EA  : 0x826A7940
// RVA : 0x006A7940
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall usercmd_t::ClearMoveCmds(usercmd_t *this)
{
  this->upmove = 0;
  this->rightmove = 0;
  this->forwardmove = 0;
}


// ========================================================================
// ?Print@usercmd_t@@QBAXXZ
// EA  : 0x826A7958
// RVA : 0x006A7958
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall usercmd_t::Print(usercmd_t *this)
{
  double v2; // [sp+18h] [-48h]

  idLib::Printf(fmt: "Frame: %d\n", this->clientGameFrame);
  idLib::Printf(fmt: "Server game time: %d\n", this->serverGameTime);
  idLib::Printf(fmt: "Buttons: %x, Buttons2: %x\n", this->buttons, this->buttons2);
  idLib::Printf(fmt: "forward: %d, right: %d, up: %d\n", this->forwardmove, this->rightmove, this->upmove);
  idLib::Printf(fmt: "inhibit: %d\n", *((unsigned __int8 *)this + 9) >> 7);
  idLib::Printf(fmt: "fromBot: %d\n", (*((_BYTE *)this + 9) & 0x40) != 0);
  idLib::Printf(fmt: "angles: %d %d %d\n", this->angles[0], this->angles[1], this->angles[2]);
  v2 = this->pos[0];
  idLib::Printf(
    fmt: (const char *)(HIDWORD(v2) - 13180),
    LODWORD(v2),
    (unsigned int)COERCE_UNSIGNED_INT64(this->pos[1]),
    (unsigned int)COERCE_UNSIGNED_INT64(this->pos[2]));
  idLib::Printf(fmt: "speed: %d\n", this->speed);
  idLib::Printf(fmt: "pitch: %d, yaw: %d, roll: %d\n", this->pitch, this->yaw, this->roll);
  idLib::Printf(fmt: "predictionStateBits: %x\n", this->predictionStateBits);
  idLib::Printf(fmt: "vehicle throttle: %d\n", this->vehicleThrottle);
  idLib::Printf(fmt: "fire count: %d\n", this->fireCount);
  idLib::Printf(fmt: "fire angles: %d %d\n", this->fireAngles[0], this->fireAngles[1]);
  idLib::Printf(fmt: "firePos: %d %d %d\n", this->firePos[0], this->firePos[1], this->firePos[2]);
}


// ========================================================================
// ?BindStringUsercmdAction@idUsercmdGenLocal@@UBA?AW4cmdGenButton_t@@PBD@Z
// EA  : 0x826A7B00
// RVA : 0x006A7B00
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

int __fastcall idUsercmdGenLocal::BindStringUsercmdAction(idUsercmdGenLocal *this, const char *cmdString)
{
  userCmdString_t *v3; // r31

  v3 = userCmdStrings;
  if ( userCmdStrings[0].string == nullptr )
    return 58;
  while ( idStr::Icmp(s1: cmdString, s2: v3->string) != 0 )
  {
    ++v3;
    if ( v3->string == nullptr )
      return 58;
  }
  return v3->button;
}


// ========================================================================
// ?Shutdown@idUsercmdGenLocal@@UAAXXZ
// EA  : 0x826A7B70
// RVA : 0x006A7B70
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Shutdown(idUsercmdGenLocal *this)
{
  this->initialized = false;
}


// ========================================================================
// ?Clear@idUsercmdGenLocal@@UAAXXZ
// EA  : 0x826A7B80
// RVA : 0x006A7B80
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Clear(idUsercmdGenLocal *this)
{
  float *v2; // r31
  int i; // r30

  v2 = &this->devices[0].joystickAxis[4];
  for ( i = 4; i != 0; --i )
  {
    memset(Dst: v2 - 78, Val: 0, Size: 0x128u);
    *v2 = 0.0;
    v2[1] = 0.0;
    v2 += 84;
  }
  this->lastInputFrame = 0;
  this->currentSettings.bindset = BIND_DEFAULT;
  this->currentSettings.joySensScale = 1.0;
  this->currentSettings.mouseSensScale = 1.0;
}


// ========================================================================
// ?Key@idUsercmdGenLocal@@AAAXHH_N@Z
// EA  : 0x826A7BF0
// RVA : 0x006A7BF0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Key(
        idUsercmdGenLocal *this,
        unsigned int inputDeviceNum,
        keyNum_t keyNum,
        bool down)
{
  this->currentDevice->keyState[keyNum] = down;
  if ( down )
    this->buttonState[idKeyInput::GetUsercmdAction(
                        numDevice: inputDeviceNum,
                        bindset: this->currentSettings.bindset,
                        keynum: keyNum)] = true;
}


// ========================================================================
// ?Mouse@idUsercmdGenLocal@@AAAXH@Z
// EA  : 0x826A7C48
// RVA : 0x006A7C48
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Mouse(idUsercmdGenLocal *this, unsigned int inputDeviceNum)
{
  idMouse *v4; // r3
  int v5; // r3
  int v6; // r26
  int v7; // r28
  idMouse *v8; // r3
  __int64 v9; // r10
  keyNum_t v10; // r31
  double v11; // fp10
  double v12; // fp10
  idMouse *v13; // r3
  unsigned int v14; // [sp+50h] [-50h] BYREF
  unsigned int v15; // [sp+54h] [-4Ch] BYREF
  __int64 v16; // [sp+58h] [-48h]
  __int64 v17; // [sp+60h] [-40h]

  if ( this->currentDeviceNum == 0 )
  {
    v4 = sys->Mouse(this: sys);
    v5 = v4->PollInputEvents(this: v4);
    v6 = v5;
    if ( v5 != 0 )
    {
      v7 = 0;
      if ( v5 > 0 )
      {
        do
        {
          v8 = sys->Mouse(this: sys);
          if ( v8->ReturnInputEvent(this: v8, a2: v7, a3: (int *)&v15, a4: (int *)&v14) != 0 )
          {
            if ( v15 >= 8 )
            {
              if ( v15 == 8 )
              {
                LODWORD(v9) = v14;
                v12 = (float)((float)v9 + this->mouseDx);
                v17 = v9;
                this->mouseDx = v12;
              }
              else if ( v15 == 9 )
              {
                LODWORD(v9) = v14;
                v11 = (float)((float)v9 + this->mouseDy);
                v16 = v9;
                this->mouseDy = v11;
              }
              else if ( v15 == 10 && v14 != 0 )
              {
                v10 = ((_cntlzw(_cntlzw(v14)) & 0x20) == 0) + 294;
                idUsercmdGenLocal::Key(this, inputDeviceNum, keyNum: v10, down: true);
                idUsercmdGenLocal::Key(this, inputDeviceNum, keyNum: v10, down: false);
              }
            }
            else
            {
              idUsercmdGenLocal::Key(this, inputDeviceNum, keyNum: (keyNum_t)(v15 + 286), down: v14 != 0);
            }
          }
          ++v7;
        }
        while ( v7 < v6 );
      }
    }
    v13 = sys->Mouse(this: sys);
    v13->EndInputEvents(this: v13);
  }
}


// ========================================================================
// ?Keyboard@idUsercmdGenLocal@@AAAXH@Z
// EA  : 0x826A7DF8
// RVA : 0x006A7DF8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Keyboard(idUsercmdGenLocal *this, unsigned int inputDeviceNum)
{
  idKeyboard *v4; // r3
  int v5; // r27
  int i; // r30
  idKeyboard *v7; // r3
  keyNum_t v8; // r10
  bool v9; // cr58
  idKeyboard *v10; // r3
  bool v11[4]; // [sp+50h] [-40h] BYREF
  keyNum_t v12; // [sp+54h] [-3Ch] BYREF

  if ( this->currentDeviceNum == 0 )
  {
    v4 = sys->Keyboard(this: sys);
    v5 = v4->PollInputEvents(this: v4);
    for ( i = 0; i < v5; ++i )
    {
      v7 = sys->Keyboard(this: sys);
      if ( v7->ReturnInputEvent(this: v7, a2: i, a3: (int *)&v12, a4: v11) != 0 )
      {
        v8 = v12;
        v9 = !v11[0];
        this->currentDevice->keyState[v12] = v11[0];
        if ( !v9 )
          this->buttonState[idKeyInput::GetUsercmdAction(
                              numDevice: inputDeviceNum,
                              bindset: this->currentSettings.bindset,
                              keynum: v8)] = true;
      }
    }
    v10 = sys->Keyboard(this: sys);
    v10->EndInputEvents(this: v10);
  }
}


// ========================================================================
// ?Joystick@idUsercmdGenLocal@@AAAXH@Z
// EA  : 0x826A7EF8
// RVA : 0x006A7EF8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Joystick(idUsercmdGenLocal *this, unsigned int inputDeviceNum)
{
  idJoystick *v4; // r3
  int v5; // r26
  int i; // r29
  idJoystick *v7; // r3
  keyNum_t v8; // r5
  idUsercmdGenLocal::usercmdDevice_t *currentDevice; // r8
  __int64 v10; // r7
  BOOL v11; // r8
  idJoystick *v12; // r3
  int v13; // [sp+50h] [-50h] BYREF
  int v14; // [sp+54h] [-4Ch] BYREF
  __int64 v15; // [sp+58h] [-48h]

  v4 = sys->Joystick(this: sys);
  v5 = v4->PollInputEvents(this: v4, a2: this->currentDeviceNum);
  for ( i = 0; i < v5; ++i )
  {
    v7 = sys->Joystick(this: sys);
    if ( v7->ReturnInputEvent(this: v7, a2: i, a3: &v14, a4: &v13) != 0 )
    {
      if ( (unsigned int)v14 < 0x20 )
      {
        v8 = v14 + 256;
        goto LABEL_11;
      }
      if ( v14 < 32 || v14 > 37 )
      {
        if ( v14 >= 38 && v14 <= 41 )
        {
          v8 = v14 + 244;
LABEL_11:
          v11 = v13 != 0;
          this->currentDevice->keyState[v8] = v13 != 0;
          if ( v11 )
            this->buttonState[idKeyInput::GetUsercmdAction(
                                numDevice: inputDeviceNum,
                                bindset: this->currentSettings.bindset,
                                keynum: v8)] = true;
        }
      }
      else
      {
        currentDevice = this->currentDevice;
        LODWORD(v10) = v13;
        HIDWORD(v10) = 4 * (v14 + 46);
        v15 = v10;
        *(float *)((char *)&currentDevice->lastPollTime + HIDWORD(v10)) = (float)v10 * (float)0.000030518509;
      }
    }
  }
  v12 = sys->Joystick(this: sys);
  v12->EndInputEvents(this: v12);
}


// ========================================================================
// ?KeyMove@idUsercmdGenLocal@@AAAXXZ
// EA  : 0x826A8120
// RVA : 0x006A8120
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUsercmdGenLocal::KeyMove(idUsercmdGenLocal *this)
{
  int v1; // r10
  int v2; // r8
  int v3; // r9
  char v4; // r11
  char v5; // r11
  char v6; // r11
  __int128 v7; // r7
  int pollTime; // r31
  double v9; // fp10
  double v10; // fp1

  v1 = 127 * (this->buttonState[52] - this->buttonState[53]);
  v2 = 127 * (this->buttonState[51] - this->buttonState[50]);
  v3 = 127 * (this->buttonState[48] - this->buttonState[49]);
  if ( v1 >= -128 )
  {
    v4 = 127;
    if ( v1 <= 127 )
      v4 = 127 * (this->buttonState[52] - this->buttonState[53]);
  }
  else
  {
    v4 = 0x80;
  }
  this->cmd.forwardmove = v4;
  if ( v2 >= -128 )
  {
    v5 = 127;
    if ( v2 <= 127 )
      v5 = v2;
  }
  else
  {
    v5 = 0x80;
  }
  this->cmd.rightmove = v5;
  if ( v3 >= -128 )
  {
    v6 = 127;
    if ( v3 <= 127 )
      v6 = v3;
  }
  else
  {
    v6 = 0x80;
  }
  DWORD1(v7) = this->currentDevice;
  LODWORD(v7) = this->buttonState[57];
  DWORD2(v7) = &in_angleSpeedKey;
  pollTime = this->pollTime;
  this->cmd.upmove = v6;
  v9 = (double)(__int64)v7;
  DWORD2(v7) = pollTime - *(_DWORD *)DWORD1(v7);
  v10 = (float)((float)((float)((float)*(__int64 *)((char *)&v7 + 4) * this->currentSettings.joySensScale)
                      * in_angleSpeedKey.valueFloat)
              * (float)0.001);
  *(float *)(DWORD1(v7) + 8) = -(float)((float)((float)((float)v9 * in_yawSpeed.valueFloat)
                                              * (float)((float)((float)((float)*(__int64 *)((char *)&v7 + 4)
                                                                      * this->currentSettings.joySensScale)
                                                              * in_angleSpeedKey.valueFloat)
                                                      * (float)0.001))
                                      - *(float *)(DWORD1(v7) + 8));
  DWORD2(v7) = &in_pitchSpeed;
  HIDWORD(v7) = this->buttonState[56];
  this->currentDevice->angles.yaw = (float)((float)((float)*(__int64 *)(&this - 1) * in_yawSpeed.valueFloat) * (float)v10)
                                  + this->currentDevice->angles.yaw;
  LODWORD(v7) = this->buttonState[54];
  this->currentDevice->angles.pitch = -(float)((float)((float)((float)(__int64)v7 * in_pitchSpeed.valueFloat)
                                                     * (float)v10)
                                             - this->currentDevice->angles.pitch);
  DWORD1(v7) = this->buttonState[55];
  this->currentDevice->angles.pitch = (float)((float)((float)*(__int64 *)&v7 * in_pitchSpeed.valueFloat) * (float)v10)
                                    + this->currentDevice->angles.pitch;
  if ( v1 != 0 || v3 != 0 || v2 != 0 )
    this->aimAssist = false;
}


// ========================================================================
// ?MouseMove@idUsercmdGenLocal@@AAAXXZ
// EA  : 0x826A82F8
// RVA : 0x006A82F8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::MouseMove(idUsercmdGenLocal *this)
{
  int v1; // r8
  int v3; // r5
  double valueFloat; // fp0
  bool v5; // mr_fpscr48
  unsigned int v6; // r9
  double v7; // fp13
  double v8; // fp12
  int v9; // r10
  int v10; // r6
  double v11; // fp10
  double v12; // fp0
  double v13; // fp13
  double v14; // fp31
  double v15; // fp29
  double v16; // fp13

  v1 = historyCounter;
  v3 = (8 * historyCounter) & 0x38;
  valueFloat = m_smooth.valueFloat;
  v5 = m_smooth.valueFloat < 1.0;
  *(float *)((char *)history[0] + v3) = this->mouseDx;
  *(float *)((char *)&history[0][1] + v3) = this->mouseDy;
  if ( v5 )
  {
    valueFloat = 1.0;
  }
  else if ( valueFloat > 8.0 )
  {
    valueFloat = 8.0;
  }
  v6 = 0;
  v7 = 0.0;
  v8 = 0.0;
  if ( valueFloat > 0.0 )
  {
    v9 = v1;
    do
    {
      ++v6;
      v10 = (8 * v9--) & 0x38;
      v7 = (float)(*(float *)((char *)history[0] + v10) + (float)v7);
      v8 = (float)(*(float *)((char *)&history[0][1] + v10) + (float)v8);
    }
    while ( (float)__SPAIR64__((float (*)[2])&history[0][1], v6) < valueFloat );
  }
  v11 = (float)((float)1.0 / (float)valueFloat);
  historyCounter = v1 + 1;
  v12 = (float)((float)((float)1.0 / (float)valueFloat) * (float)v7);
  v13 = (float)((float)v11 * (float)v8);
  if ( __fabs(v12) > 1000.0 || __fabs(v13) > 1000.0 )
  {
    v13 = 0.0;
    v12 = 0.0;
  }
  v14 = (float)((float)(this->currentSettings.mouseSens * this->currentSettings.mouseSensScale) * (float)v12);
  v15 = (float)((float)(this->currentSettings.mouseSens * this->currentSettings.mouseSensScale) * (float)v13);
  if ( m_showMouseRate.valueInteger != 0 )
    idLib::Printf(
      fmt: "[%f %f | %f %f ]\n",
      this->mouseDx,
      this->mouseDy,
      v14,
      (float)((float)(this->currentSettings.mouseSens * this->currentSettings.mouseSensScale) * (float)v13));
  this->mouseDx = 0.0;
  this->mouseDy = 0.0;
  this->currentDevice->angles.yaw = -(float)((float)(m_yaw.valueFloat * (float)v14) - this->currentDevice->angles.yaw);
  if ( this->currentSettings.lookInvert )
    v16 = -v15;
  else
    v16 = v15;
  this->currentDevice->angles.pitch = (float)((float)v16 * m_pitch.valueFloat) + this->currentDevice->angles.pitch;
  if ( v14 != 0.0 || v15 != 0.0 )
  {
    this->joystickSnapDisabled = true;
    this->aimAssist = false;
  }
}


// ========================================================================
// ?CircleToSquare@idUsercmdGenLocal@@ABAXAAM0@Z
// EA  : 0x826A8510
// RVA : 0x006A8510
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::CircleToSquare(
        idUsercmdGenLocal *this,
        float *axis_x,
        float *axis_y,
        double a4,
        double a5,
        long double a6)
{
  char v8; // r27
  char v9; // r28
  char v10; // r29
  double v11; // fp13
  double v12; // fp31
  double v13; // fp29
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp0
  double v17; // fp13

  v8 = 0;
  if ( *axis_x < 0.0 )
  {
    *axis_x = *axis_x * (float)-1.0;
    v8 = 1;
  }
  v9 = 0;
  if ( *axis_y < 0.0 )
  {
    *axis_y = *axis_y * (float)-1.0;
    v9 = 1;
  }
  v10 = 0;
  v11 = *axis_x;
  if ( *axis_y > v11 )
  {
    *axis_x = *axis_y;
    v10 = 1;
    *axis_y = v11;
  }
  if ( *axis_x >= 0.001 )
  {
    v12 = __fsqrts((float)((float)(*axis_y * *axis_y) + (float)(*axis_x * *axis_x)));
    if ( v12 > 1.0 )
      v12 = 1.0;
    v13 = (float)(*axis_y / *axis_x);
    *(double *)&v14 = v12;
    *((double *)&v14 + 1) = joy_circleToSquarePower.valueFloat;
    v15 = pow(x: v14, y: a6);
    *axis_x = (float)((float)((float)v12 - *axis_x) * (float)*(double *)&v15) + *axis_x;
    v16 = (float)((float)((float)((float)v13 - *axis_y) * (float)*(double *)&v15) + *axis_y);
    *axis_y = (float)((float)((float)v13 - *axis_y) * (float)*(double *)&v15) + *axis_y;
    if ( v10 != 0 )
    {
      v17 = *axis_x;
      *axis_x = v16;
      *axis_y = v17;
    }
    if ( v8 != 0 )
      *axis_x = *axis_x * (float)-1.0;
    if ( v9 != 0 )
      *axis_y = *axis_y * (float)-1.0;
  }
}


// ========================================================================
// ?HandleJoystickAxis@idUsercmdGenLocal@@AAAXHHMM_NPBVidDeclTable@@@Z
// EA  : 0x826A8670
// RVA : 0x006A8670
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idUsercmdGenLocal::HandleJoystickAxis(
        idUsercmdGenLocal *this,
        unsigned int inputDeviceNum,
        keyNum_t keyNum,
        double unclampedValue,
        double threshold,
        bool positive,
        const idDeclTable *sens,
        char a8,
        int a9)
{
  double v12; // fp0
  double v13; // fp0
  double v14; // fp30
  bindSet_t bindset; // r4
  bool v16; // r4
  cmdGenButton_t UsercmdAction; // r3
  long double v18; // fp4
  cmdGenButton_t v19; // r29
  double v20; // fp31
  unsigned int v21; // r11
  double v22; // fp13
  double v23; // fp0
  __int64 v24; // r8
  __int64 v25; // r6
  int v26; // r2 OVERLAPPED
  long double v28; // fp2
  long double v29; // fp2
  double v30; // fp0
  long double v31; // fp2
  long double v32; // fp2
  int v33; // r11
  int v34; // r11
  int v35; // r11
  double v36; // fp0
  int v37; // r11
  int v38; // r3
  double v40; // fp12
  idUsercmdGenLocal::usercmdDevice_t *currentDevice; // r11
  double v42; // fp0
  int v43; // r11
  int v44; // r3
  double v46; // fp12
  idUsercmdGenLocal::usercmdDevice_t *v47; // r11
  int v48; // r11
  int v49; // r3
  idUsercmdGenLocal::usercmdDevice_t *v51; // r11
  int v52; // r11
  int v53; // r3
  idUsercmdGenLocal::usercmdDevice_t *v55; // r11

  if ( (unclampedValue <= 0.0 || a8 != 0) && (unclampedValue >= 0.0 || a8 == 0) )
  {
    v12 = __fabs(unclampedValue);
    if ( v12 <= threshold )
    {
      if ( v12 >= -threshold )
        return;
      v13 = (float)((float)v12 + (float)threshold);
    }
    else
    {
      v13 = (float)((float)v12 - (float)threshold);
    }
    v14 = (float)((float)v13 / (float)((float)1.0 - (float)threshold));
    if ( v14 != 0.0 )
    {
      bindset = this->currentSettings.bindset;
      this->joystickSnapDisabled = false;
      this->aimAssist = true;
      UsercmdAction = idKeyInput::GetUsercmdAction(numDevice: inputDeviceNum, bindset, keynum: keyNum);
      v19 = UsercmdAction;
      if ( (unsigned int)UsercmdAction >= UB_NEXT_QUICK_ITEM )
      {
        if ( (unsigned int)UsercmdAction < UB_MOVEUP )
          this->cmd.buttons2 |= 1 << UsercmdAction;
      }
      else
      {
        this->cmd.buttons |= 1 << UsercmdAction;
      }
      v20 = v14;
      if ( joy_circleToSquare.valueInteger == 1 )
      {
        v21 = _S13_5;
        if ( (_S13_5 & 1) != 0 )
        {
          v22 = SQUARE_ROOT_OF_TWO;
        }
        else
        {
          v21 = _S13_5 | 1;
          _S13_5 |= 1u;
          v22 = __fsqrts(2.0);
          SQUARE_ROOT_OF_TWO = v22;
        }
        if ( (v21 & 2) != 0 )
        {
          v23 = INV_SQUARE_ROOT_OF_TWO;
        }
        else
        {
          v23 = (float)((float)1.0 / (float)v22);
          INV_SQUARE_ROOT_OF_TWO = (float)1.0 / (float)v22;
          _S13_5 = v21 | 2;
        }
        if ( v14 >= 0.0 )
        {
          if ( v14 <= v23 )
            v23 = v14;
        }
        else
        {
          v23 = 0.0;
        }
        v20 = (float)((float)v22 * (float)v23);
      }
      if ( ucmd_useSensitivityTable.valueInteger != 0 && a9 != 0 )
      {
        _FP0 = (float)((float)(this->currentSettings.joySensScale
                             * idLookupTable::TableLookup(
                                 this: *(idLookupTable **)(a9 + 64),
                                 time: v14,
                                 fastSearch: v16))
                     * (float)v14);
      }
      else
      {
        if ( joy_gammaLook.valueInteger != 0 )
        {
          *(_QWORD *)&v28 = 0x3FF0C08320000000LL;
          *((double *)&v28 + 1) = (float)((float)v20 * (float)100.0);
          v29 = pow(x: v28, y: v18);
          v30 = (float)((float)*(double *)&v29 * (float)0.0099999998);
        }
        else
        {
          *(double *)&v31 = v20;
          *((double *)&v31 + 1) = joy_powerScale.valueFloat;
          v32 = pow(x: v31, y: v18);
          v30 = (float)*(double *)&v32;
        }
        _FP0 = (float)(this->currentSettings.joySensScale * (float)v30);
      }
      switch ( v19 )
      {
        case UB_MOVEUP:
          LODWORD(v24) = this->cmd.upmove;
          v35 = (int)(float)((float)((float)v14 * (float)127.0) + (float)v24);
          goto LABEL_49;
        case UB_MOVEDOWN:
          LODWORD(v24) = this->cmd.upmove;
          v35 = (int)(float)-(float)((float)((float)v14 * (float)127.0) - (float)v24);
LABEL_49:
          if ( v35 >= -128 )
          {
            if ( v35 <= 127 )
              this->cmd.upmove = v35;
            else
              this->cmd.upmove = 127;
          }
          else
          {
            this->cmd.upmove = 0x80;
          }
          return;
        case UB_MOVELEFT:
          LODWORD(v24) = this->cmd.rightmove;
          v34 = (int)(float)-(float)((float)((float)v20 * (float)127.0) - (float)v24);
          goto LABEL_42;
        case UB_MOVERIGHT:
          LODWORD(v24) = this->cmd.rightmove;
          v34 = (int)(float)((float)((float)v20 * (float)127.0) + (float)v24);
LABEL_42:
          if ( v34 >= -128 )
          {
            if ( v34 <= 127 )
              this->cmd.rightmove = v34;
            else
              this->cmd.rightmove = 127;
          }
          else
          {
            this->cmd.rightmove = 0x80;
          }
          return;
        case UB_MOVEFORWARD:
          LODWORD(v24) = this->cmd.forwardmove;
          v33 = (int)(float)((float)((float)v20 * (float)127.0) + (float)v24);
          goto LABEL_35;
        case UB_MOVEBACK:
          LODWORD(v24) = this->cmd.forwardmove;
          v33 = (int)(float)-(float)((float)((float)v20 * (float)127.0) - (float)v24);
LABEL_35:
          if ( v33 >= -128 )
          {
            if ( v33 <= 127 )
              this->cmd.forwardmove = v33;
            else
              this->cmd.forwardmove = 127;
          }
          else
          {
            this->cmd.forwardmove = 0x80;
          }
          break;
        case UB_LOOKUP:
          if ( this->currentSettings.absoluteAngles )
          {
            if ( this->currentSettings.lookInvert )
              v36 = -1.0;
            else
              v36 = 1.0;
            this->currentDevice->angles.pitch = (float)((float)v36 * (float)v14) * (float)90.0;
          }
          else
          {
            if ( joy_dampenLook.valueInteger != 0 )
            {
              HIDWORD(v25) = this->currentDevice->lastPollTime;
              v37 = 4 * (this->currentDeviceNum + 401);
              v38 = this->pollTime - HIDWORD(v25);
              _FP7 = (float)((float)_FP0
                           - (float)((float)((float)*(__int64 *)(&v26 - 1) * joy_deltaPerMSLook.valueFloat)
                                   + *(float *)((char *)&this->__vftable + v37)));
              __asm { fsel      f0, f7, f8, f0 }
              *(float *)((char *)&this->__vftable + v37) = _FP0;
            }
            if ( this->currentSettings.lookInvert )
              v40 = -1.0;
            else
              v40 = 1.0;
            currentDevice = this->currentDevice;
            LODWORD(v25) = this->pollTime - currentDevice->lastPollTime;
            currentDevice->angles.pitch = -(float)((float)((float)((float)((float)((float)v25
                                                                                 * this->currentSettings.joyPitchSpeed)
                                                                         * (float)0.001)
                                                                 * (float)v40)
                                                         * (float)_FP0)
                                                 - currentDevice->angles.pitch);
          }
          break;
        case UB_LOOKDOWN:
          if ( this->currentSettings.absoluteAngles )
          {
            if ( this->currentSettings.lookInvert )
              v42 = -1.0;
            else
              v42 = 1.0;
            this->currentDevice->angles.pitch = (float)((float)v42 * (float)v14) * (float)-90.0;
          }
          else
          {
            if ( joy_dampenLook.valueInteger != 0 )
            {
              HIDWORD(v25) = this->currentDevice->lastPollTime;
              v43 = 4 * (this->currentDeviceNum + 401);
              v44 = this->pollTime - HIDWORD(v25);
              _FP7 = (float)((float)_FP0
                           - (float)((float)((float)*(__int64 *)(&v26 - 1) * joy_deltaPerMSLook.valueFloat)
                                   + *(float *)((char *)&this->__vftable + v43)));
              __asm { fsel      f0, f7, f8, f0 }
              *(float *)((char *)&this->__vftable + v43) = _FP0;
            }
            if ( this->currentSettings.lookInvert )
              v46 = -1.0;
            else
              v46 = 1.0;
            v47 = this->currentDevice;
            LODWORD(v25) = this->pollTime - v47->lastPollTime;
            v47->angles.pitch = (float)((float)((float)((float)((float)v25 * this->currentSettings.joyPitchSpeed)
                                                      * (float)0.001)
                                              * (float)v46)
                                      * (float)_FP0)
                              + v47->angles.pitch;
          }
          break;
        case UB_LOOKLEFT:
          if ( this->currentSettings.absoluteAngles )
          {
            this->currentDevice->angles.yaw = (float)v14 * (float)-90.0;
          }
          else
          {
            if ( joy_dampenLook.valueInteger != 0 )
            {
              HIDWORD(v25) = this->currentDevice->lastPollTime;
              v48 = 4 * (this->currentDeviceNum + 397);
              v49 = this->pollTime - HIDWORD(v25);
              _FP7 = (float)((float)_FP0
                           - (float)((float)((float)*(__int64 *)(&v26 - 1) * joy_deltaPerMSLook.valueFloat)
                                   + *(float *)((char *)&this->__vftable + v48)));
              __asm { fsel      f0, f7, f8, f0 }
              *(float *)((char *)&this->__vftable + v48) = _FP0;
            }
            v51 = this->currentDevice;
            LODWORD(v25) = this->pollTime - v51->lastPollTime;
            v51->angles.yaw = (float)((float)((float)((float)v25 * this->currentSettings.joyYawSpeed) * (float)0.001)
                                    * (float)_FP0)
                            + v51->angles.yaw;
          }
          break;
        case UB_LOOKRIGHT:
          if ( this->currentSettings.absoluteAngles )
          {
            this->currentDevice->angles.yaw = (float)v14 * (float)90.0;
          }
          else
          {
            if ( joy_dampenLook.valueInteger != 0 )
            {
              HIDWORD(v25) = this->currentDevice->lastPollTime;
              v52 = 4 * (this->currentDeviceNum + 397);
              v53 = this->pollTime - HIDWORD(v25);
              _FP7 = (float)((float)_FP0
                           - (float)((float)((float)*(__int64 *)(&v26 - 1) * joy_deltaPerMSLook.valueFloat)
                                   + *(float *)((char *)&this->__vftable + v52)));
              __asm { fsel      f0, f7, f8, f0 }
              *(float *)((char *)&this->__vftable + v52) = _FP0;
            }
            v55 = this->currentDevice;
            LODWORD(v25) = this->pollTime - v55->lastPollTime;
            v55->angles.yaw = -(float)((float)((float)((float)((float)v25 * this->currentSettings.joyYawSpeed)
                                                     * (float)0.001)
                                             * (float)_FP0)
                                     - v55->angles.yaw);
          }
          break;
        default:
          return;
      }
    }
  }
}


// ========================================================================
// ?JoystickMove@idUsercmdGenLocal@@AAAXH@Z
// EA  : 0x826A8F28
// RVA : 0x006A8F28
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::JoystickMove(
        idUsercmdGenLocal *this,
        unsigned int inputDeviceNum,
        double a3,
        double a4,
        long double a5,
        int a6,
        bool a7)
{
  const idDeclTable *v7; // r7
  double valueFloat; // fp31
  double v11; // fp28
  idUsercmdGenLocal::usercmdDevice_t *currentDevice; // r11
  idUsercmdGenLocal::usercmdDevice_t *v13; // r10
  double v14; // fp30
  double v15; // fp29
  const idDeclTable *v16; // r7
  bool v17; // r6
  const idDeclTable *v18; // r7
  bool v19; // r6
  const idDeclTable *v20; // r7
  bool v21; // r6
  const idDeclTable *v22; // r7
  bool v23; // r6
  long double v24; // fp4
  double v25; // fp2
  double v26; // fp1
  idUsercmdGenLocal::usercmdDevice_t *v27; // r11
  double v28; // fp30
  double v29; // fp29
  const idDeclTable *v30; // r7
  bool v31; // r6
  const idDeclTable *v32; // r7
  bool v33; // r6
  const idDeclTable *v34; // r7
  bool v35; // r6
  const idDeclTable *v36; // r7
  bool v37; // r6
  const idDeclTable *v38; // r7
  bool v39; // r6
  float v40; // [sp+50h] [-50h] BYREF
  float v41[11]; // [sp+54h] [-4Ch] BYREF

  v7 = (const idDeclTable *)&joy_triggerThreshold;
  valueFloat = joy_deadZone.valueFloat;
  v11 = joy_triggerThreshold.valueFloat;
  if ( this->currentSettings.absoluteAngles && !this->joystickSnapDisabled )
  {
    currentDevice = this->currentDevice;
    currentDevice->angles.roll = 0.0;
    currentDevice->angles.yaw = 0.0;
    currentDevice->angles.pitch = 0.0;
  }
  v13 = this->currentDevice;
  v14 = v13->joystickAxis[1];
  v15 = v13->joystickAxis[0];
  v40 = v13->joystickAxis[1];
  v41[0] = v15;
  if ( joy_circleToSquare.valueInteger == 2 )
  {
    idUsercmdGenLocal::CircleToSquare(this, axis_x: v41, axis_y: &v40, a4: a3, a5: a4, a6: a5);
    v14 = v40;
    v15 = v41[0];
  }
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK1_UP,
    unclampedValue: v14,
    threshold: valueFloat,
    positive: a7,
    sens: v7,
    a8: 0,
    a9: (int)this->sensitivityJoy1);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK1_DOWN,
    unclampedValue: v14,
    threshold: valueFloat,
    positive: v17,
    sens: v16,
    a8: 1,
    a9: (int)this->sensitivityJoy1);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK1_LEFT,
    unclampedValue: v15,
    threshold: valueFloat,
    positive: v19,
    sens: v18,
    a8: 0,
    a9: (int)this->sensitivityJoy1);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK1_RIGHT,
    unclampedValue: v15,
    threshold: valueFloat,
    positive: v21,
    sens: v20,
    a8: 1,
    a9: (int)this->sensitivityJoy1);
  v27 = this->currentDevice;
  v28 = v27->joystickAxis[3];
  v29 = v27->joystickAxis[2];
  v40 = v27->joystickAxis[3];
  v41[0] = v29;
  if ( joy_circleToSquare.valueInteger == 2 )
  {
    idUsercmdGenLocal::CircleToSquare(this, axis_x: v41, axis_y: &v40, a4: v26, a5: v25, a6: v24);
    v28 = v40;
    v29 = v41[0];
  }
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK2_UP,
    unclampedValue: v28,
    threshold: valueFloat,
    positive: v23,
    sens: v22,
    a8: 0,
    a9: (int)this->sensitivityJoy2);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK2_DOWN,
    unclampedValue: v28,
    threshold: valueFloat,
    positive: v31,
    sens: v30,
    a8: 1,
    a9: (int)this->sensitivityJoy2);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK2_LEFT,
    unclampedValue: v29,
    threshold: valueFloat,
    positive: v33,
    sens: v32,
    a8: 0,
    a9: (int)this->sensitivityJoy2);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_STICK2_RIGHT,
    unclampedValue: v29,
    threshold: valueFloat,
    positive: v35,
    sens: v34,
    a8: 1,
    a9: (int)this->sensitivityJoy2);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_TRIGGER1,
    unclampedValue: this->currentDevice->joystickAxis[4],
    threshold: v11,
    positive: v37,
    sens: v36,
    a8: 1,
    a9: 0);
  idUsercmdGenLocal::HandleJoystickAxis(
    this,
    inputDeviceNum,
    keyNum: K_JOY_TRIGGER2,
    unclampedValue: this->currentDevice->joystickAxis[5],
    threshold: v11,
    positive: v39,
    sens: v38,
    a8: 1,
    a9: 0);
}


// ========================================================================
// ?AimAssist@idUsercmdGenLocal@@AAAXXZ
// EA  : 0x826A9160
// RVA : 0x006A9160
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::AimAssist(idUsercmdGenLocal *this)
{
  idGame *v2; // r3
  idGame *v3; // r31
  int v4; // r3
  char IsValid; // r3
  char v6; // r11
  idAngles *p_angles; // r11
  double roll; // fp8
  float v9; // [sp+50h] [-30h] BYREF
  float v10; // [sp+54h] [-2Ch]
  float v11; // [sp+58h] [-28h]

  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  v2 = common->Game(this: common);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = v2->GetPlayerIndexFromInputDevice(this: v2, a2: this->currentDeviceNum);
    v3->UpdateAimAssist(this: v3, a2: v4, a3: (idAngles *)&v9);
    if ( (unsigned __int8)idMath::IsValid(f: v10) == 0 || (IsValid = idMath::IsValid(f: v9), v6 = 1, IsValid == 0) )
      v6 = 0;
    if ( v6 == 0 )
    {
      idLib::Warning(fmt: "invalid aim assist angles - ignoring");
      v9 = 0.0;
      v11 = 0.0;
      v10 = 0.0;
    }
  }
  p_angles = &this->currentDevice->angles;
  p_angles->pitch = p_angles->pitch + v9;
  roll = p_angles->roll;
  p_angles->yaw = v10 + p_angles->yaw;
  p_angles->roll = v11 + (float)roll;
}


// ========================================================================
// ?WeaponKick@idUsercmdGenLocal@@AAAXXZ
// EA  : 0x826A9290
// RVA : 0x006A9290
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::WeaponKick(idUsercmdGenLocal *this)
{
  idGame *v2; // r3
  idGame *v3; // r31
  int v4; // r3
  char IsValid; // r3
  char v6; // r11
  idAngles *p_angles; // r11
  double roll; // fp8
  float v9; // [sp+50h] [-30h] BYREF
  float v10; // [sp+54h] [-2Ch]
  float v11; // [sp+58h] [-28h]

  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  v2 = common->Game(this: common);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = v2->GetPlayerIndexFromInputDevice(this: v2, a2: this->currentDeviceNum);
    v3->UpdateWeaponKick(this: v3, a2: v4, a3: (idAngles *)&v9);
    if ( (unsigned __int8)idMath::IsValid(f: v10) == 0 || (IsValid = idMath::IsValid(f: v9), v6 = 1, IsValid == 0) )
      v6 = 0;
    if ( v6 == 0 )
    {
      idLib::Warning(fmt: "invalid weapon kick angles - ignoring");
      v9 = 0.0;
      v11 = 0.0;
      v10 = 0.0;
    }
  }
  p_angles = &this->currentDevice->angles;
  p_angles->pitch = p_angles->pitch + v9;
  roll = p_angles->roll;
  p_angles->yaw = v10 + p_angles->yaw;
  p_angles->roll = v11 + (float)roll;
}


// ========================================================================
// ?SaveGame@idUsercmdGenLocal@@UAAXPAVidFile@@@Z
// EA  : 0x826A93C0
// RVA : 0x006A93C0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::SaveGame(idUsercmdGenLocal *this, idFile *fp)
{
  idAngles *p_angles; // r30
  int i; // r31

  p_angles = &this->devices[0].angles;
  for ( i = 4; i != 0; --i )
  {
    fp->Write(this: fp, a2: p_angles, a3: 12u);
    p_angles += 28;
  }
}


// ========================================================================
// ?ClearAngles@idUsercmdGenLocal@@UAAXXZ
// EA  : 0x826A9408
// RVA : 0x006A9408
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::ClearAngles(idUsercmdGenLocal *this)
{
  this->devices[0].angles.pitch = 0.0;
  this->devices[0].angles.roll = 0.0;
  this->devices[0].angles.yaw = 0.0;
  this->devices[1].angles.roll = 0.0;
  this->devices[1].angles.yaw = 0.0;
  this->devices[1].angles.pitch = 0.0;
  this->devices[2].angles.roll = 0.0;
  this->devices[2].angles.yaw = 0.0;
  this->devices[2].angles.pitch = 0.0;
  this->devices[3].angles.roll = 0.0;
  this->devices[3].angles.yaw = 0.0;
  this->devices[3].angles.pitch = 0.0;
}


// ========================================================================
// ?GetUsercmd@idUsercmdGenLocal@@UAA?AVusercmd_t@@HABUinputSettings_t@@_NH@Z
// EA  : 0x826A9448
// RVA : 0x006A9448
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

idUsercmdGenLocal *__fastcall idUsercmdGenLocal::GetUsercmd(
        idUsercmdGenLocal *this,
        idUsercmdGenLocal *result,
        unsigned int inputDeviceNum,
        const inputSettings_t *settings,
        bool inhibit,
        int cmdFileNum)
{
  unsigned int *p_currentSettings; // r29
  bool *p_absoluteAngles; // r10
  idUsercmdGenLocal::usercmdDevice_t **p_currentDevice; // r9
  int i; // ctr
  int lastPollTime; // r3
  idUsercmdGenLocal::usercmdDevice_t *currentDevice; // r9
  usercmd_t *p_cmd; // r27
  bool *buttonState; // r25
  keyNum_t j; // r30
  int v19; // r11
  int v20; // r10
  bool *v21; // r8
  bool *v22; // r7
  bool *v23; // r6
  int k; // ctr
  int v25; // r10
  int v26; // r10
  int v27; // r10
  int v28; // r11
  int m; // ctr
  idUsercmdGenLocal *v30; // r3
  bool v31; // r6
  int v32; // r5
  long double v33; // fp4
  double v34; // fp2
  double v35; // fp1
  idUsercmdGenLocal::usercmdDevice_t *v36; // r10
  double valueFloat; // fp31
  const idDeclTable *v38; // r7

  if ( inputDeviceNum == 0 )
    result->lastInputFrame = idLib::frameNumber;
  result->currentDeviceNum = inputDeviceNum;
  p_currentSettings = (unsigned int *)&result->currentSettings;
  result->currentDevice = &result->devices[inputDeviceNum];
  p_absoluteAngles = &settings[-1].absoluteAngles;
  p_currentDevice = &result->currentDevice;
  for ( i = 7; i != 0; --i )
  {
    p_absoluteAngles += 4;
    *++p_currentDevice = *(idUsercmdGenLocal::usercmdDevice_t **)p_absoluteAngles;
  }
  lastPollTime = Sys_Milliseconds();
  currentDevice = result->currentDevice;
  result->pollTime = lastPollTime;
  if ( currentDevice->lastPollTime >= lastPollTime - 80 )
  {
    if ( currentDevice->lastPollTime <= lastPollTime )
      lastPollTime = currentDevice->lastPollTime;
  }
  else
  {
    lastPollTime -= 80;
  }
  p_cmd = &result->cmd;
  currentDevice->lastPollTime = lastPollTime;
  memset(Dst: &result->cmd, Val: 0, Size: sizeof(result->cmd));
  buttonState = result->buttonState;
  memset(Dst: result->buttonState, Val: 0, Size: sizeof(result->buttonState));
  idUsercmdGenLocal::Mouse(this: result, inputDeviceNum);
  idUsercmdGenLocal::Keyboard(this: result, inputDeviceNum);
  idUsercmdGenLocal::Joystick(this: result, inputDeviceNum);
  for ( j = K_NONE; j < K_LAST_KEY; ++j )
  {
    if ( result->currentDevice->keyState[j] )
      result->buttonState[idKeyInput::GetUsercmdAction(
                            numDevice: inputDeviceNum,
                            bindset: *p_currentSettings,
                            keynum: j)] = true;
  }
  v19 = 0;
  v20 = 1;
  v21 = &result->buttonState[1];
  v22 = &result->buttonState[2];
  v23 = &result->buttonState[3];
  for ( k = 8; k != 0; --k )
  {
    if ( buttonState[v19] )
      p_cmd->buttons |= v20;
    v25 = __ROL4__(v20, 1);
    if ( v21[v19] )
      p_cmd->buttons |= v25;
    v26 = __ROL4__(v25, 1);
    if ( v22[v19] )
      p_cmd->buttons |= v26;
    v27 = __ROL4__(v26, 1);
    if ( v23[v19] )
      p_cmd->buttons |= v27;
    v20 = __ROL4__(v27, 1);
    v19 += 4;
  }
  v28 = 32;
  for ( m = 4; m != 0; --m )
  {
    if ( buttonState[v28] )
      result->cmd.buttons2 |= 1 << (v28 - 32);
    if ( v21[v28] )
      result->cmd.buttons2 |= 1 << (v28 - 31);
    if ( v22[v28] )
      result->cmd.buttons2 |= 1 << (v28 - 30);
    if ( v23[v28] )
      result->cmd.buttons2 |= 1 << (v28 - 29);
    v28 += 4;
  }
  *((_BYTE *)&result->cmd + 9) = (inhibit << 7) | *((_BYTE *)&result->cmd + 9) & 0x7F;
  if ( inhibit )
  {
    v36 = result->currentDevice;
    result->mouseDx = 0.0;
    result->mouseDy = 0.0;
    valueFloat = joy_triggerThreshold.valueFloat;
    idUsercmdGenLocal::HandleJoystickAxis(
      this: result,
      inputDeviceNum,
      keyNum: K_JOY_TRIGGER1,
      unclampedValue: v36->joystickAxis[4],
      threshold: joy_triggerThreshold.valueFloat,
      positive: (bool)v23,
      sens: (const idDeclTable *)&joy_triggerThreshold,
      a8: 1,
      a9: 0);
    idUsercmdGenLocal::HandleJoystickAxis(
      this: result,
      inputDeviceNum,
      keyNum: K_JOY_TRIGGER2,
      unclampedValue: result->currentDevice->joystickAxis[5],
      threshold: valueFloat,
      positive: (bool)result->currentDevice,
      sens: v38,
      a8: 1,
      a9: 0);
  }
  else
  {
    idUsercmdGenLocal::KeyMove(this: result);
    idUsercmdGenLocal::MouseMove(this: v30);
    idUsercmdGenLocal::JoystickMove(this: result, inputDeviceNum, a3: v35, a4: v34, a5: v33, a6: v32, a7: v31);
    if ( result->aimAssist )
      idUsercmdGenLocal::AimAssist(this: result);
    idUsercmdGenLocal::WeaponKick(this: result);
  }
  result->cmd.angles[0] = (int)(float)(result->currentDevice->angles.pitch * (float)182.04445);
  result->cmd.angles[1] = (int)(float)(result->currentDevice->angles.yaw * (float)182.04445);
  result->cmd.angles[2] = (int)(float)(result->currentDevice->angles.roll * (float)182.04445);
  result->currentDevice->lastPollTime = result->pollTime;
  memcpy(Dst: this, Src: &result->cmd, Size: 0x3Cu);
  return this;
}


// ========================================================================
// ?CmdMacroRecord_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A97D0
// RVA : 0x006A97D0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall CmdMacroRecord_f(const idCmdArgs *args)
{
  __int64 v1; // r8
  __int64 v2; // r10
  __int64 v3; // r6
  va *v4; // r4
  int v5; // [sp+8h] [-1058h]
  int v6; // [sp+Ch] [-1054h]
  int v7; // [sp+10h] [-1050h]
  int v8; // [sp+14h] [-104Ch]
  int v9; // [sp+18h] [-1048h]
  int v10; // [sp+1Ch] [-1044h]
  va v11; // [sp+50h] [-1010h] BYREF

  HIDWORD(v2) = args->argc;
  LODWORD(v1) = &mp_bot_input_override;
  HIDWORD(v1) = 0x80000000;
  LODWORD(v2) = mp_bot_input_override.valueInteger;
  LODWORD(v3) = mp_bot_input_override.valueInteger;
  if ( args->argc < 2 )
  {
    HIDWORD(v3) = __CFADD__(mp_bot_input_override.valueInteger, 0x80000000) ? 0 : mp_bot_input_override.valueInteger;
    v4 = va::va(
           this: &v11,
           fmt: "temp.macro.%d.cmd",
           a3: v3,
           a4: v1,
           a5: v2,
           a6: v5,
           a7: v6,
           a8: v7,
           a9: v8,
           a10: v9,
           a11: v10);
  }
  else if ( SHIDWORD(v2) <= 1 )
  {
    v4 = (va *)&byte_8200D768;
  }
  else
  {
    v4 = (va *)args->argv[1];
  }
  idLib::Printf(fmt: "Recoding cmd macro to %s\n", v4->buffer);
}


// ========================================================================
// ?CmdMacroStop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A9860
// RVA : 0x006A9860
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall CmdMacroStop_f(const idCmdArgs *args)
{
  localUsercmdGen.loopPlayCmds[__CFADD__(mp_bot_input_override.valueInteger, 0x80000000)
                             ? 0
                             : mp_bot_input_override.valueInteger] = 0;
  localUsercmdGen.allowButtonInputDuringPlay = false;
  idLib::Printf(fmt: "Stopped Cmd Macro\n");
}


// ========================================================================
// ?CmdMacroPlay_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A98B0
// RVA : 0x006A98B0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall CmdMacroPlay_f(const idCmdArgs *args)
{
  __int64 v2; // r8
  __int64 v3; // r10
  __int64 v4; // r6
  int v5; // r28
  int v6; // r29
  va *v7; // r4
  int v8; // [sp+8h] [-1078h]
  int v9; // [sp+Ch] [-1074h]
  int v10; // [sp+10h] [-1070h]
  int v11; // [sp+14h] [-106Ch]
  int v12; // [sp+18h] [-1068h]
  int v13; // [sp+1Ch] [-1064h]
  va v14; // [sp+50h] [-1030h] BYREF

  HIDWORD(v3) = args->argc;
  LODWORD(v2) = &mp_bot_input_override;
  HIDWORD(v2) = 0x80000000;
  LODWORD(v3) = mp_bot_input_override.valueInteger;
  LODWORD(v4) = mp_bot_input_override.valueInteger;
  v5 = __CFADD__(mp_bot_input_override.valueInteger, 0x80000000) ? 0 : mp_bot_input_override.valueInteger;
  if ( args->argc < 2 )
  {
    v6 = -1;
  }
  else if ( args->argc <= 2 )
  {
    v6 = atol(nptr: &byte_8200D768);
  }
  else
  {
    v6 = atol(nptr: args->argv[2]);
  }
  if ( args->argc < 3 )
  {
    HIDWORD(v4) = v5;
    v7 = va::va(
           this: &v14,
           fmt: "temp.macro.%d.cmd",
           a3: v4,
           a4: v2,
           a5: v3,
           a6: v8,
           a7: v9,
           a8: v10,
           a9: v11,
           a10: v12,
           a11: v13);
  }
  else if ( args->argc <= 1 )
  {
    v7 = (va *)&byte_8200D768;
  }
  else
  {
    v7 = (va *)args->argv[1];
  }
  localUsercmdGen.loopPlayCmds[v5] = v6;
  localUsercmdGen.allowButtonInputDuringPlay = true;
  idLib::Printf(fmt: "Playing cmd macro %s\n", v7->buffer);
}


// ========================================================================
// ??0idUsercmdGenLocal@@QAA@XZ
// EA  : 0x826A9990
// RVA : 0x006A9990
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

idUsercmdGenLocal *__fastcall idUsercmdGenLocal::idUsercmdGenLocal(idUsercmdGenLocal *this)
{
  double valueFloat; // fp12
  bool v3; // r11
  double v4; // fp13
  double v5; // fp11
  int *p_lastInputFrame; // r10
  int i; // ctr

  this->__vftable = (idUsercmdGenLocal_vtbl *)&idUsercmdGenLocal::`vftable';
  valueFloat = joy_yawSpeed.valueFloat;
  v3 = in_invertLook.valueInteger != 0;
  v4 = m_sensitivity.valueFloat;
  v5 = joy_pitchSpeed.valueFloat;
  this->currentSettings.bindset = BIND_DEFAULT;
  this->currentSettings.lookInvert = v3;
  this->currentSettings.joyPitchSpeed = v5;
  this->currentSettings.joyYawSpeed = valueFloat;
  this->currentSettings.absoluteAngles = false;
  this->currentSettings.mouseSens = v4;
  this->currentSettings.mouseSensScale = 1.0;
  this->currentSettings.joySensScale = 1.0;
  this->cmd.buttons = 0;
  this->cmd.buttons2 = 0;
  this->cmd.forwardmove = 0;
  this->cmd.pos[2] = 0.0;
  this->cmd.rightmove = 0;
  this->cmd.pos[1] = 0.0;
  this->cmd.upmove = 0;
  this->cmd.pos[0] = 0.0;
  this->cmd.angles[2] = 0;
  this->cmd.angles[1] = 0;
  this->cmd.angles[0] = 0;
  this->cmd.clientGameFrame = 0;
  this->cmd.yaw = 0;
  this->cmd.pitch = 0;
  this->cmd.roll = 0;
  this->cmd.predictionStateBits = 0;
  this->cmd.vehicleThrottle = 0;
  this->cmd.serverGameTime = 0;
  this->cmd.fireCount = 0;
  this->cmd.fireAngles[1] = 0;
  this->cmd.fireAngles[0] = 0;
  this->cmd.firePos[2] = 0;
  this->cmd.firePos[1] = 0;
  *((_BYTE *)&this->cmd + 9) &= 0x3Fu;
  this->cmd.firePos[0] = 0;
  this->cmd.speed = 0;
  this->aimAssist = false;
  this->joystickSnapDisabled = false;
  this->lastCommandTime = 0;
  this->initialized = false;
  this->currentDeviceNum = 0;
  this->currentDevice = this->devices;
  this->devices[0].lastPollTime = 0;
  this->devices[1].lastPollTime = 0;
  this->devices[2].lastPollTime = 0;
  this->devices[3].lastPollTime = 0;
  this->pollTime = 0;
  this->devices[0].angles.pitch = 0.0;
  this->devices[0].angles.roll = 0.0;
  this->devices[0].angles.yaw = 0.0;
  this->devices[1].angles.roll = 0.0;
  this->devices[1].angles.yaw = 0.0;
  this->devices[1].angles.pitch = 0.0;
  this->devices[2].angles.roll = 0.0;
  this->devices[2].angles.yaw = 0.0;
  this->devices[2].angles.pitch = 0.0;
  this->devices[3].angles.roll = 0.0;
  this->devices[3].angles.yaw = 0.0;
  this->devices[3].angles.pitch = 0.0;
  idUsercmdGenLocal::Clear(this);
  p_lastInputFrame = &this->lastInputFrame;
  for ( i = 6; i != 0; --i )
    *++p_lastInputFrame = 0;
  *(_DWORD *)this->recording = 0;
  *(_WORD *)&this->recording[4] = 0;
  this->lastUsedLookValue[0] = 0.0;
  this->lastUsedLookValue[1] = 0.0;
  this->lastUsedLookValue[2] = 0.0;
  this->lastUsedLookValue[3] = 0.0;
  this->lastUsedLookValuePitch[0] = 0.0;
  this->lastUsedLookValuePitch[1] = 0.0;
  this->lastUsedLookValuePitch[2] = 0.0;
  this->lastUsedLookValuePitch[3] = 0.0;
  this->sensitivityJoy1 = nullptr;
  this->sensitivityJoy2 = nullptr;
  return this;
}


// ========================================================================
// ?GetUseAimAssist@idUsercmdGenLocal@@UBA_NXZ
// EA  : 0x826A9B60
// RVA : 0x006A9B60
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

BOOL __fastcall idUsercmdGenLocal::GetUseAimAssist(idUsercmdGenLocal *this)
{
  return this->aimAssist;
}


// ========================================================================
// ?Init@idUsercmdGenLocal@@UAAXXZ
// EA  : 0x826A9BC0
// RVA : 0x006A9BC0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::Init(idUsercmdGenLocal *this)
{
  this->initialized = true;
  this->sensitivityJoy1 = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclTable::resourceList,
                                                 name: "input/360_joy1",
                                                 makeDefault: false);
  this->sensitivityJoy2 = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclTable::resourceList,
                                                 name: "input/360_joy2",
                                                 makeDefault: false);
}


// ========================================================================
// ?GetRecordedUserCmd@idUsercmdGenLocal@@UAAXHAAVusercmd_t@@@Z
// EA  : 0x826A9C30
// RVA : 0x006A9C30
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __fastcall idUsercmdGenLocal::GetRecordedUserCmd(idUsercmdGenLocal *this, int cmdFileNum, usercmd_t *recordedCmd)
{
  BOOL allowButtonInputDuringPlay; // r30
  int v6; // r11
  int v7; // r9
  char rightmove; // r10
  char v9; // r9
  int v10; // r11
  char upmove; // r10
  char v12; // r9
  int v13; // r11
  usercmd_t v14; // [sp+50h] [-60h] BYREF

  if ( this->cmdFiles[cmdFileNum] != nullptr && !this->recording[cmdFileNum] )
  {
    usercmd_t::usercmd_t(this: &v14);
    allowButtonInputDuringPlay = this->allowButtonInputDuringPlay;
    if ( this->allowButtonInputDuringPlay )
    {
      v14 = *recordedCmd;
      if ( allowButtonInputDuringPlay )
      {
        v6 = v14.forwardmove + recordedCmd->forwardmove;
        v7 = recordedCmd->buttons | v14.buttons;
        recordedCmd->buttons2 |= v14.buttons2;
        recordedCmd->buttons = v7;
        if ( v6 >= -128 )
        {
          if ( v6 > 127 )
            LOBYTE(v6) = 127;
        }
        else
        {
          LOBYTE(v6) = 0x80;
        }
        rightmove = v14.rightmove;
        v9 = recordedCmd->rightmove;
        recordedCmd->forwardmove = v6;
        v10 = v9 + rightmove;
        if ( v10 >= -128 )
        {
          if ( v10 > 127 )
            LOBYTE(v10) = 127;
        }
        else
        {
          LOBYTE(v10) = 0x80;
        }
        upmove = v14.upmove;
        v12 = recordedCmd->upmove;
        recordedCmd->rightmove = v10;
        v13 = v12 + upmove;
        if ( v13 >= -128 )
        {
          if ( v13 > 127 )
            LOBYTE(v13) = 127;
        }
        else
        {
          LOBYTE(v13) = 0x80;
        }
        recordedCmd->upmove = v13;
      }
    }
  }
  this->currentDevice->lastPollTime = this->pollTime;
}


// ========================================================================
// ?LoadGame@idUsercmdGenLocal@@UAA_NPAVidFile@@@Z
// EA  : 0x826A9E90
// RVA : 0x006A9E90
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

int __fastcall idUsercmdGenLocal::LoadGame(idUsercmdGenLocal *this, idFile *fp)
{
  int v3; // r30
  idAngles *p_angles; // r31

  v3 = 0;
  p_angles = &this->devices[0].angles;
  this->Clear(this);
  while ( fp->Read(this: fp, a2: p_angles, a3: 12u) != 0 )
  {
    ++v3;
    p_angles += 28;
    if ( v3 >= 4 )
      return 1;
  }
  return 0;
}


// ========================================================================
// `dynamic initializer for 'ucmd_useSensitivityTable''
// EA  : 0x8333CE08
// RVA : 0x0133CE08
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ucmd_useSensitivityTable__()
{
  idCVar::idCVar(
    this: &ucmd_useSensitivityTable,
    name: "ucmd_useSensitivityTable",
    value: "0",
    flags: 1,
    description: " if true will use the sensitivity table set up in the editor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ucmd_useSensitivityTable__);
}


// ========================================================================
// `dynamic initializer for 'in_joystick''
// EA  : 0x8333CE60
// RVA : 0x0133CE60
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_joystick__()
{
  idCVar::idCVar(
    this: &in_joystick,
    name: "in_joystick",
    value: "4",
    flags: 65538,
    description: "enables joystick input",
    valueMin: 4.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"_AI_OBSTACLE",
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_joystick__);
}


// ========================================================================
// `dynamic initializer for 'joy_triggerThreshold''
// EA  : 0x8333CEC8
// RVA : 0x0133CEC8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_triggerThreshold__()
{
  idCVar::idCVar(
    this: &joy_triggerThreshold,
    name: "joy_triggerThreshold",
    value: "0.05",
    flags: 4,
    description: "how far the joystick triggers have to be pressed before they register as down",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_triggerThreshold__);
}


// ========================================================================
// `dynamic initializer for 'joy_deadZone''
// EA  : 0x8333CF20
// RVA : 0x0133CF20
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_deadZone__()
{
  idCVar::idCVar(
    this: &joy_deadZone,
    name: "joy_deadZone",
    value: "0.2",
    flags: 4,
    description: "specifies how large the dead-zone is on the joystick",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_deadZone__);
}


// ========================================================================
// `dynamic initializer for 'joy_powerScale''
// EA  : 0x8333CF78
// RVA : 0x0133CF78
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_powerScale__()
{
  idCVar::idCVar(
    this: &joy_powerScale,
    name: "joy_powerScale",
    value: "2",
    flags: 4,
    description: "Raise joystick values to this power",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_powerScale__);
}


// ========================================================================
// `dynamic initializer for 'joy_yawSpeed''
// EA  : 0x8333CFD0
// RVA : 0x0133CFD0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_yawSpeed__()
{
  idCVar::idCVar(
    this: &joy_yawSpeed,
    name: "joy_yawSpeed",
    value: "240",
    flags: 65540,
    description: "yaw speed when pressing left or right on the joystick",
    valueMin: 100.0,
    valueMax: 600.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"INT",
    a9: (int)"_AI_OBSTACLE",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_yawSpeed__);
}


// ========================================================================
// `dynamic initializer for 'joy_pitchSpeed''
// EA  : 0x8333D038
// RVA : 0x0133D038
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_pitchSpeed__()
{
  idCVar::idCVar(
    this: &joy_pitchSpeed,
    name: "joy_pitchSpeed",
    value: "120",
    flags: 65540,
    description: "pitch speed when pressing left or right on the joystick",
    valueMin: 100.0,
    valueMax: 600.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"_AI_OBSTACLE",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_pitchSpeed__);
}


// ========================================================================
// `dynamic initializer for 'joy_gammaLook''
// EA  : 0x8333D0A0
// RVA : 0x0133D0A0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_gammaLook__()
{
  idCVar::idCVar(
    this: &joy_gammaLook,
    name: "joy_gammaLook",
    value: "1",
    flags: 1,
    description: "use a log curve instead of a power curve for movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_gammaLook__);
}


// ========================================================================
// `dynamic initializer for 'joy_dampenLook''
// EA  : 0x8333D0F8
// RVA : 0x0133D0F8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_dampenLook__()
{
  idCVar::idCVar(
    this: &joy_dampenLook,
    name: "joy_dampenLook",
    value: "1",
    flags: 1,
    description: "Do not allow full acceleration on look",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_dampenLook__);
}


// ========================================================================
// `dynamic initializer for 'joy_deltaPerMSLook''
// EA  : 0x8333D150
// RVA : 0x0133D150
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_deltaPerMSLook__()
{
  idCVar::idCVar(
    this: &joy_deltaPerMSLook,
    name: "joy_deltaPerMSLook",
    value: "0.003",
    flags: 4,
    description: "Max amount to be added on look per MS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_deltaPerMSLook__);
}


// ========================================================================
// `dynamic initializer for 'joy_circleToSquare''
// EA  : 0x8333D1A8
// RVA : 0x0133D1A8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_circleToSquare__()
{
  idCVar::idCVar(
    this: &joy_circleToSquare,
    name: "joy_circleToSquare",
    value: "2",
    flags: 2,
    description: "Convert view input from circle to square to prevent diag slowdown.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_circleToSquare__);
}


// ========================================================================
// `dynamic initializer for 'joy_circleToSquarePower''
// EA  : 0x8333D200
// RVA : 0x0133D200
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__joy_circleToSquarePower__()
{
  idCVar::idCVar(
    this: &joy_circleToSquarePower,
    name: "joy_circleToSquarePower",
    value: "2",
    flags: 4,
    description: "Power exponent for the circle to square lerp",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__joy_circleToSquarePower__);
}


// ========================================================================
// `dynamic initializer for 'in_yawSpeed''
// EA  : 0x8333D258
// RVA : 0x0133D258
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_yawSpeed__()
{
  idCVar::idCVar(
    this: &in_yawSpeed,
    name: "in_yawspeed",
    value: "140",
    flags: 4,
    description: "yaw change speed when holding down _left or _right button",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_yawSpeed__);
}


// ========================================================================
// `dynamic initializer for 'in_pitchSpeed''
// EA  : 0x8333D2B0
// RVA : 0x0133D2B0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_pitchSpeed__()
{
  idCVar::idCVar(
    this: &in_pitchSpeed,
    name: "in_pitchspeed",
    value: "140",
    flags: 4,
    description: "pitch change speed when holding down look _lookUp or _lookDown button",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_pitchSpeed__);
}


// ========================================================================
// `dynamic initializer for 'in_angleSpeedKey''
// EA  : 0x8333D308
// RVA : 0x0133D308
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_angleSpeedKey__()
{
  idCVar::idCVar(
    this: &in_angleSpeedKey,
    name: "in_anglespeedkey",
    value: "1.5",
    flags: 4,
    description: "angle change scale when holding down _speed button",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_angleSpeedKey__);
}


// ========================================================================
// `dynamic initializer for 'in_invertLook''
// EA  : 0x8333D360
// RVA : 0x0133D360
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_invertLook__()
{
  idCVar::idCVar(
    this: &in_invertLook,
    name: "in_invertLook",
    value: "0",
    flags: 1,
    description: "inverts the look controls so the forward looks up (flight controls)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_invertLook__);
}


// ========================================================================
// `dynamic initializer for 'in_controlInactiveWindow''
// EA  : 0x8333D3B8
// RVA : 0x0133D3B8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_controlInactiveWindow__()
{
  idCVar::idCVar(
    this: &in_controlInactiveWindow,
    name: "in_controlInactiveWindow",
    value: "0",
    flags: 1,
    description: "allow joystick input to control game instances that don't have win focus",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_controlInactiveWindow__);
}


// ========================================================================
// `dynamic initializer for 'm_sensitivity''
// EA  : 0x8333D410
// RVA : 0x0133D410
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_sensitivity__()
{
  idCVar::idCVar(
    this: &m_sensitivity,
    name: "m_sensitivity",
    value: "5",
    flags: 4,
    description: "mouse view sensitivity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_sensitivity__);
}


// ========================================================================
// `dynamic initializer for 'm_menu_sensitivity''
// EA  : 0x8333D468
// RVA : 0x0133D468
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_menu_sensitivity__()
{
  idCVar::idCVar(
    this: &m_menu_sensitivity,
    name: "m_menu_sensitivity",
    value: "0.35",
    flags: 4,
    description: "mouse menu sensitivity used because using the same unscaled mouse view sensitivity is way to high",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_menu_sensitivity__);
}


// ========================================================================
// `dynamic initializer for 'm_pitch''
// EA  : 0x8333D4C0
// RVA : 0x0133D4C0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_pitch__()
{
  idCVar::idCVar(
    this: &m_pitch,
    name: "m_pitch",
    value: "0.022",
    flags: 4,
    description: "mouse pitch scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_pitch__);
}


// ========================================================================
// `dynamic initializer for 'm_yaw''
// EA  : 0x8333D518
// RVA : 0x0133D518
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_yaw__()
{
  idCVar::idCVar(
    this: &m_yaw,
    name: "m_yaw",
    value: "0.022",
    flags: 4,
    description: "mouse yaw scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_yaw__);
}


// ========================================================================
// `dynamic initializer for 'm_smooth''
// EA  : 0x8333D570
// RVA : 0x0133D570
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_smooth__()
{
  idCVar::idCVar(
    this: &m_smooth,
    name: "m_smooth",
    value: "1",
    flags: 65538,
    description: "number of samples blended for mouse viewing",
    valueMin: 1.0,
    valueMax: 8.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"_AI_OBSTACLE",
    a9: (int)&loc_826B0000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<1,8>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_smooth__);
}


// ========================================================================
// `dynamic initializer for 'm_showMouseRate''
// EA  : 0x8333D5E0
// RVA : 0x0133D5E0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_showMouseRate__()
{
  idCVar::idCVar(
    this: &m_showMouseRate,
    name: "m_showMouseRate",
    value: "0",
    flags: 1,
    description: "shows mouse movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_showMouseRate__);
}


// ========================================================================
// `dynamic initializer for 'm_vehicleMouseControl''
// EA  : 0x8333D638
// RVA : 0x0133D638
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__m_vehicleMouseControl__()
{
  idCVar::idCVar(
    this: &m_vehicleMouseControl,
    name: "m_vehicleMouseControl",
    value: "0",
    flags: 1,
    description: "use the mouse to control the camera when in a vehicle in multiplayer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__m_vehicleMouseControl__);
}


// ========================================================================
// `dynamic initializer for 'localUsercmdGen''
// EA  : 0x8333D690
// RVA : 0x0133D690
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__localUsercmdGen__()
{
  idUsercmdGenLocal::idUsercmdGenLocal(this: &localUsercmdGen);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__localUsercmdGen__);
}


// ========================================================================
// `dynamic initializer for 'CmdMacroRecord_v''
// EA  : 0x8333D6C8
// RVA : 0x0133D6C8
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__CmdMacroRecord_v__()
{
  return idCommandLink::idCommandLink(
           this: &CmdMacroRecord_v,
           cmdName: "CmdMacroRecord",
           function: CmdMacroRecord_f,
           description: "Records a cmd macro. Optionally specify filename",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'CmdMacroStop_v''
// EA  : 0x8333D6F0
// RVA : 0x0133D6F0
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__CmdMacroStop_v__()
{
  return idCommandLink::idCommandLink(
           this: &CmdMacroStop_v,
           cmdName: "CmdMacroStop",
           function: CmdMacroStop_f,
           description: "Stops recording and playback of cmd macro",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'CmdMacroPlay_v''
// EA  : 0x8333D718
// RVA : 0x0133D718
// PDB : w:\tech5\engine\framework\usercmdgen.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__CmdMacroPlay_v__()
{
  return idCommandLink::idCommandLink(
           this: &CmdMacroPlay_v,
           cmdName: "CmdMacroPlay",
           function: CmdMacroPlay_f,
           description: "<optional filename> <optional loop count>. Plays CmdMacro",
           argCompletion: nullptr);
}

