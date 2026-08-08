
// ========================================================================
// ?GetObjectList@idSuperScriptLocal@@UAAPAPBDXZ
// EA  : 0x82EE07E0
// RVA : 0x00EE07E0
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

const char **__fastcall idSuperScriptLocal::GetObjectList(idSuperScriptLocal *this)
{
  return objectList;
}


// ========================================================================
// ?GetCommentTextFor@idSuperScriptLocal@@UAAPBDPBD@Z
// EA  : 0x82EE07F8
// RVA : 0x00EE07F8
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

const char *__fastcall idSuperScriptLocal::GetCommentTextFor(idSuperScriptLocal *this, const char *type)
{
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: type);
  if ( v4.len == 18 )
  {
    if ( ssString::Cmp(this: &v4, text: "musicManagerSwitch") == 0 )
    {
      ssString::Empty(this: &v4);
      return "Transition from one manager to another";
    }
  }
  else if ( v4.len == 20 && ssString::Cmp(this: &v4, text: "phook_test1_derrived") == 0 )
  {
    ssString::Empty(this: &v4);
    return "This is also a commented object";
  }
  ssString::Empty(this: &v4);
  return nullptr;
}


// ========================================================================
// __unwind$20540
// EA  : 0x82EE08B8
// RVA : 0x00EE08B8
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_20540()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetVariablesFor@idSuperScriptLocal@@UAAPAUssVarInfo_t@@PBD@Z
// EA  : 0x82EE08E8
// RVA : 0x00EE08E8
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

ssVarInfo_t *__fastcall idSuperScriptLocal::GetVariablesFor(idSuperScriptLocal *this, const char *type)
{
  ssVarInfo_t *result; // r3
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: type);
  switch ( v4.len )
  {
    case 8:
      if ( ssString::Cmp(this: &v4, text: "dy_world") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_32;
      break;
    case 9:
      if ( ssString::Cmp(this: &v4, text: "ssComment") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_31;
      break;
    case 0xB:
      if ( ssString::Cmp(this: &v4, text: "_combatGoal") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "phook_test1") != 0 )
          goto LABEL_70;
        ssString::Empty(this: &v4);
        result = varInfo_29;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_30;
      }
      break;
    case 0xC:
      if ( ssString::Cmp(this: &v4, text: "musicManager") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "aiObjectTest") != 0 )
          goto LABEL_70;
        ssString::Empty(this: &v4);
        result = varInfo_27;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_28;
      }
      break;
    case 0xD:
      if ( ssString::Cmp(this: &v4, text: "musicModifier") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_26;
      break;
    case 0x10:
      if ( ssString::Cmp(this: &v4, text: "_goalKillCounter") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_25;
      break;
    case 0x12:
      if ( ssString::Cmp(this: &v4, text: "util_triggerLookAt") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "musicManagerSwitch") != 0 )
        {
          if ( ssString::Cmp(this: &v4, text: "util_debugMetaData") != 0 )
            goto LABEL_70;
          ssString::Empty(this: &v4);
          result = varInfo_22;
        }
        else
        {
          ssString::Empty(this: &v4);
          result = varInfo_23;
        }
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_24;
      }
      break;
    case 0x13:
      if ( ssString::Cmp(this: &v4, text: "tensionTransition_t") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "util_replaceTargets") != 0 )
          goto LABEL_70;
        ssString::Empty(this: &v4);
        result = varInfo_20;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_21;
      }
      break;
    case 0x14:
      if ( ssString::Cmp(this: &v4, text: "util_distanceTrigger") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_19;
      break;
    case 0x15:
      if ( ssString::Cmp(this: &v4, text: "util_entityFlagVolume") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "_goalRemainingCounter") != 0 )
          goto LABEL_70;
        ssString::Empty(this: &v4);
        result = varInfo_17;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_18;
      }
      break;
    case 0x16:
      if ( ssString::Cmp(this: &v4, text: "util_triggerVisibility") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_16;
      break;
    case 0x17:
      if ( ssString::Cmp(this: &v4, text: "util_entityFlagActivate") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "action_moveToGoalEntity") != 0 )
          goto LABEL_70;
        ssString::Empty(this: &v4);
        result = varInfo_14;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_15;
      }
      break;
    case 0x18:
      if ( ssString::Cmp(this: &v4, text: "util_nodeModifierTrigger") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_13;
      break;
    case 0x1A:
      if ( ssString::Cmp(this: &v4, text: "util_entityFlag::flagDef_t") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_12;
      break;
    case 0x1B:
      if ( ssString::Cmp(this: &v4, text: "phook_test1::simpleStruct_t") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_11;
      break;
    case 0x1D:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::fovInfo_t") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_10;
      break;
    case 0x1E:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::actionData") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "util_distanceTrigger::ignore_t") != 0 )
        {
          if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::lineInfo_t") != 0 )
            goto LABEL_70;
          ssString::Empty(this: &v4);
          result = varInfo_7;
        }
        else
        {
          ssString::Empty(this: &v4);
          result = varInfo_8;
        }
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_9;
      }
      break;
    case 0x1F:
      if ( ssString::Cmp(this: &v4, text: "util_triggerLookAtManagerVolume") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::planeInfo_t") != 0 )
        {
          if ( ssString::Cmp(this: &v4, text: "util_entityFlag::callFunction_t") != 0 )
            goto LABEL_70;
          ssString::Empty(this: &v4);
          result = varInfo_4;
        }
        else
        {
          ssString::Empty(this: &v4);
          result = varInfo_5;
        }
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_6;
      }
      break;
    case 0x20:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::circleInfo_t") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "util_removeActorOnTriggerTouched") != 0 )
        {
          if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::sectorInfo_t") != 0 )
            goto LABEL_70;
          ssString::Empty(this: &v4);
          result = varInfo_1;
        }
        else
        {
          ssString::Empty(this: &v4);
          result = varInfo_2;
        }
      }
      else
      {
        ssString::Empty(this: &v4);
        result = varInfo_3;
      }
      break;
    case 0x22:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::cylinderInfo_t") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo_0;
      break;
    case 0x23:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::arcLengthInfo_t") != 0 )
        goto LABEL_70;
      ssString::Empty(this: &v4);
      result = varInfo;
      break;
    default:
LABEL_70:
      ssString::Empty(this: &v4);
      result = nullptr;
      break;
  }
  return result;
}


