
// ========================================================================
// ?StringToKeyNum@idKeyInput@@SA?AW4keyNum_t@@PBD@Z
// EA  : 0x826788F0
// RVA : 0x006788F0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

keyNum_t __fastcall idKeyInput::StringToKeyNum(const char *str)
{
  keyname_t *v2; // r31

  if ( str == nullptr )
    return K_NONE;
  if ( *str == 0 )
    return K_NONE;
  v2 = keynames;
  if ( keynames[0].name == nullptr )
    return K_NONE;
  while ( idStr::Icmp(s1: str, s2: v2->name) != 0 )
  {
    ++v2;
    if ( v2->name == nullptr )
      return K_NONE;
  }
  return v2->keynum;
}


// ========================================================================
// ?KeyNumToString@idKeyInput@@SAPBDW4keyNum_t@@@Z
// EA  : 0x82678980
// RVA : 0x00678980
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

const char *__fastcall idKeyInput::KeyNumToString(keyNum_t keynum)
{
  keyname_t *v1; // r11

  v1 = keynames;
  if ( keynames[0].name == nullptr )
    return "?";
  while ( keynum != v1->keynum )
  {
    ++v1;
    if ( v1->name == nullptr )
      return "?";
  }
  return v1->name;
}


// ========================================================================
// ?LocalizedKeyName@idKeyInput@@SAPBDW4keyNum_t@@@Z
// EA  : 0x826789C8
// RVA : 0x006789C8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

const char *__fastcall idKeyInput::LocalizedKeyName(keyNum_t keynum)
{
  keyname_t *v1; // r11

  v1 = keynames;
  if ( keynames[0].name == nullptr )
    return "????";
  while ( keynum != v1->keynum )
  {
    ++v1;
    if ( v1->name == nullptr )
      return "????";
  }
  return idLocalization::GetString(inString: v1->strId);
}


// ========================================================================
// ?IsValidRebindKey@idKeyInput@@SA_NW4keyNum_t@@@Z
// EA  : 0x82678A10
// RVA : 0x00678A10
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

