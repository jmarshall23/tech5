
// ========================================================================
// ?idLexerJSON_ExpectLiteralToken@idDebugMenuLocal@@CA_NAAVidLexer@@PBD@Z
// EA  : 0x82674050
// RVA : 0x00674050
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

BOOL __fastcall idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(idLexer *src, const char *token)
{
  BOOL v4; // r30
  idToken v5; // [sp+50h] [-60h] BYREF

  v5.len = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  v5.floatvalue = -3.4028235e38;
  v5.baseBuffer[0] = 0;
  v5.intvalue = 0;
  memset(&v5.whiteSpaceStart_p, 0, 12);
  if ( idLexer::ReadToken(this: src, token: &v5) )
  {
    v4 = (_cntlzw(idStr::Cmp(s1: v5.data, s2: token)) & 0x20) != 0;
    idStr::FreeData(this: &v5);
    return v4;
  }
  else
  {
    idStr::FreeData(this: &v5);
    return false;
  }
}


// ========================================================================
// __unwind$221166
// EA  : 0x82674100
// RVA : 0x00674100
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_221166()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?idLexerJSON_ExpectString@idDebugMenuLocal@@CA_NAAVidLexer@@PBD@Z
// EA  : 0x82674130
// RVA : 0x00674130
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

BOOL __fastcall idDebugMenuLocal::idLexerJSON_ExpectString(idLexer *src, const char *string)
{
  BOOL v5; // r30
  idToken v6; // [sp+50h] [-70h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.floatvalue = -3.4028235e38;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  if ( idLexer::ReadToken(this: src, token: &v6) )
  {
    if ( v6.type == 1 )
    {
      v5 = (_cntlzw(idStr::Cmp(s1: v6.data, s2: string)) & 0x20) != 0;
      idStr::FreeData(this: &v6);
      return v5;
    }
    else
    {
      idLexer::UnreadToken(this: src);
      idStr::FreeData(this: &v6);
      return false;
    }
  }
  else
  {
    idStr::FreeData(this: &v6);
    return false;
  }
}


// ========================================================================
// __unwind$221242
// EA  : 0x826741F0
// RVA : 0x006741F0
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_221242()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?IsActive@idDebugMenuLocal@@UBA_NXZ
// EA  : 0x82674218
// RVA : 0x00674218
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

BOOL __fastcall idDebugMenuLocal::IsActive(idDebugMenuLocal *this)
{
  return com_showDebugMenu.valueInteger != 0;
}


// ========================================================================
// ?HandleGuiEvent@idDebugMenuLocal@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82674230
// RVA : 0x00674230
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