// ========================================================================
// __unwind$20615
// EA  : 0x82EE0FAC
// RVA : 0x00EE0FAC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_20615()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetEnumTypeInfoFor@idSuperScriptLocal@@UAAPAUssEnumTypeInfo_t@@PBD@Z
// EA  : 0x82EE0FE0
// RVA : 0x00EE0FE0
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

ssEnumTypeInfo_t *__fastcall idSuperScriptLocal::GetEnumTypeInfoFor(idSuperScriptLocal *this, const char *type)
{
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: type);
  if ( v4.len == 20 )
  {
    if ( ssString::Cmp(this: &v4, text: "musicTensionStates_t") == 0 )
    {
      ssString::Empty(this: &v4);
      return &varTypeInfo;
    }
  }
  else if ( v4.len == 38 )
  {
    if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::drawingTestEnum1_t") == 0 )
    {
      ssString::Empty(this: &v4);
      return &varTypeInfo_1;
    }
    if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::drawingTestEnum2_t") == 0 )
    {
      ssString::Empty(this: &v4);
      return &varTypeInfo_0;
    }
  }
  else if ( v4.len == 43 && ssString::Cmp(this: &v4, text: "util_entityFlagActivate::activateBehavior_t") == 0 )
  {
    ssString::Empty(this: &v4);
    return &varTypeInfo_2;
  }
  ssString::Empty(this: &v4);
  return nullptr;
}


// ========================================================================
// __unwind$20919
// EA  : 0x82EE1100
// RVA : 0x00EE1100
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_20919()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetMetaDataFor@idSuperScriptLocal@@UAAPAUssMetaData_t@@PBD@Z
// EA  : 0x82EE1130
// RVA : 0x00EE1130
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

