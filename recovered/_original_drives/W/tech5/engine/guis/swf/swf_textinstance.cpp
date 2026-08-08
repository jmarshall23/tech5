
// ========================================================================
// ?SwitchSubtitleText@idSWFTextInstance@@QAAXH@Z
// EA  : 0x827993B0
// RVA : 0x007993B0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SwitchSubtitleText(idSWFTextInstance *this, int time)
{
  this->subNeedsSwitch = false;
}


// ========================================================================
// ?SetSubNextStartIndex@idSWFTextInstance@@QAAXH@Z
// EA  : 0x827993C0
// RVA : 0x007993C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SetSubNextStartIndex(idSWFTextInstance *this, int value)
{
  this->subNextStartIndex = value;
}


// ========================================================================
// ?SubtitleCleanup@idSWFTextInstance@@QAAXXZ
// EA  : 0x827993C8
// RVA : 0x007993C8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SubtitleCleanup(idSWFTextInstance *this)
{
  this->subSourceID = -1;
  this->subAlign = -1;
  idStr::operator=(this: &this->text, text: &byte_8200D768);
}


// ========================================================================
// ?SetStrokeInfo@idSWFTextInstance@@QAAX_NMM@Z
// EA  : 0x827993E8
// RVA : 0x007993E8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SetStrokeInfo(idSWFTextInstance *this, bool use, double strength, double weight)
{
  this->useStroke = use;
  if ( use )
  {
    this->strokeWeight = weight;
    this->strokeStrength = strength;
  }
}


// ========================================================================
// ?ReInit@idSWFTextInstance@@QAAXXZ
// EA  : 0x82799468
// RVA : 0x00799468
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::ReInit(idSWFTextInstance *this)
{
  const char *String; // r4
  idSWFEditText *editText; // r11
  idSWFEditText *v4; // r10
  unsigned __int8 a; // r4
  int valueInteger; // r11

  if ( sys_langPolish.valueInteger == 0
    || idStr::Icmp(s1: this->swf->filename.str, s2: "swf/merchants.swf") != 0
    || idStr::Icmp(s1: this->editText->initialText.str, s2: "#str_swf_off") != 0 )
  {
    String = idLocalization::GetString(inString: this->editText->initialText.str);
  }
  else
  {
    String = "RABATU";
  }
  idStr::operator=(this: &this->text, text: String);
  editText = this->editText;
  this->lengthCalculated = false;
  idStr::operator=(this: &this->variable, text: editText->variable.str);
  v4 = this->editText;
  this->color.r = this->editText->color.r;
  this->color.g = v4->color.g;
  this->color.b = v4->color.b;
  a = v4->color.a;
  this->visible = true;
  this->selectionStart = -1;
  this->selectionEnd = -1;
  this->scroll = 0;
  this->scrollTime = 0;
  this->maxscroll = 0;
  this->shiftHeld = false;
  this->lastInputTime = 0;
  this->tooltip = false;
  this->bindset = 0;
  this->renderMode = SWF_TEXT_RENDER_NORMAL;
  this->generatingText = false;
  this->triggerGenerate = false;
  this->rndSpotsVisible = 0;
  this->textSpotsVisible = 0;
  this->startRndTime = 0;
  this->charMultiplier = 0;
  this->prevReplaceIndex = 0;
  this->scrollUpdate = false;
  this->color.a = a;
  this->isSubtitle = false;
  this->subLength = 0;
  this->subAlign = 0;
  this->subUpdating = false;
  this->subCharStartIndex = 0;
  this->subNextStartIndex = 0;
  this->subCharEndIndex = 0;
  this->subDisplayTime = 0;
  this->subStartTime = -1;
  this->subSourceID = -1;
  this->subNeedsSwitch = false;
  this->subForceKill = false;
  this->subKillTimeDelay = 0;
  this->subSwitchTime = 0;
  this->subLastWordIndex = 0;
  this->subPrevLastWordIndex = 0;
  this->subInitialLine = true;
  this->textLength = 0;
  this->inputTextStartChar = 0;
  valueInteger = swf_textRndLetterDelay.valueInteger;
  this->strokeStrength = 1.0;
  this->useStroke = false;
  this->needsSoundUpdate = false;
  this->renderDelay = valueInteger;
  this->useDropShadow = false;
  this->strokeWeight = swf_textStrokeSize.valueFloat;
}


// ========================================================================
// ?NeedsSoundPlayed@idSWFTextInstance@@QAA_NXZ
// EA  : 0x82799620
// RVA : 0x00799620
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

BOOL __fastcall idSWFTextInstance::NeedsSoundPlayed(idSWFTextInstance *this)
{
  return this->soundClip.len != 0 && this->needsSoundUpdate;
}


// ========================================================================
// ?LastWordChanged@idSWFTextInstance@@QAAXHH@Z
// EA  : 0x82799640
// RVA : 0x00799640
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::LastWordChanged(idSWFTextInstance *this, int wordCount, int time)
{
  int num; // r10
  int v4; // r11
  int v5; // r11

  num = this->subtitleTimingInfo.num;
  v4 = this->subPrevLastWordIndex + wordCount;
  if ( v4 < num )
    v5 = v4 - 1;
  else
    v5 = num - 1;
  this->subLastWordIndex = v5;
  if ( this->subStartTime == -1 )
  {
    if ( num <= 0 )
      this->subStartTime = time;
    else
      this->subStartTime = this->subtitleTimingInfo.list->startTime + time;
  }
  this->subSwitchTime = this->subtitleTimingInfo.list[this->subLastWordIndex].startTime + this->subStartTime;
}


// ========================================================================
// ?GetApporoximateSubtitleBreak@idSWFTextInstance@@QAAHH@Z
// EA  : 0x827996C0
// RVA : 0x007996C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

int __fastcall idSWFTextInstance::GetApporoximateSubtitleBreak(idSWFTextInstance *this, int time)
{
  int subStartTime; // r9
  char v4; // r3
  int subLastWordIndex; // r10
  int num; // r4
  subTimingWordData_t *list; // r9
  int v8; // r6
  int v9; // r7
  int v10; // r8
  subTimingWordData_t *v11; // r6
  int v12; // r9
  int v13; // r8
  int v14; // r6
  int v15; // r10
  int startTime; // r9
  int v17; // r9
  int v18; // r10

  subStartTime = this->subStartTime;
  subLastWordIndex = this->subLastWordIndex;
  v4 = 0;
  if ( subStartTime == -1 )
    this->subStartTime = time;
  if ( time >= this->subSwitchTime )
  {
    num = this->subtitleTimingInfo.num;
    this->subPrevLastWordIndex = subLastWordIndex;
    if ( subLastWordIndex < num )
    {
      list = this->subtitleTimingInfo.list;
      v8 = subLastWordIndex;
      v9 = subLastWordIndex;
      while ( !list[v9].forceBreak )
      {
        if ( list[v9].startTime - list[v8].startTime > swf_subtitleLengthGuess.valueInteger )
        {
          v13 = this->subStartTime;
          v14 = subLastWordIndex - 1;
          if ( subLastWordIndex - 1 < 0 )
          {
            startTime = list[subLastWordIndex].startTime;
            this->subLastWordIndex = subLastWordIndex;
            this->subSwitchTime = startTime + v13;
          }
          else
          {
            v15 = list[subLastWordIndex].startTime;
            this->subLastWordIndex = v14;
            this->subSwitchTime = v15 + v13;
          }
          v4 = 1;
          goto LABEL_18;
        }
        ++subLastWordIndex;
        ++v9;
        if ( subLastWordIndex >= this->subtitleTimingInfo.num )
          goto LABEL_18;
      }
      v10 = this->subStartTime;
      v4 = 1;
      v11 = &list[subLastWordIndex];
      if ( subLastWordIndex + 1 >= num )
        v12 = v11->startTime;
      else
        v12 = v11[1].startTime;
      this->subLastWordIndex = subLastWordIndex;
      this->subSwitchTime = v12 + v10;
    }
LABEL_18:
    if ( v4 == 0 && num > 0 )
    {
      v17 = this->subStartTime;
      v18 = this->subtitleTimingInfo.list[num - 1].startTime;
      this->subLastWordIndex = num;
      this->subSwitchTime = v18 + v17;
    }
  }
  return this->subLastWordIndex;
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_text@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799848
// RVA : 0x00799848
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text *this,
        idSWFScriptObject *object,
        __int64 value,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v5; // r30
  idSWFScriptVar *v6; // r3
  const char *String; // r3
  idStr v8[2]; // [sp+50h] [-40h] BYREF

  if ( object != nullptr )
  {
    LODWORD(a5) = object->objectType;
    if ( (_DWORD)a5 == 3 )
    {
      v5.sprite = (idSWFSpriteInstance *)object->data;
      if ( v5.sprite != nullptr )
      {
        v6 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)HIDWORD(value), a3: value, a4, a5);
        String = idLocalization::GetString(inString: (const char *)v6->value.i);
        idStr::operator=(this: (idStr *)&v5.sprite->materialOverride, text: String);
        idStr::FreeData(this: v8);
        if ( v5.sprite->materialOverride == nullptr )
        {
          v5.sprite[4].xOffset = 0.0;
          v5.sprite[1].scriptObject = (idSWFScriptObject *)-1;
          v5.sprite[1].yOffset = NAN;
        }
        HIBYTE(v5.sprite[1].actionScript) = 0;
      }
    }
  }
}