int __fastcall idKeyInput::IsValidRebindKey(int keyNum)
{
  int result; // r3
  bool v2; // zf

  if ( keyNum < 272 )
    return 1;
  v2 = keyNum > 279;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?GetUsercmdAction@idKeyInput@@SAHHW4bindSet_t@@W4keyNum_t@@@Z
// EA  : 0x82678A30
// RVA : 0x00678A30
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

cmdGenButton_t __fastcall idKeyInput::GetUsercmdAction(unsigned int numDevice, unsigned int bindset, keyNum_t keynum)
{
  if ( bindset > 6 || numDevice >= 4 )
    return UB_NONE;
  else
    return keyActions[numDevice][bindset][keynum].usercmdAction;
}


// ========================================================================
// ?SetUserDeviceNumForBind@idKeyInput@@SAXH@Z
// EA  : 0x82678A88
// RVA : 0x00678A88
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall idKeyInput::SetUserDeviceNumForBind(int inputDeviceNum)
{
  userDeviceNum = inputDeviceNum;
}


// ========================================================================
// ?PreliminaryKeyEvent@idKeyInput@@SAXHW4keyNum_t@@_N@Z
// EA  : 0x82678A98
// RVA : 0x00678A98
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall idKeyInput::PreliminaryKeyEvent(int deviceNum, keyNum_t keyNum, bool down)
{
  keyDown[keyNum] = down;
}


// ========================================================================
// ?IsDown@idKeyInput@@SA_NHW4keyNum_t@@@Z
// EA  : 0x82678AA8
// RVA : 0x00678AA8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

BOOL __fastcall idKeyInput::IsDown(int deviceNum, keyNum_t keyNum)
{
  return keyDown[keyNum];
}


// ========================================================================
// ?ClearStates@idKeyInput@@SAXXZ
// EA  : 0x82678AB8
// RVA : 0x00678AB8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

static void __fastcall idKeyInput::ClearStates()
{
  char *v0; // r11
  int i; // ctr

  v0 = (char *)&g_enableGameTimeScaling.next + 3;
  for ( i = 296; i != 0; --i )
    *++v0 = 0;
  usercmdGen->Clear(this: usercmdGen);
}


// ========================================================================
// ?Key_CovertHIDCode@@YAHH@Z
// EA  : 0x82678AF0
// RVA : 0x00678AF0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

int __fastcall Key_CovertHIDCode(int hid)
{
  _DWORD v2[8]; // [sp+0h] [-1D0h] BYREF
  _DWORD v3[108]; // [sp+20h] [-1B0h] BYREF

  if ( (unsigned int)hid > 0x6A )
  {
    if ( hid < 224 || hid > 231 )
    {
      return 0;
    }
    else
    {
      v2[5] = 54;
      v2[2] = 56;
      v2[3] = 219;
      v2[4] = 157;
      v2[6] = 184;
      v2[7] = 220;
      return v2[hid - 224];
    }
  }
  else
  {
    v3[4] = 30;
    v3[5] = 48;
    v3[6] = 46;
    v3[7] = 32;
    v3[8] = 18;
    v3[9] = 33;
    v3[10] = 34;
    v3[11] = 35;
    v3[12] = 23;
    v3[13] = 36;
    v3[14] = 37;
    v3[15] = 38;
    v3[16] = 50;
    v3[17] = 49;
    v3[18] = 24;
    v3[19] = 25;
    v3[20] = 16;
    v3[21] = 19;
    v3[22] = 31;
    v3[23] = 20;
    v3[24] = 22;
    v3[25] = 47;
    v3[26] = 17;
    v3[27] = 45;
    v3[28] = 21;
    v3[29] = 44;
    v3[30] = 2;
    v3[31] = 3;
    v3[32] = 4;
    v3[33] = 5;
    v3[34] = 6;
    v3[35] = 7;
    v3[36] = 8;
    memset(v3, 0, 16);
    v3[37] = 9;
    v3[38] = 10;
    v3[39] = 11;
    v3[40] = 28;
    v3[41] = 1;
    v3[42] = 14;
    v3[43] = 15;
    v3[44] = 57;
    v3[45] = 12;
    v3[46] = 13;
    v3[47] = 26;
    v3[48] = 27;
    v3[49] = 43;
    v3[51] = 39;
    v3[52] = 40;
    v3[53] = 41;
    v3[54] = 51;
    v3[55] = 52;
    v3[56] = 53;
    v3[57] = 58;
    v3[58] = 59;
    v3[59] = 60;
    v3[60] = 61;
    v3[61] = 62;
    v3[62] = 63;
    v3[63] = 64;
    v3[64] = 65;
    v3[65] = 66;
    v3[66] = 67;
    v3[67] = 68;
    v3[68] = 87;
    v3[69] = 88;
    v3[70] = 183;
    v3[71] = 70;
    v3[72] = 69;
    v3[73] = 210;
    v3[74] = 199;
    v3[75] = 201;
    v3[76] = 211;
    v3[77] = 207;
    v3[50] = 0;
    v3[78] = 209;
    v3[79] = 205;
    v3[80] = 203;
    v3[82] = 200;
    v3[83] = 197;
    v3[84] = 181;
    v3[85] = 55;
    v3[86] = 74;
    v3[87] = 78;
    v3[100] = 0;
    v3[88] = 156;
    v3[89] = 79;
    v3[90] = 80;
    v3[91] = 81;
    v3[81] = 208;
    v3[92] = 75;
    v3[93] = 76;
    v3[94] = 77;
    v3[95] = 71;
    v3[96] = 72;
    v3[97] = 73;
    v3[98] = 82;
    v3[99] = 83;
    v3[101] = 221;
    v3[102] = 222;
    v3[103] = 141;
    v3[104] = 100;
    v3[105] = 101;
    v3[106] = 102;
    return v3[hid];
  }
}


// ========================================================================
// ??0idKeyAction@@QAA@XZ
// EA  : 0x82678EC0
// RVA : 0x00678EC0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idKeyAction *__fastcall idKeyAction::idKeyAction(idKeyAction *this)
{
  this->binding.len = 0;
  this->binding.allocedAndFlag = 20;
  this->binding.data = this->binding.baseBuffer;
  this->binding.baseBuffer[0] = 0;
  this->usercmdAction = UB_NONE;
  return this;
}


// ========================================================================
// ?SetBinding@idKeyInput@@SAXHW4bindSet_t@@W4keyNum_t@@PBD@Z
// EA  : 0x82678EF8
// RVA : 0x00678EF8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall idKeyInput::SetBinding(
        unsigned int numDevice,
        unsigned int bindset,
        keyNum_t keynum,
        const char *binding)
{
  int v8; // r30

  if ( bindset <= 6 && numDevice < 4 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v8 = 296 * (7 * numDevice + bindset) + keynum;
    idStr::operator=(this: &keyActions[0][0][v8].binding, text: binding);
    keyActions[0][0][v8].usercmdAction = usercmdGen->BindStringUsercmdAction(this: usercmdGen, a2: binding);
    cvarSystem->SetModifiedFlags(this: cvarSystem, a2: 0x10000);
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// __unwind$220552
// EA  : 0x82678FD0
// RVA : 0x00678FD0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_220552()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetBinding@idKeyInput@@SAPBDHW4bindSet_t@@W4keyNum_t@@@Z
// EA  : 0x82678FF8
// RVA : 0x00678FF8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

char *__fastcall idKeyInput::GetBinding(unsigned int numDevice, unsigned int bindset, keyNum_t keynum)
{
  if ( bindset > 6 || numDevice >= 4 )
    return &byte_8200D768;
  else
    return keyActions[numDevice][bindset][keynum].binding.data;
}


// ========================================================================
// ?unbindAll_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82679060
// RVA : 0x00679060
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall unbindAll_f(const idCmdArgs *args)
{
  unsigned int valueInteger; // r26
  int v2; // r22
  unsigned int v3; // r30
  unsigned int v4; // r30
  cmdGenButton_t v5; // r3
  idCVarSystem *v6; // r11

  valueInteger = userDeviceNum;
  if ( key_deviceBindOverride.valueInteger >= 0 )
    valueInteger = key_deviceBindOverride.valueInteger;
  v2 = 0;
  v3 = in_bindset.valueInteger;
  do
  {
    if ( v3 <= 6 && valueInteger < 4 )
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      v4 = 296 * (7 * valueInteger + v3) + v2;
      idStr::operator=(this: &keyActions[0][0][v4].binding, text: &byte_8200D768);
      v5 = usercmdGen->BindStringUsercmdAction(this: usercmdGen, a2: &byte_8200D768);
      v6 = cvarSystem;
      keyActions[0][0][v4].usercmdAction = v5;
      v6->SetModifiedFlags(this: v6, a2: 0x10000);
      idMem::PopHeap(this: &mem);
      v3 = in_bindset.valueInteger;
    }
    ++v2;
  }
  while ( v2 < 296 );
}


// ========================================================================
// __unwind$220602
// EA  : 0x82679174
// RVA : 0x00679174
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_220602()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 176 + 80));
}


