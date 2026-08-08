
// ========================================================================
// ?IsKeyUpAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A6A8
// RVA : 0x00A4A6A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyUpAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 200 )
    return 1;
  v2 = actionKey == 282;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyDownAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A6C8
// RVA : 0x00A4A6C8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyDownAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 208 )
    return 1;
  v2 = actionKey == 283;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyRightAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A6E8
// RVA : 0x00A4A6E8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyRightAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 205 )
    return 1;
  v2 = actionKey == 285;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyLeftAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A708
// RVA : 0x00A4A708
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyLeftAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 203 )
    return 1;
  v2 = actionKey == 284;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyEnterAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A728
// RVA : 0x00A4A728
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyEnterAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 28 )
    return 1;
  if ( actionKey == 156 )
    return 1;
  v2 = actionKey == 256;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyIncrementAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A750
// RVA : 0x00A4A750
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyIncrementAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 201 )
    return 1;
  v2 = actionKey == 259;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?IsKeyDecrementAction@idGuiKeyUtils@@SA_NH@Z
// EA  : 0x82A4A770
// RVA : 0x00A4A770
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiKeyUtils::IsKeyDecrementAction(const int actionKey)
{
  int result; // r3
  bool v2; // zf

  if ( actionKey == 209 )
    return 1;
  v2 = actionKey == 258;
  result = 0;
  if ( v2 )
    return 1;
  return result;
}


// ========================================================================
// ?GetRenderedPostion@idGuiPage@@QAAXAAM0@Z
// EA  : 0x82A4A790
// RVA : 0x00A4A790
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage::GetRenderedPostion(idGuiPage *this, float *xPos, float *yPos)
{
  *xPos = this->renderX;
  *yPos = this->renderY;
}


// ========================================================================
// ??1widget_t@@UAA@XZ
// EA  : 0x82A4A7A8
// RVA : 0x00A4A7A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall widget_t::~widget_t(widget_t *this)
{
  this->__vftable = (widget_t_vtbl *)&widget_t::`vftable';
}


// ========================================================================
// ?Color@idGuiListBox@@QAAAAV1@ABVidColor@@@Z
// EA  : 0x82A4A7B8
// RVA : 0x00A4A7B8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::Color(idGuiListBox *this, const idColor *color)
{
  this->currentColor = *color;
  return this;
}


// ========================================================================
// ?BackGroundColor@idGuiListBox@@QAAAAV1@ABVidColor@@@Z
// EA  : 0x82A4A7E0
// RVA : 0x00A4A7E0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::BackGroundColor(idGuiListBox *this, const idColor *color)
{
  this->backGroundColor = *color;
  return this;
}


// ========================================================================
// ?CalcWidgetColor@idGuiListBox@@AAA?AVidColor@@H@Z
// EA  : 0x82A4A808
// RVA : 0x00A4A808
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::CalcWidgetColor(idGuiListBox *this, idColor *result, int row)
{
  float g; // r9
  int b_low; // r8
  int a_low; // r7
  float b; // r6
  float v7; // r10
  int v8; // r8
  int v9; // r7
  float v10; // r10
  int v11; // r8
  int v12; // r7

  g = result[5].g;
  b_low = LODWORD(result[5].b);
  a_low = LODWORD(result[5].a);
  b = result[1].b;
  this->__vftable = (idGuiListBox_vtbl *)LODWORD(result[5].r);
  *(float *)&this->skipMaxColumnSizeCheck = g;
  this->tabNum = b_low;
  this->selectedRow = a_low;
  if ( row == LODWORD(b) )
  {
    v7 = result[7].g;
    v8 = LODWORD(result[7].b);
    v9 = LODWORD(result[7].a);
    this->__vftable = (idGuiListBox_vtbl *)LODWORD(result[7].r);
    *(float *)&this->skipMaxColumnSizeCheck = v7;
    this->tabNum = v8;
    this->selectedRow = v9;
  }
  else if ( row == LODWORD(result->a) && LODWORD(result[1].g) == LODWORD(result->b) )
  {
    v10 = result[6].g;
    v11 = LODWORD(result[6].b);
    v12 = LODWORD(result[6].a);
    this->__vftable = (idGuiListBox_vtbl *)LODWORD(result[6].r);
    *(float *)&this->skipMaxColumnSizeCheck = v10;
    this->tabNum = v11;
    this->selectedRow = v12;
  }
  return this;
}


// ========================================================================
// ?SetRenderPosition@idGuiListBox@@QAAXMM@Z
// EA  : 0x82A4A8A8
// RVA : 0x00A4A8A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiListBox::SetRenderPosition(idGuiListBox *this, double xPos, double yPos)
{
  this->desiredRenderX = xPos;
  this->desiredRenderY = yPos;
}


// ========================================================================
// CalcRenderPos
// EA  : 0x82A4A8B8
// RVA : 0x00A4A8B8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall CalcRenderPos(
        idDeviceContext *context,
        unsigned int alignH,
        unsigned int alignV,
        float *xPos,
        __int64 nextTo,
        double xSize,
        double ySize,
        int a8,
        float *a9)
{
  float *v15; // r28
  double v16; // fp31
  __int64 v17; // r8
  int v18; // r5
  int v19; // r4
  double v20; // fp30
  __int64 v21; // r8
  int v22; // r5
  int v23; // r4
  __int64 v24; // r8
  int v25; // r5
  int v26; // r4
  double VirtualWidth; // fp1
  double v28; // fp0
  double VirtualHeight; // fp1
  double v30; // fp0

  v15 = (float *)HIDWORD(nextTo);
  if ( alignH != 0 )
  {
    if ( alignH == 1 )
    {
      if ( a9 != nullptr )
        *xPos = a9[12] + a9[8];
      else
        *xPos = (float)(idRenderModelGui::GetVirtualWidth(this: context->gui, a2: 1, a3: alignV, a4: nextTo)
                      / context->uiScale.x)
              - (float)xSize;
    }
    else if ( alignH < 3 )
    {
      if ( a9 != nullptr )
        *xPos = -(float)((float)((float)xSize * (float)0.5) - (float)((float)(a9[12] * (float)0.5) + a9[8]));
      else
        *xPos = (float)((float)(idRenderModelGui::GetVirtualWidth(
                                  this: context->gui,
                                  a2: alignH,
                                  a3: alignV,
                                  a4: nextTo)
                              / context->uiScale.x)
                      * (float)0.5)
              - (float)((float)xSize * (float)0.5);
    }
  }
  else if ( a9 != nullptr )
  {
    *xPos = a9[8] - (float)xSize;
  }
  else
  {
    *xPos = 0.0;
  }
  if ( alignV != 0 )
  {
    if ( alignV == 1 )
    {
      if ( a9 != nullptr )
        *v15 = a9[13] + a9[9];
      else
        *v15 = (float)(idRenderModelGui::GetVirtualHeight(this: context->gui, a2: alignH, a3: alignV, a4: nextTo)
                     / context->uiScale.y)
             - (float)ySize;
    }
    else if ( alignV < 3 )
    {
      if ( a9 != nullptr )
        *v15 = -(float)((float)((float)ySize * (float)0.5) - (float)((float)(a9[13] * (float)0.5) + a9[9]));
      else
        *v15 = (float)((float)(idRenderModelGui::GetVirtualHeight(
                                 this: context->gui,
                                 a2: alignH,
                                 a3: alignV,
                                 a4: nextTo)
                             / context->uiScale.y)
                     * (float)0.5)
             - (float)((float)ySize * (float)0.5);
    }
  }
  else if ( a9 != nullptr )
  {
    *v15 = a9[9] - (float)ySize;
  }
  else
  {
    *v15 = 0.0;
  }
  v16 = (float)(aigui_titleSafe.valueFloat
              * (float)(idRenderModelGui::GetVirtualWidth(this: context->gui, a2: alignH, a3: alignV, a4: nextTo)
                      / context->uiScale.x));
  v20 = (float)(aigui_titleSafe.valueFloat
              * (float)(idRenderModelGui::GetVirtualHeight(this: context->gui, a2: v19, a3: v18, a4: v17)
                      / context->uiScale.y));
  VirtualWidth = idRenderModelGui::GetVirtualWidth(this: context->gui, a2: v23, a3: v22, a4: v21);
  v28 = *xPos;
  if ( v28 >= v16 )
  {
    if ( v28 > (float)((float)((float)((float)VirtualWidth / context->uiScale.x) - (float)v16) - (float)xSize) )
      v28 = (float)((float)((float)((float)VirtualWidth / context->uiScale.x) - (float)v16) - (float)xSize);
  }
  else
  {
    v28 = v16;
  }
  *xPos = v28;
  VirtualHeight = idRenderModelGui::GetVirtualHeight(this: context->gui, a2: v26, a3: v25, a4: v24);
  v30 = *v15;
  if ( v30 >= v20 )
  {
    if ( v30 <= (float)((float)((float)((float)VirtualHeight / context->uiScale.y) - (float)v20) - (float)ySize) )
      *v15 = *v15;
    else
      *v15 = (float)((float)((float)VirtualHeight / context->uiScale.y) - (float)v20) - (float)ySize;
  }
  else
  {
    *v15 = v20;
  }
}


// ========================================================================
// ?HandleDefaultPageControls@idGuiPage@@IAA_NPBUsysEvent_t@@AAUidGuiPageStatus@@@Z
// EA  : 0x82A4AB28
// RVA : 0x00A4AB28
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiPage::HandleDefaultPageControls(
        idGuiPage *this,
        const sysEvent_t *event,
        idGuiPageStatus *pageStatus)
{
  int evValue; // r11
  int selectedTab; // r30
  char IsShiftDown; // r3
  signed int tabNum; // r9
  int v9; // r10
  int v10; // r7
  int v11; // r11
  int v12; // r10

  if ( event->evType != SE_KEY || event->evValue2 == 0 )
    return 0;
  evValue = event->evValue;
  if ( evValue != 15 )
  {
    if ( evValue == 200 )
    {
      --pageStatus->selectedRow;
      return 1;
    }
    if ( evValue == 208 )
    {
      ++pageStatus->selectedRow;
      return 1;
    }
    return 0;
  }
  selectedTab = pageStatus->selectedTab;
  IsShiftDown = idKeyInput::IsShiftDown(deviceNum: 0);
  tabNum = pageStatus->tabNum;
  __twllei(tabNum, 0);
  v9 = selectedTab - 1;
  if ( IsShiftDown == 0 )
    v9 = selectedTab + 1;
  v10 = __ROL4__(v9, 1) - 1;
  v11 = v9 % tabNum;
  v12 = pageStatus->selectedTab;
  __twlgei(tabNum & ~v10, 0xFFFFFFFF);
  if ( v12 != v11 )
  {
    pageStatus->selectedTab = v11;
    pageStatus->selectedRow = 0;
  }
  return 1;
}


// ========================================================================
// ?CalcWidth@cellTxt_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4AC20
// RVA : 0x00A4AC20
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall cellTxt_t::CalcWidth(cellTxt_t *this, idDeviceContext *context)
{
  double valueFloat; // fp31
  int v4; // r30
  const char *v5; // r4
  __int64 v6; // r7
  double v7; // fp1

  valueFloat = aigui_scale.valueFloat;
  v4 = idDeviceContext::TextWidth(
         this: context,
         scale: aigui_scale.valueFloat,
         text: (const char *)context,
         limit: (const unsigned __int8 *)this->text.data,
         a5: 0);
  LODWORD(v6) = v4 + idDeviceContext::TextWidth(this: context, scale: valueFloat, text: v5, limit: " ", a5: 0);
  v7 = (float)v6;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?Render@cellTxt_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4ACB0
// RVA : 0x00A4ACB0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall cellTxt_t::Render(
        cellTxt_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r10
  int v11; // r6
  const char *v12; // r5
  const idVec4 *v13; // r4

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v10 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v13,
    text: v12,
    a7: v11,
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)this->text.data);
}


// ========================================================================
// ?CalcWidth@cellValueFloat_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4ADA8
// RVA : 0x00A4ADA8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall cellValueFloat_t::CalcWidth(
        cellValueFloat_t *this,
        idDeviceContext *context,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  const char *v6; // r4
  va *v7; // r3
  double valueFloat; // fp31
  const char *v9; // r4
  int v10; // r30
  const char *v11; // r4
  __int64 v12; // r5
  double v13; // fp1
  int v15; // [sp+8h] [-1078h]
  int v16; // [sp+Ch] [-1074h]
  int v17; // [sp+10h] [-1070h]
  int v18; // [sp+14h] [-106Ch]
  int v19; // [sp+18h] [-1068h]
  int v20; // [sp+1Ch] [-1064h]
  va v21; // [sp+60h] [-1020h] BYREF

  LODWORD(a5) = &unk_821D0000;
  *(double *)((char *)&a3 + 4) = *this->value;
  v7 = va::va(this: &v21, fmt: v6, a3, a4, a5, a6: v15, a7: v16, a8: v17, a9: v18, a10: v19, a11: v20);
  valueFloat = aigui_scale.valueFloat;
  v10 = idDeviceContext::TextWidth(
          this: context,
          scale: aigui_scale.valueFloat,
          text: v9,
          limit: (const unsigned __int8 *)v7,
          a5: 0);
  LODWORD(v12) = v10 + idDeviceContext::TextWidth(this: context, scale: valueFloat, text: v11, limit: " ", a5: 0);
  v13 = (float)v12;
  return *((float *)&v13 + 1);
}


// ========================================================================
// ?Render@cellValueFloat_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4AE58
// RVA : 0x00A4AE58
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall cellValueFloat_t::Render(
        cellValueFloat_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int128 v10; // r10
  __int128 v11; // r6 OVERLAPPED
  double v12; // fp29
  va *v13; // r3
  int v14; // r6
  const char *v15; // r5
  const idVec4 *v16; // r4
  int v17; // [sp+8h] [-1098h]
  int v18; // [sp+Ch] [-1094h]
  int v19; // [sp+10h] [-1090h]
  int v20; // [sp+14h] [-108Ch]
  int v21; // [sp+18h] [-1088h]
  int v22; // [sp+1Ch] [-1084h]
  va v23; // [sp+60h] [-1040h] BYREF

  HIDWORD(v11) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  LODWORD(v10) = this->value;
  *(_QWORD *)((char *)&v10 + 4) = __PAIR64__(&unk_821D0000, HIDWORD(v11));
  *(double *)((char *)&v11 + 4) = *(float *)v10;
  v12 = (float)__SPAIR64__(&unk_821D0000, HIDWORD(v11));
  v13 = va::va(
          this: &v23,
          fmt: (const char *)DWORD1(v11),
          a3: v11,
          a4: *(__int64 *)&v10,
          a5: v10,
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v12 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v16,
    text: v15,
    a7: v14,
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)v13);
}


// ========================================================================
// ?DoEvent@cellValueFloat_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4AF00
// RVA : 0x00A4AF00
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall cellValueFloat_t::DoEvent(cellValueFloat_t *this, const sysEvent_t *evt, int flags)
{
  int evValue; // r11
  char v4; // r11
  bool v5; // zf
  int v7; // r11
  char v8; // r11

  if ( !this->selectedRow || evt->evValue2 == 0 )
    return 0;
  evValue = evt->evValue;
  if ( evValue == 205 || (v5 = evValue != 285, v4 = 0, !v5) )
    v4 = 1;
  if ( v4 != 0 )
  {
    *this->value = (float)this->stepSize + *this->value;
    return 2;
  }
  v7 = evt->evValue;
  if ( v7 == 203 || (v5 = v7 != 284, v8 = 0, !v5) )
    v8 = 1;
  if ( v8 == 0 )
    return 0;
  *this->value = *this->value - (float)this->stepSize;
  return 2;
}


// ========================================================================
// ?CalcWidth@cellCvar_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4AFB0
// RVA : 0x00A4AFB0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall cellCvar_t::CalcWidth(cellCvar_t *this, idDeviceContext *context)
{
  __int64 v2; // r8
  __int64 v3; // fp0
  double valueFloat; // fp1
  __int64 v5; // r8
  double v6; // fp1

  if ( this->hitClampedLimit )
  {
    LODWORD(v2) = idDeviceContext::TextWidth(
                    this: context,
                    scale: aigui_scale.valueFloat,
                    text: (const char *)context,
                    limit: "xxx",
                    a5: 0);
    v3 = v2;
  }
  else
  {
    valueFloat = aigui_scale.valueFloat;
    if ( this->canHoldToAdvance )
      LODWORD(v5) = idDeviceContext::TextWidth(
                      this: context,
                      scale: valueFloat,
                      text: (const char *)context,
                      limit: "+o-",
                      a5: 0);
    else
      LODWORD(v5) = idDeviceContext::TextWidth(
                      this: context,
                      scale: valueFloat,
                      text: (const char *)context,
                      limit: "+/-",
                      a5: 0);
    v3 = v5;
  }
  v6 = (float)v3;
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?Render@cellCvar_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4B060
// RVA : 0x00A4B060
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall cellCvar_t::Render(
        cellCvar_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r11
  int v11; // r6
  const char *v12; // r5
  const idVec4 *v13; // r4
  const char *v14; // r8
  idColor *p_color; // r7

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  if ( this->hitClampedLimit )
  {
    v14 = "xxx";
    p_color = &idColor::colorRed;
  }
  else
  {
    p_color = &this->color;
    if ( this->canHoldToAdvance )
      v14 = "+o-";
    else
      v14 = "+/-";
  }
  HIDWORD(v10) = this->hitClampedLimit;
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v10 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v13,
    text: v12,
    a7: v11,
    a8: (const idVec4 *)p_color,
    a9: (const unsigned __int8 *)v14);
}


// ========================================================================
// ?DoEvent@cellCvar_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4B118
// RVA : 0x00A4B118
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall cellCvar_t::DoEvent(cellCvar_t *this, const sysEvent_t *evt, int flags)
{
  int evValue; // r11
  char v6; // r11
  bool v7; // zf
  double v8; // fp1
  double maxValue; // fp0
  void (__fastcall *guiCallBack)(const bool); // r11
  double v12; // fp1
  void (__fastcall *v13)(const bool); // r11
  int v14; // r11
  char v15; // r11
  double v16; // fp1
  double minValue; // fp0
  double v18; // fp1
  void (__fastcall *v19)(const bool); // r11

  if ( evt->evValue2 != 0 )
  {
    evValue = evt->evValue;
    if ( evValue == 201 || (v7 = evValue != 259, v6 = 0, !v7) )
      v6 = 1;
    if ( v6 != 0 )
    {
      v8 = ((double (__fastcall *)(idCVarSystem *, char *, double))cvarSystem->GetCVarFloat)(
             a1: cvarSystem,
             a2: this->cvarName.data,
             a3: 0.0);
      maxValue = this->maxValue;
      if ( v8 == maxValue )
      {
LABEL_7:
        guiCallBack = this->guiCallBack;
        this->hitClampedLimit = true;
        if ( guiCallBack != nullptr )
          guiCallBack(a1: true);
        return 0;
      }
      if ( v8 < maxValue )
      {
        v12 = (float)(this->delta + (float)v8);
        if ( v12 > maxValue )
          v12 = this->maxValue;
        ((void (__fastcall *)(idCVarSystem *, char *, double))cvarSystem->SetCVarFloat)(
          a1: cvarSystem,
          a2: this->cvarName.data,
          a3: v12);
        v13 = this->guiCallBack;
        if ( v13 != nullptr )
          v13(a1: false);
        return 2;
      }
    }
  }
  if ( evt->evValue2 == 0 )
    return 0;
  v14 = evt->evValue;
  if ( v14 == 209 || (v7 = v14 != 258, v15 = 0, !v7) )
    v15 = 1;
  if ( v15 == 0 )
    return 0;
  v16 = ((double (__fastcall *)(idCVarSystem *, char *, double))cvarSystem->GetCVarFloat)(
          a1: cvarSystem,
          a2: this->cvarName.data,
          a3: 0.0);
  minValue = this->minValue;
  if ( v16 == minValue )
    goto LABEL_7;
  if ( v16 <= minValue )
    return 0;
  v18 = (float)((float)v16 - this->delta);
  if ( v18 < minValue )
    v18 = this->minValue;
  ((void (__fastcall *)(idCVarSystem *, char *, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: this->cvarName.data,
    a3: v18);
  v19 = this->guiCallBack;
  if ( v19 == nullptr )
    return 2;
  v19(a1: false);
  return 2;
}


// ========================================================================
// ?DoEvent@cellCmd_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4B368
// RVA : 0x00A4B368
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall cellCmd_t::DoEvent(cellCmd_t *this, const sysEvent_t *evt, int flags)
{
  int evValue; // r11
  char v5; // r11
  bool v6; // zf

  if ( !this->selectedRow || evt->evValue2 == 0 )
    return 0;
  evValue = evt->evValue;
  if ( evValue == 28 || evValue == 156 || (v6 = evValue != 256, v5 = 0, !v6) )
    v5 = 1;
  if ( v5 == 0 )
    return 0;
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: this->cmdText.data);
  idLib::Printf(fmt: "DevGUI Command: %s\n", this->cmdText.data);
  return 2;
}


// ========================================================================
// ?Render@drawCheckMark_bool_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4B4A0
// RVA : 0x00A4B4A0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall drawCheckMark_bool_t::Render(
        drawCheckMark_bool_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r11
  int v11; // r6
  const char *v12; // r5
  const idVec4 *v13; // r4
  const char *v14; // r8

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  if ( this->checked )
    v14 = "[X]";
  else
    v14 = "[ ]";
  HIDWORD(v10) = this->checked;
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v10 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v13,
    text: v12,
    a7: v11,
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)v14);
}


// ========================================================================
// ?CalcWidth@nextPageMarker_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4B538
// RVA : 0x00A4B538
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall nextPageMarker_t::CalcWidth(nextPageMarker_t *this, idDeviceContext *context)
{
  __int64 v2; // r8
  double v3; // fp1

  LODWORD(v2) = idDeviceContext::TextWidth(
                  this: context,
                  scale: aigui_scale.valueFloat,
                  text: (const char *)context,
                  limit: ">>>",
                  a5: 0);
  v3 = (float)v2;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?Render@nextPageMarker_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4B588
// RVA : 0x00A4B588
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall nextPageMarker_t::Render(
        nextPageMarker_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  int v10; // r6
  const char *v11; // r5
  const idVec4 *v12; // r4
  __int64 v13; // [sp+50h] [-40h]

  v13 = __PAIR64__("ound traces", idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat));
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v13 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v12,
    text: v11,
    a7: v10,
    a8: (const idVec4 *)&this->color,
    a9: ">>>");
}


// ========================================================================
// ?Render@checkBox_bool_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4B608
// RVA : 0x00A4B608
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall checkBox_bool_t::Render(
        checkBox_bool_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r11
  double v11; // fp29
  double v12; // fp28
  const idVec4 *v13; // r4
  double v14; // fp1
  bool *checked; // r6
  double v16; // fp27
  const char *v17; // r8
  __int64 v18; // r10
  double v19; // fp0
  double v20; // fp0

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  HIDWORD(v10) = this->__vftable;
  v11 = (float)v10;
  v12 = ((double (__fastcall *)(checkBox_bool_t *, idDeviceContext *))this->CalcWidth)(a1: this, a2: context);
  v14 = ((double (__fastcall *)(checkBox_bool_t *, idDeviceContext *))this->CalcHeight)(a1: this, a2: context);
  checked = this->checked;
  v16 = v14;
  if ( *checked )
    v17 = "[X]";
  else
    v17 = "[ ]";
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v11 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v13,
    text: (const char *)*checked,
    a7: (int)checked,
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)v17);
  LODWORD(v18) = idAIGUI::mouseX;
  v19 = (float)v18;
  if ( v19 >= xPos && v19 <= (float)((float)v12 + (float)xPos) )
  {
    LODWORD(v18) = idAIGUI::mouseY;
    v20 = (float)v18;
    if ( v20 >= yPos && v20 <= (float)((float)v16 + (float)yPos) )
      this->mouseOnWidget = true;
  }
}


// ========================================================================
// ?DoEvent@checkBox_bool_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4B740
// RVA : 0x00A4B740
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall checkBox_bool_t::DoEvent(checkBox_bool_t *this, const sysEvent_t *evt, int flags)
{
  int evValue; // r11
  char v4; // r11
  bool v5; // zf

  if ( !this->selectedRow || evt->evValue2 == 0 )
    goto LABEL_12;
  evValue = evt->evValue;
  if ( evValue == 28 || evValue == 156 || (v5 = evValue != 256, v4 = 0, !v5) )
    v4 = 1;
  if ( v4 == 0 )
  {
LABEL_12:
    if ( evt->evType != SE_KEY || evt->evValue2 == 0 || !this->mouseOnWidget || evt->evValue != 286 )
      return 0;
  }
  *this->checked = (_cntlzw(*(unsigned __int8 *)this->checked) & 0x20) != 0;
  return 2;
}


// ========================================================================
// ?CalcWidth@drawCheckMark_bool_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4B7E0
// RVA : 0x00A4B7E0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall drawCheckMark_bool_t::CalcWidth(checkBox_bitflag_t *this, idDeviceContext *context)
{
  __int64 v2; // r8
  double v3; // fp1

  LODWORD(v2) = idDeviceContext::TextWidth(
                  this: context,
                  scale: aigui_scale.valueFloat,
                  text: (const char *)context,
                  limit: "[X]",
                  a5: 0);
  v3 = (float)v2;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?Render@checkBox_bitflag_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4B830
// RVA : 0x00A4B830
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall checkBox_bitflag_t::Render(
        checkBox_bitflag_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r11
  double v11; // fp29
  double v12; // fp28
  double v13; // fp1
  int *bitfield; // r6
  const char *bit; // r5
  double v16; // fp27
  const char *v17; // r8
  __int64 v18; // r10
  double v19; // fp0
  double v20; // fp0

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  HIDWORD(v10) = this->__vftable;
  v11 = (float)v10;
  v12 = ((double (__fastcall *)(checkBox_bitflag_t *, idDeviceContext *))this->CalcWidth)(a1: this, a2: context);
  v13 = ((double (__fastcall *)(checkBox_bitflag_t *, idDeviceContext *))this->CalcHeight)(a1: this, a2: context);
  bitfield = this->bitfield;
  bit = (const char *)this->bit;
  v16 = v13;
  if ( ((1 << (char)bit) & *bitfield) != 0 )
    v17 = "[X]";
  else
    v17 = "[ ]";
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v11 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: (const idVec4 *)(1 << (char)bit),
    text: bit,
    a7: (int)bitfield,
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)v17);
  LODWORD(v18) = idAIGUI::mouseX;
  v19 = (float)v18;
  if ( v19 >= xPos && v19 <= (float)((float)v12 + (float)xPos) )
  {
    LODWORD(v18) = idAIGUI::mouseY;
    v20 = (float)v18;
    if ( v20 >= yPos && v20 <= (float)((float)v16 + (float)yPos) )
      this->mouseOnWidget = true;
  }
}


// ========================================================================
// ?DoEvent@checkBox_bitflag_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4B978
// RVA : 0x00A4B978
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall checkBox_bitflag_t::DoEvent(checkBox_bitflag_t *this, const sysEvent_t *evt, int flags)
{
  int evValue; // r11
  char v4; // r11
  bool v5; // zf
  int v6; // r11
  int v7; // r9
  int v8; // r8

  if ( !this->selectedRow || evt->evValue2 == 0 )
    goto LABEL_14;
  evValue = evt->evValue;
  if ( evValue == 28 || evValue == 156 || (v5 = evValue != 256, v4 = 0, !v5) )
    v4 = 1;
  if ( v4 == 0 )
  {
LABEL_14:
    if ( evt->evType != SE_KEY || evt->evValue2 == 0 || !this->mouseOnWidget || evt->evValue < 286 )
      return 0;
  }
  v6 = 1 << this->bit;
  v7 = *this->bitfield;
  v8 = v7 & ~v6;
  if ( (v7 & v6) == 0 )
    v8 = v7 | v6;
  *this->bitfield = v8;
  return 2;
}


// ========================================================================
// ?CalcWidth@comboBox_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4BA38
// RVA : 0x00A4BA38
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall comboBox_t::CalcWidth(comboBox_t *this, idDeviceContext *context)
{
  double valueFloat; // fp31
  int v4; // r30
  __int64 v5; // r11
  double v6; // fp1

  valueFloat = aigui_scale.valueFloat;
  v4 = idDeviceContext::TextWidth(
         this: context,
         scale: aigui_scale.valueFloat,
         text: (const char *)context,
         limit: (const unsigned __int8 *)this->comboItems[*this->comboItemIndex],
         a5: 0);
  LODWORD(v5) = v4
              + idDeviceContext::TextWidth(this: context, scale: valueFloat, text: byte_821B0000, limit: " ", a5: 0);
  v6 = (float)v5;
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?CalcHeight@comboBoxCvar_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4BAD8
// RVA : 0x00A4BAD8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall comboBoxCvar_t::CalcHeight(comboBoxCvar_t *this, idDeviceContext *context)
{
  __int64 v2; // r9
  double v3; // fp1

  LODWORD(v2) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  v3 = (float)v2;
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?Render@comboBox_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4BB20
// RVA : 0x00A4BB20
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall comboBox_t::Render(
        comboBox_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r10
  const idVec4 *v11; // r4

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  HIDWORD(v10) = this->comboItemIndex;
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v10 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v11,
    text: (const char *)(4 * *(_DWORD *)HIDWORD(v10)),
    a7: *(_DWORD *)HIDWORD(v10),
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)this->comboItems[*(_DWORD *)HIDWORD(v10)]);
}


// ========================================================================
// ?DoEvent@comboBox_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4BBA8
// RVA : 0x00A4BBA8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

widget_t::actionResult_t __fastcall comboBox_t::DoEvent(comboBox_t *this, const sysEvent_t *evt, int flags)
{
  BOOL selectedRow; // r11
  widget_t::actionResult_t result; // r3
  int evValue; // r11
  char v7; // r11
  bool v8; // zf
  int *comboItemIndex; // r9
  int v10; // r8
  int v11; // r11
  char v12; // r11
  int *v13; // r11
  int v14; // r9
  int v15; // r10

  selectedRow = this->selectedRow;
  result = ACTION_IGNORED;
  if ( selectedRow && evt->evValue2 != 0 )
  {
    evValue = evt->evValue;
    if ( evValue == 205 || (v8 = evValue != 285, v7 = 0, !v8) )
      v7 = 1;
    if ( v7 != 0 )
    {
      comboItemIndex = this->comboItemIndex;
      v10 = *comboItemIndex + 1;
LABEL_13:
      *comboItemIndex = v10;
      result = ACTION_HANDLED;
      goto LABEL_14;
    }
    v11 = evt->evValue;
    if ( v11 == 203 || (v8 = v11 != 284, v12 = 0, !v8) )
      v12 = 1;
    if ( v12 != 0 )
    {
      comboItemIndex = this->comboItemIndex;
      v10 = *comboItemIndex - 1;
      goto LABEL_13;
    }
  }
LABEL_14:
  v13 = this->comboItemIndex;
  v14 = this->comboItemNum - 1;
  v15 = *v13;
  if ( *v13 < 0 )
  {
    v15 = 0;
LABEL_16:
    *v13 = v15;
    return result;
  }
  if ( v15 <= v14 )
    goto LABEL_16;
  *v13 = v14;
  return result;
}


// ========================================================================
// ?CalcWidth@comboBoxCvar_t@@UAAMAAVidDeviceContext@@@Z
// EA  : 0x82A4BCD0
// RVA : 0x00A4BCD0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

float __fastcall comboBoxCvar_t::CalcWidth(comboBoxCvar_t *this, idDeviceContext *context)
{
  double valueFloat; // fp31
  int v4; // r30
  const char *v5; // r4
  __int64 v6; // r4
  double v7; // fp1

  valueFloat = aigui_scale.valueFloat;
  v4 = idDeviceContext::TextWidth(
         this: context,
         scale: aigui_scale.valueFloat,
         text: (const char *)context,
         limit: (const unsigned __int8 *)this->comboItems[this->comboItemIndex],
         a5: 0);
  HIDWORD(v6) = idDeviceContext::TextWidth(this: context, scale: valueFloat, text: v5, limit: " ", a5: 0);
  LODWORD(v6) = v4 + HIDWORD(v6);
  v7 = (float)v6;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?Render@comboBoxCvar_t@@UAAXAAVidDeviceContext@@MMMM@Z
// EA  : 0x82A4BD68
// RVA : 0x00A4BD68
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall comboBoxCvar_t::Render(
        comboBoxCvar_t *this,
        idDeviceContext *context,
        double xPos,
        double yPos,
        double tableWidth,
        double tableHeight)
{
  __int64 v10; // r10
  const char *v11; // r5
  const idVec4 *v12; // r4

  LODWORD(v10) = idDeviceContext::TextHeight(this: context, scale: aigui_scale.valueFloat);
  HIDWORD(v10) = this->comboItemIndex;
  idDeviceContext::DrawTextA(
    this: context,
    x: xPos,
    y: (float)((float)v10 + (float)yPos),
    scale: aigui_scale.valueFloat,
    color: v12,
    text: v11,
    a7: 4 * HIDWORD(v10),
    a8: (const idVec4 *)&this->color,
    a9: (const unsigned __int8 *)this->comboItems[HIDWORD(v10)]);
}


// ========================================================================
// ?DoEvent@comboBoxCvar_t@@UAA?AW4actionResult_t@widget_t@@ABUsysEvent_t@@H@Z
// EA  : 0x82A4BDF0
// RVA : 0x00A4BDF0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

widget_t::actionResult_t __fastcall comboBoxCvar_t::DoEvent(comboBoxCvar_t *this, const sysEvent_t *evt, int flags)
{
  BOOL selectedRow; // r11
  widget_t::actionResult_t result; // r3
  int evValue; // r11
  char v7; // r11
  bool v8; // zf
  int v9; // r11
  int v10; // r11
  char v11; // r11
  int v12; // r4

  selectedRow = this->selectedRow;
  result = ACTION_IGNORED;
  if ( !selectedRow || evt->evValue2 == 0 )
    return result;
  evValue = evt->evValue;
  if ( evValue == 205 || (v8 = evValue != 285, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 != 0 )
  {
    v9 = this->comboItemIndex + 1;
LABEL_13:
    this->comboItemIndex = v9;
    v12 = this->comboItemNum - 1;
    if ( v9 >= 0 )
    {
      if ( v9 <= v12 )
        v12 = v9;
    }
    else
    {
      v12 = 0;
    }
    this->comboItemIndex = v12;
    idCVar::SetInteger(this: this->comboCvar, newValue: v12, force: true);
    return ACTION_HANDLED;
  }
  v10 = evt->evValue;
  if ( v10 == 203 || (v8 = v10 != 284, v11 = 0, !v8) )
    v11 = 1;
  if ( v11 != 0 )
  {
    v9 = this->comboItemIndex - 1;
    goto LABEL_13;
  }
  return result;
}


// ========================================================================
// ?HandleEventQueue@idGuiListBox@@AAAXABV?$idList@UsysEvent_t@@$04@@@Z
// EA  : 0x82A4BEE8
// RVA : 0x00A4BEE8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiListBox::HandleEventQueue(idGuiListBox *this, const idList<sysEvent_t,5> *queue)
{
  int v4; // r23
  int v5; // r27
  int v6; // r25
  int v7; // r29
  int v8; // r28
  int v9; // r30
  widget_t *v10; // r3

  v4 = 0;
  if ( queue->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = 0;
      if ( this->rows.num > 0 )
      {
        v7 = 0;
        do
        {
          v8 = 0;
          if ( this->rows.list[v7].cells.num > 0 )
          {
            v9 = 0;
            do
            {
              v10 = this->rows.list[v7].cells.list[v9];
              if ( v10->DoEvent(this: v10, a2: &queue->list[v5], a3: 0) == ACTION_HANDLED_STATECHANGED )
                this->entityStateChanged = true;
              ++v8;
              ++v9;
            }
            while ( v8 < this->rows.list[v7].cells.num );
          }
          ++v6;
          ++v7;
        }
        while ( v6 < this->rows.num );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < queue->num );
  }
}


// ========================================================================
// ??0idGuiPage@@QAA@ABVidStr@@@Z
// EA  : 0x82A4C1B0
// RVA : 0x00A4C1B0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage *__fastcall idGuiPage::idGuiPage(idGuiPage *this, const idStr *name)
{
  this->isActive = false;
  this->__vftable = (idGuiPage_vtbl *)&idGuiPage::`vftable';
  this->eventQueue.list = nullptr;
  this->eventQueue.granularity = 0;
  this->eventQueue.memTag = 5;
  this->eventQueue.listStatic = 0;
  this->eventQueue.size = 0;
  this->eventQueue.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventQueue);
  this->renderX = 0.0;
  this->renderY = 0.0;
  idStr::idStr(this: (idStr *)&this->pageName, text: name);
  return this;
}