ssMetaData_t *__fastcall idSuperScriptLocal::GetMetaDataFor(idSuperScriptLocal *this, const char *type)
{
  ssMetaData_t *result; // r3
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: type);
  switch ( v4.len )
  {
    case 9:
      if ( ssString::Cmp(this: &v4, text: "ssComment") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_14;
      break;
    case 0xC:
      if ( ssString::Cmp(this: &v4, text: "musicManager") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "aiObjectTest") != 0 )
          goto LABEL_34;
        ssString::Empty(this: &v4);
        result = metaData_12;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = metaData_13;
      }
      break;
    case 0xD:
      if ( ssString::Cmp(this: &v4, text: "musicModifier") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_11;
      break;
    case 0x10:
      if ( ssString::Cmp(this: &v4, text: "_goalKillCounter") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_10;
      break;
    case 0x12:
      if ( ssString::Cmp(this: &v4, text: "util_triggerLookAt") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "musicManagerSwitch") != 0 )
        {
          if ( ssString::Cmp(this: &v4, text: "util_debugMetaData") != 0 )
            goto LABEL_34;
          ssString::Empty(this: &v4);
          result = metaData_7;
        }
        else
        {
          ssString::Empty(this: &v4);
          result = metaData_8;
        }
      }
      else
      {
        ssString::Empty(this: &v4);
        result = metaData_9;
      }
      break;
    case 0x13:
      if ( ssString::Cmp(this: &v4, text: "util_replaceTargets") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_6;
      break;
    case 0x15:
      if ( ssString::Cmp(this: &v4, text: "_goalRemainingCounter") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_5;
      break;
    case 0x16:
      if ( ssString::Cmp(this: &v4, text: "util_triggerVisibility") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_4;
      break;
    case 0x17:
      if ( ssString::Cmp(this: &v4, text: "util_entityFlagActivate") != 0 )
      {
        if ( ssString::Cmp(this: &v4, text: "action_moveToGoalEntity") != 0 )
          goto LABEL_34;
        ssString::Empty(this: &v4);
        result = metaData_2;
      }
      else
      {
        ssString::Empty(this: &v4);
        result = metaData_3;
      }
      break;
    case 0x1E:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::lineInfo_t") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_1;
      break;
    case 0x20:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::circleInfo_t") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData_0;
      break;
    case 0x22:
      if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::cylinderInfo_t") != 0 )
        goto LABEL_34;
      ssString::Empty(this: &v4);
      result = metaData;
      break;
    default:
LABEL_34:
      ssString::Empty(this: &v4);
      result = nullptr;
      break;
  }
  return result;
}


// ========================================================================
// __unwind$20992
// EA  : 0x82EE14D4
// RVA : 0x00EE14D4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_20992()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetTypeSize@idSuperScriptLocal@@UAAHPBD@Z
// EA  : 0x82EE1508
// RVA : 0x00EE1508
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

int __fastcall idSuperScriptLocal::GetTypeSize(idSuperScriptLocal *this, const char *type)
{
  ssString v4; // [sp+50h] [-30h] BYREF

  ssString::Init(this: &v4);
  ssString::operator=(this: &v4, text: type);
  if ( v4.len == 8 )
  {
    if ( ssString::Cmp(this: &v4, text: "ssEntity") == 0 )
    {
      ssString::Empty(this: &v4);
      return 4;
    }
    if ( ssString::Cmp(this: &v4, text: "ssString") == 0 )
    {
LABEL_5:
      ssString::Empty(this: &v4);
      return 16;
    }
  }
  else if ( v4.len == 30 )
  {
    if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::actionData") == 0 )
    {
      ssString::Empty(this: &v4);
      return 8;
    }
    if ( ssString::Cmp(this: &v4, text: "util_debugMetaData::lineInfo_t") == 0 )
    {
      ssString::Empty(this: &v4);
      return 24;
    }
  }
  else if ( v4.len == 31 && ssString::Cmp(this: &v4, text: "util_debugMetaData::planeInfo_t") == 0 )
  {
    goto LABEL_5;
  }
  ssString::Empty(this: &v4);
  return 0;
}


// ========================================================================
// __unwind$21153
// EA  : 0x82EE1640
// RVA : 0x00EE1640
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_21153()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 128 + 80));
}


// ========================================================================
// ?AllocType@idSuperScriptLocal@@UAAPAXPBDH@Z
// EA  : 0x82EE1670
// RVA : 0x00EE1670
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