// ========================================================================
// ?bind_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826791A0
// RVA : 0x006791A0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall bind_f(const idCmdArgs *args)
{
  int argc; // r31
  const char *v3; // r3
  keyNum_t v4; // r3
  keyNum_t v5; // r5
  unsigned int valueInteger; // r4
  unsigned int v7; // r7
  unsigned __int32 v8; // r11
  char *data; // r5
  int v10; // r9
  int v11; // r31
  char **v12; // r8
  int v13; // ctr
  char *v14; // r10
  char *v15; // r11
  int v16; // r3
  char *v17; // r11
  int v18; // r3
  const char *v19; // r10
  char *v20; // r11
  int v21; // r3
  char *v22; // r11
  int v23; // r3
  char v24[1056]; // [sp+50h] [-420h] BYREF

  argc = args->argc;
  if ( args->argc >= 2 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    v4 = idKeyInput::StringToKeyNum(str: v3);
    v5 = v4;
    if ( v4 != K_NONE )
    {
      valueInteger = in_bindset.valueInteger;
      if ( in_bindset.valueInteger <= 6u )
      {
        v7 = userDeviceNum;
        if ( key_deviceBindOverride.valueInteger >= 0 )
          v7 = key_deviceBindOverride.valueInteger;
        if ( argc == 2 )
        {
          v8 = 296 * (7 * v7 + in_bindset.valueInteger) + v4;
          if ( keyActions[0][0][v8].binding.len != 0 )
          {
            data = keyActions[0][0][v8].binding.data;
            if ( args->argc <= 1 )
              idLib::Printf(fmt: "\"%s\" = \"%s\"\n", &byte_8200D768, data);
            else
              idLib::Printf(fmt: "\"%s\" = \"%s\"\n", args->argv[1], data);
          }
          else if ( args->argc <= 1 )
          {
            idLib::Printf(fmt: "\"%s\" is not bound\n", &byte_8200D768);
          }
          else
          {
            idLib::Printf(fmt: "\"%s\" is not bound\n", args->argv[1]);
          }
        }
        else
        {
          v10 = 2;
          v24[0] = 0;
          if ( argc > 2 )
          {
            v12 = &args->argv[2];
            v13 = argc - 2;
            v11 = argc - 1;
            do
            {
              if ( v10 < 0 || v10 >= args->argc )
                v14 = &byte_8200D768;
              else
                v14 = *v12;
              v15 = v24;
              do
                v16 = (unsigned __int8)*v15++;
              while ( v16 != 0 );
              v17 = v15 - 1;
              do
              {
                v18 = (unsigned __int8)*v14++;
                *v17++ = v18;
              }
              while ( v18 != 0 );
              if ( v10 != v11 )
              {
                v19 = " ";
                v20 = v24;
                do
                  v21 = (unsigned __int8)*v20++;
                while ( v21 != 0 );
                v22 = v20 - 1;
                do
                {
                  v23 = *(unsigned __int8 *)v19++;
                  *v22++ = v23;
                }
                while ( v23 != 0 );
              }
              ++v10;
              ++v12;
              --v13;
            }
            while ( v13 != 0 );
          }
          idKeyInput::SetBinding(numDevice: v7, bindset: valueInteger, keynum: v5, binding: v24);
        }
      }
    }
    else if ( args->argc <= 1 )
    {
      idLib::Printf(fmt: "\"%s\" isn't a valid key\n", &byte_8200D768);
    }
    else
    {
      idLib::Printf(fmt: "\"%s\" isn't a valid key\n", args->argv[1]);
    }
  }
  else
  {
    idLib::Printf(fmt: "bind <key> [command] : attach a command to a key\n");
  }
}


