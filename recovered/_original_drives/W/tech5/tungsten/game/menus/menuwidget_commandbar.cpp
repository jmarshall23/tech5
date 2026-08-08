
// ========================================================================
// ?ExecuteEvent@idMenuWidget_CommandBar@@UAA_NABVidWidgetEvent@@@Z
// EA  : 0x82DDD020
// RVA : 0x00DDD020
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

int __fastcall idMenuWidget_CommandBar::ExecuteEvent(idMenuWidget_CommandBar *this, const idWidgetEvent *event)
{
  int arg; // r11
  char v3; // r10

  if ( event->type != WIDGET_EVENT_COMMAND )
    return idMenuWidget::ExecuteEvent(this, event);
  arg = event->arg;
  if ( arg < 0 || (v3 = 1, arg >= this->buttons.num) )
    v3 = 0;
  if ( v3 != 0 )
    this->HandleAction(this, a2: &this->buttons.list[arg].action, a3: event);
  return 1;
}


// ========================================================================
// ?Update@idMenuWidget_CommandBar@@UAAXXZ
// EA  : 0x82DDD0B8
// RVA : 0x00DDD0B8
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void __fastcall idMenuWidget_CommandBar::Update(idMenuWidget_CommandBar *this)
{
  idMenuWidget_CommandBar::alignment_t alignment; // r11
  int v3; // r24
  int v4; // r30
  int num; // r11
  idMD6Filter **v6; // r11
  int v7; // r29
  char *v8; // r28
  idSWFSpriteInstance *Sprite; // r3
  idSWFSpriteInstance *v10; // r30
  idSWFTextInstance *Text; // r27
  idSWFSpriteInstance *v12; // r25
  idSWFScriptObject *timestamp; // r29
  idSWFScriptFunction *v14; // r3
  idSWFScriptFunction *v15; // r4
  idSWFScriptVar *v16; // r3
  __int64 v17; // r10
  double v18; // fp30
  idStr *v19; // r3
  __int64 v20; // r10
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // r4
  double TextLength; // fp1
  __int64 v27; // r8
  int v28; // [sp+58h] [-178h]
  idList<idMD6Filter *,5> v29; // [sp+60h] [-170h] BYREF
  int v30; // [sp+70h] [-160h] BYREF
  char *v31; // [sp+84h] [-14Ch]
  int v32; // [sp+88h] [-148h]
  idEventDef **v33; // [sp+8Ch] [-144h]
  idSWFScriptVar v34; // [sp+90h] [-140h] BYREF
  idSWFScriptVar v35; // [sp+98h] [-138h] BYREF
  idSWFScriptVar v36; // [sp+A0h] [-130h] BYREF
  idSWFScriptVar v37; // [sp+A8h] [-128h] BYREF
  idSWFScriptVar v38[2]; // [sp+B0h] [-120h] BYREF
  idStr v39; // [sp+C0h] [-110h] BYREF
  __int64 v40; // [sp+E0h] [-F0h]
  __int64 v41; // [sp+E8h] [-E8h]
  idSWFScriptVar v42[2]; // [sp+F0h] [-E0h] BYREF
  idStr v43; // [sp+100h] [-D0h] BYREF

  v33 = &idEventDef::eventDefList[3154];
  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
  {
    alignment = this->alignment;
    v29.size = 5;
    v29.granularity = 1;
    v29.memTag = 5;
    v3 = 0;
    v29.list = (idMD6Filter **)&v30;
    v29.listStatic = 1;
    v29.num = 0;
    v32 = alignment == LEFT ? 1 : -1;
    v28 = 35 * v32;
    v4 = 0;
    do
    {
      idList<idMD6Node *,5>::PreAllocateWithGranularity(this: &v29, newSize: v29.num + 1);
      num = v29.num;
      if ( v29.num >= v29.size )
      {
        v6 = &v29.list[v29.size - 1];
      }
      else
      {
        ++v29.num;
        v6 = &v29.list[num];
      }
      *v6 = (idMD6Filter *)v4++;
    }
    while ( v4 < v29.size );
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)gameLocal->mainMenu->mainMenu) != 0 )
    {
      *((_DWORD *)v29.list + 1) = 0;
      *v29.list = (idMD6Filter *)1;
    }
    idSWFSpriteInstance::SetVisible(this: this->boundSprite, visible: true);
    v39.len = 0;
    v39.allocedAndFlag = 20;
    v39.data = v39.baseBuffer;
    v39.baseBuffer[0] = 0;
    if ( v29.num > 0 )
    {
      v7 = 0;
      v31 = "txt_info";
      do
      {
        v8 = (char *)BUTTON_NAMES[(int)v29.list[v7]];
        Sprite = idSWFScriptObject::GetSprite(this: this->boundSprite->scriptObject, name: v8);
        v10 = Sprite;
        if ( Sprite == nullptr )
          goto LABEL_26;
        Text = idSWFScriptObject::GetText(this: Sprite->scriptObject, name: v31);
        if ( Text == nullptr )
          goto LABEL_26;
        v12 = idSWFScriptObject::GetSprite(this: v10->scriptObject, name: "img");
        if ( v12 == nullptr )
          goto LABEL_26;
        if ( this->buttons.list[v3].label.len == 0 )
        {
          idSWFSpriteInstance::SetVisible(this: v10, visible: false);
          goto LABEL_26;
        }
        timestamp = (idSWFScriptObject *)idSWF::GetGlobal(
                                           this: (idSWF *)v42,
                                           result: *(idSWFScriptVar **)(*(_DWORD *)&v33[5128][31624].canSkip + 668),
                                           name: "shortcutKeys")->timestamp;
        idSWFScriptVar::Free(this: v42);
        if ( timestamp != nullptr )
        {
          v14 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x14u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v14 != nullptr )
          {
            v14[2].__vftable = (idSWFScriptFunction_vtbl *)this;
            v14[4].__vftable = (idSWFScriptFunction_vtbl *)v3;
            v14[1].__vftable = nullptr;
            v15 = v14;
            v14->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
            v14[3].__vftable = (idSWFScriptFunction_vtbl *)17;
          }
          else
          {
            v15 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: &v37, nf: v15);
          idSWFScriptObject::Set(this: v10->scriptObject, name: "onPress", value: &v37);
          idSWFScriptVar::Free(this: &v37);
          idStr::operator=(this: &v39, text: v8);
          idStr::ToUpper(this: &v39);
          idSWFScriptVar::idSWFScriptVar(this: &v36, o: v10->scriptObject);
          idSWFScriptObject::Set(this: timestamp, name: v39.data, value: &v36);
          idSWFScriptVar::Free(this: &v36);
          if ( v3 == 0 )
          {
            idSWFScriptVar::idSWFScriptVar(this: &v35, o: v10->scriptObject);
            idSWFScriptObject::Set(this: timestamp, name: "ENTER", value: &v35);
            v16 = &v35;
            goto _M488751_3;
          }
          if ( v3 == 1 )
          {
            idSWFScriptVar::idSWFScriptVar(this: &v34, o: v10->scriptObject);
            idSWFScriptObject::Set(this: timestamp, name: "ESCAPE", value: &v34);
            idSWFScriptVar::Free(this: &v34);
            idSWFScriptVar::idSWFScriptVar(this: v38, o: v10->scriptObject);
            idSWFScriptObject::Set(this: timestamp, name: "BACKSPACE", value: v38);
            v16 = v38;
_M488751_3:
            idSWFScriptVar::Free(this: v16);
          }
        }
        idSWFSpriteInstance::SetVisible(this: v12, visible: true);
        idSWFSpriteInstance::SetVisible(this: v10, visible: true);
        LODWORD(v17) = v28;
        v40 = v17;
        v18 = (float)v17;
        idSWFSpriteInstance::SetXPos(this: v10, xPos: v18);
        v19 = idStr::idStr(this: &v43, text: &this->buttons.list[v3].label);
        idSWFTextInstance::SetText(this: Text, val: v19);
        TextLength = idSWFTextInstance::GetTextLength(this: Text, a2: v25, a3: v24, a4: v23, a5: v22, a6: v21, a7: v20);
        LODWORD(v27) = v32;
        v41 = v27;
        v28 = (int)(float)((float)((float)((float)TextLength + (float)65.0) * (float)v27) + (float)v18);
LABEL_26:
        v7 = ++v3;
      }
      while ( v3 < v29.num );
    }
    idStr::FreeData(this: &v39);
    if ( (v29.listStatic == 0 || v29.listStatic == 2) && v29.list != nullptr )
      idMem::Free(this: &mem, ptr: v29.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$488471_0
// EA  : 0x82DDD53C
// RVA : 0x00DDD53C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488471_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 464 + 96));
}


// ========================================================================
// __unwind$488472
// EA  : 0x82DDD564
// RVA : 0x00DDD564
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488472()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 192));
}


// ========================================================================
// __unwind$488475
// EA  : 0x82DDD58C
// RVA : 0x00DDD58C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488475()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 464 + 168));
}


// ========================================================================
// __unwind$488476
// EA  : 0x82DDD5B4
// RVA : 0x00DDD5B4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488476()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 464 + 160));
}


// ========================================================================
// __unwind$488478
// EA  : 0x82DDD5DC
// RVA : 0x00DDD5DC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488478()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 464 + 144));
}


// ========================================================================
// __unwind$488479
// EA  : 0x82DDD604
// RVA : 0x00DDD604
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488479()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 464 + 176));
}


// ========================================================================
// __unwind$488477
// EA  : 0x82DDD62C
// RVA : 0x00DDD62C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_commandbar.cpp
// ========================================================================

void _unwind_488477()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 464 + 152));
}

