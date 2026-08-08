
// ========================================================================
// ?Draw@idEditField@@QBAXPAVidRenderModelGui@@HHH_N@Z
// EA  : 0x82676800
// RVA : 0x00676800
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEditField::Draw(
        idEditField *this,
        idRenderModelGui *gui,
        unsigned int x,
        __int64 width,
        bool showCursor)
{
  __int64 v5; // r11
  __int64 v8; // r29
  float y; // r11
  int cursor; // r11
  int widthInChars; // r10
  int matchLength; // r9
  __int64 v14; // r11 OVERLAPPED
  int v15; // r9 OVERLAPPED
  int v16; // r10
  __int64 v17; // fp9
  __int64 v18; // r6
  __int64 v19; // r10
  double v20; // fp30
  const idVec4 *v21; // r5
  const char *v22; // r4
  int v23; // r4
  __int64 v24; // r11
  int v25; // r7
  char *data; // r9
  int v27; // r11
  char v28; // r11
  bool v29; // zf
  idVec4 v30; // [sp+50h] [-A0h] BYREF
  __int64 v31; // [sp+60h] [-90h]
  idStr v32; // [sp+70h] [-80h] BYREF

  LODWORD(v5) = width;
  v8 = __PAIR64__(HIDWORD(width), x);
  LODWORD(v30.y) = (int)(float)((float)v5 / SMALLCHAR_WIDTH);
  y = v30.y;
  this->widthInChars = LODWORD(v30.y);
  if ( SLODWORD(y) > 25 )
    this->widthInChars = LODWORD(y) - 13;
  cursor = this->cursor;
  if ( cursor < this->scroll )
  {
    this->scroll = cursor - 5;
    if ( cursor - 5 < 0 )
      this->scroll = 0;
  }
  widthInChars = this->widthInChars;
  if ( cursor > widthInChars + this->scroll )
    this->scroll = cursor - widthInChars + 5;
  matchLength = this->autoComplete.matchLength;
  if ( matchLength > 0 )
  {
    HIDWORD(v14) = this->widthInChars;
    LODWORD(v14) = matchLength - this->scroll;
    v15 = this->buffer.len - matchLength;
    if ( (int)v14 < SHIDWORD(v14) )
    {
      v16 = HIDWORD(v14) - v14;
      if ( v16 < v15 )
        v15 = v16;
      HIDWORD(v14) = x;
      LODWORD(width) = v15;
      v31 = width;
      v17 = width;
      HIDWORD(v18) = &unk_82150000;
      LODWORD(v18) = HIDWORD(width) + 2;
      v30.x = 0.80000001;
      v30.y = 0.2;
      v30.z = 0.2;
      v30.w = 0.40000001;
      idRenderModelGui::DrawFilled(
        this: gui,
        color: &v30,
        x: (float)((float)((float)v14 * SMALLCHAR_WIDTH) + (float)*(__int64 *)((char *)&v14 + 4)),
        y: (float)v18,
        w: (float)((float)v17 * SMALLCHAR_WIDTH),
        h: (float)(SMALLCHAR_HEIGHT - (float)2.0));
    }
  }
  idStr::Mid(this: &v32, result: &this->buffer, start: this->scroll, len: this->widthInChars);
  LODWORD(v19) = HIDWORD(v8);
  v31 = v19;
  v20 = (float)v19;
  idRenderModelGui::DrawString(
    this: gui,
    x: (float)v8,
    y: v20,
    string: v22,
    defaultColor: v21,
    forceColor: (bool)v32.data,
    scale: 1.0);
  if ( showCursor && (Sys_Milliseconds() & 0x100) == 0 )
  {
    v24 = (unsigned int)this->cursor;
    v25 = v24 - this->scroll;
    if ( (int)v24 > 0 )
    {
      data = this->buffer.data;
      do
      {
        LODWORD(v24) = &data[HIDWORD(v24)];
        if ( &data[HIDWORD(v24)] == nullptr
          || *(_BYTE *)v24 != 94
          || (v27 = *(char *)(v24 + 1)) == 0
          || (v29 = v27 != 32, v28 = 1, !v29) )
        {
          v28 = 0;
        }
        if ( v28 != 0 )
          v25 -= 2;
        ++HIDWORD(v24);
      }
      while ( SHIDWORD(v24) < this->cursor );
    }
    LODWORD(v24) = v25;
    v31 = v24;
    idRenderModelGui::DrawChar(
      this: gui,
      x: (float)((float)((float)v24 * SMALLCHAR_WIDTH) + (float)v8),
      y: v20,
      character: v23,
      scale: 1.0);
  }
  idStr::FreeData(this: &v32);
}


