
// ========================================================================
// ?SetupTransitionInfo@idMenuWidget_Button@@ABAXAAUwidgetTransition_t@@W4widgetState_t@idMenuWidget@@W4animState_t@1@2@Z
// EA  : 0x82DDC0B8
// RVA : 0x00DDC0B8
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void __fastcall idMenuWidget_Button::SetupTransitionInfo(
        idMenuWidget_Button *this,
        widgetTransition_t *trans,
        const idMenuWidget::widgetState_t buttonState,
        const idMenuWidget_Button::animState_t sourceAnimState,
        const idMenuWidget_Button::animState_t destAnimState)
{
  idList<enum encounterGroupRole_t,5> *p_prefixes; // r27
  encounterGroupRole_t v10[16]; // [sp+50h] [-40h] BYREF

  p_prefixes = (idList<enum encounterGroupRole_t,5> *)&trans->prefixes;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&trans->prefixes);
  if ( buttonState == WIDGET_STATE_DISABLED )
  {
    trans->animationName = "disabled";
  }
  else
  {
    trans->animationName = (&ANIM_STATE_TRANSITIONS[3 * destAnimState])[sourceAnimState];
    if ( buttonState == WIDGET_STATE_SELECTING )
    {
      v10[0] = (encounterGroupRole_t)"sel_";
      idList<idAnimWebBlendTree *,5>::Append(this: p_prefixes, obj: v10);
    }
  }
  v10[0] = (encounterGroupRole_t)&byte_8200D768;
  idList<idAnimWebBlendTree *,5>::Append(this: p_prefixes, obj: v10);
}