// ========================================================================
// ?listBinds_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82679410
// RVA : 0x00679410
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall listBinds_f(const idCmdArgs *args)
{
  int valueInteger; // r11
  int v2; // r28
  int i; // r26
  int j; // r31
  int v5; // r10
  keyname_t *v6; // r11
  const char *name; // r4

  valueInteger = userDeviceNum;
  if ( key_deviceBindOverride.valueInteger >= 0 )
    valueInteger = key_deviceBindOverride.valueInteger;
  v2 = 2072 * valueInteger;
  for ( i = 0; i < 7; ++i )
  {
    idLib::Printf(fmt: "Bindset %d\n", i);
    for ( j = 0; j < 296; ++j )
    {
      v5 = v2 + j;
      if ( keyActions[0][0][v5].binding.len != 0 )
      {
        v6 = keynames;
        if ( keynames[0].name != nullptr )
        {
          while ( j != v6->keynum )
          {
            ++v6;
            if ( v6->name == nullptr )
              goto LABEL_9;
          }
          name = v6->name;
        }
        else
        {
LABEL_9:
          name = "?";
        }
        idLib::Printf(fmt: "%s \"%s\"\n", name, keyActions[0][0][v5].binding.data);
      }
    }
    v2 += 296;
  }
}


// ========================================================================
// ?UnbindBinding@idKeyInput@@SAXHW4bindSet_t@@PBDW4inputType_t@@@Z
// EA  : 0x82679508
// RVA : 0x00679508
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall idKeyInput::UnbindBinding(
        unsigned int numDevice,
        unsigned int bindset,
        const char *binding,
        inputType_t inputType)
{
  keyNum_t i; // r30
  bool v9; // cr57

  if ( binding != nullptr && *binding != 0 )
  {
    for ( i = K_NONE; i < K_LAST_KEY; ++i )
    {
      if ( inputType != INPUT_TYPE_KEYBOARD )
      {
        if ( inputType == INPUT_TYPE_MOUSE )
        {
          if ( i < K_MOUSE1 )
            continue;
          v9 = i > K_MWHEELUP;
        }
        else
        {
          if ( inputType != INPUT_TYPE_GAMEPAD || i < K_JOY1 )
            continue;
          v9 = i > K_JOY_DPAD_RIGHT;
        }
        if ( !v9 )
        {
LABEL_14:
          if ( idStr::Icmp(s1: keyActions[numDevice][bindset][i].binding.data, s2: binding) == 0 )
            idKeyInput::SetBinding(numDevice, bindset, keynum: i, binding: &byte_8200D768);
        }
      }
      else if ( i < K_JOY1 )
      {
        goto LABEL_14;
      }
    }
  }
}


// ========================================================================
// ?UnbindBinding@idKeyInput@@SA_NHW4bindSet_t@@PBD@Z
// EA  : 0x826795F0
// RVA : 0x006795F0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

