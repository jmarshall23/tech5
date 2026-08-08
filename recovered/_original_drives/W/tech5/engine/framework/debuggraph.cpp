
// ========================================================================
// ?Render@idDebugGraph@@QAAXPAVidRenderModelGui@@@Z
// EA  : 0x82670880
// RVA : 0x00670880
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void __fastcall idDebugGraph::Render(idDebugGraph *this, idRenderModelGui *gui)
{
  idVec4 *p_position; // r26
  __int64 v5; // r9
  int num; // r10
  double border; // fp13
  int v8; // r30
  double v9; // fp8
  double v10; // fp29
  double v11; // fp28
  double v12; // fp26
  double v13; // fp30
  double v14; // fp31
  unsigned int v15; // r29
  idDebugGraph::fillMode_t mode; // r11
  __int64 v17; // r11
  double v18; // fp0
  __int64 v19; // r11
  double v20; // fp0
  __int64 v21; // r11
  double v22; // fp0
  idStr *list; // r7
  int len; // r9
  int v25; // r8
  int v26; // r11
  __int64 v27; // r11
  double v28; // fp30
  float w; // r6
  __int64 v30; // r10
  int v31; // r30
  int v32; // r29
  idStr *v33; // r11
  __int64 v34; // r10
  __int64 v35; // r4
  char *data; // r6
  double v37; // fp8
  double z; // fp12
  double v39; // fp9
  double v40; // fp27
  double v41; // fp29
  double v42; // fp30
  double v43; // fp28
  double v44; // fp31
  int v45; // r29
  double v46; // fp13
  idDebugGraph::graphPlot_t *v47; // r11
  int v48; // r29
  unsigned int v49; // r30
  idDebugGraph::fillMode_t v50; // r11
  __int64 v51; // r11
  double v52; // fp9
  double v53; // fp7
  __int64 v54; // r11
  double v55; // fp10
  __int64 v56; // r11
  double v57; // fp13
  float y; // r8
  float v59; // r7
  __int64 v60; // r10
  int v61; // r30
  int v62; // r29
  double v63; // fp13
  idStr *v64; // r11
  __int64 v65; // r10
  __int64 v66; // r4
  char *v67; // r6
  double v68; // fp6
  double v69; // fp31
  double v70; // fp30
  __int64 v71; // r5
  int v72; // r3
  unsigned __int32 v73; // r11
  double v74; // fp8
  __int64 v75; // r10
  char *v76; // r6
  idVec4 v77; // [sp+50h] [-D0h] BYREF
  __int64 v78; // [sp+60h] [-C0h]
  __int64 v79; // [sp+68h] [-B8h]
  idVec4 v80; // [sp+70h] [-B0h] BYREF
  idVec4 v81[5]; // [sp+80h] [-A0h] BYREF

  if ( this->enable )
  {
    if ( this->white == nullptr )
      this->white = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "_white",
                                          makeDefault: true);
    v81[0].x = 0.0;
    v81[0].y = 0.0;
    v81[0].z = 0.0;
    v81[0].w = 0.0;
    gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&this->bgColor);
    p_position = &this->position;
    idRenderModelGui::DrawStretchPic(this: gui, rect: &this->position, st: v81, material: this->white);
    num = this->bars.num;
    if ( num != 0 )
    {
      border = this->border;
      v8 = 0;
      if ( this->sideways )
      {
        LODWORD(v5) = this->bars.num;
        v9 = (float)(this->position.w - this->border);
        *(_QWORD *)&v77.x = v5;
        v10 = (float)(p_position->x + (float)border);
        v11 = (float)((float)border + this->position.y);
        v12 = 1.0;
        v13 = (float)-(float)((float)((float)border * (float)2.0) - this->position.z);
        v14 = (float)((float)v9 / (float)v5);
        if ( num > 0 )
        {
          v15 = 0;
          do
          {
            mode = this->mode;
            v80 = vec4_origin;
            if ( mode != GRAPH_LINE )
            {
              if ( mode == GRAPH_FILL )
              {
                LODWORD(v19) = v8;
                HIDWORD(v19) = this->bars.list;
                v20 = this->border;
                v78 = v19;
                v80.x = v10;
                v80.z = *(float *)(HIDWORD(v19) + v15) * (float)v13;
                v80.w = (float)v14 - (float)v20;
                v80.y = (float)((float)v19 * (float)v14) + (float)v11;
              }
              else if ( mode == GRAPH_FILL_REVERSE )
              {
                LODWORD(v21) = v8;
                HIDWORD(v21) = this->bars.list;
                v22 = this->border;
                v79 = v21;
                v80.x = (float)v10 + (float)v13;
                v80.z = -(float)((float)(*(float *)(HIDWORD(v21) + v15) * (float)v13) - (float)v13);
                v80.w = (float)v14 - (float)v22;
                v80.y = (float)((float)v21 * (float)v14) + (float)v11;
              }
            }
            else
            {
              LODWORD(v17) = v8;
              HIDWORD(v17) = this->bars.list;
              v18 = this->border;
              *(_QWORD *)&v77.x = v17;
              v80.z = 1.0;
              v80.x = (float)(*(float *)(HIDWORD(v17) + v15) * (float)v13) + (float)v10;
              v80.w = (float)v14 - (float)v18;
              v80.y = (float)((float)v17 * (float)v14) + (float)v11;
            }
            gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&this->bars.list[v15 / 0x14].color);
            idRenderModelGui::DrawStretchPic(this: gui, rect: &v80, st: v81, material: this->white);
            ++v8;
            v15 += 20;
          }
          while ( v8 < this->bars.num );
        }
        if ( this->labels.num > 0 )
        {
          len = 0;
          v25 = 0;
          v26 = 0;
          do
          {
            list = this->labels.list;
            if ( len <= list[v26].len )
              len = list[v26].len;
            ++v25;
            ++v26;
          }
          while ( v25 < this->labels.num );
          LODWORD(v27) = len;
          *(float *)&v27 = p_position->x;
          v79 = v27;
          v28 = (float)v27;
          w = this->position.w;
          v80.y = this->position.y;
          v80.w = w;
          v80.z = (float)v27 * SMALLCHAR_WIDTH;
          v80.x = *(float *)&v27 - v80.z;
          gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&this->bgColor);
          idRenderModelGui::DrawStretchPic(this: gui, rect: &v80, st: v81, material: this->white);
          v31 = 0;
          if ( this->labels.num > 0 )
          {
            v32 = 0;
            do
            {
              LODWORD(v30) = v31;
              v33 = this->labels.list;
              v78 = v30;
              HIDWORD(v35) = gui;
              data = v33[v32].data;
              LODWORD(v35) = (int)(float)-(float)((float)((float)v28 * SMALLCHAR_WIDTH) - (float)v10);
              *(_QWORD *)&v77.x = v35;
              v37 = (float)((float)((float)v30 * (float)v14) + (float)v11);
              HIDWORD(v34) = &v33[v32];
              LODWORD(v79) = (int)v37;
              LODWORD(v34) = (int)v37;
              *(_QWORD *)&v80.x = v34;
              idRenderModelGui::DrawString(
                this: gui,
                x: (float)v35,
                y: (float)v34,
                string: (const char *)v35,
                defaultColor: (const idVec4 *)v35,
                forceColor: (bool)data,
                scale: 1.0);
              HIDWORD(v30) = this->labels.num;
              ++v31;
              ++v32;
            }
            while ( v31 < SHIDWORD(v30) );
          }
        }
        goto LABEL_41;
      }
      z = this->position.z;
      v39 = this->position.w;
      *(_QWORD *)&v80.x = __PAIR64__(&off_82010000, num);
      v40 = (float)((float)border + this->position.y);
      v41 = (float)(p_position->x + (float)border);
      v42 = (float)-(float)((float)((float)border * 2.0) - (float)v39);
      v12 = 1.0;
      v43 = (float)((float)((float)border + this->position.y) - (float)((float)((float)border * 2.0) - (float)v39));
      v44 = (float)((float)((float)z - (float)border) / (float)__SPAIR64__(&off_82010000, num));
      if ( this->grid.num > 0 )
      {
        v80.w = 1.0;
        v45 = 0;
        do
        {
          v46 = this->position.z;
          v47 = &this->grid.list[v45];
          v80.x = p_position->x;
          v80.z = v46;
          v80.y = -(float)((float)(v47->value * (float)v42) - (float)v43);
          gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&v47->color);
          idRenderModelGui::DrawStretchPic(this: gui, rect: &v80, st: v81, material: this->white);
          ++v8;
          ++v45;
        }
        while ( v8 < this->grid.num );
      }
      v48 = 0;
      if ( this->bars.num <= 0 )
      {
LABEL_37:
        if ( this->labels.num > 0 )
        {
          y = this->position.y;
          v59 = this->position.z;
          v80.x = p_position->x;
          v80.z = v59;
          v80.w = SMALLCHAR_HEIGHT;
          v80.y = y + (float)v42;
          gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&this->bgColor);
          idRenderModelGui::DrawStretchPic(this: gui, rect: &v80, st: v81, material: this->white);
          v61 = 0;
          if ( this->labels.num > 0 )
          {
            v62 = 0;
            do
            {
              LODWORD(v60) = v61;
              v63 = (float)(this->border + (float)v43);
              v64 = this->labels.list;
              *(_QWORD *)&v80.x = v60;
              HIDWORD(v66) = gui;
              v67 = v64[v62].data;
              LODWORD(v66) = (int)v63;
              v78 = v66;
              v68 = (float)((float)((float)v60 * (float)v44) + (float)v41);
              HIDWORD(v65) = &v64[v62];
              LODWORD(v79) = (int)v68;
              LODWORD(v65) = (int)v68;
              *(_QWORD *)&v77.x = v65;
              idRenderModelGui::DrawString(
                this: gui,
                x: (float)v65,
                y: (float)v66,
                string: (const char *)(int)v63,
                defaultColor: (const idVec4 *)(int)v63,
                forceColor: (bool)v67,
                scale: 1.0);
              HIDWORD(v60) = this->labels.num;
              ++v61;
              ++v62;
            }
            while ( v61 < SHIDWORD(v60) );
          }
        }