ssString *__fastcall idSuperScriptLocal::AllocType(idSuperScriptLocal *this, const char *type, int num)
{
  char *v5; // r3
  char *v6; // r29
  int v7; // ctr
  float *v8; // r11
  int v10; // r28
  _BYTE *j; // r27
  char *v12; // r3
  int v13; // ctr
  float *v14; // r11
  int v15; // r29
  ssString *i; // r28
  int v17; // r29
  ssString v18[5]; // [sp+60h] [-50h] BYREF

  ssString::Init(this: v18);
  ssString::operator=(this: v18, text: type);
  if ( v18[0].len == 8 )
  {
    if ( ssString::Cmp(this: v18, text: "ssEntity") != 0 )
    {
      if ( ssString::Cmp(this: v18, text: "ssString") != 0 )
      {
LABEL_36:
        ssString::Empty(this: v18);
        return nullptr;
      }
      v17 = 0;
      for ( i = (ssString *)gameInterface->Allocate(this: gameInterface, a2: 16 * num, a3: -1); v17 < num; ++v17 )
      {
        if ( &i[v17] != nullptr )
          ssString::Init(this: &i[v17]);
      }
    }
    else
    {
      v15 = 0;
      for ( i = (ssString *)gameInterface->Allocate(this: gameInterface, a2: 4 * num, a3: -1); v15 < num; ++v15 )
      {
        if ( (ssString *)((char *)i + 4 * v15) != nullptr )
          idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)(&i->len + v15));
      }
    }
    ssString::Empty(this: v18);
    return i;
  }
  if ( v18[0].len != 30 )
  {
    if ( v18[0].len == 31 && ssString::Cmp(this: v18, text: "util_debugMetaData::planeInfo_t") == 0 )
    {
      v5 = (char *)gameInterface->Allocate(this: gameInterface, a2: 16 * num, a3: -1);
      v6 = v5;
      if ( num > 0 )
      {
        v7 = num;
        v8 = (float *)(v5 + 8);
        do
        {
          if ( v8 != (float *)8 )
          {
            *(v8 - 2) = 0.0;
            *(v8 - 1) = 0.0;
            *v8 = 0.0;
            v8[1] = 0.0;
          }
          v8 += 4;
          --v7;
        }
        while ( v7 != 0 );
      }
LABEL_10:
      ssString::Empty(this: v18);
      return (ssString *)v6;
    }
    goto LABEL_36;
  }
  if ( ssString::Cmp(this: v18, text: "util_debugMetaData::actionData") != 0 )
  {
    if ( ssString::Cmp(this: v18, text: "util_debugMetaData::lineInfo_t") == 0 )
    {
      v12 = (char *)gameInterface->Allocate(this: gameInterface, a2: 24 * num, a3: -1);
      v6 = v12;
      if ( num > 0 )
      {
        v13 = num;
        v14 = (float *)(v12 + 20);
        do
        {
          if ( v14 != (float *)20 )
          {
            *(v14 - 5) = 0.0;
            *(v14 - 4) = 0.0;
            *(v14 - 3) = 0.0;
            *(v14 - 2) = 0.0;
            *(v14 - 1) = 0.0;
            *v14 = 0.0;
          }
          v14 += 6;
          --v13;
        }
        while ( v13 != 0 );
      }
      goto LABEL_10;
    }
    goto LABEL_36;
  }
  v10 = 0;
  for ( j = gameInterface->Allocate(this: gameInterface, a2: 8 * num, a3: -1); v10 < num; ++v10 )
  {
    if ( &j[8 * v10] != nullptr )
    {
      idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&j[8 * v10]);
      j[8 * v10 + 4] = 1;
    }
  }
  ssString::Empty(this: v18);
  return (ssString *)j;
}


// ========================================================================
// __unwind$21243
// EA  : 0x82EE197C
// RVA : 0x00EE197C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_21243()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$21246
// EA  : 0x82EE19A4
// RVA : 0x00EE19A4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_21246()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$21244
// EA  : 0x82EE19DC
// RVA : 0x00EE19DC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_21244()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$21245
// EA  : 0x82EE1A14
// RVA : 0x00EE1A14
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_21245()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 84));
}


// ========================================================================
// ?CheckVersionCRC@idSuperScriptLocal@@UAA_NK@Z
// EA  : 0x82EE1A50
// RVA : 0x00EE1A50
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

BOOL __fastcall idSuperScriptLocal::CheckVersionCRC(idSuperScriptLocal *this, const unsigned int exeCRCVersion)
{
  return (_cntlzw(-612483387 - exeCRCVersion) & 0x20) != 0;
}


// ========================================================================
// ?AllocObject@idSuperScriptLocal@@UAAPAVidSSObject@@PBD@Z
// EA  : 0x82EE5BA0
// RVA : 0x00EE5BA0
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