// ========================================================================
// __unwind$223697
// EA  : 0x827998D4
// RVA : 0x007998D4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_223697()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_autoSize@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799900
// RVA : 0x00799900
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFSpriteInstance *sprite; // r31
  char v4; // r3
  int v5; // r10
  unsigned int v6; // r9

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    sprite = object->data.sprite;
    if ( sprite != nullptr )
    {
      v4 = idSWFScriptVar::ToBool(this: value);
      v5 = *(_DWORD *)(*(_DWORD *)&sprite->isPlaying + 16);
      v6 = v5 | 0x10;
      if ( v4 == 0 )
        v6 = v5 & 0xFFFFFFEF;
      *(_DWORD *)(*(_DWORD *)&sprite->isPlaying + 16) = v6;
      HIBYTE(sprite[1].actionScript) = 0;
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_dropShadow@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799978
// RVA : 0x00799978
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      HIBYTE(v3.sprite[1].actions.list) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__stroke@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x827999C8
// RVA : 0x007999C8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      BYTE1(v3.sprite[1].actions.list) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__strokeStrength@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799A18
// RVA : 0x00799A18
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptObject::swfObjectData_t v7; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v7.sprite = (idSWFSpriteInstance *)object->data;
    if ( v7.sprite != nullptr )
      *(float *)&v7.sprite[1].actions.num = idSWFScriptVar::ToFloat(
                                              this: value,
                                              a2: (int)object,
                                              a3: (int)value,
                                              a4,
                                              a5,
                                              a6,
                                              a7);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__strokeWeight@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799A68
// RVA : 0x00799A68
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptObject::swfObjectData_t v7; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v7.sprite = (idSWFSpriteInstance *)object->data;
    if ( v7.sprite != nullptr )
      *(float *)&v7.sprite[1].actions.size = idSWFScriptVar::ToFloat(
                                               this: value,
                                               a2: (int)object,
                                               a3: (int)value,
                                               a4,
                                               a5,
                                               a6,
                                               a7);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__alpha@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799AB8
// RVA : 0x00799AB8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptObject::swfObjectData_t v7; // r31
  int v8; // r11

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v7.sprite = (idSWFSpriteInstance *)object->data;
    if ( v7.sprite != nullptr )
    {
      v8 = (int)(float)(idSWFScriptVar::ToFloat(this: value, a2: (int)object, a3: (int)value, a4, a5, a6, a7)
                      * (float)255.0);
      if ( v8 >= 0 )
      {
        if ( v8 > 255 )
          LOBYTE(v8) = -1;
      }
      else
      {
        LOBYTE(v8) = 0;
      }
      LOBYTE(v7.sprite[1].materialOverride) = v8;
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar__visible@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799B48
// RVA : 0x00799B48
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      HIBYTE(v3.sprite[1].materialWidth) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_selectionStart@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799B98
// RVA : 0x00799B98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      LODWORD(v3.sprite[1].yOffset) = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_selectionEnd@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799BE8
// RVA : 0x00799BE8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite[1].scriptObject = (idSWFScriptObject *)idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_isTooltip@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799C38
// RVA : 0x00799C38
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      LOBYTE(v3.sprite[1].materialWidth) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_tooltipBindset@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799C88
// RVA : 0x00799C88
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      LODWORD(v3.sprite[1].xOffset) = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_delay@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799CD8
// RVA : 0x00799CD8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      *(_DWORD *)&v3.sprite[2].materialWidth = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_updateScroll@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799D28
// RVA : 0x00799D28
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      HIBYTE(v3.sprite[2].xOffset) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_mode@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799D78
// RVA : 0x00799D78
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31
  unsigned int v4; // r3

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
    {
      v4 = idSWFScriptVar::ToInteger(this: value);
      if ( v4 > 4 )
        v4 = 0;
      v3.sprite[1].onEnterFrame.type = v4;
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_scroll@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799DE0
// RVA : 0x00799DE0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v4; // r31
  int valueInteger; // r30

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v4.sprite = (idSWFSpriteInstance *)object->data;
    if ( v4.sprite != nullptr && Sys_Milliseconds() >= v4.sprite[1].displayList.num )
    {
      valueInteger = swf_textScrollSpeed.valueInteger;
      v4.sprite[1].displayList.num = Sys_Milliseconds() + valueInteger;
      v4.sprite[1].displayList.list = (swfDisplayEntry_t *)idSWFScriptVar::ToInteger(this: value);
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_maxscroll@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799E50
// RVA : 0x00799E50
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite[1].displayList.size = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_textColor@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799EA0
// RVA : 0x00799EA0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFSpriteInstance *sprite; // r31
  int v4; // r3

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    sprite = object->data.sprite;
    if ( sprite != nullptr )
    {
      v4 = idSWFScriptVar::ToInteger(this: value);
      BYTE2(sprite[1].materialOverride) = v4;
      HIBYTE(sprite[1].materialOverride) = BYTE1(v4);
      BYTE1(sprite[1].materialOverride) = BYTE2(v4);
    }
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_subtitle@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799F00
// RVA : 0x00799F00
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      HIBYTE(v3.sprite[2].followBorder) = idSWFScriptVar::ToBool(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_subtitleAlign@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799F50
// RVA : 0x00799F50
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      v3.sprite[3].sprite = (idSWFSprite *)idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_subtitleSourceID@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x82799FA0
// RVA : 0x00799FA0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID *this,
        idSWFScriptObject *object,
        idSWFScriptVar *value)
{
  idSWFScriptObject::swfObjectData_t v3; // r31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT )
  {
    v3.sprite = (idSWFSpriteInstance *)object->data;
    if ( v3.sprite != nullptr )
      LODWORD(v3.sprite[3].yOffset) = idSWFScriptVar::ToInteger(this: value);
  }
}


// ========================================================================
// ?Init@idSWFTextInstance@@QAAXPAVidSWFEditText@@PAVidSWFSpriteInstance@@PBDHPAVidSWF@@@Z
// EA  : 0x8279A0A0
// RVA : 0x0079A0A0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::Init(
        idSWFTextInstance *this,
        idSWFEditText *_editText,
        idSWFSpriteInstance *_parent,
        const char *_name,
        int _depth,
        idSWF *_swf)
{
  idSWFSpriteInstance *parent; // r11
  idSWFScriptObject *v8; // r3
  idSWFScriptObject *scriptObject; // r7

  this->editText = _editText;
  this->swf = _swf;
  this->parent = _parent;
  this->depth = _depth;
  idAtomicString::Set(this: &this->name, str_: _name);
  parent = this->parent;
  if ( parent != nullptr )
    ++parent->scriptObject->refCount;
  idSWFTextInstance::ReInit(this);
  v8 = idSWFScriptObject::Alloc();
  this->scriptObject = v8;
  v8->prototype = &textInstanceScriptObjectPrototype;
  ++textInstanceScriptObjectPrototype.refCount;
  scriptObject = this->scriptObject;
  scriptObject->objectType = SWF_OBJECT_TEXT;
  scriptObject->data.sprite = (idSWFSpriteInstance *)this;
}


// ========================================================================
// ?GetParagraphText@idSWFTextInstance@@QAA?AVidStr@@H@Z
// EA  : 0x8279A138
// RVA : 0x0079A138
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFTextInstance *__fastcall idSWFTextInstance::GetParagraphText(
        idSWFTextInstance *this,
        idStr *result,
        int time,
        double a4,
        double a5,
        long double a6)
{
  __int64 v9; // r9
  long double v10; // fp2
  long double v11; // fp2
  int v12; // r11
  int v13; // r7
  int v14; // r10
  int allocedAndFlag; // r9
  int v16; // r8
  int v17; // r9

  if ( result[6].baseBuffer[12] != 0
    || time - *(_DWORD *)&result[6].baseBuffer[4] < *(_DWORD *)&result[6].baseBuffer[16] )
  {
    idStr::idStr((idStr *)this, text: " ");
    return this;
  }
  else if ( result[5].baseBuffer[12] != 0 )
  {
    if ( *(_DWORD *)&result[5].baseBuffer[16] != 0
      && time - *(_DWORD *)result[6].baseBuffer >= swf_textParagraphSpeed.valueInteger )
    {
      *(_DWORD *)result[6].baseBuffer = time;
      HIDWORD(v9) = &swf_textParagraphInc;
      LODWORD(v9) = result[6].data;
      *(double *)&v10 = swf_textParagraphInc.valueFloat;
      *((double *)&v10 + 1) = (float)v9;
      v11 = pow(x: v10, y: a6);
      v12 = *(_DWORD *)&result[6].baseBuffer[8];
      v13 = (int)(float)*(double *)&v11;
      if ( v12 < v13 )
      {
        v14 = 4 * v12;
        while ( 1 )
        {
          if ( v12 >= *(_DWORD *)result[8].baseBuffer )
          {
            result[5].baseBuffer[12] = 0;
            goto LABEL_19;
          }
          allocedAndFlag = result[8].allocedAndFlag;
          v16 = *(_DWORD *)(allocedAndFlag + v14);
          if ( v16 >= *(_DWORD *)&result[1].baseBuffer[12] || v16 >= *(_DWORD *)&result->baseBuffer[12] )
            break;
          v17 = *(_DWORD *)(allocedAndFlag + v14);
          ++v12;
          v14 += 4;
          *(_BYTE *)(*(_DWORD *)&result[1].baseBuffer[16] + v17) = *(_BYTE *)(*(_DWORD *)&result->baseBuffer[16] + v17);
          ++*(_DWORD *)&result[6].baseBuffer[8];
          if ( v12 >= v13 )
          {
            ++result[6].data;
            idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 56));
            return this;
          }
        }
        *(_DWORD *)&result[5].baseBuffer[16] = 0;
      }
      ++result[6].data;
    }
    idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 56));
    return this;
  }
  else
  {
    HIBYTE(result[7].len) = 0;
LABEL_19:
    idStr::idStr((idStr *)this, text: (const idStr *)&result->baseBuffer[12]);
    return this;
  }
}


// ========================================================================
// ?StartRandomText@idSWFTextInstance@@QAAXH@Z
// EA  : 0x8279A2D8
// RVA : 0x0079A2D8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::StartRandomText(idSWFTextInstance *this, unsigned int time)
{
  int v2; // r30
  idStr *p_randomtext; // r29
  const char *String; // r3
  int len; // r9

  v2 = 0;
  this->generatingText = true;
  p_randomtext = &this->randomtext;
  this->textSpotsVisible = 0;
  idStr::operator=(this: &this->randomtext, text: &byte_8200D768);
  this->startRndTime = time;
  this->rndTime = time;
  this->triggerGenerate = false;
  this->rnd.seed = time;
  this->rndSpotsVisible = 0;
  String = idLocalization::GetString(inString: this->text.data);
  idStr::operator=(this: &this->text, text: String);
  len = this->text.len;
  this->lengthCalculated = false;
  if ( len > 0 )
  {
    do
    {
      if ( this->text.data[v2] == 32 )
      {
        idStr::Append(this: p_randomtext, text: " ");
      }
      else
      {
        idStr::Append(this: p_randomtext, text: ".");
        ++this->rndSpotsVisible;
      }
      ++v2;
    }
    while ( v2 < this->text.len );
  }
}


// ========================================================================
// ?GetRandomText@idSWFTextInstance@@QAA?AVidStr@@H@Z
// EA  : 0x8279A3A8
// RVA : 0x0079A3A8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFTextInstance *__fastcall idSWFTextInstance::GetRandomText(idSWFTextInstance *this, idStr *result, int time)
{
  int v6; // r4
  const idStr *v7; // r28
  int valueInteger; // r11
  int v9; // r3
  int v10; // r9
  int v11; // r11
  _BYTE *v12; // r30
  char v13; // r9
  int v14; // r5
  int v15; // r4
  bool v16; // cr58
  int allocedAndFlag; // r11

  if ( result[6].baseBuffer[12] == 0
    && time - *(_DWORD *)&result[6].baseBuffer[4] >= *(_DWORD *)&result[6].baseBuffer[16] )
  {
    if ( result[5].baseBuffer[12] == 0 )
    {
      idStr::idStr((idStr *)this, text: (const idStr *)&result->baseBuffer[12]);
      return this;
    }
    v6 = *(_DWORD *)&result[5].baseBuffer[16];
    if ( v6 > 0 )
    {
      v7 = (idStr *)((char *)result + 56);
      valueInteger = swf_textRndLetterSpeed.valueInteger;
      if ( *(int *)&result[1].baseBuffer[12] >= 10 )
        valueInteger = swf_textRndLetterSpeed.valueInteger / 3;
      if ( time - *(_DWORD *)result[6].baseBuffer < valueInteger )
        goto LABEL_34;
      *(_DWORD *)result[6].baseBuffer = time;
      v9 = idRandom2::RandomInt(this: (idRandom2 *)&result[8].baseBuffer[12], max: v6);
      v10 = 0;
      v11 = 0;
      if ( v7->len <= 0 )
        goto LABEL_34;
      while ( 1 )
      {
        if ( v11 >= *(_DWORD *)&result->baseBuffer[12] )
        {
          *(_DWORD *)&result[5].baseBuffer[16] = 0;
          goto LABEL_34;
        }
        v12 = (_BYTE *)(*(_DWORD *)&result[1].baseBuffer[16] + v11);
        if ( *v12 == 46 )
          ++v10;
        if ( v10 == v9 )
          break;
        if ( ++v11 >= v7->len )
          goto LABEL_34;
      }
      v13 = 0;
      if ( v11 - 1 >= 0 && *(_BYTE *)(*(_DWORD *)&result->baseBuffer[16] + v11 - 1) == 32 || v11 == 0 )
        v13 = 1;
      if ( v13 != 0 || *(_DWORD *)&result[5].baseBuffer[8] == 2 )
      {
        v14 = 90;
        v15 = 65;
      }
      else
      {
        v14 = 122;
        v15 = 97;
      }
      *v12 = idRandom2::RandomInt(this: (idRandom2 *)&result[8].baseBuffer[12], min: v15, max: v14);
      v16 = result[7].data == nullptr;
      --*(_DWORD *)&result[5].baseBuffer[16];
      goto LABEL_32;
    }
    if ( v6 == 0 )
    {
      allocedAndFlag = result[6].allocedAndFlag;
      if ( allocedAndFlag < *(_DWORD *)&result->baseBuffer[12] )
      {
        v7 = (idStr *)((char *)result + 56);
        if ( allocedAndFlag < *(_DWORD *)&result[1].baseBuffer[12] )
        {
          if ( time - *(_DWORD *)result[6].baseBuffer >= swf_textRndLetterSpeed.valueInteger )
          {
            *(_DWORD *)result[6].baseBuffer = time;
            *(_BYTE *)(*(_DWORD *)&result[1].baseBuffer[16] + allocedAndFlag) = *(_BYTE *)(*(_DWORD *)&result->baseBuffer[16]
                                                                                         + allocedAndFlag);
            v16 = result[7].data == nullptr;
            ++result[6].allocedAndFlag;
LABEL_32:
            if ( !v16 )
              HIBYTE(result[8].data) = 1;
          }
        }
        else
        {
          result[6].allocedAndFlag = allocedAndFlag + 1;
        }
LABEL_34:
        if ( *(_DWORD *)&result[5].baseBuffer[16] == 0 && result[6].allocedAndFlag == *(_DWORD *)&result->baseBuffer[12] )
          result[5].baseBuffer[12] = 0;
        idStr::idStr((idStr *)this, text: v7);
        return this;
      }
    }
  }
  idStr::idStr((idStr *)this, text: " ");
  return this;
}


// ========================================================================
// ?UpdateSubtitle@idSWFTextInstance@@QAA_NH@Z
// EA  : 0x8279A600
// RVA : 0x0079A600
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

int __fastcall idSWFTextInstance::UpdateSubtitle(idSWFTextInstance *this, int time)
{
  int subNextStartIndex; // r11

  if ( this->subForceKillQueued )
  {
    *(_WORD *)&this->subForceKillQueued = 1;
    this->subKillTimeDelay = swf_subtitleExtraTime.valueInteger + time;
  }
  if ( this->subUpdating
    && !this->subForceKill
    && (time >= this->subSwitchTime && !this->subNeedsSwitch || !this->subNeedsSwitch && this->subInitialLine) )
  {
    if ( this->subInitialLine && this->subtitleTimingInfo.num > 0 )
    {
      if ( this->subStartTime == -1 )
        this->subStartTime = time - 600;
      if ( time < this->subtitleTimingInfo.list->startTime + this->subStartTime )
        return 1;
      idStr::operator=(this: &this->text, text: &this->subtitleText);
      this->subInitialLine = false;
    }
    subNextStartIndex = this->subNextStartIndex;
    if ( subNextStartIndex + 1 < this->text.len )
    {
      this->subCharStartIndex = subNextStartIndex;
      this->subNeedsSwitch = true;
    }
    else
    {
      this->subForceKillQueued = true;
    }
  }
  if ( this->subForceKill && time >= this->subKillTimeDelay )
  {
    this->subForceKill = false;
    return 0;
  }
  return 1;
}


