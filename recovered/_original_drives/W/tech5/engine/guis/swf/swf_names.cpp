
// ========================================================================
// ?GetTagName@idSWF@@SAPBDW4swfTag_t@@@Z
// EA  : 0x8277CE38
// RVA : 0x0077CE38
// PDB : w:\tech5\engine\guis\swf\swf_names.cpp
// ========================================================================

const char *__fastcall idSWF::GetTagName(swfTag_t tag)
{
  const char *result; // r3

  switch ( tag )
  {
    case Tag_End:
      result = "End";
      break;
    case Tag_ShowFrame:
      result = "ShowFrame";
      break;
    case Tag_DefineShape:
      result = "DefineShape";
      break;
    case Tag_PlaceObject:
      result = "PlaceObject";
      break;
    case Tag_RemoveObject:
      result = "RemoveObject";
      break;
    case Tag_DefineBits:
      result = "DefineBits";
      break;
    case Tag_DefineButton:
      result = "DefineButton";
      break;
    case Tag_JPEGTables:
      result = "JPEGTables";
      break;
    case Tag_SetBackgroundColor:
      result = "SetBackgroundColor";
      break;
    case Tag_DefineFont:
      result = "DefineFont";
      break;
    case Tag_DefineText:
      result = "DefineText";
      break;
    case Tag_DoAction:
      result = "DoAction";
      break;
    case Tag_DefineFontInfo:
      result = "DefineFontInfo";
      break;
    case Tag_DefineSound:
      result = "DefineSound";
      break;
    case Tag_StartSound:
      result = "StartSound";
      break;
    case Tag_DefineButtonSound:
      result = "DefineButtonSound";
      break;
    case Tag_SoundStreamHead:
      result = "SoundStreamHead";
      break;
    case Tag_SoundStreamBlock:
      result = "SoundStreamBlock";
      break;
    case Tag_DefineBitsLossless:
      result = "DefineBitsLossless";
      break;
    case Tag_DefineBitsJPEG2:
      result = "DefineBitsJPEG2";
      break;
    case Tag_DefineShape2:
      result = "DefineShape2";
      break;
    case Tag_DefineButtonCxform:
      result = "DefineButtonCxform";
      break;
    case Tag_Protect:
      result = "Protect";
      break;
    case Tag_PlaceObject2:
      result = "PlaceObject2";
      break;
    case Tag_RemoveObject2:
      result = "RemoveObject2";
      break;
    case Tag_DefineShape3:
      result = "DefineShape3";
      break;
    case Tag_DefineText2:
      result = "DefineText2";
      break;
    case Tag_DefineButton2:
      result = "DefineButton2";
      break;
    case Tag_DefineBitsJPEG3:
      result = "DefineBitsJPEG3";
      break;
    case Tag_DefineBitsLossless2:
      result = "DefineBitsLossless2";
      break;
    case Tag_DefineEditText:
      result = "DefineEditText";
      break;
    case Tag_DefineSprite:
      result = "DefineSprite";
      break;
    case Tag_FrameLabel:
      result = "FrameLabel";
      break;
    case Tag_SoundStreamHead2:
      result = "SoundStreamHead2";
      break;
    case Tag_DefineMorphShape:
      result = "DefineMorphShape";
      break;
    case Tag_DefineFont2:
      result = "DefineFont2";
      break;
    case Tag_ExportAssets:
      result = "ExportAssets";
      break;
    case Tag_ImportAssets:
      result = "ImportAssets";
      break;
    case Tag_EnableDebugger:
      result = "EnableDebugger";
      break;
    case Tag_DoInitAction:
      result = "DoInitAction";
      break;
    case Tag_DefineVideoStream:
      result = "DefineVideoStream";
      break;
    case Tag_VideoFrame:
      result = "VideoFrame";
      break;
    case Tag_DefineFontInfo2:
      result = "DefineFontInfo2";
      break;
    case Tag_EnableDebugger2:
      result = "EnableDebugger2";
      break;
    case Tag_ScriptLimits:
      result = "ScriptLimits";
      break;
    case Tag_SetTabIndex:
      result = "SetTabIndex";
      break;
    case Tag_FileAttributes:
      result = "FileAttributes";
      break;
    case Tag_PlaceObject3:
      result = "PlaceObject3";
      break;
    case Tag_ImportAssets2:
      result = "ImportAssets2";
      break;
    case Tag_DefineFontAlignZones:
      result = "DefineFontAlignZones";
      break;
    case Tag_CSMTextSettings:
      result = "CSMTextSettings";
      break;
    case Tag_DefineFont3:
      result = "DefineFont3";
      break;
    case Tag_SymbolClass:
      result = "SymbolClass";
      break;
    case Tag_Metadata:
      result = "Metadata";
      break;
    case Tag_DefineScalingGrid:
      result = "DefineScalingGrid";
      break;
    case Tag_DoABC:
      result = "DoABC";
      break;
    case Tag_DefineShape4:
      result = "DefineShape4";
      break;
    case Tag_DefineMorphShape2:
      result = "DefineMorphShape2";
      break;
    case Tag_DefineSceneAndFrameLabelData:
      result = "DefineSceneAndFrameLabelData";
      break;
    case Tag_DefineBinaryData:
      result = "DefineBinaryData";
      break;
    case Tag_DefineFontName:
      result = "DefineFontName";
      break;
    case Tag_StartSound2:
      result = "StartSound2";
      break;
    default:
      result = "????";
      break;
  }
  return result;
}