// ========================================================================
// __unwind$496218
// EA  : 0x82A4C22C
// RVA : 0x00A4C22C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496218()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??1idGuiPage@@UAA@XZ
// EA  : 0x82A4C268
// RVA : 0x00A4C268
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage::~idGuiPage(idGuiPage *this)
{
  this->__vftable = (idGuiPage_vtbl *)&idGuiPage::`vftable';
  idStr::FreeData(this: (idStr *)&this->pageName);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventQueue);
}


// ========================================================================
// __unwind$496251
// EA  : 0x82A4C2BC
// RVA : 0x00A4C2BC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496251()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?Render@idGuiListBox@@QAAXPBVidGuiPage@@AAVidDeviceContext@@W4alignH_t@@W4alignV_t@@PAV1@@Z
// EA  : 0x82A4C2F0
// RVA : 0x00A4C2F0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiListBox::Render(
        idGuiListBox *this,
        const idGuiPage *page,
        idDeviceContext *context,
        unsigned int hAlign,
        unsigned int vAlign,
        idGuiListBox *nextTo)
{
  int num; // r4
  float v13; // r11
  int maxRowsToDisplay; // r10
  double v15; // fp31
  double v16; // fp24
  idGuiListBox::row_t *v17; // r25
  int v18; // r5
  unsigned int v19; // r3
  __int64 v20; // r8
  int selectedRow; // r6
  idGuiListBox::row_t *list; // r9
  int v23; // r19
  int v24; // r17
  int v25; // r11
  idGuiListBox::row_t *v26; // r10
  int v27; // ctr
  idGuiListBox::row_t *v28; // r10
  float *v29; // r16
  int v30; // r10
  int v31; // r28
  float *v32; // r26
  int v33; // r24
  float v34; // r4
  int v36; // r27
  int v37; // r29
  widget_t *v38; // r3
  double v39; // fp31
  widget_t *v40; // r3
  double v41; // fp1
  int v47; // ctr
  float *v48; // r11
  double desiredRenderY; // fp13
  double v50; // fp25
  double v51; // fp28
  double v52; // fp1
  int v53; // r7
  int v54; // r6
  int v55; // r5
  const idVec4 *v56; // r4
  int v57; // r8
  idGuiListBox::row_t *v58; // r7
  BOOL entityStateChanged; // r6
  int v60; // r5
  int v61; // r4
  double v62; // fp30
  int v63; // r26
  int v64; // r28
  float *v65; // r25
  double v66; // fp29
  double v67; // fp27
  int v68; // r27
  int v69; // r29
  widget_t *v70; // r3
  double dividerWidth; // fp4
  double v72; // fp2
  widget_t *v73; // r3
  double borderWidth; // fp5
  int v75; // [sp+50h] [-210h] BYREF
  float desiredRenderX; // [sp+54h] [-20Ch] BYREF
  idList<float,32> v77; // [sp+60h] [-200h] BYREF
  idList<float,32> v78; // [sp+70h] [-1F0h] BYREF
  int v79; // [sp+80h] [-1E0h] BYREF

  if ( this->rows.num != 0 )
  {
    this->rendered = true;
    *(_QWORD *)&v78.num = 64;
    v78.list = (float *)&v79;
    *(_DWORD *)&v78.granularity = 66817;
    memset(&v77, 0, 14);
    *(_WORD *)&v77.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v77);
    num = this->rows.num;
    *(float *)&v75 = 0.0;
    idList<float,17>::SetNum(this: &v77, newNum: num, initValue: (float *)&v75);
    v13 = *(float *)&this->rows.num;
    maxRowsToDisplay = this->maxRowsToDisplay;
    v15 = 0.0;
    v16 = 0.0;
    v17 = nullptr;
    v18 = maxRowsToDisplay - LODWORD(v13);
    *(float *)&v75 = v13;
    v19 = (LODWORD(v13) == maxRowsToDisplay) + ((unsigned int)(LODWORD(v13) - maxRowsToDisplay) >> 31) - 1;
    LODWORD(v20) = v19 & (LODWORD(v13) - maxRowsToDisplay);
    selectedRow = this->selectedRow;
    list = (idGuiListBox::row_t *)(selectedRow - maxRowsToDisplay / 2);
    if ( (int)list >= 0 )
    {
      v23 = v19 & (LODWORD(v13) - maxRowsToDisplay);
      if ( (int)list <= (int)v20 )
        v23 = selectedRow - maxRowsToDisplay / 2;
    }
    else
    {
      v23 = 0;
    }
    v24 = maxRowsToDisplay + v23;
    if ( maxRowsToDisplay + v23 >= SLODWORD(v13) )
      v24 = LODWORD(v13);
    if ( v23 < v24 )
    {
      LODWORD(v20) = v24 - v23;
      list = this->rows.list;
      v25 = v23;
      v26 = &list[v23];
      v27 = v24 - v23;
      do
      {
        v28 = (idGuiListBox::row_t *)v26->cells.num;
        if ( (int)v17 <= (int)v28 )
          v17 = v28;
        v26 = &list[++v25];
        --v27;
      }
      while ( v27 != 0 );
    }
    v29 = v77.list;
    if ( v23 < v24 )
    {
      v30 = v78.num;
      v31 = v23;
      v32 = &v77.list[v23];
      v33 = v24 - v23;
      do
      {
        v75 = this->rows.list[v31].cells.num;
        v34 = *(float *)&v75;
        if ( v30 < v75 )
        {
          *(float *)&v75 = 0.0;
          desiredRenderX = v34;
          idList<float,17>::SetNum(this: &v78, newNum: SLODWORD(v34), initValue: (float *)&v75);
          v30 = v78.num;
        }
        _FP30 = 0.0;
        v36 = 0;
        list = (idGuiListBox::row_t *)this->rows.list[v31].cells.num;
        if ( (int)list > 0 )
        {
          v37 = 0;
          do
          {
            v38 = this->rows.list[v31].cells.list[v37];
            v39 = ((double (__fastcall *)(widget_t *, idDeviceContext *, int))v38->CalcHeight)(
                    a1: v38,
                    a2: context,
                    a3: v18);
            v40 = this->rows.list[v31].cells.list[v37];
            v40->CalcWidth(this: v40, a2: context);
            _FP13 = (float)((float)_FP30 - (float)v39);
            _FP12 = (float)(*v32 - (float)v39);
            __asm
            {
              fsel      f30, f13, f30, f31
              fsel      f11, f12, f0, f31
            }
            *v32 = _FP11;
            list = (idGuiListBox::row_t *)this->rows.list[v31].cells.num;
            if ( list == v17 || this->skipMaxColumnSizeCheck )
            {
              _FP13 = (float)(v78.list[v37] - (float)v41);
              __asm { fsel      f12, f13, f0, f1 }
              v78.list[v37] = _FP12;
            }
            ++v36;
            ++v37;
          }
          while ( v36 < this->rows.list[v31].cells.num );
          v30 = v78.num;
        }
        v15 = 0.0;
        if ( v30 > 0 )
        {
          v47 = v30;
          v48 = v78.list - 1;
          do
          {
            v15 = (float)(*++v48 + (float)v15);
            --v47;
          }
          while ( v47 != 0 );
        }
        --v33;
        v16 = (float)((float)_FP30 + (float)v16);
        ++v32;
        ++v31;
      }
      while ( v33 != 0 );
    }
    desiredRenderY = this->desiredRenderY;
    HIDWORD(v20) = &v75;
    desiredRenderX = this->desiredRenderX;
    *(float *)&v75 = desiredRenderY;
    CalcRenderPos(
      context,
      alignH: hAlign,
      alignV: vAlign,
      xPos: &desiredRenderX,
      nextTo: v20,
      xSize: v15,
      ySize: v16,
      a8: (int)list,
      a9: (float *)nextTo);
    this->renderWidth = v15;
    this->renderHeight = v16;
    v50 = desiredRenderX;
    v51 = *(float *)&v75;
    v52 = desiredRenderX;
    this->renderX = desiredRenderX;
    this->renderY = v51;
    idDeviceContext::DrawFilledRect(
      this: context,
      x: v52,
      y: v51,
      w: v15,
      h: v16,
      color: v56,
      a7: v55,
      a8: v54,
      a9: v53,
      a10: (const idVec4 *)&this->backGroundColor);
    if ( this->borderWidth <= 0.0 )
      v62 = 0.0;
    else
      v62 = (float)(this->borderWidth + (float)1.0);
    v63 = v23;
    if ( v23 < v24 )
    {
      v64 = v23;
      v65 = &v29[v23 - 1];
      do
      {
        v66 = v50;
        v67 = 0.0;
        v68 = 0;
        if ( this->rows.list[v64].cells.num > 0 )
        {
          v69 = 0;
          do
          {
            v70 = this->rows.list[v64].cells.list[v69];
            v70->Render(this: v70, a2: context, a3: (float)((float)v66 + (float)v62), a4: v51, a5: v15, a6: v16);
            v58 = this->rows.list;
            dividerWidth = this->dividerWidth;
            entityStateChanged = this->entityStateChanged;
            v60 = (int)v58[v64].cells.list;
            v61 = *(_DWORD *)(v60 + v69 * 4);
            this->entityStateChanged = (_cntlzw(*(_DWORD *)(v61 + 4) - 2) & 0x20) != 0 || entityStateChanged;
            if ( dividerWidth > 0.0 && v63 > v23 )
            {
              v72 = (float)((float)v51 + (float)6.0);
              if ( v67 != v72 )
              {
                v67 = (float)((float)v51 + (float)6.0);
                idDeviceContext::DrawFilledRect(
                  this: context,
                  x: v50,
                  y: v72,
                  w: (float)((float)v62 + (float)v15),
                  h: dividerWidth,
                  color: (const idVec4 *)v61,
                  a7: v60,
                  a8: entityStateChanged,
                  a9: (int)v58,
                  a10: (const idVec4 *)&this->dividerColor);
              }
            }
            if ( v78.list[v69] == 0.0 )
            {
              v73 = this->rows.list[v64].cells.list[v69];
              v66 = (float)(v73->CalcWidth(this: v73, a2: context) + (float)v66);
            }
            else
            {
              v66 = (float)(v78.list[v69] + (float)v66);
            }
            ++v68;
            ++v69;
          }
          while ( v68 < this->rows.list[v64].cells.num );
        }
        ++v63;
        v51 = (float)(*++v65 + (float)v51);
        ++v64;
      }
      while ( v63 < v24 );
    }
    borderWidth = this->borderWidth;
    if ( borderWidth > 0.0 )
      idDeviceContext::DrawRect(
        this: context,
        x: this->renderX,
        y: this->renderY,
        w: (float)((float)v62 + (float)v15),
        h: (float)((float)v62 + (float)v16),
        size: borderWidth,
        color: (const idVec4 *)v61,
        a8: v60,
        a9: entityStateChanged,
        a10: (int)v58,
        a11: v57,
        a12: (const idVec4 *)&this->borderColor);
    if ( page != nullptr && this->selectedTab == this->tabNum )
      idGuiListBox::HandleEventQueue(this, queue: &page->eventQueue);
    if ( (v77.listStatic == 0 || v77.listStatic == 2) && v29 != nullptr )
      idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    if ( (v78.listStatic == 0 || v78.listStatic == 2) && v78.list != nullptr )
      idMem::Free(this: &mem, ptr: v78.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$496295
// EA  : 0x82A4C820
// RVA : 0x00A4C820
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496295()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 608 + 112));
}


// ========================================================================
// __unwind$496296
// EA  : 0x82A4C848
// RVA : 0x00A4C848
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496296()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 608 + 96));
}


// ========================================================================
// ??0idGuiPage1@@QAA@XZ
// EA  : 0x82A4C878
// RVA : 0x00A4C878
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage1 *__fastcall idGuiPage1::idGuiPage1(idGuiPage1 *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "AI List");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->selectedAiIndex = 0;
  this->__vftable = (idGuiPage1_vtbl *)&idGuiPage1::`vftable';
  this->filterNum = 0;
  this->aiFilter = 1;
  return this;
}