LABEL_41:
        if ( this->capPos == CAP_NONE )
          return;
        v69 = 0.0;
        v70 = 0.0;
        v72 = idStr::LengthWithoutColors(s: this->caption.data);
        v73 = this->capPos - 1;
        *(_QWORD *)&v80.x = __PAIR64__(0x82000000, v72);
        if ( v73 > 3 )
          goto LABEL_51;
        switch ( v73 )
        {
          case 1u:
            v69 = (float)((float)(p_position->x + this->position.z) + (float)5.0);
            v70 = (float)-(float)((float)(SMALLCHAR_HEIGHT * (float)0.5)
                                - (float)((float)(this->position.w * (float)0.5) + this->position.y));
LABEL_51:
            HIDWORD(v75) = (int)v70;
            LODWORD(v71) = (int)v70;
            v79 = v71;
            v76 = this->caption.data;
            LODWORD(v75) = (int)(float)((float)(SMALLCHAR_WIDTH * (float)0.5) + (float)v69);
            *(_QWORD *)&v80.x = v75;
            idRenderModelGui::DrawString(
              this: gui,
              x: (float)v75,
              y: (float)v71,
              string: (const char *)HIDWORD(v71),
              defaultColor: (const idVec4 *)(int)v70,
              forceColor: (bool)v76,
              scale: v12);
            return;
          case 2u:
            v74 = (float)((float)(this->position.z * (float)0.5) + p_position->x);
            v70 = (float)((float)(this->position.y - (float)5.0) - SMALLCHAR_HEIGHT);
            break;
          case 0u:
            v69 = (float)((float)(p_position->x - (float)((float)__SPAIR64__(0x82000000, v72) * SMALLCHAR_WIDTH))
                        - (float)5.0);
            v70 = (float)-(float)((float)(SMALLCHAR_HEIGHT * (float)0.5)
                                - (float)((float)(this->position.w * (float)0.5) + this->position.y));
            goto LABEL_51;
          default:
            v74 = (float)((float)(this->position.z * (float)0.5) + p_position->x);
            v70 = (float)((float)(this->position.w + this->position.y) + (float)5.0);
            break;
        }
        v69 = (float)-(float)((float)((float)((float)__SPAIR64__(0x82000000, v72) * SMALLCHAR_WIDTH) * (float)0.5)
                            - (float)v74);
        goto LABEL_51;
      }
      v49 = 0;
      while ( 1 )
      {
        v50 = this->mode;
        if ( v50 == GRAPH_LINE )
          break;
        if ( v50 == GRAPH_FILL )
        {
          LODWORD(v54) = v48;
          HIDWORD(v54) = this->bars.list;
          v77.z = (float)v44 - this->border;
          v79 = v54;
          v55 = (float)((float)v43 - (float)(*(float *)(HIDWORD(v54) + v49) * (float)v42));
          v77.w = *(float *)(HIDWORD(v54) + v49) * (float)v42;
          v77.y = v55;
          v77.x = (float)((float)v54 * (float)v44) + (float)v41;
        }
        else if ( v50 == GRAPH_FILL_REVERSE )
        {
          LODWORD(v56) = v48;
          HIDWORD(v56) = this->bars.list;
          v57 = (float)((float)v44 - this->border);
          v78 = v56;
          v77.y = v40;
          v77.z = v57;
          v77.w = *(float *)(HIDWORD(v56) + v49) * (float)v42;
          v53 = (float)((float)((float)v56 * (float)v44) + (float)v41);
          goto LABEL_35;
        }
LABEL_36:
        gui->currentVertexColor = idColor::PackColor(color: (const idVec4 *)&this->bars.list[v49 / 0x14].color);
        idRenderModelGui::DrawStretchPic(this: gui, rect: &v77, st: v81, material: this->white);
        ++v48;
        v49 += 20;
        if ( v48 >= this->bars.num )
          goto LABEL_37;
      }
      LODWORD(v51) = v48;
      HIDWORD(v51) = this->bars.list;
      v52 = (float)((float)v44 - this->border);
      *(_QWORD *)&v80.x = v51;
      v77.w = 1.0;
      v77.z = v52;
      v77.y = -(float)((float)(*(float *)(HIDWORD(v51) + v49) * (float)v42) - (float)v43);
      v53 = (float)((float)((float)v51 * (float)v44) + (float)v41);