BOOL __fastcall idDebugMenuLocal::HandleGuiEvent(idDebugMenuLocal *this, const sysEvent_t *sev)
{
  int selectedItem; // r11
  char v6; // r27
  const char *v7; // r29
  idDebugMenuLocal::CGroup *v8; // r10
  int v9; // r11
  idCVar *v10; // r30
  int evValue; // r5
  int v12; // r11
  idDebugMenuLocal::CGroup *v13; // r6
  int i; // r9
  idGame *Game; // r3
  int v16; // r11
  unsigned int v17; // r11
  int v18; // r11
  int selectedGroup; // r11
  int v20; // r11
  int valueInteger; // r11
  idCVar *v22; // r3
  bool v23; // r4
  int v24; // r11
  int flags; // r11

  if ( this->groups.num == 0 )
    return false;
  if ( sev->evType == SE_KEY )
  {
    if ( sev->evValue == 265 )
      this->modKeyPressed = sev->evValue2 != 0;
    if ( sev->evType == SE_KEY && sev->evValue2 != 0 )
    {
      if ( this->modKeyPressed && sev->evValue == 264 )
      {
        idCVar::SetBool(this: &com_showDebugMenu, newValue: true, force: true);
        return true;
      }
      if ( sev->evValue == 87 )
      {
        idCVar::SetBool(
          this: &com_showDebugMenu,
          newValue: (_cntlzw(com_showDebugMenu.valueInteger) & 0x20) != 0,
          force: true);
        return true;
      }
      if ( com_showDebugMenu.valueInteger == 0 )
        return false;
      selectedItem = this->selectedItem;
      v6 = 1;
      v7 = nullptr;
      if ( selectedItem >= 0
        && (v8 = &this->groups.list[this->selectedGroup], selectedItem < v8->items.num)
        && (v9 = (int)&v8->items.list[selectedItem], v7 = *(const char **)(v9 + 76), v6 = *(_BYTE *)v9, v7 != nullptr) )
      {
        v10 = cvarSystem->Find(this: cvarSystem, a2: v7);
      }
      else
      {
        v10 = nullptr;
      }
      evValue = sev->evValue;
      if ( evValue < 65 || evValue > 90 )
      {
        if ( this->groups.list[this->selectedGroup].items.list[this->selectedItem].entityValid.len != 0 )
        {
          Game = GetGame();
          if ( Game == nullptr
            || Game->FindEntity(
                 this: Game,
                 a2: this->groups.list[this->selectedGroup].items.list[this->selectedItem].entityValid.data) == nullptr )
          {
            v7 = nullptr;
            v6 = 0;
          }
        }
        v16 = sev->evValue;
        if ( v16 > 211 )
        {
          switch ( v16 )
          {
            case 256:
              goto LABEL_56;
            case 257:
              goto LABEL_68;
            case 259:
              goto LABEL_40;
            case 280:
              goto LABEL_53;
            case 281:
              goto LABEL_54;
            case 282:
              goto LABEL_43;
            case 283:
              goto LABEL_55;
            case 284:
              goto LABEL_80;
            case 285:
              goto LABEL_85;
            default:
              goto LABEL_71;
          }
        }
        if ( v16 == 211 )
          goto LABEL_40;
        if ( v16 > 201 )
        {
          v17 = v16 - 203;
          if ( v17 > 6 )
            goto LABEL_71;
          if ( v17 != 0 )
          {
            if ( v17 == 1 )
              goto LABEL_71;
            if ( v17 != 2 )
            {
              if ( v17 != 3 && v17 != 4 )
              {
                if ( v17 == 5 )
                {
LABEL_55:
                  ++this->selectedItem;
                }
                else
                {
LABEL_54:
                  selectedGroup = this->selectedGroup;
                  this->startItem = 0;
                  this->selectedItem = 0;
                  this->selectedGroup = selectedGroup + 1;
                }
              }
              goto LABEL_71;
            }
LABEL_85:
            if ( v10 == nullptr )
              goto LABEL_71;
            flags = v10->flags;
            if ( (flags & 2) != 0 )
            {
              idCVar::SetInteger(this: v10, newValue: v10->valueInteger + 1, force: true);
              goto LABEL_71;
            }
            if ( (flags & 1) == 0 )
              goto LABEL_71;
            v23 = true;
            v22 = v10;
LABEL_70:
            idCVar::SetBool(this: v22, newValue: v23, force: true);
            goto LABEL_71;
          }
LABEL_80:
          if ( v10 == nullptr )
            goto LABEL_71;
          v24 = v10->flags;
          if ( (v24 & 2) != 0 )
          {
            idCVar::SetInteger(this: v10, newValue: v10->valueInteger - 1, force: true);
            goto LABEL_71;
          }
          if ( (v24 & 1) == 0 )
            goto LABEL_71;
          v22 = v10;
        }
        else
        {
          if ( v16 == 201 )
          {
LABEL_53:
            v18 = this->selectedGroup;
            this->startItem = 0;
            this->selectedItem = 0;
            this->selectedGroup = v18 - 1;
            goto LABEL_71;
          }
          if ( v16 > 28 )
          {
            if ( v16 == 200 )
LABEL_43:
              --this->selectedItem;
            goto LABEL_71;
          }
          if ( v16 == 28 )
          {
LABEL_56:
            if ( v10 != nullptr )
            {
              v20 = v10->flags;
              if ( (v20 & 2) != 0 )
              {
                valueInteger = v10->valueInteger;
                if ( valueInteger != 0 )
                {
                  if ( valueInteger == 1 )
                    idCVar::SetInteger(this: v10, newValue: 0, force: true);
                }
                else
                {
                  idCVar::SetInteger(this: v10, newValue: 1, force: true);
                }
              }
              else if ( (v20 & 1) != 0 )
              {
                idCVar::SetBool(this: v10, newValue: (_cntlzw(v10->valueInteger) & 0x20) != 0, force: true);
              }
            }
            else if ( v6 != 0 && v7 != nullptr )
            {
              cmdSystem->AppendCommandText(this: cmdSystem, a2: v7);
            }
            if ( v6 == 0 )
              goto LABEL_71;
          }
          else if ( v16 != 1 )
          {
            if ( v16 == 14 )
            {
LABEL_40:
              if ( v10 != nullptr )
                idCVar::Reset(this: v10);
            }
LABEL_71:
            if ( this->selectedGroup < 0 )
              this->selectedGroup = this->groups.num - 1;
            if ( this->selectedGroup >= this->groups.num )
              this->selectedGroup = 0;
            if ( this->selectedItem < 0 )
              this->selectedItem = this->groups.list[this->selectedGroup].items.num - 1;
            if ( this->selectedItem >= this->groups.list[this->selectedGroup].items.num )
              this->selectedItem = 0;
            return true;
          }
LABEL_68:
          v22 = &com_showDebugMenu;
        }
        v23 = false;
        goto LABEL_70;
      }
      v12 = 0;
      v13 = &this->groups.list[this->selectedGroup];
      if ( v13->items.num > 0 )
      {
        for ( i = 0; v13->items.list[i].shortcut != evValue; ++i )
        {
          if ( ++v12 >= this->groups.list[this->selectedGroup].items.num )
            return true;
        }
        this->selectedItem = v12;
      }
      return true;
    }
  }
  return com_showDebugMenu.valueInteger != 0;
}