// ========================================================================
// __unwind$496659
// EA  : 0x82A4C8F8
// RVA : 0x00A4C8F8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496659()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$496660
// EA  : 0x82A4C920
// RVA : 0x00A4C920
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496660()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idGuiPage2@@QAA@XZ
// EA  : 0x82A4C950
// RVA : 0x00A4C950
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage2 *__fastcall idGuiPage2::idGuiPage2(idGuiPage2 *this)
{
  idStr v3; // [sp+60h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "AI State Machine");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idGuiPage2_vtbl *)&idGuiPage2::`vftable';
  this->pageStatus.selectedRow = -1;
  this->pageStatus.selectedColumn = -1;
  this->pageStatus.selectedTab = -1;
  this->pageStatus.tabNum = 0;
  return this;
}


// ========================================================================
// __unwind$496797
// EA  : 0x82A4C9DC
// RVA : 0x00A4C9DC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496797()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$496798
// EA  : 0x82A4CA04
// RVA : 0x00A4CA04
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496798()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 160 + 180));
}


// ========================================================================
// ?InternalHandleEvent@idGuiPage2@@EAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A4CA30
// RVA : 0x00A4CA30
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

BOOL __fastcall idGuiPage2::InternalHandleEvent(idGuiPage2 *this, const sysEvent_t *event)
{
  return (unsigned __int8)idGuiPage::HandleDefaultPageControls(this, event, pageStatus: &this->pageStatus) != 0;
}


// ========================================================================
// ??0idGuiPage4@@QAA@XZ
// EA  : 0x82A4CA68
// RVA : 0x00A4CA68
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage4 *__fastcall idGuiPage4::idGuiPage4(idGuiPage4 *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "AI Enemies");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idGuiPage4_vtbl *)&idGuiPage4::`vftable';
  return this;
}


// ========================================================================
// __unwind$496947
// EA  : 0x82A4CAD4
// RVA : 0x00A4CAD4
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496947()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$496948
// EA  : 0x82A4CAFC
// RVA : 0x00A4CAFC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496948()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idGuiPage5@@QAA@XZ
// EA  : 0x82A4CB30
// RVA : 0x00A4CB30
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage5 *__fastcall idGuiPage5::idGuiPage5(idGuiPage5 *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "AI FSM Log");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idGuiPage5_vtbl *)&idGuiPage5::`vftable';
  return this;
}


// ========================================================================
// __unwind$496980
// EA  : 0x82A4CB9C
// RVA : 0x00A4CB9C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496980()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$496981
// EA  : 0x82A4CBC4
// RVA : 0x00A4CBC4
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_496981()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idGuiPage6@@QAA@XZ
// EA  : 0x82A4CBF8
// RVA : 0x00A4CBF8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPage6 *__fastcall idGuiPage6::idGuiPage6(idGuiPage6 *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "AI Navigation");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idGuiPage6_vtbl *)&idGuiPage6::`vftable';
  return this;
}


// ========================================================================
// __unwind$497019
// EA  : 0x82A4CC64
// RVA : 0x00A4CC64
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_497019()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$497020
// EA  : 0x82A4CC8C
// RVA : 0x00A4CC8C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_497020()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ?InternalRender@idGuiPage6@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A4CCB8
// RVA : 0x00A4CCB8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage6::InternalRender(idGuiPage6 *this, idAI2 *debugEnt, idDeviceContext *context)
{
  idAI2::CastTo(c: debugEnt);
}


// ========================================================================
// ??0idAIGUI@@QAA@XZ
// EA  : 0x82A4CCC8
// RVA : 0x00A4CCC8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idAIGUI *__fastcall idAIGUI::idAIGUI(idAIGUI *this)
{
  this->pages.list = nullptr;
  this->pages.granularity = 0;
  this->pages.memTag = 5;
  this->pages.listStatic = 0;
  this->pages.size = 0;
  this->pages.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->debugPages.list = nullptr;
  this->debugPages.granularity = 0;
  this->debugPages.memTag = 5;
  this->debugPages.listStatic = 0;
  this->debugPages.size = 0;
  this->debugPages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debugPages);
  this->guiModel = nullptr;
  this->initialized = false;
  return this;
}


// ========================================================================
// __unwind$497155
// EA  : 0x82A4CD38
// RVA : 0x00A4CD38
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_497155()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idAIGUI@@QAA@XZ
// EA  : 0x82A4CD68
// RVA : 0x00A4CD68
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::~idAIGUI(idAIGUI *this)
{
  idRenderModelGui *guiModel; // r3

  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->debugPages);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$497179
// EA  : 0x82A4CDD0
// RVA : 0x00A4CDD0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_497179()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$497180
// EA  : 0x82A4CDF8
// RVA : 0x00A4CDF8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_497180()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?Shutdown@idAIGUI@@QAAXXZ
// EA  : 0x82A4CE28
// RVA : 0x00A4CE28
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::Shutdown(idAIGUI *this)
{
  idList<idTypeInfoSubGraph *,5>::DeleteContents((idList<idTypeInfoGraphLink *,5> *)this);
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->debugPages);
  this->initialized = false;
}


// ========================================================================
// ?GetDebugAi@idAIGUI@@AAAPAVidAI2@@XZ
// EA  : 0x82A4CE68
// RVA : 0x00A4CE68
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idAI2 *__fastcall idAIGUI::GetDebugAi(idAIGUI *this)
{
  idAI2 *result; // r3
  idAI2 *v2; // r27
  idAI2 *DebugEntity; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r29
  idGameLocal *v6; // r3
  double v7; // fp30
  idLinkList<idActor> *next; // r11
  idActor *owner; // r31
  int v10; // r11
  char v11; // r11
  bool v12; // zf
  idPhysics *Physics; // r3
  float *v14; // r26
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp9
  double v18; // fp31
  idLinkList<idActor> *v19; // r11
  int value; // r8
  idEntity *v21; // r3
  idAI2 *v22; // r3

  if ( aigui.valueInteger != 0 )
  {
    result = (idAI2 *)idGameLocal::GetDebugPlayer(this: gameLocal);
    v2 = result;
    if ( result == nullptr )
      return result;
    DebugEntity = (idAI2 *)idGameLocal::GetDebugEntity(this: gameLocal);
    v4 = idAI2::CastTo(c: DebugEntity);
    v5 = v4;
    if ( v4 == nullptr
      || v4->IsDead(this: v4)
      || (*((_BYTE *)&v5->flags + 1) & 0x80) != 0
      || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v5) != 0 )
    {
      v6 = gameLocal;
      v7 = 1.0e30;
      next = gameLocal->actorEntities.next;
      if ( next != nullptr && next != gameLocal->actorEntities.head )
      {
        owner = next->owner;
        if ( owner != nullptr )
        {
          do
          {
            v10 = *(_DWORD *)(owner->GetType(this: owner) + 36);
            if ( v10 < idAI2::Type.typeNum || (v12 = v10 <= idAI2::Type.lastChild, v11 = 1, !v12) )
              v11 = 0;
            if ( v11 != 0
              && !owner->IsDead(this: owner)
              && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: owner) == 0
              && !owner->IsDying(this: owner)
              && (*((_BYTE *)&owner->flags + 1) & 0x80) == 0 )
            {
              Physics = idEntity::GetPhysics(this: owner);
              v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v15 = idEntity::GetPhysics(this: v2);
              v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
              v17 = (float)(v16[1] - v14[1]);
              v18 = __fsqrts((float)((float)((float)v17 * (float)v17)
                                   + (float)((float)(*v16 - *v14) * (float)(*v16 - *v14))));
              if ( v18 < v7 )
              {
                v5 = idAI2::CastTo(c: (idAI2 *)owner);
                v7 = v18;
              }
            }
            v19 = owner->actorNode.next;
            if ( v19 == nullptr || v19 == owner->actorNode.head )
              owner = nullptr;
            else
              owner = v19->owner;
          }
          while ( owner != nullptr );
          v6 = gameLocal;
        }
      }
      idGameLocal::SetDebugEntity(this: v6, ent: v5);
    }
  }
  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return idAI2::CastTo(c: nullptr);
  v21 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v21 == nullptr )
    return idAI2::CastTo(c: nullptr);
  v22 = (idAI2 *)idEntity::CastTo(c: v21);
  return idAI2::CastTo(c: v22);
}


// ========================================================================
// ?AppendEvent@idGuiPage@@QAAXPBUsysEvent_t@@@Z
// EA  : 0x82A4D118
// RVA : 0x00A4D118
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage::AppendEvent(idGuiPage *this, const drawSurf_t *event)
{
  idList<idVerletChain::constraint_t,5>::Append(this: (idList<drawSurf_t,3> *)&this->eventQueue, obj: event);
}


// ========================================================================
// ?HandleEvent@idGuiPage@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A4D120
// RVA : 0x00A4D120
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiPage::HandleEvent(idGuiPage *this, const drawSurf_t *event)
{
  if ( ((unsigned __int8 (__fastcall *)(idGuiPage *))this->InternalHandleEvent)(a1: this) != 0 )
    return 1;
  idList<idVerletChain::constraint_t,5>::Append(this: (idList<drawSurf_t,3> *)&this->eventQueue, obj: event);
  return 0;
}


// ========================================================================
// ?Render@idGuiPage@@QAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A4D188
// RVA : 0x00A4D188
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage::Render(idGuiPage *this, idEntity *debugEnt, idDeviceContext *context)
{
  idList<idVehicleState *,5> *p_eventQueue; // r31

  p_eventQueue = (idList<idVehicleState *,5> *)&this->eventQueue;
  this->InternalRender_2(this, a2: debugEnt, a3: context);
  if ( p_eventQueue->size < 0 )
    idList<idThread *,58>::Clear(this: p_eventQueue);
  p_eventQueue->num = __CFADD__(-p_eventQueue->size, p_eventQueue->size ^ 0x80000000) ? 0 : p_eventQueue->size;
}


// ========================================================================
// ?Render@idGuiPage@@QAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82A4D1F8
// RVA : 0x00A4D1F8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage::Render(idGuiPage *this, idDeviceContext *context, double xPos, double yPos)
{
  idList<idVehicleState *,5> *p_eventQueue; // r31

  p_eventQueue = (idList<idVehicleState *,5> *)&this->eventQueue;
  this->InternalRender(this, a2: context, a3: xPos, a4: yPos);
  if ( p_eventQueue->size < 0 )
    idList<idThread *,58>::Clear(this: p_eventQueue);
  p_eventQueue->num = __CFADD__(-p_eventQueue->size, p_eventQueue->size ^ 0x80000000) ? 0 : p_eventQueue->size;
}


// ========================================================================
// ?GetAiList@idGuiPage1@@AAAXAAV?$idList@UaiGuiInfo_t@@$04@@H@Z
// EA  : 0x82A4D268
// RVA : 0x00A4D268
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage1::GetAiList(idGuiPage1 *this, idList<idSkinMapping,46> *ais, int filter)
{
  idLinkList<idActor> *next; // r11
  idAI2 *owner; // r29
  idAI2 *v8; // r3
  idAI2 *v9; // r30
  int v10; // r31
  int v11; // r31
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3
  idLinkList<idActor> *v15; // r11
  idAI2 *v16; // r11
  idSkinMapping v17; // [sp+50h] [-60h] BYREF

  next = gameLocal->actorEntities.next;
  if ( next != nullptr && next != gameLocal->actorEntities.head )
  {
    owner = (idAI2 *)next->owner;
    if ( owner != nullptr )
    {
      while ( 1 )
      {
        v8 = idAI2::CastTo(c: owner);
        v9 = v8;
        if ( v8 != nullptr )
          break;
LABEL_18:
        v15 = owner->actorNode.next;
        if ( v15 == nullptr || v15 == owner->actorNode.head )
          v16 = nullptr;
        else
          v16 = (idAI2 *)v15->owner;
        owner = v16;
        if ( v16 == nullptr )
          return;
      }
      LOBYTE(v10) = 0;
      v17.from = (const idMaterial *)v8;
      v17.to = nullptr;
      if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v8) != 0 )
      {
        v10 = 2;
      }
      else
      {
        if ( !v9->IsDead(this: v9) && !v9->IsDying(this: v9) )
          goto LABEL_11;
        v10 = 1;
      }
      v17.to = (const idMaterial *)v10;
LABEL_11:
      if ( ((1 << v10) & filter) != 0 )
      {
        v11 = idList<cachedPageFile_t,5>::Append(this: ais, obj: &v17);
        value = gameLocal->debugEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v14 = idEntity::CastTo(c: v13);
        }
        else
        {
          v14 = nullptr;
        }
        if ( v9 == v14 )
          this->selectedAiIndex = v11;
      }
      goto LABEL_18;
    }
  }
}


// ========================================================================
// ?FindAiByIndex@idGuiPage1@@AAAPAVidEntity@@HH@Z
// EA  : 0x82A4D3F0
// RVA : 0x00A4D3F0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

const idMaterial *__fastcall idGuiPage1::FindAiByIndex(idGuiPage1 *this, int index, int filter)
{
  const idMaterial *from; // r30
  idList<idSkinMapping,46> v8[4]; // [sp+50h] [-40h] BYREF

  memset(v8, 0, 14);
  v8[0].memTag = 5;
  v8[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v8);
  idGuiPage1::GetAiList(this, ais: v8, filter);
  if ( index < 0 || index >= v8[0].num )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v8);
    return nullptr;
  }
  else
  {
    from = v8[0].list[index].from;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v8);
    return from;
  }
}


// ========================================================================
// __unwind$498126
// EA  : 0x82A4D488
// RVA : 0x00A4D488
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_498126()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 80));
}