// ========================================================================
// ?Update@idMenuWidget_Button@@UAAXXZ
// EA  : 0x82DDC1D8
// RVA : 0x00DDC1D8
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void __fastcall idMenuWidget_Button::Update(idMenuWidget_Button *this)
{
  idSWFScriptObject *scriptObject; // r20
  idSWFScriptObject *NestedObj; // r3
  idSWFTextInstance *text; // r30
  idStr *v5; // r3
  idSWFSpriteInstance *Sprite; // r30
  idSWFSpriteInstance *v7; // r28
  const idSWFScriptVar *v8; // r3
  idSWFSpriteInstance *v9; // r3
  idSWFSpriteInstance *v10; // r30
  int v11; // r3
  idSWFScriptObject *v12; // r30
  const char *v13; // r4
  idSWFSpriteInstance *v14; // r3
  idSWFScriptFunction *v15; // r3
  idSWFScriptFunction *v16; // r4
  idSWFScriptFunction *v17; // r3
  idSWFScriptFunction *v18; // r4
  idSWFScriptObject *v19; // r30
  idSWFScriptObject *v20; // r3
  idSWFScriptObject *v21; // r28
  idSWFScriptFunction *v22; // r3
  idSWFScriptFunction *v23; // r4
  idSWFScriptFunction *v24; // r3
  idSWFScriptFunction *v25; // r4
  idSWFScriptFunction *v26; // r3
  idSWFScriptFunction *v27; // r4
  idSWFScriptFunction *v28; // r3
  idSWFScriptFunction *v29; // r4
  idSWFScriptFunction *v30; // r3
  idSWFScriptFunction *v31; // r4
  idSWFScriptFunction *v32; // r3
  idSWFScriptFunction *v33; // r4
  idSWFScriptFunction *v34; // r3
  idSWFScriptFunction *v35; // r4
  idSWFScriptFunction *v36; // r3
  idSWFScriptFunction *v37; // r4
  idSWFScriptVar *v38; // r3
  idSWFScriptFunction *v39; // r3
  idSWFScriptFunction *v40; // r4
  idSWFScriptFunction *v41; // r3
  idSWFScriptFunction *v42; // r4
  idSWFScriptObject *v43; // r30
  idSWFScriptFunction *v44; // r3
  idSWFScriptFunction *v45; // r4
  idSWFScriptFunction *v46; // r3
  idSWFScriptFunction *v47; // r4
  idSWFSpriteInstance *boundSprite; // [sp+50h] [-140h]
  idMenuDataSource *dataSource; // [sp+50h] [-140h]
  menuOption_t optionType; // [sp+50h] [-140h]
  idSWFScriptVar v51; // [sp+58h] [-138h] BYREF
  idSWFScriptVar v52; // [sp+60h] [-130h] BYREF
  idSWFScriptVar v53; // [sp+68h] [-128h] BYREF
  idSWFScriptVar v54; // [sp+70h] [-120h] BYREF
  idSWFScriptVar v55; // [sp+78h] [-118h] BYREF
  idSWFScriptVar v56; // [sp+80h] [-110h] BYREF
  idSWFScriptVar v57; // [sp+88h] [-108h] BYREF
  idSWFScriptVar v58; // [sp+90h] [-100h] BYREF
  idSWFScriptVar v59; // [sp+98h] [-F8h] BYREF
  idSWFScriptVar v60; // [sp+A0h] [-F0h] BYREF
  idSWFScriptVar v61; // [sp+A8h] [-E8h] BYREF
  idSWFScriptVar v62; // [sp+B0h] [-E0h] BYREF
  idSWFScriptVar v63; // [sp+B8h] [-D8h] BYREF
  idSWFScriptVar v64; // [sp+C0h] [-D0h] BYREF
  idSWFScriptVar v65; // [sp+C8h] [-C8h] BYREF
  idSWFScriptVar v66; // [sp+D0h] [-C0h] BYREF
  idSWFScriptVar v67; // [sp+D8h] [-B8h] BYREF
  idSWFScriptVar v68[2]; // [sp+E0h] [-B0h] BYREF
  idStr v69[5]; // [sp+F0h] [-A0h] BYREF

  boundSprite = this->boundSprite;
  if ( boundSprite == nullptr )
    return;
  scriptObject = boundSprite->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
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
    v5 = idStr::idStr(this: v69, text: &this->label);
    idSWFTextInstance::SetText(this: text, val: v5);
    idSWFTextInstance::SetStrokeInfo(this: text, use: true, strength: 0.75, weight: 2.0);
  }
  Sprite = idSWFScriptObject::GetSprite(this: scriptObject, name: "optionType");
  if ( Sprite != nullptr )
  {
    if ( CONTROL_SPRITE_NAMES[this->optionType] != nullptr )
    {
      idSWFScriptVar::idSWFScriptVar(this: &v60, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
      idSWFScriptObject::Set(this: Sprite->scriptObject, name: "_visible", value: &v60);
      idSWFScriptVar::Free(this: &v60);
      idSWFSpriteInstance::StopFrame(
        this: Sprite,
        frameNum: (idSWFScriptVar::swfScriptVarValue_t *)(this->optionType + 1));
      v7 = idSWFScriptObject::GetSprite(
             this: Sprite->scriptObject,
             name: (char *)CONTROL_SPRITE_NAMES[this->optionType]);
      if ( v7 == nullptr )
        goto LABEL_58;
      dataSource = this->dataSource;
      if ( dataSource != nullptr )
      {
        v8 = dataSource->GetField(this: dataSource, a2: this->dataSourceFieldIndex);
        idSWFScriptVar::idSWFScriptVar(this: &v51, other: v8);
        optionType = this->optionType;
        if ( optionType == OPTION_SLIDER_BAR )
        {
          v9 = idSWFScriptObject::GetSprite(this: v7->scriptObject, name: "bar");
          v10 = v9;
          if ( v9 != nullptr )
          {
            idSWFSpriteInstance::SetVisible(this: v9, visible: true);
            v11 = idSWFScriptVar::ToInteger(this: &v51);
            idSWFSpriteInstance::StopFrame(this: v10, frameNum: (idSWFScriptVar::swfScriptVarValue_t *)(v11 + 1));
          }
        }
        else if ( optionType == OPTION_SLIDER_TEXT )
        {
          v12 = idSWFScriptObject::GetScriptObject(this: v7->scriptObject, name: "txtVal");
          if ( v12 != nullptr )
          {
            if ( (unsigned __int8)idSWFScriptVar::ToBool(this: &v51) != 0 )
              v13 = "ENABLED";
            else
              v13 = "DISABLED";
            idSWFScriptVar::idSWFScriptVar(this: &v54, s: v13);
            idSWFScriptObject::Set(this: v12, name: "text", value: &v54);
            idSWFScriptVar::Free(this: &v54);
          }
          v14 = idSWFScriptObject::GetSprite(this: v7->scriptObject, name: "bar");
          if ( v14 != nullptr )
            idSWFSpriteInstance::SetVisible(this: v14, visible: false);
        }
        idSWFScriptVar::Free(this: &v51);
      }
      v15 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v15 != nullptr )
      {
        v15[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v16 = v15;
        v15->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v15[1].__vftable = nullptr;
        v15[3].__vftable = (idSWFScriptFunction_vtbl *)2;
        v15[4].__vftable = nullptr;
      }
      else
      {
        v16 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v62, nf: v16);
      idSWFScriptObject::Set(this: v7->scriptObject, name: "onRollOver", value: &v62);
      idSWFScriptVar::Free(this: &v62);
      v17 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v17 != nullptr )
      {
        v17[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v18 = v17;
        v17->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v17[1].__vftable = nullptr;
        v17[3].__vftable = (idSWFScriptFunction_vtbl *)3;
        v17[4].__vftable = nullptr;
      }
      else
      {
        v18 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v56, nf: v18);
      idSWFScriptObject::Set(this: v7->scriptObject, name: "onRollOut", value: &v56);
      idSWFScriptVar::Free(this: &v56);
      v19 = idSWFScriptObject::GetScriptObject(this: v7->scriptObject, name: "btnLess");
      v20 = idSWFScriptObject::GetScriptObject(this: v7->scriptObject, name: "btnMore");
      v21 = v20;
      if ( v19 == nullptr || v20 == nullptr )
        goto LABEL_58;
      v22 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
      {
        v22[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v22->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v23 = v22;
        v22[1].__vftable = nullptr;
        v22[3].__vftable = (idSWFScriptFunction_vtbl *)10;
        v22[4].__vftable = nullptr;
      }
      else
      {
        v23 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v66, nf: v23);
      idSWFScriptObject::Set(this: v19, name: "onPress", value: &v66);
      idSWFScriptVar::Free(this: &v66);
      v24 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v24 != nullptr )
      {
        v24[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v24->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v25 = v24;
        v24[1].__vftable = nullptr;
        v24[3].__vftable = (idSWFScriptFunction_vtbl *)11;
        v24[4].__vftable = nullptr;
      }
      else
      {
        v25 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v58, nf: v25);
      idSWFScriptObject::Set(this: v19, name: "onRelease", value: &v58);
      idSWFScriptVar::Free(this: &v58);
      v26 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v26 != nullptr )
      {
        v26[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v26->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v27 = v26;
        v26[1].__vftable = nullptr;
        v26[3].__vftable = (idSWFScriptFunction_vtbl *)12;
        v26[4].__vftable = nullptr;
      }
      else
      {
        v27 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v64, nf: v27);
      idSWFScriptObject::Set(this: v21, name: "onPress", value: &v64);
      idSWFScriptVar::Free(this: &v64);
      v28 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v28 != nullptr )
      {
        v28[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v28->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v29 = v28;
        v28[1].__vftable = nullptr;
        v28[3].__vftable = (idSWFScriptFunction_vtbl *)13;
        v28[4].__vftable = nullptr;
      }
      else
      {
        v29 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v52, nf: v29);
      idSWFScriptObject::Set(this: v21, name: "onRelease", value: &v52);
      idSWFScriptVar::Free(this: &v52);
      v30 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v30 != nullptr )
      {
        v30[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v31 = v30;
        v30->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v30[1].__vftable = nullptr;
        v30[3].__vftable = (idSWFScriptFunction_vtbl *)2;
        v30[4].__vftable = nullptr;
      }
      else
      {
        v31 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: v68, nf: v31);
      idSWFScriptObject::Set(this: v19, name: "onRollOver", value: v68);
      idSWFScriptVar::Free(this: v68);
      v32 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v32 != nullptr )
      {
        v32[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v33 = v32;
        v32->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v32[1].__vftable = nullptr;
        v32[3].__vftable = (idSWFScriptFunction_vtbl *)3;
        v32[4].__vftable = nullptr;
      }
      else
      {
        v33 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v53, nf: v33);
      idSWFScriptObject::Set(this: v19, name: "onRollOut", value: &v53);
      idSWFScriptVar::Free(this: &v53);
      v34 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v34 != nullptr )
      {
        v34[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v35 = v34;
        v34->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v34[1].__vftable = nullptr;
        v34[3].__vftable = (idSWFScriptFunction_vtbl *)2;
        v34[4].__vftable = nullptr;
      }
      else
      {
        v35 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v55, nf: v35);
      idSWFScriptObject::Set(this: v21, name: "onRollOver", value: &v55);
      idSWFScriptVar::Free(this: &v55);
      v36 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x14u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v36 != nullptr )
      {
        v36[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v37 = v36;
        v36->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
        v36[1].__vftable = nullptr;
        v36[3].__vftable = (idSWFScriptFunction_vtbl *)3;
        v36[4].__vftable = nullptr;
      }
      else
      {
        v37 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v57, nf: v37);
      idSWFScriptObject::Set(this: v21, name: "onRollOut", value: &v57);
      v38 = &v57;
    }
    else
    {
      idSWFScriptVar::idSWFScriptVar(this: &v59, i: nullptr);
      idSWFScriptObject::Set(this: Sprite->scriptObject, name: "_visible", value: &v59);
      v38 = &v59;
    }
    idSWFScriptVar::Free(this: v38);
  }
LABEL_58:
  v39 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x14u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v39 != nullptr )
  {
    v39[2].__vftable = (idSWFScriptFunction_vtbl *)this;
    v40 = v39;
    v39->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
    v39[1].__vftable = nullptr;
    v39[3].__vftable = nullptr;
    v39[4].__vftable = nullptr;
  }
  else
  {
    v40 = nullptr;
  }
  idSWFScriptVar::idSWFScriptVar(this: &v61, nf: v40);
  idSWFScriptObject::Set(this: scriptObject, name: "onPress", value: &v61);
  idSWFScriptVar::Free(this: &v61);
  v41 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x14u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v41 != nullptr )
  {
    v41[2].__vftable = (idSWFScriptFunction_vtbl *)this;
    v41->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
    v42 = v41;
    v41[1].__vftable = nullptr;
    v41[3].__vftable = (idSWFScriptFunction_vtbl *)1;
    v41[4].__vftable = nullptr;
  }
  else
  {
    v42 = nullptr;
  }
  idSWFScriptVar::idSWFScriptVar(this: &v63, nf: v42);
  idSWFScriptObject::Set(this: scriptObject, name: "onRelease", value: &v63);
  idSWFScriptVar::Free(this: &v63);
  v43 = idSWFScriptObject::GetScriptObject(this: scriptObject, name: "hitBox");
  if ( v43 == nullptr )
    v43 = scriptObject;
  v44 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x14u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v44 != nullptr )
  {
    v44[2].__vftable = (idSWFScriptFunction_vtbl *)this;
    v45 = v44;
    v44->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
    v44[1].__vftable = nullptr;
    v44[3].__vftable = (idSWFScriptFunction_vtbl *)2;
    v44[4].__vftable = nullptr;
  }
  else
  {
    v45 = nullptr;
  }
  idSWFScriptVar::idSWFScriptVar(this: &v65, nf: v45);
  idSWFScriptObject::Set(this: v43, name: "onRollOver", value: &v65);
  idSWFScriptVar::Free(this: &v65);
  v46 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x14u,
                                 tag: TAG_SWF,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v46 != nullptr )
  {
    v46[2].__vftable = (idSWFScriptFunction_vtbl *)this;
    v47 = v46;
    v46->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
    v46[1].__vftable = nullptr;
    v46[3].__vftable = (idSWFScriptFunction_vtbl *)3;
    v46[4].__vftable = nullptr;
  }
  else
  {
    v47 = nullptr;
  }
  idSWFScriptVar::idSWFScriptVar(this: &v67, nf: v47);
  idSWFScriptObject::Set(this: v43, name: "onRollOut", value: &v67);
  idSWFScriptVar::Free(this: &v67);
}