// ========================================================================
// ?Render@idDebugMenuLocal@@UAAPAVidRenderModelGui@@XZ
// EA  : 0x82674838
// RVA : 0x00674838
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

idRenderModelGui *__fastcall idDebugMenuLocal::Render(idDebugMenuLocal *this, int a2, unsigned __int64 a3)
{
  int v4; // r29
  int v5; // r3
  double v6; // fp28
  const idVec4 *v7; // r4
  const char *v8; // r5
  const char *v9; // r5
  const idVec4 *v10; // r4
  const char *v11; // r5
  const idVec4 *v12; // r4
  double v13; // fp29
  int v14; // r30
  int v15; // r29
  const char *v16; // r4
  __int64 v17; // r9
  double v18; // fp29
  int v19; // r30
  const char *v20; // r5
  const idVec4 *v21; // r4
  int selectedItem; // r11
  const idVec4 *startItem; // r4
  double v24; // fp26
  const char *num; // r5
  __int64 v26; // r9
  int v27; // r26
  int i; // r23
  const char *data; // r27
  idDebugMenuLocal::CEntry *v30; // r29
  idCVar *v31; // r3
  float r; // r4
  idCVar *v33; // r30
  float a; // r5
  bool v35; // r11
  BOOL v36; // r25
  __int64 v37; // r4
  __int64 v38; // r7
  int flags; // r28
  const char *resetString; // r10
  char *v41; // r11
  int v42; // r9
  int v43; // r9
  bool v44; // zf
  const char *v45; // r5
  const char *v46; // r5
  const idVec4 *v47; // r4
  idGame *Game; // r3
  const char *InfoDevComment; // r3
  __int64 v51; // [sp+58h] [-868h]
  idDeviceContext v52; // [sp+B0h] [-810h] BYREF
  char v53[616]; // [sp+5C0h] [-300h] BYREF

  if ( this->guiModel == nullptr || this->groups.num == 0 )
    return nullptr;
  idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: a3);
  v4 = renderSystem->GetHeight(this: renderSystem);
  v5 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v5, height: v4);
  if ( com_showDebugMenu.valueInteger != 0 )
  {
    idDeviceContext::idDeviceContext(this: &v52, guiModel: this->guiModel);
    idDeviceContext::SetFont(this: &v52, font: this->font);
    v6 = (float)((float)__SPAIR64__(&off_82350000, renderSystem->GetWidth(this: renderSystem)) - 128.0);
    v51 = __PAIR64__("frictionTime", ((int (*)(void))renderSystem->GetHeight)());
    idDeviceContext::DrawFilledRect(
      this: &v52,
      x: 48.0,
      y: 48.0,
      w: (float)((float)v6 + (float)32.0),
      h: (float)((float)((float)v51 - (float)128.0) + (float)32.0),
      color: (const idVec4 *)"frictionTime");
    idDeviceContext::DrawTextA(
      this: &v52,
      x: 68.0,
      y: 116.0,
      scale: 0.80000001,
      color: v7,
      text: (const char *)&unk_821D0000);
    idDeviceContext::DrawTextA(
      this: &v52,
      x: 64.0,
      y: 112.0,
      scale: 0.80000001,
      color: (const idVec4 *)&unk_821D0000,
      text: v8);
    idDeviceContext::DrawTextA(this: &v52, x: 72.0, y: 136.0, scale: 0.40000001, color: v10, text: v9);
    v13 = 64.0;
    v14 = 0;
    if ( this->groups.num > 0 )
    {
      v15 = 0;
      do
      {
        idDeviceContext::DrawTextA(this: &v52, x: v13, y: 184.0, scale: 0.40000001, color: v12, text: v11);
        LODWORD(v17) = idDeviceContext::TextWidth(
                         this: &v52,
                         scale: 0.40000001,
                         text: v16,
                         limit: (int)this->groups.list[v15].title.data);
        HIDWORD(v17) = this->groups.num;
        ++v14;
        ++v15;
        v13 = (float)((float)((float)v17 + (float)v13) + (float)24.0);
      }
      while ( v14 < SHIDWORD(v17) );
    }
    v18 = 232.0;
    v19 = (int)(float)((float)((float)((float)((float)((float)((float)v51 - (float)128.0) + (float)64.0) - (float)64.0)
                                     - (float)128.0)
                             - (float)232.0)
                     * (float)0.041666668);
    idDeviceContext::DrawTextA(
      this: &v52,
      x: 68.0,
      y: (float)((float)((float)((float)((float)((float)v51 - (float)128.0) + (float)64.0) - (float)64.0) - (float)128.0)
            + (float)4.0),
      scale: 0.40000001,
      color: v12,
      text: v11);
    idDeviceContext::DrawTextA(
      this: &v52,
      x: 64.0,
      y: (float)((float)((float)((float)((float)v51 - (float)128.0) + (float)64.0) - (float)64.0) - (float)128.0),
      scale: 0.40000001,
      color: v21,
      text: v20);
    selectedItem = this->selectedItem;
    startItem = (const idVec4 *)this->startItem;
    v24 = (float)((float)((float)((float)((float)((float)v51 - (float)128.0) + (float)64.0) - (float)64.0) - (float)128.0)
                + (float)36.0);
    if ( selectedItem < (int)startItem )
      this->startItem = selectedItem;
    if ( selectedItem >= v19 + this->startItem )
      this->startItem = selectedItem - v19 + 1;
    if ( this->startItem != 0 )
      idDeviceContext::DrawTextA(
        this: &v52,
        x: 64.0,
        y: 232.0,
        scale: 0.40000001,
        color: startItem,
        text: (const char *)&unk_821D0000);
    num = (const char *)this->groups.list[this->selectedGroup].items.num;
    if ( v19 + this->startItem < (int)num )
    {
      LODWORD(v26) = v19 - 1;
      HIDWORD(v26) = "v";
      idDeviceContext::DrawTextA(
        this: &v52,
        x: 64.0,
        y: (float)((float)((float)v26 * (float)24.0) + (float)232.0),
        scale: 0.40000001,
        color: startItem,
        text: num);
    }
    v27 = this->startItem;
    if ( v27 < this->groups.list[this->selectedGroup].items.num )
    {
      for ( i = v27; ; ++i )
      {
        if ( v27 >= (int)(float)((float)((float)((float)((float)((float)((float)v51 - (float)128.0) + (float)64.0)
                                                       - (float)64.0)
                                               - (float)128.0)
                                       - (float)232.0)
                               * (float)0.041666668)
                  + this->startItem )
          return this->guiModel;
        data = nullptr;
        v30 = &this->groups.list[this->selectedGroup].items.list[i];
        if ( v30->description.len != 0 )
          data = v30->description.data;
        v31 = cvarSystem->Find(this: cvarSystem, a2: v30->cmd.data);
        r = idColor::colorWhite.r;
        v33 = v31;
        a = COERCE_FLOAT(_cntlzw(this->selectedItem - v27));
        v35 = (LOBYTE(a) & 0x20) != 0;
        if ( !v30->valid )
          a = idColor::colorDkGrey.a;
        v36 = v35;
        if ( v35 )
        {
          v37 = ((__int64 (__fastcall *)(idRenderSystem *))renderSystem->GetWidth)(a1: renderSystem);
          LODWORD(v38) = HIDWORD(v37) - 256;
          idDeviceContext::DrawFilledRect(
            this: &v52,
            x: 96.0,
            y: (float)((float)v18 - (float)18.0),
            w: (float)v38,
            h: 24.0,
            color: (const idVec4 *)v37);
        }
        if ( v33 == nullptr )
        {
          if ( data == nullptr )
            data = cmdSystem->GetCommandDescription(this: cmdSystem, a2: v30->cmd.data);
          goto LABEL_43;
        }
        flags = v33->flags;
        resetString = v33->resetString;
        v41 = v33->valueString.data;
        do
        {
          v42 = (unsigned __int8)*v41;
          v44 = v42 == 0;
          v43 = v42 - *(unsigned __int8 *)resetString;
          if ( v44 )
            break;
          ++v41;
          ++resetString;
        }
        while ( v43 == 0 );
        if ( (flags & 1) != 0 )
          break;
        if ( (flags & 2) != 0 )
        {
          sprintf_0(string: v53, format: "%d", v33->valueInteger);
        }
        else
        {
          if ( (flags & 4) == 0 )
          {
            v45 = v33->valueString.data;
LABEL_36:
            sprintf_0(string: v53, format: "%s", v45);
            goto LABEL_37;
          }
          sprintf_0(
            string: v53,
            format: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v33->valueFloat)),
            (unsigned int)COERCE_UNSIGNED_INT64(v33->valueFloat));
        }
LABEL_37:
        idDeviceContext::DrawTextA(this: &v52, x: 608.0, y: v18, scale: 0.40000001, color: v47, text: v46);
        if ( data == nullptr )
          data = v33->description;
        if ( (flags & 0x10000) != 0 )
          idDeviceContext::DrawTextA(
            this: &v52,
            x: 864.0,
            y: v18,
            scale: 0.40000001,
            color: (const idVec4 *)LODWORD(r),
            text: (const char *)LODWORD(a));
LABEL_43:
        if ( v30->shortcut != 0 )
          idDeviceContext::DrawTextA(
            this: &v52,
            x: 96.0,
            y: v18,
            scale: 0.40000001,
            color: (const idVec4 *)LODWORD(r),
            text: (const char *)LODWORD(a));
        if ( v30->entityValid.len != 0 )
        {
          Game = GetGame();
          if ( Game != nullptr )
            Game->FindEntity(this: Game, a2: v30->entityValid.data);
        }
        if ( v30->title.data != nullptr )
          idDeviceContext::DrawTextA(
            this: &v52,
            x: 144.0,
            y: v18,
            scale: 0.40000001,
            color: (const idVec4 *)LODWORD(r),
            text: (const char *)LODWORD(a));
        if ( v30->entityDescr.len != 0 )
        {
          InfoDevComment = GetInfoDevComment(entityName: v30->entityDescr.data);
          if ( InfoDevComment != nullptr )
            data = InfoDevComment;
        }
        if ( v36 )
        {
          if ( data != nullptr )
            idDeviceContext::DrawTextA(
              this: &v52,
              x: 96.0,
              y: v24,
              scale: 0.40000001,
              color: (const idVec4 *)LODWORD(r),
              text: (const char *)LODWORD(a));
          if ( v30->cmd.data != nullptr )
            idDeviceContext::DrawTextA(
              this: &v52,
              x: 96.0,
              y: (float)((float)v24 + (float)24.0),
              scale: 0.40000001,
              color: (const idVec4 *)LODWORD(r),
              text: (const char *)LODWORD(a));
          v24 = (float)((float)((float)v24 + (float)24.0) + (float)24.0);
        }
        ++v27;
        v18 = (float)((float)v18 + (float)24.0);
        if ( v27 >= this->groups.list[this->selectedGroup].items.num )
          return this->guiModel;
      }
      v45 = "true";
      if ( v33->valueInteger == 0 )
        v45 = "false";
      goto LABEL_36;
    }
  }
  return this->guiModel;
}