int __fastcall idKeyInput::UnbindBinding(unsigned int numDevice, unsigned int bindset, const char *binding)
{
  int v6; // r24
  keyNum_t v7; // r31
  unsigned int v8; // r26

  v6 = 0;
  if ( binding != nullptr && *binding != 0 )
  {
    v7 = K_NONE;
    v8 = 7 * numDevice + bindset;
    do
    {
      if ( idStr::Icmp(s1: keyActions[0][v8][v7].binding.data, s2: binding) == 0 )
      {
        idKeyInput::SetBinding(numDevice, bindset, keynum: v7, binding: &byte_8200D768);
        v6 = 1;
      }
      ++v7;
    }
    while ( v7 < K_LAST_KEY );
  }
  return v6;
}


// ========================================================================
// ?ExecKeyBinding@idKeyInput@@SA_NHW4bindSet_t@@W4keyNum_t@@@Z
// EA  : 0x826796A0
// RVA : 0x006796A0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

int __fastcall idKeyInput::ExecKeyBinding(int numDevice, bindSet_t bindset, keyNum_t keynum)
{
  int v3; // r11

  v3 = 296 * (7 * numDevice + bindset) + keynum;
  if ( keyActions[0][0][v3].usercmdAction != UB_NONE || keyActions[0][0][v3].binding.len == 0 )
    return 0;
  cmdSystem->AppendCommandText(this: cmdSystem, a2: keyActions[0][0][v3].binding.data);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "\n");
  return 1;
}


// ========================================================================
// ?GetUsercmdActionStr@idKeyInput@@SA?AVidStr@@H@Z
// EA  : 0x82679760
// RVA : 0x00679760
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idStr *__fastcall idKeyInput::GetUsercmdActionStr(idStr *result, int cmd)
{
  userCmdString_t *v3; // r11

  v3 = userCmdStrings;
  if ( userCmdStrings[0].string != nullptr )
  {
    while ( v3->button != cmd )
    {
      ++v3;
      if ( v3->string == nullptr )
        goto LABEL_4;
    }
    idStr::idStr(this: result, text: v3->string);
  }
  else
  {
LABEL_4:
    result->len = 0;
    result->allocedAndFlag = 20;
    result->data = result->baseBuffer;
    result->baseBuffer[0] = 0;
  }
  return result;
}


// ========================================================================
// ?ArgCompletion_KeyName@@YAXAAVidAutoComplete@@@Z
// EA  : 0x826797F0
// RVA : 0x006797F0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall ArgCompletion_KeyName(idAutoComplete *autoComplete)
{
  const char **p_name; // r28
  const char *v3; // r30
  int v4; // r29
  char *v5; // r10
  char *v6; // r9
  char v7; // r11
  idStr v8[3]; // [sp+50h] [-60h] BYREF

  if ( keynames[0].name != nullptr )
  {
    p_name = &keynames[0].name;
    do
    {
      v3 = *p_name;
      v8[0].allocedAndFlag = 20;
      v8[0].data = v8[0].baseBuffer;
      v8[0].len = 0;
      v8[0].baseBuffer[0] = 0;
      if ( v3 != nullptr )
      {
        v4 = 0;
        if ( *v3 != 0 )
        {
          do
            ++v4;
          while ( v3[v4] != 0 );
        }
        idStr::EnsureAlloced(this: v8, amount: v4 + 1, keepold: true, geometricGrowth: false);
        v5 = (char *)(v3 - 1);
        v6 = v8[0].data - 1;
        do
        {
          v7 = *++v5;
          *++v6 = *v5;
        }
        while ( v7 != 0 );
        v8[0].len = v4;
      }
      idAutoComplete::Append(this: autoComplete, suggestion: v8, completingArg: -1);
      idStr::FreeData(this: v8);
      p_name += 3;
    }
    while ( *p_name != nullptr );
  }
}