// ========================================================================
// ?SetSubEndIndex@idSWFTextInstance@@QAAXHH@Z
// EA  : 0x8279A738
// RVA : 0x0079A738
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SetSubEndIndex(idSWFTextInstance *this, int endChar, int time)
{
  int len; // r11

  len = this->text.len;
  this->subCharEndIndex = endChar;
  if ( endChar + 1 >= len )
    idSWFTextInstance::LastWordChanged(this, wordCount: this->subtitleTimingInfo.num, time);
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_variable@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x8279A760
// RVA : 0x0079A760
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable *this,
        idSWFScriptObject *object,
        __int64 value,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v5; // r30
  idSWFScriptVar *v6; // r28
  size_t type; // r29
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  if ( object != nullptr )
  {
    LODWORD(a5) = object->objectType;
    if ( (_DWORD)a5 == 3 )
    {
      v5.sprite = (idSWFSpriteInstance *)object->data;
      if ( v5.sprite != nullptr )
      {
        v6 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)HIDWORD(value), a3: value, a4, a5);
        type = v6->type;
        idStr::EnsureAlloced(
          this: (idStr *)&v5.sprite->onEnterFrame.value,
          amount: v6->type + 1,
          keepold: false,
          geometricGrowth: false);
        memcpy(Dst: (void *)v5.sprite->followBorder, Src: v6->value.object, Size: type);
        *(_BYTE *)(type + v5.sprite->followBorder) = 0;
        v5.sprite->onEnterFrame.value.i = type;
        idStr::FreeData(this: v8);
      }
    }
  }
}


// ========================================================================
// __unwind$225563
// EA  : 0x8279A7EC
// RVA : 0x0079A7EC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_225563()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_renderSound@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x8279A820
// RVA : 0x0079A820
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound *this,
        idSWFScriptObject *object,
        __int64 value,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v5; // r30
  idSWFScriptVar *v6; // r28
  size_t type; // r29
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  if ( object != nullptr )
  {
    LODWORD(a5) = object->objectType;
    if ( (_DWORD)a5 == 3 )
    {
      v5.sprite = (idSWFSpriteInstance *)object->data;
      if ( v5.sprite != nullptr )
      {
        v6 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)HIDWORD(value), a3: value, a4, a5);
        type = v6->type;
        idStr::EnsureAlloced(
          this: (idStr *)&v5.sprite[2].yOffset,
          amount: v6->type + 1,
          keepold: false,
          geometricGrowth: false);
        memcpy(Dst: v5.sprite[2].scriptObject, Src: v6->value.object, Size: type);
        *((_BYTE *)&v5.sprite[2].scriptObject->refCount + type) = 0;
        LODWORD(v5.sprite[2].yOffset) = type;
        idStr::FreeData(this: v8);
      }
    }
  }
}


// ========================================================================
// __unwind$225605
// EA  : 0x8279A8AC
// RVA : 0x0079A8AC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_225605()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?Set@idSWFScriptNativeVar_subtitleSpeaker@idSWFScriptObject_TextInstancePrototype@@UAAXPAVidSWFScriptObject@@ABVidSWFScriptVar@@@Z
// EA  : 0x8279A8E0
// RVA : 0x0079A8E0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker::Set(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker *this,
        idSWFScriptObject *object,
        __int64 value,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v5; // r30
  idSWFScriptVar *v6; // r28
  size_t type; // r29
  idStr v8[2]; // [sp+50h] [-50h] BYREF

  if ( object != nullptr )
  {
    LODWORD(a5) = object->objectType;
    if ( (_DWORD)a5 == 3 )
    {
      v5.sprite = (idSWFSpriteInstance *)object->data;
      if ( v5.sprite != nullptr )
      {
        v6 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v8, result: (idStr *)HIDWORD(value), a3: value, a4, a5);
        type = v6->type;
        idStr::EnsureAlloced(
          this: (idStr *)&v5.sprite[3].followBorder,
          amount: v6->type + 1,
          keepold: false,
          geometricGrowth: false);
        memcpy(Dst: *(void **)&v5.sprite[4].isPlaying, Src: v6->value.object, Size: type);
        *(_BYTE *)(type + *(_DWORD *)&v5.sprite[4].isPlaying) = 0;
        v5.sprite[3].followBorder = type;
        idStr::FreeData(this: v8);
      }
    }
  }
}


// ========================================================================
// __unwind$225647_0
// EA  : 0x8279A96C
// RVA : 0x0079A96C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_225647_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?StartParagraphText@idSWFTextInstance@@QAAXH@Z
// EA  : 0x8279A998
// RVA : 0x0079A998
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::StartParagraphText(idSWFTextInstance *this, unsigned int time)
{
  idStr *p_randomtext; // r28
  int len; // r9
  idList<int,72> *p_indexArray; // r27
  const char *String; // r3
  int v8; // r8
  int v9; // r30
  bool v10; // zf
  int v11; // r8
  int v12; // r10
  signed int num; // r11
  int v14; // r11
  unsigned int seed; // r9
  unsigned int v16; // r4
  int v17; // r3
  unsigned int v18; // r5
  int v19; // r3
  int v20; // [sp+50h] [-50h] BYREF

  this->generatingText = true;
  p_randomtext = &this->randomtext;
  this->textSpotsVisible = 0;
  idStr::operator=(this: &this->randomtext, text: &byte_8200D768);
  len = this->text.len;
  this->startRndTime = time;
  p_indexArray = &this->indexArray;
  this->rndTime = time;
  this->triggerGenerate = false;
  this->prevReplaceIndex = 0;
  this->rnd.seed = time;
  this->rndSpotsVisible = len;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexArray);
  this->charMultiplier = 0;
  String = idLocalization::GetString(inString: this->text.data);
  idStr::operator=(this: &this->text, text: String);
  v8 = this->text.len;
  v9 = 0;
  this->lengthCalculated = false;
  v20 = 0;
  if ( v8 > 0 )
  {
    do
    {
      idStr::Append(this: p_randomtext, text: " ");
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->indexArray,
        obj: (const encounterGroupRole_t *)&v20);
      v10 = ++v9 < this->text.len;
      v20 = v9;
    }
    while ( v10 );
  }
  v11 = 0;
  if ( this->indexArray.num > 0 )
  {
    v12 = 0;
    do
    {
      num = this->indexArray.num;
      if ( num != 0 )
      {
        seed = this->rnd.seed;
        __twllei(num, 0);
        v16 = 1664525 * seed + 1013904223;
        v17 = (v16 >> 10) & 0x7FFF;
        this->rnd.seed = v16;
        v18 = num & ~(__ROL4__(v17, 1) - 1);
        v14 = v17 % num;
        __twlgei(v18, 0xFFFFFFFF);
      }
      else
      {
        v14 = 0;
      }
      ++v11;
      v19 = p_indexArray->list[v12];
      p_indexArray->list[v12++] = p_indexArray->list[v14];
      p_indexArray->list[v14] = v19;
    }
    while ( v11 < this->indexArray.num );
  }
}


// ========================================================================
// ?GetTextLength@idSWFTextInstance@@QAAMXZ
// EA  : 0x8279ABD0
// RVA : 0x0079ABD0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idSWFTextInstance::GetTextLength(
        idSWFTextInstance *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  double v8; // fp1
  __int64 v9; // r10 OVERLAPPED
  idSWFScriptVar *swf; // r4
  double v11; // fp31
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  idSWFScriptVar *v15; // r3
  const char *String; // r3
  const char *v17; // r3
  idSWFEditText *editText; // r29
  idSWFDictionaryEntry *DictionaryEntry; // r3
  __int64 v20; // r9
  double v21; // fp12
  idFont **p_fontID; // r7
  idFont *v23; // r28
  double v24; // fp29
  idFont *v25; // r3
  double v26; // fp30
  double v27; // fp30
  unsigned int PointSize; // r11
  int v29; // r26
  unsigned int v30; // r25
  int v31; // r10
  int v32; // r9
  int v33; // r8
  int v34; // r7
  int v35; // r6
  int v36; // r5
  __int64 v37; // r7
  const glyphInfo_t *Glyph; // r3
  char v39; // r11
  BOOL useStroke; // r8
  double v41; // fp31
  int v43; // [sp+8h] [-108h]
  int v44; // [sp+Ch] [-104h]
  int v45; // [sp+10h] [-100h]
  int v46; // [sp+14h] [-FCh]
  int v47; // [sp+18h] [-F8h]
  unsigned int v48; // [sp+1Ch] [-F4h]
  unsigned int v49; // [sp+50h] [-C0h] BYREF
  idStr v50; // [sp+58h] [-B8h] BYREF
  idStr v51; // [sp+90h] [-80h] BYREF

  if ( !this->lengthCalculated || this->variable.len != 0 )
  {
    idStr::idStr(this: (idStr *)&v50.baseBuffer[12], text: &byte_8200D768);
    swf = (idSWFScriptVar *)this->swf;
    v11 = 0.0;
    if ( swf != nullptr )
    {
      if ( this->variable.len != 0 )
      {
        idSWF::GetGlobal(this: (idSWF *)&v50, result: swf, name: this->variable.data);
        if ( v50.len == 4 )
        {
          idStr::operator=(this: (idStr *)&v50.baseBuffer[12], text: &this->text);
        }
        else
        {
          v15 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v51, result: &v50, a3: v14, a4: v13, a5: v12);
          idStr::operator=(this: (idStr *)&v50.baseBuffer[12], text: (const idStr *)v15);
          idStr::FreeData(this: &v51);
        }
        String = idLocalization::GetString(inString: *(const char **)&v50.baseBuffer[16]);
        idStr::operator=(this: (idStr *)&v50.baseBuffer[12], text: String);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v50);
      }
      else
      {
        v17 = idLocalization::GetString(inString: this->text.data);
        idStr::operator=(this: (idStr *)&v50.baseBuffer[12], text: v17);
      }
      editText = this->editText;
      DictionaryEntry = idSWF::FindDictionaryEntry(
                          this: this->swf,
                          characterID: this->editText->fontID,
                          type: SWF_DICT_FONT);
      LODWORD(v20) = editText->fontHeight;
      v21 = (float)(editText->bounds.br.x - editText->bounds.tl.x);
      p_fontID = &DictionaryEntry->font->fontID;
      HIDWORD(v20) = &sys_langJapanese;
      *(_QWORD *)&v50.allocedAndFlag = v20;
      v23 = *p_fontID;
      v24 = __fabs(v21);
      v25 = *p_fontID;
      v26 = (float)((float)v20 * (float)0.050000001);
      if ( sys_langJapanese.valueInteger != 0 )
      {
        *(_QWORD *)&v50.allocedAndFlag = __PAIR64__(byte_821B0000, idFont::GetPointSize(this: v25));
        v27 = (float)((float)v26 / (float)((float)*(__int64 *)&v50.allocedAndFlag + (float)6.0));
      }
      else
      {
        PointSize = idFont::GetPointSize(this: v25);
        *(_QWORD *)&v50.allocedAndFlag = *(__int64 *)((char *)&v9 - 4);
        v27 = (float)((float)v26 / (float)*(__int64 *)((char *)&v9 - 4));
      }
      v29 = *(_DWORD *)&v50.baseBuffer[12];
      v49 = 0;
      if ( *(int *)&v50.baseBuffer[12] > 0 )
      {
        HIDWORD(v9) = *(_DWORD *)&v50.baseBuffer[16];
        do
        {
          v30 = idStr::UTF8Char(s: (const unsigned __int8 *)HIDWORD(v9), idx: (int *)&v49);
          Glyph = idFont::GetGlyph(
                    this: v23,
                    idx: v30,
                    a3: v36,
                    a4: v35,
                    a5: v34,
                    a6: v33,
                    a7: v32,
                    a8: v31,
                    a9: v43,
                    a10: v44,
                    a11: v45,
                    a12: v46,
                    a13: v47,
                    a14: v48);
          v9 = __PAIR64__(*(unsigned int *)&v50.baseBuffer[16], v49);
          if ( v30 != 94 )
            goto LABEL_24;
          if ( *(_DWORD *)&v50.baseBuffer[16] + v49 == 1
            || *(_BYTE *)(*(_DWORD *)&v50.baseBuffer[16] + v49 - 1) != 94
            || *(_BYTE *)(*(_DWORD *)&v50.baseBuffer[16] + v49) == 0
            || (v39 = 1, *(_BYTE *)(*(_DWORD *)&v50.baseBuffer[16] + v49) == 32) )
          {
            v39 = 0;
          }
          if ( v39 != 0 )
          {
            LODWORD(v9) = ++v49;
          }
          else
          {
LABEL_24:
            LODWORD(v37) = Glyph->xSkip;
            useStroke = this->useStroke;
            *(_QWORD *)&v50.allocedAndFlag = v37;
            v11 = (float)((float)((float)v37 * (float)v27) + (float)v11);
            if ( useStroke )
              v11 = (float)((float)((float)(this->strokeWeight * swf_textStrokeSizeGlyphSpacer.valueFloat) * (float)v27)
                          + (float)v11);
            if ( (editText->flags & 0x10) == 0 && v11 >= v24 )
            {
              v11 = v24;
              break;
            }
          }
        }
        while ( (int)v9 < v29 );
      }
    }
    LODWORD(v9) = (int)v11;
    *(_QWORD *)&v50.allocedAndFlag = v9;
    this->textLength = (int)v11;
    v41 = (float)v9;
    this->lengthCalculated = true;
    idStr::FreeData(this: (idStr *)&v50.baseBuffer[12]);
    v8 = v41;
  }
  else
  {
    LODWORD(a7) = this->textLength;
    *(_QWORD *)&v50.len = a7;
    v8 = (float)a7;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// __unwind$226039
// EA  : 0x8279AEC8
// RVA : 0x0079AEC8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226039()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$226040
// EA  : 0x8279AEF0
// RVA : 0x0079AEF0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226040()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 272 + 88));
}