// ========================================================================
// ?AddPage@idAIGUI@@QAAXPAVidGuiPage@@@Z
// EA  : 0x82A4D578
// RVA : 0x00A4D578
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::AddPage(
        idAIGUI *this,
        idGuiPage *page,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idGuiPage *a14)
{
  a14 = page;
  idList<idAnimWebBlendTree *,5>::Append(
    (idList<enum encounterGroupRole_t,5> *)this,
    obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?AddDebugPage@idAIGUI@@QAAXPAVidGuiPage@@@Z
// EA  : 0x82A4D5A0
// RVA : 0x00A4D5A0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::AddDebugPage(
        idAIGUI *this,
        idGuiPage *page,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idGuiPage *a14)
{
  a14 = page;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->debugPages,
    obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?SendEventToActivePages@idAIGUI@@AAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A4D5D0
// RVA : 0x00A4D5D0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idAIGUI::SendEventToActivePages(idAIGUI *this, const drawSurf_t *event)
{
  int v4; // r31
  int i; // r29
  idGuiPage *v7; // r31

  v4 = 0;
  if ( this->debugPages.num <= 0 )
    return 0;
  for ( i = 0; !this->debugPages.list[i]->IsEnabled(this: this->debugPages.list[i]); ++i )
  {
    if ( ++v4 >= this->debugPages.num )
      return 0;
  }
  v7 = this->debugPages.list[v4];
  if ( v7->InternalHandleEvent(this: v7, a2: (const sysEvent_t *)event) )
    return 1;
  idList<idVerletChain::constraint_t,5>::Append(this: (idList<drawSurf_t,3> *)&v7->eventQueue, obj: event);
  return 0;
}


// ========================================================================
// ?RenderActivePages@idAIGUI@@AAA_NAAVidDeviceContext@@@Z
// EA  : 0x82A4D690
// RVA : 0x00A4D690
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idAIGUI::RenderActivePages(idAIGUI *this, idDeviceContext *context)
{
  int v4; // r30
  int i; // r29
  idAI2 *DebugAi; // r28
  idGuiPage *v8; // r31
  idList<idVehicleState *,5> *p_eventQueue; // r31

  v4 = 0;
  if ( this->debugPages.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    DebugAi = idAIGUI::GetDebugAi(this);
    if ( this->debugPages.list[i]->IsEnabled(this: this->debugPages.list[i]) )
      break;
    if ( ++v4 >= this->debugPages.num )
      return 0;
  }
  v8 = this->debugPages.list[v4];
  v8->InternalRender_2(this: v8, a2: DebugAi, a3: context);
  p_eventQueue = (idList<idVehicleState *,5> *)&v8->eventQueue;
  if ( p_eventQueue->size < 0 )
    idList<idThread *,58>::Clear(this: p_eventQueue);
  p_eventQueue->num = __CFADD__(-p_eventQueue->size, p_eventQueue->size ^ 0x80000000) ? 0 : p_eventQueue->size;
  return 1;
}


// ========================================================================
// ?InternalHandleEvent@idGuiPage1@@EAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A4D780
// RVA : 0x00A4D780
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiPage1::InternalHandleEvent(idGuiPage1 *this, const sysEvent_t *event)
{
  const idMaterial *AiByIndex; // r3
  idEntity *v5; // r27
  int evValue; // r11
  const idDeclDamage *damageSuicide; // r7
  int v8; // r11
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r30
  idPhysics *v11; // r3
  int v12; // r3
  unsigned int v13; // r11
  int num; // r29
  idSkinMapping *list; // r30
  idEntity *from; // r3
  const idEventDef *v17; // r4
  idEntity *v18; // r3
  _BYTE v20[20]; // [sp+70h] [-B0h] BYREF
  idList<idSkinMapping,46> v21[2]; // [sp+90h] [-90h] BYREF
  int v22; // [sp+B0h] [-70h]
  int v23; // [sp+B4h] [-6Ch]
  const idEventArg *v24; // [sp+B8h] [-68h]
  const idEventArg *v25; // [sp+BCh] [-64h]
  _DWORD v26[5]; // [sp+D0h] [-50h] BYREF

  AiByIndex = idGuiPage1::FindAiByIndex(this, index: this->selectedAiIndex, filter: this->aiFilter);
  v5 = (idEntity *)AiByIndex;
  if ( event->evType != SE_KEY || event->evValue2 == 0 )
    return 0;
  evValue = event->evValue;
  if ( evValue > 201 )
  {
    v13 = evValue - 207;
    if ( v13 <= 4 )
    {
      if ( v13 != 0 )
      {
        switch ( v13 )
        {
          case 1u:
            ++this->selectedAiIndex;
            break;
          case 2u:
            this->selectedAiIndex += 32;
            break;
          case 3u:
            if ( AiByIndex != nullptr )
            {
              if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (void *)AiByIndex) != 0 )
                v17 = &EV_Show;
              else
                v17 = &EV_Hide;
              idEventReceiver::PostEventMS(this: v5, ev: v17, time: 0);
            }
            break;
          default:
            if ( AiByIndex != nullptr )
              AiByIndex->GetDeclTimestamp(this: AiByIndex);
            break;
        }
      }
      else if ( AiByIndex != nullptr )
      {
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v21);
        idGuiPage1::GetAiList(this, ais: v21, filter: this->aiFilter);
        num = v21[0].num;
        if ( v21[0].num > 0 )
        {
          list = v21[0].list;
          do
          {
            from = (idEntity *)list->from;
            if ( list->from != nullptr && from != v5 )
              from->Remove(this: from);
            --num;
            ++list;
          }
          while ( num != 0 );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v21);
      }
      goto LABEL_41;
    }
    return 0;
  }
  if ( evValue == 201 )
  {
    this->selectedAiIndex -= 32;
    goto LABEL_41;
  }
  if ( evValue > 197 )
  {
    if ( evValue == 199 )
    {
      if ( AiByIndex != nullptr )
      {
        DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
        Physics = idEntity::GetPhysics(this: DebugPlayer);
        v11 = idEntity::GetPhysics(this: v5);
        v12 = (int)v11->GetOrigin(this: v11, a2: 0);
        Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v12, a3: -1);
      }
      goto LABEL_41;
    }
    if ( evValue != 200 )
      return 0;
    --this->selectedAiIndex;
    goto LABEL_41;
  }
  switch ( evValue )
  {
    case 197:
      v8 = this->filterNum + 1;
      this->filterNum = v8 % 4;
      this->aiFilter = aiInfoFilters[v8 % 4].filter;
      goto LABEL_41;
    case 28:
LABEL_41:
      v18 = (idEntity *)idGuiPage1::FindAiByIndex(this, index: this->selectedAiIndex, filter: this->aiFilter);
      idGameLocal::SetDebugEntity(this: gameLocal, ent: v18);
      return 1;
    case 37:
      if ( AiByIndex != nullptr )
      {
        HIBYTE(v26[0]) = 100;
        HIBYTE(v21[0].list) = 105;
        v21[0].num = 0;
        damageSuicide = gameLocal->damageSuicide;
        HIBYTE(v22) = 105;
        v23 = 0;
        v26[1] = damageSuicide;
        memcpy(Dst: v20, Src: v26, Size: sizeof(v20));
        idEventReceiver::PostEventMS(
          this: v5,
          ev: &EV_Kill,
          time: v22,
          arg1: v24,
          arg2: v25,
          arg3: (const idEventArg *)__ROL4__(v21[0].list, 32));
      }
      goto LABEL_41;
    default:
      break;
  }
  return 0;
}


// ========================================================================
// __unwind$498809
// EA  : 0x82A4DA7C
// RVA : 0x00A4DA7C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_498809()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 288 + 144));
}


// ========================================================================
// ?HandleEvent@idAIGUI@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A4DAA8
// RVA : 0x00A4DAA8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idAIGUI::HandleEvent(idAIGUI *this, const drawSurf_t *event)
{
  int v4; // r4

  idAIGUI::SendEventToActivePages(this, event);
  if ( aigui.valueInteger == 0 )
    return 0;
  if ( LODWORD(event->sort) == 3 )
  {
    idAIGUI::mouseX += *(_DWORD *)&event->isWorld;
    idAIGUI::mouseY += (int)event->model;
  }
  if ( LODWORD(event->sort) == 1 && aigui_keyboardUse.valueInteger > 1 )
  {
    switch ( *(_DWORD *)&event->isWorld )
    {
      case 'G':
        v4 = 7;
        goto LABEL_17;
      case 'H':
        v4 = 8;
        goto LABEL_17;
      case 'I':
        v4 = 9;
        goto LABEL_17;
      case 'K':
        v4 = 4;
        goto LABEL_17;
      case 'L':
        v4 = 5;
        goto LABEL_17;
      case 'M':
        v4 = 6;
        goto LABEL_17;
      case 'O':
        v4 = 1;
        goto LABEL_17;
      case 'P':
        v4 = 2;
        goto LABEL_17;
      case 'Q':
        v4 = 3;
        goto LABEL_17;
      case 'R':
        v4 = 0;
LABEL_17:
        idCVar::SetInteger(this: &aigui, newValue: v4, force: true);
        break;
      default:
        break;
    }
  }
  if ( aigui_keyboardUse.valueInteger > 0
    && aigui.valueInteger > 0
    && aigui.valueInteger < this->pages.num
    && this->pages.list[aigui.valueInteger] != nullptr )
  {
    return idGuiPage::HandleEvent(this: this->pages.list[aigui.valueInteger], event);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ??0idGuiListBox@@QAA@XZ
// EA  : 0x82A4DD48
// RVA : 0x00A4DD48
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::idGuiListBox(idGuiListBox *this)
{
  this->renderX = 0.0;
  this->__vftable = (idGuiListBox_vtbl *)&idGuiListBox::`vftable';
  this->maxRowsToDisplay = 0x7FFFFFFF;
  this->renderY = 0.0;
  this->skipMaxColumnSizeCheck = false;
  this->selectedRow = -1;
  this->desiredRenderX = 0.0;
  this->selectedColumn = -1;
  this->desiredRenderY = 0.0;
  this->didActionRow = -1;
  this->renderWidth = 0.0;
  this->renderHeight = 0.0;
  this->entityStateChanged = false;
  this->borderWidth = 0.0;
  this->drawRowDivider = false;
  this->dividerWidth = 0.0;
  this->tabNum = 0;
  this->selectedTab = 0;
  this->borderColor = idColor::colorWhite;
  this->currentColor = idColor::colorWhite;
  this->selectedColor = idColor::colorGreen;
  this->didActionColor = idColor::colorRed;
  this->dividerColor = idColor::colorWhite;
  this->backGroundColor = defaultColorBackground;
  this->rows.granularity = 0;
  this->rows.memTag = 5;
  this->rows.listStatic = 0;
  this->rows.list = nullptr;
  this->rows.size = 0;
  this->rows.num = 0;
  return this;
}


// ========================================================================
// ??1idGuiListBox@@UAA@XZ
// EA  : 0x82A4DEC8
// RVA : 0x00A4DEC8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiListBox::~idGuiListBox(idGuiListBox *this)
{
  int v2; // r28
  int v3; // r29
  char *list; // r3

  this->__vftable = (idGuiListBox_vtbl *)&idGuiListBox::`vftable';
  v2 = 0;
  if ( this->rows.num > 0 )
  {
    v3 = 0;
    do
    {
      idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->rows.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->rows.num );
  }
  if ( this->rows.listStatic == 0 || this->rows.listStatic == 2 )
  {
    list = (char *)this->rows.list;
    if ( list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(ptr: list, num: this->rows.size);
    this->rows.list = nullptr;
    this->rows.size = 0;
  }
  this->rows.num = 0;
}


// ========================================================================
// __unwind$499186
// EA  : 0x82A4DF60
// RVA : 0x00A4DF60
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499186()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(*(_DWORD *)(v0 - 128 + 148) + 160));
}


// ========================================================================
// ?Row@idGuiListBox@@QAAAAV1@XZ
// EA  : 0x82A4DF98
// RVA : 0x00A4DF98
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::Row(idGuiListBox *this)
{
  idList<idVehicleState *,5> v3; // [sp+50h] [-30h] BYREF

  memset(&v3, 0, 14);
  v3.memTag = 5;
  v3.listStatic = 0;
  idList<idThread *,58>::Clear(this: &v3);
  idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)&v3);
  idList<idThread *,58>::Clear(this: &v3);
  return this;
}


// ========================================================================
// __unwind$499230
// EA  : 0x82A4E00C
// RVA : 0x00A4E00C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499230()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 128 + 80));
}


// ========================================================================
// ?Printf@idGuiListBox@@QAAAAV1@PBDZZ
// EA  : 0x82A4E040
// RVA : 0x00A4E040
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idGuiListBox *idGuiListBox::Printf(idGuiListBox *this, const char *fmt, __int64 a3, __int64 a4, __int64 a5, ...)
{
  int v6; // r27
  idList<enum encounterGroupRole_t,5> *v7; // r26
  char *v8; // r3
  char *v9; // r30
  idGuiListBox *v10; // r3
  idGuiListBox_vtbl *v11; // r7
  int v12; // r3
  encounterGroupRole_t v14[4]; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> v15[5]; // [sp+60h] [-50h] BYREF
  __int64 v17; // [sp+D0h] [+20h] BYREF
  __int64 v18; // [sp+D8h] [+28h]
  __int64 v19; // [sp+E0h] [+30h]
  __int64 v20; // [sp+E8h] [+38h]
  __int64 v21; // [sp+F0h] [+40h]
  __int64 v22; // [sp+F8h] [+48h]

  v17 = *(__int64 *)((char *)&a3 + 4);
  v18 = a3;
  v19 = *(__int64 *)((char *)&a4 + 4);
  v20 = a4;
  v21 = *(__int64 *)((char *)&a5 + 4);
  v22 = a5;
  if ( this->rows.num == 0 )
  {
    memset(v15, 0, 14);
    v15[0].memTag = 5;
    v15[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v15);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v15);
    idList<idThread *,58>::Clear(this: v15);
  }
  v6 = this->rows.num - 1;
  v7 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v6];
  v8 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x3Cu,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    *((_DWORD *)v8 + 1) = 0;
    v8[8] = 0;
    v8[9] = 0;
    *(_DWORD *)v8 = &cellTxt_t::`vftable';
    *(idColor *)(v8 + 12) = idColor::colorWhite;
    v9 = v8;
    *((_DWORD *)v8 + 9) = 20;
    *((_DWORD *)v8 + 8) = v8 + 40;
    *((_DWORD *)v8 + 7) = 0;
    v8[40] = 0;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v15, result: (idColor *)this, row: v6);
  v11 = v10->__vftable;
  v14[0] = (encounterGroupRole_t)&v17;
  *((_DWORD *)v9 + 3) = v11;
  *((_DWORD *)v9 + 4) = *(_DWORD *)&v10->skipMaxColumnSizeCheck;
  *((_DWORD *)v9 + 5) = v10->tabNum;
  *((_DWORD *)v9 + 6) = v10->selectedRow;
  idStr::VFormat(this: (idStr *)(v9 + 28), fmt, argptr: (char *)&v17);
  v14[0] = (encounterGroupRole_t)v9;
  v12 = idList<idAnimWebBlendTree *,5>::Append(this: v7, obj: v14);
  v9[8] = (_cntlzw(v6 - this->selectedRow) & 0x20) != 0;
  v9[9] = (_cntlzw(v12 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$499353
// EA  : 0x82A4E204
// RVA : 0x00A4E204
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499353()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?Value@idGuiListBox@@QAAAAV1@AAMM@Z
// EA  : 0x82A4E238
// RVA : 0x00A4E238
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::Value(idGuiListBox *this, float *value, double stepSize)
{
  _DWORD *v6; // r30
  int v7; // r28
  idList<enum encounterGroupRole_t,5> *v8; // r27
  _DWORD *v9; // r3
  float a; // r11
  idGuiListBox *v11; // r3
  int v12; // r4
  encounterGroupRole_t v14[4]; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> v15; // [sp+60h] [-50h] BYREF

  v6 = nullptr;
  if ( this->rows.num == 0 )
  {
    memset(&v15, 0, 14);
    *(_WORD *)&v15.memTag = 1280;
    idList<idThread *,58>::Clear(this: &v15);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)&v15);
    idList<idThread *,58>::Clear(this: &v15);
  }
  v7 = this->rows.num - 1;
  v8 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v7];
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
         size: 0x24u,
         tag: TAG_NEW,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
  {
    v9[1] = 0;
    *((_BYTE *)v9 + 8) = 0;
    *((_BYTE *)v9 + 9) = 0;
    *v9 = &cellValueFloat_t::`vftable';
    v6 = v9;
    v9[3] = LODWORD(idColor::colorWhite.r);
    v9[4] = LODWORD(idColor::colorWhite.g);
    v9[5] = LODWORD(idColor::colorWhite.b);
    a = idColor::colorWhite.a;
    *((float *)v9 + 8) = stepSize;
    *((float *)v9 + 6) = a;
    v9[7] = value;
  }
  v11 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)&v15, result: (idColor *)this, row: v7);
  v14[0] = (encounterGroupRole_t)v6;
  v6[3] = v11->__vftable;
  v6[4] = *(_DWORD *)&v11->skipMaxColumnSizeCheck;
  v6[5] = v11->tabNum;
  v6[6] = v11->selectedRow;
  v12 = idList<idAnimWebBlendTree *,5>::Append(this: v8, obj: v14);
  *((_BYTE *)v6 + 8) = (_cntlzw(v7 - this->selectedRow) & 0x20) != 0;
  *((_BYTE *)v6 + 9) = (_cntlzw(v12 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$499629
// EA  : 0x82A4E3B8
// RVA : 0x00A4E3B8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499629()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?Command@idGuiListBox@@QAAAAV1@PBD_N@Z
// EA  : 0x82A4E3E8
// RVA : 0x00A4E3E8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::Command(idGuiListBox *this, const char *commandName, const bool verifyCmdName)
{
  int v6; // r27
  idList<enum encounterGroupRole_t,5> *v7; // r25
  _DWORD *v8; // r3
  _DWORD *v9; // r28
  bool v10; // r3
  int v11; // r3
  _DWORD *v13; // [sp+50h] [-70h] BYREF
  idList<idVehicleState *,5> v14[6]; // [sp+60h] [-60h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(v14, 0, 14);
    v14[0].memTag = 5;
    v14[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v14);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v14);
    idList<idThread *,58>::Clear(this: v14);
  }
  v6 = this->rows.num - 1;
  v7 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v6];
  v8 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
         size: 0x2Cu,
         tag: TAG_NEW,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    v8[1] = 0;
    *((_BYTE *)v8 + 8) = 0;
    *((_BYTE *)v8 + 9) = 0;
    *v8 = &cellCmd_t::`vftable';
    v8[5] = 20;
    v9 = v8;
    v8[4] = v8 + 6;
    v8[3] = 0;
    *((_BYTE *)v8 + 24) = 0;
  }
  else
  {
    v9 = nullptr;
  }
  idStr::operator=(this: (idStr *)(v9 + 3), text: commandName);
  if ( verifyCmdName )
  {
    v10 = cvarSystem->CvarExists(this: cvarSystem, a2: commandName, a3: true);
    if ( !v10 )
      v10 = cmdSystem->CommandExists(this: cmdSystem, a2: commandName, a3: true);
    if ( !v10 )
      idLib::Warning(
        fmt: "idGuiListBox::Command - Command '%s' no longer exists! Please have a programmer fix ASAP!",
        commandName);
  }
  v13 = v9;
  v11 = idList<idAnimWebBlendTree *,5>::Append(this: v7, obj: (const encounterGroupRole_t *)&v13);
  *((_BYTE *)v9 + 8) = (_cntlzw(v6 - this->selectedRow) & 0x20) != 0;
  *((_BYTE *)v9 + 9) = (_cntlzw(v11 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$499709
// EA  : 0x82A4E598
// RVA : 0x00A4E598
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499709()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?ChangeCvar@idGuiListBox@@QAAAAV1@PBDMMMP6AX_N@Z1@Z
// EA  : 0x82A4E5C8
// RVA : 0x00A4E5C8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::ChangeCvar(
        idGuiListBox *this,
        const char *cvarName,
        double minValue,
        double maxValue,
        double delta,
        void (__fastcall *callBack)(const bool),
        const bool canHoldToAdvance,
        int a8,
        int a9,
        char a10)
{
  int v17; // r27
  idList<enum encounterGroupRole_t,5> *v18; // r25
  char *v19; // r3
  char *v20; // r30
  int v21; // r3
  char *v23; // [sp+50h] [-90h] BYREF
  idList<idVehicleState *,5> v24; // [sp+60h] [-80h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(&v24, 0, 14);
    v24.memTag = 5;
    v24.listStatic = 0;
    idList<idThread *,58>::Clear(this: &v24);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)&v24);
    idList<idThread *,58>::Clear(this: &v24);
  }
  v17 = this->rows.num - 1;
  v18 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v17];
  v19 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x54u,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v19 != nullptr )
  {
    *((_DWORD *)v19 + 1) = 0;
    v19[8] = 0;
    v19[9] = 0;
    v19[12] = 0;
    *(_DWORD *)v19 = &cellCvar_t::`vftable';
    *((_DWORD *)v19 + 4) = 0;
    *((_DWORD *)v19 + 5) = v19 + 28;
    *((_DWORD *)v19 + 6) = 20;
    v19[28] = 0;
    *((float *)v19 + 12) = 0.0;
    *((float *)v19 + 13) = 0.0;
    v20 = v19;
    *((float *)v19 + 14) = 0.0;
    *(idColor *)(v19 + 60) = idColor::colorWhite;
    *((_DWORD *)v19 + 19) = 0;
    v19[80] = 0;
  }
  else
  {
    v20 = nullptr;
  }
  idStr::operator=(this: (idStr *)(v20 + 16), text: cvarName);
  *((float *)v20 + 12) = minValue;
  *((float *)v20 + 13) = maxValue;
  *((_DWORD *)v20 + 19) = a9;
  *((float *)v20 + 14) = delta;
  v20[12] = a10;
  if ( !cvarSystem->CvarExists(this: cvarSystem, a2: cvarName, a3: true) )
    idLib::Warning(
      fmt: "idGuiListBox::ChangeCvar - Cvar %s no longer exists! Please have a programmer fix ASAP!",
      cvarName);
  v23 = v20;
  v21 = idList<idAnimWebBlendTree *,5>::Append(this: v18, obj: (const encounterGroupRole_t *)&v23);
  v20[8] = (_cntlzw(v17 - this->selectedRow) & 0x20) != 0;
  v20[9] = (_cntlzw(v21 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$499820
// EA  : 0x82A4E7C4
// RVA : 0x00A4E7C4
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499820()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?DrawCheckMark@idGuiListBox@@QAAAAV1@_N@Z
// EA  : 0x82A4E7F8
// RVA : 0x00A4E7F8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::DrawCheckMark(idGuiListBox *this, char checked)
{
  char *v4; // r30
  int v5; // r28
  idList<enum encounterGroupRole_t,5> *v6; // r27
  char *v7; // r3
  idGuiListBox *v8; // r3
  int v9; // r4
  char *v11; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> v12[5]; // [sp+60h] [-50h] BYREF

  v4 = nullptr;
  if ( this->rows.num == 0 )
  {
    memset(v12, 0, 14);
    v12[0].memTag = 5;
    v12[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v12);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v12);
    idList<idThread *,58>::Clear(this: v12);
  }
  v5 = this->rows.num - 1;
  v6 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v5];
  v7 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x20u,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    *((_DWORD *)v7 + 1) = 0;
    v7[8] = 0;
    v7[9] = 0;
    *(_DWORD *)v7 = &drawCheckMark_bool_t::`vftable';
    v4 = v7;
    *(idColor *)(v7 + 12) = idColor::colorWhite;
    v7[28] = checked;
  }
  v8 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v12, result: (idColor *)this, row: v5);
  v11 = v4;
  *((_DWORD *)v4 + 3) = v8->__vftable;
  *((_DWORD *)v4 + 4) = *(_DWORD *)&v8->skipMaxColumnSizeCheck;
  *((_DWORD *)v4 + 5) = v8->tabNum;
  *((_DWORD *)v4 + 6) = v8->selectedRow;
  v9 = idList<idAnimWebBlendTree *,5>::Append(this: v6, obj: (const encounterGroupRole_t *)&v11);
  v4[8] = (_cntlzw(v5 - this->selectedRow) & 0x20) != 0;
  v4[9] = (_cntlzw(v9 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$499932
// EA  : 0x82A4E968
// RVA : 0x00A4E968
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_499932()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?CheckBox@idGuiListBox@@QAAAAV1@AA_N@Z
// EA  : 0x82A4E998
// RVA : 0x00A4E998
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::CheckBox(idGuiListBox *this, bool *checked)
{
  int v4; // r27
  idList<enum encounterGroupRole_t,5> *v5; // r26
  char *v6; // r3
  char *v7; // r30
  idGuiListBox *v8; // r3
  int v9; // r4
  char *v11; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> v12[5]; // [sp+60h] [-50h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(v12, 0, 14);
    v12[0].memTag = 5;
    v12[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v12);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v12);
    idList<idThread *,58>::Clear(this: v12);
  }
  v4 = this->rows.num - 1;
  v5 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v4];
  v6 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x28u,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    *((_DWORD *)v6 + 1) = 0;
    v6[8] = 0;
    v6[9] = 0;
    *(_DWORD *)v6 = &checkBox_bool_t::`vftable';
    v7 = v6;
    *(idColor *)(v6 + 12) = idColor::colorWhite;
    *((_DWORD *)v6 + 7) = checked;
    *((_DWORD *)v6 + 8) = 0;
    v6[36] = 0;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v12, result: (idColor *)this, row: v4);
  v11 = v7;
  *((_DWORD *)v7 + 3) = v8->__vftable;
  *((_DWORD *)v7 + 4) = *(_DWORD *)&v8->skipMaxColumnSizeCheck;
  *((_DWORD *)v7 + 5) = v8->tabNum;
  *((_DWORD *)v7 + 6) = v8->selectedRow;
  v9 = idList<idAnimWebBlendTree *,5>::Append(this: v5, obj: (const encounterGroupRole_t *)&v11);
  v7[8] = (_cntlzw(v4 - this->selectedRow) & 0x20) != 0;
  v7[9] = (_cntlzw(v9 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$500013
// EA  : 0x82A4EB18
// RVA : 0x00A4EB18
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500013()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?CheckBox@idGuiListBox@@QAAAAV1@AAHH@Z
// EA  : 0x82A4EB48
// RVA : 0x00A4EB48
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::CheckBox(idGuiListBox *this, int *bitfield, int bit)
{
  int v6; // r27
  idList<enum encounterGroupRole_t,5> *v7; // r26
  char *v8; // r3
  char *v9; // r30
  idGuiListBox *v10; // r3
  int v11; // r4
  char *v13; // [sp+50h] [-70h] BYREF
  idList<idVehicleState *,5> v14[6]; // [sp+60h] [-60h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(v14, 0, 14);
    v14[0].memTag = 5;
    v14[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v14);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v14);
    idList<idThread *,58>::Clear(this: v14);
  }
  v6 = this->rows.num - 1;
  v7 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v6];
  v8 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x2Cu,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    *((_DWORD *)v8 + 1) = 0;
    v8[8] = 0;
    v8[9] = 0;
    *(_DWORD *)v8 = &checkBox_bitflag_t::`vftable';
    v9 = v8;
    *(idColor *)(v8 + 12) = idColor::colorWhite;
    *((_DWORD *)v8 + 7) = bitfield;
    *((_DWORD *)v8 + 8) = bit;
    *((_DWORD *)v8 + 9) = 0;
    v8[40] = 0;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v14, result: (idColor *)this, row: v6);
  v13 = v9;
  *((_DWORD *)v9 + 3) = v10->__vftable;
  *((_DWORD *)v9 + 4) = *(_DWORD *)&v10->skipMaxColumnSizeCheck;
  *((_DWORD *)v9 + 5) = v10->tabNum;
  *((_DWORD *)v9 + 6) = v10->selectedRow;
  v11 = idList<idAnimWebBlendTree *,5>::Append(this: v7, obj: (const encounterGroupRole_t *)&v13);
  v9[8] = (_cntlzw(v6 - this->selectedRow) & 0x20) != 0;
  v9[9] = (_cntlzw(v11 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$500094
// EA  : 0x82A4ECD0
// RVA : 0x00A4ECD0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500094()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?ComboBox@idGuiListBox@@QAAAAV1@AAHQAPBDH@Z
// EA  : 0x82A4ED00
// RVA : 0x00A4ED00
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::ComboBox(idGuiListBox *this, int *itemIndex, const char **items, int numItems)
{
  int v8; // r27
  idList<enum encounterGroupRole_t,5> *v9; // r26
  _DWORD *v10; // r3
  char *v11; // r30
  idGuiListBox *v12; // r3
  int v13; // r3
  char *v15; // [sp+50h] [-70h] BYREF
  idList<idVehicleState *,5> v16[6]; // [sp+60h] [-60h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(v16, 0, 14);
    v16[0].memTag = 5;
    v16[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v16);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v16);
    idList<idThread *,58>::Clear(this: v16);
  }
  v8 = this->rows.num - 1;
  v9 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v8];
  v10 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
          size: 0x28u,
          tag: TAG_NEW,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
  {
    v10[1] = 0;
    *((_BYTE *)v10 + 8) = 0;
    *((_BYTE *)v10 + 9) = 0;
    *v10 = &comboBox_t::`vftable';
    v11 = (char *)v10;
    v15 = (char *)(v10 + 3);
    *((float *)v10 + 6) = -1.0;
    *((float *)v10 + 5) = -1.0;
    *((float *)v10 + 4) = -1.0;
    *((float *)v10 + 3) = -1.0;
    v10[7] = itemIndex;
    v10[8] = 0;
    v10[9] = 0;
  }
  else
  {
    v11 = nullptr;
  }
  *((_DWORD *)v11 + 8) = items;
  *((_DWORD *)v11 + 9) = numItems;
  v12 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v16, result: (idColor *)this, row: v8);
  v15 = v11;
  *((_DWORD *)v11 + 3) = v12->__vftable;
  *((_DWORD *)v11 + 4) = *(_DWORD *)&v12->skipMaxColumnSizeCheck;
  *((_DWORD *)v11 + 5) = v12->tabNum;
  *((_DWORD *)v11 + 6) = v12->selectedRow;
  v13 = idList<idAnimWebBlendTree *,5>::Append(this: v9, obj: (const encounterGroupRole_t *)&v15);
  v11[8] = (_cntlzw(v8 - this->selectedRow) & 0x20) != 0;
  v11[9] = (_cntlzw(v13 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$500175
// EA  : 0x82A4EE80
// RVA : 0x00A4EE80
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500175()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?ComboBoxCvar@idGuiListBox@@QAAAAV1@AAVidCVar@@QAPBDH@Z
// EA  : 0x82A4EEB0
// RVA : 0x00A4EEB0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::ComboBoxCvar(idGuiListBox *this, idCVar *cvar, const char **items, int numItems)
{
  int v8; // r27
  idList<enum encounterGroupRole_t,5> *v9; // r26
  _DWORD *v10; // r3
  char *v11; // r30
  idGuiListBox *v12; // r3
  int v13; // r3
  char *v15; // [sp+50h] [-70h] BYREF
  idList<idVehicleState *,5> v16[6]; // [sp+60h] [-60h] BYREF

  if ( this->rows.num == 0 )
  {
    memset(v16, 0, 14);
    v16[0].memTag = 5;
    v16[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v16);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v16);
    idList<idThread *,58>::Clear(this: v16);
  }
  v8 = this->rows.num - 1;
  v9 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v8];
  v10 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
          size: 0x2Cu,
          tag: TAG_NEW,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
  {
    v10[1] = 0;
    *((_BYTE *)v10 + 8) = 0;
    *((_BYTE *)v10 + 9) = 0;
    *v10 = &comboBoxCvar_t::`vftable';
    v11 = (char *)v10;
    v15 = (char *)(v10 + 3);
    *((float *)v10 + 6) = -1.0;
    *((float *)v10 + 5) = -1.0;
    *((float *)v10 + 4) = -1.0;
    *((float *)v10 + 3) = -1.0;
    v10[8] = cvar;
    v10[9] = 0;
    v10[10] = 0;
    v10[7] = cvar->valueInteger;
  }
  else
  {
    v11 = nullptr;
  }
  *((_DWORD *)v11 + 9) = items;
  *((_DWORD *)v11 + 10) = numItems;
  v12 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v16, result: (idColor *)this, row: v8);
  v15 = v11;
  *((_DWORD *)v11 + 3) = v12->__vftable;
  *((_DWORD *)v11 + 4) = *(_DWORD *)&v12->skipMaxColumnSizeCheck;
  *((_DWORD *)v11 + 5) = v12->tabNum;
  *((_DWORD *)v11 + 6) = v12->selectedRow;
  v13 = idList<idAnimWebBlendTree *,5>::Append(this: v9, obj: (const encounterGroupRole_t *)&v15);
  v11[8] = (_cntlzw(v8 - this->selectedRow) & 0x20) != 0;
  v11[9] = (_cntlzw(v13 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$500262
// EA  : 0x82A4F038
// RVA : 0x00A4F038
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500262()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?SetChildWindow@idGuiListBox@@QAAAAV1@ABVidStr@@PAVidGuiPage@@@Z
// EA  : 0x82A4F068
// RVA : 0x00A4F068
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::SetChildWindow(idGuiListBox *this, const idStr *childName, idGuiPage *page)
{
  char *v6; // r30
  unsigned int v7; // r28
  idList<enum encounterGroupRole_t,5> *v8; // r27
  char *v9; // r3
  idGuiListBox *v10; // r3
  int v11; // r3
  char *v13; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> v14[5]; // [sp+60h] [-50h] BYREF

  v6 = nullptr;
  if ( this->rows.num == 0 )
  {
    memset(v14, 0, 14);
    v14[0].memTag = 5;
    v14[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: v14);
    idList<idGuiListBox::row_t,5>::Append(this: &this->rows, obj: (const idGuiListBox::row_t *)v14);
    idList<idThread *,58>::Clear(this: v14);
  }
  v7 = this->rows.num - 1;
  v8 = (idList<enum encounterGroupRole_t,5> *)&this->rows.list[v7];
  v9 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                 size: 0x1Cu,
                 tag: TAG_NEW,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
  {
    *((_DWORD *)v9 + 1) = 0;
    v9[8] = 0;
    v9[9] = 0;
    *(_DWORD *)v9 = &nextPageMarker_t::`vftable';
    v6 = v9;
    *(idColor *)(v9 + 12) = idColor::colorWhite;
  }
  v10 = idGuiListBox::CalcWidgetColor(this: (idGuiListBox *)v14, result: (idColor *)this, row: v7);
  *((_DWORD *)v6 + 3) = v10->__vftable;
  *((_DWORD *)v6 + 4) = *(_DWORD *)&v10->skipMaxColumnSizeCheck;
  *((_DWORD *)v6 + 5) = v10->tabNum;
  *((_DWORD *)v6 + 6) = v10->selectedRow;
  if ( childName->len != 0 && page != nullptr && (((v7 >> 31) + 1) & 1) != 0 )
    page->SetupChildRowLink(this: page, a2: v7, a3: childName);
  v13 = v6;
  v11 = idList<idAnimWebBlendTree *,5>::Append(this: v8, obj: (const encounterGroupRole_t *)&v13);
  v6[8] = (_cntlzw(v7 - this->selectedRow) & 0x20) != 0;
  v6[9] = (_cntlzw(v11 - this->selectedColumn) & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$500446
// EA  : 0x82A4F224
// RVA : 0x00A4F224
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500446()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 96));
}