// ========================================================================
// __unwind$219514
// EA  : 0x82676AEC
// RVA : 0x00676AEC
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void _unwind_219514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ??1idEditField@@QAA@XZ
// EA  : 0x82676C00
// RVA : 0x00676C00
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::~idEditField(idEditField *this)
{
  idAutoComplete *p_autoComplete; // r30
  idStr *list; // r3

  p_autoComplete = &this->autoComplete;
  if ( this->autoComplete.suggestions.listStatic == 0 || this->autoComplete.suggestions.listStatic == 2 )
  {
    list = this->autoComplete.suggestions.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: p_autoComplete->suggestions.size);
    p_autoComplete->suggestions.list = nullptr;
    p_autoComplete->suggestions.size = 0;
  }
  p_autoComplete->suggestions.num = 0;
  idStr::FreeData(this: &this->buffer);
}


// ========================================================================
// __unwind$219737
// EA  : 0x82676C64
// RVA : 0x00676C64
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void _unwind_219737()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ?Clear@idEditField@@QAAXXZ
// EA  : 0x82676C90
// RVA : 0x00676C90
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::Clear(idEditField *this)
{
  idStr::Clear(this: &this->buffer);
  this->cursor = 0;
  this->scroll = 0;
  idAutoComplete::Clear(this: &this->autoComplete);
}


// ========================================================================
// ?ClearAutoComplete@idEditField@@QAAXXZ
// EA  : 0x82676CD8
// RVA : 0x00676CD8
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::ClearAutoComplete(idEditField *this)
{
  idAutoComplete *p_autoComplete; // r3
  int matchLength; // r10
  int len; // r9

  matchLength = this->autoComplete.matchLength;
  p_autoComplete = &this->autoComplete;
  if ( matchLength > 0 )
  {
    len = this->buffer.len;
    if ( matchLength <= len )
    {
      if ( len > matchLength )
      {
        this->buffer.data[matchLength] = 0;
        this->buffer.len = matchLength;
      }
      if ( this->cursor > p_autoComplete->matchLength )
        this->cursor = p_autoComplete->matchLength;
    }
  }
  idAutoComplete::Clear(this: p_autoComplete);
}


// ========================================================================
// ?AcceptAutoComplete@idEditField@@QAA_NXZ
// EA  : 0x82676D38
// RVA : 0x00676D38
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

int __fastcall idEditField::AcceptAutoComplete(idEditField *this)
{
  int matchLength; // r11
  idAutoComplete *p_autoComplete; // r3

  if ( this->autoComplete.currentIndex < 0 )
    return 0;
  if ( this->autoComplete.suggestions.num <= 1 )
    return 0;
  matchLength = this->autoComplete.matchLength;
  p_autoComplete = &this->autoComplete;
  if ( matchLength == 0 )
    return 0;
  idAutoComplete::Clear(this: p_autoComplete);
  this->cursor = this->buffer.len;
  return 1;
}