// ========================================================================
// ??4CEntry@idDebugMenuLocal@@QAAAAU01@ABU01@@Z
// EA  : 0x82675250
// RVA : 0x00675250
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

idDebugMenuLocal::CEntry *__fastcall idDebugMenuLocal::CEntry::operator=(
        idDebugMenuLocal::CEntry *this,
        const idDebugMenuLocal::CEntry *other)
{
  int len; // r30
  int v5; // r30
  int v6; // r30
  int v7; // r30
  int v8; // r30

  this->valid = other->valid;
  this->shortcut = other->shortcut;
  len = other->title.len;
  idStr::EnsureAlloced(this: &this->title, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->title.data, Src: other->title.data, Size: len);
  this->title.data[len] = 0;
  this->title.len = len;
  v5 = other->description.len;
  idStr::EnsureAlloced(this: &this->description, amount: v5 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->description.data, Src: other->description.data, Size: v5);
  this->description.data[v5] = 0;
  this->description.len = v5;
  v6 = other->cmd.len;
  idStr::EnsureAlloced(this: &this->cmd, amount: v6 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->cmd.data, Src: other->cmd.data, Size: v6);
  this->cmd.data[v6] = 0;
  this->cmd.len = v6;
  this->color = other->color;
  v7 = other->entityValid.len;
  idStr::EnsureAlloced(this: &this->entityValid, amount: v7 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->entityValid.data, Src: other->entityValid.data, Size: v7);
  this->entityValid.data[v7] = 0;
  this->entityValid.len = v7;
  v8 = other->entityDescr.len;
  idStr::EnsureAlloced(this: &this->entityDescr, amount: v8 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->entityDescr.data, Src: other->entityDescr.data, Size: v8);
  this->entityDescr.data[v8] = 0;
  this->entityDescr.len = v8;
  return this;
}