// ========================================================================
// ?InternalRender@idGuiPage1@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A4F258
// RVA : 0x00A4F258
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage1::InternalRender(idGuiPage1 *this, idEntity *debugEnt, idDeviceContext *context)
{
  __int64 v3; // r30
  int selectedAiIndex; // r10
  int num; // r19
  unsigned int v8; // r7
  idSkinMapping *list; // r15
  idSkinMapping *v10; // r27
  int v11; // r10
  idColor *v12; // r11
  const idMaterial *to; // r11
  float g; // r7
  float v15; // r6
  float a; // r5
  idResourceList *resourceListPtr; // r14
  idGuiListBox *v18; // r3
  __int64 v19; // r8
  float b; // r11
  __int64 v21; // r10
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r3
  double v26; // fp1
  const char *filterName; // r30
  idGuiListBox *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r6
  __int64 v31; // r8
  idEntity *AiByIndex; // r30
  const char *v33; // r29
  idGuiListBox *v34; // r3
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  idGuiListBox *v38; // r3
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r6
  idGuiListBox *v42; // r3
  __int64 v43; // r8
  __int64 v44; // r10
  __int64 v45; // r6
  idGuiListBox *v46; // r3
  __int64 v47; // r8
  __int64 v48; // r6
  __int64 v49; // r10
  idGuiListBox *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  idGuiListBox *v54; // r3
  __int64 v55; // r6
  __int64 v56; // r10
  __int64 v57; // r8
  idGuiListBox *v58; // r3
  __int64 v59; // r10
  __int64 v60; // r8
  __int64 v61; // r6
  idGuiListBox *v62; // r3
  __int64 v63; // r10
  __int64 v64; // r8
  __int64 v65; // r6
  idGuiListBox *v66; // r3
  __int64 v67; // r10
  __int64 v68; // r8
  __int64 v69; // r6
  idGuiListBox *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r8
  __int64 v73; // r6
  idGuiListBox *v74; // r3
  __int64 v75; // r8
  __int64 v76; // r10
  __int64 v77; // r6
  idGuiListBox *v78; // r3
  __int64 v79; // r8
  __int64 v80; // r10
  __int64 v81; // r6
  const char *v82; // r29
  idGuiListBox *v83; // r3
  __int64 v84; // r10
  __int64 v85; // r8
  __int64 v86; // r6
  idGuiListBox *v87; // r3
  __int64 v88; // r10
  __int64 v89; // r8
  __int64 v90; // r6
  idPhysics *Physics; // r29
  idRenderWorld *v92; // r28
  idPhysics *v93; // r3
  int v94; // r27
  idPhysics *v95; // r3
  int v96; // r26
  idRenderWorld_vtbl *v97; // r30
  int v98; // r3
  idList<idSkinMapping,46> v99; // [sp+80h] [-220h] BYREF
  idColor v100; // [sp+90h] [-210h]
  idGuiListBox v101; // [sp+A0h] [-200h] BYREF
  idGuiListBox v102; // [sp+150h] [-150h] BYREF

  LODWORD(v3) = 0;
  memset(&v99, 0, 14);
  *(_WORD *)&v99.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v99);
  idGuiPage1::GetAiList(this, ais: &v99, filter: this->aiFilter);
  selectedAiIndex = this->selectedAiIndex;
  num = v99.num;
  v8 = (v99.num == 1) + ((unsigned int)(v99.num - 1) >> 31) - 1;
  if ( selectedAiIndex >= 0 )
  {
    if ( selectedAiIndex > (int)(v8 & (v99.num - 1)) )
      selectedAiIndex = v8 & (v99.num - 1);
  }
  else
  {
    selectedAiIndex = 0;
  }
  this->selectedAiIndex = selectedAiIndex;
  idGuiListBox::idGuiListBox(this: &v102);
  list = v99.list;
  v102.selectedRow = this->selectedAiIndex;
  v102.maxRowsToDisplay = 32;
  if ( num > 0 )
  {
    v10 = v99.list;
    while ( 1 )
    {
      v11 = this->selectedAiIndex;
      v100 = idColor::colorBlue;
      if ( v11 == (_DWORD)v3 )
        break;
      to = v10->to;
      if ( to == (const idMaterial *)2 )
      {
        v12 = &idColor::colorMdGrey;
        goto LABEL_13;
      }
      if ( to == (const idMaterial *)1 )
      {
        v12 = &idColor::colorRed;
        goto LABEL_13;
      }
LABEL_14:
      HIDWORD(v3) = ">";
      if ( v11 != (_DWORD)v3 )
        HIDWORD(v3) = " ";
      resourceListPtr = v10->from->resourceListPtr;
      v18 = idGuiListBox::Row(this: &v102);
      v19 = __PAIR64__((unsigned int)resourceListPtr, LODWORD(v100.g));
      b = v100.b;
      v21 = __PAIR64__(LODWORD(v100.r), LODWORD(v100.a));
      *(_QWORD *)&v18->currentColor.r = *(_QWORD *)&v100.r;
      v18->currentColor.b = b;
      LODWORD(v18->currentColor.a) = v21;
      idGuiListBox::Printf(this: v18, fmt: "%s%2d: %s", a3: v3, a4: v19, a5: v21);
      v25 = ((int (__fastcall *)(const idMaterial *))v10->from->__vftable[6].ReloadIfStale)(a1: v10->from);
      if ( v25 != 0 )
        (*(void (__fastcall **)(int))(*(_DWORD *)v25 + 76))(a1: v25);
      else
        v26 = 0.0;
      HIDWORD(v24) = LODWORD(v26);
      idGuiListBox::Printf(this: &v102, fmt: " health %.1f", a3: v24, a4: v23, a5: v22);
      LODWORD(v3) = v3 + 1;
      ++v10;
      if ( (int)v3 >= num )
        goto LABEL_22;
    }
    v12 = &idColor::colorGreen;
LABEL_13:
    g = v12->g;
    v15 = v12->b;
    a = v12->a;
    v100.r = v12->r;
    v100.g = g;
    v100.b = v15;
    v100.a = a;
    goto LABEL_14;
  }
  filterName = aiInfoFilters[this->filterNum].filterName;
  v28 = idGuiListBox::Row(this: &v102);
  HIDWORD(v29) = "ound traces";
  HIDWORD(v30) = filterName;
  idGuiListBox::Printf(this: v28, fmt: " No AI in current filter %s", a3: v30, a4: v31, a5: v29);
LABEL_22:
  idGuiListBox::Render(this: &v102, page: this, context, hAlign: 0, vAlign: 1u, nextTo: nullptr);
  AiByIndex = (idEntity *)idGuiPage1::FindAiByIndex(this, index: this->selectedAiIndex, filter: this->aiFilter);
  idGuiListBox::idGuiListBox(this: &v101);
  v33 = aiInfoFilters[this->filterNum].filterName;
  v34 = idGuiListBox::Row(this: &v101);
  HIDWORD(v35) = "ound traces";
  v38 = idGuiListBox::Printf(this: v34, fmt: "Filter(NumLock Changes)", a3: v37, a4: v36, a5: v35);
  idGuiListBox::Printf(this: v38, fmt: v33, a3: v41, a4: v40, a5: v39);
  v42 = idGuiListBox::Row(this: &v101);
  LODWORD(v43) = "ound traces";
  v46 = idGuiListBox::Printf(this: v42, fmt: "Num", a3: v45, a4: v43, a5: v44);
  HIDWORD(v47) = 0x82000000;
  HIDWORD(v48) = num;
  idGuiListBox::Printf(this: v46, fmt: "%d", a3: v48, a4: v47, a5: v49);
  v50 = idGuiListBox::Row(this: &v101);
  LODWORD(v51) = "ound traces";
  v54 = idGuiListBox::Printf(this: v50, fmt: "DEL - ", a3: v51, a4: v53, a5: v52);
  HIDWORD(v55) = "ound traces";
  idGuiListBox::Printf(this: v54, fmt: "Remove Entity", a3: v55, a4: v57, a5: v56);
  v58 = idGuiListBox::Row(this: &v101);
  v62 = idGuiListBox::Printf(this: v58, fmt: "K - ", a3: v61, a4: v60, a5: v59);
  idGuiListBox::Printf(this: v62, fmt: "Kill Entity(suicide)", a3: v65, a4: v64, a5: v63);
  v66 = idGuiListBox::Row(this: &v101);
  LODWORD(v67) = "ound traces";
  v70 = idGuiListBox::Printf(this: v66, fmt: "HOME - ", a3: v69, a4: v68, a5: v67);
  HIDWORD(v71) = "ound traces";
  idGuiListBox::Printf(this: v70, fmt: "Teleport to", a3: v73, a4: v72, a5: v71);
  v74 = idGuiListBox::Row(this: &v101);
  LODWORD(v75) = "ound traces";
  v78 = idGuiListBox::Printf(this: v74, fmt: "END - ", a3: v77, a4: v75, a5: v76);
  HIDWORD(v79) = "ound traces";
  idGuiListBox::Printf(this: v78, fmt: "Delete Other", a3: v81, a4: v79, a5: v80);
  if ( AiByIndex != nullptr )
  {
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: AiByIndex) != 0 )
      v82 = "SHOW";
    else
      v82 = "HIDE";
    v83 = idGuiListBox::Row(this: &v101);
    v87 = idGuiListBox::Printf(this: v83, fmt: "INS - ", a3: v86, a4: v85, a5: v84);
    idGuiListBox::Printf(this: v87, fmt: v82, a3: v90, a4: v89, a5: v88);
  }
  idGuiListBox::Render(this: &v101, page: this, context, hAlign: 2u, vAlign: 0, nextTo: &v102);
  if ( AiByIndex != nullptr )
  {
    Physics = idEntity::GetPhysics(this: AiByIndex);
    v92 = gameLocal->GetRenderWorld(this: gameLocal);
    v93 = idEntity::GetPhysics(this: AiByIndex);
    v94 = (int)v93->GetAxis(this: v93, a2: 0);
    v95 = idEntity::GetPhysics(this: AiByIndex);
    v96 = (int)v95->GetOrigin(this: v95, a2: 0);
    v97 = v92->__vftable;
    v98 = (int)Physics->GetBounds(this: Physics, a2: -1);
    v97->DebugOrientedBounds(
      this: v92,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idBounds *)v98,
      a4: (const idVec3 *)v96,
      a5: (const idMat3 *)v94,
      a6: 1,
      a7: false);
  }
  idGuiListBox::~idGuiListBox(this: &v101);
  idGuiListBox::~idGuiListBox(this: &v102);
  if ( (v99.listStatic == 0 || v99.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$500529
// EA  : 0x82A4F728
// RVA : 0x00A4F728
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500529()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 672 + 128));
}


// ========================================================================
// __unwind$500530
// EA  : 0x82A4F750
// RVA : 0x00A4F750
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500530()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 672 + 336));
}