// ========================================================================
// ?AutoComplete@idEditField@@QAAX_N@Z
// EA  : 0x82676DB8
// RVA : 0x00676DB8
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::AutoComplete(idEditField *this, bool reverseOrder)
{
  idStr *p_buffer; // r26
  int cursor; // r11
  idAutoComplete *p_autoComplete; // r28
  idStr *list; // r21
  size_t v7; // r29
  idStr *v8; // r3
  int v9; // r11
  int v10; // r10
  int v11; // r3
  int v12; // r5
  idStr *v13; // r4
  int v14; // r11
  int v15; // r9
  char *data; // r7
  char v17; // r10
  char v18; // r8
  char v19; // r10
  int matchLength; // r11
  int v21; // r11
  int v22; // r10
  int v23; // r27
  int v24; // r29
  idCVar *v25; // r11
  int currentIndex; // r11
  int v27; // r11
  int v28; // r11
  idStr *v29; // r27
  size_t len; // r28
  int widthInChars; // r10
  int num; // [sp+50h] [-90h]
  idStr v33[4]; // [sp+60h] [-80h] BYREF

  num = this->autoComplete.suggestions.num;
  if ( num != 0 )
  {
    if ( num > 1 )
    {
      currentIndex = this->autoComplete.currentIndex;
      if ( reverseOrder )
      {
        v27 = currentIndex - 1;
        this->autoComplete.currentIndex = v27;
        if ( v27 < 0 )
          this->autoComplete.currentIndex = num - 1;
      }
      else
      {
        v28 = currentIndex + 1;
        this->autoComplete.currentIndex = v28;
        if ( v28 == num )
          this->autoComplete.currentIndex = 0;
      }
      v29 = &this->autoComplete.suggestions.list[this->autoComplete.currentIndex];
      len = v29->len;
      idStr::EnsureAlloced(this: &this->buffer, amount: v29->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->buffer.data, Src: v29->data, Size: len);
      this->buffer.data[len] = 0;
      this->buffer.len = len;
      widthInChars = this->widthInChars;
      if ( (int)(len - this->scroll) > widthInChars )
        this->scroll = len - widthInChars;
    }
  }
  else
  {
    p_buffer = &this->buffer;
    idStr::idStr(this: v33, text: &this->buffer);
    cursor = this->cursor;
    if ( v33[0].len > cursor && cursor >= 0 )
    {
      v33[0].data[cursor] = 0;
      v33[0].len = cursor;
    }
    p_autoComplete = &this->autoComplete;
    idAutoComplete::Clear(this: &this->autoComplete);
    idCmdArgs::TokenizeString(this: &this->autoComplete.args, text: v33[0].data, keepAsStrings: false);
    if ( this->autoComplete.args.argc == 0 )
    {
LABEL_6:
      idStr::FreeData(this: v33);
      return;
    }
    if ( v33[0].data[this->cursor - 1] == 32 )
      idCmdArgs::AppendArg(this: &this->autoComplete.args, text: &byte_8200D768);
    cmdSystem->CommandCompletion(this: cmdSystem, a2: &this->autoComplete);
    cvarSystem->CommandCompletion(this: cvarSystem, a2: &this->autoComplete);
    if ( this->autoComplete.suggestions.num != 1 )
    {
LABEL_17:
      if ( this->autoComplete.suggestions.num != 0 )
      {
        idStr::operator=(this: p_buffer, text: this->autoComplete.suggestions.list);
        v9 = p_buffer->len;
        v10 = this->autoComplete.suggestions.num;
        v11 = 1;
        p_autoComplete->matchLength = p_buffer->len;
        if ( v10 > 1 )
        {
          v12 = v9;
          v13 = this->autoComplete.suggestions.list + 1;
          do
          {
            v14 = v13->len;
            if ( v12 < v13->len )
              v14 = v12;
            v12 = v14;
            p_autoComplete->matchLength = v14;
            v15 = 0;
            if ( v14 > 0 )
            {
              data = v13->data;
              while ( 1 )
              {
                v17 = data[v15];
                if ( v17 < 97 || v17 > 122 )
                  v18 = data[v15];
                else
                  v18 = v17 - 32;
                v19 = this->buffer.data[v15];
                if ( v19 >= 97 && v19 <= 122 )
                  v19 -= 32;
                if ( v18 != v19 )
                  break;
                if ( ++v15 >= p_autoComplete->matchLength )
                  goto LABEL_37;
              }
              v12 = v15;
              p_autoComplete->matchLength = v15;
            }
LABEL_37:
            ++v11;
            ++v13;
          }
          while ( v11 < this->autoComplete.suggestions.num );
        }
        matchLength = p_autoComplete->matchLength;
        if ( p_buffer->len > p_autoComplete->matchLength && matchLength >= 0 )
        {
          p_buffer->data[matchLength] = 0;
          p_buffer->len = matchLength;
        }
        v21 = p_autoComplete->matchLength;
        v22 = this->autoComplete.suggestions.num;
        this->autoComplete.currentIndex = -1;
        this->cursor = v21;
        if ( v22 > 1 )
        {
          idLib::Printf(fmt: "]%s\n", v33[0].data);
          v23 = 0;
          if ( this->autoComplete.suggestions.num > 0 )
          {
            v24 = 0;
            do
            {
              if ( this->autoComplete.args.argc == 1
                && (v25 = cvarSystem->Find(this: cvarSystem, a2: this->autoComplete.suggestions.list[v24].data)) != nullptr )
              {
                idLib::Printf(
                  fmt: " %s^7 = \"%s\"\n",
                  this->autoComplete.suggestions.list[v24].data,
                  v25->valueString.data);
              }
              else
              {
                idLib::Printf(fmt: " %s\n", this->autoComplete.suggestions.list[v24].data);
              }
              ++v23;
              ++v24;
            }
            while ( v23 < this->autoComplete.suggestions.num );
          }
        }
      }
      goto LABEL_6;
    }
    while ( idStr::Cmp(s1: this->buffer.data, s2: this->autoComplete.suggestions.list->data) != 0 )
    {
      list = this->autoComplete.suggestions.list;
      v7 = list->len;
      idStr::EnsureAlloced(this: p_buffer, amount: list->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: p_buffer->data, Src: list->data, Size: v7);
      p_buffer->data[v7] = 0;
      p_buffer->len = v7;
      this->cursor = v7;
      p_autoComplete->matchLength = 0;
      this->autoComplete.currentIndex = -1;
      this->autoComplete.args.argc = 0;
      if ( this->autoComplete.suggestions.listStatic == 0 || this->autoComplete.suggestions.listStatic == 2 )
      {
        v8 = this->autoComplete.suggestions.list;
        if ( v8 != nullptr )
          idListArrayDelete<idStr>(ptr: v8, num: this->autoComplete.suggestions.size);
        this->autoComplete.suggestions.list = nullptr;
        this->autoComplete.suggestions.size = 0;
      }
      this->autoComplete.suggestions.num = 0;
      idCmdArgs::TokenizeString(this: &this->autoComplete.args, text: this->buffer.data, keepAsStrings: false);
      cmdSystem->CommandCompletion(this: cmdSystem, a2: &this->autoComplete);
      cvarSystem->CommandCompletion(this: cvarSystem, a2: &this->autoComplete);
      if ( this->autoComplete.suggestions.num != 1 )
        goto LABEL_17;
    }
    idStr::operator+=(this: p_buffer, a: 32);
    this->cursor = p_buffer->len;
    idAutoComplete::Clear(this: &this->autoComplete);
    idStr::FreeData(this: v33);
  }
}