// ========================================================================
// __unwind$226041
// EA  : 0x8279AF18
// RVA : 0x0079AF18
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226041()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// ?SubtitleComplete@idSWFTextInstance@@QAAXXZ
// EA  : 0x8279AF40
// RVA : 0x0079AF40
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::SubtitleComplete(idSWFTextInstance *this)
{
  subTimingWordData_t *list; // r3

  this->subUpdating = false;
  this->subInitialLine = true;
  this->isSubtitle = false;
  this->subNeedsSwitch = false;
  this->subCharDisplayTime = 0;
  this->subForceKillQueued = false;
  this->subForceKill = false;
  this->subKillTimeDelay = 0;
  this->subSwitchTime = 0;
  this->subLastWordIndex = 0;
  this->subPrevLastWordIndex = 0;
  this->subStartTime = -1;
  idStr::operator=(this: &this->subSpeaker, text: &byte_8200D768);
  idStr::operator=(this: &this->subtitleText, text: &byte_8200D768);
  idStr::operator=(this: &this->text, text: &byte_8200D768);
  if ( this->subtitleTimingInfo.listStatic == 0 || this->subtitleTimingInfo.listStatic == 2 )
  {
    list = this->subtitleTimingInfo.list;
    if ( list != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &list->phrase, num: this->subtitleTimingInfo.size);
    this->subtitleTimingInfo.list = nullptr;
    this->subtitleTimingInfo.size = 0;
  }
  this->subtitleTimingInfo.num = 0;
}


// ========================================================================
// ??0idSWFScriptObject_TextInstancePrototype@@QAA@XZ
// EA  : 0x8279B000
// RVA : 0x0079B000
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptObject_TextInstancePrototype(
        idSWFScriptObject_TextInstancePrototype *this)
{
  idSWFScriptVar v3; // [sp+B0h] [-100h] BYREF
  idSWFScriptVar v4; // [sp+B8h] [-F8h] BYREF
  idSWFScriptVar v5; // [sp+C0h] [-F0h] BYREF
  idSWFScriptVar v6; // [sp+C8h] [-E8h] BYREF
  idSWFScriptVar v7; // [sp+D0h] [-E0h] BYREF
  idSWFScriptVar v8; // [sp+D8h] [-D8h] BYREF
  idSWFScriptVar v9; // [sp+E0h] [-D0h] BYREF
  idSWFScriptVar v10; // [sp+E8h] [-C8h] BYREF
  idSWFScriptVar v11; // [sp+F0h] [-C0h] BYREF
  idSWFScriptVar v12; // [sp+F8h] [-B8h] BYREF
  idSWFScriptVar v13; // [sp+100h] [-B0h] BYREF
  idSWFScriptVar v14; // [sp+108h] [-A8h] BYREF
  idSWFScriptVar v15[20]; // [sp+110h] [-A0h] BYREF

  idSWFScriptObject::idSWFScriptObject(this);
  this->scriptFunction_onKey.refCount = 0;
  this->scriptFunction_onKey.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey::`vftable';
  this->scriptFunction_onChar.refCount = 0;
  this->scriptFunction_onChar.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar::`vftable';
  this->scriptFunction_generateRnd.refCount = 0;
  this->scriptFunction_generateRnd.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd::`vftable';
  this->scriptFunction_calcNumLines.refCount = 0;
  this->scriptFunction_calcNumLines.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines::`vftable';
  this->swfScriptVar_text.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text::`vftable';
  this->swfScriptVar_autoSize.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize::`vftable';
  this->swfScriptVar_dropShadow.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow::`vftable';
  this->swfScriptVar__stroke.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke::`vftable';
  this->swfScriptVar__strokeStrength.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength::`vftable';
  this->swfScriptVar__strokeWeight.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight::`vftable';
  this->swfScriptVar_variable.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable::`vftable';
  this->swfScriptVar__alpha.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha::`vftable';
  this->swfScriptVar_textColor.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor::`vftable';
  this->swfScriptVar__visible.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible::`vftable';
  this->swfScriptVar_scroll.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll::`vftable';
  this->swfScriptVar_maxscroll.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll::`vftable';
  this->swfScriptVar_selectionStart.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart::`vftable';
  this->swfScriptVar_selectionEnd.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd::`vftable';
  this->swfScriptVar_isTooltip.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip::`vftable';
  this->swfScriptVar_tooltipBindset.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset::`vftable';
  this->swfScriptVar_mode.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode::`vftable';
  this->swfScriptVar_delay.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay::`vftable';
  this->swfScriptVar_renderSound.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound::`vftable';
  this->swfScriptVar_updateScroll.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll::`vftable';
  this->swfScriptVar_subtitle.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle::`vftable';
  this->swfScriptVar_subtitleAlign.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign::`vftable';
  this->swfScriptVar_subtitleSourceID.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID::`vftable';
  this->swfScriptVar_subtitleSpeaker.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker::`vftable';
  this->swfScriptVar__textLength.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength::`vftable';
  this->scriptFunction_subtitleSourceCheck.refCount = 0;
  this->scriptFunction_subtitleSourceCheck.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck::`vftable';
  this->scriptFunction_subtitleStart.refCount = 0;
  this->scriptFunction_subtitleStart.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart::`vftable';
  this->scriptFunction_subtitleLength.refCount = 0;
  this->scriptFunction_subtitleLength.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength::`vftable';
  this->scriptFunction_killSubtitle.refCount = 0;
  this->scriptFunction_killSubtitle.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle::`vftable';
  this->scriptFunction_forceKillSubtitle.refCount = 0;
  this->scriptFunction_forceKillSubtitle.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle::`vftable';
  this->scriptFunction_subLastLine.refCount = 0;
  this->scriptFunction_subLastLine.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine::`vftable';
  this->scriptFunction_addSubtitleInfo.refCount = 0;
  this->scriptFunction_addSubtitleInfo.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo::`vftable';
  this->scriptFunction_terminateSubtitle.refCount = 0;
  this->scriptFunction_terminateSubtitle.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle::`vftable';
  this->scriptFunction_clearTimingInfo.refCount = 0;
  this->scriptFunction_clearTimingInfo.__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo_vtbl *)&idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo::`vftable';
  this->scriptFunction_onKey.AddRef(this: &this->scriptFunction_onKey);
  idSWFScriptVar::idSWFScriptVar(this: &v3, nf: &this->scriptFunction_onKey);
  idSWFScriptObject::Set(this, name: "onKey", value: &v3);
  idSWFScriptVar::Free(this: &v3);
  this->scriptFunction_onChar.AddRef(this: &this->scriptFunction_onChar);
  idSWFScriptVar::idSWFScriptVar(this: &v10, nf: &this->scriptFunction_onChar);
  idSWFScriptObject::Set(this, name: "onChar", value: &v10);
  idSWFScriptVar::Free(this: &v10);
  this->scriptFunction_generateRnd.AddRef(this: &this->scriptFunction_generateRnd);
  idSWFScriptVar::idSWFScriptVar(this: &v6, nf: &this->scriptFunction_generateRnd);
  idSWFScriptObject::Set(this, name: "generateRnd", value: &v6);
  idSWFScriptVar::Free(this: &v6);
  this->scriptFunction_calcNumLines.AddRef(this: &this->scriptFunction_calcNumLines);
  idSWFScriptVar::idSWFScriptVar(this: &v14, nf: &this->scriptFunction_calcNumLines);
  idSWFScriptObject::Set(this, name: "calcNumLines", value: &v14);
  idSWFScriptVar::Free(this: &v14);
  this->scriptFunction_clearTimingInfo.AddRef(this: &this->scriptFunction_clearTimingInfo);
  idSWFScriptVar::idSWFScriptVar(this: &v8, nf: &this->scriptFunction_clearTimingInfo);
  idSWFScriptObject::Set(this, name: "clearTimingInfo", value: &v8);
  idSWFScriptVar::Free(this: &v8);
  idSWFScriptObject::SetNative(this, name: "text", native: &this->swfScriptVar_text);
  idSWFScriptObject::SetNative(this, name: "_textLength", native: &this->swfScriptVar__textLength);
  idSWFScriptObject::SetNative(this, name: "autoSize", native: &this->swfScriptVar_autoSize);
  idSWFScriptObject::SetNative(this, name: "dropShadow", native: &this->swfScriptVar_dropShadow);
  idSWFScriptObject::SetNative(this, name: "_stroke", native: &this->swfScriptVar__stroke);
  idSWFScriptObject::SetNative(this, name: "_strokeStrength", native: &this->swfScriptVar__strokeStrength);
  idSWFScriptObject::SetNative(this, name: "_strokeWeight", native: &this->swfScriptVar__strokeWeight);
  idSWFScriptObject::SetNative(this, name: "variable", native: &this->swfScriptVar_variable);
  idSWFScriptObject::SetNative(this, name: "_alpha", native: &this->swfScriptVar__alpha);
  idSWFScriptObject::SetNative(this, name: "textColor", native: &this->swfScriptVar_textColor);
  idSWFScriptObject::SetNative(this, name: "_visible", native: &this->swfScriptVar__visible);
  idSWFScriptObject::SetNative(this, name: "selectionStart", native: &this->swfScriptVar_selectionStart);
  idSWFScriptObject::SetNative(this, name: "selectionEnd", native: &this->swfScriptVar_selectionEnd);
  idSWFScriptObject::SetNative(this, name: "scroll", native: &this->swfScriptVar_scroll);
  idSWFScriptObject::SetNative(this, name: "maxscroll", native: &this->swfScriptVar_maxscroll);
  idSWFScriptObject::SetNative(this, name: "isTooltip", native: &this->swfScriptVar_isTooltip);
  idSWFScriptObject::SetNative(this, name: "tooltipBindset", native: &this->swfScriptVar_tooltipBindset);
  idSWFScriptObject::SetNative(this, name: "mode", native: &this->swfScriptVar_mode);
  idSWFScriptObject::SetNative(this, name: "delay", native: &this->swfScriptVar_delay);
  idSWFScriptObject::SetNative(this, name: "renderSound", native: &this->swfScriptVar_renderSound);
  idSWFScriptObject::SetNative(this, name: "updateScroll", native: &this->swfScriptVar_updateScroll);
  idSWFScriptObject::SetNative(this, name: "subtitle", native: &this->swfScriptVar_subtitle);
  idSWFScriptObject::SetNative(this, name: "subtitleAlign", native: &this->swfScriptVar_subtitleAlign);
  idSWFScriptObject::SetNative(this, name: "subtitleSourceID", native: &this->swfScriptVar_subtitleSourceID);
  idSWFScriptObject::SetNative(this, name: "subtitleSpeaker", native: &this->swfScriptVar_subtitleSpeaker);
  this->scriptFunction_subtitleSourceCheck.AddRef(this: &this->scriptFunction_subtitleSourceCheck);
  idSWFScriptVar::idSWFScriptVar(this: &v12, nf: &this->scriptFunction_subtitleSourceCheck);
  idSWFScriptObject::Set(this, name: "subtitleSourceCheck", value: &v12);
  idSWFScriptVar::Free(this: &v12);
  this->scriptFunction_subtitleStart.AddRef(this: &this->scriptFunction_subtitleStart);
  idSWFScriptVar::idSWFScriptVar(this: &v4, nf: &this->scriptFunction_subtitleStart);
  idSWFScriptObject::Set(this, name: "subtitleStart", value: &v4);
  idSWFScriptVar::Free(this: &v4);
  this->scriptFunction_subtitleLength.AddRef(this: &this->scriptFunction_subtitleLength);
  idSWFScriptVar::idSWFScriptVar(this: &v5, nf: &this->scriptFunction_subtitleLength);
  idSWFScriptObject::Set(this, name: "subtitleLength", value: &v5);
  idSWFScriptVar::Free(this: &v5);
  this->scriptFunction_killSubtitle.AddRef(this: &this->scriptFunction_killSubtitle);
  idSWFScriptVar::idSWFScriptVar(this: &v7, nf: &this->scriptFunction_killSubtitle);
  idSWFScriptObject::Set(this, name: "killSubtitle", value: &v7);
  idSWFScriptVar::Free(this: &v7);
  this->scriptFunction_forceKillSubtitle.AddRef(this: &this->scriptFunction_forceKillSubtitle);
  idSWFScriptVar::idSWFScriptVar(this: &v9, nf: &this->scriptFunction_forceKillSubtitle);
  idSWFScriptObject::Set(this, name: "forceKillSubtitle", value: &v9);
  idSWFScriptVar::Free(this: &v9);
  this->scriptFunction_subLastLine.AddRef(this: &this->scriptFunction_subLastLine);
  idSWFScriptVar::idSWFScriptVar(this: &v11, nf: &this->scriptFunction_subLastLine);
  idSWFScriptObject::Set(this, name: "subLastLine", value: &v11);
  idSWFScriptVar::Free(this: &v11);
  this->scriptFunction_addSubtitleInfo.AddRef(this: &this->scriptFunction_addSubtitleInfo);
  idSWFScriptVar::idSWFScriptVar(this: &v13, nf: &this->scriptFunction_addSubtitleInfo);
  idSWFScriptObject::Set(this, name: "addSubtitleInfo", value: &v13);
  idSWFScriptVar::Free(this: &v13);
  this->scriptFunction_terminateSubtitle.AddRef(this: &this->scriptFunction_terminateSubtitle);
  idSWFScriptVar::idSWFScriptVar(this: v15, nf: &this->scriptFunction_terminateSubtitle);
  idSWFScriptObject::Set(this, name: "terminateSubtitle", value: v15);
  idSWFScriptVar::Free(this: v15);
  return this;
}