// ========================================================================
// ?ReadEntry@idDebugMenuLocal@@AAA_NAAVidLexer@@AAUCEntry@1@@Z
// EA  : 0x826753B0
// RVA : 0x006753B0
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

int __fastcall idDebugMenuLocal::ReadEntry(idDebugMenuLocal *this, idLexer *src, idDebugMenuLocal::CEntry *entry)
{
  char v5; // r10
  int v6; // r11
  int v7; // r15
  int v8; // r15
  int len; // r15
  idToken v11; // [sp+50h] [-130h] BYREF
  idToken v12[3]; // [sp+A0h] [-E0h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.floatvalue = -3.4028235e38;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  v12[0].floatvalue = -3.4028235e38;
  v12[0].allocedAndFlag = 20;
  v12[0].data = v12[0].baseBuffer;
  v12[0].len = 0;
  v12[0].baseBuffer[0] = 0;
  v12[0].intvalue = 0;
  v12[0].whiteSpaceStart_p = nullptr;
  v12[0].whiteSpaceEnd_p = nullptr;
  v12[0].next = nullptr;
  if ( idLexer::ReadToken(this: src, token: &v11) )
  {
    while ( idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src, token: ":")
         && idLexer::ReadToken(this: src, token: v12) )
    {
      if ( idStr::Cmp(s1: v11.data, s2: "shortKey") != 0 )
      {
        if ( idStr::Cmp(s1: v11.data, s2: "title") != 0 )
        {
          if ( idStr::Cmp(s1: v11.data, s2: "cmd") != 0 )
          {
            if ( idStr::Cmp(s1: v11.data, s2: "res") != 0 )
            {
              if ( idStr::Cmp(s1: v11.data, s2: "entityValid") != 0 )
              {
                if ( idStr::Cmp(s1: v11.data, s2: "help") != 0 )
                {
                  if ( idStr::Cmp(s1: v11.data, s2: "entityDescr") != 0 )
                    idLib::Warning(
                      fmt: "DebugMenu loaded unknown key:value pair (\"%s\" : \"%s\")",
                      v11.data,
                      v12[0].data);
                  else
                    idStr::operator=(this: &entry->entityDescr, text: &v12[0]);
                }
                else
                {
                  idStr::operator=(this: &entry->description, text: &v12[0]);
                }
              }
              else
              {
                len = v12[0].len;
                idStr::EnsureAlloced(
                  this: &entry->entityValid,
                  amount: v12[0].len + 1,
                  keepold: false,
                  geometricGrowth: false);
                memcpy(Dst: entry->entityValid.data, Src: v12[0].data, Size: len);
                entry->entityValid.data[len] = 0;
                entry->entityValid.len = len;
              }
            }
            else
            {
              entry->valid = fileSystem->FileExists(this: fileSystem, a2: v12[0].data, a3: true);
            }
          }
          else
          {
            v8 = v12[0].len;
            idStr::EnsureAlloced(this: &entry->cmd, amount: v12[0].len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: entry->cmd.data, Src: v12[0].data, Size: v8);
            entry->cmd.data[v8] = 0;
            entry->cmd.len = v8;
          }
        }
        else
        {
          v7 = v12[0].len;
          idStr::EnsureAlloced(this: &entry->title, amount: v12[0].len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: entry->title.data, Src: v12[0].data, Size: v7);
          entry->title.data[v7] = 0;
          entry->title.len = v7;
        }
      }
      else
      {
        v5 = *v12[0].data;
        v6 = *v12[0].data;
        if ( v6 >= 97 && v5 <= 122 )
          v6 = v5 - 32;
        entry->shortcut = v6;
      }
      if ( !idLexer::ReadToken(this: src, token: &v11) )
        break;
      if ( idStr::Cmp(s1: v11.data, s2: "}") == 0 )
        goto LABEL_26;
      if ( idStr::Cmp(s1: v11.data, s2: ",") != 0 )
        break;
      if ( !idLexer::ReadToken(this: src, token: &v11) )
        goto LABEL_26;
    }
    idStr::FreeData(this: &v12[0]);
    idStr::FreeData(this: &v11);
    return 0;
  }
  else
  {
LABEL_26:
    idStr::FreeData(this: &v12[0]);
    idStr::FreeData(this: &v11);
    return 1;
  }
}