// ========================================================================
// __unwind$219821
// EA  : 0x8267726C
// RVA : 0x0067726C
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void _unwind_219821()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?CharEvent@idEditField@@QAAXH@Z
// EA  : 0x82677298
// RVA : 0x00677298
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::CharEvent(idEditField *this, int ch)
{
  int cursor; // r11
  int v4; // r11
  char *v5; // r10
  int len; // r10
  int v7; // r11
  idStr *p_buffer; // r3
  int v9; // r11

  switch ( ch )
  {
    case 22:
      idEditField::Paste(this);
      break;
    case 3:
    case 21:
      idStr::Clear(this: &this->buffer);
      this->cursor = 0;
      this->scroll = 0;
      idAutoComplete::Clear(this: &this->autoComplete);
      break;
    case 11:
      cursor = this->cursor;
      if ( this->buffer.len > cursor && cursor >= 0 )
      {
        this->buffer.data[cursor] = 0;
        this->buffer.len = cursor;
      }
      break;
    case 8:
      v4 = this->cursor;
      if ( v4 > 0 )
      {
        for ( ; v4 < this->buffer.len; *(v5 - 1) = *v5 )
          v5 = &this->buffer.data[v4++];
        len = this->buffer.len;
        v7 = len - 1;
        if ( len > len - 1 && v7 >= 0 )
        {
          this->buffer.data[v7] = 0;
          this->buffer.len = v7;
        }
        --this->cursor;
      }
      break;
    case 1:
      this->cursor = 0;
      break;
    case 5:
      this->cursor = this->buffer.len;
      break;
    default:
      if ( ch >= 32 )
      {
        p_buffer = &this->buffer;
        if ( this->overstrikeMode )
        {
          v9 = this->cursor;
          if ( v9 >= this->buffer.len )
            idStr::operator+=(this: p_buffer, a: ch);
          else
            this->buffer.data[v9] = ch;
          ++this->cursor;
        }
        else
        {
          idStr::Insert(this: p_buffer, a: ch, index: this->cursor);
          ++this->cursor;
        }
      }
      break;
  }
}