_goalKillCounter *__fastcall idSuperScriptLocal::AllocObject(idSuperScriptLocal *this, const char *name_)
{
  dy_world *v3; // r3
  _goalKillCounter *v4; // r30
  ssComment *v5; // r3
  idSuperScriptObject *v6; // r3
  ssDebugUtil *v7; // r3
  _combatGoal *v8; // r3
  phook_test1 *v9; // r3
  ssWorldUtil *v10; // r3
  musicManager *v11; // r3
  aiObjectTest *v12; // r3
  musicModifier *v13; // r3
  util_entityFlag *v14; // r3
  _goalKillCounter *v15; // r3
  util_triggerLookAt *v16; // r3
  musicManagerSwitch *v17; // r3
  util_debugMetaData *v18; // r3
  _goalKillCountActor *v19; // r3
  util_replaceTargets *v20; // r3
  util_distanceTrigger *v21; // r3
  idSuperScriptObject *v22; // r3
  idSuperScriptObject *v23; // r3
  util_entityFlagVolume *v24; // r3
  _goalRemainingCounter *v25; // r3
  util_triggerVisibility *v26; // r3
  util_entityFlagActivate *v27; // r3
  action_moveToGoalEntity *v28; // r3
  idSuperScriptObject *v29; // r3
  util_triggerLookAtSafety *v30; // r3
  _goalRemainingCountActor *v31; // r3
  util_triggerLookAtManagerVolume *v32; // r3
  util_removeActorOnTriggerTouched *v33; // r3
  ssString v35; // [sp+60h] [-30h] BYREF

  ssString::Init(this: &v35);
  ssString::operator=(this: &v35, text: name_);
  switch ( v35.len )
  {
    case 8:
      if ( ssString::Cmp(this: &v35, text: "dy_world") != 0 )
        goto LABEL_123;
      v3 = (dy_world *)gameInterface->Allocate(this: gameInterface, a2: 28, a3: -1);
      if ( v3 != nullptr )
        v4 = (_goalKillCounter *)dy_world::dy_world(this: v3);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 9:
      if ( ssString::Cmp(this: &v35, text: "ssComment") != 0 )
        goto LABEL_123;
      v5 = (ssComment *)gameInterface->Allocate(this: gameInterface, a2: 72, a3: -1);
      if ( v5 != nullptr )
        v4 = (_goalKillCounter *)ssComment::ssComment(this: v5);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0xA:
      if ( ssString::Cmp(this: &v35, text: "jake_test1") != 0 )
        goto LABEL_123;
      v6 = (idSuperScriptObject *)gameInterface->Allocate(this: gameInterface, a2: 8, a3: -1);
      v4 = (_goalKillCounter *)v6;
      if ( v6 != nullptr )
      {
        idSuperScriptObject::idSuperScriptObject(this: v6);
        v4->__vftable = (_goalKillCounter_vtbl *)&jake_test1::`vftable';
      }
      else
      {
        v4 = nullptr;
      }
      goto LABEL_122;
    case 0xB:
      if ( ssString::Cmp(this: &v35, text: "ssDebugUtil") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "_combatGoal") != 0 )
        {
          if ( ssString::Cmp(this: &v35, text: "phook_test1") != 0 )
          {
            if ( ssString::Cmp(this: &v35, text: "ssWorldUtil") != 0 )
              goto LABEL_123;
            v10 = (ssWorldUtil *)gameInterface->Allocate(this: gameInterface, a2: 44, a3: -1);
            if ( v10 != nullptr )
              v4 = (_goalKillCounter *)ssWorldUtil::ssWorldUtil(this: v10);
            else
              v4 = nullptr;
          }
          else
          {
            v9 = (phook_test1 *)gameInterface->Allocate(this: gameInterface, a2: 24, a3: -1);
            if ( v9 != nullptr )
              v4 = (_goalKillCounter *)phook_test1::phook_test1(this: v9);
            else
              v4 = nullptr;
          }
        }
        else
        {
          v8 = (_combatGoal *)gameInterface->Allocate(this: gameInterface, a2: 36, a3: -1);
          if ( v8 != nullptr )
            v4 = (_goalKillCounter *)_combatGoal::_combatGoal(this: v8);
          else
            v4 = nullptr;
        }
      }
      else
      {
        v7 = (ssDebugUtil *)gameInterface->Allocate(this: gameInterface, a2: 16, a3: -1);
        if ( v7 != nullptr )
          v4 = (_goalKillCounter *)ssDebugUtil::ssDebugUtil(this: v7);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0xC:
      if ( ssString::Cmp(this: &v35, text: "musicManager") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "aiObjectTest") != 0 )
          goto LABEL_123;
        v12 = (aiObjectTest *)gameInterface->Allocate(this: gameInterface, a2: 16, a3: -1);
        if ( v12 != nullptr )
          v4 = (_goalKillCounter *)aiObjectTest::aiObjectTest(this: v12);
        else
          v4 = nullptr;
      }
      else
      {
        v11 = (musicManager *)gameInterface->Allocate(this: gameInterface, a2: 136, a3: -1);
        if ( v11 != nullptr )
          v4 = (_goalKillCounter *)musicManager::musicManager(this: v11);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0xD:
      if ( ssString::Cmp(this: &v35, text: "musicModifier") != 0 )
        goto LABEL_123;
      v13 = (musicModifier *)gameInterface->Allocate(this: gameInterface, a2: 24, a3: -1);
      if ( v13 != nullptr )
        v4 = (_goalKillCounter *)musicModifier::musicModifier(this: v13);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0xF:
      if ( ssString::Cmp(this: &v35, text: "util_entityFlag") != 0 )
        goto LABEL_123;
      v14 = (util_entityFlag *)gameInterface->Allocate(this: gameInterface, a2: 24, a3: -1);
      if ( v14 != nullptr )
        v4 = (_goalKillCounter *)util_entityFlag::util_entityFlag(this: v14);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0x10:
      if ( ssString::Cmp(this: &v35, text: "_goalKillCounter") != 0 )
        goto LABEL_123;
      v15 = (_goalKillCounter *)gameInterface->Allocate(this: gameInterface, a2: 84, a3: -1);
      if ( v15 != nullptr )
        v4 = _goalKillCounter::_goalKillCounter(this: v15);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0x12:
      if ( ssString::Cmp(this: &v35, text: "util_triggerLookAt") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "musicManagerSwitch") != 0 )
        {
          if ( ssString::Cmp(this: &v35, text: "util_debugMetaData") != 0 )
            goto LABEL_123;
          v18 = (util_debugMetaData *)gameInterface->Allocate(this: gameInterface, a2: 144, a3: -1);
          if ( v18 != nullptr )
            v4 = (_goalKillCounter *)util_debugMetaData::util_debugMetaData(this: v18);
          else
            v4 = nullptr;
        }
        else
        {
          v17 = (musicManagerSwitch *)gameInterface->Allocate(this: gameInterface, a2: 28, a3: -1);
          if ( v17 != nullptr )
            v4 = (_goalKillCounter *)musicManagerSwitch::musicManagerSwitch(this: v17);
          else
            v4 = nullptr;
        }
      }
      else
      {
        v16 = (util_triggerLookAt *)gameInterface->Allocate(this: gameInterface, a2: 72, a3: -1);
        if ( v16 != nullptr )
          v4 = (_goalKillCounter *)util_triggerLookAt::util_triggerLookAt(this: v16);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0x13:
      if ( ssString::Cmp(this: &v35, text: "_goalKillCountActor") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "util_replaceTargets") != 0 )
          goto LABEL_123;
        v20 = (util_replaceTargets *)gameInterface->Allocate(this: gameInterface, a2: 24, a3: -1);
        if ( v20 != nullptr )
          v4 = (_goalKillCounter *)util_replaceTargets::util_replaceTargets(this: v20);
        else
          v4 = nullptr;
      }
      else
      {
        v19 = (_goalKillCountActor *)gameInterface->Allocate(this: gameInterface, a2: 12, a3: -1);
        if ( v19 != nullptr )
          v4 = (_goalKillCounter *)_goalKillCountActor::_goalKillCountActor(this: v19);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0x14:
      if ( ssString::Cmp(this: &v35, text: "util_distanceTrigger") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "phook_test1_derrived") != 0 )
        {
          if ( ssString::Cmp(this: &v35, text: "util_triggerTeleport") != 0 )
            goto LABEL_123;
          v23 = (idSuperScriptObject *)gameInterface->Allocate(this: gameInterface, a2: 8, a3: -1);
          v4 = (_goalKillCounter *)v23;
          if ( v23 != nullptr )
          {
            idSuperScriptObject::idSuperScriptObject(this: v23);
            v4->__vftable = (_goalKillCounter_vtbl *)&util_triggerTeleport::`vftable';
          }
          else
          {
            v4 = nullptr;
          }
        }
        else
        {
          v22 = (idSuperScriptObject *)gameInterface->Allocate(this: gameInterface, a2: 12, a3: -1);
          v4 = (_goalKillCounter *)v22;
          if ( v22 != nullptr )
          {
            idSuperScriptObject::idSuperScriptObject(this: v22);
            *(_DWORD *)&v4->bTriggerFirst = 0;
            v4->__vftable = (_goalKillCounter_vtbl *)&phook_test1_derrived::`vftable';
          }
          else
          {
            v4 = nullptr;
          }
        }
      }
      else
      {
        v21 = (util_distanceTrigger *)gameInterface->Allocate(this: gameInterface, a2: 56, a3: -1);
        if ( v21 != nullptr )
          v4 = (_goalKillCounter *)util_distanceTrigger::util_distanceTrigger(this: v21);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0x15:
      if ( ssString::Cmp(this: &v35, text: "util_entityFlagVolume") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "_goalRemainingCounter") != 0 )
          goto LABEL_123;
        v25 = (_goalRemainingCounter *)gameInterface->Allocate(this: gameInterface, a2: 76, a3: -1);
        if ( v25 != nullptr )
          v4 = (_goalKillCounter *)_goalRemainingCounter::_goalRemainingCounter(this: v25);
        else
          v4 = nullptr;
      }
      else
      {
        v24 = (util_entityFlagVolume *)gameInterface->Allocate(this: gameInterface, a2: 76, a3: -1);
        if ( v24 != nullptr )
          v4 = (_goalKillCounter *)util_entityFlagVolume::util_entityFlagVolume(this: v24);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0x16:
      if ( ssString::Cmp(this: &v35, text: "util_triggerVisibility") != 0 )
        goto LABEL_123;
      v26 = (util_triggerVisibility *)gameInterface->Allocate(this: gameInterface, a2: 36, a3: -1);
      if ( v26 != nullptr )
        v4 = (_goalKillCounter *)util_triggerVisibility::util_triggerVisibility(this: v26);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0x17:
      if ( ssString::Cmp(this: &v35, text: "util_entityFlagActivate") != 0 )
      {
        if ( ssString::Cmp(this: &v35, text: "action_moveToGoalEntity") != 0 )
          goto LABEL_123;
        v28 = (action_moveToGoalEntity *)gameInterface->Allocate(this: gameInterface, a2: 36, a3: -1);
        if ( v28 != nullptr )
          v4 = (_goalKillCounter *)action_moveToGoalEntity::action_moveToGoalEntity(this: v28);
        else
          v4 = nullptr;
      }
      else
      {
        v27 = (util_entityFlagActivate *)gameInterface->Allocate(this: gameInterface, a2: 76, a3: -1);
        if ( v27 != nullptr )
          v4 = (_goalKillCounter *)util_entityFlagActivate::util_entityFlagActivate(this: v27);
        else
          v4 = nullptr;
      }
      goto LABEL_122;
    case 0x18:
      if ( ssString::Cmp(this: &v35, text: "util_nodeModifierTrigger") == 0 )
      {
        v29 = (idSuperScriptObject *)gameInterface->Allocate(this: gameInterface, a2: 12, a3: -1);
        v4 = (_goalKillCounter *)v29;
        if ( v29 != nullptr )
        {
          idSuperScriptObject::idSuperScriptObject(this: v29);
          v4->bTriggerFirst = false;
          v4->__vftable = (_goalKillCounter_vtbl *)&util_nodeModifierTrigger::`vftable';
        }
        else
        {
          v4 = nullptr;
        }
LABEL_122:
        ssString::Empty(this: &v35);
        return v4;
      }
      if ( ssString::Cmp(this: &v35, text: "util_triggerLookAtSafety") == 0 )
      {
        v30 = (util_triggerLookAtSafety *)gameInterface->Allocate(this: gameInterface, a2: 12, a3: -1);
        if ( v30 != nullptr )
          v4 = (_goalKillCounter *)util_triggerLookAtSafety::util_triggerLookAtSafety(this: v30);
        else
          v4 = nullptr;
        goto LABEL_122;
      }
      if ( ssString::Cmp(this: &v35, text: "_goalRemainingCountActor") == 0 )
      {
        v31 = (_goalRemainingCountActor *)gameInterface->Allocate(this: gameInterface, a2: 12, a3: -1);
        if ( v31 != nullptr )
          v4 = (_goalKillCounter *)_goalRemainingCountActor::_goalRemainingCountActor(this: v31);
        else
          v4 = nullptr;
        goto LABEL_122;
      }
LABEL_123:
      AssertionFailed(msg: "Assertion failed: 0");
      ssString::Empty(this: &v35);
      return nullptr;
    case 0x1F:
      if ( ssString::Cmp(this: &v35, text: "util_triggerLookAtManagerVolume") != 0 )
        goto LABEL_123;
      v32 = (util_triggerLookAtManagerVolume *)gameInterface->Allocate(this: gameInterface, a2: 28, a3: -1);
      if ( v32 != nullptr )
        v4 = (_goalKillCounter *)util_triggerLookAtManagerVolume::util_triggerLookAtManagerVolume(this: v32);
      else
        v4 = nullptr;
      goto LABEL_122;
    case 0x20:
      if ( ssString::Cmp(this: &v35, text: "util_removeActorOnTriggerTouched") != 0 )
        goto LABEL_123;
      v33 = (util_removeActorOnTriggerTouched *)gameInterface->Allocate(this: gameInterface, a2: 16, a3: -1);
      if ( v33 != nullptr )
        v4 = (_goalKillCounter *)util_removeActorOnTriggerTouched::util_removeActorOnTriggerTouched(this: v33);
      else
        v4 = nullptr;
      goto LABEL_122;
    default:
      goto LABEL_123;
  }
}


