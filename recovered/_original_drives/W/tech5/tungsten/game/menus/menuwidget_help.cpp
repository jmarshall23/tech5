
// ========================================================================
// ?ObserveEvent@idMenuWidget_Help@@UAAXABVidMenuWidget@@ABVidWidgetEvent@@@Z
// EA  : 0x82DDE188
// RVA : 0x00DDE188
// PDB : w:\tech5\tungsten\game\menus\menuwidget_help.cpp
// ========================================================================

void __fastcall idMenuWidget_Help::ObserveEvent(
        idMenuWidget_Help *this,
        idMenuWidget *widget,
        const idWidgetEvent *event)
{
  char *v5; // r3
  const void **v6; // r28
  widgetEvent_t type; // r11
  size_t v8; // r29

  v5 = (char *)_RTDynamicCast(
                 inptr: widget,
                 VfDelta: 0,
                 SrcType: &idMenuWidget `RTTI Type Descriptor',
                 TargetType: &idMenuWidget_Button `RTTI Type Descriptor',
                 isReference: 0);
  v6 = (const void **)v5;
  if ( v5 != nullptr )
  {
    type = event->type;
    if ( event->type == WIDGET_EVENT_ROLL_OVER )
    {
      v8 = *((_DWORD *)v5 + 53);
      idStr::EnsureAlloced(this: &this->lastHoveredMessage, amount: v8 + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->lastHoveredMessage.data, Src: v6[54], Size: v8);
      this->lastHoveredMessage.data[v8] = 0;
      this->lastHoveredMessage.len = v8;
      this->Update(this);
    }
    else if ( type == WIDGET_EVENT_ROLL_OUT )
    {
      idStr::Clear(this: &this->lastHoveredMessage);
      this->Update(this);
    }
    else if ( type == WIDGET_EVENT_FOCUS_ON )
    {
      idStr::operator=(this: &this->lastFocusedMessage, text: (const idStr *)(v5 + 212));
      this->Update(this);
    }
  }
}


// ========================================================================
// ?Update@idMenuWidget_Help@@UAAXXZ
// EA  : 0x82DDE288
// RVA : 0x00DDE288
// PDB : w:\tech5\tungsten\game\menus\menuwidget_help.cpp
// ========================================================================

void __fastcall idMenuWidget_Help::Update(idMenuWidget_Help *this)
{
  idStr *p_lastHoveredMessage; // r28
  idSWFSpriteInstance *v3; // r3
  int v4; // r30
  idSWFSpriteInstance *v5; // r3
  idSWFScriptObject *NestedObj; // r3
  idSWFTextInstance *text; // r31
  idStr *v8; // r3
  idSWFSpriteInstance *boundSprite; // r11
  int currentFrame; // r29
  idStr v11[2]; // [sp+50h] [-50h] BYREF

  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
  {
    p_lastHoveredMessage = &this->lastHoveredMessage;
    if ( this->lastHoveredMessage.len <= 0 )
      p_lastHoveredMessage = &this->lastFocusedMessage;
    if ( p_lastHoveredMessage->len <= 0 )
    {
      boundSprite = this->boundSprite;
      if ( boundSprite->currentFrame != 1 )
      {
        currentFrame = boundSprite->currentFrame;
        if ( currentFrame != idSWFSpriteInstance::FindFrame(this: boundSprite, labelName: "hidden")
          && (unsigned __int8)idSWFSpriteInstance::IsBetweenFrames(
                                this: this->boundSprite,
                                frameLabel1: "hide",
                                frameLabel2: "hidden") == 0 )
        {
          idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: "hide");
        }
      }
    }
    else
    {
      v3 = this->boundSprite;
      v4 = v3->currentFrame;
      if ( v4 != idSWFSpriteInstance::FindFrame(this: v3, labelName: "shown") )
      {
        v5 = this->boundSprite;
        if ( v5->currentFrame == 1
          || !v5->isPlaying
          || (unsigned __int8)idSWFSpriteInstance::IsBetweenFrames(this: v5, frameLabel1: "show", frameLabel2: "shown") == 0 )
        {
          idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: "show");
        }
      }
      NestedObj = idSWFScriptObject::GetNestedObj(
                    this: this->boundSprite->scriptObject,
                    arg1: "txtOption",
                    arg2: "txtValue",
                    arg3: nullptr,
                    arg4: nullptr,
                    arg5: nullptr,
                    arg6: nullptr);
      if ( NestedObj != nullptr )
      {
        if ( NestedObj->objectType == SWF_OBJECT_TEXT )
          text = NestedObj->data.text;
        else
          text = nullptr;
        v8 = idStr::idStr(this: v11, text: p_lastHoveredMessage);
        idSWFTextInstance::SetText(this: text, val: v8);
        idSWFTextInstance::SetStrokeInfo(this: text, use: true, strength: 0.75, weight: 2.0);
      }
    }
  }
}