// ========================================================================
// __unwind$226185
// EA  : 0x8279B8B0
// RVA : 0x0079B8B0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226185()
{
  int v0; // r12

  idSWFScriptObject::~idSWFScriptObject(this: *(idSWFScriptObject **)(v0 - 432 + 452));
}


// ========================================================================
// __unwind$226186
// EA  : 0x8279B8D8
// RVA : 0x0079B8D8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226186()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 96));
}


// ========================================================================
// __unwind$226187
// EA  : 0x8279B904
// RVA : 0x0079B904
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226187()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 104));
}


// ========================================================================
// __unwind$226188
// EA  : 0x8279B930
// RVA : 0x0079B930
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226188()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 112));
}


// ========================================================================
// __unwind$226189
// EA  : 0x8279B95C
// RVA : 0x0079B95C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226189()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 120));
}


// ========================================================================
// __unwind$226190_0
// EA  : 0x8279B988
// RVA : 0x0079B988
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226190_0()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 128));
}


// ========================================================================
// __unwind$226191_0
// EA  : 0x8279B9B4
// RVA : 0x0079B9B4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226191_0()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 132));
}


// ========================================================================
// __unwind$226192
// EA  : 0x8279B9E0
// RVA : 0x0079B9E0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226192()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 136));
}


// ========================================================================
// __unwind$226193
// EA  : 0x8279BA0C
// RVA : 0x0079BA0C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226193()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 140));
}


// ========================================================================
// __unwind$226194
// EA  : 0x8279BA38
// RVA : 0x0079BA38
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226194()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 144));
}


// ========================================================================
// __unwind$226195
// EA  : 0x8279BA64
// RVA : 0x0079BA64
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226195()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 148));
}


// ========================================================================
// __unwind$226196
// EA  : 0x8279BA90
// RVA : 0x0079BA90
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226196()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 152));
}


// ========================================================================
// __unwind$226197
// EA  : 0x8279BABC
// RVA : 0x0079BABC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226197()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 156));
}


// ========================================================================
// __unwind$226198
// EA  : 0x8279BAE8
// RVA : 0x0079BAE8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226198()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 160));
}


// ========================================================================
// __unwind$226199
// EA  : 0x8279BB14
// RVA : 0x0079BB14
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226199()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 164));
}


// ========================================================================
// __unwind$226200
// EA  : 0x8279BB40
// RVA : 0x0079BB40
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226200()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 168));
}


// ========================================================================
// __unwind$226201
// EA  : 0x8279BB6C
// RVA : 0x0079BB6C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226201()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 172));
}


// ========================================================================
// __unwind$226202
// EA  : 0x8279BB98
// RVA : 0x0079BB98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226202()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 176));
}


// ========================================================================
// __unwind$226203
// EA  : 0x8279BBC4
// RVA : 0x0079BBC4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226203()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 180));
}


// ========================================================================
// __unwind$226204
// EA  : 0x8279BBF0
// RVA : 0x0079BBF0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226204()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 184));
}


// ========================================================================
// __unwind$226205
// EA  : 0x8279BC1C
// RVA : 0x0079BC1C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226205()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 188));
}


// ========================================================================
// __unwind$226206
// EA  : 0x8279BC48
// RVA : 0x0079BC48
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226206()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 192));
}


// ========================================================================
// __unwind$226207
// EA  : 0x8279BC74
// RVA : 0x0079BC74
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226207()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 196));
}


// ========================================================================
// __unwind$226208
// EA  : 0x8279BCA0
// RVA : 0x0079BCA0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226208()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 200));
}


// ========================================================================
// __unwind$226209
// EA  : 0x8279BCCC
// RVA : 0x0079BCCC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226209()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 204));
}


// ========================================================================
// __unwind$226210
// EA  : 0x8279BCF8
// RVA : 0x0079BCF8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226210()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 208));
}


// ========================================================================
// __unwind$226211
// EA  : 0x8279BD24
// RVA : 0x0079BD24
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226211()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 212));
}


// ========================================================================
// __unwind$226212
// EA  : 0x8279BD50
// RVA : 0x0079BD50
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226212()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 216));
}


// ========================================================================
// __unwind$226213
// EA  : 0x8279BD7C
// RVA : 0x0079BD7C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226213()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 220));
}


// ========================================================================
// __unwind$226214
// EA  : 0x8279BDA8
// RVA : 0x0079BDA8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226214()
{
  int v0; // r12

  idSWFScriptObject_SpriteInstancePrototype::idSWFScriptNativeVar__currentframe::~idSWFScriptNativeVar__currentframe(this: (idSWF::idSWFScriptNativeVar_automaticRescale *)(*(_DWORD *)(v0 - 432 + 452) + 224));
}


// ========================================================================
// __unwind$226215
// EA  : 0x8279BDD4
// RVA : 0x0079BDD4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226215()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 228));
}


// ========================================================================
// __unwind$226216
// EA  : 0x8279BE00
// RVA : 0x0079BE00
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226216()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 236));
}


// ========================================================================
// __unwind$226217
// EA  : 0x8279BE2C
// RVA : 0x0079BE2C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226217()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 244));
}


// ========================================================================
// __unwind$226218
// EA  : 0x8279BE58
// RVA : 0x0079BE58
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226218()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 252));
}


// ========================================================================
// __unwind$226219
// EA  : 0x8279BE84
// RVA : 0x0079BE84
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226219()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 260));
}


// ========================================================================
// __unwind$226220
// EA  : 0x8279BEB0
// RVA : 0x0079BEB0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226220()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 268));
}


// ========================================================================
// __unwind$226221
// EA  : 0x8279BEDC
// RVA : 0x0079BEDC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226221()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 276));
}


// ========================================================================
// __unwind$226222
// EA  : 0x8279BF08
// RVA : 0x0079BF08
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226222()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 284));
}


// ========================================================================
// __unwind$226223
// EA  : 0x8279BF34
// RVA : 0x0079BF34
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226223()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: (idSWFScriptFunction_RefCounted *)(*(_DWORD *)(v0 - 432 + 452) + 292));
}


// ========================================================================
// __unwind$226224
// EA  : 0x8279BF60
// RVA : 0x0079BF60
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226224()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$226225
// EA  : 0x8279BF88
// RVA : 0x0079BF88
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226225()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 232));
}


// ========================================================================
// __unwind$226226
// EA  : 0x8279BFB0
// RVA : 0x0079BFB0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226226()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 200));
}


// ========================================================================
// __unwind$226227
// EA  : 0x8279BFD8
// RVA : 0x0079BFD8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226227()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 264));
}


// ========================================================================
// __unwind$226228
// EA  : 0x8279C000
// RVA : 0x0079C000
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226228()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 216));
}


// ========================================================================
// __unwind$226229
// EA  : 0x8279C028
// RVA : 0x0079C028
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226229()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 248));
}


// ========================================================================
// __unwind$226230
// EA  : 0x8279C050
// RVA : 0x0079C050
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226230()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 184));
}


// ========================================================================
// __unwind$226231
// EA  : 0x8279C078
// RVA : 0x0079C078
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226231()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 192));
}


// ========================================================================
// __unwind$226232
// EA  : 0x8279C0A0
// RVA : 0x0079C0A0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226232()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 208));
}


// ========================================================================
// __unwind$226233
// EA  : 0x8279C0C8
// RVA : 0x0079C0C8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226233()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 224));
}


// ========================================================================
// __unwind$226234
// EA  : 0x8279C0F0
// RVA : 0x0079C0F0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226234()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 240));
}


// ========================================================================
// __unwind$226235
// EA  : 0x8279C118
// RVA : 0x0079C118
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226235()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 256));
}


// ========================================================================
// __unwind$226236
// EA  : 0x8279C140
// RVA : 0x0079C140
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_226236()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 272));
}


// ========================================================================
// ?Call@idSWFScriptFunction_clearTimingInfo@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C168
// RVA : 0x0079C168
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)&v5.sprite[4].yOffset);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call clearTimingInfo on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_clearTimingInfo_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_generateRnd@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C1E0
// RVA : 0x0079C1E0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    v5.sprite[1].onEnterFrame.value.b = false;
    HIBYTE(v5.sprite[2].materialOverride) = 1;
    v5.sprite[1].followBorder = -1;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call generateRnd on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_generateRnd_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_subtitleLength@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C268
// RVA : 0x0079C268
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r30

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    *(_DWORD *)&v5.sprite[3].isPlaying = idSWFScriptVar::ToInteger(this: parms->list);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call subtitleLength on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleLength_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_subtitleStart@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C2E8
// RVA : 0x0079C2E8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r31
  size_t materialOverride; // r29

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    HIBYTE(v5.sprite[3].actions.size) = 0;
    BYTE1(v5.sprite[3].actions.size) = 0;
    HIBYTE(v5.sprite[3].parent) = 1;
    BYTE2(v5.sprite[3].actions.size) = 0;
    *(_DWORD *)&v5.sprite[3].actions.granularity = 0;
    materialOverride = (size_t)v5.sprite->materialOverride;
    idStr::EnsureAlloced(
      this: (idStr *)&v5.sprite[3].scriptObject,
      amount: materialOverride + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: v5.sprite[3].displayList.list, Src: *(const void **)&v5.sprite->materialWidth, Size: materialOverride);
    *((_BYTE *)&v5.sprite[3].displayList.list->characterID + materialOverride) = 0;
    v5.sprite[3].scriptObject = (idSWFScriptObject *)materialOverride;
    idStr::operator=(this: (idStr *)&v5.sprite->materialOverride, text: &byte_8200D768);
    v5.sprite[3].depth = 0;
    v5.sprite[3].itemIndex = 0;
    v5.sprite[3].materialOverride = nullptr;
    v5.sprite[3].actionScript = nullptr;
    v5.sprite[3].onEnterFrame.type = SWF_VAR_STRINGID;
    v5.sprite[3].onEnterFrame.value.i = 0;
    v5.sprite[3].xOffset = NAN;
    LOBYTE(v5.sprite[4].materialWidth) = 1;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart_vtbl *)4;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call subtitleStart on NULL edittext");
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleStart_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_forceKillSubtitle@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C3D8
// RVA : 0x0079C3D8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    *(_DWORD *)&v5.sprite[3].actions.granularity = 0;
    BYTE2(v5.sprite[3].actions.size) = 1;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call forceKillSubtitle on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_forceKillSubtitle_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_killSubtitle@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C458
// RVA : 0x0079C458
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r11

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    BYTE1(v5.sprite[3].actions.size) = 1;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call killSubtitle on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_killSubtitle_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_terminateSubtitle@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279C4D0
// RVA : 0x0079C4D0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r31

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    idSWFTextInstance::SubtitleComplete(this: thisObject->data.text);
    v5.sprite[3].yOffset = NAN;
    v5.sprite[3].sprite = (idSWFSprite *)-1;
    idStr::operator=(this: (idStr *)&v5.sprite->materialOverride, text: &byte_8200D768);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call terminateSubtitle on NULL edittext", result);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_terminateSubtitle_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ??0idSWFTextInstance@@QAA@XZ
