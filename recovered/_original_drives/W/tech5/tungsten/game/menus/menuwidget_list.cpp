
// ========================================================================
// ?HandleAction@idMenuWidget_List@@UAA_NAAVidWidgetAction@@ABVidWidgetEvent@@@Z
// EA  : 0x82DDE450
// RVA : 0x00DDE450
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

int __fastcall idMenuWidget_List::HandleAction(
        idMenuWidget_List *this,
        idWidgetAction *action,
        const idWidgetEvent *event)
{
  int arg; // r11
  idMenuWidget_List_vtbl *v5; // r30
  int v6; // r3
  idMenuWidget_List_vtbl *v8; // r30
  int numVisibleOptions; // r29
  int v10; // r4

  if ( action->action == WIDGET_ACTION_SCROLL_VERTICAL )
  {
    arg = event->arg;
    switch ( arg )
    {
      case 0:
        v5 = this->__vftable;
        v6 = idSWFScriptVar::ToInteger(this: action->parms.list);
        v5->Scroll(this, a2: v6);
        return 1;
      case 1:
        v8 = this->__vftable;
        numVisibleOptions = this->numVisibleOptions;
        v10 = idSWFScriptVar::ToInteger(this: action->parms.list) * (numVisibleOptions - 1);
        break;
      case 2:
        v8 = this->__vftable;
        v10 = 999 * idSWFScriptVar::ToInteger(this: action->parms.list);
        break;
      default:
        return 1;
    }
    v8->ScrollOffset(this, a2: v10);
    return 1;
  }
  return idMenuWidget::HandleAction(this, action, event);
}


// ========================================================================
// ?Scroll@idMenuWidget_List@@UAAXH@Z
// EA  : 0x82DDE510
// RVA : 0x00DDE510
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

void __fastcall idMenuWidget_List::Scroll(idMenuWidget_List *this, const int scrollAmount)
{
  bool allowWrapping; // r28
  int numVisibleOptions; // r27
  int viewOffset; // r26
  int v7; // r3
  int v8; // r30
  int v9; // r29

  allowWrapping = this->allowWrapping;
  numVisibleOptions = this->numVisibleOptions;
  viewOffset = this->viewOffset;
  v8 = this->viewIndex + scrollAmount;
  v7 = this->GetTotalNumberOfOptions(this);
  if ( scrollAmount <= 0 )
  {
    if ( v8 < 0 )
    {
      v8 = v7 - 1;
      if ( !allowWrapping )
        v8 = 0;
    }
  }
  else if ( v8 > v7 - 1 )
  {
    v8 = allowWrapping ? 0 : v7 - 1;
  }
  if ( v8 - viewOffset < numVisibleOptions )
  {
    v9 = v8;
    if ( viewOffset <= v8 )
      v9 = viewOffset;
  }
  else
  {
    v9 = v8 - numVisibleOptions + 1;
  }
  if ( v9 != this->viewOffset )
  {
    this->viewOffset = v9;
    this->Update(this);
  }
  if ( v8 != this->viewIndex )
  {
    this->viewIndex = v8;
    idMenuWidget::SetFocusIndex(this, index: v8 - v9);
  }
}


// ========================================================================
// ?ScrollOffset@idMenuWidget_List@@UAAXH@Z
// EA  : 0x82DDE600
// RVA : 0x00DDE600
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

void __fastcall idMenuWidget_List::ScrollOffset(idMenuWidget_List *this, const int scrollAmount)
{
  int numVisibleOptions; // r30
  int viewIndex; // r28
  int v6; // r3
  unsigned int v7; // r7
  int v8; // r11
  int v9; // r29
  int v10; // r30

  numVisibleOptions = this->numVisibleOptions;
  viewIndex = this->viewIndex;
  v6 = this->GetTotalNumberOfOptions(this);
  v7 = (viewIndex + scrollAmount == 0) + ((unsigned int)(viewIndex + scrollAmount) >> 31) - 1;
  v8 = v7 & (viewIndex + scrollAmount);
  if ( v8 < v6 )
  {
    if ( v8 < v6 - numVisibleOptions )
      v10 = v7 & (viewIndex + scrollAmount);
    else
      v10 = ((v6 == numVisibleOptions) + ((unsigned int)(v6 - numVisibleOptions) >> 31) - 1) & (v6 - numVisibleOptions);
    v9 = v7 & (viewIndex + scrollAmount);
  }
  else
  {
    v9 = v6 - 1;
    v10 = ((v6 == numVisibleOptions) + ((unsigned int)(v6 - numVisibleOptions) >> 31) - 1) & (v6 - numVisibleOptions);
  }
  if ( v10 != this->viewOffset )
  {
    this->viewOffset = v10;
    this->Update(this);
  }
  if ( v9 != this->viewIndex )
  {
    this->viewIndex = v9;
    idMenuWidget::SetFocusIndex(this, index: v9 - v10);
  }
}


// ========================================================================
// ?Update@idMenuWidget_List@@UAAXXZ
// EA  : 0x82DDE6D8
// RVA : 0x00DDE6D8
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

