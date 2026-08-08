
// ========================================================================
// ?Update@idMenuScreen@@UAAXXZ
// EA  : 0x82DD5598
// RVA : 0x00DD5598
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void __fastcall idMenuScreen::Update(idMenuScreen *this)
{
  idSWF *mainMenu; // r30
  idSWFScriptObject *timestamp; // r17
  idSWFScriptObject::swfNamedVar_t *list; // r29
  idSWFScriptObject *ScriptObject; // r3
  idSWFScriptObject *v6; // r18
  idSWFScriptObject *v7; // r29
  int v8; // r30
  idSWFScriptFunction *v9; // r3
  idSWFScriptFunction *v10; // r4
  idSWFScriptFunction *v11; // r3
  idSWFScriptFunction *v12; // r4
  idSWFScriptObject *v13; // r29
  idSWFScriptFunction *v14; // r3
  idSWFScriptFunction *v15; // r4
  idSWFScriptFunction *v16; // r3
  idSWFScriptFunction *v17; // r4
  idSWFScriptObject *v18; // r29
  idSWFScriptFunction *v19; // r3
  idSWFScriptFunction *v20; // r4
  idSWFScriptFunction *v21; // r3
  idSWFScriptFunction *v22; // r4
  idSWFScriptObject *v23; // r29
  idSWFScriptFunction *v24; // r3
  idSWFScriptFunction *v25; // r4
  idSWFScriptFunction *v26; // r3
  idSWFScriptFunction *v27; // r4
  idSWFScriptObject *v28; // r29
  idSWFScriptFunction *v29; // r3
  idSWFScriptFunction *v30; // r4
  idSWFScriptFunction *v31; // r3
  idSWFScriptFunction *v32; // r4
  idSWFScriptObject *v33; // r29
  idSWFScriptFunction *v34; // r3
  idSWFScriptFunction *v35; // r4
  idSWFScriptFunction *v36; // r3
  idSWFScriptFunction *v37; // r4
  idSWFScriptObject *v38; // r29
  idSWFScriptFunction *v39; // r3
  idSWFScriptFunction *v40; // r4
  idSWFScriptFunction *v41; // r3
  idSWFScriptFunction *v42; // r4
  idSWFScriptObject *v43; // r29
  idSWFScriptFunction *v44; // r3
  idSWFScriptFunction *v45; // r4
  idSWFScriptFunction *v46; // r3
  idSWFScriptFunction *v47; // r4
  int i; // r29
  idSWFScriptObject v49; // [sp+50h] [-230h] BYREF
  idSWFScriptVar v50; // [sp+B0h] [-1D0h] BYREF
  idSWFScriptVar v51; // [sp+B8h] [-1C8h] BYREF
  idSWFScriptVar v52; // [sp+C0h] [-1C0h] BYREF
  idSWFScriptVar v53; // [sp+C8h] [-1B8h] BYREF
  idSWFScriptVar v54; // [sp+D0h] [-1B0h] BYREF
  idSWFScriptVar v55; // [sp+D8h] [-1A8h] BYREF
  idSWFScriptVar v56; // [sp+E0h] [-1A0h] BYREF
  idSWFScriptVar v57; // [sp+E8h] [-198h] BYREF
  idSWFScriptVar v58; // [sp+F0h] [-190h] BYREF
  idSWFScriptVar v59; // [sp+F8h] [-188h] BYREF
  idSWFScriptVar v60; // [sp+100h] [-180h] BYREF
  idSWFScriptVar v61; // [sp+108h] [-178h] BYREF
  idSWFScriptVar v62; // [sp+110h] [-170h] BYREF
  idSWFScriptVar v63; // [sp+118h] [-168h] BYREF
  idSWFScriptVar v64; // [sp+120h] [-160h] BYREF
  idSWFScriptVar v65; // [sp+128h] [-158h] BYREF
  idSWFScriptVar v66; // [sp+130h] [-150h] BYREF
  idSWFScriptVar v67; // [sp+138h] [-148h] BYREF
  idSWFScriptVar v68; // [sp+140h] [-140h] BYREF
  idSWFScriptVar v69; // [sp+148h] [-138h] BYREF
  idSWFScriptVar v70[2]; // [sp+150h] [-130h] BYREF
  idStaticList<idSWFScriptVar,16> v71[2]; // [sp+160h] [-120h] BYREF

  mainMenu = gameLocal->mainMenu->mainMenu;
  timestamp = (idSWFScriptObject *)idSWF::GetGlobal(
                                     this: (idSWF *)&v69,
                                     result: (idSWFScriptVar *)mainMenu,
                                     name: "shortcutKeys")->timestamp;
  idSWFScriptVar::Free(this: &v69);
  if ( timestamp != nullptr )
  {
    idSWFScriptObject::Get(this: &v49, result: timestamp, name: "clear");
    if ( v49.refCount == 7 )
    {
      list = v49.variables.list;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: v71);
      (*(void (__fastcall **)(idSWFScriptVar *, idSWFScriptObject::swfNamedVar_t *, _DWORD, idStaticList<idSWFScriptVar,16> *))(list->index + 4))(
        a1: v70,
        a2: list,
        a3: 0,
        a4: v71);
      idSWFScriptVar::Free(this: v70);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v71);
    }
    ScriptObject = idSWFScriptObject::GetScriptObject(this: mainMenu->mainspriteInstance->scriptObject, name: "buttons");
    v6 = ScriptObject;
    if ( ScriptObject != nullptr )
    {
      v7 = idSWFScriptObject::GetScriptObject(this: ScriptObject, name: "btnUp");
      v8 = 0;
      if ( v7 != nullptr )
      {
        v9 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x14u,
                                      tag: TAG_SWF,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
        if ( v9 != nullptr )
        {
          v9[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v10 = v9;
          v9->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v9[1].__vftable = nullptr;
          v9[3].__vftable = (idSWFScriptFunction_vtbl *)6;
          v9[4].__vftable = nullptr;
        }
        else
        {
          v10 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v68, nf: v10);
        idSWFScriptObject::Set(this: v7, name: "onPress", value: &v68);
        idSWFScriptVar::Free(this: &v68);
        v11 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
        {
          v11[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v12 = v11;
          v11->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v11[1].__vftable = nullptr;
          v11[3].__vftable = (idSWFScriptFunction_vtbl *)7;
          v11[4].__vftable = nullptr;
        }
        else
        {
          v12 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v56, nf: v12);
        idSWFScriptObject::Set(this: v7, name: "onRelease", value: &v56);
        idSWFScriptVar::Free(this: &v56);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[3], o: v7);
        idSWFScriptObject::Set(this: timestamp, name: "STICK1_UP", value: (idSWFScriptVar *)&v49.variablesHash[3]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[3]);
        idSWFScriptVar::idSWFScriptVar(this: &v64, o: v7);
        idSWFScriptObject::Set(this: timestamp, name: "UP", value: &v64);
        idSWFScriptVar::Free(this: &v64);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[7], o: v7);
        idSWFScriptObject::Set(this: timestamp, name: "MWHEEL_UP", value: (idSWFScriptVar *)&v49.variablesHash[7]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[7]);
      }
      v13 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnDown");
      if ( v13 != nullptr )
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
          v15 = v14;
          v14->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v14[1].__vftable = nullptr;
          v14[3].__vftable = (idSWFScriptFunction_vtbl *)8;
          v14[4].__vftable = nullptr;
        }
        else
        {
          v15 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v58, nf: v15);
        idSWFScriptObject::Set(this: v13, name: "onPress", value: &v58);
        idSWFScriptVar::Free(this: &v58);
        v16 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v16 != nullptr )
        {
          v16[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v17 = v16;
          v16->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v16[1].__vftable = nullptr;
          v16[3].__vftable = (idSWFScriptFunction_vtbl *)9;
          v16[4].__vftable = nullptr;
        }
        else
        {
          v17 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[11], nf: v17);
        idSWFScriptObject::Set(this: v13, name: "onRelease", value: (idSWFScriptVar *)&v49.variablesHash[11]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[11]);
        idSWFScriptVar::idSWFScriptVar(this: &v67, o: v13);
        idSWFScriptObject::Set(this: timestamp, name: "STICK1_DOWN", value: &v67);
        idSWFScriptVar::Free(this: &v67);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[15], o: v13);
        idSWFScriptObject::Set(this: timestamp, name: "DOWN", value: (idSWFScriptVar *)&v49.variablesHash[15]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[15]);
        idSWFScriptVar::idSWFScriptVar(this: &v60, o: v13);
        idSWFScriptObject::Set(this: timestamp, name: "MWHEEL_DOWN", value: &v60);
        idSWFScriptVar::Free(this: &v60);
      }
      v18 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnPageUp");
      if ( v18 != nullptr )
      {
        v19 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v19 != nullptr )
        {
          v19[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v20 = v19;
          v19->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v19[1].__vftable = nullptr;
          v19[3].__vftable = (idSWFScriptFunction_vtbl *)6;
          v19[4].__vftable = (idSWFScriptFunction_vtbl *)1;
        }
        else
        {
          v20 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v50, nf: v20);
        idSWFScriptObject::Set(this: v18, name: "onPress", value: &v50);
        idSWFScriptVar::Free(this: &v50);
        v21 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v21 != nullptr )
        {
          v21[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v22 = v21;
          v21->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v21[1].__vftable = nullptr;
          v21[3].__vftable = (idSWFScriptFunction_vtbl *)7;
          v21[4].__vftable = nullptr;
        }
        else
        {
          v22 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v66, nf: v22);
        idSWFScriptObject::Set(this: v18, name: "onRelease", value: &v66);
        idSWFScriptVar::Free(this: &v66);
        idSWFScriptVar::idSWFScriptVar(this: &v52, o: v18);
        idSWFScriptObject::Set(this: timestamp, name: "PGUP", value: &v52);
        idSWFScriptVar::Free(this: &v52);
      }
      v23 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnPageDown");
      if ( v23 != nullptr )
      {
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
          v25 = v24;
          v24->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v24[1].__vftable = nullptr;
          v24[3].__vftable = (idSWFScriptFunction_vtbl *)8;
          v24[4].__vftable = (idSWFScriptFunction_vtbl *)1;
        }
        else
        {
          v25 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v62, nf: v25);
        idSWFScriptObject::Set(this: v23, name: "onPress", value: &v62);
        idSWFScriptVar::Free(this: &v62);
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
          v27 = v26;
          v26->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v26[1].__vftable = nullptr;
          v26[3].__vftable = (idSWFScriptFunction_vtbl *)9;
          v26[4].__vftable = nullptr;
        }
        else
        {
          v27 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v54, nf: v27);
        idSWFScriptObject::Set(this: v23, name: "onRelease", value: &v54);
        idSWFScriptVar::Free(this: &v54);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variables.num, o: v23);
        idSWFScriptObject::Set(this: timestamp, name: "PGDN", value: (idSWFScriptVar *)&v49.variables.num);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variables.num);
      }
      v28 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnHome");
      if ( v28 != nullptr )
      {
        v29 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v29 != nullptr )
        {
          v29[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v30 = v29;
          v29->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v29[1].__vftable = nullptr;
          v29[3].__vftable = (idSWFScriptFunction_vtbl *)6;
          v29[4].__vftable = (idSWFScriptFunction_vtbl *)2;
        }
        else
        {
          v30 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variables.granularity, nf: v30);
        idSWFScriptObject::Set(this: v28, name: "onPress", value: (idSWFScriptVar *)&v49.variables.granularity);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variables.granularity);
        v31 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v31 != nullptr )
        {
          v31[2].__vftable = (idSWFScriptFunction_vtbl *)this;
          v32 = v31;
          v31->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v31[1].__vftable = nullptr;
          v31[3].__vftable = (idSWFScriptFunction_vtbl *)7;
          v31[4].__vftable = nullptr;
        }
        else
        {
          v32 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[1], nf: v32);
        idSWFScriptObject::Set(this: v28, name: "onRelease", value: (idSWFScriptVar *)&v49.variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[1]);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[5], o: v28);
        idSWFScriptObject::Set(this: timestamp, name: "HOME", value: (idSWFScriptVar *)&v49.variablesHash[5]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[5]);
      }
      v33 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnEnd");
      if ( v33 != nullptr )
      {
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
          v34[3].__vftable = (idSWFScriptFunction_vtbl *)8;
          v34[4].__vftable = (idSWFScriptFunction_vtbl *)2;
        }
        else
        {
          v35 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[9], nf: v35);
        idSWFScriptObject::Set(this: v33, name: "onPress", value: (idSWFScriptVar *)&v49.variablesHash[9]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[9]);
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
          v36[3].__vftable = (idSWFScriptFunction_vtbl *)9;
          v36[4].__vftable = nullptr;
        }
        else
        {
          v37 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.variablesHash[13], nf: v37);
        idSWFScriptObject::Set(this: v33, name: "onRelease", value: (idSWFScriptVar *)&v49.variablesHash[13]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.variablesHash[13]);
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v49.objectType, o: v33);
        idSWFScriptObject::Set(this: timestamp, name: "END", value: (idSWFScriptVar *)&v49.objectType);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49.objectType);
      }
      v38 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnLeft");
      if ( v38 != nullptr )
      {
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
          v39->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v40 = v39;
          v39[1].__vftable = nullptr;
          v39[3].__vftable = (idSWFScriptFunction_vtbl *)10;
          v39[4].__vftable = nullptr;
        }
        else
        {
          v40 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v51, nf: v40);
        idSWFScriptObject::Set(this: v38, name: "onPress", value: &v51);
        idSWFScriptVar::Free(this: &v51);
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
          v41[3].__vftable = (idSWFScriptFunction_vtbl *)11;
          v41[4].__vftable = nullptr;
        }
        else
        {
          v42 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v53, nf: v42);
        idSWFScriptObject::Set(this: v38, name: "onRelease", value: &v53);
        idSWFScriptVar::Free(this: &v53);
        idSWFScriptVar::idSWFScriptVar(this: &v55, o: v38);
        idSWFScriptObject::Set(this: timestamp, name: "STICK1_LEFT", value: &v55);
        idSWFScriptVar::Free(this: &v55);
        idSWFScriptVar::idSWFScriptVar(this: &v57, o: v38);
        idSWFScriptObject::Set(this: timestamp, name: "LEFT", value: &v57);
        idSWFScriptVar::Free(this: &v57);
      }
      v43 = idSWFScriptObject::GetScriptObject(this: v6, name: "btnRight");
      if ( v43 != nullptr )
      {
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
          v44->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v45 = v44;
          v44[1].__vftable = nullptr;
          v44[3].__vftable = (idSWFScriptFunction_vtbl *)12;
          v44[4].__vftable = nullptr;
        }
        else
        {
          v45 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v59, nf: v45);
        idSWFScriptObject::Set(this: v43, name: "onPress", value: &v59);
        idSWFScriptVar::Free(this: &v59);
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
          v46->__vftable = (idSWFScriptFunction_vtbl *)&idMenuWidget::WrapWidgetSWFEvent::`vftable';
          v47 = v46;
          v46[1].__vftable = nullptr;
          v46[3].__vftable = (idSWFScriptFunction_vtbl *)13;
          v46[4].__vftable = nullptr;
        }
        else
        {
          v47 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v61, nf: v47);
        idSWFScriptObject::Set(this: v43, name: "onRelease", value: &v61);
        idSWFScriptVar::Free(this: &v61);
        idSWFScriptVar::idSWFScriptVar(this: &v63, o: v43);
        idSWFScriptObject::Set(this: timestamp, name: "STICK1_RIGHT", value: &v63);
        idSWFScriptVar::Free(this: &v63);
        idSWFScriptVar::idSWFScriptVar(this: &v65, o: v43);
        idSWFScriptObject::Set(this: timestamp, name: "RIGHT", value: &v65);
        idSWFScriptVar::Free(this: &v65);
      }
      for ( i = 0; i < this->children.num; ++v8 )
      {
        this->children.list[v8]->Update(this: this->children.list[v8]);
        ++i;
      }
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v49);
  }
}


// ========================================================================
// __unwind$488233
// EA  : 0x82DD60A0
// RVA : 0x00DD60A0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488233()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 80));
}


// ========================================================================
// __unwind$488234
// EA  : 0x82DD60C8
// RVA : 0x00DD60C8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488234()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 640 + 352));
}


// ========================================================================
// __unwind$488237
// EA  : 0x82DD60F0
// RVA : 0x00DD60F0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488237()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 320));
}


// ========================================================================
// __unwind$488239
// EA  : 0x82DD6118
// RVA : 0x00DD6118
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488239()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 224));
}


// ========================================================================
// __unwind$488240_0
// EA  : 0x82DD6140
// RVA : 0x00DD6140
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488240_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 112));
}


// ========================================================================
// __unwind$488241_0
// EA  : 0x82DD6168
// RVA : 0x00DD6168
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488241_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 288));
}


// ========================================================================
// __unwind$488242
// EA  : 0x82DD6190
// RVA : 0x00DD6190
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488242()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 128));
}


// ========================================================================
// __unwind$488244
// EA  : 0x82DD61B8
// RVA : 0x00DD61B8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488244()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 240));
}


// ========================================================================
// __unwind$488246_0
// EA  : 0x82DD61E0
// RVA : 0x00DD61E0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488246_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 144));
}


// ========================================================================
// __unwind$488247_1
// EA  : 0x82DD6208
// RVA : 0x00DD6208
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488247_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 312));
}


// ========================================================================
// __unwind$488248_0
// EA  : 0x82DD6230
// RVA : 0x00DD6230
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488248_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 160));
}


// ========================================================================
// __unwind$488249_0
// EA  : 0x82DD6258
// RVA : 0x00DD6258
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488249_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 256));
}


// ========================================================================
// __unwind$488251
// EA  : 0x82DD6280
// RVA : 0x00DD6280
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488251()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 176));
}


// ========================================================================
// __unwind$488253
// EA  : 0x82DD62A8
// RVA : 0x00DD62A8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488253()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 304));
}


// ========================================================================
// __unwind$488254_0
// EA  : 0x82DD62D0
// RVA : 0x00DD62D0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488254_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 192));
}


// ========================================================================
// __unwind$488256_0
// EA  : 0x82DD62F8
// RVA : 0x00DD62F8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488256_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 272));
}


// ========================================================================
// __unwind$488258
// EA  : 0x82DD6320
// RVA : 0x00DD6320
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488258()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 208));
}


// ========================================================================
// __unwind$488259
// EA  : 0x82DD6348
// RVA : 0x00DD6348
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488259()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 88));
}


// ========================================================================
// __unwind$488261
// EA  : 0x82DD6370
// RVA : 0x00DD6370
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488261()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 96));
}


// ========================================================================
// __unwind$488263
// EA  : 0x82DD6398
// RVA : 0x00DD6398
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488263()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 104));
}


// ========================================================================
// __unwind$488264
// EA  : 0x82DD63C0
// RVA : 0x00DD63C0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488264()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 120));
}


// ========================================================================
// __unwind$488266
// EA  : 0x82DD63E8
// RVA : 0x00DD63E8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488266()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 136));
}


// ========================================================================
// __unwind$488268
// EA  : 0x82DD6410
// RVA : 0x00DD6410
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488268()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 152));
}


// ========================================================================
// __unwind$488269
// EA  : 0x82DD6438
// RVA : 0x00DD6438
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488269()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 168));
}


// ========================================================================
// __unwind$488271
// EA  : 0x82DD6460
// RVA : 0x00DD6460
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488271()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 184));
}


// ========================================================================
// __unwind$488273_0
// EA  : 0x82DD6488
// RVA : 0x00DD6488
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488273_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 200));
}


// ========================================================================
// __unwind$488274_0
// EA  : 0x82DD64B0
// RVA : 0x00DD64B0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488274_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 216));
}


// ========================================================================
// __unwind$488275_0
// EA  : 0x82DD64D8
// RVA : 0x00DD64D8
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488275_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 232));
}


// ========================================================================
// __unwind$488277_0
// EA  : 0x82DD6500
// RVA : 0x00DD6500
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488277_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 248));
}


// ========================================================================
// __unwind$488279
// EA  : 0x82DD6528
// RVA : 0x00DD6528
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488279()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 264));
}


// ========================================================================
// __unwind$488280
// EA  : 0x82DD6550
// RVA : 0x00DD6550
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488280()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 280));
}


// ========================================================================
// __unwind$488281
// EA  : 0x82DD6578
// RVA : 0x00DD6578
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_488281()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 640 + 296));
}


// ========================================================================
// ?HideScreen@idMenuScreen@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD65A0
// RVA : 0x00DD65A0
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void __fastcall idMenuScreen::HideScreen(idMenuScreen *this, const mainMenuTransition_t transitionType)
{
  const char *v4; // r4

  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
  {
    if ( transitionType != MENU_TRANSITION_ADVANCE )
      v4 = "rollOffBack";
    else
      v4 = "rollOffFront";
    idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: v4);
  }
}


// ========================================================================
// ?ShowScreen@idMenuScreen@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD6628
// RVA : 0x00DD6628
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void __fastcall idMenuScreen::ShowScreen(idMenuScreen *this, const mainMenuTransition_t transitionType)
{
  const char *v4; // r4

  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
  {
    if ( transitionType != MENU_TRANSITION_ADVANCE )
      v4 = "rollOnFront";
    else
      v4 = "rollOnBack";
    idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: v4);
    this->Update(this);
    idMenuWidget::SetFocusIndex(this, index: this->focusIndex);
  }
}


// ========================================================================
// ?ObserveEvent@idMenuScreen@@UAAXABVidMenuWidget@@ABVidWidgetEvent@@@Z
// EA  : 0x82DD6770
// RVA : 0x00DD6770
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void __fastcall idMenuScreen::ObserveEvent(idMenuScreen *this, const idMenuWidget *widget, const idWidgetEvent *event)
{
  int arg; // r11
  idSWFScriptObject *thisObject; // r11
  idSWFParmList *p_parms; // r3
  idSWFScriptObject *v7; // r10
  idWidgetEvent v8; // [sp+50h] [-160h] BYREF
  idWidgetEvent v9; // [sp+F0h] [-C0h] BYREF

  if ( event->type == WIDGET_EVENT_COMMAND )
  {
    arg = event->arg;
    if ( arg != 0 )
    {
      if ( arg != 1 )
        return;
      thisObject = event->thisObject;
      v8.type = WIDGET_EVENT_BACK;
      v8.arg = 0;
      v8.thisObject = thisObject;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
        this: &v8.parms.idStaticList<idSWFScriptVar,16>,
        other: &event->parms);
      idMenuWidget::ReceiveEvent(this, event: &v8);
      p_parms = &v8.parms;
    }
    else
    {
      v7 = event->thisObject;
      v9.type = WIDGET_EVENT_PRESS;
      v9.arg = 0;
      v9.thisObject = v7;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
        this: &v9.parms.idStaticList<idSWFScriptVar,16>,
        other: &event->parms);
      idMenuWidget::ReceiveEvent(this, event: &v9);
      p_parms = &v9.parms;
    }
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &p_parms->idStaticList<idSWFScriptVar,16>);
  }
}


// ========================================================================
// __unwind$489065
// EA  : 0x82DD682C
// RVA : 0x00DD682C
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489065()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 432 + 80));
}


// ========================================================================
// __unwind$489064_0
// EA  : 0x82DD6854
// RVA : 0x00DD6854
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489064_0()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 432 + 240));
}


// ========================================================================
// ?HandleMenu@idMenuScreen@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD6888
// RVA : 0x00DD6888
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void __fastcall idMenuScreen::HandleMenu(idMenuScreen *this, mainMenuTransition_t type)
{
  idStaticList<idSWFScriptVar,16> *v4; // r3
  idWidgetEvent v5; // [sp+50h] [-280h] BYREF
  idWidgetEvent v6; // [sp+F0h] [-1E0h] BYREF
  idStaticList<idSWFScriptVar,16> v7; // [sp+190h] [-140h] BYREF
  idStaticList<idSWFScriptVar,16> v8; // [sp+220h] [-B0h] BYREF

  if ( type == MENU_TRANSITION_ADVANCE )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v8);
    memset((void *)&v6, 0, 12);
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
      this: &v6.parms.idStaticList<idSWFScriptVar,16>,
      other: &v8);
    idMenuWidget::ReceiveEvent(this, event: &v6);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6.parms.idStaticList<idSWFScriptVar,16>);
    v4 = &v8;
_M489221_0:
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v4);
    goto LABEL_6;
  }
  if ( type == MENU_TRANSITION_BACK )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v7);
    v5.arg = 0;
    v5.type = WIDGET_EVENT_BACK;
    v5.thisObject = nullptr;
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
      this: &v5.parms.idStaticList<idSWFScriptVar,16>,
      other: &v7);
    idMenuWidget::ReceiveEvent(this, event: &v5);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v5.parms.idStaticList<idSWFScriptVar,16>);
    v4 = &v7;
    goto _M489221_0;
  }
LABEL_6:
  gameLocal->mainMenu->menuTransition = type;
}


// ========================================================================
// __unwind$489139_2
// EA  : 0x82DD6954
// RVA : 0x00DD6954
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489139_2()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 720 + 544));
}


// ========================================================================
// __unwind$489140_1
// EA  : 0x82DD697C
// RVA : 0x00DD697C
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489140_1()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 720 + 240));
}


// ========================================================================
// __unwind$489141_3
// EA  : 0x82DD69A4
// RVA : 0x00DD69A4
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489141_3()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 720 + 400));
}


// ========================================================================
// __unwind$489142_2
// EA  : 0x82DD69CC
// RVA : 0x00DD69CC
// PDB : w:\tech5\tungsten\game\menus\menuscreen.cpp
// ========================================================================

void _unwind_489142_2()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 720 + 80));
}