// ========================================================================
// __unwind$500531
// EA  : 0x82A4F778
// RVA : 0x00A4F778
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500531()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 672 + 160));
}


// ========================================================================
// ?InternalRender@idGuiPage2@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A4F7A8
// RVA : 0x00A4F7A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage2::InternalRender(idGuiPage2 *this, idAI2 *debugEnt, idDeviceContext *context)
{
  idAI2 *v5; // r3
  idAI2 *v6; // r30
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r26
  int tabNum; // r11
  int selectedRow; // r10
  int selectedColumn; // r9
  int selectedTab; // r7
  idGuiPageStatus *p_pageStatus; // r29
  idPhysics *Physics; // r3
  int v16; // r28
  double v17; // fp1
  idAngles *v18; // r3
  int entityNumber; // r27
  char *data; // r28
  double v21; // fp31
  const char *v22; // r25
  idGuiListBox *v23; // r3
  __int64 v24; // r10
  alertCycle_t AlertCycle; // r3
  const char *EnumName; // r25
  idGuiListBox *v27; // r3
  __int64 v28; // r8
  __int64 v29; // r10
  __int64 v30; // r6
  idGuiListBox *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  const char *v35; // r25
  idGuiListBox *v36; // r3
  __int64 v37; // r10
  __int64 v38; // r8
  __int64 v39; // r6
  idGuiListBox *v40; // r3
  __int64 v41; // r6
  __int64 v42; // r10
  __int64 v43; // r8
  const char *v44; // r25
  idGuiListBox *v45; // r3
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  idGuiListBox *v49; // r3
  __int64 v50; // r6
  __int64 v51; // r10
  __int64 v52; // r8
  idPhysics *v53; // r3
  float *v54; // r25
  idPhysics *v55; // r3
  float *v56; // r19
  idRenderWorld *v57; // r3
  double v58; // fp13
  double v59; // fp12
  double v60; // fp7
  double v61; // fp6
  idPhysics *v62; // r3
  int v63; // r19
  idPhysics *v64; // r3
  int v65; // r26
  idRenderWorld *v66; // r3
  int v67; // r3
  const char *v68; // r26
  idGuiListBox *v69; // r3
  __int64 v70; // r8
  __int64 v71; // r10
  __int64 v72; // r6
  idGuiListBox *v73; // r3
  __int64 v74; // r10
  __int64 v75; // r8
  __int64 v76; // r6
  int v77; // r3
  const char *v78; // r26
  idGuiListBox *v79; // r3
  __int64 v80; // r10
  __int64 v81; // r8
  __int64 v82; // r6
  idGuiListBox *v83; // r3
  __int64 v84; // r10
  __int64 v85; // r8
  __int64 v86; // r6
  idGameTimeManager *gameTimeManager; // r25
  idGuiListBox *v88; // r3
  __int64 v89; // r10
  __int64 v90; // r8
  __int64 v91; // r6
  idGuiListBox *v92; // r3
  __int64 v93; // r6
  __int64 v94; // r10
  __int64 v95; // r8
  idGameTimeManager *v96; // r26
  idGuiListBox *v97; // r3
  __int64 v98; // r8
  __int64 v99; // r10
  __int64 v100; // r6
  idGuiListBox *v101; // r3
  __int64 v102; // r6
  __int64 v103; // r10
  __int64 v104; // r8
  int v105; // r11
  int v106; // r6
  int v107; // r5
  int v108; // r10
  const char *v109; // r28
  idGuiListBox *v110; // r3
  __int64 v111; // r8
  __int64 v112; // r10
  __int64 v113; // r6
  idGuiListBox *v114; // r3
  __int64 v115; // r10
  __int64 v116; // r8
  __int64 v117; // r6
  const char *v118; // r28
  const char *v119; // r27
  idGuiListBox *v120; // r3
  __int64 v121; // r10
  __int64 v122; // r8
  __int64 v123; // r6
  idGuiListBox *v124; // r3
  __int64 v125; // r10
  __int64 v126; // r8
  __int64 v127; // r6
  const char *v128; // r27
  idGuiListBox *v129; // r3
  __int64 v130; // r10
  __int64 v131; // r8
  __int64 v132; // r6
  idGuiListBox *v133; // r3
  __int64 v134; // r10
  __int64 v135; // r8
  __int64 v136; // r6
  char v137; // r11
  idGuiListBox *v138; // r3
  __int64 v139; // r10
  __int64 v140; // r8
  __int64 v141; // r6
  idGuiListBox *v142; // r3
  __int64 v143; // r10
  __int64 v144; // r8
  __int64 v145; // r6
  char *v146; // r28
  idGuiListBox *v147; // r3
  __int64 v148; // r10
  __int64 v149; // r8
  __int64 v150; // r6
  idGuiListBox *v151; // r3
  __int64 v152; // r6
  __int64 v153; // r10
  __int64 v154; // r8
  idAngles *BodyOrientation; // r3
  const char *v156; // r28
  idGuiListBox *v157; // r3
  __int64 v158; // r10
  __int64 v159; // r8
  __int64 v160; // r6
  idGuiListBox *v161; // r3
  __int64 v162; // r10
  __int64 v163; // r6
  __int64 v164; // r8
  idAngles *MoveOrientation; // r3
  const char *v166; // r28
  idGuiListBox *v167; // r3
  __int64 v168; // r8
  __int64 v169; // r10
  __int64 v170; // r6
  idGuiListBox *v171; // r3
  __int64 v172; // r6
  __int64 v173; // r10
  __int64 v174; // r8
  idAnimWebCmdWaitHandle *activeWaitHandle; // r3
  char *v176; // r27
  idGuiListBox *v177; // r3
  __int64 v178; // r10
  __int64 v179; // r8
  __int64 v180; // r6
  idGuiListBox *v181; // r3
  __int64 v182; // r10
  __int64 v183; // r8
  __int64 v184; // r6
  char *v185; // r27
  idGuiListBox *v186; // r3
  __int64 v187; // r10
  __int64 v188; // r8
  __int64 v189; // r6
  idGuiListBox *v190; // r3
  __int64 v191; // r10
  __int64 v192; // r8
  __int64 v193; // r6
  bool v194; // r3
  int v195; // r11
  int v196; // r10
  int v197; // r9
  int v198; // r8
  int FullPath; // r30
  idClass *v200; // r29
  const char *Classname; // r28
  char *v202; // r24
  unsigned int v203; // r23
  const char *v204; // r22
  idGuiListBox *v205; // r3
  __int64 v206; // r10
  float v207[4]; // [sp+80h] [-350h] BYREF
  float v208[4]; // [sp+90h] [-340h] BYREF
  idStr v209; // [sp+A0h] [-330h] BYREF
  idStr v210; // [sp+C0h] [-310h] BYREF
  idStr v211; // [sp+E0h] [-2F0h] BYREF
  idGuiListBox v212; // [sp+100h] [-2D0h] BYREF
  idStr v213; // [sp+1B0h] [-220h] BYREF
  idStr v214; // [sp+1D0h] [-200h] BYREF
  idGuiListBox v215; // [sp+1F0h] [-1E0h] BYREF
  idGuiListBox v216; // [sp+2A0h] [-130h] BYREF

  this->pageStatus.tabNum = 0;
  v5 = idAI2::CastTo(c: debugEnt);
  v6 = v5;
  if ( v5 != nullptr )
  {
    value = v5->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    idGuiListBox::idGuiListBox(this: &v212);
    tabNum = this->pageStatus.tabNum;
    selectedRow = this->pageStatus.selectedRow;
    selectedColumn = this->pageStatus.selectedColumn;
    selectedTab = this->pageStatus.selectedTab;
    p_pageStatus = &this->pageStatus;
    this->pageStatus.tabNum = tabNum + 1;
    v212.tabNum = tabNum;
    v212.selectedRow = selectedRow;
    v212.selectedColumn = selectedColumn;
    v212.selectedTab = selectedTab;
    Physics = idEntity::GetPhysics(this: v6);
    v16 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v17 = ((double (__fastcall *)(idAIHealth *))v6->aiHealth.GetCurBaseHealth_Impl)(a1: &v6->aiHealth);
    v18 = (idAngles *)v16;
    entityNumber = v6->entityNumber;
    data = v6->name.data;
    v21 = v17;
    v22 = idVec3::ToString(this: v18, precision: 1);
    v23 = idGuiListBox::Row(this: &v212);
    HIDWORD(v24) = "ound traces";
    idGuiListBox::Printf(
      this: v23,
      fmt: "%s ( %d ) health %.2f : pos( %s )",
      a3: __SPAIR64__((unsigned int)data, entityNumber),
      a4: __SPAIR64__(LODWORD(v21), (unsigned int)v22),
      a5: v24,
      v21);
    AlertCycle = idAI2::GetAlertCycle(this: v6);
    EnumName = idTypeInfoTools::GetEnumName(
                 this: typeInfoTools,
                 enumTypeName: "alertCycle_t",
                 enumValue: AlertCycle,
                 defaultValue: "<unknown>");
    v27 = idGuiListBox::Row(this: &v212);
    HIDWORD(v28) = "ound traces";
    v31 = idGuiListBox::Printf(this: v27, fmt: "AlertCycle: ", a3: v30, a4: v28, a5: v29);
    idGuiListBox::Printf(this: v31, fmt: EnumName, a3: v34, a4: v33, a5: v32);
    v35 = idTypeInfoTools::GetEnumName(
            this: typeInfoTools,
            enumTypeName: "aiSubWeb_t",
            enumValue: v6->aiVolatile.animation.subWeb,
            defaultValue: "<unknown>");
    v36 = idGuiListBox::Row(this: &v212);
    LODWORD(v37) = "ound traces";
    v40 = idGuiListBox::Printf(this: v36, fmt: "SubWeb: ", a3: v39, a4: v38, a5: v37);
    HIDWORD(v41) = v35;
    idGuiListBox::Printf(this: v40, fmt: "%s", a3: v41, a4: v43, a5: v42);
    if ( v9 != nullptr )
      v44 = v9->name.data;
    else
      v44 = "<NONE>";
    v45 = idGuiListBox::Row(this: &v212);
    v49 = idGuiListBox::Printf(this: v45, fmt: "Enemy: ", a3: v48, a4: v47, a5: v46);
    HIDWORD(v50) = v44;
    idGuiListBox::Printf(this: v49, fmt: "%s", a3: v50, a4: v52, a5: v51);
    if ( v9 != nullptr )
    {
      v53 = idEntity::GetPhysics(this: v9);
      v54 = (float *)v53->GetOrigin(this: v53, a2: 0);
      v55 = idEntity::GetPhysics(this: v6);
      v56 = (float *)v55->GetOrigin(this: v55, a2: 0);
      v57 = gameLocal->GetRenderWorld(this: gameLocal);
      v58 = v54[2];
      v59 = v54[1];
      v208[0] = *v54;
      v208[1] = v59;
      v208[2] = (float)v58 + (float)60.0;
      v60 = (float)(v56[2] + (float)60.0);
      v61 = v56[1];
      v207[0] = *v56;
      v207[1] = v61;
      v207[2] = v60;
      v57->DebugLine(
        this: v57,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)v207,
        a4: (const idVec3 *)v208,
        a5: 0,
        a6: false);
      v62 = idEntity::GetPhysics(this: v9);
      v63 = (int)v62->GetBounds(this: v62, a2: -1);
      v64 = idEntity::GetPhysics(this: v9);
      v65 = (int)v64->GetAxis(this: v64, a2: 0);
      v66 = gameLocal->GetRenderWorld(this: gameLocal);
      v66->DebugOrientedBounds(
        this: v66,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idBounds *)v63,
        a4: (const idVec3 *)v54,
        a5: (const idMat3 *)v65,
        a6: 0,
        a7: false);
    }
    v67 = v6->GetWalkState(this: v6);
    v68 = idTypeInfoTools::GetEnumName(
            this: typeInfoTools,
            enumTypeName: "walkState_t",
            enumValue: v67,
            defaultValue: "<unknown>");
    v69 = idGuiListBox::Row(this: &v212);
    LODWORD(v70) = "ound traces";
    v73 = idGuiListBox::Printf(this: v69, fmt: "Walk State: ", a3: v72, a4: v70, a5: v71);
    idGuiListBox::Printf(this: v73, fmt: v68, a3: v76, a4: v75, a5: v74);
    v77 = v6->GetPosture(this: v6);
    v78 = idTypeInfoTools::GetEnumName(
            this: typeInfoTools,
            enumTypeName: "posture_t",
            enumValue: v77,
            defaultValue: "<unknown>");
    v79 = idGuiListBox::Row(this: &v212);
    v83 = idGuiListBox::Printf(this: v79, fmt: "Posture: ", a3: v82, a4: v81, a5: v80);
    idGuiListBox::Printf(this: v83, fmt: v78, a3: v86, a4: v85, a5: v84);
    gameTimeManager = idAnimator_AnimWeb::GetCurWebPath(
                        this: (idAnimator_AnimWeb *)&v214,
                        result: (idAnimator_AnimWeb *)&v6->aiVolatile.animation,
                        includeWebName: false)->gametimeManager.gameTimeManager;
    v88 = idGuiListBox::Row(this: &v212);
    HIDWORD(v89) = "ound traces";
    v92 = idGuiListBox::Printf(this: v88, fmt: "Cur Anim: ", a3: v91, a4: v90, a5: v89);
    HIDWORD(v93) = gameTimeManager;
    idGuiListBox::Printf(this: v92, fmt: "%s", a3: v93, a4: v95, a5: v94);
    idStr::FreeData(this: &v214);
    v96 = idAnimator_AnimWeb::GetDestWebPath(
            this: (idAnimator_AnimWeb *)&v213,
            result: (idAnimWebPath *)&v6->aiVolatile.animation,
            includeWebName: false)->gametimeManager.gameTimeManager;
    v97 = idGuiListBox::Row(this: &v212);
    HIDWORD(v98) = "ound traces";
    v101 = idGuiListBox::Printf(this: v97, fmt: "Dest Anim: ", a3: v100, a4: v98, a5: v99);
    HIDWORD(v102) = v96;
    idGuiListBox::Printf(this: v101, fmt: "%s", a3: v102, a4: v104, a5: v103);
    idStr::FreeData(this: &v213);
    idGuiListBox::idGuiListBox(this: &v216);
    v105 = this->pageStatus.tabNum;
    v106 = p_pageStatus->selectedRow;
    v107 = this->pageStatus.selectedColumn;
    v108 = this->pageStatus.selectedTab;
    this->pageStatus.tabNum = v105 + 1;
    v216.tabNum = v105;
    v216.selectedRow = v106;
    v216.selectedColumn = v107;
    v216.selectedTab = v108;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)v6) != 0 )
      v6->aiVolatile.animation.animFSM.PrintDebugInfo(this: &v6->aiVolatile.animation.animFSM, a2: &v216);
    v109 = idTypeInfoTools::GetEnumName(
             this: typeInfoTools,
             enumTypeName: "aiFireMode_t",
             enumValue: v6->aiVolatile.fireControl->fireMode,
             defaultValue: "<unknown>");
    v110 = idGuiListBox::Row(this: &v212);
    HIDWORD(v111) = "ound traces";
    v114 = idGuiListBox::Printf(this: v110, fmt: "Fire Mode: ", a3: v113, a4: v111, a5: v112);
    idGuiListBox::Printf(this: v114, fmt: v109, a3: v117, a4: v116, a5: v115);
    v118 = "on";
    v119 = "on";
    if ( !idAI2::GetEnableHeadTracking(this: v6) )
      v119 = "off";
    v120 = idGuiListBox::Row(this: &v212);
    v124 = idGuiListBox::Printf(this: v120, fmt: "Head Tracking: ", a3: v123, a4: v122, a5: v121);
    idGuiListBox::Printf(this: v124, fmt: v119, a3: v127, a4: v126, a5: v125);
    v128 = "on";
    if ( !v6->aiVolatile.focus.enableBodyRotation )
      v128 = "off";
    v129 = idGuiListBox::Row(this: &v212);
    v133 = idGuiListBox::Printf(this: v129, fmt: "Body Orient: ", a3: v132, a4: v131, a5: v130);
    idGuiListBox::Printf(this: v133, fmt: v128, a3: v136, a4: v135, a5: v134);
    if ( !v6->walkIK.enabled || (v137 = 1, v6->walkIK.enabledLegs == 0) )
      v137 = 0;
    if ( v137 == 0 )
      v118 = "off";
    v138 = idGuiListBox::Row(this: &v212);
    v142 = idGuiListBox::Printf(this: v138, fmt: "WalkIK: ", a3: v141, a4: v140, a5: v139);
    idGuiListBox::Printf(this: v142, fmt: v118, a3: v145, a4: v144, a5: v143);
    if ( idEntity::GetBindMaster(this: v6) != nullptr )
      v146 = idEntity::GetBindMaster(this: v6)->name.data;
    else
      v146 = &byte_8200D768;
    v147 = idGuiListBox::Row(this: &v212);
    v151 = idGuiListBox::Printf(this: v147, fmt: "Bind Master: ", a3: v150, a4: v149, a5: v148);
    HIDWORD(v152) = v146;
    idGuiListBox::Printf(this: v151, fmt: "%s", a3: v152, a4: v154, a5: v153);
    BodyOrientation = (idAngles *)idAI2::GetBodyOrientation(this: v6);
    v156 = idVec3::ToString(this: BodyOrientation, precision: 2);
    v157 = idGuiListBox::Row(this: &v212);
    LODWORD(v158) = "ound traces";
    v161 = idGuiListBox::Printf(this: v157, fmt: "BodyOrient: ", a3: v160, a4: v159, a5: v158);
    HIDWORD(v162) = "ound traces";
    HIDWORD(v163) = v156;
    idGuiListBox::Printf(this: v161, fmt: "( %s )", a3: v163, a4: v164, a5: v162);
    MoveOrientation = (idAngles *)idAI2::GetMoveOrientation(this: v6);
    v166 = idVec3::ToString(this: MoveOrientation, precision: 2);
    v167 = idGuiListBox::Row(this: &v212);
    LODWORD(v168) = "ound traces";
    v171 = idGuiListBox::Printf(this: v167, fmt: "MoveOrient: ", a3: v170, a4: v168, a5: v169);
    HIDWORD(v172) = v166;
    idGuiListBox::Printf(this: v171, fmt: "( %s )", a3: v172, a4: v174, a5: v173);
    activeWaitHandle = v6->GetAnimWebCmdCtx(this: v6)->activeWaitHandle;
    v210.len = 0;
    v210.allocedAndFlag = 20;
    v210.data = v210.baseBuffer;
    v210.baseBuffer[0] = 0;
    v211.allocedAndFlag = 20;
    v211.data = v211.baseBuffer;
    v211.len = 0;
    v211.baseBuffer[0] = 0;
    if ( activeWaitHandle != nullptr )
      idAnimWebCmdWaitHandle::GetDebugString(this: activeWaitHandle, info: &v210, waitPath: &v211);
    v176 = v210.data;
    v177 = idGuiListBox::Row(this: &v212);
    v181 = idGuiListBox::Printf(this: v177, fmt: "Wait Handle: ", a3: v180, a4: v179, a5: v178);
    idGuiListBox::Printf(this: v181, fmt: v176, a3: v184, a4: v183, a5: v182);
    v185 = v211.data;
    v186 = idGuiListBox::Row(this: &v212);
    LODWORD(v187) = "ound traces";
    v190 = idGuiListBox::Printf(this: v186, fmt: "Wait Anim: ", a3: v189, a4: v188, a5: v187);
    idGuiListBox::Printf(this: v190, fmt: v185, a3: v193, a4: v192, a5: v191);
    v194 = common->IsMultiplayer(this: common);
    idGuiListBox::Render(
      this: &v212,
      page: this,
      context,
      hAlign: 0,
      vAlign: (_cntlzw(v194) & 0x20) != 0,
      nextTo: nullptr);
    idGuiListBox::Render(this: &v216, page: this, context, hAlign: 1u, vAlign: 2u, nextTo: &v212);
    idGuiListBox::idGuiListBox(this: &v215);
    v195 = this->pageStatus.tabNum;
    v196 = this->pageStatus.selectedTab;
    v197 = this->pageStatus.selectedColumn;
    v198 = p_pageStatus->selectedRow;
    this->pageStatus.tabNum = v195 + 1;
    v215.tabNum = v195;
    v215.selectedTab = v196;
    v215.selectedColumn = v197;
    v215.selectedRow = v198;
    FullPath = (int)v6->aiVolatile.fsms.fsmManager.GetControllingFSM_2(this: &v6->aiVolatile.fsms.fsmManager);
    if ( FullPath != 0 )
    {
      v209.allocedAndFlag = 20;
      v209.len = 0;
      v209.data = v209.baseBuffer;
      v209.baseBuffer[0] = 0;
      do
      {
        v200 = *(idClass **)(FullPath + 40);
        idStr::operator=(this: &v209, text: &byte_8200D768);
        if ( v200 != nullptr )
        {
          ((void (__fastcall *)(idClass *, idStr *))v200->__vftable[7].GetType)(a1: v200, a2: &v209);
          Classname = idClass::GetClassname(this: v200);
        }
        else
        {
          Classname = "-";
        }
        v202 = v209.data;
        v203 = *(_DWORD *)(FullPath + 36);
        v204 = idAIStateTransition::NameForTransitionCode(tc: *(const idAIStateTransition::aiTransCode_t *)(FullPath + 60));
        v205 = idGuiListBox::Row(this: &v215);
        idGuiListBox::Printf(
          this: v205,
          fmt: "%s:%s %s %s",
          a3: __SPAIR64__(v203, (unsigned int)Classname),
          a4: __SPAIR64__((unsigned int)v204, (unsigned int)v202),
          a5: v206);
        if ( v200 == nullptr )
          break;
        FullPath = idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)v200);
      }
      while ( FullPath != 0 );
      idStr::FreeData(this: &v209);
    }
    idGuiListBox::Render(this: &v215, page: this, context, hAlign: 2u, vAlign: 1u, nextTo: nullptr);
    idGuiListBox::~idGuiListBox(this: &v215);
    idStr::FreeData(this: &v211);
    idStr::FreeData(this: &v210);
    idGuiListBox::~idGuiListBox(this: &v216);
    idGuiListBox::~idGuiListBox(this: &v212);
  }
}