// ========================================================================
// __unwind$488746_0
// EA  : 0x82DDCABC
// RVA : 0x00DDCABC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488746_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$488747_0
// EA  : 0x82DDCAE4
// RVA : 0x00DDCAE4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488747_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 88));
}


// ========================================================================
// __unwind$488748_0
// EA  : 0x82DDCB0C
// RVA : 0x00DDCB0C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488748_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$488750_0
// EA  : 0x82DDCB34
// RVA : 0x00DDCB34
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488750_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$488752_0
// EA  : 0x82DDCB5C
// RVA : 0x00DDCB5C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488752_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$488754
// EA  : 0x82DDCB84
// RVA : 0x00DDCB84
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488754()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 208));
}


// ========================================================================
// __unwind$488756_0
// EA  : 0x82DDCBAC
// RVA : 0x00DDCBAC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488756_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$488758
// EA  : 0x82DDCBD4
// RVA : 0x00DDCBD4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488758()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 192));
}


// ========================================================================
// __unwind$488760
// EA  : 0x82DDCBFC
// RVA : 0x00DDCBFC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488760()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$488762_0
// EA  : 0x82DDCC24
// RVA : 0x00DDCC24
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488762_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$488764
// EA  : 0x82DDCC4C
// RVA : 0x00DDCC4C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488764()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 104));
}