void __fastcall idMenuWidget_List::Update(idMenuWidget_List *this)
{
  idSWFScriptObject *scriptObject; // r23
  int v3; // r28
  int v4; // r24
  char v5; // r27
  int v6; // r26
  int numVisibleOptions; // r29
  idMenuWidget *v8; // r30
  int v9; // r11
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  va *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  va *v17; // r3
  idSWFSpriteInstance *Sprite; // r3
  idSWFSpriteInstance *v19; // r3
  idSWFSpriteInstance *v20; // r29
  idMenuWidget_List *v21; // r3
  int viewOffset; // r30
  int v23; // r31
  int (__fastcall *GetTotalNumberOfOptions)(idMenuWidget_List *); // ctr
  unsigned int v25; // r3
  int v26; // [sp+8h] [-1098h]
  int v27; // [sp+Ch] [-1094h]
  int v28; // [sp+10h] [-1090h]
  int v29; // [sp+14h] [-108Ch]
  int v30; // [sp+18h] [-1088h]
  int v31; // [sp+1Ch] [-1084h]
  va v32; // [sp+50h] [-1050h] BYREF

  scriptObject = gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject;
  if ( idMenuWidget::BindSprite(this, root: scriptObject) )
  {
    v3 = 0;
    if ( this->numVisibleOptions > 0 )
    {
      v4 = 0;
      do
      {
        v5 = 0;
        v6 = this->viewOffset + v3;
        if ( v3 < this->children.num )
        {
          numVisibleOptions = this->numVisibleOptions;
          v8 = this->children.list[v4];
          v9 = this->GetTotalNumberOfOptions(this);
          if ( numVisibleOptions < v9 )
            v9 = numVisibleOptions;
          HIDWORD(v12) = numVisibleOptions - v9 + v3;
          v13 = va::va(
                  this: &v32,
                  fmt: "option%d",
                  a3: v12,
                  a4: v11,
                  a5: v10,
                  a6: v26,
                  a7: v27,
                  a8: v28,
                  a9: v29,
                  a10: v30,
                  a11: v31);
          idMenuWidget::SetSpritePath(
            this: v8,
            spritePath_: &this->spritePath,
            arg1: v13->buffer,
            arg2: nullptr,
            arg3: nullptr,
            arg4: nullptr);
          if ( idMenuWidget::BindSprite(this: v8, root: scriptObject) )
          {
            this->PrepareListElement(this, a2: v8, a3: v6);
            v8->Update(this: v8);
            v5 = 1;
          }
        }
        if ( v5 == 0 )
        {
          HIDWORD(v14) = v3 - this->GetTotalNumberOfOptions(this);
          v17 = va::va(
                  this: &v32,
                  fmt: "option%d",
                  a3: v14,
                  a4: v16,
                  a5: v15,
                  a6: v26,
                  a7: v27,
                  a8: v28,
                  a9: v29,
                  a10: v30,
                  a11: v31);
          Sprite = idSWFScriptObject::GetSprite(this: this->boundSprite->scriptObject, name: v17->buffer);
          if ( Sprite != nullptr )
            idSWFSpriteInstance::SetVisible(this: Sprite, visible: false);
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->numVisibleOptions );
    }
    v19 = idSWFScriptObject::GetSprite(this: this->boundSprite->scriptObject, name: "upIndicator");
    if ( v19 != nullptr )
      idSWFSpriteInstance::SetVisible(this: v19, visible: (-this->viewOffset & ~this->viewOffset) < 0);
    v20 = idSWFScriptObject::GetSprite(this: this->boundSprite->scriptObject, name: "downIndicator");
    if ( v20 != nullptr )
    {
      v21 = this;
      viewOffset = this->viewOffset;
      GetTotalNumberOfOptions = this->GetTotalNumberOfOptions;
      v23 = this->numVisibleOptions;
      v25 = GetTotalNumberOfOptions(this: v21);
      idSWFSpriteInstance::SetVisible(
        this: v20,
        visible: ((((v25 ^ (v23 + viewOffset)) & 0x80000000) == 0) + (v23 + viewOffset >= v25)) & 1);
    }
  }
}


// ========================================================================
// ?PrepareListElement@idMenuWidget_DevList@@UAA_NAAVidMenuWidget@@H@Z
// EA  : 0x82DDE908
// RVA : 0x00DDE908
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

int __fastcall idMenuWidget_DevList::PrepareListElement(
        idMenuWidget_DevList *this,
        idMenuWidget *widget,
        int childIndex)
{
  int result; // r3
  int v6; // r28
  int v7; // r30
  idDeclDevMenuList::idDevMenuOption *v8; // r11
  const char *data; // r4
  idStr v10[2]; // [sp+50h] [-50h] BYREF

  result = (int)_RTDynamicCast(
                  inptr: widget,
                  VfDelta: 0,
                  SrcType: &idMenuWidget `RTTI Type Descriptor',
                  TargetType: &idMenuWidget_Button `RTTI Type Descriptor',
                  isReference: 0);
  v6 = result;
  if ( result != 0 )
  {
    v7 = childIndex;
    idStr::idStr(this: v10, text: &this->devMenuList->devMenuList.list[v7].devMenuDisplayName);
    v8 = &this->devMenuList->devMenuList.list[v7];
    if ( v8->devMenuSubList != nullptr )
    {
      idStr::Append(this: v10, text: " >");
      data = &byte_8200D768;
    }
    else
    {
      data = v8->devMenuMapName.data;
    }
    idStr::operator=(this: (idStr *)(v6 + 212), text: data);
    idStr::operator=(this: (idStr *)(v6 + 180), text: v10[0].data);
    idStr::FreeData(this: v10);
    return 1;
  }
  return result;
}


// ========================================================================
// __unwind$487792
// EA  : 0x82DDE9C4
// RVA : 0x00DDE9C4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_list.cpp
// ========================================================================

void _unwind_487792()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}