// EA  : 0x8279C6F0
// RVA : 0x0079C6F0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFTextInstance *__fastcall idSWFTextInstance::idSWFTextInstance(idSWFTextInstance *this)
{
  this->name.str = &byte_8200D768;
  this->text.allocedAndFlag = 20;
  this->text.len = 0;
  this->text.data = this->text.baseBuffer;
  this->text.baseBuffer[0] = 0;
  this->randomtext.allocedAndFlag = 20;
  this->randomtext.len = 0;
  this->randomtext.data = this->randomtext.baseBuffer;
  this->randomtext.baseBuffer[0] = 0;
  this->variable.allocedAndFlag = 20;
  this->variable.len = 0;
  this->variable.data = this->variable.baseBuffer;
  this->variable.baseBuffer[0] = 0;
  this->color.r = -1;
  this->color.g = -1;
  this->color.b = -1;
  this->color.a = -1;
  this->soundClip.allocedAndFlag = 20;
  this->soundClip.data = this->soundClip.baseBuffer;
  this->soundClip.len = 0;
  this->soundClip.baseBuffer[0] = 0;
  this->indexArray.list = nullptr;
  this->indexArray.granularity = 0;
  this->indexArray.memTag = 72;
  this->indexArray.listStatic = 0;
  this->indexArray.size = 0;
  this->indexArray.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexArray);
  this->rnd.seed = 0;
  this->subtitleText.allocedAndFlag = 20;
  this->subtitleText.len = 0;
  this->subtitleText.data = this->subtitleText.baseBuffer;
  this->subtitleText.baseBuffer[0] = 0;
  this->subSpeaker.allocedAndFlag = 20;
  this->subSpeaker.len = 0;
  this->subSpeaker.data = this->subSpeaker.baseBuffer;
  this->subSpeaker.baseBuffer[0] = 0;
  this->subtitleTimingInfo.granularity = 0;
  this->subtitleTimingInfo.memTag = 72;
  this->subtitleTimingInfo.listStatic = 0;
  this->subtitleTimingInfo.list = nullptr;
  this->subtitleTimingInfo.size = 0;
  this->subtitleTimingInfo.num = 0;
  this->swf = nullptr;
  return this;
}


// ========================================================================
// __unwind$227250
// EA  : 0x8279C830
// RVA : 0x0079C830
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227250()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// __unwind$227251
// EA  : 0x8279C85C
// RVA : 0x0079C85C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227251()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$227252
// EA  : 0x8279C888
// RVA : 0x0079C888
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227252()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 88));
}


// ========================================================================
// __unwind$227253
// EA  : 0x8279C8B4
// RVA : 0x0079C8B4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227253()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 228));
}


// ========================================================================
// __unwind$227254
// EA  : 0x8279C8E0
// RVA : 0x0079C8E0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227254()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 264));
}


// ========================================================================
// __unwind$227255
// EA  : 0x8279C90C
// RVA : 0x0079C90C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 328));
}


// ========================================================================
// __unwind$227256
// EA  : 0x8279C938
// RVA : 0x0079C938
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 380));
}


// ========================================================================
// ??1idSWFTextInstance@@QAA@XZ
// EA  : 0x8279C970
// RVA : 0x0079C970
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __fastcall idSWFTextInstance::~idSWFTextInstance(idSWFTextInstance *this)
{
  idSWFSpriteInstance *parent; // r11
  idSWFScriptObject *scriptObject; // r29
  int TextOrphanIndex; // r4
  idSWFScriptObject *v6; // r11
  idSWFScriptObject *v7; // r29
  subTimingWordData_t *list; // r3
  subTimingWordData_t *v10; // r3
  idSWFScriptVar v11[8]; // [sp+50h] [-40h] BYREF

  parent = this->parent;
  if ( parent != nullptr )
  {
    v11[0].type = SWF_VAR_UNDEF;
    idSWFScriptObject::Set(this: parent->scriptObject, name: (char *)this->name.str, value: v11);
    idSWFScriptVar::Free(this: v11);
    scriptObject = this->parent->scriptObject;
    if ( scriptObject->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: scriptObject);
      idMem::Free(this: &mem, ptr: scriptObject, align: ALIGN_16);
    }
  }
  TextOrphanIndex = idSWF::FindTextOrphanIndex(this: this->swf, textInstance: this);
  if ( TextOrphanIndex != -1 )
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->swf->orphanedTexts,
      index: TextOrphanIndex);
  v6 = this->scriptObject;
  v6->objectType = SWF_OBJECT_TEXT;
  v6->data.sprite = nullptr;
  idSWFScriptObject::Clear(this: this->scriptObject);
  v7 = this->scriptObject;
  if ( v7->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v7);
    idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
  }
  if ( this->subtitleTimingInfo.listStatic == 0 || this->subtitleTimingInfo.listStatic == 2 )
  {
    list = this->subtitleTimingInfo.list;
    if ( list != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &list->phrase, num: this->subtitleTimingInfo.size);
    this->subtitleTimingInfo.list = nullptr;
    this->subtitleTimingInfo.size = 0;
  }
  this->subtitleTimingInfo.num = 0;
  if ( this->subtitleTimingInfo.listStatic == 0 || this->subtitleTimingInfo.listStatic == 2 )
  {
    v10 = this->subtitleTimingInfo.list;
    if ( v10 != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &v10->phrase, num: this->subtitleTimingInfo.size);
    this->subtitleTimingInfo.list = nullptr;
    this->subtitleTimingInfo.size = 0;
  }
  this->subtitleTimingInfo.num = 0;
  idStr::FreeData(this: &this->subSpeaker);
  idStr::FreeData(this: &this->subtitleText);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indexArray);
  idStr::FreeData(this: &this->soundClip);
  idStr::FreeData(this: &this->variable);
  idStr::FreeData(this: &this->randomtext);
  idStr::FreeData(this: &this->text);
}


// ========================================================================
// __unwind$227473
// EA  : 0x8279CB00
// RVA : 0x0079CB00
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227473()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// __unwind$227474
// EA  : 0x8279CB2C
// RVA : 0x0079CB2C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227474()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$227475
// EA  : 0x8279CB58
// RVA : 0x0079CB58
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227475()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 88));
}


// ========================================================================
// __unwind$227476
// EA  : 0x8279CB84
// RVA : 0x0079CB84
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227476()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 228));
}


// ========================================================================
// __unwind$227477
// EA  : 0x8279CBB0
// RVA : 0x0079CBB0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227477()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 264));
}


// ========================================================================
// __unwind$227478
// EA  : 0x8279CBDC
// RVA : 0x0079CBDC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227478()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 328));
}


// ========================================================================
// __unwind$227479
// EA  : 0x8279CC08
// RVA : 0x0079CC08
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227479()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 380));
}


// ========================================================================
// __unwind$227480
// EA  : 0x8279CC34
// RVA : 0x0079CC34
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227480()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 144 + 164) + 420));
}


// ========================================================================
// __unwind$227481
// EA  : 0x8279CC60
// RVA : 0x0079CC60
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_227481()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_text@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CC88
// RVA : 0x0079CC88
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text_vtbl *)1;
    *((_DWORD *)this + 1) = idSWFScriptString::Alloc(s: (const idStr *)&v4.sprite->materialOverride);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_text_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_autoSize@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CD10
// RVA : 0x0079CD10
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int v5; // r9
  bool v6; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    v5 = *(_DWORD *)(*(_DWORD *)v4.sprite + 16);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize_vtbl *)4;
    v6 = (v5 & 0x10) != 0;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = v6;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_autoSize_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_dropShadow@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CD98
// RVA : 0x0079CD98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char list_high; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    list_high = HIBYTE(v4.sprite[1].actions.list);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = list_high;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_dropShadow_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__stroke@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CE18
// RVA : 0x0079CE18
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char v5; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    v5 = BYTE1(v4.sprite[1].actions.list);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = v5;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__stroke_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__strokeStrength@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CE98
// RVA : 0x0079CE98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  double v5; // fp31

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    v5 = *(float *)&v4.sprite[1].actions.num;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = v5;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeStrength_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__strokeWeight@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CF18
// RVA : 0x0079CF18
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  double v5; // fp31

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    v5 = *(float *)&v4.sprite[1].actions.size;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = v5;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__strokeWeight_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_variable@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279CF98
// RVA : 0x0079CF98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable_vtbl *)1;
    *((_DWORD *)this + 1) = idSWFScriptString::Alloc(s: (const idStr *)&v4.sprite->onEnterFrame.value);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_variable_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__alpha@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D020
// RVA : 0x0079D020
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object,
        int a4,
        __int64 a5)
{
  idSWFScriptObject::swfObjectData_t v6; // r11
  double v7; // fp31

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v6.sprite = (idSWFSpriteInstance *)object->data, v6.sprite != nullptr) )
  {
    LODWORD(a5) = LOBYTE(v6.sprite[1].materialOverride);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)4;
    v7 = (float)((float)a5 * (float)0.0039215689);
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = v7;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__alpha_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__visible@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D0C0
// RVA : 0x0079D0C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char materialWidth_high; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    materialWidth_high = HIBYTE(v4.sprite[1].materialWidth);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = materialWidth_high;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__visible_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_selectionStart@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D140
// RVA : 0x0079D140
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  float yOffset; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    yOffset = v4.sprite[1].yOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = yOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionStart_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_selectionEnd@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D1C0
// RVA : 0x0079D1C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  idSWFScriptObject *scriptObject; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    scriptObject = v4.sprite[1].scriptObject;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = scriptObject;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_selectionEnd_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_isTooltip@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D240
// RVA : 0x0079D240
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char materialWidth; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    materialWidth = v4.sprite[1].materialWidth;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = materialWidth;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_isTooltip_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_tooltipBindset@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D2C0
// RVA : 0x0079D2C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  float xOffset; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    xOffset = v4.sprite[1].xOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = xOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_tooltipBindset_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_delay@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D340
// RVA : 0x0079D340
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int v5; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    v5 = *(_DWORD *)&v4.sprite[2].materialWidth;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = v5;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_delay_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_renderSound@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D3C0
// RVA : 0x0079D3C0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound_vtbl *)1;
    *((_DWORD *)this + 1) = idSWFScriptString::Alloc(s: (const idStr *)&v4.sprite[2].yOffset);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_renderSound_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_updateScroll@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D448
// RVA : 0x0079D448
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char xOffset_high; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    xOffset_high = HIBYTE(v4.sprite[2].xOffset);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = xOffset_high;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_updateScroll_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_mode@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D4C8
// RVA : 0x0079D4C8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  idSWFScriptVar::swfScriptVarType type; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    type = v4.sprite[1].onEnterFrame.type;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = type;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_mode_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_scroll@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D548
// RVA : 0x0079D548
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  swfDisplayEntry_t *list; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    list = v4.sprite[1].displayList.list;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = list;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_scroll_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_maxscroll@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D5C8
// RVA : 0x0079D5C8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  int size; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    size = v4.sprite[1].displayList.size;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = size;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_maxscroll_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar__textLength@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D648
// RVA : 0x0079D648
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFTextInstance *text; // r3
  double TextLength; // fp31

  if ( object != nullptr && object->objectType == SWF_OBJECT_TEXT && (text = object->data.text) != nullptr )
  {
    TextLength = idSWFTextInstance::GetTextLength(this: text, a2: (int)result, a3: (int)object, a4, a5, a6, a7);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = TextLength;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength_vtbl *)2;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar__textLength_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_textColor@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279D6D0
// RVA : 0x0079D6D0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  unsigned __int8 *sprite; // r11
  int v5; // r11
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (sprite = (unsigned __int8 *)object->data.sprite) != nullptr )
  {
    v6 = sprite[121];
    v7 = sprite[122];
    v8 = __ROL4__(sprite[120], 8);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor_vtbl *)4;
    v9 = ((v8 | v6) << 8) | v7;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 6;
    *((_DWORD *)this + 1) = v9;
  }
  else
  {
    v5 = 4;
  }
  this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_textColor_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_calcNumLines@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279D770