// ========================================================================
// __unwind$221123
// EA  : 0x826798C8
// RVA : 0x006798C8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221123()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?unbind_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826798F0
// RVA : 0x006798F0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall unbind_f(const idCmdArgs *args)
{
  unsigned int valueInteger; // r31
  keyNum_t v3; // r5
  const char *v4; // r5

  if ( args->argc == 2 )
  {
    valueInteger = userDeviceNum;
    if ( key_deviceBindOverride.valueInteger >= 0 )
      valueInteger = key_deviceBindOverride.valueInteger;
    v3 = idKeyInput::StringToKeyNum(str: args->argv[1]);
    if ( v3 != K_NONE )
    {
      idKeyInput::SetBinding(
        numDevice: valueInteger,
        bindset: in_bindset.valueInteger,
        keynum: v3,
        binding: &byte_8200D768);
    }
    else
    {
      if ( args->argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      if ( (unsigned __int8)idKeyInput::UnbindBinding(
                              numDevice: valueInteger,
                              bindset: in_bindset.valueInteger,
                              binding: v4) == 0 )
      {
        if ( args->argc <= 1 )
          idLib::Printf(fmt: "\"%s\" isn't a valid key\n", &byte_8200D768);
        else
          idLib::Printf(fmt: "\"%s\" isn't a valid key\n", args->argv[1]);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "unbind <key> : remove commands from a key\n");
  }
}


// ========================================================================
// ?KeysFromBinding@idKeyInput@@SA?AVidStr@@HW4bindSet_t@@PBD_N@Z
// EA  : 0x82679A00
// RVA : 0x00679A00
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idStr *__fastcall idKeyInput::KeysFromBinding(
        idStr *result,
        int numDevice,
        bindSet_t bindset,
        const char *bind,
        bool firstOnly)
{
  char **p_data; // r23
  int i; // r28
  char **p_name; // r29

  result->allocedAndFlag = 20;
  result->data = result->baseBuffer;
  result->len = 0;
  result->baseBuffer[0] = 0;
  if ( bind != nullptr && *bind != 0 )
  {
    p_data = &keyActions[numDevice][bindset][0].binding.data;
    for ( i = 0; i < 296; ++i )
    {
      if ( idStr::Icmp(s1: *p_data, s2: bind) == 0 )
      {
        if ( result->len != 0 && !firstOnly )
          idStr::Append(this: result, text: " or ");
        if ( keynames[0].name != nullptr )
        {
          p_name = (char **)&keynames[0].name;
          do
          {
            if ( (char *)i == *(p_name - 1) && (i >= 256 && i <= 281 || i >= 282 && i <= 285) )
            {
              idStr::Append(this: result, text: "<");
              idStr::Append(this: result, text: *p_name);
              idStr::Append(this: result, text: ">");
              if ( firstOnly )
                break;
            }
            p_name += 3;
          }
          while ( *p_name != nullptr );
        }
      }
      p_data += 9;
    }
  }
  return result;
}


// ========================================================================
// __unwind$221235
// EA  : 0x82679B6C
// RVA : 0x00679B6C
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221235()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 192;
  if ( (*(_DWORD *)(v0 - 192 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 212));
  }
}


// ========================================================================
// ?KeyBindingsFromBinding@idKeyInput@@SA?AUkeyBindings_t@@HW4bindSet_t@@PBD@Z
// EA  : 0x82679BB8
// RVA : 0x00679BB8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

keyBindings_t *__fastcall idKeyInput::KeyBindingsFromBinding(
        keyBindings_t *result,
        int numDevice,
        bindSet_t bindset,
        const char *bind)
{
  keyNum_t v6; // r28
  int v7; // r22
  char *v8; // r27
  idStr *v9; // r3
  int len; // r27
  int v11; // r28
  int v12; // r28
  idStr v14; // [sp+60h] [-C0h] BYREF
  idStr v15; // [sp+80h] [-A0h] BYREF
  idStr v16[4]; // [sp+A0h] [-80h] BYREF

  v14.data = v14.baseBuffer;
  v14.allocedAndFlag = 20;
  v14.len = 0;
  v14.baseBuffer[0] = 0;
  v16[0].allocedAndFlag = 20;
  v16[0].data = v16[0].baseBuffer;
  v16[0].len = 0;
  v16[0].baseBuffer[0] = 0;
  v15.allocedAndFlag = 20;
  v15.data = v15.baseBuffer;
  v15.len = 0;
  v15.baseBuffer[0] = 0;
  if ( bind != nullptr && *bind != 0 )
  {
    v6 = K_NONE;
    v7 = 7 * numDevice + bindset;
    do
    {
      if ( idStr::Icmp(s1: keyActions[0][v7][v6].binding.data, s2: bind) == 0 )
      {
        if ( v6 < K_JOY1 || v6 > K_JOY_DPAD_RIGHT )
        {
          if ( v6 < K_MOUSE1 )
          {
            v8 = (char *)idKeyInput::LocalizedKeyName(keynum: v6);
            if ( idStr::Icmp(s1: v8, s2: &byte_8200D768) == 0 || idStr::Icmp(s1: v8, s2: v14.data) == 0 )
              goto LABEL_22;
            if ( v14.len != 0 )
              idStr::Append(this: &v14, text: ", ");
            v9 = &v14;
            goto LABEL_21;
          }
          v8 = (char *)idKeyInput::LocalizedKeyName(keynum: v6);
          if ( idStr::Icmp(s1: v8, s2: &byte_8200D768) != 0 )
          {
            if ( v16[0].len != 0 )
              idStr::Append(this: v16, text: ", ");
            v9 = v16;
            goto LABEL_21;
          }
        }
        else
        {
          v8 = (char *)idKeyInput::LocalizedKeyName(keynum: v6);
          if ( idStr::Icmp(s1: v8, s2: &byte_8200D768) != 0 )
          {
            if ( v15.len != 0 )
              idStr::Append(this: &v15, text: ", ");
            v9 = &v15;
LABEL_21:
            idStr::Append(this: v9, text: v8);
          }
        }
      }
LABEL_22:
      ++v6;
    }
    while ( v6 < K_LAST_KEY );
  }
  result->keyboard.allocedAndFlag = 20;
  result->keyboard.len = 0;
  result->keyboard.data = result->keyboard.baseBuffer;
  result->keyboard.baseBuffer[0] = 0;
  result->mouse.allocedAndFlag = 20;
  result->mouse.data = result->mouse.baseBuffer;
  result->mouse.len = 0;
  result->mouse.baseBuffer[0] = 0;
  result->gamepad.allocedAndFlag = 20;
  result->gamepad.data = result->gamepad.baseBuffer;
  result->gamepad.len = 0;
  result->gamepad.baseBuffer[0] = 0;
  len = v15.len;
  idStr::EnsureAlloced(this: &result->gamepad, amount: v15.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->gamepad.data, Src: v15.data, Size: len);
  result->gamepad.data[len] = 0;
  result->gamepad.len = len;
  v11 = v16[0].len;
  idStr::EnsureAlloced(this: &result->mouse, amount: v16[0].len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->mouse.data, Src: v16[0].data, Size: v11);
  result->mouse.data[v11] = 0;
  result->mouse.len = v11;
  v12 = v14.len;
  idStr::EnsureAlloced(this: &result->keyboard, amount: v14.len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: result->keyboard.data, Src: v14.data, Size: v12);
  result->keyboard.data[v12] = 0;
  result->keyboard.len = v12;
  idStr::FreeData(this: &v15);
  idStr::FreeData(this: v16);
  idStr::FreeData(this: &v14);
  return result;
}


// ========================================================================
// __unwind$221322_0
// EA  : 0x82679EA0
// RVA : 0x00679EA0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221322_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$221323_0
// EA  : 0x82679EC8
// RVA : 0x00679EC8
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221323_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 160));
}