// ========================================================================
// __unwind$24594
// EA  : 0x82EE6884
// RVA : 0x00EE6884
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void _unwind_24594()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$24595
// EA  : 0x82EE68AC
// RVA : 0x00EE68AC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24595(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24596
// EA  : 0x82EE68D4
// RVA : 0x00EE68D4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24596(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24597
// EA  : 0x82EE68FC
// RVA : 0x00EE68FC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24597(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24598
// EA  : 0x82EE6924
// RVA : 0x00EE6924
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24598(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24599
// EA  : 0x82EE694C
// RVA : 0x00EE694C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24599(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24600
// EA  : 0x82EE6974
// RVA : 0x00EE6974
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24600(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24601
// EA  : 0x82EE699C
// RVA : 0x00EE699C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24601(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24602
// EA  : 0x82EE69C4
// RVA : 0x00EE69C4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24602(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24603
// EA  : 0x82EE69EC
// RVA : 0x00EE69EC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24603(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24604
// EA  : 0x82EE6A14
// RVA : 0x00EE6A14
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24604(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24605
// EA  : 0x82EE6A3C
// RVA : 0x00EE6A3C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24605(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24606
// EA  : 0x82EE6A64
// RVA : 0x00EE6A64
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24606(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24607
// EA  : 0x82EE6A8C
// RVA : 0x00EE6A8C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24607(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24608
// EA  : 0x82EE6AB4
// RVA : 0x00EE6AB4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24608(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24609
// EA  : 0x82EE6ADC
// RVA : 0x00EE6ADC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24609(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24610
// EA  : 0x82EE6B04
// RVA : 0x00EE6B04
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24610(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24611
// EA  : 0x82EE6B2C
// RVA : 0x00EE6B2C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24611(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24612
// EA  : 0x82EE6B54
// RVA : 0x00EE6B54
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24612(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24613
// EA  : 0x82EE6B7C
// RVA : 0x00EE6B7C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24613(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24614
// EA  : 0x82EE6BA4
// RVA : 0x00EE6BA4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24614(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24615
// EA  : 0x82EE6BCC
// RVA : 0x00EE6BCC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24615(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24616
// EA  : 0x82EE6BF4
// RVA : 0x00EE6BF4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24616(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24617
// EA  : 0x82EE6C1C
// RVA : 0x00EE6C1C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24617(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24618
// EA  : 0x82EE6C44
// RVA : 0x00EE6C44
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24618(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24619
// EA  : 0x82EE6C6C
// RVA : 0x00EE6C6C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24619(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24620
// EA  : 0x82EE6C94
// RVA : 0x00EE6C94
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24620(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24621
// EA  : 0x82EE6CBC
// RVA : 0x00EE6CBC
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24621(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24622
// EA  : 0x82EE6CE4
// RVA : 0x00EE6CE4
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24622(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24623
// EA  : 0x82EE6D0C
// RVA : 0x00EE6D0C
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24623(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$24624
// EA  : 0x82EE6D34
// RVA : 0x00EE6D34
// PDB : w:\tech5\tungsten\superscript\generated\object_list.cpp
// ========================================================================

void __fastcall _unwind_24624(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}