// RVA : 0x0079D770
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r29
  int v7; // r30
  idSWFDictionaryEntry *DictionaryEntry; // r28
  const char *followBorder; // r3
  const char *String; // r3
  __int64 v11; // r8
  idFont **p_fontID; // r9
  idFont *v13; // r26
  double v14; // fp29
  __int64 v15; // r6
  __int64 v16; // r3
  __int64 v17; // r11
  double v18; // fp28
  double v19; // fp29
  double v20; // fp27
  double v21; // fp26
  double v22; // fp25
  int v23; // r9 OVERLAPPED
  __int64 v24; // r11 OVERLAPPED
  double v25; // fp0
  double v26; // fp31
  int v27; // r27
  int v28; // r11
  int v29; // r30
  int v30; // r29
  unsigned int v31; // r28
  int v32; // r10
  int v33; // r9
  int v34; // r8
  int v35; // r7
  int v36; // r6
  int v37; // r5
  __int64 v38; // r10
  int v39; // [sp+8h] [-108h]
  int v40; // [sp+Ch] [-104h]
  int v41; // [sp+10h] [-100h]
  int v42; // [sp+14h] [-FCh]
  int v43; // [sp+18h] [-F8h]
  unsigned int v44; // [sp+1Ch] [-F4h]
  int v45; // [sp+50h] [-C0h] BYREF
  int v46; // [sp+54h] [-BCh]
  __int64 v47; // [sp+58h] [-B8h]
  idStr v48[3]; // [sp+60h] [-B0h] BYREF

  v46 = 0;
  if ( thisObject == nullptr
    || thisObject->objectType != SWF_OBJECT_TEXT
    || (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite == nullptr) )
  {
    idLib::Warning(fmt: "SWF: tried to call calcNumLines on NULL edittext");
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines_vtbl *)4;
    return this;
  }
  v7 = *(_DWORD *)&v5.sprite->isPlaying;
  if ( (*(_DWORD *)(*(_DWORD *)v5.sprite + 16) & 2) == 0 )
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_calcNumLines_vtbl *)6;
    this->refCount = 1;
    return this;
  }
  DictionaryEntry = idSWF::FindDictionaryEntry(
                      this: *(idSWF **)&v5.sprite->currentFrame,
                      characterID: *(unsigned __int16 *)(v7 + 20),
                      type: SWF_DICT_FONT);
  if ( DictionaryEntry == nullptr )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
    return this;
  }
  v48[0].len = 0;
  v48[0].baseBuffer[0] = 0;
  v48[0].allocedAndFlag = 20;
  v48[0].data = v48[0].baseBuffer;
  if ( v5.sprite->onEnterFrame.value.i != 0 )
    followBorder = (const char *)v5.sprite->followBorder;
  else
    followBorder = *(const char **)&v5.sprite->materialWidth;
  String = idLocalization::GetString(inString: followBorder);
  idStr::operator=(this: v48, text: String);
  if ( v48[0].len == 0 || *(_DWORD *)&v5.sprite->currentFrame == 0 )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
    v46 = 1;
    goto _M228462;
  }
  p_fontID = &DictionaryEntry->font->fontID;
  LODWORD(v11) = *(unsigned __int16 *)(v7 + 22);
  v47 = v11;
  v13 = *p_fontID;
  v14 = (float)((float)v11 * (float)0.050000001);
  LODWORD(v15) = idFont::GetPointSize(this: *p_fontID);
  HIDWORD(v15) = *(unsigned __int16 *)(v7 + 38);
  LODWORD(v16) = *(unsigned __int16 *)(v7 + 36);
  LODWORD(v17) = HIDWORD(v15);
  v47 = v17;
  v18 = *(float *)(v7 + 12);
  v19 = (float)((float)v14 / (float)v15);
  v20 = (float)((float)((float)v19 * (float)1.15) + *(float *)(v7 + 4));
  v21 = (float)((float)((float)v16 * (float)0.050000001) + *(float *)v7);
  v22 = (float)-(float)((float)((float)v17 * (float)0.050000001) - *(float *)(v7 + 8));
  HIDWORD(v24) = idFont::GetAscender(this: v13);
  v23 = *(unsigned __int16 *)(v7 + 42);
  v47 = *(__int64 *)((char *)&v24 + 4);
  LODWORD(v24) = (__int16)v23;
  v25 = (float)((float)((float)*(__int64 *)((char *)&v24 + 4) * (float)v19) * (float)1.15);
  if ( (_WORD)v23 != 0 )
  {
    v47 = v24;
    v25 = (float)((float)((float)((float)v24 * (float)v19) * (float)0.050000001)
                + (float)((float)((float)*(__int64 *)((char *)&v24 + 4) * (float)v19) * (float)1.15));
  }
  v26 = v21;
  LODWORD(v47) = (int)(float)((float)((float)v18 - (float)v20) / (float)v25);
  v27 = v47;
  if ( (_DWORD)v47 == 0 )
    v27 = 1;
  v28 = 0;
  v29 = 1;
  v45 = 0;
  v30 = 0;
  if ( v48[0].len <= 0 )
  {
LABEL_31:
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)v29);
    v46 = 1;
    goto _M228462;
  }
  while ( v48[0].data[v28] == 10 )
  {
    if ( v29 == v27 )
      goto LABEL_33;
    ++v28;
    v26 = v21;
    ++v29;
    v45 = v28;
    v30 = 0;
LABEL_30:
    if ( v28 >= v48[0].len )
      goto LABEL_31;
  }
  v31 = idStr::UTF8Char(s: (const unsigned __int8 *)v48[0].data, idx: &v45);
  LODWORD(v38) = idFont::GetGlyph(
                   this: v13,
                   idx: v31,
                   a3: v37,
                   a4: v36,
                   a5: v35,
                   a6: v34,
                   a7: v33,
                   a8: v32,
                   a9: v39,
                   a10: v40,
                   a11: v41,
                   a12: v42,
                   a13: v43,
                   a14: v44)->xSkip;
  v47 = v38;
  v26 = (float)((float)((float)v38 * (float)v19) + (float)v26);
  if ( v26 <= v22 )
  {
    if ( v31 == 32 || v31 == 45 )
    {
      v28 = v45;
      v30 = v45;
    }
    else
    {
      v28 = v45;
    }
    goto LABEL_30;
  }
  if ( v29 != v27 )
  {
    v28 = v30;
    v45 = v30;
    v26 = v21;
    ++v29;
    v30 = 0;
    goto LABEL_30;
  }
LABEL_33:
  idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)v27);
  v46 = 1;
_M228462:
  idStr::FreeData(this: v48);
  return this;
}


// ========================================================================
// __unwind$228322
// EA  : 0x8279DB08
// RVA : 0x0079DB08
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228322()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 272;
  if ( (*(_DWORD *)(v0 - 272 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 292));
  }
}


// ========================================================================
// __unwind$228325
// EA  : 0x8279DB4C
// RVA : 0x0079DB4C
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228325()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_onKey@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279DB80
// RVA : 0x0079DB80
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v6; // r30
  int v7; // r3
  idSWFScriptVar *list; // r11
  int v9; // r29
  int v10; // r11
  int v11; // r11
  int v12; // r10
  idSWFScriptObject *v13; // r11
  idSWFScriptObject *v14; // r11
  float yOffset; // r10
  float v16; // r10
  idSWFScriptObject *v17; // r11
  float v18; // r29
  float v19; // r27
  const idStr *v20; // r3
  idSWFScriptObject *materialOverride; // r11
  int v22; // r10
  idSWFScriptObject *scriptObject; // r10
  int granularity_high; // r10
  idSWFScriptObject *v25; // r11
  idStr v27; // [sp+60h] [-A0h] BYREF
  idStr v28; // [sp+80h] [-80h] BYREF
  idStr v29[3]; // [sp+A0h] [-60h] BYREF

  if ( thisObject != nullptr && thisObject->objectType == SWF_OBJECT_TEXT )
  {
    v6.sprite = (idSWFSpriteInstance *)thisObject->data;
    if ( v6.sprite != nullptr )
    {
      v7 = idSWFScriptVar::ToInteger(this: parms->list);
      list = parms->list;
      v9 = v7;
      if ( (unsigned __int8)idSWFScriptVar::ToBool(this: list + 1) == 0 )
      {
        if ( v9 == 42 || v9 == 54 )
          HIBYTE(v6.sprite[1].displayList.granularity) = 0;
        goto LABEL_38;
      }
      if ( v9 > 203 )
      {
        if ( v9 == 205 )
        {
          scriptObject = v6.sprite[1].scriptObject;
          if ( (int)scriptObject < (int)v6.sprite->materialOverride )
          {
            v25 = (idSWFScriptObject *)((char *)&scriptObject->refCount + 1);
            granularity_high = HIBYTE(v6.sprite[1].displayList.granularity);
            v6.sprite[1].scriptObject = v25;
            if ( granularity_high == 0 )
              LODWORD(v6.sprite[1].yOffset) = v25;
          }
          goto LABEL_38;
        }
        if ( v9 == 207 )
        {
          materialOverride = (idSWFScriptObject *)v6.sprite->materialOverride;
          v22 = HIBYTE(v6.sprite[1].displayList.granularity);
          v6.sprite[1].scriptObject = materialOverride;
          if ( v22 == 0 )
            LODWORD(v6.sprite[1].yOffset) = materialOverride;
          goto LABEL_38;
        }
        if ( v9 != 211 )
          goto LABEL_38;
      }
      else
      {
        if ( v9 == 203 )
        {
          v11 = (int)v6.sprite[1].scriptObject;
          if ( v11 > 0 )
          {
            v12 = HIBYTE(v6.sprite[1].displayList.granularity);
            v13 = (idSWFScriptObject *)(v11 - 1);
            v6.sprite[1].scriptObject = v13;
            if ( v12 == 0 )
              LODWORD(v6.sprite[1].yOffset) = v13;
          }
          goto LABEL_38;
        }
        if ( v9 > 54 )
        {
          if ( v9 == 199 )
          {
            v10 = HIBYTE(v6.sprite[1].displayList.granularity);
            v6.sprite[1].scriptObject = nullptr;
            if ( v10 == 0 )
              v6.sprite[1].yOffset = 0.0;
          }
          goto LABEL_38;
        }
        if ( v9 == 54 )
          goto LABEL_12;
        if ( v9 != 14 )
        {
          if ( v9 == 42 )
LABEL_12:
            HIBYTE(v6.sprite[1].displayList.granularity) = (_cntlzw(common->IsMultiplayer(this: common)) & 0x20) != 0;
LABEL_38:
          v6.sprite[1].name.str = (const char *)idLib::frameNumber;
          this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey_vtbl *)4;
          idSWFScriptVar::Free((idSWFScriptVar *)this);
          this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey_vtbl *)5;
          HIBYTE(this->refCount) = 1;
          return this;
        }
      }
      v14 = v6.sprite[1].scriptObject;
      yOffset = v6.sprite[1].yOffset;
      if ( (idSWFScriptObject *)LODWORD(yOffset) == v14 )
      {
        if ( v9 == 14 )
          LODWORD(v6.sprite[1].yOffset) = (char *)&v14[-1].data.text + 3;
        else
          v6.sprite[1].scriptObject = (idSWFScriptObject *)(LODWORD(yOffset) + 1);
      }
      v16 = v6.sprite[1].yOffset;
      v17 = v6.sprite[1].scriptObject;
      v18 = v16;
      if ( SLODWORD(v16) < (int)v17
        || (v18 = *(float *)&v6.sprite[1].scriptObject, v19 = v6.sprite[1].yOffset, SLODWORD(v16) <= (int)v17) )
      {
        v19 = *(float *)&v6.sprite[1].scriptObject;
      }
      idStr::Left(
        this: &v28,
        result: (idStr *)&v6.sprite->materialOverride,
        len: ((LODWORD(v18) == 0) + (LODWORD(v18) >> 31) - 1) & LODWORD(v18));
      idStr::Right(
        this: &v27,
        result: (idStr *)&v6.sprite->materialOverride,
        len: ((v6.sprite->materialOverride == (const idMaterial *)LODWORD(v19))
       + (((unsigned int)v6.sprite->materialOverride - LODWORD(v19)) >> 31)
       - 1)
      & ((unsigned int)v6.sprite->materialOverride - LODWORD(v19)));
      v20 = operator+(result: v29, a: &v28, b: &v27);
      idStr::operator=(this: (idStr *)&v6.sprite->materialOverride, text: v20);
      idStr::FreeData(this: v29);
      v6.sprite[1].yOffset = v18;
      *(float *)&v6.sprite[1].scriptObject = v18;
      idStr::FreeData(this: &v27);
      idStr::FreeData(this: &v28);
      goto LABEL_38;
    }
  }
  idLib::Warning(fmt: "SWF: tried to call onKey on NULL edittext");
  this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onKey_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$228492_0