// ========================================================================
// ?GetActionName@idSWF@@SAPBDW4swfAction_t@@@Z
// EA  : 0x8277D2B8
// RVA : 0x0077D2B8
// PDB : w:\tech5\engine\guis\swf\swf_names.cpp
// ========================================================================

const char *__fastcall idSWF::GetActionName(swfAction_t action)
{
  const char *result; // r3

  switch ( action )
  {
    case Action_NextFrame:
      result = "NextFrame";
      break;
    case Action_PrevFrame:
      result = "PrevFrame";
      break;
    case Action_Play:
      result = "Play";
      break;
    case Action_Stop:
      result = "Stop";
      break;
    case Action_ToggleQuality:
      result = "ToggleQuality";
      break;
    case Action_StopSounds:
      result = "StopSounds";
      break;
    case Action_Add:
      result = "Add";
      break;
    case Action_Subtract:
      result = "Subtract";
      break;
    case Action_Multiply:
      result = "Multiply";
      break;
    case Action_Divide:
      result = "Divide";
      break;
    case Action_Equals:
      result = "Equals";
      break;
    case Action_Less:
      result = "Less";
      break;
    case Action_And:
      result = "And";
      break;
    case Action_Or:
      result = "Or";
      break;
    case Action_Not:
      result = "Not";
      break;
    case Action_StringEquals:
      result = "StringEquals";
      break;
    case Action_StringLength:
      result = "StringLength";
      break;
    case Action_StringExtract:
      result = "StringExtract";
      break;
    case Action_Pop:
      result = "Pop";
      break;
    case Action_ToInteger:
      result = "ToInteger";
      break;
    case Action_GetVariable:
      result = "GetVariable";
      break;
    case Action_SetVariable:
      result = "SetVariable";
      break;
    case Action_SetTarget2:
      result = "SetTarget2";
      break;
    case Action_StringAdd:
      result = "StringAdd";
      break;
    case Action_GetProperty:
      result = "GetProperty";
      break;
    case Action_SetProperty:
      result = "SetProperty";
      break;
    case Action_CloneSprite:
      result = "CloneSprite";
      break;
    case Action_RemoveSprite:
      result = "RemoveSprite";
      break;
    case Action_Trace:
      result = "Trace";
      break;
    case Action_StartDrag:
      result = "StartDrag";
      break;
    case Action_EndDrag:
      result = "EndDrag";
      break;
    case Action_StringLess:
      result = "StringLess";
      break;
    case Action_Throw:
      result = "Throw";
      break;
    case Action_CastOp:
      result = "CastOp";
      break;
    case Action_ImplementsOp:
      result = "ImplementsOp";
      break;
    case Action_RandomNumber:
      result = "RandomNumber";
      break;
    case Action_MBStringLength:
      result = "MBStringLength";
      break;
    case Action_CharToAscii:
      result = "CharToAscii";
      break;
    case Action_AsciiToChar:
      result = "AsciiToChar";
      break;
    case Action_GetTime:
      result = "GetTime";
      break;
    case Action_MBStringExtract:
      result = "MBStringExtract";
      break;
    case Action_MBCharToAscii:
      result = "MBCharToAscii";
      break;
    case Action_MBAsciiToChar:
      result = "MBAsciiToChar";
      break;
    case Action_Delete:
      result = "Delete";
      break;
    case Action_Delete2:
      result = "Delete2";
      break;
    case Action_DefineLocal:
      result = "DefineLocal";
      break;
    case Action_CallFunction:
      result = "CallFunction";
      break;
    case Action_Return:
      result = "Return";
      break;
    case Action_Modulo:
      result = "Modulo";
      break;
    case Action_NewObject:
      result = "NewObject";
      break;
    case Action_DefineLocal2:
      result = "DefineLocal2";
      break;
    case Action_InitArray:
      result = "InitArray";
      break;
    case Action_InitObject:
      result = "InitObject";
      break;
    case Action_TypeOf:
      result = "TypeOf";
      break;
    case Action_TargetPath:
      result = "TargetPath";
      break;
    case Action_Enumerate:
      result = "Enumerate";
      break;
    case Action_Add2:
      result = "Add2";
      break;
    case Action_Less2:
      result = "Less2";
      break;
    case Action_Equals2:
      result = "Equals2";
      break;
    case Action_ToNumber:
      result = "ToNumber";
      break;
    case Action_ToString:
      result = "ToString";
      break;
    case Action_PushDuplicate:
      result = "PushDuplicate";
      break;
    case Action_StackSwap:
      result = "StackSwap";
      break;
    case Action_GetMember:
      result = "GetMember";
      break;
    case Action_SetMember:
      result = "SetMember";
      break;
    case Action_Increment:
      result = "Increment";
      break;
    case Action_Decrement:
      result = "Decrement";
      break;
    case Action_CallMethod:
      result = "CallMethod";
      break;
    case Action_NewMethod:
      result = "NewMethod";
      break;
    case Action_InstanceOf:
      result = "InstanceOf";
      break;
    case Action_Enumerate2:
      result = "Enumerate2";
      break;
    case Action_BitAnd:
      result = "BitAnd";
      break;
    case Action_BitOr:
      result = "BitOr";
      break;
    case Action_BitXor:
      result = "BitXor";
      break;
    case Action_BitLShift:
      result = "BitLShift";
      break;
    case Action_BitRShift:
      result = "BitRShift";
      break;
    case Action_BitURShift:
      result = "BitURShift";
      break;
    case Action_StrictEquals:
      result = "StrictEquals";
      break;
    case Action_Greater:
      result = "Greater";
      break;
    case Action_StringGreater:
      result = "StringGreater";
      break;
    case Action_Extends:
      result = "Extends";
      break;
    case Action_GotoFrame:
      result = "GotoFrame";
      break;
    case Action_GetURL:
      result = "GetURL";
      break;
    case Action_StoreRegister:
      result = "StoreRegister";
      break;
    case Action_ConstantPool:
      result = "ConstantPool";
      break;
    case Action_WaitForFrame:
      result = "WaitForFrame";
      break;
    case Action_SetTarget:
      result = "SetTarget";
      break;
    case Action_GoToLabel:
      result = "GoToLabel";
      break;
    case Action_WaitForFrame2:
      result = "WaitForFrame2";
      break;
    case Action_DefineFunction2:
      result = "DefineFunction2";
      break;
    case Action_Try:
      result = "Try";
      break;
    case Action_With:
      result = "With";
      break;
    case Action_Push:
      result = "Push";
      break;
    case Action_Jump:
      result = "Jump";
      break;
    case Action_GetURL2:
      result = "GetURL2";
      break;
    case Action_DefineFunction:
      result = "DefineFunction";
      break;
    case Action_If:
      result = "If";
      break;
    case Action_Call:
      result = "Call";
      break;
    case Action_GotoFrame2:
      result = "GotoFrame2";
      break;
    default:
      result = "???";
      break;
  }
  return result;
}