// ========================================================================
// __unwind$488766_1
// EA  : 0x82DDCC74
// RVA : 0x00DDCC74
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488766_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 120));
}


// ========================================================================
// __unwind$488768_1
// EA  : 0x82DDCC9C
// RVA : 0x00DDCC9C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488768_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 136));
}


// ========================================================================
// __unwind$488769_2
// EA  : 0x82DDCCC4
// RVA : 0x00DDCCC4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488769_2()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 152));
}


// ========================================================================
// __unwind$488771_2
// EA  : 0x82DDCCEC
// RVA : 0x00DDCCEC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488771_2()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 168));
}


// ========================================================================
// __unwind$488773_1
// EA  : 0x82DDCD14
// RVA : 0x00DDCD14
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488773_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 184));
}


// ========================================================================
// __unwind$488775_1
// EA  : 0x82DDCD3C
// RVA : 0x00DDCD3C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488775_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 200));
}


// ========================================================================
// __unwind$488777_1
// EA  : 0x82DDCD64
// RVA : 0x00DDCD64
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_488777_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 400 + 216));
}


// ========================================================================
// ?AnimateToState@idMenuWidget_Button@@AAAXW4animState_t@1@_N@Z
// EA  : 0x82DDCD98
// RVA : 0x00DDCD98
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void __fastcall idMenuWidget_Button::AnimateToState(
        idMenuWidget_Button *this,
        __int32 targetAnimState,
        const bool force)
{
  int v5; // r30
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  int v9; // r26
  va *v10; // r29
  idSWFSpriteInstance *Sprite; // r3
  const char *v12; // r4
  int v13; // [sp+8h] [-10B8h]
  int v14; // [sp+Ch] [-10B4h]
  int v15; // [sp+10h] [-10B0h]
  int v16; // [sp+14h] [-10ACh]
  int v17; // [sp+18h] [-10A8h]
  int v18; // [sp+1Ch] [-10A4h]
  widgetTransition_t v19; // [sp+50h] [-1070h] BYREF
  const char **v20; // [sp+74h] [-104Ch]
  va v21; // [sp+80h] [-1040h] BYREF

  if ( force || targetAnimState != this->animState )
  {
    if ( this->boundSprite != nullptr )
    {
      v5 = 0;
      v19.animationName = nullptr;
      v19.prefixes.num = 0;
      v19.prefixes.size = 4;
      v19.prefixes.granularity = 1;
      v19.prefixes.list = v19.prefixes.staticList;
      v19.prefixes.memTag = 5;
      v19.prefixes.listStatic = 1;
      idMenuWidget_Button::SetupTransitionInfo(
        this,
        trans: &v19,
        buttonState: (const idMenuWidget::widgetState_t)this->widgetState,
        sourceAnimState: (const idMenuWidget_Button::animState_t)this->animState,
        destAnimState: (const idMenuWidget_Button::animState_t)targetAnimState);
      LODWORD(v7) = v19.animationName;
      HIDWORD(v8) = (unsigned __int8)*v19.animationName;
      if ( *v19.animationName != 0 )
      {
        v9 = 0;
        if ( v19.prefixes.num > 0 )
        {
          while ( 1 )
          {
            LODWORD(v6) = &v19.prefixes.list[v5];
            v20 = &v19.prefixes.list[v5];
            HIDWORD(v7) = v19.prefixes.list[v5];
            v10 = va::va(
                    this: &v21,
                    fmt: "%s%s",
                    a3: v7,
                    a4: v8,
                    a5: v6,
                    a6: v13,
                    a7: v14,
                    a8: v15,
                    a9: v16,
                    a10: v17,
                    a11: v18);
            LODWORD(v8) = idSWFSpriteInstance::FrameExists(this: this->boundSprite, labelName: v10->buffer);
            if ( (_DWORD)v8 != 0 )
              break;
            ++v9;
            ++v5;
            if ( v9 >= v19.prefixes.num )
              goto LABEL_12;
            LODWORD(v7) = v19.animationName;
          }
          idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: v10->buffer);
          this->Update(this);
        }
      }
LABEL_12:
      Sprite = idSWFScriptObject::GetSprite(this: this->boundSprite->scriptObject, name: "focusIndicator");
      if ( Sprite != nullptr )
      {
        if ( targetAnimState == 2 )
          v12 = "show";
        else
          v12 = "hide";
        idSWFSpriteInstance::PlayFrame(this: Sprite, frameName: v12);
      }
      if ( (v19.prefixes.listStatic == 0 || v19.prefixes.listStatic == 2) && v19.prefixes.list != nullptr )
        idMem::Free(this: &mem, ptr: v19.prefixes.list, align: ALIGN_16);
    }
    this->animState = targetAnimState;
  }
}