LABEL_35:
      v77.x = v53;
      goto LABEL_36;
    }
  }
}


// ========================================================================
// ?SetLabel@idDebugGraph@@QAAXHPBD@Z
// EA  : 0x826710A8
// RVA : 0x006710A8
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void __fastcall idDebugGraph::SetLabel(idDebugGraph *this, int b, const char *text)
{
  int num; // r4

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  num = this->bars.num;
  if ( this->labels.num != num )
    idList<idStr,3>::SetNum(this: (idList<idStr,5> *)&this->labels, newNum: num);
  idMem::PopHeap(this: &mem);
  idStr::operator=(this: &this->labels.list[b], text);
}


// ========================================================================
// ?Init@idDebugGraph@@QAAXH@Z
// EA  : 0x826712A0
// RVA : 0x006712A0
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void __fastcall idDebugGraph::Init(idDebugGraph *this, int numBars)
{
  idList<idDebugGraph::graphPlot_t,3> *p_bars; // r31
  int size; // r11
  idStr *list; // r3
  int v7; // r10
  int v8; // r11
  int v9; // r11
  int v10; // ctr

  p_bars = &this->bars;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( numBars <= this->bars.size
    || (unsigned __int8)idList<idDebugGraph::graphPlot_t,3>::Resize(this: &this->bars, newsize: numBars) != 0 )
  {
    size = this->bars.size;
    if ( numBars < size )
      size = numBars;
    this->bars.num = size;
  }
  idMem::PopHeap(this: &mem);
  if ( this->labels.listStatic == 0 || this->labels.listStatic == 2 )
  {
    list = this->labels.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->labels.size);
    this->labels.list = nullptr;
    this->labels.size = 0;
  }
  this->labels.num = 0;
  v7 = 0;
  if ( numBars >= 4 )
  {
    v8 = 0;
    do
    {
      v7 += 4;
      p_bars->list[v8].value = 0.0;
      p_bars->list[v8 + 1].value = 0.0;
      p_bars->list[v8 + 2].value = 0.0;
      p_bars->list[v8 + 3].value = 0.0;
      v8 += 4;
    }
    while ( v7 < numBars - 3 );
  }
  if ( v7 < numBars )
  {
    v9 = v7;
    v10 = numBars - v7;
    do
    {
      p_bars->list[v9++].value = 0.0;
      --v10;
    }
    while ( v10 != 0 );
  }
}