// ========================================================================
// __unwind$500707
// EA  : 0x82A500A8
// RVA : 0x00A500A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500707()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 976 + 256));
}


// ========================================================================
// __unwind$500708
// EA  : 0x82A500D0
// RVA : 0x00A500D0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500708()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 464));
}


// ========================================================================
// __unwind$500709
// EA  : 0x82A500F8
// RVA : 0x00A500F8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500709()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 432));
}


// ========================================================================
// __unwind$500710
// EA  : 0x82A50120
// RVA : 0x00A50120
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500710()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 976 + 672));
}


// ========================================================================
// __unwind$500711
// EA  : 0x82A50148
// RVA : 0x00A50148
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500711()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 192));
}


// ========================================================================
// __unwind$500712
// EA  : 0x82A50170
// RVA : 0x00A50170
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500712()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 224));
}


// ========================================================================
// __unwind$500713
// EA  : 0x82A50198
// RVA : 0x00A50198
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500713()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 976 + 496));
}


// ========================================================================
// __unwind$500714
// EA  : 0x82A501C0
// RVA : 0x00A501C0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_500714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 160));
}


// ========================================================================
// ?InternalRender@idGuiPage5@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A501F0
// RVA : 0x00A501F0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPage5::InternalRender(idGuiPage5 *this, idAI2 *debugEnt, idDeviceContext *context)
{
  idAI2 *v5; // r23
  int i; // r28
  const idFSMLogEntry *v7; // r3
  const idFSMLogEntry *v8; // r30
  const idTypeInfo *curStateType; // r11
  const char *v10; // r4
  const idTypeInfo *nextStateType; // r11
  const char *v12; // r4
  const idTypeInfo *transitionType; // r11
  const char *v14; // r4
  char *data; // r20
  char *v16; // r19
  char *v17; // r18
  const char *str; // r17
  const char *v19; // r16
  int time; // r30
  idGuiListBox *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  idGuiListBox *v25; // r3
  __int64 v26; // r10
  idAIAction *CurrentAction; // r3
  __int64 v28; // r29
  int lastTransitionTime; // r30
  const char *v30; // r27
  idGuiListBox *v31; // r3
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  idGuiListBox *v35; // r3
  __int64 v36; // r10
  __int64 v37; // r8
  idStr v38; // [sp+90h] [-250h] BYREF
  idStr v39; // [sp+B0h] [-230h] BYREF
  idStr v40; // [sp+D0h] [-210h] BYREF
  idGuiListBox v41; // [sp+F0h] [-1F0h] BYREF
  idGuiListBox v42; // [sp+1A0h] [-140h] BYREF

  v5 = idAI2::CastTo(c: debugEnt);
  if ( v5 != nullptr )
  {
    idGuiListBox::idGuiListBox(this: &v41);
    for ( i = 0; i < 20; ++i )
    {
      v7 = idFSMLog::FromLast(this: &v5->fsmCallback.log, i);
      v8 = v7;
      if ( v7 == nullptr )
        break;
      curStateType = v7->curStateType;
      v10 = curStateType != nullptr ? curStateType->classname : "<?>";
      idStr::idStr(this: &v38, text: v10);
      nextStateType = v8->nextStateType;
      v12 = nextStateType != nullptr ? nextStateType->classname : "<?>";
      idStr::idStr(this: &v40, text: v12);
      transitionType = v8->transitionType;
      v14 = transitionType != nullptr ? transitionType->classname : "<?>";
      idStr::idStr(this: &v39, text: v14);
      idStr::StripUntil(this: &v38, until: "_");
      idStr::StripUntil(this: &v40, until: "_");
      idStr::StripUntil(this: &v39, until: "_");
      data = v39.data;
      v16 = v38.data;
      v17 = v40.data;
      str = v8->fsm->name.str;
      v19 = idAIStateTransition::NameForTransitionCode(tc: (const idAIStateTransition::aiTransCode_t)v8->transCode);
      time = v8->time;
      v21 = idGuiListBox::Row(this: &v41);
      HIDWORD(v22) = time;
      v25 = idGuiListBox::Printf(this: v21, fmt: "FSM( %8d )", a3: v22, a4: v24, a5: v23);
      HIDWORD(v26) = v17;
      idGuiListBox::Printf(
        this: v25,
        fmt: "%s::%s (%s, %s) -> %s",
        a3: __SPAIR64__((unsigned int)str, (unsigned int)v16),
        a4: __SPAIR64__((unsigned int)data, (unsigned int)v19),
        a5: v26);
      idStr::FreeData(this: &v39);
      idStr::FreeData(this: &v40);
      idStr::FreeData(this: &v38);
    }
    idGuiListBox::Render(this: &v41, page: this, context, hAlign: 0, vAlign: 1u, nextTo: nullptr);
    idGuiListBox::idGuiListBox(this: &v42);
    if ( idAIActionFSM::GetCurrentAction(this: &v5->aiVolatile.fsms.actionManager.legsFSM) != nullptr )
    {
      CurrentAction = idAIActionFSM::GetCurrentAction(this: &v5->aiVolatile.fsms.actionManager.legsFSM);
      LODWORD(v28) = *(_DWORD *)CurrentAction->GetType(this: CurrentAction);
    }
    else
    {
      LODWORD(v28) = &byte_8200D768;
    }
    HIDWORD(v28) = v5->aiVolatile.fsms.actionManager.legsFSM.name.str;
    lastTransitionTime = v5->aiVolatile.fsms.actionManager.legsFSM.lastTransitionTime;
    v30 = idAIStateTransition::NameForTransitionCode(tc: (const idAIStateTransition::aiTransCode_t)v5->aiVolatile.fsms.actionManager.legsFSM.lastTransitionCode);
    v31 = idGuiListBox::Row(this: &v41);
    HIDWORD(v32) = lastTransitionTime;
    v35 = idGuiListBox::Printf(this: v31, fmt: "ACTIONFSM( %8d )", a3: v32, a4: v34, a5: v33);
    LODWORD(v36) = "ound traces";
    HIDWORD(v37) = v30;
    idGuiListBox::Printf(this: v35, fmt: "%s::%s (%s)", a3: v28, a4: v37, a5: v36);
    idGuiListBox::Render(this: &v42, page: this, context, hAlign: 1u, vAlign: 2u, nextTo: &v41);
    idGuiListBox::~idGuiListBox(this: &v42);
    idGuiListBox::~idGuiListBox(this: &v41);
  }
}


// ========================================================================
// __unwind$501141
// EA  : 0x82A5043C
// RVA : 0x00A5043C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501141()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 736 + 240));
}


// ========================================================================
// __unwind$501142
// EA  : 0x82A50464
// RVA : 0x00A50464
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501142()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 144));
}


// ========================================================================
// __unwind$501143
// EA  : 0x82A5048C
// RVA : 0x00A5048C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501143()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 208));
}


// ========================================================================
// __unwind$501144
// EA  : 0x82A504B4
// RVA : 0x00A504B4
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501144()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 176));
}


// ========================================================================
// __unwind$501145
// EA  : 0x82A504DC
// RVA : 0x00A504DC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501145()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 736 + 416));
}


// ========================================================================
// ?RenderAIGuiBase@idAIGUI@@AAAXAAVidDeviceContext@@@Z
// EA  : 0x82A50510
// RVA : 0x00A50510
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::RenderAIGuiBase(idAIGUI *this, idDeviceContext *context)
{
  int num; // r10
  int v5; // r30
  int v6; // r29
  idGuiPage *v7; // r10
  const char *data; // r25
  idGuiListBox *v9; // r3
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  idGuiListBox *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox v17; // [sp+80h] [-F0h] BYREF

  if ( aigui.valueInteger != 0 )
  {
    idGuiListBox::idGuiListBox(this: &v17);
    num = this->pages.num;
    v5 = 0;
    v17.selectedRow = aigui.valueInteger - 1;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        v7 = this->pages.list[v6];
        if ( v7 != nullptr )
        {
          data = v7->pageName.data;
          v9 = idGuiListBox::Row(this: &v17);
          HIDWORD(v10) = v5;
          v13 = idGuiListBox::Printf(this: v9, fmt: "KP %d - ", a3: v10, a4: v12, a5: v11);
          idGuiListBox::Printf(this: v13, fmt: data, a3: v16, a4: v15, a5: v14);
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->pages.num );
    }
    idGuiListBox::Render(this: &v17, page: nullptr, context, hAlign: 1u, vAlign: 1u, nextTo: nullptr);
    idGuiListBox::~idGuiListBox(this: &v17);
  }
}


// ========================================================================
// __unwind$501476
// EA  : 0x82A505E8
// RVA : 0x00A505E8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501476()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 368 + 128));
}


// ========================================================================
// ?DrawDebugGUI@idAIGUI@@QAAPAVidRenderModelGui@@PBVidEntity@@@Z
// EA  : 0x82A50618
// RVA : 0x00A50618
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idRenderModelGui *__fastcall idAIGUI::DrawDebugGUI(idAIGUI *this, const idEntity *ent)
{
  idAI2 *DebugAi; // r28
  int v4; // r7
  unsigned __int64 v5; // r6
  idRenderModelGui *v7; // r3
  idRenderModelGui *v8; // r3
  unsigned int v9; // r29
  unsigned int v10; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r5
  int v16; // r4
  __int64 v17; // r8
  int v18; // r5
  int v19; // r4
  int VirtualWidth; // r11
  __int64 v21; // r8
  int v22; // r5
  int v23; // r4
  int VirtualHeight; // r11
  __int64 v25; // r5
  __int64 v26; // r11
  int v27; // [sp+8h] [-5A8h]
  int v28; // [sp+Ch] [-5A4h]
  int v29; // [sp+10h] [-5A0h]
  int v30; // [sp+14h] [-59Ch]
  int v31; // [sp+18h] [-598h]
  int v32; // [sp+1Ch] [-594h]
  int v33; // [sp+20h] [-590h]
  int v34; // [sp+24h] [-58Ch]
  int v35; // [sp+28h] [-588h]
  int v36; // [sp+2Ch] [-584h]
  int v37; // [sp+30h] [-580h]
  int v38; // [sp+34h] [-57Ch]
  int v39; // [sp+38h] [-578h]
  int v40; // [sp+3Ch] [-574h]
  int v41; // [sp+40h] [-570h]
  int v42; // [sp+44h] [-56Ch]
  int v43; // [sp+48h] [-568h]
  int v44; // [sp+4Ch] [-564h]
  int v45; // [sp+50h] [-560h]
  int v46; // [sp+54h] [-55Ch]
  int v47; // [sp+58h] [-558h]
  idDeviceContext v48; // [sp+70h] [-540h] BYREF

  DebugAi = idAIGUI::GetDebugAi(this);
  if ( DebugAi == nullptr )
    return nullptr;
  if ( this->guiModel == nullptr )
  {
    v7 = (idRenderModelGui *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA410u,
                               tag: TAG_GUI_MODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
      v8 = idRenderModelGui::idRenderModelGui(this: v7);
    else
      v8 = nullptr;
    this->guiModel = v8;
  }
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: v5,
    a4: v4);
  v9 = renderSystem->GetHeight(this: renderSystem);
  v10 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v10, height: v9);
  idRenderModelGui::SetupMonospaceFont(
    this: this->guiModel,
    drawWidth: 10.0,
    a3: v16,
    a4: v15,
    a5: 0x82000000,
    a6: v14,
    a7: v13,
    a8: v12,
    a9: v11);
  idDeviceContext::idDeviceContext(this: &v48, guiModel: this->guiModel);
  idDeviceContext::SetFont(this: &v48, font: (const idFont *)monospaceFont.r);
  if ( ai_showBlendTreeWeb.valueInteger != 0 )
    idAnimWebAI::DebugDrawNodes(this: DebugAi->aiVolatile.animation.animWebAnimator.ptr, gui: this->guiModel);
  idAIGUI::RenderActivePages(this, context: &v48);
  if ( aigui.valueInteger == 0 )
    return nullptr;
  idAIGUI::RenderAIGuiBase(this, context: &v48);
  if ( aigui.valueInteger >= 0 && aigui.valueInteger < this->pages.num )
    idGuiPage::Render(this: this->pages.list[aigui.valueInteger], debugEnt: DebugAi, context: &v48);
  VirtualWidth = (int)idRenderModelGui::GetVirtualWidth(this: this->guiModel, a2: v19, a3: v18, a4: v17);
  if ( idAIGUI::mouseX < VirtualWidth )
    VirtualWidth = idAIGUI::mouseX;
  LODWORD(v21) = (VirtualWidth == 0) + ((unsigned int)VirtualWidth >> 31) - 1;
  idAIGUI::mouseX = v21 & VirtualWidth;
  VirtualHeight = (int)idRenderModelGui::GetVirtualHeight(this: this->guiModel, a2: v23, a3: v22, a4: v21);
  if ( idAIGUI::mouseY < VirtualHeight )
    VirtualHeight = idAIGUI::mouseY;
  LODWORD(v26) = ((VirtualHeight == 0) + ((unsigned int)VirtualHeight >> 31) - 1) & VirtualHeight;
  idAIGUI::mouseY = v26;
  if ( idAIGUI::usingMouse && mouseCursor.r != nullptr )
  {
    HIDWORD(v26) = idAIGUI::mouseX;
    LODWORD(v25) = idAIGUI::mouseX;
    idRenderModelGui::DrawStretchPic(
      this: this->guiModel,
      x: (float)v25,
      y: (float)v26,
      w: 32.0,
      h: 32.0,
      s1: 0.0,
      t1: 0.0,
      s2: 1.0,
      t2: 1.0,
      material: (const idMaterial *)HIDWORD(v25),
      a11: idAIGUI::mouseX,
      a12: (int)&unk_82150000,
      a13: 0x82000000,
      a14: 0x82000000,
      a15: (int)mouseCursor.r,
      a16: idAIGUI::mouseX,
      a17: v27,
      a18: v28,
      a19: v29,
      a20: v30,
      a21: v31,
      a22: v32,
      a23: v33,
      a24: v34,
      a25: v35,
      a26: v36,
      a27: v37,
      a28: v38,
      a29: v39,
      a30: v40,
      a31: v41,
      a32: v42,
      a33: v43,
      a34: v44,
      a35: v45,
      a36: v46,
      a37: v47,
      a38: (const idMaterial *)mouseCursor.r);
  }
  return this->guiModel;
}