// EA  : 0x8279DE20
// RVA : 0x0079DE20
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228492_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$228493_0
// EA  : 0x8279DE48
// RVA : 0x0079DE48
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228493_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$228494_0
// EA  : 0x8279DE70
// RVA : 0x0079DE70
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228494_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// ?Call@idSWFScriptFunction_onChar@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279DEA0
// RVA : 0x0079DEA0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r29
  int v6; // r3
  char v7; // r26
  idSWFScriptObject *scriptObject; // r11
  float yOffset; // r10
  float v10; // r28
  float v11; // r27
  const idStr *v12; // r3
  int yOffset_low; // r5
  bool v14; // r4
  idStr v16; // [sp+60h] [-A0h] BYREF
  idStr v17; // [sp+80h] [-80h] BYREF
  idStr v18[3]; // [sp+A0h] [-60h] BYREF

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    if ( (v6 < 32 || v6 > 126) && v6 != 13 || (v7 = v6, (char)v6 == 96) || (char)v6 == 126 )
    {
      v14 = false;
    }
    else
    {
      scriptObject = v5.sprite[1].scriptObject;
      yOffset = v5.sprite[1].yOffset;
      if ( (idSWFScriptObject *)LODWORD(yOffset) == scriptObject )
      {
        if ( !common->IsMultiplayer(this: common)
          || SLODWORD(v5.sprite[1].yOffset) < swf_textMaxInputLength.valueInteger )
        {
          if ( v5.sprite[1].yOffset < 0.0 )
            v5.sprite[1].yOffset = 0.0;
          yOffset_low = LODWORD(v5.sprite[1].yOffset);
          LODWORD(v5.sprite[1].yOffset) = yOffset_low + 1;
          idStr::Insert(this: (idStr *)&v5.sprite->materialOverride, a: v7, index: yOffset_low);
        }
      }
      else
      {
        v10 = v5.sprite[1].yOffset;
        if ( SLODWORD(yOffset) >= (int)scriptObject )
          v10 = *(float *)&v5.sprite[1].scriptObject;
        v11 = v5.sprite[1].yOffset;
        if ( SLODWORD(yOffset) <= (int)scriptObject )
          v11 = *(float *)&v5.sprite[1].scriptObject;
        idStr::Left(
          this: &v17,
          result: (idStr *)&v5.sprite->materialOverride,
          len: ((LODWORD(v10) == 0) + (LODWORD(v10) >> 31) - 1) & LODWORD(v10));
        idStr::Right(
          this: &v16,
          result: (idStr *)&v5.sprite->materialOverride,
          len: ((v5.sprite->materialOverride == (const idMaterial *)LODWORD(v11))
         + (((unsigned int)v5.sprite->materialOverride - LODWORD(v11)) >> 31)
         - 1)
        & ((unsigned int)v5.sprite->materialOverride - LODWORD(v11)));
        v12 = operator+(result: v18, a: &v17, b: &v16);
        idStr::operator=(this: (idStr *)&v5.sprite->materialOverride, text: v12);
        idStr::FreeData(this: v18);
        v5.sprite[1].yOffset = v10;
        idStr::Clear(this: (idStr *)&v5.sprite->materialOverride);
        idStr::Append(this: (idStr *)&v5.sprite->materialOverride, text: &v17);
        idStr::Append(this: (idStr *)&v5.sprite->materialOverride, a: v7);
        idStr::Append(this: (idStr *)&v5.sprite->materialOverride, text: &v16);
        ++LODWORD(v5.sprite[1].yOffset);
        idStr::FreeData(this: &v16);
        idStr::FreeData(this: &v17);
      }
      v14 = true;
      v5.sprite[1].scriptObject = (idSWFScriptObject *)LODWORD(v5.sprite[1].yOffset);
      v5.sprite[1].name.str = (const char *)idLib::frameNumber;
    }
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, b: v14);
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call onChar on NULL edittext");
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_onChar_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$228613
// EA  : 0x8279E0A8
// RVA : 0x0079E0A8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228613()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$228614_0
// EA  : 0x8279E0D0
// RVA : 0x0079E0D0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228614_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$228615_0
// EA  : 0x8279E0F8
// RVA : 0x0079E0F8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228615_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_subtitle@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279E120
// RVA : 0x0079E120
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  char followBorder_high; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    followBorder_high = HIBYTE(v4.sprite[2].followBorder);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_BYTE *)this + 4) = followBorder_high;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle_vtbl *)5;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitle_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_subtitleAlign@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279E1A0
// RVA : 0x0079E1A0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  idSWFSprite *sprite; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    sprite = v4.sprite[3].sprite;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((_DWORD *)this + 1) = sprite;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleAlign_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_subtitleSourceID@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279E220
// RVA : 0x0079E220
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11
  float yOffset; // r30

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    yOffset = v4.sprite[3].yOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    *((float *)this + 1) = yOffset;
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID_vtbl *)6;
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSourceID_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Get@idSWFScriptNativeVar_subtitleSpeaker@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@@Z
// EA  : 0x8279E2A0
// RVA : 0x0079E2A0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker::Get(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker *this,
        idSWFScriptVar *result,
        idSWFScriptObject *object)
{
  idSWFScriptObject::swfObjectData_t v4; // r11

  if ( object != nullptr
    && object->objectType == SWF_OBJECT_TEXT
    && (v4.sprite = (idSWFSpriteInstance *)object->data, v4.sprite != nullptr) )
  {
    idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: *(const char **)&v4.sprite[4].isPlaying);
  }
  else
  {
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptNativeVar_subtitleSpeaker_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_subtitleSourceCheck@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279E308
// RVA : 0x0079E308
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFTextInstance *text; // r30
  int v7; // r3
  int subSourceID; // r11
  int v9; // r29

  if ( thisObject != nullptr && thisObject->objectType == SWF_OBJECT_TEXT && (text = thisObject->data.text) != nullptr )
  {
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    subSourceID = text->subSourceID;
    v9 = v7;
    if ( subSourceID == -1 )
    {
      text->subSourceID = v7;
      this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck_vtbl *)6;
      this->refCount = 1;
      return this;
    }
    else
    {
      if ( v7 == subSourceID )
      {
        idSWFTextInstance::SubtitleComplete(this: text);
        text->subSourceID = v9;
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: (idSWFScriptVar::swfScriptVarValue_t *)0xFFFFFFFF);
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, i: nullptr);
      }
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call subtitleSourceCheck on NULL edittext");
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subtitleSourceCheck_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_subLastLine@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279E3F0
// RVA : 0x0079E3F0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject::swfObjectData_t v5; // r11
  idStr v7[2]; // [sp+60h] [-40h] BYREF

  if ( thisObject != nullptr
    && thisObject->objectType == SWF_OBJECT_TEXT
    && (v5.sprite = (idSWFSpriteInstance *)thisObject->data, v5.sprite != nullptr) )
  {
    v7[0].len = 0;
    v7[0].baseBuffer[0] = 0;
    v7[0].allocedAndFlag = 20;
    v7[0].data = v7[0].baseBuffer;
    idStr::CopyRange(
      this: v7,
      text: *(const char **)&v5.sprite->materialWidth,
      start: v5.sprite[3].depth,
      end: (int)v5.sprite[3].materialOverride);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine_vtbl *)1;
    this->refCount = (int)idSWFScriptString::Alloc(s: v7);
    idStr::FreeData(this: v7);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call subLastLine on NULL edittext");
    this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_subLastLine_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$228873
// EA  : 0x8279E4B4
// RVA : 0x0079E4B4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228873()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 180));
  }
}


// ========================================================================
// __unwind$228876
// EA  : 0x8279E4F8
// RVA : 0x0079E4F8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228876()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_addSubtitleInfo@idSWFScriptObject_TextInstancePrototype@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x8279E528
// RVA : 0x0079E528
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo *__fastcall idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo::Call(
        idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo *v5; // r27
  idSWFScriptVar **v6; // r28
  int v7; // r26
  idSWFScriptVar *v8; // r25
  size_t type; // r30
  idStr v11; // [sp+60h] [-90h] BYREF
  subTimingWordData_t v12[2]; // [sp+80h] [-70h] BYREF

  v5 = this;
  v6 = (idSWFScriptVar **)parms;
  if ( HIDWORD(parms) != 0 && *(_DWORD *)(HIDWORD(parms) + 88) == 3 && (v7 = *(_DWORD *)(HIDWORD(parms) + 92)) != 0 )
  {
    if ( *(_DWORD *)(parms + 4) == 3 )
    {
      v12[0].phrase.len = 0;
      LODWORD(a5) = v12[0].phrase.baseBuffer;
      v12[0].phrase.baseBuffer[0] = 0;
      v12[0].phrase.allocedAndFlag = 20;
      v12[0].phrase.data = v12[0].phrase.baseBuffer;
      v12[0].startTime = 0;
      v12[0].forceBreak = false;
      v8 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v11, result: *(idStr **)parms, a3: parms, a4, a5);
      type = v8->type;
      idStr::EnsureAlloced(this: &v12[0].phrase, amount: v8->type + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v12[0].phrase.data, Src: v8->value.object, Size: type);
      v12[0].phrase.data[type] = 0;
      v12[0].phrase.len = type;
      idStr::FreeData(this: &v11);
      v12[0].startTime = idSWFScriptVar::ToInteger(this: *v6 + 1);
      v12[0].forceBreak = idSWFScriptVar::ToBool(this: *v6 + 2);
      idList<subTimingWordData_t,72>::Append(this: (idList<subTimingWordData_t,72> *)(v7 + 420), obj: v12);
      v5->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo_vtbl *)4;
      idStr::FreeData(this: &v12[0].phrase);
      return v5;
    }
    else
    {
      this->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo_vtbl *)4;
    }
  }
  else
  {
    idLib::Warning(fmt: "SWF: tried to call addSubtitleInfo on NULL edittext");
    v5->__vftable = (idSWFScriptObject_TextInstancePrototype::idSWFScriptFunction_addSubtitleInfo_vtbl *)4;
    return v5;
  }
  return this;
}


// ========================================================================
// __unwind$228953
// EA  : 0x8279E660
// RVA : 0x0079E660
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228953()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 240;
  if ( (*(_DWORD *)(v0 - 240 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 260));
  }
}


// ========================================================================
// __unwind$228956
// EA  : 0x8279E6A4
// RVA : 0x0079E6A4
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228956()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$228957
// EA  : 0x8279E6CC
// RVA : 0x0079E6CC
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void _unwind_228957()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// `dynamic initializer for 'textInstanceScriptObjectPrototype''
// EA  : 0x83341DB0
// RVA : 0x01341DB0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__textInstanceScriptObjectPrototype__()
{
  idSWFScriptObject_TextInstancePrototype::idSWFScriptObject_TextInstancePrototype(this: &textInstanceScriptObjectPrototype);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__textInstanceScriptObjectPrototype__);
}


// ========================================================================
// `dynamic initializer for 'swf_textScrollSpeed''
// EA  : 0x83341DE8
// RVA : 0x01341DE8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textScrollSpeed__()
{
  idCVar::idCVar(
    this: &swf_textScrollSpeed,
    name: "swf_textScrollSpeed",
    value: "80",
    flags: 2,
    description: "scroll speed for text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textScrollSpeed__);
}


// ========================================================================
// `dynamic initializer for 'swf_textRndLetterSpeed''
// EA  : 0x83341E40
// RVA : 0x01341E40
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textRndLetterSpeed__()
{
  idCVar::idCVar(
    this: &swf_textRndLetterSpeed,
    name: "swf_textRndLetterSpeed",
    value: "8",
    flags: 2,
    description: "scroll speed for text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textRndLetterSpeed__);
}


// ========================================================================
// `dynamic initializer for 'swf_textRndLetterDelay''
// EA  : 0x83341E98
// RVA : 0x01341E98
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textRndLetterDelay__()
{
  idCVar::idCVar(
    this: &swf_textRndLetterDelay,
    name: "swf_textRndLetterDelay",
    value: "100",
    flags: 2,
    description: "scroll speed for text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textRndLetterDelay__);
}


// ========================================================================
// `dynamic initializer for 'swf_textParagraphSpeed''
// EA  : 0x83341EF0
// RVA : 0x01341EF0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textParagraphSpeed__()
{
  idCVar::idCVar(
    this: &swf_textParagraphSpeed,
    name: "swf_textParagraphSpeed",
    value: "15",
    flags: 2,
    description: "scroll speed for text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textParagraphSpeed__);
}


// ========================================================================
// `dynamic initializer for 'swf_textParagraphInc''
// EA  : 0x83341F48
// RVA : 0x01341F48
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textParagraphInc__()
{
  idCVar::idCVar(
    this: &swf_textParagraphInc,
    name: "swf_textParagraphInc",
    value: "1.3",
    flags: 4,
    description: "scroll speed for text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textParagraphInc__);
}


// ========================================================================
// `dynamic initializer for 'swf_subtitleExtraTime''
// EA  : 0x83341FA0
// RVA : 0x01341FA0
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_subtitleExtraTime__()
{
  idCVar::idCVar(
    this: &swf_subtitleExtraTime,
    name: "swf_subtitleExtraTime",
    value: "3500",
    flags: 2,
    description: "time after subtitles vo is complete",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_subtitleExtraTime__);
}


// ========================================================================
// `dynamic initializer for 'swf_subtitleEarlyTrans''
// EA  : 0x83341FF8
// RVA : 0x01341FF8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_subtitleEarlyTrans__()
{
  idCVar::idCVar(
    this: &swf_subtitleEarlyTrans,
    name: "swf_subtitleEarlyTrans",
    value: "3500",
    flags: 2,
    description: "early time out to switch the line",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_subtitleEarlyTrans__);
}


// ========================================================================
// `dynamic initializer for 'swf_subtitleLengthGuess''
// EA  : 0x83342050
// RVA : 0x01342050
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_subtitleLengthGuess__()
{
  idCVar::idCVar(
    this: &swf_subtitleLengthGuess,
    name: "swf_subtitleLengthGuess",
    value: "10000",
    flags: 2,
    description: "early time out to switch the line",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_subtitleLengthGuess__);
}


// ========================================================================
// `dynamic initializer for 'swf_textMaxInputLength''
// EA  : 0x833420A8
// RVA : 0x013420A8
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textMaxInputLength__()
{
  idCVar::idCVar(
    this: &swf_textMaxInputLength,
    name: "swf_textMaxInputLength",
    value: "104",
    flags: 2,
    description: "max number of characters that can go into the input line",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textMaxInputLength__);
}


// ========================================================================
// `dynamic initializer for 'swf_textStrokeSize''
// EA  : 0x83342100
// RVA : 0x01342100
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textStrokeSize__()
{
  idCVar::idCVar(
    this: &swf_textStrokeSize,
    name: "swf_textStrokeSize",
    value: "1.65f",
    flags: 4,
    description: "size of font glyph stroke",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_82200000,
    a9: (int)&unk_82200000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textStrokeSize__);
}


// ========================================================================
// `dynamic initializer for 'swf_textStrokeSizeGlyphSpacer''
// EA  : 0x83342168
// RVA : 0x01342168
// PDB : w:\tech5\engine\guis\swf\swf_textinstance.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_textStrokeSizeGlyphSpacer__()
{
  idCVar::idCVar(
    this: &swf_textStrokeSizeGlyphSpacer,
    name: "swf_textStrokeSizeGlyphSpacer",
    value: "1.5f",
    flags: 4,
    description: "additional space for spacing glyphs using stroke",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_textStrokeSizeGlyphSpacer__);
}