// ========================================================================
// __unwind$222105
// EA  : 0x8267575C
// RVA : 0x0067575C
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_222105()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$222106
// EA  : 0x82675784
// RVA : 0x00675784
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_222106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// ?ReadEntries@idDebugMenuLocal@@AAA_NAAVidLexer@@AAVCGroup@1@@Z
// EA  : 0x82675D00
// RVA : 0x00675D00
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

int __fastcall idDebugMenuLocal::ReadEntries(idDebugMenuLocal *this, idLexer *src, idDebugMenuLocal::CGroup *group)
{
  idList<idDebugMenuLocal::CEntry,3> *p_items; // r30
  int num; // r11
  int size; // r10
  idDebugMenuLocal::CEntry *list; // r9
  idDebugMenuLocal::CEntry *v9; // r5
  idToken v11; // [sp+50h] [-80h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.floatvalue = -3.4028235e38;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  v11.intvalue = 0;
  memset(&v11.whiteSpaceStart_p, 0, 12);
  p_items = &group->items;
  if ( group->items.size < 32 )
    idList<idDebugMenuLocal::CEntry,3>::Resize(this: &group->items, newsize: 32);
  if ( idLexer::ReadToken(this: src, token: &v11) )
  {
    while ( idStr::Cmp(s1: v11.data, s2: "]") != 0 )
    {
      idList<idDebugMenuLocal::CEntry,3>::PreAllocateWithGranularity(this: p_items, newSize: p_items->num + 1);
      num = p_items->num;
      size = p_items->size;
      list = p_items->list;
      if ( num >= size )
      {
        v9 = &list[size - 1];
      }
      else
      {
        v9 = &list[num];
        p_items->num = num + 1;
      }
      if ( (unsigned __int8)idDebugMenuLocal::ReadEntry(this, src, entry: v9) == 0
        || !idLexer::ReadToken(this: src, token: &v11) )
      {
        goto LABEL_17;
      }
      if ( idStr::Cmp(s1: v11.data, s2: "]") == 0 )
        break;
      if ( idStr::Cmp(s1: v11.data, s2: ",") != 0 )
      {
LABEL_17:
        idStr::FreeData(this: &v11);
        return 0;
      }
      if ( !idLexer::ReadToken(this: src, token: &v11) )
        break;
    }
  }
  idStr::FreeData(this: &v11);
  return 1;
}