// ========================================================================
// ?Paste@idEditField@@QAAXXZ
// EA  : 0x826774C8
// RVA : 0x006774C8
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::Paste(idEditField *this)
{
  _BYTE *started; // r3
  _BYTE *v3; // r29
  int v4; // r30
  int i; // r31
  char v6; // r11

  started = (_BYTE *)idLobbyBackend360::StartArbitration(pexcept: (_exception *)this);
  v3 = started;
  if ( started != nullptr )
  {
    v4 = 0;
    if ( *started != 0 )
    {
      do
        ++v4;
      while ( started[v4] != 0 );
    }
    for ( i = 0; i < v4; ++i )
    {
      v6 = v3[i];
      if ( v6 == 10 )
        break;
      if ( v6 == 13 )
        break;
      if ( v6 == 8 )
        break;
      idEditField::CharEvent(this, ch: v6);
    }
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
}


// ========================================================================
// ?SetBuffer@idEditField@@QAAXPBD@Z
// EA  : 0x82677568
// RVA : 0x00677568
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::SetBuffer(idEditField *this, const char *buf)
{
  idStr *p_buffer; // r30

  p_buffer = &this->buffer;
  idStr::Clear(this: &this->buffer);
  this->cursor = 0;
  this->scroll = 0;
  idAutoComplete::Clear(this: &this->autoComplete);
  idStr::operator=(this: p_buffer, text: buf);
  this->cursor = this->buffer.len;
}


// ========================================================================
// ??0idEditField@@QAA@XZ
// EA  : 0x826775C0
// RVA : 0x006775C0
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

idEditField *__fastcall idEditField::idEditField(idEditField *this)
{
  idStr *p_buffer; // r3

  this->buffer.len = 0;
  p_buffer = &this->buffer;
  this->buffer.data = p_buffer->baseBuffer;
  this->buffer.allocedAndFlag = 20;
  this->buffer.baseBuffer[0] = 0;
  this->autoComplete.matchLength = 0;
  this->autoComplete.currentIndex = -1;
  this->autoComplete.args.argc = 0;
  this->autoComplete.suggestions.granularity = 0;
  this->autoComplete.suggestions.memTag = 5;
  this->autoComplete.suggestions.listStatic = 0;
  this->autoComplete.suggestions.list = nullptr;
  this->autoComplete.suggestions.size = 0;
  this->autoComplete.suggestions.num = 0;
  this->overstrikeMode = false;
  this->widthInChars = 0;
  this->cursor = 0;
  this->scroll = 0;
  idStr::Clear(this: p_buffer);
  this->cursor = 0;
  this->scroll = 0;
  idAutoComplete::Clear(this: &this->autoComplete);
  return this;
}


// ========================================================================
// __unwind$220226
// EA  : 0x82677670
// RVA : 0x00677670
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void _unwind_220226()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$220227
// EA  : 0x8267769C
// RVA : 0x0067769C
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void _unwind_220227()
{
  int v0; // r12

  idAutoComplete::~idAutoComplete(this: (idAutoComplete *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ?KeyDownEvent@idEditField@@QAAXH@Z
// EA  : 0x826776C8
// RVA : 0x006776C8
// PDB : w:\tech5\engine\framework\editfield.cpp
// ========================================================================

void __fastcall idEditField::KeyDownEvent(idEditField *this, int key)
{
  bool IsDown; // r3
  char v5; // r11
  int cursor; // r11
  int len; // r10
  char *v8; // r10
  int v9; // r10
  int v10; // r11
  int v11; // r9
  char *data; // r10
  int v13; // r11
  char *v14; // r10
  int v15; // r11
  int v16; // r11
  char *v17; // r10
  int v18; // r11
  char *v19; // r10
  int v20; // r11
  int v21; // r11

  if ( key == 210 || key == 82 )
  {
    if ( idKeyInput::IsDown(deviceNum: 0, keyNum: K_LSHIFT)
      || (IsDown = idKeyInput::IsDown(deviceNum: 0, keyNum: K_RSHIFT), v5 = 0, IsDown) )
    {
      v5 = 1;
    }
    if ( v5 != 0 )
    {
      idEditField::ClearAutoComplete(this);
      idEditField::Paste(this);
      return;
    }
  }
  switch ( key )
  {
    case 211:
LABEL_11:
      if ( this->autoComplete.matchLength <= 0 )
      {
        cursor = this->cursor;
        len = this->buffer.len;
        if ( cursor < len )
        {
          if ( cursor < len - 1 )
          {
            do
            {
              v8 = &this->buffer.data[cursor++];
              *v8 = v8[1];
            }
            while ( cursor < this->buffer.len - 1 );
          }
          v9 = this->buffer.len;
          v10 = v9 - 1;
          if ( v9 > v9 - 1 && v10 >= 0 )
          {
            this->buffer.data[v10] = 0;
            this->buffer.len = v10;
          }
        }
        return;
      }
LABEL_64:
      idEditField::ClearAutoComplete(this);
      return;
    case 32:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_64;
      goto LABEL_11;
    case 205:
      goto LABEL_22;
    case 33:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_64;
LABEL_22:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 || key == 33 )
      {
        ++this->cursor;
      }
      else
      {
        v11 = this->buffer.len;
        if ( this->cursor < v11 )
        {
          data = this->buffer.data;
          do
          {
            v13 = this->cursor;
            if ( data[v13] == 32 )
              break;
            this->cursor = v13 + 1;
          }
          while ( v13 + 1 < this->buffer.len );
        }
        if ( this->cursor < v11 )
        {
          v14 = this->buffer.data;
          do
          {
            v15 = this->cursor;
            if ( v14[v15] != 32 )
              break;
            v16 = v15 + 1;
            this->cursor = v16;
          }
          while ( v16 < this->buffer.len );
        }
      }
      v21 = this->buffer.len;
      if ( this->cursor > v21 )
        this->cursor = v21;
      if ( this->autoComplete.matchLength > 0 )
        this->autoComplete.matchLength = this->cursor;
LABEL_76:
      idList<idStr,99>::~idList<idStr,99>(this: &this->autoComplete.suggestions);
      return;
    case 203:
LABEL_36:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 || key == 48 )
      {
        --this->cursor;
      }
      else
      {
        if ( this->cursor > 0 )
        {
          v17 = this->buffer.data;
          do
          {
            v18 = this->cursor;
            if ( v17[v18 - 1] != 32 )
              break;
            this->cursor = v18 - 1;
          }
          while ( v18 - 1 > 0 );
        }
        if ( this->cursor > 0 )
        {
          v19 = this->buffer.data;
          do
          {
            v20 = this->cursor;
            if ( v19[v20 - 1] == 32 )
              break;
            this->cursor = v20 - 1;
          }
          while ( v20 - 1 > 0 );
        }
      }
      if ( this->cursor < 0 )
        this->cursor = 0;
      if ( this->autoComplete.matchLength > 0 )
        this->autoComplete.matchLength = this->cursor;
      goto LABEL_76;
    case 48:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_64;
      goto LABEL_36;
    case 199:
LABEL_50:
      this->cursor = 0;
      idAutoComplete::Clear(this: &this->autoComplete);
      return;
    case 30:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_64;
      goto LABEL_50;
    case 207:
LABEL_54:
      this->cursor = this->buffer.len;
      idAutoComplete::Clear(this: &this->autoComplete);
      return;
    case 18:
      if ( (unsigned __int8)idKeyInput::IsCtrlDown(deviceNum: 0) == 0 )
        goto LABEL_64;
      goto LABEL_54;
    case 210:
      this->overstrikeMode = (_cntlzw(this->overstrikeMode) & 0x20) != 0;
      return;
    default:
      break;
  }
  if ( key != 58 && key != 56 && key != 184 && key != 29 && key != 157 && key != 42 && key != 54 )
    goto LABEL_64;
}