// ========================================================================
// __unwind$501532
// EA  : 0x82A508A8
// RVA : 0x00A508A8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501532()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1456 + 96), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ??0idGuiPageEntityList@@QAA@XZ
// EA  : 0x82A50940
// RVA : 0x00A50940
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPageEntityList *__fastcall idGuiPageEntityList::idGuiPageEntityList(idGuiPageEntityList *this)
{
  idStr v3; // [sp+60h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "Action List");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->selectedIndex = 0;
  this->__vftable = (idGuiPageEntityList_vtbl *)&idGuiPageEntityList::`vftable';
  this->entityList.granularity = 0;
  this->entityList.memTag = 5;
  this->entityList.listStatic = 0;
  this->entityList.list = nullptr;
  this->entityList.size = 0;
  this->entityList.num = 0;
  return this;
}


// ========================================================================
// __unwind$501741
// EA  : 0x82A509D8
// RVA : 0x00A509D8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$501742
// EA  : 0x82A50A00
// RVA : 0x00A50A00
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_501742()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 160 + 180));
}


// ========================================================================
// ?IsEnabled@idGuiPageEntityList@@UBA_NXZ
// EA  : 0x82A50A90
// RVA : 0x00A50A90
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

BOOL __fastcall idGuiPageEntityList::IsEnabled(idGuiPageEntityList *this)
{
  return g_showEntityWarnings.valueInteger != 0;
}


// ========================================================================
// ?InternalHandleEvent@idGuiPageEntityList@@EAA_NPBUsysEvent_t@@@Z
// EA  : 0x82A50AA8
// RVA : 0x00A50AA8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

int __fastcall idGuiPageEntityList::InternalHandleEvent(idGuiPageEntityList *this, const sysEvent_t *event)
{
  idPlayer *DebugPlayer; // r29
  int evValue; // r10
  char v6; // r11
  char v8; // r11
  char v9; // r11
  int selectedIndex; // r11
  idEntity *v11; // r30
  char *v12; // r10
  float *p_y; // r11
  int v14; // ctr
  idPhysics *Physics; // r3
  idPhysics *v16; // r3
  const idAngles *v17; // r3
  idVec3 v18; // [sp+50h] [-80h] BYREF
  float v19[4]; // [sp+60h] [-70h] BYREF
  idVec3 v20; // [sp+70h] [-60h] BYREF
  char v21; // [sp+7Ch] [-54h] BYREF
  idAngles v22[6]; // [sp+80h] [-50h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer == nullptr || event->evType != SE_KEY || event->evValue2 == 0 )
    return 0;
  evValue = event->evValue;
  if ( evValue == 200 || (v6 = 0, evValue == 282) )
    v6 = 1;
  if ( v6 != 0 )
  {
    --this->selectedIndex;
    return 1;
  }
  if ( evValue == 208 || (v8 = 0, evValue == 283) )
    v8 = 1;
  if ( v8 != 0 )
  {
    ++this->selectedIndex;
    return 1;
  }
  if ( evValue == 28 || evValue == 156 || (v9 = 0, evValue == 256) )
    v9 = 1;
  if ( v9 == 0 )
    return 0;
  selectedIndex = this->selectedIndex;
  if ( selectedIndex > -1 )
  {
    v11 = idEntityPtr<idEntity const>::operator->(this: &this->entityList.list[selectedIndex].ent);
    if ( v11 != nullptr )
    {
      idPlayer::SetNoclip(this: DebugPlayer, v: true);
      v12 = &v21;
      p_y = &mat2_identity.mat[1].y;
      v14 = 9;
      v18 = vec3_origin;
      do
      {
        ++p_y;
        v12 += 4;
        *(float *)v12 = *p_y;
        --v14;
      }
      while ( v14 != 0 );
      v11->GetModelTransform(this: v11, a2: &v18, a3: (idMat3 *)v22);
      v19[0] = v18.x - (float)(v22[0].pitch * (float)128.0);
      v19[1] = v18.y - (float)(v22[0].yaw * (float)128.0);
      v19[2] = v18.z - (float)(v22[0].roll * (float)128.0);
      Physics = idEntity::GetPhysics(this: DebugPlayer);
      Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v19, a3: -1);
      v16 = idEntity::GetPhysics(this: DebugPlayer);
      v16->SetAxis(this: v16, a2: &mat3_identity, a3: -1);
      v17 = idVec3::ToAngles(this: &v20, result: v22);
      idPlayer::SetViewAngles(this: DebugPlayer, angles: v17, force: true);
    }
  }
  return 1;
}


// ========================================================================
// ?AllWarnings@entityInfo_t@idGuiPageEntityList@@QBA?AVidStr@@PBD@Z
// EA  : 0x82A50CF0
// RVA : 0x00A50CF0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

idGuiPageEntityList::entityInfo_t *__fastcall idGuiPageEntityList::entityInfo_t::AllWarnings(
        idGuiPageEntityList::entityInfo_t *this,
        idStr *result,
        char *delimiter)
{
  int v6; // r29
  int v7; // r28

  v6 = 0;
  this->ent.spawnId.value = 0;
  this->warnings.num = 20;
  this->warnings.list = (idStr *)&this->warnings.size;
  HIBYTE(this->warnings.size) = 0;
  if ( result->allocedAndFlag > 0 )
  {
    v7 = 0;
    do
    {
      idStr::Append((idStr *)this, text: (const idStr *)&result->data[v7]);
      idStr::Append((idStr *)this, text: delimiter);
      ++v6;
      v7 += 32;
    }
    while ( v6 < result->allocedAndFlag );
  }
  return this;
}


// ========================================================================
// __unwind$502248
// EA  : 0x82A50D84
// RVA : 0x00A50D84
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502248()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 144;
  if ( (*(_DWORD *)(v0 - 144 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 164));
  }
}


// ========================================================================
// ?AddWarnings@uniqueWarnings_t@idGuiPageEntityList@@QAAXABV?$idList@VidStr@@$04@@@Z
// EA  : 0x82A51110
// RVA : 0x00A51110
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPageEntityList::uniqueWarnings_t::AddWarnings(
        idGuiPageEntityList::uniqueWarnings_t *this,
        const idList<idStr,5> *warnings)
{
  int v4; // r23
  int v5; // r27
  char v6; // r28
  int v7; // r29
  int v8; // r30
  int num; // r11
  int size; // r10
  idGuiPageEntityList::uniqueWarnings_t::warning_t *list; // r10
  idGuiPageEntityList::uniqueWarnings_t::warning_t *v12; // r30
  unsigned int allocedAndFlag; // r11
  idStr *v14; // r28
  int v15; // r11
  size_t len; // r29
  int v17; // r4
  bool v18; // zf

  v4 = 0;
  if ( warnings->num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = 0;
      v7 = 0;
      if ( this->uniques.num > 0 )
      {
        v8 = 0;
        while ( idStr::Cmp(s1: this->uniques.list[v8].warning.data, s2: warnings->list[v5].data) != 0 )
        {
          ++v7;
          ++v8;
          if ( v7 >= this->uniques.num )
            goto LABEL_9;
        }
        v6 = 1;
        ++this->uniques.list[v7].count;
      }
LABEL_9:
      if ( v6 == 0 )
      {
        idList<idGuiPageEntityList::uniqueWarnings_t::warning_t,5>::PreAllocateWithGranularity(
          this: &this->uniques,
          newSize: this->uniques.num + 1);
        num = this->uniques.num;
        size = this->uniques.size;
        if ( num >= size )
        {
          v12 = &this->uniques.list[size - 1];
        }
        else
        {
          list = this->uniques.list;
          this->uniques.num = num + 1;
          v12 = &list[num];
        }
        allocedAndFlag = v12->warning.allocedAndFlag;
        v14 = &warnings->list[v5];
        len = v14->len;
        v17 = v14->len + 1;
        v18 = allocedAndFlag >> 31 == 0;
        v15 = allocedAndFlag & 0x7FFFFFFF;
        if ( v18 )
        {
          if ( v17 > v15 )
            idStr::ReAllocate(this: &v12->warning, amount: v17, keepold: false);
        }
        else if ( v17 > v15
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v12->warning.data, Src: v14->data, Size: len);
        v12->warning.data[len] = 0;
        v12->warning.len = len;
        v12->count = 1;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < warnings->num );
  }
}


// ========================================================================
// ?InternalRender@idGuiPageEntityList@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82A51468
// RVA : 0x00A51468
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idGuiPageEntityList::InternalRender(
        idGuiPageEntityList *this,
        idEntity *debugEnt,
        idDeviceContext *context)
{
  idList<idGuiPageEntityList::entityInfo_t,5> *p_entityList; // r18
  int size; // r11
  int v7; // r29
  idGameLocal *v8; // r10
  int v9; // r11
  int v10; // r11
  idEntity *v11; // r3
  idEntity *v12; // r3
  int num; // r10
  int v14; // r20
  int v15; // r21
  idStr *v16; // r29
  idStr *list; // r28
  idEntity *v18; // r3
  idEntity *v19; // r11
  const char *data; // r27
  idGuiListBox *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  idGuiListBox *v25; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idEntity *v29; // r3
  idEntity *v30; // r3
  idRenderWorld *v31; // r27
  idGuiPageEntityList::entityInfo_t *v32; // r28
  idEntity *v33; // r3
  idEntity *v34; // r3
  idPhysics *Physics; // r3
  int v36; // r3
  int v37; // r29
  __int64 v38; // r10
  int v39; // r11
  idStr *v40; // r28
  __int64 v41; // r8
  idEntity *v42; // r3
  idEntity *v43; // r3
  __int64 v44; // r6
  va *v45; // r3
  int selectedIndex; // r11
  __int64 v47; // r10
  __int64 v48; // r8
  __int64 v49; // r6
  __int64 v50; // r10
  __int64 v51; // r8
  __int64 v52; // r6
  int v53; // r29
  int v54; // r28
  __int64 v55; // r10
  __int64 v56; // r8
  idGuiPageEntityList::uniqueWarnings_t::warning_t *v57; // r27
  int *p_count; // r29
  int i; // r30
  int v60; // r26
  __int64 v61; // r6
  __int64 v62; // r10
  __int64 v63; // r8
  int v64; // r30
  idStr *p_warning; // r29
  int v66; // [sp+8h] [-12F8h]
  int v67; // [sp+Ch] [-12F4h]
  int v68; // [sp+10h] [-12F0h]
  int v69; // [sp+14h] [-12ECh]
  int v70; // [sp+18h] [-12E8h]
  int v71; // [sp+1Ch] [-12E4h]
  idGuiListBox::row_t v72; // [sp+70h] [-1290h] BYREF
  idGuiPageEntityList::entityInfo_t v73; // [sp+80h] [-1280h] BYREF
  idGuiPageEntityList::uniqueWarnings_t v74; // [sp+A0h] [-1260h] BYREF
  int v75; // [sp+B0h] [-1250h]
  int v76; // [sp+C0h] [-1240h]
  int v77; // [sp+C4h] [-123Ch]
  int v78; // [sp+C8h] [-1238h]
  __int16 v79; // [sp+CCh] [-1234h]
  char v80; // [sp+CEh] [-1232h]
  char v81; // [sp+CFh] [-1231h]
  idGuiListBox v82; // [sp+D0h] [-1230h] BYREF
  idStr v83; // [sp+180h] [-1180h] BYREF
  idStr v84; // [sp+1A0h] [-1160h] BYREF
  idGuiListBox v85; // [sp+1C0h] [-1140h] BYREF
  va v86; // [sp+270h] [-1090h] BYREF

  p_entityList = &this->entityList;
  if ( this->entityList.size < 0 )
    idList<idGuiPageEntityList::entityInfo_t,5>::Clear(this: &this->entityList);
  size = p_entityList->size;
  *(_WORD *)&v74.uniques.memTag = 1280;
  memset(&v74, 0, 14);
  p_entityList->num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
  v79 = 0;
  v80 = 5;
  v81 = 0;
  v76 = 0;
  v78 = 0;
  v77 = 0;
  v7 = 86252;
  v8 = gameLocal;
  do
  {
    if ( *(idGameLocal_vtbl **)((char *)&v8->__vftable + v7) != nullptr )
    {
      v73.ent.spawnId.value = 0x1FFF;
      v73.warnings.memTag = 5;
      v73.warnings.listStatic = 0;
      memset(&v73.warnings, 0, 14);
      v9 = *(int *)((char *)&v8->__vftable + v7);
      if ( v9 != 0 )
      {
        v75 = *(_DWORD *)(v9 + 492);
        v10 = (v8->spawnIds.ptr[v75] << 13) | v75;
      }
      else
      {
        v10 = 0x1FFF;
      }
      v73.ent.spawnId.value = v10;
      if ( v8->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 )
      {
        v11 = v8->entities.ptr[v10 & 0x1FFF];
        if ( v11 != nullptr )
          v12 = idEntity::CastTo(c: v11);
        else
          v12 = nullptr;
      }
      else
      {
        v12 = nullptr;
      }
      v12->CheckForErrors(this: v12, a2: &v73.warnings);
      if ( v73.warnings.num > 0 )
      {
        idGuiPageEntityList::uniqueWarnings_t::AddWarnings(this: &v74, warnings: &v73.warnings);
        idList<idGuiPageEntityList::entityInfo_t,5>::Append(this: p_entityList, obj: &v73);
      }
      if ( v73.warnings.listStatic == 0 || v73.warnings.listStatic == 2 )
      {
        if ( v73.warnings.list != nullptr )
          idListArrayDelete<idStr>(ptr: v73.warnings.list, num: v73.warnings.size);
        v73.warnings.list = nullptr;
        v73.warnings.size = 0;
      }
      v8 = gameLocal;
      v73.warnings.num = 0;
    }
    v7 += 4;
  }
  while ( v7 < 119020 );
  idGuiListBox::idGuiListBox(this: &v85);
  num = this->entityList.num;
  v14 = 0;
  v85.selectedRow = this->selectedIndex;
  v85.maxRowsToDisplay = 32;
  if ( num > 0 )
  {
    v15 = 0;
    do
    {
      v16 = (idStr *)&p_entityList->list[v15];
      if ( v16->allocedAndFlag > 0 )
      {
        list = idGuiPageEntityList::entityInfo_t::AllWarnings(
                 this: (idGuiPageEntityList::entityInfo_t *)&v83,
                 result: (idStr *)&p_entityList->list[v15],
                 delimiter: " : ")->warnings.list;
        if ( gameLocal->spawnIds.ptr[v16->len & 0x1FFF] == v16->len >> 13 )
        {
          v18 = gameLocal->entities.ptr[v16->len & 0x1FFF];
          if ( v18 != nullptr )
            v19 = idEntity::CastTo(c: v18);
          else
            v19 = nullptr;
        }
        else
        {
          v19 = nullptr;
        }
        data = v19->name.data;
        v21 = idGuiListBox::Row(this: &v85);
        v25 = idGuiListBox::Printf(this: v21, fmt: data, a3: v24, a4: v23, a5: v22);
        idGuiListBox::Printf(this: v25, fmt: (const char *)list, a3: v28, a4: v27, a5: v26);
        idStr::FreeData(this: &v83);
        if ( gameLocal->spawnIds.ptr[v16->len & 0x1FFF] == v16->len >> 13
          && (v29 = gameLocal->entities.ptr[v16->len & 0x1FFF]) != nullptr )
        {
          v30 = idEntity::CastTo(c: v29);
        }
        else
        {
          v30 = nullptr;
        }
        v30->DebugDrawEntity(this: v30, a2: &idColor::colorRed, a3: 1);
        v31 = gameLocal->GetRenderWorld(this: gameLocal);
        v32 = idGuiPageEntityList::entityInfo_t::AllWarnings(
                this: (idGuiPageEntityList::entityInfo_t *)&v84,
                result: v16,
                delimiter: "\n");
        if ( gameLocal->spawnIds.ptr[v16->len & 0x1FFF] == v16->len >> 13 )
        {
          v33 = gameLocal->entities.ptr[v16->len & 0x1FFF];
          if ( v33 != nullptr )
            v34 = idEntity::CastTo(c: v33);
          else
            v34 = nullptr;
        }
        else
        {
          v34 = nullptr;
        }
        Physics = idEntity::GetPhysics(this: v34);
        v36 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        HIDWORD(v38) = v16->len;
        LODWORD(v38) = gameLocal;
        v39 = v16->len & 0x1FFF;
        v40 = v32->warnings.list;
        LODWORD(v41) = v16->len >> 13;
        v37 = v36;
        HIDWORD(v41) = v39 + 29755;
        if ( gameLocal->spawnIds.ptr[v39] == (_DWORD)v41
          && (HIDWORD(v38) = 4 * (v39 + 21563),
              (v42 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v38))) != nullptr) )
        {
          v43 = idEntity::CastTo(c: v42);
        }
        else
        {
          v43 = nullptr;
        }
        HIDWORD(v44) = v43->name.data;
        LODWORD(v44) = v40;
        v45 = va::va(
                this: &v86,
                fmt: "'%s' errors: \n%s",
                a3: v44,
                a4: v41,
                a5: v38,
                a6: v66,
                a7: v67,
                a8: v68,
                a9: v69,
                a10: v70,
                a11: v71);
        ((void (__fastcall *)(idRenderWorld *, va *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v31->DebugText)(
          a1: v31,
          a2: v45,
          a3: v37,
          a4: v31->DebugText,
          a5: &idColor::colorRed,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.1);
        idStr::FreeData(this: &v84);
      }
      ++v14;
      ++v15;
    }
    while ( v14 < this->entityList.num );
  }
  idGuiListBox::Render(this: &v85, page: this, context, hAlign: 0, vAlign: 1u, nextTo: nullptr);
  selectedIndex = this->selectedIndex;
  if ( selectedIndex >= -1 )
  {
    if ( selectedIndex > v85.rows.num - 1 )
      selectedIndex = v85.rows.num - 1;
  }
  else
  {
    selectedIndex = -1;
  }
  this->selectedIndex = selectedIndex;
  idGuiListBox::idGuiListBox(this: &v82);
  *(_WORD *)&v72.cells.memTag = 1280;
  memset(&v72, 0, 14);
  idList<idGuiListBox::row_t,5>::Append(this: &v82.rows, obj: &v72);
  idGuiListBox::Printf(
    this: &v82,
    fmt: "UP/DN( PC ) or D-Pad UP/DN( Xbox/PS3 )- select warnings",
    a3: v49,
    a4: v48,
    a5: v47);
  *(_WORD *)&v72.cells.memTag = 1280;
  memset(&v72, 0, 14);
  idList<idGuiListBox::row_t,5>::Append(this: &v82.rows, obj: &v72);
  LODWORD(v50) = "ound traces";
  idGuiListBox::Printf(
    this: &v82,
    fmt: "ENTER( PC ) or A( XBox ) / X( PS3 ) - teleport to selected",
    a3: v52,
    a4: v51,
    a5: v50);
  *(_WORD *)&v72.cells.memTag = 1280;
  memset(&v72, 0, 14);
  v82.currentColor = idColor::colorCyan;
  v53 = v85.rows.num;
  idList<idGuiListBox::row_t,5>::Append(this: &v82.rows, obj: &v72);
  v54 = v74.uniques.num;
  idGuiListBox::Printf(
    this: &v82,
    fmt: "%d bad ents, %d unique errors",
    a3: __SPAIR64__(v53, v74.uniques.num),
    a4: v56,
    a5: v55);
  v57 = v74.uniques.list;
  if ( v54 > 0 )
  {
    *(_WORD *)&v72.cells.memTag = 1280;
    p_count = &v74.uniques.list[-1].count;
    memset(&v72, 0, 14);
    for ( i = v54; i != 0; --i )
    {
      v60 = p_count[2];
      idList<idGuiListBox::row_t,5>::Append(this: &v82.rows, obj: &v72);
      p_count += 9;
      HIDWORD(v61) = *p_count;
      LODWORD(v61) = v60;
      idGuiListBox::Printf(this: &v82, fmt: "%3d warnings: '%s'", a3: v61, a4: v63, a5: v62);
    }
  }
  idGuiListBox::Render(this: &v82, page: this, context, hAlign: 2u, vAlign: 0, nextTo: &v85);
  idGuiListBox::~idGuiListBox(this: &v82);
  idGuiListBox::~idGuiListBox(this: &v85);
  if ( (v74.uniques.listStatic == 0 || v74.uniques.listStatic == 2) && v57 != nullptr )
  {
    v64 = v74.uniques.size;
    if ( v74.uniques.size > 0 )
    {
      p_warning = &v57->warning;
      do
      {
        idStr::FreeData(this: p_warning);
        --v64;
        p_warning = (idStr *)((char *)p_warning + 36);
      }
      while ( v64 != 0 );
    }
    idMem::Free(this: &mem, ptr: v57, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$502789
// EA  : 0x82A51AD0
// RVA : 0x00A51AD0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502789()
{
  int v0; // r12

  idList<idPlayer::jobMessage_t,5>::Clear(this: (idList<idVoiceTrack::idSubtitleText,5> *)(v0 - 4864 + 160));
}


// ========================================================================
// __unwind$502790
// EA  : 0x82A51AF8
// RVA : 0x00A51AF8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502790()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4864 + 192));
}


// ========================================================================
// __unwind$502791
// EA  : 0x82A51B20
// RVA : 0x00A51B20
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502791()
{
  int v0; // r12

  idGuiPageEntityList::entityInfo_t::~entityInfo_t(this: (idGuiPageEntityList::entityInfo_t *)(v0 - 4864 + 128));
}


// ========================================================================
// __unwind$502792
// EA  : 0x82A51B48
// RVA : 0x00A51B48
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502792()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 4864 + 448));
}


// ========================================================================
// __unwind$502793
// EA  : 0x82A51B70
// RVA : 0x00A51B70
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502793()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4864 + 384));
}


// ========================================================================
// __unwind$502794
// EA  : 0x82A51B98
// RVA : 0x00A51B98
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502794()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4864 + 416));
}


// ========================================================================
// __unwind$502795
// EA  : 0x82A51BC0
// RVA : 0x00A51BC0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_502795()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 4864 + 208));
}


// ========================================================================
// __unwind$503425
// EA  : 0x82A51BE8
// RVA : 0x00A51BE8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_503425()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4864 + 112));
}


// ========================================================================
// __unwind$503565
// EA  : 0x82A51C10
// RVA : 0x00A51C10
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_503565()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4864 + 112));
}


// ========================================================================
// __unwind$503721
// EA  : 0x82A51C38
// RVA : 0x00A51C38
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_503721()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4864 + 112));
}


// ========================================================================
// __unwind$503877
// EA  : 0x82A51C60
// RVA : 0x00A51C60
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _unwind_503877()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4864 + 112));
}


// ========================================================================
// ?Init@idAIGUI@@QAAXXZ
// EA  : 0x82A51D20
// RVA : 0x00A51D20
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall idAIGUI::Init(idAIGUI *this)
{
  idGuiPage1 *v2; // r3
  idGuiPage1 *v3; // r3
  idGuiPage2 *v4; // r3
  idGuiPage2 *v5; // r3
  idGuiPage4 *v6; // r3
  idGuiPage4 *v7; // r3
  idGuiPage5 *v8; // r3
  idGuiPage5 *v9; // r3
  idGuiPage6 *v10; // r3
  idGuiPage6 *v11; // r3
  idGuiPageEntityList *v12; // r3
  idGuiPageEntityList *v13; // r3
  encounterGroupRole_t v14[12]; // [sp+50h] [-30h] BYREF

  if ( this->initialized )
  {
    idLib::Warning(fmt: "Trying to Init AIGUI when its already Init!");
  }
  else
  {
    this->initialized = true;
    v14[0] = ROLE_NONE;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v2 = (idGuiPage1 *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x4Cu,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v2;
    if ( v2 != nullptr )
      v3 = idGuiPage1::idGuiPage1(this: v2);
    else
      v3 = nullptr;
    v14[0] = (encounterGroupRole_t)v3;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v4 = (idGuiPage2 *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x50u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v4;
    if ( v4 != nullptr )
      v5 = idGuiPage2::idGuiPage2(this: v4);
    else
      v5 = nullptr;
    v14[0] = (encounterGroupRole_t)v5;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v6 = (idGuiPage4 *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x40u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v6;
    if ( v6 != nullptr )
      v7 = idGuiPage4::idGuiPage4(this: v6);
    else
      v7 = nullptr;
    v14[0] = (encounterGroupRole_t)v7;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v8 = (idGuiPage5 *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x40u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v8;
    if ( v8 != nullptr )
      v9 = idGuiPage5::idGuiPage5(this: v8);
    else
      v9 = nullptr;
    v14[0] = (encounterGroupRole_t)v9;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v10 = (idGuiPage6 *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x40u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v10;
    if ( v10 != nullptr )
      v11 = idGuiPage6::idGuiPage6(this: v10);
    else
      v11 = nullptr;
    v14[0] = (encounterGroupRole_t)v11;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    v12 = (idGuiPageEntityList *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x54u,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v12;
    if ( v12 != nullptr )
      v13 = idGuiPageEntityList::idGuiPageEntityList(this: v12);
    else
      v13 = nullptr;
    v14[0] = (encounterGroupRole_t)v13;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->debugPages, obj: v14);
  }
}


// ========================================================================
// __unwind$504364
// EA  : 0x82A51F34
// RVA : 0x00A51F34
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504364(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$504365
// EA  : 0x82A51F5C
// RVA : 0x00A51F5C
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504365(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$504366
// EA  : 0x82A51F84
// RVA : 0x00A51F84
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504366(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$504367
// EA  : 0x82A51FAC
// RVA : 0x00A51FAC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504367(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$504368
// EA  : 0x82A51FD4
// RVA : 0x00A51FD4
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504368(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$504369
// EA  : 0x82A51FFC
// RVA : 0x00A51FFC
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __fastcall _unwind_504369(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'g_showEntityWarnings''
// EA  : 0x83366F20
// RVA : 0x01366F20
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEntityWarnings__()
{
  idCVar::idCVar(
    this: &g_showEntityWarnings,
    name: "g_showEntityWarnings",
    value: "0",
    flags: 1,
    description: "set to 1 to see entities that are incorrectly placed/configured/etc",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEntityWarnings__);
}


// ========================================================================
// `dynamic initializer for 'aigui_keyboardUse''
// EA  : 0x83366F78
// RVA : 0x01366F78
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aigui_keyboardUse__()
{
  idCVar::idCVar(
    this: &aigui_keyboardUse,
    name: "aigui_keyboardUse",
    value: "2",
    flags: 2,
    description: "0 = no keys, 1 = arrow keys, 2 = arrows and NumPad",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aigui_keyboardUse__);
}


// ========================================================================
// `dynamic initializer for 'ai_showBlendTreeWeb''
// EA  : 0x83366FD0
// RVA : 0x01366FD0
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_showBlendTreeWeb__()
{
  idCVar::idCVar(
    this: &ai_showBlendTreeWeb,
    name: "ai_showBlendTreeWeb",
    value: "0",
    flags: 1,
    description: "active md6 nodes from animweb during aigui",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_showBlendTreeWeb__);
}


// ========================================================================
// `dynamic initializer for 'aigui''
// EA  : 0x83367028
// RVA : 0x01367028
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aigui__()
{
  idCVar::idCVar(
    this: &aigui,
    name: "aigui",
    value: "0",
    flags: 2,
    description: "0 = no AI debug GUI, 1-9 = debug page",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aigui__);
}


// ========================================================================
// `dynamic initializer for 'aigui_show''
// EA  : 0x83367080
// RVA : 0x01367080
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aigui_show__()
{
  idCVar::idCVar(
    this: &aigui_show,
    name: "aigui_show",
    value: "0",
    flags: 2,
    description: "0 = no AI debug GUI, 1 = minimal AI debug GUI, 2 = full AI debug GUI",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aigui_show__);
}


// ========================================================================
// `dynamic initializer for 'aigui_scale''
// EA  : 0x833670D8
// RVA : 0x013670D8
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aigui_scale__()
{
  idCVar::idCVar(
    this: &aigui_scale,
    name: "aigui_scale",
    value: "0.25",
    flags: 4,
    description: "scale for AI GUI text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aigui_scale__);
}


// ========================================================================
// `dynamic initializer for 'aigui_titleSafe''
// EA  : 0x83367130
// RVA : 0x01367130
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aigui_titleSafe__()
{
  idCVar::idCVar(
    this: &aigui_titleSafe,
    name: "aigui_titleSafe",
    value: "0.1",
    flags: 4,
    description: "title safe ratio region",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aigui_titleSafe__);
}


// ========================================================================
// `dynamic initializer for 'mouseCursor''
// EA  : 0x83367188
// RVA : 0x01367188
// PDB : w:\tech5\tungsten\game\ai\aigui.cpp
// ========================================================================

void _dynamic_initializer_for__mouseCursor__()
{
  mouseCursor.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &mouseCursor;
}