// ========================================================================
// __unwind$222671
// EA  : 0x82675EA4
// RVA : 0x00675EA4
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_222671()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?ReadGroup@idDebugMenuLocal@@AAA_NAAVidLexer@@@Z
// EA  : 0x82676190
// RVA : 0x00676190
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

int __fastcall idDebugMenuLocal::ReadGroup(idDebugMenuLocal *this, idLexer *src)
{
  idDebugMenuLocal::CGroup *v5; // r28
  idToken v6; // [sp+50h] [-E0h] BYREF
  idToken v7; // [sp+A0h] [-90h] BYREF

  v6.len = 0;
  v6.allocedAndFlag = 20;
  v6.floatvalue = -3.4028235e38;
  v6.data = v6.baseBuffer;
  v6.baseBuffer[0] = 0;
  v6.intvalue = 0;
  memset(&v6.whiteSpaceStart_p, 0, 12);
  if ( idDebugMenuLocal::idLexerJSON_ExpectString(src, string: "pageName")
    && idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src, token: ":")
    && idLexer::ReadToken(this: src, token: &v6) )
  {
    v7.floatvalue = -3.4028235e38;
    v7.allocedAndFlag = 20;
    v7.data = v7.baseBuffer;
    v7.len = 0;
    v7.baseBuffer[0] = 0;
    v7.intvalue = 0;
    memset(&v7.whiteSpaceStart_p, 0, 12);
    if ( idLexer::ReadToken(this: src, token: &v7)
      && (idStr::Cmp(s1: v7.data, s2: "}") == 0
       || idStr::Cmp(s1: v7.data, s2: ",") == 0
       && idDebugMenuLocal::idLexerJSON_ExpectString(src, string: "entries")
       && idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src, token: ":")
       && idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src, token: "[")
       && (v5 = idList<idDebugMenuLocal::CGroup,3>::Alloc(this: &this->groups),
           idStr::operator=(this: &v5->title, text: &v6),
           (unsigned __int8)idDebugMenuLocal::ReadEntries(this, src, group: v5) != 0)
       && idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src, token: "}")) )
    {
      idStr::FreeData(this: &v7);
      idStr::FreeData(this: &v6);
      return 1;
    }
    else
    {
      idStr::FreeData(this: &v7);
      idStr::FreeData(this: &v6);
      return 0;
    }
  }
  else
  {
    idStr::FreeData(this: &v6);
    return 0;
  }
}