// ========================================================================
// ??0idDebugGraph@@QAA@H@Z
// EA  : 0x82671468
// RVA : 0x00671468
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

idDebugGraph *__fastcall idDebugGraph::idDebugGraph(idDebugGraph *this, int numItems)
{
  this->bgColor.r = 0.0;
  this->bgColor.g = 0.0;
  this->bgColor.b = 0.0;
  this->bgColor.a = 0.5;
  this->fontColor.r = 1.0;
  this->fontColor.g = 1.0;
  this->fontColor.b = 1.0;
  this->fontColor.a = 1.0;
  this->mode = GRAPH_FILL;
  this->border = 0.0;
  this->sideways = false;
  this->position.x = 100.0;
  this->position.y = 100.0;
  this->position.z = 100.0;
  this->position.w = 100.0;
  this->enable = true;
  this->caption.allocedAndFlag = 20;
  this->caption.data = this->caption.baseBuffer;
  this->caption.len = 0;
  this->caption.baseBuffer[0] = 0;
  this->bars.list = nullptr;
  this->bars.granularity = 0;
  this->bars.memTag = 3;
  this->bars.listStatic = 0;
  this->bars.size = 0;
  this->bars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bars);
  this->grid.list = nullptr;
  this->grid.granularity = 0;
  this->grid.memTag = 3;
  this->grid.listStatic = 0;
  this->grid.size = 0;
  this->grid.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->grid);
  this->labels.granularity = 0;
  this->labels.memTag = 3;
  this->labels.listStatic = 0;
  this->labels.list = nullptr;
  this->labels.size = 0;
  this->labels.num = 0;
  this->white = nullptr;
  this->capPos = CAP_NONE;
  idDebugGraph::Init(this, numBars: numItems);
  return this;
}