// ========================================================================
// __unwind$221324_0
// EA  : 0x82679EF0
// RVA : 0x00679EF0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221324_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$221325_0
// EA  : 0x82679F18
// RVA : 0x00679F18
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221325_0()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 288;
  if ( (*(_DWORD *)(v0 - 288 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    keyBindings_t::~keyBindings_t(this: *(testReportField_t **)(v1 + 308));
  }
}


// ========================================================================
// ?ArgCompletion_Bind@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82679F68
// RVA : 0x00679F68
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __fastcall ArgCompletion_Bind(idAutoComplete *autoComplete)
{
  idCmdArgs *p_args; // r27
  userCmdString_t *v3; // r30
  const char *i; // r4
  int v5; // r29
  int v6; // r11
  int v7; // r30
  int v8; // r28
  const char *v9; // r4
  int j; // r30
  idStr *list; // r29
  int size; // r30
  idStr *v13; // r28
  int argc; // [sp+50h] [-990h]
  idStr v15; // [sp+60h] [-980h] BYREF
  idAutoComplete v16; // [sp+80h] [-960h] BYREF

  p_args = &autoComplete->args;
  argc = autoComplete->args.argc;
  if ( argc > 2 )
  {
    if ( *autoComplete->args.argv[2] != 0 )
    {
      if ( argc <= 3 )
      {
        v3 = userCmdStrings;
        for ( i = userCmdStrings[0].string; v3->string != nullptr; i = v3->string )
        {
          idStr::idStr(this: &v15, text: i);
          idAutoComplete::Append(this: autoComplete, suggestion: &v15, completingArg: -1);
          idStr::FreeData(this: &v15);
          ++v3;
        }
      }
      v5 = 0;
      v16.matchLength = 0;
      v16.currentIndex = -1;
      v16.args.argc = 0;
      v16.suggestions.memTag = 5;
      v16.suggestions.listStatic = 0;
      memset(&v16.suggestions, 0, 14);
      v6 = p_args->argc;
      v7 = 2;
      if ( p_args->argc > 2 )
      {
        v8 = 2;
        do
        {
          if ( v7 < 0 || v7 >= v6 )
            v9 = &byte_8200D768;
          else
            v9 = p_args->argv[v8];
          idCmdArgs::AppendArg(this: &v16.args, text: v9);
          v6 = p_args->argc;
          ++v7;
          ++v8;
        }
        while ( v7 < p_args->argc );
      }
      cvarSystem->CommandCompletion(this: cvarSystem, a2: &v16);
      cmdSystem->CommandCompletion(this: cmdSystem, a2: &v16);
      for ( j = 0; j < v16.suggestions.num; ++v5 )
      {
        idAutoComplete::Append(this: autoComplete, suggestion: &v16.suggestions.list[v5], completingArg: 2);
        ++j;
      }
      if ( v16.suggestions.listStatic == 0 || v16.suggestions.listStatic == 2 )
      {
        list = v16.suggestions.list;
        if ( v16.suggestions.list != nullptr )
        {
          size = v16.suggestions.size;
          v13 = v16.suggestions.list;
          if ( v16.suggestions.size > 0 )
          {
            do
            {
              idStr::FreeData(this: list);
              --size;
              ++list;
            }
            while ( size != 0 );
          }
          idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
        }
      }
    }
  }
  else
  {
    ArgCompletion_KeyName(autoComplete);
  }
}


// ========================================================================
// __unwind$221650
// EA  : 0x8267A164
// RVA : 0x0067A164
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2528 + 96));
}