// ========================================================================
// __unwind$222879
// EA  : 0x82676448
// RVA : 0x00676448
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_222879()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$222880
// EA  : 0x82676470
// RVA : 0x00676470
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_222880()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 160));
}


// ========================================================================
// ?LoadMenu@idDebugMenuLocal@@AAA_NXZ
// EA  : 0x826764A0
// RVA : 0x006764A0
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

int __fastcall idDebugMenuLocal::LoadMenu(idDebugMenuLocal *this)
{
  idResource *v2; // r30
  int v4; // r28
  idToken v5; // [sp+50h] [-120h] BYREF
  idLexer v6; // [sp+A0h] [-D0h] BYREF

  v2 = idResourceList::Load(
         this: &idFileResource::resourceList,
         name: "debugmenu.txt",
         makeDefault: false,
         skipStaleCheck: false);
  if ( v2 != nullptr )
  {
    if ( this->groups.size < 8 )
      idList<idDebugMenuLocal::CGroup,3>::Resize(this: &this->groups, newsize: 8);
    idLexer::idLexer(this: &v6, flags_: 16);
    idLexer::LoadMemory(this: &v6, ptr: v2[1].name.str, length_: v2[1].trackedMemory, name: v2->name.str);
    v4 = 1;
    resourceManager->SetFileHook(this: resourceManager);
    v5.len = 0;
    v5.allocedAndFlag = 20;
    v5.data = v5.baseBuffer;
    v5.floatvalue = -3.4028235e38;
    v5.baseBuffer[0] = 0;
    v5.intvalue = 0;
    memset(&v5.whiteSpaceStart_p, 0, 12);
    if ( idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src: &v6, token: "{") )
    {
      while ( (unsigned __int8)idDebugMenuLocal::ReadGroup(this, src: &v6) != 0 )
      {
        if ( !idLexer::ReadToken(this: &v6, token: &v5) || idStr::Cmp(s1: v5.data, s2: "}") == 0 )
          goto LABEL_13;
        if ( idStr::Cmp(s1: v5.data, s2: ",") != 0 )
          break;
        if ( !idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(src: &v6, token: "{") )
          goto LABEL_13;
      }
      v4 = 0;
    }
LABEL_13:
    resourceManager->ReleaseFileHook(this: resourceManager);
    fileSystem->ClearZipCache(this: fileSystem);
    idStr::FreeData(this: &v5);
    idLexer::~idLexer(this: &v6);
    return v4;
  }
  else
  {
    idLib::Warning(fmt: "Could not find debugmenu.txt");
    return 0;
  }
}


// ========================================================================
// __unwind$223206
// EA  : 0x8267666C
// RVA : 0x0067666C
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_223206()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$223207
// EA  : 0x82676694
// RVA : 0x00676694
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_223207()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 80));
}


// ========================================================================
// ?Init@idDebugMenuLocal@@UAA_NXZ
// EA  : 0x826766C8
// RVA : 0x006766C8
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

int __fastcall idDebugMenuLocal::Init(idDebugMenuLocal *this)
{
  idRenderModelGui *v2; // r3
  idRenderModelGui *v3; // r3

  idDebugMenuLocal::LoadMenu(this);
  v2 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idRenderModelGui::idRenderModelGui(this: v2);
  else
    v3 = nullptr;
  this->guiModel = v3;
  this->font = (const idFont *)idResourceList::Load(
                                 this: &idFont::resourceList,
                                 name: "arial_black",
                                 makeDefault: true,
                                 skipStaleCheck: false);
  return 1;
}


// ========================================================================
// __unwind$223324
// EA  : 0x8267676C
// RVA : 0x0067676C
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_223324()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// `dynamic initializer for 'com_showDebugMenu''
// EA  : 0x8333B778
// RVA : 0x0133B778
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_showDebugMenu__()
{
  idCVar::idCVar(
    this: &com_showDebugMenu,
    name: "com_showDebugMenu",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_showDebugMenu__);
}


// ========================================================================
// `dynamic initializer for 'debugMenuLocal''
// EA  : 0x8333B7D8
// RVA : 0x0133B7D8
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debugMenuLocal__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debugMenuLocal__);
}


// ========================================================================
// __unwind$223365
// EA  : 0x8333B80C
// RVA : 0x0133B80C
// PDB : w:\tech5\engine\framework\debugmenu.cpp
// ========================================================================

void _unwind_223365()
{
  idDebugMenu::~idDebugMenu(this: &debugMenuLocal);
}