// ========================================================================
// __unwind$220361
// EA  : 0x826715A4
// RVA : 0x006715A4
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void _unwind_220361()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 68));
}


// ========================================================================
// __unwind$220362
// EA  : 0x826715D0
// RVA : 0x006715D0
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void _unwind_220362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 104));
}


// ========================================================================
// __unwind$220363
// EA  : 0x826715FC
// RVA : 0x006715FC
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void _unwind_220363()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 120));
}


// ========================================================================
// __unwind$220364
// EA  : 0x82671628
// RVA : 0x00671628
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void _unwind_220364()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 136));
}


// ========================================================================
// ?AddGridLine@idDebugGraph@@QAAXMABVidColor@@@Z
// EA  : 0x82671658
// RVA : 0x00671658
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void __fastcall idDebugGraph::AddGridLine(idDebugGraph *this, double value, const idColor *color, idColor *a4)
{
  idDebugGraph::graphPlot_t *v7; // r31

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v7 = idList<idDebugGraph::graphPlot_t,3>::Alloc(this: &this->grid);
  idMem::PopHeap(this: &mem);
  v7->value = value;
  v7->color = *a4;
}


// ========================================================================
// ?SetValue@idDebugGraph@@QAAXHMABVidColor@@@Z
// EA  : 0x826716D0
// RVA : 0x006716D0
// PDB : w:\tech5\engine\framework\debuggraph.cpp
// ========================================================================

void __fastcall idDebugGraph::SetValue(idDebugGraph *this, int b, double value, const idColor *color, float *a5)
{
  double v6; // fp31
  double v8; // fp0
  idList<idDebugGraph::graphPlot_t,3> *p_bars; // r30
  idDebugGraph::graphPlot_t *v10; // r30
  idDebugGraph::graphPlot_t *v11; // r11

  v6 = value;
  if ( this->enable )
  {
    if ( this->clamp )
    {
      v8 = 0.0;
      if ( value < 0.0 || (v8 = 1.0, value > 1.0) )
        v6 = v8;
    }
    if ( b >= 0 )
    {
      this->bars.list[b].value = v6;
      v11 = &this->bars.list[b];
      v11->color.r = *a5;
      v11->color.g = a5[1];
      v11->color.b = a5[2];
      v11->color.a = a5[3];
    }
    else
    {
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      p_bars = &this->bars;
      idList<idDebugGraph::graphPlot_t,3>::RemoveIndex(this: p_bars, index: 0);
      v10 = idList<idDebugGraph::graphPlot_t,3>::Alloc(this: p_bars);
      idMem::PopHeap(this: &mem);
      v10->value = v6;
      v10->color = *(idColor *)a5;
    }
  }
}