// ========================================================================
// __unwind$489305
// EA  : 0x82DDCF3C
// RVA : 0x00DDCF3C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

void _unwind_489305()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 4288 + 80));
}


// ========================================================================
// ?ExecuteEvent@idMenuWidget_Button@@UAA_NABVidWidgetEvent@@@Z
// EA  : 0x82DDCF68
// RVA : 0x00DDCF68
// PDB : w:\tech5\tungsten\game\menus\menuwidget_button.cpp
// ========================================================================

int __fastcall idMenuWidget_Button::ExecuteEvent(idMenuWidget_Button *this, const idWidgetEvent *event)
{
  int v4; // r30
  widgetEvent_t type; // r11
  idMenuWidget::widgetState_t v6; // r4

  v4 = 0;
  if ( this->widgetState != WIDGET_STATE_DISABLED )
  {
    type = event->type;
    if ( event->type <= (unsigned int)WIDGET_EVENT_FOCUS_OFF )
    {
      if ( type != WIDGET_EVENT_RELEASE )
      {
        if ( type == WIDGET_EVENT_ROLL_OVER )
        {
          idMenuWidget_Button::AnimateToState(this, targetAnimState: 2, force: false);
LABEL_14:
          v4 = 1;
          goto LABEL_15;
        }
        if ( type != WIDGET_EVENT_ROLL_OUT )
        {
          if ( type == WIDGET_EVENT_FOCUS_ON )
          {
            v6 = WIDGET_STATE_SELECTING;
          }
          else
          {
            if ( type == WIDGET_EVENT_PRESS )
            {
              idMenuWidget_Button::AnimateToState(this, targetAnimState: 1, force: false);
              goto LABEL_14;
            }
            v6 = WIDGET_STATE_NORMAL;
          }
          idMenuWidget::SetState(this, state: v6);
          goto LABEL_14;
        }
      }
      idMenuWidget_Button::AnimateToState(this, targetAnimState: 0, force: false);
      goto LABEL_14;
    }
  }
LABEL_15:
  idMenuWidget::ExecuteEvent(this, event);
  return v4;
}