// ========================================================================
// __unwind$221651
// EA  : 0x8267A18C
// RVA : 0x0067A18C
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void _unwind_221651()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(v0 - 2528 + 128));
}


// ========================================================================
// `dynamic initializer for 'keyActions''
// EA  : 0x8333B8E0
// RVA : 0x0133B8E0
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__keyActions__()
{
  `eh vector constructor iterator'(
    ptr: (char *)keyActions,
    size: 0x24u,
    count: 8288,
    pCtor: (void (__fastcall *)(void *))idKeyAction::idKeyAction,
    pDtor: (void (__fastcall *)(void *))idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__keyActions__);
}


// ========================================================================
// `dynamic initializer for 'in_bindset''
// EA  : 0x8333B930
// RVA : 0x0133B930
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__in_bindset__()
{
  idCVar::idCVar(
    this: &in_bindset,
    name: "bindset",
    value: "0",
    flags: 18,
    description: "value of current bind set",
    valueMin: 0.0,
    valueMax: 7.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__in_bindset__);
}


// ========================================================================
// `dynamic initializer for 'key_deviceBindOverride''
// EA  : 0x8333B998
// RVA : 0x0133B998
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__key_deviceBindOverride__()
{
  idCVar::idCVar(
    this: &key_deviceBindOverride,
    name: "key_deviceBindOverride",
    value: "-1",
    flags: 2,
    description: " if > -1 will use that device to exec bind commmands on",
    valueMin: -1.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&unk_821D0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__key_deviceBindOverride__);
}


// ========================================================================
// `dynamic initializer for 'unbind_v''
// EA  : 0x8333BA00
// RVA : 0x0133BA00
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__unbind_v__()
{
  return idCommandLink::idCommandLink(
           this: &unbind_v,
           cmdName: "unbind",
           function: unbind_f,
           description: "unbinds any command from a key",
           argCompletion: ArgCompletion_KeyName);
}


// ========================================================================
// `dynamic initializer for 'unbindAll_v''
// EA  : 0x8333BA30
// RVA : 0x0133BA30
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__unbindAll_v__()
{
  return idCommandLink::idCommandLink(
           this: &unbindAll_v,
           cmdName: "unbindAll",
           function: unbindAll_f,
           description: "unbinds any commands from all keys",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'bind_v''
// EA  : 0x8333BA58
// RVA : 0x0133BA58
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__bind_v__()
{
  return idCommandLink::idCommandLink(
           this: &bind_v,
           cmdName: "bind",
           function: bind_f,
           description: "binds a command to a key",
           argCompletion: ArgCompletion_Bind);
}


// ========================================================================
// `dynamic initializer for 'listBinds_v''
// EA  : 0x8333BA88
// RVA : 0x0133BA88
// PDB : w:\tech5\engine\framework\keyinput.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listBinds_v__()
{
  return idCommandLink::idCommandLink(
           this: &listBinds_v,
           cmdName: "listBinds",
           function: listBinds_f,
           description: "lists key bindings",
           argCompletion: nullptr);
}

